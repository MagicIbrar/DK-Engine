param([Parameter(Mandatory=$true)][string]$Archive,[Parameter(Mandatory=$true)][string]$Destination,[Parameter(Mandatory=$true)][string]$Version)
$ErrorActionPreference='Stop'
Add-Type -AssemblyName System.IO.Compression
if($Version -notmatch '^\d+\.\d+\.\d+$'){throw 'Invalid release version.'}
$dest=[IO.Path]::GetFullPath($Destination)
function Assert-NoReparse([string]$Location){
 $current=[IO.Path]::GetFullPath($Location)
 while($true){
  if(Test-Path -LiteralPath $current){$item=Get-Item -LiteralPath $current -Force;if(($item.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0){throw 'Linked release extraction paths are refused.'}}
  $parent=[IO.Path]::GetDirectoryName($current);if(-not $parent -or $parent -eq $current){break};$current=$parent
 }
}
Assert-NoReparse $Archive;Assert-NoReparse $dest
if(-not (Test-Path -LiteralPath $dest -PathType Container)){throw 'Extraction destination must exist.'}
if((Get-ChildItem -LiteralPath $dest -Force | Select-Object -First 1)){throw 'Extraction destination must be empty.'}
$stream=[IO.File]::OpenRead($Archive)
try{
 $zip=New-Object IO.Compression.ZipArchive($stream,[IO.Compression.ZipArchiveMode]::Read,$false)
 try{
  if($zip.Entries.Count -gt 10000){throw 'Release archive has too many entries.'}
  $seen=New-Object 'System.Collections.Generic.HashSet[string]' ([StringComparer]::OrdinalIgnoreCase)
  $total=[long]0;$files=0;$prefix='DK-'+$Version+'/Engine/'
  foreach($entry in $zip.Entries){
   $name=$entry.FullName
   if($name.Contains('\') -or $name.StartsWith('/') -or $name.Contains(':') -or $name.Contains([char]0)){throw 'Release archive contains an unsafe path.'}
   $parts=$name.Split('/')
   foreach($part in $parts){if($part -eq '..' -or $part -eq '.' -or $part.EndsWith(' ') -or $part.EndsWith('.') -or $part -match '^(?i:con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\.|$)'){throw 'Release archive contains an unsafe path.'}}
   if(-not $seen.Add($name)){throw 'Release archive contains duplicate paths.'}
   $unixMode=($entry.ExternalAttributes -shr 16) -band 0xF000
   if($unixMode -eq 0xA000){throw 'Release archive contains a link.'}
   if($name.EndsWith('/')){continue}
   if(-not $name.StartsWith($prefix,[StringComparison]::Ordinal)){continue}
   $rel=$name.Substring($prefix.Length)
   $segments=$rel.Split('/');if(-not $rel -or @($segments|Where-Object {-not $_}).Count){throw 'Release archive contains an unsafe engine path.'}
   if($entry.Length -gt 512MB){throw 'Release archive has an oversized file.'}
   $total+=$entry.Length;$files++
   if($total -gt 2GB){throw 'Release archive expands beyond the safe limit.'}
  }
  if($files -lt 100){throw 'Release archive is missing the full engine.'}
  foreach($entry in $zip.Entries){
   $name=$entry.FullName
   if($name.EndsWith('/') -or -not $name.StartsWith($prefix,[StringComparison]::Ordinal)){continue}
   $rel=$name.Substring($prefix.Length)
   $target=[IO.Path]::GetFullPath((Join-Path $dest ('Engine\'+$rel.Replace('/','\'))))
   if(-not $target.StartsWith((Join-Path $dest 'Engine')+'\',[StringComparison]::OrdinalIgnoreCase)){throw 'Release archive escapes extraction.'}
   [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target))|Out-Null
   $inputStream=$entry.Open();try{$output=[IO.File]::Open($target,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);try{$buffer=New-Object byte[] 65536;$written=[long]0;while(($read=$inputStream.Read($buffer,0,$buffer.Length)) -gt 0){$written+=$read;if($written -gt $entry.Length -or $written -gt 512MB){throw 'Release file exceeds its declared size.'};$output.Write($buffer,0,$read)};if($written -ne $entry.Length){throw 'Release file size mismatch.'}}finally{$output.Dispose()}}finally{$inputStream.Dispose()}
  }
  foreach($required in @('Client.exe','GameWindow.exe','server.mjs','package.json','tools\client-ui.ps1','tools\dedicated-client-entry.mjs','tools\upgrade-dedicated-install.mjs','tools\stage-dedicated-install.mjs','tools\release-update.mjs')){if(-not (Test-Path -LiteralPath (Join-Path $dest ('Engine\'+$required)) -PathType Leaf)){throw ('Release engine missing '+$required)}}
  $package=Get-Content -LiteralPath (Join-Path $dest 'Engine\package.json') -Raw|ConvertFrom-Json
  if($package.version -ne $Version){throw 'Release tag and engine version differ.'}
  Write-Output ('Verified release extraction: '+$files+' engine files.')
 }finally{$zip.Dispose()}
}finally{$stream.Dispose()}
