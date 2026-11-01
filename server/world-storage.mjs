import path from 'node:path';
import fs from 'node:fs/promises';
import {randomBytes} from 'node:crypto';
import {readDurableAccountStore} from './accounts/entity-journal.mjs';

// Local and friends worlds may share engine code, but their authored libraries
// must follow the selected account store. Preserve the legacy local library.
export function worldStorageFiles({engine,accountStore,customItemsFile}={}){
 const root=path.resolve(engine),accounts=path.resolve(accountStore);
 const key=value=>process.platform==='win32'?value.toLowerCase():value;
 const defaultLocal=key(accounts)===key(path.join(root,'server','accounts','data.json'));
 return {
  customItemsFile:customItemsFile?path.resolve(customItemsFile):defaultLocal?path.join(root,'server','custom-items.json'):`${accounts}.items.json`,
  customAssetsRoot:`${accounts}.assets`,
  customMapsRoot:`${accounts}.maps`,
  originalEditRoot:`${accounts}.original-map-overlays`,
 };
}

async function ordinary(file){
 const absolute=path.resolve(file);let at=path.parse(absolute).root;
 for(const part of path.relative(at,absolute).split(path.sep).filter(Boolean)){
  at=path.join(at,part);const st=await fs.lstat(at).catch(error=>{if(error.code==='ENOENT')return null;throw error;});
  if(st&&(st.isSymbolicLink()||st.isFile()&&st.nlink!==1))throw Error('World library paths must not contain links.');
 }
}
async function read(file){
 await ordinary(file);
 try{return JSON.parse(await fs.readFile(file,'utf8'));}catch(error){if(error.code==='ENOENT')return null;throw error;}
}
const custom=index=>Number.isSafeInteger(index)&&index>900000000&&index<900999999;
async function migrationLock(lock,destination){
 const token=randomBytes(16).toString('hex');
 for(let attempt=0;attempt<40;attempt++){
  await ordinary(lock);
  let handle;
  try{
   handle=await fs.open(lock,'wx',0o600);
   await handle.writeFile(JSON.stringify({pid:process.pid,token}));await handle.sync();await handle.close();
   return async()=>{const current=await read(lock);if(current?.token===token)await fs.unlink(lock);};
  }catch(error){
   await handle?.close().catch(()=>{});
   if(error.code!=='EEXIST')throw error;
   if(await read(destination))return null;
   let owner;try{owner=await read(lock);}catch(error){if(!(error instanceof SyntaxError))throw error;}
   if(owner&&Number.isInteger(owner.pid)&&owner.pid>0&&typeof owner.token==='string'){
    let dead=false;try{process.kill(owner.pid,0);}catch(error){if(error.code==='ESRCH')dead=true;}
    if(dead){const current=await read(lock);if(current?.pid===owner.pid&&current?.token===owner.token)await fs.unlink(lock).catch(error=>{if(error.code!=='ENOENT')throw error;});continue;}
   }
   await new Promise(resolve=>setTimeout(resolve,50));
  }
 }
 throw Error('Another server is migrating this world library. Close that server and retry; original files are preserved.');
}

const migrations=new Map();
export function initializeWorldStorage(options){
 const target=path.resolve(worldStorageFiles(options).customItemsFile),key=process.platform==='win32'?target.toLowerCase():target;
 if(migrations.has(key))return migrations.get(key);
 const task=migrateWorldStorage(options);migrations.set(key,task);
 void task.finally(()=>{if(migrations.get(key)===task)migrations.delete(key);}).catch(()=>{});
 return task;
}
async function migrateWorldStorage(options){
 const files=worldStorageFiles(options),legacy=path.join(path.resolve(options.engine),'server','custom-items.json');
 if(path.resolve(files.customItemsFile)===legacy||options.customItemsFile)return files;
 // Existing non-local characters may hold definitions from the old shared
 // library. Retain only referenced records once; never import a local world's
 // entire private catalog into a newly configured server.
 if(await read(files.customItemsFile))return files;
 // the account store with its save journal applied (accounts/entity-journal.mjs): characters saved since the last checkpoint count too
 await ordinary(options.accountStore);
 const accounts=await readDurableAccountStore(options.accountStore).then(r=>r.state,error=>{if(error.code==='ENOENT')return null;throw error;});if(!accounts)return files;
 const used=new Set(),visit=value=>{if(!value||typeof value!=='object')return;if(custom(value.itemIndex))used.add(value.itemIndex);for(const child of Object.values(value))if(child&&typeof child==='object')visit(child);};
 for(const user of Object.values(accounts.users||{}))visit(user.characters);
 if(!used.size)return files;
 const previous=await read(legacy);if(!previous)return files;
 if(previous.format!=='dekaron-online-custom-items'||previous.version!==1||!Array.isArray(previous.items))throw Error('Legacy custom item library is invalid; original files preserved.');
 const records=new Map(previous.items.map(row=>[row.index,row]));
 for(const index of used){const row=records.get(index);for(const dependency of [row?.base,row?.look?.leftItem])if(custom(dependency)&&records.has(dependency))used.add(dependency);}
 const items=previous.items.filter(row=>used.has(row.index));if(!items.length)return files;
 const value={...previous,items};
 await ordinary(files.customItemsFile);await fs.mkdir(path.dirname(files.customItemsFile),{recursive:true});
 const lock=`${files.customItemsFile}.migration-lock`,release=await migrationLock(lock,files.customItemsFile),temporary=`${files.customItemsFile}.${randomBytes(8).toString('hex')}.tmp`;
 if(!release)return files;
 try{
  if(await read(files.customItemsFile))return files;
  const output=await fs.open(temporary,'wx',0o600);
  try{await output.writeFile(JSON.stringify(value));await output.sync();}finally{await output.close();}
  await ordinary(files.customItemsFile);await fs.rename(temporary,files.customItemsFile);
 }finally{await fs.rm(temporary,{force:true});await release();}
 return files;
}
