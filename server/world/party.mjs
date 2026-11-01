import {sameScene} from './scene.mjs';
import {randomUUID} from 'node:crypto';
import {partyBelongsToExpedition,leaveExpedition,memberStatuses} from './expedition.mjs';
import {hostChatLinks} from '../../src/systems/hud-options/chat-links-rules.js';
export const PARTY_MAX=7; // Original party_renew window has seven member slots.
export const PARTY_SCHEMAS={party:['token','type','operation','targetId','name','itemway','text']};
const fail=message=>{throw Object.assign(new Error(message),{status:400})};
function store(world){world.parties||=new Map();world.partyInvites||=new Map();return world.parties;}
function online(world,id){return [...world.players.values()].find(p=>p.id===id&&!p.leaving);}
function group(world,p){store(world);return p.partyId?world.parties.get(p.partyId):null;}
function lead(p,party){if(!party||party.leader!==p.id)fail('Only the party leader can do that.');}
export function nearbyPartyMembers(world,p,origin=p){const party=group(world,p);if(!party)return[p];const members=party.members.map(id=>online(world,id)).filter(other=>other&&!other.dead&&!other.customMapPending&&sameScene(other,p)&&Math.hypot(other.x-origin.x,other.z-origin.z)<=50);return members.includes(p)?members:[p,...members];}
/**
 * share/pc/groupexpratio.csv row for a map: the party's total % of the monster EXP by counted member number.
 * Keyed by MapIndex (life.json party.groupExpByMap, tools/build-life.mjs); e.g. map 0 '7,100,200,...,700', map 25 Crespo's
 * Treasure / map 89 Tower of Spell '7,100,190,270,340,400,450,490', maps 49-55 / 551 / 607 count up to 18 members.
 * A map without a row uses row 0 (ENGINE-CHOSEN: the original fallback is unknown). Members above GroupMember are counted as
 * GroupMember and the total is still split among everyone present (ENGINE-CHOSEN: maps 232/233/257 have GroupMember 3 while a
 * party holds 7; the original handling is unknown). A 0 ratio never falls back to 100 %: the last non-zero column applies.
 */
export function groupExpRatio(partyData,mapIndex,count){
 const row=partyData?.groupExpByMap?.[Number(mapIndex)]||partyData?.groupExpDefault;
 if(!row)return 100;
 const cap=Number(row.GroupMember)>0?Number(row.GroupMember):18;
 let n=Math.max(1,Math.min(Math.floor(count)||1,cap));
 for(;n>1;n--){const ratio=Number(row[`GroupExpRatio${n}`]);if(ratio>0)return ratio;}
 const first=Number(row.GroupExpRatio1);return first>0?first:100;
}
export function partyExpRewards(world,p,exp,origin=p){
 const members=nearbyPartyMembers(world,p,origin),instance=p.instanceId&&world.instances?.get(p.instanceId);
 // Publisher July 25, 2024: equal basic monster EXP regardless of party size;
 // five or more different classes add20% in Fort Focas / Ice Castle only.
 // https://dekaron.ubifungames.com/App/News/Update?no=24072400000000000002
 // ENGINE-CHOSEN: keep existing connected/alive/same-scene50m recipients as
 // the composition set; publisher absence/death/range counting is unrecovered.
 // ENGINE-CHOSEN: floor the server-rate-scaled basic amount before the
 // caller's existing recipient level-cap/premium/item bonuses. Event objects,
 // final/PvP rewards and unrelated party map ratios retain their own paths.
 if(instance&&instance.id===p.instanceId&&Number(instance.map)===Number(p.map)&&!instance.closed&&
    ['deadFront','iceCastle'].includes(instance.kind)&&sameScene(p,origin)&&
    instance.scene?.monsters?.get(origin.id)===origin&&members.every(q=>instance.members.has(q.id))&&
    origin.def?.role==='creature'&&!origin.isBrick&&!origin.eventObject&&Number.isFinite(origin.def.exp)&&origin.def.exp>0){
  const classes=new Set(members.map(q=>q.profile?.classIndex).filter(index=>Number.isInteger(index)&&index>=0&&world.data.classDef?.(index)?.index===index));
  const basic=Math.floor(exp*(classes.size>=5?1.2:1));
  return members.map(player=>({player,exp:basic}));
 }
 if(members.length===1)return[{player:p,exp}];const ratio=groupExpRatio(world.data.partyData,p.map,members.length),total=Math.floor(exp*ratio/100);return members.map((player,index)=>({player,exp:Math.floor(total/members.length)+(index<total%members.length?1:0)}));
}
/** Owner-requested DIL policy: in-reach human party members receive all mixed-party currency.
 * NPC-only parties retain their economy. Existing50m sharing distance/remainder order are ENGINE-CHOSEN.
 * EXP counting and itemway ownership remain independent and unchanged.
 */
export function partyDilRewards(world,p,amount,origin=p){
 const members=nearbyPartyMembers(world,p,origin),humans=members.filter(q=>q.npcPlayer!==true&&q.profile?.npcPlayer!==true);
 const recipients=humans.length?humans:members,total=Math.max(0,Math.floor(Number(amount)||0));
 return recipients.map((player,index)=>({player,dil:Math.floor(total/recipients.length)+(index<total%recipients.length?1:0)}));
}
export function partyLootOwner(world,p,origin=p){const party=group(world,p),members=nearbyPartyMembers(world,p,origin);if(party?.itemway===2)return{player:p,free:true};if(!party||members.length<2)return{player:p,free:false};if(party.itemway===4)return{player:members.find(member=>member.id===party.leader)||p,free:false};if(party.itemway===3)return{player:members[Math.min(members.length-1,Math.floor(world.random()*members.length))],free:false};if(party.itemway===1){party.lootTurn=(party.lootTurn||0)%members.length;return{player:members[party.lootTurn++],free:false};}return{player:p,free:false};}
export function leaveParty(world,p){const party=group(world,p);world.partyInvites.delete(p.id);if(partyBelongsToExpedition(party)){leaveExpedition(world,p);return;}p.partyId=null;if(!party)return;party.members=party.members.filter(id=>id!==p.id);if(!party.members.length){world.parties.delete(party.id);for(const[id,invite]of world.partyInvites)if(invite.party===party.id)world.partyInvites.delete(id);}else if(party.leader===p.id)party.leader=party.members[0];world.sequence++;}
/** Party Warp lookup: {inParty, expedition, member} - member = the online party member with that id (never p itself), or null. */
export function partyWarpMember(world,p,memberId){const party=group(world,p);if(!party)return{inParty:false,expedition:false,member:null};return{inParty:true,expedition:!!partyBelongsToExpedition(party),member:memberId!==p.id&&party.members.includes(memberId)?online(world,memberId)||null:null};}
export function partySnapshot(world,p){
 store(world);for(const[id,invite]of world.partyInvites)if(invite.expires<=world.now()||!world.parties.has(invite.party))world.partyInvites.delete(id);
 const party=group(world,p),invite=world.partyInvites.get(p.id);
 const row=member=>({id:member.id,name:member.profile.name,level:member.profile.level,classIndex:member.profile.classIndex,map:member.map,hp:member.hp,maxHp:member.maxHp,shield:Math.round(Number(member.shield)||0),maxShield:Math.round(Number(member.stats?.maxShield)||0),statuses:memberStatuses(world,member),leader:party?.leader===member.id});
 return {active:!!party,id:party?.id||null,name:party?.name||'',itemway:party?.itemway||0,leaderId:party?.leader||null,maxMembers:PARTY_MAX,members:party?party.members.map(id=>online(world,id)).filter(Boolean).map(row):[],
  invite:invite?{id:invite.party,from:invite.from,name:world.parties.get(invite.party)?.name,expires:invite.expires}:null,
  connected:[...world.players.values()].filter(other=>!other.leaving).map(other=>({id:other.id,name:other.profile.name,level:other.profile.level,classIndex:other.profile.classIndex,map:other.map,inParty:!!group(world,other)}))};
}
export function partyCommand(world,p,input){
 const party=group(world,p),op=input.operation;
 // A corp of an expedition is managed through the expedition window (original messages 65-67); only chat is shared.
 if(partyBelongsToExpedition(party)&&op!=='chat')fail('You are already in an expedition. Use the expedition window.');
 const pending=world.partyInvites.get(p.id),invitedParty=pending&&world.parties.get(pending.party);
 if(p.sceneTransition||[party,invitedParty].some(g=>g?.members.some(id=>online(world,id)?.sceneTransition)))fail('Wait until party admission finishes.');
 if(op==='create'){if(party)fail('You are already in a party.');if(typeof input.name==='string'&&(input.name.length>24||/[\x00-\x1f]/.test(input.name)))fail('Use a party name of 1–24 visible characters.');const name=typeof input.name==='string'?input.name.trim():`${p.profile.name}'s Party`;const made={id:randomUUID(),name:name||'Party',leader:p.id,members:[p.id],itemway:0};world.parties.set(made.id,made);p.partyId=made.id;}
 else if(op==='leave'){if(!party)fail('You are not in a party.');leaveParty(world,p);}
 else if(op==='invite'){lead(p,party);if(party.members.length>=PARTY_MAX)fail('The party is full.');const target=online(world,input.targetId);if(!target||target===p)fail('Choose another connected character.');if(group(world,target))fail('That character is already in a party.');const existing=world.partyInvites.get(target.id);if(existing&&existing.expires>world.now())fail('That character already has a pending invitation.');world.partyInvites.set(target.id,{party:party.id,from:p.profile.name,expires:world.now()+60000});}
 else if(op==='accept'||op==='decline'){const invite=world.partyInvites.get(p.id);if(!invite||invite.expires<=world.now())fail('The party invitation expired.');const invited=world.parties.get(invite.party);if(op==='accept'){if(party)fail('Leave your current party first.');if(!invited||!online(world,invited.leader))fail('That party is no longer available.');if(invited.members.length>=PARTY_MAX)fail('The party is full.');invited.members.push(p.id);p.partyId=invited.id;}world.partyInvites.delete(p.id);}
 else if(op==='kick'||op==='lead'){lead(p,party);const target=online(world,input.targetId);if(!target||!party.members.includes(target.id)||target===p)fail('Choose another party member.');if(op==='kick')leaveParty(world,target);else party.leader=target.id;}
 else if(op==='rename'){lead(p,party);if(typeof input.name!=='string'||!input.name.trim()||input.name.length>24||/[\x00-\x1f]/.test(input.name))fail('Use a party name of 1–24 visible characters.');party.name=input.name.trim();}
 else if(op==='itemway'){lead(p,party);if(!Number.isInteger(input.itemway)||input.itemway<0||input.itemway>4)fail('Invalid item distribution mode.');party.itemway=input.itemway;}
 else if(op==='chat'){if(!party)fail('You are not in a party.');if(typeof input.text!=='string'||!input.text.trim()||input.text.length>250||/[\x00-\x1f]/.test(input.text))fail('Use a party message of 1–250 visible characters.');if(world.now()<(p.chatAt||0))fail('Wait a second before sending another message.');p.chatAt=world.now()+1000;const linked=hostChatLinks(p.profile,world.data?.itemDB,input.text.trim(),world.now());if(!linked.text)fail('Chat message is empty.');world.emit(null,{type:'chat',channel:'party',partyId:party.id,actorId:p.id,name:p.profile.name,text:linked.text,recipients:[...party.members],...(linked.links.length?{links:linked.links}:{})});}
 else fail('Unknown party action.');
 world.sequence++;
}
