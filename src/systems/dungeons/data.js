// Dungeon / travel tables (gamedata/dungeons.json + dungeons_travel.json, docs/formats/dungeons.md) and the text
// helpers every part of the dungeon system shares. Loaded once, lazily (5.9 MB + 0.2 MB).
import { fetchJSON } from '../../engine/assets.js';
import { ABSENT_MAPLIST_MAPS } from '../../world/legacy-maps.js';

export const DUNGEONS_URL = '/gamedata/dungeons.json';
export const TRAVEL_URL = '/gamedata/dungeons_travel.json';

let _p = null;
export const D = { dg: null, tr: null, byMap: new Map(), ready: false };

/** Load both tables once. Resolves D ({dg, tr, byMap: map -> {id, dungeon, floor}}). */
export function loadData() {
  if (!_p) {
    const p = Promise.all([fetchJSON(DUNGEONS_URL), fetchJSON(TRAVEL_URL)]).then(([dg, tr]) => {
      D.dg = dg; D.tr = tr;
      enrichAbsentMaplistDungeonMaps(D.dg, D.tr);
      D.byMap = new Map();
      for (const [id, dn] of Object.entries(dg.dungeons || {})) {
        (dn.floors || []).forEach((m, i) => {
          // a map can be floor 0 of its own dungeon and floor k of another (Nepturos's Lair 235 = floor 1 of 234):
          // keep the dungeon it starts (floor 0) unless nothing else is known
          const prev = D.byMap.get(Number(m));
          if (!prev || (prev.floor > 0 && i === 0)) D.byMap.set(Number(m), { id, dungeon: dn, floor: i });
        });
      }
      D.ready = true;
      return D;
    }).catch(err => { if (_p === p) _p = null; throw err; });
    _p = p;
  }
  return _p;
}


/**
 * Maplist-hole dungeon floors Global still ships (ABSENT_MAPLIST_MAPS, Lane 25): terrain and the share/map folder
 * exist, but share/maplist.csv has no row, so the Global pack keeps maps[i] as kind:orphan (files.folder only) and
 * dungeon.missingFloors. The wiring lives here in 4.2.0 code; the Global pack is never edited (Lane 52):
 * - files from the Lane 25 stem (120 -> under_crespo_indun);
 * - title / mission / time limit / missions from the floor's own Global message table, by the same rule
 *   tools/build-dungeons.mjs uses for maplist floors (codes 1, 2, 3, 10..29);
 * - the start point by the builder's rule: the first share/arrange/location.csv row of the map
 *   (120: location 11400). Its walk/snap is the builder's value for the identical cell of the same .mac.
 * Bricks, script NPCs and zone warps are Global and already in the pack (scan-fix 2026-10-29 re-check): 120 carries
 * brick_120_under_crespo_indun.csv (19 bricks: Starting Point / Boss Visit / Starting Point Removal created, 16 boss-room
 * walls IsCreate 0), npc_120_under_crespo_indun.csv (16 NPCs: 11 Warp Stones, Reezena, 2 Shield Stones, 2 Shield Protection
 * Stones) and warp.csv zone warps 11401..11411 with locations 11400..11411. No monsters are added: Global ships no
 * callmonster_120 / scriptmonster for 120 and ScriptProcess.dll has no Map_120 class (searched: Global share/map, share/
 * dungeon, share/arrange, packed data; 32/64-bit decompiles; server-ref; LANE-65). The floor is left as it is, not
 * filled from 121's waves.
 */
const DURATION_RE = /(\d+(?:\.\d+)?)\s*(hours?|hrs?|h\b|minutes?|mins?|m\b|seconds?|secs?|s\b|\uC2DC\uAC04|\uBD84|\uCD08)/gi;
function durationSec(text) {
  let sec = 0, found = false, m;
  DURATION_RE.lastIndex = 0;
  while ((m = DURATION_RE.exec(String(text ?? '')))) {
    const v = Number(m[1]), u = m[2].toLowerCase();
    sec += (u.startsWith('h') || u === '\uC2DC\uAC04') ? v * 3600 : (u.startsWith('m') || u === '\uBD84') ? v * 60 : v;
    found = true;
  }
  return found ? sec : null;
}

export function enrichAbsentMaplistDungeonMaps(dg, tr = null) {
  if (!dg?.maps || !dg?.dungeons) return dg;
  for (const [idStr, L] of Object.entries(ABSENT_MAPLIST_MAPS || {})) {
    const id = Number(idStr);
    const m = dg.maps[String(id)];
    if (!m) continue;
    if (!m.files?.map) {
      const folder = Array.isArray(m.files?.folder) ? m.files.folder : [];
      const dir = L.dir;
      const stem = L.file;
      const mal = folder.find(f => /\.mal$/i.test(f)) || `share/map/${dir}/m${String(id).padStart(3, '0')}.mal`;
      const npcs = folder.find(f => /npc_/i.test(f)) || `share/map/${dir}/npc_${dir}.csv`;
      const bricks = folder.find(f => /brick_/i.test(f)) || `share/map/${dir}/brick_${dir}.csv`;
      m.files = {
        ...(m.files || {}),
        map: `map/${stem}.map`,
        mol: `map/${stem}.mol`,
        mel: `map/${stem}.mel`,
        mac: `share/mapredcell/${stem}.mac`,
        mal, npcs, bricks,
        levelCap: m.files?.levelCap || `share/pc/levelcap/levelcap_${stem}.csv`,
        folder,
      };
      if (m.kind === 'orphan') {
        m.kind = 'instance';
        m.note = (m.note ? m.note + ' | ' : '') + 'ABSENT_MAPLIST wired in 4.2.0 code (Lane 25 / Lane 52): maplist hole but terrain+folder present';
      }
    }
    const T = m.messages || {};
    if (m.title == null && T[1]?.t && T[2]?.t && (T[3] || T[30])) {
      m.title = T[1].t;
      m.mission = T[2].t;
      if (T[3]?.t) m.timeLimit = { text: T[3].t, sec: durationSec(T[3].t) };
      const missions = Object.keys(T).map(Number).filter(c => c >= 10 && c < 30 && T[c]?.t).sort((a, b) => a - b)
        .map(c => ({ code: c, text: T[c].t, note: T[c].c || undefined }));
      if (missions.length && !m.missions) m.missions = missions;
    }
    if (!m.spawn) {
      const locs = tr?.locations || {};
      const li = (m.locations || []).find(i => Number(locs[String(i)]?.[0]) === id);
      const l = li != null ? locs[String(li)] : null;
      if (l) {
        const s = { src: `location ${li}`, x: Number(l[1]), y: Number(l[2]), dir: Number(l[3]) || 0 };
        const twin = Object.values(dg.maps).find(o => o !== m && o.files?.mac && o.files.mac === m.files?.mac
          && o.spawn && o.spawn.x === s.x && o.spawn.y === s.y && o.spawn.walk != null);
        if (twin) { s.walk = twin.spawn.walk; if (twin.spawn.snap) s.snap = [...twin.spawn.snap]; }
        m.spawn = s;
      }
    }
    for (const d of Object.values(dg.dungeons)) {
      if (!d?.missingFloors?.length) continue;
      if (!d.missingFloors.some(fm => Number(fm) === id)) continue;
      const left = d.missingFloors.filter(fm => Number(fm) !== id);
      if (left.length) d.missingFloors = left;
      else delete d.missingFloors;
    }
  }
  return dg;
}

export const mapInfo = (m) => D.dg?.maps?.[String(m)] || null;
export const dungeonById = (id) => D.dg?.dungeons?.[String(id)] || null;
export const brickDef = (i) => D.dg?.bricks?.[String(i)] || null;
export const triggerDef = (i) => D.dg?.triggers?.[String(i)] || null;
export const sysTextRaw = (code) => D.dg?.systemText?.[String(code)] ?? '';
export const location = (i) => D.tr?.locations?.[String(i)] || null;

/**
 * Where a floor starts (FILE frame {x, z, dirDeg}): the builder's spawn when it is a named location / respawn point;
 * when it only fell back to an NPC warp point (upper Tower floors pick the next-floor stairs), the floor's
 * 'start' NPC (the lever next to the entrance) is where the party arrives.
 *
 * The builder marks a candidate with walk -1 and no snap when the original .mac grid has no walkable cell within its
 * 16-cell snap (Karon's Fragment (Normal) 121: location 11416 is the source cell of zone warp 11416; Nepturos's Lair
 * 235: exit NPC 6047's warp (354,512) is outside the 512-cell map; Sacred Claw 248: exit NPC 5322's warp (61,113) is
 * sibling map 184's). The host then refused entry ("No safe dungeon floor start is available."). Such a floor
 * uses only the documented native121 zone-warp destination or the precise same-floor235/248 manager placement.
 * An arbitrary walkable alternative/exit does not establish original entrance provenance. The manager placements
 * are supported staging corrections; exact installed Global arrival acceptance remains separate.
 */
export function startPos(map) {
  const i = mapInfo(map);
  if (!i) return null;
  const s = i.spawn;
  // Dungeon floors 2026-10-29: 544 [Meister]Desacato. Global's spawn link 11731 is the exit warp 544->533 beside the
  // end Reezena 5474 (behind all 4 gates, in Enigma's room); the run begins at Reezena 5473 (Global 5001 'Talk to
  // Reezena to start instantly.'). Enter beside 5473 - ENGINE-DEFAULT (configurable).
  if (Number(map) === 544 && s?.src === 'location 11731') {
    const beg = (i.scriptNpcs || []).find(n => Number(n.npc) === 5473);
    if (beg) return { x: Math.floor(beg.x) + 0.5, z: Math.floor(beg.y) - 1.5, dirDeg: 0 };
  }
  if (!s || /^npc\b/i.test(s.src || '')) {
    const st = (i.scriptNpcs || []).find(n => n.role === 'start');
    if (st) { const [x, y] = st.warp || [st.x, st.y]; return { x: Math.floor(x) + 0.5, z: Math.floor(y) + 0.5, dirDeg: st.dir || 0 }; }
  }
  if (s && s.walk === -1 && !s.snap) {
    const paired = Number(map) === 121 && s.src === 'location 11416'
      && D.tr?.warps?.some(w => w.id === 11416 && w.from === 11416 && w.to === 11417
        && w.fromMap === 121 && w.toMap === 121 && w.dungeon === 1 && w.kind === 'zone');
    const alt = paired && (i.spawnAlt || []).find(a => a.src === 'location 11417' && a.walk != null && (a.walk !== -1 || a.snap));
    if (alt) { const [x, z] = alt.snap || [alt.x + 0.5, alt.y + 0.5]; return { x, z, dirDeg: alt.dir || 0 }; }
    const manager = Number(map) === 235 && s.src === 'exit npc 6047' && s.x === 354 && s.y === 512 ? [6047,502]
      : Number(map) === 248 && s.src === 'exit npc 5322' && s.x === 61 && s.y === 113 ? [5322,10008] : null;
    const exit = manager && (i.scriptNpcs || []).find(n => n.npc === manager[0] && n.role === 'exit'
      && n.job?.[0] === 31 && n.job?.[1] === manager[1] && (n.x > 1 || n.y > 1));
    if (exit) return { x: Math.floor(exit.x) + 0.5, z: Math.floor(exit.y) + 0.5, dirDeg: exit.dir || 0 };
  }
  if (s) { const [x, z] = s.snap || [s.x + 0.5, s.y + 0.5]; return { x, z, dirDeg: s.dir || 0 }; }
  return null;
}

/** {id, dungeon, floor} of the dungeon a map belongs to, or null. */
export function dungeonOfMap(map) { return D.byMap.get(Number(map)) || null; }

/** Keeper types that belong to other systems (events: Dead Front, Ice Castle, colosseum...). */
export const FOREIGN_KEEPERS = new Set(['EVENT', 'COLOSSEUM']);

// ------------------------------------------------------------------------------------------ text
/** printf fill (%s %d %u %02d) of a client string. */
export function fmt(s, ...args) {
  let i = 0;
  return String(s ?? '').replace(/%(%|[-+ 0#]*\d*(?:\.\d+)?[dsuif])/g, (m, spec) => {
    if (spec === '%') return '%';
    const v = args[i++];
    if (v == null) return m;
    if (/[du]$/.test(spec)) {
      const n = Math.trunc(Number(v)) || 0;
      const w = /^0(\d+)/.exec(spec);
      return w ? String(n).padStart(Number(w[1]), '0') : String(n);
    }
    const f = /\.(\d+)f/.exec(spec);
    if (f) return Number(v).toFixed(Number(f[1]));
    return String(v);
  });
}

/** Generic dungeon system text (string cate 2004), printf-filled. */
export function sysText(code, ...args) { return fmt(sysTextRaw(code), ...args); }

/** Remove client markup (for the chat log / plain labels). */
export function plain(t) {
  return String(t ?? '')
    .replace(/<\/?color[^>]*>/gi, '').replace(/<\/?font[^>]*>/gi, '').replace(/<center>/gi, '')
    .replace(/<#[0-9a-f]{6}>/gi, '').replace(/<guage[^>]*>/gi, '').replace(/<dlgdata[^>]*\/>/gi, '')
    .replace(/@<[^>]+>[^\s]*/g, '').trim();
}

/**
 * Message `code` of a map category: {t, c, fx, m, s, sent} or null. The engine fills the server slots:
 * <MAPNAME>, <MAP_COUNT_N> (vars.count), <dlgdata o=N/> (vars.floor / vars.value).
 */
export function message(map, code) {
  const m = mapInfo(map);
  return m?.messages?.[String(code)] || null;
}

export function fillSlots(text, vars = {}) {
  return String(text ?? '')
    .replace(/<MAPNAME>/g, vars.mapName ?? '')
    .replace(/<MAP_COUNT_\d+>/g, () => String(vars.count ?? 0))
    .replace(/<dlgdata\s+o\s*=\s*(\d+)\s*\/>/gi, (m, o) => String(vars.dlg?.[Number(o)] ?? vars.floor ?? ''))
    .replace(/<LEVEL>/g, String(vars.level ?? ''))
    .replace(/<COST>/g, String(vars.cost ?? ''))
    .replace(/<NAME>/g, String(vars.name ?? ''));
}

/** Text of a message code with slots filled (markup kept for rich controls). */
export function messageText(map, code, vars) {
  const msg = message(map, code);
  if (!msg || msg.t == null) return '';
  return fillSlots(msg.t, vars);
}

/** Directives of a message: {ui:[{ui, ms}], sfx:[[cate,id,vol,x]], sound:[[0|1,id]], gauge:{ms,text,sound}|null}. */
export function messageFx(map, code) {
  const msg = message(map, code);
  const out = { ui: [], sfx: [], sound: [], gauge: null };
  for (const f of msg?.fx || []) {
    if (f.ui != null) out.ui.push({ ui: Number(f.ui), ms: Number(f.ms) || 3000, args: f.args || [] });
    else if (f.sfx) out.sfx.push(f.sfx);
    else if (f.gauge) out.gauge = { ms: Number(f.ms) || 1000, text: f.text || '', sound: f.sound || null };
    else if (f.sound) out.sound.push(f.sound);
  }
  return out;
}

/** "%s %02dMin%02dSec" (system text 99) for a caption and seconds. */
export function timeText(caption, sec) {
  sec = Math.max(0, Math.ceil(Number(sec) || 0));
  return sysText(99, caption, Math.floor(sec / 60), sec % 60);
}

/** Monster display name from monsters.json. */
export function monsterName(game, idx) {
  const m = game?.data?.monster ? game.data.monster(Number(idx)) : game?.data?.monsters?.monsters?.[idx];
  return m?.name || `#${idx}`;
}

/** Deterministic PRNG (mulberry32) for scatter positions. */
export function rng(seed = 1) {
  let a = seed >>> 0;
  return () => { a = (a + 0x6D2B79F5) >>> 0; let t = a; t = Math.imul(t ^ (t >>> 15), t | 1); t ^= t + Math.imul(t ^ (t >>> 7), t | 61); return ((t ^ (t >>> 14)) >>> 0) / 4294967296; };
}
