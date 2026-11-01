// Native Renew gate assets/groups/prices with explicit engine placement and HP
// reconstruction. No live account edits; all spending uses socialTransaction.
import {randomUUID} from 'node:crypto';
import {socialRef,socialTransaction} from './social-state.mjs';
import {sameScene} from './scene.mjs';
import {trackForcedDisplacement} from './movement-authority.mjs';
import {footprintCells} from '../../src/systems/events/bricks.js';
import {blockCollisionCells} from '../../src/world/collision-blockers.js';
import {renewGateRows,renewGateLevel,renewGateHP} from '../../src/game/siege-renew-gate-rules.js';
const refuse=(code,status=409)=>{throw Object.assign(Error(`siege:701:${code}`),{status,code:'SIEGE_RENEW_REFUSED'});};
const guildOf=(s,ref)=>Object.values(s?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref));
const stateOf=(w,map)=>w.socialState?.siegeRenew?.castles?.[map];
export function siegeRenewGateDataReady(world,castle){const rows=renewGateRows(castle,world.data.eventData);return rows.length===castle?.groups?.flat().length&&rows.every(r=>r.group>=0&&r.def?.visual?.mesh&&r.def?.maxHP>0&&r.def?.defaultHP>0)&&castle.upgradePrices.length===5&&castle.upgradePrices.every(n=>Number.isSafeInteger(n)&&n>0);}
export function clearSiegeRenewGates(b){for(const m of b.gates?.values()||[]){m._releaseGate?.();m._releaseGate=null;m.disposed=true;b.scene.monsters.delete(m.id);}b.gates=new Map();}
export function syncSiegeRenewGates(world,b,castle){
 if(!siegeRenewGateDataReady(world,castle))return false;
 clearSiegeRenewGates(b);const s=stateOf(world,b.map),blocked=b.kind==='battle'&&b.phase==='battle';
 for(const row of renewGateRows(castle,world.data.eventData)){
  const def=row.def,level=renewGateLevel(s?.gateLevels?.[row.group],castle.upgradePrices.length),hp=renewGateHP(def,level,castle.upgradePrices.length),id=`renew-gate:${b.instanceId}:${row.uid}`;
  const cells=footprintCells(row.x,row.z,row.dir,(def.widthSize||1)*2,(def.heightSize||1)*2).filter(([x,z])=>x>=0&&z>=0&&x<b.scene.width&&z<b.scene.height).map(([x,z])=>({x,z,i:z*b.scene.width+x}));
  const m={id,uid:row.uid,renewObject:true,renewGate:true,isBrick:true,brickIndex:row.brick,group:row.group,gateLevel:level,map:b.map,instanceId:b.instanceId,channel:0,x:row.x,z:row.z,dir:row.dir,name:def.name,hp,maxHp:hp,dead:false,targetId:null,respawnAt:Infinity,respawnSec:Infinity,home:{x:row.x,z:row.z},brickDef:def,objectFootprint:cells,gateClosed:blocked,
   def:{level:Number(def.level)||1,exp:0,def:[0],money:[0,0,0],name:def.name,role:'object',attackable:true}};
  if(blocked)m._releaseGate=blockCollisionCells(b.scene.collision,cells.map(c=>c.i));
  b.gates.set(row.uid,m);b.scene.monsters.set(id,m);
 }
 // Closing gates cannot strand an already-present character inside a blocker.
 for(const p of world.players.values())if(sameScene(p,{map:b.map,instanceId:b.instanceId,channel:0})&&!p.leaving&&!p.sceneTransition&&!b.scene.isWalkable(p.x,p.z)){
  const at=b.scene.nearest(p.x,p.z);if(at){p.x=at.x;p.z=at.z;p.path=[];trackForcedDisplacement(world,p);world.changed(p);}
 }
 return true;
}
export function rewardSiegeRenewGate(world,p,m,authorized){
 const b=world.siegeRenewLive?.battles?.get(m.map),hit=m._acceptedHit;
 if(!m.renewGate)return false;
 if(!b||b.gates?.get(m.uid)!==m||m.hp>0)return true;
 if(!authorized||!hit||hit.source!==p?.id){m.dead=false;m.hp=hit?.hp||m.maxHp;return true;}
 m.dead=true;m.gateClosed=false;m.respawnAt=Infinity;m._releaseGate?.();m._releaseGate=null;
 world.emit(m.map,{type:'siegeGateDestroyed',actorId:m.id,uid:m.uid,instanceId:m.instanceId});
 return true; // no EXP, DIL, loot, quest or capture reward
}
export function siegeRenewGateView(world,p,b,castle){
 if(!siegeRenewGateDataReady(world,castle))return null;
 const s=stateOf(world,b.map),g=guildOf(world.socialState,socialRef(p)),prep=b.kind==='peace'||b.phase==='battle'&&world.now()<b.prepUntil;
 const groups=castle.groups.map((gates,group)=>{const level=renewGateLevel(s?.gateLevels?.[group],castle.upgradePrices.length);return {group,name:castle.strongholds?.[group]?.name||`Gate ${group+1}`,level,maxLevel:castle.upgradePrices.length,nextPrice:castle.upgradePrices[level]??null,prices:castle.upgradePrices,gates};});
 return {groups,available:prep&&g?.id===s?.owner?.guild&&g?.master===socialRef(p),funds:Number(p.profile.dil)||0};
}
export async function siegeRenewGateCommand(world,p,{b,castle,input,check}){
 const eligibility=(state,ref)=>{check();const s=state?.siegeRenew?.castles?.[b.map],g=guildOf(state,ref);if(!g)refuse(203,403);if(g.id!==s?.owner?.guild)refuse(204,403);if(g.master!==ref)refuse(205,403);if(b.kind!=='peace'&&!(b.phase==='battle'&&world.now()<b.prepUntil))refuse(101);return s;};
 eligibility(world.socialState,socialRef(p));if(!siegeRenewGateDataReady(world,castle))refuse(201,503);
 if(input.group===undefined)return siegeRenewGateView(world,p,b,castle);
 const group=Number(input.group);if(!Number.isInteger(group)||group<0||group>=castle.groups.length)refuse(206,400);
 const target=input.targetLevel===undefined?null:Number(input.targetLevel);if(target!==null&&(!Number.isInteger(target)||target<1||target>castle.upgradePrices.length))refuse(206,400);
 await socialTransaction(world,p,{get revision(){return world.socialState.revision;},requestId:`renew-gate-${randomUUID()}`},(state,profile,ref)=>{
  const s=eligibility(state,ref),level=renewGateLevel(s.gateLevels?.[group],castle.upgradePrices.length),next=target??level+1;
  if(level>=castle.upgradePrices.length)refuse(209);if(next<=level)refuse(206,400);
  const price=castle.upgradePrices.slice(level,next).reduce((a,b)=>a+b,0);if(Number(profile.dil)<price)refuse(207);
  profile.dil-=price;(s.gateLevels||={})[group]=next;return {group,level:next,price};
 });
 syncSiegeRenewGates(world,b,castle);return siegeRenewGateView(world,p,b,castle);
}
