// Native Azure Knight Point target (87 / result 4500023): the party member
// accepts the shared enemy, then owns the authored buff until time, death,
// target change or weapon change. Expedition members are explicitly excluded.
import {randomUUID} from 'node:crypto';
import {sameScene,mapFor} from './scene.mjs';
import {isObserver} from './observers.mjs';

const live=(w,p)=>p&&!p.leaving&&!p.sceneTransition&&!p.dead&&p.hp>0&&w.players.get(p.account)===p&&!isObserver(w,p);
const weapon=p=>{
  const eq=p.profile.equip,preset=eq?.presets?.[eq.active||0];
  return preset?JSON.stringify([preset[4]||null,preset[5]||null]):JSON.stringify(p.profile.equipment?.weapon||null);
};
const targetOf=(w,p,id)=>mapFor(w,p)?.monsters?.get(id)||[...w.players.values()].find(q=>q.id===id&&sameScene(q,p));
function valid(w,p,o){
  if(!o||!live(w,p)||o.token!==p.token||o.expires<=w.now()||!sameScene(o,p))return false;
  const party=w.parties?.get(p.partyId),source=w.players.get(o.sourceAccount),target=targetOf(w,p,o.targetId);
  return !!party&&!party.expedition&&party.id===o.partyId&&party.members.includes(p.id)&&party.members.includes(o.sourceId)
    &&live(w,source)&&source.id===o.sourceId&&source.token===o.sourceToken&&sameScene(source,p)
    &&target&&!target.dead&&target.hp>0&&!target.leaving&&!isObserver(w,target);
}
export function clearSharedTarget(w,p){
  const had=!!p.sharedTargetActive;delete p.sharedTargetActive;
  const sys=p._skills;
  if(sys)sys.statuses.remove(sys.game.player,s=>!!s.sharedTargetId,'silent');
  else if(p.profile.buffs)p.profile.buffs=p.profile.buffs.filter(s=>!s.sharedTargetId);
  if(had)w.changed(p);
}
export function tickSharedTarget(w,p){
  if(p.sharedTargetOffer&&!valid(w,p,p.sharedTargetOffer)){delete p.sharedTargetOffer;w.changed(p);}
  const a=p.sharedTargetActive;
  if(a&&(!valid(w,p,a)||a.weapon!==weapon(p)||!p.profile.buffs?.some(s=>s.sharedTargetId===a.id&&s.remaining>0)))clearSharedTarget(w,p);
  // A saved/reconnected character cannot inherit a consent-bound bonus.
  if(!p.sharedTargetActive&&p.profile.buffs?.some(s=>s.sharedTargetId))clearSharedTarget(w,p);
}
export function noteSharedTargetIntent(w,p,targetId){
  tickSharedTarget(w,p);
  if(p.sharedTargetActive&&targetId!==p.sharedTargetActive.targetId)clearSharedTarget(w,p);
}
export function offerSharedTarget(w,source,target,result,skill){
  const party=w.parties?.get(source.partyId),duration=Number(result.durationMs),radius=Number(result.radius);
  if(!live(w,source)||!party||party.expedition||!target||target.dead||!(target.hp>0)||!sameScene(source,target)||!Number.isFinite(duration)||duration<=0||!(radius>0))return 0;
  let count=0;
  for(const p of w.players.values()){
    if(p===source||!live(w,p)||p.partyId!==party.id||!party.members.includes(p.id)||!sameScene(source,p)||Math.hypot(p.x-source.x,p.z-source.z)>radius)continue;
    p.sharedTargetOffer={id:randomUUID(),token:p.token,sourceAccount:source.account,sourceToken:source.token,sourceId:source.id,partyId:party.id,
      targetId:target.id,skillId:skill.index,statusIndex:result.statusIndex,duration,expires:w.now()+duration,map:p.map,instanceId:p.instanceId||null,channel:p.channel??0};
    count++;w.changed(p);
  }
  return count;
}
export function sharedTargetSnapshot(w,p){
  tickSharedTarget(w,p);
  const view=o=>o?{id:o.id,targetId:o.targetId,expires:o.expires}:null;
  return {offer:view(p.sharedTargetOffer),active:view(p.sharedTargetActive)};
}
export function answerSharedTarget(w,p,input,apply){
  const fail=()=>{throw Object.assign(Error('This shared target is no longer available.'),{status:400});};
  if(Object.keys(input).some(k=>!['type','token','operation','id'].includes(k))||!['accept','cancel'].includes(input.operation))fail();
  tickSharedTarget(w,p);
  if(input.operation==='cancel'){
    if(p.sharedTargetOffer?.id===input.id){delete p.sharedTargetOffer;w.changed(p);return;}
    if(p.sharedTargetActive?.id!==input.id)fail();
    clearSharedTarget(w,p);return;
  }
  const o=p.sharedTargetOffer;
  if(!o||o.id!==input.id||!valid(w,p,o))fail();
  clearSharedTarget(w,p);
  const entry=apply(o,w.players.get(o.sourceAccount),targetOf(w,p,o.targetId));
  if(!entry)fail();
  delete p.sharedTargetOffer;
  entry.sharedTargetId=o.id;entry.mapMoveDelete=true;
  p.sharedTargetActive={...o,weapon:weapon(p),expires:w.now()+o.duration};
  w.changed(p);
}
