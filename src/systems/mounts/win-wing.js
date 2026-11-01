// Wing windows (game2/itemupgrade/ui_wing*.txt). Registered under the names the items system's NPC menu maps
// (WINGUPGRADE -> 'wingupgrade', WING_SHAPE_CHANGE -> 'wingshape') unless another system already registered them.
//   wingupgrade        "Wing Awakening" (NPC 121): the wing + Liberty Essence (wingupgrade.csv WINGS|CASH|<+N>:
//                      material x count, dil, success %, penalty NOT_FAIL) -> the wing's `next` (+N+1) item.
//   wingshape          "Change wings appearance" (NPC 146): the wing takes the look of another wing of the groups its
//                      wingchangelist.csv row allows (Group_Min..Group_Max) for NeedMoney dil + NeedMaterialIndex1 x
//                      NeedCount (the group-1 cost row); the look is inst.appearance (mounts/wings.js). Paged 10 per page.
//   wingrestore        "Reset wings appearance": back to the wing's own look (same cost).
//   wingclassexchange  "Wing Class Exchange" (kind 0/81 ticket): the same wing of another class (itemwingexchange.csv).
// Strings: SYSTEM cate 2003 codes 249-256; item upgrade strings in items-tables.json upgradeStrings.
import { fmt, idxOf, setSlot, acceptItem, countItem, removeItem, removeInst, addItem, dil, spendDil, itemName, itemDef, str, ModelPreview } from './ui-util.js';
import { submitWingService } from '../network/item-services.js';
import { wingChangeCandidates, wingUpgradeSucceeds } from './wing-rules.js';

const SYS = (win, code, fb) => str(win, 2003, code, fb, 'SYSTEM');

export function registerWingWindows(sys) {
  const g = sys.game, mgr = g.uiwin, data = sys.data;
  const ci = () => Number(g.player?.classIndex ?? g.save?.classIndex ?? 0);
  const isWing = inst => itemDef(sys, inst)?.slot === 'wing' || !!data.wing(idxOf(inst));
  const replaceInst = (inst, newIndex) => {
    // keep the instance (sockets, appearance, expiry) and swap its item index, as an upgrade does
    inst.itemIndex = newIndex;
    if (inst.index != null) inst.index = newIndex;
    g.items?.changed?.('equip:wing');
    g.events?.emit('inventory', { reason: 'wing' });
  };
  const reg = (name, def) => { if (!mgr.has(name)) { mgr.registerWindow(name, def); sys.wingWindowsOwned = true; } };

  // ------------------------------------------------------------------ Wing Awakening
  reg('wingupgrade', {
    script: 'game2/itemupgrade/ui_wingupgradewnd.txt',
    create(win) {
      const st = win.data.st = { wing: null };
      const rowFor = inst => {
        const lv = Number(itemDef(sys, inst)?.itemLv) || 0;
        return data.rows('wingTables', 'wingUpgrade').find(r => r.itemCode === 'WINGS' && r.level === lv) || null;
      };
      const refresh = () => {
        setSlot(sys, win.control('upgrade_item'), st.wing);
        win.control('lbl_upgrade_item').setText(st.wing ? itemName(sys, st.wing) : '');
        const r = st.wing ? rowFor(st.wing) : null;
        const mat = r?.material || 4000776;
        setSlot(sys, win.control('stone_item1'), mat, { count: '' });
        win.control('lbl_wingstone_name').setText(itemName(sys, mat));
        win.control('lbl_stone_have_count').setText(fmt(countItem(sys, mat)));
        win.control('lbl_stone_need_count').setText(r ? fmt(r.materialCount) : '');
        win.control('lbl_percent_count').setText(r ? `${r.rate}%` : '');
        win.control('lbl_cost').setText(r ? fmt(r.costDil) : '');
        const ready = !!r && countItem(sys, mat) >= r.materialCount;
        win.control('pan_wingstone_0_check').setVisible(ready);
        // the script leaves btn_strength `enable false`: it becomes usable once a wing and its material are ready
        win.control('btn_strength').setEnabled(ready && dil(sys) >= (r?.costDil || 0));
        win.control('btn_strength').setBlink?.(ready, 600);
      };
      win.data.refresh = refresh;
      acceptItem(sys, win.control('upgrade_item'), (inst) => {
        if (!isWing(inst)) return SYS(win, 253, '[message]No wings registered.');
        if (!itemDef(sys, inst)?.next || !rowFor(inst)) return str(win, 2005, 48, 'The item is already enhanced to the maximum level.');
        return true;
      }, (inst) => { st.wing = inst; refresh(); });
      win.control('upgrade_item').data.onClear = () => { st.wing = null; refresh(); };
      win.control('btn_strength').onClick(async () => {
        const r = st.wing ? rowFor(st.wing) : null;
        if (!r) { sys.log(win.control('lbl_ready').getText?.() || 'You need a Liberty Essence for Awakening of the wings.', 'err'); return; }
        if (countItem(sys, r.material) < r.materialCount) { sys.log(win.control('lbl_ready').getText?.() || '', 'err'); return; }
        if (dil(sys) < r.costDil) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        if (g.save?.authority === 'server') {
          // the server spends the cost, rolls the rate and turns the wing into its next level (shared rules: wing-rules.js)
          const result = await submitWingService(g, win, { operation: 'upgrade', uid: st.wing.uid }, 'btn_strength');
          if (!result) return;
          const done = result.itemServiceResult;
          if (done?.upgraded) sys.log(`${itemName(sys, done.itemIndex)}`, 'item');
          else sys.log(str(win, 40, 8, '[Message] Upgrade has failed.'), 'err');
          return;
        }
        if (!spendDil(sys, r.costDil) || !removeItem(sys, r.material, r.materialCount)) return;
        const next = itemDef(sys, st.wing)?.next;
        if (wingUpgradeSucceeds(r.rate, Math.random) && next) {
          replaceInst(st.wing, next);
          sys.log(`${itemName(sys, next)}`, 'item');
        } else sys.log(str(win, 40, 8, '[Message] Upgrade has failed.'), 'err');   // penalty NOT_FAIL: only the materials are lost
        refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { win.data.st.wing = null; win.data.refresh(); },
  });

  // ------------------------------------------------------------------ appearance change / reset
  const changeRows = () => data.rows('wingTables', 'wingChangeList');
  const costRow = () => changeRows().find(r => r.NeedMoney) || { NeedMoney: 1000000, NeedMaterialIndex1: 4000776, NeedCount: 70 };
  const rowOf = inst => changeRows().find(r => r.Index === idxOf(inst)) || null;
  // the candidate list is the shared rule (wing-rules.js), so the server accepts exactly what the window lists
  const candidates = (inst) => wingChangeCandidates({ rows: changeRows(), index: idxOf(inst), classIndex: ci(), defOf: i => itemDef(sys, i), visualOf: i => data.wing(i) });
  const shapeNav = (win) => {
    win.control('btn_shape').setChecked(win.name === 'wingshape');
    win.control('btn_restore').setChecked(win.name === 'wingrestore');
    if (!win.data._nav) {
      win.data._nav = true;
      win.control('btn_shape').onClick(() => { if (win.name !== 'wingshape') { win.close(); mgr.open('wingshape'); } });
      win.control('btn_restore').onClick(() => { if (win.name !== 'wingrestore') { win.close(); mgr.open('wingrestore'); } });
    }
  };
  const pay = (win) => {
    const c = costRow();
    setSlot(sys, win.control('item_materal'), c.NeedMaterialIndex1, { count: '' });
    win.control('lbl_materail_count').setText(`${countItem(sys, c.NeedMaterialIndex1)} / ${c.NeedCount}`);
    win.control('lbl_use_money').setText(fmt(c.NeedMoney));
    win.control('lbl_money').setText(fmt(dil(sys)));
    return c;
  };
  const charge = (win) => {
    const c = costRow();
    if (countItem(sys, c.NeedMaterialIndex1) < c.NeedCount) { sys.log(`${itemName(sys, c.NeedMaterialIndex1)} x${c.NeedCount}`, 'err'); return false; }
    if (dil(sys) < c.NeedMoney) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return false; }
    return spendDil(sys, c.NeedMoney) && removeItem(sys, c.NeedMaterialIndex1, c.NeedCount);
  };

  reg('wingshape', {
    script: 'game2/itemupgrade/ui_wingshapechange.txt',
    create(win) {
      const st = win.data.st = { wing: null, list: [], page: 0, pick: null };
      const preview = win.data.preview = new ModelPreview(sys, win.control('pan_bg'), { w: 338, h: 351, cover: win.find('pan_bg_black') });
      preview.yaw = Math.PI - 0.55;                              // wings: seen from behind
      preview.bindButtons(win);
      const refresh = () => {
        setSlot(sys, win.control('item_wing'), st.wing);
        st.list = st.wing ? candidates(st.wing) : [];
        const pages = Math.max(1, Math.ceil(st.list.length / 10));
        st.page = Math.min(st.page, pages - 1);
        for (let i = 0; i < 10; i++) {
          const idx = st.list[st.page * 10 + i];
          setSlot(sys, win.control(`wingshape_${i}`), idx || null);
          win.control(`lbl_wing_info_${i}`).setText(idx ? itemName(sys, idx) : '');
        }
        win.control('lbl_page').setText(`${st.page + 1}/${pages}`);
        const k = st.list.indexOf(st.pick) - st.page * 10;
        const fx = win.control('pan_select_effect');
        if (st.pick && k >= 0 && k < 10) { const c = win.control(`wingshape_${k}`), c0 = win.control('wingshape_0'); fx.move(fx.spec.rect?.[0] + c.box.x - c0.box.x, fx.spec.rect?.[1] + c.box.y - c0.box.y).show(); } else fx.hide();
        pay(win);
        preview.showPlayer({ wing: st.pick || (st.wing ? idxOf(st.wing) : null) });
      };
      win.data.refresh = refresh;
      acceptItem(sys, win.control('item_wing'), (inst) => {
        if (!isWing(inst)) return SYS(win, 249, '[message]Select the wings you want to change appearance.');
        if (!rowOf(inst)) return SYS(win, 251, '[message]Wings that cannot be changed appearance.');
        return true;
      }, (inst) => { st.wing = inst; st.pick = null; st.page = 0; refresh(); });
      win.control('item_wing').data.onClear = () => { st.wing = null; st.pick = null; refresh(); };
      for (let i = 0; i < 10; i++) win.control(`wingshape_${i}`).onClick(() => { const idx = st.list[st.page * 10 + i]; if (idx) { st.pick = idx; refresh(); } });
      win.control('btn_prev').onClick(() => { if (st.page > 0) { st.page--; refresh(); } });
      win.control('btn_next').onClick(() => { if ((st.page + 1) * 10 < st.list.length) { st.page++; refresh(); } });
      win.control('btn_guide').onClick(() => {
        const bg = win.control('pan_group_bg'), view = win.control('pan_view_bg');
        const on = !bg.isVisible();
        bg.setVisible(on).setEnabled(on); view.setVisible(!on);   // pan_group_bg: script enable false
        if (on) {
          const groups = {};
          for (const r of changeRows()) (groups[r.Group] ||= r);
          win.control('freeboard').setRows(Object.values(groups).map(r => [String(r.Group), itemName(sys, r.Index), `${r.Group_Min} ~ ${r.Group_Max}`]));
        }
      });
      win.control('btn_ok').onClick(async () => {
        if (!st.wing) { sys.log(SYS(win, 253, '[message]No wings registered.'), 'err'); return; }
        if (!st.pick) { sys.log(SYS(win, 249, '[message]Select the wings you want to change appearance.'), 'err'); return; }
        const r = await mgr.msgbox(`${itemName(sys, st.wing)} → ${itemName(sys, st.pick)}`, { kind: 'yesno', title: win.control('lbl_title').getText?.() || '' });
        if (r !== 'yes') return;
        if (g.save?.authority === 'server') {
          const result = await submitWingService(g, win, { operation: 'shape', uid: st.wing.uid, appearance: st.pick });
          if (result) { sys.log(SYS(win, 250, '[message]Successfully changed the appearance of the wings.'), 'sys'); st.pick = null; refresh(); }
          return;
        }
        if (!charge(win)) return;
        st.wing.appearance = st.pick;
        sys.log(SYS(win, 250, '[message]Successfully changed the appearance of the wings.'), 'sys');
        g.items?.changed?.('equip:wingshape');
        refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) pay(win); });
    },
    onOpen(win) { shapeNav(win); win.control('pan_group_bg').hide(); win.control('pan_view_bg').show(); win.data.refresh(); },
    update(win, dt) { win.data.preview?.tick(dt); },
    onClose(win) { win.data.st.wing = null; win.data.st.pick = null; },
  });

  reg('wingrestore', {
    script: 'game2/itemupgrade/ui_wingrestorewnd.txt',
    create(win) {
      const st = win.data.st = { wing: null };
      const preview = win.data.preview = new ModelPreview(sys, win.control('pan_bg'), { w: 338, h: 351, cover: win.find('pan_bg_black') });
      preview.yaw = Math.PI - 0.55;                              // wings: seen from behind
      preview.bindButtons(win);
      const refresh = () => {
        setSlot(sys, win.control('item_wing'), st.wing);
        setSlot(sys, win.control('item_restore'), st.wing?.appearance ? idxOf(st.wing) : null);
        pay(win);
        preview.showPlayer({ wing: st.wing ? idxOf(st.wing) : null });
      };
      win.data.refresh = refresh;
      acceptItem(sys, win.control('item_wing'), (inst) => (isWing(inst) && inst.appearance ? true : SYS(win, 253, '[message]No wings registered.')), (inst) => { st.wing = inst; refresh(); });
      win.control('item_wing').data.onClear = () => { st.wing = null; refresh(); };
      win.control('btn_ok').onClick(async () => {
        if (!st.wing?.appearance) { sys.log(SYS(win, 253, '[message]No wings registered.'), 'err'); return; }
        if (g.save?.authority === 'server') {
          if (await submitWingService(g, win, { operation: 'restore', uid: st.wing.uid })) sys.log(SYS(win, 255, '[message]The appearance of the wings has been restored.'), 'sys');
          return;
        }
        if (!charge(win)) return;
        delete st.wing.appearance;
        sys.log(SYS(win, 255, '[message]The appearance of the wings has been restored.'), 'sys');
        g.items?.changed?.('equip:wingshape');
        refresh();
      });
    },
    onOpen(win) { shapeNav(win); win.data.st.wing = null; win.data.refresh(); },
    update(win, dt) { win.data.preview?.tick(dt); },
  });

  // ------------------------------------------------------------------ Wing Class Exchange
  reg('wingclassexchange', {
    script: 'game2/itemupgrade/ui_wingclassexchangewnd.txt',
    create(win) {
      const st = win.data.st = { wing: null, cls: null, ticket: null };
      const groupOf = inst => data.rows('wingTables', 'wingExchange').find(r => Array.from({ length: 15 }, (_, c) => r[`class${c}`]).includes(idxOf(inst))) || null;
      // the 15 class icons are drawn in the window art (wing_class_exchange.dds) on a 4-column grid of 42 px cells from
      // (390, 120), pcclass order; btnjob is the invisible hit area, panjob the "unselectable" mark (sprite #10) and
      // the selection frame is sprite #9
      const btns = [], marks = [];
      for (let c = 0; c < 15; c++) {
        const x = 390 + (c % 4) * 42, y = 120 + Math.floor(c / 4) * 42;
        const b = win.clone('btnjob', `_${c}`, { x, y, visible: true });
        const p = win.clone('panjob', `_${c}`, { x: x + 7, y: y + 7, visible: false });
        b.setEnabled(true);
        b.setImage('check', 'wingclassexchange', 9);
        b.onClick(() => { if (b.enabled) { st.cls = c; refresh(); } });
        btns.push(b); marks.push(p);
      }
      const refresh = () => {
        setSlot(sys, win.control('upgrade_item'), st.wing);
        const grp = st.wing ? groupOf(st.wing) : null;
        btns.forEach((b, c) => {
          const ok = !!grp && !!grp[`class${c}`] && grp[`class${c}`] !== idxOf(st.wing);
          b.setEnabled(ok); b.setChecked(st.cls === c);
          marks[c].setVisible(!!grp && !ok);
        });
        const cls = st.cls != null ? g.data?.classByIndex?.get?.(st.cls) : null;
        win.control('lbl_jobname').setText(cls?.name || '');
        // the script leaves btn_exchange disabled ("enable flase"): usable once a wing and a target class are chosen
        win.control('btn_exchange').setEnabled(!!grp && st.cls != null && !!grp[`class${st.cls}`]);
      };
      win.data.refresh = refresh;
      acceptItem(sys, win.control('upgrade_item'), inst => (groupOf(inst) ? true : SYS(win, 253, '[message]No wings registered.')), inst => { st.wing = inst; st.cls = null; refresh(); });
      win.control('upgrade_item').data.onClear = () => { st.wing = null; st.cls = null; refresh(); };
      win.control('btn_exchange').onClick(async () => {
        const grp = st.wing ? groupOf(st.wing) : null;
        const target = grp && st.cls != null ? grp[`class${st.cls}`] : null;
        if (!target) return;
        const ticket = st.ticket && countItem(sys, idxOf(st.ticket)) ? idxOf(st.ticket) : findKind(sys, 0, 81);
        if (!ticket) { sys.log(itemName(sys, 0) || 'Wing Class Exchange', 'err'); return; }
        const r = await mgr.msgbox(win.control('lbl_warning_1').getText?.() || '', { kind: 'yesno', title: win.control('lbl_title').getText?.() || '' });
        if (r !== 'yes') return;
        if (g.save?.authority === 'server') {
          // the server consumes the ticket and turns the wing into the same wing of the chosen class
          if (await submitWingService(g, win, { operation: 'exchange', uid: st.wing.uid, classIndex: st.cls, ...(st.ticket?.uid ? { ticket: st.ticket.uid } : {}) }, 'btn_exchange')) { st.cls = null; refresh(); }
          return;
        }
        if (!removeItem(sys, ticket, 1)) return;
        replaceInst(st.wing, target);
        st.cls = null; refresh();
      });
    },
    onOpen(win, arg) { win.data.st.ticket = arg?.ticket || arg?.inst || null; win.data.st.wing = null; win.data.st.cls = null; win.data.refresh(); },
  });
}

function findKind(sys, type, code) {
  const it = sys.game.items;
  for (const x of it?.bag?.list || []) { const d = it.def?.(x.itemIndex); if (d && Number(d.type) === type && Number(d.code) === code) return x.itemIndex; }
  return null;
}
