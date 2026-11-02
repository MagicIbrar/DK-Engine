# Private installation-owner dashboard only; game account capabilities never authorize this panel.
function Test-OwnerAccountsContext {
 if(-not $script:dashboard -or -not $script:serverReady -or $script:remoteWorld -or $script:busy -or -not $script:runningPlan -or -not $script:control){return $false}
 try{$uri=[Uri]$script:serverUrl;return $uri.Scheme -eq 'http' -and $uri.IsLoopback -and $script:control.url -ceq $script:serverUrl}catch{return $false}
}
function Update-OwnerAccountsVisibility {
 $show=(Test-OwnerAccountsContext) -and $script:ownerAccountsAvailable
 foreach($other in @($signupPanel,$script:authPanel,$script:friendsPanel)){if($other -and $other.Visible){$show=$false}}
 if($script:ownerAccountsButton){$script:ownerAccountsButton.Visible=$show;$script:ownerAccountsButton.Enabled=$show -and -not $script:ownerAccountsWorking}
 if(-not $show -and $script:ownerAccountsPanel -and $script:ownerAccountsPanel.Visible){Close-OwnerAccountsPanel}
}
function Invoke-OwnerAccountsRequest([string]$Method='GET',$Body=$null) {
 if(-not (Test-OwnerAccountsContext)){throw 'Accounts are available only on your owned local server dashboard.'}
 $control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl
 $args=@{Uri=((Get-ClientApiUrl $script:serverUrl)+'api/launcher/accounts');Method=$Method;Headers=@{'x-dekaron-launcher-token'=$control.token};MaximumRedirection=0;TimeoutSec=15}
 if($Method -eq 'POST'){$args.ContentType='application/json; charset=utf-8';$args.Body=[Text.Encoding]::UTF8.GetBytes(($Body|ConvertTo-Json -Compress))}
 try{return Invoke-RestMethod @args}catch{
  if($_.ErrorDetails.Message){try{$detail=$_.ErrorDetails.Message|ConvertFrom-Json;if($detail.error){throw [InvalidOperationException]::new([string]$detail.error)}}catch [InvalidOperationException]{throw}catch{}}
  throw 'Account management could not be confirmed. Refresh the list before retrying.'
 }
}
function Get-OwnerAccountRows {
 $response=Invoke-OwnerAccountsRequest
 if($null -eq $response.accounts){throw 'The account list could not be verified.'}
 $seen=@{}
 foreach($row in @($response.accounts)){
  if([string]$row.id -cnotmatch '^[a-z0-9_-]{3,32}$' -or $row.id -eq 'admin' -or $row.role -cnotin @('gm','player') -or $seen.ContainsKey([string]$row.id)){throw 'The account list could not be verified.'}
  $seen[[string]$row.id]=$true
  [pscustomobject]@{id=[string]$row.id;role=[string]$row.role;display=([string]$row.id+'  /  '+[string]$row.role)}
 }
}
function Set-OwnerAccountRole([string]$Id,[ValidateSet('gm','player')][string]$Role) {
 if($Id -cnotmatch '^[a-z0-9_-]{3,32}$' -or $Id -eq 'admin'){throw 'Select a registered player account.'}
 $result=Invoke-OwnerAccountsRequest 'POST' @{account=$Id;role=$Role}
 if($result.account -cne $Id -or $result.role -cne $Role -or $result.leaseInvalidated -ne $true){throw 'The permission change could not be verified. Refresh accounts.'}
 return $(if($Role -eq 'gm'){'Granted Admin / GM / Dev to '+$Id+'.'}else{'Revoked Admin / GM / Dev from '+$Id+'.'})+' The player must re-enter their character.'
}
function Update-OwnerAccountsSelection {
 $row=$script:ownerAccountsList.SelectedItem;$ready=$null -ne $row -and -not $script:ownerAccountsWorking
 $script:ownerGrantButton.Enabled=$ready -and $row.role -ne 'gm';$script:ownerRevokeButton.Enabled=$ready -and $row.role -eq 'gm'
}
function Update-OwnerAccountsFilter {
 $selected=$script:ownerAccountsList.SelectedItem;$query=$script:ownerAccountsSearch.Text.Trim();$script:ownerAccountsList.BeginUpdate()
 try{$script:ownerAccountsList.Items.Clear();foreach($row in @($script:ownerAccountRows)){if(-not $query -or ([string]$row.id).IndexOf($query,[StringComparison]::OrdinalIgnoreCase) -ge 0 -or ([string]$row.role).IndexOf($query,[StringComparison]::OrdinalIgnoreCase) -ge 0){$native=New-Object LauncherOwnerAccountRow;$native.id=$row.id;$native.role=$row.role;[void]$script:ownerAccountsList.Items.Add($native);if($selected -and $selected.id -ceq $row.id){$script:ownerAccountsList.SelectedItem=$native}}}}finally{$script:ownerAccountsList.EndUpdate()};Update-OwnerAccountsSelection
}
function Refresh-OwnerAccountsPanel {
 $rows=@(Get-OwnerAccountRows);$script:ownerAccountRows=$rows;Update-OwnerAccountsFilter
 Update-OwnerAccountsSelection
 if(-not $rows.Count){$script:ownerAccountsResult.Text='No other accounts yet. Players can sign up, then appear here.'}
}
function Show-OwnerAccountsPanel {
 if(-not (Test-OwnerAccountsContext)){return}
 if(Get-Command Close-ClientSettingsPanel -ErrorAction SilentlyContinue){Close-ClientSettingsPanel}
 try{Refresh-OwnerAccountsPanel;$script:ownerAccountsResult.Text='Select a player account to grant or revoke Admin / GM / Dev.';if(-not $script:ownerAccountsList.Items.Count){$script:ownerAccountsResult.Text='No other accounts yet. Players can sign up, then appear here.'};if(-not $script:ownerAccountsPanel.Visible){$script:ownerAccountsCovered=@();foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$progress,$statusLine,$script:browserLaunch,$itemBuilderButton,$mapBuilderButton)){if($control -and $control.Visible){$script:ownerAccountsCovered+=,$control;$control.Visible=$false}}};$script:ownerAccountsPanel.Visible=$true;$script:ownerAccountsPanel.BringToFront()}catch{$statusLine.Text=$_.Exception.Message}
}
function Close-OwnerAccountsPanel {
 $script:ownerAccountsPanel.Visible=$false
 $restore=(Test-OwnerAccountsContext)
 foreach($other in @($signupPanel,$script:authPanel,$script:friendsPanel)){if($other -and $other.Visible){$restore=$false}}
 if($restore){foreach($control in @($script:ownerAccountsCovered)){$control.Visible=$true}}
 $script:ownerAccountsCovered=@()
}
function Change-SelectedOwnerAccount([string]$Role) {
 $row=$script:ownerAccountsList.SelectedItem;if(-not $row -or $script:ownerAccountsWorking -or -not (Test-OwnerAccountsContext)){return}
 $verb=$(if($Role -eq 'gm'){'Grant Admin / GM / Dev to '}else{'Revoke Admin / GM / Dev from '})
 if([Windows.Forms.MessageBox]::Show($form,($verb+$row.id+'? The player will leave their active character and must re-enter.'),'Account permission','YesNo','Question') -ne 'Yes'){return}
 $script:ownerAccountsWorking=$true;Update-OwnerAccountsSelection;$script:ownerRefreshButton.Enabled=$false
 try{$confirmed=Set-OwnerAccountRole $row.id $Role;$script:ownerAccountsResult.Text=$confirmed;try{Refresh-OwnerAccountsPanel;$script:ownerAccountsResult.Text=$confirmed}catch{$script:ownerAccountsResult.Text=$confirmed+' Refresh the account list.'}}
 catch{$script:ownerAccountsResult.Text=$_.Exception.Message}
 finally{$script:ownerAccountsWorking=$false;$script:ownerRefreshButton.Enabled=$true;Update-OwnerAccountsSelection}
}
function Initialize-OwnerAccountsControls {
 if(-not ('LauncherOwnerAccountRow' -as [type])){Add-Type -TypeDefinition 'public sealed class LauncherOwnerAccountRow { public string id {get;set;} public string role {get;set;} public string display {get{return id+"  /  "+role;}} }'}
 $script:ownerAccountsAvailable=$false;$script:ownerAccountsWorking=$false
 $script:ownerAccountsButton=New-Object RoundedLauncherButton;$script:ownerAccountsButton.Text='Accounts';$script:ownerAccountsButton.Location=New-Object Drawing.Point(665,45);$script:ownerAccountsButton.Size=New-Object Drawing.Size(134,36);$script:ownerAccountsButton.BackColor=$ink;$script:ownerAccountsButton.ForeColor=$gold;$script:ownerAccountsButton.FlatStyle='Flat';$script:ownerAccountsButton.Visible=$false;$form.Controls.Add($script:ownerAccountsButton);$script:ownerAccountsButton.Add_Click({Show-OwnerAccountsPanel})
 $script:ownerAccountsPanel=New-Object GalaxyPanel;$script:ownerAccountsPanel.Location=New-Object Drawing.Point(265,145);$script:ownerAccountsPanel.Size=New-Object Drawing.Size(470,416);$script:ownerAccountsPanel.BackColor=[Drawing.Color]::FromArgb(18,22,30);$script:ownerAccountsPanel.Visible=$false;$form.Controls.Add($script:ownerAccountsPanel)
 $heading=New-Object Windows.Forms.Label;$heading.Text='Player accounts';$heading.Location=New-Object Drawing.Point(18,14);$heading.Size=New-Object Drawing.Size(350,30);$heading.Font=New-Object Drawing.Font('Segoe UI',16,[Drawing.FontStyle]::Bold);$heading.ForeColor=$gold;$script:ownerAccountsPanel.Controls.Add($heading)
 $intro=New-Object Windows.Forms.Label;$intro.Text='Manage Admin / GM / Dev (max staff) access on your server.';$intro.Location=New-Object Drawing.Point(18,49);$intro.Size=New-Object Drawing.Size(434,26);$intro.ForeColor=$muted;$script:ownerAccountsPanel.Controls.Add($intro)
 $script:ownerAccountsList=New-Object GalaxyListBox;$script:ownerAccountsList.Location=New-Object Drawing.Point(18,116);$script:ownerAccountsList.Size=New-Object Drawing.Size(434,178);$script:ownerAccountsList.DisplayMember='display';$script:ownerAccountsList.BackColor=$ink;$script:ownerAccountsList.ForeColor=$form.ForeColor;$script:ownerAccountsList.BorderStyle='None';$script:ownerAccountsPanel.Controls.Add($script:ownerAccountsList);$script:ownerAccountsList.Add_SelectedIndexChanged({Update-OwnerAccountsSelection})
 $script:ownerAccountRows=@();$script:ownerAccountsSearch=New-Object GalaxyTextBox;$script:ownerAccountsSearch.AccessibleName='Search player accounts by ID or role';$script:ownerAccountsSearch.Hint='Search account or role';$script:ownerAccountsSearch.TabIndex=0;$script:ownerAccountsList.TabIndex=1;$script:ownerAccountsSearch.MaxLength=64;$script:ownerAccountsSearch.Location=New-Object Drawing.Point(18,81);$script:ownerAccountsSearch.Size=New-Object Drawing.Size(434,26);$script:ownerAccountsPanel.Controls.Add($script:ownerAccountsSearch);$script:ownerAccountsSearch.Add_TextChanged({Update-OwnerAccountsFilter})
 $buttons=@();foreach($spec in @(@('Grant Staff',18),@('Revoke Staff',164),@('Refresh',310))){$b=New-Object RoundedLauncherButton;$b.Text=$spec[0];$b.Location=New-Object Drawing.Point($spec[1],300);$b.Size=New-Object Drawing.Size(142,34);$b.AccessibleName=$spec[0] -replace 'Staff','Admin / GM / Dev';$b.FlatStyle='Flat';$b.BackColor=$ink;$b.ForeColor=$gold;$script:ownerAccountsPanel.Controls.Add($b);$buttons+=,$b}
 $script:ownerGrantButton=$buttons[0];$script:ownerRevokeButton=$buttons[1];$script:ownerRefreshButton=$buttons[2];$script:ownerGrantButton.Add_Click({Change-SelectedOwnerAccount 'gm'});$script:ownerRevokeButton.Add_Click({Change-SelectedOwnerAccount 'player'});$script:ownerRefreshButton.Add_Click({try{Refresh-OwnerAccountsPanel;$script:ownerAccountsResult.Text='Account list refreshed.'}catch{$script:ownerAccountsResult.Text=$_.Exception.Message}})
 $script:ownerAccountsResult=New-Object Windows.Forms.Label;$script:ownerAccountsResult.UseMnemonic=$false;$script:ownerAccountsResult.Location=New-Object Drawing.Point(18,345);$script:ownerAccountsResult.Size=New-Object Drawing.Size(434,57);$script:ownerAccountsResult.ForeColor=$gold;$script:ownerAccountsPanel.Controls.Add($script:ownerAccountsResult)
 $close=New-Object RoundedLauncherButton;$close.Text='Close';$close.Location=New-Object Drawing.Point(388,14);$close.Size=New-Object Drawing.Size(64,30);$close.FlatStyle='Flat';$close.BackColor=$ink;$close.ForeColor=$muted;$script:ownerAccountsPanel.Controls.Add($close);$close.Add_Click({Close-OwnerAccountsPanel})
 Update-OwnerAccountsSelection
 Add-Type -AssemblyName System.Net.Http
 $script:ownerAccountsTimer=New-Object Windows.Forms.Timer;$script:ownerAccountsTimer.Interval=100
 $script:ownerAccountsTimer.Add_Tick({
  if(-not (Test-OwnerAccountsContext)){$script:ownerAccountsAvailable=$false;if($script:ownerAccountsClient){$script:ownerAccountsClient.Dispose();$script:ownerAccountsClient=$null};$script:ownerAccountsTask=$null;Update-OwnerAccountsVisibility;return}
  $context=$script:serverUrl+'|'+$script:control.pid+'|'+$script:control.token
  if($script:ownerAccountsClient -and $context -cne $script:ownerAccountsContext){$script:ownerAccountsClient.Dispose();$script:ownerAccountsClient=$null;$script:ownerAccountsTask=$null;$script:ownerAccountsAvailable=$false}
  if(-not $script:ownerAccountsClient){$handler=New-Object Net.Http.HttpClientHandler;$handler.AllowAutoRedirect=$false;$handler.UseProxy=$false;$script:ownerAccountsClient=New-Object Net.Http.HttpClient($handler);$script:ownerAccountsClient.Timeout=[TimeSpan]::FromSeconds(2);[void]$script:ownerAccountsClient.DefaultRequestHeaders.TryAddWithoutValidation('x-dekaron-launcher-token',[string]$script:control.token);$script:ownerAccountsContext=$context;$script:ownerAccountsAt=[DateTime]::MinValue}
  if($script:ownerAccountsTask -and $script:ownerAccountsTask.IsCompleted){try{$s=$script:ownerAccountsTask.GetAwaiter().GetResult()|ConvertFrom-Json;$script:ownerAccountsAvailable=$s.engineId -ceq $script:runningPlan.engineId -and [int]$s.pid -eq [int]$script:control.pid -and $s.accountsAvailable -eq $true -and -not $s.stopping}catch{$script:ownerAccountsAvailable=$false};$script:ownerAccountsTask=$null;$script:ownerAccountsAt=[DateTime]::UtcNow.AddSeconds(1)}
  Update-OwnerAccountsVisibility
  if(-not $script:ownerAccountsTask -and [DateTime]::UtcNow -ge $script:ownerAccountsAt){$script:ownerAccountsTask=$script:ownerAccountsClient.GetStringAsync((Get-ClientApiUrl $script:serverUrl)+'api/launcher/status')}
 });if(-not $PreviewPath){$script:ownerAccountsTimer.Start()}
 $form.Add_FormClosed({$script:ownerAccountsTimer.Stop();$script:ownerAccountsTimer.Dispose();if($script:ownerAccountsClient){$script:ownerAccountsClient.Dispose();$script:ownerAccountsClient=$null}})
}
