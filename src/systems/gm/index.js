// GM system (docs/formats/gmcommands.md): every GM command of gamedata/gmcommands.json (the GM Tool privileges, the
// GM NPC functions, the developer console, the capabilities the data proves and the solo tools) from the chat box
// ("/gm <command> ..." and the bare aliases "/call", "/item", "/move" ...), the original developer console (`) and the
// GM panel (F10), plus the extras (teleport + minimap click, god / speed / noclip / free camera, kill all, cooldowns,
// NPC spawning, time / weather, quest editor, drop-table viewer, event starter, model viewer, performance overlay,
// save editor / export / import).
//
// Public API: game.gm = {
//   ready, run(line) -> Promise<bool>, st (persisted state, save.gm), openPanel(tab, arg), togglePanel(),
//   toggleConsole(), say(text), data (GMData), rateMul(kind), dshopBalance(), dshopSpend(n) }
// Hooks (runtime wraps on instances, no shared-file edits except the one registration line): game.chatCommand (the chat
// box's GM hook), game.combatHooks.beforeDamage (god / one-hit), game.expModifiers (EXP events, PC-cafe bonus),
// game.settings.dropRate / moneyRate accessors (drop / DIL events), player.moveSpeedMul (speed), controller
// _walkable / _findPath / moveTo (noclip, Ctrl+click and minimap teleport), skills _startCooldown (cooldowns off),
// monster brains (freeze / AI off, hide), world.isWalkable on map 22 (the OX wall), game._frame (time scale + perf).
import { gmData, GM_ONLY_NPCS } from './data.js';
import { matchLine, coerceArgs, ERR } from './parser.js';
import { HANDLERS, EXTRA, fmt } from './commands.js';
import { GMWindows } from './windows.js';
import { DebugLayers, FreeCam, PerfOverlay, teleport } from './worldtools.js';
import { GMPanel } from './panel.js';
import { formulaOf } from '../../game/progression.js';
import { listCharacters, saveCharacter } from '../../game/save.js';
import {hasGMPanelPermission} from './permissions.js';
import {GMBuildMode} from './build-mode.js';
import {ONLINE_PRESENTATION,commandSupport} from './online-support.js';
import {playerIntent} from './players.js';

export { GM_ONLY_NPCS };
const EXTRA_ALIASES = { rain: 'weatherfx', startevent: 'event', where: 'pos', loc: 'pos', gm: 'panel', weather: 'weatherfx', viewmodel: 'viewer', saveedit: 'save' };
const RATE_CODES = { exp: 1, drop: 2, dil: 3 };
const COL = { out: 'ffffedfc', err: 'ffff5a45', dim: 'ffa0a0a0', echo: 'ffc8c8c8', info: 'ffa0d2ff', gold: 'ffffe38c' };
const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };
const plain = s => String(s ?? '').replace(/<\/?color[^>]*>/gi, '').replace(/\\n|\\\\/g, '\n');
// These commands inspect data or change only this operator's presentation. World changes use the GM API.

export class GM {
  constructor(game) {
    this.game = game;
    this.data = gmData;
    this.windows = new GMWindows(this);
    this.debug = new DebugLayers(game);
    this.freecam = new FreeCam(game);
    this.buildMode=new GMBuildMode(this);
    this.perf = new PerfOverlay(game);
    this.panel = new GMPanel(this);
    this.eventLog = [];
    this.timescale = 1;
    this.shutdown = null;
    this._rawExp = false;
    this._ox = null;
    this._ctrlAt = 0;
    this._uiHidden = false;
    this.ready = this._init();
  }

  // ------------------------------------------------------------------------------------------ state
  /** Persisted GM state (save.gm). */
  get st() {
    const s = this.game.save;
    if (!s.gm || typeof s.gm !== 'object') s.gm = {};
    const g = s.gm;
    if (g.speed == null) g.speed = 1;
    g.rates ||= {};
    return g;
  }

  async _init() {
    await gmData.load();
    gmData.extra = new Map(EXTRA.map(c => [c.id, c]));
    for (const [w, id] of Object.entries(EXTRA_ALIASES)) gmData.extra.set(w, gmData.extra.get(id));
    for (const c of EXTRA) for (const a of c.aliases || []) { const m = /^\/gm\s+(\S+)/.exec(a); if (m) gmData.extra.set(m[1].toLowerCase(), c); }
    // the client strings the commands print (loaded once so text() works synchronously)
    const S = this.game.uiwin?.strings;
    if (S) {
      const refs = [[160, 60], [160, 61], [160, 62], [1002, 4], [1002, 5], [700, 2], [40, 126], [40, 38], [178, 1], [178, 2], [178, 3], [178, 4], [178, 5]]
        .map(([cate, code]) => ({ group: 'NORMAL', cate, code }));
      refs.push({ group: 'SYSTEM', cate: 700, code: 2 }, { group: 'SYSTEM', cate: 101, code: 3 });
      await S.need(refs).catch(() => {});
      for (const [map, code] of [[654, 9700], [654, 9553], [654, 9554], [22, 4900], [22, 5100]]) S.resolve({ group: 'DUNGEON', cate: map, code }).catch(() => {});
    }
    if (this.game.save.authority !== 'server') this.applyFormula();
    return this;
  }

  // ------------------------------------------------------------------------------------------ install
  install() {
    const g = this.game;
    this.windows.register();
    this.panel.register();
    g.gm = this;
    this.buildMode.install();
    // chat box hook (hud-options chat.js calls game.chatCommand first)
    const previousChatCommand = this._previousChatCommand = g.chatCommand;
    this._chatHook = (text) => this.chatCommand(text) || !!previousChatCommand?.call(g, text);
    g.chatCommand = this._chatHook;
    g.chat?.registerCommand?.('/gm', () => true, 'GM commands: /gm help, /gm panel (F10), ` console');
    // hotkeys: F10 = GM panel, ` = GM console (Ctrl/Shift+` = panel). A capture listener, so the keys never also
    // reach the key map (potion belt 10 / auto attack) while the GM tools take them.
    this._onKey = (e) => {
      if (e.repeat) return;
      const a = document.activeElement;
      const typing = a && (a.tagName === 'INPUT' || a.tagName === 'TEXTAREA' || a.isContentEditable);
      if (this._uiHidden && (e.code === 'Escape' || e.code === 'F10')) { e.preventDefault(); e.stopImmediatePropagation(); this.hideUI(false); return; }
      if (e.code === 'F10') { e.preventDefault(); e.stopImmediatePropagation(); if (typing) a.blur(); this.togglePanel(); return; }
      if (e.code === 'Backquote' && !typing && !e.altKey) {
        e.preventDefault(); e.stopImmediatePropagation();
        if (e.ctrlKey || e.shiftKey) this.togglePanel(); else this.toggleConsole();
      }
    };
    window.addEventListener('keydown', this._onKey, true);
    this._onPtr = (e) => { this._ctrlAt = e.ctrlKey ? performance.now() : 0; };
    window.addEventListener('pointerdown', this._onPtr, true);
    // Host simulation owns GM combat/movement/EXP flags. Never install solo simulation hooks online.
    if (g.save.authority === 'server') return;
    // combat: god mode / one-hit kills
    g.combatHooks ||= {};
    (g.combatHooks.beforeDamage ||= []).push((att, def, res) => {
      const st = this.st, p = g.player;
      if (st.god && def === p) { res.amount = 0; res.gmGod = true; }
      if (st.onehit && def?.kind === 'monster' && att && (att === p || att.owner === p)) res.amount = Math.max(num(res.amount), Math.ceil(num(def.hp)));
    });
    // EXP events + PC-cafe bonus
    (g.expModifiers ||= []).push(() => (this._rawExp ? 1 : this.rateMul('exp') * (1 + num(this.st.pcRoom) / 100)));
    // drop / DIL events: accessors over the settings the loot rolls read (never persisted)
    const S = g.settings;
    for (const [key, kind] of [['dropRate', 'drop'], ['moneyRate', 'dil']]) {
      let base = S[key] ?? 1;
      try {
        Object.defineProperty(S, key, { configurable: true, enumerable: false, get: () => num(base, 1) * this.rateMul(kind), set: (v) => { base = v; } });
      } catch (err) { console.warn('[gm] rate accessor', err); }
    }
    // skills: cooldowns off
    const eng = g.skills;
    if (eng?._startCooldown && !eng._gmCd) {
      const orig = eng._startCooldown.bind(eng);
      eng._gmCd = true;
      eng._startCooldown = (...a) => (this.st.noCooldowns ? undefined : orig(...a));
    }
    // time scale + performance overlay: the frame loop
    if (!g._gmFrame) {
      const orig = g._frame.bind(g);
      let virt = null, lastReal = null;
      g._gmFrame = true;
      g._frame = (now) => {
        const t0 = performance.now();
        if (this.timescale === 1 && virt == null) orig(now);
        else {
          if (virt == null) { virt = now; lastReal = now; }
          virt += (now - lastReal) * this.timescale; lastReal = now;
          orig(virt);
          if (this.timescale === 1) { /* keep the virtual clock (game._last is on it) */ }
        }
        if (this.perf.on) this.perf.frame(Math.min(0.1, (now - (this._lastNow ?? now)) / 1000), performance.now() - t0);
        this._lastNow = now;
      };
    }
    // event log (for /gm userlog)
    const E = g.events;
    E.on('death', ({ actor, killer }) => { if (actor === g.player) this.log(`died${killer ? ` (killed by ${killer.name})` : ''}`); else if (actor?.kind === 'monster' && killer === g.player) this.log(`killed ${actor.name} (Lv ${actor.level})`); });
    E.on('exp', ({ amount }) => { if (amount) this.log(`${amount > 0 ? '+' : ''}${fmt(amount)} EXP`); });
    E.on('levelup', ({ level }) => this.log(`level up -> ${level}`));
    E.on('loot', (d) => this.log(`loot ${d?.name || ''}${d?.count > 1 ? ` x${d.count}` : ''}`));
    E.on('map', ({ index }) => { this.log(`entered map ${index} ${g.world?.info?.name || ''}`); this._onMap(); });
    E.on('teleport', (d) => this.log(`teleport ${Math.floor(d.x)}, ${Math.floor(d.z)}`));
    E.on('quest:accept', (d) => this.log(`quest accepted ${d?.id ?? ''}`));
    E.on('quest:complete', (d) => this.log(`quest completed ${d?.id ?? ''}`));
    E.on('item:use', (d) => this.log(`used ${d?.name || d?.itemIndex || 'item'}`));
    E.on('spawn', ({ actor }) => this._wrapBrain(actor));
    if (g.world) this._onMap();
  }

  // ------------------------------------------------------------------------------------------ output
  say(text, color = COL.out) {
    const t = String(text ?? '');
    if (!t) return;
    this.windows.print(t, color);
    this.panel?.status?.(t, color);
    const kind = color === COL.err ? 'err' : 'gm';
    for (const line of t.split('\n')) {
      if (this.game.chat?.system) this.game.chat.system(line, kind);
      else this.game.hud?.log?.(line, kind === 'err' ? 'err' : 'sys');
    }
  }
  /** Client string (sync; fallback when not loaded). */
  text(group, cate, code, fallback = '') {
    const S = this.game.uiwin?.strings;
    const t = S?.get({ group: String(group).toUpperCase(), cate, code });
    return t != null && t !== '' ? plain(t) : fallback;
  }
  dungeonText(map, code, fallback = '') { return this.text('DUNGEON', map, code, fallback); }
  async dungeonTextAsync(map, code) {
    const S = this.game.uiwin?.strings;
    const t = S ? await S.resolve({ group: 'DUNGEON', cate: Number(map), code: Number(code) }).catch(() => null) : null;
    return t ? plain(t) : null;
  }
  /** 160:60 invalid / 160:61 no such mode / 160:62 failed (+ detail). */
  err(kind, detail = '') {
    const k = kind === 'mode' ? 'mode' : kind === 'failed' ? 'failed' : 'invalid';
    const [cate, code, fb] = ERR[k];
    this.say(`${this.text('NORMAL', cate, code, fb)}${detail ? ` (${detail})` : ''}`, COL.err);
  }
  log(text) {
    this.eventLog.push({ t: Date.now(), text: String(text) });
    if (this.eventLog.length > 1000) this.eventLog.splice(0, this.eventLog.length - 1000);
  }

  // ------------------------------------------------------------------------------------------ commands
  /** The chat box hook: GM lines run here; while chat is restrained, other lines are refused (700:2). */
  chatCommand(text) {
    if (!gmData.reg) return false;
    const m = matchLine(text);
    if (m) { this.run(text, { source: 'chat' }); return true; }
    const st = this.st;
    if (st.muteUntil && st.muteUntil > Date.now() && !/^\//.test(text)) {
      const left = Math.ceil((st.muteUntil - Date.now()) / 60000);
      this.game.chat?.system?.(`${this.text('SYSTEM', 700, 2, 'Your chat has been restrained.')} (${left} min)`, 'err');
      return true;
    }
    return false;
  }

  /** Run one command line. Resolves true when it was a GM line. */
  async run(line, { source = 'panel', echo = source !== 'console' } = {}) {
    await this.ready;
    const m = matchLine(line);
    if (!m) return false;
    if(!hasGMPanelPermission(this.game)){this.err('failed','GM permission is required.');return true;}
    if (echo) this.windows.print(`> ${line}`, COL.echo);
    if (m.panel) { this.openPanel(); return true; }
    const cmd = m.cmd;
    if (!cmd) { this.err('mode', `unknown command "${m.word}" - /gm help`); return true; }
    const support=commandSupport(this.game,cmd.id,{action:m.rest[0]?.t});
    if(!support.enabled){this.err('failed',support.reason);return true;}
    // Empty notice means open its editor, not clear a live shared notice.
    if(this.game.save.authority==='server'&&cmd.id==='notice'&&(!m.rest.length||(['all','map'].includes(m.rest[0].t.toLowerCase())&&!m.rest.slice(1).some(t=>t.t.trim())))){
      this.windows.openNoticeEditor();return true;
    }
    if (this.game.save.authority === 'server' && !ONLINE_PRESENTATION.has(cmd.id) && !(cmd.id === 'save' && /^(export|import|edit)$/i.test(m.rest[0]?.t || ''))) {
      const network = this.game.network;
      if (!network?.ready || !network.token) { this.err('failed', 'Wait for the shared world connection.'); return true; }
      const token=network.token;
      try {
        const result = await network._request('gm', { token, line: String(line) });
        if(this.game.network!==network||network.token!==token||!network.ready||network.disposed||!hasGMPanelPermission(this.game)){this.err('failed','The GM session changed. Reconnect and refresh this tool.');return true;}
        if (result.state) network._receiveSnapshot(result.state);
        if (result.message) this.say(result.message);
      } catch (error) { console.error('[gm] online command failed', cmd.id, error?.stack || error?.message || 'Unknown error'); this.err('failed', error.message); }
      return true;
    }
    const h = HANDLERS[cmd.id];
    if (!h) { this.err('mode', cmd.id); return true; }
    let args;
    try {
      args = (await PRE[cmd.id]?.(m, this)) || await coerceArgs(cmd, m.rest, m.restText);
    } catch (e) {
      if (e?.kind) {
        this.err(e.kind === 'mode' ? 'mode' : 'invalid', e.detail);
        this.say(`${cmd.syntax}`, COL.dim);
        return true;
      }
      console.error('[gm] parse', e);
      this.err('failed', e?.message);
      return true;
    }
    if(!hasGMPanelPermission(this.game)){this.err('failed','GM permission is required.');return true;}
    let failed = false;
    const ctx = {
      game: this.game, gm: this, line, cmd,
      say: (t, c) => this.say(t, c),
      fail: (msg, kind = 'failed') => { failed = true; this.err(kind, msg || ''); return null; },
    };
    try {
      const r = await h(args, ctx);
      if (typeof r === 'string' && r) this.say(r);
      if (!failed) {
        this.st.used = true;
        this.game.events?.emit?.('gm:command', { id: cmd.id, args, line });
      }
    } catch (err) {
      console.error(`[gm] ${cmd.id}`, err);
      this.err('failed', err?.message || String(err));
    }
    return true;
  }

  // ------------------------------------------------------------------------------------------ windows
  openPanel(tab = null, arg = null) { return this.panel.open(tab, arg).catch(error=>{this.err('failed',error.message);return false;}); }
  togglePanel() { if(!hasGMPanelPermission(this.game)){this.err('failed','GM permission is required.');return false;}return this.panel.isOpen?this.game.uiwin.close('gmpanel'):this.openPanel(); }
  toggleConsole() { if(!hasGMPanelPermission(this.game)){this.err('failed','GM permission is required.');return false;}return this.windows.toggleConsole(); }

  // ------------------------------------------------------------------------------------------ rates / tunables
  rateMul(kind) {
    const r = this.st.rates?.[kind];
    if (!r) return 1;
    if (r.until && Date.now() > r.until) return 1;
    return num(r.mult, 1) > 0 ? num(r.mult, 1) : 1;
  }
  setRate(kind, mult, minutes) {
    const st = this.st;
    const m = num(mult, 1);
    if (!(m > 0) || m === 1) { delete st.rates[kind]; return `${kind.toUpperCase()} rate event ended (x1).`; }
    const until = num(minutes) > 0 ? Date.now() + num(minutes) * 60000 : null;
    st.rates[kind] = { mult: m, from: Date.now(), until };
    const banner = this.text('NORMAL', 178, RATE_CODES[kind], ['', 'EXP x%d EVENT', 'Drop x%d EVENT', 'DIL Drop x%d EVENT'][RATE_CODES[kind]]).replace('%d', String(m));
    const lines = [banner];
    if (until) lines.push(this.text('NORMAL', 178, 4, 'Period: %s ~ %s').replace('%s', new Date().toLocaleString()).replace('%s', new Date(until).toLocaleString()));
    lines.push(this.text('NORMAL', 178, 5, '* End time may slightly vary due to server time validation.'));
    this.windows.showNotice(lines.join('\n'));
    return `${banner}${until ? ` for ${num(minutes)} minute(s)` : ''}.`;
  }
  _tickRates() {
    for (const [k, r] of Object.entries(this.st.rates || {})) {
      if (r?.until && Date.now() > r.until) { delete this.st.rates[k]; this.say(`${k.toUpperCase()} rate event ended.`, COL.gold); }
    }
  }
  /** Current value of a system variable (share/system_variable.csv + override). */
  sysvar(index) {
    const o = this.st.sysvar?.[index];
    if (o != null) return o;
    const row = (gmData.reg?.systemVariables || []).find(r => Number(Array.isArray(r) ? r[0] : r.index) === Number(index));
    return row ? (Array.isArray(row) ? row[1] : row.value) : null;
  }
  /** Apply the formula overrides onto the live formula tables (formula.ini as merged by progression.js). */
  applyFormula() {
    const F = formulaOf(this.game.data);
    const raw = this.game.data?.classesFile?.formula;
    this._formulaOrig ||= {};
    for (const [k, v] of Object.entries(this.st.formula || {})) {
      if (!(k in this._formulaOrig)) this._formulaOrig[k] = F[k];
      F[k] = v;
      if (raw && typeof raw === 'object') raw[k] = v;
    }
  }
  resetFormula() {
    const F = formulaOf(this.game.data);
    const raw = this.game.data?.classesFile?.formula;
    for (const [k, v] of Object.entries(this._formulaOrig || {})) { F[k] = v; if (raw) raw[k] = v; }
    this.st.formula = {};
  }

  // ------------------------------------------------------------------------------------------ D-Shop coins
  /** null = unlimited (the default), else the remaining coins. */
  dshopBalance() { const v = this.st.dkc; return v == null || v === 'unlimited' ? null : Math.max(0, num(v)); }
  dshopSpend(n) { if (this.dshopBalance() != null) this.st.dkc = Math.max(0, this.dshopBalance() - num(n)); }
  setCoins(v) { this.st.dkc = v === 'unlimited' ? 'unlimited' : Math.max(0, Math.floor(num(v))); this.game.events?.emit?.('dshop:coins', { coins: this.st.dkc }); }
  coinsText() { const b = this.dshopBalance(); return b == null ? 'unlimited' : fmt(b); }

  // ------------------------------------------------------------------------------------------ state toggles
  setGmMode(on) {
    this.st.mode = !!on;
    this._applyNameTag();
    this._gmNpcVisibility(true);
  }
  _applyNameTag() {
    const p = this.game.player;
    if (!p) return;
    const base = this.game.save?.name || p.name || '';
    p.name = this.st.mode ? `[GM] ${base}` : base;
    this.game.events?.emit?.('nameplate', { actor: p });
  }
  _gmNpcVisibility(force = false) {
    const on = !!this.st.mode;
    for (const n of this.game.npcs || []) {
      if (!GM_ONLY_NPCS.has(Number(n.npcIndex)) || n.gmSpawned) continue;
      if (!on) { if (n.culled) n._cullHidden = false; else if (n.group) n.group.visible = false; n.gmHidden = true; }
      else if (force || n.gmHidden) { n.gmHidden = false; if (n.culled) n._cullHidden = true; else if (n.group) n.group.visible = true; }
    }
  }
  resetItemCooldowns() { this.game.items?.uses?.cooldowns?.clear?.(); }

  /** Re-apply the per-map / per-instance wraps (map change, toggles). */
  applyWorldWraps() {
    const g = this.game, c = g.controller;
    if (c && !c._gmWrapped) {
      c._gmWrapped = true;
      const walk = c._walkable?.bind(c), find = c._findPath?.bind(c), moveTo = c.moveTo?.bind(c);
      const inside = (x, z) => { const w = g.world?.info; return !w || (x >= 0 && z >= 0 && x < (w.width || 1e9) && z < (w.height || 1e9)); };
      if (walk) c._walkable = (x, z) => (this.st.noclip ? inside(x, z) : walk(x, z));
      if (find) c._findPath = (x, z) => (this.st.noclip && inside(x, z) ? [{ x, z }] : find(x, z));
      if (moveTo) {
        c.moveTo = (x, z, ...rest) => {
          if (this.st.tpclick && this._ctrlAt && performance.now() - this._ctrlAt < 1500 && Number.isFinite(x) && Number.isFinite(z)) {
            this._ctrlAt = 0;
            this._ctrlTeleport(x, z);
            return true;
          }
          return moveTo(x, z, ...rest);
        };
      }
    }
    // player speed
    const p = g.player;
    if (p && !p._gmSpeed && typeof p.moveSpeedMul === 'function') {
      p._gmSpeed = true;
      const orig = p.moveSpeedMul.bind(p);
      p.moveSpeedMul = () => orig() * (num(this.st.speed, 1) || 1);
    }
    // the OX quiz wall (map 22, a blocking strip along y 254-256)
    const w = g.world;
    if (w && !w._gmWrapped) {
      w._gmWrapped = true;
      const orig = w.isWalkable.bind(w);
      w.isWalkable = (x, z) => {
        if (this._ox?.wall && w.info?.index === 22 && z >= 254 && z < 257 && x >= 230 && x < 283) return false;
        return orig(x, z);
      };
    }
  }

  /** Ctrl+click travel to (x, z) on the current map. Solo: the local teleport. Online: the server's authenticated GM
   *  route (operation 'teleportDestination': GM capability, lease, rate limit, walkable check), the point first snapped
   *  to the nearest walkable cell within 48 cells like the solo teleport does. One request at a time. */
  _ctrlTeleport(x, z) {
    const g = this.game;
    if (this._tpBusy || !g.world?.info) return null;
    this._tpBusy = true;
    // the click that started this must not also start a hold-to-walk (controller._press sets _holdMove after moveTo)
    queueMicrotask(() => { if (g.controller) g.controller._holdMove = false; });
    const map = Number(g.world.info.index);
    let job;
    if (g.save.authority === 'server') {
      const w = g.world;
      let p = { x, z };
      if (w.isWalkable && !w.isWalkable(x, z)) { const n = w.nearestWalkable?.(x, z, 48); if (n) p = { x: n.x, z: n.z }; }
      job = playerIntent({ game: g, status: (t) => this.say(t) }, 'teleportDestination', { map, x: p.x, z: p.z });
    } else {
      job = teleport(g, map, x, z).then(r => this.say(`Teleported to ${Math.floor(r.x)}, ${Math.floor(r.z)}.`));
    }
    return job.catch(e => this.err('failed', e?.message)).finally(() => { this._tpBusy = false; });
  }
  /** Ctrl+left clicks on the ground this frame -> _ctrlTeleport (first hit only). */
  _ctrlClicks() {
    const g = this.game;
    for (const c of g.input?.clicks || []) {
      if (c.button !== 'left' || !c.ctrl) continue;
      const gp = g.pickGround?.({ x: c.nx, y: c.ny });
      if (gp) { g.controller?.stop?.(); this._ctrlTeleport(gp.x, gp.z); break; }
    }
  }
  /** Online only: the minimap / world map travel calls controller.moveTo; a Ctrl+click there teleports instead (the solo
   *  build does this inside applyWorldWraps, which online never runs because noclip etc. are server-owned). */
  _wrapOnlineCtrlTravel() {
    const c = this.game.controller;
    if (!c || c._gmCtrlWrapped || typeof c.moveTo !== 'function') return;
    c._gmCtrlWrapped = true;
    const moveTo = c.moveTo.bind(c);
    c.moveTo = (x, z, ...rest) => {
      if (this.st.tpclick && !this.buildMode?.active && this._ctrlAt && performance.now() - this._ctrlAt < 1500 && Number.isFinite(x) && Number.isFinite(z)) {
        this._ctrlAt = 0;
        this._ctrlTeleport(x, z);
        return true;
      }
      return moveTo(x, z, ...rest);
    };
  }

  _wrapBrain(m) {
    const b = m?.brain;
    if (!b || b._gmWrapped) return;
    b._gmWrapped = true;
    const upd = b.update.bind(b);
    b.update = (dt) => {
      if (this.st.freeze) { try { m.play?.('idle', { loop: true }); } catch { /* ignore */ } return; }
      return upd(dt);
    };
    if (typeof b._validTarget === 'function') {
      const vt = b._validTarget.bind(b);
      b._validTarget = (t) => (this.st.hide && t === this.game.player ? false : vt(t));
    }
  }

  _onMap() {
    this.applyWorldWraps();
    this._applyNameTag();
    this._gmNpcVisibility(true);
    const map = this.game.world?.info?.index;
    const n = this.st.mapNotices?.[map];
    if (n) setTimeout(() => this.windows.showNotice(n), 800);
    if (this._ox && map !== 22) this._ox.auto = false;
    if (this.st.sky != null && this.st.skyMap === map) { /* per-map sky stays on its map only */ }
    this.debug._key = '';
  }

  // ------------------------------------------------------------------------------------------ shutdown
  tickShutdown(first = false) {
    const s = this.shutdown;
    if (!s) return;
    const left = s.at - this.game.time;
    const min = Math.max(0, Math.ceil(left / 60));
    if (first || (min !== s.lastMin && left > 0)) {
      s.lastMin = min;
      const t = this.text('NORMAL', 1002, 5, 'The server closes in %d minute(s).').replace('%d', String(min));
      this.windows.showNotice(t);
    }
    if (left <= 0) {
      this.shutdown = null;
      const go = () => { try { this.game.persist(); } catch (err) { console.error(err); } if (globalThis.dekaronReturnTo) globalThis.dekaronReturnTo('select'); else globalThis.location?.reload?.(); };
      if (this.game.uiwin?.has?.('systemwait')) this.game.uiwin.open('systemwait', { go }); else go();
    }
  }

  // ------------------------------------------------------------------------------------------ OX quiz (map 22)
  async ox(action, question = null) {
    const g = this.game;
    const Q = gmData.reg?.original?.oxQuiz;
    if (!Q) return 'The OX quiz data is missing.';
    this._ox ||= { wall: false, auto: false, q: null, timer: 0 };
    const ox = this._ox;
    const t = (code, fb) => this.dungeonText(22, code, fb);
    if (action === 'wall' || action === 'unwall') { ox.wall = action === 'wall'; this.applyWorldWraps(); return `${t(action === 'wall' ? 5111 : 5112, action === 'wall' ? 'Create wall.' : 'Remove wall.')} (y 254-256)`; }
    if (action === 'close') { this.st.oxEntry = false; return t(5116, 'Not allowed enter'); }
    if (action === 'end') {
      ox.auto = false; ox.q = null;
      this.windows.hideNotice();
      if (g.world?.info?.index === 22) { const r = g.respawnTarget(150); await g.travel(150, { x: 349.5, z: 129.5, dirDeg: 0 }); void r; }
      return `${t(5117, 'Export All (Game Over)')} - ${t(4900, 'Return to Ardeca.')}`;
    }
    if (action === 'auto') { ox.auto = !ox.auto; if (ox.auto) this._oxAsk(null); return `${t(5115, 'Question set (Auto)')}: ${ox.auto ? 'on (a question every 40 s)' : 'off'}`; }
    if (action === 'ask') { const q = this._oxAsk(question); return q ? `OX question ${q[0]}: ${q[1]} (answer in 20 s)` : 'No OX questions.'; }
    if (action === 'killo' || action === 'killx') {
      // the answer is O -> the X half is wrong (and the reverse). Half a (y >= 257) is O, half b (y <= 253) is X (the data does not say; gmcommands.md 9).
      const wrong = action === 'killo' ? Q.halves.b : Q.halves.a;
      const groups = wrong.groups.join(', ');
      const p = g.player;
      let hit = false;
      if (g.world?.info?.index === 22 && p && !p.dead) {
        const inX = p.x >= wrong.x[0] - 1 && p.x <= wrong.x[1] + 1, inZ = p.z >= wrong.y[0] - 0.5 && p.z <= wrong.y[1] + 1;
        if (inX && inZ && !this.st.god) { const { kill } = await import('../../game/combat.js'); kill(g, p, null); hit = true; }
      }
      return `${t(action === 'killo' ? 5113 : 5114, action === 'killo' ? 'Eliminate incorrect responders (O)' : 'Eliminate incorrect responders (X)')}: spike groups ${groups} (monster ${Q.callMonster})${hit ? ' - you were eliminated.' : '.'}`;
    }
    return null;
  }
  _oxAsk(qrow) {
    const Q = gmData.reg?.original?.oxQuiz;
    const list = Q?.questions || [];
    const q = qrow ? [qrow.index, qrow.question, qrow.answer, qrow.solution ?? qrow.explanation] : list[Math.floor(Math.random() * list.length)];
    if (!q) return;
    const ox = this._ox ||= { wall: false, auto: false };
    ox.q = { q, at: this.game.time, reveal: this.game.time + 20, next: this.game.time + 40, shown: false };
    this.windows.showNotice(`[OX Quiz ${q[0]}] ${q[1]}\n(20 seconds - O: the y 257-279 side, X: the y 232-253 side)`);
    return q;
  }
  _tickOx() {
    const ox = this._ox;
    if (!ox?.q) return;
    const now = this.game.time;
    if (!ox.q.shown && now >= ox.q.reveal) {
      ox.q.shown = true;
      const [, , ans, sol] = ox.q.q;
      this.windows.showNotice(`Answer: ${ans}\n${sol || ''}`);
      if (this.game.world?.info?.index === 22) this.ox(String(ans).toUpperCase() === 'O' ? 'killo' : 'killx').then(r => r && this.say(r));
    }
    if (ox.auto && now >= ox.q.next) this._oxAsk(null);
  }

  // ------------------------------------------------------------------------------------------ info
  characterCount() { try { return listCharacters().length; } catch { return 1; } }
  async npcPlacement(npcIndex) {
    const P = this.game.data?.npcs?.placements || {};
    for (const [map, pl] of Object.entries(P)) {
      for (const r of pl?.rows || []) if (Number(r[0]) === Number(npcIndex)) return { map: Number(map), x: num(r[1]), z: num(r[2]), dirDeg: num(r[3]) };
    }
    return null;
  }
  inspect(a) {
    if (!a) return ['Nothing selected.'];
    const r = v => (Number.isFinite(v) ? v.toFixed(1) : '-');
    const L = [`[${a.kind}] ${a.name}${a.monsterIndex != null ? ` #${a.monsterIndex}` : a.npcIndex != null ? ` #${a.npcIndex}` : ''} Lv ${a.level ?? '-'} · HP ${fmt(Math.round(a.hp))} / ${fmt(Math.round(a.maxHp))}${a.maxMp ? ` · MP ${fmt(Math.round(a.mp))} / ${fmt(Math.round(a.maxMp))}` : ''}`];
    L.push(`  pos ${r(a.x)}, ${r(a.z)} y ${r(a.y)} · yaw ${Math.round(((a.yaw || 0) * 180 / Math.PI % 360 + 360) % 360)}° · radius ${r(a.radius)} height ${r(a.height)}${a.dead ? ' · DEAD' : ''}${a.culled ? ' · culled' : ''}`);
    if (a.brain) L.push(`  AI ${a.brain.state} · target ${a.brain.target?.name || '-'} · aggressive ${!!a.brain.aggressive} · sight ${r(a.brain.sight)} · walk ${r(a.brain.walkSpeed)} run ${r(a.brain.runSpeed)} u/s`);
    const d = a.def;
    if (a.kind === 'monster' && d) L.push(`  exp ${fmt(d.exp)} · rank ${d.rank ?? '-'} · role ${d.role || '-'} · model ${d.model || d.shape || '-'}`);
    if (a.kind === 'npc' && d) L.push(`  roles ${(a.roles || []).join(', ') || '-'} · shape ${d.shape || '-'}`);
    const sts = this.game.statuses?.listOf?.(a, false) || [];
    if (sts.length) L.push(`  statuses ${sts.map(s => `${s.statusIndex ?? s.index ?? s.key} ${s.name || ''}${s.remaining != null ? ` (${Math.ceil(s.remaining)} s)` : ''}`).join(' · ')}`);
    if (a === this.game.player && a.stats) { const s = a.stats; L.push(`  attack ${fmt(s.attackMin)}-${fmt(s.attackMax)} · magic ${fmt(s.magicMin)}-${fmt(s.magicMax)} · defense ${fmt(s.defense)} · hit ${fmt(s.hitRate)} · dodge ${fmt(s.dodge)} · crit ${s.critRate} · speed ${r(a.groundSpeed?.('run'))} u/s`); }
    return L;
  }
  sysinfoLines() {
    const g = this.game, r = g.renderer, gl = r?.getContext?.();
    let gpu = '';
    try { const ext = gl?.getExtension('WEBGL_debug_renderer_info'); gpu = ext ? gl.getParameter(ext.UNMASKED_RENDERER_WEBGL) : gl?.getParameter(gl.RENDERER); } catch { /* ignore */ }
    const st = g.systems?.status?.() || { installed: [], failed: [] };
    const info = r?.info;
    let saveBytes = 0; try { saveBytes = JSON.stringify(g.save).length; } catch { /* ignore */ }
    return [
      'Dekaron Online (single player) - SYSTEM INFOMATION',
      `Browser: ${navigator.userAgent}`,
      `GPU: ${gpu || '?'} · WebGL ${r?.capabilities?.isWebGL2 ? 2 : 1} · max texture ${r?.capabilities?.maxTextureSize ?? '?'} · pixel ratio ${r?.getPixelRatio?.() ?? '?'}`,
      `Viewport ${innerWidth} x ${innerHeight} · interface scale ${g.uiwin?.scale ?? 1}`,
      `Render: ${info?.render?.calls ?? '?'} draw calls · ${fmt(info?.render?.triangles ?? 0)} triangles · ${info?.memory?.geometries ?? '?'} geometries · ${info?.memory?.textures ?? '?'} textures · ${info?.programs?.length ?? '?'} programs`,
      `Map ${g.world?.info?.index} ${g.world?.info?.name || ''} (${g.world?.info?.width ?? '?'} x ${g.world?.info?.height ?? '?'} cells)`,
      `Actors: ${(g.spawner?.monsters || []).length} monsters (${g.spawner?.records?.length ?? 0} spawn rows) · ${g.npcs?.length ?? 0} NPCs · ${g.loot?.drops?.length ?? 0} ground items`,
      `Systems installed (${st.installed.length}): ${st.installed.join(', ')}`,
      st.failed.length ? `Systems failed: ${st.failed.map(f => `${f.name} (${f.error})`).join('; ')}` : 'Systems failed: none',
      `GM data: ${gmData.commands.length} commands + ${EXTRA.length} extras · lists ${Object.keys(gmData.reg?.lists || {}).length}`,
      `Character: ${g.save?.name} · ${g.classDef?.name || ''} Lv ${g.save?.level} · save ${fmt(saveBytes)} bytes · ${this.characterCount()} character(s) on this PC`,
      `Game time ${g.time.toFixed(1)} s · time scale x${this.timescale}`,
      performance.memory ? `JS heap ${(performance.memory.usedJSHeapSize / 1048576).toFixed(0)} / ${(performance.memory.jsHeapSizeLimit / 1048576).toFixed(0)} MB` : '',
    ].filter(Boolean);
  }
  monitorLines() {
    const g = this.game, p = g.player, s = g.save, st = this.st;
    const L = [`USER MONITOR - ${s.name} (${g.classDef?.name || ''}) · ${new Date().toLocaleTimeString()}`];
    if (p) {
      L.push(`Level ${s.level} · EXP ${fmt(s.exp)} · DIL ${fmt(s.dil)} · stat points ${s.statPoints ?? 0} · skill points ${s.skillPoints ?? 0}`);
      L.push(`STR ${s.stats?.str} DEX ${s.stats?.dex} CON ${s.stats?.con} SPR ${s.stats?.spr}`);
      L.push(...this.inspect(p));
      const t = p.target;
      if (t) { L.push('Target:'); L.push(...this.inspect(t)); }
    }
    L.push(`GM: mode ${st.mode ? 'on' : 'off'} · god ${!!st.god} · hide ${!!st.hide} · speed x${st.speed} · noclip ${!!st.noclip} · one-hit ${!!st.onehit} · infinite MP ${!!st.infmp} · cooldowns ${st.noCooldowns ? 'off' : 'on'} · freeze ${!!st.freeze}`);
    L.push(`Rates: EXP x${this.rateMul('exp')} · drop x${this.rateMul('drop')} · DIL x${this.rateMul('dil')} · PC-cafe +${num(st.pcRoom)}% · D-Shop coins ${this.coinsText()}`);
    const act = g.quests?.engine?.activeIds?.() || [];
    L.push(`Quests in progress: ${act.length ? act.join(', ') : '-'}`);
    L.push('Recent log:');
    for (const e of this.eventLog.slice(-12)) L.push(`  ${new Date(e.t).toLocaleTimeString()} ${e.text}`);
    return L;
  }

  // ------------------------------------------------------------------------------------------ save tools
  viewerUrl(kind, id) {
    if (kind === 'item') {
      // the item's game (equipped / field) model, else its inventory model (items-visual.json shapes)
      const db = this.game.items?.db, def = db?.def(id), sh = def ? db.shape(def) : null;
      const m = sh?.game?.mesh ? sh.game : sh?.inv?.mesh ? sh.inv : this.game.items?.icons?.model?.(id);
      if (!m?.mesh) return null;
      const q = new URLSearchParams({ mesh: m.mesh });
      if (m.tpack) q.set('tpack', m.tpack);
      if (m.skel) q.set('skel', m.skel);
      if (m.anim) q.set('anim', m.anim);
      return `/tools/viewer.html?${q}`;
    }
    const k = kind === 'class' ? 'class' : kind === 'npc' ? 'npc' : 'monster';
    return `/tools/viewer.html?${k}=${encodeURIComponent(id ?? 0)}`;
  }
  exportSave() {
    const g = this.game;
    try { g.persist(); } catch { /* ignore */ }
    const blob = new Blob([JSON.stringify(g.save, null, 1)], { type: 'application/json' });
    const a = document.createElement('a');
    a.href = URL.createObjectURL(blob);
    a.download = `${String(g.save.name || 'character').replace(/[^\w.-]+/g, '_')}.dekaron-save.json`;
    document.body.appendChild(a); a.click(); a.remove();
    setTimeout(() => URL.revokeObjectURL(a.href), 4000);
  }
  /** Replace the character record (keeps the id) and reload the character. */
  async importSave(obj, { reload = true } = {}) {
    if(this.game.save.authority==='server')throw new Error('Online character imports and snapshot restoration are unavailable. Use server GM commands to edit this character.');
    if (!obj || typeof obj !== 'object' || Array.isArray(obj)) throw new Error('not a character record');
    const g = this.game, s = g.save;
    // Validate before touching the running character; the editor also accepts incomplete JSON.
    const next = JSON.parse(JSON.stringify(obj));
    if (!g.data.classByIndex?.has(Number(next.classIndex))) throw new Error('unknown character class');
    if (typeof next.name !== 'string' || !next.name.trim()) throw new Error('character name is required');
    if (!Number.isInteger(next.level) || next.level < 1) throw new Error('level must be a positive integer');
    if (!Array.isArray(next.inventory) || !next.equipment || typeof next.equipment !== 'object' || Array.isArray(next.equipment)) throw new Error('inventory and equipment are required');
    if (next.pos && !['x', 'z'].every(k => Number.isFinite(next.pos[k]))) throw new Error('position must contain finite x and z');
    next.id = s.id;
    // Imports cannot move a character to another local account.
    if (s.accountId != null) next.accountId = s.accountId;
    if (!saveCharacter(next)) throw new Error('could not write the character save');
    const { flushCharacterSaves } = await import('../../game/save.js');
    if (flushCharacterSaves && !await flushCharacterSaves()) throw new Error('account save failed; local backup was retained');
    for (const k of Object.keys(s)) delete s[k];
    Object.assign(s, next);
    // Autosave and beforeunload otherwise copy the OLD actor's map/HP into this record.
    if (reload && !g._gmImportPersist) {
      const persist = g.persist.bind(g);
      g._gmImportPersist = true;
      g.persist = () => this._importReloadPending ? saveCharacter(s) : persist();
    }
    this._importReloadPending = reload;
    if (reload) this.reloadSoon('Character record replaced: reloading...', false);
  }
  async snapshot(action, name) {
    const key = `dekaron-solo:gm:snap:${this.game.save.id}:${String(name || 'default')}`;
    if (action === 'save') {
      try { this.game.persist(); localStorage.setItem(key, JSON.stringify(this.game.save)); } catch (err) { return `Snapshot failed: ${err.message}`; }
      return `Snapshot "${name}" saved.`;
    }
    const raw = localStorage.getItem(key);
    if (!raw) return `No snapshot "${name}".`;
    await this.importSave(JSON.parse(raw));
    return null;
  }
  snapshotNames() {
    const pre = `dekaron-solo:gm:snap:${this.game.save.id}:`;
    const out = [];
    try { for (let i = 0; i < localStorage.length; i++) { const k = localStorage.key(i); if (k?.startsWith(pre)) out.push(k.slice(pre.length)); } } catch { /* ignore */ }
    return out.sort();
  }
  reloadSoon(msg, persist = true) {
    if (msg) this.say(msg, COL.gold);
    setTimeout(async () => {
      if (persist) { try { this.game.persist(); } catch { /* ignore */ } }
      const { flushCharacterSaves } = await import('../../game/save.js');
      if (flushCharacterSaves && !await flushCharacterSaves()) { this.err('failed', 'account save failed; reload cancelled'); return; }
      globalThis.location?.reload?.();
    }, 700);
  }
  hideUI(on = !this._uiHidden) {
    this._uiHidden = !!on;
    const el = this.game.ui;
    if (el) el.style.visibility = on ? 'hidden' : '';
    if (on) this.game.hud?.toast?.('');
    return on;
  }

  // ------------------------------------------------------------------------------------------ frame
  update(dt) {
    const g = this.game, st = this.st, p = g.player;
    this.buildMode?.update();
    const serverLease=g.save.authority==='server'&&g.network?.active&&g.network.ready&&g.network.token&&!g.network.disposed;
    if(serverLease)this._hadGMLease=true;
    if(!hasGMPanelPermission(g)||(g.save.authority==='server'&&this._hadGMLease&&!serverLease)){
      if(!this._permissionRevoked){
        this._permissionRevoked=true;this.panel.revoke();
        for(const name of ['gmconsole','gmsysinfo','gmnotice','gmrestrain','itembuilder'])g.uiwin?.close?.(name);
        globalThis.document?.getElementById?.('gm-map-builder')?.remove();
        this.freecam.set(false);this.perf.set(false);this.debug.toggle('none');this.hideUI(false);
      }
      return;
    }
    this._permissionRevoked=false;
    if (!p) return;
    if (g.save.authority === 'server') {
      // Ctrl+click teleport online: ground clicks here, minimap / world map through the moveTo wrap
      if (st.tpclick && !this.buildMode?.active) { this._wrapOnlineCtrlTravel(); this._ctrlClicks(); }
      this.debug.update(dt); this.panel.update(dt); return;
    }
    if (st.infmp && p.mp < p.maxMp) p.mp = p.maxMp;
    if (st.god) { if (p.hp < p.maxHp && !p.dead) p.hp = p.maxHp; }
    if (st.noCooldowns) g.skills?.resetCooldowns?.();
    if (st.freeze || st.hide) for (const m of g.spawner?.monsters || []) {
      this._wrapBrain(m);
      if (st.hide && m.brain?.target === p) { m.brain._leash?.(); }
    }
    if (!st.mode) this._gmNpcVisibility(false);
    // Ctrl+left click on the ground: teleport there
    if (st.tpclick&&!this.buildMode?.active) this._ctrlClicks();
    this.tickShutdown(false);
    this._tickRates();
    this._tickOx();
    this.debug.update(dt);
    this.panel.update(dt);
  }

  dispose() {
    if (this.game.chatCommand === this._chatHook) this.game.chatCommand = this._previousChatCommand;
    this.buildMode?.dispose();
    window.removeEventListener('keydown', this._onKey, true);
    window.removeEventListener('pointerdown', this._onPtr, true);
    this.debug.dispose(); this.perf.dispose(); this.freecam.set(false);
  }
}

/** Commands whose tokens need special handling before the generic coercion. */
const PRE = {
  // "/gm bgm off"
  bgm(m) { if (/^off$/i.test(m.rest[0]?.t || '')) return { map: 'off', mapRaw: 'off' }; return null; },
  // "/gm cooldowns" = reset; "/gm cooldowns off|on"
  cooldowns(m) { return m.rest.length ? null : { mode: 'reset' }; },
  // "/gm dkc" with no amount: show the balance
  dkc(m, gm) { return m.rest.length ? null : { amount: gm.coinsText() === 'unlimited' ? 'unlimited' : String(gm.dshopBalance()) }; },
  // "/gm time" with no hour: print the clock
  time(m) { return m.rest.length ? null : { hour: 'show' }; },
  // "/gm emote hi" / "/gm emote /hi" / "/gm emote 앉기": the emote slash words of the client (EU + Korean)
  async emote(m) {
    const w = String(m.rest[0]?.t || '').toLowerCase().replace(/^\/?/, '/');
    if (w === '/') return null;
    const rows = await gmData.list('emotes');
    const r = rows.find(x => (x.raw.slash || []).some(s => s.toLowerCase() === w) || (x.raw.slashKr || []).includes(w));
    return r ? { emote: r } : null;
  },
};

// ------------------------------------------------------------------------------------------ system entry points
let GMI = null;

export async function install(game) {
  GMI = new GM(game);
  GMI.install();
  await GMI.ready.catch(err => console.error('[gm] data load failed', err));
}
export function update(dt, game) { GMI?.update(dt, game); }
export function dispose() { GMI?.dispose(); GMI = null; }
export { GMI as gm };
