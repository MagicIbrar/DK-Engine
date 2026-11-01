import {sameScene} from './scene.mjs';
// ENGINE-CHOSEN nearby event assist. Observe accepted native attacks only;
// no new leader action, target mutation, movement, threat or damage change.
export function npcEventPartyFocus(world,p,scene,targets,{isNpc=q=>q?.npcPlayer===true,canAssist=()=>true,reachable=()=>false}={}){
 const instance=world.instances?.get(p.instanceId),run=instance?.run,party=p.partyId&&world.parties?.get(p.partyId);
 if(!party||!['deadFront','iceCastle'].includes(instance?.kind)||!run||run.phase!=='fortress'||run.ended||run.won!=null||instance.closeRequested||!party.members.includes(p.id))return null;
 const team=instance.teams?.find(t=>t.ids?.has(p.id));if(!team)return null;
 const current=q=>q&&world.players.get(q.account)===q&&isNpc(q)&&q.profile?.authority==='server'&&q.profile.npcPlayer===true&&sameScene(p,q)&&q.partyId===p.partyId&&team.ids.has(q.id)&&instance.members?.has(q.id)&&instance.admitted?.has(q.characterId)&&!q.dead&&!q.leaving&&!q.sceneTransition&&!q.tradeId&&!q.pcShopOpen&&!q.progressCommitting&&!q.commandActive&&canAssist(q);
 if(!current(p))return null;
 const byId=new Map();for(const q of world.players.values())if(q.partyId===p.partyId)byId.set(q.id,q);
 const members=party.members.map(id=>byId.get(id));
 // Do not silently take over a human's mixed party or an unavailable member's orders.
 if(members.some(q=>!q||!isNpc(q)))return null;
 const ordered=[members.find(q=>q.id===party.leader),...members.filter(q=>q.id!==party.leader)];
 for(const caller of ordered){
  if(!current(caller)||Math.hypot(caller.x-p.x,caller.z-p.z)>40)continue;
  const engine=caller._skills?.engine;if(engine?.active&&engine.game?._playerRecord!==caller)continue;
  const accepted=engine?.active?.target?._record||caller.attackTarget;
  const target=typeof accepted==='string'?scene.monsters.get(accepted):accepted;
  if(!target||target.dead||target.disposed||target.leaving||target.isBrick||target.eventObject||target.def?.role!=='creature'||scene.monsters.get(target.id)!==target||!targets.includes(target))continue;
  if(caller===p)return null; // Keep the caller's own existing local policy.
  const close=Math.hypot(target.x-p.x,target.z-p.z)<=8;
  if(close&&scene.collision?.lineOfSight?.(p.x,p.z,target.x,target.z))return target;
  return reachable(target)?target:null; // One bounded reachability query, then local fallback.
 }
 return null;
}
