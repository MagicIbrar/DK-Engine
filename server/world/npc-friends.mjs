import {serializeLife,commitLife,validateLife} from './life-transactions.mjs';
import {gameplayPreferences} from '../../src/game/gameplay-preferences.js';
import {MAX_FRIENDS} from './friend-requests.mjs';
const friendKey=name=>String(name||'').trim().toLowerCase();
// Messenger registration is one-way in this engine. Block only new incoming
// registrations; old friends, removals and ordinary messages keep their rules.
async function assertFriendRegistration(world,p,names){
 const previous=new Set((p.profile.npcFriends||[]).map(friendKey));
 const additions=names.filter(name=>!previous.has(friendKey(name)));
 if(!additions.length)return;
 const live=[...world.players.values()].filter(q=>q!==p&&!q.leaving);
 let roster;
 for(const name of additions){
  let target=live.find(q=>friendKey(q.profile?.name)===friendKey(name))?.profile;
  if(!target&&typeof world.listCharacters==='function'&&typeof world.inspectCharacter==='function'){
   roster??=await world.listCharacters();
   const row=roster.find(q=>friendKey(q.name)===friendKey(name));
   if(row)target=await world.inspectCharacter(row.ref);
  }
  if(gameplayPreferences(target?.gameplayPreferences).blockFriend)throw Object.assign(Error(`${target.name||name} is not accepting friend requests.`),{status:403});
 }
}
// Cap matches friend-requests MAX_FRIENDS (client messenger 0/200). CONFLICT: older SERVER-RE Segment<30>;
// prefer client per EVIDENCE-SOURCES / owner 2026-10-29. Blacklist stays 30.
// Preserve display casing; dedupe by lowercase key.
export const NPC_FRIEND_SCHEMAS={npcfriends:['token','type','operation','names']};
export async function npcFriendCommand(world,p,input){
 validateLife(input,NPC_FRIEND_SCHEMAS);
 if(input.operation!=='set'||!Array.isArray(input.names)||input.names.length>MAX_FRIENDS||input.names.some(n=>typeof n!=='string'||!n.trim()||n.length>64||/[\x00-\x1f\x7f]/.test(n)))throw Object.assign(Error(`Choose up to ${MAX_FRIENDS} valid friend names.`),{status:400});
 const seen=new Set();
 const names=[];
 for(const raw of input.names){
  const trimmed=raw.trim();
  const k=friendKey(trimmed);
  if(seen.has(k))continue;
  seen.add(k);
  names.push(trimmed);
 }
 names.sort((a,b)=>friendKey(a).localeCompare(friendKey(b)));
 const token=p.token,assertLease=()=>{if(typeof world.lease==='function'&&world.lease(p.account,token)!==p)throw Object.assign(Error('Friend registration session changed.'),{status:409});};
 return serializeLife(p,async()=>{assertLease();if(JSON.stringify(p.profile.npcFriends||[])===JSON.stringify(names))return true;await assertFriendRegistration(world,p,names);assertLease();const profile=structuredClone(p.profile);profile.npcFriends=names;await commitLife(world,p,profile);world.changed(p);return true;});
}
export function npcFriendHumans(world,p,isHuman){const name=friendKey(p.profile.name);return [...world.players.values()].filter(q=>q!==p&&!q.leaving&&isHuman(q)&&!q.messengerDecline&&(q.profile.npcFriends||[]).some(n=>friendKey(n)===name));}