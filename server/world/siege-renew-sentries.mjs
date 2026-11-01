// Native sentry records/actors. ENGINE-CHOSEN: dead rows leave the shared pool;
// survivors are recreated at native full HP when a new castle scene is loaded.
import {siegeSystemWrite} from './siege.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {sameScene,sceneKey} from './scene.mjs';
export const isSiegeRenewGuard=m=>m?.renewGuard===true;
export function siegeRenewGuardCanTarget(world,m,p){
 const b=world.siegeRenewLive?.battles?.get(m.map),r=b?.participants.get(p?.id),owner=world.socialState?.siegeRenew?.castles?.[m.map]?.owner?.guild;
 return !m.dead&&!m.disposed&&!!p&&!p.leaving&&!p.sceneTransition&&!p.dead&&!!b&&b.phase==='battle'&&!b.capturing&&world.now()>=b.prepUntil&&world.now()<b.endAt&&b.instanceId===m.instanceId&&sameScene(m,p)&&b.scene.monsters.get(m.id)===m&&owner===m.guardGuild&&r?.account===p.account&&r.characterId===p.characterId&&r.side==='attacker'&&r.guild!==owner&&!allianceOfGuild(world.socialState,owner)?.guilds.includes(r.guild);
}
export const siegeRenewGuardActive=(world,p,m)=>!m.dead&&siegeRenewGuardCanTarget(world,m,p);
export function syncSiegeRenewGuards(world,b){
 const state=world.socialState?.siegeRenew?.castles?.[b.map],rows=(state?.guards||[]).filter(row=>row.guild===state.owner?.guild),wanted=new Set(rows.map(row=>row.id));
 for(const m of b.scene.monsters.values())if(isSiegeRenewGuard(m)&&!wanted.has(m.guardRow)){m._guardCombat?.remotes.clear();m.disposed=true;b.scene.monsters.delete(m.id);world.emit(b.map,{type:'leave',actorId:m.id,instanceId:b.instanceId});}
 for(const row of rows){
  const id=`renew-guard:${b.instanceId}:${row.id}`;if(b.scene.monsters.has(id))continue;
  const def=world.data.monsterDef?.(row.sentry);if(!def?.sentry||!def.attackResults||!(def.hp>0))continue;
  const m={id,renewGuard:true,guardRow:row.id,guardGuild:row.guild,monsterIndex:row.sentry,def,name:def.name,map:b.map,instanceId:b.instanceId,channel:0,x:row.x,z:row.z,yaw:0,home:{x:row.x,z:row.z},hp:def.hp,maxHp:def.hp,dead:false,targetId:null,statuses:[],attackAt:0,respawnAt:Infinity,respawnSec:Infinity};
  b.scene.monsters.set(id,m);world.emit(b.map,{type:'spawn',actorId:id,monsterIndex:row.sentry,instanceId:b.instanceId});
 }
}
export function rewardSiegeRenewGuard(world,_p,m){
 if(!isSiegeRenewGuard(m))return false;
 m.dead=true;m.respawnAt=Infinity;m.targetId=null;m.hate?.clear();m._guardCombat?.remotes.clear();m.guardDiedAt??=world.now();
 if(!m.guardDeathWrite&&!m.guardRemoved){m.guardDeathWrite=siegeSystemWrite(world,state=>{const c=state.siegeRenew?.castles?.[m.map],before=c?.guards||[],next=before.filter(row=>row.id!==m.guardRow);if(!c||next.length===before.length)return false;c.guards=next;return true;}).then(()=>{m.guardRemoved=true;}).catch(error=>{m.guardSaveError=error.message;}).finally(()=>{m.guardDeathWrite=null;});}
 return true; // no ordinary quest, EXP, DIL or loot path
}
export function tickSiegeRenewGuardDeath(world,m){
 if(!isSiegeRenewGuard(m)||!m.dead)return false;
 if(!m.guardRemoved)rewardSiegeRenewGuard(world,null,m);
 if(m.guardRemoved&&world.now()-(m.guardDiedAt||0)>=8000){const scene=world.maps.get(sceneKey(m.map,m.instanceId));scene?.monsters.delete(m.id);}
 return true;
}
