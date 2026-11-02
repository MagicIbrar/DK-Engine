// Guild war PvP (made real for SIEGE). Members of two guilds at an ACTIVE war (state.guildWars status 'active',
// 135:111) are hostile on PvP fields (maplist IsPvP 1 + PVP_PeaceZone 0, never inside an instance): basic attacks and skills run
// the PvP pipeline of server/world/pvp.mjs (src/game/pvp-rules.js pvpDamage, shield first) through registerPvpMode. A down is an
// ordinary death (profile.deaths, the normal revive) and counts once for the killer's guild on the war (war.kills[guildId]).
// Values: src/config/engine-chosen-guild.js GUILD_WAR_CHOSEN (lane 51 g labels: COMBAT / SAFE_MAP_INDEXES ONLINE, COMBAT_MAP ONLINE +
// JUDGMENT, KILL_CREDIT / KILL_FLUSH_MS JUDGMENT).
// The kill notice is GLOBAL 130:476 "In %s %s was killed by %s." (map name, victim, killer; decompile FUN_01396f00, LANE-61).
// ONLINE (WAR_SOURCE_URL): alliance guilds auto-join an active war; SAFE_MAP_INDEXES refuse combat but still show enemy names red;
// war kills add no Niete (field-pk.mjs skips guildWarEnemy downs).
import {registerPvpMode} from './pvp.mjs';
import {sameScene} from './scene.mjs';
import {socialRef} from './social-state.mjs';
import {siegeSystemWrite} from './siege.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {warState} from '../../src/systems/extras/guildextras-rules.js';
import {isPvpField} from '../../src/game/siege-rules.js';
import {GUILD_WAR_CHOSEN as W} from '../../src/config/engine-chosen-guild.js';

const PENDING=W.PENDING_TIMEOUT_MS;
const safeMaps=()=>W.SAFE_MAP_INDEXES||[];
/** Guild ids that share a war side with `guildId`: itself plus every member of its alliance (ONLINE auto-join). */
export function warSideGuilds(state,guildId){
  if(!guildId)return [];
  const a=allianceOfGuild(state,guildId);
  return a?.guilds?.length? [...new Set(a.guilds.filter(Boolean))] : [guildId];
}
/** Per-revision index: member ref -> guild id, guild id -> Map(foe guild id -> war id) of active wars (alliance-expanded). */
function index(world){
  const state=world.socialState,now=world.now(),slot=Math.floor(now/1000);
  const c=world._guildWarIndex;if(c&&c.state===state&&c.revision===state?.revision&&c.slot===slot)return c;
  const byRef=new Map(),foes=new Map();
  for(const g of Object.values(state?.guilds||{}))for(const m of g.members||[])byRef.set(m.ref,g.id);
  for(const w of state?.guildWars||[]){if(warState(w,now,PENDING)!=='active')continue;
    const left=warSideGuilds(state,w.from),right=warSideGuilds(state,w.to);
    for(const a of left)for(const b of right){if(a===b)continue;
      (foes.get(a)||foes.set(a,new Map()).get(a)).set(b,w.id);
      (foes.get(b)||foes.set(b,new Map()).get(b)).set(a,w.id);}
  }
  return world._guildWarIndex={state,revision:state?.revision,slot,byRef,foes};
}
/** Can members of a war fight on p's current map? (GUILD_WAR_CHOSEN.COMBAT_MAP + SAFE_MAP_INDEXES) */
export function warCombatMap(world,p){
  if(!p||p.instanceId)return false;
  const map=Number(p.map);if(safeMaps().includes(map))return false;
  const row=world.data.mapRow?.(p.map);
  return Number(row?.IsPvP)===W.COMBAT_MAP.isPvP&&Number(row?.PVP_PeaceZone)===W.COMBAT_MAP.pvpPeaceZone&&isPvpField(row);
}
/** The active war id between the guilds of p and q (alliance-expanded), or null. */
export function warBetween(world,p,q){
  if(!world.socialState||!p||!q)return null;
  const x=index(world),a=x.byRef.get(socialRef(p)),b=x.byRef.get(socialRef(q));
  return a&&b&&a!==b?x.foes.get(a)?.get(b)||null:null;
}
const up=(world,q,allowDowned=false)=>!!q&&world.players.get(q.account)===q&&!q.leaving&&(allowDowned||!q.dead)&&!q.sceneTransition&&!(q.gmAuthorized&&q.profile.gm?.hide);
/** Combat foe: active war + same scene + warCombatMap (no fight in SAFE_MAP_INDEXES / peace towns). */
export function guildWarEnemy(world,p,q,{allowDowned=false}={}){
  return !!q&&q!==p&&up(world,p)&&up(world,q,allowDowned)&&sameScene(p,q)&&warCombatMap(world,p)&&warCombatMap(world,q)&&!!warBetween(world,p,q);
}
export function guildWarOpponents(world,p){return [...world.players.values()].filter(q=>guildWarEnemy(world,p,q));}
/** Rival for red names: active war (alliance-expanded), no map gate. ONLINE: names stay red even in excluded regions. */
export function guildWarRival(world,p,q,{allowDowned=false}={}){
  return !!q&&q!==p&&up(world,p)&&up(world,q,allowDowned)&&!!warBetween(world,p,q);
}
export function guildWarRivals(world,p){return [...world.players.values()].filter(q=>guildWarRival(world,p,q,{allowDowned:true}));}
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
  // 130:476 arguments in the decompile's order: map name (maplist.csv Name of the map index), victim, killer
  // ONLINE: every guild on either war side (alliance-expanded) hears the kill notice.
  const mapName=String(world.data.mapRow?.(target.map)?.Name??'').trim()||String(target.map),args=[mapName,target.profile.name,killer.profile.name];
  const guilds=new Set([...warSideGuilds(world.socialState,gid),...warSideGuilds(world.socialState,x.byRef.get(socialRef(target)))]);
  for(const q of world.players.values())if(!q.leaving&&guilds.has(x.byRef.get(socialRef(q))))world.emit(q.map,{type:'guildNotice',code:[...W.KILL_NOTICE],args,warId:war,recipients:[q.id]});
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
