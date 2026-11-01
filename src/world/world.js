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
import { Collision } from './collision.js';
import { PathFinder } from './pathfind.js';
import { GroundSurfaces } from './groundsurf.js';
import { applyShadeTree, setShade, resetShade } from './shade.js';
export { applyShade, applyShadeTree, SHADE } from './shade.js';

const STEP_HEIGHT = 1.2;   // how far above the current Y a ground helper may be and still be stepped onto

// legacy maps: see ./legacy-maps.js (shared with the host)
import { LEGACY_MAPS, legacyMapRow } from './legacy-maps.js';
export { LEGACY_MAPS, legacyMapRow };

// ------------------------------------------------------------------------------------------ shared tables
const tableCache = new Map();
function cachedTable(key, parse) {
  if (!tableCache.has(key)) tableCache.set(key, fetchText(key).then(parse).catch(() => null));
  return tableCache.get(key);
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
    minimapTable = tryFetchBuffer('script/ui/com/imagetable.txt').then(buf => {
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
    }).catch(() => new Map());
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

    onProgress(0, 'Reading the map');
    // custom maps (src/systems/mapbuilder): a row with source() supplies its original-format files in memory:
    // { map, mol, mac: ArrayBuffer, spawns?, npcPlacements?, start?, lightText?, minimap? }
    const src = typeof row.source === 'function' ? await row.source() : null;
    this.source = src;
    const [mapBuf, macBuf, molBuf, tables, mm] = await Promise.all(src ? [src.map, src.mac || null, src.mol || null, placementTables(), new Map()] : [
      fetchRequiredMapBuffer(paths.map || envInfo.files.map),
      tryFetchBuffer(paths.mac).catch(() => null),
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
    this.collision = Collision.fromBuffer(originalEdit?.mac||macBuf, map.width, map.height);
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
    this.terrain = new Terrain({ map, game, root: this.root });
    this.environment = new Environment(game, { envInfo, row, lightText: src?.lightText });
    this.water = new WaterLayer({ map, game, root: this.root, envMapKey: envInfo.environmentMap });
    await Promise.all([
      this.terrain.build(prog(0.02, 0.35)),
      this.environment.load(),
      this.water.build(),
    ]);
    if (this._disposed) return;
    onProgress(0.4, 'Placing objects');

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
    }
    // first culling pass around the focus
    const cam = { x: focus.x, z: focus.z };
    this._cull(0, cam.x, cam.z);
    onProgress(.99,'Preparing nearby effects');
    await this.portalEffects?.preloadAt(cam.x,cam.z);
    if(this._disposed)return;
    onProgress(1, 'World ready');
    return {loaded:true,world:this,mapIndex:index};
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
  _cull(dt, camX, camZ) {
    const env = this.environment;
    const view = env ? env.viewDistance : 75;
    const fogEnd = env ? env.fogEnd : view;
    const cull = Math.min(view, fogEnd + 5);
    this.cullDistance = cull;          // actors use it too (actor.js view culling)
    this.terrain?.update(camX, camZ, Math.min(view, fogEnd + 12) + 8);
    this.water?.update(dt, camX, camZ, cull + 8);
    this.objects?.update(dt, camX, camZ, cull, view);
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
    this.environment?.update(dt, focus, cp);
    // the client's sun fall-off around the player (shade.js): centre = the camera target (the player), radius =
    // the light file's lightdistance
    setShade(focus || cp, this.environment?.current?.lightDistance);
    this._shadeTimer = (this._shadeTimer || 0) - dt;
    if (this._shadeTimer <= 0) {
      // actors, drops and effects live under the same root: give their lit materials the same rule
      this._shadeTimer = 0.5;
      if (this.game.worldRoot) applyShadeTree(this.game.worldRoot);
    }
    this._cull(dt, cp.x, -cp.z);
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
    this.objects = this.portalEffects = this.water = this.terrain = this.environment = null;
    this.map = null;
  }
}
