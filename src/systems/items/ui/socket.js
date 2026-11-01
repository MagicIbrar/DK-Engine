// Sockets (NPC Carmen / Isadora, jobs ITEMADDSOCKET / ITEM_REMOVE_STONE) and socket-stone insertion.
//
// Add a Socket: game2/itemupgrade/ui_new_itemaddsocketwnd.txt
//   upgrade_item / upgrade_wingitem  the target (weapon / armour / bracelet / belt; wings use itemwingsaddsocket.csv)
//   stone_socket_0..4   socket stones used as materials: + SocketStone_Rate % each (itemaddsocket.csv, 5 % -> max 25 %,
//                       1001:171 / 1001:173 "You can increase the success rate by 5% per socket (Maximum 25%)")
//   stone_special_socket  Soul of Alchemist (upgradesubitem group 8): + its upgradeRate %
//   pan_strength: item_substone1 = Liberty Essence for wing socket smelting (1001:175), item_substone2 = the Protection stone
//                 (group 7, 1001:176): a failed wing attempt otherwise destroys one existing socket
//   rate = itemaddsocket.csv [ITEM_LEVEL = required level] <GRADE>_Rate (Deka_Rate for DK items), cost <GRADE> dil.
//   Success adds an empty socket (4 at most, 1001:37). Failure: the materials and the dil are used (1001:33).
// Remove Socket Stone: game2/itemupgrade/ui_new_itemremovestone.txt
//   stone_socket_0..4 around the circle show the target's sockets - click the stone to remove (pan_socket_N_bg marks it)
//   stone_socket_item_0..3   Argates (+Agate_Rate %) / socket stones (+SocketStone_Rate %) (1001:43; at least one)
//   stone_cash_socket        Gemcraft Booster (kind 1/11): + its rate
//   item_plier               socket pliers (pet items only in this client: 1001:281)
//   rate = itemdelstone.csv <GRADE>_Rate (Deka_Rate for DK items) + materials, cost <GRADE>_DIL; wings: itemwingsdelstone.csv.
//   "Removing a Socket Stone destroys it. Failure may destroy the socket." (1001:170): success empties the socket (the
//   stone is destroyed), failure destroys the socket with its stone.
// Insertion: drag a socket stone (kind 1/0) onto a bag item with an empty socket; itemsocket.csv says which item
// categories and ranks each stone fits (both flags must be 1). Confirm -> the stone fills the first empty socket.
import { Crafting, sysSound, clean, rich } from './craft.js';
import { fmt } from './common.js';
import { documentedSocketLimit } from '../socket-capacity.js';

const GRADE_COL = { normal: 'NORMAL', magic: 'MAGIC', noble: 'NOBLE', divine: 'DIVIN' };
const RANK_COL = { 0: 'NORMAL', 1: 'NORMAL', 2: 'EVENT', 3: 'REGEND', 4: 'CASH', 5: 'PVP', 6: 'COLOSSEUM', 7: 'NORMAL', 8: 'NORMAL', 9: 'NORMAL', 10: 'EPIC', 11: 'CASH', 12: 'EPIC', 13: 'EPIC', 14: 'EPIC', 15: 'EPIC', 16: 'PVP' };
const SOCKET_CAT = { 1063: 'WINSWORD', 1280: 'HELMET', 1281: 'COAT', 1282: 'PANTS', 1283: 'BOOTS', 1284: 'GLOVES', 1291: 'BANGLE', 1292: 'ARMOR_BELT', 1295: 'BANGLE', 1296: 'ARMOR_BELT' };
const MAX_SOCKETS = 4;
const LIBERTY = 4000776;

export const isStone = (def) => Number(def?.type) === 1 && Number(def?.code) === 0;
const isWing = (def) => Number(def?.type) === 6 && Number(def?.code) === 1;
const isArgate = (def) => Number(def?.type) === 1 && Number(def?.code) === 1 && /argate/i.test(def?.name || '');

/** Socket-able equipment (weapon / armour / bracelet / belt / wing). */
export function socketable(def) {
  if (!def?.slot) return false;
  if (isWing(def)) return true;
  const t = Number(def.type), c = Number(def.code);
  if (t === 4) return ![15, 16, 19, 30, 31, 33].includes(c);
  if (t === 5) return c <= 4 || [11, 12, 15, 16].includes(c);
  return false;
}

/** Can this socket stone go into this item (itemsocket.csv category + rank flags)? */
export function stoneFits(db, stoneDef, def) {
  const rows = db.T?.socketStones?.rows || [];
  if (!db._sockIdx) { db._sockIdx = new Map(); for (const r of rows) db._sockIdx.set(Number(r.SocketIndex), r); }
  const r = db._sockIdx.get(Number(stoneDef?.index));
  if (!r) return false;
  const kind = db.kind(def);
  const cat = isWing(def) ? 'WINGS' : SOCKET_CAT[kind] || db.equipment.upgrade?.categoryByKind?.[kind];
  if (isWing(def)) return Number(r.WINGS) === 1;
  if (!cat || Number(r[cat]) !== 1) return false;
  const rc = RANK_COL[Number(def.rank)] || 'NORMAL';
  return Number(r[rc]) === 1;
}

function rowByLevel(rows, lv) {
  if (!rows?.length) return null;
  let best = rows[0];
  for (const r of rows) if (Number(r.ITEM_LEVEL) <= lv) best = r; else break;
  return best;
}

export function registerSockets(sys) {
  const g = sys.game, db = sys.db;
  const str = (c, k) => sys.str(c, k) || '';

  // ----------------------------------------------------------------------------------------------- add socket
  {
    let K = null, W = null;
    const S = {};
    const tInst = () => S.item.inst || S.wing.inst;
    const tDef = () => S.item.def || S.wing.def;
    const wingRow = (def) => (db.T?.wingAddSocket?.rows || []).find(r => Number(r.ItemIndex) === Number(def?.index)) || null;
    const calc = () => {
      const inst = tInst(), def = tDef();
      if (!inst) return null;
      if (isWing(def)) {
        const r = wingRow(def);
        return r ? { rate: Math.min(100, Number(r.Rate) || 0), cost: Number(r.Cost_Dil) || 0, need: Number(r.Need_Item_Count) || 0, needItem: Number(r.Need_Item) || LIBERTY } : null;
      }
      const row = rowByLevel(db.T?.addSocket?.rows, Number(def.reqLv) || 0);
      if (!row) return null;
      const col = GRADE_COL[inst.grade] || 'NORMAL';
      let rate = Number(def.rank) === 5 ? Number(row.Deka_Rate) : Number(row[`${col}_Rate`]);
      const per = Number(row.SocketStone_Rate) || 5;
      rate += Math.min(25, S.mats.filter(s => s.inst).length * per);
      if (S.special.def) rate += Number(S.special.def.upgradeRate) || 0;
      return { rate: Math.max(0, Math.min(100, rate)), cost: Number(row[col]) || 0 };
    };
    const refresh = () => {
      if (!W) return;
      const def = tDef(), c = calc();
      W.control('pan_ready').setVisible(!def);
      W.control('pan_strength').setVisible(!!def);
      W.control('lbl_upgrade_item').setText(def ? `${def.name}${tInst()?.sockets?.length ? ` (${tInst().sockets.length})` : ''}` : '');
      W.control('lbl_percent').setText(c ? `${c.rate}%` : '');
      W.control('lbl_cost').setText(c ? fmt(c.cost) : '');
      W.control('lbl_explanation').setText(!def ? str(1001, 158) : str(1001, 159));
      S.mats.forEach((s, i) => W.control(`pan_socket_${i}_bg`).setVisible(!!s.inst));
      W.control('pan_special_bg').setVisible(!!S.special.inst);
      W.control('btn_strength').setEnabled(!!(def && c && !K.busy));
      W.control('lbl_substone_1').setText(isWing(def) && c ? `${fmt(K.have(c.needItem))} / ${fmt(c.need)}` : '');
    };
    const acceptTarget = (inst, def) => {
      if (!socketable(def)) return [1001, 30];
      if (Number(def.rank) === 4 && !isWing(def)) return [1001, 36];
      if ((inst.sockets?.length || 0) >= (documentedSocketLimit(db, def) ?? MAX_SOCKETS)) return [1001, 37];
      if (isWing(def) && !wingRow(def)) return [1001, 36];
      return true;
    };
    const acceptMat = (inst, def) => {
      if (!tInst()) return [1001, 30];
      if (isWing(tDef())) return [1001, 174];
      return isStone(def) ? true : [1001, 32];
    };
    function offer(inst) {
      const def = db.def(inst.itemIndex);
      if (def?.slot) { K.releaseAll(); return (isWing(def) ? S.wing : S.item).put(inst) || true; }
      if (!tInst()) { sys.msg(1001, 30); return true; }
      if (isStone(def)) { const free = S.mats.find(s => !s.inst); if (free) free.put(inst); return true; }
      if (def?.index === LIBERTY) return S.essence.put(inst) || true;
      const sr = (db.T?.upgradeSubItem?.rows || []).find(r => Number(r.ItemIndex) === def?.index);
      if (sr && Number(sr.Group) === 8) return S.special.put(inst) || true;
      if (sr && Number(sr.Group) === 7) return S.protect.put(inst) || true;
      sys.msg(1001, 32);
      return true;
    }
    async function refine() {
      if (!tInst() || K.busy) return;
      if (!K.validate()) { refresh(); return; }
      const inst = tInst(), def = tDef();
      const c = calc();
      if (!c) { sys.msg(1001, 36); return; }
      if ((inst.sockets?.length || 0) >= (documentedSocketLimit(db, def) ?? MAX_SOCKETS)) { sys.msg(1001, 37); return; }
      if (isWing(def) && K.have(c.needItem) < c.need) { sys.msg(1001, 169); return; }
      if (sys.dil < c.cost) { sys.msg(1001, 44); return; }
      if(g.save.authority==='server'){
        const intent={uid:inst.uid,action:'add',materials:S.mats.filter(s=>s.inst).map(s=>s.inst.uid),...(S.special.inst?{support:S.special.inst.uid}:{}),...(S.protect.inst?{protect:S.protect.inst.uid}:{})};
        const result=await K.review(str(1001,119),str(100,10),network=>network.action('socket',intent),()=>sys.dil>=c.cost&&(!isWing(def)||K.have(c.needItem)>=c.need));
        if(result)for(const s of K.slots)s.clear(false);refresh();return;
      }
      if (!(await K.confirm(str(1001, 119), str(100, 10)))) return;
      if (!sys.bag.list.includes(inst) || !sys.spendDil(c.cost)) { sys.msg(1001, 44); return; }
      await K.progress(2, 102);
      const protectedWing = !!S.protect.inst;
      for (const s of [...S.mats, S.special, S.protect]) if (s.inst) K.consume(s.inst, 1);
      if (isWing(def)) { let left = c.need; for (const it of sys.bag.list.filter(i => i.itemIndex === c.needItem)) { if (left <= 0) break; const k = Math.min(left, it.count || 1); K.consume(it, k); left -= k; } }
      sys.msg(null, null, clean(str(1001, 34)).replace('<VALUE>', fmt(c.cost)));
      const ok = Math.random() * 100 < c.rate;
      if (ok) {
        inst.sockets = [...(inst.sockets || []), 0];
        sysSound(sys, 101); sys.msg(1001, 35);
      } else {
        sysSound(sys, 100); sys.msg(1001, 33);
        if (isWing(def) && !protectedWing && inst.sockets?.length) { inst.sockets.pop(); if (!inst.sockets.length) delete inst.sockets; }
      }
      g.events.emit('item:socket', { item: inst, ok, action: 'add' });
      if(ok)g.events.emit('life:dekapass:event',{main:7,sub:23,value:inst.itemIndex,count:1});
      for (const s of K.slots) s.validate();
      S.item.draw(); S.wing.draw();
      sys.changed('socket', { item: inst });
      refresh();
    }
    g.uiwin.registerWindow('addsocket', {
      script: 'game2/itemupgrade/ui_new_itemaddsocketwnd.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'addsocket');
        const onChange = () => refresh();
        const tChange = () => { for (const s of [...S.mats, S.special, S.essence, S.protect]) if (s.inst && s.opts.accept(s.inst, s.def, s) !== true) s.clear(false); refresh(); };
        S.item = K.slot('upgrade_item', { accept: (i, d) => (isWing(d) ? [1001, 30] : acceptTarget(i, d)), count: false, onChange: tChange });
        S.wing = K.slot('upgrade_wingitem', { accept: (i, d) => (isWing(d) ? acceptTarget(i, d) : [1001, 38]), count: false, onChange: tChange });
        win.control('upgrade_wingitem').hide();
        S.item.opts.onChange = () => { if (S.item.inst) S.wing.clear(false); tChange(); };
        S.wing.opts.onChange = () => { if (S.wing.inst) S.item.clear(false); win.control('upgrade_wingitem').setVisible(!!S.wing.inst); win.control('upgrade_item').setVisible(!S.wing.inst); tChange(); };
        S.mats = [0, 1, 2, 3, 4].map(i => K.slot(`stone_socket_${i}`, { accept: acceptMat, count: false, onChange }));
        S.special = K.slot('stone_special_socket', {
          accept: (i, d) => { if (!tInst()) return [1001, 30]; if (isWing(tDef())) return [1001, 174]; const sr = (db.T?.upgradeSubItem?.rows || []).find(r => Number(r.ItemIndex) === d.index); return sr && Number(sr.Group) === 8 ? true : [1001, 32]; },
          count: false, onChange,
        });
        S.essence = K.slot('item_substone1', { accept: (i, d) => (!tInst() ? [1001, 30] : !isWing(tDef()) ? [1001, 38] : d.index === (calc()?.needItem ?? LIBERTY) ? true : [1001, 169]), onChange });
        S.protect = K.slot('item_substone2', {
          accept: (i, d) => { if (!tInst() || !isWing(tDef())) return [1001, 38]; const sr = (db.T?.upgradeSubItem?.rows || []).find(r => Number(r.ItemIndex) === d.index); return sr && Number(sr.Group) === 7 ? true : [1001, 169]; },
          onChange,
        });
        win.control('btn_strength').onClick(refine);
        rich(win.control('lbl_ready_desc'), str(1001, 171).replace(/\n/g, '\n'));
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) { await db.tables(); K.opened(win, arg, offer); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // ----------------------------------------------------------------------------------------------- remove stone
  {
    let K = null, W = null;
    const S = { pick: -1 };
    const tInst = () => S.item.inst;
    const tDef = () => S.item.def;
    const calc = () => {
      const inst = tInst(), def = tDef();
      if (!inst) return null;
      if (isWing(def)) {
        const r = (db.T?.wingRemoveStone?.rows || []).find(x => Number(x.ItemIndex) === def.index);
        if (!r) return null;
        let rate = Number(r.Rate) || 0;
        if (S.cash.def) rate += Number(S.cash.def.upgradeRate) || 0;
        return { rate: Math.min(100, rate), cost: Number(r.Cost_Dil) || 0 };
      }
      const row = rowByLevel(db.T?.removeStone?.rows, Number(def.reqLv) || 0);
      if (!row) return null;
      const col = GRADE_COL[inst.grade] || 'NORMAL';
      let rate = Number(def.rank) === 5 ? Number(row.Deka_Rate) : Number(row[`${col}_Rate`]);
      for (const s of S.mats) if (s.def) rate += isStone(s.def) ? Number(row.SocketStone_Rate) || 0 : Number(row.Agate_Rate) || 0;
      if (S.cash.def) rate += Number(S.cash.def.upgradeRate) || 0;
      return { rate: Math.max(0, Math.min(100, rate)), cost: Number(row[`${col}_DIL`]) || 0 };
    };
    const refresh = () => {
      if (!W) return;
      const inst = tInst(), def = tDef(), c = calc();
      W.find('lbl_upgrade_item')?.setText(def ? def.name : '');
      W.control('lbl_percent').setText(c ? `${c.rate}%` : '');
      W.control('lbl_cost').setText(c ? fmt(c.cost) : '');
      W.control('lbl_explanation').setText(!def ? str(1001, 41) : S.pick < 0 ? str(1001, 43) : '');
      const socks = inst?.sockets || [];
      if (S.pick >= 0 && !socks[S.pick]) S.pick = -1;
      S.view.forEach((v, i) => {
        const has = i < socks.length;
        v.show(has && socks[i] ? socks[i] : null);
        W.control(`pan_socket_${i}_bg`).setVisible(i === S.pick);
        v.ctrl.setVisible(true);
        v.ctrl.el.style.opacity = has ? '1' : '0.35';
      });
      S.mats.forEach((s, i) => W.control(`pan_stone_${i}_check`).setVisible(!!s.inst));
      W.control('pan_plier_bg_check').setVisible(!!S.plier.inst);
      W.control('pan_cash_bg').setVisible(!!S.cash.inst);
      W.control('btn_strength').setEnabled(!!(inst && c && S.pick >= 0 && !K.busy));
    };
    const acceptTarget = (inst, def) => {
      if (!socketable(def)) return [1001, 41];
      if (Number(def.rank) === 4 && !isWing(def)) return [1001, 42];
      if (!(inst.sockets || []).some(Boolean)) return [1001, 45];
      return true;
    };
    function offer(inst) {
      const def = db.def(inst.itemIndex);
      if (def?.slot) { K.releaseAll(); S.pick = -1; S.item.put(inst); return true; }
      if (!tInst()) { sys.msg(1001, 41); return true; }
      if (isStone(def) || isArgate(def)) { const free = S.mats.find(s => !s.inst); if (free) free.put(inst); return true; }
      if (Number(def?.type) === 1 && Number(def?.code) === 11) return S.cash.put(inst) || true;
      sys.msg(1001, 43);
      return true;
    }
    async function remove() {
      if (!tInst() || K.busy) return;
      if (!K.validate()) { refresh(); return; }
      const inst = tInst(), def = tDef();
      const c = calc();
      if (!c) { sys.msg(1001, 51); return; }
      if (S.pick < 0 || !inst.sockets?.[S.pick]) { sys.msg(1001, 46); return; }
      if (!isWing(def) && !S.mats.some(s => s.inst)) { sys.msg(1001, 43); return; }
      if (sys.dil < c.cost) { sys.msg(1001, 44); return; }
      if(g.save.authority==='server'){
        const intent={uid:inst.uid,action:'remove',slot:S.pick,materials:S.mats.filter(s=>s.inst).map(s=>s.inst.uid),...(S.cash.inst?{support:S.cash.inst.uid}:{})};
        const result=await K.review(str(1001,170),str(100,13),network=>network.action('socket',intent),()=>sys.dil>=c.cost);
        if(result)for(const s of K.slots)s.clear(false);refresh();return;
      }
      if (!(await K.confirm(str(1001, 170), str(100, 13)))) return;
      if (!sys.bag.list.includes(inst) || !sys.spendDil(c.cost)) { sys.msg(1001, 44); return; }
      await K.progress(2, 102);
      for (const s of [...S.mats, S.cash, S.plier]) if (s.inst) K.consume(s.inst, 1);
      const ok = Math.random() * 100 < c.rate;
      if (ok) { inst.sockets[S.pick] = 0; sysSound(sys, 101); sys.msg(1001, 47); }
      else {
        inst.sockets.splice(S.pick, 1);
        if (!inst.sockets.length) delete inst.sockets;
        sysSound(sys, 100); sys.msg(1001, 48);
      }
      S.pick = -1;
      g.events.emit('item:socket', { item: inst, ok, action: 'remove' });
      for (const s of K.slots) s.validate();
      if (S.item.inst && !(S.item.inst.sockets || []).some(Boolean)) S.item.clear(false); else S.item.draw();
      sys.changed('socket', { item: inst });
      refresh();
    }
    g.uiwin.registerWindow('removestone', {
      script: 'game2/itemupgrade/ui_new_itemremovestone.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'removestone');
        const onChange = () => refresh();
        S.item = K.slot('upgrade_item', { accept: acceptTarget, count: false, onChange: () => { S.pick = -1; for (const s of [...S.mats, S.cash, S.plier]) if (s.inst && !tInst()) s.clear(false); refresh(); } });
        S.view = [0, 1, 2, 3, 4].map(i => K.slot(`stone_socket_${i}`, {
          view: true,
          click: () => { const socks = tInst()?.sockets || []; if (!socks[i]) { sys.msg(1001, 46); return; } S.pick = S.pick === i ? -1 : i; refresh(); },
          emptyTip: () => (tInst() && i < (tInst().sockets?.length || 0) ? '- Empty -' : null),
        }));
        S.mats = [0, 1, 2, 3].map(i => K.slot(`stone_socket_item_${i}`, { accept: (inst, d) => (!tInst() ? [1001, 41] : isStone(d) || isArgate(d) ? true : [1001, 43]), count: false, onChange }));
        // socket pliers exist only for pet items in this client (1001:235 / 1001:281)
        S.plier = K.slot('item_plier', { accept: (inst, d) => (!tInst() ? [1001, 41] : /plier/i.test(d.name || '') ? [1001, 281] : [1001, 43]), onChange });
        S.cash = K.slot('stone_cash_socket', { accept: (inst, d) => (!tInst() ? [1001, 41] : Number(d.type) === 1 && Number(d.code) === 11 ? true : [1001, 43]), count: false, onChange });
        win.control('btn_strength').onClick(remove);
        rich(win.control('lbl_subcashitem'), str(1001, 160));
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) { await db.tables(); S.pick = -1; K.opened(win, arg, offer); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // ----------------------------------------------------------------------------------------------- insertion
  /** Drag a socket stone onto a bag item: returns true when handled (inserted or refused with a message). */
  let insertionPending = false;
  sys.insertStone = async (stone, target) => {
    if (insertionPending) return true;
    const selection = {
      stone: stone?.uid, target: target?.uid, stoneIndex: stone?.itemIndex, targetIndex: target?.itemIndex,
      sockets: JSON.stringify(target?.sockets), authority: g.save?.authority, character: g.save?.id,
      network: g.network, lease: g.network?.token,
    };
    const sessionCurrent = () => g.save?.authority === selection.authority && g.save?.id === selection.character &&
      (selection.authority !== 'server' || (g.network === selection.network && g.network?.token === selection.lease &&
        !g.network?.disposed && g.network?.ready !== false && g.network?.active !== false && typeof g.network?.action === 'function'));
    const current = () => {
      const stone = sys.bag.list.find(item => item.uid === selection.stone), target = sys.bag.list.find(item => item.uid === selection.target);
      const now = typeof g.now === 'function' ? g.now() : Date.now();
      return stone && target && stone !== target && stone.itemIndex === selection.stoneIndex && target.itemIndex === selection.targetIndex &&
        JSON.stringify(target.sockets) === selection.sockets && (stone.count ?? 1) >= 1 &&
        !(stone.expiresAt && stone.expiresAt <= now) && !(target.expiresAt && target.expiresAt <= now) ? { stone, target } : null;
    };
    if (!selection.stone || !selection.target) return false;
    insertionPending = true;
    try {
      await db.tables();
      const sd = db.def(selection.stoneIndex), td = db.def(selection.targetIndex);
      if (!isStone(sd) || !td) return false;
      if (!sessionCurrent() || !current()) { sys.msg(1001, 118); return true; }
      if (!socketable(td) || !target.sockets?.length) { sys.msg(1001, 45); return true; }
      const limit = documentedSocketLimit(db, td);
      if (limit !== null && target.sockets.length > limit) { sys.msg(1001, 37); return true; }
      if (!target.sockets.some(s => !s)) { sys.msg(1001, 37); return true; }
      if (!stoneFits(db, sd, td)) { sys.msg(1001, 31); return true; }
      const ans = await g.uiwin.msgbox(`[${sd.name}]\n${td.name}`, { kind: 'yesno', title: str(310, 1) || 'Upgrade Socket' });
      if (ans !== 'yes') return true;
      // SSE replaces bag instances while the modal is open. Resolve only the
      // reviewed UIDs, with the same item definitions and socket layout.
      const live = sessionCurrent() && current();
      if (!live) { sys.msg(1001, 118); return true; }
      const currentStone = db.def(live.stone.itemIndex), currentTarget = db.def(live.target.itemIndex);
      const k = live.target.sockets?.findIndex(s => !s);
      if (!isStone(currentStone) || !socketable(currentTarget) || !stoneFits(db, currentStone, currentTarget) || k == null || k < 0) { sys.msg(1001, 31); return true; }
      if (selection.authority === 'server') return !!(await selection.network.action('socket', { uid: selection.target, action: 'insert', stone: selection.stone }));
      if (!sys.bag.take(live.stone, 1)) return true;
      live.target.sockets[k] = currentStone.index;
      sysSound(sys, 101);
      sys.msg(null, null, `${currentStone.name} -> ${currentTarget.name}`);
      g.events.emit('item:socket', { item: live.target, ok: true, action: 'insert', stone: currentStone.index });
      sys.changed('socket', { item: live.target });
      return true;
    } finally { insertionPending = false; }
  };
}
