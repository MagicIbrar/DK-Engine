// Native: item4000862 period3600 (itemetc), item4000861 reward ticket, map653 SOLO 170-250, dungeonlist expiry 30 min,
// WORLDBY exits 651/652 (272,62), script monster 8833.
// Lane 57: Global binds the quest6011 ticket-issuance dialogue (200,000 Dil, three issue menus) to no NPC,
// and no shop, cash shop, box, Dekapass, drop, quest-reward or event row issues 4000862 or 4000861, so the
// guessed Checkpoint 5913 issuer and its cost, period and daily quota were removed.
// Lane 57 follow-up 3: Global has NO way into map 653. No npc.csv job (19/102 dungeon, 2 teleport, 31, 57)
// targets dungeon 653 or quest 6011; no location/warp/siegeteleport/servermove/smartwarp row lands on 653;
// dungeonlist 653 has no entry NPC; Checkpoint 5913's only Global jobs are teleport 133 (Zuto's Battlefield
// 650) and quest 8073. The ENGINE-CHOSEN 5913 entrance (npc, radius) was therefore removed and the host
// refuses phantom-info / phantom-enter.
// Lane 71: Phantom Castle is CLOSED (no Global entrance - nothing to resolve). The 4000861 award is REMOVED: stringtable_exchange
// calls it a reward for Zuto battle participants and the client result board (UrbanNoticeboard item_reward, "%s X %u") shows a
// server-sent reward item and count, but no Global, older-server or online source supplies the count or recipients.
export const PHANTOM_CASTLE = Object.freeze({
 map:653, quest:6011, timedTicket:4000862, rewardTicket:4000861,
 boss:8833, minLevel:170, maxLevel:250, durationSec:1800,
});
