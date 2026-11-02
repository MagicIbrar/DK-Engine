// Native UI support: validate the exact parent installation; deletion is always a deliberate UI action.
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { fileURLToPath } from 'node:url';
import { clientSource } from '../server/client-source.mjs';
import { engineIdentity, runtimeVersion } from '../server/client-identity.mjs';
const ownFile = fileURLToPath(import.meta.url);
const expectedEngine = path.dirname(path.dirname(ownFile));
const normalize = value => path.resolve(value).toLowerCase();
const optionalStat = value => { try { return fs.lstatSync(value); } catch (err) { if (err.code === 'ENOENT') return null; throw err; } };
function safeAncestors(value) {
  let current=path.resolve(value);
  while(true) {if(fs.lstatSync(current).isSymbolicLink())throw new Error(`Refusing a symbolic link or junction: ${current}`);const parent=path.dirname(current);if(parent===current)break;current=parent;}
}
function safeTree(root) {
 // A link inside a removal candidate is an entry to unlink, never a tree to scan.
 // Root entries and all retained paths are still required to be ordinary paths.
 const pending=[root]; while(pending.length) {const current=pending.pop();safeAncestors(path.dirname(current));const stat=fs.lstatSync(current);if(stat.isSymbolicLink())continue;if(stat.isDirectory())for(const name of fs.readdirSync(current))pending.push(path.join(current,name));}
}
function removeTreeUnlinked(root) {
 const pending=[{file:root,visited:false}];
 while(pending.length){
  const {file,visited}=pending.pop();
  // Recheck before every operation so a replaced ancestor cannot redirect cleanup.
  safeAncestors(path.dirname(file));
  const stat=fs.lstatSync(file);
  if(stat.isSymbolicLink()){
   if(normalize(file)===normalize(root))throw new Error('Refusing a linked cleanup root.');
   fs.unlinkSync(file);
  }else if(stat.isDirectory()){
   if(visited)fs.rmdirSync(file);
   else {pending.push({file,visited:true});for(const name of fs.readdirSync(file))pending.push({file:path.join(file,name),visited:false});}
  }else fs.rmSync(file,{force:false});
 }
}
export function planInstall(target=path.dirname(expectedEngine)) {
 safeAncestors(ownFile);safeAncestors(target);
 const engine=fs.realpathSync(expectedEngine),root=fs.realpathSync(target);
 if(normalize(root)!==normalize(path.dirname(engine))||path.basename(engine).toLowerCase()!=='engine')throw new Error('Target must directly contain this exact engine folder.');
 const profile=process.env.USERPROFILE||os.homedir();
 const userFolders=['Desktop','Downloads','Documents','Pictures','Videos','Music','AppData'];
 const forbidden=[path.parse(root).root,os.homedir(),profile,...userFolders.map(name=>path.join(profile,name)),...userFolders.map(name=>process.env.OneDrive&&path.join(process.env.OneDrive,name)),process.env.WINDIR,process.env.SystemRoot,process.env.ProgramFiles,process.env['ProgramFiles(x86)'],process.env.ProgramData].filter(Boolean);
 if(forbidden.some(value=>normalize(value)===normalize(root)))throw new Error('Refusing a drive root, home folder, standard personal folder, or system folder target.');
 const entries=fs.readdirSync(root,{withFileTypes:true}),names=new Map();
 for(const entry of entries){const lower=entry.name.toLowerCase();if(names.has(lower))throw new Error(`Duplicate case-insensitive entry: ${entry.name}`);names.set(lower,entry.name);if(fs.lstatSync(path.join(root,entry.name)).isSymbolicLink())throw new Error(`Refusing a root link or junction: ${entry.name}`);}
 for(const name of ['data','bin','engine']){const actual=names.get(name);if(!actual||!fs.statSync(path.join(root,actual)).isDirectory())throw new Error(`Missing required folder: ${name}`);}
 const clientName=names.get('client.exe');if(clientName){const st=fs.statSync(path.join(root,clientName));if(!st.isFile()||st.nlink>1)throw new Error('Client.exe must be an ordinary unlinked file.');}
 const receipt=path.join(engine,'install-receipt.json');if(optionalStat(receipt)?.isSymbolicLink())throw new Error('Refusing a linked install receipt.');
 // Keep all user-supplied Global files intact.
const remove=[]; // Preserve the user's Global files.
 for(const name of remove)safeTree(path.join(root,name));
 const portFile=path.join(engine,'server/launcher-port.json');let storedPort=7777;if(!process.env.PORT&&optionalStat(portFile)){safeAncestors(portFile);const st=fs.lstatSync(portFile);if(!st.isFile()||st.nlink>1||st.size>16384)throw new Error('Refusing linked or invalid local port state.');const saved=JSON.parse(fs.readFileSync(portFile,'utf8'));if(!saved||Object.keys(saved).some(k=>!['version','port'].includes(k))||saved.version!==1||!Number.isInteger(saved.port)||saved.port<1||saved.port>65535||[7778,7840].includes(saved.port))throw new Error('Invalid saved local port.');storedPort=saved.port;}const port=Number(process.env.PORT||storedPort);
 if(!Number.isInteger(port)||port<1||port>65535)throw new Error('PORT must be between 1 and 65535.');
 return {root,engine,engineId:engineIdentity(engine),version:clientSource(engine).version,runtimeVersion:runtimeVersion(engine),serverUrl:`http://localhost:${port}/`,clientName,remove};
}
export function stageLauncher(target){const plan=planInstall(target);const source=path.join(plan.engine,'Client.exe'),st=optionalStat(source);if(!st||st.isSymbolicLink()||!st.isFile()||st.nlink>1)throw new Error('Missing or linked engine/Client.exe. Build the launcher before installing.');const staged=path.join(plan.engine,'install-client-launcher.tmp');const existing=optionalStat(staged);if(existing&&(existing.isSymbolicLink()||!existing.isFile()||existing.nlink>1))throw new Error('Refusing a linked staged launcher.');fs.copyFileSync(source,staged);return staged;}
function identicalFile(a,b){const sa=fs.lstatSync(a),sb=fs.lstatSync(b);if(!sa.isFile()||!sb.isFile()||sa.isSymbolicLink()||sb.isSymbolicLink()||sa.nlink>1||sb.nlink>1||sa.size!==sb.size)return false;const aa=fs.openSync(a,'r');let bb;try{bb=fs.openSync(b,'r');const x=Buffer.allocUnsafe(65536),y=Buffer.allocUnsafe(65536);for(let pos=0;pos<sa.size;){const n=fs.readSync(aa,x,0,Math.min(x.length,sa.size-pos),pos),m=fs.readSync(bb,y,0,n,pos);if(!n||n!==m||!x.subarray(0,n).equals(y.subarray(0,m)))return false;pos+=n;}return true;}finally{fs.closeSync(aa);if(bb!==undefined)fs.closeSync(bb);}}
export function finalizeInstall(target){const plan=planInstall(target);if(plan.remove.length)throw new Error('Root cleanup is incomplete; launcher was not finalized.');const destination=path.join(plan.root,'DK-Engine-Client.exe'),existing=optionalStat(destination),source=path.join(plan.engine,'Client.exe');if(existing){safeAncestors(destination);safeAncestors(source);if(!identicalFile(destination,source))throw new Error('DK-Engine-Client.exe already exists and differs; it was not replaced.');}else{const staged=stageLauncher(target);fs.copyFileSync(staged,destination,fs.constants.COPYFILE_EXCL);fs.unlinkSync(staged);}fs.writeFileSync(path.join(plan.engine,'install-receipt.json'),JSON.stringify({target:plan.root,installed:new Date().toISOString(),permanentCleanup:false,launcher:'DK-Engine-Client.exe'},null,2));return plan;}
// Native UI calls this only after preparation, displayed-plan confirmation and launcher staging.
export function removeInstallEntry(target,name){const plan=planInstall(target);if(typeof name!=='string'||!plan.remove.includes(name)||path.basename(name)!==name)throw new Error('Cleanup entry is not in the validated removal plan.');const source=path.resolve(plan.root,name);if(normalize(path.dirname(source))!==normalize(plan.root))throw new Error('Unexpected cleanup path.');safeAncestors(source);removeTreeUnlinked(source);return plan;}
// Fixture-test helper uses the same no-follow cleanup as the production native UI.
export function installClient(target){const plan=planInstall(target);stageLauncher(target);for(const name of plan.remove)removeInstallEntry(target,name);return finalizeInstall(target);}
if(process.argv[1]&&normalize(process.argv[1])===normalize(ownFile)){
 try {const arg=process.argv.find(v=>v.startsWith('--target='));const plan=planInstall(arg?.slice(9));const cleanup=process.argv.find(v=>v.startsWith('--remove-entry='));if(cleanup){removeInstallEntry(arg?.slice(9),cleanup.slice(15));console.log('Validated cleanup entry removed.');}else{if(process.argv.includes('--stage-launcher'))stageLauncher(arg?.slice(9));if(process.argv.includes('--finalize'))finalizeInstall(arg?.slice(9));if(process.argv.includes('--plan-json'))console.log(JSON.stringify(plan));else console.log(`Exact target: ${plan.root}\nKeep: all existing Global files\nDelete: nothing\nOpen DK-Engine-Client.exe to use the native client window. This command does not delete files.`);}}catch(err){console.error(err.message);process.exitCode=1;}
}
