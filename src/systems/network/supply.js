// Preserve native supply windows/animation; only the host chooses and pays.
import {randomUUID} from './web-crypto.js';
export function installSharedSupply(game,network){
 const states=new Map();let pending=false;
 const send=async(kind,operation)=>{
  if(pending)return null;pending=true;
  try{
   const body={kind,operation,requestId:randomUUID()};
   if(operation!=='state')body.plateId=states.get(kind)?.id;
   const result=(await network.action('supply',body))?.supplyResult;
   if(result?.plate)states.set(kind,result.plate);
   return result||null;
  }finally{pending=false;}
 };
 game.sharedSupply={state:kind=>states.get(kind)||null,load:kind=>send(kind,'state'),spin:kind=>send(kind,'spin'),mix:()=>send('orbis','mix')};
}
