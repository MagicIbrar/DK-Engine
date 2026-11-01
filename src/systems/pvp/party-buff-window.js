import {str} from '../hud-options/util.js';
import {itemIcon} from '../shops/common.js';

export const PARTY_BUFF_SCRIPT='game2/partypvp/ui_partypvpbuffwnd.txt';
export function installPartyBuffWindow(game,network) {
  const state=()=>network.partyPvp?.state()||{},ui=game.uiwin;
  const eligible=()=>network.active&&state().phase==='setup'&&state().buffs?.length>0;
  ui.registerWindow('partypvp_buffs',{
    script:PARTY_BUFF_SCRIPT,remember:false,escClose:true,band:'modal',
    create(win){
      win.data.rows=[];win.control('pan_buff').hide();
      for(let i=0;i<30;i++){
        const row=win.clone('pan_buff',`_buff_${i}`,{x:2+(i%3)*220,y:25+Math.floor(i/3)*37});
        row._buffControl=id=>row.control(`${id}_buff_${i}`);
        row.setVisible(false);row.setEnabled(true);win.data.rows.push(row);
        row._buffControl('btn_buff').onClick(async()=>{
          const binding=row._partyBuff;
          if(!eligible()||!binding||binding.match!==state().id||binding.token!==network.token||win.data.pending)return;
          win.data.pending=true;
          try{await network.partyPvp.buff(binding.index,!(state().selectedBuffs||[]).includes(binding.index));}
          finally{win.data.pending=false;paint(win);}
        });
      }
      win.control('buff_scroll').on('change',()=>paint(win));
    },
    onOpen:win=>{win.data.signature=null;paint(win);},
    update:win=>{if(!eligible()){win.close('server');return;}paint(win);},
  });
  function paint(win){
    const s=state(),buffs=s.buffs||[],scroll=win.control('buff_scroll');
    scroll.setRange(Math.max(0,Math.ceil(buffs.length/3)-10),10);
    const offset=Math.floor(scroll.value||0)*3,selected=new Set(s.selectedBuffs||[]);
    const signature=JSON.stringify([s.id,network.token,offset,s.selectedBuffs,buffs]);
    if(signature===win.data.signature)return;win.data.signature=signature;
    win.control('lbl_count').setText((str(1008,41)||'Currently Selected Buffs: %d.').replace('%d',selected.size));
    win.data.rows.forEach((row,i)=>{
      const buff=buffs[offset+i];row.setVisible(!!buff);row._partyBuff=buff?{index:buff.index,match:s.id,token:network.token}:null;
      if(!buff)return;
      const def=game.items?.db?.def?.(buff.item),binding=row._partyBuff;
      row._buffControl('lbl_item').setText(def?.name||String(buff.item));
      row._buffControl('pan_check').setVisible(selected.has(buff.index));
      row._buffControl('item_item').setIcon(null);
      void itemIcon(game,buff.item,36,36).then(icon=>{if(row._partyBuff===binding)row._buffControl('item_item').setIcon(icon);});
    });
  }
  game.chat?.registerCommand?.('/partybuffs',()=>{if(eligible())void ui.open('partypvp_buffs');return true;},'Choose buffs for a Party Match in Buff Mode.');
}
