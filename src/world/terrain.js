// Terrain renderer for one .map (docs/formats/map.md), in the FILE frame under game.worldRoot (mirror root).
//
// Ground = the tile-atlas scheme: every cell samples one 64 px transition tile (slot from the 4 corner types +
// rotation + random variant, map.js buildTileLookup) out of maptex_first/second.dds. The tiles are uploaded as a
// DataArrayTexture (one layer per slot, mipmapped, no atlas bleeding) and a per-cell lookup texture; the terrain
// material is a MeshLambertMaterial whose map stage is replaced (onBeforeCompile) by the tile lookup, so it keeps
// three's fog, lights and shadow maps. diffuse = tile x baked vertex colour; lit = diffuse x (ambient + sun N.L)
// (environment.js sets light intensities to PI so three's Lambert BRDF (1/PI) reproduces the D3D9 modulate).
// Decals ("tiles") are drawn on top, grouped per (record, 64-cell region); s_empty holes are not drawn at all.
//
// Geometry is FILE frame: vertex (col,row,h) -> (x=col, y=h, z=row), raw normals. Triangles use the D3D winding
// (a,d,b),(a,c,d) of the map.md split (a=(c,r) b=(c+1,r) c=(c,r+1) d=(c+1,r+1)): under the mirrored worldRoot
// three flips the front face, so FrontSide shows the top side. Heights: sampleHeight() (triangle-exact).
import * as THREE from 'three';
import { buildTileLookup, buildTileArrayData, sampleHeight, tileUV, CELL_HOLE } from '../formats/map.js';
import { loadRGBA, loadTexture, maptileCandidates } from './texload.js';
import { applyShade } from './shade.js';

export const TERRAIN_CHUNK = 32;   // cells per terrain chunk side (culling unit)
export const DECAL_REGION = 64;    // cells per decal group side

// ------------------------------------------------------------------------------------------ material
// data/binary/geometry.fx MapLight (vsMapMainLight): COLOR0 = vertex.color x (g_ambient + sun x N.L x shade), saturated by
// D3D9, x the tile (Texture[0] modulate) = tile x min(vertexColour x light, 1). Exported for the pixel parity test
// (tools/test-matfx-shader-parity.mjs via tools/matfx-pixel-probe.mjs).
export function makeTerrainMaterial(tileArray, tileLUT, mapW, mapH) {
  const mat = new THREE.MeshLambertMaterial({ color: 0xffffff, vertexColors: true });
  mat.name = 'terrain';
  if (!tileArray) return mat; // no atlas: vertex colour only (cc_indun, ...)
  // the lighting clamp (shade.js) is tile x min(vertexColour x light, 1): the reference is the bare tile colour
  mat.defines = { DK_TILE_CLAMP: '' };
  const uniforms = {
    dkTileArray: { value: tileArray },
    dkTileLUT: { value: tileLUT },
    dkMapSize: { value: new THREE.Vector2(mapW, mapH) },
  };
  mat.userData.uniforms = uniforms;
  mat.onBeforeCompile = (shader) => {
    Object.assign(shader.uniforms, uniforms);
    shader.vertexShader = shader.vertexShader
      .replace('#include <common>', '#include <common>\nattribute vec2 dkCell;\nvarying vec2 vDkCell;')
      .replace('#include <begin_vertex>', '#include <begin_vertex>\nvDkCell = dkCell;');
    shader.fragmentShader = shader.fragmentShader
      .replace('#include <common>', `#include <common>
precision highp sampler2DArray;
uniform sampler2DArray dkTileArray;
uniform sampler2D dkTileLUT;
uniform vec2 dkMapSize;
varying vec2 vDkCell;
vec3 dkTileColor = vec3(1.0);
// = map.js tileUV(s, t, r): upright image seen from above (north = +row), r counter-clockwise quarter turns
vec2 dkTileUV(vec2 st, float r) {
  vec2 uv = st;
  if (r > 2.5) uv = vec2(1.0 - st.y, st.x);
  else if (r > 1.5) uv = vec2(1.0 - st.x, 1.0 - st.y);
  else if (r > 0.5) uv = vec2(st.y, 1.0 - st.x);
  return vec2(uv.x, 1.0 - uv.y);
}`)
      .replace('#include <map_fragment>', `{
  vec2 dkc = clamp(floor(vDkCell), vec2(0.0), dkMapSize - 1.0);
  vec2 dkst = clamp(vDkCell - dkc, 0.0, 1.0);
  vec4 dkt = floor(texelFetch(dkTileLUT, ivec2(dkc), 0) * 255.0 + 0.5); // r=slot g=rot b=variant a=flags
  if (mod(dkt.a, 2.0) > 0.5) discard;                                   // CELL_HOLE
  vec3 dkBase = textureGrad(dkTileArray, vec3(dkTileUV(dkst, dkt.g), dkt.r), dFdx(vDkCell), dFdy(vDkCell)).rgb;
  diffuseColor.rgb *= dkBase;
  dkTileColor = dkBase;
}`);
  };
  mat.customProgramCacheKey = () => 'dk-terrain-v2';
  return mat;
}

/** Ground decal: same geometry.fx MapLight rule as the tiles, decal x min(vertexColour x light, 1). Not yet shade-patched. */
export function makeDecalMaterial(tex) {
  const mat = new THREE.MeshLambertMaterial({
    map: tex, vertexColors: true, polygonOffset: true, polygonOffsetFactor: -1, polygonOffsetUnits: -4,
  });
  mat.defines = { DK_TILE_CLAMP: '' };
  mat.onBeforeCompile = (shader) => {
    shader.fragmentShader = shader.fragmentShader
      .replace('#include <common>', '#include <common>\nvec3 dkTileColor = vec3(1.0);')
      .replace('#include <map_fragment>', '#include <map_fragment>\ndkTileColor = diffuseColor.rgb;');
  };
  mat.customProgramCacheKey = () => 'dk-decal-v1';
  return mat;
}

// ------------------------------------------------------------------------------------------ geometry
/** One terrain chunk [x0,x0+cols) x [z0,z0+rows) in the FILE frame. Returns null when every cell is a hole. */
export function buildChunkGeometry(map, x0, z0, cols, rows) {
  const X = map.vertsX, W = map.width;
  const vx = cols + 1, vz = rows + 1, V = vx * vz;
  let nTri = 0;
  for (let r = 0; r < rows; r++) for (let c = 0; c < cols; c++) if (!map.holes[(z0 + r) * W + x0 + c]) nTri += 2;
  if (!nTri) return null;
  const pos = new Float32Array(V * 3), nrm = new Float32Array(V * 3), cell = new Float32Array(V * 2), col = new Uint8Array(V * 3);
  for (let r = 0; r < vz; r++) {
    for (let c = 0; c < vx; c++) {
      const s = (z0 + r) * X + (x0 + c), d = r * vx + c;
      pos[d * 3] = x0 + c; pos[d * 3 + 1] = map.heights[s]; pos[d * 3 + 2] = z0 + r;
      nrm[d * 3] = map.normals[s * 3]; nrm[d * 3 + 1] = map.normals[s * 3 + 1]; nrm[d * 3 + 2] = map.normals[s * 3 + 2];
      cell[d * 2] = x0 + c; cell[d * 2 + 1] = z0 + r;
      col[d * 3] = map.colors[s * 4]; col[d * 3 + 1] = map.colors[s * 4 + 1]; col[d * 3 + 2] = map.colors[s * 4 + 2];
    }
  }
  const idx = new Uint16Array(nTri * 3);
  let k = 0;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (map.holes[(z0 + r) * W + x0 + c]) continue;
      const a = r * vx + c, b = a + 1, cc = a + vx, d = cc + 1;
      idx[k++] = a; idx[k++] = d; idx[k++] = b;   // D3D (clockwise) winding, see header
      idx[k++] = a; idx[k++] = cc; idx[k++] = d;
    }
  }
  const g = new THREE.BufferGeometry();
  g.setAttribute('position', new THREE.BufferAttribute(pos, 3));
  g.setAttribute('normal', new THREE.BufferAttribute(nrm, 3));
  g.setAttribute('dkCell', new THREE.BufferAttribute(cell, 2));
  g.setAttribute('color', new THREE.BufferAttribute(col, 3, true));
  g.setIndex(new THREE.BufferAttribute(idx, 1));
  g.computeBoundingBox();
  g.computeBoundingSphere();
  return g;
}

/**
 * Decal geometry for one record, split per DECAL_REGION region of the anchor cell. FILE frame, D3D winding,
 * UV = tileUV(s, t, rotation & 3) (map.md). Returns Map<regionKey, BufferGeometry>.
 */
function buildDecalGeometries(map, d) {
  const W = map.width, H = map.height, X = map.vertsX;
  const buckets = new Map();
  for (let j = 0; j < d.count; j++) {
    const S = d.sizes[j]; if (!S) continue;
    const c0 = d.cells[j] % W, r0 = Math.floor(d.cells[j] / W);
    if (r0 >= H) continue;
    const key = Math.floor(r0 / DECAL_REGION) * 64 + Math.floor(c0 / DECAL_REGION);
    let b = buckets.get(key);
    if (!b) buckets.set(key, (b = []));
    b.push(j);
  }
  const out = new Map();
  for (const [key, list] of buckets) {
    let nv = 0, nq = 0;
    for (const j of list) {
      const S = d.sizes[j], c0 = d.cells[j] % W, r0 = Math.floor(d.cells[j] / W);
      nv += (S + 1) * (S + 1); nq += Math.min(S, W - c0) * Math.min(S, H - r0);
    }
    if (!nq) continue;
    const pos = new Float32Array(nv * 3), nrm = new Float32Array(nv * 3), uv = new Float32Array(nv * 2), col = new Uint8Array(nv * 3);
    const idx = nv > 65535 ? new Uint32Array(nq * 6) : new Uint16Array(nq * 6);
    let v = 0, k = 0;
    for (const j of list) {
      const S = d.sizes[j], c0 = d.cells[j] % W, r0 = Math.floor(d.cells[j] / W), rot = d.rotations[j] & 3, base = v;
      for (let y = 0; y <= S; y++) {
        for (let x = 0; x <= S; x++) {
          const cc = Math.min(c0 + x, W), rr = Math.min(r0 + y, H), s = rr * X + cc;
          pos[v * 3] = c0 + x; pos[v * 3 + 1] = map.heights[s]; pos[v * 3 + 2] = r0 + y;
          nrm[v * 3] = map.normals[s * 3]; nrm[v * 3 + 1] = map.normals[s * 3 + 1]; nrm[v * 3 + 2] = map.normals[s * 3 + 2];
          const [u, vv] = tileUV(x / S, y / S, rot);
          uv[v * 2] = u; uv[v * 2 + 1] = vv;
          col[v * 3] = map.colors[s * 4]; col[v * 3 + 1] = map.colors[s * 4 + 1]; col[v * 3 + 2] = map.colors[s * 4 + 2];
          v++;
        }
      }
      for (let y = 0; y < S && r0 + y < H; y++) {
        for (let x = 0; x < S && c0 + x < W; x++) {
          const a = base + y * (S + 1) + x, b = a + 1, c = a + S + 1, dd = c + 1;
          idx[k++] = a; idx[k++] = dd; idx[k++] = b;
          idx[k++] = a; idx[k++] = c; idx[k++] = dd;
        }
      }
    }
    const g = new THREE.BufferGeometry();
    g.setAttribute('position', new THREE.BufferAttribute(pos, 3));
    g.setAttribute('normal', new THREE.BufferAttribute(nrm, 3));
    g.setAttribute('uv', new THREE.BufferAttribute(uv, 2));
    g.setAttribute('color', new THREE.BufferAttribute(col, 3, true));
    g.setIndex(new THREE.BufferAttribute(k === idx.length ? idx : idx.slice(0, k), 1));
    g.computeBoundingBox();
    g.computeBoundingSphere();
    out.set(key, g);
  }
  return out;
}

// ------------------------------------------------------------------------------------------ Terrain
export class Terrain {
  /**
   * @param {{map:object, game?:object, root:THREE.Object3D}} opts  map = parseMap() result
   */
  constructor({ map, game = null, root }) {
    this.map = map;
    this.game = game;
    this.width = map.width;
    this.height = map.height;
    this.group = new THREE.Group();
    this.group.name = 'terrain';
    root.add(this.group);
    this.chunks = [];      // {mesh, cx, cz, minX, maxX, minZ, maxZ}
    this.decals = [];      // {mesh, minX, maxX, minZ, maxZ}
    this.material = null;
    this._textures = [];
    this.stats = { chunks: 0, decalMeshes: 0, decalRecords: 0, missingDecals: [], atlas: false };
  }

  /** Triangle-exact terrain height at FILE (x, z) (clamped to the map). */
  heightAt(x, z) { return sampleHeight(this.map, x, z); }

  /** Update shared border vertices in existing native chunks; no resource reload. */
  updateHeightVertices(vertices) {
    const buckets = new Map(), W = this.map.width, H = this.map.height;
    for (const source of vertices) {
      const x = source % this.map.vertsX, z = Math.floor(source / this.map.vertsX);
      const xs = new Set([Math.floor(Math.min(W-1,x)/32),Math.floor(Math.max(0,x-1)/32)]), zs = new Set([Math.floor(Math.min(H-1,z)/32),Math.floor(Math.max(0,z-1)/32)]);
      for(const cz of zs)for(const cx of xs){const key=`${cx},${cz}`;let list=buckets.get(key);if(!list)buckets.set(key,list=[]);list.push(source);}
    }
    let count = 0;
    for (const c of this.chunks) {
      const sources = buckets.get(`${c.minX/32},${c.minZ/32}`);
      if (!sources) continue;
      const geometry = c.mesh.geometry, position = geometry.getAttribute('position'), normal = geometry.getAttribute('normal');
      const stride = c.maxX - c.minX + 1;
      let touched = false;
      for (const source of sources) {
        const x = source % this.map.vertsX, z = Math.floor(source / this.map.vertsX);
        if (x < c.minX || x > c.maxX || z < c.minZ || z > c.maxZ) continue;
        const target = (z - c.minZ) * stride + x - c.minX;
        position.array[target * 3 + 1] = this.map.heights[source];
        normal.array.set(this.map.normals.subarray(source * 3, source * 3 + 3), target * 3);
        touched = true;
      }
      if (touched) { position.needsUpdate = normal.needsUpdate = true; geometry.computeBoundingBox(); geometry.computeBoundingSphere(); count++; }
    }
    return count;
  }

  /** Loads the atlases, builds the lookup textures, the chunk meshes and the decals. */
  async build(onProgress = () => {}) {
    const map = this.map;
    onProgress(0, 'Ground tiles');
    const atlases = await Promise.all(map.atlasPaths.map((p, i) => loadRGBA([p, map.atlasPathsAlt[i]])));
    let tileArray = null, tileLUT = null;
    if (atlases.some(Boolean)) {
      const arr = buildTileArrayData(atlases);
      tileArray = new THREE.DataArrayTexture(arr.data, arr.width, arr.height, arr.depth);
      Object.assign(tileArray, {
        format: THREE.RGBAFormat, type: THREE.UnsignedByteType, colorSpace: THREE.NoColorSpace, flipY: false,
        generateMipmaps: true, minFilter: THREE.LinearMipmapLinearFilter, magFilter: THREE.LinearFilter,
        wrapS: THREE.ClampToEdgeWrapping, wrapT: THREE.ClampToEdgeWrapping, anisotropy: 4,
      });
      tileArray.needsUpdate = true;
      const lut = buildTileLookup(map);
      tileLUT = new THREE.DataTexture(lut.data, lut.width, lut.height, THREE.RGBAFormat, THREE.UnsignedByteType);
      Object.assign(tileLUT, { minFilter: THREE.NearestFilter, magFilter: THREE.NearestFilter, generateMipmaps: false, flipY: false, colorSpace: THREE.NoColorSpace });
      tileLUT.needsUpdate = true;
      this._textures.push(tileArray, tileLUT);
      this.stats.atlas = true;
    } else {
      console.warn('[world] terrain atlases missing, vertex-colour fallback:', map.atlasPaths);
    }
    this.material = applyShade(makeTerrainMaterial(tileArray, tileLUT, map.width, map.height));

    // chunks
    const N = TERRAIN_CHUNK;
    for (let z0 = 0; z0 < map.height; z0 += N) {
      for (let x0 = 0; x0 < map.width; x0 += N) {
        const cols = Math.min(N, map.width - x0), rows = Math.min(N, map.height - z0);
        const g = buildChunkGeometry(map, x0, z0, cols, rows);
        if (!g) continue;
        const mesh = new THREE.Mesh(g, this.material);
        mesh.name = `terrain ${x0},${z0}`;
        mesh.receiveShadow = true;
        mesh.matrixAutoUpdate = false;
        this.group.add(mesh);
        this.chunks.push({ mesh, minX: x0, maxX: x0 + cols, minZ: z0, maxZ: z0 + rows });
      }
    }
    this.stats.chunks = this.chunks.length;
    onProgress(0.5, 'Ground decals');
    await this._buildDecals();
    onProgress(1, 'Ground ready');
  }

  async _buildDecals() {
    const map = this.map;
    const jobs = [];
    map.decals.forEach((d, record) => {
      // Empty authored records have no geometry. Do not fetch their old texture
      // names or build the cross-map fallback index during map startup.
      if (d.isNone || d.isHole || !d.path || d.count === 0 || !d.sizes.some(size => size > 0)) return;
      jobs.push((async () => {
        const first = [d.path, d.pathAlt].filter(Boolean);
        let tex = await loadTexture(this.game, first, { repeat: false });
        if (!tex) {
          // same basename in another texture/maptile/<folder>/ (dds.md: 710 records need this)
          const more = (await maptileCandidates(d.path, d.pathAlt)).filter(k => !first.includes(k));
          if (more.length) tex = await loadTexture(this.game, more, { repeat: false });
        }
        if (!tex) { this.stats.missingDecals.push(d.name); return; }
        const geos = buildDecalGeometries(map, d);
        if (!geos.size) return;
        const mat = applyShade(makeDecalMaterial(tex));
        mat.name = `decal ${d.name}`;
        this._decalMaterials = this._decalMaterials || [];
        this._decalMaterials.push(mat);
        this.stats.decalRecords++;
        for (const [key, g] of geos) {
          const mesh = new THREE.Mesh(g, mat);
          mesh.name = `decal ${d.name} r${key}`;
          mesh.renderOrder = 1 + record;
          mesh.receiveShadow = true;
          mesh.matrixAutoUpdate = false;
          this.group.add(mesh);
          const bb = g.boundingBox;
          this.decals.push({ mesh, minX: bb.min.x, maxX: bb.max.x, minZ: bb.min.z, maxZ: bb.max.z });
          this.stats.decalMeshes++;
        }
      })());
    });
    await Promise.all(jobs);
    if (this.stats.missingDecals.length) console.warn('[world] missing decal textures:', [...new Set(this.stats.missingDecals)]);
  }

  /** Distance culling (FILE frame camera position). */
  update(camX, camZ, viewDist) {
    const cull = (list) => {
      for (const c of list) {
        const dx = camX < c.minX ? c.minX - camX : camX > c.maxX ? camX - c.maxX : 0;
        const dz = camZ < c.minZ ? c.minZ - camZ : camZ > c.maxZ ? camZ - c.maxZ : 0;
        c.mesh.visible = dx * dx + dz * dz <= viewDist * viewDist;
      }
    };
    cull(this.chunks);
    cull(this.decals);
  }

  dispose() {
    for (const c of this.chunks) c.mesh.geometry.dispose();
    for (const c of this.decals) c.mesh.geometry.dispose();
    // decal textures belong to the TextureCache: free only their GPU copies (three re-uploads them if reused)
    for (const m of this._decalMaterials || []) { m.map?.dispose(); m.dispose(); }
    this.material?.dispose();
    for (const t of this._textures) t.dispose();
    this.group.removeFromParent();
    this.chunks = []; this.decals = [];
  }
}

export { CELL_HOLE };
