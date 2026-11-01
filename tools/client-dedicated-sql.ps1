function ConvertTo-DedicatedSqlInstance([string]$Value) {
 $value=$Value.Trim()
 if($value.Length -gt 200 -or $value -notmatch '^(?:\.|\(local\)|localhost|[A-Za-z0-9][A-Za-z0-9.-]*)(?:\\[A-Za-z0-9_][A-Za-z0-9_-]{0,63}|,[1-9][0-9]{0,4})?$'){throw 'Enter a SQL host, host\instance, or host,port. Credentials and connection-string options are not accepted.'}
 if($value -match ',([0-9]+)$' -and [int]$Matches[1] -gt 65535){throw 'SQL port must be between 1 and 65535.'}
 return $value
}
function Resolve-AutomaticLocalSqlInstance([string]$Value) {
 $value=ConvertTo-DedicatedSqlInstance $Value
 if($value -notmatch '^(?:\.|\(local\)|localhost)\\([A-Za-z][A-Za-z0-9_]{0,15})$' -or $Matches[1] -in @('MSSQLSERVER','DEFAULT')){throw 'Automatic setup requires a local named instance such as .\SQLEXPRESS or .\DEKARONBETA. Remote servers use Check SQL and Set up SQL world.'}
 return $Matches[1].ToUpperInvariant()
}
function Select-DedicatedLocalSqlInstance([string]$Current) {
 try{return '.\'+(Resolve-AutomaticLocalSqlInstance $Current)}catch{}
 if($script:lastLocalSqlInstance){return $script:lastLocalSqlInstance}
 return '.\SQLEXPRESS'
}
function Initialize-DedicatedSqlConfiguration {
 [Environment]::SetEnvironmentVariable('DEKARON_DEDICATED_STORAGE',(Read-DedicatedStorage),'Process')
 $file=Join-Path $clientEngine 'run\dashboard-sql-instance.txt'
 $value=if(Test-Path -LiteralPath $file){[IO.File]::ReadAllText($file)}elseif($env:DEKARON_SQL_INSTANCE){$env:DEKARON_SQL_INSTANCE}else{'.\SQLEXPRESS'}
 [Environment]::SetEnvironmentVariable('DEKARON_SQL_INSTANCE',(ConvertTo-DedicatedSqlInstance $value),'Process')
}
function Save-DedicatedSqlInstance([string]$Value) {
 if($script:serverReady -or $script:busy){throw 'Stop your world before changing the SQL server.'}
 $value=ConvertTo-DedicatedSqlInstance $Value
 try{$script:lastLocalSqlInstance='.\'+(Resolve-AutomaticLocalSqlInstance $value)}catch{}
 $file=Join-Path $clientEngine 'run\dashboard-sql-instance.txt';[void][IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($file));[IO.File]::WriteAllText($file,$value,(New-Object Text.UTF8Encoding($false)))
 [Environment]::SetEnvironmentVariable('DEKARON_SQL_INSTANCE',$value,'Process')
 return $value
}
function Test-DedicatedStorageConfigured {
 foreach($relative in @('run\dashboard-storage.txt','server\accounts\data.json','server\accounts\friends-accounts.json')){if(Test-Path -LiteralPath (Join-Path $clientEngine $relative)){return $true}}
 return $false
}
function Show-DedicatedStartupOptions {
 if(-not $script:dedicatedMode -or $script:busy -or $script:ownerAccountsWorking -or -not $script:planValid){return $false}
 if($script:serverReady -or $script:remoteWorld){Show-ClientSettingsPanel;return $true}
 try {
  $script:prestartScope=$(if($script:friendsLaunch){'friends'}else{'local'})
  $state=Invoke-ClientPrestartSettings 'read'
  if($state.running){$script:offlineSettings=$false;$script:prestartPending=$false;Show-ClientSettingsPanel;Update-ClientSettingsContinue;return $true}
  $script:offlineSettings=$true;$script:prestartPending=$true;$script:prestartAccountOnly=$false
  Show-ClientSettingsPanel;Update-ClientSettingsContinue
  $script:settingsResult.Text='Review your saved options. SQL / VPS selects local files, local SQL or a remote SQL database. Select the green Launch button when ready.'
  return $true
 }catch{$statusLine.Text=$_.Exception.Message;return $true}
}
function Show-DedicatedFirstRunStorageChoice { return (Show-DedicatedStartupOptions) }
# SQL persistence is a setup page inside the existing engine dashboard.
function Start-DedicatedSqlPageProcess($StartInfo){[Diagnostics.Process]::Start($StartInfo)}
function Install-DedicatedSqlFromPage {
 if($script:serverReady -or $script:busy){throw 'Stop your world before installing SQL Server.'}
 if($script:dedicatedSqlInstance){try{[void](Save-DedicatedSqlInstance $script:dedicatedSqlInstance.Text)}catch{$script:dedicatedSqlResult.Text=$_.Exception.Message;return}}
 try{$instanceName=Resolve-AutomaticLocalSqlInstance $(if($env:DEKARON_SQL_INSTANCE){$env:DEKARON_SQL_INSTANCE}else{'.\SQLEXPRESS'})}catch{$script:dedicatedSqlResult.Text=$_.Exception.Message;return}
 if(-not (Get-Service -Name ('MSSQL$'+$instanceName) -ErrorAction SilentlyContinue) -and -not $script:dedicatedSqlConsent.Checked){$script:dedicatedSqlResult.Text='Review the Microsoft terms and check acceptance before installing SQL Express.';return}
 $script:busy=$true;$script:dedicatedSqlInstall.Enabled=$false
 $script:dedicatedSqlResult.Text='Preparing local SQL instance '+$instanceName+'. Windows may request administrator permission.'
 $phaseFile=Join-Path ([IO.Path]::GetTempPath()) ('dekaron-sql-phase-'+[Guid]::NewGuid().ToString('N')+'.txt')
 $sqlReady=$false
 try {
  $helper=Join-Path $clientEngine 'tools\install-dedicated-sql.ps1';Assert-ClientPathUnlinked $helper
  $start=New-Object Diagnostics.ProcessStartInfo;$start.FileName=Join-Path ([Environment]::GetFolderPath('System')) 'WindowsPowerShell\v1.0\powershell.exe'
  $start.Arguments='-NoProfile -ExecutionPolicy Bypass -File "'+$helper+'" -InstanceName '+$instanceName+' -ProgressFile "'+$phaseFile+'"'+$(if($script:dedicatedSqlConsent.Checked){' -AcceptLicense'}else{''});$start.WorkingDirectory=$clientEngine;$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true
  $process=Start-DedicatedSqlPageProcess $start;$output=$process.StandardOutput.ReadToEndAsync();$errors=$process.StandardError.ReadToEndAsync()
  while(-not $process.HasExited){if(Test-Path -LiteralPath $phaseFile){try{$script:dedicatedSqlResult.Text=[IO.File]::ReadAllText($phaseFile)}catch{}};[Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(60)}
  if($process.ExitCode -ne 0){throw ($errors.GetAwaiter().GetResult()+$output.GetAwaiter().GetResult())}
  $sqlReady=$true
 }catch{$script:dedicatedSqlResult.Text=$_.Exception.Message}
 finally{if($process){$process.Dispose()};$script:busy=$false;$script:dedicatedSqlInstall.Enabled=$true;if(Test-Path -LiteralPath $phaseFile){Remove-Item -LiteralPath $phaseFile -Force}}
 if($sqlReady){Invoke-DedicatedSqlSetup '--setup';if($script:dedicatedSqlSetupSucceeded){Set-DedicatedStorage 'sqlserver';$script:dedicatedSqlStorage.SelectedIndex=1;$script:dedicatedSqlResult.Text='SQL world ready. SQL storage selected. Continue with your existing owner-account setup and Grant GM controls.'}}
}
function Read-DedicatedStorage {
 $file=Join-Path $clientEngine 'run\dashboard-storage.txt'
 if((Test-Path -LiteralPath $file) -and ([IO.File]::ReadAllText($file).Trim() -eq 'sqlserver')){return 'sqlserver'}
 return 'json'
}
function Set-DedicatedStorage([string]$Mode) {
 if($script:serverReady -or $script:busy){throw 'Stop the current world before changing storage.'}
 if($Mode -notin @('json','sqlserver')){throw 'Choose local files or SQL Server.'}
 $file=Join-Path $clientEngine 'run\dashboard-storage.txt';[void][IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($file));[IO.File]::WriteAllText($file,$Mode,(New-Object Text.UTF8Encoding($false)))
 [Environment]::SetEnvironmentVariable('DEKARON_DEDICATED_STORAGE',$Mode,'Process')
}
function Sync-StartupStorageChoice {
 if(-not $script:startupLocalStorage -or -not $script:startupSqlStorage){return}
 $sql=(Read-DedicatedStorage) -eq 'sqlserver'
 $script:startupLocalStorage.Checked=-not $sql
 $script:startupSqlStorage.Checked=$sql
 $enabled=-not ($script:serverReady -or $script:busy -or $script:ownerAccountsWorking)
 $script:startupLocalStorage.Enabled=$enabled
 $script:startupSqlStorage.Enabled=$enabled
}
function Select-StartupStorage([string]$Mode) {
 try {
  Set-DedicatedStorage $Mode
  Sync-StartupStorageChoice
  $script:settingsResult.Text=$(if($Mode -eq 'sqlserver'){'SQL server selected for your next world. Set the instance in SQL / VPS.'}else{'Local files selected for your next world.'})
 } catch {
  Sync-StartupStorageChoice
  $script:settingsResult.Text=$_.Exception.Message
 }
}
function Invoke-DedicatedSqlSetup([string]$Flag) {
 if($script:serverReady -or $script:busy){throw 'Stop your world before SQL setup.'}
 if($script:dedicatedSqlInstance){try{[void](Save-DedicatedSqlInstance $script:dedicatedSqlInstance.Text)}catch{$script:dedicatedSqlResult.Text=$_.Exception.Message;return}}
 $script:dedicatedSqlSetupSucceeded=$false
 $script:busy=$true;$script:dedicatedSqlResult.Text='Checking the dedicated SQL world...';[Windows.Forms.Application]::DoEvents()
 try {
  $scope=$(if($script:dedicatedSqlScope.SelectedIndex -eq 1){'DEKARON_DEDICATED_HOSTED'}else{'DEKARON_DEDICATED'})
  $start=New-Object Diagnostics.ProcessStartInfo;$start.FileName=$clientNode.Source;$start.Arguments='"'+(Join-Path $clientEngine 'tools\setup-dedicated-sql.mjs')+'" '+$Flag;$start.WorkingDirectory=$clientEngine;$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true
  $start.EnvironmentVariables['DEKARON_DEDICATED_SQL_DB']=$scope
  $process=Start-DedicatedSqlPageProcess $start;$output=$process.StandardOutput.ReadToEndAsync();$errors=$process.StandardError.ReadToEndAsync();$deadline=[DateTime]::UtcNow.AddMinutes(2)
  while(-not $process.HasExited){if([DateTime]::UtcNow -gt $deadline){throw 'SQL setup is still running. Wait for it to finish before starting a world.'};[Windows.Forms.Application]::DoEvents();[Threading.Thread]::Sleep(40)}
  if($process.ExitCode -ne 0){throw ($errors.GetAwaiter().GetResult()+$output.GetAwaiter().GetResult())}
  $reply=$output.GetAwaiter().GetResult()|ConvertFrom-Json
  $script:dedicatedSqlSetupSucceeded=($Flag -eq '--setup' -and $reply.installed)
  $script:dedicatedSqlResult.Text=if($reply.installed){'SQL ready: '+$reply.database+' on '+$reply.instance+'. Accounts: '+$reply.accounts+'.'}else{'SQL Server is reachable. Select Set up SQL world to create '+$scope+'.'}
 }catch{$script:dedicatedSqlResult.Text=$_.Exception.Message}finally{if($process){$process.Dispose()};$script:busy=$false}
}
function Show-DedicatedSqlPage {
 if($script:busy -or $script:ownerAccountsWorking){return}
 Close-ClientSettingsPanel
 if($script:friendsPanel){$script:friendsPanel.Visible=$false};if($script:ratesPanel){$script:ratesPanel.Visible=$false}
 foreach($control in @($heroKicker,$hero,$heroCopy,$primary,$progress,$statusLine,$script:browserLaunch,$script:localWorld,$itemBuilderButton,$mapBuilderButton)){if($control){$control.Visible=$false}}
 $script:dedicatedSqlStorage.SelectedIndex=$(if((Read-DedicatedStorage) -eq 'sqlserver'){if($env:DEKARON_SQL_INSTANCE -match '^(\.|\(local\)|localhost|127\.0\.0\.1)(\\|,|$)'){1}else{2}}else{0})
 $script:dedicatedSqlStorage.Enabled=-not $script:serverReady
 $script:dedicatedSqlCheck.Enabled=$script:dedicatedSqlSetup.Enabled=-not $script:serverReady
 $script:dedicatedSqlInstall.Enabled=-not $script:serverReady
 $script:dedicatedSqlInstance.Enabled=-not $script:serverReady
 $script:dedicatedSqlPanel.Visible=$true;$script:dedicatedSqlPanel.BringToFront();$form.AcceptButton=$null
}
function Initialize-DedicatedSqlPage {
 if(-not $script:dedicatedMode){return}
 $script:dedicatedSqlPanel=New-Object GalaxyPanel;$script:dedicatedSqlPanel.Bounds=New-Object Drawing.Rectangle(110,165,780,486);$script:dedicatedSqlPanel.Visible=$false;$form.Controls.Add($script:dedicatedSqlPanel)
 function Add-DedicatedSqlLabel([string]$Text,[int]$Y,[int]$H=28,[int]$Size=10){$label=New-Object Windows.Forms.Label;$label.Text=$Text;$label.Bounds=New-Object Drawing.Rectangle(26,$Y,726,$H);$label.ForeColor=$muted;$label.Font=New-Object Drawing.Font('Segoe UI',$Size);$script:dedicatedSqlPanel.Controls.Add($label);return $label}
 [void](Add-DedicatedSqlLabel 'SQL / VPS storage' 14 38 23)
 [void](Add-DedicatedSqlLabel 'Storage for the next local or hosted world' 65)
 $script:dedicatedSqlStorage=New-Object GalaxyComboBox;$script:dedicatedSqlStorage.Bounds=New-Object Drawing.Rectangle(26,96,726,34);$script:dedicatedSqlStorage.Items.AddRange(@('Local server (no SQL)','Local SQL server','Remote SQL server / VPS database'));$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlStorage)
 $script:dedicatedSqlStorage.Add_SelectedIndexChanged({if($script:dedicatedSqlPanel.Visible){try{if($script:dedicatedSqlStorage.SelectedIndex -eq 1){$localInstance=Select-DedicatedLocalSqlInstance $script:dedicatedSqlInstance.Text;$script:dedicatedSqlInstance.Text=$localInstance;[void](Save-DedicatedSqlInstance $localInstance)};Set-DedicatedStorage $(if($script:dedicatedSqlStorage.SelectedIndex -gt 0){'sqlserver'}else{'json'});$script:dedicatedSqlResult.Text='Storage choice saved for the next world startup.'}catch{$script:dedicatedSqlResult.Text=$_.Exception.Message}}})
 [void](Add-DedicatedSqlLabel 'SQL setup target (local and hosted worlds stay separate)' 149)
 $script:dedicatedSqlScope=New-Object GalaxyComboBox;$script:dedicatedSqlScope.Bounds=New-Object Drawing.Rectangle(26,180,726,34);$script:dedicatedSqlScope.Items.AddRange(@('Local world - DEKARON_DEDICATED','Hosted world - DEKARON_DEDICATED_HOSTED'));$script:dedicatedSqlScope.SelectedIndex=0;$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlScope)
 [void](Add-DedicatedSqlLabel 'SQL instance: local or remote (Windows authentication)' 213 20 9)
 $script:dedicatedSqlInstance=New-Object Windows.Forms.TextBox;$script:dedicatedSqlInstance.Bounds=New-Object Drawing.Rectangle(26,233,726,26);$script:dedicatedSqlInstance.Text=$env:DEKARON_SQL_INSTANCE;$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlInstance)
 $script:dedicatedSqlInstance.Add_Leave({try{[void](Save-DedicatedSqlInstance $script:dedicatedSqlInstance.Text)}catch{$script:dedicatedSqlResult.Text=$_.Exception.Message}})
 $script:dedicatedSqlCheck=New-Object RoundedLauncherButton;$script:dedicatedSqlCheck.Text='Check SQL';$script:dedicatedSqlCheck.Bounds=New-Object Drawing.Rectangle(26,266,226,36);$script:dedicatedSqlCheck.ForeColor=$gold;$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlCheck);$script:dedicatedSqlCheck.Add_Click({Invoke-DedicatedSqlSetup '--check'})
 $script:dedicatedSqlSetup=New-Object RoundedLauncherButton;$script:dedicatedSqlSetup.Text='Set up SQL world';$script:dedicatedSqlSetup.Bounds=New-Object Drawing.Rectangle(274,266,230,36);$script:dedicatedSqlSetup.ForeColor=$gold;$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlSetup);$script:dedicatedSqlSetup.Add_Click({Invoke-DedicatedSqlSetup '--setup'})
 $script:dedicatedSqlInstall=New-Object RoundedLauncherButton;$script:dedicatedSqlInstall.Text='Prepare SQL automatically';$script:dedicatedSqlInstall.Bounds=New-Object Drawing.Rectangle(526,266,226,36);$script:dedicatedSqlInstall.ForeColor=$gold;$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlInstall);$script:dedicatedSqlInstall.Add_Click({Install-DedicatedSqlFromPage})
 $script:dedicatedSqlConsent=New-Object Windows.Forms.CheckBox;$script:dedicatedSqlConsent.Text='I accept Microsoft SQL Server Express license terms and privacy notice.';$script:dedicatedSqlConsent.Bounds=New-Object Drawing.Rectangle(26,306,726,28);$script:dedicatedSqlConsent.ForeColor=$muted;$script:dedicatedSqlPanel.Controls.Add($script:dedicatedSqlConsent)
 $terms=New-Object Windows.Forms.LinkLabel;$terms.Text='Review Microsoft license terms and SQL privacy notice';$terms.Bounds=New-Object Drawing.Rectangle(26,334,726,24);$terms.LinkColor=$gold;$script:dedicatedSqlPanel.Controls.Add($terms);$terms.Add_LinkClicked({Start-Process 'https://www.microsoft.com/en-us/useterms';Start-Process 'https://learn.microsoft.com/sql/sql-server/sql-server-privacy'})
 [void](Add-DedicatedSqlLabel "SQL stores your server's world data; players connect to the game server, never SQL.`r`nUse Hosting options for joining, LAN/VPN access and the existing public-directory opt-in." 359 42)
 $script:dedicatedSqlResult=Add-DedicatedSqlLabel 'Remote SQL needs TCP access and permission for your Windows identity. Check SQL before setup.' 404 34
 $back=New-Object RoundedLauncherButton;$back.Text='Back';$back.Bounds=New-Object Drawing.Rectangle(590,438,162,34);$back.ForeColor=$muted;$script:dedicatedSqlPanel.Controls.Add($back);$back.Add_Click({$script:dedicatedSqlPanel.Visible=$false;Show-ClientSettingsPanel})
 $sqlButton=New-Object RoundedLauncherButton;$sqlButton.Text='SQL / VPS';$sqlButton.Bounds=New-Object Drawing.Rectangle(424,14,150,34);$sqlButton.ForeColor=$gold;$script:settingsPanel.Controls.Add($sqlButton);$sqlButton.Add_Click({Show-DedicatedSqlPage})
 $script:startupLocalStorage=New-Object Windows.Forms.RadioButton;$script:startupLocalStorage.Text='Local';$script:startupLocalStorage.AccessibleName='Local file server';$script:startupLocalStorage.Bounds=New-Object Drawing.Rectangle(238,20,82,26);$script:startupLocalStorage.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:startupLocalStorage)
 $script:startupSqlStorage=New-Object Windows.Forms.RadioButton;$script:startupSqlStorage.Text='SQL';$script:startupSqlStorage.AccessibleName='SQL server';$script:startupSqlStorage.Bounds=New-Object Drawing.Rectangle(327,20,78,26);$script:startupSqlStorage.ForeColor=$gold;$script:settingsPanel.Controls.Add($script:startupSqlStorage)
 $script:startupLocalStorage.Add_Click({Select-StartupStorage 'json'})
 $script:startupSqlStorage.Add_Click({Select-StartupStorage 'sqlserver'})
 Sync-StartupStorageChoice
 foreach($button in @($script:settingsTab,$script:hostButton,$script:connectButton,$script:hostingOptions,$primary,$website)){$button.Add_Click({if($script:dedicatedSqlPanel){$script:dedicatedSqlPanel.Visible=$false}})}
}
