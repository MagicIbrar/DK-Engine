import {questCommand,boxCommand,itemBoxFacade} from './quests.mjs';
import {commitLife} from './life-transactions.mjs';
import {sceneKey} from './scene.mjs';
import {enterTrustedScene} from './instances.mjs';
import {cancelFishing} from './fishing.mjs';
import {prepareSiegeRenewQuestWarp} from './siege-renew-controller.mjs';
import {trackForcedDisplacement} from './movement-authority.mjs';

// Summon boxes append native actors to map.monsters. Stage only those additions,
// preserving concurrent actors in the real scene when the commit publishes.
function stageWorld(world,actor){
 const notifications=[],scenes=[],staged=Object.create(world),baselineKeys=new Set(world.maps.keys());
 staged.emit=(map,event)=>notifications.push([map,event]);
 staged.maps=new Map(world.maps);const key=sceneKey(actor.map,actor.instanceId,actor.channel??0),scene=world.maps.get(key);
 if(scene){const copy={...scene,monsters:new Map(scene.monsters)},existing=new Set(scene.monsters.keys());scenes.push({scene,copy,existing});staged.maps.set(key,copy);}
 // Publish only newly prepared destinations. Baseline scenes may be disposed or
 // replaced while persistence is pending; their lifecycle belongs to the world.
 return {world:staged,publish(levelLimit=null){for(const[key,scene]of staged.maps)if(!baselineKeys.has(key)&&!world.maps.has(key))world.maps.set(key,scene);for(const {scene,copy,existing}of scenes)for(const[id,actor]of copy.monsters)if(!existing.has(id)&&!scene.monsters.has(id))scene.monsters.set(id,actor);for(const[map,event]of notifications)if(event.type!=='levelup'||levelLimit==null||event.level>levelLimit)world.emit(map,event);}};
}

/** Rewards, progress and notifications become visible only after a durable save.
 * Keep the native quest engine/XP formulas; buffer its cosmetic notifications while
 * it operates on a candidate. commitLife merges any concurrent recipient changes.
 */
export async function durableQuestCommand(world,p,input){
 const castleWarp=prepareSiegeRenewQuestWarp(world,p,input);
 const before=structuredClone(p.profile),transition=p.sceneTransition,hpBefore=p.hp,mpBefore=p.mp||0;
 const candidate={...p,profile:structuredClone(before),stats:{...p.stats}};
 const staged=stageWorld(world,p);
 p.sceneTransition=true;
 try{
  const result=await (input.type==='quest'?questCommand(staged.world,candidate,input):boxCommand(staged.world,candidate,input));
  let scene=null,fishBefore,fishSnapshot;
  // Field arrivals can share the reward's original durable generation. Native
  // instance admission/exit retains its separate service flow and review scope.
  if(castleWarp&&result.warpTarget){
   castleWarp.check();if(result.warpTarget.map!==castleWarp.scene.map)throw Object.assign(new Error('The original castle quest destination does not match this battle.'),{status:503});
   scene={...castleWarp.scene};Object.assign(candidate,scene);
  }else if(result.warpTarget&&!p.instanceId&&!world.data.requiresInstance?.(result.warpTarget.map)){
   fishBefore=p.fishing;fishSnapshot=fishBefore?structuredClone(fishBefore):fishBefore;candidate.fishing=fishBefore?structuredClone(fishBefore):fishBefore;
   await enterTrustedScene(staged.world,candidate,result.warpTarget.map,result.warpTarget,{kind:'quest'});
   scene={map:candidate.map,x:candidate.x,z:candidate.z,instanceId:candidate.instanceId};
  }
  // commitLife owns profile/stat/vital publication; its canonical save must also
  // contain the prepared scene while snapshots still show the original actor.
  const commitWorld=scene?Object.create(world):world;
  if(scene){let primary=true;const ownsDil=(candidate.profile.dil||0)!==(before.dil||0);commitWorld.persist=async actor=>{
   const record={...actor,...scene};try{castleWarp?.check();await world.persist(record);}finally{actor.dirty=record.dirty;actor.saveError=record.saveError;}
   // The old actor can receive trusted currency during destination loading or the
   // held primary write. Keep the quest's native cost/reward delta and that gain.
   // Follow-up progress writes use the same destination and never reapply costs.
   if(primary){primary=false;const delta=(p.profile.dil||0)-(before.dil||0);if(ownsDil&&delta){actor.profile.dil=Math.max(0,Math.min(10000000000,(actor.profile.dil||0)+delta));world.changed(actor);}}
  };}
  const gain={hp:Math.max(0,candidate.hp-hpBefore),mp:Math.max(0,(candidate.mp||0)-mpBefore)};
  const publication=await commitLife(commitWorld,p,candidate.profile,{stats:candidate.stats,hp:Math.min(p.hp+gain.hp,candidate.stats.maxHp),mp:Math.min((p.mp||0)+gain.mp,candidate.stats.maxMp||0),vitalDeltas:gain,profileBefore:before,rewardProgress:true});
  if(scene){Object.assign(p,scene);p.path=[];trackForcedDisplacement(world,p);if(p.fishing===fishBefore&&JSON.stringify(p.fishing)===JSON.stringify(fishSnapshot))p.fishing=candidate.fishing;else cancelFishing(world,p);result.warpCommitted=true;}
  staged.publish(publication.concurrentLevel>before.level?publication.concurrentLevel:null);
  for(const[map,event]of publication.notices)world.emit(map,event);
  return result;
 }finally{p.sceneTransition=transition;}
}

/** ItemUse already owns a cloned profile and its durable commit. Keep native
 * box rules, but defer journal/box notices and summoned actors until that commit.
 */
export function durableItemBoxFacade(world,p,profile,inventory){
 const candidate={...p,profile,stats:{...p.stats}},facade=itemBoxFacade(world,candidate,profile,inventory);
 let staged;
 return {...facade,open:async entry=>{staged ||= stageWorld(world,p);return itemBoxFacade(staged.world,candidate,profile,inventory).open(entry);},publish:()=>staged?.publish()};
}
