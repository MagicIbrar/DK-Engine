// Shared play: original NPC jobs 96 DK_CHANNEL_ENTER / 97 DK_CHANNEL_LEAVE (host: server/world/channels.mjs).
// A DK map with several dkmaplist locates (e.g. 183/533/700/705: 100 "1Server", 101 "2Server (PVP Channel)") opens the
// original DK server chooser game2/smartwarp/ui_serverselect.txt (title 30|94 "Channel", one btn_server per locate,
// labelled with the 9000|DK_Index name). The host answers 230|94 / 230|95 in channelResult.text.
import {loadChannelData} from '../channels/data.js';
import {dkLocates} from '../channels/channel-rules.js';
const npcId=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index);
export async function installSharedChannels(game,network){
  const data=await loadChannelData();
  const report=result=>{const text=result?.channelResult?.text;if(text){if(game.chat?.system)game.chat.system(text);else game.hud?.log?.(text,'sys');}return result;};
  const send=intent=>network.action('channel',intent).then(report);
  game.uiwin?.registerWindow?.('dkchannels',{
    script:'game2/smartwarp/ui_serverselect.txt',
    create(win){win.data.btns=[];},
    onOpen(win,{npcIndex,locates}={}){
      const tpl=win.control('btn_server'),bg=win.control('pan_bg');
      (locates||[]).forEach((l,i)=>{const b=win.data.btns[i]||=(i===0?tpl:tpl.cloneAs(`_${i}`,{x:15,y:40+i*25,parent:bg}));
        b.setText(l.name);b.setVisible(true);b.onClick(()=>{win.close('ok');void send({operation:'dkenter',npcIndex,locate:l.index});});});
      for(let i=(locates||[]).length;i<win.data.btns.length;i++)win.data.btns[i].setVisible(false);
      bg.setRect(0,0,130,70+(locates||[]).length*25);
    },
  });
  const enter=(npc,map)=>{
    const locates=dkLocates(data,map),npcIndex=npcId(npc);
    if(!locates.length)return network.unavailable?.('This DK portal');
    if(locates.length===1){void send({operation:'dkenter',npcIndex});return true;}
    void game.uiwin?.open('dkchannels',{npcIndex,locates});return true;
  };
  const leave=npc=>{void send({operation:'dkleave',npcIndex:npcId(npc)});return true;};
  let services=null;
  const register=()=>{const s=game.npcServices;if(!s?.register||services===s)return;services=s;
    s.register(96,(n,j)=>{game.uiwin?.close('npc');return enter(n,Number(j?.jobIndex));});
    s.register(97,n=>{game.uiwin?.close('npc');return leave(n);});
  };
  register();game.events?.on?.('systems',register);
  return {enter,leave};
}