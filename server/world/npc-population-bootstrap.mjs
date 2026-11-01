import {randomUUID} from 'node:crypto';
import {setImmediate as yieldTurn} from 'node:timers/promises';
import {npcPointBudget,seedNpcStartingStock} from './npc-builds.mjs';
import {NPC_PROFILE_LIMIT} from './npc-profiles.mjs';
import {prepareNewNpcEquipment} from './npc-initial-readiness.mjs';
import {prepareNewNpcSkills} from './npc-initial-skills.mjs';
import {staminaState} from '../../src/systems/hud-options/stamina-rules.js';
import {npcCityBirthSeat} from './npc-city-birth-seat.mjs';
import {seedNpcCityMarketBirth} from './npc-city-market-birth.mjs';

// ENGINE-CHOSEN new simulated-character starting cohort. No earned progress,
// money or rewards are inferred from directory intentions. Geometry is read
// through the native collision table; all subsequent actions are ordinary.
export function nativeNpcInitialProfile(data,map,identity,{serial=0,now=Date.now,random=Math.random}={}){
 const index=Number(identity.map),level=Number(identity.level),ci=Number(identity.classIndex),row=data.mapRow(index),cls=data.classDef(ci);
 if(!Number.isInteger(index)||!Number.isInteger(ci)||Number(map?.index)!==index||!row||!cls||!['str','dex','con','spr'].every(k=>Number.isFinite(cls.stats?.base?.[k])&&cls.stats.base[k]>=0)||!Number.isInteger(level)||level<Math.max(1,Number(row.LimitMinLevel)||1)||level>Math.min(data.maxLevel,Number(row.LimitMaxLevel)||data.maxLevel)||data.requiresInstance(index)||data.eventData?.modeOf?.(index)||Number(row.IsSiege)||!/^r[a-f0-9]{24}$/.test(identity.npcRosterId)||typeof identity.name!=='string'||!identity.name.trim()||!map?.isWalkable)throw Error('Native public NPC initial cohort unavailable');
 const q=identity.activity?.kind==='quest'&&data.progression?.quests?.quests?.[identity.activity.questId],placed=data.progression?.npcs?.placements?.[index]?.rows||[],giver=q&&Number(q.giver?.map)===index&&placed.find(r=>Number(r[0])===Number(q.giver.npc)),spawns=(data.spawns(index)||[]).map(s=>({...s,def:data.monsterDef(s.monsterIndex)})).filter(s=>s.def?.role==='creature'&&!s.def.boss&&Number(s.def.exp)>0&&Math.abs(Number(s.def.level)-level)<=12),anchors=[];
 if(giver)anchors.push({x:Number(giver[1]),z:Number(giver[2]),kind:'native placed quest giver'});
 if(spawns.length){const offset=serial%spawns.length;for(let n=0;n<spawns.length;n++){const s=spawns[(offset+n)%spawns.length];anchors.push({x:s.x,z:s.z,kind:'native ordinary creature spawn'});}}
 if(!anchors.length)for(const r of placed)if(data.progression.npcs.npcs?.[r[0]]?.jobs?.some(([type])=>[2,4,13,16,42,96,102].includes(Number(type))))anchors.push({x:Number(r[1]),z:Number(r[2]),kind:'native placed public service'});
 const citySeat=npcCityBirthSeat(data,map,identity);let at=citySeat?.at,source=citySeat?'native placed quiet city birth seat':null;for(const anchor of anchors){if(at)break;for(let n=0;n<12;n++){const angle=(serial+n)*2.399963229728653,radius=anchor.kind.includes('creature')?6+serial%9:9+serial%7,p={x:anchor.x+Math.cos(angle)*radius,z:anchor.z+Math.sin(angle)*radius};if(map.isWalkable(p.x,p.z)){at=p;source=anchor.kind;break;}}if(at)break;}
 if(!at)throw Error('No verified native start for this NPC cohort');
 const profile={id:'c'+randomUUID().replaceAll('-',''),authority:'server',npcPlayer:true,npcRosterId:identity.npcRosterId,...(['generated-v1','generated-v2'].includes(identity.npcNameSource)?{npcNameSource:identity.npcNameSource}:{}),name:identity.name,nameColor:'white',classIndex:ci,className:cls.name,level,exp:0,dil:0,...npcPointBudget(data,level),stats:structuredClone(cls.stats.base),hp:null,mp:null,map:index,pos:{x:at.x,z:at.z,dirDeg:0},inventory:[],equipment:{},hotbar:[],skills:{},starterSkillPending:true,created:now(),lastPlayed:now(),kills:0,deaths:0,playSeconds:0,npcTraits:structuredClone(identity.traits),npcSeed:{map:index,homeMap:index,channel:0,slot:serial,birthSlot:serial,initialPlacement:{policy:'ENGINE-CHOSEN cohort start; native collision checked',source},...(q?{initialGoal:{kind:'quest',questId:Number(q.id),map:index}}:Number(row.PeaceZone)===1&&Number(row.PcStore)===1&&['merchant','rest'].includes(identity.activity?.kind)?{initialGoal:{kind:identity.activity.kind,map:index}}:{})},npcLongTermGoal:{version:1,policy:'ENGINE-CHOSEN objective; ordinary native earned progress',kind:'progress',targetLevel:data.maxLevel}};
 if(citySeat)profile.npcSeed.initialTownSeat=structuredClone(citySeat);
 seedNpcStartingStock(profile,data,{serial,now,random,traits:profile.npcTraits});
 const ready=prepareNewNpcEquipment(profile,data,{newUnpersistedProfile:true}),bornAt=Number(now());
 if(!Number.isFinite(bornAt))throw Error('A finite native birth clock is required');
 // ENGINE-CHOSEN new-profile construction using ordinary daily stamina state;
 // no earned progress and no repeated initialization of an existing profile.
 staminaState(ready,bornAt);
 seedNpcCityMarketBirth(ready,data,{newUnpersistedProfile:true,serial,now,random});return ready;
}

/** First-world preparation, before human admission. Makes actual canonical
 * characters in bounded atomic batches; does not join2500 actors or earn XP. */
export async function prepareNpcPopulation({world,profiles,roster,enabled=()=>true,onProgress=()=>{},allowOccupied=false}={}){
 if(typeof allowOccupied!=='boolean'||!world||!(profiles?.profiles instanceof Map)||!roster?.reserve||!profiles.addBatch||!allowOccupied&&world.players.size)throw Error('NPC population preparation requires an empty native world');
 await profiles.load();await roster.syncEarned(profiles.profiles);const rows=[];for(let offset=0;;offset+=100){const page=roster.page({offset,limit:100});rows.push(...page.rows);if(offset+100>=page.total)break;}
 const byMap=new Map();for(const r of rows)if(!r.bound){if(!byMap.has(r.map))byMap.set(r.map,[]);byMap.get(r.map).push(r);}
 const report={canonicalBefore:profiles.profiles.size,created:0,unavailable:[],geometryReleased:0,geometryPinned:0,logicalProgress:false};let serial=profiles.profiles.size;
 for(const[index,candidates]of byMap){if(!enabled()||profiles.profiles.size>=NPC_PROFILE_LIMIT)break;if(!allowOccupied&&world.players.size)throw Error('Human admission started during NPC preparation');
  const owner={},editor=world.originalMapEdits,editorPinned=editor&&(!Array.isArray(editor.allowedMaps)||editor.allowedMaps.includes(Number(index)));world.data.retainMap?.(Number(index),owner);
  try{const native=await world.data.map(Number(index));let pending=[];
   const flush=async()=>{if(!pending.length)return;const batch=pending;pending=[];try{if(!allowOccupied&&world.players.size)throw Error('Human admission started during NPC preparation');const prepared=[];
    for(const row of batch){
     if(!enabled()||!allowOccupied&&world.players.size)throw Error('NPC initial learning preparation cancelled');
     prepared.push(prepareNewNpcSkills(row.profile,world,{newUnpersistedProfile:true}));
     // Bound main-thread work to one fresh profile between event-loop turns.
     await yieldTurn();
    }
    if(!enabled()||!allowOccupied&&world.players.size)throw Error('NPC initial learning preparation cancelled');
    const added=await profiles.addBatch(prepared),committed=new Map();for(const{account}of added){const profile=profiles.profiles.get(account);if(!profile)throw Error('Committed NPC bootstrap cache unavailable');committed.set(account,profile);}await roster.syncEarned(committed);report.created+=added.length;}finally{for(const r of batch)roster.release(r.identity.npcRosterId);}onProgress({...report});await yieldTurn();};
   for(const candidate of candidates){if(!enabled()||profiles.profiles.size+pending.length>=NPC_PROFILE_LIMIT)break;const identity=roster.reserve(candidate.npcRosterId);if(!identity)continue;try{pending.push({identity,profile:nativeNpcInitialProfile(world.data,native,identity,{serial:serial++,now:world.now,random:world.random})});}catch(error){roster.release(identity.npcRosterId);report.unavailable.push({map:index,npcRosterId:identity.npcRosterId,reason:error.message});}if(pending.length>=64)await flush();}await flush();
  }finally{try{if(!editorPinned&&world.data.releaseMap?.(Number(index),{owner})===true)report.geometryReleased++;else report.geometryPinned++;}finally{world.data.releaseMapReference?.(Number(index),owner);}}
 }
 await roster.syncEarned(profiles.profiles);await profiles.flush();await roster.flush();return {...report,canonicalProfiles:profiles.profiles.size,complete:profiles.profiles.size===Math.min(NPC_PROFILE_LIMIT,rows.length)};
}

