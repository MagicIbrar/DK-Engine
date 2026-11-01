// ENGINE-CHOSEN: what a scripted vehicle-purchase dialog sells.
// Ardeca's NPC Sergio lists "Purchase Swift Box" (quest 15820, share/quest/quest_15820_vehiclepurchase.csv). The original CSV only
// holds the dialog pages; the transaction lives on the original server, so it is rebuilt from what the pages say:
//   - ten pages (15000..15009) each name the DIL price of that purchase ("the price will go up with each purchase", x3 every time),
//   - the first page says "Available for purchases over 80 levels",
//   - menu 15201 "Purchase." pays and 15202 "Maybe next time." leaves, page 15100 "I don't have any left in stock." follows the tenth.
// Prices, level and the sold-out page are read from the dialog text at run time (src/systems/quests/vehicle-purchase.js); only the
// box the NPC hands over is chosen here: the text says "Swift Box", the item table has exactly one box of that name (1755570, the box
// with the Swift Debris bonus, docs/formats/boxes.md). How many a character has bought is stored per character (quests.flags),
// the original may count per account (not derivable).
export const VEHICLE_PURCHASE = Object.freeze({
  items: Object.freeze({ 15820: 1755570 }),
});
