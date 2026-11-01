import {AuthoritativeInventory} from './inventory.mjs';
import {createItem,rollOptions,canonicalItemGrade} from '../../src/systems/items/model.js';
import {indexAtLevel} from '../../src/systems/gm/itemgen.js';
import {grantGroundItem} from './loot.mjs';
import {commitLife} from './life-transactions.mjs';
import {ownedItems,cursorOwnedItems} from './item-ownership.mjs';
import {cursorState} from '../../src/systems/items/cursor-custody.js';
export async function gmItemIntent(world,p,input){
 const fail=message=>{throw Object.assign(new Error(message),{status:400});};
 if(!['makeItem','editItem'].includes(input.operation)||Object.keys(input).some(k=>!['token','operation','spec','uid'].includes(k)))fail('Unknown GM item operation.');
 const spec=input.spec;if(!spec||typeof spec!=='object'||Array.isArray(spec)||Object.keys(spec).some(k=>!['item','count','upgrade','grade','sockets','options','brand','bound','to','free','roll'].includes(k)))fail('Invalid GM item specification.');
 const profile=structuredClone(p.profile),db=world.data.itemDB,inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});if(!db)fail('Item catalog is unavailable.');
 const whole=(value,min,max)=>{if(!Number.isInteger(value)||value<min||value>max)fail('Invalid GM item number.');return value;};
 const all=ownedItems(profile);
 const target=input.operation==='editItem'?all.find(i=>i.uid===input.uid):null;if(input.operation==='editItem'&&!target)fail('Choose an owned canonical item.');
 if(target&&all.filter(i=>i.uid===input.uid).length!==1)fail('This item identity is duplicated.');
 let index=target?.itemIndex??whole(spec.item,1,999999998);if(!db.def(index))fail('Unknown item index.');if(spec.upgrade!=null)index=indexAtLevel(db,index,whole(spec.upgrade,0,40));
 const def=db.def(index);let grade=spec.grade??target?.grade??'normal';if(!['normal','magic','noble','divine'].includes(grade))fail('Unknown item grade.');
 const count=whole(spec.count??target?.count??1,1,input.operation==='editItem'?db.stackSize(def):10000);
 const pairs=value=>{if(!Array.isArray(value)||value.length>32)fail('Invalid item option list.');return value.map(row=>{if(!Array.isArray(row)||row.length!==2||!Number.isInteger(row[0])||!db.optionType(row[0])||!Number.isFinite(row[1])||Math.abs(row[1])>1e9)fail('Unknown option code or invalid option value.');return [row[0],row[1]];});};
 const rnd=spec.options==null?target?.rnd:pairs(spec.options),brand=spec.brand==null?target?.brand:pairs(spec.brand);
 grade=canonicalItemGrade(db,def,grade,{rnd});
 let sockets=spec.sockets??target?.sockets??[];if(typeof sockets==='number')sockets=Array(whole(sockets,0,4)).fill(0);
 if(!Array.isArray(sockets)||sockets.length>4||sockets.some(i=>!Number.isInteger(i)||i!==0&&!(db.def(i)?.type===1&&db.def(i)?.code===0)))fail('Invalid socket stone identifiers.');
 for(const key of ['bound','roll','free'])if(spec[key]!=null&&typeof spec[key]!=='boolean')fail('Invalid GM item flag.');
 const roll=spec.roll??true;
 const options={grade,rnd:roll&&!rnd?.length?undefined:rnd,brand,sockets,bound:spec.bound??target?.bound,roll};
 const pending=[];
 if(target){Object.assign(target,{itemIndex:index,name:def.name,count,grade,sockets});if(rnd)target.rnd=rnd;if(roll&&def.slot&&grade!=='normal'&&!target.rnd?.length)target.rnd=rollOptions(def,grade,db,world.random);if(brand)target.brand=brand;if(spec.bound!=null)target.bound=spec.bound;
  if(profile.inventory.includes(target)){const[w,h]=inv.bag.size(target);if(!inv.bag.inside(target.x,target.y,w,h)||inv.bag.occupants(target.page,target.x,target.y,w,h,target).length)fail('The edited item does not fit its inventory position.');}
 }else{const to=spec.to??'bag';if(!['bag','cash','ground'].includes(to))fail('Unknown item destination.');if(to==='bag'){if(!inv.add(index,count,options))fail('The inventory is full.');}
  else{let left=count;while(left>0){const n=Math.min(left,db.stackSize(def)),item=createItem(db,index,{...options,count:n,now:world.now(),rng:world.random});if(to==='cash'){profile.cashInv||=[];if(profile.cashInv.length>=1000)fail('Cash inventory is full.');profile.cashInv.push(item);}else pending.push(item);left-=n;}}
 }
 if(target&&cursorOwnedItems(profile).includes(target))cursorState(profile).revision++;
 const stats=world.data.stats(profile,p,world.now());
 const publication=await commitLife(world,p,profile,{stats,hp:Math.min(p.hp,stats.maxHp),mp:p.mp||0,rewardProgress:true});
 for(const[map,event]of publication.notices)world.emit(map,event);
 for(const item of pending)grantGroundItem(world,p,item);
 world.emit(p.map,{type:'gm:item',actorId:p.id});return {message:`${target?'Edited':'Granted'} ${def.name} ×${count}.`,state:world.snapshot(p),ok:true};
}

