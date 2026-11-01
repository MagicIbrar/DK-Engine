// Loot: money (dil) and item drops rolled from the real drop tables, shown as glowing markers on the ground,
// picked up into save.inventory / save.dil.
//
// Tables (monsters.json, from share/item/monsterdropitemtable.csv + itemset.csv, all rates per 100 000):
//   monster.money          [min, max, rate]                    one dil pile with probability rate/100000
//   monster.drops.money    [[countMin, countMax, min, max, rate]]  replaces monster.money when present
//   monster.drops.sets     [[itemSetIndex, ratio, socket]]      each set rolls ratio/100000; at most maxSets
//                                                               successful sets per kill (MaxItemSet; 0 -> 1)
//   monster.drops.fixed    [[itemIndex, stack, countMin, countMax]]  always dropped
//   monster.drops.fixedSets[[itemSetIndex, countMin, countMax, socket, ratio]]
//   itemSets[i].items      [[itemIndex, weight, a, b, c]] — the item is chosen by weight. For consumable sets
//                          (potions, argates: c == 0 and a <= b small) a..b is the stack size; for equipment
//                          a/b/c are the Magic/Noble/DivineNoble ratios (per 100000) and set the item grade.
// game.settings.dropRate / moneyRate (default 1) scale the item / money rates on top of formula.ini
// fMonItemDropRatio / fMonMoneyDropRatio.
//
// Inventory entries: { uid, itemIndex, name, count, stack, grade } — room for equipment / options / sockets later.
//
// Consumables (useItem) come from share/item/itemetc.csv, Type 0 rows, loaded once in the browser:
//   Code 1 / 2      restore Value1 HP / MP             (Health Potion 320, Large 480, Great 820, Quantity 1600)
//   Code 50/51/52   restore Value1 % HP / % MP / both  (20% Health Potion, HP/MP Recovery Potion ...)
//   "Appraisal"     column = re-use delay in ms (1400-2600 for potions), shared by potions of the same kind
//   ReqLv           level needed to drink it; StackNumber = stack size (> 1 means the item stacks)
import * as THREE from 'three';
import { rand, monsterDef, heal } from './combat.js';
import { formulaOf } from './progression.js';
import { ITEM_GRADE_COLORS } from '../ui/item-colors.js';

export const PICKUP_RADIUS = 3;
const PICKUP_RETRY_MS = 5000;          // a refused drop is tried last for this long
export const DROP_LIFETIME = 180;      // seconds a drop stays on the ground
export const MAX_INVENTORY = 48;       // entries — the inventory window shows an 8 x 6 grid
const CONSUMABLE_KIND = { 1: 'hp', 2: 'mp', 50: 'hp%', 51: 'mp%', 52: 'hpmp%' };

/** Parse itemetc.csv rows (first row = header) into Map itemIndex -> consumable info (Type 0 rows only). */
export function parseConsumables(rows) {
  const out = new Map();
  if (!rows || !rows.length) return out;
  const head = rows[0].map(s => String(s).trim());
  const col = (name, d) => { const i = head.indexOf(name); return i >= 0 ? i : d; };
  const C = {
    index: col('Item Index', 0), name: col('Name', 1), type: col('Type', 3), code: col('Code', 4), delay: col('Appraisal', 12),
    v1: col('Value1', 14), v2: col('Value2', 15), req: col('ReqLv', 17), stack: col('StackNumber', 22),
  };
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i];
    if (!r || r.length < 20) continue;
    const idx = Number(r[C.index]);
    if (!Number.isFinite(idx) || Number(r[C.type]) !== 0) continue;
    const code = Number(r[C.code]) || 0;
    out.set(idx, {
      itemIndex: idx, name: r[C.name], code, kind: CONSUMABLE_KIND[code] || null,
      v1: Number(r[C.v1]) || 0, v2: Number(r[C.v2]) || 0, delayMs: Number(r[C.delay]) || 0,
      reqLevel: Number(r[C.req]) || 1, stackMax: Number(r[C.stack]) || 0,
    });
  }
  return out;
}
export const DIL_ITEM = 'dil';
const GRADE_COLORS = { dil: 0xffcf40, ...Object.fromEntries(Object.entries(ITEM_GRADE_COLORS).map(([grade,color])=>[grade,parseInt(color.slice(1),16)])) };
const SCATTER = 1.4;
const STACKABLE_NAME = /potion|elixir|argate|scroll|hammer|stone|bead|cube|sphere|skull|crystal|rhombus|pyramid|medial|ore|jewel/i;

function isStackGroup(it) {
  return it.length >= 4 && (it[4] || 0) === 0 && it[2] >= 1 && it[3] >= it[2] && it[3] <= 9999 && it[2] <= 9999 && (it[2] < 100 || it[3] < 100);
}

/** Choose one item from an itemset (weighted). Returns {kind:'item', itemIndex, name, count, stack, grade} or null. */
export function pickFromSet(set, names = {}, rng = rand) {
  const items = set?.items;
  if (!items || !items.length) return null;
  let sum = 0;
  for (const it of items) sum += Math.max(0, it[1] || 0);
  let it = items[0];
  if (sum > 0) {
    let r = rng() * sum;
    for (const x of items) { r -= Math.max(0, x[1] || 0); if (r < 0) { it = x; break; } }
  }
  const itemIndex = it[0];
  const out = { kind: 'item', itemIndex, name: names[itemIndex] || `Item #${itemIndex}`, count: 1, stack: false, grade: 'normal' };
  if (isStackGroup(it)) {
    out.count = Math.max(1, it[2] + Math.floor(rng() * (it[3] - it[2] + 1)));
    // Stackability lives in the item tables (next milestone); until then stack what obviously stacks.
    out.stack = it[3] > 1 || STACKABLE_NAME.test(out.name);
  } else {
    const [,, magic = 0, noble = 0, divine = 0] = it;
    const r = rng() * 100000;
    out.grade = r < divine ? 'divine' : r < divine + noble ? 'noble' : r < divine + noble + magic ? 'magic' : 'normal';
  }
  return out;
}

/**
 * Roll everything a monster drops. def = monsters.json monster, db = monsters.json (itemSets, itemNames).
 * opts: { itemRate, moneyRate, rng }. Returns [{kind:'dil', amount} | {kind:'item', ...}].
 */
export function rollMonsterDrops(def, db, opts = {}) {
  const out = [];
  if (!def) return out;
  const rng = opts.rng || rand;
  const itemRate = opts.itemRate ?? 1;
  const moneyRate = opts.moneyRate ?? 1;
  const ri = (a, b) => { a = Math.round(a); b = Math.round(b); if (b < a) [a, b] = [b, a]; return a + Math.floor(rng() * (b - a + 1)); };
  const sets = db?.itemSets || {};
  const names = db?.itemNames || {};
  const drops = def.drops || {};

  // money
  if (Array.isArray(drops.money) && drops.money.length) {
    for (const [cmin, cmax, min, max, rate] of drops.money) {
      if (rng() * 100000 >= rate * moneyRate) continue;
      const n = Math.max(1, ri(cmin || 1, cmax || 1));
      for (let i = 0; i < n; i++) { const amount = ri(min, max); if (amount > 0) out.push({ kind: DIL_ITEM, amount }); }
    }
  } else if (Array.isArray(def.money) && def.money[1] > 0 && def.money[2] > 0) {
    if (rng() * 100000 < def.money[2] * moneyRate) {
      const amount = ri(def.money[0], def.money[1]);
      if (amount > 0) out.push({ kind: DIL_ITEM, amount });
    }
  }

  // item sets
  const cap = drops.maxSets > 0 ? drops.maxSets : 1;
  let got = 0;
  for (const [setIndex, ratio] of drops.sets || []) {
    if (got >= cap) break;
    if (rng() * 100000 >= ratio * itemRate) continue;
    const it = pickFromSet(sets[setIndex], names, rng);
    if (it) { out.push(it); got++; }
  }
  // fixed items
  for (const [itemIndex, stack, cmin, cmax] of drops.fixed || []) {
    const count = Math.max(1, ri(cmin || 1, cmax || cmin || 1));
    out.push({ kind: 'item', itemIndex, name: names[itemIndex] || `Item #${itemIndex}`, count, stack: !!stack || count > 1, grade: 'normal' });
  }
  // fixed item sets
  for (const [setIndex, cmin, cmax, , ratio] of drops.fixedSets || []) {
    if (ratio > 0 && rng() * 100000 >= ratio * itemRate) continue;
    const n = Math.max(1, ri(cmin || 1, cmax || cmin || 1));
    for (let i = 0; i < n; i++) { const it = pickFromSet(sets[setIndex], names, rng); if (it) out.push(it); }
  }
  return out;
}

// ------------------------------------------------------------------ visuals
let _gemGeo = null, _glowTex = null;
function gemGeometry() { return (_gemGeo ||= new THREE.OctahedronGeometry(0.17, 0)); }
function glowTexture() {
  if (_glowTex !== null) return _glowTex;
  _glowTex = undefined;
  if (typeof document === 'undefined') return _glowTex;
  try {
    const c = document.createElement('canvas');
    c.width = c.height = 64;
    const ctx = c.getContext('2d');
    const g = ctx.createRadialGradient(32, 32, 0, 32, 32, 32);
    g.addColorStop(0, 'rgba(255,255,255,1)');
    g.addColorStop(0.35, 'rgba(255,255,255,0.45)');
    g.addColorStop(1, 'rgba(255,255,255,0)');
    ctx.fillStyle = g;
    ctx.fillRect(0, 0, 64, 64);
    _glowTex = new THREE.CanvasTexture(c);
    _glowTex.colorSpace = THREE.SRGBColorSpace;
  } catch { _glowTex = undefined; }
  return _glowTex;
}
function labelSprite(text, color) {
  if (typeof document === 'undefined') return null;
  try {
    const c = document.createElement('canvas');
    const ctx = c.getContext('2d');
    const font = 'bold 30px Tahoma, Verdana, sans-serif';
    ctx.font = font;
    const w = Math.ceil(ctx.measureText(text).width) + 20;
    c.width = Math.min(1024, w); c.height = 44;
    ctx.font = font;
    ctx.textAlign = 'center'; ctx.textBaseline = 'middle';
    ctx.lineWidth = 5; ctx.strokeStyle = 'rgba(0,0,0,0.85)';
    ctx.strokeText(text, c.width / 2, 23);
    ctx.fillStyle = '#' + new THREE.Color(color).getHexString();
    ctx.fillText(text, c.width / 2, 23);
    const tex = new THREE.CanvasTexture(c);
    tex.colorSpace = THREE.SRGBColorSpace;
    const mat = new THREE.SpriteMaterial({ map: tex, transparent: true, depthWrite: false });
    const s = new THREE.Sprite(mat);
    const h = 0.34;
    s.scale.set((h * c.width) / c.height, h, 1);
    s.renderOrder = 10;
    return s;
  } catch { return null; }
}

export function dropLabel(entry) {
  if (entry.kind === DIL_ITEM) return `${entry.amount.toLocaleString?.('en-US') ?? entry.amount} Dil`;
  return entry.count > 1 ? `${entry.name} x${entry.count}` : entry.name;
}

// ------------------------------------------------------------------ system
export class LootSystem {
  constructor(game, opts = {}) {
    this.game = game;
    this.drops = [];
    this._seq = 0;
    this._v = new THREE.Vector3();
    this.consumables = opts.consumables || null;  // Map from parseConsumables()
    this.itemCooldowns = new Map();                // potion kind -> game time when usable again
    if (!this.consumables && opts.loadTables !== false && typeof window !== 'undefined') {
      this.ready = this._loadConsumables();
    }
    if (opts.loadTables !== false && typeof window !== 'undefined') this.loadClassDrops();
  }

  async _loadConsumables() {
    try {
      const { fetchCSV } = await import('../engine/assets.js');
      this.consumables = parseConsumables(await fetchCSV('share/item/itemetc.csv'));
    } catch (err) {
      console.warn('itemetc.csv unavailable: items cannot be used', err);
      this.consumables = new Map();
    }
    return this.consumables;
  }

  setConsumables(map) { this.consumables = map; }

  /** Stack size of an item (0/1 = does not stack), when the tables know it. */
  stackMax(itemIndex) {
    return this.consumables?.get(Number(itemIndex))?.stackMax ?? null;
  }

  // ---------------------------------------------------------------- using items
  _findEntry(ref) {
    const inv = this.game?.save?.inventory || [];
    if (ref == null) return null;
    if (typeof ref === 'number') return inv[ref] || null;
    if (typeof ref === 'string') return inv.find(e => e?.uid === ref) || null;
    if (typeof ref === 'object') {
      if (inv.includes(ref)) return ref;
      if (ref.uid) { const e = inv.find(x => x?.uid === ref.uid); if (e) return e; }
      if (ref.itemIndex != null) return inv.find(x => x?.itemIndex === Number(ref.itemIndex)) || null;
    }
    return null;
  }

  /** Seconds until a consumable of this item's kind can be used again. */
  itemCooldown(itemIndex) {
    const def = this.consumables?.get(Number(itemIndex));
    if (!def?.kind) return 0;
    return Math.max(0, (this.itemCooldowns.get(def.kind) || 0) - (this.game?.time || 0));
  }

  /**
   * Use an inventory item: ref = inventory index, uid, entry, or a hotbar entry {type:'item', uid|itemIndex}.
   * Potions restore HP/MP; other items are not usable yet. Returns true when the item was consumed.
   */
  useItem(ref) {
    const g = this.game, p = g?.player;
    const e = this._findEntry(ref);
    if (!e || !p || p.dead) return false;
    const def = this.consumables?.get(Number(e.itemIndex));
    if (!def?.kind) { this._msg(`${e.name || 'This item'} cannot be used yet.`); return false; }
    if ((g.save?.level || 1) < def.reqLevel) { this._msg(`${e.name} requires level ${def.reqLevel}.`); return false; }
    const now = g.time || 0;
    if (now < (this.itemCooldowns.get(def.kind) || 0)) return false;
    const hpFull = p.hp >= p.maxHp, mpFull = p.mp >= p.maxMp;
    let hp = 0, mp = 0;
    switch (def.kind) {
      case 'hp': hp = def.v1; break;
      case 'mp': mp = def.v1; break;
      case 'hp%': hp = p.maxHp * def.v1 / 100; break;
      case 'mp%': mp = p.maxMp * def.v1 / 100; break;
      case 'hpmp%': hp = p.maxHp * def.v1 / 100; mp = p.maxMp * (def.v2 || def.v1) / 100; break;
      default: return false;
    }
    if ((hp > 0 && !hpFull) || (mp > 0 && !mpFull)) {
      if (hp > 0) heal(g, p, p, hp);
      if (mp > 0) {
        const before = p.mp;
        p.mp = Math.min(p.maxMp, p.mp + Math.round(mp));
        try { g.hud?.floater?.(p, `+${Math.round(p.mp - before)} MP`, 'heal'); } catch { /* optional */ }
      }
    } else {
      this._msg(hp > 0 ? 'Your HP is already full.' : 'Your MP is already full.');
      return false;
    }
    this.itemCooldowns.set(def.kind, now + def.delayMs / 1000);
    e.count = (e.count || 1) - 1;
    if (e.count <= 0) {
      const inv = g.save.inventory;
      const i = inv.indexOf(e);
      if (i >= 0) inv.splice(i, 1);
    }
    g.events?.emit('itemuse', { item: e, def });
    return true;
  }

  /** Roll a dead monster's drops and scatter them around its corpse. Returns the ground drops created. */
  dropFrom(monster) {
    const g = this.game;
    const def = monsterDef(monster);
    if (!def) return [];
    const F = formulaOf(g?.data);
    const entries = rollMonsterDrops(def, g?.data?.monsters, {
      itemRate: (F.fMonItemDropRatio ?? 1) * (g?.settings?.dropRate ?? 1),
      moneyRate: (F.fMonMoneyDropRatio ?? 1) * (g?.settings?.moneyRate ?? 1),
    });
    // the class-drop layer of the map (monsterdropitem_class.csv): the equipment low-level fields drop
    try { entries.push(...this.rollClassDrops(monster, def, { itemRate: (F.fMonItemDropRatio ?? 1) * (g?.settings?.dropRate ?? 1) })); } catch (err) { console.warn('class drops failed', err); }
    const made = [];
    entries.forEach((e, i) => {
      const a = (i / Math.max(1, entries.length)) * Math.PI * 2 + rand() * 0.8;
      const r = entries.length > 1 ? 0.5 + rand() * (SCATTER - 0.5) : rand() * 0.5;
      made.push(this.spawnDrop(e, monster.x + Math.cos(a) * r, monster.z + Math.sin(a) * r));
    });
    return made;
  }

  /**
   * monsterdropitem_class.csv (gmcommands_monsters.json classDrops / itemSets, docs/formats/gmcommands.md §3.6):
   * on maps whose map-drop row has Class_Check, each row of the map whose level range holds the monster level (and
   * whose Monster_Index is 0 or this monster) fires with Rate/100000; with ClassRate/100000 it uses the killer's own
   * class list, else a random class's; one item set of that list is picked, then one item of the set by weight (grade
   * from the set's magic / noble / divine ratios). LevelCap = the largest player-over-monster level gap that still
   * drops. The map layer itself (sets, fixed items) is rolled by the dungeons system on the 'death' event.
   * This is where the "smart" weapons and armour of the starting fields (Ardeca: 2 % armour, 0.1 % weapons) come from.
   */
  rollClassDrops(monster, def, { itemRate = 1, rng = rand } = {}) {
    const g = this.game;
    const cd = this._classDrops;
    if (!cd) { this.loadClassDrops(); return []; }
    const map = Number(g?.world?.info?.index);
    const md = cd.mapDrops?.[String(map)];
    if (!md || !Number(md.classCheck)) return [];
    const lv = Number(def?.level ?? monster?.level) || 1;
    const plv = Number(g?.save?.level) || 1;
    const cls = Number(g?.save?.classIndex) || 0;
    const out = [];
    for (const r of cd.byMap.get(map) || []) {
      const [, lmin, lmax, cap, , mon, rate, classRate, byClass] = r;
      if (lv < Number(lmin) || lv > Number(lmax)) continue;
      if (Number(mon) && Number(mon) !== Number(monster?.monsterIndex ?? monster?.def?.index ?? def?.index)) continue;
      if (Number(cap) > 0 && plv - lv > Number(cap)) continue;
      if (rng() * 100000 >= Number(rate) * itemRate) continue;
      const classes = Object.keys(byClass || {});
      if (!classes.length) continue;
      const own = byClass[String(cls)];
      const list = own && rng() * 100000 < Number(classRate) ? own : byClass[classes[Math.floor(rng() * classes.length)]];
      if (!list?.length) continue;
      const it = pickFromSet(cd.itemSets[String(list[Math.floor(rng() * list.length)])], g?.data?.monsters?.itemNames || {}, rng);
      if (it) out.push(it);
    }
    return out;
  }

  /** Load the class-drop layer once (shared with the GM panel's drop viewer through fetchJSON's cache). */
  loadClassDrops() {
    if (this._classDropsP || typeof window === 'undefined') return this._classDropsP;
    this._classDropsP = import('../engine/assets.js').then(({ fetchJSON }) => fetchJSON('/gamedata/gmcommands_monsters.json')).then(j => {
      const byMap = new Map();
      for (const r of j?.classDrops || []) { const m = Number(r[0]); if (!byMap.has(m)) byMap.set(m, []); byMap.get(m).push(r); }
      this._classDrops = { byMap, mapDrops: j?.mapDrops || {}, itemSets: j?.itemSets || {} };
      return this._classDrops;
    }).catch(err => { console.warn('class drop tables unavailable', err); this._classDrops = { byMap: new Map(), mapDrops: {}, itemSets: {} }; return this._classDrops; });
    return this._classDropsP;
  }

  /** Put an entry on the ground at FILE (x, z). */
  spawnDrop(entry, x, z) {
    const g = this.game;
    const w = g?.world;
    if (w?.isWalkable && !w.isWalkable(x, z)) { // keep drops reachable
      const p = g.player;
      if (p) { x = p.x + (x - p.x) * 0.3; z = p.z + (z - p.z) * 0.3; }
    }
    const drop = {
      id: ++this._seq, entry, x, z, y: 0, born: g?.time || 0, label: dropLabel(entry), object: null,
      phase: rand() * Math.PI * 2,
    };
    drop.y = this._groundY(x, z);
    drop.object = this._makeMarker(drop);
    this.drops.push(drop);
    return drop;
  }

  _groundY(x, z) {
    const w = this.game?.world;
    const h = w?.heightAt ? w.heightAt(x, z) : 0;
    return Number.isFinite(h) ? h : 0;
  }

  _makeMarker(drop) {
    const root = this.game?.worldRoot;
    if (!root) return null;
    const color = GRADE_COLORS[drop.entry.kind === DIL_ITEM ? 'dil' : drop.entry.grade] ?? GRADE_COLORS.normal;
    const group = new THREE.Group();
    group.name = `drop:${drop.label}`;
    const gem = new THREE.Mesh(gemGeometry(), new THREE.MeshBasicMaterial({ color }));
    gem.position.y = 0.3;
    group.add(gem);
    const glow = new THREE.Sprite(new THREE.SpriteMaterial({
      map: glowTexture() || null, color, transparent: true, opacity: 0.75,
      blending: THREE.AdditiveBlending, depthWrite: false,
    }));
    glow.scale.set(0.9, 0.9, 1);
    glow.position.y = 0.3;
    group.add(glow);
    const label = labelSprite(drop.label, color);
    if (label) { label.position.y = 0.78; group.add(label); }
    group.position.set(drop.x, drop.y, drop.z); // FILE frame under the mirrored world root
    group.userData.drop = drop;
    root.add(group);
    drop.gem = gem;
    drop.glow = glow;
    return group;
  }

  _removeDrop(drop) {
    const i = this.drops.indexOf(drop);
    if (i >= 0) this.drops.splice(i, 1);
    const o = drop.object;
    if (o) {
      o.parent?.remove(o);
      o.traverse(n => {
        if (n.material) { n.material.map && n.material.map !== _glowTex && n.material.map.dispose(); n.material.dispose(); }
      });
      drop.object = null;
    }
  }

  update(dt) {
    const now = this.game?.time || 0;
    for (let i = this.drops.length - 1; i >= 0; i--) {
      const d = this.drops[i];
      const age = now - d.born;
      if (age > DROP_LIFETIME) { this._removeDrop(d); continue; }
      if (d.gem) {
        d.gem.rotation.y += dt * 2.2;
        d.gem.position.y = 0.3 + Math.sin(now * 3 + d.phase) * 0.06;
        if (d.glow) d.glow.material.opacity = 0.55 + Math.sin(now * 4 + d.phase) * 0.2;
        if (age > DROP_LIFETIME - 10) d.object.visible = Math.floor(now * 4) % 2 === 0; // blink before vanishing
      }
    }
  }

  /** Nearest drop to (x, z) within maxDist, or null. */
  nearest(x, z, maxDist = Infinity) {
    let best = null, bd = maxDist;
    for (const d of this.drops) {
      const dd = Math.hypot(d.x - x, d.z - z);
      if (dd <= bd) { bd = dd; best = d; }
    }
    return best;
  }

  /** Drop under a screen point (ndc {x,y}), or null. Used by the controller for click-to-pick-up. */
  pickAt(ndc) {
    const g = this.game;
    if (!this.drops.length || !g?.camera || !g?.raycaster) return null;
    g.raycaster.setFromCamera(ndc, g.camera);
    const ray = g.raycaster.ray;
    let best = null, bestT = Infinity;
    for (const d of this.drops) {
      if (!d.object) continue;
      d.object.updateWorldMatrix(true, false);
      const p = this._v.set(0, 0.4, 0).applyMatrix4(d.object.matrixWorld);
      if (ray.distanceSqToPoint(p) > 0.55 * 0.55) continue;
      const t = p.clone().sub(ray.origin).dot(ray.direction);
      if (t > 0 && t < bestT) { bestT = t; best = d; }
    }
    return best;
  }

  /** Pick up one drop (no range check — callers walk there first). Returns true on success. */
  pickup(drop) {
    const g = this.game;
    if (!drop || !this.drops.includes(drop)) return false;
    const save = g?.save;
    if (!save) return false;
    const e = drop.entry;
    if (e.kind === DIL_ITEM) {
      save.dil = (Number(save.dil) || 0) + e.amount;
      g.events?.emit('loot', { name: 'Dil', count: e.amount, kind: DIL_ITEM });
    } else {
      if (!this.canFit(e) || !this.addItem(e)) { this._msg('Your inventory is full.'); return false; }
      g.events?.emit('loot', { name: e.name, count: e.count, kind: 'item', itemIndex: e.itemIndex, grade: e.grade });
    }
    this._removeDrop(drop);
    return true;
  }

  /** Drops the player could pick up from (x, z), nearest first, within maxDist. A drop the host refused a moment ago (bag full,
   *  reserved for its owner) goes after the ones that were not refused, so repeated presses reach every drop instead of
   *  retrying the same one. */
  pickupOrder(x, z, maxDist = Infinity) {
    const now = Date.now(), rows = [];
    for (const d of this.drops) {
      const dd = Math.hypot(d.x - x, d.z - z);
      if (dd <= maxDist && this.canTake(d)) rows.push([d, dd, d.deniedAt && now - d.deniedAt < PICKUP_RETRY_MS ? 1 : 0]);
    }
    rows.sort((a, b) => a[2] - b[2] || a[1] - b[1]);
    return rows.map(r => r[0]);
  }

  /** May the player take this drop at all? The shared world overrides it (a drop still reserved for another player). */
  canTake(drop) { return !!drop; }

  /** A drop within maxDist that exists but may not be taken yet (reserved for another player), or null. The pickup key uses it to
   *  say so when nothing else can be taken, as the host's own refusal did before the key skipped such drops. */
  reservedNear(x, z, maxDist = Infinity) {
    for (const d of this.drops) if (Math.hypot(d.x - x, d.z - z) <= maxDist && !this.canTake(d)) return d;
    return null;
  }

  /** Is a pickup request still on its way to the host? The shared world overrides it; offline pickup is immediate. */
  pickupBusy() { return false; }

  /** One press = ONE drop: the nearest one within `radius` of the player that can be taken (the next nearest when the
   *  nearest does not fit the bag). Returns 1 when it was picked up, 0 when nothing was taken (online: the request is on
   *  its way, pickupBusy() says so). Nothing is taken while an earlier request is still unanswered. */
  pickupNearby(radius = PICKUP_RADIUS) {
    const p = this.game?.player;
    if (!p || p.dead || this.pickupBusy()) return 0;
    for (const d of this.pickupOrder(p.x, p.z, radius)) {
      if (this.pickup(d)) return 1;
      if (this.pickupBusy()) return 0;
    }
    return 0;
  }

  /** Would the whole entry fit into the inventory? */
  canFit(e) {
    const inv = this.game?.save?.inventory || [];
    const max = this.stackMax(e.itemIndex);
    const stack = max != null ? max > 1 : !!e.stack;
    let left = e.count || 1;
    if (stack) {
      for (const x of inv) {
        if (!x || x.itemIndex !== e.itemIndex || !x.stack || (x.grade || 'normal') !== (e.grade || 'normal')) continue;
        left -= max > 1 ? Math.max(0, max - x.count) : left;
        if (left <= 0) return true;
      }
    }
    const per = stack ? (max > 1 ? max : Infinity) : 1;
    return inv.length + Math.ceil(left / per) <= MAX_INVENTORY;
  }

  /** Add an item entry to save.inventory (stacks merge). Returns the inventory entry or null when full. */
  addItem(e) {
    const save = this.game?.save;
    if (!save) return null;
    const inv = (save.inventory ||= []);
    const max = this.stackMax(e.itemIndex);
    const stack = max != null ? max > 1 : !!e.stack; // the item table wins over the drop-table guess
    let left = e.count || 1;
    let last = null;
    if (stack) {
      for (const x of inv) {
        if (left <= 0) break;
        if (!x || x.itemIndex !== e.itemIndex || !x.stack || (x.grade || 'normal') !== (e.grade || 'normal')) continue;
        const room = max > 1 ? Math.max(0, max - x.count) : left;
        const add = Math.min(room, left);
        if (add > 0) { x.count += add; left -= add; last = x; }
      }
    }
    while (left > 0) {
      if (inv.length >= MAX_INVENTORY) return last;
      const n = stack && max > 1 ? Math.min(max, left) : stack ? left : 1;
      last = {
        uid: `i${Date.now().toString(36)}${(++this._seq).toString(36)}${Math.floor(rand() * 1296).toString(36)}`,
        itemIndex: e.itemIndex, name: e.name, count: n, stack, grade: e.grade || 'normal',
      };
      inv.push(last);
      left -= n;
    }
    return last;
  }

  _msg(text) {
    const now = this.game?.time || 0;
    if (text === this._lastMsg && now - (this._msgAt ?? -9) < 1) return; // don't spam the same line
    this._msgAt = now;
    this._lastMsg = text;
    try { this.game?.hud?.log?.(text, 'err'); } catch { /* optional */ }
  }

  clear() {
    for (const d of [...this.drops]) this._removeDrop(d);
    this.drops = [];
  }
}
