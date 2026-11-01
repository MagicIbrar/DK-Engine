// Shared-play Personal Shop windows (server/world/pcshop.mjs owns every rule and commit; nothing here changes the save).
//   personalshop  the seller's own shop: game2/auction/ui_auctionsellwnd_2.txt "Personal Shop" (100:34). The pan_lock_bg / btn_lock
//                 cover rows 5-9 until a Wealth Merchant's Stall expands the shop (that is ui_auctionincreasewnd_2.txt: the same
//                 window without the lock). Bag items are listed by drag & drop or right-click: Item QTY, then the original price
//                 entry game2/auction/ui_askpricewnd_2.txt (title 100:40 "Sale") and the price check ui_pricemsgwnd_2.txt (2001:163,
//                 180:44 "Is this the right amount?"); right-click a listing to remove it. Shop Name (110:10, 25 chars), Sale
//                 (110:12, dil 110:13), Open Shop / Close Shop / Withdraw (110:14 / 110:15 / 110:16); text_chat keeps the sales log
//                 (180:47 "%s item %u ea sold.\nSales amount: %s DIL").
//   pcshopview    the buyer's view of another player's shop: the same script with lbl_title_buy, the seller in lbl_pcname, the
//                 seller block hidden; click a listing to buy (Item QTY + the price check, then the server).
//   increasepcshop_caution  game2/msgbox/ui_increasepcshop.txt (100:20 "Wealthy Merchant's Stall") before a Stall is used.
// Every open shop shows its name above the seller (click it to browse). Rules / gaps: docs/PERSONAL-SHOP.md.
import {Container} from '../items/model.js';
import {gridItems} from '../items/ui/common.js';
import {buildTooltip} from '../items/tooltip.js';
import {askAmount} from '../items/ui/dialogs.js';
import {placeWithBag} from '../items/ui/craft.js';
import {strings,formatString} from '../../ui/uiwin/strings.js';
import {formatDil} from '../../ui/item-colors.js';

export const PCSHOP_SCRIPT='game2/auction/ui_auctionsellwnd_2.txt';
export const PCSHOP_PRICE_SCRIPT='game2/auction/ui_askpricewnd_2.txt';
export const PCSHOP_CHECK_SCRIPT='game2/auction/ui_pricemsgwnd_2.txt';
export const PCSHOP_CAUTION_SCRIPT='game2/msgbox/ui_increasepcshop.txt';
// ENGINE-CHOSEN: matches the host's close-range stall guard, not an authored Global distance.
export const PCSHOP_BROWSE_RANGE=3.2;
const COLS=10;
const text=async(cate,code,fallback='')=>String(await strings.resolve({group:'NORMAL',cate,code})||fallback).replace(/^\s*\[message\]\s*/i,'').replace(/\r/g,'');
/** Wealth Merchant's Stall (kind type 0 code 26 "Expand Shop"). */
export const isShopExpansion=def=>Number(def?.type)===0&&Number(def?.code)===26;

export function installSharedPersonalShop(game,network){
  const sys=game.items;if(!sys||!game.uiwin?.registerWindow)return;
  let own=null,view=null,busy=false,buying=false,disposed=false,viewing=null,signs=new Map(),raf=0,pendingSend=null,closingWindow=null,shopSittingPlayer=null,browseIntent=0;
  const log=[];
  const state=()=>network.pcShop||null;
  const send=async(operation,fields={})=>{
    if(busy||disposed)return null;busy=true;
    try{pendingSend=network.action('pcshop',{operation,...fields});const result=await pendingSend;return result?result.pcshopResult||{}:null;}
    finally{pendingSend=null;busy=false;renderOwn();renderView();}
  };
  const bagItem=uid=>sys.bag.list.find(i=>i.uid===uid)||null;
  const rowsOf=s=>Number(s?.rows)||5;
  function grid(win,items,rows){
    const g=win.control('itemlist'),bag=new Container(items,sys.db,{pages:1,cols:COLS,rows,name:'pcshop'});
    g.setItems(gridItems(sys,g,bag,0).items);
  }
  const priceTip=(it)=>{
    const el=buildTooltip(sys,it.data,{where:'pcshop'});
    if(el&&typeof document!=='undefined'&&it.data?.price){const line=document.createElement('div');line.className='pcshop-price';line.textContent=`${priceLabel} ${formatDil(it.data.price)} ${dilUnit}`;el.appendChild(line);}
    return el;
  };
  let priceLabel='Price per Unit',dilUnit='dil';
  void Promise.all([text(2009,91,priceLabel),text(110,13,dilUnit)]).then(([a,b])=>{priceLabel=a;dilUnit=b;});
  function lock(win,expanded){win.control('pan_lock_bg').setVisible(!expanded);win.control('btn_lock').setVisible(!expanded);}
  function renderOwn(){
    const s=state();if(!own?.isOpen)return;
    const items=(s?.listings||[]).map(l=>{const item=bagItem(l.uid);return item?{...structuredClone(item),count:l.count,price:l.price,page:0,x:l.x,y:l.y}:null;}).filter(Boolean);
    grid(own,items,rowsOf(s));lock(own,!!s?.expanded);
    own.control('lbl_pcname').setText(game.save?.name||'');
    const name=own.control('edt_storename');if(!name.focused&&!own.data.nameDirty)name.setValue?.(s?.name||'');name.setEnabled(!s?.open);
    own.control('lbl_income').setDil(Number(s?.income)||0);
    own.control('btn_open').setVisible(!s?.open);own.control('btn_close').setVisible(!!s?.open);
    own.control('btn_open').setEnabled(!busy);own.control('btn_close').setEnabled(!busy);own.control('btn_get').setEnabled(!busy&&(Number(s?.income)||0)>0);
  }
  function renderView(){
    if(!view?.isOpen||!viewing)return;
    grid(view,structuredClone(viewing.items||[]),rowsOf(viewing));lock(view,!!viewing.expanded);
    view.control('lbl_pcname').setText(viewing.sellerName||'');view.control('edt_storename').setValue?.(viewing.name||'');
  }
  function sellerControls(win,seller){
    for(const id of ['lbl_title_buy'])win.control(id).setVisible(true);
    for(const id of ['lbl_tagMoney','pan_imcome_bg','lbl_income','lbl_tagUnit','btn_open','btn_close','btn_get'])win.control(id).setVisible(seller);
    win.control('edt_storename').setEnabled(seller);
  }
  // ---------------------------------------------------------------- registration
  async function priceDialog(item,count){
    const win=await game.uiwin.create(PCSHOP_PRICE_SCRIPT,{modal:true,escClose:true,remember:false,disposeOnClose:true});
    win.control('lbl_count').setText(String(count));
    // The tax row and "Show Seller Info" (2010:84) belong to Consignment; the personal shop charges no fee (docs/PERSONAL-SHOP.md).
    for(const id of ['lbl_tax_desc','lbl_tax','lbl_tax_value','lbl_seller_desc','checkbox'])win.control(id).hide();
    const edit=win.control('edit_text'),unit=()=>Math.floor(Number(String(edit.getValue?.()||'').replace(/[^0-9]/g,''))||0);
    const total=()=>win.control('lbl_price').setText(formatDil(unit()*count));total();edit.on?.('change',total);
    return new Promise(resolve=>{
      let done=false;const finish=v=>{if(done)return;done=true;resolve(v);win.close('done');};
      win.control('btn_confirm').onClick(()=>finish(unit()||null));edit.on?.('enter',()=>finish(unit()||null));
      win.control('btn_cancel').onClick(()=>finish(null));
      win.once?.('close',()=>{if(!done){done=true;resolve(null);}});
      game.uiwin.openWindow(win);setTimeout(()=>edit.focus?.(),0);
    });
  }
  async function priceCheck(item,count,unit){
    const preference=game.options?.get?.('priceMsg');
    if(preference === false || (preference == null && game.settings?.pcShopSkipPriceCheck))return true;
    const def=sys.db.def(item.itemIndex),title=await text(2001,163,'Personal Store Price Check');
    // The original 30px message slot has a 25px line pitch for one line.
    // Fit our two purchase-summary lines inside it, above the authored question.
    const fit=w=>{
      if(w.key!==PCSHOP_CHECK_SCRIPT&&w.key!=='script/ui/'+PCSHOP_CHECK_SCRIPT)return;
      const body=w.control('lbl_msg');
      if(body.spec)body.spec.props={...(body.spec.props||{}),lineheight:['14']};
      body.setClip?.(true);
    };
    game.uiwin.on?.('create',fit);
    try{
      const answer=await game.uiwin.msgbox(`${def?.name||''} x ${count}\n${formatDil(unit*count)} ${dilUnit}`,{script:PCSHOP_CHECK_SCRIPT,kind:'yesno',title});
      return answer==='yes';
    }finally{game.uiwin.off?.('create',fit);}
  }
  async function register(item,count=null){
    const s=state();
    if(s?.open){game.chat?.system?.(await text(180,34),'err');return false;}
    if(!item)return false;
    const n=count??((item.count||1)>1?await askAmount(sys,await text(2009,95,'Item QTY'),item.count||1):1);if(!n)return false;
    const unit=await priceDialog(item,n);if(!unit)return false;
    if(!await priceCheck(item,n,unit))return false;
    return !!await send('register',{uid:item.uid,count:n,price:unit});
  }
  async function openShop(){
    if(game.uiwin?.dnd?.cur){game.chat?.system?.(await text(180,10),'err');return;}
    const value=String(own?.control('edt_storename')?.getValue?.()||'').trim();
    if(own)own.data.nameDirty=false;
    const result=await send('open',value?{name:value}:{});if(result)game.chat?.system?.(await text(180,2),'sys');
  }
  function beforeOwnClose(win,result){
    if(disposed||result==='shop-confirmed'||!state()?.open&&!busy)return true;
    if(!closingWindow){
      closingWindow=(async()=>{
        // Escape/window-toggle can arrive while Open Shop is awaiting the host.
        // Wait for that intent; otherwise send() would discard this close as busy.
        if(pendingSend)await pendingSend.catch(()=>null);
        if(disposed)return;
        if(state()?.open){
          const reply=await send('close');
          if(!reply||state()?.open){game.chat?.system?.('The shop could not be closed. Keep this window open and try Close Shop again.','err');return;}
        }
        win.close('shop-confirmed');
      })().catch(error=>game.chat?.system?.(error?.message||'The shop could not be closed. Try Close Shop again.','err')).finally(()=>{closingWindow=null;});
    }
    return false;
  }
  // ---------------------------------------------------------------- buying
  async function browse(sellerId,{valid=()=>true}={}){
    if(!valid())return false;
    const result=await send('view',{sellerId});if(!result?.shop||!valid())return false;
    const received=result.shop;viewing=received;if(!view?.isOpen)await game.uiwin.open('pcshopview');
    if(!valid()){if(viewing===received){view?.close('cancelled');viewing=null;}return false;}
    renderView();return true;
  }
  function requestBrowse(actor){
    const id=actor?.networkId,controller=game.controller,player=game.player,self=network.self,shop=shops.get(id);
    if(!id||id===self?.id||!shop||network.players?.get?.(id)!==actor||disposed||!network.active||!network.ready||!controller||!player||actor.disposed||actor.dead||!(actor.hp>0)||player.dead||!(player.hp>0)||state()?.open||game.uiwin?.dnd?.cur||game.windows?.capturesInput)return false;
    controller.stop();controller.setTarget(actor);controller._holdMove=false;
    const intent=++browseIntent,input=controller._inputIntentRevision,token=network.token;
    const scene={id:self.id,map:self.map,instance:self.instanceId,channel:self.channel};
    const valid=()=>!disposed&&!network.disposed&&network.active&&network.ready&&token===network.token&&intent===browseIntent&&input===controller._inputIntentRevision&&game.player===player&&!player.dead&&player.hp>0&&!actor.disposed&&!actor.dead&&actor.hp>0&&network.players?.get?.(id)===actor&&shops.get(id)?.revision===shop.revision&&shops.has(id)&&network.self?.id===scene.id&&network.self?.map===scene.map&&network.self?.instanceId===scene.instance&&network.self?.channel===scene.channel&&!state()?.open&&!game.windows?.capturesInput&&!game.uiwin?.dnd?.cur&&(!controller.order||(controller.order.type==='approach'&&controller.order.valid===valid));
    const inRange=()=>Math.hypot(network.self.x-actor.x,network.self.z-actor.z)<=PCSHOP_BROWSE_RANGE;
    const arrive=()=>{
      if(!valid())return;
      void (async()=>{
        const open=async()=>{if(pendingSend)await pendingSend.catch(()=>null);return valid()&&inRange()?browse(id,{valid}):false;};
        if(network.settleMovement)await network.settleMovement(open);else await open();
      })().catch(error=>game.chat?.system?.(error?.message||'The shop could not be opened.','err'));
    };
    if(inRange()&&Math.hypot(player.x-actor.x,player.z-actor.z)<=PCSHOP_BROWSE_RANGE)arrive();
    else controller.approach(actor,PCSHOP_BROWSE_RANGE-1,arrive,{valid,authoritativeRange:PCSHOP_BROWSE_RANGE});
    return true;
  }
  async function buy(item){
    if(buying||disposed||!view?.isOpen||!viewing||!item)return false;
    const seen={sellerId:viewing.sellerId,revision:viewing.revision,uid:item.uid,price:item.price};
    const current=()=>!disposed&&view?.isOpen&&viewing?.sellerId===seen.sellerId&&viewing?.revision===seen.revision;
    buying=true;
    try{
      const n=(item.count||1)>1?await askAmount(sys,await text(2009,95,'Item QTY'),item.count||1):1;
      if(!n||!current()||!await priceCheck(item,n,item.price)||!current())return false;
      const result=await send('buy',{...seen,count:n});
      if(current()){
        if(result?.shop){viewing=result.shop;renderView();}
        else await browse(seen.sellerId);
      }
      return !!result;
    }finally{buying=false;}
  }
  // ---------------------------------------------------------------- expansion
  async function expand(item){
    if(state()?.expanded){game.chat?.system?.('Your Personal Shop is already expanded.','err');return false;}
    if(!await caution())return false;
    return !!await send('expand',{uid:item.uid});
  }
  // The caution box keeps its script title (100:20) and buttons. 170:16 / 170:17 (lbl_static1 / lbl_caution1) are in no string
  // table, so the 5-line 170:18 text takes their space (label made multiline). ENGINE-CHOSEN (not in Global data): the script rect is center-relative
  // (-160 -78), so the box is centered; "Remaining uses" = 1 (one Stall turns 50 slots into the window's 100).
  async function caution(){
    const win=await game.uiwin.create(PCSHOP_CAUTION_SCRIPT,{name:'increasepcshop_caution',modal:true,escClose:true,remember:false,disposeOnClose:true});
    win.center?.();
    const body=String(await strings.resolve({group:'NORMAL',cate:170,code:18})||'').replace(/<VALUE>/g,'1');
    const label=win.control('lbl_caution2');label.setRect?.(10,26,300,100);if(label.spec)label.spec.props={...(label.spec.props||{}),multiline:['true']};if(label.setRichText)label.setRichText(body);else label.setText(body.replace(/<[^>]+>/g,''));
    for(const id of ['lbl_static1','lbl_caution1'])win.control(id).hide();
    return new Promise(resolve=>{
      let done=false;const finish=v=>{if(done)return;done=true;resolve(v);win.close('done');};
      win.control('btn_yes').onClick(()=>finish(true));win.control('btn_no').onClick(()=>finish(false));win.control('btn_exit').onClick(()=>finish(false));
      win.once?.('close',()=>{if(!done){done=true;resolve(false);}});
      game.uiwin.openWindow(win);win.center?.();
    });
  }
  const stall=()=>sys.bag.list.find(i=>isShopExpansion(sys.db.def(i.itemIndex)))||null;
  // ---------------------------------------------------------------- windows
  game.uiwin.registerWindow('personalshop',{
    script:PCSHOP_SCRIPT,autoClose:false,   // btn_close is 'Close Shop' (110:15) here, not a window close
    beforeClose:beforeOwnClose,
    create(w){
      own=w;w.data.nameDirty=false;sellerControls(w,true);
      const g=w.control('itemlist');g._itemsRefresh=renderOwn;g.setItemTooltip(priceTip);
      g.acceptDrop({referenceSource:'bag',referenceLabel:'Your player shop',accept:d=>d?.kind==='item'&&d.from==='bag'&&!state()?.open,drop:d=>register(d.inst)});
      const remove=it=>{if(it&&!state()?.open)void send('withdraw',{uid:it.data.uid});};
      g.on('cellrclick',(cell,it)=>remove(it));g.on('celldbl',(cell,it)=>remove(it));
      w.control('edt_storename').on?.('change',()=>{w.data.nameDirty=true;});
      w.control('btn_open').onClick(()=>{void openShop();});
      w.control('btn_close').onClick(()=>{void send('close');});
      w.control('btn_get').onClick(()=>{void send('collect');});
      w.control('btn_exit').onClick(()=>w.close('user'));
      w.control('btn_lock').onClick(()=>{const item=stall();if(item)void expand(item);});
      // "Sales Record" writes Data/ChatLog in the original (230:65); a browser client has no such folder (documented gap).
      w.control('btn_save').setEnabled(false);
      const chat=w.control('text_chat');chat.clear?.();for(const line of log)chat.addLine?.(line);
    },
    onOpen(w){renderOwn();void placeWithBag(sys,w);void send('state');},
  });
  game.uiwin.registerWindow('pcshopview',{
    script:PCSHOP_SCRIPT,autoClose:false,   // btn_close is 'Close Shop' (110:15) here, not a window close
    create(w){
      view=w;sellerControls(w,false);w.control('btn_save').hide();w.control('btn_lock').setEnabled(false);
      const g=w.control('itemlist');g._itemsRefresh=renderView;g.setItemTooltip(priceTip);
      for(const event of ['cellclick','cellrclick','celldbl'])g.on(event,(cell,it)=>{if(it)void buy(it.data);});
      w.control('btn_exit').onClick(()=>w.close('user'));
    },
    onOpen(){renderView();void placeWithBag(sys,view);},
    onClose(){viewing=null;},
  });
  // right-click a bag item while the own shop window is open lists it (an open shop answers 180:34)
  const rightClick=sys.rightClick.bind(sys);
  sys.rightClick=(item,where='bag')=>where==='bag'&&own?.isOpen?register(item):rightClick(item,where);
  const use=sys.use.bind(sys);
  const useStall=ref=>{const item=typeof ref==='object'?ref:sys.bag.list.find(i=>i.uid===ref);return item&&isShopExpansion(sys.db.def(item.itemIndex))?expand(item):use(ref);};
  sys.use=useStall;sys.useRef=useStall;if(sys.uses)sys.uses.use=useStall;
  // ---------------------------------------------------------------- shop signs over sellers
  function paintSigns(){
    raf=0;if(disposed)return;
    const hud=game.hud,layer=hud?.els?.plates;if(!layer)return;
    const seen=new Set(),pt={x:0,y:0};
    for(const [id,shop] of shops){
      const actor=id===network.self?.id?game.player:network.players?.get?.(id);if(!actor)continue;
      const pos=hud._screen?.(actor,pt);if(!pos)continue;seen.add(id);
      let sign=signs.get(id);
      if(!sign){sign=document.createElement('div');sign.className='dk-plate pcshop-sign';sign.style.cssText='position:absolute;left:0;top:0;pointer-events:auto;cursor:pointer;color:#ffe08a;white-space:nowrap';
        sign.addEventListener('click',e=>{e.stopPropagation();if(id===network.self?.id)void game.uiwin.open('personalshop');else requestBrowse(network.players?.get?.(id));});layer.appendChild(sign);signs.set(id,sign);}
      if(sign.textContent!==shop.name)sign.textContent=shop.name;
      const plate=hud._plates?.get?.(actor),box=plate&&!plate.hidden?plate.el?.getBoundingClientRect?.():null;
      const bottom=box?.height>0?Math.min(pos.y-34,box.top-3):pos.y-34;
      sign.style.transform=`translate(${pos.x.toFixed(1)}px, ${bottom.toFixed(1)}px) translate(-50%, -100%)`;sign.style.display='';
    }
    for(const [id,sign] of signs)if(!seen.has(id)){if(!shops.has(id)){sign.remove();signs.delete(id);}else sign.style.display='none';}
    if(shops.size&&typeof requestAnimationFrame==='function')raf=requestAnimationFrame(paintSigns);
  }
  const shops=new Map();
  function syncSellerPose(){
    const player=game.player,emotes=game.life?.emotes;
    if(state()?.open&&player){
      // The local emote echo is deliberately skipped by ClientWorld. A server
      // service opening the shop still needs the owner's native sit clips.
      // An earlier own sit is adopted: the host's closeShop stands the seller however the sit began.
      if(emotes?.sit?.({server:true})){shopSittingPlayer=player;if(emotes.cur?.kind==='sit')emotes.cur.server=true;}
    }else if(shopSittingPlayer){
      if(player===shopSittingPlayer&&emotes?.cur?.kind==='sit'&&emotes.cur.server)emotes.stand?.({server:true});
      shopSittingPlayer=null;
    }
  }
  const updateSigns=rows=>{
    shops.clear();for(const row of rows||[])if(row?.pcShop?.name)shops.set(row.id,row.pcShop);
    if(!raf&&typeof requestAnimationFrame==='function')raf=requestAnimationFrame(paintSigns);
  };
  const snapshot=network._snapshot.bind(network);
  network._snapshot=record=>{
    if(network.disposed||Number(record?.sequence)<network.sequence)return;snapshot(record);
    if(record?.self&&Object.hasOwn(record.self,'pcShopState'))network.pcShop=record.self.pcShopState||null;
    syncSellerPose();
    if(record?.players){updateSigns([...(record.players||[]),...(record.self?.pcShop?[record.self]:[])]);if(viewing&&!shops.has(viewing.sellerId)){view?.close('server');viewing=null;}}
    renderOwn();
  };
  const event=network._event.bind(network);
  network._event=record=>{
    if(record?.type!=='pcshop'){event(record);return;}
    void (async()=>{
      if(record.reason==='sold'&&record.sellerId===network.self?.id){
        const line=formatString(await text(180,47),record.itemName||'',record.count,formatDil(record.total));
        log.push(line);if(log.length>200)log.shift();own?.control?.('text_chat')?.addLine?.(line);
        game.chat?.system?.(formatString(await text(180,37),record.itemName||''),'sys');
      }
      if(viewing&&record.sellerId===viewing.sellerId){
        if(record.reason==='closed'){view?.close('server');viewing=null;game.chat?.system?.(await text(180,15),'sys');}
        else if(record.reason==='updated'&&record.revision!==viewing.revision)await browse(viewing.sellerId);
      }
    })();
  };
  game.personalShop={register,browse,requestBrowse,buy,expand,open:openShop,close:()=>send('close'),collect:()=>send('collect'),state,viewOpen:()=>!!view?.isOpen,log:()=>[...log],signs:()=>new Map(signs)};
  const dispose=network.dispose.bind(network);
  network.dispose=()=>{disposed=true;if(raf&&typeof cancelAnimationFrame==='function')cancelAnimationFrame(raf);for(const sign of signs.values())sign.remove();signs.clear();own?.close?.('server');view?.close?.('server');dispose();};
}
