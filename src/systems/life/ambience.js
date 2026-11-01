// Ambient sounds per map: the map's .mel (map/<MapEffect>, docs/formats/mel.md) places effect scenes; the sound
// categories are 3 'sound' (104 400 entries: wind, streams, birds, insects, torches, water falls ...) and 4
// 'game_sound' (117). sound.json resolves them: ambient[effectId].scenes[1] (cate 3) and effectSound['4'][id]
// (cate 4) = [{path, vol, range, lenMs}].
// Playback rule (mel.md): the scene is (re)started every period + random(periodRandom) ms while the listener is in
// range; period >= 1 000 000 = start once and keep it looping while in range. Every emitter is a 3-D source at the
// entry position with the unit's audible range (audio.js distance roll-off; loops are re-attenuated as the player
// moves). Only the nearest emitters play (MAX_LOOPS loops + one-shots), the rest wait until they are closer.
// Night-only / day-only emitters: scenes named *_night / animal_night play only while the light key has night=1,
// *_day / bird_day only by day (the client's sn_ names carry it; the data has no other day/night flag).
import { parseMel } from '../../formats/mel.js';
import { mapEnvironmentInfo } from '../../formats/environment.js';
import { fetchBuffer } from '../../engine/assets.js';

const CELL = 32;           // spatial grid cell (units)
const MAX_LOOPS = 10;      // concurrent ambient loops
const SCAN = 0.5;          // s between range scans

export class Ambience {
  constructor(game) {
    this.game = game;
    this.entries = [];
    this.grid = new Map();
    this.loops = new Map();      // entry -> {handle}
    this.map = null;
    this._t = 0;
    this._token = 0;
    this.enabled = true;
  }

  get S() { return this.game.data?.sound || null; }

  async load(mapIndex) {
    this.clear();
    const token = ++this._token;
    const row = this.game.mapRow?.(mapIndex) || this.game.data?.mapByIndex?.(mapIndex);
    if (!row) return;
    let key = '';
    try { key = mapEnvironmentInfo(row)?.files?.mel || ''; } catch { key = ''; }
    if (!key && row.MapEffect) key = `map/${String(row.MapEffect).toLowerCase()}`;
    if (!key) return;
    let mel;
    try { mel = parseMel(await fetchBuffer(key)); } catch { return; }
    if (token !== this._token) return;
    const S = this.S;
    if (!S) return;
    const list = [];
    for (const e of mel.entries) {
      if (e.category !== 3 && e.category !== 4) continue;
      const def = e.category === 3 ? S.ambient?.[String(e.effectId)] : S.effectSound?.['4']?.[String(e.effectId)];
      const sfx = def?.scenes?.['1'] || (def?.scenes ? Object.values(def.scenes)[0] : null);
      if (!Array.isArray(sfx) || !sfx.length) continue;
      const range = Math.max(...sfx.map((s) => Number(s.range) || 10)) * Math.max(0.5, e.scale || 1);
      const name = String(def.name || '').toLowerCase();
      const when = /night/.test(name) ? 'night' : /(_day|bird_day|day_)/.test(name) ? 'day' : null;
      list.push({ x: e.x, z: e.z, sfx, range, period: e.period, rnd: e.dirty ? 0 : e.periodRandom, persistent: e.period >= 1000000,
        next: Math.random() * Math.min(5, (e.period || 3000) / 1000), when, name });
    }
    this.entries = list;
    for (const en of list) {
      const k = `${Math.floor(en.x / CELL)},${Math.floor(en.z / CELL)}`;
      if (!this.grid.has(k)) this.grid.set(k, []);
      this.grid.get(k).push(en);
    }
    this.map = mapIndex;
  }

  _near(x, z, r) {
    const out = [];
    const c0x = Math.floor((x - r) / CELL), c1x = Math.floor((x + r) / CELL);
    const c0z = Math.floor((z - r) / CELL), c1z = Math.floor((z + r) / CELL);
    for (let cx = c0x; cx <= c1x; cx++) for (let cz = c0z; cz <= c1z; cz++) {
      const a = this.grid.get(`${cx},${cz}`);
      if (a) for (const e of a) out.push(e);
    }
    return out;
  }

  update(dt) {
    const p = this.game.player, audio = this.game.audio;
    if (!p || !audio?.sfx || !this.entries.length || !this.enabled) return;
    if ((audio.volumes?.sfx ?? 1) <= 0) return;
    const night = !!this.game.world?.environment?.current?.night;
    // one-shot timers run continuously
    this._t += dt;
    for (const e of this._active || []) {
      if (e.persistent) continue;
      e.next -= dt;
      if (e.next > 0) continue;
      e.next = ((e.period || 3000) + Math.random() * (e.rnd || 0)) / 1000;
      if (Math.hypot(e.x - p.x, e.z - p.z) > e.range) continue;
      if ((e.when === 'night' && !night) || (e.when === 'day' && night)) continue;
      for (const s of e.sfx) audio.play(s, { at: { x: e.x, z: e.z } });
    }
    if (this._t < SCAN) return;
    this._t = 0;
    const cand = this._near(p.x, p.z, 64).filter((e) => Math.hypot(e.x - p.x, e.z - p.z) <= e.range + 2)
      .filter((e) => !((e.when === 'night' && !night) || (e.when === 'day' && night)));
    this._active = cand;
    // loops: keep the nearest MAX_LOOPS
    const loops = cand.filter((e) => e.persistent).sort((a, b) => Math.hypot(a.x - p.x, a.z - p.z) - Math.hypot(b.x - p.x, b.z - p.z)).slice(0, MAX_LOOPS);
    const keep = new Set(loops);
    for (const [e, st] of this.loops) {
      const alive = st.handle && audio._voices?.includes?.(st.handle.voice);
      if (!keep.has(e) || (st.handle && !alive)) { st.handle?.stop?.(); this.loops.delete(e); }
    }
    for (const e of loops) {
      if (this.loops.has(e)) continue;
      const st = { handle: null };
      this.loops.set(e, st);
      const s = e.sfx[0];
      Promise.resolve(audio.play(s, { at: { x: e.x, z: e.z }, loop: true })).then((h) => {
        if (this.loops.get(e) === st) {
          if (h) st.handle = h;
          else this.loops.delete(e); // cancelled/failed loads may retry on a later range scan
        } else h?.stop?.();
      });
      for (const extra of e.sfx.slice(1)) audio.play(extra, { at: { x: e.x, z: e.z } });
    }
  }

  clear() {
    for (const st of this.loops.values()) st.handle?.stop?.();
    this.loops.clear();
    this.entries = [];
    this.grid.clear();
    this._active = [];
    this.map = null;
  }

  dispose() { this.clear(); }
}
