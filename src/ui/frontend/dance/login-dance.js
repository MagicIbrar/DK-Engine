// Login dance (option "Login dance", OFF by default; settings.loginDance + a user-chosen local audio file).
//
// owner timing (2026-10-27): character starts seated on the throne (game mal_chair_sit pose) → login/menu
// loads to 100% → wait preSongSeconds (2 s) → STAND UP → THEN the user's song starts → dance choreography
// on the beat grid → strut back and sit before/as the login UI settles. Song is never bundled (IndexedDB only).
import * as THREE from 'three';
import { DanceRig } from './rig.js';
import { MOVES, evalMove, mixPose } from './moves.js';

const smooth = t => t <= 0 ? 0 : t >= 1 ? 1 : 0.5 - 0.5 * Math.cos(Math.PI * t);

/** song seconds <-> beats on a tracked beat list (piecewise linear, extrapolated at the ends with the mean period). */
export class BeatClock {
  constructor(map) {
    this.beats = map?.beats?.length > 1 ? map.beats : null;
    this.period = 60 / (Number(map?.bpm) || 130);
    if (this.beats) this.period = (this.beats[this.beats.length - 1] - this.beats[0]) / (this.beats.length - 1);
    this.t0 = this.beats ? this.beats[0] : 0;
  }
  beatAt(t) {
    const B = this.beats;
    if (!B) return (t - this.t0) / this.period;
    if (t <= B[0]) return (t - B[0]) / this.period;
    if (t >= B[B.length - 1]) return B.length - 1 + (t - B[B.length - 1]) / this.period;
    let lo = 0, hi = B.length - 1;
    while (hi - lo > 1) { const m = (lo + hi) >> 1; if (B[m] <= t) lo = m; else hi = m; }
    return lo + (t - B[lo]) / (B[hi] - B[lo]);
  }
  timeAt(beat) {
    const B = this.beats;
    if (!B) return this.t0 + beat * this.period;
    const i = Math.floor(beat);
    if (i < 0) return B[0] + beat * this.period;
    if (i >= B.length - 1) return B[B.length - 1] + (beat - (B.length - 1)) * this.period;
    return B[i] + (B[i + 1] - B[i]) * (beat - i);
  }
}

/** Copy of a clip with its root (Bip01) track turned by `yaw` radians about +Y (rotation and position). */
export function rebaseYaw(clip, yaw) {
  if (!yaw) return clip;
  const c = clip.clone(), r = new THREE.Quaternion().setFromAxisAngle(new THREE.Vector3(0, 1, 0), yaw);
  const q = new THREE.Quaternion(), v = new THREE.Vector3();
  for (const t of c.tracks) {
    if (!/^Bip01\.(quaternion|position)$/.test(t.name)) continue;
    const vals = t.values = t.values.slice();
    if (t.name.endsWith('quaternion')) for (let i = 0; i < vals.length; i += 4) { q.fromArray(vals, i).premultiply(r).toArray(vals, i); }
    else for (let i = 0; i < vals.length; i += 3) { v.fromArray(vals, i).applyQuaternion(r).toArray(vals, i); }
  }
  c.name = clip.name + '@yaw';
  return c;
}

export async function loadChoreography(base = new URL('./', import.meta.url)) {
  const bust = `?v=${Date.now()}`;
  const choreo = await (await fetch(new URL('choreography.json' + bust, base))).json();
  const beatmap = await (await fetch(new URL((choreo.beatmap || 'beatmap.json') + bust, base))).json().catch(() => null);
  return { choreo, beatmap };
}

export class LoginDance {
  /**
   * @param {object} o
   * @param {import('../stage.js').FrontStage} o.stage
   * @param {import('../character.js').FrontCharacter} o.actor   loaded, placed on the throne
   * @param {object} o.choreo  choreography.json   @param {object} o.beatmap  beatmap.json
   * @param {{x:number,z:number,yaw:number}} o.chair   seat position / facing (FILE frame)
   * @param {() => number|null} o.songTime   current song time in s (null = not playing)
   * @param {(v:number, s:number) => void} [o.dimBgm]
   */
  constructor({ stage, actor, choreo, beatmap, chair, songTime, dimBgm = () => {}, moves = MOVES }) {
    Object.assign(this, { stage, actor, choreo, chair, songTime, dimBgm, moves });
    this.clock = new BeatClock(beatmap);
    this.rig = null; this.clips = {}; this.phase = 'idle'; this.sectionName = ''; this.seatT = 0;
    const f = Number(choreo?.mark?.forward) || 2.5;
    this.mark = { x: chair.x + Math.sin(chair.yaw) * f, z: chair.z + Math.cos(chair.yaw) * f };
    // Pre-song stand duration: choreo.standUpSeconds, else ~4 beats at tracked period.
    this._standUpSec = Number(choreo?.standUpSeconds);
    if (!(this._standUpSec > 0)) this._standUpSec = 4 * this.clock.period;
  }

  async prepare() {
    const a = this.actor, models = this.stage.models;
    const load = k => k ? models.loadClip(k, a.model).catch(() => null) : null;
    const c = this.choreo;
    const [seat, seatAlt, stand] = await Promise.all([load(c.seat?.clip), load(c.seat?.fallbackClip), load(c.stand?.clip)]);
    // The chair-sit clip is authored for the hall figure's .mol transform (MAL_Login_Sit: yaw 0, scale 1.36, y 19.03);
    // its Bip01 track carries the facing. Re-base it onto the character's standing facing (chair.yaw) so seat <-> stand
    // cross-fades never spin, and the seated body faces the login camera exactly as the hall figure did.
    const fix = seat ? (this.chair.yaw - (this.chair.figureYaw ?? 0)) : 0;
    this.clips = { seat: seat ? rebaseYaw(seat, fix) : seatAlt, stand };
    // Standing/dancing must face the login camera. Empirically (body-forward · toCamera):
    // place(chair.yaw=PI) faces the throne; place(chair.yaw+PI)=0 faces the camera. Seat keeps chair.yaw
    // (rebased sit clip). Travel toChair uses chair.yaw (walk toward throne).
    this.faceYaw = this.chair.yaw + Math.PI;
    if (Number(this.chair.scale) > 0) a.scale = Number(this.chair.scale);
    // take over the actor's pose update (its own state machine would replay its rest clip)
    this._origUpdate = a.update.bind(a);
    a.update = dt => this.update(dt);
    // measure the body frame on the stand pose
    a.animator.play(this.clips.stand || stand, { loop: true, fade: 0 }); a.animator.update(0);
    this.rig = new DanceRig(a.instance);
    this.rig.calibrate();
    this.toSeat(true);
    return this;
  }

  toSeat(now = false) {
    const a = this.actor;
    a.animator.play(this.clips.seat || this.clips.stand, { loop: true, fade: now ? 0 : 0.6 });
    this._seatAt();
    this.phase = 'seated';
  }

  /** Put the body on the seat transform (the .mol placement point, not the snapped floor, which is the dais edge). */
  _seatAt() {
    const a = this.actor;
    a.place(this.chair.x, this.chair.z, this.chair.yaw);
    if (Number.isFinite(this.chair.y)) { a.y = this.chair.y; a._syncGroup(); }
  }

  /** Startup load reached 100%: dim the hall BGM, start the seated hold (owner step 2). */
  loaded() {
    if (this.phase !== 'seated') return;
    const d = this.choreo.dimBgm || {};
    this.dimBgm(Number(d.to ?? 0.2), Number(d.seconds ?? 1.2));
    this.phase = 'waiting'; this.seatT = 0; this.sectionName = 'seated (hold)';
  }

  /**
   * true once stand-up finished after the post-load wait — caller starts audio THEN (owner: stand, then song).
   * Song must NOT start during 'waiting' or mid stand-up.
   */
  get wantsSong() { return this.phase === 'readyForSong'; }

  /** Begin seat→stand crossfade on wall clock (before any song). */
  _beginStandUp() {
    const a = this.actor;
    const fade = this._standUpSec;
    if (this.clips.stand) a.animator.play(this.clips.stand, { loop: true, fade });
    this._base = 'stand';
    this.phase = 'standingUp';
    this.seatT = 0;
    this.sectionName = 'stand-up (pre-song)';
    this._seatAt();
  }

  section(beat) {
    for (const s of this.choreo.sections) {
      // standUp is handled pre-song on wall clock; skip if still listed in JSON for docs/preview
      if (s.transition === 'standUp') continue;
      if (beat >= s.from && beat < s.to) return s;
    }
    return null;
  }

  update(dt) {
    const a = this.actor;
    if (!a.animator) return;
    this.seatT += dt;
    const waitSec = Number(this.choreo.preSongSeconds) || 2;

    // owner: after load 100%, wait 2s seated, then stand BEFORE song.
    if (this.phase === 'waiting' && this.seatT >= waitSec) this._beginStandUp();

    if (this.phase === 'standingUp') {
      a.animator.update(dt);
      a.animator.mixer.update(0);
      const k = smooth(this.seatT / Math.max(0.05, this._standUpSec));
      // Blend place yaw seat→camera as he rises so the turn isn't a pop at song start.
      const yaw = this.chair.yaw + (this.faceYaw - this.chair.yaw) * k;
      a.place(this.chair.x, this.chair.z, yaw);
      if (Number.isFinite(this.chair.y)) { a.y = this.chair.y; a._syncGroup(); }
      this.rig.apply(MOVES.stance.keys[0], k);
      a.group.updateMatrixWorld(true);
      if (this.seatT >= this._standUpSec) {
        this.phase = 'readyForSong';
        this.sectionName = 'standing (ready for song)';
      }
      return;
    }

    const t = this.songTime();
    // Song actually playing → enter dancing (sit-down still driven by beatmap end).
    if ((this.phase === 'readyForSong' || this.phase === 'standingUp') && t != null && t > 0) {
      this.phase = 'dancing';
      this.sectionName = '';
    }

    a.animator.update(dt);
    a.animator.mixer.update(0);            // fresh base pose before the additive layer
    if (this.debugPose) {                   // preview tool: hold one pose on the mark
      if (this._base !== 'stand') { a.animator.play(this.clips.stand, { loop: true, fade: 0 }); a.animator.update(0); a.animator.mixer.update(0); this._base = 'stand'; }
      a.place(this.mark.x, this.mark.z, this.faceYaw);
      this.rig.apply(this.debugPose, 1); return;
    }
    if (this.phase === 'readyForSong') {
      // Hold standing idle on the throne until audio actually starts (face camera).
      if (this._base !== 'stand') { a.animator.play(this.clips.stand, { loop: true, fade: 0.2 }); this._base = 'stand'; }
      a.place(this.chair.x, this.chair.z, this.faceYaw);
      if (Number.isFinite(this.chair.y)) { a.y = this.chair.y; a._syncGroup(); }
      return;
    }
    if (this.phase !== 'dancing' || t == null) { a._syncGroup(); return; }
    const beat = this.clock.beatAt(t);
    const s = this.section(beat);
    const danceSections = this.choreo.sections.filter(x => x.transition !== 'standUp');
    const last = danceSections[danceSections.length - 1];
    if (!s) {
      if (last && beat >= last.to && this.phase === 'dancing') {
        this.phase = 'seatedEnd';
        this.sectionName = 'seated (end)';
        if (this._base !== 'seat') {
          a.animator.play(this.clips.seat || this.clips.stand, { loop: true, fade: 0.4 });
          this._base = 'seat';
        }
        this._seatAt();
      }
      a._syncGroup(); return;
    }
    this.sectionName = s.name;
    const blend = Number(this.choreo.blendBeats) || 1;
    let pose = null, w = 1;
    if (s.transition === 'sitDown') {
      if (this._base !== 'seat') { a.animator.play(this.clips.seat, { loop: true, fade: this.clock.timeAt(s.to) - this.clock.timeAt(s.from) }); this._base = 'seat'; }
      this._seatAt();
      pose = MOVES.stance.keys[0]; w = 1 - smooth((beat - s.from) / (s.to - s.from));
    } else {
      // moves always ride on the standing base (also when the song is seeked straight into a section)
      if (this._base !== 'stand') { a.animator.play(this.clips.stand, { loop: true, fade: 0.25 }); a.animator.update(0); a.animator.mixer.update(0); this._base = 'stand'; }
      const mv = this.moves[s.move] || MOVES.stance;
      pose = evalMove(mv, beat - s.from);
      // blend between sections: the first `blend` beats mix from the previous section's pose
      const prev = danceSections.find(p => p.to === s.from);
      const k = (beat - s.from) / blend;
      if (prev?.move && k < 1) pose = mixPose(evalMove(this.moves[prev.move] || MOVES.stance, beat - prev.from), pose, smooth(k));
      this._travel(s, beat);
    }
    this.rig.apply(pose, w);
    a.group.updateMatrixWorld(true);
  }

  /** Sections with travel move the body between the throne and the mark (strut down / back up the purple path). */
  _travel(s, beat) {
    const a = this.actor;
    let from = this.mark, to = this.mark, yaw = this.faceYaw;
    if (s.travel === 'toMark') { from = this.chair; to = this.mark; }
    else if (s.travel === 'toChair') { from = this.mark; to = this.chair; yaw = this.chair.yaw; } // face throne while walking back
    const k = s.travel ? Math.min(1, (beat - s.from) / Math.max(1, s.to - s.from - 1)) : 1;
    // last beats of walk-back turn to face the camera again before sitting
    if (s.travel === 'toChair' && beat > s.to - 1.5) yaw = this.chair.yaw + (this.faceYaw - this.chair.yaw) * smooth((beat - (s.to - 1.5)) / 1.5);
    a.place(from.x + (to.x - from.x) * k, from.z + (to.z - from.z) * k, yaw);
  }

  dispose() {
    if (this._origUpdate) this.actor.update = this._origUpdate;
    this._origUpdate = null;
  }
}
