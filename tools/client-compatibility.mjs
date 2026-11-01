// Structural compatibility only. Builders and runtime tests remain responsible
// for references and behavior; recognizing a layout does not implement a feature.
import fs from 'node:fs/promises';
import path from 'node:path';
import {createReadStream} from 'node:fs';
import {createHash} from 'node:crypto';
import {decodeText,parseCSV} from '../src/formats/binreader.js';
import {MAP_VERSION_V1,MAP_VERSION_V2} from '../src/formats/map.js';
import {checkTables} from './lib/table-compat.mjs';
import {readFileSync,existsSync} from 'node:fs';
// TABLE-COMPAT (REVIEW REQUESTED): every-table check against the refreshed Global g2 manifest (tools/data/table-compat-g2.json).
// Only real parse blockers fail preparation (a binary whose size fits no known record stride; a skill .dat of unknown size).
// Missing tables, missing/added columns and unparsed .dat size drift are reported as warnings, because older clients
// legitimately lack newer tables/columns and the dedicated builders already decide what they need. DEKARON_TABLE_COMPAT=0 disables.
const G2_MANIFEST=new URL('./data/table-compat-g2.json',import.meta.url);
let g2Manifest;
export function defaultTableManifest(){if(g2Manifest===undefined)g2Manifest=existsSync(G2_MANIFEST)?JSON.parse(readFileSync(G2_MANIFEST,'utf8')):null;return g2Manifest;}
const TABLE_COMPAT_BLOCKING=new Set(['unsupported-binary-layout','unsupported-skill-dat-size']);

const TABLES = [
  ['share/maplist.csv',['Index','Name','MapFile']],
  ['share/creature/npc.csv',['Index','Name','Shape','JobCount','JobType1','JobIndex1']],
  ['share/item/itemweapon.csv',['ItemIndex','Name','Type','Code','ItemShape']],
  ['share/pc/pcclass.csv',['class','0']],
];
const BINARIES = [
  ['share/item/item.dat',565,'global-item-565-v1'],
  ['share/item/itemevent.dat',565,'global-item-565-v1'],
  ['share/item/itemoption.dat',148,'global-item-option-148-v1'],
];
async function ordinary(root,relative){
  let current=path.resolve(root);
  // Never follow a linked source ancestor, including a junction above dataRoot.
  for(let at=current;;){const stat=await fs.lstat(at);if(stat.isSymbolicLink()||!stat.isDirectory())throw Error('Source ancestor is not an ordinary directory');const parent=path.dirname(at);if(parent===at)break;at=parent;}
  for(const part of relative.split('/')){current=path.join(current,part);if((await fs.lstat(current)).isSymbolicLink())throw Error('Linked compatibility input');}
  const stat=await fs.stat(current);if(!stat.isFile())throw Error('Compatibility input is not a file');return {file:current,stat};
}
async function digest(file){const hash=createHash('sha256');for await(const chunk of createReadStream(file))hash.update(chunk);return hash.digest('hex');}
export async function inspectGlobalCompatibility({dataRoot,tableManifest=process.env.DEKARON_TABLE_COMPAT==='0'?null:defaultTableManifest()}){
  const inputs=[],issues=[];
  for(const [relative,required] of TABLES){
    try{
      const {file,stat}=await ordinary(dataRoot,relative),handle=await fs.open(file,'r');let bytes;
      try{const buffer=Buffer.alloc(65536);const result=await handle.read(buffer,0,buffer.length,0);bytes=buffer.subarray(0,result.bytesRead);}finally{await handle.close();}
      // Only decode the header. A bounded read may stop inside a multibyte body
      // character, which must not falsely reject an otherwise valid source.
      const le=bytes[0]===0xff&&bytes[1]===0xfe,be=bytes[0]===0xfe&&bytes[1]===0xff;
      let end=-1;
      if(le||be){for(let i=2;i+1<bytes.length;i+=2)if(bytes[i]===(le?10:0)&&bytes[i+1]===(le?0:10)){end=i+2;break;}}
      else{const newline=bytes.indexOf(10);if(newline>=0)end=newline+1;}
      const text=decodeText(end>=0?bytes.subarray(0,end):bytes,true),line=text.split('\n',1)[0];
      if(!text.includes('\n')&&stat.size>bytes.length)throw Error('Table header exceeds supported bound');
      // build-items already supports this original spelling; preflight must
      // not reject a source the actual item parser can read.
      const columns=(parseCSV(line)[0]||[]).map(value=>relative==='share/item/itemweapon.csv'?value.trim().replace(/^Item Index$/,'ItemIndex'):value.trim()),missing=required.filter(name=>!columns.includes(name));
      if(missing.length){issues.push({file:relative,code:'required-columns-missing',columns:missing});continue;}
      if(required.some(name=>columns.filter(column=>column===name).length!==1)){issues.push({file:relative,code:'ambiguous-required-columns'});continue;}
      // These tables still have positional consumers: build-boxes takes map
      // index/name from cells 0/1, build-monsters indexes NPC rows by cell 0,
      // and class builders address each column by class number. Do not accept
      // a named-header match that would silently change their joins.
      const positional=relative==='share/maplist.csv'?['Index','Name']:relative==='share/creature/npc.csv'?['Index']:relative==='share/pc/pcclass.csv'?columns.map((_,i)=>i===0?'class':String(i-1)):null;
      if(positional?.some((name,i)=>columns[i]!==name)){issues.push({file:relative,code:'unsupported-column-order',expectedPrefix:positional});continue;}
      inputs.push({file:relative,kind:'csv',profile:'required-column-names-v1',columns,bytes:stat.size,sha256:await digest(file)});
    }catch(error){issues.push({file:relative,code:error.code==='ENOENT'?'required-table-missing':'unreadable-table'});}
  }
  for(const [relative,stride,profile] of BINARIES){
    try{
      const {file,stat}=await ordinary(dataRoot,relative);
      if(!stat.size||stat.size%stride){issues.push({file:relative,code:'unsupported-binary-layout',bytes:stat.size,expectedRecordBytes:stride});continue;}
      inputs.push({file:relative,kind:'binary',profile,recordBytes:stride,records:stat.size/stride,bytes:stat.size,sha256:await digest(file)});
    }catch(error){if(error.code!=='ENOENT')issues.push({file:relative,code:'unreadable-binary'});}
  }
  // Terrain is loaded lazily at runtime, so builders do not necessarily touch
  // every map. Refuse a new format before promoting its prepared generation.
  const directories=['map'];
  while(directories.length){
    const relative=directories.pop();let entries;
    try{const dir=path.join(dataRoot,relative);if((await fs.lstat(dir)).isSymbolicLink())throw Error('Linked map directory');entries=await fs.readdir(dir,{withFileTypes:true});}
    catch(error){if(error.code==='ENOENT'&&relative==='map')continue;issues.push({file:relative,code:'unreadable-map-directory'});continue;}
    for(const entry of entries){
      const file=relative+'/'+entry.name;
      if(entry.isSymbolicLink()){issues.push({file,code:'linked-map-input'});continue;}
      if(entry.isDirectory()){directories.push(file);continue;}
      if(!entry.isFile()||!entry.name.toLowerCase().endsWith('.map'))continue;
      try{
        const located=await ordinary(dataRoot,file),handle=await fs.open(located.file,'r'),header=Buffer.alloc(4);let bytesRead;
        try{({bytesRead}=await handle.read(header,0,4,0));}finally{await handle.close();}
        const version=bytesRead===4?header.readUInt32LE():null;
        if(![MAP_VERSION_V1,MAP_VERSION_V2].includes(version)){issues.push({file,code:'unsupported-map-version',version});continue;}
        inputs.push({file,kind:'map-header',profile:'terrain-'+version,version,bytes:located.stat.size});
      }catch{issues.push({file,code:'unreadable-map-header'});}
    }
  }
  let tableCompat=null;
  if(tableManifest){
    const r=checkTables(dataRoot,tableManifest),warnings=[...r.info];
    for(const issue of r.issues){if(TABLE_COMPAT_BLOCKING.has(issue.code))issues.push({...issue,source:'table-compat'});else warnings.push(issue);}
    const counts={};for(const w of warnings)counts[w.code]=(counts[w.code]||0)+1;
    tableCompat={manifest:tableManifest.capturedFrom,manifestTables:tableManifest.tableCount,checked:r.checked,blocking:r.issues.filter(i=>TABLE_COMPAT_BLOCKING.has(i.code)).length,warningCounts:counts,warnings:warnings.slice(0,200),reviewRequested:true};
  }
  return {version:1,scope:'Core source structures only; builders validate additional formats. Not a gameplay or native-parity certification.',compatible:issues.length===0,inputs,issues,...(tableCompat?{tableCompat}:{})};
}
export function assertGlobalCompatibility(report){
  if(report?.version!==1||report.compatible!==true||!Array.isArray(report.issues)||report.issues.length){
    const details=(report?.issues||[]).map(issue=>`${issue.file}: ${issue.code}`).join('; ');
    throw Object.assign(Error(`Global data needs a compatible parser or complete source files. ${details} Previous prepared generation preserved.`),{code:'GLOBAL_FORMAT_UNSUPPORTED'});
  }
}
