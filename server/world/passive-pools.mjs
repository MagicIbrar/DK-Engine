import { SkillData } from '../../src/systems/skills/data.js';
import { SkillEngine } from '../../src/systems/skills/engine.js';

const POOLS = new Set(['HP_MAX_ADD', 'HP_MAX_MUL', 'MP_MAX_ADD', 'MP_MAX_MUL']);

/**
 * Derive learned HP/MP passive options from the profile being evaluated, not a
 * live actor's possibly stale cache. No runtime is initialized and no skill is
 * granted. The existing engine owns rank, path, style and weapon-status rules.
 */
export function createProfilePassivePools(source) {
  const classes = new Map();
  function classData(index) {
    const pack = source.skillPacks?.[index];
    if (!pack) return null;
    if (classes.has(index)) return classes.get(index);
    const data = new SkillData();
    data.classIndex = index; data.pack = pack; data.common = source.skillCommon || {};
    for (const [id, value] of Object.entries(pack.skills || {})) data.skills.set(Number(id), value);
    // Same precedence as the host skill adapter, including weapon-status rows.
    for (const rows of [source.skillStatuses, data.common.statuses, pack.statuses])
      for (const [id, value] of Object.entries(rows || {})) data.statuses.set(Number(id), value);
    data._wantFull = () => {};
    classes.set(index, data);
    return data;
  }
  return (profile, style) => {
    const data = classData(Number(profile.classIndex));
    if (!data || !profile.skills) return [];
    // Only call the engine's pure lookup methods: constructor, ensureSkills,
    // auto-unlock, combat and refresh hooks never run during stat derivation.
    const view = Object.create(SkillEngine.prototype);
    view.game = { save: profile }; view.data = data;
    view.equippedStyle = () => Number(style);
    return view.passiveEntries().flatMap(entry => {
      const options = entry.options.filter(option => POOLS.has(option.code));
      return options.length ? [{ ...entry, options }] : [];
    });
  };
}
