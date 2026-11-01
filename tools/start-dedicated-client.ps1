param([switch]$Resume,[switch]$Setup,[string]$InstallRoot,[string]$GlobalData)
$ErrorActionPreference='Stop'
# A PowerShell 7 host may pass its incompatible module search path into Windows PowerShell.
# Scope this repair to this child process; signature verification remains mandatory.
if($PSVersionTable.PSEdition -eq 'Desktop'){
 $env:PSModulePath=(Join-Path $env:ProgramFiles 'WindowsPowerShell\Modules')+';'+(Join-Path $PSHOME 'Modules')
 [Environment]::SetEnvironmentVariable('PSModuleAnalysisCachePath',$null,'Process')
}


function New-DedicatedSetupWindow([string]$Engine){
 Add-Type -AssemblyName System.Windows.Forms;Add-Type -AssemblyName System.Drawing
 if(-not ('LauncherWindow' -as [type])){Add-Type -Path (Join-Path $Engine 'tools\LauncherVisuals.cs') -ReferencedAssemblies System.Windows.Forms,System.Drawing}
 [Windows.Forms.Application]::EnableVisualStyles()
 $form=New-Object LauncherWindow;[LauncherIdentity]::Apply($form,$Engine);$form.Text='DK Setup - Prepare your engine';$form.ClientSize=New-Object Drawing.Size(900,570);$form.StartPosition='CenterScreen';$form.FormBorderStyle='FixedSingle';$form.MaximizeBox=$false;$form.ControlBox=$false;$form.Font=New-Object Drawing.Font('Segoe UI',11);$form.ForeColor=[Drawing.Color]::FromArgb(235,229,217)
 foreach($asset in @(@('launcher-background-v1.png','background'),@('dk-engine-logo-v1.png','logo'))){
  $path=Join-Path $Engine ('client-assets\'+$asset[0]);if(Test-Path -LiteralPath $path){$stream=[IO.File]::OpenRead($path);try{$original=[Drawing.Image]::FromStream($stream);try{$image=$original.Clone()}finally{$original.Dispose()}}finally{$stream.Dispose()}
   if($asset[1] -eq 'background'){$form.Artwork=$image}else{$logo=New-Object Windows.Forms.PictureBox;$logo.Image=$image;$logo.SizeMode='Zoom';$logo.BackColor=[Drawing.Color]::Transparent;$logo.Bounds=New-Object Drawing.Rectangle(255,24,390,180);$form.Controls.Add($logo);$script:entryLogo=$logo}
  }
 }
 $heading=New-Object Windows.Forms.Label;$heading.Text='Prepare your dedicated engine';$heading.Font=New-Object Drawing.Font('Segoe UI',22,[Drawing.FontStyle]::Bold);$heading.ForeColor=[Drawing.Color]::FromArgb(214,177,115);$heading.BackColor=[Drawing.Color]::Transparent;$heading.Bounds=New-Object Drawing.Rectangle(48,214,804,48);$form.Controls.Add($heading)
 $script:entryPhase=New-Object Windows.Forms.Label;$script:entryPhase.Text='1 / 4  CHECK DEPENDENCIES';$script:entryPhase.BackColor=[Drawing.Color]::Transparent;$script:entryPhase.ForeColor=[Drawing.Color]::FromArgb(214,177,115);$script:entryPhase.Bounds=New-Object Drawing.Rectangle(50,280,800,28);$form.Controls.Add($script:entryPhase)
 $script:entryLabel=New-Object Windows.Forms.Label;$script:entryLabel.Text='Checking the components needed to open DK Client.';$script:entryLabel.BackColor=[Drawing.Color]::Transparent;$script:entryLabel.Bounds=New-Object Drawing.Rectangle(50,318,800,60);$form.Controls.Add($script:entryLabel)
 $script:entryProgress=New-Object GalaxyProgress;$script:entryProgress.Bounds=New-Object Drawing.Rectangle(48,384,804,92);$script:entryProgress.Running=$true;$script:entryProgress.DetailText='Checking dependencies';$form.Controls.Add($script:entryProgress)
 $note=New-Object Windows.Forms.Label;$note.Text='Original downloads and existing saves stay preserved. The galaxy launcher opens when ready.';$note.BackColor=[Drawing.Color]::Transparent;$note.ForeColor=[Drawing.Color]::FromArgb(190,198,213);$note.Font=New-Object Drawing.Font('Segoe UI',10);$note.Bounds=New-Object Drawing.Rectangle(50,503,800,42);$form.Controls.Add($note)
 return $form
}
function Update-DedicatedSetupProgress([string]$Message){
 if(-not $script:entryProgress){return}
 $script:entryLabel.Text=$Message.Substring(0,[Math]::Min(300,$Message.Length))
 if($Message -match 'Extracted ([\d,]+)/([\d,]+) files'){$done=[double]($Matches[1]-replace ',','');$total=[double]($Matches[2]-replace ',','');$script:entryPhase.Text='2 / 4  PREPARE GLOBAL FILES';$script:entryProgress.Value=[int](100*$done/[Math]::Max(1,$total));$script:entryProgress.DetailText=('{0:N0} / {1:N0} files' -f $done,$total)}
 elseif($Message -match 'Preparing |Prepared |builder'){$script:entryPhase.Text='2 / 4  BUILD GAME DATA';$script:entryProgress.Value=0;$script:entryProgress.DetailText='Building game indexes'}
 elseif($Message -match 'Global files (\w+): (\d+)% \(([^)]+)\)'){$script:entryPhase.Text='3 / 4  VALIDATE INSTALLATION';$script:entryProgress.Value=[int]$Matches[2];$script:entryProgress.DetailText=$Matches[3]}
 elseif($Message -match 'Looking for'){$script:entryPhase.Text='2 / 4  FIND GLOBAL DATA';$script:entryProgress.Value=0;$script:entryProgress.DetailText='Finding your Global download'}
 elseif($Message -match 'Opening the galaxy'){$script:entryPhase.Text='4 / 4  OPEN GALAXY LAUNCHER';$script:entryProgress.Value=100;$script:entryProgress.DetailText='Starting DK Client'}
}
function Close-DedicatedSetupWindow{
 if($script:entryProgress){$script:entryProgress.Running=$false}
 if($script:entryForm){$art=$script:entryForm.Artwork;$script:entryForm.Dispose();if($art){$art.Dispose()}}
 if($script:entryLogo -and $script:entryLogo.Image){$script:entryLogo.Image.Dispose()}
}

function ConvertTo-EntryArgument([string]$Value){
 $b=New-Object Text.StringBuilder;[void]$b.Append('"');$slashes=0
 foreach($c in $Value.ToCharArray()){if($c -eq '\'){$slashes++;continue};if($c -eq '"'){[void]$b.Append('\',2*$slashes+1)}else{[void]$b.Append('\',$slashes)};[void]$b.Append($c);$slashes=0}
 [void]$b.Append('\',2*$slashes);[void]$b.Append('"');return $b.ToString()
}
function Invoke-EntryProcess([string]$File,[string[]]$Arguments,[string]$Status){
 if($script:entryLabel){$script:entryLabel.Text=$Status;Update-DedicatedSetupProgress $Status;[Windows.Forms.Application]::DoEvents()}
 $start=New-Object Diagnostics.ProcessStartInfo;$start.FileName=$File;$start.Arguments=($Arguments|ForEach-Object {ConvertTo-EntryArgument $_}) -join ' ';$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true
 if($script:entryLog){[IO.File]::AppendAllText($script:entryLog,('[stage] '+$Status+[Environment]::NewLine))}
 if([IO.Path]::GetFileName($File) -ieq 'powershell.exe'){[void]$start.EnvironmentVariables.Remove('PSModulePath');[void]$start.EnvironmentVariables.Remove('PSModuleAnalysisCachePath')}
 $process=[Diagnostics.Process]::Start($start)
 try{
  $stdout=New-Object Text.StringBuilder;$stderr=New-Object Text.StringBuilder
  $outLine=$process.StandardOutput.ReadLineAsync();$errLine=$process.StandardError.ReadLineAsync()
  while(-not $process.HasExited -or $null -ne $outLine -or $null -ne $errLine){
   foreach($channel in @('out','err')){
    $task=if($channel -eq 'out'){$outLine}else{$errLine}
    if($null -eq $task -or -not $task.IsCompleted){continue}
    $line=$task.GetAwaiter().GetResult()
    if($null -ne $line){
     if($channel -eq 'out'){[void]$stdout.AppendLine($line)}else{[void]$stderr.AppendLine($line)}
     if($script:entryLog){[IO.File]::AppendAllText($script:entryLog,('['+$channel+'] '+$line+[Environment]::NewLine))}
     if($script:entryLabel -and $channel -eq 'err' -and $line){Update-DedicatedSetupProgress $line}
     if($channel -eq 'out'){$outLine=$process.StandardOutput.ReadLineAsync()}else{$errLine=$process.StandardError.ReadLineAsync()}
    }elseif($channel -eq 'out'){$outLine=$null}else{$errLine=$null}
   }
   if($script:entryForm){[Windows.Forms.Application]::DoEvents()};Start-Sleep -Milliseconds 30
  }
  $process.WaitForExit();if($process.ExitCode -ne 0){throw ($stderr.ToString()+$stdout.ToString()).Trim()};return $stdout.ToString().Trim()
 }finally{$process.Dispose()}
}
function Invoke-EntryBootstrap([string]$Engine){
 $reply=Invoke-EntryProcess 'powershell.exe' @('-NoProfile','-NonInteractive','-File',(Join-Path $Engine 'tools\bootstrap-dedicated-runtime.ps1')) 'Checking Node.js and WebView2. Missing official runtimes will be prepared.'
 $node=($reply -split "`r?`n"|Where-Object {$_ -match 'node\.exe$'}|Select-Object -Last 1)
 if(-not $node -or -not (Test-Path -LiteralPath $node -PathType Leaf)){throw 'The runtime helper did not return a prepared Node executable.'};return $node
}
function Assert-DedicatedSource([string]$Engine){
 $required=@('Client.exe','GameWindow.exe','tools\client-ui.ps1','tools\dedicated-client-entry.mjs','tools\stage-dedicated-install.mjs','tools\bootstrap-dedicated-runtime.ps1')
 $missing=@($required | Where-Object {-not (Test-Path -LiteralPath (Join-Path $Engine $_) -PathType Leaf)})
 if($missing.Count){throw ('This is not a complete DK Engine download: '+($missing -join ', ')+' is missing from '+$Engine+'. Extract the whole Engine folder from the DK package, then open its Client.exe. An older server folder cannot be used as the engine.')}
}
function Invoke-EntryPlan([string]$Node,[string]$Engine,[string]$Destination,[string]$Data,[switch]$Install){
 $arguments=@((Join-Path $Engine 'tools\dedicated-client-entry.mjs'),$(if($Install){'--install'}else{'--plan'}),'--engine',$Engine,'--destination',$Destination)
 if($Data){$arguments+=@('--global-data',$Data)};if($Install){$arguments+=@('--node-exe',$Node)}
 $reply=Invoke-EntryProcess $Node $arguments $(if($Install){'Preparing Global assets and the dedicated installation. Existing accounts and settings are preserved. This can take several minutes.'}else{'Looking for prepared assets or a nearby Global data folder.'})
 return $reply|ConvertFrom-Json
}
function Select-EntryFolder([string]$Message){
 $dialog=New-Object Windows.Forms.FolderBrowserDialog;$dialog.Description=$Message;$dialog.ShowNewFolderButton=$true
 try{if($dialog.ShowDialog() -ne [Windows.Forms.DialogResult]::OK){throw 'Setup cancelled. Original files and existing installations were preserved.'};return $dialog.SelectedPath}finally{$dialog.Dispose()}
}
function New-DedicatedGalaxyStartInfo([string]$Engine,[switch]$Resume,[switch]$Setup){
 $modern=Join-Path $Engine 'tools\command-center\DKCommandCenter.exe';$classic=Join-Path $Engine 'run\classic-launcher.flag'
 $start=New-Object Diagnostics.ProcessStartInfo
 if((Test-Path -LiteralPath $modern -PathType Leaf) -and -not (Test-Path -LiteralPath $classic)){
  $start.FileName=$modern;$start.Arguments='';$start.WorkingDirectory=$Engine;$start.UseShellExecute=$false;$start.WindowStyle='Normal';return $start
 }
 $scriptFile=Join-Path $Engine 'tools\client-ui.ps1';if(-not (Test-Path -LiteralPath $scriptFile)){throw ('The installed DK Engine folder is incomplete: '+$scriptFile+' is missing. Restore the complete Engine download; existing saves and original Global data can remain in place.')}
 $arguments=@('-NoProfile','-ExecutionPolicy','Bypass','-STA','-File',$scriptFile,'-Dedicated');if($Resume){$arguments+='-Resume'};if($Setup){$arguments+='-Setup'}
 $start.FileName='powershell.exe';$start.Arguments=($arguments|ForEach-Object {ConvertTo-EntryArgument $_}) -join ' ';$start.WorkingDirectory=$Engine;$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.WindowStyle='Normal';[void]$start.EnvironmentVariables.Remove('PSModulePath');[void]$start.EnvironmentVariables.Remove('PSModuleAnalysisCachePath');return $start
}
function Open-DedicatedGalaxy([string]$Engine,[switch]$Resume,[switch]$Setup){
 $start=New-DedicatedGalaxyStartInfo $Engine -Resume:$Resume -Setup:$Setup
 Update-DedicatedSetupProgress 'Opening DK Command Center. Your installation is ready.'
 $modern=$start.FileName -like '*DKCommandCenter.exe';$process=$null
 try{
  $process=[Diagnostics.Process]::Start($start);if(-not $process){throw 'The launcher did not start.'}
  $deadline=[DateTime]::UtcNow.AddSeconds(60);while([DateTime]::UtcNow -lt $deadline){$process.Refresh();if($process.HasExited){throw 'The launcher closed before opening its window.'};if($process.MainWindowHandle -ne [IntPtr]::Zero){return};[Windows.Forms.Application]::DoEvents();Start-Sleep -Milliseconds 100};throw 'The launcher did not open its window within 60 seconds.'
 }catch{
  if(-not $modern){throw}
  if($script:entryLog){[IO.File]::AppendAllText($script:entryLog,('[fallback] Command Center failed: '+$_.Exception.Message+[Environment]::NewLine))}
  $fallback=New-DedicatedGalaxyStartInfo $Engine -Resume:$Resume -Setup:$Setup
  # Build the classic start explicitly; the modern binary remains available for troubleshooting.
  $scriptFile=Join-Path $Engine 'tools\client-ui.ps1';$arguments=@('-NoProfile','-ExecutionPolicy','Bypass','-STA','-File',$scriptFile,'-Dedicated');if($Resume){$arguments+='-Resume'};if($Setup){$arguments+='-Setup'}
  $fallback.FileName='powershell.exe';$fallback.Arguments=($arguments|ForEach-Object {ConvertTo-EntryArgument $_}) -join ' ';$fallback.CreateNoWindow=$true;[void]$fallback.EnvironmentVariables.Remove('PSModulePath');[void]$fallback.EnvironmentVariables.Remove('PSModuleAnalysisCachePath')
  $old=[Diagnostics.Process]::Start($fallback);if(-not $old){throw 'Neither launcher could start.'};try{$deadline=[DateTime]::UtcNow.AddSeconds(60);while([DateTime]::UtcNow -lt $deadline){$old.Refresh();if($old.HasExited){throw 'The classic launcher also closed before opening.'};if($old.MainWindowHandle -ne [IntPtr]::Zero){return};[Windows.Forms.Application]::DoEvents();Start-Sleep -Milliseconds 100};throw 'The classic launcher did not open within 60 seconds.'}finally{$old.Dispose()}
 }finally{if($process){$process.Dispose()}}
}
function Start-DedicatedClient([string]$Engine,[string]$Destination,[string]$Data,[switch]$Resume,[switch]$Setup){
 Assert-DedicatedSource $Engine
 if(-not $Destination){$Destination=if($env:DEKARON_DEDICATED_INSTALL_DIR){$env:DEKARON_DEDICATED_INSTALL_DIR}else{$canonical=Join-Path $env:LOCALAPPDATA 'DK Engine';$legacy=@('Dekaron Dedicated','Dekaron Dedicated3.2.3') | ForEach-Object {Join-Path $env:LOCALAPPDATA $_} | Where-Object {Test-Path -LiteralPath $_} | Select-Object -First 1;if(-not (Test-Path -LiteralPath $canonical) -and $legacy){$legacy}else{$canonical}}}
 $node=Invoke-EntryBootstrap $Engine
 while($true){$plan=Invoke-EntryPlan $node $Engine $Destination $Data
  if($plan.route -eq 'ready'){Open-DedicatedGalaxy $plan.engine -Resume:$Resume -Setup:$Setup;return $plan.engine}
  if($plan.route -in @('install','update')){$plan=Invoke-EntryPlan $node $Engine $Destination $Data -Install;Open-DedicatedGalaxy $plan.engine -Resume:$Resume;return $plan.engine}
  if($plan.route -eq 'source-needed'){$Data=Select-EntryFolder $plan.message;continue}
  if($plan.route -eq 'destination-needed'){$Destination=Join-Path (Select-EntryFolder 'Choose a parent folder for DK Engine. Setup uses that persistent folder for future updates. Existing unrecognized folders will not be overwritten.') 'DK Engine';continue}
  throw 'The installation planner returned an unknown state.'
 }
}
if($MyInvocation.InvocationName -ne '.'){
 $script:entryForm=New-DedicatedSetupWindow ([IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..')));$script:entryForm.Show()
 $run=Join-Path ([IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))) 'run';[void][IO.Directory]::CreateDirectory($run);$script:entryLog=Join-Path $run ('setup-entry-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N').Substring(0,8)+'.log')
 try{[void](Start-DedicatedClient -Engine ([IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))) -Destination $InstallRoot -Data $GlobalData -Resume:$Resume -Setup:$Setup)}catch{[Windows.Forms.MessageBox]::Show($script:entryForm,($_.Exception.Message+"`r`n`r`nDetails: "+$script:entryLog),'DK Setup stopped','OK','Error')|Out-Null;exit 1}finally{Close-DedicatedSetupWindow}
}
