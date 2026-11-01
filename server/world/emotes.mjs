// Emotes and sitting in shared play. The client plays its own motion (src/systems/life/emotes.js); the host
// validates it against the player's class action table (life.json classMotions: MOTION 10..27 emotes, 100/101 lever,
// 700..702 costume motions, EMOTIONSTART/KEEP/END = sit down / sitting / stand up) and shows it to everyone on the map:
// an `emote` event for the motion, and `sitting` on the public player row so a player arriving later sees who sits.
// Moving, attacking or casting ends sitting (the client stands up the same way).
import {fishingBusy} from './fishing.mjs';
import { WorldError } from './core.mjs';

export const EMOTE_SCHEMAS = { emote: ['token', 'type', 'motion'] };
const MOTION_RANGES = [[10, 27], [100, 101], [700, 702]];

function classMotions(world, p) { return world.data?.classMotions?.[Number(p.profile?.classIndex ?? p.classIndex) || 0] || null; }
function validMotion(world, p, motion) {
  if (motion === 'sit' || motion === 'stand') { const e = classMotions(world, p)?.emotion; return !e || !!(e.EMOTIONSTART || e.EMOTIONKEEP); }
  if (!Number.isInteger(motion) || !MOTION_RANGES.some(([a, b]) => motion >= a && motion <= b)) return false;
  const table = classMotions(world, p);
  return !table || !!table.motions?.[motion];
}

export function emoteCommand(world, p, input) {
  const motion = input.motion;
  if (!validMotion(world, p, motion)) throw new WorldError(400, 'This motion is not available to your class.');
  if (p.mount?.phase === 'on' || fishingBusy(p)) throw new WorldError(400, 'Dismount or stop fishing before using a motion.');
  const now = world.now();
  if (now - (p.emoteAt || -Infinity) < 300) throw new WorldError(429, 'Motions are too frequent.');
  p.emoteAt = now;
  p.path = [];
  if (motion === 'stand' && !p.sitting) return;
  p.sitting = motion === 'sit';
  world.emit(p.map, { type: 'emote', actorId: p.id, motion, instanceId: p.instanceId || null });
  world.changed(p);
}

/** Moving, attacking or casting stands the player up. */
export function endSitting(world, p) { if (p.sitting) { p.sitting = false; world.changed(p); } }
