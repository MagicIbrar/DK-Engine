import {Equipment,emptyEquip,S} from '../../src/systems/items/equip.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {npcPlacements,nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {upgradeRow,supportOk,upgradeRate} from '../../src/systems/items/ui/upgrade.js';
import {premiumUpgradeBonus} from './premium-service.mjs';
import {createQuestContext} from './quests.mjs';
import {npcNativeRoute,npcRoutingEdges} from './npc-routing.mjs';
import {protectedNpcEquipmentUids} from './npc-equipment-ownership.mjs';
import {mapFor} from './scene.mjs';
import {createNpcApproachCache} from './npc-navigation.mjs';
import {gearGemChoices,maximumGearOptions} from '../../src/systems/gm/gear-set.js';
import {socketable} from '../../src/systems/items/ui/socket.js';
import {documentedSocketLimit} from '../../src/systems/items/socket-capacity.js';

// ENGINE-CHOSEN population/build preferences, never native balance claims. Native
// item records, option pools, requirements, models and services remain authoritative.
export const NPC_BUILD_POLICY=Object.freeze({levelOffsets:[0,-3,2,-6,5,-1,7,-4,1,-8,4,-2,6,-5,3],levelRadius:8,
 tiers:{modest:{levelFraction:1,refinement:0,grade:'normal',sockets:0},balanced:{levelFraction:1,refinement:3,grade:'magic',sockets:1},strong:{levelFraction:1,refinement:6,grade:'noble',sockets:2},insane:{levelFraction:1,refinement:9,grade:'divine',sockets:4}}});
const startingSlots=[S.weapon,S.offhand,S.helmet,S.armor,S.pants,S.glove,S.boots,S.acc1,S.acc2,S.acc3,S.acc4,S.wing,S.earL,S.earR,S.brace1,S.brace2,S.belt,S.emblem,S.force1,S.force2,S.talisman];
const statKeys=['str','dex','con','spr'];
const ownNpc=p=>p?.authority==='server'&&p.npcPlayer===true;
const equipment=(profile,db)=>new Equipment({db,game:{save:profile}});
const active=(item,now)=>!item.expiresAt||item.expiresAt>now;
const catalogCache=new WeakMap();
const serviceApproaches=new WeakMap();
function catalog(db){if(!catalogCache.has(db))catalogCache.set(db,Object.keys(db.items).map(k=>db.def(k)).filter(d=>d&&Number(d.index)<900000000));return catalogCache.get(db);}
const activityCache=new WeakMap();
/** Native ordinary travel edges. Paid/unlock-dependent edges are intentions only;
 * callers walk to `at` and submit `action` to the existing authority. */
export function npcNativeTravelEdges(data,from){
 const valid=to=>{const mode=data.eventData?.modeOf(to);return Number.isInteger(to)&&data.mapRow?.(to)&&!data.requiresInstance?.(to)&&(!mode||mode.endsWith('Lobby'))&&!['siege','arena'].includes(data.dungeonCatalog?.maps?.[to]?.kind);};
 const edges=(data.gates?.(from)||[]).filter(g=>valid(Number(g.to?.map))).map(g=>({kind:'gate',from,to:Number(g.to.map),box:structuredClone(g.box),destination:structuredClone(g.to)}));
 const tr=data.travelData;if(!tr)return edges;
 for(const row of data.progression?.npcs?.placements?.[from]?.rows||[]){const npcIndex=Number(row[0]),at={map:from,x:Number(row[1]),z:Number(row[2]),npc:npcIndex};
  for(const [job,tableValue]of data.progression.npcs.npcs[npcIndex]?.jobs||[]){const type=Number(job),table=Number(tableValue);
   if([2,42].includes(type)){const definition=type===2?tr.teleports?.[table]:tr.skyTeleports?.find(t=>Number(t.id)===table);
    for(const unit of definition?.units||[]){const location=tr.locations?.[unit.location],to=Number(location?.[0]),cost=Number(unit.cost);if(!valid(to)||!Number.isFinite(cost)||cost<0)continue;
     edges.push({kind:'npctravel',from,to,at,action:{type:'npctravel',npcIndex,operation:type===2?'teleport':'sky',table,unit:Number(unit.unit)},cost,minimumLevel:Number(unit.level)||1,requirements:{...(unit.skyQuest||definition.skyQuest?{skyQuest:unit.skyQuest||definition.skyQuest}:{})},destination:{map:to,x:Number(location[1])+.5,z:Number(location[2])+.5}});
    }
   }else if(type===16&&Number(data.mapRow(from)?.IsPortal)!==0){for(const portal of tr.portals||[]){const to=Number(portal.map),arrival=tr.portalArrivals?.find(r=>Number(r.map)===to);if(!valid(to)||!arrival)continue;
    edges.push({kind:'npctravel',from,to,at,action:{type:'npctravel',npcIndex,operation:'portal',table,map:to},cost:0,minimumLevel:1,requirements:{},destination:{map:to,x:Number(arrival.x)+.5,z:Number(arrival.y)+.5}});}}
  }
 }
 return edges;
}
/** Actual offered resident quests and placed event officers reachable by ordinary native travel.
 * A goal describes an intention, not admission: inventory, party and quest prerequisites
 * must still pass the ordinary authority when the actor gets there. No tickets are seeded. */
export function npcNativeActivities(data,map){
 const start=Number(map?.index??map);if(!Number.isInteger(start)||!data.mapRow?.(start))return [];
 if(!activityCache.has(data))activityCache.set(data,new Map());const cache=activityCache.get(data);if(cache.has(start))return structuredClone(cache.get(start));
 const placements=data.progression?.npcs?.placements||{},npcs=data.progression?.npcs?.npcs||{};
 // Test only actual native admission/teleport thresholds. Routing chooses the
 // executable ordinary field/DK services, never promotes an event instance.
 const thresholds=[...new Set([1,...Object.keys(placements).map(m=>Number(data.mapRow(Number(m))?.LimitMinLevel)||1),...Object.keys(placements).flatMap(m=>npcRoutingEdges(data,Number(m)).map(e=>e.level||1))])].sort((a,b)=>a-b);
 const goals=[],placed=(at,npc)=>(placements[at]?.rows||[]).find(r=>Number(r[0])===Number(npc));
 const provenance={policy:'ENGINE-CHOSEN',source:'native offered quest/event catalogs, original NPC placements, ordinary gates and NPC travel services',originMap:start,maxGates:12};
 for(const q of Object.values(data.progression?.quests?.quests||{})){
  if(!q.offered||q.giver?.unplaced||q.tags?.some(t=>['event','exchange','teleport'].includes(t))||!['kill','killOnMap','collect','talk','useSkill'].includes(q.kind))continue;
  const officer=Number(q.giver?.npc),row=placed(start,officer);if(!row)continue;
  const min=Number(q.level?.[0]),max=Number(q.level?.[1])||data.maxLevel;if(!Number.isFinite(min)||min<1||max<min)continue;
  goals.push({kind:'quest',questId:Number(q.id),officer,officerMap:start,map:start,levels:[min,max],nativeLevels:structuredClone(q.level),at:{map:start,x:Number(row[1]),z:Number(row[2]),npc:officer},route:[],requirements:structuredClone(q.require||{}),provenance:{...provenance,table:'progression.quests',levelSource:'quest.level'}});
 }
 for(const [mode,definition]of Object.entries(data.eventData?.modes||{})){
  if(!['deadFront','iceCastle'].includes(mode))continue;
  for(const tier of definition.tiers||[])for(const event of tier.maps||[]){
   const eventMap=Number(event.map),field=data.eventData.field(mode,eventMap);if(!field)continue;
   const bands=[event.registrationLevel||event.level,field.entryLevel||field.level,event.entryLevel||event.level].filter(Array.isArray);if(!bands.length)continue;
   for(const officer of event.officers||[])for(const [key,placement]of Object.entries(placements)){
    const officerMap=Number(key),row=placement.rows?.find(r=>Number(r[0])===Number(officer));if(!row||!npcs[officer]?.jobs?.some(([type,index])=>Number(type)===(mode==='deadFront'?38:99)&&Number(index)===eventMap))continue;
    const bandMin=Math.max(1,...bands.map(b=>Number(b[0])||1),Number(data.mapRow(start)?.LimitMinLevel)||1),bandMax=Math.min(data.maxLevel,...bands.map(b=>Number(b[1])||data.maxLevel),Number(data.mapRow(start)?.LimitMaxLevel)||data.maxLevel);
    let route=null;for(const level of [bandMin,...thresholds.filter(l=>l>bandMin&&l<=bandMax)]){if(level>bandMax)continue;const found=npcNativeRoute(data,start,officerMap,{level,dil:Infinity});if(found){route=found.map(e=>({...e,kind:e.action.type==='travel'?'gate':e.action.type,minimumLevel:e.level||1,destination:e.arrival}));break;}}if(!route)continue;
    const admissions=[start,...route.map(r=>r.to)].map(m=>data.mapRow(m));
    const min=Math.max(1,...bands.map(b=>Number(b[0])||1),...route.map(r=>r.minimumLevel||1),...admissions.map(r=>Number(r.LimitMinLevel)||1)),max=Math.min(data.maxLevel,...bands.map(b=>Number(b[1])||data.maxLevel),...admissions.map(r=>Number(r.LimitMaxLevel)||data.maxLevel));if(max<min)continue;
    goals.push({kind:'event',eventId:eventMap,eventMap,mode,tier:tier.tier,officer:Number(officer),officerMap,map:officerMap,levels:[min,max],nativeLevels:structuredClone(bands),at:{map:officerMap,x:Number(row[1]),z:Number(row[2]),npc:Number(officer)},route:structuredClone(route),requirements:{ticket:Number(mode==='deadFront'?tier.items?.mapOfFortress:tier.items?.castleKey)||null,party:true,...(route.some(r=>r.action.operation==='dkenter')?{leavesFieldParty:true,requiredChannel:route.findLast(r=>r.action.operation==='dkenter').arrival.channel}:{}),travelDil:route.reduce((n,r)=>n+(r.cost||0),0),travel:route.filter(r=>r.kind!=='gate').map(r=>({action:r.action,cost:r.cost,...r.requirements}))},provenance:{...provenance,table:'events',levelSource:'intersection of native registration, entry and route map admission'}});
   }
  }
 }
 goals.sort((a,b)=>a.kind.localeCompare(b.kind)||a.levels[0]-b.levels[0]||(a.questId??a.eventId)-(b.questId??b.eventId)||a.officerMap-b.officerMap);cache.set(start,goals);return structuredClone(goals);
}
/** ENGINE-CHOSEN common local band, using actual native spawn/quest levels. */
export function npcLevelBand(data,{map,quests=data.progression?.quests}={}){
 if(!map)return null;
 const native=data.mapRow?.(map.index),min=Math.max(1,Number(native?.LimitMinLevel)||Number(map.level?.[0])||1),max=Math.min(data.maxLevel,Number(native?.LimitMaxLevel)||Number(map.level?.[1])||data.maxLevel);
 const actors=[...(map.monsters?.values()||[])].filter(m=>!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&Number(m.def.exp)>0&&Number.isFinite(m.respawnSec));
 let levels=actors.map(m=>Number(m.def.level)).filter(l=>l>=min&&l<=max).sort((a,b)=>a-b),source='native ordinary spawns';
 if(levels.length){const lo=levels[Math.floor((levels.length-1)*.1)],hi=levels[Math.ceil((levels.length-1)*.9)];levels=levels.filter(l=>l>=lo&&l<=hi);}
 else{source='native quest level bands';levels=Object.values(quests?.quests||{}).filter(q=>q.offered&&(Number(q.map)===map.index||Number(q.giver?.map)===map.index)&&!q.giver?.unplaced&&!q.tags?.some(t=>['event','exchange','teleport'].includes(t))&&['kill','killOnMap','collect','talk','useSkill'].includes(q.kind)).map(q=>Number(q.level?.[0])).filter(l=>l>=min&&l<=max).sort((a,b)=>a-b);}
 const candidates=[...new Set(levels)];return candidates.length?{policy:'ENGINE-CHOSEN',source,map:map.index,min:candidates[0],max:candidates.at(-1),candidates}:null;
}
export function npcPopulationChoice(data,anchorLevel,serial=0,mapContext){
 const classes=data.classesFile.classes,ordinal=Math.max(0,Math.floor(serial)),cls=classes[ordinal%classes.length];
 const offset=NPC_BUILD_POLICY.levelOffsets[ordinal%NPC_BUILD_POLICY.levelOffsets.length];
 let level=Math.max(1,Math.min(data.maxLevel,Number(anchorLevel)+offset));const levelBand=npcLevelBand(data,mapContext);let goal;
 if(levelBand){const candidates=levelBand.candidates;level=candidates[(ordinal+3*Math.floor(ordinal/data.classesFile.classes.length))%candidates.length];}
 // ENGINE-CHOSEN hub mixture: every third actor keeps the common local farm band;
 // other actors pursue actual offered veteran quest/event bands. Fields keep their local band.
 const hubRow=mapContext?.map&&data.mapRow?.(mapContext.map.index);
 if(Array.isArray(mapContext?.activities)&&Number(hubRow?.PeaceZone)===1&&Number(hubRow?.PcStore)===1&&ordinal%3!==0){
  // The caller already supplied this map's validated native activity set.
  // Rebuilding and cloning the full catalog for every resident stalls joins.
  const offered=mapContext.activities;
  const veterans=offered.filter(g=>g.levels[0]>(levelBand?.max||1)),events=veterans.filter(g=>g.kind==='event'),quests=veterans.filter(g=>g.kind==='quest');
  const pool=ordinal%3===2&&events.length?events:quests.length?quests:veterans;
  const levels=[...new Set(pool.map(g=>g.levels[0]))];if(levels.length){const chosenLevel=levels[(Math.floor(ordinal/3)+Math.floor(ordinal/classes.length))%levels.length],choices=pool.filter(g=>g.levels[0]===chosenLevel);goal=structuredClone(choices[Math.floor(ordinal/Math.max(1,levels.length))%choices.length]);level=chosenLevel;}
 }
 if(mapContext?.map){const map=mapContext.map,row=data.mapRow?.(map.index);level=Math.max(Number(row?.LimitMinLevel)||map.level?.[0]||1,Math.min(Number(row?.LimitMaxLevel)||map.level?.[1]||data.maxLevel,level));}
 // First cohort spans all classes; later cohorts also vary each class's social/build preferences.
 const social=['social','solo','outlaw'][(ordinal+Math.floor(ordinal/3)+Math.floor(ordinal/classes.length))%3],gear=['balanced','modest','strong','balanced','insane'][(ordinal+Math.floor(ordinal/classes.length))%5];
 // Experience varies within a map, but a fresh low-level character cannot
 // behave like a veteran. The level is the native admitted level above; the
 // serial only chooses a stable personality within its experience band.
 const aptitude=(ordinal%classes.length+Math.floor(ordinal/classes.length))%4;
 const pvpSkill=(level<40?['novice','regular','novice','regular']:level<100?['regular','novice','expert','elite']:level<150?['expert','regular','elite','expert']:['elite','expert','elite','expert'])[aptitude];
 const cosmetic=(ordinal*7+3)%4===0;
 return {classIndex:cls.index,level,...(goal?{levelBand:{policy:'ENGINE-CHOSEN',source:'native hub activity requirements',map:mapContext.map.index,min:goal.levels[0],max:goal.levels[1],candidates:[level]}}:levelBand?{levelBand}:{}),...(goal?{goal}:{}),traits:{policy:'ENGINE-CHOSEN',social,gear,pvpSkill,cosmetic,cooperative:social==='social',affiliation:social==='social'?'adventurer':social==='solo'?'independent':'outlaw',risk:social==='outlaw'?'aggressive':'ordinary'}};
}
export function npcPointBudget(data,level){return {statPoints:(level-1)*Number(data.classesFile.statPointsPerLevel||data.classesFile.formula.byStatPointPerLevel),skillPoints:level-1};}
function reachable(data,profile,def,planned=profile.stats){
 const next={...planned};for(const stat of ['str','dex','spr'])next[stat]=Math.max(Number(next[stat])||0,Number(def['req'+stat[0].toUpperCase()+stat.slice(1)])||0);
 if(statKeys.some(k=>next[k]>data.statCap(profile.classIndex,k)))return null;
 const cost=statKeys.reduce((n,k)=>n+Math.max(0,next[k]-profile.stats[k]),0);
 return cost<=(profile.statPoints||0)?next:null;
}
const equipmentReadSnapshot=(profile,db)=>equipment({classIndex:profile.classIndex,level:profile.level,equip:structuredClone(profile.equip)},db);
function roleOf(data,profile,eq=equipmentReadSnapshot(profile,data.itemDB)){
 const cls=data.classDef(profile.classIndex),db=data.itemDB,def=db.def(eq.get(S.weapon)?.itemIndex)||db.def(profile.inventory?.find(i=>db.def(i.itemIndex)?.slot==='weapon')?.itemIndex)||db.def(cls.weapon?.itemIndex);
 const ratios=cls.stats.damageRatios;
 const source=def?{melee:def.melee,ranged:def.ranged,magic:def.magic}:cls.weapon?.stats?{melee:[cls.weapon.stats.meleeMax],ranged:[cls.weapon.stats.rangeMax],magic:[cls.weapon.stats.magicMax]}:{melee:[ratios.strMelee],ranged:[ratios.dexRange],magic:[ratios.sprMagic]};
 return Object.entries(source).sort((a,b)=>Math.max(...(b[1]||[0]))-Math.max(...(a[1]||[0])))[0]?.[0]||'melee';
}
// ENGINE-CHOSEN utility weights prefer native offense, survivability and health.
function utility(stats,role){
 return Number(stats[role==='ranged'?'rangeMax':role==='magic'?'magicMax':'meleeMax']||0)+Number(stats.defense||0)+Number(stats.maxHp||0)/20+Number(stats.maxMp||0)/40+Number(stats.maxShield||0)/40
  +['critRate','blockRate','guardRate','magicResist','hitRate','dodge','pvpDamage','pvpDefense','bossDamage','expBonus','dropBonus','dilBonus'].reduce((n,k)=>n+(Number(stats[k])||0),0)
  +Object.values(stats.resist||{}).reduce((n,v)=>n+(Number(v)||0)/10,0)+Object.values(stats.elementDamage||{}).reduce((n,v)=>n+(Number(v)||0),0)
  +(1-Number(stats.cooldownMul??1))*100+(1-Number(stats.castMul??1))*100+(1-Number(stats.mpCostMul??1))*100;
}
function usableModel(eq,def,slot){
 if(def.slot==='weapon'&&slot===S.weapon){const rule=eq.db.weaponRule(def);if(!rule||!eq.canStyle(rule.style)&&!eq.canStyle(rule.altStyle))return false;}
 return !['weapon','helmet','armor','pants','glove','boots','wing','costume'].includes(def.slot)||!!eq.assetFor(def.index);
}
/** Native eligibility and actual stat comparison for an owned/offered item.
 * Utility is an ENGINE-CHOSEN preference, never an added combat statistic. */
export function npcEquipmentBenefit(world,p,item,{slot,prepared}={}){
 const db=world.data.itemDB,profile=p.profile,def=db?.def(item?.itemIndex);if(!def?.slot||!active(item,world.now()))return null;
  const eq=prepared?.eq||equipmentReadSnapshot(profile,db),target=reachable(world.data,profile,def),role=prepared?.role||roleOf(world.data,profile,eq);if(!target)return null;
 let best=null;for(const s of eq.slotsFor(def).filter(s=>s<100&&(slot==null||s===slot))){
  if(!usableModel(eq,def,s)||!eq.check(item,s,target).ok)continue;
  const candidate=world.data.stats.cloneProbeProfile?.(profile)??structuredClone(profile),testEq=equipment(candidate,db);testEq.place({...structuredClone(item),uid:item.uid||'npc-native-offer-probe'},s);
  // A dormant saved profile (merchant-priority advisory) has no live actor stats yet: derive its current stats from the profile.
  const benefit=utility(world.data.stats(candidate,p,world.now()),role)-utility(p.stats||world.data.stats(profile,p,world.now()),role);
  if(!best||benefit>best.benefit)best={item,slot:s,target,benefit};
 }return best;
}
export function npcOwnedBuildPlan(world,p,prepared){
 if(!ownNpc(p.profile)||p.dead||!world.data.itemDB)return null;const eq=prepared?.eq||equipmentReadSnapshot(p.profile,world.data.itemDB);let best=null;
  // This plan only reads the current equipment and weapon role. Reuse their
  // private snapshot across the candidates; each stat probe still gets its own
  // profile copy before placing an item.
  prepared||={eq,role:roleOf(world.data,p.profile,eq)};
 const marketStock=new Set([...(p.profile.npcMarketShowcase?.version===1?p.profile.npcMarketShowcase.uids:[]),...(p.profile.npcInitialMarketStock?.version===1?p.profile.npcInitialMarketStock.uids:[])]);
 for(const item of p.profile.inventory||[]){if(marketStock.has(item.uid))continue;
  for(const slot of eq.slotsFor(world.data.itemDB.def(item.itemIndex)).filter(s=>s<100)){
    const candidate=npcEquipmentBenefit(world,p,item,{slot,prepared});if(!candidate)continue;
   if((candidate.benefit>0||candidate.benefit===0&&!eq.get(slot)&&item.npcStartingStock==='ENGINE-CHOSEN')&&(!best||candidate.benefit>best.benefit))best=candidate;
  }
 }return best;
}
/** Read-only area context, reusing the population's native level-band source.
 * Existing characters keep their actual level; this describes, never resets it. */
export function npcAreaBuildContext(data,profile,{map,goal=profile.npcSeed?.initialGoal}={}){
 const row=data.mapRow?.(map?.index??profile.map),levels=[Math.max(1,Number(row?.LimitMinLevel)||1),Math.min(data.maxLevel,Number(row?.LimitMaxLevel)||data.maxLevel)];
 return {policy:'ENGINE-CHOSEN',map:map?.index??profile.map,level:profile.level,mapLevels:levels,levelBand:map?npcLevelBand(data,{map}):profile.npcSeed?.levelBand||null,goal:goal?structuredClone(goal):null,starterMaxRequirement:Math.min(Number(profile.level)||1,levels[1]),initialRefinement:(NPC_BUILD_POLICY.tiers[profile.npcTraits?.gear]||NPC_BUILD_POLICY.tiers.balanced).refinement,progression:'owned native eligible items and authored next/upgrade rows; no starting-tier end cap'};
}
/** Actual placed activity/service anchors only. The director must separately
 * validate a reachable same-scene spawn approach from its human anchor. */
export function npcNativeActivityAnchors(data,map,{goal}={}){
 const index=Number(map?.index??map),catalog=data.progression?.npcs,rows=catalog?.placements?.[index]?.rows||[],anchors=[];
 const add=(row,kind,source)=>{const npc=Number(row[0]);if(anchors.some(a=>a.npcIndex===npc&&a.kind===kind))return;anchors.push({kind,npcIndex:npc,at:{map:index,x:Number(row[1]),z:Number(row[2]),npc},jobs:structuredClone(catalog.npcs?.[npc]?.jobs||[]),provenance:{policy:'ENGINE-CHOSEN activity preference',source,placement:'native progression NPC placement'}});};
 if(goal){const row=rows.find(r=>Number(r[0])===Number(goal.officer)&&Number(goal.officerMap)===index);if(row)add(row,goal.kind,'validated native activity officer/giver');
  const first=goal.route?.find(r=>Number(r.from)===index&&r.action?.npcIndex);if(first){const row=rows.find(r=>Number(r[0])===Number(first.action.npcIndex));if(row)add(row,'travel','first native service of activity route');}}
 for(const row of rows){const jobs=catalog.npcs?.[Number(row[0])]?.jobs||[];if(jobs.some(([type])=>[2,16,42,96].includes(Number(type))))add(row,'travel','native placed teleport/portal/sky/DK-entry job');else if(jobs.some(([type])=>[38,48,99].includes(Number(type))))add(row,'event','native placed event/officer job');}
 return anchors;
}
function itemWeight(db,def,role){
 const damage=def[role==='ranged'?'ranged':role==='magic'?'magic':'melee']||[];
 return (Number(damage[1])||0)+(Number(def.def?.[1])||0)+(def.options||[]).reduce((n,[code,value])=>n+(db.optionName(code)?.match(/DAMAGE|DEFENSE|ARMOR|HP_MAX|STAT_/) ? Number(value)||0:0),0);
}
// These are explicitly chosen starting kits for NEW NPCs only. Native item
// capacity/stone compatibility/options define every effect; no live gear grant.
const startingGemCache=new WeakMap();
function startingSockets(db,def,tier){
 if(!tier.sockets||!socketable(def))return [];
 const capacity=documentedSocketLimit(db,def)??(def.socketRates||[]).reduce((n,v,i)=>Number(v)>0?i+1:n,0);
 const count=Math.min(4,tier.sockets,Math.max(0,capacity));if(!count)return [];
 if(!startingGemCache.has(db))startingGemCache.set(db,new Map());const cache=startingGemCache.get(db);
 if(!cache.has(def.index))cache.set(def.index,gearGemChoices(db,def.index,'monster'));
 const choices=cache.get(def.index);if(!choices.length)return [];
 const stone=choices[tier.grade==='divine'?0:tier.grade==='noble'?Math.min(1,choices.length-1):Math.floor((choices.length-1)/2)].index;
 return Array(count).fill(stone);
}
/** Only call on a NEW, unpersisted private NPC. This stock is never replenished. */
export function seedNpcStartingStock(profile,data,{serial=0,now=Date.now,random=Math.random,traits=profile.npcTraits||npcPopulationChoice(data,profile.level,serial).traits}={}){
 if(!ownNpc(profile))throw Error('NPC starting stock requires a private server NPC profile.');
 if(profile.npcSeed?.stock||profile.inventory?.length||Object.keys(profile.equip?.items||{}).length)throw Error('NPC starting stock can only be created once on an empty character.');
 const db=data.itemDB;if(!db)return [];db.T??=data.itemUseData?.tables;
 const tier=NPC_BUILD_POLICY.tiers[traits.gear]||NPC_BUILD_POLICY.tiers.balanced,limit=Math.max(1,npcAreaBuildContext(data,profile).starterMaxRequirement);
 profile.npcTraits=structuredClone(traits);profile.equip=emptyEquip();profile.inventory||=[];
 const inv=new AuthoritativeInventory(profile,db,{now,random}),probe=structuredClone(profile),eq=equipment(probe,db),cls=data.classDef(profile.classIndex);
 let planned={...profile.stats};const chosen=[],role=roleOf(data,profile);
 // Native basic armlet/belt enhancement series have price0. Their authored
 // prev/next chain is an ordinary gear basis; no purchase value is invented.
 // Only the strongest fresh profiles may select the native endgame families.
 // Their ordinary level, class, point, item and socket requirements still apply.
 const allowedRanks=traits.gear==='insane'?[0,10,12,13,14,15]:[0];
 const allowed=def=>allowedRanks.includes(def.rank)&&!def.period&&!def.cash&&def.npcSell!==0&&(def.price>0||['bracelet','belt'].includes(def.slot)&&!!(def.prev||def.next))&&!def.eventType&&def.reqLv<=limit&&(!def.maxLv||profile.level<=def.maxLv)&&((Number(def.classMask)>>>profile.classIndex)&1)&&Number(def.itemLv||0)<=tier.refinement;
 const defs=catalog(db).filter(allowed),weaponCodes=[...new Set(defs.filter(d=>d.slot==='weapon'&&eq.canStyle(db.weaponRule(d)?.style)).map(d=>d.code))].sort((a,b)=>a-b);
 // Use the class's actual native weapon family in every cohort. Rotating
 // styles by roster slot made high-level armor appear beside a starter dagger.
 const weaponCode=weaponCodes.includes(cls.weapon?.code)?cls.weapon.code:weaponCodes[0];
 // Synchronous per-character metadata only: slots/styles/models and this fixed
 // role do not depend on the evolving planned points or equipped probe items.
 // Actual reachable/equip/inventory/random decisions below remain live.
 const groups=new Map(startingSlots.map(slot=>[slot,[]])),weights=new Map();
 const weight=def=>{if(!weights.has(def))weights.set(def,itemWeight(db,def,role));return weights.get(def);};
 for(const def of defs){
  for(const slot of new Set(eq.slotsFor(def)))if(groups.has(slot)&&(slot!==S.weapon||def.code===weaponCode)&&usableModel(eq,def,slot))groups.get(slot).push(def);
 }
 // Bot-only appearance variety may use permanent native wings outside the
 // ordinary shop catalog. Native class, level, slot and model checks still run.
 groups.set(S.wing,catalog(db).filter(def=>def.slot==='wing'&&!def.period&&!def.eventType&&def.reqLv<=limit&&(!def.maxLv||profile.level<=def.maxLv)&&((Number(def.classMask)>>>profile.classIndex)&1)&&usableModel(eq,def,S.wing)));
 for(const slot of startingSlots){
  const ranked=groups.get(slot).sort((a,b)=>b.reqLv-a.reqLv||Number(b.itemLv)-Number(a.itemLv)||weight(b)-weight(a)||a.index-b.index);
  const mixed=serial%2===1&&[S.helmet,S.pants,S.glove,S.boots].includes(slot)&&tier.grade!=='divine';
  const nearby=mixed?ranked.findIndex(d=>d.reqLv<ranked[0]?.reqLv&&d.reqLv>=ranked[0].reqLv-20):-1;
  const offset=slot===S.wing&&ranked.length?Math.floor(random()*ranked.length):nearby>0?nearby:0;
  const candidates=offset?[...ranked.slice(offset),...ranked.slice(0,offset)]:ranked;
  for(const def of candidates){const next=reachable(data,profile,def,planned);if(!next||!eq.check({itemIndex:def.index},slot,next).ok)continue;
   const before=new Set(profile.inventory.map(i=>i.uid));if(!inv.add(def.index,1,{grade:tier.grade,bound:true,roll:tier.grade!=='divine',...(tier.grade==='divine'?{rnd:maximumGearOptions(db,def,'monster',tier.grade)}:{}),sockets:startingSockets(db,def,tier)}))break;
   const item=profile.inventory.find(i=>!before.has(i.uid));if(!item)break;
   item.npcStartingStock='ENGINE-CHOSEN';chosen.push(item.uid);planned=next;probe.stats=next;eq.place(structuredClone(item),slot);break;
  }
 }
 if(traits.cosmetic){
  // Require this native class's own mesh prefix; broad costume masks sometimes
  // point newer classes at an older class's mesh. Those records are skipped.
  const prefix=cls.skeleton?.split('/').at(-1)?.split('.')[0]?.toLowerCase();
  const costumes=catalog(db).filter(d=>d.slot==='costume'&&!d.period&&!d.cash&&!d.eventType&&d.reqLv<=profile.level&&(!d.maxLv||profile.level<=d.maxLv)&&((Number(d.classMask)>>>profile.classIndex)&1)&&eq.check({itemIndex:d.index},S.costume,planned).ok&&db.look(d.index)?.parts?.length&&prefix&&eq.assetFor(d.index)?.mesh?.split('/').at(-1)?.toLowerCase().startsWith(prefix+'_')).sort((a,b)=>a.index-b.index);
  const def=costumes[Math.floor(random()*costumes.length)];
  if(def){const before=new Set(profile.inventory.map(i=>i.uid));if(inv.add(def.index,1,{bound:true,roll:false})){const item=profile.inventory.find(i=>!before.has(i.uid));if(item){item.npcStartingStock='ENGINE-CHOSEN';chosen.push(item.uid);}}}
 }
 profile.npcSeed={...(profile.npcSeed||{}),stock:{policy:'ENGINE-CHOSEN',uids:chosen,level:profile.level,gear:traits.gear}};
 return chosen;
}
/** Existing ENGINE-CHOSEN spare-point rule; fresh query, no cached player state. */
export function npcSpareStatPlan(data,profile,role=roleOf(data,profile)){
 if(!(profile.statPoints>0))return null;
 const main={melee:'str',ranged:'dex',magic:'spr'}[role],stats=profile.stats;
 const base=data.classDef(profile.classIndex).stats.base,targetCon=base.con+Math.floor((profile.level-1)*Number(data.classesFile.statPointsPerLevel)/5),stat=stats.con<targetCon?'con':main;
 const count=Math.min(profile.statPoints,stat==='con'?targetCon-stats.con:profile.statPoints,data.statCap(profile.classIndex,stat)-stats[stat]);
 return count>0?{stat,count}:null;
}
/** One real transaction per turn; never mutate live stats/ownership directly. */
export async function npcBuildStep({world,player:p,act=input=>world.action(p.account,{...input,token:p.token})}){
 if(!ownNpc(p.profile)||p.dead||!world.data.itemDB)return false;
 const db=world.data.itemDB,profile=p.profile,eq=equipmentReadSnapshot(profile,db),role=roleOf(world.data,profile,eq);
 const cosmetic=(profile.inventory||[]).find(i=>i.npcStartingStock==='ENGINE-CHOSEN'&&db.def(i.itemIndex)?.slot==='costume'&&eq.check(i,S.costume,p.stats).ok);
 if(cosmetic&&!eq.get(S.costume)){await act({type:'equip',uid:cosmetic.uid,slot:S.costume});return true;}
 const best=npcOwnedBuildPlan(world,p,{eq,role});
 if(best){for(const stat of statKeys){const count=best.target[stat]-profile.stats[stat];if(count>0){await act({type:'allocate',stat,count});return true;}}
  // Recheck with actual derived stats: allocation bonuses cannot replace ordinary eligibility.
  if(eq.check(best.item,best.slot,p.stats).ok){await act({type:'equip',uid:best.item.uid,slot:best.slot});return true;}
 }
 const spare=npcSpareStatPlan(world.data,profile,role);
 if(spare){await act({type:'allocate',...spare});return true;}
 return false;
}

/** Native service location plus ordinary action; the director can walk to `at`. */
export function npcRefinementPlan(world,p,{uid}={}){
 if(!ownNpc(p.profile)||!world.data.itemDB||!world.data.itemUseData?.tables)return null;
 const db=world.data.itemDB;db.T=world.data.itemUseData.tables;
 const marketStock=new Set([...(p.profile.npcMarketShowcase?.version===1?p.profile.npcMarketShowcase.uids:[]),...(p.profile.npcInitialMarketStock?.version===1?p.profile.npcInitialMarketStock.uids:[])]),eq=equipment(structuredClone(p.profile),db),bag=(p.profile.inventory||[]).filter(i=>active(i,world.now())&&!marketStock.has(i.uid));
 const smiths=npcPlacements(world,p.map).filter(n=>n.roles.includes('ITEMUPGRADE')).sort((a,b)=>Math.hypot(p.x-a.x,p.z-a.z)-Math.hypot(p.x-b.x,p.z-b.z));if(!smiths.length)return null;
 for(const {slot,inst:item}of [...bag.map(inst=>({slot:null,inst})),...eq.worn()]){
  if(uid&&item.uid!==uid)continue;
  const def=db.def(item.itemIndex),next=def&&db.def(def.next);if(!def||!next||!((Number(def.classMask)>>>p.profile.classIndex)&1)||!eq.slotsFor(def).some(s=>usableModel(eq,def,s)&&usableModel(eq,next,s)&&eq.check(item,s,p.stats).ok&&eq.check({itemIndex:next.index},s,p.stats).ok))continue;
  const row=upgradeRow(db,def);if(!row||!Number.isFinite(Number(row.costDil))||Number(row.costDil)<0||p.profile.dil<Number(row.costDil))continue;
  const stone=bag.find(i=>i.uid!==item.uid&&[Number(row.stone1),Number(row.stone2)].includes(i.itemIndex));if(!stone)continue;
  // Same special-Argate binding enforced by dispatchEnhancement for native ranks5/6.
  const special={5:9908,6:9913}[Number(def.rank)],ruin=special&&bag.find(i=>i.uid!==item.uid&&i.uid!==stone.uid&&i.itemIndex===special);if(special&&!ruin)continue;
  const used=new Set([item.uid,stone.uid,ruin?.uid]);
  const sub=i=>db.T.upgradeSubItem?.rows?.find(r=>Number(r.ItemIndex)===i.itemIndex);
  // ENGINE-CHOSEN: spend only owned native compatible chance/protection items.
  const candidates=bag.filter(i=>!used.has(i.uid)&&supportOk(db,db.def(i.itemIndex),def,'rate')===true).sort((a,b)=>Number([9,6,5].includes(Number(sub(b)?.Group)))-Number([9,6,5].includes(Number(sub(a)?.Group)))||Number(db.def(b.itemIndex).upgradeRate||0)-Number(db.def(a.itemIndex).upgradeRate||0));
  const rates=candidates.slice(0,2);for(const i of rates)used.add(i.uid);
  const safe=bag.find(i=>!used.has(i.uid)&&supportOk(db,db.def(i.itemIndex),def,'safe')===true),protectedAttempt=!!safe||rates.some(i=>[6,9].includes(Number(sub(i)?.Group))||Number(sub(i)?.Group)===5&&Number(def.itemLv)>=1),rate=upgradeRate(db,def,rates.map(i=>db.def(i.itemIndex)),premiumUpgradeBonus(world,p.profile));
  // Cautious actors can advance at any authored level with owned protection or
  // native100% success; the persona no longer imposes an equipment-level ceiling.
  if(p.profile.npcTraits?.gear==='modest'&&row.penalty!=='NOT_FAIL'&&!protectedAttempt&&rate<100)continue;
  let approach=serviceApproaches.get(world);if(!approach){approach=createNpcApproachCache(world.now);serviceApproaches.set(world,approach);}const map=mapFor(world,p);
  let destination;for(const smith of smiths){const endpoint=approach(map,p,smith,12);if(endpoint){destination={smith,endpoint};break;}}if(!destination)return null;const {smith,endpoint}=destination;
  const action=slot==null?{type:'upgrade',uid:item.uid,stone:stone.uid,rates:rates.map(i=>i.uid),...(ruin?{ruin:ruin.uid}:{}),...(safe?{safe:safe.uid}:{})}:{type:'unequip',slot};
  return {at:{map:p.map,...endpoint,npc:smith.npcIndex},serviceAt:{map:p.map,x:smith.x,z:smith.z,npc:smith.npcIndex},near:!!nearbyNpc(world,p,{npcIndex:smith.npcIndex,role:'ITEMUPGRADE'}),action,uid:item.uid,stage:slot==null?'refine':'remove',cost:Number(row.costDil),native:{from:def.index,to:next.index,level:def.itemLv,resultLevel:next.itemLv,rank:def.rank,rate,penalty:row.penalty,protected:protectedAttempt},policy:'ENGINE-CHOSEN'};
 }
 return null;
}
/** Sell only unbound, ordinary unusable/duplicate gear; preserve every native quest item and all consumables/materials. */
export function npcSalePlan(world,p,{reservedUids=new Set(),pressure=false}={}){
 if(!ownNpc(p.profile)||!world.data.itemDB)return null;
 const db=world.data.itemDB,c=createQuestContext(world,p),protectedItems=new Set();
 for(const q of Object.values(c?.engine?.db?.quests||world.data.progression?.quests?.quests||{})){
  for(const o of q.objectives||[])if(['collect','item','useItem'].includes(o.kind))for(const t of o.targets||[])protectedItems.add(Number(t.id));
  for(const r of [...(q.requiredItems||[]),...(q.require?.items||[])])for(const id of [].concat(r.itemIndex??r.item??r[0]))protectedItems.add(Number(id));
  for(const reward of [q.rewards,...(q.rewardVariants?.list||[]).map(v=>v.reward||v.rewards||v)])for(const r of reward?.take||[])for(const id of [].concat(r.item))protectedItems.add(Number(id));
 }
 const eq=equipment(structuredClone(p.profile),db),bag=p.profile.inventory||[],protectedUids=protectedNpcEquipmentUids(world,p),marketStock=new Set([...(p.profile.npcMarketShowcase?.version===1?p.profile.npcMarketShowcase.uids:[]),...(p.profile.npcInitialMarketStock?.version===1?p.profile.npcInitialMarketStock.uids:[])]);
 const item=bag.find(i=>{const d=db.def(i.itemIndex);if(reservedUids.has(i.uid)||marketStock.has(i.uid)||!d?.slot||d.rank!==0||i.bound||i.npcStartingStock||p.profile.npcSeed?.stock?.uids?.includes(i.uid)||protectedUids.has(i.uid)||i.expiresAt||d.period||d.npcSell===0||d.trade===0||protectedItems.has(i.itemIndex)||!(d.sell>0||d.price>0))return false;
  if(!((Number(d.classMask)>>>p.profile.classIndex)&1))return true;
  return eq.slotsFor(d).every(slot=>{const worn=eq.get(slot);return worn&&itemWeight(db,db.def(worn.itemIndex),roleOf(world.data,p.profile))>=itemWeight(db,d,roleOf(world.data,p.profile));})&&(pressure||bag.filter(x=>x.itemIndex===i.itemIndex).length>1);
 });if(!item)return null;
 // Currency limit: never sell into a capped wallet (the excess would simply be lost).
 {const d=db.def(item.itemIndex);if((Number(p.profile.dil)||0)+Math.max(Number(d?.sell)||0,Number(d?.price)||0)>10_000_000_000)return null;}
 const shops=world.data.shopData?.shops,locations=[];
 for(const row of npcPlacements(world,p.map))for(const job of shops?.npcs?.[row.npcIndex]?.jobs||[]){const type=Number(job.jobType),shop=Number(job.shop??job.jobIndex);if(![0,33,43,51,83,102].includes(type)||!shops.shops?.[shop]||!offersOriginalJob(world,row,type,shop))continue;
  const nativeAt=shops.npcs[row.npcIndex].at?.find(([map])=>Number(map)===p.map);if(!row.custom&&!nativeAt)continue;
  const at=row.custom?{x:row.x,z:row.z}:{x:Number(nativeAt[1]),z:Number(nativeAt[2])};locations.push({at:{map:p.map,...at,npc:row.npcIndex},action:{type:'shopsell',uid:item.uid,npcIndex:row.npcIndex,shop},near:Math.hypot(p.x-at.x,p.z-at.z)<=12});
 }
 return locations.sort((a,b)=>Math.hypot(p.x-a.at.x,p.z-a.at.z)-Math.hypot(p.x-b.at.x,p.z-b.at.z))[0]||null;
}

