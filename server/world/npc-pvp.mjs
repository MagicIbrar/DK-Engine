import {sameScene,sceneKey} from './scene.mjs';
import {pkRefusal} from './field-pk.mjs';
import {duelOpponent,isPvpTarget} from './pvp.mjs';
// ENGINE-CHOSEN player decisions, never combat/PK balance: ordinary requests,
// cooldowns, safe areas, alliances, shield/damage, death and penalties apply.
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const areas=new WeakMap();
// ENGINE-CHOSEN outlaw preferences, not native PK legality. New-player fields
// do not receive unsolicited bot ambushes; actual attacks may still be defended.
export function npcPkAreaPolicy(world,p){
 const data=world.data;let cache=areas.get(data);if(!cache){cache=new Map();areas.set(data,cache);}let area=cache.get(Number(p.map));
 if(!area){const levels=(data.spawns?.(p.map)||[]).map(s=>data.monsterDef?.(s.monsterIndex)).filter(d=>d?.role==='creature'&&Number(d.exp)>0&&Number(d.level)>0).map(d=>Number(d.level)).sort((a,b)=>a-b),minimum=Number(data.mapRow?.(p.map)?.LimitMinLevel)||0,typical=levels.length?levels[Math.floor(levels.length/2)]:minimum;
  const name=String(data.mapRow?.(p.map)?.Name||'').trim(),provokedOnly=['Draco Desert','Parca Temple'].includes(name);
  area={name,nativeLevels:levels.length?[levels[0],levels.at(-1)]:null,typicalLevel:typical,provokedOnly,chance:provokedOnly?0:typical>=100?.3:typical>=60?.1:0};cache.set(Number(p.map),area);}
 return {...area,allowAmbush:!p.instanceId&&Number(p.profile.level)>=60&&area.chance>0};
}
export async function npcPvpStep(world,p,b,{act,isNpc=()=>false}={}){
 const now=world.now(),live=[...world.players.values()].filter(q=>q!==p&&!q.leaving&&!q.dead&&sameScene(p,q)),duel=p.duelId&&world.duels?.get(p.duelId);
 const action=async input=>{try{await act(p,input);return true}catch(e){if(!e.status)throw e;return false;}};
 if(p.dead){if(p.pvpRestore){if(now>=p.pvpRestore.at)await action({type:'pvp',operation:'restore'});return {handled:true};}return {handled:false};}
 const event=p.instanceId&&world.instances?.get(p.instanceId);
 if(event&&['deadFront','iceCastle'].includes(event.kind)&&['pvp','extension'].includes(event.run?.phase)){
  const enemies=live.filter(q=>isPvpTarget(world,p,q)).sort((a,c)=>distance(p,a)-distance(p,c));
  return enemies.length?{handled:true,target:enemies[0],forced:false}:{handled:true};
 }
 if(duel){
  if(duel.phase==='invited'&&duel.players[1]===p){b.prepareUntil=now+20000;await action({type:'pvp',operation:'accept'});return {handled:true};}
  const target=duelOpponent(world,p);if(target&&!target.dead)return {handled:true,target,forced:false};
  b.prepareUntil=now+10000;return {handled:true};
 }
 if(b.duelTarget&&now>=(b.duelRequestAt||0)){
  const target=live.find(q=>q.id===b.duelTarget);b.duelTarget=null;b.duelRequestAt=now+60000;
  if(target&&distance(p,target)<20){await action({type:'pvp',operation:'request',targetId:target.id});return {handled:true};}
 }
 const recent=p.pvpLastHit,defend=recent&&now-Number(recent.at)<10000&&live.find(q=>q.id===recent.by);
 if(defend&&pkRefusal(world,p,defend)===null){if(b.pkAnchor?.targetId!==defend.id)b.pkAnchor={targetId:defend.id,x:p.x,z:p.z,scene:sceneKey(p.map,p.instanceId,p.channel)};b.pkTarget=defend.id;b.pkUntil=now+10000;b.pkSource='self-defense';}
 const area=npcPkAreaPolicy(world,p);
 let target=live.find(q=>q.id===b.pkTarget);
 // ENGINE-CHOSEN finite pursuit: actual opponents can escape. Neither native
 // movement speed nor damage/skill ranges are changed by this decision radius.
 const chase=target&&distance(p,target)<=40&&(!b.pkAnchor||b.pkAnchor.scene===sceneKey(p.map,p.instanceId,p.channel)&&distance(p,b.pkAnchor)<=40);
 if(target&&chase&&(now<(b.pkUntil||0))&&(b.pkSource==='self-defense'||area.allowAmbush)&&pkRefusal(world,p,target)===null)return {handled:true,target,forced:true};
 b.pkTarget=null;
 if(p.profile.npcTraits?.social==='outlaw'&&area.allowAmbush&&now>=(b.pkReady||0)){
  b.pkReady=now+120000+Math.floor(world.random()*60000);
  if(world.random()<area.chance){const candidates=live.filter(q=>Math.abs(q.profile.level-p.profile.level)<=8&&distance(p,q)<24&&pkRefusal(world,p,q)===null).sort((a,c)=>Number(isNpc(c))-Number(isNpc(a))||distance(p,a)-distance(p,c));
   target=candidates[0];if(target){b.pkTarget=target.id;b.pkUntil=now+15000;b.pkSource='outlaw';b.pkAnchor={targetId:target.id,x:p.x,z:p.z,scene:sceneKey(p.map,p.instanceId,p.channel)};return {handled:true,target,forced:true};}
  }
 }
 return {handled:false};
}
