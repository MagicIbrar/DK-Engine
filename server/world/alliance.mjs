// ALLIANCE: the guild alliance, inside the durable social state (server/world/social-state.mjs socialTransaction).
// Rules + original sources: src/systems/extras/alliance-rules.js (share/guild/alliance.csv via gamedata life.json guild.alliance,
// share/maplist.csv IsCreateAlliance / IsInviteAlliance, stringtable_alliance cate 140). Values the data does not define:
// src/config/engine-chosen-guild.js ALLIANCE_CHOSEN (each value labelled with its source; LANE-61 removed the request / naming timeouts).
// State: state.alliances[id] = {id, name, commander: guildId, guilds: [guildId], notice, mark?, glory?, createdAt}
//        state.allianceRequests = [{id, kind: form|join, stage: invite|naming, allianceId?, fromGuild, fromRef, fromName,
//                                   toGuild, toRef, toName}]  (LANE-61: no expiresAt; requestLive below)
// The host answers with the original texts (TEXT, = the 140:x / 130:x strings without markup); the client shows the 140:x string.
// Notices (140:x with arguments) are emitted to the affected characters after the transaction commits.
import {randomUUID} from 'node:crypto';
import {socialError as fail,socialLive,socialRef} from './social-state.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {MIN_GUILD_LEVEL,MAX_GUILDS,MIN_GUILDS,NOTICE_MAX,NAME_MAX,STR,TEXT,mapAllianceFlags,isGloryItem} from '../../src/systems/extras/alliance-rules.js';
import {ALLIANCE_CHOSEN} from '../../src/config/engine-chosen-guild.js';

/** Guild operations (socialIntent field lists). Every field already exists in GUILD_SCHEMAS.guild. */
export const ALLIANCE_OPERATIONS={allianceInvite:['name'],allianceAccept:['id'],allianceDecline:['id'],allianceCreate:['id','name'],allianceCancel:['id'],
  allianceKick:['id'],allianceLeave:[],allianceDelegate:['name'],allianceNotice:['notice'],allianceMark:['bg','icon'],allianceGlory:['uid'],allianceDeleteGlory:[]};
export const isAllianceOperation=op=>Object.hasOwn(ALLIANCE_OPERATIONS,op);

const alliances=state=>state.alliances||={};
const requests=state=>Array.isArray(state.allianceRequests)?state.allianceRequests:(state.allianceRequests=[]);
/** The alliance a guild belongs to (or null). */
export function allianceOfGuild(state,guildId){return guildId?Object.values(state?.alliances||{}).find(a=>a.guilds.includes(guildId))||null:null;}
const online=(world,ref)=>[...world.players.values()].find(q=>!q.leaving&&socialRef(q)===ref)||null;
/** LANE-61: a request has no lifetime (REMOVED: no timeout in Global 140, the decompiles, the older server reference or online).
 *  It stands until it is answered or cancelled, or one of Global's cancel reasons (140:120-129) applies: the requester went
 *  offline or is no longer the guild master, or a guild is gone. Old saved requests with an expiresAt are read the same way. */
const requestLive=(world,state,r)=>!!(state.guilds[r.fromGuild]&&state.guilds[r.toGuild]&&state.guilds[r.fromGuild].master===r.fromRef&&online(world,r.fromRef));
const pendingOf=(world,state,guildId)=>(state.allianceRequests||[]).find(r=>requestLive(world,state,r)&&(r.fromGuild===guildId||r.toGuild===guildId))||null;
const byName=(world,name)=>{const key=typeof name==='string'?name.normalize('NFC').trim().toLowerCase():'';return key?[...world.players.values()].find(q=>!q.leaving&&String(q.profile?.name||'').toLowerCase()===key)||null:null;};
const allRefs=(state,a)=>a.guilds.flatMap(id=>state.guilds[id]?.members.map(m=>m.ref)||[]);
const guildRefs=(state,id)=>state.guilds[id]?.members.map(m=>m.ref)||[];
const isExecutive=(state,a,ref)=>a.guilds.some(id=>state.guilds[id]?.master===ref);   // ENGINE-CHOSEN EXECUTIVES: member guild masters
const isCommander=(state,a,ref)=>state.guilds[a.commander]?.master===ref;
function mapFlags(world,p){
  const maps=world.data.dungeonData?.dg?.maps;if(!maps)fail('The original map alliance rules are unavailable.',503);
  return mapAllianceFlags(maps,p.map);
}
function cost(world,key){const n=Number(world.data.guild?.alliance?.[key]);if(!Number.isSafeInteger(n)||n<0)fail(`Original alliance rule ${key} is unavailable.`,503);return n;}
/** Alliance name: 1..20 characters (ui_alliancename.txt edit maxlength 20), no control / format characters. */
export function checkAllianceName(value){
  const name=typeof value==='string'?value.normalize('NFC').trim():'';
  return !name||[...name].length>NAME_MAX||/[\p{Cc}\p{Cf}\p{Cs}]/u.test(name)?null:name;
}
function dissolveIfSmall(state,a,notices){
  if(a.guilds.length>=MIN_GUILDS)return false;
  notices.push({code:STR.disbanded,refs:allRefs(state,a)});     // 140:31; ENGINE-CHOSEN DISBAND_REFUND 0
  delete alliances(state)[a.id];return true;
}

/** Guards of the guild operations (130:218 / 130:219 / 130:322 / 130:323). */
export function allianceGuildGuard(world,state,g,operation){
  if(!g)return;
  const a=allianceOfGuild(state,g.id);
  if(operation==='disband'){if(a)fail(TEXT.guildAlliedDisband,409);if(pendingOf(world,state,g.id))fail(TEXT.guildFormingDisband,409);}
  if(operation==='transfer'&&a&&a.commander===g.id)fail(TEXT.guildCommanderTransfer,409);
}

/** One alliance operation inside socialTransaction. ctx: {state, profile, ref, g, input, level(row), guildMark(mark)}. Returns notices. */
export function allianceCommand(world,p,{state,profile,ref,g,input,level,guildMark}){
  const now=world.now(),op=input.operation,notices=[];
  state.allianceRequests=requests(state).filter(r=>requestLive(world,state,r));
  const a=g?allianceOfGuild(state,g.id):null;
  if(op==='allianceInvite'){
    if(!g)fail(TEXT.reqNoGuild);
    if(g.master!==ref)fail(TEXT.reqNotMaster,403);
    const flags=mapFlags(world,p);
    if(a){
      if(a.commander!==g.id)fail(TEXT.onlyCommanderInvite,403);
      if(a.guilds.length>=MAX_GUILDS)fail(TEXT.full);
      if(!flags.invite)fail(TEXT.inviteMap);
    }else{
      if(level(g)<MIN_GUILD_LEVEL)fail(TEXT.reqLevel);
      if(!Number.isSafeInteger(profile.dil)||profile.dil<cost(world,'MONEY'))fail(TEXT.reqDil);
      if(!flags.create)fail(TEXT.createMap);
    }
    if(pendingOf(world,state,g.id))fail(TEXT.reqBusy,409);
    const target=byName(world,input.name);if(!target)fail(TEXT.targetOffline,404);
    const targetRef=socialRef(target),tg=Object.values(state.guilds).find(row=>row.members.some(m=>m.ref===targetRef));
    if(!tg)fail(TEXT.noGuild,404);
    if(tg.id===g.id)fail(TEXT.reqSameGuild);
    if(tg.master!==targetRef)fail(TEXT.targetCondition);
    if(level(tg)<MIN_GUILD_LEVEL)fail(TEXT.targetLevel);
    if(allianceOfGuild(state,tg.id))fail(TEXT.targetInAlliance,409);
    if(pendingOf(world,state,tg.id))fail(TEXT.targetForming,409);
    if(!mapAllianceFlags(world.data.dungeonData.dg.maps,target.map).invite)fail(TEXT.targetMap);
    state.allianceRequests.push({id:randomUUID(),kind:a?'join':'form',stage:'invite',...(a?{allianceId:a.id}:{}),fromGuild:g.id,fromRef:ref,fromName:profile.name,toGuild:tg.id,toRef:targetRef,toName:target.profile.name});
    notices.push({code:STR.invited,args:[tg.name],refs:[ref]});   // 140:20
    return notices;
  }
  if(op==='allianceAccept'||op==='allianceDecline'){
    const r=state.allianceRequests.find(row=>row.id===input.id&&row.toRef===ref&&row.stage==='invite');
    if(!r)fail(plainOf(STR.cancelledOffline),404);
    const from=state.guilds[r.fromGuild],tg=state.guilds[r.toGuild];
    if(op==='allianceDecline'){
      state.allianceRequests=state.allianceRequests.filter(row=>row!==r);
      notices.push({code:STR.declinedBy,args:[tg.name],refs:[r.fromRef]},{code:STR.declined,refs:[ref]});   // 140:13 / 140:29
      return notices;
    }
    if(!g||g.id!==tg.id||tg.master!==ref)fail(TEXT.targetCondition,409);
    if(allianceOfGuild(state,tg.id))fail(TEXT.targetInAlliance,409);
    if(!online(world,r.fromRef)){state.allianceRequests=state.allianceRequests.filter(row=>row!==r);fail(plainOf(STR.cancelledOffline),409);}
    if(r.kind==='form'){
      r.stage='naming';
      notices.push({code:STR.agreed,refs:[ref]});   // 140:28; the requester names the alliance (snapshot outgoing stage naming)
      return notices;
    }
    const host=alliances(state)[r.allianceId];
    if(!host||host.commander!==r.fromGuild||from.master!==r.fromRef){state.allianceRequests=state.allianceRequests.filter(row=>row!==r);fail('Cannot find the host Alliance; the Alliance admission has been cancelled.',409);}   // 140:128
    if(host.guilds.length>=MAX_GUILDS)fail(TEXT.full);
    host.guilds.push(tg.id);state.allianceRequests=state.allianceRequests.filter(row=>row!==r);
    notices.push({code:STR.joinedYou,refs:guildRefs(state,tg.id)},{code:STR.joined,args:[tg.name],refs:host.guilds.filter(id=>id!==tg.id).flatMap(id=>guildRefs(state,id))});   // 140:15 / 140:34
    return notices;
  }
  if(op==='allianceCreate'){
    const r=state.allianceRequests.find(row=>row.id===input.id&&row.fromRef===ref&&row.kind==='form'&&row.stage==='naming');
    if(!r)fail(plainOf(STR.nameCancelled),404);
    const name=checkAllianceName(input.name);if(!name)fail(TEXT.nameBad);
    if(Object.values(alliances(state)).some(row=>row.name.toLowerCase()===name.toLowerCase()))fail(TEXT.nameTaken,409);
    const tg=state.guilds[r.toGuild];
    if(!g||g.id!==r.fromGuild||g.master!==ref)fail(TEXT.reqNotMaster,403);
    if(a||allianceOfGuild(state,tg.id))fail(TEXT.targetInAlliance,409);
    if(level(g)<MIN_GUILD_LEVEL)fail(TEXT.reqLevel);
    if(!mapFlags(world,p).create)fail(TEXT.createMap);
    const money=cost(world,'MONEY');if(!Number.isSafeInteger(profile.dil)||profile.dil<money)fail(TEXT.reqDil);
    profile.dil-=money;
    const id=randomUUID();alliances(state)[id]={id,name,commander:g.id,guilds:[g.id,tg.id],notice:'',createdAt:now};
    state.allianceRequests=state.allianceRequests.filter(row=>row!==r);
    notices.push({code:STR.formed,args:[money],refs:[ref]},{code:STR.joinedYou,refs:[...guildRefs(state,g.id),...guildRefs(state,tg.id)].filter(x=>x!==ref)});   // 140:58 / 140:15
    return notices;
  }
  if(op==='allianceCancel'){
    const r=state.allianceRequests.find(row=>row.id===input.id&&row.fromRef===ref);
    if(!r)fail(plainOf(STR.cancelledOffline),404);
    state.allianceRequests=state.allianceRequests.filter(row=>row!==r);
    const form=r.kind==='form';
    notices.push({code:form?STR.requesterCancelled:STR.admissionCancelled,refs:[r.toRef]},{code:form?STR.formCancelled:STR.inviteCancelled,refs:[ref]});   // 140:120/125, 140:26/27
    return notices;
  }
  if(!g)fail(TEXT.leaveNoGuild,403);
  if(op==='allianceKick'){
    if(!a)fail(TEXT.leaveNotAllied);
    if(!isCommander(state,a,ref))fail(TEXT.expelPermission,403);
    if(input.id===a.commander)fail(TEXT.expelCommander);
    if(typeof input.id!=='string'||!a.guilds.includes(input.id))fail(TEXT.noExpel);
    const out=state.guilds[input.id];a.guilds=a.guilds.filter(id=>id!==input.id);
    notices.push({code:STR.youExpelled,refs:guildRefs(state,input.id)},{code:STR.expelled,args:[out?.name||''],refs:allRefs(state,a)});   // 140:32 / 140:33
    dissolveIfSmall(state,a,notices);return notices;
  }
  if(op==='allianceLeave'){
    if(!a)fail(TEXT.leaveNotAllied);
    if(g.master!==ref)fail(TEXT.leavePermission,403);
    if(a.commander===g.id)fail(TEXT.leaveCommander);
    a.guilds=a.guilds.filter(id=>id!==g.id);
    notices.push({code:STR.youLeft,refs:guildRefs(state,g.id)},{code:STR.left,args:[g.name],refs:allRefs(state,a)});   // 140:30 / 140:35
    dissolveIfSmall(state,a,notices);return notices;
  }
  if(op==='allianceDelegate'){
    if(!a)fail(TEXT.leaveNotAllied);
    if(!isCommander(state,a,ref))fail(TEXT.delegatePermission,403);
    const key=typeof input.name==='string'?input.name.normalize('NFC').trim().toLowerCase():'';
    if(key&&key===String(profile.name).toLowerCase())fail(TEXT.delegateSame);
    const target=byName(world,input.name),targetRef=target&&socialRef(target),tg=target&&a.guilds.map(id=>state.guilds[id]).find(row=>row?.master===targetRef);
    if(!tg||tg.id===a.commander)fail(TEXT.delegateTarget);
    a.commander=tg.id;
    notices.push({code:STR.delegated,refs:[ref]},{code:STR.newCommander,args:[target.profile.name],refs:allRefs(state,a)});   // 140:77 / 140:23
    return notices;
  }
  if(op==='allianceNotice'){
    if(!a)fail(TEXT.noticeNotAllied);
    if(!isCommander(state,a,ref))fail(TEXT.noticePermission,403);   // ENGINE-CHOSEN NOTICE_EDITOR: commander
    if(typeof input.notice!=='string'||[...input.notice].length>NOTICE_MAX)fail(TEXT.noticeLong);
    if(/[\x00-\x08\x0b\x0c\x0e-\x1f\x7f]/.test(input.notice))fail('The notice contains unsupported characters.');
    a.notice=input.notice;
    notices.push({code:STR.noticeChanged,refs:[ref]},{code:STR.noticeChangedAll,refs:allRefs(state,a).filter(x=>x!==ref)});   // 140:83 / 140:131
    return notices;
  }
  if(op==='allianceMark'){
    if(!nearbyNpc(world,p,{role:'ALLIANCE_MARK'}))fail('Use a nearby alliance mark service.',403);
    if(!a)fail(TEXT.markNotMember);
    if(!isCommander(state,a,ref))fail(TEXT.markPermission,403);   // ENGINE-CHOSEN MARK_EDITOR: commander
    const mark=guildMark({bg:input.bg,icon:input.icon});if(!mark)fail('Choose an original alliance mark background and icon.');
    const price=cost(world,'MARKDIL');if(!Number.isSafeInteger(profile.dil)||profile.dil<price)fail(TEXT.markDil);
    profile.dil-=price;a.mark=mark;
    notices.push({code:STR.markChanged,args:[price],refs:[ref]});   // 140:68
    return notices;
  }
  if(op==='allianceGlory'){
    if(!a)fail(TEXT.gloryNotInAlliance);
    if(!isCommander(state,a,ref))fail(TEXT.gloryPermission,403);
    const db=world.data.itemDB;if(!db)fail('The item catalog is unavailable.',503);
    const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
    const entry=typeof input.uid==='string'?inventory.bag.list.find(item=>item.uid===input.uid):null;
    if(!entry||!isGloryItem(db.def(entry.itemIndex)))fail('Cannot find the item.');   // 140:135
    if(!inventory.consumeEntry(entry,1))fail('Cannot find the item.');
    a.glory={itemIndex:entry.itemIndex};
    notices.push({code:STR.gloryChanged,refs:allRefs(state,a)});   // 140:132
    return notices;
  }
  if(op==='allianceDeleteGlory'){
    if(!nearbyNpc(world,p,{role:'DELETEALLIANCEMARK'}))fail('Use a nearby alliance mark deletion service.',403);
    if(!a)fail(TEXT.gloryNotInAlliance);
    if(!isCommander(state,a,ref))fail(TEXT.gloryDeletePermission,403);
    if(!a.glory)fail(TEXT.gloryNone);
    delete a.glory;
    notices.push({code:STR.gloryDeleted,refs:[ref]});   // 140:57
    return notices;
  }
  fail('Unknown alliance operation.');
}
// Plain host text of codes without a TEXT entry (the original string without markup).
const PLAIN={'140:14':'The Alliance creation/invitation has been cancelled or the target is offline.','140:61':'The Alliance formation has been cancelled.'};
const plainOf=([c,n])=>PLAIN[`${c}:${n}`]||'The Alliance request is unavailable.';

/** Emit the committed notices: {type:'allianceNotice', code:[140,x], args} to each online recipient. */
export function emitAllianceNotices(world,notices){
  for(const n of notices||[]){
    const refs=new Set(n.refs||[]),recipients=[...world.players.values()].filter(q=>!q.leaving&&refs.has(socialRef(q)));
    for(const q of recipients)world.emit(q.map,{type:'allianceNotice',code:n.code,args:n.args||[],recipients:[q.id]});
  }
}

/** Alliance chat ('$', channel 16): executives speak (140:112), every member of the alliance's guilds reads. */
export function allianceChat(world,p,input){
  if(Object.keys(input).some(k=>!['token','type','operation','text'].includes(k)))fail('Send alliance chat intent only.');
  socialLive(world,p);
  const state=world.socialState,ref=socialRef(p),g=state&&Object.values(state.guilds).find(row=>row.members.some(m=>m.ref===ref));
  if(!g)fail(TEXT.leaveNoGuild,403);
  const a=allianceOfGuild(state,g.id);if(!a)fail(TEXT.leaveNotAllied,403);
  if(!isExecutive(state,a,ref))fail(TEXT.chatExecutives,403);
  if(world.now()<(p.muteUntil||0))fail('Your chat is temporarily restrained.',403);
  if(typeof input.text!=='string'||!input.text.trim()||input.text.length>250)fail('Chat must contain 1-250 characters.');
  const text=input.text.replace(/[\x00-\x1f\x7f]/g,' ').trim();if(!text)fail('Chat message is empty.');
  if(world.now()<(p.chatAt||0))fail('Wait one second between chat messages.',429);
  p.chatAt=world.now()+1000;
  const refs=new Set(allRefs(state,a)),recipients=[...world.players.values()].filter(q=>!q.leaving&&refs.has(socialRef(q))).map(q=>q.id);
  world.emit(p.map,{type:'chat',channel:'alliance',actorId:p.id,name:p.profile.name,text,recipients});
}

/** Snapshot field `alliance` of a guild member. helpers: {names(ref, fallback), level(row), guildMark(mark)}. */
export function allianceSnapshot(world,state,ref,g,helpers){
  const list=(state.allianceRequests||[]).filter(r=>requestLive(world,state,r));
  const a=g?allianceOfGuild(state,g.id):null,guildRow=id=>{const row=state.guilds[id];if(!row)return null;const m=row.members.find(x=>x.ref===row.master);
    return {id,name:row.name,masterName:helpers.names(row.master,m?.name||''),members:row.members.length,level:helpers.level(row),mark:helpers.guildMark(row.mark)};};
  const current=a?{id:a.id,name:a.name,commanderGuild:a.commander,commanderName:helpers.names(state.guilds[a.commander]?.master,guildRow(a.commander)?.masterName||''),
    isCommander:isCommander(state,a,ref),isExecutive:isExecutive(state,a,ref),notice:a.notice||'',mark:helpers.guildMark(a.mark),glory:a.glory?{itemIndex:a.glory.itemIndex}:null,
    guilds:a.guilds.map(guildRow).filter(Boolean)}:null;
  const incoming=list.filter(r=>r.toRef===ref&&r.stage==='invite').map(r=>({id:r.id,kind:r.kind,guildName:state.guilds[r.fromGuild].name,from:r.fromName,
    allianceName:r.allianceId?state.alliances?.[r.allianceId]?.name||'':'',expiresAt:null}));
  const outgoing=list.filter(r=>r.fromRef===ref).map(r=>({id:r.id,kind:r.kind,stage:r.stage,guildName:state.guilds[r.toGuild].name,to:r.toName,expiresAt:null}));
  const n=k=>{const v=Number(world.data.guild?.alliance?.[k]);return Number.isSafeInteger(v)?v:null;};
  return {current,incoming,outgoing,formCost:n('MONEY'),markCost:n('MARKDIL'),inviteTimeoutMs:ALLIANCE_CHOSEN.INVITE_TIMEOUT_MS,namingTimeoutMs:ALLIANCE_CHOSEN.NAMING_TIMEOUT_MS};
}
