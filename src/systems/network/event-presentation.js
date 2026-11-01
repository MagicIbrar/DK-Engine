// Display-only canonical event intents, shared by event and dungeon gauges.
// Server dialogs/rewards remain the sole authority for objective completion.
export function createEventPresentation(game,network,ui){
 let disposed=false,record=null,scopeKey=null;const seen=new Set();
 const scope=event=>{
  const world=game.world,id=event.instanceId,map=Number(event.map);
  const current=()=>!disposed&&!network.disposed&&!!id&&network.self?.instanceId===id&&Number(network.self?.map)===map&&game.world===world&&Number(world?.info?.index)===map;
  return current() ? current : null;
 };
 const first=key=>{if(seen.has(key))return false;seen.add(key);if(seen.size>256)seen.delete(seen.values().next().value);return true;};
 const now=()=>network.serverNow?.()??(network._serverClock?network._serverClock.time+performance.now()-network._serverClock.at:NaN);
 return {
  snapshot(value){record=value?.instance||null;const key=record?`${record.id}:${record.map}`:null;if(key!==scopeKey){scopeKey=key;seen.clear();ui.closeAll();}
   // A fresh event snapshot can retire a gauge whose terminal intent aged out
   // of the bounded event history. This closes a display, never an objective.
   const id=ui._channel?.server?.channelId;if(id&&Array.isArray(record?.channels)&&!record.channels.some(c=>c.channelId===id))ui.endServerChannel(id,false);
  },
  event(event){
   if(!['event:channel','event:channel-end','event:result'].includes(event.type))return false;
   const current=scope(event);if(!current)return true;
   if(event.type==='event:result'){
    if(event.cooperative!==true||typeof event.won!=='boolean'||![event.score,event.exp,event.rPoint].every(v=>Number.isFinite(v)&&v>=0)||!first(`result:${event.instanceId}`))return true;
    const warRows=event.war===true&&Array.isArray(event.teams)&&event.teams.length>1?event.teams.filter(t=>t&&Number.isFinite(t.point)&&Number.isFinite(t.exp)).map(t=>({rank:t.rank,party:`${t.party} party${t.rank===event.place?' (yours)':''}`,point:t.point,exp:t.exp})):null;
 void ui.result(warRows||[{rank:'',party:'Current cooperative party',point:event.score,exp:event.exp}],`${warRows?`Party war place ${event.place} of ${warRows.length}`:`Cooperative ${event.won?'objective complete':'run ended'}`} · ${event.rPoint} R-points`,{isCurrent:current});return true;
   }
   if(event.actorId!==network.self?.id||typeof event.channelId!=='string'||!event.channelId)return true;
   const key=`channel:${event.channelId}`;
   if(event.type==='event:channel-end'){first(key);ui.endServerChannel(event.channelId,event.completed===true);return true;}
   if(![event.startedAt,event.endAt,event.durationMs].every(Number.isFinite)||event.durationMs<=0||event.endAt<=event.startedAt||Math.abs(event.endAt-event.startedAt-event.durationMs)>1||!Number.isFinite(now())||now()>=event.endAt||!first(key))return true;
   const phase=event.phase??record?.phase;
   const valid=()=>current()&&record?.id===event.instanceId&&record.map===Number(event.map)&&(phase==null||record.phase===phase);
   // the run closed its dialog when the job started (offline DeadFrontRun._occupy / _slate: sys.dialog.close())
   game.sharedNpcDialog?.close?.();
   void ui.channel(event.text,event.durationMs,{server:{channelId:event.channelId,startedAt:event.startedAt,endAt:event.endAt,now,isCurrent:valid}});return true;
  },
  dispose(){disposed=true;seen.clear();ui.closeAll();}
 };
}
