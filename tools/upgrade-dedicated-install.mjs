// Owned portable installations only. SQL databases are never opened by this updater.
import fs from 'node:fs';
import {clientSource} from '../server/client-source.mjs';
import {sanitizeReleasePng} from './release-image.mjs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import {createHash,randomUUID} from 'node:crypto';
import {execFileSync} from 'node:child_process';
const PRODUCT='dekaron-dedicated-engine', MARKER='dedicated-install.json';
const CODE_ROOTS=['src','server','vendor','client-assets','deploy'];
const ROOT_CODE=['server.mjs','package.json','Client.exe','GameWindow.exe','Setup-DK.cmd','Dockerfile','compose.yaml','render.yaml','railway.json','.dockerignore','THIRD_PARTY_NOTICES.md'];
const TOOL_CODE=['client-ui.ps1','client-runtime.ps1','client-dashboard.ps1','client-dedicated-sql.ps1','start-dedicated-client.ps1','dedicated-client-entry.mjs','upgrade-dedicated-install.mjs'];
const slash=s=>s.split(path.sep).join('/');
function same(a,b){return path.resolve(a).toLowerCase()===path.resolve(b).toLowerCase();}
export function assertUnlinked(target){let current=path.resolve(target);for(;;){if(fs.existsSync(current)&&fs.lstatSync(current).isSymbolicLink())throw Error('Linked installation paths are not supported.');const parent=path.dirname(current);if(parent===current)break;current=parent;}}
function files(root,relative=''){const full=path.join(root,relative);assertUnlinked(full);if(!fs.existsSync(full))return [];if(fs.statSync(full).isFile())return [slash(relative)];return fs.readdirSync(full).sort().flatMap(n=>files(root,path.join(relative,n)));}
const serverState=rel=>rel.startsWith('server/')&&!/\.(?:mjs|ps1)$/i.test(rel)&&!/^server\/launcher-control(?:-\d+)?\.json$/i.test(rel);
function managedRuntimeFiles(root){return [...new Set([...ROOT_CODE,...files(root,'tools'),...CODE_ROOTS.flatMap(n=>files(root,n))])].filter(n=>fs.existsSync(path.join(root,n))&&(!n.startsWith('server/')||/\.(?:mjs|ps1)$/.test(n))).sort();}
const PACKAGE_PNGS=new Set(['client-assets/dk-engine-emblem-v1.png','client-assets/dk-engine-logo-v1.png','client-assets/launcher-background-v1.png','web/public/logo.png']);
export function payloadFingerprint(root,names=managedRuntimeFiles(root),{sanitizeImages=false,onProgress=()=>{}}={}){const h=createHash('sha256');let done=0;onProgress(done,names.length);for(const name of names){assertUnlinked(path.join(root,name));h.update(name+'\0');const bytes=fs.readFileSync(path.join(root,name));h.update(sanitizeImages&&PACKAGE_PNGS.has(name)?sanitizeReleasePng(bytes):bytes);h.update('\0');onProgress(++done,names.length);}return h.digest('hex');}
// Same ordered digest and link checks as payloadFingerprint, with bounded parallel reads.
// Re-check path identity after every read so a concurrent replacement fails closed.
async function checkedRuntimeStat(target){
 const paths=[];let current=path.resolve(target);for(;;){paths.push(current);const parent=path.dirname(current);if(parent===current)break;current=parent;}
 const stats=await Promise.all(paths.map(async p=>{try{return await fsp.lstat(p);}catch(error){if(error.code==='ENOENT')return null;throw error;}}));
 if(stats.some(st=>st?.isSymbolicLink()))throw Error('Linked installation paths are not supported.');
 if(!stats[0]?.isFile())throw Error('Managed runtime file missing or not a file.');return stats[0];
}
export async function payloadFingerprintAsync(root,names=managedRuntimeFiles(root),{sanitizeImages=false,onProgress=()=>{},lanes=8,maxBatchBytes=32*1024*1024}={}){
 if(!Number.isInteger(lanes)||lanes<1||lanes>16||!Number.isSafeInteger(maxBatchBytes)||maxBatchBytes<1)throw Error('Invalid runtime fingerprint limits.');
 const h=createHash('sha256');let done=0;onProgress(done,names.length);
 while(done<names.length){
  const slice=names.slice(done,done+lanes),stats=await Promise.all(slice.map(n=>checkedRuntimeStat(path.join(root,n))));let count=0,total=0;
  for(const st of stats){if(count&&total+st.size>maxBatchBytes)break;total+=st.size;count++;}
  const checked=await Promise.all(slice.slice(0,count).map(async(name,i)=>{const full=path.join(root,name),before=stats[i],bytes=await fsp.readFile(full),after=await checkedRuntimeStat(full);
   if(bytes.length!==before.size||after.size!==before.size||after.mtimeMs!==before.mtimeMs||after.ctimeMs!==before.ctimeMs||after.ino!==before.ino||after.dev!==before.dev)throw Error('Managed runtime file changed during fingerprint.');
   return sanitizeImages&&PACKAGE_PNGS.has(name)?sanitizeReleasePng(bytes):bytes;}));
  for(let i=0;i<count;i++){h.update(slice[i]+'\0');h.update(checked[i]);h.update('\0');onProgress(++done,names.length);}
 }return h.digest('hex');
}
export async function inspectInstallOwnershipAsync(root,{target=root,onProgress=()=>{}}={}){
 const marker=inspectInstallOwnership(root,{target,verifyPayload:false});
 if(await payloadFingerprintAsync(root,marker.managedFiles,{sanitizeImages:marker.imageSanitization===1,onProgress})!==marker.payloadFingerprint)throw Error('Installed runtime files changed; automatic update refused.');return marker;
}
// A build may regenerate volatile metadata without changing its source fingerprint.
// Bind warm receipts to the completed preparation snapshot, attested by this owned install.
export function assetPreparationIdentity(active){
 const prepared=active?.manifest?.prepared;
 if(!/^[a-f0-9]{64}$/.test(active?.version||'')||typeof prepared!=='string'||!Number.isFinite(Date.parse(prepared)))return null;
 return createHash('sha256').update(JSON.stringify({version:active.version,prepared,sourceFingerprint:active.manifest.sourceFingerprint||null})).digest('hex');
}
export async function writeInstallOwnership(root,target=root,{installationId=randomUUID()}={}){assertUnlinked(root);const managedFiles=managedRuntimeFiles(root);let preparationId=null;try{preparationId=assetPreparationIdentity(clientSource(root));}catch{/* Legacy runtime-only ownership cannot attest an asset preparation. */}const marker={version:1,product:PRODUCT,installationId,target:path.resolve(target),managedFiles,imageSanitization:1,...(preparationId?{assetPreparationId:preparationId}:{}),payloadFingerprint:payloadFingerprint(root,managedFiles,{sanitizeImages:true})};await fsp.writeFile(path.join(root,MARKER),JSON.stringify(marker,null,2)+'\n');return marker;}
export function inspectInstallOwnership(root,{target=root,verifyPayload=true,onProgress=()=>{}}={}){assertUnlinked(root);const marker=JSON.parse(fs.readFileSync(path.join(root,MARKER),'utf8'));if(marker.version!==1||marker.product!==PRODUCT||!/^[-a-f0-9]{36}$/i.test(marker.installationId)||!same(marker.target,target)||!/^[a-f0-9]{64}$/.test(marker.payloadFingerprint))throw Error('This folder is not an owned Dedicated installation.');if(marker.assetPreparationId!==undefined&&!/^[a-f0-9]{64}$/.test(marker.assetPreparationId))throw Error('Invalid owned asset preparation identity.');if(!Array.isArray(marker.managedFiles)||!marker.managedFiles.length||marker.managedFiles.some(n=>typeof n!=='string'||n.includes('\\')||n.split('/').some(p=>!p||p==='.'||p==='..')||path.isAbsolute(n)||n.includes(':')))throw Error('Invalid owned runtime inventory.');if(verifyPayload&&payloadFingerprint(root,marker.managedFiles,{sanitizeImages:marker.imageSanitization===1,onProgress})!==marker.payloadFingerprint)throw Error('Installed runtime files changed; automatic update refused.');return marker;}
// Legacy receipts alone are deliberately insufficient to authorize replacing a folder.
export function canAdoptLegacyInstall(root){
 try {
  assertUnlinked(root);
  const receipt=JSON.parse(fs.readFileSync(path.join(root,'install-sources.json'),'utf8'));
  const source=JSON.parse(fs.readFileSync(path.join(root,'dedicated-source.json'),'utf8'));
  if(receipt.version!==1||receipt.globalMode!=='portable-copy'||receipt.assetSource!=='User-supplied Global game data; original game executables are not redistributed.'||source.version!==1||source.sourceEngine!=='global-prepared/engine')return false;
  const allowed=new Set(['server','src','site','web','vendor','client-assets','tools','node_modules','runtime','docs','global-prepared','.client-cache','run','server.mjs','package.json','package-lock.json','index.html','join.html','launch.html','Dekaron.exe','Client.exe','GameWindow.exe','DekaronDashboard.exe','Setup-Dedicated.cmd','Setup-DK.cmd','START-HERE.txt','dedicated-source.json','install-sources.json','install-receipt.json']);
  if(fs.readdirSync(root).some(n=>!allowed.has(n)))return false;
  for(const required of ['server.mjs','Client.exe','GameWindow.exe','tools/client-ui.ps1','server/sql/dedicated-sql.mjs','global-prepared/engine/.client-cache/current.json'])if(!fs.statSync(path.join(root,required)).isFile())return false;
  const manifest=JSON.parse(fs.readFileSync(path.join(root,'global-prepared/engine/.client-cache/current.json'),'utf8'));
  if(!/^\.client-cache\/generations\/[a-zA-Z0-9_-]+$/.test(manifest.generation))return false;
  for(const part of ['data','gamedata','site-assets']){const target=path.join(root,'global-prepared/engine',manifest.generation,part);assertUnlinked(target);if(!fs.statSync(target).isDirectory())return false;}
  payloadFingerprint(root);return true;
 }catch{return false;}
}
export async function adoptLegacyInstall(root){if(!canAdoptLegacyInstall(root))throw Error('This existing folder is not a verified legacy portable Dedicated install.');return writeInstallOwnership(root);}
export function ownedInstallation(root){try{return inspectInstallOwnership(root);}catch{return null;}}
export async function assertWorldStopped(root){
 assertUnlinked(root);
 for(const rel of files(root,'server').filter(n=>/^server\/launcher-control(?:-\d+)?\.json$/i.test(n))){const row=JSON.parse(fs.readFileSync(path.join(root,rel),'utf8'));if(!Number.isSafeInteger(row.pid)||row.pid<1)throw Error('Unverifiable server control record; update refused.');try{process.kill(row.pid,0);throw Error('Stop the world and close its game/launcher before updating.');}catch(e){if(e.code!=='ESRCH')throw e;}}
 if(process.platform==='win32'){
  const script="$ErrorActionPreference='Stop';$root=$env:DEKARON_UPGRADE_ROOT.TrimEnd('\\')+'\\';@(Get-CimInstance Win32_Process | Where-Object { ($_.ExecutablePath -and $_.ExecutablePath.StartsWith($root,[StringComparison]::OrdinalIgnoreCase)) -or ($_.CommandLine -and $_.CommandLine.IndexOf($root,[StringComparison]::OrdinalIgnoreCase) -ge 0 -and $_.Name -match '^(node|GameWindow|DekaronClient|DekaronDashboard|Client|powershell|pwsh|msedgewebview2)\\.exe$') } | Select-Object ProcessId,Name)|ConvertTo-Json -Compress";
  const found=execFileSync('powershell.exe',['-NoProfile','-NonInteractive','-Command',script],{encoding:'utf8',windowsHide:true,env:{...process.env,DEKARON_UPGRADE_ROOT:root}}).trim();if(found&&found!=='[]')throw Error('Close this installation’s world, game and launcher before updating.');
 }
}
export function assetPreloadReceipts(root){
 const run=path.join(root,'run');assertUnlinked(run);if(!fs.existsSync(run))return [];
 const out=[],hex=/^[a-f0-9]{64}$/;
 for(const name of fs.readdirSync(run)){
  const match=/^asset-preload-([a-f0-9]{64})\.json$/.exec(name);if(!match)continue;
  const full=path.join(run,name);assertUnlinked(full);const st=fs.lstatSync(full);
  const invalid=()=>{throw Error('Asset preload integrity receipt is invalid; update refused without replacing the existing installation.');};
  if(!st.isFile()||st.nlink!==1||st.size>256*1024*1024)invalid();
  let receipt;try{receipt=JSON.parse(fs.readFileSync(full,'utf8'));}catch{invalid();}
  if(!receipt||Array.isArray(receipt)||Object.keys(receipt).some(k=>!['version','generation','sourceVersion','assetPreparationId','files','totalBytes','entries'].includes(k))||receipt.version!==1||(receipt.assetPreparationId!==undefined&&(typeof receipt.assetPreparationId!=='string'||!hex.test(receipt.assetPreparationId)))||receipt.generation!==match[1]||typeof receipt.sourceVersion!=='string'||!hex.test(receipt.sourceVersion)||!Number.isSafeInteger(receipt.files)||receipt.files<1||!Number.isSafeInteger(receipt.totalBytes)||receipt.totalBytes<0||!Array.isArray(receipt.entries)||receipt.entries.length!==receipt.files||receipt.files>1000000)invalid();
  const seen=new Set();let bytes=0;
  for(const e of receipt.entries){
   if(!e||Array.isArray(e)||Object.keys(e).some(k=>!['file','bytes','sha256'].includes(k))||typeof e.file!=='string'||e.file.length>4096||/[\\:\x00-\x1f\x7f]/.test(e.file)||!Number.isSafeInteger(e.bytes)||e.bytes<0||typeof e.sha256!=='string'||!hex.test(e.sha256))invalid();
   const parts=e.file.split('/');if(parts.length<2||!['data','gamedata','site-assets','sound-assets'].includes(parts[0])||parts.some(p=>!p||p==='.'||p==='..'||/[. ]$/.test(p)||/^(?:con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\.|$)/i.test(p))||seen.has(e.file.toLowerCase()))invalid();
   seen.add(e.file.toLowerCase());bytes+=e.bytes;if(!Number.isSafeInteger(bytes))invalid();
  }
  if(bytes!==receipt.totalBytes)invalid();out.push('run/'+name);
 }
 return out;
}
export function dashboardSqlInstanceFiles(root){
 const rel='run/dashboard-sql-instance.txt',full=path.join(root,rel);if(!fs.existsSync(full))return [];
 assertUnlinked(full);const st=fs.statSync(full),value=fs.readFileSync(full,'utf8').trim();
 if(!st.isFile()||st.nlink!==1||st.size>1024||value.length>200||!/^(?:\.|\(local\)|localhost|[A-Za-z0-9][A-Za-z0-9.-]*)(?:\\[A-Za-z0-9_][A-Za-z0-9_-]{0,63}|,[1-9][0-9]{0,4})?$/.test(value)||(/,/.test(value)&&Number(value.split(',')[1])>65535))throw Error('Saved SQL instance is invalid; update refused without replacing settings.');
 return [rel];
}
// MIGRATION-4.1.x: run/ also holds user data the command center writes: account backups taken before SQL setup
// (run/sql-setup-account-backup-*.json[.journal]) and the classic-launcher choice. hosting-setup/ holds the user's generated kits.
const RUN_USER_STATE=/^(?:sql-setup-account-backup-[0-9A-Za-z-]{1,64}\.json(?:\.journal)?|classic-launcher\.flag)$/;
export function runUserStateFiles(root){const run=path.join(root,'run');assertUnlinked(run);if(!fs.existsSync(run))return [];const out=[];for(const name of fs.readdirSync(run)){if(!RUN_USER_STATE.test(name))continue;const full=path.join(run,name);assertUnlinked(full);if(fs.lstatSync(full).isFile())out.push('run/'+name);}return out;}
// NO_DELETE_USER_FILES 2026-10-30: anything in the install root that the engine does not own (game files or folders
// the player added) is carried into every update, and recovered add-only from an older .rollback, before that
// rollback is retired. Updates only add or replace engine-owned files.
const ENGINE_TOP=new Set(['server','src','site','web','vendor','client-assets','tools','node_modules','runtime','docs','deploy','sql','hosting-setup','gamedata-overrides','global-prepared','.client-cache','run','gamedata','GameGuard','GameGuard.des','protect.msg','global-client.json',MARKER,'server.mjs','package.json','package-lock.json','index.html','join.html','launch.html','Dekaron.exe','Client.exe','GameWindow.exe','DekaronDashboard.exe','Setup-Dedicated.cmd','Setup-DK.cmd','START-HERE.txt','dedicated-source.json','install-sources.json','install-receipt.json',...ROOT_CODE].map(n=>n.toLowerCase()));
export function userExtraFiles(root){assertUnlinked(root);if(!fs.existsSync(root))return [];return fs.readdirSync(root).filter(n=>!ENGINE_TOP.has(n.toLowerCase())).sort().flatMap(n=>files(root,n));}
// Backups an older updater left only in <install>.rollback (it did not carry run/ backups) are copied back into the live install
// (add-only, never overwrite) before preserveState, so they survive even if this update fails after the rollback is retired.
async function recoverRollbackBackups(rollback,to){if(!fs.existsSync(rollback))return [];const got=[];for(const rel of [...runUserStateFiles(rollback).filter(r=>/^run\/sql-setup-account-backup-/.test(r)),...userExtraFiles(rollback)]){const dest=path.join(to,rel);assertUnlinked(dest);if(fs.existsSync(dest))continue;await fsp.mkdir(path.dirname(dest),{recursive:true});await fsp.copyFile(path.join(rollback,rel),dest);got.push(rel);}return got;}
function stateFiles(root){return files(root,'server').filter(serverState).concat(files(root,'hosting-setup'),runUserStateFiles(root),files(root,'runtime/native-profiles'),files(root,'GameGuard'),['GameGuard.des','protect.msg','runtime/gameguard.enabled','runtime/server-gameguard.enabled','run/dashboard-storage.txt'].filter(n=>fs.existsSync(path.join(root,n))),assetPreloadReceipts(root),dashboardSqlInstanceFiles(root),['global-client.json'].filter(n=>fs.existsSync(path.join(root,n))),userExtraFiles(root));}
async function preserveState(from,to){const addOnly=new Set(['global-client.json',...userExtraFiles(from)]);for(const rel of stateFiles(from)){if(addOnly.has(rel)&&fs.existsSync(path.join(to,rel)))continue;assertUnlinked(path.join(from,rel));assertUnlinked(path.join(to,rel));await fsp.mkdir(path.dirname(path.join(to,rel)),{recursive:true});await fsp.copyFile(path.join(from,rel),path.join(to,rel));}}
export async function recoverInterruptedUpgrade(destination){
 destination=path.resolve(destination);assertUnlinked(destination);const rollback=destination+'.rollback',lock=destination+'.update-lock';
 if(fs.existsSync(lock)){
  assertUnlinked(lock);const record=JSON.parse(fs.readFileSync(lock,'utf8'));
  const root=fs.existsSync(destination)?destination:rollback,owner=inspectInstallOwnership(root,{target:destination});
  if(record.version!==1||record.installationId!==owner.installationId||!same(record.target,destination)||!Number.isSafeInteger(record.pid)||record.pid<1)throw Error('Unverifiable update lock; no files were changed.');
  try{process.kill(record.pid,0);throw Error('Another update is running.');}catch(e){if(e.code!=='ESRCH')throw e;}
  await fsp.unlink(lock);
 }
 if(fs.existsSync(destination)||!fs.existsSync(rollback))return false;inspectInstallOwnership(rollback,{target:destination});await fsp.rename(rollback,destination);return true;
}
export async function upgradeDedicatedInstall({destination,buildCandidate,validateCandidate,activeGuard=assertWorldStopped,fault=()=>{}}){
 destination=path.resolve(destination);assertUnlinked(destination);const owner=inspectInstallOwnership(destination);await activeGuard(destination);
 if(typeof buildCandidate!=='function'||typeof validateCandidate!=='function')throw Error('A validated update builder is required.');
 const candidate=destination+'.update-'+randomUUID(),rollback=destination+'.rollback',lock=destination+'.update-lock';assertUnlinked(lock);const handle=await fsp.open(lock,'wx');await handle.writeFile(JSON.stringify({version:1,pid:process.pid,installationId:owner.installationId,target:destination}));let moved=false,installed=false;
 try{
  if(fs.existsSync(rollback))inspectInstallOwnership(rollback,{target:destination});
  await buildCandidate(candidate);await validateCandidate(candidate);await writeInstallOwnership(candidate,destination,{installationId:owner.installationId});
  await activeGuard(destination);inspectInstallOwnership(destination);if(fs.existsSync(rollback)){inspectInstallOwnership(rollback,{target:destination});await recoverRollbackBackups(rollback,destination);}await preserveState(destination,candidate);inspectInstallOwnership(candidate,{target:destination});await fault('prepared');
  // Only a verified previous rollback belonging to this exact install can be retired.
  if(fs.existsSync(rollback)){inspectInstallOwnership(rollback,{target:destination});await fsp.rm(rollback,{recursive:true});}
  await fsp.rename(destination,rollback);moved=true;await fault('old-renamed');await fsp.rename(candidate,destination);installed=true;await fault('new-renamed');
  return {installed:destination,rollback,updated:true};
 }catch(error){
  if(moved){if(installed){await fsp.rename(destination,candidate);installed=false;}await fsp.rename(rollback,destination);moved=false;}
  throw error;
 }finally{
  await handle.close();await fsp.unlink(lock);
  if(fs.existsSync(candidate)){try{try{inspectInstallOwnership(candidate,{target:destination});}catch{inspectInstallOwnership(candidate,{target:candidate});}await fsp.rm(candidate,{recursive:true});}catch{/* Unverified candidate is retained for review, never deleted. */}}
 }
}
