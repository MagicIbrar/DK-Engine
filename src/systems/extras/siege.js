// SIEGE: the Zenoa Castle siege war, client side (host: server/world/siege.mjs; rules src/game/siege-rules.js; gaps
// src/config/engine-chosen-siege.js). Everything rides on the guild snapshot (network.guild.extras.siege) and the guild
// operations siegeRegister / siegeAnnounce / siegeFortify / siegeTax / siegeEnter / siegeEmpathy / siegeLeave.
//   NPC jobs: SIEGE_TELEPORT 21 (siege tunnels Braiken / Deneb / Loa), SIEGE_ENTRY 22 / SIEGE_SEAL 23 / READYSEALAUTHORITY 32 /
//     SIEGE_INFO 26 (Bastian, Loa Castle), SIEGE_STARTTIME 24 (ui_siegetimesetwnd) and SIEGE_UPGRADEGATE1..3 27..29
//     (ui_gateupgradewnd -> ui_gateinfownd) / SIEGE_UPGRADEGATEINFO 30 (Lorenzo), REIGN_SYSOP 25 (Juto: empathy).
//   Battle HUD: ui_warstatewnd, ui_siege_play_timewnd, ui_allzeolitestatewnd (5 pendants), ui_allgatestatewnd (3 gates),
//     ui_attachtimewnd (empathy progress, 290:42), ui_respawnwnd (290:41 respawn countdown), ui_siegetaxwnd (owner master).
//   Castle gates 30001..30003 / guardian stones 31001..31005 are drawn as their original bricks, block movement while they stand
//   and are attackable by the sealed attackers (snapshot `breakable`). Enemy participants are PvP-hostile (game.isPvpHostile).
import { SiegeForceAttackAlarm, siegePlayerHostile } from '../network/siege-force-attack.js';
import { registerEventActors } from '../network/event-actors.js';
import { randomUUID } from '../network/web-crypto.js';
import { S, UI, SIEGE_MAP, GATES, STONES, JOBS, GATE_JOBS, fillText, plainText } from '../../game/siege-rules.js';
import { SIEGE_CHOSEN } from '../../config/engine-chosen-siege.js';
import { loadEventData } from '../events/data.js';
import { Brick } from '../events/bricks.js';
import { numText, msg } from '../life/common.js';
import { presentGlobalMessage } from '../events/mode-ui-rules.js';

export const SIEGE_SCRIPTS = Object.freeze({
  war: 'game2/siege/ui_warstatewnd.txt', time: 'game2/siege/ui_siege_play_timewnd.txt', stones: 'game2/siege/ui_allzeolitestatewnd.txt',
  gates: 'game2/siege/ui_allgatestatewnd.txt', attach: 'game2/siege/ui_attachtimewnd.txt', respawn: 'game2/siege/ui_respawnwnd.txt',
  timeset: 'game2/siege/ui_siegetimesetwnd.txt', upgrade: 'game2/siege/ui_gateupgradewnd.txt', gateinfo: 'game2/siege/ui_gateinfownd.txt',
  tax: 'game2/siege/ui_siegetaxwnd.txt', timenotice: 'game2/msgbox/ui_siegetimenotice.txt',
});
/** ui_allgatestatewnd pan_gate_0..2 = 290:113 South / 114 West / 115 East. */
export const GATE_PANELS = Object.freeze([30003, 30002, 30001]);
const HUD = ['war', 'time', 'stones', 'gates'];
const sref = ([cate, code]) => ({ group: 'SIEGE', cate, code });
const uref = ([cate, code]) => ({ group: 'NORMAL', cate, code });
const npcId = n => Number(n?.npcIndex ?? n?.index ?? n?.st ?? n?.def?.index);
const pad = n => String(n).padStart(2, '0');
const mmss = ms => { const s = Math.max(0, Math.ceil(ms / 1000)); return `${pad(Math.floor(s / 60))}:${pad(s % 60)}`; };

export class Siege {
  constructor(game) { this.game = game; this.wins = {}; this.cur = {}; this.bricks = new Map(); this.data = null; this.busy = false; this.services = null; this.generation = 0; this.forceAlarm=new SiegeForceAttackAlarm(game,'siegeClassicForceAlarm',()=>this.online&&this.onCastle&&this.st?.phase==='battle'); }

  async install() {
    const g = this.game, W = g.uiwin;
    if (!W?.create) return;
    void loadEventData().then(d => { this.data = d; }).catch(() => {});
    try { await W.strings?.need?.([...Object.values(S).map(sref), ...Object.values(UI).map(uref),...[ [100,73],[130,381],[290,7] ].map(uref), ...[50, 51, 52, 53, 101, 102, 104, 105, 106, 107, 108, 109, 111, 112, 116].map(c => uref([290, c])), ...[20, 21, 22, 23, 24, 25].map(c => uref([320, c]))]); } catch { /* lazy */ }
    this._register(); g.events?.on?.('systems', () => this._register());
    g.chat?.registerCommand?.('/siegetax', () => { void this.openTax(); return true; }, 'Siege tax ledger (castle owner guild master).');
    g.chat?.registerCommand?.('/leavesiege', () => { void this.send('siegeLeave'); return true; }, 'Leave Zenoa Castle.');
    g.siege = this;
  }
  dispose() { this.forceAlarm.dispose();this._releaseActor?.(); this._releaseActor=null; this._actorNetwork=null; this._clearBricks(); for (const w of Object.values(this.wins)) { try { w.close?.(); } catch { /* ignore */ } } }

  // ------------------------------------------------------------------ shared
  get gs() { return this.game.network?.guild || null; }
  get st() { return this.gs?.extras?.siege || null; }
  get online() { return this.game.save?.authority === 'server' && !!this.game.network; }
  t(pair, fallback = '') { return this.game.uiwin?.strings?.get?.(sref(pair)) ?? fallback; }
  u(pair, fallback = '') { return this.game.uiwin?.strings?.get?.(uref(pair)) ?? fallback; }
  say(pair, ...args) { return plainText(fillText(this.t(pair, ''), ...args)); }
  note(text, kind = 'sys') { if (text) msg(this.game, text, kind); }
  box(text, kind = 'ok') { return this.game.uiwin.msgbox(text, { kind }); }
  async ask(text) { return (await this.box(text, 'yesno')) === 'yes'; }
  serverNow() { const c = this.game.network?._serverClock; return c ? c.time + (performance.now() - c.at) : Date.now(); }
  /** 'siege:700:5' -> the original text; 'siege:gateMax:N' / 'siege:gateAmount:N' -> engine lines. */
  errorText(message) {
    const m = /^siege:(\d+):(\d+)$/.exec(String(message || ''));
    if (m) return this.say([Number(m[1]), Number(m[2])]) || message;
    const g = /^siege:gate(Max|Amount):(\d+)$/.exec(String(message || ''));
    if (g) return g[1] === 'Max' ? `${plainText(this.u([320, 1]))}: ${numText(Number(g[2]))} DIL` : plainText(this.u([320, 6]));
    return message;
  }
  async send(operation, fields = {}) {
    const n = this.game.network, s = this.gs;
    if (!this.online || !s?.available) { this.note('This server has no durable guild service.', 'err'); return null; }
    if (this.busy) return null;
    this.busy = true;
    try {
      const r = await n.action('guild', { operation, revision: s.revision, requestId: randomUUID(), ...fields });
      if (!r && n._lastCommandError?.message) { const text = this.errorText(n._lastCommandError.message); this.note(text, 'err'); void this.box(text); }
      return r;
    } catch (err) { const text = this.errorText(err?.message || String(err)); this.note(text, 'err'); void this.box(text); return null; }
    finally { this.busy = false; }
  }
  dialog(npc, text, menu = []) {
    const d = this.game.sharedTravel?.sys?.dialog;   // the shared NPC dialog (dungeons/dialog.js: {title, text, menu:[{text, onClick}]})
    if (d?.open) return d.open({ title: npc?.name || '', text, menu: [...menu, { text: 'Close', onClick: () => null }] });
    return this.box(text);
  }

  // ------------------------------------------------------------------ NPC services
  /** Siege jobs go first in the quests registry (network/travel.js answers SIEGE_TELEPORT 21 'unavailable'); offline = fall through. */
  _register() {
    const reg = this.game.npcServices; if (!reg?.register || this.services === reg) return; this.services = reg;
    const on = (job, fn) => { const h = (npc, info) => { if (!this.online) return false;
      const n = { ...(npc || {}), name: npc?.name, npcIndex: info?.npcIndex ?? npcId(npc), jobIndex: Number(info?.jobIndex ?? 0) };
      // The native job21 index selects the castle. Renew entrances must not
      // borrow the classic guild snapshot or advertise a Zenoa admission.
      if (job === JOBS.TELEPORT && ![0, SIEGE_MAP].includes(n.jobIndex)) { if(this.game.sharedSiegeRenew?.service?.(n,{...info,jobType:job}))return true;void this.renewUnavailable(); return true; }
      if (!this.st) return false; void fn(n); return true; };
      const list = reg.handlers instanceof Map ? reg.handlers.get(job) : null; if (Array.isArray(list)) list.unshift(h); else reg.register(job, h); };
    on(JOBS.TELEPORT, n => this.tunnel(n));
    on(JOBS.ENTRY, n => this.register(n));
    for (const job of [JOBS.SEAL, JOBS.READYSEAL]) on(job, n => this.seal(n));
    on(JOBS.INFO, n => this.info(n));
    on(JOBS.STARTTIME, n => this.openTimeSet(n));
    for (const job of [JOBS.GATE1, JOBS.GATE2, JOBS.GATE3]) on(job, n => this.openUpgrade(GATE_JOBS[job], n));
    on(JOBS.GATEINFO, n => this.gateStatus(n));
    on(JOBS.REIGN, n => this.empathy(n));
  }
  ownerLine(s) { return s?.owner ? this.say(S.infoHeld, s.owner.name) : this.say(S.infoFree); }
  async renewUnavailable() {
    await this.game.uiwin?.strings?.need?.([sref([701, 214])]);
    return this.box(this.say([701, 214]) || 'No information.');
  }
  async tunnel(npc) {
    if (![0, SIEGE_MAP].includes(Number(npc?.jobIndex ?? 0))) return this.renewUnavailable();
    const s = this.st; if (!s) return;
    const text = s.phase === 'battle' || s.phase === 'prep' ? this.say(S.infoBattle, 'Zenoa Castle') : this.ownerLine(s);
    if (await this.ask(text)) await this.send('siegeEnter', { npcIndex: npcId(npc) });
  }
  requirements(s) { return `${numText(s.cfg.fee)} DIL / Guild Lv. ${s.cfg.guildLevel} / ${s.cfg.members} members`; }
  async register(npc) {
    const s = this.st; if (!s) return;
    if (s.side === 'attacker') return this.box(this.say(S.alreadyRequested));
    if (s.side === 'defender') return this.box(this.say(S.defenderCannot));
    if (await this.ask(`${this.ownerLine(s)}\n\n${this.requirements(s)}`)) await this.send('siegeRegister');
  }
  seal() { const s = this.st; if (!s) return null; return this.box(this.say(s.side === 'attacker' ? S.confirmed : s.side === 'defender' ? S.defenderCannot : S.notRegistered)); }
  /** 500:200 filled with the castle, the next battle time (500:201), the owner and the seal list (500:202 / 500:206). */
  infoText(s) {
    const d = new Date(s.startAt), when = s.startAt ? plainText(fillText(this.t(S.infoTime), d.getUTCFullYear() % 100, d.getUTCMonth() + 1, d.getUTCDate(), d.getUTCHours())) : this.say(S.infoNoTime);
    const state = this.say(s.phase === 'idle' ? S.infoSealOpen : S.infoStarted);
    const list = plainText(fillText(this.t(S.infoSeals), s.seals.length)) + ' ' + s.seals.map(r => r.name).join(', ');
    // 500:200 uses ' / ' as its line breaks: split first, then fill the fields (the 500:201 date has its own slashes)
    const raw = this.t(S.info, '').replace(/<overlab>.*?<\/overlab>/, '').replace(/<\/?(color|set|img|overlab)[^>]*>/gi, '').split(/\s*\/\s*/).join('\n');
    return raw.replace('<SERVERNAME>', 'Dekaron').replace('<CHANNELNAME>', `CH ${SIEGE_CHOSEN.CHANNEL + 1}`).replace('<NEXT_SIEGETIME>', when)
      .replace('<ATTACKER_GUILD>', s.owner?.name || '-').replace('<ATTACKER_NAME>', s.owner?.masterName || '-').replace('<SIEGE_STATE>', state).replace('<SEAL_LIST>', list);
  }
  info(npc) {
    const s = this.st; if (!s) return null;
    const menu = [{text:plainText(this.u([100,73],'Check Declared Siege Time')),onClick:()=>void this.openTimeNotice()}];
    if(this.gs?.master===this.gs?.myRef&&this.game.life?.guild?._siegeRoster)menu.push({text:plainText(this.u([130,381],'Siege Authority')),onClick:()=>void this.game.life.guild._siegeRoster()});
    if (s.side !== 'defender' && s.side !== 'attacker') menu.push({ text: 'Siege Registration', onClick: () => void this.register(npc) });
    if (s.owner?.master) menu.push({ text: plainText(this.t([100, 167], 'Siege Tax')) || 'Siege Tax', onClick: () => void this.openTax() });
    return this.dialog(npc, this.infoText(s), menu);
  }
  async empathy(npc) {
    const s = this.st; if (!s) return;
    if (await this.ask(this.say(S.empathyStart, this.gs?.name || ''))) await this.send('siegeEmpathy');
  }

  // ------------------------------------------------------------------ windows
  /** Each window is built once (its buttons wired once, acting on this.cur[key]); HUD windows are hud:true. */
  async win(key) {
    if (this.wins[key]) return this.wins[key];
    if (this._making?.[key]) return this._making[key];
    (this._making ||= {})[key] = (async () => {
      const w = await this.game.uiwin?.create?.(SIEGE_SCRIPTS[key], { name: `siege_${key}`, hud: [...HUD, 'attach', 'respawn'].includes(key), escClose: !HUD.includes(key) }); if (!w) return null;
      this.wins[key] = w; this._wire(key, w); return w;
    })();
    try { return await this._making[key]; } finally { this._making[key] = null; }
  }
  _wire(key, w) {
    const c = id => w.control(id), num = id => Number(String(c(id)?.getValue?.() ?? '').replace(/[^\d]/g, '')) || 0;
    if (key === 'timenotice')for(const id of ['btn_no','btn_exit'])c(id)?.onClick?.(()=>w.close());
    if (key === 'timeset') { c('btn_no')?.onClick?.(() => w.close('no'));
      c('btn_yes')?.onClick?.(async () => { const raw = String(c('edit_time')?.getValue?.() ?? '').trim(), hour = raw === '' ? NaN : Number(raw); w.close('yes'); if (await this.send('siegeAnnounce', { hour })) {this.note(this.say(S.timeChanged));await this.openTimeNotice();} }); }
    if (key === 'upgrade') { c('btn_no')?.onClick?.(() => w.close('no'));
      c('btn_yes')?.onClick?.(() => { const k = num('edit_invdil_value'), brick = this.cur.upgrade; w.close('yes'); if (k > 0 && brick) void this.confirmUpgrade(brick, k * 1000); }); }
    if (key === 'gateinfo') { c('btn_no')?.onClick?.(() => w.close('no'));
      c('btn_yes')?.onClick?.(async () => { const q = this.cur.gateinfo; w.close('yes'); if (q) await this.send('siegeFortify', { gate: q.brick, amount: q.dil }); }); }
    if (key === 'tax') { for (let i = 0; i < 7; i++) c(`btn_receive${i}`)?.onClick?.(() => void this.send('siegeTax', { day: i }));
      c('btn_receive7')?.onClick?.(() => void this.send('siegeTax', { day: -1 })); }
  }
  show(w) { if (w && !w.isOpen) this.game.uiwin.openWindow(w); }
  async openTimeNotice() {
    const network=this.game.network,token=network?.token;if(!this.st?.startAt)return null;
    const w=await this.win('timenotice'),s=this.st;if(!w||network!==this.game.network||token!==network?.token||!s?.startAt)return null;
    const d=new Date(s.startAt),text=this.u([290,7],'<MONTH> / <DAY> / <YEAR> <TIME>').replace('<MONTH>',pad(d.getUTCMonth()+1)).replace('<DAY>',pad(d.getUTCDate())).replace('<YEAR>',d.getUTCFullYear()).replace('<TIME>',`${pad(d.getUTCHours())}:${pad(d.getUTCMinutes())}`);
    w.control('lbl_text')?.setText?.(text);this.show(w);return w;
  }
  async openTimeSet(npc) {
    const s = this.st; if (!s) return null;
    if (!s.owner?.master) return this.box(this.say(s.owner && s.guildId === s.owner.id ? S.notMaster : S.notDefender));
    const w = await this.win('timeset'); if (!w) return null;
    const d = new Date(s.startAt);
    // 290:8 is the date-only line ("<MONTH> / <DAY> / <YEAR>"); the window has its own edit_time + 290:9 "o'clock". plainText would drop the slashes.
    w.control('lbl_siegeDate')?.setText?.(this.u(UI.date, '<MONTH> / <DAY> / <YEAR>').replace('<MONTH>', pad(d.getUTCMonth() + 1)).replace('<DAY>', pad(d.getUTCDate())).replace('<YEAR>', d.getUTCFullYear()).replace(/<\/?(color|center|font)[^>]*>/gi, '').trim());
    w.control('edit_time')?.setValue?.(String(d.getUTCHours()));
    this.show(w); return w;
  }
  gate(brick) { return this.st?.gates?.find(g => g.brick === brick) || null; }
  async openUpgrade(brick, npc) {
    const s = this.st; if (!s) return null;
    if (!s.owner?.master) return this.box(this.say(S.defenderOnly));
    const g = this.gate(brick), w = await this.win('upgrade'); if (!w || !g) return null;
    this.cur.upgrade = brick;
    w.control('lbl_title')?.setText?.(`${g.name}`);
    w.control('lbl_maxdef_value')?.setText?.(numText(g.max)); w.control('lbl_def_value')?.setText?.(numText(g.hp));
    w.control('lbl_dil_value')?.setText?.(numText(this.game.network?.self?.profile?.dil ?? this.game.save?.dil ?? 0));
    w.control('edit_invdil_value')?.setValue?.('');
    this.show(w); return w;
  }
  async confirmUpgrade(brick, dil) {
    const s = this.st, g = this.gate(brick), w = await this.win('gateinfo'); if (!w || !g) return null;
    const points = dil / s.cfg.upgradeCost, add = points * s.cfg.upgradeHp;
    w.control('lbl_invdil_value')?.setText?.(numText(dil)); w.control('lbl_addhp_value')?.setText?.(numText(add)); w.control('lbl_totalhp_value')?.setText?.(numText(Math.min(g.max, g.hp + add)));
    this.cur.gateinfo = { brick, dil };
    this.show(w); return w;
  }
  async gateStatus() {
    const s = this.st; if (!s) return null;
    const w = await this.win('gates'); if (!w) return null; this._fillGates(w, s); this.show(w);
    this.note(s.gates.map(g => `${g.name} ${numText(g.hp)} / ${numText(g.max)}`).join(' · '));
    return w;
  }
  async openTax() {
    const s = this.st; if (!s?.owner?.master || !s.tax) { if (s) void this.box(this.say(S.notDefender)); return null; }
    const w = await this.win('tax'); if (!w) return null;
    this._fillTax(w, s); this.show(w); return w;
  }
  _fillTax(w, s) {
    for (const r of s.tax?.days || []) {
      w.control(`lbl_money${r.day}`)?.setText?.(numText(r.amount));
      w.control(`btn_receive${r.day}`)?.setVisible?.(!r.collected && r.amount > 0); w.control(`pan_received${r.day}`)?.setVisible?.(r.collected);
    }
    const any = (s.tax?.days || []).some(r => !r.collected && r.amount > 0);
    w.control('btn_receive7')?.setVisible?.(any); w.control('pan_received7')?.setVisible?.(!any);
  }
  _fillGates(w, s) {
    GATE_PANELS.forEach((brick, i) => { const g = s.gates.find(x => x.brick === brick), p = w.control(`pan_gate_${i}`); if (!p || !g) return;
      p.control('processbar')?.setGauge?.(g.max ? g.hp / g.max : 0); p.control('destroy')?.setVisible?.(!!g.dead); });
  }
  _fillStones(w, s) {
    STONES.forEach((brick, i) => { const p = w.control(`pan_zeolite_${i}`), row = s.pendants?.find(r => r.brick === brick), obj = s.objects?.find(o => o.brick === brick); if (!p) return;
      const frac = obj ? (obj.dead ? 0 : obj.hp / obj.maxHp) : 1;
      p.control('processbar')?.setGauge?.(frac); p.control('lbl_percent')?.setText?.(`${Math.round(frac * 100)}%`);
      p.control('ownerMark')?.setVisible?.(!!row?.mine); p.control('otherguildhide')?.setVisible?.(!!row?.guild && !row.mine);
      p.control('guildBg')?.setVisible?.(false); p.control('guildicon')?.setVisible?.(false); });
  }
  _fillWar(w, s, now) {
    // LANE-61: ui_warstatewnd marks are 40x40 panels; the Global client fills them from the 40 px guildbg / guildicon atlases (decompile), not the 24 px _s cells.
    w.control('lbl_serverInfo')?.setText?.('Zenoa Castle');
    w.control('lbl_time')?.setText?.(s.phase === 'idle' ? '' : mmss(s.endAt - now));
    w.control('lbl_state')?.setText?.(plainText(this.u([290, s.phase === 'idle' ? (s.announced ? 111 : 116) : 112])));
    w.control('lbl_defenderName')?.setText?.(s.owner?.name || '-');
    if (s.owner?.mark) { w.control('pan_defMarkBg')?.setImage?.('none', 'guildbg', s.owner.mark.bg); w.control('pan_defMark')?.setImage?.('none', 'guildicon', s.owner.mark.icon); }
    for (let i = 0; i < 3; i++) { const r = s.seals[i]; w.control(`lbl_attackerName_${i}`)?.setText?.(r?.name || '');
      w.control(`pan_attMarkBg_${i}`)?.setVisible?.(!!r?.mark); w.control(`pan_attMark_${i}`)?.setVisible?.(!!r?.mark);
      if (r?.mark) { w.control(`pan_attMarkBg_${i}`)?.setImage?.('none', 'guildbg', r.mark.bg); w.control(`pan_attMark_${i}`)?.setImage?.('none', 'guildicon', r.mark.icon); } }
  }

  // ------------------------------------------------------------------ live
  get onCastle() { return Number(this.game.world?.info?.index) === (this.st?.map ?? 23) && !!this.st?.objects; }
  isFoe(a) { return this.onCastle && siegePlayerHostile(this.game, a, this.st?.foes); }
  update(dt) {
    this.forceAlarm.update();
    const g = this.game, n = g.network;
    if (n && this._net !== n && typeof n._event === 'function') {
      this._net = n; const event = n._event.bind(n);
      n._event = record => {
        if (record?.type === 'siegeNotice') { const raw = record.text || (Array.isArray(record.code) ? fillText(this.t(record.code, ''), ...(record.args || [])) : ''); const text = plainText(raw); if (text) { this.note(text); void presentGlobalMessage(g, raw, text); } return; }
        event(record);
      };
      const hud = g.hud, showDeath = hud?.showDeath;
      if (hud && typeof showDeath === 'function' && !hud._siegeDeath) { hud._siegeDeath = true; hud.showDeath = (...args) => (this.st?.respawn ? undefined : showDeath.apply(hud, args)); }
    }
    if (n && this._actorNetwork !== n) { this._releaseActor?.(); this._actorNetwork=n; this._releaseActor=registerEventActors(n,'siege',id=>this._brickBy(id),30); }
    if (!g.isPvpHostile?._chained?.has('siege')) { const prev = g.isPvpHostile, f = a => this.isFoe(a) || !!prev?.(a); f._chained = new Set([...(prev?._chained || []), 'siege']); g.isPvpHostile = f; }
    const s = this.st;
    if (s !== this._last) { this._last = s; void this._sync(s).catch(() => {}); }
    for (const b of this.bricks.values()) if (!b.disposed) b.update?.(dt);
    if ((this._t = (this._t || 0) + dt) > 0.25) { this._t = 0; void this._timers(s).catch(() => {}); }
  }
  _brickBy(id) { for (const b of this.bricks.values()) if (b.networkId === id && !b.disposed) return b; return null; }
  _unpick(b) { const list = this.game.spawner?.monsters, i = list?.indexOf(b) ?? -1; if (i >= 0) list.splice(i, 1); if (this.game.player?.target === b) this.game.controller?.setTarget?.(null); }
  _clearBricks() { this.generation++; for (const b of this.bricks.values()) { this._unpick(b); b.dispose?.(); } this.bricks.clear(); }
  async _sync(s) {
    const W = this.game.uiwin;
    if (!this.onCastle) { this._clearBricks(); for (const k of [...HUD, 'attach', 'respawn']) this.wins[k]?.close?.('siege'); }
    else {
      const gen = this.generation, seen = new Set();
      for (const row of s.objects) {
        seen.add(row.id); let b = this.bricks.get(row.id);
        const def = this.data?.brick(row.brick); if (!def) continue;
        if (!b) { b = new Brick(this.game, def, { uid: row.uid, brick: row.brick, x: row.x, z: row.z, dir: row.dir, isCreate: 1 }); b.brain = null; b.networkId = row.id; this.bricks.set(row.id, b);
          void b.load?.().then(() => { if (gen !== this.generation) b.dispose?.(); }).catch(() => { b.dispose?.(); this.bricks.delete(row.id); }); }
        b.hp = row.hp; b.maxHp = b.maxHP = row.maxHp; b.isBrick = true;
        const breakable = !!row.breakable && !row.dead; b.kind = breakable ? 'monster' : 'brick'; b.breakable = breakable;
        const list = this.game.spawner?.monsters; if (breakable && list && !list.includes(b)) list.push(b); if (!breakable) this._unpick(b);
        if (row.dead && !b.dead) { b.dead = true; b.unblock?.(); if (b._specFor?.('die')) b.play?.('die', { loop: false, onEnd: () => { if (b.group) b.group.visible = false; } }); else if (b.group) b.group.visible = false; }
        else if (!row.dead && b.dead) { b.dead = false; if (b.group) b.group.visible = true; b.play?.('idle'); }
        if (!row.dead && !b.blocking) b.block?.(this.game.world?.collision);
      }
      for (const [id, b] of [...this.bricks]) if (!seen.has(id)) { this._unpick(b); b.dispose?.(); this.bricks.delete(id); }
      for (const k of HUD) this.show(await this.win(k));
    }
    if (this.wins.tax?.isOpen && s) this._fillTax(this.wins.tax, s);
    W?.strings && s && this.wins.gates?.isOpen && this._fillGates(this.wins.gates, s);
  }
  async _timers(s) {
    if (!s || !this.onCastle) return;
    const now = this.serverNow(), w = this.wins;
    if (w.war?.isOpen) this._fillWar(w.war, s, now);
    if (w.time?.isOpen) w.time.control('lbl_text')?.setText?.(plainText(fillText(this.u([290, 51]), Math.max(0, Math.ceil((s.endAt - now) / 60000)))));
    if (w.stones?.isOpen) this._fillStones(w.stones, s);
    if (w.gates?.isOpen) this._fillGates(w.gates, s);
    if (s.empathy) { const a = await this.win('attach'); if (a) { const left = s.empathy.endAt - now, total = s.empathy.endAt - s.empathy.startAt;
      a.control('lbl_waittime')?.setText?.(`${s.empathy.guildName}: ${plainText(fillText(this.u(UI.empathyLeft), Math.max(0, Math.ceil(left / 1000))))}`); a.control('processbar')?.setGauge?.(Math.max(0, Math.min(1, 1 - left / total))); this.show(a); } }
    else w.attach?.close?.('done');
    if (s.respawn) { const r = await this.win('respawn'); if (r) { const left = s.respawn.at - now;
      r.control('pan_list')?.setVisible?.(false);
      r.control('lbl_waittime')?.setText?.(`${plainText(this.t(s.respawn.location === 1 ? S.inner : S.outer))} - ${plainText(fillText(this.u(UI.respawnIn), Math.max(0, Math.ceil(left / 1000))))}`);
      r.control('processbar')?.setGauge?.(Math.max(0, Math.min(1, 1 - left / s.cfg.revivalMs))); this.show(r); } }
    else w.respawn?.close?.('done');
  }
}
