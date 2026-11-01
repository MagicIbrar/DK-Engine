// Host side of Divide Pain / Divide Force (rules and native rows: src/systems/skills/damage-share.js).
// The protected player's SHARE_DAMAGE_PARTY entry names its caster (sourceId); a hit on the protected player moves sharePct of
// it to that caster when the caster is a connected, living member of the same party in the same scene. Everything else leaves
// the hit untouched: no state is written unless a transfer actually happens, so a refused share needs no rollback.
import { findWorldPlayer } from './actor-lookup.mjs';
import { sameScene } from './scene.mjs';
import { planShare, selfBuffStep, shareEntries } from '../../src/systems/skills/damage-share.js';

const sameParty = (world, a, b) => {
 const party = a.partyId && world.parties?.get(a.partyId);
 return !!party && b.partyId === a.partyId && party.members.includes(a.id) && party.members.includes(b.id);
};

/** Why `caster` cannot take shared damage for `protectedPlayer` right now, or null when it can. */
export function shareBlocker(world, protectedPlayer, caster, { attacker = null, context = null } = {}) {
 if (!caster) return 'absent';
 if (caster === protectedPlayer || caster.id === protectedPlayer.id) return 'self';
 if (world.players.get(caster.account) !== caster || caster.leaving) return 'disconnected';
 if (caster.customMapPending || caster.sceneTransition) return 'transition';
 if (caster.dead || !(Number(caster.hp) > 0)) return 'dead';
 if (!sameScene(protectedPlayer, caster)) return 'scene';
 if (!sameParty(world, protectedPlayer, caster)) return 'party';
 if (attacker && attacker === caster) return 'attacker';
 if (context && !context(caster)) return 'context';
 return null;
}

// The blue self status runs through the caster's own skill system, as the cast would have applied it.
function receiveBuff(world, caster, entry) {
 const sys = caster._skills;
 const skill = sys?.engine?.skillDef?.(entry.skillIndex);
 const step = selfBuffStep(skill, entry.level, entry.statusIndex);
 if (!step || !(step.durationMs > 0) || !(step.chance >= 100 || world.random() * 100 < step.chance)) return;
 sys.statuses.add(sys.game.player, step.statusIndex, step.durationMs, { source: sys.game.player, skill, level: entry.level, divideReceipt: true });
}

/**
 * Share `amount` (damage the protected player is about to suffer) with the casters of its Divide entries.
 *   attacker  record of the hitter (monster or player), excluded as a caster
 *   context   optional caster -> boolean (PvP: the caster must stand on the protected player's side of the fight)
 * Returns { kept, part }: the protected player takes `kept`, the casters took `part` (kept + part === amount).
 * Never throws: on any fault the protected player takes the whole hit.
 */
export function divideShare(world, protectedPlayer, { amount, attacker = null, context = null } = {}) {
 const whole = { kept: Math.max(0, Number(amount) || 0), part: 0 };
 try {
  const entries = shareEntries(protectedPlayer?.profile?.buffs);
  if (!entries.length) return whole;
  const plan = planShare({
   entries, amount, protectedId: protectedPlayer.id,
   protectorFor: entry => {
    const caster = findWorldPlayer(world, entry.sourceId);
    return shareBlocker(world, protectedPlayer, caster, { attacker, context }) === null ? caster : null;
   },
  });
  if (!(plan.part > 0)) return whole;
  // The hp write is the commit: once a caster paid its part the protected player is relieved of it, even if a notification
  // below fails, so a fault can never charge the same damage twice.
  for (const { protector, part, entry } of plan.transfers) {
   protector.hp = Math.max(1, protector.hp - part);
   try {
    protector.lastCombat = world.now();
    world.changed(protector);
    // defeat: null = no hit reaction (the host would otherwise roll one for any damage event on a player)
    world.emit(protector.map, { type: 'damage', sourceId: attacker?.id ?? protectedPlayer.id, targetId: protector.id, amount: part, dead: false, shared: true, defeat: null, instanceId: protector.instanceId || null });
    receiveBuff(world, protector, entry);
   } catch (error) { console.warn('[skills] Divide notification failed', error?.message || error); }
  }
  return { kept: plan.kept, part: plan.part };
 } catch (error) {
  console.warn('[skills] Divide damage share skipped', error?.message || error);
  return whole;
 }
}
