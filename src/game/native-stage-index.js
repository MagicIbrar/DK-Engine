// Nest of Cherubim (map 49) native StageIndex, computed by the host from deaths it observed itself.
//
// AUTHENTICATED NATIVE FACTS (checked on every call; any mismatch returns null, so callers keep the
// first native maprespawn entry):
//  - share/arrange/maprespawn.csv row 101: map 49 returns inside map 49, StageCount 9,
//    StageIndex 10-14 at (464,479), 15-16 at (115,217), 17-18 at (272,72).
//  - script/string/dungeon/stringtable_dungeon_02.txt cate 49 codes 10-18 are the nine mission texts
//    (designer comments "Mission 1".."Mission 10", no Mission 5). Help Book
//    script/string/help/guide_info_level.txt cate 1352 code 8 lists the same nine missions in the same
//    order ("미션 1".."미션 9"). StageIndex is the mission string code.
//  - The completion condition is named by the mission's own text: 14 "Kill Kadirun." (monster 3809
//    Kadirun), 15 "Kill the Ghostman_knight, Archer." (3810/3813, shapes Ghostman_knight /
//    Ghostman_archer; messages 2200/2300/3200 count 50 Ghostmen), 17 "Kill Ephri." (3801),
//    18 "Kill Cherubim." (3800).
//  - 12 "Destroy the Central Guard Stone." is the native breakable brick 36602 "Central Guard Tower"
//    (share/creature/brick.csv), placed once on map 49 as BrickUID 104 with IsCreate 1
//    (brick_49_cherubim.csv). The same string table calls the guard stones "Guard Tower" in its designer
//    comments: 1600 "1 Guard Tower Destroyed" = "1 Guard Stone has been destroyed", 1800 "Guard Tower
//    Mission Success Message" = "all the Guard Stones have been destroyed". Its destruction (the brick's
//    own death) is the completion event.
//
// DELIBERATE ENGINE CHOICE (the original server controller, maplist ScriptName Map49_Cherubim_nest,
// is not in the client): a finished mission k proves only that StageIndex k was reached. The host never
// claims a stage it has not seen. It walks the evidenced completions in native order and stops at the
// first one that has not happened. A completion whose objective the host does not spawn (monsters with
// the prepared role 'invisible', which the dungeon host skips, or a brick the instance does not hold)
// cannot be observed, so the walk passes over it without advancing on it. Missions 10, 11, 13 and 16
// have no host-observable native event (the round-3 dungeon source audit lists each
// missing predicate); they share their neighbours' checkpoints, so only the 15 and 17 boundaries move a
// revive. Stage 15 needs 50 Ghostman kills. The Ghostmen are native combat monsters whose body the
// client draws only through action model effects (shape rows 375/376 bind the empty *_none.mesh and no
// texture pack), and the prepared catalog marks them invisible, so the 115,217 checkpoint is not
// reachable in this host. That is an open dependency, not something inferred here.
export const CHERUBIM_MAP = 49;

const MISSIONS = Object.freeze([
  [10, 'After killing monsters, go inside the castle.'],
  [11, 'Kill the monsters inside the castle.'],
  [12, 'Destroy the Central Guard Stone.'],
  [13, 'Destroy all the Guard Stones simultaneously.'],
  [14, 'Kill Kadirun.'],
  [15, 'Kill the Ghostman_knight, Archer.'],
  [16, 'Kill all the monsters in the hallway.'],
  [17, 'Kill Ephri.'],
  [18, 'Kill Cherubim.'],
]);
const STAGES = Object.freeze([[10, 464, 479], [11, 464, 479], [12, 464, 479], [13, 464, 479], [14, 464, 479], [15, 115, 217], [16, 115, 217], [17, 272, 72], [18, 272, 72]]);
const CENTRAL_GUARD = Object.freeze({ uid: 104, brick: 36602, name: 'Central Guard Tower' });
const COMPLETIONS = Object.freeze([
  Object.freeze({ stage: 12, brick: CENTRAL_GUARD }),
  Object.freeze({ stage: 14, monsters: Object.freeze([3809]), count: 1, names: Object.freeze({ 3809: 'Kadirun' }) }),
  Object.freeze({ stage: 15, monsters: Object.freeze([3810, 3813]), count: 50, shapes: Object.freeze({ 3810: 'ghostman_knight', 3813: 'ghostman_archer' }) }),
  Object.freeze({ stage: 17, monsters: Object.freeze([3801]), count: 1, names: Object.freeze({ 3801: 'Ephri' }) }),
  Object.freeze({ stage: 18, monsters: Object.freeze([3800]), count: 1, names: Object.freeze({ 3800: 'Cherubim' }) }),
]);
const GHOSTMEN = Object.freeze([['2200', '50 Ghostman_knights, Archers'], ['2300', 'eliminated 50 Ghostmen'], ['3200', '50 Ghostmen have been eliminated']]);
const GUARD_STONE_IS_TOWER = Object.freeze([['1600', '1 Guard Tower Destroyed', '1 Guard Stone has been destroyed'], ['1800', 'Guard Tower Mission Success Message', 'all the Guard Stones have been destroyed']]);

const text = (info, code) => String(info?.messages?.[String(code)]?.t ?? '');

/** Why the prepared map-49 tables do not carry the authenticated native facts, or null when they do. */
export function cherubimStageMismatch(info, monsterDef) {
  const sr = info?.stageRespawn;
  if (Number(info?.dungeonIndex) !== CHERUBIM_MAP) return 'not the native Nest of Cherubim floor';
  if (!sr || Number(sr.id) !== 101 || Number(sr.respawnMap) !== CHERUBIM_MAP || Number(sr.stageCount) !== STAGES.length || sr.stages?.length !== STAGES.length) return 'maprespawn row 101 differs';
  for (const [i, [stage, x, y]] of STAGES.entries()) { const s = sr.stages[i]; if (Number(s?.stage) !== stage || Number(s?.x) !== x || Number(s?.y) !== y) return `maprespawn StageIndex ${stage} differs`; }
  const missions = new Map((info.missions || []).map(m => [Number(m.code), String(m.text || '')]));
  if (missions.size !== MISSIONS.length) return 'mission table differs';
  for (const [code, wanted] of MISSIONS) if (missions.get(code) !== wanted || text(info, code) !== wanted) return `mission ${code} text differs`;
  for (const [code, wanted] of GHOSTMEN) if (!text(info, code).includes(wanted)) return `message ${code} no longer counts 50 Ghostmen`;
  for (const [code, comment, wanted] of GUARD_STONE_IS_TOWER) if (String(info.messages?.[code]?.c ?? '') !== comment || !text(info, code).includes(wanted)) return `message ${code} no longer names the Guard Stones Guard Towers`;
  const central = (info.bricks || []).filter(b => Number(b.uid) === CENTRAL_GUARD.uid);
  if (central.length !== 1 || Number(central[0].brick) !== CENTRAL_GUARD.brick || !Number(central[0].create)) return 'brick 104 is not the created Central Guard Tower';
  if (typeof monsterDef !== 'function') return 'monster table unavailable';
  for (const c of COMPLETIONS) for (const index of c.monsters || []) {
    const def = monsterDef(index);
    if (!def) return `monster ${index} missing`;
    if (c.names && def.name !== c.names[index]) return `monster ${index} is not ${c.names[index]}`;
    if (c.shapes && String(def.shape || '').toLowerCase() !== c.shapes[index]) return `monster ${index} shape is not ${c.shapes[index]}`;
  }
  return null;
}

const kills = (killed, index) => Number(typeof killed === 'function' ? killed(index) : killed?.get?.(index) ?? killed?.[index]) || 0;
const brickOf = (bricks, uid) => (typeof bricks === 'function' ? bricks(uid) : bricks?.get?.(uid) ?? bricks?.[uid]) || null;
/** The instance's own live brick for a brick completion: same placement uid, native brick index and name, breakable. */
const hostBrick = (c, bricks) => { const b = brickOf(bricks, c.brick.uid); return b && Number(b.place?.brick) === c.brick.brick && b.brick?.name === c.brick.name && b.breakable === true ? b : null; };
/** The host spawns a native row only when its prepared role is not 'invisible' (server/world/dungeons.mjs spawn),
 *  and a brick completion is observable only when the instance itself holds that breakable brick. */
const observable = (c, monsterDef, bricks) => c.brick ? !!hostBrick(c, bricks) : c.monsters.every(index => { const def = monsterDef(index); return !!def && def.role !== 'invisible'; });
const done = (c, killed, bricks) => c.brick ? hostBrick(c, bricks)?.dead === true : c.monsters.reduce((sum, index) => sum + kills(killed, index), 0) >= c.count;

/**
 * Host-observed native StageIndex of a map-49 instance.
 * @param {{map:number, info:object, monsterDef:(index:number)=>object, killed:Map|object|function, bricks?:Map|object|function}} input
 *   `killed` is the host director's own per-monster death tally (Director.killedIdx) and `bricks` its own
 *   live bricks by placement uid (Director.brickByUid), never client data.
 * @returns {{stage:number, reached:number[], unobservable:number[]}|null} null when not map 49 or the
 *   native facts above cannot be authenticated.
 */
export function nativeStageIndex({ map, info, monsterDef, killed, bricks } = {}) {
  if (Number(map) !== CHERUBIM_MAP || cherubimStageMismatch(info, monsterDef)) return null;
  let stage = STAGES[0][0];
  const reached = [], unobservable = COMPLETIONS.filter(c => !observable(c, monsterDef, bricks)).map(c => c.stage);
  for (const c of COMPLETIONS) {
    if (unobservable.includes(c.stage)) continue;
    if (!done(c, killed, bricks)) break;
    stage = c.stage; reached.push(c.stage);
  }
  return { stage, reached, unobservable };
}

/** The native maprespawn entry {stage, x, y} for the host-observed StageIndex, or null (use the first entry). */
export function nativeStageRespawn(input = {}) {
  const at = nativeStageIndex(input);
  if (!at) return null;
  const entry = input.info.stageRespawn.stages.find(s => Number(s.stage) === at.stage);
  return entry ? { stage: Number(entry.stage), x: Number(entry.x), y: Number(entry.y) } : null;
}
