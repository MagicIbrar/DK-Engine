// Guild war PvP (made real for SIEGE). Members of two guilds at an ACTIVE war (state.guildWars status 'active',
// 135:111) are hostile on PvP fields (maplist IsPvP 1 + PVP_PeaceZone 0, never inside an instance): basic attacks and skills run
// the PvP pipeline of server/world/pvp.mjs (src/game/pvp-rules.js pvpDamage, shield first) through registerPvpMode. A down is an
// ordinary death (profile.deaths, the normal revive) and counts once for the killer's guild on the war (war.kills[guildId]).
// ENGINE-CHOSEN values: src/config/engine-chosen-guild.js GUILD_WAR_CHOSEN (COMBAT, COMBAT_MAP, KILL_CREDIT, KILL_FLUSH_MS, KILL_NOTICE).
import {registerPvpMode} from './pvp.mjs';
import {sameScene} from './scene.mjs';
import {socialRef} from './social-state.mjs';
import {siegeSystemWrite} from './siege.mjs';
import {warState} from '../../src/systems/extras/guildextras-rules.js';
import {isPvpField} from '../../src/game/siege-rules.js';
import {GUILD_WAR_CHOSEN as W} from '../../src/config/engine-chosen-guild.js';

const PENDING=W.PENDING_TIMEOUT_MS;
/** Per-revision index: member ref -> guild id, guild id -> Map(foe guild id -> war id) of active wars. */
function index(world){
  const state=world.socialState,now=world.now(),slot=Math.floor(now/1000);
  const c=world._guildWarIndex;if(c&&c.state===state&&c.revision===state?.revision&&c.slot===slot)return c;
  const byRef=new Map(),foes=new Map();
  for(const g of Object.values(state?.guilds||{}))for(const m of g.members||[])byRef.set(m.ref,g.id);
  for(const w of state?.guildWars||[]){if(warState(w,now,PENDING)!=='active')continue;
    (foes.get(w.from)||foes.set(w.from,new Map()).get(w.from)).set(w.to,w.id);(foes.get(w.to)||foes.set(w.to,new Map()).get(w.to)).set(w.from,w.id);}
  return world._guildWarIndex={state,revision:state?.revision,slot,byRef,foes};
}
/** Can members of a war fight on p's current map? (GUILD_WAR_CHOSEN.COMBAT_MAP) */
export function warCombatMap(world,p){
  if(!p||p.instanceId)return false;
  const row=world.data.mapRow?.(p.map);
  return Number(row?.IsPvP)===W.COMBAT_MAP.isPvP&&Number(row?.PVP_PeaceZone)===W.COMBAT_MAP.pvpPeaceZone&&isPvpField(row);
}
/** The active war id between the guilds of p and q, or null. */
export function warBetween(world,p,q){
  if(!world.socialState||!p||!q)return null;
  const x=index(world),a=x.byRef.get(socialRef(p)),b=x.byRef.get(socialRef(q));
  return a&&b&&a!==b?x.foes.get(a)?.get(b)||null:null;
}
const up=(world,q,allowDowned=false)=>!!q&&world.players.get(q.account)===q&&!q.leaving&&(allowDowned||!q.dead)&&!q.sceneTransition&&!(q.gmAuthorized&&q.profile.gm?.hide);
export function guildWarEnemy(world,p,q,{allowDowned=false}={}){
  return !!q&&q!==p&&up(world,p)&&up(world,q,allowDowned)&&sameScene(p,q)&&warCombatMap(world,p)&&warCombatMap(world,q)&&!!warBetween(world,p,q);
}
export function guildWarOpponents(world,p){return [...world.players.values()].filter(q=>guildWarEnemy(world,p,q));}
const pending=world=>world.guildWarKills||=new Map();   // war id -> {guildId: n}
function onDown(world,attacker,target){
  const hit=target.pvpLastHit,by=hit?.by&&[...world.players.values()].find(q=>q.id===hit.by),killer=by||attacker;
  const war=warBetween(world,killer,target);if(!war||!warCombatMap(world,target))return;
  const key=`${target.id}:${hit?.at??world.now()}`,seen=world.guildWarDowns||=new Set();if(seen.has(key))return;seen.add(key);
  if(seen.size>2000)for(const k of [...seen].slice(0,1000))seen.delete(k);
  if(!target.dead){target.hp=0;target.dead=true;target.path=[];}
  // The skill engine may already set dead before this once-per-hit settlement.
  target.profile.deaths=(target.profile.deaths||0)+1;world.changed(target);void world.persist(target).catch(()=>{});
  const x=index(world),gid=x.byRef.get(socialRef(killer)),row=pending(world).get(war)||{};row[gid]=(row[gid]||0)+1;pending(world).set(war,row);
  const text=W.KILL_NOTICE.replace('%s',killer.profile.name).replace('%s',target.profile.name),guilds=new Set([gid,x.byRef.get(socialRef(target))]);
  for(const q of world.players.values())if(!q.leaving&&guilds.has(x.byRef.get(socialRef(q))))world.emit(q.map,{type:'guildNotice',text,warId:war,recipients:[q.id]});
}
registerPvpMode({enemy:guildWarEnemy,opponents:guildWarOpponents,onDown});
/** Durable + queued kills of a war: {guildId: n}. */
export function warKills(world,w){
  const out={...(w.kills||{})},add=row=>{for(const [g,n] of Object.entries(row||{}))out[g]=(out[g]||0)+n;};
  add(pending(world).get(w.id));
  const f=world._guildWarInflight;if(f&&world.socialState?.guildWarKillFlush!==f.id)add(f.batch.get(w.id));   // being written, not committed yet
  return out;
}
/** Fold queued kills into the durable war records (host system write); lazily called from guild snapshots. */
export function tickGuildWarPvp(world){
  const queue=pending(world),now=world.now();
  if(!queue.size||world._guildWarFlushing||now<(world._guildWarFlushAt||0)||!world.saveSocialTransaction)return null;
  world._guildWarFlushAt=now+W.KILL_FLUSH_MS;const batch=new Map(queue),id=`${now}:${Math.random().toString(36).slice(2,8)}`;queue.clear();world._guildWarInflight={id,batch};
  world._guildWarFlushing=siegeSystemWrite(world,state=>{let any=false;for(const w of state.guildWars||[]){const add=batch.get(w.id);if(!add)continue;w.kills||={};for(const [g,n] of Object.entries(add))w.kills[g]=(w.kills[g]||0)+n;any=true;}if(any)state.guildWarKillFlush=id;return any;})
    .catch(()=>{for(const [war,row] of batch){const cur=queue.get(war)||{};for(const [g,n] of Object.entries(row))cur[g]=(cur[g]||0)+n;queue.set(war,cur);}})
    .finally(()=>{world._guildWarFlushing=null;if(world._guildWarInflight?.id===id)world._guildWarInflight=null;});
  return world._guildWarFlushing;
}
