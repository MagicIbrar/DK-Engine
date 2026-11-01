// A player (or their servant / DoT) damaged monster `m`: the one entry point of the plain attack (core.mjs) and of skill /
// servant / DoT damage (skills.mjs skillEvent). A plain function of the world so the skill runtime needs no SharedWorld method.
//   hate   the hit's hostility for p (src/game/hate.js addHate; skill results add theirs in SkillEngine._aggro)
//   target a monster without a target engages its attacker (the tick then follows the hostility table)
//   call   Call patterns 4/5/6: UNDER_ATTACK while calm -> CALLTEAM once, re-armed by PERSUIT_OUT (negativecall_attack.csv:2-5,
//          positivecall_attack.csv:2-5, rangecall_attack.csv:2-5); DwCallTeamCount recruits within dwCallTeamCell cells of
//          this scene (monster-rules.js recruitCallTeam; the answering filter is ENGINE-CHOSEN, see engine-chosen-monster-ai.js)
//   cap    FOLLOWER CAP (src/game/follow-cap.js, info.csv dwFollowTarget, ENGINE-CHOSEN meaning): the hit monster and every recruit take a follower
//          slot on p only while p has fewer followers than THAT monster's dwFollowTarget; a hit monster with no free slot keeps targetId +
//          hostility (the tick retries it every tick), a recruit with no free slot does not answer the call
// Non-combatants (objects, patterns 7/13) and attack-less creatures never engage, as offline (ai.js canAttack).
import {canAttack,callTeamRule,recruitCallTeam,UNDER_ATTACK_STATE} from '../../src/game/monster-rules.js';
import {addHate} from '../../src/game/hate.js';
import {followLimit} from '../../src/game/follow-cap.js';

export function monsterHit(world, m, p, map, now, { hate = 0 } = {}) {
  if (!m || m.dead || !p) return;
  // Records that never fight (siege bricks, event objects, attack-less rows) still remember their last hitter as in 2.2.0:
  // siege.mjs settleObjectHp reads m.targetId as "who hit the gate / stone". The AI tick skips bricks and clears it on others.
  if (!canAttack(m.def)) { m.targetId = p.id; return; }
  m.aiState = UNDER_ATTACK_STATE;   // UNDER_ATTACK from REST / FEAR / UNCARING / ANNOYED -> RAGE (every pattern table); a monster that gave up a chase is hit like any other
  if (hate > 0) addHate(m, p.id, hate, world?.data?.skillCommon?.aggro, now);
  const fb = world?.follow, valid = (o, key) => !o.dead && o.targetId === key && map?.monsters?.get(o.id) === o;
  if (!m.targetId) { m.targetId = p.id; fb?.claim(m, p.id, followLimit(m.def), valid); }   // refused: stays pending (the tick takes the first free slot)
  const rule = callTeamRule(m.def);
  if (rule && !m.called && map?.monsters) {
    m.called = true;
    recruitCallTeam(map.monsters.values(), m, rule, {
      canAnswer: o => !o.dead && !o.isBrick && !o.targetId && !o.eventMarch && canAttack(o.def),
      engage: o => { if (fb && !fb.claim(o, p.id, followLimit(o.def), valid)) return false; o.targetId = p.id; o.idleMove = null; return true; },
    });
  }
}
