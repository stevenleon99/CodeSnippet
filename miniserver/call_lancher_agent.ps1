$r = Invoke-RestMethod -Method Get -Uri "http://127.0.0.1:8765/ps" `
  -Headers @{ "X-Agent-Secret" = "SuperSecret-ChangeMe" }

$r.procs | Select image,pid,session,session_id,mem | Format-Table -AutoSize

Invoke-RestMethod -Method Post -Uri "http://127.0.0.1:8765/launch" `
  -Headers @{ "X-Agent-Secret" = "SuperSecret-ChangeMe" } `
  -ContentType "application/json" `
  -Body (@{ exe='C:\Users\Steve\AppData\Roaming\Zoom\bin\Zoom.exe' } | ConvertTo-Json)