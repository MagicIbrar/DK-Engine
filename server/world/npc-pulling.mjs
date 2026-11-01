import {sameScene,mapFor} from './scene.mjs';
import {npcReachableApproach} from './npc-navigation.mjs';
import {npcDungeonObjectivePlan} from './npc-dungeon-objectives.mjs';
import {npcEventObjectivePlan} from './npc-event-objectives.mjs';

// ENGINE-CHOSEN conservative team tactics over ordinary native movement and
// attack authority. This planner does not deal damage, create aggro or send chat.
export const NPC_PULL_POLICY=Object.freeze({limits:{novice:1,regular:2,expert:3,elite:4},scan:6,range:25,teamDistance:18,returnDistance:4,maxDuration:20000,calloutMs:15000});
const calls=new WeakMap(),distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z),npc=p=>p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile?.authority==='server';
const ratio=(current,max)=>Number(max)>0?Math.max(0,Number(current)||0)/Number(max):1;
const alive=p=>p&&!p.leaving&&!p.dead&&!p.sceneTransition;
const scene=p=>[p.map,p.instanceId||'',p.channel||0].join(':');
function roster(world,p){const party=world.parties?.get(p.partyId);if(!party?.members?.includes(p.id))return null;const members=party.members.map(id=>[...world.players.values()].find(q=>q.id===id&&!q.leaving)).filter(Boolean);return {party,members};}
function callout(world,p,crew,reason,text,now){
 const coordinator=crew.members.filter(q=>npc(q)&&alive(q)&&sameScene(q,p)).sort((a,b)=>a.id.localeCompare(b.id))[0];if(coordinator!==p)return null;
 let entries=calls.get(world);if(!entries){entries=new Map();calls.set(world,entries);}const key=crew.party.id??p.partyId,last=entries.get(key);if(last&&now-last.at<NPC_PULL_POLICY.calloutMs)return null;
 if(entries.size>128)entries.delete(entries.keys().next().value);entries.set(key,{at:now,reason});return {channel:'party',partyId:p.partyId,text,reason};
}
/** Root executes `at` with ordinary move, `targetId` with existing combat,
 * `prepare` with ordinary useful support, and revalidates callout.partyId before
 * ordinary party chat. A returned plan never grants native admission or aggro.
 */
export function npcPullPlan({world,player:p,brain:b={},leader,now=world?.now?.()??0}={}){
 if(!world||!npc(p)||b.mode!=='lure')return null;
 if(!alive(p)||p.commandActive||p.progressCommitting||p.tradeCommitting||p._skills?.engine.casting||b.objectiveFlight)return {handled:true,stage:'finishing the current native action',blockedReason:'native-action'};
 if(p.instanceId){const run=world.instances?.get(p.instanceId),ownedChannel=run?.channels?.some(c=>c.p===p&&Number(c.end)>now),goal=run?.kind==='dungeon'?npcDungeonObjectivePlan(world,p):npcEventObjectivePlan(world,p);if(ownedChannel||!goal?.targetId)return {handled:true,stage:goal?.stage||'waiting for the native objective',blockedReason:'native-objective-priority'};}
 const crew=roster(world,p),liveLeader=leader&&world.players.get(leader.account)===leader;
 if(!crew||!liveLeader||!crew.party.members.includes(leader.id)||!alive(leader)||!sameScene(p,leader)||!crew.members.some(q=>!npc(q)&&alive(q)&&sameScene(q,p))){delete b.pull;return {handled:true,stage:'waiting for the actual party',blockedReason:'actual-human-party'};}
 const map=mapFor(world,p);if(!map){delete b.pull;return null;}
 const key=[p.partyId,scene(p),leader.id].join('|');if(b.pull?.key!==key)b.pull={key,stage:'prepare',started:now,selected:[],captured:[]};const state=b.pull;
 const members=crew.members.filter(q=>sameScene(q,p)),ids=new Set(members.map(q=>q.id));
 const threats=[...map.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&!m.eventObject&&ids.has(m.targetId)&&distance(m,leader)<30);
 const lowHp=members.find(q=>!q.dead&&ratio(q.hp,q.maxHp)<.3),lowMp=members.find(q=>alive(q)&&Number(q.stats?.maxMp)>0&&ratio(q.mp,q.stats.maxMp)<.1),missing=crew.members.some(q=>!alive(q)||!sameScene(q,p)||distance(q,leader)>NPC_PULL_POLICY.teamDistance);
 const ownHp=ratio(p.hp,p.maxHp),ownMp=ratio(p.mp,p.stats?.maxMp),tier=p.profile.npcTraits?.pvpSkill||'regular';
 let limit=NPC_PULL_POLICY.limits[tier]||1;if(ownHp<.65||ownMp<.35||members.some(q=>ratio(q.hp,q.maxHp)<.65))limit=1;
 state.captured=state.selected.filter(id=>{const m=map.monsters.get(id);return m&&!m.dead&&m.targetId===p.id;});
 const unsafe=lowHp?'health':lowMp?'mana':missing?'regroup':distance(p,leader)>30?'distance':null;
 if(unsafe||threats.length>=limit||now-state.started>=NPC_PULL_POLICY.maxDuration)state.stage='return';
 if(unsafe){const text=unsafe==='mana'?'Wait for mana before the next pull.':unsafe==='health'?'Regroup; a teammate is low on health.':'Get back together before the next pull.';const plan={handled:true,stage:'regrouping with the party',at:{x:leader.x,z:leader.z},callout:callout(world,p,crew,unsafe,text,now)};if(distance(p,leader)<=NPC_PULL_POLICY.returnDistance)delete plan.at;return plan;}
 if(state.stage==='return'){
  if(distance(p,leader)>NPC_PULL_POLICY.returnDistance)return {handled:true,stage:'bringing the pull back to the party',at:{x:leader.x,z:leader.z}};
  const captured=state.captured.map(id=>map.monsters.get(id)).filter(m=>m&&!m.dead),arrived=captured.every(m=>distance(m,leader)<=10);
  if(!arrived)return {handled:true,stage:'waiting for the pull to reach the party'};
  delete b.pull;return {handled:true,stage:'regrouped with the party',complete:true,targetId:captured[0]?.id};
 }
 if(state.stage==='prepare'){
  if(distance(p,leader)>NPC_PULL_POLICY.returnDistance)return {handled:true,stage:'regrouping before the pull',at:{x:leader.x,z:leader.z}};
  state.stage='select';return {handled:true,stage:'preparing for a careful pull',prepare:true};
 }
 // Do not count a issued attack as successful aggro. The actual native targetId
 // on a later world tick must identify this actor before expanding the pack.
 const pending=state.selected.find(id=>{const m=map.monsters.get(id);return m&&!m.dead&&!state.captured.includes(id);});
 if(pending){const m=map.monsters.get(pending);if(m.targetId&&!ids.has(m.targetId)){state.selected=state.selected.filter(id=>id!==pending);return {handled:true,stage:'leaving another group\'s enemy alone'};}return {handled:true,stage:'drawing an enemy toward the party',targetId:pending};}
 if(state.captured.length>=limit){state.stage='return';return {handled:true,stage:'returning with the pull',at:{x:leader.x,z:leader.z}};}
 const candidates=[...map.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&Number(m.def.exp)>0&&!state.selected.includes(m.id)&&(!m.targetId||m.targetId===p.id)&&Math.abs(Number(m.def.level)-Number(p.profile.level))<=8&&(limit===1||Number(m.def.level)<=Number(p.profile.level)+3)&&distance(m,leader)<=NPC_PULL_POLICY.range&&distance(m,p)<=NPC_PULL_POLICY.range).sort((a,b)=>distance(p,a)-distance(p,b)).slice(0,NPC_PULL_POLICY.scan);
 const reach=Math.min(8,Number(p.stats?.attackRange)||5),pick=candidates.find(m=>npcReachableApproach(map,p,m,reach));
 if(!pick){state.stage='return';return {handled:true,stage:'returning after checking the nearby enemies',at:distance(p,leader)>NPC_PULL_POLICY.returnDistance?{x:leader.x,z:leader.z}:undefined,complete:distance(p,leader)<=NPC_PULL_POLICY.returnDistance};}
 state.selected.push(pick.id);return {handled:true,stage:'drawing an enemy toward the party',targetId:pick.id};
}
