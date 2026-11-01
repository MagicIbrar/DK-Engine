// Item instances and grid containers (bags, stash, cash inventory, costume bag) of the items system.
// Pure logic (no DOM, no three.js): tools/test-items.mjs runs it under node.
//
// Instance: { uid, itemIndex, name, count, grade ('normal'|'magic'|'noble'|'divine'), rnd [[optType, value]..]
//             (rank options), sockets [0 | stoneItemIndex ..] (length = socket count), brand [[optType, value]..],
//             crest {item, options [[optType, value]..]} | null, bound (bool), expiresAt (ms epoch, 0 = never),
//             page, x, y (cell of its top-left corner inside its container) }
// The +N level is the item index itself (items.md 6.1).
//
// Container: a list of pages of cols x rows cells over a flat array (the save array itself). Each item occupies
// its w x h footprint (items.json w/h). Placement/overlap/swap/stack rules follow the original bag: an item moves to
// any free footprint; dropping it on exactly one other item swaps the two when the other one fits where the first
// came from; dropping a stack on a stack of the same item merges up to the stack size.

export const GRADES = ['normal', 'magic', 'noble', 'divine'];
let seq = 0;
export function newUid() { return `i${Date.now().toString(36)}${(++seq).toString(36)}${Math.floor(Math.random() * 46656).toString(36)}`; }

const rint = (rng, a, b) => { a = Math.round(a); b = Math.round(b); if (b < a) [a, b] = [b, a]; return a + Math.floor(rng() * (b - a + 1)); };

/** Does this instance carry per-instance data (then it never stacks)? */
export function isUnique(inst) {
  return !!((inst.rnd && inst.rnd.length) || (inst.sockets && inst.sockets.length) || (inst.brand && inst.brand.length) || inst.crest || inst.expiresAt);
}

/** Can two instances share a stack? */
export function canStack(a, b, db) {
  if (!a || !b || a === b || a.itemIndex !== b.itemIndex) return false;
  const def = db.def(a.itemIndex);
  if (db.stackSize(def) <= 1) return false;
  if ((a.grade || 'normal') !== (b.grade || 'normal') || !!a.bound !== !!b.bound) return false;
  return !isUnique(a) && !isUnique(b);
}

/**
 * Rank options: magic two, noble three, divine four. Options 1-2 use the first
 * authored pool, option 3 the second and option 4 the third (Global: the UBIFUN item pages label MinOption1..3
 * as "1st or 2nd", "3rd" and "4th Option", and Create/Remove Option shows the same). Every grade uses the
 * authored MinData..MaxData range; nothing in itemoption.dat grants Divine Noble automatic maximum values.
 */
export function rollOptions(def, grade, db, rng = Math.random) {
  const pools = db.options?.pools || {};
  const slots = def?.optionPools || [];
  let n = 0;
  if (grade === 'magic') n = 2;
  else if (grade === 'noble') n = 3;
  else if (grade === 'divine') n = 4;
  const out = [];
  for (let k = 0; k < n && slots.length; k++) {
    const [lo, hi] = slots[Math.min([0, 0, 1, 2][k] ?? 2, slots.length - 1)] || [0, 0];
    if (!(hi > 0)) continue;
    const level = rint(rng, lo || hi, hi);
    const rows = pools[level];
    if (!rows || !rows.length) continue;
    const row = rows[Math.floor(rng() * rows.length)];
    const [, type, min, max] = row;
    const v = rint(rng, min, max);
    if (type != null && v) out.push([Number(type), v]);
  }
  return out;
}

/** Socket count from the item's socketRates (percent chance of 1/2/3/4 sockets), optionally forced. */
export function rollSockets(def, rng = Math.random, extra = 0) {
  const r = def?.socketRates || [0, 0, 0, 0];
  if (!(r[0] || r[1] || r[2] || r[3])) return 0;
  const x = rng() * 100;
  let acc = 0;
  for (let k = 3; k >= 0; k--) { acc += Number(r[k]) || 0; if (x < acc) return k + 1; }
  return Math.max(0, Math.min(4, extra | 0));
}

/**
 * New item instance. opts: {count, grade, rnd, sockets (count or array), brand, crest, bound, roll (roll options
 * and sockets from the tables), rng, now}.
 */
/** Source-backed rarity for new grants; never rewrite saved bonus pairs. */
export function canonicalItemGrade(db,def,grade,opts={}) {
 if(!GRADES.includes(grade)||!def?.slot||def.slot==='vehicle'||db.stackSize(def)>1)return 'normal';
 if(grade==='normal'||(opts.rnd?.length&&opts.rnd.every(o=>Array.isArray(o)&&o.length===2&&Number.isInteger(o[0])&&db.optionType(o[0])&&Number.isFinite(o[1])))||Number(def?.index)>=900000000)return grade;
 const supported=def?.optionPools?.some(([lo,hi])=>{for(let level=lo||hi;level>0&&level<=hi;level++)if(db.options?.pools?.[level]?.length)return true;return false;});
 return def?.slot&&supported?grade:'normal';
}
export function createItem(db, itemIndex, opts = {}) {
  const def = db.def(itemIndex);
  if (!def) return null;
  const rng = opts.rng || Math.random;
  const grade = canonicalItemGrade(db,def,opts.grade,opts);
  const inst = { uid: newUid(), itemIndex: Number(itemIndex), name: def.name, count: Math.max(1, Math.floor(opts.count || 1)), grade };
  const stack = db.stackSize(def);
  if (stack <= 1) inst.count = 1;   // stackables may exceed one stack: Container.add splits them
  const equip = !!def.slot;
  if (equip && grade !== 'normal') inst.rankOptionsVersion = 1;
  if (opts.rnd) inst.rnd = opts.rnd.map(o => [Number(o[0]), Number(o[1])]);
  else if (opts.roll !== false && equip && grade !== 'normal') inst.rnd = rollOptions(def, grade, db, rng);
  if (Array.isArray(opts.sockets)) inst.sockets = opts.sockets.slice(0, 4).map(v => Number(v) || 0);
  else if (Number.isFinite(opts.sockets) && opts.sockets > 0) inst.sockets = new Array(Math.min(4, opts.sockets)).fill(0);
  else if (opts.roll && equip) { const n = rollSockets(def, rng); if (n) inst.sockets = new Array(n).fill(0); }
  if (opts.brand?.length) inst.brand = opts.brand.map(o => [Number(o[0]), Number(o[1])]);
  if (opts.crest) inst.crest = opts.crest;
  if (opts.bound || Number(def.belong) === 1 && opts.bindOnPickup) inst.bound = true;
  if (def.period > 0) inst.expiresAt = (opts.now ?? Date.now()) + def.period * 1000;
  if (!inst.rnd?.length) delete inst.rnd;
  if (!inst.sockets?.length) delete inst.sockets;
  return inst;
}

/** Repair only legacy coloured equipment with no stats; never reroll existing options. */
export function repairLegacyRankOptions(profile, db, rng = Math.random) {
  let repaired = 0;
  const items = [...(profile.inventory || []), ...(profile.storage || []), ...(profile.cashInv || []), ...(profile.costumeBag || []), ...Object.values(profile.equip?.items || {})];
  for (const inst of items) {
    const def = db.def(inst?.itemIndex);
    if (!def?.slot || !GRADES.includes(inst.grade) || inst.grade === 'normal' || inst.rankOptionsVersion) continue;
    if (!inst.rnd?.length) { const options = rollOptions(def, inst.grade, db, rng); if (options.length) { inst.rnd = options; repaired++; } }
    inst.rankOptionsVersion = 1;
  }
  return repaired;
}

/** A copy of an instance with a new uid (split stacks, clones). */
export function cloneItem(inst, patch = {}) {
  const c = JSON.parse(JSON.stringify(inst));
  c.uid = newUid();
  return Object.assign(c, patch);
}

// ------------------------------------------------------------------------------------------ containers
export class Container {
  /**
   * @param {object[]} list    the save array holding the instances (mutated in place)
   * @param {object} db        ItemDB (w/h/stack of items)
   * @param {{pages:number, cols:number, rows:number, unlocked?:()=>number, accept?:(def)=>boolean, name?:string}} o
   */
  constructor(list, db, o) {
    this.list = list;
    this.db = db;
    this.pages = o.pages || 1;
    this.cols = o.cols;
    this.rows = o.rows;
    this.unlockedFn = o.unlocked || (() => this.pages);
    this.accept = o.accept || (() => true);
    this.name = o.name || 'bag';
    this.locked = false;          // "lock item movement" (btn_LockBag)
    this.onChange = null;         // (reason) => void
  }
  get unlocked() { return Math.max(1, Math.min(this.pages, this.unlockedFn() | 0)); }
  size(inst) { const d = this.db.def(inst.itemIndex); return [Math.max(1, d?.w | 0 || 1), Math.max(1, d?.h | 0 || 1)]; }
  sizeOf(itemIndex) { const d = this.db.def(itemIndex); return [Math.max(1, d?.w | 0 || 1), Math.max(1, d?.h | 0 || 1)]; }
  items(page) { return page == null ? this.list : this.list.filter(i => (i.page | 0) === page); }
  changed(reason) { try { this.onChange?.(reason); } catch (err) { console.error('[items] container onChange', err); } }

  /** Items overlapping the rect on a page (excluding `ignore`). */
  occupants(page, x, y, w, h, ignore = null) {
    const ig = Array.isArray(ignore) ? ignore : ignore ? [ignore] : [];
    const out = [];
    for (const it of this.list) {
      if ((it.page | 0) !== page || ig.includes(it)) continue;
      const [iw, ih] = this.size(it);
      if (x < it.x + iw && it.x < x + w && y < it.y + ih && it.y < y + h) out.push(it);
    }
    return out;
  }
  inside(x, y, w, h) { return x >= 0 && y >= 0 && x + w <= this.cols && y + h <= this.rows; }
  fits(page, x, y, w, h, ignore = null) {
    return page >= 0 && page < this.unlocked && this.inside(x, y, w, h) && this.occupants(page, x, y, w, h, ignore).length === 0;
  }
  /** First free footprint (row by row, left to right) in the given page or in every unlocked page. */
  findSpot(w, h, { page = null, ignore = null, from = 0 } = {}) {
    const pages = page != null ? [page] : [...Array(this.unlocked).keys()].slice(from).concat([...Array(this.unlocked).keys()].slice(0, from));
    for (const p of pages) {
      if (p >= this.unlocked) continue;
      for (let y = 0; y + h <= this.rows; y++) for (let x = 0; x + w <= this.cols; x++) if (this.fits(p, x, y, w, h, ignore)) return { page: p, x, y };
    }
    return null;
  }
  find(pred) { return this.list.find(pred) || null; }
  byUid(uid) { return this.list.find(i => i.uid === uid) || null; }
  count(itemIndex) { let n = 0; for (const i of this.list) if (i.itemIndex === Number(itemIndex)) n += i.count || 1; return n; }

  /** Could `count` of an item (or an instance) be added without losing anything? */
  canAdd(instOrIndex, count = null) {
    const probe = typeof instOrIndex === 'object' ? instOrIndex : { itemIndex: Number(instOrIndex), count: count || 1, grade: 'normal' };
    const def = this.db.def(probe.itemIndex);
    if (!def || !this.accept(def)) return false;
    let left = count ?? probe.count ?? 1;
    const stack = this.db.stackSize(def);
    if (stack > 1) for (const it of this.list) if (!it._probe && canStack(it, probe, this.db)) left -= Math.max(0, stack - (it.count || 1));
    if (left <= 0) return true;
    // simulate placements with temporary blockers
    const [w, h] = this.sizeOf(probe.itemIndex);
    const temp = [];
    try {
      while (left > 0) {
        const s = this.findSpot(w, h);
        if (!s) return false;
        const t = { itemIndex: probe.itemIndex, count: 1, page: s.page, x: s.x, y: s.y, _probe: true };
        this.list.push(t); temp.push(t);
        left -= stack;
      }
      return true;
    } finally { for (const t of temp) this.list.splice(this.list.indexOf(t), 1); }
  }

  /**
   * Add an instance (stacks merge first, then free spots). opts: {page, x, y (exact spot), noStack}.
   * Returns {ok, placed: [inst...], left} where left = count that did not fit (inst.count is updated).
   */
  add(inst, opts = {}) {
    const def = this.db.def(inst.itemIndex);
    if (!def || !this.accept(def)) return { ok: false, placed: [], left: inst.count || 1 };
    const placed = [];
    const stack = this.db.stackSize(def);
    let left = inst.count || 1;
    if (stack > 1 && !opts.noStack && opts.x == null) {
      for (const it of this.list) {
        if (left <= 0) break;
        if (!canStack(it, inst, this.db)) continue;
        const room = Math.max(0, stack - (it.count || 1));
        const n = Math.min(room, left);
        if (n > 0) { it.count = (it.count || 1) + n; left -= n; if (!placed.includes(it)) placed.push(it); }
      }
    }
    const [w, h] = this.size(inst);
    let first = true;
    while (left > 0) {
      let spot = null;
      if (first && opts.x != null && this.fits(opts.page | 0, opts.x, opts.y, w, h)) spot = { page: opts.page | 0, x: opts.x, y: opts.y };
      else spot = this.findSpot(w, h, { page: opts.page ?? null });
      if (!spot && opts.page != null) spot = this.findSpot(w, h);
      if (!spot) break;
      const n = Math.min(left, stack);
      const piece = first && n === left ? inst : { ...JSON.parse(JSON.stringify(inst)), uid: newUid() };
      piece.count = n;
      Object.assign(piece, spot);
      this.list.push(piece);
      placed.push(piece);
      left -= n;
      first = false;
    }
    if (left > 0 && placed.length === 0) inst.count = left;
    else if (left > 0) inst.count = left;
    if (placed.length) this.changed('add');
    return { ok: left === 0, placed, left };
  }

  /** Take an instance out (whole, or `count` of a stack: returns the removed part as its own instance). */
  take(inst, count = null) {
    const i = this.list.indexOf(inst);
    if (i < 0) return null;
    const n = count == null ? (inst.count || 1) : Math.min(count, inst.count || 1);
    if (n >= (inst.count || 1)) { this.list.splice(i, 1); this.changed('remove'); return inst; }
    inst.count -= n;
    const part = { ...JSON.parse(JSON.stringify(inst)), uid: newUid(), count: n };
    delete part.page; delete part.x; delete part.y;
    this.changed('remove');
    return part;
  }

  /** Remove `count` of an item index (stacks with the fewest first). Returns how many were removed. */
  removeIndex(itemIndex, count) {
    let left = count;
    const list = this.list.filter(i => i.itemIndex === Number(itemIndex)).sort((a, b) => (a.count || 1) - (b.count || 1));
    for (const it of list) {
      if (left <= 0) break;
      const n = Math.min(left, it.count || 1);
      this.take(it, n);
      left -= n;
    }
    return count - left;
  }

  /**
   * Move an instance of this container to (page, x, y), with the original's swap / merge rules.
   * Returns 'moved' | 'swapped' | 'merged' | null (refused).
   */
  moveTo(inst, page, x, y) {
    if (this.locked) return null;
    const [w, h] = this.size(inst);
    if (page < 0 || page >= this.unlocked || !this.inside(x, y, w, h)) return null;
    const occ = this.occupants(page, x, y, w, h, inst);
    if (!occ.length) { inst.page = page; inst.x = x; inst.y = y; this.changed('move'); return 'moved'; }
    if (occ.length !== 1) return null;
    const other = occ[0];
    if (canStack(other, inst, this.db)) {
      const stack = this.db.stackSize(this.db.def(inst.itemIndex));
      const n = Math.min(stack - (other.count || 1), inst.count || 1);
      if (n <= 0) return null;
      other.count += n;
      if (n >= (inst.count || 1)) this.list.splice(this.list.indexOf(inst), 1); else inst.count -= n;
      this.changed('merge');
      return 'merged';
    }
    // swap: the other item goes to the dragged item's old place (both footprints must fit)
    const [ow, oh] = this.size(other);
    const from = { page: inst.page | 0, x: inst.x, y: inst.y };
    const save = { page: other.page, x: other.x, y: other.y };
    inst.page = page; inst.x = x; inst.y = y;
    other.page = -99;
    const okInst = this.fits(page, x, y, w, h, [inst, other]);
    other.page = from.page;
    const originFits = this.fits(from.page, from.x, from.y, ow, oh, other);
    const parking = originFits ? from : this.findSpot(ow, oh, {ignore:other});
    if (!okInst || !parking) { inst.page = from.page; inst.x = from.x; inst.y = from.y; Object.assign(other, save); return null; }
    Object.assign(other, parking);
    this.changed('swap');
    return 'swapped';
  }

  /** Place an outside instance at (page, x, y) exactly (free footprint only, or merge onto a same stack). */
  placeAt(inst, page, x, y) {
    const [w, h] = this.size(inst);
    const def = this.db.def(inst.itemIndex);
    if (!def || !this.accept(def)) return null;
    if (page < 0 || page >= this.unlocked || !this.inside(x, y, w, h)) return null;
    const occ = this.occupants(page, x, y, w, h);
    if (!occ.length) { Object.assign(inst, { page, x, y }); this.list.push(inst); this.changed('add'); return 'moved'; }
    if (occ.length === 1 && canStack(occ[0], inst, this.db)) {
      const stack = this.db.stackSize(def);
      const n = Math.min(stack - (occ[0].count || 1), inst.count || 1);
      if (n <= 0) return null;
      occ[0].count += n;
      inst.count -= n;
      this.changed('merge');
      return inst.count > 0 ? 'partial' : 'merged';
    }
    return null;
  }

  /** Sort a page (or every page): by kind, then index; re-packs footprints row by row. */
  sort(page = null) {
    const pages = page != null ? [page] : [...Array(this.unlocked).keys()];
    const moving = this.list.filter(i => pages.includes(i.page | 0));
    moving.sort((a, b) => {
      const da = this.db.def(a.itemIndex), db2 = this.db.def(b.itemIndex);
      return (db2?.h * db2?.w || 1) - (da?.h * da?.w || 1) || (da?.type - db2?.type) || (da?.code - db2?.code) || a.itemIndex - b.itemIndex;
    });
    for (const it of moving) it.page = -1;
    for (const it of moving) {
      const [w, h] = this.size(it);
      let s = null;
      for (const p of pages) { s = this.findSpot(w, h, { page: p }); if (s) break; }
      if (!s) s = this.findSpot(w, h);
      if (s) Object.assign(it, s); else { it.page = pages[0]; it.x = 0; it.y = 0; }
    }
    // merge stacks that can merge
    for (const it of [...this.list]) {
      if (!this.list.includes(it)) continue;
      for (const o of this.list) {
        if (o === it || !canStack(o, it, this.db)) continue;
        const stack = this.db.stackSize(this.db.def(it.itemIndex));
        const n = Math.min(stack - (o.count || 1), it.count || 1);
        if (n > 0) { o.count += n; it.count -= n; }
        if (it.count <= 0) { this.list.splice(this.list.indexOf(it), 1); break; }
      }
    }
    this.changed('sort');
  }

  /** Repair items without a valid position (old saves / overlapping). */
  normalize() {
    const bad = [];
    for (const it of this.list) {
      const [w, h] = this.size(it);
      if (!Number.isInteger(it.page) || !Number.isInteger(it.x) || !Number.isInteger(it.y) || it.page < 0 || it.page >= this.pages || !this.inside(it.x, it.y, w, h)
        || this.occupants(it.page, it.x, it.y, w, h, [it, ...bad]).some(o => !bad.includes(o))) bad.push(it);
    }
    for (const it of bad) it.page = -1;
    const lost = [];
    for (const it of bad) {
      const [w, h] = this.size(it);
      const s = this.findSpot(w, h, { ignore: bad.filter(b => b.page === -1) });
      if (s) Object.assign(it, s); else lost.push(it);
    }
    for (const it of lost) this.list.splice(this.list.indexOf(it), 1);
    return lost;
  }
}
