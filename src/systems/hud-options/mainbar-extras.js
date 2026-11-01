// Mainbar extras: ui_monsterquickslotwnd (hud_monsterquickslot) + the monster body of a transformed player,
// ui_spellcountwnd (hud_spellcount) and ui_upkeepstatuswnd (hud_upkeep). Rules: ./mainbar-extras-rules.js,
// ENGINE-CHOSEN values: src/config/engine-chosen-mainbar.js.
import { fetchCSV, fetchJSON } from '../../engine/assets.js';
import { Monster } from '../../actors/monster.js';
import { statusRemaining } from '../../ui/cooldown.js';
import { MAINBAR_ENGINE_CHOSEN as CFG } from '../../config/engine-chosen-mainbar.js';
import { parseChangeMonster, transformOf, monsterFormState, spellCounts, upkeepStatuses } from './mainbar-extras-rules.js';
import { statusKind, statusTip, statusIcon } from './hudwins.js';

const HUD = { hud: true, remember: false, escClose: false };

export function installMainbarExtras(game, ctx) {
  const ex = { table: new Map(), statusTable: null, forms: new Map() };
  ctx.mainbarExtras = ex;
  game.mainbarExtras = ex;
  ex.ready = Promise.all([
    fetchCSV('share/change_monster.csv').then(rows => { ex.table = parseChangeMonster(rows); }).catch(err => console.warn('[mainbar] change_monster.csv', err)),
    fetchJSON('/gamedata/skills_status.json').then(j => { ex.statusTable = j?.statuses || null; }).catch(() => {}),
  ]);
  ex.defOf = idx => game.skills?.data?.status?.(idx) || ex.statusTable?.[idx] || null;
  const own = () => (game.network?.active ? game.save?.buffs : game.player?.statuses?.length ? game.player.statuses : game.save?.buffs) || [];
  const alive = list => list.filter(s => s && !(statusRemaining(game, s) <= 0));
  ex.entriesOf = actor => (actor === game.player ? alive(own()) : actor?._skillStatusVisuals || actor?.statuses || []);
  ex.transform = () => transformOf(ex.entriesOf(game.player), ex.defOf, ex.table);

  // ------------------------------------------------------------------ spell count
  game.uiwin.registerWindow('hud_spellcount', {
    ...HUD, script: 'game2/mainbar/ui_spellcountwnd.txt',
    update(win) {
      const c = spellCounts(ex.entriesOf(game.player), ex.defOf, s => statusKind(s) === 'debuff');
      const d = win.data;
      for (const [side, list, n] of [['attack', c.attackList, c.attack], ['defense', c.defenseList, c.defense]]) {
        const sig = `${n}:${list.map(s => s.key ?? s.statusIndex).join(',')}`;
        if (d[side] === sig) continue;
        d[side] = sig;
        const pan = win.control(`pan_${side}`);
        pan.setVisible(n > 0);
        win.control(`lbl_${side}`).setText(n > 0 ? String(n) : '');
        const names = list.map(s => s.name || s.description || 'Status');
        pan.setTooltip(n > 0 ? names.join('\n') : '');
      }
    },
  });

  // ------------------------------------------------------------------ upkeep status
  game.uiwin.registerWindow('hud_upkeep', {
    ...HUD, script: 'game2/mainbar/ui_upkeepstatuswnd.txt',
    create(win) {
      win.data.slots = [];
      for (let i = 0; i < CFG.upkeep.maxIcons; i++) {
        const c = win.control(`btn_upkeepstatus_${i}`), slot = { c, s: null };
        c.setTooltip?.(() => (slot.s ? statusTip(slot.s, game) : ''));
        c.onRightClick?.(() => { if (slot.s) ctx.cancelStatus(slot.s); });
        win.data.slots.push(slot);
      }
    },
    update(win) {
      const list = upkeepStatuses(ex.entriesOf(game.player), s => statusRemaining(game, s));
      const sig = list.map(s => `${s.key ?? s.statusIndex}:${s.iconIndex}`).join('|');
      const d = win.data;
      win.data.slots.forEach((slot, i) => { slot.s = list[i] || null; });
      if (d.sig === sig) return;
      d.sig = sig;
      d.slots.forEach((slot, i) => {
        const s = list[i];
        slot.c.setVisible(!!s);
        if (s) slot.c.setImage('none', s.iconGroup || CFG.upkeep.iconGroup, statusIcon(s));
      });
    },
  });

  // ------------------------------------------------------------------ monster quickslot
  game.uiwin.registerWindow('hud_monsterquickslot', {
    ...HUD, script: 'game2/mainbar/ui_monsterquickslotwnd.txt', movable: false,
    create(win) {
      win.control('lbl_controltype').setText(CFG.monsterForm.controlTypeText);
      win.control('btn_close').onClick(() => { const t = ex.transform(); if (t) ctx.cancelStatus(t.status); });
      win.data.slots = [];
    },
    update(win) {
      const t = ex.transform();
      const d = win.data;
      if (CFG.monsterForm.liftAboveQuickslot) {
        const q = game.uiwin.window?.('hud_quickslot');
        const y = q?.isOpen && q.box ? q.box.y - win.box.h : null;
        if (y != null && d.y !== y) { d.y = y; win.setPosition(0, y, false); }
      }
      const key = t ? `${t.index}:${t.row.skills.join(',')}` : '';
      if (d.key === key) return;
      d.key = key;
      for (const c of d.slots) c.remove?.();
      d.slots = [];
      const tpl = win.find('slot');
      (t?.row.skills || []).forEach((skill, i) => {
        const c = tpl?.cloneAs?.(`_${i}`, { x: 20 + i * 44, y: 4 });
        if (!c) return;
        c.setVisible(true);
        c.setTooltip?.(() => game.skills?.data?.skill?.(skill)?.name || `Skill ${skill}`);
        d.slots.push(c);
      });
    },
  });

  // ------------------------------------------------------------------ monster bodies
  ex.update = dt => {
    const pool = [game.player, ...(game.network?.players?.values?.() || [])];
    const seen = new Set();
    for (const actor of pool) {
      if (!actor || actor.disposed) continue;
      const t = transformOf(ex.entriesOf(actor), ex.defOf, ex.table);
      if (!t) continue;
      seen.add(actor);
      let f = ex.forms.get(actor);
      if (f && f.index !== t.index) { endForm(actor, f); f = null; }
      if (!f) { f = startForm(game, actor, t); ex.forms.set(actor, f); }
      stepForm(actor, f, dt);
    }
    for (const [actor, f] of ex.forms) if (!seen.has(actor)) endForm(actor, f);
    const want = !!game.player && seen.has(game.player);
    const w = game.uiwin.window?.('hud_monsterquickslot');
    if (want && !w?.isOpen && !ex.opening) { ex.opening = true; game.uiwin.open('hud_monsterquickslot').catch(err => console.error('[mainbar] monster quickslot', err)).finally(() => { ex.opening = false; }); }
    else if (!want && w?.isOpen) game.uiwin.close('hud_monsterquickslot');
  };
  function endForm(actor, f) {
    ex.forms.delete(actor);
    for (const c of f.hidden) c.visible = true;
    f.hidden.clear();
    try { f.body?.dispose(); } catch (err) { console.warn('[mainbar] monster body', err); }
  }
  ex.dispose = () => { for (const [actor, f] of ex.forms) endForm(actor, f); };

  // hud_spellcount draws the arrow-stock sprite (`bow`) with buff counts: opened only when CFG.spellCount.enabled
  for (const w of ['hud_spellcount', 'hud_upkeep']) {
    if (w === 'hud_spellcount' && !CFG.spellCount.enabled) continue;
    game.uiwin.open(w).catch(err => console.error(`[mainbar] ${w}`, err));
  }
  return ex;
}

function startForm(game, actor, t) {
  const f = { index: t.index, row: t.row, body: null, ready: false, hidden: new Set(), state: null };
  const def = game.data?.monster?.(t.row.monsterIndex);
  if (!def) return f;
  const body = new Monster(game, def);
  body.cullable = false;
  body.fadeOnDeath = false;
  body.group.userData.actor = actor;           // picking the monster body picks the player
  body.setPosition(actor.x, actor.z);
  body.yaw = actor.yaw;
  f.body = body;
  body.load().then(() => {
    if (body.disposed) return;
    f.scale = body.scale;   // the monster's own native scale (Global parity: MONSTER_SCALE not applied)
    f.ready = true;
  });
  return f;
}

function stepForm(actor, f, dt) {
  const body = f.body;
  if (!body || body.disposed) return;
  if (body.x !== actor.x || body.z !== actor.z) body.setPosition(actor.x, actor.z);
  body.yaw = actor.yaw;
  if (f.ready) {
    // the player's own body (model, weapons, effects attached to it) is hidden; its target ring stays
    for (const c of actor.group.children) if (c !== actor._ring && c.visible) { c.visible = false; f.hidden.add(c); }
    const st = monsterFormState(actor);
    if (st !== f.state) { f.state = st; body.play(st, st === 'attack' ? { variant: 0 } : {}); }
  }
  body.update(dt);
}
