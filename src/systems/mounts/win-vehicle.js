// Vehicle windows (original scripts):
//   vehicle_mgmt   game2/vehicleupgrad/ui_vehicleupgradewnd.txt  "Vehicle Management": Crystallization (up to 10
//                  mounts -> Swift Crystals, vehicle.csv DisassembleIndex x GiveCount) and Evolution (a mount + its
//                  NeedItemIndex x NeedCount Swift Crystals -> the next-tier mount, the item's `next`). Opened by the
//                  main-menu btn_ride ("이동수단강화") and Ctrl+J (stringtable_item 1667: "Press (Ctrl + J) to evolve or
//                  crystalize the ride"). Strings: NORMAL cate 2005 codes 1001-1024.
//   vehicle_cycle  game2/vehicleupgrad/ui_vehiclecyclewnd.txt   "Enchant/Upgrade option of mount" (NPC VEHICLE_CYCLE 133):
//                  Enchant option (mount + a gearwheel, ADD_OPTION_COST dil: uniform choice across the source option
//                  pool under the existing engine policy, at level 0), Upgrade option (100 % success, Need_k Swift Crystals + NeedCost_k dil per
//                  level, 10 levels), Option info (every option's values per level). Strings: cate 355.
// The enchanted option lives on the mount instance (inst.vehicleOpt = {index, level}); it applies while riding
// (game.mounts.extraOptions()).
import { fmt, idxOf, setSlot, acceptItem, tabs, countItem, removeItem, removeInst, addItem, dil, spendDil, itemName, str } from './ui-util.js';

const MAX_CRYSTAL = 10;

export function registerVehicleWindows(sys) {
  const g = sys.game, mgr = g.uiwin, data = sys.data;
  const V = i => data.vehicle(idxOf(i));
  const say = (win, code, fb) => sys.log(str(win, 2005, code, fb), 'err');
  const sharedUnavailable = feature => {
    if (g.save?.authority !== 'server') return false;
    if (g.mounts?.vehicleServices && g.network?.active && g.network.ready && !g.network.disposed) return false;
    if (g.network?.unavailable) g.network.unavailable(feature);
    else sys.log(`${feature} is unavailable in shared play.`, 'err');
    return true;
  };
  const shared = () => g.save?.authority === 'server';
  const revision = () => g.save?.life?.vehicleServiceRevision || 0;
  const live = inst => !shared() || !inst ? inst : g.save.inventory?.find(item => item.uid === inst.uid) || null;

  // ------------------------------------------------------------------ Vehicle Management (crystallize / evolve)
  mgr.registerWindow('vehicle_mgmt', {
    script: 'game2/vehicleupgrad/ui_vehicleupgradewnd.txt',
    menuButton: 'btn_ride',
    hotkey: 'Ctrl+KeyJ',
    create(win) {
      const st = win.data.st = { tab: 0, crystal: Array(MAX_CRYSTAL).fill(null), target: null, material: null };
      const slots = Array.from({ length: MAX_CRYSTAL }, (_, i) => win.control(`slot_${i}`));
      const result = win.control('disassembleslot');
      const listed = () => st.crystal.filter(Boolean);
      const refresh = () => {
        if (shared()) { st.crystal = st.crystal.map(live); st.target = live(st.target); st.material = live(st.material); }
        // crystallization (slot i shows the mount registered in slot i)
        slots.forEach((c, i) => setSlot(sys, c, st.crystal[i] || null));
        let n = 0, out = 0;
        for (const inst of listed()) { const v = V(inst); if (v?.csv?.dis?.[0]) { out = v.csv.dis[0]; n += v.csv.dis[1] || 1; } }
        setSlot(sys, result, out ? out : null, { count: n > 1 ? n : '' });
        // evolution
        setSlot(sys, win.control('target_slot'), st.target);
        const need = st.target ? V(st.target)?.csv?.need : null;
        setSlot(sys, win.control('material_slot'), st.target && need?.[0] ? need[0] : st.material, { count: need?.[1] ? `${countItem(sys, need[0])}/${need[1]}` : '' });
        setSlot(sys, win.control('result_slot'), st.target ? V(st.target)?.next || null : null);
        win.control('btn_result').setText(str(win, 2005, st.tab === 0 ? 1004 : 1005, st.tab === 0 ? 'Crystallization' : 'Evolution'));
        win.control('lbl_notice_text').setRichText?.(str(win, 2005, st.tab === 0 ? 1017 : 1018, ''));
      };
      win.data.refresh = refresh;
      const release = i => {
        if (i !== 0) slots.forEach(c => c.data.slot?.clear(true));
        if (i !== 1) for (const id of ['target_slot', 'material_slot']) win.control(id).data.slot?.clear(true);
      };
      const sel = tabs(win, [['btn_tab_0', 'pan_vehicle_upgradwnd_disassemble'], ['btn_tab_1', 'pan_vehicle_upgradwnd_evolution']], i => { release(i); st.tab = i; refresh(); });
      win.data.sel = sel;
      const isMount = inst => !!V(inst);
      slots.forEach((c, i) => {
        acceptItem(sys, c, (inst) => {
          if (!isMount(inst)) return str(win, 2005, 1024, 'Only valid items can be registered.');
          if (!V(inst)?.csv?.dis?.[0]) return str(win, 2005, 1024, 'Only valid items can be registered.');
          if (isEquippedVehicle(sys, inst)) return str(win, 2005, 1010, 'Only selected item can be registered.');
          // registered in another slot of this window: it moves here (the slot machinery releases the other one)
          const j = st.crystal.findIndex(x => x && (x === inst || (x.uid && x.uid === inst.uid)));
          if (j >= 0 && j !== i) st.crystal[j] = null;
          if (listed().length >= MAX_CRYSTAL && !st.crystal[i]) return str(win, 2005, 1014, 'Maximum 10 vehicles can be registered to be crystallized.');
          return true;
        }, (inst) => { st.crystal[i] = inst; refresh(); });
        c.data.onClear = () => { st.crystal[i] = null; refresh(); };
      });
      acceptItem(sys, win.control('target_slot'), (inst) => {
        const v = V(inst);
        if (!v) return str(win, 2005, 1024, 'Only valid items can be registered.');
        if (!v.next || !v.csv?.need?.[0]) return str(win, 2005, 1006, 'Can only register vehicles that can evolve.');
        if (isEquippedVehicle(sys, inst)) return str(win, 2005, 1010, 'Only selected item can be registered.');
        return true;
      }, (inst) => { st.target = inst; refresh(); });
      win.control('target_slot').data.onClear = () => { st.target = null; refresh(); };
      acceptItem(sys, win.control('material_slot'), (inst) => {
        const need = st.target ? V(st.target)?.csv?.need : null;
        if (!need) return str(win, 2005, 1012, 'No vehicle to evolve is registered.');
        return idxOf(inst) === need[0] ? true : str(win, 2005, 1016, 'You need Swift Crystal to evolve your vehicles.');
      }, (inst) => { st.material = inst; refresh(); });
      win.control('btn_result').onClick(async () => {
        if (sharedUnavailable(st.tab === 0 ? 'Vehicle crystallization' : 'Vehicle evolution')) return;
        if (st.tab === 0) {
          if (!listed().length) { say(win, 1013, 'Registered vehicle to be crystallized.'); return; }
          const reviewed = listed().map(item => item.uid), reviewedRevision = revision();
          const ok = await mgr.msgbox(str(win, 2005, 1009, 'Would you Crystallize the registered vehicle?'), { kind: 'yesno', title: str(win, 2005, 1002, 'Crystallization') });
          if (ok !== 'yes') return;
          if (sharedUnavailable('Vehicle crystallization')) return;
          if (shared()) {
            if (JSON.stringify(listed().map(item => item.uid)) !== JSON.stringify(reviewed)) return;
            if (await g.mounts.vehicleServices.crystallize(reviewed, reviewedRevision)) { st.crystal = Array(MAX_CRYSTAL).fill(null); refresh(); }
            return;
          }
          let out = 0, n = 0;
          for (const inst of listed()) { const v = V(inst); if (!v?.csv?.dis?.[0]) continue; if (!removeInst(sys, inst, 1)) continue; out = v.csv.dis[0]; n += v.csv.dis[1] || 1; }
          if (out && n) addItem(sys, out, n, { source: 'crystallize' });
          if (out && n) sys.log(`${itemName(sys, out)} x${n}`, 'item');
          st.crystal = Array(MAX_CRYSTAL).fill(null);
          refresh();
        } else {
          const inst = st.target;
          const v = inst ? V(inst) : null;
          if (!v) { say(win, 1012, 'No vehicle to evolve is registered.'); return; }
          const [mat, cnt] = v.csv?.need || [0, 0];
          if (countItem(sys, mat) < cnt) { say(win, 1011, 'Not enough ingredient for evolution.'); return; }
          if (shared()) { if (await g.mounts.vehicleServices.evolve(inst.uid)) { st.target = null; st.material = null; refresh(); } return; }
          if (!removeItem(sys, mat, cnt)) { say(win, 1011, 'Not enough ingredient for evolution.'); return; }
          removeInst(sys, inst, 1);
          addItem(sys, v.next, 1, { source: 'evolve' });
          sys.log(`${itemName(sys, v.next)}`, 'item');
          st.target = null; st.material = null;
          refresh();
        }
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { win.data.sel(win.data.st.tab || 0); },
    onClose(win) { const st = win.data.st; st.crystal = Array(MAX_CRYSTAL).fill(null); st.target = null; st.material = null; },
  });

  // ------------------------------------------------------------------ Enchant / upgrade option of mount (NPC)
  mgr.registerWindow('vehicle_cycle', {
    script: 'game2/vehicleupgrad/ui_vehiclecyclewnd.txt',
    create(win) {
      const st = win.data.st = { tab: 0, vehicle: null, gear: null, up: null, crystal: null };   // registered bag items
      const opts = data.vehicleOptions();
      const needItem = opts[0]?.needItem || 7553;
      const optName = o => o ? (o.label || o.option) : '';
      const rows = () => opts.map(o => [optName(o), `${(100 / Math.max(1, opts.length)).toFixed(2)}%`, `+${fmt(o.values[10])}`]);
      win.control('freeboard').setRows(rows());
      win.control('freeboard_full').setRows(opts.map(o => [optName(o), ...o.values.map(v => fmt(v))]));
      const curOpt = inst => inst?.vehicleOpt ? { row: opts.find(o => o.index === inst.vehicleOpt.index), level: inst.vehicleOpt.level || 0 } : null;
      const refresh = () => {
        if (shared()) for (const key of ['vehicle', 'gear', 'up', 'crystal']) st[key] = live(st[key]);
        // enchant page
        setSlot(sys, win.control('item_vehicle'), st.vehicle);
        setSlot(sys, win.control('item_gear'), st.gear);
        const c = curOpt(st.vehicle);
        win.control('lbl_option_result').setText(c?.row ? `${optName(c.row)} +${fmt(c.row.values[c.level])}` : '');
        win.control('lbl_cost').setText(st.vehicle ? `${fmt(opts[0]?.addCost || 50000)} DIL` : '');
        // upgrade page
        setSlot(sys, win.control('item_vehicle_upgrade'), st.up);
        const u = curOpt(st.up);
        const have = countItem(sys, needItem);
        const nextLv = u ? Math.min(10, u.level + 1) : 0;
        setSlot(sys, win.control('item_vehicle_crystal'), st.crystal || (st.up ? needItem : null), { count: u && u.level < 10 ? `${have}/${u.row.need[nextLv - 1]}` : '' });
        win.control('lbl_now_option_step').setText(u ? `${str(win, 355, 34, 'level')} ${u.level}` : '');
        win.control('lbl_now_option').setText(u?.row ? `${optName(u.row)} +${fmt(u.row.values[u.level])}` : '');
        win.control('lbl_next_option_step').setText(u && u.level < 10 ? `${str(win, 355, 34, 'level')} ${nextLv}` : '');
        win.control('lbl_next_option').setText(u?.row && u.level < 10 ? `${optName(u.row)} +${fmt(u.row.values[nextLv])}` : '');
        win.control('lbl_cost_upgrade').setText(u?.row && u.level < 10 ? `${fmt(u.row.cost[nextLv - 1])} DIL` : '');
        const row = u?.row || opts[0];
        for (let k = 1; k <= 10; k++) {
          win.control(`lbl_tag_step_${k}`).setText(`${str(win, 355, 34, 'level')} ${k}`);
          win.control(`lbl_step_${k}`).setText(row ? str(win, 355, 35, 'x%d').replace('%d', fmt(row.need[k - 1])) : '');
        }
      };
      win.data.refresh = refresh;
      // changing the page gives the items registered on the other pages back to the bag
      const release = i => {
        if (i !== 0) for (const id of ['item_vehicle', 'item_gear']) win.control(id).data.slot?.clear(true);
        if (i !== 1) for (const id of ['item_vehicle_upgrade', 'item_vehicle_crystal']) win.control(id).data.slot?.clear(true);
      };
      const sel = tabs(win, [['btn_1', 'pan_bg1'], ['btn_2', 'pan_bg2'], ['btn_3', 'pan_bg3']], i => { release(i); st.tab = i; refresh(); });
      win.data.sel = sel;
      const mountCheck = inst => (V(inst) ? true : str(win, 2005, 42, 'The item type is invalid.'));
      acceptItem(sys, win.control('item_vehicle'), mountCheck, inst => { st.vehicle = inst; refresh(); });
      win.control('item_vehicle').data.onClear = () => { st.vehicle = null; refresh(); };
      acceptItem(sys, win.control('item_gear'), inst => (opts[0]?.addItems?.includes(idxOf(inst)) ? true : str(win, 2005, 46, 'The material is incorrect.')), inst => { st.gear = inst; refresh(); });
      win.control('item_gear').data.onClear = () => { st.gear = null; refresh(); };
      acceptItem(sys, win.control('item_vehicle_upgrade'), inst => {
        if (!V(inst)) return str(win, 2005, 42, 'The item type is invalid.');
        if (!inst.vehicleOpt) return str(win, 2005, 51, 'Only mounts with assigned options can be enhanced.');
        return true;
      }, inst => { st.up = inst; refresh(); });
      win.control('item_vehicle_upgrade').data.onClear = () => { st.up = null; refresh(); };
      acceptItem(sys, win.control('item_vehicle_crystal'), inst => (idxOf(inst) === needItem ? true : str(win, 2005, 46, 'The material is incorrect.')), inst => { st.crystal = inst; refresh(); });
      win.control('item_vehicle_crystal').data.onClear = () => { st.crystal = null; refresh(); };

      win.control('btn_accept_addoption').onClick(async () => {
        if (sharedUnavailable('Vehicle option enchantment')) return;
        if (!st.vehicle) { sys.log(str(win, 2005, 43, 'The mount does not exist.'), 'err'); return; }
        if (!st.gear || countItem(sys, idxOf(st.gear)) < 1) { sys.log(str(win, 2005, 44, 'The material does not exist.'), 'err'); return; }
        const cost = opts[0]?.addCost || 50000;
        if (dil(sys) < cost) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        const reviewed = { uid: st.vehicle.uid, gear: st.gear.uid, revision: revision() };
        if (st.vehicle.vehicleOpt) {
          const ok = await mgr.msgbox(str(win, 355, 10, '').split('\n').filter(Boolean).pop() || 'The existing option will be replaced.', { kind: 'yesno', title: str(win, 355, 8, 'Enchant option') });
          if (ok !== 'yes') return;
        }
        if (sharedUnavailable('Vehicle option enchantment')) return;
        if (shared()) {
          if (st.vehicle?.uid !== reviewed.uid || st.gear?.uid !== reviewed.gear) return;
          if (await g.mounts.vehicleServices.enchant(reviewed.uid, reviewed.gear, reviewed.revision)) refresh();
          return;
        }
        if (!spendDil(sys, cost) || !removeItem(sys, idxOf(st.gear), 1)) return;
        const row = opts[Math.floor(Math.random() * opts.length)];
        st.vehicle.vehicleOpt = { index: row.index, level: 0 };
        if (countItem(sys, idxOf(st.gear)) < 1 || (g.items?.bag && !g.items.bag.list.includes(st.gear))) st.gear = null;
        g.items?.changed?.('equip:vehicleoption');
        sys.onStatsChanged();
        refresh();
      });
      win.control('btn_accept_enhance').onClick(async () => {
        if (sharedUnavailable('Vehicle option enhancement')) return;
        const u = curOpt(st.up);
        if (!u?.row) { sys.log(str(win, 2005, 47, 'The option does not exist.'), 'err'); return; }
        if (u.level >= 10) { sys.log(str(win, 2005, 48, 'The item is already enhanced to the maximum level.'), 'err'); return; }
        const n = u.row.need[u.level], cost = u.row.cost[u.level];
        if (countItem(sys, needItem) < n) { sys.log(str(win, 2005, 49, 'Insufficient materials.'), 'err'); return; }
        if (dil(sys) < cost) { sys.log(str(win, 2005, 50, 'Insufficient DIL.'), 'err'); return; }
        if (shared()) { if (await g.mounts.vehicleServices.enhance(st.up.uid)) refresh(); return; }
        if (!spendDil(sys, cost) || !removeItem(sys, needItem, n)) return;
        st.up.vehicleOpt.level = u.level + 1;                       // 100 % success (cate 355 code 15)
        if (st.crystal && !(g.items?.bag?.list || []).includes(st.crystal)) st.crystal = null;   // used up
        g.items?.changed?.('equip:vehicleoption');
        sys.onStatsChanged();
        refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { win.data.sel(win.data.st.tab || 0); },
    onClose(win) { Object.assign(win.data.st, { vehicle: null, gear: null, up: null, crystal: null }); },
  });
}

function isEquippedVehicle(sys, inst) {
  const e = sys.riding.equipped();
  return !!(e?.inst && inst && (e.inst === inst || (e.inst.uid && e.inst.uid === inst.uid)));
}
