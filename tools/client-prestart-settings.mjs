// Local installation settings before import/start; no account or credential writes.
import fs from 'node:fs/promises';
import {readFileSync} from 'node:fs';
import path from 'node:path';
import {fileURLToPath, pathToFileURL} from 'node:url';
import {randomBytes} from 'node:crypto';
import {engineIdentity} from '../server/client-identity.mjs';
import {createServerSettings} from '../server/server-settings.mjs';
import {capacityFile, normalizeCapacity, memoryRange} from '../server/capacity-settings.mjs';

async function ordinary(file, directory=false) {
  let current=path.parse(file).root; const parts=path.relative(current,file).split(path.sep).filter(Boolean);
  for(let i=0;i<parts.length;i++) {
    if(process.platform==='win32'&&/[:\x00-\x1f]/.test(parts[i]))throw Error('Invalid local settings path.');
    current=path.join(current,parts[i]);const stat=await fs.lstat(current).catch(e=>{if(e.code==='ENOENT')return null;throw e;});
    if(stat&&(stat.isSymbolicLink()||(i<parts.length-1||directory?!stat.isDirectory():!stat.isFile()||stat.nlink>1)))throw Error('Local settings require ordinary unlinked paths.');
  }
}
async function json(file) {
  await ordinary(file);
  try {if((await fs.stat(file)).size>16384)throw Error('Local settings file too large.');return JSON.parse(await fs.readFile(file,'utf8'));}
  catch(e){if(e.code==='ENOENT')return null;throw e;}
}
async function atomic(file,value) {
  await ordinary(file);await fs.mkdir(path.dirname(file),{recursive:true});await ordinary(file);
  const temp=file+'.'+randomBytes(8).toString('hex')+'.tmp';
  try{await fs.writeFile(temp,JSON.stringify(value,null,2),{flag:'wx',mode:0o600});await ordinary(file);await fs.rename(temp,file);}
  finally{await fs.rm(temp,{force:true}).catch(()=>{});}
}
export async function prestartSettings({engine,scope='local',operation='read',value}) {
  if(!path.isAbsolute(engine)||!['local','friends'].includes(scope))throw Error('Invalid local settings target.');
  engine=path.resolve(engine);await ordinary(engine,true);const identity=engineIdentity(engine);
  const store=path.join(engine,'server/accounts',scope==='friends'?'friends-accounts.json':'data.json');
  const receipt=store+'.prestart.json',capacity=capacityFile(engine);
  const activeScopes=new Set();
  const running=async()=>{
    activeScopes.clear();
    const directory=path.join(engine,'server');await ordinary(directory,true);
    const records=(await fs.readdir(directory).catch(e=>{if(e.code==='ENOENT')return [];throw e;})).filter(x=>/^launcher-control(?:-\d+)?\.json$/.test(x));
    if(records.length>64)throw Error('Too many local control records.');
    for(const name of records){const record=await json(path.join(directory,name));if(!record||!Number.isInteger(record.pid)||record.pid<1)throw Error('Invalid local server control.');
      let alive=true;try{process.kill(record.pid,0);}catch(e){if(e.code==='ESRCH')alive=false;else if(e.code!=='EPERM')throw e;}
      if(alive){let active='unknown';try{const url=new URL(record.url);if(record.engineId===identity&&url.protocol==='http:'&&['localhost','127.0.0.1','[::1]'].includes(url.hostname)&&!url.username&&!url.password&&url.pathname==='/'&&!url.search&&!url.hash)active=url.port==='7778'?'friends':'local';}catch{}activeScopes.add(active);}
    }return activeScopes.size>0;
  };
  if(!['read','set','review','capacityRead','capacitySet'].includes(operation))throw Error('Unknown local settings operation.');
  if(await running()) {if(operation==='read'&&activeScopes.has(scope))return {running:true,reviewed:false};throw Error('A world is running from this installation. Use its authenticated dashboard settings, or stop it before reviewing another world.');}
  const host=scope==='friends'?await json(path.join(engine,'server/friends-host.json')):null;
  const settings=await createServerSettings({accountStore:store,...(typeof host?.name==='string'?{name:host.name}:{})});
  if(operation==='read'){const saved=await json(receipt);if(saved&&(saved.version!==1||typeof saved.engineId!=='string'||!/^[a-f0-9]{64}$/.test(saved.engineId)||saved.reviewed!==true||Object.keys(saved).length!==3))throw Error('Invalid first-start review.');return {running:false,reviewed:!!saved&&saved.engineId===identity,settings:settings.read()};}
  if(operation==='capacityRead'||operation==='capacitySet') {
    const saved=await json(capacity),base=normalizeCapacity(saved||{});
    if(operation==='capacitySet'){const next=normalizeCapacity(value,{base});if(await running())throw Error('The local world has started.');await atomic(capacity,next);return {settings:next,memoryRange:memoryRange(),live:null};}
    return {settings:base,memoryRange:memoryRange(),live:null};
  }
  if(await running())throw Error('The local world has started.');
  if(operation==='set')return settings.set(value);
  await atomic(receipt,{version:1,engineId:identity,reviewed:true});return {reviewed:true};
}
if(process.argv[1]&&pathToFileURL(path.resolve(process.argv[1])).href===import.meta.url){
  try{const input=JSON.parse(readFileSync(0,'utf8').replace(/^\uFEFF/,'')||'null');const engine=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');console.log(JSON.stringify(await prestartSettings({engine,scope:process.argv[3]||'local',operation:process.argv[2]||'read',value:input})));}
  catch(error){console.error(error.message);process.exitCode=1;}
}
