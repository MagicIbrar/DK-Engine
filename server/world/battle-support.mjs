import {validateLife,serializeLife,commitLife} from './life-transactions.mjs';
import {staminaState,consumeStamina,MINUTE_MS} from '../../src/systems/hud-options/stamina-rules.js';
import {activePremiums,premiumFields,almightyOf} from '../../src/systems/shops/premium-rules.js';
export const BATTLE_SUPPORT_SCHEMAS={battlesupport:['token','type','operation']};
const sessions=new WeakMap(),pending=new WeakMap();
const fail=message=>{throw Object.assign(new Error(message),{status:400});};
const scene=p=>`${p.map}:${p.instanceId||''}:${p.channel??0}`;
function unlimitedUntil(world,profile){
 const db=world.data.itemDB,dshop=world.data.shopData?.dshop;
 return activePremiums(profile.premium,world.now()).reduce((until,entry)=>{
  if(!premiumFields(dshop,entry.item))return until;
  const text=almightyOf(dshop,entry.item)?db?.descriptions?.[701]:db?.description?.(db?.def?.(entry.item));
  return /unlimited stamina/i.test(text||'')?Math.max(until,entry.until):until;
 },0);
}
function balance(profile,now){const copy=structuredClone(profile);staminaState(copy,now);return copy.stamina;}
function accrue(world,p){
 const s=sessions.get(p);if(!s)return;
 const now=world.now(),day=staminaState(structuredClone(p.profile),now).day;
 let since=s.lastAt;
 if(day!==s.day){s.day=day;s.partialMs=0;s.epoch++;const midnight=new Date(now);midnight.setHours(0,0,0,0);since=Math.max(since,midnight.getTime());}
 if(s.active)s.partialMs+=Math.max(0,now-Math.max(since,s.unlimitedUntil));
 s.lastAt=now;s.unlimitedUntil=unlimitedUntil(world,p.profile);
 if(p.dead||scene(p)!==s.scene)s.active=false;
 if(!s.unlimitedUntil&&Math.floor(s.partialMs/MINUTE_MS)>=balance(p.profile,now))s.active=false;
}
async function settle(world,p){
 accrue(world,p);const session=sessions.get(p),profile=structuredClone(p.profile),state=staminaState(profile,world.now());
 const elapsed=session?.partialMs??state.partialMs,epoch=session?.epoch,cost=Math.floor(elapsed/MINUTE_MS);
 if(cost)consumeStamina(profile,cost,world.now());state.partialMs=profile.stamina>0?elapsed%MINUTE_MS:0;
 if(JSON.stringify(profile)!==JSON.stringify(p.profile))await commitLife(world,p,profile);
 // New ticks may accrue while persistence is pending; subtract the captured charge only.
 if(session&&session.epoch===epoch){session.partialMs=profile.stamina>0?Math.max(0,session.partialMs-cost*MINUTE_MS):0;if(!session.unlimitedUntil&&!(p.profile.stamina>0))session.active=false;}
 return session;
}
export async function battleSupportCommand(world,p,input){
 if(!Object.hasOwn(BATTLE_SUPPORT_SCHEMAS,input.type))return false;
 validateLife(input,BATTLE_SUPPORT_SCHEMAS);if(!['start','stop'].includes(input.operation))fail('Choose Battle Support start or stop.');
 return serializeLife(p,async()=>{
  if(input.operation==='start'&&p.dead)fail('You cannot enable Battle Support while dead.');
  const session=await settle(world,p);
  if(input.operation==='stop'){if(session)session.active=false;world.changed(p);return true;}
  if(!unlimitedUntil(world,p.profile)&&!(p.profile.stamina>0))fail('Stamina has been depleted. You cannot enable auto attack.');
  if(session?.active)return true;
  p.battleSupportError=null;
  sessions.set(p,{active:true,scene:scene(p),day:p.profile.battleSupport.day,partialMs:p.profile.battleSupport.partialMs,lastAt:world.now(),unlimitedUntil:unlimitedUntil(world,p.profile),epoch:0});world.changed(p);return true;
 });
}
export function tickBattleSupport(world,p,dt){
 const session=sessions.get(p);if(!session)return Promise.resolve(false);
 accrue(world,p);
 if(pending.has(p))return pending.get(p);
 const today=staminaState(structuredClone(p.profile),world.now()).day;
 const checkpoint=session.partialMs>=MINUTE_MS||p.profile.battleSupport?.day!==today||!session.active&&session.partialMs!==p.profile.battleSupport?.partialMs;
 if(!checkpoint)return Promise.resolve(false);
 const task=serializeLife(p,()=>settle(world,p)).then(()=>{world.changed(p);return true;}).catch(error=>{session.active=false;p.battleSupportError=error.message;world.changed(p);throw error;}).finally(()=>pending.delete(p));
 pending.set(p,task);return task;
}
// lane-perf: staminaState() normalizes only battleSupport / stamina / staminaMax and unlimitedUntil() reads premium, so the
// per-viewer, per-tick snapshot clones just those fields instead of the whole profile (identical result; reference below,
// tools/lane-perf/test-battle-support-snapshot.mjs).
export function battleSupportSnapshot(world,p){
 const src=p.profile,profile={battleSupport:structuredClone(src.battleSupport),stamina:src.stamina,staminaMax:src.staminaMax,premium:structuredClone(src.premium)};
 const state=staminaState(profile,world.now()),session=sessions.get(p),unlimited=unlimitedUntil(world,profile)>0;
 return {active:!!session?.active&&!p.dead&&scene(p)===session.scene,stamina:profile.stamina,dailyRemaining:state.dailyRemaining,unlimited,day:state.day,error:p.battleSupportError||null};
}
export function battleSupportSnapshotReference(world,p){
 const profile=structuredClone(p.profile),state=staminaState(profile,world.now()),session=sessions.get(p),unlimited=unlimitedUntil(world,profile)>0;
 return {active:!!session?.active&&!p.dead&&scene(p)===session.scene,stamina:profile.stamina,dailyRemaining:state.dailyRemaining,unlimited,day:state.day,error:p.battleSupportError||null};
}
