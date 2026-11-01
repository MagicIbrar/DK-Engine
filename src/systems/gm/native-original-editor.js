import * as THREE from 'three';
import {beginOriginalLive} from '../mapbuilder/editor/original-live.js';
import {Brushes} from '../mapbuilder/editor/brushes.js';
import {History} from '../mapbuilder/editor/history.js';
import {captureCurrentFieldView,placeCurrentFieldView} from '../mapbuilder/editor/current-field-view.js';
import {hasGMPanelPermission} from './permissions.js';
const tools=['raise','lower','smooth','flatten','noise'];
const typing=()=>{const a=document.activeElement;return !!a&&(a.isContentEditable||/^(INPUT|TEXTAREA|SELECT)$/.test(a.tagName));};
const reject=message=>{throw Error(message);};
function supported(state,world){return state?.index===150&&state.scope?.format==='ardeca-height-scope@1'&&state.scope.fields?.length===1&&state.scope.fields[0]==='heights'&&state.scope.width===world.map.width&&state.scope.height===world.map.height&&Array.isArray(state.scope.protectedRuns);}
/** Small authoring adapter over the real Game. Draft math stays separate from
 * native arrays; the existing network adapter renders accepted generations. */
export class NativeOriginalEditor {
 constructor(game){
  this.game=game;this.api=game.originalMapEdits;this.network=game.network;this.lease=this.network?.token;this.world=game.world;this.controller=game.controller;this.index=Number(this.world?.info?.index);this.sourceHash=this.world?.info?.originalEdit?.sourceHash;this.mode=game.gm?.buildMode;this.cam=game.gm?.freecam;
  this.canvas=game.input?.canvas||game.renderer?.domElement;this.active=true;this.opened=false;this.aborted=false;this.listeners=[];this.events=new Map();this.tool='raise';this.toolOpts={radius:2,strength:3};this.history=new History(()=>this.refresh());this.brushes=new Brushes(this);this.view={updateVertices:()=>{this.dirty=true;}};this.objects={terrainChanged(){}};
  this.returnHook=()=>this.requestExit();
 }
 valid(){const g=this.game,n=this.network;return this.active&&!this.aborted&&g.world===this.world&&g.controller===this.controller&&g.originalMapEdits===this.api&&g.network===n&&n?.active===true&&n.ready===true&&n.token===this.lease&&!n.disposed&&!n._transferring&&g._worldReady===true&&!g._loadingMap&&Number(g.world?.info?.index)===this.index&&g.world.info.originalEdit?.sourceHash===this.sourceHash&&g.player&&!g.player.disposed&&hasGMPanelPermission(g)&&g.accountPermissions?.capabilities?.includes('gm:commands');}
 leaseValid(){const g=this.game,n=this.network;return g.originalMapEdits===this.api&&g.network===n&&n?.active===true&&n.ready===true&&n.token===this.lease&&!n.disposed&&hasGMPanelPermission(g)&&g.accountPermissions?.capabilities?.includes('gm:commands');}
 async request(op,args,context=true){const guard=()=>context?this.valid():this.leaseValid();if(!guard())reject('The original editor lease or context changed.');const result=await this.api[op](...args,{lease:this.lease,guard});if(!guard())reject('The original editor lease or context changed.');return result;}
 on(event,fn){const set=this.events.get(event)||new Set();this.events.set(event,set);set.add(fn);return()=>set.delete(fn);}
 emit(event,...args){for(const fn of this.events.get(event)||[])fn(...args);}
 async _buildAll(){if(!this.valid())reject('The current native field or editor lease changed.');if(this.doc.width!==this.world.map.width||this.doc.height!==this.world.map.height)reject('Native source dimensions changed.');this.history.clear();}
 syncCamera(){this.cam._update(0);}
 cancelInput(){this.endStroke();this.mode?.resetInput();}
 endStroke(){if(this.stroking){this.brushes.endStroke();this.stroking=false;}this.refresh();}
 bind(target,event,fn,options){const settings=typeof options==='boolean'?{capture:options}:options;target.addEventListener(event,fn,settings);this.listeners.push(()=>target.removeEventListener(event,fn,settings));}
 setStatus(message){if(this.status)this.status.textContent=message;this.refresh();}
 refresh(){if(!this.buttons)return;const busy=!this.opened||!!this.finishing;for(const b of this.buttons)b.disabled=busy||!!this.exitPrompt&&!Object.values(this.exitChoices||{}).includes(b);this.undo.disabled=busy||!!this.exitPrompt||!this.history.canUndo;this.redo.disabled=busy||!!this.exitPrompt||!this.history.canRedo;}
 installPanel(){
  const host=this.host=document.createElement('div');host.id='gm-current-map-editor';host.dataset.gmHelper='';host.setAttribute('aria-label','Edit current native field');host.style.cssText='position:fixed;z-index:100020;left:12px;bottom:84px;width:390px;max-width:calc(100vw - 24px);padding:8px;box-sizing:border-box;background:rgba(13,12,9,.85);border:1px solid #826d40;color:#e8dfc4;font:12px Tahoma,Verdana,sans-serif;';
  this.buttons=[];const header=document.createElement('div');header.style.cssText='display:flex;align-items:center;justify-content:space-between;margin-bottom:6px';const title=document.createElement('strong');title.textContent=`Edit current · ${this.world.info.name||'Ardeca'} #${this.index}`;header.append(title);this.exitButton=document.createElement('button');this.exitButton.textContent='Exit';this.exitButton.title='Return to your character; choose Save or Discard if edits are unsaved';this.exitButton.onclick=()=>{if(!this.exitButton.disabled)void this.requestExit().catch(e=>this.setStatus(e.message));};header.append(this.exitButton);host.append(header);this.buttons.push(this.exitButton);
  const select=document.createElement('select');select.setAttribute('aria-label','Height brush');for(const name of tools){const o=document.createElement('option');o.value=name;o.textContent=name[0].toUpperCase()+name.slice(1);select.append(o);}select.value=this.tool;select.onchange=()=>{this.cancelInput();this.tool=select.value;};host.append(select);this.buttons.push(select);
  for(const [key,label,min,max,step]of [['radius','Radius',.5,4,.5],['strength','Strength',.1,8,.1]]){const text=document.createElement('label');text.textContent=label+' ';const input=document.createElement('input');input.type='number';input.min=String(min);input.max=String(max);input.step=String(step);input.value=String(this.toolOpts[key]);input.style.width='48px';input.setAttribute('aria-label',label);input.onchange=()=>{this.cancelInput();this.toolOpts[key]=Math.max(min,Math.min(max,Number(input.value)||min));input.value=String(this.toolOpts[key]);};text.append(input);host.append(text);this.buttons.push(input);}
  const action=(label,fn)=>{const b=document.createElement('button');b.textContent=label;b.onclick=()=>{if(b.disabled)return;void Promise.resolve().then(fn).catch(e=>this.setStatus(e.message));};host.append(b);this.buttons.push(b);return b;};
  this.undo=action('Undo',()=>{this.cancelInput();this.history.undo();});this.redo=action('Redo',()=>{this.cancelInput();this.history.redo();});action('Save & return',()=>this.finish(true));action('Cancel & return',()=>this.finish(false));
  const hint=document.createElement('div');hint.textContent='Left-drag brush · right-drag look · WASD/QE fly · Ctrl+Z undo · Right Alt/Esc return';host.append(hint);this.status=document.createElement('div');this.status.textContent='Connecting to the current field…';host.append(this.status);
  for(const name of ['mousedown','mouseup','click','dblclick','wheel','contextmenu'])host.addEventListener(name,e=>{e.stopPropagation();if(name==='contextmenu')e.preventDefault();});document.body.append(host);this.refresh();
 }
 async open(){
  if(this.index!==150||!this.api?.list().includes(this.index)||!this.mode?.available()||!this.canvas||typeof this.game.pickGround!=='function'||!this.valid())reject('Native current-field editing requires loaded, source-approved Ardeca 150 and a live GM lease.');
  const preview=await this.request('read',[this.index]);if(!this.valid()||!supported(preview,this.world)||preview.sourceHash!==this.sourceHash)reject('This native field does not have the reviewed protected height scope.');
  this.mode.set(true);this.installPanel();this.game._returnOriginalEditor=this.returnHook;this.mode.render();
  // beginOriginalLive still owns source identity, scoped brush streaming and
  // Save/Cancel. Its adapter build above creates no scene, camera or renderer.
  const api={...this.api,read:index=>this.request('read',[index]),patch:input=>this.request('patch',[input]),finish:input=>this.request('finish',[input],false),sourceHash:async(...args)=>{if(!this.valid())reject('The original editor lease or context changed.');const hash=await this.api.sourceHash(...args);if(!this.valid())reject('The original editor lease or context changed.');return hash;},begin:async index=>{const state=await this.request('begin',[index]);if(!supported(state,this.world)||state.sourceHash!==this.sourceHash){await this.request('finish',[{session:state.session,epoch:state.epoch,expectedVersion:state.version,save:false}],false);reject('The protected native editing scope changed.');}return state;}};
  const live=await beginOriginalLive(this,api,message=>this.setStatus(message));
  if(!this.valid()){try{await live.finish(false);}finally{live.dispose();}reject('The native editor context changed while opening.');}
  this.initialHeights=this.doc.heights.slice();this.opened=true;if(this.game.gm.panel?.isOpen)this.game.uiwin?.close?.('gmpanel');this.installInput();this.installCursor();this.mode.render();this.refresh();this.lastTime=performance.now();
  const frame=time=>{if(!this.active)return;this.raf=requestAnimationFrame(frame);const dt=Math.max(0,Math.min(.05,(time-this.lastTime)/1000));this.lastTime=time;try{this.update(dt);}catch(e){this.setStatus(e.message);this.abort();}};this.raf=requestAnimationFrame(frame);return this;
 }
 installCursor(){this.cursor=new THREE.Mesh(new THREE.RingGeometry(.94,1,48),new THREE.MeshBasicMaterial({color:0xd6ba72,transparent:true,opacity:.85,depthTest:false,side:THREE.DoubleSide,toneMapped:false}));this.cursor.name='GM native height brush cursor';this.cursor.rotation.x=-Math.PI/2;this.cursor.renderOrder=10000;this.cursor.visible=false;(this.game.worldRoot||this.world.root).add(this.cursor);}
 groundAt(clientX,clientY){const r=this.canvas.getBoundingClientRect();if(!(r.width>0&&r.height>0)||clientX<r.left||clientY<r.top||clientX>r.left+r.width||clientY>r.top+r.height)return null;return this.game.pickGround({x:(clientX-r.left)/r.width*2-1,y:-(clientY-r.top)/r.height*2+1});}
 installInput(){
  this.bind(this.canvas,'mousedown',e=>{if(e.button!==0){this.endStroke();return;}e.preventDefault();e.stopImmediatePropagation();this.canvas.focus?.();this.point={x:e.clientX,y:e.clientY};if(!this.valid()||this.exitPrompt||this.game.paused||this.game.network.self?.originalEditPending||this.game.uiwin?.capturesInput||typing())return;const p=this.groundAt(e.clientX,e.clientY);if(!p)return;this.brushes.beginStroke(this.tool,p.x,p.z,this.toolOpts);this.stroking=true;},true);
  this.bind(window,'mousemove',e=>{if(e.target===this.canvas)this.point={x:e.clientX,y:e.clientY};else{this.point=null;this.endStroke();}});
  this.bind(window,'mouseup',e=>{if(e.button===0&&this.stroking){e.preventDefault();e.stopImmediatePropagation();this.endStroke();}},true);
  this.bind(this.canvas,'mouseleave',()=>{this.point=null;this.endStroke();});this.bind(window,'blur',()=>{this.point=null;this.cancelInput();});this.bind(document,'visibilitychange',()=>{if(document.hidden){this.point=null;this.cancelInput();}});this.bind(document,'focusin',()=>{if(typing()){this.point=null;this.cancelInput();}});
 }
 handleKey(e){if(!this.opened||!this.active||this.exitPrompt||typing()||!(e.ctrlKey||e.metaKey)||!['KeyZ','KeyY'].includes(e.code))return false;e.preventDefault();e.stopImmediatePropagation();this.cancelInput();if(e.code==='KeyY'||e.shiftKey)this.history.redo();else this.history.undo();return true;}
 update(dt){
  if(!this.valid()||!this.cam.on||!this.mode.active){this.abort();return;}
  if(this.finishing||this.exitPrompt||typing()||this.game.uiwin?.capturesInput||document.hidden||!document.hasFocus()){this.endStroke();if(this.cursor)this.cursor.visible=false;return;}
  if(this.game.paused||this.network.self?.originalEditPending){if(this.cursor)this.cursor.visible=false;return;}
  const p=this.point&&this.groundAt(this.point.x,this.point.y);if(this.cursor){this.cursor.visible=!!p;if(p){this.cursor.position.set(p.x,p.y+.05,p.z);this.cursor.scale.setScalar(this.toolOpts.radius);}}
  if(this.stroking&&p)this.brushes.applyAt(p.x,p.z,dt,this.toolOpts);
 }
 async requestExit(){
  if(this.finishing)return this.finishing;if(!this.opened)return this.finish(false);this.cancelInput();
  if(!this.doc.heights.some((y,i)=>y!==this.initialHeights[i]))return this.finish(false);
  if(this.exitPrompt)return;
  const prompt=this.exitPrompt=document.createElement('div');prompt.setAttribute('role','alert');prompt.textContent='Unsaved shared changes. Save or discard before returning to your character.';prompt.style.cssText='margin-top:6px;padding:6px;border:1px solid #d6ba72';this.host.append(prompt);this.exitChoices={};
  for(const [key,label,choice]of [['save','Save & exit',true],['discard','Discard & exit',false],['stay','Keep editing',null]]){const button=document.createElement('button');button.textContent=label;button.onclick=()=>{if(button.disabled)return;if(choice===null){prompt.remove();this.buttons=this.buttons.filter(b=>!Object.values(this.exitChoices).includes(b));this.exitPrompt=null;this.exitChoices=null;this.refresh();return;}void this.finish(choice).catch(e=>this.setStatus(e.message));};prompt.append(button);this.exitChoices[key]=button;this.buttons.push(button);}this.refresh();
 }
 finish(save){
  if(this.finishing)return this.finishing;
  this.finishing=(async()=>{if(!this.opened)await this.ready;if(!this.active)return;this.cancelInput();if(!this.valid())reject('The editor authority or native scene changed.');await this.originalLive.finish(!!save);this.cleanup(true);})().finally(()=>{this.finishing=null;this.refresh();});this.refresh();return this.finishing;
 }
 abort(){if(!this.active)return;this.aborted=true;this.endStroke();const live=this.originalLive;
  // A valid remaining lease may cancel; a revoked/swapped lease is never reused.
  if(live?.active&&this.leaseValid())void live.finish(false).catch(()=>{}).finally(()=>live.dispose());else live?.dispose();this.cleanup(true);
 }
 cleanup(returnCharacter){
  this.active=false;this.opened=false;this.endStroke();if(this.raf!=null)cancelAnimationFrame(this.raf);for(const off of this.listeners.splice(0))off();this.events.clear();this.host?.remove();if(this.cursor){this.cursor.removeFromParent();this.cursor.geometry.dispose();this.cursor.material.dispose();this.cursor=null;}
  if(this.game.originalSceneEditor===this)this.game.originalSceneEditor=null;if(this.game._returnOriginalEditor===this.returnHook)this.game._returnOriginalEditor=null;
  if(returnCharacter&&this.mode){this.mode._returning=true;try{this.mode.set(false);}finally{this.mode._returning=false;}}this.mode?.render();
 }
}
export async function openNativeOriginalEditor(game){
 const existing=game.originalSceneEditor;
 if(existing?.active){
  if(!existing.valid())reject('The previous native editor context changed. Return before reopening.');
  // Every current-field click starts at the character, including an open draft.
  const pose=captureCurrentFieldView(game);await existing.ready;
  if(!existing.valid())reject('The previous native editor context changed. Return before reopening.');
  placeCurrentFieldView(existing,pose);return existing;
 }
 const editor=new NativeOriginalEditor(game);game.originalSceneEditor=editor;editor.ready=editor.open();try{return await editor.ready;}catch(error){editor.abort();throw error;}
}
