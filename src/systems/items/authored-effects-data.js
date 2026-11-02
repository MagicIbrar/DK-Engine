import {refineLoopMs} from '../../config/glow-time-scale.js';
import {fetchText,fetchBuffer} from '../../engine/assets.js';
import {parseCSV} from '../../formats/binreader.js';
import {parseTpack,textureCandidates} from '../../formats/tpack.js';
import {parseDDS,decodeToRGBA} from '../../formats/dds.js';
import {parseEffectScenes,parseEffectData,describeControl,describeUnit,gamePathToData} from './native-effect-parser.js';
import {gfxB} from '../../config/gfx-b-switches.js'; // gfx-B

/** Effect tpacks the effect data names under a path where the client does not ship them. Each entry verified against the
 * Global pack index (audit/global-ref/index.tsv): source key absent, target key present. Only verified entries, no pattern rule. */
export const TPACK_RELOCATED=Object.freeze({'texturepack/effect/wing/sum_equ_win02.tpack':'texturepack/item/armor/wing/sum_equ_win02.tpack'});

// Index raw blocks once, yielding during large native catalog scans. Only a
// requested block enters the full keyframe parser, never the entire catalog.
async function blockIndex(text,scene){
 const out=new Map(),pattern=scene?/<cate>\s*(-?\d+)|<effect>[\s\S]*?<\/effect>/gi:/<effectdata>[^\r\n]*[\s\S]*?<\/effectdata>/gi;
 let cate=null,count=0;for(const match of text.matchAll(pattern)){
  if(scene&&match[1]!=null){cate=Number(match[1]);continue;}
  const key=scene?`${cate}:${/^\s*id\s+(-?\d+)/im.exec(match[0])?.[1]}`:/^\s*name\s+(.+)$/im.exec(match[0])?.[1]?.trim().toLowerCase();
  if(key)out.set(key,scene?`<cate> ${cate}\n${match[0]}`:match[0]);
  if(++count%128===0)await new Promise(resolve=>globalThis.setTimeout(resolve,0));
 }return out;
}

// Native modeleffect group31/sub1 maps equipped item_shape effects. Sub0 is drops.
export function equipmentEffectRows(text){
 const rows=new Map();for(const row of parseCSV(text)){
  if(Number(row[0])!==31||Number(row[1])!==1||!(Number(row[2])>0))continue;
  const ref=offset=>Number(row[offset+1])>0?{cate:Number(row[offset]),id:Number(row[offset+1]),scene:Number(row[offset+2]),timeMs:Number(row[offset+3]),loop:Number(row[offset+4])}:null;
  rows.set(Number(row[2]),{effect:ref(4),combat:ref(9)});
 }return rows;
}
// Native generic MeshStatus modes: +1..3, +4..6, +7..9, +11..14, +15 live in effectscene 7:10.
// +10 is absent from 7:10; native picks scene 7:11 ("1111") MeshStatus units ms_upgrade_1012 (mode 104, armor,
// eff_upgrade_79.dds) / ms_upgrade_W_1012 (mode 114, weapon, eff_upgrade_13.dds). Armor control in 7:11 is authored
// inactive; equipment +10 forces it active when selected. No cate-8 UI twin for +10 (ms_upgrade_U_1012 is orphaned).
export function upgradeFamily(tier){
 const n=Number(tier);return n>=1&&n<=3?1:n>=4&&n<=6?2:n>=7&&n<=9?3:n>=11&&n<=14?4:n===15?5:0;
}
export function upgradeEffectMode(tier,weapon=false){
 const n=Number(tier);if(n===10)return weapon?114:104;
 const family=upgradeFamily(n);return family?family+(weapon?10:0):0;
}
export function refinementEffect(def,slot=def?.slot){
 const weapon=slot==='weapon'||slot==='left';
 if(!weapon&&!['armor','helmet','coat','pants','glove','gloves','boots'].includes(slot))return null;
 const upgrade=Number(def?.itemLv);return upgradeEffectMode(upgrade,weapon)?{upgrade,weapon}:null;
}
/** Socket effect attribute of one socket stone: the key of its modeleffect group24 row (code4 0..6 -> scenes 7:6,7:1..7:6).
 * Source: the stone's own item Attribute column (Bead 1 fire, Cube 2 ice, Spear 3 lightning, Skull 4 poison, Crystal 5 curse; every
 * stone whose attribute and Fire/Ice/Lightning/Poison/Curse Attack option (56..60) are both set agrees: 479 of 479). The modern
 * Elemental Stones (Fire Stone V...) carry attribute 0 but exactly one such option, which names the same element enum; a stone
 * with neither (stat stones with attribute 0) selects the data's default row 0. */
export function socketStoneAttribute(stone){
 const attribute=Number(stone?.attribute);if(Number.isInteger(attribute)&&attribute>=1&&attribute<=6)return attribute;
 const elements=[...new Set([...(stone?.options||[]),...(stone?.exOptions||[])].filter(([code,value])=>Number(code)>=56&&Number(code)<=60&&Number(value)>0).map(([code])=>Number(code)-55))];
 return elements.length===1?elements[0]:0;
}
/** Equipped socket glow of a weapon or offhand/shield: socket count and, per stone attribute, how many gems of that type
 * sit in it. Invocation: one authored scene per filled gem (count intensity) at that gem's native blade bone (SWD_W0x /
 * _L from the weapon skel / item_upgrade_10* attach points); see AuthoredEquipmentEffects.prepare. Authored alpha/scale
 * keys are never multiplied by gem count. Nothing is returned for an empty item.
 * @returns {{capacity:number,filled:number,glows:{attribute:number,stones:number}[]}|null} */
export function socketEffect(def,sockets,db){
 if(!['weapon','offhand'].includes(def?.slot)||!Array.isArray(sockets))return null;
 const capacity=sockets.length;if(!capacity||capacity>4)return null;
 const counts=new Map();let filled=0;
 for(const {attribute} of socketGems(sockets,db)){counts.set(attribute,(counts.get(attribute)||0)+1);filled++;}
 if(!filled)return null;
 return {capacity,filled,glows:[...counts].sort((a,b)=>a[0]-b[0]).map(([attribute,stones])=>({attribute,stones}))};
}
/** The filled sockets of an item instance with the modeleffect group24 attribute of each stone, in socket order:
 * [{index, attribute}]. Empty sockets and non-stone ids are skipped (index is the socket's own position, 0-based, so the
 * glow of a partially socketed weapon keeps each stone where it sits). */
export function socketGems(sockets,db){
 const out=[];if(!Array.isArray(sockets))return out;
 sockets.slice(0,4).forEach((id,index)=>{
  const stone=Number(id)>0?db.def(Number(id)):null;if(!stone||Number(stone.type)!==1||Number(stone.code)!==0)return;
  out.push({index,attribute:socketStoneAttribute(stone)});
 });
 return out;
}
/** Gem colour of a socket attribute, taken from the native socket effect texture itself (texture/Effect/soket/socket_*.dds,
 * the unit of modeleffect group24 -> scene cate7 id attribute||6): the alpha-weighted mean RGB of the 32x32 glow, scaled so its
 * brightest channel is 1 (fire 1,.42,.29 / ice .33,.59,1 / lightning .29,.30,1 / poison .42,1,.34 / curse .94,.37,1 /
 * default .93,.36,1). The texture's own whitened core is thereby excluded from the hue, never the data's colour. */
export function socketHueOf(rgba){
 let a=0,r=0,g=0,b=0;
 for(let i=0;i<rgba.length;i+=4){const w=rgba[i+3]/255;a+=w;r+=rgba[i]*w;g+=rgba[i+1]*w;b+=rgba[i+2]*w;}
 if(!(a>0))return [1,1,1];
 const mean=[r/a,g/a,b/a],top=Math.max(...mean,1e-6);return mean.map(v=>v/top);
}
export class AuthoredEffectsData{
 constructor({text=fetchText,buffer=fetchBuffer,unitTypes=['sprite','decal','mesh','particle','meshstatus']}={}){this.text=text;this.buffer=buffer;this.unitTypes=new Set(unitTypes);this.files=new Map();this.indexes=new Map();this.scenes=new Map();this.units=new Map();this.pending=new Map();this.rows=null;}
 index(path,scene){if(!this.indexes.has(path)){const pending=this.file(path).then(text=>blockIndex(text,scene)).catch(error=>{if(this.indexes.get(path)===pending)this.indexes.delete(path);throw error;});this.indexes.set(path,pending);}return this.indexes.get(path);}
 file(path){if(!this.files.has(path)){const pending=Promise.resolve().then(()=>this.text(path)).catch(error=>{if(this.files.get(path)===pending)this.files.delete(path);throw error;});this.files.set(path,pending);}return this.files.get(path);}
 scene(key){return this.scenes.get(key)||null;}
 unit(key){return this.units.get(key)||null;}
 // Only resolved authored rows can prove a stance change selects the same scene.
 // Keep the conservative restart while the table is unavailable or still loading.
 sameStanceReference(id,first,second){
  if(first===second)return true;
  const row=this.referenceRows?.get(Number(id));if(!row)return false;
  const select=stance=>(stance==='battle'&&row.combat)||row.effect;
  const a=select(first),b=select(second);if(!a||!b)return a===b;
  return ['cate','id','scene','timeMs','loop'].every(key=>a[key]===b[key]);
 }
 async reference(id,combat=false){if(!this.rows){const pending=this.file('script/effect/modeleffect.csv').then(equipmentEffectRows).catch(error=>{if(this.rows===pending)this.rows=null;throw error;});this.rows=pending;}const rows=await this.rows;this.referenceRows=rows;const row=rows.get(Number(id));const ref=(combat&&row?.combat)||row?.effect;if(!ref)return null;await this.load(ref);return this.scene(`${ref.cate}:${ref.id}`)?ref:null;}
 /** Ensure 7:11's inactive armor unit (ms_upgrade_1012) is resident — _load skips active:false controls. */
 async ensureUpgrade1012Units(scene){
  const needed={1:'ms_upgrade_1012',2:'ms_upgrade_W_1012'};
  for(const [id,name] of Object.entries(needed)){
   if(scene.res[id]&&this.unit(scene.res[id]))continue;
   const resolved=await this.resolveUnit(name,'02');if(!resolved.unit)continue;
   if(!this.unitTypes.has(resolved.unit.unittype))continue;
   const resolver={path:gamePathToData,texture:p=>gamePathToData('texture',p),sound:p=>gamePathToData('sound',p),tpack:()=>null};
   const nameKey=`item:${resolved.unit.file}:${name.toLowerCase()}`;
   this.units.set(nameKey,describeUnit(resolved.unit,resolver));scene.res[id]=nameKey;
  }
 }
 async upgradeReference(tier,weapon=false){
  const mode=upgradeEffectMode(tier,weapon);if(!mode)return null;
  const plus10=mode===114||mode===104;const cateId=plus10?11:10;
  await this.load({cate:7,id:cateId});const scene=this.scene(`7:${cateId}`);if(!scene)return null;
  if(plus10)await this.ensureUpgrade1012Units(scene);
  const sceneId=100+mode;
  if(!scene.scenes[sceneId]){
   const controls=(scene.scenes[1]?.controls||[])
    .filter(c=>this.unit(scene.res[c.unit])?.meshStatus?.mode===mode)
    .map(c=>({...c,active:true})); // 7:11 authors armor control inactive
   if(controls.length!==1)throw Error('Original upgrade effect selector is ambiguous');
   scene.scenes[sceneId]={name:`selected native mesh_status ${mode}`,controls};
  }
  // Selected subscenes reuse the original control and unit without altering scene 1. The scene is authored as `lifetime 0 1000`
  // (keys 0..999), and that authored length is the play length, as every modeleffect.csv row does. LANE-63: the engine-chosen
  // 3500 ms loop (engine-chosen-refinement-rate.js) is removed.
  // glowrate2: the 0..1000 keys are normalized (FUN_011b46e0); the play length is the caller's, see src/config/glow-time-scale.js.
  return {cate:7,id:cateId,scene:sceneId,timeMs:refineLoopMs(),loop:0};
 }
 refinement(tier,weapon=false){return this.upgradeReference(tier,weapon);}
 async inventoryUpgradeReference(tier){
  // Global effectscene.com.txt has separate UI (cate 8) upgrade scenes 21..25. No cate-8 twin for +10.
  const family=upgradeFamily(tier);if(!family)return null;
  const ref={cate:8,id:20+family,scene:1,timeMs:1000,loop:0};
  await this.load(ref);return this.scene(`${ref.cate}:${ref.id}`)?ref:null;
 }
 async socketReference(attribute){
  if(!Number.isInteger(attribute)||attribute<0||attribute>6)return null;
  if(!this.socketRows){const pending=this.file('script/effect/modeleffect.csv').then(text=>new Map(parseCSV(text).filter(r=>Number(r[0])===24&&Number(r[1])===1&&Number(r[2])===0).map(r=>[Number(r[3]),r]))).catch(error=>{if(this.socketRows===pending)this.socketRows=null;throw error;});this.socketRows=pending;}
  const row=(await this.socketRows).get(attribute);
  if(!row)return null;const ref={cate:Number(row[4]),id:Number(row[5]),scene:Number(row[6]),timeMs:Number(row[7]),loop:Number(row[8])};
  await this.load(ref);return this.scene(`${ref.cate}:${ref.id}`)?ref:null;
 }
 /** ENGINE-CHOSEN station mist: the native socket scene of an attribute (socketReference) with ONE change, a control colour
  * gain (SOCKET_GLOW_CHOSEN.MIST_GAIN) on its sprite: authored sprites are texture alpha .5 x key alpha .5-.8, i.e. too faint
  * to read as mist along a whole blade. Texture, size, alpha keys and scale keys stay the data's; hue is unchanged (equal gain on
  * r,g,b). Registered as scene cate 7 id 100000 + id so the shared native scene is never mutated. */
 async socketMistReference(attribute,gain){
  const base=await this.socketReference(attribute);if(!base)return null;
  const id=100000+base.id,key=`${base.cate}:${id}`;
  if(!this.scenes.has(key)){
   const source=this.scene(`${base.cate}:${base.id}`),colour=[[0,gain,gain,gain],[999,gain,gain,gain]];
   this.scenes.set(key,{...source,scenes:Object.fromEntries(Object.entries(source.scenes).map(([sceneId,scene])=>[sceneId,{...scene,controls:scene.controls.map(c=>({...c,color:colour}))}]))});
  }
  // The mist repeats at the socket row's own modeleffect.csv group 24 eff_time (1000 ms). LANE-63: the engine-chosen 4000 ms
  // stretch (SOCKET_ORB_LOOP_MS) is removed.
  return {...base,id};
 }
 /** Inventory (UI cate8) twin of the socket scene: effectscene.com cate 8 ids 1..6 repeat cate 7's sprites with the larger UI
  * scale keys (1.5,1,1.5)(1.8,2,1.8)(1.5,1,1.5) and the same 1000 ms alpha keys; attribute 0/6 -> id 6 as in group24. */
 async inventorySocketReference(attribute){
  const id=Number(attribute)>=1&&Number(attribute)<=5?Number(attribute):6;
  const ref={cate:8,id,scene:1,timeMs:1000,loop:1};await this.load(ref);
  const scene=this.scene(`8:${id}`),control=scene?.scenes[1]?.controls?.[0];if(!control)return null;
  return {...ref,control,unit:this.unit(scene.res[control.unit])};
 }
 /** The native socket glow of an attribute as pixels: {attribute, texture, width, height, rgba, hue}. The decoded 32x32
  * texture of its scene's sprite unit (shared by the inventory icon glow); hue = socketHueOf(rgba). Cached per attribute. */
 socketGlowTexture(attribute){
  this.glowTextures||=new Map();const key=Number(attribute)||0;
  if(!this.glowTextures.has(key)){
   const pending=(async()=>{
    const ref=await this.socketReference(key);if(!ref)return null;
    const scene=this.scene(`${ref.cate}:${ref.id}`),unit=this.unit(scene.res[scene.scenes[ref.scene]?.controls?.[0]?.unit]);if(!unit?.texture)return null;
    const bytes=await this.buffer(unit.texture),view=ArrayBuffer.isView(bytes)?bytes:new Uint8Array(bytes);
    const dds=parseDDS(view.buffer.slice(view.byteOffset,view.byteOffset+view.byteLength)),image=decodeToRGBA(dds);
    return {attribute:key,texture:unit.texture,width:image.width,height:image.height,rgba:image.data,hue:socketHueOf(image.data),size:Number(unit.size)||1};
   })().catch(error=>{if(this.glowTextures.get(key)===pending)this.glowTextures.delete(key);throw error;});
   this.glowTextures.set(key,pending);
  }
  return this.glowTextures.get(key);
 }
 // A native scene may name a unit from another list_data catalog. Prefer its
 // own definition; use another file only when every matching definition agrees.
 // Never guess between conflicting same-name resources or cache transport failure.
 async resolveUnit(name,file){
  const key=String(name).toLowerCase(),local=(await this.index(`property/effect/effectdata.${file}.txt`,false)).get(key);
  if(local)return {unit:parseEffectData(local,file)[0]};
  const matches=(await Promise.all(['01','02','03','snd','com','map'].filter(f=>f!==file).map(async f=>{
   const block=(await this.index(`property/effect/effectdata.${f}.txt`,false)).get(key);
   return block?parseEffectData(block,f)[0]:null;
  }))).filter(Boolean);
  const signature=u=>JSON.stringify({type:u.unittype,tag:u.tag,fields:Object.fromEntries(Object.entries(u.fields).sort())});
  if(new Set(matches.map(signature)).size>1)return {unit:null,reason:'ambiguous-unit',files:matches.map(u=>u.file)};
  return {unit:matches[0]||null};
 }
 async load(ref){
  const key=`${ref.cate}:${ref.id}`;if(this.scenes.has(key))return;if(this.pending.has(key))return this.pending.get(key);
  // Cache all requested native definitions; scene count must not disable later gear.
  const promise=this._load(ref).finally(()=>this.pending.delete(key));this.pending.set(key,promise);return promise;
 }
 async _load(ref){
  // Parse on demand, retaining raw text once and only the selected compiled scenes/units.
  for(const file of ['01','02','03','com','map']){
   const block=(await this.index(`property/effect/effectscene.${file}.txt`,true)).get(`${ref.cate}:${ref.id}`);if(!block)continue;
   const scene=parseEffectScenes(block,file)[0];
   const selected={...scene,scenes:{},res:{},unresolved:[]};
   // Inactive native controls never spawn. Their stale/unresolved resources
   // must not abort an otherwise supported equipped scene.
   const activeUnits=new Set(scene.scenes.flatMap(s=>s.controls.map(describeControl)).filter(c=>c.active!==false).map(c=>c.unit));
   for(const [id,name]of Object.entries(scene.res)){
    if(!activeUnits.has(Number(id)))continue;
    // ORIGINAL DATA GAP, ENGINE CHOICE: some shipped scenes name a unit that no effectdata file defines (e.g. sp_light01_orange_01 in
    // 5:1372) or a texture pack the client does not ship (e.g. Effect\Wing\SUM_EQU_WIN02.tpack in 5:2007). Like tools/build-skills.mjs
    // (res {missing:true} / miss('tpack')), only that control is left without a unit (the shared EffectPlayer spawns nothing for it) and
    // it is recorded in `unresolved`; the scene's other authored controls still play. A transient request failure still rejects, and a
    // defined unit of an unsupported type still refuses the scene. (Wings of Demon God, mh_SUM_WING02: its tpack, mesh, anim and skel
    // under Effect\Wing are all absent from both Global packs; COMPATIBILITY, nativeDispatchVerified:false, see docs/WING-BINDING.md.)
    const resolved=await this.resolveUnit(name,file),unit=resolved.unit;
    if(!unit){selected.unresolved.push({res:Number(id),name,reason:resolved.reason||'unit',...(resolved.files?{files:resolved.files}:{})});continue;}
    if(!this.unitTypes.has(unit.unittype))throw Error(`Unsupported original equipment effect unit ${name}`);
    const packs=new Map();if(unit.fields.texturepack){const key=gamePathToData('texturepack',unit.fields.texturepack);let bytes;try{bytes=await this.buffer(key);}catch(error){if(error?.missing!==true&&error?.code!=='ENOENT')throw error;const alt=gfxB('wingTpackNoRelocate')?null:TPACK_RELOCATED[key]; /* gfx-B: Global names Effect\\Wing\\SUM_EQU_WIN02 (absent with its mesh/anim/skel); no relocation unless switched off */if(alt){try{bytes=await this.buffer(alt);}catch(e2){if(e2?.missing!==true&&e2?.code!=='ENOENT')throw e2;}}if(!bytes){selected.unresolved.push({res:Number(id),name,reason:'tpack',key});continue;}}const tp=parseTpack(bytes);const resolve=texture=>textureCandidates(tp.texpath,texture)[0]||null;packs.set(key,{key,frames:tp.slots.map(slot=>resolve(tp.diffuse[slot])),textures:tp.slots.map(slot=>({material:slot,diffuse:resolve(tp.diffuse[slot])}))});}
    const resolver={path:gamePathToData,texture:p=>gamePathToData('texture',p),sound:p=>gamePathToData('sound',p),tpack:p=>packs.get(gamePathToData('texturepack',p))};
    const nameKey=`item:${unit.file}:${name.toLowerCase()}`;this.units.set(nameKey,describeUnit(unit,resolver));selected.res[id]=nameKey;
   }
   for(const s of scene.scenes)selected.scenes[s.sceneId]={name:s.name,controls:s.controls.map(describeControl)};
   this.scenes.set(`${ref.cate}:${ref.id}`,selected);return;
  }
 }
}

