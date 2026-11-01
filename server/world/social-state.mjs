import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {characterRef} from '../accounts/character-ref.mjs';
import {createQuestContext} from './quests.mjs';
import {isDeepStrictEqual} from 'node:util';

export const emptySocialState=()=>({version:1,revision:0,mail:{},sent:{},guilds:{},receipts:{}});
export const socialError=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
export function validateSocialState(state){
  if(!state||state.version!==1||!Number.isSafeInteger(state.revision)||state.revision<0||['mail','sent','guilds','receipts'].some(k=>!state[k]||typeof state[k]!=='object'||Array.isArray(state[k])))socialError('Social storage is invalid; original data preserved.',503);
  return state;
}
/** Hook factory for the existing accounts API's private load/transact closures.
 * transact MUST atomically replace the same document containing users and social.
 * Never implement this hook using a second file or a sequence of profile writes.
 */
export function createSocialAccountHooks({load,transact,saveNpcProfile}){
  return {
    async getSocialState(){return structuredClone(validateSocialState((await load()).social||emptySocialState()));},
    async saveSocialTransaction({expectedRevision,state,updates=[]}){
      validateSocialState(state);
      if(state.revision!==expectedRevision+1||!Array.isArray(updates)||updates.length>1)socialError('Invalid social transaction.');
      return transact(db=>{
        const current=validateSocialState(db.social||emptySocialState());
        if(current.revision!==expectedRevision)socialError('Social state changed. Review the current state.',409);
        for(const {accountId,characterId,profile,expected,preserveLastPlayed=false}of updates){
          // Trusted simulation NPCs share this atomic social document, never
          // login users/sessions or account-premium entitlement semantics.
          if(typeof accountId==='string'&&/^npc_[a-f0-9]{32}$/.test(accountId)){
            const old=Object.hasOwn(db.npcProfiles||{},accountId)&&db.npcProfiles[accountId];
            if(!old||old.id!==characterId||old.authority!=='server'||old.npcPlayer!==true||typeof saveNpcProfile!=='function')socialError('The private NPC character is unavailable.',404);
            if(expected!==undefined||preserveLastPlayed!==false||!profile||Object.hasOwn(profile,'accountFeatures'))socialError('NPC account entitlement updates are unsupported.',400);
            if(saveNpcProfile(db,{accountId,characterId,profile})!==true)socialError('The private NPC social transaction could not be saved.',503);
            continue;
          }
          const owner=Object.hasOwn(db.users,accountId)&&db.users[accountId],index=owner?.characters.findIndex(c=>c.id===characterId&&c.authority==='server')??-1;
          if(index<0)socialError('The character is unavailable.',404);
          const old=owner.characters[index];
          if(expected!==undefined&&(!expected||!isDeepStrictEqual(old,expected.character)||!isDeepStrictEqual(owner.accountFeatures,expected.accountFeatures)))socialError('Canonical reward eligibility changed; retry without spending the entitlement.',409);
          if(typeof preserveLastPlayed!=='boolean')socialError('Invalid offline reward profile update.');
          owner.characters[index]={...structuredClone(profile),id:old.id,name:old.name,nameColor:old.nameColor||'white',classIndex:old.classIndex,className:old.className,authority:'server',lastPlayed:preserveLastPlayed?old.lastPlayed:Date.now()};
          if(preserveLastPlayed&&!Object.hasOwn(old,'lastPlayed'))delete owner.characters[index].lastPlayed;
          if(profile.accountFeatures){owner.accountFeatures=structuredClone(profile.accountFeatures);delete owner.characters[index].accountFeatures;}
          owner.revision++;
        }
        db.social=structuredClone(state);return true;
      });
    },
  };
}
export async function initializeSocial(world){
  if(!world.getSocialState||!world.saveSocialTransaction)return;
  world.socialState=validateSocialState(await world.getSocialState());
  await refreshSocialNames(world);
}
export async function refreshSocialNames(world){
  if(!world.listCharacters)return;
  if(world.socialNamesLoading)return world.socialNamesLoading;
  world.socialNamesLoading=(async()=>{
    const rows=await world.listCharacters();world.socialNames=new Map(rows.map(c=>[c.ref,c.name]));world.socialNamesAt=world.now();
  })();
  try{await world.socialNamesLoading;}finally{world.socialNamesLoading=null;}
}
export const socialRef=p=>characterRef(p.account,p.characterId);
export function socialState(world){
  if(!world.socialState||!world.saveSocialTransaction)socialError('Durable social storage is unavailable.',503);
  return world.socialState;
}
export function socialIntent(input,operations){
  const fields=Object.hasOwn(operations,input.operation)&&operations[input.operation];
  if(!fields||Object.keys(input).some(k=>!['token','type','operation','revision','requestId',...fields].includes(k)))socialError('Send social intent only, never results or resources.');
  if(!Number.isSafeInteger(input.revision)||input.revision<0||typeof input.requestId!=='string'||!/^[a-zA-Z0-9_-]{16,100}$/.test(input.requestId))socialError('A current revision and unique request ID are required.');
}
export function socialLive(world,p,{allowTransition=false}={}){
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition&&!allowTransition||p.tradeId||p.tradeCommitting)socialError('This service is unavailable while disconnected, dead, travelling or trading.',409);
}
/** Global social CAS and the actor's canonical profile commit together. Live state
 * stays untouched until durability succeeds. HTTP must retain its actor scheduler.
 */
export async function socialTransaction(world,p,input,mutate){
  p.commandActive=(p.commandActive||0)+1;
  const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(async()=>{
    socialLive(world,p);
    const current=socialState(world),ref=socialRef(p);
    if(input.revision!==current.revision)socialError('Social state changed. Review the current state.',409);
    if(current.receipts[ref]?.includes(input.requestId))socialError('That social request was already applied.',409);
    // Reuse core's existing simulation guard before cloning or asynchronous
    // directory lookup. It stops movement, HP/buffs/skills, monster targeting,
    // and autosave until the old or new durable profile can be exposed safely.
    const previousTransition=p.sceneTransition;p.sceneTransition=true;
    try{
    const beforeProfile=structuredClone(p.profile),revision=p.revision??0,hpBefore=p.hp,mpBefore=p.mp;
    const state=structuredClone(current),profile=structuredClone(p.profile),actor={...p,profile},events=[];
    // Progression must run against the staged actor. Level/stat/HP updates and
    // notifications become visible only after the same durable social write.
    const effects={grantExp(exp){
      if(!Number.isSafeInteger(exp)||exp<0||!Number.isSafeInteger((profile.exp||0)+exp))socialError('Invalid social experience reward.');
      if(!exp)return;
      if(typeof world.grantProgress!=='function')socialError('Authoritative progression is unavailable.',503);
      world.grantProgress.call({...world,changed(){},emit:(map,event)=>events.push([map,event])},actor,exp,0);
    }};
    const result=await mutate(state,profile,ref,effects);
    // Recount carried collect objectives on this staged profile before the SAME
    // durable escrow/inventory write; never emit or persist an extra operation.
    if(world.data.progression?.quests&&world.data.itemDB&&JSON.stringify(profile.inventory)!==JSON.stringify(p.profile.inventory)){
      const context=createQuestContext(world,p,{profile,commitToPlayer:false});
      context?.engine.recountCollect(null,true);
    }
    // Recipient directory resolution may await; recheck the acting lease.
    socialLive(world,p,{allowTransition:true});
    state.revision++;
    state.receipts[ref]=[...(state.receipts[ref]||[]),input.requestId].slice(-256);
    const changed=JSON.stringify(profile)!==JSON.stringify(p.profile);
    const updates=changed?[{accountId:p.account,characterId:p.characterId,profile:world.canonical(actor)}]:[];
    if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates})===false)socialError('The social transaction could not be saved.',503);
    world.socialState=state;
    if(changed){
      const levelUp=profile.level>beforeProfile.level,intervening=(p.revision??0)-revision;
      publishProfileChanges(p.profile,beforeProfile,profile);
      if(levelUp){p.stats=actor.stats;p.maxHp=actor.maxHp;p.hp=p.hp===hpBefore?actor.hp:Math.min(p.hp,p.maxHp);p.mp=p.mp===mpBefore?actor.mp:Math.min(p.mp||0,p.stats.maxMp||0);}
      refreshConcurrentBuffStats(world,p,beforeProfile);world.changed(p);p.dirty=intervening!==0;p.saveError=null;
    }
    for(const [map,event]of events)world.emit(map,event);
    return result;
    }finally{p.sceneTransition=previousTransition;}
  });
  world.saveQueue=task.catch(()=>{});
  try{const result=await task;await persistInterveningProgress(world,[p]);return result;}catch(error){if(error.status===409&&world.getSocialState)await initializeSocial(world);throw error;}
  finally{p.commandActive=Math.max(0,(p.commandActive||1)-1);}
}
