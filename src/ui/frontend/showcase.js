// Presentation-only maxed armor. Original producer references + native +15 item looks/effect selectors;
// never add an item index, inventory entry or gameplay grade to a character save.
import {fetchText,normPath} from '../../engine/assets.js';
import {ItemDB} from '../../systems/items/db.js';

export const SHOWCASE_ARMOR_GRADE = 15; // Highest authored armor grade in the supplied item/effect tables.
const slots = {helmet:'helmet',coat:'coat',pants:'pants',glove:'glove',boots:'boots'};
export function showcaseSlot(part) {
  const key = normPath(part?.tpack || part?.mesh || '');
  const folder = /\/armor\/(helmet|coat|pants|glove|boots)\//.exec(key)?.[1];
  if (folder) return slots[folder];
  return [['helmet','hel'],['coat','cot'],['pants','pat'],['glove','glv'],['boots','bot']].find(([,token])=>key.includes(`_${token}_`))?.[0] || null;
}
export function parseShowcaseParts(text) {
  const classes = new Map();
  for (const line of String(text).split(/\r?\n/)) {
    const match = /^\s*mesh\s+(\d+)\s+(\S+)\s+(\S+)/i.exec(line);
    if (!match) continue;
    const index = Number(match[1]), parts = classes.get(index) || [];
    parts.push({mesh:`mesh/${normPath(match[2])}`,tpack:`texturepack/${normPath(match[3])}`});classes.set(index,parts);
  }
  return classes;
}
// Source matches are exact class/slot/tpack and mesh; a producer mesh omitted by the builder as missing
// may use its explicit paired tpack's native item mesh (Trie Muse's HEL tpack / erroneous BOT mesh row).
export function resolveShowcaseVisuals(db,classDef,producerParts=classDef?.showcase?.parts||[]) {
  const equipment={},entries=[],references=[],available=new Map((classDef?.showcase?.parts||[]).map(p=>[showcaseSlot(p),p]));
  const candidates=Object.keys(db.items).map(id=>db.def(id)).filter(d=>Number(d?.itemLv)===SHOWCASE_ARMOR_GRADE&&Object.values(slots).includes(d.slot==='armor'?'coat':d.slot));
  for (const part of producerParts) {
    const slot=showcaseSlot(part);if(!slot||equipment[slot])continue;
    const source=available.get(slot),mesh=normPath(part.mesh),tpack=normPath(part.tpack);
    const matches=candidates.flatMap(def=>{
      if((def.slot==='armor'?'coat':def.slot)!==slot)return [];
      const look=db.look(def.index),asset=db.asset(look?.byClass?.[classDef.index]??look?.all);
      return asset&&normPath(asset.tpack)===tpack&&(normPath(asset.mesh)===mesh||!source)?[{def,asset}]:[];
    });
    // Ambiguous or unsupported assets keep the existing unrefined presentation, never guessed glow.
    const match=matches.length===1?matches[0]:null;
    const visual=match?.asset||source;
    if(!visual?.mesh)continue;
    equipment[slot]={mesh:visual.mesh,tpack:visual.tpack||null,textures:visual.textures||null};
    if(match){entries.push({slot,upgrade:SHOWCASE_ARMOR_GRADE,weapon:false});references.push({slot,itemIndex:match.def.index,name:match.def.name,grade:SHOWCASE_ARMOR_GRADE,sourceMesh:part.mesh,mesh:visual.mesh,tpack:visual.tpack,repairedMissingMesh:!source});}
  }
  return {equipment,entries,references};
}
let sourcePromise;
const resolved=new WeakMap();
export async function loadShowcaseVisuals(classDef) {
  if (!sourcePromise) {
    const pending=fetchText('script/producer/char_createinfo.txt').then(parseShowcaseParts).catch(error=>{
      if(sourcePromise===pending)sourcePromise=null;
      console.warn('[frontend] showcase producer',error.message);return null;
    });
    sourcePromise=pending;
  }
  const [db,source]=await Promise.all([ItemDB.load().catch(error=>{
    console.warn('[frontend] showcase item looks',error.message);return null;
  }),sourcePromise]);
  if(!db)return resolveShowcaseVisuals({items:{}},classDef);
  // Keep existing native parts during a transient producer failure; retry next load rather than caching a partial set.
  if(!source?.has(Number(classDef.index)))return resolveShowcaseVisuals(db,classDef);
  let classes=resolved.get(db);if(!classes){classes=new WeakMap();resolved.set(db,classes);}
  if(!classes.has(classDef))classes.set(classDef,resolveShowcaseVisuals(db,classDef,source.get(Number(classDef.index))));
  return classes.get(classDef);
}
