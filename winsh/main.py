import subprocess

# Path to your PowerShell script
ps_script_path = r"D:\CodeSnippet\winsh\script.ps1"

# Build the PowerShell command
cmd = [
    "powershell.exe",
    "-NoProfile",
    "-ExecutionPolicy", "Bypass",
    "-File", ps_script_path
]

try:
    # Run the PowerShell script and capture output
    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    print("Output:\n", result.stdout)
    if result.stderr:
        print("Errors:\n", result.stderr)
except subprocess.CalledProcessError as e:
    print(f"PowerShell script failed with return code {e.returncode}")
    print(e.output)