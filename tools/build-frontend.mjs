// Builds gamedata/frontend.json: the data of the character-create "Preview" tab (ui_classselectwnd.txt
// pan_equip_info: right-hand weapon / armour set / left-hand weapon buttons + the item list).
//
// Source: script/producer/char_iteminfo.txt, one line per item: class,set,itemIndex,name(KR)
//   set 0   = a weapon of the class (right or left hand by the item's weapon rule)
//   set N>0 = an armour set, N = stringtable_loginmsg <cate> 31 code N (EU set name); its five parts
// Joined with gamedata/items.json (EU names, slot, weapon code), items-looks.json (per-class meshes) and
// items-visual.json (inventory model of each item = the icon of the item slots) and the weapon bones
// (items.json equipment.weaponBones[class][weaponType], weaponRules[code]).
//
//   node tools/build-frontend.mjs
import { readFileSync, writeFileSync } from 'fs';
import { dirname, join } from 'path';
import { fileURLToPath } from 'url';
import { stripBOM } from '../src/formats/binreader.js';

const HERE = dirname(fileURLToPath(import.meta.url));
const ROOT = join(HERE, '..');
const DATA = process.env.DEKARON_DATA || join(ROOT, '..', 'data', 'unpacked', 'data');
const GD = process.env.DEKARON_GAMEDATA || join(ROOT, 'gamedata');
const rd = rel => new TextDecoder('euc-kr').decode(stripBOM(readFileSync(join(DATA, rel))));
const json = rel => JSON.parse(readFileSync(join(GD, rel.replace(/^gamedata\//, '')), 'utf8'));

const items = json('gamedata/items.json');
const looks = json('gamedata/items-looks.json');
const visual = json('gamedata/items-visual.json');
const E = items.equipment;
const PART_OF = { helmet: 'helmet', armor: 'coat', pants: 'pants', glove: 'glove', boots: 'boots' };

const asset = id => (id == null ? null : looks.assets[id] || null);
const lookAsset = (lk, cls) => asset(lk?.byClass?.[cls] ?? lk?.all);

function inv(it) {
  const s = it && visual.shapes[it.shape];
  return s?.inv ? { ...s.inv, twoSide: !!s.invTwoSide } : null;
}

const out = { version: 1, generatedBy: 'tools/build-frontend.mjs', source: 'script/producer/char_iteminfo.txt', classes: {} };
const missing = [];
const lines = rd('script/producer/char_iteminfo.txt').split(/\r?\n/);
for (const line of lines) {
  const c = line.split(',');
  if (c.length < 3) continue;
  const cls = Number(c[0]), set = Number(c[1]), idx = Number(c[2]);
  if (!Number.isFinite(cls) || !Number.isFinite(set) || !Number.isFinite(idx)) continue;
  const C = out.classes[cls] ||= { sets: [], weapons: [] };
  const it = items.items[String(idx)];
  const lk = looks.looks[String(idx)];
  if (!it || !lk) { missing.push(`${cls},${set},${idx} ${c[3] || ''}`); continue; }
  if (set > 0) {
    let S = C.sets.find(s => s.id === set);
    if (!S) { S = { id: set, parts: {}, items: {} }; C.sets.push(S); }
    const part = PART_OF[it.slot] || lk.parts?.[0];
    const a = lookAsset(lk, cls);
    if (part && a) { S.parts[part] = a; S.items[part] = { item: idx, name: it.name, inv: inv(it) }; }
    else missing.push(`${cls},${set},${idx} no mesh`);
    continue;
  }
  // weapon
  const rule = E.weaponRules[String(it.code)] || {};
  const wt = lk.weaponType ?? rule.weaponType;
  const bones = E.weaponBones?.[String(cls)]?.[String(wt)] || null;
  const main = lookAsset(lk, cls);
  if (!main) { missing.push(`${cls},0,${idx} weapon without mesh`); continue; }
  const left = lk.left != null ? asset(lk.left) : null;
  const hand = rule.offhand || it.slot === 'offhand' ? 'left' : 'right';
  C.weapons.push({
    item: idx, name: it.name, hand, slot: it.slot, code: it.code, hands: rule.hands || 1, column: rule.column || 'right',
    weaponType: wt, style: rule.style ?? null, label: rule.label || '', main, left, bones, inv: inv(it),
  });
}
// order: sets by id, weapons as listed. Set names: stringtable_loginmsg <cate> 31 code <set> at runtime; a few sets
// (179.. "Royal Mone Bloodvein", ...) have no entry there, so a fallback name is derived from the parts' EU item
// names (their common words minus the part word and the class suffix).
const PART_WORDS = /\b(helmet|helm|hat|armor|armour|coat|pants|boots|shoes|gloves?|gauntlets?|robe|hood|cap|mask)\b/gi;
for (const C of Object.values(out.classes)) {
  C.sets.sort((a, b) => a.id - b.id);
  for (const S of C.sets) {
    const names = Object.values(S.items).map(i => String(i.name || '').replace(/\s*\([^)]*\)\s*$/, '').replace(PART_WORDS, '').replace(/\s+/g, ' ').trim());
    const first = names[0] || '';
    S.name = names.every(n => n === first) && first ? `${first} Set` : first ? `${first} Set` : `Set ${S.id}`;
  }
}
out.missing = missing;
const file = join(GD, 'frontend.json');
writeFileSync(file, JSON.stringify(out));
const n = Object.values(out.classes).reduce((a, C) => a + C.sets.length + C.weapons.length, 0);
console.log(`frontend.json: ${Object.keys(out.classes).length} classes, ${n} entries, ${missing.length} missing -> ${file}`);
if (missing.length) console.log(missing.slice(0, 20).join('\n'));
