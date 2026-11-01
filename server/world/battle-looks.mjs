// Public look rows of a player (core.mjs publicPlayer: battleAppearance(world, p, publicAppearance(p.profile))).
// 1. Weapon appearance (Ian, src/systems/items/weapon-appearance.js): a worn weapon row keeps its `appearance` only while the
//    worn instance's material still matches its type and its timer runs; a run-out or foreign appearance is published as 0.
// 2. Native team appearance of the arena battles (share/arena/changeshape.csv as events.json modes.arena.changeShape) for
//    DK Square (dk-square.mjs lobbies) and the Draco / Lost Horizon battlefields (arena.mjs battles). ENGINE-CHOSEN teamLook
//    (src/config/engine-chosen-dk-square.js): Team = the participant's squad Squad_AllyType, projected only on the PUBLIC
//    appearance rows while the participant is inside its battle instance during the fight and the result wait. The weapon
//    look is the Team 0 appearance material whose value1 is the worn weapon's code (the same material identity as Ian's).
// The profile, its equipment, item instances, options and derived stats are never written: changed rows are copies.
import {teamLookRows} from '../../src/systems/pvp/dksquare-rules.js';
import {activeAppearance,appearanceMaterial} from '../../src/systems/items/weapon-appearance.js';
const SHOWN=new Set(['fight','over']);
const allyIn=(battle,p)=>{
  if(!battle?.teams||!battle.instanceId||p.instanceId!==battle.instanceId||!SHOWN.has(battle.phase))return 0;
  const t=battle.teams.findIndex(ids=>ids.includes(p.id));return t>=0?Number(battle.v?.squads?.[t]?.ally)||0:0;
};
/** The squad ally type whose look p shows now, or 0. */
export function battleLookAlly(world,p){
  if(!p||p.leaving)return 0;
  return allyIn(p.dkSquareId&&world.dkSquares?.get(p.dkSquareId),p)||allyIn(p.arenaId&&world.arenaBattles?.get(p.arenaId),p);
}
/** Worn weapon rows (slots 4 / 5) publish only the running, matching appearance of the worn instance. */
export function publicWeaponLooks(world,p,rows){
  const eq=p?.profile?.equip,preset=eq?.presets?.[eq?.active||0],db=world.data?.itemDB,now=typeof world.now==='function'?world.now():Date.now();
  let out=rows;
  rows.forEach((r,i)=>{
    if((r.slot!==4&&r.slot!==5)||!(Number(r.appearance)>0))return;
    const inst=eq?.items?.[preset?.[r.slot]];
    if(inst&&inst.itemIndex===r.itemIndex&&activeAppearance(db,inst,now)===Number(r.appearance))return;
    if(out===rows)out=rows.slice();
    out[i]={...r,appearance:0,sockets:[...(r.sockets||[])]};
  });
  return out;
}
/** publicAppearance(p.profile) rows -> the rows other players draw (weapon appearance checked, projected team look). */
export function battleAppearance(world,p,rows){
  rows=publicWeaponLooks(world,p,rows);
  const team=battleLookAlly(world,p);if(!team)return rows;
  const db=world.data?.itemDB,weaponCodes={};
  for(const r of rows){if(r.slot!==4&&r.slot!==5)continue;const def=db?.def?.(r.itemIndex);if(def&&Number(def.type)===4)weaponCodes[r.slot]=Number(def.code);}
  return teamLookRows(rows,{team,classIndex:p.profile?.classIndex,weaponCodes},world.data?.eventData?.ev?.modes?.arena?.changeShape,index=>appearanceMaterial(db?.def?.(index)));
}
