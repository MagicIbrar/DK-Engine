param([switch]$CheckOnly,[switch]$AcceptLicense,[string]$ProgressFile,[string]$InstanceName='SQLEXPRESS')
$ErrorActionPreference='Stop'
if($PSVersionTable.PSEdition -eq 'Desktop'){$env:PSModulePath=(Join-Path $env:ProgramFiles 'WindowsPowerShell\Modules')+';'+(Join-Path $PSHOME 'Modules');[Environment]::SetEnvironmentVariable('PSModuleAnalysisCachePath',$null,'Process')}
function Set-SqlSetupProgress([string]$Message){Write-Host $Message;if($ProgressFile){[IO.File]::WriteAllText($ProgressFile,$Message)}}
function Resolve-DedicatedSqlInstance([string]$Name){
 if($Name -notmatch '^[A-Za-z][A-Za-z0-9_]{0,15}$' -or $Name -in @('MSSQLSERVER','DEFAULT')){throw 'Choose a named SQL instance: 1-16 ASCII letters, digits or underscores, starting with a letter; MSSQLSERVER and DEFAULT are reserved.'}
 $Name.ToUpperInvariant()
}
function Get-DedicatedSqlState {
 param([string]$InstanceName='SQLEXPRESS')
 $InstanceName=Resolve-DedicatedSqlInstance $InstanceName
 $serviceName='MSSQL$'+$InstanceName
 $service=Get-Service -Name $serviceName -ErrorAction SilentlyContinue
 $registered=$false
 foreach($key in @('HKLM:\SOFTWARE\Microsoft\Microsoft SQL Server\Instance Names\SQL','HKLM:\SOFTWARE\WOW6432Node\Microsoft\Microsoft SQL Server\Instance Names\SQL')){$item=Get-ItemProperty -LiteralPath $key -ErrorAction SilentlyContinue;if($item -and $item.PSObject.Properties[$InstanceName]){$registered=$true}}
 [pscustomobject]@{installed=($null -ne $service -or $registered);instance=$InstanceName;service=$serviceName;status=$(if($service){[string]$service.Status}elseif($registered){'Registered'}else{'Missing'})}
}
function Get-DedicatedSystemCurl {
 $candidate=Join-Path ([Environment]::GetFolderPath('System')) 'curl.exe'
 if(Test-Path -LiteralPath $candidate -PathType Leaf){return $candidate}
 return $null
}
function Get-SqlDownloadTime {[DateTime]::UtcNow}
function Download-DedicatedSqlMedia([string]$Uri,[string]$Destination){
 if($Uri -notmatch '^https://download\.microsoft\.com/'){throw 'SQL media must use the official Microsoft HTTPS download host.'}
 $curl=Get-DedicatedSystemCurl
 if(-not $curl){Invoke-WebRequest -Uri $Uri -OutFile $Destination -UseBasicParsing -TimeoutSec 600;return}
 $errorFile=$Destination+'.curl-error.txt'
 $arguments='--disable --fail --location --proto =https --proto-redir =https --connect-timeout 30 --max-time 600 --retry 2 --retry-delay 2 --retry-max-time 600 --silent --show-error --output "'+$Destination+'" "'+$Uri+'"'
 $downloadProcess=$null
 try{
  $downloadProcess=Start-Process -FilePath $curl -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardError $errorFile -PassThru
  $deadline=(Get-SqlDownloadTime).AddSeconds(630)
  while(-not $downloadProcess.HasExited){
   if((Get-SqlDownloadTime) -gt $deadline){$downloadProcess.Kill();$downloadProcess.WaitForExit();throw 'SQL media download exceeded its time limit. Retry preparation.'}
   if(Test-Path -LiteralPath $Destination){$bytes=(Get-Item -LiteralPath $Destination -ErrorAction Stop).Length;Set-SqlSetupProgress ('Downloading Microsoft SQL Express: '+$bytes.ToString('N0')+' bytes received...')}
   Start-Sleep -Milliseconds 250
  }
  if($downloadProcess.ExitCode -ne 0){throw ('Microsoft SQL media download failed (curl exit '+$downloadProcess.ExitCode+'). Check your connection and retry. No installer was run.')}
  if(-not (Test-Path -LiteralPath $Destination -PathType Leaf) -or (Get-Item -LiteralPath $Destination).Length -eq 0){throw 'Microsoft SQL media download returned no data. No installer was run.'}
 }finally{if($downloadProcess){if(-not $downloadProcess.HasExited){$downloadProcess.Kill();$downloadProcess.WaitForExit()};$downloadProcess.Dispose()};if(Test-Path -LiteralPath $errorFile){Remove-Item -LiteralPath $errorFile -Force}}
}
function Assert-SqlMicrosoftSignature([string]$File){$signature=Get-AuthenticodeSignature -LiteralPath $File;if($signature.Status -ne 'Valid' -or -not $signature.SignerCertificate -or -not $signature.SignerCertificate.Subject.Contains('Microsoft Corporation')){throw 'SQL installer signature was not valid Microsoft Corporation. Setup stopped.'}}
function Get-SqlSetupOwner {return [Security.Principal.WindowsIdentity]::GetCurrent().Name}
function Start-DedicatedSqlServiceIfStopped {
 param([string]$InstanceName='SQLEXPRESS')
 $serviceName='MSSQL$'+(Resolve-DedicatedSqlInstance $InstanceName)
 $service=Get-Service -Name $serviceName -ErrorAction SilentlyContinue
 if($service -and [string]$service.Status -eq 'Stopped'){
  Set-SqlSetupProgress ('Approve Windows permission to start existing '+$InstanceName+'. Its configuration stays unchanged.')
  $shell=Join-Path ([Environment]::GetFolderPath('System')) 'WindowsPowerShell\v1.0\powershell.exe'
  $child=Start-Process -FilePath $shell -ArgumentList ('-NoProfile -NonInteractive -Command "try { Start-Service -Name '''+$serviceName+''' -ErrorAction Stop; exit 0 } catch { exit 1 }"') -Verb RunAs -WindowStyle Hidden -Wait -PassThru
  if($child.ExitCode -ne 0){throw ('Could not start '+$InstanceName+'. Approve Windows permission or start the service manually, then retry.')}
 }
}
function Get-SqlRestartReceipt([string]$InstanceName='SQLEXPRESS') {Join-Path $env:LOCALAPPDATA ('Dekaron Dedicated Setup\sql-restart-'+(Resolve-DedicatedSqlInstance $InstanceName)+'.txt')}
function Get-SqlBootIdentity {[string](Get-CimInstance Win32_OperatingSystem -ErrorAction Stop).LastBootUpTime.ToUniversalTime().Ticks}
function Assert-SqlRestartComplete {
 param([string]$InstanceName='SQLEXPRESS')
 $receipt=Get-SqlRestartReceipt $InstanceName
 if(Test-Path -LiteralPath $receipt){if([IO.File]::ReadAllText($receipt) -eq (Get-SqlBootIdentity)){throw 'SQL setup requires a Windows restart before database setup. Save your work, restart manually, then retry.'};Remove-Item -LiteralPath $receipt -Force}
}
function Save-SqlRestartRequired([string]$InstanceName='SQLEXPRESS') {$receipt=Get-SqlRestartReceipt $InstanceName;[void][IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($receipt));[IO.File]::WriteAllText($receipt,(Get-SqlBootIdentity))}
function Remove-DedicatedSqlTemporaryMedia([string]$Directory){
 $tempRoot=[IO.Path]::GetFullPath([IO.Path]::GetTempPath()).TrimEnd('\','/')
 $target=[IO.Path]::GetFullPath($Directory).TrimEnd('\','/')
 if([IO.Path]::GetDirectoryName($target) -ine $tempRoot -or [IO.Path]::GetFileName($target) -notmatch '^dekaron-sql2019-[a-f0-9]{32}$'){throw 'Unsafe SQL temporary cleanup target; files preserved.'}
 if(-not (Test-Path -LiteralPath $target)){return}
 # Check every ancestor and enumerate one directory at a time: never traverse a junction.
 $ancestor=$target
 while($ancestor){$item=Get-Item -LiteralPath $ancestor -Force -ErrorAction Stop;if($item.Attributes -band [IO.FileAttributes]::ReparsePoint){throw 'Linked SQL temporary cleanup path; files preserved.'};$parent=[IO.Path]::GetDirectoryName($ancestor);if($parent -eq $ancestor){break};$ancestor=$parent}
 $resolved=[IO.Path]::GetFullPath((Resolve-Path -LiteralPath $target -ErrorAction Stop).ProviderPath).TrimEnd('\','/')
 if($resolved -ine $target){throw 'SQL temporary cleanup resolution changed; files preserved.'}
 $pending=New-Object 'Collections.Generic.Stack[string]';$pending.Push($target)
 while($pending.Count){$current=$pending.Pop();foreach($item in Get-ChildItem -LiteralPath $current -Force -ErrorAction Stop){if($item.Attributes -band [IO.FileAttributes]::ReparsePoint){throw 'Linked SQL temporary media descendant; files preserved.'};if($item.PSIsContainer){$pending.Push($item.FullName)}}}
 Remove-Item -LiteralPath $target -Recurse -Force -ErrorAction Stop
}
function Invoke-DedicatedSqlSetup {
 param([switch]$CheckOnly,[switch]$AcceptLicense,[string]$InstanceName='SQLEXPRESS')
 $InstanceName=Resolve-DedicatedSqlInstance $InstanceName
 $state=Get-DedicatedSqlState -InstanceName $InstanceName
 if($CheckOnly){$state|ConvertTo-Json -Compress;return}
 Assert-SqlRestartComplete -InstanceName $InstanceName
 if($state.installed){Start-DedicatedSqlServiceIfStopped -InstanceName $InstanceName;Set-SqlSetupProgress ($InstanceName+' reused without configuration changes. No installer was run.');return}
 if(-not $AcceptLicense){throw 'Review and accept the Microsoft SQL Server Express license terms and privacy notice before automatic installation.'}
 if(-not [Environment]::Is64BitOperatingSystem -or $env:PROCESSOR_ARCHITECTURE -eq 'ARM64'){throw 'SQL Server 2019 Express requires supported x64 Windows.'}
 $owner=Get-SqlSetupOwner
 if(-not $owner -or $owner -match '["\r\n]'){throw 'Cannot safely determine the current Windows account for SQL administration.'}
 [Net.ServicePointManager]::SecurityProtocol=[Net.SecurityProtocolType]::Tls12
 # Official full Express media. Avoid the SSEI web wizard; setup.exe flags are documented by Microsoft Learn.
 $uri='https://download.microsoft.com/download/7/c/1/7c14e92e-bdcb-4f89-b7cf-93543e7112d1/SQLEXPR_x64_ENU.exe'
 $work=Join-Path ([IO.Path]::GetTempPath()) ('dekaron-sql2019-'+[Guid]::NewGuid().ToString('N'))
 [void][IO.Directory]::CreateDirectory($work);$download=Join-Path $work 'SQLEXPR_x64_ENU.exe';$media=Join-Path $work 'media'
 try{
  Set-SqlSetupProgress 'Downloading Microsoft SQL Express installation media...'
  Download-DedicatedSqlMedia $uri $download
  Assert-SqlMicrosoftSignature $download
  if((Get-DedicatedSqlState -InstanceName $InstanceName).installed){Set-SqlSetupProgress ($InstanceName+' appeared during download; reused without changes.');return}
  Set-SqlSetupProgress 'Verifying and extracting Microsoft SQL Express...'
  $extract=Start-Process -FilePath $download -ArgumentList ('/Q /x:"'+$media+'"') -WindowStyle Hidden -Wait -PassThru
  if($extract.ExitCode -ne 0){throw ('SQL media extraction failed (exit '+$extract.ExitCode+'). Retry setup.')}
  $setup=Join-Path $media 'setup.exe';Assert-SqlMicrosoftSignature $setup
  if((Get-DedicatedSqlState -InstanceName $InstanceName).installed){Set-SqlSetupProgress ($InstanceName+' appeared during preparation; reused without changes.');return}
  Set-SqlSetupProgress ('Approve Windows administrator permission. Installing '+$InstanceName+' in the background...')
  $arguments='/Q /ACTION=Install /FEATURES=SQLENGINE /INSTANCENAME='+$InstanceName+' /IACCEPTSQLSERVERLICENSETERMS /SUPPRESSPRIVACYSTATEMENTNOTICE /SQLSVCACCOUNT="NT SERVICE\MSSQL$'+$InstanceName+'" /SQLSVCSTARTUPTYPE=Automatic /SQLSYSADMINACCOUNTS="'+$owner+'" /ADDCURRENTUSERASSQLADMIN=False /TCPENABLED=0 /NPENABLED=0 /UpdateEnabled=True /INDICATEPROGRESS'
  # Only Microsoft-signed setup.exe is elevated. Windows authentication uses the original launcher user, even with alternate UAC credentials.
  $process=Start-Process -FilePath $setup -ArgumentList $arguments -WorkingDirectory $media -Verb RunAs -WindowStyle Hidden -Wait -PassThru
  if($process.ExitCode -in @(3010,1641)){Save-SqlRestartRequired -InstanceName $InstanceName;throw 'SQL setup requires a Windows restart. Save your work and restart manually, then click Prepare SQL again. Database setup has not run.'}
  if($process.ExitCode -ne 0){throw ('SQL setup cancelled or failed (exit '+$process.ExitCode+'). Retry after reviewing Microsoft logs: '+$env:ProgramFiles+'\Microsoft SQL Server\150\Setup Bootstrap\Log. Existing instances were not repaired or upgraded.')}
  if(-not (Get-DedicatedSqlState -InstanceName $InstanceName).installed){throw ($InstanceName+' was not found after setup. Review Microsoft setup logs before retrying.')}
  Set-SqlSetupProgress 'SQL Express is available. Preparing the selected engine world next...'
 }finally{Remove-DedicatedSqlTemporaryMedia $work}
}
if($MyInvocation.InvocationName -ne '.'){Invoke-DedicatedSqlSetup -CheckOnly:$CheckOnly -AcceptLicense:$AcceptLicense -InstanceName $InstanceName}
