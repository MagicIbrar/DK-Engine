import fs from 'node:fs/promises';
import path from 'node:path';
import {randomUUID} from 'node:crypto';
import net from 'node:net';
import {npcLegacyGeneratedName,proposeNpcUsernameMigration} from './npc-usernames.mjs';

// Trusted ENGINE-CHOSEN startup migration; never callable over HTTP or after
// world/listener creation. Human names are reserved internally, never returned.
export async function assertNpcStartupPortAvailable({host,port}={}){
 if(typeof host!=='string'||!host||host.length>253||!Number.isInteger(port)||port<1||port>65535)throw Error('Invalid NPC startup listener check');
 await new Promise((resolve,reject)=>{
  const probe=net.createServer();let settled=false;
  const finish=error=>{if(settled)return;settled=true;clearTimeout(timer);error?reject(error):resolve();};
  const timer=setTimeout(()=>{probe.close(()=>{});finish(Error('NPC startup listener check timed out'));},1500);
  probe.once('error',()=>finish(Error('NPC startup listener already active or unavailable')));
  probe.listen({host,port,exclusive:true},()=>probe.close(error=>finish(error)));
 });
}

export async function prepareNpcNamesBeforeWorld({profiles,accounts,rosterFile,authorized=false,hasWorld,hasListener,assertListenerAvailable}={}){
 const inactive=()=>{
  if(typeof hasWorld!=='function'||typeof hasListener!=='function'||hasWorld()!==false||hasListener()!==false)throw Error('NPC name preparation requires inactive startup');
  return false;
 };
 inactive();
 if(authorized!==true||!profiles?.load||!profiles?.flush||!accounts?.listWorldCharacters||typeof rosterFile!=='string'||typeof assertListenerAvailable!=='function')throw Error('Explicit generated NPC startup authorization required');
 await assertListenerAvailable();inactive();
 await profiles.load();inactive();await profiles.flush();inactive();
 const humans=await accounts.listWorldCharacters();inactive();
 if(!Array.isArray(humans)||!(profiles.profiles instanceof Map))throw Error('Canonical startup names unavailable');
 const file=path.resolve(rosterFile);
 async function ordinary(){let p=path.parse(file).root;for(const part of path.relative(p,file).split(path.sep)){p=path.join(p,part);const s=await fs.lstat(p).catch(e=>{if(e.code==='ENOENT')return null;throw e;});if(s&&(s.isSymbolicLink()||(p===file&&(!s.isFile()||s.nlink>1))))throw Error('NPC startup roster needs ordinary unlinked storage');}}
 await ordinary();inactive();let saved=null;
 try{const stat=await fs.stat(file);if(stat.size>8*1024*1024)throw Error('NPC startup roster storage bound');saved=JSON.parse(await fs.readFile(file,'utf8'));if(saved.version!==1||!Array.isArray(saved.rows)||saved.rows.length>4096||saved.rows.some(r=>typeof r?.name!=='string'||!/^r[a-f0-9]{24}$/.test(r.npcRosterId)))throw Error('Invalid NPC startup roster');}catch(e){if(e.code!=='ENOENT')throw e;}
 inactive();
 // Owner explicitly authorized recognized historical generated handles only.
 // Canonical transaction independently rechecks authority/custom/provenance.
 const confirmedLegacyIds=new Set([...profiles.profiles].filter(([,p])=>p.authority==='server'&&p.npcPlayer===true&&(p.npcSeed||p.npcRosterId)&&!p.npcNameCustom&&!p.npcCustomName&&npcLegacyGeneratedName(p.name)).map(([id])=>id));
 const usedNames=new Set([...humans.map(p=>p.name),...(saved?.rows||[]).map(r=>r.name)]);
 const proposal=proposeNpcUsernameMigration({profiles:profiles.profiles,usedNames,confirmedLegacyIds});
 if(proposal.changes.length){inactive();await profiles.migrateNames(proposal,{isActive:inactive,confirmedLegacyIds,rosterBindings:saved?.rows||[]});inactive();await profiles.flush();inactive();}
 // Canonical names always win for exact bound identities. This repairs a prior
 // committed transaction if the separate metadata write was interrupted.
 let repairedBindings=0;
 if(saved){const next=structuredClone(saved);for(const row of next.rows){const p=profiles.profiles.get(row.binding?.account);if(p?.authority==='server'&&p.npcPlayer===true&&p.id===row.binding?.profileId&&row.name!==p.name){row.name=p.name;row.npcNameSource=p.npcNameSource||row.npcNameSource;repairedBindings++;}}
  if(repairedBindings){const bytes=JSON.stringify(next);if(Buffer.byteLength(bytes)>8*1024*1024)throw Error('NPC startup roster storage bound');inactive();await ordinary();const tmp=file+'.'+randomUUID()+'.tmp';try{await fs.writeFile(tmp,bytes,{flag:'wx',mode:0o600});inactive();await ordinary();await fs.rename(tmp,file);}finally{await fs.rm(tmp,{force:true}).catch(()=>{});}}
 }
 inactive();return Object.freeze({migrated:proposal.changes.length,repairedBindings,refreshGeneratedNames:true});
}
