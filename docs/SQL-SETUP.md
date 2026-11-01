# DK Engine SQL setup in Options

1. Open **Client.exe** and choose **Options > SQL / Storage**. Stop the current world first.
2. Choose **Prepare SQL automatically**. Choose a local named instance (the default is `.\SQLEXPRESS`). To keep an existing instance separate, choose a different unused local name, for example `.\DEKARONBETA`. If the selected instance is missing, review the linked Microsoft license terms and privacy notice and check acceptance first. Setup downloads official Microsoft full Express media, verifies Microsoft signatures, then installs quietly after Windows administrator approval. The exact selected existing local instance is reused without reinstalling or reconfiguring it.
3. Choose **Local world - DEKARON_DEDICATED** for private play, or **Hosted world - DEKARON_DEDICATED_HOSTED** for Host friends/open hosting.
4. Automatic preparation also runs the guarded setup for the selected SQL world and selects SQL storage on success. **Check SQL** and **Set up SQL world** remain available separately. Setup requires a stopped world, preserves existing account data, and creates/checks only the selected dedicated database. Windows integrated authentication is used; this is a Windows SQL path, not an automatic Linux/VPS SQL provisioner.
5. Select **SQL Server** as storage. The choice applies on the next world startup. Return to the launcher and use the green **Launch** button or the configured hosting flow. On the dashboard, choose **DX11 Client** or **DX11 Fullscreen** to sign in and open the game. Selecting a setup target alone does not start a world.

To use file storage, stop the world and select **Local files** instead. Changing storage is not a promise of an automatic two-way migration. Back up the account files and SQL databases before moving existing progress, and confirm the desired accounts/characters after restarting.

| World | Default game port | SQL database | Local working account file |
|---|---|---|---|
| Local | 7996 | DEKARON_DEDICATED | server/accounts/data.json |
| Hosted | 7778 | DEKARON_DEDICATED_HOSTED | server/accounts/friends-accounts.json |

The working files are relative to this installation. Local and hosted accounts stay separate. A second host cannot own the same SQL world at the same time. If the selected port is occupied, stop the other installation through its own launcher; this launcher does not stop unrelated servers. SQL setup creates this engine's own engine_account, engine_character, engine_social and schema metadata tables in the selected dedicated database. No Farius client, database backup, account/CHARACTER database or native-client bridge is required. Existing unrelated databases are not setup targets.

**Hosting options** retains the original invite/open, LAN/VPN and public-directory opt-in workflow. Players connect to the game server, never to SQL. Keep SQL private. External connectivity needs a remote-player check with your chosen VPN/relay configuration; no test created a live public-directory entry.

Validation includes local SQL launcher lifecycle and isolated real-SQL invite/open hosting, account/character persistence and recovery, account isolation and local directory fixtures. Missing dependency paths have mocked coverage. These checks do not establish a real clean-Windows installation or compatibility with the official Global executable.

SQL installer diagnostics are under Program Files/Microsoft SQL Server/150/Setup Bootstrap/Log. If Windows must restart, save your work and restart manually before continuing. See [DEDICATED-INSTALLER-3.3.0.md](DEDICATED-INSTALLER-3.3.0.md) for dependency details.

After SQL is ready, continue through the existing owner-account and Grant GM controls. Installation does not grant GM or create a shared password. A failed or cancelled install leaves storage unchanged; retry the same action after resolving the displayed error. No automatic Windows restart is requested. Missing-dependency installation is fixture-tested, not verified on a clean factory machine.

## Existing or remote Windows SQL instance

Use the saved **SQL instance** field for a local instance, a server name, a host\instance name, or a host,port address. Run **Check SQL**, then **Set up SQL world** for the selected Local or Hosted database. The field accepts an instance address, not a username, password or connection string. Your current Windows identity must be authorized, and the server must already be reachable over the appropriate private network/TCP configuration.

**Prepare SQL automatically** installs/reuses the selected local named instance. Accepted local spellings are `.\NAME`, `(local)\NAME`, and `localhost\NAME`; NAME starts with a letter, contains at most 16 letters/digits/underscores, and cannot be MSSQLSERVER or DEFAULT. The default remains SQLEXPRESS. Choosing Local SQL preserves an existing local named-instance selection. A returning user can reuse the same instance without creating another one. It does not provision SQL on a remote VPS, configure domain trust or open network/firewall rules. A Windows VPS can run the Windows engine/SQL setup with an appropriate authorized identity; Linux hosting uses the documented JSON/SQLite path rather than this Windows SQL installer. See [HOSTING.md](HOSTING.md).

Storage/instance choices are saved for the next world startup. Keep backups when changing an existing installation, and stop its world before changing its storage target. SQL stores mutable account/character/social state; it does not replace the prepared Global asset files.
