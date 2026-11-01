# Save backup, rotation and restore (L17)

Covers the account store (`DEKARON_ACCOUNT_STORE`, default server/accounts/data.json), every sibling `<store>.*.json`
atomic store (rates, permissions, settings, items ...), and the SQLite store (`DEKARON_ACCOUNT_SQLITE`). Code: server/save-backup.mjs,
CLI tools/save-backup.mjs (node >= 22.5). Not wired into the launcher/Command Center (other team) or a scheduler; run it from the
OS scheduler (Task Scheduler / cron) or call `runBackupJob` from a server timer.

## Consistency
- JSON stores are only replaced by tmp+rename, so one open/read sees one whole generation; it must JSON.parse or the run fails.
  `*.tmp` files are never copied.
- SQLite: online backup API (`node:sqlite` `backup()`), then `PRAGMA integrity_check` on the copy. No raw file copy.
- A set is built in `.<stamp>.partial` and renamed to `<stamp>` only after every file is written; manifest.json has sha256 + size.

## Retention (defaults, configurable)
`--keep-last 10 --keep-daily 7 --keep-weeks 4`: newest 10, newest per UTC day for 7 days, newest per ISO week for 4 weeks.
Rotation runs only after the new set verified; sets without a manifest and crashed `.partial` dirs are removed.

## Commands
    node tools/save-backup.mjs run --dest D:\DekaronBackups [--sqlite path] [--keep-last N --keep-daily D --keep-weeks W]
    node tools/save-backup.mjs list --dest D:\DekaronBackups
    node tools/save-backup.mjs verify --set D:\DekaronBackups\<stamp>

## Restore
1. Stop the server (stores must not be written during restore).
2. `verify` the set. 3. `node tools/save-backup.mjs restore --set <set> --to <staging dir>` (refuses unverified sets, refuses to
   overwrite unless `--overwrite`; each file tmp+rename; stale `-wal`/`-shm` next to a restored SQLite file are removed).
4. Move the staged files over the store paths listed in manifest.json `source` (or restore with `--to` the store directory and
   `--overwrite`). 5. Start the server.
