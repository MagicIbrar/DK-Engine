// EVENT-MODES host: Mission titles (share/pc/title/title_base.csv = gamedata/life.json grade.titles, also
// world.data.nameplateTitles). The host owns which titles a character has (profile.life.titles) and which one it shows
// (profile.life.grade.titleIndex, read by server/world/nameplates.mjs). Earning: src/systems/life/title-rules.js with the
// TITLE_CHOSEN readings (Type 1 kills, Type 7 downed-by, Type 9 locked until grantTitle; 20 Solo Champion from a durable
// Colosseum Arena (Solo) clear, earnDungeonClearTitle). Hooks: recordTitleKill from
// server/world/life-events.mjs recordLifeEventKill (every monster the host rewards), noteMonsterHit from
// server/world/skills.mjs incomingSkillDamage (every monster hit on a character) + tickTitles (server/world/events.mjs).
import { titleProgress, titleState, ownsTitle, grantTitleState, dungeonClearTitle } from '../../src/systems/life/title-rules.js';

// The original title-system strings (script/string/normal/stringtable_title_syetem.txt cate 2802, "[message]" removed;
// <VALUE> = title name, [COUNT1]/[COUNT2] = have / need). tools/test-event-modes.mjs compares them with the table.
export const TITLE_TEXT = {
  earned: '[<VALUE>] Title Obtained',                          // 2802|3
  notOwned: 'Unacquired Title',                                // 2802|4
  unknown: "Title doesn't exist.",                             // 2802|5
  applied: 'Title already applied.',                           // 2802|7
  progress: '[<VALUE>] Title [COUNT1]/[COUNT2] in progress',   // 2802|9
  none: 'There is no title that has been applied',             // 2802|10
};
export const titleText = (text, value, have, need) => text.replace('<VALUE>', value).replace('[COUNT1]', have).replace('[COUNT2]', need);
const titlesOf = world => world.data?.nameplateTitles || [];
const counted = new WeakMap();
const DOWNED_BY_WINDOW_MS = 2000;   // a downed character counts the monster whose hit landed in the same host step
export function refreshTitleStats(world,p){
  if(typeof world.data?.stats!=='function')return;
  p.stats=world.data.stats(p.profile,p,world.now());p.maxHp=p.stats.maxHp;
  p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp||0,p.stats.maxMp||0);
  p.maxShield=Math.max(0,Number(p.stats.maxShield)||0);p.shield=Math.min(Number(p.shield)||0,p.maxShield);
}

function save(world, p, next, earned, progress = []) {
  p.profile.life ||= {};
  p.profile.life.titles = next;
  if(earned.length)refreshTitleStats(world,p);
  world.changed(p);
  const name = index => titlesOf(world).find(row => row.Index === index)?.Name || `#${index}`;
  const say = text => world.emit(p.map, { type: 'event:message', text, recipients: [p.id], actorId: p.id });
  for (const r of progress) say(titleText(TITLE_TEXT.progress, name(r.index), r.have, r.need));
  for (const index of earned) say(titleText(TITLE_TEXT.earned, name(index)));
}
/** A monster this host rewarded to p (counted once per death). */
export function recordTitleKill(world, p, m) {
  if (!p || p.leaving || !m?.dead || !titlesOf(world).length) return false;
  const mark = counted.get(m); if (mark && mark.at === m.respawnAt && mark.ids.has(p.id)) return false;
  if (!mark || mark.at !== m.respawnAt) counted.set(m, { at: m.respawnAt, ids: new Set([p.id]) }); else mark.ids.add(p.id);
  const r = titleProgress(titlesOf(world), p.profile.life?.titles, { kind: 'kill', monster: m.monsterIndex ?? m.def?.index });
  if (!r.changed) return false;
  save(world, p, r.state, r.earned, r.progress); return true;
}
/** The monster that just hit p (the host's monster attack step). */
export function noteMonsterHit(world, p, m) { const index = Number(m?.monsterIndex ?? m?.def?.index); if (p && Number.isSafeInteger(index)) p.lastMonsterHit = { index, at: world.now() }; }
/** p went down: a monster hit in the same step counts for Type 7. */
export function recordTitleDowned(world, p) {
  const h = p.lastMonsterHit; delete p.lastMonsterHit;
  if (!h || world.now() - h.at > DOWNED_BY_WINDOW_MS || (p.pvpLastHit && p.pvpLastHit.at >= h.at)) return false;
  const r = titleProgress(titlesOf(world), p.profile.life?.titles, { kind: 'downedBy', monster: h.index });
  if (!r.changed) return false;
  save(world, p, r.state, r.earned, r.progress); void world.persist?.(p)?.catch?.(() => {}); return true;
}
export function tickTitles(world) {
  if (!titlesOf(world).length) return;
  for (const p of world.players.values()) {
    if (p.leaving) continue;
    if (p.dead || p.hp <= 0) { if (!p.titleDownSeen) { p.titleDownSeen = true; recordTitleDowned(world, p); } }
    else p.titleDownSeen = false;
  }
}
/** Select an owned title (0 = none). */
export function selectTitle(world, p, index) {
  const i = Number(index);
  if (!Number.isSafeInteger(i) || i < 0) throw Object.assign(new Error(TITLE_TEXT.unknown), { status: 400 });
  if (i && !titlesOf(world).some(t => t.Index === i)) throw Object.assign(new Error(TITLE_TEXT.unknown), { status: 400 });
  if (i && !ownsTitle(p.profile.life?.titles, i)) throw Object.assign(new Error(TITLE_TEXT.notOwned), { status: 400 });
  const current = Number(p.profile.life?.grade?.titleIndex) || 0;
  if (i && i === current) throw Object.assign(new Error(TITLE_TEXT.applied), { status: 400 });
  if (!i && !current) throw Object.assign(new Error(TITLE_TEXT.none), { status: 400 });
  p.profile.life ||= {};
  p.profile.life.grade = { ...(p.profile.life.grade || {}), titleIndex: i };
  world.changed(p);
  return { titleIndex: i };
}
/**
 * A dungeon clear the host is committing (server/world/dungeons.mjs recordDungeonResult, inside the instance-progress
 * transaction): grants the TITLE_DUNGEON_CLEARS title on the STAGED profile p. It becomes visible only when the atomic save
 * succeeds; a failed save drops the staged copy and its message, the transaction retries, and the progress receipt and the
 * owned list stop any second grant. Returns the earned index (0 = none).
 */
export function earnDungeonClearTitle(world, p, clear) {
  const index = dungeonClearTitle(clear);
  if (!index) return 0;
  const r = grantTitleState(titlesOf(world), p.profile.life?.titles, index);
  if (!r.granted) return 0;
  p.profile.life ||= {};
  p.profile.life.titles = r.state;
  const name = titlesOf(world).find(row => row.Index === index)?.Name || `#${index}`;
  world.emit(p.map, { type: 'event:message', text: titleText(TITLE_TEXT.earned, name), recipients: [p.id], actorId: p.id });
  return index;
}
/** Host grant (Type 9 titles have no condition data; only the host's own earned conditions call this). */
export function grantTitle(world, p, index) {
  const r = grantTitleState(titlesOf(world), p.profile.life?.titles, index);
  if (r.granted) save(world, p, r.state, [Number(index)]);
  return r.granted;
}
export function titleSnapshot(p) { return titleState(p.profile.life?.titles); }
