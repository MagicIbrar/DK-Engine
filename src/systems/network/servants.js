// Native servant controls read replicated actors and send intent. The host owns
// order, target, Great charge and attack results; no local summon AI runs here.
export function installSharedServants(game,network) {
  const sm=game.skills?.summons||game.summons;if(!sm)return;
  const ui=game.uiwin||game.ui;
  let owned=null,pending=false,suspended=false;
  const close=()=>{owned=null;ui?.close?.('servant_win');ui?.close?.('servantskill');};
  const find=(owner,dead)=>owner===game.player&&network.ready&&!suspended?
    [...(network.servants?.values()||[])].find(a=>a.owner===owner&&!a.disposed&&!!a.dead===dead)||null:null;
  sm.servantOf=owner=>find(owner,false);sm.deadServantOf=owner=>find(owner,true);
  const send=(type,input)=>{
    if(pending||!network.ready||!sm.servantOf(game.player)||game.player?.dead)return false;
    pending=true;
    void Promise.resolve().then(()=>network.action(type,input)).catch(error=>console.warn('[skills] servant request failed',error)).finally(()=>{pending=false;});
    return true;
  };
  const target=()=>game.player?.target||game.controller?.target;
  sm.command=order=>{
    if(!['assist','attack','free','call','stop','destroy'].includes(order))return false;
    const input={order},t=target();if(order==='attack'&&t?.networkId)input.targetId=t.networkId;
    return send('summonOrder',input);
  };
  sm.useGreat=()=>{
    const sv=sm.servantOf(game.player);if(!sm.greatBlock(sv)||sm.greatCharge(sv)<1)return false;
    const input={},t=sv.target||target();if(t?.networkId)input.targetId=t.networkId;
    return send('summonGreat',input);
  };
  network.servantSnapshot=rows=>{
    suspended=false;
    for(const row of rows){
      const actor=network.servants?.get(row.id);if(!actor)continue;
      actor.ownerId=row.ownerId;actor.owner=row.ownerId===network.self?.id?game.player:network.players?.get(row.ownerId)||null;
      actor.charge=Number(row.charge)||0;
      actor.target=network.monsters?.get(row.targetId)||null;
    }
    const next=sm.servantOf(game.player);
    if(next!==owned){
      close();owned=next;
      if(next)game.events?.emit?.('summon',{on:true,owner:game.player,servant:next,server:true});
    }
    if(next)sm.mode=rows.find(row=>row.id===next.networkId)?.order||'assist';
  };
  const suspend=()=>{suspended=true;close();};
  const off=[game.events?.on?.('map',suspend),game.events?.on?.('teleport',suspend),
    game.events?.on?.('network',event=>{if(event?.state!=='connected')suspend();})];
  return ()=>{suspend();for(const remove of off)remove?.();network.servantSnapshot=null;};
}
