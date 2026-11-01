// Megaphone / DK Megaphone broadcasts (the super chat), host side. Rules + sources: src/systems/hud-options/superchat-rules.js.
// The spent Megaphones and the day's same-message count commit in one profile write (commitLife) before anything is queued,
// so a refused broadcast never costs an item. Queued broadcasts wait in memory (174:38 note 5: deleted when the server
// stops), one FIFO per server scope (the field server, or one DK server), released one at a time every MEGAPHONE_SLOT_MS.
// Recipients are derived here from the scope at release time; a client never names them.
import {AuthoritativeInventory} from './inventory.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {megaphoneCode,megaphoneMapBlocker,checkMegaphone,sameLeft,recordSame,serverScope,MEGAPHONE_SLOT_MS,MEGAPHONE_COLORS,SUPERCHAT_TEXT} from '../../src/systems/hud-options/superchat-rules.js';

export const MEGAPHONE_SCHEMAS={megaphone:['token','type','uid','text','color','repeat']};
const fail=(key,status=400)=>{throw Object.assign(new Error(SUPERCHAT_TEXT[key]||key),{status});};
const live=(e,now)=>!!e&&!(e.expiresAt&&e.expiresAt<=now);

function queueOf(world,scope){
  const all=world.megaphoneQueues||(world.megaphoneQueues=new Map());
  if(!all.has(scope))all.set(scope,{busyUntil:0,list:[]});
  return all.get(scope);
}
/** Pending broadcasts per scope (tests, GM tools). */
export function megaphonePending(world,scope='field'){return world.megaphoneQueues?.get(scope)?.list.length||0;}

export function megaphoneCommand(world,p,input){
  return serializeLife(p,async()=>{
    const db=world.data.itemDB;if(!db)fail('The item catalog is unavailable.',503);
    const now=world.now();
    if(now<(p.muteUntil||0))fail('Your chat is temporarily restrained.',403);
    if(typeof input.uid!=='string'||!input.uid)fail('noItem');
    const profile=structuredClone(p.profile);
    const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
    const entry=inventory.bag.list.find(e=>e.uid===input.uid);
    const code=live(entry,now)?megaphoneCode(db.def(entry.itemIndex)):0;
    if(!code)fail('noItem');
    const blocker=megaphoneMapBlocker(code,p.channel);if(blocker)fail(blocker,403);
    const checked=checkMegaphone({text:input.text,color:input.color??undefined,repeat:input.repeat??undefined});
    if(checked.error)fail(checked.error);
    const life=profile.life||(profile.life={});
    if(sameLeft(life.megaphone,checked.text,now)<checked.repeat)fail('failed',429);
    // one Megaphone per broadcast: the chosen stack first, then the other live stacks of the same item code
    const stacks=[entry,...inventory.bag.list.filter(e=>e!==entry&&live(e,now)&&megaphoneCode(db.def(e.itemIndex))===code)];
    if(stacks.reduce((n,e)=>n+(e.count||1),0)<checked.repeat)fail('noItem');
    let left=checked.repeat;
    for(const e of stacks){const take=Math.min(left,e.count||1);if(!inventory.consumeEntry(e,take))fail('failed');left-=take;if(!left)break;}
    life.megaphone=recordSame(life.megaphone,checked.text,checked.repeat,now);
    await commitLife(world,p,profile);
    world.emit(p.map,{type:'inventory',actorId:p.id,reason:'megaphone'});
    const scope=serverScope(p.channel),queue=queueOf(world,scope);
    for(let i=0;i<checked.repeat;i++)queue.list.push({actorId:p.id,name:p.profile.name,text:checked.text,color:checked.color,code,scope,map:p.map});
    tickMegaphone(world);
    return {queued:checked.repeat,pending:queue.list.length,scope};
  });
}

/** Release the next broadcast of every idle scope to every connected player of that scope. */
export function tickMegaphone(world){
  if(!world.megaphoneQueues)return;
  const now=world.now();
  for(const [scope,queue] of world.megaphoneQueues){
    if(!queue.list.length||now<queue.busyUntil)continue;
    const b=queue.list.shift();
    queue.busyUntil=now+MEGAPHONE_SLOT_MS;
    const recipients=[...world.players.values()].filter(q=>!q.leaving&&serverScope(q.channel)===scope).map(q=>q.id);
    if(!recipients.length)continue;
    world.emit(b.map,{type:'megaphone',actorId:b.actorId,name:b.name,text:b.text,color:MEGAPHONE_COLORS[b.color],code:b.code,scope,duration:MEGAPHONE_SLOT_MS,recipients});
  }
}