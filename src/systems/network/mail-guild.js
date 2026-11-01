import {openGuildSiegeRoster} from './guild-siege-roster.js';
import {delegatePhrase,STR as GUILD_STR} from '../extras/guildextras-rules.js';
import { declineBlockedInvitation } from '../hud-options/invitation-policy.js';
import {randomUUID} from './web-crypto.js';
import {setItemIcon,numText,msg,canGive,canGiveAll} from '../life/common.js';
import {askAmount} from '../items/ui/dialogs.js';
import {atlas} from '../../ui/atlas.js';
import {GLORY_STR,GLORY_TEXT} from '../extras/guild-glory-rules.js';
import {repairGuildDonationClose} from '../extras/guild-ui-clone-repair.js';
import {globalAsk} from '../../ui/uiwin/global-asks.js';
import {globalConfirm} from '../../ui/uiwin/global-windows.js';

// Selectable original guild mark cells (script/ui/com/imagetable.txt guild_bg_40a/b, guild_icon_40a..f);
// server/world/guilds.mjs GUILD_MARK_RANGE validates the same bounds.
const MARK_RANGE={bg:221,icon:783},MARK_PAGE=60,MARK_COLS=20;

/** Adapt the existing life windows without opening the local account mail store.
 * Install after network restrictions; snapshots carry mail and guild privately.
 */
export function installSharedMailGuild(game,network){
  const mail=game.life?.mail,guild=game.life?.guild;
  let busy=false,disposed=false,attachment=null,readWin=null,noticeWin=null,prompted=new Set();
  const details=new Map();
  const rankEditors=new Set();
  let siegeRosterWindow=null,siegeRosterMaking=null,delegatePending=false;
  const blankMail={available:false,revision:0,inbox:[],sent:[]},blankGuild={available:false,revision:0,founded:false,members:[],invites:[],gpoint:0,dil:0,contribution:0,notice:''};
  const ms=()=>network.mail||blankMail,gs=()=>network.guild||blankGuild;
  const report=text=>msg(game,text,'err');
  const enable=(control,value)=>{if(control.enabled!==value)control.setEnabled(value);};
  async function send(type,operation,fields={}){
    const state=type==='mail'?ms():gs();
    if(disposed||busy)return false;
    if(!state.available){report('This server has no durable social service.');return false;}
    busy=true;refresh();
    try{
      const result=await network.action(type,{operation,...(['chat','officerChat','view'].includes(operation)?{}:{revision:state.revision,requestId:randomUUID()}),...fields});
      if(type==='mail'&&result?.mailDetail)details.set(result.mailDetail.id,result.mailDetail);
      return result||false;
    }
    finally{busy=false;refresh();}
  }
  const clearCompose=w=>{attachment=null;for(const id of ['edit_receivename','edit_title','edit_dil'])w.control(id).setValue?.('');w.control('textbox').setText?.('');setItemIcon(game,w.control('letter_item'),0);};
  function renderRead(w,record){
    if(!w||!record)return;
    record={...details.get(record.id),...record};
    w.data.mail=record;
    w.control('lbl_sendername').setText(record.from||'System');w.control('lbl_Systemletter').setVisible(record.from==='System');
    w.control('lbl_subject').setText(record.title||'');w.control('textbox').setText?.(record.content||'');
    setItemIcon(game,w.control('giveitem'),record.item||0,record.itemCount||0,40,40);
    w.control('btn_item').setEnabled(!!record.item&&!busy);w.control('btn_money').setEnabled(record.dil>0&&!busy);
    w.control('lbl_money').setText(record.dil>0?numText(record.dil):'');
    w.control('btn_delete').setEnabled(!busy&&!record.item&&!record.dil);
  }
  if(mail){
    mail.inbox=()=>ms().inbox;mail.sent=()=>ms().sent;
    mail.receiveSystem=()=>{report('System mail requires a server reward service.');return false;};
    mail._fillCharList=w=>{const names=[...network.players.values()].map(p=>p.name).filter(Boolean);w.control('list_friend').setItems?.(names.length?names:['(enter a recipient name)']);};
    const originalCreate=mail._create.bind(mail);
    mail._create=w=>{
      originalCreate(w);
      w.control('send_maillist').off?.('dblclick');
      w.control('send_maillist').on('dblclick',async i=>{const record=mail.sent()[i];if(!record)return;
        const result=await send('mail','view',{id:record.id,box:'sent'});if(result?.mailDetail)await game.uiwin.msgbox(`To ${record.toName}:\n${result.mailDetail.content||''}`,{kind:'ok'});});
      w.control('letter_item').acceptDrop?.({referenceSource:'bag',referenceLabel:'Mail attachments',accept:d=>d?.kind==='item'&&d.from==='bag',drop:d=>{
        if(busy)return false;
        const item=game.items?.bag?.list?.find(i=>i.uid===d.inst?.uid),count=d.count||item?.count||1;
        if(!item||!Number.isInteger(count)||count<1||count>(item.count||1))return false;
        attachment={uid:item.uid,count};setItemIcon(game,w.control('letter_item'),item.itemIndex,count);return true;
      }});
      w.control('letter_item').onRightClick?.(()=>{if(!busy){attachment=null;setItemIcon(game,w.control('letter_item'),0);}});
      w.control('btn_cancel').off?.('click');
      w.control('btn_cancel').onClick(()=>{if(!busy)clearCompose(w);});
    };
    const originalRefresh=mail._refresh.bind(mail);
    mail._refresh=w=>{
      originalRefresh(w);w.control('btn_send').setEnabled(ms().available&&!busy);
      for(const id of ['edit_receivename','edit_title','edit_dil','textbox','btn_cancel','btn_listbox','btn_million','btn_100thousand','btn_10thousand','letter_item'])w.control(id).setEnabled(!busy);
      w.control('lbl_tagtax').setText(ms().postage==null?'Mail postage unavailable':`Postage: ${numText(ms().postage)} DIL`);
    };
    mail._send=async w=>{
      if(busy)return false;
      const amount=Number(w.control('edit_dil').getNumber?.()??w.control('edit_dil').getValue?.()??0);
      if(!Number.isSafeInteger(amount)||amount<0){report('Enter a whole DIL amount.');return false;}
      const fields={toName:w.control('edit_receivename').getValue?.()||'',title:w.control('edit_title').getValue?.()||'',content:w.control('textbox').getText?.()||'',dil:amount,...(attachment||{})};
      if(new TextEncoder().encode(JSON.stringify({token:network.token,type:'mail',operation:'send',revision:ms().revision,requestId:'0'.repeat(36),...fields})).length>4096){report('Mail content is too long. Shorten the message.');return false;}
      if(!await send('mail','send',fields))return false;
      msg(game,`Mail sent to ${fields.toName}.`,'sys');clearCompose(w);mail._refresh(w);return true;
    };
    mail._createRead=w=>{
      const warning=w.control('lbl_tagRecieveWarning');warning.setRichText?.('<color=ff0000>Claim items and DIL\nbefore deleting mail.</color>');
      readWin=w;w.control('btn_close').onClick(()=>w.close());
      w.control('btn_delete').onClick(async()=>{if(await mail._delete(w.data.mail))w.close();});
      w.control('btn_reply').onClick(()=>{const record=w.data.mail;w.close();if(record)void mail.composeTo(record.from);});
      w.control('btn_item').onClick(()=>mail._claimItem(w));w.control('btn_money').onClick(()=>mail._claimMoney(w));
    };
    mail._openRead=async(w,record)=>{readWin=w;const current=ms().inbox.find(m=>m.id===record?.id);if(!current){report('That server mail is unavailable.');w.close();return;}
      renderRead(w,current);await send('mail',current.read?'view':'read',{id:current.id,...(current.read?{box:'inbox'}:{})});};
    mail._claimItem=w=>send('mail','claim',{id:w.data.mail?.id,attachment:'item'});
    mail._claimMoney=w=>send('mail','claim',{id:w.data.mail?.id,attachment:'dil'});
    mail._delete=record=>record?send('mail','delete',{id:record.id}):Promise.resolve(false);
    mail.update=()=>{};
  }
  if(guild){
    Object.defineProperty(guild,'st',{get:gs});
    Object.defineProperty(guild,'level',{get:()=>gs().level||1});
    Object.defineProperty(guild,'members',{get:()=>gs().members});
    guild.memberCap=()=>gs().memberCap||0;
    guild._siegeRoster=async()=>{if(siegeRosterWindow?.win.isOpen)return siegeRosterWindow.win;if(siegeRosterMaking)return siegeRosterMaking;
      siegeRosterMaking=openGuildSiegeRoster(game,{state:gs,current:()=>!disposed,send:fields=>send('guild','siegeRoster',fields)}).then(window=>{siegeRosterWindow=window;return window?.win;});try{return await siegeRosterMaking;}finally{siegeRosterMaking=null;}};
    game.chat?.registerCommand?.('/gsiege',()=>{void guild._siegeRoster();return true;},'Select classic siege participants (Guild Master).');
    const originalRefresh=guild._refresh.bind(guild);
    guild._refresh=w=>{originalRefresh(w);const s=gs();w.control('lbl_memberCnt').setText(`${s.members.length} / ${s.memberCap||0}`);w.control('lbl_mygrade').setText(s.myGrade||'');w.control('lbl_dungeonclass').setText(s.frontierRanking?.award?String(s.frontierRanking.award.dungeonGrade):'-');w.control('lbl_mycontribute').setText(String(s.contribution||0));enable(w.control('btn_notice'),(s.permissions?.notice??s.myGrade==='Guild Master')&&!busy);enable(w.control('btn_dilpoint'),!busy);enable(w.control('btn_advanture'),!busy);
      w.control('lbl_GUILD_GPOINT').setText(String(s.activityPoints||0));const fraction=s.activityRatio?Math.max(0,Math.min(1,(s.playPoints||0)/s.activityRatio)):0;w.control('BAR_GPOINT').setGauge(fraction);w.control('lbl_BARPER').setText(`${Math.floor(fraction*100)}%`);};
    guild._create=w=>{
      guild.win=w;
      w.control('btn_manage').onClick(()=>{const panel=w.control('pan_managePop');panel.setVisible(!panel.isVisible());w.control('pan_funcPop').hide();});
      w.control('btn_func').onClick(()=>{const panel=w.control('pan_funcPop');panel.setVisible(!panel.isVisible());w.control('pan_managePop').hide();});
      const roster=()=>game.uiwin.msgbox(gs().members.map(m=>`${m.name}: ${m.grade}`).join('\n'),{kind:'ok',title:'Guild Members'});
      w.control('btn_state').onClick(roster);w.control('btn_power').onClick(()=>guild._editRanks());
      w.control('btn_notice').onClick(()=>guild._editNotice());w.control('btn_secede').onClick(()=>guild._disband());w.control('btn_dilpoint').onClick(()=>guild._deposit());
      w.control('textbox').setEnabled(true); // Original notice display stays read-only; allow ordinary scrolling and legible text.
      w.control('btn_advanture').onClick(()=>guild._donateAdv());
      // GUILD-DUNGEON-RANK (src/systems/extras/guildrank.js): the original Frontier Ranking window.
      w.control('btn_ranking').onClick(()=>{if(game.guildRank)void game.guildRank.open();else report('This guild service is unavailable on the server.');});
      // GUILD-BOARD (src/systems/extras/guildboard.js): Best Guild War representatives + the Record tab.
      w.control('btn_bestbattle').onClick(()=>{w.control('pan_managePop').hide();void game.guildBoard?.openBest?.();});
      w.control('btn_history').onClick(()=>{if(game.guildBoard?.openHistory?.())w.close();});
    };
    guild._open=async w=>{if(!gs().available){report('This server has no durable guild service.');return false;}if(!gs().founded){w.close();return guild._createFlow();}guild._refresh(w);};
    guild._createFlow=async()=>{
      if(!gs().available){report('This server has no durable guild service.');return false;}
      const w=await game.uiwin.create('game2/guild/ui_nameinputwnd.txt',{modal:true,name:'guildcreate'});
      w.control('lbl_msg').setText(`Found a guild for ${numText(Number(guild.cfg.MONEY)||0)} DIL at the guild service?`);
      w.control('btn_no').onClick(()=>w.close());
      w.control('btn_yes').onClick(async()=>{if(await send('guild','create',{name:w.control('edit_text').getValue?.()||''})){w.close();msg(game,`[Guild] "${gs().name}" founded.`,'sys');}});w.open();
    };
    guild._editNotice=async()=>{
      if(noticeWin?.isOpen)return noticeWin;
      const w=noticeWin=await game.uiwin.create('game2/guild/ui_noticewnd.txt',{name:'sharedguildnotice',modal:true,escClose:true,remember:false,disposeOnClose:true});
      w.control('lbl_title').setText('Guild Notice');w.control('textbox').setText(gs().notice||'');
      w.control('btn_deleteAll').onClick(()=>{if(!busy)w.control('textbox').setText('');});
      w.control('btn_regist').onClick(async()=>{if(await send('guild','notice',{notice:w.control('textbox').getText?.()||''}))w.close();});
      w.open();return w;
    };
    guild._deposit=async()=>{const bundle=gs().dilBundle||Number(guild.cfg.DILTOCON);if(!Number.isSafeInteger(bundle)||bundle<1){report('Guild donation rules are unavailable.');return false;}
      const units=await askAmount({game},`DIL: ${numText(bundle)} per unit`,Math.floor((Number(game.save.dil)||0)/bundle));return units!=null&&send('guild','deposit',{amount:units*bundle});};
    guild._donateAdv=async()=>{
      const s=gs(),bundle=s.advBundle;if(!Number.isSafeInteger(bundle)||bundle<1){report('Adventure donation rules are unavailable.');return false;}
      const w=await game.uiwin.create('game2/guild/ui_givepointwnd.txt',{name:'sharedguildadv',modal:true,escClose:true,remember:false,disposeOnClose:true});
      repairGuildDonationClose(w,atlas.table);
      w.control('lbl_guildPoint').setText(numText(s.gpoint||0));w.control('lbl_advan').setText(numText(s.adventurePoints||0));w.control('lbl_tagGivePoint').setText('Bundles to donate');w.control('lbl_unit').setText('');w.control('edt_unit').setValue('0');
      const step=delta=>{if(!busy)w.control('edt_unit').setValue(Math.max(0,Math.min(Math.floor((s.adventurePoints||0)/bundle),(Number(w.control('edt_unit').getValue())||0)+delta)));};
      w.control('btn_up').onClick(()=>step(1));w.control('btn_down').onClick(()=>step(-1));
      w.control('btn_exit').onClick(()=>w.close());w.control('btn_cancel').onClick(()=>w.close());
      w.control('btn_givePoint').onClick(async()=>{const units=Number(w.control('edt_unit').getValue());if(!Number.isSafeInteger(units)||units<1){report('Enter whole bundles of Adventure Points.');return;}if(await send('guild','donateAdv',{amount:units*bundle}))w.close();});w.open();return w;
    };
    guild._levelUp=async()=>{const next=gs().nextLevel;if(!next){report('Guild level upgrade is unavailable.');return false;}const w=await game.uiwin.create('game2/guild/ui_levelupwnd.txt',{name:'sharedguildlevel',modal:true,disposeOnClose:true});
      w.control('textbox').setText(`Raise guild to level ${next.level}?\nConsumes ${numText(next.guildPoints)} Guild Points\nand ${numText(next.activityPoints)} GPOINTs.`);w.control('btn_no').onClick(()=>w.close());w.control('btn_exit').onClick(()=>w.close());w.control('btn_yes').onClick(async()=>{if(await send('guild','levelUp'))w.close();});w.open();return w;};
    guild._editRanks=async()=>{
      const s=gs();if(!s.ranks?.length){report('Guild rank settings are unavailable.');return false;}
      const draft=structuredClone(s.ranks),editable=()=>gs().founded&&gs().id===s.id&&(gs().permissions?.setAuthorities??gs().master===gs().myRef);
      const w=await game.uiwin.create('game2/guild/ui_gradewnd.txt',{name:'sharedguildranks',modal:true,disposeOnClose:true});let selected=0;
      const permissions=[[0,'invite'],[1,'notice'],[2,'kick'],[4,'changeRank'],[6,'setAuthorities'],[7,'staffChat']];
      const refreshEditor=()=>{
        if(!w.isOpen)return;
        if(disposed||!gs().founded||gs().id!==s.id){w.close();return;}
        const allowed=editable()&&!busy;
        enable(w.control('edit_gradeName'),allowed);enable(w.control('btn_apply'),allowed);
        for(const [i]of permissions)enable(w.control(`btn_check_${i}`),allowed&&selected!==0);
      };
      rankEditors.add(refreshEditor);w.once('close',()=>rankEditors.delete(refreshEditor));
      for(let i=0;i<draft.length;i++)for(const [,key]of permissions)draft[i].permissions[key]??=i===0;
      w.control('lbl_msg').setText('Names: up to 8 characters. New members: rank 10.\nInvite, Announcement, Expel, Ranks, Authorities, Staff Chat. Apply to save.');
      function store(){draft[selected].name=String(w.control('edit_gradeName').getValue()||'');}
      function show(){
        for(let i=0;i<10;i++){w.control(`btn_list_${i}`).setText(draft[i].name);w.control(`btn_list_${i}`).setChecked(i===selected);}
        w.control('edit_gradeName').setValue(draft[selected].name);enable(w.control('edit_gradeName'),editable()&&!busy);
        for(let i=0;i<15;i++){w.control(`btn_check_${i}`).setChecked(false);enable(w.control(`btn_check_${i}`),false);}
        for(const [i,key]of permissions){w.control(`btn_check_${i}`).setChecked(draft[selected].permissions[key]);enable(w.control(`btn_check_${i}`),editable()&&selected!==0&&!busy);}
      }
      for(let i=0;i<10;i++)w.control(`btn_list_${i}`).onClick(()=>{if(busy)return;store();selected=i;show();});
      for(const [i,key]of permissions)w.control(`btn_check_${i}`).onClick(()=>{if(!editable()||selected===0||busy)return;draft[selected].permissions[key]=!draft[selected].permissions[key];w.control(`btn_check_${i}`).setChecked(draft[selected].permissions[key]);});
      enable(w.control('btn_apply'),editable()&&!busy);w.control('btn_apply').onClick(async()=>{if(!w.isOpen||!editable()||busy)return;store();if(!await globalAsk(game,'changeGradeGuild'))return;if(await send('guild','configureRanks',{ranks:draft}))w.close();});
      w.control('btn_exit').onClick(()=>w.close());show();w.open();refreshEditor();return w;
    };
    guild._setRank=async name=>{
      const member=gs().members.find(m=>m.name.toLowerCase()===String(name).trim().toLowerCase());
      if(!member||!gs().ranks){report('Choose a guild member by name.');return false;}
      const w=await game.uiwin.create('game2/guild/ui_chggradewnd.txt',{name:'sharedguildrank',modal:true,disposeOnClose:true});
      w.control('lbl_memberName').setText(member.name);w.control('combo_grade').setItems(gs().ranks.slice(1).map((r,i)=>({text:`${i+2}: ${r.name}`,value:i+2})));w.control('combo_grade').selectValue?.(member.rank||10);
      w.control('btn_cancel').onClick(()=>w.close());w.control('btn_exit').onClick(()=>w.close());w.control('btn_ok').onClick(async()=>{if(!await globalAsk(game,'changeGradeGuild'))return;if(await send('guild','setRank',{targetRef:member.ref,rank:Number(w.control('combo_grade').getValue())}))w.close();});w.open();return w;
    };
    guild._donateItems=async()=>{
      const period=gs().frontier?.period;if(!period){report('The server has not opened a Frontier donation period.');return false;}
      const w=await game.uiwin.create('game2/guilddungeon/ui_guilddungeondeliverywnd.txt',{name:'sharedguildfrontier',modal:true,disposeOnClose:true}),registered=Array(8).fill(null),rows=guild.G?.deliver||[];
      function preview(){
        const totals={dr:0,contribution:0,exp:0};
        for(let i=0;i<8;i++){const entry=registered[i],row=entry&&rows.find(r=>r.item===entry.itemIndex);setItemIcon(game,w.control(`delivery_item_${i}`),entry?.itemIndex||0,entry?.count||0);if(row)for(const key of Object.keys(totals))totals[key]+=row[key]*entry.count;}
        for(const [id,key]of [['lbl_drpoint','dr'],['lbl_contribution','contribution'],['lbl_exp','exp']])w.control(id).setText(numText(totals[key]));
      }
      // The list remains a source-table reference; registration uses owned bag
      // identities, and neither dropping nor confirming removes local items.
      const list=Array.from({length:Math.min(10,rows.length)},(_,i)=>w.clone?.('pan_deliveryitem',`_${i}`,{x:0,y:i*25}));
      const renderList=()=>{const top=Number(w.control('body_scroll').getValue())||0;for(let i=0;i<list.length;i++){
        const row=rows[top+i];list[i]?.setVisible(!!row);if(!row)continue;
        w.control(`lbl_itemname_${i}`).setText(game.items?.def?.(row.item)?.name||`Item ${row.item}`);w.control(`lbl_itempoint_${i}`).setText(numText(row.dr));
      }};
      w.control('body_scroll').setRange?.(Math.max(0,rows.length-10),10);w.control('body_scroll').on('change',renderList);renderList();
      for(let i=0;i<8;i++){
        w.control(`delivery_item_${i}`).acceptDrop?.({referenceSource:'bag',referenceLabel:'Guild delivery',accept:d=>d?.kind==='item'&&d.from==='bag',drop:d=>{
          if(busy)return false;const item=game.items?.bag?.list?.find(item=>item.uid===d.inst?.uid),count=d.count??item?.count??1;
          if(!item||!rows.some(row=>row.item===item.itemIndex)||!Number.isSafeInteger(count)||count<1||count>(item.count||1))return false;
          for(let j=0;j<8;j++)if(registered[j]?.uid===item.uid)registered[j]=null;
          registered[i]={uid:item.uid,itemIndex:item.itemIndex,count};preview();return true;
        }});w.control(`delivery_item_${i}`).onRightClick?.(()=>{if(!busy){registered[i]=null;preview();}});
      }
      w.control('btn_confirm').onClick(async()=>{const items=registered.filter(Boolean).map(({uid,count})=>({uid,count}));if(!items.length){report('Register an owned Frontier item.');return;}if(await send('guild','donateItems',{periodId:period.id,items}))w.close();});
      w.control('btn_cancel').onClick(()=>w.close());w.control('btn_exit').onClick(()=>w.close());preview();w.open();return w;
    };
    // Guild Mark service (NPC job GUILDMARK): original mark select + confirm windows, Guild Master only.
    guild._markSelect=async()=>{
      const s=gs();if(!s.founded){report('You are not in a guild.');return false;}
      if(s.master!==s.myRef){report('Only the Guild Master can register the guild mark.');return false;}
      const w=await game.uiwin.create('game2/guild/ui_markselectwnd.txt',{name:'sharedguildmark',modal:true,escClose:true,remember:false,disposeOnClose:true});
      const pick={bg:s.mark?.bg||1,icon:s.mark?.icon||1},page={bg:Math.floor((pick.bg-1)/MARK_PAGE),icon:Math.floor((pick.icon-1)/MARK_PAGE)};
      const grids={bg:{panel:'pan_markbg',cursor:'pan_bgCursor',small:'guildbg_s',large:'guildbg'},icon:{panel:'pan_mark',cursor:'pan_iconCursor',small:'guildicon_s',large:'guildicon'}},cells={bg:[],icon:[]};
      const pages=kind=>Math.ceil(MARK_RANGE[kind]/MARK_PAGE);
      const paint=()=>{
        for(const kind of ['bg','icon']){
          const g=grids[kind];
          cells[kind].forEach((cell,i)=>{const index=page[kind]*MARK_PAGE+i+1,token=cell._tok={};cell.style.backgroundImage='';cell.style.visibility=index<=MARK_RANGE[kind]?'':'hidden';
            if(index<=MARK_RANGE[kind])void atlas.sprite(g.small,index).then(sp=>{if(cell._tok===token&&sp)cell.style.backgroundImage=`url("${sp.url}")`;});});
          const at=pick[kind]-1-page[kind]*MARK_PAGE,cursor=w.control(g.cursor);cursor.setVisible(at>=0&&at<MARK_PAGE);
          if(at>=0&&at<MARK_PAGE)cursor.move((at%MARK_COLS)*24,Math.floor(at/MARK_COLS)*24);
        }
        w.control('pan_selectguildmarkbg').setImage('none','guildbg',pick.bg);w.control('pan_selectguildmark').setImage('none','guildicon',pick.icon);
      };
      for(const kind of ['bg','icon']){
        const host=w.control(grids[kind].panel).el;
        for(let i=0;i<MARK_PAGE;i++){
          const cell=document.createElement('div');
          cell.style.cssText=`position:absolute;left:${(i%MARK_COLS)*24}px;top:${Math.floor(i/MARK_COLS)*24}px;width:24px;height:24px;pointer-events:auto;cursor:pointer;background-size:100% 100%;background-repeat:no-repeat`;
          cell.addEventListener('click',()=>{const index=page[kind]*MARK_PAGE+i+1;if(index<=MARK_RANGE[kind]&&!busy){pick[kind]=index;paint();}});
          host.appendChild(cell);cells[kind].push(cell);
        }
      }
      for(const [kind,left,right]of [['bg','btn_bgLeft','btn_bgRight'],['icon','btn_iconLeft','btn_iconRight']]){
        w.control(left).onClick(()=>{page[kind]=(page[kind]+pages(kind)-1)%pages(kind);paint();});
        w.control(right).onClick(()=>{page[kind]=(page[kind]+1)%pages(kind);paint();});
      }
      const current=s.mark;w.control('pan_guildmarkbg').setVisible(!!current);w.control('pan_guildmark').setVisible(!!current);
      if(current){w.control('pan_guildmarkbg').setImage('none','guildbg',current.bg);w.control('pan_guildmark').setImage('none','guildicon',current.icon);}
      w.control('btn_exit').onClick(()=>w.close());
      w.control('btn_regist').onClick(async()=>{
        if(busy)return;const cost=gs().markCost;
        const c=await game.uiwin.create('game2/guild/ui_markconfirmwnd.txt',{name:'sharedguildmarkconfirm',modal:true,escClose:true,remember:false,disposeOnClose:true});
        c.control('pan_markBg').setImage('none','guildbg',pick.bg);c.control('pan_markIcon').setImage('none','guildicon',pick.icon);
        c.control('lbl_msg').setText(`Register this guild mark${cost?` for ${numText(cost)} DIL`:''}?`);
        c.control('btn_no').onClick(()=>c.close());c.control('btn_exit').onClick(()=>c.close());
        c.control('btn_yes').onClick(async()=>{if(await send('guild','mark',{bg:pick.bg,icon:pick.icon})){c.close();w.close();msg(game,'[Guild] Guild mark registered.','sys');}});
        c.open();
      });
      paint();w.open();return w;
    };
    // Guild of Glory (itemcash Type 0 Code 16): the glowing emblem effect (extras/guild-glory-rules.js, strings 130:70/121/175/176/177/221)
    const gstr=(ref,text)=>String(game.uiwin?.strings?.get?.({group:'NORMAL',cate:ref[0],code:ref[1]})||text).replace(/<[^>]+>/g,'').trim();
    guild.useGlory=(inst,def)=>{
      const s=gs();
      if(!s.founded){report(GLORY_TEXT.notInGuild);return true;}
      if(s.master!==s.myRef){report(gstr(GLORY_STR.noAuthority,GLORY_TEXT.noAuthority));return true;}
      void (async()=>{
        // Global msgbox/cashitem/ui_adornmentguildmark: 100:18 "Guild of Glory", lbl_text 170:37 "Would you like to use Guild of Glory?"
        if(!await globalConfirm(game,'game2:msgbox:cashitem:ui_adornmentguildmark',gstr([170,37],'Would you like to use Guild of Glory?'),{body:'lbl_text'}))return;
        if(await send('guild','glory',{uid:inst.uid}))msg(game,`[Guild] ${gstr(GLORY_STR.changed,GLORY_TEXT.changed)}`,'sys');
      })();
      return true;
    };
    guild._markDelete=async()=>{
      const s=gs();
      if(s.founded&&s.glory){   // the NPC deletes the glowing emblem EFFECT first (130:176 / 130:177), the mark itself stays
        if(s.master!==s.myRef){report('Only the Guild Master can delete the guild mark.');return false;}
        // Global msgbox/ui_delguildmarkeffect (100:18 "Guild of Glory", lbl_text = the delete question)
        if(!await globalConfirm(game,'game2:msgbox:ui_delguildmarkeffect',gstr(GLORY_STR.deleteAsk,GLORY_TEXT.deleteAsk),{body:'lbl_text'}))return false;
        if(!await send('guild','deleteGlory'))return false;msg(game,`[Guild] ${gstr(GLORY_STR.deleted,GLORY_TEXT.deleted)}`,'sys');return true;
      }
      if(!s.founded||!s.mark){report('The guild has no registered mark.');return false;}
      if(s.master!==s.myRef){report('Only the Guild Master can delete the guild mark.');return false;}
      if(await game.uiwin.msgbox('Delete the registered guild mark?',{kind:'yesno'})!=='yes')return false;
      if(!await send('guild','deleteMark'))return false;msg(game,'[Guild] Guild mark deleted.','sys');return true;
    };
    game.chat?.registerCommand?.('/grank',name=>{void guild._setRank(name);return true;},'Assign a guild member rank: /grank Name');
    game.chat?.registerCommand?.('/gfrontier',()=>{void guild._donateItems();return true;},'Open the original Frontier item donation window.');
    game.chat?.registerCommand?.('/glevel',()=>{void guild._levelUp();return true;},'Open the guild level upgrade confirmation.');
    game.chat?.registerCommand?.('/gcontribution',()=>{const rows=[...gs().members].sort((a,b)=>(b.contribution||0)-(a.contribution||0)||a.name.localeCompare(b.name));void game.uiwin.msgbox(rows.map((m,i)=>`${i+1}. ${m.name}: ${numText(m.contribution||0)}`).join('\n'),{kind:'ok',title:'Guild Contribution'});return true;},'Show current guild member contribution totals.');
    guild._disband=async()=>{const operation=gs().myGrade==='Guild Master'?'disband':'leave';if(!await globalAsk(game,operation==='disband'?'disbandGuild':'secedeGuild'))return false;
      if(!await send('guild',operation))return false;game.uiwin.close('guild');msg(game,`[Guild] ${operation==='disband'?'disbanded':'left'}.`,'sys');return true;};
    guild.donate=(itemIndex,count=1)=>{
      const item=game.items?.bag?.list?.find(i=>i.itemIndex===Number(itemIndex)&&i.count>=count),period=gs().frontier?.period;
      if(!item||!period||!Number.isSafeInteger(count)||count<1){report('Choose an owned Frontier item during an open server period.');return false;}
      return send('guild','donateItems',{periodId:period.id,items:[{uid:item.uid,count}]});
    };
    guild.inviteName=name=>{const target=[...network.players.values()].find(p=>p.name?.toLowerCase()===String(name).trim().toLowerCase());if(!target){report('Choose a nearby connected character.');return false;}return send('guild','invite',{targetId:target.networkId||target.id});};
    const memberIntent=async(operation,name)=>{const member=gs().members.find(m=>m.name.toLowerCase()===String(name).trim().toLowerCase());if(!member){report('Choose a guild member by name.');return false;}
      if(operation==='transfer'){
        if(delegatePending)return false;
        const before=gs(),token=network.token,pair=GUILD_STR.delegatePrompt;
        if(before.master!==before.myRef||member.ref===before.myRef){report('Choose another member as Guild Master.');return false;}
        delegatePending=true;
        try{
          await game.uiwin.strings?.need?.([{group:'NORMAL',cate:pair[0],code:pair[1]}]);
          const prompt=game.uiwin.strings?.get?.({group:'NORMAL',cate:pair[0],code:pair[1]})||"To Appoint the Guild Mastership, please enter 'I appoint'.";
          const typed=await game.uiwin.msgbox(null,{kind:'edit',script:'game2/msgbox/ui_delegateguild.txt',name:'guildDelegateCommand',scripted:true});
          if(typed==null||disposed||network.token!==token||gs().id!==before.id||gs().master!==gs().myRef)return false;
          if(String(typed).trim().toLowerCase()!==(delegatePhrase(prompt)||'I appoint').toLowerCase()){report(String(prompt).replace(/\s+/g,' '));return false;}
          if(!gs().members.some(m=>m.ref===member.ref))return false;
        }finally{delegatePending=false;}
      }
      return send('guild',operation,{targetRef:member.ref});};
    for(const [command,operation,help]of [['/gkick','kick','Remove a guild member: /gkick Name'],['/gleader','transfer','Transfer guild leadership: /gleader Name']])game.chat?.registerCommand?.(command,name=>{void memberIntent(operation,name);return true;},help);
    game.chat?.registerCommand?.('/ginvite',name=>{void guild.inviteName(name);return true;},'Invite a nearby character to your guild.');
    game.chat?.registerCommand?.('/gleave',()=>{void guild._disband();return true;},'Leave your guild or request disbanding.');
    for(const [command,operation]of [['/gaccept','accept'],['/gdecline','decline']])game.chat?.registerCommand?.(command,name=>{
      const invite=gs().invites.find(i=>!name||i.guildName.toLowerCase()===String(name).trim().toLowerCase());
      if(invite)void send('guild',operation,{id:invite.id});else report('No matching pending guild invitation.');return true;
    },`${operation==='accept'?'Accept':'Decline'} a pending guild invitation; optionally enter the guild name.`);
  }
  const pass=game.life?.dekapass;
  if(pass&&typeof pass.claim==='function'){
    const claim=pass.claim.bind(pass),claimAll=pass.claimAll.bind(pass);
    const reward=async fields=>{const result=await send('mail','reward',fields);if(result)msg(game,'Earned DekaPass rewards were delivered to your mailbox.','sys');return result;};
    pass.claim=(level,premium=false)=>{const row=pass.D?.rewards?.[Number(level)-1],entry=row?.[premium?'premium':'basic'];return ms().available&&entry&&!canGive(game,entry[0],entry[1])?reward({level:Number(level),premium:!!premium}):claim(level,premium);};
    pass.claimAll=()=>{const entries=pass._claimable().map(([level,premium])=>pass.D.rewards[level-1][premium?'premium':'basic']);return ms().available&&entries.length&&!canGiveAll(game,entries)?reward({all:true}):claimAll();};
  }
  function refresh(){
    if(disposed)return;
    if(mail?.win?.isOpen)mail._refresh(mail.win);
    const record=ms().inbox.find(m=>m.id===readWin?.data?.mail?.id);if(readWin?.isOpen){if(record)renderRead(readWin,record);else readWin.close();}
    if(guild?.win?.isOpen)guild._refresh(guild.win);
    for(const update of rankEditors)update();
    siegeRosterWindow?.update();
  }
  let invitationOpen=false;
  async function invitation(){
    if(disposed||busy||invitationOpen)return;
    const blocked=gs().invites[0];
    if(blocked&&declineBlockedInvitation(game,'blockGuild',blocked.id,()=>send('guild','decline',{id:blocked.id})))return;
    const invite=gs().invites.find(i=>!prompted.has(i.id));if(!invite)return;prompted.add(invite.id);
    invitationOpen=true;
    try{
      const answer=await globalAsk(game,'joinGuild',`${invite.guildName} (${invite.from})`)?'yes':'no';
      if(!disposed&&gs().invites.some(i=>i.id===invite.id)){
        if(busy||!await send('guild',answer==='yes'?'accept':'decline',{id:invite.id}))report('Guild invitation remains pending. Use /gaccept or /gdecline to retry.');
      }
    }finally{invitationOpen=false;}
  }
  const snapshot=network._snapshot.bind(network);
  network._snapshot=record=>{
    if(network.disposed||Number(record?.sequence)<network.sequence)return;
    network.mail=record.mail||blankMail;network.guild=record.guild||blankGuild;
    const visibleIds=new Set([...ms().inbox,...ms().sent].map(m=>m.id));for(const id of details.keys())if(!visibleIds.has(id))details.delete(id);
    const inviteIds=new Set(gs().invites.map(i=>i.id));for(const id of prompted)if(!inviteIds.has(id))prompted.delete(id);
    snapshot(record);refresh();
    if(mail){const n=mail.unreadCount();if(n!==mail._lastUnread){mail._lastUnread=n;mail._alert();game.events?.emit?.('mail',{unread:n});}}
    void invitation().catch(()=>{});
    // The server derives the daily login/level delta from canonical profile and
    // committed member markers. A snapshot cannot grant any local points.
    if(gs().founded&&gs().activityPending&&!busy&&network.ready)void send('guild','activity').catch(()=>{});
    // D-Shop gifts (171:43 "Gifts are sent to the Cash Inventory."): the host escrows them; this character's own
    // transaction moves them into its Cash Inventory. One attempt per social revision; a refusal leaves them pending.
    if(ms().available&&ms().gifts?.length&&!busy&&network.ready&&giftRevision!==ms().revision){giftRevision=ms().revision;void acceptGifts().catch(()=>{});}
  };
  let giftRevision=null;
  async function acceptGifts(){
    if(disposed||busy)return false;
    const count=ms().gifts.length;busy=true;
    try{
      const result=await network.action('dshopgift',{operation:'accept',revision:ms().revision,requestId:randomUUID()});
      if(result){msg(game,count>1?`${count} gifts have arrived in your Cash Inventory.`:'A gift has arrived in your Cash Inventory.','item');game.events?.emit?.('cashinventory',{reason:'gift'});}
      return result||false;
    }finally{busy=false;refresh();}
  }
  const channel=game.chat?._channel?.bind(game.chat);
  if(channel)game.chat._channel=(type,text)=>{if(!['guild','officer'].includes(type))return channel(type,text);void send('guild',type==='officer'?'officerChat':'chat',{text:String(text||'').trim()});return true;};
  const event=network._event.bind(network);
  // CHAT-LINKS: a chat record's host-made item links reach the chat line that shows it (chat-links.js expect / incoming)
  network._event=record=>{if(record.type==='chat'&&Array.isArray(record.links))game.chat?.links?.expect?.(record);if(record.type==='chat'&&['guild','officer'].includes(record.channel)){game.chat?.say?.(record.channel,record.name||'Player',record.text,Array.isArray(record.links)?{links:record.links}:{});return;}event(record);};
  const dispose=network.dispose.bind(network);
  network.dispose=()=>{disposed=true;siegeRosterWindow?.win.close();game.uiwin?.close?.('guildDelegateCommand');attachment=null;details.clear();for(const update of rankEditors)update();rankEditors.clear();network.mail=null;network.guild=null;dispose();};
  return {send,refresh};
}
