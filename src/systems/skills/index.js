import {seedStarterSlot} from './starter.js';
import {parseSkillMessages} from './messages.js';
// Skills system (key: skills) — every class's skill tree, casting, results, statuses, effects, summons and the
// original skill windows. Data: gamedata/skills/{common,class_<c>}.json (tools/build-skills-runtime.mjs from
// gamedata/skills*.json; docs/formats/skills.md, effects.md).
//
// PUBLIC API (other systems):
//   game.skills        SkillEngine (engine.js): use(slot|{skillIndex}), useSkill(index, {target, point, free}), busy,
//                      skillLevel(i), learnedLevel(i), canLevel(i), learn(i), setLevel(i, lv), resetPoints('skill'|
//                      'attribute'), cooldownRemaining(i) (s), cooldownFraction(i), resetCooldowns(i?), skillDef(i),
//                      list (class skills), castProgress {skill, t, dur} (cast bar), addStatus(actor, skill,
//                      statusIndex, ms, source), applyResult(ctx, result), passiveEntries(), msg(code)
//   game.statuses      StatusSystem (statuses.js): add(actor, statusIndex, ms, {source, skill}), remove(actor, pred),
//                      removeGroup(actor, group, count), listOf(actor), value(actor, code), flags(actor)
//                      entries {key, statusIndex, name, description, iconIndex (imagetable buffer / buffer_b), remaining,
//                      duration, stacks, buff (true = buff, false = debuff), options[]}; event 'status' {actor, status, on}
//   game.effects       EffectPlayer (effects.js): play(actorOrPoint, {cate, id, scene, timeMs}, {loop, bone}) -> handle
//                      {stop(hard)}; playAt(point, ref)
//   game.summons       SummonSystem (summons.js): servantOf(owner), all(), recall(owner), dismiss(servant),
//                      command('assist'|'attack'|'free'|'call'|'stop'|'destroy'), useGreat(), greatCharge(servant), mode
//   game.skills.spells SpellSystem (spells.js): spell.csv spells (charges, procs); spell(i), cast(ctx, result)
//   game.skills.basicAttack(target, comboRow)  combo.csv rows with their own result (arrows, area swings)
//   state().procs      force stones + runes (procs.js): forceList(), heldRunes()
//   game.skillsUI      tooltip(index) -> uiwin tooltip content, open(tab), dragPayload(index), levelUp(index),
//                      openReinforce(index), reset('skill'|'attribute'), refresh(), tabs
//   Windows (uiwin): skills (K), skillup, skillreset, skill_reinforce, servant_win, servantskill
//   Drag payload of a skill icon (uiwin dnd): data = {type: 'skill', kind: 'skill', index, skillIndex, from: 'skillwnd'}
//   Events: 'skill' {actor, skill, level, target}, 'skill:end', 'skilllearn' {skill, level}, 'status', 'summon'
//           {owner, servant, on}, 'transup' {stage}
import { SkillData } from './data.js';
import { EffectPlayer } from './effects.js';
import { StatusSystem, optionSum } from './statuses.js';
import { SkillEngine } from './engine.js';
import { SummonSystem } from './summons.js';
import { installHooks } from './hooks.js';
import { installSkillWindows } from './ui-skillwnd.js';
import { installProcs } from './procs.js';
import { installGauges } from './gauges.js';
import { fetchText } from '../../engine/assets.js';
import { installRecoveryEffects } from './recovery.js';
import { SkillEffectResources } from './effect-resources.js';

let sys = null;

export async function install(game) {
  const classIndex = Number(game.classDef?.index ?? game.save?.classIndex ?? 0);
  const data = await new SkillData().load(classIndex);
  const fx = new EffectPlayer(game, data);
  const statuses = new StatusSystem(game, data, fx);
  const engine = new SkillEngine(game, { data, fx, statuses });
  const summons = new SummonSystem(engine);
  engine.summons = summons;
  sys = { game, data, fx, statuses, engine, summons, ready: false };

  // ---- class skill list: every class now has its full tree (skills.md §13.1)
  const cls = data.classRec;
  const list = (cls?.skills || []).map(i => data.skill(i)).filter(Boolean);
  if (game.classDef) {
    // the items system re-derives game.classDef from its _base (the classes.json record) on every weapon change,
    // so the tree goes on the base record as well as the current copy
    const tree = { tabs: cls?.tabs || [], tabNames: cls?.tabNames || {}, moveSkills: cls?.moveSkills || {} };
    for (const c of new Set([game.classDef, game.classDef._base].filter(Boolean))) {
      c.skills = list;
      c.playable = true;
      c.skillTree = tree;
    }
  }
  for (const c of game.data?.classes || []) c.playable = true;   // all 15 classes have complete trees now

  // ---- replace the early SkillSystem (same interface; keeps its cooldowns)
  const old = game.skills;
  if (old?.cooldowns instanceof Map) for (const [k, v] of old.cooldowns) engine.cooldowns.set(k, v);
  try { old?.clear?.(); } catch { /* ignore */ }
  game.skills = engine;
  game.effects = fx;
  game.statuses = statuses;
  game.summons = summons;

  // ---- client messages (<cate> 60 of stringtable_skill.txt)
  engine.messages = await loadMessages();
  await engine.spells.load();
  await summons.loadGauges();

  // ---- save: learned skills, points, meister (see migrate)
  migrateSave(game, engine, list);
  // a skill reset takes the reset skills off the quick slots
  game.events?.on?.('skilllearn', e => { if (e?.reset || e?.level === 0) scrubSlots(game, engine); });
  // the "given to one who reached N lv" passives (Helion's Blessing ... every level free, one per character level)
  autoLevelGifts(game, engine, list, true);
  game.events?.on?.('levelup', () => autoLevelGifts(game, engine, list, false));
  // user's server rule (ARCHITECTURE.md 2j (f)): skills unlock by themselves at their required level and go on the
  // quick slot bar. Skills the level already allows are learned now (silently); their bar placement waits for the HUD.
  // User (09-29 12:10): skills still unlock by level, but are NOT placed on the bar automatically. The player builds
  // their own bar (placeOnBar stays exported for an explicit "fill bar" action only).
  autoUnlock(game, engine, list, { silent: true });
  game.events?.on?.('levelup', () => autoUnlock(game, engine, list, { silent: false }));

  engine.effectResources = new SkillEffectResources(engine);
  // Visual resources are prepared only by the requested-cast guards. Sweeping
  // every learned skill here blocks required-system installation and competes
  // with first map/UI loading; optional graphics must not gate world entry.
  sys.offResources=['skilllearn','equip','transup','map','teleport','network'].map(
    event=>game.events?.on?.(event,()=>engine.effectResources.cancel()));

  installHooks(game, sys);
  sys.offRecovery = installRecoveryEffects(game, data, fx);
  try { sys.procs = await installProcs(game, sys); } catch (err) { console.error('[skills] force / rune procs failed', err); }
  try { await installGauges(game, sys); } catch (err) { console.error('[skills] class gauge failed', err); }
  try { await installSkillWindows(game, sys); } catch (err) { console.error('[skills] windows failed', err); }
  sys.ready = true;
  game.events?.emit('skills:ready', { classIndex });
}

export function update(dt, game) {
  if (!sys) return;
  sys.fx.update(dt);
  sys.summons.update(dt);
  sys.hookUpdate?.(dt);
  sys.gauge?.update(dt);
}

export function dispose() {
  if (!sys) return;
  sys.offRecovery?.();
  for(const off of sys.offResources||[])off?.();
  sys.engine.effectResources?.dispose();
  sys.summons.clear();
  sys.fx.dispose();
  sys = null;
}

/** The running system (tests / GM tools). */
export function state() { return sys; }

// ------------------------------------------------------------------------------------------ helpers
async function loadMessages() {
  try {
    return parseSkillMessages(await fetchText('script/string/normal/stringtable_skill.txt', true));   // parser: ./messages.js (shared with the host)
  } catch (err) { console.warn('[skills] stringtable_skill.txt', err); }
  return {};
}

/**
 * Save layout: save.skills {index: level} (learned levels), save.skillPoints, save.attrPoints, save.meister
 * {path: 'A'|'B'|null}, save.skillsV2 (migration flag).
 * Migration from the early system (which treated level 1 as innate once reqLevel was met): every free level-1 skill
 * (spCost 0) the character's level and prerequisites allow is recorded as learned, once. New level-1 characters get
 * their free starting skills (reqLevel 1, no prerequisites) the same way; everything else is learned in the window.
 */
function migrateSave(game, engine, list) {
  const s = game.save;
  if (!s) return;
  s.skills = s.skills || {};
  if (s.attrPoints == null) s.attrPoints = Math.max(0, (Number(s.level) || 1) - 199);
  if (!s.meister) s.meister = { path: null };
  if (!s.skillsV2) {
    const lv = Number(s.level) || 1;
    let changed = true, guard = 0;
    while (changed && guard++ < 12) {
      changed = false;
      for (const sk of list) {
        if (sk.hidden || sk.tree?.window === 'meister' || s.skills[sk.index]) continue;
        const L1 = sk.levels?.[0];
        if (!L1 || Number(L1.spCost) > 0 || Number(L1.reqLevel) > lv || Number(L1.grade) > 0) continue;
        if (sk.tree?.window === 'attribute' || sk.tree?.window === 'life') continue;
        if ((L1.prereqs || []).some(p => engine.learnedLevel(p.skill) < Number(p.level))) continue;
        if (lv === 1 && (L1.prereqs || []).length) continue;
        s.skills[sk.index] = 1;
        changed = true;
      }
    }
    s.skillsV2 = true;
  }
  // Preserve the player's layout, including an intentionally empty bar.
  if (!Array.isArray(s.hotbar)) s.hotbar = [];
  if(s.authority!=='server')seedStarterSlot(s,list);
  scrubSlots(game, engine);
  s.servant = null;
  void optionSum;
}

/**
 * Level gifts: passive / mastery skills whose every level is free (spCost 0), with no prerequisites, whose levels
 * follow the character level (Helion's Blessing 160..169, Will 170.., Convictions 180.., Attribution 190..). They are
 * granted, not bought: each character level reached raises them.
 */
function autoLevelGifts(game, engine, list, silent) {
  const lv = Number(game.save?.level) || 1;
  for (const s of list) {
    if (s.hidden || !engine.isPassive(s) || s.tree?.window !== 'skill') continue;
    const L = s.levels || [];
    if (!L.length || L.some(l => Number(l.spCost) > 0 || (l.prereqs || []).length)) continue;
    if (L.length < 2 || Number(L[1].reqLevel) !== Number(L[0].reqLevel) + 1) continue;
    let target = 0;
    for (let i = 0; i < L.length; i++) if (Number(L[i].reqLevel) <= lv) target = i + 1;
    target = Math.min(target, engine.maxLevelFor(s));
    if (target > engine.learnedLevel(s.index)) engine.setLevel(s.index, target, { silent });
  }
}

/**
 * Auto-unlock (this server): every skill of the class's normal skill tabs whose level-1
 * requirements are met (character level >= reqLevel, prerequisite skills learned, trans-up grade, path) is learned at
 * level 1 for free as soon as the character reaches that level; chains unlock in one go (the prerequisites of the
 * class trees are all "skill X Lv.1"). Higher levels are still bought with skill points in the skill window. Meister,
 * attribute and life tabs keep their own rules. Returns the skills learned.
 */
export function autoUnlock(game, engine, list, { silent = false } = {}) {
  const s = game.save;
  if (!s) return [];
  const lv = Number(s.level) || 1;
  const grade = Number(s.grade ?? s.transGrade ?? 0) || 0;
  // A confirmed paid-skill reset survives reload/level-up. Other characters
  // and zero-cost first ranks retain the existing automatic unlock policy.
  const paidReset = new Set(Array.isArray(s.normalSkillResetSuppressed) ? s.normalSkillResetSuppressed : []);
  const got = [];
  let changed = true, guard = 0;
  while (changed && guard++ < 24) {
    changed = false;
    for (const sk of list) {
      if (sk.hidden || engine.learnedLevel(sk.index) > 0) continue;
      if (sk.tree?.window !== 'skill') continue;
      const L1 = sk.levels?.[0];
      if (!L1 || Number(L1.reqLevel) > lv || (Number(L1.grade) || 0) > grade) continue;
      if (Number(L1.spCost) > 0 && paidReset.has(sk.index)) continue;
      if (L1.availability && L1.availability !== 'all') continue;
      if ((L1.prereqs || []).some(p => engine.learnedLevel(p.skill) < Number(p.level))) continue;
      engine.setLevel(sk.index, 1, { silent });
      got.push(sk);
      changed = true;
    }
  }
  return got;
}

/** Put newly learned active skills on the quick slot bar (the bottom row's set first, then the other sets). */
export function placeOnBar(game, skills) {
  const eng = game.skills;
  const act = (skills || []).filter(sk => sk && !(eng?.isPassive?.(sk)));
  if (!act.length) return 0;
  const q = game.save?.quickslot, qs = game.quickslot;
  const sets = q && Array.isArray(q.sets) ? q.sets : [game.save.hotbar || (game.save.hotbar = [])];
  const onBar = (i) => sets.some(set => (set || []).some(e => e?.type === 'skill' && Number(e.index) === Number(i)));
  // the rows the bar shows (1..3 unfolded rows, bottom row first)
  const order = q ? [...new Set((q.rowSet || [0]).slice(0, Math.max(1, Number(q.rows) || 1)))] : [0];
  let n = 0;
  for (const sk of act) {
    if (onBar(sk.index)) continue;
    let done = false;
    for (const si of order) {
      const set = sets[si] || [];
      const len = Math.max(q ? 12 : 10, set.length);
      let i = -1;
      for (let k = 0; k < len; k++) if (!set[k]) { i = k; break; }
      if (i < 0) continue;
      const entry = { type: 'skill', index: sk.index };
      if (qs?.set && q) qs.set(si, i, entry); else set[i] = entry;
      done = true; n++;
      break;
    }
    if (!done) break;   // every slot is taken
  }
  if (n) game.events?.emit?.('hotbar', { auto: true });
  return n;
}

/** Remove skills that are not learned (unknown, reset, other class) from the hot bar and the quick-slot sets. */
export function scrubSlots(game, engine) {
  const s = game.save;
  if (!s) return 0;
  const ok = e => !e || e.type !== 'skill' || (engine.skillDef(e.index) && engine.learnedLevel(e.index) > 0);
  let n = 0;
  const clean = arr => { if (Array.isArray(arr)) for (let i = 0; i < arr.length; i++) if (!ok(arr[i])) { arr[i] = null; n++; } };
  clean(s.hotbar);
  for (const set of s.quickslot?.sets || []) clean(set);
  if (n) game.events?.emit?.('hotbar', { scrub: true });
  return n;
}
