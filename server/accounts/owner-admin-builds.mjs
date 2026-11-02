/**
 * Admin/GM/Dev owner showcase builds: real PvP + Mobs loadouts, dual-hand / tab-swap,
 * and buff / attack / PvP quickslot bars. Item and skill IDs come only from Engine /
 * REA Global catalogs (via planGearSet + class skill packs). No fabricated indices.
 */
import {planGearSet, gearSlotChoices, maximumGearOptions} from '../../src/systems/gm/gear-set.js';
import {S, PRESETS, Equipment} from '../../src/systems/items/equip.js';
import {createItem, Container} from '../../src/systems/items/model.js';

/** Class role tags used for bar priority and reporting. Not balance claims. */
export const ADMIN_CLASS_ROLES = Object.freeze({
  0: Object.freeze(['attacker', 'pk', 'laner']),          // Azure Knight
  1: Object.freeze(['attacker', 'mober', 'laner']),        // Segita Hunter
  2: Object.freeze(['attacker', 'mober']),                 // Incar Magician
  3: Object.freeze(['attacker', 'mober']),                 // Vicious Summoner
  4: Object.freeze(['healer', 'support']),                 // Segnale
  5: Object.freeze(['attacker', 'mober', 'pk']),           // Bagi Warrior
  6: Object.freeze(['attacker', 'laner']),                 // Aloken
  7: Object.freeze(['attacker', 'pk']),                    // Dragon Knight
  8: Object.freeze(['attacker', 'mober', 'laner']),        // Segita Shooter
  9: Object.freeze(['attacker', 'mober']),                 // Black Wizard
  10: Object.freeze(['attacker', 'mober']),                // Conserra Summoner
  11: Object.freeze(['healer', 'support']),                // Segeuriper
  12: Object.freeze(['attacker', 'mober', 'pk']),          // Half Bagi
  13: Object.freeze(['attacker']),                         // Alokes
  14: Object.freeze(['attacker', 'support', 'mober']),     // Trie Muse
});

export const ADMIN_BUILD_POLICY = 'Preset0=Mobs/overall BiS from owner gear policy; Preset1=PvP gear via native planGearSet(pvp); weapon tab II = opposite-mode weapons when distinct. Bars: row0 buff, row1 attack/mobs, row2 PvP. Skills/items only from class packs + item DB.';

const BAR_SLOTS = 12;
const tgtOf = s => Array.isArray(s.target) ? s.target : [];
const L0 = s => s.levels?.[0] || {};
const hasHeal = s => !!(L0(s).heal || s.type === 'heal');
const hasStatus = s => !!(L0(s).statuses?.length) || ['buff', 'status', 'area_status'].includes(s.type);
const hasDmg = s => !!(L0(s).hits?.length || L0(s).addDamage) || ['magic', 'melee', 'range'].includes(s.type);
const isAlly = s => tgtOf(s).includes(2);
const isEnemy = s => tgtOf(s).includes(4);
const isSelf = s => tgtOf(s).includes(16) && !isAlly(s);
const isAoe = s => tgtOf(s).includes(1);
/** Party-range buff/status (ally target). Used for healer buff bars. */
export function isPartyRangeBuff(s) {
  if (!s || s.hidden || s.kind !== 'active') return false;
  if (!isAlly(s) || !hasStatus(s)) return false;
  if (['dispel', 'resurrect'].includes(s.type)) return false;
  // Prefer true buff/status/area_status; allow heals that also apply party statuses.
  return ['buff', 'status', 'area_status'].includes(s.type) || (hasStatus(s) && !hasDmg(s)) || (hasHeal(s) && hasStatus(s) && isAlly(s));
}

function learnedActives(data, profile) {
  const pack = data.skillPacks?.[profile.classIndex];
  if (!pack) return [];
  const learned = profile.skills || {};
  return Object.values(pack.skills || {}).filter(s => !s.hidden && s.kind === 'active' && Number(learned[s.index]) > 0);
}

function uniqPush(list, skill, limit = BAR_SLOTS) {
  if (!skill || list.length >= limit) return;
  if (list.some(e => e && e.index === skill.index)) return;
  list.push({type: 'skill', index: skill.index});
}

function scoreBuff(s, roles) {
  let n = 0;
  if (isPartyRangeBuff(s)) n += 1000;
  if (isAlly(s) && hasStatus(s)) n += 400;
  if (hasHeal(s) && roles.includes('healer')) n += 300;
  if (isSelf(s) && hasStatus(s)) n += 100;
  if (s.type === 'dispel' && isAlly(s)) n += 80;
  if (s.type === 'resurrect') n += 60;
  n += Math.min(50, Number(s.range) || 0);
  return n;
}

function scoreAttack(s) {
  let n = 0;
  if (isEnemy(s) && hasDmg(s)) n += 500;
  if (isAoe(s) && isEnemy(s)) n += 300; // mober AoE
  if (hasDmg(s) && !hasHeal(s)) n += 100;
  if (isEnemy(s) && hasStatus(s) && hasDmg(s)) n += 40;
  n += Math.min(30, Number(s.range) || 0);
  return n;
}

function scorePvp(s) {
  let n = 0;
  if (isEnemy(s) && hasStatus(s) && !hasHeal(s)) n += 600; // CC / debuff
  if (isEnemy(s) && hasDmg(s) && !isAoe(s)) n += 400; // single-target burst
  if (isSelf(s) && hasStatus(s)) n += 150;
  if (isEnemy(s) && hasDmg(s) && isAoe(s)) n += 80;
  if (s.type === 'dispel' && isEnemy(s)) n += 200;
  return n;
}

/** Fill quickslot rows: 0=buff, 1=attack/mobs, 2=PvP. Returns bar report. */
export function fillAdminQuickslotBars(data, profile) {
  const roles = [...(ADMIN_CLASS_ROLES[profile.classIndex] || ['attacker'])];
  const skills = learnedActives(data, profile);
  const buffs = skills.filter(s => scoreBuff(s, roles) > 0).sort((a, b) => scoreBuff(b, roles) - scoreBuff(a, roles) || a.index - b.index);
  const attacks = skills.filter(s => scoreAttack(s) > 0).sort((a, b) => scoreAttack(b) - scoreAttack(a) || a.index - b.index);
  const pvps = skills.filter(s => scorePvp(s) > 0).sort((a, b) => scorePvp(b) - scorePvp(a) || a.index - b.index);

  // Healers: force real party-range buffs onto the buff bar first (no invented skills).
  const partyBuffs = skills.filter(isPartyRangeBuff).sort((a, b) => scoreBuff(b, roles) - scoreBuff(a, roles) || a.index - b.index);

  const row = (picked) => {
    const out = [];
    for (const s of picked) uniqPush(out, s);
    while (out.length < BAR_SLOTS) out.push(null);
    return out.slice(0, BAR_SLOTS);
  };

  const buffOrder = roles.includes('healer') || roles.includes('support')
    ? [...partyBuffs, ...buffs.filter(s => !partyBuffs.some(p => p.index === s.index))]
    : [...buffs.filter(s => isPartyRangeBuff(s) || (isSelf(s) && hasStatus(s)) || (isAlly(s) && hasStatus(s))), ...buffs];

  const sets = [row(buffOrder), row(attacks), row(pvps)];
  profile.quickslot = {
    sets,
    rows: 3,
    rowSet: [0, 1, 2],
    fixed: [false, false, false],
    locked: true,
    belt: Array(10).fill(null),
  };
  profile.hotbar = sets[0];
  profile.starterSkillSeeded = true;
  delete profile.starterSkillPending;

  const ids = row => row.filter(Boolean).map(e => e.index);
  return {
    roles,
    buffBar: ids(sets[0]),
    attackBar: ids(sets[1]),
    pvpBar: ids(sets[2]),
    partyRangeBuffs: partyBuffs.map(s => ({index: s.index, name: s.name, range: s.range, type: s.type, target: tgtOf(s)})),
  };
}

function grantPlanItems(profile, db, plan, {presetIndex, asWeaponTab2 = false} = {}) {
  const placed = [];
  profile.equip ||= {active: 0, presets: Array.from({length: PRESETS}, () => ({})), items: {}};
  while (profile.equip.presets.length < PRESETS) profile.equip.presets.push({});
  const preset = profile.equip.presets[presetIndex] ||= {};

  for (const row of plan.items || []) {
    let slot = row.slot;
    if (asWeaponTab2) {
      if (slot === S.weapon) slot = S.weapon2;
      else if (slot === S.offhand) slot = S.offhand2;
      else continue; // tab-II only carries the weapon pair
    }
    // Preset-1 full loadout: only equip armor/weapons/rings from the plan; skip if slot already points at same itemIndex.
    const existingUid = preset[slot];
    const existing = existingUid && profile.equip.items[existingUid];
    if (existing && Number(existing.itemIndex) === Number(row.item) && !asWeaponTab2 && presetIndex === 0) {
      placed.push({slot, itemIndex: row.item, name: row.name, reused: true});
      continue;
    }
    let uid = `adminbuild-p${presetIndex}-${slot}-${row.item}`;
    while (profile.equip.items[uid] || (profile.inventory || []).some(i => i.uid === uid)) uid += 'n';
    const item = createItem(db, row.item, {
      grade: row.grade || 'divine',
      rnd: row.options,
      sockets: row.sockets,
      bound: row.bound !== false,
      roll: false,
      now: Date.now(),
    });
    item.uid = uid;
    if (row.options?.length) item.rnd = row.options;
    if (row.sockets?.length) item.sockets = row.sockets;
    profile.equip.items[uid] = item;
    preset[slot] = uid;
    placed.push({slot, itemIndex: row.item, name: row.name, uid, reused: false});
  }
  return placed;
}

function clonePresetSlots(profile, fromIndex, toIndex, {onlySlots = null} = {}) {
  const from = profile.equip.presets[fromIndex] || {};
  const to = profile.equip.presets[toIndex] ||= {};
  for (const [slot, uid] of Object.entries(from)) {
    const s = Number(slot);
    if (onlySlots && !onlySlots.includes(s)) continue;
    // Share the same item instance across presets (Global Ctrl+click clone semantics).
    to[s] = uid;
  }
}

/**
 * Wire PvP vs Mobs loadouts onto equip presets + weapon tab II.
 * Preset 0 keeps the owner BiS already applied by adminProfile (mobs / overall damage).
 * Preset 1 gets a full PvP planGearSet loadout (real item IDs only).
 * Weapon tab II on preset 0 gets the other mode's weapons when they differ.
 */
export function applyAdminDualLoadouts(data, profile) {
  const db = data.itemDB;
  if (!db) return {available: false, reason: 'Item catalog unavailable.'};
  db.T ??= data.itemUseData?.tables;
  const ci = profile.classIndex;
  const level = Math.min(Number(profile.level) || data.maxLevel, data.maxLevel);
  const base = {classIndex: ci, level, upgrade: 40, grade: 'divine', sockets: 4, bound: true};

  let mobPlan, pvpPlan;
  try {
    mobPlan = planGearSet(db, {...base, mode: 'monster'});
    pvpPlan = planGearSet(db, {...base, mode: 'pvp'});
  } catch (e) {
    return {available: false, reason: e.message || String(e)};
  }

  profile.equip.active = 0;
  // Share non-weapon BiS armor/rings into preset 1, then overlay PvP plan items.
  clonePresetSlots(profile, 0, 1);

  const pvpPlaced = grantPlanItems(profile, db, pvpPlan, {presetIndex: 1});

  const mobW = mobPlan.items.find(i => i.slot === S.weapon);
  const pvpW = pvpPlan.items.find(i => i.slot === S.weapon);
  const mobOh = mobPlan.items.find(i => i.slot === S.offhand);
  const pvpOh = pvpPlan.items.find(i => i.slot === S.offhand);
  const weaponsDiffer = mobW && pvpW && Number(mobW.item) !== Number(pvpW.item);

  // Tab-II on the mobs preset: opposite-mode weapons when distinct; else leave existing weapon2 from adminProfile.
  let tab2 = [];
  if (weaponsDiffer) {
    const tabPlan = {
      items: [pvpW, pvpOh].filter(Boolean).map(i => ({...i})),
    };
    tab2 = grantPlanItems(profile, db, tabPlan, {presetIndex: 0, asWeaponTab2: true});
  }

  // Ensure mobs preset weapons prefer monster-mode plan when it differs from what's equipped.
  const preset0 = profile.equip.presets[0] || {};
  const curWuid = preset0[S.weapon];
  const curW = curWuid && profile.equip.items[curWuid];
  if (mobW && (!curW || Number(curW.itemIndex) !== Number(mobW.item))) {
    grantPlanItems(profile, db, {items: [mobW, mobOh].filter(Boolean)}, {presetIndex: 0});
  }

  return {
    available: true,
    mobs: {
      preset: 0,
      mode: 'monster',
      weapons: {weapon: mobW?.item, offhand: mobOh?.item, weaponName: mobW?.name, offhandName: mobOh?.name},
      planItems: (mobPlan.items || []).map(i => ({slot: i.slot, item: i.item, name: i.name})),
    },
    pvp: {
      preset: 1,
      mode: 'pvp',
      weapons: {weapon: pvpW?.item, offhand: pvpOh?.item, weaponName: pvpW?.name, offhandName: pvpOh?.name},
      placed: pvpPlaced.map(p => ({slot: p.slot, itemIndex: p.itemIndex, name: p.name})),
      planItems: (pvpPlan.items || []).map(i => ({slot: i.slot, item: i.item, name: i.name})),
    },
    tabSwap: {
      kind: weaponsDiffer ? 'weapon-tab-II-holds-pvp-weapons' : 'same-weapon-serves-both-modes',
      weaponsDiffer,
      tab2: tab2.map(p => ({slot: p.slot, itemIndex: p.itemIndex, name: p.name})),
    },
    missing: {mobs: mobPlan.missing || [], pvp: pvpPlan.missing || []},
  };
}

// STAFF-STANCE (2026-10-30): legal staff weapon tabs.
// * Every weapon tab (presets 0..4, tab I = slots 4/5, tab II = 104/105) must pass Equipment.check: no shield next to a
//   two-hander or a dual pair, no arrows on a crossbow. An illegal off-hand is swapped for the best legal Global off-hand of
//   that weapon (gearSlotChoices) or, when there is none, taken off the tab and put in the bag (never deleted).
// * A class whose Global skill pack has a 'Dual' tab AND a shield skill in its 'Protection' tab (Azure Knight: Dual mastery /
//   Dual advance + Shield mastery / Shield shove) gets the Global tab swap: tab I = dual one-handers (preset 0 Mobs: Axe+Axe,
//   preset 1 PvP: Mace+Mace), tab II = Mace + Shield. Only Global item ids (planGearSet / gearSlotChoices), nothing invented.
export const STAFF_STANCE_VERSION = 1;
const STANCE_TAB1 = {0: 8, 1: 6};   // preset -> dual one-hander code (8 Axe, 6 Mace); owner: "dual mace or dual axe combo"
const STANCE_TAB2_MAIN = 6;         // Mace + Shield on weapon tab II
const SHIELD_CODE = 14;
const PROVISIONED = uid => /^admin(max|build)-/.test(String(uid || ''));

export function classHasDualShieldStance(data, ci) {
  const sk = Object.values(data.skillPacks?.[ci]?.skills || {});
  return sk.some(s => s.tree?.tabName === 'Dual') && sk.some(s => s.tree?.tabName === 'Protection' && /shield/i.test(s.name || ''));
}

function referenced(profile, uid) { return (profile.equip.presets || []).some(p => p && Object.values(p).includes(uid)); }

/** Items no preset holds any more go to the bag; when the bag is full they stay in equip.items (kept, never deleted). */
function stashLoose(profile, db, uids, report) {
  const bag = new Container(profile.inventory ||= [], db, {pages: 7, cols: 10, rows: 5, unlocked: () => profile.bagsUnlocked || 2});
  for (const uid of new Set(uids)) {
    if (!uid || referenced(profile, uid)) continue;
    const item = profile.equip.items[uid];
    if (!item) continue;
    if (bag.canAdd(item) && bag.add(item).ok) { delete profile.equip.items[uid]; report.push({uid, itemIndex: item.itemIndex, to: 'bag'}); }
    else report.push({uid, itemIndex: item.itemIndex, to: 'kept-in-equip-store'});
  }
}

function styleOfCode(db, code) {
  for (const key of Object.keys(db.items)) { const d = db.def(Number(key)); if (d?.slot === 'weapon' && Number(d.code) === code) { const st = db.weaponRule(d)?.style; if (st != null) return Number(st); } }
  return null;
}

function stancePair(db, base, mode, mainCode, offhand) {
  const style = styleOfCode(db, mainCode);
  if (style == null) return null;
  const plan = planGearSet(db, {...base, mode, weaponStyle: style});
  const w = plan.items.find(i => i.slot === S.weapon);
  if (!w || Number(db.def(w.item)?.code) !== mainCode) return null;
  let off;
  if (offhand === 'dual') off = w.item;
  else {
    const pick = gearSlotChoices(db, {classIndex: base.classIndex, level: base.level, mode, upgrade: base.upgrade, slot: S.offhand, weaponItem: w.item})
      .find(c => Number(db.def(c.index)?.code) === SHIELD_CODE);
    if (!pick) return null;
    off = pick.index;
  }
  const pair = planGearSet(db, {...base, mode, weaponStyle: style, overrides: {[S.weapon]: w.item, [S.offhand]: off}});
  const pw = pair.items.find(i => i.slot === S.weapon), po = pair.items.find(i => i.slot === S.offhand);
  return pw && po ? [pw, po] : null;
}

/** Dual one-handers on tab I, Mace + Shield on tab II (classes with the Global Dual + Protection shield trees only). */
export function applyClassStance(data, profile, {force = false} = {}) {
  const db = data.itemDB, ci = profile.classIndex;
  if (!db || !classHasDualShieldStance(data, ci)) return null;
  const level = Math.min(Number(profile.level) || data.maxLevel, data.maxLevel);
  const base = {classIndex: ci, level, upgrade: 40, grade: 'divine', sockets: 4, bound: true};
  const out = [], loose = [], moved = [];
  for (const [presetIndex, code] of Object.entries(STANCE_TAB1).map(([p, c]) => [Number(p), c])) {
    const preset = profile.equip.presets[presetIndex] ||= {};
    const slots = [S.weapon, S.offhand, S.weapon2, S.offhand2];
    // Only provisioned showcase weapons are replaced; a weapon the player put there himself is left alone.
    if (!force && slots.some(s => preset[s] && !PROVISIONED(preset[s]))) { out.push({preset: presetIndex, skipped: 'player-chosen weapons'}); continue; }
    const mode = presetIndex === 1 ? 'pvp' : 'monster';
    const tab1 = stancePair(db, base, mode, code, 'dual'), tab2 = stancePair(db, base, mode, STANCE_TAB2_MAIN, 'shield');
    if (!tab1 || !tab2) { out.push({preset: presetIndex, skipped: 'Global items unavailable'}); continue; }
    for (const s of slots) { if (preset[s]) loose.push(preset[s]); delete preset[s]; }
    const a = grantPlanItems(profile, db, {items: tab1}, {presetIndex}), b = grantPlanItems(profile, db, {items: tab2}, {presetIndex, asWeaponTab2: true});
    out.push({preset: presetIndex, mode, tab1: a.map(p => ({slot: p.slot, itemIndex: p.itemIndex, name: p.name})), tab2: b.map(p => ({slot: p.slot, itemIndex: p.itemIndex, name: p.name}))});
  }
  stashLoose(profile, db, loose, moved);
  return {kind: 'dual-tab1-mace-shield-tab2', skillTabs: ['Dual', 'Protection'], presets: out, moved};
}

/** Every off-hand of every preset / tab must pass Equipment.check; swap for a legal Global off-hand or bag it. */
export function legalizeStaffOffhands(data, profile) {
  const db = data.itemDB, ci = profile.classIndex, changes = [], loose = [];
  if (!db || !profile.equip?.presets) return changes;
  const level = Math.min(Number(profile.level) || data.maxLevel, data.maxLevel);
  const eq = new Equipment({db, game: {save: profile}});
  for (let p = 0; p < profile.equip.presets.length; p++) {
    const preset = profile.equip.presets[p];
    if (!preset) continue;
    for (const [main, off] of [[S.weapon, S.offhand], [S.weapon2, S.offhand2]]) {
      const item = preset[off] && profile.equip.items[preset[off]];
      if (!item || eq.check(item, off, null, p).ok) continue;
      const oldUid = preset[off], mainItem = preset[main] && profile.equip.items[preset[main]];
      const mode = p === 1 ? 'pvp' : 'monster';
      const pick = mainItem ? gearSlotChoices(db, {classIndex: ci, level, mode, upgrade: 40, slot: S.offhand, weaponItem: mainItem.itemIndex})[0] : null;
      delete preset[off];
      loose.push(oldUid);
      let placed = null;
      if (pick) {
        const def = db.def(pick.index);
        placed = grantPlanItems(profile, db, {items: [{slot: S.offhand, item: pick.index, name: pick.name, options: maximumGearOptions(db, def, mode, 'divine'), sockets: []}]}, {presetIndex: p, asWeaponTab2: off === S.offhand2})[0] || null;
        if (placed && !eq.check(profile.equip.items[placed.uid], off, null, p).ok) { delete preset[off]; delete profile.equip.items[placed.uid]; placed = null; }
      }
      changes.push({preset: p, slot: off, removed: item.itemIndex, replacedWith: placed ? placed.itemIndex : null, name: placed?.name || null});
    }
  }
  const moved = [];
  stashLoose(profile, db, loose, moved);
  if (moved.length) changes.push({moved});
  return changes;
}

/** Idempotent fix of an already provisioned staff character (version-gated by ownerProvision.stanceVersion). */
export function normalizeStaffShowcase(data, profile) {
  if (!profile?.ownerProvision?.adminBuild || !profile.equip?.presets) return null;
  if ((Number(profile.ownerProvision.stanceVersion) || 0) >= STAFF_STANCE_VERSION) return null;
  const stance = applyClassStance(data, profile);
  const legal = legalizeStaffOffhands(data, profile);
  profile.ownerProvision = {...profile.ownerProvision, stanceVersion: STAFF_STANCE_VERSION, stance, legalized: legal};
  return {stance, legal};
}

/** Apply bars + dual loadouts; stamp ownerProvision.adminBuild. */
export function applyAdminCharacterBuilds(data, profile, gearSummary = {}) {
  const bars = fillAdminQuickslotBars(data, profile);
  const loadouts = applyAdminDualLoadouts(data, profile);
  // STAFF-STANCE: Global Dual/shield tab swap + legal off-hands on every tab.
  const stance = applyClassStance(data, profile, {force: true});
  const legalized = legalizeStaffOffhands(data, profile);
  const roles = bars.roles;
  profile.ownerProvision = {
    ...(profile.ownerProvision || {}),
    version: 3,
    adminBuild: {
      policy: ADMIN_BUILD_POLICY,
      roles,
      bars: {
        buff: bars.buffBar,
        attack: bars.attackBar,
        pvp: bars.pvpBar,
        partyRangeBuffs: bars.partyRangeBuffs,
      },
      loadouts: {
        mobsPreset: 0,
        pvpPreset: 1,
        tabSwap: loadouts.tabSwap || null,
        mobsWeapons: loadouts.mobs?.weapons || null,
        pvpWeapons: loadouts.pvp?.weapons || null,
        available: !!loadouts.available,
        reason: loadouts.reason || null,
        missing: loadouts.missing || null,
      },
      gearPolicy: gearSummary.policy || null,
    },
    stanceVersion: STAFF_STANCE_VERSION,
    stance,
    legalized,
  };
  return {bars, loadouts, roles, stance, legalized};
}
