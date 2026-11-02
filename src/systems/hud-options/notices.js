// Notices and small HUD pieces of the original client:
//   hud_sysmsg     systemwnd/ui_systemmessagewnd.txt  centre-top system message line (+ big message)
//   hud_status     mainbar/ui_statusmsgwnd.txt        stacked status lines at the top centre
//   hud_eventline  systemwnd/ui_eventlinewnd.txt      the big event announcement
//   hud_maptitle   ui_maptitlewnd.txt                 map-name banner (maptitle#<map>) on entering a map
//   death          ui_deathwnd.txt                    death / revive window (Accept = saved location, Revive =
//                                                     a resurrection item on the spot, Blessing, Auto Revive)
//   hud_server     ui_servernamewnd.txt               "Display Server Location" (View option)
//   hud_localtime  ui_localtimewnd.txt                the local date / time under it
//   hud_reception  ui_receptionwnd.txt                "Network Status Display" (View option)
//   hud_helpalarm  helpwindow/ui_helpalarmwnd.txt     the Game Guide button (opens 'guide')
//   tutorialbasic  ui_tutorialbasicwnd.txt            the new-character tips (script/string/stringtable_poptip.txt)
import { gfxC } from '../../ui/gfx-parity-c.js';
import { str, plainMarkup, plainText, clamp } from './util.js';
// Lane 47: Global death window wait text = stringtable_pc 40:125 'You will resurrect in <color=FFFFFF>(%02d)</color> seconds.'
// formatted with remaining ms / 1000 (integer division; decompile 32-bit-main FUN_00b3b4d0, decompiled.c:703654-703672). No invented fallback.
function waitText(win,ms){const t=str(40,125),c=win.control('lbl_waittime');if(!t){c.setText('');return;}const text=t.replace('%02d',String(Math.floor(Math.max(0,ms)/1000)).padStart(2,'0'));if(c.setRichText)c.setRichText(text);else c.setText(plainText(text));}
import { strings } from '../../ui/uiwin/strings.js';
import { installHudAlarmLayout } from '../extras/alarm-slots.js';
import {ORDINARY_RESPAWN_WAIT_MS} from '../../config/engine-chosen-respawn.js';
import {ownedLifeBead} from '../items/life-bead-rules.js';
import {installResurrectionOffer} from './resurrection-offer.js';
import {installSharedTarget} from './shared-target.js';

const SERVER_NAME = 'Dekaron Online';
const SERVER_LABEL = 'Dekaron Online';   // fallback only; the server supplies its chosen display name
const serverLabel = value => typeof value === 'string' && value.trim().length > 0 && value.trim().length <= 64 && !/[\x00-\x1f\x7f]/.test(value) ? value.trim() : null;

export function registerNotices(game, ctx, { request = (...args) => globalThis.fetch(...args), clock = () => performance.now() } = {}) {
  installHudAlarmLayout(game.uiwin);
  const syncResurrectionOffer=installResurrectionOffer(game);
  const syncSharedTarget=installSharedTarget(game);
  // ------------------------------------------------------------------ system message line
  game.uiwin.registerWindow('hud_sysmsg', {
    hud: true, escClose: false, script: 'game2/systemwnd/ui_systemmessagewnd.txt', remember: false,
    create(win) {
      win.data.t = 0;
      win.control('lbl_message').setVisible(false);
      win.control('lbl_bigmessage').setVisible(false);
      // Global SystemMessageWnd (decompile FUN_00b81fd0): a [message] line shows 7000 ms, then the tick hides it (no fade).
      ctx.notice = (text, { big = false, seconds = 7 } = {}) => {
        const id = big ? 'lbl_bigmessage' : 'lbl_message';
        const c = win.control(id);
        const t = plainMarkup(text);
        if (big) c.setRect(0, 0, 800, 150);
        c.setRichText(t).setVisible(true);
        c.el.style.opacity = '1';
        win.data[id] = seconds;
      };
    },
    update(win, dt) {
      syncResurrectionOffer();
      syncSharedTarget();
      for (const id of ['lbl_message', 'lbl_bigmessage']) {
        if (!(win.data[id] > 0)) continue;
        win.data[id] -= dt;
        const c = win.control(id);
        if (win.data[id] <= 0) c.setVisible(false);
      }
    },
  });

  // ------------------------------------------------------------------ status lines
  game.uiwin.registerWindow('hud_status', {
    hud: true, escClose: false, script: 'game2/mainbar/ui_statusmsgwnd.txt', remember: false,
    create(win) {
      win.data.lines = [];
      ctx.status = (text) => {
        const L = win.data.lines;
        L.push({ text: plainMarkup(text), t: 4 });
        while (L.length > 5) L.shift();
        paint();
      };
      function paint() {
        for (let i = 0; i < 5; i++) {
          const c = win.control(`lbl_status_${i}`), l = win.data.lines[i];
          c.setVisible(!!l);
          if (l) { c.setRect(0, i * 22, 200, 30); c.setRichText(l.text); }
        }
      }
      win.data.paint = paint;
    },
    update(win, dt) {
      const L = win.data.lines;
      let changed = false;
      for (const l of L) { l.t -= dt; }
      while (L.length && L[0].t <= 0) { L.shift(); changed = true; }
      L.forEach((l, i) => { const c = win.control(`lbl_status_${i}`); c.el.style.opacity = String(clamp(l.t / 0.6, 0, 1)); });
      if (changed) win.data.paint();
    },
  });

  // ------------------------------------------------------------------ event line
  game.uiwin.registerWindow('hud_eventline', {
    hud: true, escClose: false, script: 'game2/systemwnd/ui_eventlinewnd.txt', remember: false,
    create(win) {
      ctx.eventLine = (text, seconds = 6) => {
        if (!win.isOpen) game.uiwin.open('hud_eventline');
        win.control('lbl_message').setRichText(plainMarkup(text));
        win.control('lbl_message_bg').setText(plainText(text)).setTextColor('ff000000');
        win.data.t = seconds;
        win.root.el.style.opacity = '1';
      };
    },
    update(win, dt) {
      if (!(win.data.t > 0)) return;
      win.data.t -= dt;
      win.root.el.style.opacity = String(clamp(win.data.t / 1, 0, 1));
      if (win.data.t <= 0) game.uiwin.close('hud_eventline');
    },
  });

  // ------------------------------------------------------------------ map title banner
  game.uiwin.registerWindow('hud_maptitle', {
    hud: true, escClose: false, script: 'game2/ui_maptitlewnd.txt', remember: false,
    onOpen(win, mapIndex) {
      win.control('pan_maptitle').setImage('none', 'maptitle', Number(mapIndex) || 0);
      win.data.t = 0;
    },
    update(win, dt) {
      const d = win.data;
      d.t += dt;
      const life = 3.6;
      const a = d.t < 0.5 ? d.t / 0.5 : d.t > life - 0.9 ? Math.max(0, (life - d.t) / 0.9) : 1;
      win.root.el.style.opacity = a.toFixed(3);
      if (d.t >= life) game.uiwin.close('hud_maptitle');
    },
  });
  ctx.mapTitle = (mapIndex) => {
    const has = game.uiwin.atlas?.rect?.('maptitle', Number(mapIndex));
    if (has === null) return false;
    game.uiwin.open('hud_maptitle', mapIndex);
    return true;
  };

  // ------------------------------------------------------------------ server name / network status
  function paintServerLabel(win) {
    const name = win.data.serverLabel;
    if (win.data.paintedServerLabel !== name) { win.control('lbl_server').setText(name); win.data.paintedServerLabel = name; }
    if (game.network && game.network.serverName !== name) game.network.serverName = name;
  }
  function stopServerLabel(win) {
    win.data.serverInfoRequest?.abort();
    win.data.serverInfoRequest = null;
    win.data.serverInfoDue = 0;
  }
  async function refreshServerLabel(win) {
    const d = win.data;
    if (d.serverInfoDisposed || !win.isOpen || d.serverInfoRequest || clock() < d.serverInfoDue) return;
    const controller = new AbortController();
    d.serverInfoRequest = controller; d.serverInfoDue = clock() + 15000;
    try {
      // Use the HUD lifecycle for polling; the request alone has a bounded deadline.
      const signal = AbortSignal.any([controller.signal, AbortSignal.timeout(4000)]);
      const response = await request('/api/server/info', { cache: 'no-store', credentials: 'same-origin', redirect: 'error', signal });
      if (!response.ok) return;
      const info = await response.json(), name = serverLabel(info?.name);
      if (!name || signal.aborted || d.serverInfoRequest !== controller || d.serverInfoDisposed || !win.isOpen) return;
      d.serverLabel = name; paintServerLabel(win);
    } catch { /* Keep the last verified label through temporary disconnects. */ }
    finally { if (d.serverInfoRequest === controller) d.serverInfoRequest = null; }
  }
  game.uiwin.registerWindow('hud_server', {
    hud: true, escClose: false, script: 'game2/ui_servernamewnd.txt', remember: false,
    create(win) {
      win.data.serverLabel = serverLabel(game.network?.serverName) || SERVER_LABEL;
      win.data.serverInfoDue = 0; paintServerLabel(win);
      win.once('dispose', () => { win.data.serverInfoDisposed = true; stopServerLabel(win); });
    },
    onOpen(win) { void refreshServerLabel(win); },
    onClose(win) { stopServerLabel(win); },
    update(win) {
      const on = ctx.options.get('showServer') !== false;
      if (win.data.on !== on) { win.data.on = on; win.root.el.style.visibility = on ? '' : 'hidden'; }
      paintServerLabel(win); void refreshServerLabel(win);
    },
  });
  // Reuse the actual server-name script: identical atlas border, font and
  // centred label, rather than a separately styled HTML badge by the minimap.
  game.uiwin.registerWindow('hud_population', {
    hud: true, escClose: false, script: 'game2/ui_servernamewnd.txt', remember: false,
    create(win) { win.control('lbl_server').setText('Connecting…'); },
    update(win) {
      const on = ctx.options.get('showServer') !== false;
      if (win.data.on !== on) { win.data.on = on; win.root.el.style.visibility = on ? '' : 'hidden'; }
      if(game.network?.disposed&&win.data.populationText!=='Offline'){
        win.control('lbl_server').setText('Offline');win.data.populationText='Offline';
      }
    },
  });
  // the local date and time under the server name (game2/ui_localtimewnd.txt, "2018.01.03 12:24" in the client guide)
  game.uiwin.registerWindow('hud_localtime', {
    hud: true, escClose: false, script: 'game2/ui_localtimewnd.txt', remember: false,
    update(win) {
      const d = new Date(), p = n => String(n).padStart(2, '0');
      const t = gfxC('hudfmt') ? `${p(d.getMonth() + 1)}.${p(d.getDate())}.${d.getFullYear()} ${p(d.getHours())} : ${p(d.getMinutes())}` /* Global 43.19 recording '10.29.2026 08 : 18' */ : `${d.getFullYear()}.${p(d.getMonth() + 1)}.${p(d.getDate())} ${p(d.getHours())}:${p(d.getMinutes())}`;
      if (win.data.t !== t) { win.data.t = t; win.control('lbl_localtime').setText(t); }
    },
  });
  game.uiwin.registerWindow('hud_reception', {
    hud: true, escClose: false, script: 'game2/ui_receptionwnd.txt', remember: false,
    create(win) { win.data.t = 0; },
    update(win, dt) {
      const on = ctx.options.get('showReception') !== false;
      if (win.data.on !== on) { win.data.on = on; win.root.el.style.visibility = on ? '' : 'hidden'; }
      win.data.t -= dt;
      if (win.data.t > 0) return;
      win.data.t = 1;
      const net = game.network;
      const raw = net?.active && net.ready ? net.displayRtt?.() : null;
      const rtt = Number.isFinite(raw) && raw >= 0 ? raw : null;
      const ms = rtt === null ? null : Math.round(rtt);
      const bars = ms === null ? 11 : ms < 30 ? 16 : ms < 50 ? 15 : ms < 80 ? 14 : ms < 120 ? 13 : ms < 200 ? 12 : 11;
      win.control('pan_reception').setSprite('Pantheon', bars);
      win.control('lbl_ping').setText(ms === null ? '—' : (gfxC('hudfmt') ? ms+' ms' : ms+'ms')); // Global 43.19 recording '1 ms'
      win.control('lbl_ping').setTooltip?.(ms !== null ? 'Recent game-server HTTP response time '+ms+' ms (network, server work and response transfer; not network-only ping)\nFrame '+Math.round(ctx.frameMs || 16)+' ms' : net?.active ? 'Game server ping unavailable: connecting, disconnected, or no recent network timing.' : 'Local play: no game server connection.');
    },
  });

  // ------------------------------------------------------------------ game guide button
  game.uiwin.registerWindow('hud_helpalarm', {
    hud: true, escClose: false, script: 'game2/helpwindow/ui_helpalarmwnd.txt', remember: false,
    create(win) {
      const b = win.control('btn_alarm');
      // gfxC4 [alarms]: Global keeps the script's enable false / visible false (helpwindow/ui_helpalarmwnd.txt); the
      // recording (Lv 1, Ardeca) shows no guide button in the top-left grid.
      const showHelp = !gfxC('alarms');
      b.setVisible(showHelp);
      b.setEnabled(showHelp);   // the script ships it enable false / visible false: the client turns it on in game
      // tooltip 100:152 "Game Guide": the helpwindow family's guide window (helpwindow/ui_infownd2.txt)
      b.onClick(() => { game.uiwin.toggle('guide'); b.setBlink(false); if (game.save) game.save.guideSeen = true; });
    },
    onOpen(win) { win.control('btn_alarm').setBlink(!game.save?.guideSeen); },
  });

  // ------------------------------------------------------------------ new-character tips
  game.uiwin.registerWindow('tutorialbasic', {
    script: 'game2/ui_tutorialbasicwnd.txt', escClose: true,
    create(win) {
      // The script's textbox (rect -3 20 318 324, same layer as btn_exit) overlaps the X corner and swallowed its clicks
      // Lift the X above it and close explicitly; X = dismiss the tip chain like Esc.
      const x = win.control('btn_exit');
      if (x?.el) {
        x.el.style.zIndex = '1000'; x.el.style.pointerEvents = 'auto';
        // mark before any default close handler runs, so the X never chains straight into the next tip
        x.el.addEventListener('pointerdown', () => { win.data.dismissed = true; }, true);
      }
      x?.onClick?.(() => win.close('escape'));
    },
    async onOpen(win, ref) {
      const r = ref || { cate: 1, code: 1 };
      win.data.ref = r;
      const s = await strings.resolve({ group: 'POPTIP', cate: r.cate, code: r.code });
      const next = /<nextcate=(\d+)><nextcode=(\d+)>/.exec(s || '');
      win.data.next = next ? { cate: Number(next[1]), code: Number(next[2]) } : null;
      const body = plainMarkup(String(s || '').replace(/<next(cate|code)=\d+>|<eventkey=\d+>/g, ''));
      const lines = body.split('\n');
      const title = plainText(lines.find(l => plainText(l).trim()) || '').replace(/^[▶\s]+/, '');
      win.control('lbl_title').setText(title);
      ctx.renderRich(win.control('textbox'), body, { width: 300 });
    },
    onClose(win, result) {
      const n = win.data.next;
      if (game.save) game.save.tutorialStep = n ? `${n.cate}:${n.code}` : 'done';
      // (playgate) closeAll (map change, death, teleports) ends the chain too; it re-opened a tip over the screen centre
      const dismissed = win.data.dismissed || result === 'escape' || result === 'closeAll';
      win.data.dismissed = false;
      if (n && !dismissed) setTimeout(() => game.uiwin.open('tutorialbasic', n), 400);
    },
  });

  // ------------------------------------------------------------------ death window
  const respawnControl=(win,id)=>win.control('pan_respawn').control(id);
  const online=()=>game.save?.authority==='server'||game.network?.active;
  const beadNow=()=>{const server=game.network?._serverClock;return Math.floor(online()&&Number.isFinite(server?.time)&&Number.isFinite(server?.at)?server.time+performance.now()-server.at:Date.now());};
  const beadState=()=>{
    const now=beadNow(),ready=game.save?.lifeBeadReadyAt??0,valid=Number.isSafeInteger(ready)&&ready>=0;
    const normal=ctx.findReviveItem?.(false,now),blessed=ctx.findReviveItem?.(true,now),self=game.network?.self;
    const scope=!online()||self?.lifeBeadReviveAllowed===true;
    return {now,normal,blessed,scope,valid,cooldown:valid?Math.max(0,ready-now):Infinity};
  };
  const beadControls=(win,waiting)=>{
    const state=beadState(),d=win.data;
    respawnControl(win,'btn_rebirth1').setEnabled(!waiting&&!d.pending&&state.scope&&state.valid&&state.cooldown<=0&&!!state.normal);
    respawnControl(win,'btn_rebirth2').setEnabled(!waiting&&!d.pending&&state.scope&&state.valid&&!!state.blessed);
    const scopeText=state.scope?'':'Life Bead revival is unavailable in this battle scope.';
    const tips=[str(20,398),str(20,399)].map(text=>[text,scopeText].filter(Boolean).join('\n\n')),key=JSON.stringify(tips);
    if(d.beadTips!==key){d.beadTips=key;respawnControl(win,'btn_rebirth1').setTooltip?.(tips[0]);respawnControl(win,'btn_rebirth2').setTooltip?.(tips[1]);}
    const cd=respawnControl(win,'lbl_rebirth_cooltime'),template=str(81,95);
    cd.setVisible(state.scope&&Number.isFinite(state.cooldown)&&state.cooldown>0&&!!template);
    if(state.cooldown>0&&Number.isFinite(state.cooldown)&&template){const seconds=Math.ceil(state.cooldown/1000);cd.setRichText(template.replace(/<set=VALUE2>/gi,`${Math.floor(seconds/60)}:${String(seconds%60).padStart(2,'0')}`));}
    return state;
  };
  game.uiwin.registerWindow('death', {
    script: 'game2/ui_deathwnd.txt', escClose: false, remember: false, band: 'system',
    create(win) {
      const d = win.data;
      win.control('pan_waittime').setVisible(false);
      win.control('pan_revive').setVisible(false);
      const res = win.control('pan_respawn');
      res.setVisible(true);
      const accept = respawnControl(win,'btn_rebirth');
      accept.onClick(() => done('town'));
      respawnControl(win,'btn_rebirth1').onClick(() => done('item'));
      respawnControl(win,'btn_rebirth2').onClick(() => done('blessing'));
      const auto = win.control('check_autorevive');
      auto.on('change', v => ctx.options.set({ autoRevive: !!v }));
      function done(how) {
        if(d.waitUntil>clock()||d.pending||clock()<(d.retryAt||0)||game.player&&!game.player.dead)return;
        let request=d.onRevive||(()=>game.revive());
        if(how==='item'||how==='blessing'){
          const state=beadState(),blessed=how==='blessing',item=blessed?state.blessed:state.normal;
          const owned=ownedLifeBead(game.save,game.items?.db||game.items,item?.uid,state.now);
          if(!state.scope||!state.valid||!owned||owned.rule.blessed!==blessed||!blessed&&state.cooldown>0){{const t=str(40,75);if(t)ctx.chat?.system(t,'err');}return;}
          if(online())request=()=>game.network?.revive(item.uid)??null;
          else request=()=>{if(!ctx.consumeItem?.(item))return false;const result=ctx.reviveHere(owned.rule.hp/100,owned.rule.mp/100);if(result!==false&&owned.rule.cooldown>0)game.save.lifeBeadReadyAt=beadNow()+owned.rule.cooldown;return result;};
        }
        d.pending=true;
        const epoch=d.epoch;
        Promise.resolve().then(request).then(result=>{if(d.epoch!==epoch)return;if(result===false||result===null){d.pending=false;d.retryAt=clock()+1000;return;}win.close('revive');},error=>{if(d.epoch!==epoch)return;d.pending=false;d.retryAt=clock()+1000;if(error?.message)ctx.chat?.system(error.message,'err');});
      }
      d.done = done;
    },
    onOpen(win, onRevive) {
      const d = win.data;
      d.onRevive = typeof onRevive === 'function' ? onRevive : null;
      void strings.need([{cate:81},{cate:20},{cate:40}]).catch(()=>{});
      const net=game.network,ready=net?.self?.respawnReadyAt,serverNow=net?._serverClock?net._serverClock.time+performance.now()-net._serverClock.at:Date.now();
      const wait=net?.active&&Number.isFinite(ready)?Math.max(0,ready-serverNow):ORDINARY_RESPAWN_WAIT_MS;
      d.waitUntil=clock()+wait;d.waitDuration=wait;d.pending=false;d.retryAt=0;d.epoch=(d.epoch||0)+1;
      d.auto = ctx.options.get('autoRevive') ? wait/1000 : 0;
      win.control('pan_waittime').setVisible(wait>0);
      waitText(win,wait);
      win.control('processbar').setValue(0);
      respawnControl(win,'btn_rebirth').setEnabled(wait<=0);
      win.control('check_autorevive').setChecked(!!ctx.options.get('autoRevive'));
      win.control('lbl_auto_time').setVisible(!!d.auto);
      beadControls(win,wait>0);
      const pan = win.control('pan_respawn');
      pan.setRect(Math.round((game.uiwin.screen.w - 232) / 2), Math.round(game.uiwin.screen.h / 2 - 150), 232, 182);
    },
    onClose(win){win.data.epoch++;win.data.pending=false;},
    update(win, dt) {
      const d = win.data;
      if(game.player&&!game.player.dead){win.close('restored');return;}
      const remaining=Math.max(0,d.waitUntil-clock()),waiting=remaining>0;
      win.control('pan_waittime').setVisible(waiting);
      waitText(win,remaining);
      win.control('processbar').setValue(d.waitDuration?1-remaining/d.waitDuration:1);
      respawnControl(win,'btn_rebirth').setEnabled(!waiting&&!d.pending);
      beadControls(win,waiting);
      if (ctx.options.get('autoRevive')) {
        win.control('lbl_auto_time').setVisible(true).setText(`${Math.ceil(remaining/1000)}`);
        if(!waiting&&!d.pending)d.done('town');
      }else{
        win.control('lbl_auto_time').setVisible(false);
      }
    },
  });
}
