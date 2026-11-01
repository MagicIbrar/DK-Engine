# DK Engine 3.3.1 — Installation hotfix

## New players

1. Download and fully update your own compatible Global game files. Keep a separate backup.
2. Download **DK-3.3.1.zip** from this project's GitHub release. Right-click the ZIP and choose **Extract All**.
3. Move the **whole Engine folder** beside Global's **bin** and **data** folders. Keep every file and subfolder inside Engine together.
4. Open **Engine > Client.exe**. Do not run it inside the ZIP, and do not copy only the EXE.
5. Let setup finish. If asked, select Global's data folder. The launcher then opens Options: choose your settings and click the green **Launch** button.

Example:

    Dekaron
      bin
      data
      Engine
        Client.exe
        GameWindow.exe
        tools
          client-ui.ps1
        runtime
        server
        ...all the other included files and folders

## Existing players

Back up your saves/database, stop your server, and close the game and launcher. Extract the whole new ZIP into its own download folder and open its Engine > Client.exe. Keep the existing installed folder and prepared Global files. Setup updates a verified installation while preserving its accounts/settings; SQL data remains in its database. Do not delete your installed game to apply this hotfix.

## If setup says client-ui.ps1 or another package file is missing

Extract a fresh, complete DK-3.3.1.zip and open Client.exe from that extracted Engine folder. Do not mix individual files from different releases. The download includes the launcher scripts; setup checks the complete set before preparing Global files and checks the staged installation before activating it.

If extraction succeeds but a file disappears, review your security software's detection history. Do not disable protection or restore a flagged file blindly. Keep the setup log named in the error so the exact missing path and failure can be investigated. Hide personal paths and credentials before sharing logs.

## What this hotfix changes

- Rejects incomplete engine packages before the long Global preparation step.
- Requires and validates the launcher files in the staged installation before reporting success.
- Includes the native-client icon build helper with its dependent script.
- Allows a code-only update to reuse a validated portable prepared Global generation.

The reported 3.3.0 screenshot did not include its setup log. The original 3.3.0 archive contains client-ui.ps1, so an omitted archive entry is not a confirmed explanation for that particular installation.

## Optional SQL

Use Options > SQL / VPS. Local files remain available without SQL. Automatic SQL setup installs on this Windows PC after you accept Microsoft's terms and approve administrator access if requested. An existing SQL installation is reused. For a remote SQL host, enter the connection details and check access; players connect to the game server, not directly to SQL.
