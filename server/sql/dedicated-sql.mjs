// Opt-in SQL Server adapter for the dedicated host. One host must own a given
// isolated account database at a time. No original-server database is required.
import {createSqlClient} from './sql-client.mjs';
import {assertIdentifier,ensureEngineSchema} from './engine-schema.mjs';
import {createEngineSqlStore} from './engine-sql-store.mjs';

export async function createDedicatedSqlServices({env=process.env,log=console.log}={}){
  const database=env.DEKARON_DEDICATED_SQL_DB;
  if(!database)throw new Error('Set DEKARON_DEDICATED_SQL_DB before enabling SQL Server storage.');
  assertIdentifier(database);
  if(database.toUpperCase()==='DEKARON_ENGINE')
    throw new Error("Use this engine's isolated dedicated database; existing DEKARON_ENGINE is not a supported target.");
  const sql=createSqlClient({instance:env.DEKARON_SQL_INSTANCE||'.\\SQLEXPRESS',database,log});
  try{
    await sql.ping();
    if(env.DEKARON_DEDICATED_SQL_CREATE==='1')await ensureEngineSchema({sql,database,log});
    else{
      const rows=await sql.query("SELECT COUNT(*) AS n FROM sys.tables WHERE name IN ('engine_account','engine_character','engine_social')",{}, {db:database});
      if(Number(rows[0]?.n)!==3)throw new Error('SQL engine schema is missing; initialize an isolated database explicitly.');
    }
    const lock=await sql.query("DECLARE @result int; EXEC @result=sp_getapplock @Resource=N'DekaronDedicatedWorld', @LockMode='Exclusive', @LockOwner='Session', @LockTimeout=0; SELECT @result AS result",{}, {db:database});
    if(lock[0]?.result==null||!Number.isInteger(Number(lock[0]?.result))||Number(lock[0]?.result)<0)
      throw new Error('Another dedicated host already owns this SQL world, or its SQL lock could not be confirmed.');
    const store=createEngineSqlStore({sql,database,strict:true,log});
    return {sql,store,database,async close(){try{await store.flush();}finally{await sql.close();}}};
  }catch(error){await sql.close();throw error;}
}
