// CUSTOM (not Global) - "Party Rocker", a custom dancing NPC in Ardeca. Nothing in this folder exists in the Global client data.
// Added 2026-10-29 at the owner's request. It is an original character and does not depict any real person.
//
//   Where:  map 150 (Ardeca), FILE-frame 410, 446 (the coordinates the minimap label shows, the frame of npcs.json placements).
//   Body:   the Global Azure Knight class body (classes.json class 0: swd.skel + the default helmet/coat/pants/glove/boots meshes)
//           looping the Global emote clip anim/character/swordmans/motion/emoti/swd_emt_dance.anim (classes.json anims, 4.5 s).
//   Look:   CUSTOM leopard-print texture variant (drawn at runtime) on per-instance copies of the coat and pants materials
//           (the shared Global materials, which every Azure Knight uses, are never touched), plus a CUSTOM afro and CUSTOM big
//           sunglasses built from simple shapes and attached to the head bone.
//   Music:  CUSTOM track party-track.mp3 in this folder (the owner's own file), streamed through an <audio> element into the
//           game's Web Audio graph: loops, follows the music volume, distance roll-off (audio.js distanceGain) and stereo pan
//           (audio.js spatial) from the NPC, silent and paused beyond MUSIC_RANGE metres.
//   Online: NPC bodies are placed client-side by Game._spawnNpcs in both solo and server-authority play; this NPC has no jobs
//           (no shop / quest / warp), so the server's NPC service table needs no row for it.
//   Remove: delete src/custom/party-rocker/ and the two marked "CUSTOM party-rocker" lines in src/game/game.js.
import * as THREE from 'three';
import { NPC } from '../../actors/npc.js';
import { distanceGain } from '../../game/audio.js';

export const CUSTOM_TAG = 'CUSTOM (not Global)';
export const PARTY_ROCKER = Object.freeze({
  tag: CUSTOM_TAG,
  index: 990001,                 // outside every Global npcs.json index (max 60006): never collides with authored NPCs
  name: 'Party Rocker',
  map: 150,
  x: 410, z: 446,
  dirDeg: 180,
  classIndex: 0,                 // Azure Knight body
  dance: { anim: 'anim/character/swordmans/motion/emoti/swd_emt_dance.anim', timeLength: 4.5 },
  music: { file: 'party-track.mp3', range: 40, volume: 0.9 },
});
const MUSIC_URL = new URL(`./${PARTY_ROCKER.music.file}`, import.meta.url).href;
const log = (...a) => console.info('[CUSTOM party-rocker]', ...a);

/** Spawn the CUSTOM NPCs of `world` into game.npcs; returns their load promises. */
export function spawnCustomNpcs(game, world) {
  const map = Number(world?.info?.index);
  if (map !== PARTY_ROCKER.map) return [];
  if ((game.npcs || []).some(n => n.npcIndex === PARTY_ROCKER.index)) return [];
  const npc = new PartyRockerNPC(game);
  game.npcs.push(npc);
  return [npc.load().catch(err => console.warn('[CUSTOM party-rocker] failed', err))];
}

let leopardTex = null;
/** CUSTOM leopard-print texture (golden ground, dark rosettes with amber centres, a little hot pink to be loud). */
function leopardTexture() {
  if (leopardTex) return leopardTex;
  const S = 512, c = document.createElement('canvas');
  c.width = c.height = S;
  const g = c.getContext('2d');
  g.fillStyle = '#d8962a'; g.fillRect(0, 0, S, S);
  let seed = 7;
  const rnd = () => ((seed = (seed * 16807) % 2147483647) / 2147483647);
  for (let i = 0; i < 2200; i++) { g.fillStyle = `rgba(255,${200 + rnd() * 40 | 0},90,${0.08 + rnd() * 0.1})`; g.fillRect(rnd() * S, rnd() * S, 6, 6); }
  for (let i = 0; i < 60; i++) {
    const x = rnd() * S, y = rnd() * S, r = 14 + rnd() * 14;
    for (const [dx, dy] of [[0, 0], [S, 0], [-S, 0], [0, S], [0, -S]]) {
      g.save(); g.translate(x + dx, y + dy); g.rotate(rnd() * Math.PI);
      g.fillStyle = rnd() < 0.18 ? '#ff2fa0' : '#b5560f';
      g.beginPath(); g.ellipse(0, 0, r * 0.75, r * 0.55, 0, 0, Math.PI * 2); g.fill();
      g.fillStyle = '#1b0f08';
      const n = 4 + (rnd() * 3 | 0);
      for (let k = 0; k < n; k++) {
        const a = (k / n) * Math.PI * 2 + rnd() * 0.5;
        g.beginPath(); g.ellipse(Math.cos(a) * r * 0.85, Math.sin(a) * r * 0.65, r * 0.32, r * 0.18, a + Math.PI / 2, 0, Math.PI * 2); g.fill();
      }
      g.restore();
    }
  }
  leopardTex = new THREE.CanvasTexture(c);
  leopardTex.wrapS = leopardTex.wrapT = THREE.RepeatWrapping;
  leopardTex.colorSpace = THREE.SRGBColorSpace;
  leopardTex.repeat.set(2, 2);
  leopardTex.name = 'CUSTOM party-rocker leopard';
  return leopardTex;
}

/** CUSTOM afro + sunglasses in root-local (FILE frame, bind pose: feet at origin, face towards -Z). */
function buildHeadwear() {
  const hair = new THREE.Group(); hair.name = 'CUSTOM party-rocker afro';
  const hairMat = new THREE.MeshLambertMaterial({ color: 0x24140c });
  const ball = new THREE.SphereGeometry(1, 12, 9);
  const core = new THREE.Mesh(ball, hairMat); core.scale.set(0.2, 0.17, 0.19); hair.add(core);
  let seed = 3; const rnd = () => ((seed = (seed * 16807) % 2147483647) / 2147483647);
  for (let i = 0; i < 90; i++) {                       // bumpy curls over the surface
    const u = rnd() * 2 - 1, t = rnd() * Math.PI * 2, s = Math.sqrt(1 - u * u);
    const curl = new THREE.Mesh(ball, hairMat);
    const r = 0.05 + rnd() * 0.025;
    curl.scale.setScalar(r);
    curl.position.set(s * Math.cos(t) * 0.19, u * 0.16, s * Math.sin(t) * 0.18);
    hair.add(curl);
  }
  hair.position.set(0, 2.17, 0.045);
  const shades = new THREE.Group(); shades.name = 'CUSTOM party-rocker sunglasses';
  const lensMat = new THREE.MeshBasicMaterial({ color: 0x0b0b10, side: THREE.DoubleSide });   // dark tinted lenses
  const frameMat = new THREE.MeshPhongMaterial({ color: 0xffd23a, specular: 0xffffff, shininess: 60 });
  for (const sx of [-1, 1]) {
    const lens = new THREE.Mesh(new THREE.CylinderGeometry(0.056, 0.056, 0.02, 24), lensMat);
    lens.rotation.x = Math.PI / 2; lens.scale.set(1.12, 1, 0.88); lens.position.set(sx * 0.062, 0, 0); shades.add(lens);
    const rim = new THREE.Mesh(new THREE.TorusGeometry(0.058, 0.008, 6, 24), frameMat);
    rim.scale.set(1.12, 0.88, 1); rim.position.set(sx * 0.062, 0, -0.002); shades.add(rim);
    const arm = new THREE.Mesh(new THREE.BoxGeometry(0.008, 0.008, 0.13), frameMat);
    arm.position.set(sx * 0.122, 0.005, 0.07); shades.add(arm);
  }
  const bridge = new THREE.Mesh(new THREE.BoxGeometry(0.03, 0.009, 0.009), frameMat); bridge.position.set(0, 0.012, -0.002); shades.add(bridge);
  shades.position.set(0, 1.995, -0.15);
  return [hair, shades];
}

export class PartyRockerNPC extends NPC {
  constructor(game) {
    const P = PARTY_ROCKER;
    super(game, { index: P.index, name: P.name, custom: true, customTag: CUSTOM_TAG, jobs: [], roles: [], mapVisible: 0, nameVisible: 1, minimapColor: 0 },
      { npcIndex: P.index, x: P.x, z: P.z, dirDeg: P.dirDeg, warpX: 0, warpZ: 0, isEvent: 0, desc: CUSTOM_TAG, custom: true });
    this.custom = true;
    this.music = { el: null, nodes: null, playing: false, gain: 0, wanted: false, error: null, retryT: 0 };
  }

  async _load() {
    const game = this.game, P = PARTY_ROCKER, models = game?.models;
    const cls = game?.data?.classByIndex?.get?.(P.classIndex) || game?.data?.classes?.find?.(c => Number(c.index) === P.classIndex);
    if (!models || !cls?.skeleton) { console.warn('[CUSTOM party-rocker] no class body', P.classIndex); return; }
    const parts = (cls.parts || []).map(p => ({ meshKey: p.mesh, tpackKey: p.tpack || null, textures: p.textures || null }));
    const model = await models.loadSkinned({ skelKey: cls.skeleton, parts });
    if (this.disposed || !model) return;
    this.actionSet = {
      custom: CUSTOM_TAG, skel: cls.skeleton,
      clips: [[P.dance.anim, P.dance.timeLength, 0]],
      actions: { STAND: [0, 0] }, states: { idle: 0, idleCombat: 0 },
    };
    this.shape = { custom: CUSTOM_TAG, mesh: parts[1]?.meshKey || null };
    const inst = this._setSkinned(model);
    this._dressUp(inst, model);
    this._unbound = new Set();
    this._measure();
    await this._preload([['idle']]);
    log(`loaded map=${P.map} at=${this.x},${this.z} body=${cls.skeleton} dance=${P.dance.anim} (looping idle state)`);
  }

  _dressUp(inst, model) {
    inst._ensureOwn?.();                                   // per-instance material copies (shared Global materials stay as they are)
    const tex = leopardTexture();
    model.parts.forEach((part, i) => {
      if (!/_equ_(cot|pat)_/.test(part.meshKey || '')) return;      // coat + pants meshes (classes.json parts)
      const mesh = inst.meshes[i];
      const own = inst._own?.get(mesh);
      const mat = own?.mat || (mesh.material = mesh.material.clone());
      mat.map = tex;
      if (mat.color) mat.color.set(0xffffff);
      mat.needsUpdate = true;
    });
    const head = inst.bones.find(b => /(^|[^a-z])head$/i.test(b.name)) || inst.bones.find(b => /head/i.test(b.name) && !/nub/i.test(b.name));
    if (!head) { console.warn('[CUSTOM party-rocker] no head bone'); return; }
    inst.root.updateMatrixWorld(true);
    const rootInv = new THREE.Matrix4().copy(inst.root.matrixWorld).invert();
    const headInRoot = new THREE.Matrix4().multiplyMatrices(rootInv, head.matrixWorld);
    const toHead = headInRoot.clone().invert();
    for (const obj of buildHeadwear()) {
      obj.updateMatrix();
      const m = new THREE.Matrix4().multiplyMatrices(toHead, obj.matrix);
      m.decompose(obj.position, obj.quaternion, obj.scale);
      obj.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
      head.add(obj);
    }
    this.headBone = head.name;
  }

  // ------------------------------------------------------------------------------------------ music
  _startMusic() {
    const a = this.game?.audio, ctx = a?.ctx;
    if (this.music.el || !ctx || !globalThis.document) return;
    const el = document.createElement('audio');
    el.src = MUSIC_URL; el.loop = true; el.preload = 'auto'; el.crossOrigin = 'anonymous';
    const src = ctx.createMediaElementSource(el);
    const gain = ctx.createGain(); gain.gain.value = 0;
    const pan = ctx.createStereoPanner ? ctx.createStereoPanner() : null;
    src.connect(gain);
    if (pan) { gain.connect(pan); pan.connect(a.master || ctx.destination); } else gain.connect(a.master || ctx.destination);
    el.addEventListener('playing', () => { this.music.playing = true; log(`audio source playing src=${P_FILE()} at=${PARTY_ROCKER.x},${PARTY_ROCKER.z} range=${PARTY_ROCKER.music.range}m gain=${this.music.gain.toFixed(3)} t=${el.currentTime.toFixed(2)}s loop=${el.loop}`); });
    el.addEventListener('pause', () => { this.music.playing = false; });
    el.addEventListener('error', () => { this.music.error = el.error?.code || 'error'; console.warn('[CUSTOM party-rocker] music failed', MUSIC_URL, this.music.error); });
    this.music.el = el; this.music.nodes = { src, gain, pan };
  }

  _updateMusic(dt) {
    const a = this.game?.audio, M = this.music, P = PARTY_ROCKER;
    if (!a?.ctx || !this.game?.player || M.error) return;
    const sp = a.spatial ? a.spatial({ x: this.x, z: this.z }, P.music.range) : { gain: distanceGain(Math.hypot(this.x - this.game.player.x, this.z - this.game.player.z), P.music.range), pan: 0 };
    const vol = Number(a.volumes?.music ?? 0.5);
    const g = Math.min(1, P.music.volume * sp.gain * Math.min(1, vol * 2));
    const inRange = sp.gain > 0.001 && vol > 0;
    if (inRange && !M.el) this._startMusic();
    if (!M.el) return;
    M.gain = g;
    const now = a.ctx.currentTime;
    M.nodes.gain.gain.setTargetAtTime(g, now, 0.08);
    if (M.nodes.pan) M.nodes.pan.pan.setTargetAtTime(sp.pan, now, 0.08);
    if (inRange && M.el.paused) {
      M.retryT -= dt;
      if (M.retryT <= 0 && a.ctx.state === 'running') { M.retryT = 1; M.el.play().catch(() => {}); }   // autoplay waits for the first user gesture
    } else if (!inRange && !M.el.paused) M.el.pause();
  }

  update(dt) {
    super.update(dt);
    try { this._updateMusic(dt); } catch (err) { this.music.error = String(err); console.warn('[CUSTOM party-rocker] music', err); }
  }

  dispose() {
    const M = this.music;
    if (M?.el) { try { M.el.pause(); M.el.removeAttribute('src'); M.el.load(); } catch { /* ignore */ } }
    for (const n of Object.values(M?.nodes || {})) { try { n?.disconnect(); } catch { /* ignore */ } }
    if (M) { M.el = null; M.nodes = null; M.playing = false; }
    super.dispose();
  }
}
function P_FILE() { return `src/custom/party-rocker/${PARTY_ROCKER.music.file}`; }
