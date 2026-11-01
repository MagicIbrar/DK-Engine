/** Original registered pet windows submit intent; durable pending combinations resume after reconnect. */
export function installSharedPetServices(game,network){
  const api=game.mounts,sys=api?.system;if(!api||!sys)return;
  let busy=false,timer=null,pendingId=null,autoAttempted=null,disposed=false;
  const job=()=>game.save?.life?.petCombination;
  const now=()=>network._serverClock?network._serverClock.time+performance.now()-network._serverClock.at:Date.now();
  const refresh=()=>{for(const name of ['petinfo','pet_shapechange','pet_shaperestore','pet_disassemble']){const win=game.uiwin?.window?.(name);if(win?.isOpen)win.data.refresh?.();}};
  const send=async(type,fields)=>{
    if(busy||disposed)return false;busy=true;
    try{const result=await network.action(type,fields);if(result){refresh();return true;}return false;}finally{busy=false;}
  };
  const combine={start:uids=>send('petcombine',{operation:'start',uids}),finish:id=>send('petcombine',{operation:'finish',jobId:id||job()?.id}),cancel:id=>job()?send('petcombine',{operation:'cancel',jobId:id||job().id}):Promise.resolve(false)};
  api.petServices={combine,shape:(uid,shape)=>send('pettransform',{operation:'shape',uid,shape}),restore:uid=>send('pettransform',{operation:'restore',uid}),disassemble:uid=>send('pettransform',{operation:'disassemble',uid})};
  const clearMix=()=>{const win=game.uiwin?.window?.('petinfo');if(win?.data?.st){for(let i=1;i<=3;i++)win.control(`transition${i}_item`).data.slot?.clear(true);win.data.st.mix=[null,null,null];win.data.st.busy=false;win.data.refresh?.();}};
  const sync=()=>{
    const current=job();
    if(!current){clearTimeout(timer);timer=null;if(pendingId)clearMix();pendingId=null;autoAttempted=null;return;}
    const changed=pendingId!==current.id;pendingId=current.id;const win=game.uiwin?.window?.('petinfo');
    if(win?.data?.st&&changed){win.data.st.mix=current.uids.map(uid=>game.save.inventory?.find(item=>item.uid===uid)||null);win.data.st.busy=true;win.data.refresh?.();}
    const wait=Math.max(0,current.readyAt-now());
    if(!disposed&&!timer&&autoAttempted!==current.id)timer=setTimeout(()=>{timer=null;if(network.ready&&job()?.id===current.id){autoAttempted=current.id;void combine.finish(current.id);}},Math.min(2147483647,wait+30));
  };
  const bind=win=>{
    if(win.data._sharedPetServices)return;win.data._sharedPetServices=true;
    const click=(id,fn)=>{const c=win.control(id);c.off('click');c.onClick(fn);};
    if(win.name==='petinfo'){
      click('btn_mix',()=>{const pending=job();if(pending)void combine.finish(pending.id);else void combine.start(win.data.st.mix.map(item=>item?.uid));});
      for(const id of ['btn_default','btn_anneal','btn_setting'])win.control(id).onClick(()=>{if(job())void combine.cancel();});
    }else{
      click('btn_ok',async()=>{
        const st=win.data.st,uid=(st.pet||st.pick)?.uid;if(!uid)return;
        let result;
        if(win.name==='pet_shapechange'){
          if(!st.pick)return;if(await game.uiwin.msgbox(`${sys.data.name(st.pet.itemIndex)} → ${sys.data.name(st.pick)}`,{kind:'yesno',title:'Pet appearance'})!=='yes')return;
          result=await api.petServices.shape(uid,st.pick);
        }else if(win.name==='pet_shaperestore')result=await api.petServices.restore(uid);
        else{
          if(await game.uiwin.msgbox(win.control('lbl_warning').getText?.()||'Disassemble this pet?',{kind:'yesno',title:'Pet disassembly'})!=='yes')return;
          result=await api.petServices.disassemble(uid);
        }
        if(result){st.pet=null;st.pick=null;win.data.refresh?.();}
      });
    }
  };
  const opened=win=>{if(['petinfo','pet_shapechange','pet_shaperestore','pet_disassemble'].includes(win.name)){bind(win);if(win.name==='petinfo')sync();}};
  const closed=win=>{if(win.name==='petinfo'&&job())void combine.cancel();};
  game.uiwin?.on?.('open',opened);game.uiwin?.on?.('close',closed);
  for(const name of ['petinfo','pet_shapechange','pet_shaperestore','pet_disassemble']){const win=game.uiwin?.window?.(name);if(win)bind(win);}
  const off=game.events?.on?.('server:profile',sync);
  const dispose=network.dispose.bind(network);network.dispose=()=>{disposed=true;clearTimeout(timer);off?.();game.uiwin?.off?.('open',opened);game.uiwin?.off?.('close',closed);dispose();};
}
