// Runtime packs of the skill data for the browser (src/systems/skills).
//
//   node tools/build-skills-runtime.mjs            (after tools/build-skills.mjs)
//
// The full tables (gamedata/skills.json 15 MB, skills_status.json 5.7 MB, skills_effects.json 16 MB) are too heavy to
// parse on every start. This splits them, without changing a single value, into
//   gamedata/skills/common.json      enums, option codes, aggro, random buffs, weapon statuses, status groups/icons,
//                                    damage text, model effects (combat/game/spell/status/pc action), every condition
//                                    (cate 11), hit (cate 6) and game (cate 5) effect scene + its units, the force
//                                    skills (share/item/force_skill.csv, decoded like the skill results), the group
//                                    skills (share/groupskill/skillgroup.csv), servant attack results (decoded)
//   gamedata/skills/class_<c>.json   one class: its class record (tabs, clips, skill actions ...), its skills, the
//                                    remotes / servants / totems / statuses they use (followed transitively) and every
//                                    effect scene + unit any of those reference.
// Anything a pack lacks (e.g. an item buff status of another table) is loaded lazily by the runtime from the full files.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { describeResult, csvObjects } from './build-skills.mjs';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(HERE, '..');
const arg = (key) => { const i = process.argv.indexOf(key); return i >= 0 ? process.argv[i + 1] : null; };
const GD = path.resolve(arg('--gamedata') || process.env.DEKARON_GAMEDATA || path.join(ROOT, 'gamedata'));
const DATA = path.resolve(arg('--data') || process.env.DEKARON_DATA || path.resolve(ROOT, '..', 'data', 'unpacked', 'data'));
const OUT = path.join(GD, 'skills');

const readJSON = f => JSON.parse(fs.readFileSync(path.join(GD, f), 'utf8'));
const t0 = Date.now();
const S = readJSON('skills.json');
const ST = readJSON('skills_status.json');
const E = readJSON('skills_effects.json');
console.log(`loaded in ${Date.now() - t0} ms`);

const remotesMap = new Map(Object.entries(S.remotes).map(([k, v]) => [Number(k), v]));
// skills.json holds only the remotes skills launch; servant attack blocks (Bregon's fireball 307, great 312 ...) use
// other rows of remote.csv, read here with the same row layout as tools/build-skills.mjs
{
  const n = v => (v === '' || v == null || !Number.isFinite(Number(v)) ? null : Number(v));
  const rows = csvObjects(fs.readFileSync(path.join(DATA, 'share/creature/remote.csv')), true).rows;
  for (const r of rows) {
    const i = n(r.Index);
    if (i === null || remotesMap.has(i)) continue;
    const rm = {
      index: i, description: r.Description, resultType: n(r.ResultType), maxDistance: n(r.MaxDistance), moveSpeed: n(r.MoveSpeed),
      size: n(r.Size), maxPiercing: n(r.MaxPiercingNum), piercingRate: n(r.MaxPiercingRate), hitCycleMs: n(r.HitCycle),
      lifetimeMs: n(r.EffectTime), // Native lifetime exists even when EffectID is zero.
      effect: { id: n(r.EffectID), scene: n(r.SceneID), timeMs: n(r.EffectTime) },
      contactEffect: { id: n(r.ContactEffectID), scene: n(r.ContactSceneID), timeMs: n(r.ContactEffectTime) },
      piercingEffect: { id: n(r.PiercingEffectID), scene: n(r.PiercingSceneID), timeMs: n(r.PiercingEffectTime) },
      warningEffect: n(r.WarningEffectID) ? { id: n(r.WarningEffectID), cate: n(r.WarningEffectCate), scene: n(r.WarningSceneID), timeMs: n(r.WarningEffectTime) } : null,
      hitStartDistance: n(r.fHitStartDistance), destroyWhenDie: n(r.bDestroyWhenDie), source: 'remote.csv (servant)',
    };
    for (const k of ['effect', 'contactEffect', 'piercingEffect']) if (!(rm[k]?.id > 0)) delete rm[k];
    if (rm.resultType) { try { rm.impact = describeResult(rm.resultType, [], null); } catch { /* raw only */ } }
    remotesMap.set(i, rm);
    S.remotes[i] = rm;
  }
}
const statusSet = new Map(Object.entries(ST.statuses).map(([k, v]) => [Number(k), v]));
const ctx = { remotes: remotesMap, statuses: statusSet };

// ------------------------------------------------------------------------------------------ reference walkers
const EFFECT_KEYS = new Set(['effect', 'hitEffect', 'contactEffect', 'piercingEffect', 'warningEffect', 'actionEffect',
  'enterEffect', 'statusEffect', 'leaveEffect', 'standEffect', 'dieEffect', 'endEffect', 'start', 'keep', 'end']);
const STATUS_KEYS = /^(statusIndex\d?|dotStatusIndex)$/;

/** Collect effect keys ("cate:id") and status indices referenced anywhere inside obj. */
function walk(obj, fx, sts, remotes, servants, totems, depth = 0) {
  if (!obj || typeof obj !== 'object' || depth > 12) return;
  if (Array.isArray(obj)) { for (const v of obj) walk(v, fx, sts, remotes, servants, totems, depth + 1); return; }
  for (const [k, v] of Object.entries(obj)) {
    if (v && typeof v === 'object' && !Array.isArray(v) && EFFECT_KEYS.has(k) && v.id != null && (v.scene != null || v.timeMs != null)) {
      if (Number(v.id) > 0) fx.add(`${v.cate ?? 100}:${v.id}`);
    }
    if (typeof v === 'number') {
      if (STATUS_KEYS.test(k) && v > 0) sts.add(v);
      else if (k === 'remoteIndex' && v > 0) remotes?.add(v);
      else if (k === 'servantIndex' && v > 0) servants?.add(v);
      else if (k === 'totemIndex' && v > 0) totems?.add(v);
    }
    if (k === 'statusGroups' || k === 'args' || k === 'raw') continue;
    if (v && typeof v === 'object') walk(v, fx, sts, remotes, servants, totems, depth + 1);
  }
}

/** Add a scene and every unit its res slots name. */
function addScene(key, scenes, units) {
  const sc = E.scenes[key];
  if (!sc || scenes[key]) return;
  scenes[key] = sc;
  for (const r of Object.values(sc.res || {})) if (typeof r === 'string' && E.units[r]) units[r] = E.units[r];
}

// ------------------------------------------------------------------------------------------ servant attacks
const ATTACK_BLOCKS = ['Melee', 'Power_Melee', 'Special_Melee', 'Great_Melee', 'Range', 'Power_Range', 'Special__Range', 'Great_Range', 'Heal', 'Revive'];
function servantAttacks(sv) {
  const r = sv.raw || {};
  const out = [];
  for (const b of ATTACK_BLOCKS) {
    const min = Number(r[`attackDamage_Min_${b}`]) || 0, max = Number(r[`attackDamage_Max_${b}`]) || 0;
    const code = Number(r[`ResultCode_${b}`]) || 0;
    if (!(max > 0) && !code) continue;
    const args = [1, 2, 3, 4, 5, 6, 7].map(i => Number(r[`ResultValue_${b}_${i}`]) || 0);
    out.push({
      block: b.replace('__', '_').toLowerCase(), min, max,
      absMin: Number(r[`absoluteDamage_Min_${b}`]) || 0, absMax: Number(r[`absoluteDamage_Max_${b}`]) || 0,
      range: Number(r[`CellRange_${b}`]) || 0, delayMs: Number(r[`attackDelay_${b}`]) || 0,
      material: Number(r[`attackMaterial_${b}`]) || 0,
      result: code ? describeResult(code, args, ctx) : null,
    });
  }
  return out;
}

// ------------------------------------------------------------------------------------------ common tables
const decodeCsv = rel => csvObjects(fs.readFileSync(path.join(DATA, rel)), true).rows;
const forceSkills = {};
try {
  for (const r of decodeCsv('share/item/force_skill.csv')) {
    const i = Number(r.Type_Index);
    if (!(i > 0)) continue;
    const args = [1, 2, 3, 4, 5, 6, 7, 8].map(k => Number(r[`Arg${k}`]) || 0);
    const eff = (id, sc, t, cate) => (Number(id) > 0 ? { cate: Number(cate) || 100, id: Number(id), scene: Number(sc) || 1, timeMs: Number(t) || 1000 } : null);
    forceSkills[i] = {
      index: i, cooldownMs: Number(r.CoolTime) || 0, probability: Number(r.Probability) || 0,
      effect: eff(r.EffectID, r.SceneID, r.EffectTime, 100),
      result: describeResult(Number(r.ResultCode) || 0, args, ctx),
      hitEffect: eff(r.ResultEffectID, r.ResultSceneID, r.ResultEffectTime, r.ResultEffectCategory || 100),
      onTarget: Number(r.EffectPos) === 1,
    };
  }
} catch (err) { console.warn('force_skill.csv', err.message); }

const groupSkills = {};
try {
  for (const r of decodeCsv('share/groupskill/skillgroup.csv')) {
    const c = Number(r.CLASS_INDEX), g = Number(r.SKILL_GROUP_INDEX), sk = Number(r.SKILL_INDEX);
    if (!Number.isFinite(sk)) continue;
    (groupSkills[sk] = { classIndex: c, group: g, skill: sk, name: r.SKILL_NAME });
  }
} catch (err) { console.warn('skillgroup.csv', err.message); }

// basic-attack combos (share/combo/combo.csv): blocks "CLASS,STYLE,MAXCOMBO" + "COMBOCOUNT,TimeLength,Timing,Timing2,
// RESULTCODE,Arg0..Arg5" rows. The runtime (hooks.js) applies their result codes; projectile rows name a remote.
const combos = {};          // class -> style -> [{step, timeLength, timing, timing2, resultCode, args, result}]
try {
  const lines = fs.readFileSync(path.join(DATA, 'share/combo/combo.csv'), 'latin1').split(/\r?\n/);
  let cur = null, mode = null;
  for (const line of lines) {
    const f = line.split(',');
    if (/^CLASS$/i.test(f[0])) { mode = 'class'; continue; }
    if (/^COMBOCOUNT$/i.test(f[0])) { mode = 'steps'; continue; }
    if (!/^\d+$/.test(f[0])) continue;
    if (mode === 'class') {
      const c = Number(f[0]), s = Number(f[1]);
      cur = ((combos[c] ||= {})[s] = []);
      mode = null;
    } else if (mode === 'steps' && cur) {
      const code = Number(f[4]) || 0;
      const args = f.slice(5, 11).map(v => Number(v) || 0);
      cur.push({ step: Number(f[0]), timeLength: Number(f[1]) || 0, timing: Number(f[2]) || 0, timing2: Number(f[3]) || 0, resultCode: code, args,
        result: code ? describeResult(code, args, ctx) : null });
    }
  }
} catch (err) { console.warn('combo.csv', err.message); }

// spells (share/article/spell.csv): the 42000xx spell results name a row here; its STATUSINDEX / effects go in the pack
const spellRows = new Map();
try {
  for (const r of decodeCsv('share/article/spell.csv')) {
    const i = Number(r.INDEX);
    if (!(i > 0)) continue;
    spellRows.set(i, { status: Number(r.STATUSINDEX) || 0, pc: Number(r.PCEFFECTID) || 0, mon: Number(r.MONSTEREFFECTID) || 0 });
  }
} catch (err) { console.warn('spell.csv', err.message); }

fs.mkdirSync(OUT, { recursive: true });

// common effect scenes: every condition / hit / game effect, plus everything model effects reference
const cScenes = {}, cUnits = {};
for (const key of Object.keys(E.scenes)) {
  const cate = Number(key.split(':')[0]);
  if (cate === 11 || cate === 6 || cate === 5) addScene(key, cScenes, cUnits);
}
{
  const fx = new Set(), sts = new Set(), rem = new Set();
  const { pcActionEffects, ...modelFx } = E.modelEffects;
  walk(modelFx, fx, sts, rem);
  walk(forceSkills, fx, sts, rem);
  // modelEffects rows are {effect:{cate,id,...}} arrays / maps of {start,keep,end}
  const scan = o => { if (!o || typeof o !== 'object') return; if (o.id != null && o.cate != null) fx.add(`${o.cate}:${o.id}`); for (const v of Object.values(o)) scan(v); };
  scan(modelFx);
  for (const r of rem) { const rm = S.remotes[r]; if (rm) walk(rm, fx, sts); }
  for (const k of fx) addScene(k, cScenes, cUnits);
  var commonRemotes = {};
  for (const r of rem) if (S.remotes[r]) commonRemotes[r] = S.remotes[r];
  var commonStatuses = {};
  for (const s of sts) if (ST.statuses[s]) commonStatuses[s] = ST.statuses[s];
}

const common = {
  version: 1, generatedBy: 'tools/build-skills-runtime.mjs', generatedAt: new Date().toISOString(),
  sources: ['gamedata/skills.json', 'gamedata/skills_status.json', 'gamedata/skills_effects.json', 'share/item/force_skill.csv', 'share/groupskill/skillgroup.csv'],
  enums: S.enums, resultCodes: S.resultCodes, optionCodes: { ...ST.optionCodes, ...S.optionCodes },
  aggro: S.aggro, randomBuff: S.randomBuff, weaponStatus: S.weaponStatus, legacyOnly: S.legacyOnly,
  statusGroups: ST.statusGroups, statusDelete: ST.statusDelete, icons: ST.icons,
  damageText: E.damageText, modelEffects: E.modelEffects, categories: E.categories, missingEffects: E.missing,
  forceSkills, groupSkills, remotes: commonRemotes, statuses: commonStatuses,
  effects: { scenes: cScenes, units: cUnits },
};
const cj = JSON.stringify(common);
fs.writeFileSync(path.join(OUT, 'common.json'), cj);
console.log(`common.json ${(cj.length / 1e6).toFixed(2)} MB: ${Object.keys(cScenes).length} scenes, ${Object.keys(cUnits).length} units, ${Object.keys(forceSkills).length} force skills, ${Object.keys(groupSkills).length} group skills`);

// ------------------------------------------------------------------------------------------ class packs
const index = { classes: [] };
for (const cls of S.classes) {
  const skills = {};
  for (const i of cls.skills) skills[i] = S.skills[i];
  const fx = new Set(), sts = new Set(), rem = new Set(), sv = new Set(), tt = new Set();
  walk(skills, fx, sts, rem, sv, tt);
  walk(cls.clips, fx, sts);
  const classCombos = combos[cls.index] || {};
  walk(classCombos, fx, sts, rem);
  // spell rows of the spell results (their proc statuses and effects)
  for (const sk of Object.values(skills)) {
    for (const L of sk.levels || []) for (const st of L.steps || []) {
      const r = st.result;
      if (!r || !/^spell/.test(r.family || '')) continue;
      const row = spellRows.get(Number(r.args?.[0]));
      if (!row) continue;
      if (row.status) sts.add(row.status);
      if (row.pc) fx.add(`100:${row.pc}`);
      if (row.mon) fx.add(`100:${row.mon}`);
    }
  }
  // weapon statuses of the class masteries, random-buff pools
  for (const i of cls.skills) {
    const ws = S.weaponStatus[i];
    if (ws) for (const s of Object.values(ws)) sts.add(Number(s));
  }
  for (const pool of Object.values(S.randomBuff)) for (const e of pool) sts.add(Number(e.statusIndex));
  // NeedType status ranges (C'est La Vie 9760..9779, Berserker 14880..14882)
  for (const sk of Object.values(skills)) {
    if ([2, 5, 6].includes(Number(sk.needType)) && sk.needVars) {
      const [a, b] = sk.needVars.map(Number);
      if (a > 0 && b >= a && b - a < 64) for (let s = a; s <= b; s++) sts.add(s);
    }
  }
  const remotes = {}, servants = {}, totems = {};
  for (const r of rem) if (S.remotes[r]) { remotes[r] = S.remotes[r]; walk(S.remotes[r], fx, sts); }
  for (const s of sv) {
    const x = S.servants[s];
    if (!x) continue;
    servants[s] = { ...x, attackResults: servantAttacks(x) };
    walk(servants[s], fx, sts, rem);
  }
  for (const t of tt) if (S.totems[t]) { totems[t] = S.totems[t]; walk(S.totems[t], fx, sts); }
  for (const r of rem) if (S.remotes[r] && !remotes[r]) { remotes[r] = S.remotes[r]; walk(S.remotes[r], fx, sts); }
  const statuses = {};
  for (const s of sts) {
    const d = ST.statuses[s];
    if (!d) continue;
    statuses[s] = d;
    walk(d, fx, new Set());
    // proc skills of statuses (SKILL_USESKILL value = skill index of the same class) are part of the skill set already
  }
  const scenes = {}, units = {};
  for (const k of fx) if (!cScenes[k]) addScene(k, scenes, units);
  const pack = {
    version: 1, generatedBy: 'tools/build-skills-runtime.mjs', classIndex: cls.index,
    class: cls, skills, remotes, servants, totems, statuses, combos: classCombos, effects: { scenes, units },
  };
  const j = JSON.stringify(pack);
  fs.writeFileSync(path.join(OUT, `class_${cls.index}.json`), j);
  index.classes.push({ index: cls.index, code: cls.code, name: cls.name, file: `class_${cls.index}.json`, bytes: Buffer.byteLength(j, 'utf8'), skills: cls.skills.length });
  console.log(`class_${cls.index}.json ${cls.code.padEnd(3)} ${(j.length / 1e6).toFixed(2)} MB: ${cls.skills.length} skills, ${Object.keys(remotes).length} remotes, ${Object.keys(servants).length} servants, ${Object.keys(totems).length} totems, ${Object.keys(statuses).length} statuses, ${Object.keys(scenes).length} scenes, ${Object.keys(units).length} units`);
}
fs.writeFileSync(path.join(OUT, 'index.json'), JSON.stringify(index, null, 1));
console.log(`done in ${Date.now() - t0} ms`);
