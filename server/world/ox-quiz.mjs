// OX QUIZ host controller (Undo Stadion map 22 via Theme Park map 654). Rules and provenance: src/game/ox-quiz-rules.js.
// Original GM controls use the Start Stone (NPC 5830, "Usable by GM characters only.");
// Lane 47: Global OX is GM-run only; the former automatic schedule/pacing/reward (engine-chosen-ox-quiz.js) is removed.
// players enter from Hani (6185 job31 9710) through warp 11784 -> 11785 and leave through warp 11786 -> 11787.
// SharedWorld dispatches intent-only actions and publishes its canonical snapshot; tick owns the delayed native wall.
// Native zone buffs are durably saved; quiz hazards use the original monster rows and combat values.
//   Live (world.oxQuizLive, host memory only): {open, session:{id, participants, round, used, question, phase, wall}, last}
//   Durable: travel commits, GM zone buffs, and full-run survivor reward receipts, all staged before publication.
import fs from 'node:fs';
import path from 'node:path';
import {grantTimedStatus} from './skills.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {randomUUID} from 'node:crypto';
import {parseMol} from '../../src/formats/mol.js';
import {parseMesh} from '../../src/formats/mesh.js';
import {decodeText} from '../../src/formats/binreader.js';
import {parseStringTableCates} from '../../src/ui/uiwin/strings.js';
import {footprintCells} from '../../src/systems/events/bricks.js';
import {dkLocates} from '../../src/systems/channels/channel-rules.js';
import {nearbyNpc,offersOriginalJob,npcPlacements} from './npc-services.mjs';
import {commitFieldTravel,travelLocation,boundReturnTarget} from './travel.mjs';
import {channelData} from './channels.mjs';
import {trackForcedDisplacement} from './movement-authority.mjs';
import {OX_QUIZ as Q,oxRoundLimit,oxQuestions,oxSides,oxSideAt,oxCallHalves,oxEntryRefusal,oxPickQuestion} from '../../src/game/ox-quiz-rules.js';
import {statusFlags} from '../../src/game/monster-rules.js';

export const OX_QUIZ_SCHEMAS={oxquiz:['token','type','operation','answer','menu']};
export const OX_QUIZ_OPERATIONS=['buff','enter','leave','open','closeEntry','close','wall','unwall','question','eliminate','end'];
const fail=(message,status=400,code=status===409?'OX_QUIZ_REJECTED':null)=>{throw Object.assign(Error(message),{status,...(code?{code}:{})});};
/** Refusals with an original string are sent as `oxquiz:<cate>:<code>`; the client shows the original text. */
const native=(cate,code,status=409)=>fail(`oxquiz:${cate}:${code}`,status,'OX_QUIZ_REFUSED');
const WALL_DELAY_MS=5000;   // 5200 "@<effectui>2033,1,5000,1" (blue 5..1 countdown, 5000 ms) + 5201 "In 5 sec, wall appear!"

// ------------------------------------------------------------------ original data (fail closed)
const cache=new WeakMap();
/** Every original input the controller needs, or null (each check names its source). */
export function oxQuizData(world){
  const host=world?.data;if(!host||typeof host!=='object')return null;
  if(cache.has(host))return cache.get(host);
  let out=null;
  try{out=readData(world);}catch{out=null;}
  cache.set(host,out);return out;
}
function readData(world){
  const d=world.data,ev=d.eventData,arena=ev?.map?.(Q.arena),lobby=ev?.map?.(Q.lobby);
  if(arena?.mode!=='oxQuiz'||lobby?.mode!=='oxQuiz'||Number(arena.flags?.isUseMap)!==1||Number(lobby.flags?.isUseMap)!==1)return null;   // maplist isUseMap
  const questions=oxQuestions(d.lifeEvents?.ox?.questions),max=Number(d.lifeEvents?.ox?.config?.MAX_USER);   // oxlist.csv, oxevent.csv
  if(!questions||!Number.isSafeInteger(max)||max<=0)return null;
  const root=d.dataRoot;if(typeof root!=='string')return null;
  const file=rel=>{const target=path.resolve(root,String(rel).replace(/\\/g,'/'));if(!target.startsWith(path.resolve(root)+path.sep))throw Error('Invalid original path.');return new Uint8Array(fs.readFileSync(target));};
  const strings=parseStringTableCates(decodeText(file(Q.window.file),true)),W=Q.window;
  const texts=Object.fromEntries(['question','solution','answer','survivors','round'].map(k=>[k,strings.get(`${W.cate}:${W[k]}`)??null]));
  const rounds=oxRoundLimit(texts.round);if(!rounds||Object.values(texts).some(t=>!t))return null;   // 2300:28..32
  // events_text's general map22 table omits these Ox-only cate22 entries. Read their actual authored table directly.
  const mapStrings=parseStringTableCates(decodeText(file('script/string/map/stringtable_map_string_01.txt'),true));
  const mapTexts=Object.fromEntries([[Q.arena,[...Object.values(Q.menu).filter(c=>c<9000),...Object.values(Q.notice)]],[Q.lobby,[...Object.values(Q.refusal),Q.menu.open,Q.menu.closeEntry,9710]]].map(([map,codes])=>[map,Object.fromEntries(codes.map(code=>[code,mapStrings.get(`${map}:${code}`)]))]));
  if(Object.values(mapTexts).some(rows=>Object.values(rows).some(text=>!text)))return null;
  const molBytes=file(arena.files?.mol);const mol=parseMol(molBytes.buffer.slice(molBytes.byteOffset,molBytes.byteOffset+molBytes.byteLength));
  const sides=oxSides(mol.objects);if(!sides)return null;   // arena_ox.mol ar_flag/ar_line O and X
  const halves=oxCallHalves(arena.calls,sides);if(!halves||!halves.O.length||!halves.X.length)return null;   // callmonster_22 groups
  const wallRow=(arena.bricks||[]).find(r=>Number(r[0])===Q.wall.uid&&Number(r[1])===Q.wall.brick),wallDef=ev.brick?.(Q.wall.brick);
  if(!wallRow||!wallDef||Number(wallRow[5])!==0)return null;   // brick_22 UID101 36100 IsCreate 0
  // Footprint axis: the brick table gives 32 x 1 cells; its own native mesh (hidden_brick_pvp_wall.mesh) is long along
  // local Z, so at dir 90 it spans world X along the arena_ox.mol ar_line centre row (yaw 90, mesh long along local Z),
  // the strip z 254..256 that no callmonster_22 spike row covers. Every validated gate mesh is long along local X, where
  // the two readings agree; this brick is the case where they differ, so the mesh decides. No mesh -> no wall.
  const wall={uid:Q.wall.uid,brick:Q.wall.brick,x:Number(wallRow[2]),z:Number(wallRow[3]),dir:Number(wallRow[4]),w:Number(wallDef.widthSize)||1,h:Number(wallDef.heightSize)||1,name:wallDef.name,axis:meshLongAxis(file,wallDef.visual?.mesh)};
  wall.footprintDir=wall.axis==='z'?wall.dir+90:wall.axis==='x'?wall.dir:null;
  const warps=d.travelData?.warps||[],warp=(from,to)=>warps.some(w=>Number(w.from)===from&&Number(w.to)===to);
  if(!Q.warps.every(([a,b])=>warp(a,b)))return null;   // warp.csv 11784->11785, 11786->11787
  const L=Q.locations,at=Object.fromEntries(Object.entries(L).map(([k,id])=>[k,travelLocation(world,id)]));
  if(at.admission?.map!==Q.lobby||at.destination?.map!==Q.arena||at.departure?.map!==Q.arena||at.exit?.map!==Q.lobby)return null;   // location.csv
  const placed=(map,id)=>npcPlacements(world,map).filter(r=>r.npcIndex===id&&!r.custom&&r.x>0&&r.z>0);
  const npcJob=(id,[t,i])=>world.data.progression?.npcs?.npcs?.[id]?.jobs?.some(([a,b])=>Number(a)===t&&Number(b)===i);
  const N=Q.npcs,J=Q.jobs;
  if(!placed(Q.arena,N.startStone).length||!placed(Q.arena,N.escapeStone).length||!placed(Q.lobby,N.hani).length)return null;   // npc_22 / npc_654
  if(!npcJob(N.startStone,J.startStone)||!npcJob(N.escapeStone,J.escapeStone)||!npcJob(N.hani,J.hani))return null;   // npc.csv jobs
  const locates=dkLocates(channelData(world),Q.lobby);if(locates.length!==1)return null;   // dkmaplist 654: one DK server
  const levels=d.dungeonCatalog?.maps?.[Q.lobby]?.levels||d.dungeonData?.dg?.maps?.[Q.lobby]?.levels;
  if(!Array.isArray(levels)||levels.length!==2)return null;   // maplist 654 LimitMinLevel/LimitMaxLevel
  const gm=JSON.parse(fs.readFileSync(path.join(d.gamedataRoot,'gmcommands.json'),'utf8'));
  const buffs=new Map((gm.original?.gmBuffs?.buffs||[]).filter(r=>r.inMenu&&Number.isInteger(r.menu)&&Number.isInteger(r.status)&&d.skillStatuses?.[r.status]).map(r=>[r.menu,r]));
  if(buffs.size!==9)return null;
  for(const code of [9556,9557,9558,9559,9560,9700,...buffs.keys()])mapTexts[Q.lobby][code]=mapStrings.get(Q.lobby+':'+code);
  const spikeDef=d.monsterDef?.(8134),spikes=Object.fromEntries(Object.entries(halves).map(([side,groups])=>[side,groups.flatMap(group=>arena.calls[group])]));
  if(!spikeDef||Object.values(spikes).some(rows=>!rows.length||rows.some(r=>Number(r[0])!==8134||Number(r[4])!==1)))return null;
  return {buffs,spikeDef,spikes,questions,max,rounds,texts,mapTexts,sides,halves,wall,at,channel:locates[0].channel,levels:levels.map(Number)};
}

/** 'x' | 'z': the local horizontal axis along which a native brick mesh is longest; null if it cannot be read. */
function meshLongAxis(file,rel){
  if(typeof rel!=='string'||!rel)return null;
  try{
    const bytes=file(rel),mesh=parseMesh(bytes.buffer.slice(bytes.byteOffset,bytes.byteOffset+bytes.byteLength));
    let x0=Infinity,x1=-Infinity,z0=Infinity,z1=-Infinity;
    for(const m of mesh.meshes||[])for(let i=0;i<(m.positions?.length||0);i+=3){const x=m.positions[i],z=m.positions[i+2];if(x<x0)x0=x;if(x>x1)x1=x;if(z<z0)z0=z;if(z>z1)z1=z;}
    const dx=x1-x0,dz=z1-z0;if(!(dx>0&&dz>0))return null;
    return dz>dx*2?'z':dx>dz*2?'x':null;
  }catch{return null;}
}

// ------------------------------------------------------------------ live state
export const oxQuizLive=world=>world.oxQuizLive||={open:false,session:null,last:null,pending:0};
const live=world=>oxQuizLive(world);
const present=(world,q)=>!!q&&world.players.get(q.account)===q&&!q.leaving;
const inArena=(world,data,q)=>present(world,q)&&q.map===Q.arena&&!q.instanceId&&(q.channel??0)===data.channel;
const arenaPlayers=(world,data)=>[...world.players.values()].filter(q=>inArena(world,data,q));
const newSession=world=>({id:randomUUID(),startedAt:world.now(),participants:new Map(),round:0,used:new Set(),question:null,phase:'idle',wall:{state:'down',at:0,cells:null,base:null},spikes:new Set(),ending:false});
function send(world,data,players,event){if(players.length)world.emit(Q.arena,{...event,channel:data.channel,recipients:players.map(q=>q.id)});}
const survivors=s=>[...s.participants.values()].filter(r=>!r.dropout).length;

function busy(world,p){if(world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition||p.tradeId||p.instanceId)fail('The OX quiz is unavailable while disconnected, dead, travelling, trading or in a run.',409);}
function gm(p){if(!p.gmAuthorized)fail('OX quiz controls require server GM authorization.',403);}
function atNpc(world,p,id,[type,index]){
  const row=nearbyNpc(world,p,{npcIndex:id,jobType:type,jobIndex:index,radius:8});
  if(!row||!offersOriginalJob(world,row,type,index))fail('Stand near the original OX quiz NPC.',403);
}
function atStartStone(world,data,p){gm(p);if(!inArena(world,data,p))fail('Use the Start Stone in the OX arena.',403);atNpc(world,p,Q.npcs.startStone,Q.jobs.startStone);}

// ------------------------------------------------------------------ wall (brick UID 101 / 36100 "Wall of Fire")
/** Collision cell indices of the raised wall in a scene. */
export function oxWallCells(data,scene){
  return footprintCells(data.wall.x,data.wall.z,data.wall.footprintDir,data.wall.w,data.wall.h).filter(([x,z])=>x>=0&&z>=0&&x<scene.width&&z<scene.height).map(([x,z])=>z*scene.width+x);
}
function arenaScene(world,data){for(const s of world.maps.values())if(s.index===Q.arena&&!s.instanceId&&(s.channel??0)===data.channel)return s;return null;}
function raiseWall(world,data,s){
  const scene=arenaScene(world,data);if(!scene?.collision?.cells||data.wall.footprintDir==null)return false;
  const cells=oxWallCells(data,scene);
  s.wall.base=new Map(cells.map(i=>[i,scene.collision.cells[i]]));s.wall.cells=cells;
  for(const i of cells)scene.collision.cells[i]=1;
  // a player left on the raised footprint moves to the nearest walkable cell (engine choice; the original only warns)
  const blocked=new Set(cells);
  for(const q of arenaPlayers(world,data)){const i=Math.floor(q.z)*scene.width+Math.floor(q.x);if(!blocked.has(i))continue;const at=scene.nearest(q.x,q.z);if(at){q.x=at.x;q.z=at.z;q.path=[];trackForcedDisplacement(world,q);world.changed(q);world.emit(q.map,{type:'oxQuizMove',actorId:q.id,x:q.x,z:q.z,channel:data.channel,recipients:[q.id]});}}
  s.wall.state='up';s.wall.at=world.now();
  send(world,data,arenaPlayers(world,data),{type:'oxQuizWall',state:'up',uid:data.wall.uid,brick:data.wall.brick});
  return true;
}
function lowerWall(world,data,s){
  const scene=arenaScene(world,data);
  for(const id of s.spikes||[])scene?.monsters.delete(id);
  s.spikes?.clear();
  if(s.wall.state==='up'&&scene?.collision?.cells&&s.wall.base)for(const [i,v] of s.wall.base)scene.collision.cells[i]=v;
  const was=s.wall.state;s.wall={state:'down',at:world.now(),cells:null,base:null};
  if(was!=='down')send(world,data,arenaPlayers(world,data),{type:'oxQuizWall',state:'down',uid:data.wall.uid,brick:data.wall.brick});
}

/** Only incorrect responders on the spawned half can be hurt by this round's OX hazards.
 * Filtering the monster's complete target view also excludes old hate/retaliation targets and staff. */
export function oxSpikeCanTarget(world,m,p){
  if(!m?.oxSpike)return true;
  const data=oxQuizData(world),s=world.oxQuizLive?.session,r=s?.participants.get(p?.id);
  return !!(data&&s&&s.id===m.oxSession&&s.wall.state==='up'&&s.spikes.has(m.id)&&!p?.gmAuthorized&&!p?.dead&&!p?.leaving&&!p?.sceneTransition&&!p?.tradeCommitting&&inArena(world,data,p)&&r?.dropout&&r.reason==='wrong'&&oxSideAt(data.sides,p.x,p.z)===m.oxWrongSide);
}
/** Native 8134 is an invisible effect source, not an ordinary melee monster.
 * A11 result4100201: Explosion@Area@Suicidal, 0x5a2460 -> per-target0x5a2040
 * then source death0x5a2390. V1 is the area radius /32, V2 chance, V3 HP-max %.
 * The only enabled case is the native OX row (480,100,100). No generic invisible
 * creature or unknown result is activated. Selection remains quiz-scoped on every
 * area target, so an old hate target, winning responder or staff cannot be hit.
 * Original 60k melee values are not the explosion formula. */
export function tickOxSpikeCombat(world,m,scene,view){
 if(!m?.oxSpike)return false;
 const a=m.def?.attacks?.melee,s=world.oxQuizLive?.session;
 if(m.dead||m.monsterIndex!==8134||a?.[7]!==4100201||a[8]!==480||a[9]!==100||a[10]!==100||s?.id!==m.oxSession||s.wall.state!=='up'||!s.spikes.has(m.id)||world.now()<m.attackAt||statusFlags(m.statuses).attack)return true;
 const radius=a[8]/32,candidates=(view||[]).filter(p=>oxSpikeCanTarget(world,m,p)&&Math.hypot(p.x-m.x,p.z-m.z)<=radius);
 const target=candidates.find(p=>Math.hypot(p.x-m.x,p.z-m.z)<=a[4]&&(!scene.collision?.lineOfSight||scene.collision.lineOfSight(m.x,m.z,p.x,p.z)));
 if(!target)return true;
 m.targetId=target.id;m.attackAt=world.now()+a[5];
 world.emit(m.map,{type:'attack',actorId:m.id,targetId:target.id,instanceId:null,channel:m.channel,attackKey:'melee',variant:0});
 for(const p of candidates){
  // The native percentage result bypasses armor and PvP shield; it is not an
  // ordinary physical hit, and cannot reflect into a protected OX participant.
  const damage=Math.min(p.hp,Math.trunc(p.maxHp*a[10]/100));if(!(damage>0))continue;
  p.hp=Math.max(0,p.hp-damage);p.dead=p.hp===0;p.lastCombat=world.now();
  if(p.dead){p.path=[];p.profile.deaths=(p.profile.deaths||0)+1;}
  world.changed(p);world.emit(m.map,{type:'damage',sourceId:m.id,targetId:p.id,amount:damage,dead:p.dead,instanceId:null,channel:m.channel});
  if(p.dead)void world.persist(p).catch(()=>{});
 }
 m.hp=0;m.dead=true;m.targetId=null;m.hate?.clear();m.corpseObservedAt=world.now();
 world.emit(m.map,{type:'damage',sourceId:m.id,targetId:m.id,amount:m.maxHp,dead:true,instanceId:null,channel:m.channel});
 return true;
}
function spawnSpikes(world,data,s,side,scene){
  for(const row of data.spikes[side]){
    const x=Number(row[1])+.5,z=Number(row[2])+.5,id=`ox:${s.id}:${s.round}:${s.spikes.size}`,def=data.spikeDef;
    scene.monsters.set(id,{id,monsterIndex:8134,map:Q.arena,channel:data.channel,instanceId:null,name:def.name,x,z,hp:def.hp,maxHp:def.hp,home:{x,z},dead:false,targetId:null,attackAt:0,respawnAt:0,respawnSec:Infinity,oneShot:true,def,oxSpike:true,oxSession:s.id,oxWrongSide:side});
    s.spikes.add(id);
  }
}

// ------------------------------------------------------------------ travel through the original warps
async function moveOut(world,data,q){
  // dropouts and exports leave through warp 11786 -> 11787 on the Theme Park DK channel; a stray without a DK return
  // (not admitted through Hani) goes to its bound return point on the field channel instead (engine choice)
  if((q.channel??0)===data.channel&&q.profile?.dkReturn)return commitFieldTravel(world,q,{...data.at.exit,channel:data.channel});
  return commitFieldTravel(world,q,{...boundReturnTarget(world,q.profile),channel:0});
}
function markDropout(s,q,reason,now){const r=s?.participants.get(q.id);if(r&&!r.dropout){r.dropout=true;r.reason=reason;r.at=now;}}

function askQuestion(world,data,s){
 const q=oxPickQuestion(data.questions,s.used,world.random||Math.random);if(!q)fail('Every original question was used.',409);
 s.used.add(q.index);s.round++;s.phase='question';s.question={...q,askedAt:world.now()};
 send(world,data,arenaPlayers(world,data),{type:'oxQuiz',phase:'question',round:s.round,rounds:data.rounds,question:{index:q.index,text:q.question}});return {round:s.round,question:q.index};
}
function requestWall(world,data,s){
 s.wall={state:'pending',at:world.now()+WALL_DELAY_MS,cells:null,base:null};
 for(const code of [Q.notice.wallCountdown,Q.notice.wallWarning])send(world,data,arenaPlayers(world,data),{type:'oxQuizNotice',cate:Q.arena,code,at:s.wall.at});
 return {wall:'pending',at:s.wall.at};
}
function eliminate(world,data,s,answer){
 const scene=arenaScene(world,data);if(!scene?.monsters)fail('The OX arena is unavailable.',503);
 const wrong=answer==='O'?'X':'O',out=[],now=world.now();
 for(const r of s.participants.values()){
  if(r.dropout||r.arriving)continue;const q=[...world.players.values()].find(x=>x.id===r.id);
  if(!inArena(world,data,q)||q.dead){r.dropout=true;r.reason=q?.dead?'dead':'left';r.at=now;continue;}
  if(oxSideAt(data.sides,q.x,q.z)!==answer){r.dropout=true;r.reason='wrong';r.at=now;r.round=s.round;out.push(r.id);}
  else r.correctRounds=(r.correctRounds||0)+1;
 }
 s.phase='solution';spawnSpikes(world,data,s,wrong,scene);const left=survivors(s),total=s.participants.size;
 send(world,data,arenaPlayers(world,data),{type:'oxQuiz',phase:'solution',round:s.round,rounds:data.rounds,solution:{answer:s.question.answer,text:s.question.solution},survivors:left,maxCount:total,eliminated:out,callGroups:data.halves[wrong]});
 return {eliminated:out.length,survivors:left,maxCount:total,callGroups:data.halves[wrong]};
}
async function endSession(world,data,L,s){
 L.open=false;
 s.ending=true;lowerWall(world,data,s);const failed=[];
 for(const q of arenaPlayers(world,data)){if(q.gmAuthorized)continue;try{await moveOut(world,data,q);}catch(error){failed.push({id:q.id,message:error.message});}}
 if(failed.length)return {ended:false,failed};
 L.last={id:s.id,endedAt:world.now(),rounds:s.round,survivors:[...s.participants.values()].filter(r=>!r.dropout).map(r=>r.name),participants:s.participants.size};L.session=null;return {ended:true,summary:L.last};
}
// ------------------------------------------------------------------ commands
export async function oxQuizCommand(world,p,input){
  if(!input||input.type!=='oxquiz'||Object.keys(input).some(k=>!OX_QUIZ_SCHEMAS.oxquiz.includes(k)))fail('Send OX quiz intent only.');
  const op=input.operation;if(!OX_QUIZ_OPERATIONS.includes(op))fail('Unknown OX quiz operation.');
  const data=oxQuizData(world);if(!data)fail('The original OX quiz data is unavailable.',503);
  busy(world,p);
  const L=live(world),now=world.now();
  if(op==='buff'){
    gm(p);if(p.map!==Q.lobby||(p.channel??0)!==data.channel)fail('Grant the original zone buff in the Theme Park.',403);
    const buff=data.buffs.get(input.menu);if(!buff)fail('Choose a buff in the original 9560 menu.');
    const failed=[],granted=[];
    for(const q of [...world.players.values()].filter(q=>present(world,q)&&q.map===Q.lobby&&!q.instanceId&&(q.channel??0)===data.channel)){
      try{await serializeLife(q,async()=>{
        if(!present(world,q)||q.map!==Q.lobby||q.sceneTransition||q.progressCommitting)fail('Player is changing worlds.',409);
        const before=structuredClone(q.profile),candidate={...q,profile:structuredClone(before),stats:{...q.stats},_skills:null},staged=Object.create(world),events=[];
        staged.emit=(map,event)=>events.push([map,event]);
        candidate.profile.buffs=(candidate.profile.buffs||[]).filter(b=>!(Number(b.statusIndex)>=7484&&Number(b.statusIndex)<=7493));
        grantTimedStatus(staged,candidate,buff.status,buff.minutes*60000);
        await commitLife(world,q,candidate.profile,{profileBefore:before,stats:candidate.stats});
        for(const [map,event]of events)world.emit(map,event);
        world.emit(Q.lobby,{type:'oxQuizNotice',cate:Q.lobby,code:9700,channel:data.channel,recipients:[q.id]});granted.push(q.id);
      });}catch(error){failed.push({id:q.id,message:error.message});}
    }
    return {granted:granted.length,failed,status:buff.status};
  }
  if(op==='enter'){
    if(p.map!==Q.lobby||(p.channel??0)!==data.channel)fail('Talk to Hani in the Theme Park.',403);
    atNpc(world,p,Q.npcs.hani,Q.jobs.hani);
    const level=Number(p.profile.level)||1;if(level<data.levels[0]||level>data.levels[1])fail('Your level cannot enter this map.',403);
    const staff=!!p.gmAuthorized,count=arenaPlayers(world,data).filter(q=>!q.gmAuthorized).length+L.pending;
    const refusal=staff?(L.open?null:Q.refusal.notRunning):oxEntryRefusal({open:L.open&&!!L.session&&!L.session.ending,count,max:data.max});
    if(refusal)native(Q.lobby,refusal);
    // Register before the asynchronous travel so a concurrent tick never treats the arriving player as unadmitted;
    // a failed travel (load/save) removes a record this attempt created and leaves the player where it was.
    const s=L.session,created=!staff&&!s.participants.has(p.id);
    if(created)s.participants.set(p.id,{id:p.id,account:p.account,characterId:p.characterId,name:p.profile.name,joinedAt:now,dropout:false,reason:null,arriving:true});
    const record=s.participants.get(p.id);if(record&&!staff)record.arriving=true;
    if(!staff)L.pending++;
    try{await commitFieldTravel(world,p,{...data.at.destination,channel:data.channel});}
    catch(error){if(created&&L.session===s)s.participants.delete(p.id);throw error;}
    finally{if(!staff)L.pending--;if(record)delete record.arriving;}
    return {entered:true,staff,dropout:!staff&&!!s.participants.get(p.id)?.dropout};
  }
  if(op==='leave'){
    if(!inArena(world,data,p))fail('You are not in the OX arena.',403);
    atNpc(world,p,Q.npcs.escapeStone,Q.jobs.escapeStone);
    const s=L.session;await moveOut(world,data,p);markDropout(s,p,'left',now);
    return {left:true};
  }
  // GM operations
  if(op==='open'||op==='closeEntry'){
    gm(p);if(!(p.map===Q.lobby||p.map===Q.arena)||(p.channel??0)!==data.channel)fail('Use this GM function in the Theme Park or the OX arena.',403);
    if(op==='open'){if(L.session?.ending)fail('Wait until Export All finishes.',409);L.open=true;L.session||=newSession(world);}else L.open=false;
    return {open:L.open,code:op==='open'?Q.menu.open:Q.menu.closeEntry};
  }
  atStartStone(world,data,p);
  const s=L.session;if(!s)fail('Allow entry before using the OX quiz functions.',409);
  if(s.ending&&op!=='end')fail('Export All is in progress.',409);
  if(op==='close'){L.open=false;return {open:false,code:Q.menu.close};}
  if(op==='wall'){
    if(data.wall.footprintDir==null)fail('The original wall footprint is unavailable.',503);
    if(s.wall.state!=='down')fail('The wall is already raised.',409);
    return requestWall(world,data,s);
  }
  if(op==='unwall'){if(s.wall.state==='down')fail('There is no wall.',409);lowerWall(world,data,s);return {wall:'down'};}
  if(op==='question'){
    if(s.phase==='question')fail('Eliminate the incorrect responders of the current question first.',409);
    if(s.wall.state!=='down')fail('Remove the wall before the next question.',409);
    if(s.round>=data.rounds)fail(`All ${data.rounds} rounds are complete.`,409);   // 2300:32 "Round : <COUNT> / 15"
    return askQuestion(world,data,s);
  }
  if(op==='eliminate'){
    const answer=String(input.answer||'').toUpperCase();if(!['O','X'].includes(answer))fail('Choose Eliminate incorrect responders (O) or (X).');
    if(s.phase!=='question'||!s.question)fail('Set a question first.',409);
    if(answer!==s.question.answer)fail('That button does not match the original answer of this question.',409);
    if(s.wall.state!=='up')fail('Raise the wall before eliminating incorrect responders.',409);
    return eliminate(world,data,s,answer);
  }
  if(op==='end')return endSession(world,data,L,s);
  fail('Unknown OX quiz operation.');
}

// ------------------------------------------------------------------ tick
/** Wall countdown, participants that left the arena, and players in the arena without admission. */
export async function tickOxQuiz(world){
  const data=oxQuizData(world);if(!data)return;
  const L=live(world),now=world.now();let s=L.session;
  if(L.ticking)return;L.ticking=true;
  try{
    if(s?.wall.state==='pending'&&now>=s.wall.at&&!raiseWall(world,data,s))s.wall={state:'down',at:now,cells:null,base:null};
    if(s)for(const r of s.participants.values())if(!r.dropout&&!r.arriving){const q=[...world.players.values()].find(x=>x.id===r.id);if(!inArena(world,data,q)){r.dropout=true;r.reason='left';r.at=now;}}
    for(const q of [...world.players.values()]){
      if(!present(world,q)||q.map!==Q.arena||q.instanceId||q.gmAuthorized||q.sceneTransition||q.dead)continue;
      const admitted=s&&!s.ending&&inArena(world,data,q)&&s.participants.has(q.id);
      if(admitted)continue;
      try{await moveOut(world,data,q);}catch{}   // retried next tick; nothing else is changed for a failed save
    }
  }finally{L.ticking=false;}
}

// ------------------------------------------------------------------ snapshot
/** The `oxQuiz` field of a snapshot for players in the Theme Park or the arena; null elsewhere. No pending answer is exposed. */
export function oxQuizSnapshot(world,p){
  if(!p||![Q.arena,Q.lobby].includes(p.map))return null;
  const data=oxQuizData(world);if(!data)return {available:false};
  const L=live(world),s=L.session,r=s?.participants.get(p.id)||null;
  const out={available:true,map:p.map,open:L.open,channel:(p.channel??0)===data.channel,rounds:data.rounds,maxUser:data.max,gm:!!p.gmAuthorized,
    round:s?.round||0,phase:s?.phase||'idle',automatic:false,deadline:null,rewardError:null,wall:{state:s?.wall.state||'down',at:s?.wall.at||0,uid:data.wall.uid,brick:data.wall.brick,x:data.wall.x,z:data.wall.z,dir:data.wall.dir,footprintDir:data.wall.footprintDir,w:data.wall.w,h:data.wall.h},
    survivors:s?survivors(s):0,maxCount:s?s.participants.size:0,mine:r?{participant:true,dropout:r.dropout,reason:r.reason}:null,last:L.last};
  if(s?.phase==='question'&&s.question)out.question={index:s.question.index,text:s.question.question};
  if(s?.phase==='solution'&&s.question)out.solution={answer:s.question.answer,text:s.question.solution};
  return out;
}
