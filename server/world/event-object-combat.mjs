import {mapFor} from './scene.mjs';
import {queueInstanceProgress} from './instance-progress.mjs';
import {partyExpRewards} from './party.mjs';
import {scaledReward} from './rates.mjs';
import {isTeamStone,teamStoneActive,teamStoneDamage,rewardTeamStone} from './team-stones.mjs';
const supported=new Set([36818,36819]);
const percent=v=>Math.max(0,Math.min(100,Number(v)||0));
// Ice Castle breakable bricks and the DK/Draco team stones share the host's
// fixed-damage object path (core plain hits, skills, reward routing).
export const isEventObject=m=>!!m?.eventObject&&supported.has(Number(m.brickIndex))||isTeamStone(m);
export function eventObjectActive(world,p,m){
 if(isTeamStone(m))return teamStoneActive(world,p,m);
 const i=world.instances?.get(p.instanceId);
 return isEventObject(m)&&i?.kind==='iceCastle'&&i.scene===mapFor(world,p)&&i.scene.monsters.get(m.id)===m&&m.instanceId===i.id&&m.map===p.map&&!m.removed&&!m.dead&&!i.closed&&!i.closeRequested&&!i.admitting&&!i.run?.ended&&i.run?.won==null&&i.run?.phase==='fortress';
}
export function eventObjectDamage(world,p,m,amount,kind='melee'){
 if(!isEventObject(m))return amount;
 if(isTeamStone(m))return teamStoneDamage(world,p,m,amount,kind);
 if(!eventObjectActive(world,p,m))return 0;
 const d=m.brickDef,typed=kind==='magic'?d.magicResist:kind==='range'?d.rangeDamageResist:d.meleeDamageResist;
 const resist=Math.max(percent(typed),kind==='magic'?0:percent(d.physicalResist));
 return Math.max(0,Math.round((Number(amount)||0)*(100-resist)/100));
}
// The source's elemental fields are percentages. The generic skill formula caps
// monster resistance at90; these source-immune objects must retain exact100.
export function eventObjectElementDamage(m,amount,element,elementPct){
 const key={fire:'FireResist',ice:'IceResist',lightning:'LightResist',poison:'PoisonResist',curse:'CurseResist',dark:'DarkResist','dark?':'DarkResist'}[element];
 if(!isEventObject(m)||!key)return amount;
 return Math.max(0,Math.round(amount*(1-percent(elementPct||100)/100*percent(m.brickDef.raw?.[key])/100)));
}
export function rewardEventObject(world,p,m){
 if(!isEventObject(m))return false;
 if(isTeamStone(m))return rewardTeamStone(world,p,m);
 const i=world.instances?.get(m.instanceId);
 if(m._eventObjectCounted||!m.dead||!i||i.kind!=='iceCastle'||i.scene.monsters.get(m.id)!==m||p.instanceId!==i.id||p.map!==i.map)return true;
 m._eventObjectCounted=true;m.hp=0;m.targetId=null;m.respawnAt=Infinity;
 i.run.bricks.remove(m.uid,'die');
 // A counted world death earns the native objective score immediately. Account
 // EXP remains private until its queued commit; final rewards see this score.
 i.run.onBrickDestroyed?.(m);
 const rewards=new Map(partyExpRewards(world,p,scaledReward(Number(m.brickDef.exp)||0,world.rates.exp),m).map(r=>[r.player.id,r.exp]));
 queueInstanceProgress(world,i,`event-object:${m.id}`,(candidate,facade)=>{
  const exp=rewards.get(candidate.id)||0;if(exp)world.grantProgress.call(facade,candidate,exp);
  facade.emit(i.map,{type:'reward',actorId:candidate.id,exp,dil:0,objectId:m.id,instanceId:i.id});
 });
 return true;
}
