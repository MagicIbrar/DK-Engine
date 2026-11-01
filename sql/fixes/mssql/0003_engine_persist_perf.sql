-- PERSIST-PERF (review-only; tested on a throwaway SQL Server 2022 container). Run inside the engine's isolated world DB.
-- Keeps saves durable: commits must harden the log before the engine acknowledges a save (strict store).
-- No new index is needed: the batched writer (server/sql/engine-sql-store.mjs BATCH_SQL) touches rows by primary key and
-- finds an account's characters through IX_engine_character_account(account_id, slot).
DECLARE @db sysname = DB_NAME(), @s nvarchar(400);
IF (SELECT delayed_durability FROM sys.databases WHERE name = @db) <> 0
BEGIN SET @s = N'ALTER DATABASE ' + QUOTENAME(@db) + N' SET DELAYED_DURABILITY = DISABLED'; EXEC (@s); END
GO
