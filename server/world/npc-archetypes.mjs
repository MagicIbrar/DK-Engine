// ENGINE-CHOSEN player archetypes for server-owned bots. Pure, deterministic and
// cheap: an archetype is DERIVED from the saved profile (persona traits, level and a
// stable identity hash), so existing profiles are never migrated, rewritten or wiped.
// It only weights choices among existing routines/duties and paces idle decisions.
import {NPC_ARCHETYPE_MIX} from './npc-archetype-mix.mjs';

const SOCIALS=['social','solo','outlaw'],BANDS=['lt40','lt100','lt150','cap'];
// Prior of the (social, level band) cells used to balance assignment so the
// population marginal equals the configured share. social is ~uniform by
// construction in npcPopulationChoice; the band prior was measured on the
// prepared 1250-profile roster (311/78/495/366). A different roster only shifts
// the realized mix; tests report the realized deviation.
const BAND_PRIOR={lt40:0.249,lt100:0.062,lt150:0.396,cap:0.293};

export const hash32=value=>{let h=2166136261;const s=String(value);for(let i=0;i<s.length;i++){h^=s.charCodeAt(i);h=Math.imul(h,16777619);}h^=h>>>15;h=Math.imul(h,2246822507);h^=h>>>13;return h>>>0;};
export const unit=(...parts)=>(hash32(parts.join('|'))+0.5)/4294967296;
const bandOf=level=>{const l=Number(level)||1;return l<40?'lt40':l<100?'lt100':l<150?'lt150':'cap';};

export function archetypesEnabled(env=globalThis.process?.env||{}){return String(env.DEKARON_NPC_ARCHETYPES??'1')!=='0';}

function normalize(weights){const total=Object.values(weights).reduce((n,v)=>n+Math.max(0,Number(v)||0),0);const out={};for(const [k,v]of Object.entries(weights))out[k]=total>0?Math.max(0,Number(v)||0)/total:0;return out;}

/** Conditional tables P(archetype | social, band), balanced (Sinkhorn/IPF) so the
 * marginal under the cell prior equals the configured shares. Computed once per mix. */
export function compileArchetypeMix(mix=NPC_ARCHETYPE_MIX,{bandPrior=BAND_PRIOR,iterations=200}={}){
 const ids=Object.keys(mix.archetypes),target=normalize(Object.fromEntries(ids.map(id=>[id,mix.archetypes[id].share])));
 const cells=[];for(const s of SOCIALS)for(const b of BANDS)cells.push({social:s,band:b,prior:(1/SOCIALS.length)*(bandPrior[b]??0.25)});
 const base=cells.map(c=>ids.map(id=>{const a=mix.archetypes[id].affinity||{};return Math.max(1e-6,(a[c.social]??1)*(a[c.band]??1));}));
 const col=ids.map(()=>1);let rows=[];
 for(let it=0;it<iterations;it++){
  rows=base.map(r=>{const w=r.map((v,j)=>v*col[j]),t=w.reduce((n,v)=>n+v,0);return w.map(v=>v/t);});
  ids.forEach((id,j)=>{const m=cells.reduce((n,c,i)=>n+c.prior*rows[i][j],0);if(m>0)col[j]*=target[id]/m;});
 }
 const table={};cells.forEach((c,i)=>{table[c.social+'/'+c.band]=ids.map((id,j)=>[id,rows[i][j]]);});
 const commitment=Object.entries(normalize(Object.fromEntries(Object.entries(mix.commitment).map(([k,v])=>[k,v.share]))));
 return {mix,ids,target,table,commitment};
}
let compiled=compileArchetypeMix();
/** Tests/bench may install a different mix; production uses the data file. */
export function setArchetypeMix(mix){compiled=compileArchetypeMix(mix);cache=new WeakMap();return compiled;}
export function archetypeMix(){return compiled;}

const pick=(pairs,u)=>{let acc=0;for(const [k,w]of pairs){acc+=w;if(u<acc)return k;}return pairs.at(-1)[0];};
/** Stable identity: roster id, then profile id, then name/class/slot (legacy). */
export function archetypeIdentity(profile={}){return String(profile.npcRosterId||profile.id||JSON.stringify([profile.name||'',profile.classIndex??null,profile.npcSeed?.slot??null]));}

let cache=new WeakMap();
/** Deterministic archetype for a saved bot profile. Never mutates the profile. */
export function npcArchetype(profile){
 if(!profile||typeof profile!=='object')return null;
 const traits=profile.npcTraits||{},key=archetypeIdentity(profile),level=Number(profile.level)||1,band=bandOf(level);
 const memo=cache.get(profile);if(memo&&memo.key===key&&memo.band===band&&memo.social===traits.social&&memo.mix===compiled)return memo.value;
 const social=SOCIALS.includes(traits.social)?traits.social:'social';
 const id=pick(compiled.table[social+'/'+band],unit('archetype',key));
 const commitment=pick(compiled.commitment,unit('commitment',key));
 const def=compiled.mix.archetypes[id],skill=['novice','regular','expert','elite'].includes(traits.pvpSkill)?traits.pvpSkill:'regular';
 const thinkMedian=def.think.medianMs*(compiled.mix.commitment[commitment]?.think??1)*(compiled.mix.skill[skill]??1);
 // Per-bot fixed pace factor (individual differences within an archetype).
 const pace=Math.exp(def.think.sigma*0.5*gauss(unit('pace',key),unit('pace2',key)));
 const value=Object.freeze({policy:'ENGINE-CHOSEN',id,label:def.label,commitment,skill,thinkMedianMs:Math.round(thinkMedian*pace),thinkSigma:def.think.sigma,risk:def.risk,tasks:def.tasks,town:def.town,source:profile.npcRosterId?'roster-id':profile.id?'profile-id':'legacy-signature'});
 cache.set(profile,{key,band,social:traits.social,mix:compiled,value});return value;
}
function gauss(u1,u2){return Math.sqrt(-2*Math.log(Math.max(1e-12,u1)))*Math.cos(2*Math.PI*u2);}
/** Lognormal idle-decision interval (reaction/think time) for draw `n`. Deterministic. */
export function npcArchetypeThinkMs(profile,n=0,{active=false}={}){
 const a=npcArchetype(profile);if(!a)return null;const key=archetypeIdentity(profile),[lo,hi]=compiled.mix.thinkClampMs;
 const median=active?Math.min(a.thinkMedianMs,compiled.mix.activeThinkMedianCapMs??a.thinkMedianMs):a.thinkMedianMs;
 const v=median*Math.exp(a.thinkSigma*gauss(unit('think',key,n),unit('think2',key,n)));
 return Math.round(Math.max(lo,Math.min(hi,v)));
}
/** Weighted routine kind among the existing kinds for a routine cycle. */
export function npcArchetypeTask(profile,cycle,{allowed=['quest','farm','merchant','rest']}={}){
 const a=npcArchetype(profile);if(!a)return null;
 const pairs=Object.entries(normalize(Object.fromEntries(allowed.map(k=>[k,a.tasks[k]||0])))).filter(([,w])=>w>0);if(!pairs.length)return allowed[0]??null;
 return pick(pairs,unit('task',archetypeIdentity(profile),cycle));
}
/** Elected rest length (ms) for a routine cycle; AFK/idlers rest much longer. */
export function npcArchetypeRestMs(profile,cycle){
 const a=npcArchetype(profile);if(!a)return null;const [lo,hi]=compiled.mix.archetypes[a.id].restMs;
 return Math.round(lo+(hi-lo)*unit('rest',archetypeIdentity(profile),cycle));
}
/** Ordered city duty preferences for a duty epoch (first = preferred). */
export function npcArchetypeTownPreference(profile,epoch=0){
 const a=npcArchetype(profile);if(!a)return null;const w=normalize(a.town),key=archetypeIdentity(profile);
 const first=pick(Object.entries(w).filter(([,v])=>v>0),unit('town',key,epoch));
 const rest=Object.entries(w).filter(([k])=>k!==first).sort((x,y)=>y[1]-x[1]).map(([k])=>k);
 return [first,...rest];
}
export function npcArchetypeDutyDwellMs(profile,duty,epoch=0){
 const d=compiled.mix.city.dwellMs[duty];if(d==null)return 120000;if(!Array.isArray(d))return d;
 return Math.round(d[0]+(d[1]-d[0])*unit('dwell',archetypeIdentity(profile),duty,epoch));
}
/** Activity category used by realism metrics (pure classification of brain state). */
export function npcActivityCategory(activity='',{duty,task,pcShopOpen,sitting,partyId}={}){
 const a=String(activity||'');
 if(pcShopOpen||/shop|stall|selling|market|restock|drops to market|trade/i.test(a))return 'trading';
 if(/fishing/i.test(a))return 'lifeskill';
 if(/fight|enemy|combat|skill|pull|threat|recovery potion|preparing for the fight|approaching/i.test(a))return /another player|guild/i.test(a)?'pvp':'combat';
 if(/quest/i.test(a))return 'questing';
 if(/party|team|follow|group|crew|DK Square|event|dungeon|revive/i.test(a)||partyId)return 'party';
 if(/heading|travel|route|channel|walking|returning|leveling area/i.test(a))return 'travel';
 if(/equipment|smith|gear|build|refine|potion|service|town services|drops/i.test(a))return 'errands';
 if(/reply|chat|talk|conversation/i.test(a))return 'social';
 if(/break|waiting|rest|recovering|making room|sit/i.test(a)||sitting)return 'resting';
 if(/looking for an available objective|exploring/i.test(a))return 'searching';
 return 'other';
}
export function shannonBits(counts){const v=Object.values(counts).filter(n=>n>0),t=v.reduce((n,x)=>n+x,0);return t?-v.reduce((n,x)=>n+(x/t)*Math.log2(x/t),0):0;}
/** City duty preference adapter for createNpcCityDutyPlanner (null = legacy quotas). */
export function npcArchetypeCityPreference(now,{enabled=archetypesEnabled()}={}){
 if(!enabled)return null;const city=compiled.mix.city;
 return {now,caps:{quest:city.maxQuest,service:city.maxService},order:(p,epoch)=>npcArchetypeTownPreference(p.profile,epoch),dwell:(p,kind,epoch)=>npcArchetypeDutyDwellMs(p.profile,kind,epoch)};
}
/** Director status summary (called only from the status snapshot, never per tick). */
export function npcArchetypeSummary(rows){
 const byArchetype={},byCommitment={},taskSources={},idleReasons={},categories={};
 for(const {player:p,brain:b,duty,dutyDetail}of rows){
  const a=p?.profile&&npcArchetype(p.profile);if(!a)continue;
  byArchetype[a.id]=(byArchetype[a.id]||0)+1;byCommitment[a.commitment]=(byCommitment[a.commitment]||0)+1;
  if(b.taskSelection?.source)taskSources[b.taskSelection.source]=(taskSources[b.taskSelection.source]||0)+1;
  if(!b.taskGoal){const reason=dutyDetail?`city-${dutyDetail.kind}:${dutyDetail.reason}`:duty?`city-${duty}`:`no-task:${String(b.activity||'unknown').slice(0,48)}`;idleReasons[reason]=(idleReasons[reason]||0)+1;}
  const c=npcActivityCategory(b.activity,{pcShopOpen:p.pcShopOpen,sitting:p.sitting,partyId:p.partyId});categories[c]=(categories[c]||0)+1;
 }
 return {byArchetype,byCommitment,taskSources,idleReasons,categories,entropyBits:+shannonBits(categories).toFixed(3)};
}
/** Lognormal reaction delay (ms) for draw `n`, from the competence tier, archetype and commitment. */
export function npcArchetypeReactionMs(profile,n=0,{tier}={}){
 const a=npcArchetype(profile);if(!a)return null;const r=compiled.mix.reaction;if(!r)return null;const key=archetypeIdentity(profile);
 const t=['novice','regular','expert','elite'].includes(tier)?tier:a.skill,median=(r.medianMs[t]??480)*(r.archetype?.[a.id]??1)*(r.commitment?.[a.commitment]??1);
 const v=median*Math.exp(r.sigma*gauss(unit('react',key,n),unit('react2',key,n)));return Math.round(Math.max(r.clampMs[0],Math.min(r.clampMs[1],v)));
}
/** Damage wake: a bot hit while waiting for its next idle decision reacts after a sampled
 * human-like delay instead of the (possibly long) idle cadence. Never delays a decision. */
export function npcArchetypeReactionWake(p,b,event,now,{enabled=ARCHETYPES_ON,tier}={}){
 if(!enabled||!p?.profile||!b||event?.type!=='damage'||event.targetId!==p.id||!(Number(event.amount)>0)||!(Number(b.next)>now))return false;
 const ms=npcArchetypeReactionMs(p.profile,b.reactDraw=(b.reactDraw||0)+1,{tier});if(ms==null||now+ms>=b.next)return false;b.next=now+ms;return true;
}
const ARCHETYPES_ON=archetypesEnabled();
