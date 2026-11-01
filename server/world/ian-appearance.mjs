// Weapon appearance service of Ian (npc job 110 CHANGESHAPE_JOB): the host transaction behind the original two-slot window
// (game2/changeshapewnd/changeshapewnd.txt) and the timer of a changed look. Rules: src/systems/items/weapon-appearance.js;
// open choices: src/config/engine-chosen-ian.js.
//   weaponlook {operation:'change', weapon, material, revision, requestId}
//     weapon / material = bag item uids; revision = profile.weaponLook.revision the window read; requestId = replay key.
// One staged profile: the material is consumed, the native DIL cost of its kind is paid, the weapon keeps `appearance` and
// `appearanceExpiresAt`, and a receipt is recorded. Nothing is published unless the durable write succeeds; the same
// requestId returns its receipt instead of a second change. tickWeaponLooks clears run-out appearances durably.
import fs from 'node:fs/promises';
import path from 'node:path';
import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {commitLife,serializeLife,validateLife,lifeError as fail} from './life-transactions.mjs';
import {createQuestContext} from './quests.mjs';
import {decodeText,parseCSV} from '../../src/formats/binreader.js';
import {parseStringTableCates} from '../../src/ui/uiwin/strings.js';
import {appearanceMaterial,materialFits,materialSeconds,appearanceCost,appearanceRunning,appearanceExpired,systemVariables,WEAPON_LOOK_TEXT} from '../../src/systems/items/weapon-appearance.js';
import {IAN_CHOSEN} from '../../src/config/engine-chosen-ian.js';

export const IAN_SCHEMAS={weaponlook:['token','type','operation','weapon','material','revision','requestId']};
const ROLE='CHANGESHAPE_JOB',JOB=110,RETRY_MS=5000;
// The table of each string cate used here (SYSTEM 101, NORMAL 40 / 1001).
const STRING_FILES={101:'script/string/system/stringtable_system.txt',40:'script/string/normal/stringtable_pc.txt',1001:'script/string/item/stringtable_itemupgrade.txt'};
const cache=new WeakMap(),sweepAt=new WeakMap();
/** Native tables of the service, read once per world data: share/system_variable.csv and the window's refusal strings. */
export function weaponLookData(world){
  const data=world.data;let p=cache.get(data);
  if(!p){
    p=(async()=>{
      const root=data?.dataRoot;if(!root)return {variables:new Map(),text:new Map()};
      const variables=systemVariables(parseCSV(decodeText(await fs.readFile(path.join(root,'share/system_variable.csv')))).slice(1));
      const text=new Map();
      for(const [cate,file]of Object.entries(STRING_FILES)){
        const keys=new Set(Object.values(WEAPON_LOOK_TEXT).filter(([,c])=>String(c)===cate).map(([,c,code])=>`${c}:${code}`));
        const bytes=await fs.readFile(path.join(root,file)).catch(error=>{if(error.code==='ENOENT')return null;throw error;});
        if(bytes)for(const [key,value]of parseStringTableCates(decodeText(bytes)))if(keys.has(key))text.set(key,value);
      }
      return {variables,text};
    })();
    p.catch(()=>cache.delete(data));cache.set(data,p);
  }
  return p;
}
/** A native line (markup and the "[message]" prefix removed) or its Global fallback. */
export function weaponLookText(data,key){
  const [,cate,code,fallback]=WEAPON_LOOK_TEXT[key];
  return String(data?.text?.get(`${cate}:${code}`)??fallback).replace(/<[^>]+>/g,'').replace(/^\s*\[message\]\s*/i,'').replace(/\\\\?/g,' ').trim();
}
function lookState(profile){
  const s=profile.weaponLook;
  if(s==null)return {revision:0,receipts:[]};
  if(typeof s!=='object'||Array.isArray(s)||!Number.isSafeInteger(s.revision)||s.revision<0||!Array.isArray(s.receipts)||s.receipts.length>IAN_CHOSEN.receipts||s.receipts.some(r=>!r||typeof r.id!=='string'||typeof r.signature!=='string'))fail('Unsupported weapon appearance receipt state.');
  return s;
}
const receiptOut=r=>({uid:r.uid,itemIndex:r.itemIndex,appearance:r.appearance,expiresAt:r.expiresAt,dil:r.dil,replaced:r.replaced||0,revision:r.revision});
/** The actor must still be the live session of its account (a replaced or leaving session changes nothing). */
function custody(world,p){
  if(p.dead||p.leaving||p.revoked||p.sceneTransition||world.players?.get?.(p.account)!==p)fail('This character session can no longer change items.');
}
export function weaponLookCommand(world,p,input){return serializeLife(p,async()=>{
  validateLife(input,IAN_SCHEMAS);
  if(input.operation!=='change')fail('Unknown weapon appearance operation.');
  if(typeof input.weapon!=='string'||typeof input.material!=='string'||!input.weapon||!input.material||input.weapon===input.material||input.weapon.length>100||input.material.length>100||!Number.isSafeInteger(input.revision)||input.revision<0||typeof input.requestId!=='string'||!/^[A-Za-z0-9_-]{8,80}$/.test(input.requestId))fail('Send the selected weapon, material and durable intent only.');
  const data=await weaponLookData(world),t=key=>weaponLookText(data,key);
  const state=lookState(p.profile),signature=JSON.stringify(['change',input.weapon,input.material,input.revision]);
  const receipt=state.receipts.find(r=>r.id===input.requestId);
  if(receipt){if(receipt.signature!==signature)fail('That weapon appearance request ID has another intent.');return {...receiptOut(receipt),replayed:true};}
  custody(world,p);
  if(!nearbyNpc(world,p,{role:ROLE,jobType:JOB}))fail('Walk near the original weapon appearance NPC.');
  if(input.revision!==state.revision)fail(t('missing'));
  const db=world.data.itemDB;if(!db)fail('The original item catalog is unavailable.');
  const now=world.now(),profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
  const weapon=inv.bag.byUid(input.weapon),material=inv.bag.byUid(input.material),live=item=>item&&(item.count||1)>=1&&!(item.expiresAt&&item.expiresAt<=now);
  if(!live(weapon))fail(t('missing'));
  if(!live(material))fail(t('material'));
  const weaponDef=db.def(weapon.itemIndex),materialDef=db.def(material.itemIndex);
  if(Number(weaponDef?.type)!==4||(weapon.count||1)!==1||!appearanceMaterial(materialDef))fail(t('unusable'));
  if(!materialFits(materialDef,weaponDef))fail(t('mismatch'));
  const seconds=materialSeconds(materialDef);if(!seconds)fail('The original material duration is unavailable.');
  const cost=appearanceCost(materialDef,data.variables);if(cost==null)fail('The original appearance change cost is unavailable.');
  if(inv.dil<cost)fail(t('dil'));
  inv.addDil(-cost);
  if(!inv.consumeEntry(material,1))fail(t('material'));
  const replaced=Number(weapon.appearance)>0&&appearanceRunning(weapon,now)?Number(weapon.appearance):0;
  weapon.appearance=materialDef.index;weapon.appearanceExpiresAt=now+seconds*1000;
  const record={id:input.requestId,signature,uid:weapon.uid,itemIndex:weapon.itemIndex,appearance:materialDef.index,expiresAt:weapon.appearanceExpiresAt,dil:cost,replaced,revision:state.revision+1};
  profile.weaponLook={revision:record.revision,receipts:[...state.receipts.slice(-(IAN_CHOSEN.receipts-1)),record]};
  const quests=createQuestContext(world,p,{profile,inventory:inv,commitToPlayer:false});quests?.engine.recountCollect(null,true);
  custody(world,p);
  await commitLife(world,p,profile);
  quests?.commit();
  world.emit(p.map,{type:'weaponlook',actorId:p.id,operation:'change',uid:weapon.uid,appearance:record.appearance,expiresAt:record.expiresAt});
  return {...receiptOut(record),replayed:false};
});}
/** Containers whose items keep a weapon appearance: bag, worn items, personal and account-shared storage. */
function holders(profile){return [profile.inventory,Object.values(profile.equip?.items||{}),profile.storage,profile.accountFeatures?.shared].filter(Array.isArray);}
/** Remove run-out appearances from a (staged) profile; returns what was cleared. */
export function clearExpiredLooks(profile,now){
  const out=[];
  for(const list of holders(profile))for(const item of list)if(appearanceExpired(item,now)){out.push({uid:item.uid,itemIndex:item.itemIndex,appearance:item.appearance});delete item.appearance;delete item.appearanceExpiresAt;}
  return out;
}
/** Per online character, every IAN_CHOSEN.sweepMs: a durable write that clears run-out appearances, then the 'expired' event.
 *  A failed write keeps the stored fields (every look builder already hides them) and retries later. */
export function tickWeaponLooks(world,p){
  const now=world.now();if((sweepAt.get(p)||0)>now)return null;sweepAt.set(p,now+IAN_CHOSEN.sweepMs);
  if(p.leaving||p.sceneTransition||p.progressCommitting||p.tradeCommitting||p.commandActive)return null;
  if(!holders(p.profile).some(list=>list.some(item=>appearanceExpired(item,now))))return null;
  return serializeLife(p,async()=>{
    if(p.leaving||world.players?.get?.(p.account)!==p)return null;
    const profile=structuredClone(p.profile),cleared=clearExpiredLooks(profile,world.now());if(!cleared.length)return null;
    try{await commitLife(world,p,profile);}catch{sweepAt.set(p,world.now()+RETRY_MS);return null;}
    world.emit(p.map,{type:'weaponlook',actorId:p.id,operation:'expired',items:cleared});
    return cleared;
  }).catch(()=>null);
}
