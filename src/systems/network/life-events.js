// Original vaccine windows display only canonical progress. OX remains guarded.
import {randomUUID} from './web-crypto.js';
export function installSharedLifeEvents(game,network){
  const events=game.life?.events;if(!events)return;
  let pending=null,pendingContext=null,busy=false,lastToken=null,disposed=false;
  const context=()=>network.self?.characterId===game.save.id&&globalThis.location?.origin?JSON.stringify([globalThis.location.origin,network.self.id]):null;
  const current=()=>game.save.life?.events||{virus:{},revision:0,receipts:[]};
  const send=async()=>{if(!pending||busy||disposed||!network.ready||!network.token||game.save.authority!=='server'||!pendingContext||context()!==pendingContext)return false;
    const request=pending,errorBefore=network._lastCommandError;busy=true;lastToken=network.token;
    try{const result=await network.action('lifeevent',request),receipt=current().receipts?.find(r=>r.id===request.requestId)||result?.lifeEventResult?.receipt;
      if(receipt?.id===request.requestId){if(pending===request)pending=null;void events._refreshVirus();return true;}
      if(network.ready&&network._lastCommandError!==errorBefore&&pending===request)pending=null;return false;
    }finally{busy=false;}};
  events._reward=()=>{if(disposed||!network.active||!network.ready||!network.token||game.save.authority!=='server')return Promise.resolve(network.unavailable('Event rewards'));
    if(!pending){const active=events._activeVirus();if(!active)return Promise.resolve(false);const item=game.save.inventory.find(i=>i.itemIndex===active.r.ItemIndex&&i.count>0&&(!i.expiresAt||i.expiresAt>Date.now()));if(!item)return Promise.resolve(false);
      pendingContext=context();if(!pendingContext)return Promise.resolve(false);pending={event:active.r.Index,uid:item.uid,revision:current().revision??0,requestId:randomUUID()};}
    return send();};
  const off=game.events?.on?.('server:profile',()=>{if(disposed)return;void events._refreshVirus();if(!pending)return;if(context()!==pendingContext||current().receipts?.some(r=>r.id===pending.requestId)||(current().revision??0)!==pending.revision){pending=null;return;}if(network.ready&&network.token!==lastToken&&!busy)queueMicrotask(()=>void send());});
  const dispose=network.dispose.bind(network);network.dispose=()=>{disposed=true;off?.();return dispose();};
}
