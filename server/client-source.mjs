// The preparation manifest is the sole atomic switch between complete generations.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
const ENGINE = fileURLToPath(new URL('../', import.meta.url));
function safeCachePath(engine, target) {
  const root = fs.realpathSync(engine), resolved = path.resolve(target);
  const rel = path.relative(root, resolved);
  if (rel.startsWith('..') || path.isAbsolute(rel)) return false;
  let current = root;
  for (const component of rel.split(path.sep).filter(Boolean)) {
    current = path.join(current, component);
    if (fs.lstatSync(current).isSymbolicLink()) return false;
    const real = fs.realpathSync(current), relative = path.relative(root, real);
    if (relative.startsWith('..') || path.isAbsolute(relative)) return false;
  }
  return true;
}
function generationPath(engine,value) {
  return typeof value==='string'&&/^\.client-cache\/generations\/[a-zA-Z0-9_-]+$/.test(value)?path.resolve(engine,value):null;
}
export function clientSource(engine = ENGINE) {
  // DEDICATED: the copied server reads the main engine's active prepared Global generation.
  // No cache link or fallback is allowed here: a missing source must stop startup visibly.
  const dedicatedConfig=path.join(engine,'dedicated-source.json');
  if(fs.existsSync(dedicatedConfig)){
    const config=JSON.parse(fs.readFileSync(dedicatedConfig,'utf8'));
    const source=path.resolve(engine,config.sourceEngine||'');
    if(config.version!==1||source===path.resolve(engine)||!fs.existsSync(path.join(source,'.client-cache/current.json')))throw Error('Dedicated Global source is unavailable. Select your original Global data again, or redownload it if files are missing.');
    const active=clientSource(source);
    if(!active.manifest)throw Error('Dedicated Global source has no validated prepared generation. Select your original Global data again, or redownload it if files are missing.');
    return active;
  }
  const fallbackData = process.env.DEKARON_DATA || path.resolve(engine, '../data/unpacked/data');
  const fallback = { dataRoot: fallbackData, gamedataRoot: process.env.DEKARON_GAMEDATA || path.join(engine, 'gamedata'), siteAssetRoot: path.join(engine, 'site/assets'), version: 'legacy', manifest: null };
  let manifest;
  try {
    engine = fs.realpathSync(engine);
    const pointer = path.join(engine, '.client-cache/current.json');
    if (!safeCachePath(engine, pointer)) return fallback;
    manifest = JSON.parse(fs.readFileSync(pointer, 'utf8'));
  } catch { return fallback; }
  const generation = generationPath(engine,manifest.generation);
  const cache = path.resolve(engine, '.client-cache/generations');
  if (!generation || !generation.startsWith(cache + path.sep) || !manifest.source?.root || !['pack', 'loose', 'prepared'].includes(manifest.source.kind)) return fallback;
  const gamedataRoot = path.join(generation, 'gamedata');
  if(manifest.dataSnapshot!==undefined){
    if(manifest.dataSnapshot!==true||manifest.source.kind!=='loose'||manifest.dataGeneration!==undefined)return fallback;
    try{const file=path.join(generation,'manifest.json');if(!safeCachePath(engine,file)||JSON.stringify(JSON.parse(fs.readFileSync(file,'utf8')))!==JSON.stringify(manifest))return fallback;}catch{return fallback;}
  }
  let dataGeneration=generation;
  if(manifest.dataGeneration!==undefined){
    dataGeneration=generationPath(engine,manifest.dataGeneration);
    if(!dataGeneration||manifest.source.kind!=='pack'||typeof manifest.sourceFingerprint!=='string'||!/^[a-f0-9]{64}$/.test(manifest.sourceFingerprint))return fallback;
    try {
      const localManifest=path.join(generation,'manifest.json'),ownerManifest=path.join(dataGeneration,'manifest.json');
      if(!safeCachePath(engine,localManifest)||!safeCachePath(engine,ownerManifest))return fallback;
      const local=JSON.parse(fs.readFileSync(localManifest,'utf8')),owner=JSON.parse(fs.readFileSync(ownerManifest,'utf8'));
      if(JSON.stringify(local)!==JSON.stringify(manifest)||owner.generation!==manifest.dataGeneration||owner.dataGeneration!==owner.generation||owner.sourceFingerprint!==manifest.sourceFingerprint||owner.source?.kind!=='pack'||owner.source.root!==manifest.source.root||owner.packFiles!==manifest.packFiles)return fallback;
    }catch{return fallback;}
  }
  const immutable=['pack', 'prepared'].includes(manifest.source.kind)||manifest.dataSnapshot===true;
  const dataRoot = immutable ? path.join(dataGeneration, 'data') : manifest.source.root;
  if (process.env.DEKARON_DATA && path.resolve(process.env.DEKARON_DATA) !== path.resolve(dataRoot) && (manifest.source.kind === 'prepared' || path.resolve(process.env.DEKARON_DATA) !== path.resolve(manifest.source.root))) return fallback;
  try {
    if (!safeCachePath(engine, gamedataRoot) || !safeCachePath(engine, path.join(generation, 'site-assets')) || (immutable && !safeCachePath(engine, path.join(dataRoot,'share/maplist.csv')))) return fallback;
  } catch { return fallback; }
  if (!fs.existsSync(gamedataRoot) || !fs.existsSync(path.join(dataRoot, 'share/maplist.csv'))) return fallback;
  const soundRoot=path.join(generation,'sound-assets');
  if(fs.existsSync(soundRoot)&&!safeCachePath(engine,soundRoot))return fallback;
  return { dataRoot, gamedataRoot, siteAssetRoot: path.join(generation, 'site-assets'), ...(fs.existsSync(soundRoot)?{looseSoundRoot:soundRoot}:{}), version: manifest.fingerprint, manifest };
}
