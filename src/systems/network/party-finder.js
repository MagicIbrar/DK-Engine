// PARTY-FINDER: shared-play Party Search windows (server/world/party-finder.mjs owns every rule; nothing here changes the save).
//   partyrecruit   game2/party/ui_partyrecruitwnd_renew.txt "Recruit Party Member" (100:100): map (70:39, matchingmap.csv), level
//                  range (70:40, "Lv" 70:92 / "~ Lv" 70:91, "Level Limit: %d ~ %d" 70:122), jobs (70:90, btn_class_0..14) and the
//                  options Auto Party Request / Set password / Just my server / Auto leave party (70:137 / 168 / 170 / 176).
//   partysearch    game2/party/ui_partyfindwnd_renew.txt "Party Search" (100:99): three maps, "My server" (70:175); Search
//                  (2000:40) lists the parties, Ok (2000:15) starts Looking for a Party (70:104) and lists them.
//   partyfind      game2/party/ui_partylistwnd_renew.txt "Party List" (70:132): No / Map / Participants / Party Name / Request /
//                  lock (160:14, 70:134, 160:16, 70:135, 70:143, Inven_01#4), Refresh (2010:13), lbl_msg 70:153 / 70:154 / 70:155.
//   password       game2/party/ui_partypasswordwnd_renew.txt "Set password" (100:170, 100:171), 4 digits (70:169).
//   party_alarm    game2/party/ui_partyicon.txt helper icon on the HUD alarm grid (150 60) while recruiting or looking; it blinks
//                  while join requests wait, and a click answers them (Allow 70:127 / Decline 70:126).
// The party window's toggle (btn_partyFind_toggle) reads Find / Cancel / Recruit / Cancel (70:76 / 77 / 78 / 79) from here.
// ENGINE-CHOSEN choices are listed in docs/PARTY-FINDER.md.
import {str,strNow,msg,fmt} from '../life/common.js';
import {placeAlarmButton} from '../extras/alarm-slots.js';

export const PF_RECRUIT_SCRIPT='game2/party/ui_partyrecruitwnd_renew.txt';
export const PF_SEARCH_SCRIPT='game2/party/ui_partyfindwnd_renew.txt';
export const PF_LIST_SCRIPT='game2/party/ui_partylistwnd_renew.txt';
export const PF_PASSWORD_SCRIPT='game2/party/ui_partypasswordwnd_renew.txt';
export const PF_ICON_SCRIPT='game2/party/ui_partyicon.txt';
export const PF_CLASSES=15;
export const PF_ALL_CLASSES=(1<<PF_CLASSES)-1;
const STRINGS=[[70,[2,11,39,40,76,77,78,79,81,88,89,90,91,92,104,113,118,121,122,126,127,132,133,134,135,137,140,143,153,154,155,162,163,167,168,169,170,175,176]],
  [100,[99,100,170,171]],[2000,[14,15,22,40]],[2010,[13]],[160,[14,16]]];
// Party List column geometry (freeboard 7 74 456 324, offset 1, titleheight 27, nodeheight 27; widths 40 100 30 190 70 20).
const BOARD={x:7,y:74,head:27,row:27,offset:1,widths:[40,100,30,190,70,20]};
const colX=i=>BOARD.x+BOARD.offset+BOARD.widths.slice(0,i).reduce((a,b)=>a+b,0);

export function installSharedPartyFinder(game,network){
  const ui=game.uiwin;if(!ui?.registerWindow)return null;
  const t=(cate,code,fallback='')=>strNow(game,cate,code)||fallback;
  void Promise.all(STRINGS.flatMap(([cate,codes])=>codes.map(code=>str(game,cate,code).catch(()=>null))));
  const maps=()=>game.party?.P?.matchingMaps||game.life?.data?.party?.matchingMaps||[];
  const mapRow=index=>maps().find(m=>m.index===Number(index))||null;
  const mapName=index=>String(mapRow(index)?.name||'').trim();
  const selfId=()=>network.self?.id;
  const partyState=()=>network.party||game.party?.serverState||null;
  const finder=()=>partyState()?.finder||null;
  const inParty=()=>!!partyState()?.active;
  const isLeader=()=>inParty()&&partyState()?.leaderId===selfId();
  let busy=false,lastQuery={maps:[],sameServer:false},rows=[],shownRequests=new Set(),prompting=false;
  async function send(operation,fields={}){
    if(busy)return null;busy=true;
    try{const r=await network.action('partyfinder',{operation,...fields});return r?r.partyFinderResult||{}:null;}
    finally{busy=false;sync();}
  }
  const say=(code,kind='sys')=>{const [c,n]=String(code).split(':').map(Number);const s=t(c,n);if(s)msg(game,s,kind);};
  // ------------------------------------------------------------------ toggle on the party window
  function toggleText(){
    const f=finder();
    if(inParty())return isLeader()&&f?.recruit?t(70,79,'Cancel'):t(70,78,'Recruit');
    return f?.seeking?t(70,77,'Cancel'):t(70,76,'Find');
  }
  async function toggle(){
    const f=finder();
    if(inParty()){
      if(!isLeader()){say('70:121','err');return null;}
      if(f?.recruit){const r=await send('stop');if(r?.code)say(r.code);return r;}
      return ui.open('partyrecruit');
    }
    if(f?.seeking){const r=await send('unseek');if(r?.code)say(r.code);return r;}
    return ui.open('partysearch');
  }
  // ------------------------------------------------------------------ map selector (label + arrow + list panel)
  function mapSelector(w,suffix,{withNone,onPick}){
    const label=w.control(`lbl_mapname${suffix}`),panel=w.control(`pan_maplist${suffix}`),list=w.control(`list_maplist${suffix}`);
    const items=maps().filter(m=>withNone||m.index>0).map(m=>({text:String(m.name||'').trim(),data:m.index}));
    list.setItems?.(items);
    panel.hide?.();
    const set=index=>{const row=mapRow(index);label.setText(row?String(row.name||'').trim():'');w.data[`map${suffix}`]=row?row.index:0;};
    w.control(`btn_showlist${suffix}`).onClick(()=>{for(const id of w.data.panels||[])if(id!==panel)id.hide?.();panel.setVisible?.(!panel.isVisible?.());});
    (w.data.panels||=[]).push(panel);
    list.on?.('select',(i,item)=>{const index=item?.data??items[i]?.data;set(index);panel.hide?.();onPick?.(mapRow(index));});
    set(0);return set;
  }
  // ------------------------------------------------------------------ password (4 digits)
  async function askPassword(){
    const win=await ui.create(PF_PASSWORD_SCRIPT,{name:'partypassword',modal:true,escClose:true,remember:false,disposeOnClose:true});
    const edit=win.control('edit_text');
    // the script carries a second, stray pan_editBg (7 4 210 12, over the title) whose inner edit is the 4-digit one: keep the
    // framed edit under the text and give it that limit
    for(const c of win.controls?.(k=>k.spec?.id==='pan_editBg')||[])if(c.spec?.rect?.[1]===4)c.hide?.();
    if(edit.input){edit.input.maxLength=4;edit.input.inputMode='numeric';}
    edit.on?.('change',v=>{const d=String(v||'').replace(/[^0-9]/g,'').slice(0,4);if(d!==v)edit.setValue(d);});
    return new Promise(resolve=>{
      let done=false;const finish=v=>{if(done)return;done=true;resolve(v);win.close('done');};
      const confirm=()=>{const v=String(edit.getValue?.()??'');if(!/^\d{4}$/.test(v)){say('70:169','err');return;}finish(v);};
      win.control('btn_confirm').onClick(confirm);edit.on?.('enter',confirm);
      win.control('btn_cancel').onClick(()=>finish(null));
      win.once?.('close',()=>{if(!done){done=true;resolve(null);}});
      ui.openWindow(win);win.center?.();setTimeout(()=>edit.focus?.(),0);
    });
  }
  // ------------------------------------------------------------------ Recruit Party Member
  function levelLimit(w,row){
    w.control('lbl_level_Limit').setText(row&&row.index?fmt(t(70,122,'Level Limit: %d ~ %d'),row.limitMin,row.limitMax):'');
  }
  function paintClasses(w){
    for(let i=0;i<PF_CLASSES;i++){const on=((w.data.classes>>>i)&1)===1;w.control(`btn_class_${i}`).setChecked?.(on);w.control(`pan_class_${i}`).setVisible(!on);}
  }
  function createRecruit(w){
    w.data.classes=PF_ALL_CLASSES;w.data.password='';
    mapSelector(w,'',{withNone:false,onPick:row=>{
      if(!row)return;w.control('edit_level_1').setValue(String(row.min||row.limitMin||1));w.control('edit_level_2').setValue(String(row.max||row.limitMax||1));levelLimit(w,row);
    }});
    for(const id of ['edit_level_1','edit_level_2']){const e=w.control(id);if(e.input)e.input.inputMode='numeric';e.on?.('change',v=>{const d=String(v||'').replace(/[^0-9]/g,'').slice(0,3);if(d!==v)e.setValue(d);});}
    for(let i=0;i<PF_CLASSES;i++){
      w.control(`btn_class_${i}`).onClick(()=>{w.data.classes^=1<<i;paintClasses(w);});
      w.control(`pan_class_${i}`).setTooltip?.(()=>'');
    }
    paintClasses(w);
    for(const id of ['btn_auto','btn_normal','btn_autokick']){const b=w.control(id);b.onClick(()=>b.setChecked?.(!b.isChecked?.()));}
    const pw=w.control('btn_password');
    pw.onClick(async()=>{
      if(w.data.password){w.data.password='';pw.setChecked?.(false);return;}
      const v=await askPassword();w.data.password=v||'';pw.setChecked?.(!!v);
    });
    w.control('btn_ok').onClick(async()=>{
      const num=id=>{const v=String(w.control(id).getValue?.()??'').trim();return /^\d+$/.test(v)?Number(v):NaN;};
      const fields={map:w.data.map||0,minLevel:num('edit_level_1'),maxLevel:num('edit_level_2'),classes:w.data.classes,
        auto:!!w.control('btn_auto').isChecked?.(),sameServer:!!w.control('btn_normal').isChecked?.(),autoKick:!!w.control('btn_autokick').isChecked?.()};
      if(!fields.map||!Number.isInteger(fields.minLevel)||!Number.isInteger(fields.maxLevel)||!fields.classes){say('70:81','err');return;}
      if(w.data.password)fields.password=w.data.password;
      const r=await send('recruit',fields);
      if(r?.code){say(r.code);w.close('done');}
    });
  }
  // ------------------------------------------------------------------ Party Search
  function createSearch(w){
    for(let i=0;i<3;i++)mapSelector(w,`_${i}`,{withNone:true});
    const query=()=>({maps:[0,1,2].map(i=>w.data[`map_${i}`]||0).filter(Boolean),sameServer:!!w.control('check_box').isChecked?.()});
    w.control('btn_list').onClick(async()=>{const q=query();w.close('done');await showList(q,'list');});
    w.control('btn_ok').onClick(async()=>{
      const q=query();if(!q.maps.length){say('70:113','err');return;}
      w.close('done');await showList(q,'seek');
    });
  }
  // ------------------------------------------------------------------ Party List
  let listWin=null;
  async function showList(query,operation='list'){
    lastQuery={maps:[...(query?.maps||[])],sameServer:!!query?.sameServer};
    const w=await ui.open('partyfind');
    w?.control?.('lbl_msg')?.setText(t(70,153,'Searching parties...'));
    const r=await send(operation,{...(lastQuery.maps.length||operation==='seek'?{maps:lastQuery.maps}:{}),sameServer:lastQuery.sameServer});
    if(!r){w?.control?.('lbl_msg')?.setText('');return null;}
    if(r.code)say(r.code);
    rows=Array.isArray(r.parties)?r.parties:[];renderList();
    return r;
  }
  function overlay(w,k){
    const id=`_r${k}`;let join=w.data.join?.[k],lock=w.data.lock?.[k];
    if(!join){
      join=w.control('btn_refresh').cloneAs(id,{x:colX(4)+2,y:BOARD.y+BOARD.head+k*BOARD.row+2,visible:false});
      join.setRect?.(colX(4)+2,BOARD.y+BOARD.head+k*BOARD.row+2,BOARD.widths[4]-4,BOARD.row-4);
      join.setSprite?.('party_renew',35);join.setImage?.('over','party_renew',36);join.setImage?.('down','party_renew',37);
      join.onClick(()=>{const board=w.control('freeboard');void request(rows[(board.top||0)+k]);});
      lock=w.control('pan_locktitle').cloneAs(id,{x:colX(5)+2,y:BOARD.y+BOARD.head+k*BOARD.row+6,visible:false});
      // the clones sit over the freeboard rows (layer 100): keep them above the row cells so the click reaches the button
      for(const c of [join,lock])if(c.el?.style)c.el.style.zIndex='300';
      (w.data.join||=[])[k]=join;(w.data.lock||=[])[k]=lock;
    }
    return {join,lock};
  }
  function renderList(){
    const w=listWin;if(!w?.isOpen)return;
    const board=w.control('freeboard'),f=finder();
    const pendingId=f?.pending?.partyId||null;
    board.setRows?.(rows.map(r=>({cells:[String(r.no),mapName(r.map),`${r.members}/${r.max}`,r.name,'',''],data:r,color:r.partyId===pendingId?'#929292':null})));
    const shown=Math.max(0,Math.min(rows.length-(board.top||0),Math.floor((324-BOARD.head)/BOARD.row)));
    for(let k=0;k<Math.max(shown,w.data.join?.length||0);k++){
      const {join,lock}=overlay(w,k),row=rows[(board.top||0)+k];
      join.setVisible(k<shown&&!!row);lock.setVisible(k<shown&&!!row?.password);
      if(row){join.setText?.(t(70,143,'Request'));join.setEnabled?.(row.partyId!==pendingId);}
    }
    const line=rows.length?t(70,154,'<VALUE1> parties have been found.').replace('<VALUE1>',String(rows.length)):t(70,155,'No search results found.'),label=w.control('lbl_msg');
    if(/<color/i.test(line)&&typeof label?.setRichText==='function')label.setRichText(line);else label?.setText(line.replace(/<[^>]+>/g,''));
  }
  function createList(w){
    listWin=w;
    w.control('btn_refresh').onClick(()=>{void showList(lastQuery,'list');});
    const board=w.control('freeboard');
    if(board?.render){const base=board.render.bind(board);board.render=(...a)=>{base(...a);if(board._pfPainting)return;board._pfPainting=true;try{renderOverlaysOnly(w);}finally{board._pfPainting=false;}};}
    board.on?.('dblclick',(i,r)=>{void request(r?.data||rows[i]);});
    board.on?.('cellclick',(i,col,r)=>{if(col===4)void request(r?.data||rows[i]);});
  }
  function renderOverlaysOnly(w){
    const board=w.control('freeboard'),pendingId=finder()?.pending?.partyId||null;
    const shown=Math.max(0,Math.min(rows.length-(board.top||0),Math.floor((324-BOARD.head)/BOARD.row)));
    for(let k=0;k<(w.data.join?.length||0);k++){const row=rows[(board.top||0)+k];w.data.join[k].setVisible(k<shown&&!!row);w.data.lock[k].setVisible(k<shown&&!!row?.password);if(row)w.data.join[k].setEnabled?.(row.partyId!==pendingId);}
  }
  async function request(row){
    if(!row?.partyId)return null;
    let password;
    if(row.password){password=await askPassword();if(!password)return null;}
    const r=await send('request',{partyId:row.partyId,...(password?{password}:{})});
    if(r?.joined){listWin?.close?.('done');}
    else if(r?.requested)renderList();
    return r;
  }
  // ------------------------------------------------------------------ leader: join requests
  async function answerNext(){
    const f=finder();if(prompting||!f?.requests?.length)return;
    const next=f.requests.find(r=>!shownRequests.has(r.id))||f.requests[0];if(!next)return;
    prompting=true;shownRequests.add(next.id);
    try{
      const answer=await ui.msgbox(`${next.name}  ${t(70,92,'Lv')} ${next.level}`,{kind:'yesno',title:t(100,100,'Recruit Party Member'),yes:t(70,127,'Allow'),no:t(70,126,'Decline'),name:`partyfinder_request_${next.id}`});
      if(finder()?.requests?.some(r=>r.id===next.id))await send('answer',{requestId:next.id,allow:answer==='yes'});
    }finally{prompting=false;}
    if(finder()?.requests?.some(r=>!shownRequests.has(r.id)))void answerNext();
  }
  // ------------------------------------------------------------------ HUD helper icon
  let opening=false;
  async function syncAlarm(){
    const f=finder(),on=!!(f?.recruit||f?.seeking);
    if(on&&!ui.isOpen?.('party_alarm')&&!opening){opening=true;try{await ui.open('party_alarm');}finally{opening=false;}}
    else if(!on&&ui.isOpen?.('party_alarm'))ui.close?.('party_alarm');
    const w=ui.window?.('party_alarm');if(!w?.isOpen)return;
    const b=w.control('btn_alarm');placeAlarmButton(ui,w,b);
    b.setBlink?.(!!f?.requests?.length);
  }
  async function alarmClick(){
    const f=finder();
    if(f?.requests?.length){shownRequests.clear();return answerNext();}
    if(f?.recruit)return ui.open('party');
    if(f?.seeking)return showList({maps:f.seeking.maps,sameServer:f.seeking.sameServer},'list');
    return null;
  }
  // ------------------------------------------------------------------ registration
  ui.unregisterWindow?.('partyfind');
  ui.registerWindow('partyfind',{script:PF_LIST_SCRIPT,create:w=>createList(w),onOpen:w=>{listWin=w;w.center?.();renderList();}});
  ui.registerWindow('partyrecruit',{script:PF_RECRUIT_SCRIPT,create:w=>createRecruit(w),onOpen:w=>w.center?.()});
  ui.registerWindow('partysearch',{script:PF_SEARCH_SCRIPT,create:w=>createSearch(w),onOpen:w=>w.center?.()});
  ui.registerWindow('party_alarm',{script:PF_ICON_SCRIPT,hud:true,band:'hud',escClose:false,remember:false,
    create:w=>{const b=w.control('btn_alarm');b.onClick(()=>{void alarmClick();});b.setTooltip?.(()=>finder()?.recruit?t(100,100,'Recruit Party Member'):t(100,99,'Party Search'));}});
  function sync(){
    const f=finder();
    for(const id of [...shownRequests])if(!f?.requests?.some(r=>r.id===id))shownRequests.delete(id);
    if(f?.requests?.some(r=>!shownRequests.has(r.id)))void answerNext();
    if(listWin?.isOpen)renderOverlaysOnly(listWin);
    void syncAlarm();
  }
  game.events?.on?.('server:party',()=>sync());
  const event=network._event.bind(network);
  network._event=record=>{
    if(record?.type!=='partyfinder'){event(record);return;}
    const code=String(record.code||'');
    if(code==='70:11'||code==='70:2'){const [c,n]=code.split(':').map(Number);msg(game,`${record.name||''} ${t(c,n).trim()}`.trim(),'sys');}
    else if(code==='70:162'||code==='70:140')say(code,'err');
    else if(code==='70:163')say(code);
  };
  const api={toggle,toggleText,showList,request,answerNext,sync,send,get rows(){return rows;}};
  game.partyFinder=api;
  return api;
}
