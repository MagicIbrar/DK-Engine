import {UIEffects} from '../dungeons/uifx.js';
import {loadData,D,sysText} from '../dungeons/data.js';import {DungeonUI} from '../dungeons/ui.js';import {EventDialog} from '../events/dialog.js';import {Brick,footprintCells} from '../dungeons/bricks.js';import {Trigger} from '../dungeons/triggers.js';import {NPC} from '../../actors/npc.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';
import {applyDungeonArrivalView} from './dungeon-arrival.js';
import {dungeonGatePlacement} from '../../config/engine-chosen-karin-dungeon-gates.js';
import {urbanWarfareRequiresAdmission} from '../events/urban-warfare-routes.js';
import {installFrontierTicket} from './frontier-ticket.js';
/** Keep ticket quests and other original services on the ordinary NPC menu. */
export function dungeonNpcHasOtherServices(game,npc){
 if(npc?.sharedDungeonIds||npc?.isTrigger)return false;
 const id=Number(npc?.npcIndex??npc?.def?.index),db=game.quests?.db;
 if([db?.byGiver,db?.byTurnIn,db?.byTalk].some(index=>index?.has(id)))return true;
 return (npc?.def?.jobs||npc?.jobs||[]).some(([job])=>![19,45,58,34].includes(Number(job))&&Number(job)>0);
}
export async function installSharedDungeons(game,network){
 await loadData();const sys={game},ui=new DungeonUI(sys),effects=new UIEffects(game);ui.register();const dialog=game.sharedNpcDialog||=new EventDialog(game),objects=new Map(),gates=[],pending=[],channelAudio=new Map();let generation=0,loading=0,current=null,gateMap=null,audioDisposed=false;
 const send=input=>network.action('dungeon',input);const report=error=>game.chat?.system?.(error.message,'err');
 const page=(npc,record,path=[])=>({title:npc.name||'Dungeon',text:record.text,options:record.options.map((o,index)=>({label:o.label,pick:()=>{void send({operation:'npc',npc:Number(npc.npcIndex),path:[...path,index]}).then(result=>{if(result?.dialog)void dialog.show(page(npc,result.dialog,[...path,index]));}).catch(report);}}))});
 const enter=(id,npc)=>send({operation:'enter',dungeonId:String(id),npc:Number(npc?.npcIndex??npc?.def?.index)||4001});
 const opening=(npc,service=false)=>{if(npc?.isTrigger&&npc.serverTriggerId){void send({operation:'trigger',trigger:npc.serverTriggerId}).catch(report);return true;}if(current&&D.dg.maps[current.map]?.scriptNpcs.some(n=>n.npc===Number(npc?.npcIndex))){void send({operation:'npc',npc:Number(npc.npcIndex),path:[]}).then(result=>{if(result?.dialog)void dialog.open(npc,page(npc,result.dialog));}).catch(report);return true;}
 if(!service&&dungeonNpcHasOtherServices(game,npc))return false;
 const ids=npc?.sharedDungeonIds||(npc?.def?.jobs||npc?.jobs||[]).filter(([job,id])=>[19,45,58,34].includes(Number(job))&&D.dg.dungeons[String(id)]).map(([,id])=>String(id));if(!ids.length)return false;void dialog.open(npc,{title:npc.name,text:ids.map(id=>{const d=D.dg.dungeons[id];return `${d.title||d.name}\n${d.mission||''}`;}).join('\n\n'),options:ids.map(id=>({label:`Enter ${D.dg.dungeons[id].title||D.dg.dungeons[id].name}`,pick:()=>{dialog.close();void enter(id,npc).catch(report);}}))});return true;};
 const open=game.windows?.openNpc?.bind(game.windows);if(open)game.windows.openNpc=npc=>opening(npc)?null:open(npc);
 const register=()=>{for(const key of [19,45,58,34])game.npcServices?.register?.(key,npc=>opening(npc,true));};register();game.events?.on?.('systems',register);
 let releaseMask=null;
 const mask=record=>{releaseMask?.();releaseMask=null;const col=game.world?.collision;if(!col)return;const cells=[];for(const row of record.bricks||[]){if(row.removed)continue;const def=D.dg.bricks[row.brick];if(def)for(const cell of footprintCells(game.world,row.x,row.z,row.dir,def.size))cells.push(cell.i);}releaseMask=blockCollisionCells(col,cells);};
 const clear=()=>{stopInvalidChannelAudio();generation++;pending.length=0;releaseMask?.();releaseMask=null;for(const b of objects.values()){const list=b.isTrigger?game.npcs:game.spawner?.monsters;const index=list?.indexOf(b)??-1;if(index>=0)list.splice(index,1);b.unblock?.();b.dispose();}objects.clear();current=null;gateMap=null;if(game.sharedDungeons)game.sharedDungeons.monsterCount=null;ui.hideAll();};
 function gatesFor(map){for(const gate of gates.splice(0)){const index=game.npcs.indexOf(gate);if(index>=0)game.npcs.splice(index,1);gate.dispose();}gateMap=map;const points=new Map();for(const[id,d]of Object.entries(D.dg.dungeons)){const fallback=d.entry?.fallback;if(!fallback||Number(fallback.map)!==map||id.startsWith('m')||['EVENT','COLOSSEUM','PARTYMATCH','GUILD','SQUARE'].includes(d.keeper)||d.solo?.pvpOnly||d.missingFloors?.length||d.floors?.some(urbanWarfareRequiresAdmission))continue;const at=dungeonGatePlacement(fallback,id),key=`${at.x}:${at.y}`;if(!points.has(key))points.set(key,{at,ids:[]});points.get(key).ids.push(id);}for(const {at,ids}of points.values())pending.push({gate:true,map,at,ids});}
 const bridge=game.sharedDungeons={sync(record){const map=Number(game.world?.info?.index);if(!record||record.kind!=='dungeon'||record.map!==map){if(current)clear();if(gateMap!==map)gatesFor(map);return;}if(current?.id!==record.id||current.map!==map){clear();bridge.arrivalView=applyDungeonArrivalView(game);sys.director=record;ui.alarm(true);void ui.openInfo();}current=record;sys.director=record;const dungeon=D.dg.dungeons[record.dungeonId];ui.setInfo({title:dungeon.title||dungeon.name,mission:dungeon.mission,time:dungeon.timeLimit?.text,missions:record.missions});ui.setTimers([{caption:record.phase==='countdown'?'Dungeon Starting':record.phase==='cleared'?'Transfer Time':'Running Time',sec:record.remainingMs/1000}]);
 if(Number.isSafeInteger(record.remainingMonsters)&&record.phase==='running'){if(bridge.monsterCount!==record.remainingMonsters){bridge.monsterCount=record.remainingMonsters;ui.count(record.remainingMonsters,sysText(118));}}else if(bridge.monsterCount!=null){bridge.monsterCount=null;game.uiwin?.close?.('dungeon_count');}
 mask(record);for(const row of record.bricks||[]){const key=`b:${row.uid}`,b=objects.get(key);if(b){b.hp=row.hp;b.maxHP=row.maxHp;if(row.removed&&!b.open&&!b.dead){b.open=true;b.dead=row.animation==='die';b.unblock();b.play(row.animation||'open',{loop:false});if(b.dead)b.group.visible=false;}}else if(!row.removed&&!pending.some(p=>p.key===key))pending.push({key,row,kind:'brick'});}
 for(const row of record.triggers||[]){const key=row.uid,t=objects.get(key);if(t){if(t.tstate!==row.tstate){t.tstate=row.tstate;t.play('change',{loop:false});}t.locked=row.locked;t.opened=row.opened;}else if(!pending.some(p=>p.key===key))pending.push({key,row,kind:'trigger'});}
 },update(dt){effects.update(dt);for(const b of objects.values())b.update(dt);while(loading<2&&pending.length){const job=pending.shift(),version=generation;let actor;if(job.gate){if(game.world?.info?.index!==job.map)continue;const def=game.data?.npcs?.npcs?.[4001];if(!def)continue;const point=job.at,at=game.world.collision?.nearestWalkable(point.x+(point.relocated?.5:2.5),point.y+.5,6);if(!at)continue;actor=new NPC(game,{...def,index:4001,jobs:job.ids.map(id=>[19,Number(id)]),roles:['DUNGEON'],name:D.dg.dungeons[job.ids[0]].title||D.dg.dungeons[job.ids[0]].name||def.name},{npcIndex:4001,...at});actor.sharedDungeonIds=job.ids;gates.push(actor);game.npcs.push(actor);}else{if(!current)continue;const row=job.kind==='brick'?current.bricks?.find(row=>row.uid===job.row.uid&&!row.removed):current.triggers?.find(row=>row.uid===job.row.uid);if(!row)continue;if(job.kind==='brick'){actor=new Brick(game,D.dg.bricks[row.brick],{uid:row.uid,brick:row.brick,x:row.x,y:row.z,dir:row.dir});actor.networkId=`brick:${current.id}:${row.uid}`;actor.hp=row.hp;actor.maxHP=row.maxHp;if(actor.breakable)game.spawner?.monsters?.push(actor);}else{actor=new Trigger(game,D.dg.triggers[row.trigger],{trigger:row.trigger,x:row.x,y:row.z,dir:row.dir},current.map);actor.serverTriggerId=row.uid;actor.tstate=row.tstate;actor.locked=row.locked;actor.opened=row.opened;game.npcs.push(actor);}objects.set(job.key,actor);}loading++;void actor.load().then(()=>{if(version!==generation||job.gate&&job.map!==game.world?.info?.index)actor.dispose();}).catch(error=>{actor.dispose();report(error);}).finally(()=>loading--);}},dispose(){audioDisposed=true;clear();effects.dispose();for(const g of gates)g.dispose();}};
 network.dungeonActor=id=>[...objects.values()].find(actor=>actor.networkId===id);
 // SharedWorld applies self before dispatching snapshot events, and this bridge
 // syncs the instance afterwards. Use canonical self here so the entry cue in
 // that first snapshot is not discarded while current is still null.
 const playAudio=event=>{
  const world=game.world,map=Number(event.map),instanceId=event.instanceId,channelId=event.channelId;
  let lifetime=null;
  const sceneCurrent=()=>!audioDisposed&&!network.disposed&&!!instanceId&&network.self?.instanceId===instanceId&&Number(network.self?.map)===map&&game.world===world&&Number(world?.info?.index)===map;
  const isCurrent=()=>sceneCurrent()&&(!lifetime||channelAudio.get(channelId)===lifetime&&lifetime.valid());
  if(!isCurrent()||!Array.isArray(event.sound))return;
  const sound=event.sound.map(Number),a=game.audio,S=game.data?.sound;
  if(!a||!sound.every(Number.isSafeInteger))return;
  if(event.type==='dungeon:sound'){
   const [cate,id,code3,code4]=sound;
   if(sound.length!==4||cate!==22)return;
   // build-sound preserves exact soundscript codes: zero/zero uses plain id.
   const key=code3||code4?`${id}:${code3}:${code4}`:String(id),list=S?.system?.[key]?.sfx;
   if(Array.isArray(list)&&list.length){
    if(channelId){
     if(event.channelKind!=='dungeon'||event.actorId!==network.self?.id||channelAudio.has(channelId))return;
     lifetime={map,instanceId,actorId:event.actorId,handles:new Set(),valid:()=>sceneCurrent()&&network.self?.id===event.actorId&&(!event.origin||Math.hypot(Number(network.self?.x)-event.origin.x,Number(network.self?.z)-event.origin.z)<=.1)};
     channelAudio.set(channelId,lifetime);
    }
    void Promise.resolve(a.playAll?.(list,{category:'effect',isCurrent,onHandle:handle=>{if(!handle||!lifetime)return;if(isCurrent())lifetime.handles.add(handle);else handle.stop?.();}})).catch(error=>{if(lifetime)stopChannelAudio(channelId);report(error);});
   }
  }else{
   const [mode,id]=sound;
   if(sound.length!==2||![0,1].includes(mode))return;
   if(mode===0){if(S?.bgmByMapIndex?.[String(id)]?.some(r=>r.path&&!r.missing))a.playBGM?.(id);}
   else a.playBGM?.(map);
  }
 };
 function stopChannelAudio(id,completed=false){const life=channelAudio.get(id);if(!life)return;channelAudio.delete(id);for(const handle of life.handles)if(!completed||handle.voice?.stateBound)handle.stop?.();}
 function stopInvalidChannelAudio(){for(const[id,life]of channelAudio)if(!life.valid())stopChannelAudio(id);}
 const previousEvent=network._event.bind(network);network._event=event=>{if(event.type==='dungeon:effect')void effects.play(event.effect,event.durationMs);else if(event.type==='dungeon:sound'||event.type==='dungeon:jingle'){try{playAudio(event);}catch(error){if(event.channelId)stopChannelAudio(event.channelId);report(error);}}else if(event.type==='dungeon:sound-stop'){const life=channelAudio.get(event.channelId);if(life&&life.map===Number(event.map)&&life.instanceId===event.instanceId&&life.actorId===event.actorId)stopChannelAudio(event.channelId,event.completed===true);}else previousEvent(event);};
 const snapshot=network._snapshot.bind(network);network._snapshot=record=>{if(network.disposed||Number(record?.sequence)<network.sequence)return;snapshot(record);stopInvalidChannelAudio();bridge.sync(record?.instance);};const leave=network.leave.bind(network);network.leave=options=>{bridge.dispose();return leave(options);};
 game.dungeons||={};Object.assign(game.dungeons,{ready:Promise.resolve(D),enter:id=>enter(id,null),leave:()=>send({operation:'exit'}),info:id=>D.dg.dungeons[String(id)],current:()=>current});
 installFrontierTicket(game,network,bridge);return bridge;
}

