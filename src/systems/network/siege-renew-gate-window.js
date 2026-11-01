// Native ui_gateupgradewnd2 controls. A single selected group is upgraded in one
// host transaction; +/-/MAX only plan a desired level, never spend locally.
export function bindSiegeGateWindow(win,{map,prices,current,state,send,text,ask,close}){
 const c=id=>win.control(id),bindings=[];let selected=0,target=null,pending=false,disposed=false,lastLevel=null;
 const active=()=>!disposed&&win.isOpen!==false&&current();
 const bind=(control,event,fn)=>{control.on(event,fn);bindings.push(()=>control.off(event,fn));};
 const format=(code,...args)=>{let i=0;return String(text(code)||'').replace(/%[us]/g,()=>String(args[i++]??''));};
 const group=()=>state()?.gateUpgrade?.groups?.find(g=>g.group===selected);
 const cost=g=>prices.slice(g.level,target??g.level).reduce((a,b)=>a+b,0);
 c('pan_map').setImage('none','minimap',map);c('lbl_title').setText(format(1));
 const paint=()=>{
  if(!active())return;const snapshot=state(),view=snapshot?.gateUpgrade,groups=view?.groups||[],g=group();
  if(g&&lastLevel!==g.level){target=g.level;lastLevel=g.level;}
  if(g)target=Math.max(g.level,Math.min(g.maxLevel,target??g.level));
  for(let i=0;i<5;i++){
   const row=groups.find(g=>g.group===i),visible=!!row;c(`pan_gate${i}`).setVisible(visible);if(!row)continue;
   c(`lbl_gatetitle${i}`).setText(row.name);c(`lbl_level${i}`).setText(i===selected&&target>row.level?format(3,row.level,target):row.level);
   c(`btn_plus${i}`).setEnabled(!pending&&!!view.available&&(i!==selected||target<row.maxLevel));c(`btn_minus${i}`).setEnabled(!pending&&i===selected&&target>row.level);c(`btn_max${i}`).setEnabled(!pending&&!!view.available&&row.level<row.maxLevel);
  }
  c('pan_select').setVisible(!!g);if(g){const box=c(`pan_gate${selected}`).box;c('pan_select').setRect(box.x-2,box.y-2,box.w+4,box.h+4);}
  const gates=snapshot?.gates||[],mapBox=c('pan_map').box,point=r=>({x:r.z/512*mapBox.w-8.5,y:r.x/512*mapBox.h-9});
  for(let i=0;i<13;i++){const row=gates[i],icon=c(`pan_gateicondefault${i}`);icon.setVisible(!!row&&!row.dead);if(row){const p=point(row);icon.setRect(p.x,p.y,17,18);}}
  const chosen=gates.filter(row=>row.group===selected&&!row.dead);for(let i=0;i<3;i++){const icon=c(`pan_gateicon${i}`),row=chosen[i];icon.setVisible(!!row);if(row){const p=point(row);icon.setRect(p.x,p.y,17,18);}}
  c('pan_gatedesc').setVisible(!!g);if(g){c('lbl_gatename').setText(g.name);c('lbl_hp').setText(format(4)+': '+gates.filter(r=>r.group===selected).reduce((sum,r)=>sum+r.maxHp,0).toLocaleString('en-US'));}
  c('btn_confirm').setEnabled(!pending&&!!view?.available&&!!g&&target>g.level&&cost(g)<=Number(view.funds));
 };
 const pick=i=>{if(!active()||pending)return false;if(selected!==i){selected=i;lastLevel=null;target=null;}paint();return !!group();};
 for(let i=0;i<5;i++){
  // The native whole-row button has a higher layer than its +/- children.
  // Limit selection to the title strip so it cannot swallow those controls.
  c(`btn_gate${i}`).setRect(0,0,146,24);
  // Reserve enough space for native "current > selected" text between the
  // step buttons; the original level label overlaps the plus by two pixels.
  c(`lbl_level${i}`).setRect(29,29,47,14);c(`btn_plus${i}`).setRect(78,27,18,20);c(`btn_max${i}`).setRect(101,27,40,20);
  bind(c(`btn_gate${i}`),'click',()=>pick(i));
  bind(c(`btn_plus${i}`),'click',()=>{if(!pick(i))return;target=Math.min(group().maxLevel,target+1);paint();});
  bind(c(`btn_minus${i}`),'click',()=>{if(!pick(i))return;target=Math.max(group().level,target-1);paint();});
  bind(c(`btn_max${i}`),'click',()=>{if(!pick(i))return;target=group().maxLevel;paint();});
 }
 bind(c('btn_confirm'),'click',async()=>{
  if(!active()||pending)return;const g=group(),view=state()?.gateUpgrade;if(!g||!view?.available||target<=g.level||cost(g)>Number(view.funds))return;
  const plan={group:selected,targetLevel:target},level=g.level,price=cost(g);pending=true;paint();
  try{if(await ask(`${format(1)}\n${g.name}: ${format(3,level,target)}\n${format(5,price.toLocaleString('en-US'))}`,{...plan,price})!=='yes'||!active())return;
   const currentGroup=group();if(currentGroup?.level!==level||!state()?.gateUpgrade?.available||Number(state()?.gateUpgrade?.funds)<price)return;
   await send(plan);if(active()){target=null;lastLevel=null;paint();}
  }finally{pending=false;paint();}
 });
 bind(c('btn_exit'),'click',close);
 const dispose=()=>{if(disposed)return;disposed=true;for(const off of bindings)off();win.off?.('close',dispose);};win.on?.('close',dispose);paint();
 return {update:paint,dispose,get active(){return active();}};
}
