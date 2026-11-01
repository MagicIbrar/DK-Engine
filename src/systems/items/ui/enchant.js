// Option crafting, branding / dismantling / amplifying and crests - the item NPC windows of the items system.
//
// 'optionupgrade'  NPC Carmen (ITEMOPTIONUPGRADE): game2/itemupgrade/ui_optionupgradewnd_renew.txt "Create/Remove Option".
//   Options 1..4 of an item (instance rnd[k]) are crafted in order and removed from the bottom (1001:276).
//   itemoptionupgrade.csv row (ITEM_OPTION = the option slot k, ITEM_LEVEL = the item's required level):
//     required Marvric (stone_item): LOW_OPTION_STONE_INDEX (Pess 1-2, Nium 3, Tatum 4) x STONE_COUNT, or Cho Marvric
//       (HI_OPTION_STONE_INDEX) which crafts 1 or 2 options (HI_OPTION_RATE_0/1);
//     success SUCCESS_RATE / 100000 x Alchemist's Will (cash_lower_item, x2..x5, "x2" label);
//     failure: LOW/HI_PENALTY_RATE_0/1/2 = the chance that 0 / 1 / 2 existing options are lost ("option's level decreased
//       by 1/2", 1001:69-71) unless an Alchemist's Protector (cash_upper_item) is registered;
//     DK items (rank 5) also need a Ruin Marvric, Colosseum items a Colosseum Marvric (ruin_stone_item);
//     cost ASK_DIL. Grades cap the count: Magic 2, Noble 3, Divine Noble 4 (Marvric item text); Normal items none.
//   Removal: Alchemist's Arrangement (remove_item) removes the bottom option (100 %, 1001:79).
//   Right panel: the option list of the selected option tab (btn_info1..4) from items-options.json pools.
// 'incuse'  NPC Maximus/Axion/Pablos (ITEMINCUSE): game2/itemupgrade/ui_itemincusewnd_renew.txt, tabs Dismantle /
//   Amplify / Brand (btn_tab_0..2, 1001:123-125).
//   Dismantle: weapon/armour + Disassembly Hammer (0/41) -> one result of itemdisassemble.csv [Value = item level]
//     (weighted by ItemRatio_k / Total Ratio), shown in pan_Resultitem rows with their chance.
//   Listed wings instead use their own itemwingdisassemble.csv output/bounds/DIL.
//     Inclusive bounded integer weighting is ENGINE_CHOSEN; native weights are absent.
//   Amplify: itemamplify.csv RESOURCE_COUNT lower Soul Stones -> 1 TARGET_INDEX Soul Stone, COST_DIL each, x attempts.
//   Brand: Soul Stone (kind 1/19, use.brandLevel) on weapon/armour/bracelet/belt: success per itemincusedice.csv
//     [ResultValue = stone level - item level] (per 1000); success engraves 4 options drawn from itemincuseoption.csv
//     [Level = stone level] (option No -> incuseoption.csv), capped by MaxCapacityLimit; check_lock_0..3 keep a line
//     (one Brand Option Lock item 0/42 per locked line).
// 'munzang'  Crest System (MUNZANG_MAN): game2/itemupgrade/ui_munzangwnd.txt. Costumes take 6 crests: slots 1-2 green
//   (group 1, kind 1/23), 3-4 blue (1/24), 5 purple (1/25), 6 orange (1/26) (crest item text). A crest adds the option of
//   itemmunzang_option.csv [index = crest item index - 4500000] (else its name's value), costs munzang_price.csv; six
//   crests add a bonus option (311:6) from itemmunzang_incuse.csv. Extract: Plier (1/27) one crest, Hot Plier (1/28) all;
//   without a plier the crest may be lost (311:48; the 50 % keep rate is an engine choice, crest-rules.js). Removal costs DIL
//   per crest grade (official guide 16: 1,000,000 / 2,000,000 / 4,000,000 / 5,000,000; Hot Plier none; 311:32 / 311:33).
import { Crafting, sysSound, clean, rich } from './craft.js';
import { fmt } from './common.js';
import { submitItemService } from '../../network/item-services.js';
import {fetchCSV} from '../../../engine/assets.js';
import {crestRule,loadCrestSources,CREST_SUPPORTED_EFFECTS,crestInsertPrice,crestExtractDil,ENGINE_CHOSEN_UNPROTECTED_CREST_KEEP_RATE} from '../crest-rules.js';
import {canonicalOptionCode} from '../option-identities.js';
import {optionDisplayValue} from '../native-option-values.js';
import {wingDismantleRule,rollWingDismantleCount} from '../wing-dismantle-rules.js';

const MARVRIC = { pess: 9904, nium: 9905, tatum: 9906, cho: 9907, ruin: 9909, colosseum: 9914 };
const GRADE_MAX = { normal: 0, magic: 2, noble: 3, divine: 4 };
const LOCK_KIND = [0, 42];
const HAMMER_KIND = [0, 41];

export function optCode(db, name) {
  return db.optionCode ? db.optionCode(name) : canonicalOptionCode(name, db.options?.optionTypes);
}
function optText(db, type, v) {
  const ot = db.optionType(type);
  const value=optionDisplayValue(type,v,db);
  return ot?.text ? ot.text.replace(/<VALUE>/g, fmt(value)) : `${ot?.label || `Option ${type}`} ${fmt(value)}`;
}
const rint = (a, b) => { a = Math.round(a); b = Math.round(b); if (b < a) [a, b] = [b, a]; return a + Math.floor(Math.random() * (b - a + 1)); };
const isKind = (def, [t, c]) => Number(def?.type) === t && Number(def?.code) === c;
export function brandable(def) {
  const t = Number(def?.type), c = Number(def?.code);
  return (t === 4 && ![15, 16, 19, 30, 31, 33].includes(c)) || (t === 5 && (c <= 4 || [11, 12, 15, 16].includes(c)));
}

export function registerEnchant(sys) {
  const g = sys.game, db = sys.db;
  const str = (c, k) => sys.str(c, k) || '';

  // =============================================================================================== option crafting
  {
    let K = null, W = null;
    const S = { tab: 0, auto: false, rows: [], lines: [] };
    const tInst = () => S.item.inst, tDef = () => S.item.def;
    const optRow = (k, lv) => {
      const rows = db.T?.optionUpgrade?.rows || [];
      if (!db._optUpIdx) { db._optUpIdx = new Map(); for (const r of rows) db._optUpIdx.set(`${r.ITEM_OPTION}|${r.ITEM_LEVEL}`, r); }
      return db._optUpIdx.get(`${k}|${Math.max(1, Math.min(250, lv || 1))}`) || null;
    };
    const next = () => (tInst()?.rnd?.length || 0);
    const cap = () => GRADE_MAX[tInst()?.grade || 'normal'] ?? 0;
    const ruinNeed = () => (Number(tDef()?.rank) === 5 ? MARVRIC.ruin : Number(tDef()?.rank) === 6 ? MARVRIC.colosseum : null);
    const calc = () => {
      const def = tDef();
      if (!def) return null;
      const k = next();
      const row = optRow(Math.min(3, k), Number(def.reqLv) || 1);
      if (!row) return null;
      const hi = S.stone.def?.index === Number(row.HI_OPTION_STONE_INDEX);
      let rate = Number(row.SUCCESS_RATE) / 1000;
      if (S.will.def) rate *= Math.max(1, Number(S.will.def.upgradeRate) || 2);
      return { k, row, hi, rate: Math.min(100, rate), cost: Number(row.ASK_DIL) || 0, stone: hi ? Number(row.HI_OPTION_STONE_INDEX) : Number(row.LOW_OPTION_STONE_INDEX), count: Number(row.STONE_COUNT) || 1 };
    };
    const poolOf = (k) => {
      const def = tDef();
      const slots = def?.optionPools || [];
      const [lo, hi] = slots[Math.min([0, 0, 1, 2][k] ?? 2, slots.length - 1)] || [0, 0];
      const out = new Map();
      for (let lv = lo || hi; lv <= hi && lv > 0; lv++) for (const r of db.options?.pools?.[lv] || []) {
        const [, type, min, max] = r;
        const e = out.get(type);
        if (!e) out.set(type, { type, min, max }); else { e.min = Math.min(e.min, min); e.max = Math.max(e.max, max); }
      }
      return [...out.values()];
    };
    const rollOption = (k) => {
      const def = tDef();
      const slots = def?.optionPools || [];
      const [lo, hi] = slots[Math.min([0, 0, 1, 2][k] ?? 2, slots.length - 1)] || [0, 0];
      if (!(hi > 0)) return null;
      const lv = rint(lo || hi, hi);
      const rows = db.options?.pools?.[lv];
      if (!rows?.length) return null;
      const r = rows[Math.floor(Math.random() * rows.length)];
      const v = rint(r[2], r[3]);
      return v ? [Number(r[1]), v] : null;
    };
    const refresh = () => {
      if (!W) return;
      const inst = tInst(), def = tDef(), c = calc();
      W.control('lbl_itemname').setText(def ? def.name : '');
      W.control('lbl_explanation').setText(!def ? clean(str(1001, 73)) : next() >= cap() ? clean(str(1001, 64)) : '');
      const rnd = inst?.rnd || [];
      const removing = !!S.arr.inst && rnd.length > 0;
      S.lines.forEach((l, i) => {
        const o = rnd[i];
        l.setVisible(!!o);
        if (o) { l.setText(optText(db, o[0], o[1])); l.setTextColor(removing && i === rnd.length - 1 ? 'ffff3030' : 'ffffffff'); }
      });
      const trash = W.control('pan_removeicon');
      trash.setVisible(removing);
      if (removing) trash.setRect(110, 291 + (rnd.length - 1) * 24 - 5);
      W.control('lbl_rate').setText(c ? `${(Math.round(c.rate * 100) / 100).toFixed(2)}%` : '');
      W.control('lbl_cost').setText(c ? fmt(c.cost) : '');
      W.control('lbl_num1').setText(c ? (str(1001, 290) || 'Owned: %d').replace('%d', fmt(K.have(c.stone))) + ` / ${c.count}` : '');
      W.control('lbl_num2').setText((str(1001, 290) || 'Owned: %d').replace('%d', fmt(K.have(60320))));
      W.control('lbl_num3').setText(ruinNeed() ? (str(1001, 290) || 'Owned: %d').replace('%d', fmt(K.have(ruinNeed()))) : '');
      W.control('lbl_num4').setText(S.will.def ? `x${Number(S.will.def.upgradeRate) || 2}` : '');
      W.control('lbl_num5').setText((str(1001, 290) || 'Owned: %d').replace('%d', fmt(K.have(60319))));
      W.control('btn_change').setEnabled(!!(def && c && S.stone.inst && !K.busy));
      W.control('btn_remove').setEnabled(!!(def && S.arr.inst && rnd.length && !K.busy));
      W.control('btn_automaterial').setVisible(S.auto);
      W.control('btn_manualmaterial').setVisible(!S.auto);
      // option list of the selected tab
      for (let i = 0; i < 4; i++) W.control(`btn_info${i + 1}`).setChecked(i === S.tab);
      const list = def ? poolOf(S.tab) : [];
      S.rows.forEach((r, i) => {
        const e = list[i];
        for (const x of r) x.setVisible(!!e);
        if (e) { r[0].setText(db.optionType(e.type)?.label || `Option ${e.type}`); r[1].setText(fmt(e.min)); r[2].setText(fmt(e.max)); }
      });
    };
    const acceptTarget = (inst, def) => {
      if (!def?.slot || !brandable(def) && Number(def.type) !== 2) return [1001, 77];
      if (!(def.optionPools || []).some(p => p?.[1] > 0)) return [1001, 72];
      return true;
    };
    function autoMaterials() {
      const c = calc();
      if (!c) return;
      if (!S.stone.inst) { const s = K.findInBag([c.stone]); if (s) S.stone.put(s, { silent: true }); }
      const rn = ruinNeed();
      if (rn && !S.ruin.inst) { const s = K.findInBag([rn]); if (s) S.ruin.put(s, { silent: true }); }
    }
    function offer(inst) {
      const def = db.def(inst.itemIndex);
      if (def?.slot) { K.releaseAll(); S.item.put(inst); if (S.auto) autoMaterials(); refresh(); return true; }
      if (!tInst()) { sys.msg(1001, 73); return true; }
      if (Number(def?.type) === 1 && Number(def?.code) === 12) return ([MARVRIC.ruin, MARVRIC.colosseum].includes(def.index) ? S.ruin : S.stone).put(inst) || true;
      if (Number(def?.type) === 1 && Number(def?.code) === 13) return S.will.put(inst) || true;
      if (Number(def?.type) === 1 && Number(def?.code) === 15) return S.protect.put(inst) || true;
      if (Number(def?.type) === 1 && Number(def?.code) === 14) return S.arr.put(inst) || true;
      sys.msg(1001, 77);
      return true;
    }
    async function processBar(seconds = 1.6) {
      const bg = W.control('pan_processbg'), bar = W.control('processbar');
      K.busy = true; bg.show(); sysSound(sys, 98);
      const t0 = performance.now();
      await new Promise(res => { const st = () => { const f = Math.min(1, (performance.now() - t0) / (seconds * 1000)); bar.setGauge?.(f); if (f >= 1) res(); else requestAnimationFrame(st); }; st(); });
      bg.hide(); K.busy = false;
    }
    async function craft() {
      const inst = tInst(), def = tDef();
      if (!inst || K.busy) return;
      if (!K.validate()) { refresh(); return; }
      const c = calc();
      if (!c) { sys.msg(1001, 64); return; }
      if (c.k >= cap()) { sys.msg(1001, 64); return; }
      if (!S.stone.inst || S.stone.def.index !== c.stone) { sys.msg(1001, 75); return; }
      if (K.have(c.stone) < c.count) { sys.msg(1001, 75); return; }
      const rn = ruinNeed();
      if (rn && !S.ruin.inst) { sys.msg(1001, 74); return; }
      if (sys.dil < c.cost) { sys.msg(1001, 65); return; }
      if(g.save.authority==='server'){const result=await g.network.action('craft',{operation:'option',uid:inst.uid,material:S.stone.inst.uid,...(S.ruin.inst?{ruin:S.ruin.inst.uid}:{}),...(S.will.inst?{support:S.will.inst.uid}:{}),...(S.protect.inst?{protect:S.protect.inst.uid}:{})});if(result){for(const s of K.slots)s.clear(false);refresh();}return;}
      if (!sys.spendDil(c.cost)) { sys.msg(1001, 65); return; }
      await processBar();
      const { spendItems } = await import('./craft.js');
      spendItems(sys, c.stone, c.count);
      if (S.ruin.inst) K.consume(S.ruin.inst, 1);
      if (S.will.inst) K.consume(S.will.inst, 1);
      const prot = !!S.protect.inst;
      if (S.protect.inst) K.consume(S.protect.inst, 1);
      const ok = Math.random() * 100 < c.rate;
      inst.rnd = inst.rnd || [];
      if (ok) {
        let n = 1;
        if (c.hi) { const x = Math.random() * 100000; n = x < Number(c.row.HI_OPTION_RATE_0) ? 1 : 2; }
        for (let i = 0; i < n && inst.rnd.length < cap(); i++) { const o = rollOption(inst.rnd.length); if (o) inst.rnd.push(o); }
        sysSound(sys, 101); sys.msg(1001, 60);
      } else {
        sysSound(sys, 100);
        const P = c.hi ? ['HI_PENALTY_RATE_0', 'HI_PENALTY_RATE_1', 'HI_PENALTY_RATE_2'] : ['LOW_PENALTY_RATE_0', 'LOW_PENALTY_RATE_1', 'LOW_PENALTY_RATE_2'];
        const x = Math.random() * 100000;
        let lose = 0, acc = 0;
        for (let i = 0; i < 3; i++) { acc += Number(c.row[P[i]]) || 0; if (x < acc) { lose = i; break; } }
        if (prot) lose = 0;
        lose = Math.min(lose, inst.rnd.length);
        if (lose) inst.rnd.splice(inst.rnd.length - lose, lose);
        sys.msg(1001, 69 + lose);
      }
      if (!inst.rnd.length) delete inst.rnd;
      g.events.emit('item:option', { item: inst, ok });
      for (const s of K.slots) s.validate();
      if (S.auto) autoMaterials();
      S.item.draw();
      sys.changed('upgrade', { item: inst });
      refresh();
    }
    async function removeOpt() {
      const inst = tInst();
      if (!inst || K.busy) return;
      if (!K.validate()) { refresh(); return; }
      if (!inst.rnd?.length) { sys.msg(1001, 80); return; }
      if (!S.arr.inst) { sys.msg(1001, 63); return; }
      if(g.save.authority==='server'){const result=await g.network.action('craft',{operation:'removeoption',uid:inst.uid,material:S.arr.inst.uid});if(result){for(const s of K.slots)s.clear(false);refresh();}return;}
      await processBar(1.2);
      K.consume(S.arr.inst, 1);
      inst.rnd.pop();
      if (!inst.rnd.length) delete inst.rnd;
      sysSound(sys, 101); sys.msg(1001, 79);
      for (const s of K.slots) s.validate();
      S.item.draw();
      sys.changed('upgrade', { item: inst });
      refresh();
    }
    g.uiwin.registerWindow('optionupgrade', {
      script: 'game2/itemupgrade/ui_optionupgradewnd_renew.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'optionupgrade');
        const onChange = () => refresh();
        const need = () => (tInst() ? true : [1001, 73]);
        S.item = K.slot('upgrade_item', { accept: acceptTarget, count: false, onChange: () => { for (const s of [S.stone, S.ruin, S.will, S.protect, S.arr]) if (s.inst && s.opts.accept(s.inst, s.def) !== true) s.clear(false); if (S.auto) autoMaterials(); refresh(); } });
        S.stone = K.slot('stone_item', { accept: (i, d) => (need() !== true ? need() : isKind(d, [1, 12]) && ![MARVRIC.ruin, MARVRIC.colosseum].includes(d.index) ? (calc() && [calc().stone, Number(calc().row.HI_OPTION_STONE_INDEX), Number(calc().row.LOW_OPTION_STONE_INDEX)].includes(d.index) ? true : [1001, 75]) : [1001, 77]), onChange });
        S.protect = K.slot('cash_upper_item', { accept: (i, d) => (need() !== true ? need() : !isKind(d, [1, 15]) ? [1001, 67] : tInst().grade === 'normal' ? [1001, 84] : true), onChange });
        S.ruin = K.slot('ruin_stone_item', { accept: (i, d) => (need() !== true ? need() : ruinNeed() === d.index ? true : [1001, 66]), onChange });
        S.will = K.slot('cash_lower_item', { accept: (i, d) => (need() !== true ? need() : isKind(d, [1, 13]) ? true : [1001, 67]), onChange });
        S.arr = K.slot('remove_item', { accept: (i, d) => (need() !== true ? need() : isKind(d, [1, 14]) ? (tInst().rnd?.length ? true : [1001, 80]) : [1001, 67]), onChange });
        // option lines (lbl_optiondetail is the hidden template of one line)
        const tpl = win.control('lbl_optiondetail');
        for (let i = 0; i < 4; i++) S.lines.push(tpl.cloneAs(`_${i}`, { y: 286 + i * 24, visible: false }));
        // right panel rows (clones of the header labels)
        // header rects of the script: lbl_optionname 10,153 / lbl_optionmin 131,153 / lbl_optionmax 209,153 (26 px rows of the art)
        const hdr = [['lbl_optionname', 10], ['lbl_optionmin', 131], ['lbl_optionmax', 209]].map(([id, x]) => [win.control(id), x]);
        for (let r = 0; r < 12; r++) S.rows.push(hdr.map(([h, x]) => { const c = h.cloneAs(`_r${r}`, { x, y: 153 + 26 * (r + 1), visible: false }); c.setTextColor('ffd2d2d2'); return c; }));
        for (let i = 0; i < 4; i++) win.control(`btn_info${i + 1}`).onClick(() => { S.tab = i; refresh(); });
        win.control('btn_change').onClick(craft);
        win.control('btn_remove').onClick(removeOpt);
        const toggle = () => { S.auto = !S.auto; if (S.auto) autoMaterials(); refresh(); };
        win.control('btn_automaterial').onClick(toggle);
        win.control('btn_manualmaterial').onClick(toggle);
        rich(win.control('lbl_infotooltip'), str(1001, 275));
        rich(win.control('lbl_infotooltip_bottom'), str(1001, 276));
        for (const id of ['lbl_material1', 'lbl_material2', 'lbl_material3', 'lbl_material4', 'lbl_material5', 'lbl_probability']) { const c = win.control(id); const t = c.getText?.(); if (t && /<color|<center/i.test(t)) rich(c, t); }
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) { await db.tables(); S.tab = 0; K.opened(win, arg, offer); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // =============================================================================================== dismantle / amplify / brand
  {
    let K = null, W = null;
    const S = { tab: 0, count: 1, results: [] };
    const pages = ['pan_disassemble', 'pan_amplify', 'pan_incuse'];
    const P = (i) => W.control(pages[i]);
    const dis = {}, amp = {}, br = {};
    const disRow = (def) => def?.slot === 'wing' ? (() => {const wing=wingDismantleRule(db,def.index);return wing?{wing}:null;})() : (db.T?.disassemble?.rows || []).find(r => Number(r.Value) === Math.max(1, Math.min(250, Number(def?.reqLv) || 1))) || null;
    const ampRow = (idx) => (db.T?.amplify?.rows || []).find(r => Number(r.RESOURCE_INDEX) === Number(idx)) || null;
    const brandRate = (stoneDef, def) => {
      const d = Math.max(-65, Math.min(100, (Number(stoneDef?.use?.brandLevel) || 0) - (Number(def?.reqLv) || 0)));
      const r = (db.T?.incuseDice?.rows || []).find(x => Number(x.ResultValue) === d);
      return r ? Number(r.SuccessRate) / 10 : 0;
    };
    const locks = () => [0, 1, 2, 3].filter(i => W.control(`check_lock_${i}`).isChecked?.());
    function refresh() {
      if (!W) return;
      for (let i = 0; i < 3; i++) { W.control(`btn_tab_${i}`).setChecked(i === S.tab); P(i).setVisible(i === S.tab); }
      W.control('lbl_title').setText(str(1001, [284, 285, 286][S.tab]));
      W.control('btn_request').setText(str(1001, [123, 124, 125][S.tab]));
      if (S.tab === 0) {
        const def = dis.target.def, row = def ? disRow(def) : null;
        P(0).control('lbl_disassemble_target_Info').setText(def ? def.name : '');
        P(0).control('lbl_disassemble_resource_Info').setText(dis.hammer.def ? dis.hammer.def.name : '');
        P(0).control('lbl_disassemble_resource_countInfo').setText(dis.hammer.def ? (str(1001, 290) || 'Owned: %d').replace('%d', fmt(K.have(dis.hammer.def.index))) : '');
        P(0).control('lbl_disassemble_cost').setText(fmt(row?.wing?.dil || 0));
        const outs = [];
        if(row?.wing)outs.push({it:row.wing.item,n:row.wing.min,range:row.wing.min===row.wing.max?String(row.wing.min):`${row.wing.min}~${row.wing.max}`});
        else if (row) for (let k = 1; k <= 5; k++) { const it = Number(row[`ItemIndex_${k}`]); if (it) outs.push({ it, ratio: Number(row[`ItemRatio_${k}`]) / Math.max(1, Number(row['Total Ratio'])) * 100, n: Number(row[`ItemCount_${k}`]) || 1 }); }
        S.results.forEach((r, i) => {
          const o = outs[i];
          r.pan.setVisible(!!o);
          if (!o) return;
          r.slot.show(o.it, o.n);
          r.pan.control(`lbl_resultitem_name_${i}`).setText(db.name(o.it)+(o.range?` (${o.range})`:''));
          r.pan.control(`lbl_resultitem_tagchance_${i}`).setText(o.range?'':str(1001, 283));
          r.pan.control(`lbl_resultitem_chance_${i}`).setText(o.range?'':`${o.ratio.toFixed(1)}%`);
        });
        W.control('btn_request').setEnabled(!!(def && row && dis.hammer.inst && !K.busy));
      } else if (S.tab === 1) {
        const src = amp.res.def, row = src ? ampRow(src.index) : null;
        const have = src ? K.have(src.index) : 0;
        const max = row ? Math.floor(have / Number(row.RESOURCE_COUNT)) : 0;
        S.count = Math.max(row ? 1 : 0, Math.min(S.count, max));
        amp.tgt.show(row ? Number(row.TARGET_INDEX) : null);
        P(1).control('lbl_resource_Info').setText(src ? src.name : '');
        P(1).control('lbl_resource_countInfo').setText(src ? (str(1001, 290) || 'Owned: %d').replace('%d', fmt(have)) : '');
        P(1).control('lbl_target_Info').setText(row ? db.name(row.TARGET_INDEX) : '');
        P(1).control('lbl_target_countInfo').setText(row ? (str(1001, 290) || 'Owned: %d').replace('%d', fmt(K.have(row.TARGET_INDEX))) : '');
        P(1).control('lbl_source_ratio').setText(row ? String(row.RESOURCE_COUNT) : '');
        P(1).control('lbl_result_ratio').setText(row ? '1' : '');
        P(1).control('lbl_make_count').setText((str(1001, 289) || 'Up to %d Times').replace('%d', fmt(max)));
        W.control('edit_text').setValue?.(String(S.count));
        P(1).control('lbl_amplify_cost').setText(row ? fmt(Number(row.COST_DIL) * S.count) : '');
        P(1).control('lbl_amplify_useitemname').setText(src ? src.name : '');
        P(1).control('lbl_amplify_useitemcount').setText(row ? fmt(Number(row.RESOURCE_COUNT) * S.count) : '');
        P(1).control('lbl_amplify_gainitemname').setText(row ? db.name(row.TARGET_INDEX) : '');
        P(1).control('lbl_amplify_gainitemcount').setText(row ? fmt(S.count) : '');
        P(1).control('lbl_amplify_remainitemname').setText(src ? src.name : '');
        P(1).control('lbl_amplify_remainitemcount').setText(row ? fmt(have - Number(row.RESOURCE_COUNT) * S.count) : '');
        W.control('btn_request').setEnabled(!!(row && S.count > 0 && !K.busy));
      } else {
        const inst = br.target.inst, def = br.target.def, sd = br.stone.def;
        const rate = def && sd ? brandRate(sd, def) : 0;
        P(2).control('lbl_incuse_cost').setText(def && sd ? `${rate}%` : '');
        const bl = inst?.brand || [];
        for (let i = 0; i < 4; i++) {
          const cb = W.control(`check_lock_${i}`);
          const o = bl[i];
          cb.setText?.(o ? optText(db, o[0], o[1]) : '');
          cb.setEnabled?.(!!o);
          if (!o && cb.isChecked?.()) cb.setChecked(false);
        }
        W.control('btn_request').setEnabled(!!(def && sd && !K.busy));
      }
    }
    function offer(inst) {
      const def = db.def(inst.itemIndex);
      if (S.tab === 0) return (def?.slot ? dis.target : isKind(def, HAMMER_KIND) ? dis.hammer : dis.target).put(inst) || true;
      if (S.tab === 1) return amp.res.put(inst) || true;
      if (def?.slot) return br.target.put(inst) || true;
      return br.stone.put(inst) || true;
    }
    async function request() {
      if(g.save.authority==='server'&&S.tab===2){g.network.unavailable('Use the renewed Branding window');return;}
      if (K.busy) return;
      if (!K.validate()) { refresh(); return; }
      if (S.tab === 0) {
        const inst = dis.target.inst, def = dis.target.def, row = def && disRow(def);
        if (!inst || !row) { sys.msg(1001, 134); return; }
        if (!dis.hammer.inst) { sys.msg(1001, 133); return; }
        if(row.wing && sys.dil < row.wing.dil){sys.msg(1001,180);return;}
        if(g.save.authority==='server'){
          const material=dis.hammer.inst.uid;
          const result=await K.review(str(1001,148),str(1001,284),network=>network.action('craft',{operation:'dismantle',uid:inst.uid,material}),()=>!row.wing||sys.dil>=row.wing.dil);
          if(result){for(const s of K.slots)s.clear(false);refresh();}return;
        }
        if (!(await K.confirm(str(1001, 148), str(1001, 284)))) return;
        await K.progress(1.5, 98);
        if(!sys.bag.list.includes(inst)||!dis.hammer.inst||!sys.bag.list.includes(dis.hammer.inst)){sys.msg(1001,118);return;}
        let acc = 0, out = null;
        if(row.wing){const count=rollWingDismantleCount(row.wing);if(count)out=[row.wing.item,count];}
        else{const x = Math.random() * Math.max(1, Number(row['Total Ratio']));for (let k = 1; k <= 5; k++) { acc += Number(row[`ItemRatio_${k}`]) || 0; if (x < acc && Number(row[`ItemIndex_${k}`])) { out = [Number(row[`ItemIndex_${k}`]), Number(row[`ItemCount_${k}`]) || 1]; break; } }}
        if (out && !sys.canAdd(out[0], out[1])) { sys.msg(1001, 137); return; }
        if(row.wing && !sys.spendDil(row.wing.dil)){sys.msg(1001,180);return;}
        K.consume(dis.hammer.inst, 1);
        dis.target.clear(false);
        sys.removeInst(inst);
        if (out) sys.add(out[0], out[1], { source: 'dismantle' });
        sysSound(sys, 101); sys.msg(1001, 132);
        g.events.emit('item:dismantle', { item: inst, result: out });
        if(row.wing)g.events.emit('life:dekapass:event',{main:10,sub:26,value:inst.itemIndex,count:1});
      } else if (S.tab === 1) {
        const src = amp.res.def, row = src && ampRow(src.index);
        if (!row) { sys.msg(1001, 136); return; }
        const n = S.count, need = Number(row.RESOURCE_COUNT) * n, cost = Number(row.COST_DIL) * n;
        if (K.have(src.index) < need) { sys.msg(1001, 179); return; }
        if (sys.dil < cost) { sys.msg(1001, 180); return; }
        if (!sys.canAdd(Number(row.TARGET_INDEX), n)) { sys.msg(1001, 181); return; }
        if(g.save.authority==='server'){const result=await g.network.action('craft',{operation:'amplify',material:amp.res.inst.uid,count:n});if(result){for(const s of K.slots)s.clear(false);refresh();}return;}
        if (!sys.spendDil(cost)) { sys.msg(1001, 180); return; }
        await K.progress(1.2, 98);
        amp.res.clear(false);
        const { spendItems } = await import('./craft.js');
        spendItems(sys, src.index, need);
        sys.add(Number(row.TARGET_INDEX), n, { source: 'amplify' });
        sysSound(sys, 101); sys.msg(1001, 138);
        const left = sys.bag.list.find(i => i.itemIndex === src.index);
        if (left) amp.res.put(left, { silent: true });
      } else {
        const inst = br.target.inst, def = br.target.def, sd = br.stone.def;
        if (!inst) { sys.msg(1001, 134); return; }
        if (!sd) { sys.msg(1001, 133); return; }
        const L = locks();
        const lockItems = sys.bag.list.filter(i => isKind(db.def(i.itemIndex), LOCK_KIND));
        const lockHave = lockItems.reduce((a, i) => a + (i.count || 1), 0);
        if (L.length && lockHave < L.length) { sys.msg(1001, 152); return; }
        const lvDiff = (Number(sd.use?.brandLevel) || 0) - (Number(def.reqLv) || 0);
        const warn = lvDiff < 0 ? str(1001, 146) : str(81, 40);
        if (!(await K.confirm(warn, str(1001, 286)))) return;
        await K.progress(1.5, 98);
        const rate = brandRate(sd, def);
        K.consume(br.stone.inst, 1);
        if (L.length) { let left = L.length; for (const it of lockItems) { if (left <= 0) break; const k = Math.min(left, it.count || 1); sys.bag.take(it, k); left -= k; } }
        if (Math.random() * 100 < rate) {
          const lv = Math.max(1, Math.min(250, Number(sd.use?.brandLevel) || 1));
          const row = (db.T?.incuseOptionLevels?.rows || []).find(r => Number(r.Level) === lv);
          const cands = [];
          if (row) for (let k = 1; k <= Number(row.count || 0); k++) { const no = Number(row[`Value${k}`]); if (no) cands.push({ no, min: Number(row[`DataMin${k}`]), max: Number(row[`DataMax${k}`]) }); }
          const byNo = new Map((db.T?.incuseOption?.rows || []).map(r => [Number(r.No), r]));
          const old = inst.brand || [];
          const out = [];
          const used = new Set();
          for (let i = 0; i < 4; i++) {
            if (L.includes(i) && old[i]) { out.push(old[i]); used.add(old[i][0]); continue; }
            let pick = null;
            for (let tries = 0; tries < 20 && cands.length; tries++) {
              const c = cands[Math.floor(Math.random() * cands.length)];
              const opt = byNo.get(c.no);
              const code = opt && optCode(db, opt.Option);
              if (code == null || used.has(code)) continue;
              pick = [code, Math.min(Number(opt.MaxCapacityLimit) || Infinity, rint(c.min, c.max))];
              break;
            }
            if (pick) { out.push(pick); used.add(pick[0]); }
          }
          inst.brand = out;
          sysSound(sys, 101); sys.msg(1001, 140);
        } else { sysSound(sys, 100); sys.msg(1001, 141); }
        g.events.emit('item:brand', { item: inst });
        sys.changed('brand', { item: inst });
      }
      for (const s of K.slots) s.validate();
      refresh();
    }
    g.uiwin.registerWindow('incuse', {
      script: 'game2/itemupgrade/ui_itemincusewnd_renew.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'incuse');
        const onChange = () => refresh();
        // dismantle page
        dis.target = K.slot(P(0).control('target_item'), { accept: (i, d) => (d?.slot==='wing'?!!wingDismantleRule(db,d.index):brandable(d)) ? true : [1001, 135], count: false, onChange });
        dis.hammer = K.slot(P(0).control('resource_item'), { accept: (i, d) => (isKind(d, HAMMER_KIND) ? true : [1001, 136]), onChange });
        const tpl = P(0).control('pan_Resultitem');
        for (let i = 0; i < 5; i++) {
          const pan = tpl.cloneAs(`_${i}`, { y: 75 + i * 42, visible: false });
          S.results.push({ pan, slot: K.slot(pan.control(`result_item_${i}`), { view: true }) });
        }
        // amplify page
        amp.res = K.slot(P(1).control('resource_item'), { accept: (i, d) => (ampRow(d.index) ? true : [1001, 136]), onChange });
        amp.tgt = K.slot(P(1).control('target_item'), { view: true });
        const setCount = (n) => { S.count = Math.max(1, Math.floor(Number(n) || 1)); refresh(); };
        P(1).control('btn_minus').onClick(() => setCount(S.count - 1));
        P(1).control('btn_plus').onClick(() => setCount(S.count + 1));
        P(1).control('btn_max').onClick(() => setCount(1e9));
        W.control('edit_text').on?.('change', (v) => { S.count = Math.max(1, Math.floor(Number(v) || 1)); });
        W.control('edit_text').on?.('enter', () => setCount(W.control('edit_text').getValue?.()));
        rich(P(1).control('lbl_warning'), str(1001, 182));
        // brand page
        br.target = K.slot(P(2).control('target_item'), { accept: (i, d) => (brandable(d) ? true : [1001, 135]), count: false, onChange: () => { for (let k = 0; k < 4; k++) W.control(`check_lock_${k}`).setChecked(false); refresh(); } });
        br.stone = K.slot(P(2).control('resource_item'), { accept: (i, d) => (isKind(d, [1, 19]) ? (br.target.inst ? true : [1001, 134]) : [1001, 136]), onChange });
        for (let k = 0; k < 4; k++) W.control(`check_lock_${k}`).on?.('change', () => { if (!br.target.inst?.brand?.[k]) { W.control(`check_lock_${k}`).setChecked(false); sys.msg(1001, 149); } refresh(); });
        // the Brand tab is the renewed branding window (ui_itemincusewnd_renew2.txt, 'brand') at the same place
        for (let i = 0; i < 3; i++) win.control(`btn_tab_${i}`).onClick(() => {
          if (i === 2) { const at = { x: win.box.x, y: win.box.y }; const npc = K.npc; win.close('tab'); g.uiwin.open('brand', { npc, at }); return; }
          if (S.tab !== i) { K.releaseAll(); S.tab = i; refresh(); }
        });
        win.control('btn_request').onClick(request);
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) {
        await db.tables();
        if (arg?.tab === 2) { win.close('tab'); g.uiwin.open('brand', arg); return; }
        S.tab = arg?.tab ?? 0;
        if (arg?.at) win.setPosition(arg.at.x, arg.at.y);
        K.opened(win, arg, offer);
        refresh();
      },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
    sys.windowsAlias = { ...(sys.windowsAlias || {}), disassemble: ['incuse', { tab: 0 }], amplify: ['incuse', { tab: 1 }] };
  }

  // =============================================================================================== branding (renewed window)
  // game2/itemupgrade/ui_itemincusewnd_renew2.txt "Item Branding": item_target + item_resource (Soul Stone), current
  // branding options with locks (check_lock_option_1..4, one Brand Option Lock 0/42 per locked line per attempt), auto
  // branding (edit_repeat attempts, edit_endpoint = how many desired options must be met), the desired options summary
  // (6) and the full list of options the stone level can engrave (itemincuseoption.csv, select + desired value).
  {
    let K = null, W = null;
    const S = { top: 0, desired: new Map(), locks: new Set(), repeat: 1, endpoint: 1, auto: false, stop: false, cands: [] };
    const ROWS = 17;
    const tInst = () => S.item.inst, tDef = () => S.item.def, sDef = () => S.stone.def;
    const rate = () => {
      const d = Math.max(-65, Math.min(100, (Number(sDef()?.use?.brandLevel) || 0) - (Number(tDef()?.reqLv) || 0)));
      const r = (db.T?.incuseDice?.rows || []).find(x => Number(x.ResultValue) === d);
      return r ? Number(r.SuccessRate) / 10 : 0;
    };
    const byNo = () => (db._incNo ||= new Map((db.T?.incuseOption?.rows || []).map(r => [Number(r.No), r])));
    const candidates = () => {
      const lv = Math.max(1, Math.min(250, Number(sDef()?.use?.brandLevel) || 0));
      const row = sDef() ? (db.T?.incuseOptionLevels?.rows || []).find(r => Number(r.Level) === lv) : null;
      const out = [];
      if (row) for (let k = 1; k <= Number(row.count || 0); k++) {
        const no = Number(row[`Value${k}`]); const o = byNo().get(no);
        const code = o && optCode(db, o.Option);
        if (code != null) out.push({ no, code, name: o.Desc || db.optionType(code)?.label || o.Option, min: Number(row[`DataMin${k}`]), max: Math.min(Number(row[`DataMax${k}`]), Number(o.MaxCapacityLimit) || Infinity) });
      }
      return out;
    };
    const lockItems = () => sys.bag.list.filter(i => isKind(db.def(i.itemIndex), LOCK_KIND));
    const lockHave = () => lockItems().reduce((a, i) => a + (i.count || 1), 0);
    const met = (inst) => {
      if (!S.desired.size) return false;
      let n = 0;
      for (const [code, want] of S.desired) if ((inst.brand || []).some(([c, v]) => c === code && v >= want)) n++;
      return n >= Math.max(1, Math.min(S.endpoint, S.desired.size));
    };
    function refresh() {
      if (!W) return;
      const inst = tInst(), def = tDef(), sd = sDef();
      W.control('lbl_target').setText(def ? def.name : '');
      W.control('lbl_resource').setText(sd ? `${sd.name} (${fmt(K.have(sd.index))})` : '');
      W.control('lbl_probability').setText(def && sd ? (str(1001, 296) || 'Success Chance %d%%').replace('%d', rate()).replace('%%', '%') : '');
      W.control('lbl_lockcount').setText((str(1001, 298) || 'Branding Option Lock: Owned %d / %d per attempt').replace('%d', fmt(lockHave())).replace('%d', S.locks.size));
      const bl = inst?.brand || [];
      for (let k = 1; k <= 4; k++) {
        const o = bl[k - 1];
        W.control(`lbl_myoptionname_${k}`).setText(o ? (db.optionType(o[0])?.label || `Option ${o[0]}`) : '');
        W.control(`lbl_myoption_${k}`).setText(o ? fmt(o[1]) : '');
        W.control(`check_lock_option_${k}`).setChecked(S.locks.has(k - 1));
        W.control(`btn_lock_option_${k}`).setChecked?.(S.locks.has(k - 1));
      }
      W.find('edit_repeat')?.setValue?.(String(S.repeat));
      W.find('edit_endpoint')?.setValue?.(String(S.endpoint));
      W.control('lbl_dil').setText('0');
      // desired summary
      const des = [...S.desired];
      W.control('lbl_selectoptioninfo').setText((str(1001, 306) || 'Selected Desired Options %d / 6').replace('%d', des.length));
      for (let k = 1; k <= 6; k++) {
        const d = des[k - 1];
        W.control(`lbl_desieroption_${k}`).setText(d ? (db.optionType(d[0])?.label || `Option ${d[0]}`) : (k === 1 ? str(1001, 311) : ''));
        W.control(`lbl_desieroptionvalue_${k}`).setText(d ? (str(1001, 307) || '%d or Higher').replace('%d', fmt(d[1])) : (k === 1 ? str(1001, 311) : ''));
      }
      // full list
      S.cands = candidates();
      const sc = W.control('list_scroll');
      sc.setRange?.(Math.max(0, S.cands.length - ROWS), ROWS); sc.setValue?.(S.top);
      for (let r = 1; r <= ROWS; r++) {
        const c = S.cands[S.top + r - 1];
        W.control(`lbl_optionname_${r}`).setText(c ? c.name : '');
        W.control(`lbl_optionrange_${r}`).setText(c ? `${fmt(c.min)}~${fmt(c.max)}` : '');
        const cb = W.control(`check_desier_${r}`);
        cb.setVisible(!!c);
        cb.setChecked(!!c && S.desired.has(c.code));
        const ed = W.control(`edit_optioninput_${r}`);
        ed.setVisible(!!c && S.desired.has(c.code));
        if (c && S.desired.has(c.code)) ed.setValue?.(String(S.desired.get(c.code)));
      }
      W.control('btn_incuse').setVisible(!S.auto);
      W.control('btn_stoprepeat').setVisible(S.auto);
      W.control('btn_incuse').setEnabled(!!(def && sd && !K.busy));
    }
    async function brandOnce() {
      const inst = tInst(), def = tDef(), sd = sDef();
      if (!inst) { sys.msg(1001, 134); return 'stop'; }
      if (!sd || !S.stone.inst) { sys.msg(1001, 133); return 'stop'; }
      if (S.locks.size && lockHave() < S.locks.size) { sys.msg(1001, 152); return 'stop'; }
      if(g.save.authority==='server'){
        const result=await g.network.action('brand',{uid:inst.uid,stone:S.stone.inst.uid,locks:[...S.locks]});if(!result)return 'stop';
        S.item.inst=sys.bag.byUid(inst.uid);S.item.draw();if(!S.stone.validate()||!S.stone.inst){const next=K.findInBag([sd.index]);if(next)S.stone.put(next,{silent:true});}refresh();return met(S.item.inst)?'done':'go';
      }
      await K.progress(S.auto ? 0.5 : 1.5, 98);
      const p = rate();
      K.consume(S.stone.inst, 1);
      if (S.locks.size) { let left = S.locks.size; for (const it of lockItems()) { if (left <= 0) break; const k = Math.min(left, it.count || 1); sys.bag.take(it, k); left -= k; } }
      let ok = false;
      if (Math.random() * 100 < p) {
        const old = inst.brand || [];
        const cands = candidates();
        const out = [], used = new Set();
        for (let i = 0; i < 4; i++) {
          if (S.locks.has(i) && old[i]) { out.push(old[i]); used.add(old[i][0]); continue; }
          const pool = cands.filter(c => !used.has(c.code));
          if (!pool.length) break;
          const c = pool[Math.floor(Math.random() * pool.length)];
          out.push([c.code, rint(c.min, c.max)]); used.add(c.code);
        }
        inst.brand = out;
        ok = true;
        sysSound(sys, 101); sys.msg(1001, 140);
      } else { sysSound(sys, 100); sys.msg(1001, 141); }
      g.events.emit('item:brand', { item: inst, ok });
      sys.changed('brand', { item: inst });
      // the stone stack may be used up: register the next stack of the same stone
      if (!S.stone.validate() || !S.stone.inst) { const nx = K.findInBag([sd.index]); if (nx) S.stone.put(nx, { silent: true }); }
      refresh();
      return ok && met(inst) ? 'done' : 'go';
    }
    async function start() {
      if (K.busy || S.auto) return;
      if (!K.validate()) { refresh(); return; }
      if (!tInst()) { sys.msg(1001, 134); return; }
      if (!sDef()) { sys.msg(1001, 133); return; }
      const warn = (Number(sDef().use?.brandLevel) || 0) < (Number(tDef().reqLv) || 0) ? str(1001, 146) : str(81, 40);
      if (!(await K.confirm(warn, str(1001, 286)))) return;
      const n = Math.max(1, S.repeat);
      S.auto = n > 1; S.stop = false; refresh();
      for (let i = 0; i < n && !S.stop; i++) {
        const r = await brandOnce();
        if (r === 'stop' || r === 'done') break;
      }
      S.auto = false; refresh();
    }
    g.uiwin.registerWindow('brand', {
      script: 'game2/itemupgrade/ui_itemincusewnd_renew2.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'brand');
        S.item = K.slot('item_target', { accept: (i, d) => (brandable(d) ? true : [1001, 135]), count: false, onChange: () => { S.locks.clear(); refresh(); } });
        S.stone = K.slot('item_resource', { accept: (i, d) => (isKind(d, [1, 19]) ? true : [1001, 136]), onChange: () => { S.top = 0; refresh(); } });
        for (let k = 1; k <= 4; k++) {
          const tog = () => {
            if (!tInst()?.brand?.[k - 1]) { sys.msg(1001, 149); W.control(`check_lock_option_${k}`).setChecked(false); return; }
            if (S.locks.has(k - 1)) S.locks.delete(k - 1); else S.locks.add(k - 1);
            refresh();
          };
          win.control(`check_lock_option_${k}`).on('change', tog);
          win.control(`btn_lock_option_${k}`).onClick(tog);
        }
        const num = (v, lo, hi) => Math.max(lo, Math.min(hi, Math.floor(Number(v) || lo)));
        const maxRepeat = () => Math.max(1, Math.min(K.have(sDef()?.index || 0) || 1, 999));
        win.control('btn_minus_repeat').onClick(() => { S.repeat = num(S.repeat - 1, 1, 999); refresh(); });
        win.control('btn_plus_repeat').onClick(() => { S.repeat = num(S.repeat + 1, 1, 999); refresh(); });
        win.control('btn_max_repeat').onClick(() => { S.repeat = maxRepeat(); refresh(); });
        win.control('btn_minus_end').onClick(() => { S.endpoint = num(S.endpoint - 1, 1, 6); refresh(); });
        win.control('btn_plus_end').onClick(() => { S.endpoint = num(S.endpoint + 1, 1, 6); refresh(); });
        win.find('edit_repeat')?.on?.('change', (v) => { S.repeat = num(v, 1, 999); });
        win.find('edit_endpoint')?.on?.('change', (v) => { S.endpoint = num(v, 1, 6); });
        for (let r = 1; r <= ROWS; r++) {
          win.control(`check_desier_${r}`).on('change', (on) => {
            const c = S.cands[S.top + r - 1];
            if (!c) return;
            if (on && S.desired.size >= 6 && !S.desired.has(c.code)) { win.control(`check_desier_${r}`).setChecked(false); return; }
            if (on) S.desired.set(c.code, c.min); else S.desired.delete(c.code);
            refresh();
          });
          win.control(`edit_optioninput_${r}`).on?.('change', (v) => { const c = S.cands[S.top + r - 1]; if (c && S.desired.has(c.code)) S.desired.set(c.code, num(v, c.min, c.max)); });
          win.control(`edit_optioninput_${r}`).on?.('enter', () => refresh());
        }
        win.control('list_scroll').on?.('change', (v) => { S.top = Math.round(Number(v) || 0); refresh(); });
        win.control('btn_reset_desier').onClick(() => { S.desired.clear(); refresh(); });
        win.control('btn_reset').onClick(() => { S.repeat = 1; S.endpoint = 1; S.locks.clear(); S.desired.clear(); refresh(); });
        win.control('btn_incuse').onClick(start);
        win.control('btn_stoprepeat').onClick(() => { S.stop = true; });
        for (let i = 0; i < 2; i++) win.control(`btn_tab_${i}`).onClick(() => { const npc = K.npc; win.close('tab'); g.uiwin.open('incuse', { npc, tab: i }); });
        win.control('btn_tab_2').setChecked(true);
        rich(win.control('lbl_warning_1'), str(356, 3));
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) {
        await db.tables();
        K.opened(win, arg, (inst) => { const d = db.def(inst.itemIndex); return ((d?.slot ? S.item : S.stone).put(inst)) || true; });
        refresh();
      },
      onClose() { S.stop = true; K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // =============================================================================================== crests
  {
    let K = null, W = null;
    const S = { tab: 0, pick: [] };
    const GROUP_OF_SLOT = [23, 23, 24, 24, 25, 26];
    const tInst = () => S.item.inst, tDef = () => S.item.def;
    const crestOpt = (def) => {
      if(g.save.authority==='server') {
        const row=crestRule(db,db.T,def),code=row&&optCode(db,row.type);
        return code!=null&&CREST_SUPPORTED_EFFECTS.has(row.type)&&Number.isSafeInteger(row.min)?[code,row.min]:null;
      }
      const rows = db.T?.crestOption?.rows || [];
      const r = rows.find(x => Number(x.index) === Number(def.index) - 4500000);
      let code = r ? optCode(db, r.type) : null;
      let v = r ? rint(Number(r.min), Number(r.max)) : null;
      if (code == null) {
        // older crests: the value in the name ("HP 5", "Max HP 10000")
        const m = /(\d+)\s*%?\s*$/.exec(def.name || '');
        const lbl = String(def.name || '').replace(/\s*[\d.]+\s*%?\s*$/, '').trim().toLowerCase();
        for (const [c, o] of Object.entries(db.options?.optionTypes || {})) if (String(o.label || '').toLowerCase().includes(lbl) && lbl) { code = Number(c); break; }
        v = m ? Number(m[1]) : null;
      }
      return code != null && v ? [code, v] : null;
    };
    const slotsOf = (inst) => (inst?.crest?.slots ? inst.crest.slots : [null, null, null, null, null, null]);
    // Same shared rule as the host (crest-rules.js): DIL for the picked crests, 0 with a Hot Plier, null = unknown price (311:32).
    const extractCost = (inst) => crestExtractDil(S.pick.map(i => db.def(slotsOf(inst)[i]?.item)), { hotPlier: !!S.cash.inst && isKind(S.cash.def, [1, 28]) });
    const syncOptions = (inst) => {
      const c = inst.crest;
      c.options = [...c.slots.filter(Boolean).map(s => s.opt), ...(c.bonus ? [c.bonus] : [])];
      if (!c.options.length && !c.slots.some(Boolean)) delete inst.crest;
    };
    function refresh() {
      if (!W) return;
      const inst = tInst();
      for (let i = 0; i < 2; i++) W.control(`btn_tab_${i}`).setChecked(i === S.tab);
      const slots = slotsOf(inst);
      S.src.forEach((s, i) => {
        if (S.tab === 0) {
          if (!s.inst) s.show(slots[i]?.item ?? null);
          W.control(`panel_lock${i + 1}`).setVisible(!!slots[i] && !s.inst);
          W.control(`panel_select${i + 1}`).setVisible(!!s.inst);
        } else {
          s.show(slots[i]?.item ?? null);
          W.control(`panel_lock${i + 1}`).setVisible(false);
          W.control(`panel_select${i + 1}`).setVisible(S.pick.includes(i));
        }
      });
      const lines = inst?.crest?.options || [];
      for (let i = 0; i < 7; i++) W.control(`lbl_result${i + 1}`).setText(lines[i] ? optText(db, lines[i][0], lines[i][1]) : '');
      let cost = 0;
      let priceAvailable=true;
      if (S.tab === 0) { for (const s of S.src) if (s.inst) {const price=crestInsertPrice(db,db.T,s.def);if(price.error)priceAvailable=false;else cost+=price.dil;} }
      else cost = extractCost(inst) ?? 0;   // removal price per crest grade (guide 16); Hot Plier: none
      W.control('lbl_money').setText(inst ? fmt(cost) : '');
      W.control('lbl_percent').setText(inst ? (S.tab === 0 ? '100%' : S.cash.inst ? '100%' : `${Math.round(ENGINE_CHOSEN_UNPROTECTED_CREST_KEEP_RATE * 100)}%`) : '');
      W.control('lbl_hint').setText(!inst ? str(311, 5) : S.tab === 0 ? str(311, 23) : str(311, 29));
      W.control('btn_munzang').setText(S.tab === 0 ? str(311, 7) : str(311, 47));
      W.control('btn_munzang').setEnabled(!!(inst && !K.busy && priceAvailable && (S.tab === 0 ? S.src.some(s => s.inst) : S.pick.length)));
    }
    const acceptCrest = (i) => (inst, def) => {
      if (S.tab !== 0) return [311, 43];
      if (!tInst()) return [311, 9];
      if (Number(def.type) !== 1 || ![23, 24, 25, 26].includes(Number(def.code))) return [311, 34];
      if (Number(def.code) !== GROUP_OF_SLOT[i]) return [311, 14];
      if (slotsOf(tInst())[i]) return [311, 17];
      if (!crestOpt(def)) return [311, 22];
      return true;
    };
    function offer(inst) {
      const def = db.def(inst.itemIndex);
      if (def?.slot) return S.item.put(inst) || true;
      if (!tInst()) { sys.msg(311, 9); return true; }
      if (S.tab === 1) { if (isKind(def, [1, 27]) || isKind(def, [1, 28])) return S.cash.put(inst) || true; sys.msg(311, 38); return true; }
      const slots = slotsOf(tInst());
      for (let i = 0; i < 6; i++) if (GROUP_OF_SLOT[i] === Number(def?.code) && !slots[i] && !S.src[i].inst) return S.src[i].put(inst) || true;
      sys.msg(311, Number(def?.type) === 1 && [23, 24, 25, 26].includes(Number(def?.code)) ? 17 : 34);
      return true;
    }
    async function apply() {
      const inst = tInst();
      if (!inst || K.busy) return;
      if (!K.validate()) { refresh(); return; }
      if(g.save.authority==='server') {
        if(S.tab===1&&!S.cash.inst&&!(await K.confirm(str(311,48),str(311,45))))return;
        const intent=S.tab===0?{operation:'insert',uid:inst.uid,crests:S.src.flatMap((s,slot)=>s.inst?[{slot,uid:s.inst.uid}]:[])}
          :{operation:'extract',uid:inst.uid,slots:[...S.pick],...(S.cash.inst?{plier:S.cash.inst.uid}:{})};
        const result=await submitItemService(g,K,'crest',intent,refresh);
        if(result){for(const s of K.slots)s.clear(false);S.pick=[];sysSound(sys,101);sys.msg(311,intent.operation==='insert'?16:result.itemServiceResult?.kept===false?27:28);refresh();}
        return;
      }
      if (S.tab === 0) {
        const adds = S.src.map((s, i) => (s.inst ? { i, s } : null)).filter(Boolean);
        if (!adds.length) return;
        let cost = 0;
        for (const a of adds) {const price=crestInsertPrice(db,db.T,a.s.def);if(price.error){sys.msg(311,32);return;}cost+=price.dil;}
        if (sys.dil < cost) { sys.msg(311, 12); return; }
        if (!sys.spendDil(cost)) { sys.msg(311, 12); return; }
        await K.progress(1.5, 98);
        inst.crest = inst.crest?.slots ? inst.crest : { slots: [null, null, null, null, null, null], bonus: null, options: [] };
        for (const a of adds) {
          const opt = crestOpt(a.s.def);
          inst.crest.slots[a.i] = { item: a.s.def.index, opt };
          K.consume(a.s.inst, 1);
          a.s.clear(false);
        }
        if (inst.crest.slots.every(Boolean) && !inst.crest.bonus) {
          const rows = (db.T?.crestIncuse?.rows || []).filter(r => Number.isFinite(Number(r.level)) && !/[^\x00-\x7f]/.test(r.descEn || ''));
          const r = rows[Math.floor(Math.random() * rows.length)];
          const code = r && optCode(db, r.type);
          if (code != null) inst.crest.bonus = [code, rint(Number(r.min), Number(r.max))];
        }
        syncOptions(inst);
        sysSound(sys, 101); sys.msg(311, 16);
      } else {
        const picks = [...S.pick];
        if (!picks.length) { sys.msg(311, 43); return; }
        const hot = isKind(S.cash.def, [1, 28]);
        if (picks.length > 1 && !hot) { sys.msg(311, picks.length > 1 && S.cash.inst ? 44 : 39); return; }
        const price = extractCost(inst);
        if (price == null) { sys.msg(311, 32); return; }
        if (sys.dil < price) { sys.msg(311, 33); return; }
        if (!S.cash.inst && !(await K.confirm(str(311, 48), str(311, 45)))) return;
        const need = picks.map(i => slotsOf(inst)[i]?.item).filter(Boolean);
        if (price && !sys.spendDil(price)) { sys.msg(311, 33); return; }
        await K.progress(1.5, 98);
        const keep = S.cash.inst ? true : Math.random() < ENGINE_CHOSEN_UNPROTECTED_CREST_KEEP_RATE;
        if (S.cash.inst) K.consume(S.cash.inst, 1);
        for (const i of picks) inst.crest.slots[i] = null;
        inst.crest.bonus = null;
        syncOptions(inst);
        S.pick = [];
        if (keep) { for (const it of need) sys.add(it, 1, { source: 'crest', dropLeft: true }); sys.msg(311, 28); } else sys.msg(311, 27);
        sysSound(sys, keep ? 101 : 100);
      }
      g.events.emit('item:crest', { item: inst });
      for (const s of K.slots) s.validate();
      sys.changed('crest', { item: inst });
      refresh();
    }
    g.uiwin.registerWindow('munzang', {
      script: 'game2/itemupgrade/ui_munzangwnd.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'munzang');
        const onChange = () => refresh();
        S.item = K.slot('item_target', { accept: (i, d) => (d?.slot === 'costume' ? true : [311, 10]), count: false, onChange: () => { S.pick = []; for (const s of S.src) if (s.inst) s.clear(false); refresh(); } });
        S.src = [0, 1, 2, 3, 4, 5].map(i => K.slot(`itemsource_${i + 1}`, {
          accept: acceptCrest(i), count: false, onChange,
          click: () => {
            if (S.tab !== 1 || !slotsOf(tInst())[i]) return;
            S.pick = S.pick.includes(i) ? S.pick.filter(x => x !== i) : [...S.pick, i];
            refresh();
          },
        }));
        S.cash = K.slot('item_cash', { accept: (i, d) => (S.tab !== 1 ? [311, 38] : isKind(d, [1, 27]) || isKind(d, [1, 28]) ? true : [311, 38]), onChange });
        for (let i = 0; i < 2; i++) win.control(`btn_tab_${i}`).onClick(() => { if (S.tab !== i) { for (const s of [...S.src, S.cash]) if (s.inst) s.clear(false); S.tab = i; S.pick = []; refresh(); } });
        win.control('btn_munzang').onClick(apply);
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) { await db.tables(); db.crestSources||=await loadCrestSources(source=>fetchCSV(source).catch(()=>[])); S.tab = 0; S.pick = []; K.opened(win, arg, offer); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }
  void clean;
}
