import {randomUUID} from 'node:crypto';
import {isDkChannel} from '../../src/systems/channels/channel-rules.js';
// Native Portal Scroll (type3/code4), item description338: a personal portal
// lasts30minutes. Creation and stepping through it are separate operations.
export const PERSONAL_PORTAL_MS=30*60*1000;
const fail=message=>{throw Object.assign(Error(message),{status:400});};
const info=(world,map)=>world.data.dungeonCatalog?.maps?.[map]||world.data.dungeonData?.dg?.maps?.[map];
export function personalPortalFieldAllowed(world,p,map=p.map,channel=p.channel??0){
 const row=info(world,map);
 if(p.instanceId||p.dead||p.mount||p.sceneTransition||isDkChannel(channel)||!row||!['field','system'].includes(row.kind)||row.flags?.portal===0||row.flags?.returnScroll===0||world.data.requiresInstance?.(map))fail('A personal portal is unavailable in this scene.');
}
export function personalPortalState(world,p,profile=p.profile){
 const r=profile?.personalPortal;
 if(!r||r.v!==1||r.characterId!==p.characterId||typeof r.id!=='string'||!['origin','away'].includes(r.stage)||![r.map,r.channel,r.x,r.z,r.createdAt,r.expiresAt].every(Number.isFinite)||!Number.isInteger(r.map)||!Number.isInteger(r.channel)||r.expiresAt-r.createdAt!==PERSONAL_PORTAL_MS||world.now()<r.createdAt||world.now()>=r.expiresAt)return null;
 return r;
}
export function createPersonalPortal(world,p,profile,def){
 if(Number(def?.type)!==3||Number(def?.code)!==4)fail('This item does not create a personal portal.');
 personalPortalFieldAllowed(world,p);
 const now=world.now();profile.personalPortal={v:1,id:randomUUID(),characterId:p.characterId,map:p.map,channel:p.channel??0,x:p.x,z:p.z,createdAt:now,expiresAt:now+PERSONAL_PORTAL_MS,stage:'origin'};
 return true;
}
export function requirePersonalPortal(world,p,id,stage){
 personalPortalFieldAllowed(world,p);
 const r=personalPortalState(world,p);
 if(!r||r.id!==id||r.stage!==stage)fail('That personal portal is no longer available.');
 personalPortalFieldAllowed(world,p,r.map,r.channel);
 if(stage==='origin'&&(p.map!==r.map||(p.channel??0)!==r.channel||Math.hypot(p.x-r.x,p.z-r.z)>3))fail('Stand beside your own personal portal.');
 return r;
}
