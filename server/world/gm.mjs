import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {mergeRewardProgress} from './reward-progress.mjs';
import {takeInventoryItem} from './gm-transfer.mjs';
import {teleportGM} from './gm-map-destination.mjs';
import {exitInstance,enterTrustedScene} from './instances.mjs';
import {mapFor,sameScene} from './scene.mjs';
// GM intent is parsed again on the host. Grants come from the account permission store.
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomUUID } from 'node:crypto';
import { GMData } from '../../src/systems/gm/data.js';
import { matchLine, coerceArgs } from '../../src/systems/gm/parser.js';
import { EXTRA } from '../../src/systems/gm/commands.js';
import { indexAtLevel, optionCode } from '../../src/systems/gm/itemgen.js';
import { WorldError } from './core.mjs';
import {playerGM} from './gm-players.mjs';
import {npcRosterGM} from './gm-npc-roster.mjs';
import {gmItemIntent} from './gm-items.mjs';
import {inventoryGM} from './gm-inventory.mjs';
import {commitFieldTravel} from './travel.mjs';
import {commitLife} from './life-transactions.mjs';
import {defaultRoots} from './prepared-roots.mjs';
import {respawnDelayMs} from '../../src/game/monster-rules.js';
import {clearHate} from '../../src/game/hate.js';
import {gmGearSet} from './gm-gear-set.mjs';
import {setMonsterFactor,setMonsterDropItem} from './monster-tuning.mjs';
import {gmPartyWarControl} from './events.mjs';
import {gmZutoControl} from './urban-warfare-controller.mjs';
import {oxQuizCommand,oxQuizData} from './ox-quiz.mjs';
import {globalEventGM} from './gm-global-events.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {socialState,socialRef} from './social-state.mjs';
import {GM_PRIZE} from '../../src/config/engine-chosen-gm-prize.js';

const toggle = (value, old) => value === 'on' ? true : value === 'off' ? false : !old;
const bounded = (value, min = 0, max = 1e12) => {
  const number = Number(value);
  if (!Number.isFinite(number) || number < min || number > max) throw new WorldError(400, `Value must be between ${min} and ${max}.`);
  return number;
};
const flagCommands = { god: 'god', hide: 'hide', onehit: 'onehit', infinitemp: 'infmp', gmmode: 'mode', noclip: 'noclip', unlockmaps: 'unlock' };
// makeitem and giveitem: the host builds the item from the catalog with one set of bounds; no client item instance.
function gmItemSpec(world,a){
  const item=indexAtLevel(world.data.itemDB,Number(a.item.id),a.upgrade ?? 0),count=Math.floor(bounded(a.count ?? 1,1,10000)),rnd=[];
  for(const [row,value] of a.options || []){
    const raw=row.raw || row,code=Number.isFinite(Number(raw.code))?Number(raw.code):optionCode(world.data.itemDB,raw.type);
    if(code==null)continue;
    const min=Number(raw.min),max=Number(raw.max),v=Number(value);
    rnd.push([code,Number.isFinite(min)&&Number.isFinite(max)&&max>=min?Math.max(min,Math.min(max,v)):v]);
  }
  return {item,count,options:{grade:a.grade,sockets:a.sockets,roll:a.roll,bound:a.bound,rnd:rnd.length?rnd:undefined}};
}

// default root: explicit > DEKARON_GAMEDATA > the active prepared generation > legacy (server/world/prepared-roots.mjs); api.mjs passes the host root
export function createWorldGM({ gamedataRoot = defaultRoots().gamedataRoot, registry } = {}) {
  const root = path.resolve(gamedataRoot);
  const data = registry || new GMData({ readJSON: async url => {
    const name = String(url).replace(/^\/gamedata\//, '');
    if (!/^[a-zA-Z0-9_-]+\.json$/.test(name)) throw new WorldError(400, 'Invalid GM data source.');
    return JSON.parse(await fs.readFile(path.join(root, name), 'utf8'));
  } });
  let ready;
  return async function runGM(world, user, input, trustedTarget = null, services = {}) {
    if (!user.capabilities?.includes('gm:commands')) throw new WorldError(403, 'This account does not have GM permission.');
    if(input?.operation==='npcRoster')return npcRosterGM(world,user,input);
    if(input?.operation==='gearSet')return gmGearSet(world,user,input);
    if(input?.operation==='takeInventoryItem')return takeInventoryItem(world,user,input,services);
    if(input?.operation==='teleportDestination')return teleportGM(world,user,input,services);
    if (['characterDirectory','inspectInventory'].includes(input?.operation)) return inventoryGM(world,user,input);
    if(input?.operation==='customMapEnter'){
      if(Object.keys(input).some(k=>!['token','operation','index'].includes(k))||!Number.isInteger(input.index))throw new WorldError(400,'Choose a published server map index.');
      const p=world.lease(user.id,input.token),entry=world.data.customMaps?.entry(input.index);
      if(!entry)throw new WorldError(404,'Published server map not found.');
      if(p.instanceId||p.sceneTransition)throw new WorldError(409,'Exit the current instance or finish travelling before entering a custom map.');
      const now=world.now();if(now-(p.gmRateAt||0)>=1000){p.gmRateAt=now;p.gmActions=0;}if((p.gmActions=(p.gmActions||0)+1)>20)throw new WorldError(429,'Too many GM commands.');
      await commitFieldTravel(world,p,{map:entry.index,...entry.start});
      return {ok:true,message:`Entered published map ${entry.name} (#${entry.index}).`,state:world.snapshot(p)};
    }
    if(input?.operation){if(typeof input.operation!=='string')throw new WorldError(400,'Invalid GM operation.');if(JSON.stringify(input).length>(input.operation==='customImport'?256000:32000))throw new WorldError(400,'GM item request is too large.');const p=world.lease(user.id,input.token),now=world.now();if(now-(p.gmRateAt||0)>=1000){p.gmRateAt=now;p.gmActions=0;}if((p.gmActions=(p.gmActions||0)+1)>20)throw new WorldError(429,'Too many GM commands.');if(['players','renamePlayer','playerCommand'].includes(input.operation)) return playerGM(world,user,input,runGM);if(input.operation.startsWith('custom')){if(!world.data.customLibrary)throw new WorldError(503,'Server custom item library is unavailable.');return world.data.customLibrary.run(world,p,input);}return gmItemIntent(world,p,input);}
    if (!input || Object.keys(input).some(k => !['token', 'line'].includes(k)) || typeof input.line !== 'string' || input.line.length > 2048) throw new WorldError(400, 'Send a GM command line and your world lease.');
    let p = trustedTarget || world.lease(user.id, input.token);
    const now = world.now();
    if (now - (p.gmRateAt || 0) >= 1000) { p.gmRateAt = now; p.gmActions = 0; }
    if ((p.gmActions = (p.gmActions || 0) + 1) > 20) throw new WorldError(429, 'Too many GM commands.');
    ready ||= data.load().then(() => { data.extra = new Map(EXTRA.map(c => [c.id, c])); });
    await ready;
    const match = matchLine(input.line, data), cmd = match?.cmd;
    if (!cmd) throw new WorldError(400, 'Choose a GM command; /GM opens the Command Center.');
    let a;
    const commandData=Object.create(data);
    commandData.list=async listId=>{const original=await data.list(listId);if(listId!=='maps'||!world.data.customMaps)return original;
      const rows=[...original,...world.data.customMaps.list().map(e=>({id:e.index,name:e.name,sub:'Published server map',search:`${e.index} ${e.name} published server map`.toLowerCase(),raw:{index:e.index,name:e.name,level:[e.env.minLevel||1,e.env.maxLevel||250],file:`custom_${e.index}.map`}}))];rows.byId=new Map(rows.map(r=>[String(r.id),r]));return rows;};
    try { a = await coerceArgs(cmd, match.rest, match.restText, commandData); }
    catch (error) { throw new WorldError(400, `${error.detail || error.message}. ${cmd.syntax}`); }
    const id = cmd.id;
    // Lane 47: Global GM event commands (dkrpvp_*, set_dksquareInfo, guildwarhunting_*) - server/world/gm-global-events.mjs
    if(['dkrpvp_create','dkrpvp_delete','dkrpvp_applystart','dkrpvp_applymember','dkrpvp_selectteam','dkrpvp_createleague','dkrpvp_open','dkrpvp_finish','dkrpvp_setstatus','dkrpvp_createtournament','set_dksquareinfo','guildwarhunting_open','guildwarhunting_ready','guildwarhunting_start','guildwarhunting_finish'].includes(id)){let globalEvent;try{globalEvent=await globalEventGM(world,`/gm ${id} ${a.args||''}`);}catch(error){throw new WorldError(error.status||400,error.message);}
      if(!globalEvent)throw new WorldError(400,cmd.syntax);world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});return {...globalEvent,state:world.snapshot(p)};}
    if(['exprate','droprate','dilrate'].includes(id)){
      if(a._extra?.length)throw new WorldError(400,cmd.syntax);
      if(!world.rateSettings)throw new WorldError(503,'Live rate settings are unavailable on this host.');
      const kind={exprate:'exp',droprate:'drop',dilrate:'dil'}[id];
      let rates;try{rates=await world.rateSettings.setEvent(kind,Number(a.multiplier),Number(a.minutes??0));}catch(error){throw new WorldError(400,error.message);}
      const ended=Number(a.multiplier)===0||Number(a.multiplier)===1;
      return {ok:true,message:`${kind.toUpperCase()} ${ended?'event ended':`event x${a.multiplier}${Number(a.minutes)>0?` for ${a.minutes} minutes`:''}`}. Effective server rate: x${rates[kind]}. Saved for this server.`,state:world.snapshot(p)};
    }
    if(id==='mapbuff'){
      const result=await oxQuizCommand(world,p,{type:'oxquiz',token:p.token,operation:'buff',menu:Number(a.buff.id)});
      return {message:oxQuizData(world).mapTexts[654][9700],oxQuizResult:result,state:world.snapshot(p)};
    }
    if(id==='ox'||id==='oxentry'){
      if(a._extra?.length||a.question)throw new WorldError(400,'Shared OX quiz commands use intent only; the host chooses an unused original question.');
      if(id==='ox'&&a.action==='auto')throw new WorldError(400,'Scheduled OX runs automatically on Saturday at17:00 server time. This GM session remains manual; use /gm ox ask and elimination controls.');
      const operation=id==='oxentry'?(a.state==='open'?'open':'closeEntry'):({killo:'eliminate',killx:'eliminate',ask:'question'}[a.action]||a.action);
      const answer=a.action==='killo'?'O':a.action==='killx'?'X':null;
      const result=await oxQuizCommand(world,p,{type:'oxquiz',token:p.token,operation,...(answer?{answer}:{})});
      const map=id==='oxentry'?654:22,code=id==='oxentry'?(a.state==='open'?9553:9554):({wall:5111,unwall:5112,killo:5113,killx:5114,ask:5115,close:5116,end:5117}[a.action]);
      world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
      return {message:oxQuizData(world).mapTexts[map][code],oxQuizResult:result,state:world.snapshot(p)};
    }
    if(id==='partywar'||id==='partywarevent'){
      const zuto=/^zuto'?s battlefield$/i.test(String(a.content?.raw?.name||a.content?.name||'').trim());   // owner-directed Zuto adaptation
      const message=zuto?gmZutoControl(world,id==='partywarevent'?'start':a.state):await gmPartyWarControl(world,a.content,id==='partywarevent'?'start':a.state);
      world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
      return {message,state:world.snapshot(p)};
    }
    if(id==='monstertune'||id==='monsterloot'){
      try{
        if(id==='monstertune')setMonsterFactor(world,a.monsterId,a.stat,a.factor);
        else setMonsterDropItem(world,a.monsterId,a.itemId,a.chance,a.count??1);
      }catch(error){throw new WorldError(400,error.message);}
      const message=id==='monstertune'?`Monster ${a.monsterId} ${a.stat} ×${a.factor} for this server run.`:`Monster ${a.monsterId} item ${a.itemId}: ${a.chance}/100000, count ${a.count??1} for this server run.`;
      world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
      return {message,state:world.snapshot(p)};
    }
    if(['noclip','unlockmaps'].includes(id))throw new WorldError(400,`${id} is not supported by the authoritative movement and travel services.`);
    const durable=['level','exp','dil','dkc','vip','heal','revive','setstat','statreset','grade','speed','skill','allskills','skillreset','cooldowns','buff',...Object.keys(flagCommands)].includes(id),live=p,host=world,notices=[];
    const before=durable?structuredClone(p.profile):null,hpBefore=p.hp,mpBefore=p.mp||0;
    if(durable){p={...p,profile:structuredClone(before),stats:{...p.stats},_skills:null};world=Object.create(host);world.emit=(map,event)=>notices.push([map,event]);}
    const gm = ['makeitem','giveitem','clearinv','quest','queststate','killall'].includes(id) ? null : (p.profile.gm ||= {});
    const refresh = (heal = false) => {
      p.stats = world.data.stats(p.profile,p,world.now()); p.maxHp = p.stats.maxHp;
      p.hp = heal ? p.maxHp : Math.min(p.hp, p.maxHp);
      p.mp = heal ? p.stats.maxMp || 0 : Math.min(p.mp || 0, p.stats.maxMp || 0);
    };
    let sceneDurable=false;
    const warp = async (map, x, z) => {
      const target = await world.data.map(Number(map),{instance:!!world.data.requiresInstance?.(Number(map))});
      const at = target.nearest(x ?? target.start?.x ?? target.landing?.[0] ?? p.x, z ?? target.start?.z ?? target.landing?.[1] ?? p.z);
      if (!at) throw new WorldError(400, 'No walkable arrival point is available.');
      sceneDurable=!!p.instanceId||!!world.data.requiresInstance?.(Number(map)); await enterTrustedScene(world,p,Number(map),at,{kind:'gm',durable:sceneDurable});
    };
    const grantExp = amount => {
      p.profile.exp = Math.max(0, (p.profile.exp || 0) + amount);
      while (p.profile.level < (world.data.maxLevel || 250)) {
        const need = world.data.expNeeded(p.profile.level);
        if (!(need > 0) || !Number.isFinite(need) || p.profile.exp < need) break;
        p.profile.exp -= need; p.profile.level++;
        const _pts = Number(world.data.classesFile?.statPointsPerLevel) || Number(world.data.formula?.byStatPointPerLevel) || 0;
        p.profile.statPoints = (p.profile.statPoints || 0) + _pts;
        p.profile.skillPoints = (p.profile.skillPoints || 0) + 1; // see progression.SKILL_POINTS_PER_LEVEL
        world.emit(p.map, { type: 'levelup', actorId: p.id, level: p.profile.level });
      }
      refresh(true);
    };
    let message;
    if (Object.hasOwn(flagCommands, id)) {
      const key = flagCommands[id]; gm[key] = toggle(a.state ?? (id === 'cooldowns' ? a.mode === 'off' ? 'on' : 'off' : undefined), gm[key]);
      message = `${id}: ${gm[key] ? 'on' : 'off'}.`;
    } else switch (id) {
      case 'skill': case 'allskills': case 'skillreset': case 'cooldowns': case 'buff': {
        const { executeSkillGM } = await import('./skills.mjs');
        const args = id === 'skill' ? [a.skill.id, a.level] : id === 'buff' ? [a.status.id, (a.minutes ?? 30) * 60000] : [];
        executeSkillGM(world,p,id,args); message = `GM ${id} applied by the server.`; break;
      }
      case 'level': {
        const target = Math.floor(bounded(a.level, 1, world.data.maxLevel || 250)), before = p.profile.level;
        if (target > before) {
          let amount = -(p.profile.exp || 0);
          for (let lv = before; lv < target; lv++) amount += world.data.expNeeded(lv);
          if (!Number.isFinite(amount)) throw new WorldError(400, 'Level EXP data is unavailable.');
          grantExp(Math.max(0, amount));
        } else {
          p.profile.level = target; p.profile.exp = 0;
          const _pts = Number(world.data.classesFile?.statPointsPerLevel) || Number(world.data.formula?.byStatPointPerLevel) || 0; p.profile.statPoints = Math.max(0, (p.profile.statPoints || 0) - (before-target)*_pts);
          p.profile.skillPoints = Math.max(0, (p.profile.skillPoints || 0) - (before-target)); refresh(true);
        }
        message = `Level ${before} → ${p.profile.level}.`; break;
      }
      case 'exp': grantExp(bounded(a.amount)); message = `EXP granted; level ${p.profile.level}.`; break;
      case 'dil': p.profile.dil = Math.max(0, (p.profile.dil || 0) + Math.floor(bounded(a.amount, -1e12))); message = `DIL: ${p.profile.dil}.`; break;
      case 'dkc': {
        const unlimited = /^(unlimited|inf|infinite|max|∞)$/i.test(String(a.amount));
        p.profile.dkc = unlimited ? p.profile.dkc || 0 : Math.floor(bounded(String(a.amount).replace(/[,_]/g, '')));
        gm.dkc = unlimited ? 'unlimited' : p.profile.dkc;
        message = unlimited ? 'Unlimited D-Shop access is provided by your GM permission.' : `D-Shop coins: ${p.profile.dkc}.`; break;
      }
      case 'heal': case 'revive': p.dead = false; refresh(true); message = 'HP and MP restored.'; break;
      case 'setstat': {
        const value = Math.floor(bounded(a.value, 0, 65000));
        if (a.stat === 'points') p.profile.statPoints = value;
        else if (['str','dex','con','spr'].includes(a.stat)) { p.profile.stats[a.stat] = value; refresh(); }
        else throw new WorldError(400, 'Unknown stat.');
        message = `${a.stat}: ${value}.`; break;
      }
      case 'statreset': {
        const base = world.data.classDef(p.profile.classIndex).stats?.base;
        if (!base) throw new WorldError(400, 'Class base stats are unavailable.');
        let back = 0; for (const k of ['str','dex','con','spr']) back += Math.max(0, (p.profile.stats[k] || 0)-(base[k] || 0));
        p.profile.stats = { ...base }; p.profile.statPoints = (p.profile.statPoints || 0)+back; refresh(); message = `${back} stat points returned.`; break;
      }
      case 'grade': p.profile.gradePoints = Math.floor(bounded(a.points)); message = `Grade points: ${p.profile.gradePoints}.`; break;
      case 'vip': {   // VIP Points (VIP Shop currency, server-owned profile.vipPoints); no game data grants them, so GMs do
        const n = Math.floor(bounded(a.amount, 0, 1e9));
        p.profile.vipPoints = Math.min(1e12, a.mode === 'add' ? (Number(p.profile.vipPoints) || 0) + n : n);
        message = `VIP Points: ${p.profile.vipPoints}.`; break;
      }
      case 'speed': gm.speed = bounded(a.factor, 0.1, 10); message = `GM movement speed ×${gm.speed}.`; break;
      case 'move': case 'guildwarteleport': case 'siegemonitor': await warp(a.map?.id ?? p.map, a.x == null ? null : a.x+.5, a.y == null ? null : a.y+.5); message = `Moved to map ${p.map}.`; break;
      case 'goloc': await warp(a.location.raw.map, Number(a.location.raw.x)+.5, Number(a.location.raw.y)+.5); message = `Moved to ${a.location.name}.`; break;
      case 'gotonpc': {
        const placements = world.data.progression?.npcs?.placements || {};
        let found; for (const [map, entry] of Object.entries(placements)) for (const row of entry.rows || []) if (Number(row[0]) === Number(a.npc.id)) { found = { map, x:row[1], z:row[2] }; if (Number(map) === p.map) break; }
        if (!found) throw new WorldError(400, 'NPC has no known placement.');
        await warp(found.map, found.x, found.z); message = `Moved to ${a.npc.name}.`; break;
      }
      case 'usercount': message = `${[...world.players.values()].filter(q=>!q.leaving).length} connected players.`; break;
      case 'mapusercount': message = `${[...world.players.values()].filter(q=>!q.leaving && q.map === Number(a.map?.id ?? p.map)).length} players on this map.`; break;
      case 'notice': {
        const text = a.scope === 'clear' ? '' : String(a.text || '').trim();
        for (const map of world.maps.values()) if (a.scope !== 'map' || sameScene({map:map.index,instanceId:map.instanceId,channel:map.channel},p)) world.emit(map.index, { type:'gm:notice', text,instanceId:map.instanceId||null });
        message = text ? 'Notice sent.' : 'Notice cleared.'; break;
      }
      case 'mute': {
        const target = [...world.players.values()].find(q=>[q.account,q.profile.name,'me','self'].some(n=>String(n).toLowerCase()===String(a.player).toLowerCase()) && (!['me','self'].includes(a.player) || q===p));
        if (!target) throw new WorldError(400, 'That player is not connected.');
        target.muteUntil = now+bounded(a.minutes,0,525600)*60000; message = 'Chat restraint updated.'; break;
      }
      case 'freeze': world.gmFrozen = toggle(a.state,world.gmFrozen); message = `Monster simulation ${world.gmFrozen ? 'paused' : 'resumed'}.`; break;
      case 'ai': world.gmFrozen = a.state === 'off'; message = `Monster AI ${world.gmFrozen ? 'off' : 'on'}.`; break;
      case 'callmonster': {
        const def = world.data.monsterDef(Number(a.monster.id)), count = Math.floor(bounded(a.count ?? 1,1,100));
        if (!def) throw new WorldError(400, 'Unknown monster.');
        const map = mapFor(world,p);
        let spawned = 0;
        for (let i=0;i<count;i++) {
          const at = map.nearest(a.x ?? p.x+2+(i%4),a.y ?? p.z+Math.floor(i/4)); if (!at) continue;
          const key = `gm:${randomUUID()}`;
          map.monsters.set(key,{id:key,monsterIndex:Number(a.monster.id),map:p.map,instanceId:p.instanceId||null,name:def.name,...at,hp:def.hp,maxHp:def.hp,home:{...at},dead:false,targetId:null,attackAt:0,respawnAt:0,respawnSec:Infinity,oneShot:true,gmSpawned:true,def});
          spawned++;
        }
        // Summons are transient scene state, not character progress. Return the
        // authoritative bodies immediately rather than waiting for a SQL save.
        world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
        return {message:`${spawned} monster spawn requests completed.`,state:world.snapshot(p)};
      }
      case 'killall': {
        // Physical combat is accepted immediately; its profile rewards remain private.
        const staged=Object.create(world),rewards=[],before=new Map(),copies=new Map();
        staged.players=new Map();staged.parties=structuredClone(world.parties||new Map());staged.groundLoot=new Map(world.groundLoot||[]);
        staged.emit=(map,event)=>rewards.push([map,event]);
        for(const [account,actor]of world.players){const profile=structuredClone(actor.profile);before.set(actor,{profile,revision:actor.revision,hp:actor.hp,mp:actor.mp||0});const copy={...actor,profile:structuredClone(profile),stats:{...actor.stats},_skills:null};copies.set(actor,copy);staged.players.set(account,copy);}
        let count=0;
        for(const m of mapFor(world,p).monsters.values())if(!m.dead&&Math.hypot(p.x-m.x,p.z-m.z)<=(a.radius??Infinity)){
          m.hp=0;m.dead=true;m.targetId=null;clearHate(m);m.called=false;m.respawnAt=now+respawnDelayMs(m.respawnSec);count++;
          world.emit(p.map,{type:'damage',sourceId:p.id,targetId:m.id,amount:m.maxHp,dead:true});if(a.drops!==false)staged.reward(copies.get(p),m);
        }
        const recipients=[...copies].filter(([actor,copy])=>JSON.stringify(copy.profile)!==JSON.stringify(before.get(actor).profile));
        if(recipients.length>1&&!world.saveProfiles)throw new WorldError(503,'Atomic party reward storage is unavailable.');
        const transitions=recipients.map(([actor])=>actor.sceneTransition);recipients.forEach(([actor])=>{actor.sceneTransition=true;});
        try{
          if(recipients.length)await world.persistMany(recipients.map(([,copy])=>copy));
          for(const [actor,copy]of recipients){const base=before.get(actor),liveLevel=actor.profile.level,liveMaxHp=actor.maxHp,liveMaxMp=actor.stats.maxMp||0;const merged=mergeRewardProgress(world,actor,base.profile,copy,{dil:copy.profile.dil});publishProfileChanges(actor.profile,base.profile,copy.profile);actor.stats=copy.stats;actor.maxHp=copy.stats.maxHp;refreshConcurrentBuffStats(world,actor,base.profile);if(!actor.dead&&actor.hp>0){actor.hp=Math.min(actor.maxHp,actor.hp+(liveLevel>base.profile.level&&copy.profile.level>base.profile.level?Math.max(0,actor.maxHp-liveMaxHp):Math.max(0,copy.hp-base.hp)));actor.mp=Math.min(actor.stats.maxMp||0,(actor.mp||0)+(liveLevel>base.profile.level&&copy.profile.level>base.profile.level?Math.max(0,(actor.stats.maxMp||0)-liveMaxMp):Math.max(0,(copy.mp||0)-base.mp)));}world.changed(actor);for(const event of merged?.notices||[])rewards.push(event);}
          for(const [partyId,party]of staged.parties){const liveParty=world.parties?.get(partyId);if(liveParty&&liveParty.members.every((member,i)=>member===party.members[i])&&liveParty.members.length===party.members.length)liveParty.lootTurn=party.lootTurn;}
          for(const [id,drop]of staged.groundLoot)if(!world.groundLoot?.has(id)){world.groundLoot||=new Map();world.groundLoot.set(id,drop);}
          for(const [map,event]of rewards)world.emit(map,event);
          if(recipients.length)await persistInterveningProgress(world,recipients.map(([actor])=>actor));
          world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});return {message:`${count} monsters defeated.`,state:world.snapshot(p)};
        }finally{recipients.forEach(([actor],i)=>{actor.sceneTransition=transitions[i];});}
      }
      case 'respawn': for (const m of mapFor(world,p).monsters.values()) { if(m.oneShot)continue; m.dead=false;m.hp=m.maxHp;Object.assign(m,m.home);m.targetId=null;clearHate(m);m.called=false;m.anchor=null; } message='Monsters respawned.'; break;
      case 'giveitem': {
        // GM event prize (src/config/engine-chosen-gm-prize.js): the host CREATES the item on a connected character,
        // so nothing is traded, mailed or transferred and those refusals stay unchanged.
        if(!world.data.itemDB)throw new WorldError(503,'The authoritative item catalog is unavailable.');
        if(typeof world.serializeAccount!=='function'||typeof world.saveSocialTransaction!=='function')throw new WorldError(503,'GM prize storage is unavailable.');
        const spec=gmItemSpec(world,a),def=world.data.itemDB.def(spec.item);
        if(!def)throw new WorldError(400,'Unknown item.');
        const wanted=String(a.player||'').trim().toLowerCase();
        const connected=q=>!!q&&world.players.get(q.account)===q&&!q.leaving&&!q.revoked&&!q.npcPlayer&&!q.profile?.npcPlayer&&!/^npc_/.test(String(q.account))&&String(q.profile?.name||'').toLowerCase()===wanted;
        const target=wanted?[...world.players.values()].find(connected):null;
        if(!target)throw new WorldError(404,'That character is not online. GM prizes go to connected player characters.');
        // The recipient's account order covers join/replacement, leave and disconnect cleanup; its fence stops its own
        // actions, ticks and autosaves until the single canonical write settles.
        const receipt=await world.serializeAccount(target.account,async()=>{
          const custody=()=>{if(!connected(target))throw new WorldError(409,'That character\'s session changed. Nothing was granted.');};
          custody();
          if(target.sceneTransition||target.progressCommitting||target.tradeCommitting||target.progressSave||(target.commandActive||0)>(target===p?1:0))throw Object.assign(new WorldError(409,'That character is travelling, trading or saving. Try again in a moment.'),{code:'WORLD_BUSY'});
          const transition=target.sceneTransition;target.sceneTransition=true;
          try{
            const task=world.saveQueue.catch(()=>{}).then(async()=>{
              custody();
              const before=structuredClone(target.profile),profile=structuredClone(before),revision=target.revision??0;
              const inventory=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
              if(!inventory.canFit([{item:spec.item,count:spec.count,...spec.options}]))throw new WorldError(400,`${target.profile.name}'s inventory is full. Nothing was granted.`);
              if(!inventory.add(spec.item,spec.count,spec.options))throw new WorldError(400,'The item could not be granted.');
              const row={id:randomUUID(),at:world.now(),gm:{ref:socialRef(p),name:p.profile.name},to:{ref:socialRef(target),name:target.profile.name},item:spec.item,name:def.name,count:spec.count,upgrade:a.upgrade ?? 0};
              const current=socialState(world),state=structuredClone(current);
              state.gmPrizes=[...(Array.isArray(current.gmPrizes)?current.gmPrizes:[]),row].slice(-GM_PRIZE.receipts);state.revision=current.revision+1;
              // Item and receipt are one atomic write; live state changes only after it is durable.
              if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates:[{accountId:target.account,characterId:target.characterId,profile:world.canonical({...target,profile})}]})===false)throw new WorldError(503,'The GM prize could not be saved. Nothing was granted.');
              world.socialState=state;
              publishProfileChanges(target.profile,before,profile);const intervening=(target.revision??0)-revision;world.changed(target);target.dirty=intervening!==0;target.saveError=null;
              return row;
            });
            world.saveQueue=task.catch(()=>{});
            return await task;
          }finally{target.sceneTransition=transition;}
        });
        await persistInterveningProgress(world,[target]);
        world.emit(target.map,{type:'event:message',text:GM_PRIZE.notice(p.profile.name,receipt.name,receipt.count),recipients:[target.id],instanceId:target.instanceId||null});
        world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
        return {message:`Granted ${receipt.name} ×${receipt.count} to ${receipt.to.name}.`,gmPrize:receipt,state:world.snapshot(p)};
      }
      case 'makeitem': case 'clearinv': case 'quest': case 'queststate': {
        const { createQuestContext } = await import('./quests.mjs');
        const before=structuredClone(p.profile),hpBefore=p.hp,mpBefore=p.mp||0;
        const candidate={...p,profile:structuredClone(before),stats:{...p.stats}},notices=[],staged=Object.create(world);
        candidate.profile.gm ||= {};
        staged.emit=(map,event)=>notices.push([map,event]);
        const ctx = createQuestContext(staged,candidate);
        if(!ctx) throw new WorldError(503,'The authoritative quest and item catalogs are unavailable.');
        const {engine,inventory}=ctx;
        if (id==='makeitem') {
          const {item,count,options}=gmItemSpec(world,a);
          if (!inventory.canFit([{item,count,...options}])) throw new WorldError(400,'Inventory is full.');
          if(!inventory.add(item,count,options)) throw new WorldError(400,'The item could not be granted.'); message=`Granted ${a.item.name} ×${count}.`;
        } else if (id==='clearinv') { ctx.profile.inventory = (ctx.profile.inventory || []).filter(it=>a.bag != null && it.page !== a.bag-1); message='Selected inventory items removed.'; }
        else if (id==='queststate') message = JSON.stringify(a.quest ? engine.st.active[a.quest.id] || engine.st.done[a.quest.id] || null : engine.st);
        else {
          const qid=Number(a.quest.id), q=engine.db.quest(qid);
          if (!q) throw new WorldError(400,'Unknown quest.');
          if (a.action==='start') { if (!engine.accept(qid,{silent:true}).ok) throw new WorldError(400,'Quest cannot be accepted in the current state.'); }
          else if (a.action==='reset' || a.action==='abandon') { delete engine.st.active[qid]; if (a.action==='reset') delete engine.st.done[qid]; }
          else if (a.action==='complete') { const slots=engine.slots(qid); if(!slots) throw new WorldError(400,'Start the quest first.'); for(const o of q.objectives || []) if(o.slot != null) slots[o.slot]=o.count || 1; if(!engine.claim(qid,{silent:true}).ok) throw new WorldError(400,'Quest reward could not be granted.'); }
          message=`Quest ${qid}: ${a.action}.`;
        }
        ctx.commit();
        const gain={hp:Math.max(0,candidate.hp-hpBefore),mp:Math.max(0,(candidate.mp||0)-mpBefore)};
        const publication=await commitLife(world,p,candidate.profile,{stats:candidate.stats,hp:Math.min(p.hp+gain.hp,candidate.stats.maxHp),mp:Math.min((p.mp||0)+gain.mp,candidate.stats.maxMp||0),vitalDeltas:gain,profileBefore:before,rewardProgress:true});
        for(const[map,event]of notices)if(event.type!=='levelup'||publication.concurrentLevel<=before.level||event.level>publication.concurrentLevel)world.emit(map,event);
        for(const[map,event]of publication.notices)world.emit(map,event);
        world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
        return {message,state:world.snapshot(p)};
      }
      case 'repairall': message='The original item tables have no durability to repair.'; break;
      case 'save': if (a.action !== 'now') throw new WorldError(400,'Use the Command Center save tools.'); message='Character saved.'; break;
      default: throw new WorldError(400, `/${'gm'} ${id} is not connected to the shared server yet. No local-only change was applied.`);
    }
    if(!sceneDurable)world.changed(p);
    world.emit(p.map,{type:'gm:command',actorId:p.id,command:id});
    if(durable){const gain={hp:Math.max(0,p.hp-hpBefore),mp:Math.max(0,(p.mp||0)-mpBefore)};const publication=await commitLife(host,live,p.profile,{stats:p.stats,hp:p.hp,mp:p.mp,vitalDeltas:gain,profileBefore:before,rewardProgress:true,revive:['heal','revive'].includes(id)});if(id==='cooldowns')live._skills?.engine.resetCooldowns();for(const[map,event]of notices)if(event.type!=='levelup'||publication.concurrentLevel<=before.level||event.level>publication.concurrentLevel)host.emit(map,event);for(const[map,event]of publication.notices)host.emit(map,event);return {message,state:host.snapshot(live)};}
    if(!sceneDurable)await world.persist(p);
    return { message, state:world.snapshot(p) };
  };
}
