// The guild remainder inside the durable social state (server/world/social-state.mjs socialTransaction), dispatched
// from server/world/guilds.mjs: guild skills (guildskill.csv), guild war declaration / acceptance / surrender, member online
// state (snapshot), and the guild skill status on every member (profile.buffs `guildskill`). Rules + original sources:
// src/systems/extras/guildextras-rules.js; values the data does not define: src/config/engine-chosen-guild.js (GUILD_SKILL_CHOSEN,
// GUILD_WAR_CHOSEN, GUILD_MEMBER_CHOSEN; each value labelled ONLINE or JUDGMENT there (not in Global data)).
// State: guild.skill = {id, status, startedAt, expiresAt} (one at a time: status group 125)
//        state.guildWars = [{id, from, to, fromName, toName, days, status: pending|active|surrendered|ended, declaredAt, startAt?,
//                            endAt?, loser?, result?, cost: {dil, guildPoints}}]
//        war.kills = {guildId: n} (guild war PvP kills: server/world/guild-war-pvp.mjs)
//        member.lastSeen (ms) = the host saw the member online (GUILD_MEMBER_CHOSEN.LAST_LOGIN)
// Notices (135:x / 130:379 with arguments) are emitted to the affected characters after the transaction commits.
import {randomUUID} from 'node:crypto';
import {socialError as fail,socialRef} from './social-state.mjs';
import {sameScene} from './scene.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {STR,TEXT,WAR_DAYS,skillById,skillDilCost,warState,isOpenWar,autoAcceptTimes} from '../../src/systems/extras/guildextras-rules.js';
import {GUILD_WAR_CHOSEN,GUILD_MEMBER_CHOSEN} from '../../src/config/engine-chosen-guild.js';
import {guildWarOpponents,guildWarRivals,warSideGuilds,warKills,tickGuildWarPvp} from './guild-war-pvp.mjs';   // active wars are PvP-hostile (alliance auto-join)
import {siegeSnapshot} from './siege.mjs';   // SIEGE: the castle state rides on the guild snapshot

/** Guild operations (socialIntent field lists); new schema fields: GUILD_EXTRA_FIELDS. */
export const GUILD_EXTRA_FIELDS=['skillId','days'];
export const GUILD_EXTRA_OPERATIONS={guildSkill:['skillId'],warDeclare:['targetId','days'],warAccept:['id'],warDecline:['id'],warSurrender:['id']};
export const isGuildExtraOperation=op=>Object.hasOwn(GUILD_EXTRA_OPERATIONS,op);
export const SKILL_BUFF_KEY='guildskill';

const PENDING=GUILD_WAR_CHOSEN.PENDING_TIMEOUT_MS;
const wars=state=>Array.isArray(state.guildWars)?state.guildWars:(state.guildWars=[]);
const guildOf=(state,ref)=>Object.values(state?.guilds||{}).find(g=>g.members.some(m=>m.ref===ref))||null;
const amount=(n,label)=>{if(!Number.isSafeInteger(n)||n<0||n>10_000_000_000)fail(`${label} is invalid or exceeds its limit.`,503);return n;};
const between=(w,a,b)=>(w.from===a&&w.to===b)||(w.from===b&&w.to===a);
const involves=(w,id)=>w.from===id||w.to===id;
const refsOf=(state,ids)=>ids.flatMap(id=>state.guilds[id]?.members.map(m=>m.ref)||[]);

/** Settle records whose time passed: pending past the reply time -> automatically accepted (ONLINE, official JP notice
 *  2025-07-04: no answer within 3 days = accepted, the war starts); active past End Date -> ended. Returns notices. */
export function settleWars(world,state,notices=[]){
  const now=world.now(),list=wars(state),seen=world.guildWarAnnounced||=new Set();
  for(const w of list){
    const s=warState(w,now,PENDING);if(s===w.status)continue;
    const key=`${w.id}:${s}`,out=seen.has(key)?[]:notices;seen.add(key);   // a snapshot may already have announced this change (announceLapsed)
    if(w.status==='pending'){Object.assign(w,autoAcceptTimes(w,PENDING),{autoAccepted:true});if(s==='active')out.push({code:STR.nBegun,args:[w.fromName,w.toName],guilds:[w.from,w.to]});}
    w.status=s;
    if(s==='ended')out.push({code:STR.nEnded,args:[w.fromName,w.toName],guilds:[w.from,w.to]});
  }
  // every war is kept (lane 51 g: the former HISTORY_LIMIT 50 cap had no source)
  state.guildWars=list;
  return notices;
}

/** Guards of the guild operations: disband (135:34) / rename (135:35) while the guild (or an alliance mate) has a pending or active war.
 *  ONLINE (WAR_SOURCE_URL): alliance guilds auto-join, so a mate's open war also blocks rename / disband. */
export function guildWarGuard(world,state,g,operation){
  if(!g)return;
  const side=new Set(warSideGuilds(state,g.id));
  const open=(state.guildWars||[]).some(w=>(side.has(w.from)||side.has(w.to))&&isOpenWar(w,world.now(),PENDING));
  if(open&&operation==='disband')fail(TEXT.disbandAtWar,409);
  if(open&&operation==='rename')fail(TEXT.renameAtWar,409);
}

/** One operation inside socialTransaction. ctx: {state, profile, ref, g, input, level(row)}. Returns notices. */
export function guildExtraCommand(world,p,{state,ref,g,input,level,can}){
  const now=world.now(),op=input.operation,notices=settleWars(world,state);
  // LANE-61: Global grade boxes Enable Skill 0x100 / Declare War 0x200 / Accept War 0x400 (ui_gradewnd btn_check_12/9/11);
  // an older host without the grade callback keeps the Guild Master-only rule.
  const allowed=key=>typeof can==='function'?can(key)===true:!!g&&g.master===ref;
  if(op==='guildSkill'){
    if(!g)fail(TEXT.guildMissing,404);
    if(!allowed('enableSkill'))fail(TEXT.skillAuthority,403);                          // 130:418, grade box 0x100
    const row=Number.isInteger(input.skillId)?skillById(world.data.guild?.skills,input.skillId):null;
    if(!row)fail(TEXT.skillMissing,404);
    if(level(g)<row.needLevel)fail(TEXT.skillLevel);
    // Pay_Dil less the guild-level reduction of official guide 5 (levels 11-15: 5/7/10/12/15 %, guildextras-rules SKILL_DIL_DISCOUNT).
    amount(row.dil,'Original DIL cost');
    const gp=amount(row.gpoint,'Original GPoint cost'),pt=amount(row.adv,'Original Point cost'),dil=amount(skillDilCost(row,level(g)),'Guild DIL cost');
    if(amount(g.activityPoints??0,'GPOINT')<gp)fail(TEXT.skillNoGpoint);
    if(amount(g.gpoint??0,'Guild Points')<pt)fail(TEXT.skillNoPoint);
    if(amount(g.dil??0,'Guild DIL')<dil)fail(TEXT.skillNoDil);
    g.activityPoints=(g.activityPoints??0)-gp;g.gpoint=(g.gpoint??0)-pt;g.dil=(g.dil??0)-dil;
    g.skill={id:row.id,status:row.status,startedAt:now,expiresAt:now+row.sec*1000};   // replaces the running one (130:373), no refund
    for(const [code,n] of [[STR.usedGpoint,gp],[STR.usedPoint,pt],[STR.usedDil,dil]])if(n)notices.push({code,args:[n],refs:[ref]});
    notices.push({code:STR.skillApplied,args:[row.name],guilds:[g.id]});
    return notices;
  }
  if(op==='warDeclare'){
    if(!g)fail(TEXT.noGuildPlayer);
    if(!allowed('declareWar'))fail(TEXT.declarePermission,403);   // 135:8, grade box 0x200
    if(p.instanceId)fail(p.dkSquare?TEXT.dkSquare:TEXT.warArea);
    const target=[...world.players.values()].find(q=>q.id===input.targetId&&!q.leaving);
    if(!target||target===p||!sameScene(p,target))fail('Choose a character on your map.');
    if(target.dead)fail(TEXT.targetDead);
    const tg=guildOf(state,socialRef(target));
    if(!tg)fail(TEXT.targetNoGuild);
    if(tg.id===g.id)fail(TEXT.ownGuild);
    const a=allianceOfGuild(state,g.id);if(a&&a.guilds.includes(tg.id))fail(TEXT.alliedGuild);
    const list=wars(state),open=w=>['pending','active'].includes(w.status);
    // ONLINE: already at war if any guild on our alliance side has an open war with any guild on their side.
    const mySide=new Set(warSideGuilds(state,g.id)),theirSide=new Set(warSideGuilds(state,tg.id));
    if(list.some(w=>open(w)&&(mySide.has(w.from)&&theirSide.has(w.to)||mySide.has(w.to)&&theirSide.has(w.from))))fail(TEXT.alreadyAtWar,409);
    if(list.filter(w=>open(w)&&w.from===g.id).length>=GUILD_WAR_CHOSEN.MAX_DECLARATIONS)fail(TEXT.declareMax);   // ONLINE limit 3 (135:9)
    if(list.filter(w=>open(w)&&involves(w,tg.id)).length>=GUILD_WAR_CHOSEN.MAX_TARGET_WARS)fail(TEXT.targetMax);   // ONLINE limit 3 (135:37)
    if(!WAR_DAYS.includes(input.days))fail('Choose an original war duration.');
    const C=GUILD_WAR_CHOSEN.COST_BY_DAYS[input.days];if(!C)fail('Choose an original war duration.');
    const dil=C.dil,gp=C.guildPoints;   // ONLINE cost table by duration (GUILD_WAR_CHOSEN.COST_BY_DAYS)
    if(amount(g.dil??0,'Guild DIL')<dil)fail(TEXT.declareNoDil);
    if(amount(g.gpoint??0,'Guild Points')<gp)fail(TEXT.declareNoGp);
    g.dil-=dil;g.gpoint-=gp;
    list.push({id:randomUUID(),from:g.id,to:tg.id,fromName:g.name,toName:tg.name,days:input.days,status:'pending',declaredAt:now,cost:{dil,guildPoints:gp}});
    notices.push({code:STR.declaredOn,args:[tg.name],refs:[ref]},{code:STR.nDeclared,args:[g.name,tg.name],guilds:[g.id,tg.id]});
    return notices;
  }
  const w=typeof input.id==='string'?wars(state).find(x=>x.id===input.id):null;
  if(!g)fail(TEXT.guildMissing,404);
  if(op==='warAccept'||op==='warDecline'){
    if(!w||w.status!=='pending'||w.to!==g.id)fail('That war declaration is unavailable.',404);
    if(!allowed('acceptWar'))fail(TEXT.acceptPermission,403);   // 135:38, grade box 0x400
    // ONLINE (official JP notice): no accepting past the war limit (135:37)
    if(op==='warAccept'&&wars(state).filter(x=>x!==w&&x.status==='active'&&involves(x,g.id)).length>=GUILD_WAR_CHOSEN.MAX_TARGET_WARS)fail(TEXT.targetMax);
    if(op==='warAccept'){w.status='active';w.startAt=now;w.endAt=now+w.days*86400000;notices.push({code:STR.nBegun,args:[w.fromName,w.toName],guilds:[w.from,w.to]});}
    else{w.status='surrendered';w.result='declined';w.loser=g.id;w.endAt=now;notices.push({code:STR.declinedNotice,args:[w.fromName,STR.decline],guilds:[w.from,w.to]});}
    return notices;
  }
  if(op==='warSurrender'){
    if(!w||w.status!=='active'||!involves(w,g.id))fail('That war is not active.',404);
    if(!allowed('acceptWar'))fail(TEXT.acceptPermission,403);   // 135:38: DECOMPILE AcceptanceOfWarWnd surrender = mode 3 of the Accept War packet
    const other=w.from===g.id?w.toName:w.fromName;
    w.status='surrendered';w.result='surrender';w.loser=g.id;w.endAt=now;
    notices.push({code:STR.nSurrendered,args:[g.name,other],guilds:[w.from,w.to]});
    return notices;
  }
  fail('Unknown guild operation.');
}

/** Emit committed notices: {type:'guildNotice', code:[cate,code], args} (an argument [cate,code] is an original string). */
export function emitGuildExtraNotices(world,notices){
  const state=world.socialState;if(!state)return;
  for(const n of notices||[]){
    const refs=new Set([...(n.refs||[]),...refsOf(state,n.guilds||[])]);
    for(const q of world.players.values())if(!q.leaving&&refs.has(socialRef(q)))world.emit(q.map,{type:'guildNotice',code:n.code,args:n.args||[],recipients:[q.id]});
  }
}

/** Auto-accepted / ended wars become notices once per process (the snapshot settles views without a write; the record changes on the next write). */
function announceLapsed(world,state){
  const now=world.now(),seen=world.guildWarAnnounced||=new Set(),notices=[];
  for(const w of state.guildWars||[]){
    const s=warState(w,now,PENDING),key=`${w.id}:${s}`;if(s===w.status||seen.has(key))continue;
    seen.add(key);
    notices.push(s==='ended'?{code:STR.nEnded,args:[w.fromName,w.toName],guilds:[w.from,w.to]}:{code:STR.nBegun,args:[w.fromName,w.toName],guilds:[w.from,w.to]});
  }
  if(notices.length)emitGuildExtraNotices(world,notices);
}

/** Member rows: online state, map of an online member, last time seen online (recorded on the live member row). */
export function memberPresence(world,g){
  const now=world.now(),live=new Map([...world.players.values()].filter(q=>!q.leaving).map(q=>[socialRef(q),q]));
  return m=>{
    const q=live.get(m.ref);
    if(q&&(!(m.lastSeen>0)||now-m.lastSeen>=GUILD_MEMBER_CHOSEN.LAST_SEEN_STEP_MS))m.lastSeen=now;
    return {online:!!q,map:q?q.map:null,lastSeen:Number.isFinite(m.lastSeen)?m.lastSeen:null};
  };
}

/** Snapshot field `extras` of a guild member. helpers: {guildMark(mark), level(row)}. */
export function guildExtrasSnapshot(world,state,ref,g,helpers){
  announceLapsed(world,state);
  void Promise.resolve().then(()=>tickGuildWarPvp(world)).catch(()=>{});   // fold queued war kills (also run by the core tick); deferred so a snapshot never emits events while it is built
  const now=world.now(),list=state.guildWars||[],markOf=id=>helpers.guildMark(state.guilds[id]?.mark);
  const row=w=>{const auto=w.status==='pending'&&now>=w.declaredAt+PENDING?autoAcceptTimes(w,PENDING):null;   // auto-accepted, not yet written
    return {id:w.id,from:w.from,to:w.to,fromName:w.fromName,toName:w.toName,fromMark:markOf(w.from),toMark:markOf(w.to),days:w.days,
    status:warState(w,now,PENDING),declaredAt:w.declaredAt,startAt:auto?.startAt??w.startAt??null,endAt:auto?.endAt??w.endAt??(w.status==='pending'?w.declaredAt+PENDING:null),loser:w.loser??null,result:w.result??null,kills:warKills(world,w)};};
  const board=list.filter(w=>isOpenWar(w,now,PENDING)).map(row);
  const skill=g?.skill&&g.skill.expiresAt>now?{id:g.skill.id,startedAt:g.skill.startedAt,expiresAt:g.skill.expiresAt}:null;
  const isMaster=!!g&&g.master===ref,may=key=>typeof helpers.can==='function'?helpers.can(key)===true:isMaster;
  const can={enableSkill:may('enableSkill'),declareWar:may('declareWar'),acceptWar:may('acceptWar')};   // LANE-61 grade boxes
  return {skill,isMaster,can,board,mine:g?list.filter(w=>involves(w,g.id)).map(row).sort((a,b)=>(b.startAt??b.declaredAt)-(a.startAt??a.declaredAt)):[],
    incoming:can.acceptWar?board.filter(w=>w.to===g.id&&w.status==='pending'):[],
    war:{days:WAR_DAYS,costByDays:GUILD_WAR_CHOSEN.COST_BY_DAYS,pendingMs:PENDING,pendingResolve:GUILD_WAR_CHOSEN.PENDING_RESOLVE,maxDeclarations:GUILD_WAR_CHOSEN.MAX_DECLARATIONS},
    warFoes:helpers.player?guildWarOpponents(world,helpers.player).map(q=>q.id):[],   // combat foes (map-gated)
    warRivals:helpers.player?guildWarRivals(world,helpers.player).map(q=>q.id):[],   // ONLINE: red names even on SAFE_MAP_INDEXES
    siege:helpers.player?siegeSnapshot(world,helpers.player,helpers):null};
}

/** Keep the running guild skill's status (StatusIndex) in profile.buffs of a live member; recompute stats when it changes. */
export function syncGuildSkillBuffs(world,p,state=world.socialState){
  if(!p?.profile||!state||p.leaving||p.sceneTransition)return false;
  const now=world.now(),g=guildOf(state,socialRef(p)),statuses=world.data.itemUseData?.statuses||{};
  const s=g?.skill&&g.skill.expiresAt>now&&statuses[g.skill.status]?g.skill:null;
  const buffs=p.profile.buffs||=[];let changed=false;
  for(let i=buffs.length-1;i>=0;i--)if(buffs[i]?.key===SKILL_BUFF_KEY&&(!s||buffs[i].skillId!==s.id||buffs[i].expiresAt!==s.expiresAt)){buffs.splice(i,1);changed=true;}
  if(s&&!buffs.some(b=>b.key===SKILL_BUFF_KEY)){
    const def=statuses[s.status],skill=skillById(world.data.guild?.skills,s.id);
    buffs.push({key:SKILL_BUFF_KEY,statusIndex:s.status,skillId:s.id,name:skill?.name||def.description||'Guild Skill',description:def.description||'',iconIndex:def.iconIndex??null,
      options:(def.options||[]).map(o=>({code:o.code,value:o.value})),duration:(s.expiresAt-s.startedAt)/1000,remaining:(s.expiresAt-now)/1000,tick:0,item:true,group:def.group,expiresAt:s.expiresAt});
    changed=true;
  }
  if(changed&&typeof world.data.stats==='function'){
    p.stats=world.data.stats(p.profile,p,now);p.maxHp=p.stats.maxHp;p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp,p.stats.maxMp||0);world.changed?.(p);
  }
  return changed;
}
export function syncAllGuildSkillBuffs(world){for(const q of world.players.values())syncGuildSkillBuffs(world,q);}
