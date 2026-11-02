[CmdletBinding()]
param([switch]$ValidateOnly)
$ErrorActionPreference = 'Stop'
& (Join-Path $PSScriptRoot 'tools\command-center\branding\Start-VersionDashboard.ps1') -InstanceRoot (Split-Path -Parent $PSScriptRoot) -EngineRoot $PSScriptRoot -ProfileRoot (Join-Path $PSScriptRoot 'run\dashboard-profile') -Edition '4.2.0' -ValidateOnly:$ValidateOnly
