"""
GUI Launcher Agent (Windows) — start GUI apps from remote commands

Run this agent in the **interactive user session** on the testing PC. Any GUI apps it
starts will appear on that desktop (not Session 0).

Security model:
- Shared-secret header required (X-Agent-Secret)
- Optional executable allow-list/prefix filter
- Bind to loopback by default; access via SSH tunnel from remote

Dependencies:
  pip install fastapi uvicorn pydantic

Start (dev):
  set APP_AGENT_SECRET=change-me
  uvicorn gui_launcher_agent:app --host 127.0.0.1 --port 8765 --workers 1 --no-access-log

API:
  GET  /health                     -> { ok: true }
  GET  /ps                         -> list selected running processes
  POST /launch {exe, args?, cwd?, env?, wait?, timeout_sec?}
  POST /kill   {pid}

Author: ChatGPT
"""
from __future__ import annotations
import os
import sys
import time
import json
import signal
import socket
import logging
import subprocess
from typing import Dict, List, Optional

from fastapi import FastAPI, Header, HTTPException, Query
from pydantic import BaseModel, Field, validator

# --------------------------- CONFIG ---------------------------
SHARED_SECRET = os.getenv("APP_AGENT_SECRET", "change-me")
BIND_HOST     = os.getenv("APP_AGENT_HOST", "127.0.0.1")  # keep loopback; tunnel from remote
BIND_PORT     = int(os.getenv("APP_AGENT_PORT", "8765"))

# Whitelist prefixes where executables are allowed to originate from
# Tighten for your environment
ALLOWED_PREFIXES = [
    r"C:\\Program Files",
    r"C:\\Program Files (x86)",
    r"C:\\Windows",
    r"C:\\Tools",
    os.path.expandvars(r"%USERPROFILE%"),
]

PROCESS_LIST_FILTER = [".exe", ".bat", ".cmd"]  # for /ps view

LOG_PATH = os.getenv("APP_AGENT_LOG", os.path.join(os.path.expandvars(r"%ProgramData%"),
                                                    "GuiLauncherAgent", "agent.log"))
# --------------------------------------------------------------

# Ensure log directory exists
try:
    os.makedirs(os.path.dirname(LOG_PATH), exist_ok=True)
except Exception:
    pass

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    handlers=[
        logging.FileHandler(LOG_PATH, encoding="utf-8"),
        logging.StreamHandler(sys.stdout),
    ],
)
log = logging.getLogger("agent")

app = FastAPI(title="GUI Launcher Agent", version="1.0.0")


# --------------------------- MODELS ---------------------------
class LaunchRequest(BaseModel):
    exe: str = Field(..., description="Absolute path to the executable")
    args: Optional[List[str]] = Field(default=None, description="Argument list")
    cwd: Optional[str] = Field(default=None, description="Working directory")
    env: Optional[Dict[str, str]] = Field(default=None, description="Extra environment vars")
    wait: bool = Field(default=False, description="Wait for the process to exit and return code")
    timeout_sec: Optional[int] = Field(default=None, description="Timeout if wait=True")

    @validator("exe")
    def validate_exe(cls, v: str) -> str:
        v = os.path.normpath(v)
        if not os.path.isabs(v):
            raise ValueError("exe must be an absolute path")
        if not any(v.lower().startswith(p.lower()) for p in ALLOWED_PREFIXES):
            raise ValueError("exe path is not in allowed prefixes")
        if not os.path.exists(v):
            raise ValueError("exe does not exist")
        return v

    @validator("cwd")
    def validate_cwd(cls, v: Optional[str]) -> Optional[str]:
        if v is None:
            return v
        v = os.path.normpath(v)
        if not os.path.isdir(v):
            raise ValueError("cwd is not a directory")
        return v


class KillRequest(BaseModel):
    pid: int = Field(..., gt=0)


# --------------------------- HELPERS --------------------------

def _auth_or_403(secret_header: Optional[str]):
    if not secret_header or secret_header != SHARED_SECRET:
        log.warning("Auth failed or missing secret header")
        raise HTTPException(status_code=403, detail="Forbidden")


def _start_process(req: LaunchRequest) -> subprocess.Popen:
    cmd = [req.exe] + (req.args or [])
    # Avoid shell=True; safer quoting with list
    log.info("Launching: %s", json.dumps(cmd))
    try:
        p = subprocess.Popen(
            cmd,
            cwd=req.cwd or os.path.dirname(req.exe),
            env={**os.environ, **(req.env or {})},
            stdout=subprocess.PIPE if req.wait else subprocess.DEVNULL,
            stderr=subprocess.PIPE if req.wait else subprocess.DEVNULL,
            shell=False,
            creationflags=0  # visible GUI app when applicable
        )
        return p
    except Exception as e:
        log.exception("Failed to start process")
        raise HTTPException(status_code=500, detail=f"Failed to start: {e}")


def _list_simple_processes() -> List[Dict[str, str]]:
    """Lightweight process list using 'tasklist' to avoid extra deps."""
    try:
        out = subprocess.check_output(["tasklist", "/FO", "CSV", "/NH"], text=True, encoding="utf-8", errors="ignore")
        rows = []
        for line in out.splitlines():
            if not line.strip():
                continue
            try:
                # CSV: "Image Name","PID","Session Name","Session#","Mem Usage"
                cols = [c.strip().strip('"') for c in line.split(",")]
                img, pid, sess_name, sess_id, mem = (cols + [""]*5)[:5]
                if any(img.lower().endswith(ext) for ext in PROCESS_LIST_FILTER):
                    rows.append({
                        "image": img,
                        "pid": pid,
                        "session": sess_name,
                        "session_id": sess_id,
                        "mem": mem,
                    })
            except Exception:
                continue
        return rows
    except Exception as e:
        log.warning("tasklist failed: %s", e)
        return []


# --------------------------- ROUTES ---------------------------
@app.get("/health")
def health() -> Dict[str, object]:
    return {"ok": True, "time": time.time(), "host": socket.gethostname()}


@app.get("/ps")
def ps(x_agent_secret: Optional[str] = Header(None)) -> Dict[str, object]:
    _auth_or_403(x_agent_secret)
    return {"procs": _list_simple_processes()}


@app.post("/launch")
def launch(req: LaunchRequest, x_agent_secret: Optional[str] = Header(None)) -> Dict[str, object]:
    _auth_or_403(x_agent_secret)
    p = _start_process(req)
    if not req.wait:
        return {"status": "started", "pid": p.pid, "exe": req.exe, "args": req.args or []}

    try:
        outs, errs = p.communicate(timeout=req.timeout_sec)
        return {
            "status": "exited",
            "pid": p.pid,
            "returncode": p.returncode,
            "stdout": (outs or b"").decode(errors="ignore"),
            "stderr": (errs or b"").decode(errors="ignore"),
        }
    except subprocess.TimeoutExpired:
        try:
            p.kill()
        except Exception:
            pass
        return {"status": "timeout_killed", "pid": p.pid}


@app.post("/kill")
def kill(req: KillRequest, x_agent_secret: Optional[str] = Header(None)) -> Dict[str, object]:
    _auth_or_403(x_agent_secret)
    try:
        os.kill(req.pid, signal.SIGTERM)
        return {"status": "terminated", "pid": req.pid}
    except PermissionError:
        raise HTTPException(status_code=403, detail="Permission denied to kill pid")
    except ProcessLookupError:
        return {"status": "not_found", "pid": req.pid}
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


# --------------------------- MAIN -----------------------------
if __name__ == "__main__":
    # Allow `python gui_launcher_agent.py` to run the server, useful for quick tests
    import uvicorn
    host = BIND_HOST
    port = BIND_PORT
    log.info("Starting GUI Launcher Agent on %s:%s", host, port)
    # $env:APP_AGENT_SECRET = "SuperSecret-ChangeMe"
    uvicorn.run("gui_launcher_agent:app", host=host, port=port, workers=1, loop="asyncio", http="h11", log_level="info")