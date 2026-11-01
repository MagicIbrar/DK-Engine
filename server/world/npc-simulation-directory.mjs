// ENGINE-CHOSEN read-only census. A pending queue is supplied by the scheduler;
// eligibility alone never means an actor/session is running or earning rewards.
import {createHash} from 'node:crypto';

const states=['working','visible','materialized','departing','queued','parked','blocked','disabled'];
const reasons=new Set(['native-level','native-admission-unavailable','eligibility-unavailable','unsupported-map','private-instance','dk-channel','event-map','siege-map','unavailable-map','retry-pending','protected-map','route-unavailable','store-unavailable','worker-budget']);
const integer=v=>Number.isSafeInteger(v)&&v>=0;
const text=(v,n=80)=>typeof v==='string'?v.slice(0,n):'';
const resolve=v=>typeof v==='function'?v():v;
const canonical=(account,p)=>/^npc_[a-f0-9]{32}$/.test(account)&&p?.authority==='server'&&p.npcPlayer===true&&typeof p.id==='string'&&p.id.length>0;
const rosterId=(account,p)=>/^r[a-f0-9]{24}$/.test(p.npcRosterId||p.npcSeed?.rosterId)?p.npcRosterId||p.npcSeed.rosterId:'r'+createHash('sha256').update('earned:'+account+':'+p.id).digest('hex').slice(0,24);
const activity=p=>{const kind=p?.npcRoutine?.kind||p?.npcSeed?.initialGoal?.kind;return ['quest','farm','merchant','rest','afk','event','dungeon'].includes(kind)?kind:'rest';};
const publicRecord=r=>({npcRosterId:r.rosterId,name:text(r.profile.name,24),map:integer(r.profile.map)?r.profile.map:null,level:integer(r.profile.level)?r.profile.level:null,classIndex:integer(r.profile.classIndex)?r.profile.classIndex:null,activity:activity(r.profile),status:r.state,bound:true,levelSource:'actual saved character',...(r.reason?{blockedReason:r.reason}:{}),...(r.actor?{activeMap:integer(r.actor.map)?r.actor.map:null,activeLevel:integer(r.actor.profile.level)?r.actor.profile.level:null}:{} )});

/** No geometry, persistence, actions, timers or offline accounting. Exact actor
 * IDs are INTERNAL inputs. Only allowlisted public character metadata leaves.
 * eligibility is the same native predicate used by the real scheduler. queuedIds
 * must be that scheduler's pending canonical profile IDs, not a cosmetic count. */
export function createNpcSimulationDirectory({profiles,actors=new Map(),workerIds=new Set(),visibleIds=new Set(),queuedIds=new Set(),enabled=()=>false,eligibility=()=>false}={}){
 if(!(resolve(profiles) instanceof Map))throw Error('Simulation directory requires canonical profiles.');
 function census(){
  const saved=resolve(profiles),live=resolve(actors),workers=resolve(workerIds),visible=resolve(visibleIds),queued=resolve(queuedIds),on=!!resolve(enabled);
  const rows=[],byRoster=new Map(),counts=Object.fromEntries(states.map(s=>[s,0])),maps=new Map();
  for(const[account,p]of saved){
   if(!canonical(account,p))continue;
   const candidate=live instanceof Map?live.get(account):null;
   // A stale name, actor ID or cached profile cannot establish ownership.
   const actor=candidate?.account===account&&candidate.characterId===p.id&&candidate.profile?.id===p.id&&candidate.id===`${account}:${p.id}`&&canonical(account,candidate.profile)?candidate:null;
   let state,reason;
   if(actor)state=actor.leaving?'departing':visible?.has(actor.id)?'visible':workers?.has(actor.id)?'working':'materialized';
   else if(!on)state='disabled';
   else {
    let result;try{result=eligibility(p,{account});}catch{result={eligible:false,reason:'eligibility-unavailable'};}
    if(!(result===true||result?.eligible===true)){state='blocked';reason=reasons.has(result?.reason)?result.reason:'native-admission-unavailable';}
    else state=queued?.has(p.id)?'queued':'parked';
   }
   const row={rosterId:rosterId(account,p),profile:p,actor,state,reason};rows.push(row);byRoster.set(row.rosterId,row);counts[state]++;
   const map=actor?.map??p.map;if(integer(map)){const c=maps.get(map)||{map,count:0,materialized:0};c.count++;if(actor)c.materialized++;maps.set(map,c);}
  }
  const materialized=counts.working+counts.visible+counts.materialized+counts.departing;
  const summary={kind:'canonical saved simulation characters',total:rows.length,canonicalCharacters:rows.length,materializedCharacters:materialized,active:materialized,remoteWorkers:counts.working,visibleCharacters:counts.visible,actorsEnabled:on,connectionCounts:false,counts,maps:[...maps.values()].sort((a,b)=>a.map-b.map)};
  return {rows,byRoster,summary};
 }
 return {
  snapshot(){return census().summary;},
  // Decorates a bounded existing directory page. Metadata-only rows are distinct
  // from canonical characters and never enter the canonical census.
  page(page={}){
   const {byRoster,summary}=census(),limit=integer(page.limit)?Math.min(page.limit,100):100;
   const rows=(Array.isArray(page.rows)?page.rows:[]).slice(0,limit).map(r=>{
    const value=r.npcRosterId||r.rosterId,id=/^r[a-f0-9]{24}$/.test(value)?value:null,matched=byRoster.get(id);if(matched)return publicRecord(matched);
    return {npcRosterId:id,name:text(r.name,24),map:integer(r.map)?r.map:null,level:integer(r.level)?r.level:integer(r.startingLevel)?r.startingLevel:null,classIndex:integer(r.classIndex)?r.classIndex:null,activity:typeof r.activity==='string'?text(r.activity,30):text(r.activity?.kind,30),status:'unmaterialized-record',bound:false,levelSource:'starting record'};
   });
   return {enabled:true,simulationDirectoryEnabled:true,actorsEnabled:summary.actorsEnabled,total:integer(page.total)?page.total:rows.length,offset:integer(page.offset)?page.offset:0,limit,rows,maps:summary.maps,summary};
  }
 };
}
