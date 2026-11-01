// Potion belt owns ten real stacks. Legacy quickslot.belt contains references only.
import {Container} from './model.js';
export const BELT_SLOTS=10;
export function beltEligible(def){const u=def?.use;if(!u||def.slot)return false;return ['hp','hpPct','mp','mpPct','shield','shieldPct','stamina'].some(k=>Number(u[k])>0)||Number.isInteger(u.itemStatus)&&u.itemStatus>=0;}
export function beltEntry(save,slot){const item=save?.potionBelt?.find(e=>e.page===0&&e.x===slot&&e.y===0);return item?{...item,type:'item'}:null;}
export function potionBelt(profile,db){
  // References never become ownership. Existing bag stock stays unchanged on migration.
  profile.potionBelt||=[];
  if(!Array.isArray(profile.potionBelt))throw Error('Invalid potion belt ownership.');
  const slots=new Set(),uids=new Set();for(const e of profile.potionBelt){if(!e||typeof e.uid!=='string'||uids.has(e.uid)||e.page!==0||e.y!==0||!Number.isInteger(e.x)||e.x<0||e.x>=BELT_SLOTS||slots.has(e.x)||!Number.isInteger(e.count)||e.count<1||e.count>db.stackSize(db.def(e.itemIndex))||!beltEligible(db.def(e.itemIndex)))throw Error('Invalid potion belt ownership.');slots.add(e.x);uids.add(e.uid);}
  // Only list-shaped containers own items; preserved foreign/legacy shapes must not fail a world join.
  const list=v=>Array.isArray(v)?v:[];
  const other=[...list(profile.inventory),...list(profile.storage),...list(profile.cashInv),...list(profile.costumeBag),...Object.values(profile.equip?.items||{}),...list(profile.accountFeatures?.shared),...(profile.itemCursor?.item?[profile.itemCursor.item]:[]),...list(profile.itemCursor?.pending).map(entry=>entry.item)];if(other.some(e=>e&&uids.has(e.uid)))throw Error('Duplicate potion belt item identity.');
  const belt=new Container(profile.potionBelt,db,{pages:1,cols:BELT_SLOTS,rows:1,accept:beltEligible,name:'potion belt'});belt.size=()=>[1,1];return belt;
}
