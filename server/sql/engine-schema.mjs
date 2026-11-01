// Engine-owned SQL schema. Created by tools/sql-setup.mjs (idempotent). The legacy Dekaron databases (account, CHARACTER, ...) are
// never altered by this file; the engine's own tables live in their own database so a drop/recreate cannot hurt legacy data.
import { createSqlClient } from './sql-client.mjs';

export const DEFAULT_ENGINE_DB = 'DEKARON_ENGINE';
const IDENT = /^[A-Za-z0-9_]{1,64}$/;
export function assertIdentifier(name) { if (!IDENT.test(name)) throw new Error(`Unsafe SQL identifier: ${name}`); return name; }

export const SCHEMA_VERSION = 2;

// One statement per entry (each is its own batch so a failure names the culprit).
export const SCHEMA_STATEMENTS = [
  `IF OBJECT_ID('dbo.engine_meta') IS NULL CREATE TABLE dbo.engine_meta (
     k nvarchar(64) NOT NULL PRIMARY KEY, v nvarchar(max) NULL, updated_at datetime2 NOT NULL DEFAULT SYSUTCDATETIME())`,
  `IF OBJECT_ID('dbo.engine_account') IS NULL CREATE TABLE dbo.engine_account (
     account_id      nvarchar(40)  NOT NULL PRIMARY KEY,
     salt            varchar(64)   NULL,
     digest          varchar(256)  NULL,
     created_ms      bigint        NOT NULL,
     revision        int           NOT NULL,
     legacy_user_no  varchar(20)   NULL,
     extras_json     nvarchar(max) NULL,
     updated_at      datetime2     NOT NULL DEFAULT SYSUTCDATETIME())`,
  `IF OBJECT_ID('dbo.engine_character') IS NULL CREATE TABLE dbo.engine_character (
     character_id        nvarchar(100) NOT NULL PRIMARY KEY,
     account_id          nvarchar(40)  NOT NULL,
     slot                int           NOT NULL,
     name                nvarchar(64)  NOT NULL,
     class_index         int           NOT NULL,
     level               int           NOT NULL,
     exp                 bigint        NULL,
     dil                 bigint        NULL,
     map_index           int           NULL,
     pos_x               float         NULL,
     pos_z               float         NULL,
     last_played_ms      bigint        NULL,
     legacy_character_no varchar(18)   NULL,
     profile_json        nvarchar(max) NOT NULL,
     updated_at          datetime2     NOT NULL DEFAULT SYSUTCDATETIME(),
     CONSTRAINT FK_engine_character_account FOREIGN KEY (account_id) REFERENCES dbo.engine_account(account_id))`,
  `IF NOT EXISTS (SELECT 1 FROM sys.indexes WHERE name='IX_engine_character_account' AND object_id=OBJECT_ID('dbo.engine_character'))
     CREATE INDEX IX_engine_character_account ON dbo.engine_character(account_id, slot)`,
  `IF NOT EXISTS (SELECT 1 FROM sys.indexes WHERE name='IX_engine_character_name' AND object_id=OBJECT_ID('dbo.engine_character'))
     CREATE INDEX IX_engine_character_name ON dbo.engine_character(name)`,
  `IF NOT EXISTS (SELECT 1 FROM sys.indexes WHERE name='IX_engine_character_legacy' AND object_id=OBJECT_ID('dbo.engine_character'))
     CREATE INDEX IX_engine_character_legacy ON dbo.engine_character(legacy_character_no) WHERE legacy_character_no IS NOT NULL`,
  `IF OBJECT_ID('dbo.engine_character_extra') IS NULL CREATE TABLE dbo.engine_character_extra (
     character_id nvarchar(100) NOT NULL PRIMARY KEY,
     inventory_json nvarchar(max) NOT NULL,
     storage_json nvarchar(max) NOT NULL,
     equipment_json nvarchar(max) NOT NULL,
     updated_at datetime2 NOT NULL DEFAULT SYSUTCDATETIME(),
     CONSTRAINT FK_engine_character_extra_character FOREIGN KEY (character_id) REFERENCES dbo.engine_character(character_id))`,
  `IF OBJECT_ID('dbo.engine_cash') IS NULL CREATE TABLE dbo.engine_cash (
     character_id nvarchar(100) NOT NULL PRIMARY KEY,
     dkc bigint NOT NULL DEFAULT 0,
     vip_points bigint NOT NULL DEFAULT 0,
     cash_inventory_json nvarchar(max) NOT NULL,
     updated_at datetime2 NOT NULL DEFAULT SYSUTCDATETIME(),
     CONSTRAINT FK_engine_cash_character FOREIGN KEY (character_id) REFERENCES dbo.engine_character(character_id))`,
  `IF OBJECT_ID('dbo.engine_social') IS NULL CREATE TABLE dbo.engine_social (
     id int NOT NULL PRIMARY KEY CHECK (id = 1), json nvarchar(max) NOT NULL, updated_at datetime2 NOT NULL DEFAULT SYSUTCDATETIME())`,
  `IF OBJECT_ID('dbo.engine_sync_log') IS NULL CREATE TABLE dbo.engine_sync_log (
     id bigint IDENTITY(1,1) PRIMARY KEY, at datetime2 NOT NULL DEFAULT SYSUTCDATETIME(), kind varchar(24) NOT NULL, detail nvarchar(400) NULL)`,
];

/** Create the database (when missing) and every table. Safe to run repeatedly. */
export async function ensureEngineSchema({ sql, database = DEFAULT_ENGINE_DB, log = () => {} } = {}) {
  assertIdentifier(database);
  const own = !sql;
  const client = sql || createSqlClient({ database: 'master', log });
  try {
    const exists = (await client.query('SELECT COUNT(*) AS n FROM sys.databases WHERE name = @n', { n: database }, { db: 'master' }))[0].n > 0;
    if (!exists) { await client.run(`CREATE DATABASE [${database}]`, {}, { db: 'master', timeout: 120 }); log(`[sql] created database ${database}`); }
    for (const stmt of SCHEMA_STATEMENTS) await client.run(stmt, {}, { db: database });
    // Additive projections for existing SQL worlds. The complete profile remains authoritative;
    // only missing rows are backfilled, so setup never overwrites a player's saved balance.
    await client.run(`INSERT dbo.engine_character_extra (character_id, inventory_json, storage_json, equipment_json)
      SELECT c.character_id, COALESCE(JSON_QUERY(c.profile_json,'$.inventory'),N'[]'),
        COALESCE(JSON_QUERY(c.profile_json,'$.storage'),N'[]'), COALESCE(JSON_QUERY(c.profile_json,'$.equip'),N'{}')
      FROM dbo.engine_character c WHERE NOT EXISTS
        (SELECT 1 FROM dbo.engine_character_extra x WHERE x.character_id=c.character_id)`, {}, { db: database });
    await client.run(`INSERT dbo.engine_cash (character_id, dkc, vip_points, cash_inventory_json)
      SELECT c.character_id, COALESCE(TRY_CONVERT(bigint,JSON_VALUE(c.profile_json,'$.dkc')),0),
        COALESCE(TRY_CONVERT(bigint,JSON_VALUE(c.profile_json,'$.vipPoints')),0),
        COALESCE(JSON_QUERY(c.profile_json,'$.cashInv'),N'[]')
      FROM dbo.engine_character c WHERE NOT EXISTS
        (SELECT 1 FROM dbo.engine_cash x WHERE x.character_id=c.character_id)`, {}, { db: database });
    await client.run(
      `MERGE dbo.engine_meta AS t USING (SELECT 'schema_version' AS k) s ON t.k = s.k
       WHEN MATCHED THEN UPDATE SET v = @v, updated_at = SYSUTCDATETIME() WHEN NOT MATCHED THEN INSERT (k, v) VALUES ('schema_version', @v);`,
      { v: String(SCHEMA_VERSION) }, { db: database });
    return { database, created: !exists };
  } finally { if (own) await client.close(); }
}
