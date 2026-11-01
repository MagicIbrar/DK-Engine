export const RESURRECTION_SCRIPT='game2/msgbox/ui_statusrevive.txt';
export function installResurrectionOffer(game){
  const ui=game.uiwin;let opening=null;
  const current=()=>{
    const net=game.network,offer=net?.self?.resurrection;
    const now=net?._serverClock?net._serverClock.time+performance.now()-net._serverClock.at:Date.now();
    return net?.active&&game.player?.dead&&offer?.expires>now?{...offer,token:net.token}:null;
  };
  const matches=offer=>{const live=current();return live&&offer?.id===live.id&&offer.token===live.token;};
  ui.registerWindow('resurrection_offer',{
    script:RESURRECTION_SCRIPT,remember:false,escClose:false,band:'modal',
    create(win){
      win.control('lbl_text').setVisible(false);
      const answer=async accept=>{
        const offer=win.data.offer;if(!matches(offer)||win.data.pending)return;
        win.data.pending=true;
        try{const result=await game.network.action('resurrection',{id:offer.id,accept});if(result&&matches(offer))win.close('answered');}
        finally{win.data.pending=false;}
      };
      win.control('btn_yes').onClick(()=>{void answer(true);});
      win.control('btn_no').onClick(()=>{void answer(false);});
    },
    onOpen:(win,offer)=>{win.data.offer=offer;win.data.pending=false;},
    update:win=>{if(!matches(win.data.offer))win.close('server');},
  });
  return function syncResurrectionOffer(){
    const offer=current(),win=ui.window?.('resurrection_offer');
    if(!offer){if(win?.isOpen)win.close('server');return;}
    if(win?.isOpen&&matches(win.data.offer)||opening===offer.id)return;
    opening=offer.id;
    void ui.get('resurrection_offer').then(w=>{if(matches(offer))ui.openWindow(w,offer);}).catch(error=>game.chat?.system?.(error.message,'err')).finally(()=>{if(opening===offer.id)opening=null;});
  };
}
