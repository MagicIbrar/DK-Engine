import {correctedMapInfo} from '../../src/systems/dungeons/native-row-corrections.js';
import {mapFor} from './scene.mjs';
import {objectHitPoint} from './object-combat.mjs';
import {nativeShipwreckNextFloor} from '../../src/systems/dungeons/director.js';
// ENGINE-CHOSEN NPC strategy over the existing host Director, not recovered
// original server puzzle/AI code. Require the actual native-backed host plan;
// borrowed/synthesized/unknown plans do not become NPC objectives.
// Historical initial reference-proven maps, retained for earlier scoped audit tooling.
export const NPC_DUNGEON_OBJECTIVE_MAPS=Object.freeze([25,32,33]);
export function npcDungeonObjectiveSupport(world,i){
 const d=i?.director,authored=world.data?.dungeonData?.dg?.maps?.[i?.map];
 if(!authored||d?.info!==correctedMapInfo(i.map,authored)||Number(d.map)!==Number(i.map))return{supported:false,reason:'No current native dungeon catalog/map binding.'};
 if(d.plan&&d.plan.name!=='inferred'||d.foreignWaves||d.borrowedFrom||d.synthesized||(d.stages||[]).some(s=>s.synth||s.foreign))return{supported:false,reason:'Borrowed, synthesized or unknown dungeon host plan.'};
 if(!['boss','all-waves','all-static'].includes(d.clearDef?.kind))return{supported:false,reason:'No compatible explicit dungeon host clear condition.'};
 const nativeInputs=!!((authored.waves?.length&&authored.files?.calls)||(authored.static?.rows?.length&&authored.files?.monsters)||(authored.scriptSpawns?.length&&authored.files?.npcs));
 if(!nativeInputs)return{supported:false,reason:'No own authored dungeon call/static/script-monster input.'};
 return{supported:true,reason:null};
}
function menuPath(d,sn){
 const path=[0];let code=d.messages?.[String(sn.dialog)]?.m?.[0],seen=new Set();
 while(code!=null){if(seen.has(code))return null;seen.add(code);const m=d.messages?.[String(code)],label=String(m?.t||'').replace(/<[^>]*>/g,'').trim();
  // The host's first non-gauge leaf dispatches the inferred NPC role. Do not
  // turn an authored exit/refusal/wait option into a summon or lever action.
  if(/\b(?:exit|leave|cancel|go back|more time)\b|^(?:no\b|wait\b|not now\b|return\b)/i.test(label))return null;
  if(!m?.m?.length||(m.fx||[]).some(f=>f.gauge))return path;
  if(path.length>=4)return null;path.push(0);code=m.m[0];
 }
 return path;
}
function nextFloorNpc(world,i,d,sn){
 const native=world.data.dungeonData.dg.dungeons?.[d.dungeonId],floors=native?.floors;
 if(sn.role!=='warp'||!floors||Number(floors[d.floor])!==Number(i.map)||!floors[d.floor+1]||d.dungeon!==native)return false;
 if(nativeShipwreckNextFloor(d,sn))return true;
 const text=String(sn.name||'')+' '+String(sn.label||'');
 if(!/next|floor|stairs|\dF\b|move to the/i.test(text)&&String(sn.job?.[1])!=='6')return false;
 const nextName=world.data.dungeonData.dg.maps?.[floors[d.floor+1]]?.name;
 if(nextName&&String(sn.name||'').trim().toLowerCase()===String(nextName).trim().toLowerCase())return true;
 if(/\bnext\b/i.test(text))return true;
 const numeric=/(\d+)(?:st|nd|rd|th)?\s*(?:floor|F\b)/i.exec(text),word=/\b(first|second|third|fourth|fifth|sixth)\s+floor\b/i.exec(text);
 const ordinal=numeric?Number(numeric[1]):word?['first','second','third','fourth','fifth','sixth'].indexOf(word[1].toLowerCase())+1:null;
 return ordinal===d.floor+2;
}
export function npcDungeonObjectivePlan(world,p,{isNpc=q=>!!q.npcPlayer}={}){
 const i=world.instances?.get(p.instanceId),d=i?.director,party=world.parties?.get(p.partyId);
 if(!isNpc(p)||p.dead||p.leaving||p.sceneTransition||i?.kind!=='dungeon'||!d||d.disposed||i.closeRequested||i.floorTransition||!party?.members.includes(p.id))return null;
 if(![...world.players.values()].some(h=>party.members.includes(h.id)&&!isNpc(h)&&!h.dead&&!h.leaving&&!h.sceneTransition&&h.instanceId===i.id))return null;
 const support=npcDungeonObjectiveSupport(world,i);if(!support.supported)return{stage:'unsupported dungeon objectives',blockedReason:support.reason,at:null,action:null};
 if((i.channels||[]).some(c=>c.p===p))return{stage:'finishing native dungeon channel',waiting:true,at:null,action:null};
 const scene=mapFor(world,p),distance=a=>Math.hypot(p.x-a.x,p.z-a.z),choices=[],blocked=[];
 const objectPlan=()=>{const t=(d.triggers||[]).filter(t=>!t.disposed&&t.clickable&&!t.busy&&!t.locked&&!t.opened).sort((a,b)=>distance(a)-distance(b))[0];if(!t)return null;const at={map:p.map,x:t.x,z:t.z};return{stage:'operating native dungeon object',at,action:distance(at)<=3?{type:'dungeon',operation:'trigger',trigger:t.uid}:null};};
 if(d.phase==='cleared'){
  const object=objectPlan();if(object)return object;
  if(!d.isLastFloor){const next=d.scriptNpcs.filter(sn=>nextFloorNpc(world,i,d,sn)).map(sn=>({sn,path:menuPath(d,sn)})).filter(x=>x.path).sort((a,b)=>distance({x:a.sn.x,z:a.sn.y})-distance({x:b.sn.x,z:b.sn.y}))[0];
   if(!next)return{stage:'waiting for supported next floor',blockedReason:'No supported positive native next-floor NPC path.',at:null,action:null};
   const at={map:p.map,x:Number(next.sn.x),z:Number(next.sn.y),npc:Number(next.sn.npc)};return{stage:'advancing native dungeon floor',at,action:distance(at)<=8?{type:'dungeon',operation:'npc',npc:Number(next.sn.npc),path:next.path}:null};
  }
  return{stage:'leaving resolved dungeon',at:null,action:{type:'dungeon',operation:'exit'}};
 }
 if(d.phase==='failed')return{stage:'leaving resolved dungeon',at:null,action:{type:'dungeon',operation:'exit'}};
 if(!['countdown','running'].includes(d.phase))return null;
 for(const sn of d.scriptNpcs||[]){
  if(d.used.has(sn.npc)||!['start','interact','bossSummon'].includes(sn.role))continue;
  if(d.phase==='countdown'&&!(sn.role==='start'&&d.waitStart))continue;
  if(sn.role==='bossSummon'&&!d.stages.some(s=>s.kind==='boss'&&!s.spawned&&(!s.trigger||s.trigger.npc===sn.npc)))continue;
  const path=menuPath(d,sn);if(!path){blocked.push({stage:'unsupported native dungeon interaction',blockedReason:'Native dungeon menu has no supported positive first-branch path for NPC '+sn.npc+'.',at:null,action:null});continue;}const at={map:p.map,x:Number(sn.x),z:Number(sn.y),npc:Number(sn.npc)};
  choices.push({stage:'operating native dungeon '+sn.role,at,action:distance(at)<=8?{type:'dungeon',operation:'npc',npc:Number(sn.npc),path}:null});
 }
 choices.sort((a,b)=>distance(a.at)-distance(b.at));if(choices.length)return choices[0];
 if(d.phase==='countdown')return blocked[0]||{stage:'preparing during dungeon countdown',waiting:true,at:null,action:null};
 const targets=[...scene.monsters.values()].filter(m=>!m.dead&&(!m.isBrick||m.breakable)&&!['invisible','npc','trap'].includes(m.def?.role)).map(m=>({m,at:m.isBrick?objectHitPoint(scene,p,m):m})).filter(t=>t.at);
 targets.sort((a,b)=>distance(a.at)-distance(b.at));if(targets[0]){const {m,at}=targets[0];return{stage:m.isBrick?'fighting native dungeon breakable':'fighting native dungeon wave',targetId:m.id,at:{map:p.map,x:at.x,z:at.z},action:null};}
 return objectPlan()||blocked[0]||{stage:'waiting for dungeon host progression',waiting:true,at:null,action:null};
}
