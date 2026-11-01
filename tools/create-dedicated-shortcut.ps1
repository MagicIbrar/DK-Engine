param(
  [Parameter(Mandatory=$true)][string]$InstallRoot,
  [string]$Desktop = [Environment]::GetFolderPath('DesktopDirectory')
)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath($InstallRoot)
$target=Join-Path $root 'Client.exe'
$icon=Join-Path $root 'client-assets\dk-engine.ico'
if(-not (Test-Path -LiteralPath $target -PathType Leaf)){throw 'Dashboard executable is missing.'}
if(-not (Test-Path -LiteralPath $icon -PathType Leaf)){throw 'Dashboard icon is missing.'}
if(-not (Test-Path -LiteralPath $Desktop -PathType Container)){throw 'Desktop folder is unavailable.'}
$link=Join-Path $Desktop 'DK Engine.lnk'
$shell=New-Object -ComObject WScript.Shell
for($attempt=0;$attempt -lt 100;$attempt++){
 $name=if($attempt -eq 0){'DK Engine.lnk'}elseif($attempt -eq 1){'DK Engine 3.3.0.lnk'}else{'DK Engine 3.3.0 ('+$attempt+').lnk'}
 $link=Join-Path $Desktop $name
 if(-not (Test-Path -LiteralPath $link)){break}
 $existing=$shell.CreateShortcut($link)
 if([string]::Equals($existing.TargetPath,$target,[StringComparison]::OrdinalIgnoreCase) -and [string]::Equals($existing.WorkingDirectory,$root,[StringComparison]::OrdinalIgnoreCase)){Write-Output $link;exit 0}
 if($attempt -eq 99){throw 'No unused shortcut name is available; existing shortcuts were preserved.'}
}
$shortcut=$shell.CreateShortcut($link)
$shortcut.TargetPath=$target
$shortcut.WorkingDirectory=$root
$shortcut.IconLocation=$icon
$shortcut.Save()
Write-Output $link
