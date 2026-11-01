import {createHash} from 'node:crypto';
import {characterRef} from './character-ref.mjs';
const fail=(status,message)=>{throw Object.assign(new Error(message),{status});};
function canonical(v){if(Array.isArray(v))return '['+v.map(canonical).join(',')+']';if(v&&typeof v==='object')return '{'+Object.keys(v).filter(k=>v[k]!==undefined).sort().map(k=>JSON.stringify(k)+':'+canonical(v[k])).join(',')+'}';return JSON.stringify(v);}
export const gmDigest=value=>createHash('sha256').update(canonical(value)).digest('hex');
export function gmInventoryRevision(profile,lease='offline'){
  return gmDigest({lease,inventory:profile.inventory||[],potionBelt:profile.potionBelt||[],storage:profile.storage||[],equip:profile.equip||{},cash:profile.cashInv||[],costumes:profile.costumeBag||[],shared:profile.accountFeatures?.shared||[],cursor:profile.itemCursor||null,bags:profile.bagsUnlocked||2,stash:profile.stashUnlocked||2});
}
export function gmTransferIdentity(operatorRef,input){
  const fields=['ref','container','uid','count','revision','destinationRevision','requestId','reason'];
  return {key:gmDigest({operatorRef,requestId:input.requestId}),digest:gmDigest(Object.fromEntries(fields.map(k=>[k,input[k]])))};
}
function find(db,ref){for(const owner of Object.values(db.users))for(const c of owner.characters)if(c.authority==='server'&&characterRef(owner.id,c.id)===ref)return {owner,c};return null;}
/** Same atomic document as characters. authorize runs inside the storage queue;
 * guard synchronously revalidates the paused world actors before preparing bytes.
 * Never replace this with sequential saves or a separate audit file. */
export function createGMTransferHooks({load,transact,authorize}){
  return {
    async describeGMCharacter(ref){const row=find(await load(),ref);if(!row)return null;return {accountId:row.owner.id,characterId:row.c.id,revision:gmDigest(row.c),profile:structuredClone({...row.c,...(row.owner.accountFeatures?{accountFeatures:row.owner.accountFeatures}:{})})};},
    async readGMTransfer(key){return structuredClone((await load()).gmTransfers?.[key]||null);},
    async commitGMTransfer(req,{operatorRef,key,digest,updates,audit,guard}){
      if(!/^[a-f0-9]{64}$/.test(key)||!/^[a-f0-9]{64}$/.test(digest)||!Array.isArray(updates)||updates.length!==2)fail(400,'Invalid GM transfer transaction.');
      return transact(async db=>{
        const user=await authorize(req,db);
        if(!user?.capabilities?.includes('gm:commands'))fail(403,'GM permission is required to transfer items.');
        const operator=find(db,operatorRef);if(!operator||operator.owner.id!==user.id)fail(403,'The recipient must be your connected GM character.');
        guard();
        const previous=db.gmTransfers?.[key];if(previous){if(previous.digest!==digest)fail(409,'This transfer ID was already used for different input.');return {receipt:structuredClone(previous.receipt),replayed:true};}
        if(Object.keys(db.gmTransfers||{}).length>=10000)fail(503,'The durable GM audit is full. Archive it before transferring more items.');
        const rows=updates.map(u=>{const row=find(db,u.ref);if(!row)fail(404,'A transfer character is unavailable.');if(gmDigest(row.c)!==u.expectedRevision)fail(409,'Saved character progress changed. Refresh both inventories.');return {...row,u};});
        if(new Set(rows.map(r=>r.owner.id)).size!==2||!rows.some(r=>r.u.ref===operatorRef))fail(400,'Choose a character on another account.');
        for(const {owner,c,u} of rows){const index=owner.characters.indexOf(c);owner.characters[index]={...structuredClone(u.profile),id:c.id,name:c.name,nameColor:c.nameColor||'white',classIndex:c.classIndex,className:c.className,authority:'server',lastPlayed:Date.now()};if(u.profile.accountFeatures){owner.accountFeatures=structuredClone(u.profile.accountFeatures);delete owner.characters[index].accountFeatures;}owner.revision++;}
        const receipt={id:audit.requestId,source:audit.source,destination:operatorRef,container:audit.container,uid:audit.uid,receivedUid:audit.receivedUid,itemIndex:audit.itemIndex,count:audit.count,at:Date.now()};
        db.gmTransfers||={};db.gmTransfers[key]={digest,receipt,audit:{...structuredClone(audit),operatorAccount:user.id,operatorRef,at:receipt.at}};
        return {receipt,replayed:false};
      });
    },
  };
}
