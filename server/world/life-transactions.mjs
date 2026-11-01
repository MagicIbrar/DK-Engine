import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {mergeRewardProgress} from './reward-progress.mjs';
// Dedicated services share a lock even when called directly by isolated tests.
const queues = new WeakMap();
export function lifeError(message) { throw Object.assign(new Error(message), {status:400}); }
export function validateLife(input, schemas) {
  const fields=schemas[input.type];
  if(!fields || Object.keys(input).some(k=>!fields.includes(k)))lifeError('Send life-system intent only, never results or resources.');
}
export function serializeLife(p, operation) {
  const result=(queues.get(p)||Promise.resolve()).catch(()=>{}).then(async()=>{
    p.commandActive=(p.commandActive||0)+1;
    try{return await operation();}finally{p.commandActive=Math.max(0,(p.commandActive||1)-1);}
  });
  queues.set(p,result);
  void result.finally(()=>{if(queues.get(p)===result)queues.delete(p);}).catch(()=>{});
  return result;
}
export async function commitLife(world,p,profile,{stats=null,hp,mp,shield,vitalDeltas=null,profileBefore=null,rewardProgress=false,revive=false}={}) {
  // Reward settlement owns the transition flag until its durable party write
  // finishes. Joining it before taking our life-transaction flag prevents a
  // later finally from restoring that flag after the reward has released it.
  if(p.progressSave)await p.progressSave;
  // Async item effects may already have yielded before entering this commit.
  const beforeProfile=structuredClone(profileBefore||p.profile);
  const progressBeforeCommit=!!profileBefore&&JSON.stringify(profileBefore)!==JSON.stringify(p.profile);
  const transition=p.sceneTransition,revision=p.revision??0,hpBefore=p.hp,mpBefore=p.mp,deadBefore=p.dead;
  p.sceneTransition=true;
  try {
    const candidate={...p,profile};if(revive)candidate.dead=false;
    if(stats){candidate.stats=stats;candidate.maxHp=stats.maxHp;candidate.hp=hp??Math.min(p.hp,stats.maxHp);candidate.mp=mp??Math.min(p.mp||0,stats.maxMp||0);}
    candidate.maxShield=Math.max(0,Number(candidate.stats?.maxShield)||0);
    candidate.shield=Math.max(0,Math.min(candidate.maxShield,Number(shield??p.shield)||0));
    world.changed(candidate);
    let npcCheckpoint=null;
    const npcLife=!p.instanceId&&!p.profile?.instance&&(p.channel??0)===0&&!p.profile?.dkReturn&&!p.customMapPending&&!world.data.customMaps?.has?.(p.map)&&!world.data.requiresInstance?.(p.map)&&!p.arenaId&&!p.dkSquareId&&!p.colosseumId&&!p.partyPvpId&&!p.trainingCampId&&!p.duelId&&!p.raceRun&&!p.tradeId&&!p.charTradeId&&!p.tradeCommitting&&!p.progressCommitting&&!p.pcShopOpen&&!p.smartWarp&&!p.fishing&&!p.mount&&!Object.hasOwn(world,'persist')&&typeof world.persistNpcLifeCheckpoint==='function'&&world.players?.get(p.account)===p&&/^npc_[a-f0-9]{32}$/.test(p.account)&&world.npcPeriodicAccount?.(p.account)===true&&p.npcPlayer===true&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.characterId&&p.commandActive>0;
    const mergeEarned=rewardProgress||npcLife;
    const prepared=mergeEarned?{dil:profile.dil}:null;
    if(npcLife){
      npcCheckpoint=await world.persistNpcLifeCheckpoint(p,candidate);
      if(npcCheckpoint.isCurrent()!==true){const error=Object.assign(new Error('Saved bot life progress awaits original actor reconciliation.'),{status:409});Object.defineProperty(error,'npcLifeCheckpointCommitted',{value:true});throw error;}
    }else await world.persist(candidate);
    const liveLevel=p.profile.level,liveMaxHp=p.maxHp,liveMaxMp=p.stats?.maxMp||0;
    const merged=mergeEarned?mergeRewardProgress(world,p,beforeProfile,candidate,prepared):null;
    if(merged?.levelChanged){stats=candidate.stats;vitalDeltas={hp:(vitalDeltas?.hp||0)+merged.hpGain,mp:(vitalDeltas?.mp||0)+merged.mpGain};}
    // Publish only transaction-owned fields. A stop, revocation or session update
    // accepted while storage was pending belongs to the live actor, not the clone.
    publishProfileChanges(p.profile,beforeProfile,profile);
    if(stats){p.stats=stats;p.maxHp=stats.maxHp;if(!vitalDeltas){p.hp=p.hp===hpBefore?candidate.hp:Math.min(p.hp,p.maxHp);p.mp=p.mp===mpBefore?candidate.mp:Math.min(p.mp||0,stats.maxMp||0);}}
    const intervening=(p.revision??0)-revision;
    p.revision=(candidate.revision??revision)+intervening;
    p.dirty=!!candidate.dirty||intervening!==0||progressBeforeCommit;
    p.saveError=candidate.saveError;
    refreshConcurrentBuffStats(world,p,beforeProfile);
    p.maxShield=Math.max(0,Number(p.stats?.maxShield)||0);
    // A concurrent native reward may have already levelled and healed the live
    // recipient. Apply only the remaining growth, retaining its later HP/MP costs.
    if(mergeEarned&&liveLevel>beforeProfile.level&&profile.level>beforeProfile.level)vitalDeltas={hp:Math.max(0,p.maxHp-liveMaxHp),mp:Math.max(0,(p.stats.maxMp||0)-liveMaxMp)};
    // Item recovery adds its accepted gain to the latest live vitals. Preserve
    // intervening ally healing/MP costs, and never revive a later-dead actor.
    if(revive&&deadBefore&&p.dead===deadBefore&&p.hp===hpBefore&&(p.profile.deaths||0)===(beforeProfile.deaths||0)){p.dead=false;p.hp=0;}
    if(vitalDeltas){if(!p.dead&&(p.hp>0||revive)){p.hp=Math.min(p.maxHp,Math.max(0,p.hp+(vitalDeltas.hp||0)));p.mp=Math.min(p.stats.maxMp||0,Math.max(0,(p.mp||0)+(vitalDeltas.mp||0)));p.shield=(Number(p.shield)||0)+(vitalDeltas.shield||0);}else{p.hp=0;p.mp=Math.min(p.stats.maxMp||0,Math.max(0,p.mp||0));}}
    // Gear removal clamps the latest live remainder; accepted recovery adds only
    // its staged gain, so intervening damage/death cannot be overwritten.
    p.shield=Math.max(0,Math.min(p.maxShield,Number(p.shield)||0));
    const vitalsChanged=p.shield!==candidate.shield||!!vitalDeltas&&(p.hp!==candidate.hp||p.mp!==candidate.mp||p.dead!==candidate.dead);
    if(vitalsChanged)world.changed(p);
    const queuedSuccessor=npcCheckpoint?.hasQueuedSuccessor()===true;
    if(queuedSuccessor)p.dirty=true;
    if(intervening!==0||vitalsChanged||progressBeforeCommit||queuedSuccessor)await persistInterveningProgress(world,[p]);
    return {concurrentLevel:liveLevel,notices:merged?.notices||[]};
  }finally{p.sceneTransition=transition;}
}
