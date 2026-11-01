// COLOSSEUM client (shared play). The host owns queues, matches and rewards (server/world/colosseum.mjs); this module
// reads snapshot.colosseum, sends the colosseum intents and draws the original game2/colosseum windows:
//   minimap btn_colosseummatching (ENGINE-CHOSEN entry, shown while a mode's playtime is open) -> mode choice
//     (360|8 Battle Royale / 360|9 Individual Match) -> ui_matchingwait (360|6 + 360|35 players waiting, Cancel 360|120)
//   ui_matchingentry: 360|7 "%s is available ... (You will join in %d sec.)", Entry = accept, Esc = decline (360|119)
//   Battle Royale: battleroyal/ui_timerwnd (phase timer), ui_deathrollwnd (kills / death roll lines, 163:700 for the
//     sentenced player), battleroyal/ui_miniresultwnd (live board: state / class / name / level / server / kills,
//     Exit 360|81 for an eliminated entrant), result: battleroyal/ui_resultwnd (classic) or ui_resultwnd_renew.
//   Individual Match: pvpmode/ui_dashboard (timer, team sign), pvpmode/ui_resultwnd (both teams, Kills / P Points /
//     Token), map 164 effects 100 / 200 / 300 / 400 / 500.
// Map message effects (effectui) come from gamedata/dungeons.json through src/systems/dungeons/data.js.
import { loadEventData } from '../events/data.js';
import { cloneTemplate } from '../../ui/frontend/ui.js';
import { CLASS_CODES } from '../events/guild-tournament-rules.js';
import { loadData as loadDungeonData, messageFx, messageText } from '../dungeons/data.js';
import { UIEffects } from '../dungeons/uifx.js';
import { itemName } from '../life/common.js';
import { COLOSSEUM_ENGINE_CHOSEN as C } from '../../config/engine-chosen-colosseum.js';
import { installCarnivalWindows } from './monster-carnival.js';

const DIR = 'game2/colosseum/';
const plain = s => String(s ?? '').replace(/<\/?center>/gi, '').replace(/<\/?color[^>]*>/gi, '').replace(/@<effectui>\S*/g, '').replace(/^\s*\[message\]\s*/i, '').replace(/\\n/g, '\n').trim();
const sub = (c, id) => { if (!c) return null; for (const x of c.children || []) { if ((x.spec?.id ?? x.id) === id) return x; const d = sub(x, id); if (d) return d; } return null; };
const CLASS_ICON = { group: 'guildwar_apply', first: 11, count: 15 };
/** n visible clones of a template control stacked by step px; extra clones hidden. */
function rows(win, tpl, n, step, key = tpl, dx = 0) {
  win._colRows ||= {}; const list = win._colRows[key] ||= []; const src = win.find?.(tpl); if (!src) return [];
  src.setVisible?.(false);
  const base = Array.from(src.spec?.rect || [0, 0, 0, 0]).map(Number);
  for (let i = 0; i < Math.max(n, list.length); i++) { if (i < n && !list[i]) list[i] = cloneTemplate(win, tpl, `${key}_${i}c`, [base[0] + dx, base[1] + i * step, base[2], base[3]]); list[i]?.setVisible?.(i < n); }
  return list.slice(0, n);
}
const text = (c, v) => c?.setText?.(v == null ? '' : String(v));
const classIcon = (c, i) => { if (!c) return; c.setImage?.('none', CLASS_ICON.group, CLASS_ICON.first + Math.max(0, Math.min(CLASS_ICON.count - 1, Number(i) | 0))); };

export function installSharedColosseum(game, network) {
  const S = { data: null, fx: null, seen: new Map(), lastMatch: null, lastResult: null, lastNotice: null, lastOpen: null, lines: [], wins: {} };
  void loadEventData().then(d => { S.data = d; }).catch(() => {});
  void loadDungeonData().catch(() => {});
  const T = (code, fb = '') => plain(S.data?.txt?.('stringtable_colosseum.txt', 360, code)) || fb;
  const say = (t, kind = 'sys') => { if (!t) return; if (game.chat?.system) game.chat.system(t, kind); else game.hud?.log?.(t, kind); };
  const report = e => say(e?.message || String(e), 'err');
  const st = () => network.colosseumState || {};
  const serverNow = () => (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : Date.now());
  const send = (operation, fields = {}) => network.action('colosseum', { operation, ...fields }).then(r => r?.colosseumResult ?? r).catch(e => { report(e); return null; });
  const modeName = m => T(m === 'individual' ? 9 : 8, m === 'individual' ? 'Individual Match' : 'Battle Royale');
  // the colosseum string table (360) names only the first 9 classes; the other classes use the engine's own class name
  const className = i => T(CLASS_CODES[Number(i) || 0], '') || game.data?.classByIndex?.get?.(Number(i) || 0)?.name || '';
  network.colosseum = {
    state: st, register: mode => send('register', { mode }), cancel: () => send('cancel'), accept: () => send('accept'), decline: () => send('decline'), exit: () => send('exit'),
    ranking: (category, period) => send('ranking', { category, period }),
    isEnemy: a => !!a && a.kind === 'player' && a !== game.player && [...(st().match?.enemies || []), ...(st().carnival?.run?.enemies || [])].includes(a.networkId),
  };
  // MONSTER CARNIVAL (the Forgotten Shipwreck team mode) rides the colosseum snapshot and intents (src/systems/network/monster-carnival.js).
  const carnivalFx = code => { try { S.fx ||= new UIEffects(game); for (const u of S.data?.str?.('stringtable_dksquare.txt', 161, code)?.effectUi || []) void S.fx.play(u.id, u.ms); } catch { /* effects are optional */ } };
  const carnival = installCarnivalWindows(game, { state: () => st().carnival || null, send: (operation, fields = {}) => send(operation, fields), str: code => S.data?.txt?.('stringtable_dksquare.txt', 161, code) || '',
    say, effect: carnivalFx, itemName: index => itemName(game, index) });
  game.chat?.registerCommand?.('/carnival', () => { void carnival.open(); return true; }, 'Open the Forgotten Shipwreck (Monster Carnival) lobby.');
  const ui = game.uiwin;
  const win = async (key, script) => {
    const w0 = S.wins[key]; if (w0 && !w0.disposed) return w0;
    const w = await ui?.create?.(DIR + script, { name: `col_${key}`, escClose: key !== 'timer' && key !== 'dash' && key !== 'deathroll' });
    if (!w) return null; S.wins[key] = w; wire[key]?.(w); return w;
  };
  const show = async (key, script, fill) => { const w = await win(key, script); if (!w) return null; fill?.(w); if (!w.isOpen) ui.openWindow(w); return w; };
  const close = key => { const w = S.wins[key]; if (w?.isOpen) w.close?.('col'); };
  const wire = {
    wait: w => { w.find('btn_cancel')?.onClick(() => { void send('cancel'); close('wait'); }); w.find('btn_exit')?.onClick(() => close('wait')); },
    entry: w => { w.find('btn_entry')?.onClick(() => { void send('accept'); close('entry'); }); w.on?.('close', r => { if (r !== 'col' && st().match?.phase === 'prompt' && st().match?.answer !== 'accept') void send('decline'); }); },
    mini: w => {
      w.find('btn_close')?.onClick(() => close('mini'));
      w.find('btn_exit')?.onClick(() => { void send('exit'); });
      w.find('btn_maxilize')?.onClick(() => { const p = w.find('pan_main'); p?.setVisible?.(!p.visible); });
    },
    result: w => { w.find('btn_close')?.onClick(() => close('result')); w.find('btn_exit')?.onClick(() => { void send('exit'); close('result'); }); },
    renew: w => { w.find('btn_close')?.onClick(() => close('renew')); w.find('btn_exit')?.onClick(() => { void send('exit'); close('renew'); }); },
    pvp: w => { w.find('btn_exit')?.onClick(() => { void send('exit'); close('pvp'); }); },
  };
  const fx = code => {
    const map = st().match?.map ?? game.world?.info?.index;
    try { S.fx ||= new UIEffects(game); for (const u of messageFx(map, code).ui) void S.fx.play(u.ui, u.ms); } catch { /* effects are optional */ }
    const t = plain(messageText(map, code)); if (t) say(t);
  };
  // ---------------------------------------------------------------------------------------- entry (minimap)
  async function choose() {
    const s = st();
    if (s.queue) { void openWait(); return; }
    if (s.match) return;
    const open = Object.entries(s.open || {}).filter(([, v]) => v).map(([k]) => k);
    if (!open.length) { say(T(166)); return; }
    const br = open.includes('renew') && open.includes('classic') ? (game.inventory?.count?.(4002357) > 0 ? 'renew' : 'classic') : open.find(k => k !== 'individual');
    let mode = br || 'individual';
    if (br && open.includes('individual')) {
      const r = await ui.msgbox(`${modeName(br)} / ${modeName('individual')}`, { kind: 'yesno', yes: modeName(br), no: modeName('individual'), name: 'col_choose' });
      if (r === 'cancel') return; mode = r === 'yes' ? br : 'individual';
    }
    const r = await send('register', { mode });
    if (r?.registered) { say(T(101)); void openWait(); }
  }
  async function openWait() {
    const s = st(); if (!s.queue) return;
    await show('wait', 'ui_matchingwait.txt', w => fillWait(w));
  }
  const fillWait = w => { const s = st(); text(w.find('lbl_text'), `${T(6, 'Waiting to join the %s mode...').replace('%s', modeName(s.queue))}\n${T(35, '%d players are waiting.').replace('%d', String(s.waiting || 0))}`); };
  const minimapButton = () => {
    const m = ui?.window?.('hud_minimap'), b = m?.find?.('btn_colosseummatching'); if (!b) return;
    const s = st(), on = !!network.active && !s.match && (Object.values(s.open || {}).some(Boolean) || !!s.queue);
    if (b.visible !== on) b.setVisible(on);
    if (!b._colWired) { b._colWired = true; b.onClick?.(() => { void choose(); }); }
  };
  // ---------------------------------------------------------------------------------------- in a match
  const remain = at => Math.max(0, Math.floor(((at || 0) - serverNow()) / 1000));
  function fillMini(w) {
    const m = st().match; if (!m) return;
    const list = [...m.players].sort((a, b) => (a.out ? 1 : 0) - (b.out ? 1 : 0) || b.kills - a.kills);
    rows(w, 'pan_body', list.length, 24).forEach((c, i) => {
      const e = list[i];
      sub(c, 'btn_state')?.setEnabled?.(!e.out); sub(c, 'btn_state')?.setChecked?.(!!e.out);
      classIcon(sub(c, 'pan_class'), e.classIndex); text(sub(c, 'lbl_name'), e.name); text(sub(c, 'lbl_level'), e.level); text(sub(c, 'lbl_server'), e.server); text(sub(c, 'lbl_kill'), e.kills);
    });
    w.find('btn_exit')?.setVisible(!!m.out);
  }
  function deathLine(ev) {
    if (ev.kind === 'killed' && ev.by) return `${ev.by} ${T(14, 'Killed')} ${ev.name}`;
    if (ev.kind === 'killed' || ev.kind === 'sentenced' || ev.kind === 'left') return `${ev.name} ${T(13, 'Died')}`;
    return '';
  }
  async function onEvents(m) {
    // mark the events as seen BEFORE the first await: two snapshots can arrive while a window is still loading, and each would
    // otherwise replay the same events (double death-roll lines / map messages)
    const seen = S.seen.get(m.id) || 0, fresh = (m.events || []).filter(ev => ev.seq > seen);
    if (!fresh.length) return;
    S.seen.set(m.id, Math.max(seen, ...fresh.map(ev => ev.seq)));
    for (const ev of fresh) {
      if (ev.code && !(ev.code === 700 && ev.playerId !== network.self?.id)) fx(ev.code);
      if (ev.kind === 'round' && m.mode === 'renew') say(plain(messageText(m.map, 301 + m.round)));
      // Blessing of the Dead taken from a Crystal of the Dead (360|15 "Buffs"): the status icons arrive with the buffs themselves.
      if (ev.kind === 'blessing') say(`${ev.name} ${T(15, 'Buffs')} +${(ev.statuses || []).length}`);
      const line = deathLine(ev);
      if (line && m.mode !== 'individual') { S.lines.push(line); S.lines = S.lines.slice(-6); const dw = await show('deathroll', 'ui_deathrollwnd.txt'); text(dw?.find('lbl_message'), S.lines.join('\n')); }
      else if (line) say(line);
    }
  }
  function tickHud() {
    const m = st().match;
    if (!m || !['wait', 'round', 'ready', 'fight'].includes(m.phase)) { close('timer'); close('dash'); return; }
    if (m.mode === 'individual') {
      void show('dash', 'pvpmode/ui_dashboard.txt', w => {
        w.find('number_timer')?.setTime?.(remain(m.phaseEndsAt));
        w.find('pan_redsign')?.setVisible(m.team === 0); w.find('pan_bluesign')?.setVisible(m.team === 1); w.find('pan_member')?.setVisible(false);
      });
    } else void show('timer', 'battleroyal/ui_timerwnd.txt', w => { w.find('number_timer')?.setTime?.(remain(m.phaseEndsAt)); w.find('btn_penalty')?.setVisible(false); });
  }
  // ---------------------------------------------------------------------------------------- results
  function fillResult(r) {
    const mine = r.rows.find(x => x.id === r.me) || {};
    if (r.mode === 'individual') {
      void show('pvp', 'pvpmode/ui_resultwnd.txt', w => {
        // The script ships one board (pan_board, 7 rows, left half = Red Team) hidden, so it is shown here. The Blue Team half of the
        // window reuses the same header and row layout 428 px to the right (ENGINE-CHOSEN reading: the script has one board).
        w.find('pan_board')?.setVisible(true);
        if (!w._colHdr) {
          w._colHdr = true;
          for (const id of ['btn_name', 'btn_server', 'btn_level', 'btn_kills', 'btn_ppoint', 'btn_pcoin']) { const h = w.find(id), rc = h && Array.from(h.spec?.rect || []).map(Number); if (rc?.length === 4) cloneTemplate(w, id, `${id}_b`, [rc[0] + 428, rc[1], rc[2], rc[3]]); }
        }
        const fillSide = (list, key, dx) => rows(w, 'pan_line', list.length, 26, key, dx).forEach((c, i) => { const x = list[i]; classIcon(sub(c, 'pan_job'), x.classIndex); text(sub(c, 'lbl_name'), `${x.name}${r.mvp === x.id ? ' (MVP)' : ''}`); text(sub(c, 'lbl_server'), x.server); text(sub(c, 'lbl_level'), x.level); text(sub(c, 'lbl_kills'), x.kills); text(sub(c, 'lbl_ppoint'), x.reward?.party ?? 0); text(sub(c, 'lbl_pcoin'), x.reward?.coin ?? 0); });
        fillSide(r.rows.filter(x => x.team === 0), 'pan_lineA', 0); fillSide(r.rows.filter(x => x.team !== 0), 'pan_lineB', 428);
      });
      return;
    }
    if (r.mode === 'renew') {
      void show('renew', 'battleroyal/ui_resultwnd_renew.txt', w => {
        text(w.find('lbl_winner_name'), r.winner);
        w.find('freeboard1')?.setRows?.(r.rows.map(x => [x.place, className(x.classIndex), x.name, x.level, x.server, x.kills, x.reward?.br ?? 0]));
        const it = mine.reward?.item; text(w.find('lbl_reward1_item_name'), it ? `${itemName(game, it)} x${mine.reward.count}` : '');
        w.find('item_reward2')?.setVisible(false); w.find('lbl_reward2_item_name')?.setVisible(false);
      });
      return;
    }
    void show('result', 'battleroyal/ui_resultwnd.txt', w => {
      const champ = r.rows.find(x => x.place === 1);
      text(w.find('lbl_winner_name'), r.winner); text(w.find('lbl_winner_coin'), champ?.reward?.coin ?? 0);
      text(w.find('lbl_totalkill'), `${T(1, 'Kills')} ${mine.kills ?? 0}`);
      // The table under the tags (Enter / Class / Name / Level / Server / Killed): the script has the tags and the 16-row panel (pan_base,
      // 24 px rows) but no row controls, so every cell is a copy of its tag label (ENGINE-CHOSEN: Enter = the entry order in the queue).
      const cols = [['lbl_tagenter', x => x.enter], ['lbl_tagclass', x => className(x.classIndex)], ['lbl_tagname', x => x.name], ['lbl_taglevel', x => x.level], ['lbl_tagserver', x => x.server], ['lbl_tagkill', x => x.kills]];
      w._colCells ||= {};
      [...r.rows].sort((a, b) => (a.enter || 0) - (b.enter || 0)).forEach((x, i) => cols.forEach(([id, get]) => {
        const key = `${id}_row${i}`;
        if (!w._colCells[key]) { const h = w.find(id), rc = h && Array.from(h.spec?.rect || []).map(Number); if (rc?.length === 4) w._colCells[key] = cloneTemplate(w, id, key, [rc[0], 189 + i * 24, rc[2], 24]); }
        text(w._colCells[key], get(x));
      }));
      text(w.find('text_result'), r.rows.map(x => `${x.place}. ${x.name} Lv ${x.level} ${className(x.classIndex)} - ${T(1, 'Kills')} ${x.kills}${x.buffs ? ` / ${T(15, 'Buffs')} ${x.buffs}` : ''}`).join('\n'));
      w.find('number_coin')?.setNumber?.(mine.reward?.coin ?? 0); w.find('number_point')?.setNumber?.(mine.reward?.br ?? 0);
    });
  }
  // ---------------------------------------------------------------------------------------- snapshot
  async function sync(s) {
    minimapButton();
    carnival.update(s.carnival || null);
    if (s.notice && s.notice.at !== S.lastNotice) { S.lastNotice = s.notice.at; say(plain(s.notice.text)); }
    const brOpen = !!(s.open?.classic || s.open?.renew);
    if (S.lastOpen === false && brOpen) say(T(149));
    S.lastOpen = brOpen;
    if (s.queue) { const w = S.wins.wait; if (w?.isOpen) fillWait(w); else if (!S.waitShown) { S.waitShown = true; void openWait(); } }
    else { S.waitShown = false; close('wait'); }
    const m = s.match;
    if (m?.phase === 'prompt' && m.answer !== 'accept') {
      await show('entry', 'ui_matchingentry.txt', w => { text(w.find('lbl_text'), T(7, '%s is available. Do you want to join? (You will join in %d sec.)').replace('%s', modeName(m.mode)).replace('%d', String(remain(m.promptEndsAt)))); });
    } else close('entry');
    if (m && m.phase !== 'prompt') {
      await onEvents(m);
      if (m.mode !== 'individual') { const w = S.wins.mini; if (w?.isOpen) fillMini(w); else if (S.lastMatch !== m.id) void show('mini', 'battleroyal/ui_miniresultwnd.txt', fillMini); }
      S.lastMatch = m.id;
    } else { close('mini'); close('deathroll'); if (!m) { S.lines = []; } }
    tickHud();
    if (s.result && s.result.at !== S.lastResult) { S.lastResult = s.result.at; fillResult(s.result); }
    if (!m) { close('timer'); close('dash'); }
  }
  // the result windows' Exit button reads "Exit (%d sec.)": count down to the server's finishAt (the end of the result time)
  const exitCountdown = m => {
    if (m?.phase !== 'over' || !m.finishAt) return;
    for (const key of ['pvp', 'result', 'renew']) {
      const b = S.wins[key]?.isOpen ? S.wins[key].find('btn_exit') : null; if (!b) continue;
      const tpl = b._exitTpl ||= String(b.getText?.() || '');
      if (tpl.includes('%d')) b.setText(tpl.replace('%d', String(remain(m.finishAt))));
    }
  };
  const timer = setInterval(() => { if (network.disposed || !network.active) return; const s = st(); minimapButton(); exitCountdown(s.match); carnival.update(s.carnival || null); if (s.match) tickHud(); const m = s.match; if (m?.phase === 'prompt' && S.wins.entry?.isOpen) text(S.wins.entry.find('lbl_text'), T(7, '%s is available. Do you want to join? (You will join in %d sec.)').replace('%s', modeName(m.mode)).replace('%d', String(remain(m.promptEndsAt)))); }, 500);
  const snapshot = network._snapshot.bind(network);
  network._snapshot = record => {
    snapshot(record);
    if (network.disposed || !record || !('colosseum' in record)) return;
    network.colosseumState = record.colosseum || {};
    void sync(network.colosseumState).catch(() => {});
  };
  const dispose = network.dispose.bind(network);
  network.dispose = () => { clearInterval(timer); for (const k of Object.keys(S.wins)) close(k); carnival.dispose(); network.colosseum = null; network.colosseumState = null; dispose(); };
  void C;
  return network.colosseum;
}