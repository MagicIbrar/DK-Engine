// Standard mapping only. Poll fresh snapshots; never synthesize game keyboard events.
export const EDITOR_PAD_HELP='LS move · RS look · LT/RT down/up · L3 boost · A hold build/select · B clear · X undo · Y redo · LB/RB tool · D-pad ↑↓ radius, ←→ nudge · View snap · R3 view · Menu frame';
export function deadAxis(value,dead=.18){const v=Number(value);if(!Number.isFinite(v))return 0;return Math.abs(v)<=dead?0:Math.sign(v)*(Math.min(1,Math.abs(v))-dead)/(1-dead);}
const pressed=(pad,i)=>!!pad.buttons?.[i]?.pressed||Number(pad.buttons?.[i]?.value)>.5;
const trigger=(pad,i)=>Math.max(0,Math.min(1,Number(pad.buttons?.[i]?.value)||0));
const toolOrder=['select','raise','lower','smooth','flatten','noise','vcolor','type','variant','hole','collision','water','decal','objects','spawns','npcs','portals'];
export class EditorGamepad {
 constructor(editor,{getGamepads=()=>globalThis.navigator?.getGamepads?.()||[],status=()=>{},changed=()=>{}}={}){this.editor=editor;this.getGamepads=getGamepads;this.status=status;this.changed=changed;this.previous=[];this.index=null;this.action=false;this.blocked=true;}
 interrupt(){if(this.action)this.editor.cancelInput();this.action=false;this.blocked=true;}
 update(dt,{enabled=true,focused=true,typing=false,busy=false}={}){
  let pads;try{pads=Array.from(this.getGamepads());}catch{this.interrupt();this.status('Controller unavailable in this browser.');return;}
  const pad=pads.find(p=>p?.connected&&p.mapping==='standard');
  if(!pad){this.interrupt();this.index=null;this.previous=[];this.status(pads.some(p=>p?.connected)?'Controller needs a standard mapping.':'Controller: connect and press a button.');return;}
  const current=Array.from({length:17},(_,i)=>pressed(pad,i));
  if(this.index!==pad.index){this.interrupt();this.index=pad.index;this.previous=current;}
  if(!enabled||!focused||typing||busy||this.editor._gizmoDragging||this.editor._drag){this.interrupt();this.previous=current;this.status(!enabled?'Controller off.':'Controller paused. Release buttons to resume.');return;}
  if(this.blocked){this.previous=current;if(current.some(Boolean)){this.status('Release controller buttons to arm editing.');return;}this.blocked=false;}
  this.status('Standard controller ready. Aim at the crosshair.');
  const edge=i=>current[i]&&!this.previous[i],e=this.editor;
  const duration=Math.max(0,Math.min(.05,Number(dt)||0));
  e.moveNavigation({forward:-deadAxis(pad.axes?.[1]),right:deadAxis(pad.axes?.[0]),up:trigger(pad,7)-trigger(pad,6),lookX:deadAxis(pad.axes?.[2]),lookY:deadAxis(pad.axes?.[3]),boost:current[10]},duration);
  // Camera changes precede the ray; the crosshair remains the same screen point.
  e.syncCamera();
  const commands=[1,2,3,4,5,8,9,11,12,13,14,15];
  if(commands.some(edge)&&this.action){e.cancelInput();this.action=false;}
  if(edge(1)){e.cancelInput();e.clearSelection();}
  if(edge(2))e.history.undo();if(edge(3))e.history.redo();
  if(edge(4)||edge(5)){const at=toolOrder.indexOf(e.tool),step=edge(5)?1:-1;e.setTool(toolOrder[(Math.max(0,at)+step+toolOrder.length)%toolOrder.length]);}
  if(edge(12)||edge(13))e.toolOpts.radius=Math.max(.5,Math.min(64,e.toolOpts.radius+(edge(12)?1:-1)));
  if(edge(14))e.nudgeSelection(-(e.snap||.25),0);if(edge(15))e.nudgeSelection(e.snap||.25,0);
  if(edge(8)){const snaps=[0,.25,.5,1,2];e.snap=snaps[(snaps.indexOf(e.snap)+1)%snaps.length];e.transform.translationSnap=e.snap||null;}
  if(edge(11))e.setNavigation(e.navigation==='firstperson'?'freefly':'firstperson');
  if(edge(9)){e.setNavigation('freefly');e.frameCamera();}
  if(commands.some(edge))this.changed();
  const centre={x:0,y:0};
  if(edge(0)&&!commands.some(edge)&&!e._stroking&&!e._dragMarker&&!e._portalDraft){if(['spawns','npcs','portals'].includes(e.tool))e.placing=true;e.pointerDown(centre,0);this.action=true;}
  if(this.action){if(current[0])e.pointerMove(centre);else{e.pointerUp(0);this.action=false;this.changed();}}
  this.previous=current;
 }
 dispose(){this.interrupt();}
}
