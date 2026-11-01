// Draggable game windows: character (C), skills (K), inventory (I), world map (M), options (Esc) and
// the NPC dialog. Frames use the original generic window art (etc_01#87 nine-slice, close button
// etc_01#315-317, buttons etc_01#88-90, tabs etc_01#452/#453; docs/formats/ui.md §3) with a CSS fallback.
import { atlas } from './atlas.js';
import { beginPanelDrag } from './panel-drag.js';
import { clampToScreen } from './uiwin/layout.js';
import { playerNameplateName } from '../game/nameplate-view.js';
import { h, clear, clamp, fmtInt, fmtPct, fmtSec, fmtDuration, setText, toggleClass, loadLocal, saveLocal, isTyping } from './dom.js';
import {
  classDefOf, skillLevel, skillMpCost, skillCooldownMs, skillDamage, expProgress, loadProgression, progression, npcDef,
} from './gameinfo.js';
import { npcDialogInfo } from './strings.js';
import { HOTBAR_SLOTS, HOTBAR_KEYS } from './hud.js';

const LS_POS = 'dekaron-solo:ui:windows:v1';
const STAT_KEYS = [
  ['str', 'STR', 'Strength: physical damage (melee)'],
  ['dex', 'DEX', 'Dexterity: attack rating, dodge, ranged damage'],
  ['con', 'CON', 'Constitution: maximum HP and defense'],
  ['spr', 'SPR', 'Spirit: maximum MP and magic damage'],
];

// ============================================================================================ map list
const OTHER_RE = /selection map|^login$|new_server|test map|map tool|quest$|arena|colosseum|stadion|battle royale|terra's fangs|lobby|guild|tournament|infinite|dead front|ice castle|frozen valley|battlefield|event|theme park|cartel|defense battle|hunting challenge|zuto|agency|chain of fire|lost horizon|honeymoon|deka island|santa|dekaron independence|white day|halloween|blue dragon|blue snake|mazokie|final test|fight \[|monster summon|dimension rift|dead island|harbor town|stardion/i;
const DUNGEON_RE = /cave|prison|tomb|maze|tower|abyss|lair|nest|donjon|ruins of|shipwreck|fragment|chamber|mansion|library|fetters|corridor|sanctuary|sactuary|temple|crack|treasure|shelter|passage|claw|shadow shield|quilue|ellonom|elleghos|umbar|mordo|underground|hole|fire pot|phoenix|desacato|cursed night|road to immortality|scream|kastotica|agacion|oread|tritone|favnil|siz temple|transport/i;

/**
 * Classify a share/maplist.csv row: 'town' | 'field' | 'dungeon' | 'other' | null (not a real map).
 * Towns are peace zones that are not instanced (PeaceZone=1, DungeonIndex=0, DynamicType=0); dungeons are
 * instanced (DungeonIndex>0 / DynamicType=1) or cave/tower/temple... maps; PvP, siege, events, arenas,
 * character-select and tool maps are 'other'.
 */
export function classifyMap(row) {
  if (!row) return null;
  const name = String(row.Name || '').trim();
  const idx = Number(row.Index);
  const file = String(row.MapFile || '').trim();
  const n = k => Number(row[k]) || 0;
  if (!file || /<</.test(file) || idx === 65535 || !Number.isFinite(idx)) return null;
  if (!name || /[^\x20-\x7e]/.test(name) || /^\?+$/.test(name)) return 'other';
  if ((idx >= 100 && idx <= 113) || n('IsSiege') || OTHER_RE.test(name)) return 'other';
  const inst = n('DungeonIndex') > 0 || n('DynamicType') === 1;
  if (n('PeaceZone') === 1 && !inst && !/prison|abyss|rift|chamber/i.test(name) && (!DUNGEON_RE.test(name) || /parca temple/i.test(name))) return 'town';
  if (inst || DUNGEON_RE.test(name)) return 'dungeon';
  return 'field';
}

/** Group game.data.maps (Map index -> row) for the world-map window; duplicates (same name + file) collapse. */
export function groupMaps(maps) {
  const groups = { town: [], field: [], dungeon: [], other: [] };
  const seen = new Set();
  const rows = [...(maps instanceof Map ? maps.values() : maps || [])].sort((a, b) => Number(a.Index) - Number(b.Index));
  for (const row of rows) {
    const g = classifyMap(row);
    if (!g) continue;
    const key = `${String(row.Name).trim().toLowerCase()}|${String(row.MapFile).trim().toLowerCase()}`;
    if (seen.has(key)) continue;
    seen.add(key);
    const min = Number(row.LimitMinLevel) || 0, max = Number(row.LimitMaxLevel) || 0;
    groups[g].push({ index: Number(row.Index), name: String(row.Name).trim(), file: row.MapFile, min, max, group: g });
  }
  return groups;
}

export function levelRangeText(min, max) {
  if ((min <= 1) && (max === 0 || max >= 250)) return 'All levels';
  if (max === 0 || max >= 250) return `Lv ${min}+`;
  return `Lv ${min} - ${max}`;
}

// ============================================================================================ frame
class Win {
  constructor(mgr, name, { title, width, height, x, y, cls = '' }) {
    this.mgr = mgr;
    this.name = name;
    this.open = false;
    const pos = mgr.positions[name];
    this.x = pos?.x ?? x;
    this.y = pos?.y ?? y;
    this.titleEl = h('div', { class: 'dk-win-title', text: title });
    this.closeBtn = h('div', { class: 'dk-win-close', title: 'Close (Esc)', onclick: () => mgr.close(name) });
    this.head = h('div', { class: 'dk-win-head' }, this.titleEl, this.closeBtn);
    this.body = h('div', { class: 'dk-win-body' });
    this.bg = h('div', { class: 'dk-win-bg' });
    this.el = h('div', { class: `dk-win dk-hit ${cls}`, style: { width: `${width}px`, display: 'none' }, dataset: { win: name } }, this.bg, this.head, this.body);
    if (height) this.el.style.height = `${height}px`;
    mgr.layer.appendChild(this.el);
    // etc_01#87: 232x157 window with the gold title glow (top 28 px) and a footer strip (bottom ~32 px)
    atlas.frame(this.bg, 'etc_01', 87, [14, 30, 14, 34], [14, 30, 14, 26]);
    atlas.button(this.closeBtn, 'etc_01', { none: 315, over: 316, down: 317 });
    this.el.addEventListener('mousedown', () => mgr.front(this));
    this.head.addEventListener('pointerdown', e => this._drag(e));
  }

  setTitle(t) { setText(this.titleEl, t); }

  get scale() { return Number(this.mgr.game.settings?.uiScale) || 1; }

  place() {
    const s = this.scale;
    const z = s === 1 ? '' : String(s);
    if (this.el.style.zoom !== z) this.el.style.zoom = z;
    // with CSS zoom, left/top are in zoomed pixels: keep x/y in those units
    const vw = (globalThis.innerWidth || 1024) / s, vh = (globalThis.innerHeight || 768) / s;
    const w = this.el.offsetWidth || parseInt(this.el.style.width, 10) || 300;
    const height = this.el.offsetHeight || parseInt(this.el.style.height, 10) || 40;
    const fit = clampToScreen(this.x, this.y, w, height, {w:vw,h:vh});
    this.x = fit.x; this.y = fit.y;
    this.el.style.left = `${this.x}px`;
    this.el.style.top = `${this.y}px`;
  }

  _drag(e) {
    if (e.button !== 0 || e.isPrimary === false || this._cancelPanelDrag || this.closeBtn.contains(e.target)) return;
    const sx = e.clientX, sy = e.clientY, ox = this.x, oy = this.y, k = 1 / this.scale;
    this._cancelPanelDrag = beginPanelDrag(e, {
      surface: this.head,
      move: ev => { this.x = ox + (ev.clientX - sx) * k; this.y = oy + (ev.clientY - sy) * k; this.place(); },
      finish: () => {
        this._cancelPanelDrag = null;
        this.mgr.positions[this.name] = { x: this.x, y: this.y };
        saveLocal(LS_POS, this.mgr.positions);
      },
    });
  }
}

// ============================================================================================ manager
export class Windows {
  constructor(game, rootEl) {
    this.game = game;
    this.rootEl = rootEl;
    this.layer = h('div', { class: 'dk-winlayer passthru' });
    rootEl.appendChild(this.layer);
    this.positions = loadLocal(LS_POS, {});
    this.wins = {};
    this.views = {};
    this._z = 20;
    this._t = 0;
    this.pickedSkill = null;
    this.mapTab = 'town';
    this.mapFilter = '';
    this._onViewport = () => { for (const w of Object.values(this.wins)) if (w.open) w.place(); };
    globalThis.addEventListener?.('resize', this._onViewport);
    loadProgression();
  }

  get anyOpen() { return Object.values(this.wins).some(w => w.open); }

  /**
   * Windows are non-modal like the original (you keep fighting with the bag or skill list open): mouse
   * events over a window never reach the canvas anyway, so the controller only has to stop while the user
   * is typing into a text field.
   */
  // uiwin hook: modal original windows (game.uiwin) block game input too
  get capturesInput() { return isTyping() || !!this.game.uiwin?.capturesInput; }

  isOpen(name) { return this.game.uiwin?.has(name) ? this.game.uiwin.isOpen(name) : !!this.wins[name]?.open; }

  toggle(name) {
    // uiwin hook: a window registered on the platform under the same name (or `replaces: name`) takes over
    if (this.game.uiwin?.has(name)) { const was = this.game.uiwin.isOpen(name); this.game.uiwin.toggle(name); return !was; }
    if (this.wins[name]?.open) this.close(name); else this.open(name);
    return this.isOpen(name);
  }

  open(name) {
    if (this.game.uiwin?.has(name)) { this.game.uiwin.open(name); return null; }
    const w = this._win(name);
    if (!w) return null;
    if (!w.open) {
      w.open = true;
      w.el.style.display = '';
    }
    this.refresh(name);
    w.place();
    this.front(w);
    return w;
  }

  close(name) {
    if (this.game.uiwin?.has(name)) { this.game.uiwin.close(name); return; }
    const w = this.wins[name];
    if (!w || !w.open) return;
    w._cancelPanelDrag?.();
    w.open = false;
    w.el.style.display = 'none';
    if (name === 'skills') this.pickedSkill = null;
    if (name === 'npc') this._npc = null;
  }

  closeAll() {
    for (const name of Object.keys(this.wins)) this.close(name);
    this.pickedSkill = null;
    this.game.uiwin?.closeAll();   // uiwin hook: original (non-HUD) windows close too (map change, Esc)
  }

  front(w) {
    this._z += 1;
    w.el.style.zIndex = String(this._z);
  }

  /** Re-render a window (or all open ones). */
  refresh(name) {
    if (!name) { for (const n of Object.keys(this.wins)) if (this.wins[n].open) this.refresh(n); return; }
    const w = this.wins[name];
    if (!w || !w.open) return;
    const fn = this[`_render_${name}`];
    if (fn) fn.call(this, w);
  }

  /** Called every frame by the HUD: light refresh of live numbers in open windows (4 Hz). */
  update(dt) {
    this._t += dt || 0;
    if (this._t < 0.25) return;
    this._t = 0;
    for (const [name, w] of Object.entries(this.wins)) {
      if (!w.open) continue;
      const live = this[`_live_${name}`];
      if (live) live.call(this, w);
    }
  }

  consumeEnter() { return false; }

  dispose() {
    globalThis.removeEventListener?.('resize', this._onViewport);
    this.closeAll();
    this.layer.remove();
    this.wins = {};
  }

  _win(name) {
    if (this.wins[name]) return this.wins[name];
    const vw = globalThis.innerWidth || 1024, vh = globalThis.innerHeight || 768;
    const cfg = {
      character: { title: 'Character', width: 300, x: 40, y: 70 },
      skills: { title: 'Skills', width: 380, height: Math.min(560, vh - 160), x: 360, y: 70 },
      inventory: { title: 'Inventory', width: 372, x: vw - 600, y: 90 },
      map: { title: 'World Map', width: 420, height: Math.min(560, vh - 140), x: vw / 2 - 210, y: 60 },
      settings: { title: 'Options', width: 330, x: vw / 2 - 165, y: vh / 2 - 230 },
      npc: { title: '', width: 360, x: 60, y: vh / 2 - 200, cls: 'dk-npcwin' },
    }[name];
    if (!cfg) return null;
    const w = new Win(this, name, cfg);
    this.wins[name] = w;
    return w;
  }

  _button(label, onclick, { cls = '', title } = {}) {
    const b = h('div', { class: `dk-btn ${cls}`, text: label, title, onclick: e => { if (b.classList.contains('off')) return; this.game.audio?.ui?.('buttonCommon'); onclick?.(e); } });
    atlas.button(b, 'etc_01', { none: 88, over: 89, down: 90 });
    return b;
  }

  // ------------------------------------------------------------------------------------------ character
  _render_character(w) {
    const g = this.game, s = g.save || {}, c = classDefOf(g);
    const v = (this.views.character = { stats: {}, derived: {} });
    clear(w.body);
    w.setTitle('Character');
    v.name = h('div', { class: 'dk-ch-name' });
    v.cls = h('div', { class: 'dk-ch-class' });
    v.icon = h('div', { class: 'dk-ch-icon' });
    const [ig, ii] = [ 'etc_01', 100 + (Number(c?.index ?? s.classIndex) || 0) ];
    atlas.paint(v.icon, ig, ii);
    v.expFill = h('i');
    v.expText = h('div', { class: 'dk-ch-exptext' });
    v.points = h('div', { class: 'dk-ch-points' });
    const statRows = STAT_KEYS.map(([key, label, tip]) => {
      const val = h('span', { class: 'dk-ch-val' });
      const plus = this._button('+', e => this._allocate(key, e?.shiftKey ? 10 : 1), { cls: 'dk-plus', title: `Raise ${label} (shift: +10)` });
      v.stats[key] = { val, plus };
      return h('div', { class: 'dk-ch-stat', title: tip }, h('span', { class: 'dk-ch-key', text: label }), val, plus);
    });
    const D = [
      ['hp', 'HP'], ['mp', 'MP'], ['phys', 'Physical damage'], ['magic', 'Magic damage'], ['defense', 'Defense'],
      ['hit', 'Attack rating'], ['dodge', 'Dodge'], ['crit', 'Critical rate'], ['range', 'Attack range'],
      ['aspd', 'Attack speed'], ['mspd', 'Move speed'], ['regen', 'HP / MP regen'],
    ];
    const derived = D.map(([key, label]) => {
      const val = h('span', { class: 'dk-ch-dval' });
      v.derived[key] = val;
      return h('div', { class: 'dk-ch-drow' }, h('span', { text: label }), val);
    });
    v.dil = h('span', { class: 'dk-dil' });
    v.misc = h('div', { class: 'dk-ch-misc' });
    w.body.append(
      h('div', { class: 'dk-ch-head' }, v.icon, h('div', {}, v.name, v.cls)),
      h('div', { class: 'dk-ch-exp' }, h('div', { class: 'dk-ch-expbar' }, v.expFill), v.expText),
      h('div', { class: 'dk-sect' }, h('span', { text: 'Status' }), v.points),
      h('div', { class: 'dk-ch-stats' }, statRows),
      h('div', { class: 'dk-sect' }, h('span', { text: 'Details' })),
      h('div', { class: 'dk-ch-derived' }, derived),
      h('div', { class: 'dk-sect' }, h('span', { text: 'Record' })),
      h('div', { class: 'dk-ch-foot' }, h('span', {}, 'Dil ', v.dil), v.misc),
    );
    this._live_character(w);
  }

  _live_character() {
    const v = this.views.character;
    if (!v) return;
    const g = this.game, s = g.save || {}, p = g.player || {}, c = classDefOf(g);
    setText(v.name, playerNameplateName(p.name || s.name || '',p.nameplate||g.network?.self?.nameplate));
    setText(v.cls, `Level ${s.level || p.level || 1}  ${c?.name || s.className || ''}`);
    const ep = expProgress(g);
    v.expFill.style.width = `${(ep.frac * 100).toFixed(2)}%`;
    setText(v.expText, Number.isFinite(ep.need) ? `EXP ${fmtInt(ep.cur)} / ${fmtInt(ep.need)}  (${fmtPct(ep.frac)})` : 'EXP  MAX');
    const pts = Number(s.statPoints) || 0;
    setText(v.points, pts ? `Points: ${pts}` : '');
    toggleClass(v.points, 'has', pts > 0);
    for (const [key] of STAT_KEYS) {
      setText(v.stats[key].val, String(s.stats?.[key] ?? '-'));
      toggleClass(v.stats[key].plus, 'off', pts <= 0);
    }
    const st = p.stats || {};
    const num = x => (Number.isFinite(Number(x)) ? Number(x) : null);
    const range = (a, b) => (num(a) == null ? '-' : `${fmtInt(a)} ~ ${fmtInt(b ?? a)}`);
    const pct = x => { const n = num(x); if (n == null) return '-'; return `${(n <= 1 ? n * 100 : n).toFixed(1)}%`; };
    const f1 = x => (num(x) == null ? '-' : (Math.round(Number(x) * 100) / 100).toString());
    const D = v.derived;
    setText(D.hp, `${fmtInt(p.hp ?? 0)} / ${fmtInt(p.maxHp ?? st.maxHp ?? 0)}`);
    setText(D.mp, `${fmtInt(p.mp ?? 0)} / ${fmtInt(p.maxMp ?? st.maxMp ?? 0)}`);
    setText(D.phys, range(st.attackMin, st.attackMax));
    setText(D.magic, range(st.magicMin, st.magicMax));
    setText(D.defense, num(st.defense) == null ? '-' : fmtInt(st.defense));
    setText(D.hit, num(st.hitRate) == null ? '-' : (Number(st.hitRate) <= 1 ? pct(st.hitRate) : fmtInt(st.hitRate)));
    setText(D.dodge, num(st.dodge) == null ? '-' : (Number(st.dodge) <= 1 ? pct(st.dodge) : fmtInt(st.dodge)));
    setText(D.crit, pct(st.critRate));
    setText(D.range, num(st.attackRange) == null ? '-' : `${f1(st.attackRange)} m`);
    setText(D.aspd, f1(st.attackSpeed));
    setText(D.mspd, num(st.moveSpeed) == null ? '-' : `${f1(st.moveSpeed)} m/s`);
    setText(D.regen, `${f1(st.hpRegen)} / ${f1(st.mpRegen)} per s`);
    setText(v.dil, fmtInt(s.dil || 0));
    setText(v.misc, `Kills ${fmtInt(s.kills || 0)}  ·  Deaths ${fmtInt(s.deaths || 0)}  ·  Played ${fmtDuration(s.playSeconds || 0)}`);
  }

  async _allocate(stat, times = 1) {
    const g = this.game, s = g.save || {};
    await loadProgression();
    const prog = progression();
    const n = Math.min(times, Number(s.statPoints) || 0);
    if (n <= 0) return;
    if (prog?.allocateStat) prog.allocateStat(g, stat, n); // spends points, refreshes derived stats, emits 'stats'
    else {
      // fallback when progression.js is not available: spend the points directly
      s.stats = s.stats || {};
      s.stats[stat] = (Number(s.stats[stat]) || 0) + n;
      s.statPoints = (Number(s.statPoints) || 0) - n;
      g.refreshPlayerStats?.(false);
      g.events?.emit?.('stats', { stat, count: n });
    }
    this._live_character();
  }

  // ------------------------------------------------------------------------------------------ skills
  _render_skills(w) {
    const g = this.game, c = classDefOf(g);
    const v = (this.views.skills = { rows: [], mini: [] });
    clear(w.body);
    w.setTitle(`Skills${c?.name ? ` - ${c.name}` : ''}`);
    const list = h('div', { class: 'dk-sk-list' });
    const skills = [...(c?.skills || [])].sort((a, b) => (a.reqLevel || 0) - (b.reqLevel || 0) || a.index - b.index);
    if (!skills.length) list.appendChild(h('div', { class: 'dk-empty', text: 'This class has no skills in the data.' }));
    for (const sk of skills) list.appendChild(this._skillRow(sk, v));
    v.hint = h('div', { class: 'dk-sk-hint' });
    v.sp = h('span', { class: 'dk-sk-sp' });
    const mini = h('div', { class: 'dk-sk-mini' });
    for (let i = 0; i < HOTBAR_SLOTS; i++) {
      const m = { i, el: h('div', { class: 'dk-mini-slot', title: `Hot bar slot ${HOTBAR_KEYS[i]}` }), icon: h('div', { class: 'dk-mini-icon' }), key: h('span', { text: HOTBAR_KEYS[i] }) };
      m.el.append(m.icon, m.key);
      m.el.addEventListener('click', () => this._assignToSlot(i));
      m.el.addEventListener('contextmenu', e => { e.preventDefault?.(); this._setHotbar(i, null); });
      m.el.addEventListener('dragover', e => { e.preventDefault?.(); m.el.classList.add('drop'); });
      m.el.addEventListener('dragleave', () => m.el.classList.remove('drop'));
      m.el.addEventListener('drop', e => {
        e.preventDefault?.();
        m.el.classList.remove('drop');
        const idx = e.dataTransfer?.getData('application/x-dk-skill') || (e.dataTransfer?.getData('text/plain') || '').replace(/^skill:/, '');
        if (/^\d+$/.test(idx)) this._setHotbar(i, { type: 'skill', index: Number(idx) });
      });
      v.mini.push(m);
      mini.appendChild(m.el);
    }
    w.body.append(list, h('div', { class: 'dk-sk-foot' }, h('div', { class: 'dk-sk-foot-row' }, h('span', { text: 'Hot bar' }), v.sp), mini, v.hint));
    this._live_skills();
  }

  _skillRow(sk, v) {
    const g = this.game;
    const icon = h('div', { class: 'dk-sk-icon', draggable: true, title: 'Drag to the hot bar' });
    const name = h('div', { class: 'dk-sk-name' });
    const lvl = h('span', { class: 'dk-sk-lvl' });
    const info = h('div', { class: 'dk-sk-info' });
    const desc = h('div', { class: 'dk-sk-desc', text: sk.description || '' });
    const plus = this._button('+', () => this._learnSkill(sk), { cls: 'dk-plus', title: 'Raise skill level (uses skill points)' });
    const row = h('div', { class: 'dk-sk-row', title: sk.description || sk.name },
      icon, h('div', { class: 'dk-sk-text' }, h('div', { class: 'dk-sk-top' }, name, lvl), info, desc), plus);
    name.textContent = sk.name;
    atlas.paint(icon, 'skill_icon', sk.iconIndex ?? sk.index);
    icon.addEventListener('dragstart', e => {
      e.dataTransfer?.setData('application/x-dk-skill', String(sk.index));
      e.dataTransfer?.setData('text/plain', `skill:${sk.index}`);
      if (e.dataTransfer) e.dataTransfer.effectAllowed = 'copy';
    });
    row.addEventListener('click', e => {
      if (e.target === plus || plus.contains?.(e.target)) return;
      this.pickedSkill = this.pickedSkill === sk.index ? null : sk.index;
      this.game.audio?.ui?.('buttonCommon');
      this._live_skills();
    });
    row.addEventListener('dblclick', () => {
      const bar = g.save?.hotbar || [];
      if (bar.some(e => e?.type === 'skill' && Number(e.index) === sk.index)) return;
      let i = 0;
      while (i < HOTBAR_SLOTS && bar[i]) i++;
      if (i < HOTBAR_SLOTS) this._setHotbar(i, { type: 'skill', index: sk.index });
      this.pickedSkill = null;
      this._live_skills();
    });
    v.rows.push({ sk, row, icon, lvl, info, plus });
    return row;
  }

  _live_skills() {
    const v = this.views.skills;
    if (!v) return;
    const g = this.game, s = g.save || {};
    const plv = s.level || g.player?.level || 1;
    const sp = Number(s.skillPoints) || 0;
    setText(v.sp, sp ? `Skill points: ${sp}` : '');
    for (const r of v.rows) {
      const lv = skillLevel(g, r.sk);
      const max = r.sk.maxLevel || r.sk.levels?.length || 1;
      const locked = lv <= 0;
      toggleClass(r.row, 'locked', locked);
      toggleClass(r.row, 'picked', this.pickedSkill === r.sk.index);
      toggleClass(r.icon, 'grey', locked);
      setText(r.lvl, locked ? `Req. Lv ${r.sk.reqLevel || 1}` : `Lv ${lv} / ${max}`);
      const L = Math.max(1, lv);
      const dmg = skillDamage(r.sk, L);
      const parts = [`MP ${skillMpCost(r.sk, L)}`, `Cool ${fmtSec(skillCooldownMs(r.sk, L))}`];
      if (r.sk.range) parts.push(`Range ${r.sk.range} m`);
      if (dmg) parts.push(`+${fmtInt(dmg)} dmg`);
      parts.unshift(`Req. Lv ${r.sk.reqLevel || 1}`);
      setText(r.info, parts.join('  ·  '));
      const next = r.sk.levels?.find?.(x => x.level === lv + 1);
      const canLearn = sp > 0 && next && lv < max && plv >= (next.reqLevel || 0) && (Number(next.spCost) || 1) <= sp;
      toggleClass(r.plus, 'hidden', !canLearn);
    }
    const skills = new Map((classDefOf(g)?.skills || []).map(x => [Number(x.index), x]));
    const bar = s.hotbar || [];
    for (const m of v.mini) {
      const e = bar[m.i];
      const sk = e?.type === 'skill' ? skills.get(Number(e.index)) : null;
      const id = sk ? `s${sk.index}` : e?.type === 'item' ? `i${e.itemIndex}` : null;
      if (m.id !== id) {
        m.id = id;
        m.icon.style.backgroundImage = '';
        setText(m.icon, '');
        toggleClass(m.icon, 'item', e?.type === 'item');
        if (sk) atlas.paint(m.icon, 'skill_icon', sk.iconIndex ?? sk.index);
        else if (e?.type === 'item') setText(m.icon, String(e.name || 'Item').split(/\s+/).map(w => w[0]).join('').slice(0, 3));
        m.el.title = sk ? `${sk.name} [${HOTBAR_KEYS[m.i]}]` : e?.type === 'item' ? `${e.name || 'Item'} [${HOTBAR_KEYS[m.i]}]` : `Hot bar slot ${HOTBAR_KEYS[m.i]}`;
      }
      toggleClass(m.el, 'target', this.pickedSkill != null);
    }
    const picked = this.pickedSkill != null ? skills.get(this.pickedSkill) : null;
    setText(v.hint, picked
      ? `Place "${picked.name}": click a slot here or on the hot bar.`
      : 'Click a skill, then a slot  ·  double-click: first free slot  ·  drag to the hot bar  ·  right-click a slot to clear');
  }

  _assignToSlot(i) {
    if (this.pickedSkill == null) return;
    this._setHotbar(i, { type: 'skill', index: this.pickedSkill });
    this.pickedSkill = null;
    this._live_skills();
  }

  _setHotbar(i, entry) {
    const hud = this.game.hud;
    if (hud?.setSlot) hud.setSlot(i, entry);
    else {
      const s = this.game.save;
      if (!s) return;
      s.hotbar = s.hotbar || [];
      while (s.hotbar.length < HOTBAR_SLOTS) s.hotbar.push(null);
      s.hotbar[i] = entry;
      this.game.events?.emit?.('hotbar', { slot: i, entry });
    }
    this.game.audio?.ui?.('buttonCommon');
    this._live_skills();
  }

  _learnSkill(sk) {
    const g = this.game, s = g.save || {};
    if (g.skills?.learn) { g.skills.learn(sk.index); this._live_skills(); return; } // logs + emits 'skilllearn'
    const lv = skillLevel(g, sk);
    const next = sk.levels?.find?.(x => x.level === lv + 1);
    const cost = Number(next?.spCost) || 1;
    if (!next || (Number(s.skillPoints) || 0) < cost) return;
    s.skills = s.skills || {};
    s.skills[sk.index] = lv + 1;
    s.skillPoints -= cost;
    g.hud?.log?.(`${sk.name} is now level ${lv + 1}.`, 'sys');
    this._live_skills();
  }

  // ------------------------------------------------------------------------------------------ inventory
  _render_inventory(w) {
    const g = this.game;
    const v = (this.views.inventory = { cells: [] });
    clear(w.body);
    w.setTitle('Inventory');
    const grid = h('div', { class: 'dk-inv-grid' });
    const COLS = 8, ROWS = 6;
    for (let i = 0; i < COLS * ROWS; i++) {
      const cell = { i, el: h('div', { class: 'dk-inv-cell' }), name: h('div', { class: 'dk-inv-name' }), count: h('div', { class: 'dk-inv-count' }) };
      cell.el.append(cell.name, cell.count);
      cell.el.addEventListener('contextmenu', e => { e.preventDefault?.(); this._useItem(i); });
      cell.el.addEventListener('dblclick', () => this._useItem(i));
      cell.el.addEventListener('dragstart', e => {
        const it = this.game.save?.inventory?.[i];
        if (!it) { e.preventDefault?.(); return; }
        const ref = { itemIndex: it.itemIndex ?? it.index, uid: it.uid, name: it.name };
        e.dataTransfer?.setData('application/x-dk-item', JSON.stringify(ref));
        e.dataTransfer?.setData('text/plain', `item:${ref.itemIndex}`);
        if (e.dataTransfer) e.dataTransfer.effectAllowed = 'copy';
      });
      v.cells.push(cell);
      grid.appendChild(cell.el);
    }
    v.dil = h('span', { class: 'dk-dil' });
    v.count = h('span', { class: 'dk-inv-used' });
    w.body.append(grid, h('div', { class: 'dk-inv-foot' }, h('span', {}, h('b', { class: 'dk-dil-ico', text: 'D' }), ' ', v.dil, ' Dil'), v.count),
      h('div', { class: 'dk-inv-hint', text: 'Right-click / double-click: use  ·  drag a potion onto the hot bar' }));
    this._live_inventory();
  }

  _live_inventory() {
    const v = this.views.inventory;
    if (!v) return;
    const s = this.game.save || {};
    const items = Array.isArray(s.inventory) ? s.inventory : [];
    for (const c of v.cells) {
      const it = items[c.i];
      const idx = it ? (it.itemIndex ?? it.index) : null;
      const sig = it ? `${idx ?? ''}|${it.name}|${it.count ?? 1}|${it.grade || ''}` : '';
      if (c.sig === sig) continue;
      c.sig = sig;
      toggleClass(c.el, 'full', !!it);
      c.el.draggable = !!it;
      for (const gr of ['magic', 'noble', 'divine']) toggleClass(c.el, `g-${gr}`, it?.grade === gr);
      setText(c.name, it ? shortName(it.name || `#${idx}`) : '');
      setText(c.count, it && (it.count ?? 1) > 1 ? fmtInt(it.count) : '');
      const grade = it?.grade && it.grade !== 'normal' ? ` [${it.grade}]` : '';
      c.el.title = it ? `${it.name || `Item ${idx}`}${grade}${(it.count ?? 1) > 1 ? ` x${fmtInt(it.count)}` : ''}${it.desc ? `\n${it.desc}` : ''}` : '';
    }
    setText(v.dil, fmtInt(s.dil || 0));
    setText(v.count, `${items.filter(Boolean).length} / ${v.cells.length}`);
  }

  _useItem(i) {
    const g = this.game;
    const it = g.save?.inventory?.[i];
    if (!it) return;
    let ok = false;
    try {
      if (g.loot?.useItem) ok = g.loot.useItem(i);
      else if (g.useItem) ok = g.useItem(i);
      else g.hud?.log?.(`${it.name || 'This item'} cannot be used yet.`, 'err');
    } catch (err) { console.error(err); }
    if (ok && !g.loot) g.audio?.itemUse?.(it); // loot.js emits 'itemuse', which Audio hooks
    this._live_inventory();
  }

  // ------------------------------------------------------------------------------------------ world map
  _render_map(w) {
    const g = this.game;
    const v = (this.views.map = {});
    clear(w.body);
    w.setTitle('World Map');
    this._mapGroups = this._mapGroups || groupMaps(g.data?.maps);
    const tabs = h('div', { class: 'dk-tabs' });
    for (const [key, label] of [['town', 'Towns'], ['field', 'Fields'], ['dungeon', 'Dungeons'], ['other', 'Other']]) {
      const t = h('div', { class: 'dk-tab', text: `${label} (${this._mapGroups[key].length})`, dataset: { tab: key } });
      t.addEventListener('click', () => { this.mapTab = key; this.game.audio?.ui?.('buttonCommon'); this._fillMapList(); });
      atlas.button(t, 'etc_01', { none: 452, over: 453 });
      tabs.appendChild(t);
    }
    v.tabs = tabs;
    v.search = h('input', { type: 'text', class: 'dk-input', placeholder: 'Search maps…', value: this.mapFilter });
    v.search.addEventListener('input', () => { this.mapFilter = v.search.value; this._fillMapList(); });
    v.search.addEventListener('keydown', e => { if (e.key === 'Escape') { v.search.blur?.(); } e.stopPropagation?.(); });
    v.list = h('div', { class: 'dk-map-list' });
    v.cur = h('div', { class: 'dk-map-cur' });
    w.body.append(v.cur, h('div', { class: 'dk-map-top' }, tabs, v.search), v.list);
    this._fillMapList();
  }

  _fillMapList() {
    const v = this.views.map;
    if (!v) return;
    const g = this.game;
    const cur = g.world?.info?.index ?? g.save?.map;
    const curRow = g.data?.mapByIndex?.(cur);
    setText(v.cur, curRow ? `You are in ${curRow.Name}${g.player ? ` (${Math.floor(g.player.x)}, ${Math.floor(g.player.z)})` : ''}` : '');
    for (const t of v.tabs.children) toggleClass(t, 'on', t.dataset.tab === this.mapTab);
    clear(v.list);
    const q = this.mapFilter.trim().toLowerCase();
    const lvl = g.save?.level || g.player?.level || 1;
    const entries = q
      ? Object.values(this._mapGroups).flat().filter(m => m.name.toLowerCase().includes(q) || String(m.index) === q)
      : this._mapGroups[this.mapTab] || [];
    if (!entries.length) v.list.appendChild(h('div', { class: 'dk-empty', text: 'No maps.' }));
    for (const m of entries) {
      const low = m.min > 1 && lvl < m.min;
      const high = m.max > 0 && m.max < 250 && lvl > m.max;
      const row = h('div', { class: `dk-map-row${m.index === Number(cur) ? ' current' : ''}`, title: `Map ${m.index} · ${m.file}\nClick to travel` },
        h('span', { class: 'dk-map-name', text: m.name }),
        h('span', { class: `dk-map-lv${low || high ? ' bad' : ''}`, text: levelRangeText(m.min, m.max) }));
      row.addEventListener('click', () => this._travel(m));
      v.list.appendChild(row);
    }
  }

  _travel(m) {
    const g = this.game;
    this.closeAll();
    g.audio?.ui?.('buttonMain');
    g.hud?.log?.(`Travelling to ${m.name}…`, 'sys');
    try {
      const r = g.travel?.(m.index);
      r?.catch?.(err => { console.error(err); g.hud?.log?.(`Could not load ${m.name}.`, 'err'); });
    } catch (err) { console.error(err); }
  }

  // ------------------------------------------------------------------------------------------ settings
  _render_settings(w) {
    const g = this.game, st = g.settings || {};
    clear(w.body);
    w.setTitle('Options');
    const set = patch => {
      if (g.setSettings) g.setSettings(patch); else Object.assign(st, patch);
      g.events?.emit?.('settings', g.settings || st);
      if ('uiScale' in patch) for (const x of Object.values(this.wins)) if (x.open) x.place();
    };
    const slider = (label, key, min, max, step, toVal, fromVal, fmt) => {
      const out = h('span', { class: 'dk-opt-val' });
      const inp = h('input', { type: 'range', class: 'dk-range', min: String(min), max: String(max), step: String(step) });
      inp.value = String(fromVal(st[key]));
      setText(out, fmt(Number(inp.value)));
      inp.addEventListener('input', () => { setText(out, fmt(Number(inp.value))); set({ [key]: toVal(Number(inp.value)) }); });
      return h('div', { class: 'dk-opt-row' }, h('span', { class: 'dk-opt-label', text: label }), inp, out);
    };
    const check = (label, key, dflt = true) => {
      const inp = h('input', { type: 'checkbox', class: 'dk-check' });
      inp.checked = st[key] == null ? dflt : !!st[key];
      inp.addEventListener('change', () => set({ [key]: inp.checked }));
      return h('label', { class: 'dk-opt-row dk-opt-check' }, inp, h('span', { text: label }));
    };
    const pct = v => `${Math.round(v)}%`;
    w.body.append(
      h('div', { class: 'dk-sect' }, h('span', { text: 'Sound' })),
      slider('Music', 'musicVolume', 0, 100, 1, v => v / 100, v => Math.round((v ?? 0.5) * 100), pct),
      slider('Effects', 'sfxVolume', 0, 100, 1, v => v / 100, v => Math.round((v ?? 0.7) * 100), pct),
      h('div', { class: 'dk-sect' }, h('span', { text: 'Graphics' })),
      check('Shadows', 'shadows', true),
      check('Glow bloom (extra GPU work)', 'bloom', false),
      slider('Draw distance', 'drawDistance', 50, 200, 10, v => v / 100, v => Math.round((v ?? 1) * 100), pct),
      h('div', { class: 'dk-sect' }, h('span', { text: 'Interface' })),
      slider('UI scale', 'uiScale', 80, 150, 5, v => v / 100, v => Math.round((v ?? 1) * 100), pct),
      check('Show names above heads', 'showNameplates', true),
      check('Show controls help', 'showHelp', true),
      check('Show FPS', 'showFps', false),
      h('div', { class: 'dk-opt-buttons' },
        this._button('Save game', () => { g.persist?.(); g.hud?.toast?.('Game saved'); }),
        this._button('Character select', () => { g.persist?.(); if (globalThis.dekaronReturnTo) globalThis.dekaronReturnTo('select'); else globalThis.location?.reload?.(); }),
        this._button('Close', () => this.close('settings'))),
    );
  }

  // ------------------------------------------------------------------------------------------ NPC dialog
  /** Open the talk dialog of an NPC actor (name, role, greeting from the client string tables). */
  openNpc(npc) {
    const g = this.game;
    if (g.uiwin?.has('npc')) { g.uiwin.open('npc', npc); return; }   // uiwin hook: the original NPC dialog took over
    const def = npcDef(g, npc);
    this._npc = { npc, def, info: null };
    const w = this.open('npc');
    const v = (this.views.npc = {});
    clear(w.body);
    w.setTitle(def.name || npc?.name || 'NPC');
    v.title = h('div', { class: 'dk-npc-title' });
    v.greet = h('div', { class: 'dk-npc-greet', text: '…' });
    v.opts = h('div', { class: 'dk-npc-opts' });
    v.msg = h('div', { class: 'dk-npc-msg' });
    w.body.append(v.title, v.greet, v.opts, v.msg, h('div', { class: 'dk-opt-buttons' }, this._button('Close', () => this.close('npc'))));
    g.audio?.npcGreeting?.(def.index, npc);
    const cur = this._npc;
    npcDialogInfo(def, g.data?.npcs?.jobTypes).then(info => {
      if (this._npc !== cur) return;
      cur.info = info;
      w.setTitle(info.name || def.name || 'NPC');
      setText(v.title, info.title);
      setText(v.greet, info.greeting);
      clear(v.opts);
      for (const o of info.options) {
        const b = h('div', { class: 'dk-npc-opt', text: o.label });
        b.addEventListener('click', () => this._npcOption(o));
        v.opts.appendChild(b);
      }
    });
    return w;
  }

  _npcOption(o) {
    const g = this.game, v = this.views.npc;
    g.audio?.ui?.('buttonCommon');
    switch (o.role) {
      case 'TELEPORT': case 'PORTAL': case 'SIEGE_TELEPORT':
        this.close('npc'); this.mapTab = 'field'; this.open('map'); return;
      case 'DUNGEON':
        this.close('npc'); this.mapTab = 'dungeon'; this.open('map'); return;
      case 'SKILLMASTER':
        this.close('npc'); this.open('skills'); return;
      case 'RETURN': {
        const p = g.player;
        if (g.save && p && g.world) {
          g.save.returnPoint = { map: g.world.info.index, x: +p.x.toFixed(2), z: +p.z.toFixed(2) };
          setText(v.msg, 'Your return point has been set here.');
          g.hud?.log?.('Your return point has been set.', 'sys');
        }
        return;
      }
      default:
        setText(v.msg, `${o.label.replace(/^\[[^\]]*\]\s*/, '') || 'This service'} - not available yet.`);
    }
  }
}

function shortName(n) {
  const s = String(n || '');
  return s.length <= 14 ? s : `${s.slice(0, 13)}…`;
}
