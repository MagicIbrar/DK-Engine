// Expedition ("troop"): up to three corps of seven characters that run the three troop dungeons (Nest of Cherubim,
// Karon's Transport Ship B/F; share/dungeon keeper TROOP, min 9-12 members). Rules come from
// script/string/normal/stringtable_troop.txt (cate 555) and the original window ui_troopfooting.txt (three corp
// sections of seven rows; Create / Leader / Form / Move All / Modify / Quit; item distribution Basic, Orderly, Free,
// Random). Each corp is an ordinary party object flagged with its expedition, so group EXP, loot distribution and
// party chat keep working unchanged. A character is in a party OR an expedition, never both (messages 65-67).
//
// ASSUMPTIONS (not derivable from the client files): the maximum is 3 corps x 7 = 21 (the window art has exactly that
// many rows); "Move All" compacts every member into corps in their current order; invitations last 60 s like parties.
import {randomUUID} from 'node:crypto';
import {sameScene} from './scene.mjs';

export const EXPEDITION_CORPS=3;
export const CORP_MAX=7;
export const EXPEDITION_MAX=EXPEDITION_CORPS*CORP_MAX;
export const EXPEDITION_SCHEMAS={expedition:['token','type','operation','targetId','name','corp','itemway']};
const fail=message=>{throw Object.assign(new Error(message),{status:400})};
const store=world=>{world.parties||=new Map();world.expeditions||=new Map();world.expeditionInvites||=new Map();return world.expeditions;};
const online=(world,id)=>[...world.players.values()].find(p=>p.id===id&&!p.leaving);
const corpParty=(world,expedition,corp)=>expedition.corps[corp]?world.parties.get(expedition.corps[corp]):null;

/** The expedition a player belongs to (via the flagged corp party), or null. */
export function expeditionOf(world,p){store(world);const party=p?.partyId&&world.parties.get(p.partyId);return party?.expedition?world.expeditions.get(party.expedition)||null:null;}
/** A party that is owned by an expedition corp (party commands must leave these alone). */
export const partyBelongsToExpedition=party=>!!party?.expedition;
/** Connected members of the player's expedition in corp order, or null when the player is in none. */
export function expeditionMembers(world,p){
  const expedition=expeditionOf(world,p);if(!expedition)return null;
  const members=[];for(let corp=0;corp<EXPEDITION_CORPS;corp++){const party=corpParty(world,expedition,corp);if(party)for(const id of party.members){const member=online(world,id);members.push(member||{id,offline:true});}}
  return {expedition,leader:expedition.leader,members};
}
const memberIds=(world,expedition)=>{const ids=[];for(let corp=0;corp<EXPEDITION_CORPS;corp++){const party=corpParty(world,expedition,corp);if(party)ids.push(...party.members);}return ids;};
const size=(world,expedition)=>memberIds(world,expedition).length;
const lead=(p,expedition)=>{if(!expedition)fail('You are not an expedition member.');if(expedition.leader!==p.id)fail('Only an expedition leader has the authority.');};
const inInstance=(world,expedition)=>memberIds(world,expedition).some(id=>online(world,id)?.instanceId);

function makeCorp(world,expedition,corp){
  const party={id:randomUUID(),name:`${expedition.name} ${corp+1}`,leader:null,members:[],itemway:expedition.itemway,expedition:expedition.id,corp};
  world.parties.set(party.id,party);expedition.corps[corp]=party.id;return party;
}
function place(world,expedition,p,corp){
  const party=corpParty(world,expedition,corp)||makeCorp(world,expedition,corp);
  if(party.members.length>=CORP_MAX)fail('That corp is full.');
  party.members.push(p.id);p.partyId=party.id;
  party.leader=party.members.includes(expedition.leader)?expedition.leader:party.members[0];
}
function detach(world,expedition,p){
  const party=world.parties.get(p.partyId);p.partyId=null;if(!party)return;
  party.members=party.members.filter(id=>id!==p.id);
  if(!party.members.length){world.parties.delete(party.id);expedition.corps[party.corp]=null;}
  else party.leader=party.members.includes(expedition.leader)?expedition.leader:party.members[0];
}
function dissolve(world,expedition){
  for(let corp=0;corp<EXPEDITION_CORPS;corp++){const party=corpParty(world,expedition,corp);if(!party)continue;for(const id of party.members){const member=online(world,id);if(member)member.partyId=null;}world.parties.delete(party.id);}
  world.expeditions.delete(expedition.id);
  for(const [id,invite] of world.expeditionInvites)if(invite.expedition===expedition.id)world.expeditionInvites.delete(id);
}
/** A member left the world or was removed: keep the expedition consistent (also called from party leave on disconnect). */
export function leaveExpedition(world,p){
  const expedition=expeditionOf(world,p);if(!expedition)return false;
  detach(world,expedition,p);
  const ids=memberIds(world,expedition);
  if(!ids.length)dissolve(world,expedition);
  else if(expedition.leader===p.id){expedition.leader=ids[0];for(let corp=0;corp<EXPEDITION_CORPS;corp++){const party=corpParty(world,expedition,corp);if(party&&party.members.includes(expedition.leader))party.leader=expedition.leader;}}
  world.sequence++;return true;
}

/**
 * The status icons the troop state window (game2/ui_troopstatewnd.txt pan_buffstatus / pan_debuffstatus) shows under a
 * member: the statuses the original status table shares with other players (share/skill/status.csv SendToOthers = 1;
 * buff = Property 1, else debuff; icon = IconIndex in imagetable group buffer) and the member's item spells (spell.csv
 * SpellIcon, imagetable group Spell_S, always buffs). No timers: the window shows icons only.
 */
export function memberStatuses(world,member){
  const out=[];
  for(const s of member?.profile?.buffs||[]){
    if(!(Number(s.remaining)>0))continue;
    if(s.spell){if(Number.isFinite(Number(s.spellIcon)))out.push({icon:Number(s.spellIcon),group:'Spell_S',buff:true});continue;}
    const def=world.data?.skillStatuses?.[s.statusIndex]||world.data?.skillCommon?.statuses?.[s.statusIndex];
    if(Number(def?.sendToOthers)!==1)continue;
    out.push({icon:Number(def.iconIndex??s.iconIndex),group:'buffer',buff:Number(def.property)===1});
  }
  return out;
}

export function expeditionSnapshot(world,p){
  store(world);for(const [id,invite] of world.expeditionInvites)if(invite.expires<=world.now()||!world.expeditions.has(invite.expedition))world.expeditionInvites.delete(id);
  const expedition=expeditionOf(world,p),invite=world.expeditionInvites.get(p.id);
  const row=(member,corp,party)=>({id:member.id,name:member.profile.name,level:member.profile.level,classIndex:member.profile.classIndex,map:member.map,hp:member.hp,maxHp:member.maxHp,
    shield:Math.round(Number(member.shield)||0),maxShield:Math.round(Number(member.stats?.maxShield)||0),statuses:memberStatuses(world,member),corp,leader:expedition.leader===member.id,instance:!!member.instanceId});
  const corps=[];if(expedition)for(let corp=0;corp<EXPEDITION_CORPS;corp++){const party=corpParty(world,expedition,corp);corps.push(party?party.members.map(id=>online(world,id)).filter(Boolean).map(member=>row(member,corp,party)):[]);}
  return {active:!!expedition,id:expedition?.id||null,name:expedition?.name||'',leaderId:expedition?.leader||null,itemway:expedition?.itemway||0,
    maxMembers:EXPEDITION_MAX,corpMax:CORP_MAX,corps,size:expedition?corps.flat().length:0,
    invite:invite?{id:invite.expedition,from:invite.from,name:world.expeditions.get(invite.expedition)?.name,expires:invite.expires}:null};
}

const validName=name=>typeof name==='string'&&name.trim()&&name.trim().length<=24&&!/[\x00-\x1f\x7f]/.test(name);
export function expeditionCommand(world,p,input){
  store(world);const op=input.operation,expedition=expeditionOf(world,p),party=p.partyId&&world.parties.get(p.partyId);
  if(p.sceneTransition)fail('Wait until admission finishes.');
  if(op==='create'){
    if(expedition)fail('You are not allowed to form an expedition since you have already joined an expedition.');
    if(party)fail('You are not allowed to form an expedition since you have already joined a party.');
    if(!validName(input.name))fail('Please, decide on an expedition name.');
    const made={id:randomUUID(),name:input.name.trim(),leader:p.id,itemway:0,corps:[null,null,null]};world.expeditions.set(made.id,made);place(world,made,p,0);
  }
  else if(op==='invite'){
    lead(p,expedition);if(size(world,expedition)>=EXPEDITION_MAX)fail("You can't invite any more.");
    const target=online(world,input.targetId);if(!target||target===p)fail('This user is not allowed to be invited.');
    if(expeditionOf(world,target))fail('He/she has already joined the expedition.');
    if(target.partyId&&world.parties.get(target.partyId))fail('You have already joined another party.');
    const existing=world.expeditionInvites.get(target.id);if(existing&&existing.expires>world.now())fail(`${target.profile.name} is in the middle of being invited.`);
    world.expeditionInvites.set(target.id,{expedition:expedition.id,from:p.profile.name,expires:world.now()+60000});
  }
  else if(op==='accept'||op==='decline'){
    const invite=world.expeditionInvites.get(p.id);if(!invite||invite.expires<=world.now())fail('The expedition invitation expired.');
    const invited=world.expeditions.get(invite.expedition);
    if(op==='accept'){
      if(expedition)fail('Since you already belonged to an expedition, you cannot join another expedition.');
      if(party)fail('You have already joined another party.');
      if(!invited||!online(world,invited.leader))fail('The expedition leader cannot be found.');
      if(size(world,invited)>=EXPEDITION_MAX)fail("You can't invite any more.");
      let corp=0;while(corp<EXPEDITION_CORPS&&(corpParty(world,invited,corp)?.members.length||0)>=CORP_MAX)corp++;place(world,invited,p,corp);
    }
    world.expeditionInvites.delete(p.id);
  }
  else if(op==='leave'){
    if(!expedition)fail('You are not an expedition member.');
    if(p.instanceId)fail('Expedition Withdrawal, Disbandment, and Expulsion are not allowed in an instance dungeon.');
    leaveExpedition(world,p);
  }
  else if(op==='kick'){
    lead(p,expedition);const target=online(world,input.targetId);
    if(!target||target===p||expeditionOf(world,target)?.id!==expedition.id)fail('Please, choose an expedition member.');
    if(target.instanceId)fail('If a member entered an instance dungeon, the member cannot be expelled.');
    leaveExpedition(world,target);
  }
  else if(op==='lead'){
    lead(p,expedition);const target=online(world,input.targetId);
    if(!target||target===p||expeditionOf(world,target)?.id!==expedition.id)fail('The delegation has failed.');
    expedition.leader=target.id;for(let corp=0;corp<EXPEDITION_CORPS;corp++){const cp=corpParty(world,expedition,corp);if(cp)cp.leader=cp.members.includes(expedition.leader)?expedition.leader:cp.members[0];}
  }
  else if(op==='disband'){
    lead(p,expedition);if(inInstance(world,expedition))fail('Expedition Withdrawal, Disbandment, and Expulsion are not allowed in an instance dungeon.');
    dissolve(world,expedition);
  }
  else if(op==='rename'){
    lead(p,expedition);if(!validName(input.name))fail('Please, decide on an expedition name.');
    expedition.name=input.name.trim();for(let corp=0;corp<EXPEDITION_CORPS;corp++){const cp=corpParty(world,expedition,corp);if(cp)cp.name=`${expedition.name} ${corp+1}`;}
  }
  else if(op==='itemway'){
    lead(p,expedition);if(!Number.isInteger(input.itemway)||input.itemway<0||input.itemway>3)fail('The distribution system has failed');
    expedition.itemway=input.itemway;for(let corp=0;corp<EXPEDITION_CORPS;corp++){const cp=corpParty(world,expedition,corp);if(cp)cp.itemway=input.itemway;}
  }
  else if(op==='shift'){
    lead(p,expedition);const target=online(world,input.targetId);
    if(!target||expeditionOf(world,target)?.id!==expedition.id)fail('Please, choose an expedition member.');
    if(!Number.isInteger(input.corp)||input.corp<0||input.corp>=EXPEDITION_CORPS)fail('The command is invalid.');
    const from=world.parties.get(target.partyId)?.corp;if(from===input.corp)return world.sequence++;
    // Check the destination first: a refused shift must leave the member exactly where they were.
    if((corpParty(world,expedition,input.corp)?.members.length||0)>=CORP_MAX)fail('That corp is full.');
    detach(world,expedition,target);place(world,expedition,target,input.corp);
  }
  else if(op==='allmove'){
    lead(p,expedition);const ids=memberIds(world,expedition),members=ids.map(id=>online(world,id)).filter(Boolean);
    for(const member of members)detach(world,expedition,member);
    members.forEach((member,index)=>place(world,expedition,member,Math.floor(index/CORP_MAX)));
  }
  else fail('The command is invalid.');
  world.sequence++;
}
export const _internal={memberIds,sameScene};
