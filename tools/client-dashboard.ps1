# Host controls use a private file token. Browser accounts cannot start/stop the host.
function Set-LauncherBuilderVisibility([bool]$Ready) {
 $script:builderReady=$Ready
 $show=$Ready -and $script:dashboard -and $script:serverReady -and -not $script:busy
 if($signupPanel -and $signupPanel.Visible){$show=$false}
 if($script:authPanel -and $script:authPanel.Visible){$show=$false}
 if($script:settingsPanel -and $script:settingsPanel.Visible){$show=$false}
 foreach($button in @($itemBuilderButton,$mapBuilderButton)){if($button){$button.Visible=$show;$button.Enabled=$show}}
}
function Stop-LauncherBuilderStatus {
 if($script:builderStatusTimer){$script:builderStatusTimer.Stop();$script:builderStatusTimer.Dispose();$script:builderStatusTimer=$null}
 if($script:builderStatusClient){$script:builderStatusClient.Dispose();$script:builderStatusClient=$null}
 $script:builderStatusTask=$null;Set-LauncherBuilderVisibility $false
}
function Start-LauncherBuilderStatus {
 Stop-LauncherBuilderStatus
 if($PreviewPath -or -not $script:serverReady -or -not $script:control){return}
 Add-Type -AssemblyName System.Net.Http
 $script:builderStatusClient=New-Object Net.Http.HttpClient
 $script:builderStatusClient.Timeout=[TimeSpan]::FromSeconds(2)
 [void]$script:builderStatusClient.DefaultRequestHeaders.TryAddWithoutValidation('x-dekaron-launcher-token',[string]$script:control.token)
 $script:builderStatusUrl=(Get-ClientApiUrl $script:serverUrl)+'api/launcher/status'
 $script:builderStatusAt=[DateTime]::MinValue
 $script:builderStatusTimer=New-Object Windows.Forms.Timer;$script:builderStatusTimer.Interval=100
 $script:builderStatusTimer.Add_Tick({
  if(-not $script:dashboard -or -not $script:serverReady){Stop-LauncherBuilderStatus;return}
  if($script:builderStatusTask -and $script:builderStatusTask.IsCompleted){
   try{
    $status=$script:builderStatusTask.GetAwaiter().GetResult()|ConvertFrom-Json
    $valid=$status.engineId -ceq $script:runningPlan.engineId -and [int]$status.pid -eq [int]$script:control.pid -and -not $status.stopping
    Set-LauncherBuilderVisibility ($valid -and $status.builderReady -eq $true)
    if($valid -and $status.name){Set-ClientLocalServerName ([string]$status.name)}
   }catch{Set-LauncherBuilderVisibility $false}
   $script:builderStatusTask=$null;$script:builderStatusAt=[DateTime]::UtcNow.AddMilliseconds(750)
  }
  Set-LauncherBuilderVisibility ([bool]$script:builderReady)
  if(-not $script:builderStatusTask -and [DateTime]::UtcNow -ge $script:builderStatusAt){$script:builderStatusTask=$script:builderStatusClient.GetStringAsync($script:builderStatusUrl)}
 });$script:builderStatusTimer.Start()
}
function Start-LauncherRun([string]$Engine,$Plan,[string]$Url) {
 $control=Get-LauncherControl $Engine $Plan $Url
 [void](Invoke-RestMethod -Method Post -Uri ((Get-ClientApiUrl $Url)+'api/launcher/begin') -Headers @{'x-dekaron-launcher-token'=$control.token} -MaximumRedirection 0 -TimeoutSec 3)
}
function Test-ClientSettingsContext {
 if(-not $script:serverReady -or $script:remoteWorld -or -not $script:runningPlan -or -not $script:control){return $false}
 try{$uri=[Uri]$script:serverUrl;return $uri.Scheme -eq 'http' -and $uri.IsLoopback -and $script:control.url -ceq $script:serverUrl}catch{return $false}
}
function Test-ClientEditableSettingsContext {
 if(Test-ClientSettingsContext){return $true}
 if(Get-Command Test-ClientOfflineSettingsContext -ErrorAction SilentlyContinue){return (Test-ClientOfflineSettingsContext)}
 return $false
}
function Set-ClientLocalServerName([string]$Name) {
 $name=$Name.Trim();if(-not $name -or $name.Length -gt 64 -or $name -match '[\x00-\x1f\x7f]'){return}
 $script:localServerName=$name;$script:localServerNameUrl=$script:serverUrl
 if($script:serverLive){$state=$script:serverLive[[string]$script:serverUrl];if($state){$state.name=$name}}
 if($script:runningFriends -and $script:hostName){$script:hostName.Text=$name}
 if(Get-Command Update-ClientDashboardView -ErrorAction SilentlyContinue){Update-ClientDashboardView}
}
function Invoke-ClientSettingsRequest([string]$Method='GET',$Body=$null) {
 if(-not (Test-ClientSettingsContext)){if(Test-ClientEditableSettingsContext){if($Method -eq 'GET'){return (Invoke-ClientPrestartSettings 'read').settings};return (Invoke-ClientPrestartSettings 'set' $Body)};throw 'Start your own local world to change its server name.'}
 $control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl
 $args=@{Uri=((Get-ClientApiUrl $script:serverUrl)+'api/launcher/settings');Method=$Method;Headers=@{'x-dekaron-launcher-token'=$control.token};MaximumRedirection=0;TimeoutSec=5}
 if($Method -in @('POST','PUT')){$args.ContentType='application/json; charset=utf-8';$args.Body=[Text.Encoding]::UTF8.GetBytes(($Body|ConvertTo-Json -Compress))}
 try{$response=Invoke-RestMethod @args}catch{
  if($_.ErrorDetails.Message){try{$detail=$_.ErrorDetails.Message|ConvertFrom-Json;if($detail.error){throw [InvalidOperationException]::new([string]$detail.error)}}catch [InvalidOperationException]{throw}catch{}}
  throw 'Server settings could not be confirmed. Refresh settings before retrying.'
 }
 if($response.name -isnot [string] -or -not $response.name.Trim() -or $response.name.Length -gt 64 -or $response.name -match '[\x00-\x1f\x7f]'){throw 'The server name response could not be verified.'}
 return $response
}
function Update-ClientSettingsAvailability {
 if(-not $script:settingsPanel){return}
 $enabled=$script:settingsLoaded -and (Test-ClientEditableSettingsContext) -and -not $script:busy -and -not $script:ownerAccountsWorking
 $script:settingsName.Enabled=$enabled;$script:settingsSave.Enabled=$enabled
 if($script:settingsStarter){$script:settingsStarter.Enabled=$enabled}
 if($script:settingsPk){$script:settingsPk.Enabled=$enabled}
 if($script:settingsNpc){$script:settingsNpc.Enabled=$enabled}
 if($script:settingsLanguage){$script:settingsLanguage.Enabled=$enabled -and $script:settingsNpc.Checked}
 if($script:settingsCapacity){$script:settingsCapacity.Enabled=$enabled}
 $script:settingsRefresh.Enabled=-not $script:busy -and -not $script:ownerAccountsWorking
 $script:settingsHosting.Enabled=$script:settingsRefresh.Enabled
 if($script:settingsPhoneQr){$script:settingsPhoneQr.Enabled=$script:serverReady -and -not $script:remoteWorld -and -not $script:busy -and -not $script:ownerAccountsWorking}
 Update-SettingsListingControls
}
function Get-PublicListingBlocker {
 if(-not (Test-ClientSettingsContext)){return 'Start your own hosted world first. Only the host can list it.'}
 if(-not $script:runningFriends){return 'Public listing is for a hosted world. Create one in Hosting options.'}
 if(-not $script:relayConfig){return 'Public listing needs the Online relay (Hosting options > More), so your home address is never published.'}
 # Listing is optional for both open and password-protected hosted worlds.
 return ''
}
function Update-SettingsListingControls {
 if(-not $script:settingsPublicList){return}
 $idle=-not $script:busy -and -not $script:ownerAccountsWorking -and -not $script:settingsListWorking
 $blocker=Get-PublicListingBlocker
 $script:settingsPublicList.Checked=[bool]$script:publicListing
 $script:settingsPublicList.Enabled=$idle -and ($script:publicListing -or -not $blocker)
 $script:settingsDirectory.Enabled=$idle;$script:settingsDirSave.Enabled=$idle;$script:settingsDirTest.Enabled=$idle;$script:settingsLan.Enabled=$idle
 $script:settingsLan.Checked=Test-ClientAllowLan
 if(-not $script:settingsListMessage){$script:settingsListStatus.Text=$(if($script:publicListing){'Your server is listed. Turn this off at any time; your relay keeps running.'}elseif($blocker){$blocker}else{'Not listed. Turning this on shows a warning first.'})}
}
# Persist hosting extras without changing what the launcher starts as next time (the saved "kind" is kept).
function Update-ClientHostingPrefs([hashtable]$Changes) {
 $prefs=Read-ClientHostPreferences;$kind=$(if($prefs){[string]$prefs.kind}else{'local'})
 $hosting=@{mode=$(if($prefs -and $prefs.hosting){[string]$prefs.hosting.mode}else{'invite'})}
 if($prefs -and $prefs.hosting){foreach($k in @('relay','listingConsent','listDirectory','allowLan')){if($null -ne $prefs.hosting.$k){$hosting[$k]=$prefs.hosting.$k}}}
 foreach($k in $Changes.Keys){$hosting[$k]=$Changes[$k]}
 Save-ClientHostPreferences @{kind=$kind;url=$(if($prefs){$prefs.url});hosting=$hosting}
}
function Set-ClientListingPreference([bool]$On,[string]$Directory) {
 $prefs=Read-ClientHostPreferences;$changes=@{listDirectory=$Directory}
 if($prefs -and $prefs.hosting -and $prefs.hosting.relay){$r=$prefs.hosting.relay;$changes.relay=@{publicOrigin=$r.publicOrigin;tokenFile=$r.tokenFile;publish=$On;directory=$Directory}}
 if($On -and $script:listingConsent){$changes.listingConsent=$script:listingConsent}
 Update-ClientHostingPrefs $changes
}
# The host panel autosaves its own controls when they change; programmatic syncs from Settings must not trigger that stale save.
function Set-ListDirectoryText([string]$Dir) {
 $was=$script:restoringRelayPreferences;$script:restoringRelayPreferences=$true
 try{if($script:listDirectory){$script:listDirectory.Text=$Dir};if($script:publicDirectory){$script:publicDirectory.Text=$Dir}}finally{$script:restoringRelayPreferences=$was}
}
function Set-SettingsListingMessage([string]$Text) { $script:settingsListMessage=$true;$script:settingsListStatus.Text=$Text }
function Set-SettingsPublicListing([bool]$On) {
 if($script:busy -or $script:ownerAccountsWorking -or $script:settingsListWorking){return}
 $script:settingsListWorking=$true;$script:settingsListMessage=$false;$done=$false
 try{
  if($On){
   $blocker=Get-PublicListingBlocker;if($blocker){Set-SettingsListingMessage $blocker;return}
   try{$dir=(ConvertTo-ClientRelayOrigin $script:settingsDirectory.Text)+'/'}catch{Set-SettingsListingMessage 'Enter the directory address first (HTTPS, no path).';return}
   if(-not (Confirm-PublicListingConsent $dir)){Set-SettingsListingMessage 'Not listed. You did not confirm the warning.';return}
   Set-ListDirectoryText $dir;$script:relayConfig.directory=$dir;$script:relayConfig.publish=$true
   Enable-OwnedPublicListing $clientEngine $clientNode.Source $script:runningPlan $script:serverUrl
   $script:publicListing=$true;Set-ClientListingPreference $true $dir;$done=$true
   Set-SettingsListingMessage 'Listed. People using this directory will see your server. Switch it off here any time; the relay keeps running.'
  }else{
   Disable-OwnedPublicListing;$script:publicListing=$false;if($script:relayConfig){$script:relayConfig.publish=$false}
   try{Set-ClientListingPreference $false ((ConvertTo-ClientRelayOrigin $script:settingsDirectory.Text)+'/')}catch{}
   Set-SettingsListingMessage 'Withdrawn. Your server leaves the list shortly. Your relay is still running, so friends with your address can still join.'
  }
 }catch{Set-SettingsListingMessage ([string]$_.Exception.Message)}
 finally{$script:settingsListWorking=$false;Update-SettingsListingControls}
}
function Disable-OwnedPublicListing {
 # Withdraw the listing WITHOUT stopping the relay or the server.
 $script:publicationRequested=$true
 try{$control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl;$withdrawal=Invoke-RestMethod -Uri ((Get-ClientApiUrl $script:serverUrl)+'api/launcher/publication') -Method Post -Headers @{'x-dekaron-launcher-token'=$control.token} -ContentType 'application/json' -Body '{"enabled":false}' -MaximumRedirection 0 -TimeoutSec 5;if($withdrawal.enabled -is [bool] -and -not $withdrawal.enabled){$script:publicationRequested=$false}}catch{throw 'The server did not confirm the withdrawal. Try again.'}
 $script:publicListing=$false
 if($script:publisherProcess){try{$script:publisherProcess.StandardInput.Close();if(-not $script:publisherProcess.WaitForExit(12000)){$script:publisherProcess.Kill()}}finally{$script:publisherProcess.Dispose();$script:publisherProcess=$null}}
}
function Refresh-ClientSettingsPanel {
 $script:settingsLoaded=$false;$script:settingsListMessage=$false
 $prefs=$null;try{$prefs=Read-ClientHostPreferences}catch{}
 $dirText='';if($prefs -and $prefs.hosting -and $prefs.hosting.listDirectory){$dirText=[string]$prefs.hosting.listDirectory}elseif($script:listDirectory -and $script:listDirectory.Text){$dirText=$script:listDirectory.Text}elseif($env:DEKARON_DIRECTORY_URL){$dirText=$env:DEKARON_DIRECTORY_URL}
 if($script:settingsDirectory -and -not $script:settingsDirectory.Focused){$script:settingsDirectory.Text=$dirText}
 try{
  if($script:remoteWorld){$script:settingsName.Text=[string]$script:remoteMetadata.name;$script:settingsResult.Text='This world belongs to its host. Only that host can change the server name.';return}
  if(-not (Test-ClientSettingsContext) -and -not $PreviewPath -and $script:planValid -and (Get-Command Invoke-ClientPrestartSettings -ErrorAction SilentlyContinue)){$offline=Invoke-ClientPrestartSettings 'read';$script:offlineSettings=-not $offline.running}
  if(-not (Test-ClientEditableSettingsContext)){$script:settingsName.Text=$(if($script:localServerName){$script:localServerName}else{'Dekaron Online'});$script:settingsResult.Text='Start your local world, then return here to change its server name.';return}
  $settings=Invoke-ClientSettingsRequest;Set-ClientLocalServerName $settings.name;$script:settingsName.Text=$settings.name;$script:settingsLoaded=$true
  if($script:settingsStarter){$script:settingsStarter.Checked=($settings.starterPack -ne $false)}   # absent = on (the server only reports the switch while it is off)
  if($script:settingsPk){$script:settingsPk.Checked=($settings.fieldPk -ne $false)}
  if($script:settingsNpc){$script:settingsNpc.Checked=($settings.npcPlayers -eq $true)}
  if($script:settingsLanguage){$script:savedLanguage=$(if($settings.npcLanguage){[string]$settings.npcLanguage}else{'en'});$script:settingsLanguage.SelectedIndex=[Array]::IndexOf($script:botLanguageCodes,$script:savedLanguage)}
  Update-ClientSettingsContinue
  $script:settingsResult.Text='Your server name appears in the client, world list and in-game server display.'
 }catch{$script:settingsResult.Text=$_.Exception.Message}finally{Update-ClientSettingsAvailability}
}
function Update-ClientSettingsContinue {
 if(-not $script:settingsContinue){return}
 # ENGINE-CHOSEN launcher accent requested by the owner; native game UI is unchanged.
 $script:settingsContinue.Text=$(if($script:prestartPending){'Launch'}else{'Back'})
 $script:settingsContinue.AccentColor=$(if($script:prestartPending){[Drawing.Color]::FromArgb(30,164,82)}else{[Drawing.Color]::Empty})
 $script:settingsContinue.ForeColor=$(if($script:prestartPending){[Drawing.Color]::FromArgb(240,255,244)}else{$muted})
}
function Close-ClientSettingsPanel([bool]$Restore=$true) {
 if(-not $script:settingsPanel -or -not $script:settingsPanel.Visible){return}
 $script:settingsPanel.Visible=$false
 if($Restore){
  foreach($control in @($script:settingsCovered)){if($control -and $control -ne $progress){$control.Visible=$true}}
  $progress.Visible=-not $script:cachedReady -and -not $script:dashboard -and -not $script:serverReady -and -not $script:preparationFailure
  $form.AcceptButton=$primary
 }
 $script:settingsCovered=@();$script:settingsLoaded=$false
}
function Show-ClientSettingsPanel {
 if($script:busy -or $script:ownerAccountsWorking){return}
 Show-ClientDashboardTab
 $script:settingsCovered=@()
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$progress,$statusLine,$script:browserLaunch,$script:localWorld,$itemBuilderButton,$mapBuilderButton)){   # the top-row buttons stay
  if($control -and $control.Visible){$script:settingsCovered+=,$control}
 }
 $script:settingsPanel.Visible=$true;foreach($control in $script:settingsCovered){$control.Visible=$false}
 $script:settingsPanel.BringToFront();Refresh-ClientSettingsPanel
 if($script:dedicatedMode){Sync-StartupStorageChoice}
 $form.AcceptButton=$script:settingsSave
}
function Save-ClientSettings {
 $script:settingsNameSaved=$false
 if($script:busy -or $script:ownerAccountsWorking -or -not $script:settingsLoaded -or -not (Test-ClientEditableSettingsContext)){return}
 $name=$script:settingsName.Text.Trim()
 if(-not $name -or $name.Length -gt 64 -or $name -match '[\x00-\x1f\x7f]'){$script:settingsResult.Text='Use a server name of 1-64 printable characters.';return}
 $script:busy=$true;Update-ClientSettingsAvailability
 try{
  $saved=Invoke-ClientSettingsRequest 'POST' @{name=$name}
  if($saved.name -cne $name){throw 'The saved server name did not match. Refresh settings before retrying.'}
  Set-ClientLocalServerName $saved.name;$script:settingsName.Text=$saved.name;$script:settingsNameSaved=$true
  $script:settingsResult.Text='Server name saved. Open game clients update their server display shortly.'
 }catch{$script:settingsResult.Text=$_.Exception.Message}finally{$script:busy=$false;Update-ClientSettingsAvailability;Update-ClientDashboardView}
}
function Set-ClientServerSwitch([string]$Key,[bool]$On,$Box,[string]$OnText,[string]$OffText) {
 # Per-server on/off switch of the owner's world (stored beside its accounts, written only while off): one setting per request.
 if($script:busy -or $script:ownerAccountsWorking -or -not $script:settingsLoaded -or -not (Test-ClientEditableSettingsContext)){$Box.Checked=-not $On;return}
 $script:busy=$true;Update-ClientSettingsAvailability
 try{
  $saved=Invoke-ClientSettingsRequest 'POST' @{$Key=$On}
  $now=$(if($Key -eq 'npcPlayers'){$saved.$Key -eq $true}else{$saved.$Key -ne $false})
  if($now -ne $On){throw 'The saved setting did not match. Refresh settings before retrying.'}
  $Box.Checked=$now
  $script:settingsResult.Text=$(if($now){$OnText}else{$OffText})
 }catch{$Box.Checked=-not $On;$script:settingsResult.Text=$_.Exception.Message}finally{$script:busy=$false;Update-ClientSettingsAvailability;Update-ClientDashboardView}
}
function Set-ClientStarterPack([bool]$On) {
 # Does a NEW character of this server get the starter pack? Already created characters keep what they have.
 Set-ClientServerSwitch 'starterPack' $On $script:settingsStarter 'New characters on this server get the starter pack.' 'New characters on this server get NO starter pack. Characters that already exist keep what they have.'
}
function Set-ClientFieldPk([bool]$On) {
 # Player killing (PK): hold Ctrl to attack other players on the open PvP maps; safe zones, parties and guild mates stay protected.
 Set-ClientServerSwitch 'fieldPk' $On $script:settingsPk 'PK is on: players can attack each other with Ctrl on open PvP maps (never in safe zones, parties or guilds).' 'PK is off on this server: Ctrl does not attack players.'
}function Initialize-ClientSettingsControls {
 $script:settingsLoaded=$false;$script:settingsCovered=@();$script:settingsListWorking=$false;$script:settingsListMessage=$false
 $script:settingsPanel=New-Object GalaxyPanel;$script:settingsPanel.Bounds=New-Object Drawing.Rectangle(110,165,780,458);$script:settingsPanel.Visible=$false;$form.Controls.Add($script:settingsPanel)
 function Add-SettingsLabel([string]$Text,[int]$X,[int]$Y,[int]$W,[int]$H,[int]$Size=10){
  $label=New-Object Windows.Forms.Label;$label.Text=$Text;$label.UseMnemonic=$false;$label.Bounds=New-Object Drawing.Rectangle($X,$Y,$W,$H);$label.Font=New-Object Drawing.Font('Segoe UI',$Size,$(if($Size -le 10){[Drawing.FontStyle]::Bold}else{[Drawing.FontStyle]::Regular}));$label.ForeColor=$muted;$script:settingsPanel.Controls.Add($label);return $label
 }
 $heading=Add-SettingsLabel 'World settings' 26 14 205 38 19;$heading.ForeColor=$gold
 [void](Add-SettingsLabel 'Server name' 26 62 640 22)
 $script:settingsName=New-Object GalaxyTextBox;$script:settingsName.AccessibleName='Server name';$script:settingsName.MaxLength=64;$script:settingsName.Bounds=New-Object Drawing.Rectangle(26,88,550,34);$script:settingsName.ForeColor=$form.ForeColor;$script:settingsPanel.Controls.Add($script:settingsName)
 $script:settingsSave=New-Object RoundedLauncherButton;$script:settingsSave.Text='Save name';$script:settingsSave.Bounds=New-Object Drawing.Rectangle(590,88,162,34);$script:settingsSave.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:settingsSave);$script:settingsSave.Add_Click({Save-ClientSettings})
 $script:settingsResult=Add-SettingsLabel '' 26 126 726 18;$script:settingsResult.ForeColor=$gold
 $script:settingsStarter=New-Object Windows.Forms.CheckBox;$script:settingsStarter.Text='New characters get the starter pack';$script:settingsStarter.AccessibleName='Give new characters the starter pack';$script:settingsStarter.Bounds=New-Object Drawing.Rectangle(26,146,330,24);$script:settingsStarter.ForeColor=$gold;$script:settingsStarter.Checked=$true;$script:settingsStarter.Enabled=$false;$script:settingsPanel.Controls.Add($script:settingsStarter)
 $script:settingsStarter.Add_Click({Set-ClientStarterPack ([bool]$script:settingsStarter.Checked)})
 $script:settingsPk=New-Object Windows.Forms.CheckBox;$script:settingsPk.Text='Allow PK on open maps (hold Ctrl to attack players)';$script:settingsPk.AccessibleName='Allow player killing with Ctrl on open maps';$script:settingsPk.Bounds=New-Object Drawing.Rectangle(372,146,380,24);$script:settingsPk.ForeColor=$gold;$script:settingsPk.Checked=$true;$script:settingsPk.Enabled=$false;$script:settingsPanel.Controls.Add($script:settingsPk)
 $script:settingsPk.Add_Click({Set-ClientFieldPk ([bool]$script:settingsPk.Checked)})
 $script:settingsNpc=New-Object Windows.Forms.CheckBox;$script:settingsNpc.Text='Bots (experimental - work in progress)';$script:settingsNpc.AccessibleName='Enable experimental bots';$script:settingsNpc.AccessibleDescription='Disabled by default. Optional automated players with automatic population; behavior and performance are still being improved.';$script:settingsNpc.Bounds=New-Object Drawing.Rectangle(26,170,390,24);$script:settingsNpc.ForeColor=$gold;$script:settingsNpc.Checked=$false;$script:settingsNpc.Enabled=$false;$script:settingsPanel.Controls.Add($script:settingsNpc)
 $builderTip.SetToolTip($script:settingsNpc,'Disabled by default. Bots are experimental: behavior and performance are still being improved. Population adjusts automatically when enabled.')
 $script:settingsNpc.Add_Click({Set-ClientServerSwitch 'npcPlayers' ([bool]$script:settingsNpc.Checked) $script:settingsNpc 'Experimental bots are on. Behavior and performance are still a work in progress.' 'Bots are off. Their progress is saved.'})
 # --- Public server list (item 1): same galaxy pieces as the rest of the dashboard ---
 $listHeading=Add-SettingsLabel 'Public server list' 26 170 650 24 13;$listHeading.ForeColor=$gold
 $script:settingsPublicList=New-Object Windows.Forms.CheckBox;$script:settingsPublicList.Text='List my server in the public directory (access rules stay unchanged)';$script:settingsPublicList.AccessibleName='List my server in the public directory';$script:settingsPublicList.Bounds=New-Object Drawing.Rectangle(26,194,726,24);$script:settingsPublicList.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:settingsPublicList)
 $script:settingsPublicList.Add_Click({Set-SettingsPublicListing ([bool]$script:settingsPublicList.Checked)})
 [void](Add-SettingsLabel 'Directory address (HTTPS). Fills the Worlds list and is where your server lists itself.' 26 222 726 20)
 $script:settingsDirectory=New-Object GalaxyTextBox;$script:settingsDirectory.AccessibleName='Directory address';$script:settingsDirectory.MaxLength=256;$script:settingsDirectory.Bounds=New-Object Drawing.Rectangle(26,244,436,32);$script:settingsDirectory.ForeColor=$form.ForeColor;$script:settingsPanel.Controls.Add($script:settingsDirectory)
 $script:settingsDirTest=New-Object RoundedLauncherButton;$script:settingsDirTest.Text='Test connection';$script:settingsDirTest.Bounds=New-Object Drawing.Rectangle(474,244,134,32);$script:settingsDirTest.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:settingsDirTest)
 $script:settingsDirSave=New-Object RoundedLauncherButton;$script:settingsDirSave.Text='Save address';$script:settingsDirSave.Bounds=New-Object Drawing.Rectangle(618,244,134,32);$script:settingsDirSave.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:settingsDirSave)
 $script:settingsListStatus=Add-SettingsLabel '' 26 280 726 40;$script:settingsListStatus.ForeColor=$gold
 $script:settingsLan=New-Object Windows.Forms.CheckBox;$script:settingsLan.Text='Allow direct LAN connections the next time I host (shows my LAN address; relay-only is the default)';$script:settingsLan.AccessibleName='Allow direct LAN connections';$script:settingsLan.Bounds=New-Object Drawing.Rectangle(26,322,726,24);$script:settingsLan.ForeColor=$muted;$script:settingsPanel.Controls.Add($script:settingsLan)
 $script:settingsDirSave.Add_Click({Save-SettingsDirectory})
 $script:settingsDirTest.Add_Click({Test-SettingsDirectory})
 $script:settingsLan.Add_Click({Set-SettingsAllowLan ([bool]$script:settingsLan.Checked)})
 # --- one-click hosting setup routes (write a guide + files, open the folder; nothing is deployed for you) ---
 [void](Add-SettingsLabel 'Set up hosting (no project-run server: you pick where it runs)' 26 354 726 20)
 $x=26;foreach($route in @(@('local','On this PC'),@('vps','My own VPS'),@('vercel','Vercel'),@('cloudflare','Cloudflare'))){
  $button=New-Object RoundedLauncherButton;$button.Text=$route[1];$button.Tag=$route[0];$button.Bounds=New-Object Drawing.Rectangle($x,376,170,32);$button.ForeColor=$gold;$script:settingsPanel.Controls.Add($button);$x+=194
  $button.Add_Click({param($sender,$e);Invoke-HostingSetupRoute ([string]$sender.Tag)})
 }
 $script:settingsHosting=New-Object RoundedLauncherButton;$script:settingsHosting.Text='Hosting options';$script:settingsHosting.Bounds=New-Object Drawing.Rectangle(26,414,230,36);$script:settingsHosting.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:settingsHosting)
 $script:settingsHosting.Add_Click({if(-not $script:busy -and -not $script:ownerAccountsWorking){Show-ClientDashboardTab;Show-FriendsPanel $(if($script:serverReady -and $script:runningFriends){'invite'}else{'host'})}})
 $script:settingsPhoneQr=New-Object RoundedLauncherButton;$script:settingsPhoneQr.Text='Phone / tablet QR';$script:settingsPhoneQr.AccessibleName='Phone or tablet server QR';$script:settingsPhoneQr.Bounds=New-Object Drawing.Rectangle(590,14,162,34);$script:settingsPhoneQr.ForeColor=$gold;$script:settingsPhoneQr.Enabled=$false;$script:settingsPanel.Controls.Add($script:settingsPhoneQr);$script:settingsPhoneQr.Add_Click({Show-ClientPhoneQr})
 $script:settingsRefresh=New-Object RoundedLauncherButton;$script:settingsRefresh.Text='Refresh';$script:settingsRefresh.Bounds=New-Object Drawing.Rectangle(524,414,108,36);$script:settingsRefresh.ForeColor=$muted;$script:settingsPanel.Controls.Add($script:settingsRefresh);$script:settingsRefresh.Add_Click({if(-not $script:busy -and -not $script:ownerAccountsWorking){Refresh-ClientSettingsPanel}})
 $close=New-Object RoundedLauncherButton;$close.Text='Back';$close.Bounds=New-Object Drawing.Rectangle(644,414,108,36);$close.ForeColor=$muted;$script:settingsPanel.Controls.Add($close);$script:settingsContinue=$close;$close.Add_Click({if(-not $script:busy -and -not $script:ownerAccountsWorking){if($script:prestartPending){Complete-ClientPrestartSettings}else{Show-ClientDashboardTab}}})
 # One added row; shift the existing public-list/hosting controls together to preserve their spacing.
 foreach($control in $script:settingsPanel.Controls){if($control -ne $script:settingsNpc -and $control.Top -ge 170){$control.Top+=28}}
 $script:settingsPanel.Height+=28
 $script:settingsCapacity=New-Object RoundedLauncherButton;$script:settingsCapacity.Text='Server capacity';$script:settingsCapacity.Bounds=New-Object Drawing.Rectangle(268,442,242,36);$script:settingsCapacity.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:settingsCapacity);$script:settingsCapacity.Add_Click({Show-ClientCapacityPanel})
 # This fits the existing Bots row and uses the launcher's themed dropdown.
 $script:botLanguageCodes=@('en','es','pt','de','fr');$script:savedLanguage='en'
 [void](Add-SettingsLabel 'Bot chat' 422 173 108 22)
 $script:settingsLanguage=New-Object GalaxyComboBox;$script:settingsLanguage.DropDownStyle='DropDownList';$script:settingsLanguage.AccessibleName='Bot chat language';$script:settingsLanguage.Bounds=New-Object Drawing.Rectangle(536,168,216,27);$script:settingsLanguage.ForeColor=$gold;$script:settingsLanguage.BackColor=$form.BackColor
 foreach($label in @('English','Spanish','Portuguese','German','French')){[void]$script:settingsLanguage.Items.Add($label)}
 $script:settingsLanguage.SelectedIndex=0;$script:settingsLanguage.Enabled=$false;$script:settingsPanel.Controls.Add($script:settingsLanguage)
 $builderTip.SetToolTip($script:settingsLanguage,'Common bot replies and short requests. Other replies stay in English; native item and skill names stay unchanged.')
 $script:settingsLanguage.Add_SelectionChangeCommitted({Save-ClientBotLanguage})

}
function Save-SettingsDirectory {
 if($script:busy -or $script:ownerAccountsWorking){return}
 try{
  $dir=(ConvertTo-ClientRelayOrigin $script:settingsDirectory.Text)+'/'
  $changed=[bool]($script:listDirectory -and $script:listDirectory.Text -and $script:listDirectory.Text -cne $dir);$wasListed=[bool]$script:publicListing
  if($wasListed -and $changed){Set-SettingsPublicListing $false}
  Set-ListDirectoryText $dir
  Update-ClientHostingPrefs @{listDirectory=$dir}
  Set-SettingsListingMessage $(if($wasListed -and $changed){'Address saved. Listing was switched off because the directory changed; turn it on again to confirm the warning for the new directory.'}else{'Address saved. The Worlds list now loads from it automatically.'})
 }catch{Set-SettingsListingMessage 'Use the directory HTTPS root address, for example https://directory.example.com/ (no path, no port).'}
}
function Test-SettingsDirectory {
 if($script:busy -or $script:ownerAccountsWorking){return}
 try{[void](ConvertTo-PublicDirectoryUri $script:settingsDirectory.Text)}catch{Set-SettingsListingMessage $_.Exception.Message;return}
 Set-ListDirectoryText $script:settingsDirectory.Text.Trim()
 Set-SettingsListingMessage 'Testing the directory...'
 Start-PublicListFetch $true {param($ok,$text);Set-SettingsListingMessage $text}
}
function Set-SettingsAllowLan([bool]$On) {
 try{$script:allowLan=$On;Update-ClientHostingPrefs @{allowLan=$On};Set-SettingsListingMessage $(if($On){'Direct LAN connections are allowed the next time you host. Your LAN address is then shown to friends.'}else{'Relay-only: the next host binds to this PC only. Players connect through your relay.'})}
 catch{$script:allowLan=-not $On;$script:settingsLan.Checked=-not $On;Set-SettingsListingMessage ([string]$_.Exception.Message)}
}
function Invoke-HostingSetupRoute([string]$Route) {
 if($script:busy -or $script:ownerAccountsWorking){return}
 try{
  if($Route -ceq 'local'){Show-ClientDashboardTab;Show-FriendsPanel $(if($script:serverReady -and $script:runningFriends){'invite'}else{'host'})}
  $relay=$(if($script:relayOrigin){$script:relayOrigin.Text}else{''})
  $kit=New-HostingSetupKit $Route $relay $script:settingsDirectory.Text
  $folder=Write-HostingSetupKit $kit $clientEngine ((-not $PreviewPath) -and $Route -cne 'local')
  if($Route -cne 'local'){Set-SettingsListingMessage ('Guide written to '+$folder+$(if($kit.placeholders.Count){' (uses example values for the '+($kit.placeholders -join ' and ')+')'}else{''}))}
 }catch{Set-SettingsListingMessage ([string]$_.Exception.Message)}
}function Open-LauncherBuilder([string]$Engine,$Plan,[string]$Url,[string]$Tool) {
 if($Tool -notin @('itembuilder','mapbuilder')){throw 'Unknown builder.'}
 $control=Get-LauncherControl $Engine $Plan $Url
 try{
  $result=Invoke-RestMethod -Method Post -Uri ((Get-ClientApiUrl $Url)+'api/launcher/tool') -Headers @{'x-dekaron-launcher-token'=$control.token} -ContentType 'application/json; charset=utf-8' -Body ([Text.Encoding]::UTF8.GetBytes((@{tool=$Tool}|ConvertTo-Json -Compress))) -MaximumRedirection 0 -TimeoutSec 3
  if(-not $result.queued){throw 'The server did not accept the builder request.'}
  return ('Opening '+$Tool+' in primary account '+$result.primary+'.')
 }catch{
  if($_.ErrorDetails.Message){try{$detail=$_.ErrorDetails.Message|ConvertFrom-Json;if($detail.error){throw [InvalidOperationException]::new([string]$detail.error)}}catch [InvalidOperationException]{throw}catch{}}
  throw
 }
}
function Get-LauncherControl([string]$Engine,$Plan,[string]$Url) {
 $port=([Uri]$Url).Port;$file=Join-Path $Engine ('server\launcher-control-'+$port+'.json')
 if(-not (Test-Path -LiteralPath $file -PathType Leaf)){$file=Join-Path $Engine 'server\launcher-control.json'}
 Assert-ClientPathUnlinked $file
 if(-not (Test-Path -LiteralPath $file -PathType Leaf)){throw 'This installation has no launcher control file for the running server. Open Client.exe from the same game folder that started that server. If you started the server separately or updated while it was running, wait for players to leave, close it normally from its original launcher or console, then start this Client.exe again. If this repeats, check that this game folder is writable. Do not delete saves or copy control files from another installation.'}
 $control=Get-Content -LiteralPath $file -Raw | ConvertFrom-Json
 $uri=[Uri]$control.url
 if($uri.Scheme -ne 'http' -or -not $uri.IsLoopback -or $control.url -cne $Url -or $control.engineId -cne $Plan.engineId -or $control.token -notmatch '^[a-f0-9]{64}$'){throw 'The launcher could not verify its server control file.'}
 $status=Invoke-RestMethod -Uri ((Get-ClientApiUrl $Url)+'api/launcher/status') -Headers @{'x-dekaron-launcher-token'=$control.token} -MaximumRedirection 0 -TimeoutSec 3
 if(-not (Test-ClientServerIdentity $status $Plan) -or [int]$status.pid -ne [int]$control.pid){throw 'The launcher control belongs to a different server.'}
 return $control
}
function Test-LauncherServerExited($KnownControl,$Plan,[string]$Url) {
 if(-not $KnownControl -or -not $Plan){return $false}
 try {
  $uri=[Uri]$Url
  if($uri.Scheme -ne 'http' -or -not $uri.IsLoopback -or $KnownControl.url -cne $Url -or $KnownControl.engineId -cne $Plan.engineId -or $KnownControl.token -notmatch '^[a-f0-9]{64}$' -or [int]$KnownControl.pid -le 0){return $false}
  # A reused PID or any listener on this port keeps the strict live-server path.
  for($check=0;$check -lt 2;$check++){
   try{$process=[Diagnostics.Process]::GetProcessById([int]$KnownControl.pid);$process.Dispose();return $false}catch [ArgumentException]{}
   $listeners=[Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties().GetActiveTcpListeners()
   if(@($listeners|Where-Object{$_.Port -eq $uri.Port}).Count){return $false}
  }
  return $true
 }catch{return $false}
}
function Stop-LauncherServer([string]$Engine,$Plan,[string]$Url,$KnownControl=$null) {
 if(Test-LauncherServerExited $KnownControl $Plan $Url){return [pscustomobject]@{stopped=$true;saved=$false;alreadyStopped=$true}}
 $control=Get-LauncherControl $Engine $Plan $Url
 $live=Invoke-RestMethod -Uri ((Get-ClientApiUrl $Url)+'api/launcher/status') -Headers @{'x-dekaron-launcher-token'=$control.token} -MaximumRedirection 0 -TimeoutSec 5
 if([int]$live.connectedClients -gt 0 -or [int]$live.realPlayers -gt 0){throw 'Disconnect all clients from this server before stopping it. Sign out of the lobby too, or wait one minute after closing a client.'}
 $result=Invoke-RestMethod -Uri ((Get-ClientApiUrl $Url)+'api/launcher/stop') -Method Post -Headers @{'x-dekaron-launcher-token'=$control.token} -MaximumRedirection 0 -TimeoutSec 30
 if(-not $result.stopped -or -not $result.saved){throw 'The server did not confirm that characters were saved and stopped.'}
 return $result
}
function Get-ClientBrowser {
 $candidates=@()
 foreach($key in @('HKCU:\Software\Microsoft\Windows\CurrentVersion\App Paths\msedge.exe','HKLM:\Software\Microsoft\Windows\CurrentVersion\App Paths\msedge.exe','HKCU:\Software\Microsoft\Windows\CurrentVersion\App Paths\chrome.exe','HKLM:\Software\Microsoft\Windows\CurrentVersion\App Paths\chrome.exe')){
  $entry=Get-ItemProperty -LiteralPath $key -ErrorAction SilentlyContinue;if($entry){$candidates+=$entry.'(default)'}
 }
 foreach($base in @(${env:ProgramFiles(x86)},$env:ProgramFiles,$env:LOCALAPPDATA)){if($base){$candidates+=Join-Path $base 'Microsoft\Edge\Application\msedge.exe';$candidates+=Join-Path $base 'Google\Chrome\Application\chrome.exe'}}
 foreach($candidate in $candidates){if($candidate -and (Test-Path -LiteralPath $candidate -PathType Leaf)){return $candidate}}
 throw 'Install Microsoft Edge or Google Chrome to open independent game windows.'
}
function Initialize-DesktopClientReturn {
 if($script:desktopReturnTimer -or $PreviewPath){return}
 if(-not $script:desktopClients){$script:desktopClients=New-Object Collections.ArrayList}
 $script:desktopReturnPending=$false
 $script:desktopReturnTimer=New-Object Windows.Forms.Timer;$script:desktopReturnTimer.Interval=350
 $script:desktopReturnTimer.Add_Tick({Update-DesktopClientReturn});$script:desktopReturnTimer.Start()
}
function Register-DesktopClientProcess([Diagnostics.Process]$Process,[string]$ProfilePath='') {
 if(-not $Process){return}
 Initialize-DesktopClientReturn
 if(-not $script:desktopClients){$script:desktopClients=New-Object Collections.ArrayList}
 [void]$script:desktopClients.Add([pscustomobject]@{process=$Process;closeRequested=$false;returned=$false;profile=$ProfilePath})
}
# Each game window gets a throw-away browser profile (engine\runtime\browser-profiles\client-<32 hex>, Open-IsolatedGame); none is ever
# reused, so a closed window's profile is deleted (each held ~0.5 GB of browser cache; 16 GB had piled up). Only that exact folder
# shape directly under the profile root is ever removed; a folder the browser still holds is retried on the next timer ticks.
function Test-DesktopClientProfilePath([string]$Root,[string]$Path) {
 try{$rootFull=[IO.Path]::GetFullPath($Root).TrimEnd('\');$full=[IO.Path]::GetFullPath($Path).TrimEnd('\')}catch{return $false}
 return ([IO.Path]::GetDirectoryName($full) -ieq $rootFull) -and ([IO.Path]::GetFileName($full) -cmatch '^client-[0-9a-f]{32}$')
}
function Remove-DesktopClientProfile([string]$Root,[string]$Path) {
 if(-not (Test-DesktopClientProfilePath $Root $Path)){return $false}
 if(-not (Test-Path -LiteralPath $Path -PathType Container)){return $true}
 $item=Get-Item -LiteralPath $Path -Force;if($item.Attributes -band [IO.FileAttributes]::ReparsePoint){return $false}
 foreach($open in @($script:desktopClients)){if($open -and $open.profile -and ([IO.Path]::GetFullPath($open.profile).TrimEnd('\') -ieq [IO.Path]::GetFullPath($Path).TrimEnd('\'))){return $false}}
 # a running Edge / Chrome keeps <profile>\lockfile open: never delete (even partly) a profile that is still in use
 $lock=Join-Path $Path 'lockfile'
 if(Test-Path -LiteralPath $lock -PathType Leaf){try{$fs=[IO.File]::Open($lock,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$fs.Dispose()}catch{return $false}}
 try{[IO.Directory]::Delete($Path,$true);return $true}catch{return $false}
}
function Get-DesktopClientProfileRoot([string]$Engine){return [IO.Path]::GetFullPath((Join-Path $Engine 'runtime\browser-profiles'))}
function Clear-StaleDesktopClientProfiles([string]$Engine,[TimeSpan]$OlderThan=[TimeSpan]::FromHours(1)) {
 $root=Get-DesktopClientProfileRoot $Engine;if(-not (Test-Path -LiteralPath $root -PathType Container)){return 0}
 $removed=0;$cutoff=[DateTime]::Now-$OlderThan
 foreach($dir in [IO.Directory]::GetDirectories($root)){if([IO.Directory]::GetLastWriteTime($dir) -lt $cutoff -and (Remove-DesktopClientProfile $root $dir)){$removed++}}
 return $removed
}
function Update-DesktopClientReturn {
 # closed windows' profiles: the browser can hold files for a moment after its window closes, so retry for ~1 minute
 foreach($pending in @($script:desktopProfilesToRemove)){if(-not $pending){continue};$pending.tries++;if((Remove-DesktopClientProfile (Split-Path -Parent $pending.path) $pending.path) -or $pending.tries -ge 180){[void]$script:desktopProfilesToRemove.Remove($pending)}}
 foreach($entry in @($script:desktopClients)){
  try{
   $entry.process.Refresh()
   if($entry.process.HasExited){if(-not $entry.returned){$script:desktopReturnPending=$true};[void]$script:desktopClients.Remove($entry);$entry.process.Dispose();if($entry.profile){if(-not $script:desktopProfilesToRemove){$script:desktopProfilesToRemove=New-Object Collections.ArrayList};[void]$script:desktopProfilesToRemove.Add([pscustomobject]@{path=$entry.profile;tries=0})};continue}
   # Only an app process created by this launcher is examined. Never enumerate or close other browser windows.
   $title=$entry.process.MainWindowTitle
   if(-not $entry.closeRequested -and ($title -ceq 'Dekaron - Return to Client' -or $title.StartsWith('Dekaron - Return to Client - ',[StringComparison]::Ordinal))){
    $entry.closeRequested=$entry.process.CloseMainWindow()
    if($entry.closeRequested){$entry.returned=$true;$script:desktopReturnPending=$true}
   }
  }catch{[void]$script:desktopClients.Remove($entry);try{$entry.process.Dispose()}catch{}}
 }
 if($script:desktopReturnPending -and -not $script:busy -and -not $script:ownerAccountsWorking -and $form -and -not $form.IsDisposed){
  $script:desktopReturnPending=$false
  # Closing a game window never stops the shared server (other windows or friends may be playing); say so and point to the stop controls.
  if($script:serverReady -and -not $script:remoteWorld -and $statusLine){$statusLine.Text=$(if($script:serverAdopted){'Game window closed. This server was already running and stays running; use Stop server to save and stop it.'}else{'Game window closed. Your server is still running; use Stop server, or close this window, to save and stop it.'})}
  if(Get-Command Show-ClientDashboardTab -ErrorAction SilentlyContinue){Show-ClientDashboardTab}
  if($form.WindowState -eq [Windows.Forms.FormWindowState]::Minimized){$form.WindowState=[Windows.Forms.FormWindowState]::Normal}
  $form.Show();$form.BringToFront();[void]$form.Activate()
 }
}
function Stop-DesktopClientReturn {
 if($script:desktopReturnTimer){$script:desktopReturnTimer.Stop();$script:desktopReturnTimer.Dispose();$script:desktopReturnTimer=$null}
 foreach($entry in @($script:desktopClients)){try{$entry.process.Dispose()}catch{}}
 $script:desktopClients=$null;$script:desktopReturnPending=$false
}
function Open-IsolatedGame([string]$Engine,[string]$Url) {
 $destination=[Uri]$Url
 if($destination.Scheme -notin @('http','https')){throw 'The game URL must use HTTP or HTTPS.'}
 $desktopUri=New-Object UriBuilder($destination);$query=(@($desktopUri.Query.TrimStart('?').Split('&')|Where-Object{$_ -and [Uri]::UnescapeDataString(($_ -split '=',2)[0]) -ine 'client'}) -join '&');$desktopUri.Query=$(if($query){$query+'&client=desktop'}else{'client=desktop'});$destination=$desktopUri.Uri
 $browser=Get-ClientBrowser
 $profileRoot=Get-DesktopClientProfileRoot $Engine;Assert-ClientPathUnlinked $profileRoot
 try{[void](Clear-StaleDesktopClientProfiles $Engine)}catch{}   # orphans of windows closed while no launcher watched them
 $profile=Join-Path $profileRoot ('client-'+[Guid]::NewGuid().ToString('N'))
 [void][IO.Directory]::CreateDirectory($profile)
 # Each window owns cookies/storage. Never reuse a personal browser profile.
 # 1280 x 720 centred by default, like Dekaron.exe; the page fits the game area to
 # exactly 1280 x 720 (or the resolution applied in Options) once it opens - src/ui/browser-fullscreen.js fitDesktopWindow
 $area=[Windows.Forms.Screen]::PrimaryScreen.WorkingArea;$w=[Math]::Min(1280,$area.Width);$h=[Math]::Min(720,$area.Height);$x=$area.X+[int](($area.Width-$w)/2);$y=$area.Y+[int](($area.Height-$h)/2)
 # Performance switches for a WebGL game on a high-refresh display (240 fps on a 239 Hz monitor). ENGINE-CHOSEN, checked
 # with a real headed Chrome: they keep the page's timers / rAF / audio from being throttled when
 # the window is behind another one (the in-game background-frame option, not the browser, then decides the rate), and let the GPU
 # path use the card on a driver the browser would otherwise blocklist. Vsync is NOT touched: rAF already runs at the monitor's
 # rate (239 Hz measured), and removing vsync would only tear. --use-angle is not set: D3D11 is already the default ANGLE backend.
 $perf=@('--ignore-gpu-blocklist','--enable-gpu-rasterization','--enable-zero-copy','--disable-renderer-backgrounding','--disable-background-timer-throttling','--disable-backgrounding-occluded-windows','--disable-features=CalculateNativeWinOcclusion')
 # Opt-in only: set the environment variable DEKARON_UNCAPPED_FPS=1 before opening the launcher to lift the browser's frame cap and
 # vsync (benchmarking; the picture will tear). Anything else, or unset, keeps vsync on.
 if($env:DEKARON_UNCAPPED_FPS -ceq '1'){$perf+=@('--disable-frame-rate-limit','--disable-gpu-vsync')}
 $arguments=@('--user-data-dir="'+$profile+'"','--app="'+$destination.AbsoluteUri+'"',"--window-size=$w,$h","--window-position=$x,$y",'--no-first-run','--no-default-browser-check')+$perf -join ' '
 $ownedBrowser=Start-Process -FilePath $browser -ArgumentList $arguments -PassThru -ErrorAction Stop
 if($ownedBrowser){Register-DesktopClientProcess $ownedBrowser $profile}
}
# Dekaron.exe, the native DX11 client window (tools/DKClient.cs). Same signed-in launch URL as the Desktop App, plus
# shell=native (loading screen, then the login hall with its server button). Its profile is kept per account under
# runtime\native-profiles (the GPU shader cache survives, so later starts compile less); Dekaron.exe never opens without a ticket.
function Open-NativeGame([string]$Engine,[string]$Url,[string]$Account,[bool]$Borderless=$false) {
 $destination=[Uri]$Url
 if($destination.Scheme -notin @('http','https')){throw 'The game URL must use HTTP or HTTPS.'}
 $exe=Join-Path $Engine 'GameWindow.exe';Assert-ClientPathUnlinked $exe
 if(-not (Test-Path -LiteralPath $exe -PathType Leaf)){throw 'GameWindow.exe is missing from the dedicated engine folder. Restore the complete dedicated build.'}
 $uri=New-Object UriBuilder($destination);$query=(@($uri.Query.TrimStart('?').Split('&')|Where-Object{$_ -and [Uri]::UnescapeDataString(($_ -split '=',2)[0]) -notin @('client','shell')}) -join '&');$uri.Query=$(if($query){$query+'&client=desktop&shell=native'}else{'client=desktop&shell=native'})
 $profile=([string]$Account).ToLowerInvariant();if($profile -notmatch '^[a-z0-9_-]{1,32}$'){$profile='player'}
 $process=Start-Process -FilePath $exe -ArgumentList @('--url',('"'+$uri.Uri.AbsoluteUri+'"'),'--profile',$profile,$(if($Borderless){'--borderless'}else{'--windowed'})) -WorkingDirectory $Engine -PassThru -ErrorAction Stop
 if($process){Register-DesktopClientProcess $process ''}
}
function Invoke-OwnedRelayCommand($Value,[int]$Timeout=240) {
 if(-not $script:relayProcess -or $script:relayProcess.HasExited){throw 'The owned relay is not running.'}
 $Value.id=[Guid]::NewGuid().ToString('N');$script:relayProcess.StandardInput.WriteLine(($Value|ConvertTo-Json -Depth 8 -Compress));$script:relayProcess.StandardInput.Flush()
 $task=$script:relayProcess.StandardOutput.ReadLineAsync();$watch=[Diagnostics.Stopwatch]::StartNew()
 while(-not $task.IsCompleted){if($watch.Elapsed.TotalSeconds -ge $Timeout){throw 'Relay readiness timed out.'};[Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(25)}
 $line=$task.Result;if(-not $line){throw 'The relay helper closed before confirmation.'};$reply=$line|ConvertFrom-Json
 if($reply.id -cne $Value.id -or -not $reply.ok){throw 'The relay could not be verified. Check the managed hostname and token file.'};return $reply
}
function Start-OwnedClientRelay([string]$Engine,[string]$Node,$Plan,[string]$Url) {
 if(-not $script:relayConfig){return}
 $helper=Join-Path $Engine 'tools\client-relay.mjs';Assert-ClientPathUnlinked $helper
 $info=New-Object Diagnostics.ProcessStartInfo;$info.FileName=$Node;$info.Arguments='"'+$helper+'"';$info.WorkingDirectory=$Engine;$info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.RedirectStandardInput=$true;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
 $script:relayProcess=New-Object Diagnostics.Process;$script:relayProcess.StartInfo=$info;[void]$script:relayProcess.Start();$script:relayErrors=$script:relayProcess.StandardError.ReadToEndAsync()
 try{
  $config=$script:relayConfig.Clone();$config.Remove('publish');$config.Remove('directory');$config.backend=Get-ClientApiUrl $Url;$config.engineId=$Plan.engineId;$config.pid=[int]$script:control.pid;$config.gatewayPort=7840
  $statusLine.Text='Starting your private online relay...';$reply=Invoke-OwnedRelayCommand @{command='start';config=$config}
  if($reply.state -cne 'online' -or $reply.publicOrigin -cne $script:relayConfig.publicOrigin){throw 'Managed relay readiness did not match your selected hostname.'}
  $script:gameServerUrl=$reply.publicOrigin+'/';Save-ClientHostPreferences @{version=1;kind='local';mode=$script:friendsConfig.mode;relay=@{publicOrigin=$script:relayConfig.publicOrigin;tokenFile=$script:relayConfig.tokenFile;publish=$script:relayConfig.publish;directory=$script:relayConfig.directory}};$statusLine.Text='Online relay ready. Sign in to your world.'
  if($script:relayConfig.publish){Enable-OwnedPublicListing $Engine $Node $Plan $Url}
 }catch{Stop-OwnedClientRelay;throw}
}
function Enable-OwnedPublicListing([string]$Engine,[string]$Node,$Plan,[string]$Url) {
 $control=Get-LauncherControl $Engine $Plan $Url
 # A reply can fail after opt-in commits; cleanup owns the request before registration succeeds.
 $script:publicationRequested=$true
 $response=Invoke-WebRequest -UseBasicParsing -Uri ((Get-ClientApiUrl $Url)+'api/launcher/publication') -Method Post -Headers @{'x-dekaron-launcher-token'=$control.token} -ContentType 'application/json' -Body ([Text.Encoding]::UTF8.GetBytes((@{enabled=$true;url=$script:gameServerUrl}|ConvertTo-Json -Compress))) -MaximumRedirection 0 -TimeoutSec 10 -ErrorAction Stop
 if([int]$response.StatusCode -ne 200){throw 'Publication approval did not respond directly.'};$approval=$response.Content|ConvertFrom-Json
 if(-not $approval.enabled -or $approval.publicationSecret -notmatch '^[a-f0-9]{64}$'){throw 'Publication proof was not verified.'}
 $helper=Join-Path $Engine 'tools\publish-server.mjs';Assert-ClientPathUnlinked $helper
 $info=New-Object Diagnostics.ProcessStartInfo;$info.FileName=$Node;$info.Arguments='"'+$helper+'"';$info.WorkingDirectory=$Engine;$info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.RedirectStandardInput=$true;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
 $info.Arguments+=' --watch';$script:publisherProcess=New-Object Diagnostics.Process;$script:publisherProcess.StartInfo=$info
 try{
  [void]$script:publisherProcess.Start();$script:publisherProcess.StandardInput.WriteLine((@{directory=$script:relayConfig.directory;url=$script:gameServerUrl;publicationSecret=$approval.publicationSecret}|ConvertTo-Json -Compress));$script:publisherProcess.StandardInput.Flush();$script:publisherErrors=$script:publisherProcess.StandardError.ReadToEndAsync();$output=$script:publisherProcess.StandardOutput.ReadLineAsync();$watch=[Diagnostics.Stopwatch]::StartNew()
  while(-not $output.IsCompleted){if($watch.Elapsed.TotalSeconds -gt 15){throw 'Directory publication timed out.'};[Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(25)}
  if(-not (($output.Result|ConvertFrom-Json).registered)){throw 'The directory did not accept your server.'};$script:publicListing=$true
 }catch{if($script:publisherProcess){$script:publisherProcess.StandardInput.Close();if(-not $script:publisherProcess.WaitForExit(12000)){$script:publisherProcess.Kill()};$script:publisherProcess.Dispose();$script:publisherProcess=$null};throw}
}
function Stop-OwnedClientRelay {
 if($script:publicationRequested -or $script:publicListing){$script:publicationRequested=$true;try{$control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl;$withdrawal=Invoke-RestMethod -Uri ((Get-ClientApiUrl $script:serverUrl)+'api/launcher/publication') -Method Post -Headers @{'x-dekaron-launcher-token'=$control.token} -ContentType 'application/json' -Body '{"enabled":false}' -MaximumRedirection 0 -TimeoutSec 5;if($withdrawal.enabled -is [bool] -and -not $withdrawal.enabled){$script:publicationRequested=$false}}catch{};$script:publicListing=$false}
 if($script:publisherProcess){try{$script:publisherProcess.StandardInput.Close();if(-not $script:publisherProcess.WaitForExit(12000)){$script:publisherProcess.Kill()}}finally{$script:publisherProcess.Dispose();$script:publisherProcess=$null}}
 if($script:relayProcess){try{if(-not $script:relayProcess.HasExited){[void](Invoke-OwnedRelayCommand @{command='stop'} 10);$script:relayProcess.StandardInput.Close();if(-not $script:relayProcess.WaitForExit(5000)){$script:relayProcess.Kill()}}}finally{$script:relayProcess.Dispose();$script:relayProcess=$null}}
 $script:gameServerUrl=$null
}
function Restart-StaleOwnedClientServer([string]$Engine,$Plan,[string]$Url,$Observed) {
 if($Observed.app -cne 'dekaron-engine' -or $Observed.engineId -cne $Plan.engineId -or [int]$Observed.pid -le 0 -or -not $Observed.version){throw 'A different or unverifiable process is using this address. No process was stopped.'}
 $oldPlan=[pscustomobject]@{engineId=$Plan.engineId;version=$Observed.version;runtimeVersion=$Observed.runtimeVersion}
 $control=Get-LauncherControl $Engine $oldPlan $Url
 if([int]$control.pid -ne [int]$Observed.pid){throw 'The old server changed before it could be verified. No process was stopped.'}
 $statusLine.Text='Saving your characters and updating the owned server...';[Windows.Forms.Application]::DoEvents()
 Stop-LauncherServer $Engine $oldPlan $Url
 $deadline=[DateTime]::UtcNow.AddSeconds(10)
 do{
  $status=Get-ClientServerStatus $Url
  if(-not $status){return}
  if($status.engineId -cne $Plan.engineId -or [int]$status.pid -ne [int]$Observed.pid){throw 'Another process took this address after shutdown. It was not stopped.'}
  [Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(100)
 }while([DateTime]::UtcNow -lt $deadline)
 throw 'The owned server saved but has not released its address yet. Try Start again; no process was killed.'
}

function Save-ClientBotLanguage {
 if(-not $script:settingsLoaded -or $script:busy -or $script:ownerAccountsWorking -or -not (Test-ClientEditableSettingsContext) -or -not $script:settingsNpc.Checked -or $script:settingsLanguage.SelectedIndex -lt 0){return}
 $wanted=$script:botLanguageCodes[$script:settingsLanguage.SelectedIndex];if($wanted -ceq $script:savedLanguage){return}
 $script:busy=$true;Update-ClientSettingsAvailability
 try{$saved=Invoke-ClientSettingsRequest 'POST' @{npcLanguage=$wanted};$actual=$(if($saved.npcLanguage){[string]$saved.npcLanguage}else{'en'});if($actual -cne $wanted){throw 'Bot language save was not confirmed.'};$script:savedLanguage=$actual;$script:settingsResult.Text='Bot chat language saved. Common replies use this language; other replies stay in English.'}catch{$script:settingsLanguage.SelectedIndex=[Array]::IndexOf($script:botLanguageCodes,$script:savedLanguage);$script:settingsResult.Text=$_.Exception.Message}finally{$script:busy=$false;Update-ClientSettingsAvailability}
}

# Multiple accounts on the same host are allowed; switching hosts requires stopping owned hosting first.
function Assert-ClientServerSwitch([string]$Url) {
 if(-not $script:serverReady -or $script:remoteWorld){return}
 $target=$null;try{$target=([Uri]$Url).GetLeftPart([UriPartial]::Authority)}catch{throw 'Choose a valid game server address.'}
 foreach($sameHost in @($script:serverUrl,$script:gameServerUrl)){if($sameHost){try{if($target -ieq ([Uri]$sameHost).GetLeftPart([UriPartial]::Authority)){return}}catch{}}}
 throw 'Stop all hosted servers before connecting to another server.'
}
