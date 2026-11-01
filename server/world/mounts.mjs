import {mapFor,sameScene} from './scene.mjs';
import fs from 'node:fs/promises';
import path from 'node:path';
import {MountsData,ACT} from '../../src/systems/mounts/data.js';
import {skillControls} from './skills.mjs';
import {loadPetData} from './pets.mjs';
import {validateLife} from './life-transactions.mjs';
import {assertCombatService} from './niete-services.mjs';
export const MOUNT_SCHEMAS={mount:['token','type','on']};
const deny=text=>{throw Object.assign(new Error(text),{status:400})};
export async function loadMountData(root){return {mountData:JSON.parse(await fs.readFile(path.join(root,'mounts.json'),'utf8')),...await loadPetData(root)}}
function data(world){const d=new MountsData();d.core=world.data.mountData;return d}
function equippedEntry(p){const eq=p.profile.equip,uid=eq?.presets?.[eq.active||0]?.[20];return eq?.presets?(uid?eq.items?.[uid]:null):p.profile.equipment?.vehicle;}
function equipped(p){const e=equippedEntry(p);return Number(e?.itemIndex??e?.index??e)||null}
/** Original riding options; saved vehicleOpt identifies a native table row/level only. */
export function mountedStatOptions(profile,actor,core,now=Date.now()){
 const entry=equippedEntry({profile}),id=Number(entry?.itemIndex??entry?.index??entry);
 if(actor?.mount?.phase!=='on'||actor.dead||!sameScene(actor.mount,actor)||actor.mount.item!==id||entry?.expiresAt&&entry.expiresAt<=now)return [];
 const vehicle=core?.vehicles?.[id];if(!vehicle)return [];
 const out=(vehicle.o||[]).filter(([type])=>type!==43).map(pair=>[...pair]);
 const opt=entry?.vehicleOpt,row=core.vehicleOptions?.find(row=>row.index===opt?.index),level=opt?.level??0;
 if(row?.optionType!=null&&row.optionType!==43&&Number.isInteger(level)&&level>=0&&level<row.values.length){const value=row.values[level];if(Number.isFinite(value))out.push([row.optionType,value]);}
 return out;
}
function refreshStats(world,p){
 if(!world.data.stats)return;
 p.mountedStats=p.mount?.phase==='on';
 if(p._skills?.game?.refreshPlayerStats){p._skills.game.refreshPlayerStats();return;}
 p.stats=world.data.stats(p.profile,p,world.now());p.maxHp=p.stats.maxHp;
 p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp||0,p.stats.maxMp||0);
}
const mapAllows=row=>{const flag=row?.IsVehicle??row?.vehicle??1;return String(flag).trim()===''||Number(flag)!==0;};
const underwater=row=>{const speed=Number(row?.MoveSpeedFactor??row?.speed);return speed>0&&speed<1;};
const expired=(world,p)=>{const e=equippedEntry(p);return !!e?.expiresAt&&e.expiresAt<=world.now();};
function allowed(world,p,d,id){
 const classIndex=Number(p.profile.classIndex)||0;
 if(!d.vehicleLook(id,classIndex)?.mesh||!d.vehicleTable(id)?.skel||!d.row(d.riderTable(id,classIndex),ACT.STAND))deny('Native riding visuals for this transport are unavailable. Choose another mount.');
 const map=mapFor(world,p),row=map?.row||map;
 if(!mapAllows(row))deny('Mounts are unavailable on this map.');
 if(expired(world,p))deny('This mount has expired.');
 if(underwater(row)&&!d.vehicleTable(id)?.rows?.some(r=>r[1]===ACT.SM_MOVE))deny('This mount cannot swim here.');
 if(p.dead)deny('Cannot mount while dead.');
 assertCombatService(world,p);   // guide62: no boarding in battle status (40:108)
 const flags=skillControls(p);if(flags.casting||flags.lock||flags.move)deny('Cannot mount during a skill or status lock.');
 if(p.path.length)deny('Stop moving before summoning a mount.');
 if(p.pet?.phase&&p.pet.phase!=='on')deny('Wait for the current pet action.');
 if(p.transformLook||p.transformed)deny('Cannot mount while transformed.');
 if(p.transUpStage>0&&!Object.values(d.core?.vehicleSkill||{}).some(id=>Number(p.profile.skills?.[id])>0))deny('Boarding mastery is required.');
}
export async function mountCommand(world,p,input){
 if(input.type!=='mount')return false;
 validateLife(input,MOUNT_SCHEMAS);
 if(p.leaving||p.sceneTransition)deny('Wait for the current map or profile save.');
 if(typeof input.on!=='boolean')deny('Choose summon or dismiss.');
 const d=data(world);if(!d.core)deny('Mount data is unavailable.');
 if(p.mount?.phase&&p.mount.phase!=='on')deny('A mount action is already in progress.');
 if(input.on){const id=equipped(p);if(!id||!d.isVehicle(id))deny('Equip a transport item first.');if(p.mount)deny('Already mounted.');allowed(world,p,d,id);p.mount={item:id,phase:'summoning',at:world.now()+d.vehicleDelays(id).start,map:p.map,instanceId:p.instanceId||null,channel:p.channel??0};}
 else {if(!p.mount)deny('No active mount.');p.mount={...p.mount,phase:'dismissing',at:world.now()+d.vehicleDelays(p.mount.item).end};}
 p.path=[];if(!input.on)refreshStats(world,p);world.emit(p.map,{type:'mount',actorId:p.id,mount:mountState(p,world.now())});return true;
}
export function tickMount(world,p){
 // LANE-25: instance/event entries (instances.mjs createInstance, arena, dungeons, races, wars...) set p.mount=null directly;
 // drop the riding options their last refresh baked into p.stats.
 if(!p.mount){if(p.mountedStats)refreshStats(world,p);return;}
 const d=data(world),m=p.mount;
 const row=mapFor(world,p)?.row||mapFor(world,p);
 if(p.dead||!sameScene(m,p)||equipped(p)!==m.item||expired(world,p)||!mapAllows(row)||underwater(row)&&!d.vehicleTable(m.item)?.rows?.some(r=>r[1]===ACT.SM_MOVE)){p.mount=null;if(m.phase==='on')refreshStats(world,p);world.emit(p.map,{type:'mount',actorId:p.id,mount:null});return;}
 if(m.phase!=='on'&&world.now()>=m.at){p.mount=m.phase==='summoning'?{item:m.item,phase:'on',map:p.map,instanceId:p.instanceId||null,channel:p.channel??0}:null;refreshStats(world,p);world.emit(p.map,{type:'mount',actorId:p.id,mount:mountState(p,world.now())});}
}
export function mountState(p,now=Date.now()){return p.mount?{item:p.mount.item,phase:p.mount.phase,remainingMs:Math.max(0,(p.mount.at||0)-now)}:null}
export function mountSpeed(world,p){return p.mount?.phase==='on'?Math.max(.1,1+data(world).vehicleSpeed(p.mount.item)/100):1}
export function mountBusy(p){return !!p.mount&&p.mount.phase!=='on'}
