# Exact adjacent installation only; cleanup requires the explicit first-install confirmation.
function Assert-ClientFolder([string]$Root) {
 $rootPath=[IO.Path]::GetFullPath($Root).TrimEnd('\')
 if(-not (Test-Path -LiteralPath $rootPath -PathType Container)){throw 'Choose the Dekaron game folder containing data and bin.'}
 $blocked=@([IO.Path]::GetPathRoot($rootPath).TrimEnd('\'),$env:USERPROFILE,$env:WINDIR,$env:ProgramFiles,${env:ProgramFiles(x86)},$env:ProgramData)
 foreach($name in @('Desktop','Downloads','Documents','Pictures','Videos','Music','AppData')){$blocked+=Join-Path $env:USERPROFILE $name}
 foreach($folder in $blocked){if($folder -and $rootPath -ieq $folder.TrimEnd('\')){throw 'Choose a dedicated Dekaron folder, not a drive, Windows folder, or personal folder.'}}
 Assert-ClientPathUnlinked $rootPath
 foreach($name in @('data','bin')){
  $folder=Join-Path $rootPath $name
  if(-not (Test-Path -LiteralPath $folder -PathType Container)){throw 'This folder must contain both the original data and bin folders.'}
  Assert-ClientPathUnlinked $folder
 }
 return $rootPath
}
function Assert-ClientPathUnlinked([string]$Path) {
 $current=[IO.Path]::GetFullPath($Path)
 while($current){
  if(Test-Path -LiteralPath $current){$entry=Get-Item -LiteralPath $current -Force;if(($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0){throw "Linked folders/files are not supported: $current"}}
  $parent=[IO.Path]::GetDirectoryName($current);if($parent -eq $current){break};$current=$parent
 }
}
# Only the exact parent of this engine is eligible; never search other installations.
function Get-AdjacentClientFolder([string]$Engine) {
 $enginePath=[IO.Path]::GetFullPath($Engine).TrimEnd('\')
 if([IO.Path]::GetFileName($enginePath) -ine 'engine' -or -not (Test-Path -LiteralPath $enginePath -PathType Container)){throw 'Place the complete engine folder inside Dekaron, beside data and bin, then open engine\Client.exe.'}
 Assert-ClientPathUnlinked $enginePath
 return Assert-ClientFolder ([IO.Path]::GetDirectoryName($enginePath))
}
function Find-ClientFolders([string]$Engine) {
 try {return @(Get-AdjacentClientFolder $Engine)} catch {return @()}
}
function Get-ClientLocationPlan([string]$Root) {
 $target=Assert-ClientFolder $Root
 $extras=@(Get-ChildItem -LiteralPath $target -Force | Where-Object {$_.Name.ToLowerInvariant() -notin @('data','bin','engine','client.exe')} | Sort-Object Name | ForEach-Object {$_.Name})
 return [pscustomobject]@{root=$target;engine=(Join-Path $target 'engine');remove=$extras;clientName='Client.exe';provisional=$true}
}
function Copy-ClientEngine([string]$Source,[string]$Root) {
 $target=Assert-ClientFolder $Root
 $sourcePath=[IO.Path]::GetFullPath($Source).TrimEnd('\');Assert-ClientPathUnlinked $sourcePath
 $destination=Join-Path $target 'engine'
 if($sourcePath -ieq $destination){return $destination}
 if($destination.StartsWith($sourcePath+'\',[StringComparison]::OrdinalIgnoreCase)){throw 'The installation cannot be inside the downloaded engine folder.'}
 Assert-ClientPathUnlinked $destination
 # Copy the tool allowlist only. Never copy accounts, sessions, logs, unpacked data or caches.
 $roots=@('Client.exe','index.html','join.html','launch.html','server.mjs','package.json','package-lock.json','README.md','INSTALL.txt','THIRD_PARTY_NOTICES.md','Play.bat','Install.bat','GameClient.bat','Client.bat')
 $relative=New-Object 'System.Collections.Generic.List[string]'
 foreach($file in $roots){if(Test-Path -LiteralPath (Join-Path $sourcePath $file) -PathType Leaf){$relative.Add($file)}}
 foreach($dir in @('src','server','tools','site')){
  $dirPath=Join-Path $sourcePath $dir
  if(-not (Test-Path -LiteralPath $dirPath)){continue}
  foreach($entry in Get-ChildItem -LiteralPath $dirPath -Recurse -Force -File){if($entry.Extension.ToLowerInvariant() -in @('.js','.mjs','.css','.html','.ps1','.bat','.cs')){$relative.Add($entry.FullName.Substring($sourcePath.Length+1))}}
 }
 foreach($dir in @('vendor','node_modules\three\build','node_modules\three\src')){
  $dirPath=Join-Path $sourcePath $dir
  if(Test-Path -LiteralPath $dirPath){foreach($entry in Get-ChildItem -LiteralPath $dirPath -Recurse -Force -File){if($entry.Extension -in @('.js','.cjs','.json') -or $entry.Name -eq 'LICENSE'){$relative.Add($entry.FullName.Substring($sourcePath.Length+1))}}}
 }
 foreach($file in @('node_modules\three\package.json','node_modules\three\LICENSE','client-assets\dk-engine-logo-v1.png','client-assets\launcher-background-v1.png','client-assets\dk-engine-emblem-v1.png','client-assets\dk-engine.ico','docs\DISTRIBUTION.md','docs\HOSTING.md','docs\MULTIPLAYER.md','docs\TODO.md','docs\CLIENT-UPDATES.md')){if(Test-Path -LiteralPath (Join-Path $sourcePath $file) -PathType Leaf){$relative.Add($file)}}
 foreach($required in @('Client.exe','server.mjs','tools\client-ui.ps1','tools\install-client.mjs','vendor\three.module.js')){if(-not (Test-Path -LiteralPath (Join-Path $sourcePath $required) -PathType Leaf)){throw "Incomplete engine download: missing $required"}}
 # Validate every input/output before the first write; existing private state is outside this allowlist.
 foreach($name in $relative){
  $from=Join-Path $sourcePath $name;$to=[IO.Path]::GetFullPath((Join-Path $destination $name))
  if(-not $to.StartsWith($destination+'\',[StringComparison]::OrdinalIgnoreCase)){throw 'Engine copy escaped its target.'}
  Assert-ClientPathUnlinked $from;Assert-ClientPathUnlinked $to
 }
 foreach($name in $relative){
  $to=Join-Path $destination $name;[void][IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($to))
  $staged=$to+'.install-'+[Guid]::NewGuid().ToString('N')
  try{[IO.File]::Copy((Join-Path $sourcePath $name),$staged,$false);if([IO.File]::Exists($to)){[IO.File]::Replace($staged,$to,[NullString]::Value)}else{[IO.File]::Move($staged,$to)}}finally{if([IO.File]::Exists($staged)){Remove-Item -LiteralPath $staged -Force}}
 }
 return $destination
}
function New-ClientDesktopShortcut([string]$Root,[string]$Desktop=[Environment]::GetFolderPath('Desktop')) {
 $target=Assert-ClientFolder $Root
 $exe=Join-Path $target 'Client.exe';if(-not (Test-Path -LiteralPath $exe -PathType Leaf)){throw 'The installed launcher is missing.'};Assert-ClientPathUnlinked $exe
 $shortcutPath=Join-Path $Desktop 'DK Engine.lnk';Assert-ClientPathUnlinked $shortcutPath
 $shell=New-Object -ComObject WScript.Shell
 try{$shortcut=$shell.CreateShortcut($shortcutPath);$shortcut.TargetPath=$exe;$shortcut.WorkingDirectory=$target;$shortcut.IconLocation=$exe+',0';$shortcut.Description='Dekaron Online';$shortcut.Save()}finally{if($shortcut){[void][Runtime.InteropServices.Marshal]::FinalReleaseComObject($shortcut)};[void][Runtime.InteropServices.Marshal]::FinalReleaseComObject($shell)}
 return $shortcutPath
}
