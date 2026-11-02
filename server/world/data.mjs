import {createServerLists} from './server-lists.mjs';
import {mapDataPaths} from '../../src/formats/spawn.js';
import {MAIL_POSTAGE_DIL} from '../../src/systems/life/mail-rules.js';
import {LEGACY_MAPS,ABSENT_MAPLIST_MAPS,allSynthesisedMaps,legacyMapRow,firstNpcLanding,parseLegacySpawns} from '../../src/world/legacy-maps.js';
import {reconcileMapFolderBindings} from '../../src/world/map-folder-bindings.js';
import {landingOverride} from '../../src/world/map-landing.js';
import {awakeningShieldRows} from '../../src/game/awakening-shield.js';
import {ardecaHeightScope} from './original-map-scope.mjs';
import {loadDungeonData} from './dungeons.mjs';
import {enrichAbsentMaplistDungeonMaps} from '../../src/systems/dungeons/data.js';
import {EventData} from '../../src/systems/events/data.js';
import fs from 'node:fs/promises';
import {existsSync} from 'node:fs';
import path from 'node:path';
import { decodeText, parseCSV } from '../../src/formats/binreader.js';
import { Collision } from '../../src/world/collision.js';
import { PathFinder } from '../../src/world/pathfind.js';
import { deriveStats, statProviders, statPostHooks } from '../../src/game/progression.js';
import { ItemDB } from '../../src/systems/items/db.js';
import { loadWorldItemData, deriveEquipment } from './items.mjs';
import {activePetOptions} from './pets.mjs';
import {dkTierOptions} from '../../src/systems/pvp/dksquare-rules.js';
import {carnivalStatOptions} from '../../src/systems/events/monster-carnival-rules.js';   // Monster Carnival team skill 2 (161:34)
import { loadWorldShopData } from './shops.mjs';
import { loadSkillPacks } from './skills.mjs';
import { createProfilePassivePools } from './passive-pools.mjs';
import { foldSharedStatusStats } from '../../src/game/shared-status-stats.js';
import { loadSkillRootMotion } from '../skill-root-motion.mjs';
import { loadMountData, mountedStatOptions } from './mounts.mjs';
import { loadWorldLootData } from './loot.mjs';
import {loadCustomItems} from './custom-items.mjs';
import {loadItemServiceData} from './item-services-data.mjs';
import {loadLevelCaps,loadAbilityCaps} from './level-caps.mjs';
import {loadConsignmentPolicy} from './consignment.mjs';
import {loadPcRoomRules} from './pcroom.mjs';
import {loadPvpRules} from './pvp.mjs';
import {loadPartyPvpData} from './party-pvp.mjs';
import {loadColosseumData} from './colosseum.mjs';
import {defaultRoots} from './prepared-roots.mjs';

// Only this native derivation owns the smaller private probe copy. Equipment
// placement/expiry edits equip; derivation replaces top-level buffs/equipment.
// Remaining nested inputs are read-only. Extension callbacks may write any
// field, so they and any borrowed/custom stats function retain full isolation.
function nativeProbeStats(stats){
  Object.defineProperty(stats,'cloneProbeProfile',{value:function(profile){
    return this!==stats||statProviders.length||statPostHooks.length
      ? structuredClone(profile)
      : {...profile,equip:structuredClone(profile.equip)};
  }});
  return stats;
}
// Guild Frontier production policy: the shared fixed UTC+1 server week (engine-chosen-guild.js).
import {FRONTIER_CHOSEN} from '../../src/config/engine-chosen-guild.js';
import { Equipment, emptyEquip, S } from '../../src/systems/items/equip.js';
import { createItem, repairLegacyRankOptions } from '../../src/systems/items/model.js';


// ENGINE-CHOSEN reservation: retained collision/path arrays plus bounded heap.
// Header-only metadata is not native actor admission or a measured RSS bound.
// lane-core: Global packs store share/ paths lowercase (share/mapredcell/ardeca_new.mac) while maplist.csv names
// them mixed-case (Ardeca_new.mac). Windows resolves both; Linux threw ENOENT. The exact name wins; the lowercase
// relative path is tried only when the exact file is absent, and never leaves dataRoot.
export function nativeCaseAssetPath(dataRoot,target,exists=existsSync){
 if(exists(target))return target;const root=path.resolve(dataRoot),rel=path.relative(root,target);
 if(!rel||rel.startsWith('..')||path.isAbsolute(rel))return target;const lower=path.join(root,rel.toLowerCase());return exists(lower)?lower:target;
}
export async function nativeMapGeometryForecast(dataRoot,rel,io=fs){
 const root=path.resolve(dataRoot),file=path.resolve(root,String(rel).replace(/\\/g,'/'));
 if(!/^share\/mapredcell\/[^/\\]+\.mac$/i.test(String(rel).replace(/\\/g,'/'))||!file.startsWith(root+path.sep))throw Error('Invalid native collision forecast path');
 const same=(a,b)=>path.resolve(a).toLowerCase()===path.resolve(b).toLowerCase();
 let at=path.dirname(file);const dirs=[];for(;;){dirs.push(at);const parent=path.dirname(at);if(parent===at)break;at=parent;}
 for(const dir of dirs.reverse()){const s=await io.lstat(dir);if(!s.isDirectory()||s.isSymbolicLink()||!same(await io.realpath(dir),dir))throw Error('Nonordinary native collision ancestor');}
 // Prepared Global assets are intentionally hard-linked across cached generations.
 // This forecast only reads the native header; the path, opened handle and file
 // identity are still checked before and after the read. Writable private state
 // continues to require a single-link file in its own storage helpers.
 const regular=s=>s.isFile()&&!s.isSymbolicLink()&&Number.isInteger(s.nlink)&&s.nlink>=1&&Number.isSafeInteger(s.size)&&s.size>=9&&s.size<=134217736;
 const identity=(a,b)=>a.dev===b.dev&&a.ino===b.ino&&a.size===b.size&&a.mtimeMs===b.mtimeMs&&a.ctimeMs===b.ctimeMs;
 const before=await io.lstat(file);if(!regular(before)||!same(await io.realpath(file),file))throw Error('Nonordinary native collision source');
 const h=await io.open(file,'r');try{
  if(!regular(await h.stat())||!identity(before,await h.stat()))throw Error('Native collision source changed');
  const header=Buffer.alloc(8);let n=0;while(n<8){const r=await h.read(header,n,8-n,n);if(!Number.isInteger(r.bytesRead)||r.bytesRead<=0||r.bytesRead>8-n)throw Error('Invalid native collision header');n+=r.bytesRead;}
  const width=header.readUInt32LE(0),height=header.readUInt32LE(4),cells=width*height;
  if(!width||!height||width>8192||height>8192||before.size<8+cells)throw Error('Invalid native collision dimensions');
  const after=await h.stat(),named=await io.lstat(file);if(!regular(after)||!regular(named)||!identity(before,after)||!identity(before,named)||!same(await io.realpath(file),file))throw Error('Native collision source changed');
  return Object.freeze({width,height,cells,reservedBytes:20*cells+2097152});
 }finally{await h.close();}
}
export async function loadWorldData({ dataRoot, gamedataRoot, customItemsFile } = {}) {
  // explicit > DEKARON_DATA / DEKARON_GAMEDATA > the active prepared generation > legacy layout (server/world/prepared-roots.mjs);
  // the effective roots are returned (dataRoot / gamedataRoot) so secondary readers use the same tables
  ({ dataRoot, gamedataRoot } = defaultRoots({ dataRoot, gamedataRoot }));
  const read = async name => JSON.parse(await fs.readFile(path.join(gamedataRoot, name), 'utf8'));
  const [classesFile, monstersFile, lists, travel, exp] = await Promise.all(['classes.json', 'monsters.json', 'gmcommands_lists.json', 'dungeons_travel.json', 'exp.json'].map(read));
  let progression = null, itemDB = null;
  try {
    const [quests, dialogs, boxes, npcs, core, options, looks, styles] = await Promise.all(['quests.json','dialogs.json','boxes.json','npcs.json','items.json','items-options.json','items-looks.json','items-styles.json'].map(read));
    progression = { quests, dialogs, boxes, npcs, monsters: monstersFile };
    itemDB = new ItemDB({ core, options, looks, styles });
  } catch (error) { if (error.code !== 'ENOENT') throw error; }
  // Folder-convention MON_/NPC_: fill maplist holes and replace cross-map misbinds (Global share/map/<index>_*/; e.g. 27/28 wrongly baked to Aquarius).
  reconcileMapFolderBindings(monstersFile, progression?.npcs || { placements: {} }, dataRoot);
  const customLibrary=itemDB?await loadCustomItems(itemDB,{file:customItemsFile}):null;
  let itemUseData=null,shopData=null;
  if(itemDB){
    [itemUseData,shopData]=await Promise.all([loadWorldItemData(gamedataRoot,dataRoot),loadWorldShopData(gamedataRoot)]);
  }
  const skillData=await loadSkillPacks(gamedataRoot,dataRoot);
  const passivePools=createProfilePassivePools(skillData);
  // Skill clips move the caster along their authored root curve (src/systems/skills/root-motion.js): read before any cast.
  const skillRootMotion=await loadSkillRootMotion({dataRoot,gamedataRoot,packs:skillData.skillPacks});
  const mountData=await loadMountData(gamedataRoot);
  const lootData=await loadWorldLootData(gamedataRoot);
  const lifeData=await read('life.json'),partyData=lifeData.party;
  const gradeShieldRows=awakeningShieldRows(lifeData.grade?.grades);   // awakening grade shield (src/game/awakening-shield.js)
  const itemServiceData=await loadItemServiceData(dataRoot);
  const dungeonData=await loadDungeonData(gamedataRoot);enrichAbsentMaplistDungeonMaps(dungeonData.dg,dungeonData.tr);const dungeonCatalog=dungeonData.dg;   // Lane 52: ABSENT_MAPLIST floors (120) wired in code, Global pack untouched
  const eventData=new EventData(await read('events.json'),await read('events_text.json'),await read('events_caps.json'),null,await read('events_effectui.json'));
  const rows = parseCSV(decodeText(await fs.readFile(path.join(dataRoot, 'share/maplist.csv'))));
  const header = rows.shift();
  const rawMaps = new Map(rows.map(row => { const r = Object.fromEntries(header.map((key, i) => [key.trim(), row[i]?.trim()])); return [Number(r.Index), r]; }));
  // SIEGE: siege castles (Zenoa Castle 23 and the other IsSiege maps) load as shared scenes; their admission stays with the
  // siege service (server/world/siege.mjs) because field gates / travel destinations still refuse siege maps.
  // registry landings on blocked cells -> Global's own walkable arrival point (src/world/map-landing.js, map-landings.js)
  for (const m of lists.maps) { const o = landingOverride(m.index); if (o) { m.landing = o.landing; m.landingFrom = o.landingFrom; } }
  const mapInfo = new Map(lists.maps.filter(m => m.file).map(m => [m.index, m]));
  // SYNTHESISED MAPS (src/world/legacy-maps.js): client maplist omitted these indexes but Global still ships map/.mac/light + share/map folders
  // (2005 fields in LEGACY_MAPS; conscript 27/28 + dungeonlist 120 in ABSENT_MAPLIST_MAPS). Register only when native collision exists.
  for (const [k, L] of Object.entries(allSynthesisedMaps())) { const index = Number(k); if (rawMaps.has(index) && mapInfo.get(index)?.file) continue;
    const row = legacyMapRow(index, rawMaps.get(0)); const paths = mapDataPaths(row); if (!(await fs.stat(path.join(dataRoot, paths.mac)).then(st => st.isFile(), () => false))) continue;
    const dir = path.join(dataRoot, 'share/map', L.dir.toLowerCase()), text = async f => fs.readFile(path.join(dir, f.toLowerCase())).then(decodeText, () => '');
    const listed = lists.maps.find(m => m.index === index); let spawnRows = monstersFile.spawns[index]?.rows;
    if (!spawnRows?.length) { spawnRows = parseLegacySpawns(await text(`MON_${L.dir}.csv`)); if (spawnRows.length) monstersFile.spawns[index] = { rows: spawnRows, legacy: true }; }
    const landing = listed?.landing || firstNpcLanding(await text(`NPC_${L.dir}.csv`)) || (spawnRows?.[0] ? [spawnRows[0][2] + 0.5, spawnRows[0][3] + 0.5, 0] : null);
    const dungeon = Number(L.dungeonIndex || row.DungeonIndex || 0) || 0;
    rawMaps.set(index, row); mapInfo.set(index, { ...(listed || {}), index, name: L.Name, file: `map/${L.file}.map`, dungeon, siege: 0, legacy: true, landing });
    if (!listed) lists.maps.push(mapInfo.get(index)); else Object.assign(listed, mapInfo.get(index), { serverOnly: undefined }); }
  const levelCaps = await loadLevelCaps(dataRoot, rawMaps), abilityCaps = await loadAbilityCaps(dataRoot, rawMaps);
  const loaded = new Map(),loadingMaps=new Set(),mapOwners=new Map(),geometry=new Map(),forecasts=new Map();
  const asset = rel => {
    const target = path.resolve(dataRoot, String(rel).replace(/\\/g, '/').replace(/^\/+/, ''));
    if (!target.startsWith(path.resolve(dataRoot) + path.sep)) throw new Error('Invalid map asset path.');
    return nativeCaseAssetPath(dataRoot,target);
  };
  const forecast=async index=>{index=Number(index);const info=mapInfo.get(index),row=rawMaps.get(index);if(!Number.isInteger(index)||!info?.file||!row)throw Error('Unknown native map');let f=forecasts.get(index);if(!f){f=nativeMapGeometryForecast(dataRoot,path.relative(dataRoot,nativeCaseAssetPath(dataRoot,path.resolve(dataRoot,mapDataPaths(row).mac))).split(path.sep).join('/')).catch(error=>{forecasts.delete(index);throw error;});forecasts.set(index,f);f.then(value=>{if(forecasts.get(index)===f)forecasts.set(index,value);},()=>{});}return f;};
  const serverLists=createServerLists(await read('server-lists.json').catch(()=>null));
  return {
    dataRoot, gamedataRoot, serverLists,
    travelData:travel,dungeonCatalog,dungeonData,
    nameplateTitles:lifeData.grade?.titles||[],nameplateGrades:lifeData.grade?.grades||[],pkData:lifeData.pk||null,   // FIELD-PK: chaotic bands / pkcount / pkLevelCap
    eventData,lifeEvents:lifeData.events,classMotions:lifeData.classMotions||null,dekapass:lifeData.dekapass,fishing:lifeData.fishing,craft:lifeData.craft,guild:lifeData.guild,guildPolicy:FRONTIER_CHOSEN.PRODUCTION_POLICY,mailPolicy:{postage:MAIL_POSTAGE_DIL},pvpRules:await loadPvpRules(dataRoot),partyPvp:await loadPartyPvpData(dataRoot,lists.maps),colosseum:await loadColosseumData(dataRoot).catch(()=>null),consignment:await loadConsignmentPolicy(dataRoot,gamedataRoot),pcRoom:await loadPcRoomRules(dataRoot),itemServiceData,exp,
    requiresInstance: index => !!mapInfo.get(Number(index))?.dungeon,
    /** The raw share/maplist.csv row for a map index (read-only lookups such as IsPvP), or null. */
    mapRow: index => rawMaps.get(Number(index)) || null,
    // ENGINE-CHOSEN parking is restricted to proven unscripted native fields.
    // Native collision/spawn/script tables are never edited or approximated.
    fieldParkingAllowed(index){const info=mapInfo.get(Number(index)),row=rawMaps.get(Number(index));if(!info?.file||info.dungeon||!row||Number(row.IsSiege)!==0||eventData.modeOf(Number(index)))return false;const paths=mapDataPaths(row);return !!paths.mac&&!paths.bricks&&!paths.triggers&&!paths.callMonsters;},
    mapGeometryForecast:forecast,
    ownsMapGeometry(index,collision){return !!collision&&geometry.get(Number(index))?.collision===collision;},
    publicFieldDescriptor(index){index=Number(index);const info=mapInfo.get(index),row=rawMaps.get(index);if(!Number.isInteger(index)||!info?.file||info.dungeon||!row||Number(row.IsSiege)!==0||eventData.modeOf(index))return null;const min=Number(row.LimitMinLevel),max=Number(row.LimitMaxLevel);if(!Number.isInteger(min)||!Number.isInteger(max)||min<0||max<0)return null;const minLevel=min||1,maxLevel=max||(classesFile.maxLevel||250);if(maxLevel<minLevel)return null;const paths=mapDataPaths(row);if(!paths.mac)return null;return {index,minLevel,maxLevel,scripted:!!(paths.bricks||paths.triggers||paths.callMonsters)};},
    retainMap(index,owner){if(!owner)throw Error('Map geometry requires an explicit owner.');index=Number(index);let owners=mapOwners.get(index);if(!owners)mapOwners.set(index,owners=new Set());owners.add(owner);},
    releaseMapReference(index,owner){const owners=mapOwners.get(Number(index));return !!owner&&!!owners?.delete(owner);},
    // Atomic synchronous release: a failed attempt preserves cache and owners.
    releaseMap(index,{owner}={}){index=Number(index);const owners=mapOwners.get(index);if(loadingMaps.has(index)||!loaded.has(index)||owners?.size&&(!owner||owners.size!==1||!owners.has(owner)))return false;loaded.delete(index);geometry.delete(index);mapOwners.delete(index);return true;},
    mapCacheSnapshot(){let typedGeometryBytes=0,reservedGeometryBytes=0,accountingReady=true;const rows=[],allBuffers=new Set();for(const index of new Set([...loaded.keys(),...geometry.keys()])){const g=geometry.get(index);let measuredBytes=0;for(const a of g?[g.collision.cells,g.collision.grid?.attrs,g.collision.grid?.remoteBlocked,g.finder._g,g.finder._parent,g.finder._seen,g.finder._closed,g.finder._heap?.ids,g.finder._heap?.f]:[]){if(a?.buffer&&!allBuffers.has(a.buffer)){allBuffers.add(a.buffer);measuredBytes+=a.buffer.byteLength;}}typedGeometryBytes+=measuredBytes;const f=forecasts.get(index),forecastBytes=Number.isSafeInteger(f?.reservedBytes)?f.reservedBytes:null;const accountedBytes=forecastBytes===null?null:Math.max(measuredBytes,forecastBytes);if(accountedBytes===null)accountingReady=false;else reservedGeometryBytes+=accountedBytes;rows.push({index,measuredBytes,forecastBytes,accountedBytes,loading:loadingMaps.has(index)});}return {maps:loaded.size,loading:loadingMaps.size,owners:[...mapOwners.values()].reduce((n,s)=>n+s.size,0),typedGeometryBytes,reservedGeometryBytes,accountingReady,rows,otherObjectBytes:null};},
    /** The map's level-difference table (maplist StrLevelCapPath, server/world/level-caps.mjs), or null. */
    levelCap: index => levelCaps.get(Number(index)) || null,
    /** The map's level-difference ability caps (maplist StrAbilityCapPath, src/game/ability-cap.js), or null. */
    abilityCap: index => abilityCaps.get(Number(index)) || null,
    progression, itemDB, customLibrary,classesFile, itemUseData,shopData,lootData,partyData,...skillData,skillRootMotion:{files:skillRootMotion.files,curves:skillRootMotion.curves,table:skillRootMotion.table},...mountData,formula:classesFile.formula,progressionData:{classesFile,formula:classesFile.formula,gradeShieldRows,titleRows:lifeData.grade?.titles||[]},
    equipmentStyle: profile => itemDB ? new Equipment({db:itemDB,game:{save:profile}}).style() : 1,
    initializeEquipment(profile){
      if(itemDB)repairLegacyRankOptions(profile,itemDB);
      if(!itemDB||profile.equip)return;
      profile.equip=emptyEquip();
      const cd=classesFile.classes.find(c=>c.index===profile.classIndex),ci=profile.classIndex;
      const ok=d=>d&&Number(d.type)===4&&((Number(d.classMask)>>>ci)&1);
      let index=Number(cd?.weapon?.itemIndex);
      if(!ok(itemDB.def(index))){let best=null;for(const k in itemDB.items){const d=itemDB.def(k);if(!ok(d)||d.code!==Number(cd?.weapon?.code)||d.rank!==0||!(d.reqLv>=1)||d.period||/\+|\(|\[|test|event/i.test(d.name||'')||/[^\x00-\x7f]/.test(d.name||''))continue;if(!best||d.reqLv<best.reqLv||d.reqLv===best.reqLv&&d.index<best.index)best=d;}index=best?.index;}
      const inst=index&&createItem(itemDB,index,{});if(inst){profile.equip.items[inst.uid]=inst;profile.equip.presets[0][S.weapon]=inst.uid;}
    },
    start: { map: 150, x: 203.5, z: 247.5 },
    respawn: { map: 150, x: 349.5, z: 129.5 },
    maxLevel: classesFile.maxLevel || 250,
    classDef: index => classesFile.classes.find(c => c.index === index),
    statCap: (index, stat) => Number(classesFile.classes.find(c => c.index === index)?.stats?.raw?.[`${stat.toUpperCase()}_MAX`]) || 65000,
    // Mount state belongs to the live actor, never to a saved or client supplied profile.
    // Speed remains in mountSpeed; only non-speed riding options enter item stats here.
    stats: nativeProbeStats((profile,actor=null,now=Date.now()) => {
      const classDef=classesFile.classes.find(c=>c.index===profile.classIndex);
      if(itemDB)return deriveEquipment(profile,itemDB,classDef,{classesFile,gradeShieldRows,titleRows:lifeData.grade?.titles||[]},now,{isMounted:()=>false,extraOptions:()=>[...activePetOptions(profile,mountData.mountData,mountData.mountUI),...mountedStatOptions(profile,actor,mountData.mountData,now),...dkTierOptions(eventData.ev?.modes?.arena,profile),...carnivalStatOptions(actor,now)]},passivePools);
      const stats=deriveStats(profile,classDef,{classesFile,gradeShieldRows,titleRows:lifeData.grade?.titles||[]},[]);
      return Object.assign(stats,foldSharedStatusStats(stats,[],passivePools(profile,Number(profile.equipment?.weapon?.style??classDef?.style??1))));
    }),
    expNeeded: level => exp.levels.find(r => r.level === level)?.toNext ?? Infinity,
    monsterDef: index => monstersFile.monsters[index],
    spawns: map => (monstersFile.spawns[map]?.rows || []).map((r, i) => ({ id: `${map}:${i}`, monsterIndex: r[0], respawnSec: r[1], x: r[2] + 0.5, z: r[3] + 0.5 })),
    gates: map => (travel.warps || []).filter(w => w.kind === 'zone' && !w.siege && !w.dungeon && Number(w.fromMap) === map && w.box).map(w => {
      const to = travel.locations[w.to];
      return to ? { id: w.id, box: w.box, to: { map: Number(to[0]), x: Number(to[1]) + 0.5, z: Number(to[2]) + 0.5 } } : null;
    }).filter(Boolean),
    async originalMapFiles(index) {
      const row=rawMaps.get(Number(index)),info=mapInfo.get(Number(index));
      if(!row||!info||info.dungeon||info.siege)throw Object.assign(Error('Only explicitly approved original fields can be edited.'),{status:403});
      const paths=mapDataPaths(row);
      if(paths.triggers||(Number(index)!==150&&(paths.bricks||paths.callMonsters)))throw Object.assign(Error('Original scripted placement files require separate owner rules.'),{status:409});
      if(!paths.map||!paths.mac)throw Error('Original terrain/collision paths are unavailable.');
      const files=await Promise.all([paths.map,paths.mac].map(async key=>{const file=asset(key);if((await fs.stat(file)).size>32*1024*1024)throw Error('Original map asset exceeds 32 MiB.');return fs.readFile(file);}));
      const result={map:files[0],mac:files[1]};
      if(Number(index)===150){
        for(const key of ['mol','bricks','callMonsters']){if(!paths[key])throw Error('Protected Ardeca source is missing.');const target=asset(paths[key]);if((await fs.stat(target)).size>32*1024*1024)throw Error('Protected Ardeca asset exceeds its bound.');result[key]=await fs.readFile(target);}
        result.scope=ardecaHeightScope({index:150,files:result,brickDefs:dungeonData.dg.bricks,npcs:progression?.npcs?.placements?.[150]?.rows||[],gates:(travel.warps||[]).filter(w=>w.kind==='zone'&&Number(w.fromMap)===150&&w.box).map(w=>w.box)});
      }
      return result;
    },
    async map(index,{instance=false}={}) {
      if (!mapInfo.has(index) || (mapInfo.get(index).dungeon && !instance)) throw Object.assign(new Error('This map is unavailable in the shared field world.'), { status: 400 });
      if (!loaded.has(index)){loadingMaps.add(index);loaded.set(index, (async () => {
        const info = mapInfo.get(index), row = rawMaps.get(index);
        if (!row?.MapAttribute) throw new Error('Map collision data is unavailable.');
        const macPath = mapDataPaths(row).mac;   // the same lowercase data key as the forecast (prepared/Global data is stored lowercase; maplist names are mixed case)
        const expected=await forecast(index);
        const collision = Collision.fromBuffer(await fs.readFile(asset(macPath)));
        if(collision.width!==expected.width||collision.height!==expected.height)throw Error('Native collision dimensions changed after reservation.');
        if (!collision.hasData) throw new Error('Map collision data failed validation.');
        const pathfinder = new PathFinder(collision, { maxNodes: 20000, snapRadius: 8 });
        geometry.set(index,{collision,finder:pathfinder});
        return { ...info, width: collision.width, height: collision.height, collision, isWalkable: (x, z) => collision.isWalkable(x, z), path: (x, z, tx, tz) => pathfinder.findPath(x, z, tx, tz), nearest: (x, z) => collision.nearestWalkable(x, z, 32) };
      })().catch(err => { loaded.delete(index);geometry.delete(index);throw err; }).finally(()=>loadingMaps.delete(index)));}
      return loaded.get(index);
    },
  };
}
