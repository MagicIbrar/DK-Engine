import {randomUUID} from 'node:crypto';
import {AuthoritativeInventory} from './inventory.mjs';
import {ownedItems} from './item-ownership.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {premiumHas} from './premium-service.mjs';
import {DekaPass} from '../../src/systems/life/dekapass.js';
import {socialError as fail,socialRef,socialIntent,socialTransaction,socialLive} from './social-state.mjs';
import {mailDeliveryPolicy,expiredMail,expireInboxOnClone,ORIGINAL_INBOX_POLICY,PRESERVED_SYSTEM_POLICY} from './mail-policies.mjs';
import {MAIL_ATTACH_DIL_MAX,MAIL_TEXT,trimSent} from '../../src/systems/life/mail-rules.js';
import {pendingGifts} from './dshop-gifts.mjs';

export const MAIL_SCHEMAS={mail:['token','type','operation','revision','requestId','toName','title','content','dil','uid','count','id','attachment','box','level','premium','all']};
const MAX_DIL=10_000_000_000;
const text=(value,max,label)=>{if(typeof value!=='string'||value.length>max||/[\x00-\x08\x0b-\x1f\x7f]/.test(value))fail(`Invalid ${label}.`);return value.trim();};
const amount=value=>{if(!Number.isSafeInteger(value)||value<0||value>MAX_DIL)fail('Invalid DIL amount.');return value;};
// A nearby mail NPC, or the Holy Water "Remote mailbox" (premiereitem.csv Post, server-owned premium state) - the Agency pattern.
export function mailNpc(world,p){if(!nearbyNpc(world,p,{role:'MAIL'})&&!premiumHas(world,p.profile,'post'))fail('Use a nearby mail service.',403);}
/** Trusted reward providers call this only on a socialTransaction clone. Never
 * expose its reward fields as a browser intent. No live profile or inbox changes.
 */
export function stageSystemMail(world,state,profile,ref,{title,content='',dil=0,items=[],deliveryPolicy=PRESERVED_SYSTEM_POLICY}){
  title=text(title,100,'system subject');content=text(content,1000,'system message');dil=amount(dil);
  if(!title||!Array.isArray(items)||items.length>100)fail('Invalid system reward.');
  const time=world.now(),delivery=mailDeliveryPolicy(deliveryPolicy,time);
  expireInboxOnClone(state,ref,time);
  const inbox=state.mail[ref]||=[],entries=[];
  for(const reward of items){
    if(!reward||Object.keys(reward).some(k=>!['item','count','bound','period'].includes(k))||!Number.isSafeInteger(reward.item)||!Number.isSafeInteger(reward.count)||reward.count<1||reward.bound!==undefined&&typeof reward.bound!=='boolean'||reward.period!==undefined&&(!Number.isSafeInteger(reward.period)||reward.period<0||!Number.isSafeInteger(world.now()+reward.period*1000)))fail('Invalid system reward item.');
    if(!world.data.itemDB)fail('Original reward item tables are unavailable.',503);
    const staged={inventory:[],bagsUnlocked:7},inv=new AuthoritativeInventory(staged,world.data.itemDB,{now:world.now,random:world.random});
    if(!inv.add(reward.item,reward.count,reward))fail('That reward cannot be delivered safely.',503);
    entries.push(...staged.inventory);
  }
  if(inbox.length+Math.max(1,entries.length)>100)fail('Your inbox is full. Claim and delete mail before receiving more rewards.');
  const records=(entries.length?entries:[null]).map((entry,i)=>{
    if(entry)for(const key of ['page','x','y'])delete entry[key];
    return {id:randomUUID(),from:'System',toName:profile.name,title,content,dil:i===0?dil:0,item:entry?.itemIndex||0,itemCount:entry?.count||0,attachment:entry,time,delivery:{...delivery},read:false,claimed:!entry&&!(i===0&&dil)};
  });
  inbox.push(...records);return records;
}
/** General online-character routing hook, called by a trusted earned-reward
 * provider behind the existing actor scheduler. resolve runs inside the clone
 * and may consume its canonical entitlement before returning fixed rewards.
 * A permanent source/key receipt prevents delivery again after claim/delete.
 */
export function deliverSystemReward(world,p,{source,key,resolve}){
  if(typeof source!=='string'||!/^[a-zA-Z0-9_-]{1,64}$/.test(source)||['__proto__','constructor','prototype'].includes(source)||typeof key!=='string'||!/^[a-zA-Z0-9:_-]{1,160}$/.test(key)||['__proto__','constructor','prototype'].includes(key)||typeof resolve!=='function')fail('Invalid trusted reward provider.');
  return socialTransaction(world,p,{revision:world.socialState?.revision,requestId:randomUUID()},async(state,profile,ref)=>{
    state.systemRewards||={};const receipts=state.systemRewards[ref]||={},provider=receipts[source]||={};
    if(Object.hasOwn(provider,key))return {alreadyDelivered:true,ids:[...provider[key]]};
    if(Object.keys(receipts).length>64||Object.values(receipts).reduce((n,row)=>n+Object.keys(row).length,0)>=10000)fail('System reward receipt capacity has been reached; entitlement preserved.',503);
    const reward=await resolve(profile);if(!reward)fail('No earned system reward is available.');
    const records=stageSystemMail(world,state,profile,ref,reward),ids=records.map(m=>m.id);provider[key]=ids;
    return {alreadyDelivered:false,ids};
  });
}
export function mailSnapshot(world,p){
  const state=world.socialState;if(!state)return {available:false,revision:0,inbox:[],sent:[]};
  // The event stream sends headers; immutable message bodies are requested on
  // opening read/sent windows. Escrow metadata stays entirely server-private.
  const ref=socialRef(p),rows=(list,inbox=false)=>(list||[]).filter(record=>!inbox||!expiredMail(record,world.now())).map(({attachment,content,...header})=>({...header})).sort((a,b)=>b.time-a.time);
  // D-Shop gifts waiting for this character (headers only; server/world/dshop-gifts.mjs). The recipient's client accepts
  // them into its own Cash Inventory (171:43 "Gifts are sent to the Cash Inventory.").
  return {available:true,revision:state.revision,postage:world.data.mailPolicy?.postage??null,inbox:rows(state.mail[ref],true),sent:rows(state.sent[ref]),gifts:pendingGifts(world,ref)};
}
export async function mailCommand(world,p,input){
  if(input.operation==='view'){
    socialLive(world,p);
    if(Object.keys(input).some(k=>!['token','type','operation','id','box'].includes(k))||!['inbox','sent'].includes(input.box)||typeof input.id!=='string')fail('Choose an owned inbox or sent message.');
    const state=world.socialState;if(!state)fail('Durable social storage is unavailable.',503);
    const list=(input.box==='sent'?state.sent:state.mail)[socialRef(p)]||[],record=list.find(m=>m.id===input.id);
    if(!record)fail('That message is unavailable.',404);
    if(input.box==='inbox'&&expiredMail(record,world.now()))fail('That mail has reached its original inbox expiry.',410);
    const {attachment,...detail}=record;return {...detail,box:input.box};
  }
  socialIntent(input,{send:['toName','title','content','dil','uid','count'],reward:['level','premium','all'],read:['id'],claim:['id','attachment'],delete:['id']});
  return socialTransaction(world,p,input,async(state,profile,ref)=>{
    const inbox=state.mail[ref]||=[];
    if(input.operation==='reward'){
      // Only the existing server-earned DekaPass entitlement is accepted here.
      // Client requests cannot supply a recipient, attachment or reward amount.
      if(!world.data.dekapass||!world.data.itemDB)fail('Original DekaPass reward tables are unavailable.',503);
      if(input.all!==undefined&&typeof input.all!=='boolean'||input.premium!==undefined&&typeof input.premium!=='boolean'||input.all===true&&(input.level!==undefined||input.premium!==undefined))fail('Choose one pass reward or Receive all.');
      let delivered=0,deliveryError=null;
      const game={save:profile,now:world.now,world:{},items:{bag:{},count:()=>0,def:i=>world.data.itemDB.def(i),canAdd:()=>true,add:(index,count)=>{try{
        delivered+=stageSystemMail(world,state,profile,ref,{title:`DekaPass season ${world.data.dekapass.config.season} reward`,content:'Your earned DekaPass reward is attached. Claim it at a mail service.',items:[{item:index,count}]}).length;
        return true;
      }catch(error){deliveryError=error;return false;}
      }},hud:{log(){}},events:{emit(){}},persist(){},uiwin:{window:()=>null}};
      const pass=new DekaPass(game,{data:{dekapass:world.data.dekapass}});pass._alarm=()=>{};
      if(!pass.active)fail('This DekaPass season is inactive.');
      if(input.all===true)pass.claimAll();else{
        if(!Number.isInteger(input.level)||input.level<1||input.level>pass.levels)fail('Invalid reward level.');
        if(input.premium===true&&!pass.premium)fail('An active premium pass is required.',403);
        pass.claim(input.level,input.premium===true);
      }
      if(deliveryError)throw deliveryError;
      if(!delivered)fail('No eligible unclaimed DekaPass reward is available.');
      return;
    }
    if(input.operation==='send'){
      mailNpc(world,p);
      const toName=text(input.toName,20,'recipient'),title=text(input.title,100,'subject'),content=text(input.content,1000,'message'),dil=amount(input.dil);
      if(dil>MAIL_ATTACH_DIL_MAX)fail(MAIL_TEXT.attachMax);   // official Mailbox guide 25: at most 100 million attached DIL
      const postage=world.data.mailPolicy?.postage;
      if(!Number.isSafeInteger(postage)||postage<0||postage>MAX_DIL)fail('Mail postage policy has not been configured.',503);
      if(!toName||!title&&!content&&!dil&&!input.uid)fail('Choose a recipient and something to send.');
      if(!world.listCharacters)fail('The character directory is unavailable.',503);
      const matches=(await world.listCharacters()).filter(c=>c.name.toLowerCase()===toName.toLowerCase());
      if(matches.length!==1)fail(MAIL_TEXT.notFound,404);   // 250:36
      const target=matches[0];if(target.ref===ref)fail('You cannot mail yourself.');
      expireInboxOnClone(state,target.ref,world.now());
      const delivered=state.mail[target.ref]||=[];if(delivered.length>=100)fail('The recipient inbox is full.');
      if(!Number.isSafeInteger(profile.dil)||profile.dil<dil+postage)fail('Not enough DIL including postage.');
      let item=null;
      if(input.uid!==undefined){
        if(typeof input.uid!=='string'||!Number.isInteger(input.count)||input.count<1||!world.data.itemDB)fail('Choose one owned bag item and quantity.');
        const bag=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now}).bag,source=bag.byUid(input.uid),def=source&&world.data.itemDB.def(source.itemIndex);
        if(!def||source.bound||Number(def.trade)===0||source.expiresAt||Number(def.period)>0||source.pet?.active||source.pet?.inv?.length||input.count>(source.count||1))fail('That item cannot be mailed.');
        item=bag.take(source,input.count);for(const k of ['page','x','y'])delete item[k];
      }else if(input.count!==undefined)fail('An attachment quantity needs an item UID.');
      profile.dil-=dil+postage;
      const time=world.now(),record={id:randomUUID(),from:profile.name,toName:target.name,title:title||'(no subject)',content,dil,item:item?.itemIndex||0,itemCount:item?.count||0,attachment:item,time,delivery:mailDeliveryPolicy(ORIGINAL_INBOX_POLICY,time),read:false,claimed:!item&&!dil};
      delivered.push(record);
      // Sent history never owns a second spendable attachment.
      const history={...record};delete history.attachment;
      // 250:73 "Sent Mail box will save up to 10 recent mails." Escrow lives only in the recipient inbox, so trimming history
      // never removes an attachment.
      (state.sent[ref]||=[]).push(history);state.sent[ref]=trimSent(state.sent[ref]);
      return;
    }
    if(typeof input.id!=='string')fail('Choose an inbox message.');
    const record=inbox.find(m=>m.id===input.id);if(!record)fail('That message is not in your inbox.',404);
    if(expiredMail(record,world.now()))fail('That mail has reached its original inbox expiry.',410);
    if(input.operation==='read'){record.read=true;const {attachment,...detail}=record;return {...detail,box:'inbox'};}
    if(input.operation==='delete'){
      if(record.attachment||record.dil)fail('Claim attachments before deleting this message.');
      state.mail[ref]=inbox.filter(m=>m!==record);return;
    }
    mailNpc(world,p);
    if(input.attachment==='item'){
      const item=record.attachment;if(!item)fail('That item attachment was already claimed.');
      if(!world.data.itemDB?.def(item.itemIndex)||item.expiresAt&&item.expiresAt<=world.now())fail('That attachment is expired or unavailable.');
      const bag=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now}).bag;
      if(ownedItems(profile).some(owned=>owned.uid===item.uid))fail('That item identity already exists.',409);
      if(!bag.add(structuredClone(item)).ok)fail('Your inventory is full.');
      record.attachment=null;record.item=0;record.itemCount=0;
    }else if(input.attachment==='dil'){
      if(!record.dil)fail('That DIL attachment was already claimed.');
      const balance=amount(profile.dil)+amount(record.dil);if(balance>MAX_DIL)fail('Your DIL balance would exceed its limit.');
      profile.dil=balance;record.dil=0;
    }else fail('Choose the item or DIL attachment.');
    record.claimed=!record.attachment&&!record.dil;
  });
}
