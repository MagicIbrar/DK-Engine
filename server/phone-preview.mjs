// Explicit private LAN preview: shared read-only engine/assets, independent mutable stores.
import fs from 'node:fs';
import path from 'node:path';
export function phonePreview(engine,env=process.env){
 if(env.DEKARON_PHONE_PREVIEW!=='1')return null;
 const name=env.DEKARON_PHONE_PREVIEW_ID;
 if(!/^phone-[a-z0-9-]{8,60}$/.test(name||''))throw Error('A distinct private phone preview ID is required.');
 const root=path.join(engine,'runtime',name);
 for(let at=engine;at;){if(fs.lstatSync(at).isSymbolicLink())throw Error('Phone preview requires ordinary paths.');const parent=path.dirname(at);if(parent===at)break;at=parent;}
 for(const at of [path.join(engine,'runtime'),root]){if(fs.existsSync(at)&&fs.lstatSync(at).isSymbolicLink())throw Error('Phone preview directory cannot be linked.');fs.mkdirSync(at,{recursive:true});}
 const account=path.join(root,'accounts.json');
 for(const key of Object.keys(env))if(key.startsWith('DEKARON_')&&!['DEKARON_PHONE_PREVIEW','DEKARON_PHONE_PREVIEW_ID'].includes(key))delete env[key];
 Object.assign(env,{PORT:'7778',DEKARON_HOST:'0.0.0.0',DEKARON_ACCOUNT_STORE:account,DEKARON_PERMISSION_STORE:account+'.permissions.json',DEKARON_CUSTOM_ITEM_STORE:account+'.items.json',DEKARON_LOCAL_DEMO:'0',DEKARON_SECURE_COOKIES:'0',DEKARON_NPC_INTEREST:'1',DEKARON_SERVER_NAME:'Private Phone Preview'});
 const settings=account+'.settings.json';
 if(!fs.existsSync(settings))fs.writeFileSync(settings,JSON.stringify({version:1,name:'Private Phone Preview',npcPlayers:true}),{flag:'wx',mode:0o600});
 return {root,roster:path.join(root,'npc-roster.json'),capacity:path.join(root,'capacity.json'),launcher:path.join(root,'launcher-control.json')};
}
