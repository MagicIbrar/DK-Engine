import fs from 'node:fs/promises';
import nativeFs from 'node:fs';
import path from 'node:path';
import{fileURLToPath}from'node:url';
import{clientSource}from'../server/client-source.mjs';
import{parseImageTable}from'../src/ui/atlas.js';
import{decodeImage}from'../src/formats/image.js';
import{decodeToRGBA}from'../src/formats/dds.js';
import{encodePNG}from'./png.mjs';

/** Dedicated installs may junction prepared Global under engine (Franky scrub). Logical path stays inside the install. */
function dedicatedMount(engine){
  const cfgPath=path.join(engine,'dedicated-source.json');
  if(!nativeFs.existsSync(cfgPath))return null;
  let config;try{config=JSON.parse(nativeFs.readFileSync(cfgPath,'utf8'));}catch{return null;}
  if(config.version!==1||typeof config.sourceEngine!=='string'||!config.sourceEngine)return null;
  const mount=path.resolve(engine,config.sourceEngine);
  if(mount===engine||!mount.startsWith(engine+path.sep))return null;
  return mount;
}
function logicalDataRoot(engine,mount){
  if(!mount)return null;
  const curPath=path.join(mount,'.client-cache','current.json');
  if(!nativeFs.existsSync(curPath))return null;
  let cur;try{cur=JSON.parse(nativeFs.readFileSync(curPath,'utf8'));}catch{return null;}
  if(typeof cur.generation!=='string'||!/^\.client-cache\/generations\/[a-zA-Z0-9_-]+$/.test(cur.generation))return null;
  return path.resolve(mount,cur.generation,'data');
}

export async function nativePreloadArt(engine){
 engine=path.resolve(engine);
 const mount=dedicatedMount(engine);
 // Prefer the logical dedicated data root so containment matches Command Center play.mjs (junction realpath may leave the install).
 let root=logicalDataRoot(engine,mount);
 if(!root){
  const active=clientSource(engine);
  root=path.resolve(active.dataRoot);
 }
 if(!root.startsWith(engine+path.sep))throw Error('Native loading art requires installed assets.');
 async function read(key){
  const file=path.resolve(root,key);
  if(!file.startsWith(root+path.sep))throw Error('Loading artwork escaped installed data.');
  let p=file;
  while(p!==engine){
   const st=await fs.lstat(p);
   if(st.isSymbolicLink()){
    // Allow only the configured dedicated source mount under this engine.
    if(!(mount&&path.resolve(p)===mount))throw Error('Linked loading artwork refused.');
   }
   const parent=path.dirname(p);
   if(parent===p)break;
   p=parent;
  }
  return fs.readFile(file);
 }
 const rows=new Map();for(const file of ['script/ui/com/preloading.txt','script/ui/com/imagetable.txt'])for(const[k,v]of parseImageTable(new TextDecoder('euc-kr').decode(await read(file))))rows.set(k,v);
 const row=rows.get('preloading#1');if(!row||![row.x,row.y,row.w,row.h].every(Number.isInteger)||row.w<1||row.h<1||row.w>4096||row.h>4096)throw Error('Native preload sprite missing.');
 const decoded=decodeImage(await read(row.key)),image=decoded.dds?decodeToRGBA(decoded.dds):decoded;if(row.x<0||row.y<0||row.x+row.w>image.width||row.y+row.h>image.height)throw Error('Native preload crop exceeds its texture.');const rgba=new Uint8Array(row.w*row.h*4);for(let y=0;y<row.h;y++)rgba.set(image.data.subarray(((y+row.y)*image.width+row.x)*4,((y+row.y)*image.width+row.x+row.w)*4),y*row.w*4);return encodePNG(row.w,row.h,rgba);
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){try{const engine=process.argv[2],out=process.argv[3];if(!engine||!out)throw Error('Loading artwork arguments missing.');const png=await nativePreloadArt(engine);await fs.mkdir(path.dirname(out),{recursive:true});await fs.writeFile(out,png);const stable=path.join(engine,'run','native-loading-art.png');try{await fs.mkdir(path.dirname(stable),{recursive:true});await fs.writeFile(stable,png);}catch{/* recoverable cache best-effort */}}catch(e){console.error(e.message);process.exitCode=1;}}
