import {GAMEPLAY_PREFERENCE_KEYS,gameplayPreferences} from '../../game/gameplay-preferences.js';
export function installGameplayPreferences(game,network){
 let pending=false,disposed=false,last='',retryAt=0,off=null,store=null;
 const sync=async()=>{
  if(disposed||pending||!network.active||!network.ready||network._joining||!network.token||!network.self?.id||!game.options?.get)return false;
  const token=network.token,owner=network.self.id,values=gameplayPreferences(Object.fromEntries(GAMEPLAY_PREFERENCE_KEYS.map(k=>[k,game.options.get(k)]))),key=token+':'+owner+':'+JSON.stringify(values);
  if(key===last)return true;pending=true;
  try{const result=await network.action('preferences',{values});if(result&&!disposed&&token===network.token&&owner===network.self?.id)last=key;return !!result;}
  finally{pending=false;retryAt=Date.now()+1000;}
 };
 const adapter={sync,update(){if(game.options!==store){off?.();store=game.options;off=store?.on?.('change',patch=>{if(GAMEPLAY_PREFERENCE_KEYS.some(k=>k in patch)){retryAt=0;void sync().catch(()=>{});}});}if(Date.now()>=retryAt)void sync().catch(()=>{});},dispose(){disposed=true;off?.();}};
 game.gameplayPreferences=adapter;return adapter;
}
