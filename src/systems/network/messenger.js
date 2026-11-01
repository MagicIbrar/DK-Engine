// MESSENGER-CHAT: the Messenger's 1:1 chat windows and the unread notifier under the clock in shared play.
//   messenger_chat  game2/messenger/ui_chatwnd.txt (328x211): lbl_userName = the partner, textview = the conversation,
//                   edit_text (maxlength 60) + Enter sends, btn_save "Save" (1006:10) writes the conversation to a text file,
//                   btn_minimize hides it (the conversation stays), btn_exit closes it, btn_partyInvite "Invite to Party"
//                   (70:66, scripted hidden) shows only while the partner can be invited. One window per partner.
//   msn_notify      game2/messenger/ui_msnnotifywnd.txt (8 41): btn_memo "<VALUE> Notes" (1006:44) while mail is unread,
//                   btn_message "<VALUE> Messages" (1006:43) while 1:1 messages wait in a closed window; both are scripted
//                   hidden and appear only when something is unread. The window closes again when nothing is unread.
// The friend list (src/systems/life/friends.js) gets presence from the host's connected list (party snapshot), its
// "Talk" (1006:5) opens the chat window, "Decline messages" (1006:47) is sent to the host, and friends coming online or
// leaving print 1006:45 / 1006:41. server/world/messenger.mjs owns delivery; ENGINE-CHOSEN choices are listed in
// MESSENGER_CLIENT_CONFIG and docs/MESSENGER-CHAT.md.
import {str,strNow,msg} from '../life/common.js';
import {NATIVE_MESSENGER_COLOR} from '../hud-options/chat-native.js';

export const MSG_CHAT_SCRIPT='game2/messenger/ui_chatwnd.txt';
export const MSG_NOTIFY_SCRIPT='game2/messenger/ui_msnnotifywnd.txt';
export const MSG_MAX_TEXT=60;                      // ui_chatwnd.txt edit_text maxlength
/** Window/history/position policies are ENGINE-CHOSEN; text color is authored. */
export const MESSENGER_CLIENT_CONFIG=Object.freeze({
  maxWindows:5,             // at most five chat windows at once; a sixth minimizes the one opened first
  historyLines:200,         // each conversation keeps its last 200 lines for this session
  cascade:24,               // each new chat window opens 24 px right/down of the previous one (centered first)
  colorMine:NATIVE_MESSENGER_COLOR,
  colorPartner:NATIVE_MESSENGER_COLOR,
  colorSystem:NATIVE_MESSENGER_COLOR,
  // msn_notify: the scripted btn_message slot (0 20 = screen 8 61) lies on the HUD alarm row (y 60, Quest Alert 10 60). A lone
  // button takes the top slot (0 0 = 8 41); with both, btn_message sits right of btn_memo (89 0), so neither covers an alarm icon.
  notifySlots:{top:[0,0,87,19],beside:[89,0,87,19]},
});
const STRINGS=[[1006,[5,9,10,41,42,43,44,45,47,48]],[70,[66]]];
const key=n=>String(n||'').trim().toLowerCase();
export const withValue=(s,n)=>String(s||'').replace('<VALUE>',String(n));
export const chatLine=(name,text)=>`[${name}] : ${text}`;

export function installSharedMessenger(game,network){
  const ui=game.uiwin;if(!ui?.registerWindow)return null;
  const cfg=MESSENGER_CLIENT_CONFIG,t=(c,n,f='')=>strNow(game,c,n)||f;
  void Promise.all(STRINGS.flatMap(([c,codes])=>codes.map(n=>str(game,c,n).catch(()=>null))));
  const convs=new Map();
  let decline=false,sessionId=null,presence=null,known=new Map(),mailUnread=0,busy=false,opening=false,slots=0,openSeq=0;
  const connected=()=>network.party?.connected||[];
  const row=name=>{const k=key(name);return connected().find(c=>key(c.name)===k)||null;};
  const online=name=>!!row(name);
  const selfName=()=>network.self?.name||game.player?.name||'';
  const notConnected=name=>`[${name}] ${t(1006,48,'is not connected to the game, therefore cannot send the message.')}`;
  function conv(name){
    const k=key(name);let c=convs.get(k);
    if(!c){c={key:k,name:String(name).trim(),lines:[],unread:0,unreadAt:0,slot:slots++,win:null,openedAt:0};convs.set(k,c);}
    return c;
  }
  const winName=c=>`messenger_chat:${c.key}`;
  function push(c,text,color){
    c.lines.push({text,color});
    if(c.lines.length>cfg.historyLines){c.lines.splice(0,c.lines.length-cfg.historyLines);if(c.win?.isOpen)render(c);return;}
    if(c.win?.isOpen){const v=c.win.control('textview');v.addLine?.(text,color);v.scrollToEnd?.();}
  }
  function canInvite(c){
    const r=row(c.name),p=network.party;
    if(!r||r.inParty||key(r.name)===key(selfName()))return false;
    if(!p?.active)return true;
    return p.leaderId===network.self?.id&&(p.members?.length||0)<(p.maxMembers||0);
  }
  function refreshChat(c){
    const w=c.win;if(!w?.isOpen)return;
    w.control('lbl_userName').setText(c.name);
    const invite=canInvite(c),edit=w.control('edit_text'),b=w.control('btn_partyInvite');
    b.setVisible(invite);
    // the scripted button (255 186 55 19) lies over the right end of edit_text (20 188 287 14): while it shows, the edit
    // stops 3 px before it (ENGINE-CHOSEN), otherwise it keeps its scripted width
    const r=edit.spec?.rect||[20,188,287,14],bx=b.spec?.rect?.[0]??255,want=invite?Math.min(r[2],bx-3-r[0]):r[2];
    if(c.editW!==want){c.editW=want;edit.setRect?.(r[0],r[1],want,r[3]);}
  }
  function render(c){
    const w=c.win;if(!w)return;
    const v=w.control('textview');v.clear?.();for(const l of c.lines)v.addLine?.(l.text,l.color);v.scrollToEnd?.();
    refreshChat(c);
  }
  function saveLog(c){
    const text=c.lines.map(l=>l.text).join('\r\n');
    try{
      if(typeof document!=='undefined'&&typeof Blob!=='undefined'&&typeof URL!=='undefined'&&URL.createObjectURL){
        const a=document.createElement('a');a.href=URL.createObjectURL(new Blob([text],{type:'text/plain'}));
        a.download=`messenger-${c.name.replace(/[^\w.-]+/g,'_')}.txt`;document.body.appendChild(a);a.click();a.remove();
        setTimeout(()=>URL.revokeObjectURL(a.href),1000);
      }
    }catch{/* download is best effort */}
    return text;
  }
  async function send(c,text){
    text=String(text??'').replace(/[\x00-\x1f\x7f]/g,' ').trim().slice(0,MSG_MAX_TEXT);
    if(!text||busy)return null;
    busy=true;
    try{
      const r=await network.action('messenger',{operation:'send',targetName:c.name,text});
      const res=r?r.messengerResult||{}:null;if(!res)return null;
      if(res.sent)c.win?.control('edit_text').setValue?.('');
      else if(res.code==='1006:48')push(c,notConnected(res.targetName||c.name),cfg.colorSystem);
      else if(res.code==='1006:42')push(c,`[${res.targetName||c.name}] ${t(1006,42,'does not accept any requests.')}`,cfg.colorSystem);
      return res;
    }finally{busy=false;}
  }
  function createChat(w,c){
    c.win=w;
    w.control('btn_exit').onClick(()=>{c.lines=[];ui.close(w);});
    w.control('btn_minimize').onClick(()=>ui.close(w));
    w.control('btn_save').onClick(()=>saveLog(c));
    w.control('btn_partyInvite').onClick(()=>{void game.party?.inviteName?.(c.name);});
    w.control('lbl_type').setText?.('');
    const edit=w.control('edit_text');
    edit.on?.('enter',v=>{void send(c,v??edit.getValue?.());});
  }
  async function openChat(name){
    name=String(name||'').trim();if(!name)return null;
    const c=conv(name);
    if(!c.win?.isOpen){
      const open=[...convs.values()].filter(x=>x.win?.isOpen).sort((a,b)=>a.openedAt-b.openedAt);
      while(open.length>=cfg.maxWindows)ui.close(open.shift().win);
    }
    const n=winName(c);
    if(!ui.has?.(n)){
      const scr=ui.screen||{w:1024,h:768},step=(c.slot%cfg.maxWindows)*cfg.cascade;
      ui.registerWindow(n,{script:MSG_CHAT_SCRIPT,remember:false,pos:{x:Math.max(0,Math.round((scr.w-328)/2)+step),y:Math.max(0,Math.round((scr.h-211)/2)+step)},
        create:w=>createChat(w,c),onOpen:w=>{c.win=w;render(c);}});
    }
    c.unread=0;c.openedAt=++openSeq;
    const w=await ui.open(n);c.win=w;
    w?.control('edit_text').focus?.();
    void syncNotify();
    return w;
  }
  function openNextUnread(){
    const c=[...convs.values()].filter(x=>x.unread>0).sort((a,b)=>a.unreadAt-b.unreadAt)[0];
    return c?openChat(c.name):null;
  }
  function receive(e){
    const mine=e.actorId===network.self?.id,partner=mine?e.targetName:e.name;if(!partner)return;
    const c=conv(partner);
    push(c,chatLine(e.name,e.text),mine?cfg.colorMine:cfg.colorPartner);
    if(!mine&&!c.win?.isOpen){if(!c.unread)c.unreadAt=++openSeq;c.unread++;void syncNotify();}
  }
  const unreadMessages=()=>[...convs.values()].reduce((n,c)=>n+c.unread,0);
  async function syncNotify(){
    const want=()=>unreadMessages()>0||mailUnread>0;
    if(want()&&!ui.isOpen('msn_notify')&&!opening){opening=true;try{await ui.open('msn_notify');}finally{opening=false;}}
    if(!want()&&ui.isOpen('msn_notify'))ui.close('msn_notify');
    const w=ui.window?.('msn_notify');if(!w?.isOpen)return;
    const msgs=unreadMessages(),memo=mailUnread;   // counted after the (async) open so a burst shows its final total
    w.control('btn_memo').setVisible(memo>0);w.control('lbl_memoNum').setText(withValue(t(1006,44,'<VALUE> Notes'),memo));
    w.control('btn_message').setVisible(msgs>0);w.control('lbl_msgNum').setText(withValue(t(1006,43,'<VALUE> Messages'),msgs));
    w.control('btn_message').setBlink?.(msgs>0);
    const slot=memo>0?cfg.notifySlots.beside:cfg.notifySlots.top,bm=w.control('btn_message');
    if(msgs>0&&bm._slot!==slot){bm._slot=slot;bm.setRect?.(...slot);}
  }
  async function setDecline(on){
    decline=!!on;
    const r=await network.action('messenger',{operation:'decline',on:decline});
    return r?r.messengerResult||{}:null;
  }
  function onParty(s){
    const names=new Set((s?.connected||[]).map(c=>key(c.name)));
    const friends=game.life?.friends,list=friends?.list?.()||[];
    // only friends already on the list at the previous snapshot are announced (a friend added while online is not "connecting")
    let changed=!presence;const next=new Map();
    for(const f of list){
      const k=key(f.name),now=names.has(k);next.set(k,now);
      if(known.has(k)&&known.get(k)!==now){changed=true;if(k!==key(selfName()))msg(game,`[${f.name}] ${now?t(1006,45,'has connected to the game.'):t(1006,41,'has exited the game.')}`,'sys');}
      else if(!known.has(k))changed=true;
    }
    presence=names;known=next;
    if(changed&&friends?.win?.isOpen)friends._refresh?.(friends.win);
    for(const c of convs.values())refreshChat(c);
    if(network.self?.id&&network.self.id!==sessionId){sessionId=network.self.id;if(decline)void setDecline(true);}
    const n=game.life?.mail?.unreadCount?.();
    if(Number.isFinite(n)&&n!==mailUnread){mailUnread=n;void syncNotify();}
  }
  // pinned to its scripted 8 41 (not rescaled with the screen) so it lines up with the fixed alarm row at y 60 (alarm-slots.js)
  ui.registerWindow('msn_notify',{script:MSG_NOTIFY_SCRIPT,hud:true,band:'hud',escClose:false,remember:false,pos:{x:8,y:41},
    create:w=>{w.control('btn_memo').onClick(()=>{void ui.open('mail');});w.control('btn_message').onClick(()=>{void openNextUnread();});}});
  game.events?.on?.('server:party',s=>onParty(s));
  game.events?.on?.('mail',m=>{mailUnread=Math.max(0,Number(m?.unread)||0);void syncNotify();});
  const event=network._event.bind(network);
  network._event=record=>{if(record?.type==='messenger')receive(record);else event(record);};
  const friends=game.life?.friends;
  if(friends){
    friends.online=online;
    friends.chat=name=>{if(!online(name)){msg(game,notConnected(name),'err');return null;}return openChat(name);};
    friends.partyInvite=name=>{if(!online(name)){msg(game,notConnected(name),'err');return null;}return game.party?.inviteName?.(name);};
    friends.onDecline=on=>setDecline(on);
  }
  const api={openChat,openNextUnread,send,receive,saveLog,setDecline,syncNotify,online,
    get conversations(){return convs;},get unread(){return unreadMessages();},get mailUnread(){return mailUnread;},get decline(){return decline;}};
  game.messenger=api;
  return api;
}
