// ARENA client (shared play): Draco Desert Battlefield (npc job 130, Draco Battle Herald) and the Lost Horizon battlefield
// (npc job 111, npc 5519); Sunstone communion (npc 6054, job 52). The host (server/world/arena.mjs, action 'arena') owns
// entry, teams, points and settlement; these windows only show its {arenaResult} and send intents. Original windows of
// script/ui/game2/dksquare/: ui_battleinfownd_renew2 (Battle Information 160:100 / Battle Result 160:618, team tabs
// 160:643-646, my row 160:113, Battle Reward 160:652), ui_conquesticon (View Battle Information 160:40),
// ui_dksquareactivitypointwnd (personal points / ActiveScore), ui_circleprogresswnd (communion gauge), ui_missionwnd
// (Mission Details 160:120), ui_losthorizon (team points left / right), ui_rankboardwnd (162:1-6). Values the data does not
// define: src/config/engine-chosen-arena.js (ENGINE-CHOSEN). No PvP number lives here (src/game/pvp-rules.js on the host).
import { ARENA_CHOSEN as C } from '../../config/engine-chosen-arena.js';
import { ARENA_JOBS, SUNSTONE_JOB, ARENA_SCRIPTS, ARENA_STRINGS, ARENA_TEXT, TEAM_NAME_CODES, TEAM_COLOURS, GRADE_NAME_CODES, fmtClock } from './arena-rules.js';
import { classIconSprite } from '../../ui/atlas.js';
import { teamStonesFor } from '../network/team-stones.js';

const plain = s => String(s ?? '').replace(/<\/?center>/gi, '').replace(/<\/?color[^>]*>/gi, '').replace(/@<effectui>[^\s]*/g, '').replace(/\\n/g, '\n').trim();
export function arenaString(game, cate, code, fallback = '') {
  const s = game?.uiwin?.strings?.get?.({ group: 'NORMAL', cate, code });
  return s == null ? fallback : plain(s);
}
const K = (game, key, fallback = key) => { const [c, n] = ARENA_STRINGS[key] || []; return c == null ? fallback : arenaString(game, c, n, fallback); };
const fmt = (s, ...v) => { let i = 0; return String(s).replace(/%%/g, '%').replace(/%[sd]/g, () => String(v[i++] ?? '')); };
export const teamLabel = (game, t) => arenaString(game, 160, TEAM_NAME_CODES[t], ['Miseria', 'Ricchez', 'Rebel', 'Terra'][t] || `Team ${t + 1}`);
export const gradeLabel = (game, code) => arenaString(game, 160, code, '');

/** ui_battleinfownd_renew2: teams of the battle (or the result), the chosen tab, my row and the reward panel. */
export function fillBattleInfo(game, win, { battle, result, selfId, tab = null }) {
  const teams = battle?.teams || result?.teams || [], over = !battle || battle.phase === 'over', winner = battle?.winner ?? result?.winner ?? null;
  const mine = battle?.team ?? result?.team ?? 0, t = tab == null ? Math.max(0, mine) : tab;
  win.control('lbl_title').setText(over ? K(game, 'result', 'Battle Result') : K(game, 'infoTitle', 'Battle Information'));
  win.control('pan_win_info').setVisible(over && winner != null);
  TEAM_COLOURS.forEach((c, i) => win.control(`pan_top_${c}_win`).setVisible(over && winner === i));
  win.control('pan_top_draw').setVisible(over && winner === -1);
  const owner = battle?.sun?.owner ?? -1;
  TEAM_COLOURS.forEach((c, i) => {
    win.control(`pan_top_${c}_domi_score`).setVisible(i < teams.length && battle?.venue === 'draco');
    for (let k = 1; k <= 4; k++) win.control(`pan_top_${c}_domi_score_0${k}`).setVisible(k === 1 && owner === i);
  });
  for (let i = 0; i < 4; i++) { const b = win.control(`btn_team_${i + 1}`); b.setVisible(i < teams.length); if (i < teams.length) b.setText(teamLabel(game, i)); b.setChecked?.(i === t); }
  const sorted = team => [...(team?.members || [])].sort((x, y) => (y.points - x.points) || (y.kills - x.kills) || String(x.name).localeCompare(String(y.name)));
  const dash = arenaString(game, 160, 616, '-');
  const grade = m => (m.gradeString != null ? gradeLabel(game, m.gradeString) || dash : dash);
  const rows = sorted(teams[t]).map((m, i) => ({ data: m, cells: [String(i + 1), m.name, { icon: { sprite: classIconSprite(m.classIndex) }, text: '' }, '', String(m.level || ''), grade(m), String(m.battle ?? 0), String(m.mission ?? 0), String(m.bonus ?? 0), String(m.points)] }));
  win.control('freeboard1').setRows?.(rows);
  const myTeam = teams[mine], me = myTeam?.members?.find(m => m.id === selfId);
  win.control('lbl_myinfo').setText(K(game, 'mine', 'My Information'));
  win.control('lbl_myrank').setText(me ? String(sorted(myTeam).indexOf(me) + 1) : '');
  win.control('lbl_myname').setText(me?.name || '');
  win.control('lbl_myserver').setText('');
  win.control('lbl_mylevel').setText(String(me?.level || ''));
  win.control('lbl_myachievement').setText(result ? gradeLabel(game, result.gradeString) || dash : me ? grade(me) : dash);
  win.control('lbl_mykill').setText(String(me?.battle ?? 0));
  win.control('lbl_mymission').setText(String(me?.mission ?? 0));
  win.control('lbl_mybonus').setText(String(me?.bonus ?? 0));
  win.control('lbl_mytotal').setText(String(me?.points ?? 0));
  const reward = win.control('pan_info_reward'); reward.setVisible(!!result);
  if (result) {
    win.control('lbl_tag_reward').setText(K(game, 'reward', 'Battle Reward'));
    const items = (result.items || []).map(it => `${game.items?.db?.def?.(it.index)?.name || game.itemDB?.def?.(it.index)?.name || `Item ${it.index}`} x${it.count}`);
    const lines = [`${gradeLabel(game, result.gradeString)} ${result.ratio}%`, result.achieved ? K(game, 'apOk', 'AP Achieved') : K(game, 'apNo', 'Not Achieved'),
      `${K(game, 'rankScore', 'Rank Score')} +${result.rankScore}`, `${K(game, 'dpDelta', 'DP+/-')} +${result.dpGain}`, ...items];
    win.control('lbl_reward_item_name').setText(lines.join('\n'));
  }
  return { rows, tab: t };
}
/** ui_losthorizon: team points as the left / right bars and numbers; the combo / attack counters have no data and stay hidden. */
export function fillHorizon(win, battle) {
  const [a = 0, b = 0] = (battle?.teams || []).map(x => x.points), total = a + b;
  win.control('bar_left').setGauge?.(total ? a / total : 0.5); win.control('bar_right').setGauge?.(total ? b / total : 0.5);
  win.control('num_left').setNumber?.(a); win.control('num_right').setNumber?.(b);
  for (const id of ['bar_left_combo', 'bar_left_timer', 'left_combo_num', 'left_attack_num', 'bar_right_combo', 'bar_right_timer', 'right_combo_num', 'right_attack_num']) win.control(id).setVisible(false);
  return [a, b];
}
/** ui_rankboardwnd: headers 162:1-6, own row in pan_RankInfo, the other rows drawn below it. */
export function fillBoard(game, win, rows, selfId) {
  win.control('lbl_title').setText(K(game, 'boardRank', 'Ranking'));
  for (const [id, key] of [['lbl_RankingTab', 'boardRank'], ['lbl_NameTab', 'boardName'], ['lbl_ClassTab', 'boardClass'], ['lbl_LevelTab', 'boardLevel'], ['lbl_DKTierTab', 'boardTier'], ['lbl_DPScoreTab', 'boardDp']]) win.control(id).setText(K(game, key));
  const own = rows.find(r => r.id === selfId) || rows[0] || null, dash = arenaString(game, 160, 616, '-');
  win.control('lbl_Name').setText(own ? `${own.rank}. ${own.name}` : dash);
  win.control('lbl_Class').setText(own ? String(game.classNames?.[own.classIndex] ?? own.classIndex) : dash);
  win.control('lbl_Level').setText(own ? String(own.level) : dash);
  win.control('lbl_DPScore').setText(own ? String(own.dp) : dash);
  win.control('pan_Tier').setTooltip?.(own?.tier || dash);
  win.control('lbl_bottominfo').setText(arenaString(game, 160, 138, ''));
  const host = win.control('pan_Rankboard').el;
  if (host?.ownerDocument) {
    host.querySelector?.('.arena-board-rows')?.remove();
    const box = host.ownerDocument.createElement('div'); box.className = 'arena-board-rows';
    Object.assign(box.style, { position: 'absolute', left: '36px', top: '110px', width: '565px', height: '460px', overflow: 'auto', font: '12px sans-serif', color: '#e8dcc0', pointerEvents: 'auto' });
    for (const r of rows.filter(x => x !== own)) {
      const line = host.ownerDocument.createElement('div'); Object.assign(line.style, { display: 'flex', height: '20px', lineHeight: '20px' });
      for (const [w, v] of [[94, r.rank], [145, r.name], [97, game.classNames?.[r.classIndex] ?? r.classIndex], [63, r.level], [81, r.tier || dash], [80, r.dp]]) { const c = host.ownerDocument.createElement('span'); c.style.width = `${w}px`; c.style.textAlign = 'center'; c.textContent = String(v); line.appendChild(c); }
      box.appendChild(line);
    }
    host.appendChild(box);
  }
  return own;
}
/** HUD lines (EventUI dungeonTimes): time left, Sunstone owner / keep countdown, personal points, revive countdown. */
export function battleLines(game, battle, now) {
  if (!battle) return [];
  const lines = [`<color=fdb602>${K(game, 'timeLeft', 'Time remaining')}:</color> ${fmtClock((battle.phase === 'over' ? battle.finishAt : battle.endsAt) - now)}`];
  if (battle.sun) {
    lines.push(`<color=fdb602>Sunstone:</color> ${battle.sun.owner >= 0 ? teamLabel(game, battle.sun.owner) : K(game, 'neutral', 'Neutral State')}`);
    if (battle.sun.owner >= 0 && battle.sun.keepEndsAt) lines.push(`<color=fdb602>${K(game, 'untilWin', 'Until team\'s victory:')}</color> ${fmtClock(battle.sun.keepEndsAt - now)}`);
    if (battle.sun.communing) lines.push(`<color=fdb602>${K(game, 'conquering', 'Conquering')}:</color> ${teamLabel(game, battle.sun.communing.team)} ${fmtClock(battle.sun.communing.endsAt - now)}`);
  }
  lines.push(`<color=fdb602>${teamLabel(game, battle.team)}:</color> ${battle.me.points}${battle.activeScore ? ` / ${battle.activeScore}` : ''}`);
  if (battle.me.down && battle.me.autoExitAt) lines.push(`${plain(ARENA_TEXT.revive).split('\n')[0]} ${fmtClock(battle.me.autoExitAt - now)}`);
  if (battle.phase === 'over' && battle.finishAt) lines.push(fmt(arenaString(game, 160, 70, 'The battle has ended. You will be moved out of the lobby in %d second(s).'), Math.max(0, Math.ceil((battle.finishAt - now) / 1000))).replace(/\n/g, ' '));
  return lines;
}

export function installSharedArena(game, network) {
  const st = { state: null, wins: {}, tab: null, refresh: null, checked: false, shownResult: null, missionShown: null, ui: null, lines: [] };
  const report = e => { const m = plain(e?.message || String(e)); (game.chat?.system?.(m, 'err')) ?? game.hud?.log?.(m, 'err'); };
  const say = m => { const s = plain(m); (game.chat?.system?.(s)) ?? game.hud?.log?.(s); };
  const online = () => !!network?.active && game.save?.authority === 'server';
  const now = () => (typeof network?.serverNow === 'function' ? network.serverNow() : Date.now());
  const battle = () => st.state?.battle || null;
  const send = async intent => { try { const r = await network.action('arena', intent); const res = r?.arenaResult || null; if (res) apply(res); return res; } catch (e) { report(e); return null; } };
  const create = async key => { const old = st.wins[key]; if (old && !old.disposed) return old; const w = await game.uiwin?.create?.(ARENA_SCRIPTS[key], { name: `arena_${key}` }); if (!w) return null; st.wins[key] = w; return w; };
  const close = key => { try { st.wins[key]?.close?.('arena'); } catch { /* closed */ } };
  const open = w => { if (w && !w.isOpen) game.uiwin.openWindow(w); };
  // map 702 squad guardian stones (host server/world/team-stones.mjs): native brick models, HP, targeting
  const stones = network ? teamStonesFor(game, network) : null;
  function apply(res) {
    const was = battle(); st.state = res; const b = battle();
    stones?.sync('arena', b);
    if (b && b.inside) void hud(b); else if (was) leftBattle();
    if (res.result && res.result.at !== st.shownResult) { st.shownResult = res.result.at; void showResult(res.result); }
    const busy = !!b || !!res.queued;
    if (busy && !st.refresh) st.refresh = setInterval(() => void send({ operation: 'info' }), C.refreshMs);
    if (!busy && st.refresh) { clearInterval(st.refresh); st.refresh = null; }
  }
  async function hud(b) {
    const icon = await create('icon'); if (icon && !icon._arenaWired) { icon._arenaWired = true; icon.control('btn_conquest').setTooltip?.(K(game, 'viewInfo', 'View Battle Information')); icon.control('btn_conquest').onClick(() => void openInfo()); }
    open(icon);
    if (b.venue === 'draco') {
      const pts = await create('points'); pts?.control('processbar').setGauge?.(b.activeScore ? Math.min(1, b.me.points / b.activeScore) : 0); open(pts);
      const g = await create('gauge'); const c = b.sun?.communing;
      if (g) { if (c) { const total = Math.max(1, c.endsAt - c.startAt); g.control('pan_HorizenGage').setGauge?.(Math.min(1, Math.max(0, (now() - c.startAt) / total))); g.control('pan_bluegage').setVisible(c.team === b.team); g.control('pan_redgage').setVisible(c.team !== b.team); open(g); } else close('gauge'); }
    } else { const h = await create('horizon'); if (h) { fillHorizon(h, b); open(h); } }
    if (st.missionShown !== b.id) {
      st.missionShown = b.id;
      for (const code of b.missions || []) say(arenaString(game, 160, code, ''));
    }
    if (st.wins.info?.isOpen) fillBattleInfo(game, st.wins.info, { battle: b, result: st.state?.result?.battle === b.id ? st.state.result : null, selfId: network.self?.id ?? game.player?.id, tab: st.tab });
    st.lines = battleLines(game, b, now());
    try { if (!st.ui) { const { EventUI } = await import('../events/windows.js'); st.ui = new EventUI(game, st); } await st.ui.dungeonTimes(st.lines); } catch { /* HUD optional */ }
  }
  function leftBattle() { for (const k of ['icon', 'points', 'gauge', 'horizon', 'mission']) close(k); game.uiwin?.close?.('ev_dtime'); st.missionShown = null; }
  async function openMission() { const m = await create('mission'); if (!m) return; m.control('lbl_title').setText(K(game, 'missionTitle', 'Mission Details')); if (!m._arenaWired) { m._arenaWired = true; m.control('btn_exit').onClick(() => m.close('ok')); } open(m); }
  async function openInfo() {
    const w = await create('info'); if (!w) return;
    if (!w._arenaWired) { w._arenaWired = true; w.control('btn_exit').onClick(() => w.close('ok'));
      for (let i = 0; i < 4; i++) w.control(`btn_team_${i + 1}`).onClick(() => { st.tab = i; fillBattleInfo(game, w, { battle: battle(), result: st.state?.result, selfId: network.self?.id ?? game.player?.id, tab: i }); }); }
    open(w);
    fillBattleInfo(game, w, { battle: battle(), result: battle() && st.state?.result?.battle !== battle().id ? null : st.state?.result, selfId: network.self?.id ?? game.player?.id, tab: st.tab });
  }
  async function showResult(r) {
    say(r.winner < 0 ? ARENA_TEXT.noWinner : `${teamLabel(game, r.winner)}: ${r.outcome === 'win' ? 'WIN' : 'LOSE'}`);
    await openInfo();
  }
  async function openBoard() {
    const res = await send({ operation: 'board' }); if (!res?.board) return;
    const w = await create('board'); if (!w) return;
    if (!w._arenaWired) { w._arenaWired = true; w.control('btn_exit').onClick(() => w.close('ok')); }
    open(w); fillBoard(game, w, res.board, network.self?.id ?? game.player?.id);
  }
  // ---- entry (npc jobs 130 / 111) and Sunstone (job 52)
  async function enter(job, npcIndex) {
    const res = await send({ operation: 'info' }); if (!res) return;
    if (res.battle) { await openInfo(); return; }
    const v = Object.values(res.venues || {}).find(x => x.job === job); if (!v) return;
    if (res.queued) { const r = await game.uiwin?.msgbox?.(`${v.name}\n${fmt(arenaString(game, 160, 35, '%d/%d'), v.queued, v.startPlayers)}`, { title: arenaString(game, 160, 1, v.name), kind: 'yesno', yes: arenaString(game, 160, 11, 'Cancel Joining'), no: arenaString(game, 160, 46, 'OK') }); if (r === 'yes') { const c = await send({ operation: 'cancel' }); if (c?.notice) say(c.notice); } return; }
    if (v.key === 'draco' && !v.open) { await game.uiwin?.msgbox?.(ARENA_TEXT.closed, { title: v.name, kind: 'ok' }); return; }
    if (!v.levelOk) { report(new Error(ARENA_TEXT.level)); return; }
    const lines = [v.name, `Lv.${v.minLevel} - Lv.${v.maxLevel}`, `${arenaString(game, 160, 5, 'Maximum Participants')}: ${v.maxPlayers}`, `${arenaString(game, 160, 6, 'Current Participants')}: ${v.key === 'draco' ? v.inBattle : v.queued}`,
      `${arenaString(game, 160, 7, 'Playtime')}: ${fmt(arenaString(game, 160, 36, '%d min'), Math.round(v.fightSec / 60))}`, ...(v.key === 'lostHorizon' ? [`${arenaString(game, 160, 8, 'Start (M)')}: ${v.startPlayers}`] : [])];
    const r = game.uiwin?.msgbox ? await game.uiwin.msgbox(lines.join('\n'), { title: v.name, kind: 'yesno', yes: arenaString(game, 160, 18, 'Enter'), no: arenaString(game, 160, 47, 'Cancel') }) : 'yes';
    if (r !== 'yes') return;
    const e = await send({ operation: 'enter', venue: v.key, ...(Number.isInteger(npcIndex) ? { npcIndex } : {}) });
    if (e?.queued != null) say(`${v.name} ${fmt(arenaString(game, 160, 35, '%d/%d'), e.queued, e.start)}`);
  }
  async function commune() { const b = battle(); if (!b || b.venue !== 'draco') return false; const r = await send({ operation: 'commune' }); if (r?.communing) say(ARENA_TEXT.communing); return true; }
  const handlers = {
    [ARENA_JOBS.draco]: n => { if (!online()) return false; game.uiwin?.close?.('npc'); void enter(ARENA_JOBS.draco, Number(n?.npcIndex ?? n?.index ?? n?.def?.index)); return true; },
    [ARENA_JOBS.lostHorizon]: n => { if (!online()) return false; game.uiwin?.close?.('npc'); void enter(ARENA_JOBS.lostHorizon, Number(n?.npcIndex ?? n?.index ?? n?.def?.index)); return true; },
    [SUNSTONE_JOB]: () => { if (!online() || !battle()) return false; game.uiwin?.close?.('npc'); void commune(); return true; },
  };
  let services = null;
  const register = () => { const s = game.npcServices; if (!s?.register) return;
    for (const [job, h] of Object.entries(handlers)) {
      const list = s.handlers instanceof Map ? s.handlers.get(Number(job)) : null;
      if (Array.isArray(list)) { if (list[0] !== h) { const i = list.indexOf(h); if (i >= 0) list.splice(i, 1); list.unshift(h); } }
      else if (services !== s || s.get?.(Number(job)) !== h) s.register(Number(job), h);
    }
    services = s; };
  register(); game.events?.on?.('systems', register);
  const original = network._snapshot?.bind(network);
  if (original) network._snapshot = snapshot => { original(snapshot); if (network.disposed) return;
    register(); if (!st.checked && network.ready && network.token && !network._joining) { st.checked = true; setTimeout(() => void send({ operation: 'info' }), 0); } };
  // the death window's Revive is the host revive: inside a battlefield it lands on the squad Revive_Pos (server/world/arena.mjs arenaRevive)
  game.chat?.registerCommand?.('/arenaboard', () => { void openBoard(); return true; }, 'Show the DP Score rank board.');
  game.chat?.registerCommand?.('/arenainfo', () => { void openInfo(); return true; }, 'Show the battlefield information.');
  game.chat?.registerCommand?.('/arenamission', () => { void openMission(); return true; }, 'Show the Mission Details window.');
  game.chat?.registerCommand?.('/arenaleave', () => { if (battle()) void send({ operation: 'leave' }); return true; }, 'Leave the battlefield (a penalty applies during the fight).');
  game.chat?.registerCommand?.('/commune', () => { void commune(); return true; }, 'Commune with the Sunstone.');
  const leave = network.leave?.bind(network); if (leave) network.leave = options => { st.state = null; leftBattle(); if (st.refresh) { clearInterval(st.refresh); st.refresh = null; } return leave(options); };
  game.arena = { state: st, enter, commune, openInfo, openBoard, openMission, send, hud };
  return game.arena;
}