// Recovered server reward blocks for three dialog-only ticket-issuance quests. The client keeps their NPC
// jobs, dialog trees, messages and the issued items, but share/quest/quest_rewardlist.csv has no row for
// quests 35, 262 or 272 (the Global Copy packs carry the same bytes). Only exact authored evidence is used,
// in the same way as native-title-exchanges.js; any mismatch leaves the quest as its dialog-only original.
//
// AUTHENTICATED NATIVE FACTS, per quest (all validated below):
//  - share/creature/npc.csv: the entrance NPC lists the quest as its own job
//    (5525 job 1:35, 4156 job 57:262, 4157 job 57:272).
//  - The quest's own strings (script/string/quest/stringtable_quest_0.txt cate 35,
//    stringtable_quest_200.txt cates 262/272): free issuance twice a day; at most one held
//    (message 1000); used within 60 minutes; rounds 3-5 cost 2 Super Passes (message 1001);
//    five round menus 10001/10011/10021/10031/10041; success message 1003.
//  - Quest 35 also says "Only full-power Seongsu users can receive additional issuance." (1002).
//    Quests 201 and 225 use the same code for "Players with Holy Water of Almighty can receive
//    additional tickets", so rounds 3-5 of quest 35 also need an active Holy Water of Almighty service.
//  - The issued item is the one item with the quest's ticket name and a 3600-second item-table
//    period: 4000268 "Norak Secret Arena Admission Ticket", 4002358 "[Cartel] Infinite battle admission
//    ticket", 4002359 "Colosseum[Infitite battle] admission ticket".
//  - Native ticket rows of the same dialog family (quest_rewardlist 201/225/261/271/281: SubNo_Check,
//    Repeat_Count per round, Reward_Dupl_Check=1, Item_Limit + Limit_Time 3600,
//    Take_Index "4002293/7550" x2) give the row layout the engine already plays for quest 261.
//
//  - Quest 262's offer (stringtable_quest_200.txt cate 262) adds "or Infinite Battle1 ticket x1" for rounds 3-5.
//    The only items with that name are the bound/unbound pair 7285 "Infinite Battle1 Entrance Ticket (Bind)"
//    and 171041 "Infinite Battle1 Entrance Ticket" (share/item/itemetc.csv), whose description 254 reads
//    "Cartel, Colosseum, Stardion [Infinite Battle] can be used." It is offered as an OR-cost (takeAny).
//    Quest 272's offer does not list it, so 272 does not accept it.
//
// DELIBERATE ENGINE CHOICES: the "Warrior's Infinite Battle B rank ticket" (262) and "A fighter's Infinity
// Battle A rank admission ticket" (272) alternatives are NOT recovered: no item carries those names (the
// nearest are "Gladiator's ..." 171039/171040 and the unprefixed/event Rank tickets), so choosing one would be
// invented. Only the evidenced Super Pass and Infinite Battle1 costs are offered.
// The daily reset is the quest engine's existing period key (also used by native quest 261).
export const SUPER_PASSES = Object.freeze([4002293, 7550]);
export const INFINITE_BATTLE1 = Object.freeze([7285, 171041]);
const BATTLE1_NAMES = Object.freeze({ 7285: 'Infinite Battle1 Entrance Ticket (Bind)', 171041: 'Infinite Battle1 Entrance Ticket' });
const PAGES = Object.freeze([10000, 10010, 10020, 10030, 10040]);
const MENUS = Object.freeze([10001, 10011, 10021, 10031, 10041]);

const BINDINGS = Object.freeze([
  Object.freeze({ quest: 35, npc: 5525, job: 1, item: 4000268, itemName: 'Norak Secret Arena Admission Ticket', file: 'share/quest/quest_35_dungeon_ticket.csv',
    title: 'Norak Secret Arena Entry Ticket Issuance', offer: ['issued twice a day for free', "can't have more than one item", 'used within 60 minutes', '3rd to 5th rounds', 'super pass 2pcs'],
    messages: { 1000: 'already have at least one ticket', 1001: 'not enough super pass', 1002: 'Only full-power Seongsu users can receive additional issuance', 1003: 'admission ticket to Norak Secret Arena has been issued' }, holyWater: true }),
  Object.freeze({ quest: 262, npc: 4156, job: 57, item: 4002358, itemName: '[Cartel] Infinite battle admission ticket', file: 'share/quest/quest_00262_python_entering_plus.csv',
    title: 'Cartel [Infinite Battle] ticket issuance', offer: ['issued 2 times for a day with free of charge', 'cannot have the item 1 or more', 'used within 60 minutes', '3rd round ~ 5th round', 'Super Pass x2'],
    messages: { 1000: 'already have 1 or more tickets', 1001: 'enough Super Pass for the extra issuance', 1003: 'Cartel [Infinite Battle] ticket issued' }, battle1: true }),
  Object.freeze({ quest: 272, npc: 4157, job: 57, item: 4002359, itemName: 'Colosseum[Infitite battle] admission ticket', file: 'share/quest/quest_00272_elleghos_entering_plus.csv',
    title: 'Colosseum [Infinite Battle] Ticket Issuance', offer: ['issued for free only twice a day', 'cannot have more than one of these items', 'used within 60 minutes', '3rd ~ 5th round', 'Super Pass 2ea'],
    messages: { 1000: 'already have more than one ticket', 1001: 'not enough Super Passes for additional issuance', 1003: 'Colosseum [Infinite Battle] tickets have been issued' } }),
]);

const plain = s => String(s ?? '').replace(/<[^>]+>/g, '').replace(/\s+/g, ' ').trim();
const itemDef = (game, index) => { try { return game?.items?.db?.def?.(index) || game?.items?.def?.(index) || null; } catch { return null; } };

/** Why binding `b` does not hold for these prepared tables, or null when every native fact matches. */
export function ticketIssuanceMismatch(b, quests, dialogs, game) {
  const q = quests?.quests?.[b.quest], tree = dialogs?.quests?.[b.quest], strings = dialogs?.strings?.[b.quest] || {};
  if (!q || q.kind !== 'dialog' || q.rewards || q.rewardVariants || q.objectives?.length) return 'quest is not the dialog-only original';
  if (q.dialog?.file !== b.file || tree?.file !== b.file) return 'dialog file differs';
  if (Number(q.giver?.npc) !== b.npc || Number(q.turnIn?.npc) !== b.npc) return 'giver differs';
  if (!(dialogs?.npcs?.[b.npc]?.jobs || []).some(j => Number(j[0]) === b.job && Number(j[1]) === b.quest)) return 'NPC job differs';
  if (plain(strings[11]) !== b.title) return 'title differs';
  const offer = plain(strings[10000]);
  for (const t of b.offer) if (!offer.toLowerCase().includes(t.toLowerCase())) return `offer text lacks "${t}"`;
  for (const [code, t] of Object.entries(b.messages)) if (!plain(strings[code]).includes(t)) return `message ${code} differs`;
  if (!b.holyWater && strings[1002] != null && /holy water|seongsu/i.test(strings[1002])) return 'unexpected Holy Water message';
  const messages = new Map((tree.messages || []).map(m => [Number(m[0]), m]));
  for (const [k, page] of PAGES.entries()) { const m = messages.get(page); if (!m || !(m[2] || []).map(Number).includes(MENUS[k])) return `round ${k + 1} page differs`; }
  if (!/5th/.test(plain(strings[MENUS[4]]))) return 'fifth round label differs';
  const def = itemDef(game, b.item);
  if (!def || def.name !== b.itemName || Number(def.period) !== 3600 || Number(def.type) !== 0 || ![4, 5].includes(Number(def.code))) return 'issued item differs';
  for (const index of SUPER_PASSES) if (!/^Super Pass( \(Bind\))?$/.test(itemDef(game, index)?.name || '')) return 'Super Pass item differs';
  if (b.battle1) {
    if (!/or Infinite Battle1 ticket x1/i.test(offer)) return 'offer text lacks the Infinite Battle1 alternative';
    for (const index of INFINITE_BATTLE1) { const d = itemDef(game, index); if (d?.name !== BATTLE1_NAMES[index] || Number(d?.desc) !== 254) return 'Infinite Battle1 item differs'; }
  } else if (/Infinite Battle1/i.test(offer)) return 'unexpected Infinite Battle1 alternative';
  return null;
}

function recovered(b, q) {
  const timedItem = { item: b.item, seconds: 3600 }, raw = { Repeat_Check: 1, Reward_Dupl_Check: 1 };
  const round = n => ({ id: n === 1 ? String(b.quest) : `${b.quest}.0${n - 1}`, repeat: n, msg: PAGES[n - 1],
    reward: n <= 2 ? { timedItem, raw } : { take: [{ item: [...SUPER_PASSES], count: 2 }], ...(b.battle1 ? { takeAny: [[{ item: [...SUPER_PASSES], count: 2 }], [{ item: [...INFINITE_BATTLE1], count: 1 }]] } : {}), timedItem, raw, ...(b.holyWater ? { requireHolyWater: true } : {}) } });
  return { ...q, kind: 'exchange', require: { ...(q.require || {}), instant: true }, repeat: { ...(q.repeat || {}), daily: true, perPeriod: 5 },
    rewards: { timedItem, raw }, rewardVariants: { mode: 'repeat', list: [1, 2, 3, 4, 5].map(round) }, recoveredFrom: b.file };
}

/** Quest table with the three recovered issuance blocks; unchanged when any native fact differs. */
export function nativeTicketIssuance(quests, dialogs, game) {
  let out = quests;
  for (const b of BINDINGS) {
    if (ticketIssuanceMismatch(b, quests, dialogs, game)) continue;
    out = { ...out, quests: { ...out.quests, [b.quest]: recovered(b, quests.quests[b.quest]) } };
  }
  return out;
}
export const NATIVE_TICKET_BINDINGS = BINDINGS;
