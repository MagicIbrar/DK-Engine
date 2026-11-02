// MONSTER CARNIVAL (the Forgotten Shipwreck team mode): values the shipped Global data does not contain. Data-backed values stay
// in the data: share/forgottenshipwreck/startcondition.csv (DAY / StartPCCount 10 / MaxPCCount 10 / Start_Hour..Finish_Hour, as
// gamedata/dungeons.json forgottenShipwreck.schedule) and rewardslot.csv (win / lose slot tables), dungeonlist 234 (Forgotten
// Shipwreck 234 -> 235, levels 190-250, 30 minutes, KickTo 183 60,102), the Scarlet 5992 "[ Normal Mode ]" entrance text, string
// cate 161 of stringtable_dksquare.txt (lobby, team names, CP, the six team skills 33-38 / 133-138, refusals 200-227, effects
// 103-105 / 225), the game2/forgottenshipwreck windows, statuses 7496 / 7497 and the carnival monsters 9120 / 9139 / 9140.
// Nothing here scales a native value; each line below is one choice.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const CARNIVAL_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // Lane 71: CLOSED. Global has no entrance (no NPC carries job 123 MONSTER_CARNIVA, no lobby button in the data) and no Global,
  // decompile, older-server or online source gives the team rules below (CP costs, skill effects / durations, result seconds), so
  // registration is refused like Phantom Castle 653. The values below stay only as the record of what was chosen; flip this flag
  // only when a source for the entrance and the rules is found.
  closed: true,
  // ENGINE-CHOSEN (not in Global data): no Global NPC carries job 123 MONSTER_CARNIVA (jobtypeconfig.csv) and no lobby button is in the data; the chat command /carnival opens the lobby from any field map.
  opener: '/carnival',
  // ENGINE-CHOSEN (not in Global data): 161:216 "Only one character can apply for admission on one PC" is not enforced beyond the session layer (one live character per account): the host has no trusted machine identity.
  perPc: 'session layer only',
  // ENGINE-CHOSEN (not in Global data): 161:201 (War Excitement buff) is never shown: no Global status is named War Excitement (7284 / 7380 are "Excitement" rows of other modes) and no unrelated status is bound to it.
  warExcitement: 'not bound',
  // ENGINE-CHOSEN (not in Global data): the cost is the native Forgotten Shipwreck Normal Mode entrance of Scarlet 5992 (fee and items of its text, premium discount as at the dungeon entrance), checked at registration and paid on the staged profile at the run's start.
  entryCost: 'Scarlet 5992 Normal Mode entrance, paid at the start',
  // ENGINE-CHOSEN (not in Global data): a registrant needs the dungeonlist 234 level range (190-250); below it the dungeon's own 234:100 refusal is shown.
  levels: 'dungeonlist 234 levels',
  // ENGINE-CHOSEN (not in Global data): the first StartPCCount registrants (registration order) start one run of MaxPCCount; no partial run, no timeout; a registrant who fails the start checks leaves the lobby and the others wait at the front.
  matching: 'StartPCCount in registration order',
  // ENGINE-CHOSEN (not in Global data): teams alternate BLUE (161:101) / RED (161:102) in registration order.
  teams: 'alternate BLUE / RED',
  // ENGINE-CHOSEN (not in Global data): both teams play ONE shared instance of the ordinary Forgotten Shipwreck (dungeon 234, floors 234 -> 235): its Director, native monsters, stats, placement, start point, floor crystal and 30-minute limit run unchanged; only its single roulette drop is replaced by the team roulette.
  run: 'one shared dungeon 234 instance',
  // ENGINE-CHOSEN (not in Global data): a monster of the run killed by a team member gives that team CP (161:3) and score equal to the monster's native rank (at least 1).
  cpPerKill: 'native monster rank, at least 1',
  // ENGINE-CHOSEN (not in Global data): the score (ui_scorewnd) is the CP a team earned; spending CP does not lower it.
  score: 'CP earned',
  // ENGINE-CHOSEN (not in Global data): CP cost (161:4 "CP %d consumed") of the six team skills 33..38: heal 5, attack 8, root 5, seal 5, random 3, combat 8 (one full run yields about 98 CP for both teams together).
  skillCost: Object.freeze([5, 8, 5, 5, 3, 8]),
  // ENGINE-CHOSEN (not in Global data): 161:220 "Exceeded 10 uses." = ten team skill uses per team per run (161:11 shows the uses left).
  skillUses: 10,
  // ENGINE-CHOSEN (not in Global data): any standing member of a team inside the run may cast a team skill; the team's CP pays.
  caster: 'any standing team member',
  // ENGINE-CHOSEN (not in Global data): skill 1 (161:33 / 133) adds 50% of max HP and max MP to every standing member of the own team.
  heal: '50% max HP / MP, own team',
  // ENGINE-CHOSEN (not in Global data): skill 2 (161:34 / 134, no status row in the data) gives every standing own member the native All Attack option 325 COMBINE_OPTION_COMBINE_MUL +30 for 60 s through the host stat pipeline.
  attack: 'option 325 +30 for 60 s, own team',
  // ENGINE-CHOSEN (not in Global data): skill 3 (161:35 / 135) puts status 7496 (Electric Shock, move disabled: the Lightning Carnival 9140 attack status) on every standing opponent for 5000 ms.
  root: '7496 for 5000 ms, opponents',
  // ENGINE-CHOSEN (not in Global data): skill 4 (161:36 / 136) puts status 7497 (Breath of Nepturos, skills disabled) on every standing opponent for 5000 ms.
  seal: '7497 for 5000 ms, opponents',
  // ENGINE-CHOSEN (not in Global data): skill 5 (161:37 / 137) picks Hit, Seal II or Shockwave II with equal chance; Seal II = 7497 and Shockwave II = 7496 on one random standing opponent for 3000 ms (the native 9140 / Nepturos attack rows).
  random: 'Hit / Seal II / Shockwave II, equal chance',
  // ENGINE-CHOSEN (not in Global data): Hit = three hits of the team's own meteor (RED 9120 / BLUE 9139) native melee AttackDamage roll on one random standing opponent and every opponent within 3 cells of it; a hit never takes HP below 1.
  hit: '3 meteor rolls, 3 cells, HP floor 1',
  // ENGINE-CHOSEN (not in Global data): skill 6 (161:38 / 138, ui_target_skill_wnd) lets the chosen opponent and the casting team hit each other for 20 s under the shared PvP rules; no other inter-team PvP exists.
  combat: '20 s mutual PvP with the chosen opponent',
  // ENGINE-CHOSEN (not in Global data): the run ends at the last-floor clear (Nepturos), at the dungeon's time limit, at a missed floor transfer, or when one team has nobody left inside.
  end: 'clear, time limit, missed transfer or empty team',
  // ENGINE-CHOSEN (not in Global data): the higher score wins; equal scores have no winner (both teams use the lose table); a team with nobody inside loses.
  winner: 'higher score; tie = no winner',
  // ENGINE-CHOSEN (not in Global data): each member still inside after the end spins the Shipwreck Roulette (161:2) once over the win / lose rewardslot.csv row (one weighted slot); the host fixes the pick at the first spin, a full bag (161:10) keeps it for a retry, and members who never spin are spun when the run closes.
  roulette: 'one host-fixed spin per member inside',
  // ENGINE-CHOSEN (not in Global data): seconds between the end and returning everyone to the dungeon's native exit (KickTo 183 60,102).
  resultSec: 60,
  // ENGINE-CHOSEN (not in Global data): a member who leaves the run's instance (exit, disconnect) before spinning forfeits the roulette; the roulette window's exit (161:6) spins first.
  leaver: 'forfeits the roulette',
  // ENGINE-CHOSEN (not in Global data): the native effects play as 161:105 + 161:225 at the start and 161:103 (win) / 161:104 (lose) at the end.
  effects: '105 + 225 start, 103 / 104 end',
  // ENGINE-CHOSEN (not in Global data): ui_team_skill_wnd ships one btn_skill (51 x 51 at 15,9) and one pan_skill_icon template for six icons; the client lays the six copies out as 2 columns x 3 rows (x 15 / 83, y 9 / 69 / 129, icon inset 5).
  skillGrid: Object.freeze({ x: 15, y: 9, dx: 68, dy: 60 }),
});
export function carnivalChosenList() { return Object.entries(CARNIVAL_CHOSEN).filter(([k]) => k !== 'tag').map(([k, v]) => `${k}=${JSON.stringify(v)}`); }
