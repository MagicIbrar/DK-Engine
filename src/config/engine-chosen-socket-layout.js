// SOCKET STONES DRAWN ON AN ITEM ICON (bag / equipment slot / drag icon). The Global data gives every item its own
// footprint (item.dat Width / Height = inventory cells, e.g. staff 1x4, wand / sword 1x3, Bagi gauntlet 2x2, shield 2x3, bow /
// great axe 2x4) and its socket count, but no coordinates of the stones drawn over the icon. The stones are therefore placed
// from the item's OWN footprint (src/ui/uiwin/controls.js socketFootprintGrid), never from a class- or kind-wide default.
// Every entry is ENGINE-CHOSEN (not in Global data).
export const SOCKET_ICON_LAYOUT_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): stones stack along the item's longer side (tall items: down the height, wide items: across
   *  the width) and wrap onto the other axis only when that side is too short for the count; a square footprint fills across first
   *  (2x2 -> 2 + 2, as before). Footprint 1x4 -> 1 column of 4, 1x3 -> 3, 2x3 with 3 stones -> 3 rows, 2x3 with 4 -> 3 rows x 2
   *  columns, 2x4 -> 1 column, 2x2 with 4 -> 2x2. A tall grid fills column by column, a wide or square one row by row. */
  PLACEMENT: 'longer footprint side first; square footprint across first; tall grid column-major, wide/square grid row-major',
  /** ENGINE-CHOSEN (not in Global data): the most stones drawn on one icon (the item tables allow 1..4 sockets). */
  MAX_MARKERS: 4,
  /** ENGINE-CHOSEN (not in Global data): empty border (px) between the icon edge and the stones, and gap (px) between two stones. */
  PAD: 2,
  GAP: 2,
  /** ENGINE-CHOSEN (not in Global data): largest stone viewport (px); the native 32px Socket cell shows its 18px art centred in 20px. */
  MAX_SIZE: 20,
  /** Native Socket atlas cell edge (px), imagetable group Socket (Global data). */
  NATIVE_CELL: 32,
});
