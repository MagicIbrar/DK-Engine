// `scripted` service/dungeon hints are builder text classifications, not native
// completion predicates. The legacy rows need an authenticated operation/boss
// binding before a generic hook may fill them (see the per-row source audit).
export function scriptedObjectiveNeedsBinding(objective) {
  return objective?.kind === 'scripted' && ['service', 'dungeon'].includes(objective.hint);
}

/** Preserve actual authored clear objectives and explicit any-dungeon rows. */
export function clearObjectiveMatches(objective, map) {
  if (objective?.kind !== 'clearMap') return false;
  return objective.anyDungeon === true || (objective.targets || []).some(target => Number(target.id) === Number(map));
}

// Scripted dungeon slots whose qualifying boss is resolved from original data
// (tools/audit-r3-quest-credit-3.1.0.mjs and its per-row development report).
// A binding applies only to the exact original pending row (label and max count),
// is credited by a real kill of the listed monster by the player, and never by
// accepting, talking or clearing. Every other scripted service/dungeon slot stays pending.
//   AUTHENTICATED: the labelled map's original callmonster table spawns exactly one
//     monster of that name, and native questtable_renew kill rows use the same index.
//   ENGINE_CHOICE: the original data offers several same-named variants; the listed ones count.
const freezeBinding = b => Object.freeze({ ...b, monsters: Object.freeze([...b.monsters]) });
const KILL_BINDINGS = new Map(Object.entries({
  // Ruins of Baz (map 151) call 14 is the only Emperor Baz; native 6213/15861 kill 3611.
  '9763:0': { label: 'Emperor Baz in Ruins of Baz', count: 1, monsters: [3611], map: 151, rule: 'AUTHENTICATED' },
  // Ruins of Rudene (map 152) spawns only Raged 9099/9100 (fire route) and Frigid 9101/9102
  // (water route); both routes end with "Kill the arch spirit, Tyrant Rudene" (map messages 15/24).
  '9763:1': { label: 'Tyrant Rudene in Ruins of Rudene', count: 1, monsters: [9099, 9100, 9101, 9102], map: 152, rule: 'ENGINE_CHOICE' },
  // Tower of Spell Rank S 5F (map 99) call 3 is the only Hard Neo Deux Marble; native 4286 kills 5349.
  '9763:2': { label: '[Hard] Neo Deux Marble in Tower of Spell', count: 1, monsters: [5349], map: 99, rule: 'AUTHENTICATED' },
  // Ellonom (map 159) call 36 is the only Guardian Hider; native 199/5414 kill 6131.
  '9763:3': { label: 'Guardian Hider in Elonohm', count: 1, monsters: [6131], map: 159, rule: 'AUTHENTICATED' },
  // No map in the objective, and two original monsters carry the name. Every native objective row for this boss
  // (1135/5453, Karon's Fragments Hard) kills 8581; none names 9281 (_C, Core 602), so only 8581 counts.
  '15736:2': { label: 'Helphairon of the Frozen Heart', count: 1, monsters: [8581], map: null, rule: 'ENGINE_CHOICE' },
}).map(([key, b]) => [key, freezeBinding(b)]));

/** The native kill binding of a pending scripted dungeon slot, or null. */
export function nativeKillBinding(questId, objective) {
  if (!scriptedObjectiveNeedsBinding(objective) || objective.hint !== 'dungeon') return null;
  const binding = KILL_BINDINGS.get(`${Number(questId)}:${Number(objective.slot)}`);
  if (!binding || objective.label !== binding.label || Number(objective.count) !== binding.count) return null;
  return binding;
}
export function nativeKillBindingMatches(binding, monsterIndex, map) {
  return !!binding && binding.monsters.includes(Number(monsterIndex)) && (binding.map == null || Number(binding.map) === Number(map));
}
export function nativeKillBindingKeys() { return [...KILL_BINDINGS.keys()]; }

// Turn-in talk for other scripted hints (guild/PvP/rank/script/huntPoints). Per-row proof
// (journal, dialog and objective strings in the evidence JSON) shows that speaking to the
// turn-in NPC is not the original operation for the rows below, so neither solo nor online
// credits them from talk. The two rows whose original operation is speaking to the turn-in
// NPC (TURN_IN_TALK) are credited solo and, through quests.mjs's talk view, online.
const UNEARNED_TURN_IN_TALK = new Map(Object.entries({
  guildTeleport: ['23:0'],
  monsterCount: ['630:0'],
  rankCertification: ['2011:0', '2011:1', '2011:2', '2011:3', '2012:0', '2012:1', '2012:2', '2012:3', '2013:0', '2013:1', '2013:2', '2013:3',
    '2014:0', '2014:1', '2014:2', '2014:3', '2015:0', '2015:1', '2015:2', '2015:3', '2016:0', '2016:1', '2016:2', '2016:3', '2017:0', '2017:1', '2017:2', '2017:3',
    '2018:0', '2018:1', '2018:2', '2018:3', '2019:0', '2019:1', '2019:2', '2019:3', '2020:0', '2020:1', '2020:2', '2020:3', '2021:0', '2021:1', '2021:2', '2021:3',
    '2022:0', '2022:1', '2022:2', '2022:3', '2023:0', '2023:1', '2023:2', '2023:3', '2024:0', '2024:1', '2024:2', '2024:3', '2025:0', '2025:1', '2025:2', '2025:3',
    '2026:0', '2026:1', '2026:2', '2026:3', '2027:0', '2027:1', '2027:2', '2027:3'],
  pvpResult: ['1562:1', '2081:0', '2082:0', '2083:0', '2084:0', '2085:0', '2086:0', '15789:0'],
  otherNpc: ['2051:0', '4271:1', '8072:1', '8073:0'],
  killOrCollect: ['3843:1', '4176:2', '4496:1', '5412:1', '8065:1', '8905:1', '8907:2', '8908:2', '8916:2', '15968:0', '15992:1', '15995:1'],
  drinkingContest: ['4141:1', '4143:1'],
  guildMission: ['5004:1', '5005:1', '5006:1', '5007:0', '5008:0', '5009:0'],
  oreStrength: ['8909:1'],
  travel: ['8915:1'],
  fishing: ['15706:1'],
}).flatMap(([reason, rows]) => rows.map(row => [row, reason])));
const TURN_IN_TALK = new Map(Object.entries({
  // Original journal: deliver 1 Hidden Liquor to the Beggar (2105, the turn-in NPC).
  '4147:1': { reason: 'deliveryToTurnIn', label: 'Delivered a Hidden Bottle of Alcohol', count: 50 },
  // Original page 11000: "You can complete it now, Or complete it at 60,000 points" (Berks 101, the turn-in NPC).
  '12233:1': { reason: 'earlyCompletionAtTurnIn', label: 'Cumulative Hunting Points', count: 60000 },
}));

/** A scripted slot whose original operation is speaking to the turn-in NPC (credited solo and online), or null. */
export function turnInTalkBinding(questId, objective) {
  const b = TURN_IN_TALK.get(`${Number(questId)}:${Number(objective?.slot)}`);
  return b && objective?.kind === 'scripted' && objective.label === b.label && Number(objective.count) === b.count ? b : null;
}

/** Proven reason why speaking to the turn-in NPC cannot complete this scripted slot, or null. */
export function unearnedTurnInTalk(questId, objective) {
  return UNEARNED_TURN_IN_TALK.get(`${Number(questId)}:${Number(objective?.slot)}`) ?? null;
}
/** Original per-row classification table (audit/tests). */
export function turnInTalkClassification() {
  return { unearned: Object.fromEntries(UNEARNED_TURN_IN_TALK), turnInTalk: Object.fromEntries([...TURN_IN_TALK].map(([row, b]) => [row, b.reason])) };
}
