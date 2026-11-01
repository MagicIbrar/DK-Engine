import {planGearSet} from '../../src/systems/gm/gear-set.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {commitLife} from './life-transactions.mjs';
export async function gmGearSet(world,user,input){
 const fail=(status,message)=>{throw Object.assign(Error(message),{status});};
 if(!user.capabilities?.includes('gm:commands'))fail(403,'GM permission is required.');
 if(JSON.stringify(input).length>32768)fail(400,'Gear settings are too large.');
 if(Object.keys(input).some(k=>!['token','operation','targetId','settings','preview'].includes(k)))fail(400,'Unexpected gear-set fields.');
 const operator=world.lease(user.id,input.token),target=input.targetId?[...world.players.values()].find(p=>!p.leaving&&p.id===input.targetId):operator;
 if(!target)fail(404,'Select a currently connected character.');
 const now=world.now();if(now-(operator.gmRateAt||0)>=1000){operator.gmRateAt=now;operator.gmActions=0;}if((operator.gmActions=(operator.gmActions||0)+1)>20)fail(429,'Too many GM commands.');
 const settings=input.settings;
 if(!settings||typeof settings!=='object'||Array.isArray(settings)||Object.keys(settings).some(k=>!['classIndex','level','mode','upgrade','grade','sockets','bound','weaponStyle','overrides','gems'].includes(k)))fail(400,'Choose valid gear settings.');
 if(settings.classIndex!=null&&Number(settings.classIndex)!==Number(target.profile.classIndex))fail(400,'The set class must match the selected character.');
 if(settings.level!=null&&Number(settings.level)>Number(target.profile.level))fail(400,'The level ceiling cannot exceed the selected character’s level.');
 if(input.preview!=null&&typeof input.preview!=='boolean')fail(400,'Invalid gear preview flag.');
 // The live item database loads the same native socket table lazily on clients.
 // A host may never open that client UI, so attach its already loaded authoritative table here.
 world.data.itemDB.T??=world.data.itemUseData?.tables;
 let plan;try{plan=planGearSet(world.data.itemDB,{...settings,classIndex:target.profile.classIndex,level:Math.min(Number(settings.level??target.profile.level),Number(target.profile.level))});}catch(e){fail(400,e.message);}
 if(input.preview)return {ok:true,plan,target:{id:target.id,name:target.profile.name,classIndex:target.profile.classIndex,level:target.profile.level}};
 if(target.progressCommitting||target.sceneTransition||target.tradeCommitting||target.tradeId||target.charTradeId||target.pcShopOpen)fail(409,'Finish the character’s current transaction before granting gear.');
 const before=structuredClone(target.profile),profile=structuredClone(before),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
 if(!plan.items.length)fail(400,'No matching native gear exists for these settings.');
 for(const item of plan.items)if(!inv.add(item.item,1,{grade:item.grade,rnd:item.options,sockets:item.sockets,bound:item.bound,roll:false}))fail(400,'The full set does not fit in the inventory. Free space and try again.');
 const stats=world.data.stats(profile,target,world.now());
 const publication=await commitLife(world,target,profile,{stats,hp:target.hp,mp:target.mp||0,profileBefore:before,rewardProgress:true});
 for(const [map,event]of publication.notices)world.emit(map,event);
 world.emit(target.map,{type:'gm:item',actorId:target.id});
 return {ok:true,message:`Granted ${plan.items.length} ${plan.mode} gear items to ${target.profile.name}.`,plan,state:world.snapshot(operator)};
}
