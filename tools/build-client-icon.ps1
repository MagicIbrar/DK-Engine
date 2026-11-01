# Lossless PNG-in-ICO packaging plus ordinary size resampling for Windows icon sizes.
$ErrorActionPreference='Stop'
Add-Type -AssemblyName System.Drawing
$iconEngine=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$iconSource=Join-Path $iconEngine 'client-assets\dk-engine-emblem-v1.png'
$iconTarget=Join-Path $iconEngine 'client-assets\dk-engine.ico'
$sourceImage=[Drawing.Image]::FromFile($iconSource)
$iconImages=New-Object 'System.Collections.Generic.List[byte[]]'
$iconSizes=@(16,24,32,48,64,128,256)
try {
 foreach($size in $iconSizes){
  $bitmap=New-Object Drawing.Bitmap($size,$size);$graphics=[Drawing.Graphics]::FromImage($bitmap);$stream=New-Object IO.MemoryStream
  try{$graphics.InterpolationMode='HighQualityBicubic';$graphics.CompositingQuality='HighQuality';$graphics.Clear([Drawing.Color]::Transparent);$graphics.DrawImage($sourceImage,0,0,$size,$size);$bitmap.Save($stream,[Drawing.Imaging.ImageFormat]::Png);$iconImages.Add($stream.ToArray())}
  finally{$stream.Dispose();$graphics.Dispose();$bitmap.Dispose()}
 }
 $file=[IO.File]::Create($iconTarget);$writer=New-Object IO.BinaryWriter($file)
 try{
  $writer.Write([uint16]0);$writer.Write([uint16]1);$writer.Write([uint16]$iconImages.Count)
  $offset=6+16*$iconImages.Count
  for($i=0;$i -lt $iconImages.Count;$i++){$dimension=if($iconSizes[$i] -eq 256){0}else{$iconSizes[$i]};$writer.Write([byte]$dimension);$writer.Write([byte]$dimension);$writer.Write([byte]0);$writer.Write([byte]0);$writer.Write([uint16]1);$writer.Write([uint16]32);$writer.Write([uint32]$iconImages[$i].Length);$writer.Write([uint32]$offset);$offset+=$iconImages[$i].Length}
  foreach($bytes in $iconImages){$writer.Write($bytes)}
 }finally{$writer.Dispose();$file.Dispose()}
}finally{$sourceImage.Dispose()}
Write-Output 'Built matching desktop icon in seven Windows sizes.'
