// Detached worker: both this script and node.exe must be outside the installed game.
// The install root travels in the environment, not this process's command line, so
// the existing stopped-process guard cannot mistake the updater for the game.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import {createHash,randomUUID} from 'node:crypto';
import {execFileSync} from 'node:child_process';
import {pathToFileURL,fileURLToPath} from 'node:url';

const root=process.env.DEKARON_UPDATE_INSTALL_ROOT;
const cache=process.env.DEKARON_UPDATE_CACHE;
const node=process.env.DEKARON_UPDATE_NODE;
const currentVersion=process.env.DEKARON_UPDATE_CURRENT;
const token=process.env.DEKARON_UPDATE_TOKEN;
let activeVersion=null;
const wait=ms=>new Promise(resolve=>setTimeout(resolve,ms));
const inside=(p,r)=>{const rel=path.relative(path.resolve(r),path.resolve(p));return !rel||(!rel.startsWith('..'+path.sep)&&rel!=='..'&&!path.isAbsolute(rel));};
function assertNoLinks(location){let current=path.resolve(location);for(;;){if(fs.existsSync(current)&&fs.lstatSync(current).isSymbolicLink())throw Error('Linked updater paths are refused.');const parent=path.dirname(current);if(parent===current)break;current=parent;}}
const log=async(type,message)=>{if(cache)try{assertNoLinks(path.join(cache,'update-status.log'));await fsp.appendFile(path.join(cache,'update-status.log'),JSON.stringify({at:new Date().toISOString(),type,version:activeVersion,message})+'\n');}catch{}};
const sourceDir=path.dirname(fileURLToPath(import.meta.url));
async function assertOwnedWorker(){
 const marker=path.join(cache,'worker.json');assertNoLinks(marker);
 for(let attempt=0;attempt<25;attempt++){
  let record;try{record=JSON.parse(await fsp.readFile(marker,'utf8'));}catch{await wait(200);continue;}
  const expected=createHash('sha256').update(path.resolve(root).toLowerCase()).digest('hex').slice(0,24);
  if(record.token!==token||record.installId!==expected||path.resolve(record.workerScript)!==path.resolve(fileURLToPath(import.meta.url)))throw Error('Updater worker ownership does not match this installation.');
  if(record.pid===process.pid)return;
  if(record.pid!==0)throw Error('Updater worker PID is not the owned worker.');
  await wait(200);
 }
 throw Error('Updater worker reservation did not complete.');
}

async function main(){
 if(!root||!cache||!node||inside(cache,root)||inside(node,root)||inside(sourceDir,root))throw Error('Updater is not isolated from the installed game.');
 for(const location of [root,cache,node,sourceDir])assertNoLinks(location);
 await assertOwnedWorker();
 const updater=await import(pathToFileURL(path.join(sourceDir,'release-update.mjs')).href);
 let candidate;
 if(currentVersion){
  const checked=await updater.checkRelease({currentVersion,force:true});
  if(checked.status==='current'){await log('current','The installed game is already current.');return;}
  if(checked.status!=='available')throw Error(checked.message||`Update check returned ${checked.status}.`);
  await log('downloading',`Downloading and verifying ${checked.candidate.version}.`);
  await updater.cacheRelease(checked.candidate,{cache});candidate=checked.candidate;
 }else candidate=JSON.parse(await fsp.readFile(path.join(cache,'release.json'),'utf8'));
 activeVersion=candidate.version;
 if(!await updater.verifyCached(candidate,{cache}))throw Error('Cached release identity or hash is invalid.');
 if(!/^\d+\.\d+\.\d+$/.test(candidate.version)||candidate.name!==`DK-${candidate.version}.zip`||!/^[a-f0-9]{64}$/.test(candidate.sha256)||!Number.isSafeInteger(candidate.bytes)||candidate.bytes<1024||candidate.bytes>1_073_741_824)throw Error('Cached release metadata is invalid.');
 const archive=path.join(cache,candidate.name),stat=await fsp.lstat(archive);if(!stat.isFile()||stat.isSymbolicLink()||stat.size!==candidate.bytes)throw Error('Cached archive is missing or changed.');
 const hash=createHash('sha256');for await(const chunk of fs.createReadStream(archive))hash.update(chunk);if(hash.digest('hex')!==candidate.sha256)throw Error('Cached archive hash changed.');
 const extraction=path.join(cache,`extract-${randomUUID()}`);await fsp.mkdir(extraction,{recursive:false});
 try{
  execFileSync('powershell.exe',['-NoProfile','-NonInteractive','-ExecutionPolicy','Bypass','-File',path.join(sourceDir,'safe-release-extract.ps1'),'-Archive',archive,'-Destination',extraction,'-Version',candidate.version],{encoding:'utf8',timeout:180_000,windowsHide:true,maxBuffer:1024*1024});
  const engine=path.join(extraction,'Engine');
  const module=await import(pathToFileURL(path.join(engine,'tools','dedicated-client-entry.mjs')).href);
  const upgrade=await import(pathToFileURL(path.join(engine,'tools','upgrade-dedicated-install.mjs')).href);
  if(!upgrade.ownedInstallation(root))throw Error('Existing folder is not an owned DK Engine installation. Manual migration is required.');
  const installed=JSON.parse(await fsp.readFile(path.join(root,'package.json'),'utf8')).version;
  const semver=s=>s.split('.').map(Number),x=semver(candidate.version),y=semver(installed);
  if(x.length!==3||y.length!==3||x.some(n=>!Number.isSafeInteger(n))||y.some(n=>!Number.isSafeInteger(n))||x.every((n,i)=>n===y[i])||x.find((n,i)=>n!==y[i])<y.find((n,i)=>n!==y[i]))throw Error('Cached release is not newer than the installation.');
  await log('waiting','Update verified; waiting for this world, game and launcher to close.');
  const deadline=Date.now()+12*60*60*1000;
  while(true){
   try{await upgrade.assertWorldStopped(root);break;}
   catch(error){const text=String(error.message||error);if(!/Stop the world|Close this installation/i.test(text))throw error;if(Date.now()>deadline)throw Error('Timed out waiting for game/server closure. Retry from the launcher.');await wait(30_000);}
  }
  const plan=module.clientEntryPlan({engine,destination:root});if(plan.route!=='update'||path.resolve(plan.destination).toLowerCase()!==path.resolve(root).toLowerCase())throw Error('Release does not produce a safe owned update plan.');
  await assertOwnedWorker();
  await log('applying',`Installing ${candidate.version}.`);
  await module.installClientEntry(plan,{nodeExecutable:node,shortcut:false});
  await log('complete',`Installed ${candidate.version}; saves and settings retained.`);
 }finally{
  // Only this worker-created extraction is removed; cache, rollback, saves are retained.
  if(path.dirname(extraction)===path.resolve(cache)&&path.basename(extraction).startsWith('extract-'))await fsp.rm(extraction,{recursive:true,force:true});
 }
}
try{await main();}catch(error){await log('failed','The update could not finish. The installed game remains available; retry from DK Client.');process.exitCode=1;}finally{
 if(cache)try{assertNoLinks(path.join(cache,'worker.json'));const pending=JSON.parse(await fsp.readFile(path.join(cache,'worker.json'),'utf8'));if(pending.pid===process.pid&&pending.token===token)await fsp.unlink(path.join(cache,'worker.json'));}catch{}
}
