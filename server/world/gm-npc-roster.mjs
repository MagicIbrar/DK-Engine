import {WorldError} from './core.mjs';
const integer=v=>Number.isSafeInteger(v)&&v>=0;
const states=new Set(['working','visible','materialized','departing','queued','parked','blocked','disabled','unmaterialized-record']);
const liveStates=new Set(['working','visible','materialized','departing']);
const reasons=new Set(['native-level','native-admission-unavailable','eligibility-unavailable','unsupported-map','private-instance','dk-channel','event-map','siege-map','unavailable-map','retry-pending','protected-map','route-unavailable','store-unavailable','worker-budget']);
const safeMap=m=>({map:m.map,count:m.count,...(integer(m.materialized)?{materialized:m.materialized}:{})});
// ENGINE-CHOSEN read-only simulated bot directory. It grants no lease, party,
// inventory, movement or GM target for an inactive identity.
export async function npcRosterGM(world,user,input){
 if(!user?.capabilities?.includes('gm:commands'))throw new WorldError(403,'This account does not have GM permission.');
 if(!input||Object.keys(input).some(k=>!['token','operation','map','offset','limit'].includes(k))||input.operation!=='npcRoster')throw new WorldError(400,'Unexpected bot roster fields.');
 const offset=input.offset??0,limit=input.limit??50,map=input.map;
 if(!Number.isSafeInteger(offset)||offset<0||offset>4096||!Number.isSafeInteger(limit)||limit<1||limit>100||map!==undefined&&(!Number.isSafeInteger(map)||map<0))throw new WorldError(400,'Choose a valid bot roster page and map.');
 const p=world.lease(user.id,input.token),now=world.now();if(now-(p.gmRateAt||0)>=1000){p.gmRateAt=now;p.gmActions=0;}if((p.gmActions=(p.gmActions||0)+1)>20)throw new WorldError(429,'Too many GM commands.');
 const empty={enabled:false,total:0,offset,limit,rows:[],maps:[],summary:{total:0,connectionCounts:false}};
 if(typeof world.npcRosterPage!=='function')return empty;
 const result=await world.npcRosterPage({map,offset,limit});
 if(!result?.enabled)return empty;
 // Explicit public projection: metadata storage may contain binding account
 // IDs; those must never become a public row or selected live player target.
 // npcRosterPage is the trusted canonical directory projection. It already
 // validates exact account/cid/actor ownership. Re-resolving by display name
 // here previously manufactured activity and erased queued/worker states.
 const rows=(result.rows||[]).filter(r=>/^r[a-f0-9]{24}$/.test(r.npcRosterId||r.rosterId)).slice(0,limit).map(r=>{
  const status=states.has(r.status)?r.status:'unmaterialized-record',live=liveStates.has(status),bound=r.bound===true,planned=typeof r.activity==='string'?r.activity.slice(0,80):String(r.activity?.kind||'rest').slice(0,80);
  return {rosterId:r.npcRosterId||r.rosterId,name:String(r.name||'').slice(0,24),map:integer(r.map)?r.map:null,classIndex:integer(r.classIndex)?r.classIndex:null,level:integer(r.level)?r.level:null,bound,levelSource:bound?'actual saved character':'native starting level',activity:planned,activitySource:bound?'saved intention; no offline progress':'planned intention; no earned progress',status,...(live&&integer(r.activeMap)?{activeMap:r.activeMap}:{}),...(live&&integer(r.activeLevel)?{activeLevel:r.activeLevel}:{}),...(status==='blocked'&&reasons.has(r.blockedReason)?{blockedReason:r.blockedReason}:{})};
 });
 const source=result.summary||{},summary={connectionCounts:false};
 for(const key of ['total','identities','canonicalCharacters','materializedCharacters','remoteWorkers','visibleCharacters','active','bound','unbound'])if(integer(source[key]))summary[key]=source[key];
 if(typeof source.actorsEnabled==='boolean')summary.actorsEnabled=source.actorsEnabled;
 const counts={};for(const key of states)if(key!=='unmaterialized-record'&&integer(source.counts?.[key]))counts[key]=source.counts[key];
 if(Object.keys(counts).length)summary.counts=counts;
 const maps=(Array.isArray(result.maps)?result.maps:[]).filter(m=>integer(m.map)&&integer(m.count)).slice(0,4096).map(safeMap);
 if(Array.isArray(source.maps))summary.maps=source.maps.filter(m=>integer(m.map)&&integer(m.count)).slice(0,4096).map(safeMap);
 return {enabled:true,simulationDirectoryEnabled:result.simulationDirectoryEnabled===true,actorsEnabled:result.actorsEnabled!==false,total:integer(result.total)?result.total:0,offset,limit,rows,maps,summary,serverTime:now};
}
