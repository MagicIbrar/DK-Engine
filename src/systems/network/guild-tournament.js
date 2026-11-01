// Shared play: Guild Tournament (Colosseum Lobby 162 -> Guild Tournament map 165). The host runs it
// (server/world/guild-tournament.mjs); this module answers the original NPC jobs and draws snapshot.tourney with the
// original game2/guildtournament windows:
//   Ferdianand 5159: 90 info (View Info = ui_tournamentinfownd, entry list = ui_entryguildwnd, Request Cid =
//     ui_requestseedwnd, Select Players = ui_entrymemberwnd; jobs 88/89/91 have no NPC in the data and are offered
//     here, ENGINE-CHOSEN), 95 enter, 100 watch (ui_todaysmatchwnd_new).
//   Donation Angel 5165: 87 donate (B/P coin amounts of share/guildtournament/donation.csv), 86 ui_donationrankingwnd.
//   Gambler Egg 5166: 92 ui_bettingwnd, 94 ui_rewardbettingwnd, 100 watch.
// Inside a match: ui_battlereadywnd (entry/ready), ui_dashboard (kills, round wins, first kill, timer, own side HP),
// ui_roundendwnd, ui_battlereultwnd and the ui_battlereadyicon button. /leavetourney leaves the match.
// Template controls (ids ending in "_") are cloned with cloneTemplate; spacing is ENGINE-CHOSEN
// (src/config/engine-chosen-guild-tournament.js layout).
import {loadEventData} from '../events/data.js';
import {cloneTemplate} from '../../ui/frontend/ui.js';
import {GUILD_TOURNAMENT_ENGINE_CHOSEN as C} from '../../config/engine-chosen-guild-tournament.js';
import {CLASS_CODES,roundTitleCode,roundCode} from '../events/guild-tournament-rules.js';
const DIR='game2/guildtournament/';
const SCRIPTS={info:'ui_tournamentinfownd',seed:'ui_requestseedwnd',entries:'ui_entryguildwnd',members:'ui_entrymemberwnd',ranking:'ui_donationrankingwnd',
  betting:'ui_bettingwnd',reward:'ui_rewardbettingwnd',today:'ui_todaysmatchwnd_new',ready:'ui_battlereadywnd',roundEnd:'ui_roundendwnd',result:'ui_battlereultwnd',dashboard:'ui_dashboard',icon:'ui_battlereadyicon'};
const L=C.layout;
const npcId=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index);
const mmss=ms=>{const s=Math.max(0,Math.floor(ms/1000));return `${String(Math.floor(s/60)).padStart(2,'0')}:${String(s%60).padStart(2,'0')}`;};
const TITLE={16:1,8:2,4:3,2:4};
/** Find a child control of a cloned template by its script id. */
export function sub(c,id){if(!c)return null;for(const x of c.children||[]){if((x.spec?.id??x.id)===id)return x;const d=sub(x,id);if(d)return d;}return null;}
/** n visible clones of a template control, offset per row by rect(i, baseRect). Extra clones are hidden. */
export function rows(win,tpl,n,rect,key=tpl){
  win._gtRows||={};const list=win._gtRows[key]||=[];const src=win.find?.(tpl);if(!src)return [];src.setVisible?.(false);
  const base=Array.from(src.spec?.rect||[0,0,0,0]).map(Number);
  for(let i=0;i<Math.max(n,list.length);i++){if(i<n&&!list[i])list[i]=cloneTemplate(win,tpl,`${key}${i}g`,rect(i,base));list[i]?.setVisible?.(i<n);}
  return list.slice(0,n);
}
const down=step=>(i,r)=>[r[0],r[1]+i*step,r[2],r[3]];
const text=(c,v)=>c?.setText?.(v==null?'':String(v));
/** Round-of-16 view from the bracket, or a preview from the requested seeds before the lock. */
export function bracketView(t){
  if(t?.bracket?.length)return new Map(t.bracket.map(m=>[m.key,m]));
  const out=new Map(),seeds=t?.seeds||[];for(let k=1;k<=8;k++){const a=seeds[2*k-2],b=seeds[2*k-1];out.set(`16:${k}`,{key:`16:${k}`,match:16,order:k,left:a?.id?{id:a.id,name:a.name}:null,right:b?.id?{id:b.id,name:b.name}:null});}return out;
}
/** Bracket labels (lbl_16_ x8, lbl_8_ x4, lbl_4_0/1, lbl_2_0) and, in the info window, the winner connectors. */
export function fillBracket(win,t,{connectors=false}={}){
  const b=bracketView(t),pair=m=>m?`${m.left?.name||''}\n${m.right?.name||''}`:'';
  rows(win,'lbl_16_',8,down(L.bracket16)).forEach((c,i)=>text(c,pair(b.get(`16:${i+1}`))));
  rows(win,'lbl_8_',4,down(L.bracket8)).forEach((c,i)=>text(c,pair(b.get(`8:${i+1}`))));
  text(win.control('lbl_4_0'),pair(b.get('4:1')));text(win.control('lbl_4_1'),pair(b.get('4:2')));
  const fin=b.get('2:1');text(win.control('lbl_2_0'),t?.champion?.name||pair(fin));
  if(!connectors)return;
  const lit=(up,dn,m)=>{const w=m?.winner;up?.setVisible?.(!!w&&w===m.left?.id);dn?.setVisible?.(!!w&&w===m.right?.id);};
  const ups=rows(win,'pan_win_16_up_',4,down(L.bracket8)),dns=rows(win,'pan_win_16_down_',4,down(L.bracket8));
  for(let i=0;i<4;i++)lit(ups[i],dns[i],b.get(`8:${i+1}`));
  for(let i=0;i<2;i++)lit(win.control(`pan_win_8_up_${i}`),win.control(`pan_win_8_down_${i}`),b.get(`4:${i+1}`));
  lit(win.control('pan_win_4_up_0'),win.control('pan_win_4_down_0'),fin);
}
/** Guild rows (ui_entryguildwnd / ui_donationrankingwnd pan_slot_). */
export function fillGuildRows(win,list,key='slots'){
  rows(win,'pan_slot_',list.length,down(L.rankingRow),key).forEach((c,i)=>{const r=list[i];text(sub(c,'lbl_rank_'),r.rank);text(sub(c,'lbl_server_'),r.server||C.serverName);
    text(sub(c,'lbl_guild_'),r.name);text(sub(c,'lbl_guildmaster_'),r.master||'');text(sub(c,'lbl_guildmember_'),r.members??'');});
}
/** Entrant rows (pan_entry_ with class icon, name, level) for one side; side 1 is shifted one roster column. */
export function fillEntrants(win,list,side,className){
  rows(win,'pan_entry_',list.length,(i,r)=>[r[0]+side*L.rosterColumn,r[1]+i*L.entryRow,r[2],r[3]],`entry${side}_`).forEach((c,i)=>{const e=list[i];
    sub(c,'pan_entry_class_')?.setSprite?.('etc_01',100+(Number(e.classIndex)||0));text(sub(c,'lbl_entry_name_'),e.name);text(sub(c,'lbl_entry_lv_'),e.level);
    c.el?.style&&(c.el.style.opacity=e.down?'0.45':'1');c.el&&(c.el.title=className?.(e.classIndex)||'');});
}
const matchTitles=(win,match)=>{for(let i=1;i<=4;i++)win.control(`pan_matchtitle${i}`)?.setVisible?.(TITLE[match]===i);win.control('pan_matchtitle')?.setVisible?.(true);};
export function installSharedGuildTournament(game,network,sys){
  const state={t:null,data:null,wins:{},seed:null,picked:[],memberScroll:0,rankPage:0,bet:{coin:'P',score:null,amount:C.betStep,editing:false},today:{key:null,scroll:0,npc:null},
    shown:{ready:null,round:null,result:null,open:null},npc:null};
  void loadEventData().then(d=>{state.data=d;}).catch(()=>{});
  const T=(code,fb='')=>{const v=state.data?.txt?.('stringtable_colosseum.txt',360,code);return (v&&String(v).replace(/<center>/gi,'').trim())||fb;};
  const className=i=>T(CLASS_CODES[Number(i)||0],'');
  const report=error=>game.chat?.system?.(error?.message||String(error),'err');
  const say=t=>{if(!t)return;if(game.chat?.system)game.chat.system(t);else game.hud?.log?.(t,'sys');};
  const send=intent=>network.action('tourney',{npcIndex:state.npc??undefined,...intent}).then(r=>{say(r?.tourneyResult?.text);return r;}).catch(report);
  const win=async key=>{const w0=state.wins[key];if(w0&&!w0.disposed)return w0;const w=await game.uiwin?.create?.(DIR+SCRIPTS[key]+'.txt',{name:`ev_gt_${key}`});if(!w)return null;state.wins[key]=w;wire(key,w);return w;};
  const show=async(key,fill)=>{const w=await win(key);if(!w)return null;fill?.(w,state.t);if(!w.isOpen)game.uiwin.openWindow(w);return w;};
  const close=key=>{const w=state.wins[key];if(w?.isOpen)w.close?.('gt');};
  const fillers={
    info:(w,t)=>fillBracket(w,t,{connectors:true}),
    seed:(w,t)=>{fillBracket(w,t);const canSeed=!!t?.my?.master||!t;for(const id of ['btn_requestseed','btn_init','lbl_tag1'])w.control(id)?.setVisible?.(id==='lbl_tag1'||canSeed||!t?.my);const seeds=t?.seeds||Array.from({length:16},(_,i)=>({seed:i+1,id:null}));const mine=t?.my?.guildId;
      rows(w,'btn_seed_',seeds.length,down(L.seedButton)).forEach((c,i)=>{const s=seeds[i];text(c,s.name?`${s.seed} ${s.name}`:String(s.seed));
        c.setEnabled?.(!s.id||s.id===mine);c.setChecked?.(state.seed===s.seed);if(!c._gt){c._gt=1;c.onClick(()=>{state.seed=s.seed;fillers.seed(w,state.t);});}});},
    entries:(w,t)=>{text(w.control('lbl_title'),`${t?.season||1}${T(127,'th Guild Tournament Participant')}`);const list=t?.entries||[];
      rows(w,'pan_back_slot_',Math.ceil(list.length/2),down(52));fillGuildRows(w,list);},
    members:(w,t)=>{const my=t?.my,all=(my?.members||[]).filter(m=>!state.picked.some(p=>p.characterId===m.characterId)),max=10,vis=all.slice(state.memberScroll,state.memberScroll+max);
      rows(w,'btn_member_',vis.length,down(L.memberRow)).forEach((c,i)=>{const m=vis[i];sub(c,'pan_guild_class_')?.setSprite?.('etc_01',100+m.classIndex);text(sub(c,'lbl_member_name_'),m.name);text(sub(c,'lbl_guild_lv_'),m.level);
        c._gtMember=m;if(!c._gt){c._gt=1;c.onClick(()=>{const v=c._gtMember;if(!v)return;if(state.picked.length>=(state.data?.modes?.colosseum?.guildMatch?.maps?.[0]?.members||7))return;
          if(state.picked.some(p=>p.classIndex===v.classIndex))return say(T(182,'You cannot register the same class more than once.'));state.picked.push(v);fillers.members(w,state.t);});}});
      rows(w,'pan_entry_',state.picked.length,down(L.entryRow),'picked_').forEach((c,i)=>{const m=state.picked[i];sub(c,'pan_entry_class_')?.setSprite?.('etc_01',100+m.classIndex);text(sub(c,'lbl_entry_name_'),m.name);text(sub(c,'lbl_entry_lv_'),m.level);
        const x=sub(c,'btn_entry_cancel_');if(x){x._gtIndex=i;if(!x._gt){x._gt=1;x.onClick(()=>{state.picked.splice(x._gtIndex,1);fillers.members(w,state.t);});}}});},
    ranking:(w,t)=>{text(w.control('lbl_title'),`${t?.season||1}${T(18,'th Guild Tournament Donation Ranking')}`);const all=t?.ranking||[],page=state.rankPage;
      w.control('btn_page1')?.setChecked?.(page===0);w.control('btn_page2')?.setChecked?.(page===1);
      fillGuildRows(w,all.filter(r=>page===0?r.candidate===24:r.candidate!==24).slice(0,C.rankingPage));
      const me=all.find(r=>r.id===t?.my?.guildId);for(const [k,v] of [['rank',me?.rank],['server',me?(me.server||C.serverName):''],['guild',me?.name],['guildmaster',me?.master],['guildmember',me?.members]])text(w.control(`lbl_${k}_255`),v??'');},
    betting:(w,t)=>{const b=t?.betting,mine=b?.mine,st=state.bet;if(mine&&!st.editing){st.coin=mine.coin;st.score=mine.score;st.amount=mine.amount;}
      text(w.control('lbl_guild_left'),b?.left||'');text(w.control('lbl_guild_right'),b?.right||'');w.control('btn_p_coin')?.setChecked?.(st.coin==='P');w.control('btn_b_coin')?.setChecked?.(st.coin==='B');
      const scores=b?.scores||C.betScores,locked=!!mine&&!st.editing;
      rows(w,'pan_score_',scores.length,down(L.betRow)).forEach((c,i)=>{const sc=scores[i];const btn=sub(c,'btn_score_');const [l,r]=sc.split(':');text(btn,`${l}${' '.repeat(16)}${r}`);btn?.setChecked?.(st.score===sc);btn?.setEnabled?.(!locked);
        const ratio=b?.ratios?.[st.coin]?.[sc];text(sub(c,'lbl_rate_'),ratio?`x${Math.floor(ratio*100)/100}`:'-');sub(c,'pan_rate_disable')?.setVisible?.(st.score!==sc);sub(c,'pan_rate')?.setVisible?.(st.score===sc);
        if(btn){btn._gtScore=sc;if(!btn._gt){btn._gt=1;btn.onClick(()=>{state.bet.score=btn._gtScore;fillers.betting(w,state.t);});}}});
      const usable=t?.coins?.[st.coin]??0;text(w.control('lbl_betting_coin_title'),T(st.coin==='P'?171:173,''));text(w.control('lbl_usable_coin_title'),T(st.coin==='P'?172:174,''));
      text(w.control('lbl_betting_coin'),st.amount);text(w.control('lbl_usable_coin'),usable);
      w.control('btn_modify')?.setVisible?.(!!mine&&!st.editing);w.control('btn_betting')?.setEnabled?.(!!b&&!locked);},
    reward:(w,t)=>{for(const c of ['p','b'])w.control(`btn_receive_${c}_coin`)?.setVisible?.(true);text(w.control('lbl_p_coin'),t?.pool?.P||0);text(w.control('lbl_b_coin'),t?.pool?.B||0);w.control('btn_receive_p_coin')?.setEnabled?.((t?.pool?.P||0)>0);w.control('btn_receive_b_coin')?.setEnabled?.((t?.pool?.B||0)>0);},
    today:(w,t)=>{const run=t?.match,round=run?.match||(t?.bracket?.find(m=>m.status!=='done')?.match)||16,list=(t?.bracket||[]).filter(m=>m.match===round);matchTitles(w,round);
      const vis=list.slice(state.today.scroll,state.today.scroll+5);
      rows(w,'pan_match_',vis.length,down(L.matchRow)).forEach((c,i)=>{const m=vis[i],live=run?.key===m.key,done=m.status==='done';text(sub(c,'lbl_match_left_'),m.left?.name||'');text(sub(c,'lbl_match_right_'),m.right?.name||'');
        const res=(t?.results||[]).find(r=>r.key===m.key);text(sub(c,'lbl_match_time_'),live?T(({entry:193,ready:194,count:195,battle:196,roundEnd:197,break:199,matchEnd:198})[run.phase]||196,'Battle'):done?(res?.label||(res?.reason==='bye'?'-':'')):'');sub(c,'pan_match_time_end_')?.setVisible?.(done);
        const btn=sub(c,'btn_match_');if(btn){btn._gtKey=m.key;btn.setChecked?.(state.today.key===m.key);if(!btn._gt){btn._gt=1;btn.onClick(()=>{state.today.key=btn._gtKey;fillers.today(w,state.t);});}}});
      const sel=list.find(m=>m.key===(state.today.key||run?.key))||null,cur=sel&&run?.key===sel.key?run:null;
      text(w.control('lbl_guild_left'),sel?.left?.name||'');text(w.control('lbl_guild_right'),sel?.right?.name||'');
      for(const s of [0,1])fillEntrants(w,cur?(cur.sides[s].entrants.length?cur.sides[s].entrants:cur.sides[s].roster):[],s,className);
      const egg=state.today.npc===5166,canWatch=!!run&&!run.inside&&['entry','ready','count','battle','roundEnd','break'].includes(run.phase);
      w.control('btn_enter_audience')?.setVisible?.(true);w.control('btn_enter_audience')?.setEnabled?.(canWatch);const bet=w.control('btn_betting');bet?.setVisible?.(egg&&!!t?.betting);if(egg)bet?.setRect?.(196,385,85,25);},
    ready:(w,t)=>{const run=t?.match;if(!run)return;matchTitles(w,run.match);text(w.control('lbl_title'),`${T(run.phase==='entry'?193:194,'Ready Time')} ${mmss(run.remainingMs)}`);
      text(w.control('lbl_guild_left'),run.sides[0].name);text(w.control('lbl_guild_right'),run.sides[1].name);for(const s of [0,1])fillEntrants(w,run.sides[s].entrants,s,className);},
    roundEnd:(w,t)=>{const run=t?.match;if(!run)return;const last=run.rounds.at(-1)||{winner:-1,kills:[0,0],firstKill:-1};
      text(w.control('lbl_title'),`${T(roundCode(run.rounds.length-1),'Round')} - ${T(153,'Finish Round')}`);w.control('number_redkillcnt')?.setNumber?.(last.kills[0]);w.control('number_bluekillcnt')?.setNumber?.(last.kills[1]);
      text(w.control('lbl_guild_left'),run.sides[0].name);text(w.control('lbl_guild_right'),run.sides[1].name);
      w.control('pan_guild_left_firstkill')?.setVisible?.(last.firstKill===0);w.control('pan_guild_right_firstkill')?.setVisible?.(last.firstKill===1);
      w.control('pan_left')?.setVisible?.(last.winner===0);w.control('pan_right')?.setVisible?.(last.winner===1);w.control('pan_draw')?.setVisible?.(last.winner!==0&&last.winner!==1);
      w.control('pan_shade_left')?.setVisible?.(last.winner===1);w.control('pan_shade_right')?.setVisible?.(last.winner===0);
      for(const s of [0,1])fillEntrants(w,run.sides[s].entrants,s,className);},
    result:(w,t)=>{const run=t?.match,res=run?.result;if(!run||!res)return;const names=run.sides.map(s=>s.name),win=res.winner;
      text(w.control('lbl_win_message'),win===0||win===1?`${names[win]} ${T(176,'Guild won.')}`:res.reason==='disqualified'?T(206,'Both teams disqualified'):T(177,'The match ended in a tie.'));
      for(const [k,s] of [['left',0],['right',1]]){w.control(`pan_score_${k}`)?.setImage?.('none',{screen:'guildtournament',index:C.scoreDigitBase+Math.min(9,res.wins[s]||0)});w.control(`pan_win_${k}`)?.setVisible?.(win===s);text(w.control(`lbl_win_guild_${k}`),names[s]);}
      const rounds=res.rounds||run.rounds||[];
      rows(w,'pan_result_',rounds.length,down(L.resultRow)).forEach((c,i)=>{const r=rounds[i];text(sub(c,'lbl_round_'),T(roundCode(i),`Round ${i+1}`));text(sub(c,'lbl_guild_left_'),r.kills[0]);text(sub(c,'lbl_guild_right_'),r.kills[1]);
        sub(c,'pan_guild_left_firstkill_')?.setVisible?.(r.firstKill===0);sub(c,'pan_guild_right_firstkill_')?.setVisible?.(r.firstKill===1);text(sub(c,'lbl_win_guild_'),r.winner===0||r.winner===1?names[r.winner]:T(189,'Draw').replace(/<[^>]+>/g,''));});},
    dashboard:(w,t)=>{const run=t?.match;if(!run)return;const [a,b]=run.sides;text(w.control('lbl_redsign'),a.name);text(w.control('lbl_bluesign'),b.name);
      w.control('number_redkillcnt')?.setNumber?.(run.roundKills?.[0]??0);w.control('number_bluekillcnt')?.setNumber?.(run.roundKills?.[1]??0);w.control('number_timer')?.setTime?.(Math.floor(run.remainingMs/1000));
      // pan_timer_name: guildtournament 88 'ready' while counting, 89 'break time' between rounds, hidden in battle
      const tn=w.find?.('pan_timer_name')?w.control('pan_timer_name'):null;tn?.setVisible?.(run.phase!=='battle');if(run.phase!=='battle')tn?.setImage?.('none',{screen:'guildtournament',index:run.phase==='count'?88:89});
      w.control('pan_redfirstkill')?.setVisible?.(run.firstKill===0);w.control('pan_bluefirstkill')?.setVisible?.(run.firstKill===1);
      rows(w,'pan_redflag_',a.wins,(i,r)=>[r[0]-i*(r[2]+2),r[1],r[2],r[3]]);rows(w,'pan_blueflag_',b.wins,(i,r)=>[r[0]+i*(r[2]+2),r[1],r[2],r[3]]);
      const mine=run.mySide>=0?run.sides[run.mySide].entrants:[];
      rows(w,'pan_member',mine.length,down(L.dashboardMember)).forEach((c,i)=>{const e=mine[i],hp=e.maxHp?Math.max(0,Math.min(1,e.hp/e.maxHp)):0,sh=e.maxShield?Math.max(0,Math.min(1,e.shield/e.maxShield)):0;
        sub(c,'pan_class')?.setSprite?.('etc_01',100+e.classIndex);sub(c,'pan_hp')?.setRect?.(7,8+Math.round(31*(1-hp)),30,Math.round(31*hp));sub(c,'pan_shield')?.setRect?.(7,8+Math.round(31*(1-sh)),30,Math.round(31*sh));
        c.el&&(c.el.title=`${e.name} Lv ${e.level}${e.down?' (down)':''}`);c.el?.style&&(c.el.style.opacity=e.down?'0.45':'1');});},
  };
  const wire=(key,w)=>{
    for(const id of ['btn_exit','btn_close','btn_cancel'])w.find?.(id)&&w.control(id).onClick(()=>w.close('ok'));
    if(key==='seed'){w.control('btn_requestseed').onClick(()=>{if(state.seed)void send({operation:'seed',seed:state.seed});else say(T(129,'Select Cid'));});w.control('btn_init').onClick(()=>{state.seed=null;fillers.seed(w,state.t);});}
    if(key==='members'){w.control('btn_regist').onClick(()=>void send({operation:'roster',members:state.picked.map(m=>m.characterId)}));w.control('btn_init').onClick(()=>{state.picked=[];fillers.members(w,state.t);});
      w.control('scroll_upbtn')?.onClick?.(()=>{state.memberScroll=Math.max(0,state.memberScroll-1);fillers.members(w,state.t);});w.control('scroll_downbtn')?.onClick?.(()=>{state.memberScroll++;fillers.members(w,state.t);});}
    if(key==='ranking'){w.control('btn_page1').onClick(()=>{state.rankPage=0;fillers.ranking(w,state.t);});w.control('btn_page2').onClick(()=>{state.rankPage=1;fillers.ranking(w,state.t);});}
    if(key==='betting'){const st=state.bet,re=()=>fillers.betting(w,state.t);
      w.control('btn_p_coin').onClick(()=>{st.coin='P';re();});w.control('btn_b_coin').onClick(()=>{st.coin='B';re();});
      w.control('btn_betting_up').onClick(()=>{st.amount=Math.min(C.betMax,st.amount+C.betStep);re();});w.control('btn_betting_down').onClick(()=>{st.amount=Math.max(C.betStep,st.amount-C.betStep);re();});
      w.control('btn_modify').onClick(async()=>{if(await game.uiwin.msgbox(T(207,'Edit the bet?'),{kind:'yesno'})==='yes'){st.editing=true;re();}});
      w.control('btn_betting').onClick(()=>{if(!st.score)return say(T(184,'Select a score and a coin quantity to make a bet.'));void send({operation:'bet',coin:st.coin,score:st.score,amount:st.amount}).then(r=>{if(r){st.editing=false;re();}});});}
    if(key==='reward')for(const c of ['p','b'])w.control(`btn_receive_${c}_coin`).onClick(()=>void send({operation:'claim',coin:c.toUpperCase()}));
    if(key==='today'){w.control('btn_enter_audience').onClick(()=>void send({operation:'observe'}).then(r=>{if(r)w.close('ok');}));w.control('btn_betting').onClick(()=>void show('betting',fillers.betting));
      w.control('body_scroll_upbtn')?.onClick?.(()=>{state.today.scroll=Math.max(0,state.today.scroll-1);fillers.today(w,state.t);});w.control('body_scroll_downbtn')?.onClick?.(()=>{state.today.scroll++;fillers.today(w,state.t);});}
    if(key==='ready')w.control('btn_leave').onClick(()=>void send({operation:'leave'}));
    if(key==='icon')w.control('btn_show').onClick(()=>void show('ready',fillers.ready));
  };
  const clearRun=()=>{for(const k of ['ready','roundEnd','result','dashboard','icon'])close(k);};
  const sync=async t=>{
    state.t=t;const run=t?.match;
    for(const [k,w] of Object.entries(state.wins))if(w?.isOpen&&fillers[k]&&!['ready','roundEnd','result'].includes(k))fillers[k](w,t);
    // The match-open notice (360|180 / 188) comes from the host as an event message.
    if(!run?.inside){clearRun();return;}
    await show('icon');
    if(['entry','ready'].includes(run.phase)){if(state.shown.ready!==run.id+run.phase){state.shown.ready=run.id+run.phase;await show('ready',fillers.ready);}else if(state.wins.ready?.isOpen)fillers.ready(state.wins.ready,t);}
    else close('ready');
    if(['count','battle','roundEnd','break'].includes(run.phase))await show('dashboard',fillers.dashboard);else close('dashboard');
    if(run.phase==='roundEnd'&&state.shown.round!==`${run.id}:${run.rounds.length}`){state.shown.round=`${run.id}:${run.rounds.length}`;await show('roundEnd',fillers.roundEnd);}
    if(run.phase!=='roundEnd')close('roundEnd');
    if(run.phase==='matchEnd'&&state.shown.result!==run.id){state.shown.result=run.id;await show('result',fillers.result);}
  };
  const original=network._snapshot?.bind(network);
  if(original)network._snapshot=snapshot=>{original(snapshot);if(!network.disposed)void sync(snapshot?.tourney||null).catch(()=>{});};
  const dialog=(n,page)=>{const d=(sys||game.sharedTravel?.sys)?.dialog;if(d?.open)d.open({title:n?.name||n?.def?.name||'',...page});};
  const open=(key,n)=>{game.uiwin?.close('npc');state.npc=npcId(n);if(key==='members'){state.picked=[...(state.t?.my?.roster||[])];state.memberScroll=0;}if(key==='betting')state.bet.editing=false;void show(key,fillers[key]);return true;};
  const coins=()=>(state.data?.modes?.colosseum?.guildMatch?.donation)||[{type:'B',amounts:[10,50,100,500,1000]},{type:'P',amounts:[10,50,100,500,1000]}];
  let services=null;
  const register=()=>{const s=game.npcServices;if(!s?.register||services===s)return;services=s;
    // 90 info: jobs 88/89/91 (no NPC in the data) are offered from Ferdianand's info page (ENGINE-CHOSEN).
    s.register(90,n=>{game.uiwin?.close('npc');state.npc=npcId(n);dialog(n,{text:`${state.t?.season||1}${T(127,'th Guild Tournament Participant').replace(/\s*Participant$/,'')}`,menu:[
      {text:T(175,'View Info'),onClick:()=>open('info',n)},{text:`${state.t?.season||1}${T(127,'th Guild Tournament Participant')}`,onClick:()=>open('entries',n)},
      {text:T(134,'Request Cid'),onClick:()=>open('seed',n)},{text:T(141,'Select Players'),onClick:()=>open('members',n)}]});return true;});
    s.register(95,n=>{game.uiwin?.close('npc');state.npc=npcId(n);void send({operation:'enter'});return true;});
    s.register(100,n=>{state.today.npc=npcId(n);state.today.key=null;state.today.scroll=0;return open('today',n);});
    s.register(92,n=>open('betting',n));
    s.register(94,n=>open('reward',n));
    s.register(86,n=>{state.rankPage=0;return open('ranking',n);});
    s.register(87,n=>{game.uiwin?.close('npc');state.npc=npcId(n);const menu=[];for(const row of coins())for(const amount of row.amounts)menu.push({text:`Donate ${amount} ${T(row.type==='P'?169:170,`${row.type} Coin`)}`,onClick:()=>void send({operation:'donate',coin:row.type,amount})});
      dialog(n,{text:T(18,'Guild Tournament Donation').replace(/^th\s*/,''),menu});return true;});};
  register();game.events?.on?.('systems',register);
  game.chat?.registerCommand?.('/leavetourney',()=>{if(state.t?.match?.inside)void send({operation:'leave'});return true;},'Leave the Guild Tournament match.');
  const leave=network.leave?.bind(network);if(leave)network.leave=options=>{for(const k of Object.keys(state.wins))close(k);state.t=null;return leave(options);};
  return {state,sync,fillers,show};
}