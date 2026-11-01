// Pet windows (original scripts, strings PET cate 330 = script/string/pet/stringtable_petui.txt):
//   petinfo           game2/pet/ui_petinfownd.txt "Pet Management" (btn_petinven "펫관리", Y "Pet maintenance ( Y )"):
//                     General Info (model, name / rename / reset name, the pet item, healing (blessing) time, skill
//                     icons, the pet inventory), Soul Chain (re-roll a pet's options: PetSoulChangeNum times,
//                     PetSoulChangeDil, PetSoulChangeTime ms; Initialization with a Soul Chain Reset item), Pet
//                     Combination (3 pets -> an egg by petmaking.csv points / dice), Pet Setting (auto pickup filters).
//   pet_name          game2/pet/ui_nameinputwnd.txt + msgbox/ui_petnamechange.txt confirmation
//   pet_awake         game2/pet/ui_awakewnd.txt (Ocarina of Awakening / Eternity on a sleeping pet) +
//                     msgbox/pet/ui_petawake.txt / ui_petinfinity.txt confirmations
//   pet_stackdivide   game2/pet/ui_petstackdivide.txt (split a stack of the pet inventory)
//   pet_callalarm     game2/pet/ui_petcallalarmwnd.txt (the "Hatch" button while an unhatched pet egg is in the bag)
//   pet_preview       game2/pet/ui_petpreviewwnd.txt (3D preview next to a hovered pet item)
//   pet_shapechange / pet_disassemble / pet_shaperestore   NPC PET_TRANSFORM 163 (petshapechange.csv, petdisassemble.csv)
import { fmt, idxOf, setSlot, acceptItem, tabs, countItem, removeItem, removeInst, addItem, dil, spendDil, itemName, itemDef, str, ModelPreview, iconOf } from './ui-util.js';
import { PET_INV_W, PET_INV_H } from './pet.js';
import { resolvePetLayout, refreshPetDetails, bindRenewalPetControls } from './pet-ui-layout.js';
import {itemPayload,cursorActionResult} from '../items/ui/common.js';

const S = (win, code, fb) => str(win, 330, code, fb, 'PET');

export function registerPetWindows(sys) {
  const g = sys.game, mgr = g.uiwin, data = sys.data, pets = sys.pet;
  const online=()=>g.save?.authority==='server';
  const send=(type,fields)=>g.network?.action(type,fields);
  const stateOf = inst => (inst ? pets.state({ index: idxOf(inst), inst: typeof inst === 'object' ? inst : null }) : null);
  const isPetItem = inst => data.isPet(idxOf(inst));
  const summonedInst = () => (pets.summoned ? pets.equipped()?.inst : null);
  const same = (a, b) => !!a && !!b && (a === b || (a.uid && a.uid === b.uid));
  const progress = (bar, ms) => new Promise(res => {
    const t0 = performance.now();
    const step = () => { const f = Math.min(1, (performance.now() - t0) / ms); bar.setGauge(f); if (f < 1) requestAnimationFrame(step); else res(); };
    if (ms <= 0) { bar.setGauge(1); res(); } else requestAnimationFrame(step);
  });

  // ------------------------------------------------------------------ Pet Management
  mgr.registerWindow('petinfo', {
    script: 'game2/pet/ui_petinfownd.txt',
    resolveScript: resolvePetLayout,
    menuButton: 'btn_petinven',
    hotkey: 'KeyY',
    create(win) {
      const st = win.data.st = { tab: 0, soul: null, mix: [null, null, null], busy: false };
      const preview = win.data.preview = new ModelPreview(sys, win.control('item_petmodel'));
      const grid = win.control('slotbag');
      const refreshInv = () => {
        const s = pets.state();
        grid.setItems((s?.inv || []).map(it => {
          const cw = grid.cw, ch = grid.ch;
          const e = { x: it.x, y: it.y, w: it.w || 1, h: it.h || 1, count: it.count > 1 ? it.count : null, data: it, icon: null };
          iconOf(sys, it, e.w * cw, e.h * ch).then(ic => { e.icon = ic; grid.render(); });
          return e;
        }));
      };
      grid.setItemTooltip(it => (g.items?.tooltip ? g.items.tooltip(it.data) : itemName(sys, it.data)));
      // pet inventory -> bag: double / right click; drag to the bag works through the items system payload
      const toBag = (it) => {
        if(online()){if(it?.data)void send('petinventory',{operation:'withdraw',uid:it.data.uid});return;}
        const s = pets.state();
        if (!it || !s) return;
        // the stored instance itself goes back (its rolled options, sockets and grade are kept)
        const inst = { ...it.data };
        delete inst.x; delete inst.y; delete inst.w; delete inst.h; delete inst.page;
        const r = g.items?.add ? g.items.add(inst, { source: 'petinventory' }) : addItem(sys, inst.itemIndex, inst.count);
        if (!r) return;
        if (r.left > 0) {                                  // the bag is full (the items system shows its message)
          if (r.left < (inst.count || 1)) { it.data.count = r.left; refreshInv(); }
          return;
        }
        s.inv = s.inv.filter(x => x !== it.data);
        refreshInv();
      };
      grid.on('celldbl', (c, it) => toBag(it));
      grid.on('cellrclick', (c, it) => toBag(it));
      // Shift + drag a stack = split it (as in the bag): the Split Stack window asks the quantity on the drop
      const shiftDown = (e) => !!(e?.shiftKey || g.input?.down?.('ShiftLeft') || g.input?.down?.('ShiftRight'));
      grid.makeDraggable?.((e, gr) => {
        const c = gr.cellAt(e.clientX, e.clientY), it = c && gr.itemAt(c.x, c.y);
        if (!it) return null;
        const split = shiftDown(e) && (it.data.count || 1) > 1;
        if(!split&&g.items?.cursorPickup)return {...itemPayload(g.items,it.data,'pet',{parentUid:pets.equipped()?.inst?.uid},[gr.cw,gr.ch]),icon:it.icon};
        return { data: { kind: 'item', from: 'pet', petItem: it.data, itemIndex: it.data.itemIndex, count: it.data.count, split }, icon: it.icon, size: [it.w * gr.cw, it.h * gr.ch],
          onDropOutside: () => {}, onCancel: () => {} };
      });
      grid.acceptDrop?.({
        accept: d => d?.kind === 'item',
        drop: (d, e) => {
          const s = pets.state();
          if (!s) { sys.log(S(win, 119, 'Pet does not exist.'), 'err'); return false; }
          if(d.from==='cursor'){
            const cell=grid.cellAt(e.clientX,e.clientY),target=cell&&grid.itemAt(cell.x,cell.y);if(!cell)return false;
            const at=target?{x:target.data.x,y:target.data.y}:cell;
            return cursorActionResult(g.items,g.items.cursorPlace('pet',{parentUid:pets.equipped()?.inst?.uid,page:0,x:at.x,y:at.y,targetUid:target?.data?.uid??null}));
          }
          if(online()){
            if(d.from==='pet'){const c=grid.cellAt(e.clientX,e.clientY);if(!c||!d.petItem)return false;if(d.split){mgr.open('pet_stackdivide',{item:d.petItem,at:c});return true;}return Promise.resolve(send('petinventory',{operation:'move',uid:d.petItem.uid,x:Math.min(10-d.petItem.w,c.x),y:Math.min(4-d.petItem.h,c.y)})).then(Boolean);}
            if(d.from!=='bag'||!d.inst)return false;return Promise.resolve(send('petinventory',{operation:'deposit',uid:d.inst.uid})).then(Boolean);
          }
          if (d.from === 'pet') {                          // move inside the pet inventory
            const it = d.petItem, c = grid.cellAt(e.clientX, e.clientY);
            if (!it || !c) return false;
            const spot = { x: Math.min(PET_INV_W - it.w, c.x), y: Math.min(PET_INV_H - it.h, c.y) };
            if (d.split) { mgr.open('pet_stackdivide', { item: it, at: spot }); return true; }
            if (pets.freeSpot({ inv: s.inv.filter(x => x !== it) }, it.w, it.h) && !s.inv.some(o => o !== it && spot.x < o.x + o.w && spot.x + it.w > o.x && spot.y < o.y + o.h && spot.y + it.h > o.y)) { it.x = spot.x; it.y = spot.y; refreshInv(); return true; }
            return false;
          }
          const inst = d.inst;
          if (!inst) return false;
          const def = itemDef(sys, inst);
          if (def?.slot === 'pet' || isPetItem(inst)) { sys.log(S(win, 149, 'Item usage is not available in pet management window.'), 'err'); return false; }
          if (d.from && d.from !== 'bag') { sys.log(S(win, 148, 'Only item in general inventory can be registered.'), 'err'); return false; }
          if (!pets.addToInventory(s, { ...inst })) { sys.log(S(win, 128, 'Pet inventory space is insufficient.'), 'err'); return false; }
          removeInst(sys, inst, inst.count || 1);
          refreshInv();
          return true;
        },
      });

      const refreshDefault = () => {
        const eq = pets.equipped();
        const s = pets.state(eq);
        const def = eq ? data.pet(eq.index) : null;
        win.control('lbl_petname').setText(s?.name || def?.n || '');
        setSlot(sys, win.control('petitem'), eq?.inst || eq?.index || null);
        const left = Math.max(0, Number(s?.blessLeft) || 0);
        win.control('lbl_blesstime').setText(`${String(Math.floor(left / 60)).padStart(2, '0')}:${String(Math.floor(left % 60)).padStart(2, '0')}`);
        const sk = (data.ui?.petTables?.skill || []).find(r => r.index === Number(def?.cr?.skill ?? def?.skill ?? 0));
        refreshPetDetails(win, sys, def, s, sk?.skills);
        const look = (s?.shape && data.pet(s.shape)) || def;
        if (look) preview.showModel({ mesh: look.mesh, tpack: look.tpack, textures: look.textures, skel: look.kind === 'pet' ? look.table?.skel : look.skel,
          anim: look.kind === 'pet' ? data.anim(look.table?.rows?.find(r => r[1] === 1)?.[3]) : look.stand?.[0], timeLength: 1 });
        else preview.clear();
        win.control('btn_changename').setEnabled(!!eq && !s?.named);
        win.control('btn_resetname').setEnabled(!!eq && !!s?.named);
        refreshInv();
      };
      const refreshSoul = () => {
        setSlot(sys, win.control('soulchange_item'), st.soul);
        const s = stateOf(st.soul);
        const def = st.soul ? data.pet(idxOf(st.soul)) : null;
        win.control('lbl_remainchangecount').setText(s ? String(s.soulLeft ?? 0) : '');
        win.control('lbl_soulchangecost').setText(fmt(def?.cr?.raw?.PetSoulChangeDil ?? 0));
        win.control('processbar_soulchange').setGauge(0);
        const resetItem = (pets.state()?.inv || []).find(x => { const d = itemDef(sys, x); return d && Number(d.type) === 0 && Number(d.code) === 58; });
        const resetSlot = win.find('item_sc_resetitem');
        if (resetSlot) setSlot(sys, resetSlot, resetItem || null);
      };
      const mixInfo = () => {
        let pts = 0;
        for (const inst of st.mix) if (inst) pts += Number(data.pet(idxOf(inst))?.cr?.raw?.PetMakingPoint ?? 0);
        const rows = (data.ui?.petTables?.making || []).slice().sort((a, b) => a.point - b.point);
        let row = null;
        for (const r of rows) if (pts >= r.point) row = r;
        return { pts, row };
      };
      const refreshMix = () => {
        st.mix.forEach((inst, i) => setSlot(sys, win.control(`transition${i + 1}_item`), inst));
        const { row } = mixInfo();
        win.control('lbl_mixcost').setText(row ? fmt(row.dil) : '');
        const pct = v => (row ? Math.round((v / Math.max(1, row.range)) * 100) : 0);
        const show = !!row && st.mix.every(Boolean);
        ['unique', 'rare', 'normal'].forEach((grade, i) => {
          const slot = win.find('item_tr_res_' + i);
          const outcome = grade === 'unique' && row?.useLegend && row.legendEgg ? row.legendEgg : row?.[grade]?.[0];
          if (slot) setSlot(sys, slot, show ? outcome || null : null);
        });
        win.control('lbl_probability_unique').setVisible(show).setText(S(win, 161, '* Unique Pet Egg : %d%').replace('%d', pct(row?.unique?.[1] || 0)));
        win.control('lbl_probability_rare').setVisible(show).setText(S(win, 162, '* Rare Pet Egg : %d%').replace('%d', pct(row?.rare?.[1] || 0)));
        win.control('lbl_probability_normal').setVisible(show).setText(S(win, 163, '* Normal Pet Egg : %d%').replace('%d', pct(row?.normal?.[1] || 0)));
        win.control('processbar_mix').setGauge(0);
      };
      const setChecks = () => {
        const s = pets.state();
        const set = s?.settings || {};
        const map = { check_on: !!set.auto, check_off: !set.auto, check_normalitem: set.normal, check_accessory: set.accessory, check_magicitem: set.magic,
          check_nobleitem: set.noble, check_devinenobleitem: set.divine, check_legenditem: set.legend, check_reinforcementitem: set.enhance,
          check_etcitem: set.etc, check_socketitem: set.socket };
        for (const [id, v] of Object.entries(map)) win.control(id).setChecked(!!v);
      };
      const bindCheck = (id, key) => win.control(id).onChange((v) => {if(online()){void send('petsettings',{settings:{[key]:!!win.control(id).isChecked()}});return;} const s = pets.state(); if (!s) return; s.settings[key] = !!win.control(id).isChecked(); });
      win.control('check_on').onChange(() => {if(online()){void send('petsettings',{settings:{auto:true}});return;} const s = pets.state(); if (s) { s.settings.auto = true; setChecks(); } });
      win.control('check_off').onChange(() => {if(online()){void send('petsettings',{settings:{auto:false}});return;} const s = pets.state(); if (s) { s.settings.auto = false; setChecks(); } });
      bindCheck('check_normalitem', 'normal'); bindCheck('check_accessory', 'accessory'); bindCheck('check_magicitem', 'magic');
      bindCheck('check_nobleitem', 'noble'); bindCheck('check_devinenobleitem', 'divine'); bindCheck('check_legenditem', 'legend');
      bindCheck('check_reinforcementitem', 'enhance'); bindCheck('check_etcitem', 'etc'); bindCheck('check_socketitem', 'socket');

      const refresh = () => { if (st.tab === 0) refreshDefault(); else if (st.tab === 1) refreshSoul(); else if (st.tab === 2) refreshMix(); else setChecks(); };
      win.data.refresh = refresh;
      // changing the page gives the items registered on the other pages back to the bag
      const release = (i) => {
        if (i !== 1 && st.soul) win.control('soulchange_item').data.slot?.clear(true);
        if (i !== 2) st.mix.forEach((x, k) => { if (x) win.control(`transition${k + 1}_item`).data.slot?.clear(true); });
      };
      win.data.sel = tabs(win, [['btn_default', ['pan_mid_default', 'pan_inven']], ['btn_anneal', ['pan_mid_soulchange', 'pan_inven']],
        ['btn_transition', ['pan_mid_transition', 'pan_inven']], ['btn_setting', 'pan_mid_setting']], (i) => { release(i); st.tab = i; refresh(); });
      win.control('btn_close').onClick(() => win.close());
      bindRenewalPetControls(win);

      // name
      win.control('btn_changename').onClick(() => {
        if (!pets.equipped()) { sys.log(S(win, 119, 'Pet does not exist.'), 'err'); return; }
        if (pets.summoned) { sys.log(S(win, 58, 'You cannot set a name while summoning a pet.'), 'err'); return; }
        mgr.open('pet_name');
      });
      win.control('btn_resetname').onClick(async () => {
        const s = pets.state();
        if (!s?.named) { sys.log(S(win, 166, 'The pet name has not been changed, so it cannot be reset.'), 'err'); return; }
        const r = await mgr.msgbox(S(win, 165, 'Reset Equipped Pet Name'), { kind: 'yesno', title: S(win, 164, 'Reset Name') });
        if (r !== 'yes') return;
        if(online()){await send('petname',{reset:true});return;}
        s.name = ''; s.named = false;
        if (pets.actor) pets.actor.name = data.pet(pets.item)?.n || '';
        refresh();
      });

      // soul chain
      acceptItem(sys, win.control('soulchange_item'), (inst) => {
        if (!isPetItem(inst)) return S(win, 126, 'It is not a pet item.');
        if (same(inst, summonedInst())) return S(win, 120, 'You can\'t use Soul Chain on a summoned pet.');
        const s = stateOf(inst);
        if (s?.sleep) return S(win, 152, 'Sleeping pet can’t be registered.');
        if (inst.expiresAt && inst.expiresAt < Date.now() && !s?.eternal) return S(win, 144, '[message] You cannot use Soul Chain on an expired pet.');
        return true;
      }, (inst) => { st.soul = inst; refreshSoul(); });
      win.control('soulchange_item').data.onClear = () => { st.soul = null; refreshSoul(); };
      win.control('btn_soulchange').onClick(async () => {
        if(online()){if(st.soul)await send('petsoul',{uid:st.soul.uid});return;}
        if (st.busy) return;
        if (!st.soul) { sys.log(S(win, 116, 'No Soul Chain item.'), 'err'); return; }
        const s = stateOf(st.soul), def = data.pet(idxOf(st.soul));
        if (!(s.soulLeft > 0)) { sys.log(S(win, 134, 'You have used all Soul Chain counts.'), 'err'); return; }
        const cost = Number(def?.cr?.raw?.PetSoulChangeDil ?? 0);
        if (dil(sys) < cost) { sys.log(S(win, 121, 'Insufficient deal.'), 'err'); return; }
        const inst = st.soul;
        st.busy = true;
        await progress(win.control('processbar_soulchange'), Number(def?.cr?.raw?.PetSoulChangeTime ?? 2000));
        st.busy = false;
        if (st.soul !== inst || !win.isOpen) { win.control('processbar_soulchange').setGauge(0); return; }   // taken out meanwhile
        if (!spendDil(sys, cost)) return;
        s.opts = pets.rollOptions(def);
        s.soulLeft -= 1;
        sys.log(S(win, 141, '[message] Soul Chain successful.'), 'sys');
        g.items?.changed?.('equip:petsoul');
        refreshSoul();
      });
      win.control('btn_initsoulchange').onClick(async () => {
        if(online()){if(st.soul)await send('petsoul',{uid:st.soul.uid,reset:true});return;}
        if (!st.soul) { sys.log(S(win, 119, 'Pet does not exist.'), 'err'); return; }
        const s = stateOf(st.soul), def = data.pet(idxOf(st.soul));
        if (s.soulLeft > 0) { sys.log(S(win, 155, 'You cannot reset Soul Chain counts, since there are still Soul Chains remaining.'), 'err'); return; }
        // the Soul Chain Reset item is taken from the PET inventory (PET 156 "You don't have a Reset Item in Pet Inventory")
        const ps = pets.state();
        const reset = (ps?.inv || []).find(x => { const d = itemDef(sys, x); return d && Number(d.type) === 0 && Number(d.code) === 58; });
        if (!reset) { sys.log(S(win, 156, 'You don\'t have a Reset Item in Pet Inventory. Pet Soul Chain count will not be reset.'), 'err'); return; }
        if ((reset.count || 1) > 1) reset.count -= 1; else ps.inv.splice(ps.inv.indexOf(reset), 1);
        g.events?.emit('petinventory', { reason: 'soulreset' });
        s.soulLeft = Number(def?.cr?.raw?.PetSoulChangeNum ?? 10);
        sys.log(S(win, 133, 'The number of your current pet\'s Soul Chain has been initialized.'), 'sys');
        refreshSoul();
      });

      // combination
      for (let i = 0; i < 3; i++) {
        const c = win.control(`transition${i + 1}_item`);
        acceptItem(sys, c, (inst) => {
          if (!isPetItem(inst)) return S(win, 126, 'It is not a pet item.');
          if (same(inst, pets.equipped()?.inst)) return S(win, 127, 'You can\'t combine currently used pet.');
          const s = stateOf(inst);
          if (inst.expiresAt && inst.expiresAt < Date.now() && !s?.eternal) return S(win, 145, '[message] You cannot combine the expired pet.');
          const j = st.mix.findIndex(x => same(x, inst));             // registered in another slot: it moves here
          if (j >= 0 && j !== i) st.mix[j] = null;
          return true;
        }, (inst) => { st.mix[i] = inst; refreshMix(); });
        c.data.onClear = () => { st.mix[i] = null; refreshMix(); };
      }
      win.control('btn_mix').onClick(async () => {
        if(online()){g.network?.unavailable('Pet combination');return;}
        if (st.busy) return;
        if (!st.mix.every(Boolean)) { sys.log(S(win, 125, 'There are no pet combination items.'), 'err'); return; }
        const { row } = mixInfo();
        if (!row) { sys.log(S(win, 117, 'No table information.'), 'err'); return; }
        if (dil(sys) < row.dil) { sys.log(S(win, 121, 'Insufficient deal.'), 'err'); return; }
        const regs = st.mix.slice();
        st.busy = true;
        await progress(win.control('processbar_mix'), row.timeMs);
        st.busy = false;
        if (!win.isOpen || st.mix.some((x, k) => x !== regs[k])) { win.control('processbar_mix').setGauge(0); return; }
        if (!spendDil(sys, row.dil)) return;
        for (const inst of st.mix) removeInst(sys, inst, 1);
        let x = Math.random() * Math.max(1, row.range), egg = row.normal[0];
        for (const [idx, w] of [row.unique, row.rare, row.normal]) { x -= w; if (x <= 0 && idx) { egg = idx; break; } }
        // UseLegend rows (the 100 / 120 / 180 point tiers): the unique outcome is the LegendEgg ("Unique Pet Egg (Socket)")
        if (row.useLegend && row.legendEgg && egg === row.unique[0]) egg = row.legendEgg;
        addItem(sys, egg, 1, { source: 'petcombine' });
        sys.log(S(win, 124, '[message] Succeeded in combining a pet.'), 'sys');
        st.mix = [null, null, null];
        refreshMix();
      });
      g.events?.on?.('petinventory', () => { if (win.isOpen && st.tab !== 3) refreshInv(); });
      let inventoryParent=pets.equipped()?.inst?.uid;
      g.events?.on?.('inventory',()=>{const parent=pets.equipped()?.inst?.uid;if(win.isOpen){if(parent!==inventoryParent)refresh();else if(st.tab!==3)refreshInv();}inventoryParent=parent;});
      g.events?.on?.('pet', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { win.data.sel(win.data.st.tab || 0); },
    update(win, dt) {
      win.data.preview?.tick(dt);
      win.data._t = (win.data._t || 0) + dt;
      if (win.data._t > 1 && win.data.st.tab === 0) { win.data._t = 0; const s = pets.state(); const left = Math.max(0, Number(s?.blessLeft) || 0); win.control('lbl_blesstime').setText(`${String(Math.floor(left / 60)).padStart(2, '0')}:${String(Math.floor(left % 60)).padStart(2, '0')}`); }
    },
    onClose(win) { const st = win.data.st; st.soul = null; st.mix = [null, null, null]; },
  });

  // ------------------------------------------------------------------ name input
  mgr.registerWindow('pet_name', {
    script: 'game2/pet/ui_nameinputwnd.txt',
    modal: true,
    create(win) {
      const edit = win.control('edit_text');
      const ok = async () => {
        const name = String(edit.getValue?.() || '').trim();
        if (!name) return;
        const box = await mgr.create('game2/msgbox/ui_petnamechange.txt', { modal: true, disposeOnClose: true, remember: false });
        box.control('lbl_text').setText(S(box, 62, '[<NAME>]').replace('<NAME>', name));
        const r = await new Promise(res => { box.once('close', v => res(v)); box.control('btn_yes').onClick(() => box.close('yes')); box.control('btn_no').onClick(() => box.close('no')); mgr.openWindow(box); });
        if (r !== 'yes') return;
        const s = pets.state();
        if (!s) return;
        if(online()){const result=await send('petname',{name});if(result)win.close('ok');return;}
        s.name = name; s.named = true;
        if (pets.actor) pets.actor.name = name;
        win.close('ok');
        mgr.window('petinfo')?.data?.refresh?.();
      };
      win.control('btn_yes').onClick(ok);
      edit.on?.('enter', ok);
      win.control('btn_no').onClick(() => win.close('cancel'));
    },
    onOpen(win) { const e = win.control('edit_text'); e.setValue?.(''); setTimeout(() => e.focus?.(), 0); },
  });

  // ------------------------------------------------------------------ awakening ocarina
  mgr.registerWindow('pet_awake', {
    script: 'game2/pet/ui_awakewnd.txt',
    create(win) {
      const st = win.data.st = { pet: null, ocarina: null };
      acceptItem(sys, win.control('petsleepitem'), (inst) => {
        if (!isPetItem(inst)) return S(win, 126, 'It is not a pet item.');
        if (!stateOf(inst)?.sleep && !(inst.expiresAt && inst.expiresAt < Date.now())) return S(win, 151, 'Only sleeping pets can be registered.');
        return true;
      }, (inst) => { st.pet = inst; setSlot(sys, win.control('petsleepitem'), inst); });
      win.control('btn_confirm').onClick(async () => {
        if(online()){if(st.pet&&st.ocarina){const result=await send('petawake',{uid:st.pet.uid,ocarinaUid:st.ocarina.uid});if(result)win.close('ok');}return;}
        if (!st.pet || !st.ocarina) { sys.log(S(win, 159, 'Please select an item.'), 'err'); return; }
        const eternal = Number(itemDef(sys, st.ocarina)?.code) === 22;
        const file = eternal ? 'game2/msgbox/pet/ui_petinfinity.txt' : 'game2/msgbox/pet/ui_petawake.txt';
        const box = await mgr.create(file, { modal: true, disposeOnClose: true, remember: false });
        const r = await new Promise(res => { box.once('close', v => res(v)); box.control('btn_yes').onClick(() => box.close('yes')); box.control('btn_no').onClick(() => box.close('no')); mgr.openWindow(box); });
        if (r !== 'yes') return;
        const s = stateOf(st.pet);
        if (eternal && s.eternal) { sys.log(S(win, 147, 'You already used Eternal Ocarina.'), 'err'); return; }
        if (!removeInst(sys, st.ocarina, 1)) return;
        s.sleep = false;
        if (eternal) { s.eternal = true; delete st.pet.expiresAt; }
        else {
          const days = Number(itemDef(sys, st.ocarina)?.value1) || 30;
          st.pet.expiresAt = Date.now() + days * 86400000;
        }
        s.name = ''; s.named = false;                 // "You may reset the name of pet that has been awakened."
        g.items?.changed?.('equip:petawake');
        win.close('ok');
      });
      win.control('btn_cancel').onClick(() => win.close('cancel'));
    },
    onOpen(win, arg) {
      const st = win.data.st;
      st.ocarina = arg?.ocarina || null;
      st.pet = null;
      setSlot(sys, win.control('petsleepitem'), null);
      win.control('lbl_title').setText(Number(itemDef(sys, st.ocarina)?.code) === 22 ? S(win, 80, 'Ocarina of Eternity') : S(win, 52, 'Ocarina of Awakening'));
    },
  });

  // ------------------------------------------------------------------ split a pet inventory stack
  mgr.registerWindow('pet_stackdivide', {
    script: 'game2/pet/ui_petstackdivide.txt',
    modal: true,
    create(win) {
      win.control('btn_confirm').onClick(() => {
        const it = win.data.item, s = pets.state();
        const n = Math.floor(Number(win.control('edit_text').getValue?.()) || 0);
        if (!it || !s) { win.close(); return; }
        if(online()){const spot=win.data.at||pets.freeSpot(s,it.w||1,it.h||1);if(spot)void send('petinventory',{operation:'split',uid:it.uid,count:n,x:spot.x,y:spot.y}).then(result=>{if(result)win.close('ok')});return;}
        if (it.count <= 1) { sys.log(S(win, 77, 'You cannot divide the selected item.'), 'err'); return; }
        if (n <= 0 || n >= it.count) { sys.log(S(win, 78, 'You have exceeded the maximum number of\ndivision for this item.'), 'err'); return; }
        // the cell it was dropped on when that is free, else the first free place
        const w = it.w || 1, h = it.h || 1, at = win.data.at;
        const free = at && !s.inv.some(o => at.x < o.x + (o.w || 1) && at.x + w > o.x && at.y < o.y + (o.h || 1) && at.y + h > o.y);
        const spot = free ? at : pets.freeSpot(s, w, h);
        if (!spot) { sys.log(S(win, 128, 'Pet inventory space is insufficient.'), 'err'); return; }
        it.count -= n;
        s.inv.push({ ...it, count: n, x: spot.x, y: spot.y });
        win.close('ok');
        mgr.window('petinfo')?.data?.refresh?.();
      });
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      win.control('edit_text').on?.('enter', () => win.control('btn_confirm').emit?.('click'));
    },
    onOpen(win, arg) {
      win.data.item = arg?.item || null;
      win.data.at = arg?.at || null;
      const e = win.control('edit_text');
      e.setValue?.('1');
      setTimeout(() => { e.focus?.(); e.el?.querySelector?.('input')?.select?.(); }, 0);
    },
  });

  // ------------------------------------------------------------------ hatch alarm (HUD button while a pet egg is in the bag)
  mgr.registerWindow('pet_callalarm', {
    script: 'game2/pet/ui_petcallalarmwnd.txt', hud: true, remember: false, escClose: false,
    create(win) {
      // the egg's own use asks "Would you like to hatch the egg?" (boxes system, game2/msgbox/ui_hatch.txt)
      win.control('btn_alarm').onClick(() => { const egg = findByKind(sys, 0, 59, true); if (egg) g.items?.use?.(egg); });
      win.control('btn_alarm').setTooltip(() => S(win, 37, 'Hatch'));
    },
    update(win, dt) {
      win.data._t = (win.data._t || 0) + dt;
      if (win.data._t < 0.5) return;
      win.data._t = 0;
      const on = !!findByKind(sys, 0, 59, true);
      const b = win.control('btn_alarm');
      if (b.isVisible() !== on) { b.setVisible(on).setEnabled(on); b.setBlink?.(on, 500); }   // script: enable false
    },
  });
  // a HUD piece: always open (the button shows itself while an unhatched egg is in the bag)
  setTimeout(() => { mgr.open('pet_callalarm').catch?.(() => {}); }, 0);

  // pet items hovered in the bag show the 3D preview window beside the pointer (game2/pet/ui_petpreviewwnd.txt)
  const hookBag = (win) => {
    if (win?.name !== 'inventory' || win.data.__mountsPreview) return;
    const bag = win.find('slotbag');
    if (!bag) return;
    win.data.__mountsPreview = true;
    bag.on('cellover', (cell, item, e) => {
      const idx = idxOf(item?.data);
      if (!idx || !data.isPet(idx)) { if (mgr.isOpen('pet_preview')) mgr.close('pet_preview'); return; }
      const p = mgr.toLayer(e?.clientX ?? 0, e?.clientY ?? 0);
      mgr.open('pet_preview', { item: idx, x: Math.max(0, p.x - 66 - 24), y: Math.max(0, p.y - 40) });
    });
    bag.on('cellout', () => { if (mgr.isOpen('pet_preview')) mgr.close('pet_preview'); });
  };
  hookBag(mgr.window('inventory'));                          // the items system may have built it already
  mgr.on('create', hookBag);

  // ------------------------------------------------------------------ pet preview (hovering a pet item)
  mgr.registerWindow('pet_preview', {
    script: 'game2/pet/ui_petpreviewwnd.txt', remember: false, escClose: true,
    create(win) { win.data.preview = new ModelPreview(sys, win.control('pan_bg'), { w: 66, h: 97 }); },
    onOpen(win, arg) {
      const idx = idxOf(arg?.item);
      const p = data.pet(idx);
      if (!p) { win.close(); return; }
      if (win.data.item !== idx) {
        win.data.item = idx;
        const look = (arg?.shape && data.pet(arg.shape)) || p;
        win.data.preview.showModel({ mesh: look.mesh, tpack: look.tpack, textures: look.textures, skel: look.kind === 'pet' ? look.table?.skel : look.skel,
          anim: look.kind === 'pet' ? data.anim(look.table?.rows?.find(r => r[1] === 1)?.[3]) : look.stand?.[0], timeLength: 1 });
      }
      if (arg?.x != null) win.setPosition(arg.x, arg.y, false);
      win.el.style.pointerEvents = 'none';                  // never under the pointer's way (hover preview)
    },
    onClose(win) { win.data.item = null; win.data.preview.clear(); },
  });

  registerPetTransform(sys, { S, stateOf, isPetItem, same });

  // ------------------------------------------------------------------ item uses: ocarinas, pet name change
  const wrapUse = () => {
    const it = g.items;
    if (!it || it.__mountsUse || typeof it.use !== 'function') return !!it?.__mountsUse;
    it.__mountsUse = true;
    const use = it.use;
    it.use = function (inst, ...rest) {
      const def = this.def?.(inst?.itemIndex);
      if (def && Number(def.type) === 0) {
        const c = Number(def.code);
        if (c === 21 || c === 22) { mgr.open('pet_awake', { ocarina: inst }); return Promise.resolve(false); }
        if (c === 33) {
          const s = pets.state();
          if (!pets.equipped()) { sys.log(S(null, 61, 'Pet items are not installed.'), 'err'); return Promise.resolve(false); }
          if (!s.named) { mgr.open('pet_name'); return Promise.resolve(false); }
          s.named = false; s.name = '';
          removeInst(sys, inst, 1);
          mgr.open('pet_name');
          return Promise.resolve(true);
        }
      }
      return use.call(this, inst, ...rest);
    };
    return true;
  };
  if (!wrapUse()) { const t = setInterval(() => { if (wrapUse()) clearInterval(t); }, 1000); }

  // ------------------------------------------------------------------ pet inventory item dragged into the bag
  // (the items system's bag drop routes foreign payloads through receiveInBag; a chained, instance-level wrapper)
  const petToBag = (item, page, x, y) => {
    const it = g.items, s = pets.state();
    if (!it?.bag || !s || !s.inv.includes(item)) return false;
    const inst = { ...item };
    delete inst.x; delete inst.y; delete inst.w; delete inst.h;
    const r = it.bag.placeAt(inst, page, x, y);
    if (!r) return false;
    if (r === 'partial') item.count = inst.count;            // the rest stays in the pet inventory
    else s.inv = s.inv.filter(i => i !== item);
    it.changed('move');
    g.events?.emit('petinventory', { reason: 'tobag' });
    return true;
  };
  const wrapReceive = () => {
    const it = g.items;
    if (!it || it.__mountsReceive || typeof it.receiveInBag !== 'function') return !!it?.__mountsReceive;
    it.__mountsReceive = true;
    const orig = it.receiveInBag;
    it.receiveInBag = function (d, page, x, y) {
      if (d?.from === 'pet' && d.petItem) return online()?Promise.resolve(send('petinventory',{operation:'withdraw',uid:d.petItem.uid,...(page==null?{}:{page,x,y})})).then(Boolean):petToBag(d.petItem, page, x, y);
      return orig.call(this, d, page, x, y);
    };
    return true;
  };
  if (!wrapReceive()) { const t = setInterval(() => { if (wrapReceive()) clearInterval(t); }, 1000); }
}

/** First bag item of a kind (type/code), or its index. */
function findByKind(sys, type, code, inst = false) {
  const it = sys.game.items;
  const list = it?.bag?.list || it?.inv?.list || [];
  for (const x of list) {
    const d = it.def?.(x.itemIndex);
    if (d && Number(d.type) === type && Number(d.code) === code) return inst ? x : x.itemIndex;
  }
  return null;
}

// ============================================================================================ pet transform (NPC 163)
function registerPetTransform(sys, { S, stateOf, isPetItem, same }) {
  const g = sys.game, mgr = g.uiwin, data = sys.data, pets = sys.pet;
  const online=()=>g.save?.authority==='server';
  const rowsShape = () => sys.data.ui?.petTables?.shapeChange || [];
  const nav = (win) => {
    win.control('btn_shapechange').onClick(() => { if (win.name !== 'pet_shapechange') { win.close(); mgr.open('pet_shapechange'); } });
    win.control('btn_disassemble').onClick(() => { if (win.name !== 'pet_disassemble') { win.close(); mgr.open('pet_disassemble'); } });
    win.control('btn_restore').onClick(() => { if (win.name !== 'pet_shaperestore') { win.close(); mgr.open('pet_shaperestore'); } });
    win.control('btn_shapechange').setChecked(win.name === 'pet_shapechange');
    win.control('btn_disassemble').setChecked(win.name === 'pet_disassemble');
    win.control('btn_restore').setChecked(win.name === 'pet_shaperestore');
  };
  const money = (win, cost, idUse = 'lbl_usemoney', idMine = 'lbl_mymoney') => { win.control(idUse).setText(fmt(cost)); win.control(idMine).setText(fmt(dil(sys))); };
  // pan_effect_bg (layer 1000, the "black" sprite with pan_mark in its centre) is the preview's black backdrop; the
  // applied change fades the model in again on it
  const flash = (win, ms = 1200) => win.data.preview?.fadeIn(ms);
  const petModel = (idx) => { const p = data.pet(idx); return p ? { mesh: p.mesh, tpack: p.tpack, textures: p.textures, skel: p.kind === 'pet' ? p.table?.skel : p.skel, anim: p.kind === 'pet' ? data.anim(p.table?.rows?.find(r => r[1] === 1)?.[3]) : p.stand?.[0], timeLength: 1 } : null; };

  mgr.registerWindow('pet_shapechange', {
    script: 'game2/pet/ui_petshapechangewnd.txt',
    create(win) {
      const st = win.data.st = { pet: null, list: [], page: 0, pick: null };
      const preview = win.data.preview = new ModelPreview(sys, win.control('pan_preview_bg'), { w: 336, h: 336, cover: win.find('pan_effect_bg') });
      nav(win);
      const refresh = () => {
        setSlot(sys, win.control('item_pet'), st.pet);
        const row = st.pet ? rowsShape().find(r => r.item === idxOf(st.pet)) : null;
        st.list = row ? rowsShape().filter(r => r.grade === row.grade && r.item !== row.item && data.isPet(r.item)).map(r => r.item) : [];
        const pages = Math.max(1, Math.ceil(st.list.length / 10));
        st.page = Math.min(st.page, pages - 1);
        for (let i = 0; i < 10; i++) {
          const idx = st.list[st.page * 10 + i];
          setSlot(sys, win.control(`item_pet_${i}`), idx || null);
          win.control(`lbl_pet_${i}`).setText(idx ? itemName(sys, idx) : '');
        }
        win.control('lbl_page').setText(`${st.page + 1}/${pages}`);
        const selIdx = st.list.indexOf(st.pick) - st.page * 10;
        const fx = win.control('pan_selecteffect');
        if (st.pick && selIdx >= 0 && selIdx < 10) { const c = win.control(`item_pet_${selIdx}`), c0 = win.control('item_pet_0'); fx.move(fx.spec.rect?.[0] + c.box.x - c0.box.x, fx.spec.rect?.[1] + c.box.y - c0.box.y).show(); } else fx.hide();
        setSlot(sys, win.control('item_material'), row?.needItem || null);
        win.control('lbl_materailcount').setText(row ? `${countItem(sys, row.needItem)} / ${row.needCount}` : '');
        money(win, row?.dil || 0);
        win.control('lbl_preview').setText(st.pick ? itemName(sys, st.pick) : '');
        if (st.pick) preview.showModel(petModel(st.pick)); else preview.clear();
      };
      win.data.refresh = refresh;
      preview.bindButtons(win);
      acceptItem(sys, win.control('item_pet'), (inst) => {
        if (!isPetItem(inst)) return S(win, 126, 'It is not a pet item.');
        if (same(inst, pets.summoned ? pets.equipped()?.inst : null)) return sys.text('petBusy');
        if (!rowsShape().some(r => r.item === idxOf(inst))) return S(win, 126, 'It is not a pet item.');
        return true;
      }, (inst) => { st.pet = inst; st.pick = null; st.page = 0; refresh(); });
      win.control('item_pet').data.onClear = () => { st.pet = null; st.pick = null; refresh(); };
      for (let i = 0; i < 10; i++) win.control(`item_pet_${i}`).onClick(() => { const idx = st.list[st.page * 10 + i]; if (idx) { st.pick = idx; refresh(); } });
      win.control('btn_prev').onClick(() => { if (st.page > 0) { st.page--; refresh(); } });
      win.control('btn_next').onClick(() => { if ((st.page + 1) * 10 < st.list.length) { st.page++; refresh(); } });
      win.control('btn_ok').onClick(async () => {
        if(online()){g.network?.unavailable('Pet appearance change');return;}
        const row = st.pet ? rowsShape().find(r => r.item === idxOf(st.pet)) : null;
        if (!row || !st.pick) { sys.log(S(win, 159, 'Please select an item.'), 'err'); return; }
        if (countItem(sys, row.needItem) < row.needCount) { sys.log(`${itemName(sys, row.needItem)} x${row.needCount}`, 'err'); return; }
        if (dil(sys) < row.dil) { sys.log(S(win, 121, 'Insufficient deal.'), 'err'); return; }
        const r = await mgr.msgbox(`${itemName(sys, st.pet)} → ${itemName(sys, st.pick)}`, { kind: 'yesno', title: win.control('lbl_title').getText?.() || '' });
        if (r !== 'yes') return;
        if (!spendDil(sys, row.dil) || !removeItem(sys, row.needItem, row.needCount)) return;
        stateOf(st.pet).shape = st.pick;
        flash(win);
        sys.log(`${itemName(sys, st.pet)}: ${itemName(sys, st.pick)}`, 'sys');
        if (pets.summoned && same(st.pet, pets.equipped()?.inst)) { pets.despawn(); pets.summon(); }
        refresh();
      });
    },
    onOpen(win) { win.data.refresh(); },
    update(win, dt) { win.data.preview?.tick(dt); },
    onClose(win) { win.data.st.pet = null; win.data.st.pick = null; },
  });

  mgr.registerWindow('pet_shaperestore', {
    script: 'game2/pet/ui_petshaperestorewnd.txt',
    create(win) {
      const st = win.data.st = { pet: null };
      const preview = win.data.preview = new ModelPreview(sys, win.control('pan_preview_bg'), { w: 336, h: 336, cover: win.find('pan_effect_bg') });
      nav(win);
      preview.bindButtons(win);
      const refresh = () => {
        setSlot(sys, win.control('item_pet'), st.pet);
        const s = stateOf(st.pet);
        const row = st.pet ? rowsShape().find(r => r.item === idxOf(st.pet)) : null;
        setSlot(sys, win.control('item_restore'), st.pet && s?.shape ? idxOf(st.pet) : null);
        setSlot(sys, win.control('item_material'), row?.resetItem || null);
        win.control('lbl_materailcount').setText(row ? `${countItem(sys, row.resetItem)} / ${row.resetCount}` : '');
        money(win, row?.resetDil || 0);
        win.control('lbl_preview').setText(st.pet ? itemName(sys, st.pet) : '');
        if (st.pet) preview.showModel(petModel(idxOf(st.pet))); else preview.clear();
      };
      win.data.refresh = refresh;
      acceptItem(sys, win.control('item_pet'), (inst) => (isPetItem(inst) && stateOf(inst)?.shape ? true : S(win, 126, 'It is not a pet item.')), (inst) => { st.pet = inst; refresh(); });
      win.control('item_pet').data.onClear = () => { st.pet = null; refresh(); };
      win.control('btn_ok').onClick(async () => {
        if(online()){g.network?.unavailable('Pet disassembly');return;}
        const s = stateOf(st.pet);
        const row = st.pet ? rowsShape().find(r => r.item === idxOf(st.pet)) : null;
        if (!s?.shape || !row) { sys.log(S(win, 159, 'Please select an item.'), 'err'); return; }
        if (countItem(sys, row.resetItem) < row.resetCount) { sys.log(`${itemName(sys, row.resetItem)} x${row.resetCount}`, 'err'); return; }
        if (dil(sys) < row.resetDil) { sys.log(S(win, 121, 'Insufficient deal.'), 'err'); return; }
        if (!spendDil(sys, row.resetDil) || !removeItem(sys, row.resetItem, row.resetCount)) return;
        delete s.shape;
        flash(win);
        if (pets.summoned && same(st.pet, pets.equipped()?.inst)) { pets.despawn(); pets.summon(); }
        refresh();
      });
    },
    onOpen(win) { win.data.refresh(); },
    update(win, dt) { win.data.preview?.tick(dt); },
    onClose(win) { win.data.st.pet = null; },
  });

  mgr.registerWindow('pet_disassemble', {
    script: 'game2/pet/ui_petdisassemblewnd.txt',
    create(win) {
      const st = win.data.st = { pick: null };
      nav(win);
      const grid = win.control('petlist');
      const rows = () => sys.data.ui?.petTables?.disassemble || [];
      const refresh = () => {
        const list = (g.items?.bag?.list || []).filter(x => rows().some(r => r.item === x.itemIndex));
        grid.setItems(list.map((inst, i) => {
          const e = { x: i % grid.cols, y: Math.floor(i / grid.cols), w: 1, h: 1, data: inst, icon: null, color: st.pick === inst ? '#fdb602' : null };
          iconOf(sys, inst, grid.cw, grid.ch).then(ic => { e.icon = ic; grid.render(); });
          return e;
        }));
        const r = st.pick ? rows().find(x => x.item === st.pick.itemIndex) : null;
        win.control('lbl_money').setText(r ? fmt(r.dil) : '');
        win.control('lbl_info').setText(r ? `${itemName(sys, r.out)} x${r.count}` : '');
      };
      win.data.refresh = refresh;
      grid.setItemTooltip(it => (g.items?.tooltip ? g.items.tooltip(it.data) : itemName(sys, it.data)));
      grid.on('cellclick', (c, it) => { st.pick = it?.data || null; refresh(); });
      win.control('btn_ok').onClick(async () => {
        if(online()){g.network?.unavailable('Pet appearance restoration');return;}
        const r = st.pick ? rows().find(x => x.item === st.pick.itemIndex) : null;
        if (!r) { sys.log(S(win, 159, 'Please select an item.'), 'err'); return; }
        if (dil(sys) < r.dil) { sys.log(S(win, 121, 'Insufficient deal.'), 'err'); return; }
        const ok = await mgr.msgbox(win.control('lbl_warning').getText?.() || '', { kind: 'yesno', title: win.control('lbl_title').getText?.() || '' });
        if (ok !== 'yes') return;
        if (!spendDil(sys, r.dil) || !removeInst(sys, st.pick, 1)) return;
        addItem(sys, r.out, r.count, { source: 'petdisassemble' });
        st.pick = null;
        refresh();
      });
      g.events?.on?.('inventory', () => { if (win.isOpen) refresh(); });
    },
    onOpen(win) { win.data.refresh(); },
  });
}
