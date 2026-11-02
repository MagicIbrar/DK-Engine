#!/usr/bin/env node
// Detect Global source updates, extract known packs, and publish only a complete staged generation.
import fs from 'node:fs/promises';
import path from 'node:path';
import { createHash, randomBytes } from 'node:crypto';
import { spawn } from 'node:child_process';
import os from 'node:os';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { inspectPack, extractPack } from './client-pack.mjs';
import {inspectGlobalCompatibility,assertGlobalCompatibility} from './client-compatibility.mjs';

const ENGINE = fileURLToPath(new URL('../', import.meta.url));
const hash = value => createHash('sha256').update(value).digest('hex');
const exists = async file => !!await fs.stat(file).catch(() => null);
const PIPELINE = 1;
const STEPS = ['characters', 'monsters', 'items', 'skills', 'skills-runtime', 'characters', 'quests', 'shops', 'boxes', 'dungeons', 'events', 'events-ui', 'channels', 'dungeon-uifx', 'item-styles', 'mounts', 'frontend', 'sound', 'life', 'gmcommands', 'server-lists'];
// Repo files a builder imports from outside tools/build-*.mjs and src/formats: they change a builder's output, so the change detection hashes them too.
// (tools/test-prepare-inputs-covered.mjs walks the builders' imports and fails when a file is missing here.)
export const EXTRA_INPUTS = ['server/world/channel-data.mjs', 'src/systems/channels/channel-rules.js', 'src/game/effect-body.js', 'tools/transform-compatibility.mjs', 'tools/effect-unit-recovery.mjs', 'src/systems/quests/reward-text.js', 'tools/lib/siege-renew-deploy-mask.mjs', 'tools/lib/siege-sentry-results.mjs', 'src/game/siege-renew-deploy-mask.js', 'src/game/effect-path-repairs.js', 'src/config/engine-chosen-dead-island.js', 'tools/asset-ref-resolve.mjs', 'tools/lib/authored-animation-key.mjs', 'src/game/global-attack-class.js', 'src/world/map-folder-bindings.js', 'src/world/legacy-maps.js'];

// ---- running the builders in parallel (2.2.3). A job is one builder run; STEPS is the old one-after-another order, which stays the tie-break
// and the whole order when only one job may run (DEKARON_PREPARE_JOBS=1). JOB_AFTER lists, per job, the earlier jobs it has to wait for: the
// generated files it reads or rewrites, or that an earlier job read before this one replaced them. Measured by tracing every file access of the
// real builders on real game data (read / write / directory listing; one run, 21 builder processes): any pair not listed shares no generated file.
// The result of a parallel run is compared byte for byte with the sequential one (JSON time stamps aside) before each release.
export const JOBS = (() => {
  const seen = {};
  return [...STEPS, 'site-art'].map(step => { seen[step] = (seen[step] || 0) + 1; return { id: seen[step] === 1 ? step : `${step}-${seen[step]}`, step }; });
})();
export const JOB_AFTER = {
  'skills-runtime': ['characters', 'skills'],
  'characters-2': ['characters', 'skills-runtime'],
  quests: ['monsters'],
  shops: ['monsters'],
  boxes: ['monsters', 'shops'],
  dungeons: ['monsters'],
  'events-ui': ['dungeons', 'events'],
  'item-styles': ['characters-2', 'items'],
  mounts: ['items'],
  frontend: ['items'],
  sound: ['monsters'],
  life: ['characters-2', 'items'],
  gmcommands: ['characters-2', 'monsters', 'skills', 'quests'],
};
// Seconds each builder took on the development PC (sequential run): only used to start the longest chains first.
const JOB_COST = { characters: 38, monsters: 63, items: 72, skills: 32, 'skills-runtime': 1, 'characters-2': 25, quests: 8, shops: 4, boxes: 2, dungeons: 19, events: 22, 'events-ui': 4, channels: 1, 'dungeon-uifx': 2, 'item-styles': 7, mounts: 3, frontend: 1, sound: 4, life: 2, gmcommands: 8, 'site-art': 1 };

/** How many builders may run at once: DEKARON_PREPARE_JOBS (1 = the old order, at most 16), else the CPU count minus one, 1..4 (at most 2 under 6 GiB of RAM:
 *  four builders at once peaked at 3.8 GB of working set on the development PC). */
export function prepareJobLimit(env = process.env, cpus = os.availableParallelism?.() ?? os.cpus().length, memory = os.totalmem()) {
  const asked = Number.parseInt(env.DEKARON_PREPARE_JOBS, 10);
  if (Number.isInteger(asked) && asked >= 1) return Math.min(16, asked);
  const byCpu = Math.max(1, Math.min(4, cpus - 1));
  return memory < 6 * 1024 ** 3 ? Math.min(byCpu, 2) : byCpu;
}

/**
 * Run jobs (objects with a unique id) with at most `limit` at a time, each only after the jobs it depends on finished (`after[id]`).
 * `run(job, signal)` does the work. On the first failure no new job starts, the signal given to the running ones is aborted and ALL of them are
 * waited for before the failure is thrown (the caller removes the staging folder next: no builder may still be writing into it).
 * limit 1 keeps the order of `jobs`; otherwise ready jobs start longest chain first.
 */
export async function runJobs(jobs, run, { limit = 1, after = {}, cost = {}, signal } = {}) {
  const byId = new Map(jobs.map(job => [job.id, job]));
  if (byId.size !== jobs.length) throw new Error('Duplicate preparation job id.');
  for (const job of jobs) for (const dep of after[job.id] || []) if (!byId.has(dep)) throw new Error(`Preparation job ${job.id} waits for unknown job ${dep}.`);
  const order = new Map(jobs.map((job, index) => [job.id, index]));
  const later = new Map(jobs.map(job => [job.id, []]));
  for (const job of jobs) for (const dep of after[job.id] || []) { if (order.get(dep) >= order.get(job.id)) throw new Error(`Preparation job ${job.id} waits for ${dep}, which is not earlier in the order.`); later.get(dep).push(job.id); }
  const tail = new Map();
  for (const job of [...jobs].reverse()) tail.set(job.id, (cost[job.id] || 1) + Math.max(0, ...later.get(job.id).map(id => tail.get(id))));
  const abort = new AbortController(), done = new Set(), running = new Map(), pending = [...jobs], failures = [];
  const onAbort = () => abort.abort();
  signal?.addEventListener('abort', onAbort, { once: true });
  if (signal?.aborted) abort.abort();
  const start = job => {
    pending.splice(pending.indexOf(job), 1);
    running.set(job.id, Promise.resolve().then(() => run(job, abort.signal)).then(() => { done.add(job.id); }, error => { failures.push(error); abort.abort(); }).finally(() => running.delete(job.id)));
  };
  try {
    for (;;) {
      if (!abort.signal.aborted) {
        const ready = pending.filter(job => (after[job.id] || []).every(dep => done.has(dep)));
        if (limit > 1) ready.sort((a, b) => tail.get(b.id) - tail.get(a.id) || order.get(a.id) - order.get(b.id));
        for (const job of ready) { if (running.size >= Math.max(1, limit)) break; start(job); }
      }
      if (!running.size) break;
      await Promise.race(running.values());
    }
  } finally { signal?.removeEventListener('abort', onAbort); }
  if (failures.length) throw failures[0];
  if (abort.signal.aborted) throw new Error('Client preparation cancelled.');
  if (pending.length) throw new Error(`Preparation jobs could not start: ${pending.map(job => job.id).join(', ')}.`);
}
const REQUIRED = ['classes.json', 'exp.json', 'monsters.json', 'npcs.json', 'items.json', 'items-looks.json', 'skills/index.json', 'quests.json', 'shops.json', 'dshop.json', 'dungeons_travel.json', 'gmcommands.json', 'sound.json', 'frontend.json'];

async function contained(root, target) {
  const realRoot = await fs.realpath(root), absolute = path.resolve(target);
  if (absolute !== realRoot && !absolute.startsWith(realRoot + path.sep)) throw new Error('Preparation target escaped the engine directory.');
  let current = realRoot;
  for (const part of path.relative(realRoot, absolute).split(path.sep).filter(Boolean)) {
    current = path.join(current, part);
    const stat = await fs.lstat(current).catch(err => { if (err.code === 'ENOENT') return null; throw err; });
    if (!stat) break;
    if (stat.isSymbolicLink()) throw new Error(`Preparation rejects a symlink/junction: ${current}`);
    const resolved = await fs.realpath(current);
    if (resolved !== realRoot && !resolved.startsWith(realRoot + path.sep)) throw new Error('Resolved preparation target escaped the engine directory.');
  }
}

export async function discoverSource(engine = ENGINE, explicit = process.env.DEKARON_DATA) {
  const root = path.resolve(engine, '..'), data = path.join(root, 'data');
  if (explicit) {
    const target = path.resolve(explicit);
    // An isolated engine can read a pristine packed reference without copying or changing its installation.
    if (await exists(path.join(target, 'pack.hdr'))) return {kind:'pack',root:target};
    if (!await exists(path.join(target, 'share/maplist.csv'))) throw new Error(`DEKARON_DATA is not a supported loose data root: ${target}`);
    return { kind: 'loose', root: target };
  }
  if (await exists(path.join(data, 'share/maplist.csv'))) return { kind: 'loose', root: data };
  // Packed updates outrank stale extraction. Extraction is private to this engine generation.
  if (await exists(path.join(data, 'pack.hdr'))) return { kind: 'pack', root: data };
  for (const candidate of [path.join(data, 'unpacked/data'), path.join(data, 'data')]) if (await exists(path.join(candidate, 'share/maplist.csv'))) return { kind: 'loose', root: candidate };
  throw new Error('No supported Global data found. Keep engine beside data and bin; expected data/pack.hdr + pack.dNN or loose share/maplist.csv.');
}

async function files(root, { content = false, optional = false } = {}) {
  if (!await exists(root)) { if (optional) return []; throw new Error(`Missing source directory: ${root}`); }
  const result = [], directories = [''];
  while (directories.length) {
    const rel = directories.pop(), entries = await fs.readdir(path.join(root, rel), { withFileTypes: true });
    for (const entry of entries) {
      const name = rel ? `${rel}/${entry.name}` : entry.name;
      if (entry.isSymbolicLink()) throw new Error(`Source symlinks are unsupported: ${path.join(root, name)}`);
      if (entry.isDirectory()) directories.push(name);
      else if (entry.isFile()) result.push(name);
    }
  }
  result.sort();
  const rows = new Array(result.length); let cursor = 0;
  await Promise.all(Array.from({ length: 32 }, async () => {
    while (cursor < result.length) {
      const index = cursor++, name = result[index], file = path.join(root, name), stat = await fs.stat(file, { bigint: true });
      rows[index] = [name, String(stat.size), String(stat.mtimeNs), String(stat.ctimeNs), content ? hash(await fs.readFile(file)) : ''];
    }
  }));
  return rows;
}

async function fingerprint(engine, source, pack, signature = '') {
  const inputs = source.kind === 'pack' ? [...pack.packs].map(([name, stat]) => [name, stat.size, stat.mtimeMs, stat.ctimeMs]).sort() : await files(source.root);
  const looseSound=source.kind==='pack'?await files(path.join(source.root,'sound'),{optional:true}):[];
  const tools = [];
  for (const name of [...new Set(STEPS.map(s => `build-${s}.mjs`)), 'prepare-client.mjs', 'client-pack.mjs', 'client-compatibility.mjs']) {
    const file = path.join(engine, 'tools', name);
    if (await exists(file)) tools.push([name, hash(await fs.readFile(file))]);
  }
  const formats = await files(path.join(engine, 'src/formats'), { content: true, optional: true });
  const overrides = await files(path.join(engine, 'gamedata-overrides'), { content: true, optional: true });
  const art = path.join(engine, 'site/assets/build-art.mjs');
  const extras = [];
  for (const rel of EXTRA_INPUTS) { const file = path.join(engine, rel); if (await exists(file)) extras.push([rel, hash(await fs.readFile(file))]); }
  return hash(JSON.stringify({ pipeline: PIPELINE, source, header: pack && hash(pack.header), inputs, looseSound, tools, formats, overrides, art: await exists(art) ? hash(await fs.readFile(art)) : null, extras, signature }));
}

function sourceFingerprint(source, pack) {
  if (!pack) return null;
  return hash(JSON.stringify({ source, header: hash(pack.header), packs: [...pack.packs].map(([name, stat]) => [name, stat.size, stat.mtimeMs, stat.ctimeMs]).sort() }));
}

function generationPath(engine, value) {
  if (typeof value !== 'string' || !/^\.client-cache\/generations\/[a-zA-Z0-9_-]+$/.test(value)) return null;
  return path.resolve(engine, value);
}

async function reusableData(engine, current, selected, pack, sourceStamp, {auditFiles=true}={}) {
  if (!pack || !sourceStamp || current?.version!==1 || current.pipeline!==PIPELINE || current.sourceFingerprint !== sourceStamp || !selected) return null;
  try {
    await contained(engine, path.join(selected, 'manifest.json'));
    const local = JSON.parse(await fs.readFile(path.join(selected, 'manifest.json'), 'utf8'));
    if (JSON.stringify(local) !== JSON.stringify(current)) return null;
    const owner = generationPath(engine, current.dataGeneration);
    if (!owner) return null;
    await contained(engine, path.join(owner, 'manifest.json'));
    const original = JSON.parse(await fs.readFile(path.join(owner, 'manifest.json'), 'utf8'));
    if (original.generation !== current.dataGeneration || original.dataGeneration !== original.generation || original.sourceFingerprint !== sourceStamp || original.source?.kind !== 'pack' || original.source.root !== current.source?.root || original.packFiles !== pack.entries.length) return null;
    const dataRoot = path.join(owner, 'data');
    await contained(engine, dataRoot);
    await contained(engine,path.join(dataRoot,'share/maplist.csv'));
    if(!await exists(path.join(dataRoot,'share/maplist.csv')))return null;
    // PREPARE-PREFER-PACK: the pack is the source of truth. An extraction is reused only while every file still equals the bytes
    // extracted from the pack (extract-index.json, written at extraction). Files copied in later (e.g. an older generation's
    // stringtables merged over the extraction) fail this check and force a fresh extraction, so the pack copy wins.
    const indexFile=path.join(owner,'extract-index.json');await contained(engine,indexFile);
    let index;try{index=JSON.parse(await fs.readFile(indexFile,'utf8'));}catch{return null;}
    if(index?.version!==1||index.packHeader!==hash(pack.header)||!index.files||Object.keys(index.files).length!==pack.entries.length)return null;
    // Warm path (auditFiles=false): authenticate only indexed paths via stat — never readdir the extraction tree
    // (tools/test-prepare-client-reuse.mjs monkeypatches readdir to prove warm launch stays manifest-only).
    let extracted;
    if (auditFiles) {
      extracted = new Map((await files(dataRoot,{content:true})).map(([rel, size, mtimeNs, , sha]) => [rel, {size:Number(size),mtimeNs,sha}]));
      if (extracted.size !== pack.entries.length) return null;
    } else {
      extracted = new Map();
      for (const entry of pack.entries) {
        const want = index.files[entry.rel];
        if (!want || want.size !== entry.size) return null;
        const file = path.join(dataRoot, entry.rel);
        await contained(engine, file);
        let stat; try { stat = await fs.stat(file, { bigint: true }); } catch { return null; }
        if (Number(stat.size) !== entry.size) return null;
        extracted.set(entry.rel, { size: Number(stat.size), mtimeNs: String(stat.mtimeNs), sha: '' });
      }
      if (extracted.size !== pack.entries.length) return null;
    }
    for(const entry of pack.entries){
      const f=extracted.get(entry.rel),want=index.files[entry.rel];
      if(!f||!want||f.size!==entry.size||want.size!==entry.size)return null;
      if(auditFiles?f.sha!==want.sha:f.mtimeNs!==want.mtimeNs)return null;   // warm path: any rewrite changes mtime; full audit: content
    }
    return { dataRoot, dataGeneration: current.dataGeneration };
  } catch { return null; }
}

async function copyJSON(source, target) {
  if (!await exists(source)) return;
  for (const [rel] of await files(source)) {
    if (!/\.json$/i.test(rel)) continue;
    const destination = path.join(target, rel); await fs.mkdir(path.dirname(destination), { recursive: true });
    await fs.copyFile(path.join(source, rel), destination);
  }
}
async function validate(root, required) {
  for (const file of required) if (!await exists(path.join(root, file))) throw new Error(`Preparation did not produce ${file}.`);
  for (const [rel] of await files(root)) if (/\.json$/i.test(rel)) JSON.parse(await fs.readFile(path.join(root, rel), 'utf8'));
}

// A quiet parser still needs visible liveness; stdout is not a progress clock.
export async function runBuilder(tool, args, { engine, env, step, log = console.log, heartbeatMs = 15000, timeoutMs = 30 * 60 * 1000, signal } = {}) {
  if (signal?.aborted) throw new Error('Client preparation cancelled.');
  return new Promise((resolve, reject) => {
    const child = spawn(process.execPath, [tool, ...args], { cwd: engine, env, windowsHide: true, stdio: ['ignore', 'pipe', 'pipe'] });
    const started = Date.now(); let tail = '', stopped = null;
    const stop = reason => {
      if (stopped) return;
      stopped = reason;
      // Builders are Node processes; terminate before staging is cleaned up.
      child.kill('SIGKILL');
    };
    const cancel = () => stop('Client preparation cancelled.');
    signal?.addEventListener('abort', cancel, { once: true });
    const heartbeat = setInterval(() => log(`${step} is still parsing... ${Math.floor((Date.now() - started) / 1000)} seconds elapsed. Please keep this window open.`), heartbeatMs);
    const watchdog = setTimeout(() => stop(`${step} exceeded ${Math.round(timeoutMs / 60000)} minutes. Preparation stopped; previous generation preserved. Retry and send the preparation log if this repeats.`), timeoutMs);
    const cleanup = () => { clearInterval(heartbeat); clearTimeout(watchdog); signal?.removeEventListener('abort', cancel); };
    const output = bytes => { tail = (tail + bytes.toString()).slice(-5000); };
    child.stdout.on('data', output); child.stderr.on('data', output);
    child.once('error', error => { cleanup(); reject(error); });
    child.once('close', code => {
      cleanup();
      if (stopped) reject(new Error(`${stopped}\n${tail}`));
      else if (code !== 0) reject(new Error(`${path.basename(tool)} failed (${code}). Previous generation preserved.\n${tail}`));
      else resolve({ code, tail });
    });
  });
}

export async function buildClient({ engine, dataRoot, gamedataRoot, log = console.log, signal }) {
  const characterTables = ['share/pc/pcclass.csv', 'share/formula.ini', 'share/formulaex.ini', 'share/combo/combo.csv', 'share/item/itemweapon.csv', 'share/creature/remote.csv', 'share/skill/status.csv', 'share/arrange/location.csv', 'share/pc/startpoint.csv', 'share/pc/exp.csv', 'share/pc/levelcap.csv', 'share/pc/addexp.csv', 'share/pc/statmaxvalue.csv'];
  const missing = [];
  for (const table of characterTables) if (!await exists(path.join(dataRoot, table))) missing.push(table);
  if (missing.length) throw new Error(`This client data is missing tables required by the character builder: ${missing.join(', ')}. Check that the complete client data was extracted. Older GameHi editions may use different formats; compatibility cannot be determined from the folder names alone.`);
  const env = { ...process.env, DEKARON_DATA: dataRoot, DEKARON_GAMEDATA: gamedataRoot, DEKARON_SITE_ASSETS: path.join(path.dirname(gamedataRoot), 'site-assets'), DEKARON_LOOSE_SOUND_ROOT:path.join(path.dirname(gamedataRoot),'sound-assets') };
  const limit = prepareJobLimit();
  if (limit > 1) log(`Running up to ${limit} builders at a time (set DEKARON_PREPARE_JOBS=1 for one after another).`);
  await runJobs(JOBS, async ({ step }, jobSignal) => {
    const tool = step === 'site-art' ? path.join(engine, 'site/assets/build-art.mjs') : path.join(engine, 'tools', `build-${step}.mjs`);
    const args = [tool, '--data', dataRoot, '--out', step === 'mounts' ? path.join(gamedataRoot, 'mounts.json') : gamedataRoot, '--gamedata', gamedataRoot];
    log(`Preparing ${step}...`);
    await runBuilder(tool, args.slice(1), { engine, env, step, log, signal: jobSignal });
    log(`Prepared ${step}.`);
  }, { limit, after: JOB_AFTER, cost: JOB_COST, signal });
}

export async function prepareClient({ engine = ENGINE, data, check = false, force = false, build = buildClient, compatibility = build === buildClient ? inspectGlobalCompatibility : null, required = REQUIRED, signature = '', log = console.log, signal } = {}) {
  engine = path.resolve(engine);
  if ((await fs.lstat(engine)).isSymbolicLink()) throw new Error('Preparation engine directory cannot be a symlink/junction.');
  engine = await fs.realpath(engine);
  const cache = path.join(engine, '.client-cache'), generations = path.join(cache, 'generations'), pointer = path.join(cache, 'current.json');
  await contained(engine, generations); await contained(engine, pointer); await contained(engine, path.join(cache, 'prepare.lock'));
  const source = await discoverSource(engine, data), pack = source.kind === 'pack' ? await inspectPack(source.root) : null;
  if(source.kind==='loose'){
    const sourceRoot=await fs.realpath(source.root),relative=path.relative(sourceRoot,engine);
    if(!relative||!relative.startsWith('..'+path.sep)&&relative!=='..'&&!path.isAbsolute(relative))throw new Error('Loose source contains the engine; source and preparation targets must not overlap.');
    for(let at=path.resolve(source.root);;){if((await fs.lstat(at)).isSymbolicLink())throw new Error('Loose source symlinks/junctions are unsupported.');const parent=path.dirname(at);if(parent===at)break;at=parent;}
  }
  const stamp = await fingerprint(engine, source, pack, signature);
  const sourceStamp = sourceFingerprint(source, pack);
  let current; try { current = JSON.parse(await fs.readFile(pointer, 'utf8')); } catch { current = null; }
  const selected = generationPath(engine,current?.generation);
  if (selected) await contained(engine, selected);
  let usable = selected && selected.startsWith(generations + path.sep) && await exists(path.join(selected, 'gamedata'));
  if(usable){
    await contained(engine,path.join(selected,'gamedata'));await contained(engine,path.join(selected,'site-assets'));
    if(!await exists(path.join(selected,'site-assets')))usable=false;
  }
  if (usable) for (const file of required) {
    const target=path.join(selected,'gamedata',file);await contained(engine,target);
    if(!await exists(target)){usable=false;break;}
    try{JSON.parse(await fs.readFile(target,'utf8'));}catch{usable=false;break;}
  }
  if(usable&&source.kind==='loose'){
    // Older loose generations reference mutable originals; migrate before
    // claiming that both raw assets and compiled indexes can be rolled back.
    if(current?.dataSnapshot!==true)usable=false;
    else try{
      const local=path.join(selected,'manifest.json'),raw=path.join(selected,'data/share/maplist.csv');
      await contained(engine,local);await contained(engine,raw);
      if(!await exists(raw)||JSON.stringify(JSON.parse(await fs.readFile(local,'utf8')))!==JSON.stringify(current))usable=false;
    }catch{usable=false;}
  }
  const unchangedCandidate=!force&&usable&&current?.fingerprint===stamp;
  // Completed extraction is immutable. Warm launch authenticates ownership and required paths;
  // changed builders and explicit repairs additionally audit all extracted filenames/sizes.
  const reuse = selected ? await reusableData(engine,current,selected,pack,sourceStamp,{auditFiles:!unchangedCandidate}) : null;
  if(pack&&usable&&!reuse)usable=false;
  const needsBuild=force||!usable||current?.fingerprint!==stamp;
  const summary = { source, fingerprint: stamp, sourceFingerprint: sourceStamp, changed:needsBuild, reuseData:!!reuse, extractionAudit:pack?(reuse?(unchangedCandidate?'manifest':'full'):'none'):'none', packFiles: pack?.entries.length || 0, extractedBytes: pack?.bytes || 0, generation: usable ? selected : null };
  if (check) { log(JSON.stringify(summary, null, 2)); return summary; }
  if (!needsBuild) { log('Client source unchanged; using the prepared generation.'); return summary; }
  await fs.mkdir(generations, { recursive: true });
  const lockPath = path.join(cache, 'prepare.lock');
  let lock;
  try { lock = await fs.open(lockPath, 'wx'); }
  catch (err) {
    if (err.code !== 'EEXIST') throw err;
    let old; try { old = JSON.parse(await fs.readFile(lockPath, 'utf8')); } catch { throw new Error('Preparation lock is unreadable; another preparation may be active.'); }
    let alive = false; try { process.kill(old.pid, 0); alive = true; } catch (e) { if (e.code !== 'ESRCH') alive = true; }
    if (alive) throw new Error('Another client preparation is already running.');
    await fs.unlink(lockPath); lock = await fs.open(lockPath, 'wx');
  }
  await lock.writeFile(JSON.stringify({ pid: process.pid, started: Date.now() }));
  const stage = path.join(generations, `${Date.now()}-${randomBytes(4).toString('hex')}`);
  await contained(engine, stage);
  try {
    const gamedataRoot = path.join(stage, 'gamedata'); await fs.mkdir(gamedataRoot, { recursive: true });
    await fs.mkdir(path.join(stage, 'site-assets'), { recursive: true });
    // No generated indexes are required in the distribution; builders recreate every index from the owner's client.
    let dataRoot = source.root;
    if (pack && reuse) {
      dataRoot=reuse.dataRoot;
      log('Original packs unchanged; reusing the validated extracted data while rebuilding indexes.');
    } else if (pack) {
      dataRoot = path.join(stage, 'data'); let last = 0;
      log(`Extracting ${pack.entries.length} files (${(pack.bytes / 1024 ** 3).toFixed(2)} GiB) from original packs; originals stay in place.`);
      const digests=new Map();
      await extractPack(pack, dataRoot, (done, total) => { if (Date.now() - last > 10000 || done === total) { last = Date.now(); log(`Extracted ${done}/${total} files.`); } }, digests);
      const stats=new Map((await files(dataRoot)).map(([rel,size,mtimeNs])=>[rel,{size:Number(size),mtimeNs}]));
      const index={version:1,packHeader:hash(pack.header),files:Object.fromEntries(pack.entries.map(e=>[e.rel,{size:e.size,sha:digests.get(e.rel),mtimeNs:stats.get(e.rel)?.mtimeNs}]))};
      await fs.writeFile(path.join(stage,'extract-index.json'),JSON.stringify(index));
    } else {
      // Loose clients need the same immutable raw-data boundary as packed
      // clients. Builders must never read a changing external source in place.
      const before=await files(source.root);dataRoot=path.join(stage,'data');
      log(`Copying ${before.length} original loose files into a private preparation snapshot; originals stay in place.`);
      await fs.cp(source.root,dataRoot,{recursive:true,force:false,errorOnExist:true,dereference:false});
      const copied=await files(dataRoot);
      if(JSON.stringify(before.map(row=>row.slice(0,2)))!==JSON.stringify(copied.map(row=>row.slice(0,2))))throw new Error('Loose source changed during snapshot copying. Previous generation preserved.');
    }
    if (signal?.aborted) throw new Error('Client preparation cancelled.');
    // Global ships BGM beside its packs too. Copy those bytes separately so the pack extraction stays reusable/immutable.
    if(pack&&await exists(path.join(source.root,'sound'))){await files(path.join(source.root,'sound'));await fs.cp(path.join(source.root,'sound'),path.join(stage,'sound-assets'),{recursive:true,force:false});}
    if(compatibility){
      const report=await compatibility({dataRoot});
      await fs.writeFile(path.join(stage,'compatibility.json'),JSON.stringify(report,null,2));
      // A failed attempt remains diagnosable even when its incomplete stage is removed.
      await contained(engine,path.join(cache,'compatibility-last.json'));
      await fs.writeFile(path.join(cache,'compatibility-last.json'),JSON.stringify(report,null,2));
      assertGlobalCompatibility(report);
      log('Supported core Global structures detected; validating remaining formats through builders.');
    }
    await build({ engine, dataRoot, gamedataRoot, log, signal });
    // Explicit overrides are never rewritten by builders; each overrides the complete generated JSON file.
    await copyJSON(path.join(engine, 'gamedata-overrides'), gamedataRoot);
    await validate(gamedataRoot, required);
    const after = source.kind === 'pack' ? await inspectPack(source.root) : null;
    if (await fingerprint(engine, source, after, signature) !== stamp) throw new Error('Client files changed during preparation. Previous generation preserved; retry after the update finishes.');
    const generation=path.relative(engine,stage).replace(/\\/g,'/');
    const manifest = { version: 1, pipeline: PIPELINE, fingerprint: stamp, sourceFingerprint:sourceStamp, source, generation, ...(pack?{dataGeneration:reuse?.dataGeneration||generation}:{dataSnapshot:true}), prepared: new Date().toISOString(), packFiles: pack?.entries.length || 0 };
    const temporary = path.join(cache, `current-${randomBytes(4).toString('hex')}.tmp`);
    await fs.writeFile(path.join(stage, 'manifest.json'), JSON.stringify(manifest, null, 2));
    await fs.writeFile(temporary, JSON.stringify(manifest, null, 2)); await fs.rename(temporary, pointer);
    log('Client preparation complete. New files take effect on the next server start.');
    return { ...summary, generation: stage, manifest };
  } catch (err) {
    await contained(engine, stage);
    if (!path.resolve(stage).startsWith(path.resolve(generations) + path.sep)) throw new Error('Unsafe staging cleanup path.');
    await fs.rm(stage, { recursive: true, force: true });
    throw err;
  } finally { await lock.close(); await fs.unlink(lockPath).catch(() => {}); }
}

if (process.argv[1] && pathToFileURL(path.resolve(process.argv[1])).href === import.meta.url) {
  const args = process.argv.slice(2), arg = name => { const i = args.indexOf(name); return i >= 0 ? args[i + 1] : undefined; };
  const controller = new AbortController();
  process.once('SIGINT', () => controller.abort()); process.once('SIGTERM', () => controller.abort());
  try { await prepareClient({ engine: arg('--engine'), data: arg('--data'), check: args.includes('--check'), force: args.includes('--force'), signal: controller.signal }); }
  catch (err) { console.error(`Client preparation failed: ${err.message}`); process.exitCode = 1; }
}
