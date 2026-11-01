import {str} from '../hud-options/util.js';
export const PARTY_OBSERVER_SCRIPT='game2/msgbox/ui_partypvppotal.txt';
const plain=s=>String(s||'').replace(/<[^>]*>/g,'').trim();
export function installPartyObserverWindow(game,network,{makeCamera=async()=>{const {FreeCam}=await import('../gm/worldtools.js');return game.gm?.freecam||new FreeCam(game);}}={}){
  const ui=game.uiwin,state=()=>network.partyPvp?.state()||{};
  let disposed=false,cam=null,cameraRequest=0,opened=null,cameraMap=null,cameraPending=0;
  const observing=()=>!disposed&&network.active&&state().observer;
  const camera=async on=>{
    const seq=++cameraRequest;
    if(!on)cameraPending=0;
    if(on&&!cam){
      cameraPending=seq;
      try{const created=await makeCamera();if(seq!==cameraRequest||!observing())return;cam=created;}
      finally{if(cameraPending===seq)cameraPending=0;}
    }
    if(!cam||seq!==cameraRequest)return;
    if(on){cam.speed=Number(state().observerSpeed)||5;cam._partyObserver=true;cam.set(true);cameraMap=network.self?.map;}
    else if(cam._partyObserver){cam.set(false);cam._partyObserver=false;cameraMap=null;}
  };
  const readyCamera=()=>{if(observing()&&!cameraPending&&Number(game.world?.info?.index)===Number(network.self?.map)&&cameraMap!==network.self?.map)void camera(true);};
  ui.registerWindow('partypvp_observer_confirm',{
    script:PARTY_OBSERVER_SCRIPT,remember:false,escClose:true,band:'modal',
    create:win=>{
      win.control('btn_yes').onClick(async()=>{
        const pending=win.data.match;
        if(!pending||pending.token!==network.token||disposed||win.data.pending)return;
        win.data.pending=true;
        try{if(await network.partyPvp.observe(pending.id))win.close('accepted');}
        finally{win.data.pending=false;}
      });
      for(const id of ['btn_no','btn_exit'])win.control(id).onClick(()=>win.close('cancel'));
    },
    onOpen:(win,match)=>{
      win.data.match={...match,token:network.token};win.data.pending=false;
      const parts=String(str(2100,14)||'%s\\nParty Match: Join as an observer.').split(/<center>|\n/).map(plain).filter(Boolean);
      win.control('multilbl_0').setText((parts.shift()||'%s').replace('%s',match.name));
      win.control('lbl_msg').setText(parts.join('\n'));
    },
    update:win=>{if(disposed||!network.active||win.data.match?.token!==network.token)win.close('server');},
  });
  ui.registerWindow('partypvp_observer_pop',{
    script:'game2/observer/ui_observer_popwnd.txt',remember:false,escClose:false,band:'hud',
    create:win=>{
      for(const id of ['guild','siege'])win.control(`pan_observerpop_${id}`).hide();
      win.control('btn_eye').onClick(()=>win.control('pan_observerpop_partypvp').setVisible(!win.control('pan_observerpop_partypvp').visible));
      win.control('btn_UI_partypvp').onClick(()=>{const w=ui.window('partypvp_time');if(w?.isOpen)w.close();else void ui.open('partypvp_time');});
      win.control('btn_exit_partypvp').onClick(()=>{void network.partyPvp.leaveObserver();});
    },
    update:win=>{if(!observing())win.close('server');else readyCamera();},
  });
  // ENGINE-CHOSEN entry affordance: the native portal confirmation is reachable
  // from a named match near its original entrance; no invented world model.
  game.chat?.registerCommand?.('/observeparty',name=>{
    const token=network.token;
    void network.partyPvp.list().then(result=>{
      if(disposed||token!==network.token||!result)return;
      const matches=result.matches||[],query=String(name||'').trim().toLowerCase();
      const match=matches.find(m=>m.name.toLowerCase()===query)||(!query&&matches.length===1?matches[0]:null);
      if(match)void ui.open('partypvp_observer_confirm',match);
      else game.chat?.system?.(matches.length?matches.map(m=>m.name).join(', '):'No Party Match is open here.','sys');
    });return true;
  },'Observe a Party Match near its entrance: /observeparty leader-name.');
  const off=game.events?.on?.('partypvp',()=>{
    if(observing()){if(opened!==state().id){opened=state().id;void ui.open('partypvp_observer_pop');}readyCamera();}
    else{opened=null;ui.close('partypvp_observer_pop');void camera(false);}
  });
  const offMap=game.events?.on?.('map',()=>{if(observing()){void camera(false);readyCamera();}});
  const offNet=game.events?.on?.('network',({state:s}={})=>{if(s!=='connected'){opened=null;ui.close('partypvp_observer_pop');ui.close('partypvp_observer_confirm');void camera(false);}});
  return ()=>{disposed=true;off?.();offNet?.();offMap?.();void camera(false);ui.close('partypvp_observer_pop');ui.close('partypvp_observer_confirm');};
}
