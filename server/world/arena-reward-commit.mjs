import {serializeLife,commitLife} from './life-transactions.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {ARENA_CHOSEN} from '../../src/config/engine-chosen-arena.js';

// Battle outcome and reward amounts are frozen by the controller, never rerolled
// on storage failure. A receipt is written atomically with every awarded field.
// Durable outcomes (DK Square / Draco / Lost Horizon): at settlement every present
// participant's frozen outcome is first journaled on its own profile
// (profile.arena.pending, journalArenaOutcome); the award commit below removes that
// entry in the same write that adds the receipt. A host crash or a disconnect
// between the two writes leaves the outcome in storage, and replayArenaOutcomes
// pays it once at the participant's next presence (receipt = replay protection).
const PENDING_CAP=ARENA_CHOSEN.pendingOutcomes??Infinity;   // no cap (f pass: the engine bound 32 had no source)
const sameBattle=reward=>r=>r?.battle===reward.battle;
export async function journalArenaOutcome(world, player, reward) {
  return serializeLife(player, async () => {
    if (world.players.get(player.account) !== player || player.leaving) return null;
    const rec0 = player.profile.arena;
    if (rec0?.receipts?.some(sameBattle(reward)) || rec0?.pending?.some(sameBattle(reward))) return true;
    const profile = structuredClone(player.profile), rec = profile.arena ||= {dp:0,rankScore:0,battles:0,wins:0};
    rec.pending = [...(rec.pending||[]), structuredClone(reward)]; if (Number.isFinite(PENDING_CAP)) rec.pending = rec.pending.slice(-PENDING_CAP);
    await commitLife(world,player,profile,{});
    return true;
  });
}
export async function commitArenaReward(world, player, reward, credit) {
  return serializeLife(player, async () => {
    if (world.players.get(player.account) !== player || player.leaving) return null;
    const prior = player.profile.arena?.receipts?.find(sameBattle(reward)), queued = player.profile.arena?.pending?.some(sameBattle(reward));
    if (prior && !queued) return structuredClone(prior);
    const profile = structuredClone(player.profile), actor = {...player,profile}, events = [];
    const rec = profile.arena ||= {dp:0,rankScore:0,battles:0,wins:0};
    if (rec.pending) { rec.pending = rec.pending.filter(r => !sameBattle(reward)(r)); if (!rec.pending.length) delete rec.pending; }
    // Already paid (receipt) but still journaled: retire the journal entry only.
    if (prior) { await commitLife(world,player,profile,{}); return structuredClone(prior); }
    const facade = Object.create(world);
    facade.changed = () => {};
    facade.emit = (map,event) => events.push([map,event]);
    rec.dp = (Number(rec.dp)||0) + reward.dpGain;
    rec.rankScore = (Number(rec.rankScore)||0) + reward.rankScore;
    rec.battles = (Number(rec.battles)||0) + 1;
    if (reward.outcome === 'win') rec.wins = (Number(rec.wins)||0) + 1;
    const inv = world.data.itemDB ? new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}) : null;
    const items = []; let bagFull = false;
    for (const [index,count] of [[reward.coinIndex,reward.coin],[reward.proofIndex,reward.proof]]) {
      if (!(count > 0)) continue;
      if (inv?.add(index,count)) items.push({index,count}); else bagFull = true;
    }
    if (reward.exp > 0) facade.grantProgress?.(actor,reward.exp,0);
    credit?.(facade,actor);
    const receipt = {...reward,dp:rec.dp,items,bagFull};
    rec.receipts = [...(rec.receipts||[]),receipt].slice(-128);
    const committed = await commitLife(world,player,profile,{rewardProgress:true,
      stats:actor.stats,vitalDeltas:{hp:Math.max(0,(actor.maxHp||0)-(player.maxHp||0)),mp:Math.max(0,(actor.stats?.maxMp||0)-(player.stats?.maxMp||0))}});
    // A replaced actor never receives the old session's notifications.
    if (world.players.get(player.account) === player && !player.leaving) {
      for (const [map,event] of [...events,...(committed?.notices||[])]) {
        if(event.type!=='levelup'||event.level>(committed?.concurrentLevel||0))world.emit(map,event);
      }
    }
    return receipt;
  });
}
/** DP decides the held DK tier (dktierbuff options in the stat pipeline): rebuild derived stats after a DP change. */
export function refreshArenaStats(world,p){
  if(!world.data?.stats||world.players.get(p.account)!==p||p.leaving)return;
  const buffs=[...(p.profile.buffs||[]),...(p._skills?.engine.passiveEntries()||[])];
  p.stats=world.data.stats({...p.profile,buffs},p,world.now());p.maxHp=p.stats.maxHp;
  p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp||0,p.stats.maxMp||0);world.changed(p);
}
/** Pay journaled outcomes the live controller no longer owns (host restart, disconnect before the award write).
 *  owns(reward): this venue's entry; live(reward, p): the in-memory settlement still owns it; credit(reward) -> credit fn;
 *  done(p, receipt, reward): publish the paid result. Once per second, one entry per participant at a time. */
export function replayArenaOutcomes(world,key,{owns,live,credit,done}){
  const now=world.now(),at=world._arenaReplayAt||={};if(now<(at[key]||0))return;at[key]=now+1000;
  for(const p of world.players?.values()||[]){
    const pending=p.profile?.arena?.pending;if(!pending?.length||p.leaving||p.sceneTransition||p._arenaReplaying?.has(key))continue;
    const reward=pending.find(r=>owns(r)&&!live(r,p));if(!reward)continue;
    (p._arenaReplaying||=new Set()).add(key);
    void commitArenaReward(world,p,reward,credit(reward)).then(r=>{if(r)done?.(p,r,reward);}).catch(()=>{}).finally(()=>p._arenaReplaying.delete(key));
  }
}
