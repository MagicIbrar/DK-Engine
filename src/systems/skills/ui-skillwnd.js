// The original skill windows (docs/UIWIN.md platform, script/ui/game2/...):
//   skills           charwindow/ui_renewal_skillwnd_two.txt (425x678 = renewalskillwnd#1 art): class tabs down the left
//                    (normal tabs, Meister, Grand Meister, Attribute, Life = stringtable 60 / 150 names), remaining skill
//                    and attribute points, and the skill tree drawn by the client in the `skilltree` area: 62-px cells
//                    (x 0..4, y 0..9), skill slot frames renewalskillwnd#27-30 (meister #7-9), 40-px icons (skill_icon
//                    IconIndex; the grey column for unlearned), level plates #13, level-up buttons #14-17, connector
//                    tiles skill_line (4-bit masks 1 up / 2 right / 4 down / 8 left; +16 = not yet reachable). Meister tabs
//                    show the path sub tabs (btn_sub_skill_tab_1/2) and the direction-key move skills strip
//                    (pan_skill_cover, renewalskillwnd#31-33). Drag an icon to the quick slots; double click puts it
//                    on the first free slot.
//   skillup          skill/ui_skillupwnd.txt: the "+" dialog (current / next level, target level - + Max, points, OK)
//   skill_reinforce  skill/ui_skillreinforcewnd.txt: meister reinforcement (rate, DIL, skill book)
//   skillreset       msgbox/ui_skillreset.txt: skill / attribute point reset (exp.csv ClearCount_n DIL)
//   statreset        msgbox/ui_statreset.txt: stat point reset (exp.csv StatClearCost_n; src/game/point-resets.js)
//   servant_win      ui_servantwnd.txt + ui_servantskillwnd.txt: the summon's HP, commands and power gauge
import { atlas } from '../../ui/atlas.js';
import { warmSkillIcons, warmIcons } from '../../ui/icon-prewarm.js';
import { applyFont } from '../../ui/uiwin/fonts.js';
import { fetchCSVObjects } from '../../engine/assets.js';
import { installServantWindows } from './ui-servant.js';
import { RESET_COUNTS, RESET_MSG, STAT_NOTHING_TEXT, resetsUsed, pointResetCost, statResetsLeft, statResetErrorCode } from '../../game/point-resets.js';
import { resetStats } from '../../game/progression.js';

const CELL = 62;
const ORIGIN = { x: 109, y: 42 };            // window px of tree cell (0, 0)
const MEISTER_ORIGIN = { x: 109, y: 163 };   // rows 1..3 of the meister trees (row 0 = move skills strip)
const STRIP = { x: 113, y: 98, pad: 10, slot: 55 };
const num = v => (Number.isFinite(+v) ? +v : 0);

function el(cls, parent, style = {}) {
  const e = document.createElement('div');
  if (cls) e.className = cls;
  Object.assign(e.style, { position: 'absolute' }, style);
  if (parent) parent.appendChild(e);
  return e;
}
function sprite(e, group, index, dx = 0) {
  const s = atlas.spriteNow(group, index, dx);
  if (s) { e.style.backgroundImage = `url("${s.url}")`; e.style.backgroundSize = '100% 100%'; return; }
  const tok = (e._tok = {});
  atlas.sprite(group, index, dx).then(sp => { if (e._tok === tok && sp) { e.style.backgroundImage = `url("${sp.url}")`; e.style.backgroundSize = '100% 100%'; } });
}
function iconSprite(e, skill, active) {
  const i = Number(skill.iconIndex ?? skill.index);
  if (active) { sprite(e, 'skill_icon', i); return; }
  const ready = atlas.spriteNow('skill_icon', 10000 + i) || atlas.spriteNow('skill_icon', i, -40);
  if (ready) { e.style.backgroundImage = `url("${ready.url}")`; e.style.backgroundSize = '100% 100%'; return; }
  // the grey icon: imagetable 10000 + IconIndex, else the 40-px column left of the coloured one
  const tok = (e._tok = {});
  atlas.sprite('skill_icon', 10000 + i).then(s => s || atlas.sprite('skill_icon', i, -40)).then(sp => {
    if (e._tok === tok && sp) { e.style.backgroundImage = `url("${sp.url}")`; e.style.backgroundSize = '100% 100%'; }
  });
}
const strip = s => String(s ?? '').replace(/<center>/gi, '').replace(/<[^>]+>/g, '').trim();

// ============================================================================================ tooltip
/** Original-style skill tooltip (stringtable 60: Current / Next Skill Level, Lv, HP, MP, Rage, Cooldown). */
export function skillTooltip(engine, skill) {
  if (!skill) return null;
  const M = c => (c === 75 ? String(engine.msg(c)).replace(/<[^>]+>/g, '') : strip(engine.msg(c)));
  const lv = engine.learnedLevel(skill.index);
  const max = engine.maxLevelFor(skill);
  const lines = [];
  lines.push({ text: `<color=ffd257>${skill.name}</color>${lv ? `  Lv ${lv}` : ''}`, font: 4 });
  if (skill.weaponReq) lines.push({ text: skill.weaponReq, color: '#a9c7ff' });
  const kind = engine.isPassive(skill) ? 'Passive' : skill.kind === 'active' ? '' : '';
  if (kind) lines.push({ text: kind, color: '#a9a9a9' });
  const block = (L, title, level) => {
    if (!L) return;
    lines.push({ text: `<color=00ff00>${title}</color>${M(75).replace('%u', level)}`, font: 2 });
    const res = [];
    if (num(L.hp)) res.push(M(76).replace('%u', L.hp));
    if (num(L.mp)) res.push(M(77).replace('%u', L.mp));
    if (num(L.fury)) res.push(M(83).replace('%u', L.fury));
    if (res.length) lines.push({ text: res.join('   ') });
    if (num(L.cooldownMs)) lines.push({ text: M(81).replace('%.1f', (num(L.cooldownMs) / 1000).toFixed(1)) });
    const desc = L.description || skill.description;
    if (desc) lines.push({ text: desc, color: '#e0e0e0' });
  };
  if (lv > 0) block(engine.levelData(skill, lv), M(3), lv);
  if (lv < max) {
    const nl = lv + 1, L = engine.levelData(skill, nl);
    block(L, M(4), nl);
    const chk = engine.canLevel(skill.index);
    const reqs = [];
    if (L && num(engine.save?.level) < num(L.reqLevel)) reqs.push(`<color=ff4040>Required level ${L.reqLevel}</color>`);
    else if (L) reqs.push(`Required level ${L.reqLevel}`);
    for (const pr of L?.prereqs || []) {
      const ps = engine.skillDef(pr.skill);
      const ok = engine.learnedLevel(pr.skill) >= num(pr.level);
      reqs.push(`${ok ? '' : '<color=ff4040>'}${ps?.name || pr.skill} Lv ${pr.level}${ok ? '' : '</color>'}`);
    }
    if (num(L?.grade)) reqs.push(`Trans-up grade ${L.grade}`);
    if (L && num(L.spCost)) reqs.push(`${skill.pointType === 'attribute' ? 'Attribute' : 'Skill'} points: ${L.spCost}`);
    if (chk.reason === 59) reqs.push(`<color=ff4040>${M(59)}</color>`);
    if (reqs.length) lines.push({ text: reqs.join('\n'), color: '#cfcfcf' });
  } else if (lv > 0) lines.push({ text: `<color=ffd257>${M(2)}</color>` });
  else {
    // not available to this character yet (meister path not chosen / path-B skill on path A)
    block(engine.levelData(skill, 1), M(4), 1);
    const L1 = engine.levelData(skill, 1);
    if (L1?.reqLevel) lines.push({ text: `Required level ${L1.reqLevel}`, color: '#cfcfcf' });
    if (skill.tree?.window === 'meister' || skill.maxLevel?.normal === 0) lines.push({ text: `<color=ff4040>${M(59)}</color>` });
  }
  if(lv>0&&!engine.isPassive(skill)){
    const reason=engine.usability?.(skill.index);
    if(reason?.ok===false){const label={mp:'Not enough MP',hp:'Not enough HP',fury:'Not enough Rage',cooldown:'Skill is cooling down',weapon:'Required weapon is not equipped'}[reason.reason];if(label)lines.push({text:label,color:'#ff7070'});}
  }
  return { lines, width: 300 };
}

// ============================================================================================ the tree view
class TreeView {
  constructor(game, sys, win) {
    this.game = game; this.sys = sys; this.win = win;
    this.engine = sys.engine;
    this.box = el('dk-skilltree', win.root.el, { left: '0px', top: '0px', width: '425px', height: '678px', zIndex: '120', pointerEvents: 'none' });
    this.cells = [];
    this.tab = null;
    this.viewPath = null;
  }

  clear() { this.box.replaceChildren(); this.cells = []; }

  /** 2k: re-check the greying of already-drawn cells (MP/HP/cooldown/weapon/mounted/... change every frame; the
   * icons don't need a full rebuild for that). */
  refreshUsability() { for (const c of this.cells) c.paintUse?.(); }

  render(tab) {
    this.tab = tab;
    this.clear();
    if (!tab) return;
    const e = this.engine;
    const skills = tab.skills.map(i => e.skillDef(i)).filter(s => s && !s.hidden);
    const meister = tab.kind === 'meister' || tab.kind === 'grand';
    const pos = (s) => {
      if (tab.kind === 'meister' && s.tree.y === 0 && tab.hasStrip) {
        return { x: STRIP.x + STRIP.pad + s.tree.x * STRIP.slot + (STRIP.slot - CELL) / 2, y: STRIP.y + (STRIP.slot - CELL) / 2 + 2, strip: true };
      }
      const o = tab.kind === 'meister' ? MEISTER_ORIGIN : tab.kind === 'grand' ? { x: ORIGIN.x, y: STRIP.y } : ORIGIN;
      const yy = tab.kind === 'meister' ? s.tree.y - 1 : s.tree.y;
      return { x: o.x + s.tree.x * CELL, y: o.y + yy * CELL };
    };
    // connectors first (under the icons)
    if (!meister) this._lines(skills, pos);
    for (const s of skills) this._cell(s, pos(s), meister);
  }

  _lines(skills, pos) {
    const e = this.engine;
    const at = new Map(skills.map(s => [`${s.tree.x},${s.tree.y}`, s]));
    const tiles = new Map();          // "x,y" -> {mask, active}
    const addBit = (x, y, bit, active) => {
      const k = `${x},${y}`;
      const t = tiles.get(k) || { x, y, mask: 0, active: false };
      t.mask |= bit; t.active = t.active || active;
      tiles.set(k, t);
    };
    const U = 1, R = 2, D = 4, L = 8;
    for (const s of skills) {
      for (const pr of s.levels?.[0]?.prereqs || []) {
        const ps = skills.find(x => x.index === pr.skill);
        if (!ps) continue;
        const active = e.learnedLevel(pr.skill) >= num(pr.level);
        let x0 = ps.tree.x, y0 = ps.tree.y;
        const x1 = s.tree.x, y1 = s.tree.y;
        // vertical first (the prerequisite's column), then horizontal; if that corner holds another skill go
        // horizontal first
        const vertFirst = !(y1 !== y0 && x1 !== x0 && at.has(`${x0},${y1}`) && !at.has(`${x1},${y0}`));
        const stepV = () => { while (y0 !== y1) { const dy = Math.sign(y1 - y0); addBit(x0, y0, dy > 0 ? D : U, active); y0 += dy; addBit(x0, y0, dy > 0 ? U : D, active); } };
        const stepH = () => { while (x0 !== x1) { const dx = Math.sign(x1 - x0); addBit(x0, y0, dx > 0 ? R : L, active); x0 += dx; addBit(x0, y0, dx > 0 ? L : R, active); } };
        if (vertFirst) { stepV(); stepH(); } else { stepH(); stepV(); }
      }
    }
    for (const t of tiles.values()) {
      if (!t.mask) continue;
      const p = pos({ tree: { x: t.x, y: t.y } });
      const d = el('dk-skl-line', this.box, { left: `${p.x}px`, top: `${p.y}px`, width: `${CELL}px`, height: `${CELL}px`, zIndex: '1' });
      sprite(d, 'skill_line', t.active ? t.mask : t.mask + 16);
    }
  }

  _cell(s, p, meister) {
    const e = this.engine, g = this.game;
    const lv = e.learnedLevel(s.index);
    const max = e.maxLevelFor(s);
    const chk = e.canLevel(s.index);
    const passive = e.isPassive(s);
    const c = el('dk-skl-cell', this.box, { left: `${Math.round(p.x)}px`, top: `${Math.round(p.y)}px`, width: `${CELL}px`, height: `${CELL}px`, zIndex: '2' });
    // slot frame. The 40-px icon hole of the frame art is NOT centred in the sprite (measured on skill.dds): the
    // normal frames #27-30 (51x51, drop shadow right/bottom) open at 3,3; the meister frame #7 (58x58) at 7,7.
    // The icon sits at 11,7 of the 62-px cell (centred on the connector lines) and the frame is placed around it,
    // all on whole pixels.
    const fw = meister ? 58 : 51;
    const hole = meister ? 7 : 3;
    const ICON_X = 11, ICON_Y = 7;
    const frame = el('dk-skl-frame', c, { left: `${ICON_X - hole}px`, top: `${ICON_Y - hole}px`, width: `${fw}px`, height: `${fw}px`, pointerEvents: 'auto', cursor: 'pointer' });
    const reachable = lv > 0 || chk.ok || chk.reason === 82;
    const base = meister ? 7 : (reachable ? 27 : 30);
    sprite(frame, 'renewalskillwnd', base);
    const icon = el('dk-skl-icon', frame, { left: `${hole}px`, top: `${hole}px`, width: '40px', height: '40px' });
    iconSprite(icon, s, lv > 0);
    // The skill tree communicates learned ownership; transient casting restrictions
    // belong to the tooltip/hotbar, never the unlearned grey artwork.
    const paintUse = null;
    frame.addEventListener('pointerenter', ev => {
      sprite(frame, 'renewalskillwnd', meister ? 8 : (reachable ? 28 : 30));
      this.win.mgr.tooltips.show(skillTooltip(e, s), ev.clientX, ev.clientY);
    });
    frame.addEventListener('pointermove', ev => this.win.mgr.tooltips._place?.(ev.clientX, ev.clientY));
    frame.addEventListener('pointerleave', () => { sprite(frame, 'renewalskillwnd', base); this.win.mgr.tooltips.hide(); });
    // 2r: pick up to the quick slots (learned active skills only) - press-drag-release moves it while held, a plain
    // click (no movement) sticks the icon to the cursor until the next click (a hotbar slot placed/swaps it) or
    // right-click / Esc (mgr.dnd cancels globally). Pressing an unlearned or passive skill does nothing.
    frame.addEventListener('pointerdown', ev => {
      if (ev.button !== 0) return;
      if (!(lv > 0) || passive) return;
      sprite(frame, 'renewalskillwnd', meister ? 9 : 29);
      const start = { x: ev.clientX, y: ev.clientY };
      let moved = false;
      const move = mv => {
        if (moved || Math.hypot(mv.clientX - start.x, mv.clientY - start.y) < 4) return;
        moved = true;
        cleanup();
        this.win.mgr.dnd.start(dragPayload(g, s), mv, 'hold');
      };
      const up = uv => {
        cleanup();
        sprite(frame, 'renewalskillwnd', base);
        if (!moved) this.win.mgr.dnd.start(dragPayload(g, s), uv, 'sticky');
      };
      const cleanup = () => { removeEventListener('pointermove', move, true); removeEventListener('pointerup', up, true); };
      addEventListener('pointermove', move, true);
      addEventListener('pointerup', up, true);
    });
    frame.addEventListener('dblclick', () => {
      if (!(lv > 0) || passive) return;
      const bar = g.save.hotbar || (g.save.hotbar = []);
      let i = bar.findIndex((x, k) => k < 10 && !x);
      if (i < 0 && bar.length < 10) i = bar.length;
      if (i >= 0 && !bar.some(x => x?.type === 'skill' && x.index === s.index)) {
        if (g.hud?.setSlot) g.hud.setSlot(i, { type: 'skill', index: s.index }); else bar[i] = { type: 'skill', index: s.index };
        g.audio?.ui?.('buttonCommon');
      }
    });
    // level plate (current level) and the level-up button
    const plate = el('dk-skl-lv', c, { left: `${(CELL - 24) / 2 - 9}px`, top: `${CELL - 20 + 1}px`, width: '24px', height: '20px', color: '#fff', textAlign: 'center', lineHeight: '20px' });
    sprite(plate, 'renewalskillwnd', 13);
    applyFont(plate, 2);
    plate.style.color = lv >= max && lv > 0 ? '#ffd257' : '#ffffff';
    plate.textContent = String(lv);
    if (!(lv >= max)) {
      const up = el('dk-skl-up', c, { left: `${(CELL - 24) / 2 + 17}px`, top: `${CELL - 19 + 1}px`, width: '19px', height: '19px', pointerEvents: 'auto', cursor: chk.ok ? 'pointer' : 'default' });
      const ok = chk.ok;
      sprite(up, 'renewalskillwnd', ok ? 14 : 17);
      if (ok) {
        up.addEventListener('pointerenter', () => sprite(up, 'renewalskillwnd', 15));
        up.addEventListener('pointerleave', () => sprite(up, 'renewalskillwnd', 14));
        up.addEventListener('pointerdown', ev2 => { ev2.stopPropagation(); sprite(up, 'renewalskillwnd', 16); });
        up.addEventListener('click', ev2 => { ev2.stopPropagation(); g.audio?.ui?.('buttonCommon'); g.skillsUI.levelUp(s.index); });
      } else if (chk.via === 'reinforce') {
        up.style.cursor = 'pointer';
        up.addEventListener('click', () => g.skillsUI.openReinforce(s.index));
      } else {
        up.addEventListener('click', () => { g.hud?.log?.(strip(e.msg(chk.reason || 53)), 'err'); });
      }
    }
    this.cells.push({ skill: s, el: c, paintUse });
  }
}

export function dragPayload(game, s) {
  return {
    data: { type: 'skill', kind: 'skill', index: s.index, skillIndex: s.index, from: 'skillwnd' },
    icon: { sprite: ['skill_icon', Number(s.iconIndex ?? s.index)] },
    size: [40, 40],
    onDropOutside: (ev) => {
      // the HUD's quick-slot bar (hud.js .dk-slot[data-slot]) is not a uiwin window
      const t = document.elementFromPoint(ev.clientX, ev.clientY)?.closest?.('[data-slot]');
      if (t && game.hud?.setSlot) { game.hud.setSlot(Number(t.dataset.slot), { type: 'skill', index: s.index }); return true; }
      return false;
    },
  };
}

// Dynamic tree sprites are not declared as controls in the native window script,
// so registered-panel preparation cannot discover them. Prepare both learned and
// unlearned connector states and dynamic cell/button states before world entry.
export async function warmSkillTreeArtwork(target = atlas, options) {
  const refs = [];
  for (let mask = 1; mask < 16; mask++) for (const offset of [0, 16]) refs.push(['skill_line', mask + offset]);
  for (const index of [7, 8, 9, 13, 14, 15, 16, 17, 27, 28, 29, 30]) refs.push(['renewalskillwnd', index]);
  return warmIcons(refs, async ([group, index]) => {
    const sprite = await target.sprite(group, index);
    if (sprite?.url && typeof Image !== 'undefined') {
      const image = new Image();
      image.src = sprite.url;
      await image.decode(); // CSS uses the generated PNG URL, not the atlas source canvas.
    }
  }, options);
}

// ============================================================================================ install
export async function installSkillWindows(game, sys) {
  // Start before the window is first created; character-selection preparation shares this cache.
  const iconsReady = Promise.all([warmSkillIcons(sys.engine.list), warmSkillTreeArtwork()]);
  (game._interfaceIconTasks ||= []).push(iconsReady);
  const ui = game.uiwin || game.ui;
  const engine = sys.engine;
  if (!ui?.registerWindow) return;
  const cls = sys.data.classRec || {};
  const ci = Number(cls.index ?? 0);
  const tabName = code => strip(engine.messages?.[code]);
  // ---- tab list (left column): normal tabs, Meister, Grand Meister, Attribute, Life
  const tabs = [];
  const byKey = new Map();
  for (const t of cls.tabs || []) {
    const k = `${t.window}:${t.tab}:${t.path || ''}`;
    byKey.set(k, t);
  }
  const normal = (cls.tabs || []).filter(t => t.window === 'skill').sort((a, b) => a.tab - b.tab);
  normal.forEach((t, i) => tabs.push({ kind: 'skill', name: tabName((ci + 1) * 100 + i) || t.name, skills: t.skills, tab: t.tab }));
  const meA = (cls.tabs || []).find(t => t.window === 'meister' && t.tab === 1), meB = (cls.tabs || []).find(t => t.window === 'meister' && t.tab === 2);
  if (meA || meB) tabs.push({ kind: 'meister', name: tabName('150:206') || 'Meister', A: meA?.skills || [], B: meB?.skills || [], pathNames: cls.tabNames, hasStrip: true });
  const gA = (cls.tabs || []).find(t => t.window === 'meister' && t.tab === 3), gB = (cls.tabs || []).find(t => t.window === 'meister' && t.tab === 4);
  if (gA || gB) tabs.push({ kind: 'grand', name: tabName('150:207') || 'Grand Meister', A: gA?.skills || [], B: gB?.skills || [], pathNames: cls.tabNames });
  const at = (cls.tabs || []).find(t => t.window === 'attribute');
  if (at) tabs.push({ kind: 'attribute', name: tabName('150:208') || 'Attribute', skills: at.skills });
  const life = (cls.tabs || []).find(t => t.window === 'life');
  if (life) tabs.push({ kind: 'life', name: tabName('150:209') || 'Life', skills: life.skills });

  let view = null;
  let current = 0;
  const S = { tabs, view: () => view };

  const selectTab = (win, i) => {
    current = Math.max(0, Math.min(tabs.length - 1, i));
    const t = tabs[current];
    for (let k = 0; k < 9; k++) win.control(`btn_skill_tab_${k + 1}`).setChecked(k === current);
    const meister = t && (t.kind === 'meister' || t.kind === 'grand');
    const sub = win.control('pan_add_sub_skill_tab');
    sub.setVisible(!!meister);
    if (meister) {
      const path = view?.viewPath || engine.meisterPath() || 'A';
      view.viewPath = path;
      win.control('btn_sub_skill_tab_1').setText(strip(t.pathNames?.pathA || 'A')).setChecked(path === 'A');
      win.control('btn_sub_skill_tab_2').setText(strip(t.pathNames?.pathB || 'B')).setChecked(path === 'B');
      win.control('pan_skill_cover').setVisible(t.kind === 'meister');
      win.control('pan_check_box').setVisible(t.kind === 'meister');
      win.control('check_item').setChecked(!!game.save?.settings?.lockMoveSkills);
      view.render({ kind: t.kind, hasStrip: t.hasStrip, skills: path === 'B' ? t.B : t.A });
    } else view.render(t);
  };
  const refreshPoints = (win) => {
    win.control('lbl_point').setText(String(num(game.save?.skillPoints)));
    win.control('lbl_grand_point').setText(String(num(game.save?.attrPoints)));
  };
  S.refresh = () => {
    const win = ui.window('skills');
    if (!win?.isOpen || !view) return;
    refreshPoints(win);
    selectTab(win, current);
  };

  ui.registerWindow('skills', {
    script: 'game2/charwindow/ui_renewal_skillwnd_two.txt',
    hotkey: 'KeyK',
    menuButton: 'btn_skill',
    replaces: 'skills',
    create(win) {
      view = new TreeView(game, sys, win);
      win.control('skill_tree').hide();
      for (let k = 0; k < 9; k++) {
        const b = win.control(`btn_skill_tab_${k + 1}`);
        const t = tabs[k];
        if (!t) { b.hide(); continue; }
        b.show().setText(t.name).onClick(() => { game.audio?.ui?.('buttonCommon'); selectTab(win, k); });
      }
      const pickPath = async (path) => {
        const t = tabs[current];
        view.viewPath = path;
        const chosen = engine.meisterPath();
        if (!chosen && num(game.save?.level) >= 170) {
          const name = strip(path === 'A' ? t.pathNames?.pathA : t.pathNames?.pathB);
          const r = await ui.msgbox(`<center>${name}\n<center>Choose this Meister path?`, { kind: 'yesno' });
          if (r === 'yes') {
            if(game.save?.authority==='server'){await engine.chooseMeisterPath?.(path);selectTab(win,current);return;}
            game.save.meister = { ...(game.save.meister || {}), path };
            game.hud?.log?.(strip(engine.msg(61)), 'sys');
            // auto-learn meister skills of the path (skill_maister.csv autoLearn)
            for (const s of engine.list) if (s.tree?.window === 'meister' && s.tree.path === path && s.meister?.autoLearn && !engine.learnedLevel(s.index)) engine.setLevel(s.index, 1, { silent: true });
            engine.refreshPassives();
          }
        }
        selectTab(win, current);
      };
      win.control('btn_sub_skill_tab_1').onClick(() => pickPath('A'));
      win.control('btn_sub_skill_tab_2').onClick(() => pickPath('B'));
      win.control('check_item').onChange(v => { game.save.settings = { ...(game.save.settings || {}), lockMoveSkills: !!v }; });
      win.control('lbl_point').setTooltip(() => strip(engine.msg(84)));
      win.control('lbl_grand_point').setTooltip(() => strip(engine.msg(85)));
      // warm the icon sprites of every tab (the client has its skill textures resident), so tab switches paint at once
      // Icons already prepare during selection/loading, rather than waiting for this first open.
      const refreshSoon = () => { if (win.isOpen) { refreshPoints(win); selectTab(win, current); } };
      for (const evn of ['skilllearn', 'levelup', 'stats', 'equip', 'unequip']) game.events?.on(evn, refreshSoon);
    },
    onOpen(win) {
      refreshPoints(win);
      selectTab(win, current);
    },
    onClose() { ui.tooltips?.hide?.(); },
    update(win, dt) {
      // 2k: keep the visible tree's greying live (MP/HP/cooldown/weapon/mounted swing every frame) without a full
      // re-render; throttled since the tab rarely has more than a few dozen cells.
      S._uT = (S._uT || 0) - dt;
      if (S._uT > 0) return;
      S._uT = 0.15;
      view?.refreshUsability();
    },
  });

  // ---- skill level-up dialog (the "+" button)
  let upSkill = null, upTarget = 0;
  const upPaint = (win) => {
    const s = upSkill;
    if (!s) return;
    const cur = engine.learnedLevel(s.index);
    const L0 = engine.levelData(s, Math.max(1, cur)), L1 = engine.levelData(s, upTarget);
    const res = L => [num(L?.hp) ? strip(engine.msg(76)).replace('%u', L.hp) : '', num(L?.mp) ? strip(engine.msg(77)).replace('%u', L.mp) : ''].filter(Boolean).join(' ');
    const cd = L => (num(L?.cooldownMs) ? strip(engine.msg(81)).replace('%.1f', (L.cooldownMs / 1000).toFixed(1)) : '');
    for (const [side, L, lv] of [['base', cur > 0 ? L0 : null, cur], ['next', L1, upTarget]]) {
      win.control(`pan_skill_icon_${side}`).setIcon({ sprite: ['skill_icon', Number(s.iconIndex ?? s.index)] });
      win.control(`lbl_name_${side}`).setText(L ? `${s.name}${String(engine.msg(75)).replace(/<[^>]+>/g, '').replace('%u', lv)}` : s.name);
      win.control(`lbl_res_${side}`).setText(L ? res(L) : '');
      win.control(`lbl_cooltime_${side}`).setText(L ? cd(L) : '');
      win.control(`lbl_desc_${side}`).setText(L ? (L.description || s.description || '') : '');
    }
    win.control('lbl_target_level').setText(String(upTarget));
    const pt = s.pointType === 'attribute' ? 'attribute' : 'skill';
    let cost = 0;
    for (let l = cur + 1; l <= upTarget; l++) cost += num(engine.levelData(s, l)?.spCost);
    const have = engine.points(pt);
    win.control('lbl_remain_point_desc').setText(strip(engine.msg(pt === 'attribute' ? 80 : 79)));
    win.control('lbl_current_point_desc').setText(strip(engine.msg(pt === 'attribute' ? 85 : 84)));
    win.control('lbl_remain_point').setText(String(have - cost));
    win.control('lbl_current_point').setText(String(have));
    // "Increase <color=FDB602><SKILLNAME></color> skill level?" keeps its colour markup
    const d = win.control('lbl_desc');
    if (upTarget > cur && d.setRichText) d.setRichText(String(engine.msg(74)).replace('<SKILLNAME>', s.name));
    else d.setText(upTarget > cur ? strip(String(engine.msg(74)).replace('<SKILLNAME>', s.name)) : strip(engine.msg(53)));
    win.control('btn_skillup_ok').setEnabled(upTarget > cur);
  };
  const maxReach = (s) => {
    // highest level reachable now with the points in hand (each level checked in turn)
    const cur = engine.learnedLevel(s.index);
    const pt = s.pointType === 'attribute' ? 'attribute' : 'skill';
    let pts = engine.points(pt), lv = cur;
    const cap = engine.maxLevelFor(s);
    while (lv < cap) {
      const L = engine.levelData(s, lv + 1);
      if (!L || num(engine.save?.level) < num(L.reqLevel) || num(L.spCost) > pts) break;
      if ((L.prereqs || []).some(p => engine.learnedLevel(p.skill) < num(p.level))) break;
      pts -= num(L.spCost); lv++;
    }
    return lv;
  };
  ui.registerWindow('skillup', {
    script: 'game2/skill/ui_skillupwnd.txt',
    modal: false,
    create(win) {
      win.control('btn_skillup_close').onClick(() => win.close());
      win.control('btn_skillup_minus').onClick(() => { if (upTarget > engine.learnedLevel(upSkill.index) + 1) { upTarget--; upPaint(win); } });
      win.control('btn_skillup_plus').onClick(() => { if (upTarget < maxReach(upSkill)) { upTarget++; upPaint(win); } });
      win.control('btn_skillup_max').onClick(() => { upTarget = Math.max(engine.learnedLevel(upSkill.index) + 1, maxReach(upSkill)); upPaint(win); });
      win.control('btn_skillup_ok').onClick(async () => {
        const s = upSkill, target = upTarget, steps = target - engine.learnedLevel(s.index);
        win.close();
        // one learn per level bought: under server authority engine.learn is the async 'learn' action (its reply
        // applies the new level before it resolves), so the loop awaits each one instead of firing 30 requests
        for (let i = 0; i < steps && engine.learnedLevel(s.index) < target; i++) { if (!(await engine.learn(s.index))) break; }
        game.audio?.ui?.('skillLevelUp');
      });
    },
    onOpen(win, index) {
      upSkill = engine.skillDef(index);
      if (!upSkill) { win.close(); return; }
      upTarget = Math.min(engine.maxLevelFor(upSkill), engine.learnedLevel(upSkill.index) + 1);
      win.center?.();
      upPaint(win);
    },
  });

  // ---- reset (NPC jobs 7 / 120 / 13; rules and costs: src/game/point-resets.js; the shared server: server/world/point-resets.mjs)
  let clearCost = null;
  const levelRow = async () => {
    if (!clearCost) {
      try { clearCost = await fetchCSVObjects('share/pc/exp.csv'); } catch { clearCost = []; }
    }
    const lv = num(game.save?.level) || 1;
    return clearCost.find(r => Number(Object.values(r)[0]) === lv) || {};
  };
  const resetCost = async (type) => {
    const used = resetsUsed(game.save, type);
    return { cost: pointResetCost(await levelRow(), type, used), count: Math.min(5, used + 1) - 1 };
  };
  const online = () => game.save?.authority === 'server' && typeof game.network?.action === 'function';
  // <center> lines are centred in the client's text box
  const fillCentred = (tb, text) => {
    tb.clear?.();
    for (const line of String(text).split('\n')) {
      const centre = /<center>/i.test(line);
      const t = line.replace(/<center>/gi, '').trim();
      if (!tb.addLine) { tb.setText(String(text).replace(/<center>/gi, '')); break; }
      tb.addLine(t);
      if (centre && tb.content?.lastChild) tb.content.lastChild.style.textAlign = 'center';
    }
  };
  ui.registerWindow('skillreset', {
    script: 'game2/msgbox/ui_skillreset.txt',
    modal: true,
    create(win) {
      win.control('btn_no').onClick(() => win.close('no'));
      win.control('btn_exit').onClick(() => win.close('no'));
      win.control('btn_yes').onClick(async () => {
        const type = win.data.type || 'skill';
        const done = strip(engine.msg(type === 'attribute' ? RESET_MSG.attrDone : RESET_MSG.skillDone));
        // the host checks the NPC, the DIL and the refund itself (a refusal arrives as its chat line)
        if (online()) { const r = await game.network.action('pointreset', { kind: type }); if (r) game.hud?.log?.(done, 'sys'); win.close(r ? 'yes' : 'no'); return; }
        const { cost } = await resetCost(type);
        const dil = num(game.save?.dil);
        if (dil < cost) { game.hud?.log?.(strip(engine.msg(RESET_MSG.noDil)), 'err'); win.close('no'); return; }
        const back = engine.resetPoints(type);
        if (!back) { game.hud?.log?.(strip(engine.msg(type === 'attribute' ? RESET_MSG.attrNone : RESET_MSG.skillNone)), 'err'); win.close('no'); return; }
        if (game.items?.spendDil) game.items.spendDil(cost); else game.save.dil = dil - cost;
        const k = RESET_COUNTS[type];
        game.save[k] = num(game.save[k]) + 1;
        game.hud?.log?.(done, 'sys');
        win.close('yes');
      });
    },
    async onOpen(win, type = 'skill') {
      win.data.type = type;
      const { cost, count } = await resetCost(type);
      let total = 0, back = 0;
      for (const [k, v] of Object.entries(game.save.skills || {})) {
        const s = engine.skillDef(k);
        if (!s || (s.pointType === 'attribute') !== (type === 'attribute') || s.tree?.window === 'meister') continue;
        for (let i = 1; i <= num(v); i++) back += num(engine.levelData(s, i)?.spCost);
      }
      total = back + engine.points(type);
      const code = type === 'attribute' ? RESET_MSG.attrAsk : RESET_MSG.skillAsk;
      const text = String(engine.messages?.[code] ?? engine.msg(code)).replace(/<\/?font[^>]*>/gi, '')
        .replace('<TOTALPOINT>', total).replace('<SKILLPOINT>', back).replace('<COUNT>', count).replace('<BUYVALUE>', cost.toLocaleString('en-US'));
      fillCentred(win.control('textbox'), text);
      win.center?.();
    },
  });
  // msgbox/ui_statreset (100:97 "Reset Stats", an empty textbox, Ok / Cancel): the box fills its textbox with stringtable_skill
  // 60:35 (the question), 60:38 (resets left), 60:39 (the DIL) and 60:40 (unequip notice).
  ui.registerWindow('statreset', {
    script: 'game2/msgbox/ui_statreset.txt',
    modal: true,
    create(win) {
      win.control('btn_no').onClick(() => win.close('no'));
      win.control('btn_exit').onClick(() => win.close('no'));
      win.control('btn_yes').onClick(async () => {
        const done = strip(engine.msg(RESET_MSG.statDone));
        if (online()) { const r = await game.network.action('pointreset', { kind: 'stat' }); if (r) game.hud?.log?.(done, 'sys'); win.close(r ? 'yes' : 'no'); return; }
        const r = resetStats(game, await levelRow());
        if (r.error) {
          const code = statResetErrorCode(r.error);
          game.hud?.log?.(code == null ? STAT_NOTHING_TEXT : strip(String(engine.msg(code)).replace('<VALUE>', 0)), 'err');
          win.close('no'); return;
        }
        game.hud?.log?.(done, 'sys');
        win.close('yes');
      });
    },
    async onOpen(win) {
      const row = await levelRow(), used = resetsUsed(game.save, 'stat');
      const line = code => String(engine.messages?.[code] ?? engine.msg(code)).replace(/<\/?font[^>]*>/gi, '');
      const text = [line(RESET_MSG.statAsk), line(RESET_MSG.statLeft).replace('<VALUE>', statResetsLeft(row, used)),
        line(RESET_MSG.statCost).replace('<DIL>', pointResetCost(row, 'stat', used).toLocaleString('en-US')),
        line(RESET_MSG.statNotice)].join('\n');
      fillCentred(win.control('textbox'), text);
      win.center?.();
    },
  });

  // ---- meister reinforcement
  let reSkill = null;
  ui.registerWindow('skill_reinforce', {
    script: 'game2/skill/ui_skillreinforcewnd.txt',
    create(win) {
      win.control('btn_close').onClick(() => win.close());
      win.control('btn_upgrad').onClick(async () => {
        const s = reSkill;
        if (!s) { game.hud?.log?.(strip(engine.msg(64)), 'err'); return; }
        const lv = engine.learnedLevel(s.index);
        const up = (s.upgrade || []).find(u => num(u.level) === lv) || (s.upgrade || [])[lv - 1];
        if (!up || lv >= engine.maxLevelFor(s)) { game.hud?.log?.(strip(engine.msg(48)), 'err'); return; }
        const price = num(up.priceDil);
        const dil = num(game.items?.dil ?? game.save?.dil);
        if (dil < price) { game.hud?.log?.(strip(engine.msg(46)), 'err'); return; }
        const book = win.data.book;
        if (!book) { game.hud?.log?.(strip(engine.msg(44)), 'err'); return; }
        if(game.save?.authority==='server'){await engine.reinforceMeister?.(s.index,book.uid);win.data.book=null;paintRe(win);return;}
        if (game.items?.spendDil) { if (!game.items.spendDil(price)) { game.hud?.log?.(strip(engine.msg(47)), 'err'); return; } }
        else game.save.dil = dil - price;
        win.data.book = null;
        if (Math.random() * 100 < num(up.ratePct)) {
          // success: the book is used up and the skill gains a level
          try { game.items?.removeInst?.(book, 1); } catch { /* ignore */ }
          engine.setLevel(s.index, lv + 1);
          game.audio?.ui?.('skillLevelUp');
        } else game.hud?.log?.(strip(engine.msg(63)), 'err');   // failure: the book goes back to the inventory
        paintRe(win);
      });
      // the skill book of the selected skill (items type 3/9, use.meisterSkill = skill index)
      const bookOf = d => {
        const inst = d?.inst || d?.item;
        const def = inst && game.items?.def?.(inst.itemIndex);
        return def?.use?.meisterSkill != null ? { inst, skill: Number(def.use.meisterSkill) } : null;
      };
      win.control('pan_item_slot').acceptDrop?.({
        accept: d => { const b = bookOf(d); return !!b && (!reSkill || b.skill === reSkill.index); },
        drop: d => {
          const b = bookOf(d);
          if (!b) { game.hud?.log?.(strip(engine.msg(49)), 'err'); return false; }
          if (!reSkill) reSkill = engine.skillDef(b.skill);
          if (!reSkill || b.skill !== reSkill.index) { game.hud?.log?.(strip(engine.msg(64)), 'err'); return false; }
          win.data.book = b.inst;
          game.hud?.log?.(strip(engine.msg(66)), 'sys');
          paintRe(win);
          return true;
        },
      });
    },
    onOpen(win, index) { reSkill = index != null ? engine.skillDef(index) : null; paintRe(win); },
  });
  const paintRe = (win) => {
    const list = engine.list.filter(s => s.tree?.window === 'meister' && !s.hidden && engine.learnedLevel(s.index) > 0 && (s.upgrade || []).length);
    for (let i = 0; i < 12; i++) {
      const s = list[i];
      const pan = win.control(`pan_skill_${i}`);
      if (!s) { pan.hide(); continue; }
      pan.show();
      win.control(`pan_skill_icon_${i}`).setIcon({ sprite: ['skill_icon', Number(s.iconIndex ?? s.index)] });
      win.control(`txt_skill_lv_${i}`).setText(String(engine.learnedLevel(s.index)));
      const b = win.control(`btn_skill_${i}`);
      b.setChecked(reSkill === s);
      if (!b.data.wired) { b.data.wired = true; b.onClick(() => { reSkill = list[i]; paintRe(win); }); }
      b.setTooltip(() => skillTooltip(engine, s));
    }
    const s = reSkill;
    win.control('pan_choice_skill').setIcon(s ? { sprite: ['skill_icon', Number(s.iconIndex ?? s.index)] } : null);
    win.control('lbl_level').setText(s ? `Lv ${engine.learnedLevel(s.index)}` : '');
    win.control('lbl_skillname').setText(s ? s.name : '');
    const lv = s ? engine.learnedLevel(s.index) : 0;
    const up = s ? ((s.upgrade || []).find(u => num(u.level) === lv) || (s.upgrade || [])[lv - 1]) : null;
    // "Success Rate <VALUE>%" (lbl_upgrade_rate, string 100 203); lbl_ratio = the bonus of a rate cash item (none)
    const rl = win.control('lbl_upgrade_rate');
    if (win.data.rateFmt == null) win.data.rateFmt = String(rl.getText?.() || 'Success Rate <VALUE>%');
    rl.setText(win.data.rateFmt.replace('<VALUE>', up ? String(up.ratePct) : '-'));
    win.control('lbl_ratio').setText('');
    win.control('lbl_need_money').setText(up ? `${num(up.priceDil).toLocaleString('en-US')} DIL` : '');
    const book = win.data.book;
    win.control('skill_item').setIcon(null);
    if (book && game.items?.icon) {
      Promise.resolve(game.items.icon(book.itemIndex, 40, 40)).then(ic => { if (win.data.book === book && ic) win.control('skill_item').setIcon(ic); }).catch(() => {});
    }
  };

  // ---- servant windows (summoners): ui-servant.js
  try { await installServantWindows(game, sys); } catch (err) { console.error('[skills] servant windows failed', err); }

  // ---- public UI helpers
  game.skillsUI = {
    tooltip: (index) => skillTooltip(engine, engine.skillDef(index)),
    dragPayload: (index) => dragPayload(game, engine.skillDef(index)),
    open: async (tabIndex) => { await ui.open('skills'); if (tabIndex != null) selectTab(ui.window('skills'), tabIndex); },
    levelUp: (index) => ui.open('skillup', index),
    openReinforce: (index) => ui.open('skill_reinforce', index),
    reset: (type = 'skill') => ui.open('skillreset', type),
    statReset: () => ui.open('statreset'),
    refresh: () => S.refresh(),
    tabs,
  };
}

