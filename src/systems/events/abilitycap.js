// Level-difference ability caps of the event maps (share/pc/abilitycap*.csv -> events_caps.json abilityCaps, picked by
// the map's StrAbilityCapPath: events.json maps[m].files.abilityCap). docs/formats/events.md §2.8.
//   row      [levelDiff (+250 .. -250), Melee, Magic, Element Decrease Rate, All Resist Rate, Miss Rate, Blocking Rate,
//             Guard Rate] x 2 blocks
//   reading  (events.md: inferred, the split is not labelled) block 1 = the character against monsters, levelDiff =
//            monster level - character level. A positive rate lowers the character's damage (melee/range by Melee, magic
//            by Magic Decrease Rate) and adds Miss Rate to its misses; a negative rate (a much weaker monster) raises it.
//            Block 2 (the PvP context) is not used: there are no other players.
// Colosseum / Ice Castle maps use abilitycap_colosseum.csv (all zeros: no modifier); Dead Front, the Infinite Battles
// and the Colosseum Arena abliitycap_indun_01.csv; the Defense Battle abilitycap_braiken_broken.csv (a flat 50 % melee
// decrease at an equal level). Applied through game.combatHooks.beforeDamage (combat.applyDamage) on event maps only.

export function installAbilityCap(game, sys) {
  game.combatHooks = game.combatHooks || {};
  const before = game.combatHooks.beforeDamage || (game.combatHooks.beforeDamage = []);
  let cacheMap = null, cacheRows = null;
  const rowsFor = (m) => {
    if (m === cacheMap) return cacheRows;
    cacheMap = m;
    const t = sys.ownsMap(m) || sys.run?.map === m ? sys.data?.abilityCapTable(m) : null;
    cacheRows = t && !t.allZero ? new Map(t.rows.map(r => [Number(r[0]), r])) : null;
    return cacheRows;
  };
  const hook = (attacker, defender, result) => {
    const p = game.player;
    if (!p || attacker !== p || !defender || defender === p || defender.brickDef) return;
    if (defender.kind !== 'monster' || result.miss) return;
    const rows = rowsFor(Number(game.world?.info?.index));
    if (!rows) return;
    const diff = Math.max(-250, Math.min(250, Math.round((Number(defender.level) || 1) - (Number(p.level ?? game.save?.level) || 1))));
    const r = rows.get(diff);
    if (!r) return;
    const miss = Number(r[5]) || 0;
    if (miss > 0 && Math.random() * 100 < miss) { result.miss = true; result.amount = 0; result.crit = false; return; }
    const rate = result.kind === 'magic' ? Number(r[2]) || 0 : Number(r[1]) || 0;
    if (rate) result.amount = Math.max(1, Math.round((Number(result.amount) || 0) * (1 - rate / 100)));
  };
  before.push(hook);
  game.events.on('map', () => { cacheMap = null; });
  return () => { const i = before.indexOf(hook); if (i >= 0) before.splice(i, 1); };
}
