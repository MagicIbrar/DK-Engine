import path from 'node:path';
import os from 'node:os';
import net from 'node:net';

// Keep the existing launcher's hosting contract; only defaults are dedicated.
export function configureDedicatedHost({engine,env=process.env,interfaces=os.networkInterfaces()}={}){
  const hosted=env.DEKARON_SERVER_MODE==='friends';
  const port=Number(env.PORT|| (hosted?7778:7996));
  if(!Number.isInteger(port)||port<1024||port>65535)throw Error('Choose a server port from 1024 to 65535.');
  const host=env.DEKARON_DEDICATED_BIND||env.DEKARON_HOST||'127.0.0.1';
  const assigned=new Set(['127.0.0.1',...Object.values(interfaces).flat().filter(row=>row?.family==='IPv4').map(row=>row.address)]);
  if(net.isIP(host)!==4||(!assigned.has(host)&&!(host==='0.0.0.0'&&hosted&&env.DEKARON_FRIENDS_GATE==='1')))
    throw Error('Choose a local IPv4 adapter, or enable LAN access through server hosting.');
  const accountRoot=path.resolve(engine,'server/accounts');
  const account=path.resolve(env.DEKARON_ACCOUNT_STORE||path.join(accountRoot,hosted?'friends-accounts.json':'data.json'));
  const relative=path.relative(accountRoot,account);
  if(!relative||relative==='..'||relative.startsWith('..'+path.sep)||path.isAbsolute(relative))throw Error('Dedicated account saves must stay inside this engine account folder.');
  env.PORT=String(port);env.DEKARON_HOST=host;env.DEKARON_ACCOUNT_STORE=account;
  env.DEKARON_PERMISSION_STORE=account+'.permissions.json';env.DEKARON_LOCAL_DEMO='0';
  if(!hosted&&!env.DEKARON_SERVER_NAME)env.DEKARON_SERVER_NAME='Dekaron Dedicated';
  if(env.DEKARON_DEDICATED_STORAGE==='sqlite')env.DEKARON_ACCOUNT_SQLITE=account+'.sqlite';
  else delete env.DEKARON_ACCOUNT_SQLITE;
  if(env.DEKARON_DEDICATED_STORAGE==='sqlserver'&&!env.DEKARON_DEDICATED_SQL_DB)
    env.DEKARON_DEDICATED_SQL_DB=hosted?'DEKARON_DEDICATED_HOSTED':'DEKARON_DEDICATED';
  return {port,host,hosted,account};
}
