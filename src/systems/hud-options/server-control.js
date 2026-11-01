import { LocalAccounts } from '../../ui/frontend/accounts.js';
import { CREDENTIAL_KEY } from '../../ui/frontend/return.js';

const ROUTE='/api/world/server-control';
export class ServerControl {
  constructor(game,{request=(...args)=>globalThis.fetch(...args),clock=()=>performance.now(),setTimer=(fn,ms)=>globalThis.setInterval(fn,ms),clearTimer=id=>globalThis.clearInterval(id)}={}){
    this.game=game;this.request=request;this.clock=clock;this.clearTimer=clearTimer;
    this.state={state:'running',canStop:false};this.at=clock();this.pollPending=false;this.stopPending=false;this.requestVersion=0;this.finished=false;
    this._register();this.timer=setTimer(()=>{void this.poll();},500);
    this.off=game.events?.on?.('network',()=>{if(!game.network?.ready)this.state.canStop=false;});
  }
  get canStop(){return !!this.state.canStop&&!this.finished;}
  remainingMs(){return Math.max(0,(this.state.deadline||0)-(this.state.serverTime||0)-(this.clock()-this.at));}
  remaining(){return Math.ceil(this.remainingMs()/1000);}
  async _call(body){
    const controller=new AbortController(),timeout=globalThis.setTimeout(()=>controller.abort(),4000);
    try{const response=await this.request(ROUTE,{credentials:'same-origin',cache:'no-store',signal:controller.signal,...(body===undefined?{}:{method:'POST',headers:{'Content-Type':'application/json'},body:JSON.stringify(body)})});const data=await response.json();if(!response.ok)throw new Error(data.error||'Server controls are unavailable.');return data;}
    finally{globalThis.clearTimeout(timeout);}
  }
  async poll(){
    if(this.pollPending||this.stopPending||this.finished)return;
    if(!['countdown','saving'].includes(this.state.state)&&(!this.game._worldReady||!this.game.network?.ready))return;
    this.pollPending=true;const version=this.requestVersion;
    // A GET started before Stop must not replace the accepted countdown with its old status.
    try{const state=await this._call();if(!this.finished&&version===this.requestVersion)this.apply(state);}catch{if(!this.finished&&version===this.requestVersion)this.state.canStop=false;}finally{this.pollPending=false;}
  }
  async stop(){
    if(!this.canStop||this.stopPending||!['running','failed'].includes(this.state.state))return false;this.stopPending=true;this.requestVersion++;
    try{const state=await this._call({});if(this.finished)return false;this.apply(state);return true;}catch(error){if(!this.finished)this.game.chat?.system?.(error.message,'err');return false;}finally{this.stopPending=false;}
  }
  apply(state){
    if(this.finished||!state||!['running','countdown','saving','saved','failed'].includes(state.state))return;
    const previous=this.state.state;this.state=state;this.at=this.clock();
    if(state.state==='countdown'){
      this.prepared ||= this.game.uiwin.get('serverdisconnected').catch(()=>null);
      if(previous!=='countdown'){this.game.uiwin.close('gmserver');this.game.chat?.system?.('Server shutdown in 10 seconds. All progress will be saved.');void this.game.uiwin.open('servershutdownnotice');}
    }
    if(state.state==='saving'&&previous!=='saving'){this.wasPaused=this.game.paused;this.game.paused=true;}
    if(state.state==='failed'){
      if(previous==='saving')this.game.paused=!!this.wasPaused;
      this.game.uiwin.close('servershutdownnotice');
      if(previous!=='failed')this.game.chat?.system?.(state.error||'Save failed. The server remains running.','err');
    }
    if(state.state==='saved')void this.disconnect();
  }
  _register(){
    const ui=this.game.uiwin,self=this;
    const configure=(win,notice)=>{
      win.control('lbl_title').setText(notice?'Server shutdown':'GM Server');
      if(notice){win.control('btn_cancel').hide();win.control('processbar').setGauge(0);return;}
      win.control('lbl_already').hide();win.control('edit_time').hide();win.control('lbl_text_time').hide();win.control('btn_no').hide();
      win.control('lbl_text').setRect(12,45,208,108);
      const button=win.control('btn_yes');button.setRect(16,164,200,24).setText('Save & Stop Server');button.setVisible(!notice);
      if(!notice)button.onClick(()=>{void self.stop();});
    };
    const paint=(win,notice)=>{
      const phase=self.state.state;
      const text=phase==='countdown'?`Server stops in ${self.remaining()} seconds.\nAll players' progress will be saved.`:phase==='saving'?'Saving all players’ progress…\nPlease wait.':phase==='failed'?(self.state.error||'Save failed. The server remains running.'):'Save all players’ progress and stop this owned server after a 10-second countdown.';
      win.control('lbl_text').setText(text);
      if(notice)win.control('processbar').setGauge(phase==='countdown'?Math.min(1,1-self.remainingMs()/10000):1);
      else win.control('btn_yes').setEnabled(self.canStop&&['running','failed'].includes(phase)&&!self.stopPending);
    };
    ui.registerWindow('gmserver',{script:'game2/gmtool/ui_shutoffwnd.txt',band:'system',escClose:true,create:win=>configure(win,false),onOpen(win){if(!self.canStop)win.close();else paint(win,false);},update:win=>paint(win,false)});
    ui.registerWindow('servershutdownnotice',{script:'game2/systemwnd/ui_systemwaitwnd.txt',band:'system',modal:true,escClose:false,autoClose:false,create:win=>configure(win,true),onOpen:win=>paint(win,true),update:win=>paint(win,true)});
    ui.registerWindow('serverdisconnected',{script:'game2/ui_loginwnd.txt',band:'system',escClose:false,autoClose:false,create(win){
      for(const id of ['pan_selectgroup','pan_15','pan_18','btn_vk'])win.control(id).hide();
      win.control('pan_login').show();win.control('pan_message').show();
      win.control('lbl_message').setText('Server saved and stopped. Start it from the launcher, then reconnect.');
      win.control('edt_account').setValue('');win.control('edt_password').setValue('');
      win.control('btn_login').setText('Reconnect').onClick(async()=>{try{const response=await self.request('/api/server/info',{cache:'no-store'});if(!response.ok)throw new Error();const url=new URL(globalThis.location.href);url.searchParams.set('screen','login');url.searchParams.set('credentials','1');globalThis.location.replace(url.href);}catch{win.control('lbl_message').setText('The server is stopped. Start it from the launcher first.');}});
      win.control('btn_pantheon').hide();win.control('btn_quit').onClick(()=>win.control('lbl_message').setText('You are safely disconnected. You may close this client.'));
    }});
  }
  async disconnect(){
    if(this.finished)return;this.finished=true;this.clearTimer(this.timer);this.off?.();
    const g=this.game;g.paused=true;g.renderer?.setAnimationLoop?.(null);g.input&&(g.input.enabled=false);
    g.network?.dispose?.();g._launcherReadiness?.dispose?.();g.bloom?.dispose?.();g.audio?.dispose?.();g.hud?.dispose?.();
    g.uiwin.closeAll({includeHud:true});
    try{globalThis.sessionStorage?.setItem(CREDENTIAL_KEY,'1');}catch{}
    // Server persistence already succeeded; this is not the normal ESC save flow.
    void new LocalAccounts().logout().catch(()=>{});
    const win=await(this.prepared||g.uiwin.get('serverdisconnected').catch(()=>null));
    if(win)g.uiwin.openWindow(win);
    else {const message=document.createElement('div');message.className='panel deathbox';message.textContent='Server saved and stopped. You are safely disconnected.';g.ui.appendChild(message);}
  }
  dispose(){this.clearTimer(this.timer);this.off?.();this.finished=true;}
}
export function installServerControl(game){return game.save?.authority==='server'?(game.serverControl ||=new ServerControl(game)):null;}
