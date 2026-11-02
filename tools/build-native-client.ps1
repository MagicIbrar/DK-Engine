# Compile GameWindow.exe (tools/DKClient.cs, the native DX11 client window) with the Windows inbox .NET Framework compiler.
$ErrorActionPreference='Stop'
$engine=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$source=Join-Path $PSScriptRoot 'DKClient.cs'
$output=Join-Path $engine 'GameWindow.exe'
$icon=Join-Path $engine 'client-assets\dekaron-client.ico'
if(-not (Test-Path -LiteralPath $icon -PathType Leaf)){& (Join-Path $PSScriptRoot 'build-client-icon.ps1')}
foreach($target in @($engine,$source,$output)) {
 $ancestor=$target
 while($ancestor) {
  if(Test-Path -LiteralPath $ancestor){if(((Get-Item -LiteralPath $ancestor -Force).Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0){throw "Native client build rejects a link/junction: $ancestor"}}
  $parent=[IO.Path]::GetDirectoryName($ancestor);if($parent -eq $ancestor){break};$ancestor=$parent
 }
}
$compiler=@((Join-Path $env:WINDIR 'Microsoft.NET\Framework64\v4.0.30319\csc.exe'),(Join-Path $env:WINDIR 'Microsoft.NET\Framework\v4.0.30319\csc.exe')) | Where-Object {Test-Path -LiteralPath $_} | Select-Object -First 1
if(-not $compiler){throw 'The Windows .NET Framework C# compiler was not found. GameWindow.exe was not changed.'}
$temporary=Join-Path $engine ('native-build-'+[Guid]::NewGuid().ToString('N')+'.exe')
try {
 & $compiler /nologo /target:winexe /platform:anycpu /optimize+ /reference:System.Windows.Forms.dll /reference:System.Drawing.dll ("/win32icon:"+$icon) ("/win32manifest:"+(Join-Path $PSScriptRoot 'DKClient.manifest')) ("/out:"+$temporary) $source
 if($LASTEXITCODE -ne 0){throw 'GameWindow.exe compilation failed. The previous GameWindow.exe remains unchanged.'}
 Move-Item -LiteralPath $temporary -Destination $output -Force
 Write-Output 'Built GameWindow.exe (native DX11 client window) using the Windows .NET Framework compiler.'
} finally {
 if([IO.Path]::GetDirectoryName($temporary) -ne $engine){throw 'Unsafe native client build cleanup path'}
 if(Test-Path -LiteralPath $temporary){Remove-Item -LiteralPath $temporary -Force}
}
