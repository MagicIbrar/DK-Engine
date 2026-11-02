// World facade (docs/ARCHITECTURE.md §3.4): one loaded map = terrain + decals + water + objects + environment +
// collision + path finding + placement tables. Everything visual is added under game.worldRoot (mirror root) in the
// FILE frame; lights and sky go into game.scene (environment.js). All positions in and out are FILE frame
// (X = column, Z = row, Y up), see docs/formats/coords.md.
import { withChosenPlacements } from '../config/engine-chosen-guild-tournament.js';
import { prewarmNpcModels } from '../engine/npc-prewarm.js';
import * as THREE from 'three';
import { parseMap, sampleHeight } from '../formats/map.js';
import { mapEnvironmentInfo } from '../formats/environment.js';
import { mapDataPaths, parseLocationCSV, parseStartPointCSV, parseMapPointCSV, parseTableCSV } from '../formats/spawn.js';
import { fetchBuffer, fetchRequiredMapBuffer, tryFetchBuffer, fetchText, normPath } from '../engine/assets.js';
import { decodeText } from '../formats/binreader.js';
import { Terrain } from './terrain.js';
import { WaterLayer } from './water.js';
import { Environment } from './environment.js';
import { ObjectLayer } from './objects.js';
import { PortalEffects } from './portal-effects.js';
import { landingOverride } from './map-landing.js';
import { Collision } from './collision.js';
import { PathFinder } from './pathfind.js';
import { GroundSurfaces } from './groundsurf.js';
import { applyShadeTree, applyShadeTreeSliced, shadeOnFirstDraw, singlePassDoubleSided, setShade, resetShade } from './shade.js';
import { MapEffectLights } from './global-effect-light.js';
import { resolveMelLocalLights } from './mel-local-lights.js';
export { applyShade, applyShadeTree, SHADE } from './shade.js';

const STEP_HEIGHT = 1.2;   // how far above the current Y a ground helper may be and still be stepped onto

// legacy maps: see ./legacy-maps.js (shared with the host)
import { LEGACY_MAPS, legacyMapRow } from './legacy-maps.js';
export { LEGACY_MAPS, legacyMapRow };

// ------------------------------------------------------------------------------------------ shared tables
const tableCache = new Map();
function cachedTable(key, parse) {
  let p = tableCache.get(key);
  if (!p) {
    p = fetchText(key).then(parse).catch(err => {
      if (err?.transient) {
        if (tableCache.get(key) === p) tableCache.delete(key);
        throw err;
      }
      return null;
    });
    tableCache.set(key, p);
  }
  return p;
}
const placementTables = () => Promise.all([
  cachedTable('share/arrange/location.csv', parseLocationCSV),
  cachedTable('share/pc/startpoint.csv', parseStartPointCSV),
  cachedTable('share/arrange/portallocation.csv', parseMapPointCSV),
  cachedTable('share/dkmaplist.csv', t => parseTableCSV(t).rows),
  cachedTable('share/arrange/maprespawn.csv', t => parseTableCSV(t).rows),
]).then(([locations, startpoints, portals, dkmaplist, maprespawn]) => ({ locations, startpoints, portals, dkmaplist, maprespawn }));

let minimapTable = null;
/** imagetable group 'minimap' -> Map(index -> texture data key). */
function minimapKeys() {
  if (!minimapTable) {
    let p;
    p = tryFetchBuffer('script/ui/com/imagetable.txt').then(buf => {
      const out = new Map();
      if (!buf) return out;
      const text = decodeText(new Uint8Array(buf), true);
      for (const line of text.split(/\r?\n/)) {
        const c = line.split(',');
        if (c.length < 3 || c[0].trim().toLowerCase() !== 'minimap') continue;
        const idx = Number(c[1].trim());
        if (Number.isFinite(idx) && c[2].trim()) out.set(idx, normPath(`texture/${c[2].trim()}`)); // last line wins
      }
      return out;
    }).catch(err => {
      if (err?.transient) { minimapTable = null; throw err; }
      return new Map();
    });
    minimapTable = p;
  }
  return minimapTable;
}

const num = (v) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : null; };

// ------------------------------------------------------------------------------------------ World
export class World {
  constructor({ game }) {
    this.game = game;
    this.info = { index: -1, name: '', row: null, width: 512, height: 512 };
    this.spawns = [];
    this.npcPlacements = [];
    this.minimap = null;
    this.map = null;
    this.terrain = null;
    this.water = null;
    this.objects = null;
    this.portalEffects = null;
    this.mapLights = null;        // LANE-54: .mel cate-9 light placements -> environment.effectLights
    this.environment = null;
    this.collision = null;
    this.pathfinder = null;
    this.ground = null;
    this.root = new THREE.Group();
    this.root.name = 'world';
    this._tables = null;
    this._start = null;
    this._disposed = false;
    this._tmpV = new THREE.Vector3();
  }

  /** Resolve a map index to its maplist row (or a synthesised legacy row). */
  rowFor(mapIndex) {
    const data = this.game.data;
    let row = data?.mapByIndex ? data.mapByIndex(mapIndex) : null;
    if (!row) row = legacyMapRow(mapIndex, data?.mapByIndex ? data.mapByIndex(0) : null);
    return row;
  }

  /**
   * @param {number} mapIndex
   * @param {(f:number, label:string)=>void} [onProgress]
   * @param {{focus?:{x:number,z:number}}} [opts] where the player will appear (objects load nearest-first from here)
   */
  async load(mapIndex, onProgress = () => {}, opts = {}) {
    const game = this.game;
    const row = this.rowFor(mapIndex);
    if (!row) throw new Error(`World: unknown map ${mapIndex}`);
    const index = Number(row.Index);
    const envInfo = mapEnvironmentInfo(row);
    const paths = mapDataPaths(row);
    this.info = { index, name: String(row.Name || '').trim(), row, width: 512, height: 512, envInfo, paths };
    (game.worldRoot || game.scene).add(this.root);
    const prog = (a, b) => (f, label) => onProgress(a + (b - a) * Math.max(0, Math.min(1, f)), label);

    onProgress(0, '');
    // custom maps (src/systems/mapbuilder): a row with source() supplies its original-format files in memory:
    // { map, mol, mac: ArrayBuffer, spawns?, npcPlacements?, start?, lightText?, minimap? }
    const src = typeof row.source === 'function' ? await row.source() : null;
    this.source = src;
    const loadMacBuffer = async () => {
      if (src) return src.mac || null;
      if (!paths.mac) return null;
      try { return await fetchRequiredMapBuffer(paths.mac); }
      catch (err) {
        // Fail closed below instead of throwing: enterMap already disposed the previous world.
        // Full throw+lifecycle/lease retry is blocked by hazards in client420-corpus/EVIDENCE.md.
        console.warn('[world] required .mac fetch failed; fail-closed collision', paths.mac, err?.message || err);
        return null;
      }
    };
    // Authored MapAttribute uses required fetch+retry; blank/"<< Empty >>" and custom maps without mac stay optional.
    const [mapBuf, macBuf, molBuf, tables, mm] = await Promise.all(src ? [src.map, loadMacBuffer(), src.mol || null, placementTables(), new Map()] : [
      fetchRequiredMapBuffer(paths.map || envInfo.files.map),
      loadMacBuffer(),
      paths.mol ? tryFetchBuffer(paths.mol).catch(() => null) : null,
      placementTables(),
      minimapKeys(),
    ]);
    if (this._disposed) return;
    const map = parseMap(mapBuf);
    const originalEdit=await game.originalMapEdits?.loadSource?.(index,mapBuf,macBuf,map);
    if(this._disposed)return;
    if(originalEdit)this.info.originalEdit=originalEdit.state;
    this.map = map;
    this.info.width = map.width;
    this.info.height = map.height;
    this._tables = tables;
    const mmKey = mm.get(index);
    this.minimap = mmKey ? { key: mmKey, transposed: true } : null;

    // collision + paths
    const macRequired = !src && !!paths.mac && !originalEdit?.mac;
    this.collision = Collision.fromBuffer(originalEdit?.mac || macBuf, map.width, map.height, { required: macRequired });
    if (this.collision.loadFailed) console.warn('[world] collision fail-closed', { map: index, mac: paths.mac, reason: this.collision.loadFailed });
    if(originalEdit)for(let i=0;i<map.holes.length;i++)if(map.holes[i]&&!this.collision.cells[i]){this.collision.cells[i]=1;this.collision.walkableCount--;}
    this.pathfinder = new PathFinder(this.collision);
    this.ground = new GroundSurfaces(map.width, map.height);

    // placement tables
    this._buildSpawns(index);
    this._start = null;
    if (src) {
      if (Array.isArray(src.spawns)) this.spawns = src.spawns;
      if (Array.isArray(src.npcPlacements)) this.npcPlacements = src.npcPlacements;
      if (src.start) this._start = { ...src.start };
      if (src.minimap) this.minimap = src.minimap;
    }

    const sv = game.save;
    const savedHere = sv && sv.pos && Number(sv.map) === index && Number.isFinite(sv.pos.x) && Number.isFinite(sv.pos.z);
    const focus = opts.focus || (savedHere ? { x: sv.pos.x, z: sv.pos.z } : this.startPoint(false));
    // Decode nearby authored NPC models first while terrain and objects load.
    this._npcModelWarm = prewarmNpcModels(game.models, game.data?.npcs, this.npcPlacements, focus)
      .catch(error => ({ requested: 0, failures: [String(error?.message || error)] }));

    // terrain + environment + water
    this.terrain = new Terrain({ map, game, root: this.root, mapRow: this.info?.row || null });
    this.environment = new Environment(game, { envInfo, row, lightText: src?.lightText });
    this.water = new WaterLayer({ map, game, root: this.root, envMapKey: envInfo.environmentMap, reflectHeight: envInfo.reflectHeight });   // maplist Reflect_Height = Global planar water plane (LANE-66 rev c)
    await Promise.all([
      this.terrain.build(prog(0.02, 0.35)),
      this.environment.load(),
      this.water.build(),
    ]);
    if (this._disposed) return;
    onProgress(0.4, '');

    // objects: nearest-first around where the player will appear (opts.focus; else the saved position when the
    // save is on this map - game.js "continue" - else the map's start point)
    this.objects = new ObjectLayer({ game, root: this.root, heightAt: (x, z) => sampleHeight(map, x, z), ground: this.ground, environment: this.environment });
    const envNow = this.environment;
    this.objects.cullDistance = Math.min(envNow.viewDistance, envNow.fogEnd + 5);
    this.objects.viewDistance = envNow.viewDistance;
    await this.objects.load(molBuf, { focus, onProgress: prog(0.4, 1) });
    if (this._disposed) return;
    // Placed visual scenes are authored in .mel. Resolve their metadata before World ready.
    if (!src || this.npcPlacements.length) {
      this.portalEffects = new PortalEffects(game, this);
      await this.portalEffects.load(src ? null : paths.mel || envInfo.files.mel);
      await this._loadMapLights(src ? null : paths.mel || envInfo.files.mel, map);
    }
    // first culling pass around the focus
    const cam = { x: focus.x, z: focus.z };
    this._cull(0, cam.x, cam.z);
    onProgress(.99, '');
    await this.portalEffects?.preloadAt(cam.x,cam.z);
    if(this._disposed)return;
    onProgress(1, '');
    return {loaded:true,world:this,mapIndex:index};
  }

  /** LANE-54 pass 4: resolve the map's .mel cate-9 light placements (effectscene.map / effectdata.map lt_ units) and drive
   *  them through the Global effect-light receiver. Non-fatal: a missing table leaves the map without effect lights. */
  async _loadMapLights(melKey, map) {
    this.mapLights = null;
    if (!melKey) return;
    try {
      const [mel, scenesText, unitsText] = await Promise.all([tryFetchBuffer(melKey),
        fetchText('property/effect/effectscene.map.txt'), fetchText('property/effect/effectdata.map.txt')]);
      if (!mel || this._disposed) return;
      const { placements } = resolveMelLocalLights(mel, { scenesText, unitsText });
      // mel.js: THREE position = (x, terrain height + y, -z)
      for (const p of placements) p.pos = [p.x, sampleHeight(map, p.x, p.z) + p.y, -p.z];
      this.mapLights = placements.length ? new MapEffectLights(placements) : null;
    } catch (err) { console.warn('[world] map effect lights unavailable', err?.message || err); this.mapLights = null; }
  }

  // ---------------------------------------------------------------------------------------- tables
  _buildSpawns(index) {
    const data = this.game.data || {};
    const mons = data.monsters?.monsters || {};
    const rows = data.monsters?.spawns?.[index]?.rows || [];
    this.spawns = [];
    for (const r of rows) {
      const [monsterIndex, respawnSec, x, y] = r;
      const def = mons[monsterIndex];
      if (!def || def.role === 'invisible') continue;
      this.spawns.push({ monsterIndex: Number(monsterIndex), x: x + 0.5, z: y + 0.5, respawnSec: Number(respawnSec) || 0 });
    }
    // GUILD-TOURNEY: Donation Angel / Gambler Egg have no data placement (ENGINE-CHOSEN rows beside Ferdianand).
    const pl = withChosenPlacements(index, data.npcs?.placements?.[index]?.rows || []);
    const W = this.info.width, H = this.info.height;
    this.npcPlacements = [];
    for (const r of pl) {
      const [npcIndex, x, y, dirDeg, warpX, warpY, isEvent, desc] = r;
      if (!Number.isFinite(x) || !Number.isFinite(y)) continue;
      if (x <= 1 && (y <= 1 || y >= H - 2)) continue; // system NPCs parked at the map corner (coords.md)
      if (x < 0 || y < 0 || x > W || y > H) continue;
      this.npcPlacements.push({ npcIndex: Number(npcIndex), x, z: y, dirDeg: Number(dirDeg) || 0, warpX, warpZ: warpY, isEvent: !!isEvent, desc });
    }
  }

  /**
   * A safe point on this map (FILE frame). respawn = the return/respawn point where the data has one.
   * Order: startpoint.csv -> location.csv, maprespawn.csv, dkmaplist.csv respawn, portallocation.csv arrival,
   * dkmaplist LocatePos, any location.csv row of the map, NPC warp points, 1.4 units in front of the first NPC;
   * else the walkable cell nearest to the map centre. Every candidate is snapped to a walkable cell (radius 8).
   */
  startPoint(respawn = false) {
    if (!respawn && this._start) return { ...this._start };
    const idx = this.info.index;
    const t = this._tables || {};
    const cands = [];
    const add = (x, y, dirDeg = 0) => { if (Number.isFinite(x) && Number.isFinite(y) && (x > 0 || y > 0)) cands.push({ x: x + 0.5, z: y + 0.5, dirDeg: dirDeg || 0 }); };
    const loc = (i) => (t.locations ? t.locations.get(Number(i)) : null);
    if (respawn) {
      for (const sp of t.startpoints || []) { const l = loc(sp.returnIndex); if (l && l.mapIndex === idx && !l.placeholder) add(l.x, l.y, l.directionDeg); }
      for (const r of t.maprespawn || []) {
        if (num(r.MapIndex) === idx && num(r.RespawnMap) === idx) add(num(r.LocationX_1), num(r.LocationY_1));
      }
      for (const r of t.dkmaplist || []) {
        if (num(r.Index) === idx && num(r.RespawnMap_00) === idx) add(num(r.RespawnPosX_00), num(r.RespawnPosX_00_2));
      }
    }
    // Global travel arrival correction (map-landing.js): when registry/default landing
    // sits on a blocked .mac cell, prefer the authored walkable teleport/warp/portal target (exact cell).
    if (!respawn) {
      const lo = landingOverride(idx);
      if (lo?.landing) {
        const [lx, ly, ld] = lo.landing;
        cands.push({ x: Number(lx) + 0.5, z: Number(ly) + 0.5, dirDeg: Number(ld) || 0, fromLandingOverride: true });
      }
    }
    for (const sp of t.startpoints || []) { const l = loc(sp.locationIndex); if (l && l.mapIndex === idx && !l.placeholder) add(l.x, l.y, l.directionDeg); }
    for (const p of t.portals || []) if (p.mapIndex === idx) add(p.x, p.y, p.directionDeg || 0);
    for (const r of t.dkmaplist || []) if (num(r.Index) === idx) add(num(r.LocatePosX), num(r.LocatePosY));
    if (t.locations) for (const l of t.locations.values()) if (l.mapIndex === idx && !l.placeholder) add(l.x, l.y, l.directionDeg);
    // NPC warp points (coords.md: Warp_X/Y = where a warped player appears), e.g. the legacy field maps
    for (const n of this.npcPlacements) if (n.warpX > 1 && n.warpZ > 1 && !n.isEvent) add(n.warpX, n.warpZ, n.dirDeg);
    // else stand in front of the first NPC (1.4 units along its facing, as the NPC tool places warps)
    const n0 = this.npcPlacements.find(n => !n.isEvent);
    if (n0) {
      const d = (n0.dirDeg * Math.PI) / 180;
      cands.push({ x: n0.x - Math.sin(d) * 1.4, z: n0.z - Math.cos(d) * 1.4, dirDeg: n0.dirDeg });
    }
    const col = this.collision;
    let pick = null;
    for (const c of cands) {
      if (!col) { pick = c; break; }
      if (col.isWalkable(c.x, c.z)) { pick = c; break; }
      // landingOverride points are exact Global arrivals: never snap them onto a neighbor
      if (c.fromLandingOverride) continue;
      const s = col.nearestWalkable(c.x, c.z, 8);
      if (s) { pick = { x: s.x, z: s.z, dirDeg: c.dirDeg }; break; }
    }
    if (!pick) {
      const W = this.info.width, H = this.info.height;
      const s = col ? col.nearestWalkable(W / 2, H / 2, Math.max(W, H)) : null;
      pick = s ? { x: s.x, z: s.z, dirDeg: 0 } : { x: W / 2, z: H / 2, dirDeg: 0 };
    }
    if (!respawn) this._start = { ...pick };
    return pick;
  }

  // ---------------------------------------------------------------------------------------- queries
  /** Terrain surface only (no object floors). */
  terrainHeightAt(x, z) { return this.map ? sampleHeight(this.map, x, z) : 0; }

  /**
   * Ground height at FILE (x, z): the triangle-exact terrain, raised to the highest walkable object surface
   * (bridge/deck 'ground' helpers). With refY (the actor's current Y) only surfaces up to refY + step count, so
   * an actor under a bridge stays on the ground.
   */
  heightAt(x, z, refY = null) {
    if (!this.map) return 0;
    const t = sampleHeight(this.map, x, z);
    if (!this.ground || !this.ground.size) return t;
    const g = this.ground.heightAt(x, z, refY == null ? Infinity : refY + STEP_HEIGHT);
    return g > t ? g : t;
  }

  /** Inside the map and not blocked in the .mac grid. */
  isWalkable(x, z) { return this.collision ? this.collision.isWalkable(x, z) : false; }

  /** A* + string pulling; last point = target or the nearest walkable point. */
  findPath(fx, fz, tx, tz) { return this.pathfinder ? this.pathfinder.findPath(fx, fz, tx, tz) : null; }

  /** Nearest walkable cell centre to (x, z), or null. */
  nearestWalkable(x, z, maxRadius = 16) { return this.collision ? this.collision.nearestWalkable(x, z, maxRadius) : null; }

  /** Water surface level at a FILE point (or null). */
  waterLevelAt(x, z) { return this.water ? this.water.levelAt(x, z) : null; }

  /** Water definition type at a FILE cell (4 = FloorReflect: Global skips camera-underwater fog there), or null. */
  waterTypeAt(x, z) { return this.water && this.water.typeAt ? this.water.typeAt(x, z) : null; }

  /** .mac cell attribute info (share/arrange/cell.csv row: safety zone, fishing, ...). */
  cellInfo(x, z) { return this.collision ? this.collision.info(x, z) : null; }

  /**
   * Ground point under a THREE-space ray (ray-march in the FILE frame against heightAt, then bisection).
   * @param {THREE.Raycaster} raycaster
   * @returns {{x:number,y:number,z:number}|null} FILE frame
   */
  pickGround(raycaster) {
    if (!this.map) return null;
    const ray = raycaster.ray;
    const ox = ray.origin.x, oy = ray.origin.y, oz = -ray.origin.z;
    const dx = ray.direction.x, dy = ray.direction.y, dz = -ray.direction.z;
    const W = this.info.width, H = this.info.height;
    const maxT = Math.min(600, Math.max(100, this.environment ? this.environment.viewDistance * 2 : 300));
    const above = (t) => {
      const x = ox + dx * t, z = oz + dz * t;
      return oy + dy * t - this.heightAt(x, z);
    };
    let t0 = 0, f0 = above(0);
    if (f0 < 0) return null; // camera under ground
    let t = 0;
    while (t < maxT) {
      const step = Math.max(0.25, t * 0.01);
      const t1 = t + step;
      const x = ox + dx * t1, z = oz + dz * t1;
      if ((x < -2 || z < -2 || x > W + 2 || z > H + 2) && dy >= 0) break;
      const f1 = above(t1);
      if (f1 <= 0) {
        let a = t0 = t, b = t1;
        for (let i = 0; i < 20; i++) { const m = (a + b) / 2; if (above(m) > 0) a = m; else b = m; }
        const px = ox + dx * b, pz = oz + dz * b;
        if (px < 0 || pz < 0 || px > W || pz > H) return null;
        return { x: px, y: this.heightAt(px, pz), z: pz };
      }
      t = t1; f0 = f1;
    }
    return null;
  }

  // ---------------------------------------------------------------------------------------- frame
  _cull(dt, camX, camZ, pad = 0) {
    const env = this.environment;
    const view = env ? env.viewDistance : 75;
    const fogEnd = env ? env.fogEnd : view;
    const cull = Math.min(view, fogEnd + 5);
    this.cullDistance = cull;          // actors use it too (actor.js view culling) - camera-relative, unpadded
    this.terrain?.update(camX, camZ, Math.min(view, fogEnd + 12) + 8 + pad);
    this.water?.update(dt, camX, camZ, cull + 8 + pad);
    this.objects?.update(dt, camX, camZ, cull + pad, view + pad);
    this.portalEffects?.update(dt, camX, camZ);
  }

  /**
   * @param {number} dt seconds
   * @param {THREE.Vector3} cameraThreePos camera position in THREE space
   */
  update(dt, cameraThreePos) {
    if (!this.map || this._disposed) return;
    const cp = cameraThreePos || this.game.camera?.position || this._tmpV.set(this.info.width / 2, 0, -this.info.height / 2);
    const focus = this.game.cam?.target || null;
    // LANE-54: map lights post LightStart / LightStop to the environment's Global effect-light receiver before it applies
    this.mapLights?.update(dt * 1000, this.environment?.effectLights, focus || cp);
    this.environment?.update(dt, focus, cp);
    // the client's sun fall-off around the player (shade.js): centre = the camera target (the player), radius =
    // the light file's lightdistance; an active Global effect light moves the centre to the light (env+0x58) and lerps
    // the radius toward its `light` t2 (env+0x64)
    const sp = this.environment?.current?.shadePos;
    setShade(sp ? (this._shadeV || (this._shadeV = new THREE.Vector3())).set(sp[0], sp[1], sp[2]) : focus || cp, this.environment?.current?.lightDistance);
    // actors, drops and effects live under the same root: give their lit materials the same rule.
    // SMOOTH-CAM (2026-10-30): was a full applyShadeTree(worldRoot) every 0.5 s (a multi-ms walk of every node, bones included =
    // a dropped frame twice a second at 239 Hz). Now: patched in the draw that first uses the material (shade.js shadeOnFirstDraw)
    // plus the same walk spread over frames (<= 0.25 ms each) so compileAsync pre-builds still see patched materials.
    const wr = this.game.worldRoot;
    singlePassDoubleSided();
    if (wr) {
      if (globalThis.__dekaronNoShadeDrawHook === true) {
        this._shadeTimer = (this._shadeTimer || 0) - dt;
        if (this._shadeTimer <= 0) { this._shadeTimer = 0.5; applyShadeTree(wr); }
      } else {
        shadeOnFirstDraw(wr);
        const st = this._shadeSweep || (this._shadeSweep = { stack: [], wait: 0 });
        if (st.stack.length) applyShadeTreeSliced(st, wr);
        else if ((st.wait -= dt) <= 0) { st.wait = 0.5; applyShadeTreeSliced(st, wr); }
      }
    }
    // SMOOTH-CAM (2026-10-30): distance culling (objects / terrain chunks / water) is centred on the player the orbit camera looks
    // at, with the radius grown by the orbit's horizontal reach. Turning the camera swings its position ~distance units around
    // the player; centred on the camera that moved the cull circle >1.5 units on every turn and rebuilt instance buffers / rigs
    // every 0.2 s while turning. The player-centred circle (radius + reach) contains the old camera-centred one at every angle, so
    // nothing that was drawn before is dropped; it only changes when the player walks or the zoom crosses a 2-unit step.
    // First person / GM free camera / no player: the camera position as before. Kill switch: globalThis.__dekaronCameraCull = true.
    const cam = this.game.cam;
    let cx = cp.x, cz = cp.z, pad = 0;
    if (globalThis.__dekaronCameraCull !== true && focus && Number.isFinite(focus.x) && Number.isFinite(focus.z) && cam?.mode !== 'first-person' && !this.game.gm?.freecam?.on) {
      const reach = Math.hypot(cp.x - focus.x, cp.z - focus.z);
      const want = Math.max(Number(cam?.distance) || 0, reach);
      pad = Math.ceil((want + 0.5) / 2) * 2;
      if (reach <= pad) { cx = focus.x; cz = focus.z; } else pad = 0;
    }
    this._cull(dt, cx, -cz, pad);
  }

  dispose() {
    this._disposed = true;
    resetShade();
    this.objects?.dispose();
    this.portalEffects?.dispose();
    this.water?.dispose();
    this.terrain?.dispose();
    this.environment?.dispose();
    this.ground?.clear();
    this.root.removeFromParent();
    this.mapLights = null;
    this.objects = this.portalEffects = this.water = this.terrain = this.environment = null;
    this.map = null;
  }
}
