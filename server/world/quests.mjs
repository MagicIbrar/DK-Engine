import {mapFor,sameScene} from './scene.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {isCustomScene,nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import { QuestDB } from '../../src/systems/quests/data.js';
import { QuestEngine } from '../../src/systems/quests/engine.js';
import { nativeKillBinding, turnInTalkBinding } from '../../src/systems/quests/objective-credit.js';
import {rankObjective,creditPvpResult,earnedKillKind,stoneObjective} from '../../src/systems/quests/native-earned-objectives.js';
import {zutoSnapshot} from './urban-warfare-controller.mjs';
import {nativeExchangeMenu} from '../../src/systems/quests/native-exchange-menus.js';
import { questHasNativeOffer } from '../../src/systems/quests/native-offer.js';
import { purchaseInfo } from '../../src/systems/quests/vehicle-purchase.js';
import { resolveQuestWarp } from '../../src/game/warp-location.js';
import { AuthoritativeInventory } from './inventory.mjs';
import { potionBelt } from '../../src/systems/items/belt.js';
import { DEFAULT_WORLD_RATES, scaledReward } from './rates.mjs';
import { isPremiumItem, checkPremiumItem, startPremium } from './premium-service.mjs';
import {randomUUID} from 'node:crypto';
import {refreshTitleStats} from './titles.mjs';
import { MountsData } from '../../src/systems/mounts/data.js';

/** A hatched pet item (mount data `isPet`) in the bag, the equipment, the stash or the account-shared stash (Global 330:4). */
export function ownsHatchedPet(world, profile) {
  const pets = new MountsData(); pets.core = world.data.mountData; pets.ui = world.data.mountUI;
  return [profile?.inventory, Object.values(profile?.equip?.items || {}), profile?.storage, profile?.accountFeatures?.shared]
    .filter(Array.isArray).some(list => list.some(item => item && pets.isPet(item.itemIndex)));
}

const fail = message => { throw Object.assign(new Error(message), { status: 400 }); };
const clone = value => structuredClone(value);
const questCatalogues = new WeakMap();
const freezeCatalogue=value=>{if(value&&typeof value==='object'&&!Object.isFrozen(value)){for(const child of Object.values(value))freezeCatalogue(child);Object.freeze(value);}return value;};
function readonlyQuestIndex(index){
 for(const ids of index.values())Object.freeze(ids);const refuse=()=>{throw Error('Quest catalogue indexes are read-only');};
 const view={size:index.size,get:key=>index.get(key),has:key=>index.has(key),entries:()=>index.entries(),keys:()=>index.keys(),values:()=>index.values(),set:refuse,delete:refuse,clear:refuse,[Symbol.iterator]:()=>index.entries(),forEach(callback,thisArg){index.forEach((ids,key)=>callback.call(thisArg,ids,key,view));}};
 return Object.freeze(view);
}
/** Prepared native catalogues are static. Actor/game, engine, inventory, effects
 * and lazy page/name memoization remain separate for every context. */
function questDatabase(data,tables,game){
 const refs=[tables.quests,tables.dialogs,tables.boxes,tables.npcs,tables.monsters,data.itemDB],vipName=data.itemDB.def?.(10000009)?.name;
 let cached=questCatalogues.get(data);
 if(!cached||cached.vipName!==vipName||refs.some((ref,i)=>cached.refs[i]!==ref)){
  const template=new QuestDB({data:{npcs:tables.npcs,monsters:tables.monsters},items:{db:data.itemDB}},tables.quests,tables.dialogs);
  template.Q=freezeCatalogue(clone(template.Q));template.B=tables.boxes;
  for(const key of ['byGiver','byTurnIn','byTalk'])template[key]=readonlyQuestIndex(template[key]);
  cached={refs,vipName,template:Object.freeze(template)};questCatalogues.set(data,cached);
 }
 return Object.defineProperties(Object.create(cached.template),{game:{value:game,writable:true,enumerable:true},_pageIndex:{value:new Map(),writable:true},_qin:{value:undefined,writable:true}});
}
function withQuestObjectiveViews(c,views,apply){
 const db=c.engine.db,original=db.quest,byId=new Map(views.map(([q,objectives])=>[Number(q.id),{...q,objectives}]));
 db.quest=id=>byId.get(Number(id))||original.call(db,id);
 try{return apply();}finally{db.quest=original;}
}

/** Existing quest rules with server-owned inventory/XP; commands contain intent only. */
export function createQuestContext(world, player, {profile:providedProfile,inventory:providedInventory,commitToPlayer=true}={}) {
  const tables = world.data.progression;
  if (!tables || !world.data.itemDB) return null;
  const profile = providedProfile || clone(player.profile), inventory = providedInventory || new AuthoritativeInventory(profile, world.data.itemDB, { now: world.now, random: world.random });
  const pending = [], warps = [], summons = []; let experience = 0;
  const game = { save: profile, now:world.now, random:world.random, player: { x: player.x, z: player.z, yaw: player.yaw },
    world: { info: { index: player.map } }, data: { npcs: tables.npcs, monsters: tables.monsters, gradeRows:world.data.nameplateGrades,exp:world.data.exp,dungeonMaps:world.data.dungeonData?.dg?.maps },
    items: { db: world.data.itemDB, bag: inventory.bag, def: i => world.data.itemDB.def(i), count: i => inventory.count(i),
      add: (i, n, o) => inventory.add(i, n, o), remove: (i, n) => inventory.remove(i, n), addDil: n => inventory.addDil(n),
      canAddAll: (list,opts={}) => inventory.canFit(list.map(([item, count]) => ({ item, count,...opts }))) },
    events: { emit: (kind, payload) => pending.push({ kind, ...payload }) },
    grantQuestExp: amount => { experience += scaledReward(amount,(world.rates||DEFAULT_WORLD_RATES).exp); },
    questWarp: warp => warps.push(warp),
    spawner: { spawnMonster: (index, x, z) => { summons.push({ index, x, z }); return true; } },
  };
  Object.defineProperty(game.items, 'dil', { get: () => inventory.dil });
  const db = questDatabase(world.data,tables,game);
  const questInventory=new Proxy(inventory,{get(target,key){if(key==='addDil')return amount=>target.addDil(amount>0?scaledReward(amount,(world.rates||DEFAULT_WORLD_RATES).dil):amount);const value=Reflect.get(target,key,target);return typeof value==='function'?value.bind(target):value;}});
  const engine = new QuestEngine(game, db, questInventory);
  engine._changed = () => {};
  engine.checkReset();
  return { game, engine, inventory, profile, tables, pending, warps, summons,
    commit() {
      if(commitToPlayer) player.profile = profile;
      if (experience) world.grantProgress(player, experience, 0);
      if(commitToPlayer&&pending.some(event=>event.kind==='life:title'))refreshTitleStats(world,player);
      if(commitToPlayer) {for(const event of pending)if(event.kind==='quest:complete')progressDekaPass(world,player,1,12,event.id,1);world.changed(player);}
      for (const event of pending) world.emit(player.map, { type: 'quest', actorId: player.id, kind: event.kind, questId: event.id, itemIndex: event.itemIndex, count: event.count });
    },
  };
}

export function starterQuest(tables) {
  return (tables.quests.lines?.main?.story || []).find(id => {
    const q = tables.quests.quests[id]; return Number(q?.giver?.map) === 150 && (q.level?.[0] || 1) <= 1;
  }) ?? 9414;
}

export function initializeProgression(world, player) {
  const c = createQuestContext(world, player); if (!c) return;
  const flags = c.engine.st.flags;
  if (!flags.starterGiven && world.starterPackEnabled?.() === false) {
    // this server hands out no starter pack (dashboard > Settings): the character is marked so switching it on later does not hand it out afterwards
    flags.starterGiven = world.now(); flags.starterPackSkipped = true;
  }
  if (!flags.starterGiven) {
    const list = (c.tables.boxes.starter?.onCreate || []).map(e => ({ item: Number(e.item), count: Math.max(0, (e.count || 1) - c.inventory.count(e.item)) })).filter(e => e.count);
    if (c.inventory.canFit(list)) {
      for (const item of list) if (!c.inventory.add(item.item, item.count)) fail('Starter rewards could not fit in your inventory.');
      flags.starterGiven = world.now();
    }
  }
  flags.starterQuest = starterQuest(c.tables);
  c.commit();
}

function nearNpc(world,c, player, npc, quest,service=false) {
  if (!Number.isInteger(npc)) return false;
  if(isCustomScene(world,player.map)){
    const row=nearbyNpc(world,player,{npcIndex:npc,radius:8});if(!row)return false;if(!service)return true;
    const direct=(c.tables.npcs.npcs?.[npc]?.jobs||[]).filter(([type,index])=>[1,106].includes(Number(type))&&Number(index)===Number(quest.id));
    return direct.length?direct.some(([type,index])=>offersOriginalJob(world,row,type,index)):row.roles.some(role=>['QUEST','QUEST_MAIN','REQUEST_QUEST','DAILY_REQUEST_QUEST','DAILY_QUEST_STD'].includes(role));
  }
  const placed = (c.tables.npcs.placements?.[player.map]?.rows || []).filter(row => Number(row[0]) === npc).map(row => [Number(row[1]), Number(row[2])]);
  const positions = placed.length ? placed : [quest?.giver, quest?.turnIn].filter(who => Number(who?.npc) === npc && Number(who?.map) === player.map && Array.isArray(who.pos)).map(who => who.pos);
  return positions.some(([x,z]) => Math.hypot(player.x-x, player.z-z) <= 8);
}

export async function questCommand(world, player, input) {
  const c = createQuestContext(world, player); if (!c) fail('Quest data is unavailable.');
  if (!Number.isInteger(input.questId)) fail('Choose an original quest.');
  const q = c.engine.db.quest(input.questId); if (!q || q.isGroup) fail('Choose an original quest.');
  const npc = input.npc == null ? null : input.npc;
  const accept = input.operation === 'accept' || input.operation === 'instant';
  const offeredStarter = input.questId === starterQuest(c.tables) && player.map === 150 && !c.engine.st.flags.autoStarted;
  if (accept && !offeredStarter) {
    // Only a native offering path (NPC quest job, request board, giver of an offered quest, NextIndex chain) can start a quest;
    // a giverless or unlisted quest is never accepted from a client command (src/systems/quests/native-offer.js).
    if (!c.engine.offerPath(q.id, { npc })) fail(questHasNativeOffer(c.engine.db.Q, q) ? 'Walk to the quest giver before accepting this quest.' : 'No original NPC offers this quest.');
    if (!nearNpc(world,c, player, npc, q,true)) fail('Walk to the quest giver before accepting this quest.');
  }
  if (input.operation === 'claim') {
    const turnIn = q.turnIn?.npc ?? q.giver?.npc;
    const allowed = [turnIn, ...(q.turnIn?.alt || [])].map(Number);
    if (turnIn != null && (!allowed.includes(npc) || !nearNpc(world,c, player, npc, q,true))) fail('Walk to the turn-in NPC before claiming this quest.');
    if(q.rewardVariants?.mode==='choice'){
      const choice=q.rewardVariants.list.find(v=>Number(v.option)===input.option&&(v.classIndex==null||Number(v.classIndex)===player.profile.classIndex));
      if(!choice)fail('Choose an original reward for this class.');
      if(choice.slot!=null){const objective=q.objectives?.find(o=>Number(o.slot)===Number(choice.slot));if(!objective||!c.engine.objectiveDone(q,objective))fail('Complete the original objective for this reward choice.');}
    }
  }
  if (input.operation === 'talk' && !nearNpc(world,c, player, npc, q)) fail('Walk to this NPC before speaking.');
  if(input.operation==='exchange'){
    if(!nativeExchangeMenu(c.engine.db,q.id)||!c.engine.offerPath(q.id,{npc})||!nearNpc(world,c,player,npc,q,true))fail('Walk to the original exchange NPC.');
  }
  if (input.operation === 'purchase') {
    // "Purchase." of a scripted vehicle-purchase dialog (Sergio, quest 15820): the NPC that lists the dialog sells, and must be within reach
    if (!purchaseInfo(c.engine.db, q.id)) fail('This dialog sells nothing.');
    const sellers = [q.giver?.npc, ...(q.giver?.alt || []), ...(q.listedBy || []).map(l => l[0])].map(Number);
    if (!Number.isInteger(npc) || !sellers.includes(npc) || !nearNpc(world,c, player, npc, q, true)) fail('Walk to the seller before buying.');
  }
  let result;
  const options = { npc, option: input.option ?? null, silent: true };
  if (input.operation === 'accept') result = c.engine.accept(q.id, options);
  else if (input.operation === 'instant') {
    if (!c.engine._instant(q)) fail('This quest requires its original objectives.');
    result = c.engine.acceptInstant(q.id, options);
  } else if (input.operation === 'claim') result = c.engine.claim(q.id, options);
  else if (input.operation === 'talk') {
    const investigating=(q.objectives||[]).some(o=>stoneObjective(q,o)?.includes(npc));
    if(investigating){
      // Durable quest commands clone the profile/actor, while the battlefield
      // admission deliberately recognizes only the live lease in world.players.
      // Resolve that lease without replacing the candidate whose journal we save.
      const actor=world.players?.get(player.account),same=actor&&['id','token','characterId','map','instanceId','channel','x','z'].every(key=>actor[key]===player[key]);
      const live=same?zutoSnapshot(world,actor):null,mine=live?.mine;
      if(!live||live.phase!=='battle'||!mine||mine.left||mine.evicted||actor.dead||player.dead)fail('Enter the active Zuto battlefield before investigating its guardian stones.');
    }
    // Online talk resolves actual talk objectives and the per-row original turn-in talks (objective-credit.js TURN_IN_TALK) only.
    withQuestObjectiveViews(c,[[q,(q.objectives||[]).filter(o=>o.kind==='talk'||turnInTalkBinding(q.id,o)||rankObjective(q,o)||stoneObjective(q,o))]],()=>c.engine.talkTo(npc,q.id));
    result = { ok: true };
  } else if (input.operation === 'abandon') result = { ok: c.engine.abandon(q.id) };
  else if (input.operation === 'track') result = { ok: c.engine.track(q.id, input.on !== false) };
  else if (input.operation === 'purchase') result = c.engine.purchase(q.id, options);
  else if(input.operation==='exchange')result=c.engine.exchange(q.id,options);
  else fail('Unknown quest action.');
  if (!result?.ok && input.operation === 'purchase') {
    // the host cannot chat: the refusal travels as the error text (original common quest strings where they exist)
    const original = result?.code != null && typeof result.code === 'number' ? c.engine.db.common(result.code) : null;
    fail(original ? String(original).replace(/<[^>]+>/g, '').replace(/^\s*\[[^\]]*\]\s*/, '').trim() : result?.code === 'soldout' ? "I don't have any left in stock." : 'The purchase could not be completed.');
  }
  if (!result?.ok) {
    // A quest's OWN 1000/1001/1002 refusal message (ticket NPCs: 1000 already held, 1001 Super Pass shortfall,
    // 1002 Holy Water) travels as the error text exactly as the local engine prints it; the code stays on the
    // error. Other codes, and quests without their own string, keep the generic text.
    let own = result?.page?c.engine.db.pageText(q.id,result.page):null;
    if ([100,101,1000, 1001, 1002].includes(result?.code) && c.engine.db.str(q.id, result.code, { common: false }) != null) {
      const say = c.engine.say; c.engine.say = text => { own = String(text ?? ''); };
      try { c.engine.message(result.code, q); } finally { c.engine.say = say; }
      own = own?.replace(/^\s*\[[^\]]*\]\s*/, '').trim() || null;
    }
    throw Object.assign(new Error(own || `The quest requirements are not met${result?.code ? ` (${result.code})` : ''}.`), { status: 400, ...(typeof result?.code === 'number' ? { code: result.code } : {}) });
  }
  if (accept && input.questId === starterQuest(c.tables)) c.engine.st.flags.autoStarted = world.now();
  let warpTarget=null;
  if(c.warps.length){
    // a location the client table leaves at (0,0) resolves to its pair's arrival row (src/game/warp-location.js, ENGINE-CHOSEN)
    const warp=resolveQuestWarp(c.warps.at(-1),i=>world.data.travelData?.locations?.[String(i)]??null)||c.warps.at(-1);
    const map=await world.data.map(Number(warp.map),{instance:!!world.data.requiresInstance?.(Number(warp.map))}),point=map.nearest(Number(warp.pos[0])+0.5,Number(warp.pos[1])+0.5);if(!point)fail('No safe quest arrival point is available.');warpTarget={map:Number(warp.map),...point};}
  c.commit();
  return { ...result, context: c, warpTarget };
}

// Quest 18027 journal and COUNT0/COUNT1/COUNT3 messages identify these exact clears.
// Original maplist/dungeonlist distinguish A/unsuffixed from C/B/Depth/Hard.
const recoveredClears=new Map([[0,{map:33,label:"Crespo's Treasure A"}],[1,{map:176,label:"Favnil's Nest"}],[3,{map:31,label:'Magic Field of Crack'}]]);
function withRecoveredClearObjectives(c,apply){
  const views=[];
    const q=c.engine.db.quest(18027);
    if(c.engine.st.active[18027]&&q&&!q.isGroup&&q.dialog?.file==='share/quest/quest_18027_proveyourself169_daily.csv'){
      views.push([q,(q.objectives||[]).map(o=>{
        const rule=recoveredClears.get(o.slot);
        return rule&&o.kind==='scripted'&&o.count===1&&o.label===rule.label
          ? {...o,kind:'clearMap',targets:[{id:rule.map}]} : o;
      })]);
    }
    return withQuestObjectiveViews(c,views,apply);
}

// A kill only has to build the full quest context (deep clone of the profile + a new QuestDB + QuestEngine, 1.5 - 10 ms per kill)
// when one of the player's ACTIVE quests can react to this monster: a kill / killOnMap objective, a scripted kill / collect hint
// (matched by monster name), or a quest-item drop list that names the monster. Everything else in QuestEngine.onKill is a no-op
// (no random roll, no progress line, no event), so those kills only need the state the full path always left behind:
// the profile's quest / inventory / potion-belt defaults, the daily / weekly period reset and the changed() mark.
const killTraitCache = new WeakMap();
function killTraits(q) {
  let t = killTraitCache.get(q);
  if (t) return t;
  t = { always: false, kill: new Set(), ranges: [], maps: new Set(), drops: new Set() };
  for (const o of q.objectives || []) {
    if(earnedKillKind(q,o))t.always=true;
    if (o.kind === 'kill') { for (const x of o.targets || []) t.kill.add(Number(x.id)); if (Array.isArray(o.range)) t.ranges.push(o.range); }
    else if (o.kind === 'killOnMap') { for (const x of o.targets || []) t.maps.add(Number(x.id)); }
    else if (o.kind === 'scripted' && (o.hint === 'kill' || o.hint === 'collect')) t.always = true;
    else { const bound = nativeKillBinding(q.id, o); if (bound) for (const m of bound.monsters) t.kill.add(m); }
  }
  for (const d of q.drops || []) for (const m of d.monsters || []) t.drops.add(Number(m));
  killTraitCache.set(q, t);
  return t;
}
/** True when any active quest of the player could react to this kill (a superset of what QuestEngine.onKill acts on). */
function questListensToKill(tables, player, monster) {
  const defs = tables.quests?.quests;
  if (!defs) return true;
  const active = player.profile.quests?.active;
  if (!active) return false;
  const ids = Object.keys(active);
  if (!ids.length) return false;
  const mi = Number(monster.monsterIndex ?? monster.def?.index ?? monster.index), map = Number(player.map);
  for (const id of ids) {
    const q = defs[id];
    if (!q) continue;
    const t = killTraits(q);
    if (t.always || t.kill.has(mi) || t.maps.has(map) || t.drops.has(mi)) return true;
    for (const r of t.ranges) if (mi >= r[0] && mi <= r[1]) return true;
  }
  return false;
}
export function questKill(world, player, monster) {
  const tables = world.data.progression;
  if (!tables || !world.data.itemDB) return;
  if (questListensToKill(tables, player, monster)) return questKillFull(world, player, monster);
  // Same profile state as the full path leaves behind, without the clone: defaults (inventory, potion belt, quests) and the period reset in place.
  const profile = player.profile;
  profile.inventory ||= [];
  potionBelt(profile, world.data.itemDB);
  new QuestEngine({ save: profile, now: world.now }, null, null).checkReset();
  world.changed(player);
}
function questKillFull(world, player, monster) {
  const c = createQuestContext(world, player); if (!c) return;
  withRecoveredClearObjectives(c,()=>c.engine.onKill({ ...monster, kind: 'monster' }, c.game.player)); c.commit();
}

/** Trusted activity hooks, never a browser command to advance arbitrary objective slots. */
function questActivity(world,player,kind,value,count,{profile,emit=true,itemIndex=null}={}){
  const c=createQuestContext(world,player,{profile,commitToPlayer:!profile});if(!c)return null;
  const before=JSON.stringify(c.profile.quests);
  if(kind==='skill')c.engine.onSkill(value);
  else if(kind==='fish')c.engine.onFish(count,itemIndex);
  else if(kind==='clear'){
    // Neither engine treats unresolved scripted:dungeon hints as any clear (objective-credit.js).
    // Online clears advance explicit catalog and individually recovered clearMap objectives.
    // Keep all four objectives visible while advancing, so partial clears never mark ready.
    withRecoveredClearObjectives(c,()=>{
      const q=c.engine.db.quest(18027);
      if(c.engine.st.active[18027])for(const o of q?.objectives||[])
        if(o.kind==='clearMap'&&recoveredClears.get(o.slot)?.map===value)c.engine.advance(18027,o.slot,1);
    });
    const views=c.engine.activeIds().map(id=>c.engine.db.quest(id)).filter(Boolean).map(q=>[q,(q.objectives||[]).filter(o=>o.kind==='clearMap')]);
    withQuestObjectiveViews(c,views,()=>c.engine.onClearMap(value));
  }
  if(before===JSON.stringify(c.profile.quests))return null;
  if(emit)c.commit();return c;
}
export function questSkill(world,p,index,options){if(!Number.isSafeInteger(index)||index<0)return null;return questActivity(world,p,'skill',index,1,options);}
export function questFish(world,p,count=1,options){if(!Number.isSafeInteger(count)||count<1)return null;return questActivity(world,p,'fish',0,count,options);}
export function questClear(world,p,map,options){if(!Number.isSafeInteger(map)||map<0)return null;return questActivity(world,p,'clear',map,1,options);}

// Host result producer; no corresponding arbitrary-progress browser command.
// A settlement should pass its candidate profile with emit:false, then publish
// the resulting profile and notifications only when that settlement saves.
export function questPvpResult(world,player,result,{profile,emit=true}={}){
 const c=createQuestContext(world,player,{profile,commitToPlayer:!profile});if(!c)return null;
 const before=JSON.stringify(c.profile.quests);creditPvpResult(c.engine,result);
 if(before===JSON.stringify(c.profile.quests))return null;
 if(emit)c.commit();return c;
}

export function boxCommand(world, player, input, context=null) {
  const c = context || createQuestContext(world, player); if (!c) fail('Box data is unavailable.');
  if (typeof input.uid !== 'string') fail('Choose a carried box.');
  const inst = c.inventory.bag.list.find(e => e.uid === input.uid);
  if (!inst || (inst.expiresAt && inst.expiresAt <= world.now())) fail('This box is not in your inventory.');
  // The Holy Water of the Almighty is a box item whose reward is the premium service (premium-service.mjs).
  const premiumBox = isPremiumItem(world, inst.itemIndex) && !Number.isFinite(inst.premiumActivatedAt);
  if (premiumBox) checkPremiumItem(world, c.profile, inst.itemIndex);
  const b = c.tables.boxes.boxes?.[inst.itemIndex];
  if (!b || b.orphan) fail('This item is not a usable box.');
  if (player.profile.level < (b.lv || 1) || (b.maxLv && player.profile.level > b.maxLv) || (Array.isArray(b.job) && !b.job.includes(player.profile.classIndex))) fail('This box cannot open at your class or level.');
  const take = Math.max(1, b.take || 1);
  if ((inst.count || 1) < take) fail('Not enough boxes in this stack.');
  // Global msgbox/ui_alreadyhatch (330:3/330:4): "If you possess a hatched pet in the stash or inventory, you cannot hatch another pet."
  if (b.k === 'egg' && ownsHatchedPet(world, c.profile)) fail('You already own a pet.');
  const list = (b.e || []).map((e,i) => ({ item: Number(e[0]), count: Math.max(1, Number(e[1]) || 1), weight: Number(e[2]) || 0, i })).filter(e => !(b.missing || []).includes(e.item) && (b.k === 'itemset' || (b.k==='summon'?world.data.monsterDef(e.item):c.inventory.db.def(e.item))));
  let got = [], key = null;
  if (b.k === 'select') {
    const choices = input.choices;
    const count = Math.max(1, Math.min(list.length, b.give || 1));
    if (!Array.isArray(choices) || choices.length !== count || new Set(choices).size !== count || choices.some(i => !Number.isInteger(i) || !list.some(e => e.i === i))) fail('Select the required original box entries.');
    got = choices.map(i => list.find(e => e.i === i));
  } else if (['all','package'].includes(b.k)) got = list;
  else if (['random','keyed','itemset','egg','summon'].includes(b.k)) {
    if (b.k === 'keyed') { key = (b.keys || []).find(i => c.inventory.count(i)); if (!key) fail('A matching key is required.'); }
    for (let n=0;n<Math.max(1,b.give || 1);n++) {
      const sum = list.reduce((a,e) => a+e.weight,0), allSum = (b.e || []).reduce((a,e) => a+(Number(e[2]) || 0),0);
      let total = b.total || allSum; if (allSum && sum < allSum) total *= sum/allSum;
      let picked = null;
      if (!sum) picked = list[Math.floor(world.random()*list.length)];
      else { let r=world.random()*Math.max(sum,['keyed','itemset','egg','summon'].includes(b.k) ? sum : total); for (const e of list) {r-=e.weight;if(r<0){picked=e;break;}} }
      if (!picked) continue;
      if (b.k === 'itemset') {
        const set = (c.tables.boxes.itemSets?.[picked.item]?.e || []).filter(e => c.inventory.db.def(e[0]));
        let r=world.random()*set.reduce((a,e) => a+(Number(e[1])||1),0);
        for(const e of set){r-=Number(e[1])||1;if(r<0){got.push({item:Number(e[0]),count:Math.max(1,Number(e[3])||1)});break;}}
      } else got.push(picked);
    }
    if (b.bonus) got.push({ item: Number(b.bonus[0]), count: Math.max(1,b.bonus[1] || 1) });
  } else fail('This specialized box needs a server-supported pet or summon system.');
  let spawned=[];
  if(b.k==='summon'){
    const map=mapFor(world,player);if(!map||Number(map.row?.PeaceZone??0)===1)fail('You cannot summon monsters in the Safety Zone.');
    if([...map.monsters.values()].filter(m=>m.boxOwner===player.id&&!m.dead).length+got.reduce((n,e)=>n+e.count,0)>40)fail('Too many box monsters are already active.');
    for(const e of got){if(e.count>32)fail('This summon count exceeds the shared-world limit.');const def=world.data.monsterDef(e.item);if(!def)fail('Unknown box monster.');for(let n=0;n<e.count;n++){const x=player.x-Math.sin(player.yaw||0)*2.5+(n?world.random()*2-1:0),z=player.z-Math.cos(player.yaw||0)*2.5+(n?world.random()*2-1:0);if(!map.isWalkable(x,z))fail('No safe summon point is available.');spawned.push({id:'box:'+randomUUID(),map:player.map,instanceId:player.instanceId||null,boxOwner:player.id,expiresAt:world.now()+600000,monsterIndex:e.item,name:def.name,x,z,hp:def.hp,maxHp:def.hp,home:{x,z},dead:false,targetId:null,attackAt:0,respawnAt:0,respawnSec:Infinity,def})}}
  }else if (!c.inventory.canFit(got)) fail('Your inventory is full. Make space before opening this box.');
  if (!c.inventory.consumeEntry(inst,take)) fail('This box could not be consumed.');
  if (key && !c.inventory.remove(key,1)) fail('The matching key could not be consumed.');
  if(b.k==='summon'){for(const monster of spawned){monster.channel=player.instanceId?0:player.channel??0;mapFor(world,player).monsters.set(monster.id,monster)}}
  else for(const e of got) if(!c.inventory.add(e.item,e.count)) fail('Box rewards could not be placed.');
  if (premiumBox) startPremium(world, c.profile, inst.itemIndex);
  c.engine.recountCollect(null,true); c.commit();
  // itemuse already credits through its facade; the direct box UI owns this path.
  if(!context)progressDekaPass(world,player,5,22,inst.itemIndex,1);
  world.emit(player.map,{type:'box',actorId:player.id,itemIndex:inst.itemIndex,got:got.map(({item,count})=>({item,count}))});
  return {ok:true};
}

export function itemBoxFacade(world,player,profile,inventory){
  const boxes=world.data.progression?.boxes?.boxes || {};
  return {ready:Promise.resolve(true),isBox:index => !!boxes[index]&&!boxes[index].orphan,info:index=>boxes[index],
    open:async entry => boxCommand(world,player,{uid:entry.uid},createQuestContext(world,player,{profile,inventory,commitToPlayer:false})).ok};
}

export function questInventoryChanged(world,player){
  const context=createQuestContext(world,player);if(!context)return false;
  const before=JSON.stringify(context.profile.quests);
  context.engine.recountCollect(null,true);
  if(before===JSON.stringify(context.profile.quests))return false;
  context.commit();return true;
}
