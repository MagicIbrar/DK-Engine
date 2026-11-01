# DK Engine 4.0.1 — Startup, exchanges and event reliability

Read [UPDATE-4.0.1.md](UPDATE-4.0.1.md) for this update and [UPDATE-4.0.0.md](UPDATE-4.0.0.md) for the previous release and automatic update steps.

Open **Client.exe** to use the galaxy launcher for this engine. Open **Options** to review and save your settings, then click the green **Launch** button to prepare/start the selected world and reach its dashboard. Choose **DX11 Client** for a windowed 1280×720 game area, or the adjacent **DX11 Fullscreen** button for borderless fullscreen on the current monitor. Sign in when prompted. You can also keep a hosted world running without opening a game window. Global files supply game data, maps, models, textures, sound and UI assets. Neither the official Global executable nor a Farius client is launched.

An engine-only package requires your own compatible Global files. A full portable installation includes its prepared Global assets and Node. It starts with no development accounts, saved passwords or character progress. Create your own account in the launcher. If the folder already contains your installed game, use Client.exe; Setup-DK.cmd is an optional alias for the same setup flow.

Open **Options > SQL / Storage** to choose Local files or SQL Server for the next world startup. Stop the world before changing storage. Local and hosted worlds have separate accounts and SQL databases. SQL stores account, character and social data; maps, models, textures, sound and UI remain game assets.

Use **Host friends**, **Connect** and **Hosting options** for invite/open hosting, LAN/VPN access and optional directory listing. Players connect to the game server, never directly to SQL. Internet access depends on your selected network/relay configuration and must be checked from another computer.

Read [SQL-SETUP.md](SQL-SETUP.md) for SQL instructions and [DEDICATED-INSTALLER-3.3.0.md](DEDICATED-INSTALLER-3.3.0.md) for installing a new copy from supplied Global files. Keep your account files and database backups before changing storage or migrating progress.

This is an independent engine using user-supplied Global game data. No Farius executable, database backup or native-client bridge is required. Optional SQL uses this engine's own account/character/social schema. A real installation on a clean Windows computer has not been completed in this validation. Engine rendering uses WebView2/ANGLE; this is not a claim that the official Global executable connects to this server or that its rendering and protocol are identical.

Client.exe also updates an existing verified DK Engine installation in place. Stop its world and close its game/launcher first. Updates prepare and validate a replacement before preserving accounts/settings and replacing the installed code; one previous copy is retained for rollback. SQL data stays in its existing database. Unrelated folders and modified installations are refused. The default folder is Local AppData/DK Engine; a verified existing legacy installation is reused.

## Loading before local play

For local **DX11 Client** and **DX11 Fullscreen**, the native game window opens first and shows the installed Global startup artwork while **Verify and warm all installed assets** reads the prepared files. The first pass establishes a local SHA-256 baseline; later passes check that baseline. Cancelled or failed verification stops the handoff. A fresh login ticket is issued only after verification, so the long read does not consume its lifetime.

The same game window continues into catalog, interface, login-scene and shader preparation, then reveals the login hall when ready. Its percentage combines installed-byte verification (0–75%) and those preparation phases (75–100%); it is not an estimate of remaining seconds. Display smoothing never advances beyond completed work, and there is no artificial minimum loading time. Cached file access may be faster.

This reads/checks local files and may warm the operating system cache; it does not keep the whole game decoded or GPU-resident. Desktop App and the launcher's Web Browser action retain the launcher verification step. Remote joins and independently opened browsers do not claim to verify every file on the remote host. Rendering/protocol parity with the official Global client and a clean factory-Windows installation are not established by these checks.
