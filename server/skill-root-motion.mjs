// Host preparation of the skill root-motion curves (src/systems/skills/root-motion.js). Reads the root-motion block of
// every clip of the 15 prepared class packs and every class basic-attack clip (all weapon stances) from the active Global
// data (read-only, header + tail only), once per
// process and data root, then fills the shared table the headless SkillEngine samples and serves each class's part
// to browsers as /gamedata/engine-root-motion/class_<c>.json (same asset gate as /gamedata/). ~2,464 files, ~2 s.
import fs from 'node:fs/promises';
import path from 'node:path';
import { parseAnimRootMotion } from '../src/formats/anim.js';
import { rootCurve, rootKey, rootMotionCurves, encodeRootCurves } from '../src/systems/skills/root-motion.js';

export const ROOT_MOTION_ROUTE = '/gamedata/engine-root-motion/';
const CLASS_COUNT = 15;
const READ_BATCH = 32;
const cache = new Map();

async function readRoot(dataRoot, key) {
  let handle;
  try {
    handle = await fs.open(path.join(dataRoot, key), 'r');
    const { size } = await handle.stat();
    const head = Buffer.alloc(24);
    await handle.read(head, 0, 24, 0);
    const tailOffset = head.readUInt32LE(16);
    if (!(tailOffset >= 24 && tailOffset <= size)) return null;
    // a buffer with the real tail at its real offset (the bytes between header and tail are never read)
    const buf = Buffer.alloc(size);
    head.copy(buf, 0, 0, 24);
    if (size > tailOffset) await handle.read(buf, tailOffset, size - tailOffset, tailOffset);
    return rootCurve(parseAnimRootMotion(buf));
  } catch (error) {
    if (error?.code !== 'ENOENT') console.warn('[skills] root motion unreadable', key, error?.message || error);
    return null;
  } finally { await handle?.close().catch(() => {}); }
}

/** {byClass: Map<classIndex, {anims: string[], json: string}>, curves: number, files: number, ms} for one data root. */
export function loadSkillRootMotion({ dataRoot, gamedataRoot, packs = null }) {
  const id = `${path.resolve(dataRoot)}|${path.resolve(gamedataRoot)}`;
  if (cache.has(id)) return cache.get(id);
  const job = (async () => {
    const began = performance.now();
    const classAnims = [];
    // basic-attack combo clips (classes.json anims.attack + every weapon stance of items-styles.json): the controller and
    // the host's normal attack move along them the same way (src/systems/skills/root-motion.js attackStepAnim)
    const readJSON = async name => { try { return JSON.parse(await fs.readFile(path.join(gamedataRoot, name), 'utf8')); } catch (error) { console.warn('[skills] root motion:', name, 'unavailable', error?.code || error?.message); return null; } };
    const [classesFile, stylesFile] = await Promise.all([readJSON('classes.json'), readJSON('items-styles.json')]);
    const classList = Array.isArray(classesFile?.classes) ? classesFile.classes : Object.values(classesFile?.classes || {});
    for (let c = 0; c < CLASS_COUNT; c++) {
      let pack = packs?.[c];
      if (!pack) {
        try { pack = JSON.parse(await fs.readFile(path.join(gamedataRoot, `skills/class_${c}.json`), 'utf8')); }
        catch (error) { console.warn('[skills] root motion: class pack unavailable', c, error?.code || error?.message); pack = null; }
      }
      const anims = new Set();
      for (const clip of pack?.class?.clips || []) if (clip?.anim) anims.add(rootKey(clip.anim));
      const base = classList.find(x => Number(x?.index) === c);
      for (const a of base?.anims?.attack || []) if (a?.anim) anims.add(rootKey(a.anim));
      for (const style of Object.values(stylesFile?.classes?.[c]?.styles || stylesFile?.classes?.[String(c)]?.styles || {}))
        for (const a of style?.attack || []) if (a?.anim) anims.add(rootKey(a.anim));
      classAnims.push([...anims]);
    }
    const all = [...new Set(classAnims.flat())], table = new Map();
    for (let i = 0; i < all.length; i += READ_BATCH) {
      const slice = all.slice(i, i + READ_BATCH);
      const curves = await Promise.all(slice.map(key => readRoot(dataRoot, key)));
      // A prepared generation owns its own curves, including absent clips. A second Global copy can use the same
      // animation name with different bytes; never reuse the process-wide browser/offline table as a host cache.
      slice.forEach((key, k) => { table.set(key, curves[k]); rootMotionCurves.set(key, curves[k]); });
    }
    const byClass = new Map();
    let moving = 0;
    classAnims.forEach((anims, c) => {
      const entries = anims.map(key => [key, table.get(key)]).filter(([, curve]) => curve);
      moving += entries.length;
      byClass.set(c, { anims, json: JSON.stringify({ version: 1, classIndex: c, curves: encodeRootCurves(entries) }) });
    });
    return { byClass, table, files: all.length, curves: moving, ms: Math.round(performance.now() - began) };
  })();
  cache.set(id, job);
  job.catch(() => cache.delete(id));
  return job;
}

/** HTTP: /gamedata/engine-root-motion/class_<c>.json. Returns true when it answered. */
export async function handleSkillRootMotion(req, res, pathname, roots) {
  if (!pathname.startsWith(ROOT_MOTION_ROUTE)) return false;
  const m = /^class_(\d{1,2})\.json$/.exec(pathname.slice(ROOT_MOTION_ROUTE.length));
  const c = m ? Number(m[1]) : -1;
  if (!['GET', 'HEAD'].includes(req.method) || !(c >= 0 && c < CLASS_COUNT)) { res.writeHead(404); res.end('not found'); return true; }
  try {
    const table = await loadSkillRootMotion(roots);
    const body = Buffer.from(table.byClass.get(c)?.json || JSON.stringify({ version: 1, classIndex: c, curves: {} }));
    res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8', 'Content-Length': body.length, 'Cache-Control': 'no-cache', 'X-Content-Type-Options': 'nosniff' });
    res.end(req.method === 'HEAD' ? undefined : body);
  } catch (error) {
    console.warn('[skills] root motion table failed', error?.message || error);
    res.writeHead(503, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store' });
    res.end(JSON.stringify({ error: 'Skill root motion is unavailable.' }));
  }
  return true;
}
