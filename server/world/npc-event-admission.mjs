import {npcEventWindow} from './npc-event-parties.mjs';
import {joinableWar,warCapacity} from './party-war.mjs';
import {npcEventReservedAdmission} from './npc-event-resource-budget.mjs';
// Mixed parties retain ordinary authority. Independent NPC events need exact
// finite foreground custody; this never permits autonomous private dungeons.
export function validateNpcEventAdmission(world,members,{mode,map,leader,warId=null}) {
 if(!members.length||!members.every(p=>p.npcPlayer===true))return null;
 const fail=()=>{throw Object.assign(Error('NPC teams require native entry time and current finite event custody.'),{status:409});};
 const window=npcEventWindow(world.data.eventData?.modes?.[mode],world.now());if(window?.phase!=='enter')fail();
 const war=warId?world.instances?.get(warId):joinableWar(world,mode,map,leader);
 if(war&&(war.kind!==mode||Number(war.map)!==Number(map)||war.closed||war.closeRequested||war.run?.ended||war.run?.phase!=='waitStart'||war.run.phaseT<=5||war.teams.length>warCapacity(world,mode,map)))fail();
 const human=war&&[...world.players.values()].some(p=>p.npcPlayer!==true&&!p.leaving&&!p.dead&&!p.sceneTransition&&p.instanceId===war.id);
 if(!human)npcEventReservedAdmission(world,members,{map,leader,cycle:window.cycle,war:war||null});
 return war?.id||null;
}
