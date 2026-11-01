// ENGINE-CHOSEN issuer binding for the original unoffered1637 Frontier ticket dialogue.
export function installFrontierTicket(game,network,bridge){
 let disposed=false,undo=[];const ROLE='FRONTIER_TICKET';
 const eligible=n=>!disposed&&!network.disposed&&[[150,5532],[550,5668]].some(([map,npc])=>map===Number(game.world?.info?.index)&&npc===Number(n));
 const pick=npc=>{const id=Number(npc?.npcIndex??npc?.def?.index);if(!eligible(id))return false;
  void Promise.resolve(game.uiwin?.msgbox?.('Receive a Frontier Dungeon Admission Ticket? Guild level 5 is required. You can receive three per day; each expires after three hours.',{kind:'yesno',title:'Frontier Dungeon Ticket'})).then(answer=>{
   if(!eligible(id)||answer!=='yes'&&answer!==true)return;
   return network.action('dungeon',{operation:'frontier-ticket',npc:id}).then(result=>{if(result?.frontierTicket?.text)game.chat?.system?.(result.frontierTicket.text,'sys');});
  }).catch(error=>game.chat?.system?.(error.message,'err'));return true;
 };
 const register=()=>{if(disposed)return;for(const u of undo)u?.();undo=[game.npcServices?.provide?.(n=>eligible(n)?[{role:ROLE,label:'Frontier Dungeon Ticket'}]:[]),game.npcServices?.register?.(ROLE,pick)];};
 register();const off=game.events?.on?.('systems',register),old=bridge.dispose;
 bridge.dispose=()=>{disposed=true;for(const u of undo)u?.();if(typeof off==='function')off();old?.();};
}
