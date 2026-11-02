# Install or update DK Engine — 3.3.0 Client & SQL One-Click Install Update

If you already have the full portable copy, open **Client.exe**. It opens this engine's galaxy launcher. Use **Options > SQL / VPS** for storage setup. A desktop shortcut named Dekaron Engine 4.1.1 (or DK Engine) opens DK Command Center (DKCommandCenter.exe) with the transparent Engine icon; older Client.exe shortcuts are still accepted. For an existing installation, close its game windows and stop its world before updating; open Client.exe from the new package and choose the verified installed folder if asked. Your installed accounts/settings remain in place; SQL data remains in its database.

## New installation

Double-click **Client.exe**. **Setup-DK.cmd** is an optional setup alias. It prepares Node.js 24 and WebView2, checks supplied game files, creates a new installation under the current user's Local AppData/DK Engine folder, and creates the desktop shortcut. It updates a verified existing DK Engine installation while preserving its accounts and settings, and refuses unrelated folders, overlapping sources and links. Supplied Global data folders stay untouched.

Supply either a prepared Global engine folder with a validated active generation, or the original Global data folder containing pack.hdr + pack.dNN files (or loose share/maplist.csv). Setup looks nearby and asks for a folder if needed; it does not scan the whole drive. An engine-only package requires your Global files separately. No Farius client, executable or database is required. The official Global executable is not used to connect to this server.

The default portable install copies prepared Global assets into its own folder. The current prepared assets are about 9.3 GiB, plus runtime files. Original-data preparation uses an isolated temporary engine before making the final portable copy; allow roughly twice the prepared asset size plus runtime files. It validates the source through the existing preparation pipeline. Failure removes only this invocation's temporary output.

A fresh install omits development accounts, passwords, launcher tokens, saved world state, logs and internal development reports. Create your own account. Updates preserve your installed accounts, world state and settings. Keep account/database backups before changing an existing world's storage.

## After setup

Open **Options**, choose Local files or **SQL / Storage**, and save/review the desired settings. The green **Launch** button starts the selected world and opens its dashboard. **DX11 Client** opens a windowed 1024x768 game area in a fixed Global-style window (title "Dekaron", minimize and close only, no drag-resize; Options > resolution still resizes it); the adjacent **DX11 Fullscreen** button opens borderless fullscreen. Account sign-in is still required. Local DX11 loading performs the installed-file check in that same native window using the authored Global startup screen, then finishes frontend/graphics readiness before the login hall appears. See [README.md](README.md#loading-before-local-play) for the measured progress phases and cache limits.

## Dependencies

Compatible installed Node.js 24 and Microsoft WebView2 are reused. Setup also reports .NET Framework 4.x and VC++ x64 presence in -CheckOnly without requiring them as new hard installs (Windows inbox / optional game-window runtimes). When missing, setup obtains an official Node runtime with a verified SHA-256 checksum and OpenJS signature, or the Microsoft-signed WebView2 installer. See [Node release files](https://nodejs.org/download/release/latest-v24.x/) and [WebView2](https://developer.microsoft.com/en-us/microsoft-edge/webview2/).

SQL is optional. Open **Client.exe > Options > SQL / Storage**, choose the local or hosted world, and click **Prepare SQL automatically**. Missing SQL requires explicit acceptance of the linked Microsoft license terms/privacy notice and Windows UAC approval. The helper verifies Microsoft signatures on official Express media and setup.exe, installs quietly with Windows authentication, then prepares the selected engine schema and selects SQL storage. Existing local named SQL instances are reused without installation or reconfiguration. Automatic installation supports a local named instance such as .\SQLEXPRESS or .\DEKARONBETA; use the SQL instance field and the separate check/setup actions for a reachable remote Windows SQL instance. No SQL passwords are supplied and no public SQL listener is enabled. A restart request stops database setup; save work and restart manually. Continue with the existing owner-account/Grant GM controls afterward.

Then choose the Local world or Hosted world target, **Check SQL**, and **Set up SQL world**. Choose SQL Server storage for the next startup. Stop the world before database setup or changing storage. See [SQL-SETUP.md](SQL-SETUP.md).

Advanced dependency helpers: powershell.exe -NoProfile -File tools/bootstrap-dedicated-runtime.ps1 -InstallSql -AcceptSqlLicense, or tools/install-dedicated-sql.ps1 -AcceptLicense after reviewing Microsoft terms. Their -CheckOnly mode performs no installation. Microsoft SQL setup logs are under Program Files/Microsoft SQL Server/150/Setup Bootstrap/Log.

## Advanced staging

Use node tools/stage-dedicated-install.mjs --check for staging prerequisites. A ready result is not proof of SQL, internet connectivity, official-client compatibility or full game parity.

Use --stage with a new destination and --global-engine with a prepared source, or --raw-global with original Global data. --node-exe supplies the Node executable to bundle. The raw-data --check recognizes the layout only; extraction/builders do full validation. Advanced --linked-global mode avoids the portable asset copy but requires that prepared source to remain available; raw-data mode always makes a portable copy.

A full portable build and isolated SQL/hosting fixtures have been validated locally. Missing-runtime branches have mocked coverage. A real clean-Windows installation has not been completed in this validation. SQL uses this engine's own dedicated schema; it does not require any original-server database. This build is not published.

Client.exe also updates an existing verified DK Engine installation in place. Stop its world and close its game/launcher first. Updates prepare and validate a replacement before preserving accounts/settings and replacing the installed code; one previous copy is retained for rollback. SQL data stays in its existing database. Unrelated folders and modified installations are refused. The default folder is Local AppData/DK Engine; a verified existing legacy installation is reused.
