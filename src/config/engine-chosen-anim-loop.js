// ANIM-LOOP (#33): the values the Global data does not define for looping walk / run clips. Every value carries its own
// ENGINE-CHOSEN tag.
// Defined by the data and read at run time:
//   every .anim keys its poses from normalised time 0 to 1 (first key 0, last key 1); share/action/** gives TimeLength seconds and
//   a loop plays t = 0..TimeLength, then wraps (src/engine/models.js loadClip, src/engine/animator.js THREE.LoopRepeat).
// Not defined by the data: what a loop whose LAST key differs from its FIRST key should look like at the wrap. 14 of the ~100 class
// walk / run clips are authored that way (the peace walk / run of 8 of the 15 classes: Trie Muse run tail bones 28-30 deg, Alokes
// walk / run calves 13-15 deg, Incar Magician run 12 deg, Azure Knight peace run cloak bone 6.8 deg) and 276 of the 2168 monster
// loop clips (tools/test-anim-loop-seam.mjs lists them). Played as is, those bones jump once per cycle, which is the hitch seen at
// the end of the run / walk loop. src/engine/loopseam.js closes the loop: over the last few frames of a looping walk / run (and
// monster move) clip, only the tracks whose seam is over the thresholds below are eased onto the first key. Clip length, playback
// speed, the first frames and every non-looping clip are untouched.
// The remote-body hold (REMOTE_LOCOMOTION_CHOSEN) is the same kind of value for src/systems/network/actors.js and movement-sync.js.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';

export const ANIM_LOOP_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): a track whose last key is more than this many degrees from its first key is closed. */
  rotationSeamDeg: 1,
  /** ENGINE-CHOSEN (not in Global data): a position track whose last key is more than this many model units from its first key is closed. */
  positionSeam: 0.01,
  /** ENGINE-CHOSEN (not in Global data): the closing blend spans this many source frames at the end of the clip (clip length / key intervals each). */
  closeFrames: 4,
  /** ENGINE-CHOSEN (not in Global data): ...but never more than this share of the clip length. */
  maxCloseShare: 0.5,
});

export const REMOTE_LOCOMOTION_CHOSEN = Object.freeze({
  /**
   * ENGINE-CHOSEN (not in Global data): a remote body that was walking / running keeps its walk / run clip for this long (ms)
   * after its shown position stops changing. A host pose that arrives a frame or two late (network jitter, a 200 ms tween that
   * ran out) must not drop it to the stand clip and restart the stride a moment later; a real stop still shows the stand clip.
   */
  stopHoldMs: 120,
});
