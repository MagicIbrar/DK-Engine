import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {serializeLife,validateLife,commitLife,lifeError as fail} from './life-transactions.mjs';
import {createQuestContext} from './quests.mjs';

export const CONVERSION_ACTION_SCHEMAS={convert:['token','type','operation','uid','recipe']};
function originalInt(value,min=0,max=10_000_000_000){
  if(value==null||String(value).trim()===''||!Number.isSafeInteger(Number(value))||Number(value)<min||Number(value)>max)fail('The original conversion value is unavailable.');
  return Number(value);
}
function originalItem(db,value){const index=originalInt(value,1,Number.MAX_SAFE_INTEGER);if(!db.def(index))fail('The original conversion item is unavailable.');return index;}
function exactRow(rows,key,index){
  const matches=rows?.filter(row=>Number(row[key])===index)||[];
  if(!matches.length)fail('This item has no original conversion rule.');
  const signature=row=>JSON.stringify(Object.entries(row).sort(([a],[b])=>a.localeCompare(b)));
  if(matches.some(row=>signature(row)!==signature(matches[0])))fail('The original conversion rule is ambiguous.');return matches[0];
}

/** Conversion costs and outcomes become visible only after the same durable save. */
export function dispatchConversion(world,p,input){
  if(input.type!=='convert')return false;
  return serializeLife(p,async()=>{
    validateLife(input,CONVERSION_ACTION_SCHEMAS);
    const roles={accessory:'ACCESSORYUPGRADE',helmet:'HELMET_RANK_CHANGE',seal:'ITEM_CHANGE'},role=roles[input.operation];
    if(!role||!nearbyNpc(world,p,{role}))fail('Walk near the item conversion NPC.');
    if(p.dead||p.leaving||p.sceneTransition)fail('Item conversion is unavailable while dead or changing maps.');
    if(typeof input.uid!=='string'||input.operation!=='accessory'&&'recipe' in input)fail('Send only the selected original conversion intent.');
    const db=world.data.itemDB,T=world.data.itemUseData?.tables;
    if(!db||!T)fail('The original conversion catalog is unavailable.');
    const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
    const target=inv.bag.list.find(item=>item.uid===input.uid);
    if(!target||target.expiresAt&&target.expiresAt<=world.now())fail('Choose an owned item.');
    if(target.count!==1)fail('Choose one original conversion target.');
    let result,ok=true;
    const debit=value=>{const cost=originalInt(value);if(inv.dil<cost)fail('Not enough DIL.');inv.addDil(-cost);};
    const remove=(index,count)=>{
      let left=count;
      for(const item of [...inv.bag.list].filter(item=>item!==target&&item.itemIndex===index&&!(item.expiresAt&&item.expiresAt<=world.now())).sort((a,b)=>a.count-b.count)){
        if(!left)break;const take=Math.min(left,item.count);if(take&&!inv.consumeEntry(item,take))fail('Missing conversion materials.');left-=take;
      }
      return left;
    };
    if(input.operation==='accessory'){
      if(!Number.isSafeInteger(input.recipe)||input.recipe<0)fail('Invalid conversion recipe.');
      const row=T.accessoryUpgrade?.rows?.[input.recipe];if(!row||originalInt(row.itemIndex,1)!==target.itemIndex)fail('This recipe cannot convert that item.');
      const rate=originalInt(row.successRate,0,10000),success=originalItem(db,row.resultItem),failure=originalInt(row.failResultItem,0,Number.MAX_SAFE_INTEGER);
      if(failure)originalItem(db,failure);
      // Supplied accessory rows explicitly use NOT_FAIL. Unknown failure
      // penalties cannot silently become preservation or destruction.
      if(row.penalty!=='NOT_FAIL')fail('The original accessory failure penalty is unsupported.');
      debit(row.costDil);
      for(let k=1;k<=6;k++){
        const count=originalInt(row[`mat${k}Count`],0,1000000),bound=originalInt(row[`mat${k}Bound`],0,Number.MAX_SAFE_INTEGER),trade=originalInt(row[`mat${k}Trade`],0,Number.MAX_SAFE_INTEGER);
        if(!count){if(bound||trade)fail('The original conversion materials are incomplete.');continue;}
        if(!bound&&!trade)fail('The original conversion materials are unavailable.');
        let left=count;for(const index of [...new Set([bound,trade].filter(Boolean))]){originalItem(db,index);left=remove(index,left);}
        if(left)fail('Missing conversion materials.');
      }
      ok=world.random()*10000<rate;result=ok?success:failure;
    }else if(input.operation==='helmet'){
      const row=exactRow(T.helmetRankChange?.rows,'BeforItem',target.itemIndex),after=originalItem(db,row.AfterItem),rate=originalInt(row['Upgrade Rate'],0,100);
      const active=originalInt(row.ItemCount,0,10);let found=0;debit(row.NeedDil);
      for(let k=1;k<=10;k++){
        const index=originalInt(row[`Item${k}`]??row[`item${k}`],0,Number.MAX_SAFE_INTEGER),count=originalInt(row[`count${k}`],0,1000000);
        if(!index&&!count)continue;if(!index||!count)fail('The original helmet conversion materials are incomplete.');found++;originalItem(db,index);
        if(remove(index,count))fail('Missing helmet conversion materials.');
      }
      if(found!==active)fail('The original helmet material count is ambiguous.');
      ok=world.random()*100<rate;if(ok)result=after;
    }else{
      const row=exactRow(T.itemChange?.rows,'SourceItemIndex',target.itemIndex);result=originalItem(db,row.DestItemIndex);let left=originalInt(row.SpendCount,1,1000000);
      for(const item of [...inv.bag.list]){
        if(item===target||item.expiresAt&&item.expiresAt<=world.now())continue;
        const def=db.def(item.itemIndex);if(Number(def?.type)===1&&Number(def.code)===18){const take=Math.min(left,item.count);if(take&&!inv.consumeEntry(item,take))fail('The selected Sealing Powder is unavailable.');left-=take;if(!left)break;}
      }
      if(left)fail('Not enough Sealing Powder.');target.bound=false;
    }
    if(result){
      const def=db.def(result),[w,h]=inv.bag.size({itemIndex:result});
      if(!inv.bag.fits(target.page,target.x,target.y,w,h,target))fail('Your inventory cannot fit the conversion result.');
      target.itemIndex=result;target.name=def.name;
    }
    const quests=world.data.progression?.quests?createQuestContext(world,p,{profile,inventory:inv,commitToPlayer:false}):null;quests?.engine.recountCollect(null,true);
    const stats=world.data.stats?.(profile,p,world.now())||null;
    await commitLife(world,p,profile,{stats,rewardProgress:true});
    quests?.commit();world.emit(p.map,{type:'item:upgrade',actorId:p.id,kind:input.operation,ok});return true;
  });
}
