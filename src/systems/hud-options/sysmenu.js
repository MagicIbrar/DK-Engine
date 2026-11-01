// The system menu (Esc / the main menu's option button): script/ui/game2/systemwnd/ui_systemwnd.txt
//   Option -> the Option window, Channel -> the channel list (systemwnd/ui_serverselect.txt),
//   Character -> back to character select, Exit Game -> leave (systemwnd/ui_systemwaitwnd.txt "Store Game
//   Information ... Please wait." with its progress bar, cancellable), Cancel.
// Registered as 'settings' so game.js's Esc (windows.toggle('settings')) and the old menu column open it.
import { strAsync } from './util.js';
import { installServerControl } from './server-control.js';
import { currentAccountId } from '../../game/save.js';
import { loadChannelData } from '../channels/data.js';
import { movedText } from '../channels/channel-rules.js';

// Channel list = share/channellist.csv (gamedata/channels.json field: Divine Valley, Kalibus, nonPK, PK).
// Shared play runs every channel on the host (server/world/channels.mjs); single player has only Channel Index 0.

export function registerSystemMenu(game, ctx) {
  const serverControl=installServerControl(game);
  game.uiwin.registerWindow('settings', {
    script: 'game2/systemwnd/ui_systemwnd.txt', band: 'system',
    create(win) {
      win.control('btn_option').onClick(() => { win.close('option'); game.uiwin.open('options'); });
      win.control('btn_server').onClick(() => { win.close('channel'); game.uiwin.open('channels'); });
      win.control('btn_charselect').onClick(() => { win.close('select'); leave('select'); });
      win.control('btn_exit').onClick(() => { win.close('exit'); leave('login'); });
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      if(serverControl){const button=win.control('btn_server').cloneAs('_gmserver',{x:26,y:230,visible:false});button.setText('GM Server').onClick(()=>{if(serverControl.canStop){win.close('gmserver');game.uiwin.open('gmserver');}});win.data.serverButton=button;}
      // The signed-in account under the buttons (the original menu has no such line).
      const line=win.data.accountLine=document.createElement('div');
      line.className='dk-sysmenu-account';
      line.style.cssText='position:absolute;left:6px;right:6px;height:16px;text-align:center;font:11px Tahoma,Verdana,sans-serif;color:#d8c8a0;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;pointer-events:none';
      win.control('pan_system').el.appendChild(line);
      win.data.layout=-1;
    },
    update(win){
      const ready=!!serverControl?.canStop,account=currentAccountId()||'';
      if(win.data.serverButton&&win.data.serverReady!==ready){win.data.serverReady=ready;win.data.serverButton.setVisible(ready);}
      const height=(win.data.serverButton&&ready?274:234)+(account?20:0);
      if(win.data.accountLine&&win.data.accountLine.textContent!==(account?`Account: ${account}`:'')){win.data.accountLine.textContent=account?`Account: ${account}`:'';}
      if(win.data.layout!==height){win.data.layout=height;win.control('pan_system').setRect(0,0,150,height);if(win.data.accountLine)win.data.accountLine.style.top=`${height-24}px`;}
    }
  });

  const shared = () => !!(game.network?.active && game.network?.ready);
  game.uiwin.registerWindow('channels', {
    script: 'game2/systemwnd/ui_serverselect.txt',
    async create(win) {
      const data = win.data.channels = await loadChannelData().catch(() => null);
      const tpl = win.control('btn_server'), bg = win.control('pan_bg');
      win.data.btns = (data?.field || []).map((c, i) => {
        const b = i === 0 ? tpl : tpl.cloneAs(`_${i}`, { x: 15, y: 40 + i * 25, parent: bg });
        b.setText(c.name);
        b.onClick(() => { win.close('ok'); void pick(data, c.index); });
        return b;
      });
      if (!win.data.btns.length) tpl.setVisible(false);
    },
    onOpen(win) {
      const count = shared() ? win.data.btns.length : Math.min(1, win.data.btns.length);
      win.data.btns.forEach((b, i) => b.setVisible(i < count));
      win.control('pan_bg').setRect(0, 0, 130, 70 + count * 25);
    },
  });
  const pick = (data, index) => pickChannel(game, ctx, data, index);

  game.uiwin.registerWindow('systemwait', {
    script: 'game2/systemwnd/ui_systemwaitwnd.txt', modal: true, escClose: true, band: 'system',
    create(win) {
      win.control('btn_cancel').onClick(() => win.close('cancel'));
    },
    onOpen(win, arg) { win.data.t = 0; win.data.arg = arg; win.control('processbar').setGauge(0); },
    update(win, dt) {
      const d = win.data;
      d.t += dt;
      const T = 3;
      win.control('processbar').setGauge(Math.min(1, d.t / T));
      if (d.t >= T && !d.fired) { d.fired = true; const a = d.arg; win.close('done'); a?.go?.(); d.fired = false; }
    },
  });

  function leave(screen) {
    game.uiwin.open('systemwait', {
      go: () => {
        try { game.persist?.(); } catch (err) { console.error(err); }
        if (globalThis.dekaronReturnTo) globalThis.dekaronReturnTo(screen);
        else globalThis.location?.reload?.();
      },
    });
  }
}

// ---- channel change = the server's 10 s frozen cast, shown on the original warp progress window ----
// 2.2.1 (Global): the change is a 10 s bar (the server's cast, src/config/owner-travel-freeze.js); moving is refused
// meanwhile and damage interrupts it. The bar is the original warp progress window game2/ui_warpteleportwnd.txt, as the big
// map's teleports use. The client only shows the bar: the host decides when the cast is over (movefinish) and what interrupts it.
// ENGINE-CHOSEN (no data holds them): the 250 ms timer that keeps the cast moving while the tab is hidden (a hidden tab
// pauses requestAnimationFrame), and the 400 ms a "the cast is gone" reading must persist before the bar is dropped (a
// snapshot that was already in flight when the cast began must not close it).
const LOST_CAST_MS = 400, TIMER_MS = 250;
const casting = new WeakSet();   // games that have a channel cast bar running: one cast at a time
/**
 * Pick channel `index` from the channel list. env = { now, setTimeout, clearTimeout, requestAnimationFrame } (tests inject a fake clock).
 * Resolves true when the host moved the player, false otherwise (not shared, same channel, refused, cancelled, interrupted).
 */
export async function pickChannel(game, ctx, data, index, env = {}) {
  const net = game.network;
  const shared = !!(net?.active && net?.ready);
  const current = shared ? net.self?.channel ?? 0 : 0;
  // already on this channel: the client just closes the list (230:94 "You have moved to the <CHANNEL>.")
  if (!shared || current === index) { ctx.chat?.system(movedText(data, current)); return false; }
  if (casting.has(game)) return false;
  casting.add(game);
  const now = env.now || (() => performance.now());
  const later = env.setTimeout || ((fn, ms) => globalThis.setTimeout(fn, ms));
  const unlater = env.clearTimeout || (id => globalThis.clearTimeout(id));
  const frame = env.requestAnimationFrame || (globalThis.requestAnimationFrame ? fn => globalThis.requestAnimationFrame(fn) : null);
  let cast = null, win = null, cancel = false, interrupted = false, closing = false, wake = null;
  const alive = () => net.active && net.ready && net.self?.smartWarp?.nonce === cast.nonce;
  try {
    const begin = await net.action('channel', { operation: 'move', channel: index });
    const result = begin?.channelResult;
    if (result?.operation !== 'cast') { const text = result?.text; if (text) ctx.chat?.system(text); return false; }
    cast = result;
    game.controller?.stop?.();
    const ms = Math.max(1000, cast.readyAt - (begin.serverTime || Date.now()));
    const title = (await strAsync(30, 94).catch(() => '')) || 'Channel';   // 30|94 "Channel" (the channel list's own title)
    win = await game.uiwin.create('game2/ui_warpteleportwnd.txt', { name: 'warpteleport', modal: true, remember: false, disposeOnClose: true });
    win.control('lbl_title')?.setText?.(title);
    win.control('lbl_text')?.setText?.(cast.name || '');
    const bar = win.control('processbar');
    bar?.setGauge?.(0);
    // Cancel, Esc and every other way the window is closed (map change, death: uiwin.closeAll) cancel the cast
    win.control('btn_cancel')?.onClick?.(() => { cancel = true; win.close('cancel'); });
    win.on?.('close', () => { if (!closing) { cancel = true; wake?.(); } });
    game.uiwin.openWindow(win);
    const T0 = now();
    await new Promise(resolve => {
      let live = true, timer = null, rafPending = false, lostAt = null;
      const end = () => { if (!live) return; live = false; unlater(timer); resolve(); };
      wake = end;
      const step = () => {
        if (!live) return;
        if (cancel) return end();
        // the server drops the cast when the player is hit, moves, mounts, dies or the lease ends: stop the bar
        if (!alive()) { lostAt ??= now(); if (now() - lostAt >= LOST_CAST_MS) { interrupted = true; return end(); } } else lostAt = null;
        const f = Math.min(1, (now() - T0) / ms);
        bar?.setGauge?.(f);
        if (f >= 1 && lostAt == null) return end();
        unlater(timer); timer = later(step, TIMER_MS);
        if (frame && !rafPending) { rafPending = true; frame(() => { rafPending = false; step(); }); }
      };
      step();
    });
    closing = true;
    if (cancel || interrupted) {
      if (interrupted) win.close('interrupted');
      // cancelled by the player: release the host's cast (it also freezes movement); interrupted: the host already dropped it
      if (cancel && net.active && net.ready) await net.action('channel', { operation: 'movecancel', nonce: cast.nonce });
      return false;
    }
    win.close('done');
    const done = await net.action('channel', { operation: 'movefinish', nonce: cast.nonce });
    const text = done?.channelResult?.text; if (text) ctx.chat?.system(text);
    return !!done;
  } catch (error) {
    // the bar could not be built: never leave the host's cast freezing the character
    console.error('[channel] cast', error);
    if (cast && net.active && net.ready) await net.action('channel', { operation: 'movecancel', nonce: cast.nonce }).catch(() => null);
    try { if (win?.isOpen) { closing = true; win.close('failed'); } } catch { /* already gone */ }
    return false;
  } finally { casting.delete(game); }
}
