import { Equipment, emptyEquip } from '../items/equip.js';
import { styledClass } from '../items/look.js';
export function remoteAppearance(game,row,base){
  const save={name:row.name,nameColor:row.nameplate?.nameColor||row.nameColor||'white',classIndex:row.classIndex,level:row.level,equip:emptyEquip()};
  for(const item of row.appearance||[]){
    if(![4,5,7,8,9,10,11,12,18,33,36].includes(item.slot)||!Number.isSafeInteger(item.itemIndex))continue;
    const uid=`visual-${item.slot}`;save.equip.presets[0][item.slot]=uid;
    save.equip.items[uid]={uid,itemIndex:item.itemIndex,appearance:item.appearance||0,sockets:item.sockets||[]};
  }
  const db=game.items?.db;if(!db)return {save,classDef:base};
  const eq=new Equipment({db,game:{save,settings:game.settings}});save.equipment=eq.view();
  return {save,classDef:styledClass(base,db,eq.style())};
}
