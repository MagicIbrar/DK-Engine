# Same per-install mutex as the local launcher. Never edit an active/remote world offline.
function Test-ClientOfflineSettingsContext {
 return [bool]($script:offlineSettings -and -not $script:serverReady -and -not $script:remoteWorld -and $script:planValid -and -not $PreviewPath)
}
function Test-ClientEditableSettingsContext {
 return ((Test-ClientSettingsContext) -or (Test-ClientOfflineSettingsContext))
}
function Invoke-ClientPrestartSettings([string]$Operation='read',$Value=$null) {
 if($PreviewPath -or $script:remoteWorld -or $script:serverReady -or -not $script:planValid){throw 'Offline settings require your stopped local installation.'}
 if(-not $clientNode){
  $script:clientNode=Ensure-ClientRuntime -Engine $clientEngine -Log {param($message) Write-ClientLog $message}
  $fresh=Get-InstallPlan;if(-not (Test-SameInstallPlan $script:plan $fresh)){throw 'The installation plan changed. Refresh the launcher before continuing.'};$script:plan=$fresh
 }
 $mutex=Get-ClientPortMutex ('engine-'+$script:plan.engineId);if(-not $mutex){throw 'This installation is already starting. Wait for its launcher.'}
 try{
  $scope=$(if($script:prestartPending -and $script:prestartScope){$script:prestartScope}elseif($script:friendsLaunch){'friends'}else{'local'})
  $arguments=@((Join-Path $clientEngine 'tools\client-prestart-settings.mjs'),$Operation,$scope)
  $inputJson=$(if($null -ne $Value){$Value|ConvertTo-Json -Compress}else{'null'})
  $result=$inputJson | & $clientNode.Source @arguments 2>&1
  if($LASTEXITCODE -ne 0){throw (($result|ForEach-Object{[string]$_}) -join ' ')}
  return (($result -join "`n")|ConvertFrom-Json)
 }finally{$mutex.ReleaseMutex();$mutex.Dispose()}
}
# Measure the host's actual WAN connection before a new game server starts.
# Only the measured upload changes the existing stream budget; download and
# latency are diagnostics, not evidence that the CPU can run more native bots.
function Measure-ClientHostInternet {
 if(-not $clientNode -or -not $clientNode.Source){throw 'The engine runtime is unavailable for the internet test.'}
 $tool=Join-Path $clientEngine 'tools\net-speed-test.mjs'
 if(-not (Test-Path -LiteralPath $tool -PathType Leaf)){throw 'The internet test is missing from this engine.'}
 $lines=& $clientNode.Source $tool '--seconds' '4' 2>&1
 if($LASTEXITCODE -ne 0){throw 'The internet test did not finish. Saved upload settings were kept.'}
 $reply=(($lines|ForEach-Object{[string]$_}) -join "`n")|ConvertFrom-Json
 if($reply.ok -ne $true -or $reply.uploadMbps -isnot [ValueType] -or $reply.downloadMbps -isnot [ValueType] -or $reply.latencyMs -isnot [ValueType] -or [double]$reply.uploadMbps -le 0 -or [double]$reply.uploadMbps -gt 10000 -or [double]$reply.downloadMbps -lt 0 -or [double]$reply.latencyMs -lt 0){throw 'The internet test returned invalid measurements. Saved upload settings were kept.'}
 return $reply
}
function Set-ClientMeasuredUploadBeforeStart {
 $result=Measure-ClientHostInternet
 $upload=[math]::Round([double]$result.uploadMbps,1)
 $updated=Invoke-ClientPrestartSettings 'capacitySet' @{uploadMbps=$upload}
 if([double]$updated.settings.uploadMbps -ne $upload){throw 'Measured upload could not be saved. Saved upload settings were kept.'}
 return $result
}
function Confirm-ClientPrestartSettings([bool]$AccountOnly) {
 if($script:serverReady -or $script:remoteWorld){return $true}
 $script:prestartScope=$(if($script:friendsLaunch){'friends'}else{'local'})
 $state=Invoke-ClientPrestartSettings 'read'
 if($state.running){$script:offlineSettings=$false;$script:prestartPending=$false;return $true}
 $script:offlineSettings=$true
 if($state.reviewed){return $true}
 $script:prestartPending=$true;$script:prestartAccountOnly=$AccountOnly
 Show-ClientSettingsPanel
 Update-ClientSettingsContinue;$script:settingsResult.Text='Choose your world settings before preparation and startup. Then select Launch.'
 return $false
}
function Complete-ClientPrestartSettings {
 if(-not $script:prestartPending -or $script:busy -or -not (Test-ClientOfflineSettingsContext)){return}
 Save-ClientSettings
 if(-not $script:settingsNameSaved){return}
 try{
  [void](Invoke-ClientPrestartSettings 'review');$accountOnly=$script:prestartAccountOnly
  $hostSetup=$script:prestartScope -eq 'friends'
  $script:prestartPending=$false;Update-ClientSettingsContinue;Close-ClientSettingsPanel
  if($hostSetup){Show-FriendsPanel 'host';$script:friendsResult.Text='World settings saved. Complete your host account setup to start.'}
  else{[void](Invoke-ClientLaunch $accountOnly)}
 }catch{$script:settingsResult.Text=$_.Exception.Message}
}
