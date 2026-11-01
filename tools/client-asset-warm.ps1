# Desktop-only local prepared-asset verification. No remote asset paths or account URLs enter the child.
function Start-AssetWarmProcess($StartInfo){[Diagnostics.Process]::Start($StartInfo)}
function Invoke-DedicatedAssetWarm([scriptblock]$StillCurrent={return $true},[scriptblock]$Report={param($Message)},[scriptblock]$OnProgress={param($State)}) {
 if(-not $script:dedicatedMode -or $script:remoteWorld){return}
 $helper=Join-Path $clientEngine 'tools\verify-warm-assets.mjs';Assert-ClientPathUnlinked $helper
 $phase=Join-Path ([IO.Path]::GetTempPath()) ('dekaron-asset-warm-'+[Guid]::NewGuid().ToString('N')+'.json')
 $process=$null
 try{
  & $Report 'Verify and warm all installed assets: counting files...'
  $start=New-Object Diagnostics.ProcessStartInfo;$start.FileName=$clientNode.Source;$start.Arguments='"'+$helper+'" --engine "'+$clientEngine+'" --progress "'+$phase+'"';$start.WorkingDirectory=$clientEngine;$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true
  $process=Start-AssetWarmProcess $start;$output=$process.StandardOutput.ReadToEndAsync();$errors=$process.StandardError.ReadToEndAsync()
  while(-not $process.HasExited){
   if($script:closeRequested -or -not (& $StillCurrent)){throw 'Asset preload cancelled. Game launch stopped.'}
   $state=$null;if(Test-Path -LiteralPath $phase){try{$state=[IO.File]::ReadAllText($phase)|ConvertFrom-Json}catch{}};if($state){& $OnProgress $state;& $Report ('Verify and warm all installed assets: '+$state.files+'/'+$state.totalFiles+' files, '+[Math]::Round($state.bytes/1MB,1)+'/'+[Math]::Round($state.totalBytes/1MB,1)+' MiB')}
   [Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(100)
  }
  if($process.ExitCode -ne 0){throw ($errors.GetAwaiter().GetResult()+$output.GetAwaiter().GetResult())}
  if($script:closeRequested -or -not (& $StillCurrent)){throw 'Asset preload cancelled. Game launch stopped.'}
  $reply=$output.GetAwaiter().GetResult()|ConvertFrom-Json;if(-not $reply.verified -or $reply.bytes -ne $reply.totalBytes){throw 'Full asset verification did not complete. Game launch stopped.'}; & $OnProgress $reply
 }finally{if($process){if(-not $process.HasExited){$process.Kill();$process.WaitForExit()};$process.Dispose()};if(Test-Path -LiteralPath $phase){Remove-Item -LiteralPath $phase -Force}}
}

# Same native window spans local full-byte verification and authenticated frontend readiness.
# Only private inherited stdin carries progress and the fresh ticket; no disk ticket or HTTP control route.
function Start-NativePreloadWindow([string]$Account,[bool]$Borderless=$false,[scriptblock]$StillCurrent={return $true}) {
 $process=$null
 $art=Join-Path ([IO.Path]::GetTempPath()) ('dk-loading-'+[Guid]::NewGuid().ToString('N')+'.png')
 $helper=Join-Path $clientEngine 'tools\native-preload-art.mjs';Assert-ClientPathUnlinked $helper
 try{
  & $clientNode.Source $helper $clientEngine $art
  if($LASTEXITCODE -ne 0){throw 'The installed native loading artwork could not be prepared.'}
  $exe=Join-Path $clientEngine 'GameWindow.exe';Assert-ClientPathUnlinked $exe
  $origin=([Uri]$script:authUrl).GetLeftPart([UriPartial]::Authority);if(-not ([Uri]$origin).IsLoopback){throw 'Local native preload requires the local server.'}
  $profile=$Account.ToLowerInvariant();if($profile -notmatch '^[a-z0-9_-]{1,32}$'){$profile='player'}
  $start=New-Object Diagnostics.ProcessStartInfo;$start.FileName=$exe;$start.WorkingDirectory=$clientEngine;$start.UseShellExecute=$false;$start.RedirectStandardInput=$true;$start.RedirectStandardOutput=$true;$start.CreateNoWindow=$true
  $start.Arguments='--preload-image "'+$art+'" --preload-origin "'+$origin+'" --profile '+$profile+$(if($Borderless){' --borderless'}else{' --windowed'})
  $process=[Diagnostics.Process]::Start($start);if(-not $process){throw 'The native loading window did not start.'}
  $ready=$process.StandardOutput.ReadLineAsync();$timer=[Diagnostics.Stopwatch]::StartNew();while(-not $ready.IsCompleted){if($process.HasExited -or $timer.Elapsed.TotalSeconds -gt 20 -or -not (& $StillCurrent)){throw 'The native loading window did not become ready.'};[Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(25)};if($ready.GetAwaiter().GetResult() -cne 'PRELOAD_READY'){throw 'The native loading window handshake failed.'}
  return [pscustomobject]@{process=$process;art=$art;handedOff=$false}
 }catch{if($process){if(-not $process.HasExited){$process.Kill();$process.WaitForExit()};$process.Dispose()};if(Test-Path -LiteralPath $art){Remove-Item -LiteralPath $art -Force};throw}
}
function Send-NativePreloadProgress($Window,$State) {
 if($Window.process.HasExited){throw 'The native loading window was closed. Game launch stopped.'}
 if($State.phase -eq 'inventory'){$done=[long]$State.files;$total=[long]$State.totalFiles;if($total -gt 0 -and $done -ge 0 -and $done -le $total){$Window.process.StandardInput.WriteLine('INVENTORY '+$done+' '+$total);$Window.process.StandardInput.Flush()};return}
 $done=[long]$State.bytes;$total=[long]$State.totalBytes;$files=[long]$State.files;$totalFiles=[long]$State.totalFiles
 if($total -gt 0 -and $done -ge 0 -and $done -le $total -and $totalFiles -gt 0 -and $files -ge 0 -and $files -le $totalFiles){$Window.process.StandardInput.WriteLine('VERIFY '+$files+' '+$totalFiles+' '+$done+' '+$total);$Window.process.StandardInput.Flush()}
}
function Complete-NativePreloadWindow($Window,[string]$Url) {
 if($Window.process.HasExited){throw 'The native loading window was closed. Game launch stopped.'}
 $uri=New-Object UriBuilder($Url);$uri.Query='client=desktop&shell=native'
 $Window.process.StandardInput.WriteLine('LAUNCH '+$uri.Uri.AbsoluteUri);$Window.process.StandardInput.Flush();$Window.process.StandardInput.Close()
 $Window.handedOff=$true;Register-DesktopClientProcess $Window.process ''
}
function Close-NativePreloadAttempt($Window) {
 if(-not $Window){return}
 if(-not $Window.handedOff){try{if(-not $Window.process.HasExited){$Window.process.Kill();$Window.process.WaitForExit()}}finally{$Window.process.Dispose()}}
 if(Test-Path -LiteralPath $Window.art){Remove-Item -LiteralPath $Window.art -Force}
}
