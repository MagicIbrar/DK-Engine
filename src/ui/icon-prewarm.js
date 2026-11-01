// Resident UI icons, prepared in bounded batches while character selection/map loading runs.
// Canvas sprites remain in UIAtlas's existing cache; no GPU upload or per-frame polling.
import { atlas } from './atlas.js';
import { fetchJSON } from '../engine/assets.js';

export async function warmIcons(values, action, { concurrency = 2, yieldWork = () => new Promise(r => setTimeout(r, 0)) } = {}) {
  let cursor = 0;
  const unique = [...new Set(values)];
  await Promise.all(Array.from({ length: Math.min(Math.max(1, Math.min(4, concurrency)), unique.length) }, async () => {
    while (cursor < unique.length) {
      await action(unique[cursor++]);
      await yieldWork();
    }
  }));
  return unique.length;
}

export function warmSkillIcons(skills, target = atlas, options) {
  const ids = skills.filter(s => !s.hidden).map(s => Number(s.iconIndex ?? s.index)).filter(Number.isFinite);
  return warmIcons(ids, async i => {
    await target.sprite('skill_icon', i);
    if (!(await target.sprite('skill_icon', 10000 + i))) await target.sprite('skill_icon', i, -40);
  }, options);
}

const classes = new Map();
export function prewarmClassIcons(classIndex) {
  const index = Number(classIndex);
  if (!Number.isInteger(index) || index < 0 || index > 14) return Promise.resolve();
  if (!classes.has(index)) classes.set(index, fetchJSON(`/gamedata/skills/class_${index}.json`)
    .then(pack => warmSkillIcons(Object.values(pack.skills || {}))).catch(error => {
      classes.delete(index); console.warn('[ui] skill icon preparation', error?.message || error);
    }));
  return classes.get(index);
}
