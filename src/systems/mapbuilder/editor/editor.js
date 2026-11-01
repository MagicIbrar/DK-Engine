import { readRenderTargetPixels } from '../../../engine/pixel-pack-readback.js';
// Map Builder editor core: owns the live document, the render layers (EditorView terrain/water/env, Overlay,
// ObjectsLayer, MarkersLayer, ObjectLibrary), the fly camera, tool/pointer dispatch, undo history and
// new/open/save/export/import/play. tools/mapbuilder.html constructs one Editor and drives its update()/render().
import * as THREE from 'three';
import { TransformControls } from 'three/addons/controls/TransformControls.js';
import { MapDoc, newId, normFolder, SIZES } from '../format.js';
import * as store from '../store.js';
import { mapDataPaths } from '../../../formats/spawn.js';
import { fetchBuffer, tryFetchBuffer } from '../../../engine/assets.js';
import { fileToThree } from '../../../engine/space.js';
import { EditorView } from './view.js';
import { Overlay } from './overlay.js';
import { ObjectsLayer } from './objects3d.js';
import { MarkersLayer } from './markers.js';
import { ObjectLibrary } from './library.js';
import { Brushes } from './brushes.js';
import { History } from './history.js';
import {packDkmap} from '../pack.js';
import {launchSandboxPreview} from './preview-launch.js';

const RADIUS_TOOLS = new Set(['raise', 'lower', 'smooth', 'flatten', 'noise', 'vcolor', 'type', 'variant', 'hole', 'water', 'collision']);
const CONTINUOUS_TOOLS = new Set(['raise', 'lower', 'smooth', 'flatten', 'vcolor']);

export const TOOLS = {
  select: { group: 'select' },
  raise: { group: 'terrain' }, lower: { group: 'terrain' }, smooth: { group: 'terrain' }, flatten: { group: 'terrain' }, noise: { group: 'terrain' },
  vcolor: { group: 'terrain' },
  type: { group: 'tiles' }, variant: { group: 'tiles' }, decal: { group: 'tiles' }, hole: { group: 'tiles' },
  water: { group: 'water' },
  collision: { group: 'collision' },
  objects: { group: 'objects' },
  spawns: { group: 'spawns' }, npcs: { group: 'npcs' }, portals: { group: 'portals' },
};

export class Editor {
  constructor(game) {
    this.game = game;
    this.doc = MapDoc.blank({ size: 128, name: 'New Map' });
    this.view = new EditorView(this);
    this.overlay = new Overlay(this);
    this.objects = new ObjectsLayer(this);
    this.markers = new MarkersLayer(this);
    this.library = new ObjectLibrary(this);
    this.brushes = new Brushes(this);
    this.history = new History(() => { this.dirty=true;this.emit('history'); });
    this.library.load().catch(err => console.warn('[mapbuilder] library load failed', err));

    this.currentId = null;
    this.dirty = false;
    this.tool = 'select';
    this.toolOpts = {
      radius: 6, strength: 3, falloff: 'smooth', min: '', max: '', color: [90, 140, 70], type: 0, erase: false,
      defName: 'water01.txt', absolute: '', offset: 0.4, attr: 1, decal: null, decalSize: 2, decalRot: 0,
    };
    this.placing = false;              // "Add" armed for objects/spawns/npcs/portals
    this.libraryPick = null;           // selected object-library name for placement
    this.spawnPick = null;             // { monsterIndex, name }
    this.npcPick = null;               // { npcIndex, name }
    this.snap = 0;                     // grid snap size (0 = off)
    this.gridOn = false;
    this.collisionOn = false;

    this.selection = { kind: null, ids: new Set() };
    this._listeners = new Map();

    // camera (three-space, outside worldRoot - fileToThree converts; same fly scheme as tools/world.html)
    this.cam = { pos: new THREE.Vector3(64, 40, 64), yaw: Math.PI * 0.8, pitch: -0.5, speed: 24 };
    this.navigation='freefly';this.eyeHeight=1.8;
    this.frameCamera(); // the default above is FILE-shaped, not a real THREE-space point - replace it right away
    this.keys = new Set();
    this._drag = null;                 // right-drag look
    this._stroking = false;
    this._lastGround = null;
    this._portalDraft = null;

    // Selection pivot stays in FILE space alongside the placed objects.
    this._selectionPivot = new THREE.Group();this.objects.root.add(this._selectionPivot);
    // transform gizmo
    this.transform = new TransformControls(game.camera, game.renderer.domElement);
    this.transform.size = 0.9;
    this.transformHelper = this.transform.getHelper();
    // NOT under view.root/worldRoot: TransformControlsRoot positions itself from the target's WORLD matrix each
    // frame (worldPosition.decompose), so it must live under an identity-transform parent, not the mirrored root.
    game.scene.add(this.transformHelper);
    this.transform.addEventListener('dragging-changed', (e) => { this._gizmoDragging = e.value; this._onGizmoDragToggle(e.value); });
    this.transform.addEventListener('objectChange', () => this._onGizmoChange());
    this.transform.enabled = false;
    this.transformHelper.visible = false;

    this.ready = this._buildAll();
  }

  on(ev, fn) { (this._listeners.get(ev) || this._listeners.set(ev, new Set()).get(ev)).add(fn); return () => this._listeners.get(ev)?.delete(fn); }
  emit(ev, ...args) { for (const fn of this._listeners.get(ev) || []) { try { fn(...args); } catch (err) { console.error(`[mapbuilder] listener ${ev}`, err); } } }

  get dirty() { return !!this._dirty; }
  set dirty(value) { this._dirty=!!value;if(value)this._editRevision=(this._editRevision||0)+1; }

  // ---------------------------------------------------------------------------------------- map lifecycle
  async _buildAll(onProgress) {
    this.history.clear();
    this.selection = { kind: null, ids: new Set() };
    this.transform.detach(); this.transformHelper.visible = false;
    await this.view.build(onProgress);
    this.overlay.updateStart(); this.overlay.updatePortals(); this.overlay.rebuildCollision();
    await this.objects.rebuildAll();
    this.markers.rebuildAll();
    this.dirty = false;
    this.emit('map');
  }

  /** Eye above/outside a corner of the map, looking at its centre (same yaw/pitch convention as update()'s dir). */
  frameCamera() {
    this.navigation='freefly';
    const s = this.doc.width, cx = s / 2, cz = s / 2;
    const gy = this.doc.heightAt(cx, cz);
    const e = fileToThree(cx - s * 0.62, gy + s * 0.55, cz - s * 0.62);
    const t = fileToThree(cx, gy, cz);
    const d = t.clone().sub(e);
    this.cam.pos.copy(e);
    this.cam.yaw = Math.atan2(-d.x, -d.z);
    this.cam.pitch = Math.atan2(d.y, Math.hypot(d.x, d.z));
  }

  setNavigation(mode) {
    if(!['freefly','firstperson'].includes(mode))return;
    this.cancelInput();this.navigation=mode;
    if(mode==='firstperson'){
      const start=this.doc.meta.start,x=Math.max(0,Math.min(this.doc.width-.001,start.x)),z=Math.max(0,Math.min(this.doc.height-.001,start.z));
      fileToThree(x,this.doc.heightAt(x,z)+this.eyeHeight,z,this.cam.pos);this.cam.pitch=-.12;
    }
    this.emit('navigation',mode);
  }
  moveNavigation({forward=0,right=0,up=0,lookX=0,lookY=0,boost=false}={},dt=0){
    dt=Math.max(0,Math.min(.05,Number(dt)||0));this.cam.yaw-=lookX*1.8*dt;this.cam.pitch=Math.max(-1.5,Math.min(1.5,this.cam.pitch-lookY*1.5*dt));
    const len=Math.max(1,Math.hypot(forward,right,up)),sp=(this.navigation==='firstperson'?Math.min(this.cam.speed,8):this.cam.speed)*(boost?3.2:1)*dt/len,yaw=this.cam.yaw;
    this.cam.pos.x+=(-Math.sin(yaw)*forward+Math.cos(yaw)*right)*sp;this.cam.pos.z+=(-Math.cos(yaw)*forward-Math.sin(yaw)*right)*sp;
    if(this.navigation==='firstperson'){
      this.cam.pos.x=Math.max(0,Math.min(this.doc.width-.001,this.cam.pos.x));this.cam.pos.z=-Math.max(0,Math.min(this.doc.height-.001,-this.cam.pos.z));this.cam.pos.y=this.doc.heightAt(this.cam.pos.x,-this.cam.pos.z)+this.eyeHeight;
    }else this.cam.pos.y+=up*sp;
  }
  syncCamera(){const g=this.game,yaw=this.cam.yaw;g.camera.position.copy(this.cam.pos);const dir=new THREE.Vector3(-Math.sin(yaw)*Math.cos(this.cam.pitch),Math.sin(this.cam.pitch),-Math.cos(yaw)*Math.cos(this.cam.pitch));g.camera.lookAt(this.cam.pos.clone().add(dir));g.camera.updateMatrixWorld();}
  cancelInput(){this.keys?.clear();this._ctrl=false;this._drag=null;this._portalDraft=null;if(this._gizmoBefore){this._onGizmoDragToggle(false);this.transform.dragging=false;this._gizmoDragging=false;}if(this._stroking){this.brushes.endStroke();this._stroking=false;}if(this._dragMarker){this._commitMarkerDrag(this._dragMarker);this._dragMarker=null;}this.overlay?.setCursor?.(null);}

  async newMap(opts) {
    if(this.originalLive?.active)throw Error('Finish or cancel the original shared session first.');
    this.doc = MapDoc.blank(opts);
    this.currentId = null;
    await this._buildAll();
    this.frameCamera();
    this.dirty=true;
    this.emit('doclist');
  }

  /** Start a new custom map from one of the shipped client maps (its terrain/objects become the starting point). */
  async newFromOriginal(mapIndex, name) {
    if(this.originalLive?.active)throw Error('Finish or cancel the original shared session first.');
    const row = this.game.data?.mapByIndex?.(mapIndex);
    if (!row) throw new Error(`unknown base map ${mapIndex}`);
    const paths = mapDataPaths(row);
    const [mapBuf, molBuf, macBuf] = await Promise.all([
      fetchBuffer(paths.map), tryFetchBuffer(paths.mol).catch(() => null), tryFetchBuffer(paths.mac).catch(() => null),
    ]);
    const doc = MapDoc.fromFiles({ map: mapBuf, mol: molBuf, mac: macBuf });
    doc.meta.name = String(name || `${String(row.Name || 'Map').trim()} (custom)`).slice(0, 60);
    doc.meta.basedOn = Number(mapIndex);
    doc.meta.env.light = String(row.EnvironmentFile || doc.meta.env.light);
    doc.meta.env.envMap = String(row.EnvironmentMap || doc.meta.env.envMap);
    doc.meta.env.clipFar = Number(row.Clip_Far) || doc.meta.env.clipFar;
    doc.meta.env.bgmMap = Number(mapIndex);
    this.doc = doc;
    this.currentId = null;
    await this._buildAll();
    this.frameCamera();
    this.dirty=true;
    this.emit('doclist');
  }

  async openMap(id, onProgress) {
    if(this.originalLive?.active)throw Error('Finish or cancel the original shared session first.');
    const rec = await store.loadMap(id);
    if (!rec) throw new Error('map not found');
    this.doc = MapDoc.fromFiles({ map: rec.map, mol: rec.mol, mac: rec.mac, meta: rec.meta });
    this.currentId = id;
    await this._buildAll(onProgress);
    this.frameCamera();
  }

  save({asCopy=false}={}) {
    if(this.originalLive?.active)return Promise.reject(Error('Use Save original overlay or Cancel shared edits.'));
    if(this._saveTask)return this._saveMode===asCopy?this._saveTask:Promise.reject(new Error('Wait for the current map save before Save As.'));
    this._saveMode=asCopy;
    const task=this._saveNow({asCopy});this._saveTask=task;
    void task.finally(()=>{if(this._saveTask===task)this._saveTask=null;}).catch(()=>{});
    return task;
  }

  async _saveNow({asCopy}) {
    const doc=this.doc;
    const revision=this._editRevision||0;
    const meta = await store.saveMap({ ...doc.toFiles(), meta: { ...doc.meta, id: asCopy?null:this.currentId,index:asCopy?null:doc.meta.index,created:asCopy?0:doc.meta.created } });
    if(this.doc===doc){
      this.currentId = meta.id;
      Object.assign(doc.meta,{id:meta.id,index:meta.index,created:meta.created,modified:meta.modified});
      this.dirty = (this._editRevision||0)!==revision;
    }
    this.emit('saved', meta);
    this.emit('doclist');
    return meta;
  }

  async captureMinimap() {
    const g = this.game;
    const size = 512, doc = this.doc;
    const cam = new THREE.OrthographicCamera(0, doc.width, 0, doc.height, 0.1, 4000);
    cam.position.set(doc.width / 2, 1000, -(doc.height / 2)); cam.up.set(0, 0, -1); cam.lookAt(doc.width / 2, 0, -(doc.height / 2));
    cam.left = -doc.width / 2; cam.right = doc.width / 2; cam.top = doc.height / 2; cam.bottom = -doc.height / 2;
    cam.updateProjectionMatrix();
    const rt = new THREE.WebGLRenderTarget(size, size);
    const prevTarget = g.renderer.getRenderTarget();
    const color=g.renderer.getClearColor(new THREE.Color()).clone(),alpha=g.renderer.getClearAlpha();
    const viewport=g.renderer.getViewport(new THREE.Vector4()),scissor=g.renderer.getScissor(new THREE.Vector4()),scissorTest=g.renderer.getScissorTest();
    const nodes=[this.markers.root,this.overlay.root,this.objects.root,this.transformHelper,this.view.terrain?.group,this.view.water?.group].filter(Boolean),visibility=nodes.map(node=>node.visible);
    const buf = new Uint8Array(size * size * 4);
    try{
      for(const node of nodes)node.visible=node===this.view.terrain?.group||node===this.view.water?.group;
      g.renderer.setRenderTarget(rt);g.renderer.setScissorTest(false);
      g.renderer.setClearColor(0x203040,1);g.renderer.clear();g.renderer.render(g.scene,cam);
      readRenderTargetPixels(g.renderer, rt,0,0,size,size,buf);
    }finally{
      g.renderer.setRenderTarget(prevTarget);g.renderer.setClearColor(color,alpha);g.renderer.setViewport(viewport);g.renderer.setScissor(scissor);g.renderer.setScissorTest(scissorTest);
      nodes.forEach((node,i)=>{node.visible=visibility[i];});rt.dispose();
    }
    // WebGL readback is bottom-up; flip to a top-down PNG (client minimaps are already "transposed" per format.js loadSource)
    const canvas = document.createElement('canvas'); canvas.width = size; canvas.height = size;
    const ctx = canvas.getContext('2d');
    const img = ctx.createImageData(size, size);
    for (let y = 0; y < size; y++) img.data.set(buf.subarray((size - 1 - y) * size * 4, (size - y) * size * 4), y * size * 4);
    ctx.putImageData(img, 0, 0);
    const url = canvas.toDataURL('image/png');
    this.doc.meta.minimap = url;
    this.dirty=true;
    return url;
  }

  async exportFile() {
    if (!this.currentId||this.dirty) await this.save();
    if(this.dirty)throw new Error('The map changed during saving. Save the latest edits before exporting.');
    const buf = await store.exportMap(this.currentId);
    return new Blob([buf], { type: 'application/octet-stream' });
  }
  async importFile(file) {
    const buf = await file.arrayBuffer();
    const meta = await store.importMap(buf);
    if (!meta) throw new Error('not a .dkmap file');
    this.emit('doclist');
    return meta;
  }

  async publish(api,{editingIndex=null,expectedRevision,requestId}={}) {
    if(!api?.publish)throw new Error('Open Map Builder from a connected GM panel to publish to its server.');
    const doc=this.doc,revision=this._editRevision||0,bytes=packDkmap(doc.toFiles());
    const result=await api.publish(bytes,{editingIndex,expectedRevision,requestId});
    const newerDraft=this.doc!==doc||(this._editRevision||0)!==revision;
    this.emit('published',{...result,newerDraft});return {...result,newerDraft};
  }

  async openPublished(api,index) {
    if(!api?.source)throw new Error('Connect to the GM server before opening a published map.');
    const files=await api.source(index),meta=await store.importMap(packDkmap(files));
    await this.openMap(meta.id);this.emit('doclist');return meta;
  }

  resize(size) {
    if(this.originalLive?.active)throw Error('Finish or cancel the original shared session first.');
    if (!SIZES.includes(size)) return;
    this.doc = this.doc.resized(size);
    this.history.clear();
    this.ready = this._buildAll().then(()=>{this.dirty=true;});
    return this.ready;
  }

  async play() {
    return launchSandboxPreview(this);
  }

  // ---------------------------------------------------------------------------------------- tools
  setTool(name) {
    if(this.originalLive?.active&&!(this.originalLive.allowedTools||['raise','lower','smooth','flatten','noise','vcolor','type','variant','hole','water','collision']).includes(name)){this.emit('tool',this.tool);return;}
    this.cancelInput();
    if (!TOOLS[name]) return;
    this.tool = name;
    this.placing = false;
    this.toolOpts.erase = false; // 'erase' is shared by the hole/decal/water tools; never leak it across a tool switch
    this._portalDraft = null;
    this.overlay.setCursor(null);
    if (name !== 'select' && name !== 'objects') this._detachGizmo();
    this.emit('tool', name);
  }

  // ---------------------------------------------------------------------------------------- selection / gizmo
  select(kind, id, { additive = false } = {}) {
    if (!additive) this.selection = { kind, ids: new Set(id != null ? [id] : []) };
    else {
      if (this.selection.kind && this.selection.kind !== kind) this.selection = { kind, ids: new Set() };
      this.selection.kind = kind;
      if (id != null) { this.selection.ids.has(id) ? this.selection.ids.delete(id) : this.selection.ids.add(id); }
    }
    this._syncSelectionVisual();
    this.emit('selection');
  }
  clearSelection() { this.selection = { kind: null, ids: new Set() }; this._syncSelectionVisual(); this.emit('selection'); }

  _syncSelectionVisual() {
    this.objects.clearAllHighlights();
    this.markers.setSelected(null, null);
    this._detachGizmo();
    const { kind, ids } = this.selection;
    if (!kind || !ids.size) return;
    if (kind === 'objects') {
      for (const id of ids) this.objects.highlight(id, true);
      if (ids.size === 1) this._attachGizmo(this.objects.byId.get([...ids][0])?.group, 'object', [...ids][0]);
      else {this._refreshSelectionPivot();this._attachGizmo(this._selectionPivot, 'objects', [...ids]);}
    } else {
      const id = [...ids][0];
      this.markers.setSelected(kind, id);
    }
  }

  _attachGizmo(object3d, kind, id) {
    if (!object3d) return;
    this.transform.attach(object3d);
    this.transform.enabled = true;
    this.transformHelper.visible = true;
    this._gizmoTarget = { kind, id };
  }
  _detachGizmo() {
    if(this._gizmoBefore)this._onGizmoDragToggle(false);
    this.transform.detach();
    this.transform.enabled = false;
    this.transformHelper.visible = false;
    this._gizmoTarget = null;
  }
  setGizmoMode(mode) { if(this.originalLive?.active)return;this.transform.setMode(mode); }

  _refreshSelectionPivot() {
    if(!this._selectionPivot || this._gizmoBefore)return;
    const groups=[...this.selection.ids].map(id=>this.objects.byId.get(id)?.group).filter(Boolean);
    this._selectionPivot.position.set(0,0,0);
    for(const group of groups)this._selectionPivot.position.add(group.position);
    if(groups.length)this._selectionPivot.position.multiplyScalar(1/groups.length);
    this._selectionPivot.quaternion.identity();this._selectionPivot.scale.setScalar(1);this._selectionPivot.updateMatrix();
  }

  /** Inspector edits share the same undo stack as brushes and gizmo drags. */
  editRecord(kind,id,patch,label=`Edit ${kind}`) {
    if(this.originalLive?.active)throw Error('Original shared sessions support brush fields only.');
    const doc=this.doc,list=kind==='objects'?doc.objects:doc.meta[kind];
    const rec=list?.find(r=>r.id===id);if(!rec)return false;
    const before=structuredClone(rec),after={...before,...structuredClone(patch)};
    if(JSON.stringify(before)===JSON.stringify(after))return false;
    const apply=value=>{
      Object.assign(rec,structuredClone(value));
      if(this.doc!==doc)return;
      if(kind==='objects')this.objects.syncTransform(id);
      else {this.markers.refresh(kind,id);if(kind==='portals')this.overlay.updatePortals();}
      if(kind==='objects')this._refreshSelectionPivot();
      this.dirty=true;this.emit(kind==='objects'?'objectEdited':'markerEdited',id);
    };
    apply(after);this.history.push(label,()=>apply(before),()=>apply(after));return true;
  }

  editEnvironment(patch) {
    const doc=this.doc,before=structuredClone(doc.meta.env),after={...before,...structuredClone(patch)};
    if(JSON.stringify(before)===JSON.stringify(after))return false;
    const apply=value=>{doc.meta.env=structuredClone(value);if(this.doc!==doc)return;
      this.dirty=true;this.emit('environment');
      // Render rebuilds may fetch assets; preserve a visible error and avoid an
      // unhandled rejection from synchronous undo/redo callbacks.
      this.ready=this._renderTask=(this._renderTask||Promise.resolve()).then(async()=>{if(this.doc===doc){await this.view.rebuildEnvironment();await this.view.rebuildWater();}}).catch(error=>{this.emit('error',error);});
    };
    apply(after);this.history.push('Edit environment',()=>apply(before),()=>apply(after));return true;
  }

  editTileFolder(folder) {
    const doc=this.doc,before=doc.tileFolder,after=normFolder(folder);if(before===after)return false;
    const apply=value=>{doc.tileFolder=value;if(this.doc!==doc)return;this.dirty=true;this.emit('environment');
      this.ready=this._renderTask=(this._renderTask||Promise.resolve()).then(()=>{if(this.doc===doc)return this.view.rebuildTerrain();}).catch(error=>{this.emit('error',error);});};
    apply(after);this.history.push('Change terrain textures',()=>apply(before),()=>apply(after));return true;
  }

  _onGizmoChange() {
    const t = this._gizmoTarget;
    const drag=this._gizmoBefore;
    if (!t || !drag) return;
    const g=this.transform.object;
    // MOL stores a uniform scalar. Constrain every axis handle before persisting.
    if(this.transform.mode==='scale'){
      const axis=this.transform.axis,values=g.scale.toArray(),base=drag.scale;
      const at=axis==='Y'?1:axis==='Z'?2:values.reduce((best,v,i)=>Math.abs(v-base)>Math.abs(values[best]-base)?i:best,0);
      g.scale.setScalar(Math.max(.001,values[at]));
    }
    g.updateMatrix();
    const delta=g.matrix.clone().multiply(drag.inverse),pos=new THREE.Vector3(),q=new THREE.Quaternion(),scale=new THREE.Vector3();
    for(const entry of drag.entries){
      const e=this.objects.byId.get(entry.id);if(!e)continue;
      delta.clone().multiply(entry.matrix).decompose(pos,q,scale);
      Object.assign(e.rec,{x:pos.x,z:pos.z,y:pos.y-this.doc.heightAt(pos.x,pos.z),qx:q.x,qy:q.y,qz:q.z,qw:q.w,scale:scale.x});
      this.objects.syncTransform(entry.id);
    }
    this.dirty = true;
    this.emit('objectEdited', t.id);
  }

  /** TransformControls 'dragging-changed': capture the object's transform before a drag, push one undo entry after. */
  _onGizmoDragToggle(dragging) {
    const t = this._gizmoTarget;
    if (!t || !['object','objects'].includes(t.kind)) return;
    if(dragging){
      const g=this.transform.object;g.updateMatrix();
      const ids=t.kind==='object'?[t.id]:t.id;
      this._gizmoBefore={doc:this.doc,inverse:g.matrix.clone().invert(),scale:g.scale.x,entries:ids.map(id=>{
        const e=this.objects.byId.get(id);if(!e)return null;e.group.updateMatrix();return{id,before:structuredClone(e.rec),matrix:e.group.matrix.clone()};
      }).filter(Boolean)};return;
    }
    const drag=this._gizmoBefore;this._gizmoBefore=null;if(!drag)return;
    const before=drag.entries.map(e=>e.before),after=drag.entries.map(e=>structuredClone(this.objects.byId.get(e.id)?.rec||e.before));
    this._refreshSelectionPivot();
    if(JSON.stringify(before)===JSON.stringify(after))return;
    const apply=values=>{if(this.doc!==drag.doc)return;for(const value of values){const rec=this.doc.objects.find(r=>r.id===value.id);if(rec){Object.assign(rec,structuredClone(value));this.objects.syncTransform(rec.id);}}this._refreshSelectionPivot();this.dirty=true;this.emit('objectEdited');};
    this.history.push('Move/rotate/scale objects',()=>apply(before),()=>apply(after));
  }

  deleteSelection() {
    if(this.originalLive?.active)return;
    const { kind, ids } = this.selection;
    if (!kind || !ids.size) return;
    if (kind === 'objects') {
      const removed = [...ids].map(id => this.objects.byId.get(id)?.rec).filter(Boolean);
      const idx = removed.map(r => this.doc.objects.indexOf(r));
      this.doc.objects = this.doc.objects.filter(r => !ids.has(r.id));
      for (const id of ids) this.objects.remove(id);
      this.history.push('Delete objects',
        () => { for (let i = 0; i < removed.length; i++) this.doc.objects.splice(Math.min(idx[i], this.doc.objects.length), 0, removed[i]); for (const r of removed) this.objects.add(r); },
        () => { this.doc.objects = this.doc.objects.filter(r => !ids.has(r.id)); for (const id of ids) this.objects.remove(id); });
    } else if (kind === 'spawns' || kind === 'npcs' || kind === 'portals') {
      const list = this.doc.meta[kind];
      const removed = list.filter(r => ids.has(r.id));
      this.doc.meta[kind] = list.filter(r => !ids.has(r.id));
      for (const r of removed) this.markers.removeMarker(kind, r.id);
      this.history.push(`Delete ${kind}`,
        () => { this.doc.meta[kind] = [...this.doc.meta[kind], ...removed]; for (const r of removed) this.markers.refresh(kind, r.id); if (kind === 'portals') this.overlay.updatePortals(); },
        () => { this.doc.meta[kind] = this.doc.meta[kind].filter(r => !ids.has(r.id)); for (const r of removed) this.markers.removeMarker(kind, r.id); if (kind === 'portals') this.overlay.updatePortals(); });
    }
    this.clearSelection();
    this.dirty = true;
  }

  duplicateSelection() {
    if(this.originalLive?.active)return;
    if (this.selection.kind !== 'objects' || !this.selection.ids.size) return;
    const copies = [];
    for (const id of this.selection.ids) {
      const rec = this.objects.byId.get(id)?.rec;
      if (!rec) continue;
      const c = { ...rec, id: newId('o'), x: rec.x + 1, z: rec.z + 1 };
      this.doc.objects.push(c); this.objects.add(c); copies.push(c);
    }
    this.history.push('Duplicate objects',
      () => { this.doc.objects = this.doc.objects.filter(r => !copies.includes(r)); for (const c of copies) this.objects.remove(c.id); },
      () => { for (const c of copies) { this.doc.objects.push(c); this.objects.add(c); } });
    this.select('objects', null);
    for (const c of copies) this.select('objects', c.id, { additive: true });
    this.dirty = true;
  }

  nudgeSelection(dx, dz) {
    if(this.originalLive?.active)return;
    const { kind, ids } = this.selection;
    if (!ids.size) return;
    const records=(kind==='objects'?this.doc.objects:this.doc.meta[kind]||[]).filter(r=>ids.has(r.id));
    const before=records.map(r=>structuredClone(r)),after=before.map(r=>kind==='portals'?{...r,x0:r.x0+dx,z0:r.z0+dz,x1:r.x1+dx,z1:r.z1+dz}:{...r,x:r.x+dx,z:r.z+dz});
    if(!records.length||(!dx&&!dz))return;
    const apply=values=>{records.forEach((rec,i)=>{Object.assign(rec,values[i]);if(kind==='objects')this.objects.syncTransform(rec.id);else this.markers.refresh(kind,rec.id);});if(kind==='objects')this._refreshSelectionPivot();if(kind==='portals')this.overlay.updatePortals();this.dirty=true;this.emit('selection');};
    apply(after);this.history.push('Nudge selection',()=>apply(before),()=>apply(after));
  }

  // ---------------------------------------------------------------------------------------- placement
  snapSelectionToSurface() {
    if(this.selection.kind!=='objects')return;
    const ids=[...this.selection.ids],records=this.doc.objects.filter(r=>this.selection.ids.has(r.id));
    const before=records.map(r=>structuredClone(r)),after=before.map(r=>({...r,y:this.objects.groundHeightAt(r.x,r.z,this.doc.heightAt(r.x,r.z)+(r.y||0)+.8,ids)-this.doc.heightAt(r.x,r.z)}));
    if(JSON.stringify(before)===JSON.stringify(after))return;
    const apply=values=>{records.forEach((rec,i)=>{Object.assign(rec,values[i]);this.objects.syncTransform(rec.id);});this._refreshSelectionPivot();this.dirty=true;this.emit('objectEdited');};
    apply(after);this.history.push('Snap objects to surface',()=>apply(before),()=>apply(after));
  }
  placeObject(x, z, surfaceY = Infinity) {
    if (!this.libraryPick) return;
    const rec = { id: newId('o'), name: this.libraryPick, x: this._snap(x), z: this._snap(z), y: 0, qx: 0, qy: 0, qz: 0, qw: 1, scale: 1 };
    rec.y=(this.objects.groundHeightAt?.(rec.x,rec.z,surfaceY+.01)??this.doc.heightAt(rec.x,rec.z))-this.doc.heightAt(rec.x,rec.z);
    this.doc.objects.push(rec);
    this.objects.add(rec);
    this.history.push('Place object',
      () => { this.doc.objects = this.doc.objects.filter(r => r !== rec); this.objects.remove(rec.id); },
      () => { this.doc.objects.push(rec); this.objects.add(rec); });
    this.dirty = true;
    return rec;
  }
  placeSpawn(x, z) {
    if (!this.spawnPick) return;
    const rec = { id: newId('s'), monsterIndex: Number(this.spawnPick.monsterIndex), x: this._snap(x), z: this._snap(z), respawnSec: 30 };
    this.doc.meta.spawns.push(rec);
    this.markers.refresh('spawns', rec.id);
    this.history.push('Place spawn',
      () => { this.doc.meta.spawns = this.doc.meta.spawns.filter(r => r !== rec); this.markers.removeMarker('spawns', rec.id); },
      () => { this.doc.meta.spawns.push(rec); this.markers.refresh('spawns', rec.id); });
    this.dirty = true;
    return rec;
  }
  placeNpc(x, z) {
    if (!this.npcPick) return;
    const rec = { id: newId('n'), npcIndex: Number(this.npcPick.npcIndex), x: this._snap(x), z: this._snap(z), dirDeg: 0, name: null };
    this.doc.meta.npcs.push(rec);
    this.markers.refresh('npcs', rec.id);
    this.history.push('Place NPC',
      () => { this.doc.meta.npcs = this.doc.meta.npcs.filter(r => r !== rec); this.markers.removeMarker('npcs', rec.id); },
      () => { this.doc.meta.npcs.push(rec); this.markers.refresh('npcs', rec.id); });
    this.dirty = true;
    return rec;
  }
  commitPortalDraft() {
    const d = this._portalDraft; this._portalDraft = null;
    if (!d) return null;
    const x0 = Math.min(d.x0, d.x1), x1 = Math.max(d.x0, d.x1), z0 = Math.min(d.z0, d.z1), z1 = Math.max(d.z0, d.z1);
    if (x1 - x0 < 0.5 || z1 - z0 < 0.5) return null;
    const rec = { id: newId('p'), name: 'Portal', x0, z0, x1, z1, object: null, to: { map: this.doc.meta.index || 0, x: (x0 + x1) / 2, z: (z0 + z1) / 2, dirDeg: 0 } };
    this.doc.meta.portals.push(rec);
    this.markers.refresh('portals', rec.id); this.overlay.updatePortals();
    this.history.push('Place portal',
      () => { this.doc.meta.portals = this.doc.meta.portals.filter(r => r !== rec); this.markers.removeMarker('portals', rec.id); this.overlay.updatePortals(); },
      () => { this.doc.meta.portals.push(rec); this.markers.refresh('portals', rec.id); this.overlay.updatePortals(); });
    this.dirty = true;
    return rec;
  }
  _snap(v) { return this.snap > 0 ? Math.round(v / this.snap) * this.snap : v; }

  // ---------------------------------------------------------------------------------------- pointer input (called by tools/mapbuilder.html)
  pointerDown(ndc, button, {additive=false} = {}) {
    if (this._gizmoDragging) return;
    if (button === 2) { this._drag = { ndc: ndc.clone() }; return; }
    if (button !== 0) return;
    const ray = this._ray(ndc);
    const group = TOOLS[this.tool]?.group;
    if (group === 'select' || (group === 'objects' && !this.libraryPick)) {
      const hitObj = this.objects.pick(ray);
      if (hitObj != null) { this.select('objects', hitObj, { additive }); return; }
      const hitM = this.markers.pick(ray);
      if (hitM) { this.select(hitM.kind, hitM.id, { additive: false }); this._dragMarker = hitM; this._beginMarkerDrag(hitM, ray); return; }
      if(!additive)this.clearSelection();
      return;
    }
    if (group === 'objects' && this.libraryPick) {
      let p=this.view.pickGround(ray,{clampToMap:true});const surface=this.objects.pickSurface?.(ray);
      if(surface&&surface.x>=0&&surface.z>=0&&surface.x<=this.doc.width&&surface.z<=this.doc.height){
        const distance=v=>ray.ray.origin.distanceToSquared(new THREE.Vector3(v.x,v.y,-v.z));
        if(!p||distance(surface)<distance(p))p=surface;
      }
      if(p)this.placeObject(p.x,p.z,p.y);return;
    }
    if (this.tool === 'spawns') {
      if (this.placing && this.spawnPick) { const p = this.view.pickGround(ray, { clampToMap: true }); if (p) this.placeSpawn(p.x, p.z); return; }
      const hitM = this.markers.pick(ray); if (hitM?.kind === 'spawns') { this.select('spawns', hitM.id); this._dragMarker = hitM; this._beginMarkerDrag(hitM, ray); } else this.clearSelection();
      return;
    }
    if (this.tool === 'npcs') {
      if (this.placing && this.npcPick) { const p = this.view.pickGround(ray, { clampToMap: true }); if (p) this.placeNpc(p.x, p.z); return; }
      const hitM = this.markers.pick(ray); if (hitM?.kind === 'npcs') { this.select('npcs', hitM.id); this._dragMarker = hitM; this._beginMarkerDrag(hitM, ray); } else this.clearSelection();
      return;
    }
    if (this.tool === 'portals') {
      if (this.placing) { const p = this.view.pickGround(ray, { clampToMap: true }); if (p) this._portalDraft = { x0: p.x, z0: p.z, x1: p.x, z1: p.z }; return; }
      const hitM = this.markers.pick(ray); if (hitM?.kind === 'portals') { this.select('portals', hitM.id); this._dragMarker = hitM; this._beginMarkerDrag(hitM, ray); } else this.clearSelection();
      return;
    }
    if (this.tool === 'decal') {
      const p = this.view.pickGround(ray, { clampToMap: true });
      if (!p) return;
      if (this.toolOpts.erase) this.brushes.eraseDecalAt(p.x, p.z);
      else if (this.toolOpts.decal) this.brushes.stampDecal(p.x, p.z, { name: this.toolOpts.decal, size: this.toolOpts.decalSize, rot: this.toolOpts.decalRot });
      return;
    }
    // terrain / tile / water / collision brushes
    const p = this.view.pickGround(ray, { clampToMap: true });
    if (!p) return;
    this._lastGround = p;
    this._stroking = true;
    this.brushes.beginStroke(this.tool, p.x, p.z, this.toolOpts);
    this.brushes.applyAt(p.x, p.z, 1 / 60, this.toolOpts);
    this.dirty = true;
  }

  pointerMove(ndc) {
    if (this._drag) { const dx = ndc.x - this._drag.ndc.x, dy = ndc.y - this._drag.ndc.y; this.cam.yaw -= dx * 2.4; this.cam.pitch = Math.max(-1.5, Math.min(1.5, this.cam.pitch + dy * 2.0)); this._drag.ndc.copy(ndc); return; }
    const ray = this._ray(ndc);
    if (this._dragMarker) {
      const p = this.view.pickGround(ray, { clampToMap: true });
      if (p) this._applyMarkerDrag(this._dragMarker, p);
      return;
    }
    if (this._portalDraft) { const p = this.view.pickGround(ray, { clampToMap: true }); if (p) { this._portalDraft.x1 = p.x; this._portalDraft.z1 = p.z; } return; }
    const p = this.view.pickGround(ray, { clampToMap: true });
    this._lastGround = p;
    if (p && RADIUS_TOOLS.has(this.tool)) this.overlay.setCursor(p, this.toolOpts.radius || 1); else this.overlay.setCursor(null);
    if (this._stroking && p && !CONTINUOUS_TOOLS.has(this.tool)) this.brushes.applyAt(p.x, p.z, 1 / 60, this.toolOpts);
  }

  pointerUp(button) {
    if (button === 2) { this._drag = null; return; }
    if (this._stroking) { this.brushes.endStroke(); this._stroking = false; }
    if (this._dragMarker) { this._commitMarkerDrag(this._dragMarker); this._dragMarker = null; }
    if (this._portalDraft) this.commitPortalDraft();
  }

  _beginMarkerDrag(hit, ray) {
    const p = this.view.pickGround(ray, { clampToMap: true });
    this._dragStart = p;
    this._dragOrig = null;
    const rec = (this.doc.meta[hit.kind] || []).find(r => r.id === hit.id);
    this._dragRecBefore = rec ? { ...rec } : null;
    if (hit.kind === 'portals' && hit.handle == null && rec) this._dragOrig = { x0: rec.x0, z0: rec.z0, x1: rec.x1, z1: rec.z1 };
  }
  _applyMarkerDrag(hit, p) {
    if (hit.kind === 'portals') {
      const rec = this.doc.meta.portals.find(r => r.id === hit.id);
      if (!rec) return;
      if (hit.handle === 0) { rec.x0 = this._snap(p.x); rec.z0 = this._snap(p.z); }
      else if (hit.handle === 1) { rec.x1 = this._snap(p.x); rec.z1 = this._snap(p.z); }
      else if (this._dragOrig && this._dragStart) {
        const dx = p.x - this._dragStart.x, dz = p.z - this._dragStart.z;
        rec.x0 = this._snap(this._dragOrig.x0 + dx); rec.z0 = this._snap(this._dragOrig.z0 + dz);
        rec.x1 = this._snap(this._dragOrig.x1 + dx); rec.z1 = this._snap(this._dragOrig.z1 + dz);
      }
      this.markers.refresh('portals', hit.id); this.overlay.updatePortals();
      return;
    }
    const list = hit.kind === 'spawns' ? this.doc.meta.spawns : this.doc.meta.npcs;
    const rec = list.find(r => r.id === hit.id);
    if (!rec) return;
    rec.x = this._snap(p.x); rec.z = this._snap(p.z);
    this.markers.refresh(hit.kind, hit.id);
  }
  _commitMarkerDrag(hit) {
    const before = this._dragRecBefore;
    const rec = (this.doc.meta[hit.kind] || []).find(r => r.id === hit.id);
    this._dragRecBefore = null; this._dragOrig = null; this._dragStart = null;
    if (before && rec) {
      const after = { ...rec }, kind = hit.kind;
      const moved = Object.keys(after).some(k => JSON.stringify(after[k]) !== JSON.stringify(before[k]));
      if (moved) this.history.push(`Move ${kind}`,
        () => { Object.assign((this.doc.meta[kind] || []).find(r => r.id === hit.id) || {}, before); this.markers.refresh(kind, hit.id); if (kind === 'portals') this.overlay.updatePortals(); },
        () => { Object.assign((this.doc.meta[kind] || []).find(r => r.id === hit.id) || {}, after); this.markers.refresh(kind, hit.id); if (kind === 'portals') this.overlay.updatePortals(); });
    }
    this.dirty = true;
    this.emit('markerEdited', hit);
  }

  _ray(ndc) {
    const raycaster = this._raycaster || (this._raycaster = new THREE.Raycaster());
    raycaster.setFromCamera(ndc, this.game.camera);
    return raycaster;
  }

  keyDown(code) {
    this.keys.add(code);
    if (code === 'Delete' || code === 'Backspace') this.deleteSelection();
    if ((code === 'KeyD') && (this._ctrl)) this.duplicateSelection();
    if (code === 'Digit1') this.setGizmoMode('translate');
    if (code === 'Digit2') this.setGizmoMode('rotate');
    if (code === 'Digit3') this.setGizmoMode('scale');
    if (code === 'ArrowLeft') this.nudgeSelection(-(this.snap || 0.25), 0);
    if (code === 'ArrowRight') this.nudgeSelection(this.snap || 0.25, 0);
    if (code === 'ArrowUp') this.nudgeSelection(0, -(this.snap || 0.25));
    if (code === 'ArrowDown') this.nudgeSelection(0, this.snap || 0.25);
    if (code === 'ControlLeft' || code === 'ControlRight') this._ctrl = true;
    if (this._ctrl && code === 'KeyZ') this.history.undo();
    if (this._ctrl && code === 'KeyY') this.history.redo();
  }
  keyUp(code) { this.keys.delete(code); if (code === 'ControlLeft' || code === 'ControlRight') this._ctrl = false; }

  // ---------------------------------------------------------------------------------------- frame
  update(dt) {
    // Strength is per second, independent of mouse event frequency; holding still also works.
    if (this._stroking && this._lastGround && CONTINUOUS_TOOLS.has(this.tool))
      this.brushes.applyAt(this._lastGround.x, this._lastGround.z, Math.max(0, Math.min(0.05, dt)), this.toolOpts);
    this.moveNavigation({forward:Number(this.keys.has('KeyW'))-Number(this.keys.has('KeyS')),right:Number(this.keys.has('KeyD'))-Number(this.keys.has('KeyA')),up:Number(this.keys.has('KeyE'))-Number(this.keys.has('KeyQ')),boost:this.keys.has('ShiftLeft')||this.keys.has('ShiftRight')},dt);
    const g = this.game;
    this.syncCamera();
    if(this.overlay?.startFlag){const start=this.doc.meta.start;this.overlay.startFlag.visible=this.navigation!=='firstperson'||Math.hypot(this.cam.pos.x-start.x,-this.cam.pos.z-start.z)>2;}
    this.view.update(dt, g.camera, g.camera.position);
  }

  dispose() {
    this.cancelInput();
    this.originalLive?.dispose();
    this.transformHelper.removeFromParent();
    this.transform.dispose();
    this.view.dispose(); this.overlay.dispose(); this.objects.dispose(); this.markers.dispose();
  }
}
