import {npcArchetype,archetypeIdentity,unit,archetypeMix} from './npc-archetypes.mjs';
// ENGINE-CHOSEN connection/decision pacing only. Every resident remains an
// ordinary actual world lease; this helper grants no movement, progress or loot.
const hash=value=>{let n=2166136261;for(const c of String(value||''))n=Math.imul(n^c.charCodeAt(0),16777619)>>>0;return n;};
export const NPC_RESIDENT_POLICY=Object.freeze({joinSpacingMs:250,lingerMs:120000,startupMinMs:250,startupSpanMs:1750});
export function createNpcResidentSchedule(now,options={}){
 const policy={...NPC_RESIDENT_POLICY,...options},absent=new Map(),scenes=new Map();let nextJoin=0;
 return {
  ready(scene){return now()>=nextJoin&&now()>=(scenes.get(scene)||0);},
  joined(scene){nextJoin=now()+Math.max(0,policy.joinSpacingMs);scenes.set(scene,nextJoin);},
  retirement(account,{present=false,protected:protectedActor=false}={}){
   if(present||protectedActor){absent.delete(account);return false;}
   if(!absent.has(account))absent.set(account,now());
   return now()-absent.get(account)>=Math.max(0,policy.lingerMs);
  },
  startup(profile,{saved=true}={}){
   const delay=policy.startupMinMs+hash(profile.id)%Math.max(1,policy.startupSpanMs);
   // Stagger ordinary autonomous work; direct human requests can be scheduled
   // separately by the director. Preserve the saved profile and actual position.
   return {next:now()+delay,learnAt:now()+delay+(saved?5000:0),questAt:now()+delay,serviceAt:now()+delay+5000};
  },
  forget(account){absent.delete(account);},clear(){absent.clear();scenes.clear();nextJoin=0;},
 };
}
// ENGINE-CHOSEN login/logout cycles (opt-in: NPC_ARCHETYPE_MIX.sessions.enabled or
// DEKARON_NPC_SESSIONS=1). Deterministic per profile and local day; derived, never
// persisted. A session decides only WHICH saved bots are eligible to be admitted or
// should leave through the ordinary leave path when idle. It never forces a leave
// during combat, trade, party, quest commit or any protected custody.
const DAY=86400000,MIN=60000;
export function npcSessionsEnabled(env=globalThis.process?.env||{}){const v=env.DEKARON_NPC_SESSIONS;return v==null?archetypeMix().mix.sessions?.enabled===true:String(v)==='1';}
const localDay=(now,offsetMin)=>Math.floor((now+offsetMin*MIN)/DAY);
function gaussian(u1,u2){return Math.sqrt(-2*Math.log(Math.max(1e-12,u1)))*Math.cos(2*Math.PI*u2);}
/** Sessions that START on local day `day` for this profile: [{start,end}] (ms epoch). */
export function npcDaySessions(profile,day,{offsetMin=-new Date(day*DAY).getTimezoneOffset()}={}){
 const a=npcArchetype(profile);if(!a)return [];const mix=archetypeMix().mix,def=mix.archetypes[a.id],key=archetypeIdentity(profile),c=mix.commitment[a.commitment]||{session:1};
 // Regular/hardcore players sometimes log in twice a day; some casuals skip days.
 const count=a.commitment==='casual'?(unit('skip',key,day)<0.35?0:1):a.commitment==='hardcore'?2:(unit('twice',key,day)<0.3?2:1),out=[];
 for(let i=0;i<count;i++){
  const hours=def.session.hours,hour=hours[Math.floor(unit('hour',key,day,i)*hours.length)],start=day*DAY-offsetMin*MIN+hour*3600000+Math.floor(unit('minute',key,day,i)*60)*MIN;
  const len=Math.max(10,Math.min(960,def.session.medianMin*c.session*Math.exp(def.session.sigma*gaussian(unit('len',key,day,i),unit('len2',key,day,i)))))*MIN;
  out.push({start,end:start+len});
 }
 out.sort((x,y)=>x.start-y.start);
 // Merge overlaps and enforce a minimum offline gap between sessions.
 const gap=(mix.sessions?.minOfflineMin??20)*MIN,merged=[];for(const s of out){const last=merged.at(-1);if(last&&s.start<last.end+gap)last.end=Math.max(last.end,s.end);else merged.push({...s});}
 return merged;
}
/** {online, end, nextStart} for `now`; considers sessions started yesterday too. */
export function npcSessionState(profile,now,{offsetMin=-new Date(now).getTimezoneOffset()}={}){
 const day=localDay(now,offsetMin),sessions=[...npcDaySessions(profile,day-1,{offsetMin}),...npcDaySessions(profile,day,{offsetMin}),...npcDaySessions(profile,day+1,{offsetMin})];
 const current=sessions.find(s=>now>=s.start&&now<s.end),next=sessions.find(s=>s.start>now);
 return {online:!!current,end:current?.end??null,nextStart:next?.start??null};
}
// Cached boolean form: recomputed only when the cached session window boundary passes.
const onlineCache=new WeakMap();
export function npcSessionOnline(profile,now){
 if(!profile||typeof profile!=='object')return true;const hit=onlineCache.get(profile);if(hit&&now>=hit.from&&now<hit.until)return hit.online;
 const s=npcSessionState(profile,now),until=Math.min(s.online?s.end:s.nextStart??now+3600000,now+3600000);onlineCache.set(profile,{from:now,until,online:s.online});return s.online;
}
