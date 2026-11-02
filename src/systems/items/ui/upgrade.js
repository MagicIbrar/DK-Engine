// Reinforce Item (NPC Maximus / Axion / Pablos, job ITEMUPGRADE): game2/itemupgrade/ui_upgradewnd.txt.
//
//   upgrade_item   the target (weapon / armour / accessory / emblem in the bag; equipped items are refused, 1001:2)
//   stone_item     the upgrade stone of itemupgrade.csv for (category, grade, +N): stone1 or its bound twin stone2
//   stone_ruin     Ruin Argate for DK items (rank 5) / Colosseum Argate for Colosseum items (rank 6) (item texts 116/119:
//                  "Must be used with normal enhancement stones")
//   cash_caron, cash_growbless   the two "Chance" slots: upgradesubitem.csv Probability items (+upgradeRate %); the
//                  Epic/Theos Grace / Glory / Spirit items also protect from their slot (their item texts)
//   cash_safe      the protection slot (upgradesubitem.csv Safety items: Blacksmith Protector / Talisman)
//   pan_ready      help page with the stone of each gear family (350:139..146) while nothing is registered
//   pan_select_stone  once a target is registered: the usable stones (item_stone1..5), the owned rate items (substone
//                  1-2) and protection items (substone 3-4) - click one to register it; btn_resourcesetting registers
//                  the best set automatically; btn_strength reinforces.
// Rules (items.md 6.1): success % = rateUpTo144 / rateFrom145 (by the item's required level) + the rate items, max 100;
// cost = costDil; one stone (+ one Ruin/Colosseum Argate) and each registered rate / protection item are used per try.
// Failure penalty of the row: NOT_FAIL, BACK_TO_ZERO, BACK_TO_CONST_N (+Value), BACKWARD_ITEM (itemupgrade_safe.csv
// BACKWARD_LEVEL rows, cumulative BACKWARD_RATIO %), ALLITEM_DESTRUCT. A protection item turns the failure into a
// drop by the BACKWARD_RATIO_EX column of the current level (never destroyed; "Blessed"/"Talisman Protector" drop at
// most 3); Grace: at most 3 levels; Glory: 0-1 level; Spirit of Blacksmith: stays.
import { Crafting, sysSound, clean, indexAtLevel, morph } from './craft.js';
import { fmt } from './common.js';

const EXAMPLES = [9901, 4000380, 9908, 4000515, 4000580];   // Copper / Condensed Copper / Ruin / Circulation I / Water Argate
const RUIN = { 5: [9908], 6: [9913] };                        // DK items: Ruin Argate; Colosseum items: Colosseum Argate
const EPIC_RANKS = new Set([10, 12, 13, 14, 15]);

export function targetFamily(def) {
  const t = Number(def?.type), c = Number(def?.code);
  if (EPIC_RANKS.has(Number(def?.rank))) return Number(def.rank) === 15 ? 'TEOS' : 'EPIC';
  if (t === 5 && c === 13) return 'EMBLEM';
  if (t === 2 || (t === 5 && [11, 12, 15, 16, 18].includes(c))) return 'ACC';
  return 'EQUIP';
}

/** itemupgrade.csv row of an item at its current +N (null when it cannot be reinforced). */
export function upgradeRow(db, def) {
  const T = db.T, U = db.equipment.upgrade;
  if (!def || !def.next || !T?.itemUpgrade?.rows) return null;
  if (!db._upIdx) {
    db._upIdx = new Map();
    for (const r of T.itemUpgrade.rows) db._upIdx.set(`${r.itemCode}|${r.rank}|${r.level}`, r);
  }
  const kind = db.kind(def);
  const code = U.categoryByKind?.[kind];
  if (!code) return null;
  const lv = Number(def.itemLv) || 0;
  const rank = Number(def.rank) || 0;
  const grades = [U.gradeByRank?.[rank], rank === 5 || rank === 6 || rank === 1 || rank === 7 || rank === 8 || rank === 9 ? 'NORMAL' : null, 'NORMAL'].filter(Boolean);
  for (const g of grades) { const r = db._upIdx.get(`${code}|${g}|${lv}`); if (r) return r; }
  return null;
}

/** upgradesubitem.csv row of a support item. */
function subRow(db, itemIndex) {
  const rows = db.T?.upgradeSubItem?.rows || [];
  if (!db._subIdx) { db._subIdx = new Map(); for (const r of rows) db._subIdx.set(Number(r.ItemIndex), r); }
  return db._subIdx.get(Number(itemIndex)) || null;
}

/**
 * Can support item `sub` (def) be used on target `tdef`? Returns true or a client message [cate, code].
 * slot: 'rate' | 'safe'
 */
export function supportOk(db, sub, tdef, slot) {
  const r = subRow(db, sub?.index);
  if (!r) return [1001, 5];
  const fam = targetFamily(tdef);
  const lv = Number(tdef?.itemLv) || 0;
  const epic = fam === 'EPIC' || fam === 'TEOS';
  const g = Number(r.Group);
  if (slot === 'safe') {
    if (!(Number(r.Safety) === 1 && Number(r.Probability) === 0 && g === 3)) return g === 9 || g === 6 || g === 5 ? [1001, 164] : [1001, 185];
    if (epic) return [1001, 166];
    if (fam === 'ACC') return [1001, 168];
    if (lv < 1) return [1001, 13];
    return true;
  }
  // rate slots
  if (g === 3) return [1001, 164];
  if (g === 7 || g === 8) return [1001, 87];
  if (g === 5 || g === 6 || g === 9) {
    if (!epic) return [1001, 165];
    if (g === 5 && lv > 8) return [1001, 218];
    if (g === 6 && (lv < 9 || lv > 11)) return [1001, 219];
    if (g === 9 && (fam !== 'TEOS' || lv < 12)) return [1001, 220];
    return true;
  }
  if (epic) return [1001, 166];
  if (g === 1) {
    if (fam === 'ACC') return [1001, 168];
    if (lv > 8) return [1001, 24];
    if (Number(sub.code) === 29 && ((Number(tdef.reqLv) || 0) > (Number(sub.value2) || 160) || Number(tdef.rank) === 3)) return [1001, 185];
    return true;
  }
  if (g === 2) return lv === 9 ? true : [1001, 24];
  if (g === 4) return fam === 'ACC' ? (lv > 8 ? [1001, 24] : true) : [1001, 87];
  return [1001, 185];
}

/**
 * Holy Water ItemUpgradeRate (share/item/premiereitem.csv, percentage points: 5 / 8 / 10 / 50 / 100). The item text of Holy Water of
 * Almighty (description 701) says "Item enhancement success chance increased by 5% (unavailable above +11 enhancement)": READING of
 * that sentence - attempts whose result would be above +11 get no bonus (an item at +10 -> +11 does, +11 -> +12 does not).
 */
export const PREMIUM_UPGRADE_MAX_RESULT = 11;
export function premiumUpgradeBonusFor(tdef, bonus) {
  const result = (Number(tdef?.itemLv) || 0) + 1;
  return Number(bonus) > 0 && result <= PREMIUM_UPGRADE_MAX_RESULT ? Number(bonus) : 0;
}

/** Success % of a target with its registered support items (+ the running Holy Water ItemUpgradeRate, see above). */
export function upgradeRate(db, tdef, supports = [], premiumBonus = 0) {
  const row = upgradeRow(db, tdef);
  if (!row) return 0;
  let p = (Number(tdef.reqLv) || 0) <= 144 ? Number(row.rateUpTo144) : Number(row.rateFrom145);
  for (const s of supports) if (s) p += Number(s.upgradeRate) || 0;
  p += premiumUpgradeBonusFor(tdef, premiumBonus);
  return Math.max(0, Math.min(100, p));
}

/**
 * Level after a failed attempt (or -1 = destroyed). protect: null | {kind:'safe'|'grace'|'glory'|'spirit', maxDrop}
 */
export function failLevel(db, row, lv, protect, rng = Math.random) {
  const safeRows = (db.T?.itemUpgradeSafe?.rows || []).filter(r => Number(r.UPGRADE_LEVEL) === lv).sort((a, b) => a.BACKWARD_LEVEL - b.BACKWARD_LEVEL);
  const byRatio = (col) => {
    if (!safeRows.length) return Math.max(0, lv - 1);
    const x = rng() * 100;
    for (const r of safeRows) if (x < Number(r[col])) return Number(r.BACKWARD_LEVEL);
    return Number(safeRows[safeRows.length - 1].BACKWARD_LEVEL);
  };
  const pen = String(row?.penalty || 'NOT_FAIL');
  if (protect) {
    if (protect.kind === 'spirit') return lv;
    if (protect.kind === 'glory') return Math.max(0, lv - (rng() < 0.5 ? 0 : 1));
    if (pen === 'NOT_FAIL') return lv;
    const to = byRatio('BACKWARD_RATIO_EX');
    return Math.max(to, lv - (protect.maxDrop ?? 99));
  }
  switch (pen) {
    case 'NOT_FAIL': case '': return lv;
    case 'BACK_TO_ZERO': return 0;
    case 'BACK_TO_CONST_N': return Math.min(lv, Number(row.value) || 0);
    case 'BACKWARD_ITEM': return byRatio('BACKWARD_RATIO');
    case 'ALLITEM_DESTRUCT': return -1;
    default: return lv;
  }
}

export function registerUpgrade(sys) {
  const g = sys.game, db = sys.db;
  let K = null, W = null;
  const S = {};
  const str = (c, k) => sys.str(c, k) || '';

  const target = () => S.item.inst;
  const tdef = () => S.item.def;
  const supports = () => [S.rate1.def, S.rate2.def].filter(Boolean);
  // the running Holy Water ItemUpgradeRate (game.premium mirrors the server-owned state online); the server applies the same rule
  const premiumBonus = () => Number(g.premium?.upgradeRateBonus?.()) || 0;
  const protectOf = () => {
    for (const s of [S.rate1, S.rate2]) {
      const r = s.def && subRow(db, s.def.index);
      if (!r) continue;
      if (Number(r.Group) === 9) return { kind: 'spirit' };
      if (Number(r.Group) === 6) return { kind: 'glory' };
      if (Number(r.Group) === 5 && (Number(tdef()?.itemLv) || 0) >= 1) return { kind: 'grace', maxDrop: 3 };
    }
    // Blessed Blacksmith's Talisman / Talisman Protector (kind 1/21): "Upgrade level can go down by up to 3"
    if (S.safe.def) return { kind: 'safe', maxDrop: Number(S.safe.def.code) === 21 ? 3 : 99 };
    return null;
  };

  function refresh() {
    if (!W) return;
    const def = tdef();
    const row = def ? upgradeRow(db, def) : null;
    W.control('pan_ready').setVisible(!def);
    W.control('pan_select_stone').setVisible(!!def);
    W.control('lbl_upgrade_item').setText(def ? def.name : '');
    const r1 = S.rate1.def ? Number(S.rate1.def.upgradeRate) || 0 : 0;
    const r2 = S.rate2.def ? Number(S.rate2.def.upgradeRate) || 0 : 0;
    W.control('lbl_percent').setText(r1 ? `+${r1}%` : '');
    W.control('lbl_growbless_per').setText(`+ ${r2}%`);
    const rate = def ? upgradeRate(db, def, supports(), premiumBonus()) : 0;
    W.control('lbl_upgrade_rate').setText(def ? (str(350, 196) || '%d %%').replace('%d', rate).replace('%%', '%') : '');
    W.control('lbl_cost').setText(row ? fmt(row.costDil) : '');
    W.control('pan_stone_item').setVisible(!!S.stone.inst);
    W.control('pan_cash_caron').setVisible(!!S.rate1.inst);
    W.control('pan_cash_growbless').setVisible(!!S.rate2.inst);
    W.control('pan_cash_safe').setVisible(!!S.safe.inst);
    // explanation line: what to add next
    const exp = !def ? str(1001, 161) : !S.stone.inst ? str(1001, 162) : (!S.rate1.inst && !S.rate2.inst) ? str(1001, 163) : str(1001, 119);
    W.control('lbl_explanation').setText(exp);
    const needRuin = def && RUIN[Number(def.rank)];
    W.control('btn_strength').setEnabled(!!(def && row && S.stone.inst && (!needRuin || S.ruin.inst) && !K.busy));
    // pan_select_stone lists (stones usable for this row, owned support items)
    if (def) {
      const stones = row ? [...new Set([row.stone1, row.stone2].filter(Boolean).map(Number))] : [];
      if (needRuin) stones.push(...needRuin);
      S.list.stones.forEach((sl, i) => { const it = stones[i]; sl.show(it ?? null, it != null ? K.have(it) : null); sl.data = it; });
      const owned = (pred) => [...new Set(sys.bag.list.map(i => i.itemIndex))].filter(i => { const d = db.def(i); return subRow(db, i) && pred(d); });
      const rateItems = owned(d => supportOk(db, d, def, 'rate') === true && Number(subRow(db, d.index).Probability) === 1);
      const safeItems = owned(d => (supportOk(db, d, def, 'safe') === true) || ([6, 9].includes(Number(subRow(db, d.index).Group)) && supportOk(db, d, def, 'rate') === true));
      S.list.rates.forEach((sl, i) => { const it = rateItems[i]; sl.show(it ?? null, it != null ? K.have(it) : null); sl.data = it; });
      S.list.safes.forEach((sl, i) => { const it = safeItems[i]; sl.show(it ?? null, it != null ? K.have(it) : null); sl.data = it; });
    }
  }

  const acceptTarget = (inst, def) => {
    if (!def?.slot) return [1001, 5];
    if (Number(def.type) === 6) return [1001, 4];
    if (!upgradeRow(db, def)) return [1001, 4];
    if (inst.expiresAt && inst.expiresAt < Date.now()) return [1001, 4];
    return true;
  };
  const acceptStone = (inst, def) => {
    const row = upgradeRow(db, tdef());
    if (!tdef()) return [1001, 22];
    if (!row) return [1001, 4];
    return [row.stone1, row.stone2].map(Number).includes(def.index) ? true : [1001, 21];
  };
  const acceptRuin = (inst, def) => {
    const need = RUIN[Number(tdef()?.rank)];
    if (!tdef()) return [1001, 22];
    return need && need.includes(def.index) ? true : [1001, 5];
  };
  const acceptRate = (other) => (inst, def) => {
    if (!tdef()) return [1001, 22];
    if (upgradeRate(db, tdef(), [], premiumBonus()) >= 100 && Number(subRow(db, def.index)?.Safety) !== 1) return [1001, 279];   // "Not used if success rate is 100%."
    const ok = supportOk(db, def, tdef(), 'rate');
    if (ok !== true) return ok;
    const o = other().def;
    if (o && Number(subRow(db, o.index)?.Group) === Number(subRow(db, def.index)?.Group)) return [311, 26];
    return true;
  };
  const acceptSafe = (inst, def) => (tdef() ? supportOk(db, def, tdef(), 'safe') : [1001, 22]);

  /** Put a bag item into the right slot (right click in the bag, list clicks). */
  function offer(inst) {
    const def = db.def(inst.itemIndex);
    if (!def) return false;
    if (!target() && def.slot) return S.item.put(inst);
    if (def.slot) { S.item.clear(false); for (const s of [S.stone, S.ruin, S.rate1, S.rate2, S.safe]) s.clear(false); return S.item.put(inst); }
    if (!target()) { sys.msg(1001, 22); return true; }
    const row = upgradeRow(db, tdef());
    if (row && [row.stone1, row.stone2].map(Number).includes(def.index)) return S.stone.put(inst) || true;
    if (RUIN[Number(tdef().rank)]?.includes(def.index)) return S.ruin.put(inst) || true;
    const sr = subRow(db, def.index);
    if (sr) {
      if (Number(sr.Group) === 3) return S.safe.put(inst) || true;
      return (!S.rate1.inst ? S.rate1.put(inst) : S.rate2.put(inst)) || true;
    }
    sys.msg(1001, 5);
    return true;
  }
  function pick(itemIndex) {
    if (itemIndex == null) return;
    const inst = K.findInBag(itemIndex);
    if (!inst) { sys.msg(null, null, clean(str(350, 166)).split('\\')[0]); return; }
    offer(inst);
  }
  /** "Register": the stone, the best rate items and a protection item from the bag. */
  function autoFill() {
    const def = tdef();
    if (!def) { sys.msg(1001, 22); return; }
    const row = upgradeRow(db, def);
    if (!row) { sys.msg(1001, 4); return; }
    if (!S.stone.inst) { const s = K.findInBag([row.stone1, row.stone2]); if (s) S.stone.put(s, { silent: true }); }
    const ruin = RUIN[Number(def.rank)];
    if (ruin && !S.ruin.inst) { const s = K.findInBag(ruin); if (s) S.ruin.put(s, { silent: true }); }
    const cands = sys.bag.list.filter(i => !sys.reserved?.has(i.uid) && subRow(db, i.itemIndex))
      .sort((a, b) => (Number(db.def(b.itemIndex)?.upgradeRate) || 0) - (Number(db.def(a.itemIndex)?.upgradeRate) || 0));
    const base = upgradeRate(db, def, [], premiumBonus());
    for (const c of cands) {
      const d = db.def(c.itemIndex);
      if (Number(subRow(db, d.index).Group) === 3) { if (!S.safe.inst && row.penalty !== 'NOT_FAIL') S.safe.put(c, { silent: true }); continue; }
      if (base >= 100 && Number(subRow(db, d.index).Safety) !== 1) continue;
      if (!S.rate1.inst) S.rate1.put(c, { silent: true }); else if (!S.rate2.inst) S.rate2.put(c, { silent: true });
    }
    if (!S.stone.inst) sys.msg(null, null, clean(str(350, 166)).split('\\')[0]);
    refresh();
  }

  async function reinforce() {
    if (!target() || !tdef() || K.busy) return;
    if (!K.validate()) { refresh(); return; }
    const inst = target(), def = tdef();
    const row = upgradeRow(db, def);
    if (!row) { sys.msg(1001, 4); return; }
    if (!S.stone.inst) { sys.msg(1001, 21); return; }
    if (RUIN[Number(def.rank)] && !S.ruin.inst) { sys.msg(null, null, clean(str(350, 166)).split('\\')[0]); return; }
    const cost = Number(row.costDil) || 0;
    if (sys.dil < cost) { sys.msg(1001, 3); return; }
    const protect = protectOf();
    const lv = Number(def.itemLv) || 0;
    // warnings: destruction possible without protection (1001:216/217 epic, 1001:167 +7, 1001:20 +4 and higher)
    let warn = str(1001, 119);
    if (row.penalty === 'ALLITEM_DESTRUCT' && !protect) warn = lv + 1 >= 7 ? str(1001, 167) : str(1001, 217);
    else if (lv >= 4 && !protect && row.penalty !== 'NOT_FAIL') warn = str(1001, 20);
    if(g.save.authority==='server') {
      const intent={uid:inst.uid,stone:S.stone.inst.uid,rates:[S.rate1.inst,S.rate2.inst].filter(Boolean).map(i=>i.uid),...(S.safe.inst?{safe:S.safe.inst.uid}:{}),...(S.ruin.inst?{ruin:S.ruin.inst.uid}:{})};
      const result=await K.review(warn,str(100,12),network=>network.action('upgrade',intent),()=>sys.dil>=cost);
      if(result)for(const slot of K.slots)slot.clear(false);refresh();return;
    }
    if (!(await K.confirm(warn, str(100, 12)))) return;
    if (!sys.bag.list.includes(inst) || !sys.spendDil(cost)) { sys.msg(1001, 3); return; }
    W.control('btn_strength').setEnabled(false);
    await K.progress(2, 98);
    const rate = upgradeRate(db, def, supports(), premiumBonus());
    // materials are used whatever happens
    K.consume(S.stone.inst, 1);
    if (S.ruin.inst) K.consume(S.ruin.inst, 1);
    for (const s of [S.rate1, S.rate2]) if (s.inst) K.consume(s.inst, 1);
    if (S.safe.inst && row.penalty !== 'NOT_FAIL') K.consume(S.safe.inst, 1);
    const ok = Math.random() * 100 < rate;
    let newLv = lv + 1;
    if (ok) {
      morph(sys, inst, def.next);
      sysSound(sys, 101);
      sys.msg(1001, 6);
      if (newLv >= (Number(db.equipment.formula?.byUpgradeNotifyLevel) || 9)) g.hud?.log?.(`${g.save.name}: ${inst.name}`, 'item');
    } else {
      sysSound(sys, 100);
      newLv = failLevel(db, row, lv, protect);
      if (newLv < 0) {
        sys.removeInst(inst);
        sys.msg(1001, 7);
      } else if (newLv < lv) {
        morph(sys, inst, indexAtLevel(db, def.index, newLv));
        sys.msg(null, null, clean(str(1001, 12)).replace('<itemlevel>', `+${newLv}`));
      } else sys.msg(1001, 11);
    }
    const kind={4:'weapon',5:'armor',2:'accessory'}[Number(def.type)]; g.events.emit('item:upgrade', { item: inst, ok, level: ok ? lv + 1 : newLv, destroyed: newLv < 0, kind });
    for (const s of K.slots) s.validate();
    if (S.item.inst && !sys.bag.list.includes(S.item.inst)) S.item.clear(false);
    S.item.draw();
    sys.changed('upgrade', { item: inst });
    refresh();
  }

  g.uiwin.registerWindow('upgrade', {
    script: 'game2/itemupgrade/ui_upgradewnd.txt',
    create(win) {
      W = win;
      K = new Crafting(sys, win, 'upgrade');
      const onChange = () => refresh();
      S.item = K.slot('upgrade_item', { accept: acceptTarget, count: false, onChange: () => { for (const s of [S.stone, S.ruin, S.rate1, S.rate2, S.safe]) if (s.inst && s.opts.accept(s.inst, s.def, s) !== true) s.clear(false); refresh(); } });
      S.stone = K.slot('stone_item', { accept: acceptStone, onChange });
      S.ruin = K.slot('stone_ruin', { accept: acceptRuin, onChange });
      S.rate1 = K.slot('cash_caron', { accept: acceptRate(() => S.rate2), onChange });
      S.rate2 = K.slot('cash_growbless', { accept: acceptRate(() => S.rate1), onChange });
      S.safe = K.slot('cash_safe', { accept: acceptSafe, onChange });
      const ready = win.control('pan_ready'), sel = win.control('pan_select_stone');
      S.examples = [1, 2, 3, 4, 5].map(i => K.slot(ready.control(`item_example${i}`), { view: true }));
      S.examples.forEach((s, i) => s.show(EXAMPLES[i]));
      const listSlot = (id) => { const s = K.slot(sel.control(id), { view: true, click: (sl) => pick(sl.data), dblclick: (sl) => pick(sl.data) }); return s; };
      S.list = {
        stones: [1, 2, 3, 4, 5].map(i => listSlot(`item_stone${i}`)),
        rates: [1, 2].map(i => listSlot(`item_substone${i}`)),
        safes: [3, 4].map(i => listSlot(`item_substone${i}`)),
      };
      sel.control('btn_resourcesetting').onClick(autoFill);
      sel.control('btn_strength').onClick(reinforce);
      g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      g.events.on('dil', () => { if (win.isOpen) refresh(); });
    },
    async onOpen(win, arg) {
      await db.tables();
      K.opened(win, arg, offer);
      refresh();
    },
    onClose() { K.closed(); },
    update(win) { K.tick(win); },
  });
}
