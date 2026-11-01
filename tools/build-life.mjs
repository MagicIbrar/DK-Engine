// Builder of gamedata/life.json (+ life_rebirth.json): every table the life/social systems (src/systems/life) need,
// straight from the client data, with English text from script/lines_eu where the csv carries Korean.
//   node tools/build-life.mjs [--data <unpacked data root>] [--pretty]
//
// Sections (docs/formats/life.md describes each one and the decisions):
//   fishing      share/fishing/{fishingrod,fish,fishingskill,fish_notify}.csv + share/arrange/cell.csv fishing rows
//                + the fish item sets (share/item/itemset.csv) + rod / bait items
//   craft        share/craft/{craft,craft_exp}.csv + script/product/product_list_*.csv trees
//   dekapass     share/dekapass/*.csv
//   events       share/event/*.csv (virus/vaccine, event time, OX quiz), script/contents_timetable/daystable.csv
//                (English via lines_eu), script/eventinfo/*
//   premiere     share/premiere/{teleport,respon,cash_randombox}.csv
//   guild        share/guild/*.csv, share/guildobserver/info.csv, script/guild/guilduniquename*.csv
//   party        share/partysearch/matchingmap.csv, share/pc/groupexpratio.csv
//   grade        share/pc/awakening/*.csv, share/pc/gradecap/*.csv, share/pc/title/title_base.csv
//   pk           share/pc/{chaotic,pkcount,pklevelcap}.csv
//   monsterGrade share/creature/monster.csv Wgrade / DwGradeExp / ChaoticLevel / P_point (only non-zero rows)
//   classMotions share/action/action/pc/*.act.*.dat: fishing (style 23), MOTION (emotes, levers 100/101, costume 700+),
//                EMOTION start/keep/end (sit), SURRENDER - per class
//   cosmotion    script/cosmotion/cosmotion.csv ; interactive  script/interactiveaction/triggerinteractiveaction.csv
//   weather      property/effect/effectscene.com.txt cate 10 + the weather/sound units it lists
//   items        name / size / inventory model of every item any of the above references
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { BinReader, parseCSV } from '../src/formats/binreader.js';
import { parseActionDat } from '../src/formats/modeldef.js';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ENGINE = path.resolve(HERE, '..');
const argv = process.argv.slice(2);
const arg = (k) => { const i = argv.indexOf(k); return i >= 0 ? argv[i + 1] : null; };
const DATA = path.resolve(arg('--data') || process.env.DEKARON_DATA || path.resolve(ENGINE, '../data/unpacked/data'));
const OUT = path.resolve(arg('--out') || process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata'));
const PRETTY = argv.includes('--pretty');
const log = (...a) => console.log(...a);
const warn = [];

const euckr = new TextDecoder('euc-kr');
const utf16 = new TextDecoder('utf-16le');
const readRel = (rel) => fs.readFileSync(path.join(DATA, rel));
const existsRel = (rel) => { try { return fs.statSync(path.join(DATA, rel)).isFile(); } catch { return false; } };
function textRel(rel) {
  const b = readRel(rel);
  if (b[0] === 0xff && b[1] === 0xfe) return utf16.decode(b.subarray(2));
  if (b[0] === 0xef && b[1] === 0xbb && b[2] === 0xbf) return new TextDecoder('utf-8').decode(b.subarray(3));
  return euckr.decode(b);
}
const csvRel = (rel) => parseCSV(textRel(rel)).map((r) => (r || []).map((c) => String(c ?? '').trim()));
const num = (v, d = 0) => { const s = String(v ?? '').trim(); const x = Number(s); return s !== '' && Number.isFinite(x) ? x : d; };
const hasHangul = (s) => /[ㄱ-ㆎ가-힣]/.test(String(s || ''));
function table(rel) {
  const rows = csvRel(rel);
  const header = rows[0] || [];
  const out = [];
  rows.slice(1).forEach((r, i) => {
    if (!r.some((c) => c !== '')) return;
    const o = { _row: i + 1 };
    header.forEach((h, k) => { if (h !== '') o[h] = r[k] ?? ''; });
    out.push(o);
  });
  return { header, rows: out, raw: rows };
}
const typed = (o) => { const r = {}; for (const [k, v] of Object.entries(o)) { if (k === '_row') continue; const s = String(v); r[k] = s !== '' && Number.isFinite(Number(s)) ? Number(s) : v; } return r; };

// ------------------------------------------------------------------------------------------ lines_eu
function parseLinesEu(buf) {
  const r = new BinReader(buf);
  const wstr = (n) => utf16.decode(r.bytes(n * 2));
  const readIndex = () => { const n = r.u32(); const files = []; for (let i = 0; i < n; i++) { const name = wstr(r.u32()); const c = r.u32(); const cols = []; for (let k = 0; k < c; k++) cols.push([r.i32(), r.i32()]); files.push({ name, cols }); } return files; };
  readIndex(); readIndex();
  const nStr = r.u32(); const strings = new Map();
  for (let i = 0; i < nStr; i++) { const id = r.u32(); strings.set(id, wstr(r.u32())); }
  const keys = new Map();
  for (let pass = 0; pass < 2; pass++) { const n = r.u32(); for (let i = 0; i < n; i++) { const k = wstr(r.u32()); keys.set(k, r.u32()); } }
  return { strings, keys };
}
const LINES = parseLinesEu(readRel('script/lines_eu'));
const L = (key) => { const id = LINES.keys.get(key); return id ? (LINES.strings.get(id) ?? null) : null; };
/** English text of a csv cell: lines_eu "<folder>#<file>#<col>|<row>" when the csv text is Korean (or always when prefer). */
const En = (folderFile, col, row, csvText) => { const l = L(`${folderFile}#${col}|${row}`); return l && (hasHangul(csvText) || !csvText) ? l.trim() : (csvText ?? l ?? ''); };

// ------------------------------------------------------------------------------------------ items (subset)
const ITEMS = JSON.parse(fs.readFileSync(path.join(OUT, 'items.json'), 'utf8'));
const VIS = JSON.parse(fs.readFileSync(path.join(OUT, 'items-visual.json'), 'utf8'));
const D = ITEMS.itemDefaults || {};
const wantItems = new Set();
const needItem = (i) => { i = num(i); if (i > 0) wantItems.add(i); return i; };
function itemOut(i) {
  const raw = ITEMS.items[String(i)];
  if (!raw) return null;
  const it = { ...D, ...raw };
  const shape = VIS.shapes?.[String(it.shape)] || null;
  const o = { name: it.name, type: it.type, code: it.code, w: it.w, h: it.h, rank: it.rank || 0 };
  if (it.stack) o.stack = it.stack;
  if (it.maxStack) o.maxStack = it.maxStack;
  if (it.value1) o.value1 = it.value1;
  if (it.reqLv) o.reqLv = it.reqLv;
  if (it.slot) o.slot = it.slot;
  if (it.price) o.price = it.price;
  if (it.period) o.period = it.period;
  if (it.options?.length) o.options = it.options;
  if (it.desc) o.desc = it.desc;
  if (it.quality != null) o.quality = it.quality;
  if (shape?.inv) { o.inv = shape.inv; if (shape.invTwoSide != null) o.inv = { ...shape.inv, twoSide: !!shape.invTwoSide }; }
  if (it.use) o.use = it.use;
  return o;
}

// ------------------------------------------------------------------------------------------ item sets
const ITEMSET = new Map();
{
  const rows = csvRel('share/item/itemset.csv');
  for (const r of rows.slice(1)) {
    const idx = num(r[0], -1); if (idx < 0 || ITEMSET.has(idx)) continue;
    const count = num(r[3]);
    const items = [];
    for (let k = 0; k < 50; k++) {
      const b = 4 + k * 5;
      const it = num(r[b]); if (!it) continue;
      items.push([it, num(r[b + 1]), num(r[b + 2]), num(r[b + 3]), num(r[b + 4])]);
    }
    ITEMSET.set(idx, { total: num(r[2]), count, items });
  }
}
const setOut = (i) => { const s = ITEMSET.get(num(i)); if (!s) { warn.push(`itemset ${i} missing`); return null; } for (const [it] of s.items) needItem(it); return s; };

const out = { version: 1, generatedBy: 'tools/build-life.mjs', generatedAt: new Date().toISOString() };

// ------------------------------------------------------------------------------------------ fishing
{
  const rods = {};
  const rodTab = table('share/fishing/fishingrod.csv');
  const rodNames = { 1: 'Nibbler Fishing Rod', 2: 'Bamboo Fishing Rod', 3: 'Seagull Fishing Rod', 4: 'Red Lava Fishing Rod', 5: 'Blue Bear Fishing Rod', 6: 'Duron Fishing Rod', 7: 'Basic Auto Fishing Rod', 8: 'Cash Auto Fishing Rod', 9: 'Unique Auto Fishing Rod', 255: 'Fishing Rod' };
  for (const r of rodTab.rows) {
    const i = num(r.Index);
    rods[i] = { name: rodNames[i] || r.Name, maxHp: num(r.MaxHP), recovery: num(r.Recovery), strength: num(r.Strength), reqLevel: num(r.RequirePCLevel), reqSkill: num(r.RequireFishSkillLevel), auto: i >= 7 && i <= 9 };
  }
  // fish.csv is transposed: column k = fish k
  const fr = csvRel('share/fishing/fish.csv');
  const byKey = new Map(fr.filter((r) => r[0]).map((r) => [r[0], r]));
  const ids = (byKey.get('Index') || []).slice(1).map((x) => num(x)).filter((x) => x > 0);
  const fish = {};
  const fishNames = ['Small Fish', 'Medium Fish', 'Large Fish'];
  ids.forEach((id, k) => {
    const g = (key) => num((byKey.get(key) || [])[k + 1]);
    const sets = [];
    for (let s = 1; s <= 15; s++) { const si = g(`ItemSetIndex_${s}`), ratio = g(`ItemSetDropRatio_${s}`); if (si && ratio) { sets.push([si, ratio]); setOut(si); } }
    const rank = g('Rank');
    fish[id] = { name: id >= 46 ? ['Basic Auto Fishing', 'Cash Auto Fishing', 'Unique Auto Fishing'][id - 46] : fishNames[rank - 1] || 'Fish',
      rank, exp: g('Exp'), maxHp: g('MaxHP'), startHp: g('StartHP'), recovery: g('Recovery'), strength: g('Strength'),
      resistRatio: g('ResistRatio'), resistMin: g('ResistTimeMin'), resistMax: g('ResistTimeMax'), delayMin: g('DelayTimeMin'), delayMax: g('DelayTimeMax'),
      itemSetCount: g('ItemSetCount'), sets };
  });
  const cells = {};
  const cellTab = table('share/arrange/cell.csv');
  const regionEn = { 100: 'Test', 101: 'Braiken Castle / Loa Castle', 102: 'North Ares / West Morte / East Ares', 103: 'Deneb', 104: 'Requies', 105: 'Avalon',
    201: 'Heihaff', 202: 'Heihaff area 2', 203: 'Parca Temple', 204: 'Parca Temple area 2', 205: 'Crespo', 301: 'Norak / Castor 1F', 302: 'Norak / Castor 1F area 2', 303: 'Norak / Castor 2F', 304: 'Norak / Castor 2F area 2', 305: 'Draco Desert' };
  for (const r of cellTab.rows) {
    const i = num(r.Cell_Index);
    if (String(r.Fishing).toUpperCase() !== 'Y' && !(i >= 100 && i <= 310)) continue;
    const list = [];
    for (let k = 1; k <= 10; k++) { const f = num(r[`FishIndex_${k}`]), p = num(r[`FishRatio_${k}`]); if (f && p) list.push([f, p]); }
    cells[i] = { fishing: String(r.Fishing).toUpperCase() === 'Y', blocked: String(r.Blocked).toUpperCase() === 'Y', region: regionEn[i] || regionEn[i - 5] || '',
      skillMin: num(r.FishSkillLevelMin), casting: num(r.FishingCasting), fishCount: num(r.FishCount), fish: list,
      auto: [num(r.AutoFishIndex_1), num(r.AutoFishIndex_2), num(r.AutoFishIndex_Unique)] };
  }
  const skills = {};
  const classCodes = { KNIGHT: 0, HUNTER: 1, MAGICIAN: 2, SUMMONER: 3, SEGNALLE: 4, WARRIOR: 5, ALLOKEN: 6, CONCERRA: 10, RIPER: 11, WIZARD: 9, HALFBAGI: 12, DRAGONKNIGHT: 7, SHOOTER: 8, TRI: 14, NALO: 13 };
  for (const r of table('share/fishing/fishingskill.csv').rows) { const c = classCodes[String(r.Class).toUpperCase()]; if (c != null) skills[c] = num(r.SkillIndex); }
  const notify = table('share/fishing/fish_notify.csv').rows.map((r) => num(r.Index));
  notify.forEach(needItem);
  // rod and bait items (manual rods: weapon code 19; auto rods: code 30; bait: misc code 19)
  const rodItems = {}, baits = {};
  for (const [k, raw] of Object.entries(ITEMS.items)) {
    const it = { ...D, ...raw };
    if (it.type === 4 && (it.code === 19 || it.code === 30)) {
      let rod = rods[it.value1] && it.value1 !== 255 ? it.value1 : null;
      if (rod == null) {       // value1 255 ("사용불가" row) -> the manual rod row with the item's level requirement
        const byLv = Object.entries(rods).find(([ri, rv]) => Number(ri) <= 5 && rv.reqLevel === it.reqLv);
        rod = byLv ? Number(byLv[0]) : 1;
      }
      rodItems[k] = rod; needItem(k);
    } else if (it.type === 0 && it.code === 19) { baits[k] = it.value1 || 1; needItem(k); }
  }
  const sets = {};
  for (const f of Object.values(fish)) for (const [si] of f.sets) sets[si] = ITEMSET.get(si);
  out.fishing = { rods, rodItems, baits, fish, cells, skills, notify, sets };
  log(`fishing: ${Object.keys(rods).length} rods, ${Object.keys(rodItems).length} rod items, ${Object.keys(baits).length} baits, ${Object.keys(fish).length} fish, ${Object.keys(cells).length} cells, ${Object.keys(sets).length} item sets`);
}

// ------------------------------------------------------------------------------------------ craft
{
  const recipes = {};
  const t = table('share/craft/craft.csv');
  for (const r of t.rows) {
    const i = num(r.craft_index);
    const mats = [];
    for (let k = 1; k <= 10; k++) { const it = num(r[`item_${k}`]), c = num(r[`count_${k}`]); if (it && c) { mats.push([it, c]); needItem(it); } }
    needItem(r.reward_item);
    recipes[i] = { type: num(r.Type ?? r.type), name: En('craft#craft.csv', 2, r._row, r.desc), time: num(r.time), dil: num(r.dil), needPoint: num(r.need_point), rewardPoint: num(r.reward_point),
      item: num(r.reward_item), count: num(r.reward_count), prob: num(r.Probability), max: num(r.Max_count), mats };
  }
  const exp = table('share/craft/craft_exp.csv').rows.map((r) => ({ level: num(r.Lv), exp: num(r.Craft_exp) }));
  const trees = {};
  for (const k of ['weapon', 'armor', 'alchemy', 'common']) {
    const rel = `script/product/product_list_${k}.csv`;
    // header is "Tree,Name,code" in common/alchemy and "Depth,Name,Code" in weapon/armor: read by position
    const rows = csvRel(rel).slice(1).filter((r) => r[0] !== '' && r[1] !== undefined).map((r) => ({ depth: num(r[0]), name: String(r[1]).replace(/¡¯|’/g, "'"), code: num(r[2]) }));
    trees[k] = rows;
  }
  // lines_eu addresses translations by physical CSV row, which can drift when
  // a patch inserts recipes (43.8.0 recipe 699 was mislabeled as 5%, not 10%).
  // The current product trees bind their English labels to recipe IDs. Prefer
  // that identity for untranslated raw names, but never guess among aliases.
  const recipeNames = new Map();
  for (const tree of Object.values(trees)) for (const entry of tree) {
    if (!entry.code || !entry.name || hasHangul(entry.name)) continue;
    if (!recipeNames.has(entry.code)) recipeNames.set(entry.code, new Set());
    recipeNames.get(entry.code).add(entry.name);
  }
  for (const row of t.rows) {
    if (row.desc && !hasHangul(row.desc)) continue;
    const id = num(row.craft_index), names = recipeNames.get(id);
    if (names?.size === 1) recipes[id].name = [...names][0];
  }
  // catalysts (type 1 code 33: value2 = seconds taken off a craft) and Dora's Workshop (type 1 code 34: +1 craft slot)
  const catalysts = {}, workshops = [];
  for (const [k, raw] of Object.entries(ITEMS.items)) {
    const it = { ...D, ...raw };
    if (it.type === 1 && it.code === 33 && it.value2 > 0) { catalysts[k] = it.value2; needItem(k); }
    else if (it.type === 1 && it.code === 34) { workshops.push(Number(k)); needItem(k); }
  }
  // the craft mastery reset costs (stringtable_craft 2900:201: 1st free, then 10 000 / 100 000 / 1 000 000 / 10 000 000)
  const resetCost = [0, 10000, 100000, 1000000, 10000000];
  out.craft = { recipes, exp, trees, typeNames: { 1: 'weapon', 2: 'armor', 3: 'alchemy', 11: 'common' }, catalysts, workshops, resetCost, slots: { base: 1, max: 3 } };
  log(`craft: ${Object.keys(recipes).length} recipes, ${exp.length} levels, trees ${Object.entries(trees).map(([k, v]) => `${k} ${v.length}`).join(', ')}`);
}

// ------------------------------------------------------------------------------------------ deka pass
{
  const cfg = {};
  for (const r of csvRel('share/dekapass/dekapassconfig.csv')) if (r[0]) cfg[r[0]] = num(r[1], r[1]);
  const mt = table('share/dekapass/dekapassmission.csv');
  const missions = mt.rows.filter((r) => r.season !== '').map((r) => ({ season: num(r.season), type: num(r.mission_type), index: num(r.index), main: num(r.category_main),
    sub: num(r.category_sub), value: String(r.value || '0').split('/').map((x) => num(x)).filter((x) => x), count: num(r.count), point: num(r.point) }));
  // category names (the csv's side table: CATEGORY name, id)
  const categories = {};
  for (const r of mt.raw.slice(1)) { const name = String(r[11] || '').replace(/,$/, '').trim(); const id = r[12]; if (name && id !== '' && id != null) categories[num(id)] = name; }
  const rewards = table('share/dekapass/dekapassreward.csv').rows.map((r) => ({ level: num(r.wLevel), basic: [needItem(r.BasicReward), num(r.BasicRewardCount)], premium: [needItem(r.PremierReward), num(r.PremierRewardCount)] }));
  out.dekapass = { config: cfg, missions, categories, rewards };
  log(`dekapass: season ${cfg.season}, ${missions.length} missions, ${rewards.length} levels`);
}

// ------------------------------------------------------------------------------------------ events
{
  const virus = table('share/event/virus_event.csv').rows.map((r) => { const o = typed(r); needItem(o.ItemIndex); needItem(o.RewardItem_Index); return o; });
  const eventTime = table('share/event/event_time.csv').rows.map((r) => { const o = typed(r); needItem(o.ItemIndex); needItem(o.Special_ItemIndex); return o; });
  const oxConfig = {}; for (const r of table('share/event/oxevent.csv').rows) oxConfig[r.Key] = num(r.Value, r.Value);
  const ox = table('share/event/oxlist.csv').rows.map((r) => ({ index: num(r.Index), q: r.Question, a: String(r.Answer).trim().toUpperCase(), why: r.Solution }));
  const publisher = {};
  for (const f of ['china_7ongame', 'korea_gamehi', 'korea_http', 'proxy']) if (existsRel(`share/event/${f}.csv`)) publisher[f] = table(`share/event/${f}.csv`).rows.map(typed);
  const tt = table('script/contents_timetable.csv');
  const timetable = tt.rows.map((r) => ({ no: num(r['No.']), time: r.Time, end: r.EndTime, name: En('script#contents_timetable.csv', 3, r._row, r.Name), map: En('script#contents_timetable.csv', 4, r._row, r.Map),
    level: En('script#contents_timetable.csv', 5, r._row, r.Level), week: r.week === '' ? null : num(r.week), tab: num(r.TAB) }));
  const dt = csvRel('script/contents_daystable.csv');
  const daystable = dt.slice(1).filter((r) => r[0]).map((r) => ({ no: num(r[0]), time: r[1], name: "Zuto's Battlefield", map: 'Ardeca', level: 'Lv. 180 +', week: num(r[5]), nameKr: r[2] }));
  const info = csvRel('script/eventinfo/info.csv');
  const infoCfg = { title: info[1]?.[0] || '', enable: String(info[1]?.[1] || '').toLowerCase() === 'true' };
  const mapEvent = table('script/eventinfo/mapevent.csv').rows.map(typed);
  out.events = { virus, eventTime, ox: { config: oxConfig, questions: ox, maps: [22, 654] }, publisher, timetable, daystable, info: infoCfg, mapEvent };
  log(`events: ${virus.length} virus rows, ${ox.length} OX questions, ${timetable.length}+${daystable.length} timetable rows`);
}

// ------------------------------------------------------------------------------------------ premiere
{
  const teleport = table('share/premiere/teleport.csv').rows.map((r) => ({ location: num(r.LocationIndex), type: num(r.Type), name: En('premiere#teleport.csv', 2, r._row, r.LocationName), min: num(r.MinLevel), max: num(r.MaxLevel) }));
  const respon = table('share/premiere/respon.csv').rows.map((r) => ({ location: num(r.LocationIndex), name: En('premiere#respon.csv', 1, r._row, r.LocationName), min: num(r.MinLevel), max: num(r.MaxLevel), order: num(r.Order) }));
  const boxes = {};
  for (const r of csvRel('share/premiere/cash_randombox.csv').slice(1)) {
    const box = num(r[0]); if (!box) continue;
    const keys = []; for (let k = 0; k < num(r[1]); k++) { const x = num(r[2 + k]); if (x) keys.push(needItem(x)); }
    const n = num(r[8]); const items = [];
    for (let k = 0; k < n; k++) { const b = 9 + k * 4; const it = num(r[b]); if (it) items.push([needItem(it), num(r[b + 1]), num(r[b + 2]), num(r[b + 3])]); }
    boxes[box] = { keys, items }; needItem(box);
  }
  // location.csv rows the lists point at
  const loc = {};
  const lt = csvRel('share/arrange/location.csv');
  const lh = lt[0].map((h) => h.trim());
  const want = new Set([...teleport.map((t) => t.location), ...respon.map((t) => t.location)]);
  for (const r of lt.slice(1)) { const i = num(r[0], -1); if (want.has(i) && !loc[i]) { const o = {}; lh.forEach((h, k) => { if (h) o[h] = num(r[k], r[k]); }); loc[i] = o; } }
  out.premiere = { teleport, respon, boxes, locations: loc };
  log(`premiere: ${teleport.length} teleports, ${respon.length} respawns, ${Object.keys(boxes).length} boxes, ${Object.keys(loc).length} locations`);
}

// ------------------------------------------------------------------------------------------ guild
{
  const config = {};
  for (const r of csvRel('share/guild/guild.csv')) if (r[0]) config[r[0]] = num(r[1], r[1]);
  const skills = table('share/guild/guildskill.csv').rows.map((r) => ({ id: num(r.Skill_ID), group: num(r.Group), level: num(r.Level), name: En('guild#guildskill.csv', 3, r._row, r.Skill_Name),
    desc: num(r.Skill_Desc), icon: num(r.IconID), needLevel: num(r.NeeD_GuilDLv), gpoint: num(r.Pay_Gpoint), adv: num(r.Pay_ADvpoint), dil: num(r.Pay_Dil), status: num(r.Status_ID), sec: num(r.Apply_Sec) }));
  const deliver = table('share/guild/guild_deliver.csv').rows.map((r) => { needItem(r.Item_ID); return { item: num(r.Item_ID), dr: num(r.Give_DRpoint), contribution: num(r.Give_Contribution), exp: num(r.Give_EXP) }; });
  const dungeonGrade = table('share/guild/guild_dungeongrade.csv').rows.map(typed);
  const alliance = {}; for (const r of csvRel('share/guild/alliance.csv')) if (r[0]) alliance[r[0]] = num(r[1], r[1]);
  const observer = table('share/guildobserver/info.csv').rows.map(typed);
  out.guild = { config, skills, deliver, dungeonGrade, alliance, observer };
  log(`guild: ${Object.keys(config).length} config keys, ${skills.length} skills, ${deliver.length} deliver items`);
}

// ------------------------------------------------------------------------------------------ party
{
  const maps = table('share/partysearch/matchingmap.csv').rows.map((r) => ({ index: num(r.Index), name: En('partysearch#matchingmap.csv', 1, r._row, r.Name), type: num(r.Map_Type),
    limitMin: num(r.LimitMinLevel), limitMax: num(r.LimitMaxLevel), min: num(r.DefaultMinLevel), max: num(r.DefaultMaxLevel) }));
  // share/pc/groupexpratio.csv is keyed by MapIndex: GroupMember (members counted, 3 / 7 / 18) and GroupExpRatio1..18 (the
  // party's total % of the monster EXP). Every row is exported (groupExpByMap); row 0 stays groupExpDefault for the readers
  // that predate the per-map table. LeaderExpRatio / EventExpRatio are 0 in every row and are not exported.
  // (share/item/groupexpratio.csv is a second, different table - map 0 there is 6 members, 100..250 - exported by
  // build-items.mjs; share/stringlist.csv L705 registers only PC\GroupExpRatio.csv, which is the one used here.)
  const geRows = table('share/pc/groupexpratio.csv').rows.map(typed);
  const ge = geRows[0] || null;
  const groupExpByMap = {};
  for (const r of geRows) {
    const row = { GroupMember: num(r.GroupMember) };
    for (let i = 1; i <= 18; i++) row[`GroupExpRatio${i}`] = num(r[`GroupExpRatio${i}`]);
    groupExpByMap[num(r.MapIndex)] = row;
  }
  out.party = { matchingMaps: maps, groupExpDefault: ge, groupExpByMap };
  log(`party: ${maps.length} matching maps, ${Object.keys(groupExpByMap).length} group EXP rows`);
}

// ------------------------------------------------------------------------------------------ grade / titles / pk
{
  const g = csvRel('share/pc/awakening/grade.csv');
  const grades = g.slice(1).filter((r) => r[0] !== '').map((r) => ({ division: num(r[0]), grade: num(r[1]), levelLimit: num(r[2]), name: r[3], royalHi: num(r[4]), royalLo: num(r[5]), gradeExp: num(r[6]),
    rewardSkill: num(r[7]), rewardShield: num(r[8]), rewardStat: num(r[9]), rewardSpSkill: num(r[10]), reward5: num(r[11]), options: r.slice(12, 22).map((x) => num(x)).filter((x) => x) }));
  const options = table('share/pc/awakening/gradeoption.csv').rows.map((r) => ({ index: num(r.OptionIndex), type: num(r.OptionType), value: num(r.Value) }));
  const week = csvRel('share/pc/awakening/gradeweek.csv').slice(1).filter((r) => r[0]).map((r) => ({ division: num(r[0]), name: r[1], shield: num(r[2]) }));
  const caps = {};
  for (const f of fs.readdirSync(path.join(DATA, 'share/pc/gradecap'))) if (/\.csv$/i.test(f)) caps[f.replace(/^gradeexp\s*/i, '').replace(/\.csv$/i, '').trim().toLowerCase()] = table(`share/pc/gradecap/${f}`).rows.map((r) => ({ start: num(r.Grade_Start), end: num(r.Grade_End), rate: num(r.GradeExpRate) }));
  const titles = table('share/pc/title/title_base.csv').rows.map(typed);
  const chaotic = table('share/pc/chaotic.csv').rows.map((r) => ({ index: num(r.Index), start: num(r['ChaoticLevel Start']), end: num(r['ChaoticLevel End']), dropRate: num(r['Item Drop Rate']), respawn: num(r.wRespawnIndex) }));
  const pkRaw = csvRel('share/pc/pkcount.csv');
  const pkcount = pkRaw.slice(1).filter((r) => r[0]).map((r) => ({ start: num(r[1]), end: num(r[2]), chaotic: num(r[3]), level: num(r[4]) }));
  const pkLevelCap = table('share/pc/pklevelcap.csv').rows.map((r) => ({ start: num(r.LevelStart), end: num(r.LevelEnd), rate: num(r.ChaoticRate) }));
  const selfRevive = table('share/pc/selfrevive.csv').rows.map((r) => num(r.ItemIndex)); selfRevive.forEach(needItem);
  out.grade = { grades, options, week, caps, titles };
  out.pk = { chaotic, pkcount, pkLevelCap, selfRevive };
  log(`grade: ${grades.length} grades, caps ${Object.keys(caps).join('/')}, ${titles.length} titles; pk tables ${chaotic.length}/${pkcount.length}/${pkLevelCap.length}`);
}

// ------------------------------------------------------------------------------------------ monster grade exp / chaotic
{
  const t = table('share/creature/monster.csv');
  const mg = {};
  for (const r of t.rows) {
    const i = num(r.Index, -1); if (i < 0 || mg[i]) continue;
    const v = [num(r.Wgrade), num(r.DwGradeExp), num(r.ChaoticLevel), num(r.P_point_Min), num(r.P_point_Max), num(r.P_point_Rate)];
    if (v.some((x) => x)) mg[i] = v;
  }
  out.monsterGrade = { fields: ['wgrade', 'gradeExp', 'chaoticLevel', 'pPointMin', 'pPointMax', 'pPointRate'], monsters: mg };
  log(`monsterGrade: ${Object.keys(mg).length} monsters with grade/chaotic/point values`);
}

// ------------------------------------------------------------------------------------------ per-class motions
{
  const CL = JSON.parse(fs.readFileSync(path.join(OUT, 'classes.json'), 'utf8'));
  const classMotions = {};
  for (const c of CL.classes) {
    const rel = c.actionFile;
    if (!rel || !existsRel(rel)) { warn.push(`class ${c.index}: action file ${rel} missing`); continue; }
    const b = readRel(rel);
    const t = parseActionDat(b.buffer.slice(b.byteOffset, b.byteOffset + b.length));
    const rec = (x) => ({ anim: x.animKey, t: Math.round(x.timeLength * 1000) / 1000, effect: x.effect || 0, fade: x.startInter || 0 });
    const cm = { fishing: {}, motions: {}, emotion: {}, market: {}, surrender: null };
    for (const x of t.actions) {
      if (!x.animKey || !(x.timeLength > 0)) continue;
      if (x.style === 23 && /^(STAND|MOVE|FISHFIGHTING|OPENFISHING|CLOSEFISHING)$/.test(x.action)) cm.fishing[`${x.action}:${x.index}`] = rec(x);
      else if (x.action === 'MOTION' && x.style === 0) cm.motions[x.index] = rec(x);
      else if (/^EMOTION(START|KEEP|END)$/.test(x.action) && x.style === 0) cm.emotion[x.action] = rec(x);
      else if (/^(OPENMARKET|CLOSEMARKET)$/.test(x.action) && x.style === 0) cm.market[`${x.action}:${x.index}`] = rec(x);
      else if (x.action === 'SURRENDER' && x.style === 0) cm.surrender = rec(x);
    }
    classMotions[c.index] = cm;
  }
  out.classMotions = classMotions;
  log(`classMotions: ${Object.keys(classMotions).length} classes (fishing ${Object.values(classMotions).map((m) => Object.keys(m.fishing).length).join('/')})`);
}

// ------------------------------------------------------------------------------------------ cosmotion / interactive
{
  const cm = table('script/cosmotion/cosmotion.csv').rows.map((r) => ({ motion: num(r.MotionIndex), cls: num(r.Class), sub: num(r.SubType), item: needItem(r.ItemID) }));
  out.cosmotion = cm;
  out.interactive = table('script/interactiveaction/triggerinteractiveaction.csv').rows.map((r) => ({ trigger: num(r.TriggerIndex), actions: [1, 2, 3, 4, 5].map((k) => num(r[`ActionIndex_${k}`])).filter((x) => x), interaction: num(r.InteractionIndex), dir: num(r.Direction) }));
  log(`cosmotion: ${cm.length} rows; interactive: ${out.interactive.length} triggers`);
}

// ------------------------------------------------------------------------------------------ weather
{
  const sceneTxt = textRel('property/effect/effectscene.com.txt').split(/\r?\n/);
  let on = false; const lines = [];
  for (const l of sceneTxt) { if (/^<cate>\s+10\b/.test(l)) on = true; if (on) lines.push(l); if (on && /^<\/cate>/.test(l)) break; }
  const res = {}; const scenes = {};
  let cur = null, ctl = null;
  for (const raw of lines) {
    const l = raw.trim(); if (!l || l.startsWith('#')) continue;
    let m;
    if ((m = /^res\s+(\d+)\s+(\S+)/.exec(l))) res[+m[1]] = m[2];
    else if (l === '<scene>') cur = { controls: [] };
    else if (l === '</scene>') { scenes[cur.id] = cur; cur = null; }
    else if (cur && (m = /^sceneid\s+(\d+)/.exec(l))) cur.id = +m[1];
    else if (cur && (m = /^name\s+(\S+)/.exec(l)) && !ctl) cur.name = m[1];
    else if (l === '<control>') ctl = {};
    else if (l === '</control>') { if (ctl.active) cur.controls.push(ctl); ctl = null; }
    else if (ctl) {
      const k = l.split(/\s+/)[0], v = l.slice(k.length).trim();
      if (k === 'unitid') ctl.unit = +v;
      else if (k === 'active') ctl.active = v === 'true';
      else if (k === 'startposition') ctl.pos = v.split(/\s+/).map(Number);
      else if (k === 'lifetime') ctl.life = v.split(/\s+/).map(Number);
      else if (k === 'randomstart') ctl.random = v === 'true';
      else if (k === 'animtime') ctl.animtime = Number(v);
      else if (/^(scale|alpha|color)$/.test(k)) ctl[k] = [...v.matchAll(/\(([^)]*)\)/g)].map((g) => g[1].split(/[\s,]+/).filter(Boolean).map(Number));
    }
  }
  for (const s of Object.values(scenes)) for (const c of s.controls) c.res = res[c.unit];
  // units: weather particles from effectdata.com/.map, sounds from effectdata.snd
  const units = {};
  const want = new Set(Object.values(res).map((x) => x.toLowerCase()));
  for (const f of ['property/effect/effectdata.com.txt', 'property/effect/effectdata.map.txt', 'property/effect/effectdata.snd.txt']) {
    const blocks = textRel(f).split('<effectdata>');
    for (const b of blocks) {
      const nm = /\bname\s+(\S+)/.exec(b)?.[1]; if (!nm || !want.has(nm.toLowerCase()) || units[nm.toLowerCase()]) continue;
      const u = {};
      for (const line of b.split(/\r?\n/)) {
        const t = line.trim(); if (!t || t.startsWith('<') || t.startsWith('#')) continue;
        const k = t.split(/\s+/)[0]; const v = t.slice(k.length).trim();
        u[k] = v;
      }
      const o = { type: u.unittype, name: nm };
      if (u.unittype === 'sound') { const p = u.sound.split(/\s+/); o.sound = { path: p[0].replace(/\\/g, '/').toLowerCase(), flag: num(p[1]), vol: num(p[2]), range: num(p[3]), lenMs: num(p[4]) }; }
      else {
        const nums = (s) => String(s || '').split(/\s+/).filter(Boolean).map(Number);
        const tex = (s) => s ? ('texture/' + s.replace(/\\/g, '/').toLowerCase()).replace(/\/+/g, '/') : '';
        Object.assign(o, { billboard: u.billboardtype, size: num(u.size, 1), texture: tex(u.texturefile), tpack: u.texturepack ? ('texturepack/' + u.texturepack.replace(/\\/g, '/').toLowerCase()) : '',
          blend: u.blendtype, state: u.activestate, life: nums(u.lifetime), emit: num(u.emitrate), max: num(u.maxelementcount), rotate: num(u.addrotate), velocity: nums(u.velocity),
          accel: num(u.acceleration), dir: nums(u.spawndirection), gravity: nums(u.gravity), range: nums(u.startrange), triangle: u.trianglerender === 'true',
          flat: u.flattexturefile ? { max: num(u.flatmaxelementcount), texture: tex(u.flattexturefile), scale: nums(u.flatscale), color: nums(u.flatcolor), rate: num(u.flatrenderrate, 1) } : null });
        if (o.texture && !existsRel(o.texture)) { const alt = o.texture.replace(/\.dds$/, '.tga'); if (existsRel(alt)) o.texture = alt; else warn.push(`weather texture ${o.texture} missing`); }
      }
      units[nm.toLowerCase()] = o;
    }
  }
  out.weather = { effect: 100, cate: 10, res, scenes, units, names: { 1: 'rain', 2: 'snow', 3: 'sandstorm', 4: 'shower', 5: 'blossom', 6: 'festival_pollen' } };
  log(`weather: ${Object.keys(scenes).length} scenes, ${Object.keys(units).length} units`);
}

// ------------------------------------------------------------------------------------------ rebirth (dynamic options) -> separate file
{
  const change = table('share/rebirth/changeoption.csv').rows.map((r) => ({ from: r['Option Type'], type: num(r.Type), code: num(r.Code), job: num(r.Job), to: r['Change Option'] }));
  const grp = (rel) => {
    const raw = csvRel(rel);
    const englishHeader = ['OptionLevel', 'OptionIndex', 'Type', 'Description', 'MinData', 'MaxData'];
    const headerCount = rel === 'share/rebirth/itemoption_weapon.csv' &&
      raw[1]?.length === englishHeader.length && raw[1].every((v, i) => v === englishHeader[i]) ? 2 : 1;
    const byLevel = {};
    raw.slice(headerCount).forEach((r, i) => {
      if (!r.some((v) => v !== '')) return;
      const lv = Number(r[0]), index = Number(r[1]);
      if (r.length !== 6 || !Number.isSafeInteger(lv) || lv <= 0 || !Number.isSafeInteger(index) || index <= 0 ||
        !r[2] || [r[4], r[5]].some((v) => v === '' || !Number.isFinite(Number(v))))
        throw new Error(`Invalid rebirth option record ${i + headerCount + 1} in ${rel}`);
      (byLevel[lv] ||= []).push([index, r[2], r[3], Number(r[4]), Number(r[5])]);
    });
    return byLevel;
  };
  const reb = { version: 1, fields: ['index', 'type', 'desc', 'min', 'max'], change, armor: grp('share/rebirth/itemoption_armor.csv'), weapon: grp('share/rebirth/itemoption_weapon.csv') };
  fs.writeFileSync(path.join(OUT, 'life_rebirth.json'), JSON.stringify(reb));
  log(`rebirth: ${change.length} change rows, armor levels ${Object.keys(reb.armor).length}, weapon levels ${Object.keys(reb.weapon).length}`);
}

// ------------------------------------------------------------------------------------------ items subset
{
  const items = {};
  for (const i of [...wantItems].sort((a, b) => a - b)) { const o = itemOut(i); if (o) items[i] = o; else warn.push(`item ${i} not in items.json`); }
  out.items = items;
  log(`items: ${Object.keys(items).length} referenced items`);
}

fs.writeFileSync(path.join(OUT, 'life.json'), PRETTY ? JSON.stringify(out, null, 1) : JSON.stringify(out));
const size = fs.statSync(path.join(OUT, 'life.json')).size;
log(`wrote gamedata/life.json (${(size / 1024).toFixed(0)} KB)`);
if (warn.length) { log(`${warn.length} warnings:`); for (const w of warn.slice(0, 40)) log('  ' + w); }
