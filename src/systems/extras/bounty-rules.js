// Monster bounty (the Wanted Notice Board), every rule from the client data (no DOM here; tools/test-monster-bounty.mjs):
//   window   script/ui/game2/monsterbounty/ui_monsterbountywnd.txt: 7 posters pan_montage_1..7 (clones of pan_montage_1:
//            pan_monster portrait, lbl_monstername, lbl_location, lbl_npc, pan_clear stamp), btn_prevpage / btn_nextpage,
//            lbl_page, lbl_info (text2 2304 1 "Upon completing the Wanted Quest, you will receive 1 [Fall Maple Leaf].")
//   NPC      npc 6214 "Wanted Notice Board" (shape wanted_board, an event placement on map 533 Mitera): its only job is
//            JobType 171 WANTED_EVENT and stringtable_jobtype.txt has no menu line for 171, so the board opens on the click
//   posters  the quests of category 'wanted' ([EVENT] Wanted Notice No.01..21 = quests 15853..15873), board order = No.NN of the
//            title, shown while their share/quest/specificperiodschedule.csv window is open (quests.json schedule: the same
//            gate the quest engine applies to accepting them)
//   portrait imagetable group 'monsterbounty', index = the poster's kill-target monster index (UI\Game\MonsterBounty\montage.dds)
//   texts    lbl_monstername = the kill target's name; lbl_location = the coloured place of the quest-details line
//            ("* Defeat <target> in [the] <color=..>PLACE</color>", quest string 12); lbl_npc = the completion NPC
//            ([nlink]N[/nlink] of the same text, else the quest's turn-in NPC)
//   clear    pan_clear (statusboard #5 "completed") when the character has completed the quest
// Not in the data (engine choices, documented): the page label format "p / n" and that the page buttons stop at the ends.
export const WANTED_EVENT_JOB = 171;
export const WANTED_CATEGORY = 'wanted';
export const BOUNTY_SCRIPT = 'game2/monsterbounty/ui_monsterbountywnd.txt';
export const DETAILS_STRING = 12;

/** The poster number of a wanted quest ("[EVENT] Wanted Notice No.07" -> 7). */
export function posterNumber(q) {
  const m = /No\.\s*(\d+)/i.exec(String(q?.title || q?.name || ''));
  return m ? Number(m[1]) : Infinity;
}

/** Is the quest's event window (schedule) open at `now` (ms)? Quests without a schedule always are. */
export function scheduleOpen(q, now) {
  const s = q?.schedule;
  if (!s) return true;
  const a = Date.parse(s.start), b = Date.parse(s.end);
  return !((Number.isFinite(a) && now < a) || (Number.isFinite(b) && now > b));
}

/** The wanted quests on the board at `now`, in board order. `quests` = quests.json quests (object or array). */
export function wantedQuests(quests, now) {
  return Object.values(quests || {})
    .filter(q => q && !q.isGroup && q.cat === WANTED_CATEGORY && scheduleOpen(q, now))
    .sort((a, b) => posterNumber(a) - posterNumber(b) || Number(a.id) - Number(b.id));
}

const LOCATION = /\bin\s+(?:the\s+)?<color=[0-9a-f]{6,8}>([^<]+)<\/color>/i;
/** The coloured place name of a quest-details text ("... in the <color=75ff42>Norak Cave Arena</color>"), or ''. */
export function posterLocation(text) {
  const m = LOCATION.exec(String(text || ''));
  return m ? m[1].trim() : '';
}

/** The completion NPC index of a quest-details text ([nlink]204[/nlink]), or null. */
export function posterNpc(text) {
  const m = /\[nlink\]\s*(\d+)\s*\[\/nlink\]/i.exec(String(text || ''));
  return m ? Number(m[1]) : null;
}

/** The kill target {id, name} a poster shows (the first target of the quest's kill objective). */
export function posterTarget(q) {
  const o = (q?.objectives || []).find(x => x?.kind === 'kill' && (x.targets || []).length) || (q?.objectives || []).find(x => (x?.targets || []).length);
  const t = o?.targets?.[0];
  return t ? { id: Number(t.id), name: String(t.name || '') } : null;
}

/**
 * Everything one poster shows. details = the quest's string 12 (quest details), npcName(n) resolves an NPC name.
 * @returns {{id:number, monster:number|null, name:string, location:string, npc:number|null, npcName:string}}
 */
export function posterOf(q, details, npcName = null) {
  const target = posterTarget(q);
  const npc = posterNpc(details) ?? (q?.turnIn?.npc != null ? Number(q.turnIn.npc) : null);
  const resolved = npc != null && npcName ? npcName(npc) : '';
  const turnIn = npc != null && npc === Number(q?.turnIn?.npc) ? q.turnIn.name : '';
  return { id: Number(q.id), monster: target ? target.id : null, name: target ? target.name : '', location: posterLocation(details), npc, npcName: String(resolved || turnIn || '') };
}

/** Number of pages for n posters with `per` posters per page (an empty board still shows page 1 / 1). */
export function pageCount(n, per) { return Math.max(1, Math.ceil(Math.max(0, n) / Math.max(1, per))); }

/** Clamp a page index into [0, pages - 1]. */
export function clampPage(page, n, per) { return Math.min(Math.max(0, Math.floor(Number(page) || 0)), pageCount(n, per) - 1); }

/** The posters of a page. */
export function pageItems(list, page, per) {
  const p = clampPage(page, list.length, per);
  return list.slice(p * per, p * per + per);
}

/** Does an NPC (actor or npcs.json def) belong to the board: its every job is WANTED_EVENT? */
export function isBoardNpc(npc) {
  const jobs = npc?.jobs || npc?.def?.jobs || [];
  return jobs.length > 0 && jobs.every(j => Number(j?.[0]) === WANTED_EVENT_JOB);
}
