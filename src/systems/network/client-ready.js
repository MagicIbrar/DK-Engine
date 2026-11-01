/** Launcher tools follow a completed, successfully rendered scene, never login/join alone. */
export class ClientReadiness {
 constructor(game,network,{clock=()=>performance.now(),document:doc=globalThis.document,setTimer=(fn,ms)=>globalThis.setInterval(fn,ms),clearTimer=id=>globalThis.clearInterval(id)}={}){
  this.game=game;this.network=network;this.clock=clock;this.document=doc;this.clearTimer=clearTimer;
  this.renderLease=null;this.renderMap=null;this.renderAt=-Infinity;this.sent=null;this.sentAt=-Infinity;this.generation=0;this.sequence=0;this.disposed=false;
  this.off=game.events?.on?.('network',({state})=>{if(state!=='connected')this.invalidate();});
  this.visibility=()=>{if(doc?.hidden)this.invalidate();};doc?.addEventListener?.('visibilitychange',this.visibility);
  this.timer=setTimer(()=>this.tick(),250);
 }
 rendered(){
  if(this.disposed)return;const n=this.network,g=this.game;
  if(!g._worldReady||g._loadingMap||!g.world||!g.player||!n.ready||n.status!=='connected'||!n.token||Number(g.world.info?.index)!==Number(n.self?.map))return;
  this.renderLease=n.token;this.renderMap=Number(g.world.info.index);this.renderAt=this.clock();
 }
 condition(){const n=this.network,g=this.game;return !!(!this.disposed&&!this.document?.hidden&&g._worldReady&&!g._loadingMap&&n.ready&&!n.disposed&&n.status==='connected'&&n.token===this.renderLease&&Number(n.self?.map)===this.renderMap&&Number(g.world?.info?.index)===this.renderMap&&this.clock()-this.renderAt<2500&&(n.self?.permissions?.capabilities||g.accountPermissions?.capabilities||[]).includes('gm:panel'));}
 tick(){
  if(this.disposed)return;const ready=this.condition(),n=this.network,lease=n.token;
  if(!lease)return;const map=Number(gMap(this.game,n));if(!Number.isSafeInteger(map))return;
  const key=`${lease}:${map}:${ready}`,now=this.clock();
  if(this.sent===key&&(!ready||now-this.sentAt<2000))return;
  // Ordinary accounts do not call the GM-only endpoint. A previously ready GM
  // still sends false when its permission/connection/scene state changes.
  if(!ready&&!this.sent)return;
  this.sent=key;this.sentAt=now;const sequence=++this.sequence,generation=this.generation;
  void n._request('client-ready',{token:lease,ready,map,sequence}).catch(error=>{
   // A map transition can outlast the rendered frame. Keep the normal heartbeat
   // interval after its expected conflict instead of retrying every timer tick.
   if(this.sequence===sequence&&this.generation===generation&&this.sent===key&&!(ready&&error?.status===409))this.sent=null;
  });
 }
 invalidate(){this.generation++;this.renderLease=null;this.renderMap=null;this.renderAt=-Infinity;this.tick();}
 dispose({keepalive=false}={}){
  if(this.disposed)return;const n=this.network,lease=n.token,map=Number(gMap(this.game,n));
  this.disposed=true;this.clearTimer(this.timer);this.off?.();this.document?.removeEventListener?.('visibilitychange',this.visibility);
  if(lease&&this.sent&&Number.isSafeInteger(map))void n._request('client-ready',{token:lease,ready:false,map,sequence:++this.sequence},keepalive).catch(()=>{});
 }
}
function gMap(game,network){return network.self?.map??game.world?.info?.index;}
