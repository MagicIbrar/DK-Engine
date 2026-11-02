[CmdletBinding()]
param(
  [Parameter(Mandatory=$true)][string]$InstanceRoot,
  [Parameter(Mandatory=$true)][string]$EngineRoot,
  [Parameter(Mandatory=$true)][string]$ProfileRoot,
  [Parameter(Mandatory=$true)][string]$Edition,
  [switch]$ValidateOnly
)
$ErrorActionPreference = 'Stop'
$app = Split-Path -Parent $PSScriptRoot
$exe = Join-Path $app 'DKCommandCenter.exe'
$identity = Join-Path $PSScriptRoot 'DashboardIdentity.exe'
$receipt = Join-Path $ProfileRoot 'dashboard-identity.json'
foreach ($required in @($exe, $identity, (Join-Path $app 'dk-logo.ico'), (Join-Path $app 'backend\main.mjs'))) {
  if (-not (Test-Path -LiteralPath $required -PathType Leaf)) { throw "Missing this edition's dashboard file: $required" }
}
# Pass only this project's paths. A shared installer or another installed edition is never selected.
function Quote-Argument([string]$value) { '"' + [regex]::Replace([regex]::Replace($value, '(\\*)"', '$1$1\"'), '(\\+)$', '$1$1') + '"' }
$check = New-Object System.Diagnostics.ProcessStartInfo
$check.FileName = $identity
$mode = if ($ValidateOnly) { 'validate' } else { 'apply' }
$check.Arguments = (@($mode,$exe,$InstanceRoot,$Edition,$receipt) | ForEach-Object { Quote-Argument $_ }) -join ' '
$check.UseShellExecute = $false
$check.CreateNoWindow = $true
$check.RedirectStandardOutput = $true
$check.RedirectStandardError = $true
$process = [System.Diagnostics.Process]::Start($check)
$result = $process.StandardOutput.ReadToEnd()
$failure = $process.StandardError.ReadToEnd()
$process.WaitForExit()
$exitCode = $process.ExitCode
$process.Dispose()
if ($exitCode -ne 0) { throw "This edition's dashboard identity check failed: $failure" }
$verified = $result | ConvertFrom-Json
if ($ValidateOnly) {
  [pscustomobject]@{ edition=$Edition; instanceRoot=$InstanceRoot; dashboard=$exe; engine=$EngineRoot; profile=$ProfileRoot; icon=(Join-Path $app 'dk-logo.ico'); appUserModelId=$verified.appUserModelId; identityChangesRequired=$verified.changed; startsProcesses=$false } | ConvertTo-Json -Compress
  return
}
$launch = New-Object System.Diagnostics.ProcessStartInfo
$launch.FileName = $exe
$launch.WorkingDirectory = $app
$launch.Arguments = '--profile ' + (Quote-Argument $ProfileRoot)
$launch.UseShellExecute = $false
$launch.CreateNoWindow = $true
foreach ($key in @($launch.EnvironmentVariables.Keys)) { if ($key -like 'DKCC_*') { $launch.EnvironmentVariables.Remove($key) } }
$launch.EnvironmentVariables['DKCC_MODE'] = 'install'
$launch.EnvironmentVariables['DKCC_APP'] = $app
$launch.EnvironmentVariables['DKCC_ENGINE'] = $EngineRoot
$launch.EnvironmentVariables['DKCC_PROFILE'] = $ProfileRoot
$started = [System.Diagnostics.Process]::Start($launch)
$started.Dispose()
