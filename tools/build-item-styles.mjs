#!/usr/bin/env node
// Dekaron Solo - per-weapon-style animation sets of every class (items system, docs/formats/items.md 4.2).
//
// classes.json carries the animation map of each class's STARTER weapon style only. Equipping another weapon
// type changes the stance (items.json equipment.weaponRules[code].style, the dual / shield / guard-arm combined
// styles 10, 14-18, 26-28), so the character needs that style's STAND / MOVE / ATTACK / DEFEAT / ... clips.
// This builder reads the same class action files (share/action/action/pc/<x>.act.<class>.dat) with the same
// lookup rules as tools/build-characters.mjs (weapon style -> style 1 -> style 0; own-folder clips first; only
// clips that exist on disk; ATTACK timings repaired from combo.csv) and writes
//   gamedata/items-styles.json  { classes: { <classIndex>: { styles: { <style>: anims }, combos: { <style>: steps } } } }
// where anims = { idle, idleAlt, walk, run, attack[], hit[], blocked[], block, guard, die, dieAlt, revive,
//                 knockdown, stun, sleep, speedFromRootMotion {walk, run} } (entries as classes.json anims).
//
// Usage: node tools/build-item-styles.mjs [--data <root>] [--out <dir>]
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { normPath, gamePathToData, parseActionDat, parseComboCSV } from './build-characters.mjs';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const arg = (k, d) => { const i = process.argv.indexOf(k); return i > 0 ? process.argv[i + 1] : d; };
const DATA = path.resolve(arg('--data', path.join(HERE, '../../data/unpacked/data')));
const OUT = path.resolve(arg('--out', path.join(HERE, '../gamedata')));

const FILES = new Map();
for (const top of ['anim', 'share']) {
  const abs = path.join(DATA, top);
  for (const rel of fs.readdirSync(abs, { recursive: true })) FILES.set(normPath(`${top}/${rel}`), path.join(abs, rel));
}
const has = k => !!k && FILES.has(normPath(k));
const read = k => { const a = FILES.get(normPath(k)); if (!a) throw new Error(`missing ${k}`); return fs.readFileSync(a); };

const anim = await import(pathToFileURL(path.join(HERE, '../src/formats/anim.js')).href).catch(() => null);
const classesJson = JSON.parse(fs.readFileSync(path.join(OUT, 'classes.json'), 'utf8'));
const itemsJson = JSON.parse(fs.readFileSync(path.join(OUT, 'items.json'), 'utf8'));
const combos = parseComboCSV(read('share/combo/combo.csv'));
const E = itemsJson.equipment;
const EXTRA_STYLES = [1, 10, 14, 15, 16, 17, 18, 26, 27, 28];

const fraction = (v, alt) => {
  if (v >= 0 && v <= 1.0001) return { v };
  if (alt !== undefined && alt >= 0 && alt <= 1) return { v: alt, raw: v, how: 'combo.csv' };
  return { v: Math.min(1, Math.max(0, v || 0)), raw: v, how: 'clamped' };
};

const out = { version: 1, generatedBy: 'tools/build-item-styles.mjs', generatedAt: new Date().toISOString(),
  what: 'per-class, per-weapon-style animation maps (same rules as classes.json anims) for equipped weapons', classes: {} };
let nStyles = 0, problems = [];
for (const cls of classesJson.classes) {
  const ci = Number(cls.index);
  const actKey = cls.actionFile ? normPath(cls.actionFile) : null;
  if (!actKey || !has(actKey)) { problems.push(`class ${ci}: no action file ${actKey}`); continue; }
  const act = parseActionDat(read(actKey));
  const recs = act.records;
  const ownClip = x => !cls.animDir || gamePathToData('anim', x.anim).startsWith(cls.animDir + '/');
  const findRec = (styles, action, index) => {
    for (const own of [true, false]) for (const s of styles) {
      const r = recs.find(x => x.style === s && x.action === action && x.index === index && x.anim && (!own || ownClip(x)) && has(gamePathToData('anim', x.anim)));
      if (r) return r;
    }
    return null;
  };
  const animRef = (r) => {
    const key = gamePathToData('anim', r.anim);
    const cmb = r.action === 6 ? combos.get(`${ci}:${r.style}`)?.[r.index] : undefined;
    const t1 = fraction(r.timing, cmb?.timing), t2 = fraction(r.timing2, cmb?.timing2);
    return {
      anim: key, action: r.actionName, style: r.style, index: r.index, timeLength: +r.timeLength.toFixed(4),
      startInter: +r.startInter.toFixed(3), endInter: +r.endInter.toFixed(3),
      ...(t1.v ? { timing: +t1.v.toFixed(4) } : {}), ...(t2.v ? { timing2: +t2.v.toFixed(4) } : {}),
      ...(r.swing ? { swing: r.swing } : {}), ...(r.strike ? { strike: r.strike } : {}), ...(r.split ? { split: r.split } : {}),
      ...(r.freeze ? { freeze: +r.freeze.toFixed(4) } : {}), ...(r.effect ? { effect: r.effect } : {}),
      ...(r.cancelTime ? { cancelTime: r.cancelTime } : {}),
    };
  };
  const present = new Set(recs.filter(r => r.action === 1 || r.action === 6).map(r => r.style));
  const want = new Set([...(E.classStyles[ci] || []), ...EXTRA_STYLES].filter(s => present.has(s)));
  const C = { styles: {}, combos: {} };
  for (const style of [...want].sort((a, b) => a - b)) {
    if (style === 0) continue;
    const W = [style, 1, 0];
    const A = {};
    const setA = (name, styles, action, index) => {
      const r = findRec(styles, action, index);
      if (!r) return;
      A[name] = animRef(r);
      if (r.style !== styles[0]) A[name].fallbackFromStyle = styles[0];
    };
    setA('idle', W, 1, 0); setA('idleAlt', W, 1, 1); setA('walk', W, 2, 0); setA('run', W, 2, 1);
    setA('swimIdle', W, 26, 0); setA('swimIdleCombat', W, 26, 1);
    setA('swimWalk', W, 28, 0); setA('swimRun', W, 28, 1);
    setA('die', [style, 0, 1], 8, 0); setA('dieAlt', [style, 0, 1], 8, 1); setA('revive', [style, 0, 1], 11, 0);
    setA('knockdown', [style, 0, 1], 38, 0); setA('stun', [style, 0, 1], 41, 0); setA('sleep', [style, 0, 1], 43, 0);
    setA('block', W, 12, 0); setA('guard', W, 14, 0);
    const listOf = (action, styles) => {
      for (const s of styles) {
        const ok = recs.filter(r => r.style === s && r.action === action && r.anim && has(gamePathToData('anim', r.anim))).sort((a, b) => a.index - b.index);
        if (ok.length) return ok.map(animRef);
      }
      return [];
    };
    A.attack = listOf(6, W);
    A.hit = listOf(7, W);
    A.blocked = listOf(13, W);
    // own ATTACK clips of this exact style decide whether the class can really use it (else fallback style)
    A.hasOwnAttack = recs.some(r => r.style === style && r.action === 6 && r.anim && has(gamePathToData('anim', r.anim)));
    const sfr = {};
    if (anim?.parseAnim && anim?.sampleRootMotion) {
      for (const nm of ['walk', 'run']) {
        const a = A[nm];
        if (!a) continue;
        try {
          const rm = anim.sampleRootMotion(anim.parseAnim(read(a.anim)), 1);
          a.rootMotion = rm.map(v => +v.toFixed(4));
          if (a.timeLength > 0) sfr[nm] = +(Math.hypot(rm[0], rm[2]) / a.timeLength).toFixed(3);
        } catch (e) { problems.push(`class ${ci} style ${style} ${nm}: ${e.message}`); }
      }
    }
    A.speedFromRootMotion = sfr;
    C.styles[style] = A;
    const cmb = combos.get(`${ci}:${style}`);
    if (cmb) C.combos[style] = cmb;
    nStyles++;
  }
  out.classes[ci] = C;
}
out.counts = { classes: Object.keys(out.classes).length, styles: nStyles };
out.problems = problems;
fs.writeFileSync(path.join(OUT, 'items-styles.json'), JSON.stringify(out));
console.log(`items-styles.json: ${out.counts.classes} classes, ${nStyles} styles, ${problems.length} problems`);
for (const p of problems.slice(0, 20)) console.log('  ', p);
