-- L17 0001 (local SQLite account store, server/accounts/sqlite-store.mjs): migration tracking. Additive.
CREATE TABLE IF NOT EXISTS schema_migration (id INTEGER PRIMARY KEY, name TEXT NOT NULL, sha256 TEXT NOT NULL, applied_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now'))) STRICT;
