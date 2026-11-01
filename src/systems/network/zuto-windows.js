// Original game2/dksquare Zuto windows. All numbers and deadlines come from the host.
import {setItemIcon,itemName} from '../life/common.js';
const scripts={dash:'ui_urbandashboard',stones:'ui_urbanstatewnd',wait:'ui_urbanwaiting',result:'ui_urbannoticeboard'};
const sub=(c,id)=>{for(const v of c?.children||[]){if(v.id===id||v.spec?.id===id)return v;const found=sub(v,id);if(found)return found;}return null;};
const text=(c,v)=>c?.setText?.(v==null?'':String(v));
export function zutoWindowView(snapshot,map,now){
  const field=map===650&&!!snapshot&&!snapshot.lobby,ending=field&&!!snapshot.outcome;
  const deadline=field?(ending?snapshot.returnAt:['init','entry'].includes(snapshot.phase)?snapshot.startAt:snapshot.endAt):snapshot?.lobby?snapshot.battle?.startAt:null;
  const seconds=Number.isFinite(deadline)&&Number.isFinite(now)?Math.max(0,Math.ceil((deadline-now)/1000)):null;
  return {field,ending,seconds,dash:field&&!ending,wait:seconds!==null&&(ending||[651,652].includes(map)&&['init','entry'].includes(snapshot?.battle?.phase)),result:ending?snapshot.outcome:null};
}
export function installZutoWindows(game,network,getSnapshot,T){
  const ui=game.uiwin,wanted=new Map(),pending=new Map();let disposed=false,key=null,shownResult=null;
  for(const [name,script]of Object.entries(scripts))ui?.registerWindow?.(`zuto_${name}`,{script:`game2/dksquare/${script}.txt`,hud:name!=='result',remember:false,escClose:name==='result',band:name==='result'?'normal':'hud'});
  const close=name=>{wanted.delete(name);ui?.close?.(`zuto_${name}`);};
  const show=(name,fill)=>{
    wanted.set(name,fill);if(pending.has(name)||!ui?.open)return;
    const promise=Promise.resolve(ui.open(`zuto_${name}`)).then(w=>{if(disposed||!wanted.has(name)){ui.close(`zuto_${name}`);return;}wanted.get(name)?.(w);}).catch(e=>game.chat?.system?.(e.message,'err')).finally(()=>pending.delete(name));pending.set(name,promise);
  };
  const fillPerson=(w,prefix,row)=>{
    text(w.find(`lbl_${prefix}_name`),row?.name);text(w.find(`lbl_${prefix}_class`),game.data?.classByIndex?.get?.(row?.classIndex)?.name||'');
    text(w.find(`lbl_${prefix}_server`),row?.side?T(160,row.side==='red'?644:643):'');text(w.find(`lbl_${prefix}_level`),row?.level);text(w.find(`lbl_${prefix}_occupation`),row?.captures);text(w.find(`lbl_${prefix}_kill`),row?.kills);
  };
  const fillResult=(w,s)=>{
    const mine=s.mine||{},out=s.outcome;
    for(const kind of ['win','lose','draw'])w.find(`pan_top_${kind}`)?.setVisible(kind===(out.winner?out.winner===mine.side?'win':'lose':'draw'));
    for(const side of ['red','blue']){const base=side==='red'?10:20;w.find(`pan_top_${side}_domi_score`)?.setImage('none','urbanresult',base+(out.stones?.[side]||0));const digits=String(Math.max(0,Math.min(9999,s.kills?.[side]||0))).padStart(4,'0');for(let i=0;i<4;i++)w.find(`pan_top_${side}_kill_score_0${4-i}`)?.setImage('none','urbanresult',base+Number(digits[i]));}
    fillPerson(w,'my',mine);text(w.find('lbl_my_achievement'),(mine.achievements||[]).map(k=>T(160,k==='slayer'?614:615)).join(' / '));
    w.find('pan_middle_detail')?.setVisible(false);
    const rows=Object.entries(out.achievements||{}).filter(([,r])=>r);
    for(let i=0;i<2;i++){
      const suffix=`_zuto${i}`;let c=w.find(`pan_middle_detail${suffix}`);if(!c)c=w.clone?.('pan_middle_detail',suffix,{y:20+i*25});c?.setVisible(i<rows.length);if(i>=rows.length)continue;
      const [kind,r]=rows[i];for(const [id,value]of Object.entries({achievement:T(160,kind==='slayer'?614:615),name:r.name,class:game.data?.classByIndex?.get?.(r.classIndex)?.name||'',server:T(160,r.side==='red'?644:643),level:r.level,occupation:r.captures,kill:r.kills}))text(w.find(`lbl_d_${id}${suffix}`),value);
    }
    for(const [slot,kinds]of [['reward',['win','lose']],['achive',['slayer','ruler']],['join',['join']],['attend',['attend']]]){
      const rows=(mine.rewardRows||[]).filter(r=>kinds.includes(r.kind)),r=rows[0],count=rows.reduce((n,r)=>n+r.count,0),control=w.find(`item_${slot}`);
      void setItemIcon(game,control,r?.item,count).catch(()=>{});text(w.find(`lbl_${slot}_item_name`),r?`${itemName(game,r.item)}${count>1?' x'+count:''}`:'');
    }
    if(!w._zutoClose){w._zutoClose=true;w.find('btn_exit')?.onClick(()=>close('result'));}
  };
  function update(){
    if(disposed)return;
    const s=getSnapshot(),map=Number(game.world?.info?.index),clock=network._serverClock,now=clock?clock.time+performance.now()-clock.at:NaN,v=zutoWindowView(s,map,now);
    const next=JSON.stringify([map,s,v.seconds]);if(next===key)return;key=next;
    if(v.dash)show('dash',w=>{w.find('number_redkillcnt')?.setNumber(s.kills?.red||0);w.find('number_bluekillcnt')?.setNumber(s.kills?.blue||0);w.find('number_timer')?.setTime(v.seconds||0);w.find('pan_timer_name')?.setVisible(['init','entry'].includes(s.phase));});else close('dash');
    if(v.field)show('stones',w=>{for(let i=0;i<5;i++){const stone=s.stones?.find(x=>x.index===i),icon=sub(w.find(`pan_occupation_complet_${i}`),'worldicon');icon?.setImage('none',stone?.owner?{screen:'buffer',index:stone.owner==='red'?92:115,color:'ffffffff'}:null);w.find(`pan_occupation_ing_${i}`)?.setVisible(!!stone?.seizing);}});else close('stones');
    if(v.wait)show('wait',w=>{w.find('pan_time')?.setVisible(true);text(w.find('textbox_time'),`${T(v.ending?650:160,v.ending?1:601)} ${Math.floor(v.seconds/60)}:${String(v.seconds%60).padStart(2,'0')}`);});else close('wait');
    if(v.result){if(shownResult!==s.id){shownResult=s.id;show('result',w=>fillResult(w,s));}}else{shownResult=null;close('result');}
  }
  return {update,dispose(){disposed=true;for(const name of Object.keys(scripts))close(name);}};
}
