// Dead Island (map551) in-run rules. NATIVE rows are read from the prepared
// client tables; every ENGINE-CHOSEN value below says what it was derived from.
// The Global server director for this map is not in any supplied source.
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

// ENGINE-CHOSEN timings. The native rows give magnitudes and the item cooldown
// (itemetc Appraisal 2000ms, 15000ms for Midas/Shackle) but no effect length.
// Self and guild buffs last 60s: four native 15s cooldown windows, so a stone
// used once per stage covers a stage fight without permanent uptime.
// Shackle lasts its own native 15s cooldown. Midas crystals keep the native
// "disappear in time" rule with a 30s life (two Shackle windows).
export const DEAD_ISLAND_TIMING=Object.freeze({
 abilityMs:60000,shackleMs:15000,areaHealMs:5000,midasCrystalMs:30000,
 // One stone per chosen ability at each battle-stage start (stages 1-4): a
 // "consumable item" (native desc 898..907) that the run re-issues per stage.
 stonesPerStage:1,
});

// NATIVE totems: npc 5537 Earth, 5538 Forest, 5539 Fire, 5540 Wind,
// 5541 Heaven (Sky), 5545 Water; job31:5003; dialog 30000/30001 with the
// native 5000ms gauge and sound 22/1028/25/29; Igniter 7490 (code72, desc892).
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
// ENGINE-CHOSEN totem timings: released power lasts 30s (six native 5s
// resonance gauges, enough for one member to walk between totems); a used
// totem recharges in 120s (four combination windows); combination statuses
// last 30s, invincibility 10s (the native Qune/Dekaron invincible rows are
// short buffs). Failure 238 is shown when a release expires unused.
export const DEAD_ISLAND_TOTEM_TIMING=Object.freeze({gaugeMs:5000,releaseMs:30000,rechargeMs:120000,comboMs:30000,invincibleMs:10000});
export const DEAD_ISLAND_IGNITER=7490;
// ENGINE-CHOSEN Igniter supply: native itemset 4852 "guild dungeon lever item"
// (100% Igniter) is referenced by no Global monster. Every authored wave
// monster (7982 Teracota, 7983 Dryad, 7984 Diver) killed in a running battle
// drops that set once, so Igniters are earned by fighting, never bought.
export const DEAD_ISLAND_IGNITER_SET=4852;
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
// ENGINE-CHOSEN self-destruct pressure: native 225/226 Recollapse 7986. From
// stage2 a Recollapse appears every 90s at a random living run member's
// position (one at first, +1 each later stage; native 225 "summon stage
// increased" at each step), keeping its native stats and result row.
export const DEAD_ISLAND_RECOLLAPSE=Object.freeze({monster:7986,everyMs:90000,firstStage:2});
export const DEAD_ISLAND_RECOVERY_GEM=7985;

// Interior gates 5660/5661/5662 (NATIVE job31:5005, dialog40000/40001/40002,
// text "Go inside."). The landing zone and the arena are separate collision
// regions; no location/warp row exists for map551. ENGINE-CHOSEN landing:
// the first arena-region cell two cells past the wall on the straight line
// from the gate NPC to the arena centre (250,272), searched in the prepared
// collision at run time.
export const DEAD_ISLAND_GATES=Object.freeze([5660,5661,5662]);
export const DEAD_ISLAND_ARENA_CENTRE=Object.freeze({x:250,z:272});
// ENGINE-CHOSEN boss anchors: the three Helion NPCs stand in the landing ring,
// which the arena wall separates from the fight, so bosses cannot use them.
// Each boss stands 25 cells from the arena centre toward its own gate
// (7979 west 5660, 7980 south 5661, 7981 east 5662: the same order as the
// Helions 5533/5534/5535), keeping the native three-sided layout inside the arena.
export const DEAD_ISLAND_BOSS_GATES=Object.freeze([[7979,5660],[7980,5661],[7981,5662]]);
export const DEAD_ISLAND_BOSS_RADIUS=25;
export const DEAD_ISLAND_TITLE=14;   // NATIVE title "Frontier Pioneer" (Type 9; earned by using the interior gate after entry)

// Paid-run custody (ENGINE-CHOSEN): the guild's paid run is recorded in the
// durable social document. After a host restart or after every member left,
// a returning admitted member reattaches to the same run id until its native
// 120-minute deadline. The battle restarts from preparation (no charge);
// cleared runs are not recreated.
export const DEAD_ISLAND_RUN_LABEL='ENGINE-CHOSEN paid-run reattachment; native deadline and reset prices retained';
