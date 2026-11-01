// Costume windows: the transcendence costume "costume circulation" set (NPC COSTUME_CYCLE 124, "[Costume Design] I am
// ready to be fabulous."), five original windows sharing the left tab strip btn_sewing / btn_foundation / btn_option /
// btn_shape / btn_exchange (game2/costumeupgrade/*_renew.txt):
//   costumesewing      Transcendence: pick the appearance of the new Transcendence Costume (costumesewinglist.csv
//                      Type 0), sew with Mystical Fabric (costumesewing.csv Type 0: 100 fabric + 1,000,000 dil per
//                      attempt, 5 % (50,000 / 1,000,000)); sewing repeats the chosen number of attempts and stops at the
//                      first success. The result is the class's Transcendence Costume (transcendencecostume.csv, the
//                      "Transcendence Costume Ex-Box" 1761060 content) wearing the chosen appearance.
//   costumefoundation  Dismantle a costume of the bag (costumedisassemble.csv: fabric x Count_Min..Max for Need_Dil;
//                      a transcendence costume returns costumesewing.csv Type 1: 25 fabric, RETRUN_ITEM).
//   costumeoption      Change Options of a transcendence costume (Type 2: 40 fabric + 10,000,000 dil): three random
//                      options of costume_option.csv (mode = rarity divisor, see docs/MOUNTS.md), stored as the
//                      instance's random options (inst.rnd, counted by the items system's stats).
//   costumeshape       Appearance Change of a transcendence costume (Type 3: 100 fabric + 10,000,000 dil) to one of
//                      costumeshapechange.csv (Type 2); the look is inst.appearance (mounts/costume.js).
//   exchangefabric     Fabric Swap (Type 4: 1 bound fabric + 1 of 4002339 + 500 dil -> 1 tradable fabric 4002292).
// Strings: SYSTEM cate 2003 codes 230-256 (stringtable_system.txt "[message] Sewing failed." ...).
import { fmt, idxOf, setSlot, acceptItem, countItem, removeItem, removeInst, addItem, dil, spendDil, itemName, itemDef, str, ModelPreview, iconOf } from './ui-util.js';
import { submitCostumeService } from '../network/item-services.js';
import { FABRIC, optionNameMap, optionCodeByName, rollCostumeOptions, sewingSucceeds } from './costume-rules.js';

const TABS = [['btn_sewing', 'costumesewing'], ['btn_foundation', 'costumefoundation'], ['btn_option', 'costumeoption'], ['btn_shape', 'costumeshape'], ['btn_exchange', 'exchangefabric']];
const SYS = (win, code, fb) => str(win, 2003, code, fb, 'SYSTEM');

export function registerCostumeWindows(sys) {
  const g = sys.game, mgr = g.uiwin, data = sys.data;
  const ci = () => Number(g.player?.classIndex ?? g.save?.classIndex ?? 0);
  const sew = type => data.rows('costumeTables', 'costumeSewing').find(r => r.Type === type) || null;
  const fabricCount = () => FABRIC.reduce((a, i) => a + countItem(sys, i), 0);
  const takeFabric = (n) => {                                     // either variant (bound first)
    if (fabricCount() < n) return false;
    let left = n;
    for (const i of FABRIC) { const c = Math.min(left, countItem(sys, i)); if (c > 0 && removeItem(sys, i, c)) left -= c; }
    return left <= 0;
  };
  // appearance lists: only costumes the character's class can wear (item ClassMask) that have a look for the class
  const forClass = idx => { const d = itemDef(sys, idx); return (!d || ((Number(d.classMask) >>> ci()) & 1)) && !!data.costume(idx, ci()); };
  // option names of costume_option.csv -> option type codes (the items system's option table, else the mounts one)
  let byName = null;
  const typeOf = (name) => {
    byName ??= optionNameMap(g.items?.db?.options?.optionTypes, data.core?.optionLabels);
    return optionCodeByName(byName, name);
  };
  const transcendence = () => data.rows('costumeTables', 'transcendenceCostume').map(r => r.ItemIndex);
  const isTranscend = inst => transcendence().includes(idxOf(inst));
  const nav = (win) => {
    for (const [btn, name] of TABS) {
      const c = win.find(btn);
      if (!c) continue;
      c.setChecked(name === win.name);
      if (!c._mountsNav) { c._mountsNav = true; c.onClick(() => { if (win.name !== name) { win.close(); mgr.open(name); } }); }
    }
  };
  const money = (win, cost) => { win.control('lbl_use_money').setText(fmt(cost)); win.find('lbl_my_money') ? win.control('lbl_my_money').setText(fmt(dil(sys))) : win.control('lbl_money').setText(fmt(dil(sys))); };
  /** A 4-row appearance list (btn_itemshape_k + itemshape_k + lbl_item_info_k) with its vscroll. */
  const shapeList = (win, getList, onPick) => {
    const st = { top: 0, pick: null };
    const scroll = win.control('list_scroll');
    const render = () => {
      const list = getList();
      scroll.setRange?.(Math.max(0, list.length - 4), 4);
      for (let k = 0; k < 4; k++) {
        const idx = list[st.top + k];
        setSlot(sys, win.control(`itemshape_${k}`), idx || null);
        win.control(`lbl_item_info_${k}`).setText(idx ? itemName(sys, idx) : '');
        win.control(`btn_itemshape_${k}`).setChecked(!!idx && idx === st.pick).setEnabled(!!idx);
      }
    };
    scroll.on?.('change', v => { st.top = v; render(); });
    win.control('pan_shape_item_list').el?.addEventListener('wheel', (e) => { e.preventDefault(); st.top = Math.max(0, Math.min(Math.max(0, getList().length - 4), st.top + Math.sign(e.deltaY))); scroll.setValue?.(st.top); render(); }, { passive: false });
    for (let k = 0; k < 4; k++) win.control(`btn_itemshape_${k}`).onClick(() => { const idx = getList()[st.top + k]; if (idx) { st.pick = idx; render(); onPick(idx); } });
    return { st, render, reset: () => { st.top = 0; st.pick = null; scroll.setValue?.(0); render(); } };
  };
  const confirm = async (text, title) => (await mgr.msgbox(text, { kind: 'yesno', title })) === 'yes';

  const reg = (name, def) => { if (!mgr.has(name)) mgr.registerWindow(name, def); };

  // ------------------------------------------------------------------ Transcendence (sewing)
  reg('costumesewing', {
    script: 'game2/costumeupgrade/ui_costumesewingwnd_renew.txt',
    create(win) {
      const st = win.data.st = { count: 1, running: false };
      const preview = win.data.preview = new ModelPreview(sys, win.control('pan_bg'), { w: 340, h: 351, cover: win.find('pan_bg_black') });
      preview.bindButtons(win);
      const list = () => data.rows('costumeTables', 'costumeSewingList').filter(r => r.Type === 0 && forClass(r.Itemindex)).map(r => r.Itemindex);
      const L = shapeList(win, list, (idx) => { preview.showPlayer({ costume: idx }); refresh(); });
      win.data.list = L;
      const refresh = () => {
        const r = sew(0);
        setSlot(sys, win.control('item_material'), FABRIC[0], { count: '' });
        win.control('lbl_item_name').setText(itemName(sys, FABRIC[0]));
        win.control('lbl_make_count').setText(`${fabricCount()} / ${(r?.Keycount || 0) * st.count}`);
        win.control('lbl_count').setText(String(st.count));
        win.data.rateBase ??= win.control('lbl_rate').getText?.() || 'Success Rate';
        win.control('lbl_rate').setText(`${win.data.rateBase} ${((r?.Rate || 0) / 10000).toFixed(1)}%`);
        money(win, (r?.Dil || 0) * st.count);
        win.control('btn_ok').setVisible(!st.running);
        win.control('btn_stop').setVisible(st.running).setEnabled(st.running);   // script: enable false
      };
      win.data.refresh = refresh;
      const maxCount = () => { const r = sew(0); if (!r) return 0; return Math.max(0, Math.min(Math.floor(fabricCount() / Math.max(1, r.Keycount)), r.Dil ? Math.floor(dil(sys) / r.Dil) : 999)); };
      win.control('btn_min').onClick(() => { st.count = Math.max(1, st.count - 1); refresh(); });
      win.control('btn_plus').onClick(() => { st.count = Math.max(1, Math.min(Math.max(1, maxCount()), st.count + 1)); refresh(); });
      win.control('btn_max').onClick(() => { st.count = Math.max(1, maxCount()); refresh(); });
      win.control('btn_stop').onClick(() => { st.running = false; refresh(); });
      win.control('btn_ok').onClick(async () => {
        const r = sew(0);
        if (!L.st.pick) { sys.log(SYS(win, 244, '[message] Must select Transcendence Costume and new appearance.'), 'err'); return; }
        if (!r) return;
        if (!(await confirm(win.control('lbl_info').getText?.() || '', win.control('lbl_title').getText?.() || ''))) return;
        st.running = true; refresh();
        for (let n = 0; n < st.count && st.running && win.isOpen; n++) {
          if (fabricCount() < r.Keycount) { sys.log(SYS(win, 231, '[message] Not enough materials.'), 'err'); break; }
          if (dil(sys) < r.Dil) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); break; }
          if (g.save?.authority === 'server') {
            // one attempt per request: the server spends the fabric + dil, rolls Rate / 1,000,000 and makes the costume
            const result = await submitCostumeService(g, win, { operation: 'sew', appearance: L.st.pick });
            if (!result) break;                                   // refused (reason already shown): keep the selection
            if (result.itemServiceResult?.sewn) { sys.log(SYS(win, 234, '[message] Sewing successful.'), 'sys'); break; }
            sys.log(SYS(win, 233, '[message] Sewing failed.'), 'err');
            refresh();
            await new Promise(res => setTimeout(res, 600));
            continue;
          }
          if (!spendDil(sys, r.Dil) || !takeFabric(r.Keycount)) break;
          await new Promise(res => setTimeout(res, 600));
          if (sewingSucceeds(r.Rate, Math.random)) {
            const tc = transcendence().find(i => (Number(itemDef(sys, i)?.classMask) >>> ci()) & 1) || r.Itemindex;
            const res = addItem(sys, tc, 1, { source: 'sewing' });
            const inst = res?.placed?.[0];
            if (inst) inst.appearance = L.st.pick;
            sys.log(SYS(win, 234, '[message] Sewing successful.'), 'sys');
            break;
          }
          sys.log(SYS(win, 233, '[message] Sewing failed.'), 'err');
          refresh();
        }
        st.running = false; refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { nav(win); win.data.list.reset(); win.data.st.count = 1; win.data.preview.showPlayer({}); win.data.refresh(); },
    update(win, dt) { win.data.preview?.tick(dt); },
    onClose(win) { win.data.st.running = false; },
  });

  // ------------------------------------------------------------------ Dismantle
  reg('costumefoundation', {
    script: 'game2/costumeupgrade/ui_costumefoundationwnd_renew.txt',
    create(win) {
      const st = win.data.st = { pick: null };
      const grid = win.control('itemlist');
      const rule = inst => {
        const r = data.rows('costumeTables', 'costumeDisassemble').find(x => x.ItemIndex === idxOf(inst));
        if (r) return { out: r.Output_Item, min: r.Count_Min, max: r.Count_Max, dil: r.Need_Dil };
        if (isTranscend(inst)) { const t = sew(1); return t ? { out: t.KeyItem_index_1, min: t.Keycount, max: t.Keycount, dil: t.Dil } : null; }
        return null;
      };
      const costumes = () => [...(g.items?.bag?.list || []), ...(g.items?.costumeBag?.list || [])].filter(x => itemDef(sys, x)?.slot === 'costume' && rule(x));
      const refresh = () => {
        const list = costumes();
        grid.setItems(list.map((inst, i) => {
          const e = { x: i % grid.cols, y: Math.floor(i / grid.cols), w: 1, h: 1, data: inst, icon: null, color: st.pick === inst ? '#fdb602' : null };
          iconOf(sys, inst, grid.cw, grid.ch).then(ic => { e.icon = ic; grid.render(); });
          return e;
        }));
        const r = st.pick ? rule(st.pick) : null;
        money(win, r?.dil || 0);
        win.control('lbl_info').setText(r ? `${itemName(sys, r.out)} x${r.min === r.max ? r.min : `${r.min}~${r.max}`}` : '');
      };
      win.data.refresh = refresh;
      grid.setItemTooltip(it => (g.items?.tooltip ? g.items.tooltip(it.data) : itemName(sys, it.data)));
      grid.on('cellclick', (c, it) => { st.pick = it?.data || null; refresh(); });
      win.control('btn_ok').onClick(async () => {
        if(st.busy)return;
        const r = st.pick ? rule(st.pick) : null;
        if (!r) { sys.log(SYS(win, 238, '[message] No costumes to dismantle.'), 'err'); return; }
        if (dil(sys) < r.dil) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        if (!(await confirm(win.control('lbl_warning').getText?.() || '', win.control('lbl_title').getText?.() || ''))) return;
        if(g.save?.authority==='server') {
          const result=await submitCostumeService(g,win,{operation:'disassemble',uid:st.pick.uid});
          if(result){st.pick=null;refresh();}return;
        }
        if (!spendDil(sys, r.dil) || !removeInst(sys, st.pick, 1)) return;
        const n = r.min + Math.floor(Math.random() * (r.max - r.min + 1));
        addItem(sys, r.out, n, { source: 'costumedismantle' });
        sys.log(`${itemName(sys, r.out)} x${n}`, 'item');
        st.pick = null; refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { nav(win); win.data.refresh(); },
  });

  // ------------------------------------------------------------------ Change Options
  reg('costumeoption', {
    script: 'game2/costumeupgrade/ui_costumeoptionwnd_renew.txt',
    create(win) {
      const st = win.data.st = { costume: null };
      const opts = () => data.rows('costumeTables', 'costumeOption');
      const label = (name, v) => {
        const t = typeOf(name);
        return t != null ? sys.game.mounts.optionText(t, v) : `${name} ${v}`;
      };
      const refresh = () => {
        setSlot(sys, win.control('item_costume'), st.costume);
        win.control('lbl_costume_name').setText(st.costume ? itemName(sys, st.costume) : '');
        const cur = st.costume?.rnd || [];
        for (let k = 0; k < 3; k++) {
          const o = cur[k];
          win.control(`lbl_option_${k}`).setText(o ? sys.game.mounts.optionText(o[0], o[1]) : '');
        }
        const r = sew(2);
        setSlot(sys, win.control('item_material'), FABRIC[0], { count: '' });
        win.control('lbl_item_name').setText(itemName(sys, FABRIC[0]));
        win.control('lbl_make_count').setText(`${fabricCount()} / ${r?.Keycount || 0}`);
        win.control('pan_money').setVisible(!!st.costume);
        win.control('lbl_use_money').setText(fmt(r?.Dil || 0));
        win.control('lbl_money').setText(fmt(dil(sys)));
      };
      win.data.refresh = refresh;
      win.control('textbox').clear?.();
      for (const o of opts()) win.control('textbox').addLine?.(label(o.option, o.value));
      win.control('btn_open_list').onClick(() => { win.control('pan_option_list').show().setEnabled(true); win.control('btn_open_list').hide(); });
      win.control('btn_close_list').onClick(() => { win.control('pan_option_list').hide(); win.control('btn_open_list').show(); });
      acceptItem(sys, win.control('item_costume'), inst => (isTranscend(inst) ? true : SYS(win, 230, '[message] Transcendence Costume not selected.')), inst => { st.costume = inst; refresh(); });
      win.control('item_costume').data.onClear = () => { st.costume = null; refresh(); };
      win.control('btn_ok').onClick(async () => {
        const r = sew(2);
        if (!st.costume) { sys.log(SYS(win, 230, '[message] Transcendence Costume not selected.'), 'err'); return; }
        if (fabricCount() < r.Keycount) { sys.log(SYS(win, 231, '[message] Not enough materials.'), 'err'); return; }
        if (dil(sys) < r.Dil) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        if (!(await confirm(win.control('lbl_info').getText?.() || '', win.control('lbl_title').getText?.() || ''))) return;
        if (g.save?.authority === 'server') {
          // the server spends the fabric + dil and rolls the three options (shared rules: costume-rules.js)
          if (await submitCostumeService(g, win, { operation: 'option', uid: st.costume.uid })) refresh();
          return;
        }
        if (!spendDil(sys, r.Dil) || !takeFabric(r.Keycount)) return;
        st.costume.rnd = rollCostumeOptions(opts(), typeOf, Math.random);
        g.items?.changed?.('equip:costumeoption');
        refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { nav(win); win.control('pan_option_list').hide(); win.control('btn_open_list').show(); win.data.refresh(); },
    onClose(win) { win.data.st.costume = null; },
  });

  // ------------------------------------------------------------------ Appearance Change
  reg('costumeshape', {
    script: 'game2/costumeupgrade/ui_costumeshapewnd_renew.txt',
    create(win) {
      const st = win.data.st = { costume: null };
      const preview = win.data.preview = new ModelPreview(sys, win.control('pan_bg'), { w: 338, h: 351, cover: win.find('pan_bg_black') });
      preview.bindButtons(win);
      const list = () => data.rows('costumeTables', 'costumeShapeChange').filter(r => forClass(r.Itemindex)).map(r => r.Itemindex);
      const L = win.data.list = shapeList(win, list, (idx) => { preview.showPlayer({ costume: idx }); });
      const refresh = () => {
        setSlot(sys, win.control('item_costume'), st.costume);
        win.control('lbl_costume_name').setText(st.costume ? itemName(sys, st.costume) : '');
        const r = sew(3);
        setSlot(sys, win.control('item_material'), FABRIC[0], { count: '' });
        win.control('lbl_item_name').setText(itemName(sys, FABRIC[0]));
        win.control('lbl_make_count').setText(`${fabricCount()} / ${r?.Keycount || 0}`);
        money(win, r?.Dil || 0);
        L.render();
      };
      win.data.refresh = refresh;
      acceptItem(sys, win.control('item_costume'), inst => (isTranscend(inst) ? true : SYS(win, 242, '[message] This costume\'s appearance cannot be changed.')), inst => { st.costume = inst; refresh(); });
      win.control('item_costume').data.onClear = () => { st.costume = null; refresh(); };
      win.control('btn_ok').onClick(async () => {
        if(st.busy)return;
        const r = sew(3);
        if (!st.costume || !L.st.pick) { sys.log(SYS(win, 244, '[message] Must select Transcendence Costume and new appearance.'), 'err'); return; }
        if (fabricCount() < r.Keycount) { sys.log(SYS(win, 231, '[message] Not enough materials.'), 'err'); return; }
        if (dil(sys) < r.Dil) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        if (!(await confirm(win.control('lbl_info').getText?.() || '', win.control('lbl_title').getText?.() || ''))) return;
        if(g.save?.authority==='server'){await submitCostumeService(g,win,{operation:'shape',uid:st.costume.uid,appearance:L.st.pick});return;}
        if (!spendDil(sys, r.Dil) || !takeFabric(r.Keycount)) return;
        st.costume.appearance = L.st.pick;
        sys.log(SYS(win, 245, '[message] Costume appearance changed.'), 'sys');
        g.items?.changed?.('equip:costumeshape');
        refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { nav(win); win.data.list.reset(); win.data.preview.showPlayer({}); win.data.refresh(); },
    update(win, dt) { win.data.preview?.tick(dt); },
    onClose(win) { win.data.st.costume = null; },
  });

  // ------------------------------------------------------------------ Fabric Swap
  reg('exchangefabric', {
    script: 'game2/costumeupgrade/ui_exchangefebric_renew.txt',
    create(win) {
      const st = win.data.st = { count: 1 };
      const r = () => sew(4);
      const maxCount = () => { const x = r(); if (!x) return 0; return Math.max(0, Math.min(Math.floor(countItem(sys, x.KeyItem_index_1) / Math.max(1, x.Keycount)), Math.floor(countItem(sys, x.KeyItem_index_2) / Math.max(1, x.Keycount2 || 1)), x.Dil ? Math.floor(dil(sys) / x.Dil) : 99999)); };
      const refresh = () => {
        const x = r();
        if (!x) return;
        setSlot(sys, win.control('item_result'), x.Itemindex, { count: '' });
        win.control('lbl_result_item_name').setText(itemName(sys, x.Itemindex));
        setSlot(sys, win.control('item_material'), x.KeyItem_index_1, { count: '' });
        win.control('lbl_item_name').setText(itemName(sys, x.KeyItem_index_1));
        win.control('lbl_make_count').setText(`${countItem(sys, x.KeyItem_index_1)} / ${x.Keycount * st.count}`);
        setSlot(sys, win.control('item_material2'), x.KeyItem_index_2, { count: '' });
        win.control('lbl_item_name2').setText(itemName(sys, x.KeyItem_index_2));
        win.control('lbl_make_count2').setText(`${countItem(sys, x.KeyItem_index_2)} / ${(x.Keycount2 || 1) * st.count}`);
        win.control('lbl_count').setText(String(st.count));
        money(win, x.Dil * st.count);
      };
      win.data.refresh = refresh;
      win.control('btn_min').onClick(() => { st.count = Math.max(1, st.count - 1); refresh(); });
      win.control('btn_plus').onClick(() => { st.count = Math.max(1, Math.min(Math.max(1, maxCount()), st.count + 1)); refresh(); });
      win.control('btn_max').onClick(() => { st.count = Math.max(1, maxCount()); refresh(); });
      win.control('btn_ok').onClick(async () => {
        if(st.busy)return;
        const x = r();
        if (!x) return;
        const n = st.count;
        if (countItem(sys, x.KeyItem_index_1) < x.Keycount * n || countItem(sys, x.KeyItem_index_2) < (x.Keycount2 || 1) * n) { sys.log(SYS(win, 231, '[message] Not enough materials.'), 'err'); return; }
        if (dil(sys) < x.Dil * n) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        if(g.save?.authority==='server') {
          const result=await submitCostumeService(g,win,{operation:'fabric',count:n});
          if(result){st.count=1;refresh();}return;
        }
        if (!spendDil(sys, x.Dil * n)) return;
        removeItem(sys, x.KeyItem_index_1, x.Keycount * n);
        removeItem(sys, x.KeyItem_index_2, (x.Keycount2 || 1) * n);
        addItem(sys, x.Itemindex, n, { source: 'fabricswap' });
        st.count = 1; refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { nav(win); win.data.st.count = 1; win.data.refresh(); },
  });
}
