// Reuse authored mount/rider rigs, but summon and dismissal are server intents.
import {Riding} from '../mounts/riding.js';
import {WingVisual} from '../mounts/wings.js';
// Cosmetic only: the original delay window follows canonical phase/remaining time.
export function sharedMountProgress(game,sys,network){
 let phase=null,total=0,remaining=0,win=null,generation=0;
 const paint=()=>win?.control('processbar').setGauge(total?Math.min(1,Math.max(0,1-remaining/total)):0);
 const sync=()=>{
  const state=network.self?.mount,next=['summoning','dismissing'].includes(state?.phase)?state.phase:null;
  remaining=Math.max(0,Number(state?.remainingMs)||0);
  if(next===phase){paint();return;}
  phase=next;const seq=++generation;
  if(!phase){if(win?.isOpen)win.close('canonical');win=null;return;}
  total=Math.max(1,remaining);
  void Promise.resolve(game.uiwin?.get('mount_delay')).then(w=>{
   if(!w||seq!==generation||network.disposed)return;
   win=w;w.control('pan_waittime').show();w.control('lbl_waittime').setText(sys.text(phase==='summoning'?'summoning':'deactivating'));paint();game.uiwin.openWindow(w);
  }).catch(error=>console.warn('[network] mount progress',error));
 };
 const update=sys.update?.bind(sys);
 if(update)sys.update=dt=>{update(dt);if(phase){remaining=Math.max(0,remaining-dt*1000);paint();}};
 game.events?.on?.('server:profile',sync);sync();
}
export function installSharedMounts(game,network){
 const api=game.mounts,sys=api?.system,ride=sys?.riding;if(!ride)return;
 sharedMountProgress(game,sys,network);
 const jobs=[];let loading=0;
 const drain=()=>{while(loading<2&&jobs.length){const job=jobs.shift();loading++;Promise.resolve().then(job.run).then(job.resolve,job.reject).finally(()=>{loading--;drain()});}};
 const build=(riding,item)=>new Promise((resolve,reject)=>{jobs.push({run:()=>network.disposed?null:riding._build(item),resolve,reject});drain();});
 let generation=0,desired=null;
 // MOVE-NO-RUBBERBAND: summon/dismiss mid-move first settles the body at its real position (stop report), so the
 // host's stand-still rule and mount cast never snap the rider back (network/client.js settleMovement).
 const settled=fn=>typeof network.settleMovement==='function'?network.settleMovement(fn):fn();
 ride.mount=()=>settled(()=>network.action('mount',{on:true}));
 ride.dismount=()=>settled(()=>network.action('mount',{on:false}));
 ride.toggle=()=>settled(()=>network.action('mount',{on:!network.self?.mount}));
 if(api.test)for(const name of Object.keys(api.test))api.test[name]=()=>network.unavailable('Unverified equipment');
 const apply=async state=>{
  const item=state?.phase==='on'?state.item:null;
  if(item===desired)return;desired=item;const seq=++generation;
  if(!item){ride._detach();return;}
  // the rig riding.js pre-loaded (and pre-compiled) while on foot, else a fresh load
  const rig=ride._takeWarm?.(item)||await build(ride,item);
  if(seq!==generation||network.disposed||desired!==item){ride._disposeRig(rig);return;}
  if(rig){ride._detach();ride._attach(item,rig);}
 };
 game.events?.on?.('server:profile',()=>{void apply(network.self?.mount).catch(error=>console.warn('[network] mount visual',error));});
 network.actorMount=(actor,row)=>{
  if(actor.kind!=='player'||!actor.model)return;
  let state=actor._sharedMount;
  if(!state){
   const facade=Object.create(game);facade.player=actor;Object.defineProperty(facade,'save',{get:()=>actor.save});facade.events={emit(){}};
   const riding=new Riding({game:facade,data:sys.data,setMenuChecked(){},onStatsChanged(){}});
   const wings=new WingVisual({game:facade,data:sys.data,riding});
   const buildWing=wings._build.bind(wings);let wingQueued=false;
   wings._build=(...args)=>{
    if(wingQueued)return;wingQueued=true;
    const work=new Promise((resolve,reject)=>{jobs.push({run:()=>actor.disposed||network.disposed||wings.equipped()!==args[1]?null:buildWing(...args),resolve,reject});drain();});
    void work.catch(error=>console.warn('[network] remote wing',error)).finally(()=>{wingQueued=false;});
   };
   state=actor._sharedMount={riding,wings,item:null,generation:0};
   const update=actor.update.bind(actor),dispose=actor.dispose.bind(actor);
   actor.update=dt=>{update(dt);riding.update(dt);wings.update(dt)};
   actor.dispose=()=>{state.generation++;wings.dispose();riding._detach();dispose()};
  }
  const item=row.mount?.phase==='on'?row.mount.item:null;
  if(item===state.item)return;state.item=item;const seq=++state.generation;
  if(!item){state.riding._detach();return;}
  void build(state.riding,item).then(rig=>{
   if(seq!==state.generation||actor.disposed){state.riding._disposeRig(rig);return;}
   if(rig){state.riding._detach();state.riding._attach(item,rig);}
  }).catch(error=>console.warn('[network] remote mount',error));
 };
}
