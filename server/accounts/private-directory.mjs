// Opt-in local account directory isolation. No child process on the atomic-save path.
import path from 'node:path';
import fs from 'node:fs/promises';
import {spawn} from 'node:child_process';
import {createHash} from 'node:crypto';
const pinned=new Map(),required=new Set();
const key=p=>path.resolve(p).toLowerCase();
const quote=s=>"'"+String(s).replaceAll("'","''")+"'";
export const sha=b=>createHash('sha256').update(b).digest('hex');
export function directoryScope({engine,store}){const e=path.resolve(engine),s=path.resolve(store);if(!/^[A-Za-z]:[\\/]/.test(e)||key(s)!==key(path.join(e,'server/accounts/data.json')))throw Error('Explicit default local account store required.');return{engine:e,store:s,directory:path.dirname(s)};}
export async function ordinaryPath(file){let at=path.resolve(file);for(;;){const s=await fs.lstat(at);if(s.isSymbolicLink()||s.isFile()&&s.nlink!==1)throw Error('Unlinked ordinary path required.');const p=path.dirname(at);if(p===at)break;at=p;}}
// Win32 directory handles are duplicated into this Node process. Their sharing restrictions
// survive helper exit and are released by OS process exit (or explicit stopped-context release).
export const native=String.raw`
Add-Type -TypeDefinition @'
using System;using System.IO;using System.Runtime.InteropServices;using System.Text;using System.Collections.Generic;
public static class C21DirectoryNative {
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)]static extern IntPtr CreateFileW(string p,uint access,uint share,IntPtr sa,uint create,uint flags,IntPtr template);
 [DllImport("kernel32.dll",SetLastError=true)]public static extern bool CloseHandle(IntPtr h);
 [DllImport("kernel32.dll",SetLastError=true)]static extern IntPtr OpenProcess(uint access,bool inherit,uint pid);
 [DllImport("kernel32.dll")]static extern IntPtr GetCurrentProcess();
 [DllImport("kernel32.dll",SetLastError=true)]static extern bool DuplicateHandle(IntPtr sp,IntPtr sh,IntPtr tp,out IntPtr th,uint access,bool inherit,uint options);
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)]static extern uint GetFinalPathNameByHandleW(IntPtr h,StringBuilder b,uint size,uint flags);
 [StructLayout(LayoutKind.Sequential)]public struct Info {public uint attrs,a,b,c,d,e,f,volume,high,low,links,indexHigh,indexLow;}
 [DllImport("kernel32.dll",SetLastError=true)]static extern bool GetFileInformationByHandle(IntPtr h,out Info info);
 public static List<IntPtr> Pin(string directory){var drive=new DriveInfo(Path.GetPathRoot(directory));if(drive.DriveFormat!="NTFS"||drive.DriveType!=DriveType.Fixed)throw new Exception("C21_FILESYSTEM");var chain=new List<string>();for(var p=new DirectoryInfo(Path.GetFullPath(directory));p!=null;p=p.Parent)chain.Add(p.FullName);if(chain.Count>32)throw new Exception("C21_DEPTH");chain.Reverse();var result=new List<IntPtr>();try{foreach(var p in chain){var h=CreateFileW(p,0x80020000,3,IntPtr.Zero,3,0x02200000,IntPtr.Zero);if(h==new IntPtr(-1))throw new Exception("C21_PIN");result.Add(h);Info i;if(!GetFileInformationByHandle(h,out i)||(i.attrs&0x400)!=0||(i.attrs&0x10)==0)throw new Exception("C21_REPARSE");var b=new StringBuilder(32768);var n=GetFinalPathNameByHandleW(h,b,32768,0);if(n==0||n>=32768)throw new Exception("C21_IDENTITY");var resolved=b.ToString();if(resolved.StartsWith(@"\\?\"))resolved=resolved.Substring(4);if(!String.Equals(resolved.TrimEnd('\\'),p.TrimEnd('\\'),StringComparison.OrdinalIgnoreCase))throw new Exception("C21_IDENTITY");}return result;}catch{foreach(var h in result)CloseHandle(h);throw;}}
 public static long[] Transfer(List<IntPtr> handles,uint pid){var proc=OpenProcess(0x40,false,pid);if(proc==IntPtr.Zero)throw new Exception("C21_PROCESS");var result=new List<long>();try{foreach(var h in handles){IntPtr copy;if(!DuplicateHandle(GetCurrentProcess(),h,proc,out copy,0,false,2))throw new Exception("C21_DUPLICATE");result.Add(copy.ToInt64());}return result.ToArray();}catch{foreach(var v in result){IntPtr ignored;DuplicateHandle(proc,new IntPtr(v),IntPtr.Zero,out ignored,0,false,1);}throw;}finally{CloseHandle(proc);}}
 public static void Release(long[] handles,uint pid){var proc=OpenProcess(0x40,false,pid);if(proc==IntPtr.Zero)throw new Exception("C21_PROCESS");try{foreach(var v in handles){IntPtr ignored;if(!DuplicateHandle(proc,new IntPtr(v),IntPtr.Zero,out ignored,0,false,1))throw new Exception("C21_RELEASE");}}finally{CloseHandle(proc);}}
 public static void VerifyFile(string p){var h=CreateFileW(p,0x20080,7,IntPtr.Zero,3,0x00200000,IntPtr.Zero);if(h==new IntPtr(-1))throw new Exception("C21_FILE");try{Info i;if(!GetFileInformationByHandle(h,out i)||(i.attrs&0x410)!=0||i.links!=1)throw new Exception("C21_LINK");}finally{CloseHandle(h);}}
}
'@
`;
export const policy=String.raw`
$sid=[Security.Principal.WindowsIdentity]::GetCurrent().User
$trusted=@($sid.Value,'S-1-5-18','S-1-5-32-544')
function HashBytes($bytes){$h=[Security.Cryptography.SHA256]::Create();try{return ([BitConverter]::ToString($h.ComputeHash($bytes))).Replace('-','').ToLowerInvariant()}finally{$h.Dispose()}}
function HashAcl($a){return HashBytes $a.GetSecurityDescriptorBinaryForm()}
function PrivateAcl($a,$directory){
 $r=@($a.GetAccessRules($true,$true,[Security.Principal.SecurityIdentifier]));$seen=@{};$ok=$a.GetOwner([Security.Principal.SecurityIdentifier]).Value -in $trusted
 if($directory -and -not $a.AreAccessRulesProtected){$ok=$false}
 foreach($v in $r){$who=$v.IdentityReference.Value;if($who -notin $trusted -or $seen.ContainsKey($who) -or $v.AccessControlType -ne 'Allow' -or [int]$v.FileSystemRights -ne [int][Security.AccessControl.FileSystemRights]::FullControl){$ok=$false};$seen[$who]=$true
  if($directory -and ($v.IsInherited -or $v.InheritanceFlags -ne ([Security.AccessControl.InheritanceFlags]::ContainerInherit -bor [Security.AccessControl.InheritanceFlags]::ObjectInherit) -or $v.PropagationFlags -ne 'None')){$ok=$false}
  if(-not $directory -and ($v.InheritanceFlags -ne 'None' -or $v.PropagationFlags -ne 'None')){$ok=$false}
 }
 return [bool]($ok -and $r.Count -eq 3 -and $seen.ContainsKey($sid.Value) -and $seen.ContainsKey('S-1-5-18') -and $seen.ContainsKey('S-1-5-32-544'))
}
function Canonical($directory,$owner){
 $a=if($directory){New-Object Security.AccessControl.DirectorySecurity}else{New-Object Security.AccessControl.FileSecurity};$a.SetOwner($owner);$a.SetAccessRuleProtection($true,$false)
 foreach($who in $trusted){$s=New-Object Security.Principal.SecurityIdentifier($who);$flags=if($directory){'ContainerInherit,ObjectInherit'}else{'None'};$a.AddAccessRule((New-Object Security.AccessControl.FileSystemAccessRule($s,'FullControl',$flags,'None','Allow')))};return $a
}
function PrivateCreate($p,$bytes){$a=Canonical $false $sid;$h=[IO.FileStream]::new($p,[IO.FileMode]::CreateNew,[Security.AccessControl.FileSystemRights]::Write,[IO.FileShare]::None,4096,[IO.FileOptions]::WriteThrough,$a);try{if(-not (PrivateAcl ([IO.File]::GetAccessControl($p)) $false)){throw 'C21_CREATE_ACL'};$h.Write($bytes,0,$bytes.Length);$h.Flush($true)}finally{$h.Dispose()}}
function CheckContext($engine,$store,$additional){
 $e=[IO.Directory]::GetAccessControl($engine).GetOwner([Security.Principal.SecurityIdentifier]).Value
 if($e -ne $sid.Value -and $e -ne 'S-1-5-32-544'){throw 'C21_INSTALLATION_OWNER'}
 $d=[IO.Directory]::GetAccessControl([IO.Path]::GetDirectoryName($store));$a=[IO.File]::GetAccessControl($store)
 [C21DirectoryNative]::VerifyFile($store)
 if(-not (PrivateAcl $d $true) -or -not (PrivateAcl $a $false) -or $a.GetOwner([Security.Principal.SecurityIdentifier]).Value -ne $sid.Value){throw 'C21_PRIVATE_CONTEXT'}
 $extra=$true;if($additional){[C21DirectoryNative]::VerifyFile($additional);$x=[IO.File]::GetAccessControl($additional);$extra=(PrivateAcl $x $false) -and $x.GetOwner([Security.Principal.SecurityIdentifier]).Value -eq $sid.Value;if(-not $extra){throw 'C21_PRIVATE_EXTRA'}}
 return [pscustomobject]@{privateStore=$true;privateDirectory=$true;additionalPrivate=[bool]$extra}
}
`;
export async function windowsDirectoryScript(body){
 if(process.platform!=='win32')throw Error('Windows directory security required.');
 const systemRoot=process.env.SystemRoot;if(!systemRoot||!path.isAbsolute(systemRoot))throw Error('Absolute Windows system runtime required.');const powershell=path.join(systemRoot,'System32/WindowsPowerShell/v1.0/powershell.exe');const executable=await fs.lstat(powershell);if(!executable.isFile()||executable.isSymbolicLink())throw Error('Windows system runtime required.');
 const script="$ErrorActionPreference='Stop';"+native+policy+body;
 return new Promise((resolve,reject)=>{
  const p=spawn(powershell,['-NoProfile','-NonInteractive','-Command',"$ErrorActionPreference='Stop';[Console]::InputEncoding=[Text.UTF8Encoding]::new($false);[Console]::OutputEncoding=[Text.UTF8Encoding]::new($false);try{$s=[Console]::In.ReadToEnd(); & ([ScriptBlock]::Create($s))}catch{$code='DIRECTORY_REFUSED';if($_.Exception.ToString() -match '(C21_[A-Z_]+)'){$code=$Matches[1]};[pscustomobject]@{refusal=$code}|ConvertTo-Json -Compress;exit 1}"],{windowsHide:true,stdio:['pipe','pipe','pipe']});let out='',size=0;p.stdout.setEncoding('utf8');
  const timer=setTimeout(()=>{p.kill();reject(Error('Windows directory security timed out.'));},60000);
  const fail=()=>{clearTimeout(timer);let code='DIRECTORY_REFUSED';try{const r=JSON.parse(out.trim());const allowed=new Set(['C21_DEPTH','C21_PIN','C21_REPARSE','C21_IDENTITY','C21_PROCESS','C21_DUPLICATE','C21_RELEASE','C21_FILE','C21_LINK','C21_FILESYSTEM','C21_INSTALLATION_OWNER','C21_PRIVATE_CONTEXT','C21_PRIVATE_EXTRA','C21_NODE_LIMIT','C21_ALLOWLIST','C21_ALLOWLIST_CHANGED','C21_BYTE_LIMIT','C21_READ','C21_NODE_OWNER','C21_STORE_OWNER','C21_BYTES_CHANGED','C21_STALE_PLAN','C21_BACKUP_PARENT','C21_BACKUP_COLLISION','C21_BACKUP_ACL','C21_BACKUP_BYTES','C21_BACKUP_ACL_BYTES','C21_ACL_CHANGED','C21_NEW_ACL','C21_NODE_ADDED','C21_STALE_ROLLBACK','C21_ROLLBACK_PRIVATE','C21_ROLLBACK_NODES','C21_ROLLBACK_NODE','C21_ROLLBACK_RAW','C21_ROLLBACK_OWNER','C21_ROLLBACK_ACL_EXACT']);if(allowed.has(r.refusal))code=r.refusal;}catch{}reject(Error('Windows directory security refused: '+code));};
  p.on('error',fail);p.stdin.on('error',()=>{});p.stdout.on('data',b=>{size+=Buffer.byteLength(b,'utf8');if(size>4*1024*1024){p.stdout.destroy();fail();}else out+=b;});p.stderr.resume();
  p.on('close',code=>{clearTimeout(timer);if(code!==0)return fail();try{resolve(JSON.parse(out.trim()));}catch{fail();}});p.stdin.end(script,'utf8');
 });
}
export async function inspectPrivateAccountDirectory(options){const o=directoryScope(options);await ordinaryPath(o.store);let additional='';if(options.additionalFile){additional=path.resolve(options.additionalFile);if(key(path.dirname(additional))!==key(o.directory))throw Error('Private sibling required.');await ordinaryPath(additional);}return windowsDirectoryScript(`$locks=[C21DirectoryNative]::Pin(${quote(o.directory)});try{CheckContext ${quote(o.engine)} ${quote(o.store)} ${quote(additional)}|ConvertTo-Json -Compress}finally{foreach($h in $locks){[C21DirectoryNative]::CloseHandle($h)|Out-Null}}`);}
export async function pinPrivateAccountDirectory(options){const o=directoryScope(options),k=key(o.store);if(pinned.has(k))return;required.add(k);await ordinaryPath(o.store);
 const result=await windowsDirectoryScript(`$locks=[C21DirectoryNative]::Pin(${quote(o.directory)});try{$check=CheckContext ${quote(o.engine)} ${quote(o.store)} ''; $copies=[C21DirectoryNative]::Transfer($locks,${process.pid});[pscustomobject]@{handles=@($copies);privateStore=$true;privateDirectory=$true}|ConvertTo-Json -Compress}finally{foreach($h in $locks){[C21DirectoryNative]::CloseHandle($h)|Out-Null}}`);
 if(!result.privateStore||!Array.isArray(result.handles)||result.handles.length<1||result.handles.length>32||result.handles.some(h=>!Number.isSafeInteger(h)||h<=0))throw Error('Private directory pin refused.');pinned.set(k,result.handles);
}
export async function pinPrivateAccountBackup(options){const o=directoryScope(options),backup=path.resolve(options.backup);if(!pinned.has(key(o.store)))throw Error('Source private directory must already be pinned.');const parent=path.dirname(backup);if(key(parent)!==key(o.directory)&&(!/^C21-directory-backup-[a-f0-9]{12}$/i.test(path.basename(parent))||!/^original-\d{4}\.bin$/i.test(path.basename(backup))))throw Error('Reviewed sibling or directory-transition raw backup required.');await ordinaryPath(backup);const k=key(backup);if(pinned.has(k))return;
 const result=await windowsDirectoryScript(`$locks=[C21DirectoryNative]::Pin(${quote(parent)});try{$context=CheckContext ${quote(o.engine)} ${quote(o.store)} '';[C21DirectoryNative]::VerifyFile(${quote(backup)});$d=[IO.Directory]::GetAccessControl(${quote(parent)});$a=[IO.File]::GetAccessControl(${quote(backup)});if(-not (PrivateAcl $d $true) -or -not (PrivateAcl $a $false) -or $a.GetOwner([Security.Principal.SecurityIdentifier]).Value -ne $sid.Value){throw 'C21_PRIVATE_EXTRA'};$copies=[C21DirectoryNative]::Transfer($locks,${process.pid});[pscustomobject]@{handles=@($copies);additionalPrivate=$true}|ConvertTo-Json -Compress}finally{foreach($h in $locks){[C21DirectoryNative]::CloseHandle($h)|Out-Null}}`);
 if(!result.additionalPrivate||!Array.isArray(result.handles)||result.handles.length<1||result.handles.some(h=>!Number.isSafeInteger(h)||h<=0))throw Error('Private backup pin refused.');pinned.set(k,result.handles);
}
export function assertPrivateAccountDirectory(file){const k=key(file);if(required.has(k)||process.env.DEKARON_PRIVATE_ACCOUNT_DIR==='1'&&path.basename(file).toLowerCase()==='data.json'){if(!pinned.has(k))throw Error('Private account directory must be pinned before saving.');}}
// Only after all operations for this context are stopped. Required status is retained so writes refuse.
export async function releasePrivateAccountDirectory(file){const k=key(file),handles=pinned.get(k);if(!handles)return;pinned.delete(k);await windowsDirectoryScript(`[C21DirectoryNative]::Release([long[]]@(${handles.join(',')}),${process.pid});[pscustomobject]@{released=$true}|ConvertTo-Json -Compress`);}
export const psQuote=quote;
