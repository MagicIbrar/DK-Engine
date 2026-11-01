// Day / night (maplist OnedayTime): one continuous world clock for every map.
//
// The original server owns the time of day; every client of a channel sees the same hour, and a map's light file
// (map/light_*.txt, docs/formats/environment.md) is sampled at it. A game day is 240 000 units and lasts
// OnedayTime(Min) real minutes (90 on most maps, 30 on 20 maps). Here the server clock is the local wall clock:
//   game time = (real minutes since the epoch  mod  OnedayTime) / OnedayTime x 240 000
// so the hour is the same after a map change, a reload or a restart, exactly like reconnecting to a live server.
// The environment of the loaded map (world.environment, src/world/environment.js) is driven through its fixedTime.
//
// game.life.clock: { time (0..240000), hour (0..24), minutes, isNight, dayMinutes,
//                    setHour(h) (shifts the clock), freeze(h|null), speed (multiplier), reset() }
// Events: 'life:hour' {hour} once per game hour, 'life:night' {night} when the light key's night flag flips.
import { DAY_UNITS } from '../../formats/environment.js';

const LS = 'dekaron-solo:life:clock:v1';
const load = () => { try { return JSON.parse(localStorage.getItem(LS) || '{}') || {}; } catch { return {}; } };
const store = (v) => { try { localStorage.setItem(LS, JSON.stringify(v)); } catch { /* private mode */ } };

export class WorldClock {
  constructor(game) {
    this.game = game;
    const s = load();
    this.offsetUnits = Number(s.offsetUnits) || 0;   // GM / options shift of the clock
    this.frozen = Number.isFinite(s.frozen) ? s.frozen : null;
    this.speed = Number(s.speed) > 0 ? Number(s.speed) : 1;
    this._speedBase = { real: Date.now(), game: null };
    this.time = 0;
    this._lastHour = -1;
    this._night = null;
  }

  get dayMinutes() {
    const env = this.game.world?.environment;
    const v = Number(env?.dayMinutes) || Number(this.game.world?.info?.row?.['OnedayTime(Min)']) || 90;
    return v > 0 ? v : 90;
  }

  /** Game time units (0..240000) for a real time. */
  timeAt(ms = Date.now()) {
    if (this.frozen != null) return this.frozen;
    const perMs = DAY_UNITS / (this.dayMinutes * 60000);
    let t;
    if (this.speed !== 1) {
      // accelerated clock: continue from the moment the speed was set
      if (this._speedBase.game == null) this._speedBase = { real: ms, game: this._raw(ms, perMs) };
      t = this._speedBase.game + (ms - this._speedBase.real) * perMs * this.speed;
    } else t = this._raw(ms, perMs);
    return ((t % DAY_UNITS) + DAY_UNITS) % DAY_UNITS;
  }
  _raw(ms, perMs) { return ms * perMs + this.offsetUnits; }

  get hour() { return (this.time / DAY_UNITS) * 24; }
  get minutes() { return Math.floor((this.hour % 1) * 60); }
  /** The current light key says night (night-only lights, torches...). */
  get isNight() { return !!this.game.world?.environment?.current?.night; }
  /** "HH:MM" of the game clock. */
  text() { const h = Math.floor(this.hour); return `${String(h).padStart(2, '0')}:${String(this.minutes).padStart(2, '0')}`; }

  /** Move the clock so that it is `h` o'clock now (keeps running). */
  setHour(h) {
    const want = (((Number(h) % 24) + 24) % 24) * (DAY_UNITS / 24);
    this.frozen = null;
    const cur = this.timeAt();
    this.offsetUnits = (this.offsetUnits + want - cur) % DAY_UNITS;
    this._save();
    this.update(0);
  }
  /** Freeze at hour h (null = run). */
  freeze(h) { this.frozen = h == null ? null : (((Number(h) % 24) + 24) % 24) * (DAY_UNITS / 24); this._save(); this.update(0); }
  setSpeed(k) { this.speed = Number(k) > 0 ? Number(k) : 1; this._speedBase = { real: Date.now(), game: null }; this._save(); }
  reset() { this.offsetUnits = 0; this.frozen = null; this.speed = 1; this._save(); this.update(0); }
  _save() { store({ offsetUnits: this.offsetUnits, frozen: this.frozen, speed: this.speed }); }

  update() {
    this.time = this.timeAt();
    const env = this.game.world?.environment;
    if (env) env.fixedTime = this.time;          // environment.update() (world.update, after the systems) samples it
    const hr = Math.floor(this.hour);
    if (hr !== this._lastHour) { this._lastHour = hr; this.game.events?.emit?.('life:hour', { hour: hr }); }
    const night = this.isNight;
    if (night !== this._night) { this._night = night; this.game.events?.emit?.('life:night', { night }); }
  }
}
