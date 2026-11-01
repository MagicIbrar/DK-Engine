// Native Rune Exchange Box Duplicate Warning uses the dedicated checklist, not item names or proc groups.
import {fetchCSVObjects} from '../../engine/assets.js';
export const RUNE_CHECKLIST='script/runechecklist/runeitem_check.csv';
export function runeGroups(rows){const groups=new Map();for(const row of rows||[]){const item=Number(row.ItemIndex),group=Number(row.RuneGroup);if(Number.isSafeInteger(item)&&item>0&&Number.isSafeInteger(group)&&group>0)groups.set(item,group);}return groups;}
export function duplicateRuneRewards(groups,rewards,inventory,now=Date.now()){
 const held=new Set((inventory||[]).filter(x=>x&&Number(x.count??1)>0&&!(Number(x.expiresAt)>0&&Number(x.expiresAt)<=now)).map(x=>groups.get(Number(x.itemIndex))).filter(x=>x!==undefined));
 return [...new Set((rewards||[]).map(x=>Number(x.item??x.itemIndex)).filter(item=>groups.has(item)&&held.has(groups.get(item))))];
}
export class RuneBoxWarning {
 constructor(game,{load=()=>fetchCSVObjects(RUNE_CHECKLIST,true)}={}){this.game=game;this.load=load;this.pending=null;}
 async confirm(rewards){
  const g=this.game;if(!rewards?.length)return true;if((g.options?.get?.('runeMsg')??g.settings?.runeMsg??true)===false)return true;
  const groups=await(this.pending??=this.load().then(runeGroups).catch(error=>{this.pending=null;throw error;}));
  const owned=g.items?.bag?.list??g.save?.inventory??[];
  if(!duplicateRuneRewards(groups,rewards,owned).length)return true;
  const W=g.uiwin,win=await W.create('game2/randombox/ui_runecheckmsgwnd.txt',{modal:true,escClose:true,remember:false,disposeOnClose:true});
  return new Promise(resolve=>{
   let done=false;const finish=ok=>{if(done)return;done=true;if(ok&&win.find('chk_checkbox')?.isChecked?.()){g.settings??={};g.settings.runeMsg=false;g.setSettings?.({runeMsg:false});}resolve(ok);win.close('done');};
   win.find('btn_confirm')?.onClick(()=>finish(true));win.find('btn_cancel')?.onClick(()=>finish(false));win.once('close',()=>finish(false));W.openWindow(win);
  });
 }
}
