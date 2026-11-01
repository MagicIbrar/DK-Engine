import {beltEntry,beltEligible} from '../items/belt.js';
import {itemSwapResult,itemPayload,cursorActionResult} from '../items/ui/common.js';
// Skill quick slots (script/ui/game2/mainbar/ui_quickslotwnd.txt) and the potion belt (ui_itembeltwnd.txt).
//
// Behaviour from the client's own guide (guide_info_system 1302:2, stringtable_helper 1106, tooltip 23:60):
//   * 3 sets of 12 slots ("dozen" rows built from the pan_dozen / slot / slot_label templates, 44 px cells).
//   * com_dozen (opened by the setting button beside the lock) unfolds 1..3 rows.
//   * the lock (newMainbar#70-72 locked / #73-75 open, 231:4-8) protects existing shortcuts from removal/rearrangement;
//     learned active skills copied from the skill page may fill empty slots.
//   * each row's number button (btn_exist) is blue (moves with Z/X) or red (keeps its set); Z / X and the up/down
//     arrows rotate the sets through the blue rows (only when more than one row is unfolded). lbl_slotNum = the set.
//   * keys: row 1 = "Skill Slot 1" keys (1..0, -, =), rows 2/3 = their own key categories (unbound by default).
//   * control type A: the slot key selects the skill (slot highlight) and a right click uses it; B: the key uses it.
//   * potion belt: F1..F10 on 10 item cells.
// Save: save.quickslot = { sets:[[12]x3], rows, rowSet:[3], fixed:[3], locked, belt:[10] }; save.hotbar mirrors the
// set of the bottom row (skills.use(slot) / older code keep working).
import { skillMap, skillLevel, skillMpCost } from '../../ui/gameinfo.js';
import { keyName, bindingName } from './keymap.js';
import { str, fmtInt } from './util.js';
import {skillTooltip} from '../skills/ui-skillwnd.js';
import {skillWeaponCompatible} from '../skills/skill-weapon.js';
import {itemCooldownFraction} from '../../ui/cooldown.js';

// A separate presentation layer: it never owns input, icon color or cooldown wedges.
export function paintSelectedSkill(cell, selected) {
  if (cell.selectedPulse === selected) return;
  cell.selectedPulse = selected;
  if (selected && !cell.selectionRing) {
    if (!document.getElementById('dk-selected-skill-pulse-style')) {
      const css = document.createElement('style'); css.id = 'dk-selected-skill-pulse-style';
      css.textContent = '@keyframes dk-selected-skill-pulse{0%,100%{opacity:.08}50%{opacity:.4}}.dk-selected-skill-pulse{position:absolute;left:2px;top:4px;width:40px;height:40px;background:radial-gradient(ellipse at center,rgba(210,214,220,.7),rgba(170,176,184,.3) 50%,transparent 76%);pointer-events:none;z-index:6;animation:dk-selected-skill-pulse 1.2s ease-in-out infinite}@media(prefers-reduced-motion:reduce){.dk-selected-skill-pulse{animation:none;opacity:.24}}';
      document.head.append(css);
    }
    cell.selectionRing = document.createElement('div'); cell.selectionRing.className = 'dk-selected-skill-pulse';
    cell.selectionRing.setAttribute('aria-hidden', 'true'); cell.slot.el.append(cell.selectionRing);
  }
  if (cell.selectionRing) cell.selectionRing.hidden = !selected;
}

export function quickSkillTooltip(game,index){
  const engine=game.skills,skill=engine?.skillDef?.(Number(index));if(!skill)return null;
  const tip=skillTooltip(engine,skill),state=engine.usability?.(skill.index);
  if(state?.ok===false){
    const reasons={mp:'Not enough MP',hp:'Not enough HP',fury:'Not enough Rage',weapon:'Required weapon is not equipped',cooldown:'Skill is cooling down',stage:'Required Trans Up stage is not active',silenced:'An active status prevents skill use',dead:'Character is dead',mounted:'Cannot use while mounted',unlearned:'Skill is not learned'};
    const text=reasons[state.reason]||'Skill is unavailable';
    if(!tip.lines.some(line=>String(line.text||'').replace(/<[^>]+>/g,'').trim()===text))tip.lines.push({text,color:'#ff6060'});
  }
  return tip;
}

// Learned icons retain colour when short on MP; weapon/TransUp mismatch greys the bar.
export function quickSkillIconFilter(game, skill) {
  const learned = typeof game.skills?.learnedLevel === 'function'
    ? Number(game.skills.learnedLevel(skill.index)) : skillLevel(game, skill);
  const engine = game.skills;
  // UI skillMap entries omit native weapon styles; resolve the cast definition.
  const nativeSkill = engine?.skillDef?.(Number(skill.index)) || skill;
  const weaponReady = typeof engine?.equippedStyle === 'function'
    ? skillWeaponCompatible(nativeSkill, engine.equippedStyle())
    : engine?.usability?.(skill.index)?.reason !== 'weapon';
  const requiredStage = Number(nativeSkill.awakeningCheck) || 0;
  const stageReady = requiredStage <= (Number(game.player?.transUpStage) || 0);
  return learned > 0 && weaponReady && stageReady ? '' : 'grayscale(1) brightness(.5)';
}

const SLOTS = 12;
const CELL = 44;
const ROW_H = 48;

// Shortcut references stay in the saved layout until a drop succeeds, but the
// carried icon must not also remain painted in its source slot.
function heldVisibility(el, held) {
  if (!el) return;
  const value = held ? 'hidden' : '';
  if (el.style.visibility !== value) el.style.visibility = value;
}

// Native image requests follow slot meaning, not snapshot object identity.
export function refreshShortcutIcon(game, ctx, cell, current, paint, width, height, now = Date.now()) {
  const entry = current(), generation = game.items?.icons?.cache?.generation || 0;
  const index = entry?.type === 'item' ? Number(entry.itemIndex) : null;
  const key = index == null ? null : index + ':' + generation;
  let state = cell.itemImage;
  if (!state || state.key !== key) {
    state = cell.itemImage = { key, index, generation, attempts: 0, pending: false, ready: false, retryAt: 0 };
    paint(null);
  }
  if (key == null || state.ready || state.pending || state.attempts >= 3 || now < state.retryAt) return;
  state.pending = true; state.attempts++;
  Promise.resolve().then(() => ctx.itemIcon(entry, width, height)).then(icon => {
    if (cell.itemImage !== state || Number(current()?.itemIndex) !== index || (game.items?.icons?.cache?.generation || 0) !== generation) return;
    if (icon) { state.ready = true; paint(icon); }
  }).catch(() => {}).finally(() => { state.pending = false; state.retryAt = now + 1100; });
}

export function quickState(game) {
  const s = game.save;
  if (!s) return null;
  let q = s.quickslot;
  if (!q || !Array.isArray(q.sets)) {
    const old = Array.isArray(s.hotbar) ? s.hotbar : [];
    const set0 = Array.from({ length: SLOTS }, (_, i) => old[i] || null);
    q = s.quickslot = {
      sets: [set0, Array(SLOTS).fill(null), Array(SLOTS).fill(null)],
      rows: 3, rowSet: [0, 1, 2], fixed: [false, false, false], locked: true,
      belt: Array(10).fill(null),
    };
    // potions that sat on the old bar move to the belt
    set0.forEach((e, i) => { if (e?.type === 'item') { const b = q.belt.indexOf(null); if (b >= 0) { q.belt[b] = e; set0[i] = null; } } });
  }
  for (const set of q.sets) while (set.length < SLOTS) set.push(null);
  while (q.belt.length < 10) q.belt.push(null);
  s.hotbar = q.sets[q.rowSet[0]];
  return q;
}

/** Normalise a drag payload / picked thing into a slot entry, or null. */
export function entryFrom(data) {
  if (!data) return null;
  if (data.from === 'quickslot' || data.from === 'belt') return data.entry || null;
  const sk = data.skill?.index ?? data.skillIndex ?? (data.type === 'skill' ? data.index : null);
  if (sk != null) return { type: 'skill', index: Number(sk) };
  const it = data.item || (data.type === 'item' ? data : null) || (data.itemIndex != null ? data : null);
  if (it && (it.itemIndex != null || it.index != null)) return { type: 'item', itemIndex: Number(it.itemIndex ?? it.index), uid: it.uid, name: it.name };
  return null;
}

export function registerQuickSlots(game, ctx) {
  const sfx = (k) => game.audio?.ui?.(k);
  const shortcutPayload = (set, index, entry, icon) => ({
    data: { from: 'quickslot', set, slot: index, entry },
    icon, size: [40, 40],
    canRetain: () => quickState(game)?.sets?.[set]?.[index] === entry,
    onDropOutside() {
      if (quickState(game)?.sets?.[set]?.[index] !== entry) return false;
      ctx.quick.set(set, index, null);
      sfx('buttonCommon');
      return true;
    },
  });

  // ------------------------------------------------------------------ skill quick slots
  game.uiwin.registerWindow('hud_quickslot', {
    hud: true, escClose: false, script: 'game2/mainbar/ui_quickslotwnd.txt',
    create(win) {
      const d = win.data;
      const bg = win.control('pan_bg');
      d.rows = [];
      d.cells = [];
      for (let r = 0; r < 3; r++) {
        const y = 96 - r * ROW_H;
        const dozen = win.control('pan_dozen').cloneAs(`_${r}`, { x: 0, y, parent: bg });
        const exist = win.control(`btn_exist_${r}`);
        exist.onClick(() => toggleFixed(r));
        const cells = [];
        for (let i = 0; i < SLOTS; i++) {
          const slot = win.control('slot').cloneAs(`_${r}_${i}`, { x: 3 + i * CELL, y, parent: bg });
          const label = win.control('slot_label').cloneAs(`_${r}_${i}`, { x: 2 + i * CELL, y, parent: bg });
          const cell = { r, i, slot, label, grd: slot.children.find(c => /slot_grd/i.test(c.id)), skillPanel: slot.children.find(c => /slot_skill/i.test(c.id)), coolPanel: slot.children.find(c => /slot_cool/i.test(c.id)) };
          cell.setIcon = (icon) => (cell.skillPanel || slot).setIcon(icon);
          cell.setCool = (f) => (cell.coolPanel || slot).setCooldown(f);
          wireCell(cell);
          cells.push(cell);
        }
        d.rows.push({ dozen, exist, num: win.control(`lbl_slotNum_${r}`), cells });
        d.cells.push(...cells);
      }
      const combo = win.control('com_dozen');
      // The settings button opens this selector; row buttons already show their set numbers.
      if (combo.label) combo.label.style.visibility = 'hidden';
      combo.on('change', (i, it) => { const q = quickState(game); if (!q) return; q.rows = Math.max(1, Math.min(3, Number(it?.value) || 1)); layoutRows(); ctx.quick.changed(); });
      win.control('btn_setting').onClick(() => {
        combo.openList();
      });
      win.control('btn_setting').setTooltip('Show 1, 2 or 3 skill rows');
      win.control('btn_lock').onClick(() => {
        const q = quickState(game); if (!q) return;
        q.locked = !q.locked;
        ctx.quick.changed();
        paintLock();
        ctx.chat?.system(str(231, q.locked ? 4 : 5));
      });
      win.control('btn_slot_up').onClick(() => rotate(1));
      win.control('btn_slot_down').onClick(() => rotate(-1));
      d.layoutRows = layoutRows;
      d.paintLock = paintLock;
      d.refreshKeys = refreshKeys;
      ctx.keymap.on('change', () => refreshKeys());
      game.events?.on?.('options', ({ changed }) => { if ('controlType' in changed) paintControlType(); });

      function layoutRows() {
        const q = quickState(game); if (!q) return;
        d.rows.forEach((row, r) => {
          const on = r < q.rows;
          row.dozen.setVisible(on);
          for (const c of row.cells) { c.slot.setVisible(on); c.label.setVisible(on); }
        });
        combo.selectValue(q.rows);
        combo.setRect(549, 96 - (q.rows - 1) * ROW_H, 19, 48);
        paintRows();
        d.sig = '';
      }
      function paintRows() {
        const q = quickState(game); if (!q) return;
        d.rows.forEach((row, r) => {
          row.num.setText(String(q.rowSet[r] + 1));
          row.exist.setChecked(!q.fixed[r]);
        });
      }
      function paintLock() {
        const q = quickState(game); if (!q) return;
        const b = win.control('btn_lock');
        if (q.locked) { b.setImage('none', 'newMainbar', 70); b.setImage('down', 'newMainbar', 71); b.setImage('over', 'newMainbar', 72); }
        else { b.setImage('none', 'newMainbar', 73); b.setImage('down', 'newMainbar', 74); b.setImage('over', 'newMainbar', 75); }
        b.setTooltip(str(231, q.locked ? 7 : 8));
        // The lock protects skill placement; viewing fewer rows is always available.
        win.control('btn_setting').setEnabled(true);
      }
      function paintControlType() { win.control('lbl_controltype').setText(ctx.options.get('controlType') === 0 ? 'A' : 'B'); }
      function refreshKeys() {
        for (const c of d.cells) c.label.setText(keyShort(ctx.keymap.get(`slot${c.r}_${c.i}`)));
      }
      function toggleFixed(r) {
        const q = quickState(game); if (!q) return;
        if (q.locked) { ctx.chat?.system(str(231, 7)); return; }
        q.fixed[r] = !q.fixed[r];
        ctx.quick.changed();
        paintRows();
      }
      function rotate(dir) { ctx.quick.rotate(dir); }
      function wireCell(cell) {
        const { slot } = cell;
        slot.onClick(() => {
          const q = quickState(game);
          if (game.windows?.pickedSkill != null) {
            ctx.quick.set(q.rowSet[cell.r], cell.i, { type: 'skill', index: game.windows.pickedSkill });
            game.windows.pickedSkill = null; game.windows.refresh?.('skills'); sfx('buttonCommon');
            return;
          }
          ctx.quick.useCell(cell.r, cell.i);
        });
        slot.onRightClick(() => ctx.quick.useCell(cell.r, cell.i));
        slot.el.addEventListener('pointerenter', () => { cell.hover = true; paintCell(cell); });
        slot.el.addEventListener('pointerleave', () => { cell.hover = false; cell.down = false; paintCell(cell); });
        slot.el.addEventListener('pointerdown', () => { cell.down = true; paintCell(cell); });
        slot.el.addEventListener('pointerup', () => { cell.down = false; paintCell(cell); });
        slot.setTooltip(() => cellTip(cell));
        // Authored icon/overlay panels must not steal the slot's hover/drag target.
        const transparent=control=>{for(const child of control.children||[]){child.el.style.pointerEvents='none';transparent(child);}};
        transparent(slot);
        // drag out / between slots (uiwin drag-and-drop)
        slot.makeDraggable(() => {
          const q = quickState(game);
          const set = q.rowSet[cell.r];
          const e = q.sets[set][cell.i];
          if (!e) return null;
          if (q.locked) return null;
          return shortcutPayload(set, cell.i, e, (cell.skillPanel || slot).getIcon());
        });
        slot.acceptDrop({
          accept: (data) => !!entryFrom(data),
          drop: (data) => {
            const q = quickState(game);
            const set = q.rowSet[cell.r];
            const e = entryFrom(data);
            if (!e) return false;
            // Lock protects existing shortcuts, while a learned skill copied
            // from its page may fill an empty slot (matching quick.set).
            if (q.locked) {
              const skill = e.type === 'skill' && game.skills?.skillDef?.(e.index);
              const addSkill = data.from === 'skillwnd' && !q.sets[set][cell.i] && skill &&
                game.skills.learnedLevel(e.index) > 0 && !game.skills.isPassive(skill);
              if (!addSkill) {
                ctx.chat?.system('Unlock the skill bar to replace or move shortcuts.');
                const held = game.uiwin.dnd?.cur?.payload;
                return held ? { heldItem: held } : false;
              }
            }
            if (data.from === 'quickslot') {
              if (data.set === set && data.slot === cell.i) return true;
              const other = q.sets[data.set][data.slot];
              const displaced = q.sets[set][cell.i];
              const displacedIcon = (cell.skillPanel || slot).getIcon();
              q.sets[data.set][data.slot] = displaced;
              q.sets[set][cell.i] = other;
              ctx.quick.changed();
              sfx('buttonCommon');
              return displaced ? { heldItem: shortcutPayload(data.set, data.slot, displaced, displacedIcon) } : true;
            } else {
              if (data.from === 'belt' && !q.locked) { q.belt[data.slot] = null; }
              ctx.quick.set(set, cell.i, e);
            }
            sfx('buttonCommon');
            // This bar stores a shortcut, not the owned item. Keep real custody
            // on the mouse until the player places it in an owned container.
            if(data.from==='cursor')return cursorActionResult(game.items,true);
            return true;
          },
        });
        // the older CSS windows drag skills/items with HTML5 drag and drop
        slot.el.addEventListener('dragover', (ev) => ev.preventDefault());
        slot.el.addEventListener('drop', (ev) => {
          ev.preventDefault();
          const dt = ev.dataTransfer;
          const q = quickState(game);
          const set = q.rowSet[cell.r];
          const sk = dt?.getData('application/x-dk-skill');
          const it = dt?.getData('application/x-dk-item');
          if (sk) ctx.quick.set(set, cell.i, { type: 'skill', index: Number(sk) });
          else if (it) { try { const o = JSON.parse(it); ctx.quick.set(set, cell.i, { type: 'item', itemIndex: Number(o.itemIndex), name: o.name }); } catch { /* ignore */ } }
        });
      }
      function paintCell(cell) {
        const q = quickState(game), entry = q?.sets[q.rowSet[cell.r]]?.[cell.i], selected = ctx.quick.selected;
        const active = !!selected && selected.r === cell.r && selected.i === cell.i && selected.set === q?.rowSet[cell.r] && entry?.type === 'skill' && Number(entry.index) === selected.index;
        paintSelectedSkill(cell, active);
        const armed = !active && ctx.quick.armed && ctx.quick.armed.r === cell.r && ctx.quick.armed.i === cell.i;
        const idx = armed ? (cell.down ? 126 : cell.hover ? 125 : 124) : cell.down ? 123 : cell.hover ? 122 : null;
        if (cell.grdIdx === idx) return;
        cell.grdIdx = idx;
        if (idx == null) cell.grd?.setImage('none', null); else cell.grd?.setImage('none', 'newMainbar', idx);
      }
      d.paintCell = paintCell;
      function cellTip(cell) {
        const q = quickState(game);
        const e = q.sets[q.rowSet[cell.r]][cell.i];
        if (!e) return null;
        if (e.type === 'skill') {
          if(game.skills?.skillDef?.(Number(e.index)))return quickSkillTooltip(game,e.index);
          const sk = skillMap(game).get(Number(e.index));
          if (!sk) return null;
          const lv = skillLevel(game, sk);
          const lines = [`<color=f4be3d>${sk.name}</color>${lv > 0 ? `  Lv.${lv}` : ''}`];
          const mp = skillMpCost(sk, Math.max(1, lv));
          if (mp) lines.push(`MP ${fmtInt(mp)}`);
          if (sk.description) lines.push(sk.description);
          return lines.join('\n');
        }
        return `${ctx.itemName(e) || 'Item'}\nInventory shortcut - uses inventory stock`;
      }
      paintLock(); paintControlType(); refreshKeys(); layoutRows();
    },
    update(win, dt) {
      const d = win.data;
      const q = quickState(game);
      if (!q) return;
      const sig = JSON.stringify([q.sets, q.rowSet, q.rows, game.save?.level]);
      if (sig !== d.sig) { d.sig = sig; renderIcons(win); }
      for (const c of d.cells) {
        if (c.r >= q.rows) continue;
        const held = game.uiwin.dnd?.data;
        heldVisibility((c.skillPanel || c.slot)._icon,
          held?.from === 'quickslot' && held.set === q.rowSet[c.r] && held.slot === c.i);
        const e = q.sets[q.rowSet[c.r]][c.i];
        d.paintCell(c);
        if (!e) { if (c.cd) { c.setCool(0); c.cd = 0; } continue; }
        if (e.type === 'skill') {
          const sk = c.skill;
          if (!sk) continue;
          // Weapon requirements update with every frame; cooldown keeps its own sweep.
          const filt = quickSkillIconFilter(game, sk);
          if (c.filt !== filt) { c.filt = filt; if (c.skillPanel?.el) c.skillPanel.el.style.filter = filt; }
          let f = 0;
          try { f = Number(game.skills?.cooldownFraction?.(sk.index)) || 0; } catch { f = 0; }
          if ((f === 0 && c.cd) || Math.abs((c.cd || 0) - f) > 0.004) { c.cd = f; c.setCool(f); }
        } else if (e.type === 'item') {
          refreshShortcutIcon(game, ctx, c, () => quickState(game)?.sets[quickState(game).rowSet[c.r]]?.[c.i], c.setIcon, 40, 40);
          const n = ctx.itemCount(e);
          if (c.count !== n) { c.count = n; c.slot.setCount(n > 0 ? fmtInt(n) : '0'); if (c.skillPanel?.el) c.skillPanel.el.style.filter = n > 0 ? '' : 'grayscale(1) brightness(.5)'; }
          const f = itemCooldownFraction(game, e.itemIndex);
          if ((f === 0 && c.cd) || Math.abs((c.cd || 0) - f) > 0.004) { c.cd = f; c.setCool(f); }
        }
      }
    },
  });

  function renderIcons(win) {
    const q = quickState(game);
    const skills = skillMap(game);
    for (const c of win.data.cells) {
      const e = q.sets[q.rowSet[c.r]][c.i];
      c.skill = e?.type === 'skill' ? skills.get(Number(e.index)) || null : null;
      c.count = undefined; c.filt = undefined;
      if (c.skillPanel?.el) c.skillPanel.el.style.filter = '';
      c.slot.setCount('');
      if (!e) { c.itemImage = null; c.setIcon(null); continue; }
      if (c.skill) { c.itemImage = null; c.setIcon({ sprite: ['skill_icon', Number(c.skill.iconIndex ?? c.skill.index)] }); }
      else if (e.type === 'item') {
        refreshShortcutIcon(game, ctx, c, () => quickState(game)?.sets[quickState(game).rowSet[c.r]]?.[c.i], c.setIcon, 40, 40);
      } else c.setIcon(null);
    }
    win.data.paintRows?.();
    for (const row of win.data.rows) row.num.setText(String(q.rowSet[win.data.rows.indexOf(row)] + 1));
  }

  // ------------------------------------------------------------------ potion belt
  game.uiwin.registerWindow('hud_itembelt', {
    hud: true, escClose: false, script: 'game2/mainbar/ui_itembeltwnd.txt', movable: true,
    create(win) {
      // Use the authored horizontal placement. The former right-edge override
      // put the belt across the HP/MP bars at narrower desktop resolutions.
      // Repair overlapping old positions on placement, retaining other user drags.
      const place = win.place.bind(win);
      win.place = () => {
        place();
        const hp = game.uiwin.window('hud_hp');
        const panel = hp?.find?.('pan_bg');
        if (!hp?.isOpen || !panel) return win;
        const a = win.box, b = {x:hp.box.x + panel.box.x,y:hp.box.y + panel.box.y,w:panel.box.w,h:panel.box.h};
        if (a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y) {
          const userPosition = win._pos;
          win.setPosition(a.x, Math.max(0, b.y - a.h - 4), false);
          // A layout repair is not a user drag: keep bottom anchoring on resize.
          win._pos = userPosition;
        }
        return win;
      };
      const d = win.data;
      d.cells = [];
      for (let i = 0; i < 10; i++) {
        const item = win.control(`item${i}`);
        const cell = { i, item, key: win.control(`lbl_key${i}`), cnt: win.control(`lbl_item${i}`) };
        // Like inventory, left click picks up the owned stack; right click/F keys use it.
        item.onRightClick(() => ctx.quick.useBelt(i));
        item.setTooltip(() => { const e = beltEntry(game.save,i); return e ? `${ctx.itemName(e) || 'Item'}\nStored in potion belt` : null; });
        item.makeDraggable(() => {
          const e = beltEntry(game.save,i);
          if (!e) return null;
          if(game.items?.cursorPickup)return {...itemPayload(game.items,e,'belt',{slot:i},[32,32]),icon:item.getIcon()};
          return { data: { kind:'item', from:'belt', slot:i, entry:e, inst:e, uid:e.uid, itemIndex:e.itemIndex }, canRetain:()=>beltEntry(game.save,i)?.uid===e.uid, icon: item.getIcon(), count:e.count, size: [32, 32], onDropOutside() { return false; } };
        });
        item.acceptDrop({
          accept:data=>['cursor','bag','belt'].includes(data.from)&&!!(data.inst||data.entry)?.uid&&beltEligible(game.items?.db?.def((data.inst||data.entry).itemIndex)),
          drop:data=>{
            if(data.from==='cursor')return cursorActionResult(game.items,game.items.cursorPlace('belt',{page:0,x:i,y:0,targetUid:beltEntry(game.save,i)?.uid??null}));
            const owned=data.inst||data.entry;if(!owned?.uid)return false;
            const displaced=beltEntry(game.save,i)?.uid;
            return Promise.resolve(itemSwapResult(game.items,data.from==='belt'?game.items?.beltMove?.(owned,i):game.items?.beltDeposit?.(owned,i),data,displaced))
              .then(result=>{if(result)sfx('buttonCommon');return result;});
          },
        });
        d.cells.push(cell);
      }
      const keys = () => d.cells.forEach(c => c.key.setText(keyShort(ctx.keymap.get(`belt${c.i}`))));
      keys();
      ctx.keymap.on('change', keys);
    },
    update(win) {
      const q = quickState(game);
      if (!q) return;
      const d = win.data;
      const sig = JSON.stringify(game.save?.potionBelt||[]);
      if (d.sig !== sig) {
        d.sig = sig;
        for (const c of d.cells) {
          const e = beltEntry(game.save,c.i);
          c.count = undefined;
          refreshShortcutIcon(game, ctx, c, () => beltEntry(game.save,c.i), icon => c.item.setIcon(icon), 33, 33);
        }
      }
      for (const c of d.cells) {
        refreshShortcutIcon(game, ctx, c, () => beltEntry(game.save,c.i), icon => c.item.setIcon(icon), 33, 33);
        const held = game.uiwin.dnd?.data;
        const carrying = held?.from === 'belt' && held.slot === c.i;
        heldVisibility(c.item._icon, carrying);
        heldVisibility(c.cnt.el, carrying);
        const e = beltEntry(game.save,c.i);
        const n = e ? ctx.itemCount({itemIndex:e.itemIndex}) : null;
        if (c.count !== n) { c.count = n; c.cnt.setText(n == null ? '' : String(n)); if (c.item._icon) c.item._icon.style.filter = n === 0 ? 'grayscale(1) brightness(.5)' : ''; }
        if (e) {
          c.item.setCooldown(itemCooldownFraction(game, e.itemIndex));
        } else c.item.setCooldown(0);
      }
    },
  });
}

/** Compact key caption for a slot label ('1', 'F1', 'Ctrl+1'). */
function keyShort(spec) {
  if (!spec) return '';
  const name = bindingName(spec);
  return name.replace(/\s\+\s/g, '+').replace(/^Ctrl\+/, 'C+').replace(/^Shift\+/, 'S+').replace(/^Alt\+/, 'A+');
}
export { keyShort, keyName };
