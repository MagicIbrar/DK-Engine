// SiegeRenew guard deployment after the controller's native ladder
// (Lorenzo126, window701:213, guild701:203/204/205). This module applies
//   AUTHENTICATED: guard types SENTRY_INDEX 50001-50006 (700:95 "Incorrect guard index"), MAXSENTRY 100 per castle
//     (701:218 "All guards have been deployed."), SENTRY_UPGRADE_COST 100,000 DIL per guard (guide 32), no move / recall
//     (no such operation exists), reset when the defending guild changes (controller capture write);
//   RECOVERED: native alpha-mask 3x3 placement; approved master-carried DIL.
//   ENGINE-CHOSEN: shared100 pool, solid MAC/overlap safeguards, native-full-HP
//     survivor recreation and collision-safe1.5m warrior knockback.
// Durable: state.siegeRenew.castles[map].guards = [{id, sentry, x, z, guild, ref, at, cost}] written in ONE
// socialTransaction with the master's DIL debit. The controller then creates
// native actors; the core and skill adapter enforce attacker-only combat.
import {randomUUID} from 'node:crypto';
import {socialTransaction,socialRef} from './social-state.mjs';
import {guardPlacementRefusal} from '../../src/game/siege-renew-proposed-rules.js';
const refuse=([cate,code],status=409)=>{throw Object.assign(Error(`siege:${cate}:${code}`),{status,code:'SIEGE_RENEW_REFUSED'});};
const guildOfRef=(state,ref)=>Object.values(state?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref))||null;
export function siegeRenewGuardDataReady(world,sentry){
 const d=world.data.monsterDef?.(sentry);if(!d?.sentry||!d.ok||!(d.hp>0)||!Object.keys(d.attacks||{}).length)return false;
 return Object.keys(d.attacks).every(key=>{const r=d.attackResults?.[key];return r?.family==='damage'||r?.family==='projectile'&&r.impact?.family==='damage'&&!!world.data.skillFull?.remotes?.[r.remoteIndex];});
}

export async function deploySiegeRenewGuard(world,p,{scene,castle,cfg,input,check}){
  const sentry=Number(input.sentry),x=Number(input.x),z=Number(input.z),map=castle.map;
  if(!cfg.sentryIndexes.includes(sentry))refuse([700,95],400);
  if(!siegeRenewGuardDataReady(world,sentry))refuse([701,214],503);
  const verdict=(state,ref,dil)=>{
    const s=state?.siegeRenew?.castles?.[map],g=guildOfRef(state,ref),guards=s?.guards||[];
    if(!g)refuse([701,203],403);if(!s?.owner||s.owner.guild!==g.id)refuse([701,204],403);if(g.master!==ref)refuse([701,205],403);
    if(guards.length>=cfg.maxSentry)refuse([701,218]);
    const placement=guardPlacementRefusal({scene,castle,guards,x,z});if(placement)refuse(placement);
    if(!(Number(dil)>=cfg.sentryUpgradeCost))refuse([701,207]);
    return {s,g,guards};
  };
  verdict(world.socialState,socialRef(p),p.profile.dil);
  const intent={get revision(){return world.socialState?.revision;},requestId:`renew-guard-${randomUUID()}`};
  return socialTransaction(world,p,intent,(state,profile,ref)=>{
    check();
    const {s,g,guards}=verdict(state,ref,profile.dil),row={id:randomUUID().slice(0,8),sentry,x:Math.floor(x)+.5,z:Math.floor(z)+.5,guild:g.id,ref,at:world.now(),cost:cfg.sentryUpgradeCost};
    profile.dil-=cfg.sentryUpgradeCost;s.guards=[...guards,row];
    return {guard:row,deployed:s.guards.length,max:cfg.maxSentry};
  });
}
