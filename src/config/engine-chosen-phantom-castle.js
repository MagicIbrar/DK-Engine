// Native: quest6011 cost200000, item4000862 period3600, map653 SOLO170–250,
// dungeonlist expiry30min, WORLDBY exits651/652 (272,62), script monster8833.
// ENGINE-CHOSEN missing-server-script reconstruction: lobby checkpoint5913 is
// both ticket issuer and entrance (its unlabeled 2000/2100/2101 prompt mirrors
// battlefield admission). Three daily issues follow the three named issue
// strings + daily periodquest row; higher unlabeled issuance tiers stay absent.
// One native Fanatic is placed in a reachable room by the existing dungeon
// anchor selector. It is not weakened, duplicated or given invented loot.
export const PHANTOM_CASTLE = Object.freeze({
 map:653, npc:5913, quest:6011, timedTicket:4000862, rewardTicket:4000861,
 cost:200000, periodSec:3600, issuesPerDay:3, radius:10,
 boss:8833, minLevel:170, maxLevel:250, durationSec:1800,
});
