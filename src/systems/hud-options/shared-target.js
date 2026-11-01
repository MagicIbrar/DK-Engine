export const SHARED_TARGET_SCRIPT='game2/ui_targetbuffwnd.txt';
export function installSharedTarget(game){
  const ui=game.uiwin;let opening=null,pending=null,selection=0,ownSelection=false,lastCancel=null;
  const net=()=>game.network,state=()=>net()?.active?net().self?.sharedTarget||{}:{};
  const current=()=>{
    const n=net(),o=state().offer,now=n?._serverClock?n._serverClock.time+performance.now()-n._serverClock.at:Date.now();
    return !game.player?.dead&&o?.expires>now?{...o,token:n.token}:null;
  };
  const same=o=>{const c=current();return c&&c.id===o?.id&&c.token===o.token;};
  const actor=id=>net()?.players?.get(id)||net()?.monsters?.get(id)||net()?.eventActor?.(id);
  game.events?.on?.('target',({actor:a}={})=>{
    if(ownSelection)return;selection++;
    const binding=state().active,id=a?.networkId||a?.id;
    if(binding&&id!==binding.targetId&&lastCancel!==binding.id){lastCancel=binding.id;void net().action('shareTarget',{operation:'cancel',id:binding.id}).then(result=>{if(!result&&lastCancel===binding.id)lastCancel=null;});}
  });
  ui.registerWindow('shared_target',{
    script:SHARED_TARGET_SCRIPT,remember:false,escClose:false,band:'hud',
    create:win=>win.control('btn_targetbuff').onClick(async()=>{
      const offer=win.data.offer,n=net(),selected=selection,target=offer&&actor(offer.targetId);
      if(!same(offer)||pending||!target||target.dead||target.disposed)return;
      pending=offer.id;
      try{
        const result=await n.action('shareTarget',{operation:'accept',id:offer.id});
        if(!result||n!==net()||n.token!==offer.token)return;
        if(selected!==selection){void n.action('shareTarget',{operation:'cancel',id:offer.id});return;}
        ownSelection=true;
        try{game.controller?.setTarget?.(target);}finally{ownSelection=false;}
        win.close('accepted');
      }finally{pending=null;}
    }),
    onOpen:(win,offer)=>{win.data.offer=offer;},
    update:win=>{if(!same(win.data.offer))win.close('server');},
  });
  return ()=>{
    const offer=current(),win=ui.window?.('shared_target');
    if(!offer){if(win?.isOpen)win.close('server');return;}
    if(win?.isOpen&&same(win.data.offer)||opening===offer.id)return;
    opening=offer.id;
    void ui.get('shared_target').then(w=>{if(same(offer))ui.openWindow(w,offer);})
      .catch(error=>game.chat?.system?.(error.message,'err')).finally(()=>{if(opening===offer.id)opening=null;});
  };
}
