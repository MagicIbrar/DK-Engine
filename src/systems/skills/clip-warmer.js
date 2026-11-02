// SKILL-CLIP-COLD 2026-10-30 (phase 2): idle body-clip warming, so no skill's first cast waits on a clip load.
// Global keeps a class's skill motions resident; the web client loads each clip on demand, and a cold clip froze the pose,
// then played late / cut, or not at all (actor.js _tryCandidates). This warms, chunked and never blocking:
//  - the local player: every learned, castable skill's phase clips at the length they will play (current cast speed via
//    SkillEngine.castMul, equipped weapon style); a cast-speed / style / level / body change re-warms the new lengths;
//  - nearby players: each unique skill anim of their class pack once per body (any length: Actor plays a resolved clip of
//    the same anim at once, restretched to the requested length, actor.js readyClipOf).
// Monsters need nothing here: their skills are ATTACK action clips, preloaded at spawn (monster.js _load).
import { skillPhases, bodyClipRequests } from './engine.js';
import { skillWeaponCompatible } from './skill-weapon.js';

const LOCAL_SCAN_MS = 500, REMOTE_SCAN_MS = 1500, REMOTE_RANGE = 60;
const MAX_INFLIGHT = 4, MAX_INFLIGHT_BUSY = 1, START_PER_FRAME = 3, FRAME_BUDGET_MS = 1;

const norm = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
const clock = () => (globalThis.performance?.now?.() ?? Date.now());

export function createClipWarmer(game, engine) {
  const localQ = [], remoteQ = [];
  const started = new WeakMap();      // body model -> Set('anim|len') already requested
  const remoteDone = new WeakMap();   // remote body model -> true once its class clips are queued
  const modelIds = new WeakMap(); let modelSeq = 0;
  let inflight = 0, nextLocal = 0, nextRemote = 0, localSig = '', disposed = false;
  let scan = null;                    // {player, learned, i, style, mul}: phase lists are built a slice per frame (FRAME_BUDGET_MS)
  const stats = { requested: 0, resolved: 0, failed: 0, localClips: 0, remoteActors: 0, remoteClips: 0, maxFrameMs: 0, lastIdleAt: 0 };

  function enqueue(actor, list, q, byAnim) {
    const model = actor?.model; if (!model) return 0;
    let set = started.get(model); if (!set) started.set(model, set = new Set());
    let n = 0;
    for (const r of list) {
      const anim = norm(r.anim), len = Math.round(Number(r.len) * 1e6) / 1e6;
      const k = byAnim ? anim : `${anim}|${len}`;
      if (!anim || !(len > 0) || set.has(k)) continue;
      set.add(k); q.push({ actor, model, anim, len }); n++;
    }
    return n;
  }

  function localScan(p) {
    const data = engine.data; if (!data?.skills) return;
    const style = engine.equippedStyle(), mul = engine.castMul();
    if (!modelIds.has(p.model)) modelIds.set(p.model, ++modelSeq);
    const learned = [];
    for (const skill of data.skills.values()) {
      const id = Number(skill?.index), lv = engine.skillLevel(id);
      if (lv > 0 && !engine.isPassive(skill) && skillWeaponCompatible(skill, style)) learned.push(id, lv);
    }
    const sig = `${modelIds.get(p.model)}|${style}|${mul}|${learned.join(',')}`;
    if (sig === localSig) return;
    localSig = sig;
    // a changed cast speed / style / level supersedes lengths not started yet (they are requested again if they come back)
    for (const job of localQ) started.get(job.model)?.delete(`${job.anim}|${job.len}`);
    localQ.length = 0;
    scan = { player: p, learned, i: 0, style, mul };
  }

  function scanSlice(t0) {
    const sc = scan, data = engine.data;
    if (!sc || !data) return;
    if (sc.player !== game.player || sc.player.model == null) { scan = null; localSig = ''; return; }
    const list = [];
    while (sc.i < sc.learned.length && clock() - t0 < FRAME_BUDGET_MS) {
      const skill = engine.skillDef(sc.learned[sc.i]), L = skill && engine.levelData(skill, sc.learned[sc.i + 1]);
      sc.i += 2;
      if (!L) continue;
      try {
        const phases = skillPhases(skill, L).map(ph => ph.kind === 'cast' ? { ...ph, durationMs: ph.durationMs * sc.mul } : ph);
        for (const r of bodyClipRequests(data, skill, phases, sc.style)) list.push(r);
      } catch { /* a malformed row only skips its own warm */ }
    }
    stats.localClips += enqueue(sc.player, list, localQ, false);
    if (sc.i >= sc.learned.length) scan = null;
  }

  function remoteScan() {
    const net = game.network, players = net?.players, packOf = net?.remoteSkillPack, me = game.player;
    if (!players?.values || typeof packOf !== 'function') return;
    for (const a of players.values()) {
      if (!a || a === me || a.disposed || a.dead || !a.model || typeof a.warmClip !== 'function' || remoteDone.get(a.model)) continue;
      if (me && Math.hypot((a.x || 0) - (me.x || 0), (a.z || 0) - (me.z || 0)) > REMOTE_RANGE) continue;
      const ci = Number(a.save?.classIndex ?? a.classDef?.index);
      if (!Number.isInteger(ci) || ci < 0 || ci > 14) continue;
      const pack = packOf(ci);
      if (!pack?.data?.skills) continue;           // loading; picked up on a later scan
      remoteDone.set(a.model, true); stats.remoteActors++;
      const style = Number(a.classDef?.style ?? 1), list = [];
      for (const skill of pack.data.skills.values()) {
        if (!skill || engine.isPassive(skill)) continue;
        const L = pack.data.level(skill, 1) || skill.levels?.find(Boolean);
        if (!L) continue;
        try { for (const r of bodyClipRequests(pack.data, skill, skillPhases(skill, L), style)) list.push(r); } catch { /* skip row */ }
      }
      stats.remoteClips += enqueue(a, list, remoteQ, true);
    }
  }

  function pump(t0) {
    const limit = engine.active || game._loadingMap ? MAX_INFLIGHT_BUSY : MAX_INFLIGHT;
    let n = 0;
    while (inflight < limit && n < START_PER_FRAME && clock() - t0 < FRAME_BUDGET_MS) {
      const job = localQ.shift() || remoteQ.shift(); if (!job) break;
      const { actor } = job;
      if (actor.disposed || actor.model !== job.model || typeof actor.warmClip !== 'function') continue;
      let p; try { p = actor.warmClip(job.anim, job.len); } catch { p = null; }
      if (!p) continue;
      n++; inflight++; stats.requested++;
      Promise.resolve(p).then(c => { if (c) stats.resolved++; else stats.failed++; }, () => { stats.failed++; })
        .finally(() => { inflight--; if (!inflight && !localQ.length && !remoteQ.length) stats.lastIdleAt = clock(); });
    }
  }

  function update(t = clock()) {
    if (disposed) return;
    const t0 = clock(), p = game.player;
    if (!scan && p?.model && typeof p.warmClip === 'function' && t >= nextLocal) { nextLocal = t + LOCAL_SCAN_MS; localScan(p); }
    if (scan) scanSlice(t0);
    if (!scan && t >= nextRemote && game._worldReady === true && !game._loadingMap) { nextRemote = t + REMOTE_SCAN_MS; remoteScan(); }
    pump(t0);
    stats.maxFrameMs = Math.max(stats.maxFrameMs, clock() - t0);
  }

  return {
    update, stats,
    get pending() { return localQ.length + remoteQ.length + inflight; },
    dispose() { disposed = true; localQ.length = 0; remoteQ.length = 0; },
  };
}
