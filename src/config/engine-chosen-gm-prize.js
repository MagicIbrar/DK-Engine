// GM event prizes on the shared server. Some original items only ever come from GM-hosted events: Camouflage
// [Frontier] 1755139 (share/system_variable.csv index 51, the Frontier dungeon entry item; itemcash Trade 0 and the
// 999999 not-for-sale cost; no shop, box, quest, drop or event row). The original GM tool privileges
// (share/server/gradelist.csv) have no "give an item to a character" entry, so the grant below is an engine design.
// ENGINE-CHOSEN command: /gm giveitem <character> <item> [count] [upgrade] [sockets] [option value]... takes the
// makeitem arguments and bounds after one character name. The host creates the item in that character's bag, so an
// untradeable prize needs no trade, mail or transfer rule, and those refusals stay unchanged.
// ENGINE-CHOSEN recipients: connected player characters only, by exact character name (case-insensitive). Offline
// characters and bots are refused, so the prize lands while its owner is playing.
// ENGINE-CHOSEN receipt: every grant is written in the same atomic save as the item, to the durable shared document
// as gmPrizes (newest `receipts` kept): id, time, granting GM character, recipient, item, count, upgrade.
// ENGINE-CHOSEN notice: the recipient sees one system chat line naming the GM, the item and the count.
export const GM_PRIZE=Object.freeze({
 command:'giveitem',
 receipts:500,
 notice:(gm,item,count)=>`GM ${gm} granted you ${item} x${count}.`,
 label:'ENGINE-CHOSEN GM prize grant: online player recipients, atomic item + receipt save, private notice',
});
