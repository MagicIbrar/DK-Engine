# DEDICATED: build only executables inside this separate copy.
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$compiler=@((Join-Path $env:WINDIR 'Microsoft.NET\Framework64\v4.0.30319\csc.exe'),(Join-Path $env:WINDIR 'Microsoft.NET\Framework\v4.0.30319\csc.exe')) | Where-Object {Test-Path -LiteralPath $_} | Select-Object -First 1
if(-not $compiler){throw 'The Windows .NET Framework C# compiler is unavailable.'}
$icon=Join-Path $root 'client-assets\dekaron-client.ico'
if(-not (Test-Path -LiteralPath $icon)){throw 'The copied game icon is missing.'}
& $compiler /nologo /target:winexe /platform:anycpu /optimize+ /reference:System.Windows.Forms.dll /reference:System.Drawing.dll ("/win32icon:"+$icon) ("/win32manifest:"+(Join-Path $PSScriptRoot 'DKClient.manifest')) ("/out:"+(Join-Path $root 'GameWindow.exe')) (Join-Path $PSScriptRoot 'DKClient.cs')
if($LASTEXITCODE -ne 0){throw 'GameWindow.exe build failed.'}
& $compiler /nologo /target:winexe /platform:anycpu /optimize+ /reference:System.Windows.Forms.dll /reference:System.Drawing.dll /reference:System.Web.Extensions.dll ("/win32icon:"+$icon) ("/out:"+(Join-Path $root 'Client.exe')) (Join-Path $PSScriptRoot 'launcher\DedicatedDashboard.cs')
if($LASTEXITCODE -ne 0){throw 'Client.exe build failed.'}
Write-Output 'Built DK Client.exe and GameWindow.exe.'
