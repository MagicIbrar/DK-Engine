// ENGINE-CHOSEN bag-pressure planning. Uses only the existing player actions
// (`shopsell` via npcSalePlan, `storage` deposit at a placed Storage NPC) with
// their normal server validation. Nothing is destroyed, discarded or created.
import {Container} from '../../src/systems/items/model.js';
import {npcPlacements} from './npc-services.mjs';
import {protectedNpcEquipmentUids} from './npc-equipment-ownership.mjs';
import {npcBagFill} from './npc-loot.mjs';
export const NPC_BAG_POLICY=Object.freeze({pressure:0.85,full:0.95,retryMs:20000});
export function npcBagPressure(world,p){const fill=npcBagFill(p.profile,world.data.itemDB);return {fill,pressure:fill>=NPC_BAG_POLICY.pressure,full:fill>=NPC_BAG_POLICY.full};}
/** Deposit one spare (unequipped, unreserved) gear piece at a Storage NPC on this map when the bag is full. */
export function npcStoragePlan(world,p,{reservedUids=new Set()}={}){
 const db=world.data.itemDB;if(!db||p.instanceId)return null;
 // Same deposit fee the storage action charges (formula stStorageCostPerUnit, default 10): no plan with depleted currency.
 const fee=Number(db.equipment?.formula?.stStorageCostPerUnit)||10;if((Number(p.profile.dil)||0)<fee)return null;
 const stores=npcPlacements(world,p.map).filter(r=>r.roles?.includes('STORAGE')&&Number.isFinite(r.x)&&Number.isFinite(r.z));if(!stores.length)return null;
 const prot=protectedNpcEquipmentUids(world,p),keep=new Set([...(p.profile.npcMarketShowcase?.version===1?p.profile.npcMarketShowcase.uids:[]),...(p.profile.npcInitialMarketStock?.version===1?p.profile.npcInitialMarketStock.uids:[]),...(p.profile.npcSeed?.stock?.uids||[])]);
 const stash=new Container([...(p.profile.storage||[])],db,{pages:4,cols:10,rows:10,unlocked:()=>p.profile.stashUnlocked||2});
 const item=(p.profile.inventory||[]).find(i=>{const d=db.def(i.itemIndex);return !!d?.slot&&!reservedUids.has(i.uid)&&!keep.has(i.uid)&&!prot.has(i.uid)&&!i.npcStartingStock&&!i.expiresAt&&!d.period&&stash.canAdd({...i});});
 if(!item)return null;
 const at=stores.sort((a,b)=>Math.hypot(p.x-a.x,p.z-a.z)-Math.hypot(p.x-b.x,p.z-b.z))[0];
 return {at:{map:p.map,x:at.x,z:at.z,npc:at.npcIndex},serviceAt:{map:p.map,x:at.x,z:at.z,npc:at.npcIndex},near:Math.hypot(p.x-at.x,p.z-at.z)<=12,action:{type:'storage',uid:item.uid,direction:'deposit'},uid:item.uid,stage:'store'};
}
