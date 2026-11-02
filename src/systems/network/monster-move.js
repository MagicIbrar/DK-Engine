// Lane 60 - Global remote-monster movement (client).
//
// Global (64-bit client, RTTI names) does not render monsters from a delayed, interpolated position buffer.
// Each server action becomes a Ghost::ModelCenter::Actors::Command:
//   * MoveDest (vft 7ff671e06f78; Command::Builder slot 4 FUN_7ff67099bde0 -> FUN_7ff67099d010): destination + speed.
//     Executed by PC::Action slot 36 FUN_7ff670a0d280: dir = dest - from, normalised when longer than 1e-6
//     (DAT_7ff671e84dec), the facing is SET at once (no turn rate), the move clip starts, and TDoll::CPathFindMoveCmd
//     walks the doll to the destination (Transfrom::State::CPathFind FUN_7ff6712d5540: per frame it advances by the
//     clip's root-motion distance x speed scale, FUN_7ff6712c9e70, and sets the facing to the step direction).
//     Arrival ends the move (listener at +0x70); the monster then stands where it is.
//   * Stand / MoveDir / Attack (Builder slot 1 cases 1 / 2 / 6: FUN_7ff67099c1c0 / FUN_7ff67099b980 / FUN_7ff67099b680)
//     first run the catch-up rule FUN_7ff67099d200 between the shown position and the packet position:
//       distance < 1.0 (DAT_7ff671e84f48)                   -> no correction at all
//       time left = arrival time - now (Stand: packet time + 1000 ms, FUN_7ff67099c1c0 `*param_4 + 1000`)
//       reach = time left x speed / 1000 (DAT_7ff671e851b4 = 1000)
//       time left > 0 and reach > distance                  -> MoveDest walk to the packet position
//       otherwise (late, or cannot make it in time)         -> Command::Position (vft 7ff671e06fe0): placed there
// The host publishes row.mv = [x, z, speed] (MoveDest) while a monster moves and row.mv = 0 (Stand) while it stands
// (server/world/monster-gait.mjs). Rows without mv come from an old host and keep the RemoteMotion buffer (actors.js).
//
// UNRESOLVED (documented in docs/global-parity-420/lanes/LANE-60-REPORT.md): the speed argument the Stand catch-up
// receives (FUN_7ff67099d200 param_11 is lost in the decompile). ENGINE-CHOSEN stand-in: the speed of the monster's last
// published move, else its monster.dat WalkSpeed. The 10-cell teleport guard is the existing movement-config TELEPORT_CELLS.
import { MOVEMENT_SYNC as C } from './movement-config.js';
import { remoteLocomotionState, placeRemote } from './movement-sync.js';

export const GLOBAL_MONSTER_MOVE = Object.freeze({
  catchUpIgnoreCells: 1.0,   // DAT_7ff671e84f48 (FUN_7ff67099d200: no command below 1.0)
  standWindowMs: 1000,       // FUN_7ff67099c1c0: Stand arrival time = packet time + 1000
  msPerSecond: 1000,         // DAT_7ff671e851b4
  epsilon: 1e-6,             // DAT_7ff671e84dec
});
const G = GLOBAL_MONSTER_MOVE;

/** A host row that carries the Global move field (new host). */
export function isGlobalMoveRow(row) {
  return !!row && (row.mv === 0 || (Array.isArray(row.mv) && row.mv.length >= 3));
}

function face(actor, dx, dz) {
  if (!(Math.hypot(dx, dz) > G.epsilon)) return;          // FUN_7ff670a0d280: keep the current facing
  const yaw = Math.atan2(-dx, -dz);                        // same FILE-frame convention as Actor.faceDirection
  actor.yaw = yaw; actor._yawGoal = yaw;
}
function walkSpeedOf(actor) { const s = Number(actor?.def?.speed?.[0]); return s > 0 ? s : 0; }

export class GlobalMonsterMove {
  constructor() { this.mode = 'stand'; this.dest = null; this.speed = 0; this.walk = false; this.lastSpeed = 0; this.lastWalk = false; this.standAt = null; this.last = null; }

  /** One host row. Returns what it did: 'move' | 'stay' | 'catchup' | 'snap' | 'same'. */
  push(actor, row, { hostNow = null, poseTime = null } = {}) {
    if (!Number.isFinite(row?.x) || !Number.isFinite(row?.z)) return 'same';
    const mv = row.mv, walk = row.walk === 'peace' || row.walk === 'battle';
    if (Array.isArray(mv) && Number.isFinite(mv[0]) && Number.isFinite(mv[1]) && Number(mv[2]) > 0) {
      if (Math.hypot(row.x - actor.x, row.z - actor.z) > C.TELEPORT_CELLS) actor.setPosition(row.x, row.z);
      const dest = { x: mv[0], z: mv[1] };
      const fresh = this.mode !== 'move' || !this.last || Math.hypot(dest.x - this.last.x, dest.z - this.last.z) > G.epsilon;
      this.mode = 'move'; this.dest = dest; this.last = dest; this.speed = Number(mv[2]); this.walk = walk;
      this.lastSpeed = this.speed; this.lastWalk = walk; this.standAt = null;
      if (fresh) face(actor, dest.x - actor.x, dest.z - actor.z);   // MoveDest: facing snaps toward the destination
      return 'move';
    }
    // Stand (mv 0): the catch-up rule runs once per stand position.
    if (this.mode !== 'move' && this.standAt && this.standAt.x === row.x && this.standAt.z === row.z) return 'same';
    this.standAt = { x: row.x, z: row.z }; this.last = null;
    const d = Math.hypot(row.x - actor.x, row.z - actor.z);
    if (d < G.catchUpIgnoreCells) { this.mode = 'stand'; this.dest = null; return 'stay'; }
    const speed = this.lastSpeed > 0 ? this.lastSpeed : walkSpeedOf(actor);
    const left = Number.isFinite(poseTime) && Number.isFinite(hostNow) ? poseTime + G.standWindowMs - hostNow : G.standWindowMs;
    const reach = left > 0 ? left * speed / G.msPerSecond : 0;
    if (!(left > 0) || reach <= d || reach < G.epsilon) { actor.setPosition(row.x, row.z); this.mode = 'stand'; this.dest = null; return 'snap'; }
    this.mode = 'catchup'; this.dest = { x: row.x, z: row.z }; this.speed = speed; this.walk = this.lastWalk;
    face(actor, row.x - actor.x, row.z - actor.z);
    return 'catchup';
  }

  /** Per frame: walk toward the destination at the commanded speed, then stand. */
  update(actor, dt, now, rest = 'idle') {
    let moving = false;
    if (!actor.dead && this.dest && (this.mode === 'move' || this.mode === 'catchup')) {
      const dx = this.dest.x - actor.x, dz = this.dest.z - actor.z, d = Math.hypot(dx, dz);
      const step = Math.max(0, this.speed * Math.max(0, Number(dt) || 0));
      if (d <= G.epsilon) this._arrive();
      else if (step >= d) { face(actor, dx, dz); placeRemote(actor, this.dest.x, this.dest.z); moving = true; this._arrive(); }
      else if (step > 0) { face(actor, dx, dz); placeRemote(actor, actor.x + dx / d * step, actor.z + dz / d * step); moving = true; }
    }
    if (!actor.dead && (actor._networkAnimHold || 0) <= now) {
      const state = remoteLocomotionState(actor, moving, this.walk, now, rest);
      if (actor.state !== state) actor.play(state);
    }
    return moving;
  }
  _arrive() { this.dest = null; if (this.mode === 'catchup') this.mode = 'stand'; }
  get moving() { return !!this.dest && (this.mode === 'move' || this.mode === 'catchup'); }
}