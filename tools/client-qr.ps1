# Offline address-only phone QR. Showing/saving a code never starts, stops or reconfigures a server.
function Get-ClientPhoneAddresses($Status,[string]$Relay='',[string[]]$Lan=@()) {
 if(-not $Status -or $Status.stopping -or $Status.hostMode -cnotin @('open','friends')){return @()}
 $port=[int]$Status.port;if($port -lt 1 -or $port -gt 65535){return @()}
 if($Relay){$url=ConvertTo-FriendsUrl $Relay;if(([Uri]$url).Scheme -cne 'https'){throw 'A relay QR requires the current HTTPS relay.'};return @($url)}
 if($Status.listenHost -ceq '0.0.0.0'){return @($Lan|Where-Object{try{$uri=[Uri](ConvertTo-FriendsUrl $_);$uri.Scheme -ceq 'http' -and -not $uri.IsLoopback -and $uri.Port -eq $port}catch{$false}}|Select-Object -Unique)}
 if($Status.listenHost -match '^\d+\.\d+\.\d+\.\d+$'){try{$uri=[Uri](ConvertTo-FriendsUrl ('http://'+$Status.listenHost+':'+$port+'/'));if(-not $uri.IsLoopback){return @($uri.AbsoluteUri)}}catch{}}
 return @()
}
function Get-ClientPhoneShare {
 if(-not $script:serverReady -or $script:remoteWorld -or -not $script:runningPlan -or -not $script:control){throw 'Start your own hosted world before sharing its phone QR.'}
 $control=Get-LauncherControl $clientEngine $script:runningPlan $script:serverUrl
 $status=Invoke-RestMethod -Uri ((Get-ClientApiUrl $script:serverUrl)+'api/launcher/status') -Headers @{'x-dekaron-launcher-token'=$control.token} -MaximumRedirection 0 -TimeoutSec 3
 if(-not (Test-ClientServerIdentity $status $script:runningPlan) -or $status.engineId -cne $script:runningPlan.engineId -or [int]$status.pid -ne [int]$script:control.pid -or [int]$status.pid -ne [int]$control.pid -or $status.stopping){throw 'The running server changed. Refresh the launcher before sharing.'}
 # The authenticated status comes from this exact loopback listener; port is its URI, not a saved preference.
 $status|Add-Member -NotePropertyName port -NotePropertyValue ([Uri]$script:serverUrl).Port -Force
 $relay=$(if($script:relayConfig -and $script:gameServerUrl -and $script:gameServerUrl.TrimEnd('/') -ceq $script:relayConfig.publicOrigin){$script:gameServerUrl}else{''})
 if($relay){$currentRelay=Get-ClientServerStatus $relay;if(-not (Test-ClientServerIdentity $currentRelay $script:runningPlan) -or [int]$currentRelay.pid -ne [int]$status.pid){throw 'The HTTPS relay did not confirm this running server. Check its connection before sharing the QR.'}}
 $addresses=@(Get-ClientPhoneAddresses $status $relay @(Get-FriendsAddresses ([int]$status.port)))
 if(-not $addresses.Count){throw 'This running world has no shareable listener. Enable direct LAN connections for the next host start, or use the current managed HTTPS relay.'}
 return [pscustomobject]@{addresses=$addresses;url=$script:serverUrl;engineId=$status.engineId;pid=[int]$status.pid;hostMode=$status.hostMode}
}
function New-ClientPhoneQr([string]$Address) {
 $node=$(if($clientNode -and $clientNode.Source){$clientNode}else{Get-ClientNode -Engine $clientEngine})
 if(-not $node -or -not $node.Source){throw 'The engine runtime is unavailable for QR generation.'}
 $helper=Join-Path $clientEngine 'tools\client-qr.mjs';Assert-ClientPathUnlinked $helper
 $info=New-Object Diagnostics.ProcessStartInfo;$info.FileName=$node.Source;$info.Arguments='"'+$helper+'"';$info.WorkingDirectory=$clientEngine;$info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.RedirectStandardInput=$true;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
 $process=New-Object Diagnostics.Process;$process.StartInfo=$info
 try{[void]$process.Start();$process.StandardInput.Write((@{address=$Address}|ConvertTo-Json -Compress));$process.StandardInput.Close();$output=$process.StandardOutput.ReadToEnd();$errorText=$process.StandardError.ReadToEnd();$process.WaitForExit();if($process.ExitCode -ne 0 -or $output.Length -gt 65536){throw 'QR generation refused this address.'};$data=$output|ConvertFrom-Json}finally{$process.Dispose()}
 $size=[int]$data.size;if($size -lt 21 -or $size -gt 177 -or $data.quietZone -ne 4 -or @($data.matrix).Count -ne $size){throw 'Invalid QR matrix.'}
 $scale=[int][math]::Max(2,[math]::Min(6,[math]::Floor(360/($size+8))));$pixels=($size+8)*$scale;$bitmap=New-Object Drawing.Bitmap($pixels,$pixels);$graphics=[Drawing.Graphics]::FromImage($bitmap)
 try{$graphics.Clear([Drawing.Color]::White);for($y=0;$y -lt $size;$y++){$row=[string]$data.matrix[$y];if($row.Length -ne $size -or $row -match '[^01]'){throw 'Invalid QR matrix row.'};for($x=0;$x -lt $size;$x++){if($row[$x] -eq '1'){$graphics.FillRectangle([Drawing.Brushes]::Black,($x+4)*$scale,($y+4)*$scale,$scale,$scale)}}}}catch{$bitmap.Dispose();throw}finally{$graphics.Dispose()}
 return [pscustomobject]@{image=$bitmap;address=[string]$data.address;payload=[string]$data.payload}
}
function Show-ClientPhoneQr {
 if($script:busy -or $script:ownerAccountsWorking){return}
 $dialog=$null;$picture=$null;$timer=$null
 try{
  $share=Get-ClientPhoneShare
  $dialog=New-Object Windows.Forms.Form;$dialog.Text='Phone / tablet QR';$dialog.StartPosition='CenterParent';$dialog.FormBorderStyle='FixedDialog';$dialog.MaximizeBox=$false;$dialog.MinimizeBox=$false;$dialog.ShowInTaskbar=$false;$dialog.ClientSize=New-Object Drawing.Size(500,590);$dialog.BackColor=$ink;$dialog.ForeColor=$gold;$dialog.Font=$form.Font
  $help=New-Object Windows.Forms.Label;$help.Text='Install the Android app, tap Scan server QR, scan this code, then Join after the server check. Passwords stay separate.';$help.Bounds=New-Object Drawing.Rectangle(20,12,460,55);$dialog.Controls.Add($help)
  $selector=New-Object Windows.Forms.ComboBox;$selector.DropDownStyle='DropDownList';$selector.Bounds=New-Object Drawing.Rectangle(20,72,460,28);$selector.AccessibleName='Running server address';foreach($url in $share.addresses){[void]$selector.Items.Add($url)};$dialog.Controls.Add($selector)
  $picture=New-Object Windows.Forms.PictureBox;$picture.Bounds=New-Object Drawing.Rectangle(20,112,460,372);$picture.SizeMode='CenterImage';$picture.BackColor=[Drawing.Color]::White;$picture.AccessibleName='Address-only server QR';$dialog.Controls.Add($picture)
  $message=New-Object Windows.Forms.Label;$message.Bounds=New-Object Drawing.Rectangle(20,490,460,38);$dialog.Controls.Add($message)
  $copy=New-Object Windows.Forms.Button;$copy.Text='Copy app link';$copy.Bounds=New-Object Drawing.Rectangle(20,540,140,34);$dialog.Controls.Add($copy)
  $save=New-Object Windows.Forms.Button;$save.Text='Save QR image';$save.Bounds=New-Object Drawing.Rectangle(174,540,140,34);$dialog.Controls.Add($save)
  $close=New-Object Windows.Forms.Button;$close.Text='Close';$close.Bounds=New-Object Drawing.Rectangle(340,540,140,34);$close.Add_Click({$dialog.Close()});$dialog.Controls.Add($close);$dialog.CancelButton=$close
  $selector.Add_SelectedIndexChanged({try{$qr=New-ClientPhoneQr ([string]$selector.SelectedItem);$old=$picture.Image;$picture.Image=$qr.image;if($old){$old.Dispose()};$picture.Tag=$qr.payload;$message.Text=$qr.address;$copy.Enabled=$true;$save.Enabled=$true}catch{$message.Text=$_.Exception.Message;$copy.Enabled=$false;$save.Enabled=$false;if($picture.Image){$picture.Image.Dispose();$picture.Image=$null};$picture.Tag=$null}})
  $copy.Add_Click({if($picture.Tag){[Windows.Forms.Clipboard]::SetText([string]$picture.Tag);$message.Text='App link copied. No password is included.'}})
  $save.Add_Click({if(-not $picture.Image){return};$file=New-Object Windows.Forms.SaveFileDialog;$file.Filter='PNG image|*.png';$file.FileName='Dekaron-server-QR.png';try{if($file.ShowDialog($dialog) -eq [Windows.Forms.DialogResult]::OK){$picture.Image.Save($file.FileName,[Drawing.Imaging.ImageFormat]::Png);$message.Text='QR saved. Share passwords separately.'}}finally{$file.Dispose()}})
  $timer=New-Object Windows.Forms.Timer;$timer.Interval=1000;$timer.Add_Tick({if(-not $script:serverReady -or $script:remoteWorld -or $script:serverUrl -cne $share.url -or -not $script:control -or [int]$script:control.pid -ne $share.pid -or -not $script:runningPlan -or $script:runningPlan.engineId -cne $share.engineId){$dialog.Close()}});$timer.Start();$selector.SelectedIndex=0;[void]$dialog.ShowDialog($form)
 }catch{if($script:settingsPanel -and $script:settingsPanel.Visible){$script:settingsResult.Text=$_.Exception.Message}elseif($script:friendsResult){$script:friendsResult.Text=$_.Exception.Message}}
 finally{if($timer){$timer.Stop();$timer.Dispose()};if($picture -and $picture.Image){$picture.Image.Dispose();$picture.Image=$null};if($dialog){$dialog.Dispose()}}
}
