// Local experiment: all mutable state belongs to this engine. Existing assets are read only.
import fs from 'node:fs';
import path from 'node:path';
export function sandboxConfig(engine) {
 const file=path.join(engine,'server/npc-sandbox.json');
 if(!fs.existsSync(file))return null;
 const c=JSON.parse(fs.readFileSync(file,'utf8'));
 if(c.nativeCapacity!=null&&c.nativeCapacity!==1250)throw Error('Invalid sandbox native capacity');
 if(c.interestManaged!=null&&typeof c.interestManaged!=='boolean'||c.interestManaged===true&&c.nativeCapacity!=null)throw Error('Invalid sandbox interest-managed bot setting');
 const canonical=p=>fs.realpathSync.native(p).toLowerCase();
 const host=c.host??'127.0.0.1',privateHost=/^(?:127\.|10\.|192\.168\.|172\.(?:1[6-9]|2\d|3[01])\.)/.test(host)&&host.split('.').length===4&&host.split('.').every(n=>/^\d+$/.test(n)&&Number(n)<=255);
 if(c.version!==1||canonical(c.engine)!==canonical(engine)||!path.isAbsolute(c.readOnlyData)||!Number.isInteger(c.port)||c.port<1024||c.port>65535||!(privateHost||host==='0.0.0.0'))throw Error('Invalid copied-client sandbox configuration');
 for(const p of [engine,c.readOnlyData])if(fs.lstatSync(p).isSymbolicLink())throw Error('Sandbox paths must be ordinary directories');
 return c;
}
export function applySandboxEnvironment(engine) {
 const c=sandboxConfig(engine);if(!c)return null;
 if(process.env.PORT&&Number(process.env.PORT)!==c.port)throw Error(`Copied client only uses its configured port ${c.port}`);
 const accounts=path.join(engine,'server/accounts/data.json');
 const host=c.host??'127.0.0.1';
 Object.assign(process.env,{PORT:String(c.port),DEKARON_HOST:host,DEKARON_DATA:c.readOnlyData,DEKARON_ACCOUNT_STORE:accounts,DEKARON_PERMISSION_STORE:accounts+'.permissions.json',DEKARON_LOCAL_DEMO:host.startsWith('127.')?'1':'0',DEKARON_SECURE_COOKIES:'0'});
 if(c.nativeCapacity!=null)process.env.DEKARON_NPC_NATIVE_CAPACITY=String(c.nativeCapacity);
 // Interest-managed bots: only maps a human occupies hold actors; everything else is simulated presence.
 if(c.interestManaged===true){process.env.DEKARON_NPC_INTEREST='1';delete process.env.DEKARON_NPC_NATIVE_CAPACITY;}else delete process.env.DEKARON_NPC_INTEREST;
 for(const k of ['DEKARON_GAMEDATA','DEKARON_CUSTOM_ITEM_STORE','DEKARON_RELAY_SECRET','DEKARON_RELAY_ORIGIN','DEKARON_FRIENDS_GATE','DEKARON_SERVER_MODE'])delete process.env[k];
 return c;
}
