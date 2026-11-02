// Build gamedata/sound.json: every sound the solo engine needs, resolved to real files.
//
//   node tools/build-sound.mjs            -> writes gamedata/sound.json + prints a summary
//
// Sources (all under data/unpacked/data):
//   script/bgsound.csv                  MapIndex -> BGM playlist (mp3, served from data/sound/bgm)
//   property/effect/effectdata.snd.txt  sound units: name -> wav file + volume/range/length/loop
//   property/effect/effectscene.snd.txt sound "effect scenes" <cate> -> <effect id> -> scenes -> units
//   script/effect/soundscript.csv       game events (code1..code4) -> effectscene.snd cate 4 (game_sound) id/scene
//   script/effect/modeleffect.csv       action Effect id (act.csv "Effect" column, code1=25) -> cate/id/scene
//   share/action/monster/<idx>.<shape>.act.csv  monster actions (ATTACK n / DEAD / STAND ...) with Effect ids
//   share/creature/monster.csv          Index, Name, Material, ShapeInfo
// All output paths are relative to the sound root, lower-case, '/'-separated. The server resolves
// /sound/<path> against data/unpacked/data/sound first, then data/sound.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parseCSV, decodeText } from '../src/formats/binreader.js';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ENGINE = path.resolve(HERE, '..');
const GAME = path.resolve(ENGINE, '..');
const DATA = process.env.DEKARON_DATA || path.join(GAME, 'data', 'unpacked', 'data');
const SOUND_ROOTS = [path.join(DATA, 'sound'), ...(process.env.DEKARON_LOOSE_SOUND_ROOT?[process.env.DEKARON_LOOSE_SOUND_ROOT]:[]), path.join(GAME, 'data', 'sound')];
const GD = process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata');
const OUT = path.join(GD, 'sound.json');

const readText = (rel) => decodeText(fs.readFileSync(path.join(DATA, rel)), true); // EUC-KR
const readCSV = (rel) => parseCSV(readText(rel));

// ---------------------------------------------------------------- sound file index
const soundFiles = new Map(); // lower rel path -> root index
const byBase = new Map();     // lower basename -> [rel]
function indexRoot(root, ri, dir = root) {
  if (!fs.existsSync(dir)) return;
  for (const e of fs.readdirSync(dir, { withFileTypes: true })) {
    const p = path.join(dir, e.name);
    if (e.isDirectory()) { if (e.name.toLowerCase() !== 'cvs') indexRoot(root, ri, p); continue; }
    if (!/\.(wav|mp3|ogg)$/i.test(e.name)) continue;
    const rel = path.relative(root, p).split(path.sep).join('/').toLowerCase();
    if (!soundFiles.has(rel)) soundFiles.set(rel, ri);
    const b = rel.split('/').pop();
    if (!byBase.has(b)) byBase.set(b, []);
    byBase.get(b).push(rel);
  }
}
SOUND_ROOTS.forEach((r, i) => indexRoot(r, i));
const loose = (b) => b.replace(/[_\-\s]+/g, '');
const byLoose = new Map();
for (const rel of soundFiles.keys()) { const k = loose(rel.split('/').pop()); if (!byLoose.has(k)) byLoose.set(k, []); byLoose.get(k).push(rel); }

const resolveStats = { direct: 0, stripped: 0, basename: 0, missing: 0 };
const missing = new Map();
/** Game path ("Skill\\Foo.wav", "BGM\\Field_03.mp3", "Sound\\x.wav", "Item_Drop_Fishingpole") -> sound-root relative path or null. */
function resolveSound(raw, ctx = '') {
  if (!raw) return null;
  let p = String(raw).trim().replace(/\\/g, '/').replace(/^\.?\/+/, '').toLowerCase();
  const cands = [p];
  if (p.startsWith('sound/')) cands.push(p.slice(6));
  if (/(\.[a-z0-9]{3})\1$/.test(p)) cands.push(p.slice(0, -4)); // "battle_06.mp3.mp3"
  if (!/\.(wav|mp3|ogg)$/.test(p)) cands.push(p + '.wav', p.replace(/\.[a-z0-9]*$/, '') + '.wav');
  for (let i = 0; i < cands.length; i++) {
    if (soundFiles.has(cands[i])) { resolveStats[i === 0 ? 'direct' : 'stripped']++; return cands[i]; }
  }
  for (const c of cands) {
    const b = c.split('/').pop();
    const hits = byBase.get(b);
    if (hits) { resolveStats.basename++; return hits.find((h) => !h.includes('/')) || hits[0]; }
  }
  // Typos in the data ("item__use_powder.wav" on disk vs "item_use_powder.wav" referenced): compare
  // basenames with separators removed.
  for (const c of cands) {
    const hits = byLoose.get(loose(c.split('/').pop()));
    if (hits && hits.length === 1) { resolveStats.basename++; return hits[0]; }
  }
  resolveStats.missing++;
  if (!missing.has(p)) missing.set(p, ctx);
  return null;
}

// ---------------------------------------------------------------- effectdata.snd.txt
// <effectdata> 0 / name sn_X / unittype sound / subtype skill|none|ambient|servant /
// sound <file> <flagA 0|1> <volume 0..600, 100 = normal> <range f> <lengthMs> <flagB true|false>
//   flagB is NOT a loop flag: it is true on exactly 167 units = 151 NPC greeting voices, 7 spoken HUD warnings
//   (message\lack_of_*), 3 quest jingles, 2 emote voices, 4 santa lines - never on an ambient bed - and for 69 of them
//   lengthMs (10000 for lack_of_HP / NPC AARON) is several times the clip length. Read as "exclusive": play the clip
//   once and ignore re-triggers of the same unit until lengthMs has passed. -> sfx.exclusive
//   flagA (1 on 95%) is NOT "positional": every UI click / quest / message unit has 1, while 135 ranged ambient
//   emitters (wind, stream, torch, magma...), 59 monster `stand` idles and 10 buff `keep` sustains have 0.
//   Meaning unknown (sustained / owner-bound or unpanned); kept raw as sfx.unkFlag = 0 when 0.
function parseEffectData(text) {
  const out = new Map();
  for (const m of text.matchAll(/<effectdata>([\s\S]*?)<\/effectdata>/g)) {
    const kv = {};
    for (const line of m[1].split(/\r?\n/)) {
      const t = line.trim(); if (!t) continue;
      const sp = t.search(/\s/); if (sp < 0) continue;
      kv[t.slice(0, sp)] = t.slice(sp).trim();
    }
    if (!kv.name) continue;
    const u = { name: kv.name, unittype: kv.unittype, subtype: kv.subtype || 'none' };
    if (kv.sound) {
      const tok = kv.sound.split(/\s+/);
      const tail = tok.slice(-5);
      u.file = tok.slice(0, tok.length - 5).join(' ') || tok[0];
      u.unkFlag = Number(tail[0]);
      u.volume = Number(tail[1]);
      u.range = Number(tail[2]);
      u.lengthMs = Number(tail[3]);
      u.exclusive = tail[4] === 'true';
    }
    out.set(kv.name.toLowerCase(), u);
  }
  return out;
}

// ---------------------------------------------------------------- effectscene.*.txt
// <cate> N name ... <effect> id N / name X / <list> res <unit> <effectdataName> </list>
//   <scene> sceneid N / name S / <control> unitid U / active / startposition / lifetime startMs endMs / randomstart ... </control> </scene>
function parseEffectScenes(text) {
  const scenes = new Map(); // "cate:id" -> effect
  const cateNames = {};
  let cate = 0;
  const re = /<cate>\s*(\d+)[ \t]*([^\r\n]*)|<effect>([\s\S]*?)<\/effect>/g;
  for (const m of text.matchAll(re)) {
    if (m[1] !== undefined) { cate = Number(m[1]); cateNames[cate] = m[2].trim(); continue; }
    const body = m[3];
    const id = Number((/^\s*id\s+(\d+)/m.exec(body) || [])[1]);
    const name = ((/^\s*name\s+([^\r\n]+)/m.exec(body) || [])[1] || '').trim();
    const res = {};
    const list = /<list>([\s\S]*?)<\/list>/.exec(body);
    if (list) for (const r of list[1].matchAll(/res\s+(\d+)\s+(\S+)/g)) res[r[1]] = r[2];
    const sc = [];
    for (const s of body.matchAll(/<scene>([\s\S]*?)<\/scene>/g)) {
      const sid = Number((/sceneid\s+(\d+)/.exec(s[1]) || [])[1]);
      const sname = ((/^\s*name\s+([^\r\n]+)/m.exec(s[1]) || [])[1] || '').trim();
      const controls = [];
      for (const c of s[1].matchAll(/<control>([\s\S]*?)<\/control>/g)) {
        const unit = (/unitid\s+(\d+)/.exec(c[1]) || [])[1];
        const lt = /lifetime\s+(-?\d+)\s+(-?\d+)/.exec(c[1]);
        const act = /active\s+(\w+)/.exec(c[1]);
        controls.push({ unit, start: lt ? Number(lt[1]) : 0, end: lt ? Number(lt[2]) : 0, active: !act || act[1] !== 'false', randomStart: /randomstart\s+true/.test(c[1]) });
      }
      sc.push({ id: sid, name: sname, controls });
    }
    if (!Number.isFinite(id)) continue;
    const key = `${cate}:${id}`;
    if (!scenes.has(key)) scenes.set(key, { cate, id, name, res, scenes: sc });
  }
  return { scenes, cateNames };
}

const edata = parseEffectData(readText('property/effect/effectdata.snd.txt'));
const { scenes: sndScenes, cateNames } = parseEffectScenes(readText('property/effect/effectscene.snd.txt'));

/** Resolve one effect-scene (cate,id,sceneId) to a list of playable sfx. sceneId null = every scene. */
function sceneSfx(cate, id, sceneId = null, ctx = '') {
  const eff = sndScenes.get(`${cate}:${id}`);
  if (!eff) return null;
  const out = [];
  const scs = sceneId == null ? eff.scenes : eff.scenes.filter((s) => s.id === Number(sceneId));
  for (const s of scs) {
    for (const c of s.controls) {
      if (!c.active) continue;
      const unitName = eff.res[c.unit];
      const u = unitName && edata.get(unitName.toLowerCase());
      if (!u || !u.file) continue;
      const p = resolveSound(u.file, `${ctx} ${eff.name}/${unitName}`);
      if (!p) continue;
      const sfx = { path: p, vol: u.volume, range: u.range, lenMs: u.lengthMs };
      if (c.start) sfx.delayMs = c.start;
      if (u.exclusive) sfx.exclusive = true;
      if (u.unkFlag === 0) sfx.unkFlag = 0;
      out.push(sfx);
    }
  }
  return out;
}
const sfxKey = (s) => s.path + '|' + (s.delayMs || 0);
function uniqPush(arr, list) { if (!list) return arr; for (const s of list) if (!arr.some((a) => sfxKey(a) === sfxKey(s))) arr.push(s); return arr; }

// ---------------------------------------------------------------- BGM
const bgmByMapIndex = {};
{
  const rows = readCSV('script/bgsound.csv');
  const head = rows.shift().map((h) => h.trim());
  const col = (n) => head.indexOf(n);
  for (const r of rows) {
    const mi = (r[col('MapIndex')] || '').trim();
    const file = (r[col('Path')] || '').trim();
    if (!mi || !file) continue;
    const p = resolveSound(file, `bgsound map ${mi}`);
    const e = {
      path: p || file.replace(/\\/g, '/').toLowerCase(),
      delayMs: Number(r[col('DelayTime')] || 0), playCount: Number(r[col('PlayCount')] || 0),
      fadeMs: Number(r[col('FadeTime')] || 0), repeat: Number(r[col('Repeat')] || 0),
    };
    const sub = Number(r[col('SubTypeIndex')] || 0);
    if (sub) e.subType = sub;
    // Scan fix A: a missing BGM is a Global data gap, not an extraction miss. Verified 2026-10-29 for the only two
    // (map 46 BGM\Field_13_1.mp3, bgsound.csv:207; map 546 BGM\bgm_dungeon01.mp3, :745): the raw Global client
    // data/sound/bgm ships neither (only field_13.mp3). The playlist skips missing entries.
    if (!p) { e.missing = true; e.globalDataGap = true; }
    (bgmByMapIndex[mi] ||= []).push(e);
  }
}
const bgmSpecial = {
  login: '9999', charSelect: ['100', '101', '102', '103', '104', '106', '107', '113'],
  fishingStart: '1000', fishingFight: '1001', pvpAccept: '1200', pvpStart: '1201', pvpDefeat: '1202', pvpVictory: '1203',
};

// ---------------------------------------------------------------- monster.csv (needed to classify soundscript rows)
const monsters = new Map(); // index -> {name, material, shape}
{
  const rows = readCSV('share/creature/monster.csv');
  const head = rows.shift().map((h) => h.trim());
  const iI = head.indexOf('Index'), iN = head.indexOf('Name'), iM = head.indexOf('Material'), iS = head.indexOf('ShapeInfo');
  for (const r of rows) if (r[iI] && /^\d+$/.test(r[iI].trim())) monsters.set(+r[iI], { name: r[iN], material: +r[iM], shape: (r[iS] || '').trim().toLowerCase() });
}
const MIN_MONSTER_INDEX = Math.min(...monsters.keys()); // 101: anything below is not a monster index

// ---------------------------------------------------------------- soundscript.csv (cate 4 game sounds)
const ss = readCSV('script/effect/soundscript.csv');
ss.shift();
const ssRows = ss.filter((r) => r.length >= 6 && /^\d+$/.test((r[0] || '').trim()) && /^\d+$/.test((r[4] || '').trim()))
  .map((r) => ({ c1: +r[0], c2: +r[1], c3: +r[2], c4: +r[3], id: +r[4], scene: +r[5], timeMs: +r[6] || 0, desc: (r[7] || '').trim() }));
const ssSfx = (r, ctx) => sceneSfx(4, r.id, r.scene, ctx) || [];

// Name tokens from the effect names so code numbers become readable.
function effName(r) { return (sndScenes.get(`4:${r.id}`) || {}).name || ''; }
const weaponNames = {}, materialNames = {}, armorNames = {}, groundNames = {}, itemClassNames = {};
for (const r of ssRows) {
  const n = effName(r);
  let m;
  if ((r.c1 === 9 || r.c1 === 11) && (m = /^Item_(?:Drop|Set)_(\w+)/i.exec(n))) itemClassNames[r.c2] ||= m[1].toLowerCase();
  if (r.c1 === 3 && (m = /^Block_([A-Za-z]+)_([A-Za-z]+)/.exec(n))) { weaponNames[r.c2] ||= m[1].toLowerCase(); materialNames[r.c3] ||= m[2].toLowerCase(); }
  if (r.c1 === 5 && (m = /^Atk_([A-Za-z]+)_([A-Za-z]+)/.exec(n))) { weaponNames[r.c2] ||= m[1].toLowerCase(); materialNames[r.c3] ||= m[2].toLowerCase(); }
  if (r.c1 === 7 && (m = /^Mon_([A-Za-z]+)_Cut/.exec(n))) { materialNames[r.c2] ||= m[1].toLowerCase(); }
  if ((r.c1 === 1 || r.c1 === 2) && (m = /^(?:Walk|Run)_([A-Za-z]+)_([A-Za-z]+)/.exec(n))) { armorNames[r.c2] ||= m[1].toLowerCase(); groundNames[r.c3] ||= m[2].toLowerCase(); }
  if ((r.c1 === 1 || r.c1 === 2) && /^Swim/i.test(n)) groundNames[r.c3] ||= 'swim';
}

// code1=0 ("creature basic sounds"), code2 = event. The meaning of code3/code4 depends on the event:
//   code2 0..4: code3 = creature kind (0 PC, 1 monster, 2 summon), code4 = PC class / monster Index / summon index
//   code2 5 (attack voice): PC rows are "0,5,<class>,<variant 1..4>" (desc "기본 공격 사운드 (<class>)"), i.e.
//            code3 = CLASS and code4 = variant; monster/summon rows keep code3 = kind, code4 = index (>= 101).
//   code2 6 (attack sound): "0,6,<attack number 1..4>,<monster Index>" (desc "<monster>_att0N") -> ATTACK index N-1;
//            "0,6,0,0" is the colosseum crowd cheer (desc "콜로세움 환호 소리").
const CREATURE_EVENT = { 0: 'levelUp', 1: 'revive', 2: 'idle', 3: 'hit', 4: 'die', 5: 'attackVoice', 6: 'attack' };
const pcSfx = {};          // class index -> {levelUp, revive, hit, die, attackVoice}
const creatureBasic = {};  // `${kind}:${index}` -> {idle, hit, die, ...}   kind 1 = monster, 2 = servant/summon
const creatureAttack = {}; // monster index -> [sfx[] per ATTACK index]  (soundscript code2 = 6)
const hit = { block: {}, impact: {}, swing: {}, monsterCut: {} };
const footsteps = { walk: {}, run: {} };
const itemSfx = { drop: {}, pick: {}, equip: {}, get: {}, use: {} };
const ui = {};
const npcVoice = {};
const emote = {};
const system = {};
const misc = {};
const unknownCodes = {};

for (const r of ssRows) {
  const list = ssSfx(r, `soundscript ${r.c1},${r.c2},${r.c3},${r.c4}`);
  if (!list.length) continue;
  const one = list.length === 1 ? list[0] : list;
  switch (r.c1) {
    case 0: {
      const ev = CREATURE_EVENT[r.c2] || `event${r.c2}`;
      if (r.c2 === 5 && r.c4 >= 1 && r.c4 < MIN_MONSTER_INDEX && r.c3 <= 14) {
        uniqPush(((pcSfx[r.c3] ||= {}).attackVoice ||= []), list); // PC class voice, variant r.c4
      } else if (r.c2 === 6 && r.c3 === 0 && r.c4 === 0) {
        uniqPush((system.crowdKill ||= { name: effName(r), sfx: [] }).sfx, list);
      } else if (r.c2 === 6) {
        if (r.c4 >= MIN_MONSTER_INDEX && r.c3 >= 1) { const a = (creatureAttack[r.c4] ||= []); a[r.c3 - 1] = uniqPush(a[r.c3 - 1] || [], list); }
        else uniqPush((unknownCodes[`${r.c1}:${r.c2}:${r.c3}:${r.c4}`] ||= []), list);
      } else if (r.c3 === 0) {
        uniqPush(((pcSfx[r.c4] ||= {})[ev] ||= []), list);
      } else if (r.c3 === 1 && r.c4 < MIN_MONSTER_INDEX) {
        // not a monster index: e.g. "0,1,1,2" (archer revive on "monster 2"). Indices >= 101 that are missing from
        // monster.csv (retired monsters with act files, e.g. 2005 ruinnel) are kept like the act-file sets.
        uniqPush((unknownCodes[`${r.c1}:${r.c2}:${r.c3}:${r.c4}`] ||= []), list);
      } else {
        uniqPush((((creatureBasic[`${r.c3}:${r.c4}`] ||= {}))[ev] ||= []), list);
      }
      break;
    }
    case 1: case 2: {
      const kind = r.c1 === 1 ? 'walk' : 'run';
      const a = String(r.c2), g = groundNames[r.c3] || String(r.c3); // armor keyed by code (0 = default, see codes.armor)
      uniqPush(((footsteps[kind][a] ||= {})[g] ||= []), list);
      break;
    }
    case 3: uniqPush(((hit.block[weaponNames[r.c2] || r.c2] ||= {})[materialNames[r.c3] || r.c3] ||= []), list); break;
    case 5: uniqPush(((hit.impact[weaponNames[r.c2] || r.c2] ||= {})[materialNames[r.c3] || r.c3] ||= []), list); break;
    case 6: uniqPush((hit.swing[weaponNames[r.c2] || r.c2] ||= []), list); break;
    case 7: uniqPush((hit.monsterCut[materialNames[r.c2] || r.c2] ||= []), list); break;
    case 9: uniqPush((itemSfx.drop[r.c2] ||= []), list); break;
    case 10: uniqPush((itemSfx.pick[r.c2] ||= []), list); break;
    case 11: uniqPush((itemSfx.equip[r.c2] ||= []), list); break;
    case 12: uniqPush((itemSfx.get[r.c2] ||= []), list); break;
    case 13: uniqPush((itemSfx.use[r.c2] ||= []), list); break;
    case 15: {
      // code3 = the `sound N` attribute of window-script buttons (407x `sound 0`, 14x `sound 1`).
      // Effect 472 "UI_button": scene 1 = sd_UI_Press_Non (ui_press_main_00), 2 = sd_UI_Press_Com (ui_com_button),
      // 3 = sd_UI_Press_exit; rows map code3 0 -> scene 2, 1 -> scene 1, 2 -> scene 3. Effect 748: open/close box.
      const names = { 0: 'buttonCommon', 1: 'buttonMain', 2: 'buttonExit', 3: 'boxOpen', 4: 'boxClose' };
      uniqPush((ui[names[r.c3] || `ui${r.c3}`] ||= []), list);
      uniqPush(((ui.bySoundCode ||= {})[r.c3] ||= []), list);
      break;
    }
    case 18: uniqPush((npcVoice[r.c3] ||= []), list); break;
    case 22: {
      const n = effName(r).replace(/^sd_/i, '');
      uniqPush((system[`${r.c2}${r.c3 || r.c4 ? `:${r.c3}:${r.c4}` : ''}`] ||= { name: n, sfx: [] }).sfx, list); break;
    }
    case 23: uniqPush(((emote[r.c2] ||= {})[r.c3] ||= []), list); break;
    case 42: uniqPush((misc[`${r.c2}:${r.c3}:${r.c4}`] ||= []), list); break;
    default: uniqPush((unknownCodes[`${r.c1}:${r.c2}:${r.c3}:${r.c4}`] ||= []), list);
  }
  void one;
}
// Friendly UI aliases (from system messages + common unit names).
const sysByName = {};
for (const [k, v] of Object.entries(system)) sysByName[v.name.toLowerCase()] ||= { key: k, sfx: v.sfx };
// Spoken HUD warnings: take vol/lenMs/exclusive from their effectdata unit `sd_<name>` when it exists
// (sd_lack_of_HP: vol 80, lenMs 10000, exclusive -> at most one "lack of HP" every 10 s).
for (const n of ['lack_of_hp', 'lack_of_mana', 'lack_of_space', 'lack_of_arrow', 'lack_of_bolt', 'lack_of_dil', 'lack_of_fury', 'unsuitable_item']) {
  const p = resolveSound(`message/${n}.wav`, 'ui message');
  if (!p) continue;
  const u = edata.get(`sd_${n}`);
  const s = { path: p, vol: u ? u.volume : 100 };
  if (u) { s.range = u.range; s.lenMs = u.lengthMs; if (u.exclusive) s.exclusive = true; }
  ui[n.replace(/_(\w)/g, (_, c) => c.toUpperCase())] = [s];
}

// ---------------------------------------------------------------- modeleffect.csv: action Effect id -> sound
// modeleffect code1=25 rows are namespaced by code2 = creature kind (the same Effect id means different
// things for a PC, a monster or a servant): 0 pc, 1 monster, 2 servant, 4 trigger/object, 5 brick
// (destructible), 6 guard, 8 totem (sacra). code3 is 1 for almost everything (0 = servant "enter",
// totem "stand"); keys are "<id>" for code3 = 1 and "<code3>:<id>" otherwise.
const KIND_NAMES = { 0: 'pc', 1: 'monster', 2: 'servant', 4: 'trigger', 5: 'brick', 6: 'guard', 8: 'totem' };
// 9 keys occur twice (e.g. monster 100 = "agathion_att3" and later "Dabih walk"); every act table that uses those
// ids is the FIRST row's monster (agathion ATTACK2 / DEAD0), so the first row wins (later duplicates ignored).
const actionEffectSfx = {}; // kind -> key -> sfx[]
const modelEffectDupes = [];
{
  const rows = readCSV('script/effect/modeleffect.csv'); rows.shift();
  const seen = new Set();
  for (const r of rows) {
    if ((r[0] || '').trim() !== '25' || !r[3]) continue;
    const kind = KIND_NAMES[+r[1]] || `kind${+r[1]}`;
    const c3 = +r[2];
    const eff = +r[3], cate = +r[4], id = +r[5], scene = +r[6];
    const key = c3 === 1 ? String(eff) : `${c3}:${eff}`;
    if (seen.has(`${kind}/${key}`)) { modelEffectDupes.push(`${kind}/${key}`); continue; }
    seen.add(`${kind}/${key}`);
    const list = sceneSfx(cate, id, scene, `modeleffect ${kind} ${key}`);
    if (list && list.length) uniqPush(((actionEffectSfx[kind] ||= {})[key] ||= []), list);
  }
}

// ---------------------------------------------------------------- monsters
// Monster action tables. The monster index of a table is its HEADER `Index` row, NOT the file name:
// share/action/monster uses three naming styles (`110.moth.act.csv`, `spider.act.102.csv`,
// `5097_lamina_summoner.act.csv`, plus stray `x.act..csv` / `x_act.csv`) and some names state the wrong index
// (`8074.yetirion.act.csv` holds Index 8075, `catastrophe.act.2808.csv` holds 505). See docs/formats/monsters.md.
// Source 1 (preferred): gamedata/monsters.json - the monsters builder's chosen table per index (compiled
//   share/action/action/monster/*.act.dat, i.e. exactly the clips the engine animates): actionSets[act].actions
//   {ACTION: [clip per action index]} and clips[i][clipFields.effect / .timing].
// Source 2: every share/action/monster/*.csv keyed by its Index row. Fills rows without a clip (REVIVE carries
//   an Effect but no animation, so it is absent from monsters.json) and indices monsters.json does not list
//   (retired monsters). Where both give a non-zero Effect for the same (action, index) the compiled table wins.
const ACTION_KEY = { ATTACK: 'attack', DEAD: 'die', SM_DEAD: 'die', DEFEAT: 'hit', STAND: 'idle', SM_STAND: 'idle', MOVE: 'move', SM_MOVE: 'move', REVIVE: 'revive', ENTER: 'enter', LEAVE: 'leave', BLOCKED: 'blocked', BLOCKING: 'blocking', GUARDING: 'guarding' };
const actStats = { csvFiles: 0, csvIndices: 0, csvNameIndexMismatch: 0, jsonIndices: 0, jsonUsed: false, rows: 0, rowsFromCsvOnly: 0 };
// index -> Map("ACTION:i" -> {eff, timing})
const csvTables = new Map();
{
  const actDir = path.join(DATA, 'share', 'action', 'monster');
  for (const f of fs.readdirSync(actDir)) {
    if (!/\.csv$/i.test(f) || fs.statSync(path.join(actDir, f)).isDirectory()) continue;
    const rows = parseCSV(decodeText(fs.readFileSync(path.join(actDir, f)), true));
    const ir = rows.find((r) => (r[0] || '').trim() === 'Index');
    const head = rows.find((r) => (r[0] || '').trim() === 'Style');
    if (!ir || !head || !/^\d+$/.test((ir[1] || '').trim())) continue;
    actStats.csvFiles++;
    const idx = +ir[1];
    const nameNum = (/(?:^|\.)(\d+)(?=[._])/.exec(f) || [])[1];
    if (nameNum && +nameNum !== idx) actStats.csvNameIndexMismatch++;
    const ei = head.findIndex((h) => h.trim() === 'Effect'), ti = head.findIndex((h) => h.trim() === 'Timing');
    const table = new Map();
    for (const r of rows) {
      if (!/^\d+$/.test((r[0] || '').trim())) continue;
      const eff = ei >= 0 ? +r[ei] || 0 : 0;
      if (!eff) continue;
      table.set(`${(r[1] || '').trim().toUpperCase()}:${+r[2] || 0}`, { eff, timing: ti >= 0 ? Number(r[ti]) || 0 : 0 });
    }
    // Several files may claim one index: keep the one whose file name agrees with the header, else the richer one.
    const prev = csvTables.get(idx);
    const score = (nameNum && +nameNum === idx ? 1e6 : 0) + table.size;
    if (!prev || score > prev.score) csvTables.set(idx, { table, score, file: f });
  }
  actStats.csvIndices = csvTables.size;
}
const jsonTables = new Map();
{
  const mj = path.join(GD, 'monsters.json');
  if (fs.existsSync(mj)) {
    const M = JSON.parse(fs.readFileSync(mj, 'utf8'));
    const EI = (M.clipFields || []).indexOf('effect'), TI = (M.clipFields || []).indexOf('timing');
    if (EI >= 0 && M.monsters && M.actionSets) {
      actStats.jsonUsed = true;
      for (const [idx, mon] of Object.entries(M.monsters)) {
        const set = mon && mon.act && M.actionSets[mon.act];
        if (!set || !set.actions) continue;
        const table = new Map();
        for (const [action, list] of Object.entries(set.actions)) {
          (list || []).forEach((ci, i) => {
            const clip = ci >= 0 ? set.clips[ci] : null;
            const eff = clip ? +(clip[EI] || 0) : 0;
            if (eff) table.set(`${action.toUpperCase()}:${i}`, { eff, timing: clip && TI >= 0 ? +(clip[TI] || 0) : 0 });
          });
        }
        jsonTables.set(+idx, table);
      }
      actStats.jsonIndices = jsonTables.size;
    }
  }
}
const perIndex = new Map(); // monster index -> sfx set
let actRefs = 0, actResolved = 0;
for (const idx of new Set([...jsonTables.keys(), ...csvTables.keys()])) {
  const merged = new Map(jsonTables.get(idx) || []);
  for (const [k, v] of (csvTables.get(idx) || { table: new Map() }).table) if (!merged.has(k)) { merged.set(k, v); actStats.rowsFromCsvOnly++; }
  if (!merged.size) continue;
  const set = perIndex.get(idx) || { shape: (monsters.get(idx) || {}).shape || (csvTables.get(idx)?.file || `index${idx}`).replace(/\.csv$/i, '').toLowerCase() };
  for (const [k, { eff, timing }] of merged) {
    actStats.rows++; actRefs++;
    const list = (actionEffectSfx.monster || {})[eff];
    if (!list) continue;
    actResolved++;
    const [action, aiStr] = k.split(':'); const ai = +aiStr;
    const key = ACTION_KEY[action] || action.toLowerCase();
    if (key === 'attack') {
      set.attack ||= [];
      set.attack[ai] = uniqPush(set.attack[ai] || [], list);
      if (timing) (set.attackTiming ||= [])[ai] = timing; // hit moment (fraction of TimeLength) - informative
    } else uniqPush((set[key] ||= []), list);
  }
  perIndex.set(idx, set);
}
// Per-attack monster sounds from soundscript (code1=0, code2=6): ATTACK index i plays these as well.
for (const [idx, list] of Object.entries(creatureAttack)) {
  const set = perIndex.get(+idx) || { shape: (monsters.get(+idx) || {}).shape || `index${idx}` };
  set.attack ||= [];
  list.forEach((l, i) => { if (l) set.attack[i] = uniqPush(set.attack[i] || [], l); });
  perIndex.set(+idx, set);
}
// Merge the generic creature sounds (soundscript code1=0, kind 1) into the per-index sets.
for (const [k, v] of Object.entries(creatureBasic)) {
  const [kind, idx] = k.split(':').map(Number);
  if (kind !== 1) continue;
  const set = perIndex.get(idx) || { shape: (monsters.get(idx) || {}).shape || `index${idx}` };
  for (const [ev, list] of Object.entries(v)) {
    const key = ev === 'attackVoice' ? 'attackVoice' : ev;
    uniqPush((set[key] ||= []), list);
  }
  perIndex.set(idx, set);
}
// Group by ShapeInfo (monster.csv) - identical sets share one entry; variants get "shape@index".
const monsterSfx = {};
const monsterSfxIndex = {};
const canon = (s) => JSON.stringify(Object.entries(s).filter(([k]) => k !== 'shape' && k !== 'material').sort());
for (const [idx, set] of [...perIndex.entries()].sort((a, b) => a[0] - b[0])) {
  if (set.attack) for (let i = 0; i < set.attack.length; i++) set.attack[i] ||= [];
  const mon = monsters.get(idx);
  const shape = (mon && mon.shape) || set.shape;
  const entry = { ...set }; delete entry.shape;
  if (mon) entry.material = materialNames[mon.material] || mon.material;
  if (Object.keys(entry).filter((k) => k !== 'material').length === 0) continue;
  if (!monsterSfx[shape]) { monsterSfx[shape] = entry; monsterSfxIndex[idx] = shape; }
  else if (canon(monsterSfx[shape]) === canon(entry)) monsterSfxIndex[idx] = shape;
  else { monsterSfx[`${shape}@${idx}`] = entry; monsterSfxIndex[idx] = `${shape}@${idx}`; }
}
const summonSfx = {};
for (const [k, v] of Object.entries(creatureBasic)) { const [kind, idx] = k.split(':'); if (kind !== '1') summonSfx[`${kind}:${idx}`] = v; }

// ---------------------------------------------------------------- skills (cate 100), ambient (cate 3), everything else
function sceneTable(cate) {
  const out = {};
  for (const eff of sndScenes.values()) {
    if (eff.cate !== cate) continue;
    const scenes = {};
    for (const s of eff.scenes) {
      const l = sceneSfx(cate, eff.id, s.id, `cate ${cate}`);
      if (l && l.length) scenes[s.id] = l;
    }
    if (Object.keys(scenes).length) out[eff.id] = { name: eff.name, scenes };
  }
  return out;
}
const skill = sceneTable(100);
const ambient = sceneTable(3);
const effectSound = {};
for (const c of Object.keys(cateNames).map(Number)) if (![100, 3].includes(c)) effectSound[c] = sceneTable(c);

// ---------------------------------------------------------------- write
const json = {
  version: 1,
  generatedBy: 'tools/build-sound.mjs',
  note: 'Paths are relative to /sound/ (server tries data/unpacked/data/sound then data/sound). sfx = {path, vol(0-600, 100=normal), range(m), lenMs, delayMs?, exclusive?(voice line: play once, ignore re-triggers for lenMs), unkFlag?(raw effectdata flag, 0 only; NOT a 2D flag)}. effectdata has no loop flag: looping comes from the caller (.mel period >= 1e6, a repeating STAND action). See docs/formats/sound.md.',
  codes: { weapon: weaponNames, material: materialNames, armor: armorNames, ground: groundNames, itemClass: itemClassNames, creatureEvent: CREATURE_EVENT, effectCategories: cateNames },
  bgmByMapIndex, bgmSpecial,
  monsterSfx, monsterSfxIndex,
  pcSfx, summonSfx,
  hit, footsteps,
  ui, system, item: itemSfx, npcVoice, emote, misc,
  actionEffectSfx,
  skill, ambient, effectSound,
  unknownCodes,
  missing: Object.fromEntries([...missing.entries()].sort()),
};
fs.mkdirSync(path.dirname(OUT), { recursive: true });
fs.writeFileSync(OUT, JSON.stringify(json));

// ---------------------------------------------------------------- summary / validation
let sfxCount = 0; const refFiles = new Set(); let badPaths = 0;
(function walk(o) {
  if (Array.isArray(o)) return o.forEach(walk);
  if (o && typeof o === 'object') {
    if (typeof o.path === 'string' && ('vol' in o || 'delayMs' in o || 'playCount' in o)) {
      sfxCount++; refFiles.add(o.path);
      if (!o.missing && !soundFiles.has(o.path)) badPaths++;
    }
    for (const [k, v] of Object.entries(o)) if (k !== 'missing') walk(v);
  }
})(json);
const count = (o) => Object.keys(o).length;
console.log(`sound files indexed: ${soundFiles.size} (${SOUND_ROOTS.join(' | ')})`);
console.log(`effectdata.snd units: ${edata.size}, effectscene.snd effects: ${sndScenes.size}`, cateNames);
console.log(`soundscript rows: ${ssRows.length}`);
console.log(`BGM: ${count(bgmByMapIndex)} map indices, ${Object.values(bgmByMapIndex).flat().length} entries, ${Object.values(bgmByMapIndex).flat().filter((e) => e.missing).length} missing`);
console.log(`monster action tables: monsters.json ${actStats.jsonUsed ? actStats.jsonIndices + ' indices' : 'NOT FOUND (run tools/build-monsters.mjs first for full coverage)'}; csv ${actStats.csvFiles} files -> ${actStats.csvIndices} indices by header Index (${actStats.csvNameIndexMismatch} file names state another index); rows with Effect ${actRefs} (${actStats.rowsFromCsvOnly} from csv only), with sound ${actResolved}`);
console.log(`monsterSfx: ${count(monsterSfx)} entries covering ${count(monsterSfxIndex)} monster indices (of ${monsters.size} in monster.csv)`);
console.log(`pcSfx classes: ${Object.keys(pcSfx).join(',')}; summon/other creature sets: ${count(summonSfx)}`);
console.log(`hit: block ${count(hit.block)} weapons, impact ${count(hit.impact)}, swing ${count(hit.swing)}, monsterCut ${count(hit.monsterCut)} materials; footsteps walk ${count(footsteps.walk)} run ${count(footsteps.run)} armors`);
console.log(`ui keys: ${Object.keys(ui).join(', ')}`);
console.log(`items: drop ${count(itemSfx.drop)} pick ${count(itemSfx.pick)} equip ${count(itemSfx.equip)} get ${count(itemSfx.get)} use ${count(itemSfx.use)}; npcVoice ${count(npcVoice)}; emote ${count(emote)}; system ${count(system)}`);
console.log(`actionEffectSfx: ${JSON.stringify(Object.fromEntries(Object.entries(actionEffectSfx).map(([k, v]) => [k, count(v)])))}; skill scenes: ${count(skill)}; ambient: ${count(ambient)}; other cates: ${JSON.stringify(Object.fromEntries(Object.entries(effectSound).map(([k, v]) => [k, count(v)])))}`);
console.log(`unknown soundscript codes: ${count(unknownCodes)}; modeleffect code1=25 duplicate keys ignored (first row wins): ${modelEffectDupes.join(', ') || 'none'}`);
console.log(`resolution: ${JSON.stringify(resolveStats)}; distinct missing: ${missing.size}`);
console.log([...missing.entries()].slice(0, 20).map(([p, c]) => `   missing ${p}  (${c.trim()})`).join('\n'));
console.log(`sfx references written: ${sfxCount}, distinct files: ${refFiles.size}, paths not on disk: ${badPaths}`);
console.log(`wrote ${OUT} (${(fs.statSync(OUT).size / 1024).toFixed(0)} KB)`);
// Spot checks
const sample = ['bison', 'spiderraba', 'moth'].map((s) => [s, monsterSfx[s] && Object.keys(monsterSfx[s])]);
console.log('spot check monsterSfx keys:', JSON.stringify(sample));
console.log('bison attack[0]:', JSON.stringify(monsterSfx.bison?.attack?.[0]));
console.log('map 0 bgm:', JSON.stringify(bgmByMapIndex['0']));
