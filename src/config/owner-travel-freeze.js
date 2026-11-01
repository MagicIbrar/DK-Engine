// ENGINE-CHOSEN (Global behaviour; no data file holds it - the original progress windows
// game2/ui_warpteleportwnd.txt / ui_systemwaitwnd.txt carry a bar and Cancel but no duration, and the timing lives in the
// packed client): changing channel and the big map's teleports (map NPC teleport, Select Warp / Party Warp) take a 10 second
// bar during which the character cannot move, so a fight cannot be escaped instantly. Taking damage still interrupts the
// cast (server/world/travel.mjs). The Blessing Warp Stone's Smart Warp keeps its original 3 s cast.
export const TRAVEL_FREEZE_MS = 10000;
/** Cast kinds (p.smartWarp.kind) that freeze movement while they prepare. */
export const TRAVEL_FREEZE_KINDS = Object.freeze(['channel', 'mapnpc', 'premium']);
