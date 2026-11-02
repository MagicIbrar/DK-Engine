// DKR-PVP: DK Rumble 3v3 PvP (Colosseum pvp3v3), GM-run as in Global. Lane 47 (2026-10-29) replaced the invented automatic
// season (calendar-driven allocation, league points, rank order, Round of 16 seeding, rounds-to-win, round / break / result
// timers, observer point, revive rule) with the Global GM command flow (client GM help strings, decompile 64-bit-named
// strings-xref.csv / 32-bit-main decompiled.c 269971-270054):
//   dkrpvp_create [startTime] [endTi..] / dkrpvp_delete [code] / dkrpvp_setstatus [start|apply|league|tournament|end] [end time]
//   dkrpvp_applystart [teamname] [teammark] [teammarkbg] / dkrpvp_applymember [membername] [membercharno] [memberuserno]
//   [class] [grade] [world] [level] / dkrpvp_selectteam / dkrpvp_createleague / dkrpvp_open|finish [type] [group] [order]
//   dkrpvp_createtournament [league group1] [league order1] [league team1] [league group2] [league order2] [league team2]
//   [tournament group] [tournament order] [match time]
// Server replies follow the Global strings "DKRPvPBattle CREATE %s %s", "DKRPvPBattle DELETE %s %s", "DKRPvPBattle SetState %s"
// and "DKRPvPBattle SetState %s %u". Data used as written: share/dkrpvpbattle/config.csv (map, ObserverMaxCount, Wait_Time,
// Round_Time, three start cells per team) and matchtime.csv (shown calendar). NPC jobs 148 register, 149 game info, 160 enter
// player, 161 enter observer (Entry Guard 6180 on 719, 60006 on 714). Texts: stringtable_partywarui 2011|*.
// REMOVED (lane 71: no Global value, no older-server reference data (its share/ has no dkrpvpbattle tables) and no credible online rule;
// see LANE-47-REPORT.md / LANE-71-REPORT.md): createleague allocation, selectteam meaning,
// how createtournament's [league team] picks a team, round count / round winner / match winner, observer entry point,
// the time format of the GM time arguments.
import {DKR_JOBS,DKR_TEAM_SIZE,DKR_NAME_MAX,dkrData} from '../../src/systems/events/dkr-pvp-rules.js';
import {registerPvpMode} from './pvp.mjs';
import {registerObserverMode} from './observers.mjs';
import {createInstance,exitInstance,requestInstanceClose} from './instances.mjs';
import {nearbyNpc,npcPlacements} from './npc-services.mjs';
import {guildMark} from './guilds.mjs';
import {sameScene} from './scene.mjs';
export const DKR_SCHEMAS={dkr:['token','type','operation','npcIndex','name','bg','icon','key']};
// Original texts (stringtable_partywarui.txt cate 2011).
export const DKR_TEXT={
  noParty:'You are not in a party.',                                                   // 2011|500
  leader:'Only the party leader can do this.',                                         // 2011|501
  count:'Incorrect number of party members.',                                          // 2011|503
  sameClass:'Duplicate class in the party.',                                           // 2011|505
  failed:'Application failed.',                                                        // 2011|507
  periodEnded:'Application period has ended.',                                         // 2011|508
  applied:'Successfully applied.',                                                     // 2011|520
  onlyRegistered:'Only registered players can enter the match.',                       // 2011|523
  notPeriod:'Not during application period.',                                         // 2011|528
  updated:'Application information successfully updated.',                             // 2011|533
  updateFailed:'Failed to update application information.',                            // 2011|534
  cancelled:'Application successfully canceled.',                                      // 2011|535
  cancelFailed:'Failed to cancel application.',                                        // 2011|536
  mounted:'Cannot enter while mounted.',                                               // 2011|545
  inParty:'Cannot enter while in a party.',                                            // 2011|546
  mismatch:'Party info does not match registered team info.\nTo update members, cancel and reapply.', // 2011|547
  otherTeam:'One or more party members are already registered in another team.',      // 2011|548
  already:'Application failed. One or more characters are already registered.',        // 2011|550
  nameTaken:'Team name already exists. Please choose a different name.',               // 2011|551
  noMatch:'No ongoing matches at this time.\nPlease check the match schedule.',         // 2011|554
};
// Kept for the core.mjs import; the host no longer blocks revive (the Global revive rule is unknown), so it is never sent.
export const DKR_REVIVE_TEXT=DKR_TEXT.noMatch;
export const DKR_STATUS=Object.freeze(['start','apply','league','tournament','end']);
export const DKR_REMOVED=Object.freeze({
  createleague:'Removed (no source): dkrpvp_createleague league allocation is not in Global data.',
  selectteam:'Removed (no source): dkrpvp_selectteam behaviour is not in Global data.',
  tournamentTeam:'Removed (no source): dkrpvp_createtournament does not pick teams from [league team] (not in Global data).',
  observerPoint:'Removed (no source): Global config.csv has no observer entry point, so observing is closed.',
});
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const DKR_MISSING=new WeakSet();
const tablesOf=world=>{const data=world?.data;if(!data||typeof data!=='object')return null;if(data.dkrPvp)return data.dkrPvp;if(DKR_MISSING.has(data))return null;
  let d=null;try{d=dkrData(data.eventData?.modes,data.dkrPvpCalendar||null)||null;}catch(error){console.warn('[dkr-pvp] tables unavailable:',error?.message||error);}
  if(d)data.dkrPvp=d;else DKR_MISSING.add(data);return d;};
const dataOf=world=>{const d=tablesOf(world);if(!d)fail('DK Rumble tables are unavailable on this host.',503);return d;};
const live=(world,p)=>!!p&&world.players.get(p.account)===p&&!p.leaving;
const byId=(world,id)=>{for(const q of world.players.values())if(q.id===id&&!q.leaving)return q;return null;};
const season=world=>world.dkrPvp||null;
const requireNpc=(world,p,job,input,text)=>{const npc=nearbyNpc(world,p,{jobType:job,...(input?.npcIndex!=null&&Number.isInteger(Number(input.npcIndex))?{npcIndex:Number(input.npcIndex)}:{})});if(!npc)fail(text,403);return npc;};
const teamOf=(s,cid)=>{if(!s)return null;for(const t of s.teams.values())if(t.members.some(m=>m.characterId===cid))return t;return null;};
const runOf=(world,p)=>{if(!p?.instanceId)return null;for(const r of world.dkrPvp?.runs?.values()||[])if(r.instance?.id===p.instanceId)return r;return null;};
const sideOf=(run,p)=>run?run.sides.findIndex(x=>x.ids.has(p.id)):-1;
const memberIds=t=>t?t.members.map(m=>m.characterId):[];
export function isDkrObserver(world,p){const run=runOf(world,p);return !!run&&run.observers.has(p.characterId);}
export const DKR_OBSERVER_ACTIONS=new Set(['move','stop','chat','emote','dkr']);
registerObserverMode({is:isDkrObserver,actions:DKR_OBSERVER_ACTIONS});
export function dkrEnemy(world,p,q){
  const run=runOf(world,p);if(!run||run.phase!=='battle'||!q||runOf(world,q)!==run)return false;
  const a=sideOf(run,p),b=sideOf(run,q);return a>=0&&b>=0&&a!==b&&sameScene(p,q);
}
// ui_dashboard number_redkillcnt / number_bluekillcnt: kills and deaths are counted; nothing else is decided from them.
registerPvpMode({enemy:dkrEnemy,opponents:(world,p)=>[...world.players.values()].filter(q=>dkrEnemy(world,p,q)&&!q.dead),
  onDown:(world,attacker,target)=>{const run=runOf(world,target);if(!run)return;const v=sideOf(run,target);if(v<0)return;
    run.sides[v].deaths++;const st=run.stats.get(target.id);if(st)st.deaths++;
    const s=attacker?sideOf(run,attacker):-1;if(s>=0&&s!==v){run.sides[s].kills++;const k=run.stats.get(attacker.id);if(k)k.kills++;}}});
export function dkrBlocksRevive(){return false;}
// --- registration (job 148), open while the GM status is "apply"
function partyOf(world,p){const party=p.partyId?world.parties?.get(p.partyId):null;if(!party)fail(DKR_TEXT.noParty);if(party.leader!==p.id)fail(DKR_TEXT.leader,403);return party;}
function periodCheck(world,text){const s=season(world);if(!s||s.status==='start')fail(DKR_TEXT.notPeriod,409);if(s.status!=='apply')fail(text||DKR_TEXT.periodEnded,409);return s;}
const cleanName=v=>String(v??'').replace(/[\u0000-\u001f<>]/g,'').trim();
const markOf=input=>guildMark({bg:Number(input.bg),icon:Number(input.icon)});
function partyRows(world,party){
  if(party.members.length!==DKR_TEAM_SIZE)fail(DKR_TEXT.count);
  const rows=party.members.map(id=>{const q=byId(world,id);if(!q||!live(world,q))fail(DKR_TEXT.failed,409);return {characterId:q.characterId,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:Number(q.profile.level)||1};});
  if(new Set(rows.map(r=>r.classIndex)).size!==rows.length)fail(DKR_TEXT.sameClass);return rows;
}
function nameCheck(s,name,except){if(!name||name.length>DKR_NAME_MAX)fail(DKR_TEXT.failed);const low=name.toLowerCase();for(const t of s.teams.values())if(t.id!==except&&t.name.toLowerCase()===low)fail(DKR_TEXT.nameTaken,409);}
function register(world,p,input){
  requireNpc(world,p,DKR_JOBS.register,input,DKR_TEXT.failed);const s=periodCheck(world),party=partyOf(world,p),rows=partyRows(world,party);
  if(teamOf(s,p.characterId))fail(DKR_TEXT.already,409);if(rows.some(r=>teamOf(s,r.characterId)))fail(DKR_TEXT.otherTeam,409);
  const name=cleanName(input.name),mark=markOf(input);if(!mark)fail(DKR_TEXT.failed);nameCheck(s,name);
  const id=`t${++s.serial}`;s.teams.set(id,{id,name,mark,leader:p.characterId,members:rows,order:s.serial,registeredAt:world.now()});
  return {operation:'register',team:id,text:DKR_TEXT.applied};
}
function edit(world,p,input){
  requireNpc(world,p,DKR_JOBS.register,input,DKR_TEXT.updateFailed);const s=periodCheck(world,DKR_TEXT.updateFailed),t=teamOf(s,p.characterId);if(!t)fail(DKR_TEXT.updateFailed,404);
  if(t.leader!==p.characterId)fail(DKR_TEXT.leader,403);const party=partyOf(world,p);
  const now=party.members.map(id=>byId(world,id)?.characterId).filter(Boolean).sort().join(),was=memberIds(t).sort().join();if(now!==was)fail(DKR_TEXT.mismatch,409);
  const name=cleanName(input.name??t.name),mark=input.bg==null&&input.icon==null?t.mark:markOf(input);if(!mark)fail(DKR_TEXT.updateFailed);nameCheck(s,name,t.id);
  t.name=name;t.mark=mark;return {operation:'edit',team:t.id,text:DKR_TEXT.updated};
}
function cancel(world,p,input){
  requireNpc(world,p,DKR_JOBS.register,input,DKR_TEXT.cancelFailed);const s=periodCheck(world,DKR_TEXT.cancelFailed),t=teamOf(s,p.characterId);if(!t)fail(DKR_TEXT.cancelFailed,404);
  if(t.leader!==p.characterId)fail(DKR_TEXT.leader,403);s.teams.delete(t.id);return {operation:'cancel',text:DKR_TEXT.cancelled};
}
// --- GM commands (the Global names; parsed by server/world/gm-global-events.mjs)
const matchKey=(type,group,order)=>`${String(type)}:${String(group)}:${String(order)}`;
const needSeason=(world,code)=>{const s=season(world);if(!s)return fail(`DKRPvPBattle SetState ${code} BATTLE_NOT_EXIST`,404);return s;};
export async function dkrGm(world,command,args){
  dataOf(world);const a=args.map(v=>String(v));
  switch(command){
    case 'dkrpvp_create':{if(a.length<2)fail('dkrpvp_create [startTime] [endTime]');if(world.dkrPvp)return {message:`DKRPvPBattle CREATE ${world.dkrPvp.code} ALREADY_EXIST`};
      const code=String((world.dkrPvpSerial=(world.dkrPvpSerial||0)+1));
      world.dkrPvp={code,startTime:a[0],endTime:a[1],status:'start',statusEnd:null,teams:new Map(),serial:0,pending:null,matches:new Map(),runs:new Map()};
      return {message:`DKRPvPBattle CREATE ${code}`};}
    case 'dkrpvp_delete':{const s=season(world);if(!s||s.code!==a[0])return {message:`DKRPvPBattle DELETE ${a[0]??''} BATTLE_NOT_EXIST`};
      for(const run of [...s.runs.values()])await closeRun(world,s,run,true);world.dkrPvp=null;return {message:`DKRPvPBattle DELETE ${a[0]}`};}
    case 'dkrpvp_setstatus':{const s=needSeason(world,a[0]??'');if(!DKR_STATUS.includes(a[0]))fail('dkrpvp_setstatus [start|apply|league|tournament|end] [end time]');
      s.status=a[0];s.statusEnd=a[1]??null;return {message:`DKRPvPBattle SetState ${a[0]}`};}
    case 'dkrpvp_applystart':{const s=needSeason(world,'apply');if(a.length<3)fail('dkrpvp_applystart [teamname] [teammark] [teammarkbg]');
      const name=cleanName(a[0]),mark=guildMark({icon:Number(a[1]),bg:Number(a[2])});if(!mark)fail(DKR_TEXT.failed);nameCheck(s,name);
      const id=`t${++s.serial}`;s.teams.set(id,{id,name,mark,leader:null,members:[],order:s.serial,registeredAt:world.now(),gm:true});s.pending=id;return {message:`${DKR_TEXT.applied} ${name}`};}
    case 'dkrpvp_applymember':{const s=needSeason(world,'apply'),t=s.pending&&s.teams.get(s.pending);if(!t)fail('dkrpvp_applystart [teamname] [teammark] [teammarkbg]');
      if(a.length<7)fail('dkrpvp_applymember [membername] [membercharno] [memberuserno] [class] [grade] [world] [level]');
      if(t.members.length>=DKR_TEAM_SIZE)fail(DKR_TEXT.count);if(teamOf(s,a[1]))fail(DKR_TEXT.already,409);
      t.members.push({characterId:a[1],name:a[0],userNo:a[2],classIndex:Number(a[3])||0,grade:Number(a[4])||0,world:Number(a[5])||0,level:Number(a[6])||1});
      if(!t.leader)t.leader=a[1];return {message:`${DKR_TEXT.applied} ${a[0]}`};}
    case 'dkrpvp_selectteam':needSeason(world,'');return {message:DKR_REMOVED.selectteam,removed:true};
    case 'dkrpvp_createleague':needSeason(world,'');return {message:DKR_REMOVED.createleague,removed:true};
    case 'dkrpvp_createtournament':{const s=needSeason(world,'');if(a.length<9)fail('dkrpvp_createtournament [league group1] [league order1] [league team1] [league group2] [league order2] [league team2] [tournament group] [tournament order] [match time]');
      const key=matchKey('tournament',a[6],a[7]);
      s.matches.set(key,{key,kind:'tournament',match:Number(a[6]),order:Number(a[7]),time:a[8],from:[{group:a[0],order:a[1],team:a[2]},{group:a[3],order:a[4],team:a[5]}],left:null,right:null,status:'pending',result:null});
      return {message:`DKRPvPBattle CREATE ${key}`,note:DKR_REMOVED.tournamentTeam,removed:true};}
    case 'dkrpvp_open':{const s=needSeason(world,a.join(' '));const m=s.matches.get(matchKey(a[0],a[1],a[2]));
      if(!m)return {message:`DKRPvPBattle SetState ${a.join(' ')} BATTLE_NOT_EXIST`};if(!m.left||!m.right)return {message:`DKRPvPBattle SetState ${m.key} BATTLE_NOT_EXIST`,note:DKR_REMOVED.tournamentTeam};
      if(s.runs.has(m.key))return {message:`DKRPvPBattle SetState ${m.key} ALREADY_EXIST`};openRun(world,s,m);return {message:`DKRPvPBattle SetState ${m.key}`};}
    case 'dkrpvp_finish':{const s=needSeason(world,a.join(' '));const key=matchKey(a[0],a[1],a[2]),run=s.runs.get(key);if(!run)return {message:`DKRPvPBattle SetState ${key} BATTLE_NOT_EXIST`};
      finishRun(world,s,run);return {message:`DKRPvPBattle SetState ${key}`};}
    default:return null;
  }
}
// --- a GM-opened match: entry for config.csv Wait_Time, then the fight for Round_Time; dkrpvp_finish ends it.
function openRun(world,s,m){const d=dataOf(world),now=world.now(),team=id=>s.teams.get(id);
  const sides=[m.left,m.right].map(id=>{const t=team(id);return {teamId:id,name:t?.name||'',mark:t?.mark||null,members:memberIds(t),ids:new Set(),kills:0,deaths:0,wins:0};});
  const run={key:m.key,kind:m.kind,group:m.group,match:m.match,order:m.order,at:now,phase:'entry',phaseEnd:now+d.waitSec*1000,round:1,rounds:[],sides,stats:new Map(),observers:new Set(),instance:null,result:null};
  m.status='open';s.runs.set(m.key,run);return run;}
function finishRun(world,s,run){const m=s.matches.get(run.key);if(run.phase==='battle'||run.phase==='entry')run.rounds.push({winner:null,kills:run.sides.map(x=>x.kills),deaths:run.sides.map(x=>x.deaths)});
  run.phase='matchEnd';run.phaseEnd=null;
  // Removed (no source, lane 71): no match winner rule is in Global data; only the counted kills / deaths are recorded.
  run.result={winner:null,wins:[0,0],kills:run.sides.map(x=>x.kills),deaths:run.sides.map(x=>x.deaths),rounds:run.rounds};
  if(m){m.status='done';m.result=run.result;}}
async function closeRun(world,s,run,force=false){
  const members=[...world.players.values()].filter(q=>runOf(world,q)===run);
  if(members.length){if(!force)return false;for(const q of members)await exitInstance(world,q).catch(()=>{});}
  if(run.instance)void requestInstanceClose(world,run.instance)?.catch?.(()=>{});s.runs.delete(run.key);return true;}
export async function tickDkrPvp(world){const s=season(world);if(!s||!tablesOf(world))return;const d=dataOf(world),now=world.now();
  for(const run of [...s.runs.values()]){
    if(run.phase==='entry'&&now>=run.phaseEnd){run.phase='battle';run.phaseEnd=now+d.roundSec*1000;}
    else if(run.phase==='battle'&&now>=run.phaseEnd){run.phase='roundEnd';run.phaseEnd=null;run.rounds.push({winner:null,kills:run.sides.map(x=>x.kills),deaths:run.sides.map(x=>x.deaths)});}
    else if(run.phase==='matchEnd'&&run.instance){const inside=[...world.players.values()].some(q=>runOf(world,q)===run);if(!inside)await closeRun(world,s,run);}
  }
}
// --- enter (job 160) / observe (job 161) / leave
async function admit(world,run,p){const d=dataOf(world),exit={map:p.map,x:p.x,z:p.z};
  if(!run.instance)run.instance=await createInstance(world,{map:d.map,members:[p],kind:'dkrPvp',exit});
  else{const instance=run.instance;world.emit(p.map,{type:'leave',actorId:p.id});p.instanceId=instance.id;p.map=instance.map;p.path=[];p.mount=null;p.pet=null;instance.admitted.add(p.characterId);instance.members.add(p.id);p.profile.instance={id:instance.id,kind:instance.kind,map:instance.map,exit:instance.exit};}
  const i=sideOf(run,p),[x,z]=(i===0?d.teamA:d.teamB)[Math.max(0,run.sides[i].ids.size-1)%DKR_TEAM_SIZE];
  const at=run.instance.scene.nearest(Number(x)+.5,Number(z)+.5);if(at){p.x=at.x;p.z=at.z;}
  world.changed(p);await world.persist(p);world.emit(p.map,{type:'join',actorId:p.id});
}
async function enter(world,p,input){
  requireNpc(world,p,DKR_JOBS.enter,input,DKR_TEXT.noMatch);const s=season(world),open=[...(s?.runs.values()||[])].filter(r=>r.phase==='entry');if(!open.length)fail(DKR_TEXT.noMatch,409);
  const t=teamOf(s,p.characterId);if(!t)fail(DKR_TEXT.onlyRegistered,403);const run=open.find(r=>r.sides.some(x=>x.teamId===t.id));if(!run)fail(DKR_TEXT.noMatch,409);
  if(p.mount?.phase==='on'||p.mount?.phase==='mounting')fail(DKR_TEXT.mounted,409);if(p.partyId)fail(DKR_TEXT.inParty,409);if(p.instanceId)fail(DKR_TEXT.noMatch,409);
  const i=run.sides.findIndex(x=>x.teamId===t.id);run.sides[i].ids.add(p.id);run.stats.set(p.id,{kills:0,deaths:0});
  await admit(world,run,p);return {operation:'enter',key:run.key};
}
export async function dkrCommand(world,p,input){
  dataOf(world);
  switch(input.operation){
    case 'register':return register(world,p,input);
    case 'edit':return edit(world,p,input);
    case 'cancel':return cancel(world,p,input);
    case 'info':requireNpc(world,p,DKR_JOBS.info,input,DKR_TEXT.noMatch);return {operation:'info'};
    case 'enter':return enter(world,p,input);
    case 'observe':requireNpc(world,p,DKR_JOBS.observe,input,DKR_TEXT.noMatch);fail(DKR_REMOVED.observerPoint,409);break;
    case 'leave':{const run=runOf(world,p);if(!run)fail(DKR_TEXT.noMatch);run.observers.delete(p.characterId);await exitInstance(world,p);return {operation:'leave'};}
    default:fail(DKR_TEXT.noMatch);
  }
}
// --- snapshot (near the Entry Guards, inside a match, and to registered players). phase: the GM status read for the windows.
const PHASE={start:'before',apply:'registration',league:'league',tournament:'tournament',end:'ended'};
const teamView=t=>t?{id:t.id,name:t.name,mark:t.mark,members:t.members.map(m=>({name:m.name,classIndex:m.classIndex,level:m.level}))}:null;
const matchView=m=>({key:m.key,kind:m.kind,group:m.group,match:m.match,order:m.order,at:m.at??null,time:m.time??null,left:m.left,right:m.right,status:m.status,bye:false,result:m.result});
const entrant=(world,run,id)=>{const q=byId(world,id),st=run.stats.get(id)||{kills:0,deaths:0};return q?{id,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:q.profile.level,down:!!q.dead,hp:q.hp,maxHp:q.maxHp,shield:Number(q.shield)||0,maxShield:Number(q.stats?.maxShield)||0,...st}:{id,down:true,...st};};
const runView=(world,run,p,d)=>({key:run.key,kind:run.kind,group:run.group,match:run.match,order:run.order,at:run.at,phase:run.phase,remainingMs:run.phaseEnd?Math.max(0,run.phaseEnd-world.now()):0,round:run.round,rounds:run.rounds,
  roundKills:run.sides.map(x=>x.kills),firstKill:null,observers:run.observers.size,observerMax:d.observerMax,observerSpeed:d.observerSpeed,
  sides:run.sides.map(x=>({teamId:x.teamId,name:x.name,mark:x.mark,wins:x.wins,kills:x.kills,deaths:x.deaths,entrants:[...x.ids].map(id=>entrant(world,run,id))})),
  mySide:sideOf(run,p),inside:runOf(world,p)===run,observer:false,down:!!p.dead&&runOf(world,p)===run,result:run.result});
const nearGuard=(world,p)=>{try{return npcPlacements(world,p.map).some(r=>r.jobs.some(([t])=>[DKR_JOBS.register,DKR_JOBS.enter,DKR_JOBS.observe].includes(Number(t))));}catch{return false;}};
export function dkrSnapshot(world,p){
  const d=tablesOf(world);if(!d)return null;const s=season(world),mine=teamOf(s,p.characterId),inside=runOf(world,p);
  if(!inside&&!mine&&!nearGuard(world,p))return null;
  const cal=d.calendar,party=p.partyId?world.parties?.get(p.partyId):null;
  const out={phase:s?PHASE[s.status]:'before',status:s?.status||null,statusEnd:s?.statusEnd??null,code:s?.code??null,now:world.now(),
    calendar:{registrationStart:cal.registrationStart,registrationEnd:cal.registrationEnd,leagueStart:cal.leagueStart},
    party:party?{leader:party.leader===p.id,members:party.members.map(id=>byId(world,id)).filter(Boolean).map(q=>({name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:q.profile.level}))}:null,
    my:mine?{...teamView(mine),leader:mine.leader===p.characterId,group:null}:null,teams:{},groups:null,matches:[],open:[],run:null,champion:null,teamCount:s?.teams.size||0};
  if(!s)return out;
  for(const t of s.teams.values())out.teams[t.id]=teamView(t);
  out.matches=[...s.matches.values()].map(matchView);
  out.open=[...s.runs.values()].filter(r=>r.phase!=='matchEnd').map(r=>({key:r.key,kind:r.kind,group:r.group,match:r.match,order:r.order,at:r.at,phase:r.phase,left:r.sides[0].teamId,right:r.sides[1].teamId,observers:r.observers.size}));
  const run=inside||(mine&&[...s.runs.values()].find(r=>r.sides.some(x=>x.teamId===mine.id)));if(run)out.run=runView(world,run,p,d);
  return out;
}