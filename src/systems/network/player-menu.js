import {installPcPop} from '../pvp/duel.js';
import {needStrings,str} from '../hud-options/util.js';
import {onOxMap,partyWarMap} from '../pvp/pk-channel.js';

// Native pcpop 240 rows only: Global PcPopWnd builds rows 240:0..13 and has no
// messenger 1006 rows (lane 62, docs/global-parity-420/PLAYER-CARD-PARITY.md).
// NPC players use exactly the same routes and host permission guards as humans.
export function installSharedPlayerMenu(game,network) {
 if(network._socialPlayerMenu)return network._socialPlayerMenu;
 const pop=installPcPop(game),valid=t=>!!network.active&&!!network.ready&&!network.disposed&&t?.kind==='player'&&t!==game.player&&!t.disposed&&!!t.networkId&&(!network.players?.get||network.players.get(t.networkId)===t);
 const party=()=>network.party||game.party?.serverState||{},leader=()=>!party().active||party().leaderId===network.self?.id;
 const report=error=>game.chat?.system?.(error?.message||String(error),'err');
 const run=fn=>t=>{if(!valid(t))return false;try{return Promise.resolve(fn(t)).catch(error=>{report(error);return false;});}catch(error){report(error);return false;}};
 const add=(code,visible,fn,cate=240,label=code)=>pop.add({code,cate,label,visible:t=>valid(t)&&visible(t),run:run(fn)});
 // Native 240:0 / action315 means this player follows the selected character.
 // ENGINE-CHOSEN near-body gap; ordinary approach owns pathing, speed, stops,
 // manual-input/skill cancellation and host movement validation.
 const followRange=.15;
 const scene=()=>JSON.stringify([network._actorScene,network.self?.map,network.self?.instanceId,network.self?.channel]);
 const canFollow=t=>valid(t)&&!t.dead&&!game.player?.dead&&!network.self?.dead&&!network.pcShop?.open&&!game.skills?.busy&&!!game.controller?.approach&&Number.isFinite(t.x)&&Number.isFinite(t.z);
 const follow=(t,{valid:guard}={})=>{
  if(!canFollow(t)||guard&&!guard())return false;
  const c=game.controller,p=game.player,at=scene();let settled=false;
  c.stop?.();c.setTarget?.(t);
  c.approach(t,followRange,()=>{if(!settled){settled=true;network.stop?.();}},{valid:()=>{
   if(!valid(t)||guard&&!guard()||p!==game.player||at!==scene()||p.target!==t||t.dead||network.pcShop?.open)return false;
   if(Math.hypot(p.x-t.x,p.z-t.z)>followRange+(t.radius||0.5)*0.9+.35)settled=false;
   return true;
  }});
  // Resume this same finite order after reaching the gap. No recursive calls,
  // repeated orders, background timer or chat commands while the target rests.
  const order=c.order;if(!order||order.type!=='approach'||order.target!==t)return false;
  order.resume=order;return true;
 };
 // Party HUD uses this same selected-player movement route; it performs its
 // own current membership/authoritative scene checks before requesting follow.
 network.playerFollow={canFollow,follow};
 add(0,canFollow,follow);
 game.events?.on?.('keyaction',a=>{if(a?.id==='follow')follow(game.player?.target);});
 const say=(text,kind='sys')=>{const s=String(text||'').replace(/<[^>]+>/g,'').trim();if(s)game.chat?.system?.(s,kind);return false;};
 add(1,()=>!!game.life?.friends?.add,t=>game.life.friends.add(t.name));
 // 240:2: Global hides Trade on a party-war map (Minimap -> LogicObject::PartyWar::Provider map check) and refuses
 // on the OX Quiz map with SYSTEM 101:167 (pk-channel.js). The host still owns every trade rule.
 add(2,()=>!!game.trade?.request&&!partyWarMap(game,network),t=>onOxMap(network)?say(str(101,167,'SYSTEM'),'err'):game.trade.request(t.networkId));
 add(3,()=>!!game.chat?.openInput,t=>game.chat.openInput(`"${t.name} `));
 // 240:4 / 240:6 / 240:7 / 240:9 / 240:12: Global builds these rows for every player target; the host refuses
 // what the caller may not do (leader, guild master, alliance commander checks stay server side).
 add(4,()=>!!game.party?.command,async t=>{
  if(!party().active&&!(await game.party.command('create')))return false;
  return game.party.command('invite',{targetId:t.networkId});
 });
 add(6,()=>!!game.life?.guild?.inviteName,t=>game.life.guild.inviteName(t.name));
 // 240:7 Alliance = Global InviteAlliance (the host's allianceInvite names the target, who must be a guild master).
 add(7,()=>!!game.alliance?.invite,t=>game.alliance.invite(t.name));
 // 240:9 Block = Global RequestBlackList (Messenger blacklist add); the result is the host's 1006 code.
 add(9,()=>!!game.blacklist?.add,async t=>{const r=await game.blacklist.add(t.name),m=/^(\d+):(\d+)$/.exec(String(r?.code||''));if(m)say(str(Number(m[1]),Number(m[2])).replace(/%s/g,t.name),r?.ok===false?'err':'sys');return r?.ok!==false;});
 // 240:10 "Shut Out(Expansion)": Global sends the Expedition (troop) invite from this row, shown only to the
 // expedition leader (Troop::Reference: has a troop and self id == troop leader id).
 add(10,()=>!!game.life?.expedition?.isLeader,async t=>{const ok=await game.life.expedition.command('invite',{targetId:t.networkId});if(ok)say(str(555,27).replace(/%s/g,t.name));return ok;});   // 555:27 after the send, as Global RequestTroop
 // 240:11 "Expedition" = Global RequestCharTrade (Character Transfer): added by chartrade/index.js (MENU.order 11).
 // 240:12 Report = Global AutoReport after the 80:46 / 81:46 confirm box (server/world/auto-report.mjs).
 add(12,()=>!!game.uiwin?.msgbox,async t=>{
  const yes=await game.uiwin.msgbox(str(81,46),{title:str(80,46),kind:'yesno'});
  if(yes!=='yes'||!valid(t))return false;
  try{return !!(await network.action('autoreport',{targetId:t.networkId}));}catch{return false;}   // an older host has no autoreport route
 });
 void needStrings([0,1,2,3,4,6,7,9,10,12].map(n=>['NORMAL',240,n]).concat([['NORMAL',80,46],['NORMAL',81,46],['NORMAL',555,27],['SYSTEM',101,167]])).catch(()=>{});
 network._socialPlayerMenu=pop;return pop;
}
