// Monster spawner: keeps the map's MON_*.csv spawn rows alive around the player.
//
//   * spawns = world.spawns = [{ monsterIndex, x, z, respawnSec }] in the FILE frame (cell centres)
//   * monsters within ACTIVATE_DIST of the player are constructed lazily (Monster + load(), at most
//     MAX_CONCURRENT_LOADS at a time, nearest first) and removed again beyond DEACTIVATE_DIST.
//     A despawned monster keeps its respawn state; an idle one simply comes back when the player returns. Streaming is a
//     performance mechanic only: a hurt living monster that is despawned comes back with the same fraction of its max HP
//     (rec.hpFraction; no regeneration, no heal). It is re-created at its spawn point (the monster is rebuilt from the row,
//     as before); a monster that was killed follows its normal respawn timer and returns at full HP.
//   * kills: the corpse stays until it has faded (or CORPSE_SECONDS), then the row respawns after its regen time.
//   * at most MAX_LIVE monsters exist at once.
//
// Regen values (seconds, share/map/*/MON_*.csv column 2) are sanitised (ENGINE-CHOSEN, shared with the server through
// src/game/monster-rules.js sanitizeRespawn / src/config/engine-chosen-monster-ai.js respawn):
//   0 / missing / negative  -> DEFAULT_RESPAWN (30 s, the most common value in the client, 5,226 of 27,885 rows)
//   1..4                    -> MIN_RESPAWN (5 s) so a row cannot spam
//   >= 60000 (60000, 65534 = "effectively never" in the server tables) -> RARE_RESPAWN (15 min) so single-player
//                              unique spawns come back eventually instead of never
//   everything else (9 s .. 36000 s, boss rows 2700/3600/3800 s) is used as-is.
import { MonsterBrain } from './ai.js';
import { isAlive } from './combat.js';
import { sanitizeRespawn } from './monster-rules.js';
import { MONSTER_AI_ENGINE_CHOSEN as C } from '../config/engine-chosen-monster-ai.js';

export const ACTIVATE_DIST = 70;
export const DEACTIVATE_DIST = 110;
export const MAX_LIVE = 80;
export const MAX_CONCURRENT_LOADS = 4;
export const DEFAULT_RESPAWN = C.respawn.defaultSec;
export const MIN_RESPAWN = C.respawn.minSec;
export const RARE_RESPAWN = C.respawn.rareSec;
export const CORPSE_SECONDS = 8;
const SCAN_INTERVAL = 0.4;
const LOAD_RETRY = 60;

export { sanitizeRespawn };

/** HP fraction (0..1) of a living, hurt monster; null when it is at full HP or has no usable HP. */
function hurtFraction(m) {
  const max = Number(m.maxHp), hp = Number(m.hp);
  if (!(max > 0) || !(hp > 0) || hp >= max) return null;
  return hp / max;
}

// perf3: three creates each skeleton's float bone texture lazily inside the first draw of the body (WebGLRenderer.setProgram),
// so a crowd that becomes visible in one frame allocated and uploaded dozens of RGBA32F textures in that frame. Create them
// here, exactly as three would (Skeleton.computeBoneTexture, same size and contents), and push them through the budgeted
// upload queue before the monster is adopted. The first draw then finds boneTexture set and initialised: same pixels.
async function prepareBoneTextures(g, m) {
  const up = g?.textures?.uploads;
  if (globalThis.__dekaronNoBonePrep === true) return;   // kill switch (A/B): three creates them in the first draw again
  if (!up || typeof up.upload !== 'function') return;
  const roots = [m?.group, m?.object].filter(Boolean), seen = new Set(), jobs = [];
  for (const root of roots) root.traverse?.(o => {
    const sk = o.isSkinnedMesh ? o.skeleton : null;
    if (!sk || seen.has(sk)) return;
    seen.add(sk);
    if (sk.boneTexture === null && typeof sk.computeBoneTexture === 'function') sk.computeBoneTexture();
    if (sk.boneTexture && !sk.boneTexture._dkUploaded) { sk.boneTexture._dkUploaded = true; jobs.push(up.upload(sk.boneTexture).catch(() => null)); }
  });
  if (jobs.length) await Promise.all(jobs);
}

export class Spawner {
  /** opts.MonsterClass / opts.BrainClass let tests (or other modes) inject their own classes. */
  constructor(game, opts = {}) {
    this.game = game;
    this.MonsterClass = opts.MonsterClass || null;
    this.BrainClass = opts.BrainClass || MonsterBrain;
    this.activateDist = opts.activateDist ?? ACTIVATE_DIST;
    this.deactivateDist = opts.deactivateDist ?? DEACTIVATE_DIST;
    this.maxLive = opts.maxLive ?? MAX_LIVE;
    this.maxLoads = opts.maxLoads ?? MAX_CONCURRENT_LOADS;
    this.records = [];
    this._list = [];
    this._loading = new Set();
    this._gen = 0;
    this._scan = 0;
    this._classPromise = null;
  }

  /** Live monster actors (alive or corpses still fading). */
  get monsters() { return this._list; }
  get loadingCount() { return this._loading.size; }

  start(spawns) {
    this.clear();
    this.records = (spawns || []).map((s, i) => ({
      id: i,
      spawn: { monsterIndex: Number(s.monsterIndex), x: Number(s.x), z: Number(s.z), respawnSec: s.respawnSec },
      respawnSec: sanitizeRespawn(s.respawnSec),
      monster: null,
      loading: false,
      hpFraction: null,   // HP (fraction of max) of a living monster despawned while hurt; null = full
      deadAt: null,
      respawnAt: 0,
      failedUntil: 0,
      skip: false,
    }));
    this._scan = 0;
  }

  /**
   * (playgate, 2u) Load the monsters around the player while the loading screen is still up (bounded), so their
   * meshes / textures / clips are not decoded on the main thread during the first seconds of play (the "wonky first
   * steps" hitches). Monsters adopted here stay frozen until the game unpauses.
   */
  async prewarm(maxMs = 6000) {
    const t0 = performance.now();
    for (let pass = 0; pass < 24 && performance.now() - t0 < maxMs; pass++) {
      this._scanSpawns(this.game?.time || 0);
      if (!this._loading.size) break;
      while (this._loading.size && performance.now() - t0 < maxMs) await new Promise(r => setTimeout(r, 40));
    }
  }

  /**
   * (overnight 43.19, 2026-10-29) One hidden instance of every monster KIND of this map's MON rows that is not live yet, loaded under the
   * loading screen and kept until the load's warm draws (game.js _warmUp: _drawFrame, warmWholeScene, a real render) have drawn it once,
   * then released (releaseKindWarm). MEASURED (tools/_overnight-43.19/bench-mobs.mjs, RTX 3070 / ANGLE D3D11, Ardeca, 200 real monsters
   * of the map's 15 kinds spawned at once): the first draw of each new kind stalled the GPU process (ANGLE draw variants, texture / buffer
   * creation - see engine/warm-draw.js), main thread idle: 96-150 ms frames; with every kind already drawn once the same spawn peaked at
   * 33 ms. Model cache, textures and shader programs (keepShaderPrograms) stay; only these instances are disposed.
   * Works for the server-authority mode too (kinds come from world.spawns). Kill switch: globalThis.__dekaronNoKindWarm = true.
   */
  async prewarmKinds(spawns, maxMs = 4000) {
    this.releaseKindWarm();
    if (globalThis.__dekaronNoKindWarm === true) return 0;
    const g = this.game, p = g?.player;
    if (!p || typeof g?.data?.monster !== 'function') return 0;
    const live = new Set(this._list.map(m => Number(m.spawnRecord?.spawn?.monsterIndex)));
    const kinds = [...new Set((spawns || []).map(s => Number(s.monsterIndex)))].filter(k => Number.isFinite(k) && !live.has(k));
    if (!kinds.length) return 0;
    const gen = this._gen, t0 = performance.now(), warm = this._kindWarm = [];
    const Cls = await this._monsterClass();
    let next = 0;
    const lane = async () => {
      while (next < kinds.length && performance.now() - t0 < maxMs && gen === this._gen && this._kindWarm === warm) {
        const k = kinds[next++], def = g.data.monster(k);
        if (!def || def.role === 'invisible') continue;
        let m = null;
        try { m = new Cls(g, def, { monsterIndex: k, x: p.x, z: p.z, respawnSec: 0 }); warm.push(m); await m.load?.(); }
        catch (err) { if (m) this._disposeMonster(m); }
      }
    };
    await Promise.all(Array.from({ length: Math.max(1, this.maxLoads) }, lane));
    this.kindWarmStats = { kinds: kinds.length, loaded: warm.length, ms: Math.round(performance.now() - t0) };
    return warm.length;
  }

  /** Dispose the hidden kind-warm instances (after the load's warm draws; at the latest on the first play-time update). */
  releaseKindWarm() {
    const warm = this._kindWarm;
    this._kindWarm = null;
    if (warm) for (const m of warm) this._disposeMonster(m);
  }

  clear() {
    this.releaseKindWarm();
    this._gen++;
    for (const m of this._list) this._disposeMonster(m);
    this._list = [];
    this._loading.clear();
    for (const r of this.records) { r.monster = null; r.loading = false; }
    this.records = [];
  }

  update(dt) {
    const g = this.game;
    if (this._kindWarm && !g?._loadingMap) this.releaseKindWarm();   // safety: never let a kind-warm body reach a play frame
    const now = g?.time || 0;
    // 1) think + animate every live monster, collect faded corpses
    let removed = false;
    for (const m of this._list) {
      const dg = globalThis.__dkT_spDiag ? performance.now() : 0;   // PERF-CROWD diagnostics (DK_T=spDiag)
      try {
        if (!m.dead && m.brain) m.brain.update(dt);
        const dm = dg ? performance.now() : 0;
        m.update?.(dt);
        if (dg) { const t = performance.now(), D = (globalThis.__dkSpDiag ||= { worstBrain: [0], worstUpdate: [0] }); if (dm - dg > D.worstBrain[0]) D.worstBrain = [+(dm - dg).toFixed(2), m.name, m.brain?.state, g?.time]; if (t - dm > D.worstUpdate[0]) D.worstUpdate = [+(t - dm).toFixed(2), m.name, m.clip?.name ?? m.state ?? null, g?.time]; }
      } catch (err) { console.warn('monster update failed', m?.name, err); }
      const rec = m.spawnRecord;
      if (m.dead) {
        if (rec && rec.deadAt == null) rec.deadAt = m.diedAt ?? now;
        const since = now - (rec?.deadAt ?? m.diedAt ?? now);
        const faded = m.faded === true || m.removable === true || m.fadeDone === true;
        if (faded || since >= CORPSE_SECONDS) {
          if (rec) {
            rec.respawnAt = rec.oneShot ? Infinity : (rec.deadAt ?? now) + rec.respawnSec;
            if (rec.oneShot) rec.skip = true;
            rec.deadAt = null;
            rec.monster = null;
          }
          m._spawnerRemove = true;
          removed = true;
        }
      }
    }
    if (removed) {
      const keep = [];
      for (const m of this._list) {
        if (m._spawnerRemove) {
          if (g?.player?.target === m) this._clearPlayerTarget(m);
          this._disposeMonster(m);
        } else keep.push(m);
      }
      this._list = keep;
      this.records = this.records.filter(rec => !rec.oneShot || !rec.skip || rec.loading || rec.monster);
    }
    // 2) (de)activate rows around the player
    this._scan -= dt;
    if (this._scan <= 0) {
      this._scan = SCAN_INTERVAL;
      this._scanSpawns(now);
    }
  }

  _clearPlayerTarget(m) {
    const g = this.game;
    if (g.controller?.setTarget) g.controller.setTarget(null);
    else { g.player.target = null; g.events?.emit('target', { actor: null }); }
    m.setHighlight?.(false);
  }

  _scanSpawns(now) {
    const p = this.game?.player;
    if (!p) return;
    // deactivate far monsters (never one that is fighting the player)
    let removed = false;
    for (const m of this._list) {
      if (m.dead || m._spawnerRemove || m.persistent) continue;   // persistent: scripted event actors (bricks, waves)
      const fighting = m.brain && (m.brain.state === 'chase' || m.brain.state === 'attack') && m.brain.target === p;
      if (fighting) continue;
      if (Math.hypot(m.x - p.x, m.z - p.z) > this.deactivateDist) {
        const rec = m.spawnRecord;
        if (rec) {
          rec.monster = null;
          rec.respawnAt = Math.max(rec.respawnAt, now);
          // streaming is a performance mechanic, not a heal: remember how hurt it was (fraction of max HP) for _adopt
          rec.hpFraction = hurtFraction(m);
          // A monster whose chase ended away from its spawn (brain.anchor = its roaming
          // centre) comes back where it was, with the same roaming centre. A monster that never gave up a chase is re-created at its spawn as always.
          rec.restore = m.brain?.anchor ? { x: m.x, z: m.z, anchor: { x: m.brain.anchor.x, z: m.brain.anchor.z } } : null;
        }
        m._spawnerRemove = true;
        removed = true;
      }
    }
    if (removed) {
      const keep = [];
      for (const m of this._list) {
        if (m._spawnerRemove) {
          if (this.game.player?.target === m) this._clearPlayerTarget(m);
          this._disposeMonster(m);
        } else keep.push(m);
      }
      this._list = keep;
    }

    // activate nearby rows, nearest first
    let budget = Math.min(this.maxLoads - this._loading.size, this.maxLive - this._list.length - this._loading.size);
    if (budget <= 0) return;
    const r2 = this.activateDist * this.activateDist;
    const cand = [];
    for (const rec of this.records) {
      if (rec.monster || rec.loading || rec.skip) continue;
      if (now < rec.respawnAt || now < rec.failedUntil) continue;
      const dx = rec.spawn.x - p.x, dz = rec.spawn.z - p.z;
      const d2 = dx * dx + dz * dz;
      if (d2 <= r2) cand.push([d2, rec]);
    }
    cand.sort((a, b) => a[0] - b[0]);
    for (const [, rec] of cand) {
      if (budget-- <= 0) break;
      this._load(rec, now);
    }
  }

  async _monsterClass() {
    if (this.MonsterClass) return this.MonsterClass;
    if (!this._classPromise) this._classPromise = import('../actors/monster.js').then(mod => (this.MonsterClass = mod.Monster));
    return this._classPromise;
  }

  async _load(rec, now) {
    const g = this.game;
    const def = g?.data?.monster ? g.data.monster(rec.spawn.monsterIndex) : null;
    if (!def) { rec.skip = true; return; }
    if (def.role === 'invisible') { rec.skip = true; return; } // trap / trigger volumes have no body
    rec.loading = true;
    this._loading.add(rec);
    const gen = this._gen;
    let m = null;
    try {
      const Cls = await this._monsterClass();
      if (gen !== this._gen) return;
      m = new Cls(g, def, rec.spawn);
      await m.load?.();
      if (gen !== this._gen || !this.records.includes(rec)) { this._disposeMonster(m); m = null; return; }
      await prepareBoneTextures(g, m);
      if (gen !== this._gen || !this.records.includes(rec)) { this._disposeMonster(m); m = null; return; }
      this._adopt(m, def, rec);
    } catch (err) {
      console.warn('monster spawn failed', rec.spawn.monsterIndex, def?.name, err);
      rec.failedUntil = (g?.time || now) + LOAD_RETRY;
      if (m) this._disposeMonster(m);
    } finally {
      if (gen === this._gen) {
        rec.loading = false;
        this._loading.delete(rec);
        this._scan = Math.min(this._scan, 0); // a load slot freed up: fill it on the next frame
      }
    }
  }

  _adopt(m, def, rec) {
    if (!m.def) m.def = def;
    m.spawn = m.spawn || rec.spawn;
    m.home = { x: rec.spawn.x, z: rec.spawn.z };
    m.spawnRecord = rec;
    if (m.kind == null) m.kind = 'monster';
    if (m.level == null) m.level = def.level;
    if (!(m.maxHp > 0)) m.maxHp = Math.max(1, Number(def.hp) || 1);
    if (m.hp == null || !(m.hp > 0)) m.hp = m.maxHp;
    // a slot whose living monster was despawned while hurt comes back with the same fraction of max HP (never full, never
    // regenerated). hpFraction is only ever set for a LIVING despawned monster and consumed here, so a slot that was never
    // hurt, or whose monster was killed (it is not despawned: it follows the respawn timer), is created at full HP
    if (rec.hpFraction != null) m.hp = Math.max(1, Math.min(m.maxHp, m.maxHp * rec.hpFraction));
    rec.hpFraction = null;
    m.dead = false;
    if (!Number.isFinite(m.x) || Math.hypot(m.x - rec.spawn.x, m.z - rec.spawn.z) > 0.01) m.setPosition?.(rec.spawn.x, rec.spawn.z);
    const rs = rec.restore;
    rec.restore = null;
    if (rs) m.setPosition?.(rs.x, rs.z);   // despawned by distance while re-homed: back where it was (the spawn itself stays m.home / rec.spawn)
    m.brain = new this.BrainClass(this.game, m);
    if (rs) m.brain.anchor = { x: rs.anchor.x, z: rs.anchor.z };
    rec.monster = m;
    rec.deadAt = null;
    this._list.push(m);
    this.game?.events?.emit('spawn', { actor: m });
  }

  _disposeMonster(m) {
    if (!m || m._spawnerDisposed) return;
    m._spawnerDisposed = true;
    try { m.brain?.dispose?.(); } catch { /* the follower slot is healed by the book */ }
    m.brain = null;
    try { m.setHighlight?.(false); } catch { /* ignore */ }
    try { m.dispose?.(); } catch (err) { console.warn('monster dispose failed', err); }
    m.disposed = true;
  }

  /** Living monsters within `radius` of (x, z). */
  near(x, z, radius) {
    const out = [];
    for (const m of this._list) if (isAlive(m) && Math.hypot(m.x - x, m.z - z) <= radius) out.push(m);
    return out;
  }
}
