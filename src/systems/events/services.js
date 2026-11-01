// NPC services of the event job types (share/creature/jobtypeconfig.csv names, events.json jobTypes):
//   37/38 RECORD/ENTER_PARTY_WAR (Dead Front officers), 98/99 (Ice Castle officers), 39 PARTY_WAR_REIGN (depots, run),
//   19 DUNGEON for the event instances (Colosseum Arena 615/616, Infinite Battle 153-155/613, Infinite Battle 2
//   228/229/534, Forgotten Shipwreck 234/263, Forbidden Fetters 260), 96/97 DK_CHANNEL_ENTER/LEAVE for the event lobbies
//   (84 Chain of Fire, 166 Frozen Valley, 714 Terra's Fangs lobby, 533 Mitera, 654 Theme Park, lounges 708-721),
//   137 GUILDWAR_HUNTING_ENTER (Defense Battle 707), and the PvP-only services, which keep working but answer with the
//   original texts because no other player will ever come (soloRules): 81/82/132 Colosseum waiting list (matching
//   window, colosseum 360|101), 85 ranking, 86-95/100 guild tournament, 93 guild battle, 48 DK Square, 130 Draco
//   battlefield, 111/115 Lost Horizon, 119 Zuto guardian stone, 125-129 siege, 40 observer.
// Entry rules are the data's: level (field.csv window within the maplist gate / dungeon greeting), items (Map of
// Fortress / Castle Key per tier, arena tickets), DIL fees; the checks use the original partywar / dungeon messages.
import { itemCount, removeItem, payDil, points } from './inventory.js';
import { plain, hudLog } from './text.js';
import {urbanWarfareUnavailableText} from './urban-warfare-routes.js';
import {serverDate} from '../../game/server-time.js';

export const EVENT_JOBS = new Set([37, 38, 98, 99, 39, 81, 82, 132, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 100, 130, 137, 40, 125, 126, 127, 128, 129, 119, 111, 115, 48]);
const INSTANCE_MAPS = new Set([615, 616, 153, 154, 155, 613, 228, 229, 534, 234, 263, 250, 260]);
const LOBBY_MAPS = new Set([84, 166, 714, 533, 654, 708, 709, 710, 711, 712, 713, 718, 719, 720, 721, 162, 45]);

export function installServices(game, sys) {
  const S = new Services(game, sys);
  sys.services = S;
  const register = (allowOwn) => {
    let reg = game.npcServices;
    if (!reg?.register) {
      if (!allowOwn) return;
      // no NPC-service registry (quests system absent): a minimal one, driven by the old NPC window's options
      reg = game.npcServices = makeRegistry(game);
    }
    if (S._reg === reg) return;
    S._reg = reg;
    const fn = (npc, info) => S.handle(npc, info);
    for (const key of new Set([19, 96, 97, ...EVENT_JOBS])) chain(reg, key, fn);
  };
  register(false);
  // once every system is installed: register on the final registry (or create one)
  game.events.on('systems', () => register(true));
}

function chain(reg, key, fn) {
  // the quests registry keeps a list per key and runs it in order: the events handler goes first (it only answers for
  // the event maps / event jobs and returns false otherwise, e.g. the dungeon system's job-19 entry still runs)
  if (reg.handlers instanceof Map && typeof reg.register === 'function') {
    const k = Number(key);
    const list = reg.handlers.get(k);
    if (Array.isArray(list)) { list.unshift(fn); return; }
    reg.register(k, fn);
    return;
  }
  let prev = null;
  try { prev = reg.get?.(key) || reg.handlers?.get?.(key) || reg.handlers?.[key] || null; } catch { prev = null; }
  reg.register(key, (npc, info) => {
    const r = fn(npc, info);
    if (r) return r;
    return typeof prev === 'function' ? prev(npc, info) : false;
  });
}

function makeRegistry(game) {
  const handlers = new Map();
  const reg = {
    handlers,
    register(key, fn) { handlers.set(key, fn); },
    get(key) { return handlers.get(key) || null; },
    dispatch(npc, o) {
      const fn = handlers.get(Number(o.jobType)) || handlers.get(o.role);
      return fn ? fn(npc, o) : false;
    },
  };
  const W = game.windows;
  if (W && typeof W._npcOption === 'function' && !W._eventsOptWrapped) {
    const orig = W._npcOption.bind(W);
    W._npcOption = (o) => {
      const npc = W._npc?.npc;
      let r = false;
      try { r = npc ? reg.dispatch(npc, o) : false; } catch (err) { console.error('[events] service', err); }
      if (r) { if (r !== 'keep') W.close('npc'); return; }
      orig(o);
    };
    W._eventsOptWrapped = true;
  }
  return reg;
}

class Services {
  constructor(game, sys) { this.game = game; this.sys = sys; }
  get data() { return this.sys.data; }

  /** Is (jobType, jobIndex) served by the events system? */
  isEventJob(jt, ji) {
    if (jt === 19) return INSTANCE_MAPS.has(ji);
    if (jt === 96) return LOBBY_MAPS.has(ji);
    if (jt === 97) return LOBBY_MAPS.has(Number(this.game.world?.info?.index));
    return EVENT_JOBS.has(jt);
  }

  /** npcServices entry point: truthy when handled. */
  handle(npc, info) {
    const jt = Number(info?.jobType), ji = Number(info?.jobIndex);
    if (!this.isEventJob(jt, ji)) return false;
    const page = this.jobPage(npc, jt, ji);
    if (!page) return false;
    if (typeof page === 'function') { page(); return true; }
    this.sys.dialog.open(npc, page);
    return true;
  }

  /** Full dialog page of an NPC whose jobs are all event jobs (windows.openNpc hook). */
  pageFor(npc) {
    const def = npc.def || {};
    const jobs = def.jobs || [];
    const greet = this.data.npc(def.index ?? npc.npcIndex)?.greeting || '';
    const options = [];
    for (const [jt, ji] of jobs) {
      if (jt === 39) continue;                         // depots belong to the Dead Front run
      options.push({ label: this.label(jt, ji), pick: () => { const p = this.jobPage(npc, Number(jt), Number(ji)); if (typeof p === 'function') p(); else if (p) this.sys.dialog.show({ title: npc.name, ...p }); } });
    }
    if (!options.length) return null;
    return { title: npc.name, text: greet, options, info: this.infoFor(jobs) };
  }

  label(jt, ji) {
    let l = this.data.ev.jobTypes?.[jt]?.label;
    // untranslated / mis-encoded labels (132 BATTLEROYAL_RENEW is Korean in the EU table): the classic job's label
    if (l && /[\u1100-\u11ff\u3130-\u318f\uac00-\ud7af\u4e00-\u9fff]/.test(l)) l = jt === 132 ? this.data.ev.jobTypes?.[82]?.label : null;
    if (jt === 19) return `${l || '[Mission]'} ${this.mapName(ji)}`.trim();
    return plain(l || `[${this.data.ev.jobTypes?.[jt]?.name || jt}]`);
  }
  mapName(m) { return String(this.game.mapRow?.(m)?.Name || this.data.map(m)?.name || `Map ${m}`).trim(); }

  /** Rules shown by the dialog's "See more" page. */
  infoFor(jobs) {
    const j = jobs.find(([t]) => [37, 38, 98, 99].includes(Number(t)));
    if (!j) return null;
    const mode = [98, 99].includes(Number(j[0])) ? 'iceCastle' : 'deadFront';
    const m = Number(j[1]);
    const f = this.data.field(mode, m) || {};
    const t = this.data.tierOf(mode, m);
    const item = mode === 'iceCastle' ? t?.tier.items?.castleKey : t?.tier.items?.mapOfFortress;
    const lv = f.entryLevel || f.level || [];
    const sched = (this.data.modes[mode]?.schedule || []).map(s => s.battleStart).join(', ');
    return {
      title: this.mapName(m),
      text: [
        `<color=fdb602>Entrance Level</color> ${lv[0] ?? '?'} ~ ${lv[1] ?? '?'}`,
        item ? `<color=fdb602>Required Item</color> ${this.data.itemName(item)}` : '',
        `<color=fdb602>Parties</color> ${f.maxParties ?? 4}`,
        `<color=fdb602>Battle</color> ${sched}`,
        `<color=fdb602>Victory Reward</color> ${Number(f.winRPoint || 0).toLocaleString('en-US')} R-Point`,
      ].filter(Boolean).join('\n'),
    };
  }

  // ------------------------------------------------------------------------------------------ jobs
  jobPage(npc, jt, ji) {
    switch (jt) {
      case 37: case 98: return () => this.apply(npc, jt === 98 ? 'iceCastle' : 'deadFront', ji);
      case 38: case 99: return () => this.enterPartyWar(npc, jt === 99 ? 'iceCastle' : 'deadFront', ji);
      case 19: return this.instancePage(npc, ji);
      case 96: return () => this.dkEnter(ji);
      case 97: return () => this.dkLeave();
      case 137: return () => this.enterDefense(npc);
      case 81: case 82: case 132: return () => this.waitingList(jt);
      case 85: return () => this.ranking();
      case 93: case 95: return () => this.say('stringtable_partywarui.txt', 2011, 554);
      case 86: return () => this.say('stringtable_colosseum.txt', 360, 181);
      case 87: return () => this.say('stringtable_colosseum.txt', 360, this.game.save?.guild ? 31 : 30);
      case 88: case 89: case 90: case 91: return () => this.say('stringtable_colosseum.txt', 360, 179);
      case 92: return () => this.say('stringtable_colosseum.txt', 360, 186);
      case 94: return () => this.say('stringtable_colosseum.txt', 360, 83);
      case 100: case 40: return () => this.say('stringtable_colosseum.txt', 360, 205);
      case 48: case 130: case 111: case 115: return () => this.say('stringtable_partywarui.txt', 2011, 554);
      case 119: return () => { this.sys.dialog.close(); this.game.uiwin?.msgbox(urbanWarfareUnavailableText(this.data), { kind: 'ok' }); };
      case 125: case 126: case 127: case 128: case 129: return () => this.siege(jt);
      default: return null;
    }
  }

  say(file, cate, code, kind = 'dialog') {
    const e = this.data.str(file, cate, code);
    const t = plain(e?.text || '');
    if (!t) return;
    this.sys.dialog.close();
    if (kind === 'msgbox') this.game.uiwin?.msgbox(t, { kind: 'ok' });
    else { hudLog(this.game, t.replace(/\n/g, ' '), 'sys'); this.game.uiwin?.msgbox(t, { kind: 'ok' }); }
  }
  pwSay(mode, cate, code) { this.say(mode === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt', cate, code); }
  pwText(mode, cate, code) { return plain(this.data.txt(mode === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt', cate, code)); }

  // ------------------------------------------------------------------------------------------ party war
  _pwCheck(mode, m, entering) {
    const f = this.data.field(mode, m);
    const t = this.data.tierOf(mode, m);
    if (!f || !t) { this.pwSay(mode, entering ? 200 : 100, entering ? 5 : 10); return null; }
    const lv = Number(this.game.save?.level) || 1;
    const [lo, hi] = f.entryLevel || f.level || [1, 250];
    if (lv < lo || lv > hi) { this.pwSay(mode, entering ? 200 : 100, entering ? 3 : 2); return null; }
    // Global partywar/field.csv ItemCode is the admission item (0 on all 25 Global fields => none); name-inferred tier maps/keys are not a rule.
    const item = Number(f.itemCode) || 0;
    if (item && itemCount(this.game, item) < 1) { this.pwSay(mode, entering ? 200 : 100, entering ? 1 : 4); return null; }
    return { f, t, item };
  }

  apply(npc, mode, m) {
    const ok = this._pwCheck(mode, m, false);
    if (!ok) return;
    const reg = (this.game.save.eventState ||= {}).partyWar ||= {};
    if (reg[mode] === m) { this.pwSay(mode, 100, 8); return; }
    reg[mode] = m;
    this.sys.dialog.close();
    hudLog(this.game, this.pwText(mode, 100, 1), 'sys');
    this.game.uiwin?.msgbox(this.pwText(mode, 100, 1), { kind: 'ok' });
  }

  enterPartyWar(npc, mode, m) {
    const ok = this._pwCheck(mode, m, true);
    if (!ok) return;
    // solo: RECORD + ENTER in one click (the officer's entry dialog #200|105 / #200|106)
    this.sys.dialog.show({
      title: npc.name,
      text: this.pwText(mode, 200, 105),
      options: [{ label: this.pwText(mode, 200, 106), pick: () => {
        this.sys.dialog.close();
        if (ok.item && !removeItem(this.game, ok.item, 1)) { this.pwSay(mode, 200, 1); return; }
        const reg = (this.game.save.eventState ||= {}).partyWar ||= {};
        reg[mode] = null;
        const s = this.data.fieldPoint(mode, m, ok.f.starts?.[0]);
        this.sys.enter(m, { mode, x: s?.x, z: s?.z, entry: 'officer' });
      } }],
    });
    return true;
  }

  // ------------------------------------------------------------------------------------------ instances
  instancePage(npc, m) {
    const mode = this.data.modeOf(m) || (m === 260 ? 'forbiddenShackles' : null);
    const dg = this.data.dg?.maps?.[m] || {};
    const noKo = s => (/[\uac00-\ud7a3]/.test(s) ? '' : s);            // untranslated (Korean) placeholder lines of the EU tables
    // <dlgdata o=0/> = the floor (Forbidden Fetters progress), <dlgdata o=1/> = the mode word of the mission line ("Easy")
    const modeWord = String(this.data.mapTxt(m, 2) || dg.mission || '').match(/[A-Za-z]+/)?.[0] || '';
    const floor = m === 260 ? (Number(this.game.save?.eventState?.fetters?.floor) || 1) : '';
    const title = plain(this.data.mapTxt(m, 1) || dg.title || this.mapName(m)).replace(/<dlgdata o=0\/?>/g, String(floor))
      .replace(/<dlgdata o=1\/?>/g, modeWord).replace(/<dlgdata[^>]*>/g, '').replace(/\s+/g, ' ').trim();
    const mission = noKo(plain(this.data.mapTxt(m, 2) || dg.mission || ''));
    const time = plain(this.data.mapTxt(m, 3) || dg.timeLimit?.text || '');
    const text = [title, mission, time].filter(Boolean).join('\n');
    return {
      title: npc.name, text,
      options: [{ label: this.data.txt('stringtable_colosseum.txt', 360, 75) || 'Enter', pick: () => this.enterInstance(npc, m, mode) },
        { label: this.data.txt('stringtable_colosseum.txt', 360, 82) || 'Close', pick: () => this.sys.dialog.close() }],
    };
  }

  enterInstance(npc, m, mode) {
    const g = this.game;
    const lv = Number(g.save?.level) || 1;
    const row = g.mapRow?.(m);
    const say = (code, dflt) => { const t = plain(this.data.mapTxt(m, code) || dflt); hudLog(g, t, 'err'); g.uiwin?.msgbox(t, { kind: 'ok' }); };
    let minLv = Number(row?.LimitMinLevel) || 1;
    const maxLv = Number(row?.LimitMaxLevel) || 250;
    let dil = 0, ticket = null;
    if (mode === 'colosseumArena') {
      const R = this.data.modes.colosseum?.arena?.rules || {};
      const c = m === 616 ? R.party : R.solo;
      minLv = c?.level ?? minLv; dil = c?.dil ?? 0; ticket = c?.ticket ?? null;
    } else if (mode === 'infiniteBattle') {
      const c = (this.data.modes.colosseum?.infiniteBattle || []).find(b => Number(b.map) === m);
      minLv = Number(c?.gate?.levels?.[0]) || minLv;
    }
    this.sys.dialog.close();
    if (lv < minLv || lv > maxLv) { hudLog(g, this.data.dg?.maps?.[m]?.messages?.[100]?.t ? plain(this.data.dg.maps[m].messages[100].t) : 'Your level is too low to enter.', 'err'); g.uiwin?.msgbox(`Lv. ${minLv}${maxLv < 250 ? ` ~ ${maxLv}` : '+'}`, { kind: 'ok' }); return; }
    if (dil && (Number(g.save?.dil) || 0) < dil) { say(100, 'Not enough DIL to enter.'); return; }
    if (ticket && itemCount(g, ticket) < 1) { say(101, 'Lack of required item to enter in Inventory.'); return; }
    if (dil) payDil(g, dil);
    if (ticket) removeItem(g, ticket, 1);
    // entry point: beside the exit NPC (Reezena) or the dungeon builder's spawn
    const dg = this.data.dg?.maps?.[m];
    const sp = dg?.spawn;
    let x = null, z = null;
    if (sp?.snap && Number.isFinite(Number(sp.snap[0]))) { x = Number(sp.snap[0]); z = Number(sp.snap[1]); }   // the builder's walkable cell
    else if (sp && sp.walk !== -1 && Number.isFinite(Number(sp.x))) { x = Number(sp.x) + 0.5; z = Number(sp.y) + 0.5; }
    const ex = (this.data.map(m)?.npcs || []).find(r => /reezena|rezeena|regina/i.test(this.data.npc(r[0])?.name || ''));
    if (x == null && ex) { x = Number(ex[1]); z = Number(ex[2]); }
    // never on top of the exit NPC: stand two cells in front of it (south of the ring on the Colosseum maps)
    if (x != null && ex && Math.hypot(x - Number(ex[1]), z - Number(ex[2])) < 1.5) z += 2;
    else if (x != null && !ex && /exit npc/i.test(sp?.src || '')) z += 2;          // spawn taken from the exit NPC's cell
    this.sys.enter(m, { mode: mode === 'forbiddenShackles' ? 'forbiddenShackles' : undefined, x, z, entry: 'npc' });
  }

  // ------------------------------------------------------------------------------------------ DK channel / lobbies
  dkEnter(m) {
    this.sys.dialog.close();
    const dk = this.data.map(m)?.dkMapList;
    const loc = dk?.locate || null;
    this.sys.enter(m, loc ? { x: Number(loc[0]) + 0.5, z: Number(loc[1]) + 0.5 } : {});
  }
  dkLeave() {
    this.sys.dialog.close();
    const r = this.game.respawnTarget?.(this.game.world?.info?.index);
    this.game.travel(r?.mapIndex ?? 3, r ? { x: r.x, z: r.z } : null);
  }

  enterDefense() {
    this.sys.dialog.close();
    const g = this.game;
    const row = g.mapRow?.(707);
    const lv = Number(g.save?.level) || 1;
    if (lv < (Number(row?.LimitMinLevel) || 200)) { g.uiwin?.msgbox(`Lv. ${Number(row?.LimitMinLevel) || 200}+`, { kind: 'ok' }); return; }
    const c = this.data.modes.guildWarHunting?.config || {};
    this.sys.enter(707, { x: (Number(c.StartX) || 397) + 0.5, z: (Number(c.StartY) || 410) + 0.5, entry: 'npc' });
  }

  // ------------------------------------------------------------------------------------------ PvP-only services
  async waitingList(jt) {
    this.sys.dialog.close();
    const C = 'stringtable_colosseum.txt';
    const br = jt === 82 || jt === 132;
    if (br) {
      const pt = this.data.modes.colosseum?.battleRoyal?.[jt === 132 ? 'renew' : 'classic']?.playtime || [];
      const h = serverDate().getUTCHours();
      const open = !pt.length || pt.some(p => h >= Number(p.StartTime) && h < Number(p.EndTime));
      if (!open) { this.say(C, 360, 166); return; }
      if (jt === 132) {
        const tk = this.data.modes.colosseum?.battleRoyal?.renew?.rows?.[0]?.EntranceIndex;
        if (tk && itemCount(this.game, tk) < 1) { this.say(C, 360, 99); return; }
      }
    }
    const mode = plain(this.data.txt(C, 360, br ? 8 : 9));
    hudLog(this.game, plain(this.data.txt(C, 360, 101)), 'sys');
    const r = await this.sys.ui.matching(null, plain(this.data.txt(C, 360, 6)).replace('%s', mode).replace(/<center>/g, ''));
    if (r) hudLog(this.game, plain(this.data.txt(C, 360, 120)), 'sys');
  }

  /**
   * Colosseum ranking (RANKING_SEARCH 85): the original game2/colosseum/ui_rankingwnd.txt. The ranking server only ever
   * holds this character, so the board is its own row (pan_base: rank, class, name, level, server, guild, 5 values).
   * Categories btn_total / btn_battleroyal / btn_partyranking (colosseum 360|63/8/65; value columns 44/45/46 score,
   * 47 wins, 49 defeats, 1 kills, 13 died: inferred order), periods btn_whole / btn_week / btn_month (74/36/37),
   * search (combo_search Ranking / Class / Name / Level, edit_min/max, edit_name, combo_class) filters that row;
   * My Ranking / My INFO. show it, My Guild needs a guild (360|30), My Friends has no data (360|83), Reset clears.
   */
  async ranking() {
    this.sys.dialog.close();
    const ui = this.game.uiwin;
    if (!ui) return;
    const C = 'stringtable_colosseum.txt';
    const T = (k, d = '') => plain(this.data.txt(C, 360, k) || d);
    try {
      const win = await ui.create('game2/colosseum/ui_rankingwnd.txt', { name: 'ev_ranking', disposeOnClose: true });
      ui.openWindow(win);
      const g = this.game, s = g.save || {};
      const ctl = (id) => win.control(id);
      const st = { cat: 'total', period: 'whole' };
      const cats = { total: ['btn_total', 44, 'colosseumPoint'], battleroyal: ['btn_battleroyal', 45, 'brPoint'], party: ['btn_partyranking', 46, 'partyPoint'] };
      const periods = { whole: 'btn_whole', week: 'btn_week', month: 'btn_month' };
      const className = () => String(g.player?.classDef?.name || g.data?.classByIndex?.(s.classIndex)?.name || s.className || '');
      const guild = () => String(s.guild?.name || s.guildName || g.guild?.name || '');
      const showRow = (on, notice = '') => {
        ctl('pan_base').setVisible(on);
        ctl('lbl_notice').setText(notice);
        if (!on) return;
        const p = points(g);
        const rec = (s.eventState?.colosseum?.[st.cat]) || {};
        ctl('lbl_rank').setText('1');
        ctl('lbl_name').setText(s.name || '');
        ctl('lbl_level').setText(String(s.level || 1));
        ctl('lbl_server').setText('Dekaron Online');
        ctl('lbl_guild').setText(guild());
        const pc = ctl('pan_class'); if (pc?.el) pc.el.title = className();
        const vals = [Number(p[cats[st.cat][2]]) || 0, rec.wins || 0, rec.defeats || 0, rec.kills || 0, rec.died || 0];
        ['a', 'b', 'c', 'd', 'e'].forEach((k, i) => ctl(`lbl_content_${k}`).setText(Number(vals[i]).toLocaleString('en-US')));
      };
      const header = () => {
        const cols = [T(cats[st.cat][1]), T(47, 'wins'), T(49, 'defeats'), T(1, 'Kills'), T(13, 'Died')];
        cols.forEach((t, i) => ctl(`lbl_content_${i}`).setText(t));
        for (const [k, [id]] of Object.entries(cats)) ctl(id).setChecked(k === st.cat);
        for (const [k, id] of Object.entries(periods)) ctl(id).setChecked(k === st.period);
      };
      const refresh = () => { header(); showRow(true); };
      for (const [k, [id]] of Object.entries(cats)) ctl(id).onClick(() => { st.cat = k; refresh(); });
      for (const [k, id] of Object.entries(periods)) ctl(id).onClick(() => { st.period = k; refresh(); });
      for (const id of ['btn_prev', 'btn_page', 'btn_next']) ctl(id).setVisible(false);    // one page
      const search = () => {
        header();
        const mode = ctl('combo_search').getText?.() || '';
        const lv = Number(s.level) || 1;
        const lo = ctl('edit_min').getValue?.() ?? '', hi = ctl('edit_max').getValue?.() ?? '';
        if ((lo && !/^\d+$/.test(lo)) || (hi && !/^\d+$/.test(hi))) { showRow(false, T(86)); return; }
        let ok = true;
        if (/level/i.test(mode) || mode === T(41)) ok = (!lo || lv >= Number(lo)) && (!hi || lv <= Number(hi));
        else if (/rank/i.test(mode) || mode === T(67)) ok = (!lo || Number(lo) <= 1) && (!hi || Number(hi) >= 1);
        else if (/class/i.test(mode) || mode === T(39)) ok = !ctl('combo_class').getText?.() || ctl('combo_class').getText() === className();
        const name = String(ctl('edit_name').getValue?.() || '').trim();
        if (name) ok = ok && String(s.name || '').toLowerCase().includes(name.toLowerCase());
        showRow(ok, ok ? '' : T(83));
      };
      ctl('btn_search').onClick(search);
      ctl('edit_name').on?.('enter', search);
      ctl('btn_mygrade').onClick(refresh);
      ctl('btn_mycharacter').onClick(refresh);
      ctl('btn_myguild').onClick(() => { header(); if (guild()) showRow(true); else showRow(false, T(30)); });
      ctl('btn_myfriend').onClick(() => { header(); showRow(false, T(83)); });
      ctl('btn_reset').onClick(() => { for (const id of ['edit_min', 'edit_max', 'edit_name']) ctl(id).clear?.(); ctl('combo_search').select?.(0); refresh(); });
      ctl('btn_exit').onClick(() => win.close('ok'));
      refresh();
    } catch (err) {
      console.warn('[events] ranking window', err);
      this.say(C, 360, 83);
    }
  }

  /** Castle services (TAX_INFO 125, SENTRY_OPEN 126, SIEGE_DEFENDER/MASTER_TELEPORT 127/128, SIEGE_DEFENDER_SKILL 129).
   *  Solo: no guild ever holds the castle (the siege is guild PvP), so the castle NPCs answer with the original siege
   *  texts: 100|10 "This castle is not currently held by anyone..." / 700|4 "You are not a guild member." /
   *  800|24 "[ Only the master of defending guild is allowed ]". */
  siege(jt) {
    this.sys.dialog.close();
    const S = 'stringtable_siege.txt';
    const guild = !!(this.game.save?.guild || this.game.guild?.name);
    const [c, k] = (jt === 126 || jt === 129) ? (guild ? [800, 24] : [700, 4]) : [100, 10];
    const t = plain(this.data.txt(S, c, k) || this.data.txt('stringtable_partywarui.txt', 2011, 554) || '');
    if (t) this.game.uiwin?.msgbox(t, { kind: 'ok' });
  }
}
