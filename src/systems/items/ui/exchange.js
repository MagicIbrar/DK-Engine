// Item conversion windows of the items system:
//  'accupgrade'  NPC Aria (ACCESSORYUPGRADE): game2/itemupgrade/ui_acc_upgradewnd_new.txt "Item upgrade". Tree of
//     accessoryupgrade.csv (mainCate 351:1-6 -> subCate 351:<sub> -> source items), the source -> result pair, up to 6
//     material lines (bound or tradeable variant, count), cost, success % (successRate / 100), 352:<sub> where to get
//     it, 353:<eventText>; failure: penalty (NOT_FAIL keeps the source) or failResultItem (353:6).
//  'helmetrank'  NPC Ace (HELMET_RANK_CHANGE): game2/itemupgrade/ui_helmetupgradewnd.txt "Convert Item Grade" (Epic ->
//     Theos, helmetrankchange.csv: BeforItem -> AfterItem, NeedDil, Upgrade Rate, Item1..10 x count). btn_open shows the
//     list of convertible items (multi_tree).
//  'itemchange'  NPC Sealer Bosea / Kami (ITEM_CHANGE): game2/itemupgrade/ui_changeitemwnd.txt "Seal Item": the item of
//     itemchange.csv SourceItemIndex becomes DestItemIndex for SpendCount Sealing Powder (kind 1/18).
//  'stonegamble' NPC Carmen (ITEM_SOCKETSTONE_CRUSHER / _PRODUCE): game2/itemupgrade/ui_stonegamble.txt "Socket Stone
//     Machine" (share/support/socketstone/socketstone_produce.csv: machines with 20 results and cumulative Dice per
//     1,000,000, Need_Item_Type x Need_Item_Count + Need_DIL per spin; Socket Lock (0/61) / Premium Socket Stone Lock
//     (0/62) exclude up to Normal/Primium_Lock_Viable slots from the roll, one lock item per locked slot per spin) and
//     the dismantler page (socketstone_crusher.csv: Need_Item -> Count_Min..Count_Max Output_Item, Need_Dil).
//  'talisman'    NPC Viola (TALISMAN_EFFECT_TRANSFORM): game2/itemupgrade/ui_talismaneffecttransformwnd.txt "Change
//     Talisman Appearance" (share/support/tarlismaneffecttransform/talismaneffecttransform.csv: effect, materials, dil,
//     reset dil): the talisman instance keeps `appearance` (effect index), shown by the effects system.
import { Crafting, sysSound, clean, morph, spendItems, rich } from './craft.js';
import { fmt } from './common.js';
import { fetchCSV } from '../../../engine/assets.js';
import { submitItemService } from '../../network/item-services.js';

const isKind = (def, t, c) => Number(def?.type) === t && Number(def?.code) === c;

/** Copy an instance's per-item data onto a new item index (conversions keep sockets, options, brand, crest). */
function convert(sys, inst, newIndex) { return morph(sys, inst, newIndex); }

// These windows consume materials automatically rather than registering them
// in slots. Keep the exact reviewed target and resource stacks across the modal.
function conversionReview(sys, target, indices, row) {
  const state = item => item ? JSON.stringify(Object.fromEntries(Object.entries(item).filter(([key]) => !['page', 'x', 'y'].includes(key)).sort(([a], [b]) => a.localeCompare(b)))) : null;
  const now = () => typeof sys.game.now === 'function' ? sys.game.now() : Date.now();
  const available = item => (item.count ?? 1) > 0 && !(item.expiresAt && item.expiresAt <= now());
  const materials = () => JSON.stringify(sys.bag.list.filter(item => indices.has(item.itemIndex) && available(item)).sort((a, b) => a.uid.localeCompare(b.uid)).map(state));
  const uid = target.uid, reviewedTarget = state(target), reviewedMaterials = materials(), reviewedRule = JSON.stringify(row);
  return () => {
    const live = sys.bag.list.find(item => item.uid === uid);
    return live && available(live) && state(live) === reviewedTarget && materials() === reviewedMaterials && JSON.stringify(row) === reviewedRule;
  };
}

export async function registerExchange(sys) {
  const g = sys.game, db = sys.db;
  const str = (c, k) => sys.str(c, k) || '';
  const owned = (i) => sys.bag.count(i);

  // =============================================================================================== accessory upgrade
  {
    let K = null, W = null;
    const S = { row: null, lines: [] };
    const rows = () => db.T?.accessoryUpgrade?.rows || [];
    const matList = (r) => { const out = []; for (let k = 1; k <= 6; k++) { const n = Number(r[`mat${k}Count`]) || 0; if (n > 0) out.push({ bound: Number(r[`mat${k}Bound`]) || 0, trade: Number(r[`mat${k}Trade`]) || 0, n }); } return out; };
    const haveMat = (m) => (m.bound ? owned(m.bound) : 0) + (m.trade && m.trade !== m.bound ? owned(m.trade) : 0);
    function tree() {
      const byMain = new Map();
      for (const r of rows()) {
        if (!byMain.has(r.mainCate)) byMain.set(r.mainCate, new Map());
        const sub = byMain.get(r.mainCate);
        if (!sub.has(r.subCate)) sub.set(r.subCate, []);
        sub.get(r.subCate).push(r);
      }
      const nodes = [];
      for (const [m, subs] of [...byMain].sort((a, b) => a[0] - b[0])) {
        nodes.push({
          text: str(351, m) || `#${m}`, open: false, selectable: false,
          children: [...subs].sort((a, b) => a[0] - b[0]).map(([s, list]) => ({
            text: str(351, s) || `#${s}`, open: false, selectable: false,
            children: list.sort((a, b) => a.sortOrder - b.sortOrder).map(r => ({ text: db.name(r.itemIndex), data: r, color: owned(r.itemIndex) ? 'ffffffff' : 'ff9a9a9a' })),
          })),
        });
      }
      W.control('multi_tree').setNodes?.(nodes);
    }
    function refresh() {
      if (!W) return;
      const r = S.row;
      W.control('pan_no_item').setVisible(!r);
      W.control('pan_resultItem').setVisible(!!r);
      W.control('pan_material').setVisible(!!r);
      S.src.show(r ? r.itemIndex : null);
      S.res.show(r ? r.resultItem : null);
      const mats = r ? matList(r) : [];
      S.lines.forEach((l, i) => {
        const m = mats[i];
        l.pan.setVisible(!!m);
        if (!m) return;
        const have = haveMat(m);
        l.slot.show(m.trade || m.bound);
        l.lbl.setText(`${db.name(m.trade || m.bound)}  ${fmt(have)} / ${fmt(m.n)}`);
        l.lbl.setTextColor(have >= m.n ? 'ffffffff' : 'ffff4040');
      });
      W.control('txt_req_money').setText(r ? fmt(r.costDil) : '');
      const ru = W.control('lbl_upgrade_rate');
      ru.setVisible(!!r);
      if (r) ru.setText((str(100, 203) || 'Success Rate <VALUE>%').replace('<VALUE>', String(Number(r.successRate) / 100)));
      rich(W.control('lbl_desc'), r ? str(352, r.subCate) : '');
      // 353:1-4 are "enhancement event in progress" notices (no event runs in solo); 353:5 / 353:6 describe the row
      rich(W.control('lbl_desc_event'), r ? (r.failResultItem ? str(353, 6) : Number(r.successRate) < 10000 ? str(353, 5) : '') : '');
      W.control('lbl_item_desc').setText(str(350, 198));
      const src = r ? K.findInBag([r.itemIndex]) : null;
      W.control('btn_strength').setEnabled(!!(r && src && mats.every(m => haveMat(m) >= m.n) && sys.dil >= (Number(r.costDil) || 0) && !K.busy));
    }
    function select(r) { S.row = r; W.control('pan_start_bg_accessory').hide(); refresh(); }
    function offer(inst) {
      const r = rows().find(x => Number(x.itemIndex) === inst.itemIndex);
      if (r) { select(r); return true; }
      sys.msg(1001, 85);
      return true;
    }
    async function craft() {
      const r = S.row;
      if (!r || K.busy) return;
      const src = K.findInBag([r.itemIndex]);
      if (!src) { sys.msg(350, 167); return; }
      const mats = matList(r);
      if (!mats.every(m => haveMat(m) >= m.n)) { sys.msg(null, null, clean(str(350, 166)).split('\\')[0]); return; }
      if (sys.dil < (Number(r.costDil) || 0)) { sys.msg(null, null, clean(str(350, 168)).split('\\')[0]); return; }
      if(g.save.authority==='server'){
        const intent={operation:'accessory',uid:src.uid,recipe:rows().indexOf(r)};
        const valid=conversionReview(sys,src,new Set(mats.flatMap(m=>[m.bound,m.trade]).filter(Boolean)),r);
        await K.review(str(1001,119),str(350,164),network=>network.action('convert',intent),()=>S.row===r&&valid()&&sys.dil>=Number(r.costDil)&&mats.every(m=>haveMat(m)>=m.n));
        tree();refresh();return;
      }
      if (!(await K.confirm(str(1001, 119), str(350, 164)))) return;
      if (!sys.spendDil(Number(r.costDil) || 0)) return;
      await K.progress(1.5, 103);
      for (const m of mats) { let left = m.n; if (m.bound) left -= spendItems(sys, m.bound, left); if (left > 0 && m.trade) spendItems(sys, m.trade, left); }
      const ok = Math.random() * 10000 < Number(r.successRate);
      if (ok) { convert(sys, src, r.resultItem); sysSound(sys, 101); sys.msg(350, 160); }
      else if (r.failResultItem) { convert(sys, src, r.failResultItem); sysSound(sys, 100); sys.msg(350, 161); }
      else if (r.penalty === 'ALLITEM_DESTRUCT') { sys.removeInst(src); sysSound(sys, 100); sys.msg(350, 163); }
      else { sysSound(sys, 100); sys.msg(350, 161); }
      g.events.emit('item:upgrade', { item: src, ok, kind: 'accessory' });
      sys.changed('upgrade', { item: src });
      if (ok) { const nx = rows().find(x => Number(x.itemIndex) === Number(r.resultItem)); if (nx) S.row = nx; }
      tree(); refresh();
    }
    g.uiwin.registerWindow('accupgrade', {
      script: 'game2/itemupgrade/ui_acc_upgradewnd_new.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'accupgrade');
        // pan_bg (layer 10) would cover pan_resultItem (layer 1) under the platform's "higher layer on top" rule; the
        // client draws them in document order (the background first), so the background goes to the bottom here
        const bg = win.find('pan_bg');
        if (bg?.el) bg.el.style.zIndex = '0';
        S.src = K.slot('item_upgrade', { view: true });
        S.res = K.slot('item_result', { view: true });
        for (let i = 0; i < 7; i++) {
          const pan = win.control(`pan_line${i}`);
          S.lines.push({ pan, lbl: pan.control('lbl_line_title'), slot: K.slot(pan.control('item_resource'), { view: true }) });
        }
        win.control('multi_tree').on?.('select', (node) => { if (node?.data) select(node.data); });
        win.control('pan_start_bg_accessory').onClick?.(() => win.control('pan_start_bg_accessory').hide());
        win.control('btn_strength').onClick(craft);
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) refresh(); });
        g.events.on('dil', () => { if (win.isOpen) refresh(); });
      },
      async onOpen(win, arg) { await db.tables(); S.row = null; win.control('pan_start_bg_accessory').show(); tree(); K.opened(win, arg, offer); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // =============================================================================================== helmet rank change
  {
    let K = null, W = null;
    const S = { row: null, lines: [] };
    const rows = () => db.T?.helmetRankChange?.rows || [];
    const mats = (r) => { const out = []; for (let k = 1; k <= 10; k++) { const i = Number(r[`Item${k}`] ?? r[`item${k}`]) || 0, n = Number(r[`count${k}`]) || 0; if (i && n) out.push({ i, n }); } return out; };
    function refresh() {
      if (!W) return;
      const r = S.row;
      S.res.show(r ? r.AfterItem : null);
      W.control('lbl_upgrade_item').setText(S.item.def ? S.item.def.name : r ? db.name(r.BeforItem) : '');
      W.control('lbl_upgrade_rank').setText(str(1001, 227));
      const m = r ? mats(r) : [];
      S.lines.forEach((l, i) => {
        const x = m[i];
        l.pan.setVisible(!!x);
        if (!x) return;
        l.slot.show(x.i);
        l.lbl.setText(`${db.name(x.i)}  ${fmt(owned(x.i))} / ${fmt(x.n)}`);
        l.lbl.setTextColor(owned(x.i) >= x.n ? 'ffffffff' : 'ffff4040');
      });
      W.control('lbl_percent').setText(r ? `${r['Upgrade Rate']}%` : '');
      W.control('lbl_cost').setText(r ? fmt(r.NeedDil) : '');
      rich(W.control('lbl_warning'), str(1001, 221));
      W.control('btn_change').setEnabled(!!(r && S.item.inst && !K.busy));
    }
    function list() {
      const byMain = new Map();
      for (const r of rows()) { if (!byMain.has(r.Main)) byMain.set(r.Main, []); byMain.get(r.Main).push(r); }
      W.control('multi_tree').setNodes?.([...byMain].map(([m, list]) => ({
        text: str(357, m) || db.kindName(db.def(list[0].BeforItem)) || `#${m}`, open: true, selectable: false,
        children: list.map(r => ({ text: `${db.name(r.BeforItem)}`, data: r, color: owned(r.BeforItem) ? 'ffffffff' : 'ff9a9a9a' })),
      })));
      const r = S.row;
      W.control('multi_tree_material').setNodes?.(r ? mats(r).map(x => ({ text: `${db.name(x.i)} x${fmt(x.n)}` })) : []);
    }
    function offer(inst) { return S.item.put(inst) || true; }
    async function change() {
      const r = S.row;
      if (!r || !S.item.inst || K.busy) return;
      if (!K.validate()) { refresh(); return; }
      const inst = S.item.inst;
      const m = mats(r);
      if (!m.every(x => owned(x.i) >= x.n)) { sys.msg(350, 191); return; }
      if (sys.dil < Number(r.NeedDil)) { sys.msg(350, 186); return; }
      if(g.save.authority==='server'){
        const intent={operation:'helmet',uid:inst.uid},valid=conversionReview(sys,inst,new Set(m.map(x=>x.i)),r);
        const result=await K.review(str(1001,221),str(100,200),network=>network.action('convert',intent),()=>S.row===r&&valid()&&sys.dil>=Number(r.NeedDil)&&m.every(x=>owned(x.i)>=x.n));
        if(result)for(const slot of K.slots)slot.clear(false);list();refresh();return;
      }
      if (!(await K.confirm(str(1001, 221), str(100, 200)))) return;
      if (!sys.spendDil(Number(r.NeedDil))) return;
      await K.progress(1.5, 98);
      for (const x of m) spendItems(sys, x.i, x.n);
      const ok = Math.random() * 100 < Number(r['Upgrade Rate']);
      if (ok) { S.item.clear(false); convert(sys, inst, r.AfterItem); sysSound(sys, 101); sys.msg(350, 184); }
      else { sysSound(sys, 100); sys.msg(350, 185); }
      sys.changed('upgrade', { item: inst });
      if (ok) S.row = null;
      list(); refresh();
    }
    g.uiwin.registerWindow('helmetrank', {
      script: 'game2/itemupgrade/ui_helmetupgradewnd.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'helmetrank');
        S.item = K.slot('upgrade_item', {
          accept: (inst, def) => { const r = rows().find(x => Number(x.BeforItem) === def.index); if (!r) return def?.slot ? [350, 188] : [350, 190]; S.row = r; return true; },
          count: false, onChange: () => { if (!S.item.inst) S.row = null; list(); refresh(); },
        });
        S.src = K.slot('item_upgrade', { view: true });
        S.res = K.slot('item_result', { view: true });
        for (let i = 0; i < 3; i++) {
          const pan = win.control(`pan_line${i}`);
          S.lines.push({ pan, lbl: pan.control('lbl_line_title'), slot: K.slot(pan.control('item_resource'), { view: true }) });
        }
        win.control('item_upgrade').hide();
        win.control('btn_open').onClick(() => { const p = win.control('pan_materials_info'); p.setVisible(!p.isVisible()); list(); });
        win.control('multi_tree').on?.('select', (node) => { if (node?.data && !S.item.inst) { S.row = node.data; list(); refresh(); } });
        win.control('btn_change').onClick(change);
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) { await db.tables(); S.row = null; K.opened(win, arg, offer); list(); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // =============================================================================================== seal item
  {
    let K = null, W = null;
    const S = {};
    const rowOf = (idx) => (db.T?.itemChange?.rows || []).find(r => Number(r.SourceItemIndex) === Number(idx)) || null;
    const powders = () => sys.bag.list.filter(i => isKind(db.def(i.itemIndex), 1, 18) && !/package|pack|box/i.test(db.name(i.itemIndex)));
    const powderCount = () => powders().reduce((a, i) => a + (i.count || 1), 0);
    function refresh() {
      if (!W) return;
      const r = S.item.def ? rowOf(S.item.def.index) : null;
      W.control('lbl_spendcount').setText(r ? `${fmt(powderCount())}/${fmt(r.SpendCount)}` : '');
      S.powder.show(powders()[0]?.itemIndex ?? 63741);
      W.control('btn_accept').setEnabled(!!(r && !K.busy));
    }
    function offer(inst) { const def = db.def(inst.itemIndex); if (isKind(def, 1, 18)) return true; return S.item.put(inst) || true; }
    async function seal() {
      const inst = S.item.inst;
      if (!inst) { sys.msg(350, 9); return; }
      if (!K.validate()) { refresh(); return; }
      const r = rowOf(inst.itemIndex);
      if (!r) { sys.msg(350, 3); return; }
      if (powderCount() < Number(r.SpendCount)) { sys.msg(350, 10); return; }
      if(g.save.authority==='server'){const result=await g.network.action('convert',{operation:'seal',uid:inst.uid});if(result){for(const slot of K.slots)slot.clear(false);refresh();}return;}
      await K.progress(1.2, 98);
      let left = Number(r.SpendCount);
      for (const p of powders()) { if (left <= 0) break; const k = Math.min(left, p.count || 1); sys.bag.take(p, k); left -= k; }
      S.item.clear(false);
      convert(sys, inst, r.DestItemIndex);
      inst.bound = false;
      sysSound(sys, 101); sys.msg(350, 1);
      sys.changed('upgrade', { item: inst });
      refresh();
    }
    g.uiwin.registerWindow('itemchange', {
      script: 'game2/itemupgrade/ui_changeitemwnd.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'itemchange');
        S.item = K.slot('change_item', { accept: (inst, def) => (rowOf(def.index) ? true : [350, 3]), count: false, onChange: () => refresh() });
        S.powder = K.slot('spend_item', { view: true });
        win.control('btn_accept').onClick(seal);
        win.control('pan_inven').hide();
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) { await db.tables(); K.opened(win, arg, offer); refresh(); },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // =============================================================================================== socket stone machine
  {
    let K = null, W = null;
    const S = { page: 'produce', machine: 0, locks: new Set(), tabs: [], slots: [], crush: [], log: [] };
    let DATA = null;
    const load = () => (DATA ||= Promise.all([
      fetchCSV('share/support/socketstone/socketstone_produce.csv').catch(() => []),
      fetchCSV('share/support/socketstone/socketstone_crusher.csv').catch(() => []),
    ]).then(([p, c]) => {
      const hp = p[0] || [], hc = c[0] || [];
      const obj = (h, v) => Object.fromEntries(h.map((k, i) => [k, isNaN(Number(v[i])) ? v[i] : Number(v[i])]));
      const machines = p.slice(1).filter(v => v.length > 5).map(v => {
        const o = obj(hp, v);
        o.results = [];
        for (let k = 1; k <= (o.Count || 20); k++) o.results.push({ item: Number(o[`Result_Item_${k}`]), dice: Number(o[`Dice_${k}`]), hi: Number(o[`Item_Highlight_${k}`]) });
        return o;
      });
      const crusher = new Map(c.slice(1).filter(v => v.length > 5).map(v => { const o = obj(hc, v); return [Number(o.Need_Item), o]; }));
      return { machines, crusher };
    }));
    const M = () => DATA && S.D?.machines[S.machine];
    const kindCount = (t, c) => sys.bag.list.filter(i => isKind(db.def(i.itemIndex), t, c)).reduce((a, i) => a + (i.count || 1), 0);
    const spendKind = (t, c, n) => { let left = n; for (const it of sys.bag.list.filter(i => isKind(db.def(i.itemIndex), t, c) && !sys.reserved?.has(i.uid))) { if (left <= 0) break; const k = Math.min(left, it.count || 1); sys.bag.take(it, k); left -= k; } return n - left; };
    const log = (t) => { S.log.push(t); W.control('text_result').addLine?.(t); };
    function refresh() {
      if (!W || !S.D) return;
      const prod = S.page === 'produce';
      W.control('pan_produce').setVisible(prod);
      W.control('pan_crusher').setVisible(!prod);
      if (prod) {
        const m = M();
        S.tabs.forEach((t, i) => { t.setChecked(i === S.machine); });
        S.slots.forEach((s, i) => {
          const r = m?.results[i];
          s.show(r?.item || null);
          s.ctrl.control('pan_highlight')?.setVisible(!!r?.hi);
          s.lock.setChecked?.(S.locks.has(i));
          s.ctrl.el.style.filter = S.locks.has(i) ? 'grayscale(1) brightness(0.45)' : '';
        });
        const nmax = Number(m?.Normal_Lock_Viable) || 0, pmax = Number(m?.Primium_Lock_Viable) || 0;
        W.control('lbl_normalmax').setText(String(nmax));
        W.control('lbl_cashmax').setText(String(pmax));
        const n = Math.min(S.locks.size, nmax);
        W.control('lbl_normaluse').setText(String(n));
        W.control('lbl_cashuse').setText(String(Math.max(0, S.locks.size - n)));
        W.control('lbl_cost').setText(fmt(m?.Need_DIL || 0));
        W.control('lbl_meal').setText(`${fmt(kindCount(0, Number(m?.Need_Item_Type) || 60))}/${fmt(m?.Need_Item_Count || 0)}`);
        W.control('btn_produce').setEnabled(!!(m && !K.busy));
      } else {
        let dil = 0, out = 0;
        for (const s of S.crush) if (s.inst) { const r = S.D.crusher.get(s.inst.itemIndex); if (r) { dil += Number(r.Need_Dil) || 0; out += Math.round(((Number(r.Count_Min) || 0) + (Number(r.Count_Max) || 0)) / 2); } }
        W.control('lbl_require_dil').setText(fmt(dil));
        S.result.show(out ? 7315 : null, out || null);
        W.control('lbl_result').setText(out ? `${db.name(7315)} ~${fmt(out)}` : '');
        W.control('btn_crusher').setEnabled(!!(S.crush.some(s => s.inst) && !K.busy));
      }
    }
    async function spin() {
      const m = M();
      if (!m || K.busy) return;
      if(g.save.authority==='server') {
        const result=await submitItemService(g,K,'stonemachine',{operation:'produce',machine:Number(m.Index),locks:[...S.locks]},refresh);
        const committed=result?.itemServiceResult;
        if(committed?.itemIndex){S.win.show(committed.itemIndex);sysSound(sys,101);log((str(350,130)||'%s item received.').replace('%s',db.name(committed.itemIndex)));}
        refresh();return;
      }
      const needType = Number(m.Need_Item_Type) || 60, needN = Number(m.Need_Item_Count) || 0, dil = Number(m.Need_DIL) || 0;
      if (kindCount(0, needType) < needN) { sys.msg(350, 126); return; }
      if (sys.dil < dil) { sys.msg(350, 127); return; }
      const nmax = Number(m.Normal_Lock_Viable) || 0, pmax = Number(m.Primium_Lock_Viable) || 0;
      const nl = Math.min(S.locks.size, nmax), pl = S.locks.size - nl;
      if (S.locks.size > nmax + pmax) { sys.msg(350, 128); return; }
      if (kindCount(0, Number(m.Normal_Lock_Need_ItemType) || 61) < nl || kindCount(0, Number(m.Primium_Lock_Need_ItemType) || 62) < pl) { sys.msg(350, 120); return; }
      if (!sys.canAdd(m.results[0]?.item || 7315, 1)) { sys.msg(350, 123); return; }
      if (!sys.spendDil(dil)) { sys.msg(350, 127); return; }
      spendKind(0, needType, needN);
      spendKind(0, Number(m.Normal_Lock_Need_ItemType) || 61, nl);
      spendKind(0, Number(m.Primium_Lock_Need_ItemType) || 62, pl);
      // roll on the cumulative dice, excluding locked slots
      const weights = m.results.map((r, i) => ({ i, w: r.dice - (i ? m.results[i - 1].dice : 0) })).filter(x => !S.locks.has(x.i) && x.w > 0);
      const total = weights.reduce((a, x) => a + x.w, 0);
      let x = Math.random() * total, win = weights[weights.length - 1]?.i ?? 0;
      for (const e of weights) { if (x < e.w) { win = e.i; break; } x -= e.w; }
      // the roulette light runs around the 20 slots and stops on the winner
      K.busy = true; refresh();
      sysSound(sys, 102);
      const steps = 20 * 2 + win;
      for (let s = 0; s <= steps; s++) {
        const k = s % 20;
        S.slots.forEach((sl, i) => { const tp = sl.ctrl.control('timer_gambleslot'); if (tp) { tp.setVisible(i === k); if (i === k) tp.start?.(); } else sl.ctrl.el.style.outline = i === k ? '2px solid #ffd24a' : ''; });
        await new Promise(r => setTimeout(r, 30 + Math.max(0, s - steps + 12) * 25));
      }
      K.busy = false;
      const item = m.results[win].item;
      S.win.show(item);
      sys.add(item, 1, { source: 'socketmachine', dropLeft: true });
      sysSound(sys, 101);
      log((str(350, 130) || '%s item received.').replace('%s', db.name(item)));
      refresh();
    }
    async function crush() {
      if (K.busy) return;
      if (!K.validate()) { refresh(); return; }
      const list = S.crush.filter(s => s.inst);
      if (!list.length) return;
      let dil = 0;
      for (const s of list) dil += Number(S.D.crusher.get(s.inst.itemIndex)?.Need_Dil) || 0;
      if (sys.dil < dil) { sys.msg(350, 127); return; }
      if (!(await K.confirm(str(350, 137), str(350, 136)))) return;
      if(g.save.authority==='server') {
        const result=await submitItemService(g,K,'stonemachine',{operation:'crush',uids:list.map(s=>s.inst.uid)},refresh);
        if(result){for(const s of S.crush)s.clear(false);sysSound(sys,101);refresh();}return;
      }
      if (!sys.spendDil(dil)) return;
      await K.progress(1.2, 98);
      let total = 0;
      for (const s of list) {
        const r = S.D.crusher.get(s.inst.itemIndex);
        const n = Math.round((Number(r.Count_Min) || 0) + Math.random() * ((Number(r.Count_Max) || 0) - (Number(r.Count_Min) || 0)));
        total += n;
        const inst = s.inst;
        s.clear(false);
        sys.bag.take(inst, 1);
      }
      if (total) sys.add(7315, total, { source: 'crusher', dropLeft: true });
      sysSound(sys, 101);
      sys.msg(null, null, (str(350, 133) || '%s %d pcs added up').replace('%s', db.name(7315)).replace('%d', fmt(total)));
      refresh();
    }
    function offer(inst) {
      if (S.page !== 'crusher') { sys.msg(350, 119); return true; }
      if (!S.D.crusher.has(inst.itemIndex)) { sys.msg(350, 114); return true; }
      const free = S.crush.find(s => !s.inst);
      if (free) free.put(inst); else sys.msg(350, 117);
      return true;
    }
    g.uiwin.registerWindow('stonegamble', {
      script: 'game2/itemupgrade/ui_stonegamble.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'stonegamble');
        for (let i = 0; i < 20; i++) {
          const ctrl = win.control(`gambleslot_${i}`);
          const s = K.slot(ctrl, { view: true });
          s.lock = ctrl.control('btn_gambleslot');
          s.lock.onClick(() => {
            const m = M();
            if (!m || K.busy) return;
            if (S.locks.has(i)) S.locks.delete(i);
            else if (S.locks.size >= (Number(m.Normal_Lock_Viable) || 0) + (Number(m.Primium_Lock_Viable) || 0)) { sys.msg(350, 116); return; }
            else S.locks.add(i);
            refresh();
          });
          S.slots.push(s);
        }
        S.win = K.slot('gamblewin', { view: true });
        S.crush = [...Array(10).keys()].map(i => K.slot(`stoneslot_${i}`, { accept: (inst, d) => (S.D?.crusher.has(d.index) ? true : [350, 114]), onChange: () => refresh() }));
        S.premium = K.slot('premiumstone', { view: true });
        S.result = K.slot('resultstone', { view: true });
        win.control('btn_produce').onClick(spin);
        win.control('btn_crusher').onClick(crush);
        win.control('btn_crusherwnd').onClick(() => { S.page = 'crusher'; refresh(); });
        win.control('btn_producewnd').onClick(() => { K.releaseAll(); S.page = 'produce'; refresh(); });
        for (const b of win.controls('btn_close')) b.onClick(() => win.close());
        win.control('pan_inven').hide();
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) {
        S.D = await load();
        // one tab per machine (btn_tab is the hidden template)
        if (!S.tabs.length) {
          const tpl = W.control('btn_tab');
          S.D.machines.forEach((m, i) => {
            const t = tpl.cloneAs(`_${i}`, { x: 9 + i * 72, y: 34, visible: true });
            t.setText(String(m.Name || `#${i + 1}`));
            t.onClick(() => { if (!K.busy) { S.machine = i; S.locks.clear(); refresh(); } });
            S.tabs.push(t);
          });
        }
        S.page = arg?.role === 'ITEM_SOCKETSTONE_CRUSHER' && arg?.crusher ? 'crusher' : 'produce';
        K.opened(win, arg, offer);
        refresh();
      },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }

  // =============================================================================================== talisman appearance
  {
    let K = null, W = null;
    const S = { list: [], top: 0, pick: -1, cells: [] };
    let DATA = null;
    const load = () => (DATA ||= fetchCSV('share/support/tarlismaneffecttransform/talismaneffecttransform.csv').then(rows => {
      const h = rows[0] || [];
      return rows.slice(1).filter(v => v.length > 5).map(v => Object.fromEntries(h.map((k, i) => [k, isNaN(Number(v[i])) ? String(v[i] || '').replace(/\\\\/g, ' ') : Number(v[i])])));
    }).catch(() => []));
    const COLS = 5, ROWS = 3;
    function refresh() {
      if (!W) return;
      const inst = S.item.inst;
      W.control('lbl_myitem').setText(inst ? inst.name : '');
      const cur = S.list.find(e => e.effectIndex === inst?.appearance);
      W.control('lbl_myeffectname').setText(cur ? cur.Description : '');
      W.control('pan_myeffect').setVisible(!!cur);
      S.cells.forEach((c, i) => {
        const e = S.list[S.top * COLS + i];
        c.setVisible(!!e);
        if (!e) return;
        c.control(`lbl_effectname${c.data.suf}`)?.setText(e.Description);
        c.data.sel?.setVisible(S.top * COLS + i === S.pick);
      });
      const e = S.list[S.pick];
      W.control('lbl_previeweffect').setText(e ? e.Description : '');
      const need = e && Number(e.NeedItemIndex1) ? [{ i: Number(e.NeedItemIndex1), n: Number(e.NeedItem1Count) || 1 }] : [];
      if (e && Number(e.NeedItemIndex2)) need.push({ i: Number(e.NeedItemIndex2), n: Number(e.NeedItem2Count) || 1 });
      [1, 2].forEach((k, j) => {
        const x = need[j];
        W.control(`pan_item${k}`).setVisible(!!x || k === 1);
        S.mats[j].show(x ? x.i : null);
        W.control(`lbl_item${k}`).setText(x ? db.name(x.i) : '');
        W.control(`lbl_itemcount${k}`).setText(x ? `${fmt(owned(x.i))} / ${fmt(x.n)}` : '');
      });
      W.control('lbl_dil').setText(e ? fmt(e.NeedDil) : '');
      W.control('btn_transform').setEnabled(!!(inst && e && !K.busy));
      W.control('btn_reset').setEnabled(!!(inst && inst.appearance != null && !K.busy));
      const sc = W.control('list_scroll');
      sc.setRange?.(Math.max(0, Math.ceil(S.list.length / COLS) - ROWS), ROWS); sc.setValue?.(S.top);
    }
    async function transform() {
      const inst = S.item.inst, e = S.list[S.pick];
      if (!inst || !e || K.busy) return;
      if (inst.appearance === e.effectIndex) { sys.msg(354, 42); return; }
      const need = [[e.NeedItemIndex1, e.NeedItem1Count], [e.NeedItemIndex2, e.NeedItem2Count]].filter(([i, n]) => Number(i) && Number(n));
      if (!need.every(([i, n]) => owned(Number(i)) >= Number(n))) { sys.msg(1001, 260); return; }
      if (sys.dil < Number(e.NeedDil)) { sys.msg(350, 197); return; }
      if (!(await K.confirm(str(354, 81), str(100, 181)))) return;
      if(g.save.authority==='server') {
        const result=await submitItemService(g,K,'talisman',{operation:'transform',uid:inst.uid,effect:Number(e.effectIndex)},refresh);
        if(result){S.item.clear(false);sysSound(sys,101);refresh();}return;
      }
      if (!sys.spendDil(Number(e.NeedDil))) return;
      for (const [i, n] of need) spendItems(sys, Number(i), Number(n));
      inst.appearance = e.effectIndex;
      sysSound(sys, 101);
      g.events.emit('item:appearance', { item: inst, effect: e.effectIndex });
      sys.changed('upgrade', { item: inst });
      refresh();
    }
    async function reset() {
      const inst = S.item.inst;
      if (!inst || inst.appearance == null || K.busy) return;
      const e = S.list.find(x => x.effectIndex === inst.appearance);
      const cost = Number(e?.ResetDil) || 0;
      if (!(await K.confirm((str(354, 82) || '').replace('%s', fmt(cost)), str(100, 181)))) return;
      if(g.save.authority==='server') {
        const result=await submitItemService(g,K,'talisman',{operation:'reset',uid:inst.uid},refresh);
        if(result){S.item.clear(false);sysSound(sys,101);refresh();}return;
      }
      if (!sys.spendDil(cost)) { sys.msg(350, 197); return; }
      delete inst.appearance;
      sysSound(sys, 101);
      g.events.emit('item:appearance', { item: inst, effect: null });
      sys.changed('upgrade', { item: inst });
      refresh();
    }
    g.uiwin.registerWindow('talisman', {
      script: 'game2/itemupgrade/ui_talismaneffecttransformwnd.txt',
      create(win) {
        W = win;
        K = new Crafting(sys, win, 'talisman');
        S.item = K.slot('item_myitem', { accept: (inst, def) => (isKind(def, 5, 18) ? true : [1001, 185]), count: false, onChange: () => refresh() });
        S.mats = [K.slot('item_material1', { view: true }), K.slot('item_material2', { view: true })];
        const tpl = win.control('btn_talisman');
        for (let r = 0; r < ROWS; r++) for (let c = 0; c < COLS; c++) {
          const k = r * COLS + c;
          const cell = tpl.cloneAs(`_${k}`, { x: 2 + c * 83, y: r * 88, visible: false });
          cell.data.suf = `_${k}`;
          // the selection frame is a sibling template of the cell button (pan_selectbox)
          const selTpl = win.find('pan_selectbox');
          cell.data.sel = selTpl ? selTpl.cloneAs(`_${k}`, { x: 2 + c * 83, y: r * 88, visible: false }) : null;
          cell.onClick(() => { S.pick = S.top * COLS + k; refresh(); });
          S.cells.push(cell);
        }
        tpl.hide();
        win.control('list_scroll').on?.('change', (v) => { S.top = Math.round(Number(v) || 0); refresh(); });
        win.control('btn_transform').onClick(transform);
        win.control('btn_reset').onClick(reset);
        g.events.on('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      async onOpen(win, arg) {
        S.list = await load();
        S.pick = -1; S.top = 0;
        K.opened(win, arg, (inst) => S.item.put(inst) || true);
        refresh();
      },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
  }
}
