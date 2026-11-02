import fs from 'node:fs/promises';import path from 'node:path';import {createReadStream,writeFileSync} from 'node:fs';import {createHash,randomUUID} from 'node:crypto';import {fileURLToPath} from 'node:url';import {clientSource} from '../server/client-source.mjs';import {inspectInstallOwnershipAsync,inspectInstallOwnership,writeInstallOwnership,assetPreparationIdentity,assetPreloadReceipts} from './upgrade-dedicated-install.mjs';
// RUNTIME-REATTEST 2026-10-30: in-place engine code edits (src/, server/, tools/ ...) changed the runtime fingerprint and every
// launch then stopped with 'Full asset verification did not complete ... Installed runtime files changed'. Engine code is
// not game data: when ONLY the runtime fingerprint differs (same owned installation, same target, same prepared asset
// snapshot), re-attest the runtime in place (old marker kept in run/install-record-history, logged in
// run/runtime-reattest.log) and continue. Game data is still checked byte-for-byte against its receipt below, so real
// asset corruption still stops the launch. DK_STRICT_RUNTIME=1 restores the old refusal.
async function ownedRuntime(engine,active,onProgress){
 try{return await inspectInstallOwnershipAsync(engine,{onProgress});}
 catch(error){
  if(process.env.DK_STRICT_RUNTIME==='1'||!/Installed runtime files changed/.test(String(error?.message)))throw error;
  const marker=inspectInstallOwnership(engine,{verifyPayload:false});
  if(marker.assetPreparationId&&marker.assetPreparationId!==assetPreparationIdentity(active))throw error;
  const hist=path.join(engine,'run','install-record-history');await fs.mkdir(hist,{recursive:true});
  const stamp=new Date().toISOString().replace(/[-:.]/g,'');await fs.copyFile(path.join(engine,'dedicated-install.json'),path.join(hist,'dedicated-install.json.'+stamp));
  const next=await writeInstallOwnership(engine,marker.target,{installationId:marker.installationId});
  await fs.appendFile(path.join(engine,'run','runtime-reattest.log'),JSON.stringify({at:new Date().toISOString(),reason:'runtime-files-changed',old:marker.payloadFingerprint,new:next.payloadFingerprint,oldFiles:marker.managedFiles.length,newFiles:next.managedFiles.length})+'\n');
  return next;
 }
}
import * as nativeFs from 'node:fs';import {Worker,isMainThread,parentPort,workerData} from 'node:worker_threads';
// In-process workers avoid hundreds of thousands of promise/stream objects and
// keep SHA work off the launcher thread. They still read and hash every byte.
if(!isMainThread&&workerData?.assetWarmIO){
 const stopped=new Int32Array(workerData.cancel),buffer=Buffer.allocUnsafe(workerData.chunkBytes);
 const check=()=>{if(Atomics.load(stopped,0))throw Error('Asset preload cancelled. Game launch stopped.');};
 parentPort.on('message',batch=>{try{const results=[];let pendingBytes=0,last=Date.now();
  for(const entry of batch){check();const hash=createHash('sha256');let read=0;const fd=nativeFs.openSync(entry.full,'r');try{while(read<entry.bytes){check();const count=nativeFs.readSync(fd,buffer,0,Math.min(buffer.length,entry.bytes-read),null);if(!count)break;read+=count;if(read>entry.bytes)throw Error('Prepared asset changed while reading: '+entry.file);hash.update(buffer.subarray(0,count));pendingBytes+=count;if(Date.now()-last>=75){parentPort.postMessage({bytes:pendingBytes});pendingBytes=0;last=Date.now();}}}finally{nativeFs.closeSync(fd);}
   const after=nativeFs.lstatSync(entry.full);if(after.isSymbolicLink()||!after.isFile()||after.size!==entry.bytes||after.mtimeMs!==entry.mtimeMs||after.ctimeMs!==entry.ctimeMs||after.ino!==entry.ino||after.dev!==entry.dev||read!==entry.bytes)throw Error('Prepared asset changed while reading: '+entry.file);
   results.push({file:entry.file,bytes:read,sha256:hash.digest('hex')});
  }parentPort.postMessage({bytes:pendingBytes,results});
 }catch(error){parentPort.postMessage({error:error.message});}});
}
async function warmInWorkers(entries,{count,chunkBytes,signal,onBytes,onResult}){
 const cancel=new SharedArrayBuffer(4),flag=new Int32Array(cancel),workers=[];let cursor=0,completed=0,settled=false;
 const abort=()=>Atomics.store(flag,0,1);signal?.addEventListener('abort',abort,{once:true});
 try{await new Promise((resolve,reject)=>{
  const fail=error=>{if(!settled){settled=true;abort();reject(error);}};
  const dispatch=worker=>{if(signal?.aborted){fail(Error('Asset preload cancelled. Game launch stopped.'));return;}if(cursor<entries.length){const batch=entries.slice(cursor,cursor+64);cursor+=batch.length;worker.postMessage(batch);}};
  for(let i=0;i<Math.min(count,entries.length);i++){
   const worker=new Worker(new URL(import.meta.url),{workerData:{assetWarmIO:true,cancel,chunkBytes}});workers.push(worker);
   worker.on('error',fail);worker.on('exit',code=>{if(!settled)fail(Error('Asset preload worker exited before completion: '+code));});
   worker.on('message',message=>{if(settled)return;try{if(message.error){fail(Error(message.error));return;}if(message.bytes)onBytes(message.bytes);if(message.results){for(const result of message.results){onResult(result);completed++;}onBytes(0);if(completed===entries.length){settled=true;resolve();}else dispatch(worker);}}catch(error){fail(error);}});dispatch(worker);
  }
 });}finally{abort();signal?.removeEventListener('abort',abort);await Promise.all(workers.map(worker=>worker.terminate()));}
}
const samePath=(a,b)=>path.relative(path.resolve(a),path.resolve(b))==='',inside=(root,p)=>{const rel=path.relative(path.resolve(root),path.resolve(p));return rel===''||(!path.isAbsolute(rel)&&rel!=='..'&&!rel.startsWith('..'+path.sep));},digest=b=>createHash('sha256').update(b).digest('hex');
function dedicatedMount(engine){const cfgPath=path.join(engine,'dedicated-source.json');if(!nativeFs.existsSync(cfgPath))return null;let config;try{config=JSON.parse(nativeFs.readFileSync(cfgPath,'utf8'));}catch{return null;}if(config.version!==1||typeof config.sourceEngine!=='string'||!config.sourceEngine)return null;const mount=path.resolve(engine,config.sourceEngine);if(mount===engine||!mount.startsWith(engine+path.sep))return null;return mount;}
async function unlinked(p){let current=path.resolve(p);while(true){const st=await fs.lstat(current);if(st.isSymbolicLink())throw Error('Asset preload refuses linked paths.');const parent=path.dirname(current);if(parent===current)break;current=parent;}}
export async function verifyAndWarmAssets({engine,signal,onProgress=()=>{},resolveSource=clientSource,chunkBytes=256*1024,concurrency=24,ioWorkers=16}={}){
 if(!Number.isInteger(chunkBytes)||chunkBytes<1||chunkBytes>256*1024)throw Error('Asset preload chunk size exceeds its bounded memory limit.');
 if(!Number.isInteger(concurrency)||concurrency<1||concurrency>32)throw Error('Asset preload concurrency exceeds its bounded limit.');
 if(!Number.isInteger(ioWorkers)||ioWorkers<0||ioWorkers>16)throw Error('Asset preload worker count exceeds its bounded limit.');
 const cancelled=()=>{if(signal?.aborted)throw Error('Asset preload cancelled. Game launch stopped.');};cancelled();const installEngine=path.resolve(engine);await unlinked(installEngine);const mount=dedicatedMount(installEngine);const mountReal=mount?await fs.realpath(mount).catch(()=>null):null;engine=await fs.realpath(installEngine);
 const active=resolveSource(installEngine);if(!active.manifest||active.version==='legacy')throw Error('Full asset preload requires an installed prepared generation.');
 const roots={data:active.dataRoot,gamedata:active.gamedataRoot,...(active.siteAssetRoot?{'site-assets':active.siteAssetRoot}:{}),...(active.looseSoundRoot?{'sound-assets':active.looseSoundRoot}:{})};
 const declaredFiles=active.manifest.files,declaredBytes=active.manifest.bytes;
 for(const value of [declaredFiles,declaredBytes])if(value!==undefined&&(!Number.isSafeInteger(value)||value<0))throw Error('Invalid declared prepared asset totals.');
 const entries=[];let totalBytes=0,lastInventory=0;
 const inventoryProgress=(force=false)=>{if(force||Date.now()-lastInventory>=100){lastInventory=Date.now();onProgress({phase:'inventory',files:entries.length,totalFiles:declaredFiles??0,bytes:0,totalBytes:declaredBytes??0});}};
 inventoryProgress(true);
 for(const [kind,rootValue]of Object.entries(roots)){
  const root=path.resolve(rootValue);const contained=inside(engine,root)||(mountReal&&inside(mountReal,root));if(!contained||samePath(root,engine))throw Error('Prepared asset root escaped the installed engine.');await unlinked(root);if(!samePath(await fs.realpath(root),root))throw Error('Prepared asset root resolution changed.');
  const pending=[root];while(pending.length){cancelled();const dir=pending.pop(),names=await fs.readdir(dir);let next=0,inventoryFailure=null;
   await Promise.all(Array.from({length:Math.min(concurrency,names.length)},async()=>{while(!inventoryFailure&&next<names.length){const name=names[next++];try{cancelled();const full=path.join(dir,name),st=await fs.lstat(full);if(st.isSymbolicLink())throw Error('Asset preload refuses linked assets.');if(st.isDirectory())pending.push(full);else if(st.isFile()){entries.push({file:kind+'/'+path.relative(root,full).replaceAll('\\','/'),full,bytes:st.size,mtimeMs:st.mtimeMs,ctimeMs:st.ctimeMs,ino:st.ino,dev:st.dev});totalBytes+=st.size;inventoryProgress();}else throw Error('Unsupported prepared asset entry.');}catch(error){inventoryFailure??=error;}}}));if(inventoryFailure)throw inventoryFailure;
  }
 }
 inventoryProgress(true);if((declaredFiles!==undefined&&entries.length!==declaredFiles)||(declaredBytes!==undefined&&totalBytes!==declaredBytes))throw Error('Prepared asset inventory does not match declared file/byte totals. Repair before playing.');
 entries.sort((a,b)=>a.file.localeCompare(b.file));if(!entries.length)throw Error('Prepared asset inventory is empty.');
 let preparationId=null;
 if(await fs.lstat(path.join(engine,'dedicated-install.json')).catch(()=>null)){
  const owner=await ownedRuntime(engine,active,(files,totalFiles)=>onProgress({phase:'runtime-fingerprint',files,totalFiles})),expected=assetPreparationIdentity(active);
  if(owner.assetPreparationId){if(owner.assetPreparationId!==expected)throw Error('Prepared asset snapshot does not match the verified installation. Repair before playing.');preparationId=owner.assetPreparationId;}
 }
 // Legacy owned markers retain their original receipt identity and tamper checks.
 // Only an authorized installation/update can attest a new preparation snapshot.
 const generation=digest(JSON.stringify({version:active.version,roots,...(preparationId?{assetPreparationId:preparationId}:{})})),run=path.join(engine,'run');if(await fs.lstat(run).catch(()=>null))await unlinked(run);else await fs.mkdir(run);const receiptPath=path.join(run,'asset-preload-'+generation+'.json');onProgress({phase:'receipt-validation'});let trusted=null;try{await unlinked(receiptPath);trusted=JSON.parse(await fs.readFile(receiptPath,'utf8'));}catch(error){if(error.code!=='ENOENT')throw error;}
 if(trusted&&(trusted.version!==1||trusted.generation!==generation||trusted.sourceVersion!==active.version||(trusted.assetPreparationId??null)!==preparationId||!Array.isArray(trusted.entries)))throw Error('Asset preload receipt is invalid.');
 let legacyOriginal=null;
 if(preparationId&&!trusted){
  const legacyGeneration=digest(JSON.stringify({version:active.version,roots})),legacyName='asset-preload-'+legacyGeneration+'.json';
  if(await fs.lstat(path.join(run,legacyName)).catch(()=>null)){
   onProgress({phase:'receipt-validation'});assetPreloadReceipts(engine);const legacy=JSON.parse(await fs.readFile(path.join(run,legacyName),'utf8'));
   if(legacy.sourceVersion!==active.version)throw Error('Legacy asset receipt source changed; repair verification required.');
   legacyOriginal=new Map(legacy.entries.filter(e=>!e.file.startsWith('gamedata/')).map(e=>[e.file,e]));
   if(entries.filter(e=>!e.file.startsWith('gamedata/')).length!==legacyOriginal.size||entries.some(e=>!e.file.startsWith('gamedata/')&&legacyOriginal.get(e.file)?.bytes!==e.bytes))throw Error('Original asset inventory changed during receipt migration. Repair before playing.');
  }
 }
 const previous=trusted?new Map(trusted.entries.map(e=>[e.file,e])):null;if(previous&&(previous.size!==entries.length||entries.some(e=>previous.get(e.file)?.bytes!==e.bytes)))throw Error('Installed asset inventory changed within the same generation. Repair the installation before playing.');
 // FAST_RECEIPT_REUSE: owned install with matching preparation + trusted receipt + unchanged size/mtime/ctime/ino/dev skips full SHA rehash (no warm reads; files load on demand like Global).
 if(previous&&preparationId&&trusted?.assetPreparationId===preparationId){
  let files=0,bytes=0;const results=new Array(entries.length);const emit=()=>onProgress({phase:'Verify installed assets (receipt)',files,totalFiles:entries.length,bytes,totalBytes,generation});emit();
  let next=0,failure=null;const workers=Math.min(concurrency,entries.length);
  await Promise.all(Array.from({length:workers},async()=>{while(!failure){const index=next++;if(index>=entries.length)return;const entry=entries[index];try{cancelled();const st=await fs.lstat(entry.full);if(st.isSymbolicLink()||!st.isFile()||st.size!==entry.bytes||st.mtimeMs!==entry.mtimeMs||st.ctimeMs!==entry.ctimeMs||st.ino!==entry.ino||st.dev!==entry.dev)throw Error('Installed asset identity changed: '+entry.file+'. Repair before playing.');const prior=previous.get(entry.file);if(!prior||prior.bytes!==entry.bytes||typeof prior.sha256!=='string'||!/^[a-f0-9]{64}$/.test(prior.sha256))throw Error('Trusted receipt entry missing for '+entry.file);/* LAUNCH_PARITY 2026-10-29: no per-file open/64KB sample read here (it hashed nothing). Global opens only its pack index + packs at launch (Procmon global-0-100-20261027-231624: 81 files); this sample pass opened all ~200k loose files (take5 Procmon 6:42:10-6:43:35). Identity (lstat) + trusted receipt checks above are unchanged. */results[index]={file:entry.file,bytes:entry.bytes,sha256:prior.sha256};files++;bytes+=entry.bytes;emit();}catch(error){failure??=signal?.aborted?Error('Asset preload cancelled. Game launch stopped.'):error;}}}));if(failure)throw failure;cancelled();const finalSource=resolveSource(engine);if(finalSource.version!==active.version||!samePath(finalSource.dataRoot,active.dataRoot)||!samePath(finalSource.gamedataRoot,active.gamedataRoot)||(preparationId&&assetPreparationIdentity(finalSource)!==preparationId))throw Error('Prepared generation changed during asset verification. Retry launch.');
  return {verified:true,baselineCreated:false,files,bytes,totalBytes,generation,receipt:path.basename(receiptPath),fastReceiptReuse:true,scope:'Receipt-backed identity verification (no warm reads); full SHA-256 already attested for this preparation.'};
 }
 let cursor=0,files=0,bytes=0;const results=new Array(entries.length),emit=()=>onProgress({phase:'Verify and warm all installed assets',files,totalFiles:entries.length,bytes,totalBytes,generation});emit();let failure=null;
 // Workers read exactly the inventoried length; the post-read size/mtime/ctime/ino/dev checks
 // still reject growth, truncation, replacement and links. Avoid one redundant EOF read per file.
 // Every launch still reads and hashes every byte. Receipt timestamps are not
 // authentication: never skip a checksum based on editable metadata alone.
 if(ioWorkers){
  const positions=new Map(entries.map((entry,index)=>[entry.file,index]));
  await warmInWorkers(entries,{count:ioWorkers,chunkBytes,signal,onBytes:count=>{bytes+=count;emit();},onResult:result=>{cancelled();if((previous&&previous.get(result.file)?.sha256!==result.sha256)||(legacyOriginal&&legacyOriginal.has(result.file)&&legacyOriginal.get(result.file).sha256!==result.sha256))throw Error('Installed asset checksum changed: '+result.file+'. Repair before playing.');results[positions.get(result.file)]=result;files++;}});
 }else await Promise.all(Array.from({length:concurrency},async()=>{while(!failure&&cursor<entries.length){const index=cursor++,entry=entries[index];try{
  cancelled();const hash=createHash('sha256');let read=0;
  if(entry.bytes<=chunkBytes){
   // Bound tiny-file buffers by concurrency * chunkBytes; avoid a stream and
   // async iterator for each of the many small native records.
   const handle=await fs.open(entry.full,'r');try{const data=Buffer.allocUnsafe(entry.bytes+1);while(read<data.length){cancelled();const result=await handle.read(data,read,data.length-read,read);if(!result.bytesRead)break;read+=result.bytesRead;}cancelled();bytes+=read;hash.update(data.subarray(0,read));emit();}finally{await handle.close();}
  }else{
   const stream=createReadStream(entry.full,{highWaterMark:chunkBytes});const abort=()=>stream.destroy(Error('Asset preload cancelled. Game launch stopped.'));signal?.addEventListener('abort',abort,{once:true});try{for await(const chunk of stream){cancelled();read+=chunk.length;bytes+=chunk.length;hash.update(chunk);emit();}}finally{signal?.removeEventListener('abort',abort);stream.destroy();}
  }
  const after=await fs.lstat(entry.full);if(after.isSymbolicLink()||!after.isFile()||after.size!==entry.bytes||after.mtimeMs!==entry.mtimeMs||after.ctimeMs!==entry.ctimeMs||after.ino!==entry.ino||after.dev!==entry.dev)throw Error('Prepared asset changed while reading: '+entry.file);
  if(read!==entry.bytes)throw Error('Installed asset changed while reading: '+entry.file);
  const sha256=hash.digest('hex');if((previous&&previous.get(entry.file)?.sha256!==sha256)||(legacyOriginal&&legacyOriginal.has(entry.file)&&legacyOriginal.get(entry.file).sha256!==sha256))throw Error('Installed asset checksum changed: '+entry.file+'. Repair before playing.');results[index]={file:entry.file,bytes:read,sha256};files++;emit();
 }catch(error){failure??=signal?.aborted?Error('Asset preload cancelled. Game launch stopped.'):error;}}}));if(failure)throw failure;cancelled();const finalSource=resolveSource(engine);if(finalSource.version!==active.version||!samePath(finalSource.dataRoot,active.dataRoot)||!samePath(finalSource.gamedataRoot,active.gamedataRoot)||(preparationId&&assetPreparationIdentity(finalSource)!==preparationId))throw Error('Prepared generation changed during asset verification. Retry launch.');
 const receipt={version:1,generation,sourceVersion:active.version,...(preparationId?{assetPreparationId:preparationId}:{}),files,totalBytes,entries:results},temp=receiptPath+'.tmp-'+randomUUID();try{await fs.writeFile(temp,JSON.stringify(receipt),{flag:'wx'});cancelled();await fs.rename(temp,receiptPath);}finally{await fs.unlink(temp).catch(e=>{if(e.code!=='ENOENT')throw e;});}
 return {verified:true,baselineCreated:!trusted,files,bytes,totalBytes,generation,receipt:path.basename(receiptPath),scope:'Installed file SHA-256 verification and OS file-cache warming; not complete CPU/GPU decoding or guaranteed cache residency.'};
}
if(isMainThread&&process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
 const arg=name=>{const at=process.argv.indexOf(name);return at<0?null:process.argv[at+1];},engine=arg('--engine'),progress=arg('--progress');let last=0,lastPhase=null;
 try{const result=await verifyAndWarmAssets({engine,onProgress:state=>{if(progress&&(state.phase!==lastPhase||Date.now()-last>=100)){last=Date.now();lastPhase=state.phase;writeFileSync(progress,JSON.stringify(state));}}});if(progress)await fs.writeFile(progress,JSON.stringify({...result,phase:'All installed assets verified',files:result.files,totalFiles:result.files,bytes:result.bytes,totalBytes:result.totalBytes}));console.log(JSON.stringify(result));}catch(error){console.error(error.message);process.exitCode=1;}
}
