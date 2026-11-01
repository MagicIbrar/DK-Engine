import {gmInventoryRevision} from '../accounts/gm-transfers.mjs';
import {ownedItems} from './item-ownership.mjs';
import {cursorEntries} from '../../src/systems/items/cursor-custody.js';
import { WorldError } from './core.mjs';
import { characterRef } from '../accounts/character-ref.mjs';

const fail = (status, message) => { throw new WorldError(status, message); };
const ITEM_KEYS = ['uid','itemIndex','name','count','grade','rnd','sockets','brand','crest','bound','expiresAt','page','x','y','durability','maxDurability','appearance','appearanceExpiresAt','shape','customId'];
function item(value) {
  if (!value || typeof value !== 'object' || !Number.isFinite(value.itemIndex)) return null;
  return Object.fromEntries(ITEM_KEYS.filter(k => Object.hasOwn(value, k)).map(k => [k, structuredClone(value[k])]));
}
const items = values => (Array.isArray(values) ? values : []).map(item).filter(Boolean);
export function inventoryView(profile) {
  const equip = profile.equip || {};
  const owned=ownedItems(profile);
  return {
    inventory: items(profile.inventory), storage: items(profile.storage), costumeBag: items(profile.costumeBag),
    cash: items(profile.cashInv), shared: items(profile.accountFeatures?.shared),
    cursor: cursorEntries(profile).map(entry=>({item:item(entry.item),origin:structuredClone(entry.origin)})),
    pets: owned.flatMap(pet => items(pet.pet?.inv).map(value => ({...value,petName:pet.pet.name||pet.name||String(pet.itemIndex)}))),
    equip: { active: equip.active || 0, presets: structuredClone(equip.presets || []), items: Object.fromEntries(Object.entries(equip.items || {}).map(([uid, value]) => [uid, item(value)]).filter(([,value]) => value)) },
    dil: Number(profile.dil) || 0, stashDil: Number(profile.stashDil) || 0, sharedDil: Number(profile.accountFeatures?.sharedDil) || 0,
    bagUnlocked: profile.bagsUnlocked || 2, stashUnlocked: profile.stashUnlocked || 2,
  };
}
export async function inventoryGM(world, user, input) {
  if (!user.capabilities?.includes('gm:commands')) fail(403, 'GM permission is required to inspect inventories.');
  const operator = world.lease(user.id, input.token), now = world.now();
  if (now - (operator.inventoryReadAt || 0) >= 1000) { operator.inventoryReadAt = now; operator.inventoryReads = 0; }
  if ((operator.inventoryReads = (operator.inventoryReads || 0) + 1) > 10) fail(429, 'Wait a moment before refreshing the inventory viewer.');
  const allowed = input.operation === 'characterDirectory' ? ['token','operation','query','offset'] : ['token','operation','ref','targetId'];
  if (Object.keys(input).some(key => !allowed.includes(key))) fail(400, 'Unexpected inventory viewer fields.');
  const live = [...world.players.values()].filter(p => !p.leaving);
  if (input.operation === 'characterDirectory') {
    if (input.query != null && (typeof input.query !== 'string' || input.query.length > 80)) fail(400, 'Use a character name to search.');
    const offset = input.offset ?? 0;
    if (!Number.isInteger(offset) || offset < 0 || offset > 1000000) fail(400, 'Invalid character page.');
    if (!world.listCharacters) fail(503, 'Character directory is unavailable.');
    const roster = new Map((await world.listCharacters()).map(c => [c.ref, {...c, online:false}]));
    for (const p of live) { const ref=characterRef(p.account,p.characterId); roster.set(ref,{ref,name:p.profile.name,classIndex:p.profile.classIndex,level:p.profile.level,map:p.map,lastPlayed:world.now(),online:true}); }
    const query=(input.query || '').trim().toLowerCase();
    const rows=[...roster.values()].filter(c => !query || c.name.toLowerCase().includes(query)).sort((a,b)=>Number(b.online)-Number(a.online)||a.name.localeCompare(b.name)||a.ref.localeCompare(b.ref));
    return {characters:rows.slice(offset,offset+100),total:rows.length,offset,serverTime:world.now()};
  }
  if (input.operation !== 'inspectInventory') fail(400,'Unknown inventory viewer operation.');
  if ((input.ref == null) === (input.targetId == null)) fail(400,'Choose one character.');
  if (input.ref != null && (typeof input.ref !== 'string' || !/^[a-f0-9]{64}$/.test(input.ref))) fail(400,'Invalid character reference.');
  if (input.targetId != null && (typeof input.targetId !== 'string' || input.targetId.length > 160)) fail(400,'Invalid player target.');
  const target=live.find(p => input.targetId ? p.id === input.targetId : characterRef(p.account,p.characterId) === input.ref);
  const profile=target?.profile || (input.ref && await world.inspectCharacter?.(input.ref));
  if (!profile) fail(404,'This character is no longer available.');
  const ref=target ? characterRef(target.account,target.characterId) : input.ref;
  return {revision:gmInventoryRevision(profile,target?.token),destinationRevision:gmInventoryRevision(operator.profile,operator.token),character:{ref,name:profile.name,level:profile.level,classIndex:profile.classIndex,map:target?.map ?? profile.map,online:!!target,stats:structuredClone(target?.stats || world.data.stats(structuredClone(profile)))},contents:inventoryView(profile),serverTime:world.now()};
}
