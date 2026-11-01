-- L17 0001: migration tracking for the engine database (DEKARON_ENGINE). REVIEW ONLY - not applied anywhere.
-- Additive, idempotent; never touches legacy Global databases (account, CHARACTER, ...).
-- Records the current hand-rolled schema (server/sql/engine-schema.mjs SCHEMA_VERSION=2) as baseline 0000.
IF OBJECT_ID('dbo.engine_schema_migration') IS NULL
  CREATE TABLE dbo.engine_schema_migration (
    id          int           NOT NULL PRIMARY KEY,         -- file number (0001 -> 1)
    name        nvarchar(128) NOT NULL,
    sha256      char(64)      NOT NULL,                     -- checksum of the script text as applied
    applied_at  datetime2     NOT NULL DEFAULT SYSUTCDATETIME(),
    applied_by  nvarchar(128) NOT NULL DEFAULT SUSER_SNAME());
GO
IF NOT EXISTS (SELECT 1 FROM dbo.engine_schema_migration WHERE id = 0)
  INSERT dbo.engine_schema_migration (id, name, sha256)
  SELECT 0, N'baseline engine-schema.mjs v' + COALESCE((SELECT v FROM dbo.engine_meta WHERE k = 'schema_version'), N'?'), REPLICATE('0', 64);
GO
