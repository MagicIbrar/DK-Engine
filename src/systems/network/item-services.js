/** Original service windows use this only online; canonical profile application belongs to NetworkClient. */
export async function submitItemService(game,craft,type,intent,refresh=()=>{}) {
  if(craft.busy)return false;
  craft.busy=true;refresh();
  try {
    if(!game.network?.action){game.network?.unavailable?.('Item services');return false;}
    return await game.network.action(type,intent);
  } finally {craft.busy=false;refresh();}
}

/** Wing windows (upgrade / appearance / restore / class exchange): the server spends the cost and rolls; the wing selection is rebound to the canonical item. */
export async function submitWingService(game,win,intent,button='btn_ok') {
  const st=win.data.st;
  const result=await submitItemService(game,st,'wing',intent,()=>{
    win.control(button)?.setEnabled?.(!st.busy);win.data.refresh?.();
  });
  if(!result)return false;
  if(st.wing?.uid)st.wing=(game.items?.bag?.list||[]).find(item=>item.uid===st.wing.uid)||null;
  win.data.refresh?.();return result;
}

/** Costume windows retain selections on rejection and rebind them after the canonical response. */
export async function submitCostumeService(game,win,intent) {
  const st=win.data.st;
  const result=await submitItemService(game,st,'costume',intent,()=>{
    win.control('btn_ok').setEnabled(!st.busy);win.data.refresh?.();
  });
  if(!result)return false;
  const all=[...(game.items?.bag?.list||[]),...(game.items?.costumeBag?.list||[])];
  for(const key of ['costume','pick'])if(st[key]?.uid)st[key]=all.find(item=>item.uid===st[key].uid)||null;
  win.data.refresh?.();return result;
}
