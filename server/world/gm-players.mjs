import {WorldError} from './core.mjs';
const error=(status,message)=>{throw new WorldError(status,message);};
export async function playerGM(world,user,input,runGM){
 const operator=world.lease(user.id,input.token);
 const keys=input.operation==='players'?['token','operation']:input.operation==='renamePlayer'?['token','operation','targetId','name','nameColor','staffOverride']:['token','operation','targetId','line'];
 if(Object.keys(input).some(key=>!keys.includes(key)))error(400,'Unexpected player tool fields.');
 if(input.operation==='players')return {players:[...world.players.values()].filter(p=>!p.leaving).map(p=>({id:p.id,name:p.profile.name,classIndex:p.profile.classIndex,level:p.profile.level,map:p.map,x:p.x,z:p.z})),maps:[...world.maps.values()].map(map=>({id:map.index,width:map.width||map.collision?.width||512,height:map.height||map.collision?.height||512})),serverTime:world.now()};
 const target=[...world.players.values()].find(p=>!p.leaving&&p.id===input.targetId);
 if(!target)error(404,'Select a currently connected character.');
 if(input.operation==='renamePlayer'){
   if(input.staffOverride!=null&&typeof input.staffOverride!=='boolean')error(400,'Invalid staff name override.');
   if(input.staffOverride===true&&(target.gmAuthorized!==true||target.npcPlayer===true))error(403,'Staff labels require a currently authorized staff character.');
   if(!world.renameProfile)error(503,'Character rename storage is unavailable.');
   const result=await world.renameProfile(target.account,target.characterId,input.name,input.nameColor,undefined,{staffOverride:input.staffOverride===true});
   target.profile.name=result.name;target.profile.nameColor=result.nameColor||'white';world.changed(target);world.emit(target.map,{type:'rename',actorId:target.id,name:result.name,nameColor:target.profile.nameColor});
   await world.persist(target);
   return {message:'Character renamed.',player:{id:target.id,name:target.profile.name,nameColor:target.profile.nameColor},state:world.snapshot(operator)};
 }
 if(typeof input.line!=='string'||input.line.length>256||!/^\/gm\s+(?:heal|level|exp|dil|move)\b/i.test(input.line))error(400,'Choose heal, level, EXP, DIL or move for the selected player.');
 // Existing command parser, original rules and persistence; lease selection stays host-side.
 const result=await runGM(world,user,{token:operator.token,line:input.line},target);
 return {...result,state:world.snapshot(operator)};
}
