Dashboard identity and transparent artwork

Dashboard icons are edition-specific crests. Game icons remain the native game executable's own resources. Do not substitute the dashboard crest into dekaron.exe, Dekaron_local.exe, GameWindow's native-client icon, or a native game-only shortcut.

The ICO contains transparent PNG frames at 16, 24, 32, 48, 64, 128 and 256 pixels. The 256-pixel PNG is for normal UI/favicons; the 512-pixel *-dashboard-logo.png passes the command-center logo uploader. The SVG is the editable vector source. Checkerboard patterns appear only in the preview sheet, never in delivered assets.

Start-VersionDashboard.ps1 receives this edition's exact project, engine and profile paths. It does not invoke the old shared LocalAppData bootstrap. ValidateOnly checks routing and identity without starting the dashboard, game or game services. The entry sets DKCC variables only in its own child environment.

DashboardIdentity edits only the two UTF-16 AppUserModelID literals in admitted managed dashboard builds, with equal byte length. It normalizes those literals and checks the entire remaining binary against the two reviewed source hashes before any edit. The native game is never an input. An unrelated/new dashboard build is rejected, not patched by guessed offsets. Dashboard host code updates should set the edition/root/profile identity in source or add a newly reviewed build hash after static inspection.

Identity is DK.Dash. plus the first eight lowercase hexadecimal SHA-256 characters of UTF-8(edition + '|' + normalized project root + '|' + normalized profile directory). Paths are absolute and lowercase. The dashboard checks its identity each launch, so a folder copied to a new location receives a new identity without mixing with another build. The desktop link must use the same AppUserModelID. A relocated copy needs its own newly created desktop shortcut pointing to that location.

Backups of changed assets, UI files and old desktop shortcuts are under this project's dashboard-branding-backups folder. The dashboard host's original binary backup is in tools/command-center/branding-backups (under engine for projects using that layout). Receipts are in the named project profile. No Windows/taskbar transparency settings are changed.

Build helpers with the installed .NET Framework C# compiler, referencing System.Web.Extensions.dll. RenderDashboardIcons.cs additionally needs System.Drawing.dll. The supplied helper binaries are built from the adjacent source files. No decompiler output is represented as original source by these branding helpers.

Global package: the runtime owner should close only its own dashboard, run Install-Global-Branding.ps1 -ValidateOnly, then run the installer normally. It applies its exact admitted host identity, copies artwork/helpers/direct entry, and creates Global 0.0.1 Dashboard.lnk. It does not launch any game or service. If its host has changed, integrate the identity into that current source rather than disabling hash checks.

A2: native dashboard-shell, browser favicon and portability integration belong to the A2 runtime owner. Use tools/a2-dashboard/assets/a2-dashboard.ico for the dashboard; retain the native dekaron.exe/a2-icon art for the game.

A9: Dashboard/assets contains branding only. No client/server/database has been acquired or validated by this branding package. Do not create a playable-game shortcut until the A9 build guide's readiness gates are met.
