-- L17 0002 (SQLite): same world-state document table as mssql/0002, for JSON-file modules. Additive; no data moved.
CREATE TABLE IF NOT EXISTS world_state (scope TEXT NOT NULL, id TEXT NOT NULL, json TEXT NOT NULL CHECK (json_valid(json)), revision INTEGER NOT NULL DEFAULT 1, updated_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now')), PRIMARY KEY(scope,id)) STRICT;
