# Optional launcher updates. Network/extraction work is always a separate Node process.
# Never stop a game/server or close the launcher here. The core worker owns safe deferred apply.
function New-ReleaseUiState {
 return @{Closed=$false;NextCheck=[DateTime]::MinValue;NextStatus=[DateTime]::MinValue;CheckEnabled=$true;Operation=$null;Queue=@('check');Available=$null;Notified=$null;InstallRequested=$false;Cached=$false;Scheduled=$false;Message='Checking for updates in the background...'}
}
function Add-ReleaseUiOperation($State,[string]$Operation){
 if($State.Closed -or $Operation -notin @('check','retry','queue','status','enable-check','disable-check')){return}
 if($State.Operation -eq $Operation -or $State.Queue -contains $Operation){return}
 $State.Queue+=@($Operation)
}
function Request-ReleaseUiInstall($State){
 if($State.Closed -or -not $State.Available -or $State.InstallRequested -or $State.Scheduled){return}
 $State.InstallRequested=$true
 Add-ReleaseUiOperation $State 'queue'
}
function Receive-ReleaseUiReply($State,[string]$Operation,$Reply){
 if($State.Closed){return}
 if($Operation -eq 'status'){
  $phase=[string]$Reply.status
  if($phase -notin @('idle','queued','downloading','waiting','applying','complete','failed','current')){throw 'Invalid updater status'}
  $State.NextStatus=[DateTime]::UtcNow.AddSeconds(5)
  if($phase -eq 'idle'){return}
  $v=[string]$Reply.version
  if($v -and $v -notmatch '^\d{1,5}\.\d{1,5}\.\d{1,5}$'){throw 'Invalid update status version'}
  if($phase -in @('queued','downloading','waiting','applying')){
   if($v){$State.Available=$v};$State.InstallRequested=$true;$State.Scheduled=$true
  }elseif($phase -eq 'failed'){
   if($v){$State.Available=$v};$State.InstallRequested=$false;$State.Scheduled=$false
  }elseif($phase -in @('complete','current')){
   $State.Available=$null;$State.InstallRequested=$false;$State.Scheduled=$false
  }
  $State.Message=[string]$Reply.message
  return
 }
 $State.NextCheck=[DateTime]::UtcNow.AddMinutes(5)

 switch([string]$Reply.status){
  'available' {
   $v=[string]$Reply.candidate.version
   if($v -notmatch '^\d+\.\d+\.\d+$'){throw 'Invalid release version'}
   if($State.Available -ne $v){$State.Cached=$false;$State.Scheduled=$false}
   $State.Available=$v;$State.Message="A new update dropped: $v. Click to install."
  }
  {$_ -in @('scheduled','pending')} {
   if(-not $State.InstallRequested){throw 'Unexpected unrequested installation'}
   $State.Scheduled=$true;$State.Message="Update $($State.Available) requested. Download and verification continue in the background. Close your game, server and launcher normally; installation waits until safe. Nothing is restarted."
  }
  'current' {if(-not $State.Available){$State.Message='Your engine is up to date.'}}
  'disabled' {$State.CheckEnabled=$false;$State.Message='Automatic update checks are off. Click Updates to check manually.'}
  'offline' {$State.Message='Update check unavailable. You can keep using this installation.'}
  default {
   if($Operation -in @('enable-check','disable-check')){$State.CheckEnabled=$Operation -eq 'enable-check';$State.Message='Update notification preference saved.'}
   else{throw 'Unexpected updater response'}
  }
 }
}
function ConvertTo-ReleaseUiArgument([string]$Value){
 $b=New-Object Text.StringBuilder;[void]$b.Append('"');$slashes=0
 foreach($c in $Value.ToCharArray()){if($c -eq '\'){$slashes++;continue};if($c -eq '"'){[void]$b.Append('\',2*$slashes+1)}else{[void]$b.Append('\',$slashes)};[void]$b.Append($c);$slashes=0}
 [void]$b.Append('\',2*$slashes);[void]$b.Append('"');return $b.ToString()
}
function New-ReleaseUiStartInfo([string]$Node,[string]$Engine,[string]$Version,[string]$Operation){
 if($Operation -notin @('check','retry','queue','status','enable-check','disable-check')){throw 'Unsupported updater operation'}
 # Startup and periodic checks always run, including installations with a legacy opt-out.
 $command=if($Operation -eq 'check'){'retry'}else{$Operation}
 $args=@((Join-Path $Engine 'tools\release-update.mjs'),('--'+$command))
 if($Operation -in @('check','retry','queue')){$args+=@('--current',$Version)}
 if($Operation -in @('queue','status')){$args+=@('--install',$Engine)}
 $info=New-Object Diagnostics.ProcessStartInfo;$info.FileName=$Node;$info.Arguments=($args|ForEach-Object {ConvertTo-ReleaseUiArgument $_}) -join ' ';$info.WorkingDirectory=$Engine;$info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.WindowStyle='Hidden';$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true;return $info
}
function Start-ReleaseUiProcess($Info){return [Diagnostics.Process]::Start($Info)}
function Start-ReleaseUiNext {
 $s=$script:releaseUi;if(-not $s -or $s.Closed -or $s.Operation -or -not $s.Queue.Count){return}
 $op=$s.Queue[0];$s.Queue=@($s.Queue|Select-Object -Skip 1);$s.Operation=$op
 if($op -eq 'status'){$s.NextStatus=[DateTime]::UtcNow.AddSeconds(5)}
 try{
  $s.Process=Start-ReleaseUiProcess (New-ReleaseUiStartInfo $s.Node $s.Engine $s.Version $op)
  $s.Stdout=$s.Process.StandardOutput.ReadToEndAsync();$s.Stderr=$s.Process.StandardError.ReadToEndAsync();$s.Started=[DateTime]::UtcNow
  if($op -eq 'queue'){$s.Message='Scheduling the background update. You can keep playing.'}
 }catch{$s.Operation=$null;$s.Process=$null;$s.Message='Updates are unavailable. Your installed game remains usable.';$s.NextCheck=[DateTime]::UtcNow.AddMinutes(5)}
}
function Update-ReleaseUiControls {
 $s=$script:releaseUi;if(-not $s -or $s.Closed){return}
 if($s.Link){$s.Link.Text=if($s.Available){"Update $($s.Available)"}else{'Updates'};$s.Tip.SetToolTip($s.Link,$s.Message)}
 if($s.Popup -and -not $s.Popup.IsDisposed){
  $s.Heading.Text=if($s.Available){"Update $($s.Available) available"}else{'Engine updates'}
  $s.Detail.Text=$s.Message
  $s.Install.Enabled=[bool]$s.Available -and -not $s.InstallRequested -and -not $s.Scheduled
  $s.Install.Text=if($s.Scheduled){'Update queued'}elseif($s.InstallRequested){'Preparing update...'}else{'Install now'}
 }
}
function Hide-ReleaseUiNotice {
 $s=$script:releaseUi;if(-not $s -or $s.Closed -or -not $s.Popup -or $s.Popup.IsDisposed){return}
 $s.Popup.Hide()
 if($s.PreviousFocus -and -not $s.PreviousFocus.IsDisposed -and $s.PreviousFocus.CanFocus){[void]$s.PreviousFocus.Focus()}
 elseif($s.Link -and $s.Link.CanFocus){[void]$s.Link.Focus()}
 $s.PreviousFocus=$null
}
function Set-ReleaseUiNoticePosition {
 $s=$script:releaseUi;if(-not $s -or $s.Closed -or -not $s.Popup -or $s.Popup.IsDisposed){return}
 $s.Popup.Location=New-Object Drawing.Point([Math]::Max(0,[int](($s.Form.ClientSize.Width-$s.Popup.Width)/2)),[Math]::Max(0,[int](($s.Form.ClientSize.Height-$s.Popup.Height)/2)))
}
function Show-ReleaseUiNotice {
 $s=$script:releaseUi;if(-not $s -or $s.Closed){return}
 if(-not $s.Form -or $s.Form.IsDisposed){return}
 if(-not $s.Popup -or $s.Popup.IsDisposed){
  # A child of the existing launcher, never a separate window or browser tab.
  $w=New-Object GalaxyPanel;$w.Name='EmbeddedUpdateNotice';$w.AccessibleName='Engine update';$w.Visible=$false;$w.Size=New-Object Drawing.Size(480,248);$w.Font=$s.Form.Font;$w.ForeColor=$s.Form.ForeColor
  $heading=New-Object Windows.Forms.Label;$heading.UseMnemonic=$false;$heading.ForeColor=[Drawing.Color]::FromArgb(214,177,115);$heading.Font=New-Object Drawing.Font('Segoe UI',16,[Drawing.FontStyle]::Bold);$heading.Bounds=New-Object Drawing.Rectangle(22,20,392,36);$w.Controls.Add($heading)
  $detail=New-Object Windows.Forms.Label;$detail.Bounds=New-Object Drawing.Rectangle(22,68,436,108);$detail.UseMnemonic=$false;$w.Controls.Add($detail)
  $install=New-Object RoundedLauncherButton;$install.AccessibleName='Install update now';$install.Bounds=New-Object Drawing.Rectangle(22,192,272,36);$install.ForeColor=[Drawing.Color]::FromArgb(214,177,115);$install.TabIndex=0;$w.Controls.Add($install);$install.Add_Click({Request-ReleaseUiInstall $script:releaseUi;Start-ReleaseUiNext;Update-ReleaseUiControls})
  $later=New-Object RoundedLauncherButton;$later.Text='Later';$later.AccessibleName='Install update later';$later.Bounds=New-Object Drawing.Rectangle(310,192,148,36);$later.ForeColor=$s.Form.ForeColor;$later.TabIndex=1;$w.Controls.Add($later);$later.Add_Click({Hide-ReleaseUiNotice})
  $close=New-Object RoundedLauncherButton;$close.Text='X';$close.AccessibleName='Dismiss update notification';$close.Bounds=New-Object Drawing.Rectangle(426,18,32,30);$close.ForeColor=$s.Form.ForeColor;$close.TabIndex=2;$w.Controls.Add($close);$close.Add_Click({Hide-ReleaseUiNotice})
  $s.Popup=$w;$s.Heading=$heading;$s.Detail=$detail;$s.Install=$install;$s.Later=$later;$s.Dismiss=$close
  $s.Form.Controls.Add($w)
  $s.ResizeHandler=[EventHandler]{Set-ReleaseUiNoticePosition};$s.Form.Add_Resize($s.ResizeHandler)
  $s.PreviousKeyPreview=$s.Form.KeyPreview;$s.Form.KeyPreview=$true
  $s.KeyHandler=[Windows.Forms.KeyEventHandler]{param($sender,$e) if($script:releaseUi.Popup -and $script:releaseUi.Popup.Visible -and $e.KeyCode -eq [Windows.Forms.Keys]::Escape){Hide-ReleaseUiNotice;$e.Handled=$true;$e.SuppressKeyPress=$true}}
  $s.Form.Add_KeyDown($s.KeyHandler)
 }
 if(-not $s.Popup.Visible){$s.PreviousFocus=$s.Form.ActiveControl}
 Update-ReleaseUiControls;Set-ReleaseUiNoticePosition;$s.Popup.Show();$s.Popup.BringToFront()
}
function Invoke-ReleaseUiTick {
 $s=$script:releaseUi;if(-not $s -or $s.Closed){return}
 if($s.Operation -and $s.Process){
  $seconds=60
  if($s.Process.HasExited -and $s.Stdout.IsCompleted -and $s.Stderr.IsCompleted){
   $op=$s.Operation
   try{if($s.Process.ExitCode -ne 0){throw 'Updater command failed'};$text=$s.Stdout.GetAwaiter().GetResult();if($text.Length -gt 1048576){throw 'Oversize updater reply'};Receive-ReleaseUiReply $s $op ($text|ConvertFrom-Json)}catch{$s.Message='Update could not be completed. Your installed game is unchanged; click Updates to retry.';$s.InstallRequested=$false;$s.NextCheck=[DateTime]::UtcNow.AddMinutes(5)}finally{$s.Process.Dispose();$s.Process=$null;$s.Operation=$null}
  }elseif(([DateTime]::UtcNow-$s.Started).TotalSeconds -gt $seconds){
   # Only this check/download/scheduler process; never terminate a host, client or detached apply worker.
   try{$s.Process.Kill()}catch{};$s.Process.Dispose();$s.Process=$null;$s.Operation=$null;$s.InstallRequested=$false;$s.Message='Update request timed out. You can keep using this installation.';$s.NextCheck=[DateTime]::UtcNow.AddMinutes(5)
  }
 }
 if(-not $s.Operation -and -not $s.Queue.Count -and $s.Scheduled -and [DateTime]::UtcNow -ge $s.NextStatus){Add-ReleaseUiOperation $s 'status'}
 if(-not $s.Operation -and -not $s.Queue.Count -and -not $s.Scheduled -and [DateTime]::UtcNow -ge $s.NextCheck){Add-ReleaseUiOperation $s 'check'}
 if($s.Available -and $s.Notified -ne $s.Available){$s.Notified=$s.Available;Show-ReleaseUiNotice}
 Start-ReleaseUiNext;Update-ReleaseUiControls
}
function Initialize-ClientReleaseUpdates([string]$Engine,[string]$Node,$Form){
 if(-not $Node -or -not (Test-Path -LiteralPath (Join-Path $Engine 'tools\release-update.mjs') -PathType Leaf)){return}
 try{$version=(Get-Content -LiteralPath (Join-Path $Engine 'package.json') -Raw|ConvertFrom-Json).version;if($version -notmatch '^\d+\.\d+\.\d+$'){return}}catch{return}
 $s=New-ReleaseUiState;$s.Queue=@('status','check');$script:releaseUi=$s;$s.Engine=$Engine;$s.Node=$Node;$s.Version=$version;$s.Form=$Form
 $link=New-Object Windows.Forms.LinkLabel;$link.Text='Updates';$link.Bounds=New-Object Drawing.Rectangle(140,638,150,24);$link.LinkColor=[Drawing.Color]::FromArgb(214,177,115);$link.BackColor=[Drawing.Color]::Transparent;$Form.Controls.Add($link);$s.Link=$link;$s.Tip=New-Object Windows.Forms.ToolTip
 $link.Add_LinkClicked({if(-not $script:releaseUi.Available){Add-ReleaseUiOperation $script:releaseUi 'retry';Start-ReleaseUiNext};Show-ReleaseUiNotice})
 $timer=New-Object Windows.Forms.Timer;$timer.Interval=250;$timer.Add_Tick({Invoke-ReleaseUiTick});$s.Timer=$timer;$timer.Start();Start-ReleaseUiNext
}
function Stop-ClientReleaseUpdates {
 $s=$script:releaseUi;if(-not $s -or $s.Closed){return};$s.Closed=$true;$s.Queue=@()
 if($s.Timer){$s.Timer.Stop();$s.Timer.Dispose()}
 if($s.Form -and -not $s.Form.IsDisposed){
  if($s.ResizeHandler){$s.Form.Remove_Resize($s.ResizeHandler)}
  if($s.KeyHandler){$s.Form.Remove_KeyDown($s.KeyHandler);$s.Form.KeyPreview=$s.PreviousKeyPreview}
 }
 if($s.Popup -and -not $s.Popup.IsDisposed){$s.Popup.Hide();$s.Heading.Font.Dispose();$s.Popup.Dispose()}
 if($s.Process){try{if($s.Operation -ne 'queue' -and -not $s.Process.HasExited){$s.Process.Kill()}}catch{};$s.Process.Dispose();$s.Process=$null}
 if($s.Tip){$s.Tip.Dispose()}
}
