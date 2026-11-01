// Mission titles (share/pc/title/title_base.csv via gamedata/life.json grade.titles): which titles a character owns and
// how it earns them. Shared by the host (server/world/titles.mjs), the offline Grade system (src/systems/life/grade.js),
// the character window title tab and tools/test-event-modes.mjs. Readings of the data gaps:
// src/config/engine-chosen-event-modes.js TITLE_CHOSEN (Type 1 kills, Type 7 downed-by, Type 9 locked until granted, the
// Type 9 rows whose description names a dungeon clear = TITLE_DUNGEON_CLEARS).
export const TITLE_KILL = 1, TITLE_DOWNED_BY = 7, TITLE_SCRIPT = 9;

const n = v => Number(v) || 0;
/** Condition of one title row: {kind:'kill'|'downedBy'|'script', monster, count}. */
export function titleCondition(t) {
  const type = n(t?.Type);
  if (type === TITLE_KILL) return { kind: 'kill', monster: n(t.Type_Value1), count: Math.max(1, n(t.Type_Value2)) };
  if (type === TITLE_DOWNED_BY) return { kind: 'downedBy', monster: n(t.Type_Value1), count: Math.max(1, n(t.Type_Value2)) };
  return { kind: 'script', monster: 0, count: 0 };
}
/** Monsters any Type 1 / Type 7 title counts ({kill:Set, downedBy:Set}); progress is only stored for these. */
export function titleMonsters(titles = []) {
  const out = { kill: new Set(), downedBy: new Set() };
  for (const t of titles) { const c = titleCondition(t); if (c.kind !== 'script' && c.monster) out[c.kind].add(c.monster); }
  return out;
}
/** A clean copy of a stored title state {owned:[index], kill:{monster:n}, downedBy:{monster:n}}. */
export function titleState(s) {
  const o = s && typeof s === 'object' ? s : {};
  const map = m => Object.fromEntries(Object.entries(m && typeof m === 'object' ? m : {}).filter(([k, v]) => Number.isSafeInteger(Number(k)) && Number.isSafeInteger(v) && v > 0));
  return { owned: [...new Set((Array.isArray(o.owned) ? o.owned : []).filter(i => Number.isSafeInteger(i) && i > 0))].sort((a, b) => a - b), kill: map(o.kill), downedBy: map(o.downedBy) };
}
export function ownsTitle(state, index) { return !!index && titleState(state).owned.includes(Number(index)); }

/** One event ({kind:'kill'|'downedBy', monster}) -> {state, earned:[index], progress:[{index, have, need}] (titles still unfinished that this event counted for)}; state unchanged and earned [] when nothing counts. */
export function titleProgress(titles, state, { kind, monster }) {
  const st = titleState(state), m = n(monster);
  if (!['kill', 'downedBy'].includes(kind) || !titleMonsters(titles)[kind].has(m)) return { state: st, earned: [], progress: [], changed: false };
  st[kind][m] = (st[kind][m] || 0) + 1;
  const earned = [], progress = [];
  for (const t of titles) {
    const c = titleCondition(t);
    if (c.kind !== kind || c.monster !== m || st.owned.includes(t.Index)) continue;
    if (st[kind][m] >= c.count) { st.owned.push(t.Index); earned.push(t.Index); } else progress.push({ index: t.Index, have: st[kind][m], need: c.count });
  }
  st.owned.sort((a, b) => a - b);
  return { state: st, earned, progress, changed: true };
}
// Type 9 titles whose native description (2803|<Index>) names one dungeon clear. 20 "Solo Champion": 2803|20 "Clear Colosseum
// Arena (Solo) in Ardeca's Colosseum Lobby." = dungeonlist 615 "Colosseum Arena" (Keeper_Type SOLO, title "Colosseum Arena
// (Solo)", entry NPC 5931 Dein in the Colosseum Lobby 162). The party arena 616 and the Colosseum matches (Battle Royale,
// Individual Match) are other modes and earn nothing here.
export const TITLE_DUNGEON_CLEARS = Object.freeze([Object.freeze({ title: 20, dungeon: '615', keeper: 'SOLO' })]);
/** The title a clear of the last floor of dungeon `dungeonId` earns its one runner (0 = none). */
export function dungeonClearTitle({ dungeonId, keeper, lastFloor, members } = {}) {
  const row = TITLE_DUNGEON_CLEARS.find(r => r.dungeon === String(dungeonId));
  return row && keeper === row.keeper && lastFloor === true && members === 1 ? row.title : 0;
}
/** Host grant of a title (Type 9 has no condition data; only the host's own earned conditions call this). */
export function grantTitleState(titles, state, index) {
  const st = titleState(state), i = n(index);
  if (!titles.some(t => t.Index === i) || st.owned.includes(i)) return { state: st, granted: false };
  st.owned.push(i); st.owned.sort((a, b) => a - b); return { state: st, granted: true };
}
/** Window rows: every title with owned flag and progress ({have, need} for Type 1 / 7). */
export function titleRows(titles = [], state) {
  const st = titleState(state);
  return titles.map(t => { const c = titleCondition(t); return { index: t.Index, name: t.Name, owned: st.owned.includes(t.Index), kind: c.kind, have: c.kind === 'script' ? null : Math.min(c.count, st[c.kind][c.monster] || 0), need: c.kind === 'script' ? null : c.count }; });
}
