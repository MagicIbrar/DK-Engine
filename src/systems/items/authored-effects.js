import * as THREE from 'three';
import {EffectPlayer,controlBone,attachBoneName} from '../skills/effects.js';
import {AuthoredEffectsData,refinementEffect,socketEffect,socketGems} from './authored-effects-data.js';
import {WeaponGemGlow,weaponBlade,weaponStations,stationScale,weaponDepthBias,socketBoneLocal} from './weapon-gem-glow.js';
import {gfxB} from '../../config/gfx-b-switches.js'; // gfx-B2
import {updateOrbit} from './weapon-orbit.js';
import {costumeIntrinsicEffects} from './costume-effects.js';

/** Equipped scenes play at their authored rate (an earlier half-speed Rondo bubble clock was not native). */
export function equipmentPresentationRate() { return 1; }

// Cursor pickup changes the visible loadout before ownership is committed.
// Effects must follow that same preview rather than waiting for a saved loadout
// that deliberately still owns the carried item in its original slot.
export const equipmentViewFor = actor => actor?._equipmentPreview?.equipment || actor?.save?.equipment || {};

/** Socket entries of a weapon (see socketEffect / socketGems and src/config/engine-chosen-socket-glow.js):
 *  - one {slot, socketGlow:{attribute, stones, capacity, slots}} per stone attribute; `slots` = the socket indexes carrying it,
 *    each of which plays the attribute's authored sprite scene at its own station on the weapon;
 *  - one {slot, socketTint:{capacity, gems:[{index, attribute}]}} for the gem-coloured pass over the weapon itself. */
const socketEntries=(slot,effect,gems=[])=>effect?[
 ...effect.glows.map(g=>({slot,socketGlow:{attribute:g.attribute,stones:g.stones,capacity:effect.capacity,slots:gems.filter(x=>x.attribute===g.attribute).map(x=>x.index)}})),
 {slot,socketTint:{capacity:effect.capacity,gems:gems.map(({index,attribute})=>({index,attribute}))}},
]:[];

export function equippedEffectIds(db,view,equip=null){
 // A weapon appearance (weapon-appearance.js) draws its material's own item_shape row: the shape's model effects follow the
 // drawn material; the grade (refinement) and socket effects stay the worn weapon's.
 const drawn=index=>Number(index)>0?db.def(Number(index)):null;
 const out=[],costumes=new Set();for(const [slot,asset]of Object.entries(view||{})){
  if(!asset?.itemIndex)continue;const def=db.def(asset.itemIndex),shape=db.shape((slot==='weapon'||slot==='wing')&&drawn(asset.appearance)||def);
  // A costume covers several body parts with one item; its intrinsic effect plays once.
  const repeated=asset.costume&&costumes.has(asset.itemIndex);if(asset.costume)costumes.add(asset.itemIndex);
  // Talisman appearance transforms select another native talisman effect index.
  const own=asset.costume?costumeIntrinsicEffects(db,asset):slot==='talisman'&&Number(asset.appearance)>0?[asset.appearance]:[shape?.effect,shape?.effectAdd];
  if(!repeated)for(const id of own)if(Number(id)>0)out.push({slot,id:Number(id)});
  const refinement=!asset.costume&&refinementEffect(def,slot);if(refinement)out.push({slot,...refinement});
  if(slot==='weapon')out.push(...socketEntries(slot,socketEffect(def,asset.sockets,db),socketGems(asset.sockets,db)));
  if(slot==='weapon'&&asset.leftMesh){
   const preset=equip?.presets?.[equip.active||0],off=equip?.items?.[preset?.[5]],offIndex=asset.leftItemIndex||off?.itemIndex,offDef=offIndex?db.def(offIndex):null;
   // Intrinsic FX belong to the item supplying this mesh. Paired meshes use
   // their main item's authored left selectors; independent offhands use theirs.
   const independent=asset.leftIndependent??!!off,leftShape=independent?db.shape(drawn(asset.leftAppearance)||offDef):shape;
   const leftIds=independent?[leftShape?.effect,leftShape?.effectAdd]:[leftShape?.leftEffect,leftShape?.leftEffectAdd];
   for(const id of leftIds)if(Number(id)>0)out.push({slot:'left',id:Number(id)});
   // A second independent weapon has its own grade; a paired native weapon
   // uses the main grade. Never paint a main-hand grade onto an unknown shield.
   const rule=db.weaponRule?.(def),paired=asset.leftIndependent===false||rule?.column==='both'||rule?.name==='ORB';
   const leftDef=independent?offDef:paired?def:null;
   const leftRef=leftDef&&refinementEffect(leftDef,'left');if(leftRef)out.push({slot:'left',...leftRef});
   const leftSockets=asset.leftSockets||off?.sockets;
   out.push(...socketEntries('left',leftDef&&socketEffect(leftDef,leftSockets,db),socketGems(leftSockets,db)));
  }
 }return out;
}
function wingFor(actor){
 if(actor.transUpStage>0||actor.transformLook||actor.transformed||actor.transform)return null;
 const bone=actor.instance?.getBone?.(equipmentViewFor(actor).wing?.bone||'weaponW');
 return bone?.children?.find(object=>object.userData?.mountsWing)||null;
}
/** Effect owner of an equipment slot (exported for tests). A wing scene may name a bone of the wearer rather than of the
 * wing rig: 2023 Champion's Wings (scene of shape effect on wing_strongest2023_*.skel) attach to `weaponW`, the class-skeleton
 * bone the wing itself mounts on (items.json equipment.wingBone), which the wing skel does not contain. Wing bones resolve on
 * the wing rig first, then on the wearer's skeleton (as weapon bones already do); a bone on neither remains unresolved. */
/** Indices of active controls whose attach bone resolves on no rig of the owner (exported for tests). */
export function blockedControls(controls,owner){const blocked=new Set();controls.forEach((c,index)=>{const bone=attachBoneName(controlBone(c));if(c.active!==false&&bone&&!['top','center','movement'].includes(bone)&&!owner.instance?.getBone(bone))blocked.add(index);});return blocked;}
export function ownerFor(actor,slot){
 const wing=slot==='wing'?wingFor(actor):null;if(slot==='wing'&&!wing)return null;
 const hand=slot==='left'?'second':'main',weapon=slot==='weapon'||slot==='left'?actor._weaponObjs?.find(e=>e.hand===hand)?.obj:null;
 const assetKey=String(equipmentViewFor(actor)[slot]?.mesh||'').replace(/\\/g,'/').toLowerCase();
 const bodyMeshes=(actor.instance?.meshes||[]).filter((mesh,i)=>assetKey&&String(actor.instance?.model?.parts?.[i]?.meshKey||'').replace(/\\/g,'/').toLowerCase()===assetKey);
 return {get disposed(){return actor.disposed;},get x(){return actor.x;},get z(){return actor.z;},get y(){return actor.y;},get yaw(){return actor.yaw;},group:wing||weapon||actor.group,height:actor.height,
  instance:{meshes:wing?wing.userData.instance?.meshes||[]:weapon?(()=>{const meshes=[];weapon.traverse(o=>{if(o.isMesh&&!o.userData.ownMat)meshes.push(o);});return meshes;})():bodyMeshes,getBone(name){if(wing)return wing.userData.instance?.getBone?.(name)||actor.instance?.getBone?.(name)||null;const find=n=>{let found=null;weapon?.traverse(o=>{if(!found&&o.isBone&&(o.userData.raw===n||o.name===n))found=o;});return found;};
 // Left twin rigs (10511 att_equ_leg_bal_01_l.skel: SWD_W0x_L) resolve the shared scene's main-hand names to their _L twin.
 return find(name)||(slot==='left'&&!/_L$/i.test(name)?find(name+'_L'):null)||actor.instance?.getBone?.(name);}}};
}
/** Socket scenes author no bone/position. ENGINE-CHOSEN attachment boundary:
 * play their unchanged zero offset at the installed weapon origin. The native
 * binary's invocation point is unavailable; no strike-line midpoint is inferred.
 * Keeping group on that weapon also lets the existing first-person pass rebase
 * this same sprite to its visible native hand without altering its size/alpha. */
const weaponFor=(actor,slot)=>actor._weaponObjs?.find(e=>e.hand===(slot==='left'?'second':'main'))?.obj||null;
/** ENGINE-CHOSEN station: with `station` ({local}, weapon-space point of a socket on the blade line, see weapon-gem-glow.js)
 * the scene plays there instead of at the weapon origin; the rest (lifetime, visibility, first-person rebasing) is unchanged. */
function glowOwner(actor,slot,station=null){
 const weapon=weaponFor(actor,slot);
 if(!weapon)return null;
 const point=new THREE.Vector3(),world=()=>{weapon.updateWorldMatrix(true,false);return point.copy(station.local).applyMatrix4(weapon.matrixWorld);};
 const instance=actor.instance,owner=ownerFor(actor,slot),coordinate=index=>{weapon.updateWorldMatrix(true,false);return weapon.matrixWorld.elements[index];};
 const attached=()=>{if(!weapon.parent)return false;if(!actor.group)return true;for(let node=weapon;node;node=node.parent)if(node===actor.group)return true;return false;};
 // The sprite lives under the global FX root, so inherit the captured weapon's
 // lifetime and effective visibility explicitly. Hiding keeps its native clock;
 // unequip/body replacement/detachment must never move it to a stale local origin.
 Object.defineProperties(owner,{
  disposed:{get:()=>actor.disposed||actor.instance!==instance||!actor._weaponObjs?.some(e=>e.obj===weapon)||!attached()},
  attachmentVisible:{get:()=>{for(let node=weapon;node;node=node.parent)if(node.visible===false)return false;return true;}},
  x:{get:()=>station?world().x:coordinate(12)},y:{get:()=>station?world().y:coordinate(13)},z:{get:()=>station?-world().z:-coordinate(14)}
 });
 return owner;
}
/** The weapon meshes the actor's body has actually installed match the equipment view that wants them. After a Tab swap
 * save.equipment changes at once while the body (and its weapon objects) rebuild ~0.4 s later; weapon effects must neither
 * keep playing on the retired weapon nor be prepared onto it. */
export function weaponsSettled(actor){
 if(actor._installedEquipment){
  const asset=value=>value?.mesh?JSON.stringify([value.mesh,value.tpack||null,value.textures||null]):null;
  if(['helmet','coat','pants','glove','boots'].some(slot=>asset(actor._installedEquipment[slot])!==asset(equipmentViewFor(actor)[slot])))return false;
 }
 const wanted=equipmentViewFor(actor).weapon;
 // A Player always records what it installed (null when bare-handed); stand-ins without any record cannot mismatch.
 if(actor.weapon===undefined)return true;
 if(!wanted||wanted.none||!wanted.mesh)return !actor.weapon?.def?.mesh;
 const have=actor.weapon?.def;if(!have)return false;
 return have.mesh===wanted.mesh&&(have.leftMesh||null)===(wanted.leftMesh||null);
}

// Each slot owns its own effects. Re-equipping a coat must not restart a wing,
// a shield, socket tint or another armor piece just because the actor changed.
function slotSnapshots(actor,entries){
 const snapshots=new Map(),view=equipmentViewFor(actor);
 for(const slot of new Set(entries.map(entry=>entry.slot))){
  const asset=slot==='left'?Object.fromEntries(Object.entries(view.weapon||{}).filter(([key])=>key.startsWith('left')))
   :slot==='weapon'?Object.fromEntries(Object.entries(view.weapon||{}).filter(([key])=>!key.startsWith('left'))):view[slot];
  const own=entries.filter(entry=>entry.slot===slot),owner=ownerFor(actor,slot);
  snapshots.set(slot,{signature:JSON.stringify([own,asset]),stance:own.some(entry=>entry.id)?actor.stance:null,effectIds:own.filter(entry=>entry.id).map(entry=>entry.id),targets:[owner?.group,...(owner?.instance?.meshes||[])]});
 }
 return snapshots;
}
const sameSlot=(before,after,data)=>before&&after&&before.signature===after.signature&&before.targets.length===after.targets.length&&before.targets.every((target,index)=>target===after.targets[index])
 &&(before.stance===after.stance||after.effectIds.every(id=>data?.sameStanceReference?.(id,before.stance,after.stance)===true));
// Effects are only for currently visible equipped actors. Inventory columns author no effect.
export class AuthoredEquipmentEffects{
 constructor(game,db,{data=new AuthoredEffectsData(),fx=null,maxHandles=Infinity,entriesForActor=actor=>equippedEffectIds(db,equipmentViewFor(actor),actor._equipmentPreview?.equip||actor.save?.equip)}={}){this.game=game;this.db=db;this.data=data;this.fx=fx;this.maxHandles=maxHandles;this.entriesForActor=entriesForActor;this.records=new Map();this.pending=0;this.elapsed=1;this.clock=0;this.disposed=false;}
 clear(actor){const record=this.records.get(actor);if(!record)return;record.expired=true;for(const h of record.handles)h.stop(true);this.records.delete(actor);}
 update(dt){
  if(this.disposed)return;
  // Black Wizard orbs keep orbiting across run / walk / skill clips (weapon-orbit.js). World actors only: the front-end scenes
  // (actors owned by a FrontStage) drive their own orbit from select.js / create.js with the scene's forced style.
  // (PERF: this ran `new Set([player, ...actors()])` + a full pass over ~180 actors every frame. Same visits, same order, each player once,
  // without the Set / spread copy: only `kind === 'player'` actors can orbit, and those are few, so a tiny reused list de-duplicates them.)
  {const list=this.game.actors?.()||[],seen=this._orbitSeen||(this._orbitSeen=[]);seen.length=0;
   const visit=actor=>{if(actor?.kind!=='player'||seen.includes(actor))return;seen.push(actor);if(!actor.stage&&!actor.culled)updateOrbit(actor,dt);};
   visit(this.game.player);for(const actor of list)visit(actor);seen.length=0;}
  // TransUp replaces the wing rig. Retire its detached global FX in this update.
  for(const [actor,record]of this.records)if((actor.transUpStage>0||actor.transformLook||actor.transformed||actor.transform)&&record.weapons?.some(w=>w.userData?.mountsWing)){
   for(const handle of record.handles.filter(handle=>handle.equipmentSlot==='wing'))handle.stop(true);
   record.handles=record.handles.filter(handle=>handle.equipmentSlot!=='wing');record.slots?.delete('wing');this.elapsed=.25;
  }
  // A swapped-out weapon's effects end this frame; new ones wait for the rebuilt body (see weaponsSettled).
  for(const [actor,record]of this.records){
   if(record.visualRevision!==actor._equipmentVisualRevision)this.elapsed=.25;
   if(record.instance!==actor.instance){this.clear(actor);this.elapsed=.25;continue;}
   const expiredSlots=new Set(record.handles.filter(handle=>handle.owner?.disposed).map(handle=>handle.equipmentSlot));
   if(expiredSlots.size){for(const handle of record.handles.filter(handle=>expiredSlots.has(handle.equipmentSlot)))handle.stop(true);record.handles=record.handles.filter(handle=>!expiredSlots.has(handle.equipmentSlot));for(const slot of expiredSlots)record.slots?.delete(slot);this.elapsed=.25;}
  }
  this.clock+=Math.max(0,dt);if(this.game.effects?.enabled===false){for(const actor of [...this.records.keys()])this.clear(actor);return;}this.elapsed+=dt;
  if(this.elapsed>=.25){this.elapsed=0;const actors=[...new Set([this.game.player,...(this.game.actors?.()||[])])].filter(a=>a?.kind==='player'&&!a.disposed&&!a.culled&&!a.dead&&a.loaded&&a.instance&&Math.hypot(a.x-(this.game.player?.x||0),a.z-(this.game.player?.z||0))<60);
   for(const actor of this.records.keys())if(!actors.includes(actor))this.clear(actor);
   for(const actor of actors){if(!weaponsSettled(actor))continue;const entries=this.entriesForActor(actor),slots=slotSnapshots(actor,entries),weapons=(actor._weaponObjs||[]).map(w=>w.obj).concat(wingFor(actor)||[]);let record=this.records.get(actor);
    if(record&&(record.slots.size!==slots.size||[...slots].some(([slot,state])=>!sameSlot(record.slots.get(slot),state,this.data)))){
     // Supersede any pending async preparation before transferring live handles.
     // Only complete slots can transfer; a half-loaded slot retries as a whole.
     record.expired=true;
     const keep=new Set([...slots].filter(([slot,state])=>record.completeSlots.has(slot)&&sameSlot(record.slots.get(slot),state,this.data)).map(([slot])=>slot));
     const handles=[];for(const handle of record.handles){if(keep.has(handle.equipmentSlot))handles.push(handle);else handle.stop(true);}
     record={instance:actor.instance,slots,weapons,handles,completeSlots:keep,expired:false,next:0,visualRevision:actor._equipmentVisualRevision};this.records.set(actor,record);
    }
    if(record)record.visualRevision=actor._equipmentVisualRevision;
    if((record&&(!record.retry&&record.next>=entries.length||record.retry&&record.retryAt>this.clock))||!entries.length||this.pending>=2||record?.preparing)continue;
    record ||= {instance:actor.instance,slots,weapons,handles:[],completeSlots:new Set(),expired:false,next:0};record.visualRevision=actor._equipmentVisualRevision;record.retry=false;record.preparing=true;this.records.set(actor,record);this.pending++;
    void this.prepare(actor,record,entries).catch(error=>{record.error=error.message;record.failures=(record.failures||0)+1;record.retry=record.failures<3;record.retryAt=this.clock+2**(record.failures-1);if(record.failures===1)console.warn('[items] authored effect',error.message);}).finally(()=>{record.preparing=false;this.pending--;});
   }
  }
  this.fx?.update(dt);
  // Gem-coloured weapon passes are not scenes of the effect player; they advance on the same frame clock.
  for(const record of this.records.values())for(const h of record.handles)if(h instanceof WeaponGemGlow)h.update(dt);
 }
 /** The gem-coloured pass over the weapon: each socket's hue is the native socket texture's hue (socketGlowTexture),
  * placed at that socket's station on the weapon line. Returns false when it must be retried (weapon not attached yet). */
 async prepareTint(actor,record,entry){
  if(gfxB('socketWashOff'))return true;   // gfx-B2: Global authors no weapon tint; only the native socket scenes play
  const tint=entry.socketTint,attributes=[...new Set(tint.gems.map(g=>g.attribute))];
  const hues=new Map((await Promise.all(attributes.map(async a=>[a,(await this.data.socketGlowTexture?.(a))?.hue]))).filter(([,hue])=>hue));
  if(record.expired||this.disposed||actor.culled||actor.dead||actor.disposed||actor.instance!==record.instance)return true;
  const weapon=weaponFor(actor,entry.slot),owner=glowOwner(actor,entry.slot);if(!weapon||!owner)return true;
  if(owner.disposed)return false;
  const stations=weaponStations(weaponBlade(weapon),tint.capacity),gems=tint.gems.filter(g=>hues.has(g.attribute)&&stations[g.index]).map(g=>({local:stations[g.index].local,rgb:hues.get(g.attribute)}));
  if(!gems.length)return true;
  const handle=new WeaponGemGlow({weapon,owner,stations:gems,capacity:tint.capacity,spacing:stations[0].spacing,timeMs:1000,glow:this.game.gfx?.glow||null});handle.equipmentSlot=entry.slot;record.handles.push(handle);
  return true;
 }
 async prepare(actor,record,entries){
  for(;record.next<entries.length;record.next++){const entry=entries[record.next],glow=entry.socketGlow;
   if(record.expired||this.disposed)return;
   if(record.completeSlots?.has(entry.slot))continue;
   if(entry.socketTint){if(!await this.prepareTint(actor,record,entry)){record.retry=true;return;}continue;}
   // GLOBAL DATA for the gem mist: authored socket scenes (modeleffect group 24 -> cate 7 ids 1-6) carry startposition
   // 0 0 0 and no bone. Attach point comes from the weapon skel's native blade dummies (SWD_W01..SWD_W04 / _L), the same
   // bones item_upgrade_10* scenes use. Count intensity = one authored scene per filled gem at that gem's bone (no alpha
   // gain invention). Fallback: ENGINE-CHOSEN weaponStations blade line, then weapon origin.
   const ref=glow?await this.data.socketReference(glow.attribute):entry.upgrade?await this.data.upgradeReference(entry.upgrade,entry.weapon):await this.data.reference(entry.id,actor.stance==='battle');
   if(record.expired||this.disposed||actor.culled||actor.dead||actor.disposed||actor.instance!==record.instance)return;if(!ref)continue;
   this.fx||=new EffectPlayer(this.game,this.data);
   const stations=glow?( ()=>{
    const weapon=weaponFor(actor,entry.slot);
    const blade=weaponBlade(weapon);
    const fallback=blade?weaponStations(blade,glow.capacity):[];
    const idxs=Array.isArray(glow.slots)&&glow.slots.length?glow.slots:[0];
    return idxs.map(index=>{
     const local=socketBoneLocal(weapon,entry.slot,index);
     if(local)return{local,spacing:fallback[index]?.spacing||0.4,index};
     if(fallback[index])return{...fallback[index],index};
     return null; // glowOwner(null) = weapon origin; stacked origins still = count intensity
    });
   })():[null];
   const active=this.fx.active.size;
   if(active>=this.maxHandles||(active>0&&active+stations.length>this.maxHandles)){record.retry=true;return;}
   const owners=stations.map(station=>glow?glowOwner(actor,entry.slot,station):ownerFor(actor,entry.slot));
   if(owners.some(o=>!o))continue;
   // An initially hidden/unattached weapon can acquire its native hand/holster
   // later without changing equipment identity. Retry at the existing cadence.
   if(owners.some(o=>o.disposed)){record.retry=true;return;}
   const owner=owners[0],scene=this.data.scene(`${ref.cate}:${ref.id}`),requestedScene=ref.scene??1;
   // Match ScenePlay's first-scene fallback before validating attachment bones.
   const selectedScene=scene.scenes?.[requestedScene]?requestedScene:Object.keys(scene.scenes||{})[0];
   const controls=scene.scenes?.[selectedScene]?.controls||[];
   // Do not relocate an authored weapon-bone effect to the torso when the native rig is absent.
   let controlFilter;
   // Per-control bone check for every slot (wing, weapon, left): a control whose bone is on no rig the item binds is omitted;
   // its siblings still play. Previously non-wing slots dropped the whole scene on one missing bone (left orb 10511, effect 48).
   // COMPATIBILITY (nativeDispatchVerified:false): see docs/WING-BINDING.md; tested by tools/test-item-fx-perbone.mjs.
   {const blocked=blockedControls(controls,owner);
    if(blocked.size){
     for(const index of blocked)(record.unresolvedBones||=[]).push({slot:entry.slot,effect:entry.id,scene:Number(selectedScene),control:index,bone:attachBoneName(controlBone(controls[index]))});
     if(!controls.some((c,index)=>c.active!==false&&!blocked.has(index)))continue;
     controlFilter=(_,index)=>!blocked.has(index);
    }
   }
   // Refinement scenes play at their authored length (lifetime 0 1000) with their authored alpha/colour keys: no invented cadence.
   // Socket pulse uses the original sprite, alpha and scale keys. Count intensity is one sprite per filled gem (stations
   // above); authored alpha/scale are never multiplied by gem count.
   // LANE-70b: stationScale (SPRITE_SPACING/MIN/MAX) and the mist depth bias are ENGINE-CHOSEN; Global plays the socket scene
   // (effectscene 7:1..6) at its authored size/scale keys and depth. gfx-B socketSpriteAuthored (default on) drops both.
   const authoredSprite=gfxB('socketSpriteAuthored');
   const depthBias=glow&&!authoredSprite?weaponDepthBias(weaponFor(actor,entry.slot)):0;
   stations.forEach((station,i)=>{
    const handle=this.fx.play(owners[i],ref,{loop:glow?true:ref.loop===0,particleSpace:'attachment',...(controlFilter?{controlFilter}:{}),...(station&&!authoredSprite?{scale:stationScale(station.spacing)}:{}),...(depthBias>0?{depthBias}:{})});
    if(handle){
     handle.equipmentSlot=entry.slot;
     // A model replacement must not restart every still-worn glow at its
     // brightest first frame. Continuous equipment scenes share the live clock.
     if(handle.loop&&Number(ref.timeMs)>0){handle.t=this.clock%(Number(ref.timeMs)/1000);handle.update?.(0);}
     record.handles.push(handle);
    }
   });
  }
  for(const entry of entries)record.completeSlots?.add(entry.slot);
 }
 dispose(){this.disposed=true;for(const actor of [...this.records.keys()])this.clear(actor);this.fx?.dispose();}
}


