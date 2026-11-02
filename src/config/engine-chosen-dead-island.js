// Dead Island (map551) in-run rules. NATIVE rows are read from the prepared
// client tables; older-server-reference rows come from server-ref
// map551 share (Arena==Normal). ENGINE-CHOSEN / UNRESOLVED values stay
// only where no Global client, decompile pseudocode, or server-ref source gives
// a duration/rule. The Global server director for this map is not in any
// supplied source.
// Admission (server/world/dead-island.mjs): runs 1-3 per server day take a Frontier ticket; runs 4-6 need one
// Camouflage [Frontier] (NATIVE system_variable 51 = 1755139, desc 918 "3 additional entries"; itemcash Trade 0,
// not for sale). It is a GM-event prize, awarded with the GM grant command /gm giveitem
// (src/config/engine-chosen-gm-prize.js); without it the native refusal 551:110 applies.

// NATIVE: dungeon_551 menu 13100/13200/13300 -> 14001..14010; item 7499..7508
// (itemetc code71, Value1 1231..1240) -> itemstatus 1231..1240 -> trigger
// statuses 7304..7313. Each trigger names the effect row 7226..7235 of the
// same ability ("Slaughter" -> "Ancient Str [Slaughter]"), so the binding is
// by native name identity, never by an equal number.
export const DEAD_ISLAND_ABILITIES=Object.freeze([
 Object.freeze({menu:14001,item:7499,itemStatus:1231,trigger:7304,status:7226,kind:'self',type:13100}),   // Genocide / Slaughter
 Object.freeze({menu:14002,item:7500,itemStatus:1232,trigger:7305,status:7227,kind:'self',type:13100}),   // Berserker / Zealot
 Object.freeze({menu:14009,item:7507,itemStatus:1239,trigger:7312,status:7234,kind:'self',type:13100}),   // Bravery / Valor
 Object.freeze({menu:14003,item:7501,itemStatus:1233,trigger:7306,status:7228,kind:'self',type:13200}),   // Iron Will / Strong Will
 Object.freeze({menu:14008,item:7506,itemStatus:1238,trigger:7311,status:7233,kind:'self',type:13200}),   // Resistance / Immune
 Object.freeze({menu:14010,item:7508,itemStatus:1240,trigger:7313,status:7235,kind:'self',type:13200}),   // Mana Barrier
 Object.freeze({menu:14004,item:7502,itemStatus:1234,trigger:7307,status:7229,kind:'guild',type:13300}),  // Area Heal / All recovery
 Object.freeze({menu:14005,item:7503,itemStatus:1235,trigger:7308,status:7230,kind:'midas',type:13300}),  // Midas
 Object.freeze({menu:14006,item:7504,itemStatus:1236,trigger:7309,status:7231,kind:'monsters',type:13300}),// Shackle / Restrain
 Object.freeze({menu:14007,item:7505,itemStatus:1237,trigger:7310,status:7232,kind:'self',type:13300}),   // Hermes
]);

// NATIVE itemetc Appraisal cooldowns (ms): 7499-7502/7505-7508 = 2000; 7503/7504 = 15000; 7490 Igniter = 0.
// status.csv for 7226..7235 / 7281..7296 / 7324 has no Time/Duration column — effect lengths are not in client tables.
//
// UNRESOLVED effect lengths (kept as ENGINE-CHOSEN working values; searched with zero hits):
//   abilityMs, areaHealMs, midasCrystalMs, stonesPerStage,
//   totem releaseMs/rechargeMs/comboMs/invincibleMs (except gaugeMs),
//   Recollapse everyMs, boss radius, paid-run custody, igniter set drop policy.
// Search paths (2026-10-29 America/Los_Angeles):
//   server-ref — ini/txt/csv/scripts,
//     map551 callmon/brick/npc/mon (no timer fields; RegenCycle=0), maplist (no 7200 field),
//     DekaronServer.exe/ScriptProcess.dll string tables (Totem/AbilityCap only; no Dead Island director),
//     DB .bak/.sql/.mdf as text (runtime DBs; no DI design timers);
//   decompile Ghidra decompiled.c / README (no guide/stringtable assets; no DI timer/packet constants;
//     numeric 1380/551/7200 hits are address noise);
//   Scrubbed Global 0.0.1 + prepared prepared-client stringtables/status/itemetc
//     (totem gauge 5000 NATIVE; reset prices NATIVE; Appraisal cooldowns NATIVE; no ability duration).
export const DEAD_ISLAND_TIMING=Object.freeze({
 // UNRESOLVED / ENGINE-CHOSEN: no Global/server-ref duration for ability buff length.
 abilityMs:60000,
 // UNRESOLVED / ENGINE-CHOSEN duration; NATIVE Appraisal cooldown for 7504 is 15000 (itemetc).
 shackleMs:15000,
 // UNRESOLVED / ENGINE-CHOSEN: Area Heal string says "Heals Guild member's HP" with no length.
 areaHealMs:5000,
 // UNRESOLVED / ENGINE-CHOSEN: Midas "disappear in time"; Appraisal cooldown 15000 NATIVE on 7503.
 midasCrystalMs:30000,
 // UNRESOLVED / ENGINE-CHOSEN: one stone per stage (desc 898..907 call them consumable; no count in tables).
 stonesPerStage:1,
});

// NATIVE totems: npc 5537 Earth, 5538 Forest, 5539 Fire, 5540 Wind,
// 5541 Heaven (Sky), 5545 Water; job31:5003; dialog 30000/30001 with the
// native 5000ms gauge and sound 22/1028/25/29; Igniter 7490 (code72, desc892).
// older-server-reference: server-ref Normal/Arena npc_551_deadman_island.csv lists the same 18 indices.
export const DEAD_ISLAND_TOTEMS=Object.freeze([
 Object.freeze({npc:5537,key:'earth',released:227}),Object.freeze({npc:5538,key:'woods',released:228}),
 Object.freeze({npc:5539,key:'fire',released:229}),Object.freeze({npc:5540,key:'wind',released:230}),
 Object.freeze({npc:5541,key:'sky',released:231}),Object.freeze({npc:5545,key:'water',released:240}),
]);
// NATIVE combinations (item desc 892): five released totems; the one that is
// missing names the effect. Effect statuses are the native group130 rows.
export const DEAD_ISLAND_COMBOS=Object.freeze([
 // ENGINE-CHOSEN status for "Sand Fairy's Power": 7296 Ancient Totem [weaken]
 // is the only group130 totem row not otherwise named by another effect.
 Object.freeze({missing:'water',message:233,effect:'weaken',status:7296}),
 Object.freeze({missing:'sky',message:234,effect:'liftCurse',status:7290}),
 Object.freeze({missing:'wind',message:235,effect:'overclock',status:7291}),
 Object.freeze({missing:'fire',message:236,effect:'invincible',status:7292}),
 Object.freeze({missing:'woods',message:237,effect:'neutralize'}),
 Object.freeze({missing:'earth',message:241,effect:'triforce'}),
]);
// Totem timings: gaugeMs is NATIVE (stringtable_dungeon_06 code 30001
// "<guage,sec 5000,text Resonating with the Ancient Totem,snd 22 1028 25 29>").
// releaseMs/rechargeMs/comboMs/invincibleMs remain UNRESOLVED / ENGINE-CHOSEN
// (no duration in status.csv or server-ref; see search paths on DEAD_ISLAND_TIMING).
export const DEAD_ISLAND_TOTEM_TIMING=Object.freeze({
 gaugeMs:5000, // NATIVE
 releaseMs:30000, // UNRESOLVED / ENGINE-CHOSEN
 rechargeMs:120000, // UNRESOLVED / ENGINE-CHOSEN
 comboMs:30000, // UNRESOLVED / ENGINE-CHOSEN
 invincibleMs:10000, // UNRESOLVED / ENGINE-CHOSEN
});
export const DEAD_ISLAND_IGNITER=7490;
// UNRESOLVED / ENGINE-CHOSEN Igniter supply: native itemset 4852 "guild dungeon lever item"
// (100% Igniter) is referenced by no Global monster. Every authored wave
// monster (7982 Teracota, 7983 Dryad, 7984 Diver) killed in a running battle
// drops that set once, so Igniters are earned by fighting, never bought.
export const DEAD_ISLAND_IGNITER_SET=4852;
// older-server-reference: server-ref map551 callmon_551_deadman_island.csv
// CallIndex 1/2/3 -> MonsterIndex 7982/7983/7984 (Arena==Normal; mon file empty).
export const DEAD_ISLAND_WAVE_MONSTERS=Object.freeze([7982,7983,7984]);

// NATIVE bosses and their group130 rows.
export const DEAD_ISLAND_BOSSES=Object.freeze([
 Object.freeze({monster:7979,vitality:7286,neutralize:7293,curse:7281,attUp:251,defDown:254}),   // Quetzalcoatl
 Object.freeze({monster:7980,vitality:7287,neutralize:7294,curse:7282,attUp:252,defDown:255}),   // Hatun Kucha
 Object.freeze({monster:7981,vitality:7288,neutralize:7295,curse:7283,attUp:253,defDown:256}),   // Mapinguari
]);
export const DEAD_ISLAND_TRIFORCE=7324;          // NATIVE "Triforce\Creates a strong barrier." (group104)
export const DEAD_ISLAND_ABSORB_UPGRADE=7246;   // NATIVE Ancient Curse Absorb [Upgrade Lv1..15] 7246..7260
export const DEAD_ISLAND_ABSORB_WEAKEN=7261;    // NATIVE Ancient Curse Absorb [Weaken Lv1..15] 7261..7275
// NATIVE curses: each boss's specialMelee row (1000202, 15m area) applies its
// curse 7281/7282/7283 at 100% for 120000ms; wave rows apply 7301/7302/7303 at
// 5% (Teracota/Dryad/Diver). The host applies these result statuses for run
// monsters only. ENGINE-CHOSEN: lifting the curse with the totem combination
// makes each living boss absorb it (native 262 + 251..253, Upgrade level +1);
// a boss whose vitality is neutralized at that moment takes the native Weaken
// level instead (254..256). Triforce and vitality are applied when the boss
// appears and last the whole run; Triforce makes the boss immune to damage
// (its native "strong barrier" option) until the totem combination removes it.
// UNRESOLVED / ENGINE-CHOSEN self-destruct pressure: native 225/226 Recollapse 7986. From
// stage2 a Recollapse appears every 90s at a random living run member's
// position (one at first, +1 each later stage; native 225 "summon stage
// increased" at each step), keeping its native stats and result row.
// everyMs 90000: zero evidence in server-ref / Global / decompile.
export const DEAD_ISLAND_RECOLLAPSE=Object.freeze({monster:7986,everyMs:90000,firstStage:2});
export const DEAD_ISLAND_RECOVERY_GEM=7985;

// Interior gates 5660/5661/5662 (NATIVE job31:5005, dialog40000/40001/40002,
// text "Go inside."). The landing zone and the arena are separate collision
// regions; no location/warp row exists for map551. ENGINE-CHOSEN landing:
// the first arena-region cell two cells past the wall on the straight line
// from the gate NPC to the arena centre (250,272), searched in the prepared
// collision at run time.
// older-server-reference bricks: BrickIndex 36922 x3, RegenCycle 0 (server-ref brick_551).
export const DEAD_ISLAND_GATES=Object.freeze([5660,5661,5662]);
export const DEAD_ISLAND_ARENA_CENTRE=Object.freeze({x:250,z:272});
// UNRESOLVED / ENGINE-CHOSEN boss anchors: the three Helion NPCs stand in the landing ring,
// which the arena wall separates from the fight, so bosses cannot use them.
// Each boss stands 25 cells from the arena centre toward its own gate
// (7979 west 5660, 7980 south 5661, 7981 east 5662: the same order as the
// Helions 5533/5534/5535), keeping the native three-sided layout inside the arena.
export const DEAD_ISLAND_BOSS_GATES=Object.freeze([[7979,5660],[7980,5661],[7981,5662]]);
export const DEAD_ISLAND_BOSS_RADIUS=25;
export const DEAD_ISLAND_TITLE=14;   // NATIVE title "Frontier Pioneer" (Type 9; earned by using the interior gate after entry)

// NATIVE reset prices from stringtable_dungeon_06 codes 21000..21400
// ("Reset payment 10,000,000 DIL" … "160,000,000 DIL"). Used by dead-island-plan / host reset.
export const DEAD_ISLAND_RESET_PRICES=Object.freeze([10000000,20000000,40000000,80000000,160000000]);

// Paid-run custody (UNRESOLVED / ENGINE-CHOSEN): the guild's paid run is recorded in the
// durable social document. After a host restart or after every member left,
// a returning admitted member reattaches to the same run id until its native
// 120-minute deadline. The battle restarts from preparation (no charge);
// cleared runs are not recreated.
export const DEAD_ISLAND_RUN_LABEL='UNRESOLVED/ENGINE-CHOSEN paid-run reattachment; NATIVE deadline 7200s and NATIVE reset prices retained';

// Explicit UNRESOLVED inventory for coordinator (zero evidence after full search).
export const DEAD_ISLAND_UNRESOLVED=Object.freeze({
 abilityMs:60000,
 areaHealMs:5000,
 midasCrystalMs:30000,
 stonesPerStage:1,
 totemReleaseMs:30000,
 totemRechargeMs:120000,
 totemComboMs:30000,
 totemInvincibleMs:10000,
 recollapseEveryMs:90000,
 bossRadius:25,
 igniterSetDropPolicy:'itemset 4852 on every authored wave kill',
 paidRunCustody:true,
 guideCate1380Body:true,
 searchPaths:Object.freeze([
  String.raw`audit\server-ref\Server 2014`,
  String.raw`audit\server-ref`,
  String.raw`audit\server-ref\DB Cleaned`,
  String.raw`audit\server-ref\legacy`,
  String.raw`audit\server-ref\SQL Server 2014`,
  String.raw`audit\decompile`,
  String.raw`audit\Scrubbed Global 0.0.1`,
  String.raw`audit\4.2.0\global-prepared\engine\.client-cache\generations\prepared-client\data\script\string`,
  String.raw`audit\4.2.0\global-prepared\engine\.client-cache\generations\prepared-client\data\share\skill\status.csv`,
  String.raw`audit\4.2.0\global-prepared\engine\.client-cache\generations\prepared-client\data\share\item\itemetc.csv`,
 ]),
});
