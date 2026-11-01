import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath} from 'node:url';
import {inspectGLB,GLB_LIMITS} from '../src/systems/itembuilder/glb-import.js';
const defaultRoot=fileURLToPath(new URL('./custom-assets/',import.meta.url));
async function ordinary(target){
 const absolute=path.resolve(target),parsed=path.parse(absolute);let current=parsed.root;
 for(const part of path.relative(parsed.root,absolute).split(path.sep).filter(Boolean)){current=path.join(current,part);let stat;try{stat=await fs.lstat(current);}catch(error){if(error.code==='ENOENT')continue;throw error;}if(stat.isSymbolicLink()||(!stat.isDirectory()&&(!stat.isFile()||stat.nlink!==1)))throw Error('Custom asset storage must use ordinary files/directories.');const actual=await fs.realpath(current);if(path.resolve(actual).toLowerCase()!==path.resolve(current).toLowerCase())throw Error('Custom asset storage cannot traverse links.');}
 return absolute;
}
export function createCustomAssets({root=defaultRoot,maxBytes=512*1024*1024}={}){
 let queue=Promise.resolve();
 const filename=hash=>{if(!/^[a-f0-9]{64}$/.test(hash))throw Error('Invalid custom asset digest.');return path.join(path.resolve(root),`${hash}.glb`);};
 return{
  async put(bytes){
   const buffer=bytes.buffer.slice(bytes.byteOffset,bytes.byteOffset+bytes.byteLength),report=inspectGLB(buffer);
   if(report.skins)throw Error('Rigged armor import requires verified native skeleton/bind-pose mapping. Import a rigid weapon or static item instead.');
   if(report.animations||report.json.meshes?.some(mesh=>mesh.primitives?.some(primitive=>primitive.targets?.length)))throw Error('Animated/morphing GLB equipment needs a runtime animation adapter. Export a rigid static weapon.');
   const hash=crypto.createHash('sha256').update(bytes).digest('hex');
   const task=queue.catch(()=>{}).then(async()=>{
    await ordinary(root);await fs.mkdir(root,{recursive:true});await ordinary(root);
    const target=await ordinary(filename(hash));
    try{const existing=await fs.readFile(target);if(crypto.createHash('sha256').update(existing).digest('hex')!==hash)throw Error('Stored custom asset digest mismatch.');return;}catch(error){if(error.code!=='ENOENT')throw error;}
    let total=0;for(const entry of await fs.readdir(root,{withFileTypes:true})){if(!entry.isFile()||!/^[a-f0-9]{64}\.glb$/.test(entry.name))throw Error('Unexpected entry in custom asset storage.');const file=await ordinary(path.join(root,entry.name));total+=(await fs.stat(file)).size;}
    if(total+bytes.length>maxBytes)throw Error('Custom asset library exceeds512MiB; remove unused assets through server maintenance first.');
    const temp=path.join(root,`${hash}.${crypto.randomUUID()}.tmp`);let handle;
    try{handle=await fs.open(temp,'wx',0o600);await handle.writeFile(bytes);await handle.sync();await handle.close();handle=null;await ordinary(root);await fs.rename(temp,target);}finally{await handle?.close();await fs.unlink(temp).catch(error=>{if(error.code!=='ENOENT')throw error;});}
   });queue=task;await task;
   return{mesh:`custom/glb/${hash}.glb`,digest:hash,bytes:bytes.length,triangles:report.triangles,materials:report.materials,images:report.images,warnings:report.warnings};
  },
  async get(hash){const target=await ordinary(filename(hash));const bytes=await fs.readFile(target);if(bytes.length>GLB_LIMITS.bytes||crypto.createHash('sha256').update(bytes).digest('hex')!==hash)throw Error('Stored custom asset integrity check failed.');return bytes;},
 };
}
