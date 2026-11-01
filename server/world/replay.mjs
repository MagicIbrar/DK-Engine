import {createHash} from 'node:crypto';
import {WorldError} from './core.mjs';
function canonical(value){if(Array.isArray(value))return '['+value.map(canonical).join(',')+']';if(value&&typeof value==='object')return '{'+Object.keys(value).sort().map(k=>JSON.stringify(k)+':'+canonical(value[k])).join(',')+'}';return JSON.stringify(value);}
export class CommandReceipts {
 constructor(){this.leases=new WeakMap();}
 async execute({player,headers,pathname,command,now,snapshot,dispatch}){
 const raw=headers['x-dekaron-command-sequence'],timeRaw=headers['x-dekaron-command-time'];
 if(typeof raw!=='string'||!/^\d+$/.test(raw)||!Number.isSafeInteger(Number(raw))||Number(raw)<=0||typeof timeRaw!=='string'||!/^\d+$/.test(timeRaw)||!Number.isSafeInteger(Number(timeRaw)))throw new WorldError(422,'A valid command sequence and server time are required.');
 const sequence=Number(raw),time=Number(timeRaw);if(now-time>15000||time-now>5000)throw new WorldError(422,'Command time expired. Refresh the shared world state before trying again.');
 let state=this.leases.get(player);if(!state){state={high:0,move:0,receipts:new Map(),at:now,count:0};this.leases.set(player,state);}
 if(now-state.at>=1000||now<state.at){state.at=now;state.count=0;}if(++state.count>120)throw new WorldError(429,'Too many command envelopes.');
 const digest=createHash('sha256').update(pathname+'\n'+canonical(command)).digest('hex'),previous=state.receipts.get(sequence);
 if(previous){if(previous.digest!==digest)throw new WorldError(422,'Command sequence was already used for different input.');if(previous.error)throw Object.assign(new WorldError(previous.error.status,previous.error.message),previous.error.code?{code:previous.error.code}:{});const current=snapshot();return pathname.endsWith('/gm')?{ok:true,replayed:true,state:current}:{...current,replayed:true};}
 if(sequence<=state.high-128)throw new WorldError(422,'Command sequence is too old.');
 // Movement reports travel on parallel connections and can arrive out of order. A newer report already set the
 // movement state, so an older one is superseded: answered with the current state, never applied (no 422).
 if((command.type==='move'||command.type==='stop')&&sequence<=state.move){state.high=Math.max(state.high,sequence);state.receipts.set(sequence,{digest});const current=snapshot();return {...current,superseded:true};}
 state.high=Math.max(state.high,sequence);if((command.type==='move'||command.type==='stop'))state.move=sequence;
 for(const key of state.receipts.keys())if(key<=state.high-128)state.receipts.delete(key);
 const receipt={digest};state.receipts.set(sequence,receipt);
 try{return await dispatch();}catch(error){receipt.error={status:error.status||503,message:error.status?String(error.message).slice(0,1024):'Shared world is temporarily unavailable.',...(error.code==='WORLD_BUSY'?{code:error.code}:{})};throw error;}
 }
}
