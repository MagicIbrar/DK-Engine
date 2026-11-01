// The import boundary is stricter than the original-client readers, which tolerate
// legacy stubs and unknown fields. Validate every part before publishing a draft.
import {parseMap} from '../../formats/map.js';
import {parseMol} from '../../formats/mol.js';
import {parseMac} from '../../formats/mac.js';
import {META_FORMAT} from './format.js';

const fail = message => { throw new Error(`Custom map: ${message}`); };
const object = (v, label) => { if (!v || typeof v !== 'object' || Array.isArray(v)) fail(`${label} must be an object.`); };
const number = (v, label, min=-1000000, max=1000000) => { if (typeof v !== 'number' || !Number.isFinite(v) || v < min || v > max) fail(`Invalid ${label}.`); };
const integer = (v, label, min=0, max=2147483647) => { number(v,label,min,max); if(!Number.isSafeInteger(v))fail(`Invalid ${label}.`); };
const text = (v,label,max=1024) => { if(typeof v !== 'string' || v.length>max || /[\x00-\x08\x0b\x0c\x0e-\x1f]/.test(v))fail(`Invalid ${label}.`); };
function asset(v,label){text(v,label,1024);const parts=v.replace(/\\/g,'/').split('/');if(!v || /^[a-z]+:|^[/\\]/i.test(v)||parts.some(p=>p==='..'||p==='.'))fail(`Invalid ${label} asset path.`);}
function point(v,label,W,H){object(v,label);number(v.x,`${label} X`,0,W);number(v.z,`${label} Z`,0,H);if(v.dirDeg!=null)number(v.dirDeg,`${label} direction`);}
function safeTree(v,depth=0){if(depth>16)fail('Metadata is too deeply nested.');if(v&&typeof v==='object'){for(const [k,value] of Object.entries(v)){if(['__proto__','prototype','constructor'].includes(k))fail('Unsafe metadata key.');safeTree(value,depth+1);}}else if(typeof v==='number'&&!Number.isFinite(v))fail('Metadata contains a nonfinite number.');}

export function validateMapFiles(files){
  object(files,'files');
  // Header limits must be checked before parseMap allocates its grids.
  const bytes=new Uint8Array(files.map || 0);
  if(bytes.byteLength<16 || bytes.byteLength>64*1024*1024)fail('Invalid terrain file size.');
  const header=new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength),W=header.getUint32(4,true),H=header.getUint32(8,true);
  if(!W||!H||W>1024||H>1024)fail('Imported maps are limited to 1024 cells on each side.');
  const map=parseMap(bytes,{strict:true});
  if(!map.knownVersion)fail('Unsupported map file version.');
  for(const [label,grid] of [['terrain heights',map.heights],['terrain normals',map.normals]])for(const value of grid)number(value,label);
  asset(map.tileFolder,'tile folder');for(const name of map.atlasNames)asset(name,'atlas');
  for(const water of map.water){asset(water.name,'water');for(let i=0;i<water.cells.length;i++){integer(water.cells[i],'water cell',0,W*H-1);number(water.cellHeights[i],'water height');}}
  for(const decal of map.decals){if(!decal.isNone)asset(decal.name,'decal');for(let i=0;i<decal.count;i++){integer(decal.cells[i],'decal cell',0,W*H-1);integer(decal.sizes[i],'decal size',0,1024);}}
  if(files.mol?.byteLength){const mol=parseMol(files.mol);if(mol.trailingBytes)fail('Trailing object bytes.');if(mol.count>100000)fail('Too many objects.');for(const o of mol.objects){asset(o.name,'object');for(const k of ['x','z','y','qx','qy','qz','qw','scale'])number(o[k],`object ${k}`);if(Math.hypot(o.qx,o.qy,o.qz,o.qw)<0.00001)fail('Invalid object quaternion.');}}
  if(files.mac?.byteLength){const collision=parseMac(files.mac);if(collision.empty||collision.width!==W||collision.height!==H)fail('Collision grid does not match the map.');if(collision.trailingBytes)fail('Trailing collision bytes.');}
  const meta=files.meta??{};object(meta,'metadata');safeTree(meta);
  if(meta.format!=null&&meta.format!==META_FORMAT)fail('Unsupported metadata format.');
  for(const k of ['name','desc','author'])if(meta[k]!=null)text(meta[k],k,k==='desc'?4096:120);
  if(meta.start!=null)point(meta.start,'start',W,H);
  for(const kind of ['spawns','npcs','portals']){
    const list=meta[kind]??[];if(!Array.isArray(list)||list.length>10000)fail(`Invalid ${kind} list.`);const ids=new Set();
    for(const row of list){object(row,kind);text(row.id,`${kind} ID`,120);if(!row.id||ids.has(row.id))fail(`Duplicate or empty ${kind} ID.`);ids.add(row.id);
      if(kind==='portals'){for(const k of ['x0','x1'])number(row[k],`portal ${k}`,0,W);for(const k of ['z0','z1'])number(row[k],`portal ${k}`,0,H);if(row.name!=null)text(row.name,'portal name',120);if(row.object)asset(row.object,'portal object');object(row.to,'portal destination');integer(row.to.map,'destination map');number(row.to.x,'destination X',0);number(row.to.z,'destination Z',0);if(row.to.dirDeg!=null)number(row.to.dirDeg,'destination direction');if(row.to.custom!=null)text(row.to.custom,'destination custom ID',120);
      }else{point(row,kind,W,H);integer(row[kind==='spawns'?'monsterIndex':'npcIndex'],`${kind} index`,1);if(kind==='spawns')number(row.respawnSec,'respawn seconds',1,86400);if(row.name!=null)text(row.name,`${kind} name`,120);if(row.jobs!=null){if(!Array.isArray(row.jobs)||row.jobs.length>100)fail('Invalid NPC jobs.');for(const job of row.jobs){if(!Array.isArray(job)||job.length!==2)fail('Invalid NPC job.');integer(job[0],'NPC job type');integer(job[1],'NPC job index');}}}
    }
  }
  if(meta.env!=null){object(meta.env,'environment');const e=meta.env;for(const k of ['light','envMap'])if(e[k]!=null)asset(e[k],k);if(e.lightText!=null)text(e.lightText,'light text',65536);for(const k of ['clipFar','dayMinutes'])if(e[k]!=null)number(e[k],k,0.01,100000);if(e.fixedHour!=null)number(e.fixedHour,'fixed hour',0,24);for(const k of ['bgmMap','minLevel','maxLevel'])if(e[k]!=null)integer(e[k],k);if(e.returnScroll!=null)integer(e.returnScroll,'return scroll',0,1);if(e.maxLevel>0&&e.minLevel>e.maxLevel)fail('Minimum level exceeds maximum level.');}
  if(meta.minimap!=null){text(meta.minimap,'minimap',4*1024*1024);if(!/^data:image\/png;base64,iVBORw0KGgo[A-Za-z0-9+/]*={0,2}$/.test(meta.minimap))fail('Minimap must be a PNG data URL.');}
  return {map,meta};
}
