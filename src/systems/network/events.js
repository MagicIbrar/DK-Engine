import {loadEventData} from '../events/data.js';
import {registerEventActors} from './event-actors.js';
import {EventUI} from '../events/windows.js';
import {EffectBanners} from '../events/effectui.js';
import {createSharedEventAnnouncer} from './event-announcements.js';
import {createEventPresentation} from './event-presentation.js';
import {createSharedEventTimers} from './event-timers.js';
import {createSharedEventMessages} from './event-messages.js';
import {EventDialog} from '../events/dialog.js';
import {Brick,eventBrickFootprintCells} from '../events/bricks.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';
import {urbanWarfareUnavailableText} from '../events/urban-warfare-routes.js';
import {installSharedOxQuiz} from './ox-quiz.js';
import {installSharedSiegeRenew} from './siege-renew.js';
import {installSharedZuto} from './zuto.js';
import {installSharedPhantomCastle} from './phantom-castle.js';

// A Dead Front snapshot contains every barrier on a 512-cell map. The native
// entrance gates are appended after the initial barriers, so FIFO loading can
// leave the gate beside a newly arrived player invisible for many asset loads.
export function nextVisibleEventBrick(pending, rows, player, phase, radius = 120) {
 const x=Number(player?.x),z=Number(player?.z),positioned=Number.isFinite(x)&&Number.isFinite(z);
 let best=null,score=Infinity;
 for(const row of rows||[]){
  if(!pending.has(row.uid)||row.removed)continue;
  const distance=positioned?(Number(row.x)-x)**2+(Number(row.z)-z)**2:0;
  if(positioned&&distance>radius*radius)continue;
  const entrance=phase==='waitStart'&&row.uid>=101&&row.uid<=104;
  const priority=positioned?distance:(entrance?-1:0);
  if(priority<score){best=row;score=priority;}
 }
 return best;
}

// Server-only event intents and original visual assets. No local phase/reward director runs here.
export function installSharedEvents(game,network){
 const bridge=game.sharedEvents={data:null,instance:null,bricks:new Map(),loading:0,pending:new Set(),generation:0};
 const dialog=game.sharedNpcDialog||=new EventDialog(game),ui=new EventUI(game,bridge),presentation=createEventPresentation(game,network,ui),timers=createSharedEventTimers(game,network,ui,()=>bridge.data),messages=createSharedEventMessages(game,network,ui,bridge);let latest=null,releaseMask=null,maskedCollision=null,announcer=null;
 const ready=loadEventData().then(data=>{bridge.data=data;announcer=createSharedEventAnnouncer(game,ui,new EffectBanners(game,bridge),data);sync(latest);return data;}).catch(error=>game.chat?.system?.(error.message,'err'));
 const action=async input=>{const result=await network.action('event',input);return result;};
 const pageFor=(npc,record,path=[])=>({title:npc.name||'Event',text:record.text,options:(record.options||[]).map((o,index)=>({label:o.label,pick:()=>{void action({operation:'npc',npc:Number(npc.npcIndex??npc.def?.index),path:[...path,index]}).then(next=>{if(next?.dialog&&(next.dialog.text||next.dialog.options?.length))void dialog.show(pageFor(npc,next.dialog,[...path,index]));else if(next)dialog.close();}).catch(error=>game.chat?.system?.(error.message,'err'));}}))});
 const open=npc=>{
  const id=Number(npc?.npcIndex??npc?.def?.index),data=bridge.data;if(!data)return false;
  const officer=data.officerByNpc.get(id);
  if(officer){const mode=officer.mode==='deadFront'?'Dead Front':'Ice Castle',field=data.field(officer.mode,officer.map),itemCode=Number(field?.itemCode)||0;if(!field)return false;void dialog.open(npc,{title:npc.name,text:`${mode} • Shared cooperative instance\nOriginal level range: ${(field.entryLevel||field.level).join('–')}\n${itemCode>0?`Each member needs: ${data.itemName(itemCode)}`:'No admission item is required by this field.'}\nApply alone or as party leader. Selected entrants may enter during the entry window.`,options:[{label:`Apply for ${mode}`,pick:()=>{dialog.close();void action({operation:'record',map:officer.map,npc:id}).then(result=>{if(result?.applied===true)game.chat?.system?.('Event application recorded.','sys');}).catch(error=>game.chat?.system?.(error.message,'err'));}},{label:`Enter ${mode}`,pick:()=>{dialog.close();void action({operation:'enter',map:officer.map,npc:id}).catch(error=>game.chat?.system?.(error.message,'err'));}}]});return true;}
  if(bridge.instance&&data.map(bridge.instance.map)?.npcs.some(row=>Number(row[0])===id)){void action({operation:'npc',npc:id,path:[]}).then(result=>{if(result?.dialog)void dialog.open(npc,pageFor(npc,result.dialog));}).catch(error=>game.chat?.system?.(error.message,'err'));return true;}
  return false;
 };
 const oldOpen=game.windows?.openNpc?.bind(game.windows);if(oldOpen)game.windows.openNpc=npc=>open(npc)?null:oldOpen(npc);
 const register=()=>{for(const key of [37,38,98,99])game.npcServices?.register?.(key,npc=>open(npc));game.npcServices?.register?.(119,npc=>{dialog.close();if(game.sharedZuto?.stone?.(npc))return true;game.uiwin?.msgbox?.(urbanWarfareUnavailableText(bridge.data),{kind:'ok'});return true;});};register();game.events?.on?.('systems',register);
 const restore=()=>{releaseMask?.();releaseMask=null;maskedCollision=null;};
 const supported=row=>!!row.breakable&&[36818,36819].includes(Number(row.brick))&&typeof row.id==='string';
 const unpick=b=>{const list=game.spawner?.monsters,index=list?.indexOf(b)??-1;if(index>=0)list.splice(index,1);if(game.player?.target===b)game.controller?.setTarget?.(null);};
 const clear=()=>{bridge.generation++;for(const b of bridge.bricks.values()){unpick(b);b.dispose();}bridge.bricks.clear();bridge.pending.clear();restore();bridge.instance=null;ui.closeAll();};
 const mask=rows=>{restore();const col=game.world?.collision;if(!col?.cells)return;const cells=[];for(const row of rows){if(row.removed)continue;const def=bridge.data.brick(row.brick);if(!def)continue;for(const[x,z]of eventBrickFootprintCells(game.world?.info?.index,row,def)){if(x<0||z<0||x>=col.width||z>=col.height)continue;cells.push(z*col.width+x);}}releaseMask=blockCollisionCells(col,cells);maskedCollision=col;};
 function sync(record){if(record?.kind==='dungeon')record=null;latest=record;network.eventWar=record?.war||null;if(!bridge.data)return;if(!record||Number(game.world?.info?.index)!==record.map){if(bridge.instance)clear();return;}if(bridge.instance?.id!==record.id)clear();bridge.instance=record;mask(record.bricks||[]);for(const row of record.bricks||[]){const b=bridge.bricks.get(row.uid);if(b){b.hp=row.hp??b.hp;b.maxHp=row.maxHp??b.maxHp;b.dead=!!row.dead;b.breakable=supported(row)&&record.phase==='fortress'&&record.won==null&&!row.removed&&!b.dead;b.kind=b.breakable?'monster':'brick';if(b.breakable&&!game.spawner?.monsters?.includes(b))game.spawner?.monsters?.push(b);else if(!b.breakable)unpick(b);}if(b&&row.removed&&!b.removed){b.removed=true;b.play(row.animation||'open',{loop:false,onEnd:row.animation==='die'&&supported(row)?()=>setTimeout(()=>{if(!b.disposed)b.group.visible=false;},400):undefined});if(row.animation==='die'&&!supported(row))b.group.visible=false;}else if(!b&&!row.removed)bridge.pending.add(row.uid);}
  const war=record.war&&record.war.teams?.length>1?record.war:null,rank=war?(war.place??[...war.teams].sort((x,y)=>y.score-x.score||x.index-y.index).findIndex(t=>t.index===war.team)+1):'';void ui.partyInfo(record.score??0,rank||'');if(record.towerHp!=null)void ui.tower(record.towerHp/100);
 }
 game.chat?.registerCommand?.('/leaveinstance',()=>{if(bridge.instance)void action({operation:'exit'}).catch(error=>game.chat?.system?.(error.message,'err'));return true;},'Leave the current server instance.');
 // Shared Game skips the local spawner loop; this bridge owns every event brick visual update, including picked actors.
 bridge.update=dt=>{if(latest&&bridge.data&&Number(game.world?.info?.index)===latest.map&&game.world?.collision!==maskedCollision)sync(latest);messages.update(dt);timers.update();ui.update(dt);announcer?.update(dt);for(const b of bridge.bricks.values())b.update(dt);while(bridge.loading<2&&bridge.pending.size){const row=nextVisibleEventBrick(bridge.pending,bridge.instance?.bricks,game.player,bridge.instance?.phase);if(!row)break;const uid=row.uid;bridge.pending.delete(uid);const def=bridge.data.brick(row.brick);if(!def)continue;const generation=bridge.generation,b=new Brick(game,def,row);b.breakable=supported(row)&&bridge.instance.phase==='fortress'&&bridge.instance.won==null;b.kind=b.breakable?'monster':'brick';b.brain=null;b.networkId=row.id||null;b.hp=row.hp??b.hp;b.maxHp=row.maxHp??b.maxHp;b.maxHP=b.maxHp;b.isBrick=true;b.dead=!!row.dead;if(b.breakable)game.spawner?.monsters?.push(b);bridge.bricks.set(uid,b);bridge.loading++;void b.load().then(()=>{if(generation!==bridge.generation){unpick(b);b.dispose();}}).catch(()=>{unpick(b);b.dispose();if(bridge.bricks.get(uid)===b)bridge.bricks.delete(uid);}).finally(()=>bridge.loading--);}};
 const originalSnapshot=network._snapshot.bind(network);network._snapshot=snapshot=>{if(network.disposed)return;if(Number(snapshot?.sequence)<network.sequence){originalSnapshot(snapshot);return;}presentation.snapshot(snapshot);messages.snapshot(snapshot?.instance);originalSnapshot(snapshot);announcer?.consume(snapshot?.eventAnnouncements);sync(snapshot?.instance||null);messages.update(0);timers.snapshot(snapshot);for(const channel of snapshot?.instance?.channels||[])presentation.event(channel);if(snapshot?.instance?.result)presentation.event(snapshot.instance.result);};const originalEvent=network._event.bind(network);network._event=event=>{if(presentation.event(event)||messages.event(event))return;if(event.type==='event:message')game.chat?.system?.(event.text,'sys');else originalEvent(event);};
 const releaseActor=registerEventActors(network,'shared-events',id=>{for(const b of bridge.bricks.values())if(b.networkId===id&&!b.disposed)return b;return null;});
 bridge.dispose=()=>{releaseActor();messages.dispose();timers.dispose();presentation.dispose();announcer?.dispose();clear();ui.closeAll();};const leave=network.leave.bind(network);network.leave=options=>{bridge.dispose();return leave(options);};
 bridge.ready=ready;bridge.openNpc=open;game.eventsSystem={ownsMap:m=>['deadFront','iceCastle'].includes(bridge.data?.modeOf(m)),get run(){return bridge.instance;}};
 installSharedOxQuiz(game,network,{bridge,dialog,ui});
 installSharedSiegeRenew(game,network,{bridge,dialog});
 installSharedZuto(game,network,{bridge});   // owner-directed Zuto adaptation: registration line, stone seize, notices
 installSharedPhantomCastle(game,network,{bridge,dialog});
 return bridge;
}
