import {characterNameCSS} from '../game/character-name.js';
import {guildNameCSS} from '../game/guild-name-color.js';
import {partyNameplateFrame} from '../game/party-nameplate.js';
import {nameplateView,playerNameplateDetails,playerNameplateName} from '../game/nameplate-view.js';
import {nameplateHeadGap} from '../game/nameplate-layout.js';
// In-game HUD, laid out like the original game2 window scripts (script/ui/game2/**, reference screen 1024x768,
// docs/formats/ui.md) and painted with the original atlases where they exist:
//   quick-slot bar  mainbar/ui_quickslotwnd.txt  (left bottom)        newMainbar#200-205, #122/#123
//   HP/MP window    mainbar/ui_hpwnd.txt         (right of the bar)   newMainbar#3, #11-13, etc_01#100+class
//   EXP bar         mainbar/ui_mainmenuwnd.txt   (screen bottom)      newMainbar#61-65
//   menu buttons    mainbar/ui_mainmenuwnd.txt   (right bottom)       new_mainbar#47/#117/#108 + buttons
//   target plate    ui_targetpop.txt             (center top)         pcpop#1 / #128 (boss), #46 HP
//   minimap         minimap/ui_minimapwnd.txt    (right top)          mainbar_minimap#40/#50/#110/#30/#35
//   map title       ui_maptitlewnd.txt           (center top +148)    maptitle#<map index>
//   death box       ui_deathwnd.txt                                   etc_02#1, etc_01#88-90
// Everything has a CSS fallback look (src/ui/style.css "dk-" rules) while/if the art is unavailable.
import * as THREE from 'three';
import { atlas, classIconSprite } from './atlas.js';
import { CursorManager } from './cursor.js';
import {GuildNameplateArt} from './guild-nameplate-art.js';
import { h, clear, clamp01, fmtInt, fmtPct, setText, setStyle, toggleClass, loadLocal, saveLocal, isTyping } from './dom.js';
import {
  classDefOf, skillMap, skillLevel, skillMpCost, skillCooldownMs, expProgress, loadProgression,
  isAggressive, isBoss, levelDiffColor, npcDef,
} from './gameinfo.js';
import { loadStringTable, NPC_JOB, npcJobNameTitle } from './strings.js';
import { applyFont } from './uiwin/fonts.js';

export const HOTBAR_SLOTS = 10;
export const HOTBAR_KEYS = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0'];
const NAMEPLATE_RANGE = 35;
const NAMEPLATE_RANGE_SQ_PAD = (NAMEPLATE_RANGE + 1e-4) * (NAMEPLATE_RANGE + 1e-4);   // cheap reject before the exact hypot test
const RECT_REFRESH_S = 1;   // ENGINE-CHOSEN (opt-6): safety re-read of the canvas rect; resize events are the normal trigger
const FLOATER_LIFE = { 'dmg-out': 1.1, 'dmg-in': 1.1, crit: 1.4, heal: 1.2, miss: 0.9, exp: 1.6, guard: 1.0, dot: 0.9 };
const MAX_LOG = 200;
const MINIMAP_SIZE = 158;
const MINIMAP_ZOOMS = [0.5, 0.75, 1, 1.5, 2, 3];   // screen px per world unit (1 texel = 1 cell at 1)
const LS_UI = 'dekaron-solo:ui:v1';

const tmpV = new THREE.Vector3();
const tmpV2 = new THREE.Vector3();

export class HUD {
  constructor(game, rootEl) {
    this.game = game;
    this.rootEl = rootEl;
    this.prefs = { helpCollapsed: false, chatFilter: 'all', minimapZoom: 2, minimapHidden: false, ...loadLocal(LS_UI, {}) };
    this._off = [];
    this._floaters = [];
    this._floaterPool = [];
    this._plates = new Map();     // actor -> plate record
    this._guildArt = new GuildNameplateArt({db:()=>game.items?.db,visible:mark=>mark.closest('.dk-plate')?.style.display!=='none'});
    this._damaged = new WeakMap(); // actor -> time of last damage
    this._deadAt = new WeakMap();  // actor -> time first seen dead
    this._log = [];
    this._fps = { frames: 0, t: 0 };
    this._timers = { minimap: 0, cursor: 0 };
    this._toast = null;
    this._flash = 0;
    this._mm = { tex: null, key: null, transposed: true, size: 512, name: '', world: null };
    this._hotbarSig = '';
    this._targetSig = '';
    this._mapIndex = null;
    this.els = {};
    loadProgression();
    this._build();
    this._wire();
    this.cursor = game.canvas ? new CursorManager(game.canvas) : null;
    atlas.load().then(() => this._paintArt());
    // The original atlas explicitly labels pcpop#79 as name_border (80% black).
    // Share one decoded nine-slice; never load or resize textures per actor/frame.
    this._nameplateArtReady = Promise.all([atlas.sprite('pcpop',79),atlas.sprite('pcpop',105)]).then(sprites => {
      this._plateFrame = sprites[0];this._plateFrames=new Map([[79,sprites[0]],[105,sprites[1]]]);
      for (const plate of this._plates.values()) this._paintPlateFrame(plate);
    });
    loadStringTable(NPC_JOB).then(t => { this._jobStrings = t; this._targetSig = ''; });
  }

  // =========================================================================================== build
  _build() {
    const E = this.els;
    this.root = h('div', { class: 'dk-hud passthru' });
    this.rootEl.appendChild(this.root);

    // world-anchored layers first (below the panels)
    E.plates = h('div', { class: 'dk-plates passthru' });
    E.floaters = h('div', { class: 'dk-floaters passthru' });
    this.root.append(E.plates, E.floaters);

    // ---- EXP bar (screen bottom, full width)
    E.expL = h('div', { class: 'dk-exp-l' });
    E.expC = h('div', { class: 'dk-exp-c' });
    E.expR = h('div', { class: 'dk-exp-r' });
    E.expFill = h('div', { class: 'dk-exp-fill' });
    E.expGrid = h('div', { class: 'dk-exp-grid' });
    E.expText = h('div', { class: 'dk-exp-text' });
    E.exp = h('div', { class: 'dk-expbar dk-hit', title: 'Experience' }, E.expL, E.expC, E.expR, E.expFill, E.expGrid, E.expText);

    // ---- quick-slot bar (10 slots, keys 1-0)
    E.quickFront = h('div', { class: 'dk-q-front' });
    E.quickRear = h('div', { class: 'dk-q-rear' },
      E.qUp = h('div', { class: 'dk-q-btn dk-q-up', title: 'Previous slot bar' }),
      E.qDown = h('div', { class: 'dk-q-btn dk-q-down', title: 'Next slot bar' }),
      E.qSet = h('div', { class: 'dk-q-btn2 dk-q-set', title: 'Skill list (K)', onclick: () => this.game.windows?.toggle?.('skills') }),
      E.qLock = h('div', { class: 'dk-q-btn2 dk-q-lock', onclick: () => this._toggleLock() }),
      E.qPage = h('div', { class: 'dk-q-page', text: '1' }));
    this.slots = [];
    const slotEls = [];
    for (let i = 0; i < HOTBAR_SLOTS; i++) {
      const s = {
        i,
        el: h('div', { class: 'dk-slot', dataset: { slot: String(i) } }),
        icon: h('div', { class: 'dk-slot-icon' }),
        cool: h('div', { class: 'dk-slot-cool' }),
        cdt: h('div', { class: 'dk-slot-cdt' }),
        key: h('div', { class: 'dk-slot-key', text: HOTBAR_KEYS[i] }),
        lbl: h('div', { class: 'dk-slot-lbl' }),
        cnt: h('div', { class: 'dk-slot-cnt' }),
        over: h('div', { class: 'dk-slot-over' }),
        press: h('div', { class: 'dk-slot-press' }),
        entry: null, skill: null, pressT: 0, iconId: null,
      };
      s.el.append(s.icon, s.lbl, s.cool, s.cdt, s.key, s.cnt, s.over, s.press);
      this._wireSlot(s);
      this.slots.push(s);
      slotEls.push(s.el);
    }
    E.quick = h('div', { class: 'dk-quick dk-hit' }, E.quickFront, slotEls, E.quickRear);

    // ---- HP / MP window (ui_hpwnd)
    E.hpCaption = h('div', { class: 'dk-hp-caption' });
    E.shield = h('div', { class: 'dk-pb dk-pb-shield' });
    E.hpFill = h('div', { class: 'dk-pb dk-pb-hp' });
    E.mpFill = h('div', { class: 'dk-pb dk-pb-mp' });
    E.hpLbl = h('div', { class: 'dk-lbl dk-lbl-hp' });
    E.mpLbl = h('div', { class: 'dk-lbl dk-lbl-mp' });
    E.classIcon = h('div', { class: 'dk-hp-class' });
    E.pcLevel = h('div', { class: 'dk-lbl dk-hp-lvl' });
    E.pcName = h('div', { class: 'dk-lbl dk-hp-name' });
    E.pcExp = h('div', { class: 'dk-lbl dk-hp-exp' });
    E.hpBg = h('div', { class: 'dk-hp-bg' }, E.shield, E.hpFill, E.mpFill, E.hpLbl, E.mpLbl, E.classIcon, E.pcLevel, E.pcName, E.pcExp);
    E.hp = h('div', { class: 'dk-hpwnd dk-hit' }, E.hpCaption, E.hpBg);

    // ---- target plate (ui_targetpop)
    E.tgtPlate = h('div', { class: 'dk-tgt-plate' });
    E.tgtName = h('div', { class: 'dk-tgt-name' });
    E.tgtLevel = h('div', { class: 'dk-tgt-level' });
    E.tgtHpFill = h('div', { class: 'dk-tgt-hp' });
    E.tgtHpText = h('div', { class: 'dk-tgt-hptext' });
    E.tgtClose = h('div', { class: 'dk-tgt-close', title: 'Clear target', onclick: () => this._clearTarget() });
    E.tgtAggro = h('div', { class: 'dk-tgt-aggro', title: 'Aggressive: attacks on sight' });
    E.tgtStatus = h('div', { class: 'dk-tgt-status' });
    E.target = h('div', { class: 'dk-target dk-hit', style: { display: 'none' } },
      E.tgtPlate, E.tgtName, E.tgtLevel, E.tgtHpFill, E.tgtHpText, E.tgtAggro, E.tgtClose, E.tgtStatus);

    // ---- player buffs (ui_buffwnd icons, group buffer_b 30x30)
    E.buffs = h('div', { class: 'dk-buffs dk-hit' });

    // ---- minimap (ui_minimapwnd)
    E.mmTop = h('div', { class: 'dk-mm-top' });
    E.mmSun = h('div', { class: 'dk-mm-sun' });
    E.mmName = h('div', { class: 'dk-mm-name' });
    E.mmPos = h('div', { class: 'dk-mm-pos' });
    E.mmZoomIn = h('div', { class: 'dk-mm-btn dk-mm-zin', title: 'Zoom in', onclick: () => this.zoomMinimap(+1) });
    E.mmZoomOut = h('div', { class: 'dk-mm-btn dk-mm-zout', title: 'Zoom out', onclick: () => this.zoomMinimap(-1) });
    E.mmToggle = h('div', { class: 'dk-mm-btn dk-mm-toggle', title: 'Show / hide minimap', onclick: () => this._toggleMinimap() });
    E.mmBg = h('div', { class: 'dk-mm-bg' });
    E.mmCanvas = h('canvas', { class: 'dk-mm-canvas', width: MINIMAP_SIZE, height: MINIMAP_SIZE });
    E.mmBorder = h('div', { class: 'dk-mm-border' });
    E.mmPanel = h('div', { class: 'dk-mm-panel' }, E.mmBg, E.mmCanvas, E.mmBorder);
    E.minimap = h('div', { class: 'dk-mini dk-hit' }, E.mmTop, E.mmSun, E.mmName, E.mmPos, E.mmZoomIn, E.mmZoomOut, E.mmToggle, E.mmPanel);
    E.mmCanvas.addEventListener('wheel', e => { e.preventDefault(); this.zoomMinimap(e.deltaY < 0 ? 1 : -1); }, { passive: false });

    // ---- menu column (ui_mainmenuwnd pan_menu_top/middle/bottom)
    E.menu = this._buildMenu();

    // ---- chat / system log
    E.chatLines = h('div', { class: 'dk-chat-lines' });
    E.chatTabs = h('div', { class: 'dk-chat-tabs' });
    for (const [key, label] of [['all', 'All'], ['combat', 'Combat'], ['system', 'System']]) {
      const b = h('div', { class: 'dk-chat-tab', text: label, dataset: { f: key }, onclick: () => this._setChatFilter(key) });
      E.chatTabs.appendChild(b);
    }
    E.chatInput = h('input', { type: 'text', class: 'dk-chat-input', maxlength: '120', placeholder: 'Press Enter to chat' });
    E.chat = h('div', { class: 'dk-chat dk-hit' }, E.chatTabs, E.chatLines, E.chatInput);
    E.chatInput.addEventListener('keydown', e => this._chatKey(e));
    E.chatInput.addEventListener('blur', () => E.chat.classList.remove('typing'));
    this._setChatFilter(this.prefs.chatFilter || 'all');

    // ---- misc
    E.toast = h('div', { class: 'dk-toast passthru', style: { display: 'none' } });
    E.flash = h('div', { class: 'dk-flash passthru', style: { display: 'none' } },
      E.flashText = h('div', { class: 'dk-flash-text' }));
    E.fps = h('div', { class: 'dk-fps passthru' });
    E.helpBody = h('div', { class: 'dk-help-body' },
      helpLine('Left click', 'move / attack / talk'),
      helpLine('Shift + click', 'attack in place'),
      helpLine('W A S D', 'run'),
      helpLine('Right drag', 'turn camera'),
      helpLine('Right click', 'clear target'),
      helpLine('Wheel', 'zoom'),
      helpLine('1 - 0', 'hot bar skills / items'),
      helpLine('Tab', 'nearest target'),
      helpLine('Z', 'pick up items'),
      helpLine('C  K  I  M', 'character, skills, bag, map'),
      helpLine('Esc', 'close windows / options'),
      helpLine('Enter', 'chat'));
    E.helpHead = h('div', { class: 'dk-help-head', onclick: () => this._toggleHelp() },
      h('span', { text: 'Controls' }), E.helpArrow = h('span', { class: 'dk-help-arrow' }));
    E.help = h('div', { class: 'dk-help dk-hit' }, E.helpHead, E.helpBody);
    toggleClass(E.help, 'collapsed', this.prefs.helpCollapsed);

    this.root.append(E.exp, E.quick, E.hp, E.buffs, E.target, E.minimap, E.menu, E.chat, E.help, E.fps);
    // toast / level-up flash / death box live in their own layer above the windows
    this.top = h('div', { class: 'dk-top passthru' }, E.toast, E.flash);
    this.rootEl.appendChild(this.top);
    this._applyMinimapHidden();

    this._onKey = e => {
      if (e.key === 'Enter' && !isTyping() && !e.repeat) {
        if (this.game.windows?.anyOpen && this.game.windows?.consumeEnter?.()) return;
        e.preventDefault();
        this.focusChat();
      }
    };
    globalThis.addEventListener?.('keydown', this._onKey);
    // clicking the world leaves any text field (chat, map search) so WASD / hot keys work again
    this._onCanvasDown = () => {
      const a = globalThis.document?.activeElement;
      if (a && (a.tagName === 'INPUT' || a.tagName === 'TEXTAREA')) { a.blur?.(); this.els.chat.classList.remove('typing'); }
    };
    this.game.canvas?.addEventListener?.('mousedown', this._onCanvasDown);
  }

  _buildMenu() {
    const E = this.els;
    const W = this.game.windows;
    const open = name => () => (this.game.windows || W)?.toggle?.(name);
    const soon = label => () => this.toast(`${label} is not available yet`);
    // [id, x, y, sprites {none, down, over}, title, action | null]
    const top = [
      ['vehicle', 7, 7, [48, 49, 50], 'Vehicle', null],
      ['inven', 40, 7, [72, 73, 74], 'Inventory (I)', open('inventory')],
    ];
    const middle = [
      ['ride', 7, 7, [203, 204, 205], 'Ride', null],
      ['petsummon', 7, 38, [51, 52, 53], 'Pet', null],
      ['petinven', 7, 69, [54, 55, 56], 'Pet inventory', null],
      ['fishing', 7, 100, [57, 58, 59], 'Fishing', null],
      ['mail', 7, 131, [60, 61, 62], 'Mail', null],
      ['expedition', 7, 162, [63, 64, 65], 'Expedition', null],
      ['party', 7, 193, [66, 67, 68], 'Party', null],
      ['supply', 7, 224, [102, 103, 104], 'Supply machine', null],
      ['craft', 40, 7, [200, 201, 202], 'Crafting', null],
      ['character', 40, 38, [75, 76, 77], 'Character (C)', open('character')],
      ['skill', 40, 69, [78, 79, 80], 'Skills (K)', open('skills')],
      ['quest', 40, 100, [81, 82, 83], 'Quests', null],
      ['map', 40, 131, [87, 88, 89], 'World map (M)', open('map')],
      ['personalshop', 40, 162, [90, 91, 92], 'Personal shop', null],
      ['guild', 40, 193, [69, 70, 71], 'Guild', null],
      ['single_supply', 40, 224, [113, 114, 115], 'Supply', null],
    ];
    const bottom = [
      ['escoption', 40, 0, [93, 94, 95], 'Options (Esc)', open('settings')],
    ];
    const mk = (panelCls, bgIdx, list) => {
      const p = h('div', { class: `dk-menu-panel ${panelCls}` });
      p._bg = bgIdx;
      for (const [id, x, y, spr, title, act] of list) {
        const b = h('div', { class: `dk-menu-btn${act ? '' : ' off'}`, title: act ? title : `${title} (not available yet)`, style: { left: `${x}px`, top: `${y}px` }, dataset: { id } });
        b._spr = spr;
        b.addEventListener('click', () => {
          // uiwin hook: a system bound this original menu button (game.ui.registerMenuButton('btn_<id>', ...))
          if (this.game.uiwin?.hasMenuButton(`btn_${id}`) || this.game.uiwin?.hasMenuButton(id)) { this.game.audio?.ui?.('buttonMain'); this.game.uiwin.menuAction(id); return; }
          this.game.audio?.ui?.(act ? 'buttonMain' : 'buttonCommon'); (act || soon(title))();
        });
        p.appendChild(b);
      }
      return p;
    };
    E.menuTop = mk('dk-menu-top', 47, top);
    E.menuMid = mk('dk-menu-mid', 117, middle);
    E.menuBot = mk('dk-menu-bot', 108, bottom);
    return h('div', { class: 'dk-menu dk-hit' }, E.menuTop, E.menuMid, E.menuBot);
  }

  async _paintArt() {
    const E = this.els;
    const g = 'newMainbar';
    // HP window
    atlas.paint(E.hpBg, g, 3);
    atlas.paint(E.shield, g, 11);
    atlas.paint(E.hpFill, g, 12);
    atlas.paint(E.mpFill, g, 13);
    this._paintClassIcon();
    // EXP bar
    atlas.paint(E.expL, g, 61);
    atlas.paint(E.expC, g, 62);
    atlas.paint(E.expR, g, 63);
    atlas.paint(E.expFill, g, 65);
    atlas.paint(E.expGrid, g, 64).then(ok => {
      if (ok) { E.expGrid.style.backgroundRepeat = 'repeat-x'; E.expGrid.style.backgroundSize = '28px 6px'; }
    });
    // quick slots
    atlas.paint(E.quickFront, g, 200);
    atlas.paint(E.quickRear, g, 203);
    atlas.button(E.qUp, g, { none: 101, over: 103, down: 102 });
    atlas.button(E.qDown, g, { none: 111, over: 113, down: 112 });
    atlas.button(E.qSet, g, { none: 80, over: 82, down: 81 });
    this._paintLock();
    for (const s of this.slots) {
      atlas.paint(s.el, g, 201);
      atlas.paint(s.over, g, 122);
      atlas.paint(s.press, g, 123);
    }
    // target plate
    atlas.paint(E.tgtHpFill, 'pcpop', 46);
    atlas.button(E.tgtClose, 'pcpop', { none: 50, over: 51, down: 52 });
    this._targetSig = '';
    // minimap
    atlas.paint(E.mmTop, 'mainbar_minimap', 40);
    atlas.paint(E.mmSun, 'mainbar_minimap', 71);
    atlas.paint(E.mmBorder, 'mainbar_minimap', 50);
    atlas.paint(E.mmBg, 'mainbar_minimap', 110);
    atlas.button(E.mmZoomIn, 'mainbar_minimap', { none: 60 });
    atlas.button(E.mmZoomOut, 'mainbar_minimap', { none: 61 });
    this._paintMinimapToggle();
    this._mmSprites = {};
    for (const [k, idx] of [['arrow', 30], ['camera', 35], ['flag', 32]]) {
      atlas.sprite('mainbar_minimap', idx).then(s => { if (s) this._mmSprites[k] = s.canvas; });
    }
    for (let c = 0; c <= 8; c++) atlas.sprite('mainbar_minimap', 120 + c).then(s => { if (s) this._mmSprites[`dot${c}`] = s.canvas; });
    // menu
    for (const p of [E.menuTop, E.menuMid, E.menuBot]) {
      atlas.paint(p, 'new_mainbar', p._bg);
      for (const b of p.children) if (b._spr) atlas.button(b, 'new_mainbar', { none: b._spr[0], down: b._spr[1], over: b._spr[2] });
    }
    // chat frame
    atlas.frame(E.chatInput, 'etc_01', 78, [4, 4, 4, 4]);
    this._hotbarSig = '';
  }

  _paintLock() {
    const locked = !!this.prefs.hotbarLocked;
    this.els.qLock.title = locked ? 'Hot bar locked (click to unlock)' : 'Lock the hot bar';
    toggleClass(this.els.qLock, 'on', locked);
    // newMainbar#70-72 lock button; the "down" sprite doubles as the locked look
    atlas.button(this.els.qLock, 'newMainbar', locked ? { none: 71, over: 72, down: 71 } : { none: 70, over: 72, down: 71 });
  }

  _toggleLock() {
    this.prefs.hotbarLocked = !this.prefs.hotbarLocked;
    saveLocal(LS_UI, this.prefs);
    this._paintLock();
    this.game.audio?.ui?.('buttonCommon');
  }

  _paintClassIcon() {
    const c = classDefOf(this.game);
    const [g, i] = classIconSprite(c?.index ?? this.game.save?.classIndex);
    atlas.paint(this.els.classIcon, g, i);
  }

  _paintMinimapToggle() {
    const hidden = this.prefs.minimapHidden;
    atlas.button(this.els.mmToggle, 'mainbar_minimap', hidden ? { none: 20, over: 21, down: 22 } : { none: 10, over: 11, down: 12 });
  }

  // =========================================================================================== events
  _wire() {
    const ev = this.game.events;
    if (!ev?.on) return;
    const on = (t, fn) => this._off.push(ev.on(t, fn));
    on('damage', e => this._onDamage(e));
    on('death', e => this._onDeath(e));
    on('exp', e => {
      const amt = Math.round(e?.amount || 0);
      if (amt < 0) { this.log(`You lost ${fmtInt(-amt)} experience.`, 'err'); return; }
      if (amt === 0) return;
      this.log(`You gained ${fmtInt(amt)} experience.`, 'exp');
      if (this.game.player) this.floater(this.game.player, `+${fmtInt(amt)} EXP`, 'exp');
    });
    on('levelup', e => {
      const lv = e?.level ?? this.game.save?.level;
      this.log(`Level up! You are now level ${lv}.`, 'sys');
      this.levelUpFlash(lv);
      this._paintClassIcon();
    });
    on('loot', e => {
      if (!e) return;
      const n = e.count > 1 ? ` x${fmtInt(e.count)}` : '';
      const isDil = /^dil$/i.test(String(e.name || ''));
      this.log(isDil ? `You picked up ${fmtInt(e.count || 0)} Dil.` : `You picked up ${e.name}${n}.`, 'item');
    });
    on('target', () => { this._targetSig = ''; });
    on('skill', e => {
      if (!e || e.actor !== this.game.player) return;
      const idx = e.skill?.index ?? e.skill;
      for (const s of this.slots) if (s.entry?.type === 'skill' && Number(s.entry.index) === Number(idx)) s.pressT = 0.18;
    });
    on('map', e => {
      this._mapIndex = e?.index;
      const row = this.game.data?.mapByIndex?.(e?.index);
      if (row?.Name) this.log(`You entered ${row.Name}.`, 'sys');
    });
    on('skilllearn', e => {
      if (e?.skill) this.log(`${e.skill.name} is now level ${e.level}.`, 'sys');
      this._hotbarSig = '';
      this.game.windows?.refresh?.('skills');
    });
    on('stats', () => this.game.windows?.refresh?.('character'));
    on('settings', () => this._applySettings());
    this._applySettings();
  }

  _onDamage(e) {
    if (!e) return;
    const p = this.game.player;
    const { source, target } = e;
    if (target) this._damaged.set(target, this.game.time ?? performance.now() / 1000);
    const amt = fmtInt(e.amount || 0);
    const skillName = e.skill?.name ? `${e.skill.name} ` : '';
    const note = `${e.crit ? ' (critical!)' : ''}${e.guard ? ' (blocked)' : ''}`;
    const kind = e.crit ? 'crit' : null;
    if (target === p) {
      if (e.miss) { this.floater(p, 'Miss', 'miss'); return; }
      this.floater(p, e.guard ? `Block ${amt}` : amt, e.guard ? 'guard' : kind || 'dmg-in');
      if (!e.dot) this.log(`${source?.name || 'Something'}${skillName ? `'s ${skillName.trim()}` : ''} hits you for ${amt}${note}.`, 'dmg');
    } else if (source === p || source?.owner === p) {
      if (e.miss) { this.floater(target, 'Miss', 'miss'); if (!e.dot) this.log(`You missed ${target?.name || 'the target'}.`, 'dmg'); return; }
      this.floater(target, e.guard ? `Block ${amt}` : amt, e.guard ? 'guard' : kind || (e.dot ? 'dot' : 'dmg-out'));
      if (!e.dot) this.log(`${skillName ? `Your ${skillName}hits` : 'You hit'} ${target?.name || 'the target'} for ${amt}${note}.`, 'dmg');
    } else if (target && !e.miss) {
      this.floater(target, amt, 'dmg-out');
    }
  }

  _onDeath(e) {
    const p = this.game.player;
    if (!e?.actor) return;
    if (e.actor === p) this.log(`You were defeated${e.killer?.name ? ` by ${e.killer.name}` : ''}.`, 'err');
    else if (e.actor.kind === 'monster' && (e.killer === p || !e.killer)) this.log(`You defeated ${e.actor.name}.`, 'sys');
  }

  _applySettings() {
    const s = this.game.settings || {};
    toggleClass(this.els.fps, 'hidden', s.showFps !== true);   // 2.2.1: no frame-rate number on screen unless the player switches it on (was: shown unless switched off)
    toggleClass(this.els.help, 'hidden', s.showHelp === false);
    const scale = Number(s.uiScale) || 1;
    const E = this.els;
    for (const el of [E.exp, E.quick, E.hp, E.buffs, E.target, E.minimap, E.menu, E.chat, E.help, E.toast]) {
      setStyle(el, 'zoom', scale === 1 ? '' : String(scale));
    }
    this.showNameplates = s.showNameplates !== false;
  }

  // =========================================================================================== API
  /** Append a line to the chat/system log. kind: 'sys'|'dmg'|'exp'|'item'|'err'|'chat'. */
  log(text, kind = 'sys') {
    const el = h('div', { class: `dk-line l-${kind}`, text: String(text) });
    this.els.chatLines.appendChild(el);
    this._log.push(el);
    while (this._log.length > MAX_LOG) { const old = this._log.shift(); old.remove?.(); }
    this._scrollChat();
    return el;
  }

  /** Floating combat text that follows `actor` briefly. kind: 'dmg-out'|'dmg-in'|'crit'|'heal'|'miss'|'exp'. */
  floater(actor, text, kind = 'dmg-out') {
    if (!actor) return null;
    const el = this._floaterPool.pop() || h('div', { class: 'dk-float' });
    el.className = `dk-float ${kind}${kind === 'heal' && /MP/.test(String(text)) ? ' mp' : ''}`;
    el.textContent = String(text);
    el.style.opacity = '0';
    if (!el.parentNode) this.els.floaters.appendChild(el);
    // stack floaters on the same actor so they don't overlap
    const same = this._floaters.filter(f => f.actor === actor && f.t < 0.35).length;
    const f = {
      el, actor, kind, t: 0, life: FLOATER_LIFE[kind] || 1.2,
      dx: (Math.random() - 0.5) * 22 + (kind === 'dmg-in' ? 22 : kind === 'exp' ? -34 : kind === 'heal' ? -22 : 0), dy: -same * 16,
      last: null,
    };
    this._floaters.push(f);
    if (this._floaters.length > 60) this._killFloater(this._floaters[0]);
    return f;
  }

  toast(text) {
    const E = this.els;
    const row = this._mapIndex != null ? this.game.data?.mapByIndex?.(this._mapIndex) : null;
    clear(E.toast);
    const t = { t: 0, life: 2.6 };
    if (row && String(text) === String(row.Name) && text) {
      // original map-title banner (ui_maptitlewnd, maptitle#<map>)
      const banner = h('div', { class: 'dk-maptitle' }, h('span', { text: String(text) }));
      E.toast.appendChild(banner);
      E.toast.className = 'dk-toast dk-toast-map passthru';
      t.life = 3.6;
      atlas.paint(banner, 'maptitle', this._mapIndex).then(ok => { if (ok) banner.classList.add('art'); });
    } else {
      E.toast.className = 'dk-toast passthru';
      E.toast.appendChild(h('span', { text: String(text) }));
    }
    E.toast.style.display = '';
    E.toast.style.opacity = '0';
    this._toast = t;
  }

  /** Death dialog (ui_deathwnd): "Revive in town". */
  showDeath(onRevive) {
    this.hideDeath();
    const btn = h('div', { class: 'dk-btn dk-death-btn', text: 'Revive in town' });
    const box = h('div', { class: 'dk-death dk-hit' },
      h('div', { class: 'dk-death-title', text: 'Death' }),
      h('div', { class: 'dk-death-msg', text: 'You have been defeated.' }),
      h('div', { class: 'dk-death-sub', text: 'You will return to the town of this region.' }),
      btn);
    const done = () => {
      this.hideDeath();
      this.game.audio?.ui?.('buttonMain');
      try { onRevive?.(); } catch (err) { console.error(err); }
    };
    btn.addEventListener('click', done);
    atlas.paint(box, 'etc_02', 1);
    atlas.button(btn, 'etc_01', { none: 88, over: 89, down: 90 });
    this.top.appendChild(box);
    this._death = { box, done };
  }

  hideDeath() {
    if (this._death) { this._death.box.remove(); this._death = null; }
  }

  /** Called after each map load. */
  setMinimap(world) {
    const mm = this._mm;
    mm.world = world || null;
    mm.tex = null;
    mm.key = world?.minimap?.key || null;
    mm.transposed = world?.minimap ? world.minimap.transposed !== false : true;
    mm.name = world?.info?.name || this.game.data?.mapByIndex?.(world?.info?.index)?.Name || '';
    this._mapIndex = world?.info?.index ?? this._mapIndex;
    setText(this.els.mmName, mm.name);
    this.els.mmName.title = mm.name;
    if (mm.key) {
      const key = mm.key;
      atlas.texture(key).then(t => { if (this._mm.key === key) this._mm.tex = t; });
    }
    this._drawMinimap();
  }

  zoomMinimap(dir) {
    const z = Math.max(0, Math.min(MINIMAP_ZOOMS.length - 1, (this.prefs.minimapZoom ?? 2) + dir));
    this.prefs.minimapZoom = z;
    saveLocal(LS_UI, this.prefs);
    this.game.audio?.ui?.('buttonCommon');
    this._drawMinimap();
  }

  focusChat() {
    const inp = this.els.chatInput;
    this.els.chat.classList.add('typing');
    inp.focus?.();
  }

  levelUpFlash(level) {
    this._flash = 2.2;
    setText(this.els.flashText, `LEVEL UP!  ${level != null ? level : ''}`.trim());
    this.els.flash.style.display = '';
  }

  // =========================================================================================== update
  update(dt) {
    this._flushChatScroll();
    const g = this.game;
    dt = Math.max(0, Math.min(0.25, Number(dt) || 0));
    this._fpsTick(dt);
    if (!g.player) { this._updateTimers(dt); return; }
    this._updatePlayer();
    this._renderStatuses(this.els.buffs, g.save?.buffs || g.player.statuses, 'buffer_b', 'buffer', true);
    this._updateExp();
    this._updateHotbar(dt);
    this._updateTarget();
    this._updateWorldText(dt);
    this._guildArt.tick(performance.now());
    this._timers.minimap -= dt;
    if (this._timers.minimap <= 0) { this._timers.minimap = 1 / 20; this._drawMinimap(); }
    this._updateCursor(dt);
    this._updateTimers(dt);
    if (this._death && g.player && !g.player.dead && g.player.hp > 0) this.hideDeath();
    g.windows?.update?.(dt);
  }

  _fpsTick(dt) {
    const f = this._fps;
    f.frames++; f.t += dt;
    if (f.t >= 0.5) {
      const fps = f.frames / f.t;
      const info = this.game.renderer?.info?.render;
      setText(this.els.fps, `${fps.toFixed(0)} fps${info ? ` · ${fmtInt(info.calls)} draws` : ''}`);
      f.frames = 0; f.t = 0;
    }
  }

  _updatePlayer() {
    const g = this.game, p = g.player, E = this.els, s = g.save || {};
    const hp = Math.max(0, Math.round(p.hp || 0)), mhp = Math.max(1, Math.round(p.maxHp || 1));
    const mp = Math.max(0, Math.round(p.mp || 0)), mmp = Math.max(1, Math.round(p.maxMp || 1));
    setStyle(E.hpFill, 'width', `${Math.round(clamp01(hp / mhp) * 233)}px`);
    setStyle(E.mpFill, 'width', `${Math.round(clamp01(mp / mmp) * 233)}px`);
    const shield = Number(p.shield), mshield = Number(p.maxShield);
    setStyle(E.shield, 'width', mshield > 0 ? `${Math.round(clamp01(shield / mshield) * 268)}px` : '0px');
    setText(E.hpLbl, `${fmtInt(hp)} / ${fmtInt(mhp)}`);
    setText(E.mpLbl, `${fmtInt(mp)} / ${fmtInt(mmp)}`);
    setText(E.pcLevel, `Lv ${s.level || p.level || 1}`);
    setText(E.pcName, p.name || s.name || '');
    const c = classDefOf(g);
    setText(E.hpCaption, c?.name || s.className || '');
    toggleClass(E.hp, 'low', hp / mhp < 0.25 && hp > 0);
  }

  _updateExp() {
    const { frac, cur, need, level } = expProgress(this.game);
    const pct = fmtPct(frac);
    setStyle(this.els.expFill, 'width', `${(frac * 100).toFixed(3)}%`);
    setText(this.els.pcExp, pct);
    setText(this.els.expText, Number.isFinite(need) ? `Lv ${level}  ·  ${fmtInt(cur)} / ${fmtInt(need)}  (${pct})` : `Lv ${level}  ·  MAX`);
  }

  // ---------------------------------------------------------------------------------------- hotbar
  _hotbar() {
    const s = this.game.save;
    if (!s) return [];
    if (!Array.isArray(s.hotbar)) s.hotbar = [];
    return s.hotbar;
  }

  _updateHotbar(dt) {
    const g = this.game;
    const bar = this._hotbar();
    const sig = JSON.stringify(bar.slice(0, HOTBAR_SLOTS)) + (g.save?.level || 0);
    if (sig !== this._hotbarSig) { this._hotbarSig = sig; this._renderHotbar(); }
    const mp = g.player?.mp ?? 0;
    for (const s of this.slots) {
      if (s.pressT > 0) s.pressT -= dt;
      toggleClass(s.el, 'pressed', s.pressT > 0);
      const sk = s.skill;
      if (s.entry?.type === 'item') {
        // potions on the bar: total count in the bag, greyed at 0, shared potion cooldown from loot.js
        const n = itemCount(g, s.entry);
        setText(s.cnt, n > 0 ? fmtInt(n) : '0');
        toggleClass(s.el, 'nostock', n <= 0);
        let left = 0;
        try { left = Number(g.loot?.itemCooldown?.(s.entry.itemIndex)) || 0; } catch { left = 0; }
        setStyle(s.cool, 'background', left > 0 ? 'rgba(0,0,0,0.6)' : '');
        setText(s.cdt, left >= 1 ? String(Math.ceil(left)) : '');
        continue;
      }
      setText(s.cnt, '');
      if (!sk) { setStyle(s.cool, 'background', ''); setText(s.cdt, ''); toggleClass(s.el, 'nomp', false); continue; }
      const lv = Math.max(1, skillLevel(g, sk));
      const cost = skillMpCost(sk, lv);
      toggleClass(s.el, 'nomp', mp < cost);
      toggleClass(s.el, 'locked', skillLevel(g, sk) <= 0);
      let f = 0;
      try { f = Number(g.skills?.cooldownFraction?.(sk.index)) || 0; } catch { f = 0; }
      f = clamp01(f);
      if (f > 0.001) {
        const deg = ((1 - f) * 360).toFixed(1);
        setStyle(s.cool, 'background', `conic-gradient(transparent ${deg}deg, rgba(0,0,0,0.68) ${deg}deg)`);
        let remain = null;
        try { remain = g.skills?.cooldownRemaining?.(sk.index); } catch { remain = null; }
        if (remain == null) remain = (f * skillCooldownMs(sk, lv)) / 1000;
        setText(s.cdt, remain >= 1 ? String(Math.ceil(remain)) : '');
      } else {
        setStyle(s.cool, 'background', '');
        setText(s.cdt, '');
      }
    }
  }

  _renderHotbar() {
    const bar = this._hotbar();
    const skills = skillMap(this.game);
    for (const s of this.slots) {
      const e = bar[s.i] || null;
      s.entry = e;
      s.skill = e?.type === 'skill' ? skills.get(Number(e.index)) || null : null;
      const id = s.skill ? `skill:${s.skill.index}` : e ? `${e.type}:${e.itemIndex ?? e.index ?? e.name}` : '';
      if (id === s.iconId) continue;
      s.iconId = id;
      s.icon.style.backgroundImage = '';
      s.icon.classList.remove('art');
      setText(s.lbl, '');
      toggleClass(s.el, 'empty', !e);
      toggleClass(s.el, 'item', e?.type === 'item');
      toggleClass(s.el, 'nostock', false);
      s.el.draggable = !!e;
      const itemName = e?.type === 'item' ? (e.name || findItem(this.game, e)?.name || `Item ${e.itemIndex}`) : '';
      s.el.title = s.skill ? `${s.skill.name}  [${HOTBAR_KEYS[s.i]}]` : e ? `${itemName || e.type}  [${HOTBAR_KEYS[s.i]}]` : `Slot ${HOTBAR_KEYS[s.i]} (drag a skill or potion here)`;
      if (s.skill) {
        setText(s.lbl, s.skill.name);
        atlas.paint(s.icon, 'skill_icon', s.skill.iconIndex ?? s.skill.index).then(ok => { if (ok) setText(s.lbl, ''); });
      } else if (e) {
        setText(s.lbl, itemName.slice(0, 16));
      }
    }
  }

  _wireSlot(s) {
    const el = s.el;
    el.addEventListener('click', e => { e.stopPropagation?.(); this.useSlot(s.i); });
    el.addEventListener('contextmenu', e => { e.preventDefault?.(); if (!this.prefs.hotbarLocked) this.setSlot(s.i, null); });
    el.addEventListener('dragstart', e => {
      if (!s.entry || this.prefs.hotbarLocked) { e.preventDefault?.(); return; }
      e.dataTransfer?.setData('application/x-dk-slot', String(s.i));
      e.dataTransfer?.setData('text/plain', `slot:${s.i}`);
      if (e.dataTransfer) e.dataTransfer.effectAllowed = 'move';
    });
    el.addEventListener('dragend', e => {
      // dragged off the bar -> remove it (original behaviour)
      if (e.dataTransfer && e.dataTransfer.dropEffect === 'none') this.setSlot(s.i, null);
    });
    el.addEventListener('dragover', e => { e.preventDefault?.(); if (e.dataTransfer) e.dataTransfer.dropEffect = 'move'; el.classList.add('drop'); });
    el.addEventListener('dragleave', () => el.classList.remove('drop'));
    el.addEventListener('drop', e => {
      e.preventDefault?.();
      el.classList.remove('drop');
      if (this.prefs.hotbarLocked) { this.log('The hot bar is locked.', 'err'); return; }
      const dt = e.dataTransfer;
      const fromSlot = dt?.getData('application/x-dk-slot');
      const skill = dt?.getData('application/x-dk-skill');
      const item = dt?.getData('application/x-dk-item');
      const txt = dt?.getData('text/plain') || '';
      if (fromSlot !== '' && fromSlot != null) this.swapSlots(Number(fromSlot), s.i);
      else if (skill !== '' && skill != null) this.setSlot(s.i, { type: 'skill', index: Number(skill) });
      else if (item) {
        try { const it = JSON.parse(item); this.setSlot(s.i, { type: 'item', itemIndex: Number(it.itemIndex), name: it.name }); } catch { /* ignore */ }
      }
      else if (/^skill:\d+$/.test(txt)) this.setSlot(s.i, { type: 'skill', index: Number(txt.slice(6)) });
      else if (/^slot:\d+$/.test(txt)) this.swapSlots(Number(txt.slice(5)), s.i);
    });
  }

  /** Put an entry ({type:'skill', index}) in a hot-bar slot (null clears it). */
  setSlot(i, entry) {
    const bar = this._hotbar();
    while (bar.length < HOTBAR_SLOTS) bar.push(null);
    bar[i] = entry ? { ...entry } : null;
    this._hotbarSig = '';
    this.game.events?.emit?.('hotbar', { slot: i, entry: bar[i] });
  }

  swapSlots(a, b) {
    if (a === b || !(a >= 0) || !(b >= 0)) return;
    const bar = this._hotbar();
    while (bar.length < HOTBAR_SLOTS) bar.push(null);
    [bar[a], bar[b]] = [bar[b], bar[a]];
    this._hotbarSig = '';
    this.game.events?.emit?.('hotbar', { slot: b, entry: bar[b] });
  }

  /** Use a hot-bar slot (mouse click). Windows can intercept to assign a picked skill instead. */
  useSlot(i) {
    const g = this.game;
    if (g.windows?.pickedSkill != null) {
      this.setSlot(i, { type: 'skill', index: g.windows.pickedSkill });
      g.windows.pickedSkill = null;
      g.windows.refresh?.('skills');
      g.audio?.ui?.('buttonCommon');
      return true;
    }
    const s = this.slots[i];
    if (!s?.entry || g.player?.dead) return false;
    let ok = false;
    try {
      ok = g.skills?.useSlot ? g.skills.useSlot(i) : g.skills?.use?.(i);
    } catch (err) { console.error(err); }
    if (ok === false && s.skill) {
      // the skill system writes the reason to the log; add the original spoken warning
      const lv = Math.max(1, skillLevel(g, s.skill));
      if ((g.player?.mp ?? 0) < skillMpCost(s.skill, lv)) g.audio?.ui?.('lackOfMana');
    }
    if (ok !== false) s.pressT = 0.18;
    return ok;
  }

  // ---------------------------------------------------------------------------------------- target
  _updateTarget() {
    const g = this.game, E = this.els;
    const t = g.player?.target;
    if (!t || t === g.player || (t.kind === 'monster' && this._deadFor(t) > 1.5)) {
      if (this._targetSig !== 'none') { this._targetSig = 'none'; E.target.style.display = 'none'; }
      return;
    }
    const boss = t.kind === 'monster' && isBoss(t);
    const aggr = isAggressive(t);
    const sig = `${t.id ?? t.name}|${boss}|${aggr}|${t.level}|${t.name}`;
    if (sig !== this._targetSig) {
      this._targetSig = sig;
      E.target.style.display = '';
      toggleClass(E.target, 'boss', boss);
      toggleClass(E.target, 'npc', t.kind === 'npc');
      E.tgtPlate.style.backgroundImage = '';
      E.tgtPlate.classList.remove('art');
      if (boss) atlas.paint(E.tgtPlate, 'pcpop', 128); else atlas.paint(E.tgtPlate, 'pcpop', 1);
      let name = t.name || '';
      if (t.kind === 'npc') {
        const d = npcDef(g, t);
        const js = this._jobStrings?.get(Number(d.desc));
        const nt = npcJobNameTitle(t, js);
        name = nt?.name || name;
        setText(E.tgtLevel, nt?.title || '');
      } else {
        setText(E.tgtLevel, t.level != null ? `Lv ${t.level}` : '');
      }
      setText(E.tgtName, name);
      E.tgtName.style.color = aggr ? '#ff5a45' : '';
      E.tgtLevel.style.color = t.kind === 'monster' && t.level != null ? levelDiffColor(g, t.level) : '';
      toggleClass(E.tgtAggro, 'on', aggr);
    }
    this._renderStatuses(E.tgtStatus, t.statuses, 'buffer', 'buffer_b', false);
    const f = t.maxHp > 0 ? clamp01(t.hp / t.maxHp) : 0;
    setStyle(E.tgtHpFill, 'width', `${Math.round(f * 144)}px`);
    setText(E.tgtHpText, t.kind === 'npc' ? '' : t.maxHp > 0 ? `${fmtInt(Math.max(0, t.hp))} / ${fmtInt(t.maxHp)}` : '');
    toggleClass(E.target, 'dead', !!t.dead || t.hp <= 0);
  }

  /** Seconds since `a` was first seen dead (0 while alive). */
  /**
   * Status icons (skills.js entries {key, name, description, iconIndex, remaining, duration}) as sprites of the
   * imagetable buff groups: player buffs use buffer_b (30x30, ui_buffwnd), target statuses buffer (22x22, ui_targetpop).
   */
  _renderStatuses(box, list, group, fallback, withTime) {
    list = Array.isArray(list) ? list.filter(s => s && !(Number(s.remaining) <= 0)).slice(0, 12) : [];
    const sig = list.map(s => `${s.key ?? s.name}:${s.iconIndex}`).join('|');
    if (box._sig !== sig) {
      box._sig = sig;
      clear(box);
      box._items = [];
      for (const s of list) {
        const icon = h('div', { class: 'dk-st-icon' });
        const time = withTime ? h('div', { class: 'dk-st-time' }) : null;
        const el = h('div', { class: 'dk-st', title: `${s.name || 'Status'}${s.description ? `\n${s.description}` : ''}` }, icon, time);
        if (s.iconIndex != null) {
          atlas.paint(icon, group, s.iconIndex).then(ok => { if (!ok && fallback) return atlas.paint(icon, fallback, s.iconIndex); return ok; })
            .then(ok => { if (!ok) icon.textContent = String(s.name || '?').slice(0, 1); });
        } else icon.textContent = String(s.name || '?').slice(0, 1);
        box.appendChild(el);
        box._items.push({ el, time });
      }
    }
    box._items.forEach((it, i) => {
      const r = Number(list[i]?.remaining);
      if (it.time) setText(it.time, Number.isFinite(r) ? (r >= 60 ? `${Math.ceil(r / 60)}m` : `${Math.ceil(r)}s`) : '');
      toggleClass(it.el, 'ending', Number.isFinite(r) && r < 5);
    });
  }

  _deadFor(a) {
    if (!a?.dead) { this._deadAt.delete(a); return 0; }
    const now = this.game.time ?? performance.now() / 1000;
    if (!this._deadAt.has(a)) this._deadAt.set(a, now);
    return now - this._deadAt.get(a);
  }

  _clearTarget() {
    const p = this.game.player;
    if (!p) return;
    p.target?.setHighlight?.(false);
    p.target = null;
    this.game.events?.emit?.('target', { actor: null });
  }

  // ---------------------------------------------------------------------------------------- floaters / nameplates
  _screen(actor, out) {
    const cam = this.game.camera;
    if (!cam) return null;
    let v = null;
    try { v = actor.headWorldPosition ? actor.headWorldPosition(tmpV) : null; } catch { v = null; }
    if (!v) v = tmpV.set(actor.x || 0, (actor.y || 0) + (actor.height || 2), -(actor.z || 0));
    tmpV2.copy(v).project(cam);
    if (tmpV2.z > 1 || tmpV2.z < -1) return null;
    const W = this._vw, H = this._vh;
    out.x = (this._vx || 0) + (tmpV2.x + 1) * 0.5 * W;
    out.y = (this._vy || 0) + (1 - tmpV2.y) * 0.5 * H;
    return out;
  }

  _updateWorldText(dt) {
    const c = this.game.canvas;
    // HUD runs before WebGLRenderer, which normally refreshes these matrices.
    // Project against this frame's camera, rather than the preceding render.
    this.game.camera?.updateWorldMatrix(true, false);
    // opt-6: getBoundingClientRect() forces a synchronous style + layout pass, and the HUD has dirtied the DOM by now in every
    // frame, so reading it per frame cost a layout per frame (0.1+ ms of the frame). The canvas is `position: fixed; inset: 0;
    // width: 100vw; height: 100vh` (src/ui/style.css #game): its rect only changes with the window / canvas size. It is
    // re-read when the window or the canvas reports a resize and, as a safety net for anything not reported, once per
    // RECT_REFRESH_S of game time. The value read is the same expression as before.
    this._rectAge = (this._rectAge || 0) + dt;
    if (this._rectDirty !== false || this._rectAge >= RECT_REFRESH_S) {
      this._rectAge = 0;
      this._watchViewport(c);
      this._rectDirty = false;
      const rect = c?.getBoundingClientRect?.();
      this._vw = rect?.width || c?.clientWidth || globalThis.innerWidth || 1024;
      this._vh = rect?.height || c?.clientHeight || globalThis.innerHeight || 768;
      this._vx = rect?.left || 0;
      this._vy = rect?.top || 0;
    }
    this._updateFloaters(dt);
    this._updatePlates();
  }

  /** Once: mark the cached canvas rect stale whenever the window or the canvas is resized (see _updateWorldText). */
  _watchViewport(canvas) {
    if (this._viewportWatched) return;
    this._viewportWatched = true;
    this._onViewport = () => { this._rectDirty = true; };
    globalThis.addEventListener?.('resize', this._onViewport);
    try {
      if (canvas && typeof globalThis.ResizeObserver === 'function') {
        this._rectObserver = new globalThis.ResizeObserver(this._onViewport);
        this._rectObserver.observe(canvas);
      }
    } catch { this._rectObserver = null; }
  }

  _updateFloaters(dt) {
    const pt = this._ptTmp || (this._ptTmp = { x: 0, y: 0 });
    for (let i = this._floaters.length - 1; i >= 0; i--) {
      const f = this._floaters[i];
      f.t += dt;
      if (f.t >= f.life) { this._killFloater(f); continue; }
      const alive = f.actor && !gone(f.actor);
      const pos = alive ? this._screen(f.actor, pt) : null;
      if (pos) { if (f.last) { f.last.x = pos.x; f.last.y = pos.y; } else f.last = { x: pos.x, y: pos.y }; }
      if (!f.last) { f.el.style.opacity = '0'; continue; }
      const k = f.t / f.life;
      const rise = f.kind === 'exp' ? 70 : 52;
      const x = f.last.x + f.dx;
      const y = f.last.y - 14 + f.dy - rise * easeOut(k);
      const pop = f.kind === 'crit' ? 1 + 0.6 * Math.max(0, 1 - f.t / 0.15) : 1 + 0.25 * Math.max(0, 1 - f.t / 0.12);
      const a = k < 0.08 ? k / 0.08 : k > 0.65 ? Math.max(0, 1 - (k - 0.65) / 0.35) : 1;
      f.el.style.transform = `translate(${x.toFixed(1)}px, ${y.toFixed(1)}px) translate(-50%, -50%) scale(${pop.toFixed(3)})`;
      f.el.style.opacity = a.toFixed(3);
    }
  }

  _killFloater(f) {
    const i = this._floaters.indexOf(f);
    if (i >= 0) this._floaters.splice(i, 1);
    f.el.style.opacity = '0';
    if (this._floaterPool.length < 40) this._floaterPool.push(f.el); else f.el.remove();
  }

  _updatePlates() {
    const g = this.game, p = g.player;
    // opt-6: the per-frame `new Set()` of the plates seen this frame is a frame stamp on the plate record instead
    const stamp = this._plateStamp = (this._plateStamp || 0) + 1;
    if (g.camera && p) {
      const hoverOnly=this.showNameplates===false||nameplateView(g.options)===2;
      const now = g.time ?? 0;
      const pt = this._ptTmp || (this._ptTmp = { x: 0, y: 0 });
      let actors = [];
      try { actors = g.actors ? g.actors() : []; } catch { actors = []; }
      for (const a of actors) {
        if (!a || gone(a)) continue;
        if (hoverOnly&&this._nameHoverActor!==a&&p.target!==a) continue;
        if (a.group && a.group.visible === false) continue;
        let d = 0;
        if (a !== p) {
          const dx = (a.x || 0) - p.x, dz = (a.z || 0) - p.z;
          if (dx * dx + dz * dz > NAMEPLATE_RANGE_SQ_PAD) continue;   // certainly out of range: skip the hypot (the exact test follows)
          d = Math.hypot(dx, dz);
        }
        if (d > NAMEPLATE_RANGE) continue;
        if (a.kind === 'monster' && this._deadFor(a) > 1.2) continue;
        const pos = this._screen(a, pt);
        if (!pos) continue;
        const pl = this._plate(a);
        pl.seen = stamp;
        const targeted = p.target === a;
        const lastHit = this._damaged.get(a);
        const damaged = a.kind === 'monster' && (a.hp < a.maxHp || (lastHit != null && now - lastHit < 8));
        const showHp = a.kind === 'monster' && (targeted || damaged) && !a.dead;
        toggleClass(pl.el, 'targeted', targeted);
        toggleClass(pl.hpb, 'on', showHp);
        if (showHp) setStyle(pl.fill, 'width', `${(clamp01(a.hp / Math.max(1, a.maxHp)) * 100).toFixed(1)}%`);
        const fade = d > NAMEPLATE_RANGE - 5 ? (NAMEPLATE_RANGE - d) / 5 : 1;
        const opacity = a.dead ? 0.5 : fade;
        if (pl.opacityRaw !== opacity) { pl.opacityRaw = opacity; setStyle(pl.el, 'opacity', opacity.toFixed(2)); }   // opt-6: no toFixed while the number is unchanged
        // written only when it changed: a style write per plate per frame (every actor within 35 units) was a DOM cost that
        // grew with the crowd (2.2.1, measured)
        // opt-6: the string is a pure function of pos.x / pos.y, so it is not even built while those are the same numbers as last frame
        const headGap = nameplateHeadGap(a,g,pos,{top:this._vy||0,height:this._vh});
        if (pl.rawX !== pos.x || pl.rawY !== pos.y || pl.headGap !== headGap) {
          pl.rawX = pos.x; pl.rawY = pos.y;
          pl.headGap = headGap;
          const transform = `translate(${pos.x.toFixed(1)}px, ${(pos.y - headGap).toFixed(1)}px) translate(-50%, -100%)`;
          if (pl.transform !== transform) { pl.transform = transform; pl.el.style.transform = transform; }
        }
        if (pl.hidden) { pl.hidden = false; pl.el.style.display = ''; }   // opt-6: a flag instead of reading el.style.display for every plate every frame
      }
    }
    for (const [a, pl] of this._plates) {
      if (pl.seen === stamp) continue;
      if (gone(a) || !a.group || a.group.parent === null) { this._guildArt?.remove(pl.mark);this._guildArt?.remove(pl.amark);pl.el.remove(); this._plates.delete(a); continue; }
      if (!pl.hidden) { pl.hidden = true; pl.el.style.display = 'none'; }
    }
  }

  /** NPC name + title from script/string/npc/stringtable_job.txt (desc id), once the table is loaded. */
  _npcPlateText(a, pl) {
    const d = npcDef(this.game, a);
    const js = this._jobStrings?.get(Number(d.desc));
    const nt = npcJobNameTitle(a, js);
    if (!this._jobStrings && !nt) return;
    pl.npcResolved = true;
    if (nt?.name) pl.name.textContent = nt.name;
    pl.title.textContent = nt?.title || '';
  }

  _plate(a) {
    const viewerLevel = this.game.save?.level || this.game.player?.level || 1;
    let pl = this._plates.get(a);
    if (pl) {
      if (a.kind === 'player' || a.kind === 'monster') setText(pl.name, a.name || '');
      if (a.kind === 'player') this._playerPlateText(a,pl);
      if (a.kind === 'monster' && (pl.level !== a.level || pl.viewerLevel !== viewerLevel)) {
        pl.level = a.level; pl.viewerLevel = viewerLevel;
        pl.name.style.color = levelDiffColor(this.game, a.level);
      }
      if (a.kind === 'npc' && !pl.npcResolved) this._npcPlateText(a, pl);
      return pl;
    }
    const kindCls = a.kind === 'npc' ? 'npc' : a.kind === 'player' ? 'player' : 'mon';
    pl = {
      el: h('div', { class: `dk-plate ${kindCls}` }),
      name: h('div', { class: 'dk-plate-name', text: a.name || '' }),
      guild: h('div', { class: 'dk-plate-guild' }),
      guildName: h('span'),
      // Original guild mark: guildbg_s background under guildicon_s icon (24 px imagetable cells).
      mark: h('span', { class: 'dk-plate-mark' }, h('i', { class: 'bg' }), h('i', { class: 'icon' })),
      // ALLIANCE: alliance mark + name above the guild line (src/config/engine-chosen-guild.js ALLIANCE_CHOSEN.NAMEPLATE).
      alliance: h('div', { class: 'dk-plate-guild dk-plate-alliance' }),
      allianceName: h('span'),
      amark: h('span', { class: 'dk-plate-mark' }, h('i', { class: 'bg' }), h('i', { class: 'icon' })),
      title: h('div', { class: 'dk-plate-title' }),
      rank: h('div', { class: 'dk-plate-title dk-plate-rank' }),
      hpb: h('div', { class: 'dk-plate-hp' }),
      fill: h('i'),
      level: a.level,
      viewerLevel,
    };
    pl.hpb.appendChild(pl.fill);
    pl.guild.append(pl.mark, pl.guildName);
    pl.alliance.append(pl.amark, pl.allianceName);applyFont(pl.alliance,2);
    applyFont(pl.name, 2);
    applyFont(pl.title, 2);applyFont(pl.rank,2);applyFont(pl.guild,2);
    this._paintPlateFrame(pl);
    if (a.kind === 'npc') {
      this._npcPlateText(a, pl);
      pl.el.append(pl.title, pl.name);
    } else {
      if(a.kind==='player'){this._playerPlateText(a,pl);pl.el.append(pl.alliance,pl.guild,pl.title,pl.rank);}
      pl.el.append(pl.name, pl.hpb);
      if (a.kind === 'monster') {
        pl.name.style.color = levelDiffColor(this.game, a.level);
        if (isBoss(a)) pl.el.classList.add('boss');
      }
    }
    this.els.plates.appendChild(pl.el);
    this._plates.set(a, pl);
    return pl;
  }

  _playerPlateText(a,pl) {
    const info=this._playerNameplateInfo(a),details=playerNameplateDetails(info,this.game.options,this._nameHoverActor===a);
    setText(pl.name,playerNameplateName(a.name,info));
    if(pl.title){setText(pl.title,details.title);setStyle(pl.title,'display',details.title?'':'none');}
    if(pl.rank){setText(pl.rank,details.rank);setStyle(pl.rank,'display',details.rank?'':'none');}
    setText(pl.guildName,info?.guild?.name||'');
    setStyle(pl.guild,'display',details.guild?.name?'':'none');
    setStyle(pl.guild,'color',guildNameCSS(info?.guild?.color));
    const mark=info?.guild?.mark,key=mark?`${mark.bg}:${mark.icon}`:'';
    if(pl.markKey!==key){
      pl.markKey=key;setStyle(pl.mark,'display',key?'':'none');
      const [bg,icon]=pl.mark.children;bg.style.backgroundImage='';icon.style.backgroundImage='';
      if(key){void atlas.paint(bg,'guildbg_s',mark.bg);void atlas.paint(icon,'guildicon_s',mark.icon);}
    }
    const ally=details.alliance;
    setText(pl.allianceName,ally?.name||'');setStyle(pl.alliance,'display',ally?.name?'':'none');
    const amark=ally?.mark,akey=amark?`${amark.bg}:${amark.icon}`:'';
    if(pl.amarkKey!==akey){
      pl.amarkKey=akey;setStyle(pl.amark,'display',akey?'':'none');
      const [bg,icon]=pl.amark.children;bg.style.backgroundImage='';icon.style.backgroundImage='';
      if(akey){void atlas.paint(bg,'guildbg_s',amark.bg);void atlas.paint(icon,'guildicon_s',amark.icon);}
    }
    // Preserve native crest layers; registered native glory items select
    // authored UI sprites. Unavailable art keeps its ordinary static crest.
    if(this.game.items?.db){void this._guildArt?.set(pl.mark,key&&details.guild?.name?info?.guild?.glory:0,{kind:'guild'});void this._guildArt?.set(pl.amark,akey?ally?.glory:0,{kind:'alliance'});}
    setStyle(pl.name,'color',characterNameCSS(info?.nameColor||a.nameColor||a.save?.nameColor));
    const frame=partyNameplateFrame(this.game,a);
    if(pl.frameIndex!==frame){pl.frameIndex=frame;this._paintPlateFrame(pl);}
  }

  _playerNameplateInfo(a) {
    if(a.nameplate)return a.nameplate;
    if(a!==this.game.player)return {};
    const grade=this.game.life?.grade;
    return {title:grade?.title?.()?.Name||'',grade:grade?.current?.()?.name||'',dkTier:this.game.save?.dkTier};
  }

  _nameplateAtPointer() {
    const mouse=this.game.input?.mouse;if(!mouse)return null;
    // Cached projected positions: no DOM measurements/layout work for the crowd.
    let best=null,bottom=-Infinity;
    for(const [a,pl]of this._plates) {
      if(a.kind!=='player'||pl.hidden||gone(a)||!Number.isFinite(pl.rawX))continue;
      const info=playerNameplateDetails(this._playerNameplateInfo(a),this.game.options,this._nameHoverActor===a),lines=[pl.name?.textContent||a.name,info.guild?.name,info.alliance?.name,info.title,info.rank].filter(Boolean);
      const width=Math.min(300,Math.max(60,...lines.map(s=>String(s).length*8+24))),height=lines.length*18+12,y=pl.rawY-(pl.headGap??nameplateHeadGap(a));
      if(Math.abs(mouse.x-pl.rawX)<=width/2&&mouse.y>=y-height&&mouse.y<=y&&y>bottom){best=a;bottom=y;}
    }
    return best;
  }

  _showPlayerNameHover(a) {
    // The nameplate already presents the player's name and guild details on hover.
    // Never open a second floating tooltip for the same character.
    const tip=this.game.uiwin?.tooltips;
    if(this._nameHoverContent&&tip?.el?.firstChild===this._nameHoverContent&&!tip.owner)tip.hide();
    this._nameHoverContent=null;this._nameHoverSig='';
  }

  _paintPlateFrame(pl) {
    const sprite = this._plateFrames?.get(pl.frameIndex||79)||this._plateFrame;
    if (!sprite) return;
    const [l, t, r, b] = sprite.row.m;
    pl.el.style.borderStyle = 'solid';
    pl.el.style.borderWidth = `${t}px ${r}px ${b}px ${l}px`;
    pl.el.style.borderImage = `url("${sprite.url}") ${t} ${r} ${b} ${l} fill / ${t}px ${r}px ${b}px ${l}px stretch`;
    pl.el.classList.add('art');
  }

  // ---------------------------------------------------------------------------------------- minimap
  _mmToTex(x, z) {
    // coords.md: minimap texel (u right, v down) shows FILE X = v, Z = u (transposed), 512 units per texture
    return this._mm.transposed ? { u: z, v: x } : { u: x, v: z };
  }

  _drawMinimap() {
    const g = this.game, E = this.els, mm = this._mm, p = g.player;
    if (p) setText(E.mmPos, `${Math.floor(p.x)}, ${Math.floor(p.z)}`);
    if (this.prefs.minimapHidden) return;
    const cv = E.mmCanvas;
    const ctx = cv.getContext ? cv.getContext('2d') : null;
    if (!ctx) return;
    const S = MINIMAP_SIZE, cx = S / 2, cy = S / 2;
    ctx.clearRect(0, 0, S, S);
    if (!p) return;
    const k = MINIMAP_ZOOMS[this.prefs.minimapZoom ?? 2] || 1;
    const P = this._mmToTex(p.x, p.z);
    const toScreen = (x, z) => { const t = this._mmToTex(x, z); return { x: cx + (t.u - P.u) * k, y: cy + (t.v - P.v) * k }; };
    if (mm.tex?.canvas) {
      const span = mm.size * k;
      ctx.imageSmoothingEnabled = k < 1;
      ctx.drawImage(mm.tex.canvas, 0, 0, mm.tex.width, mm.tex.height, cx - P.u * k, cy - P.v * k, span, span);
    }
    // camera view cone (#35), rotated to the camera heading
    const cam = g.camera;
    if (cam?.getWorldDirection) {
      cam.getWorldDirection(tmpV);
      const fx = tmpV.x, fz = -tmpV.z; // THREE -> FILE
      const d = this._mmToTex(fx, fz);
      const ang = Math.atan2(d.u, -d.v);
      const spr = this._mmSprites?.camera;
      ctx.save();
      ctx.translate(cx, cy);
      ctx.rotate(ang);
      if (spr) { ctx.globalAlpha = 0.55; ctx.drawImage(spr, -spr.width / 2, -spr.height + 6, spr.width, spr.height); }
      else {
        ctx.fillStyle = 'rgba(255,255,255,0.16)';
        ctx.beginPath(); ctx.moveTo(0, 0); ctx.lineTo(-26, -44); ctx.lineTo(26, -44); ctx.closePath(); ctx.fill();
      }
      ctx.restore();
    }
    // monsters (red), NPCs (by minimapColor)
    const dot = (key, x, y, color, r) => {
      if (x < -6 || y < -6 || x > S + 6 || y > S + 6) return;
      const spr = this._mmSprites?.[key];
      if (spr) ctx.drawImage(spr, Math.round(x - 3), Math.round(y - 3), 6, 6);
      else { ctx.fillStyle = color; ctx.beginPath(); ctx.arc(x, y, r, 0, Math.PI * 2); ctx.fill(); }
    };
    let monsters = [];
    try { monsters = g.spawner?.monsters || []; } catch { monsters = []; }
    for (const m of monsters) {
      if (!m || m.dead) continue;
      const s = toScreen(m.x, m.z);
      dot('dot1', s.x, s.y, '#ff3a2a', 2.2);
    }
    for (const n of g.npcs || []) {
      const s = toScreen(n.x, n.z);
      const c = Number(npcDef(g, n).minimapColor) || 0;
      if (s.x < -6 || s.y < -6 || s.x > S + 6 || s.y > S + 6) continue;
      const spr = this._mmSprites?.[`dot${Math.max(0, Math.min(7, c === 0 ? 5 : c))}`];
      if (spr) ctx.drawImage(spr, Math.round(s.x - 4), Math.round(s.y - 4), 8, 8);
      else { ctx.fillStyle = '#ffe24a'; ctx.fillRect(s.x - 2.5, s.y - 2.5, 5, 5); }
    }
    // the player arrow (#30), pointing along the facing
    const fx = -Math.sin(p.yaw || 0), fz = -Math.cos(p.yaw || 0);
    const d = this._mmToTex(fx, fz);
    const ang = Math.atan2(d.u, -d.v);
    ctx.save();
    ctx.translate(cx, cy);
    ctx.rotate(ang);
    const arrow = this._mmSprites?.arrow;
    if (arrow) ctx.drawImage(arrow, -arrow.width / 2, -arrow.height / 2, arrow.width, arrow.height);
    else {
      ctx.fillStyle = '#ff2a1a'; ctx.strokeStyle = '#000';
      ctx.beginPath(); ctx.moveTo(0, -8); ctx.lineTo(6, 6); ctx.lineTo(0, 3); ctx.lineTo(-6, 6); ctx.closePath(); ctx.fill(); ctx.stroke();
    }
    ctx.restore();
  }

  _toggleMinimap() {
    this.prefs.minimapHidden = !this.prefs.minimapHidden;
    saveLocal(LS_UI, this.prefs);
    this._applyMinimapHidden();
    this._paintMinimapToggle();
    this.game.audio?.ui?.('buttonCommon');
  }

  _applyMinimapHidden() {
    toggleClass(this.els.minimap, 'collapsed', !!this.prefs.minimapHidden);
    toggleClass(this.els.help, 'mm-collapsed', !!this.prefs.minimapHidden);
  }

  // ---------------------------------------------------------------------------------------- cursor
  _updateCursor(dt) {
    const c = this.cursor, g = this.game;
    if (!c) return;
    this._timers.cursor -= dt;
    if (this._timers.cursor <= 0) {
      this._timers.cursor = 0.1;
      const inp = g.input;
      let kind = 'normal',hover=null;
      // Turning the camera keeps the normal arrow (the grip glove is the item-pickup cursor, not a camera cursor).
      if (inp?.dragging?.right || inp?.dragging?.middle || inp?.held?.right) kind = 'normal';
      else if (inp && inp.mouseOverCanvas !== false && g.pickActor && g.camera && g.world) {
        let a = null, drop = null;
        // A ground item under the pointer: the original grip (hand) cursor (mouse.csv 'grip' = cursorgrip.tpack = cursor_05-1/2.dds). The
        // test is the click's own (controller._press tries loot.pickAt before any actor), so the hand shows exactly where a click would
        // pick the item up. A window over it never gets here (mouseOverCanvas), a UI drag in progress or a modal window changes nothing.
        if (g.loot?.drops?.length && !g.uiwin?.dnd?.cur && !g.uiwin?.modalOpen) { try { drop = g.loot.pickAt?.({ x: inp.mouse.nx, y: inp.mouse.ny }) || null; } catch { drop = null; } }
        if (drop) kind = 'grip';
        else { try { a = g.pickActor({ x: inp.mouse.nx, y: inp.mouse.ny }); } catch { a = null; } }
        if(a?.kind==='player')hover=a;
        hover=this._nameplateAtPointer()||hover;
        if ((a?.kind === 'monster' && !a.dead) || (a?.kind === 'player' && a !== g.player && !a.dead && g.isPvpHostile?.(a))) kind = 'attack';   // monsters and hostile players (Ctrl = Force Attack on a PK field)
        else if (a?.kind === 'npc') kind = 'talk';
      }
      this._nameHoverActor=hover;this._showPlayerNameHover(hover);c.set(kind);
    }
    c.update(dt);
  }

  // ---------------------------------------------------------------------------------------- timers (toast / flash)
  _updateTimers(dt) {
    const E = this.els;
    const t = this._toast;
    if (t) {
      t.t += dt;
      const a = t.t < 0.35 ? t.t / 0.35 : t.t > t.life - 0.8 ? Math.max(0, (t.life - t.t) / 0.8) : 1;
      E.toast.style.opacity = a.toFixed(3);
      if (t.t >= t.life) { E.toast.style.display = 'none'; this._toast = null; }
    }
    if (this._flash > 0) {
      this._flash -= dt;
      const k = Math.max(0, this._flash / 2.2);
      E.flash.style.opacity = (k > 0.85 ? (1 - k) / 0.15 : k / 0.85).toFixed(3);
      if (this._flash <= 0) E.flash.style.display = 'none';
    }
  }

  // ---------------------------------------------------------------------------------------- chat
  _setChatFilter(f) {
    this.prefs.chatFilter = f;
    saveLocal(LS_UI, this.prefs);
    this.els.chat.dataset.filter = f;
    for (const b of this.els.chatTabs.children) toggleClass(b, 'on', b.dataset.f === f);
    this._scrollChat();
  }

  _scrollChat() { this._chatScrollPending=true; }
  _flushChatScroll() {
    if(!this._chatScrollPending)return;
    this._chatScrollPending=false;
    const l=this.els.chatLines;l.scrollTop=l.scrollHeight;
  }

  _chatKey(e) {
    const inp = this.els.chatInput;
    if (e.key === 'Enter') {
      e.preventDefault?.();
      const text = inp.value.trim();
      inp.value = '';
      if (text) {
        const handled = this.game.chatCommand?.(text);
        if (!handled) {
          if (text.startsWith('/')) this._slashCommand(text);
          else this.log(`${this.game.player?.name || this.game.save?.name || 'You'}: ${text}`, 'chat');
        }
      }
      inp.blur?.();
      this.els.chat.classList.remove('typing');
    } else if (e.key === 'Escape') {
      e.preventDefault?.();
      inp.value = '';
      inp.blur?.();
      this.els.chat.classList.remove('typing');
    }
    e.stopPropagation?.();
  }

  _slashCommand(text) {
    const [cmd] = text.slice(1).split(/\s+/);
    const g = this.game;
    switch ((cmd || '').toLowerCase()) {
      case 'help': this.log('Commands: /help, /pos, /fps, /clear', 'sys'); break;
      case 'pos': if (g.player) this.log(`${g.world?.info?.name || ''} (${g.player.x.toFixed(1)}, ${g.player.z.toFixed(1)})`, 'sys'); break;
      case 'fps': g.setSettings?.({ showFps: g.settings?.showFps !== true }); g.events?.emit?.('settings', g.settings); break;
      case 'clear': for (const l of this._log) l.remove?.(); this._log = []; break;
      default: this.log(`Unknown command: ${text}`, 'err');
    }
  }

  _toggleHelp() {
    this.prefs.helpCollapsed = !this.prefs.helpCollapsed;
    saveLocal(LS_UI, this.prefs);
    toggleClass(this.els.help, 'collapsed', this.prefs.helpCollapsed);
  }

  dispose() {
    this._chatScrollPending=false;
    for (const off of this._off) { try { off?.(); } catch { /* ignore */ } }
    this._off = [];
    globalThis.removeEventListener?.('keydown', this._onKey);
    if (this._onViewport) globalThis.removeEventListener?.('resize', this._onViewport);
    this._rectObserver?.disconnect?.();
    this.game.canvas?.removeEventListener?.('mousedown', this._onCanvasDown);
    if(this._nameHoverContent&&this.game.uiwin?.tooltips?.el?.firstChild===this._nameHoverContent)this.game.uiwin.tooltips.hide();
    this.root.remove();
    this.top.remove();
    if (this.game.canvas?.style) this.game.canvas.style.cursor = '';
    this._plates.clear();
    this._guildArt?.dispose();
    this._floaters = [];
  }
}

function helpLine(k, v) {
  return h('div', { class: 'dk-help-line' }, h('b', { text: k }), h('span', { text: v }));
}

function easeOut(k) { return 1 - (1 - k) * (1 - k); }

/** Inventory entry for a hot-bar item ({type:'item', itemIndex, uid?}). */
function findItem(game, e) {
  const inv = game?.save?.inventory || [];
  return inv.find(x => x && ((e.uid && x.uid === e.uid) || (e.itemIndex != null && Number(x.itemIndex) === Number(e.itemIndex)))) || null;
}
/** Total count of that item in the bag. */
function itemCount(game, e) {
  let n = 0;
  for (const x of game?.save?.inventory || []) {
    if (x && ((e.itemIndex != null && Number(x.itemIndex) === Number(e.itemIndex)) || (e.uid && x.uid === e.uid))) n += Number(x.count) || 1;
  }
  return n;
}

/** Actor removed from the world (actors set .disposed; mocks may use ._disposed). */
function gone(a) { return !!(a.disposed || a._disposed); }
