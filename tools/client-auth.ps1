# Account and invite passwords stay in native fields/HTTPS or private-LAN POST bodies.
function Read-SavedAccountIds([string]$Url) {
 $file=Join-Path $clientEngine 'server\saved-logins.json';Assert-ClientPathUnlinked $file
 if(-not (Test-Path -LiteralPath $file)){return @()}
 if((Get-Item -LiteralPath $file).Length -gt 65536){throw 'Saved login list is too large.'}
 $origin=([Uri]$Url).GetLeftPart([UriPartial]::Authority).ToLowerInvariant()
 return @(Get-Content -LiteralPath $file -Raw|ConvertFrom-Json|Where-Object {$_.server -ceq $origin -and $_.id -match '^[a-z0-9_-]{3,32}$' -and $_.id -ne 'admin'}|ForEach-Object {$_.id}|Select-Object -Unique)
}
function Get-SavedLoginOrigin([string]$Url){return ([Uri]$Url).GetLeftPart([UriPartial]::Authority).ToLowerInvariant()}
# Saved-login tokens are SERVER-ISSUED (api/auth/remember) and stored only as Windows DPAPI blobs (current user), bound to that
# server origin through the DPAPI entropy. No password is ever written. A token from server A is rejected by server B.
function Protect-SavedLoginToken([string]$Origin,[string]$Token) {
 Add-Type -AssemblyName System.Security
 $entropy=[Text.Encoding]::UTF8.GetBytes('dekaron-saved-login:'+$Origin)
 return [Convert]::ToBase64String([Security.Cryptography.ProtectedData]::Protect([Text.Encoding]::UTF8.GetBytes($Token),$entropy,[Security.Cryptography.DataProtectionScope]::CurrentUser))
}
function Unprotect-SavedLoginToken([string]$Origin,[string]$Blob) {
 try{Add-Type -AssemblyName System.Security;$entropy=[Text.Encoding]::UTF8.GetBytes('dekaron-saved-login:'+$Origin)
  $token=[Text.Encoding]::UTF8.GetString([Security.Cryptography.ProtectedData]::Unprotect([Convert]::FromBase64String($Blob),$entropy,[Security.Cryptography.DataProtectionScope]::CurrentUser))
  if($token -match '^[a-f0-9]{64}$'){return $token}}catch{}
 return ''
}
function Get-SavedAccountToken([string]$Url,[string]$Id) {
 $file=Join-Path $clientEngine 'server\saved-logins.json';Assert-ClientPathUnlinked $file
 if(-not (Test-Path -LiteralPath $file) -or (Get-Item -LiteralPath $file).Length -gt 65536){return ''}
 $origin=Get-SavedLoginOrigin $Url;$id=$Id.Trim().ToLowerInvariant()
 foreach($row in @(Get-Content -LiteralPath $file -Raw|ConvertFrom-Json)){if($row.server -ceq $origin -and $row.id -ceq $id -and $row.token -is [string] -and $row.token -match '^[A-Za-z0-9+/=]{20,2048}$'){return (Unprotect-SavedLoginToken $origin $row.token)}}
 return ''
}
function Save-AccountId([string]$Url,[string]$Id,[bool]$Remove=$false,[string]$Token='',[bool]$KeepToken=$true) {
 $id=$Id.Trim().ToLowerInvariant();if($id -notmatch '^[a-z0-9_-]{3,32}$' -or $id -eq 'admin'){return}
 $folder=Join-Path $clientEngine 'server';Assert-ClientPathUnlinked $folder
 $file=Join-Path $folder 'saved-logins.json';Assert-ClientPathUnlinked $file
 $origin=Get-SavedLoginOrigin $Url;$rows=@();$kept=''
 if(Test-Path -LiteralPath $file){if((Get-Item -LiteralPath $file).Length -gt 65536){throw 'Saved login list is too large.'};$rows=@(Get-Content -LiteralPath $file -Raw|ConvertFrom-Json)}
 $safe=@();foreach($row in $rows){if($row.id -notmatch '^[a-z0-9_-]{3,32}$' -or $row.id -eq 'admin'){continue};try{$uri=[Uri]$row.server;if($uri.Scheme -notin @('http','https') -or $uri.UserInfo -or $uri.Query -or $uri.Fragment){continue}
  $blob=$(if($row.token -is [string] -and $row.token -match '^[A-Za-z0-9+/=]{20,2048}$'){[string]$row.token}else{''})
  if($row.server -ceq $origin -and $row.id -ceq $id){$kept=$blob;continue}
  $entry=@{server=$uri.GetLeftPart([UriPartial]::Authority).ToLowerInvariant();id=[string]$row.id};if($blob){$entry.token=$blob};$safe+=$entry}catch{}}
 if(-not $Remove){$entry=@{server=$origin;id=$id};if($Token){$entry.token=Protect-SavedLoginToken $origin $Token}elseif($KeepToken -and $kept){$entry.token=$kept};$safe+=$entry};$safe=@($safe|Select-Object -Last 100)
 [IO.File]::WriteAllText($file,(ConvertTo-Json -InputObject $safe -Compress))
}function Refresh-SavedAccountIds {
 $script:savedLogin.Items.Clear();foreach($id in @(Read-SavedAccountIds $script:authUrl)){[void]$script:savedLogin.Items.Add($id)}
}
function Test-NativeAuthAttempt($Attempt) {
 if($script:closeRequested -or $form.IsDisposed -or $form.Disposing){return $false}
 if($null -eq $Attempt){return $true}
 return [object]::ReferenceEquals($script:authAttempt,$Attempt) -and $script:authGeneration -eq $Attempt.generation -and $script:authPanel.Visible -and $script:authUrl -ceq $Attempt.url -and $script:authTarget -ceq $Attempt.target -and $script:authBrowser -eq $Attempt.browser -and $script:authSignupMode -eq $Attempt.signup -and $script:authFriends -eq $Attempt.friends -and ($script:ownerAuto.Visible -and $script:ownerAuto.Enabled -and $script:ownerAuto.Checked) -eq $Attempt.owner
}
function Assert-NativeAuthAttempt($Attempt) {
 if(-not (Test-NativeAuthAttempt $Attempt)){throw [OperationCanceledException]::new('Sign-in canceled.')}
}
function New-NativeAuthWorker {return [Management.Automation.PowerShell]::Create()}
function Wait-NativeAuthUi { [Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(20) }
function Invoke-PumpedNativeAuthTransport($Options,[bool]$Rest=$false,[bool]$PanelStatus=$false) {
 $attempt=$(if($PanelStatus){$null}else{$script:authAttempt});$generation=$script:authGeneration;Assert-NativeAuthAttempt $attempt
 $worker=$null;$pending=$null;$stop=$null;$canceled=$false
 try{
  $worker=New-NativeAuthWorker
  [void]$worker.AddScript(@'
param($Options,[bool]$Rest)
try{
 if($Rest){$value=Invoke-RestMethod @Options}else{$value=Invoke-WebRequest @Options}
 [pscustomobject]@{ok=$true;value=$value}
}catch{[pscustomobject]@{ok=$false;error=$_}}
'@).AddArgument($Options).AddArgument($Rest)
  $pending=$worker.BeginInvoke()
  while(-not $pending.IsCompleted){
   Wait-NativeAuthUi
   if($script:authGeneration -ne $generation -or -not (Test-NativeAuthAttempt $attempt)){$canceled=$true;if($null -eq $stop){$stop=$worker.BeginStop($null,$null)}}
  }
  if($canceled){try{[void]$worker.EndInvoke($pending)}catch{};throw [OperationCanceledException]::new('Sign-in canceled.')}
  if($script:authGeneration -ne $generation){throw [OperationCanceledException]::new('Sign-in canceled.')}
  Assert-NativeAuthAttempt $attempt
  $rows=$worker.EndInvoke($pending)
  if($rows.Count -ne 1){throw 'The authentication transport did not return one response.'}
  if(-not $rows[0].ok){throw $rows[0].error}
  return $rows[0].value
 }finally{if($worker){if($stop){try{$worker.EndStop($stop)}catch{}};$worker.Dispose()}}
}
function Invoke-NativeAuthRequest([string]$Url,[string]$Route,$Session,$Body=$null) {
 $base=[Uri]$Url
 if($base.Scheme -notin @('http','https') -or $base.UserInfo -or $base.Query -or $base.Fragment -or $base.AbsolutePath -ne '/' -or $Route -notmatch '^api/[a-z/-]+$'){throw 'Invalid selected server endpoint.'}
 $options=@{Uri=(Get-ClientApiUrl ($Url+$Route));WebSession=$Session;MaximumRedirection=0;TimeoutSec=15;ErrorAction='Stop';Headers=@{Host=$base.Authority}}
 if($null -ne $Body){$options.Method='POST';$options.ContentType='application/json; charset=utf-8';$options.Body=[Text.Encoding]::UTF8.GetBytes(($Body|ConvertTo-Json -Compress))}
 try{
  $options.UseBasicParsing=$true
  $response=Invoke-PumpedNativeAuthTransport $options
  if([int]$response.StatusCode -lt 200 -or [int]$response.StatusCode -ge 300){throw 'The server did not respond directly.'}
  return ($response.Content|ConvertFrom-Json)
 }catch{
  if($_.Exception -is [OperationCanceledException]){throw}
  $message='The account request failed. Check the address and try again; redirects are not accepted.'
  $cause=$_.Exception;while($cause.InnerException){$cause=$cause.InnerException}
  if($cause -is [Net.WebException]){if($cause.Status -eq [Net.WebExceptionStatus]::Timeout){$message='The account request timed out. Please try again.'}elseif($cause.Status -in @([Net.WebExceptionStatus]::ConnectFailure,[Net.WebExceptionStatus]::NameResolutionFailure)){$message='The account server could not be reached. Check the address and try again.'}}
  if($_.Exception.Response){try{$reader=New-Object IO.StreamReader($_.Exception.Response.GetResponseStream());$detail=$reader.ReadToEnd()|ConvertFrom-Json;$reader.Dispose();if($detail.error){$message=[string]$detail.error}}catch{}}
  if($_.ErrorDetails.Message){try{$detail=$_.ErrorDetails.Message|ConvertFrom-Json;if($detail.error){$message=[string]$detail.error}}catch{}}
  throw $message
 }
}
function New-NativeAuthSession {return New-Object Microsoft.PowerShell.Commands.WebRequestSession}
function Test-NativeAuthServer([string]$Url,$Session,[bool]$Friends) {
 $status=Invoke-NativeAuthRequest $Url $(if($Friends){'api/friends/status'}else{'api/client/status'}) $Session
 if($status.app -cne 'dekaron-engine'){throw 'The selected address is not a Dekaron engine server.'}
 if($Friends -and (($status.protocol -isnot [int] -and $status.protocol -isnot [long]) -or $status.protocol -ne 1 -or ($status.version -isnot [int] -and $status.version -isnot [long]) -or $status.version -ne 1 -or $status.requiresInvite -isnot [bool] -or -not (($status.hostMode -ceq 'friends' -and $status.requiresInvite) -or ($status.hostMode -ceq 'open' -and -not $status.requiresInvite)))){throw 'This friends server is incompatible or is not invite protected.'}
 return $status
}
function Authenticate-NativeAccount([string]$Url,$Session,[string]$Id,[string]$Password,[string]$InvitePassword,[bool]$Friends=$false,[string]$SavedToken='',[bool]$Remember=$false) {
 $verified=Test-NativeAuthServer $Url $Session $Friends
 if($Friends -and $verified.requiresInvite){[void](Invoke-NativeAuthRequest $Url 'api/friends/join' $Session @{password=$InvitePassword})}
 $id=$Id.Trim().ToLowerInvariant()
 if($SavedToken){try{$account=Invoke-NativeAuthRequest $Url 'api/auth/remember-login' $Session @{id=$id;token=$SavedToken}}catch{if($_.Exception -is [OperationCanceledException]){throw};throw [InvalidOperationException]::new('SAVED_LOGIN_REJECTED: '+$_.Exception.Message)}}
 else{$account=Invoke-NativeAuthRequest $Url 'api/auth/login' $Session @{id=$id;password=$Password}}
 if($account.id -cne $id){throw 'The account response did not match your login.'}
 # Save account: ask THIS server for a fresh remember token while the session is live (a saved-token login always rotates it).
 $fresh='';if($Remember -or $SavedToken){try{$body=@{};if($SavedToken){$body.replace=$SavedToken};$issued=Invoke-NativeAuthRequest $Url 'api/auth/remember' $Session $body;if($issued.token -match '^[a-f0-9]{64}$'){$fresh=[string]$issued.token}}catch{if($_.Exception -is [OperationCanceledException]){throw};$fresh=''}}
 $handoff=Invoke-NativeAuthRequest $Url 'api/auth/launch-ticket' $Session @{}
 if($handoff.ticket -notmatch '^[a-f0-9]{64}$' -or $handoff.expiresIn -notin @(45,180)){throw 'The game handoff could not be verified.'}
 return [pscustomobject]@{url=$Url+'launch#ticket='+$handoff.ticket;id=$id;rememberToken=$fresh}
}
function Authenticate-OwnerLauncher([string]$Url) {
 if($script:remoteWorld -or $script:authFriends -or -not $script:serverReady -or $Url -cne $script:serverUrl){throw 'Local admin is available only in your local world.'}
 $control=Get-LauncherControl $clientEngine $script:runningPlan $Url
 $options=@{Uri=((Get-ClientApiUrl $Url)+'api/launcher/owner-launch');Method='Post';Headers=@{'x-dekaron-launcher-token'=$control.token;Host=([Uri]$Url).Authority};ContentType='application/json';Body='{}';MaximumRedirection=0;TimeoutSec=60}
 $handoff=Invoke-PumpedNativeAuthTransport $options $true
 if($handoff.ticket -notmatch '^[a-f0-9]{64}$' -or $handoff.expiresIn -notin @(45,180)){throw 'The owner handoff could not be verified.'}
 return [pscustomobject]@{url=$Url+'launch#ticket='+$handoff.ticket;id='admin'}
}
function Get-OwnerPreparationTime {return [DateTime]::UtcNow}
function Wait-OwnerLauncherPreparation([string]$Url,$Attempt,[int]$StallSeconds=180,[int]$OverallSeconds=1200) {
 if($StallSeconds -lt 1 -or $OverallSeconds -lt $StallSeconds -or $OverallSeconds -gt 1200){throw 'Invalid owner preparation wait policy.'}
 if(-not $Attempt.owner -or $script:remoteWorld -or $script:authFriends -or -not $script:serverReady -or $Url -cne $script:serverUrl){throw 'Local owner preparation is available only in your local world.'}
 Assert-NativeAuthAttempt $Attempt
 # Discard this ticket; the normal sign-in obtains a fresh ticket after asset warming.
 $null=Authenticate-OwnerLauncher $Url
 $control=Get-LauncherControl $clientEngine $script:runningPlan $Url
 $deadline=(Get-OwnerPreparationTime).AddSeconds($OverallSeconds);$stallDeadline=(Get-OwnerPreparationTime).AddSeconds($StallSeconds);$mostEnrolled=0;$mostActions=0;$hadCrest=$false;$hadGlory=$false
 while($true){
  Assert-NativeAuthAttempt $Attempt
  if((Get-OwnerPreparationTime) -ge $deadline -or (Get-OwnerPreparationTime) -ge $stallDeadline){throw 'Owner guild preparation timed out. Check host setup status, then retry owner sign-in.'}
  $script:authResult.Text='Preparing owner characters and guild before opening the game...'
  $options=@{Uri=((Get-ClientApiUrl $Url)+'api/launcher/status');Method='Get';Headers=@{'x-dekaron-launcher-token'=$control.token;Host=([Uri]$Url).Authority};MaximumRedirection=0;TimeoutSec=10}
  $status=Invoke-PumpedNativeAuthTransport $options $true
  Assert-NativeAuthAttempt $Attempt
  if($status.app -cne 'dekaron-engine' -or $status.stopping -or [int]$status.pid -ne [int]$control.pid){throw 'The local host changed during owner preparation. Return to Client and retry.'}
  $report=$status.adminGuild
  $enrolled=0;$actions=0;$eligible=0
  if($report.enrolled -is [int] -or $report.enrolled -is [long]){$enrolled=[Math]::Max(0,[long]$report.enrolled)}
  if($report.actions -is [int] -or $report.actions -is [long]){$actions=[Math]::Max(0,[long]$report.actions)}
  if($report.eligible -is [int] -or $report.eligible -is [long]){$eligible=[Math]::Max(0,[long]$report.eligible)}
  if($enrolled -gt $mostEnrolled -or $actions -gt $mostActions -or ($report.crestComplete -eq $true -and -not $hadCrest) -or ($report.gloryComplete -eq $true -and -not $hadGlory)){$stallDeadline=(Get-OwnerPreparationTime).AddSeconds($StallSeconds)}
  $mostEnrolled=[Math]::Max($mostEnrolled,$enrolled);$mostActions=[Math]::Max($mostActions,$actions);$hadCrest=$hadCrest -or $report.crestComplete -eq $true;$hadGlory=$hadGlory -or $report.gloryComplete -eq $true
  if($eligible -gt 0){$script:authResult.Text='Preparing owner guild: '+$enrolled+' / '+$eligible+' characters enrolled. The game opens when setup finishes.'}
  if($report.complete -eq $true -and $report.phase -ceq 'complete'){return}
  $pending=$report.phase -cin @('queued','running') -or ($report.phase -ceq 'deferred' -and $report.reason -cin @('world-not-ready','human-admission-or-host-stopping','human-admission-or-setup-budget'))
  if(-not $pending){throw 'Owner guild preparation could not finish. Check private host setup status and other owner sessions, then retry owner sign-in.'}
  $next=(Get-OwnerPreparationTime).AddMilliseconds(250)
  while((Get-OwnerPreparationTime) -lt $next){Assert-NativeAuthAttempt $Attempt;Wait-NativeAuthUi}
 }
}
function Register-NativeAccount([string]$Url,$Session,[string]$Id,[string]$Password,[string]$Confirm,[string]$InvitePassword,[bool]$Friends=$false) {
 if($Password -cne $Confirm){throw 'Passwords do not match.'}
 $verified=Test-NativeAuthServer $Url $Session $Friends
 if($Friends -and $verified.requiresInvite){[void](Invoke-NativeAuthRequest $Url 'api/friends/join' $Session @{password=$InvitePassword})}
 $id=$Id.Trim().ToLowerInvariant();$account=Invoke-NativeAuthRequest $Url 'api/auth/signup' $Session @{id=$id;password=$Password}
 if($account.id -cne $id){throw 'The account response did not match your registration.'}
 [void](Invoke-NativeAuthRequest $Url 'api/auth/logout' $Session @{})
 return $account
}
# $Target ('native' | 'desktop' | 'browser'): the version the dashboard button asked for = the panel's Enter button.
function Show-NativeAuthPanel([string]$Url,[bool]$Friends=$false,$Metadata=$null,[bool]$Signup=$false,[bool]$Browser=$false,[string]$Target='',[bool]$Borderless=$false) {
 $script:authNativeBorderless=($Target -eq 'native' -and $Borderless);$script:requestedNativeBorderless=$false
 $script:authGeneration=[long]$script:authGeneration+1
 if(Get-Command Stop-ClientReadinessProbe -ErrorAction SilentlyContinue){Stop-ClientReadinessProbe}
 $script:authUrl=ConvertTo-FriendsUrl $Url;$script:authFriends=$Friends;$script:authSignupMode=$Signup
 $script:authBrowser=$Browser;$script:authMetadata=$Metadata
 $script:authSession=New-NativeAuthSession
 if($script:publicPanel){$script:publicPanel.Visible=$false};$script:authPanel.Visible=$true;$script:friendsPanel.Visible=$false;$script:ratesPanel.Visible=$false;$signupPanel.Visible=$false
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$progress,$statusLine,$itemBuilderButton,$mapBuilderButton)){$control.Visible=$false}
 if($script:browserLaunch){$script:browserLaunch.Visible=$false};if($script:localWorld){$script:localWorld.Visible=$false}   # the top-row buttons stay
 $script:authTitle.Text=$(if($Signup){'Create your account'}else{'Sign in to your world'})
 $name='Dekaron Online';if($Metadata.name){$name=[string]$Metadata.name}elseif($script:localServerName -and $script:localServerNameUrl -ceq $script:authUrl){$name=$script:localServerName}
 $script:authServer.Text=$name+"`r`n"+$script:authUrl+"`r`nAccounts belong only to this server."
 if($Metadata.rates){$script:authServer.Text+="`r`nEXP "+$Metadata.rates.exp+'x / DIL '+$Metadata.rates.dil+'x / Drop '+$Metadata.rates.drop+'x'}
 $inviteRequired=$Friends -and $Metadata.requiresInvite -ne $false;$script:authInvite.Visible=$inviteRequired;$script:authInviteLabel.Visible=$inviteRequired;$script:authConfirm.Visible=$Signup;$script:authConfirmLabel.Visible=$Signup
 # Three ways to play, each named for what it opens; every one signs in first and opens the game already signed in.
 $script:authSubmit.Text=$(if($Signup){'Create account'}else{'Desktop App'});$script:authSubmit.Left=$(if($Signup){18}else{141});$script:authSubmit.Width=$(if($Signup){365}else{116});$script:authBrowserSubmit.Visible=-not $Signup;$script:authNativeSubmit.Visible=-not $Signup;$script:authResult.Text=''
 foreach($field in @($script:authId,$script:authPassword,$script:authConfirm,$script:authInvite)){$field.Clear()}
 $script:rememberAccount.Visible=-not $Signup;$script:savedLogin.Visible=-not $Signup;$script:forgetAccount.Visible=-not $Signup
 $script:rememberAccount.Checked=$false
 try{Refresh-SavedAccountIds}catch{$script:authResult.Text='Saved account list unavailable; enter your ID normally.'}
 $script:authPanel.BringToFront()
 $script:authTarget=$(if($Target -in @('native','desktop','browser')){$Target}elseif($Browser){'browser'}else{'desktop'})
 $form.AcceptButton=$(if($Signup){$script:authSubmit}elseif($script:authTarget -eq 'browser'){$script:authBrowserSubmit}elseif($script:authTarget -eq 'native' -and $script:authNativeSubmit){$script:authNativeSubmit}else{$script:authSubmit})
 $script:ownerAuto.Visible=$false;$script:ownerAuto.Enabled=$false;$script:ownerAuto.Checked=$false
 if(-not $Friends -and -not $Signup -and -not $script:remoteWorld -and $script:serverReady -and $script:authUrl -ceq $script:serverUrl){try{$control=Get-LauncherControl $clientEngine $script:runningPlan $script:authUrl;$ownerStatus=Invoke-PumpedNativeAuthTransport @{Uri=((Get-ClientApiUrl $script:authUrl)+'api/launcher/status');Headers=@{'x-dekaron-launcher-token'=$control.token;Host=([Uri]$script:authUrl).Authority};MaximumRedirection=0;TimeoutSec=3} $true $true;$script:ownerAuto.Visible=$true;$script:ownerAuto.Enabled=$ownerStatus.ownerAvailable -eq $true}catch{}}
 Update-OwnerAuthFields
}
function Update-OwnerAuthFields {
 $owner=$script:ownerAuto.Visible -and $script:ownerAuto.Enabled -and $script:ownerAuto.Checked
 $script:authId.Enabled=-not $owner;$script:authPassword.Enabled=-not $owner
 if($owner){$script:authId.Clear();$script:authPassword.Clear()}
}
function Close-NativeAuthPanel {
 $script:authGeneration=[long]$script:authGeneration+1
 foreach($field in @($script:authId,$script:authPassword,$script:authConfirm,$script:authInvite)){$field.Clear()};$script:authSession=$null;$script:authPanel.Visible=$false
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$statusLine)){$control.Visible=$true}
 $progress.Visible=-not $script:cachedReady -and -not $script:dashboard -and -not $script:serverReady;Set-LauncherBuilderVisibility ([bool]$script:builderReady);$script:hostButton.Visible=$true;$script:connectButton.Visible=$true
 if($script:hostingOptions){$script:hostingOptions.Visible=$true};if($script:browserLaunch){$script:browserLaunch.Visible=$script:dashboard};if($script:localWorld){$script:localWorld.Visible=$script:remoteWorld};$form.AcceptButton=$primary
}
function Submit-NativeAuth {
 $nativePreload=$null
 if($script:busy){return}
 $attempt=[pscustomobject]@{generation=$script:authGeneration;url=$script:authUrl;target=$script:authTarget;borderless=($script:authTarget -eq 'native' -and [bool]$script:authNativeBorderless);browser=$script:authBrowser;signup=$script:authSignupMode;friends=$script:authFriends;owner=($script:ownerAuto.Visible -and $script:ownerAuto.Enabled -and $script:ownerAuto.Checked)};$script:authAttempt=$attempt
 if($script:busy){return};$script:busy=$true;$script:authSubmit.Enabled=$false;$script:authBrowserSubmit.Enabled=$false;if($script:authNativeSubmit){$script:authNativeSubmit.Enabled=$false};$script:authSignIn.Enabled=$false;$script:authSignUp.Enabled=$false;$script:authBack.Enabled=$true;$script:authResult.Text=$(if($script:authSignupMode){'Creating account...'}else{'Signing in...'})
 try{
  [Windows.Forms.Application]::DoEvents()
  Assert-NativeAuthAttempt $attempt
  $script:authSession=New-NativeAuthSession
  if($script:authSignupMode){[void](Register-NativeAccount $script:authUrl $script:authSession $script:authId.Text $script:authPassword.Text $script:authConfirm.Text $script:authInvite.Text $script:authFriends);Assert-NativeAuthAttempt $attempt;Show-NativeAuthPanel $script:authUrl $script:authFriends $script:authMetadata $false $script:authBrowser;foreach($field in @($script:authId,$script:authPassword,$script:authConfirm,$script:authInvite)){$field.Clear()};$script:authResult.Text='Account created! Sign in with your new account.'}
  else{if($attempt.owner){Wait-OwnerLauncherPreparation $script:authUrl $attempt};if($script:dedicatedMode -and -not $script:remoteWorld -and $script:authTarget -eq 'native'){$preloadAccount=if($attempt.owner){'admin'}else{$script:authId.Text};$nativePreload=Start-NativePreloadWindow $preloadAccount -Borderless $attempt.borderless -StillCurrent {Test-NativeAuthAttempt $attempt}};if(Get-Command Invoke-DedicatedAssetWarm -ErrorAction SilentlyContinue){Invoke-DedicatedAssetWarm -StillCurrent {(Test-NativeAuthAttempt $attempt) -and (-not $nativePreload -or -not $nativePreload.process.HasExited)} -Report {param($message) $script:authResult.Text=$(if($nativePreload){'Loading installed assets in the game window...'}else{$message})} -OnProgress {param($state) if($nativePreload){Send-NativePreloadProgress $nativePreload $state}};Assert-NativeAuthAttempt $attempt};if($script:ownerAuto.Visible -and $script:ownerAuto.Enabled -and $script:ownerAuto.Checked){$result=Authenticate-OwnerLauncher $script:authUrl}else{$savedToken='';if(-not $script:authPassword.Text){$savedToken=Get-SavedAccountToken $script:authUrl $script:authId.Text};$result=Authenticate-NativeAccount $script:authUrl $script:authSession $script:authId.Text $script:authPassword.Text $script:authInvite.Text $script:authFriends $savedToken ([bool]$script:rememberAccount.Checked)};Assert-NativeAuthAttempt $attempt;if($script:authBrowser){Start-Process -FilePath $result.url -ErrorAction Stop}elseif($script:authTarget -eq 'native'){if($nativePreload){Complete-NativePreloadWindow $nativePreload $result.url}else{Open-NativeGame $clientEngine $result.url $result.id -Borderless $attempt.borderless}}else{Open-IsolatedGame $clientEngine $result.url};if($result.id -ne 'admin' -and ($script:rememberAccount.Checked -or $savedToken)){try{if($result.rememberToken){Save-AccountId $script:authUrl $result.id $false $result.rememberToken}elseif($savedToken){Save-AccountId $script:authUrl $result.id $false '' $false}else{Save-AccountId $script:authUrl $result.id}}catch{Write-ClientLog 'Could not save account.'}};Close-NativeAuthPanel;$statusLine.Text=$(if($result.id -eq 'admin'){'Game window opened as the local admin.'}else{'Game window opened for account '+$result.id+' (shown in its title bar).'})}
 }catch{if(-not (Test-NativeAuthAttempt $attempt)){return};$message=$_.Exception.Message;if($message -like 'SAVED_LOGIN_REJECTED*'){try{Save-AccountId $script:authUrl $script:authId.Text $false '' $false}catch{};$message='Your saved login expired or was revoked on this server. Enter your password.'};if($message -match 'reserved for the installation owner'){$message='For local admin, select Auto-sign in as local admin, then DX11 Client, Desktop App or Web Browser.'};$script:authResult.Text=$message;$script:authResult.Refresh()}
 finally{if($nativePreload){Close-NativePreloadAttempt $nativePreload};if($script:authGeneration -eq $attempt.generation){foreach($field in @($script:authPassword,$script:authConfirm,$script:authInvite)){$field.Clear()};$script:authSession=$null;$script:authTarget='desktop';$script:requestedNativeBorderless=$false;$script:authNativeBorderless=$false};if([object]::ReferenceEquals($script:authAttempt,$attempt)){$script:authAttempt=$null};$script:busy=$false;$script:authSubmit.Enabled=$true;$script:authBrowserSubmit.Enabled=$true;if($script:authNativeSubmit){$script:authNativeSubmit.Enabled=$true};$script:authSignIn.Enabled=$true;$script:authSignUp.Enabled=$true;$script:authBack.Enabled=$true}
}
function Initialize-NativeAuthControls {
 $script:authPanel=New-Object GalaxyPanel;$script:authPanel.Location=New-Object Drawing.Point(300,145);$script:authPanel.Size=New-Object Drawing.Size(400,486);$script:authPanel.BackColor=[Drawing.Color]::FromArgb(18,22,30);$script:authPanel.Visible=$false;$form.Controls.Add($script:authPanel)
 $script:authTitle=New-Object Windows.Forms.Label;$script:authTitle.Location=New-Object Drawing.Point(18,14);$script:authTitle.Size=New-Object Drawing.Size(365,28);$script:authTitle.Font=New-Object Drawing.Font('Segoe UI',14,[Drawing.FontStyle]::Bold);$script:authTitle.ForeColor=$gold;$script:authPanel.Controls.Add($script:authTitle)
 $script:authServer=New-Object Windows.Forms.Label;$script:authServer.Location=New-Object Drawing.Point(18,48);$script:authServer.Size=New-Object Drawing.Size(365,80);$script:authServer.ForeColor=$muted;$script:authPanel.Controls.Add($script:authServer)
 $script:authSignIn=New-Object RoundedLauncherButton;$script:authSignIn.Text='Sign in';$script:authSignIn.Location=New-Object Drawing.Point(18,129);$script:authSignIn.Size=New-Object Drawing.Size(172,30)
 $script:authSignUp=New-Object RoundedLauncherButton;$script:authSignUp.Text='Sign up';$script:authSignUp.Location=New-Object Drawing.Point(210,129);$script:authSignUp.Size=New-Object Drawing.Size(172,30)
 foreach($button in @($script:authSignIn,$script:authSignUp)){$button.FlatStyle='Flat';$button.BackColor=$ink;$button.ForeColor=$gold;$script:authPanel.Controls.Add($button)}
 $labels=@('Invite password','Account ID','Account password','Repeat account password');$fields=@()
 for($i=0;$i -lt 4;$i++){$label=New-Object Windows.Forms.Label;$label.Text=$labels[$i];$label.Location=New-Object Drawing.Point(18,(167+$i*45));$label.Size=New-Object Drawing.Size(365,18);$label.ForeColor=$muted;$field=New-Object GalaxyTextBox;$field.Location=New-Object Drawing.Point(18,(185+$i*45));$field.Size=New-Object Drawing.Size(365,24);$field.UseSystemPasswordChar=$i -ne 1;$field.BackColor=[Drawing.Color]::FromArgb(30,35,44);$field.ForeColor=$gold;$script:authPanel.Controls.Add($label);$script:authPanel.Controls.Add($field);$fields+=$field;if($i -eq 0){$script:authInviteLabel=$label};if($i -eq 3){$script:authConfirmLabel=$label}}
 $script:authInvite=$fields[0];$script:authId=$fields[1];$script:authPassword=$fields[2];$script:authConfirm=$fields[3]
 $script:ownerAuto=New-Object Windows.Forms.CheckBox;$script:ownerAuto.Text='Auto-sign in as local admin';$script:ownerAuto.Location=New-Object Drawing.Point(18,185);$script:ownerAuto.Size=New-Object Drawing.Size(365,24);$script:ownerAuto.ForeColor=$gold;$script:ownerAuto.Visible=$false;$script:authPanel.Controls.Add($script:ownerAuto);$script:ownerAuto.Add_CheckedChanged({Update-OwnerAuthFields})
 $script:rememberAccount=New-Object Windows.Forms.CheckBox;$script:rememberAccount.Text='Save account on this server (no password stored)';$script:rememberAccount.Location=New-Object Drawing.Point(18,302);$script:rememberAccount.Size=New-Object Drawing.Size(365,22);$script:rememberAccount.ForeColor=$gold;$script:authPanel.Controls.Add($script:rememberAccount)
 $script:savedLogin=New-Object GalaxyComboBox;$script:savedLogin.DropDownStyle='DropDownList';$script:savedLogin.Location=New-Object Drawing.Point(18,329);$script:savedLogin.Size=New-Object Drawing.Size(265,24);$script:savedLogin.BackColor=$ink;$script:savedLogin.ForeColor=$gold;$script:authPanel.Controls.Add($script:savedLogin)
 $script:savedLogin.Add_SelectedIndexChanged({if($script:savedLogin.SelectedItem){$script:ownerAuto.Checked=$false;$script:authId.Text=[string]$script:savedLogin.SelectedItem;$script:authPassword.Clear();if(Get-SavedAccountToken $script:authUrl ([string]$script:savedLogin.SelectedItem)){$script:authResult.Text='Saved login found. Leave the password empty and press Launch client.'}}})
 $script:forgetAccount=New-Object RoundedLauncherButton;$script:forgetAccount.Text='Forget';$script:forgetAccount.Location=New-Object Drawing.Point(291,329);$script:forgetAccount.Size=New-Object Drawing.Size(92,24);$script:authPanel.Controls.Add($script:forgetAccount)
 $script:forgetAccount.Add_Click({try{if($script:savedLogin.SelectedItem){try{$old=Get-SavedAccountToken $script:authUrl ([string]$script:savedLogin.SelectedItem);if($old){[void](Invoke-NativeAuthRequest $script:authUrl 'api/auth/remember-revoke' (New-NativeAuthSession) @{id=([string]$script:savedLogin.SelectedItem);token=$old})}}catch{};Save-AccountId $script:authUrl ([string]$script:savedLogin.SelectedItem) $true;Refresh-SavedAccountIds}}catch{$script:authResult.Text='Could not update saved account list.'}})
 $script:authId.MaxLength=32;foreach($field in @($script:authInvite,$script:authPassword,$script:authConfirm)){$field.MaxLength=128}
 $script:authNativeSubmit=New-Object RoundedLauncherButton;$script:authNativeSubmit.Text='DX11 Client';$script:authNativeSubmit.Location=New-Object Drawing.Point(18,366);$script:authNativeSubmit.Size=New-Object Drawing.Size(116,36);$script:authNativeSubmit.UseMnemonic=$false;$script:authNativeSubmit.BackColor=$gold;$script:authNativeSubmit.ForeColor=$ink;$script:authNativeSubmit.FlatStyle='Flat';$script:authPanel.Controls.Add($script:authNativeSubmit);$script:authNativeSubmit.Add_Click({if(-not $script:busy -and -not $script:authSignupMode){$script:authBrowser=$false;$script:authTarget='native';Submit-NativeAuth}})
 $script:authSubmit=New-Object RoundedLauncherButton;$script:authSubmit.Location=New-Object Drawing.Point(141,366);$script:authSubmit.Size=New-Object Drawing.Size(116,36);$script:authSubmit.UseMnemonic=$false;$script:authSubmit.BackColor=$gold;$script:authSubmit.ForeColor=$ink;$script:authSubmit.FlatStyle='Flat';$script:authPanel.Controls.Add($script:authSubmit);$script:authSubmit.Add_Click({if(-not $script:busy){if(-not $script:authSignupMode){$script:authBrowser=$false;$script:authTarget='desktop'};Submit-NativeAuth}})
 $script:authBrowserSubmit=New-Object RoundedLauncherButton;$script:authBrowserSubmit.Text='Web Browser';$script:authBrowserSubmit.Location=New-Object Drawing.Point(264,366);$script:authBrowserSubmit.Size=New-Object Drawing.Size(119,36);$script:authBrowserSubmit.UseMnemonic=$false;$script:authBrowserSubmit.BackColor=$gold;$script:authBrowserSubmit.ForeColor=$ink;$script:authBrowserSubmit.FlatStyle='Flat';$script:authPanel.Controls.Add($script:authBrowserSubmit);$script:authBrowserSubmit.Add_Click({if(-not $script:busy -and -not $script:authSignupMode){$script:authBrowser=$true;$script:authTarget='browser';Submit-NativeAuth}})
 $authTips=New-Object Windows.Forms.ToolTip
 $authTips.SetToolTip($script:authNativeSubmit,'Dekaron.exe: the native game window (Direct3D 11). Starts with the loading screen and the login hall; click the server to enter.')
 $authTips.SetToolTip($script:authSubmit,'Desktop App: the game in its own app window (Edge / Chrome app mode).')
 $authTips.SetToolTip($script:authBrowserSubmit,'Web Browser: the game in a tab of your default browser.')
 $script:authResult=New-Object Windows.Forms.Label;$script:authResult.Location=New-Object Drawing.Point(18,413);$script:authResult.Size=New-Object Drawing.Size(285,66);$script:authResult.BackColor=$script:authPanel.BackColor;$script:authResult.ForeColor=$gold;$script:authResult.UseMnemonic=$false;$script:authPanel.Controls.Add($script:authResult)
 $script:authBack=New-Object RoundedLauncherButton;$script:authBack.Text='Back';$script:authBack.Location=New-Object Drawing.Point(313,413);$script:authBack.Size=New-Object Drawing.Size(70,28);$script:authPanel.Controls.Add($script:authBack);$script:authBack.Add_Click({if(-not $script:busy -or $script:authAttempt){Close-NativeAuthPanel}})
 $script:authSignIn.Add_Click({if(-not $script:busy){Show-NativeAuthPanel $script:authUrl $script:authFriends $script:authMetadata $false $script:authBrowser}});$script:authSignUp.Add_Click({if(-not $script:busy){Show-NativeAuthPanel $script:authUrl $script:authFriends $script:authMetadata $true $script:authBrowser}})
}

