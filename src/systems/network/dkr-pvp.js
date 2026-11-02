// Shared play: DK Rumble 3v3 PvP (Colosseum pvp3v3, arena map 164). The host runs the season (server/world/dkr-pvp.mjs);
// this module answers the original Entry Guard jobs and draws snapshot.dkr with the original game2/dkrpvpbattle windows:
//   148 ui_registrationwnd (team name, party members, guildbg / guildicon team mark; Apply 2011|5 / Edit 6 / Unapply 7)
//   149 ui_gameinfownd (Group Stage Schedule / Status, Tournament Schedule / Status tabs, loadchild fragments)
//   160 ui_enterplayerwnd (own open match, Enter Match 2011|526/527), 161 ui_observerwnd (open matches, Watch Match)
// Inside the arena: ui_dashboard (round kills, first kill, timer, round wins, own team HP), ui_roundresultwnd at each round
// end, ui_matchresultwnd + ui_totalresultwnd at the match end. Observers fly the observer camera at ObserverSpeed
// (config.csv, cells/s: ENGINE-CHOSEN unit). /leavedkr leaves the arena; /dkrcamera toggles the observer camera.
import {loadEventData} from '../events/data.js';
import {cloneTemplate} from '../../ui/frontend/ui.js';
import {atlas} from '../../ui/atlas.js';
import {CLASS_CODES} from '../events/guild-tournament-rules.js';
import {DKR_JOBS,DKR_GROUPS,DKR_STRINGS,DKR_SCRIPTS,DKR_NAME_MAX,dateLabel,groupCode} from '../events/dkr-pvp-rules.js';
const DIR='game2/dkrpvpbattle/';
const MARK_RANGE={bg:221,icon:783},MARK_PAGE=60,MARK_COLS=20; // = server/world/guilds.mjs GUILD_MARK_RANGE (guildbg / guildicon atlases)
const npcId=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index);
const text=(c,v)=>c?.setText?.(v==null||v===''?' ':String(v)); // ' ' so a scripted default text is not shown
const ctl=(w,id)=>w?.find?.(id)?w.control(id):null;
const vis=(c,v)=>c?.setVisible?.(!!v);
const mark=(w,bgId,iconId,m)=>{const b=ctl(w,bgId),i=ctl(w,iconId);vis(b,!!m);vis(i,!!m);if(m){b?.setImage?.('none',{screen:'guildbg',index:m.bg,color:'ffffffff'});i?.setImage?.('none',{screen:'guildicon',index:m.icon,color:'ffffffff'});}};
const img=(c,index)=>c?.setImage?.('none',{screen:'dkrpvpbattle',index});
/** Matches of the game info windows. */
export function leagueList(t,tab){const g=tab>0?DKR_GROUPS[tab-1]:null;return (t?.matches||[]).filter(m=>m.kind==='league'&&m.left&&m.right&&(!g||m.group===g)).sort((a,b)=>a.at-b.at||a.group.localeCompare(b.group));}
export function tournamentList(t,tab){return (t?.matches||[]).filter(m=>m.kind==='tournament'&&(tab===0||(tab===1?m.status==='done':m.status!=='done'))).sort((a,b)=>a.at-b.at||b.match-a.match||a.order-b.order);}
/** Bracket box ids of ui_tournamentstate: Round of 16 .. final (2) and third place (3). */
export const BRACKET_BOXES=Object.freeze({16:8,8:4,4:2,2:1,3:1});
export const scoreText=m=>m?.result&&!m.result.bye?`${m.result.wins[0]} : ${m.result.wins[1]}`:'VS';
export function installSharedDkrPvp(game,network,sys){
  const state={t:null,data:null,wins:{},npc:null,info:{tab:0,league:0,leagueScroll:0,stateScroll:0,tour:0,tourScroll:0},observe:{key:null,scroll:0},
    pick:{bg:1,icon:1},page:{bg:0,icon:0},detail:null,shown:{round:null,match:null},camera:{on:false,cam:null}};
  void loadEventData().then(d=>{state.data=d;}).catch(()=>{});
  const T=(code,fb='')=>{const v=state.data?.txt?.(DKR_STRINGS.file,DKR_STRINGS.cate,code);return (v&&String(v).replace(/<[^>]+>/g,'').replace(/\\n/g,'\n').trim())||fb;};
  const C360=(code,fb='')=>{const v=state.data?.txt?.('stringtable_colosseum.txt',360,code);return (v&&String(v).replace(/<[^>]+>/g,'').trim())||fb;};
  const className=i=>C360(CLASS_CODES[Number(i)||0],'');
  const report=error=>game.chat?.system?.(error?.message||String(error),'err');
  const say=t=>{if(!t)return;if(game.chat?.system)game.chat.system(t);else game.hud?.log?.(t,'sys');};
  const send=intent=>network.action('dkr',{npcIndex:state.npc??undefined,...intent}).then(r=>{say(r?.dkrResult?.text);return r;}).catch(report);
  const team=id=>id?state.t?.teams?.[id]||null:null;
  // Lane 71: match names follow the Global client (64-bit decompile, DKR match label builder near 0x7ff6715cbc78 picks 2011|1000-1004
  // and 1010): league rows 1000 'Group <GROUPNAME>', tournament rows 1001 'Round of <GROUPNAME>' (16 / 8), 1002 Semifinals (4),
  // 1003 3rd Place Match (3), 1004 Finals (2), then 1010 'Match<ORDERNAME>' when the round has several matches (JUDGMENT: ORDERNAME = ' ' + order).
  const fill=(s,k,v)=>String(s).split(k).join(String(v));
  const roundLabel=m=>m.kind==='league'?fill(T(1000,'Group <GROUPNAME>'),'<GROUPNAME>',m.group):m.match>=8?fill(T(1001,'Round of <GROUPNAME>'),'<GROUPNAME>',m.match):m.match===4?T(1002,'Semifinals'):m.match===3?T(1003,'3rd Place Match'):T(1004,'Finals');
  const matchName=m=>!m?'':roundLabel(m)+(m.kind==='league'||m.match>=4?' '+fill(T(1010,'Match<ORDERNAME>'),'<ORDERNAME>',' '+m.order):'');
  const when=ms=>ms?dateLabel(String(state.data?.txt?.(DKR_STRINGS.file,DKR_STRINGS.cate,117)||'<MONTH> / <DAY> <HOUR> : <MINUTE>'),ms):''; // 2011|117 keeps its <MONTH> / <DAY> tokens
  const win=async key=>{const w0=state.wins[key];if(w0&&!w0.disposed)return w0;const w=await game.uiwin?.create?.(DIR+DKR_SCRIPTS[key]+'.txt',{name:`ev_dkr_${key}`});if(!w)return null;state.wins[key]=w;wire(key,w);return w;};
  const show=async(key,fill)=>{const w=await win(key);if(!w)return null;fill?.(w,state.t);if(!w.isOpen)game.uiwin.openWindow(w);return w;};
  const close=key=>{const w=state.wins[key];if(w?.isOpen)w.close?.('dkr');};
  const members=(w,prefix,side,list,{world=false,level=true}={})=>{for(let i=0;i<3;i++){const m=list?.[i];
    const cls=ctl(w,`pan_${prefix}classmark_${side}_${i}`),row=ctl(w,`pan_${prefix}member_${side}_${i}`);vis(cls,!!m);vis(row,!!m);if(!m)continue;
    cls?.setSprite?.('etc_01',100+(Number(m.classIndex)||0));text(ctl(w,`lbl_${prefix}membername_${side}_${i}`),m.name);if(level)text(ctl(w,`lbl_${prefix}memberlevel_${side}_${i}`),m.level);if(world)text(ctl(w,`lbl_${prefix}memberworld_${side}_${i}`),'');
    if(row?.el){row.el.title=className(m.classIndex);row.el.style.opacity=m.down?'0.45':'1';}}};
  // --- registration (job 148)
  const markCells={bg:[],icon:[]};
  const paintMarks=w=>{for(const kind of ['bg','icon']){const small=kind==='bg'?'guildbg_s':'guildicon_s';
      markCells[kind].forEach((cell,i)=>{const index=state.page[kind]*MARK_PAGE+i+1,tok=cell._tok={};cell.style.backgroundImage='';cell.style.visibility=index<=MARK_RANGE[kind]?'':'hidden';
        if(index<=MARK_RANGE[kind])void atlas.sprite(small,index).then(sp=>{if(cell._tok===tok&&sp)cell.style.backgroundImage=`url("${sp.url}")`;});});
      const at=state.pick[kind]-1-state.page[kind]*MARK_PAGE,cur=ctl(w,kind==='bg'?'pan_bgCursor':'pan_iconCursor');vis(cur,at>=0&&at<MARK_PAGE);if(at>=0&&at<MARK_PAGE)cur?.move?.((at%MARK_COLS)*24,Math.floor(at/MARK_COLS)*24);}
    mark(w,'pan_selectguildmarkbg','pan_selectguildmark',{bg:state.pick.bg,icon:state.pick.icon});};
  const fillers={
    register:(w,t)=>{const my=t?.my,party=t?.party,list=my?my.members:(party?.members||[]);
      text(ctl(w,'lbl_info_teamname'),T(2,'Team Name'));const edit=ctl(w,'edit_teamname');if(edit&&!w._dkrTyped)edit.setText?.(my?.name||'');
      for(let i=1;i<=3;i++){const m=list[i-1];vis(ctl(w,`pan_memberclass${i}`),!!m);if(m)ctl(w,`pan_memberclass${i}`)?.setSprite?.('etc_01',100+(Number(m.classIndex)||0));
        text(ctl(w,`lbl_membername${i}`),m?.name);text(ctl(w,`lbl_memberworld${i}`),'');text(ctl(w,`lbl_memberclass${i}`),m?className(m.classIndex):'');text(ctl(w,`lbl_memberlevel${i}`),m?.level);text(ctl(w,`lbl_membergrade${i}`),'');}
      vis(ctl(w,'btn_regist'),!my);vis(ctl(w,'btn_modify'),!!my);ctl(w,'btn_cancel')?.setEnabled?.(!!my);paintMarks(w);},
    info:(w,t)=>{const tab=state.info.tab;['league_info','league_state','tournament_info','tournament_state'].forEach((k,i)=>{vis(ctl(w,`pan_contents_${k}`),tab===i);ctl(w,`btn_tab_${k}`)?.setChecked?.(tab===i);});
      vis(ctl(w,'info_scroll'),tab===0);vis(ctl(w,'info_scroll_leagueresult'),tab===1);
      if(tab===0)fillLeagueInfo(w,t);else if(tab===1)fillLeagueState(w,t);else if(tab===2)fillTournamentInfo(w,t);else fillTournamentState(w,t);},
    enter:(w,t)=>{const run=t?.run,a=team(run?.sides?.[0]?.teamId),b=team(run?.sides?.[1]?.teamId);
      text(ctl(w,'lbl_matchinfo'),matchName(run));text(ctl(w,'lbl_matchtime'),when(run?.at));text(ctl(w,'lbl_teamname_0'),a?.name);text(ctl(w,'lbl_teamname_1'),b?.name);
      mark(w,'pan_teammarkbg_0','pan_teammark_0',a?.mark);mark(w,'pan_teammarkbg_1','pan_teammark_1',b?.mark);members(w,'match',0,a?.members);members(w,'match',1,b?.members);
      text(ctl(w,'lbl_message'),run?T(527,'Do you want to enter the match?'):T(554,'No ongoing matches at this time.'));ctl(w,'btn_enter')?.setEnabled?.(!!run&&run.phase==='entry'&&!run.inside);},
    observe:(w,t)=>{const list=t?.open||[],st=state.observe;st.scroll=Math.max(0,Math.min(st.scroll,Math.max(0,list.length-4)));if(!list.some(m=>m.key===st.key))st.key=list[0]?.key||null;
      vis(ctl(w,'lbl_info_nomatch'),!list.length);
      for(let i=0;i<4;i++){const m=list[st.scroll+i],a=team(m?.left),b=team(m?.right);vis(ctl(w,`pan_teaminfo_${i}`),!!m);if(!m)continue;
        text(ctl(w,`lbl_matchinfo_${i}`),matchName(m));text(ctl(w,`lbl_matchtime_${i}`),when(m.at));text(ctl(w,`lbl_teamname_${i}_0`),a?.name);text(ctl(w,`lbl_teamname_${i}_1`),b?.name);
        mark(w,`pan_teammarkbg_${i}_0`,`pan_teammark_${i}_0`,a?.mark);mark(w,`pan_teammarkbg_${i}_1`,`pan_teammark_${i}_1`,b?.mark);
        const btn=ctl(w,`btn_info_${i}`);if(btn){btn._dkrKey=m.key;btn.setChecked?.(st.key===m.key);if(!btn._dkr){btn._dkr=1;btn.onClick(()=>{state.observe.key=btn._dkrKey;fillers.observe(w,state.t);});}}}
      const sel=list.find(m=>m.key===st.key),a=team(sel?.left),b=team(sel?.right);text(ctl(w,'lbl_matchteamname_0'),a?.name);text(ctl(w,'lbl_matchteamname_1'),b?.name);
      members(w,'match',0,a?.members);members(w,'match',1,b?.members);ctl(w,'btn_enter')?.setEnabled?.(!!sel);},
    dashboard:(w,t)=>{const run=t?.run;if(!run)return;const [a,b]=run.sides;text(ctl(w,'lbl_redsign'),a.name);text(ctl(w,'lbl_bluesign'),b.name);
      ctl(w,'number_redkillcnt')?.setNumber?.(run.roundKills?.[0]??0);ctl(w,'number_bluekillcnt')?.setNumber?.(run.roundKills?.[1]??0);ctl(w,'number_timer')?.setTime?.(Math.floor(run.remainingMs/1000));
      // ui_dashboard pan_timer_name: guildtournament 88 'ready' while counting, 89 'break time' between rounds, hidden in battle
      const tn=ctl(w,'pan_timer_name');vis(tn,run.phase!=='battle');if(run.phase!=='battle')tn?.setImage?.('none',{screen:'guildtournament',index:run.phase==='count'?88:89});
      vis(ctl(w,'pan_redfirstkill'),run.firstKill===0);vis(ctl(w,'pan_bluefirstkill'),run.firstKill===1);
      rows(w,'pan_redflag_',a.wins,(i,r)=>[r[0]-i*(r[2]+2),r[1],r[2],r[3]]);rows(w,'pan_blueflag_',b.wins,(i,r)=>[r[0]+i*(r[2]+2),r[1],r[2],r[3]]);
      const mine=run.mySide>=0?run.sides[run.mySide].entrants:[];
      rows(w,'pan_member',mine.length,(i,r)=>[r[0],r[1]+i*(r[3]+4),r[2],r[3]]).forEach((c,i)=>{const e=mine[i],hp=e.maxHp?Math.max(0,Math.min(1,e.hp/e.maxHp)):0,sh=e.maxShield?Math.max(0,Math.min(1,e.shield/e.maxShield)):0;
        sub(c,'pan_class')?.setSprite?.('etc_01',100+(e.classIndex||0));sub(c,'pan_hp')?.setRect?.(7,8+Math.round(31*(1-hp)),30,Math.round(31*hp));sub(c,'pan_shield')?.setRect?.(7,8+Math.round(31*(1-sh)),30,Math.round(31*sh));
        if(c.el){c.el.title=`${e.name} Lv ${e.level}${e.down?' (down)':''}`;c.el.style.opacity=e.down?'0.45':'1';}});},
    round:(w,t)=>{const run=t?.run;if(!run)return;const n=run.rounds.length,last=run.rounds[n-1]||{winner:-1};
      text(ctl(w,'lbl_title'),`${T(544,'Result')}`);img(ctl(w,'pan_roundnumber'),109+Math.min(4,Math.max(0,n-1)));
      text(ctl(w,'lbl_teamname1'),run.sides[0].name);text(ctl(w,'lbl_teamname2'),run.sides[1].name);mark(w,'pan_teammarkbg1','pan_teammark1',run.sides[0].mark);mark(w,'pan_teammarkbg2','pan_teammark2',run.sides[1].mark);
      img(ctl(w,'pan_score1'),115+Math.min(9,run.sides[0].wins));img(ctl(w,'pan_score2'),115+Math.min(9,run.sides[1].wins));
      for(const s of [0,1]){const list=run.sides[s].entrants;for(let i=1;i<=3;i++){const e=list[i-1];vis(ctl(w,`pan_memberclass${s+1}_${i}`),!!e);if(e)ctl(w,`pan_memberclass${s+1}_${i}`)?.setSprite?.('etc_01',100+(e.classIndex||0));
        text(ctl(w,`lbl_membername${s+1}_${i}`),e?.name);text(ctl(w,`lbl_memberlevel${s+1}_${i}`),e?.level);}}
      w._dkrRoundWinner=last.winner;},
    match:(w,t)=>fillMatchResult(w,state.detail||t?.run?.result&&{...t.run.result,key:t.run.key,kind:t.run.kind,group:t.run.group,match:t.run.match,order:t.run.order,left:t.run.sides[0].teamId,right:t.run.sides[1].teamId}),
    total:(w,t)=>{const run=t?.run,res=run?.result;if(!res)return;const win=res.winner,wt=win===0||win===1?team(run.sides[win].teamId)||run.sides[win]:null;
      vis(ctl(w,'pan_draw'),!wt);for(const id of ['pan_winteammarkbase','lbl_winteamname','pan_winteamresult'])vis(ctl(w,id),!!wt);
      if(wt){text(ctl(w,'lbl_winteamname'),wt.name);mark(w,'pan_winteammarkbg','pan_winteammark',wt.mark);}
      const rounds=res.rounds||[];for(let i=1;i<=5;i++){const r=rounds[i-1];vis(ctl(w,`pan_matchinfo_detail_${i}`),!!r);if(!r)continue;const k=i;
        for(const s of [0,1]){const n=s+1;img(ctl(w,`pan_result${n}_${k}`),r.winner===s?103:r.winner<0?105:104);text(ctl(w,`lbl_name${n}_${k}`),run.sides[s].name);mark(w,`pan_markbg${n}_${k}`,`pan_mark${n}_${k}`,run.sides[s].mark);
          vis(ctl(w,`pan_firstkill${n}_${k}`),r.firstKill===s);img(ctl(w,`pan_matchcount${n}_${k}`),115+Math.min(9,r.kills[s]));}}},
  };
  function fillMatchResult(w,res){if(!res)return;const a=team(res.left),b=team(res.right),win=res.winner;
    text(ctl(w,'lbl_matchname'),matchName(res));text(ctl(w,'lbl_teamname_0'),a?.name||res.names?.[0]);text(ctl(w,'lbl_teamname_1'),b?.name||res.names?.[1]);
    mark(w,'pan_guildmarkbg_0','pan_guildmark_0',a?.mark);mark(w,'pan_guildmarkbg_1','pan_guildmark_1',b?.mark);
    vis(ctl(w,'pan_win_team1'),win===0);vis(ctl(w,'pan_lose_team1'),win===1);vis(ctl(w,'pan_win_team2'),win===1);vis(ctl(w,'pan_lose_team2'),win===0);vis(ctl(w,'pan_draw'),win!==0&&win!==1);
    for(const s of [0,1]){const list=res.members?.[s]||[];for(let i=0;i<3;i++){const m=list[i];vis(ctl(w,`pan_classmark_${s}_${i}`),!!m);vis(ctl(w,`pan_member_${s}_${i}`),!!m);if(!m)continue;
      ctl(w,`pan_classmark_${s}_${i}`)?.setSprite?.('etc_01',100+(m.classIndex||0));text(ctl(w,`lbl_membername_${s}_${i}`),m.name);text(ctl(w,`lbl_memberlevel_${s}_${i}`),m.level||'');text(ctl(w,`lbl_membergrade_${s}_${i}`),'');
      text(ctl(w,`lbl_memberkillcount_${s}_${i}`),m.kills);text(ctl(w,`lbl_memberdeathcount_${s}_${i}`),m.deaths);}}
    const rounds=res.rounds||[];for(let i=0;i<5;i++){const r=rounds[i];vis(ctl(w,`pan_roundresultinfo_${i}`),!!r);if(!r){for(const s of [0,1])mark(w,`pan_teammarkbg_${i}_${s}`,`pan_teammark_${i}_${s}`,null);continue;}
      img(sub(ctl(w,`pan_roundresultinfo_${i}`),'pan_num'),309+i);for(const s of [0,1]){text(ctl(w,`lbl_teamname_${i}_${s}`),(s?b:a)?.name||res.names?.[s]);mark(w,`pan_teammarkbg_${i}_${s}`,`pan_teammark_${i}_${s}`,(s?b:a)?.mark);
        text(ctl(w,`lbl_team_killcount_${i}_${s}`),r.kills[s]);text(ctl(w,`lbl_team_deathcount_${i}_${s}`),r.deaths?.[s]??0);}
      const sec=Math.round((r.ms||0)/1000);text(ctl(w,`lbl_round_time_${i}`),`${String(Math.floor(sec/60)).padStart(2,'0')}:${String(sec%60).padStart(2,'0')}`);
      text(ctl(w,`lbl_round_result_${i}`),r.winner===0||r.winner===1?((r.winner?b:a)?.name||res.names?.[r.winner]):T(540,'Draw'));
      vis(ctl(w,`pan_win_${i}`),r.winner===0);vis(ctl(w,`pan_extrawin_${i}`),false);}}
  function infoSlot(w,p,i,m){const a=team(m?.left),b=team(m?.right);vis(ctl(w,`pan_${p}info_${i}`),!!m);if(!m)return;
    text(ctl(w,`lbl_${p}matchname_${i}`),matchName(m));text(ctl(w,`lbl_${p}matchtime_${i}`),when(m.at));
    const done=m.status==='done'&&m.result,score=done&&!m.result.bye;text(ctl(w,`lbl_${p}teamscore_${i}_0`),score?m.result.wins[0]:'');text(ctl(w,`lbl_${p}teamscore_${i}_1`),score?m.result.wins[1]:'');
    for(const s of [0,1]){const tm=s?b:a;text(ctl(w,`lbl_${p}teamname_${i}_${s}`),tm?.name||'');mark(w,`pan_${p}guildmarkbg_${i}_${s}`,`pan_${p}guildmark_${i}_${s}`,tm?.mark);members(w,p,`${i}_${s}`,tm?.members,{world:true});}
    const flag=ctl(w,`pan_${p}team_win_${i}`);vis(flag,done&&(m.result.winner===0||m.result.winner===1));if(done&&m.result.winner===1)flag?.setRect?.(752,23,28,16);else if(done)flag?.setRect?.(12,23,28,16);
    const btn=ctl(w,`btn_${p}info_result_${i}`);if(btn){btn._dkrMatch=m;btn.setEnabled?.(!!done&&!m.result.bye);if(!btn._dkr){btn._dkr=1;btn.onClick(()=>{const x=btn._dkrMatch;if(!x?.result)return;state.detail={...x.result,key:x.key,kind:x.kind,group:x.group,match:x.match,order:x.order,left:x.left,right:x.right};void show('match',fillers.match);});}}}
  function fillLeagueInfo(w,t){const list=leagueList(t,state.info.league),max=Math.max(0,list.length-4);state.info.leagueScroll=Math.min(state.info.leagueScroll,max);
    for(let i=0;i<=8;i++)ctl(w,`btn_subtab_leagueinfo_${i}`)?.setChecked?.(state.info.league===i);text(ctl(w,'lbl_info_leagueinfo'),T(13,'Group Stage'));
    for(let i=0;i<4;i++)infoSlot(w,'league',i,list[state.info.leagueScroll+i]);}
  function fillTournamentInfo(w,t){const list=tournamentList(t,state.info.tour),max=Math.max(0,list.length-4);state.info.tourScroll=Math.min(state.info.tourScroll,max);
    for(let i=0;i<=2;i++)ctl(w,`btn_subtab_tournamentinfo_${i}`)?.setChecked?.(state.info.tour===i);
    for(let i=0;i<4;i++)infoSlot(w,'tournament',i,list[state.info.tourScroll+i]);}
  function fillLeagueState(w,t){const page=Math.min(1,state.info.stateScroll);
    for(let i=0;i<4;i++){const g=DKR_GROUPS[page*4+i],ranks=t?.groups?.[g]||[];text(ctl(w,`lbl_leaguestate_group_${i}`),T(groupCode(g),`Group ${g}`));
      for(let j=0;j<4;j++){const r=ranks[j],tm=team(r?.id);vis(ctl(w,`pan_leaguestateinfo_${i}_${j}`),!!r);mark(w,`pan_leaguestatemarkbg_${i}_${j}`,`pan_leaguestatemark_${i}_${j}`,tm?.mark);if(!r)continue;
        text(ctl(w,`lbl_leaguestateteamname_${i}_${j}`),tm?.name);text(ctl(w,`lbl_leaguestatewin_${i}_${j}`),r.win);text(ctl(w,`lbl_leaguestatedraw_${i}_${j}`),r.draw);text(ctl(w,`lbl_leaguestatelose_${i}_${j}`),r.loss);
        text(ctl(w,`lbl_leaguestatekilldeath_${i}_${j}`),`${r.kills}/${r.deaths}`);text(ctl(w,`lbl_leaguestatepoint_${i}_${j}`),r.points);}
      const ms=(t?.matches||[]).filter(m=>m.kind==='league'&&m.group===g).sort((a,b)=>a.order-b.order);
      for(let k=0;k<6;k++){const m=ms[k],show=m&&m.left&&m.right;vis(ctl(w,`pan_leaguematchscoreinfo_${i}_${k}`),!!show);if(!show)continue;
        text(ctl(w,`lbl_leaguematchscore_teamname1_${i}_${k}`),team(m.left)?.name);text(ctl(w,`lbl_leaguematchscore_${i}_${k}`),m.status==='done'?scoreText(m):'VS');text(ctl(w,`lbl_leaguematchscore_teamname2_${i}_${k}`),team(m.right)?.name);}}}
  function fillTournamentState(w,t){const by=new Map((t?.matches||[]).filter(m=>m.kind==='tournament').map(m=>[`${m.match}_${m.order-1}`,m]));
    for(const [g,count] of Object.entries(BRACKET_BOXES))for(let n=0;n<count;n++){const m=by.get(`${g}_${n}`),done=m?.status==='done'&&m.result;
      for(const s of [0,1]){const tm=team(s?m?.right:m?.left);text(ctl(w,`lbl_tournamentteamname_${g}_${n}_${s}`),tm?.name||'');mark(w,`pan_tournamentstatemarkbg_${g}_${n}_${s}`,`pan_tournamentstatemark_${g}_${n}_${s}`,tm?.mark);
        text(ctl(w,`lbl_tournamentscore_${g}_${n}_${s}`),done&&!m.result.bye?m.result.wins[s]:'');vis(ctl(w,`pan_tournamentstate_bg_win_${g}_${n}_${s}`),!!done&&m.result.winner===s);}}}
  function sub(c,id){if(!c)return null;for(const x of c.children||[]){if((x.spec?.id??x.id)===id)return x;const d=sub(x,id);if(d)return d;}return null;}
  function rows(w,tpl,n,rect,key=tpl){w._dkrRows||={};const list=w._dkrRows[key]||=[];const src=w.find?.(tpl);if(!src)return [];src.setVisible?.(false);
    const base=Array.from(src.spec?.rect||[0,0,0,0]).map(Number);for(let i=0;i<Math.max(n,list.length);i++){if(i<n&&!list[i])list[i]=cloneTemplate(w,tpl,`${key}${i}d`,rect(i,base));list[i]?.setVisible?.(i<n);}return list.slice(0,n);}
  const confirm=async code=>(await game.uiwin?.msgbox?.(T(code,''),{kind:'yesno',name:'ev_dkr_confirm'}))==='yes';
  const wire=(key,w)=>{
    for(const id of ['btn_exit'])ctl(w,id)?.onClick?.(()=>{w.close('ok');if(key==='total')void show('match',fillers.match);}); // the total result opens the match details
    if(key==='register'){
      for(const kind of ['bg','icon']){const host=ctl(w,kind==='bg'?'pan_markbg':'pan_mark')?.el;markCells[kind]=[];
        for(let i=0;i<MARK_PAGE&&host&&typeof document!=='undefined';i++){const cell=document.createElement('div');cell.style.cssText=`position:absolute;left:${(i%MARK_COLS)*24}px;top:${Math.floor(i/MARK_COLS)*24}px;width:24px;height:24px;pointer-events:auto;cursor:pointer;background-size:100% 100%;background-repeat:no-repeat`;
          cell.dataset.dkrMark=kind;cell.addEventListener('click',()=>{const index=state.page[kind]*MARK_PAGE+i+1;if(index<=MARK_RANGE[kind]){state.pick[kind]=index;paintMarks(w);}});host.appendChild(cell);markCells[kind].push(cell);}}
      const pages=kind=>Math.ceil(MARK_RANGE[kind]/MARK_PAGE);
      for(const [kind,l,r] of [['bg','btn_bgLeft','btn_bgRight'],['icon','btn_iconLeft','btn_iconRight']]){ctl(w,l)?.onClick?.(()=>{state.page[kind]=(state.page[kind]+pages(kind)-1)%pages(kind);paintMarks(w);});ctl(w,r)?.onClick?.(()=>{state.page[kind]=(state.page[kind]+1)%pages(kind);paintMarks(w);});}
      const name=()=>String(ctl(w,'edit_teamname')?.getText?.()||'').trim().slice(0,DKR_NAME_MAX);ctl(w,'edit_teamname')?.el?.addEventListener?.('input',()=>{w._dkrTyped=true;});
      ctl(w,'btn_regist')?.onClick?.(async()=>{if(await confirm(14))void send({operation:'register',name:name(),bg:state.pick.bg,icon:state.pick.icon}).then(r=>{if(r)w._dkrTyped=false;});});
      ctl(w,'btn_modify')?.onClick?.(async()=>{if(await confirm(15))void send({operation:'edit',name:name(),bg:state.pick.bg,icon:state.pick.icon}).then(r=>{if(r)w._dkrTyped=false;});});
      ctl(w,'btn_cancel')?.onClick?.(async()=>{if(await confirm(16))void send({operation:'cancel'}).then(r=>{if(r)w._dkrTyped=false;});});}
    if(key==='info'){['league_info','league_state','tournament_info','tournament_state'].forEach((k,i)=>ctl(w,`btn_tab_${k}`)?.onClick?.(()=>{state.info.tab=i;fillers.info(w,state.t);}));
      for(let i=0;i<=8;i++)ctl(w,`btn_subtab_leagueinfo_${i}`)?.onClick?.(()=>{state.info.league=i;state.info.leagueScroll=0;fillers.info(w,state.t);});
      for(let i=0;i<=2;i++)ctl(w,`btn_subtab_tournamentinfo_${i}`)?.onClick?.(()=>{state.info.tour=i;state.info.tourScroll=0;fillers.info(w,state.t);});
      const step=(k,d)=>{state.info[k]=Math.max(0,state.info[k]+d);fillers.info(w,state.t);};
      ctl(w,'info_scroll_upbtn')?.onClick?.(()=>step('leagueScroll',-1));ctl(w,'info_scroll_downbtn')?.onClick?.(()=>step('leagueScroll',1));
      ctl(w,'info_scroll_leagueresult_upbtn')?.onClick?.(()=>step('stateScroll',-1));ctl(w,'info_scroll_leagueresult_downbtn')?.onClick?.(()=>step('stateScroll',1));
      ctl(w,'tournamentinfo_scroll_upbtn')?.onClick?.(()=>step('tourScroll',-1));ctl(w,'tournamentinfo_scroll_downbtn')?.onClick?.(()=>step('tourScroll',1));}
    if(key==='enter')ctl(w,'btn_enter')?.onClick?.(()=>void send({operation:'enter'}).then(r=>{if(r)w.close('ok');}));
    if(key==='observe'){ctl(w,'btn_enter')?.onClick?.(()=>void send({operation:'observe',key:state.observe.key}).then(r=>{if(r)w.close('ok');}));
      ctl(w,'info_scroll_upbtn')?.onClick?.(()=>{state.observe.scroll=Math.max(0,state.observe.scroll-1);fillers.observe(w,state.t);});ctl(w,'info_scroll_downbtn')?.onClick?.(()=>{state.observe.scroll++;fillers.observe(w,state.t);});}
  };
  async function camera(on,speed){
    if(!state.camera.cam){if(game.gm?.freecam?.set)state.camera.cam=game.gm.freecam;else{try{const {FreeCam}=await import('../gm/worldtools.js');state.camera.cam=new FreeCam(game);}catch{state.camera.cam=null;}}}
    const cam=state.camera.cam;if(!cam?.set)return;if(on){if(Number(speed)>0)cam.speed=Number(speed);if(!cam.on)cam.set(true);cam._dkr=true;}else if(cam.on&&cam._dkr){cam.set(false);cam._dkr=false;}state.camera.on=!!on;
  }
  const clearRun=()=>{for(const k of ['dashboard','round'])close(k);if(state.camera.on)void camera(false);};
  const sync=async t=>{
    state.t=t;const run=t?.run;
    for(const [k,w] of Object.entries(state.wins))if(w?.isOpen&&fillers[k]&&!['round','match','total'].includes(k))fillers[k](w,t);
    if(!run?.inside){clearRun();return;}
    if(run.observer&&!state.camera.on&&state.camera.auto!==run.key){state.camera.auto=run.key;await camera(true,run.observerSpeed);}
    if(['count','battle','roundEnd','break'].includes(run.phase))await show('dashboard',fillers.dashboard);else close('dashboard');
    if(run.phase==='roundEnd'&&state.shown.round!==`${run.key}:${run.rounds.length}`){state.shown.round=`${run.key}:${run.rounds.length}`;await show('round',fillers.round);}
    if(run.phase!=='roundEnd')close('round');
    if(run.phase==='matchEnd'&&state.shown.match!==run.key){state.shown.match=run.key;state.detail={...run.result,key:run.key,kind:run.kind,group:run.group,match:run.match,order:run.order,left:run.sides[0].teamId,right:run.sides[1].teamId};await show('total',fillers.total);}
  };
  const original=network._snapshot?.bind(network);
  if(original)network._snapshot=snapshot=>{original(snapshot);if(!network.disposed)void sync(snapshot?.dkr||null).catch(()=>{});};
  const open=(key,n)=>{game.uiwin?.close('npc');state.npc=npcId(n);void show(key,fillers[key]);return true;};
  let services=null;
  const register=()=>{const s=game.npcServices;if(!s?.register||services===s)return;services=s;
    s.register(DKR_JOBS.register,n=>{const my=state.t?.my;if(my?.mark)state.pick={bg:my.mark.bg,icon:my.mark.icon};state.page={bg:Math.floor((state.pick.bg-1)/MARK_PAGE),icon:Math.floor((state.pick.icon-1)/MARK_PAGE)};return open('register',n);});
    s.register(DKR_JOBS.info,n=>{state.npc=npcId(n);void send({operation:'info'});return open('info',n);});
    s.register(DKR_JOBS.enter,n=>{if(!state.t?.run||state.t.run.phase!=='entry'){game.uiwin?.close('npc');state.npc=npcId(n);void send({operation:'enter'});return true;}return open('enter',n);});
    s.register(DKR_JOBS.observe,n=>{state.observe.scroll=0;return open('observe',n);});};
  register();game.events?.on?.('systems',register);
  game.chat?.registerCommand?.('/leavedkr',()=>{if(state.t?.run?.inside)void send({operation:'leave'});return true;},'Leave the DK Rumble arena.');
  game.chat?.registerCommand?.('/dkrcamera',()=>{const run=state.t?.run;if(run?.observer)void camera(!state.camera.on,run.observerSpeed);return true;},'Toggle the DK Rumble observer camera.');
  const leave=network.leave?.bind(network);if(leave)network.leave=options=>{for(const k of Object.keys(state.wins))close(k);state.t=null;return leave(options);};
  return {state,sync,fillers,show};
}