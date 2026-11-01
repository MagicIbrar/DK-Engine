// PARTY-FINDER: the original Party Search system in shared play. Windows (script/ui/game2/party/*_renew.txt):
// "Recruit Party Member" ui_partyrecruitwnd_renew (100:100; map 70:39, level 70:40, job 70:90, options 70:137/168/170/176),
// "Party Search" ui_partyfindwnd_renew (100:99; three maps, "My server" 70:175), "Party List" ui_partylistwnd_renew (70:132),
// "Set password" ui_partypasswordwnd_renew (100:170/171) and the HUD helper icon ui_partyicon. The map list and its level limits
// are share/partysearch/matchingmap.csv (gamedata/life.json party.matchingMaps). Every refusal is the original
// stringtable_party.txt cate 70 text (tools/test-party-finder.mjs compares them). Rules the data does not state are
// ENGINE-CHOSEN and listed in PARTY_FINDER_CONFIG and docs/PARTY-FINDER.md.
import {randomUUID} from 'node:crypto';
import {WorldError} from './core.mjs';
import {PARTY_MAX,leaveParty} from './party.mjs';
import {partyBelongsToExpedition} from './expedition.mjs';

export const PARTY_FINDER_SCHEMAS={partyfinder:['token','type','operation','map','minLevel','maxLevel','classes','auto','password','sameServer','autoKick','maps','partyId','requestId','allow']};
export const PARTY_FINDER_CLASSES=15;                     // btn_class_0..14 = classIndex 0..14 (etc_01 100+classIndex)
export const PARTY_FINDER_ALL_CLASSES=(1<<PARTY_FINDER_CLASSES)-1;
export const PARTY_FINDER_SEARCH_MAPS=3;                  // lbl_mapname_0..2 / list_maplist_0..2
export const PARTY_FINDER_PASSWORD=/^\d{4}$/;             // 70:169 "The password can only be 4 digits." / 100:171
/** ENGINE-CHOSEN (not in Global data): timings and limits the client data does not carry. */
export const PARTY_FINDER_CONFIG=Object.freeze({
  requestTtlMs:60000,       // a join request waits 60 s for the leader (same as a party invitation, server/world/party.mjs)
  inviteTtlMs:60000,        // an Auto Party Request invitation lives 60 s like a normal invitation
  listMax:100,              // at most 100 rows in one Party List answer
});
/** Original text (script/string/party/stringtable_party.txt cate 70). */
export const PARTY_FINDER_TEXT={
  invalid:'Invalid conditions.',
  alreadyRecruiting:'You already started recruiting members.',
  leaderOnly:'Only Party Leaders can use the Recruit Party Member option.',
  dungeonRecruit:'You cannot use the Recruit Party Member option while in dungeons.',
  recruitStarted:'Your Party Member recruitment has initiated.',
  recruitStopped:'You stopped recruiting Party Members.',
  invalidInfo:'Invalid information.',
  inParty:'You are already in a Party.',
  noLeader:'Cannot find the Party Leader.',
  noTarget:'The target does not exist.',
  youNotLeader:'You are not the Party Leader.',
  alreadySeeking:'You already started looking for a Party.',
  dungeonSeek:'You cannot use the Look for Party option while in dungeons.',
  seekStarted:'You started looking for a Party.',
  channelRecruit:'You cannot switch channels while recruiting Party Members.',
  noConditions:'Party Search Failed: Please select the search conditions.',
  delegateRecruit:'You cannot delegate your Party Leader authority while recruiting Party Members.',
  seekStopped:'You stopped looking for a Party.',
  memberRecruit:'Party Members cannot use the Recruit Party Member option.',
  expedition:'This cannot be used while on an Expedition.',
  fullRecruit:'You cannot recruit Party Members when your Party is full.',
  notRecruiting:'The Party is not recruiting new members.',
  noParty:'No such Party exists. Please refresh the Party list.',
  stopped:'This Party stopped recruiting new members. Please refresh the Party list.',
  criteria:'[Party Invitation Failed] This character does not meet your criteria for new members.',
  full:'The Party is full; you cannot join the Party.',
  sameChannel:'The target should be in the same channel.',
  targetInParty:'[Party Invitation Failed] The target character is already in a Party.',
  rejected:'Rejected the party invitation.',
  inviting:'Inviting to the party.',
  pinMismatch:'Invalid password.',
  passwordDigits:'The password can only be 4 digits.',
  joined:'has joined the Party.',
  expelled:'has been expelled from the party.',
};
export const PARTY_FINDER_TEXT_REFS={invalid:'70:81',alreadyRecruiting:'70:82',leaderOnly:'70:83',dungeonRecruit:'70:85',recruitStarted:'70:88',recruitStopped:'70:89',invalidInfo:'70:93',
  inParty:'70:94',noLeader:'70:95',noTarget:'70:97',youNotLeader:'70:101',alreadySeeking:'70:102',dungeonSeek:'70:103',seekStarted:'70:104',channelRecruit:'70:112',
  noConditions:'70:113',delegateRecruit:'70:115',seekStopped:'70:118',memberRecruit:'70:121',expedition:'70:123',fullRecruit:'70:124',notRecruiting:'70:136',
  noParty:'70:139',stopped:'70:140',criteria:'70:148',full:'70:151',sameChannel:'70:161',targetInParty:'70:8',rejected:'70:162',inviting:'70:163',pinMismatch:'70:167',
  passwordDigits:'70:169',joined:'70:11',expelled:'70:2'};
const T=PARTY_FINDER_TEXT;
const fail=message=>{throw new WorldError(400,message);};
const ADMISSION_BUSY='Wait until party admission finishes.';   // same engine text as server/world/party.mjs
function stores(world){world.parties||=new Map();world.partyInvites||=new Map();world.partyFinderRequests||=new Map();return world.partyFinderRequests;}
function online(world,id){return [...world.players.values()].find(p=>p.id===id&&!p.leaving)||null;}
function partyOf(world,p){return p?.partyId?world.parties?.get(p.partyId)||null:null;}
const matching=world=>world.data?.partyData?.matchingMaps||[];
const mapRow=(world,index)=>matching(world).find(m=>m.index===index)||null;
/** matchingmap.csv row "All Map" (index 60): a recruitment or search for it matches every map. */
const allMapIndex=world=>matching(world).find(m=>/^all map$/i.test(String(m.name||'').trim()))?.index??null;
const intIn=(v,a,b)=>Number.isInteger(v)&&v>=a&&v<=b;
const channelOf=p=>Number(p?.channel)||0;
const flag=(value,name)=>{if(value===undefined)return false;if(typeof value!=='boolean')fail(T.invalid);return value;};
export function fitsRecruit(party,q){
  const r=party?.recruit;if(!r||!q)return false;
  const level=Number(q.profile?.level)||1,ci=Number(q.profile?.classIndex);
  return level>=r.minLevel&&level<=r.maxLevel&&intIn(ci,0,PARTY_FINDER_CLASSES-1)&&((r.classes>>>ci)&1)===1;
}
function mapsMatch(world,recruitMap,maps){if(!maps?.length)return true;const all=allMapIndex(world);return recruitMap===all||maps.includes(all)||maps.includes(recruitMap);}
function notify(world,recipients,code,extra={}){const ids=[...new Set(recipients.filter(Boolean))];if(ids.length)world.emit(null,{type:'partyfinder',code,recipients:ids,...extra});}
function parseMaps(world,value){
  if(value===undefined)return [];
  if(!Array.isArray(value)||value.length>PARTY_FINDER_SEARCH_MAPS)fail(T.invalid);
  const out=[];for(const index of value){if(!Number.isInteger(index)||!mapRow(world,index))fail(T.invalid);if(index&&!out.includes(index))out.push(index);}
  return out;
}
/** Expired requests, parties that stopped recruiting or joined an expedition, seekers that found a party, Auto leave party. */
function sweep(world){
  const requests=stores(world),now=world.now();
  for(const party of world.parties.values()){
    const r=party.recruit;if(!r)continue;
    if(partyBelongsToExpedition(party)||!party.members.length){party.recruit=null;continue;}
    r.admitted=r.admitted.filter(id=>party.members.includes(id));
    // ENGINE-CHOSEN reading of "Auto leave party" (70:176): a member admitted through this recruitment who no longer meets its
    // level range (levelled past it) leaves the party automatically; the party sees "<name> has been expelled from the party." (70:2)
    if(r.autoKick)for(const id of [...r.admitted]){
      const q=online(world,id);if(!q||q.sceneTransition||q.progressCommitting||fitsRecruit(party,q))continue;
      const members=[...party.members];leaveParty(world,q);r.admitted=r.admitted.filter(x=>x!==id);notify(world,members,'70:2',{name:q.profile.name});
    }
  }
  for(const p of world.players.values())if(p.partySeek&&(p.partyId||p.instanceId))p.partySeek=null;
  for(const [id,request] of requests){const party=world.parties.get(request.party);if(request.expires<=now||!party?.recruit||!online(world,request.from)||partyOf(world,online(world,request.from)))requests.delete(id);}
}
function inviteSeeker(world,party,q){
  const leader=online(world,party.leader);if(!leader)return false;
  const invite=world.partyInvites.get(q.id);if(invite&&invite.expires>world.now())return false;
  world.partyInvites.set(q.id,{party:party.id,from:leader.profile.name,expires:world.now()+PARTY_FINDER_CONFIG.inviteTtlMs,finder:true});
  notify(world,[leader.id],'70:163',{name:q.profile.name});return true;
}
const pendingInvites=(world,party)=>[...world.partyInvites.values()].filter(i=>i.party===party.id&&i.expires>world.now()).length;
function seekerFits(world,party,q){
  const r=party.recruit,leader=online(world,party.leader);
  if(!r?.auto||r.password||!leader||q.partyId||q.instanceId||!q.partySeek||q===leader)return false;
  if((r.sameServer||q.partySeek.sameServer)&&channelOf(leader)!==channelOf(q))return false;
  return mapsMatch(world,r.map,q.partySeek.maps)&&fitsRecruit(party,q)&&party.members.length+pendingInvites(world,party)<PARTY_MAX;
}
// ENGINE-CHOSEN reading of "Auto Party Request" (70:137): join requests that meet the criteria are admitted at once, and players who
// are Looking for a Party (party_find "Ok") on a matching map are sent the party's invitation automatically (password-less only).
function autoMatchParty(world,party){for(const q of world.players.values())if(!q.leaving&&seekerFits(world,party,q))inviteSeeker(world,party,q);}
function autoMatchSeeker(world,q){for(const party of world.parties.values())if(seekerFits(world,party,q)){inviteSeeker(world,party,q);return;}}
function admit(world,party,q){
  const requests=stores(world);
  party.members.push(q.id);q.partyId=party.id;q.partySeek=null;world.partyInvites.delete(q.id);
  for(const [id,request] of requests)if(request.from===q.id)requests.delete(id);
  party.recruit?.admitted.push(q.id);
  notify(world,party.members,'70:11',{name:q.profile.name});world.sequence++;
}
function rowOf(world,party,index){
  const r=party.recruit,leader=online(world,party.leader);
  return {no:index+1,partyId:party.id,map:r.map,name:party.name,leader:leader?.profile.name||'',members:party.members.length,max:PARTY_MAX,
    password:!!r.password,minLevel:r.minLevel,maxLevel:r.maxLevel,classes:r.classes,auto:!!r.auto,sameServer:!!r.sameServer};
}
/** "Display only Parties that are available to join." (70:133): recruiting, not full, my level/class fit, channel rule kept. */
export function partyFinderList(world,p,maps=[],sameServer=false){
  sweep(world);
  const out=[];
  for(const party of world.parties.values()){
    const r=party.recruit,leader=online(world,party.leader);
    if(!r||!leader||party.id===p.partyId||party.members.length>=PARTY_MAX||!fitsRecruit(party,p)||!mapsMatch(world,r.map,maps))continue;
    if((r.sameServer||sameServer)&&channelOf(leader)!==channelOf(p))continue;
    out.push(party);
  }
  return out.sort((a,b)=>a.recruit.started-b.recruit.started).slice(0,PARTY_FINDER_CONFIG.listMax).map((party,i)=>rowOf(world,party,i));
}
export function partyFinderGuard(world,p,input){
  const party=partyOf(world,p);if(!party?.recruit||party.leader!==p.id)return;
  if(input.type==='party'&&input.operation==='lead')fail(T.delegateRecruit);
  if(input.type==='channel'&&input.operation==='move')fail(T.channelRecruit);
}
export function partyFinderCommand(world,p,input){
  const requests=stores(world);sweep(world);
  const op=input.operation,party=partyOf(world,p),now=world.now();
  if(p.sceneTransition)fail(ADMISSION_BUSY);
  if(op==='recruit'){
    if(partyBelongsToExpedition(party))fail(T.expedition);
    if(p.instanceId)fail(T.dungeonRecruit);
    if(!party)fail(T.leaderOnly);
    if(party.leader!==p.id)fail(T.memberRecruit);
    if(party?.recruit)fail(T.alreadyRecruiting);
    if(party.members.length>=PARTY_MAX)fail(T.fullRecruit);
    const row=mapRow(world,input.map);
    if(!row||!row.index||!intIn(input.minLevel,row.limitMin,row.limitMax)||!intIn(input.maxLevel,input.minLevel,row.limitMax)||!intIn(input.classes,1,PARTY_FINDER_ALL_CLASSES))fail(T.invalid);
    let password='';
    if(input.password!==undefined&&input.password!==''){if(typeof input.password!=='string'||!PARTY_FINDER_PASSWORD.test(input.password))fail(T.passwordDigits);password=input.password;}
    const auto=flag(input.auto),sameServer=flag(input.sameServer),autoKick=flag(input.autoKick);
    const own=party;
    p.partySeek=null;
    own.recruit={map:row.index,minLevel:input.minLevel,maxLevel:input.maxLevel,classes:input.classes,auto,password,sameServer,autoKick,started:now,admitted:[]};
    autoMatchParty(world,own);world.sequence++;
    return {operation:op,code:'70:88'};
  }
  if(op==='stop'){
    if(!party?.recruit)fail(T.notRecruiting);
    if(party.leader!==p.id)fail(T.youNotLeader);
    party.recruit=null;for(const [id,request] of requests)if(request.party===party.id){requests.delete(id);notify(world,[request.from],'70:140');}
    world.sequence++;return {operation:op,code:'70:89'};
  }
  if(op==='seek'){
    if(party)fail(T.inParty);
    if(p.instanceId)fail(T.dungeonSeek);
    if(p.partySeek)fail(T.alreadySeeking);
    const maps=parseMaps(world,input.maps);if(!maps.length)fail(T.noConditions);
    const sameServer=flag(input.sameServer);
    p.partySeek={maps,sameServer,started:now};autoMatchSeeker(world,p);world.sequence++;
    return {operation:op,code:'70:104',parties:partyFinderList(world,p,maps,sameServer)};
  }
  if(op==='unseek'){
    if(!p.partySeek)fail(T.invalidInfo);
    p.partySeek=null;world.sequence++;return {operation:op,code:'70:118'};
  }
  if(op==='list'){
    const maps=parseMaps(world,input.maps),sameServer=flag(input.sameServer);
    return {operation:op,parties:partyFinderList(world,p,maps,sameServer)};
  }
  if(op==='request'){
    if(party)fail(T.inParty);
    if(typeof input.partyId!=='string')fail(T.noParty);
    const target=world.parties.get(input.partyId);if(!target)fail(T.noParty);
    if(!target.recruit||partyBelongsToExpedition(target))fail(T.stopped);
    const leader=online(world,target.leader);if(!leader)fail(T.noLeader);
    if(target.members.length>=PARTY_MAX)fail(T.full);
    if(target.recruit.sameServer&&channelOf(leader)!==channelOf(p))fail(T.sameChannel);
    if(!fitsRecruit(target,p))fail(T.criteria);
    if(target.recruit.password&&input.password!==target.recruit.password)fail(T.pinMismatch);
    if(target.members.some(id=>online(world,id)?.sceneTransition))fail(ADMISSION_BUSY);
    if(target.recruit.auto){admit(world,target,p);return {operation:op,joined:target.id,code:'70:11'};}
    for(const [id,request] of requests)if(request.from===p.id)requests.delete(id);
    const request={id:randomUUID(),party:target.id,from:p.id,name:p.profile.name,level:Number(p.profile.level)||1,classIndex:Number(p.profile.classIndex)||0,expires:now+PARTY_FINDER_CONFIG.requestTtlMs};
    requests.set(request.id,request);notify(world,[leader.id],'request',{name:request.name,requestId:request.id});world.sequence++;
    return {operation:op,requested:target.id};
  }
  if(op==='answer'){
    if(typeof input.requestId!=='string')fail(T.invalidInfo);
    const request=requests.get(input.requestId);if(!request)fail(T.invalidInfo);
    const target=world.parties.get(request.party);if(!target||target.leader!==p.id)fail(T.youNotLeader);
    if(typeof input.allow!=='boolean')fail(T.invalidInfo);
    requests.delete(request.id);world.sequence++;
    const q=online(world,request.from);if(!q)fail(T.noTarget);
    if(!input.allow){notify(world,[q.id],'70:162');return {operation:op,allow:false};}
    if(partyOf(world,q))fail(T.targetInParty);
    if(!target.recruit)fail(T.stopped);
    if(target.members.length>=PARTY_MAX)fail(T.full);
    if(q.sceneTransition||target.members.some(id=>online(world,id)?.sceneTransition))fail(ADMISSION_BUSY);
    admit(world,target,q);return {operation:op,allow:true};
  }
  fail('Unknown party search action.');
}
/** Window state for one player: own recruitment (password never sent), own search, the leader's pending requests. */
export function partyFinderSnapshot(world,p){
  const requests=stores(world),party=partyOf(world,p),r=party?.recruit,leader=!!party&&party.leader===p.id;
  const mine=[...requests.values()].find(x=>x.from===p.id);
  return {
    recruit:r?{map:r.map,minLevel:r.minLevel,maxLevel:r.maxLevel,classes:r.classes,auto:r.auto,password:!!r.password,sameServer:r.sameServer,autoKick:r.autoKick,started:r.started}:null,
    leader,seeking:p.partySeek?{maps:[...p.partySeek.maps],sameServer:p.partySeek.sameServer}:null,
    requests:leader&&r?[...requests.values()].filter(x=>x.party===party.id).map(x=>({id:x.id,name:x.name,level:x.level,classIndex:x.classIndex,expires:x.expires})):[],
    pending:mine?{partyId:mine.party,expires:mine.expires}:null,
  };
}
/** core.mjs snapshot hook: sweep first, then the party snapshot carries `finder`. */
export function withPartyFinder(world,p,build){sweep(world);const snapshot=build();snapshot.finder=partyFinderSnapshot(world,p);return snapshot;}
