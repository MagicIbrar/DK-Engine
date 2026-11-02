# DK Engine 4.0.3 — Map entry, stun and Chakra fixes

Version 4.0.3 is a small fix release on top of 4.0.2. The Command Center launcher, storage options and every 4.0.2 and 4.0.1 change remain included. Installed 4.0.2 copies are offered this update by the launcher's update prompt.

Maps: Requies Beach, Honeymoon Island and Ellonom open again. Their firefly effect scene points at a path animation that the Global files do not contain, and the map loader used to treat that as a failed load ("Loading stopped unexpectedly"). Now only the missing effect part is skipped and the rest of the map loads. Those firefly effects are not drawn on these three maps.

Stun: a stunned character now plays the stun animation for the whole stun. Before, stun statuses were read as a knock-down, so the character flipped and tumbled in the air on the stunned player's own screen.

Summoner skills: Dual Chakra (Vicious Summoner and Conserra Summoner) keeps its party and enemy auras for as long as the skill lasts. Before, the auras ended after about 3 seconds while the skill itself lasts about a minute.

Statuses that had no effect before:

- Statuses that block HP or MP recovery now stop natural regeneration and the HP or MP restored by skill effects.
- Mana shock style debuffs take their MP loss when they are applied.
- Lethal Cutter's Ignore DEF ignores part of the target's melee defence.
- Rapid Fire's Additional Shield Damage takes extra points off a PvP shield.

The release package contains no Global game assets: supply your own Global folder when setup requests it. Existing installation state is preserved by the updater; keep your own backup before updating.

Contributors: DEV ShadoW, CYBER, Magic Ibrar.
