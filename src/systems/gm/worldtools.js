// World-side GM tools: immediate monster / NPC spawning, teleport, kill all, respawn, debug overlays, the free
// camera, the performance overlay and the sky override. Everything works through the engine's public objects
// (game.spawner, game.world, game.npcs, game.cam, game.renderer) and runtime wraps on instances; no shared file is edited.
import * as THREE from 'three';
import { kill } from '../../game/combat.js';
import { fileToThree } from '../../engine/space.js';

// ------------------------------------------------------------------------------------------ spawning
/**
 * Spawn a monster NOW at a FILE point (callmonster): a one-shot spawner record that never respawns, loaded at once
 * (not through the spawner's lazy 4-at-a-time queue), with full AI, drops, EXP and quest credit.
 * Resolves the Monster (or null).
 */
export async function spawnMonsterNow(game, monsterIndex, x, z, { persistent = false, tag = 'gm' } = {}) {
  const sp = game.spawner, w = game.world;
  const def = game.data?.monster?.(monsterIndex);
  if (!sp || !w || !def) return null;
  let px = x, pz = z;
  if (!w.isWalkable(px, pz)) { const n = w.nearestWalkable?.(px, pz, 6); if (n) { px = n.x; pz = n.z; } }
  const rec = {
    id: `${tag}${Date.now().toString(36)}${Math.random().toString(36).slice(2, 6)}`,
    spawn: { monsterIndex: Number(monsterIndex), x: px, z: pz, respawnSec: 0 },
    respawnSec: 1e12, monster: null, loading: true, deadAt: null, respawnAt: 0, failedUntil: 0, skip: false, oneShot: true, gm: true,
  };
  sp.records.push(rec);
  const gen = sp._gen;
  try {
    const Cls = await sp._monsterClass();
    if (gen !== sp._gen) return null;
    const m = new Cls(game, def, rec.spawn);
    await m.load?.();
    if (gen !== sp._gen || !sp.records.includes(rec)) { try { m.dispose?.(); } catch { /* ignore */ } return null; }
    sp._adopt(m, def, rec);
    m.gmSpawned = true;
    if (persistent) m.persistent = true;
    return m;
  } catch (err) {
    console.warn('[gm] spawn failed', monsterIndex, err);
    rec.skip = true;
    return null;
  } finally {
    rec.loading = false;
    // after death the record never comes back
    rec.respawnAt = 0;
  }
}

/** Scatter points: `count` walkable cells 1-3 cells around (x, z) (or exactly x, z for one). */
export function scatter(game, x, z, count) {
  const out = [];
  const w = game.world;
  for (let i = 0; i < count; i++) {
    if (i === 0 && count === 1) { out.push({ x, z }); continue; }
    let p = null;
    for (let k = 0; k < 12 && !p; k++) {
      const a = Math.random() * Math.PI * 2, r = 1 + Math.random() * Math.min(8, 2 + count / 6);
      const q = { x: x + Math.cos(a) * r, z: z + Math.sin(a) * r };
      if (!w || w.isWalkable(q.x, q.z)) p = q;
    }
    out.push(p || { x, z });
  }
  return out;
}

/** Spawn an NPC at a FILE point (functional: dialog, shops, quests...). Resolves the NPC. */
export async function spawnNpcNow(game, npcIndex, x, z, dirDeg = 0) {
  const def = game.data?.npcs?.npcs?.[npcIndex];
  if (!def) return null;
  const { NPC } = await import('../../actors/npc.js');
  const world = game.world;
  const npc = new NPC(game, { index: Number(npcIndex), ...def }, { npcIndex: Number(npcIndex), x, z, dirDeg, gm: true });
  await npc.load();
  if (game.world !== world) { npc.dispose(); return null; }
  npc.gmSpawned = true;
  game.npcs.push(npc);
  game.events?.emit?.('npc:spawn', { npc });
  return npc;
}

// ------------------------------------------------------------------------------------------ teleport
/** Teleport to a map / FILE point (null point = the map's landing / start point). */
export async function teleport(game, map, x = null, z = null, dirDeg = null) {
  const pos = Number.isFinite(x) && Number.isFinite(z) ? { x, z, dirDeg: dirDeg ?? ((game.player?.yaw || 0) * 180 / Math.PI) } : null;
  // a blocked cell: the nearest walkable one within 48 cells (game.travel alone falls back to the map's start point)
  const near = (w) => { if (!pos || !w || w.isWalkable(pos.x, pos.z)) return pos; const n = w.nearestWalkable?.(pos.x, pos.z, 48); return n ? { ...pos, x: n.x, z: n.z } : pos; };
  const same = game.world?.info?.index === Number(map);
  await game.travel(Number(map), same ? near(game.world) : pos);
  if (Number(game.world?.info?.index) !== Number(map)) throw new Error(`Could not enter map ${map}.`);
  if (!same && pos && game.world && !game.world.isWalkable(pos.x, pos.z)) {
    const p = near(game.world);
    if (p && p !== pos && game.world.isWalkable(p.x, p.z)) await game.travel(Number(map), p);
  }
  return { map: game.world?.info?.index, x: game.player?.x, z: game.player?.z };
}

// ------------------------------------------------------------------------------------------ monsters
/** Kill every live monster within radius (Infinity = the whole map). drops: the player gets the kill (EXP + loot). */
export function killAll(game, radius = Infinity, drops = true) {
  const p = game.player;
  let n = 0;
  for (const m of [...(game.spawner?.monsters || [])]) {
    if (m.dead || m.invulnerable) continue;
    if (Number.isFinite(radius) && p && Math.hypot(m.x - p.x, m.z - p.z) > radius) continue;
    kill(game, m, drops ? p : null);
    n++;
  }
  return n;
}

/** Respawn every spawn row of the map now (dead rows come back, far ones load when you get near). */
export function respawnAll(game) {
  const sp = game.spawner;
  if (!sp || !game.world) return 0;
  let n = 0;
  for (const r of sp.records) {
    if (r.gm) continue;
    if (!r.monster && !r.loading) { r.respawnAt = 0; r.failedUntil = 0; r.deadAt = null; n++; }
  }
  sp._scan = 0;
  return n;
}

// ------------------------------------------------------------------------------------------ debug overlays
export class DebugLayers {
  constructor(game) {
    this.game = game;
    this.on = new Set();
    this.root = null;
    this._t = 0;
    this._key = '';
  }
  toggle(layer, want = null) {
    if (layer === 'none') { this.on.clear(); this._clear(); return false; }
    const v = want == null ? !this.on.has(layer) : !!want;
    if (v) this.on.add(layer); else this.on.delete(layer);
    this._key = '';
    this._t = 0;
    if (!this.on.size) this._clear();
    return v;
  }
  _clear() {
    if (!this.root) return;
    this.root.traverse(o => { o.geometry?.dispose?.(); if (o.material && !o.material._shared) o.material.dispose?.(); });
    this.root.removeFromParent();
    this.root = null;
  }
  update(dt) {
    const g = this.game;
    if (!this.on.size || !g.world || !g.player) return;
    this._t -= dt;
    const p = g.player;
    const key = `${g.world.info.index}|${Math.round(p.x / 6)}|${Math.round(p.z / 6)}|${[...this.on].join()}`;
    const dynamic = this.on.has('bounds') || this.on.has('nav') || this.on.has('npcs') || this.on.has('spawns');
    if (key === this._key && (!dynamic || this._t > 0)) return;
    this._key = key; this._t = 0.5;
    this._clear();
    const root = this.root = new THREE.Group();
    root.name = 'gm-debug';
    g.worldRoot.add(root);
    const w = g.world, R = 40, cx = Math.floor(p.x), cz = Math.floor(p.z);
    const h = (x, z) => (w.heightAt(x, z) || 0) + 0.06;
    if (this.on.has('collision')) {
      const cells = [];
      for (let z = cz - R; z <= cz + R; z++) for (let x = cx - R; x <= cx + R; x++) if (!w.isWalkable(x + 0.5, z + 0.5)) cells.push([x, z]);
      if (cells.length) {
        const geo = new THREE.PlaneGeometry(0.96, 0.96); geo.rotateX(-Math.PI / 2);
        const mat = new THREE.MeshBasicMaterial({ color: 0xff3030, transparent: true, opacity: 0.38, side: THREE.DoubleSide, depthWrite: false });
        const im = new THREE.InstancedMesh(geo, mat, cells.length);
        const m4 = new THREE.Matrix4();
        cells.forEach(([x, z], i) => { m4.makeTranslation(x + 0.5, h(x + 0.5, z + 0.5), z + 0.5); im.setMatrixAt(i, m4); });
        im.frustumCulled = false; im.renderOrder = 5;
        root.add(im);
      }
    }
    if (this.on.has('grid')) {
      const pts = [];
      const G = 32;
      for (let k = -G; k <= G; k++) {
        for (let s = -G; s < G; s++) {
          pts.push(cx + k, h(cx + k, cz + s), cz + s, cx + k, h(cx + k, cz + s + 1), cz + s + 1);
          pts.push(cx + s, h(cx + s, cz + k), cz + k, cx + s + 1, h(cx + s + 1, cz + k), cz + k);
        }
      }
      const geo = new THREE.BufferGeometry(); geo.setAttribute('position', new THREE.Float32BufferAttribute(pts, 3));
      const ln = new THREE.LineSegments(geo, new THREE.LineBasicMaterial({ color: 0x40ffff, transparent: true, opacity: 0.35 }));
      ln.frustumCulled = false; root.add(ln);
    }
    if (this.on.has('spawns')) {
      const pts = [], col = [];
      for (const r of g.spawner?.records || []) {
        const x = r.spawn.x, z = r.spawn.z;
        if (Math.abs(x - p.x) > 90 || Math.abs(z - p.z) > 90) continue;
        pts.push(x, h(x, z) + 0.4, z);
        const c = r.monster && !r.monster.dead ? [0.2, 1, 0.3] : r.loading ? [1, 1, 0.2] : [1, 0.35, 0.2];
        col.push(...c);
      }
      if (pts.length) {
        const geo = new THREE.BufferGeometry();
        geo.setAttribute('position', new THREE.Float32BufferAttribute(pts, 3));
        geo.setAttribute('color', new THREE.Float32BufferAttribute(col, 3));
        const pm = new THREE.Points(geo, new THREE.PointsMaterial({ size: 9, sizeAttenuation: false, vertexColors: true, depthTest: false }));
        pm.frustumCulled = false; pm.renderOrder = 10; root.add(pm);
      }
    }
    if (this.on.has('npcs')) {
      const pts = [];
      for (const n of g.npcs) { pts.push(n.x, (n.y || 0), n.z, n.x, (n.y || 0) + (n.height || 2) + 1.2, n.z); }
      if (pts.length) {
        const geo = new THREE.BufferGeometry(); geo.setAttribute('position', new THREE.Float32BufferAttribute(pts, 3));
        const ln = new THREE.LineSegments(geo, new THREE.LineBasicMaterial({ color: 0xffd040, depthTest: false }));
        ln.frustumCulled = false; ln.renderOrder = 10; root.add(ln);
      }
    }
    if (this.on.has('nav')) {
      const o = g.controller?.order;
      const path = o?.path;
      if (path?.length) {
        const pts = [p.x, (p.y || 0) + 0.3, p.z];
        for (const q of path) pts.push(q.x, h(q.x, q.z) + 0.3, q.z);
        const geo = new THREE.BufferGeometry(); geo.setAttribute('position', new THREE.Float32BufferAttribute(pts, 3));
        const ln = new THREE.Line(geo, new THREE.LineBasicMaterial({ color: 0x60ff60, depthTest: false }));
        ln.frustumCulled = false; ln.renderOrder = 10; root.add(ln);
      }
      // walkable cells right around the player (green) for the path finder's view
      const cells = [];
      for (let z = cz - 12; z <= cz + 12; z++) for (let x = cx - 12; x <= cx + 12; x++) if (w.isWalkable(x + 0.5, z + 0.5)) cells.push([x, z]);
      if (cells.length) {
        const geo = new THREE.PlaneGeometry(0.9, 0.9); geo.rotateX(-Math.PI / 2);
        const im = new THREE.InstancedMesh(geo, new THREE.MeshBasicMaterial({ color: 0x30ff60, transparent: true, opacity: 0.18, side: THREE.DoubleSide, depthWrite: false }), cells.length);
        const m4 = new THREE.Matrix4();
        cells.forEach(([x, z], i) => { m4.makeTranslation(x + 0.5, h(x + 0.5, z + 0.5), z + 0.5); im.setMatrixAt(i, m4); });
        im.frustumCulled = false; root.add(im);
      }
    }
    if (this.on.has('bounds')) {
      const pts = [];
      for (const a of g.actors()) {
        if (Math.hypot(a.x - p.x, a.z - p.z) > 60) continue;
        const r = a.radius || 0.5, hh = a.height || 2, y0 = a.y || 0;
        const c = [[-r, -r], [r, -r], [r, r], [-r, r]];
        for (let k = 0; k < 4; k++) {
          const [ax, az] = c[k], [bx, bz] = c[(k + 1) % 4];
          pts.push(a.x + ax, y0, a.z + az, a.x + bx, y0, a.z + bz);
          pts.push(a.x + ax, y0 + hh, a.z + az, a.x + bx, y0 + hh, a.z + bz);
          pts.push(a.x + ax, y0, a.z + az, a.x + ax, y0 + hh, a.z + az);
        }
      }
      if (pts.length) {
        const geo = new THREE.BufferGeometry(); geo.setAttribute('position', new THREE.Float32BufferAttribute(pts, 3));
        const ln = new THREE.LineSegments(geo, new THREE.LineBasicMaterial({ color: 0xff60ff }));
        ln.frustumCulled = false; root.add(ln);
      }
    }
  }
  dispose() { this._clear(); this.on.clear(); }
}

// ------------------------------------------------------------------------------------------ free camera
export class FreeCam {
  constructor(game) {
    this.game = game;
    this.on = false;
    this.pos = new THREE.Vector3();
    this.yaw = 0; this.pitch = -0.3;
    this.speed = 12;
  }
  set(on) {
    const g = this.game;
    if (on === this.on) return on;
    this.on = !!on;
    if (this.on) {
      this.pos.copy(g.camera.position);
      const d = new THREE.Vector3(); g.camera.getWorldDirection(d);
      this.yaw = Math.atan2(-d.x, -d.z); this.pitch = Math.asin(Math.max(-1, Math.min(1, d.y)));
      if (!g.cam._gmOrigUpdate) {
        const orig = g.cam.update.bind(g.cam);
        g.cam._gmOrigUpdate = orig;
      }
      g.cam.update=(dt)=>(this.on?this._update(dt):g.cam._gmOrigUpdate(dt));
      if (g.controller && !g.controller._gmOrigUpdate) {
        const oc = g.controller.update.bind(g.controller);
        g.controller._gmOrigUpdate = oc;
      }
      g.controller.update=(dt)=>{if(!this.on)g.controller._gmOrigUpdate(dt);};
      g.controller?.stop?.();
    } else {
      g.cam.snap?.();
    }
    return this.on;
  }
  _update(dt) {
    const g = this.game, inp = g.input, K = this._editorKeys||inp.keys;   // raw key state (the key map only remaps hit/down)
    dt=Math.max(0,Math.min(.05,Number(dt)||0));
    const a=document.activeElement,typing=a&&(a.isContentEditable||/INPUT|TEXTAREA|SELECT/.test(a.tagName)),focused=!document.hidden&&document.hasFocus();
    if (!typing&&focused&&(inp.held.right || inp.held.middle)) { this.yaw -= inp.mouse.dx * 0.004; this.pitch -= inp.mouse.dy * 0.004; }
    this.pitch = Math.max(-1.5, Math.min(1.5, this.pitch));
    if (!typing&&focused&&inp.mouse.wheel) this.speed = Math.max(1, Math.min(200, this.speed * Math.pow(0.85, inp.mouse.wheel)));
    const f = new THREE.Vector3(-Math.sin(this.yaw) * Math.cos(this.pitch), Math.sin(this.pitch), -Math.cos(this.yaw) * Math.cos(this.pitch));
    const r = new THREE.Vector3(Math.cos(this.yaw), 0, -Math.sin(this.yaw));
    const v = new THREE.Vector3();
    if (!typing&&focused) {
      if (K.has('KeyW') || K.has('ArrowUp')) v.add(f);
      if (K.has('KeyS') || K.has('ArrowDown')) v.sub(f);
      if (K.has('KeyD') || K.has('ArrowRight')) v.add(r);
      if (K.has('KeyA') || K.has('ArrowLeft')) v.sub(r);
      if (K.has('KeyE') || K.has('Space')) v.y += 1;
      if (K.has('KeyQ') || K.has('KeyC')) v.y -= 1;
    }
    const fast = K.has('ShiftLeft') || K.has('ShiftRight') ? 4 : 1;
    if (v.lengthSq() > 0) this.pos.addScaledVector(v.normalize(), this.speed * fast * dt);
    g.camera.position.copy(this.pos);
    g.camera.lookAt(this.pos.clone().add(f));
  }
  /** The FILE-frame point under the free camera (for "teleport here"). */
  groundBelow() {
    const g = this.game;
    const x = this.pos.x, z = -this.pos.z;
    return g.world ? { x, z } : null;
  }
}

// ------------------------------------------------------------------------------------------ performance overlay
export class PerfOverlay {
  constructor(game) {
    this.game = game;
    this.el = null;
    this.frames = 0; this.acc = 0; this.t = 0;
    this.ms = []; this.fps = 0; this.worst = 0;
  }
  set(on) {
    if (on && !this.el) {
      const el = this.el = document.createElement('div');
      el.style.cssText = 'position:fixed;left:6px;top:6px;z-index:60;pointer-events:none;font:11px/14px Tahoma,Verdana,sans-serif;'
        + 'color:#e8f5c8;background:rgba(8,10,6,.78);border:1px solid #5a4a2a;padding:5px 8px;white-space:pre;text-shadow:1px 1px 0 #000;min-width:190px';
      (document.getElementById('ui') || document.body).appendChild(el);
    } else if (!on && this.el) { this.el.remove(); this.el = null; }
    return !!this.el;
  }
  get on() { return !!this.el; }
  /** frameMs = measured CPU time of one game frame. */
  frame(dt, frameMs) {
    if (!this.el) return;
    this.frames++; this.acc += dt; this.t -= dt;
    this.ms.push(frameMs); if (this.ms.length > 120) this.ms.shift();
    this.worst = Math.max(this.worst * 0.995, frameMs);
    if (this.t > 0) return;
    this.t = 0.25;
    this.fps = this.acc > 0 ? this.frames / this.acc : 0;
    this.frames = 0; this.acc = 0;
    const g = this.game, r = g.renderer?.info;
    const avg = this.ms.reduce((s, x) => s + x, 0) / Math.max(1, this.ms.length);
    const mon = g.spawner?.monsters || [];
    const mem = performance.memory ? `${(performance.memory.usedJSHeapSize / 1048576).toFixed(0)} / ${(performance.memory.jsHeapSizeLimit / 1048576).toFixed(0)} MB` : 'n/a';
    const p = g.player;
    const st = g.systems?.status?.() || { installed: [], failed: [] };
    this.el.textContent = [
      `FPS ${this.fps.toFixed(1)}   frame ${avg.toFixed(2)} ms (worst ${this.worst.toFixed(1)})`,
      `draw calls ${r?.render?.calls ?? '?'}   triangles ${(r?.render?.triangles ?? 0).toLocaleString('en-US')}`,
      `geometries ${r?.memory?.geometries ?? '?'}   textures ${r?.memory?.textures ?? '?'}   programs ${r?.programs?.length ?? '?'}`,
      `monsters ${mon.filter(m => !m.dead).length} live / ${mon.length} (+${g.spawner?.loadingCount ?? 0} loading)   npcs ${g.npcs?.length ?? 0}   drops ${g.loot?.drops?.length ?? 0}`,
      `map ${g.world?.info?.index ?? '-'} ${g.world?.info?.name || ''}`,
      p ? `pos ${p.x.toFixed(1)}, ${p.z.toFixed(1)}  y ${(p.y || 0).toFixed(1)}  yaw ${((p.yaw * 180 / Math.PI) % 360).toFixed(0)}` : '',
      `JS heap ${mem}   systems ${st.installed.length} ok${st.failed.length ? `, ${st.failed.length} failed` : ''}`,
    ].filter(Boolean).join('\n');
  }
  dispose() { this.set(false); }
}

// ------------------------------------------------------------------------------------------ sky override
/** Force a sky_table.txt sky type on the loaded map's environment (null = the map's own light keys). */
export function applySky(game, skyIndex) {
  const env = game.world?.environment;
  if (!env) return false;
  if (!env._gmOrigUpdate) {
    const orig = env.update.bind(env);
    env._gmOrigUpdate = orig;
    env.update = (dt, focus, camPos) => {
      orig(dt, focus, camPos);
      const t = env._gmSky;
      if (t == null) return;
      const tex = env._skyTexResolved?.get(t);
      const u = env.skyUniforms;
      if (!u) return;
      if (tex) { u.skyA.value = tex; u.skyB.value = tex; u.skyMix.value = 0; u.hasSky.value = 1; }
      const ck = env.skyTable?.[t]?.cloud;
      const ct = ck ? env._cloudTex?.get(ck) : null;
      if (ct) u.cloudTex.value = ct;
    };
  }
  env._gmSky = skyIndex == null ? null : Number(skyIndex);
  if (env._gmSky != null) {
    env._skyTexture?.(env._gmSky);
    const ck = env.skyTable?.[env._gmSky]?.cloud;
    if (ck && env._cloudTex && !env._cloudTex.has(ck) && game.textures?.load) {
      game.textures.load(ck, { repeat: true }).then(t => { if (t && env._cloudTex && !env._cloudTex.has(ck)) env._cloudTex.set(ck, t); }).catch(() => {});
    }
  }
  return true;
}

/** FILE point -> THREE vector (camera-space helpers for the panel). */
export const toThree = (x, y, z) => fileToThree(x, y, z, new THREE.Vector3());
