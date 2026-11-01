// One live preview per Command Center, with selection-scoped model/texture caches.
import * as THREE from 'three';
import { ItemPreview } from '../itembuilder/preview.js';
import { ModelCache } from '../../engine/models.js';
import { TextureCache } from '../../engine/textures.js';
import { Animator } from '../../engine/animator.js';
import { actionSetSpec } from '../../actors/actor.js';

export class GMModelPreview extends ItemPreview {
  constructor(game, kind, index) {
    super(Object.create(game), game.items?.db);
    this.kind = kind; this.itemIndex = Number(index); this.mode = 'item';
    this.classIndex = Number(game.save?.classIndex) || 0;
  }
  mount(el, w, h) {
    super.mount(el, w, h);
    this.textures = new TextureCache(this.renderer);
    this.game.models = new ModelCache(this.textures);
  }
  _build() {
    const work = this._pendingBuild = super._build();
    const pending = this._pendingBuilds ||= new Set();
    pending.add(work);
    work.then(() => pending.delete(work), () => pending.delete(work));
    return work;
  }
  async _buildItem(def) {
    if (this.kind === 'item') return super._buildItem(def);
    const db = this.game.data?.[this.kind === 'monster' ? 'monsters' : 'npcs'];
    const row = db?.[this.kind === 'monster' ? 'monsters' : 'npcs']?.[this.itemIndex];
    const shape = db?.shapes?.[row?.shape], set = db?.actionSets?.[row?.act];
    if (!shape?.mesh) return { status: 'This entry has no authored model.' };
    const opts = { tpackKey: shape.tpack || null, textures: shape.textures || null };
    const skinned = !!set?.skel && !row.static;
    const model = skinned
      ? await this.game.models.loadSkinned({ skelKey: set.skel, parts: [{ meshKey: shape.mesh, ...opts }] })
      : await this.game.models.loadStatic(shape.mesh, opts);
    if (!model || model.empty || model.bbox.isEmpty()) return { status: 'No visible geometry in this authored model.' };
    const instance = skinned ? model.instantiate() : null;
    const object = instance?.root || model.instantiate();
    object.traverse(node => { if (node.isSkinnedMesh) node.frustumCulled = false; });
    const scale = Number(row.scale ?? shape.scale ?? 1) || 1;
    object.scale.setScalar(scale);
    const animator = instance ? new Animator(instance) : null;
    const spec = actionSetSpec(set, new Set(set?.unboundClips || []), 'idle');
    const clip = animator && spec ? await this.game.models.loadClip(spec.key, model, { duration: spec.duration }) : null;
    if (clip) animator.play(clip, { loop: true, fade: 0 });
    return { kind: 'object', object, instance, extraAnimators: animator ? [animator] : [],
      box: model.bbox.clone().applyMatrix4(new THREE.Matrix4().makeScale(scale, scale, scale)),
      status: clip ? 'Animated idle · drag to rotate · wheel to zoom' : 'Authored static pose · drag to rotate · wheel to zoom' };
  }
  unmount() {
    const models = this.game.models, textures = this.textures, pending = [...new Set([...(this._pendingBuilds || []), this._pendingBuild].filter(Boolean))];
    super.unmount();
    // Wait for cancelled builds before freeing cache resources; never dispose gameplay caches.
    if (!textures) return;
    this.textures = null;
    void (async () => {
      await Promise.allSettled(pending);
      const loaded = await Promise.allSettled([...models._static.values(), ...models._skinned.values()]);
      const geometry = new Set(models._geoms.values()), materials = new Set(models._materials.values());
      for (const result of loaded) for (const part of result.value?.parts || []) {
        if (part.geometry) geometry.add(part.geometry);
        if (part.material) materials.add(part.material);
      }
      const ownedTextures = new Set([...textures._textures.values(), textures.placeholder]);
      for (const material of materials) for (const value of Object.values(material)) if (value?.isTexture) ownedTextures.add(value);
      for (const resource of [...geometry, ...materials, ...ownedTextures]) resource.dispose();
      for (const value of Object.values(models)) if (value instanceof Map) value.clear();
      textures._cache.clear(); textures._textures.clear();
    })();
  }
}

const controllers = new WeakMap();
export function embeddedModelPreview(ctx, parent, kind, index) {
  let controller = controllers.get(ctx.panel);
  if (!controller) {
    controller = { selections: new Map(), active: null, preview: null };
    const sync = () => {
      const s = ctx.panel.isOpen && [...controller.selections.values()].find(s => s.host.isConnected && s.host.getClientRects().length);
      if (s !== controller.active) { controller.preview?.unmount(); controller.preview = null; controller.active = s; }
      if (!s) return;
      if (controller.preview || s.failed) return;
      const preview = controller.preview = new GMModelPreview(ctx.game, s.kind, s.index);
      preview.onStatus = text => { s.status.textContent = text || 'Drag to rotate · wheel to zoom'; };
      try { preview.mount(s.host, 300, 190); preview.refresh(); }
      catch (error) { preview.unmount(); controller.preview = null; s.failed = true; s.status.textContent = `Preview unavailable: ${error.message}`; }
    };
    controller.sync = sync;
    controller.observer = new MutationObserver(sync);
    // Observe only this window, including tab/close visibility and detached selections.
    controller.observer.observe(ctx.panel.win.el, { attributes: true, attributeFilter: ['style', 'class'], childList: true, subtree: true });
    ctx.panel.win.on('dispose', () => {
      controller.observer.disconnect(); controller.preview?.unmount(); controller.preview = null;
      controller.selections.clear(); controllers.delete(ctx.panel);
    });
    controllers.set(ctx.panel, controller);
  }
  controller.preview?.unmount(); controller.preview = null;
  const host = document.createElement('div'), status = document.createElement('div');
  host.className = 'gm-model-preview'; host.setAttribute('aria-label', `${kind} 3D preview`);
  Object.assign(host.style, { position: 'relative', width: '300px', height: '190px', background: 'rgba(0,0,0,.35)', margin: '6px 0' });
  status.className = 'dim'; status.textContent = 'Loading authored model…';
  parent.append(host, status);
  controller.selections.set(kind, { host, status, kind, index });
  controller.sync();
}
