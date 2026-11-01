import {cursorEntries} from '../../src/systems/items/cursor-custody.js';
const list=v=>Array.isArray(v)?v:[];
// Preserve duplicates for the caller's identity checks. Never deduplicate by UID:
// two copies of one UID are precisely the ownership failure being detected.
function descendants(items){const out=[];const visit=(item,ancestors)=>{if(!item)return;if(ancestors.has(item))throw Object.assign(Error('Cyclic item ownership.'),{status:400});out.push(item);const next=new Set(ancestors);next.add(item);for(const nested of list(item.pet?.inv))visit(nested,next);};for(const item of items)visit(item,new Set());return out;}
export function cursorOwnedItems(profile){return descendants(cursorEntries(profile).map(entry=>entry.item));}
export function ownedItems(profile){return descendants([
 ...list(profile.inventory),...list(profile.potionBelt),...list(profile.storage),...list(profile.cashInv),
 ...list(profile.costumeBag),...list(profile.accountFeatures?.shared),...Object.values(profile.equip?.items||{}),
 ...cursorEntries(profile).map(entry=>entry.item),
]);}
