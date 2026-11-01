import {urbanWarfareRequiresAdmission,urbanWarfareUnavailableText} from '../../src/systems/events/urban-warfare-routes.js';

// Closed admission boundary for Zuto's Battlefield 650 and Phantom Castle 653. Every generic route (travel, Smart Warp,
// NPC warp, dungeon floors, saved-map join) is refused here. Native factions are source servers (World_Index 1 / 2);
// never derive a side from a client field, editable profile, field channel, random split or the entered lobby.
//
// The ONE exception is the owner-directed single-server adaptation (src/game/urban-warfare-rules.js ZUTO_ADAPTATION):
// the Zuto controller (server/world/urban-warfare-controller.mjs) validates a registered, host-assigned member for the
// native Checkpoint teleport 133 and then opens exactly one synchronous destination check for map 650 through
// withUrbanWarfareTravelPermit. Phantom Castle 653 never receives a permit (its native entry route is unresolved).
let pending=null;
/** Run `start` (which must call commitFieldTravel synchronously first) with a one-shot permit for `map` (650 only). */
export function withUrbanWarfareTravelPermit(world,map,start){
 if(Number(map)!==650||!world||typeof start!=='function')throw Object.assign(Error('Only the Zuto battlefield accepts a controller permit.'),{status:403});
 const permit={world,map:650,used:false};pending=permit;
 try{return start();}finally{if(pending===permit)pending=null;}
}
export function assertUrbanWarfareAdmissionAvailable(world,map) {
 if(!urbanWarfareRequiresAdmission(map))return;
 if(pending&&!pending.used&&pending.world===world&&pending.map===Number(map)){pending.used=true;pending=null;return;}
 throw Object.assign(Error(urbanWarfareUnavailableText(world.data?.eventData)),{status:503,code:'URBAN_WARFARE_UNAVAILABLE'});
}
