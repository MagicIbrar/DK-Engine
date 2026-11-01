// Native team guardian / protection stone bricks of the DK Square (map 67) and Draco Desert Battlefield (map 702)
// battles. Native rows: events.json maps[m].bricks [uid, brick, x, z, dir, IsCreate, Revival, RegenCycle] (IsCreate 0 =
// created by the server, Revival 0 = never revived) and bricks[] defs; a stone's `ally` is the squad it belongs to
// (field.csv Squad_AllyType: 1 Miseria, 2 Ricchez, 3 Rebel, 4 Terra). Only another squad's participant may damage a
// stone during the fight; the destroying hit pays dkactionpoint ActionType 3 "Destroy Guardian Stone" (sub mission
// 160:302) through the battle's onDestroyed. Which placement rows stand per venue/rank: src/config/engine-chosen-dk-square.js
// stoneUids and src/config/engine-chosen-arena.js dracoStoneUids (ENGINE-CHOSEN).
// Native stats kept: defaultHP/maxHP, defence_Min/Max and guardRate/guardEfficiency enter the stone's monster row exactly
// as a monster's def/guard rows (the core fixed-object plain hit uses def[0]; skills use the combat.js monster defence
// and guard), damage resist fields as written (absent = 0), AntiStatusRate 100 refuses statuses (skills.mjs), the native
// widthSize x heightSize footprint blocks the instance collision clone while the stone stands (eventBrickFootprintCells,
// the same cells the client Brick blocks). Unapplied (ENGINE-CHOSEN, see the config lines): HPRecovery (the host applies
// no monster/brick HP recovery anywhere and the row carries no period) and the brick exp column (battle rewards are the
// dkactionpoint / activity.csv settlement).
import {eventBrickFootprintCells} from '../../src/systems/events/bricks.js';
const pct=v=>Math.max(0,Math.min(100,Number(v)||0));
export const isTeamStone=m=>!!m?.teamStone;
/** Stone rows for a venue: the native placements of `uids` whose brick def names a squad (ally) and can be targeted. */
export function teamStoneRows(world,map,uids){
 const placed=world.data.eventData?.map?.(map)?.bricks||world.data.eventData?.ev?.maps?.[map]?.bricks||[],out=[];
 for(const uid of uids||[]){
  const row=placed.find(r=>Number(r[0])===Number(uid)),def=row&&world.data.eventData?.brick?.(Number(row[1]));
  if(!row||!def||!(Number(def.ally)>0)||!Number(def.targeting)||!Number(def.isAttackable))continue;
  out.push({uid:Number(row[0]),brick:Number(row[1]),x:Number(row[2]),z:Number(row[3]),dir:Number(row[4]),ally:Number(def.ally),def});
 }
 return out;
}
/** Create the stones in a battle instance at their native placements. squadOfAlly(ally) -> the venue's team index. */
export function spawnTeamStones(world,{battle,instance,rows,squadOfAlly,teamOf,onDestroyed}){
 const scene=instance.scene,col=scene.collision,W=col?.width||scene.width,H=col?.height||scene.height,stones=[];
 for(const row of rows){
  const team=squadOfAlly(row.ally);if(!(team>=0))continue;
  const d=row.def,hp=Number(d.defaultHP)||Number(d.maxHP)||1,id=`stone:${instance.id}:${row.uid}`;
  const cells=eventBrickFootprintCells(instance.map,{uid:row.uid,x:row.x,z:row.z,dir:row.dir},d).filter(([x,z])=>x>=0&&z>=0&&x<W&&z<H).map(([x,z])=>({i:z*W+x,x,z}));
  const m={id,uid:row.uid,teamStone:{battle,team,ally:row.ally,teamOf,onDestroyed,scene},isBrick:true,brickIndex:row.brick,map:instance.map,instanceId:instance.id,channel:0,x:row.x,z:row.z,dir:row.dir,name:d.name,
   hp,maxHp:Number(d.maxHP)||hp,dead:false,targetId:null,respawnAt:Infinity,respawnSec:Infinity,home:{x:row.x,z:row.z},brickDef:d,kind:'monster',objectFootprint:cells,_cells:new Map(cells.map(c=>[c.i,col?.cells?.[c.i]])),
   def:{name:d.name,level:Number(d.level)||1,hp,exp:0,def:[Number(d.defence_Min)||0,Number(d.defence_Max)||Number(d.defence_Min)||0],guard:[Number(d.guardRate)||0,Number(d.guardEfficiency)||0],resist:[],speed:[0,0],money:[0,0,0],role:'object',attackable:true,antiStatusRate:d.raw?.AntiStatusRate,antiKnockBack:Number(d.raw?.AntiKnockBackRate)>=100}};
  if(col?.cells)for(const c of cells)col.cells[c.i]=1;
  scene.monsters.set(id,m);stones.push(m);
 }
 return stones;
}
const release=m=>{const cells=m.teamStone?.scene?.collision?.cells;if(cells&&m._cells){for(const [i,v]of m._cells)cells[i]=v??0;m._cells=null;}};
/** Battle over / instance gone: free the footprints; the stones stay unbreakable (phase) until the scene is dropped. */
export function releaseTeamStones(stones){for(const m of stones||[])release(m);}
/** Authority before any HP change, for plain hits and delayed skill / proc hits: an up participant of another squad,
 *  inside the same battle instance and map, during the fight, on a standing stone of this scene. */
export function teamStoneActive(world,p,m,{lethal=false}={}){
 const s=m?.teamStone;if(!s||m.dead&&!lethal||m._teamStoneCounted||s.scene.monsters.get(m.id)!==m||s.battle.phase!=='fight')return false;
 if(!p||p.dead||p.leaving||world.players?.get(p.account)!==p||p.instanceId!==m.instanceId||p.map!==m.map)return false;
 const team=s.teamOf(p);return team>=0&&team!==s.team;
}
export function teamStoneDamage(world,p,m,amount,kind='melee'){
 if(!teamStoneActive(world,p,m))return 0;
 const d=m.brickDef,typed=kind==='magic'?d.magicResist:kind==='range'?d.rangeDamageResist:d.meleeDamageResist;
 const resist=Math.max(pct(typed),kind==='magic'?0:pct(d.physicalResist));
 const damage=p.gmAuthorized&&p.profile?.gm?.onehit?m.hp:Math.max(0,Math.round((Number(amount)||0)*(100-resist)/100));
 // The accepted hit that may destroy the stone: only this attacker, only when it reaches 0 HP.
 if(damage>0)m._acceptedHit={source:p.id,team:m.teamStone.teamOf(p),hp:m.hp,lethal:damage>=m.hp,at:world.now()};
 return damage;
}
/** The destroying hit: counted once, for the same accepted enemy attacker whose hit was lethal; any other 0 HP
 *  (GM kill-all, a stale or foreign hit) restores the stone. */
export function rewardTeamStone(world,p,m){
 const s=m.teamStone,hit=m._acceptedHit;if(m._teamStoneCounted)return true;
 if(!s||s.scene.monsters.get(m.id)!==m||m.hp>0)return true;
 // restore (never below the true standing HP): the HP seen when the latest accepted hit was resolved, or full HP
 if(!hit?.lethal||hit.source!==p?.id||!teamStoneActive(world,p,m,{lethal:true})){m.dead=false;m.hp=Math.max(1,hit?hit.hp:m.maxHp);m.respawnAt=Infinity;if(hit)m._acceptedHit={...hit,lethal:false};return true;}
 m._teamStoneCounted=true;m.dead=true;m.hp=0;m.targetId=null;m.respawnAt=Infinity;m.destroyedBy=p.id;delete m._acceptedHit;release(m);
 s.onDestroyed?.(world,p,m);
 world.emit(m.map,{type:'stone:destroyed',stoneId:m.id,uid:m.uid,team:s.team,by:p.id,instanceId:m.instanceId});
 return true;
}
/** Public stone rows (battle snapshot). breakable = this viewer may damage it now. */
export function teamStoneSnapshot(stones,viewerTeam){
 return (stones||[]).map(m=>({id:m.id,uid:m.uid,brickIndex:m.brickIndex,x:m.x,z:m.z,dir:m.dir,hp:Math.max(0,Math.round(m.hp)),maxHp:m.maxHp,dead:!!m.dead,team:m.teamStone.team,ally:m.teamStone.ally,
  breakable:!m.dead&&m.teamStone.battle.phase==='fight'&&viewerTeam>=0&&viewerTeam!==m.teamStone.team}));
}
