// Equipment of the items system: slots, validation, weapon stances, the look/stat view the rest of the engine reads.
// Rules: docs/formats/items.md 4 (slots, weapon rules, hands, dual wield, shields/guard arms, ammo, class styles).
//
// save.equip = { active: 0..4 (preset), presets: [{slotId: uid}] x5, items: {uid: inst}, locked: bool }
//   slot ids = items.json equipment.slots (suititem_N of ui_invenwnd_base_renew.txt); 104/105 = the weapon tab II
//   pair (the reserve set, equipment.reserveSetOffset 100), 114 = the sub costume.
// An item can sit in several presets at once (Ctrl+click clones it into another preset tab, as the original).
import { activeAppearance, materialFits, materialLook } from './weapon-appearance.js';

export const S = { acc1: 0, acc3: 1, acc2: 2, acc4: 3, weapon: 4, offhand: 5, grow: 6, wing: 7, helmet: 8, armor: 9, pants: 10,
  glove: 11, boots: 12, costume: 18, pet: 19, vehicle: 20, earL: 24, earR: 25, brace1: 26, brace2: 27, belt: 28, emblem: 33,
  force1: 34, force2: 35, talisman: 36, weapon2: 104, offhand2: 105, costume2: 114 };
export const PART_OF_SLOT = { 8: 'helmet', 9: 'coat', 10: 'pants', 11: 'glove', 12: 'boots' };
export const PRESETS = 5;
const DUAL_STATUS = { 1: 'wDualSwordStatus', 6: 'wDualMacStatus', 8: 'wDualAxStatus' };

export function emptyEquip() { return { active: 0, presets: Array.from({ length: PRESETS }, () => ({})), items: {}, locked: false }; }

/** The off-hands of a preset still fit its weapons (the ammo / dual / shield rules of Equipment.check). */
export function pairedPreset(equip, preset) {
  return [S.offhand, S.offhand2].every(off => { const item = equip.get(off, preset); return !item || equip.check(item, off, null, preset).ok; });
}
/**
 * Global inven/ui_selectpresetequipwnd (itemdesc "Ctrl + Left Click to clone equipped item to another preset tab"): for each
 * preset 0..4, can the item worn in `slot` of `fromPreset` be registered there? 'source' (the clicked preset), 'holds' (already
 * registered in that slot), 'free' (an empty slot the preset can wear with its weapons), 'occupied' / 'unpaired' (260:75
 * "Not allowed"). null when the slot is empty.
 */
export function presetCloneStates(equip, slot, fromPreset) {
  const item = equip.get(slot, fromPreset);
  if (!item) return null;
  return Array.from({ length: PRESETS }, (_, t) => {
    if (t === fromPreset) return 'source';
    const row = equip.preset(t);
    if (row[slot] === item.uid) return 'holds';
    if (row[slot]) return 'occupied';
    row[slot] = item.uid;
    const ok = pairedPreset(equip, t);
    delete row[slot];
    return ok ? 'free' : 'unpaired';
  });
}
/** Registers that item in every listed preset that is 'free'; returns the presets it went into. */
export function clonePresetTo(equip, slot, fromPreset, targets) {
  const states = presetCloneStates(equip, slot, fromPreset), item = equip.get(slot, fromPreset), done = [];
  for (const t of new Set(targets)) if (states?.[t] === 'free') { equip.preset(t)[slot] = item.uid; done.push(t); }
  return done;
}
/** Presets 0..4 that hold `uid` (inven/ui_selectpresetunequipwnd lists them; 260:63 "None" on the others). */
export function presetsHolding(equip, uid) {
  return Array.from({ length: PRESETS }, (_, t) => t).filter(t => equip.findSlot(uid, t) != null);
}

export class Equipment {
  /** @param sys the items system ({db, game}) */
  constructor(sys) { this.sys = sys; }
  get db() { return this.sys.db; }
  get save() { return this.sys.game.save; }
  get data() { const e = this.save.equip ||= emptyEquip(); if (!e.presets) Object.assign(e, emptyEquip(), e); return e; }
  get classIndex() { return Number(this.save.classIndex) || 0; }
  preset(i = this.data.active) { return this.data.presets[i] ||= {}; }

  /** Instance in a slot of a preset (default: active). */
  get(slot, presetIdx = this.data.active) { const uid = this.preset(presetIdx)[slot]; return uid ? this.data.items[uid] || null : null; }
  /** [{slot, inst}] of a preset. */
  entries(presetIdx = this.data.active) {
    const out = [];
    for (const [slot, uid] of Object.entries(this.preset(presetIdx))) { const inst = this.data.items[uid]; if (inst) out.push({ slot: Number(slot), inst }); }
    return out;
  }
  /** Worn items that count (the active weapon pair, not the tab-II pair; costumes count). */
  worn(presetIdx = this.data.active) { return this.entries(presetIdx).filter(e => e.slot < 100); }
  /** Is this uid referenced by any preset? */
  isEquipped(uid) { return this.data.presets.some(p => Object.values(p).includes(uid)); }
  findSlot(uid, presetIdx = this.data.active) { for (const [s, u] of Object.entries(this.preset(presetIdx))) if (u === uid) return Number(s); return null; }

  // ---------------------------------------------------------------------------------------- rules
  /** Slot ids an item may occupy (items.json slotGroups). Dual wield also offers the off-hand slot. */
  slotsFor(def) {
    if (!def?.slot) return [];
    const g = this.db.equipment.slotGroups?.[def.slot] || [];
    const out = [...g];
    if (def.slot === 'weapon' && this.db.weaponRule(def)?.dual && this.canStyle(10)) out.push(S.offhand);
    return out;
  }
  canStyle(style) { return this.db.classStyles(this.classIndex).includes(style) && !!this.db.styleAnims(this.classIndex, style); }

  /**
   * Can `inst` go into `slot` (of the active preset)? Returns {ok, msg} (msg = [cate, code] client string or text).
   * stats = the character's current derived stats (str/dex/spr checks).
   */
  // LANE-22: presetIdx = the preset that will hold the item (off-hand rules read THAT preset's main weapon).
  check(inst, slot, stats = this.sys.game.player?.stats, presetIdx = this.data.active) {
    const def = this.db.def(inst?.itemIndex);
    if (!def || !def.slot) return { ok: false, msg: [40, 56] };
    // Only the declared native slots and the two weapon reserve slots exist.
    if (!Number.isInteger(slot) || !Object.values(S).includes(slot)) return { ok: false, msg: [40, 56] };
    const base = slot === S.weapon2 ? S.weapon : slot === S.offhand2 ? S.offhand : slot;
    if (!this.slotsFor(def).includes(base)) return { ok: false, msg: [40, 56] };
    const ci = this.classIndex;
    if (!((Number(def.classMask) >>> ci) & 1)) return { ok: false, msg: [40, 56] };
    const lv = Number(this.save.level) || 1;
    if (lv < (def.reqLv || 0) || (def.maxLv > 0 && lv > def.maxLv)) return { ok: false, msg: [40, 227] };
    if (stats) {
      if ((def.reqStr || 0) > (stats.str || 0) || (def.reqDex || 0) > (stats.dex || 0) || (def.reqSpr || 0) > (stats.spr || 0)) return { ok: false, msg: [40, 56] };
    }
    if (inst.expiresAt && inst.expiresAt < Date.now()) return { ok: false, msg: [40, 51] };
    // weapons / off-hand combinations
    const W = (s) => this.db.def(this.get(s, presetIdx)?.itemIndex);
    if (base === S.offhand) {
      const main = W(slot >= 100 ? S.weapon2 : S.weapon);
      const mr = this.db.weaponRule(main);
      const r = this.db.weaponRule(def);
      if (def.slot === 'weapon') {                       // second one-hander: dual wield of the same code
        if (!main || !mr?.dual || main.code !== def.code || !this.canStyle(10)) return { ok: false, msg: [20, 9] };
      } else if (r?.ammoFor != null) {                    // arrows / bolts need the matching bow
        if (!main || Number(main.code) !== r.ammoFor) return { ok: false, msg: [260, 60] };
      } else if (main && mr && (mr.hands || 1) >= 2) return { ok: false, msg: [20, 9] };
      else if (main && mr && !mr.withOffhand?.[def.code] && def.code !== 14) return { ok: false, msg: [20, 9] };
    }
    // the same unique accessory twice (e.g. 'Majestic' earrings) is refused by the item text; the data has no flag,
    // so only the exact same index in the paired slot is refused
    return { ok: true };
  }

  /** Default slot for an item (first empty of its group, else the first of the group). */
  autoSlot(def, presetIdx = this.data.active) {
    const g = (this.db.equipment.slotGroups?.[def?.slot] || []);
    for (const s of g) if (!this.preset(presetIdx)[s]) return s;
    return g[0] ?? null;
  }

  /**
   * Put an instance into a slot of a preset. Returns {ok, msg, displaced: [inst]} - displaced items (the previous
   * occupant, an off-hand a two-hander pushes out, ammo that no longer fits) must be returned to the bag by the caller.
   */
  place(inst, slot, presetIdx = this.data.active) {
    const d = this.data, p = this.preset(presetIdx);
    const displaced = [];
    const out = (s) => { const u = p[s]; if (!u) return; delete p[s]; const it = d.items[u]; if (it && !this.isEquipped(u)) { delete d.items[u]; displaced.push(it); } };
    out(slot);
    d.items[inst.uid] = inst;
    p[slot] = inst.uid;
    const def = this.db.def(inst.itemIndex);
    const base = slot >= 100 ? slot - 100 : slot;
    const off = slot >= 100 ? S.offhand2 : S.offhand;
    if (base === S.weapon) {
      const r = this.db.weaponRule(def);
      const o = this.db.def(d.items[p[off]]?.itemIndex);
      if (o) {
        const orule = this.db.weaponRule(o);
        const keep = orule?.ammoFor != null ? orule.ammoFor === Number(def.code)
          : o.slot === 'weapon' ? (r?.dual && o.code === def.code)
            : (r && (r.hands || 1) < 2 && (r.withOffhand?.[o.code] || o.code === 14));
        if (!keep) out(off);
      }
    }
    this.sys.changed?.('equip', { slot, inst });
    return { ok: true, displaced };
  }
  /** Remove the item of a slot from a preset; returns it when no other preset still holds it (else null). */
  remove(slot, presetIdx = this.data.active) {
    const d = this.data, p = this.preset(presetIdx);
    const u = p[slot];
    if (!u) return null;
    delete p[slot];
    const it = d.items[u];
    let freed = null;
    if (it && !this.isEquipped(u)) { delete d.items[u]; freed = it; }
    // an off-hand that depended on the main weapon (ammo, dual second weapon) falls off with it
    const base = slot >= 100 ? slot - 100 : slot;
    const extra = [];
    if (base === S.weapon) {
      const off = slot >= 100 ? S.offhand2 : S.offhand;
      const o = this.db.def(d.items[p[off]]?.itemIndex);
      if (o && (o.slot === 'weapon' || this.db.weaponRule(o)?.ammoFor != null)) {
        const ou = p[off]; delete p[off];
        if (!this.isEquipped(ou)) { extra.push(d.items[ou]); delete d.items[ou]; }
      }
    }
    this.sys.changed?.('unequip', { slot, inst: it });
    return { inst: freed, extra };
  }
  /** Weapon tab I <-> II: swap slots 4/5 with 104/105 of the active preset. */
  swapWeaponTab() {
    const p = this.preset();
    for (const [a, b] of [[S.weapon, S.weapon2], [S.offhand, S.offhand2]]) { const t = p[a]; if (p[b]) p[a] = p[b]; else delete p[a]; if (t) p[b] = t; else delete p[b]; }
    this.data.weaponTab = this.data.weaponTab ? 0 : 1;
    this.sys.changed?.('weapontab');
  }
  /** Main costume <-> sub costume. */
  swapCostume() {
    const p = this.preset();
    const t = p[S.costume]; if (p[S.costume2]) p[S.costume] = p[S.costume2]; else delete p[S.costume]; if (t) p[S.costume2] = t; else delete p[S.costume2];
    this.sys.changed?.('costume');
  }

  // ---------------------------------------------------------------------------------------- stance
  /** The weapon stance (style) of the worn weapons, with the class fallback (style -> 1 -> 0). */
  style() {
    const main = this.db.def(this.get(S.weapon)?.itemIndex);
    const off = this.db.def(this.get(S.offhand)?.itemIndex);
    let st = 1;
    const mr = this.db.weaponRule(main), or = this.db.weaponRule(off);
    if (main && mr) {
      st = mr.style ?? 1;
      if (off) {
        if (off.slot === 'weapon' && mr.dual && off.code === main.code) st = mr.dual;
        else if (mr.withOffhand?.[off.code]) st = mr.withOffhand[off.code];
      }
    } else if (off && or && Number(off.code) === 14) st = 14;
    else if (off && or && Number(off.code) === 21) st = 26;
    if (!this.canStyle(st)) {
      if (mr?.altStyle && this.canStyle(mr.altStyle)) return mr.altStyle;
      if (main && mr && this.canStyle(mr.style)) return mr.style;
      return this.canStyle(1) ? 1 : 0;
    }
    return st;
  }
  /** Dual weapon status (formula wDual*Status) when two same one-handers are worn. */
  dualStatus() {
    const main = this.db.def(this.get(S.weapon)?.itemIndex), off = this.db.def(this.get(S.offhand)?.itemIndex);
    if (!main || !off || off.slot !== 'weapon' || main.code !== off.code) return null;
    const k = DUAL_STATUS[main.code];
    return k ? Number(this.db.equipment.formula?.[k]) || null : null;
  }

  // ---------------------------------------------------------------------------------------- view for Player / progression
  /** The look of an item for this class: an asset {mesh, tpack, textures} or null. */
  assetFor(itemIndex, key = 'all') {
    const L = this.db.look(itemIndex);
    if (!L) return null;
    const ci = this.classIndex;
    if (key === 'all') return this.db.asset(L.byClass?.[ci] ?? L.all);
    return this.db.asset(L[key]);
  }

  /**
   * The weapon def Player.js attaches (bones per items.json weaponBones for this class, battle/peace columns):
   * {mesh,tpack,textures,bone,bonePeace, leftMesh,leftTpack,leftTextures,boneLeft,bonePeaceLeft, itemIndex, ...}
   * or {none:true} for bare hands.
   * Weapon appearance (Ian, weapon-appearance.js): a worn weapon whose running appearance material matches its code draws
   * the material's own item_shape meshes and action tables (appearance / leftAppearance = the material); itemIndex, sockets
   * and everything the stats read stay the worn weapon's. battle = {4, 5} projected materials of the own body inside a
   * DK Square / Draco battle (mounts/battle-look.js), used only when they match the worn code as well.
   */
  weaponView(battle = null) {
    const ci = this.classIndex;
    const mainI = this.get(S.weapon), offI = this.get(S.offhand);
    const main = this.db.def(mainI?.itemIndex), off = this.db.def(offI?.itemIndex);
    const now = typeof this.sys.game?.now === 'function' ? this.sys.game.now() : Date.now();
    const lookOf = (inst, def, slot) => {
      const team = Number(battle?.[slot]) || 0;
      const index = team && materialFits(this.db.def(team), def) ? team : activeAppearance(this.db, inst, now);
      return index ? materialLook(this.db, index) : null;
    };
    const mainLook = main ? lookOf(mainI, main, S.weapon) : null, offLook = off ? lookOf(offI, off, S.offhand) : null;
    const bonesOf = (def) => this.db.weaponBones(ci, 1024 + Number(def.code)) || {};
    const handBones = (def, side) => {
      const b = bonesOf(def);
      return side === 'left' ? { battle: b.battleLeft, peace: b.peaceLeft } : { battle: b.battleRight, peace: b.peaceRight };
    };
    const w = { none: true };
    const hands = [];   // [{asset, bones, item, look?, paired?}] main first
    if (main) {
      const r = this.db.weaponRule(main) || {};
      const a = mainLook ? mainLook.asset : this.assetFor(main.index);
      const L = this.db.look(main.index) || {};
      if (a) {
        if (r.column === 'left') hands.push({ asset: a, bones: handBones(main, 'left'), item: main.index, look: mainLook });
        else hands.push({ asset: a, bones: handBones(main, 'right'), item: main.index, look: mainLook });
        // Black Wizard orbs come in PAIRS where the data carries a left orb (the builder's weaponRules say column 'right', but the
        // data defines two): script/weapon_bonename.csv names BOTH orb bones of class 9 (BAL_R + BAL_L, each on its own pivot of
        // skel/character/bwz.skel: BAL_position / BAL_Rotate), and an orb with a left-hand counterpart (item_shape col 23 /
        // script/weapon_left.csv -> the *_l.mesh + *_l.skel/.anim, look.left) is drawn twice. Orbs without one (the starter
        // Mareumon: no _l mesh, no weapon_left.csv row) stay a single orb. An appearance material follows its own shape's left mesh.
        const orbPair = r.name === 'ORB' && (mainLook ? mainLook.left != null : L.left != null);
        if (r.column === 'both' || orbPair) {
          const la = (mainLook ? mainLook.left : this.db.asset(L.left)) || a;
          hands.push({ asset: la, bones: handBones(main, 'left'), item: mainLook ? main.index : L.leftItem || main.index, look: mainLook, paired: true });
        }
      }
    }
    if (off && hands.length < 2) {
      const a = offLook ? offLook.asset : this.assetFor(off.index);
      if (a) {
        const r = this.db.weaponRule(off) || {};
        // dual wield: the second one-hander goes on the left bones of its own type; shields / guard arms: left column;
        // ammo (quiver): its own table row (both columns name the quiver bone)
        const side = off.slot === 'weapon' ? 'left' : (r.column === 'left' ? 'left' : 'right');
        hands.push({ asset: a, bones: handBones(off, side), item: off.index, look: offLook });
      }
    }
    if (!hands.length) return w;
    const [h0, h1] = hands;
    // animated weapons (legend / epic meshes skinned to their own skeleton, items.md 7.3): the item action table's
    // skeleton and its loop clip (every row of a weapon table names the same clip)
    const tableOf = (id) => {
      const A = this.db._actionsData;
      const t = id != null && A ? A.item?.[id] : null;
      if (!t?.skel || !t.rows?.length) return null;
      const row = t.rows.find(r => r[0] === 0 && r[1] === 1) || t.rows[0];
      const anim = A.anims?.[row[3]];
      return anim ? { skel: t.skel, anim, animTime: Number(row[4]) || 2 } : null;
    };
    const actOf = (itemIndex, key) => tableOf(this.db.look(itemIndex)?.[key]);
    // G6: an item action record may name the weapon's OWN skeleton but no motion rows (673 Global weapons, e.g. 3000386 action
    // 16533 -> skel/item/weapon/lsword/att_equ_lsw_ego_01.skel). Its authored worn effect binds to that skeleton's bones
    // (5:1372 -> SWD_W / SWD_W01), so Player attaches only that skeleton's bind-pose bones (attachSkel); nothing animates it.
    const rigTable = (id) => { const t = id != null ? this.db._actionsData?.item?.[id] : null; return t?.skel && !t.rows?.length ? t.skel : null; };
    const rigOf = (itemIndex, key) => rigTable(this.db.look(itemIndex)?.[key]);
    // an appearance material: its own action table, the paired left hand its weapon_left.csv row's table (else its own)
    const lookAct = (h, f) => h.paired ? f(h.look.leftAction) || f(h.look.action) : f(h.look.action);
    // Shape-provided left meshes still use weapon_left.csv's own action record.
    const leftActionItem = main && this.db.equipment?.weaponLeft?.[main.index];
    const a0 = h0.look ? lookAct(h0, tableOf) : actOf(h0.item, 'action') || (main && h0.item === main.index ? actOf(main.index, 'action') : null);
    const a1 = !h1 ? null : h1.look ? lookAct(h1, tableOf) : (h1.item === main?.index ? actOf(main.index, 'leftAction') || (leftActionItem && actOf(leftActionItem, 'action')) || actOf(main.index, 'action') : actOf(h1.item, 'action'));
    const r0 = a0 ? null : h0.look ? lookAct(h0, rigTable) : rigOf(h0.item, 'action');
    const r1 = !h1 || a1 ? null : h1.look ? lookAct(h1, rigTable) : h1.item === main?.index ? rigOf(main.index, 'leftAction') || (leftActionItem && rigOf(leftActionItem, 'action')) : rigOf(h1.item, 'action');
    if (r0) w.attachSkel = r0;
    if (r1) w.leftAttachSkel = r1;
    Object.assign(w, {
      none: false, itemIndex: main?.index ?? off?.index, name: main?.name ?? off?.name,
      sockets: (mainI?.sockets||offI?.sockets||[]).slice(0,4).map(n=>Number(n)||0),
      leftItemIndex: h1?.item||null,
      leftIndependent: !!h1 && !h1.paired,
      leftSockets: (offI?.sockets||(h1?.item===main?.index?mainI?.sockets:[])||[]).slice(0,4).map(n=>Number(n)||0),
      mesh: h0.asset.mesh, tpack: h0.asset.tpack || null, textures: h0.asset.textures || null,
      bone: h0.bones.battle, bonePeace: h0.bones.peace || h0.bones.battle,
      leftMesh: h1 ? h1.asset.mesh : null, leftTpack: h1 ? h1.asset.tpack || null : null, leftTextures: h1 ? h1.asset.textures || null : null,
      boneLeft: h1 ? h1.bones.battle : undefined, bonePeaceLeft: h1 ? (h1.bones.peace || h1.bones.battle) : undefined,
      skel: a0?.skel || null, anim: a0?.anim || null, animTime: a0?.animTime || null,
      leftSkel: a1?.skel || null, leftAnim: a1?.anim || null, leftAnimTime: a1?.animTime || null,
    });
    if (h0.look) w.appearance = h0.look.index;
    if (h1?.look) w.leftAppearance = h1.look.index;
    delete w.none;
    w.none = false;
    return w;
  }

  /**
   * Legacy save.equipment view: {helmet|coat|pants|glove|boots: {mesh,tpack,textures,itemIndex,stats}, weapon: {...weaponView, stats}}.
   * Costumes replace the parts they cover while shown (settings.showCostume !== false); the armour stats still count.
   */
  view(stats) {
    const eq = {};
    for (const [slot, part] of Object.entries(PART_OF_SLOT)) {
      const inst = this.get(Number(slot));
      if (!inst) continue;
      const a = this.assetFor(inst.itemIndex);
      eq[part] = a ? { ...a, itemIndex: inst.itemIndex, sockets:(inst.sockets||[]).slice(0,4).map(n=>Number(n)||0) } : { itemIndex: inst.itemIndex };
    }
    // the own body inside a DK Square / Draco battle draws its squad's projected look (sys.battleLook, mounts/battle-look.js):
    // {costume, wing, emblem, weapon: {4, 5}} item indices; the real items keep their stats and come back afterwards
    const team = typeof this.sys.battleLook === 'function' ? this.sys.battleLook(this.save) : null;
    const cos = team?.costume ? { itemIndex: team.costume } : this.get(S.costume);
    const show = this.sys.game.settings?.showCostume !== false;
    if (cos && show) {
      const L = this.db.look(cos.itemIndex);
      // the appearance chosen in the costume shape change / Transcendence windows (inst.appearance = a costume item of
      // costumeshapechange.csv / costumesewinglist.csv) is drawn on the parts of the worn costume
      const app = Number(cos.appearance) || 0;
      const a = (app && this.db.look(app)?.slot === 'costume' && this.assetFor(app)) || this.assetFor(cos.itemIndex);
      if (L && a) for (const part of L.parts || []) eq[part] = { ...a, itemIndex: cos.itemIndex, costume: true };
    }
    eq.weapon = this.weaponView(team?.weapon || null);
    eq.weapon.stats = stats?.weapon || { meleeMin: 0, meleeMax: 0, magicMin: 0, magicMax: 0, rangeMin: 0, rangeMax: 0, range: 1.5, speed: 1, critical: 0 };
    if (stats?.flat) eq._items = { stats: stats.flat };
    eq.wing = this.wingView(team?.wing || null);
    // Meshless worn items whose shapes author visible effects (native modeleffect 31/1): emblem auras and the
    // talisman ground sigil. A talisman's transformed appearance replaces its own effect index.
    for (const [part, slot] of [['emblem', S.emblem], ['talisman', S.talisman]]) {
      const inst = part === 'emblem' && team?.emblem ? { itemIndex: team.emblem } : this.get(slot);
      if (inst) eq[part] = { itemIndex: inst.itemIndex, appearance: Number(inst.appearance) || 0 };
    }
    return eq;
  }

  wingView(projected = null) {
    const inst = projected ? { itemIndex: projected } : this.get(S.wing);
    if (!inst) return null;
    // WingVisual draws a transformed wing's own model and rig. Publish that same
    // look to intrinsic effects, while keeping the worn identity/stat source.
    const app = Number(inst.appearance) || 0;
    const appearanceAsset = app && this.db.look(app)?.slot === 'wing' && this.assetFor(app);
    const appearance = appearanceAsset?.mesh ? app : 0;
    const L = this.db.look(appearance || inst.itemIndex);
    const a = appearance ? appearanceAsset : this.assetFor(inst.itemIndex);
    return a ? { ...a, itemIndex: inst.itemIndex, ...(appearance ? { appearance } : {}), bone: L?.bone || this.db.equipment.wingBone || 'weaponW', action: L?.action ?? null } : null;
  }
}
