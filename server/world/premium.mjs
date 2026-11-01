// Premium warp (Select Warp list) and premium return point commands. State/rules: premium-service.mjs.
import {randomBytes} from 'node:crypto';
import {PREMIUM_TEXT,PREMIUM_WARP_MS,premiumTeleportList,premiumResponList,partyWarpText} from '../../src/systems/shops/premium-rules.js';
import {premiumHas,dshopOf} from './premium-service.mjs';
import {travelLocation,destinationAllowed,commitFieldTravel} from './travel.mjs';
import {partyWarpMember} from './party.mjs';
import {isDkChannel} from '../../src/systems/channels/channel-rules.js';
import {assertNieteService,assertCombatPremium} from './niete-services.mjs';

export const PREMIUM_SCHEMAS={premium:['token','type','operation','location','nonce','member']};
/**
 * Party Warp destination: the CURRENT position of an online member of p's party (checked again when the cast finishes). Data rules:
 * PartyWarp service running, in a party (101:163), not an Expedition (101:164), member found (101:166). A member inside a dungeon /
 * instance / DK channel is on a "map where Party Warp is limited" (101:160); the destination also passes the normal travel admission
 * (siege / arena / level limits): a level refusal answers 101:169, any other 101:160. No column in the data marks other limited maps.
 */
function partyWarpAt(world,p,memberId){
  if(!premiumHas(world,p.profile,'partyWarp'))fail(PREMIUM_TEXT.noService);
  if(typeof memberId!=='string'||!memberId)fail(partyWarpText('noLocation'));
  const found=partyWarpMember(world,p,memberId);
  if(!found.inParty)fail(partyWarpText('notInParty'));
  if(found.expedition)fail(partyWarpText('expedition'));
  const t=found.member;if(!t)fail(partyWarpText('noLocation'));
  const name=String(t.profile?.name||t.name||'');
  if(t.instanceId||world.data.requiresInstance?.(t.map)||isDkChannel(t.channel))fail(partyWarpText('limited',name));
  if(t.sceneTransition||![t.map,t.x,t.z].every(Number.isFinite))fail(partyWarpText('cannotTarget',name));
  const at={map:t.map,x:t.x,z:t.z,dirDeg:0,channel:t.channel??0};
  try{destinationAllowed(world,p,at);}catch(error){fail(/level/i.test(error.message)?partyWarpText('level'):partyWarpText('limited',name));}
  return {at,name};
}
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
function listFor(world,profile,kind){
  const dshop=dshopOf(world),level=Number(profile.level)||1;
  return kind==='teleport'?premiumTeleportList(dshop,level):premiumResponList(dshop,level);
}
function warpRow(world,p,location){
  if(!premiumHas(world,p.profile,'teleport'))fail(PREMIUM_TEXT.noService);
  const row=listFor(world,p.profile,'teleport').find(r=>r.location===location);
  if(!row)fail('That destination is not available at your level.');
  const at=travelLocation(world,row.location);if(!at)fail('The original travel destination is unavailable.');
  // dungeon rows never become free admission: they keep their own admission service
  if(world.data.requiresInstance?.(at.map))fail('Use the original dungeon admission service for this destination.');
  return {row,at};
}
function warpAllowed(world,p){
  assertNieteService(world,p);
  assertCombatPremium(world,p);   // guide62 / 101:248: no Holy Water premium feature in battle status
  if(p.dead||p.sceneTransition)fail('Travel is unavailable while dead or changing maps.');
  if(p.mount)fail(PREMIUM_TEXT.riding);
  if(p.instanceId)fail(PREMIUM_TEXT.dungeon);
  if(world.data.requiresInstance?.(p.map))fail(PREMIUM_TEXT.dungeon);
}
/** Server-owned premium warp cast (begin -> finish after the preparation time, cancel) and return-point selection. */
export async function premiumCommand(world,p,input){
  const op=input.operation;
  if(op==='returnpoint'){
    if(!Number.isInteger(input.location))fail('Invalid return point.');
    if(!premiumHas(world,p.profile,'respon'))fail(PREMIUM_TEXT.noService);
    const row=listFor(world,p.profile,'respon').find(r=>r.location===input.location);
    if(!row||!travelLocation(world,row.location))fail(PREMIUM_TEXT.changeFail);
    const profile=structuredClone(p.profile);profile.premiumRespawn=row.location;
    const previous=p.sceneTransition;p.sceneTransition=true;
    try{const candidate={...p,profile};world.changed(candidate);await world.persist(candidate);for(const key of ['profile','dirty','revision','saveError'])p[key]=candidate[key];}finally{p.sceneTransition=previous;}
    return {returnPoint:row.location};
  }
  if(op==='warpcancel'){const cast=p.smartWarp;if(cast&&(cast.kind!=='premium'||input.nonce!==cast.nonce))fail('That premium warp is no longer active.');p.smartWarp=null;return {};}
  if(op==='warpbegin'){
    const party=input.member!==undefined;
    if(party&&(p.instanceId||world.data.requiresInstance?.(p.map)))fail(partyWarpText('currentMap'));   // 101:167
    warpAllowed(world,p);
    if(party)partyWarpAt(world,p,input.member);
    else{if(!Number.isInteger(input.location))fail('Invalid destination.');const {at}=warpRow(world,p,input.location);destinationAllowed(world,p,at);}
    // Party Warp uses the same server-owned cast as Select Warp (no separate cast time in the data)
    p.smartWarp={kind:'premium',...(party?{member:input.member}:{location:input.location}),nonce:randomBytes(32).toString('hex'),readyAt:world.now()+PREMIUM_WARP_MS,expiresAt:world.now()+PREMIUM_WARP_MS+12000,map:p.map,instanceId:p.instanceId,x:p.x,z:p.z,hp:p.hp,sequence:world.sequence};
    p.path=[];return {};
  }
  if(op==='warpfinish'){
    const cast=p.smartWarp;
    if(!cast||cast.kind!=='premium'||input.nonce!==cast.nonce)fail('That premium warp is no longer active.');
    if(world.now()<cast.readyAt)fail('Premium warp preparation is not complete.');
    p.smartWarp=null;      // one use: completion cannot be replayed
    warpAllowed(world,p);
    if(world.now()>cast.expiresAt||p.map!==cast.map||p.instanceId!==cast.instanceId||Math.hypot(p.x-cast.x,p.z-cast.z)>.01||p.hp<cast.hp||world.events?.some(e=>e.sequence>cast.sequence&&e.type==='damage'&&e.targetId===p.id))fail('Premium warp was interrupted.');
    if(cast.member!==undefined){   // Party Warp: the member's position NOW (they may have moved / left during the cast)
      const {at,name}=partyWarpAt(world,p,cast.member);
      await commitFieldTravel(world,p,at);
      return {partyWarp:{name,map:at.map,text:partyWarpText('done',name)}};
    }
    const {at}=warpRow(world,p,cast.location);destinationAllowed(world,p,at);
    if(world.data.requiresInstance?.(at.map))fail('Use the original dungeon admission service for this destination.');
    await commitFieldTravel(world,p,at);
    return {};
  }
  fail('Unknown premium operation.');
}

/** Revive target: the chosen premium return point while the Respon service runs (field maps only). */
export function premiumRespawn(world,p){
  const id=p.profile.premiumRespawn;
  if(id==null||!premiumHas(world,p.profile,'respon'))return null;
  if(!listFor(world,p.profile,'respon').some(r=>r.location===id))return null;
  return travelLocation(world,id);
}
