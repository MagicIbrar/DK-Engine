import {canDropToGround} from '../items/flags.js';
const PICKUP_FLIGHT_MS = 4000; // a pickup request counts as "in flight" at most this long (a lost answer must not lock the key)
export function installSharedLoot(game,network){
  const loot=game.loot;if(!loot)return;const actors=new Map(),flight=new Map();
  // One pickup key press = one request: while a request is unanswered the key takes nothing else (loot.pickupNearby / controller).
  loot.pickupBusy=()=>{const now=Date.now();for(const[id,at]of flight)if(now-at>=PICKUP_FLIGHT_MS)flight.delete(id);return flight.size>0;};
  // A drop reserved for another player (host protectedUntil, host clock) is not offered to the key; the host still decides.
  loot.canTake=drop=>{if(!drop)return false;if(!drop.ownerId||!(drop.protectedUntil>0)||drop.ownerId===network.self?.id)return true;
    const c=network._serverClock,now=c?c.time+performance.now()-c.at:Date.now();return now>=drop.protectedUntil;};
  loot.pickup=drop=>{const id=drop?.networkId;if(!id||flight.has(id))return false;flight.set(id,Date.now());
    void network.action('pickup',{dropId:id}).then(result=>{if(!result)drop.deniedAt=Date.now();}).finally(()=>flight.delete(id));return false;};
  const snapshot=network._snapshot.bind(network);
  network._snapshot=state=>{snapshot(state);if(!Array.isArray(state?.drops))return;
    const live=new Set();for(const row of state.drops){live.add(row.id);if(!actors.has(row.id)){const marker=loot.spawnDrop(row.entry,row.x,row.z);marker.networkId=row.id;marker.ownerId=row.ownerId;marker.protectedUntil=row.protectedUntil;actors.set(row.id,marker);}}
    for(const[id,marker]of actors)if(!live.has(id)){loot._removeDrop(marker);actors.delete(id);}
  };
  if(game.items)game.items.discardAsk=async item=>{
    const destroy=!canDropToGround(game.items.db.def(item.itemIndex),item);
    const result=await game.uiwin?.msgbox?.(`${destroy?'Permanently destroy':'Drop'} ${item.name}?`,{kind:'yesno'});if(result!=='yes')return false;
    return !!await network.action('discard',{uid:item.uid,count:item.count||1});
  };
}

