import fs from 'node:fs/promises';
import path from 'node:path';
import {randomUUID} from 'node:crypto';
export const NPC_PROFILE_LIMIT=2500;
// ENGINE-CHOSEN optional automated characters. The private account-store namespace permits durable atomic human/NPC transactions without login users or sessions.
export function createNpcProfiles({file,getProfile,saveProfile,saveProfiles,atomicStore}) {
 const profiles=new Map();let loaded=false,loading,writes=Promise.resolve();
 async function ordinary(){let p=path.parse(file).root;for(const part of path.relative(p,file).split(path.sep)){p=path.join(p,part);const s=await fs.lstat(p).catch(e=>{if(e.code==='ENOENT')return null;throw e});if(s&&(s.isSymbolicLink()||(!s.isDirectory()&&(!s.isFile()||s.nlink>1))))throw Error('NPC store must be ordinary unlinked storage');}}
 function valid(id,p){return /^npc_[a-f0-9]{32}$/.test(id)&&p?.authority==='server'&&p.npcPlayer===true&&p.id;}
 async function load(){if(loaded)return;if(!loading)loading=(async()=>{
  let rows;if(atomicStore)rows=Object.entries(await atomicStore.loadNpcProfiles());
  else{await ordinary();try{const s=JSON.parse(await fs.readFile(file,'utf8'));if(s.version!==1||!Array.isArray(s.profiles))throw Error('Invalid NPC profile store');rows=s.profiles}catch(e){if(e.code!=='ENOENT')throw e;rows=[]}}
  if(rows.length>NPC_PROFILE_LIMIT||rows.some(([id,p])=>!valid(id,p)))throw Error('Invalid NPC character store');for(const [id,p]of rows)profiles.set(id,structuredClone(p));loaded=true;
 })().catch(e=>{loading=null;throw e});return loading;}
 function reservedNpc(id){if(typeof id!=='string')throw Error('Invalid profile account');if(!id.startsWith('npc_'))return false;if(!/^npc_[a-f0-9]{32}$/.test(id))throw Error('Invalid reserved NPC identity');return true;}
 function own(id){return typeof id==='string'&&/^npc_[a-f0-9]{32}$/.test(id)&&profiles.has(id);}
 async function writeFile(next){await ordinary();await fs.mkdir(path.dirname(file),{recursive:true});const tmp=file+'.'+randomUUID()+'.tmp';try{await fs.writeFile(tmp,JSON.stringify({version:1,profiles:[...next]}),{flag:'wx',mode:0o600});await ordinary();await fs.rename(tmp,file)}finally{await fs.rm(tmp,{force:true}).catch(()=>{})}}
 function queue(fn){const task=writes.catch(()=>{}).then(fn);writes=task;return task;}
 function validate(id,cid,p){if(!own(id)||profiles.get(id).id!==cid||p.id!==cid||!valid(id,p))throw Error('Invalid NPC profile transaction');}
 // Keep the canonical Map's insertion order during progress commits. Clearing
 // it invalidates a long-lived population iterator and can starve every saved
 // character beyond the first few rows. Publication is still synchronous and
 // only follows a completed durable transaction.
 function publish(next){for(const id of profiles.keys())if(!next.has(id))profiles.delete(id);for(const [id,p]of next)profiles.set(id,p);}
 const missing=()=>{throw Object.assign(Error('Atomic NPC progress storage is unavailable.'),{status:503});};
 return {load,own,profiles,
  // Snapshot stamps come from the backend, never the requested-profile cache.
  async admissionSnapshot(rows){
   if(!Array.isArray(rows)||!rows.length||rows.length>16)throw Error('Invalid NPC admission wave');
   await load();const keys=new Set();
   for(const r of rows){if(!r||!reservedNpc(r.accountId)||!own(r.accountId)||profiles.get(r.accountId).id!==r.characterId||keys.has(r.accountId))throw Error('Invalid NPC admission identity');keys.add(r.accountId);}
   if(!atomicStore?.readNpcAdmissions)missing();
   return atomicStore.readNpcAdmissions(rows);
  },
  // Called only inside the world's save task. Hold cache order across durable
  // CAS and normalized publication, never across native staging/saveQueue waits.
  async admissionCommit(rows){
   if(!Array.isArray(rows)||!rows.length||rows.length>16)throw Error('Invalid NPC admission wave');
   await load();return queue(async()=>{
    if(!atomicStore?.commitNpcAdmissions)missing();const keys=new Set();
    for(const r of rows){if(!r||!reservedNpc(r.accountId)||keys.has(r.accountId))throw Error('Invalid NPC admission identity');validate(r.accountId,r.characterId,r.profile);keys.add(r.accountId);}
    const result=await atomicStore.commitNpcAdmissions(rows);
    try{
    if(result?.committed!==true||!Array.isArray(result.updates)||result.updates.length!==rows.length)missing();
    const next=new Map(profiles),remaining=new Map(rows.map(r=>[r.accountId,r.characterId]));
    for(const u of result.updates){if(!u||remaining.get(u.accountId)!==u.characterId||Object.hasOwn(u.profile||{},'accountFeatures'))missing();validate(u.accountId,u.characterId,u.profile);remaining.delete(u.accountId);next.set(u.accountId,structuredClone(u.profile));}
    if(remaining.size)missing();publish(next);return result;
    }catch(error){if(result?.committed===true)error.npcAdmissionCommitted=true;throw error;}
   });
  },
  // Trusted lifecycle migration only; account store commits every reference first.
  async migrateNames(proposal,context){await load();return queue(async()=>{
   if(!atomicStore?.migrateNpcNames)missing();
   const result=await atomicStore.migrateNpcNames(proposal,context);
   if(result?.committed!==true||!Array.isArray(result.updates))missing();
   const next=new Map(profiles);
   for(const u of result.updates){validate(u.accountId,u.characterId,u.profile);next.set(u.accountId,structuredClone(u.profile));}
   publish(next);return result;
  });},
  // Trusted cache publication AFTER a canonical transaction has committed.
  // Never called by HTTP; no second file write or independent reward commit.
  async adoptCommitted(updates){
   if(!Array.isArray(updates)||updates.length>187)throw Error('Invalid committed NPC updates');
   for(const u of updates){if(!u||typeof u.accountId!=='string'||!u.profile||typeof u.characterId!=='string')throw Error('Invalid committed NPC updates');reservedNpc(u.accountId);}
   if(!updates.some(u=>reservedNpc(u.accountId)))return true;
   await load();return queue(async()=>{
   if(!Array.isArray(updates)||updates.length>187)throw Error('Invalid committed NPC updates');
   const bots=updates.filter(u=>own(u?.accountId)),keys=new Set();
   for(const u of updates){if(!u||typeof u.accountId!=='string'||!u.profile||typeof u.characterId!=='string')throw Error('Invalid committed NPC updates');if(/^npc_[a-f0-9]{32}$/.test(u.accountId)&&!own(u.accountId))throw Error('Invalid NPC profile transaction');}
   for(const u of bots){validate(u.accountId,u.characterId,u.profile);if(keys.has(u.accountId)||Object.hasOwn(u.profile,'accountFeatures'))throw Error('Invalid committed NPC updates');keys.add(u.accountId);}
   const next=new Map(profiles);for(const u of bots){const old=profiles.get(u.accountId);next.set(u.accountId,{...structuredClone(u.profile),id:old.id,name:old.name,nameColor:old.nameColor||'white',classIndex:old.classIndex,className:old.className,authority:'server',npcPlayer:true});}
   publish(next);return true;
  });},
  async add(p){await load();const id='npc_'+randomUUID().replaceAll('-','');if(!valid(id,p))throw Error('Invalid NPC profile');return queue(async()=>{if(profiles.size>=NPC_PROFILE_LIMIT)throw Error('NPC roster capacity reached');const next=new Map(profiles);next.set(id,structuredClone(p));if(atomicStore){if(await atomicStore.addNpcProfile(id,p)!==true)missing()}else await writeFile(next);publish(next);return id});},
  async addBatch(input){await load();if(!Array.isArray(input)||!input.length||input.length>64)throw Error('Invalid NPC bootstrap batch');const prepared=input.map(p=>({accountId:'npc_'+randomUUID().replaceAll('-',''),profile:structuredClone(p)}));if(prepared.some(r=>!valid(r.accountId,r.profile)))throw Error('Invalid NPC profile');return queue(async()=>{
   if(profiles.size+prepared.length>NPC_PROFILE_LIMIT)throw Error('NPC roster capacity reached');const next=new Map(profiles);for(const r of prepared)next.set(r.accountId,r.profile);
   if(atomicStore){if(!atomicStore.addNpcProfiles||await atomicStore.addNpcProfiles(prepared)!==true)missing()}else await writeFile(next);
   publish(next);return prepared.map(r=>({account:r.accountId,profile:structuredClone(r.profile)}));
  });},
  async get(id,cid){if(!reservedNpc(id))return getProfile(id,cid);await load();if(own(id))return profiles.get(id).id===cid?structuredClone(profiles.get(id)):null;return null;},
  async save(id,cid,p){if(!reservedNpc(id))return saveProfile(id,cid,p);await load();return queue(async()=>{validate(id,cid,p);const old=profiles.get(id),next=new Map(profiles);next.set(id,{...structuredClone(p),id:old.id,name:old.name,classIndex:old.classIndex,authority:'server',npcPlayer:true});if(atomicStore){if(await atomicStore.saveNpcProfile(id,cid,p)!==true)missing()}else await writeFile(next);publish(next);return true});},
  async saveMany(updates){
   if(!Array.isArray(updates)||!updates.length||updates.length>187)throw Error('Invalid mixed progress transaction');
   for(const u of updates){if(!u||typeof u.accountId!=='string'||typeof u.characterId!=='string'||!u.profile)throw Error('Invalid mixed progress target');reservedNpc(u.accountId);}
   if(!updates.some(u=>reservedNpc(u.accountId)))return queue(async()=>{
    if(atomicStore){if(await atomicStore.saveWorldAndNpcProfiles(updates)!==true)missing();return true;}
    return saveProfiles(updates);
   });
   await load();return queue(async()=>{const bots=updates.filter(u=>own(u.accountId)),humans=updates.filter(u=>!own(u.accountId));for(const u of bots)validate(u.accountId,u.characterId,u.profile);const next=new Map(profiles);for(const u of bots){const old=profiles.get(u.accountId);next.set(u.accountId,{...structuredClone(u.profile),id:old.id,name:old.name,classIndex:old.classIndex,authority:'server',npcPlayer:true});}
   if(atomicStore){if(await atomicStore.saveWorldAndNpcProfiles(updates)!==true)missing()}
   else if(bots.length&&humans.length)missing();
   else if(humans.length){if(await saveProfiles(humans)===false)return false;}
   else if(bots.length)await writeFile(next);
   publish(next);return true;
  });},
  // LANE1-PERF: shutdown/handoff flush closes any bot save-coalescing window.
  async flush(){if(atomicStore?.flushPendingCommits)await atomicStore.flushPendingCommits(writes);await writes;},
 };
}
