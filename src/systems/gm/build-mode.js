import {hasGMPanelPermission} from './permissions.js';
import {GMAuthorHelper} from './author-helper.js';
const navigationKeys=new Set(['KeyW','KeyA','KeyS','KeyD','KeyQ','KeyE','ShiftLeft','ShiftRight','Space','KeyC','ArrowUp','ArrowDown','ArrowLeft','ArrowRight']);
const typing=()=>{const a=globalThis.document?.activeElement;return !!a&&(a.isContentEditable||/^(INPUT|TEXTAREA|SELECT)$/.test(a.tagName));};
export class GMBuildMode {
 constructor(gm){this.gm=gm;this.game=gm.game;this.active=false;this.keys=new Set();}
 available(){const g=this.game,n=g.network,connected=g.save?.authority==='server'?n?.active===true&&n.ready===true&&!!n.token&&!n.disposed:(!n?.active||n.ready);return hasGMPanelPermission(g)&&!!g.player&&!g.player.disposed&&!!g.world&&!!g.controller&&!!g.camera&&!!g.cam&&g._worldReady===true&&!g._loadingMap&&!n?._transferring&&connected;}
 resetInput(){const i=this.game.input;this.keys.clear();for(const set of [i?.keys,i?.pressed,i?.released])set?.clear?.();if(i){i.clicks?.splice(0);for(const key of ['left','right','middle']){if(i.held)i.held[key]=false;if(i.dragging)i.dragging[key]=false;}if(i.mouse){i.mouse.dx=0;i.mouse.dy=0;i.mouse.wheel=0;}i._down={};}if(this.game.controller)this.game.controller._wasd=false;}
 set(on){
  on=!!on;if(on===this.active)return this.active;if(on&&!this.available())return false;
  const author=this.game.originalSceneEditor;
  if(!on&&!this._returning&&author?.active){if(author.valid()){void author.requestExit().catch(error=>this.gm.say(error.message));return this.active;}author.abort();}
  if(!on&&!this._returning&&this.available()&&this.game._returnOriginalEditor&&document.getElementById('gm-map-builder')?.querySelector('iframe')?.contentWindow?.mapbuilder?.editor?.originalLive?.active){void this.game._returnOriginalEditor().catch(error=>this.gm.say(error.message));return this.active;}
  if(!on&&!this.available()&&this.game._returnOriginalEditor){globalThis.document?.getElementById?.('gm-map-builder')?.remove();this.game._returnOriginalEditor=null;}
  const g=this.game;if(!on)g.controller?.stop?.();this.resetInput();this.active=on;
  if(on){this.world=g.world;this.controller=g.controller;this.map=g.world.info?.index;if(this.gm.freecam.on)g.controller?.stop?.();this.gm.freecam.set(true);this.gm.freecam._editorKeys=this.keys;this.gm.freecam.pos.set(g.player.x,(g.player.y||0)+1.8,-g.player.z);}
  else{this.gm.freecam._editorKeys=null;this.gm.freecam.set(false);if(g._worldReady&&!g._loadingMap)g.cam?.snap?.();}
  this.render();return this.active;
 }
 install(){
  const d=document;this.helper=new GMAuthorHelper(this).install();this.host=this.helper.host;
  this.onKey=e=>{if(this.game.originalSceneEditor?.handleKey(e))return;if(e.code==='AltRight'&&!e.repeat&&!typing()){if(!this.available()&&!this.active)return;e.preventDefault();e.stopImmediatePropagation();this.set(!this.active);return;}if(!this.active)return;if(typing())return;if(e.code==='Escape'){e.preventDefault();e.stopImmediatePropagation();this.set(false);return;}if(e.target?.closest?.('[data-gm-helper]'))return;e.preventDefault();e.stopImmediatePropagation();if(navigationKeys.has(e.code))this.keys.add(e.code);};
  this.onUp=e=>{this.keys.delete(e.code);};this.onBlur=()=>this.resetInput();this.onFocus=()=>{if(typing())this.resetInput();};this.onVisibility=()=>{if(d.hidden)this.resetInput();};
  window.addEventListener('keydown',this.onKey,true);window.addEventListener('keyup',this.onUp,true);window.addEventListener('blur',this.onBlur);d.addEventListener('focusin',this.onFocus);d.addEventListener('visibilitychange',this.onVisibility);this.render();
 }
 render(){this.helper?.render();}
 update(){if(this.active&&(!this.available()||!this.gm.freecam.on||this.world!==this.game.world||this.controller!==this.game.controller||this.map!==this.game.world?.info?.index))this.set(false);this.render();}
 dispose(){this.set(false);this.helper?.dispose();if(!this.onKey)return;window.removeEventListener('keydown',this.onKey,true);window.removeEventListener('keyup',this.onUp,true);window.removeEventListener('blur',this.onBlur);document.removeEventListener('focusin',this.onFocus);document.removeEventListener('visibilitychange',this.onVisibility);}
}
