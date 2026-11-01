import {characterRef} from '../accounts/character-ref.mjs';
import {deliverSystemReward,stageSystemMail} from './mail.mjs';
import {socialError as fail,socialState,initializeSocial} from './social-state.mjs';
import {rewardMailPolicy,expireInboxOnClone} from './mail-policies.mjs';

const id=value=>typeof value==='string'&&value.length>0&&value.length<=160&&!/[\x00-\x1f\x7f]/.test(value);
function providerIdentity({source,key,resolve}){
  if(typeof source!=='string'||!/^[a-zA-Z0-9_-]{1,64}$/.test(source)||typeof key!=='string'||!/^[a-zA-Z0-9:_-]{1,160}$/.test(key)||[source,key].some(v=>['__proto__','constructor','prototype'].includes(v))||typeof resolve!=='function')fail('Invalid trusted reward provider.');
}
function receipt(state,ref,source,key){
  const provider=state.systemRewards?.[ref]?.[source];
  if(!provider||!Object.hasOwn(provider,key))return null;
  if(!Array.isArray(provider[key])||provider[key].some(v=>typeof v!=='string'))fail('System reward receipt is invalid; data preserved.',503);
  return {alreadyDelivered:true,ids:[...provider[key]]};
}
function recordReceipt(state,ref,source,key,ids){
  state.systemRewards||={};const receipts=state.systemRewards[ref]||={};
  if(!Object.hasOwn(receipts,source))receipts[source]={};
  if(Object.keys(receipts).length>64||Object.values(receipts).reduce((n,row)=>n+Object.keys(row).length,0)>=10000)fail('System reward receipt capacity has been reached; entitlement preserved.',503);
  receipts[source][key]=ids;
}
// New server-only entry point. It owns the account scheduler; callers must NOT
// invoke it from an already-held account/save/social queue. No HTTP intent.
// resolve must check a real canonical earned entitlement; reward values remain
// fixed by that provider. Attendance/COD/recovery/return are explicitly refused.
export function routeEarnedRewardMail(world,{accountId,characterId},provider){
  if(!id(accountId)||!id(characterId))fail('Choose a canonical reward recipient.');
  providerIdentity(provider);
  const policy=rewardMailPolicy(provider.family);
  if(typeof world.serializeAccount!=='function'||typeof world.getProfile!=='function')fail('Canonical reward recipient scheduling is unavailable.',503);
  return world.serializeAccount(accountId,async()=>{
    const online=world.players.get(accountId);
    const resolve=async profile=>{
      const reward=await provider.resolve(profile);
      if(!reward)return null;
      // The routing layer sets mailbox retention, never the producer/browser.
      return {...reward,deliveryPolicy:policy};
    };
    if(online){
      if(online.characterId!==characterId)fail('Another character on this account is active; defer offline reward routing.',409);
      return deliverSystemReward(world,online,{source:provider.source,key:provider.key,resolve});
    }
    const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(async()=>{
      if(world.players.has(accountId))fail('Recipient connected while reward routing was pending; retry through its actor scheduler.',409);
      const current=socialState(world),ref=characterRef(accountId,characterId);
      const prior=receipt(current,ref,provider.source,provider.key);if(prior)return prior;
      const original=await world.getProfile(accountId,characterId);
      if(!original||original.id!==characterId||original.authority!=='server')fail('The reward recipient is unavailable.',404);
      const state=structuredClone(current),profile=structuredClone(original),reward=await resolve(profile);
      if(!reward)fail('No earned system reward is available.');
      if(profile.id!==original.id||profile.name!==original.name||profile.classIndex!==original.classIndex||profile.authority!=='server')fail('Reward provider changed canonical identity.',503);
      const records=stageSystemMail(world,state,profile,ref,reward),ids=records.map(record=>record.id);
      recordReceipt(state,ref,provider.source,provider.key,ids);state.revision++;
      // Always compare the full canonical character and shared features, even
      // when resolve only reads eligibility. Avoid racing an admin/account edit.
      const expected={character:structuredClone(original),accountFeatures:structuredClone(original.accountFeatures)};
      delete expected.character.accountFeatures;
      if(world.players.has(accountId))fail('Recipient connected during reward verification; retry.',409);
      const updates=[{accountId,characterId,profile,expected,preserveLastPlayed:true}];
      if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates})===false)fail('The reward transaction could not be saved.',503);
      world.socialState=state;return {alreadyDelivered:false,ids};
    });
    world.saveQueue=task.catch(()=>{});
    try{return await task;}catch(error){if(error.status===409&&world.getSocialState)await initializeSocial(world);throw error;}
  });
}

// Trusted bounded maintenance call: at most ten inboxes per pass. This writes
// ONLY social state and preserves permanent earned receipts. No profile writes,
// returns, refunds or bag grants occur on expiry. Retry after a failed save.
export function sweepExpiredMail(world,refs){
  if(!Array.isArray(refs)||refs.length<1||refs.length>10||new Set(refs).size!==refs.length||refs.some(ref=>typeof ref!=='string'||!/^[a-f0-9]{64}$/.test(ref)))fail('Choose one to ten canonical mailbox references.');
  const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(async()=>{
    const current=socialState(world),state=structuredClone(current);let removed=0;
    for(const ref of refs)removed+=expireInboxOnClone(state,ref,world.now());
    if(!removed)return {removed:0};
    state.revision++;
    if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates:[]})===false)fail('Expired mail cleanup could not be saved.',503);
    world.socialState=state;return {removed};
  });
  world.saveQueue=task.catch(()=>{});
  return task.catch(async error=>{if(error.status===409&&world.getSocialState)await initializeSocial(world);throw error;});
}
