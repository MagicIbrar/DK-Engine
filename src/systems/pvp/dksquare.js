import { applyInvitationPreference } from '../hud-options/invitation-policy.js';
// DK-SQUARE client (shared play): npc job 48 ARENA_SQUARE (npcs 121 / 720 / 5167) opens the DK Square Lobby; the host
// (server/world/dk-square.mjs, action 'dksquare', snapshot field dkSquare) owns lobbies, teams, points and settlement; these
// windows only show its state and send intents. Original windows of script/ui/game2/dksquare (strings cate 160 / 161 / 162):
//   dk_active   ui_activeicon.txt              HUD icon -> lobby list (only while the DK Square hours are open)
//   dk_select   ui_selectwnd.txt               DK Square Lobby 160:13: No / Lobby Name / Participants / Waiting-In Battle / Join
//   dk_create   ui_createdksquarewnd.txt       Caution for Entry 160:25 before Open Lobby (rank band 160:503/504, 160:130)
//   dk_alarm    ui_lobbyalarm.txt              Lobby Waiting icon (160:41), tooltip 160:44
//   dk_waiting  ui_waitinginfownd.txt          Waiting Information 160:1-12, Cancel Joining 160:11
//   dk_confirm  ui_confirmwnd.txt              entry confirmation 160:48 / raid 160:79 countdown, OK 160:46 / Cancel 160:47
//   dk_time     ui_attachtimewnd.txt           battle time left
//   dk_points   ui_dksquareactivitypointwnd.txt personal points / ActiveScore
//   dk_gauge    ui_circleprogresswnd.txt       Sunstone communion progress (blue = own team, red = the other)
//   dk_icon     ui_conquesticon.txt            View Battle Information (160:40)
//   dk_mission  ui_missionwnd.txt              Mission Details 160:120 (160:301-303)
//   dk_msgbox   ui_msgbox.txt                  160:70 countdown after the result
//   dk_info     ui_battleinfownd_renew2.txt    Battle Information / Result (shared filler of src/systems/arena/arena.js)
//   dk_board    ui_rankboardwnd.txt            DP Score rank board (162:1-6)
// Every gap value: src/config/engine-chosen-dk-square.js (ENGINE-CHOSEN). No PvP number lives here (src/game/pvp-rules.js on the host).
import { DK_SQUARE_CHOSEN as C } from '../../config/engine-chosen-dk-square.js';
import { DK_SQUARE_JOB, DK_SQUARE_SCRIPTS as W, DK_SQUARE_TEXT } from './dksquare-rules.js';
import { SUNSTONE_JOB, fmtClock } from '../arena/arena-rules.js';
import { arenaString, fillBattleInfo, fillBoard, teamLabel } from '../arena/arena.js';
import { placeAlarmButton } from '../extras/alarm-slots.js';
import {atlas} from '../../ui/atlas.js';
import {repairDkSquareDownScroll} from '../../ui/native-scroll-art.js';
import {teamStonesFor} from '../network/team-stones.js';

const plain = s => String(s ?? '').replace(/<\/?center>/gi, '').replace(/<\/?color[^>]*>/gi, '').replace(/@<effectui>[^\s]*/g, '').replace(/\\n/g, '\n').trim();
const fmt = (s, ...v) => { let i = 0; return String(s).replace(/%%/g, '%').replace(/%[sd]/g, () => String(v[i++] ?? '')); };
const S = (game, code, fallback = '') => arenaString(game, 160, code, fallback);
const RANK_BAND = { 7: 503, 8: 504 };   // DK Square Rank A / Rank S: Lv.%d - Lv.%d
const BLANK = { open: false, rank: null, lobbies: [], lobby: null, battle: null, result: null, notice: null, record: null };

/** Lobby list rows for the ui_selectwnd freeboard (5 nodes: No / Lobby Name / Participants / state icon + text / Join). */
export function lobbyRows(game, state) {
  return (state?.lobbies || []).map(r => ({ data: r, cells: [String(r.no), r.name, fmt(S(game, 35, '%d/%d'), r.players, r.max),
    { icon: { sprite: ['DKSquare', r.inBattle ? 16 : 15] }, text: S(game, r.inBattle ? 22 : 21, r.inBattle ? 'In Battle' : 'Waiting') },
    { text: S(game, 23, 'Join'), color: r.closing || r.players >= r.max ? '#808080' : '#ffffff' }] }));
}
/** Waiting Information values (ui_waitinginfownd). */
export function waitingValues(game, lobby) {
  const mission = S(game, (lobby?.missions || [])[0] || 301, '');
  return { lbl_stateinfo: plain(fmt(S(game, 2, 'If %d players complete the team, it will be set randomly and teleported to the battlefield.'), lobby.start)).replace(/\\/g, ','),
    lbl_inputnumber: String(lobby.no), lbl_inputkind: mission, lbl_inputpeople: String(lobby.max), lbl_inputintrocount: String(lobby.players),
    lbl_inputruntime: fmt(S(game, 36, '%d min'), lobby.playMinutes), lbl_inputstartpeople: fmt(S(game, 37, '%d'), lobby.start),
    lbl_inputmainmission: mission, lbl_inputsubmission: (lobby.missions || []).slice(1).map(c => S(game, c, '')).filter(Boolean).join(' / ') };
}

export function installSharedDkSquare(game, network) {
  let disposed = false, refresh = null;
  const st = () => network.dkSquareState || BLANK;
  const online = () => !!network?.active && game.save?.authority === 'server';
  const now = () => (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : Date.now());
  const report = e => { const m = plain(e?.message || String(e)); (game.chat?.system?.(m, 'err')) ?? game.hud?.log?.(m, 'err'); };
  const say = m => { const s = plain(m); if (s) (game.chat?.system?.(s)) ?? game.hud?.log?.(s); };
  const send = async (operation, fields = {}) => {
    if (disposed || !network.active) return null;
    try { const r = await network.action('dksquare', { operation, ...fields }); return r?.dkSquareResult ?? null; } catch (e) { report(e); return null; }
  };
  const lobby = () => st().lobby, battle = () => st().battle;
  const inBattle = () => !!battle()?.inside;
  let lastNpc = null;
  network.dkSquare = {
    state: st, send, list: () => send('list'), open: () => send('open', lastNpc != null ? { npcIndex: lastNpc } : {}),
    join: lobbyId => send('join', { lobbyId, ...(lastNpc != null ? { npcIndex: lastNpc } : {}) }), cancel: () => send('cancel'),
    accept: () => send('accept'), decline: () => send('decline'), leave: () => send('leave'), commune: () => send('commune'), board: () => send('board'),
    isEnemy: a => !!a && a.kind === 'player' && a !== game.player && battle()?.phase === 'fight' && (battle().enemies || []).includes(a.networkId),
  };
  const hostile = game.isPvpHostile;
  game.isPvpHostile = a => !!network.dkSquare?.isEnemy(a) || !!hostile?.(a);
  const revive = network.revive?.bind(network);
  if (revive) network.revive = () => (inBattle() && battle().me.down ? send('revive') : revive());
  // map 67 squad protection stones (host server/world/team-stones.mjs): native brick models, HP, targeting
  const stones = teamStonesFor(game, network);
  const snapshot = network._snapshot?.bind(network);
  if (snapshot) network._snapshot = record => {
    if (network.disposed || Number(record?.sequence) < network.sequence) return;
    const prev = network.dkSquareState;
    network.dkSquareState = record?.dkSquare || BLANK;
    snapshot(record);
    stones.sync('dkSquare', network.dkSquareState.battle);
    register();
    game.events?.emit?.('dksquare', { state: network.dkSquareState, prev });
    const busy = !!lobby();
    if (busy && !refresh) refresh = setInterval(() => void send('list'), C.refreshMs);
    if (!busy && refresh) { clearInterval(refresh); refresh = null; }
  };
  const dispose = network.dispose?.bind(network);
  if (dispose) network.dispose = () => { disposed = true; if (refresh) clearInterval(refresh); network.dkSquareState = null; network.dkSquare = null; if (hostile) game.isPvpHostile = hostile; if (revive) network.revive = revive; dispose(); };

  // ---- npc jobs 48 (lobby list) and 52 (Sunstone inside a DK Square battle)
  async function openLobbyList(npcIndex) {
    if (Number.isInteger(npcIndex)) lastNpc = npcIndex;
    const res = await send('list'); if (!res) return;
    if (res.lobby) { game.uiwin?.open?.(res.lobby.phase === 'waiting' || res.lobby.phase === 'confirm' ? 'dk_waiting' : 'dk_info'); return; }
    if (!res.open) { await game.uiwin?.msgbox?.(DK_SQUARE_TEXT.closed, { title: S(game, 13, 'DK Square Lobby'), kind: 'ok' }); return; }
    if (!res.rank) { report(new Error(DK_SQUARE_TEXT.level)); return; }
    game.uiwin?.open?.('dk_select');
  }
  const handlers = {
    [DK_SQUARE_JOB]: (n, info) => { if (!online()) return false; game.uiwin?.close?.('npc'); void openLobbyList(Number(info?.npcIndex ?? n?.npcIndex ?? n?.index ?? n?.def?.index)); return true; },
    [SUNSTONE_JOB]: () => { if (!online() || !inBattle()) return false; game.uiwin?.close?.('npc'); void send('commune').then(r => { if (r?.communing) say(S(game, 206, '')); }); return true; },
  };
  let services = null;
  function register() {
    const s = game.npcServices; if (!s?.register) return;
    for (const [job, h] of Object.entries(handlers)) {
      const list = s.handlers instanceof Map ? s.handlers.get(Number(job)) : null;
      if (Array.isArray(list)) { if (!list.includes(h)) list.unshift(h); }
      else if (services !== s || s.get?.(Number(job)) !== h) s.register(Number(job), h);
    }
    services = s;
  }
  register(); game.events?.on?.('systems', register);
  game.chat?.registerCommand?.('/dksquare', () => { void openLobbyList(); return true; }, 'Show the DK Square Lobby.');
  game.chat?.registerCommand?.('/dkboard', () => { void (async () => { const r = await send('board'); if (r?.board) { game.uiwin?.open?.('dk_board'); fillBoard(game, game.uiwin.window('dk_board'), r.board, network.self?.id ?? game.player?.id); } })(); return true; }, 'Show the DP Score rank board.');
  installDkSquareWindows(game, network);
  return network.dkSquare;
}

export function installDkSquareWindows(game, network) {
  const ui = game.uiwin; if (!ui?.registerWindow) return;
  const D = () => network.dkSquare, st = () => D()?.state() || BLANK, lob = () => st().lobby, bat = () => st().battle;
  const now = () => (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : Date.now());
  const isOpen = n => !!ui.window?.(n)?.isOpen;
  const open = (n, a) => { if (!isOpen(n)) ui.open(n, a); };
  const close = n => { const w = ui.window?.(n); if (w?.isOpen) w.close(); };
  const inside = () => !!bat()?.inside;
  const selfId = () => network.self?.id ?? game.player?.id;

  ui.registerWindow('dk_active', { script: W.active, hud: true, escClose: false, remember: false,
    create(win) { win.control('btn_active').onClick(() => (ui.toggle ? ui.toggle('dk_select') : ui.open('dk_select'))); win.control('btn_active').setTooltip?.(() => S(game, 13, 'DK Square Lobby')); },
    update(win) { if (!st().open || !st().rank || lob()) { win.close(); return; } placeAlarmButton(ui, win, win.control('btn_active'), ['attendance_alarm', 'connectreward_alarm', 'craftalarm']); } });
  ui.registerWindow('dk_alarm', { script: W.alarm, hud: true, escClose: false, remember: false,
    create(win) { win.control('btn_alarm').onClick(() => { const l = lob(); if (l && !l.accepted && (l.phase === 'confirm' || l.raid)) open('dk_confirm'); else open('dk_waiting'); }); },
    update(win) {
      const l = lob(); if (!l || !(['waiting', 'confirm', 'starting'].includes(l.phase) || l.raid)) { win.close(); return; }
      win.control('btn_alarm').setBlink?.(!l.accepted && (l.phase === 'confirm' || l.raid));
      win.control('btn_alarm').setTooltip?.(() => plain(fmt(S(game, 44, 'Lobby No.: %d\nCurrent/Minimum Participants to start: %d / %d\n\nMaximum Participants: %d\nBattle Mode: %s'), l.no, l.players, l.start, l.max, S(game, (l.missions || [])[0] || 301, ''))));
      placeAlarmButton(ui, win, win.control('btn_alarm'), ['attendance_alarm', 'connectreward_alarm', 'craftalarm', 'dk_active']);
    } });

  // ---- lobby list + Open Lobby caution
  const selectDef = {
    script: W.select, escClose: true, remember: false,
    create(win) {
      repairDkSquareDownScroll(win.control('selectwnd_scroll_downbtn'),atlas.table);
      win.control('btn_exit').onClick(() => win.close());
      win.control('btn_newcamp').onClick(() => open('dk_create'));
      win.control('btn_refresh').onClick(() => { win.data.sig = ''; void D()?.list(); });
      const board = win.control('freeboard');
      board.on?.('cellclick', (i, ci, row) => { if (ci === (board.cols?.length ?? 5) - 1 && row?.data && !row.data.closing) void D()?.join(row.data.id); });
      board.on?.('dblclick', (i, row) => { if (row?.data && !row.data.closing) void D()?.join(row.data.id); });
      win.data.sig = '';
    },
    onOpen(win) { win.data.sig = ''; void D()?.list(); selectDef.refresh(win); },
    refresh(win) {
      const rows = lobbyRows(game, st()), sig = JSON.stringify(rows.map(r => r.data)); if (sig === win.data.sig) return; win.data.sig = sig;
      win.control('freeboard').setRows?.(rows); win.control('btn_newcamp').setEnabled?.(!lob());
      const r = st().rank; win.control('lbl_time_alarm').setText(r ? `${plain(fmt(S(game, RANK_BAND[r.rank] || 503, 'Lv.%d - Lv.%d'), r.minLevel, r.maxLevel))}  ${S(game, 130, '')}` : S(game, 130, ''));
    },
    update(win) { selectDef.refresh(win); if (lob()) win.close(); },
  };
  ui.registerWindow('dk_select', selectDef);
  ui.registerWindow('dk_create', { script: W.create, escClose: true, remember: false, band: 'modal',
    create(win) { win.control('btn_yes').onClick(() => { void D()?.open(); win.close(); }); win.control('btn_no').onClick(() => win.close()); },
    onOpen(win) {
      const r = st().rank; win.control('lbl_title').setText(S(game, 25, 'Caution for Entry'));
      win.control('lbl_msg').setText([S(game, 20, 'Open Lobby'), r ? plain(fmt(S(game, RANK_BAND[r.rank] || 503, 'Lv.%d - Lv.%d'), r.minLevel, r.maxLevel)) : '', r ? `${r.enterCost} DIL` : '', S(game, 130, '')].filter(Boolean).join('\n'));
      for (const id of ['pan_progressBg', 'processbar', 'check_autoenter']) win.control(id).setVisible?.(false);
    } });

  // ---- waiting information + entry / raid confirmation
  const waitDef = {
    script: W.waiting, escClose: true, remember: false,
    create(win) { win.control('btn_exit').onClick(() => win.close()); win.control('btn_cancel').onClick(() => { void D()?.cancel(); win.close(); }); },
    onOpen(win) { waitDef.refresh(win); },
    refresh(win) { const l = lob(); if (!l) return; for (const [id, v] of Object.entries(waitingValues(game, l))) win.control(id).setText(v); },
    update(win) { const l = lob(); if (!l || !['waiting', 'confirm'].includes(l.phase)) { win.close(); return; } waitDef.refresh(win); },
  };
  ui.registerWindow('dk_waiting', waitDef);
  ui.registerWindow('dk_confirm', { script: W.confirm, escClose: false, remember: false, band: 'modal',
    create(win) { win.control('btn_yes').onClick(() => { void D()?.accept(); win.close(); }); win.control('btn_no').onClick(() => { void D()?.decline(); win.close(); }); win.control('check_autoenter').setVisible?.(true); win.control('check_autoenter').on?.('change', value => game.options?.set?.({dkAutoEnter:!!value})); },
    update(win) {
      const l = lob(); if (!l || l.accepted || !(l.phase === 'confirm' || l.raid)) { win.close(); return; }
      const left = Math.max(0, Math.ceil(((l.confirmEndsAt || 0) - now()) / 1000)), total = Math.max(1, (l.confirmEndsAt || 0) - (l.confirmAt || 0));
      win.control('check_autoenter').setChecked?.(game.options?.get?.('dkAutoEnter') === true);
      win.control('lbl_title').setText(S(game, 25, 'Caution for Entry'));
      win.control('lbl_msg').setText(plain(fmt(S(game, l.raid ? 79 : 48, '(%d)'), left)));
      win.control('processbar').setGauge?.(Math.max(0, Math.min(1, ((l.confirmEndsAt || 0) - now()) / total)));
    } });

  // ---- battle HUD
  ui.registerWindow('dk_time', { script: W.time, hud: true, escClose: false, remember: false,
    update(win) {
      const b = bat(); if (!b?.inside) { win.close(); return; }
      const t = now(), end = b.phase === 'over' ? b.finishAt : b.endsAt, total = b.phase === 'over' ? C.finishWaitSec * 1000 : Math.max(1, (b.endsAt || 0) - (b.startAt || 0));
      win.control('lbl_waittime').setText(fmtClock((end || 0) - t));
      win.control('processbar').setGauge?.(Math.max(0, Math.min(1, ((end || 0) - t) / total)));
    } });
  ui.registerWindow('dk_points', { script: W.points, hud: true, escClose: false, remember: false,
    update(win) { const b = bat(); if (!b?.inside) { win.close(); return; } win.control('processbar').setGauge?.(b.activeScore ? Math.min(1, b.me.points / b.activeScore) : 0); } });
  ui.registerWindow('dk_gauge', { script: W.gauge, hud: true, escClose: false, remember: false,
    update(win) {
      const b = bat(), c = b?.sun?.communing; if (!b?.inside || !c) { win.close(); return; }
      win.control('pan_HorizenGage').setGauge?.(Math.min(1, Math.max(0, (now() - c.startAt) / Math.max(1, c.endsAt - c.startAt))));
      win.control('pan_bluegage').setVisible(c.team === b.team); win.control('pan_redgage').setVisible(c.team !== b.team); win.control('pan_fullgage')?.setVisible?.(false);
    } });
  ui.registerWindow('dk_icon', { script: W.icon, hud: true, escClose: false, remember: false,
    create(win) { const b = win.control('btn_conquest'); b.onClick(() => (ui.toggle ? ui.toggle('dk_info') : ui.open('dk_info'))); b.setTooltip?.(() => S(game, 40, 'View Battle Information')); },
    update(win) { if (!inside()) win.close(); } });
  ui.registerWindow('dk_mission', { script: W.mission, escClose: true, remember: false,
    create(win) { win.control('btn_exit').onClick(() => win.close()); },
    onOpen(win) { win.control('lbl_title').setText(S(game, 120, 'Mission Details')); },
    update(win) { if (!inside()) win.close(); } });
  ui.registerWindow('dk_msgbox', { script: W.msgbox, hud: true, escClose: false, remember: false,
    onOpen(win, text) { win.data.until = performance.now() + 5000; win.control('lbl_text').setText(text || ''); },
    update(win) {
      const b = bat();
      if (b?.phase === 'over' && b.finishAt && b.inside) { win.control('lbl_text').setText(plain(fmt(S(game, 70, 'The battle has ended. You will be moved out of the lobby in %d second(s).'), Math.max(0, Math.ceil((b.finishAt - now()) / 1000))))); return; }
      if (performance.now() > (win.data.until || 0)) win.close();
    } });
  const infoDef = {
    script: W.info, escClose: true, remember: false,
    create(win) {
      win.data.tab = null;
      win.control('btn_exit').onClick(() => win.close());
      for (let i = 0; i < 4; i++) win.control(`btn_team_${i + 1}`).onClick(() => { win.data.tab = i; infoDef.refresh(win); });
    },
    onOpen(win) { win.data.tab = null; infoDef.refresh(win); },
    refresh(win) {
      const b = bat(), r = st().result, result = b && r?.battle !== b.id ? null : r;
      if (!b && !r) return;
      fillBattleInfo(game, win, { battle: b, result, selfId: selfId(), tab: win.data.tab });
      const owner = b?.sun?.owner ?? -1;   // map 67 has the Sunstone: show its owner like the Draco battle does
      ['blue', 'red'].forEach((c, i) => { win.control(`pan_top_${c}_domi_score`).setVisible(!!b); for (let k = 1; k <= 4; k++) win.control(`pan_top_${c}_domi_score_0${k}`).setVisible(k === 1 && owner === i); });
    },
    update(win) { if (!bat() && !st().result) { win.close(); return; } infoDef.refresh(win); },
  };
  ui.registerWindow('dk_info', infoDef);
  ui.registerWindow('dk_board', { script: W.board, escClose: true, remember: false, create(win) { win.control('btn_exit').onClick(() => win.close()); } });

  // ---- state transitions
  let last = {}, lastAuto = false;
  game.events?.on?.('dksquare', ({ state }) => {
    const s = state || BLANK, l = s.lobby, p = last.lobby, b = s.battle, pb = last.battle;
    if (l && (['waiting', 'confirm'].includes(l.phase) || l.raid)) { open('dk_alarm'); if (!p) { if (!l.raid) open('dk_waiting'); close('dk_select'); } }
    const auto = acceptDkEntryPreference(game, l, () => D()?.accept());
    if (auto) close('dk_confirm');
    else if (l && !l.accepted && (lastAuto || (l.phase === 'confirm' && p?.phase !== 'confirm') || (l.raid && !p?.raid))) open('dk_confirm');
    if (b?.inside) { open('dk_time'); open('dk_points'); open('dk_icon'); if (b.sun?.communing) open('dk_gauge'); }
    if (b?.inside && b.phase === 'fight' && !(pb?.inside && pb.id === b.id)) {
      close('dk_waiting'); close('dk_confirm'); open('dk_mission');
      for (const code of b.missions || []) game.chat?.system?.(S(game, code, ''), 'sys');
    }
    if (b?.inside && b.phase === 'over' && pb?.phase === 'fight') open('dk_msgbox', '');
    if (s.result && s.result.at !== last.result?.at) { open('dk_info'); game.chat?.system?.(s.result.winner < 0 ? S(game, 633, '') : `${teamLabel(game, s.result.winner)}: ${s.result.outcome === 'win' ? 'WIN' : 'LOSE'}`, 'sys'); }
    if (s.notice && s.notice.at !== last.notice?.at) { const text = s.notice.reason === 'cancelled' ? S(game, 49, '') : s.notice.reason === 'someCancelled' ? S(game, 98, '') : ''; if (text) game.chat?.system?.(plain(text), 'sys'); }
    if (s.open && s.rank && !l && !isOpen('dk_active')) open('dk_active');
    last = s; lastAuto = auto;
  });
}

/** Native DK Auto Entrance only confirms a lobby the player has already joined. */
export function acceptDkEntryPreference(game, lobby, accept) {
  if (!lobby?.id || lobby.accepted || !(lobby.phase === 'confirm' || lobby.raid)) return false;
  return applyInvitationPreference(game, 'dkAutoEnter', String(lobby.id) + ':' + String(lobby.confirmAt) + ':' + String(lobby.confirmEndsAt), accept);
}
