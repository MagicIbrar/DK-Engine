import {beltEntry} from '../items/belt.js';
import {ownedLifeBead} from '../items/life-bead-rules.js';
// hud-options: the in-game interface shell of the original client, rebuilt from its own window scripts through the
// UI platform (docs/UIWIN.md), plus the Option window with every tab, the key map, chat and help. docs/HUD_OPTIONS.md.
//
//   HUD windows (hud band, never closed by Esc): hud_hp, hud_quickslot, hud_itembelt, hud_mainmenu (EXP bar + menu),
//   hud_target (+ hud_bosshp), hud_buff / hud_skillbuff / hud_debuff, hud_minimap, hud_chat, hud_sysmsg, hud_status,
//   hud_maptitle, hud_eventline, hud_server, hud_localtime, hud_reception, hud_helpalarm
//   windows: settings (system menu, Esc), options (Option window), keymap, map (big map, M), chatoption, chatcolor,
//   channels, systemwait, death, help, guide, contentsguide, contents, tutorialbasic, mp3player (MP3 Player option)
//   option hooks into other systems: optfx.js (+ trace.js weapon trace, waterfx.js water ripples / floor reflection)
//   public APIs: game.options (settings.js), game.keymap (keymap.js), game.chat (chat.js: system / say /
//   registerCommand / openInput), game.emote(motion, type), game.minimap.setMarker/removeMarker,
//   game.quickslot (get/set/use/rotate), game.hudOptions (the context object)
// The old DOM HUD (src/ui/hud.js) keeps its public API (log, floater, toast, showDeath, setMinimap, nameplates);
// its panels are hidden and its calls are routed to the original windows.
import * as THREE from 'three';
import { OptionStore } from './settings.js';
import {nextNameplateView} from '../../game/nameplate-view.js';
import { KeyMap, ACTIONS, ACTION_BY_ID, bindingName } from './keymap.js';
import { OptionEffects } from './apply.js';
import { registerOptionWindow } from './optionwin.js';
import { registerKeymapWindow } from './keymapwin.js';
import { dispatchCameraToggle } from './camera-controls.js';
import { registerHpWindow, registerMainMenu, registerTargetWindow, registerBossBar, registerBuffWindows } from './hudwins.js';
import { registerQuickSlots, quickState } from './quickslot.js';
import { registerMinimap, registerWorldMap } from './minimap.js';
import { Chat, registerChatWindows, makeEmote } from './chat.js';
import {itemPickupText, dilPickupText} from './chat-notice-colors.js';
import { installSuperChat } from './superchat.js';
import { installChatLinks } from './chat-links.js';
import { registerNotices } from './notices.js';
import { registerSystemMenu } from './sysmenu.js';
import { registerHelpWindows, renderRich } from './help.js';
import { DamageNumbers } from './floaters.js';
import { ChatBubbles } from './bubbles.js';
import { takeScreenshot } from './screenshot.js';
import { OptionHooks } from './optfx.js';
import { registerMp3Player } from './mp3.js';
import { registerPresets } from './presets.js';
import { installMainbarExtras } from './mainbar-extras.js';
import { fetchJSON, fetchText } from '../../engine/assets.js';
import { isAggressive } from '../../ui/gameinfo.js';
import { str, plainMarkup, plainText, needStrings, fmtInt, clamp } from './util.js';
import { installAutoHunt } from './autohunt.js';
import { updateDropNames, disposeDropNames } from './dropnames.js';
import { resetAnimState } from '../../game/combat.js';

const HUD_WINDOWS = ['hud_mainmenu', 'hud_hp', 'hud_quickslot', 'hud_itembelt', 'hud_target', 'hud_buff', 'hud_skillbuff',
  'hud_debuff', 'hud_minimap', 'hud_chat', 'hud_sysmsg', 'hud_status', 'hud_server', 'hud_population', 'hud_localtime', 'hud_reception', 'hud_helpalarm', 'hud_presetmini'];

let ctx = null;

export async function install(game) {
  if (!game.uiwin) throw new Error('hud-options needs the UI platform (game.uiwin)');
  ctx = { game, tmpV: new THREE.Vector3(), timers: [], owned: new WeakSet(), deadAt: new WeakMap() };
  game.hudOptions = ctx;

  // strings used synchronously by the windows (option, keymap, chat, tooltips, pc messages, maintoolbar)
  await needStrings([
    ['NORMAL', 2001, 0], ['NORMAL', 2200, 0], ['NORMAL', 2201, 0], ['NORMAL', 2202, 1], ['NORMAL', 230, 1], ['NORMAL', 22, 1],
    ['NORMAL', 40, 1], ['NORMAL', 231, 1], ['NORMAL', 50, 1], ['NORMAL', 120, 1], ['NORMAL', 1006, 48], ['NORMAL', 130, 23],
    ['NORMAL', 140, 107], ['NORMAL', 1008, 21], ['NORMAL', 370, 59], ['NORMAL', 2400, 1],
    ['NORMAL', 2000, 124], ['NORMAL', 260, 43], ['NORMAL', 260, 53],
  ]).catch(err => console.warn('[hud-options] strings', err));

  // ---------------------------------------------------------------- stores
  ctx.options = game.options = new OptionStore(game);
  ctx.keymap = game.keymap = new KeyMap(game);
  ctx.keymap.install(game.input);
  wireHotkeys(game);
  ctx.effects = new OptionEffects(game, ctx.options);
  ctx.shake = (a, d) => ctx.effects.shake(a, d);
  ctx.chat = new Chat(game, ctx);
  game.chat = ctx.chat;
  ctx.emote = game.emote = makeEmote(game, ctx);
  ctx.renderRich = renderRich;
  ctx.numbers = new DamageNumbers(game, ctx);
  ctx.bubbles = new ChatBubbles(game);
  installHelpers(game);

  // ---------------------------------------------------------------- windows
  registerOptionWindow(game, ctx);
  registerKeymapWindow(game, ctx);
  registerSystemMenu(game, ctx);
  registerHpWindow(game, ctx);
  registerMainMenu(game, ctx);
  registerTargetWindow(game, ctx);
  registerBossBar(game, ctx);
  registerBuffWindows(game, ctx);
  installMainbarExtras(game, ctx);   // MAINBAR monster quickslot + transformed body, spell count, upkeep status
  registerQuickSlots(game, ctx);
  registerMinimap(game, ctx);
  registerWorldMap(game, ctx);
  registerChatWindows(game, ctx);
  ctx.superchat = installSuperChat(game, ctx);   // Megaphone input + broadcast band
  ctx.chatLinks = installChatLinks(game, ctx);   // CHAT-LINKS item links + ItemLinktooltipwnd / ui_itemlinkpreview
  registerNotices(game, ctx);
  registerHelpWindows(game, ctx);
  ctx.mp3 = registerMp3Player(game, ctx);
  ctx.presets = registerPresets(game, ctx);
  ctx.hooks = new OptionHooks(game, ctx);
  ctx.autoHunt = installAutoHunt(game);
  game.uiwin.registerMenuButton('btn_escoption', 'settings');
  game.uiwin.registerMenuButton('btn_map', 'map');

  takeOverOldHud(game);
  wireEvents(game);
  for (const w of HUD_WINDOWS) game.uiwin.open(w).catch(err => console.error(`[hud-options] ${w}`, err));
  // new characters get the tips of the client (stringtable_poptip) once
  game.events?.on?.('map', () => {
    const s = game.save;
    if (s && !s.tutorialStep && (Number(s.level) || 1) <= 1) { s.tutorialStep = '1:1'; setTimeout(() => game.uiwin.open('tutorialbasic', { cate: 1, code: 1 }), 2500); }
  });
}

export function update(dt, game) {
  if (!ctx) return;
  ctx.frameMs = ctx.frameMs ? ctx.frameMs * 0.95 + dt * 1000 * 0.05 : dt * 1000;
  for (let i = ctx.timers.length - 1; i >= 0; i--) { const t = ctx.timers[i]; t.t -= dt; if (t.t <= 0) { ctx.timers.splice(i, 1); try { t.fn(); } catch (err) { console.error(err); } } }
  dispatchKeys(game);
  ctx.autoHunt?.update(dt);
  try { ctx.mainbarExtras?.update(dt); } catch (err) { console.error('[mainbar]', err); }
  mouseActions(game);
  autoPotion(game, dt);
  ctx.numbers.update(dt);
  // Game updates speech once after the current camera and HUD nameplates.
  ctx.hooks?.update(dt);
  updateDropNames(game, ctx);
  walkMode(game);
  // sitting ends when anything else (moving, attacking, being hit) takes over the animation
  const pl = game.player;
  if (pl?._sitting && pl._gpState !== 'sit' && pl._gpState !== 'sitDown') pl._sitting = false;
}

export function dispose() {
  disposeDropNames(ctx?.game, ctx);
  ctx?.game?.serverControl?.dispose?.();
  ctx?.effects?.dispose();
  ctx?.numbers?.dispose();
  ctx?.bubbles?.dispose();
  ctx?.hooks?.dispose();
  ctx?.autoHunt?.dispose();
  ctx?.mainbarExtras?.dispose?.();
  ctx?.mp3?.audio?.pause();
  ctx = null;
}

// ============================================================================================ helpers
/** Native death-item hooks, shared by the HUD installer and focused original-UI acceptance. */
export function installDeathItemHelpers(game,helpers){
  helpers.findReviveItem = (blessed = false, now = Date.now()) => (game.save?.inventory || []).find(item => {
    const owned=ownedLifeBead(game.save,game.items?.db||game.items,item?.uid,now);
    return owned&&owned.rule.blessed===blessed;
  }) || null;
  helpers.consumeItem = (it) => {
    if(game.save?.authority==='server'||game.network?.active)return false;
    if(typeof game.items?.consume==='function')return game.items.consume(it,1);
    if (typeof game.inventory?.consume === 'function') return game.inventory.consume(it.uid ?? it.itemIndex, 1);
    it.count = (Number(it.count) || 1) - 1;
    if (it.count <= 0) { const inv = game.save.inventory; inv.splice(inv.indexOf(it), 1); }
    return true;
  };
  helpers.reviveHere = (ratio = 1, mpRatio = ratio) => {
    if(game.save?.authority==='server'||game.network?.active)return false;
    const p = game.player;
    if (!p||!p.dead) return false;
    p.dead = false;
    p.hp = Math.max(1, Math.round(p.maxHp * ratio));
    p.mp = Math.round(p.maxMp * mpRatio);
    p.play?.('revive', { loop: false });
    game.events?.emit?.('revive', { actor: p, inPlace: true });
    return true;
  };
}

function installHelpers(game) {
  ctx.later = (sec, fn) => ctx.timers.push({ t: sec, fn });
  ctx.clearTarget = () => { if (game.controller?.setTarget) game.controller.setTarget(null); else if (game.player) game.player.target = null; };
  ctx.deadFor = (a) => { if (!a?.dead) { ctx.deadAt.delete(a); return 0; } const now = game.time || 0; if (!ctx.deadAt.has(a)) ctx.deadAt.set(a, now); return now - ctx.deadAt.get(a); };
  ctx.ownedBy = (m) => ctx.owned.has(m);
  ctx.bossBar = (t) => {
    const w = game.uiwin.window('hud_bosshp');
    if (t) { if (!w?.isOpen) game.uiwin.open('hud_bosshp').then(win => { win.data.target = t; win.control('lbl_name').setText(t.name || ''); }); else if (w.data.target !== t) { w.data.target = t; w.control('lbl_name').setText(t.name || ''); } }
    else if (w?.isOpen) game.uiwin.close('hud_bosshp');
  };
  ctx.cancelStatus = (s) => {
    const p = game.player;
    if (!p || s.debuff) return;
    // shared play: the host owns the statuses (server/world/skills.mjs statusCancel)
    if (game.network?.active) { if (s.key != null) Promise.resolve(game.network.action('statusCancel', { key: String(s.key) })).catch(err => ctx.chat?.system?.(err?.message || String(err), 'err')); return; }
    if (typeof game.skills?.removeStatus === 'function') { game.skills.removeStatus(p, s.key ?? s.name); return; }
    for (const list of [p.statuses, game.save?.buffs]) if (Array.isArray(list)) { const i = list.indexOf(s); if (i >= 0) list.splice(i, 1); }
    game.events?.emit?.('statuses', { actor: p });
  };
  ctx.travel = () => (ctx._travel ||= fetchJSON('/gamedata/dungeons_travel.json').catch(() => null));
  // ---- items (the items system may provide richer APIs; loot.js entries otherwise)
  ctx.itemCount = (e) => {
    const idx=Number(e?.itemIndex),owned=[...(game.save?.inventory||[]),...(game.save?.potionBelt||[])];
    if(e?.uid){const entries=owned.filter(x=>x.uid===e.uid);return entries.length===1?Number(entries[0].count)||1:0;}
    return owned.filter(x=>Number(x.itemIndex)===idx).reduce((n,x)=>n+(Number(x.count)||1),0);
  };
  ctx.itemName = (e) => {
    const idx = Number(e?.itemIndex);
    try { const n = game.items?.name?.(idx) ?? game.items?.def?.(idx)?.name; if (n) return n; } catch { /* fall back */ }
    return e?.name || (game.save?.inventory || []).find(x => Number(x?.itemIndex) === idx)?.name || game.loot?.consumables?.get(idx)?.name || `Item ${idx}`;
  };
  ctx.itemIcon = async (e, w, h) => {
    const idx = Number(e?.itemIndex);
    for (const [o, f] of [[game.items, 'iconURL'], [game.items, 'icon'], [game.inventory, 'iconURL'], [game.inventory, 'icon']]) {
      if (typeof o?.[f] !== 'function') continue;
      try { const r = await o[f](idx, w, h); if (r) return typeof r === 'string' ? { url: r } : r; } catch { /* next */ }
    }
    return null;
  };
  installDeathItemHelpers(game,ctx);
  ctx.badWord = null;
  loadChatFilter();
  // ---- quick slots
  ctx.quick = game.quickslot = {
    armed: null,
    get(set, i) { return quickState(game)?.sets[set]?.[i] || null; },
    set(set, i, entry) {
      const q = quickState(game); if (!q) return;
      if (!entry && q.locked) { ctx.chat.system(str(231, 7)); return; }
      q.sets[set][i] = entry ? { ...entry } : null;
      this.changed();
      game.events?.emit?.('hotbar', { set, slot: i, entry: q.sets[set][i] });
    },
    changed() { const q = quickState(game); if (q) game.save.hotbar = q.sets[q.rowSet[0]]; },
    /** Use the slot of a displayed row (control type A arms it instead). */
    useCell(r, i, fromKey = false) {
      const q = quickState(game); if (!q || r >= q.rows) return false;
      const e = q.sets[q.rowSet[r]][i];
      if (!e) return false;
      // Presentation only: casting/arming remains controlled by the existing paths.
      if (e.type === 'skill') this.selected = { r, i, set: q.rowSet[r], index: Number(e.index) };
      if (fromKey && ctx.options.get('controlType') === 0 && e.type === 'skill') { this.armed = { r, i }; return true; }
      return this.useEntry(e);
    },
    useEntry(e) {
      if (!e || game.player?.dead) return false;
      // 2k: a greyed skill does nothing when pressed - no cast attempt, so no message / sound spam either.
      if (e.type === 'skill') {
        let usable = true;
        try { usable = game.skills?.usability?.(e.index)?.ok !== false; } catch { usable = true; }
        if (!usable) { this.armed = null; return false; }
      }
      let ok = false;
      try { ok = game.skills?.use?.(e.type === 'skill' ? { skillIndex: e.index } : e); } catch (err) { console.error(err); }
      if (ok === false && e.type === 'skill') game.audio?.ui?.('lackOfMana');
      if (e.type === 'skill') this.armed = null;
      return ok;
    },
    useBelt(i) { const e = beltEntry(game.save,i);return e?game.items?.use?.(e):false; },
    rotate(dir) {
      const q = quickState(game); if (!q) return;
      if (q.rows <= 1) return;
      const rows = [...Array(q.rows).keys()].filter(r => !q.fixed[r]);
      if (rows.length < 2) return;
      const sets = rows.map(r => q.rowSet[r]);
      const rot = dir > 0 ? [sets[sets.length - 1], ...sets.slice(0, -1)] : [...sets.slice(1), sets[0]];
      rows.forEach((r, k) => { q.rowSet[r] = rot[k]; });
      this.changed();
      game.audio?.ui?.('buttonCommon');
    },
    firstFree(set = null) { const q = quickState(game); const s = set ?? q.rowSet[0]; return q.sets[s].indexOf(null); },
  };
  // the old API (windows.js double-click, skills/items systems): hud.setSlot(i, entry) = the bottom row's slot i
  if (game.hud) {
    game.hud.setSlot = (i, entry) => { const q = quickState(game); if (q) ctx.quick.set(q.rowSet[0], i, entry); };
    game.hud.useSlot = (i) => ctx.quick.useCell(0, i);
  }
  ctx.menuFallback = (id, action) => {
    if (id === 'btn_cash' || id === 'btn_vipshop' || id === 'btn_cashinven' || id === 'btn_supplymachine' || id === 'btn_single_supplymachine' || id === 'btn_none') {
      const names = { btn_cash: 'dshop', btn_vipshop: 'vipshop', btn_cashinven: 'cashinventory', btn_supplymachine: 'supplymachine', btn_single_supplymachine: 'orbis' };
      const n = names[id];
      if (n && game.uiwin.has(n)) game.uiwin.toggle(n);
      else if (id !== 'btn_none') ctx.chat.system(`${plainText(game.uiwin.window('hud_mainmenu')?.control(id)?.tooltip?.() || '') || id.replace('btn_', '')}`, 'err');
      return;
    }
    runAction(game, ACTION_BY_ID.get(action));
  };
  ctx.system = (t, k) => ctx.chat.system(t, k);
  // world balloon over the speaker (script/ui/game2/ui_chatbubble.txt: pcpop#100 frame, bubbles.js)
  ctx.bubble = (text, type = 'normal', actor = null) => {
    ctx._bubble = { text: String(text), t: 6 };
    ctx.bubbles?.show(actor || game.player, text, type);
  };
}

async function loadChatFilter() {
  try {
    const t = await fetchText('script/filter/chatfilter.txt', true);
    const words = t.split(/\r?\n/).map(s => s.trim()).filter(s => s && !s.startsWith('//') && s.length > 1);
    ctx.badWord = (msg) => { const m = msg.toLowerCase(); return words.find(w => m.includes(w.toLowerCase())) || null; };
  } catch { /* no filter */ }
}

// ============================================================================================ key map plumbing
function wireHotkeys(game) {
  const mgr = game.uiwin, km = ctx.keymap;
  // uiwin tests its own (bound) codes on the raw keys
  const origHandle = mgr.handleKeys.bind(mgr);
  mgr.handleKeys = (inp) => km.bypass(() => origHandle(inp));
  // window actions: other systems' hotkeys at the action's default key follow the binding
  const owners = new Map();   // action id -> Set(hotkey names)
  ctx.hotkeyOwners = owners;
  // window actions and the menu-button actions other systems may also hotkey (J mount, T pet: mounts/windows.js)
  const winActions = ACTIONS.filter(isHotkeyAction);
  const actionForDefault = (code) => winActions.find(a => a.def && a.def === code);
  const origReg = mgr.registerHotkey.bind(mgr);
  const sync = (a) => {
    const spec = km.get(a.id) || 'Unbound';
    const names = owners.get(a.id) || new Set();
    for (const n of names) {
      if (n === `km:${a.id}`) continue;
      mgr.keyOverrides[n] = spec;
      origReg(spec, findAction(n), { name: n });
    }
    // our own fallback only when nobody else handles the action
    const mine = `km:${a.id}`;
    const others = [...names].some(n => n !== mine);
    for (const list of mgr.hotkeys.values()) for (let i = list.length - 1; i >= 0; i--) if (list[i].name === mine) list.splice(i, 1);
    if (!others && spec !== 'Unbound') { origReg(spec, () => runAction(game, a), { name: mine }); names.add(mine); owners.set(a.id, names); }
  };
  const findAction = (name) => { for (const list of mgr.hotkeys.values()) for (const h of list) if (h.name === name) return h.action; return name; };
  mgr.registerHotkey = (code, action, opts = {}) => {
    const name = opts.name ?? (typeof action === 'string' ? action : '');
    const a = !String(name).startsWith('km:') ? actionForDefault(code) : null;
    if (a && name) {
      if (!owners.has(a.id)) owners.set(a.id, new Set());
      owners.get(a.id).add(name);
      const bound = km.get(a.id) || 'Unbound';
      if (bound !== code) mgr.keyOverrides[name] = bound;
      const r = origReg(code, action, opts);
      sync(a);
      return r;
    }
    return origReg(code, action, opts);
  };
  // hotkeys registered before us
  for (const list of [...mgr.hotkeys.values()]) for (const h of list.slice()) {
    const a = actionForDefault(h.def);
    if (a && h.name) { if (!owners.has(a.id)) owners.set(a.id, new Set()); owners.get(a.id).add(h.name); }
  }
  for (const a of winActions) sync(a);
  km.on('change', (id) => { for (const a of winActions) if (!id || id === a.id) sync(a); });
}

/** Actions dispatched as uiwin hotkeys (followed by other systems' hotkeys at the same default key). */
function isHotkeyAction(a) { return !!a?.id && (a.kind === 'win' || (a.kind === 'act' && !!a.menu)); }

/** Run a key-map action that is not an engine key (see keymap.js). */
function runAction(game, a) {
  if (!a) return;
  const mgr = game.uiwin, p = game.player;
  game.events?.emit?.('keyaction', { id: a.id });
  if (a.kind === 'win') {
    if (a.menu && mgr.hasMenuButton(a.menu)) { mgr.menuAction(a.menu); return; }
    if (a.win && mgr.has(a.win)) { mgr.toggle(a.win); return; }
    if (a.win && ['character', 'skills', 'inventory', 'map'].includes(a.win)) { game.windows?.toggle?.(a.win); return; }
    if (a.id === 'autohunt') { game.uiwin.toggle('autohunt'); return; }
    ctx.chat.system(`${plainText(str(2200, a.code)).trim()}: ${str(40, 51) || 'You cannot use this item for now.'}`.replace(/item/, 'function'), 'err');
    return;
  }
  if (a.kind === 'emote') {
    const sitting = game.life?.emotes ? game.life.emotes.sitting : p?._sitting;
    ctx.emote(a.motion, a.motion === 1 ? (sitting ? 2 : 1) : 0);
    return;
  }
  switch (a.id) {
    case 'names': ctx.options.set(nextNameplateView(ctx.options)); break;
    case 'chat': ctx.options.set({ chatVisible: ctx.options.get('chatVisible') === false }); break;
    // R mid-move: forget the tracked locomotion state so the next frame re-plays it (run <-> walk clip, walkMode below)
    case 'walk': ctx.walk = !ctx.walk; if (p?._gpState === 'run') resetAnimState(p); break;
    case 'ride': case 'petsummon': case 'fishing':
      if (a.menu && mgr.hasMenuButton(a.menu)) mgr.menuAction(a.menu);
      break;
    case 'autoattack': { const t = p?.target; if (t && t.kind === 'monster' && !t.dead) game.controller?.attack?.(t); break; }
    case 'autohuntstart': game.autoHunt?.toggle?.(); break; // native keymap304.
    case 'hotkeyitem': void game.autoHunt?.hotkeyItems?.(); break; // native keymap317 + autohunt370:64.
    case 'selftarget':
      if (p) { try { p.target?.setHighlight?.(false); } catch { /* ignore */ } p.target = p; game.events?.emit?.('target', { actor: p }); }
      break;
    case 'controlA': case 'controlB': {
      const t = a.id === 'controlA' ? 0 : 1;
      ctx.options.set({ controlType: t });
      ctx.chat.system(str(40, t === 0 ? 12 : 13));
      break;
    }
    case 'setup': ctx.quick.rotate(1); break;
    case 'setdown': ctx.quick.rotate(-1); break;
    case 'npctalk': {
      let best = null, bd = 12;
      for (const n of game.npcs || []) { const d = Math.hypot(n.x - p.x, n.z - p.z); if (d < bd) { bd = d; best = n; } }
      const c = game.controller;
      if (best && c) { c.stop?.(); c.order = { type: 'npc', npc: best, path: c._findPath?.(best.x, best.z) || null, i: 0 }; }
      break;
    }
    case 'screenshot': takeScreenshot(game, ctx); break;
    case 'weaponswap': ctx.presets?.weaponSwap(); break;
    case 'equipswap': ctx.presets?.nextPreset(); break;
    default:
      if (a.kind === 'slot') ctx.quick.useCell(a.row, a.slot, true);
      else if (a.belt != null) ctx.quick.useBelt(a.belt);
      else if (a.preset != null) ctx.presets?.setPreset(a.preset);
      // follow, summon orders, item link: the owning systems listen to 'keyaction'
  }
}

/** Every frame: the key-map actions that are not engine keys or window hotkeys. */
function dispatchKeys(game) {
  const km = ctx.keymap, mgr = game.uiwin;
  dispatchCameraToggle(game, km);
  if (!km.raw || mgr.capturesInput || game.paused || !game.player) return;
  for (const a of ACTIONS) {
    if (!a.id || a.kind === 'engine' || a.kind === 'camera' || isHotkeyAction(a)) continue;
    const spec = km.get(a.id);
    if (!spec) continue;
    if (a.id === 'dropnames' || a.id === 'forceattack') continue;   // held keys (dropNames) / a click modifier
    if (km.hit(spec, { allowForceAttack: a.kind === 'slot' })) runAction(game, a);
  }
}

/** Mouse: middle click resets the view; control type A: a right click uses the selected skill. */
function mouseActions(game) {
  const inp = game.input;
  if (!inp) return;
  for (const c of inp.clicks || []) {
    if (c.button === 'middle') ctx.effects.resetCamera();
  }
}

// control type A: the controller would clear the target on a right click into empty space; take the click first
function wrapController(game) {
  const c = game.controller;
  if (!c || c._hoWrap) return;
  c._hoWrap = true;
  const orig = c.update.bind(c);
  c.update = (dt) => {
    const inp = game.input;
    const armed = ctx.quick?.armed;
    if (armed && inp?.clicks?.length) {
      const rest = [];
      for (const k of inp.clicks) {
        if (k.button !== 'right') { rest.push(k); continue; }
        const a = game.pickActor?.({ x: k.nx, y: k.ny });
        if (a && !a.dead && (a.kind === 'monster' || (a.kind === 'player' && game.isPvpHostile?.(a)))) c.setTarget?.(a);
        const q = quickState(game);
        const e = q?.sets[q.rowSet[armed.r]]?.[armed.i];
        if (e) ctx.quick.useEntry(e);
        ctx.quick.armed = null;
      }
      inp.clicks.length = 0; inp.clicks.push(...rest);
    }
    return orig(dt);
  };
}

// ============================================================================================ gameplay hooks
function autoPotion(game, dt) {
  ctx._potT = (ctx._potT || 0) - dt;
  if (ctx._potT > 0 || !ctx.options.get('autoPotion')) return;
  ctx._potT = 0.3;
  const p = game.player;
  if (!p || p.dead) return;
  const q = quickState(game);
  const pick = (want) => {
    const cands = [...(q?.belt || []), ...(game.save?.inventory || [])].filter(Boolean);
    for (const e of cands) {
      const def = game.loot?.consumables?.get(Number(e.itemIndex));
      if (!def?.kind || !def.kind.includes(want)) continue;
      if ((Number(game.loot?.itemCooldown?.(e.itemIndex)) || 0) > 0) continue;
      if (ctx.itemCount(e) <= 0) continue;
      return e;
    }
    return null;
  };
  if (p.maxHp > 0 && (p.hp / p.maxHp) * 100 < Number(ctx.options.get('hpLimit'))) { const e = pick('hp'); if (e) game.loot?.useItem?.(e); }
  if (p.maxMp > 0 && (p.mp / p.maxMp) * 100 < Number(ctx.options.get('mpLimit'))) { const e = pick('mp'); if (e) game.loot?.useItem?.(e); }
}

/** R (Walk/run): the player walks at the walk clip's own ground speed. */
function walkMode(game) {
  const p = game.player;
  if (!p || p._hoWalk) return;
  p._hoWalk = true;
  const origSpeed = p.groundSpeed?.bind(p), origPlay = p.play?.bind(p);
  // walking applies on foot (a mounted player moves at the vehicle's stride)
  const on = () => !!ctx?.walk && !game.mounts?.isMounted?.();
  if (origSpeed) p.groundSpeed = (state = 'run', battle) => origSpeed(on() && state === 'run' ? 'walk' : state, battle);
  if (origPlay) p.play = (state, opts = {}) => origPlay(on() && state === 'run' ? 'walk' : state, opts);
  // Online the host moves the player: every move intent says whether (and in which stance) the player walks, so the
  // host uses the same walk speed the client predicts (network/client.js move, server movement-speed.mjs).
  p.walking = () => (on() ? (p.inBattle?.() ? 'battle' : 'peace') : null);
}

// ============================================================================================ the old DOM HUD
function takeOverOldHud(game) {
  const hud = game.hud;
  if (!hud) return;
  // its event handlers (log lines, flashes) are replaced by the original windows' own messages below
  for (const off of hud._off || []) { try { off(); } catch { /* ignore */ } }
  hud._off = [];
  globalThis.removeEventListener?.('keydown', hud._onKey);
  const E = hud.els || {};
  for (const k of ['exp', 'quick', 'hp', 'buffs', 'target', 'minimap', 'menu', 'chat', 'help', 'fps']) if (E[k]) E[k].style.display = 'none';
  const noop = () => {};
  for (const m of ['_updatePlayer', '_updateExp', '_updateHotbar', '_updateTarget', '_drawMinimap', '_fpsTick', '_paintArt']) hud[m] = noop;
  hud._renderStatuses = noop;
  hud.levelUpFlash = noop;
  hud.focusChat = () => ctx.chat.openInput();
  hud.zoomMinimap = (dir) => ctx.options.set({ minimapZoom: dir > 0 ? 1 : 0 });
  hud.log = (text, kind = 'sys') => { if (kind !== 'dmg') ctx.chat.system(text, kind === 'chat' ? 'sys' : kind); };
  hud.toast = (text) => {
    const idx = game.world?.info?.index;
    const row = idx != null ? (game.mapRow?.(idx) || game.data?.mapByIndex?.(idx)) : null;
    if (row && String(text) === String(row.Name)) ctx.mapTitle(idx);
    else if (text) ctx.notice?.(text);
  };
  hud.showDeath = (onRevive) => { game.uiwin.open('death', onRevive); };
  hud.hideDeath = () => game.uiwin.close('death');
  // damage numbers: the original sprite digits (floaters.js) replace the CSS floaters; heals still come through here
  hud.floater = (actor, text, kind = 'dmg-out') => {
    if (kind === 'heal') {
      const n = Number(String(text).replace(/[^\d]/g, ''));
      if (n > 0 && viewAllowed(game, actor, actor)) ctx.numbers.show(actor, { value: n, kind: /MP/i.test(String(text)) ? 'mp' : 'heal' });
    }
    return null;
  };
}

/** "Damage Effect Display Setting": 0 all, 1 own only (the player is the source or the target), 2 none. */
function viewAllowed(game, source, target) {
  const v = Number(ctx.options.get('damageView')) || 0;
  if (v === 2) return false;
  if (v === 1) { const p = game.player; return source === p || target === p || source?.owner === p; }
  return true;
}

function wireEvents(game) {
  const ev = game.events;
  const p = () => game.player;
  wrapController(game);
  const displayDamage = (e) => {
    if (!e?.target) return;
    const me = p();
    if ((e.source === me || e.source?.owner === me) && e.target.kind === 'monster') ctx.owned.add(e.target);
    if (!viewAllowed(game, e.source, e.target)) return;
    const toMe = e.target === me;
    if (e.miss) { ctx.numbers.show(e.target, { word: 'miss' }); return; }
    if (e.guard) { ctx.numbers.show(e.target, { word: 'block', value: e.amount, kind: toMe ? 'in' : 'out' }); return; }
    const kind = e.dot ? 'dot' : toMe ? (e.crit ? 'incrit' : 'in') : (e.source === me || e.source?.owner === me) ? (e.crit ? 'crit' : 'out') : 'other';
    ctx.numbers.show(e.target, { value: e.amount, kind, crit: !!e.crit });
    if (toMe && (e.crit || (e.source && isAggressive(e.source) && Number(e.source?.def?.rank) >= 3))) ctx.shake(e.crit ? 0.18 : 0.12, 0.3);
  };
  ev.on('damage', displayDamage);
  // Authoritative impacts use a cosmetic channel to avoid local reward hooks.
  ev.on('server:damage', displayDamage);
  ev.on('death', (e) => {
    if (e?.actor === p()) ctx.chat.system(`${plainText(str(40, 108) || '')}`.trim() || 'You have died.', 'err');
  });
  ev.on('exp', (e) => {
    const amt = Math.round(e?.amount || 0);
    if (!amt) return;
    if (amt > 0) ctx.chat.system(`${str(40, 3) || 'Obtained EXP: ['} ${fmtInt(amt)} ]`, 'exp');
    else ctx.chat.system(`EXP -${fmtInt(-amt)}`, 'err');
  });
  ev.on('levelup', () => {
    const t = str(40, 4) || '[Message] Your level has increased.';
    ctx.chat.system(t, 'sys');
    ctx.notice?.(t.replace(/^\[Message\]\s*/i, ''));
  });
  ev.on('loot', (e) => {
    if (!e) return;
    if (/^dil$/i.test(String(e.name || ''))) {
      // (playgate) the items system's pickup already prints 40:83 for dil; printing it here too doubled the line
      if (!game.items) ctx.chat.system(dilPickupText(str(40, 83) || 'Acquired DIL: [ %lld DIL].', e.count), 'item');
    }
    else ctx.chat.system(itemPickupText(plainMarkup(str(40, 42) || '[Message] <NAME> has acquired <VALUE>.').replace('<NAME>', p()?.name || ''), e.name, e.count, e.grade), 'item');
  });
  ev.on('skilllearn', (e) => { if (e?.skill && !e.announced) ctx.chat.system(`${e.skill.name} Lv.${e.level}`, 'sys'); game.windows?.refresh?.('skills'); });
  ev.on('stats', () => game.windows?.refresh?.('character'));
  ev.on('map', () => { ctx.effects.applyWorld(); });
  ev.on('revive', () => game.uiwin.close('death'));
  ev.on('options', ({ changed }) => { if ('controlType' in changed) { ctx.quick.armed = null; } });
  // skill cooldown / "not enough MP" and similar reasons the skill system prints come through hud.log already
}
