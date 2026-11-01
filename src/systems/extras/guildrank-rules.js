// GUILD-DUNGEON-RANK: rules of the Guild Frontier Ranking window + the guild window's Dungeon Lv, shared by the host
// (server/world/guild-frontier.mjs guildFrontierRanking) and the client (src/systems/extras/guildrank.js).
// Original sources (read-only, data/unpacked/data):
//   window   script/ui/game2/guilddungeon/ui_guilddungeonrankingwnd.txt (guilddungeonrankingwnd, 320x492): tab btn_tab_guildranking
//            132:2 "Frontier Ranking", title 132:1 "Ranking", column heads 132:3 Ranking / 132:4 Guild Name / 132:5 FR Point,
//            pan_rankinglist (6 86 308 326) with the pan_element row template (308x30: lbl_rank, guild mark pan_markback/front 23x23,
//            lbl_guildname, lbl_drpoint), btn_prev/btn_next/btn_page scripted enable false + visible false (one page), own guild row
//            pan_myguild (lbl_myrank, pan_mymarkback/front, lbl_myguildname, lbl_mydrpoint), btn_confirm 132:6, btn_help.
//   help     ui_deliveryrankinfownd.txt (deliveryrankinginfownd): 132:100 title, 132:101 explanation, 132:102 Rank Awards,
//            132:110..113 rank ranges, 132:120..123 awards. Imagetable guild_ranking 1..17.
//   guild    game2/guild/ui_guildwnd.txt: lbl_tagdungeonclass 132:1200 "Dungeon Lv" -> lbl_dungeonclass, btn_ranking 132:1204
//            "Ranking Status" (opens the window), lbl_tagmycontribute 132:1203 -> lbl_mycontribute.
//   award    share/guild/guild_dungeongrade.csv Rank 1..10 -> Dungeon_Grade 1..10 (BaseCreatCount 3, MaxCreatCount 6).
//   points   share/guild/guild_deliver.csv Give_DRpoint (already server-side: guilds.mjs donateItems).
// Rows: 10 = the 10 ranks of guild_dungeongrade.csv = the 30 px pan_element rows that fit above the (hidden) page line at y 305 of
// pan_rankinglist (10 x 30 = 300). NOT IN THE DATA (documented, not invented): the weekly Thursday maintenance time and time zone
// (132:101/500 say "every Thursday during maintenance"; production uses the disclosed ENGINE-CHOSEN Thursday 03:00 fixed
// server UTC+1 week, engine-chosen-guild.js FRONTIER_CHOSEN, settled by guild-frontier.mjs tickGuildFrontier), the tie
// rule (competition ranking: tied guilds share the first rank of their range and its Dungeon Lv), the text of an empty
// Dungeon Lv (the engine keeps the existing '-').
export const RANK_SCRIPT = 'game2/guilddungeon/ui_guilddungeonrankingwnd.txt';
export const HELP_SCRIPT = 'game2/guilddungeon/ui_deliveryrankinfownd.txt';
export const RANK_ROWS = 10;
export const ROW_HEIGHT = 30;
export const STR = { title: [132, 1], tab: [132, 2], colRank: [132, 3], colName: [132, 4], colPoint: [132, 5], confirm: [132, 6], dungeonLv: [132, 1200], status: [132, 1204] };
export const NO_DUNGEON = '-';
/** ENGINE-CHOSEN (not in Global data) tie rule and maintenance time: src/config/engine-chosen-guild.js FRONTIER_CHOSEN. */
export { FRONTIER_CHOSEN } from '../../config/engine-chosen-guild.js';
export const TIE_RULE = 'competition-shared-rank';   // = FRONTIER_CHOSEN.TIE_RULE (checked by tools/test-alliance.mjs)
/** Score position [first, last] (tie range) -> rank text. */
export function positionText(pos) { if (!Array.isArray(pos) || !Number.isInteger(pos[0])) return ''; return String(pos[0]); }
/** guild_dungeongrade.csv row of a score position; a tie range is awarded its first (shared) rank. */
export function dungeonGradeOf(pos, grades) {
  if (!Array.isArray(pos) || !Number.isInteger(pos[0]) || pos[0]<1 || !Array.isArray(grades)) return null;
  const row = grades.find(r => Number(r.Rank) === pos[0]);
  return row && Number.isInteger(Number(row.Dungeon_Grade)) ? { rank: pos[0], dungeonGrade: Number(row.Dungeon_Grade) } : null;
}
export const pointText = n => Number(n || 0).toLocaleString('en-US');

/** "[Frontier Dungeon] Move" (quest dialog share/quest/quest_01641_enter_guildport.csv, 1641:10000 "Let me know if you want to enter
 * Guild Frontier Dungeon. I can take you to the harbour.", option 10001 "Move.", refusal 1641:100 "Frontier Dungeon can only be
 * entered by Guild Members who own it."). AUTHENTICATED NATIVE ROUTE: npc.csv lists 1641 on exactly two NPCs, Vascuda 5532 (Ardeca 150)
 * and Vascuda 5668 (Harbor Town 550, beside the 550 arrival point), and warp.csv has exactly one scripted pair between those maps:
 * 11759 (150 -> location 11760 "Village near port", the only way into 550) and 11760 (550 -> location 11759 "In front of Bascuda in
 * Ardeca"). Who may go: members of a guild that OWNS the Frontier Dungeon = holds a guild_dungeongrade.csv award in force
 * (132:101/500/501: the top-ranking guilds, for the following week; server/world/guild-frontier.mjs frontierDungeonAward). Leaving
 * Harbor Town is never gated (no portal / return scroll there: maplist IsPortal 0, IsReturnScroll 0). Dead Island 551 (Keeper GUILD,
 * Ticket 1, guild-master creation, BaseCreatCount 3 / MaxCreatCount 6) stays closed: its ticket item binding, creation/entry
 * counters and grade use are not defined by the client data. */
export const FRONTIER_MOVE = Object.freeze({
  quest: 1641, option: 10001, refusal: 100,
  routes: Object.freeze([
    Object.freeze({ npc: 5532, map: 150, warp: 11759, toMap: 550, needsAward: true }),
    Object.freeze({ npc: 5668, map: 550, warp: 11760, toMap: 150, needsAward: false }),
  ]),
});
/** The native move route offered by this NPC on this map, or null. */
export function frontierMoveRoute(npcIndex, map) { return FRONTIER_MOVE.routes.find(r => r.npc === Number(npcIndex) && r.map === Number(map)) || null; }

/** Native warp/location pairs; grade order is ENGINE-CHOSEN from parallel maps552..561. */
export const HIDEOUT_MOVE=Object.freeze({enterQuest:23,exitQuest:24,option:10001,enterNpc:135,exitNpc:5669});
export function hideoutMoveRoute(npcIndex,map,grade){
 const npc=Number(npcIndex),m=Number(map),g=Number(grade);
 if(npc===135&&m===150&&Number.isInteger(g)&&g>=1&&g<=10)return {npc,map:m,quest:23,warp:11739+2*(g-1),location:11740+2*(g-1),toMap:551+g,needsAward:true};
 if(npc===5669&&m>=552&&m<=561)return {npc,map:m,quest:24,warp:11740+2*(m-552),location:11739+2*(m-552),toMap:150,needsAward:false};
 return null;
}
