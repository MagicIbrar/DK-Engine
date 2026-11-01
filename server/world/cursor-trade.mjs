// Cursor custody may change unoffered ownership while the trade window stays open.
// This is not permission to move an offered item or edit an already confirmed offer.
const fail=message=>{throw Object.assign(Error(message),{status:409});};
export function cursorTradeSaving(p){const m=p?._cursorTradeSave;return !!m&&m.token===p.token&&m.account===p.account&&m.characterId===p.characterId&&m.map===p.map&&m.instanceId===p.instanceId&&m.channel===p.channel&&!p.leaving&&!p.revoked&&!p.dead;}
export function guardCursorTrade(world,p,input,profile=p.profile){
 for(const [session,offer]of [
  [world.trades?.get(p.tradeId),t=>t.offers.get(p.id)],
  [world.charTrades?.get(p.charTradeId),t=>t.players[1]===p?t.payment:null],
 ]){
  if(!session)continue;
  if(session.committing||session.phase!=='open'||session.confirmed?.size||!session.players.includes(p))fail('Finish or cancel the trade confirmation before moving items.');
  const row=offer(session);if(!row)continue;
  if((profile.dil||0)<row.dil)fail('That DIL is reserved for the trade.');
  for(const offered of row.items){
   if(input.uid===offered.uid||input.targetUid===offered.uid)fail('Remove that item from the trade offer before moving it.');
   const owned=(profile.inventory||[]).filter(i=>i.uid===offered.uid);
   if(owned.length!==1||JSON.stringify(owned[0])!==row.fingerprints.get(offered.uid))fail('The trade item must remain unchanged in its inventory position.');
  }
 }
}
export async function cursorTradeTransaction(world,p,input,run){
 guardCursorTrade(world,p,input);
 const prior=p._cursorTradeSave;
 if(p.tradeId||p.charTradeId)p._cursorTradeSave={token:p.token,account:p.account,characterId:p.characterId,map:p.map,instanceId:p.instanceId,channel:p.channel};
 try{return await run();}finally{if(prior===undefined)delete p._cursorTradeSave;else p._cursorTradeSave=prior;}
}
