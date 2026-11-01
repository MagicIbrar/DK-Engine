// Native guard-mask rules and approved defender recipients. Guard activation is
// still separately disabled pending actor/combat integration.
import {siegeDeployCellAllowed} from './siege-renew-deploy-mask.js';

/** AUTHENTICATED NATIVE value used by the default: share/creature/sentry.csv Width 3 for all six guard records. */
export const GUARD_WIDTH = 3;

/** Proposed default 1 (guard placement boundary). Returns null when (x, z) is a valid guard cell, else the native 701:219
 * "Cannot place guard here." refusal. scene: native castle scene; castle: controller castle record; guards: deployed rows. */
export function guardPlacementRefusal({ scene, castle, guards = [], x, z, width = GUARD_WIDTH }) {
  const bad = [701, 219];
  if (!Number.isFinite(Number(x)) || !Number.isFinite(Number(z))) return bad;
  const cx = Math.floor(Number(x)), cz = Math.floor(Number(z)), half = Math.floor(width / 2);
  for(let dz=-half;dz<=half;dz++)for(let dx=-half;dx<=half;dx++)if(!siegeDeployCellAllowed(castle.deployMask,cx+dx,cz+dz))return bad;
  // ENGINE-CHOSEN wall safety: mask artwork can bleed into solid MAC cells.
  // Rampart attribute1000 remains eligible where the native alpha allows it.
  const attr=scene.collision?.attrAt?.(cx+.5,cz+.5);
  if(attr===undefined?!(scene.isWalkable?.(cx+.5,cz+.5)??true):attr<0||[1,2,3].includes(attr))return bad;
  if (guards.some(g => Math.abs(Math.floor(g.x) - cx) < width && Math.abs(Math.floor(g.z) - cz) < width)) return bad;
  return null;
}

/** Approved 2026-10-13: literal native "all guild members" / "all attackers".
 * ENGINE-CHOSEN scope: online living guild members across scenes; hostile effects
 * remain inside the castle battle and include allied attacker guilds. */
export function defenderSkillRecipients({ selection, participants, ownerGuild, ownerMembers = [] }) {
  const living = p => p && !p.dead && !p.leaving && !p.sceneTransition;
  return selection === 0 ? [...new Set(ownerMembers.filter(living))]
    : participants.filter(({ player, record }) => living(player) && record?.side === 'attacker' && record.guild !== ownerGuild).map(({ player }) => player);
}

/** Proposed default 4 (cooldown): remaining milliseconds of a castle skill (0 = ready). */
export const skillCooldownLeft = (castleState, selection, now) => Math.max(0, Number(castleState?.skills?.[selection]?.readyAt || 0) - now);
