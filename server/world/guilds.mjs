import {randomUUID} from 'node:crypto';
import {guildSiegeRoster,setGuildSiegeRoster} from './guild-siege-roster.mjs';
import {sameScene} from './scene.mjs';
import {currentFrontierPeriod as frontierPeriod,recordFrontierDonation,preserveGuildFrontier,guildFrontierStandings,guildFrontierRanking} from './guild-frontier.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {hostChatLinks} from '../../src/systems/hud-options/chat-links-rules.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {isGuildGloryItem,GLORY_TEXT} from '../../src/systems/extras/guild-glory-rules.js';
import {scaledReward} from './rates.mjs';
import {socialError as fail,socialRef,socialIntent,socialLive,socialTransaction,refreshSocialNames} from './social-state.mjs';
import {checkNewGuildName,isGuildNameItem,isGuildMistakeItem,GUILD_NAME_CHANGES_MAX,NAME_TEXT} from '../../src/systems/extras/namechange-rules.js';
import {BOARD_OPERATIONS,BOARD_SCHEMA_FIELDS,boardCommand,boardSnapshot,pendingApplication,clearApplications,recordHistory,memberDetail} from './guild-board.mjs';
import {TEXT as BOARD_TEXT} from '../../src/systems/extras/guildboard-rules.js';
import {ALLIANCE_OPERATIONS,isAllianceOperation,allianceCommand,allianceGuildGuard,allianceSnapshot,allianceChat,emitAllianceNotices} from './alliance.mjs';
import {SIEGE_FIELDS,SIEGE_OPERATIONS,isSiegeOperation,isSiegeLiveOperation,siegeCommand,siegeLiveCommand,emitSiegeNotices,sideOf as siegeSide} from './siege.mjs';   // SIEGE
import {GUILD_EXTRA_FIELDS,GUILD_EXTRA_OPERATIONS,isGuildExtraOperation,guildExtraCommand,guildWarGuard,emitGuildExtraNotices,memberPresence,guildExtrasSnapshot,syncGuildSkillBuffs,syncAllGuildSkillBuffs} from './guild-extras.mjs';

export const GUILD_SCHEMAS={guild:['token','type','operation','revision','requestId','name','targetId','targetRef','id','notice','amount','text','ranks','rank','items','periodId','bg','icon','uid','memberRefs',...BOARD_SCHEMA_FIELDS,...GUILD_EXTRA_FIELDS,...SIEGE_FIELDS]};
// Original guild mark = one guildbg atlas cell + one guildicon atlas cell (game2/guild/ui_markselectwnd.txt).
// Selectable cells (script/ui/com/imagetable.txt): guild_bg_40a/b 1..221, guild_icon_40a..f 1..783. The
// user/event cells (bg 1001+, icon 2001+) belong to special adornment marks and are not selectable.
export const GUILD_MARK_RANGE={bg:221,icon:783};
// GUILD-DUNGEON-RANK: ranking view + public guild marks of the listed guilds (marks are already public on nameplates).
function frontierRanking(world,state,g){const r=guildFrontierRanking(world,g.id,world.data.guild?.dungeonGrade);if(!r)return null;const markOf=id=>Object.hasOwn(state.guilds,id)?guildMark(state.guilds[id].mark):null;for(const row of r.rows)row.mark=markOf(row.id);return {...r,mark:guildMark(g.mark),name:g.name};}
export function guildMark(mark){return mark&&Number.isInteger(mark.bg)&&Number.isInteger(mark.icon)&&mark.bg>=1&&mark.icon>=1&&mark.bg<=GUILD_MARK_RANGE.bg&&mark.icon<=GUILD_MARK_RANGE.icon?{bg:mark.bg,icon:mark.icon}:null;}
const membership=(state,ref)=>Object.values(state.guilds).find(g=>g.members.some(m=>m.ref===ref));
/** A guild invitation stands while its inviter is an online member who may still invite (LANE-61: no timeout or cap in any source;
 *  accepting also needs the inviter nearby). Old saved invitations with an expiresAt are read the same way. */
const inviteLive=(world,row,i)=>row.members.some(m=>m.ref===i.from)&&permission(row,i.from,'invite')&&[...world.players.values()].some(q=>!q.leaving&&socialRef(q)===i.from);
// LANE-61: grade permissions = Global game2/guild/ui_gradewnd.txt btn_check_N + the GradeManageWnd mask bit of each box
// (32-bit client decompile): 0 Invite 0x1, 1 Announcement 0x20, 2 Expel 0x2, 3 Register/Mod (guild mark) 0x4, 4 Change Rank 0x8,
// 6 Set Authorities 0x10, 7 Staff Chat 0x80, 9 Declare War 0x200, 11 Accept War 0x400, 12 Enable Skill 0x100.
// Boxes 5 See Info, 8 Battle Condition and 10 View Position are always checked (not stored); 13/14 are unused.
export const GUILD_PERMISSION_BITS=Object.freeze({invite:0x1,kick:0x2,mark:0x4,changeRank:0x8,setAuthorities:0x10,notice:0x20,staffChat:0x80,enableSkill:0x100,declareWar:0x200,acceptWar:0x400});
const PERMISSIONS=Object.keys(GUILD_PERMISSION_BITS);
const ADDED_PERMISSIONS=['changeRank','setAuthorities','staffChat','mark','enableSkill','declareWar','acceptWar'];   // absent in older saves -> master only
// Default grades of a new guild (older server reference: DB Cleaned CHARACTER.bak GUILD_PEERAGE template rows of guild_code
// 'MASTERCODE', copied by SP_GUILD_CREATE / SP_GUILD_PEERAGE_BASIC_C): peerage 0 'master' 0xFFFFFFFF, 1 '1' 0x3A, 2 '2' 0x01, 3..9 '3'..'9' 0.
// Global 130:202: rank names are at most 8 letters and new members begin at rank 10.
export const GUILD_DEFAULT_GRADES=Object.freeze([['master',0xFFFFFFFF],['1',0x3A],['2',0x01],['3',0],['4',0],['5',0],['6',0],['7',0],['8',0],['9',0]]);
const defaultRanks=()=>GUILD_DEFAULT_GRADES.map(([name,mask],i)=>({name,permissions:Object.fromEntries(PERMISSIONS.map(key=>[key,i===0||(mask&GUILD_PERMISSION_BITS[key])!==0]))}));
// Global stringtable_guild refusals (cate 130 / 135) for the checks below.
export const GUILD_TEXT=Object.freeze({alreadyJoined:'You have already joined another guild.',noDil:'Not enough DIL to create a guild.',lowLevel:'Level too low to create a guild.',
  noAuthority:'You have no authority.',noInvite:'You have no authority to invite someone to join.',noExpel:'You have no authority to request an expel.',noMark:'You have no authority to change the guild emblem.',
  notAuthorized:'You are not authorized.',noStaffChat:'You do not have the right to join the staff chat.',targetInGuild:'Selected user is already in another guild.',full:'You cannot join the guild because it has reached the maximum number of members.',
  masterQuit:'The guild master cannot quit.',expelMaster:'You cannot expel the guild master.',rankMaster:'You cannot change the rank of the guild master.',noDisband:'You do not have the authority to disband the guild.',
  disbandMembers:'You cannot disband the guild that still has members. You must expel all members first.',markDil:'Not enough DIL to pay for changing the guild emblem.',
  markSiege:'A guild participating in Siege Battle cannot change the guild emblem.',disbandSiege:'A guild participating in Siege Battle cannot be disbanded.',
  appointLevel:"The appointee's level has to be at least 50.",appointOffline:'The appointee is not in the game.',rankNameEmpty:'Authority name is empty.',notInGuild:'You are not in a guild.'});
// 130:13 / 120 / 106 / 121 / 88 / 135 / 418 / 135:8 / 135:38
const PERMISSION_TEXT={invite:GUILD_TEXT.noInvite,kick:GUILD_TEXT.noExpel,mark:GUILD_TEXT.noMark,setAuthorities:GUILD_TEXT.notAuthorized,staffChat:GUILD_TEXT.noStaffChat};
const memberRank=(g,m)=>m.ref===g.master?1:m.rank??10;
function ranks(g,status=503){
  const rows=g.ranks??defaultRanks();
  if(!Array.isArray(rows)||rows.length!==10||rows.some(r=>!r||typeof r.name!=='string'||!r.name.trim()||[...r.name].length>8||/[\x00-\x1f\x7f]/.test(r.name)||!r.permissions||PERMISSIONS.some(k=>typeof r.permissions[k]!=='boolean'&&!(ADDED_PERMISSIONS.includes(k)&&r.permissions[k]===undefined))))fail('Guild ranks are invalid; data preserved.',status);
  return rows.map((row,index)=>({...row,permissions:Object.fromEntries(PERMISSIONS.map(key=>[key,row.permissions[key]??(index===0)]))}));
}
function permission(g,ref,key){
  if(ref===g.master)return true;
  const m=g.members.find(m=>m.ref===ref),rank=m&&memberRank(g,m);
  if(!Number.isInteger(rank)||rank<2||rank>10)return false;
  return ranks(g)[rank-1].permissions[key]===true;
}
function requirePermission(g,ref,key){if(!permission(g,ref,key))fail(PERMISSION_TEXT[key]||GUILD_TEXT.noAuthority,403);}
// Guild Point (ADV donations) and GPOINT (activity) are distinct currencies.
// Original stringtable_guild 130:183,236-238; level upgrades consume both.
const level=(world,g)=>{if(g.level!==undefined){if(!Number.isInteger(g.level)||g.level<1||g.level>15)fail('Guild level is invalid; data preserved.',503);return g.level;}let n=1;for(let i=1;i<=15;i++)if(g.gpoint>=Number(world.data.guild?.config?.[`LEVELSTEP${i}`]))n=i;return n;};
const value=(n,label)=>{if(!Number.isSafeInteger(n)||n<0||n>10_000_000_000)fail(`${label} is invalid or exceeds its limit.`);return n;};
const add=(n,delta,label)=>value(value(n??0,label)+value(delta,label),label);
const rule=(cfg,key)=>{const n=Number(cfg?.[key]);if(!Number.isSafeInteger(n)||n<1)fail(`Original guild rule ${key} is unavailable.`,503);return n;};
const cap=(world,g)=>{const n=Number(world.data.guild?.config?.[`LEVEL${level(world,g)}_MEMBER`]);if(!Number.isInteger(n)||n<1)fail('Original guild member limits are unavailable.',503);return n;};
// One new member (invitation accept, publicity application approve / immediate join): activity ledger + no pending application left.
function join(state,g,{ref,name,level,classIndex}){g.members.push({ref,name,grade:'Member',rank:10,contribution:0,observedLevel:level,...(Number.isInteger(classIndex)?{classIndex}:{})});state.guildActivity||={};const ledger=state.guildActivity[ref]||={observedLevel:level};ledger.observedLevel=Math.max(ledger.observedLevel??level,level);clearApplications(state,ref);}
function master(g,ref){if(g.master!==ref)fail(GUILD_TEXT.noAuthority,403);}   // 130:13
function nearby(world,p,target){if(!target||target===p||target.leaving||target.dead||target.sceneTransition||!sameScene(p,target)||Math.hypot(p.x-target.x,p.z-target.z)>12)fail('Choose a nearby connected character.');}
// --- NET-REALM begin (DK_GUILD_NAME_MEMO, default on): the online ref->name tables are viewer-independent, so inside one
// snapshot scope (broadcast slice / coalesced /state batch) they are built once, not once per viewer (or per board row).
// Same semantics as before: liveNames = last live player per ref wins (Map ctor), names() = first live player per ref wins (find).
const NET_GUILD_MEMO=process.env.DK_GUILD_NAME_MEMO!=='0';
const netBuildLive=world=>new Map([...world.players.values()].filter(q=>!q.leaving).map(q=>[socialRef(q),q.profile.name]));
const netBuildFirst=world=>{const m=new Map();for(const q of world.players.values())if(!q.leaving){const r=socialRef(q);if(!m.has(r))m.set(r,q);}return m;};
function netLiveNames(world){return NET_GUILD_MEMO&&world.broadcastMemo?world.broadcastMemo('guildLiveNames',()=>netBuildLive(world)):netBuildLive(world);}
function netFirstLiveName(world,r){
  if(!NET_GUILD_MEMO||!world.broadcastMemo||!world._broadcastMemo)return [...world.players.values()].find(q=>!q.leaving&&socialRef(q)===r)?.profile.name;
  return world.broadcastMemo('guildFirstLive',()=>netBuildFirst(world)).get(r)?.profile.name;
}
// --- NET-REALM end
export function guildSnapshot(world,p){
  const state=world.socialState;if(!state)return {available:false,revision:0,founded:false,members:[],invites:[]};
  const ref=socialRef(p),g=membership(state,ref);
  syncGuildSkillBuffs(world,p,state);   // The running guild skill's status on this member
  if(world.listCharacters&&world.now()-(world.socialNamesAt??-Infinity)>=5000)void refreshSocialNames(world).catch(()=>{});
  const boardHelpers={level:row=>level(world,row),cap:row=>cap(world,row),names:(r,fallback)=>netFirstLiveName(world,r)||world.socialNames?.get(r)||fallback};
  const invites=Object.values(state.guilds).flatMap(row=>row.invites.filter(i=>i.to===ref&&inviteLive(world,row,i)).map(i=>({id:i.id,guildName:row.name,from:i.fromName,expiresAt:null})));   // no timeout (LANE-61)
  const extras=guildExtrasSnapshot(world,state,ref,g,{guildMark,level:row=>level(world,row),player:p,can:key=>!!g&&permission(g,ref,key)});   // Skills / wars
  if(!g)return {available:true,revision:state.revision,founded:false,name:'',notice:'',gpoint:0,dil:0,contribution:0,members:[],invites,extras,...boardSnapshot(world,state,ref,null,boardHelpers)};
  const liveNames=netLiveNames(world);
  const rankRows=ranks(g),period=frontierPeriod(world),detail=memberDetail(world),presence=memberPresence(world,g);
  const members=g.members.map(m=>({ref:m.ref,...detail(m,m.ref),...presence(m),rank:memberRank(g,m),grade:m.ref===g.master?'Guild Master':rankRows[memberRank(g,m)-1]?.name||'Member',contribution:m.contribution??0,name:liveNames.get(m.ref)||world.socialNames?.get(m.ref)||m.name}));
  const next=level(world,g)+1,cfg=world.data.guild.config;
  const mine=g.members.find(m=>m.ref===ref),ledger=state.guildActivity?.[ref]||mine,activityPending=ledger.loginDay===undefined||ledger.loginDay<Math.floor(world.now()/86400000)||p.profile.level>(ledger.observedLevel??p.profile.level);
  return {available:true,revision:state.revision,founded:true,id:g.id,name:g.name,mark:guildMark(g.mark),glory:g.glory?{itemIndex:g.glory.itemIndex}:null,nameChanges:g.nameChanges||0,markCost:Number(cfg.MARKDIL)||null,notice:g.notice,dil:g.dil,gpoint:g.gpoint,activityPoints:g.activityPoints??0,playPoints:g.playPoints??0,activityPending,activityRatio:Number(cfg.PLAYPOINTRATIO)||0,adventurePoints:p.profile.quests?.points?.adv??0,advBundle:Number(cfg.ADVPOINTRATIO)||0,dilBundle:Number(cfg.DILTOCON)||0,contribution:members.find(m=>m.ref===ref)?.contribution??0,level:level(world,g),nextLevel:next<=15?{level:next,guildPoints:Number(cfg[`LEVELSTEP${next}`]),activityPoints:Number(cfg[`LEVEL${next}_GPOINT`])}:null,memberCap:cap(world,g),master:g.master,myRef:ref,siegeRoster:guildSiegeRoster(world,g,state),myGrade:members.find(m=>m.ref===ref)?.grade,ranks:rankRows,permissions:Object.fromEntries(PERMISSIONS.map(key=>[key,permission(g,ref,key)])),frontier:period?{period,points:g.frontier?.[period.id]?.points??0,standings:guildFrontierStandings(world,period.id)}:null,frontierRanking:frontierRanking(world,state,g),alliance:allianceSnapshot(world,state,ref,g,{names:boardHelpers.names,level:row=>level(world,row),guildMark}),extras,members,invites,...boardSnapshot(world,state,ref,g,boardHelpers)};
}
export function guildChat(world,p,input){
  if(Object.keys(input).some(k=>!['token','type','operation','text'].includes(k)))fail('Send guild chat intent only.');
  socialLive(world,p);
  const state=world.socialState,g=state&&membership(state,socialRef(p));if(!g)fail('Join a guild before using guild chat.',403);
  if(world.now()<(p.muteUntil||0))fail('Your chat is temporarily restrained.',403);
  if(typeof input.text!=='string'||!input.text.trim()||input.text.length>250)fail('Chat must contain 1–250 characters.');
  if(input.operation==='officerChat')requirePermission(g,socialRef(p),'staffChat');
  const linked=hostChatLinks(p.profile,world.data?.itemDB,input.text.replace(/[\x00-\x1f\x7f]/g,' ').trim(),world.now()),text=linked.text;if(!text)fail('Chat message is empty.');
  if(world.now()<(p.chatAt||0))fail('Wait one second between chat messages.',429);
  p.chatAt=world.now()+1000;
  const staff=input.operation==='officerChat',refs=new Set(g.members.filter(m=>!staff||permission(g,m.ref,'staffChat')).map(m=>m.ref)),recipients=[...world.players.values()].filter(q=>!q.leaving&&refs.has(socialRef(q))).map(q=>q.id);
  world.emit(p.map,{type:'chat',channel:staff?'officer':'guild',actorId:p.id,name:p.profile.name,text,recipients,...(linked.links.length?{links:linked.links}:{})});
}
/** Trusted join/level-up hook. Retry failed persistence on the next owned actor
 * lifecycle; receipts and per-member day/level markers commit with social state.
 */
export function guildActivity(world,p){
  if(!world.socialState||!membership(world.socialState,socialRef(p)))return Promise.resolve(false);
  return guildCommand(world,p,{type:'guild',operation:'activity',revision:world.socialState.revision,requestId:randomUUID()});
}
export async function guildCommand(world,p,input){
  if(['chat','officerChat'].includes(input.operation))return guildChat(world,p,input);
  if(input.operation==='allianceChat')return allianceChat(world,p,input);   // ALLIANCE '$' chat (server/world/alliance.mjs)
  if(isSiegeLiveOperation(input.operation))return siegeLiveCommand(world,p,input);   // SIEGE: tunnel entry / Juto empathy (server/world/siege.mjs)
  socialIntent(input,{create:['name'],rename:['name','uid'],resetNameChanges:['uid'],invite:['targetId'],accept:['id'],decline:['id'],notice:['notice'],deposit:['amount'],donateAdv:['amount'],donateItems:['items','periodId'],configureRanks:['ranks'],setRank:['targetRef','rank'],levelUp:[],activity:[],kick:['targetRef'],transfer:['targetRef'],siegeRoster:['memberRefs'],leave:[],disband:[],mark:['bg','icon'],deleteMark:[],glory:['uid'],deleteGlory:[],...BOARD_OPERATIONS,...ALLIANCE_OPERATIONS,...GUILD_EXTRA_OPERATIONS,...SIEGE_OPERATIONS});
  let allianceNotices=null,extraNotices=null,siegeNotices=null;   // 135:x / 130:379 notices, emitted only after the durable commit   // ALLIANCE: 140:x notices, emitted only after the durable commit
  return socialTransaction(world,p,input,(state,profile,ref,effects)=>{
    const cfg=world.data.guild?.config,g=membership(state,ref);
    if(!cfg)fail('The original guild configuration is unavailable.',503);
    if(g&&g.level===undefined)g.level=level(world,g); // Freeze legacy level before spending or adding points.
    if(input.operation==='create'){
      if(g)fail(GUILD_TEXT.alreadyJoined);   // 130:2
      if(pendingApplication(state,ref))fail(BOARD_TEXT.waitingCreate,409);   // 134:52
      if(!nearbyNpc(world,p,{role:'GUILD'}))fail('Use a nearby Guild Master service.',403);
      if(Number(cfg.ADV)||Number(cfg.PEERAGE))fail('This founding requirement is unsupported.',503);
      const cost=Number(cfg.MONEY),minLevel=Number(cfg.LEVEL);
      if(!Number.isSafeInteger(cost)||cost<0||!Number.isInteger(minLevel)||minLevel<1)fail('Original guild founding rules are unavailable.',503);
      if(profile.level<minLevel)fail(GUILD_TEXT.lowLevel);   // 130:5 (guild.csv LEVEL)
      // Global ui_nameinputwnd edit_text maxlength 20 / 130:223 (20 characters); 130:7 taken, 130:8 unusable.
      const checked=checkNewGuildName(input.name,{taken:key=>Object.values(state.guilds).some(row=>row.name.toLowerCase()===key)});
      if(checked.error)fail(NAME_TEXT[checked.error],checked.error==='guildNameTaken'?409:400);
      const name=checked.name;
      if(!Number.isSafeInteger(profile.dil)||profile.dil<cost)fail(GUILD_TEXT.noDil);   // 130:3
      profile.dil-=cost;const id=randomUUID();state.guilds[id]={id,name,master:ref,members:[{ref,name:profile.name,grade:'Guild Master',rank:1,contribution:0,observedLevel:profile.level}],ranks:defaultRanks(),notice:'',level:1,dil:0,gpoint:0,activityPoints:0,playPoints:0,invites:[],createdAt:world.now()};state.guildActivity||={};const ledger=state.guildActivity[ref]||={observedLevel:profile.level};ledger.observedLevel=Math.max(ledger.observedLevel??profile.level,profile.level);cap(world,state.guilds[id]);return;
    }
    if(input.operation==='rename'){
      // Guild Name Change item (itemcash Type 0 Code 80, 20:1864); rules + sources: src/systems/extras/namechange-rules.js.
      if(!g)fail(NAME_TEXT.noGuild);
      if(g.master!==ref)fail(NAME_TEXT.guildLeaderOnly,403);
      guildWarGuard(world,state,g,'rename');   // 135:35
      if((g.nameChanges||0)>=GUILD_NAME_CHANGES_MAX)fail(NAME_TEXT.guildLimit,409);   // 130:314 "Changed: <VALUE>/1 Time", 130:317
      const checked=checkNewGuildName(input.name,{taken:key=>Object.values(state.guilds).some(row=>row.name.toLowerCase()===key)});
      if(checked.error)fail(NAME_TEXT[checked.error],checked.error==='guildNameTaken'?409:400);
      const db=world.data.itemDB;if(!db)fail('The item catalog is unavailable.',503);
      const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
      const entry=typeof input.uid==='string'?inventory.bag.list.find(item=>item.uid===input.uid):null;
      if(!entry||!isGuildNameItem(db.def(entry.itemIndex)))fail('Choose a Guild Name Change item in your bag.');
      if(!inventory.consumeEntry(entry,1))fail('This item is no longer available.');
      g.name=checked.name;g.nameChanges=(g.nameChanges||0)+1;return;   // 130:318: each change counts once
    }
    if(input.operation==='resetNameChanges'){
      // Guild Master's Mistake (itemcash Type 0 Code 27): 170:14 resets the guild's name change history; 130:316 while it is 0
      if(!g)fail(NAME_TEXT.noGuild);
      if(g.master!==ref)fail(NAME_TEXT.guildLeaderOnly,403);
      if(!(g.nameChanges>0))fail(NAME_TEXT.guildZeroChanges,409);
      const db=world.data.itemDB;if(!db)fail('The item catalog is unavailable.',503);
      const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
      const entry=typeof input.uid==='string'?inventory.bag.list.find(item=>item.uid===input.uid):null;
      if(!entry||!isGuildMistakeItem(db.def(entry.itemIndex)))fail("Choose a Guild Master's Mistake item in your bag.");
      if(!inventory.consumeEntry(entry,1))fail('This item is no longer available.');
      g.nameChanges=0;return;
    }
    if(['accept','decline'].includes(input.operation)){
      const invited=Object.values(state.guilds).find(row=>row.invites.some(i=>i.id===input.id&&i.to===ref&&inviteLive(world,row,i)));
      if(!invited)fail('That invitation is unavailable.',404);
      const invite=invited.invites.find(i=>i.id===input.id);
      if(input.operation==='accept'){
        if(g)fail(GUILD_TEXT.alreadyJoined);   // 130:2
        const inviter=[...world.players.values()].find(q=>socialRef(q)===invite.from);
        if(!permission(invited,invite.from,'invite'))fail('The inviter no longer has guild invitation permission.',409);
        nearby(world,p,inviter);if(invited.members.length>=cap(world,invited))fail(GUILD_TEXT.full);   // 130:104
        join(state,invited,{ref,name:profile.name,level:profile.level,classIndex:profile.classIndex});
        for(const row of Object.values(state.guilds))if(row!==invited)row.invites=(row.invites||[]).filter(i=>i.to!==ref);   // joined: other invitations end
      }
      invited.invites=invited.invites.filter(i=>i!==invite);return;
    }
    // Guild publicity board, applications, Best Guild War representatives (server/world/guild-board.mjs).
    if(Object.hasOwn(BOARD_OPERATIONS,input.operation)){boardCommand(world,p,{state,profile,ref,g,input,cap:row=>cap(world,row),join:(row,m)=>join(state,row,m)});return;}
    // Guild alliance (server/world/alliance.mjs; rules src/systems/extras/alliance-rules.js).
    if(isAllianceOperation(input.operation)){allianceNotices=allianceCommand(world,p,{state,profile,ref,g,input,level:row=>level(world,row),guildMark});return;}
    // Guild skills / guild war declaration (server/world/guild-extras.mjs; rules src/systems/extras/guildextras-rules.js).
    // Siege registration / announce / gate fortify / tax (server/world/siege.mjs; rules src/game/siege-rules.js).
    if(isSiegeOperation(input.operation)){siegeNotices=siegeCommand(world,p,{state,profile,ref,g,input,level:row=>level(world,row)});return;}
    if(isGuildExtraOperation(input.operation)){extraNotices=guildExtraCommand(world,p,{state,profile,ref,g,input,level:row=>level(world,row),can:key=>!!g&&permission(g,ref,key)});return;}
    if(!g)fail(GUILD_TEXT.notInGuild,403);   // 130:23
    if(input.operation==='siegeRoster'){setGuildSiegeRoster(world,state,g,ref,input.memberRefs);return;}
    if(input.operation==='activity'){
      // UTC day is an explicit engine boundary: the original strings specify
      // once per day, but do not supply the native guild server timezone.
      const member=g.members.find(m=>m.ref===ref),day=Math.floor(world.now()/86400000),ratio=rule(cfg,'PLAYPOINTRATIO');
      state.guildActivity||={};const ledger=state.guildActivity[ref]||={observedLevel:member.observedLevel??profile.level};
      let points=0;
      value(profile.level,'Character level');
      if(ledger.loginDay===undefined||ledger.loginDay<day){points+=rule(cfg,'LOGINPLAYPOINT');ledger.loginDay=day;}
      if(ledger.observedLevel!==undefined){value(ledger.observedLevel,'Observed level');const rate=rule(cfg,'LVUPPLAYPOINTRATE');if(rate!==100)fail('This activity level ratio is unsupported.',503);points+=Math.max(0,profile.level-ledger.observedLevel);}
      ledger.observedLevel=Math.max(ledger.observedLevel??profile.level,profile.level);
      const total=add(g.playPoints,points,'Play Points');g.activityPoints=add(g.activityPoints,Math.floor(total/ratio),'GPOINT');g.playPoints=total%ratio;return;
    }
    if(input.operation==='invite'){
      requirePermission(g,ref,'invite');const target=[...world.players.values()].find(q=>q.id===input.targetId);nearby(world,p,target);
      const targetRef=socialRef(target);if(membership(state,targetRef))fail(GUILD_TEXT.targetInGuild);   // 130:26
      if(g.members.length>=cap(world,g))fail(GUILD_TEXT.full);   // 130:104
      // REMOVED (LANE-61): the 60 s lifetime and the 100-invitation cap (no source in Global, the decompiles, the older server
      // reference or online). An invitation ends when answered, re-sent, the target joins a guild, or its inviter is gone (inviteLive).
      g.invites=g.invites.filter(i=>i.to!==targetRef&&g.members.some(m=>m.ref===i.from)&&!membership(state,i.to));
      g.invites.push({id:randomUUID(),from:ref,fromName:profile.name,to:targetRef});return;
    }
    if(input.operation==='deposit'){
      if(!nearbyNpc(world,p,{role:'GUILD'}))fail('Use a nearby Guild Master service.',403);
      const n=input.amount,bundle=rule(cfg,'DILTOCON');if(!Number.isSafeInteger(n)||n<bundle||n%bundle||!Number.isSafeInteger(profile.dil)||profile.dil<n)fail(`Donate affordable DIL in ${bundle.toLocaleString('en-US')} increments.`);
      g.dil=add(g.dil,n,'Guild DIL');const member=g.members.find(m=>m.ref===ref);member.contribution=add(member.contribution,n/bundle,'Contribution');profile.dil-=n;recordHistory(g,{type:'DIL',name:profile.name,amount:n},world.now());return;
    }
    if(input.operation==='donateAdv'){
      const n=input.amount,bundle=rule(cfg,'ADVPOINTRATIO'),con=rule(cfg,'ADVTOCON'),balance=profile.quests?.points?.adv??0;
      if(bundle!==con)fail('This Adventure contribution ratio is unsupported.',503);
      if(!Number.isSafeInteger(n)||n<bundle||n%bundle||value(balance,'Adventure Points')<n)fail(`Donate earned Adventure Points in ${bundle.toLocaleString('en-US')} increments.`);
      const member=g.members.find(m=>m.ref===ref);g.gpoint=add(g.gpoint,n/bundle,'Guild Points');member.contribution=add(member.contribution,n/con,'Contribution');profile.quests.points.adv-=n;recordHistory(g,{type:'ADV',name:profile.name,amount:n},world.now());return;
    }
    if(input.operation==='donateItems'){
      const period=frontierPeriod(world);
      if(!period)fail('The authoritative Frontier maintenance period is unavailable; items preserved.',503);
      if(input.periodId!==period.id)fail('The Frontier donation period changed. Review the current period.',409);
      if(!nearbyNpc(world,p,{role:'GUILD_DELIVER',jobType:112,jobIndex:0}))fail('Use a nearby original Guild Frontier delivery service.',403);
      if(!Array.isArray(input.items)||input.items.length<1||input.items.length>8||!world.data.itemDB||!Array.isArray(world.data.guild.deliver))fail('Register one to eight owned Frontier item stacks.');
      const seen=new Set(),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now}),entries=[];
      let points=0,contribution=0,exp=0;
      for(const inputItem of input.items){
        if(!inputItem||Object.keys(inputItem).some(k=>!['uid','count'].includes(k))||typeof inputItem.uid!=='string'||seen.has(inputItem.uid)||!Number.isSafeInteger(inputItem.count)||inputItem.count<1)fail('Choose distinct owned Frontier stacks and whole quantities.');
        seen.add(inputItem.uid);const item=inv.bag.byUid(inputItem.uid),row=item&&world.data.guild.deliver.find(r=>r.item===item.itemIndex);
        if(!row||inputItem.count>(item.count||1)||item.expiresAt&&item.expiresAt<=world.now()||item.pet)fail('That Frontier item or quantity is unavailable.');
        points=add(points,value(row.dr,'Original Frontier reward')*inputItem.count,'Frontier Points');contribution=add(contribution,value(row.contribution,'Original contribution reward')*inputItem.count,'Contribution');exp=add(exp,value(row.exp,'Original EXP reward')*inputItem.count,'Frontier EXP');entries.push([item,inputItem.count]);
      }
      recordFrontierDonation(state,g,period,ref,profile.name,{points,contribution,exp});
      g.frontier||={};const total=g.frontier[period.id]||={points:0};total.points=add(total.points,points,'Frontier Points');
      const member=g.members.find(m=>m.ref===ref);member.contribution=add(member.contribution,contribution,'Contribution');
      for(const [item,count]of entries)if(!inv.consumeEntry(item,count))fail('Frontier item consumption failed.');
      effects.grantExp(scaledReward(exp,world.rates?.exp??1));return;
    }
    if(input.operation==='leave'){
      if(g.master===ref)fail(GUILD_TEXT.masterQuit);   // 130:105
      g.members=g.members.filter(m=>m.ref!==ref);if(Array.isArray(g.siegeMembers))g.siegeMembers=g.siegeMembers.filter(r=>r!==ref);return;
    }
    if(input.operation==='notice'){
      requirePermission(g,ref,'notice');
      if(typeof input.notice!=='string'||input.notice.length>500||/[\x00-\x08\x0b-\x1f\x7f]/.test(input.notice))fail('Guild notices can contain at most 500 characters.');   // Global ui_noticewnd maxlength 500g.notice=input.notice;return;
    }
    if(input.operation==='kick'){
      requirePermission(g,ref,'kick');const target=g.members.find(m=>m.ref===input.targetRef),mine=g.members.find(m=>m.ref===ref);
      if(target?.ref===g.master)fail(GUILD_TEXT.expelMaster,403);   // 130:107
      if(!target||target.ref===ref||!mine)fail('Choose another guild member.');
      // LANE-61: the invented down-rank-only expel rule is removed; Global gates expel only by the Expel (0x2) grade box (130:106).
      g.members=g.members.filter(m=>m!==target);if(Array.isArray(g.siegeMembers))g.siegeMembers=g.siegeMembers.filter(r=>r!==target.ref);g.invites=g.invites.filter(i=>i.from!==target.ref);return;
    }
    if(input.operation==='configureRanks'){
      requirePermission(g,ref,'setAuthorities');
      if(!Array.isArray(input.ranks)||input.ranks.length!==10||input.ranks.some(row=>!row||Object.keys(row).some(k=>!['name','permissions'].includes(k))||typeof row.name!=='string'||!row.permissions||Object.keys(row.permissions).some(k=>!PERMISSIONS.includes(k))))fail('Submit exactly ten rank names and supported permissions.');
      if(input.ranks.some(row=>!row.name.trim()))fail(GUILD_TEXT.rankNameEmpty);   // 130:125
      const current=ranks(g),proposed=ranks({...g,ranks:input.ranks.map((row,i)=>({...row,permissions:{...current[i].permissions,...row.permissions}}))},400);
      if(PERMISSIONS.some(key=>!proposed[0].permissions[key]))fail('Guild Master permissions cannot be removed.');
      g.ranks=proposed.map(row=>({name:row.name.trim(),permissions:{...row.permissions}}));return;
    }
    if(input.operation==='setRank'){
      requirePermission(g,ref,'changeRank');
      const target=g.members.find(m=>m.ref===input.targetRef);
      if(target?.ref===g.master)fail(GUILD_TEXT.rankMaster,403);   // 130:128
      if(!target||target.ref===ref||!Number.isInteger(input.rank)||input.rank<2||input.rank>10)fail('Assign a non-master member to rank 2–10.');
      target.rank=input.rank;target.grade=ranks(g)[input.rank-1].name;return;
    }
    if(input.operation==='mark'){
      // Register/Mod grade box (0x4, 130:121); fee guild.csv MARKDIL (130:83 / 130:84); 130:233 while registered for the siege.
      requirePermission(g,ref,'mark');
      if(!nearbyNpc(world,p,{role:'GUILDMARK'}))fail('Use a nearby guild mark service.',403);
      if(siegeSide(world,g.id,state))fail(GUILD_TEXT.markSiege,409);
      const mark=guildMark({bg:input.bg,icon:input.icon});if(!mark)fail('Choose an original guild mark background and icon.');
      const cost=rule(cfg,'MARKDIL');if(!Number.isSafeInteger(profile.dil)||profile.dil<cost)fail(GUILD_TEXT.markDil);
      profile.dil-=cost;g.mark=mark;return;
    }
    if(input.operation==='disband'&&g.master!==ref)fail(GUILD_TEXT.noDisband,403);   // 130:103
    master(g,ref);
    if(input.operation==='levelUp'){
      const next=level(world,g)+1;if(next>15)fail('The guild is at its highest level.');
      const gp=rule(cfg,`LEVELSTEP${next}`),activity=Number(cfg[`LEVEL${next}_GPOINT`]);value(activity,'Level GPOINT cost');
      if(value(g.gpoint,'Guild Points')<gp||value(g.activityPoints??0,'GPOINT')<activity)fail('Not enough Guild Points and GPOINTs to raise the guild level.');
      g.gpoint-=gp;g.activityPoints=(g.activityPoints??0)-activity;g.level=next;cap(world,g);return;
    }
    if(input.operation==='disband'){
      allianceGuildGuard(world,state,g,'disband');   // 130:219 / 130:323
      guildWarGuard(world,state,g,'disband');        // 135:34
      if(!nearbyNpc(world,p,{role:'DISBANDGUILD'}))fail('Use a nearby guild disband service.',403);
      if(siegeSide(world,g.id,state))fail(GUILD_TEXT.disbandSiege,409);   // 130:232
      if(g.members.length!==1)fail(GUILD_TEXT.disbandMembers);   // 130:111
      // LANE-61: a guild with DIL disbands; its treasury is forfeited with the guild (OLDER SERVER REFERENCE SP_GUILD_DELETE archives
      // the row, guild_Dil included, to GUILD_INFO_SECEDE; nothing is paid out). ONLINE (dekarons.com guild wiki): the emblem effect
      // goes with it (delete state.guilds[id] drops g.glory).
      preserveGuildFrontier(state,g);
      delete state.guilds[g.id];return;
    }
    if(input.operation==='deleteMark'){
      // REMOVED (LANE-61): deleting the guild MARK has no Global source; the DELETEGUILDMARK NPC deletes the emblem EFFECT
      // (decompile FUN_013950e0: 130:177 / 130:175 ...). An old client's request is answered as Global answers it with no effect.
      fail(GLORY_TEXT.none);   // 130:175
    }
    if(input.operation==='glory'){
      // Guild of Glory (itemcash Type 0 Code 16, guild-glory-rules.js): the Guild Master registers the glowing emblem effect; the item is spent here
      const db=world.data.itemDB;if(!db)fail('The item catalog is unavailable.',503);
      const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
      const entry=typeof input.uid==='string'?inventory.bag.list.find(item=>item.uid===input.uid):null;
      if(!entry||!isGuildGloryItem(db.def(entry.itemIndex)))fail('Cannot find the item.');
      if(!inventory.consumeEntry(entry,1))fail('Cannot find the item.');
      g.glory={itemIndex:entry.itemIndex};return;
    }
    if(input.operation==='deleteGlory'){
      // Master only (after master() above): DECOMPILE FUN_013950e0 result 3 = 130:88 "You are not authorized." proves an authority
      // check; the Glory item is registered by the Guild Master only, so the same master check applies to its deletion.
      if(!nearbyNpc(world,p,{role:'DELETEGUILDMARK'}))fail('Use a nearby guild mark deletion service.',403);
      if(!g.glory)fail(GLORY_TEXT.none);   // 130:175
      delete g.glory;return;
    }
    allianceGuildGuard(world,state,g,'transfer');   // 130:218
    const member=g.members.find(m=>m.ref===input.targetRef);if(!member||member.ref===ref)fail('Choose another guild member.');
    const appointee=[...world.players.values()].find(q=>!q.leaving&&socialRef(q)===member.ref);
    if(!appointee)fail(GUILD_TEXT.appointOffline);   // 130:133
    if(appointee.profile.level<Number(cfg.LEVEL))fail(GUILD_TEXT.appointLevel);   // 130:132 (guild.csv LEVEL 50)
    const previousMaster=g.master;g.master=member.ref;for(const row of g.members){row.rank=row.ref===g.master?1:row.ref===previousMaster?10:row.rank??10;row.grade=row.ref===g.master?'Guild Master':ranks(g)[row.rank-1].name;}g.invites=[];
  }).then(result=>{emitAllianceNotices(world,allianceNotices);emitGuildExtraNotices(world,extraNotices);emitSiegeNotices(world,siegeNotices);syncAllGuildSkillBuffs(world);return result;});
}
