// QUEST REWARDS and EARNED TITLE 27. Every reward identity, refusal code and title condition comes from the Global data
// (quest journals code 12, item names / box contents, title_base.csv and stringtable_title_syetem 2803, dungeonlist, map
// call tables). Only the gaps the data leaves open are listed here, each on its own tagged line.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const QUEST_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): a commission journal printing "1 of following" / "1 random from the list" gives each printed alternative an equal share (the client has no weights); an alternative whose item has no native row keeps its share and, when drawn, grants only the guaranteed part (the claim reports the skipped line). Shares are never renormalised over the remaining alternatives.
  randomAlternatives: 'equal share per printed line; absent item keeps its share',
  // ENGINE-CHOSEN (not in Global data): quest 9755 "1 Wedding Box (2 hours)" = the native Wedding Box (2 Hours) of the claiming class (13 class rows exist); Alokes and Trie Muse have no box row, so their line stays unresolved and nothing is manufactured.
  classWeddingBox: 'box of the claiming class',
  // ENGINE-CHOSEN (not in Global data): a journal name carried by two native rows (Scroll of Vitality / Patience) is the lowest index, the base row, as preparation resolves duplicate names.
  duplicateName: 'lowest index (base row)',
  // ENGINE-CHOSEN (not in Global data): an event quest whose earned outcome cannot exist in the data (no item row for its reward or required item, no spawn / call row for its target, no producer for its material) is refused with the native common 1027 "This quest cannot be conducted today."; a non-event quest in the same state with 1050 "Cannot complete yet.".
  absentOutcome: 'event 1027, other 1050',
  // ENGINE-CHOSEN (not in Global data): title 27 "Karon's Fragment Hard/Core" = dungeonlist 603 Karon's Fragments (Hard) or 602 Karon's Fragments (Core) (entered at Karon's Remnants 1239); either one completes it, in one run. The unentered 601 / 604 "Karon's Fragments Hard" rows have no entry NPC.
  title27Dungeons: Object.freeze(['602', '603']),
  // ENGINE-CHOSEN (not in Global data): "all monsters" = every monster row the run spawned (creature and object roles; invisible helpers and bricks excluded), with every stage of the floor spawned and the native clear reached.
  title27Population: 'every spawned monster of a fully spawned, cleared run',
  // ENGINE-CHOSEN (not in Global data): only a death that reached the host reward path from a live member inside that instance counts as defeated; any other death (GM kill-all, a GM one-hit attack, a death without a rewarded killer) means that run can no longer earn the title.
  title27Kills: 'host-rewarded kills by live members only',
  // ENGINE-CHOSEN (not in Global data): the title goes to every member inside the instance when the last monster falls, in one durable party write (failed write: nothing granted, retried; receipts stop a replay).
  title27Recipients: 'every member present, one durable write',
});

export function questChosenList() {
  return Object.entries(QUEST_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'string' ? v : JSON.stringify(v)}`);
}
