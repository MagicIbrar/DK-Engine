# DK Engine 4.0.0 — Inventory, Skills, Effects & Client Readiness

Version 4.0.0 brings the following changes since 3.3.5.

[4.0.0 release notes and downloads](https://github.com/waveforgemp3app-cmyk/Tool/releases/tag/v4.0.0)

## 01 | Inventory pickup, placement and swaps

- Items now have real saved cursor ownership. Picking an item up removes it from its previous slot; it stays held until you place it, swap it, or successfully return it.

- Added consistent cursor placement, occupied-slot swaps, stack merges and remainder handling across inventory, equipment, the potion belt, personal storage, account storage and the costume bag.

- Full-bag equipment swaps can keep the displaced item on the cursor. Dependent off-hand equipment is preserved for recovery instead of silently dropping or disappearing.

- Picking up equipped gear detaches its equipment references and worn bonuses. Equipment checks use the destination equipment set, including inactive sets.

- Closing and reopening windows, reconnecting and reloading preserve held-item ownership. Escape returns the item only when its original destination is legal; otherwise it remains held.

- Cash-inventory and pet-inventory items use the same cursor ownership rules. Cash metadata and expiry are preserved, and held pet contents remain recoverable if the pet is removed or unsummoned.

- Added acknowledged cursor transactions so repeated clicks, stale responses, invalid placements and failed saves cannot silently move the same item twice.

- Explicit item dropping retains confirmation, map restrictions, rolled item properties and loot ownership. Inventory overflow no longer triggers an automatic equipment drop.


## 02 | Trade, shops, storage and saved ownership

- Connected held items to crafting, mail, trade, character-transfer payments, player-shop registration, NPC sales and shop search. Services that require bag space explain the refusal and retain the held item when no legal space exists.

- Safe inventory cursor moves no longer unnecessarily close trades or character-transfer offers. Offered items, reserved money, confirmation locks and actual movement or disconnect cancellation remain enforced.

- Mail, gifts and GM transfers now include held items and nested pet contents in duplicate-ownership checks. GM inspection and editing recognize cursor items, and custom-item archiving preserves other players' existing copies.

- Added save and connection compatibility checks for the new held-item state, including local and SQL-backed persistence and older clients that cannot display held items.


## 03 | Pet, enhancement and consumable safeguards

- Pet disassembly now refuses expired inputs instead of granting output without consuming the target. Pet Soul Chain Reset also checks expiry and stack count and rolls back a failed save.

- Enhancement material selection excludes expired Brand Option Lock items and checks consumption results before completing the operation.

- Buff and premium consumables are no longer consumed when their required status data is unavailable. Temporary loading failures can recover in the same session without granting a partial premium benefit.


## 04 | Party protection and Recall skills

- Corrected Divide Pain and Divide Force damage sharing to use the caster and protected party member, with their respective 40% and 25% shares and appropriate target validation.

- Corrected Summoner and Concerra Recall to relocate the selected eligible party member. Party membership, location and eligibility are checked again when the effect lands; the separate servant recall command remains available.


## 05 | Skill movement and server combat checks

- Improved skill and basic-attack movement synchronization, authored movement-curve sampling, collision handling and correction of refused predicted attacks.

- Strengthened server validation of basic-attack sequences and authored attack timing. Changing targets or reconnecting no longer resets the relevant combat timing protections.

- Tightened movement-budget checks, including repeated rounding allowance, speed-based recovery, bounded burst allowance and clock rollback handling.


## 06 | Skill visuals and sound lifetimes

- New local skill casts wait for their reachable graphics resources before spending resources or sending the cast. Preparation has bounded work and deadlines, rechecks cast eligibility and cancels stale intent; native effect clocks remain unchanged.

- Fixed unwanted flat white meshes in Armor Breaker and Energy Hammer by respecting their authored zero-size effect layers.

- Effect sound selection now follows the visual scene selected by a scene-zero request, including the affected Judge of Helion effect records.

- Stopped effect scenes can no longer launch delayed sound, mesh or camera controls after their owning phase has ended. Existing emitted particles can still finish normally.

- Native wing animations retain their authored speed when the character moves faster or slower.

- Equipment effects preserve their ongoing animation when switching between peace and combat stances selects the same native effect. Authored animation timing remains unchanged.


## 07 | Monster, NPC and servant effects

- Connected authored action effects for normal monsters and monster-based NPC models to their selected animations, with cleanup on interruption, death, despawn and map changes.

- Map entry now waits for the visible monster bodies to finish loading.

- Restored authored servant attack effects and basic idle, hit, death and attack sounds. Servant voices and scene audio avoid duplicate playback, and local and observer death-event ordering no longer suppresses the death voice.


## 08 | Mount and pet effects and audio

- Preserved class-specific mount appearance effects and authored mount action effects, including cloud mounts. Older prepared caches can recover the corresponding action data from validated source records.

- Connected pet appearance, idle, movement and swimming action effects with independent lifetimes. Pet enter and leave effects now follow accepted spawn and removal transitions without stale asynchronous reappearance.

- Restored motorcycle idle and running scene audio with its authored distance limits and cleanup on movement changes, dismount, death, map changes and disposal.


## 09 | Ultimate weapon action tables

- Restored selection of 39 Ultimate weapon action tables whose filenames previously bypassed the action-table index.


## 10 | Map rendering and event objectives

- Enabled authored map-object normal maps where the object and material support them, including mirrored tangent handling and graphics-option changes.

- Restored omitted floor-reflection groups in Chaos Temple and Mansion. Reflection rendering now preserves all authored height groups and rejects obsolete map-loading callbacks.

- Empty and erased map decals no longer trigger unnecessary texture requests; visible decal records retain their normal loading and rendering path.

- Fixed Infinite Battle and Dead Front quest progress recognition to use the map's authored script identity as well as legacy names, including the renamed [IB] maps.


## 11 | DK Stats and player-count display

- Eligible unclaimed Awakening/DK rank rewards are now granted when the level gate is crossed. Existing claims prevent duplicate rewards; later exchanges also recover previously missed eligible rewards.

- Corrected the DK Stats tab layout, overlapping backgrounds and EXP-label handling. DK Point and DK Tier rows retain the game's existing frame style.

- Moved the live online-player count into a centered native-style row beneath the top-left title, aligned with the date row. Removed the separate count beside the minimap and adjusted the controls below it.


## 12 | Startup progress, interface caching and readiness

- World entry no longer waits for graphics preparation for every learned skill. A requested first cast still prepares its own resources before costs or dispatch; native effect clocks remain unchanged.

- Restored Global’s blue movement destination marker, including tracking while holding the mouse button.

- The first page of each NPC shop on the current map prepares before entry and displays cached images on first open. Other shop pages prepare in the background after the world is ready.

- Skill-tree connection lines and button artwork now prepare before entry so they appear together when the panel first opens.

- Time and login reward panels now prepare their reward and required-item images before entry, so those images are ready when the panels first open.

- Fixed missed chat replies when network updates arrive out of order.

- The launcher reaches 100% only after frontend readiness, and unfinished loading work no longer rounds up to 100% prematurely.

- Probability Info builds its controls in smaller batches and avoids repeatedly indexing the same controls, reducing the measured panel-construction work.

- Added an optional compiled UI cache tied to the prepared data, engine version and compiler version. Storage failures fall back safely, and required loading errors remain visible.

- Required item, skill and online-network systems must finish installation before world entry. Required effect and status catalogs finish loading before skill data becomes ready, with shared catalog objects, bounded retries and clear terminal failure handling.


## 13 | Global data compatibility and safe preparation

- Improved source-data compatibility through explicit text encoding markers, named item primary-key columns and validation of supported map/table layouts. Failed or interrupted preparation keeps the previous prepared generation intact.


## 14 | Verification and community thanks

- Validation includes 38 passing integrated regression suites, 229 grade-reward checks, 14 skill-installation checks, 46 cast-resource guard checks and 9 focused browser/WebGL checks, alongside existing inventory, server, rendering and audio coverage. These results do not establish all-skill visual or native-client parity or replace in-game testing.

- Big thanks to DEV ShadoW, CYBER and Magic Ibrar for helping with the project, and to everyone contributing, testing and sharing feedback.

