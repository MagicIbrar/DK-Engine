import { declineBlockedInvitation } from '../hud-options/invitation-policy.js';
import {Container} from '../items/model.js';
import {gridItems} from '../items/ui/common.js';
import {buildTooltip} from '../items/tooltip.js';
import {askAmount,askSplit} from '../items/ui/dialogs.js';
import {placeWithBag} from '../items/ui/craft.js';
import {strings} from '../../ui/uiwin/strings.js';

/** The original two-sided trade window displays server offers; bag items remain owned until commit. */
export function installSharedTrade(game,network){
  const sys=game.items;if(!sys)return;
  let win,waiting=null,waitOpening=false,busy=false,opening=false,promptId=null,disposed=false;
  const state=()=>network.trade;
  const send=async(operation,extra={})=>{
    const s=state();if(busy||!s&&operation!=='request')return false;
    busy=true;try{return !!await network.action('trade',{operation,...(operation==='request'?{}:{id:s.id,...(operation==='cancel'?{}:{revision:s.revision})}),...extra});}finally{busy=false;render();}
  };
  const offer=(items,dil=state()?.self.dil||0)=>send('offer',{items,dil});
  const rows=()=>state()?.self.items.map(i=>({uid:i.uid,count:i.count||1}))||[];
  const editable=()=>state()?.phase==='open'&&!state()?.self.confirmed;
  const add=async(item,count=null)=>{
    if(!editable()||!item)return false;
    if(count==null)count=(item.count||1)>1?await askSplit(sys,item):1;
    if(!Number.isInteger(count)||count<1||count>(item.count||1)||!editable())return false;
    const next=rows(),existing=next.find(i=>i.uid===item.uid);if(existing)existing.count=count;else next.push({uid:item.uid,count});
    return offer(next);
  };
  const remove=item=>editable()?offer(rows().filter(i=>i.uid!==item.uid)):false;
  function reviewControls(){
    const s=state();if(!win?.isOpen||!s)return;
    const reviewing=s.phase==='review'||s.phase==='ready',duration=Number(s.reviewReadyAt)-Number(s.reviewStartedAt);
    const gauge=reviewing&&duration>0?Math.max(0,Math.min(1,(serverNow()-s.reviewStartedAt)/duration)):0;
    win.control('pan_progressBg').setVisible(reviewing);win.control('processbar').setGauge(gauge);
    // Both native buttons say "Confirm". Present one action at a time in the
    // same position; the server still requires both players at both stages.
    win.control('btn_ok').setVisible(s.phase==='open');
    win.control('btn_lastok').setVisible(reviewing);
    win.control('btn_ok').setEnabled(!busy&&s.phase==='open'&&!s.self.confirmed);
    // Clock extrapolation only displays progress. A canonical ready snapshot enables the final action.
    win.control('btn_lastok').setEnabled(!busy&&s.phase==='ready'&&gauge>=1&&!s.self.finalConfirmed);
  }
  function render(){
    const s=state();if(!win?.isOpen||!s)return;
    win.control('lbl_tradername').setText(s.partner.name);
    win.control('lbl_mymoney').setDil(s.self.dil);win.control('lbl_tradermoney').setDil(s.other.dil);
    win.control('btn_myConfirm').setChecked(s.self.confirmed);win.control('btn_confirm').setChecked(s.other.confirmed);
    for(const [key,row]of [['slotme',s.self],['slottrader',s.other]]){
      const grid=win.control(key),bag=new Container(row.items,sys.db,{pages:1,cols:10,rows:5});
      grid.setItems(gridItems(sys,grid,bag,0).items);
    }
    win.control('pan_my_bg_lock').setVisible(s.self.confirmed);win.control('pan_trader_bg_lock').setVisible(s.other.confirmed);
    reviewControls();
  }
  game.trade={request:targetId=>send('request',{targetId}),add,remove,offerDil:dil=>editable()?offer(rows(),dil):false,confirm:()=>send('confirm'),finalConfirm:()=>send('finalConfirm'),cancel:()=>send('cancel')};
  // The original "Wait to Trade" window (trade/ui_invitetrade.txt: title 100:41, text 110:18, Cancel 2000:14) is what the
  // requester sees until the invitee answers or the invitation expires (the server's expiresAt drives its gauge).
  const serverNow=()=>network._serverClock?network._serverClock.time+performance.now()-network._serverClock.at:Date.now();
  game.uiwin?.registerWindow?.('tradewait',{
    script:'game2/trade/ui_invitetrade.txt',
    create(w){waiting=w;w.control('btn_cancel').onClick(()=>{void send('cancel');});},
    onOpen(w){w.data.total=Math.max(1,(state()?.expiresAt||0)-serverNow());w.control('processbar').setGauge(0);},
    update(w){const s=state();if(s?.expiresAt)w.control('processbar').setGauge(Math.max(0,Math.min(1,1-(s.expiresAt-serverNow())/(w.data.total||1))));},
    onClose(){const s=state();if(s?.phase==='invited'&&!s.incoming)void send('cancel');},
  });
  game.uiwin?.registerWindow?.('sharedtrade',{
    script:'game2/trade/ui_tradewnd.txt',
    create(w){
      win=w;
      // This script's right inventory panel is absent in the supplied revision. Pair its original left panel with the existing inventory.
      w.spec={...w.spec,rect:[-166,-236,167,237],titlerect:[7,3,330,30]};w.place();
      for(const id of ['slotme','slottrader']){const grid=w.control(id);grid.setRect(7,id==='slotme'?248:49,320,160);grid._itemsRefresh=render;grid.setItemTooltip(it=>buildTooltip(sys,it.data,{where:'trade'}));}
      const mine=w.control('slotme');mine.on('cellrclick',async(cell,it)=>{
        if(!it||!editable())return;
        const offered=it.data,owned=sys.bag?.list?.find(row=>row.uid===offered.uid);
        if(!owned||(offered.count||1)<=1){void remove(offered);return;}
        const quantity=await askSplit(sys,owned);
        if(quantity&&editable()&&rows().some(row=>row.uid===offered.uid))void add(owned,quantity);
      });mine.on('celldbl',(cell,it)=>{if(it)void remove(it.data);});
      mine.acceptDrop({referenceSource:'bag',referenceLabel:'Trading',accept:d=>d?.kind==='item'&&d.from==='bag',drop:d=>add(d.inst,d.count||d.inst.count||1)});
      w.control('lbl_mymoney').onClick(async()=>{if(!editable())return;const n=await askAmount(sys,'Offer DIL',Number(game.save.dil)||0);if(n&&editable())await offer(rows(),n);});
      w.control('lbl_mymoney').on('rclick',()=>{if(editable())void offer(rows(),0);});
      w.control('btn_ok').onClick(()=>{if(state()?.phase==='open'&&!state().self.confirmed)void send('confirm');});
      w.control('btn_lastok').onClick(()=>{if(state()?.phase==='ready'&&!state().self.finalConfirmed)void send('finalConfirm');});
      w.control('btn_lastok').setRect(...(w.control('btn_ok').spec?.rect||[92,446,57,19]));
      w.control('btn_lastok').hide();
      w.control('btn_myConfirm').setEnabled(false);
      w.control('btn_confirm').setEnabled(false);
      for(const id of ['btn_cancel','btn_exit'])w.control(id).onClick(()=>{void send('cancel');});
      for(const id of ['lbl_itemmessage','lbl_moneymessage'])w.control(id).hide();
      // Preserve the original native labels/art: title110:7, first110:9 and final2000:22.
      w.control('slotme').setTooltip?.('Drop bag items here. Right-click a stack to choose its offer quantity; double-click to remove it.');
      w.control('lbl_mymoney').setTooltip?.('Click to offer DIL; right-click to clear the DIL offer.');
    },
    onOpen(){render();void placeWithBag(sys,win);},
    update(){reviewControls();},
    onClose(){if(state())void send('cancel');},
  });
  const rightClick=sys.rightClick.bind(sys);sys.rightClick=(item,where='bag')=>state()&&where==='bag'?(editable()?add(item):false):rightClick(item,where);
  const sync=async()=>{
    const s=state();
    if(!s){if(win?.isOpen)win.close('server');if(waiting?.isOpen)waiting.close('server');game.uiwin?.close?.('tradeinvitation','no');return;}
    if(s.phase==='invited'){
      if(s.incoming) {
        if(declineBlockedInvitation(game,'blockTrade',s.id,()=>send('cancel'))) { game.uiwin?.close?.('tradeinvitation','no'); return; }
        // the original invitation box (msgbox/ui_tradeinvitation.txt): "<name>" + 110:20 "likes to trade with you." + Accept / Decline
        if(promptId!==s.id){promptId=s.id;const id=s.id;
          const title=await strings.resolve({group:'NORMAL',cate:100,code:42});
          const answer=await game.uiwin?.msgbox?.(s.partner.name,{script:'game2/msgbox/ui_tradeinvitation.txt',name:'tradeinvitation',kind:'yesno',title:title||''});
          if(state()?.id===id)await send(answer==='yes'?'accept':'cancel');
        }
        return;
      }
      if(!waiting?.isOpen&&!waitOpening&&!disposed){waitOpening=true;try{await game.uiwin?.open?.('tradewait');}finally{waitOpening=false;}}
      return;
    }
    if(waiting?.isOpen)waiting.close('server');
    if(!win?.isOpen&&!opening&&!disposed){opening=true;try{await game.uiwin.open('sharedtrade');if(!state()||disposed)win?.close('server');}finally{opening=false;}}
    render();
  };
  const snapshot=network._snapshot.bind(network);network._snapshot=record=>{if(network.disposed||Number(record?.sequence)<network.sequence)return;snapshot(record);network.trade=record?.trade||null;void sync();};
  const event=network._event.bind(network);network._event=record=>{if(record.type==='trade'){if(['completed','cancelled','disconnected','expired or interrupted','interrupted by gameplay','save failed; review again'].includes(record.reason))game.chat?.system?.(`Trade ${record.reason}.`,record.reason.startsWith('save')?'err':'sys');}else event(record);};
  game.chat?.registerCommand?.('/trade',name=>{
    const target=[...network.players.values()].find(p=>p.name?.toLowerCase()===name.trim().toLowerCase());
    if(target)void game.trade.request(target.networkId||target.id);else game.chat.system('Choose a nearby connected character: /trade Name','err');return true;
  },'Trade with a nearby connected character.');
  const dispose=network.dispose.bind(network);network.dispose=()=>{disposed=true;network.trade=null;win?.close('server');waiting?.close('server');dispose();};
}
