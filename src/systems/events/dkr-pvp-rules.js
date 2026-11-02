// DKR-PVP data rules: read share/dkrpvpbattle/config.csv + matchtime.csv (gamedata events.json modes.colosseum.pvp3v3).
// Lane 47: the invented league / tournament / round decisions are removed; the season is GM-run (server/world/dkr-pvp.mjs).
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
/** 2011|117 "<MONTH> / <DAY> <HOUR> : <MINUTE>". */
export function dateLabel(template,ms){const d=serverDate(ms),p=v=>String(v).padStart(2,'0');return String(template||'<MONTH> / <DAY> <HOUR> : <MINUTE>').replace('<MONTH>',p(d.getUTCMonth()+1)).replace('<DAY>',p(d.getUTCDate())).replace('<HOUR>',p(d.getUTCHours())).replace('<MINUTE>',p(d.getUTCMinutes()));}
/** Window title of a match: Group stage A-H (2011|101-108) / Round of 16 / 8 / 4, third place, final. */
export const groupCode=g=>101+DKR_GROUPS.indexOf(g);
