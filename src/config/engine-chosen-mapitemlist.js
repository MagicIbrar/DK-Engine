// UI-MAPITEMLIST: ENGINE-CHOSEN (not in Global data). The original server sends the "Main Reward Item List" content
// (game2/itemlist/ui_mapitemlist.txt); no client file lists it, so the engine builds it from the client's own monster spawn
// and drop tables (share/map MON_* / callmonster_*, share/item/monsterdropitemtable.csv + itemset.csv = gamedata/monsters.json)
// with the rules below. Listed in docs/UI-MAPITEMLIST.md.
export const MAPITEMLIST_CONFIG = Object.freeze({
  commonRegionShare: 0.5,       // an item that drops in at least half of the regions with drops is "Common (All Regions)" (2004:127)
  commonOutOfMaps: true,        // Common items are listed once under Common, not again under every map
  otherRegionName: 'Other Regions', // maplist TerritoryIndex 0 groups unrelated maps; it has no region name in the data
  regionNameFrom: 'lowestIndexMap', // a region (TerritoryIndex 1..n) is named after its lowest-index maplist map (3 Deneb, 5 Heihaff...)
  mergeSameName: true,          // maps sharing a name inside one region (Guild Hideout x10, Tower of Spell 1F x2) are one entry
  sort: 'reqLvDescThenName',    // highest required level first (the "main" rewards), then by name
  search: 'substringInSelection', // Search: case-insensitive part of the item name, inside the selected entry; Reset clears it
  defaultSelection: 'currentMapElseAll', // opened from the big map: the current map's entry when it has one, else All
});