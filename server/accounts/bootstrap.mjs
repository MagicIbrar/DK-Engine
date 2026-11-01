import fs from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { randomBytes, scrypt as rawScrypt, timingSafeEqual } from 'node:crypto';
import { promisify } from 'node:util';
import { permissionFile, setAccountRole, accountPermissions } from './permissions.mjs';

const scrypt=promisify(rawScrypt);
const defaultFile=fileURLToPath(new URL('./data.json',import.meta.url));
export function isLoopbackHost(host){return host==='localhost'||host==='::1'||/^127\.(?:\d{1,3}\.){2}\d{1,3}$/.test(host)&&host.split('.').every(x=>Number(x)<=255);}
async function readStore(file){
  try {const stat=await fs.lstat(file);if(!stat.isFile()||stat.isSymbolicLink()||stat.nlink>1)throw new Error('Account store must be a regular, unlinked file.');return JSON.parse(await fs.readFile(file,'utf8'));}
  catch(error){if(error.code==='ENOENT')return null;throw error;}
}
async function usesDefault(user){if(!user?.salt||!user?.digest)return false;const digest=Buffer.from(user.digest,'hex'),actual=await scrypt('password',user.salt,64);return digest.length===actual.length&&timingSafeEqual(digest,actual);}

/** Fresh local installs reserve a private admin with a discarded random password. Existing accounts are never reset. */
export async function initializeLocalDemo({file=process.env.DEKARON_ACCOUNT_STORE||defaultFile,permissionsFile=permissionFile(file),host=process.env.DEKARON_HOST||'127.0.0.1',enabled=process.env.DEKARON_LOCAL_DEMO!=='0'}={}){
  const original=await readStore(file);
  if(await usesDefault(original?.users?.admin)&&!isLoopbackHost(host))throw new Error('Default admin/password credentials are local only. Change the demo password before binding a public host.');
  if(!enabled||original&&Object.keys(original.users||{}).length)return {localDemo:false};
  if(!isLoopbackHost(host))throw new Error('Fresh demo setup with admin/password requires a loopback host. Set DEKARON_LOCAL_DEMO=0 for a public server.');
  // A marker survives account deletion: restarting cannot silently reset the demo.
  if(original?.localDemo)return {localDemo:false};
  if(original&&(original.version!==1||!original.users||!original.sessions))throw new Error('Invalid empty account store; demo initialization refused.');
  // Refuse unsafe or malformed grants before creating any account.
  await accountPermissions(permissionsFile,'admin');
  try {const st=await fs.lstat(permissionsFile);if(!st.isFile()||st.isSymbolicLink()||st.nlink>1)throw new Error('Permissions store must be a regular, unlinked file.');const grants=JSON.parse(await fs.readFile(permissionsFile,'utf8'));if(grants.version!==1||!grants.accounts)throw new Error('Invalid permissions store.');}catch(error){if(error.code!=='ENOENT')throw error;}
  const salt=randomBytes(16).toString('hex'),digest=(await scrypt(randomBytes(48).toString('hex'),salt,64)).toString('hex');
  const state={version:1,users:{},sessions:{},...original,localDemo:{id:'admin',created:Date.now()}};
  state.users.admin={id:'admin',salt,digest,created:Date.now(),revision:0,characters:[]};
  await fs.mkdir(path.dirname(file),{recursive:true});
  if(original){
    // Recheck immediately before replacement; never overwrite a newly registered user.
    if(JSON.stringify(await readStore(file))!==JSON.stringify(original))throw new Error('Account store changed during demo setup. Retry startup.');
    const temp=`${file}.demo-${randomBytes(8).toString('hex')}.tmp`;
    try{await fs.writeFile(temp,JSON.stringify(state),{flag:'wx',mode:0o600});await fs.rename(temp,file);}finally{await fs.rm(temp,{force:true});}
  }else await fs.writeFile(file,JSON.stringify(state),{flag:'wx',mode:0o600});
  try{await setAccountRole({accountStore:file,file:permissionsFile,account:'admin',role:'gm'});}
  catch(error){
    // Do not leave a half-created demo if its host-managed grant could not be saved.
    if(JSON.stringify(await readStore(file))===JSON.stringify(state)){
      if(!original)await fs.unlink(file);
      else {const rollback=`${file}.rollback-${randomBytes(8).toString('hex')}.tmp`;try{await fs.writeFile(rollback,JSON.stringify(original),{flag:'wx',mode:0o600});await fs.rename(rollback,file);}finally{await fs.rm(rollback,{force:true});}}
    }
    throw error;
  }
  return {localDemo:true,id:'admin'};
}

export async function localDemoInfo({file=process.env.DEKARON_ACCOUNT_STORE||defaultFile,host=process.env.DEKARON_HOST||'127.0.0.1'}={}){
  if(!isLoopbackHost(host))return {localDemo:false};
  const state=await readStore(file);
  return state?.localDemo?.id==='admin'&&await usesDefault(state.users?.admin)?{localDemo:true,id:'admin'}:{localDemo:false};
}
