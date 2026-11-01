// OBSERVER client (shared play): npc job 40 ENTER_GUILD_OBSERVER (Blake 135, Cain 734) -> venue chooser -> the original
// windows of script/ui/game2/observer/:
//   ui_observer_enterwnd     Join Observer Mode (2100:1): Maximum Observers 2100:13, Current (Guild) Observers 2100:11/12, help 2100:15
//   ui_observer_popwnd       btn_eye + the venue panel: guild (UI / EXIT) or siege (Warp / Accompany / UI / EXIT, 241:0-3)
//   ui_observer_areamovewnd  Move to Observer Area (2100:2): help 2100:16 + the share/observer/info.csv areas (names 2101)
//   ui_observer_optionwnd    Observer UI Options (2100:3): Chat Window 2100:18, Observer Camera 2100:19, Siege Status Window 2100:17
//   ui_observer_exitwnd      Exit (2100:0): 2100:10
// The host (server/world/observer.mjs, action 'observer') seats, warps and returns the observer; rules: observer-rules.js;
// values the data does not define: src/config/engine-chosen-observer.js (ENGINE-CHOSEN). The party-match pop variant
// (pan_observerpop_partypvp, 2100:14) belongs to PARTY-PVP and stays hidden here.
import { OBSERVER_CHOSEN as C } from '../../config/engine-chosen-observer.js';
import { OBSERVER_JOB, OBSERVER_SCRIPTS, OBSERVER_STRINGS, stripItemCaution, followPoint, popVariant } from './observer-rules.js';
import {createObserverMarker} from './marker.js';

export function observerText(game, key, fallback = '') {
  const [cate, code] = OBSERVER_STRINGS[key] || [];
  const s = cate == null ? null : game?.uiwin?.strings?.get?.({ group: 'NORMAL', cate, code });
  return s == null ? fallback : String(s);
}
export function areaName(game, area) {
  const s = area?.textCode == null ? null : game?.uiwin?.strings?.get?.({ group: 'NORMAL', cate: 2101, code: area.textCode });
  return s == null ? String(area?.name || `Area ${Number(area?.index) + 1}`) : String(s);
}
const T = (game, key) => observerText(game, key, key);
/** Fill ui_observer_enterwnd for one venue record (host info). */
export function fillEnterWindow(game, win, venue) {
  win.control('lbl_title').setText(T(game, 'enterTitle'));
  win.control('lbl_usercount_text').setText(T(game, 'max'));
  win.control('lbl_usercount').setText(String(venue.max));
  win.control('lbl_entercount_text').setText(T(game, venue.key === 'guild' ? 'currentGuild' : 'current'));
  win.control('lbl_entercount').setText(String(venue.count));
  win.control('lbl_confirmhelp').setText(`${venue.name}\n${stripItemCaution(T(game, 'enterHelp'))}`);
}
export function fillExitWindow(game, win) {
  win.control('lbl_title').setText(T(game, 'exitTitle'));
  win.control('lbl_exithelp').setText(stripItemCaution(T(game, 'exitHelp')));
}
/** Fill ui_observer_areamovewnd's txt_area: the help text, then one clickable line per area. Returns the area lines. */
export function fillAreaWindow(game, win, venue, onPick) {
  win.control('lbl_title').setText(T(game, 'areaTitle'));
  const box = win.control('txt_area'), help = T(game, 'areaHelp');
  box.setText(help);
  const offset = help.split('\n').length, lines = [];
  for (const a of venue.areas || []) { const text = `${lines.length + 1}. ${areaName(game, a)}`; box.addLine(text, 'ffffe08a'); lines.push({ index: a.index, text }); }
  const rows = box.content?.children;
  lines.forEach((l, i) => { const row = rows?.[offset + i]; if (!row) return; if (row.style) row.style.cursor = 'pointer'; const pick = () => onPick?.(l.index);
    if (row.addEventListener) row.addEventListener('click', pick); else row.onclick = pick; });
  box._observerAreas = lines;
  box.setTop?.(0);   // show the list from the help line (addLine keeps the view at the end)
  return lines;
}
/** Show the pop panel of one venue variant (guild / siege / partypvp) and hide the others. */
export function applyPopVariant(win, variant, open = true) {
  for (const v of ['partypvp', 'guild', 'siege']) win.control(`pan_observerpop_${v}`).setVisible(open && v === variant);
}
const OPTION_KEYS = Object.freeze({ chat: 'chatmode', camera: 'cameramode', situation: 'situationmode' });
export function fillOptionWindow(game, win, opts) {
  win.control('lbl_title').setText(T(game, 'optionTitle'));
  win.control('lbl_chatmode').setText(T(game, 'chat'));
  win.control('lbl_cameramode').setText(T(game, 'camera'));
  win.control('lbl_situationmode').setText(T(game, 'situation'));
  for (const [k, id] of Object.entries(OPTION_KEYS)) win.control(`pan_${id}_check`).setVisible(!!opts[k]);
}

export function installSharedObserver(game, network) {
  const marker=createObserverMarker(game);let disposed=false,epoch=0;
  const st = { seat: null, venues: null, wins: {}, options: { ...C.defaults }, pending: null, following: false, followTimer: null, refresh: null, checked: false, popOpen: true };
  const report = e => { if(disposed)return;let m = e?.message || String(e);const match=/^siege:(241|290):(\d+)$/.exec(m);if(match)m=game.uiwin?.strings?.get?.({group:'NORMAL',cate:Number(match[1]),code:Number(match[2])})||m;(game.chat?.system?.(m, 'err')) ?? game.hud?.log?.(m, 'err'); };
  const online = () => !!network?.active && game.save?.authority === 'server';
  const apply = res => { if (!res||disposed) return; if (res.venues) st.venues = res.venues; const was = st.seat; st.seat = res.seat || null;marker.setSeat(st.seat); if (was && !st.seat) leftVenue(); if (st.seat) seated(); };
  const send = async intent => { const generation=epoch,token=network.token;try { const r = await network.action('observer', intent);if(disposed||generation!==epoch||token!==network.token)return null; const res = r?.observerResult || null; apply(res); return res; } catch (e) { if(generation===epoch)report(e); return null; } };
  const create = async key => {
    const old = st.wins[key]; if (old && !old.disposed) return old;
    const generation=epoch,w = await game.uiwin?.create?.(OBSERVER_SCRIPTS[key], { name: `observer_${key}` }); if (!w) return null;
    if(disposed||generation!==epoch){w.close?.('observer');return null;}
    st.wins[key] = w; return w;
  };
  const close = key => { try { st.wins[key]?.close?.('observer'); } catch { /* closed */ } };
  const venue = () => st.seat && st.venues?.[st.seat.venue];
  // ---- entry
  async function choose(npcIndex,venueKey=null) {
    const res = await send({ operation: 'info' }); if (!res) return;
    if (res.seat) { await openPop(); return; }
    const renew=venueKey&&res.venues?.[venueKey]||Object.values(res.venues||{}).find(v=>v.key?.startsWith('renew-')&&v.npcIndex===npcIndex);
    if(renew){await openEnter(renew,npcIndex);return;}
    const g = npcIndex!==753&&res.venues?.guild?.available ? res.venues.guild : null, s = npcIndex===753&&res.venues?.siege?.available ? res.venues.siege : null;
    if (!g && !s) { report(new Error('No observer venue is open on this server.')); return; }
    let key = g ? 'guild' : 'siege';
    if (g && s && game.uiwin?.msgbox) {
      const r = await game.uiwin.msgbox(C.chooseText, { title: T(game, 'enterTitle'), kind: 'yesno', yes: g.name, no: s.name });
      if (r === 'cancel') return; key = r === 'yes' ? 'guild' : 'siege';
    }
    await openEnter(res.venues[key], npcIndex);
  }
  async function openEnter(v, npcIndex) {
    if (!v) return; const w = await create('enter'); if (!w) return;
    fillEnterWindow(game, w, v);
    if (!w._observerWired) { w._observerWired = true;
      w.control('btn_ok').onClick(async () => { const pend = w._observerPending;w._observerPending=null; w.close('ok'); if (pend&&pend.epoch===epoch&&pend.token===network.token&&pend.world===game.world&&!disposed) await send({ operation: 'enter', venue: pend.venue, ...(Number.isInteger(pend.npcIndex) ? { npcIndex: pend.npcIndex } : {}) }); });
      for (const b of ['btn_cancel', 'btn_exit']) w.control(b).onClick(() => w.close('cancel')); }
    w._observerPending = { venue: v.key, npcIndex,epoch,token:network.token,world:game.world };
    game.uiwin.openWindow(w);
  }
  // ---- seated
  function seated() { void openPop(); if (!st.refresh) st.refresh = setInterval(() => { if (st.seat) void send({ operation: 'info' }).then(situation); }, C.refreshMs); situation(); }
  function leftVenue() {
    marker.clear();
    for (const k of Object.keys(st.wins)) close(k);
    stopFollow(); setChat(true); setCamera(false); game.uiwin?.close?.('ev_dtime');
    if (st.refresh) { clearInterval(st.refresh); st.refresh = null; }
  }
  async function openPop() {
    const v = venue(); if (!v) return; const w = await create('pop'); if (!w) return;
    if (!w._observerWired) { w._observerWired = true;
      w.control('btn_eye').onClick(() => { st.popOpen = !st.popOpen; applyPopVariant(w, popVariant(st.seat?.venue), st.popOpen); });
      w.control('btn_UI_guild').onClick(() => void openOptions()); w.control('btn_exit_guild').onClick(() => void openExit());
      w.control('btn_UI').onClick(() => void openOptions()); w.control('btn_exit').onClick(() => void openExit());
      w.control('btn_warp').onClick(() => void openAreas()); w.control('btn_follow').onClick(() => toggleFollow()); }
    for (const [id, key] of [['btn_warp', 'warp'], ['btn_follow', 'follow'], ['btn_UI', 'ui'], ['btn_exit', 'exitButton'], ['btn_UI_guild', 'ui'], ['btn_exit_guild', 'exitButton']]) w.control(id).setText(T(game, key));
    applyPopVariant(w, popVariant(st.seat.venue), st.popOpen);
    if (!w.isOpen) game.uiwin.openWindow(w);
  }
  async function openExit() {
    const w = await create('exit'); if (!w) return; fillExitWindow(game, w);
    if (!w._observerWired) { w._observerWired = true;
      w.control('btn_ok').onClick(async () => { w.close('ok'); await send({ operation: 'exit' }); });
      for (const b of ['btn_cancel', 'btn_exit']) w.control(b).onClick(() => w.close('cancel')); }
    game.uiwin.openWindow(w);
  }
  async function openAreas() {
    const v = venue(); if (!v?.areas?.length) return; const w = await create('area'); if (!w) return;
    game.uiwin.openWindow(w);
    fillAreaWindow(game, w, v, index => { w.close('ok'); stopFollow();void (async()=>{if(!st.options.camera){report(new Error('siege:241:9'));return;}await send({operation:'camera',enabled:true});await send({ operation: 'warp', area: index });})(); });
    if (!w._observerWired) { w._observerWired = true; w.control('btn_exit').onClick(() => w.close('cancel')); }
  }
  async function openOptions() {
    const w = await create('option'); if (!w) return;
    st.pending = { ...st.options }; fillOptionWindow(game, w, st.pending);
    if (!w._observerWired) { w._observerWired = true;
      for (const [k, id] of Object.entries(OPTION_KEYS)) for (const c of [`pan_${id}`, `pan_${id}_check`, `lbl_${id}`]) {
        const ctl = w.control(c), flip = () => { st.pending[k] = !st.pending[k]; w.control(`pan_${id}_check`).setVisible(st.pending[k]); };
        if (ctl.el?.addEventListener) { ctl.el.style.cursor = 'pointer'; ctl.el.style.pointerEvents = 'auto'; ctl.el.addEventListener('click', flip); } else ctl.onClick?.(flip); }
      w.control('btn_apply').onClick(() => applyOptions(st.pending));
      w.control('btn_ok').onClick(() => { applyOptions(st.pending); w.close('ok'); });
      for (const b of ['btn_cancel', 'btn_exit']) w.control(b).onClick(() => w.close('cancel')); }
    game.uiwin.openWindow(w);
  }
  function applyOptions(o) { st.options = { ...o }; setChat(o.chat); setCamera(o.camera); situation(); }
  function setChat(on) { const w = game.uiwin?.window?.('hud_chat'); if (w?.el?.style) w.el.style.visibility = on ? '' : 'hidden'; }
  async function freecam() {
    if (game.gm?.freecam?.set) return game.gm.freecam;
    if (!st.cam) { try { const { FreeCam } = await import('../gm/worldtools.js'); st.cam = new FreeCam(game); } catch { st.cam = null; } }
    return st.cam;
  }
  async function setCamera(on) { const cam = await freecam(); if (!cam?.set) return; if (on && st.seat) { cam.speed = venue()?.cameraSpeed || cam.speed; cam.set(true); } else if (cam.on && cam._observer) cam.set(false); cam._observer = !!on && !!st.seat;if(st.seat)await send({operation:'camera',enabled:!!on}); }
  async function situation() {
    const v = venue(); if (!v) return;
    if (!st.options.situation) { game.uiwin?.close?.('ev_dtime'); return; }
    const lines = [`<color=fdb602>${T(game, v.key === 'guild' ? 'currentGuild' : 'current')}:</color> ${v.count} / ${v.max}`];
    if (v.key === 'siege') lines.unshift(`<color=fdb602>${T(game, 'situation')}:</color> ${C.situationIdle}`);
    if(v.key.startsWith('renew-')){const clock=network._serverClock,now=clock?clock.time+performance.now()-clock.at:Date.now(),seconds=Math.max(0,Math.ceil(((v.endAt||0)-now)/1000));lines.unshift(`${v.name}: ${Math.floor(seconds/60)}:${String(seconds%60).padStart(2,'0')}`);}
    st.lines = lines;
    try { if (!st.ui) { const { EventUI } = await import('../events/windows.js'); st.ui = new EventUI(game, st); } await st.ui.dungeonTimes(lines); } catch { /* HUD optional */ }
  }
  // ---- Accompany (siege pop btn_follow)
  function toggleFollow() { if (st.following) { stopFollow(); return; }
    const t = game.player?.target; if (!t || t.kind !== 'player' || t === game.player) { report(new Error('Select a player to accompany.')); return; }
    st.following = true; st.followTimer = setInterval(() => { const target = game.player?.target;
      if (!st.seat || !target || target.kind !== 'player' || target.dead) { stopFollow(); return; }
      const p = followPoint(game.player, target); if (p) game.controller?.moveTo?.(p.x, p.z); }, C.followEveryMs); }
  function stopFollow() { st.following = false; if (st.followTimer) { clearInterval(st.followTimer); st.followTimer = null; } }
  // ---- wiring: npc job 40, first snapshot info, map changes
  let services = null;
  // The events system answers job 40 offline with its original text; this handler goes first and passes when not online.
  const handler = n => { if (!online()) return false; game.uiwin?.close?.('npc'); void choose(Number(n?.npcIndex ?? n?.index ?? n?.st ?? n?.def?.index)); return true; };
  const siegeHandler=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index)===753?handler(n):false;
  const register = () => { const s = game.npcServices; if (!s?.register) return;
    const list = s.handlers instanceof Map ? s.handlers.get(OBSERVER_JOB) : null;
    if (Array.isArray(list)) { if (list[0] !== handler) { const i = list.indexOf(handler); if (i >= 0) list.splice(i, 1); list.unshift(handler); } }
    else if (services !== s || s.get?.(OBSERVER_JOB) !== handler) s.register(OBSERVER_JOB, handler);
    const siegeList=s.handlers instanceof Map?s.handlers.get(36):null;
    if(Array.isArray(siegeList)){if(!siegeList.includes(siegeHandler))siegeList.unshift(siegeHandler);}else if(services!==s)s.register(36,siegeHandler);
    services = s; };
  register(); const offSystems=game.events?.on?.('systems', register);
  const offMap=game.events?.on?.('map',({index})=>{if(st.seat&&Number(index)!==Number(st.seat.map)){st.seat=null;leftVenue();}else marker.setSeat(st.seat);});
  const original = network._snapshot?.bind(network);
  if (original) network._snapshot = snapshot => { original(snapshot); if (network.disposed) return;
    if(disposed)return;register(); if (!st.checked && network.ready && network.token && !network._joining) { st.checked = true; setTimeout(() => {if(!disposed)void send({ operation: 'info' });}, 0); }
    if(st.seat&&network.self&&(network.self.map!==st.seat.map||(st.seat.instanceId&&network.self.instanceId!==st.seat.instanceId))){st.seat=null;leftVenue();}
    if (st.seat && Number(game.world?.info?.index) === st.seat.map && !st.wins.pop?.isOpen) void openPop(); };
  game.chat?.registerCommand?.('/observerexit', () => { if (st.seat) void openExit(); return true; }, 'Leave Observer mode.');
  const leave = network.leave?.bind(network); if (leave) network.leave = options => { epoch++;st.checked=false;st.seat = null; leftVenue(); return leave(options); };
  const dispose=()=>{if(disposed)return;disposed=true;epoch++;st.seat=null;leftVenue();marker.dispose();offSystems?.();offMap?.();services?.unregister?.(OBSERVER_JOB,handler);services?.unregister?.(36,siegeHandler);};
  game.observer = { state: st, choose, openEnter, openPop, openExit, openAreas, openOptions, applyOptions, send,apply,update:dt=>marker.update(dt),dispose };
  return game.observer;
}
