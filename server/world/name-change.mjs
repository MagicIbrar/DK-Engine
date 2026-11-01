// Character name change (item Type 0 Code 23), host side. Rules + sources: src/systems/extras/namechange-rules.js.
// The rename and the spent item commit in ONE accounts transaction (renameProfile with the staged profile), so a failed or
// refused rename never costs the item and a spent item always renamed the character. The client then returns to character
// selection (170:11 "You will be redirected to the Character Selection screen").
import {AuthoritativeInventory} from './inventory.mjs';
import {serializeLife} from './life-transactions.mjs';
import {publishProfileChanges} from './profile-publication.mjs';
import {expeditionOf} from './expedition.mjs';
import {socialRef} from './social-state.mjs';
import {isCharNameItem,charNameBlocker,checkNewCharacterName,NAME_TEXT} from '../../src/systems/extras/namechange-rules.js';

export const NAME_CHANGE_SCHEMAS={charname:['token','type','uid','name']};
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};

/** The host-checkable conditions of 170:10: party, expedition, guild (the friend list is client-held, see the client flow). */
export function charNameConditions(world,p){
  const party=!!(p.partyId&&world.parties?.get?.(p.partyId));
  const expedition=!!expeditionOf(world,p);
  const ref=socialRef(p),guild=Object.values(world.socialState?.guilds||{}).some(g=>g.members?.some(m=>m.ref===ref));
  return {party,expedition,guild};
}

export function charNameCommand(world,p,input){
  return serializeLife(p,async()=>{
    if(typeof input.uid!=='string'||typeof input.name!=='string')fail('Choose the name change item and a new name.');
    if(!world.renameProfile)fail('Character rename storage is unavailable.',503);
    const db=world.data.itemDB;if(!db)fail('The item catalog is unavailable.',503);
    const blocker=charNameBlocker(charNameConditions(world,p));if(blocker)fail(NAME_TEXT[blocker]);
    const checked=checkNewCharacterName(input.name,{current:p.profile.name});if(checked.error)fail(NAME_TEXT[checked.error]||NAME_TEXT.nameChars);
    const before=structuredClone(p.profile),profile=structuredClone(p.profile);
    const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
    const entry=inventory.bag.list.find(item=>item.uid===input.uid);
    if(!entry||!isCharNameItem(db.def(entry.itemIndex)))fail('Choose a Character Name Change item in your bag.');
    if(!inventory.consumeEntry(entry,1))fail('This item is no longer available.');
    // Same save queue as every profile write: the rename and the spent item are one durable record. sceneTransition holds
    // autosave/simulation (as commitLife does) so no older profile can be written over it while it is pending.
    const transition=p.sceneTransition;p.sceneTransition=true;
    try{
      const record=world.canonical({...p,profile});
      const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(()=>world.renameProfile(p.account,p.characterId,checked.name,undefined,record));
      world.saveQueue=task.catch(()=>{});
      let result;
      try{result=await task;}catch(error){if(error.status===409)fail(NAME_TEXT.nameTaken,409);throw error;}
      profile.name=result.name;
      publishProfileChanges(p.profile,before,profile);
      world.changed(p);
      world.emit(p.map,{type:'rename',actorId:p.id,name:result.name,nameColor:p.profile.nameColor||'white'});
      world.emit(p.map,{type:'inventory',actorId:p.id,reason:'charname'});
      return {name:result.name};
    }finally{p.sceneTransition=transition;}
  });
}
