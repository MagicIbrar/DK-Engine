import {siegeDeployCell,siegeDeployCellAllowed,siegeDeployPoint} from '../../game/siege-renew-deploy-mask.js';

// Original ui_siegeguardwnd controls, art and native pivot rectangle. Reading the
// pivot as the stretched map rectangle is engine-chosen; display and click use
// the same inverse, preserving the native minimap u=FILE Z / v=FILE X convention.
export function bindSiegeGuardWindow(win,{map,cfg,mask,defs,current,state,funds,send,refuse,close}){
 const controls=id=>win.controls?.(c=>c.id?.toLowerCase()===id)||[win.control(id)];
 const base=win.control('pan_map_base'),mapPanel=win.control('pan_map'),red=win.control('pan_map_red'),selection=win.control('pan_select');
 const [x,y,width,height]=win.control(`pivot_${map}`).spec?.rect||[];
 if(![x,y,width,height].every(Number.isFinite)||!(width>0&&height>0)||!mask)return null;
 const rect={x,y,width,height},bindings=[];let selected=null,pending=false,disposed=false,paintKey=null;
 const active=()=>!disposed&&win.isOpen!==false&&current();
 const bind=(control,event,fn)=>{control.on(event,fn);bindings.push(()=>control.off(event,fn));};
 base.setClip(true);for(const c of [mapPanel,red])c.setRect(x,y,width,height);
 mapPanel.setImage('none','minimap',map);red.setImage('none','minimap_red',map);
 // The original script repeats lbl_cost three times; only the top-level layer
 // 102 label is the value field. The two cloned description placeholders must
 // stay empty instead of painting a price outside their parents.
 const costs=controls('lbl_cost'),cost=costs.find(c=>Number(c.spec?.layer)===102)||costs.at(-1);
 for(const c of costs)if(c!==cost)c.setVisible(false);
 cost?.setText(Number(cfg.sentryUpgradeCost).toLocaleString('en-US'));
 selection.setVisible(false);
 let dots=null;
 if(base.el?.ownerDocument){dots=base.el.ownerDocument.createElement('div');dots.style.cssText='position:absolute;inset:0;pointer-events:none;z-index:6';base.el.appendChild(dots);}
 const paint=()=>{
  if(!active())return;const guards=state()?.guards||[],remaining=Math.max(0,cfg.maxSentry-guards.length);
  // The host has one shared castle pool, not six independent unproven quotas.
  cfg.sentryIndexes.forEach((index,i)=>{win.control(`lbl_guardcount${i}`).setText(remaining);win.control(`lbl_guardtitle${i}`).setText(defs[index]?.name||'');});
  win.control('lbl_guardcount_total').setText(guards.length);win.control('lbl_money').setText(Math.max(0,Number(funds())||0).toLocaleString('en-US'));
  const key=JSON.stringify(guards.map(g=>[g.id,g.sentry,g.x,g.z]));if(!dots||key===paintKey)return;paintKey=key;dots.replaceChildren();
  for(const guard of guards){const point=siegeDeployPoint(rect,Math.floor(guard.x),Math.floor(guard.z)),dot=dots.ownerDocument.createElement('div');dot.style.cssText=`position:absolute;left:${point.u-2}px;top:${point.v-2}px;width:4px;height:4px;border-radius:50%;background:#f9b600;box-shadow:0 0 0 1px #000`;dot.title=defs[guard.sentry]?.name||'';dots.appendChild(dot);}
 };
 cfg.sentryIndexes.forEach((index,i)=>bind(win.control(`btn_guard${i}`),'click',()=>{
  if(!active())return;selected=index;const box=win.control(`pan_guard${i}`).box;selection.setRect(box.x-3,box.y-3,box.w+6,box.h+6);selection.setVisible(true);
 }));
 const point=event=>{const box=base.el.getBoundingClientRect();if(!(box.width>0&&box.height>0))return null;const u=(event.clientX-box.left)*base.box.w/box.width,v=(event.clientY-box.top)*base.box.h/box.height;if(u<0||v<0||u>=base.box.w||v>=base.box.h)return null;return siegeDeployCell(rect,u,v);};
 const hover=event=>{if(!active())return;const cell=point(event);win.control('lbl_cursorpos').setText(cell?`${cell.x}, ${cell.z}`:'');};
 base.el.addEventListener('pointermove',hover);bindings.push(()=>base.el.removeEventListener('pointermove',hover));
 // Map and empty background both consume a completed native-control click, so
 // touch release cannot leak into a world movement order behind this window.
 const deploy=async event=>{
  event.stopPropagation?.();if(!active()||pending)return;
  if(selected==null){refuse([320,107]);return;}
  const cell=point(event);if(!cell)return;
  // Native Width=3; the host additionally checks live actor overlap and walls.
  for(let dx=-1;dx<=1;dx++)for(let dz=-1;dz<=1;dz++)if(!siegeDeployCellAllowed(mask,cell.x+dx,cell.z+dz)){refuse([701,219]);return;}
  pending=true;try{await send({sentry:selected,...cell});if(active())paint();}finally{pending=false;}
 };
 bind(mapPanel,'click',deploy);bind(win.control('pan_map_bg'),'click',deploy);
 bind(win.control('btn_exit'),'click',close);bind(win.control('btn_confirm'),'click',close);
 const dispose=()=>{if(disposed)return;disposed=true;for(const off of bindings)off();dots?.remove();win.off?.('close',dispose);};win.on?.('close',dispose);
 paint();return {update:paint,dispose,get active(){return active();}};
}
