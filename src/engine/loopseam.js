// Loop-seam closing for looping walk / run (and monster move) clips (#33, tunables: src/config/engine-chosen-anim-loop.js).
//
// A loop plays t = 0..duration and wraps from the LAST key to the FIRST key. Most clips are authored closed (last key == first key),
// but about one class walk / run clip in seven (and one monster loop clip in eight) is not: tails, cloaks, calves jump 5-30 degrees
// once per cycle. closeLoopSeam() returns a clip of the same name, duration and key times for t < duration - window in which every
// track whose wrap jump is larger than that track's normal per-frame change at the wrap (and over the ENGINE-CHOSEN floors) eases
// onto its first key over the last few frames, so the wrap is continuous. Tracks without such a seam are shared with the source clip.
// Non-looping clips must never go through here (the caller decides; Actor._applyClip only passes a looping walk / run clip).
import * as THREE from 'three';
import { AUTHORING_FPS } from '../formats/anim.js';
import { ANIM_LOOP_CHOSEN as C } from '../config/engine-chosen-anim-loop.js';

const RAD2DEG = 180 / Math.PI;
const EPS = 1e-6;
const _qa = new THREE.Quaternion(), _qb = new THREE.Quaternion();

const kindOf = track => (track.name.endsWith('.quaternion') ? 'rot' : track.name.endsWith('.position') ? 'pos' : null);

/** Distance between two key values of a track: degrees for a rotation track, model units for a position track. */
function valueDistance(kind, a, b, vs) {
  if (kind === 'rot') {
    let dot = 0;
    for (let c = 0; c < 4; c++) dot += a[c] * b[c];
    return 2 * Math.acos(Math.min(1, Math.abs(dot))) * RAD2DEG;
  }
  let d = 0;
  for (let c = 0; c < vs; c++) d = Math.max(d, Math.abs(a[c] - b[c]));
  return d;
}

/** Difference between the last and the first key of a track: degrees (rotation) or model units (position); 0 for any other track. */
export function trackSeam(track) {
  const kind = kindOf(track), n = track.times.length;
  if (!kind || n < 2) return 0;
  const vs = track.getValueSize();
  return valueDistance(kind, track.values.slice((n - 1) * vs, n * vs), track.values.slice(0, vs), vs);
}

/** Source frame time of a clip: duration / key intervals (frameCount), 1/30 s authoring rate when the anim does not say. */
export function frameTime(clip) {
  const T = clip.duration, intervals = Number(clip.userData?.frameCount) > 1 ? Number(clip.userData.frameCount) : Math.max(1, T * AUTHORING_FPS);
  return T / intervals;
}

/**
 * The track's normal per-frame change where the loop wraps: its biggest change over one frame time within two frames of the loop
 * point on either side (the last two frames of the clip and the first two). This is what the wrap jump is compared with.
 */
export function wrapFrameStep(track, T, h) {
  const kind = kindOf(track), vs = track.getValueSize();
  if (!kind || !(h > 0)) return 0;
  const interp = track.createInterpolant();
  const at = t => Array.from(interp.evaluate(Math.max(0, Math.min(T, t))));
  let max = 0;
  for (const [a, b] of [[T - 2 * h, T - h], [T - h, T], [0, h], [h, 2 * h]]) max = Math.max(max, valueDistance(kind, at(a), at(b), vs));
  return max;
}

/** Does this track jump at the wrap by more than its normal per-frame change there (and over the floor)? */
export function hasSeam(track, T, h) {
  const kind = kindOf(track);
  if (!kind) return false;
  const seam = trackSeam(track), floor = kind === 'rot' ? C.rotationSeamDeg : C.positionSeam;
  return seam > floor && seam > wrapFrameStep(track, T, h);
}

/** Length (s) of the closing blend of a clip: closeFrames source frames, at most maxCloseShare of the clip. */
export function closeWindow(clip) {
  return Math.min(C.closeFrames * frameTime(clip), clip.duration * C.maxCloseShare);
}

function closeTrack(track, T, B) {
  const kind = kindOf(track), vs = track.getValueSize(), n = track.times.length, t0 = T - B;
  const interp = track.createInterpolant();
  const times = [], vals = [];
  const push = (t, arr, off) => { times.push(t); for (let c = 0; c < vs; c++) vals.push(arr[off + c]); };
  const first = Array.from(track.values.slice(0, vs));
  for (let i = 0; i < n; i++) if (track.times[i] < t0 - EPS) push(track.times[i], track.values, i * vs);
  push(t0, interp.evaluate(t0), 0);                                   // the pose the clip has where the blend starts
  for (let i = 0; i < n; i++) {
    const t = track.times[i];
    if (!(t > t0 + EPS && t < T - EPS)) continue;
    const u = (t - t0) / B, s = u * u * (3 - 2 * u);                   // smoothstep: no velocity kink where the blend starts
    if (kind === 'rot') {
      _qa.fromArray(track.values, i * vs); _qb.fromArray(first);
      _qa.slerp(_qb, s);
      times.push(t); vals.push(_qa.x, _qa.y, _qa.z, _qa.w);
    } else {
      times.push(t);
      for (let c = 0; c < vs; c++) vals.push(track.values[i * vs + c] + (first[c] - track.values[i * vs + c]) * s);
    }
  }
  push(T, first, 0);                                                  // the wrap lands exactly on the first key
  const out = track.clone();
  out.times = new Float32Array(times);
  out.values = new Float32Array(vals);
  return out;
}

/**
 * The loop-closed version of a looping clip (the clip itself when no track has a seam).
 * Cached on clip.userData.loopClosed (userData is shared with the closed clip, so closing it again returns it).
 * @param {THREE.AnimationClip} clip
 * @returns {THREE.AnimationClip}
 */
export function closeLoopSeam(clip) {
  if (!clip || !(clip.duration > 0) || !clip.tracks?.length) return clip;
  const ud = clip.userData || (clip.userData = {});
  if (ud.loopClosed !== undefined) return ud.loopClosed || clip;
  const T = clip.duration, h = frameTime(clip), B = closeWindow(clip);
  const seamed = clip.tracks.map(tr => hasSeam(tr, T, h));
  if (!seamed.some(Boolean)) { ud.loopClosed = null; return clip; }
  const tracks = clip.tracks.map((tr, i) => (seamed[i] ? closeTrack(tr, T, B) : tr));
  const closed = new THREE.AnimationClip(clip.name, T, tracks, clip.blendMode);
  closed.userData = ud;
  ud.loopClosed = closed;
  ud.loopClosedTracks = seamed.filter(Boolean).length;
  return closed;
}
