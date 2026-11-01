import {npcNativeActivities,npcLevelBand} from './npc-builds.mjs';
const residentBands=new WeakMap();
const residentActivities=new WeakMap();
function nativeResidentActivities(data,map){let cache=residentActivities.get(data);if(!cache){cache=new Map();residentActivities.set(data,cache);}if(!cache.has(map))cache.set(map,npcNativeActivities(data,map));return cache.get(map);}
export function nativeResidentBand(data,map){let cache=residentBands.get(data);if(!cache){cache=new Map();residentBands.set(data,cache);}if(!cache.has(map)){const monsters=new Map((data.spawns?.(map)||[]).map(s=>[s.id,{...s,def:data.monsterDef?.(s.monsterIndex)}]));cache.set(map,npcLevelBand(data,{map:{index:map,monsters}}));}return cache.get(map);}
// ENGINE-CHOSEN cohort reuse. Preserve earned characters; select appropriate
// residents instead of changing saved levels/equipment to fit a new map.
export function npcResidentHasAcceptedWork(data,profile){
 const quests=data.progression?.quests?.quests||{};
 return Object.keys(profile.quests?.active||{}).some(id=>quests[id]&&!quests[id].isGroup&&!quests[id].hidden);
}
export function npcResidentMatches(data,profile,anchor,choice){
 if(Number(profile.map)!==Number(anchor.map)||(profile.channel??profile.npcSeed?.channel??0)!==(anchor.channel||0)||profile.instance)return false;
 const row=data.mapRow?.(anchor.map),level=Number(profile.level),min=Math.max(1,Number(row?.LimitMinLevel)||1),max=Number(row?.LimitMaxLevel)||data.maxLevel;
 if(!Number.isFinite(level)||level<min||level>max)return false;
 const home=profile.npcSeed?.homeMap??profile.npcSeed?.map;
 // Actual native travellers may retain a higher/lower earned level than the
 // resident farming cohort, subject to ordinary map admission.
 if(home!=null&&Number(home)!==Number(profile.map))return true;
 // Existing earned quest-log intent takes priority over a newly sampled seed
 // goal. The ordinary join/quest engine still validates resets and objectives.
 if(npcResidentHasAcceptedWork(data,profile))return true;
 const wanted=choice.goal,saved=profile.npcSeed?.initialGoal;
 // Durable native intent is eligibility, not a new random cohort preference.
 // Revalidate its actual offered catalog/officer/route/level band before reuse.
 // Birth preferences have only kind/map. They establish ordinary town residency,
 // never revive an expired routine or authorize a scripted objective.
 if(saved&&['merchant','rest'].includes(saved.kind))return saved.map===Number(profile.map)&&
  Object.keys(saved).every(k=>k==='kind'||k==='map')&&Number(row?.PeaceZone)===1&&Number(row?.PcStore)===1&&
  !data.requiresInstance?.(Number(profile.map))&&!data.eventData?.modeOf?.(Number(profile.map))&&!Number(row?.IsSiege)&&
  !!data.progression?.npcs?.placements?.[Number(profile.map)]?.rows?.some(r=>r[1]!==null&&r[1]!==''&&r[2]!==null&&r[2]!==''&&Number.isFinite(Number(r[1]))&&Number.isFinite(Number(r[2])));
 if(saved){const quest=data.progression?.quests?.quests?.[saved.questId],localQuest=saved.kind==='quest'&&(saved.officer===undefined||saved.officerMap===undefined)&&saved.map===Number(profile.map)&&Number(quest?.giver?.map)===Number(profile.map);
  const actual=nativeResidentActivities(data,Number(profile.map)).find(g=>g.kind===saved.kind&&(g.questId??g.eventId)===(saved.questId??saved.eventId)&&(g.officer===saved.officer&&g.officerMap===saved.officerMap||localQuest&&g.officerMap===Number(profile.map)&&g.officer===Number(quest.giver.npc)&&(saved.officer===undefined||saved.officer===g.officer)&&(saved.officerMap===undefined||saved.officerMap===g.officerMap)));
  return !!actual&&level>=actual.levels[0]&&level<=actual.levels[1];
 }
 const durableBand=profile.npcSeed?.levelBand,actualBand=nativeResidentBand(data,Number(profile.map));
 if(durableBand&&Number(durableBand.map)===Number(profile.map)&&actualBand&&level>=actualBand.min&&level<=actualBand.max)return true;
 if(wanted){
  if(saved?.kind!==wanted.kind||saved.questId!==wanted.questId||saved.eventId!==wanted.eventId)return false;
  return level>=Number(wanted.levels?.[0]||1)&&level<=Number(wanted.levels?.[1]||data.maxLevel);
 }
 if(saved)return false;
 const band=choice.levelBand;return !band||level>=band.min&&level<=band.max;
}

export function npcReusableResidents({data,profiles,players,anchor,choice,slot,candidates=profiles}){
 return [...candidates].filter(([id,p])=>!players.has(id)&&p.npcSeed?.stock&&npcResidentMatches(data,p,anchor,choice)).sort((a,b)=>
  Number(npcResidentHasAcceptedWork(data,b[1]))-Number(npcResidentHasAcceptedWork(data,a[1]))||
  Number(b[1].classIndex===choice.classIndex)-Number(a[1].classIndex===choice.classIndex)||
  Number(b[1].npcTraits?.gear===choice.traits?.gear)-Number(a[1].npcTraits?.gear===choice.traits?.gear)||
  Number(b[1].npcSeed?.slot===slot)-Number(a[1].npcSeed?.slot===slot));
}
