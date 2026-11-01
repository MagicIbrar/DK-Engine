// Half Bagi fury gauge on the host (rules: src/systems/skills/fury-rules.js, shared with the offline gauge).
// The skill engine pays a fury skill from p.fury (the actor proxy writes the record) and refuses it while p.fury is short; nothing on
// the host ever raised it, so every fury skill of the class was refused online. p.fury is the one number: hits and hits taken raise
// it, the tick lowers it, a cast spends it, and the owner's own snapshot row carries it (the HUD gauge and the quick-slot grey-out
// read it on the client). Not saved: the offline gauge starts empty each session too.
// Active statuses (p.profile.buffs) scale the passive loss by their native FURY_DPS_CORRECTION_MUL (Fury Control slows it, Self Injury
// turns it into a recharge); the reading is ENGINE-CHOSEN (src/config/engine-chosen-fury.js).
import {FURY_HIT_GAIN,FURY_HURT_GAIN,furyDecay,furyGain,furyLossScale,furyRules} from '../../src/systems/skills/fury-rules.js';

const gaugeOf=(world,p)=>{
 if(p._fury===undefined){
  const raw=world.data?.classDef?.(p.profile?.classIndex)?.stats?.raw,rules=furyRules(raw);
  p._fury=rules?{rules,g:{cur:0,fullAt:null}}:null;
 }
 return p._fury;
};
const maxOf=p=>Math.max(1,Number(p.stats?.maxMp)||0);
const seconds=world=>world.now()/1000;
/** Bring the gauge to what p.fury says now (a cast spent some) before it is changed again. */
const load=(f,p,max)=>{f.g.cur=Math.max(0,Math.min(max,Number(p.fury)||0));if(f.g.cur<max)f.g.fullAt=null;return f.g;};

export function furyEnabled(world,p){return !!gaugeOf(world,p);}
function add(world,p,frac){
 const f=gaugeOf(world,p);if(!f||p.dead)return false;
 const max=maxOf(p),g=load(f,p,max),before=g.cur;
 furyGain(g,max,frac,seconds(world));
 if(g.cur===before)return false;
 p.fury=g.cur;world.changed(p);return true;
}
/** This player's hit landed on a monster. */
export function furyHit(world,p){return add(world,p,FURY_HIT_GAIN);}
/** A monster's hit landed on this player. */
export function furyHurt(world,p){return add(world,p,FURY_HURT_GAIN);}
/** The passive loss, once per world tick; true when the shown (whole) value moved. */
export function tickFury(world,p,dt){
 const f=gaugeOf(world,p);if(!f||p.dead)return false;
 const max=maxOf(p),g=load(f,p,max),scale=furyLossScale(p.profile?.buffs);
 if(!(g.cur>0)&&scale>=0)return false;
 const before=Math.floor(g.cur);
 furyDecay(g,f.rules,max,dt,seconds(world),scale);
 p.fury=g.cur;
 if(Math.floor(g.cur)===before)return false;
 world.changed(p);return true;
}
/** The owner's snapshot value (whole number), or null for a class without the gauge. */
export function furyOf(world,p){
 const f=gaugeOf(world,p);if(!f)return null;
 return Math.floor(Math.max(0,Math.min(maxOf(p),Number(p.fury)||0)));
}
