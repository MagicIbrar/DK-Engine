import {gmItemIntent} from './world/gm-items.mjs';
import {characterRef} from './accounts/character-ref.mjs';
import {isGuildGloryItem} from '../src/systems/extras/guild-glory-rules.js';
import {createAdminGuildSetup} from './admin-guild-setup.mjs';
import {PROMOTION_COST,meets} from '../src/systems/extras/guildboard-rules.js';
import {createAdminGuildServiceVisit} from './admin-guild-service-visit.mjs';

// Root wires these private accounts facade methods and the world API account
// serializer. Merely binding this adapter performs no reads, joins or writes.
export function bindAdminGuildHost({world,accounts,serialize,shouldYield=()=>false,runGM=null,runBudgetMs=20000}={}){
 if(!world||typeof serialize!=='function'||typeof shouldYield!=='function'||!Number.isInteger(runBudgetMs)||runBudgetMs<1||runBudgetMs>60000||['listAdminGuildCandidates','readAdminGuildAccess','getWorldProfile'].some(k=>typeof accounts?.[k]!=='function'))throw Error('Private ADMIN facade hooks required.');
 let flight,deadline=0;const yielding=()=>shouldYield()||!!deadline&&Date.now()>=deadline;
 const fail=reason=>{throw Object.assign(Error(reason),{setupReason:reason});};
 const readAccess=account=>accounts.readAdminGuildAccess(account);
 const authorized=async account=>{if(!(await readAccess(account))?.capabilities?.includes('gm:commands'))fail('administrator-access-changed');};
 const send=async(p,intent)=>{await authorized(p.account);if(world.players.get(p.account)!==p||p.leaving)fail('ordinary-session-mismatch');if(intent.type!=='stop'&&yielding())fail('human-admission-or-setup-budget');return world.action(p.account,{...intent,token:p.token});};
 const visitService=createAdminGuildServiceVisit({world,send,shouldYield:yielding});
 const setup=createAdminGuildSetup({
  listCandidates:()=>accounts.listAdminGuildCandidates(),readAccess,
  readCharacter:c=>accounts.getWorldProfile(c.account,c.characterId),
  readState:()=>world.socialState,nativeConfig:()=>world.data.guild.config,
  itemDef:index=>world.data.itemDB.def(index),now:()=>world.now(),send,visitService,
  provisionFunds:typeof accounts.canProvisionAdminGuildSetup==='function'&&typeof runGM==='function'?async p=>{
   await authorized(p.account);
   if(!await accounts.canProvisionAdminGuildSetup(p.account))return;
   if(world.players.get(p.account)!==p||p.leaving)fail('ordinary-session-mismatch');
   if(yielding())fail('human-admission-or-setup-budget');
   const candidates=[],refs=new Set(),accessByAccount=new Map();
   for(const c of await accounts.listAdminGuildCandidates()){if(!accessByAccount.has(c.account))accessByAccount.set(c.account,await readAccess(c.account));if(!accessByAccount.get(c.account)?.capabilities?.includes('gm:commands'))continue;candidates.push(c);refs.add(characterRef(c.account,c.characterId));}
   const matches=Object.values(world.socialState.guilds).filter(g=>g.adminManaged===true||String(g.name).toUpperCase()==='ADMIN');
   if(matches.length>1||matches.some(g=>g.adminManaged!==true&&g.name!=='ADMIN'))fail('ADMIN-name-conflict');
   const guild=matches[0],ref=characterRef(p.account,p.characterId),cfg=world.data.guild.config;
   if(!refs.has(ref)||p.profile.npcSeed||p.profile.npcPlayer||Number(cfg.ADV)||Number(cfg.PEERAGE))fail('ADMIN-ownership-conflict');
   if(guild&&(guild.master!==ref||guild.members.some(m=>!refs.has(m.ref))))fail('ADMIN-ownership-conflict');
   for(const g of Object.values(world.socialState.guilds))if(g!==guild&&(g.members?.some(m=>refs.has(m.ref))||g.applications?.some(a=>refs.has(a.ref))))fail('character-in-other-guild');
   const num=(key,min=0)=>{const n=Number(cfg[key]);if(!Number.isSafeInteger(n)||n<min)throw Object.assign(Error('native-rule-unavailable'),{setupReason:'native-rule-unavailable',nativeRule:key});return n;};
   const missing=candidates.filter(c=>!guild?.members.some(m=>m.ref===characterRef(c.account,c.characterId))),needBoard=missing.length>(guild?0:1),promotion=guild?.promotion?.expiresAt>world.now()?guild.promotion:null;
   if((guild?.members.length||0)+missing.length>num('LEVEL'+(guild?.level??1)+'_MEMBER',1))fail('native-member-capacity');
   if(!guild&&p.profile.level<num('LEVEL',1))fail('founder-native-level-unmet');
   if(needBoard&&promotion){for(const c of missing){const profile=await accounts.getWorldProfile(c.account,c.characterId);if(!promotion.approval||!meets(promotion,{level:profile.level,classIndex:profile.classIndex,grade:profile.grade}))fail('existing-promotion-conflict');}}
   const bundle=needBoard&&!promotion?num('DILTOCON',1):1,deposit=needBoard&&!promotion?Math.ceil(Math.max(0,PROMOTION_COST-(guild?.dil||0))/bundle)*bundle:0;
   const required=(guild?0:num('MONEY'))+(guild?.mark?0:num('MARKDIL',1))+deposit;
   // Fresh authoritative characters omit DIL until their first currency action.
   // Match the ordinary GM currency handler's absent balance without accepting malformed values.
   const balance=p.profile.dil===undefined?0:p.profile.dil;
   if(!Number.isSafeInteger(required)||required<0||required>1e12||!Number.isSafeInteger(balance)||balance<0)fail('native-rule-unavailable');
   const shortfall=Math.max(0,required-balance);if(!shortfall)return;
   await authorized(p.account);if(!await accounts.canProvisionAdminGuildSetup(p.account))fail('administrator-access-changed');
   // Existing durable GM currency command, exact remaining native setup costs only.
   const result=await runGM(world,{id:p.account,...await readAccess(p.account)},{token:p.token,line:'/gm dil '+shortfall});
   if(result===false||result?.ok===false)fail('ordinary-action-rejected');
  }:null,
  provisionGlory:typeof accounts.canProvisionAdminGuildGlory==='function'?async p=>{
   await authorized(p.account);
   if(!await accounts.canProvisionAdminGuildGlory(p.account))return;
   if(world.players.get(p.account)!==p||p.leaving)fail('ordinary-session-mismatch');
   if(yielding())fail('human-admission-or-setup-budget');
   const guild=Object.values(world.socialState.guilds).find(g=>g.adminManaged===true||g.name==='ADMIN');
   if(!guild||guild.master!==characterRef(p.account,p.characterId)||guild.glory)fail('ADMIN-ownership-conflict');
   if(!isGuildGloryItem(world.data.itemDB.def(60040)))fail('native-Glory-item-unavailable');
   // Exact native item only; canonical inventory placement and durable save are
   // shared with the GM Item Maker. Activation consumes it through guildCommand.
   await gmItemIntent(world,p,{operation:'makeItem',spec:{item:60040,count:1,to:'bag',roll:false}});
  }:null,
  withCharacter:(c,fn)=>serialize(c.account,async()=>{
   await authorized(c.account);if(yielding())fail('human-admission-or-setup-budget');if(world.players.has(c.account))fail('existing-session-active');
   let p;
   try{await world.join(c.account,c.characterId);p=world.players.get(c.account);if(!p||p.characterId!==c.characterId)fail('ordinary-session-mismatch');return await fn(p);}
   finally{if(p&&world.players.get(c.account)===p)await world.leave(c.account,p.token);}
  }),
 });
 // Budget is cooperative: never race or abandon an in-flight durable write.
 return {run(){if(flight)return flight;deadline=Date.now()+runBudgetMs;flight=setup.run().finally(()=>{flight=null;deadline=0;});return flight;}};
}
