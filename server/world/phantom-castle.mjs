import {PHANTOM_CASTLE as C} from '../../src/config/engine-chosen-phantom-castle.js';

// Lane 57 follow-up 3: Global data has no entrance to Zuto's Phantom Castle (map 653): no NPC job, warp,
// teleport or location targets it (see engine-chosen-phantom-castle.js). The ENGINE-CHOSEN Checkpoint 5913
// entrance was removed. Older clients that still send phantom-info / phantom-enter get a plain refusal:
// nothing is consumed, no instance is created and no state changes.
const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
export function phantomCastleCommand(world,p,input) {
 return Promise.resolve().then(()=>{
  if(input?.operation!=='phantom-info'&&input?.operation!=='phantom-enter')fail('Choose a Phantom Castle action.');
  fail(`Zuto's Phantom Castle (map ${C.map}) has no entrance in the original data.`,403);
 });
}