# Per-install local ports only. No listener is stopped or killed by this module.
function Assert-ClientPortPath([string]$Path) {
 $current=[IO.Path]::GetFullPath($Path)
 while($current){if(Test-Path -LiteralPath $current){$entry=Get-Item -LiteralPath $current -Force;if(($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0 -or $entry.LinkType -eq 'HardLink'){throw 'Local port state must not use linked paths.'}};$next=[IO.Path]::GetDirectoryName($current);if($next -eq $current){break};$current=$next}
}
function Read-ClientPortJson([string]$Path) {
 Assert-ClientPortPath $Path
 if(-not (Test-Path -LiteralPath $Path)){return $null}
 $entry=Get-Item -LiteralPath $Path -Force;if($entry.PSIsContainer -or $entry.Length -gt 16384){throw 'Invalid private local port state.'}
 return ([IO.File]::ReadAllText($Path)|ConvertFrom-Json)
}
function Get-ClientPortHttp([int]$Port,[string]$Route,[string]$Token) {
 $request=[Net.HttpWebRequest]::Create('http://127.0.0.1:'+ $Port + $Route);$request.AllowAutoRedirect=$false;$request.Proxy=$null;$request.Timeout=400;$request.ReadWriteTimeout=400
 if($Token){$request.Headers.Add('x-dekaron-launcher-token',$Token)}
 try{$response=$request.GetResponse();try{if([int]$response.StatusCode -ne 200){return $null};$stream=$response.GetResponseStream();$memory=New-Object IO.MemoryStream;try{$buffer=New-Object byte[] 4096;while(($count=$stream.Read($buffer,0,$buffer.Length)) -gt 0){$memory.Write($buffer,0,$count);if($memory.Length -gt 16384){return $null}};return ([Text.Encoding]::UTF8.GetString($memory.ToArray())|ConvertFrom-Json)}finally{$memory.Dispose();$stream.Dispose()}}finally{$response.Dispose()}}catch{return $null}
}
function Test-ClientPortOwned([string]$Engine,[string]$EngineId,[int]$Port) {
 $status=Get-ClientPortHttp $Port '/api/client/status' ''
 if(-not $status -or $status.app -cne 'dekaron-engine' -or $status.engineId -cne $EngineId){return $false}
 $recovery='This installation already has a server, but its private control cannot be verified. Close that server normally, then press Start. No process was stopped.'
 if([int]$status.pid -le 0){throw $recovery}
 $file=Join-Path $Engine ('server\launcher-control-'+$Port+'.json');if(-not(Test-Path -LiteralPath $file)){$file=Join-Path $Engine 'server\launcher-control.json'};if(-not(Test-Path -LiteralPath $file)){throw $recovery}
 $control=Read-ClientPortJson $file
 if(-not $control -or $control.engineId -cne $EngineId -or [int]$control.pid -ne [int]$status.pid -or $control.token -notmatch '^[a-f0-9]{64}$'){throw $recovery}
 try{$uri=[Uri]$control.url;if($uri.Scheme -cne 'http' -or -not $uri.IsLoopback -or $uri.Port -ne $Port -or $uri.UserInfo -or $uri.Query -or $uri.Fragment -or $uri.AbsolutePath -ne '/'){throw $recovery};$process=[Diagnostics.Process]::GetProcessById([int]$control.pid);try{if($process.HasExited){throw $recovery}}finally{$process.Dispose()}}catch{throw $recovery}
 $private=Get-ClientPortHttp $Port '/api/launcher/status' $control.token
 if($null -eq $private -or $private.engineId -cne $EngineId -or [int]$private.pid -ne [int]$control.pid -or $private.stopping){throw $recovery};return $true
}
function Get-ClientPortMutex([string]$Name) {
 $mutex=New-Object Threading.Mutex($false,('Local\DekaronLocalPort-'+$Name));$owned=$false
 try{try{$owned=$mutex.WaitOne(0)}catch [Threading.AbandonedMutexException]{$owned=$true};if(-not $owned){$mutex.Dispose();return $null};return $mutex}catch{$mutex.Dispose();throw}
}
function Get-ClientFreePort([int]$Port) {
 $ipv6=$null;
 $listener=New-Object Net.Sockets.TcpListener([Net.IPAddress]::Loopback,$Port);$listener.ExclusiveAddressUse=$true
 try{$listener.Start();$chosen=[int]$listener.LocalEndpoint.Port;try{$ipv6=New-Object Net.Sockets.TcpListener([Net.IPAddress]::IPv6Loopback,$chosen);$ipv6.ExclusiveAddressUse=$true;$ipv6.Server.DualMode=$false;$ipv6.Start()}catch [Net.Sockets.SocketException]{if($_.Exception.SocketErrorCode -ne [Net.Sockets.SocketError]::AddressFamilyNotSupported){return 0}};return $chosen}catch [Net.Sockets.SocketException]{return 0}finally{if($ipv6){$ipv6.Stop()};$listener.Stop()}
}
function Release-ClientLocalPort($Selection) {
 if(-not $Selection -or $Selection.released){return};$Selection.released=$true
 foreach($mutex in @($Selection.reservation,$Selection.engineReservation)){if($mutex){try{$mutex.ReleaseMutex()}finally{$mutex.Dispose()}}}
}
function Assert-ClientLocalPort($Selection,[string]$Engine,[string]$EngineId) {
 if(-not $Selection -or $Selection.released){throw 'The local port reservation expired.'}
 if(Test-ClientPortOwned $Engine $EngineId $Selection.port){return}
 if((Get-ClientFreePort $Selection.port) -ne $Selection.port){throw 'Another process took the selected address. Nothing was stopped. Press Start again.'}
}
function Get-ClientLocalPort([string]$Engine,[string]$EngineId,[string]$ExplicitPort='',[int]$PreferredPort=7777) {
 $enginePath=[IO.Path]::GetFullPath($Engine).TrimEnd('\');Assert-ClientPortPath $enginePath
 if(-not(Test-Path -LiteralPath (Join-Path $enginePath 'server') -PathType Container) -or $EngineId -notmatch '^[a-f0-9]{64}$'){throw 'Select a verified complete engine before choosing its local address.'}
 if($PreferredPort -lt 1 -or $PreferredPort -gt 65535){throw 'Invalid preferred local port.'}
 $explicit=-not [string]::IsNullOrWhiteSpace($ExplicitPort)
 if($explicit -and ($ExplicitPort -notmatch '^\d+$' -or [double]$ExplicitPort -lt 1 -or [double]$ExplicitPort -gt 65535)){throw 'PORT must be between 1 and 65535.'}
 $engineMutex=Get-ClientPortMutex ('engine-'+$EngineId);if(-not $engineMutex){throw 'This installation is already starting. Wait for its launcher.'}
 $selection=$null;$portMutex=$null
 try{
  $stateFile=Join-Path $enginePath 'server\launcher-port.json';$sticky=Read-ClientPortJson $stateFile
  if($sticky -and ($sticky.version -ne 1 -or @($sticky.PSObject.Properties.Name|Where-Object{$_ -notin @('version','port')}).Count -gt 0 -or $sticky.port -isnot [int] -or $sticky.port -lt 1 -or $sticky.port -gt 65535 -or $sticky.port -in @(7778,7840))){throw 'Invalid saved local port. No listener was changed.'}
  $candidate=$(if($explicit){[int]$ExplicitPort}elseif($sticky){[int]$sticky.port}else{$PreferredPort})
  # Never create a second writer for this engine when its known local server survives.
  $known=@($PreferredPort,$candidate)
  $controlFiles=@(Get-ChildItem -LiteralPath (Join-Path $enginePath 'server') -Filter 'launcher-control*.json' -File)
  if($controlFiles.Count -gt 64){throw 'Too many saved server controls. Resolve the existing local server before starting another.'}
  foreach($recordFile in $controlFiles){$record=Read-ClientPortJson $recordFile.FullName;if($record.engineId -cne $EngineId -or [int]$record.pid -le 0){continue};try{$live=[Diagnostics.Process]::GetProcessById([int]$record.pid);$live.Dispose();$recordUri=[Uri]$record.url;if($recordUri.IsLoopback -and $recordUri.Scheme -eq 'http' -and $recordUri.Port -notin @(7778,7840)){$known+=$recordUri.Port}}catch{}}
  $ownedPorts=@();foreach($knownPort in ($known|Select-Object -Unique)){if($knownPort -in @(7778,7840) -and -not($explicit -and $knownPort -eq $candidate)){continue};if(Test-ClientPortOwned $enginePath $EngineId $knownPort){$ownedPorts+=$knownPort}}
  if($ownedPorts.Count -gt 1){throw 'More than one local server is using this installation. Resolve those servers before starting again. Nothing was stopped.'}
  if($ownedPorts.Count -eq 1){if($explicit -and $ownedPorts[0] -ne $candidate){throw 'This installation is already running on another local port. Explicit PORT was preserved; no second server was started.'};$candidate=[int]$ownedPorts[0]}
  for($attempt=0;$attempt -lt 24;$attempt++){
   $portMutex=Get-ClientPortMutex ('port-'+$candidate)
   if($portMutex){$owned=Test-ClientPortOwned $enginePath $EngineId $candidate;$free=$(if($owned){$candidate}else{Get-ClientFreePort $candidate});if($owned -or $free -eq $candidate){$selection=[pscustomobject]@{port=$candidate;url=('http://localhost:'+ $candidate +'/');existing=$owned;reservation=$portMutex;engineReservation=$engineMutex;released=$false};break};$portMutex.ReleaseMutex();$portMutex.Dispose();$portMutex=$null}
   if($explicit){throw 'Explicit PORT is busy or unverified. No process was stopped.'}
   do{$candidate=Get-ClientFreePort 0}while($candidate -in @(0,7778,7840))
  }
  if(-not $selection){throw 'No available local address could be reserved. No process was stopped.'}
  # Recheck immediately before persisting; callers recheck again before spawning.
  Assert-ClientLocalPort $selection $enginePath $EngineId
  if(-not $explicit){Assert-ClientPortPath $stateFile;$temporary=$stateFile+'.'+[Guid]::NewGuid().ToString('N')+'.tmp';try{[IO.File]::WriteAllText($temporary,(@{version=1;port=$selection.port}|ConvertTo-Json -Compress),(New-Object Text.UTF8Encoding($false)));if(Test-Path -LiteralPath $stateFile){[IO.File]::Replace($temporary,$stateFile,[System.Management.Automation.Language.NullString]::Value)}else{[IO.File]::Move($temporary,$stateFile)}}finally{if(Test-Path -LiteralPath $temporary){Remove-Item -LiteralPath $temporary -Force}}}
  return $selection
 }catch{if($selection){Release-ClientLocalPort $selection}else{if($portMutex){try{$portMutex.ReleaseMutex()}finally{$portMutex.Dispose()}};$engineMutex.ReleaseMutex();$engineMutex.Dispose()};throw}
}
