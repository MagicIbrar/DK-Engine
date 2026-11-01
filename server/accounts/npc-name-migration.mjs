import {characterNameKey,normalizeCharacterName} from '../../src/game/character-name.js';
import {npcUsernameMigrationEligible,npcGeneratedUsername} from '../world/npc-usernames.mjs';

const fail=message=>{throw Object.assign(Error(message),{status:409});};
/** Trusted, server-only migration. Caller holds its lifecycle lock until commit and
 * cache/roster publication complete; isActive must not be an asynchronous guess. */
export function createNpcNameMigration({transact}){
 return async function migrateNpcNames(proposal,{isActive,confirmedLegacyIds=new Set(),preserveNames=new Set(),rosterBindings=[]}={}){
  if(typeof isActive!=='function'||!(confirmedLegacyIds instanceof Set)||!(preserveNames instanceof Set)||!Array.isArray(rosterBindings)||rosterBindings.length>4096)fail('Trusted inactive NPC migration context required');
  const input=structuredClone(proposal),bindings=structuredClone(rosterBindings),confirmed=new Set(confirmedLegacyIds),preserved=new Set(preserveNames);
  if(input?.version!==2||input.requiresOffline!==true||!Array.isArray(input.changes)||!input.changes.length||input.changes.length>2500)fail('Invalid trusted NPC name proposal');
  return transact(db=>{
   const changes=input.changes,accounts=new Set(),newNames=new Set(),reserved=new Map();
   const reserve=(name,owner)=>{const k=characterNameKey(name);if(!reserved.has(k))reserved.set(k,new Set());reserved.get(k).add(owner);};
   for(const [account,p]of Object.entries(db.npcProfiles||{}))reserve(p.name,account);
   for(const user of Object.values(db.users))for(const p of user.characters||[])reserve(p.name,'human');
   for(const r of bindings){if(typeof r?.name!=='string'||!r.npcRosterId)fail('Invalid NPC roster binding snapshot');reserve(r.name,r.binding?.account||'roster:'+r.npcRosterId);}
   const replacement=new Map(),renamed=[];
   for(const c of changes){
    const old=Object.hasOwn(db.npcProfiles||{},c?.account)&&db.npcProfiles[c.account];
    if(!old||Object.hasOwn(db.users,c.account)||accounts.has(c.account)||c.characterId!==old.id||c.oldName!==old.name||c.npcRosterId!==(old.npcRosterId||null)||c.npcNameSource!=='generated-v2'||c.requiresOffline!==true)fail('Stale or invalid NPC name identity');
    if(!npcUsernameMigrationEligible(c.account,old,{confirmedLegacyIds:confirmed,preserveNames:preserved}))fail('NPC generated-name provenance is unproven or protected');
    if(isActive(c.account,c.characterId)!==false)fail('Active NPC name migration refused');
    if(typeof c.name!=='string'||!/^[A-Za-z][A-Za-z0-9]{2,11}$/.test(c.name)||normalizeCharacterName(c.name)!==c.name||!npcGeneratedUsername(c.name))fail('Invalid generated NPC replacement name');
    const key=characterNameKey(c.name);if(key===characterNameKey(old.name)||reserved.has(key)||newNames.has(key))fail('NPC replacement name conflict');
    const bound=bindings.filter(r=>r.binding?.account===c.account||r.binding?.profileId===c.characterId||c.npcRosterId&&r.npcRosterId===c.npcRosterId);
    if(bound.length>1||bound.some(r=>r.name!==c.oldName||r.binding?.account!==c.account||r.binding?.profileId!==c.characterId||c.npcRosterId&&r.npcRosterId!==c.npcRosterId))fail('Stale NPC roster binding');
    accounts.add(c.account);newNames.add(key);replacement.set(characterNameKey(c.oldName),c.name);renamed.push(c);
   }
   // An ambiguous legacy name cannot safely rewrite name-based friend references.
   for(const c of renamed)if(reserved.get(characterNameKey(c.oldName))?.size!==1)fail('Ambiguous legacy NPC friend name');
   const updates=[],humanFriendUpdates=[];
   const friends=p=>{if(!Array.isArray(p.npcFriends))return false;let changed=false;p.npcFriends=p.npcFriends.map(name=>{const next=replacement.get(characterNameKey(name));if(next!==undefined){changed=true;return characterNameKey(next);}return name;});return changed;};
   for(const c of renamed){const p=db.npcProfiles[c.account];p.name=c.name;p.npcNameSource='generated-v2';}
   for(const [account,p]of Object.entries(db.npcProfiles)){const friendChange=friends(p);if(accounts.has(account)||friendChange)updates.push({accountId:account,characterId:p.id,profile:structuredClone(p)});}
   for(const [account,user]of Object.entries(db.users)){let changed=false;for(const p of user.characters||[])if(friends(p)){changed=true;humanFriendUpdates.push({accountId:account,characterId:p.id,npcFriends:structuredClone(p.npcFriends)});}if(changed)user.revision=(Number(user.revision)||0)+1;}
   for(const r of bindings){const c=renamed.find(c=>c.account===r.binding?.account&&c.characterId===r.binding?.profileId);if(c)r.name=c.name;}
   // A canonical receipt repairs the separately persisted roster after interruption.
   db.npcNameMigrations||={};for(const c of renamed)db.npcNameMigrations[c.account]={characterId:c.characterId,npcRosterId:c.npcRosterId,oldName:c.oldName,name:c.name,source:'generated-v2'};
   for(const c of renamed)if(isActive(c.account,c.characterId)!==false)fail('Active NPC name migration refused');
   return {committed:true,changes:structuredClone(renamed),updates,humanFriendUpdates,rosterBindings:bindings};
  });
 };
}
