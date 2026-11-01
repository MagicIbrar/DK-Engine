# Private, pinned portable runtime. No administrator access, system install or PATH mutation.
# Pins verified from https://nodejs.org/dist/v22.23.3/SHASUMS256.txt on 2026-09-29.
$script:ClientNodeVersion = '22.23.3'
$script:ClientNodePins = @{
 x64 = @{Zip='2b0ff57b049cda1bbcea2240eec20467018713c1efe1f7360c2681859b90ed71';Exe='9c9245166b4a8e182e0b797da9c20136117ff24368eaff1fec8343a123c8db0e'}
 arm64 = @{Zip='33dad22e4cef5ee8f9fbb1b0d037fdacd0e56d12a4580f0d63f68b894deab535';Exe='b5a3165ec6f24c0b1fe2a10fed58e03f6c1d7d141beb3b225ff030ceac6c5eb5'}
}
function Assert-ClientRuntimePath([string]$Engine,[string]$Target) {
 $root=[IO.Path]::GetFullPath($Engine).TrimEnd('\','/')
 $absolute=[IO.Path]::GetFullPath($Target)
 if(-not ($absolute.Equals($root,[StringComparison]::OrdinalIgnoreCase) -or $absolute.StartsWith($root+[IO.Path]::DirectorySeparatorChar,[StringComparison]::OrdinalIgnoreCase))){throw 'Runtime path escaped the engine folder.'}
 $current=$absolute
 while($current){
  if(Test-Path -LiteralPath $current){$item=Get-Item -LiteralPath $current -Force;if(($item.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0){throw "Runtime refuses a link/junction: $current"}}
  $parent=[IO.Path]::GetDirectoryName($current);if($parent -eq $current){break};$current=$parent
 }
 return $absolute
}
function Get-ClientNodeArchitecture {
 $architecture=if($env:PROCESSOR_ARCHITEW6432){$env:PROCESSOR_ARCHITEW6432}else{$env:PROCESSOR_ARCHITECTURE}
 if($architecture -eq 'ARM64'){return 'arm64'}
 if($architecture -eq 'AMD64'){return 'x64'}
 throw 'The private client runtime requires 64-bit Windows (x64 or ARM64).'
}
function Get-ClientNodeVersion([string]$Source) {
 $start=New-Object Diagnostics.ProcessStartInfo
 $start.FileName=$Source;$start.Arguments='--version';$start.UseShellExecute=$false;$start.CreateNoWindow=$true
 $start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true
 $process=$null
 try{
  $process=[Diagnostics.Process]::Start($start)
  $stdout=$process.StandardOutput.ReadToEndAsync();$stderr=$process.StandardError.ReadToEndAsync()
  if(-not $process.WaitForExit(5000)){ $process.Kill();return $null }
  $version=$stdout.GetAwaiter().GetResult().Trim()
  if($process.ExitCode -eq 0 -and $version -match '^v(\d+)\.(\d+)\.(\d+)$' -and [int]$Matches[1] -ge 20){return $version}
 }catch{return $null}finally{if($process){$process.Dispose()}}
 return $null
}
function Assert-ClientDependencies([string]$Engine) {
 foreach($relative in @('node_modules\three\package.json','node_modules\three\build\three.module.js','node_modules\three\build\three.cjs','vendor\three.module.js','vendor\jsm\postprocessing\EffectComposer.js','vendor\jsm\postprocessing\Pass.js')){
  $file=Assert-ClientRuntimePath $Engine (Join-Path $Engine $relative)
  if(-not (Test-Path -LiteralPath $file -PathType Leaf)){throw "Engine package is incomplete: $relative is missing. Copy the complete engine release before retrying. No game files were deleted."}
 }
 $package=Get-Content -LiteralPath (Join-Path $Engine 'node_modules\three\package.json') -Raw | ConvertFrom-Json
 if($package.version -ne '0.170.0'){throw 'Engine requires the bundled Three 0.170.0 dependency. Copy the complete engine release before retrying.'}
}
function Get-ClientNode([string]$Engine) {
 if($script:dedicatedMode){
  $bundled=Assert-ClientRuntimePath $Engine (Join-Path $Engine 'runtime\node.exe')
  if(Test-Path -LiteralPath $bundled -PathType Leaf){
   $signature=Get-AuthenticodeSignature -LiteralPath $bundled
   if($signature.Status -ne 'Valid' -or -not $signature.SignerCertificate.Subject.Contains('OpenJS Foundation')){throw 'Bundled Node.js signature is not valid.'}
   $version=Get-ClientNodeVersion $bundled
   if($version -notmatch '^v(\d+)\.' -or [int]$Matches[1] -lt 24){throw 'Dedicated SQL requires Node.js 24 or newer.'}
   return [PSCustomObject]@{Source=$bundled;Version=$version;Private=$true}
  }
  . (Join-Path $PSScriptRoot 'bootstrap-dedicated-runtime.ps1')
  $dedicatedNode=Find-Node24
  if($dedicatedNode){return [PSCustomObject]@{Source=$dedicatedNode;Version=(Get-ClientNodeVersion $dedicatedNode);Private=$false}}
  throw 'Dedicated runtime is missing. Run the dedicated installer to prepare Node.js 24 and WebView2.'
 }

 $runtime=Assert-ClientRuntimePath $Engine (Join-Path $Engine 'runtime')
 if(Test-Path -LiteralPath $runtime -PathType Container){
  foreach($directory in @(Get-ChildItem -LiteralPath $runtime -Directory -Force | Sort-Object Name -Descending)){
   foreach($architecture in @('x64','arm64')){
    if($directory.Name -notlike "node-v$script:ClientNodeVersion-win-$architecture-*"){continue}
    $source=Assert-ClientRuntimePath $Engine (Join-Path $directory.FullName 'node.exe')
    if(-not (Test-Path -LiteralPath $source -PathType Leaf)){continue}
    if((Get-FileHash -LiteralPath $source -Algorithm SHA256).Hash.ToLowerInvariant() -ne $script:ClientNodePins[$architecture].Exe){continue}
    $version=Get-ClientNodeVersion $source
    if($version -eq "v$script:ClientNodeVersion"){return [PSCustomObject]@{Source=$source;Version=$version;Private=$true}}
   }
  }
 }
 foreach($candidate in @(Get-Command node.exe -All -CommandType Application -ErrorAction SilentlyContinue)){
  $version=Get-ClientNodeVersion $candidate.Source
  if($version){return [PSCustomObject]@{Source=$candidate.Source;Version=$version;Private=$false}}
 }
 return $null
}
# The server's memory limit chosen in dashboard > Settings > Server capacity (server\capacity.json memoryMB; 0 or
# missing = Node's automatic limit). It is a process limit, so it is applied here when the launcher STARTS the server
# (--max-old-space-size); the running server reports the limit it really has (/api/launcher/capacity live.memory.heapLimitMB).
function Get-ClientServerArguments([string]$Engine) {
 $arguments=@('server.mjs')
 try{
  $file=Join-Path $Engine 'server\capacity.json'
  if(Test-Path -LiteralPath $file -PathType Leaf){
   $saved=Get-Content -LiteralPath $file -Raw | ConvertFrom-Json
   $mb=0;if($null -ne $saved.memoryMB -and [int]::TryParse([string]$saved.memoryMB,[ref]$mb) -and $mb -ge 1024 -and $mb -le 1048576){$arguments=@("--max-old-space-size=$mb",'server.mjs')}
  }
 }catch{}
 return ,$arguments
}
# The log callback is best-effort: a failing logger must never abort the runtime download or the setup around it.
function Write-ClientRuntimeLog([scriptblock]$Log,[string]$Text) {
 if($Log){try{[void](& $Log $Text)}catch{}}
}
function Wait-ClientRuntimeTask($Task,[DateTime]$Deadline,[scriptblock]$Log) {
 while(-not $Task.IsCompleted){
  if([DateTime]::UtcNow -gt $Deadline){throw 'Runtime download timed out. Existing files were preserved; retry when the connection is available.'}
  if('System.Windows.Forms.Application' -as [type]){[Windows.Forms.Application]::DoEvents()}
  [Threading.Thread]::Sleep(50)
 }
 return $Task.GetAwaiter().GetResult()
}
function Receive-ClientRuntime([Uri]$Uri,[string]$Destination,[scriptblock]$Log) {
 if($Uri.Scheme -ne 'https' -or $Uri.Host -ne 'nodejs.org' -or $Uri.Port -ne 443){throw 'Runtime downloads must use official nodejs.org HTTPS.'}
 Add-Type -AssemblyName System.Net.Http
 [Net.ServicePointManager]::SecurityProtocol=[Net.SecurityProtocolType]::Tls12
 $handler=New-Object Net.Http.HttpClientHandler;$handler.AllowAutoRedirect=$false
 $client=New-Object Net.Http.HttpClient($handler);$client.Timeout=[TimeSpan]::FromMinutes(3)
 $response=$null;$input=$null;$output=$null;$deadline=[DateTime]::UtcNow.AddMinutes(3)
 try{
  $response=Wait-ClientRuntimeTask ($client.GetAsync($Uri,[Net.Http.HttpCompletionOption]::ResponseHeadersRead)) $deadline $Log
  [void]$response.EnsureSuccessStatusCode()
  $input=Wait-ClientRuntimeTask ($response.Content.ReadAsStreamAsync()) $deadline $Log
  $output=[IO.File]::Open($Destination,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
  $buffer=New-Object byte[] 65536;$total=0;$last=[DateTime]::UtcNow
  while($true){
   $count=Wait-ClientRuntimeTask ($input.ReadAsync($buffer,0,$buffer.Length)) $deadline $Log
   if($count -eq 0){break};$total+=$count
   if($total -gt 100MB){throw 'Runtime archive exceeded its safe download size limit.'}
   $output.Write($buffer,0,$count)
   if(([DateTime]::UtcNow-$last).TotalSeconds -ge 1){Write-ClientRuntimeLog $Log ("Downloading private Node runtime: {0:N1} MiB" -f ($total/1MB));$last=[DateTime]::UtcNow}
  }
 }finally{if($output){$output.Dispose()};if($input){$input.Dispose()};if($response){$response.Dispose()};$client.Dispose();$handler.Dispose()}
}
function Expand-ClientNodeArchive([string]$Archive,[string]$Stage,[string]$Architecture) {
 Add-Type -AssemblyName System.IO.Compression
 Add-Type -AssemblyName System.IO.Compression.FileSystem
 $zip=[IO.Compression.ZipFile]::OpenRead($Archive)
 try{
  foreach($name in @('node.exe','LICENSE')){
   $key="node-v$script:ClientNodeVersion-win-$Architecture/$name"
   $matches=@($zip.Entries | Where-Object {$_.FullName -ceq $key})
   if($matches.Count -ne 1 -or $matches[0].Length -gt 100MB){throw "Runtime archive is invalid: required $name entry is missing, duplicated or oversized."}
   # Never use archive paths as extraction destinations; only these two fixed files.
   [IO.Compression.ZipFileExtensions]::ExtractToFile($matches[0],(Join-Path $Stage $name),$false)
  }
 }finally{$zip.Dispose()}
}
function Ensure-ClientRuntime([string]$Engine,[scriptblock]$Log) {
 Assert-ClientDependencies $Engine
 $existing=Get-ClientNode $Engine
 if($existing){return $existing}
 $architecture=Get-ClientNodeArchitecture;$pin=$script:ClientNodePins[$architecture]
 $runtime=Assert-ClientRuntimePath $Engine (Join-Path $Engine 'runtime')
 [void][IO.Directory]::CreateDirectory($runtime)
 $stage=Assert-ClientRuntimePath $Engine (Join-Path $runtime ('.stage-'+[Guid]::NewGuid().ToString('N')))
 [void][IO.Directory]::CreateDirectory($stage)
 $archive=Join-Path $stage 'download.zip'
 try{
  Write-ClientRuntimeLog $Log "Installing verified private Node $script:ClientNodeVersion. System settings are unchanged."
  Receive-ClientRuntime ([Uri]"https://nodejs.org/dist/v$script:ClientNodeVersion/node-v$script:ClientNodeVersion-win-$architecture.zip") $archive $Log
  if((Get-FileHash -LiteralPath $archive -Algorithm SHA256).Hash.ToLowerInvariant() -ne $pin.Zip){throw 'Node download checksum mismatch. Downloaded bytes were not executed.'}
  Expand-ClientNodeArchive $archive $stage $architecture
  $binary=Assert-ClientRuntimePath $Engine (Join-Path $stage 'node.exe')
  if((Get-FileHash -LiteralPath $binary -Algorithm SHA256).Hash.ToLowerInvariant() -ne $pin.Exe){throw 'Node executable checksum mismatch. Downloaded bytes were not executed.'}
  if((Get-ClientNodeVersion $binary) -ne "v$script:ClientNodeVersion"){throw 'Verified Node runtime could not run on this Windows installation.'}
  Remove-Item -LiteralPath $archive -Force
  $destination=Assert-ClientRuntimePath $Engine (Join-Path $runtime ("node-v$script:ClientNodeVersion-win-$architecture-"+[Guid]::NewGuid().ToString('N')))
  [void](Assert-ClientRuntimePath $Engine $stage)
  [IO.Directory]::Move($stage,$destination)
  Write-ClientRuntimeLog $Log 'Private runtime ready.'
  return [PSCustomObject]@{Source=(Join-Path $destination 'node.exe');Version="v$script:ClientNodeVersion";Private=$true}
 }finally{
  if(Test-Path -LiteralPath $stage){
   [void](Assert-ClientRuntimePath $Engine $stage)
   foreach($entry in Get-ChildItem -LiteralPath $stage -Force -Recurse){if(($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0){throw 'Runtime staging cleanup refused a link/junction.'}}
   Remove-Item -LiteralPath $stage -Recurse -Force
  }
 }
}
