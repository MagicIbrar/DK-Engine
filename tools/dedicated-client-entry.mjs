import fs from 'node:fs';import {createHash} from 'node:crypto';import path from 'node:path';import {fileURLToPath} from 'node:url';
import {clientSource} from '../server/client-source.mjs';
import {discoverGlobal,discoverRawGlobals,inspect,stage,stageRawGlobal} from './stage-dedicated-install.mjs';
import {payloadFingerprint,ownedInstallation,canAdoptLegacyInstall,adoptLegacyInstall,upgradeDedicatedInstall,recoverInterruptedUpgrade} from './upgrade-dedicated-install.mjs';
const ROOT=fileURLToPath(new URL('../',import.meta.url));
const exists=p=>fs.existsSync(p);
export function normalizeGlobalData(folder){
 if(!folder)return null;return [folder,path.join(folder,'data'),path.join(folder,'data/unpacked/data'),path.join(folder,'unpacked/data'),path.join(folder,'Dekaron'),path.join(folder,'Dekaron/data')].find(p=>exists(path.join(p,'pack.hdr'))||exists(path.join(p,'share/maplist.csv')))||null;
}
function prepared(engine){try{const active=clientSource(engine),inside=p=>{const rel=path.relative(path.resolve(engine),path.resolve(p));return rel!==''&&!rel.startsWith('..'+path.sep)&&rel!=='..'&&!path.isAbsolute(rel);};return !!active.manifest&&[active.dataRoot,active.gamedataRoot,active.siteAssetRoot].every(inside)&&exists(path.join(engine,'tools/client-ui.ps1'))&&exists(path.join(engine,'Client.exe'));}catch{return false;}}
function rawFingerprint(raw){
 try{const header=fs.readFileSync(path.join(raw,'pack.hdr')),hash=b=>createHash('sha256').update(b).digest('hex');const names=[...new Set(header.toString('latin1').match(/pack\.d\d\d/g)||[])].sort();if(!names.length)return null;const packs=names.map(n=>{const st=fs.statSync(path.join(raw,n));return [n,st.size,st.mtimeMs,st.ctimeMs];});return hash(JSON.stringify({source:{kind:'pack',root:raw},header:hash(header),packs}));}catch{return null;}
}
export function clientEntryPlan({engine=ROOT,destination,globalData}={}){
 engine=path.resolve(engine);const base=process.env.LOCALAPPDATA||path.dirname(engine),canonical=path.join(base,'DK Engine'),legacy=[path.join(base,'Dekaron Dedicated'),path.join(base,'Dekaron Dedicated3.2.3')].find(exists);destination=path.resolve(destination||process.env.DEKARON_DEDICATED_INSTALL_DIR||(!exists(canonical)&&legacy?legacy:canonical));
 if(prepared(engine))return {route:'ready',engine};
 let rawGlobal=null,globalEngine=null,candidates=[];
 if(globalData){rawGlobal=normalizeGlobalData(path.resolve(globalData));if(!rawGlobal){globalEngine=path.resolve(globalData);if(!exists(path.join(globalEngine,'.client-cache/current.json')))return {route:'source-needed',message:'Choose the complete Global data folder containing pack.hdr and pack.dNN, or loose share/maplist.csv.'};}}
 else{candidates=discoverRawGlobals(engine);if(candidates.length===1)rawGlobal=candidates[0];}
 if(exists(destination)){
  const owner=ownedInstallation(destination),adoptLegacy=!owner&&canAdoptLegacyInstall(destination);
  if(!prepared(destination)||(!owner&&!adoptLegacy))return {route:'destination-needed',destination,message:'This existing folder is not a verified Dedicated installation. Choose your installed Dedicated folder; unrelated folders are preserved.'};
  const savedRawFingerprint=clientSource(destination).manifest?.sourceFingerprint;
  // Older portable receipts omitted raw provenance. Missing evidence is not a
  // changed download; a code update or an explicit new source still reparses it.
  const currentRawFingerprint=rawGlobal?rawFingerprint(rawGlobal):null;
  const rawChanged=!!(currentRawFingerprint&&(/^[a-f0-9]{64}$/.test(savedRawFingerprint||'')?currentRawFingerprint!==savedRawFingerprint:globalData));
  const changed=adoptLegacy||owner.managedFiles.some(name=>!exists(path.join(engine,name)))||owner.payloadFingerprint!==payloadFingerprint(engine,owner.managedFiles,{sanitizeImages:owner.imageSanitization===1})||rawChanged;
  if(!changed)return {route:'ready',engine:destination};
  if(!rawGlobal&&!globalEngine)globalEngine=path.join(destination,'global-prepared/engine');
  return {route:'update',engine,destination,...(rawGlobal?{rawGlobal}:{globalEngine}),adoptLegacy};
 }
 if(rawGlobal||globalEngine)return {route:'install',engine,destination,...(rawGlobal?{rawGlobal}:{globalEngine})};
 if(candidates.length>1)return {route:'source-needed',candidates,message:'Several nearby Global data folders were found. Choose the one to prepare.'};
 globalEngine=discoverGlobal(engine);
 if(globalEngine&&path.dirname(path.resolve(globalEngine))===path.dirname(engine))return {route:'install',engine,destination,globalEngine};
 return {route:'source-needed',message:'Place your downloaded Global data beside this engine, or choose its data folder.'};
}
export async function installClientEntry(plan,{nodeExecutable=process.execPath,...options}={}){
 if(!['install','update'].includes(plan.route))throw Error('A validated installation plan is required.');
 const build=destination=>plan.rawGlobal?stageRawGlobal(plan.rawGlobal,destination,{dedicatedSource:plan.engine,nodeExecutable,...options,shortcut:plan.route==='install'&&options.shortcut!==false}):stage(inspect({dedicatedSource:plan.engine,globalEngine:plan.globalEngine}),destination,{nodeExecutable,...options,shortcut:plan.route==='install'&&options.shortcut!==false});
 if(plan.route==='update'){
  if(plan.adoptLegacy)await adoptLegacyInstall(plan.destination);
  return upgradeDedicatedInstall({destination:plan.destination,buildCandidate:build,validateCandidate:async candidate=>{if(!prepared(candidate))throw Error('Updated Global preparation is incomplete. Existing install preserved.');}});
 }
 const result=await build(plan.destination);return result;
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
 try{const args=process.argv.slice(2),arg=name=>{const at=args.indexOf(name);return at<0?undefined:args[at+1];};if(!args.includes('--plan')&&!args.includes('--install'))throw Error('Use --plan or --install.');const destination=arg('--destination');if(destination)await recoverInterruptedUpgrade(destination);const plan=clientEntryPlan({engine:arg('--engine'),destination,globalData:arg('--global-data')});if(args.includes('--install')){const result=await installClientEntry(plan,{nodeExecutable:arg('--node-exe')||process.execPath});console.log(JSON.stringify({route:'ready',engine:result.installed,shortcutError:result.shortcutError}));}else console.log(JSON.stringify(plan));}catch(error){console.error(error.message);process.exitCode=1;}
}
