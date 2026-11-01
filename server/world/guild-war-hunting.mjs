// GUILD-WAR-HUNTING (shared play): "Braiken Castle Defense Battle" on map 707, a guild-against-guild PvE score race.
// Original data: NPC Vascuda 5532 (Ardeca) jobs 137 GUILDWAR_HUNTING_ENTER_GUILDER / 138 GUILDWAR_HUNTING_ENTER_OBSERVER;
// share/guildwarhunting/config.csv (MAPINDEX 707, StartX/Y, ReviveX1/Y1, ObserverMaxCount, monster -> Score rows);
// maps[707] random call tables + random position tables (radius) + the castle gate brick (isCreate 1); maplist level 200+,
// IsPvP 0 / PeaceZone 1 (no player combat); strings 707|100 Begin in, 101 Progress Time, 102 invaders appeared,
// 103 End waiting time; scoreboard columns 270|4/77-85. Timings, the session model and the server name are
// ENGINE-CHOSEN (src/config/engine-chosen-guild-war-hunting.js).
// Model: one shared instance per session. Every guild member who enters at Vascuda joins it, and kills score for the
// killer's guild. The final board ranks guilds by score (ties: the guild that reached its score first), then everyone
// returns to where they entered. Observers (job 138, up to ObserverMaxCount) are invisible and untargetable and can
// only walk or chat. Death revives in place at ReviveX1/Y1.
import {randomUUID} from 'node:crypto';
import {createInstance,exitInstance,requestInstanceClose} from './instances.mjs';
import {cancelFishing} from './fishing.mjs';
import {pcshopGuard} from './pcshop.mjs';
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {socialRef} from './social-state.mjs';
import {guildMark} from './guilds.mjs';
import {footprintCells} from '../../src/systems/events/bricks.js';
import {plain} from '../../src/systems/events/text.js';
import {registerObserverMode,isObserver,anyObserverAction} from './observers.mjs';
import {GUILD_WAR_HUNTING_ENGINE_CHOSEN as CHOSEN} from '../../src/config/engine-chosen-guild-war-hunting.js';
export const HUNT_SCHEMAS={hunt:['token','type','operation','npcIndex']};
export const HUNT_MAP=707;
const JOB_GUILDER=137,JOB_OBSERVER=138;
const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
const modeOf=world=>world.data.eventData?.modes?.guildWarHunting||null;
const mapInfo=world=>world.data.eventData?.map?.(HUNT_MAP)||null;
const textOf=(world,code)=>plain(world.data.eventData?.mapTxt?.(HUNT_MAP,code)||'').trim();
/** Guild of a connected character from the shared social state: name, level, master and mark. */
export function huntGuildOf(world,p){
  const guilds=world.socialState?.guilds;if(!guilds)return null;
  const ref=socialRef(p),g=Object.values(guilds).find(row=>row?.members?.some(m=>m.ref===ref));if(!g)return null;
  let level=Number.isInteger(g.level)?g.level:1;
  if(!Number.isInteger(g.level))for(let i=1;i<=15;i++)if((g.gpoint||0)>=Number(world.data.guild?.config?.[`LEVELSTEP${i}`]))level=i;
  const masterRow=g.members.find(m=>m.ref===g.master),live=[...world.players.values()].find(q=>!q.leaving&&socialRef(q)===g.master);
  return {id:String(g.id),name:String(g.name||''),level,master:live?.profile?.name||world.socialNames?.get?.(g.master)||masterRow?.name||'',mark:guildMark(g.mark)};
}
const currentRun=world=>{const run=world.guildWarHunt;if(run&&(!world.instances?.has(run.instance.id)||run.instance.closed)){world.guildWarHunt=null;return null;}return run||null;};
const inRun=(run,p)=>!!run&&p.instanceId===run.instance.id;
const huntObserver=(world,p)=>{const run=world.guildWarHunt;return inRun(run,p)&&run.observers.has(p.characterId);};
/** SharedWorld's observer hook: true for an observer of any registered mode (hunt, tourney, OBSERVER; server/world/observers.mjs). */
export function isHuntObserver(world,p){return isObserver(world,p);}
function startPoint(world,scene,observer){const c=modeOf(world)?.config||{};const at=scene.nearest(Number(c.StartX)+.5,Number(c.StartY)+.5);if(!at)fail('No safe Guild War Hunting start point is available.',503);return at;}
function newRun(world,instance){
  const info=mapInfo(world),calls=new Map(),positions=new Map();
  for(const [ci,mon,count,pos] of info?.randomCalls||[]){if(!calls.has(ci))calls.set(ci,[]);calls.get(ci).push({mon:Number(mon),count:Number(count)||1,pos:Number(pos)});}
  for(const [pi,x,z,r] of info?.randomPositions||[]){if(!positions.has(pi))positions.set(pi,[]);positions.get(pi).push([Number(x),Number(z),Number(r)||0]);}
  const now=world.now();
  const run={id:instance.id,instance,phase:'begin',startedAt:now,phaseEnd:now+CHOSEN.beginSec*1000,nextCall:Infinity,callIndex:0,order:[...calls.keys()].sort((a,b)=>a-b),calls,positions,
    scoreOf:new Map((modeOf(world)?.monsterScore||[]).map(([m,s])=>[Number(m),Number(s)])),guilds:new Map(),players:new Map(),observers:new Set(),invaders:new Set(),board:null,closing:false,bricks:[]};
  // the castle gate (isCreate 1) stands for the whole battle: block its footprint in the instance collision
  const scene=instance.scene;
  for(const [uid,brick,x,z,dir,isCreate] of info?.bricks||[]){if(Number(isCreate)!==1)continue;const def=world.data.eventData?.brick?.(brick);if(!def)continue;
    for(const [cx,cz] of footprintCells(x,z,dir,def.widthSize||1,def.heightSize||1))if(cx>=0&&cz>=0&&cx<scene.width&&cz<scene.height&&scene.collision?.cells)scene.collision.cells[cz*scene.width+cx]=1;
    run.bricks.push({uid,brick,x,z,dir});}
  // no instance.run: tickEvents/eventSnapshot treat instance.run as a cooperative event; currentRun() drops a closed instance.
  return run;
}
function admit(world,instance,p){
  cancelFishing(world,p);world.emit(p.map,{type:'leave',actorId:p.id});
  p.instanceId=instance.id;p.map=instance.map;p.path=[];p.mount=null;p.pet=null;
  instance.admitted.add(p.characterId);instance.members.add(p.id);
  p.profile.instance={id:instance.id,kind:instance.kind,map:instance.map,exit:instance.exit};world.changed(p);
}
async function enter(world,p,input,observer){
  // Admission can also be called outside SharedWorld's dispatcher; hold an open-shop seller in place (180:3).
  pcshopGuard(world,p,{type:'hunt'});
  const job=observer?JOB_OBSERVER:JOB_GUILDER,npcIndex=Number(input.npcIndex);
  if(p.instanceId)fail('Leave the current run first.',403);
  const placed=Number.isInteger(npcIndex)?nearbyNpc(world,p,{npcIndex,jobType:job,radius:8}):null;
  if(!placed||!placed.jobs.some(([t,i])=>Number(t)===job&&offersOriginalJob(world,placed,job,i)))fail('Stand near Vascuda in Ardeca.',403);
  const info=mapInfo(world),min=Number(info?.level?.[0])||1;
  if((Number(p.profile.level)||1)<min)fail(`Guild War Hunting requires Lv. ${min}+.`,403);
  let run=currentRun(world);const guild=observer?null:huntGuildOf(world,p);
  if(!observer&&!guild)fail('Only guild members can join Guild War Hunting.',403);
  if(observer){if(!run||run.phase==='end')fail('No Guild War Hunting is in progress to observe.',409);
    const max=Number(modeOf(world)?.config?.ObserverMaxCount)||0;if(run.observers.size>=max)fail('The observer seats are full.',409);}
  else if(run&&run.phase==='end')fail('This Guild War Hunting is ending. Enter the next session.',409);
  const exit={map:p.map,x:p.x,z:p.z};
  if(!run){
    const total=(CHOSEN.beginSec+CHOSEN.battleSec+CHOSEN.endSec+300)*1000;
    const instance=await createInstance(world,{map:HUNT_MAP,members:[p],kind:'guildWarHunting',exit,durationMs:total});
    run=world.guildWarHunt=newRun(world,instance);
  }else admit(world,run.instance,p);
  const at=startPoint(world,run.instance.scene,observer);p.x=at.x;p.z=at.z;p.yaw=0;
  if(observer)run.observers.add(p.characterId);
  else{if(!run.guilds.has(guild.id))run.guilds.set(guild.id,{...guild,score:0,scoredAt:Infinity});else Object.assign(run.guilds.get(guild.id),{...guild,score:run.guilds.get(guild.id).score});
    if(!run.players.has(p.characterId))run.players.set(p.characterId,{name:p.profile.name,guildId:guild.id,score:0});}
  world.changed(p);await world.persist(p);if(!observer)world.emit(p.map,{type:'join',actorId:p.id});
  return {operation:observer?'observe':'enter',phase:run.phase};
}
function spawnCall(world,run){
  const ci=run.order[run.callIndex++],scene=run.instance.scene,rows=run.calls.get(ci)||[];
  for(const c of rows){const def=world.data.monsterDef(c.mon);if(!def)continue;const pts=run.positions.get(c.pos)||[];if(!pts.length)continue;
    const [px,pz,r]=pts[Math.floor(world.random()*pts.length)%pts.length];
    for(let n=0;n<c.count;n++){const a=world.random()*Math.PI*2,d=world.random()*r;const point=scene.nearest(px+.5+Math.cos(a)*d,pz+.5+Math.sin(a)*d);if(!point)continue;
      const id=`hunt:${run.id}:${randomUUID()}`,score=run.scoreOf.get(c.mon)||0;
      const m={id,map:HUNT_MAP,instanceId:run.id,channel:0,monsterIndex:c.mon,name:def.name,...point,hp:def.hp,maxHp:def.hp,home:{...point},dead:false,targetId:null,attackAt:0,respawnAt:Infinity,respawnSec:Infinity,
        def:{...def},huntScore:score,huntArea:[px,pz]};   // the invaders keep their own data AI (monsters.json ai: aggressive, sight, pursuit)
      m.onKilled=killer=>creditKill(world,run,killer,m);
      scene.monsters.set(id,m);run.invaders.add(m);}}
  world.emit(HUNT_MAP,{type:'event:message',text:textOf(world,102),instanceId:run.id});
}
/** Called by SharedWorld.reward for the killer (a summon's kill credits its owner). */
export function creditKill(world,run,killer,m){
  if(m._huntCounted||world.guildWarHunt!==run||run.phase!=='battle'||!inRun(run,killer)||run.observers.has(killer.characterId))return;m._huntCounted=true;
  const row=run.players.get(killer.characterId),guild=row&&run.guilds.get(row.guildId),score=Number(m.huntScore)||0;if(!guild||score<=0)return;
  row.score+=score;guild.score+=score;guild.scoredAt=world.now();
}
function ranking(run){return [...run.guilds.values()].sort((a,b)=>b.score-a.score||a.scoredAt-b.scoredAt||a.name.localeCompare(b.name)).map((g,i)=>({rank:i+1,id:g.id,name:g.name,level:g.level,master:g.master,mark:g.mark,server:CHOSEN.serverName,score:g.score}));}
export function tickGuildWarHunting(world){
  const run=currentRun(world);if(!run)return;const now=world.now();
  if(run.phase==='begin'&&now>=run.phaseEnd){run.phase='battle';run.phaseEnd=now+CHOSEN.battleSec*1000;run.nextCall=now+1000;}
  if(run.phase==='battle'){
    while(now>=run.nextCall&&run.callIndex<run.order.length){spawnCall(world,run);run.nextCall+=CHOSEN.callEverySec*1000;}
    if(now>=run.phaseEnd){for(const m of run.invaders)run.instance.scene.monsters.delete(m.id);run.invaders.clear();run.board=ranking(run);run.phase='end';run.phaseEnd=now+CHOSEN.endSec*1000;
      world.emit(HUNT_MAP,{type:'hunt:board',instanceId:run.id});}
  }
  if(run.phase==='end'&&now>=run.phaseEnd){run.closing=true;void requestInstanceClose(world,run.instance)?.catch?.(()=>{});}
}
export function huntSnapshot(world,p){
  const run=world.guildWarHunt;if(!inRun(run,p))return null;
  const board=run.board||ranking(run),observer=run.observers.has(p.characterId),mine=run.players.get(p.characterId),own=mine&&board.find(r=>r.id===mine.guildId);
  return {id:run.id,map:HUNT_MAP,phase:run.phase,remainingMs:Math.max(0,run.phaseEnd-world.now()),observer,final:!!run.board,top:board.slice(0,10),
    me:own?{rank:own.rank,guildName:own.name,server:CHOSEN.serverName,name:p.profile.name,mark:own.mark,guildScore:own.score,score:mine.score}:null,
    observers:run.observers.size,bricks:run.bricks,lights:huntLights(world,run,p,mine)};
}
const r1=v=>Math.round(v*10)/10;
/** ui_huntminimapwnd lights (ENGINE-CHOSEN meaning, see the config): you, your guild members' centre, the two areas
 *  with the most live invaders, and the strongest live invader. */
export function huntLights(world,run,p,mine=run.players.get(p.characterId)){
  const live=[...run.invaders].filter(m=>!m.dead),areas=new Map();
  for(const m of live){if(!m.huntArea)continue;const k=m.huntArea.join(':');const a=areas.get(k)||{x:m.huntArea[0]+.5,z:m.huntArea[1]+.5,count:0};a.count++;areas.set(k,a);}
  const invaders=[...areas.values()].sort((a,b)=>b.count-a.count||a.x-b.x||a.z-b.z).slice(0,2).map(a=>[r1(a.x),r1(a.z),a.count]);
  const boss=live.filter(m=>(Number(m.huntScore)||0)>=CHOSEN.minimap.bossMinScore).sort((a,b)=>b.huntScore-a.huntScore||String(a.id).localeCompare(String(b.id)))[0]||null;
  const mates=mine?[...world.players.values()].filter(q=>q!==p&&!q.leaving&&inRun(run,q)&&!run.observers.has(q.characterId)&&run.players.get(q.characterId)?.guildId===mine.guildId):[];
  const guild=mates.length?[r1(mates.reduce((n,q)=>n+q.x,0)/mates.length),r1(mates.reduce((n,q)=>n+q.z,0)/mates.length),mates.length]:null;
  return {self:[r1(p.x),r1(p.z)],guild,invaders,boss:boss?[r1(boss.x),r1(boss.z),boss.huntScore]:null};
}
/** Death inside the hunt revives at ReviveX1/Y1 instead of leaving the run. */
// Other modes that revive inside their own scene (ARENA: server/world/arena.mjs) register here; core's revive asks huntRevive first.
export const SCENE_REVIVE_HOOKS=[];
export function huntRevive(world,p){
  for(const hook of SCENE_REVIVE_HOOKS)if(hook(world,p))return true;
  const run=world.guildWarHunt;if(!inRun(run,p)||!p.dead)return false;
  const c=modeOf(world)?.config||{},at=run.instance.scene.nearest(Number(c.ReviveX1)+.5,Number(c.ReviveY1)+.5);if(!at)return false;
  p.x=at.x;p.z=at.z;p.hp=p.maxHp;p.mp=p.stats.maxMp||0;p.dead=false;p.path=[];world.changed(p);return true;
}
/** Observers may walk, stop, chat, emote and use the hunt service only. */
const HUNT_OBSERVER_ACTIONS=new Set(['move','stop','chat','emote','hunt']);
registerObserverMode({is:huntObserver,actions:HUNT_OBSERVER_ACTIONS});
// SharedWorld checks OBSERVER_ACTIONS after isHuntObserver: any registered mode's action passes there, each service checks its own seat.
export const OBSERVER_ACTIONS=Object.freeze({has:anyObserverAction});
export async function huntCommand(world,p,input){
  if(input.operation==='enter')return enter(world,p,input,false);
  if(input.operation==='observe')return enter(world,p,input,true);
  if(input.operation==='leave'){const run=world.guildWarHunt;if(!inRun(run,p))fail('You are not in Guild War Hunting.');run.observers.delete(p.characterId);await exitInstance(world,p);return {operation:'leave'};}
  fail('Unknown Guild War Hunting operation.');
}
