/** Original inventory UI sends intents; only canonical snapshots mutate its arrays. */
import {sharedItemCooldown} from '../../ui/cooldown.js';
import {restoreCursor} from '../items/ui/common.js';
import {confirmItemUse} from '../items/use-confirm.js';
export function installSharedItems(game, network) {
  const sys=game.items;if(!sys)return;
  if(game.loot)game.loot.itemCooldown=index=>sharedItemCooldown(game,index).remaining;
  const emptyAccount={shared:[],sharedDil:0,sharedStash:false};
  sys.account=()=>game.save?.accountFeatures||emptyAccount;
  sys.saveAccount=()=>false;
  if(sys.shared)sys.shared.list=sys.account().shared||[];
  network.itemUseEvent=(event,actor)=>{
    const item={itemIndex:event.itemIndex},def=sys.db.def?.(event.itemIndex);if(!def||!actor)return;
    if(event.actorId===network.self?.id){game.events?.emit?.('itemuse',{item,def,actor,server:true,eventId:event.sequence});return;}
    // Remote recovery is cosmetic. Local item listeners also open services and count missions, so keep their scope local.
    const use=def.use||{},codes=[(use.hp||use.hpPct)&&21,(use.mp||use.mpPct)&&31];
    for(const code of codes){const row=game.effects?.data?.modelEffects?.game?.find(row=>Number(row.code?.[0])===code&&!Number(row.code?.[1])&&!Number(row.code?.[2]));if(row?.effect)game.effects.play(actor,row.effect,{loop:false});}
    game.events?.emit?.('server:itemuse',{item,def,actor,eventId:event.sequence});
  };
  const send=(type,payload)=>network.action(type,payload).then(result=>!!result);
  const cursor=(operation,payload={})=>send('cursor',{operation,revision:game.save.itemCursor?.revision||0,...payload});
  sys.cursorPickup=source=>cursor('pickup',{container:source.from,uid:source.uid,...(source.slot==null?{}:{slot:source.slot}),...(source.preset==null?{}:{preset:source.preset}),...(source.parentUid==null?{}:{parentUid:source.parentUid})});
  sys.cursorPlace=(container,point)=>cursor('place',{container,...point,uid:game.save.itemCursor?.item?.uid});
  sys.cursorCancel=()=>cursor('cancel',{uid:game.save.itemCursor?.item?.uid});
  sys.cursorDiscard=(uid,revision)=>cursor('discard',{uid,revision});
  const at=point=>point?{page:point.page,x:point.x,y:point.y}:{};
  const owned=()=>[...sys.bag.list,...(game.save?.potionBelt||[])];
  const resolve=ref=>{if(typeof ref==='number')return sys.bag.list[ref];const uid=typeof ref==='string'?ref:ref?.uid;if(uid){const found=owned().filter(i=>i.uid===uid);return found.length===1?found[0]:null;}return owned().filter(i=>i.itemIndex===Number(ref?.itemIndex)).sort((a,b)=>a.count-b.count)[0];};
  sys.beltDeposit=(item,slot)=>send('beltmove',{uid:item.uid,direction:'deposit',slot});
  sys.beltMove=(item,slot)=>send('beltmove',{uid:item.uid,direction:'move',slot});
  sys.beltWithdraw=(item,point)=>send('beltmove',{uid:item.uid,direction:'withdraw',...at(point)});
  const use=ref=>{const item=resolve(ref);if(!item)return Promise.resolve(false);const def=sys.db.def(item.itemIndex);if(Number(def?.type)===0&&[16,30].includes(Number(def.code))){const service=Number(def.code)===16?game.life?.guild:game.alliance;return Promise.resolve(service?.useGlory?.(item,def)??false);}if(def?.type===0&&[21,22].includes(def.code))return Promise.resolve(game.uiwin?.open('pet_awake',{ocarina:item})).then(()=>false);if(def?.type===0&&def.code===33)return send('petname',{reset:true,resetUid:item.uid}).then(ok=>{if(ok)void game.uiwin?.open('pet_name');return ok});if(def?.type===0&&[23,27,80].includes(def.code)&&game.nameChange)return Promise.resolve(game.nameChange.use(item,def)).then(()=>false);if(def?.type===0&&[38,39].includes(def.code)&&game.superchat)return Promise.resolve(game.superchat.use(item,def)).then(()=>false);if(game.boxes?.isBox?.(item.itemIndex))return game.boxes.open(item);return confirmItemUse(game,item,def).then(ok=>ok?send('itemuse',{uid:item.uid}):false);};   // Global cash item boxes first (items/use-confirm.js)
  sys.use=use;sys.useRef=use;if(sys.uses)sys.uses.use=use;
  sys.equipItem=(item,slot,preset)=>send(sys.costumeBag?.list?.some(i=>i.uid===item.uid)?'costume':'equip',{...(sys.costumeBag?.list?.some(i=>i.uid===item.uid)?{operation:'equip'}:{}),uid:item.uid,...(slot==null?{}:{slot}),...(preset==null?{}:{preset})});
  sys.unequip=(slot,preset,point)=>send('unequip',{slot,...(preset==null?{}:{preset}),...at(point)});
  sys.unequipTo=(target,slot,preset,point)=>target===sys.bag?sys.unequip(slot,preset,point):target===sys.costumeBag?send('costume',{operation:'unequip',slot,...(preset==null?{}:{preset}),...at(point)}):Promise.resolve(network.unavailable('This equipment destination'));
  sys.equipFromDrag=(drag,slot,preset)=>drag.from==='equip'?drag.preset===preset?(drag.slot===slot?Promise.resolve(true):send('equipswap',{slot:drag.slot,targetSlot:slot,preset})):Promise.resolve(network.unavailable('Equipment slot move between presets')):sys.equipItem(drag.inst,slot,preset);
  sys.clonePreset=(item,slot,preset,targets)=>send('clonepreset',{slot,preset,...(Array.isArray(targets)?{targets}:{})});
  sys.setPreset=preset=>send('preset',{preset});sys.swapWeaponTab=()=>send('weapontab',{});
  sys.receiveCash=(item,point)=>send('cashclaim',{uid:item.uid,...at(point)});
  sys.stashDeposit=(item,point)=>{
    const tab=sys.storageTab?.();
    if(tab===4)return send('storage',{uid:item.uid,direction:'deposit',shared:true,...at(point)});
    if(!point&&Number.isInteger(tab)&&sys.stash?.findSpot&&sys.stash?.size){const [w,h]=sys.stash.size(item);point=sys.stash.findSpot(w,h,{page:tab})||sys.stash.findSpot(w,h);if(!point)return Promise.resolve(false);}
    return send('storage',{uid:item.uid,direction:'deposit',...at(point)});
  };
  sys.stashWithdraw=(item,point)=>send('storage',{uid:item.uid,direction:'withdraw',...(sys.shared?.list?.some(i=>i.uid===item.uid)?{shared:true}:{}),...at(point)});
  sys.sharedBank=(direction,amount)=>send('bank',{direction,amount,shared:true});
  sys.bag.moveTo=(item,page,x,y)=>send('itemmove',{uid:item.uid,page,x,y});
  sys.bag.sort=page=>send('sortitems',{container:'bag',...(page==null?{}:{page})});
  if(sys.costumeBag)sys.costumeBag.moveTo=(item,page,x,y)=>send('costume',{operation:'move',uid:item.uid,page,x,y});
  if(sys.stash){sys.stash.sort=page=>send('sortitems',{container:'stash',...(page==null?{}:{page})});sys.stash.moveTo=(item,page,x,y)=>send('stashmove',{uid:item.uid,page,x,y});}
  if(sys.shared){sys.shared.moveTo=(item,page,x,y)=>send('stashmove',{uid:item.uid,page,x,y,shared:true});sys.shared.sort=page=>send('sortitems',{container:'shared',...(page==null?{}:{page})});}
  sys.transfer=(drag,target,page,x,y)=>target===sys.costumeBag?(drag.from==='bag'?send('costume',{operation:'deposit',uid:drag.uid||drag.inst?.uid,...at(page==null?null:{page,x,y})}):Promise.resolve(network.unavailable('This costume destination'))):drag.from==='costume'&&target===sys.bag?send('costume',{operation:'withdraw',uid:drag.uid||drag.inst?.uid,...at(page==null?null:{page,x,y})}):drag.from==='pet'?send('petinventory',{operation:'withdraw',uid:drag.petItem?.uid,...at(page==null?null:{page,x,y})}):drag.from==='cash'?sys.receiveCash(drag.inst,page==null?null:{page,x,y}):target===sys.bag?send('itemmove',{uid:drag.uid||drag.inst?.uid,page,x,y}):Promise.resolve(network.unavailable('This container transfer'));
  sys.receiveInBag=(drag,page,x,y)=>drag.from==='belt'?sys.beltWithdraw(drag.inst||drag.entry,{page,x,y}):drag.from==='equip'?sys.unequip(drag.slot,drag.preset,{page,x,y}):['stash','shared'].includes(drag.from)?sys.stashWithdraw(drag.inst,{page,x,y}):sys.transfer(drag,sys.bag,page,x,y);
  sys.rightClick=(item,where='bag')=>{
    if(where==='cash')return sys.receiveCash(item);
    if(['stash','shared'].includes(where))return sys.stashWithdraw(item);
    if(game.uiwin?.isOpen?.('storage'))return sys.stashDeposit(item);
    if(game.uiwin?.isOpen?.('shop'))return game.shops?.sell?.(item);
    return sys.db.def(item.itemIndex)?.slot?sys.equipItem(item):use(item);
  };
  let previous='';game.events?.on?.('server:profile',()=>{
    if(sys.shared)sys.shared.list=sys.account().shared||[];
    const signature=JSON.stringify([game.save.inventory,game.save.potionBelt,game.save.equip,game.save.costumeBag,game.save.cashInv,game.save.storage,game.save.accountFeatures,game.save.dkc,game.save.vipPoints,game.save.itemCursor]);
    if(signature===previous)return;previous=signature;
    // Equipment.data is a getter over game.save.equip. The canonical save was
    // already replaced by _profile; assigning the getter throws before visuals refresh.
    sys._recompute?.();sys.look?.apply?.();
    restoreCursor(sys);
    for(const name of ['inventory','cashinventory','equip','items'])game.events.emit(name,{reason:'server'});
  });
}
