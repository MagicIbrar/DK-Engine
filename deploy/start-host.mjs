// Persistent single-world container entrypoint. Never package client files or bootstrap secrets.
import fs from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { spawn } from 'node:child_process';
import { configureFriendsHost, friendsHostStatus } from '../tools/configure-friends-host.mjs';
import { prepareClient } from '../tools/prepare-client.mjs';
import { isPublicConnectorAsset } from '../server/public-assets.mjs';
import { readWorldRates } from '../server/world/rates.mjs';
export const HOST_TOOLS=["build-boxes.mjs","build-channels.mjs","build-characters.mjs","build-dungeon-uifx.mjs","build-dungeons.mjs","build-events-ui.mjs","build-events.mjs","build-frontend.mjs","build-gmcommands.mjs","build-item-styles.mjs","build-items.mjs","build-life.mjs","build-monsters.mjs","build-mounts.mjs","build-quests.mjs","build-shops.mjs","build-skills-runtime.mjs","build-skills.mjs","build-sound.mjs","client-pack.mjs","configure-friends-host.mjs","lib/siege-renew-deploy-mask.mjs","lib/siege-sentry-results.mjs","png.mjs","prepare-client.mjs","transform-compatibility.mjs"];
export function assertPersistentHostStorage(env=process.env,platform=process.platform){if(env.DEKARON_DEDICATED_STORAGE==='sqlserver'&&platform!=='win32')throw Error('SQL Server storage currently requires the Windows PowerShell SqlClient bridge. Linux containers/VPS hosts support local JSON or SQLite storage; Windows hosts may use SQL Server.');}
const rateVariables=['DEKARON_EXP_RATE','DEKARON_DIL_RATE','DEKARON_DROP_RATE'];
// Optional provider fields can be blank after bootstrap; the persisted rates remain the fallback.
function deploymentRates(env){return Object.fromEntries(rateVariables.filter(key=>env[key]!==undefined&&String(env[key]).trim()!=='').map(key=>[key,env[key]]));}

async function unlinked(target) {
  const absolute=path.resolve(target); let current=path.parse(absolute).root;
  for(const part of path.relative(current,absolute).split(path.sep).filter(Boolean)) {
    current=path.join(current,part);
    const stat=await fs.lstat(current).catch(error=>{if(error.code==='ENOENT')return null;throw error;});
    if(stat&&(stat.isSymbolicLink()||stat.isFile()&&stat.nlink>1))throw new Error('Host storage must not contain links.');
  }
}
export async function stageHost(source, state) {
  await unlinked(source);source=await fs.realpath(source);state=path.resolve(state);
  if(state===source||state.startsWith(source+path.sep)||source.startsWith(state+path.sep))throw new Error('Host storage must be separate from the image.');
  await unlinked(state);await fs.mkdir(state,{recursive:true});
  const engine=path.join(state,'engine');
  await unlinked(engine);
  const folders=new Set(['src','server','site','tools','vendor','node_modules','client-assets','deploy']);
  const topFiles=new Set(['package.json','package-lock.json','index.html','join.html','launch.html','server.mjs','THIRD_PARTY_NOTICES.md']);
  // dekaron-online-logo-v1.png is allowed here but not present in this build (no copy exists in 4.2.0 or 4.1.x); the entry is inert.
  const assets=new Set(['dekaron-online-logo-v1.png','dekaron-online-emblem-v1.png','launcher-background-v1.png','dekaron-online.ico','server-logo-v1.png']);
  const allowed=(relative,directory)=>{
    const parts=relative.split(path.sep),top=parts[0],name=parts.at(-1);
    if(top==='web')return directory?relative==='web'||relative===path.join('web','public'):isPublicConnectorAsset('/'+parts.join('/'));
    if(directory)return folders.has(top)&&!parts.some(p=>p.startsWith('.')&&top!=='node_modules');
    if(parts.length===1)return topFiles.has(name);
    if(top==='node_modules')return true;
    if(top==='server')return name.endsWith('.mjs')||relative===path.join('server','sql','sql-host.ps1');
    if(top==='tools')return HOST_TOOLS.includes(parts.slice(1).join('/'));
    if(top==='client-assets')return parts.length===2&&assets.has(name);
    if(top==='deploy')return relative===path.join('deploy','start-host.mjs');
    if(top==='vendor')return name.endsWith('.js')||name==='LICENSE';
    return ['src','site'].includes(top)&&/\.(?:js|mjs|css|html)$/.test(name);
  };
  // Only image code is refreshed. Accounts, imports and custom state already in /state stay intact.
  async function copy(relative='') {
    for(const entry of await fs.readdir(path.join(source,relative),{withFileTypes:true})) {
      const name=path.join(relative,entry.name),target=path.join(engine,name);
      const included=allowed(name,entry.isDirectory())||(entry.isSymbolicLink()&&(allowed(name,true)||allowed(name,false)));
      if(!included)continue;
      if(entry.isSymbolicLink())throw new Error('Host image must not contain links.');
      if(!target.startsWith(engine+path.sep))throw new Error('Host path escaped its storage directory.');
      await unlinked(target);
      if(entry.isDirectory()){await fs.mkdir(target,{recursive:true});await copy(name);}
      else if(entry.isFile()){await unlinked(path.join(source,name));await fs.copyFile(path.join(source,name),target);}
    }
  }
  await fs.mkdir(engine,{recursive:true});await copy();return engine;
}
export async function configurePersistentHost(engine,env=process.env) {
  const stored=await friendsHostStatus(engine);
  if(stored.configured)return stored;
  const mode=env.DEKARON_HOST_MODE||'invite';
  if(!['invite','open'].includes(mode))throw new Error('DEKARON_HOST_MODE must be invite or open.');
  return configureFriendsHost(engine,{
    id:env.DEKARON_HOST_ACCOUNT,password:env.DEKARON_HOST_PASSWORD,confirmPassword:env.DEKARON_HOST_PASSWORD,
    mode,serverPassword:mode==='invite'?env.DEKARON_INVITE_PASSWORD:undefined,
    name:env.DEKARON_SERVER_NAME||'Dekaron Online',rates:readWorldRates(deploymentRates(env)),
  });
}
export function persistentHostEnvironment(config,env=process.env) {
  const childEnv={...env,PORT:env.PORT||'7778',DEKARON_HOST:'0.0.0.0',DEKARON_LOCAL_DEMO:'0',DEKARON_SERVER_MODE:'friends',DEKARON_FRIENDS_GATE:'1',DEKARON_ACCOUNT_STORE:config.accountStore};
  delete childEnv.DEKARON_HOST_PASSWORD;delete childEnv.DEKARON_INVITE_PASSWORD;
  for(const key of rateVariables)if(childEnv[key]!==undefined&&String(childEnv[key]).trim()==='')delete childEnv[key];
  return childEnv;
}
export async function startHost({source=fileURLToPath(new URL('../',import.meta.url)),state=process.env.DEKARON_STATE||'/state',env=process.env}={}) {
  assertPersistentHostStorage(env);
  const engine=await stageHost(source,state);
  const data=path.join(path.resolve(state),'data');
  const available=await fs.stat(data).catch(()=>null);
  if(!available?.isDirectory())throw new Error('Upload your own compatible Global data folder to the private volume at /state/data, then restart. No game data is bundled.');
  const config=await configurePersistentHost(engine,env);
  await prepareClient({engine,log:message=>console.log(message)});
  const childEnv=persistentHostEnvironment(config,env);
  const child=spawn(process.execPath,[path.join(engine,'server.mjs')],{cwd:engine,env:childEnv,stdio:'inherit'});
  const forward=signal=>child.kill(signal);
  process.on('SIGTERM',forward);process.on('SIGINT',forward);
  return await new Promise((resolve,reject)=>{child.on('error',reject);child.on('exit',code=>{process.removeListener('SIGTERM',forward);process.removeListener('SIGINT',forward);resolve(code??1);});});
}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{process.exitCode=await startHost();}catch(error){console.error(error.message);process.exitCode=1;}}
