param(
  [Parameter(Mandatory=$true)][string]$InstallRoot,
  [string]$Desktop = [Environment]::GetFolderPath('DesktopDirectory')
)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath($InstallRoot)
if(-not (Test-Path -LiteralPath $Desktop -PathType Container)){throw 'Desktop folder is unavailable.'}

function Resolve-EngineLaunchTarget([string]$EngineRoot){
  $candidates=@(
    (Join-Path $EngineRoot 'Client.exe'),
    (Join-Path $EngineRoot 'DKCommandCenter.exe'),
    (Join-Path $EngineRoot 'tools\command-center\DKCommandCenter.exe')
  )
  foreach($path in $candidates){
    if(Test-Path -LiteralPath $path -PathType Leaf){
      return [pscustomobject]@{
        Target=[IO.Path]::GetFullPath($path)
        WorkingDirectory=[IO.Path]::GetFullPath([IO.Path]::GetDirectoryName($path))
      }
    }
  }
  throw 'Dashboard executable is missing (DKCommandCenter.exe or Client.exe).'
}

function Resolve-EngineShortcutIcon([string]$EngineRoot,[string]$TargetPath){
  $targetDir=[IO.Path]::GetDirectoryName($TargetPath)
  $candidates=@(
    (Join-Path $EngineRoot 'client-assets\dekaron-client.ico'),
    (Join-Path $targetDir 'dk-engine-transparent-4.1.1.ico'),
    (Join-Path $EngineRoot 'dk-engine-transparent-4.1.1.ico'),
    (Join-Path $EngineRoot 'tools\command-center\dk-engine-transparent-4.1.1.ico'),
    (Join-Path $EngineRoot 'DKCommandCenter.ico'),
    (Join-Path $EngineRoot 'client-assets\dk-engine.ico'),
    (Join-Path $targetDir 'dk-logo.ico')
  )
  foreach($path in $candidates){
    if(Test-Path -LiteralPath $path -PathType Leaf){return ([IO.Path]::GetFullPath($path)+',0')}
  }
  return ($TargetPath+',0')
}

$launch=Resolve-EngineLaunchTarget $root
$target=$launch.Target
$workdir=$launch.WorkingDirectory
$icon=Resolve-EngineShortcutIcon $root $target
$shell=New-Object -ComObject WScript.Shell

# Prefer current branding; keep legacy DK Engine names so upgrades do not duplicate shortcuts.
$names=@(
  'Dekaron Engine 4.1.1.lnk',
  'DK Engine.lnk',
  'DK Engine 4.1.1.lnk',
  'Dekaron Engine.lnk',
  'DK Engine 3.3.0.lnk'
)
for($attempt=0;$attempt -lt 100;$attempt++){
  $name=if($attempt -lt $names.Count){$names[$attempt]}else{'Dekaron Engine 4.1.1 ('+$attempt+').lnk'}
  $link=Join-Path $Desktop $name
  if(-not (Test-Path -LiteralPath $link)){break}
  $existing=$shell.CreateShortcut($link)
  $sameTarget=[string]::Equals($existing.TargetPath,$target,[StringComparison]::OrdinalIgnoreCase)
  $sameWork=[string]::Equals($existing.WorkingDirectory,$workdir,[StringComparison]::OrdinalIgnoreCase)
  if($sameTarget -and $sameWork){
    # Refresh icon to current transparent Engine crest when an older icon is still attached.
    if(-not [string]::Equals(($existing.IconLocation+''),$icon,[StringComparison]::OrdinalIgnoreCase)){
      $existing.IconLocation=$icon
      $existing.Save()
    }
    Write-Output $link
    exit 0
  }
  if($attempt -eq 99){throw 'No unused shortcut name is available; existing shortcuts were preserved.'}
}

$shortcut=$shell.CreateShortcut($link)
$shortcut.TargetPath=$target
$shortcut.WorkingDirectory=$workdir
$shortcut.IconLocation=$icon
$shortcut.Description='Dekaron Engine'
$shortcut.Save()
Write-Output $link
