// Wanted status of a player (FIELD-PK): the chaotic value of profile.life.grade, the same record the offline Grade system keeps
// (src/systems/life/grade.js: chaotic / pk / pkWindow) with the original bands (life.json pk = share/pc/{chaotic,pkcount,pklevelcap}.csv).
// Light module (no world imports) so name plates and the PK mode can both read it.
import {FIELD_PK} from '../../src/config/engine-chosen-pk.js';
import {chaoticDecayPerSec} from '../../src/game/chaotic-decay.js';

const num=v=>Number.isFinite(Number(v))?Number(v):0;
const stateOf=p=>{const life=p.profile.life||={};return life.grade||={totalExp:0,rowKey:null,claimed:{},chaotic:0,pk:0,pkWindow:[],titleIndex:0};};
const bandOf=(world,value)=>(world.data?.pkData?.chaotic||[]).find(r=>value>=r.start&&value<=r.end)||null;
// A player object belongs to one online session. Persisted chaoticAt must never charge disconnected time on reconnect.
// Each observation records the map the session stood on; the interval up to the next observation decays at that map's rate.
const onlineAt=new WeakMap();
const observe=(world,p,at)=>onlineAt.set(p,{at,map:p.map});
/** Passive decay while logged in, at the native per-map rate (share/maplist.csv wChaoticDecrease per dwChaoticDecreasePeriod,
 * src/game/chaotic-decay.js). pklevelcap.csv signed level bands concern level differences; they are not an absolute
 * character-level multiplier for this passive decay. */
export function chaoticValue(world,p){
  const g=p.profile.life?.grade;if(!g||!(num(g.chaotic)>0)){observe(world,p,world.now());return 0;}   // never created = nothing to fade
  const now=world.now();
  const previous=onlineAt.get(p);observe(world,p,now);
  if(previous==null){g.chaoticAt=now;return num(g.chaotic);}
  const rate=chaoticDecayPerSec(world.data?.mapRow?.(previous.map),0);
  g.chaotic=Math.max(0,num(g.chaotic)-rate*Math.max(0,now-previous.at)/1000);g.chaoticAt=now;
  return g.chaotic;
}
/** Native forced respawn of a chaotic band: share/pc/chaotic.csv wRespawnIndex (15 for values 501+) is a share/arrange/location.csv
 * row (15 = "Prison in Braiken Castle", map 16 at 256,203). Returns that location index or null. The field revival transaction
 * resolves that original location before the normal or premium return point. */
export function forcedRespawnLocation(world,p){const v=chaoticValue(world,p);if(!(v>0))return null;const index=Number(bandOf(world,Math.floor(v))?.respawn);return Number.isInteger(index)&&index>0?index:null;}
/** Battle (combat) status, official Global guide 62: 60 s from the last unlawful forced field hit (field-pk.mjs noteForcedHit
 * records it through noteBattleStatus). Runtime host state; a duel is never battle status. Guide 62 also forbids "move the character
 * selection window" during it, so the start is kept per character in host memory and a reconnect of the same character inside the
 * 60 s keeps the status (it is not written to the save). */
export function noteBattleStatus(world,p,at=world.now()){
  p.pkBattleAt=at;if(p.characterId==null)return;
  const kept=world.pkBattleByCharacter||=new Map();kept.set(String(p.characterId),at);
  if(kept.size>4096)for(const [key,value]of kept)if(!(world.now()-value>=0&&world.now()-value<=FIELD_PK.battleStatusMs))kept.delete(key);
}
export function pkBattleStartedAt(world,p){
  if(!p)return null;
  const kept=p.characterId!=null?world.pkBattleByCharacter?.get?.(String(p.characterId)):undefined;
  if(Number.isFinite(kept)&&!(Number(p.pkBattleAt)>=kept))p.pkBattleAt=kept;   // a reconnected actor resumes the kept status
  return p.pkBattleAt??null;
}
export function pkBattleActive(world,p){
  if(!p||p.duelId)return false;
  const at=pkBattleStartedAt(world,p);if(at==null)return false;
  const age=world.now()-at;return age>=0&&age<=FIELD_PK.battleStatusMs;
}
/** 0 normal, 1 wanted (purple), 2 wanted in a band that forces a respawn (red). */
export function wantedLevel(world,p){const v=chaoticValue(world,p);return !(v>0)?0:bandOf(world,Math.floor(v))?.respawn>0?2:1;}
/** A PK kill: the pkcount row of "kills in the last hour" is added to the chaotic value (the maths of the offline Grade.addPk). */
export function addChaos(world,killer){
  const st=stateOf(killer),before=wantedLevel(world,killer),now=world.now(),table=world.data?.pkData?.pkcount||[];
  st.pk=num(st.pk)+1;st.pkWindow=[...(st.pkWindow||[]).filter(t=>now-t<3600e3),now];
  const n=st.pkWindow.length,row=table.find(r=>n>=r.start&&n<=r.end)||table[table.length-1];
  if(row)st.chaotic=num(st.chaotic)+num(row.chaotic);
  st.chaoticAt=now;
  observe(world,killer,now);
  return {before,after:wantedLevel(world,killer)};
}

/** Global NormalDeadPC 0x5df1b0 / Decrease.cpp 0x845d60: when a chaotic character dies,
 * chaotic -= pkcount.csv col4 for the current kills-in-last-hour count, floored at 0.
 * MATH-VERIFY row 14. build-life maps col4 as `level` (and optionally `decrease`). */
export function chaoticDeath(world,p){
  const beforeWanted=wantedLevel(world,p);
  const current=chaoticValue(world,p);
  if(!(current>0))return {before:beforeWanted,after:beforeWanted,decreased:0};
  const st=stateOf(p),now=world.now(),table=world.data?.pkData?.pkcount||[];
  const n=(st.pkWindow||[]).filter(t=>now-t<3600e3).length;
  const row=table.find(r=>n>=r.start&&n<=r.end)||table[table.length-1];
  const amount=row?num(row.decrease??row.level):0;
  st.chaotic=Math.max(0,num(st.chaotic)-amount);
  st.chaoticAt=now;
  observe(world,p,now);
  return {before:beforeWanted,after:wantedLevel(world,p),decreased:amount};
}

/** Field Safe Time (NonPK): formula.ini dwNonPKTime (30000) + stringtable_pc 1003:10
 * "cannot attack or be attacked for 30 seconds." Granted to a field-PK death victim on revive
 * (field-pk marks pkSafePending; field-respawn calls noteSafeTime). Mode controllers (siege/arena/urban) call grantModeSafeTime on player revive. Runtime host state, kept per
 * character across reconnect like battle status. Mode-specific durations (siege/arena/urban) are
 * available on world.data.pvpRules when those controllers grant Safe Time. */
export function noteSafeTime(world,p,durationMs,at=world.now()){
  const ms=Number(durationMs); if(!p||!(ms>0))return null;
  const until=at+ms; p.pkSafeUntil=until;
  if(p.characterId!=null){ const kept=world.pkSafeByCharacter||=new Map(); kept.set(String(p.characterId),until);
    if(kept.size>4096){ const now=world.now(); for(const [key,value] of kept) if(!(value>now)) kept.delete(key); }
  }
  return until;
}
export function pkSafeUntilOf(world,p){
  if(!p)return null;
  // Map is authoritative across reconnect/clear (same pattern as battle status keep + explicit clear).
  if(p.characterId!=null&&world.pkSafeByCharacter){
    const kept=world.pkSafeByCharacter.get(String(p.characterId));
    if(Number.isFinite(kept)){ if(!(Number(p.pkSafeUntil)>=kept))p.pkSafeUntil=kept; return kept; }
    delete p.pkSafeUntil; return null;
  }
  return Number.isFinite(p.pkSafeUntil)?p.pkSafeUntil:null;
}
export function pkSafeTimeActive(world,p){
  if(!p||p.duelId)return false;
  const until=pkSafeUntilOf(world,p); if(until==null)return false;
  return world.now()<until;
}
/** Mode NonPK after revive (formula.ini dwSeige/Arena/UrbanWarfareNonPKTime).
 * Client notice uses stringtable_pc 1003:11 (no hard-coded 30s — that text is field-only 1003:10).
 * Duel is exempt at isPvpTarget; field-pk pkRefusal already blocks Safe Time pairs. */
export function grantModeSafeTime(world,p,kind='field'){
  const rules=world.data?.pvpRules||{};
  const ms=Number(kind==='siege'?rules.siegeNonPkTimeMs:kind==='arena'?rules.arenaNonPkTimeMs:kind==='urban'?rules.urbanWarfareNonPkTimeMs:rules.nonPkTimeMs)||0;
  if(!(ms>0)||!p)return false;
  noteSafeTime(world,p,ms);
  world.emit(p.map,{type:'pk',reason:'safetime-mode',actorId:p.id,targetId:p.id,recipients:[p.id]});
  return true;
}
export function clearSafeTime(world,p){
  if(!p)return; delete p.pkSafeUntil; delete p.pkSafePending;
  if(p.characterId!=null)world.pkSafeByCharacter?.delete?.(String(p.characterId));
}
