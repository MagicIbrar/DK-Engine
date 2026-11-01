// One-command setup/check for this copy's isolated SQL Server world.
import fs from 'node:fs/promises';
import {constants} from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {createSqlClient} from '../server/sql/sql-client.mjs';
import {ensureEngineSchema} from '../server/sql/engine-schema.mjs';
import {reserveStoppedWorld} from './dedicated-setup-guard.mjs';

const ROOT=fileURLToPath(new URL('../',import.meta.url));
const mode=process.argv[2];
if(!['--check','--setup'].includes(mode))throw new Error('Use --check or --setup.');
const instance=process.env.DEKARON_SQL_INSTANCE||'.\\SQLEXPRESS';
const database=process.env.DEKARON_DEDICATED_SQL_DB||'DEKARON_DEDICATED';
if(!['DEKARON_DEDICATED','DEKARON_DEDICATED_HOSTED'].includes(database))throw Error('Choose the dedicated Local world or Hosted world database.');
const hosted=database==='DEKARON_DEDICATED_HOSTED';
const sql=createSqlClient({instance,database:'master'});
let guard;
try{
  if(mode==='--setup')guard=await reserveStoppedWorld({port:hosted?7778:7996});
  const edition=await sql.query('SELECT SERVERPROPERTY(\'Edition\') AS edition, SERVERPROPERTY(\'ProductVersion\') AS version',{}, {db:'master'});
  const db=await sql.query('SELECT name FROM sys.databases WHERE name=@name',{name:database},{db:'master'});
  if(mode==='--setup'){
    // Also protect against another dedicated host using this SQL world.
    if(db.length){
      const rows=await sql.query("DECLARE @result int; EXEC @result=sp_getapplock @Resource=N'DekaronDedicatedWorld', @LockMode='Exclusive', @LockOwner='Session', @LockTimeout=0; SELECT @result AS result",{}, {db:database});
      const result=rows[0]?.result;
      if(result===null||result===undefined||!Number.isInteger(Number(result))||Number(result)<0)throw new Error('Stop the SQL world before changing its setup.');
    }
    const source=path.join(ROOT,'server','accounts',hosted?'friends-accounts.json':'data.json');
    const backup=path.join(ROOT,'run',`sql-setup-account-backup-${new Date().toISOString().replace(/[:.]/g,'-')}.json`);
    await fs.mkdir(path.dirname(backup),{recursive:true});
    try{await fs.copyFile(source,backup,constants.COPYFILE_EXCL);}catch(error){if(error.code!=='ENOENT')throw error;}
    // the save journal next to it (accounts/entity-journal.mjs): after an unclean stop it holds saves the file does not have yet
    try{await fs.copyFile(source+'.journal',backup+'.journal',constants.COPYFILE_EXCL);}catch(error){if(error.code!=='ENOENT')throw error;}
    await ensureEngineSchema({sql,database});
  }
  const current=await sql.query('SELECT name FROM sys.databases WHERE name=@name',{name:database},{db:'master'});
  let accounts=null;
  if(current.length){const rows=await sql.query('SELECT COUNT(*) AS n FROM dbo.engine_account',{}, {db:database});accounts=Number(rows[0]?.n||0);}
  console.log(JSON.stringify({ok:true,instance,database,installed:!!current.length,accounts,edition:String(edition[0]?.edition||''),version:String(edition[0]?.version||'')}));
}finally{try{await sql.close();}finally{await guard?.close();}}
