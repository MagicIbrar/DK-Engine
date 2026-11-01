import {Travel,sysTextSmart} from '../dungeons/travel.js';
import {installPersonalPortal,personalPortalClientState} from './personal-portal.js';
import {DungeonDialog} from '../dungeons/dialog.js';
import {loadData,D,mapInfo} from '../dungeons/data.js';
import {installSharedChannels} from './channels.js';
import {installSharedGuildWarHunting} from './guild-war-hunting.js';
import {installSharedGuildTournament} from './guild-tournament.js';
import {installSharedObserver} from '../observer/observer.js';
import {installSharedArena} from '../arena/arena.js';
import {npcWarpText} from '../shops/premium-rules.js';
import {installSharedNavigation} from './navigation.js';
import {FRONTIER_MOVE} from '../extras/guildrank-rules.js';
import {COMBAT_TEXT} from '../../config/engine-chosen-pk.js';
const npcId=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index);
export class SharedTravel extends Travel{
 constructor(sys,network){super(sys);this.network=network;}
 mapNpcWarp(npcIndex,name=''){if(this._mapNpcPending||!this.network.active||!this.network.ready||!Number.isInteger(npcIndex))return false;this._mapNpcPending=true;void this._runMapNpc(npcIndex,name).catch(()=>this.game.hud?.log?.('NPC teleport failed.','sys')).finally(()=>{this._mapNpcPending=false;});return true;}
 async _runMapNpc(npcIndex,name=''){
  const game=this.game,network=this.network;game.controller?.stop?.();const begin=await network.action('mapnpcwarp',{operation:'begin',npcIndex}),cast=begin?.self?.smartWarp;if(!cast||cast.kind!=='mapnpc')return;
  const map=begin.self.map,started=performance.now(),ms=Math.max(5000,cast.readyAt-(begin.serverTime||Date.now()));let timer;
  try{timer=setInterval(()=>{if(!network.active||!network.ready||network.self?.map!==map||network.self?.smartWarp?.nonce!==cast.nonce)game.uiwin?.close?.('warpteleport','interrupted');},100);
   const ok=await this.cast('NPC Teleport','Teleporting to the selected map NPC...',ms);if(ok){const remaining=ms-(performance.now()-started);if(remaining>0)await new Promise(r=>setTimeout(r,remaining+1));}
   if(network.active&&network.ready){const done=await network.action('mapnpcwarp',{operation:ok?'finish':'cancel',nonce:cast.nonce});if(ok&&done)game.hud?.log?.(npcWarpText('done',name),'sys');}   // 101:171
  }finally{clearInterval(timer);}
 }
 go(){return this.network.unavailable('Use an original travel service or return item.');}
 _pay(){throw Error('Shared travel costs are server owned.');}
 teleportMenu(npc,table){this._npc={npcIndex:npcId(npc),table:Number(table),operation:'teleport'};return super.teleportMenu(npc,table);}
 skyTeleport(npc,table){this._npc={npcIndex:npcId(npc),table:Number(table),operation:'sky'};return super.skyTeleport(npc,table);}
 teleportTo(unit,route){
  const service=route?{npcIndex:Number(route.npc),table:Number(route.table),operation:'teleport'}:this._npc;
  if(!service||!Number.isInteger(service.npcIndex)||!Number.isInteger(service.table)||!this.network.active||!this.network.ready)return false;
  void this.network.action('npctravel',{...service,unit:Number(unit.unit)});return true;
 }
 setReturn(npc,table){void this.network.action('npctravel',{npcIndex:npcId(npc),operation:'bind',table:Number(table)}).then(result=>{
  if(!result)return;const text='The return point has been set.';this.sys.notice(text);this.game.uiwin?.msgbox?.(text,{kind:'ok'});
 });return true;}
 portalMenu(npc,table){
  const arrivals=new Map((D.tr?.portalArrivals||[]).map(r=>[r.map,r])),seen=new Set(),ret=this.returnTarget(),base={npcIndex:npcId(npc),operation:'portal',table:Number(table)};
  const menu=ret?[{text:`${mapInfo(ret.map)?.name||''} (Return Point)`,onClick:()=>this.network.action('npctravel',base)}]:[];
  const personal=personalPortalClientState(this.network);
  if(personal?.stage==='away')menu.unshift({text:`Return to Personal Portal (${mapInfo(personal.map)?.name||personal.map})`,onClick:()=>this.network.action('npctravel',{...base,operation:'personal-return',portalId:personal.id})});
  for(const p of D.tr?.portals||[]){const a=arrivals.get(p.map);if(!a||seen.has(p.map))continue;seen.add(p.map);menu.push({text:a.name||p.mapName,onClick:()=>this.network.action('npctravel',{...base,map:p.map})});}
  this.sys.dialog.open({title:npc?.name||'',text:'The return portal will teleport you to your last\nset Return point.',menu});return true;
 }
 returnToBind(){return this.network.unavailable('Use a return scroll from your inventory.');}
 siegeTeleport(){return this.network.unavailable('Siege admission');}
 scriptedWarp(){return this.network.unavailable('This scripted travel service');}
 /** 1641 "[Frontier Dungeon] Move." at Vascuda: an intent only (which Vascuda); the host checks the NPC, map, route and the guild's
  *  awarded Frontier rank (server/world/travel.mjs frontierMove) and refuses with 1641:100. */
 hideoutMove(npcIndex){if(!this.network.active||!this.network.ready||!Number.isInteger(npcIndex))return false;this.game.controller?.stop?.();void this.network.action('npctravel',{npcIndex,operation:'hideout'});return true;}
 frontierMove(npcIndex){if(!this.network.active||!this.network.ready||!Number.isInteger(npcIndex))return false;this.game.controller?.stop?.();void this.network.action('npctravel',{npcIndex,operation:'frontier'});return true;}
 async _runSmart(win,row){
  if(!row)return;this.game.controller?.stop?.();
  const begin=await this.network.action('smartwarp',{operation:'begin',rowId:Number(row.id)}),cast=begin?.self?.smartWarp;
  if(!cast)return;
  const ms=Math.max(3000,cast.readyAt-(begin.serverTime||Date.now()));
  const started=performance.now();
  const ok=await this.cast(sysTextSmart(win,0,this.game).replace(/<[^>]+>/g,''),sysTextSmart(win,14,this.game),ms);
  // The first UI update's dt can predate opening the cast window. Never let
  // that frame credit finish a server cast before its real minimum duration.
  if(ok){const remaining=ms-(performance.now()-started);if(remaining>0)await new Promise(resolve=>setTimeout(resolve,remaining+1));}
  const result=await this.network.action('smartwarp',{operation:ok?'finish':'cancel',nonce:cast.nonce});
  if(ok&&result)win.close();
 }
 _smartMove(win,k){return this._runSmart(win,win.control(`btn_move_${k}`).data.row);}
 _specialMove(win){return this._runSmart(win,win.data.row);}
}
export async function installSharedTravel(game,network){
 await loadData();
 const sys={game,itemCount:ids=>(game.save.inventory||[]).filter(i=>ids.includes(Number(i.itemIndex))).reduce((s,i)=>s+(Number(i.count)||1),0),notice:t=>game.hud?.log?.(t,'sys'),npcGreeting:n=>n?.name||''};
 sys.dialog=new DungeonDialog(sys);const travel=new SharedTravel(sys,network);sys.travel=travel;travel.install();
 installPersonalPortal(game,network,D.tr);
 installSharedNavigation(sys,network);
 game.dungeons||={};Object.assign(game.dungeons,{travel,returnToBind:()=>travel.returnToBind(),canUseReturnScroll:()=>mapInfo(game.world?.info?.index)?.flags?.returnScroll!==0&&!network.instance?.id});
 let services=null;
 const register=()=>{const s=game.npcServices;if(!s?.register||services===s)return;services=s;
  for(const [job,fn]of [[2,(n,j)=>travel.teleportMenu(n,j.jobIndex)],[4,(n,j)=>travel.setReturn(n,j.jobIndex)],[16,(n,j)=>travel.portalMenu(n,j.jobIndex)],[42,(n,j)=>travel.skyTeleport(n,j.jobIndex)]])s.register(job,(n,j)=>{game.uiwin?.close('npc');return fn(n,j);});
 };
 register();game.events?.on?.('systems',register);game.sharedTravel=travel;
 const event=network._event.bind(network);network._event=e=>{if(e.type==='frontierNotice'){if(e.text){game.chat?.system?.(e.text,'sys');sys.notice(e.text);}return;}event(e);};
 // Native talk-tree branch ends that are host travel services (src/systems/quests/dialog.js reads game.npcTreeActions).
 (game.npcTreeActions||=new Map()).set(`${FRONTIER_MOVE.quest}:${FRONTIER_MOVE.option}`,(npc,n)=>travel.frontierMove(Number(n)));
 // NPC jobs 96/97 DK_CHANNEL_ENTER/LEAVE are travel services too (network/channels.js).
 await installSharedChannels(game,network).catch(error=>console.warn('[network] DK channel portals unavailable',error));
 try{installSharedGuildWarHunting(game,network);}catch(error){console.warn('[network] Guild War Hunting unavailable',error);}
 try{installSharedGuildTournament(game,network,sys);}catch(error){console.warn('[network] Guild Tournament unavailable',error);}
 // OBSERVER: npc job 40 observer venues (src/systems/observer/observer.js, host server/world/observer.mjs).
 try{installSharedObserver(game,network);}catch(error){console.warn('[network] Observer mode unavailable',error);}
 try{installSharedArena(game,network);}catch(error){console.warn('[network] Arena battlefields unavailable',error);}
 // Official guide 62 battle status: no NPC use. The host refuses every NPC service (server/world/npc-service-guard.mjs); the client
 // mirrors it by not opening NPC windows while the server snapshot reports battle status (40:108). Re-wrapped when a later system
 // wraps openNpc, so this check stays outermost.
 guardNpcWindows(game,network);game.events?.on?.('systems',()=>guardNpcWindows(game,network));
 await game.uiwin?.open('smartwarp_alarm');return travel;
}
/** Server-reported battle status (self.battleStatusUntil, server clock) is still running. */
export function battleStatusBlocksNpc(network,now=globalThis.performance?.now?.()??Date.now()){
 const until=Number(network?.self?.battleStatusUntil);if(!network?.active||!Number.isFinite(until))return false;
 const c=network._serverClock,server=c&&Number.isFinite(c.time)?c.time+(now-c.at):Date.now();return server<=until;
}
export function guardNpcWindows(game,network){
 const w=game.windows;if(!w||typeof w.openNpc!=='function'||w.openNpc._battleStatusGuard)return false;
 const inner=w.openNpc.bind(w),guarded=npc=>{if(battleStatusBlocksNpc(network)){game.chat?.system?.(COMBAT_TEXT.service,'err');return null;}return inner(npc);};
 guarded._battleStatusGuard=true;w.openNpc=guarded;return true;
}
