// The original renewed confirmation displays gate levels, HP and the total
// charge. Confirm only authorizes the caller's already-quoted host intent.
export async function siegeUpgradeConfirm(game,review,current=()=>true) {
  const win=await game.uiwin.create('game2/siege/ui_siegeupgradeconfirmwnd.txt',{name:'siegeRenewGateConfirm',modal:true,escClose:true,remember:false,disposeOnClose:true});
  if(!current()){win.close();return 'cancel';}
  const c=id=>win.control(id),format=(code,...args)=>{let i=0;return String(game.uiwin.strings?.get?.({group:'NORMAL',cate:410,code})||'').replace(/%[us]/g,()=>String(args[i++]??''));};
  const groups=review.groups.slice(0,5);
  for(let i=0;i<5;i++){
    const row=groups[i];c(`pan_gate${i}`).setVisible(!!row);if(!row)continue;
    c(`lbl_gatename${i}`).setText(row.name);
    c(`lbl_level${i}`).setText(row.level===row.targetLevel?row.level:format(3,row.level,row.targetLevel));
    c(`lbl_hp${i}`).setText(row.hp===row.targetHp?Number(row.hp).toLocaleString('en-US'):`${Number(row.hp).toLocaleString('en-US')} > ${Number(row.targetHp).toLocaleString('en-US')}`);
  }
  // Global's static money/footer coordinates overlap its fourth/fifth rows.
  const moneyY=48+groups.length*78+6,footerY=moneyY+22;
  c('lbl_money').setRect(4,moneyY,261,18);c('lbl_money').setText(format(5,Number(review.price).toLocaleString('en-US')));
  c('pan_bg_mid').setRect(0,67,269,Math.max(0,footerY-67));c('pan_bg_bottom').setRect(0,footerY,269,32);
  c('pan_base').setRect(0,0,269,footerY+32);
  return new Promise(resolve=>{
    let done=false;const finish=value=>{if(done)return;done=true;resolve(value);};
    win.on('close',()=>finish('cancel'));
    c('btn_yes').onClick(()=>{finish(current()?'yes':'cancel');win.close();});
    for(const id of ['btn_no','btn_exit'])c(id).onClick(()=>win.close());
    win.open();
  });
}
