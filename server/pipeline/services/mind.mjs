// MIND (mob / NPC AI service), Realm side. Our own service name and code (docs/SERVER-SPLIT-DESIGN.md, Phase A remaining).
// OFF unless the Realm process is started with DK_MIND=1: mindFor() then returns null and the world tick runs exactly as before.
//
// What Mind owns today: TARGET ACQUISITION of idle aggressive monsters (the SIGHT_IN scan: monsters x players of a scene).
//   * Every tick Realm copies out, for each monster that reached that scan, its position, roaming centre, sight and pursuit, and
//     the positions of the players it could see (the scene view the tick already built). That copy goes to the Mind worker
//     (mind-worker.mjs, own thread, typed arrays transferred).
//   * The worker answers with an ACQUIRE intent per monster: the players inside the acquisition rule widened by two margins.
//   * The next tick(s), Realm APPLIES an intent instead of scanning, and stays authoritative: it re-runs the exact rule
//     (live, canAcquire, follower cap) on the intent's players, plus every player that moved more than PLAYER_MARGIN since the
//     copy or was not in it, in the same order its own scan uses.
// Why the result is exactly Realm's own scan (not "close to it"): a player p that passes canAcquire now, with the monster
// within MONSTER_MARGIN of its copied spot and p within PLAYER_MARGIN of its copied spot (else p is tested anyway), was within
// sight + both margins of the monster, within pursuit + PLAYER_MARGIN of the same roaming centre, and the monster within
// pursuit + MONSTER_MARGIN of it, at copy time (triangle inequality). The worker lists every such player, so the first player
// passing the rule in Realm's order is the same one. The follower-cap check runs only after canAcquire passes, as before, so its
// calls (and their healing) happen in the same order. When anything does not line up (no intent yet, other roaming centre,
// sight / pursuit changed, monster moved too far, fewer than 16 players: the same size where Realm's own grid is skipped) the
// tick simply runs its own scan. Stale intents are therefore safe; they only cost a few extra checks.
// Not moved (and why): hostility retarget, leash, chase steps, attack choice and damage stay in Realm. They change state every
// hit or consume Realm's single random stream in order, so moving them would change outcomes, not just where they run.
import { Worker } from 'node:worker_threads';
import { performance } from 'node:perf_hooks';
import { pipelineClient } from '../client.mjs';

export const MIND_DEFAULTS = Object.freeze({ playerMargin: 4, monsterMargin: 4, minPlayers: 16, maxAge: 3 });   // ENGINE-CHOSEN (cells / players / ticks)

import { mindAllowed } from './cores.mjs';   // NETX4: no Mind worker on a 1-core machine (cores.mjs)
export function mindEnabled(env = process.env) { return mindAllowed(env); }

/** The Mind link of one world, or null when Mind is off (DK_MIND != 1). */
export function mindFor(world, { env = process.env, ...opts } = {}) {
  if (!mindEnabled(env)) return null;
  // DK_MIND_PLAYER_MARGIN / DK_MIND_MONSTER_MARGIN (cells) and DK_MIND_MAX_AGE (ticks) only change how often Realm re-tests players itself, never the result
  const num = v => (v !== undefined && v !== '' && Number.isFinite(+v) && +v >= 0 ? +v : undefined);
  opts = { playerMargin: num(env.DK_MIND_PLAYER_MARGIN), monsterMargin: num(env.DK_MIND_MONSTER_MARGIN), maxAge: num(env.DK_MIND_MAX_AGE), ...opts };
  for (const k of Object.keys(opts)) if (opts[k] === undefined) delete opts[k];
  try { return new MindLink(opts); } catch (error) { console.warn('[mind] disabled:', error?.message || error); return null; }
}

class MindLink {
  constructor({ playerMargin = MIND_DEFAULTS.playerMargin, monsterMargin = MIND_DEFAULTS.monsterMargin, minPlayers = MIND_DEFAULTS.minPlayers, maxAge = MIND_DEFAULTS.maxAge } = {}) {
    this.PM = playerMargin; this.MM = monsterMargin; this.minPlayers = minPlayers; this.maxAge = maxAge;
    this.PM2 = playerMargin * playerMargin; this.MM2 = monsterMargin * monsterMargin;
    this.worker = new Worker(new URL('./mind-worker.mjs', import.meta.url), { workerData: { playerMargin, monsterMargin } });
    this.worker.on('message', msg => this._onMessage(msg));
    this.worker.on('error', error => this._fail(error));
    this.worker.on('exit', code => { if (!this.closed) this._fail(new Error('Mind worker exited ' + code)); });
    this.worker.unref();   // after the listeners (adding a listener refs it again): Mind never keeps Realm alive
    this.gen = 0; this.inFlight = null; this.latest = null; this.rec = null; this.closed = false; this.failed = false;
    this.waiters = [];
    this.counters = { posted: 0, skipped: 0, results: 0, used: 0, fallback: 0, extras: 0, workerMs: 0, realmMs: 0 };
    this._statsAt = 0;
  }
  _fail(error) {
    if (this.failed) return;
    this.failed = true; this.latest = null; this.inFlight = null; this.rec = null;
    console.warn('[mind] worker failed, Realm scans on its own again:', error?.message || error);
    this._wake();
  }
  _wake() { const w = this.waiters; this.waiters = []; if (w.length) this.worker.unref(); for (const r of w) r(); }
  _onMessage(msg) {
    const pending = this.inFlight;
    if (!pending || msg?.gen !== pending.gen) return;
    this.inFlight = null;
    if (msg.op === 'intents') {
      pending.cOff = msg.cOff; pending.cand = msg.cand;
      this.latest = pending; this.counters.results++; this.counters.workerMs += msg.ms || 0;
    } else if (msg.op === 'error') console.warn('[mind] plan failed:', msg.message);
    this._wake();
  }
  /** Resolves when no copy is waiting for the worker (tests and benches). */
  settle() {
    if (!this.inFlight || this.failed) return Promise.resolve();
    this.worker.ref();   // only while someone waits on the answer (an unref'd worker would let the event loop drain)
    return new Promise(r => this.waiters.push(r));
  }
  close() { this.closed = true; this.latest = null; this.inFlight = null; this._wake(); return this.worker.terminate().catch(() => {}); }
  stats() { return { ...this.counters, gen: this.gen, inFlight: !!this.inFlight, failed: this.failed, margins: { player: this.PM, monster: this.MM } }; }

  beginTick() { this.rec = null; this._views = new WeakMap(); this.tickNo = (this.tickNo || 0) + 1; }

  _record(map, list, m, sight, pursuit, home) {
    let r = this.rec;
    if (!r) r = this.rec = { tickNo: this.tickNo, scenes: [], sceneOf: new Map(), players: [], pl: [], pSlot: new Map(), monsters: [], mon: [], mScene: [], mSlot: new Map() };
    if (r.mSlot.has(m)) return;
    let s = r.sceneOf.get(map);
    if (s === undefined) {
      // a scene's players are copied once, when its first monster is recorded, so they are contiguous and in the tick's order;
      // players that join the scene view later in this tick are not in the copy (apply tests them itself)
      s = r.scenes.length; r.sceneOf.set(map, s); r.scenes.push(map);
      const slots = new Map(); r.pSlot.set(map, slots);
      for (const p of list) { if (slots.has(p)) continue; slots.set(p, r.players.length); r.players.push(p); r.pl.push(p.x, p.z); }
    }
    r.mSlot.set(m, r.monsters.length); r.monsters.push(m);
    r.mon.push(m.x, m.z, home?.x, home?.z, sight, pursuit); r.mScene.push(s);
  }

  /** Players of `list` that the latest intents do not cover: not copied for this scene, or moved more than PLAYER_MARGIN. */
  _extras(L, map, list, epoch) {
    let v = this._views.get(list);
    if (v && v.epoch === epoch && v.L === L) return v;
    // at[copy slot] = the player's index in today's list when the copy still covers them, else -1
    const slots = L.pSlot.get(map), at = new Int32Array(L.players.length).fill(-1), extras = [];
    let ordered = true, last = -1;
    for (let i = 0; i < list.length; i++) {
      const p = list[i], k = slots?.get(p);
      if (k === undefined) { extras.push(i); continue; }
      const dx = p.x - L.pl[2 * k], dz = p.z - L.pl[2 * k + 1];
      if (!(dx * dx + dz * dz <= this.PM2)) { extras.push(i); continue; }
      if (at[k] !== -1) continue;   // a player listed twice: the first index is the one the inline scan meets first
      at[k] = i; if (k < last) ordered = false; last = k;
    }
    v = { epoch, L, at, extras, ordered };
    this._views.set(list, v);
    if (extras.length) this.counters.extras += extras.length;
    return v;
  }

  /**
   * The tick's SIGHT_IN scan for monster m: returns the target (a player or null) decided from Mind's intent, or undefined
   * when the tick must run its own scan. `pred` is the tick's own acquisition rule; `epoch` changes whenever the tick says
   * player positions may have moved (its playerGrids reset).
   */
  acquire(map, list, m, sight, pursuit, home, pred, epoch) {
    if (this.failed) return undefined;
    if (list.length < this.minPlayers) return undefined;
    const t0 = performance.now();
    this._record(map, list, m, sight, pursuit, home);
    let L = this.latest;
    // intents older than MAX_AGE ticks are not used: players have drifted, extras would grow, and the inline scan is cheaper
    if (L && this.tickNo - L.tickNo > this.maxAge) L = null;
    let out;
    const i = L ? L.mSlot.get(m) : undefined;
    if (i !== undefined && L.scenes[L.mScene[i]] === map) {
      const o = 6 * i, mon = L.mon;
      const dx = m.x - mon[o], dz = m.z - mon[o + 1];
      if (dx * dx + dz * dz <= this.MM2 && home && home.x === mon[o + 2] && home.z === mon[o + 3] && sight === mon[o + 4] && pursuit === mon[o + 5]) {
        const v = this._extras(L, map, list, epoch), order = [], cand = L.cand, va = v.at;
        for (let k = L.cOff[i], e = L.cOff[i + 1]; k < e; k++) { const a = va[cand[k]]; if (a >= 0) order.push(a); }
        if (v.extras.length) { for (const a of v.extras) order.push(a); order.sort((a, b) => a - b); }
        else if (!v.ordered) order.sort((a, b) => a - b);
        out = null;
        for (const at of order) { const p = list[at]; if (pred(p)) { out = p; break; } }
        this.counters.used++;
      }
    }
    if (out === undefined) this.counters.fallback++;
    this.counters.realmMs += performance.now() - t0;
    return out;
  }

  /** End of the monster pass: send this tick's copy to the worker (at most one copy in flight; a busy worker skips a tick). */
  endTick(now = Date.now()) {
    const r = this.rec; this.rec = null;
    if (r && !this.failed) {
      if (this.inFlight) this.counters.skipped++;
      else {
        r.gen = ++this.gen;
        const sOff = new Int32Array(r.scenes.length + 1);
        // scenes were appended in order; scene s starts at the first player copied for it
        for (let s = 0, at = 0; s < r.scenes.length; s++) { sOff[s] = at; at += r.pSlot.get(r.scenes[s]).size; sOff[s + 1] = at; }
        const mon = Float64Array.from(r.mon), mScene = Int32Array.from(r.mScene), pl = Float64Array.from(r.pl);
        r.mon = mon; r.pl = pl;
        this.inFlight = r; this.counters.posted++;
        // the worker gets its own copies (the typed arrays above stay with Realm for the apply checks)
        this.worker.postMessage({ op: 'plan', gen: r.gen, mon: mon.slice(), mScene, sOff, pl: pl.slice() }, [mScene.buffer, sOff.buffer]);
      }
    }
    if (now - this._statsAt >= 1000) { this._statsAt = now; try { pipelineClient()?.stats('stats.mind', this.stats()); } catch {} }
  }
}
