# Owner-only dashboard capacity editor. The server establishes every range/default;
# memory applies on the next server start, player cap/upload apply immediately.
function Invoke-ClientCapacityRequest([string]$Method='GET',$Body=$null) {
 if(-not (Test-ClientSettingsContext)){if(Test-ClientEditableSettingsContext){return (Invoke-ClientPrestartSettings $(if($Method -eq 'GET'){'capacityRead'}else{'capacitySet'}) $Body)};throw 'Start your own local world to manage server capacity.'}
 $control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl
 $args=@{Uri=((Get-ClientApiUrl $script:serverUrl)+'api/launcher/capacity');Method=$Method;Headers=@{'x-dekaron-launcher-token'=$control.token};MaximumRedirection=0;TimeoutSec=5}
 if($Method -eq 'POST'){$args.ContentType='application/json; charset=utf-8';$args.Body=[Text.Encoding]::UTF8.GetBytes(($Body|ConvertTo-Json -Compress))}
 try{$reply=Invoke-RestMethod @args}catch{throw 'Capacity could not be confirmed. Refresh before retrying.'}
 if(-not $reply.settings -or -not $reply.memoryRange -or -not $reply.live){throw 'The server capacity response is incomplete.'}
 $s=$reply.settings;$r=$reply.memoryRange
 foreach($n in @($s.maxPlayers,$s.memoryMB,$s.uploadMbps,$s.uploadShare,$r.min,$r.max,$r.step)){if($null -ne $n -and -not [double]::IsNaN([double]$n) -and -not [double]::IsInfinity([double]$n)){continue};throw 'The server capacity response is invalid.'}
 if($s.maxPlayers -lt 1 -or $s.maxPlayers -gt 500 -or $s.memoryMB -lt 0 -or $s.uploadMbps -lt 0 -or $s.uploadMbps -gt 10000 -or $s.uploadShare -lt .1 -or $s.uploadShare -gt .95 -or $r.min -lt 1024 -or $r.max -lt $r.min -or $r.step -lt 1){throw 'The server capacity ranges are invalid.'}
 return $reply
}
function Update-ClientCapacityValues($Reply) {
 $s=$Reply.settings;$r=$Reply.memoryRange
 $script:capacityPlayers.Value=[decimal]$s.maxPlayers
 $script:capacityMemory.Minimum=[decimal]$r.min;$script:capacityMemory.Maximum=[decimal]$r.max;$script:capacityMemory.Increment=[decimal]$r.step
 $script:capacityAuto.Checked=([int]$s.memoryMB -eq 0)
 $script:capacityMemory.Value=[decimal]$(if($s.memoryMB){$s.memoryMB}else{$r.recommended})
 $script:capacityMemory.Enabled=-not $script:capacityAuto.Checked
 $script:capacityUpload.Value=[decimal]$s.uploadMbps;$script:capacityShare.Value=[decimal]([math]::Round($s.uploadShare*100))
 if(-not $Reply.live){$script:capacityLive.Text='Saved startup settings. The world is stopped.';$script:capacityLoaded=$true;$script:capacitySave.Enabled=$true;return}
 $live=$Reply.live;$memory=$live.memory
 $script:capacityLive.Text=('Live: {0}/{1} players   |   Sent {2} KB/s   |   Heap {3}/{4} MB   |   Process {5} MB' -f $live.players,$live.maxPlayers,$live.sentKBps,$memory.heapUsedMB,$memory.heapLimitMB,$memory.rssMB)
 if($live.botAuto){$script:capacityLive.Text+="`r`nBots: automatic nearby density $($live.botAuto.percent)% | up to $($live.botAuto.presenceTarget) simulated across maps ($($live.botAuto.reason))"}
 $script:capacityLoaded=$true;$script:capacitySave.Enabled=$true
}
function Refresh-ClientCapacityPanel {
 $script:capacityLoaded=$false;$script:capacitySave.Enabled=$false
 try{Update-ClientCapacityValues (Invoke-ClientCapacityRequest);$script:capacityResult.Text='Player cap and upload apply now. Memory applies the next time this server starts.'}catch{$script:capacityResult.Text=$_.Exception.Message}
}
function Save-ClientCapacityPanel {
 if(-not $script:capacityLoaded -or $script:busy -or $script:ownerAccountsWorking -or -not (Test-ClientEditableSettingsContext)){return}
 $script:capacitySave.Enabled=$false
 try{
  $input=@{maxPlayers=[int]$script:capacityPlayers.Value;memoryMB=$(if($script:capacityAuto.Checked){0}else{[int]$script:capacityMemory.Value});uploadMbps=[double]$script:capacityUpload.Value;uploadShare=([double]$script:capacityShare.Value/100)}
  $reply=Invoke-ClientCapacityRequest 'POST' $input
  if([int]$reply.settings.maxPlayers -ne $input.maxPlayers -or [double]$reply.settings.uploadMbps -ne $input.uploadMbps -or [double]$reply.settings.uploadShare -ne $input.uploadShare){throw 'Saved capacity did not match. Refresh before retrying.'}
  Update-ClientCapacityValues $reply;$script:capacityResult.Text='Capacity saved. Player cap and upload apply now; memory applies at the next start.'
 }catch{$script:capacityLoaded=$false;$script:capacityResult.Text=$_.Exception.Message}finally{$script:capacitySave.Enabled=$script:capacityLoaded}
}
function New-ClientCapacityPanel {
 $dialog=New-Object LauncherWindow;$dialog.Text='Server capacity';$dialog.ClientSize=New-Object Drawing.Size(780,440);$dialog.FormBorderStyle='FixedDialog';$dialog.MaximizeBox=$false;$dialog.MinimizeBox=$false;$dialog.StartPosition='CenterParent';$dialog.ForeColor=$form.ForeColor;$dialog.BackColor=$form.BackColor
 $panel=New-Object GalaxyPanel;$panel.Dock='Fill';$dialog.Controls.Add($panel)
 function Add-CapacityLabel([string]$Text,[int]$X,[int]$Y,[int]$W,[int]$H,[int]$Size=10){$c=New-Object Windows.Forms.Label;$c.Text=$Text;$c.UseMnemonic=$false;$c.Bounds=New-Object Drawing.Rectangle($X,$Y,$W,$H);$c.Font=New-Object Drawing.Font('Segoe UI',$Size);$c.ForeColor=$muted;$panel.Controls.Add($c);return $c}
 $heading=Add-CapacityLabel 'Server capacity' 26 16 726 38 23;$heading.ForeColor=$gold
 [void](Add-CapacityLabel 'Maximum human players (1-500; owner / GM may always join)' 26 72 540 24)
 [void](Add-CapacityLabel 'Server memory (MB; next start)' 26 120 540 24)
 [void](Add-CapacityLabel 'Your upload speed (Mbps; 0 means no upload limit)' 26 194 540 24)
 [void](Add-CapacityLabel 'Upload share used by the game (%)' 26 242 540 24)
 function Add-CapacityNumber([string]$Name,[int]$Y,[decimal]$Min,[decimal]$Max,[int]$Decimals=0){$c=New-Object Windows.Forms.NumericUpDown;$c.AccessibleName=$Name;$c.Bounds=New-Object Drawing.Rectangle(584,$Y,168,32);$c.Minimum=$Min;$c.Maximum=$Max;$c.DecimalPlaces=$Decimals;$c.ForeColor=$form.ForeColor;$c.BackColor=$form.BackColor;$c.Font=New-Object Drawing.Font('Segoe UI',11);$panel.Controls.Add($c);return $c}
 $script:capacityPlayers=Add-CapacityNumber 'Maximum players' 68 1 500
 $script:capacityMemory=Add-CapacityNumber 'Server memory MB' 116 1024 1048576
 $script:capacityUpload=Add-CapacityNumber 'Upload speed Mbps' 190 0 10000 1
 $script:capacityShare=Add-CapacityNumber 'Game upload percentage' 238 10 95
 $script:capacityAuto=New-Object Windows.Forms.CheckBox;$script:capacityAuto.Text='Automatic memory (Node default)';$script:capacityAuto.Bounds=New-Object Drawing.Rectangle(26,155,726,26);$script:capacityAuto.ForeColor=$gold;$panel.Controls.Add($script:capacityAuto);$script:capacityAuto.Add_CheckedChanged({$script:capacityMemory.Enabled=-not $script:capacityAuto.Checked})
 $script:capacityLive=Add-CapacityLabel '' 26 282 726 38
 $script:capacityResult=Add-CapacityLabel '' 26 326 726 42;$script:capacityResult.ForeColor=$gold
 $script:capacitySave=New-Object RoundedLauncherButton;$script:capacitySave.Text='Save capacity';$script:capacitySave.Bounds=New-Object Drawing.Rectangle(26,384,220,36);$script:capacitySave.ForeColor=$gold;$panel.Controls.Add($script:capacitySave);$script:capacitySave.Add_Click({Save-ClientCapacityPanel});$dialog.AcceptButton=$script:capacitySave
 $refresh=New-Object RoundedLauncherButton;$refresh.Text='Refresh';$refresh.Bounds=New-Object Drawing.Rectangle(508,384,116,36);$refresh.ForeColor=$muted;$panel.Controls.Add($refresh);$refresh.Add_Click({Refresh-ClientCapacityPanel})
 $close=New-Object RoundedLauncherButton;$close.Text='Back';$close.Bounds=New-Object Drawing.Rectangle(636,384,116,36);$close.ForeColor=$muted;$close.DialogResult='Cancel';$panel.Controls.Add($close);$dialog.CancelButton=$close
 return $dialog
}
function Show-ClientCapacityPanel {
 if($script:busy -or $script:ownerAccountsWorking -or -not (Test-ClientEditableSettingsContext)){return}
 $dialog=New-ClientCapacityPanel
 try{Refresh-ClientCapacityPanel;[void]$dialog.ShowDialog($form)}finally{$script:capacityLoaded=$false;$dialog.Dispose()}
}
