// Original vehicle windows send intent; uncertain writes retain their request ID through reconnect.
import {randomUUID} from './web-crypto.js';
export function installSharedVehicleServices(game,network){
  const api=game.mounts;if(!api)return;
  // The launcher opens the selected endpoint itself; world requests use that origin.
  // Wait for authenticated join identity before restoring account/character intents.
  const origin=globalThis.location?.origin;
  let key=null,pending=null,busy=false,disposed=false,lastRetryToken=null;
  const context=()=>{
    const self=network.self,char=game.save.id;
    if(!network.ready||!/^https?:\/\//.test(origin||'')||globalThis.location?.origin!==origin||self?.characterId!==char||!self.id?.endsWith(':'+char))return null;
    return `dekaron:vehicle-intent:v2:${JSON.stringify([origin,self.id])}`;
  };
  const bind=()=>{
    const next=context();if(!next)return false;
    if(next!==key){if(busy)return false;key=next;pending=null;lastRetryToken=null;try{pending=JSON.parse(globalThis.sessionStorage?.getItem(key)||'null');}catch{}}
    return true;
  };
  const store=()=>{if(!key)return;try{if(pending)globalThis.sessionStorage?.setItem(key,JSON.stringify(pending));else globalThis.sessionStorage?.removeItem(key);}catch{}};
  const life=()=>game.save.life||{};
  const receipt=id=>life().vehicleServiceReceipts?.find(r=>r.id===id);
  const refresh=()=>{for(const name of ['vehicle_mgmt','vehicle_cycle']){const win=game.uiwin?.window?.(name);if(win?.isOpen)win.data.refresh?.();}};
  const same=(a,b)=>JSON.stringify({operation:a.operation,uid:a.uid,gear:a.gear,uids:a.uids&&[...a.uids].sort()})===JSON.stringify({operation:b.operation,uid:b.uid,gear:b.gear,uids:b.uids&&[...b.uids].sort()});
  const send=async()=>{
    if(!pending||busy||disposed||!network.ready||!network.token||game.save.authority!=='server'||context()!==key)return false;
    const request=pending,requestKey=key,errorBefore=network._lastCommandError;busy=true;lastRetryToken=network.token;
    try{
      const result=await network.action('vehicleservice',request);
      if(context()!==requestKey)return false;
      const confirmed=receipt(request.requestId)||result?.vehicleServiceResult?.receipt;
      if(confirmed?.id===request.requestId){if(pending===request){pending=null;store();}refresh();return true;}
      // Known command errors keep the connection ready. A transport/save failure disconnects
      // it, so preserve that uncertain intent and retry the same ID after the next join.
      if(network.ready&&network._lastCommandError!==errorBefore&&pending===request){pending=null;store();}
      return false;
    }finally{busy=false;}
  };
  const submit=(operation,fields,reviewedRevision)=>{
    if(disposed||!network.active||!network.ready||!network.token||game.save.authority!=='server'||!bind())return Promise.resolve(network.unavailable('Vehicle services'));
    const selected={operation,...fields};
    if(pending&&!same(pending,selected)){game.chat?.system?.('Wait for the pending vehicle action to reconnect before choosing another action.','err');return Promise.resolve(false);}
    if(!pending){pending={...selected,revision:reviewedRevision??life().vehicleServiceRevision??0,requestId:randomUUID()};lastRetryToken=null;store();}
    return send();
  };
  api.vehicleServices={crystallize:(uids,revision)=>submit('crystallize',{uids},revision),evolve:uid=>submit('evolve',{uid}),enchant:(uid,gear,revision)=>submit('enchant',{uid,gear},revision),enhance:uid=>submit('enhance',{uid}),retry:send,get pending(){return pending&&structuredClone(pending);},get busy(){return busy;}};
  const sync=()=>{
    if(disposed||!bind()||!pending)return;
    if(receipt(pending.requestId)){pending=null;store();refresh();return;}
    if(network.ready&&(life().vehicleServiceRevision||0)!==pending.revision){pending=null;store();refresh();return;}
    if(network.ready&&network.token&&network.token!==lastRetryToken&&!busy)queueMicrotask(()=>{if(!disposed)void send();});
  };
  const off=game.events?.on?.('server:profile',sync);
  const dispose=network.dispose.bind(network);network.dispose=()=>{disposed=true;off?.();return dispose();};
  sync();
}
