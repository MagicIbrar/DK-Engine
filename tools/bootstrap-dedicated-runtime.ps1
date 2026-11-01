param([switch]$CheckOnly,[switch]$InstallSql,[switch]$AcceptSqlLicense)
$ErrorActionPreference='Stop'
# A PowerShell 7 host may pass its incompatible module search path into Windows PowerShell.
# Scope this repair to this child process; signature verification remains mandatory.
if($PSVersionTable.PSEdition -eq 'Desktop'){
 $env:PSModulePath=(Join-Path $env:ProgramFiles 'WindowsPowerShell\Modules')+';'+(Join-Path $PSHOME 'Modules')
 [Environment]::SetEnvironmentVariable('PSModuleAnalysisCachePath',$null,'Process')
}

[Net.ServicePointManager]::SecurityProtocol=[Net.SecurityProtocolType]::Tls12

function Test-SignedBy([string]$File,[string]$Publisher){
  $signature=Get-AuthenticodeSignature -LiteralPath $File
  return $signature.Status -eq 'Valid' -and $signature.SignerCertificate -and $signature.SignerCertificate.Subject.Contains($Publisher)
}
function Test-Node24([string]$File){
  if(-not $File -or -not (Test-Path -LiteralPath $File -PathType Leaf)){return $false}
  try{$version=(& $File --version | Select-Object -First 1)}catch{return $false}
  return $version -match '^v(\d+)\.' -and [int]$Matches[1] -ge 24
}
function Find-Node24{
  $bundled=Join-Path $PSScriptRoot '..\runtime\node.exe'
  if((Test-Node24 $bundled) -and (Test-SignedBy $bundled 'OpenJS Foundation')){return [IO.Path]::GetFullPath($bundled)}
  $command=Get-Command node.exe -ErrorAction SilentlyContinue | Select-Object -First 1
  if($command -and (Test-Node24 $command.Source)){return $command.Source}
  $cached=Join-Path $env:LOCALAPPDATA 'Dekaron Dedicated Setup\Runtime\node.exe'
  if((Test-Node24 $cached) -and (Test-SignedBy $cached 'OpenJS Foundation')){return $cached}
  return $null
}
function Test-WebView2{
  $folders=@()
  if(${env:ProgramFiles(x86)}){$folders+=Join-Path ${env:ProgramFiles(x86)} 'Microsoft\EdgeWebView\Application'}
  if($env:ProgramFiles){$folders+=Join-Path $env:ProgramFiles 'Microsoft\EdgeWebView\Application'}
  if($env:LOCALAPPDATA){$folders+=Join-Path $env:LOCALAPPDATA 'Microsoft\EdgeWebView\Application'}
  foreach($folder in $folders){
    if(-not (Test-Path -LiteralPath $folder -PathType Container)){continue}
    foreach($child in (Get-ChildItem -LiteralPath $folder -Directory -ErrorAction SilentlyContinue)){
      if(Test-Path -LiteralPath (Join-Path $child.FullName 'msedgewebview2.exe') -PathType Leaf){return $true}
    }
  }
  return $false
}
function Test-SqlExpress{
  $service=Get-Service -Name 'MSSQL$SQLEXPRESS' -ErrorAction SilentlyContinue
  return $null -ne $service
}
function Get-NodeLicenseVersion([string]$Node){return ((& $Node --version|Select-Object -First 1).Trim())}
function Test-NodeLicense([string]$File){return (Test-Path -LiteralPath $File -PathType Leaf) -and (Get-Item -LiteralPath $File).Length -gt 4096 -and (Get-Content -LiteralPath $File -Raw).StartsWith('Node.js is licensed for use as follows:')}
function Ensure-NodeLicense([string]$Node){
 $version=Get-NodeLicenseVersion $Node;if($version -notmatch '^v\d+\.\d+\.\d+$'){throw 'Cannot determine the exact Node.js version for its license notices.'}
 $cache=Join-Path $env:LOCALAPPDATA ('Dekaron Dedicated Setup\Licenses\'+$version);$target=Join-Path $cache 'LICENSE'
 foreach($candidate in @((Join-Path ([IO.Path]::GetDirectoryName($Node)) 'LICENSE'),(Join-Path $PSScriptRoot ('runtime-licenses\node-'+$version+'-LICENSE')),$target)){if(Test-NodeLicense $candidate){return $candidate}}
 New-Item -ItemType Directory -Path $cache -Force|Out-Null
 if(Test-Path -LiteralPath $target){throw 'Cached Node.js license is invalid; restore the exact release LICENSE before retrying.'}
 $download=Join-Path $cache ('LICENSE-'+[Guid]::NewGuid().ToString('N')+'.tmp')
 try{Invoke-WebRequest -Uri ('https://raw.githubusercontent.com/nodejs/node/'+$version+'/LICENSE') -OutFile $download -UseBasicParsing;if(-not (Test-NodeLicense $download)){throw 'Official Node.js license notices were incomplete.'};Move-Item -LiteralPath $download -Destination $target;return $target}finally{if(Test-Path -LiteralPath $download){Remove-Item -LiteralPath $download -Force}}
}
function Ensure-Node24{
  $existing=Find-Node24
  if($existing){Ensure-NodeLicense $existing|Out-Null;return $existing}
  $arch=if($env:PROCESSOR_ARCHITECTURE -eq 'ARM64'){'win-arm64'}else{'win-x64'}
  $base='https://nodejs.org/download/release/latest-v24.x/'
  $hashes=(Invoke-WebRequest -Uri ($base+'SHASUMS256.txt') -UseBasicParsing).Content
  $line=($hashes -split "`n" | Where-Object {$_ -match ('^[a-fA-F0-9]{64}\s+'+$arch+'/node\.exe\s*$')} | Select-Object -First 1)
  if(-not $line){throw 'Official Node.js release checksum for this Windows architecture was not found.'}
  $expected=($line -split '\s+')[0].ToLowerInvariant()
  $folder=Join-Path $env:LOCALAPPDATA 'Dekaron Dedicated Setup\Runtime'
  New-Item -ItemType Directory -Path $folder -Force | Out-Null
  $target=Join-Path $folder 'node.exe'
  if(Test-Path -LiteralPath $target){throw 'Cached Node.js is invalid. Remove only the cached Dekaron Dedicated Setup Runtime folder and retry.'}
  $download=Join-Path $folder ('node-'+[Guid]::NewGuid().ToString('N')+'.exe')
  try{
    Invoke-WebRequest -Uri ($base+$arch+'/node.exe') -OutFile $download -UseBasicParsing
    $actual=(Get-FileHash -LiteralPath $download -Algorithm SHA256).Hash.ToLowerInvariant()
    if($actual -ne $expected){throw 'Node.js download checksum did not match the official release.'}
    if(-not (Test-SignedBy $download 'OpenJS Foundation')){throw 'Node.js signature was not from OpenJS Foundation.'}
    if(-not (Test-Node24 $download)){throw 'Downloaded Node.js is older than version 24.'}
    Move-Item -LiteralPath $download -Destination $target
    Ensure-NodeLicense $target|Out-Null
    return $target
  }finally{if(Test-Path -LiteralPath $download){Remove-Item -LiteralPath $download -Force}}
}
function Ensure-WebView2{
  if(Test-WebView2){return}
  $download=Join-Path ([IO.Path]::GetTempPath()) ('dekaron-webview2-'+[Guid]::NewGuid().ToString('N')+'.exe')
  try{
    Invoke-WebRequest -Uri 'https://go.microsoft.com/fwlink/p/?LinkId=2124703' -OutFile $download -UseBasicParsing
    if(-not (Test-SignedBy $download 'Microsoft Corporation')){throw 'WebView2 installer signature was not from Microsoft Corporation.'}
    $process=Start-Process -FilePath $download -ArgumentList @('/silent','/install') -WindowStyle Hidden -Wait -PassThru
    if($process.ExitCode -ne 0){throw ('WebView2 installer exited with code '+$process.ExitCode)}
    for($i=0;$i -lt 15 -and -not (Test-WebView2);$i++){Start-Sleep -Seconds 2}
    if(-not (Test-WebView2)){throw 'WebView2 setup completed but the Runtime could not be found.'}
  }finally{if(Test-Path -LiteralPath $download){Remove-Item -LiteralPath $download -Force}}
}

if($MyInvocation.InvocationName -eq '.'){return}
if($CheckOnly){
  [pscustomobject]@{node24=[bool](Find-Node24);webView2=[bool](Test-WebView2);sqlExpressInstalled=[bool](Test-SqlExpress)} | ConvertTo-Json -Compress
  exit 0
}
if($InstallSql){ & (Join-Path $PSScriptRoot 'install-dedicated-sql.ps1') -AcceptLicense:$AcceptSqlLicense }
Ensure-WebView2
$node=Ensure-Node24
if(-not $node){throw 'Node.js 24 could not be prepared.'}
Write-Output $node


