// ENGINE-CHOSEN bot loot planning. The server's pickup action stays the only
// authority (ownership timer, party owner, duplicate-claim guard, bag fit,
// durable commit). These helpers only stop a bot from re-requesting a drop the
// server already refused, and from walking to items its bag cannot hold.
import {Container} from '../../src/systems/items/model.js';
export const NPC_LOOT_POLICY=Object.freeze({bagFullMs:30000,busyMs:3000,otherMs:15000,maxSkips:64,nearFullCells:0.95});
const bagOptions=p=>({pages:7,cols:10,rows:5,unlocked:()=>p.profile.bagsUnlocked||2,name:'bag'});
/** Occupied share of unlocked bag cells (0..1+). */
export function npcBagFill(profile,db){
 const unlocked=Math.max(1,Math.min(7,Number(profile?.bagsUnlocked)||2));let used=0;
 for(const i of profile?.inventory||[]){const d=db?.def?.(i.itemIndex);used+=Math.max(1,d?.w|0||1)*Math.max(1,d?.h|0||1);}
 return used/(unlocked*50);
}
/** Could this ground entry be added to the bag right now (read-only probe on a copy)? */
export function npcBagCanHold(world,p,entry){
 const db=world.data.itemDB;if(!db||entry?.kind!=='item')return true;
 if(npcBagFill(p.profile,db)<NPC_LOOT_POLICY.nearFullCells)return true;
 const bag=new Container([...(p.profile.inventory||[])],db,bagOptions(p));
 return bag.canAdd(entry.inst?{...entry.inst}:{itemIndex:Number(entry.itemIndex),count:Number(entry.count)||1,grade:entry.grade||'normal'});
}
export function npcLootEligible(world,p,b,d,now){
 // Same ownership rule the server enforces: own drop, or its protection expired (party owner chosen at drop time).
 if(!(d.ownerId===p.id||now>=d.protectedUntil))return false;
 const skip=b.lootSkip?.get(d.id);if(skip&&now<skip)return false;
 if(d.entry?.kind==='item'){
  if(now<(b.bagFullUntil||0))return false;
  // The near-full fit probe (~160 us) is memoized per bag shape + item for 5 s.
  const inv=p.profile.inventory||[],key=inv.length+':'+(inv.at(-1)?.uid||'')+':'+d.entry.itemIndex;let probe=b.bagProbe;
  if(!probe||probe.key!==key||now-probe.at>5000)probe=b.bagProbe={key,at:now,ok:npcBagCanHold(world,p,d.entry)};
  if(!probe.ok){b.bagFullUntil=now+NPC_LOOT_POLICY.bagFullMs;b.bagFullSeen=(b.bagFullSeen||0)+1;return false;}
 }
 return true;
}
export function npcLootRefused(b,d,error,now){
 const P=NPC_LOOT_POLICY,msg=String(error?.message||'');b.lootSkip||=new Map();
 for(const [id,until]of b.lootSkip)if(until<=now)b.lootSkip.delete(id);
 let ms=P.otherMs;
 if(/inventory is full/i.test(msg)){b.bagFullUntil=now+P.bagFullMs;b.bagFullSeen=(b.bagFullSeen||0)+1;ms=P.bagFullMs;}
 else if(/reserved for its owner/i.test(msg))ms=Math.max(P.busyMs,(Number(d.protectedUntil)||0)-now);
 else if(/already being picked up|party inventory changes/i.test(msg))ms=P.busyMs;
 if(b.lootSkip.size>=P.maxSkips)b.lootSkip.delete(b.lootSkip.keys().next().value);
 b.lootSkip.set(d.id,now+ms);b.lootRefusal={reason:msg.slice(0,60),at:now};
 return ms;
}
