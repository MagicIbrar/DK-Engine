function Update-SavedServerFilter {
 $selected=$script:savedServers.SelectedItem;$query=$script:savedSearch.Text.Trim();$script:savedServers.BeginUpdate()
 try{$script:savedServers.Items.Clear();foreach($entry in @($script:savedServerRows)){if(-not $query -or ([string]$entry.name).IndexOf($query,[StringComparison]::OrdinalIgnoreCase) -ge 0 -or ([string]$entry.url).IndexOf($query,[StringComparison]::OrdinalIgnoreCase) -ge 0){[void]$script:savedServers.Items.Add($entry);if($selected -and $selected.url -ceq $entry.url){$script:savedServers.SelectedItem=$entry}}}}finally{$script:savedServers.EndUpdate()}
}
function Update-HostAccessControls {
 if($script:hostFields.Count -ge 8){$show=$script:friendsMode -eq 'host' -and $script:hostAccess.SelectedIndex -eq 0;$script:hostFields[6].Visible=$show;$script:hostFields[7].Visible=$show;if(-not $show){$script:hostInputs[3].Clear()}}
 Update-RelayPublicationEligibility
}
# Invite-only LAN hosting and explicit remote joining. Never changes router/firewall rules.
function ConvertTo-FriendsUrl([string]$Value) {
 $text=$Value.Trim();if(-not $text){throw 'Paste the address your host sent you.'}
 if($text -notmatch '^https?://'){
  $bareIp=$null;$hostPart=($text.TrimEnd('/') -split ':',2)[0]
  if([Net.IPAddress]::TryParse($hostPart,[ref]$bareIp) -or $hostPart -ieq 'localhost'){$text='http://'+$text;if($text -notmatch ':\d+/?$'){$text=$text.TrimEnd('/')+':7778/'}}
  else{$text='https://'+$text}
 }
 $uri=$null;if(-not [Uri]::TryCreate($text,[UriKind]::Absolute,[ref]$uri) -or $uri.Scheme -notin @('http','https') -or $uri.UserInfo -or $uri.Query -or $uri.Fragment -or $uri.AbsolutePath -ne '/'){throw 'Use the host LAN address and port 7778, without credentials or extra paths.'}
 if($uri.Scheme -eq 'http'){
  $ip=$null;$private=$uri.IsLoopback
  if([Net.IPAddress]::TryParse($uri.Host,[ref]$ip) -and $ip.AddressFamily -eq [Net.Sockets.AddressFamily]::InterNetwork){$b=$ip.GetAddressBytes();$private=$private -or $b[0] -eq 10 -or ($b[0] -eq 172 -and $b[1] -ge 16 -and $b[1] -le 31) -or ($b[0] -eq 192 -and $b[1] -eq 168)}
  if(-not $private){throw 'Plain HTTP joining is limited to LAN/private VPN addresses. Internet hosting needs a trusted HTTPS address.'}
 }
 return $uri.AbsoluteUri
}
function Get-FriendsAddresses([int]$Port=7778) {
 $addresses=@()
 foreach($adapter in [Net.NetworkInformation.NetworkInterface]::GetAllNetworkInterfaces()){
  if($adapter.OperationalStatus -ne [Net.NetworkInformation.OperationalStatus]::Up){continue}
  foreach($entry in $adapter.GetIPProperties().UnicastAddresses){
   $ip=$entry.Address;if($ip.AddressFamily -ne [Net.Sockets.AddressFamily]::InterNetwork -or [Net.IPAddress]::IsLoopback($ip)){continue}
   $b=$ip.GetAddressBytes();if($b[0] -eq 10 -or ($b[0] -eq 172 -and $b[1] -ge 16 -and $b[1] -le 31) -or ($b[0] -eq 192 -and $b[1] -eq 168)){$addresses+='http://'+$ip.ToString()+':'+$Port+'/'}
  }
 }
 return @($addresses|Select-Object -Unique)
}
function Invoke-FriendsConfiguration([string]$Engine,[string]$Node,$Credentials=$null) {
 $helper=Join-Path $Engine 'tools\configure-friends-host.mjs';Assert-ClientPathUnlinked $helper
 $info=New-Object Diagnostics.ProcessStartInfo;$info.FileName=$Node;$info.Arguments='"'+$helper+'"'+$(if($null -eq $Credentials){' --status'}else{''});$info.WorkingDirectory=$Engine;$info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.RedirectStandardInput=$true;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
 $process=New-Object Diagnostics.Process;$process.StartInfo=$info
 try{
  [void]$process.Start();if($null -ne $Credentials){$process.StandardInput.Write(($Credentials|ConvertTo-Json -Compress))};$process.StandardInput.Close()
  $output=$process.StandardOutput.ReadToEnd();$failure=$process.StandardError.ReadToEnd();$process.WaitForExit()
  if($process.ExitCode -ne 0){$message='Friends host configuration failed.';try{$errorData=$failure|ConvertFrom-Json;if($errorData.error){$message=[string]$errorData.error}}catch{};throw $message}
  $config=$output|ConvertFrom-Json
  if($config.port -ne 7778){throw 'The friends host configuration has an unexpected port.'}
  if($config.configured){foreach($pair in @(@('accountStore','server\accounts\friends-accounts.json'),@('permissionsFile','server\accounts\friends-accounts.json.permissions.json'))){$actual=[IO.Path]::GetFullPath([string]$config.($pair[0]));$expected=[IO.Path]::GetFullPath((Join-Path $Engine $pair[1]));if($actual -ine $expected){throw 'Friends host configuration escaped its private account folder.'};Assert-ClientPathUnlinked $actual}}
  return $config
 }finally{$process.Dispose()}
}
function Test-ClientAllowLan {
 if($script:allowLan){return $true}
 try{$pp=Read-ClientHostPreferences;return [bool]($pp -and $pp.hosting -and $pp.hosting.allowLan)}catch{return $false}
}
function Start-FriendsServerProcess([string]$Node,[string]$Engine,[string]$Stdout,[string]$Stderr,$Config) {
 if(-not $Config.configured -or $Config.port -ne 7778){throw 'Configure an Admin / GM / Dev (max staff) account before hosting.'}
 $rates=$Config.rates;if(-not $rates){$rates=[pscustomobject]@{exp=1;dil=1;drop=1}}
 $values=@{DEKARON_HOST=$(if(Test-ClientAllowLan){'0.0.0.0'}else{'127.0.0.1'});PORT='7778';DEKARON_LOCAL_DEMO='0';DEKARON_ACCOUNT_STORE=[string]$Config.accountStore;DEKARON_PERMISSION_STORE=[string]$Config.permissionsFile;DEKARON_SERVER_MODE='friends';DEKARON_FRIENDS_GATE='1';DEKARON_EXP_RATE=([double]$rates.exp).ToString([Globalization.CultureInfo]::InvariantCulture);DEKARON_DIL_RATE=([double]$rates.dil).ToString([Globalization.CultureInfo]::InvariantCulture);DEKARON_DROP_RATE=([double]$rates.drop).ToString([Globalization.CultureInfo]::InvariantCulture)};if($script:relayConfig){$values.DEKARON_HOST='127.0.0.1';$values.DEKARON_RELAY_SECRET=$script:relayConfig.secret;$values.DEKARON_RELAY_ORIGIN=$script:relayConfig.publicOrigin};$previous=@{}
 foreach($key in $values.Keys){$previous[$key]=[Environment]::GetEnvironmentVariable($key,'Process')}
 try{foreach($key in $values.Keys){[Environment]::SetEnvironmentVariable($key,$values[$key],'Process')};return Start-Process -FilePath $Node -ArgumentList $(if(Get-Command Get-ClientServerArguments -ErrorAction SilentlyContinue){Get-ClientServerArguments $Engine}else{'server.mjs'}) -WorkingDirectory $Engine -WindowStyle Hidden -RedirectStandardOutput $Stdout -RedirectStandardError $Stderr -PassThru}
 finally{foreach($key in $values.Keys){[Environment]::SetEnvironmentVariable($key,$previous[$key],'Process')}}
}
function Join-FriendsGame([string]$Engine,[string]$Address) {
 $url=ConvertTo-FriendsUrl $Address
 Assert-ClientServerSwitch $url
 try{$status=Invoke-RestMethod -Uri ((Get-ClientApiUrl $url)+'api/friends/status') -MaximumRedirection 0 -TimeoutSec 5}catch{throw 'The host did not respond directly. Check the address, LAN/VPN and firewall; redirects are not accepted.'}
 if($status.app -cne 'dekaron-engine' -or ($status.protocol -isnot [int] -and $status.protocol -isnot [long]) -or $status.protocol -ne 1 -or ($status.version -isnot [int] -and $status.version -isnot [long]) -or $status.version -ne 1 -or $status.requiresInvite -isnot [bool] -or -not (($status.hostMode -ceq 'friends' -and $status.requiresInvite) -or ($status.hostMode -ceq 'open' -and -not $status.requiresInvite))){throw 'This address is not a compatible invite-only Dekaron friends server.'}
 return [pscustomobject]@{url=$url;protocol=$status.protocol;rates=$status.rates;name=$status.name;metadata=$status}
}
function Start-FriendsHost {
 Update-RelayPublicationEligibility
 Set-PendingRelayConfiguration
 try{
 if($script:serverReady){throw 'Stop this dashboard server first. Local play on another dashboard remains untouched.'}
 if(-not $script:planValid){throw 'Choose your updated game folder before hosting.'}
 if($script:needsInstall -and -not (Confirm-ClientSetup $script:plan)){return}
 $script:friendsLaunch=$true
 Show-FriendsPanel 'close';Close-LauncherSignup;[void](Invoke-ClientLaunch $false);if($script:serverReady -and $script:runningFriends){Save-ClientHostPreferences @{kind='host'};$script:hostButton.Text='Resume host'}
 }finally{$script:friendsLaunch=$false;if($script:pendingFriendsCredentials){$script:pendingFriendsCredentials.Clear();$script:pendingFriendsCredentials=$null}}
}
function Show-FriendsPanel([string]$Mode) {
 if($script:busy){return}
 $show=$Mode -ne 'close';if($show -and -not $script:friendsPanel.Visible){$script:friendsCovered=@();foreach($control in @($script:browserLaunch,$itemBuilderButton,$mapBuilderButton)){if($control){if($control.Visible){$script:friendsCovered+=,$control};$control.Visible=$false}}};$script:friendsPanel.Visible=$show   # the top-row buttons stay
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$statusLine)){if($control){$control.Visible=-not $show}}
 $progress.Visible=-not $show -and -not $script:cachedReady -and -not $script:dashboard -and -not $script:serverReady
 $signupPanel.Visible=$false
 if(-not $show){$script:ratesPanel.Visible=$false;$script:publicPanel.Visible=$false;foreach($control in @($script:friendsCovered)){if($control){$control.Visible=$true}};$script:friendsCovered=@();return}
 $script:publicPanel.Visible=$false;$script:friendsPanel.BringToFront();$script:friendsMode=$Mode
 $hostMode=$Mode -eq 'host';$inviteMode=$Mode -eq 'invite'
 if($hostMode){Restore-ClientRelayPreferences}
 $script:friendsTitle.Text=$(if($hostMode){'Host your friends'}elseif($inviteMode){'Invite your party'}else{'Connect to a world'})
 $script:friendsIntro.Text=$(if($hostMode){'One-time private world setup. Accounts here are separate from local play.'}elseif($inviteMode){'Share your LAN/private VPN address and invite password privately.'}else{'Saved servers or host address.'})
 $script:publicTab.Visible=$Mode -eq 'connect';$script:hostAccess.Visible=$hostMode;$script:hostName.Visible=$hostMode;$script:friendsIntro.Width=$(if($Mode -eq 'connect'){155}else{310});$script:friendsIntro.Height=$(if($hostMode){22}else{48});if($hostMode){$script:friendsIntro.Text='A separate private world. Server name:'}
 $script:ratesToggle.Visible=$hostMode;$script:ratesPanel.Visible=$hostMode -and $script:ratesToggle.Checked
 foreach($control in $script:hostFields){$control.Visible=$hostMode};if($hostMode){Update-HostAccessControls}
 $script:rememberHost.Visible=$Mode -eq 'connect';$script:joinAddress.Visible=-not $hostMode;$script:friendsAction.Text=$(if($hostMode){'Create host & play'}elseif($inviteMode){'Copy invite address'}else{'Test address & connect'})
 $script:friendsAction.Enabled=$true;$script:friendsResult.Text='';$script:internetHelp.Visible=$inviteMode
 if($script:friendsPhoneQr){$script:friendsPhoneQr.Visible=$inviteMode;$script:friendsPhoneQr.Enabled=$script:serverReady -and -not $script:remoteWorld}
 $script:savedServers.Visible=$Mode -eq 'connect';$script:savedSearch.Visible=$Mode -eq 'connect';if($Mode -eq 'connect'){Update-SavedServerControls;$script:savedServerRows=@($script:savedServers.Items);Update-SavedServerFilter;if(-not $script:publicDirectory.Text.Trim()){try{$prefs=Read-ClientHostPreferences;if($prefs -and $prefs.hosting -and $prefs.hosting.listDirectory){$script:publicDirectory.Text=[string]$prefs.hosting.listDirectory}}catch{}};Start-PublicListFetch};$script:friendsPanel.Height=$(if($hostMode){442}elseif($Mode -eq 'connect'){370}else{354});$script:friendsAction.Top=$(if($hostMode){323}elseif($Mode -eq 'connect'){245}else{218});$script:friendsBack.Top=$(if($hostMode){375}elseif($Mode -eq 'connect'){290}else{262});$script:friendsResult.Top=$(if($hostMode){372}elseif($Mode -eq 'connect'){290}else{262})
 if($inviteMode -and $script:gameServerUrl){$script:joinAddress.Text=$script:gameServerUrl;$script:friendsResult.Text='Share this relay address. Your home IP is not listed.';return}
 if($inviteMode -and -not (Test-ClientAllowLan)){$script:joinAddress.Text='';$script:friendsAction.Enabled=$false;$script:friendsResult.Text='Relay-only: your LAN address is hidden and not copied. Turn on Online relay in Hosting options for an address to share, or allow direct LAN connections in Settings.';return}
 if($inviteMode){$addresses=@(Get-FriendsAddresses);$script:joinAddress.Text=$(if($addresses.Count){$addresses[0]}else{''});$script:friendsResult.Text=$(if($addresses.Count -gt 1){'Multiple networks found. Replace this with the address on your friends network.'}elseif(-not $addresses.Count){'No private LAN/VPN address found. Connect to a private network first.'}else{'Host stays running while this dashboard is open.'})}
}
function Initialize-FriendsControls {
 $script:friendsCovered=@()
 $script:friendsPanel=New-Object GalaxyPanel;$script:friendsPanel.Location=New-Object Drawing.Point(325,155);$script:friendsPanel.Size=New-Object Drawing.Size(350,442);$script:friendsPanel.BackColor=[Drawing.Color]::FromArgb(18,22,30);$form.Controls.Add($script:friendsPanel);$script:friendsPanel.Visible=$false
 $script:friendsTitle=New-Object Windows.Forms.Label;$script:friendsTitle.Location=New-Object Drawing.Point(16,16);$script:friendsTitle.Size=New-Object Drawing.Size(232,30);$script:friendsTitle.Font=New-Object Drawing.Font('Segoe UI',13,[Drawing.FontStyle]::Bold);$script:friendsTitle.ForeColor=$gold;$script:friendsPanel.Controls.Add($script:friendsTitle)
 $script:friendsIntro=New-Object Windows.Forms.Label;$script:friendsIntro.Location=New-Object Drawing.Point(16,53);$script:friendsIntro.Size=New-Object Drawing.Size(310,48);$script:friendsIntro.ForeColor=$muted;$script:friendsPanel.Controls.Add($script:friendsIntro)
 $script:hostName=New-Object GalaxyTextBox;$script:hostName.Text='Dekaron Online';$script:hostName.MaxLength=64;$script:hostName.Location=New-Object Drawing.Point(16,78);$script:hostName.Size=New-Object Drawing.Size(310,26);$script:hostName.BackColor=[Drawing.Color]::FromArgb(30,35,44);$script:hostName.ForeColor=$gold;$script:friendsPanel.Controls.Add($script:hostName)
 $script:hostAccess=New-Object GalaxyComboBox;$script:hostAccess.DropDownStyle='DropDownList';[void]$script:hostAccess.Items.Add('Invite only');[void]$script:hostAccess.Items.Add('Open (accounts required)');$script:hostAccess.SelectedIndex=0;$script:hostAccess.Location=New-Object Drawing.Point(16,108);$script:hostAccess.Size=New-Object Drawing.Size(310,26);$script:friendsPanel.Controls.Add($script:hostAccess);$script:hostAccess.Add_SelectedIndexChanged({Update-HostAccessControls})
 $script:ratesToggle=New-Object Windows.Forms.CheckBox;$script:ratesToggle.Text='More';$script:ratesToggle.Location=New-Object Drawing.Point(258,17);$script:ratesToggle.Size=New-Object Drawing.Size(76,24);$script:ratesToggle.ForeColor=$muted;$script:friendsPanel.Controls.Add($script:ratesToggle)
 $script:ratesPanel=New-Object GalaxyPanel;$script:ratesPanel.Location=New-Object Drawing.Point(690,210);$script:ratesPanel.Size=New-Object Drawing.Size(280,438);$script:ratesPanel.BackColor=[Drawing.Color]::FromArgb(18,22,30);$script:ratesPanel.Visible=$false;$form.Controls.Add($script:ratesPanel);$script:rateInputs=@()
 for($i=0;$i -lt 3;$i++){$label=New-Object Windows.Forms.Label;$label.Text=@('EXP multiplier','DIL multiplier','Drop multiplier')[$i];$label.Location=New-Object Drawing.Point(14,(20+$i*60));$label.Size=New-Object Drawing.Size(190,20);$label.ForeColor=$muted;$field=New-Object GalaxyNumberBox;$field.DecimalPlaces=1;$field.Minimum=[decimal]0.1;$field.Maximum=100;$field.Increment=[decimal]0.1;$field.Value=1;$field.Location=New-Object Drawing.Point(14,(42+$i*60));$field.Size=New-Object Drawing.Size(190,26);$script:ratesPanel.Controls.Add($label);$script:ratesPanel.Controls.Add($field);$script:rateInputs+=$field}
 $script:ratesToggle.Add_CheckedChanged({$script:ratesPanel.Visible=$script:ratesToggle.Checked -and $script:friendsMode -eq 'host';if($script:ratesPanel.Visible){$script:ratesPanel.BringToFront()}})
 Initialize-RelayControls
 $script:hostFields=@();$script:hostInputs=@()
 $labels=@('Admin / GM / Dev account ID','Staff password (12+ characters)','Repeat staff password','Invite password (different, 12+)')
 for($i=0;$i -lt 4;$i++){$label=New-Object Windows.Forms.Label;$label.Text=$labels[$i];$label.Location=New-Object Drawing.Point(16,(141+$i*44));$label.Size=New-Object Drawing.Size(310,19);$label.ForeColor=$muted;$field=New-Object GalaxyTextBox;$field.Location=New-Object Drawing.Point(16,(160+$i*44));$field.Size=New-Object Drawing.Size(310,26);$field.BackColor=[Drawing.Color]::FromArgb(30,35,44);$field.ForeColor=$gold;$field.UseSystemPasswordChar=$i -gt 0;$script:friendsPanel.Controls.Add($label);$script:friendsPanel.Controls.Add($field);$script:hostFields+=$label;$script:hostFields+=$field;$script:hostInputs+=$field}
 $script:joinAddress=New-Object GalaxyTextBox;$script:joinAddress.Location=New-Object Drawing.Point(16,115);$script:joinAddress.Size=New-Object Drawing.Size(310,28);$script:joinAddress.BackColor=[Drawing.Color]::FromArgb(30,35,44);$script:joinAddress.ForeColor=$gold;$script:friendsPanel.Controls.Add($script:joinAddress)
 $script:internetHelp=New-Object Windows.Forms.CheckBox;$script:internetHelp.Text='Show Internet / HTTPS setup';$script:internetHelp.Location=New-Object Drawing.Point(16,163);$script:internetHelp.Size=New-Object Drawing.Size(310,28);$script:internetHelp.ForeColor=$muted;$script:friendsPanel.Controls.Add($script:internetHelp)
 $script:internetHelp.Add_CheckedChanged({if($script:internetHelp.Checked){$script:friendsResult.Text='Internet access needs a reachable HTTPS host or private VPN. This does not open your router, firewall or a tunnel. See docs/MULTIPLAYER.md.'}else{$script:friendsResult.Text='LAN/private VPN hosting is enabled while this host dashboard is running.'}})
 $script:friendsPhoneQr=New-Object RoundedLauncherButton;$script:friendsPhoneQr.Text='Phone / tablet QR';$script:friendsPhoneQr.AccessibleName='Phone or tablet server QR';$script:friendsPhoneQr.Bounds=New-Object Drawing.Rectangle(16,146,310,32);$script:friendsPhoneQr.ForeColor=$gold;$script:friendsPhoneQr.Visible=$false;$script:friendsPanel.Controls.Add($script:friendsPhoneQr);$script:friendsPhoneQr.Add_Click({Show-ClientPhoneQr})
 $script:internetHelp.Top=180
 $script:friendsAction=New-Object RoundedLauncherButton;$script:friendsAction.UseMnemonic=$false;$script:friendsAction.Location=New-Object Drawing.Point(16,323);$script:friendsAction.Size=New-Object Drawing.Size(310,38);$script:friendsAction.BackColor=$gold;$script:friendsAction.ForeColor=$ink;$script:friendsAction.FlatStyle='Flat';$script:friendsPanel.Controls.Add($script:friendsAction)
 $script:friendsBack=New-Object RoundedLauncherButton;$script:friendsBack.Text='Back';$script:friendsBack.Location=New-Object Drawing.Point(258,375);$script:friendsBack.Size=New-Object Drawing.Size(68,30);$script:friendsPanel.Controls.Add($script:friendsBack);$script:friendsBack.Add_Click({Show-FriendsPanel 'close'})
 $script:friendsResult=New-Object Windows.Forms.Label;$script:friendsResult.Location=New-Object Drawing.Point(16,372);$script:friendsResult.Size=New-Object Drawing.Size(236,62);$script:friendsResult.ForeColor=$gold;$script:friendsPanel.Controls.Add($script:friendsResult)
 $script:friendsAction.Add_Click({
  if($script:busy){return};$script:friendsAction.Enabled=$false
  try{
   if($script:friendsMode -eq 'host'){
    if(Get-Command Confirm-ClientPrestartSettings -ErrorAction SilentlyContinue){$script:friendsLaunch=$true;try{if(-not (Confirm-ClientPrestartSettings $false)){return}}finally{$script:friendsLaunch=$false}}
    $runtime=Ensure-ClientRuntime -Engine $clientEngine -Log {param($message) Write-ClientLog $message}
    $credentials=@{id=$script:hostInputs[0].Text;password=$script:hostInputs[1].Text;confirmPassword=$script:hostInputs[2].Text;serverPassword=$script:hostInputs[3].Text;name=$script:hostName.Text;mode=$(if($script:hostAccess.SelectedIndex -eq 1){'open'}else{'invite'});rates=@{exp=[double]$script:rateInputs[0].Value;dil=[double]$script:rateInputs[1].Value;drop=[double]$script:rateInputs[2].Value}}
    Set-PendingRelayConfiguration
    $script:pendingFriendsCredentials=$credentials
    for($i=1;$i -lt 4;$i++){$script:hostInputs[$i].Clear()}
    Start-FriendsHost
   }elseif($script:friendsMode -eq 'invite'){[Windows.Forms.Clipboard]::SetText((ConvertTo-FriendsUrl $script:joinAddress.Text));$script:friendsResult.Text='Address copied. Send the invite password separately.'}
   else{$destination=Join-FriendsGame $clientEngine $script:joinAddress.Text;if($script:rememberHost.Checked){Save-ClientHostPreferences @{version=1;kind='remote';url=$destination.url;name=$destination.metadata.name}};Show-RemoteWorldDashboard $destination.url $destination.metadata;Show-NativeAuthPanel $destination.url $true $destination.metadata}
  }catch{$script:friendsResult.Text=$_.Exception.Message}finally{$script:friendsAction.Enabled=$true}
 })
 $script:rememberHost=New-Object Windows.Forms.CheckBox;$script:rememberHost.Checked=$true;$script:rememberHost.Text='Save server for next launch';$script:rememberHost.Location=New-Object Drawing.Point(16,157);$script:rememberHost.Size=New-Object Drawing.Size(310,24);$script:rememberHost.ForeColor=$muted;$script:friendsPanel.Controls.Add($script:rememberHost)
 $script:savedServers=New-Object GalaxyComboBox;$script:savedServers.DropDownStyle='DropDownList';$script:savedServers.AccessibleName='Search saved servers by name';$script:savedServers.DisplayMember='name';$script:savedServers.FormattingEnabled=$true;$script:savedServers.Add_Format({param($sender,$e);$e.Value=Format-ServerRowText $e.ListItem $e.Value});$script:savedServers.Location=New-Object Drawing.Point(16,211);$script:savedServers.Size=New-Object Drawing.Size(310,24);$script:friendsPanel.Controls.Add($script:savedServers);$script:savedServers.Add_SelectedIndexChanged({if($script:savedServers.SelectedItem){$script:joinAddress.Text=$script:savedServers.SelectedItem.url}})
 $script:savedServerRows=@();$script:savedSearch=New-Object GalaxyTextBox;$script:savedSearch.AccessibleName='Search saved server names or addresses';$script:savedSearch.Hint='Search saved name or address';$script:savedSearch.MaxLength=128;$script:savedSearch.Location=New-Object Drawing.Point(16,181);$script:savedSearch.Size=New-Object Drawing.Size(310,26);$script:friendsPanel.Controls.Add($script:savedSearch);$script:savedSearch.Add_TextChanged({Update-SavedServerFilter})
 Initialize-PublicServerControls
 $script:hostButton=New-Object RoundedLauncherButton;$script:hostButton.Text='Host friends';$script:hostButton.Location=New-Object Drawing.Point(300,565);$script:hostButton.Size=New-Object Drawing.Size(192,34);$script:hostButton.FlatStyle='Flat';$script:hostButton.BackColor=$ink;$script:hostButton.ForeColor=$muted;$form.Controls.Add($script:hostButton)
 $script:connectButton=New-Object RoundedLauncherButton;$script:connectButton.Text='Connect';$script:connectButton.Location=New-Object Drawing.Point(508,565);$script:connectButton.Size=New-Object Drawing.Size(192,34);$script:connectButton.FlatStyle='Flat';$script:connectButton.BackColor=$ink;$script:connectButton.ForeColor=$muted;$form.Controls.Add($script:connectButton)
 $script:hostTab=New-Object RoundedLauncherButton;$script:hostTab.Text='Host / invite';$script:hostTab.Location=New-Object Drawing.Point(665,87);$script:hostTab.Size=New-Object Drawing.Size(134,30);$script:hostTab.Visible=$false;$script:hostTab.FlatStyle='Flat';$script:hostTab.BackColor=$ink;$script:hostTab.ForeColor=$muted;$form.Controls.Add($script:hostTab);$script:hostTab.Add_Click({Show-FriendsPanel 'invite'})
 # Top-row buttons (client-ui.ps1 Initialize-ClientDashboardTabs). Pressing the button of the open panel again closes it
 # (back to the home / dashboard view); after loading they open the same panels the retired Worlds / Hosting tabs did.
 $script:connectButton.Add_Click({
  if($script:busy -or $script:ownerAccountsWorking){return}
  if($script:friendsPanel.Visible -and $script:friendsMode -eq 'connect'){Show-FriendsPanel 'close'}else{if($script:dashboard -and (Get-Command Show-ClientDashboardTab -ErrorAction SilentlyContinue)){Show-ClientDashboardTab};Show-FriendsPanel 'connect'}
  if(Get-Command Update-ClientDashboardView -ErrorAction SilentlyContinue){Update-ClientDashboardView}
 })
 $script:hostButton.Add_Click({
  if($script:busy){return}
  if($script:dashboard){   # after loading: invite your party (a friends host is running) or set one up, like the old Hosting tab
   if($script:ownerAccountsWorking -or $script:remoteWorld){return}
   $mode=$(if($script:serverReady -and $script:runningFriends){'invite'}else{'host'})
   if($script:friendsPanel.Visible -and $script:friendsMode -eq $mode){Show-FriendsPanel 'close'}else{if(Get-Command Show-ClientDashboardTab -ErrorAction SilentlyContinue){Show-ClientDashboardTab};Show-FriendsPanel $mode}
   if(Get-Command Update-ClientDashboardView -ErrorAction SilentlyContinue){Update-ClientDashboardView};return
  }
  try{$runtime=Ensure-ClientRuntime -Engine $clientEngine -Log {param($message) Write-ClientLog $message};$hostEngine=$clientEngine;if($script:selectedGameRoot){$installed=Join-Path $script:selectedGameRoot 'engine';if(Test-Path -LiteralPath (Join-Path $installed 'tools\configure-friends-host.mjs')){$hostEngine=$installed}};$script:friendsConfig=Invoke-FriendsConfiguration $hostEngine $runtime.Source;if($script:friendsConfig.configured){Start-FriendsHost}else{Show-FriendsPanel 'host'}}catch{$statusLine.Text=$_.Exception.Message}
 })
}
function ConvertTo-PublicDirectoryUri([string]$Address) {
 $uri=$null;if(-not [Uri]::TryCreate($Address.Trim(),[UriKind]::Absolute,[ref]$uri)){throw 'Use the directory HTTPS root address.'}
 if($uri.Scheme -cne 'https' -or $uri.UserInfo -or $uri.Query -or $uri.Fragment -or $uri.AbsolutePath -ne '/'){throw 'Use the directory HTTPS root address.'}
 return $uri
}
function Get-PublicServerDirectory([string]$Address) {
 $uri=ConvertTo-PublicDirectoryUri $Address
 $reply=Invoke-WebRequest -UseBasicParsing -Uri ($uri.AbsoluteUri+'api/servers') -MaximumRedirection 0 -TimeoutSec 15 -ErrorAction Stop
 if([int]$reply.StatusCode -ne 200){throw 'The directory must respond directly.'}
 return ConvertFrom-PublicDirectoryContent $reply.Content
}
function ConvertFrom-PublicDirectoryContent([string]$Content) {
 $value=$Content|ConvertFrom-Json
 if($value.app -cne 'dekaron-directory' -or $value.version -ne 1 -or $value.protocol -ne 1){throw 'Incompatible server directory.'}
 $safe=@();foreach($entry in $value.servers){
  if($entry.requiresInvite -isnot [bool] -or -not (($entry.hostMode -ceq 'open' -and -not $entry.requiresInvite) -or ($entry.hostMode -ceq 'friends' -and $entry.requiresInvite)) -or ($entry.version -isnot [int] -and $entry.version -isnot [long]) -or $entry.version -ne 1 -or ($entry.protocol -isnot [int] -and $entry.protocol -isnot [long]) -or $entry.protocol -ne 1){continue}
  try{$url=ConvertTo-FriendsUrl $entry.url;if(([Uri]$url).Scheme -cne 'https'){continue};$safe+=[pscustomobject]@{name=[string]$entry.name;url=$url;players=$entry.players;rates=$entry.rates;hostMode=$entry.hostMode;requiresInvite=$entry.requiresInvite}}catch{}
 };return $safe
}
# Automatic list fetch (item 1): when the Worlds screen opens, the list is pulled from the directory the PLAYER configured in Settings.
# Non-blocking (async HttpClient + timer), no redirects, at most one automatic request per minute per address (the directory rate-limits readers too).
function Start-PublicListFetch([bool]$Force=$false,[scriptblock]$Done=$null) {
 if(-not $script:publicDirectory){return}
 $address=$script:publicDirectory.Text.Trim()
 if(-not $address){$script:publicListStatus='No directory set. Add one in Settings > Public server list to see public worlds here.';return}
 try{$uri=ConvertTo-PublicDirectoryUri $address}catch{$script:publicListStatus=$_.Exception.Message;return}
 if($script:publicFetchTask -and -not $script:publicFetchTask.IsCompleted){return}
 if(-not $Force -and $script:publicFetchAddress -ceq $address -and $script:publicFetchAt -and ([DateTime]::UtcNow-$script:publicFetchAt).TotalSeconds -lt 60){return}
 $script:publicFetchAddress=$address;$script:publicFetchAt=[DateTime]::UtcNow;$script:publicListStatus='Loading the public list...'
 Add-Type -AssemblyName System.Net.Http
 $handler=New-Object Net.Http.HttpClientHandler;$handler.AllowAutoRedirect=$false
 $script:publicFetchClient=New-Object Net.Http.HttpClient($handler);$script:publicFetchClient.Timeout=[TimeSpan]::FromSeconds(8)
 $script:publicFetchTask=$script:publicFetchClient.GetStringAsync($uri.AbsoluteUri+'api/servers');$script:publicFetchDone=$Done
 if($script:publicFetchTimer){$script:publicFetchTimer.Stop();$script:publicFetchTimer.Dispose()}
 $script:publicFetchTimer=New-Object Windows.Forms.Timer;$script:publicFetchTimer.Interval=150
 $script:publicFetchTimer.Add_Tick({
  if(-not $script:publicFetchTask -or -not $script:publicFetchTask.IsCompleted){return}
  $script:publicFetchTimer.Stop();$ok=$false
  try{$script:publicServerRows=@(ConvertFrom-PublicDirectoryContent ($script:publicFetchTask.GetAwaiter().GetResult()));Update-PublicServerFilter;$ok=$true;$script:publicListStatus='It works: '+@($script:publicServerRows).Count+' public server(s) listed.'}
  catch{$script:publicListStatus='The directory did not answer correctly ('+$(if($_.Exception.InnerException){$_.Exception.InnerException.Message}else{$_.Exception.Message})+').'}
  finally{$script:publicFetchClient.Dispose();$script:publicFetchClient=$null}
  if($script:friendsResult -and $script:friendsPanel.Visible -and $script:friendsMode -eq 'connect'){$script:friendsResult.Text=$script:publicListStatus}
  if($script:publicFetchDone){try{& $script:publicFetchDone $ok $script:publicListStatus}catch{}}
 });$script:publicFetchTimer.Start()
}
function Update-PublicServerFilter {
 $selected=$script:publicList.SelectedItem;$query=$script:publicSearch.Text.Trim();$script:publicList.BeginUpdate()
 try{$script:publicList.Items.Clear();foreach($entry in @($script:publicServerRows)){if(-not $query -or ([string]$entry.name).IndexOf($query,[StringComparison]::OrdinalIgnoreCase) -ge 0 -or ([string]$entry.url).IndexOf($query,[StringComparison]::OrdinalIgnoreCase) -ge 0){[void]$script:publicList.Items.Add($entry);if($selected -and $selected.url -ceq $entry.url){$script:publicList.SelectedItem=$entry}}}}finally{$script:publicList.EndUpdate()}
}
function Initialize-PublicServerControls {
 $script:publicPanel=New-Object GalaxyPanel;$script:publicPanel.Location=New-Object Drawing.Point(690,155);$script:publicPanel.Size=New-Object Drawing.Size(270,410);$script:publicPanel.BackColor=$ink;$script:publicPanel.Visible=$false;$form.Controls.Add($script:publicPanel)
 $directory=New-Object GalaxyTextBox;$directory.Location=New-Object Drawing.Point(12,36);$directory.Size=New-Object Drawing.Size(246,26);$directory.Text=$env:DEKARON_DIRECTORY_URL;$script:publicPanel.Controls.Add($directory)
 $label=New-Object Windows.Forms.Label;$label.Text='Listed servers / HTTPS directory';$label.ForeColor=$gold;$label.Location=New-Object Drawing.Point(12,10);$label.Size=New-Object Drawing.Size(246,22);$script:publicPanel.Controls.Add($label)
 $load=New-Object RoundedLauncherButton;$load.Text='Refresh list';$load.Location=New-Object Drawing.Point(12,70);$script:publicPanel.Controls.Add($load)
 $list=New-Object GalaxyListBox;$list.Location=New-Object Drawing.Point(12,151);$list.Size=New-Object Drawing.Size(246,177);$list.DisplayMember='name';$list.FormattingEnabled=$true;$list.Add_Format({param($sender,$e);$e.Value=Format-ServerRowText $e.ListItem $e.Value});$script:publicPanel.Controls.Add($list)
 $choose=New-Object RoundedLauncherButton;$choose.Text='Select server';$choose.Location=New-Object Drawing.Point(12,340);$choose.Size=New-Object Drawing.Size(246,32);$script:publicPanel.Controls.Add($choose)
 $script:publicDirectory=$directory;$script:publicList=$list;$script:publicServerRows=@();$directory.TabIndex=0;$load.TabIndex=1;$list.TabIndex=3;$choose.TabIndex=4
 $searchLabel=New-Object Windows.Forms.Label;$searchLabel.Text='Search name or address';$searchLabel.ForeColor=$muted;$searchLabel.Location=New-Object Drawing.Point(12,104);$searchLabel.Size=New-Object Drawing.Size(246,18);$script:publicPanel.Controls.Add($searchLabel)
 $script:publicSearch=New-Object GalaxyTextBox;$script:publicSearch.AccessibleName='Search public servers by name or address';$script:publicSearch.TabIndex=2;$script:publicSearch.MaxLength=256;$script:publicSearch.Location=New-Object Drawing.Point(12,124);$script:publicSearch.Size=New-Object Drawing.Size(246,24);$script:publicPanel.Controls.Add($script:publicSearch);$script:publicSearch.Add_TextChanged({Update-PublicServerFilter})
 $load.Add_Click({if($script:busy){return};Start-PublicListFetch $true})
 $choose.Add_Click({$list=$script:publicList;if($script:busy -or -not $list.SelectedItem){return};try{$selected=Join-FriendsGame $clientEngine $list.SelectedItem.url;Save-ClientHostPreferences @{kind='remote';url=$selected.url;name=$selected.metadata.name};$script:publicPanel.Visible=$false;Show-RemoteWorldDashboard $selected.url $selected.metadata;Show-NativeAuthPanel $selected.url $true $selected.metadata}catch{$script:friendsResult.Text=$_.Exception.Message}})
 $script:publicTab=New-Object RoundedLauncherButton;$script:publicTab.Text='Public Servers';$script:publicTab.Location=New-Object Drawing.Point(180,70);$script:publicTab.Size=New-Object Drawing.Size(146,30);$script:friendsPanel.Controls.Add($script:publicTab);$script:publicTab.Add_Click({if(-not $script:busy){$script:publicPanel.Visible=-not $script:publicPanel.Visible;$script:publicPanel.BringToFront()}})
}function Initialize-RelayControls {
 $script:onlineToggle=New-Object Windows.Forms.CheckBox;$script:onlineToggle.Text='Online relay (managed HTTPS)';$script:onlineToggle.Location=New-Object Drawing.Point(14,205);$script:onlineToggle.Size=New-Object Drawing.Size(250,24);$script:onlineToggle.ForeColor=$gold;$script:ratesPanel.Controls.Add($script:onlineToggle)
 $script:relayOrigin=New-Object GalaxyTextBox;$script:relayOrigin.Location=New-Object Drawing.Point(14,260);$script:relayOrigin.Size=New-Object Drawing.Size(250,26);$script:ratesPanel.Controls.Add($script:relayOrigin)
 $label=New-Object Windows.Forms.Label;$label.Text='Your HTTPS relay hostname';$label.ForeColor=$muted;$label.Location=New-Object Drawing.Point(14,236);$label.Size=New-Object Drawing.Size(250,22);$script:ratesPanel.Controls.Add($label)
 $script:relayToken=New-Object GalaxyTextBox;$script:relayToken.Location=New-Object Drawing.Point(14,315);$script:relayToken.Size=New-Object Drawing.Size(210,26);$script:ratesPanel.Controls.Add($script:relayToken)
 $label=New-Object Windows.Forms.Label;$label.Text='Token file / ingress port 7840';$label.ForeColor=$muted;$label.Location=New-Object Drawing.Point(14,292);$label.Size=New-Object Drawing.Size(250,22);$script:ratesPanel.Controls.Add($label)
 $browse=New-Object RoundedLauncherButton;$browse.Text='...';$browse.Location=New-Object Drawing.Point(230,315);$browse.Size=New-Object Drawing.Size(34,26);$script:ratesPanel.Controls.Add($browse);$browse.Add_Click({if($script:busy){return};$picker=New-Object Windows.Forms.OpenFileDialog;try{if($picker.ShowDialog($form) -eq 'OK'){$script:relayToken.Text=$picker.FileName}}finally{$picker.Dispose()}})
 $script:listToggle=New-Object Windows.Forms.CheckBox;$script:listToggle.Text='List publicly (optional)';$script:listToggle.Location=New-Object Drawing.Point(14,356);$script:listToggle.Size=New-Object Drawing.Size(250,24);$script:listToggle.ForeColor=$gold;$script:ratesPanel.Controls.Add($script:listToggle)
 $directoryLabel=New-Object Windows.Forms.Label;$directoryLabel.Text='HTTPS directory root';$directoryLabel.ForeColor=$muted;$directoryLabel.Location=New-Object Drawing.Point(14,380);$directoryLabel.Size=New-Object Drawing.Size(250,18);$script:ratesPanel.Controls.Add($directoryLabel)
 $script:listDirectory=New-Object GalaxyTextBox;$script:listDirectory.Text=$env:DEKARON_DIRECTORY_URL;$script:listDirectory.Location=New-Object Drawing.Point(14,401);$script:listDirectory.Size=New-Object Drawing.Size(250,26);$script:ratesPanel.Controls.Add($script:listDirectory)
 $script:relayPreferencesDirty=$false;Restore-ClientRelayPreferences;Update-RelayPublicationEligibility
 $changed={if($script:restoringRelayPreferences){return};$script:relayPreferencesDirty=$true;Update-RelayPublicationEligibility;try{Save-ClientRelayControlPreferences}catch{}}
 # Turning public listing ON always goes through the warning (or an existing consent record for this exact directory).
 $script:listToggle.Add_CheckedChanged({if($script:restoringRelayPreferences -or -not $script:listToggle.Checked){return};if(-not (Confirm-PublicListingConsent $script:listDirectory.Text)){$script:restoringRelayPreferences=$true;try{$script:listToggle.Checked=$false}finally{$script:restoringRelayPreferences=$false}}})
 $script:onlineToggle.Add_CheckedChanged($changed);$script:listToggle.Add_CheckedChanged($changed);$script:hostAccess.Add_SelectedIndexChanged($changed)
 foreach($control in @($script:relayOrigin,$script:relayToken,$script:listDirectory)){$control.Add_TextChanged($changed)}
}
function ConvertTo-ClientRelayOrigin([string]$Value) {
 $uri=$null;$ip=$null
 if(-not [Uri]::TryCreate($Value,[UriKind]::Absolute,[ref]$uri) -or $uri.Scheme -cne 'https' -or $uri.UserInfo -or $uri.Query -or $uri.Fragment -or $uri.AbsolutePath -ne '/' -or -not $uri.IsDefaultPort -or $uri.IsLoopback -or [Net.IPAddress]::TryParse($uri.DnsSafeHost,[ref]$ip) -or $uri.DnsSafeHost.EndsWith('.localhost',[StringComparison]::OrdinalIgnoreCase) -or $uri.DnsSafeHost -notmatch '^([a-z0-9](?:[a-z0-9-]{0,61}[a-z0-9])?\.)+[a-z]{2,63}$' -or $uri.DnsSafeHost.Length -gt 253){throw 'Use a public HTTPS hostname without credentials or extra paths.'}
 return $uri.GetLeftPart([UriPartial]::Authority)
}
function ConvertTo-SafeListingConsent($Value) {
 if($null -eq $Value){return $null}
 try{
  if(($Value.version -isnot [int] -and $Value.version -isnot [long]) -or $Value.version -ne 1){return $null}
  $when=[DateTime]::MinValue;if(-not [DateTime]::TryParseExact([string]$Value.acceptedAt,'yyyy-MM-dd''T''HH:mm:ss''Z''',[Globalization.CultureInfo]::InvariantCulture,[Globalization.DateTimeStyles]::AssumeUniversal -bor [Globalization.DateTimeStyles]::AdjustToUniversal,[ref]$when)){return $null}
  if($when -gt [DateTime]::UtcNow.AddDays(1) -or $when -lt [DateTime]'2026-01-01'){return $null}
  $directory=(ConvertTo-ClientRelayOrigin ([string]$Value.directory))+'/'
  return @{version=1;acceptedAt=$when.ToString('yyyy-MM-dd''T''HH:mm:ss''Z''',[Globalization.CultureInfo]::InvariantCulture);directory=$directory}
 }catch{return $null}
}
function ConvertTo-SafeClientHosting($Value) {
 if($null -eq $Value){return $null}
 if($Value.mode -cnotin @('invite','open')){throw 'Invalid saved host mode.'}
 $safe=@{mode=[string]$Value.mode}
 # Public-listing consent record (item 1): written only after the warning dialog is accepted. Anything malformed reads as "no consent".
 $consent=ConvertTo-SafeListingConsent $Value.listingConsent;if($consent){$safe.listingConsent=$consent}
 # The directory the player configured in Settings (fetches the Worlds list and is where a consenting host lists itself).
 if($Value.listDirectory){try{$safe.listDirectory=(ConvertTo-ClientRelayOrigin ([string]$Value.listDirectory))+'/'}catch{}}
 # Relay-only is the default; direct LAN binding is an explicit opt-in.
 $safe.allowLan=($Value.allowLan -is [bool] -and $Value.allowLan)
 if($null -eq $Value.relay){return $safe}
 $relay=$Value.relay;$origin=ConvertTo-ClientRelayOrigin ([string]$relay.publicOrigin)
 if(($relay.publish -isnot [bool])){throw 'Invalid saved public listing choice.'}
 $token=[string]$relay.tokenFile
 if(-not $token -or $token.Length -gt 1024 -or $token -match '[\x00-\x1f\x7f]' -or -not [IO.Path]::IsPathRooted($token) -or $token.StartsWith('\\') -or $token -notmatch '^[a-z]:[\\/]'){throw 'Choose a private local token-file path.'}
 $token=[IO.Path]::GetFullPath($token)
 $directory='';if($relay.directory){try{$directory=(ConvertTo-ClientRelayOrigin ([string]$relay.directory))+'/'}catch{if($relay.publish){throw}}}
 if($relay.publish -and -not $directory){throw 'Public listing needs an HTTPS directory root.'}
 # Listing needs a consent record for exactly this directory; without it the choice reads back as OFF.
 $listed=[bool]$relay.publish -and $consent -and $consent.directory -ceq $directory
 $safe.relay=@{publicOrigin=$origin;tokenFile=$token;publish=[bool]$listed;directory=$directory};return $safe
}
function Test-PublicListingConsent([string]$Directory) {
 try{$dir=(ConvertTo-ClientRelayOrigin $Directory)+'/'}catch{return $false}
 $c=ConvertTo-SafeListingConsent $script:listingConsent
 return [bool]($c -and $c.directory -ceq $dir)
}
function Get-PublicListingWarningText([string]$Directory) {
 return ("If you continue, anyone who uses this directory will see your server:`r`n"+$Directory+"`r`n`r`n"+
  "Shown publicly: your server name, your relay address, how many players are online, your EXP / DIL / Drop rates, and whether a server password is required.`r`n`r`n"+
  "- Open worlds allow anyone to create accounts and join. Password-protected worlds still require your server password; that password is never listed.`r`n"+
  "- Your home IP address is never published, because players connect through your relay. Your relay provider does see every player's IP address.`r`n"+
  "- A relay can still be attacked. Nothing is impossible to DDoS.`r`n"+
  "- You are responsible for who you let in and for the game files your server sends (see docs\HOSTING.md).`r`n"+
  "- You can turn listing off at any time in Settings > Public server list. Your server then leaves the list within about 90 seconds.`r`n`r`n"+
  "Nothing is listed unless you press the button below.")
}
function Confirm-PublicListingConsent([string]$Directory) {
 try{$dir=(ConvertTo-ClientRelayOrigin $Directory)+'/'}catch{[void][Windows.Forms.MessageBox]::Show($form,'Enter the HTTPS address of the directory first (Settings > Public server list).','Public server list','OK','Information');return $false}
 if(Test-PublicListingConsent $dir){return $true}
 $accepted=$false
 if($script:listingConsentPrompt){$accepted=[bool](& $script:listingConsentPrompt $dir (Get-PublicListingWarningText $dir))}
 else{
  $dialog=New-Object Windows.Forms.Form;$dialog.Text='List your server publicly?';$dialog.ClientSize=New-Object Drawing.Size(600,420);$dialog.StartPosition='CenterParent';$dialog.Font=New-Object Drawing.Font('Segoe UI',10);$dialog.BackColor=$ink;$dialog.ForeColor=$form.ForeColor;$dialog.MinimizeBox=$false;$dialog.MaximizeBox=$false;$dialog.ShowInTaskbar=$false
  $body=New-Object GalaxyTextBox;$body.Multiline=$true;$body.ReadOnly=$true;$body.ScrollBars='Vertical';$body.WordWrap=$true;$body.Location=New-Object Drawing.Point(16,16);$body.Size=New-Object Drawing.Size(568,340);$body.BackColor=[Drawing.Color]::FromArgb(24,29,39);$body.ForeColor=$form.ForeColor;$body.Text=Get-PublicListingWarningText $dir;$dialog.Controls.Add($body)
  $yes=New-Object RoundedLauncherButton;$yes.Text='List my server';$yes.Location=New-Object Drawing.Point(16,370);$yes.Size=New-Object Drawing.Size(200,34);$yes.ForeColor=$gold;$yes.DialogResult='Yes';$dialog.Controls.Add($yes)
  $no=New-Object RoundedLauncherButton;$no.Text='Cancel';$no.Location=New-Object Drawing.Point(464,370);$no.Size=New-Object Drawing.Size(120,34);$no.DialogResult='Cancel';$dialog.Controls.Add($no);$dialog.CancelButton=$no;$dialog.ActiveControl=$no;$body.TabStop=$false
  try{$accepted=([string]$dialog.ShowDialog($form) -eq 'Yes')}finally{$dialog.Dispose()}
 }
 if(-not $accepted){return $false}
 $script:listingConsent=@{version=1;acceptedAt=[DateTime]::UtcNow.ToString('yyyy-MM-dd''T''HH:mm:ss''Z''',[Globalization.CultureInfo]::InvariantCulture);directory=$dir}
 try{Update-ClientHostingPrefs @{listingConsent=$script:listingConsent}}catch{}
 return $true
}
function Update-RelayPublicationEligibility {
 if(-not $script:listToggle -or -not $script:onlineToggle -or -not $script:hostAccess){return}
 # A listing never removes the server-password gate.
 $script:listToggle.Enabled=$script:onlineToggle.Checked
 if(-not $script:listToggle.Enabled){$script:listToggle.Checked=$false}
}
function Get-ClientStoredHostMode {
 $file=Join-Path $clientEngine 'server\friends-host.json';Assert-ClientPathUnlinked $file
 if(-not (Test-Path -LiteralPath $file -PathType Leaf)){return ''}
 if((Get-Item -LiteralPath $file).Length -gt 65536){return ''}
 $value=Get-Content -LiteralPath $file -Raw|ConvertFrom-Json
 if(($value.version -isnot [int] -and $value.version -isnot [long]) -or ($value.port -isnot [int] -and $value.port -isnot [long]) -or $value.version -ne 1 -or $value.port -ne 7778 -or $value.mode -cnotin @('invite','open')){return ''};return [string]$value.mode
}
function Restore-ClientRelayPreferences {
 if($script:relayPreferencesDirty){return}
 $script:restoringRelayPreferences=$true
 try{
  $script:onlineToggle.Checked=$false;$script:listToggle.Checked=$false
  $prefs=Read-ClientHostPreferences
  if($prefs -and $prefs.hosting){$script:listingConsent=$prefs.hosting.listingConsent;$script:allowLan=[bool]$prefs.hosting.allowLan;if($prefs.hosting.listDirectory){$script:listDirectory.Text=[string]$prefs.hosting.listDirectory;if($script:publicDirectory){$script:publicDirectory.Text=[string]$prefs.hosting.listDirectory}}}
  if(-not $prefs -or -not $prefs.hosting -or -not $prefs.hosting.relay){return}
  $saved=$prefs.hosting.relay;$mode=Get-ClientStoredHostMode
  if($script:friendsConfig -and $script:friendsConfig.configured -and $script:friendsConfig.mode -cin @('open','invite')){$mode=$script:friendsConfig.mode}
  $script:relayOrigin.Text=$saved.publicOrigin;$script:relayToken.Text=$saved.tokenFile;$script:listDirectory.Text=$saved.directory;$script:onlineToggle.Checked=$true
  if($mode){$script:hostAccess.SelectedIndex=$(if($mode -eq 'open'){1}else{0})}
  $script:listToggle.Checked=$mode -cin @('invite','open') -and $saved.publish
 }catch{$script:onlineToggle.Checked=$false;$script:listToggle.Checked=$false}finally{Update-RelayPublicationEligibility;$script:restoringRelayPreferences=$false}
}
function Save-ClientRelayControlPreferences {
 $mode=$(if($script:hostAccess.SelectedIndex -eq 1){'open'}else{'invite'});$relay=$null
 if($script:onlineToggle.Checked){$relay=@{publicOrigin=$script:relayOrigin.Text;tokenFile=$script:relayToken.Text;publish=[bool]$script:listToggle.Checked;directory=$script:listDirectory.Text}}
 $extra=@{listingConsent=$script:listingConsent;listDirectory=$script:listDirectory.Text;allowLan=[bool]$script:allowLan}
 $hosting=@{mode=$mode;relay=$relay}+$extra
 try{$hosting=ConvertTo-SafeClientHosting $hosting}catch{if($script:listToggle.Checked){throw};$hosting=@{mode=$mode}+$extra;try{$hosting=ConvertTo-SafeClientHosting $hosting}catch{$hosting=@{mode=$mode}}}
 Save-ClientHostPreferences @{kind='host';hosting=$hosting}
}
function Set-PendingRelayConfiguration {
 $script:relayConfig=$null
 if(-not $script:onlineToggle.Checked){if($script:listToggle.Checked){throw 'Public listing needs an online relay.'};return}
 $origin=[Uri](ConvertTo-ClientRelayOrigin $script:relayOrigin.Text)
 $token=[IO.Path]::GetFullPath($script:relayToken.Text);Assert-ClientPathUnlinked $token;if(-not (Test-Path -LiteralPath $token -PathType Leaf)){throw 'Select your private cloudflared token file.'}
 # Both access modes may opt in; discovery preserves requiresInvite.
 if($script:listToggle.Checked){[void](ConvertTo-ClientRelayOrigin $script:listDirectory.Text)}
 $bytes=New-Object byte[] 32;$rng=[Security.Cryptography.RandomNumberGenerator]::Create();try{$rng.GetBytes($bytes)}finally{$rng.Dispose()}
 $script:relayConfig=@{publicOrigin=$origin.GetLeftPart([UriPartial]::Authority);tokenFile=$token;secret=([BitConverter]::ToString($bytes).Replace('-','').ToLowerInvariant());mode='named';publish=$script:listToggle.Checked;directory=$script:listDirectory.Text}
}function Save-ClientHostPreferences($Value) {
 $existing=Read-ClientHostPreferences;$servers=@();if($Value.kind -eq 'remote'){$servers+=@{url=(ConvertTo-FriendsUrl ([string]$Value.url));name=[string]$Value.name}};if($existing){$servers+=@($existing.servers)}
 $hosting=$existing.hosting
 if($Value -is [Collections.IDictionary] -and $Value.Contains('hosting') -or $Value.PSObject.Properties.Name -contains 'hosting'){$hosting=$Value.hosting}
 elseif($Value.relay){$hosting=@{mode=$Value.mode;relay=$Value.relay;listingConsent=$(if($script:listingConsent){$script:listingConsent}else{$existing.hosting.listingConsent});listDirectory=$(if($script:listDirectory -and $script:listDirectory.Text){$script:listDirectory.Text}else{$existing.hosting.listDirectory});allowLan=$(if($script:allowLan){$true}else{[bool]$existing.hosting.allowLan})}}
 $Value=ConvertTo-SafeClientPreferences ([pscustomobject]@{version=2;kind=$Value.kind;url=$Value.url;servers=$servers;hosting=$hosting})
 $folder=Join-Path $clientEngine 'server';Assert-ClientPathUnlinked $folder;[void][IO.Directory]::CreateDirectory($folder)
 $file=Join-Path $folder 'launcher-preferences.json';Assert-ClientPathUnlinked $file;$temporary=$file+'.'+[Guid]::NewGuid().ToString('N')+'.tmp'
 try{[IO.File]::WriteAllText($temporary,($Value|ConvertTo-Json -Depth 6),[Text.UTF8Encoding]::new($false));Move-Item -LiteralPath $temporary -Destination $file -Force}finally{if(Test-Path -LiteralPath $temporary){Remove-Item -LiteralPath $temporary}}
}
function Read-ClientHostPreferences {
 $file=Join-Path $clientEngine 'server\launcher-preferences.json';Assert-ClientPathUnlinked $file
 if(-not (Test-Path -LiteralPath $file -PathType Leaf)){return $null};if((Get-Item -LiteralPath $file).Length -gt 16384){throw 'Invalid saved hosting preferences.'}
 return ConvertTo-SafeClientPreferences (Get-Content -LiteralPath $file -Raw|ConvertFrom-Json)
}
function ConvertTo-SafeClientPreferences($Value) {
 if($Value.version -notin @(1,2) -or $Value.kind -notin @('local','remote','host')){throw 'Invalid saved hosting preferences.'}
 $servers=@();$seen=@{};$entries=$(if($Value.version -eq 1 -and $Value.kind -eq 'remote'){@([pscustomobject]@{url=$Value.url;name=$Value.url})}else{@($Value.servers)})
 foreach($entry in $entries){if($null -eq $entry){continue};$url=ConvertTo-FriendsUrl ([string]$entry.url);if($seen.ContainsKey($url)){continue};$seen[$url]=$true;$name=([string]$entry.name -replace '[\x00-\x1f\x7f]','').Trim();if(-not $name){$name=$url};if($name.Length -gt 96){$name=$name.Substring(0,96)};$servers+=@{url=$url;name=$name};if($servers.Count -ge 12){break}}
 $safe=@{version=2;kind=[string]$Value.kind;servers=@($servers)};if($safe.kind -eq 'remote'){$safe.url=ConvertTo-FriendsUrl ([string]$Value.url)};if($Value.version -eq 2 -and $Value.hosting){$safe.hosting=ConvertTo-SafeClientHosting $Value.hosting};return $safe
}
function Update-SavedServerControls {
 if(-not $script:savedServers){return};$script:savedServers.Items.Clear();$prefs=Read-ClientHostPreferences
 if($prefs){foreach($entry in $prefs.servers){[void]$script:savedServers.Items.Add([pscustomobject]$entry)}}
}
function Show-RemoteWorldDashboard([string]$Url,$Metadata) {
 if($script:serverReady){throw 'Stop your owned server before switching this dashboard to a remote world.'}
 if($script:hostingOptions){$script:hostingOptions.Visible=$true};$script:remoteWorld=$true;$script:remoteMetadata=$Metadata;$script:gameServerUrl=$Url;$script:dashboard=$true;$script:serverReady=$false;$script:runningFriends=$true
 $primary.Text='DX11 Client';$primary.Enabled=$true;$website.Enabled=$true;$stopServer.Visible=$false;$chooseFolder.Visible=$true;$progress.Visible=$false
 $itemBuilderButton.Visible=$false;$mapBuilderButton.Visible=$false;$script:hostButton.Visible=$true;$script:connectButton.Visible=$true;$script:hostTab.Visible=$false;$script:browserLaunch.Visible=$true;$script:localWorld.Visible=$true
 $statusLine.Text=[string]$Metadata.name+' / '+$Url;$footerCopy.Visible=$false
}
function Initialize-RemoteWorldControls {
 $form.Add_FormClosed({if($script:remoteProbeState){$script:remoteProbeState.timer.Stop();$script:remoteProbeState.timer.Dispose();$script:remoteProbeState.request.Abort();$script:remoteProbeState=$null}})
 $script:hostingOptions=New-Object RoundedLauncherButton;$script:hostingOptions.Text='Hosting options';$script:hostingOptions.Location=New-Object Drawing.Point(300,605);$script:hostingOptions.Size=New-Object Drawing.Size(192,26);$script:hostingOptions.FlatStyle='Flat';$script:hostingOptions.BackColor=$ink;$script:hostingOptions.ForeColor=$gold;$form.Controls.Add($script:hostingOptions)
 $script:hostingOptions.Add_Click({
  if($script:busy -or $script:ownerAccountsWorking -or $script:remoteWorld){return}
  if($script:friendsPanel.Visible -and $script:friendsMode -eq 'host'){Show-FriendsPanel 'close'}else{if($script:dashboard -and (Get-Command Show-ClientDashboardTab -ErrorAction SilentlyContinue)){Show-ClientDashboardTab};Show-FriendsPanel 'host'}
  if(Get-Command Update-ClientDashboardView -ErrorAction SilentlyContinue){Update-ClientDashboardView}
 })
 # Dashboard (the same three versions as the sign-in panel, not the old Launch desktop / browser list):
 # big button = DX11 Client (Dekaron.exe), row = Desktop App | Web Browser | Other server... Each opens sign-in with that
 # version as its Enter button. ($script:browserLaunch keeps its name for the other scripts: it is the Desktop App button.)
 $script:browserLaunch=New-Object RoundedLauncherButton;$script:browserLaunch.Text='Desktop App';$script:browserLaunch.Location=New-Object Drawing.Point(300,565);$script:browserLaunch.Size=New-Object Drawing.Size(192,34);$script:browserLaunch.FlatStyle='Flat';$script:browserLaunch.BackColor=$ink;$script:browserLaunch.ForeColor=$gold;$script:browserLaunch.Visible=$false;$form.Controls.Add($script:browserLaunch)
 $script:webLaunch=New-Object RoundedLauncherButton;$script:webLaunch.Text='Web Browser';$script:webLaunch.Location=New-Object Drawing.Point(508,565);$script:webLaunch.Size=New-Object Drawing.Size(192,34);$script:webLaunch.FlatStyle='Flat';$script:webLaunch.BackColor=$ink;$script:webLaunch.ForeColor=$gold;$script:webLaunch.Visible=$false;$form.Controls.Add($script:webLaunch)
 $script:browserLaunch.Add_VisibleChanged({$script:webLaunch.Visible=$script:browserLaunch.Visible})
 $script:localWorld=New-Object RoundedLauncherButton;$script:localWorld.Text='Local world';$script:localWorld.Location=New-Object Drawing.Point(704,605);$script:localWorld.Size=New-Object Drawing.Size(140,34);$script:localWorld.Visible=$false;$form.Controls.Add($script:localWorld)
 $script:localWorld.Add_Click({if($script:busy){return};Save-ClientHostPreferences @{version=1;kind='local'};$script:remoteWorld=$false;$script:dashboard=$false;$script:gameServerUrl=$null;$script:remoteMetadata=$null;$script:localWorld.Visible=$false;$script:browserLaunch.Visible=$false;$primary.Text='Start';$primary.Enabled=$script:planValid;$chooseFolder.Visible=$true;$script:hostButton.Visible=$true;$script:connectButton.Visible=$true;$progress.Visible=-not $script:cachedReady;$script:hostingOptions.Visible=$true;$statusLine.Text='Local play selected.'})
 $script:browserLaunch.Add_Click({if($script:busy){return};$url=$(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl});Show-NativeAuthPanel $url $script:runningFriends $script:remoteMetadata $false $false 'desktop'})
 $script:webLaunch.Add_Click({if($script:busy){return};$url=$(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl});Show-NativeAuthPanel $url $script:runningFriends $script:remoteMetadata $false $true 'browser'})
 Initialize-ExtraClientControls
 Initialize-ServerLiveStatus
}
# Live server status: lists show real online/offline and player counts read from each server's own status endpoint
# (/api/friends/status, the same data the public directory relays) and refresh while a list is on screen. Probing is
# parallel and harvested by a timer, so the launcher never freezes on a slow or offline server.
$script:serverLive=@{};$script:serverLiveProbe=$null;$script:serverLiveNext=[datetime]::MinValue;$script:serverLiveSignature=''
function ConvertTo-ServerPopulation($Status,[bool]$Online=$true) {
 # Only authoritative integer aggregates are accepted. Older hosts expose a
 # total but no split; unknown bot counts must never be presented as zero.
 $state=[pscustomobject]@{online=$Online;players=$null;realPlayers=$null;botPlayers=$null;populationKnown=$false;name=$null}
 if(-not $Online -or -not $Status){return $state}
 function Valid-PopulationCount($Value){return (($Value -is [int] -or $Value -is [long]) -and $Value -ge 0 -and $Value -le 100000)}
 if(Valid-PopulationCount $Status.players){$state.players=[int]$Status.players}
 if($null -ne $state.players -and (Valid-PopulationCount $Status.realPlayers) -and (Valid-PopulationCount $Status.botPlayers) -and ([long]$Status.realPlayers+[long]$Status.botPlayers) -eq $state.players){
  $state.realPlayers=[int]$Status.realPlayers;$state.botPlayers=[int]$Status.botPlayers;$state.populationKnown=$true
 }
 if($Status.name -is [string] -and $Status.name.Length -le 64 -and $Status.name -notmatch '[\x00-\x1f\x7f]'){$state.name=$Status.name.Trim()}
 return $state
}
function Format-ServerPopulationText($State,[switch]$Compact) {
 if(-not $State){return 'Checking population...'}
 if(-not $State.online){return 'Server offline'}
 if($State.populationKnown){
  if($Compact){return ([string]$State.realPlayers)+' real / '+$State.botPlayers+' bots'}
  return 'Real players: '+$State.realPlayers+'  |  Bots: '+$State.botPlayers+'  |  Total: '+$State.players
 }
 if($null -ne $State.players){return 'Total: '+$State.players+'  |  Real players / bots: unknown'}
 return 'Online - population unavailable'
}
function Format-ServerStatusText($State) {
 if(-not $State){return ''}
 if(-not $State.online){return 'offline'}
 if($State.populationKnown){return Format-ServerPopulationText $State -Compact}
 if($null -ne $State.players){return ([string]$State.players)+' online'}
 return 'online'
}
function Update-ClientPopulationTile($State) {
 # ENGINE-CHOSEN layout: use the existing fading GalaxyPanel tile. Labels are
 # transparent; there is no PictureBox, foreign bitmap or opaque white inlay.
 $value=$script:dashboardPlayersValue;if(-not $value){return}
 if(-not $script:dashboardPopulationTotal){
  $value.Font=New-Object Drawing.Font('Segoe UI',13)
  $value.AccessibleName='Real players and bots online'
  $detail=New-Object Windows.Forms.Label;$detail.UseMnemonic=$false;$detail.Name='populationTotal';$detail.AccessibleName='Total active players';$detail.BackColor=[Drawing.Color]::Transparent;$detail.ForeColor=$value.ForeColor;$detail.Font=New-Object Drawing.Font('Segoe UI',9)
  $detail.Bounds=New-Object Drawing.Rectangle($value.Left,($value.Top+$value.Height),$value.Width,18)
  $value.Parent.Controls.Add($detail);$script:dashboardPopulationTotal=$detail
 }
 $value.Text=$(if(-not $State){'Checking...'}elseif(-not $State.online){'Offline'}elseif($State.populationKnown){'Real: '+$State.realPlayers+'  |  Bots: '+$State.botPlayers}else{'Real / bots: unknown'})
 $script:dashboardPopulationTotal.Text=$(if($State -and $State.online -and $null -ne $State.players){'Total online: '+$State.players}elseif($State -and $State.online){'Total unavailable'}else{''})
 $value.AccessibleDescription=Format-ServerPopulationText $State
 $script:dashboardPopulationTotal.AccessibleDescription=$script:dashboardPopulationTotal.Text
}
function Format-ServerRowText($Item,$Text) {
 $state=$null;if($Item -and $Item.url){$state=$script:serverLive[[string]$Item.url]}
 $suffix=Format-ServerStatusText $state
 if(-not $suffix -and $Item -and $null -ne $Item.players -and ([string]$Item.players) -match '^\d{1,6}$'){$suffix=([string]$Item.players)+' online'}
 if($Item -and $Item.requiresInvite -is [bool]){$access=$(if($Item.requiresInvite){'Password required'}else{'Open'});$suffix=$(if($suffix){$access+' - '+$suffix}else{$access})}
 if(-not $suffix){return $Text}
 return ([string]$Text)+' - '+$suffix
}
function Start-ServerLiveProbe([string[]]$Urls,[int]$TimeoutMs=3000) {
 $jobs=@()
 foreach($url in $Urls){
  $job=[pscustomobject]@{url=$url;request=$null;task=$null}
  try{
   $request=[Net.HttpWebRequest][Net.WebRequest]::Create((Get-ClientApiUrl $url)+'api/friends/status')
   $request.Method='GET';$request.AllowAutoRedirect=$false;$request.Timeout=$TimeoutMs;$request.ReadWriteTimeout=$TimeoutMs;$request.Host=([Uri]$url).Authority;$request.UserAgent='DekaronLauncher'
   $job.request=$request;$job.task=$request.GetResponseAsync()
  }catch{}
  $jobs+=$job
 }
 return [pscustomobject]@{jobs=$jobs;deadline=(Get-Date).AddMilliseconds($TimeoutMs+700)}
}
# Returns $null while requests are still in flight, otherwise url -> state (online, players, name).
function Receive-ServerLiveProbe($Probe) {
 $pending=@($Probe.jobs|Where-Object {$_.task -and -not $_.task.IsCompleted})
 if($pending.Count -and (Get-Date) -lt $Probe.deadline){return $null}
 $result=@{}
 foreach($job in $Probe.jobs){
  $state=ConvertTo-ServerPopulation $null $false
  if($job.task -and $job.task.IsCompleted -and -not $job.task.IsFaulted -and -not $job.task.IsCanceled){
   $response=$null;$reader=$null
   try{
    $response=$job.task.Result;$reader=New-Object IO.StreamReader($response.GetResponseStream(),[Text.Encoding]::UTF8)
    $buffer=New-Object char[] 65536;$count=$reader.Read($buffer,0,$buffer.Length);$status=(New-Object string($buffer,0,[Math]::Max(0,$count)))|ConvertFrom-Json
    if($status.app -ceq 'dekaron-engine'){$state=ConvertTo-ServerPopulation $status}
   }catch{}finally{if($reader){$reader.Dispose()};if($response){$response.Close()}}
  }elseif($job.request -and $job.task -and -not $job.task.IsCompleted){try{$job.request.Abort()}catch{}}
  $result[$job.url]=$state
 }
 return $result
}
function Get-LocalWorldPopulation {
 if(-not $script:serverReady -or $script:remoteWorld -or -not $script:serverUrl -or -not $script:runningPlan){return $null}
 try{
  $control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl
  $status=Invoke-RestMethod -Uri ((Get-ClientApiUrl $script:serverUrl)+'api/launcher/status') -Headers @{'x-dekaron-launcher-token'=$control.token;Host=([Uri]$script:serverUrl).Authority} -MaximumRedirection 0 -TimeoutSec 2
  if($status.name -is [string] -and $status.name.Trim() -and $status.name.Length -le 64 -and $status.name -notmatch '[\x00-\x1f\x7f]'){$script:localServerName=$status.name.Trim();$script:localServerNameUrl=$script:serverUrl}
  return ConvertTo-ServerPopulation $status
 }catch{}
 return $null
}
function Get-LocalWorldPlayers {
 # Existing capacity consumers still receive the total number, never the split.
 $state=Get-LocalWorldPopulation;if($state){return $state.players};return $null
}
function Update-ServerLiveViews {
 foreach($view in @($script:extraServer,$script:publicList,$script:savedServers)){if($view){$view.Invalidate()}}
 if(-not $script:onlineLabel){return}
 $text=''
 if($script:dashboard){
  $url=$(if($script:remoteWorld){$script:gameServerUrl}else{$script:serverUrl});$state=$(if($url){$script:serverLive[[string]$url]})
  $text=Format-ServerPopulationText $state
 }
 $script:onlineLabel.Text=$text
 $script:onlineLabel.AccessibleName='Real players and bots online';$script:onlineLabel.AccessibleDescription=$text
}
function Invoke-ServerLiveTick {
 $targets=@()
 if($script:extraPanel -and $script:extraPanel.Visible){$targets+=@($script:extraServer.Items|Where-Object {-not $_.local}|ForEach-Object {$_.url})}
 if($script:publicPanel -and $script:publicPanel.Visible){$targets+=@($script:publicServerRows|ForEach-Object {$_.url})}
 if($script:friendsPanel -and $script:friendsPanel.Visible -and $script:savedServers -and $script:savedServers.Visible){$targets+=@($script:savedServerRows|ForEach-Object {$_.url})}
 if((($script:onlineLabel -and $script:onlineLabel.Visible) -or ($script:clientDashboardPanel -and $script:clientDashboardPanel.Visible)) -and $script:remoteWorld -and $script:gameServerUrl){$targets+=$script:gameServerUrl}
 $targets=@($targets|Where-Object {$_ -and ([string]$_) -match '^https?://'}|Select-Object -Unique -First 24)
 if($script:serverLiveProbe){
  $result=Receive-ServerLiveProbe $script:serverLiveProbe;if($null -eq $result){return}
  foreach($key in @($result.Keys)){$script:serverLive[$key]=$result[$key]}
  $script:serverLiveProbe=$null;$script:serverLiveNext=(Get-Date).AddSeconds(10);Update-ServerLiveViews;return
 }
 $signature=$targets -join '|'
 $needLocal=$script:serverReady -and (($script:onlineLabel -and $script:onlineLabel.Visible) -or ($script:clientDashboardPanel -and $script:clientDashboardPanel.Visible) -or ($script:extraPanel -and $script:extraPanel.Visible))
 if($signature -eq $script:serverLiveSignature -and (Get-Date) -lt $script:serverLiveNext){return}
 if(-not $targets.Count -and -not $needLocal){$script:serverLiveSignature=$signature;$script:serverLiveNext=(Get-Date).AddSeconds(10);return}
 $script:serverLiveSignature=$signature
 if($needLocal){$state=Get-LocalWorldPopulation;if(-not $state){$state=ConvertTo-ServerPopulation $null $false};$script:serverLive[[string]$script:serverUrl]=$state}
 if($targets.Count){$script:serverLiveProbe=Start-ServerLiveProbe $targets}else{$script:serverLiveNext=(Get-Date).AddSeconds(10)}
 Update-ServerLiveViews
}
function Initialize-ServerLiveStatus {
 $script:onlineLabel=New-Object Windows.Forms.Label;$script:onlineLabel.UseMnemonic=$false;$script:onlineLabel.Location=New-Object Drawing.Point(80,372);$script:onlineLabel.Size=New-Object Drawing.Size(840,24);$script:onlineLabel.TextAlign='MiddleCenter';$script:onlineLabel.Font=New-Object Drawing.Font('Segoe UI',10);$script:onlineLabel.ForeColor=$gold;$script:onlineLabel.BackColor=[Drawing.Color]::Transparent;$script:onlineLabel.Visible=$false;$form.Controls.Add($script:onlineLabel)
 $script:browserLaunch.Add_VisibleChanged({if($script:onlineLabel){$script:onlineLabel.Visible=$script:browserLaunch.Visible;Update-ServerLiveViews}})
 $script:onlineLabel.Visible=$script:browserLaunch.Visible
 $script:serverLiveTimer=New-Object Windows.Forms.Timer;$script:serverLiveTimer.Interval=400
 $script:serverLiveTimer.Add_Tick({try{Invoke-ServerLiveTick}catch{}})
 $form.Add_FormClosed({if($script:serverLiveTimer){$script:serverLiveTimer.Stop();$script:serverLiveTimer.Dispose();$script:serverLiveTimer=$null}})
 if(-not $PreviewPath){$script:serverLiveTimer.Start()}
}
# Extra client: open another game window for ANY server from one dashboard. The player picks the server (this computer's
# world or a saved server), then Desktop client or Browser. Accounts belong to the selected server only, a second sign-in
# to an account that is already connected is refused by that server, so several clients need several accounts.
function Update-ExtraClientServers {
 $items=@();$seen=@{}
 if($script:serverReady -and -not $script:remoteWorld){$url=$(if($script:gameServerUrl){$script:gameServerUrl}else{$script:serverUrl});$items+=[pscustomobject]@{name='This computer - your local world';label='This computer - your local world';url=$url;local=$true;metadata=$null};$seen[$url]=$true}
 if($script:remoteWorld -and $script:gameServerUrl){$name=$(if($script:remoteMetadata.name){[string]$script:remoteMetadata.name}else{[string]$script:gameServerUrl});$items+=[pscustomobject]@{name=$name;label=$name+' - this dashboard';url=$script:gameServerUrl;local=$false;metadata=$script:remoteMetadata};$seen[$script:gameServerUrl]=$true}
 try{$prefs=Read-ClientHostPreferences;if($prefs){foreach($entry in $prefs.servers){if($seen.ContainsKey($entry.url)){continue};$seen[$entry.url]=$true;$items+=[pscustomobject]@{name=[string]$entry.name;label=([string]$entry.name+' - '+$entry.url);url=$entry.url;local=$false;metadata=$null}}}}catch{}
 $script:extraServer.Items.Clear();foreach($item in $items){[void]$script:extraServer.Items.Add($item)}
 if($script:extraServer.Items.Count -gt 0){$script:extraServer.SelectedIndex=0}
 $script:extraStatus.Text=$(if($items.Count -gt 0){'Each client needs its own account on that server.'}else{'No servers yet. Use Connect on the start screen to save one.'})
 $script:extraDesktop.Enabled=$items.Count -gt 0;$script:extraBrowser.Enabled=$items.Count -gt 0
}
function Show-ExtraClientPanel {
 if($script:busy -or -not $script:extraPanel){return}
 Update-ExtraClientServers;$script:serverLiveNext=[datetime]::MinValue
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$progress,$statusLine,$itemBuilderButton,$mapBuilderButton)){if($control){$control.Visible=$false}}
 foreach($control in @($script:browserLaunch,$script:webLaunch,$script:localWorld)){if($control){$control.Visible=$false}}   # the top-row buttons stay
 $script:extraPanel.Visible=$true;$script:extraPanel.BringToFront();[void]$script:extraServer.Focus()
}
function Close-ExtraClientPanel {
 $script:extraPanel.Visible=$false;Close-NativeAuthPanel
}
function Invoke-ExtraClientLaunch([bool]$Browser,[string]$Target='') {
 if($script:busy){return};$item=$script:extraServer.SelectedItem
 if(-not $item){$script:extraStatus.Text='Choose a server first.';return}
 try{
  Assert-ClientServerSwitch $item.url
  if($item.local){$script:extraPanel.Visible=$false;Show-NativeAuthPanel $item.url $script:runningFriends $null $false $Browser $Target}
  else{
   $meta=$item.metadata;$url=$item.url
   if(-not $meta){$script:busy=$true;$script:extraStatus.Text='Checking the server...';$script:extraStatus.Refresh();try{$destination=Join-FriendsGame $clientEngine $item.url;$meta=$destination.metadata;$url=$destination.url}finally{$script:busy=$false}}
   $script:extraPanel.Visible=$false;Show-NativeAuthPanel $url $true $meta $false $Browser $Target
  }
  $statusLine.Text='Sign in with a different account for every client on this server.'
 }catch{$script:extraPanel.Visible=$true;$script:extraPanel.BringToFront();$script:extraStatus.Text=$_.Exception.Message}
}
function Initialize-ExtraClientControls {
 $script:extraClient=New-Object RoundedLauncherButton;$script:extraClient.Text='Other server...';$script:extraClient.Location=New-Object Drawing.Point(704,565);$script:extraClient.Size=New-Object Drawing.Size(140,34);$script:extraClient.FlatStyle='Flat';$script:extraClient.BackColor=$ink;$script:extraClient.ForeColor=$gold;$script:extraClient.Visible=$false;$form.Controls.Add($script:extraClient)
 $script:extraPanel=New-Object GalaxyPanel;$script:extraPanel.Location=New-Object Drawing.Point(300,170);$script:extraPanel.Size=New-Object Drawing.Size(400,330);$script:extraPanel.BackColor=[Drawing.Color]::FromArgb(18,22,30);$script:extraPanel.Visible=$false;$form.Controls.Add($script:extraPanel)
 $title=New-Object Windows.Forms.Label;$title.Text='Open another client';$title.Location=New-Object Drawing.Point(18,14);$title.Size=New-Object Drawing.Size(365,28);$title.Font=New-Object Drawing.Font('Segoe UI',14,[Drawing.FontStyle]::Bold);$title.ForeColor=$gold;$script:extraPanel.Controls.Add($title)
 $intro=New-Object Windows.Forms.Label;$intro.Text="Choose the server for this window, then how to open it. Accounts belong to one server, and an account can only be signed in once, so every extra client needs its own account.";$intro.Location=New-Object Drawing.Point(18,48);$intro.Size=New-Object Drawing.Size(365,64);$intro.ForeColor=$muted;$script:extraPanel.Controls.Add($intro)
 $script:extraServer=New-Object GalaxyComboBox;$script:extraServer.DropDownStyle='DropDownList';$script:extraServer.DisplayMember='label';$script:extraServer.FormattingEnabled=$true;$script:extraServer.Add_Format({param($sender,$e);$item=$e.ListItem;$state=$script:serverLive[[string]$item.url];if($state){$base=$(if($item.local -or -not $state.name){$item.name}else{$state.name});$e.Value=$base+' - '+(Format-ServerStatusText $state)}});$script:extraServer.Location=New-Object Drawing.Point(18,120);$script:extraServer.Size=New-Object Drawing.Size(365,26);$script:extraServer.BackColor=$ink;$script:extraServer.ForeColor=$gold;$script:extraPanel.Controls.Add($script:extraServer)
 $script:extraDesktop=New-Object RoundedLauncherButton;$script:extraNative=New-Object RoundedLauncherButton;$script:extraNative.Text='DX11 Client';$script:extraNative.Location=New-Object Drawing.Point(18,166);$script:extraNative.Size=New-Object Drawing.Size(116,38);$script:extraNative.BackColor=$gold;$script:extraNative.ForeColor=$ink;$script:extraNative.FlatStyle='Flat';$script:extraPanel.Controls.Add($script:extraNative)
 $script:extraDesktop.Text='Desktop App';$script:extraDesktop.Location=New-Object Drawing.Point(141,166);$script:extraDesktop.Size=New-Object Drawing.Size(116,38);$script:extraDesktop.BackColor=$gold;$script:extraDesktop.ForeColor=$ink;$script:extraDesktop.FlatStyle='Flat';$script:extraPanel.Controls.Add($script:extraDesktop)
 $script:extraBrowser=New-Object RoundedLauncherButton;$script:extraBrowser.Text='Web Browser';$script:extraBrowser.Location=New-Object Drawing.Point(264,166);$script:extraBrowser.Size=New-Object Drawing.Size(119,38);$script:extraBrowser.BackColor=$gold;$script:extraBrowser.ForeColor=$ink;$script:extraBrowser.FlatStyle='Flat';$script:extraPanel.Controls.Add($script:extraBrowser)
 $script:extraBack=New-Object RoundedLauncherButton;$script:extraBack.Text='Back';$script:extraBack.Location=New-Object Drawing.Point(18,220);$script:extraBack.Size=New-Object Drawing.Size(365,30);$script:extraBack.FlatStyle='Flat';$script:extraBack.BackColor=$ink;$script:extraBack.ForeColor=$gold;$script:extraPanel.Controls.Add($script:extraBack)
 $script:extraStatus=New-Object Windows.Forms.Label;$script:extraStatus.UseMnemonic=$false;$script:extraStatus.Location=New-Object Drawing.Point(18,262);$script:extraStatus.Size=New-Object Drawing.Size(365,56);$script:extraStatus.ForeColor=$gold;$script:extraPanel.Controls.Add($script:extraStatus)
 $script:extraClient.Add_Click({if(-not $script:busy){Show-ExtraClientPanel}})
 $script:extraNative.Add_Click({Invoke-ExtraClientLaunch $false 'native'})
 $script:extraDesktop.Add_Click({Invoke-ExtraClientLaunch $false 'desktop'})
 $script:extraBrowser.Add_Click({Invoke-ExtraClientLaunch $true 'browser'})
 $script:extraBack.Add_Click({Close-ExtraClientPanel})
 # The button is available wherever "Launch browser" is (every dashboard) and nowhere else.
 $script:browserLaunch.Add_VisibleChanged({if($script:extraClient){$script:extraClient.Visible=$script:browserLaunch.Visible}})
 $script:extraClient.Visible=$script:browserLaunch.Visible
}
function Start-SavedRemoteProbe {
 try{Update-SavedServerControls;$hostConfig=Join-Path $clientEngine 'server\friends-host.json';Assert-ClientPathUnlinked $hostConfig;if(Test-Path -LiteralPath $hostConfig -PathType Leaf){$script:hostButton.Text='Resume host'};$prefs=Read-ClientHostPreferences;if(-not $prefs -or $prefs.kind -ne 'remote'){return};$script:savedRemoteUrl=$prefs.url
  $request=[Net.HttpWebRequest]::Create((Get-ClientApiUrl ($prefs.url+'api/friends/status')));$request.AllowAutoRedirect=$false;$request.Timeout=15000;$request.Host=([Uri]$prefs.url).Authority;$pending=$request.BeginGetResponse($null,$null);$watch=[Diagnostics.Stopwatch]::StartNew()
  $timer=New-Object Windows.Forms.Timer;$timer.Interval=40;$script:remoteProbe=$timer;$script:remoteProbeState=@{request=$request;pending=$pending;watch=$watch;timer=$timer;prefs=$prefs}
  $timer.Add_Tick({param($sender,$eventArgs)
   $state=$script:remoteProbeState;if(-not [object]::ReferenceEquals($sender,$state.timer)){return};$request=$state.request;$pending=$state.pending;$watch=$state.watch;$timer=$state.timer;$prefs=$state.prefs
   if($form.IsDisposed -or $script:busy -or $script:dashboard -or $script:savedRemoteUrl -cne $prefs.url){$timer.Stop();$timer.Dispose();$request.Abort();return}
   if(-not $pending.IsCompleted){if($watch.Elapsed.TotalSeconds -gt 15){$timer.Stop();$timer.Dispose();$request.Abort();$statusLine.Text='Saved web world is offline. Use Connect to retry.'};return}
   $timer.Stop();$timer.Dispose()
   try{$response=$request.EndGetResponse($pending);try{if([int]$response.StatusCode -ne 200){throw 'The saved address must respond directly.'};$reader=New-Object IO.StreamReader($response.GetResponseStream());try{$meta=$reader.ReadToEnd()|ConvertFrom-Json}finally{$reader.Dispose()}}finally{$response.Dispose()}
    if($meta.app -cne 'dekaron-engine' -or $meta.protocol -ne 1 -or $meta.version -ne 1 -or $meta.requiresInvite -isnot [bool] -or -not (($meta.hostMode -ceq 'open' -and -not $meta.requiresInvite) -or ($meta.hostMode -ceq 'friends' -and $meta.requiresInvite))){throw 'Saved URL is not a compatible game server API. A static website cannot host the world.'}
    Stop-ClientReadinessProbe;Show-RemoteWorldDashboard $prefs.url $meta
   }catch{$statusLine.Text='Saved web world could not be verified. Use Connect to check its game API URL.'}
  });$timer.Start()
 }catch{$statusLine.Text='Saved hosting preferences could not be verified.'}
}
