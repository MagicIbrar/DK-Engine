import {npcSlotsAvailable} from './npc-human-slots.mjs';
import {npcWorkerBudgetCensus} from './npc-worker-budget.mjs';
// Internal reservations complement the ordinary world's final native lease/
// durable CAS checks. They never publish staged actors or replace those checks.
export function createNpcAdmissionBudget(world,{workerPlayers=()=>[],maxWorkers=6}={}){
 const held=new Map();
 const census=()=>npcWorkerBudgetCensus({players:world.players,held,humanReservations:world.npcHumanReservations,workerPlayers:workerPlayers(),capacity:Number.isInteger(world.npcSlotCapacity)?world.npcSlotCapacity:150,maxWorkers});
 const available=(count=1)=>Number.isInteger(count)&&count>=0&&census().available>=count&&npcSlotsAvailable(world,count);
 world.npcPendingAdmissionAccounts=()=>[...held.keys()].filter(account=>!world.players.has(account));
 return {
  available,
  pending:()=>held.size,
  census,
  has:account=>held.has(account),
  reserve(accounts,{role='foreground'}={}){
   if(!['foreground','worker'].includes(role)||!Array.isArray(accounts)||!accounts.length||new Set(accounts).size!==accounts.length||accounts.some(account=>typeof account!=='string'||held.has(account)||world.players.has(account))||!available(accounts.length)||role==='worker'&&census().workerAvailable<accounts.length)return null;
   const ticket={role};for(const account of accounts)held.set(account,ticket);let released=false;
   const release=()=>{if(released)return;released=true;for(const account of accounts)if(held.get(account)===ticket)held.delete(account);};
   release.valid=()=>{const c=census();return !released&&accounts.every(account=>held.get(account)===ticket)&&c.total<=c.capacity&&c.workerUnits<=c.maxWorkers;};
   return release;
  },
 };
}
