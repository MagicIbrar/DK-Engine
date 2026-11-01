import {randomUUID} from 'node:crypto';
import {characterRef} from './accounts/character-ref.mjs';
import {guildMark} from './world/guilds.mjs';
import {isGuildGloryItem} from '../src/systems/extras/guild-glory-rules.js';
import {PROMOTION_COST,meets} from '../src/systems/extras/guildboard-rules.js';

// Private host adapter only. Trusted callbacks resolve permissions/characters;
// no caller role, token, guild result, currency or owned-item claims are accepted.
// Guild writes use ordinary intents; the optional private owner hook grants a native item
// through the durable GM item service. Never rewrite social membership or permissions.
export function createAdminGuildSetup({listCandidates,readAccess,readCharacter,readState,nativeConfig,itemDef,withCharacter,visitService,send,provisionGlory=null,provisionFunds=null,now=Date.now,mark={bg:1,icon:1},gloryItems=[60040]}={}) {
 const hooks={listCandidates,readAccess,readCharacter,readState,nativeConfig,itemDef,withCharacter,visitService,send};
 if(Object.values(hooks).some(fn=>typeof fn!=='function')||!guildMark(mark)||!Array.isArray(gloryItems)||!gloryItems.length||gloryItems.some(i=>!Number.isSafeInteger(i)))throw Error('Trusted ADMIN setup hooks and native art selection are required.');
 // Default art selection is ENGINE-CHOSEN among actual selectable native cells;
 // 60040 is the supported Purple Star item. Only the private installation-owner
 // hook may provision it when ADMIN has no Glory and its master owns none.
 const selectedMark={...mark},supportedGlory=new Set(gloryItems);let flight;
 const blocked=reason=>{throw Object.assign(Error(reason),{setupReason:reason});};
 const state=async()=>{const s=await readState();if(!s||!Number.isSafeInteger(s.revision)||!s.guilds||typeof s.guilds!=='object')blocked('social-storage-unavailable');return s;};
 const gm=async c=>{const access=await readAccess(c.account);return access?.capabilities?.includes('gm:commands')===true;};
 const membership=(s,ref)=>Object.values(s.guilds).find(g=>g.members?.some(m=>m.ref===ref));
 // A private, owner-managed guild may be renamed without creating a second
 // ADMIN guild. The marker grants no permissions: validate still checks every
 // member and master against the current trusted GM roster.
 const target=s=>{const matches=Object.values(s.guilds).filter(g=>g.adminManaged===true||String(g.name).toUpperCase()==='ADMIN');if(matches.length>1||matches.some(g=>g.adminManaged!==true&&g.name!=='ADMIN'))blocked('ADMIN-name-conflict');return matches[0];};
 const profile=async c=>{const p=await readCharacter(c);if(!p||p.authority!=='server'||p.id!==c.characterId)blocked('authoritative-character-unavailable');return p;};
 const ownedGlory=p=>(p.inventory||[]).find(i=>typeof i.uid==='string'&&(i.count??1)>0&&!(i.expiresAt&&i.expiresAt<=now())&&supportedGlory.has(i.itemIndex)&&isGuildGloryItem(itemDef(i.itemIndex)));
 const number=(cfg,key,min=0)=>{const n=Number(cfg[key]);if(!Number.isSafeInteger(n)||n<min)throw Object.assign(Error('native-rule-unavailable'),{setupReason:'native-rule-unavailable',nativeRule:key});return n;};
 return {run(){if(flight)return flight;flight=execute().finally(()=>{flight=null;});return flight;}};
 async function execute(){
  const report={complete:false,membershipComplete:false,crestComplete:false,gloryComplete:false,partial:false,eligible:0,excluded:0,enrolled:0,actions:0,guild:'ADMIN',reason:null};
  try{
   const candidates=await listCandidates();if(!Array.isArray(candidates))blocked('private-roster-unavailable');
   const seen=new Set(),eligible=[],initialAccess=new Map();
   for(const c of candidates){if(!c||typeof c.account!=='string'||typeof c.characterId!=='string')blocked('private-roster-invalid');const ref=characterRef(c.account,c.characterId);if(seen.has(ref))continue;seen.add(ref);if(!initialAccess.has(c.account))initialAccess.set(c.account,await gm(c));if(!initialAccess.get(c.account)){report.excluded++;continue;}const p=await profile(c);if(p.npcSeed||p.npcPlayer)blocked('NPC-not-admin-eligible');eligible.push({...c,ref,profile:p});}
   report.eligible=eligible.length;if(!eligible.length)blocked('no-actual-GM-characters');
   const refs=new Set(eligible.map(c=>c.ref));let s=await state(),g=target(s);const cfg=await nativeConfig();if(!cfg||Number(cfg.ADV)||Number(cfg.PEERAGE))blocked('native-founding-rule-unsupported');
   const validate=async()=>{for(const account of new Set(eligible.map(c=>c.account)))if(!await gm({account}))blocked('administrator-access-changed');const current=await state(),guild=target(current);if(guild&&(!refs.has(guild.master)||guild.members.some(m=>!refs.has(m.ref))))blocked('ADMIN-ownership-conflict');for(const c of eligible){const other=membership(current,c.ref);if(other&&other!==guild)blocked('character-in-other-guild');}return {s:current,g:guild};};
   ({s,g}=await validate());
   report.enrolled=eligible.filter(c=>g?.members.some(m=>m.ref===c.ref)).length;
   report.crestComplete=!!guildMark(g?.mark);report.gloryComplete=isGuildGloryItem(itemDef(g?.glory?.itemIndex));
   if(eligible.some(c=>Object.values(s.guilds).some(row=>row!==g&&row.applications?.some(a=>a.ref===c.ref))))blocked('other-guild-application-conflict');
   const missing=()=>eligible.filter(c=>!g?.members.some(m=>m.ref===c.ref));
   const capacity=number(cfg,`LEVEL${g?.level??1}_MEMBER`,1);if((g?.members.length||0)+missing().length>capacity)blocked('native-member-capacity');
   if(g?.mark&&!guildMark(g.mark))blocked('invalid-existing-native-mark');if(g?.glory&&!isGuildGloryItem(itemDef(g.glory.itemIndex)))blocked('existing-Glory-not-supported');
   const pending=missing(),needBoard=pending.length>(g?0:1),activePromotion=g?.promotion?.expiresAt>now()?g.promotion:null;
   if(needBoard&&activePromotion&&(!activePromotion.approval||pending.some(c=>!meets(activePromotion,{level:c.profile.level,classIndex:c.profile.classIndex,grade:c.profile.grade}))))blocked('existing-promotion-conflict');
   const createCost=g?0:number(cfg,'MONEY'),markCost=g?.mark?0:number(cfg,'MARKDIL',1),boardCost=needBoard&&!activePromotion?PROMOTION_COST:0,bundle=boardCost?number(cfg,'DILTOCON',1):1;
   const deposit=boardCost?Math.ceil(Math.max(0,boardCost-(g?.dil||0))/bundle)*bundle:0;
   const founders=g?eligible.filter(c=>c.ref===g.master):eligible.filter(c=>c.profile.level>=number(cfg,'LEVEL',1));
   const requiredFunds=createCost+markCost+deposit;
   if(!Number.isSafeInteger(requiredFunds)||requiredFunds<0||requiredFunds>1e12)blocked('native-rule-unavailable');
   let funded=founders.filter(c=>Number.isSafeInteger(c.profile.dil)&&c.profile.dil>=requiredFunds);
   if(!funded.length&&typeof provisionFunds==='function'){
    for(const candidate of founders){
     await validate();
     await withCharacter(candidate,async handle=>{
      if(handle?.account!==candidate.account||handle?.characterId!==candidate.characterId)blocked('ordinary-session-mismatch');
      await provisionFunds(handle);
     });
     for(const c of founders)c.profile=await profile(c);
     funded=founders.filter(c=>Number.isSafeInteger(c.profile.dil)&&c.profile.dil>=requiredFunds);
     if(funded.length)break;
    }
   }
   const founder=funded.find(c=>ownedGlory(c.profile))||funded[0];
   if(!founder){if(!founders.length)blocked('founder-native-level-unmet');blocked('owned-funds-insufficient');}
   const perform=async(c,operation,fields={},service)=>{
    await validate();if(!await gm(c))blocked('administrator-access-changed');
    await withCharacter(c,async handle=>{if(handle?.account!==c.account||handle?.characterId!==c.characterId)blocked('ordinary-session-mismatch');if(service)await visitService(handle,service);
     const current=await state();const result=await send(handle,{type:'guild',operation,revision:current.revision,requestId:randomUUID(),...fields});if(result==null||result===false||result.ok===false)blocked('ordinary-action-rejected');});
    report.actions++;({s,g}=await validate());
   };
   if(!g)await perform(founder,'create',{name:'ADMIN'},'GUILD');
   if(!g.mark)await perform(founder,'mark',selectedMark,'GUILDMARK');
   const remaining=missing();
   if(remaining.length){
    if(!(g.promotion?.expiresAt>now())){const short=Math.max(0,PROMOTION_COST-(g.dil||0)),amount=Math.ceil(short/number(cfg,'DILTOCON',1))*number(cfg,'DILTOCON',1);if(amount)await perform(founder,'deposit',{amount},'GUILD');await perform(founder,'promote',{levelLimit:0,grade:0,classes:Array.from({length:15},(_,i)=>i),approval:true,title:'ADMIN enrollment',content:'Approval required for verified administrator characters.'},'GUILD_ADVERTISE_APPLICATION');}
    for(const c of remaining){
     ({s,g}=await validate());if(g.members.some(m=>m.ref===c.ref))continue;
     const otherApplication=Object.values(s.guilds).find(row=>row!==g&&row.applications?.some(a=>a.ref===c.ref));if(otherApplication)blocked('other-guild-application-conflict');
     if(!g.applications?.some(a=>a.ref===c.ref))await perform(c,'apply',{guildId:g.id,comment:'ADMIN enrollment'},'GUILD_ADVERTISE_LIST');
     ({s,g}=await validate());const application=g.applications?.find(a=>a.ref===c.ref);if(!application)blocked('ordinary-application-unavailable');
     // Approval only for the exact private verified target, never every applicant.
     if(!refs.has(application.ref)||!await gm(c))blocked('application-not-eligible');
     await perform(founder,'approve',{id:application.id},'GUILD_ADVERTISE_APPLICATION');report.enrolled++;
    }
   }
   ({s,g}=await validate());report.membershipComplete=!!g&&eligible.every(c=>g.members.some(m=>m.ref===c.ref));report.crestComplete=!!guildMark(g?.mark);report.partial=report.membershipComplete&&report.crestComplete;if(!report.partial)blocked('canonical-projection-incomplete');
   // Remove only our approval-required promotion, avoiding an unnecessary public
   // recruitment listing. A failed removal is retryable without replaying costs.
   if(g.promotion?.title==='ADMIN enrollment'&&g.promotion.approval)await perform(founder,'deletePromotion',{},'GUILD_ADVERTISE_APPLICATION');
   if(!g.glory){
    let owned=ownedGlory(await profile(founder));
    if(!owned&&typeof provisionGlory==='function'){
     await validate();
     await withCharacter(founder,async handle=>{
      if(handle?.account!==founder.account||handle?.characterId!==founder.characterId)blocked('ordinary-session-mismatch');
      // Recheck within the serialized session; retries reuse a successfully saved item.
      ({s,g}=await validate());if(g.glory||ownedGlory(handle.profile))return;
      await provisionGlory(handle);
     });
     ({s,g}=await validate());owned=ownedGlory(await profile(founder));
    }
    if(!g.glory){if(!owned)blocked('owned-supported-Glory-missing');await perform(founder,'glory',{uid:owned.uid});}
   }
   report.guild=g.name;report.gloryComplete=isGuildGloryItem(itemDef(g.glory?.itemIndex));report.complete=report.membershipComplete&&report.crestComplete&&report.gloryComplete;report.partial=!report.complete;if(!report.complete)blocked('canonical-projection-incomplete');
   return report;
  }catch(error){report.complete=false;report.reason=error.setupReason||'ordinary-action-failed';if(typeof error.nativeRule==='string'&&/^[A-Z0-9_]{1,40}$/.test(error.nativeRule))report.nativeRule=error.nativeRule;if(Number.isInteger(error.status))report.status=error.status;return report;}
 }
}
