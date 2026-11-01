import {applyItem,removeItem,isCustomIndex,DRAFT_INDEX} from '../itembuilder/registry.js';
export function installSharedCustomItems(game,network){
 let revision=-1,wanted=-1,pending=false;const snapshot=network._snapshot.bind(network);
 const fetchLibrary=async()=>{if(pending||wanted===revision)return;pending=true;let success=false;try{const result=await network._request('customitems');if(!Array.isArray(result.items)||!Number.isInteger(result.revision))throw new Error('Invalid server item library.');if(result.revision<(game.serverCustomItems?.revision??-1)){revision=game.serverCustomItems.revision;wanted=Math.max(wanted,revision);return;}
  const db=game.items.db;for(const key of Object.keys(db.items))if(isCustomIndex(key)&&Number(key)!==DRAFT_INDEX)removeItem(db,Number(key));for(const record of result.items)applyItem(db,record);
  revision=result.revision;wanted=Math.max(wanted,revision);success=true;game.serverCustomItems=result;game.items.icons?.cache?.clear?.();game.items._recompute?.();game.items.look?.apply?.();
  game.events.emit('server:customitems',result);game.events.emit('inventory',{reason:'server-catalog'});
 }catch(error){network._lastCommandError={message:error.message,at:Date.now()};}finally{pending=false;if(success&&wanted!==revision&&revision>=0)void fetchLibrary();}};
 network._snapshot=state=>{snapshot(state);if(Number.isInteger(state?.customItemsRevision)){wanted=Math.max(wanted,state.customItemsRevision);void fetchLibrary();}};
 network.refreshCustomItems=()=>{revision=-1;return fetchLibrary();};
}
