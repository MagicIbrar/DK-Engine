// ENGINE-CHOSEN targeting over native run progress, never a gate or spawn mutation.
export const NPC_DF_PRIORITY_POLICY=Object.freeze({defendHpRatio:.75,threatRange:25,candidates:4});
export function npcDeadFrontTargetPriority(world,p,scene,targets,{canAssist=()=>true}={}){
 const instance=world.instances?.get(p.instanceId),run=instance?.run;
 if(instance?.map!==p.map||instance?.scene!==scene)return [];
 if(world.players?.get(p.account)!==p||p.profile?.authority!=='server'||p.profile.npcPlayer!==true||instance?.kind!=='deadFront'||!run||run.phase!=='fortress'||run.ended||run.won!=null||instance.closeRequested||p.dead||p.leaving||p.sceneTransition||p.tradeId||p.pcShopOpen||p.progressCommitting||p.commandActive||!canAssist(p)||!instance.members?.has(p.id)||!instance.admitted?.has(p.characterId))return [];
 const party=p.partyId&&world.parties?.get(p.partyId),mates=new Set(party?.members||[]);mates.add(p.id);
 const key=run.waves?.live?.('finalBoss')?.length?'finalBoss':run.bricks?.standing?.(118)===false?'midBoss':run.bricks?.standing?.(117)===false&&run.bricks?.standing?.(118)===true?'bridge':null;
 if(!key)return [];
 const required=(key==='bridge'?[...(run.waves.groups?.keys()||[])].filter(k=>/^bridge_\d+$/.test(k)).flatMap(k=>run.waves.live(k)||[]):run.waves.live(key)||[]).filter(m=>targets.includes(m)&&scene.monsters.get(m.id)===m&&!m.dead&&!m.disposed&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature');
 // Healthy engaged actors retain mandatory progression. Protect actually wounded
 // current teammates; unavailable HP remains defensive rather than assumed safe.
 const actors=new Map([...world.players.values()].filter(q=>mates.has(q.id)&&q.map===p.map&&q.instanceId===p.instanceId&&q.channel===p.channel&&!q.dead&&!q.leaving).map(q=>[q.id,q]));
 if(targets.some(m=>{
  if(required.includes(m)||m.dead||!mates.has(m.targetId)||Math.hypot(m.x-p.x,m.z-p.z)>NPC_DF_PRIORITY_POLICY.threatRange)return false;
  const q=actors.get(m.targetId);if(!q)return false;
  const hp=q.hp,max=q.stats?.maxHp;
  return !Number.isFinite(hp)||!Number.isFinite(max)||max<=0||hp/max<=NPC_DF_PRIORITY_POLICY.defendHpRatio;
 }))return [];
 return required.sort((a,b)=>Math.hypot(a.x-p.x,a.z-p.z)-Math.hypot(b.x-p.x,b.z-p.z)).slice(0,NPC_DF_PRIORITY_POLICY.candidates);
}
