# DK Engine 4.0.2 — Command Center

Version 4.0.2 adds the integrated DK Command Center launcher. Open `Client.exe` as before: setup checks the required runtimes and prepared Global files, then opens Command Center. If the new window cannot start, setup opens the classic launcher. In Settings → Launcher, you can choose the classic launcher for subsequent starts.

The Home page shows world status, player and bot counts, storage choice, recent events, and first-start world settings. Play & Connect groups local play, joining and hosting. Server contains world controls and account tools. SQL & Storage includes connection profiles, database browsing, bounded live monitoring, a read-only query workspace, and guarded backup and test-database tools. Game & Content, Updates & Diagnostics, and Settings & About hold the remaining tools without separate launcher windows. An embedded update prompt offers Install now or Later; updates still use the engine's verified, deferred installer.

The installed launcher uses this engine's own world and prepared Global generation. Launcher preferences and diagnostic exports live in a separate per-install profile under `%LOCALAPPDATA%\DK Command Center`; account and character storage remains under the engine or SQL Server according to your storage selection. Switching between local files and SQL Server does not migrate existing characters automatically.

Command Center's SQL query workspace defaults to database-enforced read-only access. Write mode is limited to disposable `DKTEST_` databases. Backups and setup actions show their target before they run. Players connect to the game server; SQL Server is not exposed to game clients.

The 4.0.1 gameplay and content fixes remain included. The release package contains no Global game assets: supply your own Global folder when setup requests it. Existing installation state is preserved by the updater; keep your own backup before changing storage or updating.

Contributors: DEV ShadoW, CYBER, Magic Ibrar.
