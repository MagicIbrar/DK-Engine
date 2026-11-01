// EVENT-MODES shared-world adapter: the Server Whole Competition (Race) windows and the host-owned Mission titles.
// The entered player's own state (phase, rank, kills, down, ranking) arrives with every state snapshot (snapshot.race, so a downed
// entrant that cannot send actions still sees it); the band list of the entry window is read with the race-info operation.
//   race_entree     game2/race/ui_entreeinfo.txt  title 100|128; header + one cloned pan_list row per band of this host
//                                                 (Server / Rank / Level / Users / Status / Entry, Refresh = RACE_CHOSEN.labels,
//                                                 because text2 210|1..7 is in no shipped string table); Entry -> race-entry
//   race_connectpc  game2/race/ui_connectpc.txt   title 100|129 'Entry Capacity'; pan_serverinfo row = entrants / LimitedCount
//                                                 while waiting for StartHour
//   race_dashboard  game2/race/ui_dashboard.txt   race#2 plate during the competition: rank, kills / deaths, time left
// The host (server/world/race.mjs) owns entry, spawn brackets, every hit (src/game/pvp-rules.js), respawn and the ranking;
// this file only shows its `race` state (event operation race-info) and sends its intents. Titles: game.life.grade.setTitle
// sends the `title` operation (server/world/titles.mjs) and game.life.grade.owns reads the host's profile.life.titles.
import { RACE_CHOSEN as C } from '../../config/engine-chosen-event-modes.js';
import { ownsTitle } from '../life/title-rules.js';

const DIR = 'game2/race/';
const ROW_H = 24, LIST_Y = 62;
// race 2 / 3 / 4 (war_01.dds regions) are blank in the shipped texture: RACE_CHOSEN.plateArt draws the plate instead.
const plate = el => { if (el) Object.assign(el.style, { background: C.plateArt.background, border: C.plateArt.border, boxSizing: 'border-box' }); };
const mmss = ms => { const s = Math.max(0, Math.ceil((Number(ms) || 0) / 1000)); return `${String(Math.floor(s / 60)).padStart(2, '0')}:${String(s % 60).padStart(2, '0')}`; };

export function installSharedRace(game, network) {
  let disposed = false, state = null, inflight = null, lastPoll = 0, lastSig = '';
  const serverNow = () => (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : Date.now());
  const err = e => game.chat?.system?.(e?.message || String(e), 'err');
  const send = async (operation, fields = {}) => {
    if (disposed || !network.active) return null;
    const r = await network.action('event', { operation, ...fields });
    if (r?.race) { state = r.race; game.events?.emit?.('race', { state }); }
    return r;
  };
  const poll = () => { if (inflight || disposed || !network.active || network.self?.dead) return inflight; lastPoll = performance.now(); inflight = send('race-info').catch(() => null).finally(() => { inflight = null; }); return inflight; };
  const run = () => state?.run || null;
  const inRace = () => { const r = run(); return !!r && r.inside && ['race', 'over'].includes(r.phase); };
  network.race = {
    state: () => state, info: poll, enter: map => send('race-entry', { map }).catch(err), leave: () => send('race-leave').catch(err),
    isEnemy: a => !!a && a.kind === 'player' && a !== game.player && run()?.phase === 'race' && (run().enemies || []).includes(a.networkId),
    serverNow,
  };
  const hostile = game.isPvpHostile;
  game.isPvpHostile = a => !!network.race?.isEnemy(a) || !!hostile?.(a);
  const hud = game.hud, showDeath = hud?.showDeath;
  if (hud && typeof showDeath === 'function') hud.showDeath = function (...args) { if (network.active && inRace()) return undefined; return showDeath.apply(this, args); };

  // ---- Mission titles: the host owns ownership and the shown title
  const grade = game.life?.grade, setTitle = grade?.setTitle, owns = grade?.owns;
  if (grade) {
    grade.owns = i => ownsTitle(game.save?.life?.titles, i);
    grade.setTitle = i => {
      const index = Number(i) || 0;
      if (index && !grade.owns(index)) return false;
      void network.action('event', { operation: 'title', title: index }).then(() => game.events?.emit?.('life:title', { index })).catch(err);
      return true;
    };
  }

  // ---- windows
  const ui = game.uiwin;
  const isOpen = n => !!ui?.window?.(n)?.isOpen;
  const open = n => { if (ui && !isOpen(n)) void ui.open(n); };
  const close = n => { const w = ui?.window?.(n); if (w?.isOpen) w.close(); };
  const text = (win, id, s) => { const c = win.find?.(id) || null; if (c) c.setText(String(s ?? '')); return c; };
  if (ui?.registerWindow) {
    const entree = {
      script: DIR + 'ui_entreeinfo.txt', escClose: true, remember: false,
      create(win) {
        win.control('btn_exit').onClick(() => win.close());
        win.control('btn_refresh').setText(C.labels.refresh).onClick(() => { void poll(); });
        for (const [id, k] of [['lbl_server', 'server'], ['lbl_rank', 'rank'], ['lbl_level', 'level'], ['lbl_usercount', 'users'], ['lbl_status', 'status']]) text(win, id, C.labels[k]);
        win.control('btn_entry').setVisible(false);
        win.data.rows = [];
      },
      onOpen(win) { win.data.sig = ''; void poll(); },
      update(win) {
        if (performance.now() - lastPoll > C.refreshMs) void poll();
        const rows = state?.rows || [], sig = JSON.stringify([rows, run()?.rank, run()?.map]);
        if (sig === win.data.sig) return; win.data.sig = sig;
        const tmpl = win.control('pan_list');
        rows.forEach((r, k) => {
          let row = win.data.rows[k];
          if (!row) {
            row = win.data.rows[k] = tmpl.cloneAs(`_r${k}`, { y: LIST_Y + ROW_H * (k + 1), visible: true });
            row.control?.(`btn_entry_r${k}`)?.setText(C.labels.entry).onClick(() => { const cur = state?.rows?.[k]; if (cur?.canEnter) void network.race.enter(cur.map).then(() => win.close()); });
          }
          row.setVisible(true);
          const mine = run()?.map === r.map;
          text(win, `lbl_server_r${k}`, r.server);
          text(win, `lbl_rank_r${k}`, mine && run()?.rank ? String(run().rank) : '-');
          text(win, `lbl_level_r${k}`, `Lv. ${r.minLevel} - ${r.maxLevel}`);
          text(win, `lbl_usercount_r${k}`, `${r.users} / ${r.limit}`);
          text(win, `lbl_status_r${k}`, r.status);
          const b = win.find?.(`btn_entry_r${k}`); if (b) { b.setVisible(true); b.setEnabled(!!r.canEnter); }
        });
        for (let k = rows.length; k < win.data.rows.length; k++) win.data.rows[k].setVisible(false);
      },
    };
    ui.registerWindow('race_entree', entree);
    ui.registerWindow('race_connectpc', {
      script: DIR + 'ui_connectpc.txt', hud: true, escClose: false, remember: false,
      create(win) {
        plate(win.control('pan_title').el);
        const row = win.control('pan_serverinfo').cloneAs('_cnt', { y: 27, visible: true });
        plate(row.el);
        win.data.label = win.control('lbl_title').cloneAs('_cnt', { parent: row, x: 0, y: 0, visible: true });
        win.data.label.setRect?.(0, 0, 139, 24);
      },
      update(win) {
        const r = run(); if (!r || r.phase !== 'entry') { win.close(); return; }
        win.data.label.setText(`${r.server}  ${r.users} / ${r.limit}  ${mmss(r.startAt - serverNow())}`);
      },
    });
    ui.registerWindow('race_dashboard', {
      script: DIR + 'ui_dashboard.txt', hud: true, escClose: false, remember: false,
      create(win) {
        plate(win.control('pan_back').el);
        const el = win.data.el = document.createElement('div');
        el.className = 'race-dashboard-text';
        Object.assign(el.style, { position: 'absolute', zIndex: '10', left: '0', top: '0', width: '237px', height: '71px', display: 'flex', flexDirection: 'column', justifyContent: 'center', alignItems: 'center', color: '#fff', font: '12px sans-serif', textShadow: '1px 1px 0 #000', pointerEvents: 'none', whiteSpace: 'pre' });
        win.root.el.appendChild(el);
      },
      update(win) {
        const r = run(); if (!r || !r.inside || !['race', 'over'].includes(r.phase)) { win.close(); return; }
        const left = r.phase === 'race' ? mmss(r.endAt - serverNow()) : C.status.over;
        win.data.el.textContent = `${C.labels.rank} ${r.rank ?? '-'} / ${r.users}\nKills ${r.kills}  Deaths ${r.deaths}\n${left}`;
      },
    });
  }
  game.chat?.registerCommand?.('/race', () => { if (isOpen('race_entree')) close('race_entree'); else open('race_entree'); return true; }, 'Open the Server Whole Competition window.');

  // ---- keep the HUD windows in step with the host state (snapshot.race of every state poll)
  const onRace = () => { const r = run(); if (!r) return; if (r.phase === 'entry') open('race_connectpc'); else if (r.inside && ['race', 'over'].includes(r.phase)) open('race_dashboard'); };
  game.events?.on?.('race', onRace);
  const snapshot = network._snapshot.bind(network);
  network._snapshot = record => {
    if (network.disposed || Number(record?.sequence) < network.sequence) return;
    snapshot(record);
    const view = record?.race || null, sig = JSON.stringify(view);
    if (sig === lastSig) return;
    lastSig = sig;
    if (view) state = view; else if (state?.run) state = { ...state, run: null }; else return;
    game.events?.emit?.('race', { state });
  };
  const dispose = network.dispose.bind(network);
  network.dispose = () => {
    disposed = true; network.race = null;
    if (hostile) game.isPvpHostile = hostile; if (hud && showDeath) hud.showDeath = showDeath;
    if (grade) { if (setTitle) grade.setTitle = setTitle; if (owns) grade.owns = owns; else delete grade.owns; }
    dispose();
  };
  return network.race;
}
