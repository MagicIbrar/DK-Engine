// Native quest_05458_title_vip + item10000009 + title_base26; current Global guide18 confirms this exchange.
// The client lacks this server reward block. Only the exact authored dialog/item route is recovered.
export function nativeTitleExchanges(quests, dialogs, game) {
  const q=quests?.quests?.[5458], tree=dialogs?.quests?.[5458], text=String(dialogs?.strings?.[5458]?.[10000]||'');
  const item=game?.items?.db?.def?.(10000009)||game?.items?.def?.(10000009);
  const file='share/quest/quest_05458_title_vip.csv';
  if(!q||q.kind!=='dialog'||q.rewards||q.dialog?.file!==file||tree?.file!==file||Number(q.giver?.npc)!==5686||Number(q.giver?.map)!==150||Number(q.turnIn?.npc)!==5686||Number(q.turnIn?.map)!==150||item?.name!=='VIP Title Ticket'||!text.includes('VIP Title Ticket')||!text.includes('Title : VIP')||!text.includes('Maximum HP+1000'))return quests;
  // A singular owned ticket is handed over; no extra level, Premium-active, or daily requirement is authored.
  const exchange={...q,kind:'exchange',require:{...(q.require||{}),items:[{item:10000009,count:1}],titleAbsent:26},rewards:{take:[{item:10000009,count:1}],title:26,titleName:'VIP'},recoveredFrom:file};
  return {...quests,quests:{...quests.quests,5458:exchange}};
}
