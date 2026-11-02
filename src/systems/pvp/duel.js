import { declineBlockedInvitation } from '../hud-options/invitation-policy.js';
// PVP-DUEL client windows (original scripts, strings stringtable_pvp.txt cate 280 / 1008, pcpop 240). The host owns the
// duel (server/world/pvp.mjs); these windows only show network.pvp state and send its intents.
//   pcpop           game2/ui_pcpopwnd.txt                   player menu from the target plate (btn_showpcpop); 240:5 Duel
//   pvp_ask         game2/msgbox/ui_pvpask.txt              the challenged player: 280:14 (name / text / Victory Points), Accept / Decline
//   pvp_acceptwait  game2/pvpbattlewnd/ui_pvprequestwaitwnd.txt the challenger: 280:5 + time bar, Cancel
//   pvp_countui     game2/pvpbattlewnd/ui_pvpcountwnd.txt   1008:8 "Your match will begin shortly." + N 1008:10 "sec"
//   pvpbattlewnd    game2/pvpbattlewnd/ui_pvpbattlewnd.txt  280:8 Winner / 280:16 Loser / 280:80 DRAW, points 280:9 / 1008:14, 280:10
//   pvp_restore     game2/pvpbattlewnd/ui_restorewnd.txt    280:3 PvP Respawn wait bar, then 280:4 Reincarnate (resurrect at the spot)
import { str, needStrings } from '../hud-options/util.js';
import { ENGINE_CHOSEN } from '../../game/pvp-rules.js';
import { measureText } from '../../ui/uiwin/fonts.js';
import { nonPkChannel, onOxMap } from './pk-channel.js';

const S = (c, code) => str(c, code) || '';
const plain = s => String(s || '').replace(/<\/?center>/gi, '').replace(/<color=0x[0-9a-f]{2}([0-9a-f]{6})>/gi, '').trim();
const sound = (game, k) => { try { game.audio?.ui?.(k); } catch { /* optional */ } };

/** pcpop entries other systems can add to: {code (240:n, also the row order), visible(target), run(target)}.
 *  Global's PcPopWnd builds only rows 240:0..13 (lane 62, PLAYER-CARD-PARITY.md); cate + label stay for callers
 *  that pass a row label (chartrade row 11 = Global RequestCharTrade, label 240:11). */
export function installPcPop(game) {
  if (game.pcpop) return game.pcpop;
  const entries = [];
  const usable=t=>!!t&&!t.disposed&&t!==game.player&&game.network?.active!==false&&game.network?.ready!==false&&!game.network?.disposed&&(!game.network?.players?.get||game.network.players.get(t.networkId)===t);
  let pendingTarget = null, revision = 0;
  const api = game.pcpop = {
    add(entry) { entries.push(entry); entries.sort((a, b) => a.code - b.code); return api; },
    close() { pendingTarget=null;revision++;game.uiwin.close?.('pcpop');api.syncButton();return true; },
    toggle(target) { const win=game.uiwin.window?.('pcpop');if(pendingTarget===target||win?.isOpen&&win.data.target===target)return api.close();return api.open(target); },
    open(target) {
      const list = entries.filter(e => e.visible?.(target) !== false);if(!usable(target)||!list.length)return false;
      pendingTarget=target;const request=++revision;api.syncButton();
      // Window construction is asynchronous on first use. A second arrow click
      // cancels that pending open rather than letting it reopen after collapse.
      if(game.uiwin.get&&game.uiwin.openWindow){
        void game.uiwin.get('pcpop').then(win=>{if(request!==revision)return;if(!usable(target)||game.player?.target!==target){api.close();return;}const latest=entries.filter(e=>e.visible?.(target)!==false);if(!latest.length){api.close();return;}game.uiwin.openWindow(win,{target,list:latest});}).catch(error=>{if(request===revision){api.close();game.chat?.system?.(error?.message||String(error),'err');}});
      }else game.uiwin.open('pcpop',{target,list});
      return true;
    },
    /** The target plate's menu button (ui_targetpop.txt btn_showpcpop, `visible false` in the script inside
     *  pan_showpcpop): shown while the selected player has a menu row. Called every frame by the systems using it. */
    syncButton() {
      const w = game.uiwin.window?.('hud_target');
      if (!w?.isOpen) return false;
      const btn = w.find?.('btn_showpcpop');
      if (!btn) return false;
      const t = game.player?.target;
      const want = usable(t) && t.kind === 'player' && entries.some(e => e.visible?.(t) !== false);
      const menu=game.uiwin.window?.('pcpop'),expanded=want&&(pendingTarget===t||menu?.isOpen&&menu.data.target===t),show=want&&!expanded;
      if (btn.visible !== show) btn.setVisible(show);
      const close=w.find?.('btn_closepcpop'),panel=w.find?.('pan_showpcpop');
      if(close&&close.visible!==!!expanded)close.setVisible(!!expanded);
      if(panel&&panel.visible!==want)panel.setVisible(want);
      return want;
    },
  };
  game.uiwin.registerWindow('pcpop', {
    script: 'game2/ui_pcpopwnd.txt', remember: false, escClose: true, band: 'system',
    create(win) { win.control('btn_popup').setVisible(false); win.control('pan_sentrypop').setVisible(false); win.control('pan_pcpop_gm').setVisible(false); win.data.rows = []; },
    onOpen(win, arg) {
      const d = win.data; for (const c of d.rows) c.remove?.(); d.rows = []; d.target = arg?.target || null;
      // JUDGMENT (lane 51 g; layout fit only, no value): retain the native pcpop normal/hover row art,
      // but fit real labels instead of letting them escape its authored 70px row.
      const list = arg?.list || [], font = win.control('btn_popup').spec?.titles?.[0]?.font ?? 4;
      const label = e => S(e.cate ?? 240, e.label ?? e.code);
      const textWidth = text => { try { return measureText(text, font); } catch { return text.length * 6; } };
      const width = Math.max(70, ...list.map(e => Math.ceil(textWidth(label(e))) + 16)), height = Math.max(21, list.length * 21);
      win.control('pan_pcpop').setRect?.(0, 0, width, height);
      if (win.spec) { win.spec.rect = [0, 0, width, height]; win.place?.(); }
      list.forEach((e, i) => {
        const c = win.clone('btn_popup', `_${i}`, { x: 0, y: i * 21 });
        c.setRect?.(0, i * 21, width, 21);
        const target=d.target;
        c.setVisible(true); c.setEnabled(true); c.setText(label(e)); c.onClick(() => { if(!usable(target)||game.player?.target!==target||win.data.target!==target||e.visible?.(target)===false)return;win.close();e.run(target); }); d.rows.push(c);
      });
      const t = game.uiwin.window?.('hud_target');
      // The native window includes blank/status space beyond its visible card.
      // Anchor to the card itself, in the UI layer's coordinates (embedded
      // native windows can have a nonzero viewport origin and interface scale).
      const card = t?.find?.('pan_bg')?.el?.getBoundingClientRect?.();
      const box = card && card.right > card.left && card.bottom > card.top ? card : t?.el?.getBoundingClientRect?.();
      if (box) {
        const scale = Number(game.uiwin.scale) > 0 ? Number(game.uiwin.scale) : 1;
        const point = (x, y) => game.uiwin.toLayer?.(x, y) || { x: x / scale, y: y / scale };
        const topLeft = point(box.left, box.top), topRight = point(box.right, box.top);
        const screen = game.uiwin.screen || win.mgr?.screen;
        const right = topRight.x + 4, left = topLeft.x - width - 4;
        const x = screen && right + width > screen.w && left >= 0 ? left : right;
        const fitX = screen ? Math.max(0, Math.min(Math.round(x), Math.floor(screen.w - width))) : Math.round(x);
        const fitY = screen ? Math.max(0, Math.min(Math.round(topLeft.y), Math.floor(screen.h - height))) : Math.round(topLeft.y);
        win.setPosition(fitX, fitY, false);
      }
    },
    onClose(win) { if(pendingTarget===win.data.target){pendingTarget=null;revision++;}api.syncButton(); },
    update(win) { const t = win.data.target; if (!usable(t) || game.player?.target !== t||!entries.some(e=>e.visible?.(t)!==false)) api.close(); },
  });
  return api;
}

export function installDuelWindows(game, network) {
  const P = () => network.pvp, st = () => P()?.state() || {};
  const now = () => P()?.serverNow() ?? Date.now();
  void needStrings([['NORMAL', 280, 14], ['NORMAL', 1008, 1], ['NORMAL', 240, 5], ['NORMAL', 240, 31], ['SYSTEM', 101, 167]]).catch(() => {});
  const ui = game.uiwin;
  const pop = installPcPop(game);
  const valid=t=>t?.kind==='player'&&t!==game.player&&!t.disposed&&!!network.active&&network.ready!==false&&!network.disposed&&(!network.players?.get||network.players.get(t.networkId)===t);
  // 240:5 Duel (Global PcPopWnd click): OX Quiz map -> SYSTEM 101:167, non-PK channel -> 240:31 (pk-channel.js), else request.
  const refuse = text => { const s = plain(text); if (s) game.chat?.system?.(s, 'err'); return false; };
  pop.add({ code: 5, visible: valid, run: async t => {
    if (onOxMap(network)) return refuse(str(101, 167, 'SYSTEM'));
    if (await nonPkChannel(network) === true) return refuse(S(240, 31));
    if (valid(t)&&!st().id) void P()?.request(t);
  } });

  ui.registerWindow('pvp_ask', {
    script: 'game2/msgbox/ui_pvpask.txt', remember: false, escClose: false, band: 'modal',
    create(win) {
      win.control('btn_yes').onClick(() => { void P()?.accept(); win.close(); });
      win.control('btn_no').onClick(() => { void P()?.decline(); win.close(); });
    },
    onOpen(win) {
      const s = st(), parts = String(S(280, 14)).split(/<center>/i).map(plain).filter(Boolean);
      win.control('multilbl_0').setText((parts[0] || '%s').replace('%s', s.opponent?.name || '')).setTextColor('fff4be3d');
      win.control('lbl_quest').setText(parts.slice(1, -1).join(' '));
      win.control('multilbl_1').setText((parts.at(-1) || '%d').replace('%d', String(s.opponent?.points ?? 0)));
      win.data.id = s.id;
    },
    update(win) { const s = st(); if (!s.incoming || s.id !== win.data.id) win.close(); },
  });
  ui.registerWindow('pvp_acceptwait', {
    script: 'game2/pvpbattlewnd/ui_pvprequestwaitwnd.txt', remember: false, escClose: false, band: 'system',
    create(win) { win.control('btn_cancel').onClick(() => { const s=st();if(network.active&&network.token===win.data.token&&s.phase==='invited'&&!s.incoming&&s.id===win.data.id)void P()?.cancel(); win.close(); }); },
    onOpen(win) { win.data.id = st().id;win.data.token=network.token; },
    update(win) {
      const s = st(); if (!network.active||network.token!==win.data.token||s.phase !== 'invited' || s.incoming || s.id !== win.data.id) { win.close(); return; }
      const total = Math.max(1, (s.expiresAt || 0) - (s.createdAt || 0));
      win.control('processbar').setGauge(Math.max(0, Math.min(1, ((s.expiresAt || 0) - now()) / total)));
    },
  });
  ui.registerWindow('pvp_countui', {
    script: 'game2/pvpbattlewnd/ui_pvpcountwnd.txt', remember: false, escClose: false, band: 'hud',
    create(win) { win.control('pan_back_count').setVisible(true); },
    update(win) {
      const s = st(); if (s.phase !== 'countdown') { win.close(); return; }
      const n = Math.max(0, Math.ceil(((s.startAt || 0) - now()) / 1000));
      win.control('lbl_text').setText(plain(S(1008, 8)));
      win.control('lbl_count').setText(`${n} ${plain(S(1008, 10))}`);
    },
  });
  ui.registerWindow('pvpbattlewnd', {
    script: 'game2/pvpbattlewnd/ui_pvpbattlewnd.txt', remember: false, escClose: true, band: 'hud',
    // lbl_get (59 px, no align) cannot hold 280:9 / 1008:14 and ran into lbl_getpoint; it takes the right alignment
    // its sibling caption lbl_total has in the same script so both captions end at the value column.
    create(win) { const g = win.find('lbl_get'), t = win.find('lbl_total'); if (g && t?.spec?.align) g.spec.align = { ...t.spec.align }; },
    onOpen(win) {
      const r = st().result; if (!r) return;
      win.data.at = r.at;
      win.control('lbl_result').setText(plain(r.result === 'win' ? S(280, 8) : r.result === 'lose' ? S(280, 16) : S(280, 80)));
      win.control('lbl_get').setText(plain(r.result === 'lose' ? S(1008, 14) : S(280, 9)));
      win.control('lbl_getpoint').setText(String(r.result === 'lose' ? r.loss : r.gain));
      win.control('lbl_total').setText(plain(S(280, 10)));
      win.control('lbl_totalpoint').setText(String(r.total));
    },
    // resultShowSec 5 = PVPBattleWnd 5000 ms close (FINAL 64-bit decompile FUN_7ff670cfb450; src/game/pvp-rules.js).
    update(win) { const r = st().result; if (!r || r.at !== win.data.at || now() - r.at > ENGINE_CHOSEN.resultShowSec * 1000) win.close(); },
  });
  ui.registerWindow('pvp_restore', {
    script: 'game2/pvpbattlewnd/ui_restorewnd.txt', remember: false, escClose: false, band: 'system',
    create(win) { win.control('btn_accept').onClick(() => { void P()?.restore(); }); win.control('lbl_waittime').setText(plain(S(280, 3))); },
    // The bar runs from the result to restoreAt = the host's 15 s DeadRestoreWnd wait (restoreWaitSec, FINAL 64-bit decompile
    // FUN_7ff670cfcbb0); then pan_respawn and btn_accept show.
    update(win) {
      const s = st(); if (!s.restoreAt || !game.player?.dead) { win.close(); return; }
      const left = s.restoreAt - now(), ready = left <= 0;
      win.control('pan_waittime').setVisible(!ready); win.control('pan_respawn').setVisible(ready);
      if (!ready) win.control('processbar').setGauge(Math.max(0, Math.min(1, 1 - left / Math.max(1, s.restoreAt - (s.result?.at || s.restoreAt - 1000)))));
    },
  });

  // drive the windows from the host state (each snapshot)
  let last = {};
  game.events?.on?.('pvp', ({ state }) => {
    const s = state || {}, open = n => { const w = ui.window?.(n); if (!w?.isOpen) ui.open(n); };
    const blocked = s.phase === 'invited' && s.incoming && declineBlockedInvitation(game,'blockPvp',s.id,()=>P()?.decline());
    if (blocked) ui.close?.('pvp_ask');
    else if (s.phase === 'invited') open(s.incoming ? 'pvp_ask' : 'pvp_acceptwait');
    if (s.phase === 'countdown') { open('pvp_countui'); if (last.phase !== 'countdown') sound(game, 'pvpAccept'); }
    if (s.phase === 'fight' && last.phase !== 'fight') { sound(game, 'pvpStart'); game.chat?.system?.(`${plain(S(1008, 18)) || 'VS'} ${s.opponent?.name || ''}`, 'sys'); }
    if (s.result && s.result.at !== last.result?.at) {
      open('pvpbattlewnd'); sound(game, s.result.result === 'win' ? 'pvpVictory' : 'pvpDefeat');
      const r = s.result, line = r.result === 'win' ? `${plain(S(1008, 11))} ${plain(S(1008, 13))} ${r.gain}` : r.result === 'lose' ? `${plain(S(1008, 12))} ${plain(S(1008, 14))} ${r.loss}` : plain(S(280, 80));
      game.chat?.system?.(`${line} ${plain(S(1008, 15))} ${r.total}`, 'sys');
    }
    if (s.restoreAt && game.player?.dead) open('pvp_restore');
    if (s.notice && s.notice.at !== last.notice?.at) {
      const n = s.notice, text = n.reason === 'declined' ? (n.requester ? S(1008, 7) : '') : S(1008, 4);
      if (text) game.chat?.system?.(plain(text), 'sys');
    }
    last = s;
  });
}
