# DK Engine 3.3.3 — review build

This build is staged for owner game testing. GitHub and forum publication await approval.

## Start

1. Keep your existing Global download and a backup. Extract the complete Engine folder together.
2. Open Client.exe. In Options, select **Local** or **SQL** before the green Launch button.
3. For local or remote SQL, open **SQL / VPS** to check the chosen instance and prepare that world. Phones connect to the game-server address, not directly to SQL.
4. Launch your world, then launch the DX11 client and sign in.

## Changes since 3.3.2

- The startup Options page shows the saved Local/SQL choice directly. SQL / VPS still handles local and remote SQL details.
- SQL setup adds engine_character_extra and engine_cash as additive character, inventory, and cash projections. Existing character profiles remain the authoritative game saves. SQL setup backfills projection rows without overwriting existing player data.
- The final merged bot, wing, visual, GM rate, and runtime changes from the private 3.3.3 integration are included in this candidate. Native visual parity and all skills are not claimed; further skill work is planned for 3.4.0.

## Data note

Back up accounts and SQL before changing storage. The new SQL tables are synchronized projections for inspection and future interoperability. Do not edit them as an alternative way to grant cash; the game still reads the authoritative character profile.
