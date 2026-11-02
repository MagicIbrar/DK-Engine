import {upgradeRow,supportOk,upgradeRate,failLevel} from '../../src/systems/items/ui/upgrade.js';
import {indexAtLevel} from '../../src/systems/items/ui/craft.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {premiumUpgradeBonus} from './premium-service.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {isStone,socketable,stoneFits} from '../../src/systems/items/ui/socket.js';
import {optCode,brandable} from '../../src/systems/items/ui/enchant.js';
import {documentedSocketLimit} from '../../src/systems/items/socket-capacity.js';
import {wingDismantleRule,rollWingDismantleCount} from '../../src/systems/items/wing-dismantle-rules.js';
export const ENHANCEMENT_ACTION_SCHEMAS={upgrade:['token','type','uid','stone','ruin','rates','safe'],socket:['token','type','uid','action','stone','materials','support','protect','slot'],brand:['token','type','uid','stone','locks'],craft:['token','type','operation','uid','material','count','ruin','support','protect']};
export async function dispatchEnhancement(world,p,input){
 // These new mission producers own their exact target through durable save.
 // Two public commands can pass core's early guard before async dispatch reaches
 // the first save. Recheck the current human lease inside the serialized scope.
 if(input.type==='craft'&&input.operation==='dismantle'||input.type==='socket'&&input.action==='add'){
  const operation=()=>serializeLife(p,async()=>{
   if(typeof world.lease==='function'&&world.lease(p.account,input.token)!==p)throw Object.assign(Error('The enhancement actor changed.'),{status:409});
   if(p.dead||p.leaving||p.revoked||p.sceneTransition||p.progressCommitting||p.tradeCommitting)throw Object.assign(Error('Wait for the current enhancement scope.'),{status:409,code:'WORLD_BUSY'});
   return input.type==='craft'?craft(world,p,input):socket(world,p,input);
  });
  return typeof world.serializeAccount==='function'&&p.account?world.serializeAccount(p.account,operation):operation();
 }
 if(input.type==='craft')return craft(world,p,input);if(input.type==='brand')return brand(world,p,input);if(input.type==='socket')return socket(world,p,input);if(input.type!=='upgrade')return false;
 const fail=message=>{throw Object.assign(new Error(message),{status:400});};
 if(!nearbyNpc(world,p,{role:'ITEMUPGRADE'}))fail('Walk near an item upgrade NPC.');
 const profile=structuredClone(p.profile),db=world.data.itemDB,bag=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});db.T=world.data.itemUseData.tables;
 const find=uid=>{const item=bag.bag.list.find(i=>i.uid===uid);if(!item||item.expiresAt&&item.expiresAt<=world.now())fail('An enhancement item is no longer available.');return item;};
 const target=find(input.uid),def=db.def(target.itemIndex),row=upgradeRow(db,def);if(!row)fail('This item cannot be reinforced.');
 const stone=find(input.stone);if(![Number(row.stone1),Number(row.stone2)].includes(stone.itemIndex))fail('Choose the correct enhancement stone.');
 if(!Array.isArray(input.rates)||input.rates.length>2)fail('Choose at most two rate items.');
 const rates=input.rates.map(find),safe=input.safe?find(input.safe):null,ruin=input.ruin?find(input.ruin):null;
 const all=[target,stone,...rates,...[safe,ruin].filter(Boolean)];if(new Set(all.map(i=>i.uid)).size!==all.length)fail('Each enhancement slot needs a different item.');
 for(const item of rates)if(supportOk(db,db.def(item.itemIndex),def,'rate')!==true)fail('This rate item cannot reinforce this target.');
 if(safe&&supportOk(db,db.def(safe.itemIndex),def,'safe')!==true)fail('This protector cannot reinforce this target.');
 // Evidence (scan fix A): Global itemetc.csv:2933/2938 Ruin Argate 9908 Rank 5, Colosseum Argate 9913 Rank 6 (stone Rank = target Rank).
 const required={5:9908,6:9913}[Number(def.rank)];if(required&&ruin?.itemIndex!==required||ruin&&!required)fail('Choose the required special argate.');
 const cost=Number(row.costDil)||0;if(bag.dil<cost)fail('Not enough DIL.');bag.addDil(-cost);
 // Evidence (scan fix A): code-21 protectors (itemcash.csv 1751027/1751067) use Global description 450 "Upgrade level can go down by up to 3."
 // Other protectors state no cap, so 99 = no extra cap beyond itemupgrade_safe.csv BACKWARD_* (ENGINE-CHOSEN sentinel).
 let protect=safe?{kind:'safe',maxDrop:db.def(safe.itemIndex).code===21?3:99}:null;
 for(const item of rates){const support=db.T.upgradeSubItem.rows.find(r=>Number(r.ItemIndex)===item.itemIndex);const group=Number(support?.Group);if(group===9)protect={kind:'spirit'};else if(group===6)protect={kind:'glory'};else if(group===5&&def.itemLv>=1)protect={kind:'grace',maxDrop:3};}
 // + the running Holy Water ItemUpgradeRate (server-owned premium state; up to a +11 result, upgrade.js premiumUpgradeBonusFor)
 const ok=world.random()*100<upgradeRate(db,def,rates.map(i=>db.def(i.itemIndex)),premiumUpgradeBonus(world,p.profile));
 for(const item of [stone,...rates,...[ruin,...(row.penalty!=='NOT_FAIL'?[safe]:[])].filter(Boolean)])if(!bag.consumeEntry(item,1))fail('Missing enhancement materials.');
 const level=ok?Number(def.itemLv||0)+1:failLevel(db,row,Number(def.itemLv)||0,protect,world.random);
 if(level<0)bag.bag.take(target);else{const index=ok?def.next:indexAtLevel(db,def.index,level),next=db.def(index);if(!next)fail('The enhancement result is unavailable.');target.itemIndex=Number(index);target.name=next.name;}
 // Global item type: 4=weapon, 5=armor, 2=accessory (type 3=use/scrolls). DekaPass REINFORCEM subs 17/18/19.
 const kind={4:'weapon',5:'armor',2:'accessory'}[Number(def.type)],sub={weapon:17,armor:18,accessory:19}[kind];
 if(sub)progressDekaPass({...world,changed(){}},{...p,profile},4,sub,0,1);
 await commitLife(world,p,profile);world.emit(p.map,{type:'item:upgrade',actorId:p.id,kind,ok,level,destroyed:level<0});return true;
}
async function craft(world,p,input){
 const fail=message=>{throw Object.assign(new Error(message),{status:400});};
 const role=['removeoption','option'].includes(input.operation)?'ITEMOPTIONUPGRADE':'ITEMINCUSE';
 if(!nearbyNpc(world,p,{role}))fail('Walk near the crafting NPC.');
 const db=world.data.itemDB,profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});db.T=world.data.itemUseData.tables;
 const find=uid=>{const i=inv.bag.list.find(i=>i.uid===uid);if(!i||i.expiresAt&&i.expiresAt<=world.now())fail('A crafting material is no longer available.');return i;};
 if(input.operation==='option'){
  const target=find(input.uid),material=find(input.material),def=db.def(target.itemIndex),k=target.rnd?.length||0,cap={normal:0,magic:2,noble:3,divine:4}[target.grade]||0;
  const row=db.T.optionUpgrade.rows.find(r=>Number(r.ITEM_OPTION)===Math.min(3,k)&&Number(r.ITEM_LEVEL)===Math.max(1,Math.min(250,Number(def.reqLv)||1)));
  if(!def.slot||!brandable(def)&&Number(def.type)!==2||k>=cap||!row)fail('This item cannot receive another option.');
  const hi=material.itemIndex===Number(row.HI_OPTION_STONE_INDEX);if(!hi&&material.itemIndex!==Number(row.LOW_OPTION_STONE_INDEX))fail('Choose the correct Marvric.');
  // Evidence (scan fix A): Global itemetc.csv:2934/2939 Ruin Mavric 9909 Rank 5, Colosseum Mavric 9914 Rank 6 (stone Rank = target Rank).
  const ruin=input.ruin?find(input.ruin):null,support=input.support?find(input.support):null,protect=input.protect?find(input.protect):null,required={5:9909,6:9914}[Number(def.rank)];
  if(required&&ruin?.itemIndex!==required||ruin&&!required)fail('Choose the required special Marvric.');
  const kind=(i,c)=>{const d=db.def(i.itemIndex);return d.type===1&&d.code===c;};if(support&&!kind(support,13)||protect&&!kind(protect,15))fail('Invalid Alchemist support item.');
  const slots=[target,material,...[ruin,support,protect].filter(Boolean)];if(new Set(slots.map(i=>i.uid)).size!==slots.length)fail('Each option slot needs a different item.');
  const cost=Number(row.ASK_DIL)||0;if(inv.dil<cost||!inv.remove(material.itemIndex,Number(row.STONE_COUNT)||1))fail('Not enough Marvrics or DIL.');inv.addDil(-cost);for(const i of [ruin,support,protect].filter(Boolean))if(!inv.consumeEntry(i,1))fail('Missing Alchemist support item.');
  const rate=Math.min(100,Number(row.SUCCESS_RATE)/1000*(support?Math.max(1,Number(db.def(support.itemIndex).upgradeRate)||2):1));target.rnd||=[];
  if(world.random()*100<rate){const n=hi&&world.random()*100000>=Number(row.HI_OPTION_RATE_0)?2:1;for(let a=0;a<n&&target.rnd.length<cap;a++){const pools=def.optionPools||[],[lo,high]=pools[Math.min([0,0,1,2][target.rnd.length]??2,pools.length-1)]||[0,0];if(!(high>0))continue;const level=(lo||high)+Math.floor(world.random()*(high-(lo||high)+1)),rows=db.options.pools[level];if(!rows?.length)continue;const r=rows[Math.floor(world.random()*rows.length)],min=Math.round(r[2]),max=Math.round(r[3]),v=min+Math.floor(world.random()*(max-min+1));if(v)target.rnd.push([Number(r[1]),v]);}}
  else if(!protect){const keys=hi?['HI_PENALTY_RATE_0','HI_PENALTY_RATE_1','HI_PENALTY_RATE_2']:['LOW_PENALTY_RATE_0','LOW_PENALTY_RATE_1','LOW_PENALTY_RATE_2'],dice=world.random()*100000;let sum=0,lose=0;for(let a=0;a<3;a++){sum+=Number(row[keys[a]])||0;if(dice<sum){lose=a;break;}}lose=Math.min(lose,target.rnd.length);if(lose)target.rnd.splice(target.rnd.length-lose,lose);}
  // DekaPass ITEM 5 / DYNAMIC_OPTION 36 season 26 "Craft Options at Carmen NPC" (3202:26): one per crafting attempt, like Enhance.
  progressDekaPass({...world,changed(){}},{...p,profile},5,36,target.itemIndex,1);
 }else if(input.operation==='removeoption'){
  const target=find(input.uid),material=find(input.material),def=db.def(material.itemIndex);
  if(target===material||!target.rnd?.length||def.type!==1||def.code!==14)fail('Choose an option-bearing item and Alchemist Arrangement.');
  if(!inv.consumeEntry(material,1))fail('The Alchemist Arrangement is unavailable.');target.rnd.pop();
 }else if(input.operation==='dismantle'){
  const target=find(input.uid),material=find(input.material),def=db.def(target.itemIndex),hammer=db.def(material.itemIndex);
  if(target===material||hammer.type!==0||hammer.code!==41)fail('Choose equipment and a Disassembly Hammer.');
  let result=null;
  if(def.slot==='wing'){
   const row=wingDismantleRule(db,target.itemIndex);if(!row)fail('This wing has no supported original dismantling rule.');
   if(inv.dil<row.dil)fail('Not enough DIL.');inv.addDil(-row.dil);
   const count=rollWingDismantleCount(row,world.random);if(count)result=[row.item,count];
  }else{
   const row=db.T.disassemble.rows.find(r=>Number(r.Value)===Math.max(1,Math.min(250,Number(def.reqLv)||1)));
   if(!brandable(def)||!row)fail('Choose equipment and a Disassembly Hammer.');
   const dice=world.random()*Math.max(1,Number(row['Total Ratio']));let sum=0;for(let k=1;k<=5;k++){sum+=Number(row[`ItemRatio_${k}`])||0;if(dice<sum&&Number(row[`ItemIndex_${k}`])){result=[Number(row[`ItemIndex_${k}`]),Number(row[`ItemCount_${k}`])||1];break;}}
  }
  if(!inv.consumeEntry(material,1))fail('The Disassembly Hammer is unavailable.');inv.bag.take(target);if(result&&!inv.add(...result))fail('Your inventory cannot fit the crafting result.');
  progressDekaPass({...world,changed(){}},{...p,profile},def.slot==='wing'?10:5,26,target.itemIndex,1);
 }else if(input.operation==='amplify'){
  const material=find(input.material),row=db.T.amplify.rows.find(r=>Number(r.RESOURCE_INDEX)===material.itemIndex),count=input.count;
  if(!row||!Number.isInteger(count)||count<1||count>999)fail('Choose a supported Soul Stone and quantity.');
  const cost=Number(row.COST_DIL)*count,need=Number(row.RESOURCE_COUNT)*count;if(inv.dil<cost||!inv.remove(material.itemIndex,need))fail('Not enough Soul Stones or DIL.');inv.addDil(-cost);if(!inv.add(Number(row.TARGET_INDEX),count))fail('Your inventory cannot fit the crafting result.');
  // DekaPass SOUL 9 / UPGRADE 29 season 7 "Amplify Soul Stones" (3202:7): 3206:7 "Exchanges must be done in batches of 10, not 100
  // at once", so one amplification operation counts once whatever its quantity.
  progressDekaPass({...world,changed(){}},{...p,profile},9,29,Number(row.TARGET_INDEX),1);
 }else fail('This crafting operation is unavailable.');
 await commitLife(world,p,profile,{rewardProgress:true});world.emit(p.map,{type:'inventory',actorId:p.id,reason:'craft'});return true;
}
async function brand(world,p,input){
 const fail=message=>{throw Object.assign(new Error(message),{status:400});};
 // Branding is the ITEMINCUSE (job 103) NPC service: official Global guide 2 / help 1306:2 "through the NPCs Axion, Pablos, and
 // Maximus"; the client opens it only from that NPC's window (enchant.js 'incuse' tab 2).
 if(!nearbyNpc(world,p,{role:'ITEMINCUSE'}))fail('Walk near the crafting NPC.');
 const db=world.data.itemDB,profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});db.T=world.data.itemUseData.tables;
 const target=inv.bag.list.find(i=>i.uid===input.uid),stone=inv.bag.list.find(i=>i.uid===input.stone),def=target&&db.def(target.itemIndex),sd=stone&&db.def(stone.itemIndex);
 if(!target||!stone||target===stone||!brandable(def)||Number(sd.type)!==1||Number(sd.code)!==19||target.expiresAt&&target.expiresAt<=world.now()||stone.expiresAt&&stone.expiresAt<=world.now())fail('Choose owned branding equipment and a Soul Stone.');
 if(!Array.isArray(input.locks)||input.locks.length>4||new Set(input.locks).size!==input.locks.length||input.locks.some(i=>!Number.isInteger(i)||i<0||i>3||!target.brand?.[i]))fail('Invalid branding locks.');
 const locks=inv.bag.list.filter(i=>{const d=db.def(i.itemIndex);return d.type===0&&d.code===42&&!(i.expiresAt&&i.expiresAt<=world.now());});if(locks.reduce((n,i)=>n+i.count,0)<input.locks.length)fail('Not enough Brand Option Locks.');
 const lv=Math.max(1,Math.min(250,Number(sd.use?.brandLevel)||0)),row=db.T.incuseOptionLevels.rows.find(r=>Number(r.Level)===lv),pool=[];
 if(row)for(let k=1;k<=Number(row.count||0);k++){const option=db.T.incuseOption.rows.find(r=>Number(r.No)===Number(row[`Value${k}`])),code=option&&optCode(db,option.Option);if(code!=null)pool.push({code,min:Number(row[`DataMin${k}`]),max:Math.min(Number(row[`DataMax${k}`]),Number(option.MaxCapacityLimit)||Infinity)});}
 if(!pool.length)fail('Branding options are unavailable.');
 if(!inv.consumeEntry(stone,1))fail('The Soul Stone is unavailable.');let left=input.locks.length;for(const item of locks){const n=Math.min(left,item.count);if(n&&!inv.consumeEntry(item,n))fail('A Brand Option Lock is unavailable.');left-=n;}
 const difference=Math.max(-65,Math.min(100,(Number(sd.use?.brandLevel)||0)-(Number(def.reqLv)||0))),dice=db.T.incuseDice.rows.find(r=>Number(r.ResultValue)===difference),ok=world.random()*100<(Number(dice?.SuccessRate)||0)/10;
 if(ok){const old=target.brand||[],out=[],used=new Set();for(let i=0;i<4;i++){if(input.locks.includes(i)&&old[i]){out.push(old[i]);used.add(old[i][0]);continue;}const candidates=pool.filter(o=>!used.has(o.code));if(!candidates.length)break;const option=candidates[Math.floor(world.random()*candidates.length)],min=Math.round(option.min),max=Math.round(option.max);out.push([option.code,min+Math.floor(world.random()*(max-min+1))]);used.add(option.code);}target.brand=out;}
 // DekaPass REINFORCEM 4 / OPTION 11 season 4 "Craft Brand Option" (3202:4; Korean 각인 = Branding, help 1306:2): one per attempt.
 progressDekaPass({...world,changed(){}},{...p,profile},4,11,target.itemIndex,1);
 await commitLife(world,p,profile);world.emit(p.map,{type:'item:brand',actorId:p.id,ok});return true;
}
async function socket(world,p,input){
 const fail=message=>{throw Object.assign(new Error(message),{status:400});};
 const profile=structuredClone(p.profile),db=world.data.itemDB,inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});db.T=world.data.itemUseData.tables;
 const find=uid=>{const item=inv.bag.list.find(i=>i.uid===uid);if(!item||item.expiresAt&&item.expiresAt<=world.now())fail('A socket item is no longer available.');return item;};
 const target=find(input.uid),def=db.def(target.itemIndex);if(!socketable(def))fail('This item cannot hold sockets.');let ok=true;
 if(input.action==='insert'){
  const limit=documentedSocketLimit(db,def);if(limit!==null&&(target.sockets?.length||0)>limit)fail('This item exceeds its supported socket count.');
  const stone=find(input.stone),sd=db.def(stone.itemIndex),slot=target.sockets?.findIndex(n=>!n);
  if(stone.uid===target.uid||!isStone(sd)||!stoneFits(db,sd,def)||slot==null||slot<0)fail('Choose a compatible stone and empty socket.');
  if(!inv.consumeEntry(stone,1))fail('The socket stone is unavailable.');target.sockets[slot]=sd.index;
 }else{
  if(!['add','remove'].includes(input.action))fail('Unknown socket operation.');
  const role=input.action==='add'?'ITEMADDSOCKET':'ITEM_REMOVE_STONE';
  if(!nearbyNpc(world,p,{role}))fail('Walk near a socket NPC.');
  const wing=Number(def.type)===6&&Number(def.code)===1;
  if(!wing&&Number(def.rank)===4)fail('This cash item cannot be socketed.');
  if(!Array.isArray(input.materials)||input.materials.length>(input.action==='add'?5:4))fail('Invalid socket materials.');
  const mats=input.materials.map(find),support=input.support?find(input.support):null,protect=input.protect?find(input.protect):null;
  const all=[target,...mats,...[support,protect].filter(Boolean)];if(new Set(all.map(i=>i.uid)).size!==all.length)fail('Each socket slot needs a different item.');
  for(const mat of mats){const d=db.def(mat.itemIndex);if(!isStone(d)&&!(input.action==='remove'&&d.type===1&&d.code===1&&/argate/i.test(d.name)))fail('Invalid socket material.');}
  const sub=item=>db.T.upgradeSubItem.rows.find(r=>Number(r.ItemIndex)===item.itemIndex);
  if(protect&&(!wing||input.action!=='add'||Number(sub(protect)?.Group)!==7))fail('Invalid socket protection.');
  if(support&&(input.action==='add'?wing||Number(sub(support)?.Group)!==8:Number(db.def(support.itemIndex).type)!==1||Number(db.def(support.itemIndex).code)!==11))fail('Invalid socket rate item.');
  let rate,cost,need=0,needItem;
  if(wing){const rows=input.action==='add'?db.T.wingAddSocket.rows:db.T.wingRemoveStone.rows,row=rows.find(r=>Number(r.ItemIndex)===def.index);if(!row)fail('Wing socket rules are unavailable.');rate=Number(row.Rate)||0;cost=Number(row.Cost_Dil)||0;need=Number(row.Need_Item_Count)||0;needItem=Number(row.Need_Item)||4000776;}
  else{const rows=input.action==='add'?db.T.addSocket.rows:db.T.removeStone.rows;let row=rows?.[0];for(const r of rows||[])if(Number(r.ITEM_LEVEL)<=Number(def.reqLv||0))row=r;else break;if(!row)fail('Socket rules are unavailable.');const col={normal:'NORMAL',magic:'MAGIC',noble:'NOBLE',divine:'DIVIN'}[target.grade]||'NORMAL';rate=Number(def.rank)===5?Number(row.Deka_Rate):Number(row[`${col}_Rate`]);rate+=input.action==='add'?Math.min(25,mats.length*(Number(row.SocketStone_Rate)||5)):mats.reduce((n,i)=>n+(isStone(db.def(i.itemIndex))?Number(row.SocketStone_Rate)||0:Number(row.Agate_Rate)||0),0);cost=Number(row[input.action==='add'?col:`${col}_DIL`])||0;}
  if(support)rate+=Number(db.def(support.itemIndex).upgradeRate)||0;
  if(input.action==='add'&&(target.sockets?.length||0)>=(documentedSocketLimit(db,def)??4))fail('All socket slots are already open.');
  if(input.action==='remove'&&(!Number.isInteger(input.slot)||!target.sockets?.[input.slot]||!wing&&!mats.length))fail('Choose a filled socket and removal materials.');
  if(inv.dil<cost)fail('Not enough DIL.');if(need&&!inv.remove(needItem,need))fail('Not enough wing socket materials.');inv.addDil(-cost);
  for(const item of [...mats,...[support,protect].filter(Boolean)])if(!inv.consumeEntry(item,1))fail('Missing socket materials.');
  ok=world.random()*100<Math.max(0,Math.min(100,rate));
  if(input.action==='add'){if(ok)target.sockets=[...(target.sockets||[]),0];else if(wing&&!protect&&target.sockets?.length)target.sockets.pop();}
  else if(ok)target.sockets[input.slot]=0;else target.sockets.splice(input.slot,1);
 }
 // Applying a stone differs from opening or removing a socket.
 if(input.action==='insert')progressDekaPass({...world,changed(){}},{...p,profile},7,22,target.itemIndex,1);
 // Native CREATE 23 (season21, Socket Refinement): only a created socket counts.
 // A refused request, failed roll or failed durable save cannot publish credit.
 if(input.action==='add'&&ok)progressDekaPass({...world,changed(){}},{...p,profile},7,23,target.itemIndex,1);
 await commitLife(world,p,profile,{stats:world.data.stats(profile,p,world.now()),rewardProgress:true});world.emit(p.map,{type:'item:socket',actorId:p.id,ok,action:input.action});return true;
}
