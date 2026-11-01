// ENGINE-CHOSEN visibility for inferred, unplaced Ardeca quest actors. Native
// placement rows (including Karin's event flag) never pass through this policy.
// Event dates are unknown; eligibility alone must not enable every old event.
export function visibleUnplacedQuest({quest,who,map,active=false,eligible=false,requested=new Set()}={}) {
  if (!quest || quest.isGroup || !who?.unplaced || Number(who.map)!==Number(map) || !Array.isArray(who.pos)) return false;
  return Number(map)===150 ? !!active || requested.has(Number(who.npc)) : !!active || !!eligible;
}
