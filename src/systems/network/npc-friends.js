// ENGINE-CHOSEN NPC conversational opt-in; the existing Friends list and
// Messenger remain the player's interface. No account/session data is copied.
import {friendRosterKey,friendRosterReady} from '../life/common.js';
export function installNpcFriends(game,network){
 let busy=false,last=null,next=0,disposed=false,again=false;
 const sync=async()=>{if(disposed||game.life?.friends?.pendingAdd||!network.active||!network.ready||!network.self?.id||!game.life?.friends?.list||!friendRosterReady(game,network))return;
  if(busy){again=true;return;}
  const owner=network.self.id,scope=friendRosterKey(game);
  const names=game.life.friends.list().map(f=>f.name),key=scope+':'+JSON.stringify(names.map(n=>String(n).toLowerCase()).sort());if(key===last)return;
  busy=true;try{const result=await network.action('npcfriends',{operation:'set',names});if(result&&!disposed&&network.active&&network.ready&&network.self?.id===owner&&friendRosterKey(game)===scope&&friendRosterReady(game,network))last=key;}finally{busy=false;if(again){again=false;if(!disposed)void sync().catch(e=>game.chat?.system?.(e.message,'err'));}}
 };
 const adapter={sync,invalidate(){last=null;},get disposed(){return disposed;},update(){const now=Date.now();if(now<next)return;next=now+2000;void sync().catch(e=>game.chat?.system?.(e.message,'err'));},dispose(){disposed=true;again=false;}};
 game.npcFriends=adapter;return adapter;
}
