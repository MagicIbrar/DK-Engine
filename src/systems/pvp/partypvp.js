import { declineBlockedInvitation } from '../hud-options/invitation-policy.js';
// PARTY-PVP client windows (original scripts; strings stringtable_pvp.txt cate 280 / 1008, pcpop 240:8). The host owns
// the match (server/world/party-pvp.mjs); these windows only show network.partyPvp state and send its intents.
//   pcpop                240:8 "Party PvP" on another party's leader (only for a party leader)
//   partypvp_ask         game2/msgbox/ui_partypvpask.txt          the challenged leader: 280:17 (name / text / average level)
//   partypvp_acceptwait  game2/msgbox/ui_partypvpacceptwait.txt   the requesting leader: 280:19 + time bar, Cancel
//   partypvp_battle      game2/partypvp/ui_partypvp_battlewnd.txt both parties: setting (BLUE leader edits, Confirm ->
//                        partypvp_setting 280:63) + 7 v 7 member rows with Start 280:36 / Withdraw 280:37 (-> partypvp_cancel 280:47)
//   partypvp_time        game2/partypvp/ui_limittimewnd.txt       1008:8 + N 1008:10 before the start, 280:44 during, 280:51 after
//   partypvp_result      game2/partypvp/ui_partypvp_resultwnd.txt BLUE/RED members + scores, Total Points, Survived, Prize Money
import { str, needStrings } from '../hud-options/util.js';
import { installPcPop } from './duel.js';
import {installPartyBuffWindow} from './party-buff-window.js';

const S = (c, code) => str(c, code) || '';
const plain = s => String(s || '').replace(/<\/?center>/gi, '').replace(/<\/?color[^>]*>/gi, '').replace(/\\\\/g, ' ').trim();
const sound = (game, k) => { try { game.audio?.ui?.(k); } catch { /* optional */ } };
const CLASS_ICON = { group: 'guildwar_apply', first: 11, count: 15 };   // imagetable guildwar_apply 11..25 (same cells as the guild windows)
const READY_IMAGE = ['Partypvp', 2];                                    // imagetable Partypvp 2: the 18 x 18 ready mark
const ROWS = 7;
const mmss = (fmt, ms) => { const s = Math.max(0, Math.ceil(ms / 1000)); return plain(fmt).replace('%02d', String(Math.floor(s / 60)).padStart(2, '0')).replace('%02d', String(s % 60).padStart(2, '0')); };

function fillRow(win, prefix, i, m, { ready, score } = {}) {
  const cls = win.find(`pan_${prefix}classimg_${i}`), name = win.find(`pan_${prefix}namelist_${i}`);
  cls?.setVisible(!!m); name?.setVisible(!!m);
  if (m) { cls?.setImage('none', CLASS_ICON.group, CLASS_ICON.first + Math.max(0, Math.min(CLASS_ICON.count - 1, m.classIndex | 0))); name?.setText(`${m.name}  Lv ${m.level}`); }
  const r = win.find(`pan_${prefix}readyimg_${i}`); if (r) { r.setVisible(!!m && !!ready); if (m && ready) r.setImage('none', READY_IMAGE[0], READY_IMAGE[1]); }
  if (score) { const l = win.find(score); if (l) { l.setVisible(!!m); l.setText(m ? String(m.score || 0) : ''); } }
}

// The browser font runs wider than the client's bitmap fonts: an original string that overflows its script rect (the
// 164 px Party Match timer, the 235 px 280:77 notice) is scaled down to the rect instead of spilling over its neighbours.
function fitText(c) {
  const span = c?.txt?.firstChild; if (!span) return;
  span.style.transform = ''; span.style.transformOrigin = 'center center';
  const w = c.txt.getBoundingClientRect().width, tw = span.getBoundingClientRect().width;
  if (w > 0 && tw > w) span.style.transform = `scale(${Math.max(0.5, (w - 2) / tw)})`;
}

export function installPartyPvpWindows(game, network) {
  const P = () => network.partyPvp, st = () => P()?.state() || {};
  const now = () => P()?.serverNow() ?? Date.now();
  void needStrings([['NORMAL', 280, 17], ['NORMAL', 1008, 20], ['NORMAL', 240, 8]]).catch(() => {});
  const ui = game.uiwin;
  installPartyBuffWindow(game,network);
  const pop = installPcPop(game);
  const party = () => network.party || game.party?.serverState || null;
  const myId = () => network.self?.id;
  pop.add({ code: 8, visible: t => t?.kind === 'player' && t !== game.player && !!network.active && party()?.active && party()?.leaderId === myId() && !(party()?.members || []).some(mm => mm.id === t.networkId),
    run: t => { if (!st().id) void P()?.request(t); } });

  ui.registerWindow('partypvp_ask', {
    script: 'game2/msgbox/ui_partypvpask.txt', remember: false, escClose: false, band: 'modal',
    create(win) {
      win.control('btn_yes').onClick(() => { void P()?.accept(); win.close(); });
      win.control('btn_no').onClick(() => { void P()?.decline(); win.close(); });
    },
    onOpen(win) {
      const s = st(), parts = String(S(280, 17)).split(/<center>/i).map(plain).filter(Boolean);
      win.control('multilbl_0').setText((parts[0] || '%s').replace('%s', s.enemy?.name || '')).setTextColor('fff4be3d');
      win.control('lbl_quest').setText(parts.slice(1, -1).join(' '));
      win.control('multilbl_1').setText((parts.at(-1) || '%d').replace('%d', String(s.enemy?.avgLevel ?? 0)));
      win.data.id = s.id;
    },
    update(win) { const s = st(); if (!s.incoming || s.id !== win.data.id) win.close(); },
  });
  ui.registerWindow('partypvp_acceptwait', {
    script: 'game2/msgbox/ui_partypvpacceptwait.txt', remember: false, escClose: false, band: 'system',
    create(win) { win.control('btn_no').onClick(() => { void P()?.cancel(); win.close(); }); },
    onOpen(win) { win.data.id = st().id; },
    update(win) {
      const s = st(); if (!s.waiting || s.id !== win.data.id) { win.close(); return; }
      const total = Math.max(1, (s.expiresAt || 0) - (s.createdAt || 0));
      win.control('processbar').setGauge(Math.max(0, Math.min(1, ((s.expiresAt || 0) - now()) / total)));
    },
  });
  const confirm = (name, script, onYes) => ui.registerWindow(name, {
    script, remember: false, escClose: true, band: 'modal',
    create(win) { win.control('btn_yes').onClick(() => { win.close(); onYes(win.data.arg); }); win.control('btn_no').onClick(() => win.close()); win.find('btn_exit')?.onClick(() => win.close()); },
    onOpen(win, arg) { win.data.arg = arg; },
  });
  confirm('partypvp_setting', 'game2/msgbox/ui_partypvpsetting.txt', a => { if (a) void P()?.setting(a.row, a.fee, a.minutes); });
  confirm('partypvp_cancel', 'game2/msgbox/ui_partypvpcancel.txt', () => { void P()?.withdraw(); });

  const rowOf = (s, index) => (s.rows || []).find(r => r.index === Number(index)) || (s.rows || [])[0] || null;
  const battleDef = {
    script: 'game2/partypvp/ui_partypvp_battlewnd.txt', remember: false, escClose: false, band: 'system',
    create(win) {
      // the rune-removal option (280:117) and the panel fold arrows have no original rule here: not shown
      for (const id of ['lbl_removerune', 'combo_removerune', 'btn_up', 'btn_down']) win.find(id)?.setVisible(false);
      // 280:77 carries its own line break: keep the two original lines (this instance only; the cached spec is shared)
      const warn = win.find('lbl_warning'); if (warn) { warn.autoWrap = () => false; warn.paintText(); }
      win.control('btn_ready').setEnabled(true).onClick(() => { void P()?.ready(); });
      win.control('btn_leave').onClick(() => ui.open('partypvp_cancel'));
      win.control('btn_confirm').onClick(() => {
        const fee = Number(String(win.control('edit_fee').getText()).replace(/[^0-9]/g, '')) || 0;
        ui.open('partypvp_setting', { row: win.control('combo_place').getValue(), fee, minutes: win.control('combo_wartime').getValue() });
      });
      win.control('combo_place').onChange(() => { const r = rowOf(st(), win.control('combo_place').getValue()); if (r) win.control('pan_placeimg').setImage('none', 'PartypvpImg', r.imgIndex); });
      win.control('combo_system').onChange(()=>{
        const mode=Number(win.control('combo_system').getValue()),rows=(st().rows||[]).filter(r=>r.mode===mode);
        win.control('combo_place').setItems(rows.map(r=>({text:r.mapName||String(r.map),value:r.index}))).select(0);
        const r=rows[0];if(r)win.control('pan_placeimg').setImage('none','PartypvpImg',r.imgIndex);
      });
      win.data.sig = '';
    },
    onOpen(win) { win.data.sig = ''; win.data.id = st().id; battleDef.refresh(win); requestAnimationFrame(() => fitText(win.find('lbl_warning'))); },
    refresh(win) {
      const s = st(); if (!s.id) return;
      win.control('lbl_avrlevel').setText(String(s.enemy?.avgLevel ?? ''));
      const sig = JSON.stringify([s.settings, s.canSet, (s.rows || []).length]);
      if (sig !== win.data.sig) {
        win.data.sig = sig;
        const rows = s.rows || [], modes = [...new Map(rows.map(r => [r.mode, r.modeName])).entries()];
        const chosen=rowOf(s,s.settings?.row);
        win.control('combo_system').setItems(modes.map(([value, text]) => ({ text, value }))).selectValue(chosen?.mode);
        win.control('combo_place').setItems(rows.filter(r=>r.mode===chosen?.mode).map(r => ({ text: r.mapName || String(r.map), value: r.index }))).selectValue(s.settings?.row);
        win.control('combo_wartime').setItems((s.minutes || [15, 30, 60]).map((v, i) => ({ text: plain(S(280, 60 + i)) || `${v}`, value: v }))).selectValue(s.settings?.minutes);
        win.control('edit_fee').setText(String(s.settings?.fee ?? ''));
        const r = rowOf(s, s.settings?.row); if (r) win.control('pan_placeimg').setImage('none', 'PartypvpImg', r.imgIndex);
        for (const id of ['combo_system', 'combo_place', 'edit_fee', 'combo_wartime']) win.control(id).setEnabled(!!s.canSet);
        win.control('btn_confirm').setVisible(!!s.canSet);
      }
      for (let i = 0; i < ROWS; i++) {
        const a = s.own?.members?.[i], b = s.enemy?.members?.[i];
        fillRow(win, '', i, a, { ready: a?.ready }); fillRow(win, 'Enemy', i, b, { ready: b?.ready });
      }
      win.control('btn_ready').setText(plain(s.ready ? S(280, 43) : S(280, 36)));
    },
    update(win) { const s = st(); if (s.phase !== 'setup' || s.id !== win.data.id) win.close(); },
  };
  ui.registerWindow('partypvp_battle', battleDef);
  ui.registerWindow('partypvp_time', {
    script: 'game2/partypvp/ui_limittimewnd.txt', remember: false, escClose: false, band: 'hud',
    update(win) {
      const s = st(), t = now();
      let text = '';
      if (s.phase === 'wait') text = `${plain(S(1008, 8))} ${Math.max(0, Math.ceil(((s.startAt || 0) - t) / 1000))} ${plain(S(1008, 10))}`;
      else if (s.phase === 'fight') text = mmss(S(280, 44), (s.endsAt || 0) - t);
      else if (s.phase === 'over') text = mmss(S(280, 51), (s.finishAt || 0) - t);
      else { win.close(); return; }
      if (text !== win.data.text) { win.data.text = text; win.control('lbl_text').setText(text); fitText(win.control('lbl_text')); }
    },
  });
  ui.registerWindow('partypvp_result', {
    script: 'game2/partypvp/ui_partypvp_resultwnd.txt', remember: false, escClose: true, band: 'system',
    create(win) { win.find('edit_money')?.setVisible(false); win.find('pan_observer_display')?.setVisible(false); },
    onOpen(win) {
      const r = st().result; if (!r) return; win.data.at = r.at;
      const [blue, red] = r.teams;
      for (let i = 0; i < ROWS; i++) { fillRow(win, '', i, blue.members[i], { score: `lbl_score_${i}` }); fillRow(win, 'Enemy', i, red.members[i], { score: `lbl_Enemyscroe_${i}` }); }
      win.control('lbl_bluepoint').setText(String(blue.points)); win.control('lbl_redpoint').setText(String(red.points));
      win.control('lbl_blueuser').setText(String(blue.survived)); win.control('lbl_reduser').setText(String(red.survived));
      win.control('pan_bg_winner').setVisible(r.prize > 0);
      win.control('lbl_money').setText(Number(r.prize || 0).toLocaleString('en-US'));
    },
    update(win) { const s = st(), r = s.result; if (!r || r.at !== win.data.at || (!s.id && now() - r.at > 60000)) win.close(); },
  });

  let last = {};
  game.events?.on?.('partypvp', ({ state }) => {
    const s = state || {}, open = n => { const w = ui.window?.(n); if (!w?.isOpen) ui.open(n); };
    const blocked = s.phase === 'invited' && s.incoming && declineBlockedInvitation(game,'blockPartyPvp',s.id,()=>P()?.decline());
    if (blocked) ui.close?.('partypvp_ask');
    else if (s.phase === 'invited' && s.incoming) open('partypvp_ask');
    if (s.phase === 'invited' && s.waiting) open('partypvp_acceptwait');
    if (s.phase === 'setup') { const w = ui.window?.('partypvp_battle'); if (!w?.isOpen) ui.open('partypvp_battle'); else battleDef.refresh(w); }
    if(s.phase==='setup'&&s.buffs?.length&&(!last.buffs?.length||last.id!==s.id))open('partypvp_buffs');
    if (['wait', 'fight', 'over'].includes(s.phase)) open('partypvp_time');
    if (s.phase === 'wait' && last.phase !== 'wait') sound(game, 'pvpAccept');
    if (s.phase === 'fight' && last.phase !== 'fight'&&!s.observer) { sound(game, 'pvpStart'); game.chat?.system?.(`${plain(S(1008, 18)) || 'VS'} ${s.enemy?.name || ''}`, 'sys'); }
    if (s.result && s.result.at !== last.result?.at) {
      open('partypvp_result');
      const mine = s.result.winner === s.result.side;
      sound(game, s.result.winner === 'draw' ? 'pvpDefeat' : mine ? 'pvpVictory' : 'pvpDefeat');
      game.chat?.system?.(plain(s.result.winner === 'blue' ? S(280, 78) : s.result.winner === 'red' ? S(280, 79) : S(280, 80)), 'sys');
    }
    if (s.notice && s.notice.at !== last.notice?.at) {
      const n = s.notice, text = n.reason === 'declined' ? (n.requester ? S(1008, 7) : '') : S(1008, 20);
      if (text) game.chat?.system?.(plain(text), 'sys');
    }
    last = s;
  });
}
