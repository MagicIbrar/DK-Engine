// Lord's Treasure Chest of the active castles 193 Imperial / 194 Golden / 195 Conbelton (weekly reward).
//
// AUTHENTICATED NATIVE RULES (original data, read through the prepared gamedata; never edited):
//   share/map/19x_siege_new_*/trigger_*.csv  one chest trigger per castle: 193 trigger 1 at (494,37), 194 trigger 46 at
//                                            (211,36), 195 trigger 47 at (409,34): 6.5-8.5 cells from the castle's
//                                            Castellan Room location (location.csv type 5)
//   share/creature/trigger.csv               rows 1 / 46 / 47 "treasure box" (CP949 name), shape siege_box, two states
//   share/item/triggerdropitem.csv           rows 193:1 / 194:46 / 195:47, CondName <map>_Siege, no money and no random
//                                            sets; three fixed items (Fix_ItemIndex / Fix_ItemStack / CountMin..Max) and
//                                            five fixed item sets (Fix_ItemSet / CountMin..Max / FixItemSetRatio of 100000)
//   share/item/itemset.csv                   sets 5619-5629: [item, weight, stackMin, stackMax] rows of the castle token
//                                            (2/3/4 at 55000/35000/10000), the castle scrolls x25 and the common coin /
//                                            Arcane EXP scroll x10
//   Official guide 32 "Lord's Treasure Chest": castle lords obtain items once a week through the chest in their rooms,
//   from the end of the siege until the next siege begins; chests regenerate every Sunday at the end of the siege; items
//   drop according to probability. Its reward lists agree with the table ("Z coin 50" = Fix_ItemStack 50 x 1;
//   "Platinum HP Potion IV S Pack 2000 x 5 bundles" = Fix_ItemStack 2000 x CountMin..Max 5), so a fixed row grants
//   Fix_ItemStack units per counted bundle.
// CONFLICT (in-game value kept): the guide lists Empowered Blue/Black Scrolls for the Golden Castle, while the original
//   sets 5626 / 5627 hold 4002317 Empowered Gold Scroll and 4002318 Empowered Red Scroll. The table is used.
//
// ENGINE CHOICES (stated, not native):
//   - every fixed item set rolls independently against its ratio / 100000 and picks by weight inside the set: the same
//     reading the engine already applies to monster and dungeon trigger tables (src/game/loot.js);
//   - the server drop-rate multiplier is NOT applied: the weekly castle reward keeps the native ratios exactly;
//   - the reward goes straight into the lord's bag in the same atomic write as the weekly claim (instead of ground loot
//     that a restart would lose); a bag that cannot hold all of it refuses with the original 700:84 "Inventory is full.";
//   - the lord must stand within RADIUS cells of the native chest cell (the NPC service radius used by the controller).
export const RENEW_CHEST = Object.freeze({ castles: Object.freeze([193, 194, 195]), radius: 8, shape: 'siege_box', ratioScale: 100000 });

const int = v => (Number.isInteger(Number(v)) ? Number(v) : NaN);
const positive = v => Number.isInteger(v) && v > 0;

/** Validated native chest catalog: Map(map -> {map, trigger, x, z, dir, name, states, fixed, fixedSets, sets}) or null when any
 * authored input is missing or not of the supported shape (the chest then stays unavailable; nothing is approximated). */
export function renewChestCatalog(dungeonData, boxes, itemDB = null) {
  const dg = dungeonData?.dg || dungeonData, sets = boxes?.itemSets;
  if (!dg?.maps || !dg?.triggers || !dg?.triggerDrops || !sets) return null;
  const out = new Map();
  for (const map of RENEW_CHEST.castles) {
    const placed = (dg.maps[map]?.triggers || []).filter(t => dg.triggerDrops[t.drop || `${map}:${t.trigger}`]?.cond === `${map}_Siege`);
    if (placed.length !== 1) return null;
    const pl = placed[0], key = pl.drop || `${map}:${pl.trigger}`, row = dg.triggerDrops[key], def = dg.triggers[pl.trigger];
    if (!def || def.shape !== RENEW_CHEST.shape || Number(row.map) !== map || Number(row.trigger) !== Number(pl.trigger)) return null;
    if ((row.money || []).length || (row.sets || []).length || Number(row.maxItemSet) || Number(row.maxItemSetEx) || (row.setsEx || []).length || (row.fixedSetsEx || []).length) return null;
    const fixed = (row.fixed || []).map(([item, stack, min, max]) => ({ itemIndex: int(item), stack: int(stack), min: int(min), max: int(max) }));
    const fixedSets = (row.fixedSets || []).map(([set, min, max, socket, ratio]) => ({ set: int(set), min: int(min), max: int(max), socket: int(socket), ratio: int(ratio) }));
    if (!fixed.length || !fixedSets.length) return null;
    if (fixed.some(f => !positive(f.itemIndex) || !positive(f.stack) || !positive(f.min) || !(f.max >= f.min) || (itemDB && !itemDB.def(f.itemIndex)))) return null;
    if (fixedSets.some(f => !positive(f.set) || !positive(f.min) || !(f.max >= f.min) || f.socket !== 0 || !positive(f.ratio) || f.ratio > RENEW_CHEST.ratioScale)) return null;
    const used = {};
    for (const f of fixedSets) {
      const s = sets[f.set] || sets[String(f.set)], entries = (s?.e || s?.items || []).map(([item, weight, min, max]) => ({ itemIndex: int(item), weight: int(weight), min: int(min), max: int(max) }));
      if (!entries.length || entries.some(e => !positive(e.itemIndex) || !positive(e.weight) || !positive(e.min) || !(e.max >= e.min) || (itemDB && !itemDB.def(e.itemIndex)))) return null;
      used[f.set] = Object.freeze({ name: s.n || s.name || '', total: entries.reduce((n, e) => n + e.weight, 0), entries: Object.freeze(entries.map(e => Object.freeze(e))) });
    }
    out.set(map, Object.freeze({ map, trigger: Number(pl.trigger), key, x: Number(pl.x), z: Number(pl.y), dir: Number(pl.dir) || 0, name: row.name || def.name || '',
      states: def.states || [], fixed: Object.freeze(fixed.map(f => Object.freeze(f))), fixedSets: Object.freeze(fixedSets.map(f => Object.freeze(f))), sets: Object.freeze(used) }));
  }
  return out;
}

/** Roll one native chest opening: [{itemIndex, count}] in table order (same item merged). rng() in [0, 1). */
export function rollRenewChest(entry, rng = Math.random) {
  const between = (a, b) => a + Math.floor(rng() * (b - a + 1)), out = new Map();
  const give = (itemIndex, count) => out.set(itemIndex, (out.get(itemIndex) || 0) + count);
  for (const f of entry.fixed) give(f.itemIndex, f.stack * between(f.min, f.max));
  for (const f of entry.fixedSets) {
    if (rng() * RENEW_CHEST.ratioScale >= f.ratio) continue;
    const set = entry.sets[f.set];
    for (let n = between(f.min, f.max); n > 0; n--) {
      let r = rng() * set.total, pick = set.entries[set.entries.length - 1];
      for (const e of set.entries) { r -= e.weight; if (r < 0) { pick = e; break; } }
      give(pick.itemIndex, between(pick.min, pick.max));
    }
  }
  return [...out].map(([itemIndex, count]) => ({ itemIndex, count }));
}

/** Exact native probability of each set roll (for evidence and the client description; no client roll exists). */
export function renewChestOdds(entry) {
  return entry.fixedSets.map(f => ({ set: f.set, chance: f.ratio / RENEW_CHEST.ratioScale, picks: [f.min, f.max],
    items: entry.sets[f.set].entries.map(e => ({ itemIndex: e.itemIndex, chance: e.weight / entry.sets[f.set].total, count: [e.min, e.max] })) }));
}

/** Weekly chest state after a battle ends: regenerated for the owner holding the castle at the end, else none. */
export function renewChestAfterEnd(owner, { startAt, endedAt }) {
  return owner?.guild ? { guild: owner.guild, name: owner.name || null, startAt, regeneratedAt: endedAt, claimed: null } : null;
}
