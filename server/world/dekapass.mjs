// Original pass missions/rewards, advanced only by server gameplay hooks.
import {DekaPass} from '../../src/systems/life/dekapass.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
const deny=message=>{throw Object.assign(new Error(message),{status:400})};
export const DEKAPASS_SCHEMAS={dekapass:['token','type','level','premium','all']};
// Premium rewards need an active Premium Holy Water of Almighty, the same rule as the client (DekaPass.premium,
// stringtable_dekapass 3200:2). st.premium publishes that entitlement to the online client (network/life.js reads it) and is
// recomputed from the character's premium services at every access, so it closes when the service ends. Progress and claims
// retain the original season/character state and earned-tier requirements.
class ServerDekaPass extends DekaPass {
 get st(){const st=super.st;st.premium=super.premium;return st;}
}
function context(world,p,profile){
 const inventory=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
 const game={save:profile,now:world.now,world:{},items:{bag:inventory.bag,count:i=>inventory.count(i),def:i=>world.data.itemDB.def(i),db:world.data.itemDB,canAdd:(i,n)=>inventory.canFit([{item:i,count:n}]),add:(i,n,o)=>inventory.add(i,n,o)},uiwin:{window:()=>null,open:async()=>null},hud:{log(){}},events:{emit(){}},persist(){}};
 const pass=new ServerDekaPass(game,{data:{dekapass:world.data.dekapass}});pass._alarm=()=>{};return pass;
}
export function initializeDekaPass(world,p){if(!world.data.dekapass||!world.data.itemDB)return;const pass=context(world,p,p.profile);void pass.st;}
export function progressDekaPass(world,p,main,sub,value=0,count=1,options={}){
 if(!world.data.dekapass||!world.data.itemDB||!Number.isFinite(count)||count<=0)return;
 const before=JSON.stringify(p.profile.life?.dekapass),pass=context(world,p,p.profile);pass.progress(main,sub,value,count,{party:options?.party===true});
 if(JSON.stringify(p.profile.life?.dekapass)!==before)world.changed(p);
}
/** A monster kill made by another member of p's party (MONSTER 31 / KILL 32): only missions whose native help counts party kills
 * (stringtable_dekapass 3206:27, src/systems/life/dekapass.js PARTY_KILL_MISSIONS). The killer's own credit stays the ordinary call. */
export function progressDekaPassPartyKill(world,member,monsterIndex){progressDekaPass(world,member,31,32,monsterIndex,1,{party:true});}
export function tickDekaPass(world,p,dt){if(!world.data.dekapass||!world.data.itemDB||p.leaving||p.commandActive||!Number.isFinite(dt)||dt<=0)return;const pass=context(world,p,p.profile);if(!pass.active)return;const day=p.profile.life?.dekapass?.day,st=pass.st;if(st.day!==day)p._passSeconds=0;st.playSec=(st.playSec||0)+dt;p._passSeconds=(p._passSeconds||0)+dt;if(p._passSeconds>=5){const count=Math.floor(p._passSeconds);p._passSeconds-=count;pass.progress(0,0,0,count);world.changed(p);}}
export async function dekapassCommand(world,p,input){
 return serializeLife(p,async()=>{
 if(!world.data.dekapass||!world.data.itemDB)deny('Deka Pass tables are unavailable.');
 if(input.all!=null&&typeof input.all!=='boolean'||input.premium!=null&&typeof input.premium!=='boolean')deny('Invalid Deka Pass request.');
 if(input.all&&input.level!=null)deny('Choose one reward or Receive all.');
 const profile=structuredClone(p.profile),pass=context(world,p,profile);if(!pass.active)deny('This Deka Pass season is inactive.');
 let claimed=0;if(input.all===true)claimed=pass.claimAll();else{if(!Number.isInteger(input.level)||input.level<1||input.level>pass.levels)deny('Invalid reward level.');claimed=pass.claim(input.level,input.premium===true)?1:0;}
 if(!claimed)deny('No eligible reward was granted. Check pass level, premium access, prior claims and bag space.');
 await commitLife(world,p,profile);world.emit(p.map,{type:'dekapass',actorId:p.id,claimed,instanceId:p.instanceId||null});return true;
 });
}
