import fs from 'node:fs/promises';
import path from 'node:path';
import {createHash,randomUUID} from 'node:crypto';
import {channelData} from './channels.mjs';
import {npcLevelBand,npcPopulationChoice} from './npc-builds.mjs';
import {npcUsername,npcLegacyGeneratedName} from './npc-usernames.mjs';
import {createNpcEarnedRowIndex} from './npc-earned-index.mjs';

// ENGINE-CHOSEN simulated identities, NOT connections or characters. This file
// contains no equipment, money, experience, skills, objectives completed or leases.
const MAX_ROWS=4096,MAX_PAGE=100,MAX_BYTES=8*1024*1024;
const fold=s=>String(s).toLowerCase(),hash=s=>createHash('sha256').update(s).digest('hex');
const deepFreeze=o=>{if(o&&typeof o==='object'){Object.values(o).forEach(deepFreeze);Object.freeze(o);}return o;};
const own=p=>p?.authority==='server'&&p.npcPlayer===true;
const safeTraits=p=>Object.fromEntries(['policy','social','gear','pvpSkill','cosmetic','cooperative','affiliation','risk'].filter(k=>typeof p?.[k]==='string'||typeof p?.[k]==='boolean').map(k=>[k,p[k]]));
function safeActivity(p){const a=p?.npcRoutine||p?.activity;return a&&['quest','farm','merchant','rest','afk','event','dungeon'].includes(a.kind)?{kind:a.kind,...(Number.isInteger(Number(a.questId))?{questId:Number(a.questId)}:{}),source:'saved intention; no simulated progress'}:{kind:'rest',source:'ENGINE-CHOSEN simulated intention'};}
function earnedMetadata(account,p){return {account,profileId:p.id,name:p.name,...(['generated-v1','generated-v2'].includes(p.npcNameSource)?{npcNameSource:p.npcNameSource}:{}),map:Number(p.map),level:Number(p.level),classIndex:Number(p.classIndex),traits:safeTraits(p.npcTraits),activity:safeActivity(p)};}

// Fast path only for the exact canonical projection. Noncanonical shape/order
// falls through to the original JSON comparison; no profile-reference caching.
const activityKinds=new Set(['quest','farm','merchant','rest','afk','event','dungeon']);
const traitValue=v=>typeof v==='string'||typeof v==='boolean';
const traitKeys=['policy','social','gear','pvpSkill','cosmetic','cooperative','affiliation','risk'];
function earnedMetadataMatches(r,account,p){
 if(Object.hasOwn(r,'account')||Object.hasOwn(r,'profileId')||r.name!==p.name||r.map!==Number(p.map)||r.level!==Number(p.level)||r.classIndex!==Number(p.classIndex)||r.levelSource!=='actual earned profile')return false;
 if((p.npcNameSource==='generated-v1'||p.npcNameSource==='generated-v2')&&r.npcNameSource!==p.npcNameSource)return false;
 if(!r.binding||r.binding.account!==account||r.binding.profileId!==p.id)return false;
 let n=0;for(const key in r.binding){if(!Object.hasOwn(r.binding,key)||key!==(n++===0?'account':'profileId')||n>2)return false;}if(n!==2)return false;
 if(!r.traits)return false;let cursor=0,seen=0;
 for(const key in r.traits){if(!Object.hasOwn(r.traits,key))return false;while(cursor<traitKeys.length&&!traitValue(p.npcTraits?.[traitKeys[cursor]]))cursor++;if(cursor>=traitKeys.length||key!==traitKeys[cursor++]||r.traits[key]!==p.npcTraits[key])return false;seen++;}
 let expected=0;for(const key of traitKeys)if(traitValue(p.npcTraits?.[key]))expected++;if(seen!==expected)return false;
 const a=p.npcRoutine||p.activity,valid=a&&activityKinds.has(a.kind),quest=valid&&Number.isInteger(Number(a.questId));
 const activity=r.activity;if(!activity||activity.kind!==(valid?a.kind:'rest')||activity.source!==(valid?'saved intention; no simulated progress':'ENGINE-CHOSEN simulated intention')||quest&&activity.questId!==Number(a.questId))return false;
 n=0;for(const key in activity){const want=n===0?'kind':quest&&n===1?'questId':'source';if(!Object.hasOwn(activity,key)||key!==want||n>=(quest?3:2))return false;n++;}return n===(quest?3:2);
}

/** Metadata-only catalogue. No data.map(), collision reads, path queries or actions. */
async function nativeAreas(data){
 const lists=JSON.parse(await fs.readFile(path.join(data.gamedataRoot,'gmcommands_lists.json'),'utf8')),dk=channelData({data}).dkMaps||{},areas=[],unanchored=new Set();
 for(const entry of lists.maps||[]){const index=Number(entry.index),row=data.mapRow(index);
  if(!row||data.requiresInstance(index)||dk[index]||data.eventData?.modeOf(index)||Number(row.IsSiege))continue;
  const monsters=new Map((data.spawns(index)||[]).map((s,i)=>[i,{...s,def:data.monsterDef(s.monsterIndex)}])),placements=data.progression?.npcs?.placements?.[index]?.rows||[];
  const npcAnchor=placements.some(r=>r[1]!==null&&r[1]!==''&&r[2]!==null&&r[2]!==''&&Number.isFinite(Number(r[1]))&&Number.isFinite(Number(r[2])));
  const creatureAnchor=[...monsters.values()].some(s=>Number.isFinite(s.x)&&Number.isFinite(s.z)&&s.def?.role==='creature'&&!s.def.boss&&Number(s.def.exp)>0);
  if(!npcAnchor&&!creatureAnchor){unanchored.add(index);continue;}
  const map={index,monsters},band=npcLevelBand(data,{map});
  if(!band)continue;
  const placed=new Set(placements.map(r=>Number(r[0])));
  const goals=Object.values(data.progression?.quests?.quests||{}).filter(q=>q.offered&&!q.giver?.unplaced&&placed.has(Number(q.giver?.npc))&&!q.tags?.some(t=>['event','exchange','teleport'].includes(t))&&['kill','killOnMap','collect','talk','useSkill'].includes(q.kind)&&Number(q.level?.[0])>=band.min&&Number(q.level?.[0])<=Math.min(data.maxLevel,Number(row.LimitMaxLevel)||data.maxLevel)).map(q=>({questId:Number(q.id),level:Number(q.level[0]),source:'native offered quest and placed giver'}));
  areas.push({index,name:String(entry.name||index),map,band,goals,hub:Number(row.PeaceZone)===1&&Number(row.PcStore)===1});
 }
 return {areas:areas.sort((a,b)=>a.index-b.index),unanchored};
}

export async function createNpcDormantRoster({data,file,count=2500,existingProfiles=new Map(),usedNames=[],refreshGeneratedNames=false,refreshUnanchoredAreas=false}={}){
 if(!data||!file||!Number.isInteger(count)||count<1||count>MAX_ROWS)throw Error('Invalid simulated roster configuration');
 const {areas,unanchored}=await nativeAreas(data),byMap=new Map(areas.map(a=>[a.index,a]));if(!areas.length)throw Error('No native public roster areas');
 const classes=new Set(data.classesFile.classes.map(c=>c.index)),held=new Set();let rows=[],loaded=false,writes=Promise.resolve();
 const gcd=(a,b)=>b?gcd(b,a%b):a;let classStride=1;while(gcd(areas.length+classStride,classes.size)!==1)classStride++; // ENGINE-CHOSEN varied metadata cohorts, not native class rules.
 async function ordinary(){let current=path.parse(path.resolve(file)).root;for(const part of path.relative(current,path.resolve(file)).split(path.sep)){current=path.join(current,part);const s=await fs.lstat(current).catch(e=>{if(e.code==='ENOENT')return null;throw e;});if(s&&(s.isSymbolicLink()||(current===path.resolve(file)&&!s.isFile())||(!s.isDirectory()&&(!s.isFile()||s.nlink>1))))throw Error('Simulated roster needs ordinary unlinked storage');}}
 async function persist(next){const bytes=JSON.stringify({version:1,kind:'simulated inactive metadata',rows:next});if(Buffer.byteLength(bytes)>MAX_BYTES)throw Error('Simulated roster exceeds storage bound');await ordinary();await fs.mkdir(path.dirname(file),{recursive:true});const tmp=file+'.'+randomUUID()+'.tmp';try{await fs.writeFile(tmp,bytes,{flag:'wx',mode:0o600});await ordinary();await fs.rename(tmp,file);}finally{await fs.rm(tmp,{force:true}).catch(()=>{});}}
 const queue=fn=>{const next=writes.catch(()=>{}).then(fn);writes=next;return next;};
 function valid(r){return /^r[a-f0-9]{24}$/.test(r?.npcRosterId)&&typeof r.name==='string'&&r.name.length<=24&&Number.isInteger(r.map)&&Number.isInteger(r.level)&&r.level>=1&&r.level<=data.maxLevel&&classes.has(r.classIndex)&&(r.binding||data.mapRow(r.map));}
 function publicRow(r,activeNames){const active=activeNames===undefined?null:new Set([...activeNames].map(fold));return deepFreeze({npcRosterId:r.npcRosterId,name:r.name,...(['generated-v1','generated-v2'].includes(r.npcNameSource)?{npcNameSource:r.npcNameSource}:{}),map:r.map,mapName:byMap.get(r.map)?.name||null,level:r.level,classIndex:r.classIndex,traits:safeTraits(r.traits),activity:safeActivity(r),levelSource:r.levelSource,available:byMap.has(r.map),...(!byMap.has(r.map)?{unavailableReason:unanchored.has(r.map)?'no verified native start anchor':'unsupported ordinary roster area'}:{}),status:active?.has(fold(r.name))?'active':active?'simulated / inactive':'simulated roster',bound:!!r.binding});}
 function grow(saved){
   const next=saved.slice(),used=new Set([...usedNames,...[...existingProfiles.values()].map(p=>p.name),...saved.map(r=>r.name)].map(fold)),ids=new Set(saved.map(r=>r.npcRosterId)),salt=randomUUID();let nameIndex=0;
   // ENGINE-CHOSEN fresh births only. Never rebalance existing identities.
   const town=areas.find(a=>a.index===150&&a.hub),others=areas.filter(a=>a!==town),weighted=town&&others.length,areaBirths=new Map();
   for(const r of saved)areaBirths.set(r.map,(areaBirths.get(r.map)||0)+1);
   for(let i=next.length;i<count;i++){
    const slot=i%10,area=weighted?(slot<7?town:others[(Math.floor(i/10)*3+slot-7)%others.length]):areas[i%areas.length];
    const ordinal=weighted?(areaBirths.get(area.index)||0):i+Math.floor(i/areas.length)*classStride;
    areaBirths.set(area.index,(areaBirths.get(area.index)||0)+1);
    // Local rotation covers every class even in sparsely populated fields;
    // the goal phase also advances between class rounds instead of locking a class to one intention.
    const goalOrdinal=weighted?ordinal+Math.floor(ordinal/classes.size):ordinal,choice=npcPopulationChoice(data,area.band.min,ordinal,{map:area.map}),goal=area.hub&&goalOrdinal%3!==0&&area.goals.length?area.goals[Math.floor(goalOrdinal/3)%area.goals.length]:null;let name;
    name=npcUsername(nameIndex++,used);used.add(fold(name));
    let npcRosterId;do{npcRosterId='r'+hash(salt+':'+i+':'+randomUUID()).slice(0,24);}while(ids.has(npcRosterId));ids.add(npcRosterId);
    next.push({npcRosterId,name,npcNameSource:'generated-v2',map:area.index,level:goal?.level??choice.level,classIndex:choice.classIndex,traits:choice.traits,activity:goal?{kind:'quest',questId:goal.questId,source:goal.source}:{kind:['farm','farm','merchant','rest'][goalOrdinal%4],source:'ENGINE-CHOSEN simulated intention'},levelSource:goal?'native offered quest requirement':area.band.source});
   }return next;
 }
 async function load(){if(loaded)return api;await ordinary();let saved=[];try{const stat=await fs.stat(file);if(stat.size>MAX_BYTES)throw Error('Simulated roster exceeds storage bound');const value=JSON.parse(await fs.readFile(file,'utf8'));if(value.version!==1||!Array.isArray(value.rows)||value.rows.length>MAX_ROWS||value.rows.some(r=>!valid(r))||new Set(value.rows.map(r=>r.npcRosterId)).size!==value.rows.length||new Set(value.rows.map(r=>fold(r.name))).size!==value.rows.length)throw Error('Invalid simulated roster');saved=value.rows;}catch(e){if(e.code!=='ENOENT')throw e;}
  const initial=saved.length?saved:[...existingProfiles].filter(([,p])=>own(p)&&classes.has(p.classIndex)).map(([account,p])=>{
   const {account:unusedAccount,profileId:unusedProfile,...metadata}=earnedMetadata(account,p),id=p.npcRosterId||p.npcSeed?.rosterId;
   return {...metadata,npcRosterId:/^r[a-f0-9]{24}$/.test(id)?id:'r'+hash('earned:'+account+':'+p.id).slice(0,24),binding:{account,profileId:p.id},levelSource:'actual earned profile'};
  });
  if(initial.length>MAX_ROWS||initial.some(r=>!valid(r))||new Set(initial.map(r=>r.npcRosterId)).size!==initial.length||new Set(initial.map(r=>fold(r.name))).size!==initial.length)throw Error('Invalid earned roster identities');
  let refreshed=false;
  if(refreshUnanchoredAreas===true){const earnedIds=new Set([...existingProfiles].filter(([,p])=>own(p)).flatMap(([account,p])=>[account,p.id,p.npcRosterId,p.npcSeed?.rosterId]).filter(Boolean));
   for(let i=0;i<initial.length;i++){const r=initial[i];if(r.binding||earnedIds.has(r.npcRosterId)||!unanchored.has(r.map))continue;
    const compatible=areas.filter(a=>a.band.candidates.includes(r.level)),pool=compatible.length?compatible:areas,serial=parseInt(hash(r.npcRosterId).slice(0,8),16),area=pool[serial%pool.length],choice=npcPopulationChoice(data,area.band.min,serial,{map:area.map});
    initial[i]={...r,map:area.index,level:compatible.length?r.level:choice.level,activity:{kind:area.hub?'rest':'farm',source:'ENGINE-CHOSEN unbound metadata rehome to verified native start area'},levelSource:area.band.source};refreshed=true;
   }
  }
  if(refreshGeneratedNames===true){const used=new Set([...usedNames,...[...existingProfiles.values()].map(p=>p.name),...initial.map(r=>r.name)].map(fold));let serial=0;
   for(let i=0;i<initial.length;i++){const r=initial[i];if(r.binding||r.npcNameCustom||r.npcCustomName||r.npcNameSource==='generated-v2'||!npcLegacyGeneratedName(r.name))continue;
    const name=npcUsername(serial++,used);used.add(fold(name));initial[i]={...r,name,npcNameSource:'generated-v2'};refreshed=true;
   }
  }
  const next=grow(initial);if(refreshed||next.length!==saved.length)await persist(next);rows=next;
  loaded=true;await syncEarned(existingProfiles);return api;
 }
 // LANE1-PERF incremental roster sync. rows is never mutated in place (every
 // change reassigns it), so an index over the current rows array stays exact
 // until rows is reassigned. A read-only pass using that cached index handles
 // the common "nothing to change" sync; the first profile that would need a row
 // replacement aborts to the unchanged original algorithm (syncEarnedFull).
 // Profiles are still compared field-by-field every call (no profile-reference
 // caching). The unique-name check is skipped only for the exact rows array it
 // already passed on.
 let cachedIndex=null,cachedIndexRows=null,namesCheckedRows=null,mapRows=null,mapRowsFor=null;
 // Per-map row lists in roster order (exact first-match for candidate()).
 function rowsOnMap(map){if(mapRowsFor!==rows){mapRows=new Map();for(const r of rows){let list=mapRows.get(r.map);if(!list)mapRows.set(r.map,list=[]);list.push(r);}mapRowsFor=rows;}return mapRows.get(Number(map))||[];}const syncStats={calls:0,fast:0,full:0};
 function syncEarnedFast(profiles){
  if(cachedIndexRows!==rows){cachedIndex=createNpcEarnedRowIndex(rows.slice());cachedIndexRows=rows;}
  const keep=new Set();
  for(const[account,p]of profiles){if(!own(p)||!classes.has(p.classIndex))continue;const r=rows[cachedIndex.match(account,p)];
   if(!r)return null;
   if(r.binding&&r.binding.profileId!==p.id)throw Error('Roster identity already belongs to an earned profile');
   if(!earnedMetadataMatches(r,account,p)){
   const m=earnedMetadata(account,p),updated={...r,...m,binding:{account,profileId:p.id},levelSource:'actual earned profile'};delete updated.account;delete updated.profileId;
   if(JSON.stringify(updated)!==JSON.stringify(r))return null;}
   keep.add(r.npcRosterId);
  }
  if(namesCheckedRows!==rows){if(new Set(rows.map(r=>fold(r.name))).size!==rows.length)throw Error('Earned identity collides with simulated name');namesCheckedRows=rows;}
  for(const id of keep)held.delete(id);return api.summary();
 }
 async function syncEarned(profiles=existingProfiles){return queue(async()=>{syncStats.calls++;const fast=syncEarnedFast(profiles);if(fast){syncStats.fast++;return fast;}syncStats.full++;return syncEarnedFull(profiles);});}
 async function syncEarnedFull(profiles){const next=rows.slice(),index=createNpcEarnedRowIndex(next),released=new Set();let changed=false;for(const[account,p]of profiles){if(!own(p)||!classes.has(p.classIndex))continue;let at=index.match(account,p),r=next[at];
    if(!r){const publicId='r'+hash('earned:'+account+':'+p.id).slice(0,24);at=index.vacant(held);if(at<0)throw Error('Simulated roster cannot displace earned identities');r=index.replace(at,{npcRosterId:publicId});}
    if(r.binding&&r.binding.profileId!==p.id)throw Error('Roster identity already belongs to an earned profile');
    if(earnedMetadataMatches(r,account,p)){released.add(r.npcRosterId);continue;}
    const m=earnedMetadata(account,p),updated={...r,...m,binding:{account,profileId:p.id},levelSource:'actual earned profile'};delete updated.account;delete updated.profileId;
    if(JSON.stringify(updated)!==JSON.stringify(r)){index.replace(at,updated);changed=true;}released.add(r.npcRosterId);
   }if(new Set(next.map(r=>fold(r.name))).size!==next.length)throw Error('Earned identity collides with simulated name');if(changed){await persist(next);rows=next;}else namesCheckedRows=rows;for(const id of released)held.delete(id);return api.summary();}
 const api={load,syncEarned,syncStats:()=>({...syncStats}),
  page({map,offset=0,limit=MAX_PAGE,activeNames}={}){const filtered=rows.filter(r=>map===undefined||r.map===Number(map)),start=Number.isFinite(offset)?Math.max(0,Math.floor(offset)):0,size=Number.isFinite(limit)?Math.max(0,Math.min(MAX_PAGE,Math.floor(limit))):MAX_PAGE;return {kind:'simulated roster',total:filtered.length,offset:start,limit:size,rows:filtered.slice(start,start+size).map(r=>publicRow(r,activeNames))};},
  candidate(map,{classIndex,levelMin=1,levelMax=data.maxLevel,excludeNames=[]}={}){const excluded=new Set([...excludeNames].map(fold)),r=rowsOnMap(map).find(r=>!r.binding&&!held.has(r.npcRosterId)&&r.map===Number(map)&&byMap.has(r.map)&&(classIndex===undefined||r.classIndex===classIndex)&&r.level>=levelMin&&r.level<=levelMax&&!excluded.has(fold(r.name)));if(!r)return null;held.add(r.npcRosterId);return publicRow(r);},
  // Trusted server-only batch activation; retains the exact persistent identity.
  reserve(id){const r=rows.find(q=>q.npcRosterId===id);if(!r||r.binding||held.has(id)||!byMap.has(r.map))return null;held.add(id);return publicRow(r);},
  release(id){return held.delete(id);},
  async bind(id,metadata){return queue(async()=>{const r=rows.find(r=>r.npcRosterId===id);try{if(!r||r.binding||!held.has(id)||!metadata?.profileId||fold(metadata.name)!==fold(r.name)||metadata.classIndex!==r.classIndex||metadata.level!==r.level||metadata.map!==r.map)throw Error('Invalid normal activation binding');const next=structuredClone(rows),q=next.find(q=>q.npcRosterId===id);q.binding={profileId:metadata.profileId,...(metadata.account?{account:metadata.account}:{})};q.activity=metadata.activity?safeActivity(metadata):q.activity;q.traits=metadata.traits?safeTraits(metadata.traits):q.traits;q.levelSource='actual earned profile';await persist(next);rows=next;return publicRow(q);}finally{held.delete(id);}});},
  summary(){const maps=new Map();for(const r of rows)maps.set(r.map,(maps.get(r.map)||0)+1);return {kind:'simulated roster',identities:rows.length,bound:rows.filter(r=>r.binding).length,unbound:rows.filter(r=>!r.binding).length,reserved:held.size,unavailable:rows.filter(r=>!byMap.has(r.map)).length,connectionCounts:false,maps:[...maps].sort((a,b)=>a[0]-b[0]).map(([map,count])=>({map,count}))};},
  async flush(){await writes;},
 };
 await load();return api;
}
