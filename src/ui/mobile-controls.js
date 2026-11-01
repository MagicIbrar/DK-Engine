import { UIList, UITree } from './uiwin/lists.js';
import {positionMobileMenu} from './mobile-menu-position.js';

// Touch is an input adapter, never a second movement/combat or item authority.
export function touchControlsAvailable(win = globalThis) {
  return (win.navigator?.maxTouchPoints || 0) > 0 || !!win.matchMedia?.('(pointer: coarse)')?.matches;
}

export function installMobileControls(game, { doc = document, win = window } = {}) {
  if (!touchControlsAvailable(win) || !game?.input) return null;
  const input = game.input, canvas = input.canvas;
  const later = win.setTimeout?.bind(win) || setTimeout, clear = win.clearTimeout?.bind(win) || clearTimeout;
  // ENGINE-CHOSEN touch thresholds. Native controller owns paths, range and costs.
  const HOLD_MS = 300, ITEM_HOLD_MS = 600, TAP_SLOP = 8, CAMERA_PAN = 1.18;
  const root = doc.createElement('div');root.className = 'dk-mobile-controls';root.setAttribute('aria-label','Touch game controls');
  doc.body.classList?.add?.('dk-touch-ui');
  const rail = doc.createElement('div');rail.className = 'dk-mobile-actions';root.appendChild(rail);
  const extra = doc.createElement('div');extra.className = 'dk-mobile-extra';extra.hidden = true;root.appendChild(extra);
  // The original game menu, chat and hotbar already accept taps. Keep their
  // screen space clear; the extra touch actions live behind one small button.
  const bar = doc.createElement('div');bar.className = 'dk-mobile-skills';extra.appendChild(bar);
  let disposed = false, page = 0, menuPosition=null;const buttonTouches=new Map();
  let armedModifiers={shift:false,ctrl:false},activeModifiers=null,armedScope=null;const modifiedEvents=new Map(),modifierMethods=[];
  const button = (parent,label,title,action,cls='') => {
    const el = doc.createElement('button');el.type='button';el.className=('dk-mobile-button '+cls).trim();el.textContent=label;el.setAttribute('aria-label',title);
    let suppressTouch=null;
    el.addEventListener('pointerdown',e=>{e.stopPropagation();if(e.pointerType!=='touch')return;suppressTouch=null;if(e.isPrimary===false||allTouches.size>1)return;buttonTouches.set(el,{id:e.pointerId,x:e.clientX,y:e.clientY,canceled:false});});
    el.addEventListener('pointermove',e=>{const t=buttonTouches.get(el);if(t?.id===e.pointerId&&Math.hypot(e.clientX-t.x,e.clientY-t.y)>TAP_SLOP)t.canceled=true;});
    const endButton=(e,canceled=false)=>{const t=buttonTouches.get(el);if(e.pointerType!=='touch'||t?.id!==e.pointerId)return;buttonTouches.delete(el);suppressTouch={id:e.pointerId,until:Date.now()+900};const r=el.getBoundingClientRect();if(canceled||t.canceled||disposed||e.clientX<r.left||e.clientY<r.top||e.clientX>r.left+r.width||e.clientY>r.top+r.height)return;e.preventDefault();e.stopPropagation();action(e);};
    el.addEventListener('pointerup',e=>endButton(e));el.addEventListener('pointercancel',e=>endButton(e,true));el.addEventListener('lostpointercapture',e=>endButton(e,true));
    el.addEventListener('click',e=>{e.preventDefault();e.stopPropagation();if(suppressTouch&&Date.now()<suppressTouch.until&&(e.pointerType==='touch'&&e.pointerId===suppressTouch.id||e.sourceCapabilities?.firesTouchEvents))return;if(!disposed)action(e);});parent.appendChild(el);return el;
  };
  const closePanels = () => {extra.hidden=true;panels.setAttribute('aria-expanded','false');};
  const menuControl=id=>game.uiwin?.window?.('hud_mainmenu')?.find?.(id);
  // The original HUD button also owns native fallback actions (for example
  // Stats). Preserve that handler chain rather than only direct menu bindings.
  const openNative = id => {const ctrl=menuControl(id);if(ctrl?.emit){if(ctrl.enabled!==false)ctrl.emit('click');}else game.uiwin?.menuAction(id);closePanels();};
  const panels = button(rail,'Panels','Open game panels',()=>{extra.hidden=!extra.hidden;panels.setAttribute('aria-expanded',String(!extra.hidden));menuPosition?.layout();});panels.setAttribute('aria-expanded','false');
  button(extra,'Bag','Open inventory',()=>openNative('btn_inven'));
  button(extra,'Map','Open map',()=>openNative('btn_map'));
  button(extra,'Chat','Open chat',()=>{closePanels();if(game.chat?.openInput)game.chat.openInput();else game.hud?.focusChat?.();});
  for (const [label,id] of [['Stats','btn_character'],['Skills','btn_skill'],['Quests','btn_quest'],['Party','btn_party'],['Guild','btn_guild'],['Expedition','btn_expedition'],['Friends','btn_mail'],['Pet bag','btn_petinven'],['Mounts','btn_ride'],['Craft','btn_craft'],['Shop','btn_personalshop'],['D-Shop','btn_cash'],['Cash bag','btn_cashinven'],['VIP shop','btn_vipshop'],['Supply','btn_supplymachine'],['Orbis','btn_single_supplymachine'],['Ride','btn_vehicle'],['Summon pet','btn_petsummon'],['Fish','btn_fishing'],['Menu','btn_escoption']])if(menuControl(id)||!game.uiwin?.hasMenuButton||game.uiwin.hasMenuButton(id))button(extra,label,'Open '+label.toLowerCase(),()=>openNative(id));
  button(extra,'Pick','Pick up nearby item',()=>{game.controller?.pickupNearby();closePanels();});
  button(extra,'Stop','Stop moving and attacking',()=>{reset();game.controller?.stop();closePanels();});
  const shiftButton=button(extra,'Shift','Use Shift for the next touch: split stacks, link items, option ranges or ten stat points',()=>{armedModifiers.shift=!armedModifiers.shift;armedScope=scope();paintModifiers();});
  const ctrlButton=button(extra,'Ctrl','Use Ctrl for the next touch: compare, copy equipment preset or ordinary Force Attack',()=>{armedModifiers.ctrl=!armedModifiers.ctrl;armedScope=scope();paintModifiers();});
  const modifierState=doc.createElement('div');modifierState.className='dk-mobile-modifier-state';modifierState.setAttribute('aria-live','polite');root.appendChild(modifierState);
  function paintModifiers(){shiftButton.setAttribute('aria-pressed',String(armedModifiers.shift));ctrlButton.setAttribute('aria-pressed',String(armedModifiers.ctrl));const m=activeModifiers||armedModifiers;modifierState.hidden=!(m.shift||m.ctrl);modifierState.textContent=[m.ctrl&&'Ctrl',m.shift&&'Shift'].filter(Boolean).join('+')+' next';}
  paintModifiers();
  const playable = () => !disposed&&!doc.hidden&&input.enabled!==false&&game.player&&!game.player.dead&&!game.player.disposed&&!game.controller?._inputBlocked?.()&&!(game.network?.active&&!game.network.ready);
  const skills = Array.from({length:6},(_,i)=>button(bar,String(i+1),'Use hotbar slot '+(i+1),e=>{if(!playable())return;takeModifiers(e);try{if(game.quickslot?.useCell){game.quickslot.useCell(0,page+i);return;}const slots=game.save?.hotbar;if(Array.isArray(slots)){const entry=slots[page+i];if(entry)game.skills?.use(entry);}else game.skills?.use(page+i);}finally{if(activeModifiers){activeModifiers.ending=true;activeModifiers.order=game.controller?.order?.networkSkill?game.controller.order:null;}}},'skill'));
  button(bar,'1–6','Switch hotbar slots',()=>{page=page?0:6;for(let i=0;i<skills.length;i++){skills[i].textContent=String(page+i+1);skills[i].setAttribute('aria-label','Use hotbar slot '+(page+i+1));}pageButton.textContent=page?'7–12':'1–6';},'page');
  const pageButton = bar.children[bar.children.length-1];
  const hint=doc.createElement('div');hint.className='dk-mobile-hint';hint.textContent='Tap ground to move; hold to follow your finger. Tap a monster to select, tap it again to attack. Two fingers drag or turn the camera; pinch to zoom. Hold a bag or equipped item to pick it up, then drag and release to place or equip it. Hold shop items for their normal right action. Shift/Ctrl apply once to the next touch. Shift: split, link or options. Ctrl: compare or preset copy. A modified item hold shows its tooltip.';extra.appendChild(hint);

  const points=new Map(),allTouches=new Set(),uiTouches=new Map();let single=null,pair=null,chord=false,touchLeft=false,touchRight=false,ui=null,swallow=null;
  const recentUiReleases=[];
  const rememberUiRelease=e=>{recentUiReleases.push({x:e.clientX,y:e.clientY,until:Date.now()+900});if(recentUiReleases.length>8)recentUiReleases.shift();};
  const ghostFromUi=e=>{
    if(e.target!==canvas||e.sourceCapabilities?.firesTouchEvents===false)return false;
    const now=Date.now();while(recentUiReleases.length&&recentUiReleases[0].until<now)recentUiReleases.shift();
    return recentUiReleases.some(t=>Math.hypot(e.clientX-t.x,e.clientY-t.y)<=18);
  };
  const dnd=game.uiwin?.dnd,dragMethods=[];
  const dragControls=new Map(),dragClass='dk-mobile-native-drag';
  const prepareDragControls=w=>{for(const ctrl of w?.all||[]){const el=ctrl.el;if(typeof ctrl._drag!=='function'||!el?.classList||dragControls.has(el))continue;dragControls.set(el,el.classList.contains(dragClass));el.classList.add(dragClass);}};
  for(const w of new Set(game.uiwin?.wins?.values?.()||[]))prepareDragControls(w);
  game.uiwin?.on?.('open',prepareDragControls);
  const touchDragEvent=()=>dnd?.cand?.e?.pointerType==='touch'?dnd.cand.e:dnd?.cur&&dnd._lastPointer?.pointerType==='touch'?dnd._lastPointer:null;
  const cancelTouchDrag=id=>{const owner=touchDragEvent();if(!owner||(id!=null&&owner.pointerId!==id)||dnd?.cur?.pending)return;if(dnd.cand?.e===owner)dnd.cand=null;if(dnd.active)dnd.cancel();};
  // DragDrop's original capture listeners remain registered in the same order.
  // Its arrow listeners look up these methods at dispatch, so only touch-pointer
  // custody is adapted; native payloads/drop transactions stay unchanged.
  for(const key of ['_onMove','_onUp','_onDownGlobal'])if(typeof dnd?.[key]==='function'){const original=dnd[key],wrapped=function(e){const owner=touchDragEvent();
    // After a refused release the native item stays picked up. A fresh primary
    // touch may place it even though Android assigns that touch a new ID.
    if(key==='_onDownGlobal'&&e.pointerType==='touch'&&e.isPrimary!==false&&this.cur?.mode==='sticky'&&!allTouches.size){this._lastPointer=e;return original.call(this,e);}
    if(e.pointerType==='touch'&&(e.isPrimary===false||(owner&&owner.pointerId!==e.pointerId)))return;if(e.pointerType==='mouse'&&owner)cancelTouchDrag();return original.call(this,e);};dnd[key]=wrapped;dragMethods.push({key,original,wrapped});}
  if(typeof dnd?.pointerDown==='function'){const key='pointerDown',original=dnd[key],wrapped=function(ctrl,e){if(e.pointerType==='touch'&&(e.isPrimary===false||allTouches.size>1))return true;return original.call(this,ctrl,e);};dnd[key]=wrapped;dragMethods.push({key,original,wrapped});}
  const scope=()=>({player:game.player,world:game.world,map:game.network?.self?.map,instance:game.network?.self?.instanceId,channel:game.network?.self?.channel});
  const sameScope=s=>s&&s.player===game.player&&s.world===game.world&&s.map===game.network?.self?.map&&s.instance===game.network?.self?.instanceId&&s.channel===game.network?.self?.channel;
  const modifierCurrent=()=>activeModifiers&&sameScope(activeModifiers.scope)&&!disposed&&!doc.hidden&&input.enabled!==false&&!game.player?.dead&&!game.player?.disposed&&!(game.network?.active&&!game.network.ready)?activeModifiers:null;
  const eventModifiers=e=>{const m=modifierCurrent();if(!m||e.pointerType!=='touch'||e.pointerId!==m.id)return;if(!modifiedEvents.has(e))modifiedEvents.set(e,{ctrl:Object.getOwnPropertyDescriptor(e,'ctrlKey'),shift:Object.getOwnPropertyDescriptor(e,'shiftKey')});for(const [key,on]of [['ctrlKey',m.ctrl],['shiftKey',m.shift]])if(on)Object.defineProperty(e,key,{configurable:true,value:true});};
  function clearModifiers(){const owned=!!activeModifiers;armedModifiers={shift:false,ctrl:false};armedScope=null;activeModifiers=null;for(const [e,d]of modifiedEvents){for(const [key,old]of [['ctrlKey',d.ctrl],['shiftKey',d.shift]]){if(old)Object.defineProperty(e,key,old);else delete e[key];}}modifiedEvents.clear();if(owned){game.uiwin?.tooltips?._shiftHeld?.(!!physicalModifier('ShiftLeft')||!!physicalModifier('ShiftRight'));game.uiwin?.tooltips?._ctrlHeld?.(!!physicalModifier('ControlLeft')||!!physicalModifier('ControlRight'));}paintModifiers();}
  function takeModifiers(e){if(armedScope&&!sameScope(armedScope))clearModifiers();if(e?.pointerType!=='touch'||!(armedModifiers.shift||armedModifiers.ctrl))return;activeModifiers={...armedModifiers,id:e.pointerId,scope:scope(),ending:false};armedModifiers={shift:false,ctrl:false};eventModifiers(e);paintModifiers();}
  // KeyMap retains its raw reader before this adapter is installed. Adapt that
  // reader when present, preserving remaps and every real keyboard key.
  const reader=game.keymap?.raw||input,physicalModifier=reader.down?.bind(reader)||(()=>false);
  if(typeof reader.down==='function'){const key='down',original=reader[key],wrapped=function(code){if(original.call(this,code))return true;const m=modifierCurrent();return !!m&&(m.ctrl&&['ControlLeft','ControlRight'].includes(code)||m.shift&&['ShiftLeft','ShiftRight'].includes(code));};reader[key]=wrapped;modifierMethods.push({owner:reader,key,original,wrapped});}
  if(typeof input.endFrame==='function'){const key='endFrame',original=input[key],wrapped=function(...args){const out=original.apply(this,args);if(armedScope&&(!sameScope(armedScope)||doc.hidden||input.enabled===false))clearModifiers();if(activeModifiers&&(!modifierCurrent()||activeModifiers.ending&&(!activeModifiers.order||game.controller?.order!==activeModifiers.order)))clearModifiers();return out;};input[key]=wrapped;modifierMethods.push({owner:input,key,original,wrapped});}
  const consume=e=>{e.preventDefault();e.stopImmediatePropagation();};
  const cancelTimer=t=>{if(t?.timer!=null){clear(t.timer);t.timer=null;}};
  const mouseAt=e=>{const r=canvas?.getBoundingClientRect?.();if(!r?.width||!r?.height)return false;Object.assign(input.mouse,{x:e.clientX,y:e.clientY,nx:(e.clientX-r.left)/r.width*2-1,ny:-(e.clientY-r.top)/r.height*2+1});return true;};
  const releaseMove=stop=>{if(touchLeft){input.held.left=false;touchLeft=false;if(stop&&game.controller?.order?.type==='move')game.controller.stop();}};
  const releaseCamera=()=>{if(touchRight){input.held.right=false;touchRight=false;}pair=null;};
  const cancelUi=()=>{cancelTimer(ui);ui=null;};
  const clearGesture=()=>{cancelTimer(single);releaseMove(true);releaseCamera();single=null;};
  function reset(){const ownsInput=points.size>0||touchLeft||touchRight;for(const t of buttonTouches.values())t.canceled=true;clearModifiers();clearGesture();cancelUi();points.clear();allTouches.clear();uiTouches.clear();recentUiReleases.length=0;chord=false;swallow=null;if(input.mobile)input.mobile.moveX=input.mobile.moveY=0;if(ownsInput){input.mouse.dx=input.mouse.dy=0;input.mouse.wheel=0;}
    cancelTouchDrag();
  }
  const overWorld=e=>{const el=doc.elementFromPoint?.(e.clientX,e.clientY);return !el||el===canvas;};
  const promoteHold=()=>{const t=single;if(!t||chord||points.size!==1||allTouches.size!==1||!sameScope(t.scope)||!playable()||game.uiwin?.dnd?.active||!overWorld(t.last))return;
    if(!mouseAt(t.last))return;const ndc={x:input.mouse.nx,y:input.mouse.ny};if(game.pickActor?.(ndc)||game.loot?.pickAt?.(ndc)||!game.pickGround?.(ndc))return;
    t.hold=true;touchLeft=true;input.held.left=true;
  };
  const pairMetrics=()=>{const [a,b]=points.values();return {x:(a.x+b.x)/2,y:(a.y+b.y)/2,d:Math.max(12,Math.hypot(b.x-a.x,b.y-a.y)),a:Math.atan2(b.y-a.y,b.x-a.x)};};
  const beginPair=()=>{cancelTimer(single);releaseMove(true);single=null;chord=true;if(points.size===2&&allTouches.size===2&&playable()&&!game.uiwin?.dnd?.active){pair={...pairMetrics(),scope:scope()};touchRight=true;input.held.right=true;}else releaseCamera();};
  // Use the original control's semantic handler: no MouseEvent/right-click mode.
  const rightAction=(target,e)=>{let ctrl;for(let el=target;el;el=el.parentElement){if(el._uw){ctrl=el._uw;break;}}
    if(!ctrl||ctrl.enabled===false||ctrl.win?.isOpen===false||ctrl.el?.isConnected===false)return null;
    if(typeof ctrl.cellAt==='function'&&typeof ctrl.itemAt==='function'&&ctrl._h?.cellrclick?.length){const cell=ctrl.cellAt(e.clientX,e.clientY),item=cell&&ctrl.itemAt(cell.x,cell.y);if(!item)return null;const valid=()=>{const at=ctrl.cellAt(e.clientX,e.clientY);return ctrl.enabled!==false&&ctrl.win?.isOpen!==false&&ctrl.el?.isConnected!==false&&!!at&&ctrl.itemAt(at.x,at.y)===item;};return {ctrl,valid,run(){if(!valid())return false;ctrl.emit('cellrclick',ctrl.cellAt(e.clientX,e.clientY),item,e);return true;}};}
    // Original list and tree rows have distinct right-action signatures.
    if((ctrl instanceof UIList||ctrl instanceof UITree)&&ctrl._h?.rclick?.length){let row=target;while(row&&row.parentElement!==ctrl.rows)row=row.parentElement;const k=Array.from(ctrl.rows?.children||[]).indexOf(row),i=ctrl.top+k,item=ctrl instanceof UIList?ctrl.items?.[i]:ctrl.flat?.[i];if(k<0||!item)return null;const valid=()=>ctrl.enabled!==false&&ctrl.win?.isOpen!==false&&ctrl.el?.isConnected!==false&&row?.isConnected!==false&&ctrl.rows.children[k]===row&&ctrl.top+k===i&&(ctrl instanceof UIList?ctrl.items[i]:ctrl.flat[i])===item;return {ctrl,valid,run(){if(!valid())return false;if(ctrl instanceof UIList)ctrl.emit('rclick',i,item,e);else ctrl.emit('rclick',item,e);return true;}};}
    if(!Array.isArray(ctrl.items)&&!Array.isArray(ctrl.flat)&&ctrl._h?.rclick?.length)return {ctrl,valid:()=>ctrl.enabled!==false&&ctrl.win?.isOpen!==false&&ctrl.el?.isConnected!==false,run(){if(!this.valid())return false;ctrl.emit('rclick',e);return true;}};
    return null;
  };
  const inspectModifiedItem=candidate=>{const ctrl=candidate.action.ctrl,tips=game.uiwin?.tooltips;if(!candidate.action.valid?.()||typeof ctrl.tooltip!=='function'||!tips?.enter||!tips?.move)return false;if(ctrl.type==='itemslot')ctrl._hc=ctrl.cellAt(candidate.x,candidate.y);tips.enter(ctrl,candidate.event);tips._shiftHeld?.(!!modifierCurrent()?.shift);tips._ctrlHeld?.(!!modifierCurrent()?.ctrl);tips.move(ctrl,candidate.event);return true;};
  const itemHold=candidate=>{
    const action=candidate.action,pressed=dnd?.cand;
    if(!action.valid?.())return false;
    if(modifierCurrent()?.ctrl||modifierCurrent()?.shift){if(pressed?.ctrl===action.ctrl)dnd.cand=null;return inspectModifiedItem(candidate);}
    // Keep the native owned-item payload and transaction. Holding must lift it,
    // not invoke the equip/use right-action before the player chooses a target.
    if(pressed?.ctrl===action.ctrl&&pressed.e.pointerId===candidate.id&&typeof action.ctrl._drag==='function'){
      dnd.cand=null;
      return dnd.start(action.ctrl,pressed.e,'hold');
    }
    return action.run();
  };
  const down=e=>{if(disposed)return;if(e.pointerType==='mouse'){if(e.sourceCapabilities?.firesTouchEvents===true&&ghostFromUi(e)){consume(e);return;}if(points.size||ui||activeModifiers||armedModifiers.ctrl||armedModifiers.shift)reset();recentUiReleases.length=0;return;}if(e.pointerType!=='touch')return;if(!allTouches.size&&!points.size&&(input.held.left||input.held.right||input.held.middle)){if(input.held.left&&game.controller?.order?.type==='move')game.controller.stop();input.held.left=input.held.right=input.held.middle=false;for(const key of ['left','right','middle'])input.dragging[key]=false;input._down={};input.mouse.dx=input.mouse.dy=0;input.mouse.wheel=0;}allTouches.add(e.pointerId);
    if(e.target!==canvas)uiTouches.set(e.pointerId,true);
    if(allTouches.size>1){for(const t of buttonTouches.values())t.canceled=true;clearModifiers();cancelUi();cancelTouchDrag();if(points.size)beginPair();}
    else if(!root.contains(e.target)&&!['INPUT','TEXTAREA'].includes(e.target?.tagName)&&!e.target?.isContentEditable&&!game.uiwin?.dnd?.cur?.pending){if(!extra.hidden)closePanels();if(activeModifiers?.ending)clearModifiers();takeModifiers(e);eventModifiers(e);}
    if(e.target!==canvas||!canvas||e.defaultPrevented||game.uiwin?.dnd?.active){if(e.target!==canvas&&allTouches.size===1){const action=rightAction(e.target,e);if(action){ui={event:e,id:e.pointerId,target:e.target,x:e.clientX,y:e.clientY,scope:scope(),action,fired:false,timer:null};const candidate=ui;candidate.timer=later(()=>{if(ui!==candidate||doc.hidden||!sameScope(candidate.scope)||allTouches.size!==1||game.uiwin?.dnd?.active)return;if(itemHold(candidate)){candidate.fired=true;swallow={target:candidate.target,until:Date.now()+1200};}},ITEM_HOLD_MS);}}return;}
    consume(e);if(!playable())return;points.set(e.pointerId,{x:e.clientX,y:e.clientY});canvas.setPointerCapture?.(e.pointerId);
    if(points.size===1&&allTouches.size===1){single={id:e.pointerId,x:e.clientX,y:e.clientY,last:e,scope:scope(),hold:false,moved:false,timer:null};single.timer=later(promoteHold,HOLD_MS);chord=false;}
    else if(points.size===2&&allTouches.size===2)beginPair();else{clearGesture();chord=true;}
  };
  const move=e=>{if(e.pointerType!=='touch'||disposed)return;
    eventModifiers(e);
    if(ui?.id===e.pointerId&&Math.hypot(e.clientX-ui.x,e.clientY-ui.y)>TAP_SLOP)cancelUi();
    const p=points.get(e.pointerId);if(!p)return;consume(e);p.x=e.clientX;p.y=e.clientY;
    if(!playable()||!sameScope((pair||single)?.scope)||!overWorld(e)){clearGesture();chord=true;return;}
    if(pair&&points.size===2){const next=pairMetrics(),angle=Math.atan2(Math.sin(next.a-pair.a),Math.cos(next.a-pair.a));input.mouse.dx+=(next.x-pair.x)*CAMERA_PAN+angle/.006;input.mouse.dy+=(next.y-pair.y)*CAMERA_PAN;input.mouse.wheel+=Math.max(-6,Math.min(6,Math.log(pair.d/next.d)/Math.log(1.12)));Object.assign(pair,next);return;}
    if(single?.id===e.pointerId&&!chord){single.last=e;single.moved ||= Math.hypot(e.clientX-single.x,e.clientY-single.y)>TAP_SLOP;if(single.hold)mouseAt(e);}
  };
  const end=(e,canceled=false)=>{if(e.pointerType!=='touch'||disposed)return;eventModifiers(e);if(activeModifiers?.id===e.pointerId){activeModifiers.ending=true;if(canceled)clearModifiers();}allTouches.delete(e.pointerId);if(canceled)cancelTouchDrag(e.pointerId);
    if(uiTouches.delete(e.pointerId)){rememberUiRelease(e);if(e.target===canvas)consume(e);}
    if(ui?.id===e.pointerId){const candidate=ui;cancelUi();if(candidate.fired){consume(e);swallow={target:candidate.target,until:Date.now()+900};}else if(canceled){const dnd=game.uiwin?.dnd;if(dnd?.cand?.e?.pointerId===e.pointerId)dnd.cand=null;if(dnd?.active&&!dnd.cur?.pending&&dnd._lastPointer?.pointerId===e.pointerId)dnd.cancel();}}
    if(!points.has(e.pointerId))return;consume(e);points.delete(e.pointerId);const t=single;cancelTimer(t);
    if(!canceled&&!chord&&t?.id===e.pointerId&&!t.hold&&!t.moved&&sameScope(t.scope)&&playable()&&overWorld(e)&&!game.uiwin?.dnd?.active&&mouseAt(e))input.clicks.push({button:'left',x:e.clientX,y:e.clientY,nx:input.mouse.nx,ny:input.mouse.ny,shift:!!e.shiftKey,ctrl:!!e.ctrlKey});
    releaseMove(true);releaseCamera();single=null;if(!points.size&&!allTouches.size)chord=false;
    if(canvas.hasPointerCapture?.(e.pointerId))canvas.releasePointerCapture?.(e.pointerId);
  };
  const suppress=e=>{eventModifiers(e);if(ghostFromUi(e)){consume(e);return;}if(e.type==='contextmenu'&&ui&&(e.target===ui.target||ui.target?.contains?.(e.target))){consume(e);return;}if(swallow&&Date.now()<swallow.until&&(e.target===swallow.target||swallow.target?.contains?.(e.target))){consume(e);if(e.type==='click')swallow=null;}};
  const suppressGhostMouse=e=>{if(ghostFromUi(e))consume(e);};
  const visibility=()=>{if(doc.hidden)reset();};
  // Physical keyboard/text editing supersedes touch-only choices. Run after
  // Input's ordinary key reader; never insert a key or cancel accepted work.
  const keyboard=()=>{if(activeModifiers||armedModifiers.ctrl||armedModifiers.shift){clearModifiers();cancelUi();}};
  const textFocus=e=>{if(['INPUT','TEXTAREA'].includes(e.target?.tagName)||e.target?.isContentEditable)keyboard();};
  const listeners=[['pointerdown',down],['pointermove',move],['pointerup',e=>end(e)],['pointercancel',e=>end(e,true)],['lostpointercapture',e=>{if(allTouches.has(e.pointerId))end(e,true);}],['mousedown',suppressGhostMouse],['mouseup',suppressGhostMouse],['click',suppress],['contextmenu',suppress]];
  for(const [type,fn]of listeners)win.addEventListener(type,fn,{capture:true,passive:false});
  win.addEventListener('blur',reset);win.addEventListener('pagehide',reset);win.addEventListener('keydown',keyboard);doc.addEventListener?.('focusin',textFocus);doc.addEventListener?.('visibilitychange',visibility);doc.body.appendChild(root);
  menuPosition=positionMobileMenu(game,{doc,win,root,rail,extra,modifier:modifierState});
  return {root,dispose(){if(disposed)return;reset();disposed=true;menuPosition?.dispose();doc.body.classList?.remove?.('dk-touch-ui');game.uiwin?.off?.('open',prepareDragControls);for(const [el,existed]of dragControls)if(!existed)el.classList.remove(dragClass);dragControls.clear();for(const {owner,key,original,wrapped}of modifierMethods)if(owner[key]===wrapped)owner[key]=original;for(const {key,original,wrapped}of dragMethods)if(dnd[key]===wrapped)dnd[key]=original;for(const [type,fn]of listeners)win.removeEventListener(type,fn,true);win.removeEventListener('blur',reset);win.removeEventListener('pagehide',reset);win.removeEventListener('keydown',keyboard);doc.removeEventListener?.('focusin',textFocus);doc.removeEventListener?.('visibilitychange',visibility);root.remove();}};
}
