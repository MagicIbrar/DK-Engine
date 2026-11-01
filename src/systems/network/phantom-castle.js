import {PHANTOM_CASTLE as C} from '../../config/engine-chosen-phantom-castle.js';

// The original ticket quest has no attached NPC in the available client tables.
// ENGINE-CHOSEN: expose its named first three issuances at each Zuto Checkpoint.
// The host owns eligibility, DIL, expiration, daily count and instance admission.
export function installSharedPhantomCastle(game,network,{bridge,dialog}) {
 const ROLE='PHANTOM_CASTLE';let disposed=false,generation=0,undo=[];
 const available=()=>!disposed&&!network.disposed&&[651,652].includes(Number(game.world?.info?.index));
 const send=operation=>network.action('dungeon',{operation,npc:C.npc});
 const error=e=>game.chat?.system?.(e.message,'err');
 const open=npc=>{
  if(!available()||Number(npc?.npcIndex??npc?.def?.index)!==C.npc)return false;
  const request=++generation;
  void Promise.resolve(send('phantom-info')).then(result=>{
   if(!available()||request!==generation||!result?.phantom)return;
   const info=result.phantom;
   const run=operation=>{
    dialog.close();generation++;
    void Promise.resolve(send(operation)).then(next=>{
     if(next?.phantom?.issued)game.chat?.system?.('Phantom Castle Admission Ticket received. Use it within 60 minutes.','sys');
    }).catch(error);
   };
   return dialog.open(npc,{title:'Phantom Castle',
    text:`Challenge the Acquirai Fanatic alone.\nLevel 170–250 • 30 minutes\nAdmission Ticket: 200,000 DIL; expires after 60 minutes.\nTickets remaining today: ${info.remaining} of ${C.issuesPerDay}.`,
    options:[...(info.tickets===0&&info.remaining>0?[{label:'Buy an Admission Ticket — 200,000 DIL',pick:()=>{
     void Promise.resolve(game.uiwin?.msgbox?.('Spend 200,000 DIL for a Phantom Castle Admission Ticket? It expires after 60 minutes.',{kind:'yesno'})).then(answer=>{
      if(available()&&request===generation&&(answer==='yes'||answer===true))run('phantom-ticket');
     }).catch(error);
    }}]:[]),{label:'Enter Phantom Castle',pick:()=>{if(available()&&request===generation)run('phantom-enter');}}]});
  }).catch(error);
  return true;
 };
 const provider=n=>available()&&Number(n)===C.npc?[{role:ROLE,label:'Phantom Castle'}]:[];
 const register=()=>{if(disposed)return;for(const u of undo)if(typeof u==='function')u();undo=[game.npcServices?.provide?.(provider),game.npcServices?.register?.(ROLE,open)];};
 register();const off=game.events?.on?.('systems',register);
 const previousDispose=bridge.dispose;
 bridge.dispose=()=>{disposed=true;generation++;if(typeof off==='function')off();for(const u of undo)if(typeof u==='function')u();undo=[];previousDispose?.();};
 return {open};
}
