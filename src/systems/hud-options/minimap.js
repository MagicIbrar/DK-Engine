// Minimap (script/ui/game2/minimap/ui_minimapwnd.txt) and the big map window (script/ui/game2/ui_new_mapwnd.txt).
//
// Minimap texture: imagetable group `minimap`, index = map index, 512 x 512 px = 512 x 512 cells, transposed
// (docs/formats/coords.md: texel u = FILE Z, v = FILE X). The 512 px pan_map sits inside the 158 px pan_minimap_bg
// viewport (it clips) and is moved so the player stays centred. + / _ (btn_bigmap_show / _hide, mainbar_minimap
// #60/#61) switch between the normal and the doubled scale; the up/down arrows fold the map away. Player arrow
// (#30), camera radar (#35), NPC marks (mainbar_minimap #120 + npcs.json minimapColor; 22-26 = the siege
// guardian stones #142-146), the move-target flag (#32) and markers added by other systems
// (game.minimap.setMarker). The day/night dial scrolls the two 512 px time strips (#90/#91) with the time of day.
// A click on the minimap walks there.
import { gfxC } from '../../ui/gfx-parity-c.js';
import { paintIcon } from '../../ui/uiwin/controls.js';
import { npcDef } from '../../ui/gameinfo.js';
import { loadStringTable, NPC_JOB, npcJobNameTitle } from '../../ui/strings.js';
import { fetchCSVObjects } from '../../engine/assets.js';
import { str, LS, clamp, npcNameFix } from './util.js';
import { hasGMPanelPermission } from '../gm/permissions.js';
import {drawWorldMapParty,worldMapPartyRows} from './map-party.js';
import { DAY_UNITS } from '../../formats/environment.js';

// Share the environment's authored clock; the HUD must not run a second day.
export function minimapDayFraction(env, elapsed = 0) {
  const value = env?.time != null && Number.isFinite(Number(env.time))
    ? Number(env.time) / DAY_UNITS
    : env?.dayFraction ?? env?.timeOfDay ?? env?.t;
  const t = value != null && Number.isFinite(Number(value)) ? Number(value) : (Number(elapsed) || 0) / 1200;
  return ((t % 1) + 1) % 1;
}

const VIEW = 158;
const HALF = VIEW / 2;
// mainbar_minimap#32, minimap_02.dds rect304,135,34,38: the opaque pole
// base spans x7..12 on row31; six bottom rows are transparent. Place that
// visible base at the destination, not the transparent rectangle's bottom center.
// This anchor is derived from authored pixels; the packed executable's anchor
// is unavailable. The sprite and hit geometry remain native.
export const MINIMAP_MOVE_FLAG_ANCHOR = Object.freeze([10, 32]);
// Selected-NPC glow cycle on the big map (seconds). ENGINE-CHOSEN: no file holds it (the pulse is inside the packed client);
// Global pulses on a 4-6 s cycle, so the middle of that range.
const NPC_PULSE_S = 5;
let jobStrings = null;
loadStringTable(NPC_JOB).then(t => { jobStrings = t; }).catch(() => {});

/** FILE (x, z) -> minimap texel (u right, v down): transposed. */
export const toTex = (x, z) => ({ u: z, v: x });
/** texel -> FILE */
export const fromTex = (u, v) => ({ x: v, z: u });
/** Screen angle (radians, clockwise from up) of a FILE direction on the minimap. */
export function texAngle(fx, fz) { const t = toTex(fx, fz); return Math.atan2(t.u, -t.v); }

/** NPC name (+ title) from the job string table. */
export function npcNameTitle(game, n) {
  const d = npcDef(game, n);
  const js = jobStrings?.get(Number(d.desc));
  // a few event NPCs kept Korean job strings in this EU client: the EU name of npc.csv is used instead (util.js)
  return npcNameFix(npcJobNameTitle(n, js), n.name || d.name);
}

export function registerMinimap(game, ctx) {
  const markers = new Map();   // id -> {x, z, sprite:[g,i], size, tip, el}
  game.minimap = {
    /** Add or move a marker: {x, z, sprite:[group, index], size:[w,h], tip, map} (map defaults to the current one). */
    setMarker(id, m) { markers.set(id, { ...(markers.get(id) || {}), ...m }); },
    removeMarker(id) { const m = markers.get(id); m?.el?.remove(); markers.delete(id); },
    markers,
  };

  game.uiwin.registerWindow('hud_minimap', {
    hud: true, escClose: false, script: 'game2/minimap/ui_minimapwnd.txt',
    create(win) {
      const d = win.data;
      d.map = win.control('pan_map');
      d.bg = win.control('pan_minimap_bg');
      d.bg.setClip(true);
      // The authored 512px time strips scroll inside this 45px aperture.
      win.control('pan_time_rect').setClip(true);
      const mapName=win.control('lbl_mapName');
      mapName.setClip(true);
      mapName.setTooltip?.(()=>mapName.getText());
      d.layer = document.createElement('div');
      d.layer.style.cssText = 'position:absolute;left:0;top:0;width:100%;height:100%;pointer-events:none';
      d.map.el.appendChild(d.layer);
      d.npcEls = new Map();
      d.partyEls = new Map(); d.partyArrows = new Map();   // party members: the dot (pan_party, mainbar_minimap #126) and the edge arrow (pan_partyindicate #140)
      const zoom = (z) => { ctx.options.set({ minimapZoom: z }); paintButtons(); d.lastKey = ''; };
      win.control('btn_bigmap_show').onClick(() => zoom(1));
      win.control('btn_bigmap_hide').onClick(() => zoom(0));
      win.control('btn_minimap_hide').onClick(() => { ctx.options.set({ minimapHidden: true }); paintButtons(); });
      win.control('btn_minimap_show').onClick(() => { ctx.options.set({ minimapHidden: false }); paintButtons(); });
      // The corner map uses the same authenticated GM destination as the big map.
      // Ordinary players still issue a walk order; no modifier or panel is needed for an admin.
      d.bg.on('click', (e) => {
        const p = game.player; if (!p) return;
        const r = d.map.el.getBoundingClientRect();
        // Invert the actual painted map origin. Its scrolling rectangle is
        // rounded to pixels, so reconstructing it from the player loses up to
        // half a reference pixel, especially at fractional HUD scales.
        if (!(r.width > 0 && r.height > 0)) return;
        const u = (e.clientX - r.left) * 512 / r.width, v = (e.clientY - r.top) * 512 / r.height;
        const w = fromTex(u, v);
        if (game.gm) game.gm._ctrlAt = 0;
        if (game.gm?._ctrlTeleport && hasGMPanelPermission(game) &&
            (game.save?.authority !== 'server' || game.accountPermissions?.capabilities?.includes('gm:commands'))) {
          game.gm._ctrlTeleport(w.x, w.z);
          return;
        }
        game.controller?.moveTo?.(w.x, w.z);
      });
      d.bg.el.style.cursor = 'pointer';
      d.bg.el.classList.add('uw-hit');
      d.bg.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); zoom(e.deltaY < 0 ? 1 : 0); }, { passive: false });
      function paintButtons() {
        const zoomed = ctx.options.get('minimapZoom') === 1, hidden = !!ctx.options.get('minimapHidden');
        win.control('btn_bigmap_show').setVisible(!zoomed);
        win.control('btn_bigmap_hide').setVisible(zoomed);
        win.control('btn_minimap_hide').setVisible(!hidden);
        win.control('btn_minimap_show').setVisible(hidden);
        win.control('pan_minimap').setVisible(!hidden);
      }
      d.paintButtons = paintButtons;
      paintButtons();
      game.events?.on?.('moveorder', (e) => { d.moveTarget = e && Number.isFinite(e.x) ? { x: e.x, z: e.z, t: 0 } : null; });
    },
    onOpen(win) { win.data.lastKey = ''; },
    update(win, dt) {
      const g = game, p = g.player, d = win.data;
      if (!p || !g.world) return;
      const mapIndex = g.world.info?.index;
      const k = scale();
      // map name / texture
      if (d.mapIndex !== mapIndex) {
        d.mapIndex = mapIndex;
        const row = g.mapRow?.(mapIndex) || g.data?.mapByIndex?.(mapIndex);
        const mapName=win.control('lbl_mapName');
        mapName.setText(row?.Name || g.world.info?.name || '');
        // Keep long original map names inside the authored 108px header;
        // its tooltip preserves the complete name without covering nearby art.
        if(mapName.txt?.firstChild)Object.assign(mapName.txt.firstChild.style,{maxWidth:'100%',overflow:'hidden',textOverflow:'ellipsis'});
        d.map.setImage('none', 'minimap', mapIndex);
        for (const el of d.npcEls.values()) el.remove();
        d.npcEls.clear();
        for (const el of [...d.partyEls.values(), ...d.partyArrows.values()]) el.remove();
        d.partyEls.clear(); d.partyArrows.clear();
        d.lastKey = '';
      }
      // position + scroll
      // opt-6: each string / rotation below is a pure function of a few numbers; it is only rebuilt (and the DOM only
      // touched) when those numbers changed since the frame that produced the current DOM state. d.pos / d.lastKey stay the
      // authority: whoever resets them (zoom, onOpen, map change) still forces the rewrite.
      const fx = Math.floor(p.x), fz = Math.floor(p.z);
      if (!(d.posX === fx && d.posZ === fz && d.pos === d.posStr)) {
        const pos = gfxC('hudfmt') ? `${fx} : ${fz}` : `${fx}, ${fz}`; // Global 43.19 recording '206 : 243'
        d.posX = fx; d.posZ = fz; d.posStr = pos;
        if (d.pos !== pos) { d.pos = pos; win.control('lbl_position').setText(pos); }
      }
      if (!(d.keyX === p.x && d.keyZ === p.z && d.keyK === k && d.lastKey === d.keyStr)) {
        const P = toTex(p.x, p.z);
        const key = `${(P.u * k).toFixed(1)}|${(P.v * k).toFixed(1)}|${k}`;
        d.keyX = p.x; d.keyZ = p.z; d.keyK = k; d.keyStr = key;
        if (d.lastKey !== key) { d.lastKey = key; d.map.setRect(Math.round(HALF - P.u * k), Math.round(HALF - P.v * k), 512 * k, 512 * k); }
      }
      // player arrow + camera radar
      const yaw = p.yaw || 0, arrowEl = win.control('pan_pointArrow').el;
      if (d.arrowYaw !== yaw || d.arrowEl !== arrowEl) {
        d.arrowYaw = yaw; d.arrowEl = arrowEl;
        rotate(arrowEl, texAngle(-Math.sin(yaw), -Math.cos(yaw)));
      }
      if (g.camera?.getWorldDirection) {
        const v = g.camera.getWorldDirection(ctx.tmpV), camEl = win.control('pan_pointCamera').el;
        if (d.camX !== v.x || d.camZ !== v.z || d.camEl !== camEl) {
          d.camX = v.x; d.camZ = v.z; d.camEl = camEl;
          rotate(camEl, texAngle(v.x, -v.z));
        }
      }
      // NPC marks (4 Hz)
      d.t = (d.t || 0) - dt;
      if (d.t <= 0) { d.t = 0.25; drawNpcs(win, k); drawMarkers(win, k); drawParty(win, k); }
      // move-target flag
      const mt = d.moveTarget;
      const flag = win.control('pan_movetargetmini');
      if (mt && Math.hypot(mt.x - p.x, mt.z - p.z) > 1.2) {
        const T = toTex(mt.x, mt.z);
        flag.setVisible(true);
        flag.setRect(Math.round(T.u * k - MINIMAP_MOVE_FLAG_ANCHOR[0]), Math.round(T.v * k - MINIMAP_MOVE_FLAG_ANCHOR[1]), 34, 38);
      } else { if (mt) d.moveTarget = null; flag.setVisible(false); }
      dayNight(win);
    },
  });

  function scale() { return ctx.options.get('minimapZoom') === 1 ? 2 : 1; }
  function rotate(el, a) { if (el) el.style.transform = `rotate(${a.toFixed(3)}rad)`; }

  function drawNpcs(win, k) {
    const d = win.data;
    // opt-6 (4 Hz, but ~100 NPCs in a town): a frame stamp on the mark instead of a Set, and left / top are written only when the
    // rounded pixel changed (NPCs stand still: the old code rewrote 200 style strings every 0.25 s)
    const stamp = d.npcStamp = (d.npcStamp || 0) + 1;
    for (const n of game.npcs || []) {
      const def = npcDef(game, n);
      if (Number(def.mapVisible) === 0) continue;
      const c = Number(def.minimapColor) || 0;
      let el = d.npcEls.get(n);
      if (!el) {
        el = document.createElement('div');
        el.className = 'uw-icon';
        el.style.width = '10px'; el.style.height = '10px';
        paintIcon(el, { sprite: ['mainbar_minimap', 120 + c] });
        d.layer.appendChild(el);
        d.npcEls.set(n, el);
      }
      const left = Math.round(n.z * k - 5), top = Math.round(n.x * k - 5);   // toTex(x, z) = { u: z, v: x }
      if (el._mmLeft !== left) { el._mmLeft = left; el.style.left = `${left}px`; }
      if (el._mmTop !== top) { el._mmTop = top; el.style.top = `${top}px`; }
      el._mmSeen = stamp;
    }
    for (const [n, el] of d.npcEls) if (el._mmSeen !== stamp) { el.remove(); d.npcEls.delete(n); }
  }
  /** Party members on this map (original ui_minimapwnd.txt pan_party / pan_partyindicate): a dot where they stand, an arrow on the edge of the
   *  view pointing at the ones beyond it. Positions come from the shared-world player rows (every player of the scene is in the snapshot). */
  function drawParty(win, k) {
    const d = win.data, p = game.player, net = game.network, map = game.world?.info?.index;
    if (!d.partyEls) { d.partyEls = new Map(); d.partyArrows = new Map(); }
    const members = net?.active && p ? (net.party?.members || []) : [];
    const currentMembers = new Set(worldMapPartyRows(game).map(member => member.id));
    const seen = new Set();
    for (const m of members) {
      if (!m?.id || m.id === net.self?.id || Number(m.map) !== Number(map) || !currentMembers.has(m.id)) continue;
      const a = net.players?.get?.(m.id);
      if (!a || !Number.isFinite(a.x) || !Number.isFinite(a.z)) continue;
      seen.add(m.id);
      const dx = (a.z - p.z) * k, dy = (a.x - p.x) * k;   // minimap pixels from the player (texel u = z, v = x)
      const inside = Math.abs(dx) <= HALF - 6 && Math.abs(dy) <= HALF - 6;
      let dot = d.partyEls.get(m.id);
      if (!dot) { dot = document.createElement('div'); dot.className = 'uw-icon'; dot.style.width = dot.style.height = '10px'; paintIcon(dot, { sprite: ['mainbar_minimap', 126] }); d.layer.appendChild(dot); d.partyEls.set(m.id, dot); }
      dot.title = m.name || '';
      dot.style.display = inside ? '' : 'none';
      if (inside) { dot.style.left = `${Math.round(a.z * k - 5)}px`; dot.style.top = `${Math.round(a.x * k - 5)}px`; }
      let arrow = d.partyArrows.get(m.id);
      if (!arrow) { arrow = document.createElement('div'); arrow.className = 'uw-icon'; arrow.style.width = '14px'; arrow.style.height = '21px'; arrow.style.pointerEvents = 'none'; paintIcon(arrow, { sprite: ['mainbar_minimap', 140] }); d.bg.el.appendChild(arrow); d.partyArrows.set(m.id, arrow); }
      arrow.style.display = inside ? 'none' : '';
      if (!inside) {
        const s = (HALF - 12) / Math.max(Math.abs(dx), Math.abs(dy), 1);
        arrow.style.left = `${Math.round(HALF + dx * s - 7)}px`; arrow.style.top = `${Math.round(HALF + dy * s - 10)}px`;
        rotate(arrow, Math.atan2(dx, -dy));
      }
    }
    for (const [id, el] of d.partyEls) if (!seen.has(id)) { el.remove(); d.partyEls.delete(id); }
    for (const [id, el] of d.partyArrows) if (!seen.has(id)) { el.remove(); d.partyArrows.delete(id); }
  }
  function drawMarkers(win, k) {
    const d = win.data, map = game.world?.info?.index;
    for (const m of markers.values()) {
      const on = m.map == null || Number(m.map) === map;
      if (!m.el) { m.el = document.createElement('div'); m.el.className = 'uw-icon'; d.layer.appendChild(m.el); m.painted = null; }
      if (m.el.parentNode !== d.layer) d.layer.appendChild(m.el);
      m.el.style.display = on ? '' : 'none';
      if (!on) continue;
      const [w, h] = m.size || [10, 10];
      const sig = (m.sprite || []).join('#');
      if (m.painted !== sig) { m.painted = sig; paintIcon(m.el, m.sprite ? { sprite: m.sprite } : null); }
      const T = toTex(m.x, m.z);
      m.el.style.width = `${w}px`; m.el.style.height = `${h}px`;
      m.el.style.left = `${Math.round(T.u * k - w / 2)}px`; m.el.style.top = `${Math.round(T.v * k - h / 2)}px`;
    }
  }
  /** Day/night dial: the two 512 px strips scroll with the environment's time of day (0..1). */
  function dayNight(win) {
    const env = game.world?.environment;
    const t = minimapDayFraction(env, game.time);
    const x = -Math.round(t * (512 - 45));
    const d = win.data;
    if (d.dn === x) return;
    d.dn = x;
    win.control('pan_timebar1').setRect(x, 0, 512, 45);
    win.control('pan_timebar2').setRect(x + 512, 0, 512, 45);
    const night = t < 0.25 || t > 0.75;
    win.control('pan_time_sun').setVisible(!night);
    win.control('pan_time_moon').setVisible(night);
  }
}

// ============================================================================================ big map (M)
const LS_FAV = 'dekaron-solo:mapfav:v1';
let monsterPositions = null;
function loadMonsterPositions() {
  monsterPositions ||= fetchCSVObjects('script/minimap/minimap_monsterposition.csv').catch(() => []);
  return monsterPositions;
}

// Native monster-position rows describe habitats, never live attack targets.
export function mapMonsterPoints(row, map) {
  if (!row || Number(row.Map_Index) !== Number(map)) return [];
  const points = [];
  for (let k = 1; k <= 3; k++) {
    const x = Number(row['PositionX_' + k]), z = Number(row['PositionY_' + k]);
    if (Number.isFinite(x) && Number.isFinite(z) && x >= 0 && z >= 0 && (x > 0 || z > 0)) points.push({ x, z });
  }
  return points;
}
// Map list Move. Global: NPC Warp (teleport to the NPC, 101:171) is a Holy Water of Almighty service (premiereitem.csv NpcWarp,
// 101:187 "Able to use NPC Warp"); with it Move warps (the server checks the service again, shops/premium-rules.js). Without it
// Move walks to the NPC like a click on the map (ENGINE-CHOSEN: Move works for every player; Global's own
// map auto-walk is a mount option).
export function walkMapNpc(game, npc) {
  if (!npc || !(game.npcs || []).includes(npc) || npc.disposed || Number(npcDef(game, npc).mapVisible) === 0) return false;
  if (game.premium?.any?.('npcWarp') && game.sharedTravel?.mapNpcWarp) return game.sharedTravel.mapNpcWarp(npcDef(game, npc).index, npcNameTitle(game, npc).name) || false;
  if (!game.controller?.moveTo) return false;
  game.controller.moveTo(npc.x, npc.z);
  return true;
}

// Native Map list scroll shells span the list; only the visible scrollbar strip is a hit region.
export function mapScrollHitInset(scroll) {
  const parts = [scroll?.up, scroll?.down, scroll?.bar].filter(c => c?.box?.w > 0);
  if (!parts.length || !(scroll?.box?.w > 0)) return null;
  const left = Math.max(0, Math.min(...parts.map(c => c.box.x)));
  const right = Math.min(scroll.box.w, Math.max(...parts.map(c => c.box.x + c.box.w)));
  if (!(right > left)) return null;
  return `inset(0px ${Math.max(0, scroll.box.w - right)}px 0px ${left}px)`;
}

export function registerWorldMap(game, ctx) {
  game.uiwin.registerWindow('map', {
    script: 'game2/ui_new_mapwnd.txt',
    create(win) {
      const d = win.data;
      d.tab = 'npc';
      d.favs = new Set(LS.load(LS_FAV, []));
      d.body = win.control('pan_body');
      d.map = win.control('pan_map');
      d.layer = document.createElement('div');
      d.layer.style.cssText = 'position:absolute;left:0;top:0;width:512px;height:512px;pointer-events:none';
      d.map.el.appendChild(d.layer);
      d.rings = [];
      const tabs = { btn_npclist: 'list_npclist', btn_monsterposition: 'list_monsterpositionlist', btn_teleportlist: 'list_teleportlist', btn_responlist: 'list_responlist' };
      const show = (btn) => {
        d.tab = btn;
        for (const [b, l] of Object.entries(tabs)) { win.control(b).setChecked(b === btn); win.control(l).setVisible(b === btn); }
        paintFavButtons();
      };
      for (const b of Object.keys(tabs)) win.control(b).onClick(() => show(b));
      // Premium Service (Growth Blessing / Holy Water of Almighty; tooltip 25/50 "Premium service that is enabled through
      // Growth Blessing and Holy Water of Almighty"): the button flips the right-hand lists between NPC / Monster and
      // Select Warp / Return Point, and only works while a premium teleport or return service is running.
      const bless = win.control('btn_bless');
      const premiumOn = () => !!(game.premium?.any?.('teleport') || game.premium?.any?.('respon'));
      const showPremium = (on) => {
        d.premium = on;
        bless.setChecked(on);
        win.control('btn_npclist').setVisible(!on); win.control('btn_monsterposition').setVisible(!on);
        win.control('btn_teleportlist').setVisible(on && !!game.premium?.any?.('teleport')); win.control('btn_responlist').setVisible(on && !!game.premium?.any?.('respon'));
        show(on ? (game.premium?.any?.('teleport') ? 'btn_teleportlist' : 'btn_responlist') : 'btn_npclist');
      };
      d.showPremium = showPremium; d.premiumOn = premiumOn;
      bless.onClick(() => {
        if (!d.premium && !premiumOn()) { bless.setChecked(false); ctx.chat?.system(str(25, 50) || 'Premium service that is enabled through Growth Blessing and Holy Water of Almighty.'); return; }
        showPremium(!d.premium);
      });
      // transparency
      const sld = win.control('sld_alpha');
      sld.setRange(30, 100);
      const setAlpha = (v) => { ctx.options.set({ mapAlpha: v }); win.el.style.opacity = String(clamp(v, 30, 100) / 100); };
      sld.on('change', v => setAlpha(Math.round(v)));
      win.control('btn_minus').onClick(() => { sld.setValue(sld.getValue() - 5); setAlpha(sld.getValue()); });
      win.control('btn_plus').onClick(() => { sld.setValue(sld.getValue() + 5); setAlpha(sld.getValue()); });
      d.setAlpha = setAlpha; d.sld = sld;
      // lists
      const npcList = win.control('list_npclist');
      npcList.el.classList.add('uw-map-npc-list');
      // No backdrop of its own: Global's listbox has no image, the panel art behind it is pan_bg (bigmap #1).
      npcList.on('select', (i, it) => selectNpc(it?.data));
      npcList.on('dblclick', () => moveToNpc());
      // Keep the event badge and ordinary NPC actions on their own row as it scrolls.
      // Premium teleport remains in the Select Warp list.
      const gmTp = () => !!game.gm?._ctrlTeleport && hasGMPanelPermission(game);
      const ordinaryNpc = it => !!it?.data && !it.data.placement?.isEvent;
      npcList.rowActions = [
        { badge: true, label: 'EVENT', sprite: ['bigmap', 84], show: (i, it) => !!it?.data?.placement?.isEvent },
        { label: 'Add', show: (i, it) => ordinaryNpc(it) && !isFav(it.data), onClick: (i, it) => setFav(it.data, true) },
        { label: 'Del', show: (i, it) => ordinaryNpc(it) && isFav(it.data), onClick: (i, it) => setFav(it.data, false) },
        { label: 'Move', show: (i, it) => ordinaryNpc(it), onClick: () => moveToNpc() },
      ];
      win.control('btn_npc_move').onClick(() => moveToNpc());
      win.control('btn_npc_add_favorite').onClick(() => { if (d.selNpc) setFav(d.selNpc, true); });
      // ui_new_mapwnd.txt: Add favorite (2000/96) and Del favorite (2000/97) share one rect and swap with the selected
      // NPC's favorite state; btn_event_npc (bigmap #84, disabled) takes that rect for an event-placed NPC.
      win.control('btn_npc_del_favorite').onClick(() => { if (d.selNpc) setFav(d.selNpc, false); });
      const monList = win.control('list_monsterpositionlist');
      monList.on('select', (i, it) => showMonster(it?.data));
      // Select Warp / Return Point (premium service): the row is selected with a click and used with a double click; the
      // warp cast and the return point are the premium service's (server-owned online, see systems/shops/premium.js)
      const tpList = win.control('list_teleportlist');
      tpList.on('dblclick', () => { const it = tpList.items[tpList.getSelected()]; if (it?.data) teleport(it.data); });
      tpList.on('select', (i, it) => { d.selTp = it?.data; });
      const retList = win.control('list_responlist');
      retList.on('dblclick', () => { const it = retList.items[retList.getSelected()]; if (it?.data) setReturn(it.data); });
      retList.on('select', (i, it) => { d.selRet = it?.data; });
      // click on the map walks there - ADMIN / GM accounts (and only those) teleport there instead, no Ctrl and no GM panel needed;
      // hovering an NPC mark shows its name balloon, clicking one selects that NPC (Global fixed Move / EVENT controls act on it)
      d.map.el.classList.add('uw-hit');
      d.map.on('click', (e) => {
        const r = d.map.el.getBoundingClientRect(), sc = game.uiwin.scale;
        const u = (e.clientX - r.left) / sc, v = (e.clientY - r.top) / sc;
        const w = fromTex(u, v);
        const hit = nearestNpcMark(u, v);
        if (hit) { selectNpc(hit); return; }
        if (gmTp()) { game.gm._ctrlTeleport(w.x, w.z); return; }   // the GM route snaps to walkable ground and checks the capability on the server
        game.controller?.moveTo?.(w.x, w.z);
      });
      d.map.el.addEventListener('pointermove', (e) => {
        const r = d.map.el.getBoundingClientRect(), sc = game.uiwin.scale;
        const u = (e.clientX - r.left) / sc, v = (e.clientY - r.top) / sc;
        const hit = nearestNpcMark(u, v);
        balloon(hit ? npcNameTitle(game, hit).name : null, hit);
      });
      d.map.el.addEventListener('pointerleave', () => balloon(null));

      // One favorite per placed NPC: several placements share one NPC index (portals, dungeon entrances, event shrines
      // listed by their placement names), so the key carries the placement cell. A saved map:index key from before still
      // matches when that index is placed once on the map.
      function favKey(n) { return `${game.world?.info?.index}:${npcDef(game, n).index}:${Math.round(n.x)}:${Math.round(n.z)}`; }
      function legacyKey(n) { return `${game.world?.info?.index}:${npcDef(game, n).index}`; }
      function isFav(n) {
        if (d.favs.has(favKey(n))) return true;
        if (!d.favs.has(legacyKey(n))) return false;
        const index = npcDef(game, n).index;
        return (game.npcs || []).filter(o => npcDef(game, o).index === index).length === 1;
      }
      function setFav(n, on) {
        d.favs.delete(legacyKey(n));
        if (on) d.favs.add(favKey(n)); else d.favs.delete(favKey(n));
        // Re-select by identity after favorite sorting; the old row index may now name a different NPC.
        LS.save(LS_FAV, [...d.favs]); fillNpcs(); selectNpc(n);
      }
      function paintFavButtons() {
        // Fixed-position controls overlap the first list rows; row actions replace them.
        for (const id of ['btn_npc_move','btn_event_npc','btn_npc_add_favorite','btn_npc_del_favorite'])
          win.control(id).setVisible(false).setEnabled(false);
        npcList.render?.();
      }
      function selectNpc(n) {
        d.selNpc = n || null;
        const m = win.control('pan_selectednpc'), fx = win.control('pan_selectednpc_effect');
        if (n) {
          const T = toTex(n.x, n.z);
          m.setVisible(true); m.setRect(Math.round(T.u - 6), Math.round(T.v - 14), 12, 14);
          fx.setVisible(true); fx.setRect(Math.round(T.u - 6), Math.round(T.v - 14), 12, 14);
          const i = npcList.items.findIndex(it => it.data === n);
          if (i >= 0 && npcList.getSelected() !== i) npcList.select(i);
          d.pulseT = 0; fx.el.style.opacity = '0';   // the glow starts dark and lights up (update: NPC_PULSE_S)
        } else {
          m.setVisible(false); fx.setVisible(false);
          // 2.2.1: the map opens with NO NPC selected - setItems keeps the old row index, so the last NPC stayed highlighted
          if (npcList.getSelected() !== -1) npcList.select(-1);
        }
        paintFavButtons();
      }
      function moveToNpc() {
        const n = d.selNpc; if (!n) return;
        const ok = walkMapNpc(game, n);
        if (ok === false) ctx.chat?.system(str(40, 73));
        win.close('move');
      }
      function nearestNpcMark(u, v) {
        let best = null, bd = 7;
        for (const n of game.npcs || []) {
          if (Number(npcDef(game, n).mapVisible) === 0) continue;
          const T = toTex(n.x, n.z);
          const dd = Math.hypot(T.u - u, T.v - v);
          if (dd < bd) { bd = dd; best = n; }
        }
        return best;
      }
      function balloon(text, n) {
        const tip = win.control('pan_new_tooltip');
        if (!text) { tip.setVisible(false); return; }
        const T = toTex(n.x, n.z);
        const w = Math.max(40, Math.min(250, text.length * 6 + 14));
        tip.setVisible(true);
        tip.setRect(Math.round(T.u - 12), Math.round(T.v - 42), w + 27, 37);
        win.control('lbl_new_tooltip').setText(text);
        win.control('pan_new_tooltip_mid').setRect(17, 8, w - 4, 21);
        win.control('pan_new_tooltip_right').setRect(w + 13, 8, 6, 21);
        win.control('pan_new_tooltip_downtag').setVisible(true);
      }
      async function showMonster(row) {
        for (const r of d.rings) r.remove();
        d.rings = [];
        if (!row) return;
        for (const {x, z} of mapMonsterPoints(row, game.world?.info?.index)) {
          const T = toTex(x, z);
          const el = document.createElement('div');
          el.className = 'uw-icon uw-hit';
          el.style.pointerEvents = 'auto';
          el.style.cursor = 'pointer';
          el.setAttribute('role', 'button');
          el.setAttribute('aria-label', row.Monster_Name || 'Monster habitat');
          el.tabIndex = 0;
          const locate = () => { if (Number(row.Map_Index) !== game.world?.info?.index) return; const i = monList.items.findIndex(it => it.data === row); if (i >= 0) monList.select(i); };
          // Keep the map control from capturing this gesture as a background walk.
          el.addEventListener('pointerdown', ev => ev.stopPropagation());
          el.addEventListener('pointerup', ev => ev.stopPropagation());
          el.addEventListener('click', ev => { ev.stopPropagation(); locate(); });
          el.addEventListener('keydown', ev => { if (ev.key === 'Enter' || ev.key === ' ') { ev.preventDefault(); ev.stopPropagation(); locate(); } });
          el.title = row.Monster_Name || 'Monster habitat';
          el.style.cssText += `;width:64px;height:64px;left:${Math.round(T.u - 32)}px;top:${Math.round(T.v - 32)}px`;
          d.layer.appendChild(el);
          d.rings.push(el);
        }
        d.ringT = 0;
      }
      async function fillNpcs() {
    const list = [];
    for (const n of game.npcs || []) {
      if (Number(npcDef(game, n).mapVisible) === 0) continue;
      const { name, title } = npcNameTitle(game, n);
      if (!name) continue;
      const event = !!n.placement?.isEvent;
      list.push({ n, name, title, fav: isFav(n), event });
    }
    // C5 SCREENSHOT-SOURCED: event NPCs first in #FFFF00, then favorites, then A-Z
    list.sort((a, b) => (b.event - a.event) || (b.fav - a.fav) || a.name.localeCompare(b.name));
    npcList.setItems(list.map(it => ({
      text: `${it.fav ? '★ ' : ''}${it.name}${it.title ? ` ${it.title}` : ''}`,
      data: it.n,
      color: it.event ? 'ffffff00' : (it.fav ? 'ffffd200' : null),
    })));
  }
  async function fillMonsters() {
        const map = game.world?.info?.index;
        const rows = (await loadMonsterPositions()).filter(r => Number(r.Map_Index) === map);
        if (game.world?.info?.index !== map) return;
        monList.setItems(rows.map(r => {
          const def = game.data?.monster?.(Number(r.Monster_Index)) || game.data?.monsters?.monsters?.[r.Monster_Index];
          const lv = def?.level ?? def?.Level;
          return { text: `${lv != null ? `Lv.${lv} ` : ''}${def?.name || r.Monster_Name}`, data: r };
        }));
      }
      // The two lists carry only what the running premium service allows (share/premiere/teleport.csv / respon.csv,
      // level-filtered): Select Warp needs the Teleport service, Return Point the Respon service.
      function fillTeleports() {
        const prem = game.premium;
        const tps = prem?.any?.('teleport') ? prem.teleportList() : [];
        tpList.setItems(tps.map(t => ({ text: t.name, data: { location: t.location, premium: t } })));
        const cur = prem?.returnPointId?.();
        const rets = prem?.any?.('respon') ? prem.responList() : [];
        retList.setItems(rets.map(t => ({ text: t.name, color: cur === t.location ? 'ffffd200' : null, data: { location: t.location, premium: t } })));
        d.selTp = null; d.selRet = null;
        // the service may have started or ended while the window is open
        if (d.premium && !premiumOn()) showPremium(false);
      }
      async function teleport(u) {
        const t = u?.premium;
        if (!t || !game.premium) return;
        const ok = await game.premium.warpTo(t);
        if (ok) win.close('teleport');
      }
      async function setReturn(p) {
        const t = p?.premium;
        if (!t || !game.premium) return;
        if (await game.premium.setReturnPoint(t)) fillTeleports();
      }
      d.fillPremium = fillTeleports;
      d.fill = () => { fillNpcs(); fillMonsters(); fillTeleports(); selectNpc(null); showMonster(null); };
      d.show = show;
      d.selectNpc = selectNpc;
    },
    // 2.2.1 (Global): the NPC selection is not kept after closing the map (onOpen clears it again for a window that is
    // opened by any other route)
    onClose(win) {
      const d = win.data;
      if (d.selNpc) d.selectNpc?.(null);
    },
    onOpen(win) {
      const d = win.data, g = game;
      // every list's scroll shell spans the list: only the scrollbar strip may take pointer input (the Select Warp and
      // Return Point lists were covered by their shell, so no row could be selected)
      for (const id of ['list_npclist', 'list_monsterpositionlist', 'list_teleportlist', 'list_responlist']) {
        const scroll = win.control(id).scroll, inset = mapScrollHitInset(scroll);
        if (inset) scroll.el.style.clipPath = inset;
      }
      const idx = g.world?.info?.index;
      const row = g.mapRow?.(idx) || g.data?.mapByIndex?.(idx);
      win.control('lbl_mapName').setText(row?.Name || g.world?.info?.name || '');
      d.map.setImage('none', 'minimap', idx);
      d.premium = !!d.premium && d.premiumOn();
      d.fill();
      d.sld.setValue(Number(ctx.options.get('mapAlpha')) || 100);
      d.setAlpha(d.sld.getValue());
      d.showPremium(d.premium);
    },
    update(win, dt) {
      const d = win.data, p = game.player;
      drawWorldMapParty(game,d,{paintIcon,toTex});
      if (!p) return;
      // 2.2.1 (Global): the selected NPC's mark lights up in a slow pulse - bigmap #60 (pan_selectednpc_effect, the gold /
      // red glow in ui_new_mapwnd.txt) over bigmap #59. The script has no timing; Global pulses on a 4-6 s cycle.
      if (d.selNpc) {
        d.pulseT = ((d.pulseT || 0) + dt) % NPC_PULSE_S;
        win.control('pan_selectednpc_effect').el.style.opacity = (0.5 - 0.5 * Math.cos(d.pulseT / NPC_PULSE_S * Math.PI * 2)).toFixed(3);
      }
      const P = toTex(p.x, p.z);
      const arrow = win.control('pan_pointArrow');
      arrow.setRect(Math.round(P.u - 7), Math.round(P.v - 10), 14, 21);
      arrow.el.style.transform = `rotate(${texAngle(-Math.sin(p.yaw || 0), -Math.cos(p.yaw || 0)).toFixed(3)}rad)`;
      const cam = win.control('pan_pointCamera');
      cam.setRect(Math.round(P.u - 31), Math.round(P.v - 31), 62, 62);
      if (game.camera?.getWorldDirection) { const v = game.camera.getWorldDirection(ctx.tmpV); cam.el.style.transform = `rotate(${texAngle(v.x, -v.z).toFixed(3)}rad)`; }
      // NPC marks
      d.t = (d.t || 0) - dt;
      if (d.t <= 0) {
        d.t = 0.5;
        d.npcEls ||= new Map();
        const seen = new Set();
        for (const n of game.npcs || []) {
          const def = npcDef(game, n);
          if (Number(def.mapVisible) === 0) continue;
          let el = d.npcEls.get(n);
          if (!el) { el = document.createElement('div'); el.className = 'uw-icon'; el.style.width = el.style.height = '10px'; paintIcon(el, { sprite: ['mainbar_minimap', 120 + (Number(def.minimapColor) || 0)] }); d.layer.appendChild(el); d.npcEls.set(n, el); }
          const T = toTex(n.x, n.z);
          el.style.left = `${Math.round(T.u - 5)}px`; el.style.top = `${Math.round(T.v - 5)}px`;
          seen.add(n);
        }
        for (const [n, el] of d.npcEls) if (!seen.has(n)) { el.remove(); d.npcEls.delete(n); }
      }
      // monster position rings pulse through bigmap #83..#79
      if (d.rings.length) {
        d.ringT = (d.ringT || 0) + dt;
        const f = 83 - (Math.floor(d.ringT * 10) % 5);
        if (d.ringF !== f) { d.ringF = f; for (const el of d.rings) paintIcon(el, { sprite: ['bigmap', f] }); }
      }
    },
  });
}
