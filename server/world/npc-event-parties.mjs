import {sameScene,mapFor} from './scene.mjs';
import {PARTY_MAX} from './party.mjs';
import {joinableWar} from './party-war.mjs';
import {npcTownServicePlan,npcTownPartyPlan} from './npc-town-layout.mjs';
import {npcEventWalkStage} from './npc-chain-fire-attendance.mjs';
import {partyWarWindow} from '../../src/systems/events/partywar-clock.js';
import {createNpcEventResourceBudget} from './npc-event-resource-budget.mjs';
import {createNpcChainFireAttendance} from './npc-chain-fire-attendance.mjs';

// ENGINE-CHOSEN NPC decisions only: full ordinary seven-member parties, stable
// willing/solo split, local host-clock interpretation, retry cadence and density.
// Native time/config, placed officers, level bands, ticket ownership, field team
// capacity are read without changing them. Host admission remains world.action.
const MODES=['deadFront','iceCastle'];
const dist=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const alive=p=>p&&!p.leaving&&!p.dead&&!p.sceneTransition&&!p.instanceId;
const inBand=(p,band)=>Array.isArray(band)&&p.profile.level>=Number(band[0])&&p.profile.level<=Number(band[1]);
const owns=(p,item)=>(p.profile.inventory||[]).some(i=>Number(i.itemIndex)===item&&Number(i.count||1)>0);
const willing=p=>{let h=0;for(const c of String(p.characterId||p.id))h=(h*31+c.charCodeAt(0))>>>0;return h%4!==0;};
// Keep native field capacity available for actual players even when bots apply first.
const npcTeamLimit=o=>Math.min(2,Math.max(0,o.maxParties-1));
// ENGINE-CHOSEN roles from actual OWNED native learned rows, never a class
// label that implies a character learned a heal/buff it does not own.
export function npcEventCapabilities(data,p){
 const result={heal:false,support:false,damage:false};for(const[id,level]of Object.entries(p.profile.skills||{})){const skill=data.skillPacks?.[p.profile.classIndex]?.skills?.[id],row=skill?.levels?.find(r=>Number(r.level)===Number(level));if(!row||row.reqLevel>p.profile.level)continue;for(const step of row.steps||skill.steps||[]){const r=step.result;if(!r)continue;const ally=!!(Number(skill.targetMask)&(2|32))||r.target==='party';if(ally&&['heal','heal_area','heal_party','resurrect'].includes(r.family))result.heal=true;if(ally&&['status','area_status_party'].includes(r.family)&&Number(data.skillStatuses?.[r.statusIndex]?.property)===1)result.support=true;if(['damage','remote','projectile','servant_explode'].includes(r.family))result.damage=true;}}
 return result;
}
export function npcEventTeamSelection(data,pool,count=PARTY_MAX,existing=[]){
 const chosen=[...existing],remaining=pool.filter(p=>!chosen.includes(p)),classes=new Set(chosen.map(p=>p.profile.classIndex)),roles=new Set(),capabilities=new Map([...chosen,...remaining].map(p=>[p,npcEventCapabilities(data,p)]));let healers=0;
 const note=p=>{const r=capabilities.get(p);if(r.heal)healers++;for(const[k,v]of Object.entries(r))if(v)roles.add(k);};chosen.forEach(note);
 while(remaining.length&&chosen.length<Math.min(PARTY_MAX,count)){
  // Prefer one real learned healer and varied offensive classes. Two healers
  // are enough for a newly formed crew; existing human/earned parties stay intact.
  const available=remaining.filter(p=>healers<2||!capabilities.get(p).heal);if(!available.length)break;
  const score=p=>{const r=capabilities.get(p);return (!roles.has('heal')&&r.heal?100:0)+(!roles.has('support')&&r.support?40:0)+(!roles.has('damage')&&r.damage?20:0)+(!classes.has(p.profile.classIndex)?10:0)+(r.damage?2:0);};
  available.sort((a,b)=>score(b)-score(a)||String(a.id).localeCompare(String(b.id)));const next=available[0];remaining.splice(remaining.indexOf(next),1);chosen.push(next);classes.add(next.profile.classIndex);note(next);
 }
 return chosen;
}
export function npcEventWindow(mode,now) {
 return partyWarWindow(mode,now);
}
export function npcEventOptions(world,anchor,now=world.now()) {
 if(!alive(anchor)||world.data.requiresInstance?.(anchor.map))return [];
 const data=world.data.eventData,out=[];
 for(const key of MODES){const mode=data?.modes?.[key],window=npcEventWindow(mode,now);if(!window)continue;
  const live=new Set((data.solo?.[key]?.liveMaps||[]).map(Number));
  for(const tier of mode.tiers||[])for(const row of tier.maps||[]) {
   const field=data.field(key,row.map),ticket=Number(field?.itemCode)||0;// field.csv ItemCode (Global: 0 => no admission item)
   if(!field||!row.officerPlaced||!live.has(Number(row.map))||!inBand(anchor,row.registrationLevel)||!inBand(anchor,field.entryLevel||row.entryLevel))continue;
   for(const npc of row.officers||[]){const officer=(mode.officers||[]).find(o=>Number(o.npc)===Number(npc));
    for(const at of officer?.placed||[])if(Number(at[0])===Number(anchor.map))out.push({mode:key,map:Number(row.map),npc:Number(npc),ticket,registrationLevel:row.registrationLevel,entryLevel:field.entryLevel||row.entryLevel,maxParties:Math.min(4,Math.max(1,Number(field.maxParties)||1)),window,at:{map:Number(at[0]),x:Number(at[1])+.5,z:Number(at[2])+.5},variant:row.variant});
   }
  }
 }
 // Prefer the native normal variant. Selection between overlapping native bands
 // is an NPC strategy, not an original service selection rule.
 return out.sort((a,b)=>(a.variant==='normal'?0:1)-(b.variant==='normal'?0:1)||a.map-b.map);
}
export function createNpcEventParties(world,{isNpc,act,move,eligible=willing,onError=()=>{},attendanceHooks=null}) {
 if(typeof isNpc!=='function'||typeof act!=='function')throw Error('NPC events require actor classification and ordinary action adapter.');
 const intents=new Map();let busy=false;
 const budget=createNpcEventResourceBudget(world),attendance=attendanceHooks&&createNpcChainFireAttendance(world,{act,move,onError,...attendanceHooks});
 const actor=id=>[...world.players.values()].find(p=>p.id===id&&!p.leaving);
 const humans=()=>[...world.players.values()].filter(p=>!isNpc(p)&&alive(p));
 const humanWar=(p,o)=>{if(!alive(p))return null;const war=o&&joinableWar(world,o.mode,o.map,p);return war&&[...world.players.values()].some(h=>!isNpc(h)&&!h.leaving&&!h.dead&&!h.sceneTransition&&h.instanceId===war.id)?war:null;};
 const anchored=(p,o)=>alive(p)&&(humans().some(h=>sameScene(h,p))||!!humanWar(p,o)||!!attendance?.retains(p));
 const permitted=(p,o)=>alive(p)&&inBand(p,o.registrationLevel)&&inBand(p,o.entryLevel)&&(!o.ticket||owns(p,o.ticket));
 const members=g=>(world.parties.get(g.partyId)?.members||[]).map(actor);
 const keyOf=(anchor,o)=>`${anchor.map}:${anchor.channel||0}:${o.mode}:${o.map}:${o.window.cycle}`;
 async function action(p,input){try{return await act(p,input);}catch(e){if(!e.status)throw e;onError(e,p);return null;}}
 async function form(anchor,o) {
  const key=keyOf(anchor,o),existing=[...intents.values()].filter(g=>g.key===key);if(existing.length>=npcTeamLimit(o))return;
  const selected=attendance?.teamFor(anchor);
  const previous=[...world.parties.values()].find(party=>!intents.has(party.id)&&party.members.length===PARTY_MAX&&party.members.every(id=>{const p=actor(id);return p&&(!selected||selected.includes(p))&&isNpc(p)&&eligible(p)&&sameScene(p,anchor)&&permitted(p,o);})&&actor(party.leader));
  if(previous){intents.set(previous.id,{key,partyId:previous.id,leaderId:previous.leader,option:o,next:0,registered:false,stage:'gather'});return;}
  const pool=[...world.players.values()].filter(p=>(selected?selected.includes(p):!attendance?.retains(p))&&isNpc(p)&&eligible(p)&&sameScene(p,anchor)&&permitted(p,o)&&!p.partyId&&!world.partyInvites?.has(p.id)).sort((a,b)=>String(a.id).localeCompare(String(b.id)));
  if(pool.length<PARTY_MAX)return;
  // ENGINE-CHOSEN courtesy window for a human to request the final ordinary
  // seat. Never hold it beyond 30 s before the native registration closes.
  const fillAt=Math.min(world.now()+60000,o.window.closed-30000),count=fillAt>world.now()?PARTY_MAX-1:PARTY_MAX,picked=npcEventTeamSelection(world.data,pool,count),leader=picked[0];
  if(picked.length!==count)return; // No partial native party from unavailable role composition.
  await action(leader,{type:'party',operation:'create'});if(!leader.partyId)return;
  for(const p of picked.slice(1)){if(!anchored(leader)||!sameScene(p,leader)||!permitted(p,o))return;await action(leader,{type:'party',operation:'invite',targetId:p.id});const invite=world.partyInvites?.get(p.id);if(invite?.party===leader.partyId)await action(p,{type:'party',operation:'accept'});}
  const party=world.parties.get(leader.partyId);if(party?.members.length!==count)return;
  intents.set(party.id,{key,partyId:party.id,leaderId:leader.id,option:o,next:0,fillAt,registered:false,stage:count<PARTY_MAX?'recruiting one open seat':'gather'});
 }
 async function advance(g,now) {
  const leader=actor(g.leaderId),o=g.option,party=world.parties.get(g.partyId),team=members(g);
  if(team.some(p=>p&&!isNpc(p))){intents.delete(g.partyId);return;}
  if(!party||party.leader!==g.leaderId||team.some(p=>!p)||now>=o.window.end){intents.delete(g.partyId);return;}
  if(leader.instanceId){intents.delete(g.partyId);return;}
  if(!anchored(leader,o)||team.some(p=>!sameScene(p,leader))){intents.delete(g.partyId);return;}
  if(now<g.next)return;
  if(team.some(p=>!permitted(p,o)))return;
  if(team.length<PARTY_MAX&&now>=(g.fillAt||0)&&now<o.window.closed){
   const humanInvite=[...(world.partyInvites||[])].some(([id,i])=>{const target=actor(id);return i.party===party.id&&i.expires>now&&target&&!isNpc(target);});
   if(!humanInvite){const selected=attendance?.teamFor(leader),pool=[...world.players.values()].filter(p=>(selected?selected.includes(p):!attendance?.retains(p))&&isNpc(p)&&eligible(p)&&sameScene(p,leader)&&permitted(p,o)&&!p.partyId&&!world.partyInvites?.has(p.id)),picked=npcEventTeamSelection(world.data,pool,PARTY_MAX,team);for(const p of picked.filter(p=>!team.includes(p))){await action(leader,{type:'party',operation:'invite',targetId:p.id});if(world.partyInvites?.get(p.id)?.party===party.id)await action(p,{type:'party',operation:'accept'});}}
  }
  // One native service approach for the leader; followers reserve distinct
  // reachable party positions, rather than all walking onto the officer.
  // These are ordinary movement goals, including genuine admitted DK lobbies.
  const row=world.data.progression?.npcs?.placements?.[leader.map]?.rows?.find(r=>Number(r[0])===o.npc),service=row?{map:leader.map,npc:o.npc,x:Number(row[1]),z:Number(row[2])}:null;
  const approach=service&&npcTownServicePlan(world,leader,service,{allowDk:true});
  if(approach&&!approach.near&&move){g.next=now+1000;await move(leader,approach.at);}
  for(const p of team)if(p!==leader&&isNpc(p)){
   if(!anchored(leader,o))return;
   const position=npcTownPartyPlan(world,p,leader,{allowDk:true});
   if(position&&!position.near&&move){g.next=now+1000;await move(p,position.at);}
   else if(!position&&attendance?.retains(p)&&dist(p,leader)>20&&!leader.path?.length&&move){
    // First gather through ordinary native walking; distinct final seats can
    // be selected once the distant member reaches its actual party leader.
    const at=npcEventWalkStage(mapFor(world,p),p,leader);
    if(at){g.next=now+1000;await move(p,at);}
   }
  }
  if(!anchored(leader,o)||team.some(p=>!permitted(p,o)||!sameScene(p,leader)))return;
  if(dist(leader,o.at)>8||team.some(p=>dist(p,leader)>20))return;
  if(team.length!==PARTY_MAX){g.stage='recruiting one open seat';return;}
  if(now>=o.window.register&&now<o.window.closed){if(!g.registered){g.next=now+1000;const result=await action(leader,{type:'event',operation:'record',map:o.map,npc:o.npc});if(result?.applied!==true){g.stage='application pending';return;}}g.registered=true;g.stage='applied';return;}
  if(!g.registered||now<o.window.enter||now>=o.window.end)return;
  // Existing human wars retain their ordinary path. Independent finite native
  // event attendance must reserve its exact team/geometry before host admission.
  let reservation;if(!humanWar(leader,o)){if(!attendance?.retains(leader))return;reservation=await budget.acquire(team,{map:o.map,until:o.window.end,instance:true,partyId:party.id,cycle:o.window.cycle,joinInstance:joinableWar(world,o.mode,o.map,leader)});if(!reservation){g.stage='waiting for event resources';return;}}
  g.next=now+1000;g.stage='entering';try{await action(leader,{type:'event',operation:'enter',map:o.map,npc:o.npc});}finally{reservation?.release();}
  if(leader.instanceId)intents.delete(g.partyId);
 }
 return {
  // Called by root's director, serially. No background timer or server restart.
  async tick(){if(busy)return;busy=true;try{await attendance?.tick();const now=world.now();for(const g of [...intents.values()])await advance(g,now);
   const seen=new Set();for(const h of [...humans(),...[...world.players.values()].filter(p=>attendance?.retains(p)&&alive(p))]){const o=npcEventOptions(world,h,now).find(o=>o.window.phase==='register');if(!o)continue;const selected=attendance?.teamFor(h),key=keyOf(h,o)+(selected?':'+selected[0].id:'');if(seen.has(key))continue;seen.add(key);await form(h,o);}
  }finally{busy=false;}},
  handles:p=>[...intents.values()].some(g=>world.parties.get(g.partyId)?.members.includes(p.id))||!!attendance?.handles(p),
  // Only pre-existing staged competitors may remain briefly in their lobby
  // while a human already entered a joinable war. This never permits spawning.
  retains:p=>!!attendance?.retains(p)||isNpc(p)&&alive(p)&&[...intents.values()].some(g=>g.registered&&world.now()>=g.option.window.enter&&world.now()<g.option.window.end&&world.parties.get(g.partyId)?.members.includes(p.id)&&permitted(p,g.option)&&!!humanWar(actor(g.leaderId),g.option)),
  snapshot:()=>[...intents.values()].map(g=>({partyId:g.partyId,leaderId:g.leaderId,mode:g.option.mode,map:g.option.map,npc:g.option.npc,stage:g.stage,registered:g.registered,enterAt:g.option.window.enter,closesAt:g.option.window.end})),
  densityFor(anchor){const o=npcEventOptions(world,anchor).find(o=>o.window.phase==='register');return o?npcTeamLimit(o)*PARTY_MAX:0;},
  attendance:()=>attendance?.snapshot()||[],
  attending:p=>!!attendance?.handles(p),
  dispose(){attendance?.dispose();budget.dispose();intents.clear();},
 };
}
