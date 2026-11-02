#!/usr/bin/env node
// Dekaron Solo - mounts / pets / wings / costumes data builder (system: src/systems/mounts, docs/MOUNTS.md).
//
// Reads the item builder's outputs (gamedata/items*.json, docs/formats/items.md) plus the client tables that only
// these systems use, and writes ONE compact runtime file:
//   gamedata/mounts.json
//     vehicles        every mount item (type 6 code 4): name, level window, period, options (applied while RIDING),
//                     exOptions (applied while EQUIPPED), vehicle_shape look (mesh per class, 'ride' bone, FootStyle,
//                     vehicle action table) and its share/vehicle/vehicle.csv row (summon/dismiss delay, tier,
//                     crystallisation output, evolution material, ActionSpeedMul)
//     vehicleActions  share/action/action/vehicle tables (mount skeleton + STAND/MOVE/DEFEAT/SM_* rows)
//     riderActions    share/action/action/rider tables ("<class code><FootStyle>": the rider's mounted poses)
//     vehicleOptions  share/vehicle/vehicleoption.csv (mount option enchant / upgrade: values + costs per level)
//     ridingHeight    script/ridingheightcorrection (chat bubble / emblem heights per mount and class)
//     wings           wing item -> [asset, action table]; wingActions (skeleton + rows + the wingrider skeleton)
//     costumes        costume item -> parts + asset (per class)
//     pets            pet items (new system: pet.csv creature + pet_shape model + action table) and the 36 legacy
//                     share/creature/pet.csv pets (pet01..pet10 models with their monster anims)
//     petTables       petoption / petskill / petbless / petmaking / petdisassemble / petshapechange /
//                     petitem_shape / petitempickup
//     costumeTables, wingTables   (copied from items-tables.json)
//     names, shapes   English names and inventory models of every item these systems show
//     sys             share/system_variable.csv summon casting times
//
// Usage: node tools/build-mounts.mjs [--data <unpacked data root>] [--gamedata <dir>] [--out <file>]
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parseCSV, decodeText } from '../src/formats/binreader.js';
import { parseActionDat } from '../src/formats/modeldef.js';
import { parseAnim } from '../src/formats/anim.js';
import { parseMesh } from '../src/formats/mesh.js';
import { parseSkel, findBone } from '../src/formats/skel.js';
import { createAuthoredAnimationLookup, resolveAuthoredAnimationKey } from './lib/authored-animation-key.mjs';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const arg = (k, d) => { const i = process.argv.indexOf(k); return i > 0 ? process.argv[i + 1] : d; };
const DATA = path.resolve(arg('--data', path.join(HERE, '../../data/unpacked/data')));
const GD = path.resolve(arg('--gamedata', path.join(HERE, '../gamedata')));
const OUT = path.resolve(arg('--out', path.join(GD, 'mounts.json')));

const t0 = Date.now();
const readJSON = f => JSON.parse(fs.readFileSync(path.join(GD, f), 'utf8'));
const exists = k => fs.existsSync(path.join(DATA, k));
const readText = (k, kr = true) => decodeText(new Uint8Array(fs.readFileSync(path.join(DATA, k))), kr);
const csvObjects = (k, kr = true) => {
  if (!exists(k)) return [];
  const rows = parseCSV(readText(k, kr));
  const head = (rows.shift() || []).map(h => String(h).trim());
  return rows.filter(r => r.some(x => String(x).trim() !== '')).map(r => {
    const o = {};
    head.forEach((h, i) => { if (h) o[h] = String(r[i] ?? '').trim(); });
    return o;
  });
};
const num = v => { const n = Number(String(v ?? '').replace(/,/g, '').trim()); return Number.isFinite(n) ? n : 0; };
const key = p => String(p || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();

console.log('[mounts] reading items*.json ...');
const I = readJSON('items.json');
const V = readJSON('items-visual.json');
const L = readJSON('items-looks.json');
const A = readJSON('items-actions.json');
const T = readJSON('items-tables.json');
const O = readJSON('items-options.json');
const item = i => (I.items[i] ? { ...I.itemDefaults, ...I.items[i] } : null);

const names = {};
const shapes = {};
const itemShape = {};
const problems = [];
const animationLookup = createAuthoredAnimationLookup(DATA);
const resolvedAnimationRefs = new Map();
function authoredAnimation(key) {
  const result = resolveAuthoredAnimationKey(key, animationLookup);
  if (result.key && result.reason === 'extension') resolvedAnimationRefs.set(key, result.key);
  return result.key;
}
/** Remember an item's name + inventory model (icons in the windows of these systems). */
function need(idx) {
  idx = Number(idx);
  if (!(idx > 0) || names[idx] != null) return;
  const it = item(idx);
  if (!it) { names[idx] = ''; return; }
  names[idx] = it.name || '';
  if (it.shape && V.shapes[it.shape]?.inv) {
    itemShape[idx] = it.shape;
    if (!shapes[it.shape]) shapes[it.shape] = V.shapes[it.shape].inv;
  }
}
const small = it => {
  const o = { n: it.name, lv: it.reqLv || 0 };
  if (it.maxLv) o.mx = it.maxLv;
  if (it.classMask !== 32767) o.cm = it.classMask;
  if (it.period) o.per = it.period;
  if (it.options?.length) o.o = it.options;
  if (it.exOptions?.length) o.xo = it.exOptions;
  if (it.next) o.next = it.next;
  if (it.prev) o.prev = it.prev;
  if (it.rank) o.rk = it.rank;
  if (it.desc) o.desc = it.desc;
  if (it.itemLv) o.il = it.itemLv;
  return o;
};

// ------------------------------------------------------------------------------------------ vehicles
// Scan fix A: vehicle.csv rows 1754771, 2310234-2310237, 2313520 are NOT built on purpose: in Global items those indices
// are boxes (1754771/2310234/2313520, type 0) or wings (2310235-2310237, slot wing), not slot=vehicle items.
const vehicleCsv = {};
for (const r of csvObjects('share/vehicle/vehicle.csv', false)) {
  vehicleCsv[num(r.Index)] = {
    sd: num(r.StartDelay), ed: num(r.EndDelay), tier: num(r.Tier),
    dis: [num(r.DisassembleIndex), num(r.GiveCount)], need: [num(r.NeedItemIndex), num(r.NeedCount)],
    asm: num(r.ActionSpeedMul), desc: num(r.Description),
  };
}
const vehicles = {};
const vlooks = [];            // deduplicated {mesh, tpack, textures} of the mount meshes
const vlookIds = new Map();
const vlook = m => { if (!m?.mesh) return null; const k = JSON.stringify(m); if (!vlookIds.has(k)) { vlookIds.set(k, vlooks.length); vlooks.push(m); } return vlookIds.get(k); };
let vCount = 0, vNoLook = 0;
for (const k in I.items) {
  const it = item(k);
  if (it.slot !== 'vehicle') continue;
  vCount++;
  const o = small(it);
  const look = V.vehicles[k];
  if (look) {
    o.bone = look.bone || 'ride';
    o.fs = look.footStyle ?? 0;
    o.act = look.action ?? look.vehicleIndex ?? 0;
    if (look.all) o.all = vlook(look.all);
    if (look.byClass) { o.byClass = {}; for (const [c, m] of Object.entries(look.byClass)) o.byClass[c] = vlook(m); }
    if (look.effect) o.eff = look.effect;
  } else vNoLook++;
  if (vehicleCsv[k]) o.csv = vehicleCsv[k];
  vehicles[k] = o;
  need(k);
  if (o.next) need(o.next);
  if (o.csv) { need(o.csv.dis[0]); need(o.csv.need[0]); }
}

// vehicle option enchant / upgrade (share/vehicle/vehicleoption.csv)
const vehicleOptions = csvObjects('share/vehicle/vehicleoption.csv', false).map(r => {
  const values = [], need = [], cost = [];
  for (let i = 0; i <= 10; i++) values.push(num(r[`Value_${i}`]));
  for (let i = 1; i <= 10; i++) { need.push(num(r[i === 1 ? 'Need_1' : `Need${i}`] ?? r[`Need_${i}`])); cost.push(num(r[`NeedCost_${i}`])); }
  const optType = Object.entries(O.optionTypes).find(([, v]) => v.name === r.OPTION)?.[0];
  return {
    index: num(r.INDEX), option: r.OPTION, optionType: optType != null ? Number(optType) : null, label: r.DESCRIPTION,
    addCost: num(r.ADD_OPTION_COST), addItems: String(r.ADD_OPTION_ITEM || '').split('/').map(num).filter(Boolean),
    values, needItem: num(r.NEED_ITEM), need, cost,
  };
});
for (const r of vehicleOptions) { for (const x of r.addItems) need(x); need(r.needItem); }

// riding skill (Boarding mastery) per class name of the table
const vehicleSkill = {};
for (const r of csvObjects('share/vehicle/vehicleskill.csv', false)) vehicleSkill[r.Class] = num(r.SkillIndex);

// riding heights: rows are named in Korean after the mounts; map them to the vehicle meshes
const RIDE_NAME_TO_MESH = {
  '홍예운': ['cloud'], '근두운': ['cloud'], '적운': ['cloud'], '뇌운': ['cloud'], '홍운': ['cloud'],
  '러빙러빙 하트': ['cloud_heart'], '오토바이': ['motorcycle'], '바이크': ['2021_motobike', '2021_motobike_big', '2021_motobike_sma'],
  '타락한 유니콘': ['unicorn'], '주작': ['phenix'], '가오리': ['ray'], '실피드': ['sylphid'], '알루드라': ['sylphid2'],
  '그라니': ['grani'], '그리니': ['rimpaks'], '림파크스': ['rimpaks'], '벨룸': ['bellum2'], '벤투스': ['bellum'],
  '아퀼라 라티스': ['rhathys', 'rhathys02'], '아퀼라라티스': ['rhathys', 'rhathys02'], '투르크': ['turk'],
  '아퀴라 라티스': ['rhathys', 'rhathys02'], '아퀴라라티스': ['rhathys', 'rhathys02'],
  '홀리노바': ['horse_colosseum'], '와이즈곤': ['wisegon_baby'], '리틀와이즈곤': ['wisegon_baby'], '레전드 드래곤': ['wisegon_baby'],
  '청마': ['bluehorse'], '적토마': ['bluehorse'], '백호': ['whitetiger', 'blacktiger'], '팬더': ['vehicle_panda'], '페가수스': ['unicorn'],
};
function heightTable(file) {
  const rows = parseCSV(readText(file, true));
  const head = rows.shift() || [];
  const out = {};
  for (const r of rows) {
    const nm = String(r[0] || '').trim();
    if (!nm) continue;
    const vals = r.slice(1, head.length).map(num);
    const meshes = RIDE_NAME_TO_MESH[nm];
    if (!meshes) { problems.push(`ridingheight: unmapped mount name ${nm} in ${file}`); continue; }
    for (const m of meshes) if (!out[m]) out[m] = vals;   // first row of a name wins (duplicates keep the earlier row)
  }
  return { classes: head.slice(1).map(h => String(h).trim()), byMesh: out };
}
const ridingHeight = {
  bubble: heightTable('script/ridingheightcorrection/charbubbleheight.csv'),
  emblem: heightTable('script/ridingheightcorrection/emblemheight.csv'),
  correction: (() => {
    const rows = parseCSV(readText('script/ridingheightcorrection/emblemheightcorrection.csv', true));
    rows.shift();
    const out = {};
    for (const r of rows) if (String(r[0]).trim() !== '') out[num(r[0]) === 0 ? 'emblem' : 'nametag'] = r.slice(2, 17).map(num);
    return out;
  })(),
};

// ------------------------------------------------------------------------------------------ wings
const assetMap = new Map();   // items-looks asset id -> compact id
const assets = [];
const asset = id => {
  if (id == null || !L.assets[id]) return null;
  if (!assetMap.has(id)) { assetMap.set(id, assets.length); assets.push(L.assets[id]); }
  return assetMap.get(id);
};
const wings = {};
const wingActions = {};
const wingAnimIds = new Map(A.anims.map((anim, id) => [anim, id]));
const wingAnim = anim => {
  if (!wingAnimIds.has(anim)) { wingAnimIds.set(anim, A.anims.length); A.anims.push(anim); }
  return wingAnimIds.get(anim);
};
let wingRiderParsed = 0;
for (const k in L.looks) {
  const lk = L.looks[k];
  if (lk.slot !== 'wing') continue;
  const it = item(k);
  const a = asset(lk.all);
  if (a == null) continue;
  wings[k] = lk.action ? [a, lk.action] : [a];
  names[k] = it?.name || '';
  if (it?.shape && V.shapes[it.shape]?.inv) { itemShape[k] = it.shape; shapes[it.shape] ||= V.shapes[it.shape].inv; }
  if (lk.action && !wingActions[lk.action] && A.item[lk.action]) {
    const t = A.item[lk.action];
    // wings play STAND (1) and MOVE (2) rows of the character's style (plus the market / fishing poses, which the
    // solo game maps onto STAND): keep STAND index 0..1 and MOVE index 0..1
    const e = { skel: t.skel, rows: t.rows.filter(r => (r[1] === 1 || r[1] === 2) && r[2] <= 1) };
    if (t.wingRider) {
      try {
        const buf = fs.readFileSync(path.join(DATA, key(t.wingRider)));
        const w = parseActionDat(buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.byteLength));
        const sk = w.skelKey && exists(w.skelKey) ? w.skelKey : null;
        if (sk && sk !== t.skel) e.riderSkel = sk;
        // The mounted table can change the clip or its duration even when the rig is identical.
        // Retain its authored rows; only emit clips and a rig that actually exist in this client.
        if (sk) {
          let missing = 0;
          e.riderRows = w.actions.filter(r => (r.actionId === 1 || r.actionId === 2) && r.index <= 1 && r.animKey).flatMap(r => {
            const animation = authoredAnimation(r.animKey);
            if (!animation) { missing++; return []; }
            return [[r.style, r.actionId, r.index, wingAnim(animation), Math.round(r.timeLength * 1000) / 1000]];
          });
          if (missing) problems.push(`wingrider ${t.wingRider}: ${missing} rows reference missing animations`);
        }
        wingRiderParsed++;
      } catch (err) { problems.push(`wingrider ${t.wingRider}: ${err.message}`); }
    }
    wingActions[lk.action] = e;
  }
}
// COMPATIBILITY (nativeDispatchVerified:false), docs/WING-BINDING.md: Action_Index 0 names no share/action/list.csv table, but
// Global still ships each such wing's own compiled per-class, per-item tables share/action/action/{item,wingrider}/
// wing<cls>.act.<itemID>.dat (header Index = the item). One is bound only when it is the single table for the item's single
// wearable class, its header Index is the item, and its skeleton exists and holds every bone of the item's mesh palette. Where
// both exist for other wings, the class-matched per-item rig equals the Action_Index rig 1,753 times out of 1,856.
let wingItemTables = 0;
{
  const C = readJSON('classes.json').classes;
  const code = Object.fromEntries(Object.values(C).map(c => [c.index, String(c.code).toLowerCase()]));
  const perItem = { item: new Map(), wingrider: new Map() };
  for (const kind of Object.keys(perItem)) {
    const dir = path.join(DATA, 'share/action/action', kind);
    for (const f of fs.existsSync(dir) ? fs.readdirSync(dir) : []) {
      const m = /^wing([a-z]+)(?:_\d+)?\.act\.(\d+)\.dat$/i.exec(f);
      if (!m) continue;
      const k = `${m[2]}:${m[1].toLowerCase()}`;
      if (!perItem[kind].has(k)) perItem[kind].set(k, []);
      perItem[kind].get(k).push(`share/action/action/${kind}/${f}`);
    }
  }
  const dat = rel => { const b = fs.readFileSync(path.join(DATA, rel)); return parseActionDat(b.buffer.slice(b.byteOffset, b.byteOffset + b.byteLength)); };
  const rowsOf = (a, src) => {
    let missing = 0;
    const rows = a.actions.filter(r => (r.actionId === 1 || r.actionId === 2) && r.index <= 1 && r.animKey).flatMap(r => {
      const animation = authoredAnimation(r.animKey);
      if (!animation) { missing++; return []; }
      return [[r.style, r.actionId, r.index, wingAnim(animation), Math.round(r.timeLength * 1000) / 1000]];
    });
    if (missing) problems.push(`${src}: ${missing} rows reference missing animations`);
    return rows;
  };
  for (const k in wings) {
    const it = item(k);
    if (!it || it.action || wings[k].length > 1) continue;
    const classes = Array.from({ length: 15 }, (_, i) => i).filter(i => !it.classMask || ((it.classMask >>> i) & 1));
    if (classes.length !== 1) continue;
    const files = perItem.item.get(`${k}:${code[classes[0]]}`) || [];
    if (files.length !== 1) continue;
    try {
      const a = dat(files[0]);
      const sk = a.skelKey && exists(a.skelKey) ? a.skelKey : null;
      if (a.index !== Number(k) || !sk) continue;
      const mb = fs.readFileSync(path.join(DATA, assets[wings[k][0]].mesh));
      const palette = [...new Set(parseMesh(mb.buffer.slice(mb.byteOffset, mb.byteOffset + mb.byteLength)).meshes.flatMap(m => m.bonePalette || []))];
      const rig = parseSkel(fs.readFileSync(path.join(DATA, sk)));
      if (!palette.length || !palette.every(b => findBone(rig, b) >= 0)) continue;
      const e = { skel: sk, rows: rowsOf(a, files[0]), compat: files[0] };
      const riders = perItem.wingrider.get(`${k}:${code[classes[0]]}`) || [];
      if (riders.length === 1) {
        const w = dat(riders[0]);
        const rs = w.skelKey && exists(w.skelKey) ? w.skelKey : null;
        if (w.index === Number(k) && rs) { if (rs !== sk) e.riderSkel = rs; e.riderRows = rowsOf(w, riders[0]); }
      }
      wingActions[`i${k}`] = e;
      wings[k] = [wings[k][0], `i${k}`];
      wingItemTables++;
    } catch (err) { problems.push(`wing ${k} per-item table: ${err.message}`); }
  }
}

// ------------------------------------------------------------------------------------------ costumes
const costumes = {};
for (const k in L.looks) {
  const lk = L.looks[k];
  if (lk.slot !== 'costume') continue;
  const it = item(k);
  const e = { p: lk.parts };
  if (lk.all != null) e.a = asset(lk.all);
  if (lk.byClass) { e.c = {}; for (const [c, id] of Object.entries(lk.byClass)) e.c[c] = asset(id); }
  if (e.a == null && !e.c) continue;
  costumes[k] = e;
  names[k] = it?.name || '';
  if (it?.period) e.per = it.period;
  if (it?.shape && V.shapes[it.shape]?.inv) { itemShape[k] = it.shape; shapes[it.shape] ||= V.shapes[it.shape].inv; }
}

// ------------------------------------------------------------------------------------------ pets
const pets = {};
for (const k in V.pets) {
  const p = V.pets[k];
  const it = item(k);
  pets[k] = {
    n: it?.name || p.name, lv: it?.reqLv || 0, per: it?.period || 0, sleep: p.sleepItem || 0, model: p.modelItem || 0,
    shape: p.shapeInfo, mesh: p.mesh, tpack: p.tpack, textures: p.textures, act: p.action, eff: p.effect || 0,
    cr: p.creature ? { rank: p.creature.rank, walk: p.creature.walkSpeed, ai: p.creature.aiKey, enter: p.creature.enterEffect,
      leave: p.creature.leaveEffect, og: p.creature.optionGroup, skill: p.creature.skill, bless: p.creature.bless,
      raw: p.creature.raw } : null,
  };
  need(k); if (p.sleepItem) need(p.sleepItem); if (p.modelItem) need(p.modelItem);
}
const petActions = {};
for (const k in A.pet) petActions[k] = A.pet[k];

// the 36 pre-2010 pets of share/creature/pet.csv (Woody, Wiki, Ariel ...): monster-style models without action tables
const petShapeRows = {};
for (const r of parseCSV(readText('script/shape/pet_shape.csv', true)).slice(1)) {
  const shape = String(r[1] || '').trim().toLowerCase();
  if (shape) petShapeRows[shape] = { name: String(r[0] || '').trim(), mesh: key(`mesh/${r[2]}`), tpack: key(`texturepack/${r[3]}`), effect: num(r[4]) || 0 };
}
const animSeconds = k => {
  try {
    const buf = fs.readFileSync(path.join(DATA, k));
    const a = parseAnim(buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.byteLength));
    return Math.round((a.estDurationSec || 1) * 1000) / 1000;
  } catch { return 1; }
};
const legacyPets = {};
for (const r of csvObjects('share/creature/pet.csv', false)) {
  const idx = num(r.Index), shape = String(r.ShapeInfo || '').trim().toLowerCase();
  const sr = petShapeRows[shape];
  if (!sr || !exists(sr.mesh)) { problems.push(`legacy pet ${idx} ${r.Name}: no model for ${shape}`); continue; }
  const skel = `skel/monster/${shape}.skel`;
  const dir = `anim/monster/${shape}/`;
  const anim = n => { const k = `${dir}${shape}_${n}.anim`; return exists(k) ? [k, animSeconds(k)] : null; };
  legacyPets[idx] = {
    n: item(idx)?.name || r.Name, shape, mesh: sr.mesh, tpack: exists(sr.tpack) ? sr.tpack : null, skel: exists(skel) ? skel : null, eff: sr.effect,
    walk: num(r.WalkSpeed), stand: anim('stand'), walkA: anim('walk'), run: anim('run'), swimStand: anim('swim_stand'),
    swimWalk: anim('swim_walk'), swimRun: anim('swim_run'), cstand: anim('cstand'), og: num(r.PetOptionGroupID),
    skill: num(r.PetSkillID), bless: num(r.PetBlessID), blessTime: num(r.BlessTime), enter: num(r.EnterEffect), leave: num(r.LeaveEffect),
  };
  need(idx);
}

// pet tables
const petTables = {
  option: csvObjects('share/creature/pet/petoption.csv', false).map(r => ({ group: num(r.OptionGroup), index: num(r.OptionIndex),
    type: r.Type, optionType: Number(Object.entries(O.optionTypes).find(([, v]) => v.name === r.Type)?.[0] ?? -1), text: r.Description,
    min: num(r.MinData), max: num(r.MaxData), weight: num(r.Range) })),
  skill: csvObjects('share/creature/pet/petskill.csv', false).map(r => {
    const skills = [];
    for (let i = 1; i <= 5; i++) {
      const nm = r[`PetSkillName_${i}`];
      if (!nm || nm === '0') continue;
      skills.push({ name: nm, option: num(r[`PetSkillOptionID_${i}`]), range: num(r[`PetSkillOptionRange_${i}`]),
        icon: num(r[`IconID_${i}`]), mini: num(r[`MiniIconID_${i}`]), desc: num(r[`DescriptionID_${i}`]) });
    }
    return { index: num(r.Index), grade: r.Note_1, note: r.Note_2, skills };
  }),
  bless: csvObjects('share/creature/pet/petbless.csv', false).map(r => {
    const items = [];
    for (let i = 1; i <= 20; i++) if (num(r[`BlessItemID${i}`])) items.push([num(r[`BlessItemID${i}`]), num(r[`BlessItemIDDice${i}`])]);
    for (const [x] of items) need(x);
    return { index: num(r.Index), count: num(r.BlessItemNum), dice: num(r.BlessDice), items };
  }),
  making: csvObjects('share/creature/pet/petmaking.csv', false).map(r => {
    const o = { index: num(r.Index), point: num(r.StandardPoint), timeMs: num(r.PetMakingTime), dil: num(r.PetMakingDil),
      range: num(r.AllRange), normal: [num(r.NomalPet), num(r.NomalPetDice)], rare: [num(r.RarePet), num(r.RarePetDice)],
      unique: [num(r.UniquePet), num(r.UniquePetDice)], useLegend: num(r.UseLegend), legendEgg: num(r.LegendEgg) };
    need(o.normal[0]); need(o.rare[0]); need(o.unique[0]); need(o.legendEgg);
    return o;
  }),
  disassemble: csvObjects('share/creature/pet/petdisassemble.csv', false).map(r => {
    const o = { item: num(r.ItemIndex), out: num(r.Output_Item), count: num(r.OutputCount), dil: num(r.Need_Dil) };
    need(o.item); need(o.out); return o;
  }),
  shapeChange: csvObjects('share/creature/pet/petshapechange.csv', false).map(r => {
    const o = { item: num(r.PetItemIndex), grade: num(r.Grade), needItem: num(r.NeedItemIndex), needCount: num(r.NeedItemCount),
      dil: num(r.PayDil), resetItem: num(r.Reset_NeedItem), resetCount: num(r.Reset_NeedItem_Count), resetDil: num(r.Reset_Dil) };
    need(o.item); need(o.needItem); need(o.resetItem); return o;
  }),
  itemShape: csvObjects('share/item/petitem_shape.csv', false).map(r => ({ item: num(r.ItemIndex), pet: num(r.PetShape),
    dormancy: num(r.Dormancyshape), model: num(r.shapeindex), previewHeight: num(r.previewheight) })),
  pickup: csvObjects('share/item/petitempickup.csv', false).map(r => ({ item: num(r.Index), name: r.Name })),
};
for (const r of petTables.itemShape) { need(r.item); need(r.dormancy); need(r.model); }

// ------------------------------------------------------------------------------------------ costume / wing tables
// compact: {source, cols, rows: [[...]]} without the Korean description / name columns (the English names are in `names`)
const DROP_COLS = new Set(['Desc', 'Name', 'name', 'rate2Unused']);
const KEEP_NAME = new Set(['wingShapeChange']);
const pick = k => {
  if (!T[k]) return null;
  const cols = T[k].columns.filter(c => KEEP_NAME.has(k) ? !/^Name_\d+$/.test(c) : !DROP_COLS.has(c));
  return { source: T[k].source, cols, rows: T[k].rows.map(r => cols.map(c => r[c] ?? null)) };
};
const costumeTables = {};
for (const k of ['costumeSewing', 'costumeSewingList', 'costumeShapeChange', 'costumeDisassemble', 'costumeOption', 'transcendenceCostume']) costumeTables[k] = pick(k);
const wingTables = {};
for (const k of ['wingUpgrade', 'wingDisassemble', 'wingAddSocket', 'wingRemoveStone', 'wingExchange', 'wingChangeList', 'wingShapeChange']) wingTables[k] = pick(k);
const scan = (t, cols) => {
  if (!t) return;
  const ix = cols.map(c => t.cols.indexOf(c)).filter(i => i >= 0);
  for (const r of t.rows) for (const i of ix) if (r[i] != null) need(r[i]);
};
scan(costumeTables.costumeSewing, ['KeyItem_index_1', 'KeyItem_index_2', 'Itemindex']);
scan(costumeTables.costumeSewingList, ['Itemindex']);
scan(costumeTables.costumeShapeChange, ['Itemindex']);
scan(costumeTables.costumeDisassemble, ['ItemIndex', 'Output_Item']);
scan(costumeTables.transcendenceCostume, ['ItemIndex']);
scan(wingTables.wingUpgrade, ['material']);
scan(wingTables.wingDisassemble, ['ItemIndex', 'Output_Item']);
scan(wingTables.wingChangeList, ['Index', 'NeedMaterialIndex1']);
scan(wingTables.wingExchange, Array.from({ length: 15 }, (_, c) => `class${c}`));
scan(wingTables.wingShapeChange, ['Index', ...Array.from({ length: 60 }, (_, c) => `Index_${c + 1}`)]);

// ------------------------------------------------------------------------------------------ system variables
const sysVar = {};
for (const r of csvObjects('share/system_variable.csv', false)) sysVar[num(r.Index)] = num(r.Variable);
const sys = { petSummonMs: sysVar[13] ?? 3000, petUnsummonMs: sysVar[14] ?? 1000, vehicleSummonMs: sysVar[15] ?? 3000, vehicleUnsummonMs: sysVar[16] ?? 1000 };

// ------------------------------------------------------------------------------------------ write
// every referenced anim/skel must exist
let checked = 0, missingAssets = 0;
const chk = k => { if (!k) return; checked++; if (!exists(k)) { missingAssets++; if (missingAssets < 30) problems.push(`missing ${k}`); } };
for (const t of Object.values(A.vehicle)) chk(t.skel);
for (const t of Object.values(A.rider)) chk(t.skel);
for (const t of Object.values(wingActions)) { chk(t.skel); chk(t.riderSkel); }
for (const p of Object.values(legacyPets)) { chk(p.mesh); chk(p.skel); }

// mount / rider tables: STAND (1) idx 0-1, MOVE (2) idx 0-1, DEFEAT (7), BLOCKING/BLOCKED/GUARDING (12-14),
// SM_STAND (26), SM_MOVE (28) idx 0-1 - the only actions a mounted character performs
const RIDE_ACTS = new Set([1, 2, 7, 12, 13, 14, 26, 28]);
const filterRide = tables => {
  const o = {};
  for (const [k, t] of Object.entries(tables)) o[k] = { skel: t.skel, ...(t.file ? {file:t.file} : {}), rows: t.rows.filter(r => RIDE_ACTS.has(r[1]) && (r[2] === 0 || (r[2] === 1 && (r[1] === 1 || r[1] === 2 || r[1] === 26 || r[1] === 28)))) };
  return o;
};
const vehicleActions = filterRide(A.vehicle);
const riderActions = filterRide(A.rider);

const out = {
  version: 1,
  generatedBy: 'tools/build-mounts.mjs',
  generatedAt: new Date().toISOString(),
  what: {
    vehicles: 'item -> {n name, lv reqLv, mx maxLv, cm classMask (absent = all), per period s, o options applied while RIDING, xo exOptions applied while EQUIPPED, bone (rider attach bone on the mount), fs FootStyle (riderActions key = class code + fs), act vehicleActions key, all | byClass {classIndex: {mesh,tpack,textures}}, csv {sd StartDelay ms, ed EndDelay ms, tier, dis [crystal item, count], need [evolution material, count], asm ActionSpeedMul %}}',
    vehicleActions: 'VehicleIndex -> {skel, rows [style, actionId, index, anims index, timeLength s]} (actionIds: items-actions.json)',
    riderActions: '"<class code><FootStyle>" -> {skel, rows} of the rider\'s mounted poses',
    wings: 'item -> [asset, wingActions key?]; wingActions key -> {skel, rows, riderSkel?, riderRows? (native wingrider skeleton and action rows used while mounted)}; key "i<item>" = COMPATIBILITY per-item table of an Action_Index-0 wing (compat = its source file)',
    costumes: 'item -> {p parts replaced, a asset (all classes) | c {classIndex: asset}}',
    pets: 'new pet item -> {n, lv, per, sleep (sleep item), model item, shape, mesh, tpack, textures, act (petActions key), eff, cr creature}; legacyPets: share/creature/pet.csv pets',
  },
  anims: A.anims,
  actionIds: A.actionIds,
  riderCodes: I.equipment.riderCodes,
  wingBone: I.equipment.wingBone,
  costypeParts: I.equipment.costypeParts,
  sys,
  vehicles, vlooks, vehicleActions, riderActions, vehicleOptions, vehicleSkill, ridingHeight,
  wings, wingActions, costumes, assets,
  pets, petActions, legacyPets,
  optionLabels: Object.fromEntries(Object.entries(O.optionTypes).map(([k, v]) => [k, { name: v.name, label: v.label, text: v.text }])),
  report: { vehicles: vCount, vehiclesWithoutLook: vNoLook, wings: Object.keys(wings).length, wingActionTables: Object.keys(wingActions).length,
    wingRiderParsed, wingItemTables, costumes: Object.keys(costumes).length, assets: assets.length, pets: Object.keys(pets).length,
    legacyPets: Object.keys(legacyPets).length, names: Object.keys(names).length, shapes: Object.keys(shapes).length,
    assetChecks: checked, missingAssets, problems,
    resolvedAnimationRefs: [...resolvedAnimationRefs].map(([authored, resolved]) => ({authored, resolved})) },
};
// window tables + item names / inventory models (loaded lazily by the windows)
const ui = {
  version: 1, generatedBy: 'tools/build-mounts.mjs', generatedAt: out.generatedAt,
  what: { tables: '{source, cols, rows: [[...]]} (Korean description/name columns dropped; English names in `names`)',
    names: 'item -> English name', shapes: 'item_shape id -> inventory model {mesh,tpack,textures}', itemShape: 'item -> shape id' },
  petTables, costumeTables, wingTables, names, shapes, itemShape,
};
fs.writeFileSync(OUT, JSON.stringify(out));
const OUT_UI = OUT.replace(/\.json$/, '-ui.json');
fs.writeFileSync(OUT_UI, JSON.stringify(ui));
const mb = f => (fs.statSync(f).size / 1048576).toFixed(2);
console.log(`[mounts] wrote ${OUT} (${mb(OUT)} MB) + ${OUT_UI} (${mb(OUT_UI)} MB) in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
console.log(JSON.stringify(out.report, null, 1).slice(0, 3000));
