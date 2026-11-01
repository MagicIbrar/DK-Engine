// Stage only prepared game assets from a user-supplied, validated Global generation.
// External sources are never changed. Fresh installer-owned preparation may transfer its generated assets.
import fs from 'node:fs/promises';
import path from 'node:path';
import { createHash, randomUUID } from 'node:crypto';
import { clientSource } from '../server/client-source.mjs';

const ASSET_DIRS = ['data', 'gamedata', 'site-assets', 'sound-assets'];
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const isWithin = (root, target) => target === root || target.startsWith(root + path.sep);

// An ownership capability exists only after this module creates a brand-new preparation directory.
// A caller-supplied path/object cannot authorize moving an existing user folder.
const ownedPreparations=new WeakMap();
export async function createOwnedPreparation(destination){
 destination=path.resolve(destination);
 let current=path.dirname(destination);
 while(true){const st=await fs.lstat(current);if(st.isSymbolicLink())throw Error('Owned preparation refuses linked parents.');const parent=path.dirname(current);if(parent===current)break;current=parent;}
 destination=path.join(await fs.realpath(path.dirname(destination)),path.basename(destination));
 const root=destination+'.prepare-'+randomUUID();await fs.mkdir(root,{recursive:false});
 const capability=Object.freeze({root});ownedPreparations.set(capability,{root:await fs.realpath(root),destination});return capability;
}

async function inventory(root) {
  const result = { files: 0, bytes: 0 };
  const pending = [root];
  while (pending.length) {
    const dir = pending.pop();
    for (const entry of await fs.readdir(dir, { withFileTypes: true })) {
      const target = path.join(dir, entry.name);
      const stat = await fs.lstat(target);
      if (stat.isSymbolicLink()) throw Error(`Prepared assets contain a link: ${target}`);
      if (stat.isDirectory()) pending.push(target);
      else if (stat.isFile()) { result.files++; result.bytes += stat.size; }
      else throw Error(`Prepared assets contain an unsupported entry: ${target}`);
    }
  }
  return result;
}

async function copyDirectory(source, target, onFile) {
  await fs.cp(source, target, {
    recursive: true,
    force: false,
    errorOnExist: true,
    filter: async candidate => {
      const stat = await fs.lstat(candidate);
      if (stat.isSymbolicLink() || (!stat.isDirectory() && !stat.isFile())) throw Error(`Unsafe Global asset entry: ${candidate}`);
      if (stat.isFile()) onFile(stat.size);
      return true;
    },
  });
}

/**
 * Copy the active prepared Global assets into an installer-owned empty destination.
 * Call before the install staging directory is renamed into place. The returned
 * relative sourceEngine is suitable for dedicated-source.json in that directory.
 */
export async function stagePreparedGlobal({ sourceEngine, destinationEngine, onProgress = () => {}, ownedPreparation = null }) {
  if (!sourceEngine || !destinationEngine) throw Error('Choose a prepared Global engine and an install staging directory.');
  const sourceRoot = await fs.realpath(sourceEngine);
  const destinationRoot = await fs.realpath(destinationEngine);
  if (isWithin(sourceRoot, destinationRoot) || isWithin(destinationRoot, sourceRoot)) throw Error('The Global source and install staging directories must be separate.');
  let owner=null;
  if(ownedPreparation){
    owner=ownedPreparations.get(ownedPreparation);
    if(!owner||owner.root!==sourceRoot||path.dirname(destinationRoot)!==path.dirname(owner.destination)||!path.basename(destinationRoot).startsWith(path.basename(owner.destination)+'.staging-'))throw Error('Asset transfer requires the matching fresh owned preparation and its install staging sibling.');
    if((await fs.stat(sourceRoot)).dev!==(await fs.stat(destinationRoot)).dev)throw Error('Owned asset transfer requires the same filesystem.');
  }
  const active = clientSource(sourceRoot);
  if (!active.manifest || active.version === 'legacy') throw Error('The selected Global engine has no active prepared generation.');
  const roots = {
    data: active.dataRoot,
    gamedata: active.gamedataRoot,
    'site-assets': active.siteAssetRoot,
    'sound-assets': active.looseSoundRoot,
  };
  for (const required of ['data', 'gamedata', 'site-assets']) {
    if (!(await fs.stat(roots[required]).catch(() => null))?.isDirectory()) throw Error(`Prepared Global ${required} is missing.`);
  }
  for (const rel of ['share/maplist.csv']) {
    if (!(await fs.stat(path.join(roots.data, rel)).catch(() => null))?.isFile()) throw Error(`Prepared Global file is missing: ${rel}`);
  }
  const portableEngine = path.join(destinationRoot, 'global-prepared', 'engine');
  const generationName = `portable-${active.version.slice(0, 16)}`;
  const generationRelative = `.client-cache/generations/${generationName}`;
  const generation = path.join(portableEngine, '.client-cache', 'generations', generationName);
  if (await fs.lstat(generation).catch(() => null)) throw Error('The portable Global generation already exists in the staging directory.');
  const expected=new Map();
  for(const [dir,rel] of [['data','share/maplist.csv'],['gamedata','classes.json']])expected.set(dir+'/'+rel,hash(await fs.readFile(path.join(roots[dir],rel))));
  const counts={};
  const before = { files: 0, bytes: 0 };
  for (const name of ASSET_DIRS) {
    if (!roots[name]) continue;
    const count = await inventory(roots[name]);counts[name]=count;
    before.files += count.files;
    before.bytes += count.bytes;
  }
  onProgress({ phase: owner?'relocate':'copy', files: 0, bytes: 0, totalFiles: before.files, totalBytes: before.bytes });
  let queuedFiles = 0, queuedBytes = 0;
  const onFile = size => {
    queuedFiles++;
    queuedBytes += size;
    if (queuedFiles % 5000 === 0) onProgress({ phase: 'copy', files: queuedFiles, bytes: queuedBytes, totalFiles: before.files, totalBytes: before.bytes });
  };
  await fs.mkdir(generation, { recursive: true });
  let movedFiles=0,copiedFiles=0;
  for (const name of ASSET_DIRS) if (roots[name]) {
    const real=await fs.realpath(roots[name]);
    // Loose Global data may be external even during raw setup; that input remains copy-only.
    if(owner&&real!==sourceRoot&&isWithin(sourceRoot,real)){
      await fs.rename(roots[name],path.join(generation,name));movedFiles+=counts[name].files;
      queuedFiles+=counts[name].files;queuedBytes+=counts[name].bytes;
      onProgress({phase:'relocate',files:queuedFiles,bytes:queuedBytes,totalFiles:before.files,totalBytes:before.bytes});
    }else{await copyDirectory(roots[name],path.join(generation,name),onFile);copiedFiles+=counts[name].files;}
  }
  const after = await inventory(generation);
  if (before.files !== after.files || before.bytes !== after.bytes) throw Error('The staged Global file count or byte total changed during copying.');
  onProgress({ phase: 'verify', files: after.files, bytes: after.bytes, totalFiles: before.files, totalBytes: before.bytes });
  for (const [dir, rel] of [['data', 'share/maplist.csv'], ['gamedata', 'classes.json']]) {
    const copied = await fs.readFile(path.join(generation, dir, rel));
    if (expected.get(dir+'/'+rel) !== hash(copied)) throw Error(`The staged Global ${rel} differs from the source.`);
  }
  const manifest = {
    version: 1,
    pipeline: active.manifest.pipeline,
    fingerprint: active.version,
    ...(/^[a-f0-9]{64}$/.test(active.manifest.sourceFingerprint||'')?{sourceFingerprint:active.manifest.sourceFingerprint}:{}),
    source: { kind: 'prepared', root: generationRelative + '/data' },
    generation: generationRelative,
    prepared: active.manifest.prepared,
    portablePrepared: true,
    files: before.files,
    bytes: before.bytes,
  };
  await fs.writeFile(path.join(generation, 'manifest.json'), JSON.stringify(manifest, null, 2));
  const cache = path.join(portableEngine, '.client-cache');
  await fs.writeFile(path.join(cache, 'current.json'), JSON.stringify(manifest, null, 2));
  if (!clientSource(portableEngine).manifest) throw Error('The staged Global generation failed client validation.');
  return { sourceEngine: 'global-prepared/engine', files: before.files, bytes: before.bytes, fingerprint: active.version, movedFiles, copiedFiles };
}
