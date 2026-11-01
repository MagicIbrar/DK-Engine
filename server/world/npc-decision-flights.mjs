// ENGINE-CHOSEN concurrency limit, not native action timing. A slow ordinary
// action keeps its exact actor flight without holding every other actor.
export function createNpcDecisionFlights({world,current,enabled,generation=()=>0,onError=()=>{},maxFlights=8}={}){
 const flights=new Map();
 const owns=p=>flights.get(p?.account)?.player===p;
 return {
  owns,
  count:()=>flights.size,
  start(player,brain,work){
   if(!enabled()||flights.size>=maxFlights||flights.has(player.account)||!current(player,brain))return false;
   const account=player.account,token=player.token,id=player.id,characterId=player.characterId,epoch=generation();
   const flight={player,brain,token,task:null};flights.set(account,flight);
   const actorCustody=()=>world.players.get(account)===player&&player.token===token&&player.id===id&&player.characterId===characterId&&current(player,brain);
   const custody=()=>generation()===epoch&&actorCustody();
   flight.task=Promise.resolve().then(async()=>{if(!enabled()||!custody())return;await work(custody);
    // Capture this accepted actor checkpoint only; do not chase the global
    // save tail or a replacement account's work during shutdown/handoff.
    const checkpoint=player._npcLatestFlight;if(actorCustody()&&checkpoint?.token===token&&checkpoint.id===id&&checkpoint.characterId===characterId)await checkpoint.task;
   }).finally(()=>{if(flights.get(account)===flight)flights.delete(account);});
   // Observe checkpoint failures too. Never attach a failure to a replacement
   // actor/brain, and never leave an unhandled rejection between director ticks.
   void flight.task.catch(error=>{if(custody())onError(error,player,brain);});return true;
  },
  async settle(){while(flights.size)await Promise.allSettled([...flights.values()].map(f=>f.task));},
 };
}
