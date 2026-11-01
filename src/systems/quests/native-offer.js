// Native quest offering paths. A character can only take a quest where the original client/server offers it:
//   menu     npc.csv lists the quest under one of this NPC's quest jobs (1 QUEST, 57 DAILY_QUEST_STD, 106 QUEST_MAIN,
//            114 MISSION_TITLE) - the NPC dialog menu (dialog.js menuEntries)
//   board    this NPC's request board (office_set, jobs 18 REQUEST_QUEST / 54 DAILY_REQUEST_QUEST) lists it (QuestBoard)
//   giver    an original NPC job or board offers the quest and this NPC is its start NPC (questtable S_npc / listing NPC)
//   chain    this NPC starts the quest and it is the reward NextIndex of a quest the character completed (dialog.js
//            _afterClaim opens the next quest at the same NPC)
//   starter  the new character's first main-story quest in Ardeca (QuestStartDialog, no NPC)
// Anything else (giverless or unlisted legacy/event quests) has no original offer. Accept/claim rules, levels,
// prerequisites and limits stay in QuestEngine.check(); this only answers "is it offered here".
export const QUEST_MENU_JOBS = Object.freeze([1, 57, 106, 114]);
export const BOARD_JOBS = Object.freeze([18, 54]);

const previousIndex = new WeakMap();
function previousOf(quests, id) {
  if (!quests || typeof quests !== 'object') return [];
  let index = previousIndex.get(quests);
  if (!index) {
    index = new Map();
    for (const q of Object.values(quests)) if (q && !q.isGroup && q.next != null) {
      const key = Number(q.next);
      if (!index.has(key)) index.set(key, []);
      index.get(key).push(Number(q.id));
    }
    previousIndex.set(quests, index);
  }
  return index.get(Number(id)) || [];
}

/** The main story's first quest in Ardeca (same rule as server/world/quests.mjs starterQuest). */
export function starterQuestId(catalog) {
  return (catalog?.lines?.main?.story || []).find(id => {
    const q = catalog?.quests?.[id];
    return Number(q?.giver?.map) === 150 && (q.level?.[0] || 1) <= 1;
  }) ?? 9414;
}

export function questGivers(q) {
  return [q?.giver?.npc, ...(q?.giver?.alt || [])].filter(n => n != null).map(Number);
}

/**
 * The native path through which `npc` offers quest `q` to this character, or null.
 * @param catalog  the quest catalogue ({quests, lines}) the quest came from
 * @param isDone   (questId) => completed by this character (NextIndex chain)
 * @param starter  the request comes from the starter offer (no NPC)
 */
export function nativeOfferPath(catalog, q, npc, { isDone = () => false, starter = false } = {}) {
  if (!q || q.isGroup) return null;
  if (starter) return Number(q.id) === Number(starterQuestId(catalog)) ? 'starter' : null;
  if (!Number.isInteger(npc)) return null;
  for (const [n, jobType] of q.listedBy || []) {
    if (Number(n) !== npc) continue;
    if (QUEST_MENU_JOBS.includes(Number(jobType))) return 'menu';
    if (BOARD_JOBS.includes(Number(jobType))) return 'board';
  }
  if (!questGivers(q).includes(npc)) return null;
  if (q.offered) return 'giver';
  if (previousOf(catalog?.quests, q.id).some(id => isDone(id))) return 'chain';
  return null;
}

/** Whether any original NPC, board or chain can ever offer this quest (for the refusal text). */
export function questHasNativeOffer(catalog, q) {
  return !!q && !q.isGroup && (!!q.offered || (q.listedBy || []).length > 0 || (questGivers(q).length > 0 && previousOf(catalog?.quests, q.id).length > 0) || Number(q.id) === Number(starterQuestId(catalog)));
}
