// Native "effect body" monsters: fighting monsters whose model is drawn only by their action effects.
//
// AUTHENTICATED NATIVE PATTERN (Global client data, e.g. Nest of Cherubim Ghostman_knight 3810 / Ghostman_archer 3813):
//  - script/shape/monster_shape.csv binds the shape to an empty `*_none.mesh` with no texture pack, so the body itself
//    draws nothing (the same convention as trap / trigger volumes);
//  - the monster's own action table (share/action/monster/*.act.<index>.csv) puts an Effect id on its combat records
//    (ATTACK / BLOCKING / BLOCKED / DEFEAT / DEAD / GUARDING) and 0 on STAND / MOVE;
//  - script/effect/modeleffect.csv code1 25 / code2 1 (monster action-record effects) maps each id (code4) to one effect
//    scene, and every one of those scenes (property/effect/effectscene.*.txt) draws a mesh unit of the REAL body model
//    (the shape mesh without "_none"; property/effect/effectdata.*.txt).
// So the native client shows such a monster only while it attacks, blocks, guards, takes a hit or dies, as its own
// flickering body effect. Trap volumes that merely play an attack/explosion effect (A_trap, fire/thunder traps, the
// Ghostman-shaped trap rows 3765/5356/5357/7417/7429) do not draw the body mesh and stay invisible helpers.
// Every id must resolve to exactly one row and every scene must draw the body; otherwise the monster is not classified
// (fail closed). This module has no engine imports: tools/build-monsters.mjs and the runtime both use it.

export const MONSTER_ACTION_EFFECT = Object.freeze({ code1: 25, kind: 1 });
export const EFFECT_FILES = Object.freeze(['01', '02', '03', 'com', 'map']);
const CLIP_EFFECT = 7;   // monsters.json clipFields: [anim, timeLength, startInter, endInter, timing, split, timing2, effect, ...]

const norm = p => String(p ?? '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
const file = p => norm(p).split('/').pop();
const num = v => { const n = Number(String(v ?? '').trim()); return Number.isFinite(n) ? n : NaN; };

/** modeleffect.csv rows (arrays of cells, header allowed) -> Map(actionEffectId -> [{cate,id,scene,timeMs,loop,variant}]). */
export function monsterActionEffectRows(rows) {
  const out = new Map();
  for (const r of rows || []) {
    const c = (r || []).map(num);
    if (c[0] !== MONSTER_ACTION_EFFECT.code1 || c[1] !== MONSTER_ACTION_EFFECT.kind || !(c[3] > 0) || !(c[5] > 0)) continue;
    const list = out.get(c[3]) || [];
    list.push({ cate: c[4], id: c[5], scene: c[6] || 1, timeMs: c[7] || 0, loop: c[8] || 0, variant: c[2] });
    out.set(c[3], list);
  }
  return out;
}

/** property/effect/effectscene.<file>.txt text -> Map("cate:id" -> {file, res:[unit names, lower case]}). The first file
 *  that defines a key wins, in EFFECT_FILES order (as the runtime loader resolves it). */
export function effectSceneResources(text, fileTag = '', into = new Map()) {
  let cate = null, cur = null;
  for (const raw of String(text || '').split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line.startsWith('#')) continue;
    let m;
    if ((m = /^<cate>\s+(\d+)/i.exec(line))) { cate = Number(m[1]); continue; }
    if (/^<effect>$/i.test(line)) { cur = { id: null, res: [] }; continue; }
    if (/^<\/effect>$/i.test(line)) { if (cur && cur.id != null && cate != null) { const key = `${cate}:${cur.id}`; if (!into.has(key)) into.set(key, { file: fileTag, res: cur.res }); } cur = null; continue; }
    if (!cur) continue;
    if (cur.id == null && (m = /^id\s+(\d+)$/i.exec(line))) { cur.id = Number(m[1]); continue; }
    if ((m = /^res\s+\d+\s+(\S+)$/i.exec(line))) cur.res.push(m[1].toLowerCase());
  }
  return into;
}

/** property/effect/effectdata.<file>.txt text -> Map("<file>:<unit name lower>" -> {type, mesh}). */
export function effectMeshUnits(text, fileTag = '', into = new Map()) {
  let cur = null;
  for (const raw of String(text || '').split(/\r?\n/)) {
    const line = raw.trim();
    if (/^<effectdata>/i.test(line)) { cur = { name: '', type: '', mesh: null }; continue; }
    if (/^<\/effectdata>/i.test(line)) { if (cur?.name) into.set(`${fileTag}:${cur.name.toLowerCase()}`, { type: cur.type.toLowerCase(), mesh: cur.mesh }); cur = null; continue; }
    if (!cur) continue;
    const m = /^(\S+)\s+(.*)$/.exec(line);
    if (!m) continue;
    const key = m[1].toLowerCase(), value = m[2].trim();
    if (key === 'name') cur.name = value; else if (key === 'unittype') cur.type = value; else if (key === 'mesh') cur.mesh = value || null;
  }
  return into;
}

/**
 * Classify one monster. clips = its action-set clips (monsters.json actionSets[act].clips).
 * @returns {{body:'effect', bodyMesh:string, bodyEffects:Object<string,{cate,id,scene,timeMs,loop}>}|null}
 */
export function classifyEffectBody({ shapeMesh, shapeTpack, clips, rows, scenes, units } = {}) {
  if (!/_none\.mesh$/i.test(norm(shapeMesh)) || shapeTpack || !Array.isArray(clips) || !rows || !scenes || !units) return null;
  const bodyMesh = file(shapeMesh).replace(/_none\.mesh$/, '.mesh');
  const ids = [...new Set(clips.map(c => Number(c?.[CLIP_EFFECT])).filter(e => e > 0))].sort((a, b) => a - b);
  if (!ids.length) return null;
  const bodyEffects = {};
  for (const id of ids) {
    const list = rows.get(id) || [];
    if (list.length !== 1) return null;                       // unresolved or ambiguous variant
    const ref = list[0], scene = scenes.get(`${ref.cate}:${ref.id}`);
    if (!scene) return null;
    const drawsBody = scene.res.some(name => { const u = units.get(`${scene.file}:${name}`); return u?.type === 'mesh' && file(u.mesh) === bodyMesh; });
    if (!drawsBody) return null;
    bodyEffects[id] = { cate: ref.cate, id: ref.id, scene: ref.scene, timeMs: ref.timeMs, loop: ref.loop };
  }
  return { body: 'effect', bodyMesh, bodyEffects };
}

/** The authored body effect of an action-set clip of an effect-body monster, or null. */
export function bodyEffectRef(def, actionSet, clipIndex) {
  if (def?.body !== 'effect' || !Number.isInteger(clipIndex) || clipIndex < 0) return null;
  const id = Number(actionSet?.clips?.[clipIndex]?.[CLIP_EFFECT]);
  const ref = id > 0 ? def.bodyEffects?.[id] : null;
  return ref && ref.id > 0 ? { cate: Number(ref.cate), id: Number(ref.id), scene: Number(ref.scene) || 1, timeMs: Number(ref.timeMs) || 0, loop: Number(ref.loop) || 0, effect: id } : null;
}
