# Dekaron 4.2.0 Update

## How to update

- **Existing 4.1.x users:** open Client.exe. The launcher finds the 4.2.0 update and installs it for you; close the game, world and launcher when asked, then reopen Client.exe. Or install this folder over the top of your old one. Accounts, characters, settings, SQL progress, SQL-setup backups, the launcher choice and the hosting kit are kept. Back up your own saves first.
- **Hosts:** the server-list ping now answers on your public port + 1 (see HOSTING.md). Open or forward both ports.
- **New players:** see START-HERE.txt.

*All changes since 4.1.3. Open each section to see the details.*

<details>
<summary>01 | Launcher, Loading & Game Window (10)</summary>

- The game window now opens first. Account preparation runs alongside the file check instead of before it.
- Later launches check files faster: the quick check no longer opens and reads every file (about 22 s down to 13 s in testing).
- The window opens centred on your main screen with no white flash.
- Gray start screen, GameGuard splash and update box appear in the official order and timing.
- Loading art fades in from black. The loading bar runs from 0 to 99.9 on the official loading curve and never runs ahead of real loading.
- A short black frame shows before the login screen, as in the official client.
- Window: native title bar, the Dekaron icon and the title "Dekaron". Minimize and close only.
- Default window size is now 1024x768. The resolution chosen in Options is remembered, and F11 fullscreen still works.
- Item icons draw much faster (about 2-124 ms down to 0.1-3 ms per icon in testing).
- The game window reports version 4.2.0.

</details>

<details>
<summary>02 | Server Stability & Network (8)</summary>

- Ping is answered on its own thread, so a busy server can't delay it. If that port can't be reached, the game falls back to the normal ping automatically.
- The HUD ping now shows the network round trip only, not server processing time.
- Crash guard: one unexpected server error is logged and the server keeps running. A burst of errors saves everything and shuts down cleanly.
- Lighter server load with many players: status requests arriving together share one update, outdated moves get a short reply, and stream updates reuse shared data. Players receive the same data as before.
- The consignment market list and guild name tables are built once per update for everyone, instead of once per viewer.
- The monster and NPC spawn data sent to the game now matches the server's own corrected map data.
- Temporary load failures now retry instead of leaving models, textures, water, the minimap, quest marks or data missing.
- Large monster spawns are spread over several frames, and monster bone data is prepared before the monster appears, reducing stutter.

</details>

<details>
<summary>03 | Graphics & Lighting (15)</summary>

- Bloom uses the official shader settings. The default bloom level is the middle setting.
- The camera can tilt up to 70 degrees, so you can see the sky.
- Sun and lens flare now draw. Sun beams only show on maps whose sky has them, and no longer appear in dungeons, caves, prisons or arenas.
- Placed sun-ray objects now draw as soft rays. They were invisible before.
- Animated map objects keep their scrolling textures. Reverse-scrolling textures are fixed and looping effects loop seamlessly.
- Ground textures use each map's own texture filtering settings.
- Lamps, candles, torches and pumpkins no longer flash or disappear as the camera turns. Glowing parts use additive glow while the base stays solid.
- Water: type 1 water has reflection and refraction, type 3 has reflection only. Texture density, flow speed and colour fade follow the official data. A blue underwater fog shows when the camera is under water.
- Fog is centred on the camera's focus point. Reversed fog and "fog walls" on some maps are fixed.
- Sky switches instantly, indoor areas show no sky, and cloud speed follows the official data.
- Shadow levels 0/1/2/3 are off/256/512/1024, with the official shadow range. The High Shadow and Trilinear Filter options now work.
- Coloured map lights tint ambient light, sunlight, fog and bloom as you get close, and fade back when you leave.
- Weather (snow, rain, petals, fireflies, sand) particle density and movement follow the official rules. Only petals and pollen spin.
- Terrain tile type and rotation are chosen the official way.
- Lake and fountain water use the official reflection strength, edge shine and colour fade.

</details>

<details>
<summary>04 | Effects, Wings & Weapons (15)</summary>

- Weapon and armor enhancement glow +1 to +15 uses the matching official effect for each tier, including the dedicated +10 effect.
- +15 weapons show their natural glow again (for example Rondo's Spear +15).
- Enhancement glow brightness is calculated the official way, on the character and in the inventory preview. Enhancement and socket shine use a 1-second loop.
- Socket gems glow mid-blade with one effect per gem, coloured by element, on offhand weapons and shields too. Socketed weapons no longer get a gem-coloured tint.
- Vital Attack Diamonds show as an ice effect.
- Aura glow uses the official blur, and auras no longer cut off at a distance.
- Particle sizes fixed on about 1,401 effects that were nearly invisible (for example Ardeca's falling leaves, which are back).
- Particles emit on the official millisecond interval with no first-frame burst, only spin when set to, and spawn, aim and fall with gravity by the official rules.
- Added missing attribute tooltip text to 1,848 wings and 3,119 weapons.
- Cash wings and weapons that have no model in the official data show no model when equipped, without errors.
- Weapon swing trails come from each weapon model's own data (including second trails). Bows, crossbows, staves and shields have none, as in the official game.
- Skill effect models now take map lighting and are hidden correctly behind objects.
- Santa dual-wield weapons show their left-hand model. Cash potion bottles draw solid. Inventory icons no longer get extra halos.
- Changing wings while the previous wings are still loading no longer loses your choice.
- The official wing effect table is now read: the 2,620 wings it lists are flagged for their own wing effect.

</details>

<details>
<summary>05 | Interface & HUD (15)</summary>

- HUD text uses the official formats: "Lv.N", "EXP 0.00%", minimap "X : Z" and ping "N ms". HP, MP and EXP numbers use regular weight.
- Chat: party chat is blue, "The Party has been formed." uses the party colour, and item requirement lines are green. The chat window uses the official default layout and the super-chat box is always shown.
- The HP window and skill quickslot open at their official default positions. New characters start with 1 quickslot row.
- Top-left alarm icons, signal bars and ping use the official layout. The Game Guide alarm is hidden and the Orbis alarm shows at every level.
- The big map NPC list shows 32 rows with no dark backdrop.
- Event notices stack up to 5 lines, and the oldest line drops every 15 seconds. System pop-ups show for 7 seconds without fading.
- The death window reads "You will resurrect in (NN) seconds." and counts down in whole seconds.
- Inventory, storage, shop, pick-up and drop messages use the official text.
- The right-click player menu matches the official entries. Trade and duel are blocked on the OX map, trade is hidden on Dead Front / Ice Castle maps, and reporting asks for confirmation.
- Character info (C) shows real critical damage and shield recovery values. Stats a class doesn't have show blank instead of 0.
- Guild marks are sharp: 24 px beside names and 40 px in the siege status window.
- Click-to-move circle stays still while you hold the mouse, then spins, grows and fades after release until you arrive.
- Closed supply machines say "It isn't a selling machine."
- Fixed garbled characters in some host-panel and guild texts.
- 35 more official windows (for example the repair window) are now available to the game, with their official window and button names.

</details>

<details>
<summary>06 | Login & Character Select (5)</summary>

- The login OK button dismisses the message, and pop-up toasts last 2 seconds.
- Character delete shows a countdown with cancel and confirm when the server uses delayed deletion.
- Up to 18 characters per account (2 pages of 9).
- Fonts, Tab between fields, Enter / Escape and the on-screen keyboard work as in the official login screen.
- The character select and create camera (height, distance, facing) matches the official client for all 15 classes, male and female.

</details>

<details>
<summary>07 | Characters, Skills & Status Effects (17)</summary>

- Running stops the moment a skill is cast, for you and for other players. Stale delayed skill animations no longer override the current one.
- Fixed short skills sometimes playing their cast animation twice, and the position snap-back after skills that move your character.
- Skill animations that fail to load retry instead of staying missing.
- Each level gives 5 stat points and 1 skill point (all 15 classes). The EXP table uses the official data with a max level of 250.
- EXP bonuses work: cash EXP items, buffs and the Premium +10% apply to hunting and party EXP.
- Trans-Up at level 131 and 165, and Meister at 170. Skills now unlock at the correct awakening grade.
- Normal resurrection restores HP/MP by the official ratio after a 10-second wait.
- Death costs 3% of the EXP needed for the current level, without level loss. Field PK victims lose it only once.
- Using a skill on cooldown shows the official message "You cannot use the skill at the moment."
- Half Bagi Fury gains 0.2 per second and holds for 10 seconds. Combo timings and the shared cooldown of the Crash group skills follow the official data.
- Pets and mounts are dismissed when their owner dies. Pets load with their latest position and name, and the pet combination timer no longer gets overwritten. A servant ownership delay is fixed.
- The Life Bead resurrection item is connected.
- Status effect animations loop the official way (play once or last until the status ends). Spell auras play at their real length and loop for the spell's duration.
- Statuses with no official icon show an empty slot. 23 status descriptions were corrected.
- Status stacking, same-family replacement, clearing on death, and stun/sleep blocking movement and attacks follow the official rules.
- Holy Water of Almighty / Premiere services are connected (auto-hunt potion group, minimap Premium service, enhancement bonus, party and NPC teleport, and more).
- Running speed follows each class’s official run animation.

</details>

<details>
<summary>08 | Combat & PvP (12)</summary>

- PvP damage uses each skill's PvP damage rate. The forced minimum of 1 damage is gone, and attack range uses the character's real range.
- Hit chance is limited to 30%-95%. Normal respawns use the official respawn ratios.
- Damage numbers: Block shows the Block word, Guard shows the number with the Guard icon, Immune shows for full resistance, and Blow works. Damage number colours and rows follow the official damage table.
- Critical numbers use the official row, font and display time. Heals and MP recovery no longer show numbers, and damage over time shows as normal damage.
- Duels: invite within 32 cells, leaving the 32-cell area for 10 seconds loses, 10-second accept wait, 5-second start countdown and 5-second result. Duel points use the official formula.
- Forced PK (Ctrl) lasts while Ctrl is held, with no 4-second limit.
- PK name colours: combat is violet and wanted is red. Pink is no longer used.
- Safe time after a PK death: field 30 s, Siege 20 s, Arena 10 s, Urban Warfare 20 s. Duels are exempt. Town safe zones block PK.
- The field PK notice shows once when it starts and again only after the 60-second combat state ends. Infamy only decays as the map allows.
- Guild war: enemy guild names are red, war can't be fought in Braiken, Loa, Mors, Quarin Islands and Ardeca, and allied guild members count as enemies of your enemy.
- Party PvP requests are refused on Siege and Party War maps.
- Melee and ranged damage resistance is capped at 75%. Damage reduction is capped at 75% from gear and 90% from skills. Element resistance is capped at 85%.

</details>

<details>
<summary>09 | Monsters & NPCs (10)</summary>

- Monsters walk while roaming and run while chasing. They turn straight toward their target point, move at the server's speed and stop exactly on the spot.
- Small position gaps are left alone, medium gaps are walked and large gaps snap into place. No more sliding monsters.
- A monster that gives up a chase goes back to roaming. It doesn't walk home or heal. Monsters stand still while swinging an attack.
- Fixed spawns on Conscript A and M (maps 27 and 28), which had Aquarius monsters and NPCs.
- Missing monster spawn sets added (including East Ares 4, West Morte 9 and Forgotten Island) and missing NPC sets added.
- NPCs on maps 176, 614 and 615 now load. All shop NPCs work, including Deacon's multi-shop.
- The Egutt map (715) keeps its NPCs. Nothing was removed.
- Quest marks use the official "!" and "?" effects in yellow, grey, blue, red and violet. They spin once every 2 seconds, the inner glow pulses, and they no longer flicker when the loop restarts.
- Maps with an empty official monster list now use the older official server spawns: Loa Castle (7), Tomb of the Black Dragon (20), map 158, Lost Horizon (548) and the guild agit (552), plus 4 summon lists.
- Tower dungeon maps 95 and 99 keep their monster spawns.

</details>

<details>
<summary>10 | Quests (3)</summary>

- Quests that existed but could not be accepted are fixed: the ones that should be offered now have a giver, and the rest are marked inactive as in the official data.
- Thanksgiving quests 9489 and 9490 (ThanksHunting days 2 and 3) can be accepted and have working dialogs.
- Main and growth quest chains were checked link by link with no broken links.

</details>

<details>
<summary>11 | Maps & Environment (3)</summary>

- 3 maps added: Conscript A (27), Conscript M (28) and Karon's Fragments_S (120).
- Warps checked: 53 two-way pairs and 26 one-way. No warp, portal or NPC teleport leads to a map the official game doesn't use.
- If a map's collision fails to load, you can no longer walk through walls. A failed map entry cleans up properly.

</details>

<details>
<summary>12 | Dungeons & Tickets (14)</summary>

- Instance length uses each dungeon's official time limit. Party size up to 7. Mounts are dismissed on entry where riding isn't allowed. No daily entry limits, as in the official data.
- Cave of Abyss is sealed during Siege. Time Attack (614) costs 100,000 DIL to enter.
- Dungeons play only their own official monster waves. Waves borrowed from other dungeons or generated to fill gaps were removed.
- Karon's Fragments (4 difficulties) full flow, including the Shield Protector pair that must both fall within 5 seconds.
- Karon's Fragments_S is playable with a 20-minute limit.
- Quilue Liana: Qilue Rhianna appears 180 seconds after entry, and killing her clears the dungeon.
- Tower of Spell 1F plays its own waves, lever NPCs, messages and 10-minute timer. Script monster positions in Tower of Spell, Nest of Cherubim, Umbar's Hangout and Mordo Lumbule follow the older official server data.
- Dead Island: 5-second Ancient Totem gauge, resets from 10M to 160M DIL, a 7,200-second challenge, and working levers and triggers.
- Forbidden Shackles: 20 floors with per-floor clear EXP and a reset cost to start over.
- Dungeons without an entry NPC use the entry point set in the official dungeon list.
- Tickets: dungeons that need a ticket use one per entry and refuse entry without it. Requies Beach diving (236) and Cursed Night (258) need their tickets. Alternatives work (for example Infinite Battle 2: an IB2 ticket or 2 Super Passes).
- Ticket issue and use work after a reconnect without double-charging.
- Map cutscene events work (hidden UI, fades, camera, actors and dialog) and can be skipped. They are started by a GM.
- Karon’s Fragments_S has its official Warp Stones, Shield Stones, Regena and boss-room walls.

</details>

<details>
<summary>13 | Events & Modes (15)</summary>

- Classic Siege runs on its official schedule; it was running 1 hour early. Guard hire and siege skills show the official "Not yet available" text.
- Siege notices: [siege] messages show in the siege window and [message] notices in the system window for 7 seconds each, in Classic and Renew, with 30/10/5-minute warnings.
- Dead Front is rebuilt from the older official server script: routes open by kill count, and boss, gate order and timings follow the original.
- Dead Front: inner gates stay closed until the levers are pulled, treasure appears only after a win, and a blue 5-second countdown plays before PvP and overtime.
- Dead Front: parties are told whether they were selected, applications need a party and stop at the party limit, and the officer uses the official dialog and refusal lines.
- Dead Front: mid-boss and final boss kills give the whole team EXP, rewards are given only once even after a reconnect, and boss and end-of-war message timings are corrected.
- Dead Front / Ice Castle: parties with 5 or more different classes get +20% EXP.
- Ice Castle: 3 rounds of 3 waves, with Karke from round 3 wave 2, and its own official officer lines.
- OX Quiz is GM-run: 89 questions, 15 rounds, up to 200 players, Lv 195+, entry through Hani.
- DKR PvP and DK Square are run by a GM with the official GM commands. DKR PvP match names follow the official data.
- Guild War Hunting runs on map 707 with up to 200 observers, started and managed by a GM.
- Field Boss: Saturday Mitera, with normal drops.
- Guild Frontier settles from the official guild ranking data.
- The Wanted Notice Board (NPC 6214) works.
- Party War, Forgotten Shipwreck and their roulettes follow the official data.

</details>

<details>
<summary>14 | Items, Enhancement & Economy (17)</summary>

- Enhancement success rates, protection items, fail results and costs follow the official enhancement table.
- Fixed armor being treated as the wrong category by DekaPass enhancement.
- Socketing and removing gems cost 8,000 DIL. Socket stones can be inserted straight from the cursor when playing online.
- Crest: 6 slots with extraction costs by level; Hot Plier extracts for free.
- Brand, Disassemble, Amplify, Seal, Carmen option add/remove and the Bloodbane option-change recipes are connected. The Dynamic Option (Rebirth) option table is connected.
- Item rules are enforced everywhere: trade, mail, consignment, personal shops, NPC selling, dropping, discarding, shared storage and bind-on-pickup.
- Expired timed items are removed from your bag, storage and costume bag.
- Drops: 20-second loot protection and items vanish after 180 seconds. Warehouse fee is 10 DIL per unit.
- Item handling feels like the official client: click to pick up and click to drop, dragging starts after 15 px, the held icon is centred, Shift+click opens the split window, Esc cancels, and dropping outside the bag asks for confirmation.
- Dragging an item onto your character to equip it was removed. Pick-up, drop and equip sounds play by item quality.
- Cash Shop has all 175 official items and the Mileage Shop all 19.
- DekaPass season 5: 200 points per day, 6,000 per season, 39 missions and 30 rewards.
- Vehicles: crystallize, evolve and enchant. You can only ride on maps that allow vehicles.
- Orbis of Fate / supply machines: Lv 80+, with a daily limit.
- Weapons with 0 base damage in the official data show 0 in their tooltip.
- Dynamic Option (Rebirth) changes use each item’s official material recipe.
- Drops: conditional drops, item-set drops, pick-up time limits and pet pick-up rules from the official drop tables are now used. Options 307 and 337-340 show their labels, and shops 40, 61, 91 and 92 show only their official tabs.

</details>

<details>
<summary>15 | Social & Guilds (9)</summary>

- Friends list holds up to 200, and the accept/decline order is fixed. Blacklist holds up to 30 and blocks whispers, chat, megaphone and messenger.
- Mail postage is 100 DIL. Consignment: 1,000,000 DIL deposit, 5% fee, 7 days, up to 5 items.
- NPC shop buy-back holds up to 10 items and clears when you log out or return to character select.
- Party up to 7, expedition 3x7. Personal shops open in Ardeca.
- Guild permissions expanded to the official 10, with default ranks Master and 1-9 for new guilds. Existing guilds keep their rank names.
- Guild names up to 20 characters, checked against the official banned-word list (also renames and alliance names). Guild notice up to 500 characters.
- Members with the mark permission can set the guild mark; it can't change during Siege. Guild invite, leave, kick, disband and transfer messages use the official text.
- War declaration costs follow the official table (3, 7, 15 and 30 days). Up to 3 wars at once, unanswered declarations start after 3 days, and members with the accept permission can surrender.
- Alliance officers are the member guild masters; the alliance leader edits the notice and mark.

</details>

<details>
<summary>16 | Sound (2)</summary>

- Attack voices play on every attack. The first background track starts with the official delay, and a stopped sound can play again.
- Map music, volume categories, mount sounds and servant sounds follow the official data.

</details>

<details>
<summary>17 | GM & Hosting (4)</summary>

- 15 official GM commands added for running DKR PvP, DK Square and Guild War Hunting. Map cutscene events can be started by a GM.
- Modes without an official schedule (for example Guild War Hunting) no longer start by themselves; a GM starts them.
- Remember login lasts 30 days and keeps up to 5 logins.
- The server sends monster move targets and speeds so the game can move them smoothly.

</details>

<details>
<summary>18 | Removed (not in the official game) (16)</summary>

- Race mode: windows, the /race command and gameplay.
- Training Camp, including its HUD alarm icon.
- Phantom Castle is closed (no official entrance), along with the 200,000 DIL ticket purchase and its rewards.
- Carnival party mode is closed (no official entrance). Forgotten Shipwreck and its roulette are not affected.
- Automatic OX Quiz schedule, gift-box reward and countdown window; automatic DKR PvP season and Guild War Hunting schedule. These are now GM-run.
- DK Square confirm and leave timers, and the wait after Arena and party PvP matches. The 300-second duel time limit.
- "Guard" and "Cancel" damage words, and heal / MP numbers.
- The /gwar command, the 50-entry guild war log limit, the 60-second guild invite timeout, the 100-member invite cap, alliance invite/naming timers and the "kick lower ranks only" rule. Guild mark deletion.
- Made-up wing models and wing particles, the logo particles on the server select screen, and letter icons in the status bar.
- The "Preview" inspect window for other players and the /inspect command.
- 5 retired Cecil +9 weapons.
- Dungeon waves with no official data (Infinite Hunt style rounds, borrowed or generated waves). Those floors are empty until official data exists.
- Field Boss timed broadcast and special drops; automatic cutscene triggers; automatic map event timers.
- Map object hide-on-block (one cause of flashing lamps), made-up weather splashes and fades, Crash Boost screen distortion, the extra bloom boost, the big map NPC list backdrop, random particle wobble and random attack-voice skips.
- The guessed Frontier ticket from Vascuda, Dead Front's gate-closing sound and made-up officer page, Dead Front officers on maps 40-42 and 78-81, Ice Castle's made-up tower warning and wave timer, and OX's made-up countdown and English hints.
- Forced PK's 4-second limit and the PvP minimum damage of 1. The made-up EXP table fallback and made-up fallback messages in mode pop-ups.

</details>

<details>
<summary>19 | Compatibility (5)</summary>

- 4.2.0 uses the same connection method as 4.1.3. New data fields are additions that older versions simply ignore.
- A 4.2.0 game connecting to a 4.1.3 host falls back to the old behaviour (for example, monsters still move smoothly when the host doesn't send move targets).
- Older clients asking for removed modes (Race, Training Camp) get a normal refusal, not an error.
- Hosts: the fast ping uses the game port +1. If only the game port is open to players, ping still works through the normal path.
- For the full update, the host and all players should update to 4.2.0.

</details>

<details>
<summary>20 | Latest Fixes (16)</summary>

- The installer and updater never delete game files, on first launch or after an update.
- The engine finds GameGuard in your own Global client (saved by setup in global-client.json).
- Logging in again takes over a stuck old session instead of closing with "already connected".
- The staff guild setup only runs while the world is empty, so staff characters no longer roam the world.
- Staff and admin characters only wear legal gear. The Azure Knight gets the official weapon-set swap: tab I dual axe or dual mace, tab II mace + shield.
- Character select and create: every class stands at the same spot, distance and height in its card, and each class keeps its own official backdrop.
- "Full asset verification did not complete. Game launch stopped." no longer blocks a good install. The install re-checks itself.
- The weapon and armor enhancement glow is back (silver, blue, gold, red and purple by grade), with its pulse, colour and scroll matched to the official game. The tier glow on item icons is back too.
- Item icons are loaded and cached at startup, so the inventory, storage, NPC shops, D-Shop and VIP open full instantly. The inventory no longer opens empty.
- Skill cast animations are preloaded, so skills play their full animation in sync instead of freezing, cutting off or not showing.
- Starter boxes, gift boxes and packs open again.
- Dashboard: the false "world is busy" status message is fixed.
- Buff and enhancement glows no longer all disappear at once when a character changes look (for example Trans-Up or a gear change). Party buffs last their full time, a recast refreshes them, and they end on time.
- Smoother frame rate on maps with reflective water, such as Ardeca: lights are re-pointed instead of rebuilding shaders every frame, with an identical picture.
- The weapon and armor enhancement glow now pulses and scrolls at the official slower speed (a 3.5-second pulse) instead of flickering too fast.
- Window title is Dekaron.exe, with minimize and close only.

</details>

*Earlier 4.1.3 changes remain included.*
