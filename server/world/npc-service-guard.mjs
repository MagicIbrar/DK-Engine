// Battle status and NPC services. Official Global guide 62 "Battle status": "It lasts for 60 seconds from the moment you start PK",
// "Boarding a means of transportation / using a mobile portal / using an NPC is not possible", "During the Almighty Holy Water premium
// feature, NPCs and parties cannot be moved". Native refusals: stringtable_pc 40:108 "[Message] This cannot be used in the Combat
// mode." (COMBAT_TEXT.service) and stringtable_system 101:248 (COMBAT_TEXT.premium) for the Holy Water substitutes of an NPC.
//
// One central guard, so every NPC service module stays unchanged:
//   * SharedWorld.action/npcAction run each command of a battle-status actor inside an AsyncLocalStorage scope;
//   * npc-services.mjs nearbyNpc (the proximity check every NPC service performs) refuses inside that scope when it finds the NPC;
//   * the few NPC services that do not go through nearbyNpc (quest dialogs at placed NPCs, dungeon entrances at placed NPCs) and the
//     Holy Water substitutes (remote storage, post, brokerage) are refused here before dispatch.
// Not refused: cancel / leave / exit / decline / abandon / quit / unregister / close operations (cancelling stays possible), commands
// that use no NPC (inventory, skills, chat, party, D-Shop, guild window, Colosseum queue window ...), and the battle objects of a
// running battle that merely have NPC rows (Sunstone job 52, siege reign job 25, Zuto stones job 119).
import {AsyncLocalStorage} from 'node:async_hooks';
import {pkBattleActive,pkBattleStartedAt} from './wanted.mjs';
import {premiumHas,premiumRemoteStorage} from './premium-service.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {FIELD_PK,COMBAT_TEXT} from '../../src/config/engine-chosen-pk.js';

const scope=new AsyncLocalStorage();
export const NPC_BATTLE_CANCEL_OPS=Object.freeze(['cancel','leave','exit','decline','abandon','quit','unregister','close']);
/** Battle objects (not NPC services): Sunstone 52 (arena-rules SUNSTONE_JOB), siege reign 25 (siege-rules JOBS.REIGN), Zuto stone 119. */
export const BATTLE_OBJECT_JOBS=Object.freeze([52,25,119]);
const QUEST_NPC_OPS=['accept','instant','claim','talk','purchase'];
const MIDDLEMAN_JOB=46;
const refuse=(text,code)=>{throw Object.assign(new Error(text),{status:400,code});};
const service=()=>refuse(COMBAT_TEXT.service,'NPC_BATTLE_STATUS');      // 40:108
const premium=()=>refuse(COMBAT_TEXT.premium,'PREMIUM_BATTLE_STATUS');  // 101:248

/** Services that are NPC uses but are not (always) found through nearbyNpc, checked before dispatch inside the scope. */
function directNpcUse(world,p,input){
  const type=input.type,op=input.operation;
  if(type==='quest'&&QUEST_NPC_OPS.includes(op)&&input.npc!=null)service();            // quest dialog accept / turn-in / talk / sale at an NPC
  if(type==='dungeon'&&op==='enter')service();                                          // dungeon entrance NPC
  const storage=['storage','stashmove','bank'].includes(type)||type==='sortitems'&&input.container!=null&&input.container!=='bag';
  if(storage){nearbyNpc(world,p,{role:'STORAGE'});if(premiumRemoteStorage(world,p.profile))premium();}   // Storage NPC, else Holy Water remote storage
  if(type==='mail'&&['send','delete'].includes(op)){nearbyNpc(world,p,{role:'MAIL'});if(premiumHas(world,p.profile,'post'))premium();}
  if(type==='consign'){nearbyNpc(world,p,{jobType:MIDDLEMAN_JOB});if(premiumHas(world,p.profile,'brokerage'))premium();}
}
/** SharedWorld.action / npcAction: run one command, inside the NPC-service scope while the actor is in battle status. */
export function runNpcServiceScope(world,account,input,fn){
  const p=world.players?.get?.(account);
  if(!p||!input||typeof input!=='object'||NPC_BATTLE_CANCEL_OPS.includes(input.operation)||!pkBattleActive(world,p))return fn();
  return scope.run({player:p},()=>{directNpcUse(world,p,input);return fn();});
}
/** nearbyNpc found `row` for p: inside a battle-status command this is an NPC use and is refused (40:108). */
export function assertNpcServiceUse(world,p,query={}){
  const s=scope.getStore();
  if(s&&s.player===p&&!BATTLE_OBJECT_JOBS.includes(Number(query.jobType))&&pkBattleActive(world,p))service();
}
/** Server time at which the actor's battle status ends (self snapshot, so the client can mirror the refusal), or undefined. */
export function battleStatusUntil(world,p){if(!pkBattleActive(world,p))return undefined;const at=pkBattleStartedAt(world,p);return Number.isFinite(at)?at+FIELD_PK.battleStatusMs:undefined;}
