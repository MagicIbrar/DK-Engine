// Chat window (script/ui/game2/chat/ui_chatwnd.txt), chat option window (chat/ui_chatoption.txt), text colour
// window (chat/ui_selectchatcolorwnd.txt), chat commands and emotes.
//
//   * three text boxes: general chat (text_general, the tabs All / @Match / ;Party / Guild / &Vice / $Ally filter
//     it), system messages (text_system: everything the game reports) and the world "super chat" (text_superchat).
//   * Enter opens the input line (pan_text / edit_text, 100 chars), Enter sends, Esc cancels.
//   * prefixes (stringtable_chat cate 230 help lines, gmcommands.md §2.3): " whisper, ; party, ! shout, # guild,
//     ' guild whisper, & officer, $ alliance, @ matching, % world; ':' normal. Slash words: the emote macros
//     (script/lua/motion_macro.csv -> stringtable_emoticon cate 51, plus the Korean shortcuts of motion_macro.lua),
//     the chat-type macros (chattype_macro.lua + English aliases) and commands other systems register
//     (game.chat.registerCommand). Single player: every channel echoes locally; party / guild / whisper answer with
//     the client's own "not in a party / guild / not connected" messages when there is nobody to receive them.
//   * Action button: the two emote pages (com_action_2 / com_action_1, item data = motion or 1001 sit / 2001 stand /
//     3000 costume); Help button: the chat command list (com_help, item data = chat type) which prefills the input.
//   * Save Chat writes the log to a text file (230:66); Settings opens the chat option window; the clock button opens
//     the contents time table.
import { fetchText, fetchCSVObjects } from '../../engine/assets.js';
import { applyFont, fontOf } from '../../ui/uiwin/fonts.js';
import { playOnce, playLoop } from '../../game/combat.js';
import { str, plainMarkup, plainText, clamp, isTyping, LS } from './util.js';
import { SHOUT_COOLDOWN_MS, WORLD_CHAT_COOLDOWN_MS, worldWaitText } from './superchat-rules.js';
import { NATIVE_SYSTEM_COLOR, NATIVE_CHAT_LABEL_CODES, NATIVE_CHAT_SWATCHES } from './chat-native.js';
import {chatStackBand} from './chat-stacking.js';

// ENGINE-CHOSEN channel-specific defaults: native text_general is white, but the
// shipped scripts/config do not supply the executable's individual channel palette.
// User selections below do use the authored native palette.
export const CHAT_TYPES = {
  normal: { id: 0, color: 'ffffffff', filter: 'chatNormal', tab: 'btn_normal', label: '' },
  shout: { id: 1, color: 'ffffa040', filter: 'chatShout', label: 'Shout' },
  whisper: { id: 3, color: 'ffff8cf0', filter: 'chatWhisper', label: 'Whisper' },
  party: { id: 4, color: 'ff6ed2ff', filter: 'chatParty', tab: 'btn_party', label: 'Party' },
  guild: { id: 7, color: 'ff7cff7c', filter: 'chatGuild', tab: 'btn_guild', label: 'Guild' },
  officer: { id: 10, color: 'ff3cf0c8', filter: 'chatOfficer', tab: 'btn_guildmember', label: 'Officer' },
  alliance: { id: 16, color: 'ffffd264', filter: 'chatAlliance', tab: 'btn_alliance', label: 'Alliance' },
  matching: { id: 20, color: 'ffc8a0ff', filter: 'chatWorldMatch', tab: 'btn_worldchat', label: 'Matching' },
  world: { id: 21, color: 'ffffff3c', filter: 'chatWorld', label: 'World' },
  // Megaphone / DK Megaphone broadcasts (superchat.js): their own colour and the item name (173:38 / 173:39) as label
  megaphone: { id: -1, color: 'ffffffff', filter: 'chatWorld', label: 'Megaphone' },
};
const TYPE_BY_ID = Object.fromEntries(Object.entries(CHAT_TYPES).map(([k, v]) => [v.id, k]));
const PREFIX = { '"': 'whisper', ';': 'party', '!': 'shout', '#': 'guild', "'": 'guildwhisper', '&': 'officer', '$': 'alliance', '@': 'matching', '%': 'world', ':': 'normal' };
const TYPE_PREFIX = { whisper: '"', party: ';', shout: '!', guild: '#', officer: '&', alliance: '$', matching: '@', world: '%', normal: '' };
const TABS = { btn_normal: null, btn_worldchat: 'matching', btn_party: 'party', btn_guild: 'guild', btn_guildmember: 'officer', btn_alliance: 'alliance' };
/** option chat-type list (com_show_chatmsg_chattype) -> chat type */
export const COLOR_TYPES = ['normal', 'party', 'guild', 'officer', 'alliance', 'matching', 'world'];
// Only the base system color is authored by the active HUD. Per-kind overrides
// remain ENGINE-CHOSEN until the original dispatch colors can be established.
const SYS_COLORS = { sys: NATIVE_SYSTEM_COLOR, err: 'ffff5a45', exp: 'ffa0d2ff', item: 'ffffffff', dmg: 'ffc8c8c8', chat: 'ffffffff', gm: 'ffffedfc' };
const CHAT_HEIGHTS = [64, 96, 144, 192, 240, 288];
const SYS_HEIGHTS = [48, 80, 125, 160, 200, 240];
const CHAT_FONTS = [1, 2, 3, 4, 5];   // font.csv index for the Font Size steps (Tahoma 8..12)
const MAX_LINES = 300;

/** 55 authored swatches, left to right and top to bottom. */
export const SWATCHES = NATIVE_CHAT_SWATCHES;

// ------------------------------------------------------------------------------------------ macros
let macros = null;
/** Emote + chat-type slash macros from the client's lua/csv tables (EU strings + Korean shortcuts). */
export function loadMacros() {
  if (macros) return macros;
  macros = (async () => {
    const emotes = new Map(), types = new Map();
    const add = (m, k, v) => { const key = String(k || '').trim().toLowerCase(); if (key && key.startsWith('/') && !m.has(key)) m.set(key, v); };
    // EU: motion_macro.csv (cate, code -> motion, motiontype); stringtable_emoticon cate 51 = the slash word
    try {
      const rows = await fetchCSVObjects('script/lua/motion_macro.csv');
      const { strings } = await import('../../ui/uiwin/strings.js');
      await strings.need(rows.map(r => ({ group: 'NORMAL', cate: Number(r.cate), code: Number(r.code) })));
      for (const r of rows) {
        const s = await strings.resolve({ group: 'NORMAL', cate: Number(r.cate), code: Number(r.code) });
        add(emotes, s, { motion: Number(r.motion), type: Number(r.motiontype) || 0 });
      }
      // the help lists (50:4001..4021) name more aliases per emote: map each to the motion of its first word
      for (let c = 4001; c <= 4021; c++) {
        const list = await strings.resolve({ group: 'NORMAL', cate: 50, code: c });
        const words = String(list || '').split(/\s+/).filter(w => w.startsWith('/'));
        const known = words.map(w => emotes.get(w.toLowerCase())).find(Boolean);
        if (known) for (const w of words) add(emotes, w, known);
      }
    } catch (err) { console.warn('[hud-options] motion_macro', err); }
    // Korean shortcuts (motion_macro.lua / chattype_macro.lua, EUC-KR)
    try {
      const lua = await fetchText('script/lua/motion_macro.lua', true);
      for (const m of lua.matchAll(/shortcut\s*=\s*"([^"]+)"\s*,\s*motion\s*=\s*(\d+)\s*,\s*motiontype\s*=\s*(\d+)/g)) add(emotes, m[1], { motion: Number(m[2]), type: Number(m[3]) });
    } catch { /* optional */ }
    try {
      const lua = await fetchText('script/lua/chattype_macro.lua', true);
      for (const m of lua.matchAll(/shortcut\s*=\s*"([^"]+)"\s*,\s*ChatType\s*=\s*(\d+)/g)) add(types, m[1], Number(m[2]));
    } catch { /* optional */ }
    // English chat-type aliases (the EU tables have none: chattype_macro.csv points at missing 230:1000-1019)
    for (const [w, t] of [['/normal', 0], ['/n', 0], ['/shout', 1], ['/s', 1], ['/whisper', 3], ['/w', 3], ['/party', 4], ['/p', 4],
      ['/expedition', 4], ['/e', 4], ['/guild', 7], ['/g', 7], ['/officer', 10], ['/o', 10], ['/invite', 15], ['/i', 15],
      ['/alliance', 16], ['/a', 16], ['/match', 20], ['/m', 20], ['/map', 1], ['/world', 21], ['/global', 21]]) add(types, w, t);
    return { emotes, types };
  })();
  return macros;
}

// ------------------------------------------------------------------------------------------ chat system
export class Chat {
  constructor(game, ctx) {
    this.game = game;
    this.ctx = ctx;
    this.general = [];   // {type, text, color, name}
    this.sysLines = [];  // {kind, text, color} (not 'system': that name is the method below)
    this.world = [];
    this.tab = 'btn_normal';
    this.commands = new Map();
    this.lastWhisper = null;
    this.history = LS.load('dekaron-solo:chathistory', []) || [];
    this.hIndex = -1;
    loadMacros();
  }

  // -------------------------------------------------------------- API
  /** A system message (the system box). kind: sys | err | exp | item | dmg | gm. */
  system(text, kind = 'sys') {
    if (text == null || text === '') return;
    const t = plainMarkup(String(text));
    const e = { kind, text: t, color: SYS_COLORS[kind] || SYS_COLORS.sys, time: Date.now() };
    this.sysLines.push(e);
    if (this.sysLines.length > MAX_LINES) this.sysLines.shift();
    this.win?.control('text_system').addLine(t, e.color);
    return e;
  }
  /** A chat line: type normal|shout|whisper|party|guild|officer|alliance|matching|world. */
  say(type, name, text, extra = {}) {
    const T = CHAT_TYPES[type] || CHAT_TYPES.normal;
    const color = extra.color ? `ff${String(extra.color).slice(-6)}` : this._color(type);
    let line;
    if (type === 'whisper') line = extra.to ? `To [${extra.to}] : ${text}` : `From [${name}] : ${text}`;
    else if (type === 'normal') line = `${name} : ${text}`;
    else line = `[${extra.label || plainText(str(230, NATIVE_CHAT_LABEL_CODES[type])).trim() || T.label}] ${name} : ${text}`;
    // CHAT-LINKS: item links of the line (host record, or resolved locally) -> clickable "[Name]" runs (chat-links.js)
    const links = this.links ? this.links.incoming(extra.links, text) : null;
    const e = { type, name, text: line, color, time: Date.now(), fixed: !!extra.color, links: links?.length ? links : null };
    this.general.push(e);
    if (this.general.length > MAX_LINES) this.general.shift();
    if (type === 'world' || type === 'shout' || type === 'megaphone') {
      this.world.push(e); if (this.world.length > 60) this.world.shift();
      this.win?.control('text_superchat').addLine(line, color);
      if (e.links) this.links?.decorate(this.win?.control('text_superchat')?.content?.lastChild, e);
      if (this.world.length === 1) this.win?.data?.apply?.();   // the world box appears with its first line
    }
    if (this._visible(e)) this._addGeneral(e);
    this.game.events?.emit?.('chat', { type, name, text });
    return e;
  }
  /** Register a slash command: fn(args string, fullText) -> truthy when handled. */
  registerCommand(name, fn, help = '') { this.commands.set(String(name).toLowerCase().replace(/^\/?/, '/'), { fn, help }); }
  /** A chat balloon over an actor (ui_chatbubble.txt), e.g. an NPC or a summoned speaker: bubble(actor, text, type). */
  bubble(actor, text, type = 'normal') { this.ctx.bubbles?.show(actor || this.game.player, text, type); }

  _color(type) {
    const over = this.ctx.options.get('chatColors');
    const o = over && over[type];
    return o ? `ff${o}` : (CHAT_TYPES[type]?.color || 'ffffffff');
  }
  _visible(e) {
    const T = CHAT_TYPES[e.type];
    const O = this.ctx.options;
    if (T?.filter && O.get(T.filter) === false) return false;
    const want = TABS[this.tab];
    return !want || e.type === want || e.type === 'whisper';
  }
  _addGeneral(e) {
    const tb = this.win?.control('text_general');
    if (!tb?.addLine) return;
    tb.addLine(e.text, e.color);
    const div = tb.content?.lastChild;
    if (e.links) this.links?.decorate(div, e);
    if (div && e.name && e.name !== this._me()) {
      div.style.cursor = 'pointer';
      div.addEventListener('click', () => this.openInput(`"${e.name} `));
    }
  }
  _me() { return this.game.player?.name || this.game.save?.name || ''; }
  rebuild() {
    const tb = this.win?.control('text_general');
    if (!tb?.clear) return;
    this._recolor();
    tb.clear();
    for (const e of this.general) if (this._visible(e)) this._addGeneral(e);
    tb.scrollToEnd();
  }
  _recolor() { for (const e of this.general) if (!e.fixed) e.color = this._color(e.type); }

  // -------------------------------------------------------------- input
  openInput(prefill = '') {
    const w = this.win;
    if (!w) return;
    if (this.ctx.options.get('chatVisible') === false) this.ctx.options.set({ chatVisible: true });
    w.control('pan_text').setVisible(true);
    const ed = w.control('edit_text');
    if (prefill) ed.setValue(prefill);
    setTimeout(() => { ed.focus(); try { const n = ed.input.value.length; ed.input.setSelectionRange(n, n); } catch { /* ignore */ } }, 0);
  }
  closeInput() {
    const w = this.win;
    if (!w) return;
    const ed = w.control('edit_text');
    ed.clear(); ed.blur();
    w.control('pan_text').setVisible(false);
  }
  get inputOpen() { return !!this.win?.control('pan_text').isVisible(); }

  async send(raw) {
    const text = String(raw ?? '').trim();
    if (!text) return;
    this.history.unshift(text); this.history = this.history.slice(0, 30); this.hIndex = -1;
    LS.save('dekaron-solo:chathistory', this.history);
    const g = this.game, me = this._me();
    // the GM panel / console hook
    try { if (g.chatCommand?.(text)) return; } catch (err) { console.error(err); }
    const first = text[0];
    if (PREFIX[first] && first !== '/') return this._out(PREFIX[first], text.slice(1));
    if (first === '/') {
      const [cmd0, ...rest] = text.split(/\s+/);
      const cmd = cmd0.toLowerCase();
      const args = rest.join(' ');
      const reg = this.commands.get(cmd);
      if (reg) { try { if (reg.fn(args, text) !== false) return; } catch (err) { console.error(err); } }
      const M = await loadMacros();
      const em = M.emotes.get(cmd);
      if (em) { this.ctx.emote(em.motion, em.type); return; }
      if (M.types.has(cmd)) {
        const t = TYPE_BY_ID[M.types.get(cmd)];
        if (M.types.get(cmd) === 15 && !this.game.party?.active) { this.system(str(1008, 21) || 'The character is not in a Party.', 'err'); return; }
        if (!args) { this.inputType = t || 'normal'; return; }
        return this._out(t || 'normal', args);
      }
      if (cmd === '/help' || cmd === '/?') { this._help(); return; }
    }
    const tabType = TABS[this.tab] || this.inputType || 'normal';
    return this._out(tabType, text);
  }
  /** CHAT-LINKS: the input's "[Name]" links become {item:uid} tokens, then the channel (local or the shared-play host) sends. */
  _out(type, text) { return this._channel(type, this.links ? this.links.encode(text, type) : text); }
  _channel(type, text) {
    const me = this._me();
    text = String(text || '').trim();
    // single player: the tokens resolve against the own save, as the host does online (chat-links-rules.js)
    let links = null;
    if (this.links) ({ text, links } = this.links.resolveLocal(text));
    const lx = links?.length ? { links } : {};
    if (type === 'whisper' || type === 'guildwhisper') {
      const m = /^(\S+)\s+(.*)$/.exec(text);
      if (!m) return;
      const [, to, msg] = m;
      if (to === me) { this.say('whisper', me, msg, { to, ...lx }); this.say('whisper', me, msg, lx); return; }
      this.lastWhisper = to;
      this.system(`[${to}] ${str(1006, 48) || 'is not connected to the game, therefore cannot send the message.'}`, 'err');
      return;
    }
    if (!text) return;
    const g = this.game;
    if (type === 'party' && !(g.party?.members?.length > 1)) { this.say('party', me, text, lx); return; }
    if ((type === 'guild' || type === 'officer') && !g.guild?.name && !g.save?.guild) { this.system(str(130, 23) || 'You are not in a guild.', 'err'); return; }
    if (type === 'alliance' && !g.guild?.alliance && !g.save?.alliance) { this.system(str(140, 107) || 'You are not in a guild.', 'err'); return; }
    // the client's chat filter: restricted words are refused (230:59)
    const bad = this.ctx.badWord?.(text);
    if (bad) { this.system(plainMarkup(str(230, 59)).replace('[SLANG]', bad), 'err'); return; }
    // "!" map shout: once every 10 seconds (230:69); "%" world chat: once every 30 seconds (230:90, formula.ini dwShoutDelay)
    if (type === 'world') {
      const now = Date.now(), left = this._lastWorld ? this._lastWorld + WORLD_CHAT_COOLDOWN_MS - now : 0;
      if (left > 0) { this.system(worldWaitText(left, plainText(str(230, 90) || '') || undefined), 'err'); return; }
      this._lastWorld = now;
    }
    if (type === 'shout') {
      const now = Date.now();
      if (this._lastShout && now - this._lastShout < SHOUT_COOLDOWN_MS) { this.system(plainText(str(230, 69) || 'You can Shout only once every 10 seconds.').replace(/\s*\n\s*/g, ' '), 'err'); return; }
      this._lastShout = now;
    }
    this.say(type, me, text, lx);
    // the speaker's balloon (ui_chatbubble.txt): normal chat in the plain frame, the group channels in their colour
    if (['normal', 'shout', 'party', 'guild', 'officer', 'alliance'].includes(type)) this.ctx.bubble?.(text, type);
  }
  _help() {
    for (const c of [45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56]) { const s = str(230, c); if (s) this.system(s); }
    for (const [name, { help }] of this.commands) if (help) this.system(`${name} ${help}`);
  }
}

// ------------------------------------------------------------------------------------------ windows
export function registerChatWindows(game, ctx) {
  const chat = ctx.chat;
  game.uiwin.registerWindow('hud_chat', {
    hud: true, escClose: false, script: 'game2/chat/ui_chatwnd.txt', remember: true,
    menuExclude: Object.keys(TABS), // Chat tabs select filters/input, never open similarly named management windows.
    create(win) {
      chat.win = win;
      for(const id of ['text_general','text_system','text_superchat'])win.control(id).frameLineSync=true;
      const d = win.data;
      // tabs
      for (const b of Object.keys(TABS)) win.control(b).onClick(() => { chat.tab = b; chat.inputType = TABS[b] || 'normal'; paintTabs(); chat.rebuild(); });
      function paintTabs() { for (const b of Object.keys(TABS)) win.control(b).setChecked(b === chat.tab); }
      paintTabs();
      // input
      const ed = win.control('edit_text');
      ed.on('enter', () => { const v = ed.getValue(); chat.closeInput(); chat.send(v); });
      ed.on('escape', () => { chat.links?.clear(); chat.closeInput(); });
      ed.input?.addEventListener('keydown', (e) => {
        if (e.key === 'ArrowUp' || e.key === 'ArrowDown') {
          e.preventDefault();
          chat.hIndex = clamp(chat.hIndex + (e.key === 'ArrowUp' ? 1 : -1), -1, chat.history.length - 1);
          ed.setValue(chat.hIndex >= 0 ? chat.history[chat.hIndex] : '');
        } else if (e.key === 'Tab' && chat.lastWhisper) { e.preventDefault(); ed.setValue(`"${chat.lastWhisper} `); }
      });
      win.control('btn_open').onClick(() => chat.closeInput());
      win.control('btn_type').onClick(() => { const c = !win.control('btn_type').isChecked(); win.control('btn_type').setChecked(c); });
      win.control('btn_type').setChecked(true);   // ENG input (IME#5)
      // action (emotes) and help combos
      const a1 = win.control('com_action_1'), a2 = win.control('com_action_2'), help = win.control('com_help');
      for (const c of [a1, a2, help]) c.setVisible(false);
      d.actionPage = 2;
      const openAction = () => { const c = d.actionPage === 2 ? a2 : a1; c.setVisible(true); c.openList(); win.control('prev_action').setVisible(true); win.control('next_action').setVisible(true); };
      win.control('btn_action').onClick(() => openAction());
      win.control('prev_action').onClick(() => { d.actionPage = 2; openAction(); });
      win.control('next_action').onClick(() => { d.actionPage = 1; openAction(); });
      const runAction = (it) => {
        const v = Number(it?.value);
        if (!Number.isFinite(v)) return;
        if (v >= 3000) ctx.emote(100, 0);
        else if (v >= 1000) ctx.emote(v % 1000, Math.floor(v / 1000));
        else ctx.emote(v, 0);
      };
      // These combos are MENUS: a combobox only emits 'change' when the selection changes, and it starts on row 0, so the
      // first emote of a page (and any emote picked twice in a row) did nothing ("emotes not working", 2.1.1 known issue).
      // Keep them with no current row so every pick is a change.
      for (const c of [a1, a2, help]) c.select(-1);
      a1.on('change', (i, it) => { runAction(it); a1.select(-1); a1.setVisible(false); });
      a2.on('change', (i, it) => { runAction(it); a2.select(-1); a2.setVisible(false); });
      win.control('btn_help').onClick(() => { help.setVisible(true); help.openList(); });
      help.on('change', (i, it) => {
        help.select(-1);
        help.setVisible(false);
        const t = TYPE_BY_ID[Number(it?.value)] || (Number(it?.value) === 3 ? 'whisper' : 'normal');
        chat.openInput(TYPE_PREFIX[t] ?? '');
      });
      for (const c of [a1, a2]) c.items.forEach((it, i) => { const ref = c.info?.items?.[i]; if (ref) it.tooltip = ref; });
      // top buttons
      win.control('btn_logsave').onClick(() => saveLog(win));
      win.control('btn_option').onClick(() => game.uiwin.toggle('chatoption'));
      // the clock: the events system binds it (menu button btn_contentsview -> its timetable with "start now");
      // without it the plain time table of help.js opens
      win.control('btn_contentsview').onClick(() => { if (!game.uiwin.hasMenuButton('btn_contentsview')) game.uiwin.toggle('contents'); });
      // name pop-up (right click on a name in the chat)
      const pop = win.control('pan_pop');
      pop.setVisible(false);
      win.control('text_general').el.addEventListener('contextmenu', (e) => {
        const line = e.target.closest?.('div');
        const entry = line && chat.general.find(x => x.text === line.textContent);
        if (!entry?.name || entry.name === chat._me()) return;
        e.preventDefault();
        d.popName = entry.name;
        win.control('lbl_name').setText(entry.name);
        const r = win.control('pan_chatwindow').el.getBoundingClientRect(), sc = game.uiwin.scale;
        pop.setRect(Math.round((e.clientX - r.left) / sc), Math.round((e.clientY - r.top) / sc) - 75, 145, 75);
        pop.setVisible(true);
      });
      pop.control('btn_whisper')?.onClick(() => { pop.setVisible(false); chat.openInput(`"${d.popName} `); });
      for (const id of ['btn_invite', 'btn_friend', 'btn_black', 'btn_autoreport']) pop.control(id)?.onClick(() => {
        pop.setVisible(false);
        chat.system(`[${d.popName}] ${str(1006, 48)}`, 'err');
      });
      addEventListener('pointerdown', (e) => { if (pop.visible && !pop.el.contains(e.target)) pop.setVisible(false); }, true);
      // mail / messenger / receipt icons appear when the owning systems report news
      game.events?.on?.('mail', (m) => { win.control('btn_mail').setVisible(!!m?.unread); win.control('btn_mail').setBlink(!!m?.unread); });
      // btn_mail is wired by the UI platform itself when a system binds the mail menu button
      win.control('btn_messenger').onClick(() => game.uiwin.menuAction('btn_mail'));
      // the three scroll bars follow their box's height (applyLook resizes the boxes; script heights 144/125/48)
      for (const id of ['text_general_scroll', 'text_system_scroll', 'text_superchat_scroll']) {
        const sc = win.find(id);
        if (sc?.spec?.rect) sc.spec = { ...sc.spec, rect: [sc.spec.rect[0], sc.spec.rect[1], sc.spec.rect[2], 0] };
      }
      d.apply = () => applyLook(win);
      applyLook(win);
      for (const e of chat.sysLines) win.control('text_system').addLine(e.text, e.color);
      chat.rebuild();
    },
    update(win) {
      for(const id of ['text_general','text_system','text_superchat'])win.control(id).flushFrameLines();
      const band=chatStackBand(ctx.options.get('chatOnTop'),game.uiwin.openList);
      if(win.opts.band!==band){win.opts.band=band;game.uiwin._restack();}
      const vis = ctx.options.get('chatVisible') !== false;
      if (win.data.vis !== vis) { win.data.vis = vis; win.root.el.style.visibility = vis ? '' : 'hidden'; }
      if (win.data.layoutViewport !== layoutViewport(win)) applyLook(win, false);
    },
  });

  /** Sizes, transparency, font, "On Top", movable. */
  function layoutViewport(win) {
    return [game.uiwin.screen.w, game.uiwin.screen.h, win.box.x, win.box.y].join(':');
  }

  function applyLook(win, appearance = true) {
    const O = ctx.options;
    let gh = CHAT_HEIGHTS[clamp((Number(O.get('chatSize')) || 3) - 1, 0, CHAT_HEIGHTS.length - 1)];
    let sh = SYS_HEIGHTS[clamp((Number(O.get('sysSize')) || 3) - 1, 0, SYS_HEIGHTS.length - 1)];
    const hasWorld = chat.world.length > 0;
    // ENGINE-CHOSEN compact presentation: retain the authored 48px broadcast box,
    // replacing its empty 64px gap with the same 1px separator as the lower boxes.
    // Limit displayed heights only when the scaled viewport cannot fit the saved sizes.
    const scr = game.uiwin.screen;
    const available = Math.max(50, Math.floor(scr.h) - (hasWorld ? 98 : 49));
    if (gh + sh > available) {
      const extra = gh + sh - 50;
      gh = 34 + Math.floor((available - 50) * (gh - 34) / extra);
      sh = available - gh;
    }
    const P = win.control('pan_chatwindow').box.h || 200;
    const genTop = P - 18 - gh, sysTop = genTop - 1 - sh, supTop = sysTop - 1 - 48;
    win.control('pan_gencolor').setRect(0, genTop, 386, gh);
    // the dark general box runs behind the channel tab row (pan_back, 18 px at its bottom); the text lines end above
    // it, else the text box (layer 100) covers the tabs (layer 90) and swallows their clicks
    win.control('text_general').setRect(0, genTop, 386, Math.max(16, gh - 18));
    win.control('pan_syscolor').setRect(0, sysTop, 386, sh);
    win.control('text_system').setRect(0, sysTop, 386, sh);
    win.control('pan_superchatcolor').setRect(0, supTop, 386, 48);
    win.control('text_superchat').setRect(0, supTop, 386, 48);
    win.control('pan_superchatcolor').setVisible(hasWorld); win.control('text_superchat').setVisible(hasWorld);
    // The button row (contents view / log save / option / mail / messenger / receipt, 26x26 at the panel top)
    // was drawn INSIDE the system box. In the client it floats just above the topmost chat box, lined up.
    const topBox = Math.min(genTop, sh > 0 ? sysTop : genTop, hasWorld ? supTop : Infinity);
    const btnY = topBox - 27;
    [['btn_contentsview', 0], ['btn_logsave', 26], ['btn_option', 52], ['btn_mail', 78], ['btn_messenger', 104], ['btn_receipt', 130]]
      .forEach(([id, x]) => { try { win.control(id)?.setRect?.(x, btnY, 26, 26); } catch { /* control absent in this script */ } });
    // Correct the child group, leaving remembered window coordinates/preferences untouched.
    // The native input extends 3px below the 200px panel; include it in the bounds.
    const dx = clamp(0, -win.box.x, scr.w - win.box.x - 386);
    const dy = clamp(0, -win.box.y - btnY, scr.h - win.box.y - P - 3);
    win.control('pan_chatwindow').setRect(dx, dy, 380, P);
    win.data.layoutViewport = layoutViewport(win);
    const ga = clamp(Number(O.get('chatAlpha')) || 0, 0, 255), sa = clamp(Number(O.get('sysAlpha')) || 0, 0, 255);
    win.control('pan_gencolor').setImage('none', { screen: 'common', index: 1, color: [ga, 1, 1, 1] });
    win.control('pan_syscolor').setImage('none', { screen: 'common', index: 1, color: [sa, 1, 1, 1] });
    win.control('pan_superchatcolor').setImage('none', { screen: 'common', index: 1, color: [sa, 1, 1, 1] });
    for (const id of ['text_general', 'text_system', 'text_superchat']) win.control(id).setImage('none', null);
    const fi = CHAT_FONTS[clamp((Number(O.get('chatFont')) || 2) - 1, 0, CHAT_FONTS.length - 1)];
    for (const id of ['text_general', 'text_system', 'text_superchat']) {
      const tb = win.control(id);
      if (!tb.content) continue;
      tb.font = fi;
      // Keep the native textbox rhythm; font IDs are identifiers, not pixel sizes.
      tb.lh = Math.max(Number(tb.spec?.props?.lineheight?.[0]) || 16, fontOf(fi).height);
      applyFont(tb.content, fi, tb.lh);
      for (const div of tb.content.children) div.style.minHeight = `${tb.lh}px`;
      tb._range?.(); if (appearance) tb.scrollToEnd?.();
    }
    win.opts.band = chatStackBand(O.get('chatOnTop'),game.uiwin.openList);
    win.opts.movable = !!O.get('chatMovable');
    win.spec.titlerect = O.get('chatMovable') ? [dx, dy + btnY, dx + 386, dy + btnY + 26] : null;
    if (appearance) game.uiwin.focus(win);
  }

  function saveLog(win) {
    const pad = n => String(n).padStart(2, '0');
    const d = new Date();
    const name = `ChatLog_${d.getFullYear()}${pad(d.getMonth() + 1)}${pad(d.getDate())}_${pad(d.getHours())}${pad(d.getMinutes())}${pad(d.getSeconds())}.txt`;
    const lines = [...chat.general.map(e => `[${new Date(e.time).toLocaleTimeString()}] ${e.text}`), '', ...chat.sysLines.map(e => `[${new Date(e.time).toLocaleTimeString()}] ${e.text}`)];
    const blob = new Blob([lines.join('\r\n')], { type: 'text/plain' });
    const a = document.createElement('a');
    a.href = URL.createObjectURL(blob); a.download = name;
    document.body.appendChild(a); a.click(); a.remove();
    setTimeout(() => URL.revokeObjectURL(a.href), 2000);
    chat.system(plainText(str(230, 66)).replace(/\s*\n\s*/g, ' '));
  }

  // ------------------------------------------------------------------ chat option window
  game.uiwin.registerWindow('chatoption', {
    script: 'game2/chat/ui_chatoption.txt',
    create(win) {
      const d = win.data;
      const checks = { check_alwaysontop: 'chatOnTop', check_chatfixed: 'chatMovable', check_extrafeatures: 'chatExtra', check_normal: 'chatNormal',
        check_world: 'chatWorldMatch', check_party: 'chatParty', check_guild: 'chatGuild', check_shout: 'chatShout', check_whisper: 'chatWhisper',
        check_guildleader: 'chatOfficer', check_alliance: 'chatAlliance', check_allworldchat: 'chatWorld' };
      d.target = 'chat';
      const sizeKey = () => (d.target === 'chat' ? 'chatSize' : 'sysSize');
      const alphaKey = () => (d.target === 'chat' ? 'chatAlpha' : 'sysAlpha');
      for (const [id, k] of Object.entries(checks)) win.control(id).on('change', v => { d.draft[k] = !!v; });
      win.control('check_extrafeatures').setEnabled(false).setTooltip('Extra chat features are not implemented in this client yet.');
      const sld = win.control('sld_set');
      sld.setRange(0, 255);
      sld.on('change', v => { d.draft[alphaKey()] = Math.round(v); });
      const tabs = () => { win.control('btn_chatwndtab').setChecked(d.target === 'chat'); win.control('btn_syswndtab').setChecked(d.target === 'sys'); sld.setValue(d.draft[alphaKey()]); paint(); };
      win.control('btn_chatwndtab').onClick(() => { d.target = 'chat'; tabs(); });
      win.control('btn_syswndtab').onClick(() => { d.target = 'sys'; tabs(); });
      const step = (k, dir, max) => { d.draft[k] = clamp((Number(d.draft[k]) || 3) + dir, 1, max); paint(); };
      win.control('btn_up').onClick(() => step(sizeKey(), 1, CHAT_HEIGHTS.length));
      win.control('btn_down').onClick(() => step(sizeKey(), -1, CHAT_HEIGHTS.length));
      win.control('btn_fontsizeup').onClick(() => step('chatFont', 1, CHAT_FONTS.length));
      win.control('btn_fontsizedown').onClick(() => step('chatFont', -1, CHAT_FONTS.length));
      function paint() {
        win.control('lbl_chatwndsize').setText(String(d.draft[sizeKey()]));
        win.control('lbl_fontsize').setText(String(d.draft.chatFont));
      }
      win.control('btn_confirm').onClick(() => {
        const moving = d.draft.chatMovable !== ctx.options.get('chatMovable');
        ctx.options.set(d.draft);
        if (moving) {
          chat.system(plainText(str(230, d.draft.chatMovable ? 71 : 72)).replace(/\s*\n\s*/g, ' '));
          if (!d.draft.chatMovable) game.uiwin.window('hud_chat')?.resetPosition();
        }
        win.close('ok');
      });
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      d.load = () => {
        d.draft = { ...ctx.options.all() };
        for (const [id, k] of Object.entries(checks)) win.control(id).setChecked(!!d.draft[k]);
        tabs();
      };
    },
    onOpen(win) { win.data.load(); },
  });

  // ------------------------------------------------------------------ text colour window
  game.uiwin.registerWindow('chatcolor', {
    script: 'game2/chat/ui_selectchatcolorwnd.txt',
    create(win) {
      const d = win.data;
      const fx = win.control('pan_select_effect');
      for (let i = 1; i <= 55; i++) {
        const b = win.control(`btn_color_${i}`);
        const hex = SWATCHES[i - 1];
        // The parent fontcolor#2 already paints each native swatch. Keep the
        // transparent hit areas so code does not cover or replace that artwork.
        b.onClick(() => { d.pick = hex; const [x, y] = b.rect(); fx.setVisible(true); fx.setRect(x - 2, y - 2 + 0, 38, 36); });
      }
      win.control('btn_ok').onClick(() => {
        if (d.pick) {
          const type = COLOR_TYPES[clamp(Number(d.arg?.type ?? ctx.options.get('chatType')) || 0, 0, COLOR_TYPES.length - 1)];
          const colors = { ...(d.arg?.colors || ctx.options.get('chatColors') || {}), [type]: d.pick };
          if (d.arg?.onApply) d.arg.onApply(colors); else ctx.options.set({ chatColors: colors });
        }
        win.close('ok');
      });
    },
    onOpen(win, arg) { win.data.arg = arg || null; win.data.pick = null; win.control('pan_select_effect').setVisible(false); },
  });

  // ------------------------------------------------------------------ keyboard: Enter opens the chat line
  addEventListener('keydown', (e) => {
    if (e.key !== 'Enter' || e.repeat || isTyping() || game.uiwin?.modalOpen) return;
    if (!chat.win) return;
    e.preventDefault();
    chat.openInput();
  });
  ctx.options.on('change', (patch) => {
    if (!chat.win) return;
    if (['chatSize', 'sysSize', 'chatAlpha', 'sysAlpha', 'chatFont', 'chatOnTop', 'chatMovable'].some(k => k in patch)) chat.win.data.apply();
    if (Object.keys(patch).some(k => /^chat(Normal|WorldMatch|Party|Guild|Shout|Whisper|Officer|Alliance|World|Colors)$/.test(k))) chat.rebuild();
  });
}

// ------------------------------------------------------------------------------------------ emotes
/**
 * Play an emote (gmcommands.md §6.13): motion N of the class action table MOTION (classes.json anims.emotes by
 * index); motionType 1 = sit down and keep sitting until moving, 2 = stand up; costume = motion 100.
 */
export function makeEmote(game, ctx) {
  return function emote(motion, type = 0) {
    const p = game.player;
    if (!p) return false;
    // the life system owns the motions (class action table MOTION, EMOTIONSTART/KEEP/END, costume motions, sounds,
    // mount/fishing/dead checks AND the system chat line that says why an emote was refused): delegate when it is
    // installed (also for a dead player, so the refusal is shown); the code below is the stand-alone fallback
    const L = game.life?.emotes;
    if (L) {
      if (type === 1) return L.sit();
      if (type === 2) return L.stand();
      if (Number(motion) === 100) return L.costume();
      return L.playMotion(Number(motion));
    }
    if (p.dead) return false;
    const now = game.controller?.now ?? game.time ?? 0;
    const A = p.anims || {};
    game.controller?.stop?.();
    if (type === 1 || motion === 12) {
      const t = Number(A.sitDown?.timeLength) || 2;
      // hold past the clip so the controller's idle request can't cut in before the sit loop takes over
      playOnce(p, 'sitDown', {}, now, t + 1);
      ctx.later(Math.max(0, t - 0.05), () => { if (p._gpState === 'sitDown') { playLoop(p, 'sit', {}, game.controller?.now ?? 0, true); p._gpHold = Infinity; } });
      p._sitting = true;
      return true;
    }
    if (type === 2 || motion === 13) {
      if (!p._sitting) return false;
      p._sitting = false;
      const t = Number(A.standUp?.timeLength) || 1.8;
      p._gpHold = 0;
      playOnce(p, 'standUp', {}, now, t);
      return true;
    }
    const e = (A.emotes || []).find(x => Number(x.index) === Number(motion));
    if (!e) return false;
    p._sitting = false;
    playOnce(p, 'emote', { variant: Number(motion) }, now, Number(e.timeLength) || 2);
    game.audio?.playAll?.(game.audio?.S?.emote?.[motion]);
    return true;
  };
}
