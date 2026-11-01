import {installPcPop} from '../pvp/duel.js';
import {needStrings} from '../hud-options/util.js';

// Native pcpop240 row labels plus messenger1006 Talk/Send Message. The latter
// two rows reuse the native messenger actions in this menu (ENGINE-CHOSEN order).
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
 add(1,()=>!!game.life?.friends?.add,t=>game.life.friends.add(t.name));
 add(2,()=>!!game.trade?.request,t=>game.trade.request(t.networkId));
 add(3,()=>!!game.chat?.openInput,t=>game.chat.openInput(`"${t.name} `));
 add(3.1,()=>!!game.messenger?.openChat,t=>game.messenger.openChat(t.name),1006,5);
 add(3.2,()=>!!game.chat?.openInput,t=>game.chat.openInput(`"${t.name} `),1006,6);
 add(4,t=>!!game.party?.command&&leader()&&!(party().members||[]).some(p=>p.id===t.networkId),async t=>{
  if(!party().active&&!(await game.party.command('create')))return false;
  return game.party.command('invite',{targetId:t.networkId});
 });
 add(6,()=>!!game.life?.guild?.inviteName&&!!network.guild?.founded,t=>game.life.guild.inviteName(t.name));
 void needStrings([0,1,2,3,4,6].map(n=>['NORMAL',240,n]).concat([['NORMAL',1006,5],['NORMAL',1006,6]])).catch(()=>{});
 network._socialPlayerMenu=pop;return pop;
}
