import {AuthoritativeInventory} from './inventory.mjs';
import {serializeLife,commitLife} from './life-transactions.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {mapFor} from './scene.mjs';
import {isDkChannel} from './channels.mjs';
import {ownedLifeBead} from '../../src/systems/items/life-bead-rules.js';
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};

// Shared with the public death-window availability field. This is the bounded
// engine admission policy, not an inferred native permission for special modes.
export function lifeBeadReviveAllowed(world,p){
 const map=p?.map,info=world.data.dungeonData?.dg?.maps?.[map];
 const chaos=p?.profile?.life?.grade?.chaotic??0,band=world.data.pkData?.chaotic?.find(r=>chaos>=r.start&&chaos<=r.end);
 // Native forced location15 must not be bypassed by an unproven bead exception.
 // No blanket Niete prohibition:20:398/399 do not state one. This conservative
 // scope policy leaves that exception unavailable pending native server proof.
 if(!Number.isFinite(chaos)||chaos<0||chaos>0&&(!band||Number(band.respawn)>0))return false;
 return !!p&&!!info&&['field','system'].includes(info.kind)&&!info.flags?.siege
  &&!p.instanceId&&!p.profile?.instance&&!p.profile?.dkReturn&&!world.data.requiresInstance?.(map)&&!isDkChannel(p.channel)
  &&!world.data.eventData?.modeOf(map)&&!world.data.customMaps?.has?.(map)&&!p.customMapPending
  &&!p.arenaId&&!p.dkSquareId&&!p.colosseumId&&!p.partyPvpId&&!p.trainingCampId&&!p.duelId&&!p.pvpRestore
  &&!p.raceRun&&!p.tradeId&&!p.charTradeId&&!p.pcShopOpen&&!p.smartWarp&&!p.mount&&!p.fishing
  &&!p.sceneTransition&&!p.progressCommitting&&!p.tradeCommitting;
}

/** Optional original death-window item intent. Core must retain its PvP/event
 * guards and ten-second timer before dispatch. No uid retains ordinary revival.
 * Initially supported on native ordinary field scenes; event/instance policy
 * needs its own authenticated native scope rather than bypassing those rules.
 */
export async function reviveWithLifeBead(world,p,input,authorize){
 if(!Object.hasOwn(input,'uid'))return false;
 if(typeof input.uid!=='string'||!input.uid)fail('Choose one owned native Life Bead by its inventory identity.');
 if(typeof authorize!=='function'||typeof world.serializeAccount!=='function')fail('Life Bead revival authority is unavailable.',503);
 return world.serializeAccount(p.account,()=>serializeLife(p,async()=>{
  const token=p.token,map=p.map,channel=p.channel??0;
  const check=()=>{
   authorize();
   if(world.players.get(p.account)!==p||p.token!==token||p.profile?.authority!=='server'||p.profile.id!==p.characterId||p.leaving||p.revoked||p.sceneTransition||p.progressCommitting||p.tradeCommitting||!p.dead||p.hp>0||p.map!==map||(p.channel??0)!==channel)fail('The original revival scope changed.',409);
   if(Number.isFinite(p.respawnReadyAt)&&world.now()<p.respawnReadyAt)fail('Wait for the original revival countdown.');
   if(!lifeBeadReviveAllowed(world,p))fail('Life Bead revival is unavailable in this battle scope.');
   const scene=mapFor(world,p);if(!scene?.isWalkable?.(p.x,p.z))fail('No safe original revival point is available.',503);
  };
  check();
  const owned=ownedLifeBead(p.profile,world.data.itemDB,input.uid,world.now());if(!owned)fail('Choose one owned, unexpired native Life Bead from your bag.');
  const {item,rule}=owned,ready=p.profile.lifeBeadReadyAt??0;
  if(!Number.isSafeInteger(ready)||ready<0)fail('The saved Life Bead cooldown is invalid; item preserved.',503);
  if(rule.cooldown>0&&world.now()<ready)fail('The Life Bead is cooling down.');
  const before=structuredClone(p.profile),profile=structuredClone(before),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  const entry=inv.bag.byUid(item.uid);if(!entry||!inv.consumeEntry(entry,1))fail('The chosen Life Bead is unavailable.');
  if(rule.cooldown>0)profile.lifeBeadReadyAt=world.now()+rule.cooldown;
  progressDekaPass({...world,changed(){}},{...p,profile},5,34,item.itemIndex,1);
  const passives=p._skills?.engine?.passiveEntries?.()||[];
  const stats=world.data.stats({...profile,buffs:[...(profile.buffs||[]),...passives]},p,world.now()),hp=Math.max(1,Math.round(stats.maxHp*rule.hp/100)),mp=Math.round((stats.maxMp||0)*rule.mp/100);
  check();
  const result=await commitLife(world,p,profile,{stats,hp,mp,shield:p.shield,revive:true,vitalDeltas:{hp,mp:mp-(p.mp||0)},profileBefore:before,rewardProgress:true});
  p.path=[];p.attackTarget=null;delete p.respawnReadyAt;world.snapshotPublicRows?.delete(p);
  for(const [at,event]of result.notices)world.emit(at,event);
  world.emit(p.map,{type:'itemuse',actorId:p.id,itemIndex:item.itemIndex,instanceId:null,revive:true});
  world.emit(p.map,{type:'revive',actorId:p.id,instanceId:null});return true;
 }));
}
