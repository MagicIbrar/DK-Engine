// DKR-PVP pure rules: read share/dkrpvpbattle/config.csv + matchtime.csv (gamedata events.json modes.colosseum.pvp3v3)
// and decide the league / tournament / round outcomes. The gaps the data leaves are in src/config/engine-chosen-dkr-pvp.js.
import {DKR_PVP_CHOSEN as C} from '../../config/engine-chosen-dkr-pvp.js';
import {serverDate,serverTimestamp} from '../../game/server-time.js';
export const DKR_JOBS=Object.freeze({register:148,info:149,tournamentInfo:150,enter:160,observe:161,leave:97});
export const DKR_GROUPS=Object.freeze(['A','B','C','D','E','F','G','H']);
export const DKR_TEAM_SIZE=3;           // config.csv: three start cells per team; 2011|503 "Incorrect number of party members."
export const DKR_NAME_MAX=20;           // ui_registrationwnd edit_teamname maxlength 20
export const DKR_STRINGS=Object.freeze({file:'stringtable_partywarui.txt',cate:2011});
export const DKR_SCRIPTS=Object.freeze({register:'ui_registrationwnd',info:'ui_gameinfownd',enter:'ui_enterplayerwnd',observe:'ui_observerwnd',
  dashboard:'ui_dashboard',round:'ui_roundresultwnd',match:'ui_matchresultwnd',total:'ui_totalresultwnd'});
const n=v=>Number(v);
const cfgValue=(row,key)=>{if(row[key]!==undefined)return n(row[key]);const k=Object.keys(row).find(x=>x===key||x.startsWith(key+' '));return k===undefined?NaN:n(row[k]);};
/** Calendar rows (matchtime.csv) -> timestamps on the shared UTC+1 server calendar. */
export function parseCalendar(rows){
  const at=r=>serverTimestamp(n(r.Year),n(r.Month)-1,n(r.Day),n(r.Hour),n(r.Min),n(r.Sec)||0);
  const out={registrationStart:null,registrationEnd:null,leagueStart:null,league:[],tournament:[]};
  for(const r of rows||[]){const m=String(r.Match||'');
    if(m==='RegistrationStart')out.registrationStart=at(r);else if(m==='RegistrationEnd')out.registrationEnd=at(r);else if(m==='LeagueStart')out.leagueStart=at(r);
    else if(m==='League')out.league.push({key:`L:${r.Group}:${n(r.Order)}`,group:String(r.Group),order:n(r.Order),at:at(r)});
    else if(m==='Tournament')out.tournament.push({key:`T:${n(r.Group)}:${n(r.Order)}`,match:n(r.Group),order:n(r.Order),at:at(r)});}
  out.league.sort((a,b)=>a.at-b.at||a.group.localeCompare(b.group)||a.order-b.order);out.tournament.sort((a,b)=>a.at-b.at||b.match-a.match||a.order-b.order);
  return out;
}
/** Data tables of the mode. override = operator calendar rows (world.data.dkrPvpCalendar), else the data calendar. */
export function dkrData(modes,override=null){
  const src=modes?.colosseum?.pvp3v3;const row=src?.config?.[0];if(!row)return null;
  const start=(t,i)=>[cfgValue(row,`StartX${t}_${i}`),cfgValue(row,`StartY${t}_${i}`)];
  return {server:cfgValue(row,'DKSERVERINDEX'),map:cfgValue(row,'MAPINDEX'),observerMax:cfgValue(row,'ObserverMaxCount'),waitSec:cfgValue(row,'Wait_Time'),
    roundSec:cfgValue(row,'Round_Time'),createSec:cfgValue(row,'Match_Create_Time'),observerSpeed:cfgValue(row,'ObserverSpeed'),
    teamA:[1,2,3].map(i=>start(1,i)),teamB:[1,2,3].map(i=>start(2,i)),calendar:parseCalendar(override||src.matchTime||[])};
}
/** Season phase at `now` from the calendar: before / registration / closed / league / tournament. */
export function seasonPhase(cal,now){
  if(cal.registrationStart==null||now<cal.registrationStart)return 'before';
  if(now<cal.registrationEnd)return 'registration';
  if(now<cal.leagueStart)return 'closed';
  const firstT=cal.tournament.length?Math.min(...cal.tournament.map(m=>m.at)):Infinity;
  return now<firstT?'league':'tournament'; // the host reports 'ended' once the last calendar match is finished
}
/** Deal teams (registration order) round-robin into groups A-H, groupSize each; the rest overflow (2011|538). */
export function allocateGroups(teamIds,groups=DKR_GROUPS,size=C.groupSize){
  const out=Object.fromEntries(groups.map(g=>[g,[]])),overflow=[];
  teamIds.forEach((id,i)=>{const g=groups[i%groups.length];if(out[g].length<size)out[g].push(id);else overflow.push(id);});return {groups:out,overflow};
}
/** League matches from the calendar rows and the group slots (missing slot = null side). */
export function leagueMatches(cal,groups,pairs=C.leaguePairs){
  return cal.league.map(r=>{const [a,b]=pairs[(r.order-1)%pairs.length]||[0,1],ids=groups[r.group]||[];return {...r,kind:'league',left:ids[a]??null,right:ids[b]??null};});
}
/** Group standings from finished league matches. results: [{left,right,winner(0/1/null),kills:[a,b],deaths:[a,b]}]. */
export function standings(ids,results,order=new Map(),pts=C.points){
  const rows=new Map(ids.map(id=>[id,{id,win:0,draw:0,loss:0,kills:0,deaths:0,points:0}]));
  for(const r of results){for(const s of [0,1]){const id=s?r.right:r.left,row=rows.get(id);if(!row)continue;
    row.kills+=r.kills?.[s]||0;row.deaths+=r.deaths?.[s]||0;
    if(r.winner===s){row.win++;row.points+=pts.win;}else if(r.winner==null&&!r.noShow){row.draw++;row.points+=pts.draw;}else{row.loss++;row.points+=pts.loss;}}}
  return [...rows.values()].sort((a,b)=>b.points-a.points||(b.kills-b.deaths)-(a.kills-a.deaths)||b.kills-a.kills||(order.get(a.id)??1e9)-(order.get(b.id)??1e9)).map((r,i)=>({...r,rank:i+1}));
}
/** Tournament bracket: Round of 16 from the group ranks, then 8 / 4 / third place (3) / final (2). */
export function buildTournament(cal,ranks,seed=C.round16){
  const at=key=>cal.tournament.find(t=>t.key===key)?.at??null,b=new Map(),pick=(g,r)=>ranks[g]?.[r-1]?.id??null;
  seed.forEach(([g1,r1,g2,r2],i)=>b.set(`T:16:${i+1}`,{key:`T:16:${i+1}`,kind:'tournament',match:16,order:i+1,at:at(`T:16:${i+1}`),left:pick(g1,r1),right:pick(g2,r2)}));
  for(const [m,c] of [[8,4],[4,2],[2,1]])for(let o=1;o<=c;o++)b.set(`T:${m}:${o}`,{key:`T:${m}:${o}`,kind:'tournament',match:m,order:o,at:at(`T:${m}:${o}`),left:null,right:null,feeds:[`T:${m*2}:${2*o-1}`,`T:${m*2}:${2*o}`]});
  b.set('T:3:1',{key:'T:3:1',kind:'tournament',match:3,order:1,at:at('T:3:1'),left:null,right:null,feeds:['T:4:1','T:4:2'],losers:true});
  for(const m of b.values()){m.status='pending';m.winner=undefined;}
  return b;
}
/** After a tournament match: fill the next slots (winner up, semi-final losers to the third-place match). */
export function advanceTournament(b,m){
  for(const x of b.values()){if(!x.feeds)continue;const slot=x.feeds.indexOf(m.key);if(slot<0)continue;
    const id=x.losers?(m.match===4&&m.winner!=null?(m.winner===0?m.right:m.left):null):(m.winner==null?null:(m.winner===0?m.left:m.right));
    if(slot===0)x.left=id;else x.right=id;}
}
/** Who wins a round: annihilation -> the side still standing; at Round_Time -> more kills, else a draw round (-1). */
export function roundOutcome({alive,kills},reason){
  if(reason==='annihilation'){const a=alive[0]>0,b=alive[1]>0;return a&&!b?0:b&&!a?1:-1;}
  return kills[0]>kills[1]?0:kills[1]>kills[0]?1:-1;
}
export const matchDecided=(wins,rounds)=>wins.some(w=>w>=C.roundsToWin)||rounds>=C.maxRounds;
/** Match winner: more round wins; league level -> draw (null); tournament level -> kills, fewer deaths, upper slot. */
export function matchWinner({kind,wins,kills,deaths}){
  if(wins[0]!==wins[1])return wins[0]>wins[1]?0:1;if(kind==='league')return null;
  if(kills[0]!==kills[1])return kills[0]>kills[1]?0:1;if(deaths[0]!==deaths[1])return deaths[0]<deaths[1]?0:1;return 0;
}
/** 2011|117 "<MONTH> / <DAY> <HOUR> : <MINUTE>". */
export function dateLabel(template,ms){const d=serverDate(ms),p=v=>String(v).padStart(2,'0');return String(template||'<MONTH> / <DAY> <HOUR> : <MINUTE>').replace('<MONTH>',p(d.getUTCMonth()+1)).replace('<DAY>',p(d.getUTCDate())).replace('<HOUR>',p(d.getUTCHours())).replace('<MINUTE>',p(d.getUTCMinutes()));}
/** Window title of a match: Group stage A-H (2011|101-108) / Round of 16 / 8 / 4, third place, final. */
export const groupCode=g=>101+DKR_GROUPS.indexOf(g);
