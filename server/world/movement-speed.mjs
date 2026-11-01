import {mountSpeed} from './mounts.mjs';
import {walkSpeedRatio} from '../../src/game/progression.js';

/** The host's existing run stride, shared by simulation and prediction metadata. */
export function authorizedGMSpeed(p){const factor=Number(p.profile.gm?.speed||1);return p.gmAuthorized&&Number.isFinite(factor)?Math.max(.1,Math.min(10,factor)):1;}
// p.stats.moveSpeed is derived server-side from the class run stride x the status data (deriveStats floors the multiplier at 0.2),
// so it is not clamped here: the old 1..6 u/s clamp ate buffs above 6 (data goes to ~7.9) and slows below 1 (~0.69), which made the
// client's prediction (unclamped) outrun the server. tools/test-speed-buff-accuracy.mjs pins server == client == data.
export function canonicalMovementSpeed(world,p){return Math.max(0.1,p.stats.moveSpeed||2.5)*authorizedGMSpeed(p)*mountSpeed(world,p);}
/** Speed of the current path: run speed, or the class walk stride (R walk, move intent `walk: 'peace'|'battle'`) on foot. */
export function pathMovementSpeed(world,p){const walking=(p.walk==='peace'||p.walk==='battle')&&p.mount?.phase!=='on';return canonicalMovementSpeed(world,p)*(walking?walkSpeedRatio(world.data?.classDef?.(p.classIndex),p.walk==='peace'):1);}
