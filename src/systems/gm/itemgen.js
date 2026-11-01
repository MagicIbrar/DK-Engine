// Item generator (docs/formats/gmcommands.md §6.3 / §6.9): any item with grade, +N upgrade, sockets (with socket
// stones), up to 6 random options and a count, created through the items system's API (docs/done/items.json:
// game.items.create / add; instances {itemIndex, count, grade, rnd:[[optType, value]], sockets:[0|stone], bound}).
//   * +N: every upgrade level is its own item record chained by def.next / def.prev (itemLv); the generator walks the
//     chain (the same rule as the Reinforce window's indexAtLevel).
//   * options: itemoption_{weapon,armor,accessory}.csv rows (gmcommands_items options) -> option type code through
//     items-options.json optionTypes (by name); the value is clamped to the row's min..max unless `free` is set.
//   * count: stackables fill stacks (the bag splits them), other items are created one instance each.
//   * destination: bag (overflow dropped at the feet, the original rule), ground, or the cash inventory.
import { gmData } from './data.js';
import { rollOptions } from '../items/model.js';

export const GRADES = ['normal', 'magic', 'noble', 'divine'];
function onlineSpec(db,spec){const next={...spec};next.item=Number(spec.item?.id??spec.item);next.options=(spec.options||[]).map(([row,value])=>{const raw=row?.raw||row,code=typeof row==='number'?row:Number.isFinite(Number(raw.code))?Number(raw.code):optionCode(db,raw.type);let val=Number(value);if(!spec.free&&Number.isFinite(Number(raw.min))&&Number.isFinite(Number(raw.max)))val=Math.max(Number(raw.min),Math.min(Number(raw.max),val));return [code,val];});if(Array.isArray(next.sockets))next.sockets=next.sockets.map(i=>Number(i?.id??i)||0);for(const key of Object.keys(next))if(next[key]==null||key==='item'&&!Number.isFinite(next.item))delete next[key];return next;}
async function onlineItem(game,operation,spec,uid){try{const network=game.network;if(!network?.ready||!network.token)return {ok:false,message:'Wait for the shared world connection.'};const token=network.token,generation=network._leaseGeneration;const result=await network._request('gm',{token,operation,spec:onlineSpec(game.items.db,spec),...(uid?{uid}:{})});if(game.network!==network||network.token!==token||network._leaseGeneration!==generation||!network.ready||network.disposed)throw new Error('The GM session changed. Reconnect and retry.');if(result.state)network._receiveSnapshot(result.state);return result;}catch(error){return {ok:false,message:error.message};}}

/** The +0 .. +N chain of an item: [{lv, index, name}]. */
export function upgradeChain(db, index) {
  let d = db?.def(index);
  if (!d) return [];
  let guard = 0;
  while (d.prev && db.def(d.prev) && (Number(db.def(d.prev).itemLv) || 0) < (Number(d.itemLv) || 0) && guard++ < 60) d = db.def(d.prev);
  const out = [];
  const seen = new Set();
  while (d && !seen.has(d.index) && out.length < 60) {
    seen.add(d.index);
    out.push({ lv: Number(d.itemLv) || 0, index: d.index, name: d.name });
    const n = d.next ? db.def(d.next) : null;
    if (!n || (Number(n.itemLv) || 0) <= (Number(d.itemLv) || 0)) break;
    d = n;
  }
  return out;
}

/** Item index at +lv (nearest level on the chain). */
export function indexAtLevel(db, index, lv) {
  const ch = upgradeChain(db, index);
  if (!ch.length) return Number(index);
  let best = ch[0];
  for (const c of ch) if (c.lv <= lv) best = c;
  return best.index;
}

/** option type name -> code (items-options.json optionTypes). */
let _codes = null;
export function optionCode(db, name) {
  if (!_codes) {
    _codes = new Map();
    for (const [code, t] of Object.entries(db?.options?.optionTypes || {})) if (t?.name && !_codes.has(t.name)) _codes.set(t.name, Number(code));
  }
  return _codes.get(String(name)) ?? null;
}

/** Which option table fits an item: weapon / armor / accessory (or null). */
export function optionTableOf(db, def, row = null) {
  const t = String(row?.raw?.table || '').toLowerCase();
  if (t === 'weapon' || t === 'armor' || t === 'accessory') return t;
  if (!def) return null;
  if (Number(def.type) === 4) return 'weapon';
  if (Number(def.type) === 2) return 'accessory';
  if (Number(def.type) === 1 || def.slot) return 'armor';
  return null;
}

/** Describe an item for the generator: def, chain, stack, footprint, option table, box contents. */
export async function describeItem(game, index) {
  const db = game.items?.db;
  const rows = await gmData.list('items');
  const row = rows.byId.get(String(index)) || null;
  const def = db?.def(index) || null;
  const chain = db ? upgradeChain(db, index) : [];
  const cur = def ? (Number(def.itemLv) || 0) : 0;
  return {
    index: Number(index), row, def,
    name: def?.name || row?.name || `Item ${index}`,
    chain, level: cur, maxUpgrade: chain.length ? chain[chain.length - 1].lv : 0,
    stack: db && def ? db.stackSize(def) : Math.max(1, Number(row?.raw?.stack) || 1),
    w: Number(def?.w) || 1, h: Number(def?.h) || 1,
    equip: !!def?.slot, table: optionTableOf(db, def, row),
    reqLv: def?.reqLv ?? row?.raw?.reqLv, rank: def?.rank ?? row?.raw?.rank,
    kind: db && def ? db.kindName(def) : '', rankName: db && def ? db.rankName(def) : '',
    box: game.boxes?.isBox?.(index) ? game.boxes.info(index) : null,
    loadable: !!def,
  };
}

/**
 * Create and deliver items. spec:
 *   { item, count=1, upgrade=null (+N), grade='normal', sockets=0 | [stoneIndex|0...], options=[[optionRow|{type,min,max}|code, value]],
 *     brand=[[code,value]], bound=false, to='bag'|'ground'|'cash', free=false (no min..max clamp), roll=false }
 * Returns { ok, created: [inst], placed, dropped, message }.
 */
export async function makeItem(game, spec) {
  const sys = game.items;
  if (!sys?.db) return { ok: false, message: 'The items system is not ready.' };
  await sys.ready;
  if(game.save.authority==='server')return onlineItem(game,'makeItem',spec);
  const db = sys.db;
  let index = Number(spec.item?.id ?? spec.item);
  if (!db.def(index)) return { ok: false, message: `Item ${index} is not in the item tables (item.dat / csv).` };
  if (spec.upgrade != null && spec.upgrade !== '') index = indexAtLevel(db, index, Number(spec.upgrade) || 0);
  const def = db.def(index);
  const grade = GRADES.includes(spec.grade) ? spec.grade : 'normal';
  // options -> rnd [[code, value]]
  const rnd = [];
  for (const o of spec.options || []) {
    if (!o) continue;
    const [opt, val] = o;
    let code = null, min = -Infinity, max = Infinity;
    if (typeof opt === 'number') code = opt;
    else {
      const r = opt?.raw || opt;
      code = Number.isFinite(Number(r?.code)) ? Number(r.code) : optionCode(db, r?.type);
      min = Number(r?.min); max = Number(r?.max);
    }
    if (code == null) continue;
    let v = Number(val);
    if (!Number.isFinite(v)) v = Number.isFinite(max) ? max : 1;
    if (!spec.free && Number.isFinite(min) && Number.isFinite(max) && max >= min) v = Math.max(min, Math.min(max, v));
    rnd.push([code, v]);
  }
  let sockets = spec.sockets;
  if (Array.isArray(sockets)) sockets = sockets.slice(0, 4).map(s => Number(s?.id ?? s) || 0);
  else sockets = Math.max(0, Math.min(4, Number(sockets) || 0));
  const count = Math.max(1, Math.floor(Number(spec.count) || 1));
  const stack = db.stackSize(def);
  const opts = { grade, rnd: rnd.length ? rnd : undefined, sockets, bound: !!spec.bound, roll: spec.roll !== false && !rnd.length };
  if (spec.brand?.length) opts.brand = spec.brand;
  const insts = [];
  if (stack > 1) insts.push(sys.create(index, { ...opts, count }));
  else for (let k = 0; k < count; k++) insts.push(sys.create(index, { ...opts, count: 1 }));
  const created = insts.filter(Boolean);
  if (!created.length) return { ok: false, message: `Cannot create item ${index}.` };
  let placed = 0, dropped = 0;
  const to = spec.to || 'bag';
  for (const inst of created) {
    if (to === 'cash') { sys.add(inst, { to: 'cash', source: 'gm', silent: true }); placed += inst.count || 1; continue; }
    if (to === 'ground') {
      const p = game.player;
      const a = Math.random() * Math.PI * 2, rr = 0.6 + Math.random() * 1.2;
      game.loot?.spawnDrop?.({ kind: 'item', itemIndex: inst.itemIndex, name: inst.name, count: inst.count, grade: inst.grade, inst }, p.x + Math.cos(a) * rr, p.z + Math.sin(a) * rr);
      dropped += inst.count || 1;
      continue;
    }
    const want = inst.count || 1;
    const r = sys.add(inst, { dropLeft: true, source: 'gm', silent: true });
    placed += want - (r.left || 0);
    dropped += r.left || 0;
  }
  game.events?.emit?.('gm:item', { index, count, grade, to });
  const name = def.name;
  const where = to === 'cash' ? 'Cash Inventory' : to === 'ground' ? 'the ground' : 'the inventory';
  return {
    ok: true, created, placed, dropped, index,
    message: `${name}${count > 1 ? ` x${count}` : ''}${grade !== 'normal' ? ` [${grade}]` : ''}${rnd.length ? ` +${rnd.length} opt` : ''}${(Array.isArray(sockets) ? sockets.length : sockets) ? ` ${Array.isArray(sockets) ? sockets.length : sockets} sockets` : ''} -> ${where}${dropped && to === 'bag' ? ` (${dropped} dropped at your feet: bag full)` : ''}`,
  };
}

/** Edit an existing instance in place: {upgrade, grade, sockets, options, count, bound}. */
export async function editItem(game, inst, patch) {
  const sys = game.items, db = sys?.db;
  if (!inst || !db) return false;
  if(game.save.authority==='server'){const result=await onlineItem(game,'editItem',patch,inst.uid);if(!result.ok)game.gm?.say?.(result.message,'ffff5a45');return !!result.ok;}
  if (patch.upgrade != null) {
    const ni = indexAtLevel(db, inst.itemIndex, Number(patch.upgrade) || 0);
    const d = db.def(ni);
    if (d) { inst.itemIndex = ni; inst.name = d.name; }
  }
  if (patch.grade && GRADES.includes(patch.grade)) inst.grade = patch.grade;
  if (patch.sockets != null) {
    const s = Array.isArray(patch.sockets) ? patch.sockets.slice(0, 4).map(v => Number(v?.id ?? v) || 0) : new Array(Math.max(0, Math.min(4, Number(patch.sockets) || 0))).fill(0);
    if (s.length) inst.sockets = s; else delete inst.sockets;
  }
  if (patch.options) {
    const rnd = [];
    for (const [opt, val] of patch.options) {
      const r = opt?.raw || opt;
      const code = typeof opt === 'number' ? opt : Number.isFinite(Number(r?.code)) ? Number(r.code) : optionCode(db, r?.type);
      if (code != null && Number.isFinite(Number(val))) rnd.push([code, Number(val)]);
    }
    if (rnd.length) inst.rnd = rnd; else delete inst.rnd;
  }
  if (patch.roll !== false && db.def(inst.itemIndex)?.slot && inst.grade !== 'normal' && !inst.rnd?.length) inst.rnd = rollOptions(db.def(inst.itemIndex), inst.grade, db);
  if (patch.count != null) {
    const st = db.stackSize(db.def(inst.itemIndex));
    inst.count = Math.max(1, Math.min(st > 1 ? st : 1, Math.floor(Number(patch.count) || 1)));
  }
  if (patch.bound != null) { if (patch.bound) inst.bound = true; else delete inst.bound; }
  const where = sys.where(inst);
  sys.changed(where === 'equip' ? 'equip' : 'upgrade', { item: inst });
  return true;
}

/** Every item instance the character owns: [{inst, where, label}] (bag, equipment, stash, costume bag, cash). */
export function ownedItems(game) {
  const sys = game.items;
  if (!sys?.bag) return [];
  const out = [];
  for (const [where, c] of [['bag', sys.bag], ['stash', sys.stash], ['costume', sys.costumeBag]]) for (const inst of c.list) out.push({ inst, where });
  for (const inst of Object.values(sys.equip?.data?.items || {})) if (sys.equip.isEquipped?.(inst.uid)) out.push({ inst, where: 'equip' });
  for (const inst of game.save.cashInv || []) out.push({ inst, where: 'cash' });
  return out.map(o => ({ ...o, label: `${o.inst.name || sys.name(o.inst.itemIndex)}${o.inst.count > 1 ? ` x${o.inst.count}` : ''} [${o.where}${o.where === 'bag' ? ` ${(o.inst.page | 0) + 1}` : ''}]` }));
}
