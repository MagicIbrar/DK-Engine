// Dekaron model viewer (tools/viewer.html). Uses the engine's own TextureCache / ModelCache / Animator, so what you see
// here is exactly what the game renders. Models live under a mirror root (scale z = -1), as in game.js.
import * as THREE from 'three';
import { OrbitControls } from 'three/addons/controls/OrbitControls.js';
import { fetchJSON, fetchText, normPath, listDir, stats as assetStats } from '../src/engine/assets.js';
import { TextureCache } from '../src/engine/textures.js';
import { ModelCache } from '../src/engine/models.js';
import { Animator } from '../src/engine/animator.js';
import { fileToThree, WORLD_MIRROR } from '../src/engine/space.js';
import { sampleRootMotion } from '../src/formats/anim.js';
import { loadObjectDB, resolveObjectAsync, OBJECT_CATEGORIES } from '../src/formats/assetresolve.js';

const Q = new URLSearchParams(location.search);
const $ = id => document.getElementById(id);
if (Q.get('ui') === '0') document.body.classList.add('noui');

// ------------------------------------------------------------------------------------------ renderer / scene
const canvas = $('c');
const renderer = new THREE.WebGLRenderer({ canvas, antialias: true, preserveDrawingBuffer: true });
THREE.ColorManagement.enabled = false;                 // DX9 gamma-space look (ARCHITECTURE.md §1)
renderer.outputColorSpace = THREE.LinearSRGBColorSpace;
renderer.toneMapping = THREE.NoToneMapping;
renderer.setPixelRatio(Math.min(devicePixelRatio, 2));

const scene = new THREE.Scene();
scene.background = new THREE.Color(0x46525e);
const camera = new THREE.PerspectiveCamera(45, 1, 0.05, 2000);
const controls = new OrbitControls(camera, canvas);
controls.enableDamping = true;

// three.js r155+ Lambert = albedo/PI * irradiance: scale by PI so that intensity 1 == D3D "diffuse * light" (1x)
const ambient = new THREE.AmbientLight(0xffffff, 0.55 * Math.PI);
const sun = new THREE.DirectionalLight(0xffffff, 0.75 * Math.PI);
fileToThree(-4, 9, -7, sun.position);                   // FILE direction: above, in front (-Z) and to the left (-X)
scene.add(ambient, sun);

const worldRoot = new THREE.Group();
worldRoot.name = 'worldRoot (FILE frame, Z mirrored)';
worldRoot.scale.copy(WORLD_MIRROR);
scene.add(worldRoot);
const holder = new THREE.Group();                       // yaw of the model (FILE frame, rotation.y = +deg)
worldRoot.add(holder);
const grid = new THREE.GridHelper(40, 40, 0x8899aa, 0x5a6672);
grid.visible = Q.get('grid') !== '0';
worldRoot.add(grid);
// FILE-frame forward of a yaw-0 model (-Z) — models must face this way while walking forward
const fwd = new THREE.ArrowHelper(new THREE.Vector3(0, 0, -1), new THREE.Vector3(0, 0.02, 0), 1.5, 0xff9933, 0.3, 0.15);
fwd.visible = Q.get('axes') !== '0';
holder.add(fwd);

const textures = new TextureCache(renderer);
const models = new ModelCache(textures);
window.viewer = { THREE, renderer, scene, camera, controls, worldRoot, holder, textures, models };

function resize() {
  const r = $('view').getBoundingClientRect();
  renderer.setSize(r.width, r.height, false);
  camera.aspect = r.width / Math.max(1, r.height);
  camera.updateProjectionMatrix();
}
addEventListener('resize', resize);
resize();

// ------------------------------------------------------------------------------------------ state
const S = {
  kind: null, label: '', model: null, instance: null, object: null, animator: null, clips: [], clipIndex: -1,
  weapon: null, weaponObjs: [], extraInfo: '', paused: false, skelHelper: null, bboxHelper: null, loadId: 0,
  rm: { loops: 0, lastTime: 0 },
};
let DB = { monsters: null, npcs: null, classes: null, objects: null };

function setStatus(t) { $('status').textContent = t; }
const base = k => String(k || '').split('/').pop();

function clearModel() {
  if (S.animator) S.animator.dispose();
  if (S.instance) S.instance.dispose();
  if (S.object) S.object.removeFromParent();
  if (S.skelHelper) { S.skelHelper.removeFromParent(); S.skelHelper.dispose?.(); }
  if (S.bboxHelper) S.bboxHelper.removeFromParent();
  Object.assign(S, { model: null, instance: null, object: null, animator: null, clips: [], clipIndex: -1, weapon: null,
    weaponObjs: [], extraInfo: '', skelHelper: null, bboxHelper: null });
  S.rm = { loops: 0, lastTime: 0 };
  $('clips').innerHTML = '';
}

function frameCamera(opts = {}) {
  const bb = S.model?.bbox;
  const box = bb && !bb.isEmpty() ? bb : new THREE.Box3(new THREE.Vector3(-1, 0, -1), new THREE.Vector3(1, 2, 1));
  const c = box.getCenter(new THREE.Vector3());
  const size = box.getSize(new THREE.Vector3());
  const r = Math.max(size.x, size.y, size.z);
  const [d0, hf, az] = (Q.get('cam') || '').split(',').map(Number);
  const dist = opts.dist ?? (Number.isFinite(d0) && d0 > 0 ? d0 : r * 1.35 + 1.2);
  const hFrac = Number.isFinite(hf) ? hf : 0.35;
  const azim = ((Number.isFinite(az) ? az : 35) * Math.PI) / 180;
  const tq = (Q.get('tgt') || '').split(',').map(Number);   // &tgt=x,y,z FILE-frame look-at point
  const target = tq.length === 3 && tq.every(Number.isFinite) ? fileToThree(tq[0], tq[1], tq[2]) : fileToThree(c.x, c.y, c.z);
  controls.target.copy(target);
  const len = Math.max(0.5, Math.max(size.x, size.z) * 0.8);
  fwd.setLength(len, len * 0.22, len * 0.12);
  // yaw 0 faces FILE -Z = three +Z: put the camera on the +Z side so the model faces the viewer
  camera.position.set(target.x + Math.sin(azim) * dist, target.y + dist * hFrac, target.z + Math.cos(azim) * dist);
  camera.near = Math.max(0.02, dist / 500);
  camera.far = Math.max(200, dist * 20);
  camera.updateProjectionMatrix();
  controls.update();
}

function applyToggles() {
  const wire = $('wire').checked;
  const root = S.instance?.root || S.object;
  root?.traverse(o => { if (o.isMesh && o.material) o.material.wireframe = wire; });
  if ($('skelHelp').checked && S.instance && !S.skelHelper) {
    S.skelHelper = new THREE.SkeletonHelper(S.instance.root);
    scene.add(S.skelHelper);
  } else if (!$('skelHelp').checked && S.skelHelper) { S.skelHelper.removeFromParent(); S.skelHelper = null; }
  if ($('bbox').checked && S.model && !S.bboxHelper) {
    S.bboxHelper = new THREE.Box3Helper(S.model.bbox.clone(), 0x66ccff);
    holder.add(S.bboxHelper);
  } else if (!$('bbox').checked && S.bboxHelper) { S.bboxHelper.removeFromParent(); S.bboxHelper = null; }
}

// ------------------------------------------------------------------------------------------ clip list
const LOOP_ACTIONS = new Set(['STAND', 'MOVE', 'GUARDING', 'BLOCKING', 'EMOTIONKEEP', 'SM_STAND', 'SM_MOVE']);

function renderClips() {
  const el = $('clips');
  el.innerHTML = '';
  S.clips.forEach((c, i) => {
    const d = document.createElement('div');
    d.innerHTML = `<span class="t">${c.duration ? c.duration.toFixed(2) + 's' : ''}</span>${c.label}`;
    d.title = c.animKey;
    d.onclick = () => playClip(i);
    if (i === S.clipIndex) d.className = 'on';
    el.appendChild(d);
  });
}

async function playClip(i, { loop } = {}) {
  const c = S.clips[i];
  if (!c || !S.model?.boneNames) return;
  const id = S.loadId;
  setStatus(`loading ${base(c.animKey)}…`);
  const clip = await models.loadClip(c.animKey, S.model, { duration: c.duration });
  if (id !== S.loadId) return;
  if (!clip) { setStatus(`clip failed: ${c.animKey}`); return; }
  S.clipIndex = i;
  const lp = loop ?? c.loop;
  $('loop').checked = lp;
  S.animator.play(clip, { loop: lp, fade: 0.15, speed: Number($('speed').value) });
  S.rm = { loops: 0, lastTime: 0 };
  S.instance.root.position.set(0, 0, 0);
  if (S.weapon) attachWeapon(c.style === 0 ? 'peace' : 'battle');
  renderClips();
  setStatus(`${base(c.animKey)}  ${clip.tracks.length} tracks (${clip.userData.boundTracks} bones, ${clip.userData.skippedTracks} skipped)`);
}

function pickClip(want) {
  if (want == null || !S.clips.length) return 0;
  if (/^\d+$/.test(want)) return Math.min(S.clips.length - 1, Number(want));
  const w = String(want).toLowerCase();
  let i = S.clips.findIndex(c => c.names.some(n => n.toLowerCase() === w));
  if (i < 0) i = S.clips.findIndex(c => c.label.toLowerCase().includes(w) || c.animKey.includes(w));
  return Math.max(0, i);
}

// ------------------------------------------------------------------------------------------ loaders
async function showSkinned(def, clips, label, extra = '') {
  const id = ++S.loadId;
  clearModel();
  setStatus(`loading ${label}…`);
  const model = await models.loadSkinned(def);
  if (id !== S.loadId) return null;
  if (!model) { setStatus(`failed: ${label}`); $('info').textContent = `${label}\nmodel failed to load (see console)`; return null; }
  S.kind = 'skinned'; S.label = label; S.model = model;
  S.instance = model.instantiate();
  holder.add(S.instance.root);
  S.animator = new Animator(S.instance);
  S.clips = clips;
  S.extraInfo = extra;
  renderClips();
  applyToggles();
  frameCamera();
  if (clips.length) await playClip(pickClip(Q.get('clip')));
  else setStatus(`${label}: no clips`);
  return model;
}

async function showStatic(meshKey, opts, label, extra = '') {
  const id = ++S.loadId;
  clearModel();
  setStatus(`loading ${label}…`);
  const model = await models.loadStatic(meshKey, opts);
  if (id !== S.loadId) return null;
  if (!model) { setStatus(`failed: ${label}`); $('info').textContent = `${label}\nmesh failed to load (see console)`; return null; }
  S.kind = 'static'; S.label = label; S.model = model; S.extraInfo = extra;
  S.object = model.instantiate();
  holder.add(S.object);
  applyToggles();
  frameCamera();
  setStatus(`${label}: static`);
  return model;
}

function actionClipList(set) {
  const names = set.clips.map(() => []);
  for (const [st, v] of Object.entries(set.states || {})) {
    const arr = Array.isArray(v) ? v : [v];
    arr.forEach((ci, k) => { if (ci >= 0 && names[ci]) names[ci].push(Array.isArray(v) ? `${st}${k}` : st); });
  }
  const acts = set.clips.map(() => new Set());
  for (const [a, v] of Object.entries(set.actions || {})) (v || []).forEach(ci => { if (ci >= 0 && acts[ci]) acts[ci].add(a); });
  const unbound = new Set(set.unboundClips || []);
  return set.clips.map((c, i) => ({
    animKey: c[0], duration: c[1], names: names[i], loop: [...acts[i]].some(a => LOOP_ACTIONS.has(a)),
    label: `#${i} ${names[i].join('/') || [...acts[i]].join('/') || '-'} · ${base(c[0])}${unbound.has(i) ? ' (unbound)' : ''}`,
  }));
}

async function loadMonster(idx) {
  DB.monsters ||= await fetchJSON('/gamedata/monsters.json');
  const m = DB.monsters.monsters[idx];
  if (!m) { setStatus(`no monster ${idx}`); return; }
  const shape = DB.monsters.shapes[m.shape] || {};
  const set = DB.monsters.actionSets[m.act] || { clips: [], states: {} };
  const extra = `monster ${idx} lv${m.level} ${m.role} shape=${m.shape} act=${m.act}${m.skelMismatch ? ` skelMismatch=${m.skelMismatch}` : ''}`;
  return showSkinned({ skelKey: set.skel, parts: [{ meshKey: shape.mesh, tpackKey: shape.tpack, textures: shape.textures }] },
    actionClipList(set), `${m.name} (#${idx})`, extra);
}

async function loadNpc(idx) {
  DB.npcs ||= await fetchJSON('/gamedata/npcs.json');
  const n = DB.npcs.npcs[idx];
  if (!n) { setStatus(`no npc ${idx}`); return; }
  const shape = DB.npcs.shapes[n.shape] || {};
  const set = DB.npcs.actionSets[n.act];
  const extra = `npc ${idx} shape=${n.shape} act=${n.act || '-'}${n.static ? ' static' : ''} roles=${(n.roles || []).join(',')}`;
  if (!set || !set.skel) return showStatic(shape.mesh, { tpackKey: shape.tpack, textures: shape.textures }, `${n.name} (npc ${idx})`, extra);
  return showSkinned({ skelKey: set.skel, parts: [{ meshKey: shape.mesh, tpackKey: shape.tpack, textures: shape.textures }] },
    actionClipList(set), `${n.name} (npc ${idx})`, extra);
}

async function loadClass(idx) {
  DB.classes ||= await fetchJSON('/gamedata/classes.json');
  const c = DB.classes.classes.find(x => +x.index === +idx);
  if (!c) { setStatus(`no class ${idx}`); return; }
  const clips = [];
  for (const [k, v] of Object.entries(c.anims || {})) {
    const arr = Array.isArray(v) ? v : [v];
    arr.forEach((e, i) => {
      if (!e || !e.anim) return;
      const name = Array.isArray(v) ? `${k}${i}` : k;
      clips.push({ animKey: e.anim, duration: e.timeLength, names: [name, e.name || name], style: e.style ?? 0,
        loop: LOOP_ACTIONS.has(e.action) || /^(idle|walk|run|sit$)/.test(k),
        label: `${name}${e.name ? ' ' + e.name : ''} · ${base(e.anim)} [s${e.style ?? '-'}]` });
    });
  }
  const useShowcase = Q.get('showcase') === '1' && c.showcase?.parts?.length;
  const parts = (useShowcase ? c.showcase.parts : c.parts).map(p => ({ meshKey: p.mesh, tpackKey: p.tpack, textures: p.textures }));
  const extra = `class ${c.index} ${c.code} skel=${c.skeleton} style=${c.styleName}\nweapon ${c.weapon?.name || '-'} (${base(c.weapon?.mesh)}) battle=${c.weapon?.bone} peace=${c.weapon?.bonePeace}${c.weapon?.leftMesh ? ` left=${c.weapon.boneLeft}/${c.weapon.bonePeaceLeft}` : ''}`;
  const id = S.loadId + 1;
  const wpromise = c.weapon?.mesh ? models.loadStatic(c.weapon.mesh, { tpackKey: c.weapon.tpack, textures: c.weapon.textures }) : null;
  const lpromise = c.weapon?.leftMesh ? models.loadStatic(c.weapon.leftMesh, { tpackKey: c.weapon.leftMesh === c.weapon.mesh ? c.weapon.tpack : null, textures: c.weapon.leftMesh === c.weapon.mesh ? c.weapon.textures : null }) : null;
  const [wm, lm] = await Promise.all([wpromise, lpromise]);
  if (S.loadId + 1 !== id) return;
  S.pendingWeapon = { def: c.weapon, right: wm, left: lm };
  return showSkinned({ skelKey: c.skeleton, parts }, clips, `${c.name} (class ${c.index})`, extra);
}

function attachWeapon(stance) {
  const w = S.weapon;
  if (!w || !S.instance) return;
  for (const o of S.weaponObjs) S.instance.detach(o);
  S.weaponObjs = [];
  const put = (model, bone) => {
    if (!model || !bone) return;
    const o = model.instantiate();
    if (S.instance.attach(o, bone)) S.weaponObjs.push(o);
    else console.warn('viewer: no bone', bone);
  };
  put(w.right, stance === 'peace' ? w.def.bonePeace : w.def.bone);
  if (w.left) put(w.left, stance === 'peace' ? (w.def.bonePeaceLeft || w.def.boneLeft) : w.def.boneLeft);
  applyToggles();
}

async function loadObject(name) {
  DB.objects ||= await loadObjectDB(t => fetchText(t));
  const r = await resolveObjectAsync(name, DB.objects, t => fetchText(t));
  const f = r.flags || {};
  const opts = { tpackKey: r.tpack, twoSide: f.twoside, transparent: f.transparent, maxDiffuse: f.maxdiffuse };
  const extra = `object ${name} (${r.source}) mesh=${r.mesh} tpack=${r.tpack}\nflags twoside=${f.twoside ?? '-'} transparent=${f.transparent ?? '-'} maxdiffuse=${f.maxdiffuse ?? '-'}${r.animated ? `\nskel=${r.skel} anim=${r.anim} (${r.animTime}s)` : ''}`;
  if (r.animated && r.skel) {
    const clips = r.anim ? [{ animKey: r.anim, duration: r.animTime || null, names: ['anim'], loop: true, label: `anim · ${base(r.anim)}` }] : [];
    return showSkinned({ skelKey: r.skel, parts: [{ meshKey: r.mesh, ...opts }] }, clips, name, extra);
  }
  return showStatic(r.mesh, opts, name, extra);
}

async function loadMeshKey(meshKey, { tpack, skel, anim, dur } = {}) {
  const label = base(meshKey);
  if (skel) {
    const clips = anim ? [{ animKey: anim, duration: dur ? Number(dur) : null, names: ['anim'], loop: true, label: base(anim) }] : [];
    return showSkinned({ skelKey: skel, parts: [{ meshKey, tpackKey: tpack || null }] }, clips, label, `mesh ${meshKey}\nskel ${skel}`);
  }
  return showStatic(meshKey, { tpackKey: tpack || null, twoSide: Q.get('twoside'), transparent: Q.get('transparent') }, label, `mesh ${meshKey}`);
}

// ------------------------------------------------------------------------------------------ side panel
let TAB = 'monster';
let listItems = [];
let meshDir = 'mesh/object/building';

async function buildList() {
  const q = $('search').value.trim().toLowerCase();
  const el = $('list');
  el.innerHTML = '';
  let items = [];
  if (TAB === 'monster') {
    DB.monsters ||= await fetchJSON('/gamedata/monsters.json');
    items = Object.entries(DB.monsters.monsters).map(([i, m]) => ({ id: i, text: m.name, sub: `lv${m.level} ${m.shape}${m.spawns ? '' : ' ·nospawn'}` }));
  } else if (TAB === 'npc') {
    DB.npcs ||= await fetchJSON('/gamedata/npcs.json');
    items = Object.entries(DB.npcs.npcs).map(([i, n]) => ({ id: i, text: n.name, sub: n.shape }));
  } else if (TAB === 'class') {
    DB.classes ||= await fetchJSON('/gamedata/classes.json');
    items = DB.classes.classes.map(c => ({ id: String(c.index), text: c.name, sub: c.playable ? '' : 'unplayable' }));
  } else if (TAB === 'object') {
    DB.objects ||= await loadObjectDB(t => fetchText(t));
    const cat = $('objcat')?.value || 'building';
    const tab = DB.objects.tables.get(cat);
    items = tab ? [...tab.values()].map(r => ({ id: `${cat}\\${r.name}`, text: r.name, sub: r.skel ? 'anim' : '' })) : [];
  } else if (TAB === 'mesh') {
    const ents = await listDir(meshDir);
    items = [{ id: '..', text: '..', dir: true }].concat(ents.sort((a, b) => (b.dir - a.dir) || a.name.localeCompare(b.name))
      .map(e => ({ id: `${meshDir}/${e.name}`, text: e.name + (e.dir ? '/' : ''), dir: e.dir })));
  }
  if (q) items = items.filter(it => it.id.toLowerCase().includes(q) || it.text.toLowerCase().includes(q) || (it.sub || '').toLowerCase().includes(q));
  listItems = items;
  for (const it of items.slice(0, 600)) {
    const d = document.createElement('div');
    d.innerHTML = TAB === 'mesh' || TAB === 'object' ? `${it.text} <span class="n">${it.sub || ''}</span>` : `<span class="n">${it.id}</span>${it.text} <span class="n">${it.sub || ''}</span>`;
    d.onclick = () => choose(it, d);
    el.appendChild(d);
  }
  if (items.length > 600) { const d = document.createElement('div'); d.textContent = `… ${items.length - 600} more (refine the search)`; d.style.color = 'var(--dim)'; el.appendChild(d); }
}

async function choose(it, el) {
  for (const n of $('list').children) n.classList.remove('on');
  el?.classList.add('on');
  try {
    if (TAB === 'monster') await loadMonster(it.id);
    else if (TAB === 'npc') await loadNpc(it.id);
    else if (TAB === 'class') await loadClassWithWeapon(it.id);
    else if (TAB === 'object') await loadObject(it.id);
    else if (TAB === 'mesh') {
      if (it.id === '..') { meshDir = meshDir.split('/').slice(0, -1).join('/') || 'mesh'; $('meshdir').value = meshDir; return buildList(); }
      if (it.dir) { meshDir = it.id; $('meshdir').value = meshDir; return buildList(); }
      if (/\.mesh$/.test(it.id)) await loadMeshKey(it.id, { tpack: $('meshtpack').value.trim(), skel: $('meshskel').value.trim(), anim: $('meshanim').value.trim() });
    }
  } catch (err) { console.error(err); setStatus(String(err.message || err)); }
}

async function loadClassWithWeapon(idx) {
  await loadClass(idx);
  if (S.pendingWeapon && S.instance) {
    S.weapon = S.pendingWeapon;
    S.pendingWeapon = null;
    const c = S.clips[S.clipIndex];
    attachWeapon(c && c.style === 0 ? 'peace' : 'battle');
  }
}

function setTab(t) {
  TAB = t;
  for (const b of document.querySelectorAll('#tabs button')) b.classList.toggle('on', b.dataset.tab === t);
  const ex = $('pickExtra');
  ex.innerHTML = '';
  if (t === 'object') {
    const sel = document.createElement('select');
    sel.id = 'objcat';
    for (const c of OBJECT_CATEGORIES) { const o = document.createElement('option'); o.value = o.textContent = c; sel.appendChild(o); }
    sel.value = 'building';
    sel.onchange = buildList;
    ex.appendChild(sel);
  } else if (t === 'mesh') {
    ex.innerHTML = `<input id="meshdir" value="${meshDir}" title="folder (enter to browse) or a .mesh key (enter to load)">
      <input id="meshtpack" placeholder="tpack key (optional; default texturepack/<same path>.tpack)">
      <input id="meshskel" placeholder="skel key (optional -> skinned)"><input id="meshanim" placeholder="anim key (optional)">`;
    ex.querySelector('#meshdir').onkeydown = e => {
      if (e.key !== 'Enter') return;
      const v = normPath(e.target.value);
      if (/\.mesh$/.test(v)) loadMeshKey(v, { tpack: $('meshtpack').value.trim(), skel: $('meshskel').value.trim(), anim: $('meshanim').value.trim() });
      else { meshDir = v; buildList(); }
    };
  }
  $('search').value = '';
  buildList().catch(err => setStatus(String(err)));
}

for (const b of document.querySelectorAll('#tabs button')) b.onclick = () => setTab(b.dataset.tab);
$('search').oninput = () => buildList();
$('search').onkeydown = e => { if (e.key === 'Enter' && listItems[0]) choose(listItems[0], $('list').firstChild); };
for (const id of ['wire', 'skelHelp', 'bbox']) $(id).onchange = applyToggles;
$('speed').oninput = () => { $('speedv').textContent = Number($('speed').value).toFixed(2); S.animator?.setSpeed(Number($('speed').value)); };
$('yaw').oninput = () => { $('yawv').textContent = `${$('yaw').value}°`; holder.rotation.y = (Number($('yaw').value) * Math.PI) / 180; };
$('loop').onchange = () => { if (S.clipIndex >= 0) playClip(S.clipIndex, { loop: $('loop').checked }); };
$('rm').onchange = () => { S.rm = { loops: 0, lastTime: 0 }; if (S.instance) S.instance.root.position.set(0, 0, 0); frameCamera(); };
$('pause').onclick = () => { S.paused = !S.paused; $('pause').textContent = S.paused ? 'play' : 'pause'; };
$('frame').onclick = () => frameCamera();
$('shot').onclick = () => savePNG(`${S.label.replace(/[^a-z0-9_-]+/gi, '_')}.png`);

// ------------------------------------------------------------------------------------------ screenshots
async function savePNG(name) {
  renderer.render(scene, camera);
  const blob = await new Promise(res => canvas.toBlob(res, 'image/png'));
  const sink = Q.get('sink');
  if (sink) {
    const r = await fetch(`http://localhost:${sink}/save?name=${encodeURIComponent(name)}`, { method: 'POST', body: blob });
    setStatus(`saved ${name}: ${r.status}`);
    return r.ok;
  }
  const a = document.createElement('a');
  a.href = URL.createObjectURL(blob);
  a.download = name;
  a.click();
  return true;
}
window.viewer.savePNG = savePNG;

// ------------------------------------------------------------------------------------------ info + loop
function infoText() {
  const L = [];
  if (!S.model) return 'pick a model';
  const m = S.model;
  L.push(`${S.label}`);
  if (S.extraInfo) L.push(S.extraInfo);
  const bb = m.bbox;
  L.push(`bbox ${bb.min.toArray().map(v => v.toFixed(2)).join(',')} .. ${bb.max.toArray().map(v => v.toFixed(2)).join(',')}  h=${(m.height || 0).toFixed(2)}`);
  if (S.kind === 'skinned') L.push(`bones ${m.boneNames.length}${m.missingSkeleton ? ' (MISSING SKELETON: bind pose)' : ''}  parts ${m.parts.length}`);
  for (const p of m.parts.slice(0, 12)) {
    const t = p.texture?.userData;
    const mat = p.material;
    L.push(` ${p.name} slot${p.slot}: ${t ? `${base(t.key)} ${t.format}${t.compressed ? '' : '(rgba)'} ${t.width}x${t.height} α=${t.alphaKind}` : 'NO TEXTURE'}` +
      ` | ${mat.type.replace('Material', '')}${mat.alphaTest ? ` test${mat.alphaTest}` : ''}${mat.transparent ? ' blend' : ''}${mat.side === THREE.DoubleSide ? ' 2side' : ''}` +
      `${p.missingBones?.length ? ` missingBones=${p.missingBones.length}` : ''}`);
  }
  if (m.parts.length > 12) L.push(` … ${m.parts.length - 12} more parts`);
  if (m.helpers && Object.keys(m.helpers).length) L.push(`helpers: ${Object.keys(m.helpers).join(', ')}`);
  const a = S.animator;
  if (a?.clip) L.push(`clip ${base(a.clip.name)} ${a.time.toFixed(2)}/${a.clip.duration.toFixed(2)}s (${(a.progress * 100).toFixed(0)}%)${S.clips[S.clipIndex]?.loop ? '' : ' once'}`);
  L.push(`textures ${textures.stats.loaded} (compressed ${textures.stats.compressed}, rgba ${textures.stats.decoded}, missing ${textures.stats.missing})  files ${assetStats.loaded}`);
  return L.join('\n');
}

const clock = new THREE.Clock();
let infoT = 0;
const tmpV = new THREE.Vector3();
function step() {
  const dt = Math.min(0.1, clock.getDelta());
  if (S.animator && !S.paused) {
    S.animator.update(dt);
    // root-motion preview: move the instance by the clip's own root displacement (model space, forward = -Z)
    const clip = S.animator.clip;
    const rm = clip?.userData?.rootMotion;
    if ($('rm').checked && rm && rm.times.length && S.animator.current) {
      const d = clip.duration || 1;
      const t = S.animator.time;
      if (t + 1e-6 < S.rm.lastTime && S.clips[S.clipIndex]?.loop) S.rm.loops++;
      S.rm.lastTime = t;
      const src = { rootMotion: rm };
      const cur = sampleRootMotion(src, Math.min(1, t / d));
      const full = sampleRootMotion(src, 1);
      if (S.rm.loops > 4) { S.rm.loops = 0; }
      const before = S.instance.root.getWorldPosition(tmpV).clone();
      S.instance.root.position.set(cur[0] + full[0] * S.rm.loops, 0, cur[2] + full[2] * S.rm.loops);
      const after = S.instance.root.getWorldPosition(new THREE.Vector3());
      const delta = after.sub(before);
      controls.target.add(delta); camera.position.add(delta);
    }
  }
  controls.update();
  renderer.render(scene, camera);
  infoT -= dt;
  if (infoT <= 0) { infoT = 0.2; $('info').textContent = infoText(); }
}
// rAF drives the loop; background tabs and non-composited panes starve rAF, so a timer takes over when it stalls
// (keeps automated captures animating).
let lastRaf = 0;
function rafLoop() {
  lastRaf = performance.now();
  try { step(); } catch (err) { console.error('[viewer] frame', err); }
  requestAnimationFrame(rafLoop);
}
requestAnimationFrame(rafLoop);
setInterval(() => {
  if (performance.now() - lastRaf < 250) return;
  try { step(); } catch (err) { console.error('[viewer] frame', err); }
}, 33);

/** Jump the current clip to `sec` seconds and pause (deterministic captures: &t=<seconds>). */
function seek(sec) {
  const a = S.animator;
  if (!a?.current || !Number.isFinite(sec)) return;
  a.update(1);                                    // finish any cross-fade first
  a.current.time = Math.max(0, Math.min(sec, a.clip.duration));
  a.mixer.update(0);
  S.paused = true;
  $('pause').textContent = 'play';
}

// ------------------------------------------------------------------------------------------ boot from URL
(async () => {
  if (Q.get('speed')) { $('speed').value = Q.get('speed'); $('speedv').textContent = Number(Q.get('speed')).toFixed(2); }
  if (Q.get('yaw')) { $('yaw').value = Q.get('yaw'); $('yaw').oninput(); }
  if (Q.get('rm') === '1') $('rm').checked = true;
  let tab = 'monster';
  try {
    if (Q.get('class') != null) { tab = 'class'; setTab(tab); await loadClassWithWeapon(Q.get('class')); }
    else if (Q.get('npc') != null) { tab = 'npc'; setTab(tab); await loadNpc(Q.get('npc')); }
    else if (Q.get('object') != null) {
      tab = 'object'; setTab(tab);
      const cat = Q.get('object').split(/[\\/]/)[0].toLowerCase();
      if ($('objcat') && OBJECT_CATEGORIES.includes(cat)) { $('objcat').value = cat; buildList(); }
      await loadObject(Q.get('object'));
    }
    else if (Q.get('mesh') != null) { tab = 'mesh'; setTab(tab); await loadMeshKey(normPath(Q.get('mesh')), { tpack: Q.get('tpack'), skel: Q.get('skel'), anim: Q.get('anim'), dur: Q.get('dur') }); }
    else { setTab(tab); await loadMonster(Q.get('monster') ?? 102); }
  } catch (err) { console.error(err); setStatus(String(err.message || err)); }
  if (Q.get('t') != null) seek(Number(Q.get('t')));
  window.viewer.ready = true;
})();
Object.assign(window.viewer, { S, loadMonster, loadNpc, loadClass: loadClassWithWeapon, loadObject, loadMeshKey, playClip, frameCamera, attachWeapon, seek });
