$destination = "D:\CodeSnippet\winsh\dest"
$repoUrl = "https://github.com/huggingface/transformers.git"

try {
    $proc = Start-Process git -ArgumentList "clone", "--progress", $repoUrl, $destination `
        -NoNewWindow -RedirectStandardError temp.txt -PassThru

    while (-not $proc.HasExited) {
        Start-Sleep -Milliseconds 500
        $lines = Get-Content temp.txt
        $last = $lines[-1]
        if ($last -match 'Receiving objects:\s+(\d+)%') {
            $percent = [int]$matches[1]
            Write-Progress -Activity "Cloning repository..." -PercentComplete $percent
        }
    }
    Write-Progress -Activity "Cloning repository..." -Completed
}
catch {
    Write-Host "Clone failed: $($_.Exception.Message)" -ForegroundColor Red
}