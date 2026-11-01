// DKR-PVP: server-authoritative DK Rumble 3v3 PvP season (Colosseum pvp3v3). Original data: share/dkrpvpbattle/config.csv
// (map 164, ObserverMaxCount, Wait_Time, Round_Time, Match_Create_Time, team start cells, ObserverSpeed) and matchtime.csv
// (registration, league allocation, league groups A-H orders 1-6, tournament 16/8/4/3/2 calendar). NPC jobs: 148 register,
// 149 game info, 160 enter player, 161 enter observer (Entry Guard 6180 on 719, 60006 on 714). Texts: stringtable_partywarui
// 2011|*. Every value the data does not give is in src/config/engine-chosen-dkr-pvp.js. Player-vs-player hits run through
// the shared PvP pipeline (server/world/pvp.mjs, rules src/game/pvp-rules.js); observers use server/world/observers.mjs.
import {DKR_PVP_CHOSEN as C} from '../../src/config/engine-chosen-dkr-pvp.js';
import {DKR_JOBS,DKR_TEAM_SIZE,DKR_NAME_MAX,dkrData,seasonPhase,allocateGroups,leagueMatches,standings,buildTournament,advanceTournament,roundOutcome,matchDecided,matchWinner,DKR_GROUPS} from '../../src/systems/events/dkr-pvp-rules.js';
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
  allocated:'League allocation completed.',                                            // 2011|537
  allocFailed:'League allocation failed.',                                             // 2011|538
  mounted:'Cannot enter while mounted.',                                               // 2011|545
  inParty:'Cannot enter while in a party.',                                            // 2011|546
  mismatch:'Party info does not match registered team info.\nTo update members, cancel and reapply.', // 2011|547
  otherTeam:'One or more party members are already registered in another team.',      // 2011|548
  already:'Application failed. One or more characters are already registered.',        // 2011|550
  nameTaken:'Team name already exists. Please choose a different name.',               // 2011|551
  noMatch:'No ongoing matches at this time.\nPlease check the match schedule.',         // 2011|554
  far:'Walk near the Entry Guard first.',                                              // engine text
  busy:'You cannot enter from here.',                                                  // engine text
  full:'This match cannot take more observers.',                                       // engine text
  fighter:'You cannot watch a match you are playing in.',                              // engine text
  open:'Your DK Rumble match is open. Talk to the Entry Guard to enter.',              // engine text
};
export const DKR_REVIVE_TEXT='You cannot revive during a DK Rumble round.'; // engine text
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const dataOf=world=>{const d=world.data?.dkrPvp||(world.data.dkrPvp=dkrData(world.data.eventData?.modes,world.data.dkrPvpCalendar||null));if(!d)fail('DK Rumble tables are unavailable on this host.',503);return d;};
const live=(world,p)=>!!p&&world.players.get(p.account)===p&&!p.leaving;
const byId=(world,id)=>{for(const q of world.players.values())if(q.id===id&&!q.leaving)return q;return null;};
const byChar=(world,cid)=>{for(const q of world.players.values())if(q.characterId===cid&&!q.leaving)return q;return null;};
const fresh=key=>({seasonKey:key,teams:new Map(),serial:0,allocated:false,groups:null,overflow:[],matches:new Map(),bracket:false,runs:new Map(),ended:false,champion:null});
function S(world){const d=dataOf(world),key=d.calendar.registrationStart;if(!world.dkrPvp||world.dkrPvp.seasonKey!==key)world.dkrPvp=fresh(key);return world.dkrPvp;}
const requireNpc=(world,p,job,input)=>{const npc=nearbyNpc(world,p,{jobType:job,radius:C.npcRadius,...(input?.npcIndex!=null&&Number.isInteger(Number(input.npcIndex))?{npcIndex:Number(input.npcIndex)}:{})});if(!npc)fail(DKR_TEXT.far,403);return npc;};
const teamOf=(s,cid)=>{for(const t of s.teams.values())if(t.members.some(m=>m.characterId===cid))return t;return null;};
const runOf=(world,p)=>{if(!p?.instanceId)return null;for(const r of world.dkrPvp?.runs?.values()||[])if(r.instance?.id===p.instanceId)return r;return null;};
const sideOf=(run,p)=>run?run.sides.findIndex(x=>x.ids.has(p.id)):-1;
const tell=(world,ids,text)=>{for(const q of world.players.values())if(!q.leaving&&ids.includes(q.characterId))world.emit(q.map,{type:'event:message',text,recipients:[q.id]});};
const memberIds=t=>t?t.members.map(m=>m.characterId):[];
/** Observers of a DK Rumble match. */
export function isDkrObserver(world,p){const run=runOf(world,p);return !!run&&run.observers.has(p.characterId);}
export const DKR_OBSERVER_ACTIONS=new Set(['move','stop','chat','emote','dkr']);
registerObserverMode({is:isDkrObserver,actions:DKR_OBSERVER_ACTIONS});
export function dkrEnemy(world,p,q){
  const run=runOf(world,p);if(!run||run.phase!=='battle'||!q||runOf(world,q)!==run)return false;
  const a=sideOf(run,p),b=sideOf(run,q);return a>=0&&b>=0&&a!==b&&!run.down.has(p.id)&&!run.down.has(q.id)&&sameScene(p,q);
}
function markDown(world,run,q,by){
  if(run.down.has(q.id))return;run.down.add(q.id);q.hp=0;q.dead=true;q.path=[];world.changed(q);
  const v=sideOf(run,q);if(v<0)return;run.sides[v].deaths++;run.roundDeaths[v]++;const st=run.stats.get(q.id);if(st)st.deaths++;
  const s=by?sideOf(run,by):-1;if(s>=0&&s!==v){run.sides[s].kills++;run.roundKills[s]++;const k=run.stats.get(by.id);if(k)k.kills++;if(run.firstKill==null)run.firstKill=s;}
}
registerPvpMode({enemy:dkrEnemy,opponents:(world,p)=>[...world.players.values()].filter(q=>dkrEnemy(world,p,q)&&!q.dead),
  onDown:(world,attacker,target)=>{const run=runOf(world,target);if(run&&sideOf(run,target)>=0)markDown(world,run,target,attacker);}});
/** Downed fighters stay down until the next round; the host revive is refused inside a match. */
export function dkrBlocksRevive(world,p){const run=runOf(world,p);return !!run&&sideOf(run,p)>=0;}
// --- registration (job 148)
function partyOf(world,p){const party=p.partyId?world.parties?.get(p.partyId):null;if(!party)fail(DKR_TEXT.noParty);if(party.leader!==p.id)fail(DKR_TEXT.leader,403);return party;}
function periodCheck(world,{edit=false}={}){const d=dataOf(world),ph=seasonPhase(d.calendar,world.now());
  if(ph==='before')fail(DKR_TEXT.notPeriod,409);if(ph!=='registration')fail(edit?DKR_TEXT.updateFailed:DKR_TEXT.periodEnded,409);}
const cleanName=v=>String(v??'').replace(/[\u0000-\u001f<>]/g,'').trim();
const markOf=input=>guildMark({bg:Number(input.bg??1),icon:Number(input.icon??1)});
function partyRows(world,party){
  if(party.members.length!==DKR_TEAM_SIZE)fail(DKR_TEXT.count);
  const rows=party.members.map(id=>{const q=byId(world,id);if(!q||!live(world,q))fail(DKR_TEXT.failed,409);return {characterId:q.characterId,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:Number(q.profile.level)||1};});
  if(new Set(rows.map(r=>r.classIndex)).size!==rows.length)fail(DKR_TEXT.sameClass);return rows;
}
function nameCheck(s,name,except){if(!name||name.length>DKR_NAME_MAX)fail(DKR_TEXT.failed);const low=name.toLowerCase();for(const t of s.teams.values())if(t.id!==except&&t.name.toLowerCase()===low)fail(DKR_TEXT.nameTaken,409);}
function register(world,p,input){
  requireNpc(world,p,DKR_JOBS.register,input);periodCheck(world);const s=S(world),party=partyOf(world,p),rows=partyRows(world,party);
  if(teamOf(s,p.characterId))fail(DKR_TEXT.already,409);if(rows.some(r=>teamOf(s,r.characterId)))fail(DKR_TEXT.otherTeam,409);
  const name=cleanName(input.name),mark=markOf(input);if(!mark)fail(DKR_TEXT.failed);nameCheck(s,name);
  const id=`t${++s.serial}`;s.teams.set(id,{id,name,mark,leader:p.characterId,members:rows,order:s.serial,registeredAt:world.now()});
  return {operation:'register',team:id,text:DKR_TEXT.applied};
}
function edit(world,p,input){
  requireNpc(world,p,DKR_JOBS.register,input);periodCheck(world,{edit:true});const s=S(world),t=teamOf(s,p.characterId);if(!t)fail(DKR_TEXT.updateFailed,404);
  if(t.leader!==p.characterId)fail(DKR_TEXT.leader,403);const party=partyOf(world,p);
  const now=party.members.map(id=>byId(world,id)?.characterId).filter(Boolean).sort().join(),was=memberIds(t).sort().join();if(now!==was)fail(DKR_TEXT.mismatch,409);
  const name=cleanName(input.name??t.name),mark=input.bg==null&&input.icon==null?t.mark:markOf(input);if(!mark)fail(DKR_TEXT.updateFailed);nameCheck(s,name,t.id);
  t.name=name;t.mark=mark;return {operation:'edit',team:t.id,text:DKR_TEXT.updated};
}
function cancel(world,p,input){
  requireNpc(world,p,DKR_JOBS.register,input);const d=dataOf(world);if(seasonPhase(d.calendar,world.now())!=='registration')fail(DKR_TEXT.cancelFailed,409);
  const s=S(world),t=teamOf(s,p.characterId);if(!t)fail(DKR_TEXT.cancelFailed,404);if(t.leader!==p.characterId)fail(DKR_TEXT.leader,403);
  s.teams.delete(t.id);return {operation:'cancel',text:DKR_TEXT.cancelled};
}
// --- season flow
function allocate(world,s){const d=dataOf(world),ids=[...s.teams.values()].sort((a,b)=>a.order-b.order).map(t=>t.id),{groups,overflow}=allocateGroups(ids);
  s.groups=groups;s.overflow=overflow;s.allocated=true;for(const m of leagueMatches(d.calendar,groups))s.matches.set(m.key,{...m,status:'pending'});
  for(const t of s.teams.values())tell(world,memberIds(t),overflow.includes(t.id)?DKR_TEXT.allocFailed:DKR_TEXT.allocated);}
function results(s,kind,group){return [...s.matches.values()].filter(m=>m.kind===kind&&(!group||m.group===group)&&m.status==='done'&&m.result).map(m=>({left:m.left,right:m.right,...m.result}));}
export function groupRanks(s){const order=new Map([...s.teams.values()].map(t=>[t.id,t.order]));return Object.fromEntries(DKR_GROUPS.map(g=>[g,standings(s.groups?.[g]||[],results(s,'league',g),order)]));}
function seedTournament(world,s){const d=dataOf(world);for(const [k,m] of buildTournament(d.calendar,groupRanks(s)))s.matches.set(k,m);s.bracket=true;}
function side(s,teamId){const t=s.teams.get(teamId);return {teamId,name:t?.name||'',mark:t?.mark||null,members:memberIds(t),ids:new Set(),wins:0,kills:0,deaths:0};}
function openRun(world,s,m){const d=dataOf(world),now=world.now();
  const run={key:m.key,kind:m.kind,group:m.group,match:m.match,order:m.order,at:m.at,phase:'entry',phaseEnd:Math.max(now,m.at-d.createSec*1000)+d.waitSec*1000,round:0,rounds:[],
    sides:[side(s,m.left),side(s,m.right)],down:new Set(),roundKills:[0,0],roundDeaths:[0,0],firstKill:null,roundStart:0,stats:new Map(),instance:null,observers:new Set(),result:null};
  s.runs.set(m.key,run);m.status='open';for(const x of run.sides)tell(world,x.members,DKR_TEXT.open);return run;}
function settle(world,s,m,result){m.status='done';m.result=result;if(m.kind==='tournament'){m.winner=result.winner;advanceTournament(s.matches,m);if(m.match===2)s.champion=result.winner==null?null:(result.winner===0?m.left:m.right);}}
function finishMatch(world,s,run,reason){
  const m=s.matches.get(run.key),wins=run.sides.map(x=>x.wins),kills=run.sides.map(x=>x.kills),deaths=run.sides.map(x=>x.deaths);
  const winner=reason==='forfeit'?run.forfeitWinner:reason==='noShow'?null:matchWinner({kind:run.kind,wins,kills,deaths});
  run.result={winner,reason,wins,kills,deaths,noShow:reason==='noShow',rounds:run.rounds.map(r=>({...r})),names:run.sides.map(x=>x.name),
    members:run.sides.map(x=>x.members.map(cid=>{const q=byChar(world,cid),st=q&&run.stats.get(q.id);return {characterId:cid,name:q?.profile?.name||s.teams.get(x.teamId)?.members.find(r=>r.characterId===cid)?.name||'',classIndex:Number(q?.profile?.classIndex)||0,level:Number(q?.profile?.level)||0,kills:st?.kills||0,deaths:st?.deaths||0,entered:!!st};}))};
  settle(world,s,m,run.result);run.phase='matchEnd';run.phaseEnd=world.now()+C.finishMatchSec*1000;
}
function placeSide(world,run,i){const d=dataOf(world),starts=i===0?d.teamA:d.teamB,scene=run.instance.scene;let n=0;
  for(const id of run.sides[i].ids){const q=byId(world,id);if(!q||runOf(world,q)!==run)continue;const [x,z]=starts[n++%starts.length];const at=scene.nearest(x+.5,z+.5);if(at){q.x=at.x;q.z=at.z;q.path=[];}
    q.dead=false;q.hp=q.maxHp;q.mp=q.stats?.maxMp||0;q.shield=Number(q.stats?.maxShield)||0;delete q.pvpLastHit;world.changed(q);world.emit(q.map,{type:'revive',actorId:q.id,instanceId:q.instanceId});}}
function endRound(world,run,reason){
  const alive=run.sides.map(x=>[...x.ids].filter(id=>!run.down.has(id)).length),winner=roundOutcome({alive,kills:run.roundKills},reason);
  if(winner>=0)run.sides[winner].wins++;
  run.rounds.push({winner,kills:[...run.roundKills],deaths:[...run.roundDeaths],firstKill:run.firstKill,ms:world.now()-run.roundStart,reason});run.round++;
  run.phase='roundEnd';run.phaseEnd=world.now()+C.finishRoundSec*1000;
}
async function closeRun(world,s,run){
  if(run.instance){const members=[...world.players.values()].filter(q=>runOf(world,q)===run);for(const q of members)if(q.dead){q.dead=false;q.hp=q.maxHp;world.changed(q);}
    if(members.length){void requestInstanceClose(world,run.instance)?.catch?.(()=>{});return false;}}
  s.runs.delete(run.key);return true;}
async function tickRun(world,s,run){const d=dataOf(world),now=world.now();
  if(run.instance)for(const x of run.sides)for(const id of [...x.ids]){const q=byId(world,id);if((!q||!live(world,q)||runOf(world,q)!==run)&&run.phase==='battle')run.down.add(id);}
  if(run.phase==='entry'&&now>=run.phaseEnd){
    const counts=run.sides.map(x=>x.ids.size);
    if(counts.every(c=>c<C.minimumEntrants)){finishMatch(world,s,run,'noShow');return;}
    if(counts.some(c=>c<C.minimumEntrants)){run.forfeitWinner=counts[0]>=C.minimumEntrants?0:1;finishMatch(world,s,run,'forfeit');return;}
    placeSide(world,run,0);placeSide(world,run,1);run.phase='count';run.phaseEnd=now+C.countSec*1000;return;}
  if(run.phase==='count'&&now>=run.phaseEnd){run.phase='battle';run.phaseEnd=now+d.roundSec*1000;run.roundStart=now;run.down=new Set();run.roundKills=[0,0];run.roundDeaths=[0,0];run.firstKill=null;return;}
  if(run.phase==='battle'){
    for(const x of run.sides)for(const id of x.ids){const q=byId(world,id);if(q&&runOf(world,q)===run&&(q.dead||q.hp<=0))markDown(world,run,q,q.pvpLastHit?.by&&byId(world,q.pvpLastHit.by));}
    const alive=run.sides.map(x=>[...x.ids].filter(id=>!run.down.has(id)).length);
    if(alive.some(a=>a===0))endRound(world,run,'annihilation');else if(now>=run.phaseEnd)endRound(world,run,'time');return;}
  if(run.phase==='roundEnd'&&now>=run.phaseEnd){
    if(matchDecided(run.sides.map(x=>x.wins),run.round)){finishMatch(world,s,run,'decided');return;}
    run.phase='break';run.phaseEnd=now+C.breakSec*1000;placeSide(world,run,0);placeSide(world,run,1);return;}
  if(run.phase==='break'&&now>=run.phaseEnd){run.phase='count';run.phaseEnd=now+C.countSec*1000;return;}
  if(run.phase==='matchEnd'&&now>=run.phaseEnd)await closeRun(world,s,run);
}
const feedsDone=(s,m)=>!m.feeds||m.feeds.every(k=>s.matches.get(k)?.status==='done');
export async function tickDkrPvp(world){
  let d;try{d=dataOf(world);}catch{return;}const s=S(world),now=world.now(),cal=d.calendar,ph=seasonPhase(cal,now);
  if(s.ended)return;
  if(!s.allocated&&(ph==='league'||ph==='tournament'))allocate(world,s);
  if(!s.allocated)return;
  const tOpen=cal.tournament.length?Math.min(...cal.tournament.map(t=>t.at))-d.createSec*1000:Infinity;
  if(!s.bracket&&now>=tOpen&&[...s.matches.values()].every(m=>m.kind!=='league'||m.status==='done'))seedTournament(world,s);
  for(const m of s.matches.values()){
    if(m.status!=='pending'||m.at==null||now<m.at-d.createSec*1000||!feedsDone(s,m))continue;
    if(!m.left&&!m.right){settle(world,s,m,{winner:null,reason:'empty',wins:[0,0],kills:[0,0],deaths:[0,0],noShow:true,bye:true});continue;}
    if(!m.left||!m.right){if(m.kind==='league'){m.status='done';m.result=null;m.bye=true;continue;}settle(world,s,m,{winner:m.left?0:1,reason:'bye',wins:[0,0],kills:[0,0],deaths:[0,0],bye:true});continue;}
    openRun(world,s,m);
  }
  for(const run of [...s.runs.values()])await tickRun(world,s,run);
  if(s.bracket&&!s.runs.size&&[...s.matches.values()].every(m=>m.status==='done'))s.ended=true;
}
// --- enter (job 160) / observe (job 161) / leave
async function admit(world,run,p,observer){const d=dataOf(world),exit={map:p.map,x:p.x,z:p.z};
  if(!run.instance)run.instance=await createInstance(world,{map:d.map,members:[p],kind:'dkrPvp',exit,durationMs:(d.waitSec+d.createSec+C.maxRounds*(C.countSec+d.roundSec+C.finishRoundSec+C.breakSec)+C.finishMatchSec+300)*1000});
  else{const instance=run.instance;world.emit(p.map,{type:'leave',actorId:p.id});p.instanceId=instance.id;p.map=instance.map;p.path=[];p.mount=null;p.pet=null;instance.admitted.add(p.characterId);instance.members.add(p.id);p.profile.instance={id:instance.id,kind:instance.kind,map:instance.map,exit:instance.exit};}
  const i=sideOf(run,p),[x,z]=observer?C.observerPoint:(i===0?d.teamA:d.teamB)[Math.max(0,run.sides[i].ids.size-1)%DKR_TEAM_SIZE];
  const at=run.instance.scene.nearest(Number(x)+.5,Number(z)+.5);if(at){p.x=at.x;p.z=at.z;}
  if(observer)run.observers.add(p.characterId);world.changed(p);await world.persist(p);if(!observer)world.emit(p.map,{type:'join',actorId:p.id});
}
async function enter(world,p,input){
  requireNpc(world,p,DKR_JOBS.enter,input);const s=S(world),open=[...s.runs.values()].filter(r=>r.phase==='entry');if(!open.length)fail(DKR_TEXT.noMatch,409);
  const t=teamOf(s,p.characterId);if(!t)fail(DKR_TEXT.onlyRegistered,403);const run=open.find(r=>r.sides.some(x=>x.teamId===t.id));if(!run)fail(DKR_TEXT.noMatch,409);
  if(p.mount?.phase==='on'||p.mount?.phase==='mounting')fail(DKR_TEXT.mounted,409);if(p.partyId)fail(DKR_TEXT.inParty,409);if(p.instanceId)fail(DKR_TEXT.busy,409);
  const i=run.sides.findIndex(x=>x.teamId===t.id);run.sides[i].ids.add(p.id);run.stats.set(p.id,{kills:0,deaths:0});
  await admit(world,run,p,false);return {operation:'enter',key:run.key};
}
async function observe(world,p,input){
  requireNpc(world,p,DKR_JOBS.observe,input);const s=S(world),d=dataOf(world),list=[...s.runs.values()].filter(r=>r.phase!=='matchEnd');if(!list.length)fail(DKR_TEXT.noMatch,409);
  const run=list.find(r=>r.key===input.key)||(input.key==null?list[0]:null);if(!run)fail(DKR_TEXT.noMatch,409);
  if(run.sides.some(x=>x.members.includes(p.characterId)))fail(DKR_TEXT.fighter,403);if(run.observers.size>=d.observerMax)fail(DKR_TEXT.full,409);
  if(p.mount?.phase==='on'||p.mount?.phase==='mounting')fail(DKR_TEXT.mounted,409);if(p.instanceId)fail(DKR_TEXT.busy,409);
  await admit(world,run,p,true);return {operation:'observe',key:run.key};
}
export async function dkrCommand(world,p,input){
  dataOf(world);
  switch(input.operation){
    case 'register':return register(world,p,input);
    case 'edit':return edit(world,p,input);
    case 'cancel':return cancel(world,p,input);
    case 'info':requireNpc(world,p,DKR_JOBS.info,input);return {operation:'info'};
    case 'enter':return enter(world,p,input);
    case 'observe':return observe(world,p,input);
    case 'leave':{const run=runOf(world,p);if(!run)fail('You are not in a DK Rumble match.');run.observers.delete(p.characterId);if(run.phase==='battle'&&sideOf(run,p)>=0)markDown(world,run,p,null);await exitInstance(world,p);return {operation:'leave'};}
    default:fail('Choose a DK Rumble operation.');
  }
}
// --- snapshot (sent near the Entry Guards, inside a match, and to registered players)
const teamView=t=>t?{id:t.id,name:t.name,mark:t.mark,members:t.members.map(m=>({name:m.name,classIndex:m.classIndex,level:m.level}))}:null;
const matchView=m=>({key:m.key,kind:m.kind,group:m.group,match:m.match,order:m.order,at:m.at,left:m.left,right:m.right,status:m.status,bye:!!m.bye,
  result:m.result?{winner:m.result.winner,reason:m.result.reason,bye:!!m.result.bye,wins:m.result.wins,kills:m.result.kills,deaths:m.result.deaths,rounds:m.result.rounds,members:m.result.members}:null});
const entrant=(world,run,id)=>{const q=byId(world,id),st=run.stats.get(id)||{kills:0,deaths:0};return q?{id,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:q.profile.level,down:run.down.has(id),hp:q.hp,maxHp:q.maxHp,shield:Number(q.shield)||0,maxShield:Number(q.stats?.maxShield)||0,...st}:{id,down:true,...st};};
const runView=(world,run,p,d)=>({key:run.key,kind:run.kind,group:run.group,match:run.match,order:run.order,at:run.at,phase:run.phase,remainingMs:Math.max(0,run.phaseEnd-world.now()),round:run.round,rounds:run.rounds,
  roundKills:run.roundKills,firstKill:run.firstKill,observers:run.observers.size,observerMax:d.observerMax,observerSpeed:d.observerSpeed,
  sides:run.sides.map(x=>({teamId:x.teamId,name:x.name,mark:x.mark,wins:x.wins,kills:x.kills,deaths:x.deaths,entrants:[...x.ids].map(id=>entrant(world,run,id))})),
  mySide:sideOf(run,p),inside:runOf(world,p)===run,observer:run.observers.has(p.characterId)&&runOf(world,p)===run,down:run.down.has(p.id),result:run.result});
const nearGuard=(world,p)=>{try{return npcPlacements(world,p.map).some(r=>r.jobs.some(([t])=>[DKR_JOBS.register,DKR_JOBS.enter,DKR_JOBS.observe].includes(Number(t))));}catch{return false;}};
export function dkrSnapshot(world,p){
  let d;try{d=dataOf(world);}catch{return null;}const s=world.dkrPvp;const mine=s&&teamOf(s,p.characterId),inside=runOf(world,p);
  if(!inside&&!mine&&!nearGuard(world,p))return null;
  const now=world.now(),cal=d.calendar,party=p.partyId?world.parties?.get(p.partyId):null;
  const out={phase:s?.ended?'ended':seasonPhase(cal,now),now,calendar:{registrationStart:cal.registrationStart,registrationEnd:cal.registrationEnd,leagueStart:cal.leagueStart},
    party:party?{leader:party.leader===p.id,members:party.members.map(id=>byId(world,id)).filter(Boolean).map(q=>({name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:q.profile.level}))}:null,
    my:mine?{...teamView(mine),leader:mine.leader===p.characterId,group:s.groups?Object.keys(s.groups).find(g=>s.groups[g].includes(mine.id))||null:null}:null,
    teams:{},groups:null,matches:[],open:[],run:null,champion:s?.champion||null,teamCount:s?.teams.size||0};
  if(!s)return out;
  for(const t of s.teams.values())out.teams[t.id]=teamView(t);
  if(s.groups)out.groups=Object.fromEntries(Object.entries(groupRanks(s)));
  out.matches=[...s.matches.values()].map(matchView);
  out.open=[...s.runs.values()].filter(r=>r.phase!=='matchEnd').map(r=>({key:r.key,kind:r.kind,group:r.group,match:r.match,order:r.order,at:r.at,phase:r.phase,left:r.sides[0].teamId,right:r.sides[1].teamId,observers:r.observers.size}));
  const run=inside||(mine&&[...s.runs.values()].find(r=>r.sides.some(x=>x.teamId===mine.id)));if(run)out.run=runView(world,run,p,d);
  return out;
}