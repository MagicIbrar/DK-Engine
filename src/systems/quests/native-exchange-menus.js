// Native quest204 confirmation pages. Counts/output identities are printed in
// Global's journal and matched to item/box contents.
export const ARGATE_ROUTES=Object.freeze({10001:10010,10002:10100,10011:20000,10012:20010,10013:20100,10014:21000,10015:22000,10016:23000,10101:30000,10102:30010,10103:30100,10104:31000});
export const ARGATE_RECIPES=Object.freeze({
 20001:{take:4000515,need:2,give:4000516,count:1,message:200},
 20011:{take:4000515,need:4,give:4000517,count:1,message:300},
 20101:{take:4000515,need:8,give:4000518,count:1,message:400},
 21001:{take:4000515,need:16,give:4000519,count:1,message:500},
 22001:{take:4000515,need:300,give:1756352,count:1,message:600},
 23001:{take:4000515,need:300,give:1756353,count:1,message:700},
 30001:{take:4000516,need:1,give:4000515,count:1,message:800},
 30011:{take:4000517,need:1,give:4000515,count:2,message:900},
 30101:{take:4000518,need:1,give:4000515,count:4,message:1000},
 31001:{take:4000519,need:1,give:4000515,count:8,message:1100},
});
export const OBLIVION_GROUPS=Object.freeze({
 21001:{quests:[5007,5008,5009],items:[7521,1755140]},
 22001:{quests:[5004,5005,5006],items:[7522,1755141]},
 23001:{quests:[1400,1401,1402],items:[7523,1755142]},
});
export function nativeExchangeMenu(db,id){
 const q=db.quest(id),file=q?.dialog?.file;
 if(id===204&&file==='share/quest/quest_00204_corriders_agate_swap.csv'&&db.str(id,10011,{common:false})?.includes('Argate II'))return 'argate';
 if(id===1645&&file==='share/quest/quest_01645_reset_frontierquest.csv'&&db.str(id,10000,{common:false})?.includes('Letter of Oblivion'))return 'oblivion';
 return null;
}
export function nativeExchangePage(db,id,option){
 const kind=nativeExchangeMenu(db,id);
 if(kind==='argate')return ARGATE_ROUTES[option]??null;
 if(kind==='oblivion')return {10001:21000,10002:22000,10003:23000}[option]??null;
 return undefined;
}
export function questInventoryTransfer(inv,{take=[],give=[],takeDil=0,giveDil=0}={}){
 // Both production adapters expose their owned bag. Keep exact instances and
 // rollback all removals/additions on a placement failure; outer host commit
 // additionally protects against storage failures and concurrent progress.
 const list=inv.bag?.list||inv.items?.bag?.list||inv.game?.save?.inventory;
 const before=list?.map(entry=>({entry,value:structuredClone(entry)})),dil=inv.dil;
 const restore=()=>{if(before){for(const{entry,value}of before){for(const key of Object.keys(entry))delete entry[key];Object.assign(entry,value);}list.splice(0,list.length,...before.map(x=>x.entry));}if(inv.dil!==dil)inv.addDil(dil-inv.dil);};
 if(takeDil>inv.dil)return false;
 for(const t of take){const ids=Array.isArray(t.item)?t.item:[t.item];if(ids.reduce((n,id)=>n+inv.count(id),0)<t.count)return false;}
 try{
  for(const t of take){let left=t.count;for(const id of Array.isArray(t.item)?t.item:[t.item]){const n=Math.min(left,inv.count(id));if(n&&!inv.remove(id,n))throw Error('take failed');left-=n;}if(left)throw Error('take incomplete');}
  if(!inv.canFit(give.map(item=>({...item,reason:'questReward'}))))throw Error('no room');
  for(const item of give)if(!inv.add(item.item,item.count,{reason:'questReward',period:item.period,sockets:item.sockets}))throw Error('placement failed');
  if(takeDil||giveDil)inv.addDil(giveDil-takeDil);
  return true;
 }catch{restore();return false;}
}
