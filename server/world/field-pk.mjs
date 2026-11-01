import {gameplayPreferences} from '../../src/game/gameplay-preferences.js';
// FIELD-PK: forced attack (Ctrl, keymap 302 "Force Attack") on other players of open PvP fields.
// Original pieces: maplist IsPvP 1 + PVP_PeaceZone 0 (the same test as the guild war: siege-rules isPvpField), PeaceZone / PVP_PeaceZone
// maps are Safety Zones (1003:8), IsNotIncreaseChao maps never add chaotic, share/pc/{chaotic,pkcount,pklevelcap}.csv (life.json pk) give
// the wanted status: a PK kill adds the pkcount row of "kills in the last hour" to the killer's chaotic value (the same maths as the
// offline Grade.addPk), the value fades with time, a value above 0 colours the name purple, the bands that force a respawn colour it red.
// Messages are stringtable_pc cate 1003 (src/config/engine-chosen-pk.js PK_TEXT). Battle status lasts the official 60 s (guide 62,
// FIELD_PK.battleStatusMs) and the chaotic value fades at the map's native rate (wanted.mjs). ENGINE-CHOSEN: how long a forced action stays armed,
// the notice repeat, the wanted colours, "no chaos for killing a wanted player" (FIELD_PK). The damage is the PvP pipeline of
// server/world/pvp.mjs (src/game/pvp-rules.js, shield first); this file only decides WHO may be hit and what a kill costs.
import {registerPvpMode,noteForcedIntent} from './pvp.mjs';
import {sameScene} from './scene.mjs';
import {isObserver} from './observers.mjs';
import {socialRef} from './social-state.mjs';
import {guildWarEnemy} from './guild-war-pvp.mjs';
import {wantedLevel,addChaos,pkBattleActive,noteBattleStatus} from './wanted.mjs';
import {isPvpField} from '../../src/game/siege-rules.js';
import {FIELD_PK,PK_TEXT} from '../../src/config/engine-chosen-pk.js';

const num=v=>Number.isFinite(Number(v))?Number(v):0;
const up=(world,q,allowDowned=false)=>!!q&&world.players.get(q.account)===q&&!q.leaving&&(allowDowned||!q.dead)&&!q.sceneTransition&&!(q.gmAuthorized&&q.profile.gm?.hide);

export {noteForcedIntent};   // a forced attack / skill command arms p (pvp.mjs, shared with skills.mjs)
const armed=(world,p)=>p.pkForcedAt!=null&&world.now()-p.pkForcedAt<=FIELD_PK.forcedWindowMs;

/** Is this server and this place a PK field for p? null = yes, else 'off' | 'safe' | 'instance'. */
export function pkPlace(world,p){
  if(world.fieldPkEnabled?.()===false)return 'off';
  if(p.instanceId)return 'instance';
  const row=world.data?.mapRow?.(p.map);
  return isPvpField(row)?null:'safe';
}
const guildOf=(world,p)=>{const ref=socialRef(p);return Object.values(world.socialState?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref))?.id||null;};
const allied=(world,p,q)=>(!!p.partyId&&p.partyId===q.partyId)||(()=>{const a=guildOf(world,p);return gameplayPreferences(p.profile.gameplayPreferences).notGuild&&!!a&&a===guildOf(world,q);})();
/** Why p may not hit q right now ('off' | 'safe' | 'instance' | 'ally' | 'invalid'), or null when forced PK is allowed. */
export function pkRefusal(world,p,q,{allowDowned=false}={}){
  if(!q||q===p||!up(world,p)||!up(world,q,allowDowned)||!sameScene(p,q)||isObserver(world,q)||isObserver(world,p))return 'invalid';
  const place=pkPlace(world,p);if(place)return place;
  if(pkPlace(world,q))return 'safe';
  if(allied(world,p,q))return 'ally';
  return null;
}
// A lawful target is the current native-wanted actor or a battle-status aggressor. Official Global guide 62: battle status
// "lasts for 60 seconds from the moment you start PK" (FIELD_PK.battleStatusMs, wanted.mjs pkBattleActive); each new unlawful
// forced hit restarts it. Hostility is never derived from a client color.
const acceptedHits=new WeakMap();
const battleAggressor=(world,p)=>up(world,p,true)&&pkBattleActive(world,p)&&pkPlace(world,p)===null;
export {pkBattleActive};
const lawfulTarget=(world,p)=>wantedLevel(world,p)>0||battleAggressor(world,p);
const enemy=(world,p,q)=>pkRefusal(world,p,q)===null&&(armed(world,p)||lawfulTarget(world,q));
const opponents=(world,p)=>[...world.players.values()].filter(q=>enemy(world,p,q));
const acceptedHit=(world,killer,target)=>{
  const hit=acceptedHits.get(target),age=world.now()-Number(hit?.at);
  return !!killer&&hit?.killer===killer&&hit.record===target.pvpLastHit&&target.pvpLastHit?.by===killer.id&&age>=0&&age<=FIELD_PK.forcedWindowMs&&hit.map===target.map&&hit.channel===(target.channel||0)&&hit.instance===(target.instanceId||null)?hit:null;
};

// ---- consequences of a PK kill
async function onDown(world,attacker,target){
  const by=target.pvpLastHit?.by&&[...world.players.values()].find(q=>q.id===target.pvpLastHit.by),killer=by||attacker;
  // A skill's ordinary kill() has already marked this verified victim dead.
  // Only the internal down path permits that state; attack guards still refuse it.
  const hit=acceptedHit(world,killer,target);
  if(!killer||killer===target||(!armed(world,killer)&&!hit?.lawful)||pkRefusal(world,killer,target,{allowDowned:true})!==null||guildWarEnemy(world,killer,target,{allowDowned:true}))return;   // a guild war kill belongs to the war, not to PK
  const key=`${target.id}:${target.pvpLastHit?.at??world.now()}`,seen=world.fieldPkDowns||=new Set();if(seen.has(key))return;seen.add(key);
  if(seen.size>2000)for(const k of [...seen].slice(0,1000))seen.delete(k);
  if(!target.dead){target.hp=0;target.dead=true;target.path=[];}
  target.profile.deaths=(target.profile.deaths||0)+1;world.changed(target);
  killer.profile.kills=(killer.profile.kills||0)+1;
  let evil=false;
  const row=world.data?.mapRow?.(killer.map),noChaos=num(row?.IsNotIncreaseChao)===1,victimWanted=wantedLevel(world,target)>0;
  if(!noChaos&&!hit?.lawful&&!(FIELD_PK.justKill&&victimWanted)){const r=addChaos(world,killer);evil=r.before===0&&r.after>0;}
  world.changed(killer);
  world.emit(killer.map,{type:'pk',reason:'killed',actorId:killer.id,targetId:target.id,recipients:[killer.id,target.id]});
  if(evil)world.emit(killer.map,{type:'pk',reason:'evil',actorId:killer.id,targetId:killer.id,recipients:[killer.id]});
  void world.persistMany?.([killer,target].filter(q=>up(world,q)||q===target)).catch?.(()=>{});
}
/** Called for every forced hit on a player (basic attack or skill): the attacked / being-attacked notices, once per pair per interval. */
export function noteForcedHit(world,attacker,target){
  const seen=attacker.pkNoticed||={},now=world.now();
  // Snapshot the accepted hit before any attacker flag changes. Retaliation must not
  // turn the victim into an aggressor or forgive the original aggressor's next kill.
  const lawful=lawfulTarget(world,target),record=target.pvpLastHit;
  const age=now-Number(record?.at);
  if(record?.by===attacker.id&&Number.isFinite(record.at)&&age>=0&&age<=FIELD_PK.forcedWindowMs&&pkRefusal(world,attacker,target,{allowDowned:true})===null)acceptedHits.set(target,{killer:attacker,record,at:record.at,lawful,map:target.map,channel:target.channel||0,instance:target.instanceId||null});
  if(!lawful){noteBattleStatus(world,attacker,now);attacker.pkBattleVictim=target.id;}   // kept per character through a reconnect (wanted.mjs)
  if(seen[target.id]!=null&&now-seen[target.id]<FIELD_PK.noticeRepeatMs)return;
  seen[target.id]=now;
  world.emit(attacker.map,{type:'pk',reason:'attacked',actorId:attacker.id,targetId:target.id,recipients:[attacker.id,target.id]});
}
registerPvpMode({enemy,opponents,onDown,onHit:(world,attacker,target)=>{if(enemy(world,attacker,target)&&!guildWarEnemy(world,attacker,target))noteForcedHit(world,attacker,target);}});
export const pkEnemy=enemy;

/** The refusal text a forced attack on q gets from the original strings (cate 1003), or null when allowed. */
export function pkRefusalText(world,p,q){
  const why=pkRefusal(world,p,q);
  if(why==='safe')return PK_TEXT[8];
  if(why==='ally')return `${q?.profile?.name||''} ${PK_TEXT[3]}`.trim();
  return null;
}
