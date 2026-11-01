// TRAINING-CAMP client windows (original scripts script/ui/game2/trainingcamp/*.txt, strings stringtable_dksquare.txt
// cate 160, imagetable screen TrainingCamp = the ENGINE-CHOSEN rows of src/config/engine-chosen-training-camp.js). The host
// owns lobbies and battles (server/world/training-camp.mjs); these windows only show network.trainingCamp state and send
// its intents.
//   tc_active    ui_activeicon.txt        HUD icon (TrainingCamp 64) -> lobby list
//   tc_select    ui_selectwnd.txt         DK Square Lobby 160:13: No / Lobby Name / Participants / Waiting-In Battle / Join;
//                                         Open Lobby 160:20, refresh (TrainingCamp 11-13)
//   tc_alarm     ui_lobbyalarm.txt        HUD lobby-waiting icon (TrainingCamp 52 / blink 53) while waiting (160:41)
//   tc_waiting   ui_waitinginfownd.txt    Waiting Information 160:1-12, Cancel Joining 160:11
//   tc_confirm   ui_confirmwnd.txt        Caution for Entry 160:25, 160:48 countdown, OK 160:46 / Cancel 160:47
//   tc_time      ui_attachtimewnd.txt     battle time left (bar + MM:SS)
//   tc_progress  ui_circleprogresswnd.txt team balance: blue (Miseria) / red (Ricchez) share of the Battle points
//   tc_conquest  ui_conquesticon.txt      View Battle Information (160:40) -> tc_info
//   tc_mission   ui_missionwnd.txt        Mission Details 160:120 (shown at the battle start)
//   tc_msgbox    ui_tcampmsgbox.txt       160:303 at the start, 160:70 after the result
//   tc_info      ui_battleinfownd.txt     Battle Information 160:100-113, WIN / LOSE, Leave Now 160:71
import { str, needStrings } from '../hud-options/util.js';
import { classIconSprite } from '../../ui/atlas.js';
import { placeAlarmButton } from '../extras/alarm-slots.js';
import { TRAINING_CAMP_SCREEN as SCREEN } from '../../config/engine-chosen-training-camp.js';

const S = code => str(160, code) || '';
const plain = s => String(s || '').replace(/<\/?center>/gi, '').replace(/<\/?color[^>]*>/gi, '').replace(/\\\\|\\n|\n/g, ' ').replace(/\s+/g, ' ').trim();
const P = (s, ...v) => { let i = 0; return plain(s).replace(/%%/g, '%').replace(/%[sd]/g, () => String(v[i++] ?? '')); };
const sound = (game, k) => { try { game.audio?.ui?.(k); } catch { /* optional */ } };
const DIR = 'game2/trainingcamp/';
const TEAM_ART = [44, 45], STATE_ICON = { waiting: 15, battle: 16 }, WINLOSE = { win: 42, lose: 43 };

export function installTrainingCampWindows(game, network) {
  const T = () => network.trainingCamp, st = () => T()?.state() || {};
  const lob = () => st().lobby || null;
  const now = () => T()?.serverNow() ?? Date.now();
  const ui = game.uiwin; if (!ui?.registerWindow) return;
  void needStrings([['NORMAL', 160, 1], ['NORMAL', 160, 100], ['NORMAL', 160, 303]]).catch(() => {});
  const isOpen = n => !!ui.window?.(n)?.isOpen;
  const open = (n, a) => { if (!isOpen(n)) ui.open(n, a); };
  const close = n => { const w = ui.window?.(n); if (w?.isOpen) w.close(); };
  const battlePhase = l => !!l && ['fight', 'over'].includes(l.phase) && l.inside;

  ui.registerWindow('tc_active', { script: DIR + 'ui_activeicon.txt', hud: true, escClose: false, remember: false,
    create(win) { win.control('btn_active').onClick(() => (ui.toggle ? ui.toggle('tc_select') : ui.open('tc_select'))); },
    update(win) { placeAlarmButton(ui, win, win.control('btn_active'), ['attendance_alarm', 'connectreward_alarm', 'craftalarm']); } });
  ui.registerWindow('tc_alarm', { script: DIR + 'ui_lobbyalarm.txt', hud: true, escClose: false, remember: false,
    create(win) { win.control('btn_alarm').onClick(() => { const l = lob(); if (l?.phase === 'confirm' && !l.accepted) open('tc_confirm'); else open('tc_waiting'); }); },
    update(win) {
      const l = lob(); if (!l || !['waiting', 'confirm', 'starting'].includes(l.phase)) { win.close(); return; }
      win.control('btn_alarm').setBlink?.(l.phase === 'confirm' && !l.accepted);
      placeAlarmButton(ui, win, win.control('btn_alarm'), ['attendance_alarm', 'connectreward_alarm', 'craftalarm', 'tc_active']);
    } });

  // ---- lobby list
  const rowsOf = () => (st().lobbies || []).map(r => ({ data: r, cells: [String(r.no), r.name, P(S(35), r.players, r.max),
    { icon: { sprite: [SCREEN, r.inBattle ? STATE_ICON.battle : STATE_ICON.waiting] }, text: '' }, { text: plain(r.inBattle ? S(22) : S(23)), color: r.inBattle || r.players >= r.max ? '#808080' : '#ffffff' }] }));
  const selectDef = {
    script: DIR + 'ui_selectwnd.txt', escClose: true, remember: false,
    create(win) {
      win.control('btn_exit').onClick(() => win.close());
      win.control('btn_newcamp').onClick(() => { void T()?.open(); });
      win.control('btn_refresh').onClick(() => { win.data.sig = ''; selectDef.refresh(win); });
      const board = win.control('freeboard');
      board.on('cellclick', (i, ci, row) => { if (ci === board.cols.length - 1 && row?.data && !row.data.inBattle) void T()?.join(row.data.id); });
      board.on('dblclick', (i, row) => { if (row?.data && !row.data.inBattle) void T()?.join(row.data.id); });
      win.data.sig = '';
    },
    onOpen(win) { win.data.sig = ''; selectDef.refresh(win); },
    refresh(win) { const rows = rowsOf(), sig = JSON.stringify(rows.map(r => r.data)); if (sig === win.data.sig) return; win.data.sig = sig; win.control('freeboard').setRows(rows); win.control('btn_newcamp').setEnabled(!lob()); },
    update(win) { selectDef.refresh(win); if (lob()) win.close(); },
  };
  ui.registerWindow('tc_select', selectDef);

  // ---- waiting information
  const waitDef = {
    script: DIR + 'ui_waitinginfownd.txt', escClose: true, remember: false,
    create(win) { win.control('btn_exit').onClick(() => win.close()); win.control('btn_cancel').onClick(() => { void T()?.cancel(); win.close(); }); },
    onOpen(win) { waitDef.refresh(win); },
    refresh(win) {
      const l = lob(), R = st().rules || {}; if (!l) return;
      const mission = plain(S((R.mission || [160, 303])[1]));
      win.control('lbl_stateinfo').setText(P(S(2), l.start));
      win.control('lbl_inputnumber').setText(String(l.no)); win.control('lbl_inputkind').setText(mission);
      win.control('lbl_inputpeople').setText(String(l.max)); win.control('lbl_inputintrocount').setText(String(l.players));
      win.control('lbl_inputruntime').setText(P(S(36), l.playMinutes)); win.control('lbl_inputstartpeople').setText(P(S(37), l.start));
      win.control('lbl_inputmainmission').setText(mission); win.control('lbl_inputsubmission').setText('');
    },
    update(win) { const l = lob(); if (!l || !['waiting', 'confirm'].includes(l.phase)) { win.close(); return; } waitDef.refresh(win); },
  };
  ui.registerWindow('tc_waiting', waitDef);

  // ---- entry confirmation
  ui.registerWindow('tc_confirm', {
    script: DIR + 'ui_confirmwnd.txt', escClose: false, remember: false, band: 'modal',
    create(win) { win.control('btn_yes').onClick(() => { void T()?.accept(); win.close(); }); win.control('btn_no').onClick(() => { void T()?.decline(); win.close(); }); },
    update(win) {
      const l = lob(); if (!l || l.phase !== 'confirm' || l.accepted) { win.close(); return; }
      const left = Math.max(0, Math.ceil(((l.confirmEndsAt || 0) - now()) / 1000)), total = Math.max(1, (l.confirmEndsAt || 0) - (l.confirmAt || 0));
      win.control('lbl_msg').setText(P(S(48), left));
      win.control('processbar').setGauge(Math.max(0, Math.min(1, ((l.confirmEndsAt || 0) - now()) / total)));
    },
  });

  // ---- battle HUD
  const teamPoints = l => (l?.teams || []).map(t => t.points || 0);
  ui.registerWindow('tc_time', { script: DIR + 'ui_attachtimewnd.txt', hud: true, escClose: false, remember: false,
    update(win) {
      const l = lob(); if (!battlePhase(l)) { win.close(); return; }
      const t = now(), end = l.phase === 'over' ? l.finishAt : l.endsAt, total = l.phase === 'over' ? Math.max(1, (l.finishAt || 0) - (l.result?.at || l.endsAt || t)) : Math.max(1, (l.endsAt || 0) - (l.startAt || 0));
      const sec = Math.max(0, Math.ceil(((end || 0) - t) / 1000));
      win.control('lbl_waittime').setText(`${String(Math.floor(sec / 60)).padStart(2, '0')}:${String(sec % 60).padStart(2, '0')}`);
      win.control('processbar').setGauge(Math.max(0, Math.min(1, ((end || 0) - t) / total)));
    } });
  ui.registerWindow('tc_progress', { script: DIR + 'ui_circleprogresswnd.txt', hud: true, escClose: false, remember: false,
    update(win) {
      const l = lob(); if (!battlePhase(l)) { win.close(); return; }
      const [a = 0, b = 0] = teamPoints(l), share = a + b ? a / (a + b) : 0.5;
      win.control('pan_HorizenGage').setGauge(share);
      win.control('pan_bluegage').setVisible(a > b); win.control('pan_redgage').setVisible(b > a); win.control('pan_fullgage').setVisible(a === b);
    } });
  ui.registerWindow('tc_conquest', { script: DIR + 'ui_conquesticon.txt', hud: true, escClose: false, remember: false,
    create(win) { const b = win.control('btn_conquest'); b.onClick(() => (ui.toggle ? ui.toggle('tc_info') : ui.open('tc_info'))); b.setTooltip?.(() => plain(S(40))); },
    update(win) { if (!battlePhase(lob())) win.close(); } });
  ui.registerWindow('tc_mission', { script: DIR + 'ui_missionwnd.txt', escClose: true, remember: false,
    create(win) { win.control('btn_exit').onClick(() => win.close()); },
    update(win) { if (!battlePhase(lob())) win.close(); } });
  ui.registerWindow('tc_msgbox', { script: DIR + 'ui_tcampmsgbox.txt', hud: true, escClose: false, remember: false,
    onOpen(win, text) { win.data.until = performance.now() + 5000; win.data.text = text; win.control('lbl_text').setText(text || ''); },
    update(win) {
      const l = lob();
      if (l?.phase === 'over' && l.finishAt) { win.control('lbl_text').setText(P(S(70), Math.max(0, Math.ceil((l.finishAt - now()) / 1000)))); return; }
      if (performance.now() > (win.data.until || 0)) win.close();
    } });

  // ---- battle information
  const infoDef = {
    script: DIR + 'ui_battleinfownd.txt', escClose: true, remember: false,
    create(win) {
      win.data.team = -1;
      win.control('btn_exit').onClick(() => win.close());
      win.control('btn_out').onClick(() => { void T()?.leave(); win.close(); });
      win.control('btn_team_1').onClick(() => { win.data.team = 0; win.data.sig = ''; infoDef.refresh(win); });
      win.control('btn_team_2').onClick(() => { win.data.team = 1; win.data.sig = ''; infoDef.refresh(win); });
    },
    onOpen(win) { win.data.sig = ''; win.data.sec = win.data.ab = null; const l = lob(); win.data.team = l?.team >= 0 ? l.team : 0; infoDef.refresh(win); },
    refresh(win) {
      const l = lob(), r = st().result; if (!l && !r) return;
      const teams = l?.teams || r?.teams || [], mine = l?.team ?? r?.team ?? -1, t = win.data.team < 0 ? Math.max(0, mine) : win.data.team;
      const [a = 0, b = 0] = teamPoints({ teams });
      const over = (l?.phase || 'over') === 'over';
      const sec = over ? 0 : Math.max(0, Math.ceil(((l?.endsAt || 0) - now()) / 1000));
      if (win.data.ab !== `${a}:${b}`) { win.data.ab = `${a}:${b}`; win.control('number1').setNumber(a); win.control('number2').setNumber(b); }
      // redraw the imagenumber only when the second changes: a per-frame redraw keeps replacing the glyph whose atlas sprite is still loading
      const timer = win.control('number_timer'); if (win.data.sec !== sec) { win.data.sec = sec; if (timer.setTime) timer.setTime(sec); else timer.setNumber(sec); }
      timer.setVisible(!over);
      win.control('pro_gage').setGauge(a + b ? a / (a + b) : 0.5);
      const outcome = r?.outcome || (l?.winner == null ? null : l.winner < 0 ? 'draw' : l.winner === mine ? 'win' : 'lose');
      const wl = win.control('pan_winlose'); wl.setVisible(over && (outcome === 'win' || outcome === 'lose'));
      if (outcome === 'win' || outcome === 'lose') wl.setImage('none', SCREEN, WINLOSE[outcome]);
      win.control('btn_team_1').setChecked?.(t === 0); win.control('btn_team_2').setChecked?.(t === 1);
      const sorted = team => [...(team?.members || [])].sort((x, y) => (y.total - x.total) || (y.battle - x.battle) || String(x.name).localeCompare(String(y.name)));
      const row = (m, i) => ({ data: m, cells: [String(i + 1), m.name, { icon: { sprite: classIconSprite(m.classIndex) }, text: '' }, '', String(m.level || ''), '', String(m.battle), String(m.mission), String(m.bonus), String(m.total)] });
      const sig = JSON.stringify([teams, t, over, outcome]);
      if (sig !== win.data.sig) { win.data.sig = sig; win.control('freeboard1').setRows(sorted(teams[t]).map(row)); }
      const myTeam = teams[mine], me = myTeam?.members?.find(m => m.id === network.self?.id);
      const rank = me ? sorted(myTeam).indexOf(me) + 1 : '';
      win.control('lbl_myindex').setText(String(rank)); win.control('lbl_myname').setText(me?.name || '');
      win.control('pan_myclass').setImage('none', SCREEN, 32); win.control('lbl_myserver').setText(''); win.control('lbl_mylevel').setText(String(me?.level || ''));
      win.control('lbl_mygrade').setText(''); win.control('lbl_mykill').setText(String(me?.battle ?? 0)); win.control('lbl_mymission').setText(String(me?.mission ?? 0));
      win.control('lbl_mybonus').setText(String(me?.bonus ?? 0)); win.control('lbl_mytotal').setText(String(me?.total ?? 0));
      const end = win.control('lbl_endmessage'); end.setVisible(over && !!l?.finishAt);
      if (over && l?.finishAt) end.setText(P(S(70), Math.max(0, Math.ceil((l.finishAt - now()) / 1000))));
      win.control('btn_out').setVisible(over && !!l?.inside);
    },
    update(win) { const l = lob(); if (!l && !st().result) { win.close(); return; } infoDef.refresh(win); },
  };
  ui.registerWindow('tc_info', infoDef);

  // ---- state transitions
  let last = {};
  game.events?.on?.('trainingcamp', ({ state }) => {
    const s = state || {}, l = s.lobby || null, p = last.lobby || null;
    if (l && ['waiting', 'confirm'].includes(l.phase)) { open('tc_alarm'); if (!p) { open('tc_waiting'); close('tc_select'); } }
    if (l?.phase === 'confirm' && !l.accepted && p?.phase !== 'confirm') { open('tc_confirm'); sound(game, 'pvpAccept'); }
    if (battlePhase(l)) { open('tc_time'); open('tc_progress'); open('tc_conquest'); }
    if (battlePhase(l) && l.phase === 'fight' && !(p && p.phase === 'fight' && p.inside)) { close('tc_waiting'); close('tc_confirm'); open('tc_mission'); open('tc_msgbox', plain(S(303))); sound(game, 'pvpStart'); }
    if (s.result && s.result.at !== last.result?.at) {
      open('tc_info'); open('tc_msgbox', '');
      sound(game, s.result.outcome === 'win' ? 'pvpVictory' : 'pvpDefeat');
    }
    if (s.notice && s.notice.at !== last.notice?.at) {
      const text = s.notice.reason === 'cancelled' ? S(49) : s.notice.reason === 'someCancelled' ? S(98) : '';
      if (text) game.chat?.system?.(plain(text), 'sys');
    }
    if (network.active && !isOpen('tc_active') && !battlePhase(l)) open('tc_active');
    if (battlePhase(l) && isOpen('tc_active')) close('tc_active');
    last = s;
  });
}