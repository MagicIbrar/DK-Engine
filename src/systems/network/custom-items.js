import {applyItem,removeItem,isCustomIndex,DRAFT_INDEX} from '../itembuilder/registry.js';
// ICON-PRELOAD (2026-10-30): the library fetch after every connect used to clear the WHOLE item icon cache
// (game.items.icons.cache.clear()), revoking every icon baked behind the loading screen: the inventory, equipment and
// shops then repainted EMPTY right after login and re-rendered every icon. Only icons of custom items whose record
// actually changed are invalidated now.
const customSnapshot=(db)=>{const out=new Map();for(const key of Object.keys(db.items))if(isCustomIndex(key)&&Number(key)!==DRAFT_INDEX){let shape=null;try{shape=db.shape?.(db.items[key])??null;}catch{}out.set(Number(key),JSON.stringify([db.items[key],shape]));}return out;};
const changedCustom=(before,after)=>{const out=new Set();for(const [i,v] of after)if(before.get(i)!==v)out.add(i);for(const i of before.keys())if(!after.has(i))out.add(i);return out;};
export function installSharedCustomItems(game,network){
 let revision=-1,wanted=-1,pending=false;const snapshot=network._snapshot.bind(network);
 const fetchLibrary=async()=>{if(pending||wanted===revision)return;pending=true;let success=false;try{const result=await network._request('customitems');if(!Array.isArray(result.items)||!Number.isInteger(result.revision))throw new Error('Invalid server item library.');if(result.revision<(game.serverCustomItems?.revision??-1)){revision=game.serverCustomItems.revision;wanted=Math.max(wanted,revision);return;}
  const db=game.items.db;const before=customSnapshot(db);for(const key of Object.keys(db.items))if(isCustomIndex(key)&&Number(key)!==DRAFT_INDEX)removeItem(db,Number(key));for(const record of result.items)applyItem(db,record);
  revision=result.revision;wanted=Math.max(wanted,revision);success=true;game.serverCustomItems=result;const changed=changedCustom(before,customSnapshot(db));const iconCache=game.items.icons?.cache;if(changed.size){if(iconCache?.invalidateItems)iconCache.invalidateItems(changed);else iconCache?.clear?.();}game._customItemIconsInvalidated=changed.size;game.items._recompute?.();game.items.look?.apply?.();
  game.events.emit('server:customitems',result);game.events.emit('inventory',{reason:'server-catalog'});
 }catch(error){network._lastCommandError={message:error.message,at:Date.now()};}finally{pending=false;if(success&&wanted!==revision&&revision>=0)void fetchLibrary();}};
 network._snapshot=state=>{snapshot(state);if(Number.isInteger(state?.customItemsRevision)){wanted=Math.max(wanted,state.customItemsRevision);void fetchLibrary();}};
 network.refreshCustomItems=()=>{revision=-1;return fetchLibrary();};
}
