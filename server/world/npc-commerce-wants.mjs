import {Equipment} from '../../src/systems/items/equip.js';
import {npcEquipmentBenefit} from './npc-builds.mjs';
import {commerceBuyBudget,nativeCommerceAnchor} from './npc-commerce-value.mjs';

// ENGINE-CHOSEN bounded shopping preference; never an item grant or native price.
export const NPC_GEAR_WANT_POLICY=Object.freeze({minimumBid:500000000,rawChunk:256,candidates:8,probes:2,retryMs:30000,globalMs:250});
const indexes=new WeakMap(),states=new WeakMap(),schedules=new WeakMap();
const slots=new Set(['weapon','offhand','helmet','armor','pants','glove','boots']);
const tier=d=>Number(d.reqLv)>=150||Number(d.itemLv)>=6||Number(d.rank)>=6;
const ordinary=d=>slots.has(d.slot)&&Number(d.trade)!==0&&!d.period&&!d.eventType&&!/^event/.test(String(d.src||''))&&tier(d);
/** Shared incremental raw-row index: no merged-def cache expansion or stat probes. */
export function prepareNpcGearWantIndex(db){
 if(indexes.has(db))return indexes.get(db).promise;
 const state={ready:false,classes:Array.from({length:15},()=>[]),scanned:0};indexes.set(db,state);
 function* rows(){for(const key in db.items)if(Object.hasOwn(db.items,key))yield key;}
 const iterator=rows();state.promise=new Promise(resolve=>{const chunk=()=>{for(let n=0;n<NPC_GEAR_WANT_POLICY.rawChunk;n++){const next=iterator.next();if(next.done){state.ready=true;resolve(state);return;}state.scanned++;const id=Number(next.value);if(!Number.isSafeInteger(id)||id>=900000000)continue;const raw=db.items[id],d={...db.defaults,...raw};if(!ordinary(d))continue;const anchor=Number(d.price)>0?Number(d.price):Number(d.sell);if(!Number.isSafeInteger(anchor)||anchor>10000000000||Math.floor(anchor*.7)<NPC_GEAR_WANT_POLICY.minimumBid)continue;for(let ci=0;ci<15;ci++)if((Number(d.classMask)>>>ci)&1)state.classes[ci].push(id);}setImmediate(chunk);};setImmediate(chunk);});return state.promise;
}
function current(world,p,id,eq){
 const db=world.data.itemDB,d=db.def(id);if(!d||!ordinary(d)||world.data.fishing?.rodItems?.[id]!=null)return null;
 if(d.slot==='weapon'&&Number(d.code)!==Number(world.data.classDef(p.profile.classIndex)?.weapon?.code))return null;
 if((p.profile.inventory||[]).some(i=>i.itemIndex===id)||Object.values(p.profile.equip?.items||{}).some(i=>i.itemIndex===id))return null;
 const maxPrice=Math.min(commerceBuyBudget(p.profile),Math.floor((nativeCommerceAnchor(db,{itemIndex:id})||0)*.7));if(maxPrice<NPC_GEAR_WANT_POLICY.minimumBid)return null;
 const item={itemIndex:id,count:1};const slot=eq.slotsFor(d).find(slot=>slot<100&&eq.check(item,slot,p.stats).ok);return slot==null?null:{itemIndex:id,count:1,maxPrice,slot,kind:'gear',provenance:'ENGINE-CHOSEN native eligible upgrade bid:70% native anchor capped by25% owned DIL'};
}
/** Advisories are invalidated by equipment/stat changes; exact offered instances
 * still run existing live native usefulness/ownership checks at every trade revision. */
export function npcGearWants(world,p){
 const db=world?.data?.itemDB;if(!db||p?.npcPlayer!==true||p.profile?.npcPlayer!==true||p.profile.authority!=='server'||p.dead||p.leaving||commerceBuyBudget(p.profile)<NPC_GEAR_WANT_POLICY.minimumBid)return [];
 prepareNpcGearWantIndex(db);const index=indexes.get(db);if(!index.ready)return [];
 let state=states.get(p);if(!state||state.db!==db){state={db,next:0,cursor:0,selected:null};states.set(p,state);}
 const fingerprint=JSON.stringify([p.profile.classIndex,p.profile.level,p.stats,p.profile.stats,p.profile.statPoints,p.profile.equip]);if(state.fingerprint!==fingerprint){state.selected=null;state.fingerprint=fingerprint;}
 const eq=new Equipment({db,game:{save:structuredClone(p.profile)}}),now=world.now();
 if(state.selected){const fresh=current(world,p,state.selected.itemIndex,eq);if(fresh&&now<state.next)return [fresh];state.selected=null;}
 if(now<state.next||now<(schedules.get(world)||0))return [];
 state.next=now+NPC_GEAR_WANT_POLICY.retryMs;schedules.set(world,now+NPC_GEAR_WANT_POLICY.globalMs);
 const ids=index.classes[p.profile.classIndex]||[];let best=null,probes=0;
 for(let n=0;n<Math.min(ids.length,NPC_GEAR_WANT_POLICY.candidates)&&probes<NPC_GEAR_WANT_POLICY.probes;n++){
  const id=ids[state.cursor++%ids.length],candidate=current(world,p,id,eq);if(!candidate)continue;probes++;
  const benefit=npcEquipmentBenefit(world,p,{itemIndex:id,count:1},{slot:candidate.slot});if(benefit?.benefit>0&&(!best||benefit.benefit>best.benefit))best={...candidate,benefit:benefit.benefit};
 }
 if(best){state.selected=best;return [current(world,p,best.itemIndex,eq)].filter(Boolean);}return [];
}
