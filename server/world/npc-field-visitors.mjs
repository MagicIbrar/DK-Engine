import {sceneKey} from './scene.mjs';
import {findWorldPlayer} from './actor-lookup.mjs';
import {isDkChannel} from './channels.mjs';
import {npcTownServicePlan,npcTownMayPark} from './npc-town-layout.mjs';
import {npcRetainedCityBirthSeat} from './npc-city-birth-seat.mjs';

// ENGINE-CHOSEN online visitor diversity, not names/levels changed on saved
// characters or simulated offline progress. All joins/leaves stay ordinary.
export const NPC_FIELD_VISITOR_POLICY=Object.freeze({familiar:2,absenceMs:1500,maxScenes:128});
export function npcOccupiedField(world,p,isHuman){return !!(p&&isHuman(p)&&!p.dead&&!p.sceneTransition&&!p.instanceId&&!isDkChannel(p.channel)&&!world.data.requiresInstance?.(p.map)&&!world.data.eventData?.modeOf?.(p.map)&&!Number(world.data.mapRow?.(p.map)?.IsSiege));}
export function npcFieldCohortEligible(data,profile,anchor,choice,{friends=new Set()}={}){
 const row=data.mapRow?.(anchor.map),band=choice.levelBand;
 // Native towns host legitimate veteran services. Familiar human friends may
 // retain their earned levels under the existing native admission validator.
 if(Number(row?.PeaceZone)===1&&Number(row?.PcStore)===1||friends.has(String(profile.name).toLowerCase()))return true;
 return !band||Number(profile.level)>=band.min&&Number(profile.level)<=band.max;
}
// A brief, distinct resting approach to a genuine town service. The director
// must walk normally; this is not a service transaction or a saved relocation.
export function npcTownIdlePlan({world,player:p,brain:b,isHuman,approach=npcTownServicePlan}){
 const row=world.data.mapRow?.(p?.map),end=p?.path?.at(-1),ownWalk=end&&b?.idleTownPlan?.at?.map===p.map&&Math.hypot(end.x-b.idleTownPlan.at.x,end.z-b.idleTownPlan.at.z)<=1;
 if(!p||!b||Number(row?.PeaceZone)!==1||Number(row?.PcStore)!==1||!npcTownMayPark(world,p)||b.mode==='wait'||p.path?.length&&!ownWalk||b.questId||Object.keys(p.profile.quests?.active||{}).length||!['taking a short break','looking for an available objective'].includes(b.activity)||npcFieldVisitorProtected(world,p,b,{isHuman}))return null;
 const born=npcRetainedCityBirthSeat(world,p);if(born)return born;
 const catalog=world.data.progression?.npcs,services=(catalog?.placements?.[p.map]?.rows||[]).filter(([id,x,z])=>[x,z].every(Number.isFinite)&&catalog.npcs?.[id]?.jobs?.some(([type])=>[2,4,13,16,42,96,102].includes(Number(type))));
 if(!services.length)return null;let hash=2166136261;for(const c of p.account)hash=Math.imul(hash^c.charCodeAt(0),16777619)>>>0;
 const choice=b.idleTownChoice?.map===p.map?b.idleTownChoice:{map:p.map,cursor:0,retry:0};b.idleTownChoice=choice;if(world.now()<choice.retry)return null;
 const [npc,x,z]=services[(hash+choice.cursor)%services.length],plan=approach(world,p,{map:p.map,npc:Number(npc),x,z});if(!plan){choice.cursor=(choice.cursor+1)%services.length;choice.retry=world.now()+2000;return null;}return {...plan,source:{kind:'rest',npc:Number(npc),placement:'native useful town service',policy:'ENGINE-CHOSEN distinct brief rest; no service/reward claim'}};
}
export function npcFieldVisitorProtected(world,p,brain,{isHuman,talking=new Set(),eventRetains=()=>false}={}){
 const actor=id=>findWorldPlayer(world,id),party=world.parties.get(p.partyId),leader=actor(brain.follow),invite=world.partyInvites.get(p.id),inviter=invite&&invite.expires>world.now()&&actor(world.parties.get(invite.party)?.leader);
 if(p.instanceId||eventRetains(p)||leader&&isHuman(leader)||party?.members.some(id=>isHuman(actor(id)))||inviter&&isHuman(inviter))return true;
 if(p.dead||p.pcShopOpen||p.tradeId||p.commandActive||p.progressCommitting||p.sceneTransition||brain.objectiveFlight||brain.refineRestore||p.profile.npcEquipment?.phase==='working')return true;
 if(p._skills?.engine.casting)return true;
 if(talking.has(p.id)||brain.queue?.some(m=>Number(m.at)<=world.now()&&world.now()-Number(m.at)<=20000)||world.now()<Number(brain.chatReady||0))return true;
 return [...(world.maps.get(sceneKey(p.map,p.instanceId,p.channel))?.monsters?.values()||[])].some(m=>!m.dead&&(m.targetId===p.id||m.id===p.attackTarget)&&Math.hypot(m.x-p.x,m.z-p.z)<15);
}
export function createNpcFieldVisitors(now,options={}){
 const policy={...NPC_FIELD_VISITOR_POLICY,...options},scenes=new Map(),absent=new Map();
 const get=key=>{let s=scenes.get(key);if(!s){if(scenes.size>=policy.maxScenes){const old=[...scenes].find(([,v])=>!v.present);if(old)scenes.delete(old[0]);else return null;}s={visit:0,present:false,familiar:[],current:new Set(),previous:new Set()};scenes.set(key,s);}return s;};
 return{
  observe(keys){const active=new Set(keys);for(const[key,s]of scenes)if(!active.has(key))s.present=false;for(const key of active){const s=get(key);if(!s)continue;if(!s.present){s.previous=new Set(s.current);s.current.clear();s.visit++;s.present=true;}}},
  select(key,{candidates=[],friends=new Set(),canCreate=true,slot=0}={}){const s=get(key);if(!s)return candidates[0]||null;const friend=candidates.find(([,p])=>friends.has(String(p.name).toLowerCase()));if(friend)return friend;if(s.visit<2)return candidates[0]||null;
   const familiar=candidates.find(([id])=>s.familiar.includes(id));if(familiar)return familiar;const fresh=candidates.find(([id])=>!s.previous.has(id));if(fresh)return fresh;
   if(canCreate)return null;return candidates.length?candidates[(s.visit+Math.max(0,slot))%candidates.length]:null;
  },
  joined(key,account){const s=get(key);if(s){s.current.add(account);if(s.familiar.length<Math.max(0,Math.min(2,policy.familiar))&&!s.familiar.includes(account))s.familiar.push(account);}absent.delete(account);},
  retirement(account,{present=false,protected:protectedActor=false}={}){if(present||protectedActor){absent.delete(account);return false;}if(!absent.has(account))absent.set(account,now());return now()-absent.get(account)>=Math.max(0,policy.absenceMs);},
  forget(account){absent.delete(account);},
  clear(){scenes.clear();absent.clear();},
  snapshot(){return{policy:'ENGINE-CHOSEN',scenes:scenes.size,familiar:policy.familiar,absenceMs:policy.absenceMs};},
 };
}
