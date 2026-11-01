import {atlas} from '../../ui/atlas.js';
import {hasGMPanelPermission} from './permissions.js';
import {openBuilder} from './builders.js';
import {toggleGameplayCamera} from '../hud-options/camera-controls.js';
import {bindingName} from '../hud-options/keymap.js';

const POSITION='dekaron-solo:gm-helper-position:v1';
export function helperPosition(x,y,width,height,viewportWidth,viewportHeight){
 return {x:Math.max(0,Math.min(Number.isFinite(x)?x:0,Math.max(0,viewportWidth-width))),y:Math.max(0,Math.min(Number.isFinite(y)?y:0,Math.max(0,viewportHeight-height)))};
}
/** Small original-art launcher; the authenticated server still validates every action. */
export class GMAuthorHelper {
 constructor(mode){this.mode=mode;this.gm=mode.gm;this.game=mode.game;this.disposed=false;}
 currentOriginal(){return this.game.originalMapEdits?.list().includes(Number(this.game.world?.info?.index))===true;}
 visible(){const g=this.game,n=g.network;return g.save?.authority==='server'&&n?.active===true&&n.ready===true&&!!n.token&&!n.disposed&&!n._transferring&&!!g.player&&!g.player.disposed&&g._worldReady===true&&!g._loadingMap;}
 available(){const g=this.game,n=g.network;return this.mode.available()&&g.save?.authority==='server'&&n?.active===true&&n.ready===true&&!!n.token&&!n.disposed&&!g.player?.disposed&&hasGMPanelPermission(g);}
 install(){
  const d=document,host=this.host=d.createElement('div');host.id='gm-build-controls';host.dataset.gmHelper='';host.setAttribute('aria-label','GM helper');host.hidden=true;
  host.style.cssText='position:fixed;z-index:100010;width:232px;max-width:100vw;box-sizing:border-box;padding:4px 5px;color:#e8dfc4;background:rgba(13,12,9,.45);border:5px solid rgba(130,109,64,.4);font:11px/13px Tahoma,Verdana,sans-serif;text-shadow:1px 1px #000;user-select:none;';
  const header=this.header=d.createElement('div');header.textContent='GM helper · drag';header.tabIndex=0;header.setAttribute('role','button');header.setAttribute('aria-label','Move GM helper');header.title='Drag to move; arrow keys move this helper, Shift moves faster.';header.style.cssText='cursor:move;touch-action:none;color:#d6ba72;font-weight:bold;margin-bottom:3px;';host.append(header);
  const button=(row,text,action)=>{const b=d.createElement('button');b.type='button';b.textContent=text;b.style.cssText='flex:1;min-width:0;height:19px;padding:0 3px;border:0;background:rgba(47,39,25,.5);color:#e8dfc4;font:11px Tahoma,Verdana,sans-serif;text-shadow:1px 1px #000;cursor:pointer;';b.onclick=()=>{if(!this.available())return;action();this.render(true);};row.append(b);void atlas.sprite('etc_01',2).then(s=>{if(!this.disposed&&s)b.style.background=`url("${s.url}") center/100% 100% no-repeat`;});return b;};
  host.style.transition=globalThis.matchMedia?.('(prefers-reduced-motion: reduce)').matches?'none':'opacity 220ms ease';
  host.style.opacity='.55';
  for(const event of ['pointerenter','pointerleave','focusin','focusout'])host.addEventListener(event,()=>{host.style.opacity=event==='pointerenter'||event==='focusin'||host.matches?.(':hover, :focus-within')?'1':'.55';});
  header.textContent='';header.style.display='flex';header.style.alignItems='center';header.style.gap='4px';
  this.heading=d.createElement('span');this.heading.style.flex='1';header.append(this.heading);
  this.collapse=d.createElement('button');this.collapse.type='button';this.collapse.style.cssText='width:18px;height:18px;padding:0;border:0;background:rgba(47,39,25,.7);color:#e8dfc4;cursor:pointer;font:14px Tahoma,sans-serif';header.append(this.collapse);
  this.collapse.onclick=e=>{e?.stopPropagation?.();if(!this.visible())return;this.collapsed=!this.collapsed;this.render(true);const b=host.getBoundingClientRect();this.place(b.left,b.top);this.savePosition();};
  this.rows=[];
  const row=()=>{const r=d.createElement('div');r.style.cssText='display:flex;gap:3px;margin:2px 0;';host.append(r);this.rows.push(r);return r;};
  const main=row();this.tools=button(main,'GM Tools',()=>this.gm.togglePanel());this.pov=button(main,'First-person',()=>{if(this.mode.active)this.mode.set(false);if(this.gm.freecam.on)this.gm.freecam.set(false);this.mode.resetInput();toggleGameplayCamera(this.game);});
  const editors=row();this.map=button(editors,'Map',()=>void openBuilder(this.game,'mapbuilder',{currentOriginal:this.currentOriginal()}).catch(e=>this.gm.say(e.message)));this.item=button(editors,'Item',()=>void openBuilder(this.game,'itembuilder').catch(e=>this.gm.say(e.message)));this.fly=button(editors,'Fly',()=>this.mode.set(!this.mode.active));
  this.hints=d.createElement('div');this.hints.style.cssText='color:#b3aa91;margin-top:3px;white-space:pre-line;';host.append(this.hints);
  for(const event of ['pointerdown','pointerup','mousedown','mouseup','click','dblclick','wheel','contextmenu'])host.addEventListener(event,e=>{e.stopPropagation();if(event==='contextmenu')e.preventDefault();},{passive:event==='wheel'});
  this.start=e=>{if(this.drag||e.target===this.collapse||e.button!==0||!this.visible())return;e.preventDefault();e.stopPropagation();header.focus?.();const b=host.getBoundingClientRect();this.drag={id:e.pointerId??'mouse',x:e.clientX,y:e.clientY,left:b.left,top:b.top};if(e.pointerId!=null)header.setPointerCapture?.(e.pointerId);this.mode.resetInput();};
  this.move=e=>{if(!this.drag||(e.pointerId??'mouse')!==this.drag.id)return;if(!this.visible()){this.endDrag(true);return;}e.preventDefault();this.place(this.drag.left+e.clientX-this.drag.x,this.drag.top+e.clientY-this.drag.y);};
  this.up=e=>{if(this.drag&&(e.pointerId??'mouse')===this.drag.id)this.endDrag(false);};this.cancel=e=>{if(this.drag&&(e.pointerId??'mouse')===this.drag.id)this.endDrag(true);};
  // Capture release before the helper's UI isolation stops bubbling to gameplay.
  header.addEventListener('pointerdown',this.start);header.addEventListener('lostpointercapture',this.cancel);window.addEventListener('pointermove',this.move,true);window.addEventListener('pointerup',this.up,true);window.addEventListener('pointercancel',this.cancel,true);
  header.addEventListener('mousedown',this.start);window.addEventListener('mousemove',this.move,true);window.addEventListener('mouseup',this.up,true);
  header.addEventListener('keydown',e=>{if(e.target===this.collapse||!this.visible()||!['ArrowLeft','ArrowRight','ArrowUp','ArrowDown'].includes(e.code))return;e.preventDefault();e.stopPropagation();const b=host.getBoundingClientRect(),step=e.shiftKey?10:1;this.place(b.left+(e.code==='ArrowLeft'?-step:e.code==='ArrowRight'?step:0),b.top+(e.code==='ArrowUp'?-step:e.code==='ArrowDown'?step:0));this.savePosition();});
  this.resize=()=>{const b=host.getBoundingClientRect();this.place(b.left,b.top);};this.blur=()=>this.endDrag(true);window.addEventListener('resize',this.resize);window.addEventListener('blur',this.blur);
  d.body.append(host);let saved;try{saved=JSON.parse(localStorage.getItem(POSITION)||'null');}catch{}this.collapsed=saved?.collapsed===true;this.place(saved?.x??Math.max(0,(globalThis.innerWidth||1024)-246),saved?.y??96);
  // Tint the original tooltip frame, keeping its authored nine-slice alpha.
  void atlas.tinted('etc_01',66,'b3ffffff').then(s=>{if(this.disposed||!s)return;const[l,t,r,b]=s.row.m;host.style.borderImage=`url("${s.url}") ${t} ${r} ${b} ${l} fill / ${t}px ${r}px ${b}px ${l}px stretch`;host.style.background='none';host.dataset.originalArt='etc_01#66';});
  this.render();return this;
 }
 place(x,y){if(!this.host)return;const b=this.host.getBoundingClientRect(),p=helperPosition(x,y,b.width||(this.collapsed?32:232),b.height||(this.collapsed?30:104),globalThis.innerWidth||1024,globalThis.innerHeight||768);this.host.style.left=`${p.x}px`;this.host.style.top=`${p.y}px`;}
 savePosition(){const b=this.host.getBoundingClientRect();try{localStorage.setItem(POSITION,JSON.stringify({x:b.left,y:b.top,collapsed:!!this.collapsed}));}catch{}}
 endDrag(cancel=false){const drag=this.drag;if(!drag)return;this.drag=null;if(cancel)this.place(drag.left,drag.top);else this.savePosition();try{this.header.releasePointerCapture?.(drag.id);}catch{}this.mode.resetInput();}
 render(force=false){
  if(!this.host||this.disposed)return;const available=this.available(),visible=this.visible(),wasHidden=this.host.hidden;this.host.hidden=!visible;
  if(!visible){this.endDrag(true);this.hints.textContent='';this._rendered=null;return;}
  if(wasHidden&&globalThis.requestAnimationFrame){this.host.style.opacity='0';requestAnimationFrame(()=>{if(!this.disposed&&!this.host.hidden)this.host.style.opacity=this.host.matches?.(':hover, :focus-within')?'1':'.55';});}
  for(const button of [this.tools,this.pov,this.map,this.item,this.fly])button.hidden=!available||!!this.collapsed;
  for(const row of this.rows){row.hidden=!available||!!this.collapsed;row.style.display=row.hidden?'none':'flex';}
  this.hints.hidden=!!this.collapsed;this.heading.hidden=!!this.collapsed;
  this.host.style.width=this.collapsed?'32px':'232px';this.host.style.padding=this.collapsed?'1px':'4px 5px';
  this.header.style.marginBottom=this.collapsed?'0':'3px';
  this.collapse.textContent=this.collapsed?'+':'−';this.collapse.title=this.collapsed?'Restore helper':'Minimize helper';this.collapse.setAttribute('aria-label',this.collapse.title);this.collapse.setAttribute('aria-expanded',String(!this.collapsed));
  this.heading.textContent=available?'GM helper · drag':'POV';
  this.header.tabIndex=0;this.header.setAttribute('aria-label','Move helper');
  this.host.setAttribute('aria-label',available?'GM helper':'POV key binding');
  if(!available){const binding=this.game.keymap?.get('cameraView');this.hints.textContent=`POV ${binding?bindingName(binding):'unbound'}`;this._rendered=null;return;}
  const g=this.game,first=g.cam.mode==='first-person',open=!!this.gm.panel?.isOpen,binding=g.keymap?.get('cameraView'),name=bindingName(binding);
  const nativeEditing=!!g.originalSceneEditor?.active,povReady=!!g.options&&!!g.cam.setMode&&!g.player.dead&&!g.paused&&!g.uiwin?.capturesInput&&g.input?.enabled!==false&&!nativeEditing;
  const currentOriginal=this.currentOriginal(),state=`${this.mode.active}:${first}:${open}:${binding}:${povReady}:${!!g.customMaps?.openBuilder}:${!!g.customItems?.openBuilder}:${currentOriginal}:${nativeEditing}`;if(!force&&state===this._rendered)return;this._rendered=state;
  this.tools.textContent=open?'Close GM Tools':'GM Tools';this.tools.setAttribute('aria-pressed',String(open));this.tools.title='Open or close Command Center · F10';
  this.pov.textContent=first?'Third-person':'First-person';this.pov.setAttribute('aria-pressed',String(first));this.pov.disabled=!povReady;this.pov.title=povReady?`Character POV · saved binding: ${name}`:'Close the current dialog and return to a living character to change POV.';
  this.fly.textContent=this.mode.active?'Return':'Fly';this.fly.setAttribute('aria-pressed',String(this.mode.active));this.fly.title='GM fly camera · Right Alt / Esc returns';
  this.map.disabled=!currentOriginal&&!g.customMaps?.openBuilder;this.map.textContent=currentOriginal?(nativeEditing?'Editing':'Edit current'):'Custom maps';this.item.disabled=!g.customItems?.openBuilder;this.map.title=currentOriginal?'Edit the current native field from your standing character':'Map Builder · publish saved custom-map revisions';this.item.title='Item Builder';
  for(const button of [this.tools,this.pov,this.map,this.item,this.fly]){button.style.opacity=button.disabled?'.45':'1';button.style.cursor=button.disabled?'default':'pointer';}
  this.hints.textContent=this.mode.active?'WASD fly · Q/E height · Shift boost\nRight-drag look · Right Alt / Esc return':`F10 tools · POV ${binding?name:'unbound'}\nRight Alt fly · Map/Item editors`;
 }
 dispose(){if(this.disposed)return;this.endDrag(true);this.disposed=true;this.host?.remove();window.removeEventListener('pointermove',this.move,true);window.removeEventListener('pointerup',this.up,true);window.removeEventListener('pointercancel',this.cancel,true);window.removeEventListener('mousemove',this.move,true);window.removeEventListener('mouseup',this.up,true);window.removeEventListener('resize',this.resize);window.removeEventListener('blur',this.blur);}
}
