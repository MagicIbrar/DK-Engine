// Walk-in warp zones: the map-to-map gates of the original (share/arrange/warp.csv rows with a trigger rectangle,
// pre-built into gamedata/dungeons_travel.json `warps`, docs/formats/dungeons.md §Travel "Walk-in zones").
//
//   warps[] { id, from, to, rect:[w,h], kind:'zone'|'scripted'|'disabled', siege, dungeon, fromMap, toMap,
//             box:[x0, y0, x1, y1] (cells, FILE frame; from-location = min corner) }
//   locations[id] = [map, x, y, dirDeg, name]  (integer cells: stand at x + 0.5, y + 0.5)
//
// Walking into a zone of the current map loads the destination map at the to-location (e.g. Ardeca (35..39, 460..464)
// -> Deneb, Ardeca (487..489, 213..215) -> Braiken Castle Underground Prison). Only kind 'zone' rows fire here;
// 'scripted' warps belong to NPC / map scripts and siege gates (siege = 1) to the siege system. A zone arms only
// after the player has stood outside every zone once since arriving, so an arrival point that happens to lie inside
// the destination's own gate never bounces the player back. maplist LimitMinLevel / LimitMaxLevel are enforced with
// the client's own message.
//
// Another system (e.g. a full dungeon / travel system) can take this over with game.warpZones.enabled = false.
import { fetchJSON } from '../../engine/assets.js';
import { prefetchMapAssets, hasMapManifest } from '../../engine/prefetch.js';
import { PREFETCH } from '../../config/engine-chosen-loading.js';
import { atlas } from '../../ui/atlas.js';

const CHECK_INTERVAL = 0.1;          // s between zone tests
const MSG_LOW = 'Your level is too low to enter.';           // script/string/dungeon/stringtable_dungeon_03.txt
const MSG_HIGH = 'You are not in the right level to enter.'; // script/string/dungeon/stringtable_dungeon_06.txt

let travel = null;       // dungeons_travel.json
let byMap = new Map();   // map -> [{ id, x0, z0, x1, z1, to:{map,x,z,dirDeg,name} }]
let state = { map: -1, armed: false, t: 0, blockedZone: null };

export async function install(game) {
  game.warpZones = { enabled: true, zonesOn: map => byMap.get(Number(map)) || [], zoneAt };
  try { travel = await fetchJSON('/gamedata/dungeons_travel.json'); } catch (err) { console.warn('[warpzones] no dungeons_travel.json', err); return; }
  const L = travel.locations || {};
  byMap = new Map();
  for (const w of travel.warps || []) {
    // In a shared dungeon the same-map zones need an authenticated portal
    // action. Field gates retain their ordinary travel route.
    if (w.kind !== 'zone' || w.siege || !Array.isArray(w.box)) continue;
    const loc = L[w.to];
    if (!loc) continue;
    const [map, x, y, dirDeg, name] = loc;
    const [x0, y0, x1, y1] = w.box;
    const z = { id: w.id, x0, z0: y0, x1: x1 + 1, z1: y1 + 1, dungeon: !!w.dungeon,
      to: { map: Number(map), x: Number(x) + 0.5, z: Number(y) + 0.5, dirDeg: Number(dirDeg) || 0, name: name || '' } };
    if (!byMap.has(Number(w.fromMap))) byMap.set(Number(w.fromMap), []);
    byMap.get(Number(w.fromMap)).push(z);
  }
  game.events?.on?.('map', () => { state = { map: game.world?.info?.index ?? -1, armed: false, t: 0, blockedZone: null }; });
  game.events?.on?.('teleport', () => { state.armed = false; state.blockedZone = null; });
}

// 2.2.1 instant map changes (engine/prefetch.js): walking up to a gate replays the destination map's recorded asset list
// in the background (a map visited before), so the map change finds its textures, meshes and window art in the caches.
let prefetchedZone = null;
function prefetchNearby(game, map, x, z) {
  const r = PREFETCH.portalRadius;
  let best = null, bestD = r * r;
  for (const w of byMap.get(Number(map)) || []) {
    const dx = x < w.x0 ? w.x0 - x : x >= w.x1 ? x - w.x1 : 0, dz = z < w.z0 ? w.z0 - z : z >= w.z1 ? z - w.z1 : 0;
    const d = dx * dx + dz * dz;
    if (d < bestD) { bestD = d; best = w; }
  }
  if (!best || best === prefetchedZone || !hasMapManifest(best.to.map)) return;
  prefetchedZone = best;
  const row = game.mapRow ? game.mapRow(best.to.map) : game.data?.mapByIndex?.(best.to.map);
  void prefetchMapAssets(best.to.map, { textures: game.textures, atlas, row, lanes: PREFETCH.portalLanes });
}

/** The zone of `map` containing FILE point (x, z), or null. */
export function zoneAt(map, x, z) {
  for (const w of byMap.get(Number(map)) || []) if (x >= w.x0 && x < w.x1 && z >= w.z0 && z < w.z1) return w;
  return null;
}

export function update(dt, game) {
  if (!game.warpZones?.enabled || game.paused || game._loadingMap) return;
  const p = game.player, world = game.world;
  if (!p || p.dead || !world) return;
  state.t -= dt;
  if (state.t > 0) return;
  state.t = CHECK_INTERVAL;
  const map = world.info.index;
  if (state.map !== map) state = { map, armed: false, t: CHECK_INTERVAL, blockedZone: null };
  const zone = zoneAt(map, p.x, p.z);
  if (!zone) { state.armed = true; state.blockedZone = null; prefetchNearby(game, map, p.x, p.z); return; }
  if (state.blockedZone === zone && state.retryAt && Date.now() >= state.retryAt) {
    state.blockedZone = null; state.retryAt = 0; state.armed = true;
  }
  if (!state.armed || state.blockedZone === zone) return;
  if (game.save?.authority === 'server' && zone.dungeon && !game.network?.self?.instanceId) return;
  // level gate of the destination map (maplist LimitMinLevel / LimitMaxLevel)
  const row = game.mapRow ? game.mapRow(zone.to.map) : game.data?.mapByIndex?.(zone.to.map);
  if (!row) { state.blockedZone = zone; return; }
  const lvl = Number(game.save?.level) || 1;
  const min = Number(row.LimitMinLevel) || 0, max = Number(row.LimitMaxLevel) || 0;
  if (((min > 0 && lvl < min) || (max > 0 && lvl > max)) && !game.gm?.st?.unlock) {   // GM /gm unlockmaps ignores the gate
    state.blockedZone = zone;
    game.hud?.log?.(lvl < min ? MSG_LOW : MSG_HIGH, 'err');
    return;
  }
  state.armed = false;
  game.controller?.stop?.();
  game.events?.emit?.('warpzone', { from: map, zone: zone.id, to: zone.to });
  // start the map change after this frame has finished (enterMap drops the old world synchronously)
  setTimeout(() => {
    Promise.resolve(game.save?.authority === 'server' && zone.dungeon
      ? game.network.action('dungeon', { operation: 'warp', gateId: zone.id })
      : game.travel(zone.to.map, { x: zone.to.x, z: zone.to.z, dirDeg: zone.to.dirDeg }, { gateId: zone.id }))
      .then(result => {
        // An online refusal leaves the character inside the gate. Re-arm after
        // a short pause so movement acknowledgement can catch up and retry.
        if (game.save?.authority === 'server' && !result && game.world?.info?.index === map) {
          state.blockedZone = zone; state.retryAt = Date.now() + 1000;
        }
      })
      .catch(err => { state.blockedZone = zone; state.retryAt = Date.now() + 1000; console.error('[warpzones] travel failed', err); });
  }, 0);
}
