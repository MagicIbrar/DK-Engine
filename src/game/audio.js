// Sound: background music per map (script/bgsound.csv playlists) and positional sound effects, all
// resolved through gamedata/sound.json (docs/formats/sound.md). Files are served from /sound/<path>.
//
// * BGM: two <audio> elements cross-fade. A map lists a playlist (sound.json bgmByMapIndex[map] =
//   [{path, delayMs, playCount, fadeMs, repeat}]); like the client we pick an entry at random, start it
//   after delayMs, play it playCount times and, if repeat, pick the next one when it ends. The lists include
//   bgm_silent_* tracks, which give the natural pauses between songs.
// * SFX: Web Audio buffers (decoded once, cached), a voice pool (oldest voice is stopped when full), distance
//   attenuation in the FILE frame from the player (sound.json range = audible radius in metres) and stereo
//   panning from the camera's right vector.
// * Browsers block audio until a user gesture: the AudioContext is resumed and pending music started on the
//   first pointerdown/keydown.
import { soundURL, cachedAssetRequest } from '../engine/assets.js';
import { classDefOf, monsterDef, weaponSound } from '../ui/gameinfo.js';

const MAX_VOICES = 24;
const DEFAULT_RANGE = 25;
const DEFAULT_FADE_MS = 1800;
const SAME_SOUND_GAP = 0.045;   // s: identical sounds closer than this are merged
const MONSTER_IDLE_MIN = 5, MONSTER_IDLE_MAX = 11;

/**
 * Distance gain: 1 at the listener, smooth fall-off to 0 at `range` (metres).
 * g = (1 - d/range)^2 â€” close to the client's linear-in-dB roll-off for the short ranges it uses (10-50 m).
 */
export function distanceGain(d, range = DEFAULT_RANGE) {
  const r = Math.max(0.5, Number(range) || DEFAULT_RANGE);
  if (!(d >= 0)) return 1;
  if (d >= r) return 0;
  const k = 1 - d / r;
  return k * k;
}

/** Pick the next playlist entry at random, avoiding an immediate repeat when possible. */
export function pickTrack(list, lastPath = null, rnd = Math.random) {
  const usable = (list || []).filter(e => e && e.path && !e.missing);
  if (!usable.length) return null;
  const different = usable.filter(e => e.path !== lastPath);
  const pool = different.length ? different : usable;
  return pool[Math.min(pool.length - 1, Math.floor(rnd() * pool.length))];
}

function pickOne(list) {
  if (!Array.isArray(list) || !list.length) return null;
  return list[Math.floor(Math.random() * list.length)];
}

export class Audio {
  constructor(game) {
    this.game = game;
    this.volumes = { music: 0.5, sfx: 0.7 };
    this.ctx = null;
    this.master = null;
    this.sfxBus = null;
    this._buffers = new Map();
    this._bufferFailures = new Map();
    this._voices = [];
    this._recent = new Map();   // path -> request identity and context start time
    this._exclusive = new Map(); // voice-line lockouts from effectdata lenMs
    this._pendingSfx = new Set();
    this._sfxGeneration = 0;
    this._disposed = false;
    this._off = [];
    this._stepDist = 0;
    this._stepFoot = 0;
    this._stepRequest = 0;
    this._lastPos = null;
    this._idleTimer = 4;
    this._unlocked = false;
    this._attackAt = new WeakMap(); // actor -> time its attack sound was started by an 'attack' event
    this._deathSounded = new WeakSet();
    this.music = { els: [], cur: -1, list: [], entry: null, mapIndex: null, timer: null, plays: 0, fade: null, pending: null, failures: new Map() };
    this._initContext();
    this._initMusic();
    this._installUnlock();
    this._wire();
  }

  get S() { return this.game?.data?.sound || null; }

  // ------------------------------------------------------------------------------------------ setup
  _initContext() {
    const AC = globalThis.AudioContext || globalThis.webkitAudioContext;
    if (!AC) return;
    try {
      this.ctx = new AC({ latencyHint: 'interactive' });
      this.master = this.ctx.createGain();
      this.master.connect(this.ctx.destination);
      this.sfxBus = this.ctx.createGain();
      this.sfxBus.gain.value = this.volumes.sfx;
      this.sfxBus.connect(this.master);
    } catch (err) {
      console.warn('[audio] no Web Audio', err);
      this.ctx = null;
    }
  }

  _initMusic() {
    const doc = globalThis.document;
    if (!doc?.createElement) return;
    for (let i = 0; i < 2; i++) {
      const el = doc.createElement('audio');
      el.preload = 'auto';
      el.loop = false;
      el.volume = 0;
      el._fade = 0;          // 0..1 cross-fade factor
      el.addEventListener?.('ended', () => this._onTrackEnded(el));
      el.addEventListener?.('error', () => { if (el === this.music.els[this.music.cur]) this._onTrackEnded(el, true); });
      this.music.els.push(el);
    }
  }

  _installUnlock() {
    const unlock = () => {
      this._unlocked = true;
      if (this.ctx && this.ctx.state === 'suspended') this.ctx.resume().catch(() => {});
      const p = this.music.pending;
      if (p) { this.music.pending = null; this._playEl(p); }
      if (this.ctx?.state !== 'suspended' && !this.music.pending) {
        globalThis.removeEventListener?.('pointerdown', unlock, true);
        globalThis.removeEventListener?.('keydown', unlock, true);
      }
    };
    this._unlock = unlock;
    globalThis.addEventListener?.('pointerdown', unlock, true);
    globalThis.addEventListener?.('keydown', unlock, true);
  }

  // ------------------------------------------------------------------------------------------ volumes
  setVolumes({ music, sfx } = {}) {
    const previousSfx = this.volumes.sfx;
    if (Number.isFinite(Number(music))) this.volumes.music = Math.max(0, Math.min(1, Number(music)));
    if (Number.isFinite(Number(sfx))) this.volumes.sfx = Math.max(0, Math.min(1, Number(sfx)));
    if (previousSfx > 0 && this.volumes.sfx <= 0) this.cancelPendingSfx();
    if (this.sfxBus) this.sfxBus.gain.value = this.volumes.sfx;
    for (const el of this.music.els) el.volume = this._musicVol(el);
  }

  _musicVol(el) {
    return Math.max(0, Math.min(1, this.volumes.music * (el._fade ?? 0)));
  }

  // ------------------------------------------------------------------------------------------ music
  /** Start the map's playlist (cross-fading from whatever plays now). Same map + still playing = no-op. */
  playBGM(mapIndex) {
    if (this._disposed) return;
    const S = this.S;
    const list = (S?.bgmByMapIndex?.[String(mapIndex)] || []).filter(e => e && e.path && !e.missing);
    const M = this.music;
    const playing = M.cur >= 0 && M.els[M.cur] && !M.els[M.cur].paused;
    if (M.mapIndex === mapIndex && (playing || M.timer)) return;
    M.mapIndex = mapIndex;
    M.list = list;
    if (!list.length) { this.stopBGM(); return; }
    // keep the current song if the new map lists it too (e.g. revive into the same region)
    if (playing && M.entry && list.some(e => e.path === M.entry.path)) return;
    this._nextTrack(true);
  }

  stopBGM(fadeMs = DEFAULT_FADE_MS) {
    const M = this.music;
    clearTimeout(M.timer); M.timer = null;
    M.entry = null;
    M.pending = null;
    for (const el of M.els) this._fadeEl(el, 0, fadeMs, true);
    M.cur = -1;
  }

  _nextTrack(first = false) {
    const M = this.music;
    clearTimeout(M.timer); M.timer = null;
    // On entering a map start with a real song; the bgm_silent_* entries only space out the later picks.
    const available = M.list.filter(e => (M.failures.get(e.path) || 0) <= Date.now());
    const audible = available.filter(e => !/silent/i.test(e.path));
    const entry = pickTrack(first && audible.length ? audible : available, M.entry?.path);
    if (!entry) { this.stopBGM(); return; }
    M.entry = entry;
    M.plays = 0;
    const delay = first ? Math.min(Number(entry.delayMs) || 0, 1500) : Number(entry.delayMs) || 0;
    const mapAtStart = M.mapIndex;
    // fade the old track out right away; start the new one after its delay
    for (const el of M.els) if (!el.paused) this._fadeEl(el, 0, DEFAULT_FADE_MS, true);
    M.timer = setTimeout(() => {
      M.timer = null;
      if (M.mapIndex !== mapAtStart || M.entry !== entry) return;
      this._startEntry(entry);
    }, delay);
  }

  _startEntry(entry) {
    const M = this.music;
    if (this._disposed || !M.els.length || M.entry !== entry) return;
    const next = (M.cur + 1) % M.els.length;
    const el = M.els[next];
    const prev = M.els[M.cur];
    M.cur = next;
    el.src = soundURL(entry.path);
    el.currentTime = 0;
    el._fade = 0;
    el.volume = 0;
    el._entry = entry;
    if (prev && prev !== el && !prev.paused) this._fadeEl(prev, 0, DEFAULT_FADE_MS, true);
    this._playEl(el);
    this._fadeEl(el, 1, Number(entry.fadeMs ?? DEFAULT_FADE_MS), false);
  }

  _playEl(el) {
    const entry = el._entry;
    const current = () => !this._disposed && this.music.els[this.music.cur] === el && this.music.entry === entry;
    try {
      const p = el.play();
      if (p?.catch) p.catch(err => { if (current() && err?.name === 'NotAllowedError') this.music.pending = el; });
    } catch { if (current()) this.music.pending = el; }
  }

  _onTrackEnded(el, error = false) {
    const M = this.music;
    if (el !== M.els[M.cur] || !M.entry) return;
    // A missing/unplayable playlist must not cycle forever through failed URLs.
    // A later map/music request may retry transient failures after this backoff.
    if (error) M.failures.set(M.entry.path, Date.now() + 30000);
    M.plays++;
    const count = Math.max(1, Number(M.entry.playCount) || 1);
    if (!error && M.plays < count) { el.currentTime = 0; this._playEl(el); return; }
    if (error || Number(M.entry.repeat ?? 1)) this._nextTrack(false);
  }

  _fadeEl(el, to, ms, pauseAtEnd) {
    clearInterval(el._fadeTimer);
    el._fadeTimer = null;
    if (ms <= 0) {
      el._fade = to; el.volume = this._musicVol(el);
      if (pauseAtEnd && to === 0) { try { el.pause(); } catch { /* ignore */ } }
      return;
    }
    const from = el._fade ?? 0;
    const t0 = Date.now();
    const dur = Math.max(1, ms);
    const step = () => {
      const k = Math.min(1, (Date.now() - t0) / dur);
      el._fade = from + (to - from) * k;
      el.volume = this._musicVol(el);
      if (k >= 1) {
        clearInterval(el._fadeTimer); el._fadeTimer = null;
        if (pauseAtEnd && to === 0) { try { el.pause(); } catch { /* ignore */ } }
      }
    };
    step();
    if (to !== el._fade) el._fadeTimer = setInterval(step, 50);
  }

  // ------------------------------------------------------------------------------------------ sfx
  _buffer(path) {
    if (!this.ctx) return Promise.resolve(null);
    return cachedAssetRequest(this._buffers, this._bufferFailures, path, async () => {
      const res = await fetch(soundURL(path));
      if (!res.ok || res.status === 204 || res.headers?.get?.('X-Missing')) {
        throw Object.assign(new Error(`sound request failed (${res.status}): ${path}`), {
          missing: res.status === 404 || res.status === 204 || !!res.headers?.get?.('X-Missing'),
        });
      }
      return this.ctx.decodeAudioData(await res.arrayBuffer());
    }).catch(() => null);
  }

  /** Listener (player) position in the FILE frame. */
  _listener() {
    const p = this.game?.player;
    return p ? { x: p.x, z: p.z } : null;
  }

  /** Gain and stereo pan for a FILE-frame point. */
  spatial(at, range) {
    const L = this._listener();
    if (!at || !L) return { gain: 1, pan: 0 };
    const dx = at.x - L.x, dz = at.z - L.z;
    const d = Math.hypot(dx, dz);
    const gain = distanceGain(d, range);
    let pan = 0;
    const cam = this.game?.camera;
    if (cam?.matrixWorld && d > 0.5) {
      const e = cam.matrixWorld.elements;          // camera right = column 0 (THREE space)
      const rx = e[0], rz = -e[2];                   // -> FILE frame (z mirrored)
      const rl = Math.hypot(rx, rz) || 1;
      pan = Math.max(-0.75, Math.min(0.75, ((dx * rx + dz * rz) / (d * rl)) * Math.min(1, d / 4)));
    }
    return { gain, pan };
  }

  /**
   * Play a sound file (path relative to /sound/). opts: { volume (0..1.8), at: FILE {x,z} (positional),
   * range (m), delayMs, loop, rate }. Resolves a handle { stop() } or null.
   */
  sfx(path, opts = {}) {
    if (this._disposed || !path || !this.ctx || this.volumes.sfx <= 0) return Promise.resolve(null);
    const { volume = 1, at = null, range = DEFAULT_RANGE, delayMs = 0, loop = false, rate = 1, exclusiveMs = 0, mixGain = null, isCurrent = null, stateBound = false, category = null } = opts;
    if (isCurrent && !isCurrent()) return Promise.resolve(null);
    const categoryGain = () => mixGain ? mixGain() : 1;
    const sp = this.spatial(at, range);
    const gain = volume * sp.gain * categoryGain();
    if (gain < 0.01) return Promise.resolve(null);
    const now = this.ctx.currentTime;
    const startAt = now + Math.max(0, delayMs) / 1000;
    if ((this._exclusive.get(path)?.until ?? -Infinity) > startAt) return Promise.resolve(null);
    const last = this._recent.get(path);
    if (last != null && Math.abs(startAt - last.startAt) < SAME_SOUND_GAP) return Promise.resolve(null);
    const recent = { startAt };
    this._recent.set(path, recent);
    const reservation = exclusiveMs > 0 ? { until: startAt + exclusiveMs / 1000 } : null;
    if (reservation) this._exclusive.set(path, reservation);
    if (this._recent.size > 256) this._recent.clear();
    const context = this.ctx, world = this.game?.world, generation = this._sfxGeneration;
    let admittedVoice = null;
    const release = () => {
      if (reservation && this._exclusive.get(path) === reservation) this._exclusive.delete(path);
      if (this._recent.get(path) === recent) this._recent.delete(path);
    };
    const pending = { category, release, cancelled: false };
    this._pendingSfx.add(pending);
    return this._buffer(path).then(buf => {
      this._pendingSfx.delete(pending);
      if (pending.cancelled || !buf || this._disposed || this.ctx !== context || context.state === 'closed' || this.volumes.sfx <= 0 || generation !== this._sfxGeneration || this.game?.world !== world || (isCurrent && !isCurrent())) { release(); return null; }
      // Loading may finish after the listener has moved; use the arrival-time mix.
      const currentSpatial = this.spatial(at, range);
      if (volume * currentSpatial.gain * categoryGain() < 0.01) { release(); return null; }
      const src = this.ctx.createBufferSource();
      src.buffer = buf;
      src.loop = !!loop;
      src.playbackRate.value = rate;
      const g = this.ctx.createGain();
      g.gain.value = Math.min(1.8, volume * currentSpatial.gain * categoryGain());
      let node = src;
      node.connect(g);
      node = g;
      let pn = null;
      if (this.ctx.createStereoPanner && at) {
        pn = this.ctx.createStereoPanner();
        pn.pan.value = currentSpatial.pan;
        node.connect(pn);
        node = pn;
      }
      node.connect(this.sfxBus);
      const voice = admittedVoice = { src, gain: g, panner: pn, path, t: startAt, at, range, base: volume, loop: !!loop, mixGain, stateBound };
      while (this._voices.length >= MAX_VOICES) this._stopVoice(this._voices[0]);
      this._voices.push(voice);
      src.onended = () => this._dropVoice(voice);
      const actualStart = Math.max(this.ctx.currentTime, startAt);
      if (reservation) reservation.until = actualStart + exclusiveMs / 1000;
      src.start(actualStart);
      return { stop: () => this._stopVoice(voice), voice };
    }).catch(() => { this._pendingSfx.delete(pending); if (admittedVoice) this._stopVoice(admittedVoice); release(); return null; });
  }

  /** Drop queued loads at a mute boundary without stopping admitted voices/loops. */
  cancelPendingSfx(category = null) {
    for (const pending of this._pendingSfx) {
      if (category != null && pending.category !== category) continue;
      pending.cancelled = true;
      pending.release();
      this._pendingSfx.delete(pending);
    }
  }

  /** Play a sound.json sfx record ({path, vol, range, delayMs, loop, positional}). */
  play(rec, opts = {}) {
    if (!rec?.path) return Promise.resolve(null);
    const positional = rec.positional !== false && opts.at;
    return this.sfx(rec.path, {
      volume: (Number(rec.vol ?? 100) / 100) * (opts.volume ?? 1),
      at: positional ? opts.at : null,
      range: rec.range || opts.range || DEFAULT_RANGE,
      delayMs: (Number(rec.delayMs) || 0) + (Number(opts.delayMs) || 0),
      loop: opts.loop ?? !!rec.loop,
      exclusiveMs: rec.exclusive ? Math.max(0, Number(rec.lenMs) || 0) : 0,
      mixGain: opts.mixGain,
      isCurrent: opts.isCurrent ? () => opts.isCurrent(rec) : null,
      stateBound: rec.unkFlag === 0,
      category: opts.category,
    });
  }
  playAll(list, opts) {
    return Array.isArray(list) ? Promise.all(list.map(r => this.play(r, opts).then(handle => {
      opts?.onHandle?.(handle);
      return handle;
    }))) : Promise.resolve([]);
  }
  playOne(list, opts) { const r = pickOne(list); if (r) this.play(r, opts); }

  _stopVoice(v) {
    try { v.src.stop(); } catch { /* already stopped */ }
    this._dropVoice(v);
  }
  _dropVoice(v) {
    const i = this._voices.indexOf(v);
    if (i >= 0) this._voices.splice(i, 1);
    for (const node of [v.src, v.gain, v.panner]) { try { node?.disconnect(); } catch { /* ignore */ } }
  }

  /** Invalidate decoded/scheduled sounds and stride state at travel boundaries. */
  resetWorldAudio() {
    this._sfxGeneration++;
    this.cancelPendingSfx();
    for (const voice of [...this._voices]) this._stopVoice(voice);
    this._recent.clear(); this._exclusive.clear();
    this._lastPos = null; this._stepDist = 0; this._stepFoot = 0;
    this._stepRequest++;
    this._attackAt = new WeakMap();
    this._deathSounded = new WeakSet();
  }

  /** UI sounds by sound.json ui key: buttonMain, buttonCommon, buttonExit, boxOpen, boxClose, lackOfMana, ... */
  ui(key) {
    const list = this.S?.ui?.[key];
    if (list) this.playAll(list, { volume: 0.8 });
  }

  /** NPC greeting voice (sound.json npcVoice[npc index]) when a dialog opens. */
  npcGreeting(npcIndex, npc) {
    const list = this.S?.npcVoice?.[String(npcIndex)];
    if (list) this.playOne(list, { at: npc ? { x: npc.x, z: npc.z } : null });
  }

  /** Item use (soundscript code 13: sound.json item.use[item Index]). */
  itemUse(item) {
    const list = this.S?.item?.use?.[String(item?.itemIndex ?? item?.index)];
    if (list) this.playOne(list);
  }

  // ------------------------------------------------------------------------------------------ game hooks
  _monSfx(actor) {
    const S = this.S;
    if (!S) return null;
    const d = monsterDef(actor);
    const idx = d?.index ?? actor?.monsterIndex ?? actor?.index;
    let key = idx != null ? S.monsterSfxIndex?.[String(idx)] : null;
    if (!key && d?.shape) key = String(d.shape).toLowerCase();
    return key ? S.monsterSfx?.[key] || null : null;
  }

  /** Native soundscript0/event/2/servantIndex, invoked by an accepted servant
   * clip. Action-scene sounds own identical paths. As with monster voices,
   * attack-voice chance/variant selection is engine policy, not native data. */
  servantClip(actor,state,{excluded=new Set(),isCurrent=()=>true,onHandle}={}) {
    const bank=this.S?.summonSfx?.[`2:${actor?.servantIndex}`];
    const event=state==='idle'||state==='idleCombat'?'idle':state==='hit'?'hit':state==='die'?'die':state==='attack'||state==='skill'?'attackVoice':null;
    if(!bank||!event||actor.disposed||!isCurrent())return Promise.resolve([]);
    if(event==='attackVoice'&&Math.random()>=.35)return Promise.resolve([]);
    if(event==='die'){if(this._deathSounded.has(actor))return Promise.resolve([]);this._deathSounded.add(actor);}
    else if(!actor.dead)this._deathSounded.delete(actor);
    let rows=(bank[event]||[]).filter(r=>!excluded.has(String(r.path||'').replace(/\\/g,'/').replace(/^sound\//i,'').toLowerCase()));
    if(event==='attackVoice'&&rows.length)rows=[pickOne(rows)];
    return this.playAll(rows,{at:this._at(actor),category:'servant',isCurrent,onHandle});
  }

  _material(actor, m) {
    if (m?.material) return m.material;
    const code = monsterDef(actor)?.material;
    return code != null ? this.S?.codes?.material?.[String(code)] || null : null;
  }

  _pc(actor = this.game.player) {
    const c = actor?.classDef || classDefOf(this.game);
    return this.S?.pcSfx?.[String(c?.index ?? actor?.classIndex ?? actor?.save?.classIndex ?? this.game?.save?.classIndex ?? 0)] || null;
  }

  _weapon(actor) {
    const visible = actor?.save?.equipment?.weapon;
    if (visible?.none) return 'fist';
    const db = this.game?.items?.db;
    const itemIndex = visible?.itemIndex ?? (actor === this.game.player ? this.game.items?.equip?.get?.(4)?.itemIndex : null);
    const rule = itemIndex != null ? db?.weaponRule?.(db.def?.(itemIndex)) : null;
    return rule?.name ? weaponSound({ weapon: { type: rule.name } }) : weaponSound(actor?.classDef || classDefOf(this.game));
  }

  _at(a) { return a ? { x: a.x, z: a.z } : null; }

  _now() { return Number.isFinite(this.game?.time) ? this.game.time : performance.now() / 1000; }

  /** True when an 'attack' event already played this actor's swing/attack sound for the current blow. */
  _recentlyAttacked(a) {
    const t = this._attackAt.get(a);
    const elapsed = this._now() - t;
    return t != null && elapsed >= 0 && elapsed < 1.5;
  }

  _onDeath(actor) {
    // Servant voices belong to the accepted die clip, which can start after
    // this synchronous death/damage event. Do not consume its death epoch here.
    if (!actor || !['player','monster'].includes(actor.kind) || this._deathSounded.has(actor)) return;
    this._deathSounded.add(actor);
    if (actor.kind === 'player') this.playAll(this._pc(actor)?.die, { at: actor === this.game.player ? null : this._at(actor) });
    else if (actor.kind === 'monster') this.playAll(this._monSfx(actor)?.die, { at: this._at(actor) });
  }

  _wire() {
    const ev = this.game?.events;
    if (!ev?.on) return;
    const on = (t, fn) => this._off.push(ev.on(t, e => { try { fn(e || {}); } catch (err) { console.warn('[audio]', t, err); } }));
    on('map', () => this.resetWorldAudio());
    on('teleport', () => this.resetWorldAudio());
    on('damage', e => this._onDamage(e));
    // Online damage is deliberately cosmetic and uses a separate event channel.
    on('server:damage', e => this._onDamage({ ...e, suppressSwing: true }));
    on('death', ({ actor }) => this._onDeath(actor));
    on('levelup', () => this.playAll(this._pc()?.levelUp));
    // (the skills system's effect player plays skill sounds from the effect scenes itself: game.effects.soundOn)
    on('skill', ({ actor, skill }) => { if (actor && skill && actor === this.game.player && !this.game.effects?.soundOn) this.playSkill(skill, actor); });
    on('loot', ({ name }) => {
      const it = this.S?.item;
      const dil = /^dil$/i.test(String(name || ''));
      this.playOne(it?.pick?.[dil ? '44' : '0'] || it?.get?.[dil ? '44' : '0']);
    });
    on('revive', () => { this._wasDead = false; this._deathSounded.delete(this.game.player); this.playAll(this._pc()?.revive); });
    on('itemuse', ({ item }) => this.itemUse(item));
    // controller: {actor: player, target, step}; ai: {actor: monster, target, attackKey}
    on('attack', ({ actor, attackKey, step, index }) => {
      const idx = index ?? (attackKey != null ? this.game.data?.monsters?.attackActionIndex?.[attackKey] : null) ?? step ?? 0;
      this.attackStart(actor, idx);
    });
    on('server:attack', ({ actor, index }) => { if (actor !== this.game.player) this.attackStart(actor, index ?? 0); });
  }

  /**
   * Hit sounds (sound.md "hit"): the player's weapon swing, impact[weapon][monster material] + monsterCut[material]
   * when it lands, block[weapon][material] when guarded; the victim's defeat voice (monster hit / pc hit).
   * Monster attack sounds normally start with the 'attack' event (attack animation start); a damage without a
   * preceding 'attack' event (scripted damage) plays them here instead.
   */
  _onDamage({ source, target, crit, miss, guard, dot, skill, suppressSwing = false }) {
    const p = this.game.player;
    if (!target) return;
    if (!target.dead) this._deathSounded.delete(target);
    // Shared snapshots set lethal victims dead before cosmetic damage is delivered.
    if (this.game.save?.authority === 'server' && target.dead) this._onDeath(target);
    const hitAt = this._at(target);
    const S = this.S;
    // attacker side
    if (source && source.kind === 'monster' && !dot && !this._recentlyAttacked(source)) {
      const m = this._monSfx(source);
      const atk = m?.attack;
      if (Array.isArray(atk) && atk.length) this.playAll(atk[Math.floor(Math.random() * atk.length)], { at: this._at(source) });
    }
    if (source?.kind === 'player' && !dot) {
      const w = this._weapon(source);
      if (!skill && !suppressSwing && !this._recentlyAttacked(source)) this.playOne(S?.hit?.swing?.[w], { at: hitAt, volume: 0.9 });
      if (!miss && target.kind === 'monster') {
        const m = this._monSfx(target);
        const mat = this._material(target, m) || 'norm';
        if (guard) this.playOne(S?.hit?.block?.[w]?.[mat] || S?.hit?.block?.[mat]?.[w], { at: hitAt });
        else {
          this.playOne(S?.hit?.impact?.[w]?.[mat] || S?.hit?.impact?.[w]?.norm, { at: hitAt, volume: skill ? 0.7 : 1 });
          this.playOne(S?.hit?.monsterCut?.[mat], { at: hitAt, volume: crit ? 1 : 0.7 });
        }
      }
    }
    // victim side
    if (miss || dot || target.dead) return;
    if (target.kind === 'player') this.playAll(this._pc(target)?.hit, { at: target === p ? null : hitAt, volume: crit ? 1.1 : 0.9 });
    else if (target.kind === 'monster' && !target.dead) this.playAll(this._monSfx(target)?.hit, { at: hitAt });
  }

  /**
   * An attack animation started ('attack' event). Monsters: sound.json monsterSfx attack[ATTACK action index]
   * (+ occasional attack voice). Player: weapon swing variant for the combo step (+ occasional class voice).
   */
  attackStart(actor, index = 0) {
    if (!actor) return;
    const at = this._at(actor);
    if (actor.kind === 'monster') {
      const m = this._monSfx(actor);
      const atk = m?.attack;
      const list = Array.isArray(atk) && atk.length ? atk[Math.max(0, Math.min(atk.length - 1, Number(index) || 0))] : null;
      if (list) this.playAll(list, { at });
      if (m?.attackVoice && Math.random() < 0.35) this.playOne(m.attackVoice, { at });
      this._attackAt.set(actor, this._now());
    } else if (actor.kind === 'player') {
      const list = this.S?.hit?.swing?.[this._weapon(actor)];
      if (Array.isArray(list) && list.length) this.play(list[(Number(index) || 0) % list.length], { at, volume: 0.9 });
      if (Math.random() < 0.3) this.playOne(this._pc(actor)?.attackVoice, { at: actor === this.game.player ? null : at });
      this._attackAt.set(actor, this._now());
    }
  }

  /**
   * Skill sounds: every step's action Effect id -> actionEffectSfx.pc[id] (started with the step), and the
   * result's hit effect -> skill[id].scenes[scene] (at the step's hit timing).
   */
  playSkill(skill, actor) {
    const S = this.S;
    if (!S || !skill) return;
    const at = this._at(actor);
    let t = 0;
    for (const st of skill.steps || []) {
      const eff = st.anim?.effect;
      if (eff != null) this.playAll(S.actionEffectSfx?.pc?.[String(eff)], { at, delayMs: t });
      const he = st.result?.hitEffect;
      if (he?.id != null) {
        const sc = S.skill?.[String(he.id)]?.scenes;
        const list = sc?.[String(he.scene ?? 1)] || (sc ? Object.values(sc)[0] : null);
        const hitDelay = t + Number(st.anim?.timing ?? 0.5) * Number(st.durationMs ?? 600);
        this.playAll(list, { at: actor?.target ? this._at(actor.target) : at, delayMs: hitDelay });
      }
      t += Number(st.durationMs) || 0;
    }
  }

  // ------------------------------------------------------------------------------------------ per frame
  update(dt) {
    dt = Number(dt) || 0;
    const g = this.game, p = g?.player;
    if (!p || !this.ctx || this._disposed) return;
    // revive voice when the player comes back to life (game.revive() emits no event)
    if (this._wasDead && !p.dead) { this._deathSounded.delete(p); this.playAll(this._pc()?.revive); }
    this._wasDead = !!p.dead;
    // Refresh active positional voices and category gains, including muted loops.
    for (const v of this._voices) {
      const sp = this.spatial(v.at, v.range);
      v.gain.gain.value = Math.min(1.8, v.base * sp.gain * (v.mixGain ? v.mixGain() : 1));
      if (v.panner) v.panner.pan.value = sp.pan;
    }
    this._footsteps(dt, p);
    this._monsterIdle(dt);
  }

  _footsteps(dt, p) {
    const last = this._lastPos;
    this._lastPos = { x: p.x, z: p.z };
    if (!last || p.dead || dt <= 0) { this._stepRequest++; return; }
    const d = Math.hypot(p.x - last.x, p.z - last.z);
    if (d > 5) { this._stepDist = 0; this._stepFoot = 0; this._stepRequest++; return; } // teleport
    const speed = d / dt;
    if (speed < 0.4) { this._stepDist = 0; this._stepRequest++; return; }
    const run = speed > 2.7;
    // one step per half cycle: run 3.45 m / cycle, walk ~1.8 m / cycle (classes.json speedFromRootMotion)
    const stride = run ? 1.72 : 0.9;
    this._stepDist += d;
    if (this._stepDist < stride) return;
    this._stepDist -= stride;
    const fs = this.S?.footsteps?.[run ? 'run' : 'walk'];
    // ENGINE-CHOSEN binding: native soundscript code2 shares the boots' item
    // Quality/sound-class enum. Costumes never change the equipment sound.
    const boots = this.game.save?.equipment?.boots ?? p.save?.equipment?.boots;
    const def = boots?.itemIndex ? this.game.items?.db?.def(boots.itemIndex) : null;
    const armorCode = def && Object.hasOwn(fs || {}, String(def.quality)) ? String(def.quality) : '0';
    const armor = fs?.[armorCode] || fs?.['0'];
    const ground = this.game.world?.groundTypeAt?.(p.x, p.z) || 'soil';
    const pair = armor?.[ground] || armor?.soil;
    if (!pair) return;
    const request = ++this._stepRequest;
    this.play(pair[this._stepFoot % pair.length], { volume: 0.45,
      isCurrent: () => request === this._stepRequest && this.game.player === p && !p.dead && !this.game.paused });
    this._stepFoot ^= 1;
  }

  _monsterIdle(dt) {
    this._idleTimer -= dt;
    if (this._idleTimer > 0) return;
    this._idleTimer = MONSTER_IDLE_MIN + Math.random() * (MONSTER_IDLE_MAX - MONSTER_IDLE_MIN);
    const p = this.game.player;
    let mons = [];
    try { mons = this.game.spawner?.monsters || []; } catch { mons = []; }
    const near = mons.filter(m => m && !m.dead && Math.hypot(m.x - p.x, m.z - p.z) < 18);
    const m = pickOne(near);
    if (m) this.playAll(this._monSfx(m)?.idle, { at: this._at(m), volume: 0.8 });
  }

  dispose() {
    if (this._disposed) return;
    this._disposed = true;
    for (const off of this._off) { try { off?.(); } catch { /* ignore */ } }
    this._off = [];
    this.stopBGM(0);
    this.resetWorldAudio();
    globalThis.removeEventListener?.('pointerdown', this._unlock, true);
    globalThis.removeEventListener?.('keydown', this._unlock, true);
    try { this.ctx?.close(); } catch { /* ignore */ }
  }
}
