import {Messenger} from '../events/text.js';
import {EffectBanners} from '../events/effectui.js';

// Display-only original event directives. The host owns stages, recipients and event sequence.
export function createSharedEventMessages(game,network,ui,bridge){
 let disposed=false,record=null,generation=0,world=game.world,lastSequence=-1,bgm=null;
 const pending=[],effects=new Set();
 const stopMusic=()=>{if(bgm&&game.audio?.music?.mapIndex===bgm.id)game.audio.stopBGM?.(0);bgm=null;};
 const scope=event=>!disposed&&!network.disposed&&record?.id===event.instanceId&&record.map===Number(event.map)&&network.self?.instanceId===event.instanceId&&Number(network.self?.map)===Number(event.map)&&(!event.phase||event.phase===record.phase);
 const ready=()=>!!bridge.data&&Number(game.world?.info?.index)===record?.map;
 const removeEffects=()=>{for(const b of effects)for(const e of b.live)for(const p of e.parts)p.el.remove();effects.clear();};
 const report=error=>game.chat?.system?.(error.message,'err');
 const play=event=>{
  const scene=game.world,epoch=generation,current=()=>scope(event)&&generation===epoch&&game.world===scene;
  if(!current()||!ready())return;
  const scoped=Object.create(game),nativeUi=game.uiwin,nativeAudio=game.audio,windowToken=Symbol('event-window');
  const windowRequests=game._sharedEventWindowRequests||=new Map();
  // Original window loading and sound decoding may complete after the battle/map has changed.
  scoped.uiwin=nativeUi&&Object.assign(Object.create(nativeUi),{
   window:name=>{if(!current())return null;windowRequests.set(name,windowToken);return nativeUi.window(name);},
   open:async(...args)=>{const name=args[0],existing=nativeUi.window(name);windowRequests.set(name,windowToken);const w=await nativeUi.open(...args);if(current())return w;if(!existing&&windowRequests.get(name)===windowToken)w?.close?.();return null;},
  });
  scoped.hud={log:text=>{if(current())game.chat?.system?.(text,'sys');}};
  scoped.audio={
   playBGM:id=>{if(current()){nativeAudio?.playBGM?.(id);bgm={id,instanceId:event.instanceId,world:scene};}},
   playAll:(list,opts)=>{if(!current())return;try{return Promise.resolve(nativeAudio?.playAll?.(list,{...opts,category:'effect',isCurrent:current})).catch(report);}catch(error){report(error);}},
  };
  const banners=new EffectBanners(scoped,bridge);effects.add(banners);
  const speaker=new Messenger(scoped,{
   notice:text=>{
    const token=Symbol('native-event-notice'),guarded=Object.create(ui);game._sharedEventNotice=token;
    Object.defineProperty(guarded,'_msgT',{get:()=>ui._msgT,set:value=>{if(current())ui._msgT=value;}});
    guarded._open=async(...args)=>{const w=await ui._open(...args);if(current())return w;if(game._sharedEventNotice===token)w?.close?.();return null;};
    void guarded.notice(text).catch(report);
   },
   banner:(id,ms)=>{banners.pending=(banners.pending||0)+1;void banners.show(id,ms).catch(report).finally(()=>banners.pending--);},
  });
  try{speaker.say(event.nativeEntry,{chat:event.chat!==false,notice:event.notice!==false,at:event.at||null});}catch(error){report(error);}
 };
 const flush=()=>{
  if(world!==game.world){world=game.world;generation++;stopMusic();removeEffects();}
  if(!ready())return;
  for(const event of pending.splice(0))if(scope(event))play(event);
  // A late join restores only the current authored music, never prior countdown/result notices.
  const id=Number(record.nativeBgm);
  if(record.phase!=='waitStart'&&Number.isSafeInteger(id)&&id>0&&scope({instanceId:record.id,map:record.map})&&(!bgm||bgm.id!==id||bgm.instanceId!==record.id||bgm.world!==world))play({instanceId:record.id,map:record.map,nativeEntry:{kind:'effect',sound:[{a:0,id}]}});
 };
 return {
  snapshot(value){
   const next=['deadFront','iceCastle'].includes(value?.kind)?value:null;
   if(next?.id!==record?.id||next?.map!==record?.map){generation++;lastSequence=-1;pending.length=0;stopMusic();removeEffects();}
   else if(next?.phase!==record?.phase){generation++;removeEffects();}
   record=next;
  },
  event(event){
   if(event?.type!=='event:message'||!event.nativeEntry)return false;
   if(!scope(event))return true;
   const seq=Number(event.sequence);if(!Number.isSafeInteger(seq)||seq<0||seq<=lastSequence)return true;
   lastSequence=seq;pending.push(event);if(pending.length>128)pending.shift();flush();return true;
  },
  update(dt){flush();for(const b of effects){b.update(dt);if(!b.live.length&&!b.pending)effects.delete(b);}},
  dispose(){disposed=true;generation++;pending.length=0;stopMusic();removeEffects();},
 };
}
