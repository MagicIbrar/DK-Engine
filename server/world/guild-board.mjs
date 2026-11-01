// GUILD-BOARD host: guild publicity (recruitment board), applications, the guild record (history) and the Best Guild War
// representatives, all inside the guild social transaction of server/world/guilds.mjs (one durable CAS write per intent; the
// actor's profile and every guild change commit together). Rules + original sources: src/systems/extras/guildboard-rules.js.
import {randomUUID} from 'node:crypto';
import {nearbyNpc} from './npc-services.mjs';
import {socialRef} from './social-state.mjs';
import * as R from '../../src/systems/extras/guildboard-rules.js';

const PROMOTION=['levelLimit','grade','classes','approval','title','content'];
export const BOARD_OPERATIONS={promote:PROMOTION,editPromotion:PROMOTION,deletePromotion:[],apply:['guildId','comment'],cancelApply:[],approve:['id'],reject:['id'],bestGuild:['members']};
export const BOARD_SCHEMA_FIELDS=['levelLimit','grade','classes','approval','title','content','guildId','comment','members'];
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const active=(g,now)=>g?.promotion&&g.promotion.expiresAt>now?g.promotion:null;

export function pendingApplication(state,ref){
  for(const g of Object.values(state.guilds))for(const a of g.applications||[])if(a.ref===ref)return {guild:g,application:a};
  return null;
}
/** Drop every pending application of a character (it joined a guild some other way). */
export function clearApplications(state,ref){for(const g of Object.values(state.guilds))if(g.applications?.some(a=>a.ref===ref))g.applications=g.applications.filter(a=>a.ref!==ref);}
export function recordHistory(g,entry,now){g.history=[...(Array.isArray(g.history)?g.history:[]),{at:now,...entry}].slice(-R.HISTORY_LIMIT);}

/** Member class/level for the windows: live profile, else the account roster (refreshed every 5 s like the social names), else the join record. */
export function memberDetail(world){
  if(world.listCharacters&&!world.guildRosterLoading&&world.now()-(world.guildRosterAt??-Infinity)>=5000){
    world.guildRosterAt=world.now();
    world.guildRosterLoading=Promise.resolve().then(()=>world.listCharacters()).then(rows=>{world.guildRoster=new Map(rows.map(c=>[c.ref,{classIndex:c.classIndex,level:c.level}]));}).catch(()=>{}).finally(()=>{world.guildRosterLoading=null;});
  }
  const live=new Map([...world.players.values()].filter(q=>!q.leaving).map(q=>[socialRef(q),q.profile]));
  return (m,ref)=>{const p=live.get(ref),r=world.guildRoster?.get(ref);
    return {classIndex:Number.isInteger(p?.classIndex)?p.classIndex:Number.isInteger(r?.classIndex)?r.classIndex:m.classIndex??null,level:Number(p?.level??r?.level??m.level??m.observedLevel)||0};};
}

/** Snapshot fields: the public board (every active promotion), my pending application and, for members, the guild's own records. */
export function boardSnapshot(world,state,ref,g,{level,cap,names}){
  const now=world.now(),best=Number(world.data.guild?.config?.BEST_GUILD)||0;
  const board=Object.values(state.guilds).filter(row=>active(row,now)).map(row=>{const pr=row.promotion;
    return {guildId:row.id,name:row.name,level:level(row),members:row.members.length,cap:cap(row),master:names(row.master,row.members.find(m=>m.ref===row.master)?.name),mark:row.mark||null,createdAt:row.createdAt||0,
      levelLimit:pr.levelLimit,grade:pr.grade,classes:pr.classes,approval:pr.approval,title:pr.title,content:pr.content,registeredAt:pr.registeredAt,expiresAt:pr.expiresAt};})
    .sort((a,b)=>b.registeredAt-a.registeredAt||a.name.localeCompare(b.name));
  const mine=pendingApplication(state,ref);
  const out={board,application:mine?{guildId:mine.guild.id,guildName:mine.guild.name,at:mine.application.at}:null,promotionCost:R.PROMOTION_COST,promotionDays:R.PROMOTION_DAYS};
  if(!g)return out;
  const own=active(g,now);
  return {...out,createdAt:g.createdAt||0,promotion:own?{...own,classes:[...own.classes]}:null,
    applications:g.master===ref?(g.applications||[]).map(a=>({id:a.id,name:a.name,level:a.level,classIndex:a.classIndex,grade:a.grade,comment:a.comment,at:a.at})):[],
    history:(g.history||[]).map(h=>({...h})),bestGuild:{count:best,members:[...(g.bestGuild?.members||[])],at:g.bestGuild?.at||0}};
}

/** One board intent. `ctx` = helpers of guilds.mjs: cap(g), join(g, record) (adds a member + activity ledger). */
export function boardCommand(world,p,{state,profile,ref,g,input,cap,join}){
  const now=world.now(),op=input.operation;
  if(op==='apply'){
    if(g)fail(R.TEXT.member);
    if(!nearbyNpc(world,p,{role:R.ROLE.list}))fail('Use a nearby Guild sign.',403);
    if(pendingApplication(state,ref))fail(R.TEXT.applying,409);
    const target=typeof input.guildId==='string'&&state.guilds[input.guildId];
    if(!target)fail(R.TEXT.noGuild,404);
    const pr=active(target,now);if(!pr)fail(R.TEXT.ended,409);
    const comment=R.checkComment(input.comment);if(comment.error)fail(`Application messages can contain at most ${R.COMMENT_MAX} characters.`);
    const me={level:Number(profile.level)||0,classIndex:profile.classIndex,grade:Number(profile.grade)||0};
    if(!R.meets(pr,me))fail(R.TEXT.meet);
    if(!pr.approval){if(target.members.length>=cap(target))fail(R.TEXT.full);join(target,{ref,name:profile.name,level:me.level,classIndex:me.classIndex});return {joined:target.name};}
    target.applications=Array.isArray(target.applications)?target.applications:[];
    if(target.applications.length>=R.APPLICATION_LIMIT)fail(R.TEXT.applicantsFull,409);
    target.applications.push({id:randomUUID(),ref,name:profile.name,level:me.level,classIndex:me.classIndex,grade:me.grade,comment:comment.value,at:now});
    return {applied:target.name};
  }
  if(op==='cancelApply'){const mine=pendingApplication(state,ref);if(!mine)fail('You have no pending guild application.',404);mine.guild.applications=mine.guild.applications.filter(a=>a!==mine.application);return {canceled:mine.guild.name};}
  if(!g)fail(R.TEXT.noGuild,403);
  if(op==='bestGuild'){
    if(g.master!==ref)fail(R.TEXT.bestMaster,403);
    const count=Number(world.data.guild?.config?.BEST_GUILD);if(!Number.isInteger(count)||count<1)fail('The original Best Guild War rule is unavailable.',503);
    const detail=memberDetail(world),members=g.members.map(m=>({ref:m.ref,...detail(m,m.ref)}));
    const checked=R.checkBest(input.members,members,count);if(checked.error)fail(R.TEXT[checked.error]);
    g.bestGuild={members:checked.value,at:now};return {bestGuild:true};
  }
  if(['approve','reject'].includes(op)){
    if(g.master!==ref)fail(R.TEXT.approveLeader,403);
    if(!nearbyNpc(world,p,{role:R.ROLE.manage}))fail('Use a nearby guild publicity service.',403);
    const a=(g.applications||[]).find(row=>row.id===input.id);if(!a)fail('That application is unavailable.',404);
    g.applications=g.applications.filter(row=>row!==a);
    if(op==='reject')return {rejected:a.name};
    if(Object.values(state.guilds).some(row=>row.members.some(m=>m.ref===a.ref)))fail(R.TEXT.member,409);
    if(g.members.length>=cap(g))fail(R.TEXT.full);
    join(g,{ref:a.ref,name:a.name,level:a.level,classIndex:a.classIndex});return {approved:a.name};
  }
  // promote / editPromotion: the guild leader at the guild publicity service (Blake, job 135); deletePromotion also from the promotion's
  // own 'More information' window at a Guild sign (job 134, btn_delete 134:46).
  if(g.master!==ref)fail(R.TEXT.leaderOnly,403);
  if(!nearbyNpc(world,p,{role:R.ROLE.manage})&&!(op==='deletePromotion'&&nearbyNpc(world,p,{role:R.ROLE.list})))fail('Use a nearby guild publicity service.',403);
  const own=active(g,now);
  if(op==='deletePromotion'){if(!own)fail('The guild has no registered promotion.',404);delete g.promotion;g.applications=[];return {deleted:true};}
  const checked=R.checkPromotion(Object.fromEntries(PROMOTION.map(k=>[k,input[k]])));
  if(checked.error)fail(R.TEXT.conditions);
  if(op==='editPromotion'){if(!own)fail('The guild has no registered promotion.',404);g.promotion={...own,...checked.value};return {edited:true};}
  if(own)fail(R.TEXT.already,409);
  if(!Number.isSafeInteger(g.dil)||g.dil<R.PROMOTION_COST)fail(R.TEXT.noDil);
  g.dil-=R.PROMOTION_COST;g.applications=[];
  g.promotion={...checked.value,registeredAt:now,expiresAt:now+R.PROMOTION_DAYS*R.DAY_MS};
  recordHistory(g,{type:'use',name:profile.name,amount:R.PROMOTION_COST},now);
  return {registered:true};
}
