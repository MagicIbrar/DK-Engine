// A bfcache restore must not reuse the lease/actors disposed by pagehide.
// Ordinary tab visibility changes keep the existing live connection.
export function installNetworkPageLifecycle(network,win=globalThis){
 let hidden=false,restoring=false,leaving;
 const show=async event=>{
  if(!event.persisted||!hidden||restoring)return;
  restoring=true;win.removeEventListener?.('pageshow',show);
  let saved=false,timer;try{saved=(await Promise.race([leaving,new Promise(resolve=>{timer=win.setTimeout?.(()=>resolve(false),30000);})]))!==false;}catch{}finally{win.clearTimeout?.(timer);}
  if(saved)win.location?.reload?.();
  else {network.game?.hud?.log?.('The previous connection could not finish saving. Reopen the connection screen and retry after the host recovers.','err');win.dispatchEvent?.(new Event('dekaron:connection-recovery-required'));}
 };
 network._pagehide=()=>{hidden=true;win.addEventListener?.('pageshow',show);leaving=network.leave({keepalive:true});};
 win.addEventListener?.('pagehide',network._pagehide);
}
