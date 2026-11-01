import {socialError as fail,socialState,initializeSocial,socialRef} from './social-state.mjs';
import {RANK_ROWS,dungeonGradeOf} from '../../src/systems/extras/guildrank-rules.js';
import {engineFrontierWeek,FRONTIER_CHOSEN} from '../../src/config/engine-chosen-guild.js';

const MAX_POINTS=10_000_000_000,MAX_PERIODS=512,MAX_GUILDS=1000,MAX_DONORS=5000;
const own=(rows,key)=>Object.hasOwn(rows,key)?rows[key]:undefined;
const points=(n,label='Frontier Points')=>{if(!Number.isSafeInteger(n)||n<0||n>MAX_POINTS)fail(`${label} is invalid; data preserved.`,503);return n;};
function dictionary(value,label){if(!value||typeof value!=='object'||Array.isArray(value))fail(`${label} is invalid; data preserved.`,503);return value;}
function guildIdentity(row){if(!row||typeof row.id!=='string'||!row.id||['__proto__','constructor','prototype'].includes(row.id)||typeof row.name!=='string')fail('Frontier guild identity is invalid; data preserved.',503);}
export function frontierPeriodDescriptor(row){
  if(!row||typeof row.id!=='string'||!/^[a-zA-Z0-9_-]{1,64}$/.test(row.id)||['__proto__','constructor','prototype'].includes(row.id)||!Number.isSafeInteger(row.opensAt)||!Number.isSafeInteger(row.closesAt)||row.opensAt<0||row.opensAt>=row.closesAt)fail('An explicit immutable Frontier maintenance period is required.',503);
  return {id:row.id,opensAt:row.opensAt,closesAt:row.closesAt};
}
function periods(state){return dictionary(state.frontierPeriods||{},'Frontier periods');}
function compatible(saved,period){if(saved.id!==period.id||saved.opensAt!==period.opensAt||saved.closesAt!==period.closesAt)fail('The saved Frontier period differs from server policy; data preserved.',503);}
export function currentFrontierPeriod(world){
  let period;
  // An explicit policy period wins; guildPolicy.frontierSchedule 'engine-chosen' opts into the ENGINE-CHOSEN (not in Global data) weekly
  // Thursday 03:00 fixed server time UTC+1 maintenance week (src/config/engine-chosen-guild.js FRONTIER_CHOSEN.MAINTENANCE).
  const policy=world.data.guildPolicy;
  try{period=frontierPeriodDescriptor(policy?.frontierPeriod??(policy?.frontierSchedule==='engine-chosen'?engineFrontierWeek(world.now()):undefined));}catch{return null;}
  // Preserve immutable weeks already accepting donations while moving to the recovered clock.
  const now=world.now();
  if(policy?.frontierSchedule==='engine-chosen'&&policy.frontierPeriod===undefined){
    try{
      const history=Object.values(periods(world.socialState||{})).map(frontierPeriodDescriptor);
      const active=history.find(r=>r.opensAt<=now&&now<r.closesAt);
      if(active)period=active;
      else {const cutoff=Math.max(period.opensAt,...history.filter(r=>r.closesAt<=now&&r.closesAt<period.closesAt).map(r=>r.closesAt));period={...period,opensAt:cutoff};}
    }catch{return null;}
  }
  if(now<period.opensAt||now>=period.closesAt)return null;
  // Invalid policy disables this service without breaking unrelated snapshots.
  try{const saved=own(periods(world.socialState||{}),period.id);
    if(saved){compatible(saved,period);if(saved.closedAt!==undefined)return null;}
  }catch{return null;}
  return period;
}
function ledger(state,period){
  state.frontierPeriods||={};const rows=periods(state);let saved=own(rows,period.id);
  if(saved)compatible(saved,period);
  else{
    if(Object.keys(rows).length>=MAX_PERIODS)fail('Frontier period capacity reached; data preserved.',503);
    for(const row of Object.values(rows)){const other=frontierPeriodDescriptor(row);if(period.opensAt<other.closesAt&&period.closesAt>other.opensAt)fail('Frontier periods cannot overlap; data preserved.',503);}
    saved=rows[period.id]={...period};
  }
  // Preserve pre-patch totals still present in guild records. Deleted legacy
  // guilds cannot be reconstructed from the remaining client data.
  if(saved.guilds===undefined){
    saved.guilds={};
    for(const g of Object.values(state.guilds)){
      guildIdentity(g);
      const old=g.frontier&&own(g.frontier,period.id);if(!old)continue;
      const total=points(old.points);if(!total)continue;
      if(Object.keys(saved.guilds).length>=MAX_GUILDS)fail('Frontier guild capacity reached; data preserved.',503);
      saved.guilds[g.id]={id:g.id,name:g.name,points:total,donors:{}};
    }
  }
  dictionary(saved.guilds,'Frontier guild ledger');return saved;
}
/** Called only on the existing social transaction clone, before bag removal. */
export function recordFrontierDonation(state,guild,period,ref,name,reward){
  guildIdentity(guild);if(typeof ref!=='string'||!/^[a-f0-9]{64}$/.test(ref)||typeof name!=='string')fail('Frontier donor identity is invalid; items preserved.',503);
  const saved=ledger(state,frontierPeriodDescriptor(period));if(saved.closedAt!==undefined)fail('The Frontier period is finalized; items preserved.',409);
  const current=points(guild.frontier?.[period.id]?.points??0);let row=own(saved.guilds,guild.id);
  if(!row){if(Object.keys(saved.guilds).length>=MAX_GUILDS)fail('Frontier guild capacity reached; items preserved.',503);row=saved.guilds[guild.id]={id:guild.id,name:guild.name,points:current,donors:{}};}
  if(row.id!==guild.id||points(row.points)!==current)fail('Frontier guild totals disagree; items preserved.',503);
  dictionary(row.donors,'Frontier donor ledger');let donor=own(row.donors,ref);
  if(!donor){if(Object.keys(row.donors).length>=MAX_DONORS)fail('Frontier donor capacity reached; items preserved.',503);donor=row.donors[ref]={name,points:0,contribution:0,exp:0};}
  row.name=guild.name;donor.name=name;
  for(const key of ['points','contribution','exp'])donor[key]=points(points(donor[key])+points(reward[key]),`Weekly ${key}`);
  row.points=points(current+points(reward.points));
}
/** Preserve recoverable legacy weeks in the same zero-fund disband clone. */
export function preserveGuildFrontier(state,guild){
  guildIdentity(guild);
  for(const [id,total]of Object.entries(dictionary(guild.frontier??{},'Guild Frontier totals'))){
    const source=own(periods(state),id);if(!source)fail('Frontier period evidence is missing; guild preserved.',503);
    const saved=ledger(state,frontierPeriodDescriptor(source)),row=own(saved.guilds,guild.id);
    if(points(total.points)!==points(row?.points??0))fail('Frontier guild totals disagree; guild preserved.',503);
  }
}
/** Public score order only: a tie range is not an official awarded rank.
 * Names/points are public guild information; donor refs and account IDs stay private.
 */
function standings(state,periodId,all=false){
  const saved=own(periods(state),periodId);if(!saved)return null;
  const period=frontierPeriodDescriptor(saved),byId=new Map();
  if(saved.closedAt!==undefined&&(!Number.isSafeInteger(saved.closedAt)||saved.closedAt<period.closesAt))fail('Frontier closure is invalid; data preserved.',503);
  const entries=Object.entries(dictionary(saved.guilds??{},'Frontier guild ledger'));if(entries.length>MAX_GUILDS)fail('Frontier guild capacity exceeded; data preserved.',503);
  for(const [id,row]of entries){guildIdentity(row);if(id!==row.id)fail('Frontier guild key is invalid; data preserved.',503);if(points(row.points))byId.set(row.id,{id:row.id,name:row.name,points:row.points});}
  // Read-only legacy view; a later transaction migrates it durably.
  if(saved.guilds===undefined)for(const g of Object.values(state.guilds)){const n=points(g.frontier?.[periodId]?.points??0);if(n)byId.set(g.id,{id:g.id,name:g.name,points:n});}
  const rows=[...byId.values()].sort((a,b)=>b.points-a.points||(a.id<b.id?-1:a.id>b.id?1:0));
  let start=0;while(start<rows.length){let end=start+1;while(end<rows.length&&rows[end].points===rows[start].points)end++;for(let i=start;i<end;i++)rows[i].scorePosition=[start+1,end];start=end;}
  return {period,finalized:saved.closedAt!==undefined,closedAt:saved.closedAt??null,tiePolicy:FRONTIER_CHOSEN.TIE_RULE,awardPolicy:'native-grade-for-shared-rank',participants:rows.length,rows:all?rows:rows.slice(0,10)};
}
export function guildFrontierStandings(world,periodId){return standings(socialState(world),periodId);}
/** End of "the following week" of a finalized period (AUTHENTICATED NATIVE RULE 132:500 "The Frontier Dungeon rank is maintained for
 * one week, starting Thursday." / 132:501 "...gain access to the Frontier Dungeon for the following week."). With the engine-chosen
 * weekly policy it is the next policy week (exact across a DST change); otherwise one more period of the same length. */
function followingWeekEnd(world,period){
  if(world.data?.guildPolicy?.frontierSchedule==='engine-chosen'&&world.data.guildPolicy.frontierPeriod===undefined){
    try{const next=engineFrontierWeek(period.closesAt);if(next.opensAt<=period.closesAt&&next.closesAt>period.closesAt)return next.closesAt;}catch{/* falls back to the period length */}
  }
  return period.closesAt+(period.closesAt-period.opensAt);
}
/** Authenticated server-side Frontier Dungeon ownership of a guild: its competition score position (positive ties share the first rank) in the latest
 * FINALIZED period whose following week contains now, mapped through guild_dungeongrade.csv (Rank 1-10 -> Dungeon_Grade 1-10).
 * Reads only the durable social ledger; never a client field. null = the guild owns no Frontier Dungeon right now. */
export function frontierDungeonAward(world,guildId,grades=world.data?.guild?.dungeonGrade){
  let state,rows;try{state=socialState(world);rows=Object.values(periods(state));}catch{return null;}
  if(typeof guildId!=='string'||!guildId||!Array.isArray(grades))return null;
  const now=world.now();let best=null;
  for(const row of rows){
    let d;try{d=frontierPeriodDescriptor(row);}catch{continue;}
    if(row.closedAt===undefined||!Number.isSafeInteger(row.closedAt)||row.closedAt<d.closesAt)continue;
    const until=followingWeekEnd(world,d);if(now<d.closesAt||now>=until)continue;
    if(!best||d.closesAt>best.period.closesAt)best={period:d,until};
  }
  if(!best)return null;
  let shown;try{shown=standings(state,best.period.id,true);}catch{return null;}
  const mine=shown?.finalized?shown.rows.find(r=>r.id===guildId):null,grade=mine&&dungeonGradeOf(mine.scorePosition,grades);
  return grade?{periodId:best.period.id,rank:grade.rank,dungeonGrade:grade.dungeonGrade,validFrom:best.period.closesAt,validUntil:best.until}:null;
}
/** The live actor's guild (durable social membership by server-side character ref) and its current Frontier Dungeon award. */
export function guildFrontierAccess(world,p){
  let state;try{state=socialState(world);}catch{return {guild:null,award:null};}
  const ref=socialRef(p),guild=Object.values(state.guilds||{}).find(g=>Array.isArray(g?.members)&&g.members.some(m=>m.ref===ref))||null;
  return {guild,award:guild?frontierDungeonAward(world,guild.id):null};
}
/** GUILD-DUNGEON-RANK (ui_guilddungeonrankingwnd.txt + the guild window's Dungeon Lv, rules: guildrank-rules.js). Shows the open
 * period's live standings, else the latest finalized period; `mine` = the guild's own score position over ALL rows; `award` = the
 * guild_dungeongrade.csv Dungeon_Grade of its position in the latest FINALIZED period (positive ties share the first competition rank). Read-only; an invalid
 * ledger disables the view instead of breaking the guild snapshot. */
export function guildFrontierRanking(world,guildId,grades=[]){
  let state,saved;try{state=socialState(world);saved=Object.values(periods(state));}catch{return null;}
  const open=currentFrontierPeriod(world),finals=[];
  for(const row of saved){try{const d=frontierPeriodDescriptor(row);if(row.closedAt!==undefined)finals.push(d);}catch{/* skipped: invalid rows never shown */}}
  finals.sort((a,b)=>b.closesAt-a.closesAt);
  const full=id=>{try{return standings(state,id,true);}catch{return null;}};
  const place=s=>{const r=s?.rows.find(x=>x.id===guildId);return r?{points:r.points,scorePosition:r.scorePosition}:null;};
  const period=open||finals[0]||null,shown=period?full(period.id):null;
  // Dungeon Lv = the award that is in force now (132:500: kept for the one following week), not merely the newest settlement.
  const won=frontierDungeonAward(world,guildId,grades);
  return {period,live:!!open,finalized:!!shown?.finalized,participants:shown?.participants??0,
    rows:(shown?.rows||[]).slice(0,RANK_ROWS).map(r=>({id:r.id,name:r.name,points:r.points,scorePosition:r.scorePosition})),
    mine:place(shown),award:won?{periodId:won.periodId,rank:won.rank,dungeonGrade:won.dungeonGrade}:null};
}
/** Trusted maintenance hook, outside an active save/social transaction. The descriptor must equal the saved period (the server
 * policy's: production = the disclosed ENGINE-CHOSEN Thursday 03:00 fixed server time UTC+1 week, FRONTIER_CHOSEN.MAINTENANCE).
 * The same accounts-document CAS makes closure permanent and retry-safe; tickGuildFrontier is its scheduled production caller.
 */
export async function finalizeGuildFrontier(world,descriptor){
  const period=frontierPeriodDescriptor(descriptor);
  const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(async()=>{
    if(world.now()<period.closesAt)fail('Frontier maintenance cannot finalize an open period.',409);
    const current=socialState(world),old=own(periods(current),period.id);
    if(old){compatible(old,period);if(old.closedAt!==undefined)return guildFrontierStandings(world,period.id);}
    const state=structuredClone(current),saved=ledger(state,period);
    for(const g of Object.values(state.guilds)){const total=points(g.frontier?.[period.id]?.points??0),row=own(saved.guilds,g.id);if(total!==points(row?.points??0))fail('Frontier guild totals disagree; maintenance preserved.',503);}
    saved.closedAt=world.now();state.revision++;const result=standings(state,period.id);
    if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates:[]})===false)fail('The Frontier maintenance transaction could not be saved.',503);
    world.socialState=state;
    for(const p of world.players?.values?.()||[])if(p.map>=552&&p.map<=561&&!p.leaving){world.emit(p.map,{type:'frontierNotice',cate:552,code:100,text:frontierCloseText(world),recipients:[p.id],channel:p.channel??0});if(hideoutNeedsReturn(world,p))p._frontierCloseNotice=true;}
    return result;
  });
  world.saveQueue=task.catch(()=>{});
  try{const result=await task;await maintainGuildHideouts(world);return result;}catch(error){if(error.status===409&&world.getSocialState)await initializeSocial(world);throw error;}
}
/** Scheduled production settlement (SharedWorld.tick): the oldest saved, unsettled period whose close has passed is finalized
 * through finalizeGuildFrontier. One attempt at a time; a failed save leaves the period open and is retried after
 * FRONTIER_CHOSEN.FINALIZE_RETRY_MS; an overdue backlog (host was down at maintenance) settles oldest first. Periods nobody
 * donated in never get a ledger row and need no settlement. Returns the running attempt (tests await it) or null. */
export function tickGuildFrontier(world){
  if(!world.socialState||!world.saveSocialTransaction)return null;
  const job=world.frontierFinalizer||={busy:false,nextAt:0,failures:0,lastError:null,settled:[]},now=world.now();
  if(job.busy||now<job.nextAt)return null;
  job.nextAt=now+FRONTIER_CHOSEN.FINALIZE_POLL_MS;
  let due=null;
  try{for(const row of Object.values(periods(world.socialState))){const d=frontierPeriodDescriptor(row);if(row.closedAt===undefined&&d.closesAt<=now&&(!due||d.closesAt<due.closesAt))due=d;}}
  catch(error){job.lastError=String(error?.message||error);return null;}   // an invalid ledger is never "repaired" by the scheduler
  if(!due){
    const invalid=[...world.players?.values?.()||[]].some(p=>hideoutNeedsReturn(world,p));if(!invalid)return null;
    job.busy=true;job.attempt=maintainGuildHideouts(world).then(()=>null).finally(()=>{job.busy=false;});return job.attempt;
  }
  job.busy=true;
  const attempt=finalizeGuildFrontier(world,due).then(result=>{
    job.failures=0;job.lastError=null;job.nextAt=0;job.settled=[...job.settled.slice(-15),due.id];return result;
  },error=>{
    job.failures++;job.lastError=String(error?.message||error);job.nextAt=world.now()+FRONTIER_CHOSEN.FINALIZE_RETRY_MS;return null;
  }).finally(()=>{job.busy=false;});
  job.attempt=attempt;return attempt;
}

/** True while a completed donation period still awaits its durable settlement. */
export function frontierSettlementPending(world){
 try{return Object.values(periods(socialState(world))).some(r=>r.closedAt===undefined&&frontierPeriodDescriptor(r).closesAt<=world.now());}catch{return true;}
}

const frontierCloseText=world=>String(world.data.dungeonData?.dg?.maps?.[552]?.messages?.[100]?.t||world.data.dungeonCatalog?.maps?.[552]?.messages?.[100]?.t||'Guild hideout will close shortly to reflect the ranking change.').replace(/^\s*\[message\]\s*/i,'');
function hideoutNeedsReturn(world,p){return !!p&&!p.leaving&&!p.instanceId&&p.map>=552&&p.map<=561&&!frontierSettlementPending(world)&&guildFrontierAccess(world,p).award?.dungeonGrade!==p.map-551;}
/** Settlement revokes an expired hideout grant. Travel saves first, retries on failure and rechecks queued actor identity. */
export async function maintainGuildHideouts(world){
  if(!world.players||typeof world.serializeAccount!=='function')return;
  const {commitFieldTravel,travelLocation}=await import('./travel.mjs');
  for(const p of world.players.values()){
    if(!hideoutNeedsReturn(world,p)||p._frontierReturning)continue;
    p._frontierReturning=true;
    try{await world.serializeAccount(p.account,async()=>{
      if(world.players.get(p.account)!==p||!hideoutNeedsReturn(world,p)||p.sceneTransition||p.progressCommitting||p.commandActive||p.tradeId||p.charTradeId)return;
      const at=travelLocation(world,11739);if(!at||at.map!==150)return;
      if(!p._frontierCloseNotice){world.emit(p.map,{type:'frontierNotice',cate:552,code:100,text:frontierCloseText(world),recipients:[p.id],channel:p.channel??0});p._frontierCloseNotice=true;}
      await commitFieldTravel(world,p,{...at,channel:0});delete p._frontierCloseNotice;
    });}catch{/* Storage/map failure leaves the actor in place; the next poll retries. */}finally{delete p._frontierReturning;}
  }
}
