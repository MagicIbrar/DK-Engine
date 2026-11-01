// Native ui_atkcastlewnd: ten paged rows, sortable columns and Auto Grant for
// the first SIEGE_ATTACK_MAX members of the displayed order (130:427).
export async function openGuildSiegeRoster(game,{state,send,current=()=>true}) {
  const start=state(),id=start?.id,token=game.network?.token;
  if(!start?.founded||!start.siegeRoster?.limit)return null;
  const valid=()=>current()&&game.network?.token===token&&state()?.id===id&&state()?.founded;
  const win=await game.uiwin.create('game2/guild/ui_atkcastlewnd.txt',{name:'guildSiegeAuthority',modal:true,escClose:true,remember:false,disposeOnClose:true});
  if(!valid()){win.close();return null;}
  const c=id=>win.control(id),selected=new Set(start.siegeRoster.selected),columns={name:'name',job:'classIndex',class:'rank',contribute:'contribution'};
  let sort='contribution',dir=-1,top=0,pending=false,disposed=false,rows=[];
  const editable=()=>valid()&&!pending&&!state().siegeRoster?.locked&&state().master===state().myRef;
  const changed=()=>{const saved=state()?.siegeRoster?.selected||[];return saved.length!==selected.size||saved.some(r=>!selected.has(r));};
  const paint=()=>{
    if(disposed)return;
    if(!valid()){win.close();return;}
    const s=state(),members=new Set(s.members.map(m=>m.ref));
    for(const ref of selected)if(!members.has(ref))selected.delete(ref);
    rows=[...s.members].sort((a,b)=>(typeof a[sort]==='string'?String(a[sort]).localeCompare(String(b[sort])):(Number(a[sort])||0)-(Number(b[sort])||0))*dir||a.name.localeCompare(b.name));
    top=Math.max(0,Math.min(top,rows.length-10));c('vscroll').setRange?.(Math.max(0,rows.length-10),10);
    c('lbl_count').setText(`${selected.size}/${s.siegeRoster.limit}`);
    for(const [column,key]of Object.entries(columns))for(const suffix of ['','_h','_l'])c(`btn_col_${column}${suffix}`).setVisible(sort===key?suffix===(dir>0?'_h':'_l'):suffix==='');
    for(let i=0;i<10;i++){
      const row=c(`btnlist_${i}`),m=rows[top+i];row.setVisible(!!m);if(!m)continue;
      row.setEnabled(editable());row.control('pan_check').setVisible(selected.has(m.ref));
      row.control('lbl_name').setText(m.name);row.control('lbl_class').setText(game.data?.classByIndex?.get?.(Number(m.classIndex))?.name||'');
      row.control('lbl_grade').setText(m.grade||'');row.control('lbl_point').setText(Number(m.contribution||0).toLocaleString('en-US'));
    }
    c('btn_top50').setEnabled(editable());c('btn_ok').setEnabled(editable()&&changed());
  };
  for(let i=0;i<10;i++)c(`btnlist_${i}`).onClick(()=>{const m=rows[top+i];if(!m||!editable())return;if(selected.has(m.ref))selected.delete(m.ref);else if(selected.size<state().siegeRoster.limit)selected.add(m.ref);paint();});
  for(const [column,key]of Object.entries(columns))for(const suffix of ['','_h','_l'])c(`btn_col_${column}${suffix}`).onClick(()=>{dir=sort===key?-dir:1;sort=key;top=0;paint();});
  c('vscroll').on?.('change',v=>{top=Number(v)||0;paint();});
  c('btn_top50').onClick(()=>{if(!editable())return;selected.clear();for(const m of rows.slice(0,state().siegeRoster.limit))selected.add(m.ref);paint();});
  c('btn_ok').onClick(async()=>{if(!editable()||!changed())return;pending=true;paint();try{if(await send({memberRefs:[...selected]})&&valid())win.close();}finally{pending=false;paint();}});
  for(const name of ['btn_cancel','btn_exit'])c(name).onClick(()=>win.close());
  win.on?.('close',()=>{disposed=true;});
  win.open();paint();
  return {win,update:paint};
}
