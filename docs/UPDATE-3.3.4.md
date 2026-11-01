# DK Engine 3.3.4 — equipment, cursor and water-map update

Use your own legally obtained, updated Global game files. Keep backups of your game files and saves. Extract the complete Engine folder together, close the game and world before updating, then open `Client.exe`. Existing account, settings and SQL data remain in the installed data location; changing Local/SQL targets does not merge those saves.

## Changes since 3.3.3

- Clicking inventory equipment or a bag item lifts its icon onto the cursor. A refused placement keeps an owned item held so another grid cell or compatible slot can be chosen.
- Successful equipment and bag swaps continue holding the displaced item, resolved from the acknowledged owned item UID and its actual destination. F-key belt moves use the same ownership handoff.
- Skill shortcuts can be picked up with a click. Swapping two shortcuts leaves the displaced shortcut on the cursor. The quickslot lock still blocks editing.
- Closing and reopening inventory while carrying an item keeps the cursor state, including through the inventory button.
- Ordinary equipment changes keep the existing character skeleton, animation mixer, unchanged meshes and independent slot effects. Only the changed gear is replaced; changing armor no longer restarts the sword, shield, wing or emblem effects.
- Independent offhands, including shields, select their own refinement effects. A held-item preview uses the visible loadout before the server commits a placement.
- Compatible equipment-to-occupied-bag swaps retain the displaced item on the cursor. Large-item footprints clamp inside the grid, including edge cells; partial stack merges retain only the owned remainder.
- A held equipped item can swap with a wing, box or other bag item without trying to equip that bag item. Different-size swaps can safely park the displaced item elsewhere when the source footprint is too small; it remains held on the cursor. A synthesized double-click cannot auto-use or auto-equip an item during pickup/swap.
- Stabilize sprite-trail edge orientation when an effect gently bobs or reverses direction, including Karon Bell Emblem VI. Authored texture, color, size and animation keys remain unchanged.
- Prepare all unique NPC shop item thumbnails during loading and retain compressed session images so the first populated shop grid can reuse them. Startup now reports NPC shop preparation progress. This moves artwork work into startup; it does not remove network or database latency.
- Restore the movement click marker.
- Swim handling recognizes the mapped aquatic areas across all 15 classes, with a fallback for older prepared client generations.

## Scope

The item server remains authoritative. A red requirement or slot refusal does not commit a move. The package contains the engine and required runtime files, but no Global game assets or player accounts. These changes were checked in focused code regressions; a live retest of every item, map and character combination is still welcome.
