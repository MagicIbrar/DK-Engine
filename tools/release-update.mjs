// Candidate 3.3.5 updater. No user installation is changed by check/cache.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import os from 'node:os';
import https from 'node:https';
import {createHash,randomUUID} from 'node:crypto';
import {spawn} from 'node:child_process';
import {fileURLToPath} from 'node:url';

export const REPO='waveforgemp3app-cmyk/Tool';
export const RELEASE_API=`https://api.github.com/repos/${REPO}/releases/latest`;
const MAX_JSON=1_048_576,MAX_ZIP=1_073_741_824,MAX_REDIRECTS=5;
const HOSTS=new Set(['api.github.com','github.com','release-assets.githubusercontent.com','objects.githubusercontent.com']);
const VERSION=/^(?:v)?(\d{1,5})\.(\d{1,5})\.(\d{1,5})$/;
const PLAIN_VERSION=/^\d{1,5}\.\d{1,5}\.\d{1,5}$/;
const SAME=(a,b)=>path.resolve(a).toLowerCase()===path.resolve(b).toLowerCase();
const inside=(p,r)=>{const rel=path.relative(path.resolve(r),path.resolve(p));return !rel||(!rel.startsWith('..'+path.sep)&&rel!=='..'&&!path.isAbsolute(rel));};
function assertNoLinks(location){let current=path.resolve(location);for(;;){if(fs.existsSync(current)&&fs.lstatSync(current).isSymbolicLink())throw Error('Linked updater paths are refused.');const parent=path.dirname(current);if(parent===current)break;current=parent;}}
function validCandidate(row){
 if(!row||!PLAIN_VERSION.test(row.version||'')||![row.version,'v'+row.version].includes(row.tag)||row.name!==`DK-${row.version}.zip`||path.basename(row.name)!==row.name||!/^[a-f0-9]{64}$/.test(row.sha256||'')||!Number.isSafeInteger(row.bytes)||row.bytes<1024||row.bytes>MAX_ZIP)return false;
 return row.url===`https://github.com/${REPO}/releases/download/${encodeURIComponent(row.tag)}/${row.name}`;
}
async function cleanOwnedWorkers(installId){
 const base=path.join(cacheBase(),'workers');assertNoLinks(base);
 let rows;try{rows=await fsp.readdir(base,{withFileTypes:true});}catch(error){if(error.code==='ENOENT')return;throw error;}
 for(const row of rows){
  if(!row.isDirectory()||!/^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$/.test(row.name))continue;
  const folder=path.join(base,row.name),marker=path.join(folder,'.owned.json');
  try{assertNoLinks(marker);const owner=JSON.parse(await fsp.readFile(marker,'utf8'));
   if(owner.token!==row.name||owner.installId!==installId||path.resolve(owner.workerScript)!==path.join(folder,'release-update-worker.mjs'))continue;
   if(Number.isSafeInteger(owner.pid)&&owner.pid>0){try{process.kill(owner.pid,0);continue;}catch(error){if(error.code!=='ESRCH')continue;}}
   if(owner.pid===0&&Number.isSafeInteger(owner.ownerPid)){try{process.kill(owner.ownerPid,0);continue;}catch(error){if(error.code!=='ESRCH')continue;}}
   await fsp.rm(folder,{recursive:true,force:true});
  }catch{/* Unknown or active folders remain untouched. */}
 }
}
const cacheBase=()=>path.join(process.env.LOCALAPPDATA||os.tmpdir(),'DK Engine Updates');
const defaultCache=()=>path.join(cacheBase(),'cache');
export const cacheForInstall=installRoot=>path.join(cacheBase(),'installs',createHash('sha256').update(path.resolve(installRoot).toLowerCase()).digest('hex').slice(0,24));
const prefsFile=()=>path.join(cacheBase(),'preferences.json');

export function compareVersions(a,b){
 const x=VERSION.exec(a),y=VERSION.exec(b);if(!x||!y)throw Error('Only stable numeric release versions are supported.');
 for(let i=1;i<=3;i++){const n=Number(x[i])-Number(y[i]);if(n)return Math.sign(n);}return 0;
}
export function releaseCandidate(release,currentVersion){
 if(!release||release.draft!==false||release.prerelease!==false||typeof release.tag_name!=='string'||!VERSION.test(release.tag_name))return null;
 const version=release.tag_name.replace(/^v/,'');if(compareVersions(version,currentVersion)<=0)return null;
 const name=`DK-${version}.zip`,assets=Array.isArray(release.assets)?release.assets:[];
 const matches=assets.filter(a=>a?.name===name&&a.state==='uploaded');
 if(matches.length!==1)throw Error(`Published release ${release.tag_name} must contain exactly one ${name} asset.`);
 const asset=matches[0],digest=/^sha256:([a-f0-9]{64})$/i.exec(asset.digest||'');
 if(!digest||!Number.isSafeInteger(asset.size)||asset.size<1024||asset.size>MAX_ZIP)throw Error('Release asset is missing a valid GitHub SHA-256 digest or size.');
 const expected=`https://github.com/${REPO}/releases/download/${encodeURIComponent(release.tag_name)}/${name}`;
 if(asset.browser_download_url!==expected)throw Error('Release asset URL does not match the expected repository and tag.');
 return {version,tag:release.tag_name,name,bytes:asset.size,sha256:digest[1].toLowerCase(),url:expected};
}
function permittedUrl(value){
 const url=new URL(value);if(url.protocol!=='https:'||!HOSTS.has(url.hostname)||url.username||url.password||url.port)throw Error('Release download redirected to an unexpected host.');
 return url;
}
async function requestStream(url,{remaining=MAX_REDIRECTS}={}){
 url=permittedUrl(url);
 return new Promise((resolve,reject)=>{
  const req=https.get(url,{headers:{'User-Agent':'DK-Engine-Updater/3.3.5','Accept':'application/vnd.github+json','X-GitHub-Api-Version':'2022-11-28'},timeout:15_000},res=>{
   if([301,302,303,307,308].includes(res.statusCode)){
    const next=res.headers.location;res.resume();if(!next||remaining<=0)return reject(Error('Too many release redirects.'));
    try{resolve(requestStream(new URL(next,url).href,{remaining:remaining-1}));}catch(error){reject(error);}return;
   }
   if(res.statusCode!==200){res.resume();return reject(Error(`GitHub returned HTTP ${res.statusCode}.`));}
   resolve(res);
  });req.on('timeout',()=>req.destroy(Error('Release request timed out.')));req.on('error',reject);
 });
}
async function readJson(url){
 const stream=await requestStream(url);let bytes=0,chunks=[];
 for await(const chunk of stream){bytes+=chunk.length;if(bytes>MAX_JSON){stream.destroy();throw Error('Release metadata is too large.');}chunks.push(chunk);}
 return JSON.parse(Buffer.concat(chunks).toString('utf8'));
}
export async function preferences(){try{assertNoLinks(prefsFile());const p=JSON.parse(await fsp.readFile(prefsFile(),'utf8'));return {checkOnLaunch:p.checkOnLaunch!==false};}catch{return {checkOnLaunch:true};}}
export async function setPreferences(patch){
 const current=await preferences();if('checkOnLaunch' in patch){if(typeof patch.checkOnLaunch!=='boolean')throw Error('Invalid checkOnLaunch preference.');current.checkOnLaunch=patch.checkOnLaunch;}
 assertNoLinks(prefsFile());
 await fsp.mkdir(cacheBase(),{recursive:true});const temp=prefsFile()+'.'+randomUUID();await fsp.writeFile(temp,JSON.stringify(current)+'\n',{flag:'wx'});await fsp.rename(temp,prefsFile());return current;
}
export async function checkRelease({currentVersion,fetchMetadata=readJson,force=false}={}){
 if(!VERSION.test(currentVersion||''))throw Error('Installed version must be a stable numeric version.');
 const prefs=await preferences();if(!prefs.checkOnLaunch&&!force)return {status:'disabled',preferences:prefs};
 try{const release=await fetchMetadata(RELEASE_API),candidate=releaseCandidate(release,currentVersion);return candidate?{status:'available',candidate,preferences:prefs}:{status:'current',preferences:prefs};}
 catch(error){return {status:'offline',message:String(error.message||error),preferences:prefs};}
}
export async function verifyCached(candidate,{cache=defaultCache()}={}){
 if(!validCandidate(candidate))return false;assertNoLinks(cache);assertNoLinks(path.join(cache,'release.json'));assertNoLinks(path.join(cache,candidate.name));
 const metaPath=path.join(cache,'release.json'),zipPath=path.join(cache,candidate.name);
 try{
  const meta=JSON.parse(await fsp.readFile(metaPath,'utf8'));
  if(JSON.stringify(meta)!==JSON.stringify(candidate))return false;
  const st=await fsp.lstat(zipPath);if(!st.isFile()||st.isSymbolicLink()||st.size!==candidate.bytes)return false;
  const hash=createHash('sha256');for await(const chunk of fs.createReadStream(zipPath))hash.update(chunk);
  return hash.digest('hex')===candidate.sha256;
 }catch{return false;}
}
export async function cacheRelease(candidate,{cache=defaultCache(),openStream=requestStream}={}){
 // Candidate must have been produced by releaseCandidate, including its exact repo URL.
 if(!validCandidate(candidate))throw Error('Invalid release candidate.');assertNoLinks(cache);assertNoLinks(path.join(cache,'release.json'));assertNoLinks(path.join(cache,candidate.name));
 if(await verifyCached(candidate,{cache}))return {status:'cached',version:candidate.version,cache,zip:path.join(cache,candidate.name)};
 await fsp.mkdir(cache,{recursive:true});const pending=path.join(cache,`.download-${randomUUID()}`);let bytes=0;
 try{
  const stream=await openStream(candidate.url),hash=createHash('sha256');
  const out=await fsp.open(pending,'wx');
  try{for await(const chunk of stream){bytes+=chunk.length;if(bytes>candidate.bytes||bytes>MAX_ZIP){stream.destroy();throw Error('Release asset exceeds declared size.');}hash.update(chunk);let offset=0;while(offset<chunk.length){const written=await out.write(chunk,offset,chunk.length-offset);offset+=written.bytesWritten;}}await out.sync();}finally{await out.close();}
  if(bytes!==candidate.bytes||hash.digest('hex')!==candidate.sha256)throw Error('Release asset failed size or SHA-256 verification.');
  const zip=path.join(cache,candidate.name);await fsp.rename(pending,zip);
  await fsp.writeFile(path.join(cache,'release.json'),JSON.stringify(candidate)+'\n');
  // Keep a single verified release in our cache. Never inspect or remove files outside it.
  for(const name of await fsp.readdir(cache))if(/^DK-\d+\.\d+\.\d+\.zip$/.test(name)&&name!==candidate.name)await fsp.unlink(path.join(cache,name));
  return {status:'cached',version:candidate.version,cache,zip};
 }catch(error){await fsp.rm(pending,{force:true});throw error;}
}
export async function scheduleApply({installRoot,candidate=null,currentVersion=null,cache=null,nodeExecutable=process.execPath}={}){
 if(!candidate&&!VERSION.test(currentVersion||''))throw Error('Installed version is required to queue the update.');
 installRoot=path.resolve(installRoot);cache=path.resolve(cache||cacheForInstall(installRoot));nodeExecutable=path.resolve(nodeExecutable);
 if(candidate&&!await verifyCached(candidate,{cache}))throw Error('Verified cached release is required.');
 assertNoLinks(installRoot);assertNoLinks(cache);assertNoLinks(nodeExecutable);
 if(inside(cache,installRoot)||!fs.existsSync(nodeExecutable))throw Error('Updater cache or Node runtime is unavailable outside the installed game.');
 await fsp.mkdir(cache,{recursive:true});
 const pendingFile=path.join(cache,'worker.json');
 assertNoLinks(pendingFile);
 let old=null;try{old=JSON.parse(await fsp.readFile(pendingFile,'utf8'));}catch(error){if(error.code!=='ENOENT')throw Error('Updater reservation is invalid. No installation was changed.');}
 const installId=createHash('sha256').update(installRoot.toLowerCase()).digest('hex').slice(0,24);
 if(old&&(!/^[a-f0-9-]{36}$/.test(old.token||'')||old.installId!==installId||!Number.isSafeInteger(old.createdAt)||typeof old.workerScript!=='string'))throw Error('Updater reservation belongs to another or invalid installation.');
 if(old&&old.token&&Date.now()-old.createdAt<13*60*60*1000){
  if(old.pid===0&&Number.isSafeInteger(old.ownerPid))try{process.kill(old.ownerPid,0);return {status:'pending',version:old.version||null};}catch(error){if(error.code!=='ESRCH')throw Error('Cannot verify the previous updater scheduler; update deferred.');}
  if(Number.isSafeInteger(old.pid)&&old.pid>0){
   let live=false;try{process.kill(old.pid,0);live=true;}catch(error){if(error.code!=='ESRCH')throw Error('Cannot verify the previous updater process; update deferred.');}
   if(live&&process.platform!=='win32')return {status:'pending',version:old.version||null};
   if(live){
    const query="$ErrorActionPreference='Stop';$p=Get-CimInstance Win32_Process -Filter 'ProcessId="+old.pid+"';if(-not $p){throw 'Process identity unavailable'};$p.CommandLine";
    let cmd;try{cmd=String((await import('node:child_process')).execFileSync('powershell.exe',['-NoProfile','-NonInteractive','-Command',query],{encoding:'utf8',windowsHide:true}));}catch{throw Error('Cannot verify the previous updater process; update deferred.');}
    if(!cmd.trim())throw Error('Cannot verify the previous updater process; update deferred.');
    if(cmd.includes(old.workerScript))return {status:'pending',version:old.version||null};
   }
  }
 }
 if(old){const stat=await fsp.lstat(pendingFile);if(!stat.isFile()||stat.isSymbolicLink())throw Error('Unverifiable updater record.');await fsp.unlink(pendingFile);}
 await cleanOwnedWorkers(installId);
 const token=randomUUID(),workerRoot=path.join(cacheBase(),'workers',token),workerScript=path.join(workerRoot,'release-update-worker.mjs');
 assertNoLinks(workerRoot);if(inside(workerRoot,installRoot))throw Error('Updater worker must be outside the installed game.');
 const createdAt=Date.now(),record={token,pid:0,ownerPid:process.pid,installId,version:candidate?.version||null,createdAt,workerScript};
 let handle;try{handle=await fsp.open(pendingFile,'wx');await handle.writeFile(JSON.stringify(record)+'\n');}catch(error){if(error.code==='EEXIST')return {status:'pending',version:null};throw error;}finally{await handle?.close();}
 try{
  assertNoLinks(path.join(cache,'update-status.log'));await fsp.appendFile(path.join(cache,'update-status.log'),JSON.stringify({at:new Date().toISOString(),type:'queued',version:record.version,message:'Update requested.'})+'\n');
  await fsp.mkdir(workerRoot,{recursive:true});await fsp.writeFile(path.join(workerRoot,'.owned.json'),JSON.stringify(record)+'\n',{flag:'wx'});const sourceDir=path.dirname(fileURLToPath(import.meta.url));
  for(const name of ['release-update.mjs','release-update-worker.mjs','safe-release-extract.ps1'])await fsp.copyFile(path.join(sourceDir,name),path.join(workerRoot,name));
  let workerNode=nodeExecutable;
  if(inside(workerNode,installRoot)){workerNode=path.join(workerRoot,'node.exe');await fsp.copyFile(nodeExecutable,workerNode);const license=path.join(path.dirname(nodeExecutable),'LICENSE');if(fs.existsSync(license))await fsp.copyFile(license,path.join(workerRoot,'LICENSE'));}
  const child=spawn(workerNode,[workerScript],{detached:true,stdio:'ignore',windowsHide:true,env:{...process.env,DEKARON_UPDATE_INSTALL_ROOT:installRoot,DEKARON_UPDATE_CACHE:cache,DEKARON_UPDATE_NODE:workerNode,DEKARON_UPDATE_CURRENT:currentVersion||'',DEKARON_UPDATE_TOKEN:token}});
  await new Promise((resolve,reject)=>{child.once('spawn',resolve);child.once('error',reject);});
  if(!Number.isSafeInteger(child.pid)||child.pid<1)throw Error('Could not start the external updater worker.');
  record.pid=child.pid;await fsp.writeFile(path.join(workerRoot,'.owned.json'),JSON.stringify(record)+'\n');await fsp.writeFile(pendingFile,JSON.stringify(record)+'\n');child.unref();return {status:'scheduled',version:record.version};
 }catch(error){try{const current=JSON.parse(await fsp.readFile(pendingFile,'utf8'));if(current.token===token)await fsp.unlink(pendingFile);}catch{}throw error;}
}
export async function cachedCandidate({cache=defaultCache()}={}){
 try{assertNoLinks(path.join(cache,'release.json'));const row=JSON.parse(await fsp.readFile(path.join(cache,'release.json'),'utf8'));return await verifyCached(row,{cache})?row:null;}catch{return null;}
}
export async function updateStatus({installRoot}={}){
 if(!installRoot)throw Error('Installed game folder is required for update status.');
 const cache=cacheForInstall(installRoot),logFile=path.join(cache,'update-status.log'),pendingFile=path.join(cache,'worker.json');
 assertNoLinks(logFile);assertNoLinks(pendingFile);
 let latest=null;
 try{const size=(await fsp.stat(logFile)).size;if(size>256*1024)throw Error('Updater status log is too large.');const rows=(await fsp.readFile(logFile,'utf8')).trim().split(/\r?\n/);latest=JSON.parse(rows.at(-1));}catch(error){if(error.message==='Updater status log is too large.')throw error;}
 let pending=null;try{pending=JSON.parse(await fsp.readFile(pendingFile,'utf8'));}catch{}
 const known=new Set(['queued','downloading','waiting','applying','complete','failed','current']);
 const phase=known.has(latest?.type)?latest.type:pending?'queued':'idle';
 const version=/^\d{1,5}\.\d{1,5}\.\d{1,5}$/.test(latest?.version||'')?latest.version:/^\d{1,5}\.\d{1,5}\.\d{1,5}$/.test(pending?.version||'')?pending.version:null;
 const messages={queued:'Update requested. Preparing the download.',downloading:'Downloading and verifying the update.',waiting:'Update ready. Close the game, world and launcher to install it.',applying:'Installing the verified update.',complete:'Update installed. Reopen DK Client.',failed:'Update could not finish. Click Retry. If it fails again, report code UPDATE-UNKNOWN.',current:'Your game is current.',idle:'No update is pending.'};
 const failures={
  check:'Update check could not finish. Check your connection and retry. If it persists, report code UPDATE-CHECK.',
  download:'Update download could not finish. Check your connection and retry. If it persists, report code UPDATE-DOWNLOAD.',
  verify:'The update package could not be verified. Retry the update. If it persists, report code UPDATE-VERIFY.',
  prepare:'The update could not be prepared. Retry the update. If it persists, report code UPDATE-PREPARE.',
  wait:'The update could not continue while waiting for the game to close. Close the game, world and launcher, then retry. Report code UPDATE-WAIT if it persists.',
  install:'The update could not be installed. Retry the update. If it persists, report code UPDATE-INSTALL.',
  space:'There is not enough free space to update. Free some disk space and retry. Report code UPDATE-SPACE if it persists.',
  permission:'The updater could not access a required file or folder. Check file permissions and retry. Report code UPDATE-PERMISSION if it persists.',
  busy:'A required file is in use. Close the game, world and launcher, then retry. Report code UPDATE-BUSY if it persists.',
  manual:'This installation cannot be updated automatically. Request help with manual migration and report code UPDATE-MANUAL.'
 };
 const reason=phase==='failed'&&typeof latest?.reason==='string'&&Object.hasOwn(failures,latest.reason)?latest.reason:null;
 return {status:phase,version,updatedAt:typeof latest?.at==='string'?latest.at:null,message:reason?failures[reason]:messages[phase]};
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
 const args=process.argv.slice(2),arg=n=>{const i=args.indexOf(n);return i>=0?args[i+1]:undefined;};
 try{
  const mode=args[0];let result;
  if(mode==='--preferences')result=await preferences();
  else if(mode==='--disable-auto')result=await setPreferences({checkOnLaunch:false});
  else if(mode==='--enable-auto')result=await setPreferences({checkOnLaunch:true});
  else if(mode==='--disable-check')result=await setPreferences({checkOnLaunch:false});
  else if(mode==='--enable-check')result=await setPreferences({checkOnLaunch:true});
  else if(mode==='--check'||mode==='--retry')result=await checkRelease({currentVersion:arg('--current'),force:mode==='--retry'});
  else if(mode==='--cache'){const checked=await checkRelease({currentVersion:arg('--current'),force:true});result=checked.status==='available'?await cacheRelease(checked.candidate,{cache:arg('--install')?cacheForInstall(arg('--install')):defaultCache()}):checked;}
  else if(mode==='--apply'){const installRoot=arg('--install'),cache=cacheForInstall(installRoot),candidate=await cachedCandidate({cache});if(!candidate)throw Error('No verified cached release.');result=await scheduleApply({installRoot,candidate,cache});}
  else if(mode==='--queue')result=await scheduleApply({installRoot:arg('--install'),currentVersion:arg('--current')});
  else if(mode==='--status')result=await updateStatus({installRoot:arg('--install')});
  else throw Error('Use --check, --cache, --apply, --retry, --preferences, --disable-auto, or --enable-auto.');
  console.log(JSON.stringify(result));
 }catch(error){console.error(error.message);process.exitCode=1;}
}
