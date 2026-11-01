-- L17 0002: SQL home for world state that is persisted today as JSON files (see bench/SQL-INVENTORY.md).
-- REVIEW ONLY - not applied anywhere. Generic keyed document table: scope = module, id = record key.
-- Columns stay JSON on purpose: no Global schema mapping is invented (awaiting the supplied Global schema script).
IF OBJECT_ID('dbo.engine_world_state') IS NULL
  CREATE TABLE dbo.engine_world_state (
    scope      varchar(48)   NOT NULL,
    id         nvarchar(200) NOT NULL,
    json       nvarchar(max) NOT NULL CHECK (ISJSON(json) = 1),
    revision   int           NOT NULL DEFAULT 1,
    updated_at datetime2     NOT NULL DEFAULT SYSUTCDATETIME(),
    CONSTRAINT PK_engine_world_state PRIMARY KEY (scope, id));
GO
