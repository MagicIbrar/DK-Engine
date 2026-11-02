param([string]$PreviewPath='', [ValidateSet('home','signup','loading','dashboard','host','connect','auth','openhost','extra','sql','options')][string]$PreviewMode='home', [switch]$Resume, [switch]$Setup, [switch]$Dedicated)
# One client window: displayed exact deletion plan, one explicit Install & Play action.
$ErrorActionPreference='Stop'
$OutputEncoding=New-Object Text.UTF8Encoding($false)
[Console]::OutputEncoding=$OutputEncoding
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
[Windows.Forms.Application]::EnableVisualStyles()
$clientEngine=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$script:dedicatedMode=[bool]$Dedicated
if($script:dedicatedMode){[Environment]::SetEnvironmentVariable('PORT','7996','Process')}
$script:npcSandbox=$null
$sandboxConfigPath=Join-Path $clientEngine 'server\npc-sandbox.json'
if(Test-Path -LiteralPath $sandboxConfigPath){
 $script:npcSandbox=Get-Content -LiteralPath $sandboxConfigPath -Raw|ConvertFrom-Json
 if($script:npcSandbox.version -ne 1 -or [IO.Path]::GetFullPath($script:npcSandbox.engine) -ine $clientEngine -or [int]$script:npcSandbox.port -lt 1024 -or [int]$script:npcSandbox.port -gt 65535){throw 'Invalid copied-client configuration.'}
 [Environment]::SetEnvironmentVariable('PORT',[string]$script:npcSandbox.port,'Process')
 [Environment]::SetEnvironmentVariable('DEKARON_DATA',[string]$script:npcSandbox.readOnlyData,'Process')
}
. (Join-Path $PSScriptRoot 'client-location.ps1')
. (Join-Path $PSScriptRoot 'client-dashboard.ps1')
. (Join-Path $PSScriptRoot 'client-prestart-settings.ps1')
. (Join-Path $PSScriptRoot 'client-capacity-panel.ps1')
. (Join-Path $PSScriptRoot 'client-friends.ps1')
. (Join-Path $PSScriptRoot 'client-qr.ps1')
. (Join-Path $PSScriptRoot 'client-auth.ps1')
. (Join-Path $PSScriptRoot 'client-owner-accounts.ps1')
. (Join-Path $PSScriptRoot 'client-port.ps1')
. (Join-Path $PSScriptRoot 'client-hosting-setup.ps1')
. (Join-Path $PSScriptRoot 'client-dedicated-sql.ps1')
. (Join-Path $PSScriptRoot 'client-asset-warm.ps1')
. (Join-Path $PSScriptRoot 'client-release-update.ps1')
if($script:dedicatedMode){Initialize-DedicatedSqlConfiguration}
$script:requestedLocalPort=[Environment]::GetEnvironmentVariable('PORT','Process')
Add-Type -Path (Join-Path $PSScriptRoot 'LauncherVisuals.cs') -ReferencedAssemblies System.Windows.Forms,System.Drawing
$script:selectedGameRoot=$null
if(-not $PreviewPath -and -not $script:dedicatedMode){
 $detected=@(Find-ClientFolders $clientEngine)
 if($detected.Count -eq 1){$script:selectedGameRoot=$detected[0]}
}
$clientNode=$null
$startupError=$null
if(-not $PreviewPath){
 $runtimeScript=Join-Path $PSScriptRoot 'client-runtime.ps1'
 try {
  if(-not (Test-Path -LiteralPath $runtimeScript)){throw 'The runtime helper is missing. Restore the complete engine release.'}
  . $runtimeScript; $clientNode=Get-ClientNode -Engine $clientEngine
 } catch {$startupError=$_.Exception.Message;$clientNode=$null}
}
$gold=[Drawing.Color]::FromArgb(214,177,115)
$ink=[Drawing.Color]::FromArgb(13,16,23)
$muted=[Drawing.Color]::FromArgb(210,218,230) # ENGINE-CHOSEN: readable secondary text over launcher art.
$form=New-Object LauncherWindow
$form.AnimatePanels=-not [bool]$PreviewPath
[LauncherIdentity]::Apply($form,$clientEngine)
$form.Text='DK Client'; $form.ClientSize=New-Object Drawing.Size(1000,680); $form.MinimumSize=$form.Size; $form.MaximizeBox=$false
$form.StartPosition='CenterScreen'; $form.BackColor=$ink; $form.ForeColor=[Drawing.Color]::FromArgb(235,229,217); $form.Font=New-Object Drawing.Font('Segoe UI',10)
$script:ownedLauncherArt=$null; $artStream=$null; $sourceArt=$null
try {
 $artPath=Join-Path $clientEngine 'client-assets\launcher-background-v1.png'
 if(Test-Path -LiteralPath $artPath -PathType Leaf){$artStream=[IO.File]::OpenRead($artPath);$sourceArt=[Drawing.Image]::FromStream($artStream);$script:ownedLauncherArt=$sourceArt.Clone()}
} catch {$script:ownedLauncherArt=$null} finally {if($sourceArt){$sourceArt.Dispose()};if($artStream){$artStream.Dispose()}}
$form.Artwork=$script:ownedLauncherArt

function New-ClientLabel([string]$text,[int]$x,[int]$y,[int]$w,[int]$h,[int]$size=10) {
 $label=New-Object Windows.Forms.Label; $label.Text=$text; $label.UseMnemonic=$false; $label.Location=New-Object Drawing.Point($x,$y); $label.Size=New-Object Drawing.Size($w,$h); $label.BackColor=[Drawing.Color]::Transparent; $label.Font=New-Object Drawing.Font('Segoe UI',$size); $form.Controls.Add($label); return $label
}
$title=New-ClientLabel '' 40 31 620 48 29; $title.Font=New-Object Drawing.Font('Segoe UI',29,[Drawing.FontStyle]::Bold); $title.ForeColor=$gold
$subtitle=New-ClientLabel '' 44 82 580 24 9; $subtitle.ForeColor=$muted
$clientLogo=New-Object Windows.Forms.PictureBox
$clientLogo.Location=New-Object Drawing.Point(30,12); $clientLogo.Size=New-Object Drawing.Size(620,98); $clientLogo.SizeMode='Zoom'; $clientLogo.Visible=$false; $clientLogo.BackColor=[Drawing.Color]::Transparent; $form.Controls.Add($clientLogo)
$script:ownedClientLogo=$null; $logoStream=$null; $sourceLogo=$null
try {
 $logoPath=Join-Path $clientEngine 'client-assets\dk-engine-logo-v1.png'
 if(Test-Path -LiteralPath $logoPath -PathType Leaf){
  $logoStream=[IO.File]::OpenRead($logoPath); $sourceLogo=[Drawing.Image]::FromStream($logoStream)
  $script:ownedClientLogo=$sourceLogo.Clone(); $clientLogo.Image=$script:ownedClientLogo
  $clientLogo.Visible=$false; $title.Visible=$false; $subtitle.Visible=$false
 }
} catch {
 if($script:ownedClientLogo){$script:ownedClientLogo.Dispose();$script:ownedClientLogo=$null}
 $clientLogo.Image=$null;$clientLogo.Visible=$false;$title.Visible=$false; $subtitle.Visible=$false
} finally {if($sourceLogo){$sourceLogo.Dispose()};if($logoStream){$logoStream.Dispose()}}
$serverStatus=New-ClientLabel '' 690 37 270 22 9; $serverStatus.Visible=$false
$website=New-Object RoundedLauncherButton
$website.Text='Sign up';$website.Location=New-Object Drawing.Point(818,45);$website.Size=New-Object Drawing.Size(140,36);$website.FlatStyle='Flat';$website.ForeColor=$gold;$website.BackColor=$ink;$form.Controls.Add($website)
$openLogin=New-Object Windows.Forms.LinkLabel
$openLogin.Text='Open login';$openLogin.Location=New-Object Drawing.Point(690,76);$openLogin.Size=New-Object Drawing.Size(115,24);$openLogin.LinkColor=$gold;$openLogin.BackColor=$ink;$openLogin.Enabled=$false;$openLogin.Visible=$false;$form.Controls.Add($openLogin)
$openLogin.Add_LinkClicked({if($script:serverReady){try{Show-NativeAuthPanel $(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl}) $script:runningFriends}catch{Write-ClientLog $_.Exception.Message}}})
$heroKicker=New-ClientLabel '' 90 180 820 23 9; $heroKicker.ForeColor=$gold;$heroKicker.TextAlign='MiddleCenter'
$hero=New-ClientLabel '' 50 220 900 56 32; $hero.Font=New-Object Drawing.Font('Segoe UI',28,[Drawing.FontStyle]::Bold);$hero.TextAlign='MiddleCenter'
$heroCopy=New-ClientLabel '' 90 287 820 38 12; $heroCopy.ForeColor=$muted;$heroCopy.TextAlign='MiddleCenter'
$folderHeading=New-ClientLabel 'DETECTED INSTALLATION' 54 305 540 22 9; $folderHeading.ForeColor=$gold
$chooseFolder=New-Object RoundedLauncherButton
$chooseFolder.Text='Setup help';$chooseFolder.Location=New-Object Drawing.Point(665,45);$chooseFolder.Size=New-Object Drawing.Size(134,36);$chooseFolder.FlatStyle='Flat';$chooseFolder.BackColor=$ink;$chooseFolder.ForeColor=$muted;$form.Controls.Add($chooseFolder)
$chooseFolder.Add_Click({
 if($script:busy){return}
 if($script:dedicatedMode){
  $help=@'
NEW USERS
1. Download Global legally, update it fully, and keep a separate backup.
2. Put the complete Engine folder beside Global's bin and data folders.
3. Open Engine\Client.exe. Setup checks and prepares the required files.
4. In Options, choose your world settings. SQL / VPS lets you choose local files, SQL on this PC, or your remote SQL server.
5. Click the green Launch button. On the dashboard, choose your game client and sign in.

EXISTING USERS / UPDATING
1. Close your game windows and use Stop server to save your world.
2. Keep a backup of your installation and database.
3. Replace the engine package files with the complete new release. Keep your existing saves, server settings, and prepared Global folder.
4. Open Client.exe. The updater preserves your world and saved settings; changed Global files are prepared when needed.
5. Review your saved Options, click green Launch, then open the game.

SQL / VPS
SQL is optional. Automatic SQL installation is for this Windows PC. For remote SQL, enter its host or instance in Options > SQL / VPS, then Check SQL. Your Windows account needs access to that database. Players connect to your game server address, not directly to SQL.

Keep the whole Engine package together; copying Client.exe alone is not an update. Setup-DK.cmd rechecks dependencies. Hosting options manages invitations and public/private server listings.
'@
  [void][Windows.Forms.MessageBox]::Show($form,$help,'Setup help - New and existing users','OK','Information');return
 }
 [void][Windows.Forms.MessageBox]::Show($form,'Place the complete engine folder inside your updated Dekaron folder, beside data and bin. Then open engine\Client.exe. After installation, use DK Engine on your desktop or DK-Engine-Client.exe in the game folder.','DK Setup','OK','Information')
})
$details=New-Object GalaxyTextBox
$details.Multiline=$true;$details.ReadOnly=$true;$details.ScrollBars='Vertical';$details.BorderStyle='None';$details.BackColor=[Drawing.Color]::FromArgb(18,22,30);$details.ForeColor=$form.ForeColor;$details.Location=New-Object Drawing.Point(54,335);$details.Size=New-Object Drawing.Size(552,105);$details.Font=New-Object Drawing.Font('Consolas',9);$form.Controls.Add($details)
$cleanupNotice=New-ClientLabel 'Existing Global files are kept. A separate DK Engine launcher will be created.' 54 450 550 35 9; $cleanupNotice.ForeColor=[Drawing.Color]::FromArgb(235,145,133)
$phaseLabels=@();$phaseNames=$(if($script:dedicatedMode){@('Verify copy','Dependencies','Prepared data','Start world','Ready')}else{@('Verify folder','Dependencies','Import client','Clean files','Ready')})
for($i=0;$i -lt 5;$i++){$label=New-ClientLabel $phaseNames[$i] (40+$i*119) 510 118 23 9;$label.ForeColor=$muted;$phaseLabels+=,$label}
$progress=New-Object GalaxyProgress
$progress.Location=New-Object Drawing.Point(80,375);$progress.Size=New-Object Drawing.Size(840,98);$progress.Value=0;$progress.Visible=$true;$form.Controls.Add($progress)
$primary=New-Object RoundedLauncherButton
$primary.Text='Start';$primary.UseMnemonic=$false;$primary.Location=New-Object Drawing.Point(300,502);$primary.Size=New-Object Drawing.Size(400,56);$primary.FlatStyle='Flat';$primary.BackColor=$gold;$primary.ForeColor=$ink;$primary.Font=New-Object Drawing.Font('Segoe UI',18,[Drawing.FontStyle]::Bold);$form.Controls.Add($primary)
$script:fullScreenLaunch=New-Object RoundedLauncherButton;$script:fullScreenLaunch.Text='DX11 Fullscreen';$script:fullScreenLaunch.Bounds=New-Object Drawing.Rectangle(508,502,192,56);$script:fullScreenLaunch.Font=New-Object Drawing.Font('Segoe UI',14,[Drawing.FontStyle]::Bold);$script:fullScreenLaunch.ForeColor=$ink;$script:fullScreenLaunch.BackColor=$gold;$script:fullScreenLaunch.Visible=$false;$form.Controls.Add($script:fullScreenLaunch)
function Update-NativeLaunchButtons {
 $gameChoice=$primary.Text -like 'DX11*'
 if($gameChoice){$primary.Width=192;$primary.Font=$script:fullScreenLaunch.Font}else{$primary.Width=400}
 $script:fullScreenLaunch.Visible=$primary.Visible -and $gameChoice
 $script:fullScreenLaunch.Enabled=$primary.Enabled
}
$primary.Add_VisibleChanged({Update-NativeLaunchButtons});$primary.Add_TextChanged({Update-NativeLaunchButtons});$primary.Add_EnabledChanged({Update-NativeLaunchButtons})
$statusLine=New-ClientLabel 'Ready when you are.' 80 337 840 31 10; $statusLine.ForeColor=$gold;$statusLine.TextAlign='MiddleCenter'
$note=New-ClientLabel '' 128 613 160 26 11; $note.ForeColor=$gold
$footerCopy=New-ClientLabel '' 129 640 660 22 9;$footerCopy.ForeColor=$muted
$showDetails=New-Object Windows.Forms.LinkLabel
$showDetails.Text='Show details';$showDetails.LinkColor=$gold;$showDetails.Location=New-Object Drawing.Point(839,637);$showDetails.Size=New-Object Drawing.Size(120,24);$showDetails.BackColor=[Drawing.Color]::Transparent;$form.Controls.Add($showDetails)
$script:clientLogTextBox=New-Object GalaxyTextBox
$script:clientLogTextBox.Multiline=$true;$script:clientLogTextBox.ReadOnly=$true;$script:clientLogTextBox.ScrollBars='Vertical';$script:clientLogTextBox.BackColor=[Drawing.Color]::FromArgb(18,22,30);$script:clientLogTextBox.ForeColor=$muted;$script:clientLogTextBox.Location=New-Object Drawing.Point(40,695);$script:clientLogTextBox.Size=New-Object Drawing.Size(920,165);$script:clientLogTextBox.Visible=$false;$form.Controls.Add($script:clientLogTextBox)
# Write-ClientLog reaches the box through this uniquely named global (see there); nothing else may reuse the name.
$global:DekaronLauncherLogBox=$script:clientLogTextBox
$showDetails.Add_LinkClicked({Show-ClientFailureDetails})
$signupPanel=New-Object GalaxyPanel
$signupPanel.Location=New-Object Drawing.Point(669,160);$signupPanel.Size=New-Object Drawing.Size(272,416);$signupPanel.BackColor=[Drawing.Color]::FromArgb(18,22,30);$form.Controls.Add($signupPanel)
$signupTitle=New-Object Windows.Forms.Label;$signupTitle.Text='Create your account';$signupTitle.ForeColor=$gold;$signupTitle.Font=New-Object Drawing.Font('Segoe UI',14,[Drawing.FontStyle]::Bold);$signupTitle.Size=New-Object Drawing.Size(272,30);$signupPanel.Controls.Add($signupTitle)
$signupIntro=New-Object Windows.Forms.Label;$signupIntro.Text='Create your local account.';$signupIntro.ForeColor=$muted;$signupIntro.Location=New-Object Drawing.Point(0,37);$signupIntro.Size=New-Object Drawing.Size(200,25);$signupIntro.Font=New-Object Drawing.Font('Segoe UI',9);$signupPanel.Controls.Add($signupIntro)
$accountId=New-Object GalaxyTextBox;$accountPassword=New-Object GalaxyTextBox;$confirmPassword=New-Object GalaxyTextBox
$accountPassword.UseSystemPasswordChar=$true;$confirmPassword.UseSystemPasswordChar=$true
$accountId.MaxLength=32;$accountPassword.MaxLength=128;$confirmPassword.MaxLength=128
$fields=@(@('Account ID',$accountId),@('Password',$accountPassword),@('Confirm password',$confirmPassword))
for($i=0;$i -lt 3;$i++){
 $label=New-Object Windows.Forms.Label;$label.Text=$fields[$i][0];$label.ForeColor=$muted;$label.Location=New-Object Drawing.Point(0,(74+$i*65));$label.Size=New-Object Drawing.Size(272,21);$signupPanel.Controls.Add($label)
 $field=$fields[$i][1];$field.Location=New-Object Drawing.Point(0,(97+$i*65));$field.Size=New-Object Drawing.Size(272,28);$field.BackColor=[Drawing.Color]::FromArgb(30,35,44);$field.ForeColor=$form.ForeColor;$field.BorderStyle='FixedSingle';$signupPanel.Controls.Add($field)
}
$signupHint=New-Object Windows.Forms.Label;$signupHint.Text='ID: 3-32 letters, numbers, _ or -.`r`nPassword: 6-128 characters.'.Replace('`r`n',"`r`n");$signupHint.ForeColor=$muted;$signupHint.Location=New-Object Drawing.Point(0,269);$signupHint.Size=New-Object Drawing.Size(272,38);$signupHint.Font=New-Object Drawing.Font('Segoe UI',8);$signupPanel.Controls.Add($signupHint)
$signupSubmit=New-Object RoundedLauncherButton
$signupSubmit.Text='Create account';$signupSubmit.Location=New-Object Drawing.Point(0,314);$signupSubmit.Size=New-Object Drawing.Size(272,38);$signupSubmit.FlatStyle='Flat';$signupSubmit.BackColor=[Drawing.Color]::FromArgb(116,45,47);$signupSubmit.ForeColor=$form.ForeColor;$signupPanel.Controls.Add($signupSubmit)
$signupBack=New-Object RoundedLauncherButton
$signupBack.Text='Clear';$signupBack.Location=New-Object Drawing.Point(205,37);$signupBack.Size=New-Object Drawing.Size(67,25);$signupBack.FlatStyle='Flat';$signupBack.ForeColor=$muted;$signupPanel.Controls.Add($signupBack)
$signupResult=New-Object Windows.Forms.Label;$signupResult.UseMnemonic=$false;$signupResult.Location=New-Object Drawing.Point(0,365);$signupResult.Size=New-Object Drawing.Size(272,50);$signupResult.ForeColor=$gold;$signupResult.Font=New-Object Drawing.Font('Segoe UI',9);$signupPanel.Controls.Add($signupResult)
foreach($control in @($folderHeading,$details,$cleanupNotice,$showDetails)+$phaseLabels){$control.Visible=$false}
$signupPanel.Visible=$false;$signupPanel.Location=New-Object Drawing.Point(350,150);$signupPanel.Size=New-Object Drawing.Size(300,418);$signupPanel.Padding=New-Object Windows.Forms.Padding(14)
$signupPanel.BringToFront()
$appEmblem=New-Object Windows.Forms.PictureBox;$appEmblem.Location=New-Object Drawing.Point(40,592);$appEmblem.Size=New-Object Drawing.Size(80,80);$appEmblem.SizeMode='Zoom';$appEmblem.BackColor=[Drawing.Color]::Transparent;$form.Controls.Add($appEmblem)
$script:ownedEmblem=$null
try{$emblemSource=[Drawing.Image]::FromFile((Join-Path $clientEngine 'client-assets\dk-engine-emblem-v1.png'));try{$script:ownedEmblem=$emblemSource.Clone();$appEmblem.Image=$script:ownedEmblem}finally{$emblemSource.Dispose()}}catch{}
$stopServer=New-Object RoundedLauncherButton;$stopServer.Text='Stop server';$stopServer.Location=New-Object Drawing.Point(818,616);$stopServer.Size=New-Object Drawing.Size(140,36);$stopServer.FlatStyle='Flat';$stopServer.BackColor=$ink;$stopServer.ForeColor=[Drawing.Color]::FromArgb(225,148,159);$stopServer.Visible=$false;$form.Controls.Add($stopServer)
$script:dashboard=$false;$script:prepareSteps=0
$builderTip=New-Object Windows.Forms.ToolTip
$itemBuilderButton=New-Object RoundedLauncherButton;$itemBuilderButton.Text='◆  Item Builder';$itemBuilderButton.Location=New-Object Drawing.Point(300,565);$itemBuilderButton.Size=New-Object Drawing.Size(192,34);$itemBuilderButton.Visible=$false;$itemBuilderButton.FlatStyle='Flat';$itemBuilderButton.BackColor=$ink;$itemBuilderButton.ForeColor=$muted;$form.Controls.Add($itemBuilderButton)
$mapBuilderButton=New-Object RoundedLauncherButton;$mapBuilderButton.Text='▦  Map Builder';$mapBuilderButton.Location=New-Object Drawing.Point(508,565);$mapBuilderButton.Size=New-Object Drawing.Size(192,34);$mapBuilderButton.Visible=$false;$mapBuilderButton.FlatStyle='Flat';$mapBuilderButton.BackColor=$ink;$mapBuilderButton.ForeColor=$muted;$form.Controls.Add($mapBuilderButton)
$builderTip.SetToolTip($itemBuilderButton,'Open Item Builder in the first account logged in after Start. GM permission required.')
$builderTip.SetToolTip($mapBuilderButton,'Open Map Builder in the primary account. Log back in with that account after logout.')
$itemBuilderButton.Add_Click({try{$statusLine.Text=Open-LauncherBuilder $clientEngine $script:runningPlan $script:serverUrl 'itembuilder'}catch{$statusLine.Text=$_.Exception.Message}})
$mapBuilderButton.Add_Click({try{$statusLine.Text=Open-LauncherBuilder $clientEngine $script:runningPlan $script:serverUrl 'mapbuilder'}catch{$statusLine.Text=$_.Exception.Message}})
Initialize-FriendsControls
Initialize-NativeAuthControls
Initialize-RemoteWorldControls
Initialize-OwnerAccountsControls
function Update-ClientDashboardView {
 if(-not $script:clientDashboardPanel -or $script:updatingClientDashboard){return}
 $script:updatingClientDashboard=$true
 try {
  $available=[bool]$script:dashboard
  $overlay=$false
  foreach($panel in @($signupPanel,$script:authPanel,$script:friendsPanel,$script:extraPanel,$script:ownerAccountsPanel,$script:dedicatedSqlPanel)){if($panel -and $panel.Visible){$overlay=$true}}
  if($overlay -and $script:settingsPanel.Visible){Close-ClientSettingsPanel $false}
  if($script:settingsPanel.Visible){$overlay=$true}
  foreach($tab in @($script:dashboardTab,$script:worldsTab,$script:hostingTab)){$tab.Visible=$false}
  $script:settingsTab.Enabled=-not $script:busy -and -not $script:ownerAccountsWorking
  # The top row stays in every state (see Initialize-ClientDashboardTabs); a remote world (another host's server) has no
  # local hosting, so the two hosting buttons are greyed there instead of disappearing.
  foreach($button in @($script:clientTopRow)){if($button){$button.Visible=$true}}
  foreach($button in @($script:hostButton,$script:connectButton,$script:hostingOptions)){if($button){$button.Enabled=-not $script:busy -and -not $script:ownerAccountsWorking}}
  if($script:remoteWorld){foreach($button in @($script:hostButton,$script:hostingOptions)){if($button){$button.Enabled=$false}}}
  if($script:hostTab){$script:hostTab.Visible=$false}
  $script:settingsTab.ForeColor=$(if($script:settingsPanel.Visible){$gold}else{$muted})
  Update-ClientSettingsAvailability
  $show=$available -and -not $overlay
  $script:clientDashboardPanel.Visible=$show
  $script:dashboardTab.ForeColor=$(if($show){$gold}else{$muted})
  $script:connectButton.ForeColor=$(if($script:friendsPanel.Visible -and $script:friendsMode -eq 'connect'){$gold}else{$muted})
  $script:hostingOptions.ForeColor=$(if($script:friendsPanel.Visible -and $script:friendsMode -eq 'host'){$gold}else{$muted})
  $script:hostButton.ForeColor=$(if($script:friendsPanel.Visible -and $script:friendsMode -eq 'invite'){$gold}else{$muted})
  if(-not $show){
   if(-not $available -and -not $script:busy -and -not $overlay){foreach($control in @($heroKicker,$hero,$heroCopy,$statusLine)){$control.Visible=$true}}
   return
  }
  foreach($control in @($heroKicker,$hero,$heroCopy,$statusLine)){$control.Visible=$false}
  $script:clientDashboardPanel.BringToFront()
  $url=$(if($script:remoteWorld){$script:gameServerUrl}else{$script:serverUrl})
  $state=$(if($url){$script:serverLive[[string]$url]})
  $name='Dekaron Online';if($script:remoteWorld -and $script:remoteMetadata.name){$name=[string]$script:remoteMetadata.name}elseif($state -and $state.name){$name=[string]$state.name}elseif(-not $script:remoteWorld -and $script:localServerNameUrl -ceq $script:serverUrl -and $script:localServerName){$name=$script:localServerName}
  $script:dashboardWorldName.Text=$name
  $script:dashboardWorldAddress.Text=[string]$url
  $script:dashboardModeValue.Text=$(if($script:remoteWorld){'Remote world'}elseif($script:runningFriends){'Hosted world'}else{'Local world'})
  Update-ClientPopulationTile $state
  $script:dashboardSummary.Text=$(if($statusLine.Text){$statusLine.Text}else{'Launch a client, choose a world, or manage your host.'})
  if($script:onlineLabel){$script:onlineLabel.Visible=$false}
 } finally {$script:updatingClientDashboard=$false}
}
function Show-ClientDashboardTab {
 if($script:busy -or $script:ownerAccountsWorking){return}
 Close-ClientSettingsPanel
 if($script:ownerAccountsPanel.Visible){Close-OwnerAccountsPanel}
 if($script:extraPanel.Visible){Close-ExtraClientPanel}
 if($script:authPanel.Visible){Close-NativeAuthPanel}
 if($script:friendsPanel.Visible){Show-FriendsPanel 'close'}
 if($signupPanel.Visible){Show-LauncherSignup $false}
 if($script:dashboard){
  $primary.Visible=$true;$script:browserLaunch.Visible=$true;$progress.Visible=$false
  $script:localWorld.Visible=[bool]$script:remoteWorld
  Set-LauncherBuilderVisibility ([bool]$script:builderReady)
  $form.AcceptButton=$primary
 }
 Update-ClientDashboardView
}
function Get-ClientTopRowCell([int]$FormWidth,[int]$Slot) {
 $w=140;$h=36;$gap=8;$right=$FormWidth-42
 return New-Object Drawing.Rectangle(($right-6*$w-5*$gap+$Slot*($w+$gap)),45,$w,$h)
}
function Initialize-ClientDashboardTabs {
 $script:updatingClientDashboard=$false
 $tabs=@()
 # ENGINE-CHOSEN layout: ONE row of six equal
 # buttons across the top, right-aligned to form width - 42, identical before and after loading:
 #   Setup help | Sign up | Settings | Host friends | Connect | Hosting options
 # After loading, Connect and Hosting options do what the retired Worlds / Hosting tabs did (Dashboard = the panels' Back).
 # The retired tab objects stay (hidden) because other scripts and tests still reference them.
 foreach($spec in @('Dashboard','Worlds','Hosting','Settings')){
  $tab=New-Object RoundedLauncherButton;$tab.Text=$spec;$tab.Bounds=New-Object Drawing.Rectangle(0,0,140,36);$tab.ForeColor=$muted;$tab.BackColor=$ink;$tab.Visible=$false;$form.Controls.Add($tab);$tabs+=,$tab
 }
 $script:dashboardTab=$tabs[0];$script:worldsTab=$tabs[1];$script:hostingTab=$tabs[2];$script:settingsTab=$tabs[3];$script:settingsTab.Visible=$true;$script:settingsTab.Text='Options'
 $script:clientTopRow=@($chooseFolder,$website,$script:settingsTab,$script:hostButton,$script:connectButton,$script:hostingOptions)
 for($i=0;$i -lt 6;$i++){$button=$script:clientTopRow[$i];$button.Bounds=Get-ClientTopRowCell $form.ClientSize.Width $i;$button.FlatStyle='Flat';$button.BackColor=$ink;$button.Font=$script:settingsTab.Font}
 foreach($button in @($script:hostButton,$script:connectButton,$script:hostingOptions)){$button.ForeColor=$muted}
 # Accounts (owner-only) is not one of the six: bottom right, above Stop server.
 if($script:ownerAccountsButton){$script:ownerAccountsButton.Bounds=New-Object Drawing.Rectangle(818,484,140,36)}
 if($script:extraClient){$script:extraClient.Bounds=New-Object Drawing.Rectangle(818,528,140,36)}
 if($script:localWorld){$script:localWorld.Bounds=New-Object Drawing.Rectangle(818,572,140,36)}
 if($script:hostTab){$script:hostTab.Visible=$false}
 $script:dashboardTab.Add_Click({Show-ClientDashboardTab})
 $script:settingsTab.Add_Click({Show-ClientSettingsPanel})
 $script:worldsTab.Add_Click({if(-not $script:busy -and -not $script:ownerAccountsWorking){Show-ClientDashboardTab;Show-FriendsPanel 'connect';Update-ClientDashboardView}})
 $script:hostingTab.Add_Click({if(-not $script:busy -and -not $script:ownerAccountsWorking){Show-ClientDashboardTab;Show-FriendsPanel $(if($script:serverReady -and $script:runningFriends){'invite'}else{'host'});Update-ClientDashboardView}})
 $script:clientDashboardPanel=New-Object GalaxyPanel;$script:clientDashboardPanel.Location=New-Object Drawing.Point(110,165);$script:clientDashboardPanel.Size=New-Object Drawing.Size(780,305);$script:clientDashboardPanel.Visible=$false;$form.Controls.Add($script:clientDashboardPanel)
 function Add-DashboardLabel($Parent,[string]$Text,[int]$X,[int]$Y,[int]$W,[int]$H,[int]$Size=10){
  $label=New-Object Windows.Forms.Label;$label.Text=$Text;$label.UseMnemonic=$false;$label.Location=New-Object Drawing.Point($X,$Y);$label.Size=New-Object Drawing.Size($W,$H);$label.ForeColor=$muted;$label.BackColor=[Drawing.Color]::Transparent;$label.Font=New-Object Drawing.Font('Segoe UI',[Math]::Max(10,$Size),$(if($Size -le 10){[Drawing.FontStyle]::Bold}else{[Drawing.FontStyle]::Regular}));$Parent.Controls.Add($label);return $label
 }
 $caption=Add-DashboardLabel $script:clientDashboardPanel 'WORLD DASHBOARD' 24 19 710 20 9;$caption.ForeColor=$gold
 $script:dashboardWorldName=Add-DashboardLabel $script:clientDashboardPanel 'Dekaron Online' 24 46 710 39 24
 $script:dashboardWorldName.ForeColor=$form.ForeColor
 $script:dashboardWorldAddress=Add-DashboardLabel $script:clientDashboardPanel '' 26 88 710 23 10
 $values=@()
 for($i=0;$i -lt 2;$i++){
  $tile=New-Object GalaxyPanel;$tile.Location=New-Object Drawing.Point((24+$i*366),128);$tile.Size=New-Object Drawing.Size(354,99);$script:clientDashboardPanel.Controls.Add($tile)
  [void](Add-DashboardLabel $tile @('WORLD','PLAYERS ONLINE')[$i] 16 14 323 20 9)
  $value=Add-DashboardLabel $tile 'Checking...' 16 44 323 34 19;$value.ForeColor=$gold;$values+=,$value
 }
 $script:dashboardModeValue=$values[0];$script:dashboardPlayersValue=$values[1]
 $script:dashboardSummary=Add-DashboardLabel $script:clientDashboardPanel '' 26 244 710 43 10
 foreach($panel in @($signupPanel,$script:authPanel,$script:friendsPanel,$script:extraPanel,$script:ownerAccountsPanel,$script:settingsPanel)){$panel.Add_VisibleChanged({Update-ClientDashboardView})}
 foreach($control in @($heroKicker,$hero,$heroCopy,$statusLine,$script:browserLaunch)){$control.Add_VisibleChanged({Update-ClientDashboardView})}
 $script:onlineLabel.Add_TextChanged({Update-ClientDashboardView});$statusLine.Add_TextChanged({Update-ClientDashboardView})
 $script:serverLiveTimer.Add_Tick({Update-ClientDashboardView})
}
Initialize-ClientSettingsControls
Initialize-ClientDashboardTabs
Initialize-DedicatedSqlPage
Initialize-DesktopClientReturn
function Show-LauncherSignup([bool]$show) {
 if($script:friendsPanel){$script:friendsPanel.Visible=$false;$script:ratesPanel.Visible=$false;$script:hostButton.Visible=$true;$script:connectButton.Visible=$true}   # top row stays
 Set-LauncherBuilderVisibility ([bool]$script:builderReady -and -not $show)
 $signupPanel.Visible=$show;$website.Text=if($show){'Back'}else{'Sign up'}
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$statusLine)){$control.Visible=-not $show}
 $progress.Visible=-not $show -and -not $script:cachedReady -and -not $script:dashboard -and -not $script:serverReady
 if($show){$signupPanel.BringToFront();[void]$accountId.Focus()}
}
function Set-LauncherProgress([int]$value,[string]$message='') {
 $progress.Value=[Math]::Max($progress.Value,[Math]::Min(100,$value))
 if($script:closeRequested){$statusLine.Text='Close requested. Finishing the current operation safely...'}elseif($message){$statusLine.Text=$message}
 $progress.AccessibleDescription=($progress.Value.ToString()+' percent complete')
}
function Show-ServerDashboard {
 # A completed start always leaves a usable launch dashboard, regardless of which setup panel started it.
 Close-ClientSettingsPanel $false
 foreach($panel in @($signupPanel,$script:friendsPanel,$script:ratesPanel,$script:authPanel,$script:extraPanel,$script:ownerAccountsPanel,$script:dedicatedSqlPanel)){if($panel){$panel.Visible=$false}}
 $primary.Visible=$true;$script:localWorld.Visible=$false;$form.AcceptButton=$primary
 $script:prestartPending=$false;Update-ClientSettingsContinue
 if($script:hostButton){$script:hostButton.Visible=$true;$script:connectButton.Visible=$true;$script:hostTab.Visible=$false}   # top row stays after loading
 $itemBuilderButton.Top=605;$mapBuilderButton.Top=605;Set-LauncherBuilderVisibility $false
 $script:hostingOptions.Visible=$true;$script:remoteWorld=$false;$script:browserLaunch.Visible=$true;$script:dashboard=$true;$heroKicker.Text='SERVER DASHBOARD';$hero.Text='Your world is live.'
 $heroCopy.Text='Open a window for each player. Use a different account in every window.'
 $primary.Text='DX11 Client';$stopServer.Visible=$true;$chooseFolder.Visible=$true
 $footerCopy.Text=$(if($script:serverAdopted){'This server was already running. Closing this dashboard leaves it running; use Stop server to save and stop it.'}else{'Closing this dashboard saves your characters and stops the server.'})
 $progress.DetailText='';Set-LauncherProgress 100 'Ready to play.';$progress.Visible=$false
 Start-LauncherBuilderStatus
 if($script:clientDashboardPanel){Update-ClientDashboardView}
}
function Stop-ClientDashboard {
 if(-not $script:serverReady){return $true}
 $statusLine.Text='Saving characters and stopping...';$script:busy=$true;[Windows.Forms.Application]::DoEvents()
 try{$shutdown=Stop-LauncherServer $clientEngine $script:runningPlan $script:serverUrl $script:control;Stop-OwnedClientRelay
  # The server answers "saved" first and exits a moment later; wait (bounded, never killing) so Stopped really means no server process remains.
  if(-not $shutdown.alreadyStopped -and $script:control -and [int]$script:control.pid -gt 0){$exitDeadline=[DateTime]::UtcNow.AddSeconds(8);do{$stopTarget=$null;try{$stopTarget=[Diagnostics.Process]::GetProcessById([int]$script:control.pid);if($stopTarget.HasExited){$stopTarget=$null}}catch{$stopTarget=$null};if($stopTarget){$stopTarget.Dispose();[Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(50)}}while($stopTarget -and [DateTime]::UtcNow -lt $exitDeadline)}
  Stop-LauncherBuilderStatus;$script:serverReady=$false;$script:serverAdopted=$false;$script:dashboard=$false;$script:runningFriends=$false;$script:hostTab.Visible=$false;$script:hostButton.Visible=$true;$script:connectButton.Visible=$true;$stopServer.Visible=$false;$itemBuilderButton.Visible=$false;$mapBuilderButton.Visible=$false;$script:hostingOptions.Visible=$true;$script:browserLaunch.Visible=$false;$primary.Text='Start';$heroKicker.Text='';$hero.Text='Your world is resting.';$heroCopy.Text='Start whenever you are ready to return.';$statusLine.Text=$(if($shutdown.alreadyStopped){'Server already stopped.'}else{'Progress saved. Server stopped.'});$chooseFolder.Visible=$true;$progress.Value=0;$footerCopy.Text='';return $true}
 catch{$statusLine.Text=$_.Exception.Message;[void][Windows.Forms.MessageBox]::Show($form,$_.Exception.Message,'Server still running','OK','Warning');return $false}
 finally{$script:busy=$false}
}
$stopServer.Add_Click({if(-not $script:busy){[void](Stop-ClientDashboard)}})
$script:busy=$false;$script:serverReady=$false;$script:planValid=$false
function Set-ClientPhase([string]$phase,[string]$message) {
 $index=[Array]::IndexOf($phaseNames,$phase)
 for($i=0;$i -lt $phaseLabels.Count;$i++){$phaseLabels[$i].ForeColor=if($i -lt $index){[Drawing.Color]::FromArgb(130,174,145)}elseif($i -eq $index){$gold}else{$muted}}
 $milestone=@{'Verify folder'=3;'Dependencies'=8;'Import client'=18;'Clean files'=88;'Ready'=100}
 Set-LauncherProgress $milestone[$phase] $message;[Windows.Forms.Application]::DoEvents()
}
function Write-ClientLog([string]$text) {
 # A log line must never abort setup. The runtime helpers call this through a scriptblock held in their own `$Log`
 # parameter and PowerShell resolves plain variable names through the call stack, so the text box is reached through a
 # uniquely named global and checked by type, never through a name (`$log`) or scope lookup that a callee can shadow.
 try{
  if($text -match '^Extracting |^Preparing '){$script:cachedReady=$false;$progress.Visible=-not $signupPanel.Visible}
  $logBox=$global:DekaronLauncherLogBox
  if($logBox -is [Windows.Forms.TextBoxBase]){$logBox.AppendText($text+[Environment]::NewLine)}
  if($text -match 'Extracted\s+(\d+)/(\d+)\s+files' -and [double]$Matches[2] -gt 0){Set-LauncherProgress ([int](18+47*[double]$Matches[1]/[double]$Matches[2])) 'Importing your world...'}
  elseif($text -match '^Preparing (.+)\.\.\.'){if($script:prepareSteps -lt 20){$script:prepareSteps++};$script:preparingName=$Matches[1];Set-LauncherProgress (65+$script:prepareSteps) ('Preparing '+$script:preparingName+'...')}
  elseif($text -match '^.+ is still parsing\.\.\.'){Set-LauncherProgress $progress.Value $text}
  elseif($text -match 'Client source unchanged|Client preparation complete'){Set-LauncherProgress 87 'Your world is ready. Opening the gateway...'}
  [Windows.Forms.Application]::DoEvents()
 }catch{}
}

function ConvertTo-ClientSupportText([string]$Text) {
 # Support details retain relative missing-file names, never the installation owner's home path.
 foreach($root in @($clientEngine,$script:selectedGameRoot,$env:USERPROFILE,$env:TEMP)){
  if($root){$Text=[regex]::Replace($Text,[regex]::Escape([string]$root),'<local folder>',[Text.RegularExpressions.RegexOptions]::IgnoreCase)}
 }
 $Text=[regex]::Replace($Text,'(?i)([A-Z]:[\\/]Users[\\/])[^\\/\r\n]+','$1<user>')
 $Text=[regex]::Replace($Text,'(?i)(token|password|secret)([=:]\s*)[^\s,;]+','$1$2<redacted>')
 return $Text
}
function Show-ClientFailureDetails {
 if(-not $script:preparationFailure){return}
 $dialog=New-Object Windows.Forms.Form;$dialog.Text='Setup details';$dialog.ClientSize=New-Object Drawing.Size(680,370);$dialog.StartPosition='CenterParent';$dialog.Font=New-Object Drawing.Font('Segoe UI',10);$dialog.BackColor=$ink;$dialog.ForeColor=$form.ForeColor;$dialog.MinimizeBox=$false;$dialog.MaximizeBox=$false
 $body=New-Object GalaxyTextBox;$body.Multiline=$true;$body.ReadOnly=$true;$body.ScrollBars='Both';$body.WordWrap=$false;$body.Location=New-Object Drawing.Point(16,16);$body.Size=New-Object Drawing.Size(648,295);$body.BackColor=[Drawing.Color]::FromArgb(24,29,39);$body.ForeColor=$form.ForeColor;$body.Text=ConvertTo-ClientSupportText $script:preparationFailure;$dialog.Controls.Add($body)
 $copy=New-Object RoundedLauncherButton;$copy.Text='Copy details';$copy.Location=New-Object Drawing.Point(16,325);$copy.Size=New-Object Drawing.Size(145,32);$dialog.Controls.Add($copy);$copy.Add_Click({[Windows.Forms.Clipboard]::SetText($body.Text);$copy.Text='Copied'})
 $close=New-Object RoundedLauncherButton;$close.Text='Close';$close.Location=New-Object Drawing.Point(544,325);$close.Size=New-Object Drawing.Size(120,32);$close.DialogResult='Cancel';$dialog.Controls.Add($close);$dialog.CancelButton=$close
 try{[void]$dialog.ShowDialog($form)}finally{$dialog.Dispose()}
}

function Get-InstallPlan {
 if($script:dedicatedMode){$output=& $clientNode.Source (Join-Path $clientEngine 'tools\dedicated-client-plan.mjs') 2>&1;if($LASTEXITCODE -ne 0){throw ($output -join "`n")};return (($output -join '')|ConvertFrom-Json)}
 if($script:npcSandbox){
  if(-not $clientNode){throw 'The copied client runtime is unavailable.'}
  $sandboxOutput=& $clientNode.Source (Join-Path $clientEngine 'tools\npc-sandbox-plan.mjs') 2>&1
  if($LASTEXITCODE -ne 0){throw ($sandboxOutput -join [Environment]::NewLine)}
  return (($sandboxOutput -join '')|ConvertFrom-Json)
 }
 if(-not $PreviewPath){
  try{$script:selectedGameRoot=Get-AdjacentClientFolder $clientEngine}catch{throw 'Place the complete engine folder inside Dekaron, beside data and bin, then open engine\Client.exe.'}
 }
 if(-not $clientNode){return Get-ProvisionalPlan}
 $output = & $clientNode.Source (Join-Path $clientEngine 'tools\install-client.mjs') --plan-json 2>&1
 if($LASTEXITCODE -ne 0){throw ($output -join [Environment]::NewLine)}
 return (($output -join '') | ConvertFrom-Json)
}
function Get-ProvisionalPlan {
 $root=if($script:selectedGameRoot){$script:selectedGameRoot}else{[IO.Path]::GetDirectoryName($clientEngine)}
 return Get-ClientLocationPlan $root
}
function Test-SameInstallPlan($first,$second) {
 $a=(@($first.remove | ForEach-Object {$_.ToLowerInvariant()} | Sort-Object) -join '|')
 $b=(@($second.remove | ForEach-Object {$_.ToLowerInvariant()} | Sort-Object) -join '|')
 return $first.root -ieq $second.root -and $a -ceq $b
}
function Update-ClientPlan([switch]$DeferReadiness) {
 try {
  $script:plan=Get-InstallPlan
  $script:planValid=$true
  $receiptPath=Join-Path $clientEngine 'install-receipt.json'
  $launcherName='DK-Engine-Client.exe'
  try {$receipt=Get-Content -LiteralPath $receiptPath -Raw | ConvertFrom-Json; if($receipt.launcher -in @('Client.exe','DK-Engine-Client.exe')){$launcherName=$receipt.launcher}} catch {}
  $script:needsInstall=-not (Test-Path -LiteralPath $receiptPath -PathType Leaf) -or -not (Test-Path -LiteralPath (Join-Path $script:plan.root $launcherName) -PathType Leaf)
  if($script:dedicatedMode){$script:needsInstall=$false;$script:selectedGameRoot=$null}
  if($script:npcSandbox){$script:needsInstall=$false;$script:selectedGameRoot=$null}
  $extra=if($script:needsInstall -and $script:plan.remove.Count){$script:plan.remove -join ', '}else{'(none)'}
  $details.Text=$(if($script:dedicatedMode){"Dedicated copy: $clientEngine`r`nClient: prepared Global data`r`nProgress: this copy's separate local or SQL world"}else{"$($script:plan.root)`r`nKEEP: existing Global files`r`nDELETE: $extra"})
  $primary.Text=if($script:dashboard){'DX11 Client'}else{'Start'}
  $cleanupNotice.Text=if($script:needsInstall){'Existing Global files are kept. A separate DK Engine launcher will be created.'}else{'Your client is installed. Start checks updated data before play.'}
  if($script:dedicatedMode){$cleanupNotice.Text='Prepared dedicated client. Start opens this copy; its accounts and characters stay separate.'}
  if($script:npcSandbox){$cleanupNotice.Text='NPC / skill test copy. Separate accounts and server; game assets are read only.'}
  $primary.Enabled=$true
  $website.Enabled=$true
  $signupSubmit.Enabled=$true
  if(-not $script:dashboard){$script:cachedReady=$false;if(-not $script:needsInstall -and $clientNode){if($DeferReadiness){$progress.Visible=$false;$statusLine.Text='Checking installed client...';Start-ClientReadinessProbe}else{$script:cachedReady=(Get-CachedClientReady).ready}};if(-not $DeferReadiness -or $script:needsInstall){$progress.Visible=-not $script:cachedReady};if($script:cachedReady){$statusLine.Text='Your client is ready. Sign in, host friends, or connect.'}}
 } catch {$script:planValid=$false;$primary.Enabled=$false; $website.Enabled=$false;$signupSubmit.Enabled=$false; $details.Text=$_.Exception.Message; $statusLine.Text=$_.Exception.Message}
}
function Stop-ClientReadinessProbe {
 if($script:readinessTimer){$script:readinessTimer.Stop();$script:readinessTimer.Dispose();$script:readinessTimer=$null}
 if($script:readinessWorker){try{if(-not $script:readinessWorker.HasExited){$script:readinessWorker.Kill()}}catch{};try{$script:readinessWorker.Dispose()}catch{};$script:readinessWorker=$null}
 $script:readinessOutput=$null;$script:readinessErrors=$null
}
function Update-ClientReadinessView([bool]$Ready) {
 $script:cachedReady=$Ready;$overlay=$false
 foreach($panel in @($signupPanel,$script:authPanel,$script:friendsPanel,$script:extraPanel,$script:ownerAccountsPanel,$script:settingsPanel)){if($panel -and $panel.Visible){$overlay=$true}}
 $progress.Visible=-not $Ready -and -not $script:dashboard -and -not $script:serverReady -and -not $overlay
 $statusLine.Text=$(if($Ready){'Your client is ready. Sign in, host friends, or connect.'}else{'Start will prepare updated client files.'})
}
function Start-ClientReadinessProbe {
 Stop-ClientReadinessProbe
 try{
  $start=New-Object Diagnostics.ProcessStartInfo;$start.FileName=$clientNode.Source;$start.Arguments='"'+(Join-Path $clientEngine 'tools\client-ready.mjs')+'"';$start.WorkingDirectory=$clientEngine;$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true
  $script:readinessEngine=$clientEngine;$script:readinessWorker=[Diagnostics.Process]::Start($start);$script:readinessOutput=$script:readinessWorker.StandardOutput.ReadToEndAsync();$script:readinessErrors=$script:readinessWorker.StandardError.ReadToEndAsync()
  $script:readinessTimer=New-Object Windows.Forms.Timer;$script:readinessTimer.Interval=30
  $script:readinessTimer.Add_Tick({
   param($sender,$eventArgs)
   if(-not [object]::ReferenceEquals($sender,$script:readinessTimer)){return}
   if(-not $script:readinessWorker -or -not $script:readinessWorker.HasExited -or -not $script:readinessOutput.IsCompleted -or -not $script:readinessErrors.IsCompleted){return}
   $ready=$false
   try{if($script:readinessWorker.ExitCode -eq 0){$state=$script:readinessOutput.GetAwaiter().GetResult()|ConvertFrom-Json;$ready=$state.ready -eq $true -and $state.changed -eq $false -and $state.version -match '^[a-f0-9]{64}$'}}catch{}
   if(-not $script:busy -and $script:readinessEngine -ieq $clientEngine -and -not $script:dashboard){Update-ClientReadinessView $ready}
   Stop-ClientReadinessProbe
  });$script:readinessTimer.Start()
 }catch{Stop-ClientReadinessProbe;Update-ClientReadinessView $false;$statusLine.Text='Start will verify and prepare this client.'}
}
function Get-CachedClientReady {
 if(-not $clientNode){return [pscustomobject]@{ready=$false;changed=$true;version=$null}}
 try{$result=& $clientNode.Source (Join-Path $clientEngine 'tools\client-ready.mjs') 2>$null;if($LASTEXITCODE -ne 0){throw 'Readiness check failed'};$state=($result -join '')|ConvertFrom-Json;if($state.ready -and -not $state.changed -and $state.version -match '^[a-f0-9]{64}$'){return $state}}catch{}
 return [pscustomobject]@{ready=$false;changed=$true;version=$null}
}
function Get-ClientApiUrl([string]$url) {
 $endpoint=New-Object UriBuilder($url)
 # Windows PowerShell can spend over two seconds trying ::1 before IPv4.
 # Keep the browser's localhost origin (and cookies); bypass DNS for native API calls.
 if($endpoint.Host -ieq 'localhost' -and $endpoint.Scheme -eq 'http'){$endpoint.Host='127.0.0.1'}
 return $endpoint.Uri.AbsoluteUri
}
function Get-ClientServerStatus([string]$url) {
 try { return Invoke-RestMethod -Uri ((Get-ClientApiUrl $url)+'api/client/status') -Method Get -TimeoutSec 3 -ErrorAction Stop } catch { return $null }
}
function Open-ClientGame([string]$url) {
 $destination=[Uri]$url
 if($destination.Scheme -notin @('http','https')){throw 'The game URL must use HTTP or HTTPS.'}
 if($script:runningFriends){$gate=New-Object UriBuilder($destination);$gate.Path='/join';$destination=$gate.Uri}
 Invoke-DedicatedAssetWarm -Report {param($message) $statusLine.Text=$message}
 Open-IsolatedGame -Engine $clientEngine -Url $destination.AbsoluteUri
}
function Test-ClientServerIdentity($status,$plan) {
 return $null -ne $status -and $status.app -ceq 'dekaron-engine' -and $status.engineId -ceq $plan.engineId -and $status.version -ceq $plan.version -and (-not $plan.runtimeVersion -or $status.runtimeVersion -ceq $plan.runtimeVersion) -and [int]$status.pid -gt 0
}
function Get-ClientPrivateDirectoryRequired([string]$Engine) {
 $directory=Join-Path ([IO.Path]::GetFullPath($Engine)) 'server\accounts'
 Assert-ClientPathUnlinked $directory
 $entry=Get-Item -LiteralPath $directory -Force -ErrorAction Stop
 if(-not $entry.PSIsContainer){throw 'The local accounts path must be an ordinary directory.'}
 # Protection persists after the reviewed transition. Runtime pinning verifies the full policy.
 return [IO.Directory]::GetAccessControl($directory, [Security.AccessControl.AccessControlSections]::Access).AreAccessRulesProtected
}
function Assert-ClientPrivateDirectoryStatus($Status,[bool]$Required) {
 if($Required -and ($null -eq $Status -or $Status.privateAccountDirectory -isnot [bool] -or $Status.privateAccountDirectory -ne $true)){throw 'This local server has not confirmed private account protection. Save and stop it normally, then start through Client.exe.'}
}
function Invoke-ClientPrivateDirectorySpawn([bool]$Required,[scriptblock]$Spawn) {
 $prior=[Environment]::GetEnvironmentVariable('DEKARON_PRIVATE_ACCOUNT_DIR','Process');$priorLauncher=[Environment]::GetEnvironmentVariable('DEKARON_LAUNCHER_PID','Process')
 # A server this launcher starts follows this window process: if the launcher dies without a normal stop, the server saves and exits.
 try{[Environment]::SetEnvironmentVariable('DEKARON_PRIVATE_ACCOUNT_DIR',$(if($Required){'1'}else{'0'}),'Process');[Environment]::SetEnvironmentVariable('DEKARON_LAUNCHER_PID',[string]$PID,'Process');& $Spawn}
 finally{[Environment]::SetEnvironmentVariable('DEKARON_PRIVATE_ACCOUNT_DIR',$prior,'Process');[Environment]::SetEnvironmentVariable('DEKARON_LAUNCHER_PID',$priorLauncher,'Process')}
}
function Request-ClientClose {
 $script:closeRequested=$true
 $script:closeTimer.Start()
 $statusLine.Text='Close requested. Finishing the current operation safely...'
}
$script:closeRequested=$false;$script:preparationWorker=$null
$script:closeTimer=New-Object Windows.Forms.Timer
$script:closeTimer.Interval=100
$script:closeTimer.Add_Tick({if($script:busy){return};$script:closeTimer.Stop();if($script:closeRequested -and -not $form.IsDisposed){$form.Close()}})
function Invoke-Preparation {
 if($script:dedicatedMode){Write-ClientLog 'Using the dedicated preloaded client data. No installation cleanup is required.';return}
 if($script:npcSandbox){if(-not (Get-CachedClientReady).ready){Write-ClientLog 'Preparing moved client data...'; $sandboxPrepareExit=Invoke-ClientNode -arguments @((Join-Path $clientEngine 'tools\prepare-client.mjs'),'--engine',$clientEngine,'--data',[string]$script:npcSandbox.readOnlyData);if($sandboxPrepareExit -ne 0){throw 'Copied client preparation failed. See setup details.'}};return}
 Write-ClientLog 'Checking and preparing client data before any cleanup...'
 $script:preparingClient=$true
 try{$exitCode=Invoke-ClientNode -arguments @((Join-Path $clientEngine 'tools\prepare-client.mjs'),'--engine',$clientEngine)}finally{$script:preparingClient=$false}
 if($script:closeRequested){throw 'Client preparation finished safely. Launch cancelled; original game files were retained.'}
 if($exitCode -ne 0){
  $script:preparationFailure="Preparation stopped before game-file cleanup.`r`n"+$script:lastClientNodeOutput
  $reason='The client data could not be prepared.'
  if($script:lastClientNodeOutput -match '(?m)^Client preparation failed:\s*([^\r\n]+)'){$reason=$Matches[1]}
  $reason=ConvertTo-ClientSupportText $reason
  throw ($reason+"`r`nYour original game files were kept. Open setup details below.")
 }
}
function Invoke-ClientNode([string[]]$arguments) {
 $script:lastClientNodeOutput=''
 $start=New-Object Diagnostics.ProcessStartInfo
 $start.FileName=$clientNode.Source
 $start.Arguments=($arguments | ForEach-Object {'"'+$_.Replace('"','\"')+'"'}) -join ' '
 $start.WorkingDirectory=$clientEngine; $start.UseShellExecute=$false; $start.CreateNoWindow=$true
 $start.RedirectStandardOutput=$true; $start.RedirectStandardError=$true
 $start.StandardOutputEncoding=$OutputEncoding; $start.StandardErrorEncoding=$OutputEncoding
 $worker=[Diagnostics.Process]::Start($start)
 if($script:preparingClient){$script:preparationWorker=$worker}
 try {
 $stdout=$worker.StandardOutput.ReadLineAsync(); $stderr=$worker.StandardError.ReadLineAsync()
 $outClosed=$false; $errClosed=$false
 while(-not $worker.HasExited -or -not $outClosed -or -not $errClosed){
  if(-not $outClosed -and $stdout.IsCompleted){
   $line=$stdout.GetAwaiter().GetResult()
   if($null -eq $line){$outClosed=$true}else{$script:lastClientNodeOutput=($script:lastClientNodeOutput+$line+"`r`n");if($script:lastClientNodeOutput.Length -gt 24000){$script:lastClientNodeOutput=$script:lastClientNodeOutput.Substring($script:lastClientNodeOutput.Length-24000)};Write-ClientLog $line; $stdout=$worker.StandardOutput.ReadLineAsync()}
  }
  if(-not $errClosed -and $stderr.IsCompleted){
   $line=$stderr.GetAwaiter().GetResult()
   if($null -eq $line){$errClosed=$true}else{$script:lastClientNodeOutput=($script:lastClientNodeOutput+$line+"`r`n");if($script:lastClientNodeOutput.Length -gt 24000){$script:lastClientNodeOutput=$script:lastClientNodeOutput.Substring($script:lastClientNodeOutput.Length-24000)};Write-ClientLog $line; $stderr=$worker.StandardError.ReadLineAsync()}
  }
  [Windows.Forms.Application]::DoEvents(); Start-Sleep -Milliseconds 30
 }
 return $worker.ExitCode
 }finally{if($script:preparationWorker -eq $worker){$script:preparationWorker=$null};$worker.Dispose()}
}
function Read-ClientPreparationTask($Task) {
 # A busy server can exceed one poll's HTTP timeout during bot admission. The
 # canceled poll has no response; keep the previous progress and try again.
 if($Task.IsCanceled){return $null}
 return ($Task.GetAwaiter().GetResult()|ConvertFrom-Json)
}
function Wait-ClientWorldPreparation([string]$Url,$Plan,$Control) {
 Add-Type -AssemblyName System.Net.Http
 $handler=New-Object Net.Http.HttpClientHandler
 $client=$null
 try {
  $handler.AllowAutoRedirect=$false
  $client=New-Object Net.Http.HttpClient -ArgumentList (, $handler)
  $client.Timeout=[TimeSpan]::FromSeconds(10)
  [void]$client.DefaultRequestHeaders.TryAddWithoutValidation('x-dekaron-launcher-token',[string]$Control.token)
  $endpoint=(Get-ClientApiUrl $Url)+'api/launcher/preparation'
  $progress.Visible=$true
  $timedOutPolls=0
  while($true){
   if($script:closeRequested -or $form.IsDisposed){throw 'Launch cancelled before sign-in and game window.'}
   $task=$client.GetStringAsync($endpoint)
   while(-not $task.IsCompleted){
    [Windows.Forms.Application]::DoEvents()
    if($script:closeRequested -or $form.IsDisposed){throw 'Launch cancelled before sign-in and game window.'}
    [Threading.Thread]::Sleep(25)
   }
   if($script:closeRequested -or $form.IsDisposed){throw 'Launch cancelled before sign-in and game window.'}
   $status=Read-ClientPreparationTask $task
   if($null -eq $status){
    $timedOutPolls++
    if($timedOutPolls -ge 60){throw 'The server did not answer preparation checks for 10 minutes. Check its status before retrying.'}
    $progress.DetailText='Waiting for the server to finish preparing bots...'
    [Threading.Thread]::Sleep(250)
    continue
   }
   $timedOutPolls=0
   if(-not (Test-ClientServerIdentity $status $Plan) -or [int]$status.pid -ne [int]$Control.pid -or $status.stopping){throw 'Shared world preparation server changed or is stopping. No game window was opened.'}
   $state=$status.preparation
   if($state.ready -isnot [bool] -or $state.phase -notin @('ready','preparing','failed') -or $state.ready -ne ($state.phase -eq 'ready') -or ($state.retryAfterMs -isnot [int] -and $state.retryAfterMs -isnot [long]) -or $state.retryAfterMs -lt 0 -or $state.retryAfterMs -gt 3000){throw 'Invalid shared world preparation response.'}
   if($state.ready){$progress.DetailText='';return}
   if($state.phase -eq 'failed'){throw 'Shared world preparation failed. No game window was opened. Review the server status and retry deliberately.'}
   $message='Preparing your shared world...';$value=88
   if($null -ne $state.progress){
    $count=$state.progress.admitted;$target=$state.progress.target
    if(($count -isnot [int] -and $count -isnot [long]) -or ($target -isnot [int] -and $target -isnot [long]) -or $target -lt 1 -or $target -gt 2500 -or $count -lt 0 -or $count -gt $target){throw 'Invalid native admission progress.'}
    $message='Preparing native bots: '+$count+' of '+$target+' admitted...'
    $progress.DetailText=($count.ToString()+' / '+$target.ToString()+' bots')
    $value=88+[int][Math]::Floor(11*$count/$target)
   }else{$progress.DetailText=''}
   Set-LauncherProgress $value $message
   $until=[DateTime]::UtcNow.AddMilliseconds([Math]::Max(250,$state.retryAfterMs))
   while([DateTime]::UtcNow -lt $until){
    [Windows.Forms.Application]::DoEvents()
    if($script:closeRequested -or $form.IsDisposed){throw 'Launch cancelled before sign-in and game window.'}
    [Threading.Thread]::Sleep(25)
   }
  }
 } finally {if($client){$client.Dispose()}else{$handler.Dispose()}}
}
function Invoke-ClientLaunch([bool]$accountOnly=$false) {
 if(-not $script:planValid){$statusLine.Text='The game folder is not valid. Restore engine beside the original data and bin folders.';return $false}
 if($script:busy){return}
 try{if(-not (Confirm-ClientPrestartSettings $accountOnly)){return $false}}catch{$statusLine.Text=$_.Exception.Message;return $false}
 $script:busy=$true; $primary.Enabled=$false; $website.Enabled=$false; $progress.Visible=-not $signupPanel.Visible -and -not $script:cachedReady
 $script:preparationFailure=$null;if($showDetails){$showDetails.Visible=$false};if($statusLine.PSObject.Properties['Height']){$statusLine.Height=31}
 Stop-ClientReadinessProbe
 # A retry can adopt the same server while its native-bot admission is already
 # underway. Keep the displayed stage until the server reports its live count.
 if($script:needsInstall){$progress.Value=0}
 $progress.DetailText='';$progress.Running=$true;$script:prepareSteps=0
 $signupBack.Enabled=$false
 try {
  $phaseLabels[3].Text=if($accountOnly -or -not $script:needsInstall){'Files retained'}else{'Clean files'}
  $displayed=$script:plan
  Set-ClientPhase 'Verify folder' 'Opening your adventure...'
  if(-not (Test-SameInstallPlan (Get-InstallPlan) $displayed)){throw 'The displayed target or deletion list changed. Review the refreshed list and click again.'}
  Set-ClientPhase 'Dependencies' 'Preparing to launch...'
  if(-not (Get-Command Ensure-ClientRuntime -ErrorAction SilentlyContinue)){throw 'The engine runtime helper is missing. Restore the complete engine release.'}
  $script:clientNode=Ensure-ClientRuntime -Engine $clientEngine -Log {param($message) Write-ClientLog $message}
  if(-not $clientNode -or -not $clientNode.Source){throw 'The required engine runtime could not be verified.'}
  $initial=Get-InstallPlan
  if(-not (Test-SameInstallPlan $initial $displayed)){throw 'The validated target or deletion list changed. Review the refreshed list and click again.'}
  Write-ClientLog "Target: $($initial.root)"
  Set-ClientPhase 'Import client' 'Bringing your world to life...'
  Invoke-Preparation
  $fresh=Get-InstallPlan
  if(-not (Test-SameInstallPlan $initial $fresh)){throw 'The target or deletion list changed during preparation. Review the refreshed list and click again.'}
  if($script:closeRequested){throw 'Launch cancelled before installation or server startup.'}
  $finalized=$false
  if($script:friendsLaunch){
   try{$script:friendsConfig=Invoke-FriendsConfiguration $clientEngine $clientNode.Source $script:pendingFriendsCredentials}
   finally{if($script:pendingFriendsCredentials){$script:pendingFriendsCredentials.Clear();$script:pendingFriendsCredentials=$null}}
   if(-not $script:friendsConfig.configured){throw 'Configure the installed friends host before starting it.'}
  }
  if(-not $accountOnly -and $script:needsInstall){
   Set-ClientPhase 'Clean files' 'Finishing your installation...'
   if((Invoke-ClientNode -arguments @((Join-Path $clientEngine 'tools\install-client.mjs'),'--stage-launcher')) -ne 0){throw 'Launcher staging failed. Cleanup was not started.'}
   foreach($name in $fresh.remove){
    $removePath=[IO.Path]::GetFullPath((Join-Path $fresh.root $name))
    if([IO.Path]::GetDirectoryName($removePath) -ne [IO.Path]::GetFullPath($fresh.root)){throw 'Cleanup path escaped the exact game root.'}
    Write-ClientLog "Permanently deleting: $removePath"
    # The shared helper unlinks nested junctions themselves and never traverses their targets.
    if((Invoke-ClientNode -arguments @((Join-Path $clientEngine 'tools\install-client.mjs'),('--remove-entry='+$name))) -ne 0){throw 'Validated cleanup stopped. Remaining files were preserved.'}
   }
   if((Invoke-ClientNode -arguments @((Join-Path $clientEngine 'tools\install-client.mjs'),'--finalize')) -ne 0){throw 'Launcher finalization failed. Remaining files were preserved.'}
   $script:plan=Get-InstallPlan
   $script:needsInstall=$false
   Update-ClientPlan
   $finalized=$true
  }
  if($script:closeRequested){throw 'Close requested. Installation finished safely; game startup cancelled.'}
  if($accountOnly){Write-ClientLog 'Client ready. Starting the account server...'}else{Write-ClientLog 'Client ready. Starting the game...'}
  $script:serverReady=$false; $script:serverUrl=$null; $script:serverProcess=$null; $script:serverAdopted=$false; $script:control=$null; $openLogin.Enabled=$false
  $script:runningPlan=$(if($finalized){$script:plan}else{$fresh})
  if($script:friendsLaunch){$script:runningPlan.serverUrl='http://localhost:7778/'}else{$script:portSelection=Get-ClientLocalPort -Engine $clientEngine -EngineId $script:runningPlan.engineId -ExplicitPort $script:requestedLocalPort;$script:runningPlan.serverUrl=$script:portSelection.url;Assert-ClientLocalPort -Selection $script:portSelection -Engine $clientEngine -EngineId $script:runningPlan.engineId}
  $script:plan=$script:runningPlan
  $privateDirectoryRequired=$false;if(-not $script:friendsLaunch){$privateDirectoryRequired=Get-ClientPrivateDirectoryRequired $clientEngine}
  $existing=Get-ClientServerStatus $script:runningPlan.serverUrl
  if($existing -and $existing.app -ceq 'dekaron-engine' -and $existing.engineId -ceq $script:runningPlan.engineId -and -not (Test-ClientServerIdentity $existing $script:runningPlan)){
   Restart-StaleOwnedClientServer $clientEngine $script:runningPlan $script:runningPlan.serverUrl $existing
   $existing=$null
  }
  if($existing -and $existing.app -ceq 'dekaron-engine' -and $existing.engineId -ceq $script:runningPlan.engineId){
   if($script:friendsLaunch -and $script:relayConfig){throw 'Stop the existing friends server deliberately, then start this online relay configuration. No process was stopped.'}
   if($script:friendsLaunch -and ($existing.listenHost -cne '0.0.0.0' -or $existing.accountScope -cne 'friends')){throw 'Port 7778 is already running a different hosting mode. Stop that server deliberately before hosting friends.'}
   if(-not (Test-ClientServerIdentity $existing $script:runningPlan)){throw 'This engine server is running an older prepared generation. Close it and restart through Client.exe to apply the update. No process was stopped.'}
   Assert-ClientPrivateDirectoryStatus $existing $privateDirectoryRequired
   $script:serverUrl=$script:runningPlan.serverUrl; $script:serverReady=$true
   # Only a server this launcher spawned (earlier in this session) is stopped when the window closes; a server started by hand or by another launcher is left running.
   $script:serverAdopted=-not (@($script:spawnedServerPids) -contains [int]$existing.pid)
   Write-ClientLog 'Existing server identity and prepared generation confirmed.'
  } else {
  if(-not $accountOnly){
   $progress.DetailText='Checking host upload speed...'
   try{
    $speed=Set-ClientMeasuredUploadBeforeStart
    Write-ClientLog ('Host connection: upload {0} Mbps, download {1} Mbps, test latency {2} ms. Upload budget saved for this server start.' -f $speed.uploadMbps,$speed.downloadMbps,$speed.latencyMs)
   }catch{Write-ClientLog ('Host internet test unavailable; saved upload setting kept. '+$_.Exception.Message)}
   finally{$progress.DetailText=''}
  }
  $runId=[Guid]::NewGuid().ToString('N')
  $stdoutPath=Join-Path $clientEngine "client-server-$runId.log"
  $stderrPath=Join-Path $clientEngine "client-server-$runId.error.log"
  $serverArguments=Get-ClientServerArguments $clientEngine
  Invoke-ClientPrivateDirectorySpawn $privateDirectoryRequired {
  if($script:friendsLaunch){$script:serverProcess=Start-FriendsServerProcess $clientNode.Source $clientEngine $stdoutPath $stderrPath $script:friendsConfig}
  else{Assert-ClientLocalPort -Selection $script:portSelection -Engine $clientEngine -EngineId $script:runningPlan.engineId;$priorPort=[Environment]::GetEnvironmentVariable('PORT','Process');try{[Environment]::SetEnvironmentVariable('PORT',[string]$script:portSelection.port,'Process');$script:serverProcess=Start-Process -FilePath $clientNode.Source -ArgumentList $serverArguments -WorkingDirectory $clientEngine -WindowStyle Hidden -RedirectStandardOutput $stdoutPath -RedirectStandardError $stderrPath -PassThru}finally{[Environment]::SetEnvironmentVariable('PORT',$priorPort,'Process')}}
  }
  if($script:serverProcess -and $script:serverProcess.Id){$script:spawnedServerPids=@($script:spawnedServerPids)+[int]$script:serverProcess.Id}
  $deadline=[DateTime]::UtcNow.AddSeconds(15)
  while([DateTime]::UtcNow -lt $deadline){
   [Windows.Forms.Application]::DoEvents(); Start-Sleep -Milliseconds 80
   if($script:serverProcess.HasExited){
    $errorText=if(Test-Path -LiteralPath $stderrPath){Get-Content -LiteralPath $stderrPath -Raw}else{'Server exited before readiness.'}
    throw "Server startup failed. Close an already running game server before retrying. No process was stopped. $errorText"
   }
   if(Test-Path -LiteralPath $stdoutPath){
    $readiness=Select-String -LiteralPath $stdoutPath -Pattern 'Dekaron (?:Online|Dedicated) running at (http://\S+)' | Select-Object -First 1
    if($readiness){$script:serverUrl=$readiness.Matches[0].Groups[1].Value; $script:serverReady=$true; break}
   }
  }
  if(-not $script:serverReady){throw "Server readiness was not confirmed. Review $stdoutPath and $stderrPath before starting another copy."}
  $startedStatus=Get-ClientServerStatus $script:serverUrl
  if(-not (Test-ClientServerIdentity $startedStatus $script:runningPlan)){$script:serverReady=$false;throw 'The started server identity or prepared generation could not be verified. No process was stopped.'}
  try{Assert-ClientPrivateDirectoryStatus $startedStatus $privateDirectoryRequired}catch{$script:serverReady=$false;throw}
  }
  Write-ClientLog 'Own server confirmed ready.'
  $script:runningFriends=[bool]$script:friendsLaunch
  $script:control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl
  if(-not $accountOnly){Wait-ClientWorldPreparation $script:serverUrl $script:runningPlan $script:control}
  if($script:closeRequested -or $form.IsDisposed){throw 'Launch cancelled before sign-in and game window.'}
  $openLogin.Enabled=$true
  if($script:runningFriends -and $script:relayConfig){Start-OwnedClientRelay $clientEngine $clientNode.Source $script:runningPlan $script:serverUrl}
  if(-not $accountOnly -and $script:selectedGameRoot){try{[void](New-ClientDesktopShortcut -Root $script:plan.root);Write-ClientLog 'Desktop shortcut created: DK Engine'}catch{Write-ClientLog ('The game is ready. Desktop shortcut could not be created: '+$_.Exception.Message)}}
  if(-not $accountOnly){Start-LauncherRun $clientEngine $script:runningPlan $script:serverUrl;Show-ServerDashboard}
  Set-ClientPhase 'Ready' $(if($accountOnly){'Ready to create your account.'}else{'Server ready. Choose DX11, DX11 Fullscreen, Desktop App, or Web Browser.'})
  return $true
 } catch {$failure=$_.Exception.Message;if(-not $script:control){$script:serverReady=$false};Write-ClientLog $failure; Update-ClientPlan; $statusLine.Text=$failure; return $false}
 finally {if($script:portSelection){Release-ClientLocalPort -Selection $script:portSelection;$script:portSelection=$null};if($script:pendingFriendsCredentials){$script:pendingFriendsCredentials.Clear();$script:pendingFriendsCredentials=$null};$script:busy=$false; $primary.Enabled=$script:planValid; $website.Enabled=$script:planValid; $progress.Running=$false; $progress.Visible=-not $signupPanel.Visible -and -not $script:authPanel.Visible -and -not $script:cachedReady; $signupBack.Enabled=$true;if($script:preparationFailure){$progress.Visible=$false;if($showDetails){$showDetails.Text='Setup details';$showDetails.Visible=$true};if($statusLine.PSObject.Properties['Height']){$statusLine.Height=110}}}
}
function Close-LauncherSignup {
 $accountId.Clear(); $accountPassword.Clear(); $confirmPassword.Clear(); $signupResult.Text=''; $primary.Focus()
}
$signupBack.Add_Click({if($script:busy){return}; Close-LauncherSignup})
function Confirm-ClientSetup($plan) {
 $warning="This will replace the official Global client in:`r`n$($plan.root)`r`n`r`nIt permanently deletes EVERYTHING in that folder except data, bin, engine and Client.exe. Global's original launcher and other files will be removed. No backup is created and this cannot be undone.`r`n`r`nBack up the FULL game folder somewhere else first. Close Global and its updater before continuing.`r`n`r`nDelete listed files: $(@($plan.remove) -join ', ')`r`n`r`nContinue installing Dekaron Online?"
 return [Windows.Forms.MessageBox]::Show($form,$warning,'Back up Global before installing','YesNo','Warning','Button2') -eq 'Yes'
}
function Begin-ClientSetup {
 if($script:busy -or -not $script:planValid){return $false}
 if($script:needsInstall -and -not (Confirm-ClientSetup $script:plan)){$statusLine.Text='Installation cancelled. Your original game files were kept.';return $false}
 Close-LauncherSignup
 return (Invoke-ClientLaunch $false)
}
function Open-NativeLaunchChoice([bool]$Borderless) {
 if($script:busy){return}
 $script:requestedNativeBorderless=$Borderless
 if($script:remoteWorld){Show-NativeAuthPanel $script:gameServerUrl $true $script:remoteMetadata $false $false 'native' -Borderless $Borderless;return}
 if($script:dashboard){try{[void](Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl);Show-NativeAuthPanel $(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl}) $script:runningFriends $null $false $false 'native' -Borderless $Borderless;$statusLine.Text='Sign in with a different account for another game window.'}catch{$statusLine.Text=$_.Exception.Message};return}
 [void](Begin-ClientSetup)
}
$primary.Add_Click({Open-NativeLaunchChoice $false})
$script:fullScreenLaunch.Add_Click({Open-NativeLaunchChoice $true})
$website.Add_Click({if($script:busy){return};if($script:remoteWorld){Show-NativeAuthPanel $script:gameServerUrl $true $script:remoteMetadata $true;return};if($script:serverReady){Show-NativeAuthPanel $(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl}) $script:runningFriends $null $true;return};if(Invoke-ClientLaunch $true){Start-LauncherRun $clientEngine $script:runningPlan $script:serverUrl;Show-NativeAuthPanel $(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl}) $false $null $true}})
$signupSubmit.Add_Click({
 if($script:busy){return}
 if(-not $script:planValid){$signupResult.Text='The game folder is not valid. Restore engine beside data and bin first.';return}
 $id=$accountId.Text.Trim().ToLowerInvariant()
 if($id -notmatch '^[a-z0-9_-]{3,32}$' -or $id -eq '__proto__'){$signupResult.Text='Use an ID of 3-32 letters, numbers, underscores or dashes.';return}
 if($accountPassword.Text.Length -lt 6 -or $accountPassword.Text.Length -gt 128){$signupResult.Text='Use a password of 6-128 characters.';return}
 if($accountPassword.Text -cne $confirmPassword.Text){$signupResult.Text='The passwords do not match.';return}
 $signupSubmit.Enabled=$false; $accountId.Enabled=$false; $accountPassword.Enabled=$false; $confirmPassword.Enabled=$false
 $signupResult.Text='Preparing your local account server...'
 try {
  if(-not $script:serverReady -and -not (Invoke-ClientLaunch $true)){$signupResult.Text='Could not prepare your account: '+$statusLine.Text;return}
  $script:busy=$true; $primary.Enabled=$false; $website.Enabled=$false
  $checkedStatus=$null;try{$checkedStatus=Invoke-PumpedNativeAuthTransport @{Uri=((Get-ClientApiUrl $script:serverUrl)+'api/client/status');Method='Get';TimeoutSec=3;ErrorAction='Stop'} $true}catch{if($_.Exception -is [OperationCanceledException]){throw}}
  if(-not (Test-ClientServerIdentity $checkedStatus $script:runningPlan)){throw 'identity'}
  $signupResult.Text='Creating your account...'; [Windows.Forms.Application]::DoEvents()
  # Credentials remain in memory and the HTTP body, never URLs/logs/process arguments.
  $requestBody=@{id=$id;password=$accountPassword.Text}|ConvertTo-Json -Compress
  $session=New-Object Microsoft.PowerShell.Commands.WebRequestSession
  $result=Invoke-PumpedNativeAuthTransport @{Uri=((Get-ClientApiUrl $script:serverUrl)+'api/auth/signup');Method='Post';ContentType='application/json; charset=utf-8';Body=([Text.Encoding]::UTF8.GetBytes($requestBody));WebSession=$session;TimeoutSec=30;ErrorAction='Stop'} $true
  if($null -eq $result -or $result.id -cne $id){throw 'The account server response could not be verified.'}
  [void](Invoke-PumpedNativeAuthTransport @{Uri=((Get-ClientApiUrl $script:serverUrl)+'api/auth/logout');Method='Post';ContentType='application/json';Body='{}';WebSession=$session;TimeoutSec=30;ErrorAction='Stop'} $true)
  $accountId.Clear(); $accountPassword.Clear(); $confirmPassword.Clear()
  $signupResult.Text="Account created! Click $($primary.Text), then log in with your account."
 } catch {
  $code=0
  try {$code=[int]$_.Exception.Response.StatusCode} catch {}
  $signupResult.Text=switch($code){409 {'That account ID already exists. Choose another ID or log in.'} 400 {'The account ID or password is not valid.'} 429 {'Too many attempts. Please wait and try again.'} default {'Account creation failed. Check the local server and try again.'}}
 } finally {
  $requestBody=$null; $session=$null; $result=$null; $script:busy=$false; $primary.Enabled=$script:planValid; $website.Enabled=$script:planValid; $signupSubmit.Enabled=$script:planValid
  $accountId.Enabled=$true; $accountPassword.Enabled=$true; $confirmPassword.Enabled=$true
 }
})
$form.Add_FormClosing({param($sender,$eventArgs)
 if($script:busy){$eventArgs.Cancel=$true;Request-ClientClose;return}
 if($script:serverReady -and -not $PreviewPath){
  # A server this launcher did not start (the owner's own, or another launcher's) is detached, never stopped, by closing the window.
  if($script:serverAdopted){Stop-OwnedClientRelay;Stop-LauncherBuilderStatus;$script:serverReady=$false;$script:dashboard=$false}
  elseif(-not (Stop-ClientDashboard)){$eventArgs.Cancel=$true}
 }
})
$form.Add_FormClosed({$progress.Running=$false;$appEmblem.Image=$null;if($script:ownedEmblem){$script:ownedEmblem.Dispose();$script:ownedEmblem=$null}})
$form.Add_FormClosed({$script:closeTimer.Stop();$script:closeTimer.Dispose();Stop-ClientReadinessProbe})
$form.Add_FormClosed({Stop-LauncherBuilderStatus})
$form.Add_FormClosed({Stop-DesktopClientReturn})
$form.Add_FormClosed({$clientLogo.Image=$null; if($script:ownedClientLogo){$script:ownedClientLogo.Dispose(); $script:ownedClientLogo=$null};if($script:ownedLauncherArt){$script:ownedLauncherArt.Dispose();$script:ownedLauncherArt=$null}})
$form.Add_FormClosed({Stop-ClientReleaseUpdates})
if($PreviewPath){
 # Offscreen developer proof: no runtime discovery/download, network, launch or cleanup.
 $previewFile=[IO.Path]::GetFullPath($PreviewPath)
 if(-not $previewFile.StartsWith($clientEngine+[IO.Path]::DirectorySeparatorChar,[StringComparison]::OrdinalIgnoreCase)){throw 'Preview output must be inside this engine workspace.'}
 if(Test-Path -LiteralPath $previewFile){throw 'Choose a new preview filename; existing files are preserved.'}
 $previewParent=[IO.Path]::GetDirectoryName($previewFile)
 $check=$previewParent
 while($check){$entry=Get-Item -LiteralPath $check -Force;if(($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0){throw 'Preview output refuses linked directories.'};$check=[IO.Path]::GetDirectoryName($check)}
 $script:plan=[pscustomobject]@{root='C:\Games\Dekaron Global';remove=@();clientName='Client.exe'}
 $details.Text="C:\Games\Dekaron Global`r`nKEEP: existing Global files`r`nDELETE: (none)"
 if($PreviewMode -eq 'sql'){Show-DedicatedSqlPage}
 if($PreviewMode -eq 'signup'){Show-LauncherSignup $true;$accountId.Text='Your_account';$signupResult.Text='Your next adventure starts here.'}
 if($PreviewMode -eq 'loading'){$progress.Value=63;$progress.Running=$true;$statusLine.Text='Bringing your world to life...';$primary.Text='Preparing...';$primary.Enabled=$false}
 if($PreviewMode -eq 'dashboard'){Show-ServerDashboard;$script:serverUrl='http://127.0.0.1:7778/';$script:serverLive[$script:serverUrl]=[pscustomobject]@{online=$true;players=3;name=$null};Update-ServerLiveViews}
 if($PreviewMode -eq 'extra'){Show-ServerDashboard;Show-ExtraClientPanel;$script:extraServer.Items.Clear();foreach($fixture in @(@('This computer - your local world','http://127.0.0.1:7778/',$true,2),@('Alex and friends','http://203.0.113.9:7778/',$false,5),@('Weekend raid server','https://raid.example.net/',$false,$null))){[void]$script:extraServer.Items.Add([pscustomobject]@{name=$fixture[0];label=$fixture[0];url=$fixture[1];local=$fixture[2];metadata=$null});$script:serverLive[$fixture[1]]=[pscustomobject]@{online=($null -ne $fixture[3]);players=$fixture[3];name=$null}};$script:extraServer.SelectedIndex=1;$script:extraDesktop.Enabled=$true;$script:extraBrowser.Enabled=$true;$script:extraStatus.Text='Each client needs its own account on that server.'}
 if($PreviewMode -in @('host','connect')){Show-FriendsPanel $PreviewMode}
 if($PreviewMode -eq 'openhost'){Show-FriendsPanel 'host';$script:hostAccess.SelectedIndex=1;$script:ratesToggle.Checked=$true}
 if($PreviewMode -eq 'auth'){Show-NativeAuthPanel 'http://localhost:7778/' $true ([pscustomobject]@{name='Your private world';rates=[pscustomobject]@{exp=1;dil=1;drop=1}})}
 # WinForms skips child painting for an invisible form. Create it offscreen,
 # without a taskbar entry, so DrawToBitmap captures the actual native controls.
 $form.StartPosition='Manual';$form.Location=New-Object Drawing.Point(-32000,-32000);$form.ShowInTaskbar=$false
 $form.Show();$form.PerformLayout();[Windows.Forms.Application]::DoEvents()
 if($PreviewMode -eq 'options'){
  Show-ClientSettingsPanel
  $script:offlineSettings=$true;$script:prestartPending=$true;Update-ClientSettingsContinue
  $script:settingsResult.Text='Review your saved options. SQL / VPS selects local files, local SQL or a remote SQL database. Select the green Launch button when ready.'
 }
 $form.PerformLayout();[Windows.Forms.Application]::DoEvents()
 if($PreviewMode -eq 'loading'){$renderClock=[Diagnostics.Stopwatch]::StartNew();while($renderClock.ElapsedMilliseconds -lt 350){[Windows.Forms.Application]::DoEvents();Start-Sleep -Milliseconds 10}}
 $previewBitmap=New-Object Drawing.Bitmap($form.Width,$form.Height)
 try {$form.DrawToBitmap($previewBitmap,(New-Object Drawing.Rectangle(0,0,$form.Width,$form.Height)));$previewBitmap.Save($previewFile,[Drawing.Imaging.ImageFormat]::Png)} finally {$previewBitmap.Dispose();$form.Dispose();if($script:ownedClientLogo){$script:ownedClientLogo.Dispose();$script:ownedClientLogo=$null};if($script:ownedLauncherArt){$script:ownedLauncherArt.Dispose();$script:ownedLauncherArt=$null}}
 Write-Output "Preview saved: $previewFile"
 return
}
Update-ClientPlan -DeferReadiness
if($startupError){$statusLine.Text=$startupError}elseif($script:planValid -and $script:needsInstall){$statusLine.Text='Ready when you are.'}
function Resume-InstalledClient {
 # Update restarts only resume an already installed local client. First install
 # still requires the ordinary reviewed deletion confirmation from Start.
 if(-not $script:planValid -or $script:needsInstall -or $script:busy){$statusLine.Text='Click Start to review the selected installation.';return $false}
 return (Invoke-ClientLaunch $false)
}
$form.Add_Shown({if($clientNode){Initialize-ClientReleaseUpdates $clientEngine $clientNode.Source $form}})
$form.Add_Shown({if($Setup){[void](Begin-ClientSetup)}elseif($Resume){[void](Resume-InstalledClient)}elseif($script:dedicatedMode){[void](Show-DedicatedStartupOptions)}else{Start-SavedRemoteProbe}})
[void]$form.ShowDialog()


