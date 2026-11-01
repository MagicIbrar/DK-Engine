import {GAMEPLAY_PREFERENCE_SCHEMAS,gameplayPreferenceCommand} from './gameplay-preferences.mjs';
import {claimEligibleGradeRewards} from '../../src/game/grade-rewards.js';
import {durableQuestCommand,durableItemBoxFacade} from './quest-transactions.mjs';
import {randomUUID} from 'node:crypto';
import {npcSlotsAvailable} from './npc-human-slots.mjs';
import {publicNameplate} from './nameplates.mjs';
import {ORDINARY_RESPAWN_WAIT_MS} from '../../src/config/engine-chosen-respawn.js';
import {reviveNativeDungeon} from './dungeon-respawn.mjs';
import {reviveWithLifeBead,lifeBeadReviveAllowed} from './life-bead-revive.mjs';
import {reviveNativeField} from './field-respawn.mjs';
import {DUNGEON_SCHEMAS,dispatchDungeon,tickDungeons,dungeonSnapshot} from './dungeons.mjs';
import {TRAVEL_SCHEMAS,travelCommand,smartWarpState,tickTravel,commitFieldTravel,travelFrozen} from './travel.mjs';
import {objectHitPoint} from './object-combat.mjs';
import {isEventObject,eventObjectActive,eventObjectDamage,rewardEventObject} from './event-object-combat.mjs';
import {canClaimDeadFrontTreasure} from './dead-front-treasure.mjs';
import {EVENT_SCHEMAS,eventCommand,tickEvents,eventSnapshot,partyWarAnnouncements,partyWarLobbySnapshot} from './events.mjs';
import {OX_QUIZ_SCHEMAS,oxQuizCommand,tickOxQuiz,oxQuizSnapshot,oxSpikeCanTarget,tickOxSpikeCombat} from './ox-quiz.mjs';
import {POINT_RESET_SCHEMAS,pointResetCommand} from './point-resets.mjs';
import {ZUTO_SCHEMAS,zutoCommand,tickZuto,zutoSnapshot,reviveZuto,isZutoBattlefieldTeleport,zutoEnterBattlefield} from './urban-warfare-controller.mjs';   // owner-directed Zuto adaptation (urban-warfare-rules.js ZUTO_ADAPTATION)
import {SIEGE_RENEW_SCHEMAS,siegeRenewCommand,tickSiegeRenew,siegeRenewSnapshot,isSiegeRenewObject,siegeRenewObjectActive,siegeRenewObjectDamage,rewardSiegeRenewObject,reviveSiegeRenew} from './siege-renew-controller.mjs';
import {stepEventMarch} from './event-march.mjs';
import {isSiegeRenewGuard,siegeRenewGuardActive,siegeRenewGuardCanTarget,rewardSiegeRenewGuard,tickSiegeRenewGuardDeath} from './siege-renew-sentries.mjs';
import {attackSiegeRenewGuard,tickSiegeRenewGuardCombat} from './siege-renew-sentry-combat.mjs';
import {raceSnapshot} from './race.mjs';
import {Collision} from '../../src/world/collision.js';
import {PathFinder} from '../../src/world/pathfind.js';
import {regenStep} from '../../src/game/progression.js';
import {playerDefeatReaction} from '../../src/game/hit-reaction.js';
import {restoreInstance,disposeEmptyInstances,exitInstance,enterTrustedScene} from './instances.mjs';
import {restoreDeadIslandRun} from './dead-island.mjs';
import {deadIslandSuicide,deadIslandMonsterAttack} from './dead-island-run.mjs';
import {sceneKey,sameScene,mapFor} from './scene.mjs';
import {rememberNativeFieldScene,parkNativeFieldScene} from './npc-field-residency.mjs';
import {LIFE_EVENT_SCHEMAS,lifeEventCommand,recordLifeEventKill} from './life-events.mjs';
import { randomBytes } from 'node:crypto';
import { assertUrbanWarfareAdmissionAvailable } from './urban-warfare.mjs';
import { publicAppearance } from './appearance.mjs';
import { battleAppearance } from './battle-looks.mjs';
import {Equipment,S,PRESETS} from '../../src/systems/items/equip.js';
import {Container} from '../../src/systems/items/model.js';
import {readWorldRates,scaledReward} from './rates.mjs';
import { PARTY_SCHEMAS, partyCommand, partySnapshot, leaveParty, nearbyPartyMembers, partyExpRewards } from './party.mjs';
import { EXPEDITION_SCHEMAS, expeditionCommand, expeditionSnapshot } from './expedition.mjs';
import { initializeProgression, questCommand, boxCommand, questKill, itemBoxFacade, questInventoryChanged } from './quests.mjs';
import { ITEM_ACTION_SCHEMAS, dispatchItemAction, expireItemEffects } from './items.mjs';
import { SHOP_ACTION_SCHEMAS, dispatchShopAction } from './shops.mjs';
import { initializeStarterSkills, SKILL_SCHEMAS, skillCommand, tickSkills, skillControls, itemSkillFacade, summonSnapshot, incomingSkillDamage, skillStatusVisuals, skillTransformVisual, activeRemaining } from './skills.mjs';
import {resurrectionSnapshot} from './resurrection-offer.mjs';
import {sharedTargetSnapshot,noteSharedTargetIntent} from './shared-target.mjs';
import {captureRejoinRecovery,restoreRejoinRecovery} from './rejoin-recovery.mjs';
import { LOOT_ACTION_SCHEMAS, dispatchLootAction, groundDrops, monsterLoot } from './loot.mjs';
import { ENHANCEMENT_ACTION_SCHEMAS, dispatchEnhancement } from './enhancement.mjs';
import { MOUNT_SCHEMAS, mountCommand, tickMount, mountBusy, mountState } from './mounts.mjs';
import {authorizedGMSpeed,canonicalMovementSpeed,pathMovementSpeed} from './movement-speed.mjs';
import {MOVEMENT_REPORT_FIELDS,hasMovementReport,applyMovementReport,trackForcedDisplacement,noteHostStep,noteSkillRootMotion,trackMovementBlock,reportingMovement,expireIdleReport,movementSelf,movementPublic} from './movement-authority.mjs';
import {startAttackRoot,tickAttackRoot,clearAttackRoot,attackStepFor,commitAttackStep,previewAttackStep,commitAttackStepAdmission} from './attack-root-motion.mjs';
import { CONVERSION_ACTION_SCHEMAS, dispatchConversion } from './conversions.mjs';
import {PET_SCHEMAS,petCommand,tickPet,petState,initializePets} from './pets.mjs';
import {DEKAPASS_SCHEMAS,initializeDekaPass,progressDekaPass,tickDekaPass,dekapassCommand} from './dekapass.mjs';
import {CRAFTING_SCHEMAS,initializeCrafting,craftingCommand} from './crafting.mjs';
import {FISHING_SCHEMAS,fishingCommand,fishingState,fishingPose,tickFishing,cancelFishing,fishingBusy} from './fishing.mjs';
import {SUPPLY_SCHEMAS,supplyCommand} from './supply.mjs';
import {EMOTE_SCHEMAS,emoteCommand,endSitting} from './emotes.mjs';
import {SUPPORT_REWARD_SCHEMAS,supportRewardCommand,tickSupportRewards,recordSupportRewardKill} from './support-rewards.mjs';
import {levelCapRate} from './level-caps.mjs';
import {applyAbilityCap} from '../../src/game/ability-cap.js';
import {combatOptionValue,penetratedDefense,criticalChance,criticalDamageMultiplier,modifyHitDamage,blockChance,guardChance,guardEfficiency} from '../../src/game/combat.js';
import {SOCIAL_SCHEMAS,socialChat} from './social.mjs';
import {TRADE_SCHEMAS,tradeCommand,tradeSnapshot,cancelTrade,tickTrades} from './trade.mjs';
import {CHAR_TRADE_SCHEMAS,charTradeCommand,charTradeSnapshot,cancelCharTrade,tickCharTrades} from './char-trade.mjs';
import {PET_SERVICE_SCHEMAS,petServiceCommand} from './pet-services.mjs';
import {VEHICLE_SERVICE_SCHEMAS,vehicleServiceCommand} from './vehicle-services.mjs';
import {MAIL_SCHEMAS,mailCommand,mailSnapshot} from './mail.mjs';
import {CONSIGN_SCHEMAS,consignCommand,consignmentSnapshot} from './consignment.mjs';
import {PVP_SCHEMAS,pvpCommand,pvpAttack,tickPvp,pvpSnapshot,noteForcedIntent,isPvpTarget} from './pvp.mjs';
import {pkRefusalText} from './field-pk.mjs';   // FIELD-PK: registers the forced-attack PvP mode
import {furyHit,furyHurt,tickFury,furyOf} from './fury.mjs';   // Half Bagi fury gauge (without it every fury skill is refused online)
import {PARTY_PVP_SCHEMAS,PARTY_PVP_TEXT,partyPvpCommand,partyPvpGuard,tickPartyPvp,partyPvpSnapshot,partyPvpBlocksRevive} from './party-pvp.mjs';
import {TRAINING_CAMP_SCHEMAS,TRAINING_CAMP_TEXT,trainingCampCommand,tickTrainingCamp,trainingCampSnapshot,trainingCampBlocksRevive} from './training-camp.mjs';
import {DK_SQUARE_SCHEMAS,dkSquareCommand,tickDkSquare,dkSquareSnapshot} from './dk-square.mjs';
import {COLOSSEUM_SCHEMAS,COLOSSEUM_REVIVE_TEXT,colosseumCommand,colosseumSnapshot,tickColosseum,colosseumBlocksRevive} from './colosseum.mjs';
import {tickSiege} from './siege.mjs';
import {tickGuildWarPvp} from './guild-war-pvp.mjs';
import {GUILD_SCHEMAS,guildCommand,guildSnapshot} from './guilds.mjs';
import {tickGuildFrontier} from './guild-frontier.mjs';
import {runNpcServiceScope,battleStatusUntil} from './npc-service-guard.mjs';
import {ITEM_SERVICE_SCHEMAS,itemServiceCommand} from './item-services.mjs';
import {IAN_SCHEMAS,weaponLookCommand,tickWeaponLooks} from './ian-appearance.mjs';
import {PREMIUM_SCHEMAS,premiumCommand,premiumRespawn} from './premium.mjs';
import {NAME_CHANGE_SCHEMAS,charNameCommand} from './name-change.mjs';
import {MEGAPHONE_SCHEMAS,megaphoneCommand,tickMegaphone} from './megaphone.mjs';
import {premiumExpPercent,premiumPartyBonus,syncPremiumBuffs} from './premium-service.mjs';
import {playerRewardBonus} from '../../src/game/reward-bonus.js';
import {flushInstanceProgress} from './instance-progress.mjs';
import {itemCooldownState,itemCooldownEntries} from './item-cooldowns.mjs';
import {idleMonster} from './monster-idle.mjs';
import {CHANNEL_SCHEMAS,channelCommand,restoreChannel,reviveScene,isDkChannel,validateLoginChannel,loginChannel} from './channels.mjs';
import {HUNT_SCHEMAS,OBSERVER_ACTIONS,huntCommand,huntRevive,huntSnapshot,isHuntObserver,tickGuildWarHunting} from './guild-war-hunting.mjs';
import {TOURNEY_SCHEMAS,TOURNEY_REVIVE_TEXT,tourneyCommand,tourneySnapshot,tickGuildTournament,tourneyBlocksRevive} from './guild-tournament.mjs';
import {DKR_SCHEMAS,DKR_REVIVE_TEXT,dkrCommand,dkrSnapshot,tickDkrPvp,dkrBlocksRevive} from './dkr-pvp.mjs';
import {isObserver,observerAllows} from './observers.mjs';
import {PCSHOP_SCHEMAS,pcshopCommand,pcshopGuard,publicPcShop,pcshopSnapshot,isShopOpen} from './pcshop.mjs';
import {PARTY_FINDER_SCHEMAS,partyFinderCommand,partyFinderGuard,withPartyFinder} from './party-finder.mjs';
import {MESSENGER_SCHEMAS,messengerCommand} from './messenger.mjs';
import {BLACKLIST_SCHEMAS,blacklistCommand} from './blacklist.mjs';
import {BATTLE_SUPPORT_SCHEMAS,battleSupportCommand,tickBattleSupport,battleSupportSnapshot} from './battle-support.mjs';
import {NPC_FRIEND_SCHEMAS,npcFriendCommand} from './npc-friends.mjs';
import {FRIEND_REQUEST_SCHEMAS,friendRequestCommand} from './friend-requests.mjs';
import {PCRoomChecking} from './pcroom.mjs';
import {NORMAL_ATTACK_CONTACT as NORMAL_CONTACT} from '../../src/config/engine-chosen-normal-attack.js';
import {attackReady,nextAttackAt,playerAttackLimit} from '../../src/game/attack-timing.js';
import {rememberHumanPresentation,pendingPresentationEvents} from './presentation-backlog.mjs';
import {SERVER_LOAD_ENGINE_CHOSEN as SERVER_LOAD} from '../../src/config/engine-chosen-server-load.js';
// Per-monster AI rules shared with the offline brain (src/game/ai.js): sight / pursuit / speeds / reach / attack choice /
// call-team / statuses from monsters.json, the engine-chosen fallbacks from src/config/engine-chosen-monster-ai.js.
import {aggroRadius,leashRange,chaseSpeed,isImmobile,bodyRadius,isNonCombatant,canAttack,preferredReach,canAcquire,shouldLeash,chooseAttack,attackKind,attackVariant,statusSpeedMul,statusFlags,respawnDelayMs,persuitOutRule,REST_STATE,rehomes,roamCentre} from '../../src/game/monster-rules.js';
import {pickTarget,clearHate,plainHitHate} from '../../src/game/hate.js';
import {monsterHit} from './monster-hit.mjs';
import {FollowBook,followLimit,hatedAlternatives} from '../../src/game/follow-cap.js';
import {MONSTER_AI_ENGINE_CHOSEN as MONSTER_AI} from '../../src/config/engine-chosen-monster-ai.js';

export class WorldError extends Error { constructor(status, message) { super(message); this.status = status; } }
const distance = (a, b) => Math.hypot(a.x - b.x, a.z - b.z);
const clone = value => JSON.parse(JSON.stringify(value));
const finite = value => typeof value === 'number' && Number.isFinite(value);
const VIEW_CELLS = SERVER_LOAD.viewCells, SNAPSHOT_MONSTER_CAP = SERVER_LOAD.snapshotMonsterCap;
// placeholder of the monster rows inside a broadcast snapshot's JSON (snapshotText); a random string never present in game data
const ROWS_TOKEN = `__dekaronMonsterRows_${randomUUID()}`, PLAYER_ROWS_TOKEN = `__dekaronPlayerRows_${randomUUID()}`, PLAYER_ROW_TEXT = new WeakMap();
// event ring / per-snapshot cap (ENGINE-CHOSEN, src/config/engine-chosen-server-load.js)
const EVENT_RING = SERVER_LOAD.eventRing, EVENT_TRIM = SERVER_LOAD.eventRingTrim, EVENT_SNAPSHOT_CAP = SERVER_LOAD.eventSnapshotCap;

/** Server-only simulation. Client commands contain intent, never stats, HP, rewards or inventory snapshots. */
// Full shields on explicit respawn. Rejoining preserves the saved remainder.
function refillShield(p) { p.maxShield = Math.max(0, Number(p.stats?.maxShield) || 0); p.shield = p.maxShield; }
const armorSlots=[S.helmet,S.armor,S.pants,S.glove,S.boots];
/** ENGINE-CHOSEN admission preparation, only inside trusted staged wave CAS.
 * Transfer existing marked stock into EMPTY active armor slots. No rewards,
 * requirements allocation, replacement, HP fill or live equipment mutation. */
export function prepareOwnedNpcArmor(profile,data,{account,characterId,trustedWave=false,now=Date.now}={}){
 const unchanged=()=>({profile,equipped:0});
 if(trustedWave!==true||!/^npc_[a-f0-9]{32}$/.test(account||'')||profile?.id!==characterId||profile?.authority!=='server'||profile.npcPlayer!==true||!data?.itemDB||typeof data.stats!=='function'||!(profile.hp==null||Number.isFinite(profile.hp)&&profile.hp>0)||profile.instanceId||profile.instance||profile.dkReturn||profile.partyId||profile.tradeId||profile.pcShopOpen||profile.npcEquipment?.phase==='working'||profile.npcFishing||profile.npcMerchantReservation?.phase==='held'||['listing','open','closing'].includes(profile.npcMerchant?.phase))return unchanged();
 const stock=profile.npcSeed?.stock,e=profile.equip;
 if(stock?.policy!=='ENGINE-CHOSEN'||!Array.isArray(stock.uids)||stock.uids.length>22||new Set(stock.uids).size!==stock.uids.length||!Array.isArray(profile.inventory)||profile.inventory.length>350||!e||e.locked||!Number.isInteger(e.active)||e.active<0||e.active>=PRESETS||!Array.isArray(e.presets)||e.presets.length!==PRESETS||e.presets.some(p=>!p||typeof p!=='object'||Array.isArray(p))||!e.items||typeof e.items!=='object'||Array.isArray(e.items))return unchanged();
 const uids=profile.inventory.map(i=>i?.uid);if(uids.some(uid=>typeof uid!=='string'||!uid)||new Set(uids).size!==uids.length)return unchanged();
 const next=structuredClone(profile),db=data.itemDB,bag=new Container(next.inventory,db,{pages:7,cols:10,rows:5,unlocked:()=>next.bagsUnlocked||2,name:'bag'}),eq=new Equipment({db,game:{save:next}});let equipped=0;
 for(const slot of armorSlots){
  // Any reference, including a broken or reserved one, remains untouched.
  if(Object.hasOwn(next.equip.presets[next.equip.active],slot))continue;
  for(const uid of stock.uids){
   const item=bag.byUid(uid);if(!item||item.count!==1||item.bound!==true||item.npcStartingStock!=='ENGINE-CHOSEN'||item.expiresAt||next.equip.items[uid]||Object.values(next.equip.items).some(item=>item?.uid===uid)||eq.isEquipped(uid)||['potionBelt','storage','cashInv','costumeBag'].some(key=>Array.isArray(next[key])&&next[key].some(i=>i?.uid===uid)))continue;
   const def=db.def(item.itemIndex);if(!def||!eq.slotsFor(def).includes(slot)||!eq.assetFor(def.index))continue;
   // Native stats derivation may normalize its input; discard that probe.
   const stats=data.stats(structuredClone(next),null,now());
   if(!eq.check(item,slot,stats).ok)continue;
   const taken=bag.take(item);if(!taken||taken.uid!==uid)throw Error('Owned armor transfer refused');
   delete taken.page;delete taken.x;delete taken.y;
   const result=eq.place(taken,slot);if(!result.ok||result.displaced?.length)throw Error('Owned armor placement refused');
   equipped++;break;
  }
 }
 return equipped?{profile:next,equipped}:unchanged();
}
/** Private aggregate presentation only. Presence is not native gear viability,
 * a model-load result or a promise of surviving the area's monsters. */
export function npcOwnedEquipmentCounts(world,profiles){
 const out={actors:0,alive:0,dead:0,withActiveArmor:0,withActiveWeapon:0};
 if(!(world?.players instanceof Map)||!(profiles?.profiles instanceof Map))return out;
 for(const[account,p]of world.players){const saved=profiles.profiles.get(account);
  if(!/^npc_[a-f0-9]{32}$/.test(account)||p?.account!==account||p.leaving||p.profile?.authority!=='server'||p.profile.npcPlayer!==true||saved?.authority!=='server'||saved.npcPlayer!==true||typeof saved.id!=='string'||p.profile.id!==saved.id||p.characterId!==saved.id||p.id!==account+':'+saved.id)continue;
  out.actors++;if(p.dead)out.dead++;else out.alive++;
  const eq=p.profile.equip,preset=eq?.presets?.[eq.active||0];const has=slot=>{const item=eq?.items?.[preset?.[slot]];return Number.isSafeInteger(item?.itemIndex)&&item.itemIndex>0;};
  if(has(S.armor))out.withActiveArmor++;if(has(S.weapon))out.withActiveWeapon++;
 }
 return out;
}

export class SharedWorld {
  constructor({ data, getProfile, saveProfile, saveProfiles, now = Date.now, random = Math.random, rates = readWorldRates(), rateSettings = null }) {
    this.rates=readWorldRates({DEKARON_EXP_RATE:rates.exp,DEKARON_DIL_RATE:rates.dil,DEKARON_DROP_RATE:rates.drop});
    this.pcRoom=new PCRoomChecking(data?.pcRoom||undefined,{log:m=>console.log('[pcroom]',m)});   // SERVER-RE.md §7 PCRoomChecking
    this.rateSettings=rateSettings;
    if(rateSettings)Object.defineProperty(this,'rates',{get:()=>rateSettings.current(),enumerable:true});
    this.data = data; this.getProfile = getProfile; this.saveProfile = saveProfile;this.saveProfiles=saveProfiles; this.now = now; this.random = random;
    this.players = new Map(); this.maps = new Map(); this.events = []; this.sequence = 0;
    this.parties = new Map(); this.partyInvites = new Map();
    this._parkedFieldScenes=new Map();this._sceneLeases=new Map();this._fieldMapOwners=new Map();this._saveFlights=0;
    this.accountQueues = new Map(); this.saveQueue = Promise.resolve(); this.lastTick = now();
    this.itemBoxFacade=(p,profile,inventory)=>durableItemBoxFacade(this,p,profile,inventory);
    this.itemSkillFacade=(p,profile)=>itemSkillFacade(this,p,profile);
    this.follow=new FollowBook();   // per-TARGET follower cap (src/game/follow-cap.js: info.csv dwFollowTarget, ENGINE-CHOSEN meaning; DEKARON_FOLLOW_CAP=off is the kill switch)
  }
  acquireSceneLease(index,instanceId=null,channel=0){const key=index==null?'*':sceneKey(index,instanceId,channel);this._sceneLeases.set(key,(this._sceneLeases.get(key)||0)+1);let released=false;return ()=>{if(released)return;released=true;const n=this._sceneLeases.get(key)||0;if(n<=1)this._sceneLeases.delete(key);else this._sceneLeases.set(key,n-1);};}
  parkFieldScene(index,channel=0){return parkNativeFieldScene(this,Number(index),channel);}
  async map(index, instanceId = null, channel = 0) {const release=this.acquireSceneLease(index,instanceId,channel);try{return await this._loadScene(index,instanceId,channel);}finally{release();}}
  async _loadScene(index, instanceId = null, channel = 0) {
    if(this.data.customMaps?.isDeploying(index))throw new WorldError(409,'Map publication is in progress. Retry entry after it finishes.');
    if(instanceId)channel=0;const key=sceneKey(index,instanceId,channel);
    if (this.maps.has(key)) return this.maps.get(key);
    if(!this._fieldMapOwners.has(Number(index))&&this.data.retainMap){const owner=Symbol('native scene geometry owner');this.data.retainMap(Number(index),owner);this._fieldMapOwners.set(Number(index),owner);}
    let loaded = await this.data.map(index,{instance:!!instanceId});
    if(this.data.customMaps?.isDeploying(index))throw new WorldError(409,'Map publication is in progress. Retry entry after it finishes.');
    if(instanceId && loaded.collision instanceof Collision){
      const source=loaded.collision,collision=new Collision(source.grid?{...source.grid,cells:new Uint8Array(source.cells)}:null,source.width,source.height);
      if(!source.grid)collision.cells.set(source.cells);
      const finder=new PathFinder(collision,{maxNodes:20000,snapRadius:8});
      loaded={...loaded,collision,isWalkable:(x,z)=>collision.isWalkable(x,z),path:(x,z,tx,tz)=>finder.findPath(x,z,tx,tz),nearest:(x,z)=>collision.nearestWalkable(x,z,32)};
    }
    if (this.maps.has(key)) return this.maps.get(key);
    const parked=this._parkedFieldScenes.get(key);
    if(parked){for(const k of ['collision','path','nearest','isWalkable'])parked[k]=loaded[k];this.maps.set(key,parked);this._parkedFieldScenes.delete(key);return parked;}
    const monsters = new Map();
    for (const spawn of this.data.spawns(index)) {
      const def = this.data.monsterDef(spawn.monsterIndex);
      // role 'invisible' rows (no texture pack: effect sources / boss tags) are not spawned, as the client spawner.js:205 and
      // dungeons.mjs do not (monster-rules.js isNonCombatant explains the ENGINE-CHOSEN reason)
      if (!def || def.role === 'object' || def.role === 'invisible' || !loaded.isWalkable(spawn.x, spawn.z)) continue;
      const id=instanceId?`${instanceId}:${spawn.id}`:channel?`ch${channel}:${spawn.id}`:spawn.id;
      monsters.set(id, { ...spawn, id, instanceId, channel, map: index, name: def.name, hp: def.hp, maxHp: def.hp, home: { x: spawn.x, z: spawn.z }, dead: false, targetId: null, attackAt: 0, respawnAt: 0, def });
    }
    const state = rememberNativeFieldScene({ ...loaded, index, instanceId, channel, monsters }); this.maps.set(key, state); return state;
  }
  serializeAccount(account, operation) {
    const previous = this.accountQueues.get(account) || Promise.resolve();
    const result = previous.catch(() => {}).then(operation);
    this.accountQueues.set(account, result);
    void result.finally(() => { if (this.accountQueues.get(account) === result) this.accountQueues.delete(account); }).catch(() => {});
    return result;
  }
  join(account, characterId, admissionObserver=null, channel=undefined, cursorVersion=undefined) {const release=this.acquireSceneLease(null);return this.serializeAccount(account,()=>this._join(account,characterId,false,admissionObserver,channel,cursorVersion)).finally(release);}
  // Trusted bot lifecycle only. Human admission retains its complete snapshot.
  joinNpc(account,characterId) {if(!/^npc_[a-f0-9]{32}$/.test(account))throw new WorldError(403,"Bot admission requires a canonical NPC account.");const release=this.acquireSceneLease(null);return this.serializeAccount(account,()=>this._join(account,characterId,true)).finally(release);}
  async _join(account, characterId, npcReceipt = false, admissionObserver=null, requestedChannel=undefined, cursorVersion=undefined) {
    validateLoginChannel(this,requestedChannel);
    if(cursorVersion!==undefined&&cursorVersion!==1)throw new WorldError(400,'Unsupported inventory cursor protocol.');
    const observe=name=>{if(!npcReceipt&&typeof admissionObserver==='function'){try{const pending=admissionObserver(name);if(pending&&typeof pending.then==='function')void Promise.resolve(pending).catch(()=>{});}catch{}}};
    if (typeof characterId !== 'string' || !/^[a-zA-Z0-9_-]{1,100}$/.test(characterId)) throw new WorldError(400, 'Choose a server character.');
    const old = this.players.get(account);
    if(old)observe('replacementCleanup');
    if (old) { await battleSupportCommand(this,old,{type:'battlesupport',operation:'stop',token:old.token});await flushInstanceProgress(this,old); old.leaving = true; try { await this.persist(old); } catch (err) { if(!old.revoked)old.leaving = false; throw err; } (cancelTrade(this,old,'rejoined'),cancelCharTrade(this,old,'rejoined'));leaveParty(this,old); if(this.players.get(account)===old)this.players.delete(account); }
    observe('getProfile');
    const profile = await this.getProfile(account, characterId);
    if((profile?.itemCursor?.item||profile?.itemCursor?.pending?.length)&&cursorVersion!==1)throw new WorldError(409,'This character has a held item. Update your client to restore and place it safely.');
    observe('nativeStage');
    const {player,where}=await this._stageNpc(account,characterId,profile,npcReceipt);
    player.cursorVersion=cursorVersion===1?1:0;
    const selectedChannel=loginChannel(this,player,requestedChannel);
    if(selectedChannel!==player.channel){await this.map(player.map,player.instanceId,selectedChannel);player.channel=selectedChannel;}
    if(npcReceipt&&!npcSlotsAvailable(this,1,[account]))throw new WorldError(503,'A player slot is reserved for a human connection.');
    this.players.set(account, player); this.emit(where.map, { type: 'join', actorId: player.id }); void this.pcRoom?.enter(player);
    const reattached=player.instanceId&&this.instances?.get(player.instanceId);if(reattached?.restored&&reattached.admitting){reattached.members.add(player.id);reattached.admitting=false;}
    observe('durablePersist');
    try { await this.persist(player,npcReceipt?null:()=>observe('durableStore')); } catch (err) { this.players.delete(account); throw err; }
    if(npcReceipt){const state=this.snapshot(player,{npcReceipt:true,since:this.sequence});return {token:player.token,self:state.self,state};}
    observe('coreSnapshot');
    return { token: player.token, self: this.publicPlayer(player, true), state: this.snapshot(player) };
  }
  async _stageNpc(account,characterId,profile,npcReceipt=false,prepareArmorBeforePublish=false) {
    if (!profile || profile.authority !== 'server') throw new WorldError(403, 'Shared play requires a character created by the server. Local imports remain offline.');
    if(npcReceipt&&(!/^npc_[a-f0-9]{32}$/.test(account)||profile.npcPlayer!==true))throw new WorldError(403,'Bot admission requires a canonical NPC character.');
    if (!this.data.classDef(profile.classIndex)) throw new WorldError(400, 'Unknown class.');
    let p = clone(profile);
    p.itemCooldowns=itemCooldownState(p.itemCooldowns,this.now());
    // Only the verified server profile is used; join/action body has no save import path.
    p.level = Math.max(1, Math.min(this.data.maxLevel || 250, Math.floor(p.level || 1)));
    p.stats ||= clone(this.data.classDef(p.classIndex).stats?.base || { str: 5, dex: 5, con: 5, spr: 5 });
    this.data.initializeEquipment?.(p);
    if(npcReceipt&&prepareArmorBeforePublish)p=prepareOwnedNpcArmor(p,this.data,{account,characterId,trustedWave:true,now:this.now}).profile;
    initializePets(p);
    syncPremiumBuffs(this,p);
    // Dead Island paid-run reattachment; any failure keeps the safe harbor exit below.
    if(p.instance?.map===551)await restoreDeadIslandRun(this,p).catch(error=>{console.error('[dead-island] run restore failed:',error?.message||error);});
    const instanceId=restoreInstance(this,p);
    const channelStart=restoreChannel(this,p,instanceId);let channel=channelStart.channel;
    const stats = this.data.stats(p);
    let where = channelStart.where || { map: p.map ?? this.data.start.map, x: p.pos?.x ?? this.data.start.x, z: p.pos?.z ?? this.data.start.z };
    // A saved human destination must obey the same native Zuto admission
    // boundary as travel. Resolve normal instance/channel recovery first.
    assertUrbanWarfareAdmissionAvailable(this, where.map);
    let map;
    try { map = await this.map(where.map,instanceId,channel); } catch { where = { ...this.data.start }; channel = 0; map = await this.map(where.map); }
    if (!map.isWalkable(where.x, where.z)) {
      const near = map.nearest(where.x, where.z);
      const start = map.start;
      const at = near || (finite(start?.x) && finite(start?.z) && map.isWalkable(start.x, start.z) ? start : null);
      if (!at || !finite(at.x) || !finite(at.z) || !map.isWalkable(at.x, at.z)) throw new WorldError(503, 'No safe map spawn is available.');
      where = { ...where, x: at.x, z: at.z };
    }
    const player = { instanceId, channel, id: `${account}:${characterId}`, account, characterId, profile: p, token: randomBytes(32).toString('hex'), ...where, yaw: 0, hp: p.hp == null ? stats.maxHp : Math.max(0, Math.min(stats.maxHp, p.hp)), maxHp: stats.maxHp, stats, path: [], attackAt: 0, lastSeen: this.now(), lastSave: this.now(), rateAt: this.now(), actions: 0, moveAt: -Infinity, dirty: true, revision: 1 };
    player.classDef=this.data.classDef(p.classIndex); // internal native factors, never a client-supplied combat value
    player.dead = player.hp <= 0;
    if(player.dead)player.respawnReadyAt=this.now()+ORDINARY_RESPAWN_WAIT_MS;
    player.itemCooldownState=structuredClone(p.itemCooldowns);player.itemCooldowns=itemCooldownEntries(p.itemCooldowns,this.now());
    player.mp = p.mp == null ? stats.maxMp || 0 : Math.max(0, Math.min(stats.maxMp || 0, p.mp));
    initializeProgression(this, player);
    initializeDekaPass(this,player);
    initializeCrafting(this,player);
    initializeStarterSkills(this, player);
    // Capacity after equipment/passives establish it. New/legacy characters have full shields;
    // a canonical saved remainder cannot be refilled by repeatedly replacing the client lease.
    player.maxShield = Math.max(0, Number(player.stats.maxShield) || 0);
    player.shield = Number.isFinite(p.shield)?Math.max(0,Math.min(player.maxShield,p.shield)):player.maxShield;
    restoreRejoinRecovery(this,player);
    return {player,where};
  }
  // Trusted bounded admissions; API/caller owns capacity reservations. No rejoin.
  joinNpcWave(rows) {
    if(!Array.isArray(rows)||!rows.length||rows.length>16)throw new WorldError(400,'NPC admission requires one to sixteen identities.');
    const keys=new Set(),input=rows.map(r=>{
      if(!r||typeof r.account!=='string'||!/^npc_[a-f0-9]{32}$/.test(r.account)||typeof r.characterId!=='string'||!/^[a-zA-Z0-9_-]{1,100}$/.test(r.characterId)||keys.has(r.account)||this.players.has(r.account))throw new WorldError(409,'NPC wave requires distinct absent canonical actors.');
      keys.add(r.account);return {accountId:r.account,characterId:r.characterId};
    });
    if(typeof this.npcAdmissionSnapshot!=='function'||typeof this.npcAdmissionCommit!=='function'||this.npcAdmissionEnabled?.()!==true)throw new WorldError(503,'NPC durable admission is unavailable.');
    const accounts=[...keys].sort(),release=this.acquireSceneLease(null);
    // Register the SAME task on every account synchronously before yielding.
    // Disjoint waves may stage concurrently; overlapping waves cannot deadlock.
    const previous=accounts.map(a=>(this.accountQueues.get(a)||Promise.resolve()).catch(()=>{}));
    const task=Promise.all(previous).then(()=>this._joinNpcWave(input));
    for(const a of accounts)this.accountQueues.set(a,task);
    void task.finally(()=>{for(const a of accounts)if(this.accountQueues.get(a)===task)this.accountQueues.delete(a);release();}).catch(()=>{});
    return task;
  }
  async _joinNpcWave(input) {
    const check=()=>{if(this.npcAdmissionEnabled?.()!==true||!npcSlotsAvailable(this,input.length,input.map(r=>r.accountId))||input.some(r=>this.players.has(r.accountId)))throw new WorldError(409,'NPC admission changed while preparing.');};
    check();const stamps=await this.npcAdmissionSnapshot(input),byId=new Map();
    if(!Array.isArray(stamps)||stamps.length!==input.length)throw new WorldError(503,'Invalid NPC admission stamps.');
    for(const s of stamps){const r=input.find(r=>r.accountId===s?.accountId);if(!r||r.characterId!==s.characterId||s.expected?.id!==r.characterId||byId.has(r.accountId))throw new WorldError(503,'Invalid NPC admission stamp identity.');byId.set(r.accountId,s);}
    const staged=[],buffers=this._npcAdmissionEvents||(this._npcAdmissionEvents=new Map());let committed=false;
    try{
      let stagedSinceYield=0;
      for(const r of input){check();const id=r.accountId+':'+r.characterId;if(buffers.has(id))throw new WorldError(409,'NPC admission already pending.');buffers.set(id,[]);
        const {player}=await this._stageNpc(r.accountId,r.characterId,byId.get(r.accountId).expected,true,true);
        player.npcPlayer=true;player.permissions={role:'player',capabilities:[]};player.capabilities=[];player.gmAuthorized=false;
        staged.push({player,stamp:byId.get(r.accountId),generation:player.revision,profile:this.canonical(player)});
        if(++stagedSinceYield===2){stagedSinceYield=0;await new Promise(resolve=>setImmediate(resolve));check();}
      }
      check();
      const task=this.saveQueue.catch(()=>{}).then(async()=>{check();return this.npcAdmissionCommit(staged.map(s=>({...s.stamp,profile:s.profile})));});
      this.saveQueue=task;const result=await this._trackSceneSave(task);committed=true;
      if(result?.committed!==true||!Array.isArray(result.updates)||result.updates.length!==staged.length)throw new WorldError(503,'NPC durable admission result is invalid.');
      const normalized=new Map(result.updates.map(u=>[u.accountId,u]));
      for(const s of staged){const u=normalized.get(s.player.account);if(!u||u.characterId!==s.player.characterId||u.profile?.id!==s.player.characterId||u.profile.authority!=='server'||u.profile.npcPlayer!==true)throw new WorldError(503,'NPC durable admission result identity is invalid.');}
      check();
      // Backend normalization replaces the staged profile; skill proxies read
      // player.profile dynamically and keep their original real-world identity.
      for(const s of staged){s.player.profile=structuredClone(normalized.get(s.player.account).profile);s.player.saveError=null;if(s.player.revision===s.generation)s.player.dirty=false;}
      for(const s of staged)this.players.set(s.player.account,s.player);
      for(const s of staged){const pending=buffers.get(s.player.id)||[];buffers.delete(s.player.id);for(const e of pending)this.emit(e.map,e.event);this.emit(s.player.map,{type:'join',actorId:s.player.id});}
      // Internal callers need the committed identity and lease only. Building a
      // full viewer snapshot for every NPC stalls the event loop during a wave.
      return {committed:true,updates:result.updates,admissions:staged.map(({player})=>({account:player.account,characterId:player.characterId,token:player.token}))};
    }catch(error){if(committed||error.npcAdmissionCommitted===true){error.npcAdmissionCommitted=true;Object.defineProperty(error,'npcAdmissionActors',{value:staged.map(s=>s.player).filter(player=>this.players.get(player.account)===player),enumerable:false,configurable:true});}throw error;}
    finally{for(const r of input)buffers.delete(r.accountId+':'+r.characterId);}
  }
  lease(account, token) {
    const p = this.players.get(account);
    if (!p || p.leaving || typeof token !== 'string' || token !== p.token) throw new WorldError(409, 'Your world lease expired or another tab joined. Rejoin to continue.');
    p.lastSeen = this.now(); return p;
  }
  emit(map, event) {
    const pending=this._npcAdmissionEvents?.get(event.actorId);
    if(pending){if(pending.length>=256)throw new WorldError(503,'NPC initialization event bound exceeded.');pending.push({map,event:{...event}});return;}
    this.snapshotPublicRows?.clear();
    let damageTarget=null;
    if(event.type==='damage'){
      let target;
      for(const p of this.players.values())if(p.id===event.targetId && p.map===map && (event.instanceId===undefined || (p.instanceId||null)===(event.instanceId||null))){target=p;break;}
      damageTarget=target;
      if(target&&Number.isFinite(event.amount)&&event.amount>0)target.hitRevision=(target.hitRevision||0)+1;
      // The host picks a player's hit reaction once (src/game/hit-reaction.js), so the victim and every observer play the same DEFEAT row.
      if(target&&event.amount>0&&event.defeat===undefined){
        let casting=false;try{casting=!!skillControls(target).casting;}catch{}
        const defeat=playerDefeatReaction({dead:!!(target.dead||event.dead),moving:!!target.path?.length,attacking:(typeof this.now==='function'?this.now():Date.now())<(Number(target.attackAt)||0),casting,sitting:!!target.sitting,fishing:fishingBusy(target),defeatResistance:combatOptionValue(target,'DEFENSE_DEFEATRATE_MUL')},()=>this.random());
        if(defeat!=null)event={...event,defeat};
      }
    }
    const ids=[event.actorId,event.sourceId,event.targetId].filter(Boolean);
    let actor;
    for(const p of this.players.values())if(ids.includes(p.id)){actor=p;break;}
    if(!actor)for(const m of this.maps.values())if(ids.some(id=>m.monsters.has(id))){actor=m;break;}
    const instanceId=event.instanceId!==undefined?event.instanceId:actor?.instanceId||null;
    const channel=event.channel!==undefined?event.channel:actor?.channel??0;
    // 2.2.1: the ring holds EVENT_RING events (was 200 for the whole world, so a crowd's attack / damage events fell out before a
    // throttled stream's next snapshot and damage numbers went missing); trimmed in blocks so a push stays O(1)
    const entry={ ...event, instanceId, channel, map, sequence: ++this.sequence };
    rememberHumanPresentation(actor,entry);
    if(damageTarget&&damageTarget!==actor)rememberHumanPresentation(damageTarget,entry);
    this.events.push(entry); if (this.events.length > EVENT_RING + EVENT_TRIM) this.events.splice(0, this.events.length - EVENT_RING); }
  /** A viewer's events: use the last stream cursor even after a brief stream stall. Falling back to the world's last 200
   *  events can discard this player's EXP/DIL/chat messages under crowd load before the next poll recovers. A viewer with no
   *  cursor still gets the last 200; the ring and snapshot cap remain bounded. */
  snapshotEvents(p) {
    const ev = this.events, since = p._streamEventSeq;
    let list;
    if (since == null) list = ev.slice(-200);
    else { let lo = 0, hi = ev.length; while (lo < hi) { const mid = (lo + hi) >> 1; if (ev[mid].sequence <= since) lo = mid + 1; else hi = mid; } list = ev.slice(lo); }
    list=pendingPresentationEvents(p,list,since);
    const mine = e => e.actorId === p.id || e.targetId === p.id || e.sourceId === p.id || (e.recipients && e.recipients.includes(p.id));
    let rows = list.filter(e => e.recipients ? e.recipients.includes(p.id) : sameScene(e, p));
    if (rows.length > EVENT_SNAPSHOT_CAP) { let others = rows.filter(e => !mine(e)).length - Math.max(0, EVENT_SNAPSHOT_CAP - rows.filter(mine).length); rows = rows.filter(e => mine(e) || others-- <= 0); }
    return rows;
  }
  changed(p) { if(p.dead){if(!Number.isFinite(p.respawnReadyAt))p.respawnReadyAt=this.now()+ORDINARY_RESPAWN_WAIT_MS;}else delete p.respawnReadyAt;this.snapshotPublicRows?.delete(p); p.dirty = true; p.revision++; }
  canonical(p, shallow = false) {
    // shallow: only for a snapshot that is serialized at once (snapshotText) - the same JSON without deep-copying the profile
    return { ...(shallow ? p.profile : clone(p.profile)), map: p.map, pos: { x: p.x, z: p.z, dirDeg: p.yaw * 180 / Math.PI }, hp: p.dead ? 0 : Math.max(1, Math.round(p.hp)), mp: Math.round(p.mp || 0), shield: Math.round(Math.max(0, Math.min(Number(p.stats.maxShield) || 0, Number(p.shield) || 0))), combatRecovery:captureRejoinRecovery(this,p,activeRemaining(p._skills?.engine)), stats: shallow ? p.profile.stats : clone(p.profile.stats), authority: 'server' };
  }
  publicPlayer(p, self = false) {
    const result = { id: p.id, characterId: p.characterId, instanceId:p.instanceId||null, channel:p.channel??0, name: p.profile.name, classIndex: p.profile.classIndex, map: p.map, x: p.x, z: p.z, yaw: p.yaw, hp: p.hp, maxHp: p.maxHp, mp: p.mp, maxMp: p.stats.maxMp || 0, shield: Math.round(p.shield || 0), maxShield: Math.round(Number(p.stats.maxShield) || 0), level: p.profile.level, exp: p.profile.exp || 0, dil: p.profile.dil || 0, dead: p.dead, mount:mountState(p,this.now()), moving: p.path.length > 0 };
    if(p.npcPlayer)result.npcPlayer=true;
    if(p.walk&&p.path.length&&p.mount?.phase!=='on')result.walk=p.walk;
    if(p.sitting)result.sitting=true;
    if(self){const fury=furyOf(this,p);if(fury!=null)result.fury=fury;if(p.dead&&Number.isFinite(p.respawnReadyAt))result.respawnReadyAt=p.respawnReadyAt;result.resurrection=resurrectionSnapshot(this,p);result.sharedTarget=sharedTargetSnapshot(this,p);result.lifeBeadReviveAllowed=lifeBeadReviveAllowed(this,p);const battleUntil=battleStatusUntil(this,p);if(battleUntil)result.battleStatusUntil=battleUntil;}
    const pcShop=publicPcShop(this,p);if(pcShop)result.pcShop=pcShop;if(self)result.pcShopState=pcshopSnapshot(this,p);
    result.statusVisuals=skillStatusVisuals(this,p);result.transUp=skillTransformVisual(this,p);
    result.nameplate=publicNameplate(this,p);result.nameColor=result.nameplate.nameColor;result.fishing=fishingPose(p);result.appearance = battleAppearance(this,p,publicAppearance(p.profile));result.pet=petState(p,this.now());
    if(self){result.gmSpeed=authorizedGMSpeed(p);result.moveSpeed=canonicalMovementSpeed(this,p);Object.assign(result,movementSelf(this,p));result.moveBlocked=!!(skillControls(p).move||mountBusy(p)||travelFrozen(this,p));}
    {const motion=movementPublic(p);if(motion)Object.assign(result,motion);}
    if (self) { result.itemCooldowns=itemCooldownState(p.itemCooldownState??p.profile.itemCooldowns,this.now());result.fishing=fishingState(p);result.battleSupport=battleSupportSnapshot(this,p);result.smartWarp=smartWarpState(p);{const shallow=this._snapshotTextBuild===p;result.profile = this.canonical(p,shallow);result.profile.itemCooldowns=shallow?result.itemCooldowns:structuredClone(result.itemCooldowns);} result.saveError = p.saveError || null; result.permissions = p.permissions || { role: 'player', capabilities: [] }; result.attackReadyAt = p.attackAt || 0; result.attackCooldownMs = playerAttackLimit(this.data, p).spacingMs; }
    return result;
  }
  // Only the synchronous SSE snapshot/write loop may share public rows. HTTP
  // snapshots, private self rows, events and visibility are always built anew.
  // In particular, a sequence/revision is not a snapshot invalidation token.
  withSnapshotBroadcast(build) {
    const previous=this.snapshotPublicRows,previousMonsters=this.snapshotMonsterText;
    this.snapshotPublicRows=new Map();
    // 2.2.1: a monster row is the same for every viewer of one broadcast (nothing moves monsters while it runs), so its JSON
    // is built once per broadcast and spliced into each viewer's snapshot (snapshotText).
    this.snapshotMonsterText=new Map();
    const previousMemo=this._broadcastMemo;this._broadcastMemo=new Map();
    // An inner snapshot can publish forced movement or run mutating hooks.
    // Restoring an outer scope must not revive its previously cached rows.
    try{return build();}finally{previous?.clear();this.snapshotPublicRows=previous;this.snapshotMonsterText=previousMonsters;this._broadcastMemo=previousMemo;}
  }
  /** lane-perf: a viewer-independent value (depends only on world state + key) computed once per synchronous broadcast scope.
   *  Outside a broadcast it is computed every call. `_broadcastMemoAudit` (tests) recomputes and compares every hit. */
  broadcastMemo(key, compute) {
    const memo=this._broadcastMemo;if(!memo)return compute();
    if(memo.has(key)){const v=memo.get(key);if(this._broadcastMemoAudit)this._broadcastMemoAudit(key,v,compute());return v;}
    const v=compute();memo.set(key,v);return v;
  }
  /** The monsters a viewer's snapshot lists: every monster of its scene within VIEW_CELLS, the nearest SNAPSHOT_MONSTER_CAP
   *  when there are more (order of the kept rows = scene order, so below the cap the list is exactly what it always was). */
  snapshotMonsters(p, map, noteContact) {
    if (!map) return [];
    const reach = Math.min(8, p.stats.attackRange || 5) + .5, near = [], dists = [];
    for (const m of map.monsters.values()) {
      if (m.isBrick) continue;
      const d = distance(m, p);
      if (d <= reach) noteContact(m);
      if (d < VIEW_CELLS) { near.push(m); dists.push(d); }
    }
    if (near.length <= SNAPSHOT_MONSTER_CAP) return near;
    // nearest CAP by a 1-cell distance histogram (O(n), no sort)
    const counts = new Uint32Array(VIEW_CELLS + 1);
    for (const d of dists) counts[Math.floor(d)]++;
    let edge = 0, kept = 0;
    while (edge <= VIEW_CELLS && kept + counts[edge] <= SNAPSHOT_MONSTER_CAP) kept += counts[edge++];
    let room = SNAPSHOT_MONSTER_CAP - kept;
    const rows = [];
    for (let i = 0; i < near.length; i++) { const b = Math.floor(dists[i]); if (b < edge || (b === edge && room-- > 0)) rows.push(near[i]); }
    return rows;
  }
  monsterRow(m) { return { id: m.id, monsterIndex: m.monsterIndex, name: m.name, map: m.map, x: m.x, z: m.z, hp: m.hp, maxHp: m.maxHp, dead: m.dead, ...(m.renewGuard?{renewGuard:true,guardGuild:m.guardGuild,instanceId:m.instanceId,channel:m.channel??0}:{}),statusVisuals:skillStatusVisuals(this,m) }; }
  /** The broadcast snapshot as JSON text (api.mjs stream): the same bytes as JSON.stringify(snapshot(p)), with each monster row
   *  serialized once per broadcast instead of once per viewer. */
  /** rowCache (optional, one per SSE stream: {key, rows:{players:Map,monsters:Map}}): a row whose JSON equals the one
   *  this stream got last frame is sent as its id only (src/systems/network/rows-delta.js expands it). */
  snapshotText(p, rowCache = null) {
    // the viewer's own profile row is serialized right here, so it is read in place instead of deep-copied (canonical shallow)
    let snap; this._snapshotTextBuild = p;
    try { snap = this.snapshot(p, { monsterRecords: true }); } finally { this._snapshotTextBuild = null; }
    // the stream's event cursor: its next snapshot (and replies meanwhile) carry every event after this one (snapshotEvents)
    p._streamEventSeq = snap.sequence; p._streamEventAt = this.now();
    const cache = this.snapshotMonsterText, records = snap.monsters;
    snap.monsters = ROWS_TOKEN;
    const rows = records.map(m => { let t = cache?.get(m); if (t === undefined) { t = JSON.stringify(this.monsterRow(m)); cache?.set(m, t); } return t; });
    // equivalence test hook: the original serialization, built before any splicing (tools/lane-perf/server-tick.mjs LP_AUDIT)
    const audit = this._rowsDeltaAudit ? JSON.stringify(snap).replace(`"${ROWS_TOKEN}"`, () => `[${rows.join(',')}]`) : null;
    // public player rows are shared objects within one broadcast (snapshotPublicRows): serialize each once per broadcast
    let playerTexts = null;
    if (Array.isArray(snap.players)) { playerTexts = snap.players.map(r => { if (!r || typeof r !== 'object') return JSON.stringify(r); let t = PLAYER_ROW_TEXT.get(r); if (t === undefined || !this.snapshotPublicRows) { t = JSON.stringify(r); if (this.snapshotPublicRows) PLAYER_ROW_TEXT.set(r, t); } return t; }); }
    let monsterRows = rows, playerRows = playerTexts;
    if (rowCache) {
      const delta = (field, ids, texts) => { const prior = rowCache.rows[field], next = new Map(); const out = texts.map((t, i) => { const id = ids[i]; if (typeof id !== 'string' && typeof id !== 'number') return t; next.set(id, t); return prior.get(id) === t ? JSON.stringify(id) : t; }); rowCache.rows[field] = next; return out; };
      monsterRows = delta('monsters', records.map(m => m.id), rows);
      if (playerTexts) playerRows = delta('players', snap.players.map(r => r?.id), playerTexts);
      snap.rowsDelta = rowCache.key;
    }
    if (playerRows) snap.players = PLAYER_ROWS_TOKEN;
    let text = JSON.stringify(snap).replace(`"${ROWS_TOKEN}"`, () => `[${monsterRows.join(',')}]`);
    if (playerRows) text = text.replace(`"${PLAYER_ROWS_TOKEN}"`, () => `[${playerRows.join(',')}]`);
    if (audit !== null) this._rowsDeltaAudit(p, audit, text);
    return text;
  }
  snapshotPublicPlayer(p) {
    const rows=this.snapshotPublicRows;
    // These rows contain live countdowns or an expiry test. Preserve their
    // original per-viewer clock reads, including millisecond boundary changes.
    if(!rows||p.mount||p.pet||p.profile.transUp)return this.publicPlayer(p);
    if(!rows.has(p))rows.set(p,this.publicPlayer(p));
    return rows.get(p);
  }
  snapshot(p, { monsterRecords = false, npcReceipt = false, since = this.sequence } = {}) {
    if(npcReceipt&&(this.players.get(p?.account)!==p||!/^npc_[a-f0-9]{32}$/.test(p.account)||p.profile?.authority!=='server'||p.profile?.npcPlayer!==true))throw new WorldError(403,'Bot receipts require an actual canonical actor.');
    trackForcedDisplacement(this,p);
    // Tracking movement and self-only snapshot hooks can mutate this actor even
    // without changed()/emit(). Later viewers must see the newly published row.
    this.snapshotPublicRows?.delete(p);
    const map = mapFor(this,p);
    const serverTime=this.now(),contactScene=sceneKey(p.map,p.instanceId,p.channel??0),contactRevision=p.mv?.posRev??0;
    if(p._normalContactScene!==contactScene||p._normalContactRevision!==contactRevision){p._normalAttackContacts=new Map();p._normalContactScene=contactScene;p._normalContactRevision=contactRevision;}
    const contacts=p._normalAttackContacts||=new Map();
    for(const [id,contact]of contacts)if(serverTime-contact.at>NORMAL_CONTACT.recentMs)contacts.delete(id);
    const noteContact=m=>{
      if(!p.dead&&!m.dead&&!m.eventObject&&!['object','invisible','npc','trap'].includes(m.def.role)&&(!map.collision?.lineOfSight||map.collision.lineOfSight(p.x,p.z,m.x,m.z))&&(contacts.has(m.id)||contacts.size<NORMAL_CONTACT.maxTargets))
        contacts.set(m.id,{at:serverTime,actor:m,map,scene:contactScene,channel:p.channel??0,revision:contactRevision,monsterScene:sceneKey(m.map,m.instanceId,m.channel??0),player:{x:p.x,z:p.z},monster:{x:m.x,z:m.z}});
    };
    // ENGINE-CHOSEN internal command receipt: no rendered world, inventory
    // clone or census. Preserve native contact observations and exact delivered
    // chat recipients; ordinary human snapshots and command authority are unchanged.
    if(npcReceipt){
      for(const m of map?.monsters?.values()||[])if(distance(p,m)<=Math.min(8,p.stats.attackRange||5)+.5)noteContact(m);
      let lo=0,hi=this.events.length;while(lo<hi){const mid=(lo+hi)>>1;if(this.events[mid].sequence<=since)lo=mid+1;else hi=mid;}
      const events=this.events.slice(lo).filter(e=>e.actorId===p.id&&(e.type==='chat'||e.type==='messenger')&&(e.recipients?e.recipients.includes(p.id):sameScene(e,p)));
      return {sequence:this.sequence,serverTime,tickAt:this.lastTick,self:{id:p.id,fishing:fishingState(p)},events};
    }
    const npcInterest=this.npcSnapshotInterest?.(p);
    return { sequence: this.sequence, serverTime, npcSceneReadiness:this.npcSceneReadiness?.(p)||null, npcScenePreparationRequired:this.npcScenePreparationRequired?.(p)===true, tickAt: this.lastTick, eventAnnouncements:this.broadcastMemo(`partyWarAnnouncements:${serverTime}`,()=>partyWarAnnouncements(this,serverTime)), eventLobby:partyWarLobbySnapshot(this,p,serverTime), mail:mailSnapshot(this,p),consign:consignmentSnapshot(this,p),pvp:pvpSnapshot(this,p),partyPvp:partyPvpSnapshot(this,p),trainingCamp:trainingCampSnapshot(this,p),dkSquare:dkSquareSnapshot(this,p),colosseum:colosseumSnapshot(this,p),race:raceSnapshot(this,p),oxQuiz:oxQuizSnapshot(this,p),zuto:zutoSnapshot(this,p),siegeRenew:siegeRenewSnapshot(this,p),guild:guildSnapshot(this,p),hunt:huntSnapshot(this,p),tourney:tourneySnapshot(this,p),dkr:dkrSnapshot(this,p),trade:tradeSnapshot(this,p),chartrade:charTradeSnapshot(this,p), customItemsRevision:this.data.customLibrary?.revision||0, customMapsRevision:this.data.customMaps?.revision||0, instance:dungeonSnapshot(this,p)||eventSnapshot(this,p), onlineCount: this.onlineCount(), simulationPopulation:this.npcPopulationCensus?.()||null, party:withPartyFinder(this,p,()=>partySnapshot(this,p)), expedition:expeditionSnapshot(this,p), summons:summonSnapshot(this,p.map,p.instanceId,p.channel??0), drops:groundDrops(this,p.map,p.instanceId,p.channel??0), self: this.publicPlayer(p, true), players: [...this.players.values()].filter(q => !q.leaving && sameScene(q,p) && (q===p||!isObserver(this,q))&&(!(npcInterest instanceof Set)||npcInterest.has(q.id))).map(q => this.snapshotPublicPlayer(q)), monsters: (records => monsterRecords ? records : records.map(m => this.monsterRow(m)))(this.snapshotMonsters(p, map, noteContact)), events: this.snapshotEvents(p) };
  }
  onlineCount() {
    let count=0;for(const player of this.players.values())if(!player.leaving)count++;
    return count;
  }
  async action(account,input){const release=this.acquireSceneLease(null);try{return await runNpcServiceScope(this,account,input,()=>this._action(account,input));}finally{release();}}   // guide 62 battle status: no NPC use (npc-service-guard.mjs)
  // Only trusted server bot callers choose lightweight receipts. HTTP callers
  // still use action(); the same lease, schema, range and transaction checks run.
  async npcAction(account,input){const p=this.lease(account,input.token);if(!/^npc_[a-f0-9]{32}$/.test(account)||p.profile?.authority!=='server'||p.profile?.npcPlayer!==true)throw new WorldError(403,'Bot command requires a canonical NPC character.');const release=this.acquireSceneLease(null);try{return await runNpcServiceScope(this,account,input,()=>this._action(account,input,true));}finally{release();}}
  async _action(account, input, npcReceipt = false) {
    const p = this.lease(account, input.token), now = this.now(), since=this.sequence;
    const finish=()=>this.snapshot(p,npcReceipt?{npcReceipt:true,since}:{});
    if (now - p.rateAt >= 1000) { p.rateAt = now; p.actions = 0; }
    if (++p.actions > 30) throw new WorldError(429, 'Too many world commands.');
    const schemas = { ...GAMEPLAY_PREFERENCE_SCHEMAS, move: ['token', 'type', 'x', 'z', 'walk', ...MOVEMENT_REPORT_FIELDS], stop: ['token', 'type', ...MOVEMENT_REPORT_FIELDS], attack: ['token', 'type', 'targetId', 'forced', 'step'], travel: ['token', 'type', 'map', 'gateId'], revive: ['token', 'type', 'uid'], ...NPC_FRIEND_SCHEMAS,...FRIEND_REQUEST_SCHEMAS,...BLACKLIST_SCHEMAS,...BATTLE_SUPPORT_SCHEMAS,...SOCIAL_SCHEMAS,...TRADE_SCHEMAS,...CHAR_TRADE_SCHEMAS,...PET_SERVICE_SCHEMAS,...VEHICLE_SERVICE_SCHEMAS,...MAIL_SCHEMAS,...CONSIGN_SCHEMAS,...PVP_SCHEMAS,...PARTY_PVP_SCHEMAS,...TRAINING_CAMP_SCHEMAS,...GUILD_SCHEMAS,...ITEM_SERVICE_SCHEMAS,...PREMIUM_SCHEMAS,...NAME_CHANGE_SCHEMAS,...MEGAPHONE_SCHEMAS, allocate: ['token', 'type', 'stat', 'count'],
      quest: ['token','type','operation','questId','npc','option','on'], box: ['token','type','uid','choices'], ...ITEM_ACTION_SCHEMAS,...SHOP_ACTION_SCHEMAS,...SKILL_SCHEMAS,...TRAVEL_SCHEMAS,...CHANNEL_SCHEMAS,...HUNT_SCHEMAS,...TOURNEY_SCHEMAS,...DKR_SCHEMAS,...LOOT_ACTION_SCHEMAS,...ENHANCEMENT_ACTION_SCHEMAS,...MOUNT_SCHEMAS,...PARTY_SCHEMAS,...EXPEDITION_SCHEMAS,...CONVERSION_ACTION_SCHEMAS,...EVENT_SCHEMAS,...DUNGEON_SCHEMAS,...PET_SCHEMAS,...DEKAPASS_SCHEMAS,...CRAFTING_SCHEMAS,...FISHING_SCHEMAS,...SUPPLY_SCHEMAS,...LIFE_EVENT_SCHEMAS,...EMOTE_SCHEMAS,...SUPPORT_REWARD_SCHEMAS,...PCSHOP_SCHEMAS,...PARTY_FINDER_SCHEMAS,...MESSENGER_SCHEMAS,...DK_SQUARE_SCHEMAS,...COLOSSEUM_SCHEMAS,...OX_QUIZ_SCHEMAS,...SIEGE_RENEW_SCHEMAS,...ZUTO_SCHEMAS,...IAN_SCHEMAS,...POINT_RESET_SCHEMAS };
    const permitted = typeof input.type === 'string' && Object.hasOwn(schemas, input.type) ? schemas[input.type] : null;
    if (!permitted) throw new WorldError(400, 'This action is unavailable in shared play.');
    if (Object.keys(input).some(k => !permitted.includes(k))) throw new WorldError(400, 'World commands cannot change stats, damage or inventory.');
    // ENGINE-CHOSEN reconnect safety: abandoning a running cast cannot skip its remaining recovery.
    if((input.type==='attack'||input.type==='cast')&&now<(p._rejoinCastUntil||0))throw new WorldError(429,'The previous cast is still recovering.');
    if(p.sceneTransition||p.progressCommitting){
      // Key release must still clear the path during a short durable reward write.
      // No profile/revision mutation can overwrite the staged transaction.
      if(input.type==='stop'){p.path=[];return finish();}
      throw Object.assign(new WorldError(409,'Wait for the current map or reward save to finish.'),{code:'WORLD_BUSY'});
    }
    if(input.type==='preferences'){await gameplayPreferenceCommand(this,p,input);return finish();}
    // Check every command before early-return services can move an open-shop seller.
    pcshopGuard(this,p,input);   // Original 180:3 / 110:313 restrictions, including mode entry and Battle Support.
    // Opening a shop must not leave an already-running auto attack/stamina session active (180:20 standing).
    if(input.type==='pcshop'&&input.operation==='open'&&battleSupportSnapshot(this,p).active)
      throw new WorldError(400,'You can only open a shop while standing.');
    // MESSENGER-CHAT: 1:1 messenger lines are chat, so they go out while dead like chat does (server/world/messenger.mjs)
    if(input.type==='blacklist'){const result=await blacklistCommand(this,p,input);return {...finish(),blacklistResult:result};}
    if(input.type==='messenger'){const result=messengerCommand(this,p,input);return {...finish(),messengerResult:result};}
    if(input.type==='battlesupport'){await battleSupportCommand(this,p,input);return finish();}
    if(input.type==='npcfriends'){await npcFriendCommand(this,p,input);return finish();}
    if(input.type==='friendrequest'){const result=friendRequestCommand(this,p,input);return {...finish(),friendRequestResult:result};}
    // A reconnecting corpse may release movement and read PvP/observer status
    // while its revive window opens. Neither operation can move or fight.
    if (p.dead && input.type === 'stop') { p.path = []; return finish(); }
    if (p.dead && !['revive', 'resurrection', 'chat'].includes(input.type) && !(input.type === 'pvp' && input.operation === 'restore') && !(input.type === 'dksquare' && ['revive', 'leave', 'list'].includes(input.operation)) && !(input.type === 'observer' && input.operation === 'info') && !(input.type === 'arena' && input.operation === 'info')) throw new WorldError(400, 'Revive before acting.');
    // GUILD-WAR-HUNT / GUILD-TOURNEY: observers only watch (server/world/observers.mjs); each mode has its own action.
    if(isObserver(this,p)&&!observerAllows(this,p,input.type))throw new WorldError(403,'Observers can only watch.');
    if(input.type==='attack'||input.type==='cast'&&input.targetId!=null)noteSharedTargetIntent(this,p,input.targetId);
    if(input.type==='tourney'){const result=await tourneyCommand(this,p,input);return {...finish(),tourneyResult:result};}
    if(input.type==='dkr'){const result=await dkrCommand(this,p,input);return {...finish(),dkrResult:result};}
    if(input.type==='hunt'){const result=await huntCommand(this,p,input);return {...finish(),huntResult:result};}
    partyPvpGuard(this,p,input);   // PARTY-PVP: no new leader (280:66), no portal / travel (280:68) during a Party Match
    partyFinderGuard(this,p,input);   // PARTY-FINDER: a recruiting leader cannot delegate (70:115) or switch channels (70:112)
    if(input.type==='trade'){await tradeCommand(this,p,input);return finish();}
    // CHAR-TRADE: the character transfer session (server/world/char-trade.mjs)
    if(input.type==='chartrade'){const charTradeResult=await charTradeCommand(this,p,input);return {...finish(),charTradeResult};}
    if(input.type==='partyfinder'){const result=partyFinderCommand(this,p,input);return {...finish(),partyFinderResult:result};}
    // Cursor transactions validate untouched offers and confirmation locks in items.mjs.
    if(!['chat','party','expedition','stop','emote','cursor'].includes(input.type)){cancelTrade(this,p,'interrupted by gameplay');cancelCharTrade(this,p,'interrupted by gameplay');}
    const map = mapFor(this,p);
    if(input.type==='pcshop'){const result=await pcshopCommand(this,p,input);return {...finish(),pcshopResult:result};}
    if(input.type==='mail'){const mailDetail=await mailCommand(this,p,input);return {...finish(),...(mailDetail?{mailDetail}:{})};}
    if(input.type==='consign'){const consignResult=await consignCommand(this,p,input);return {...finish(),consignResult};}
    if(input.type==='pvp'){const pvpResult=await pvpCommand(this,p,input);return {...finish(),pvpResult};}
    if(input.type==='partypvp'){const partyPvpResult=await partyPvpCommand(this,p,input);return {...finish(),partyPvpResult};}
    // DK-SQUARE: npc job 48 lobbies and the map 67 battlefield (server/world/dk-square.mjs)
    if(input.type==='dksquare'){const dkSquareResult=await dkSquareCommand(this,p,input);return {...finish(),dkSquareResult};}
    if(input.type==='trainingcamp'){const trainingCampResult=await trainingCampCommand(this,p,input);return {...finish(),trainingCampResult};}
    // COLOSSEUM: queues, Battle Royale (163 / 196) and Individual Match (164) (server/world/colosseum.mjs)
    if(input.type==='colosseum'){const colosseumResult=await colosseumCommand(this,p,input);return {...finish(),colosseumResult};}
    if(input.type==='guild'){await guildCommand(this,p,input);return finish();}
    if(input.type==='premium'){const result=await premiumCommand(this,p,input);return {...finish(),premiumResult:result};}
    if(input.type==='charname'){const result=await charNameCommand(this,p,input);return {...finish(),nameChangeResult:result};}
    if(input.type==='megaphone'){const result=await megaphoneCommand(this,p,input);return {...finish(),megaphoneResult:result};}
    if(Object.hasOwn(ITEM_SERVICE_SCHEMAS,input.type)){const result=await itemServiceCommand(this,p,input);return {...finish(),itemServiceResult:result};}
    if(Object.hasOwn(IAN_SCHEMAS,input.type)){const result=await weaponLookCommand(this,p,input);return {...finish(),weaponLookResult:result};}   // npc job 110 weapon appearance (ian-appearance.mjs)
    if(Object.hasOwn(VEHICLE_SERVICE_SCHEMAS,input.type)){const result=await vehicleServiceCommand(this,p,input);return {...finish(),vehicleServiceResult:result};}
    if(Object.hasOwn(PET_SERVICE_SCHEMAS,input.type)){const result=await petServiceCommand(this,p,input);if(questInventoryChanged(this,p))await this.persist(p);return {...finish(),petServiceResult:result};}
    if(input.type==='lifeevent'){const result=await lifeEventCommand(this,p,input);return {...finish(),lifeEventResult:result};}
    if(input.type==='production'){const result=await craftingCommand(this,p,input);return {...finish(),productionResult:result};}
    if(input.type==='fishing'){await fishingCommand(this,p,input);return finish();}
    if(input.type==='supply'){const supplyResult=await supplyCommand(this,p,input);return {...finish(),supplyResult};}
    if(input.type==='emote'){emoteCommand(this,p,input);return finish();}
    if(Object.hasOwn(SUPPORT_REWARD_SCHEMAS,input.type)){const result=await supportRewardCommand(this,p,input);return {...finish(),supportRewardResult:result};}
    if(['move','attack','travel','cast','mount','npctravel','smartwarp','equip','unequip','preset','weapontab','equipswap','itemuse','event','dungeon','channel','oxquiz','siegerenew','zuto'].includes(input.type)){cancelFishing(this,p);endSitting(this,p);}
    if(input.type==='channel'){const result=await channelCommand(this,p,input);return {...finish(),channelResult:result};}
    if(Object.hasOwn(DUNGEON_SCHEMAS,input.type)){const result=await dispatchDungeon(this,p,input);return {...finish(),...(typeof result==='object'?result:{})};}
    if(input.type==='siegerenew'){const result=await siegeRenewCommand(this,p,input);return {...finish(),siegeRenewResult:result};}
    if(isZutoBattlefieldTeleport(this,input)){const result=await zutoEnterBattlefield(this,p,input);return {...finish(),zutoResult:result};}   // native teleport 133 -> 650 (Zuto adaptation)
    if(await travelCommand(this,p,input))return finish();
    if(input.type==='event'){const result=await eventCommand(this,p,input);return {...finish(),...(result||{})};}
    if(input.type==='oxquiz'){const result=await oxQuizCommand(this,p,input);return {...finish(),oxQuizResult:result};}
    if(input.type==='zuto'){const result=await zutoCommand(this,p,input);return {...finish(),zutoResult:result};}
    if(Object.hasOwn(PARTY_SCHEMAS,input.type)){partyCommand(this,p,input);return finish();}
    if(Object.hasOwn(EXPEDITION_SCHEMAS,input.type)){expeditionCommand(this,p,input);return finish();}
    if(Object.hasOwn(MOUNT_SCHEMAS,input.type)){await mountCommand(this,p,input);return finish();}
    if(Object.hasOwn(PET_SCHEMAS,input.type)){await petCommand(this,p,input);return finish();}
    if(Object.hasOwn(DEKAPASS_SCHEMAS,input.type)){await dekapassCommand(this,p,input);return finish();}
    // NPC skill / attribute / stat resets (npc jobs 7 / 120 / 13, server/world/point-resets.mjs)
    if(input.type==='pointreset'){const result=await pointResetCommand(this,p,input);return {...finish(),pointResetResult:result};}
    if(Object.hasOwn(SKILL_SCHEMAS,input.type)){if(mountBusy(p))throw new WorldError(400,'Wait for mount preparation.');await skillCommand(this,p,input);return finish();}
    if(await dispatchItemAction(this,p,input) || await dispatchShopAction(this,p,input) || await dispatchLootAction(this,p,input) || await dispatchEnhancement(this,p,input) || await dispatchConversion(this,p,input)) {if(questInventoryChanged(this,p))await this.persist(p);return finish();}
    if (input.type === 'quest' || input.type === 'box') {
      const result = await durableQuestCommand(this,p,input);
      if (result.warpTarget && !result.warpCommitted) {
        if(p.instanceId)await exitInstance(this,p,{persist:false});
        await enterTrustedScene(this,p,result.warpTarget.map,result.warpTarget,{kind:'quest'});
      }
      for (const summon of result.context?.summons || []) {
        const def=this.data.monsterDef(summon.index);
        if(!def || !map.isWalkable(summon.x,summon.z)) continue;
        const id=`quest:${p.id}:${randomBytes(8).toString('hex')}`;
        map.monsters.set(id,{id,map:p.map,instanceId:p.instanceId||null,monsterIndex:summon.index,name:def.name,x:summon.x,z:summon.z,hp:def.hp,maxHp:def.hp,home:{x:summon.x,z:summon.z},dead:false,targetId:null,attackAt:0,respawnAt:0,respawnSec:Infinity,def});
      }
      if(result.warpTarget && !result.warpCommitted)await this.persist(p); return {...finish(),result:{ok:result.ok,...(result.purchase?{purchase:result.purchase}:{})}};
    }
    // MOVE-NO-RUBBERBAND: a client-predicted intent carries its own position; the host validates and echoes it.
    if (input.type === 'stop') { if(!hasMovementReport(input)||applyMovementReport(this,p,map,input,{blocked:!!(skillControls(p).move||mountBusy(p)||travelFrozen(this,p)||isShopOpen(this,p)),rootLocked:!!p._skills?.engine?.rootLocked?.()})==='accepted')clearAttackRoot(p); p.path = []; this.changed(p); return finish(); }   // an open Personal Shop holds its seller: a stop report cannot carry the character anywhere (180:3)
    if (input.type === 'move' && hasMovementReport(input)) {
      if (!finite(input.x) || !finite(input.z)) throw new WorldError(400, 'Destination is outside the walkable map.');
      if (input.walk !== undefined && input.walk !== 'peace' && input.walk !== 'battle') throw new WorldError(400, 'Walk must be peace or battle.');
      if(applyMovementReport(this,p,map,input,{blocked:!!(skillControls(p).move||mountBusy(p)||travelFrozen(this,p)),destination:{x:input.x,z:input.z},walk:input.walk,rootLocked:!!p._skills?.engine?.rootLocked?.()})==='accepted')clearAttackRoot(p);   // input movement ends any swing still carrying the body
      return finish();
    }
    if (input.type === 'move') {
      if(skillControls(p).move||mountBusy(p)||travelFrozen(this,p))throw new WorldError(400,'Movement is currently blocked by a skill effect or mount preparation.');
      if (!finite(input.x) || !finite(input.z)) throw new WorldError(400, 'Destination is outside the walkable map.');
      if (input.walk !== undefined && input.walk !== 'peace' && input.walk !== 'battle') throw new WorldError(400, 'Walk must be peace or battle.');
      let destination={x:input.x,z:input.z};
      if(!map.isWalkable(destination.x,destination.z)){
        const inside=map.collision?.inBounds?.(destination.x,destination.z)??(destination.x>=0&&destination.z>=0&&destination.x<map.width&&destination.z<map.height);
        const near=inside?map.collision?.nearestWalkable?.(destination.x,destination.z,3):null;
        if(!near||distance(destination,near)>3||!map.isWalkable(near.x,near.z))throw new WorldError(400,'Destination is outside the walkable map.');
        destination=near;
      }
      if (now - p.moveAt < 150) throw new WorldError(429, 'Movement requests are too frequent.');
      p.moveAt = now; if(p.mv)p.mv.reporting=false; // a plain intent hands movement back to the host path step
      p.walk = input.walk || null;
      p.path = map.path ? map.path(p.x, p.z, destination.x, destination.z) || [] : [destination];
      if (!p.path.length) throw new WorldError(400, 'No walkable path reaches this destination.');
      clearAttackRoot(p); // Plain host-owned movement (including NPC navigation) also ends a swing.
    }
    if (input.type === 'attack') {
      if(input.step!==undefined&&(!Number.isInteger(input.step)||input.step<0||input.step>63))throw new WorldError(400,'Attack step must be a combo step index.');
      const step=attackStepFor(this,p,input,now);
      const stepApproval=previewAttackStep(this,p,step,now);
      if(skillControls(p).attack||skillControls(p).casting||mountBusy(p)||p.mount?.phase==='on')throw new WorldError(400,'Dismount or wait for your skill effect before attacking.');
      // PVP-DUEL: a player target is only valid as the duel opponent (server/world/pvp.mjs; PvP damage src/game/pvp-rules.js).
      const pvpFoe=!map.monsters.has(input.targetId)&&[...this.players.values()].find(q=>q.id===input.targetId&&q!==p&&sameScene(q,p)&&!isObserver(this,q));
      if(pvpFoe){
        // FIELD-PK: Ctrl (forced attack) arms the attacker; a refusal the original names (Safety Zone 1003:8, ally 1003:3) is told as such
        if(input.forced===true){noteForcedIntent(this,p);const refusal=!isPvpTarget(this,p,pvpFoe)&&pkRefusalText(this,p,pvpFoe);if(refusal)throw new WorldError(400,refusal);}
        await pvpAttack(this,p,pvpFoe,now,step);
        commitAttackStepAdmission(p,stepApproval);
        commitAttackStep(this,p,input.targetId,step,now);
        if(Number.isInteger(step)&&startAttackRoot(this,p,step))p.path=[];   // the accepted swing carries the body along its clip (attack-root-motion.mjs)
        return finish();
      }
      const m = map.monsters.get(input.targetId);
      if (!m || m.dead) throw new WorldError(400, 'Choose a live monster on your map.');
      if(!canClaimDeadFrontTreasure(this,p,m))throw new WorldError(400,'Only the winning Dead Front team can open this treasure.');
      if(isEventObject(m)&&!eventObjectActive(this,p,m))throw new WorldError(400,'This event object is not available for combat.');
      if(isSiegeRenewObject(m)&&!siegeRenewObjectActive(this,p,m))throw new WorldError(400,'This castle object is not available for combat.');
      if(isSiegeRenewGuard(m)&&!siegeRenewGuardActive(this,p,m))throw new WorldError(400,'This castle guard is not an enemy.');
      // a solid object (siege gate / stone pedestal) is reached at its exposed edge, not at its centre
      const hitPoint = m.isBrick && map.collision?.lineOfSight ? objectHitPoint(map, p, m) : null;
      const reach=Math.min(8,p.stats.attackRange||5)+.5,contact=p._normalAttackContacts?.get(m.id);
      // ENGINE-CHOSEN: one bounded monster hit backed by a recent host-observed contact.
      // Current LOS still applies; forced movement, scene changes and fresh far targets do not qualify.
      const recentContact=!m.isBrick&&!m.eventObject&&!['object','invisible','npc','trap'].includes(m.def.role)&&contact?.actor===m&&contact.map===map&&contact.scene===sceneKey(p.map,p.instanceId,p.channel??0)&&contact.channel===(p.channel??0)&&contact.monsterScene===sceneKey(m.map,m.instanceId,m.channel??0)&&contact.revision===(p.mv?.posRev??0)&&
        now>=contact.at&&now-contact.at<=NORMAL_CONTACT.recentMs&&distance(contact.player,contact.monster)<=reach&&
        distance(p,contact.player)<=NORMAL_CONTACT.extraCells&&distance(m,contact.monster)<=NORMAL_CONTACT.extraCells;
      if (distance(p, hitPoint || m) > reach && !(recentContact&&distance(p,m)<=reach+NORMAL_CONTACT.extraCells)) throw new WorldError(400, 'Monster is outside attack range.');
      if (map.collision?.lineOfSight && !(m.isBrick?hitPoint:map.collision.lineOfSight(p.x, p.z, m.x, m.z))) throw new WorldError(400, 'An obstacle blocks this attack.');
      // The combo cadence of the game data (src/game/attack-timing.js, the same numbers the client swings with).
      const attackLimit=playerAttackLimit(this.data,p);
      if (!attackReady(p.attackAt, now, attackLimit.burstMs)) throw new WorldError(429, 'Attack is cooling down.');
      p._normalAttackContacts?.delete(m.id);
      // The target has passed authority/range/collision/cooldown validation.
      // Share its accepted combat heading instead of the last movement heading.
      if (Math.hypot(m.x-p.x,m.z-p.z)>1e-6) p.yaw = Math.atan2(-(m.x - p.x), -(m.z - p.z));
      p.attackAt = nextAttackAt(p.attackAt, now, attackLimit.intervalMs);
      p.lastCombat = now;
      p.path = [];
      // BASIC-ATTACK ROOT MOTION: the accepted swing carries the body along its own clip curve (attack-root-motion.mjs)
      commitAttackStepAdmission(p,stepApproval);
      commitAttackStep(this,p,input.targetId,step,now);
      if (Number.isInteger(step)) startAttackRoot(this, p, step);
      p._skills?.statuses.onAttack(p._skills.game.player);
      const raw = Math.max(1, (p.stats.attackMin || 20) + this.random() * ((p.stats.attackMax || p.stats.attackMin || 20) - (p.stats.attackMin || 20)));
      const fixedDamage = isEventObject(m) || isSiegeRenewObject(m) || (p.gmAuthorized && p.profile.gm?.onehit);
      const defense = fixedDamage ? Math.max(0, m.def.def?.[0] || 0) : penetratedDefense(p, m.def.def?.[0], p.stats.attackType || 'melee');
      const baseDamage = p.gmAuthorized && p.profile.gm?.onehit ? m.hp : Math.max(1, Math.round(raw * 100 / (100 + defense)));
      // MAP-CAPS: the map's level-difference ability caps (block 1: a character attacking a monster) scale or miss the hit.
      const capped = fixedDamage ? { amount: baseDamage, miss: false }
        : applyAbilityCap(this.data.abilityCap?.(p.map), { attackerLevel: p.profile.level, defenderLevel: m.def.level, attackerIsPlayer: true, kind: p.stats.attackType || 'melee' }, baseDamage, () => this.random());
      let damage=capped.miss?0:eventObjectDamage(this,p,m,capped.amount,p.stats.attackType||'melee');
      damage=siegeRenewObjectDamage(this,p,m,damage,p.stats.attackType||'melee');
      // Plain attacks roll the same critical as the client's combat.js: derived stats.critRate (%) and critMultiplier
      // (formula.ini / pcclass); no crit on a miss, a GM one-hit, or fixed-damage event objects.
      const crit=damage>0&&!fixedDamage&&this.random()*100<criticalChance(p,m,Number(p.stats.critRate)||0);
      if(crit)damage=Math.max(1,Math.round(damage*criticalDamageMultiplier(p,m,Number(p.stats.critMultiplier)||1)));
      const blockRate=fixedDamage?0:blockChance(p,m,Number(m.def.blockRate)||0);
      const guardRate=fixedDamage?0:guardChance(p,m,Number(m.def.guard?.[0])||0);
      const block=damage>0&&blockRate>0&&this.random()*100<blockRate;
      const guard=damage>0&&!block&&guardRate>0&&this.random()*100<guardRate;
      if(block)damage=0;
      else if(guard){const efficiency=Number(m.def.guard?.[1])||0;damage=Math.max(1,Math.round(damage*(1-guardEfficiency(m,Math.min(75,efficiency>100?efficiency/10:efficiency))/100)));}
      if(damage>0&&!fixedDamage)damage=modifyHitDamage(p,m,damage);
      m.hp = Math.max(0, m.hp - damage);
      if(damage>0&&!isEventObject(m)&&!isSiegeRenewObject(m))furyHit(this,p);
      // hostility (share/ai/damageaggrocode.csv class code x damage), engagement and the Call patterns (src/game/hate.js, monsterHit)
      if(!isSiegeRenewObject(m))this.monsterHit(m, p, map, now, { hate: plainHitHate(damage, p.profile.classIndex, this.data.skillCommon?.aggro) });
      this.emit(p.map, { type: 'attack', actorId: p.id, targetId: m.id, ...(Number.isInteger(step) ? { variant: step } : {}) });   // observers play this combo step's own clip
      this.emit(p.map, { type: 'damage', sourceId: p.id, targetId: m.id, amount: damage, dead: m.hp === 0, ...(capped.miss ? { miss: true } : {}), ...(crit ? { crit: true } : {}), ...(block ? {block:true}:{}), ...(guard ? {guard:true}:{}) });
      if (m.hp === 0) { m.dead = true; m.targetId = null; clearHate(m); m.called = false; m.respawnAt = isSiegeRenewObject(m)?Infinity:now + respawnDelayMs(m.respawnSec); this.reward(p, m); if(!isEventObject(m)&&!isSiegeRenewObject(m))void this.persistLatest(p).catch(()=>{}); }
      // 2.2.1: the kill's save is queued at once but the reply no longer waits for the disk: a save queued behind other players'
      // saves held kill replies for 1.6-12 s (measured) and those replies feed the HUD ping. Kills that land
      // while that save still waits in the queue join it (persistLatest saves the newest state when it runs). A failed save
      // still marks the player dirty with saveError and the 5 s save retries it, as the player-death save below already did.
    }
    if (input.type === 'travel') {
      if(p.instanceId)throw new WorldError(403,'Use the instance exit to leave this run.');
      // The rendered body can reach the gate before its last movement report
      // reaches the host. A client-named original gate gets a bounded 2.5-cell
      // acknowledgement margin; unnamed travel retains the strict old rule.
      if (input.gateId != null && !Number.isSafeInteger(input.gateId)) throw new WorldError(400, 'Choose an original field gate.');
      const gate = this.data.gates(p.map).find(g => {
        if (g.to.map !== input.map || input.gateId != null && g.id !== input.gateId) return false;
        const right=g.box[2]+(g.exclusive?0:1),bottom=g.box[3]+(g.exclusive?0:1);
        if (input.gateId == null) return p.x>=g.box[0]&&p.z>=g.box[1]&&p.x<right&&p.z<bottom;
        const dx=Math.max(g.box[0]-p.x,0,p.x-right),dz=Math.max(g.box[1]-p.z,0,p.z-bottom);
        return Math.hypot(dx,dz) <= 2.5;
      });
      // A published server map (Map Builder) has no original field gate leading in: a player enters it at its authored start
      // point from an open field (the /custommap command, the big map list and the teleport NPC's [Custom Maps] entry all send
      // this travel). ENGINE-CHOSEN (Global has no custom maps); the map's own level range, the travel-service guard below and
      // every mode that blocks 'travel' (arena, DK Square, colosseum, party PvP) still apply.
      const published = gate ? null : this.data.customMaps?.entry?.(input.map);
      if (!gate && !published) throw new WorldError(403, 'Walk into an original field gate before travelling.');
      if (published && (p.dead || p.mount || p.sceneTransition)) throw new WorldError(403, 'Travel is unavailable while dead, mounted or changing maps.');
      const to = gate ? gate.to : {map: published.index, x: published.start?.x, z: published.start?.z, dirDeg: published.start?.dirDeg};
      const eventMode=this.data.eventData?.modeOf(to.map);
      // The original Ardeca walk-in gate enters the public Colosseum lobby;
      // only the battles beyond a lobby require event-officer admission.
      if(eventMode&&(this.data.eventData?.modeOf(p.map)||!['deadFrontLobby','colosseumLobby'].includes(eventMode)))throw new WorldError(403,'Use the original event officer for admission.');
      // Validate the same field channel which commitFieldTravel retains. A
      // nonzero field channel must not also load an unrelated base scene.
      const destination = await this.map(to.map,null,isDkChannel(p.channel)?p.profile.dkReturn?.channel??0:p.channel??0);
      this.lease(account, input.token);
      const [min, max] = destination.level || [1, 250];
      if (p.profile.level < min || (max && p.profile.level > max)) throw new WorldError(403, 'Your level cannot enter this map.');
      const at = destination.isWalkable(to.x, to.z) ? to : destination.nearest(to.x, to.z);
      if (!at) throw new WorldError(503, 'No safe arrival point is available.');
      await commitFieldTravel(this,p,{map:to.map,x:at.x,z:at.z,dirDeg:to.dirDeg});
    }
    if (input.type === 'revive') {
      if(partyPvpBlocksRevive(this,p))throw new WorldError(400,PARTY_PVP_TEXT.revive);
      if(trainingCampBlocksRevive(this,p))throw new WorldError(400,TRAINING_CAMP_TEXT.revive);
      if(colosseumBlocksRevive(this,p))throw new WorldError(400,COLOSSEUM_REVIVE_TEXT);
      // An item intent must never fall through to an event/town revival that
      // ignores the chosen item. The native field-only policy is public too.
      if(Object.hasOwn(input,'uid')){
        if(typeof input.uid!=='string'||!input.uid.trim())throw new WorldError(400,'Choose one owned native Life Bead.');
        if(!lifeBeadReviveAllowed(this,p))throw new WorldError(400,'Life Bead revival is unavailable in this battle scope.');
      }
      // Premium return point (Respon service): field maps only; an instance's own respawn rules still apply.
      const premiumAt = p.dead && !p.instanceId && !this.data.requiresInstance?.(p.map) ? premiumRespawn(this,p) : null;
      if(p.dead&&huntRevive(this,p)){refillShield(p);this.lease(account,input.token);await this.persist(p);this.emit(p.map,{type:'revive',actorId:p.id});return finish();}
      if(tourneyBlocksRevive(this,p))throw new WorldError(400,TOURNEY_REVIVE_TEXT);
      if(dkrBlocksRevive(this,p))throw new WorldError(400,DKR_REVIVE_TEXT);
      if(p.dead&&Number.isFinite(p.respawnReadyAt)&&this.now()<p.respawnReadyAt)throw new WorldError(400,`Respawn is ready in ${Math.ceil((p.respawnReadyAt-this.now())/1000)} seconds.`);
      if(await reviveWithLifeBead(this,p,input,()=>this.lease(account,input.token)))return finish();
      if(p.dead&&await reviveSiegeRenew(this,p,()=>this.lease(account,input.token)))return finish();
      if(p.dead&&await reviveZuto(this,p,()=>this.lease(account,input.token)))return finish();
      if(p.dead&&await reviveNativeDungeon(this,p,()=>this.lease(account,input.token)))return finish();
      if(p.dead&&await reviveNativeField(this,p,premiumAt,()=>this.lease(account,input.token)))return finish();
      if(p.instanceId)await exitInstance(this,p,{persist:false});
      if (!p.dead) throw new WorldError(400, 'You are already alive.');
      // DK maps revive on their own DK channel by dkmaplist RespawnType (channels.mjs reviveScene).
      const scene = reviveScene(this,p,premiumAt);
      let respawn = premiumAt || scene.at || this.data.respawn || this.data.start, town = null, at = null;
      try { town = await this.map(respawn.map,null,scene.channel); at = town.nearest(respawn.x, respawn.z); } catch (error) { if (!premiumAt) throw error; }
      if (premiumAt && !at) { respawn = this.data.respawn || this.data.start; town = await this.map(respawn.map,null,scene.channel); at = town.nearest(respawn.x, respawn.z); }
      this.lease(account, input.token);
      if (!at) throw new WorldError(503, 'No safe revive point is available.');
      p.map = respawn.map; p.channel = scene.channel; if (scene.leftDk) delete p.profile.dkReturn; p.x = at.x; p.z = at.z; p.hp = p.maxHp; p.mp = p.stats.maxMp || 0; refillShield(p); p.dead = false; p.path = []; this.changed(p); await this.persist(p);
      this.emit(p.map, { type: 'revive', actorId: p.id });
    }
    if (input.type === 'chat') {
      socialChat(this,p,input);
    }
    if (input.type === 'allocate') {
      const { stat, count } = input;
      if (!['str', 'dex', 'con', 'spr'].includes(stat) || !Number.isInteger(count) || count <= 0) throw new WorldError(400, 'Choose STR/DEX/CON/SPR and a positive whole number of points.');
      if (count > (p.profile.statPoints || 0)) throw new WorldError(400, 'You do not have enough stat points.');
      const cap = this.data.statCap?.(p.profile.classIndex, stat) || 65000;
      const next = Number(p.profile.stats[stat] || 0) + count;
      if (next > cap) throw new WorldError(400, `This class cannot exceed ${cap} ${stat.toUpperCase()}.`);
      const updated = { ...p.profile, stats: { ...p.profile.stats, [stat]: next }, statPoints: p.profile.statPoints - count };
      const derived = this.data.stats(updated,p,this.now());
      p.profile = updated; p.stats = derived; p.maxHp = derived.maxHp;
      p.hp = Math.min(p.hp, p.maxHp); p.mp = Math.min(p.mp || 0, derived.maxMp || 0);
      this.changed(p); this.emit(p.map, { type: 'stats', actorId: p.id, stat, count });
      await this.persist(p);
    }
    return finish();
  }
  reward(p, m) {
    if(rewardSiegeRenewGuard(this,p,m))return;
    if(rewardSiegeRenewObject(this,p,m))return;
    m.onKilled?.(p);
    if(rewardEventObject(this,p,m))return;
    for(const member of nearbyPartyMembers(this,p,m))questKill(this,member,m);
    recordLifeEventKill(this,p,m);
    recordSupportRewardKill(this,p,m);
    p.profile.kills = (p.profile.kills || 0) + 1;
    const exp = scaledReward(m.def.exp,this.rates.exp);
    const money = m.def.money || [0, 0, 0], chance = Math.min(1, Math.max(0, money[2] > 1 ? money[2] / 100000 : money[2] || 0));
    // + RESULT_DIL_MUL of the killer's buffs / items (src/game/reward-bonus.js)
    const dil = this.random() < chance ? Math.floor(scaledReward(Math.floor(money[0] + this.random() * Math.max(0, money[1] - money[0] + 1)),this.rates.dil)*(1+playerRewardBonus('dil',p,this.now())/100)) : 0;
    const rolled=monsterLoot(this,p,m);
    // Premium service (Growth Blessing / Holy Water of the Almighty): +Rate % hunting EXP, plus PartyBonusRate x party size
    // inside a party (stringtable_cashitem 510 "[BonusRate*Party]%"). Each recipient's own service counts.
    const shares=partyExpRewards(this,p,exp,m),partySize=shares.length>1?shares.length:0;
    // MAP-CAPS: the map's level-difference table (maplist StrLevelCapPath) sets each recipient's % of the monster EXP.
    const capOf=player=>levelCapRate(this.data.levelCap?.(p.map),(Number(m.def.level)||0)-(Number(player.profile.level)||1))/100;
    // + each recipient's own RESULT_EXP_MUL (EXP scrolls / potions / items; src/game/reward-bonus.js), added like the premium rates
    const bonusOf=player=>capOf(player)*(1+((this.pcRoom?.expPercent(player)||0)+premiumExpPercent(this,player.profile)+premiumPartyBonus(this,player.profile)*partySize+playerRewardBonus('exp',player,this.now()))/100);
    let ownExp=0; // Report the killer's credited party share, including its own bonuses.
    for(const reward of shares){const gain=Math.floor(reward.exp*bonusOf(reward.player));if(reward.player===p)ownExp=Math.max(0,gain);this.grantProgress(reward.player,gain,reward.player===p&&!rolled?dil:0);if(reward.player!==p)this.emit(p.map,{type:'reward',actorId:reward.player.id,exp:gain,dil:0,monsterId:m.id});}
    progressDekaPass(this,p,31,32,m.monsterIndex??m.def.index,1);
    // dil in the reward event = what was CREDITED just now. With ground loot (rolled) the monster's DIL is a pile on the ground that is
    // picked up later (loot.mjs 'pickup'); the separate roll above is not paid, so it must not be shown as obtained.
    this.changed(p); this.emit(p.map, { type: 'reward', actorId: p.id, exp:ownExp, dil: rolled ? 0 : dil, monsterId: m.id });
  }
  grantProgress(p, exp, dil = 0) {
    p.profile.exp = (p.profile.exp || 0) + Math.max(0,Math.floor(exp)); p.profile.dil = Math.max(0,(p.profile.dil || 0)+Math.floor(dil));
    while (p.profile.level < (this.data.maxLevel || 250)) {
      const need = this.data.expNeeded(p.profile.level);
      if (!(need > 0) || p.profile.exp < need) break;
      p.profile.exp -= need; p.profile.level++; p.profile.statPoints = (p.profile.statPoints || 0) + 5; p.profile.skillPoints = (p.profile.skillPoints || 0) + 1;
      claimEligibleGradeRewards(p.profile,this.data.nameplateGrades);
      p.stats = this.data.stats(p.profile,p,this.now()); p.maxHp = p.stats.maxHp; p.hp = p.maxHp; p.mp = p.stats.maxMp || 0;
      this.emit(p.map, { type: 'levelup', actorId: p.id, level: p.profile.level });
    }
    this.changed(p);
  }
  step(p, target, speed, dt, map) {
    const dist = distance(p, target), length = Math.min(dist, speed * dt);
    if (!dist) return true;
    const x = p.x + (target.x - p.x) / dist * length, z = p.z + (target.z - p.z) / dist * length;
    if (!map.isWalkable(x, z) || (map.collision?.lineOfSight && !map.collision.lineOfSight(p.x, p.z, x, z))) return false;
    p.yaw = Math.atan2(-(target.x - p.x), -(target.z - p.z)); p.x = x; p.z = z;
    return length >= dist;
  }
  /** A player (or their servant / DoT) damaged monster `m`: hostility, engagement and the Call patterns (monster-hit.mjs). */
  monsterHit(m, p, map, now, opts) { return monsterHit(this, m, p, map, now, opts); }
  tick() {
    if(this.originalMapEdits?.isCommitting){this.lastTick=this.now();return;}
    this.originalMapEdits?.tick();
    const now = this.now(), dt = Math.min(0.2, Math.max(0, (now - this.lastTick) / 1000)); this.lastTick = now;
    this.sequence++;
    tickTrades(this);tickCharTrades(this);
    tickMegaphone(this);
    for (const p of this.players.values()) {
      if(p.sceneTransition||p.tradeCommitting)continue;
      if (p.leaving) {
        if(p.partyId)leaveParty(this,p);
        if (!p.pendingDisconnect&&!p.disconnectRetry&&now-p.lastSave>=5000) {
          p.lastSave=now;
          const task=this.retryDisconnect?this.retryDisconnect(p):this.finishDisconnect(p);
          p.disconnectRetry=task;void task.finally(()=>{if(p.disconnectRetry===task)p.disconnectRetry=null;}).catch(()=>{});
        }
        continue;
      }
      expireItemEffects(this,p);
      tickWeaponLooks(this,p);   // run-out weapon appearances (ian-appearance.mjs)
      void tickBattleSupport(this,p,dt).catch(()=>{}); // The module stops and reports failed durable stamina writes.
      // A displacement from before this tick is settled first, so only the cast's own root motion is absorbed after it.
      if(!p.leaving){
        trackForcedDisplacement(this,p);tickSkills(this,p,dt);
        // skill clips and basic-attack swings both move the record along their own root curve: one canonical delta
        const skill=p._skills?.engine?.takeRootDelta?.(),swing=tickAttackRoot(this,p,dt);
        noteSkillRootMotion(this,p,skill&&swing?{x:skill.x+swing.x,z:skill.z+swing.z}:skill||swing);
      }
      if(!p.leaving)tickMount(this,p);
      if(!p.leaving&&!p.commandActive)tickPet(this,p,dt);
      if(!p.leaving&&!p.commandActive)tickDekaPass(this,p,dt);
      if(!p.leaving&&!p.commandActive)tickSupportRewards(this,p,dt);
      if(!p.leaving&&!p.commandActive)tickFishing(this,p,dt);
      if (now - p.lastSeen > 60000 && !(this.npcPeriodicAccount?.(p.account)===true&&/^npc_[a-f0-9]{32}$/.test(p.account)&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true)) { void this.leave(p.account, p.token).catch(() => {}); continue; }
      const map = mapFor(this,p);
      const moveBlocked=!!(skillControls(p).move||mountBusy(p)||travelFrozen(this,p)||isShopOpen(this,p));trackMovementBlock(this,p,moveBlocked);
      // A client-predicted mover is extrapolated along its intent between reports (host range checks stay current);
      // its published pose remains the last accepted report (movement-authority.mjs).
      if (reportingMovement(p)) expireIdleReport(this,p);
      if (!p.dead && p.path.length && !moveBlocked) { const before = { x: p.x, z: p.z }; if (this.step(p, p.path[0], pathMovementSpeed(this,p), dt, map)) p.path.shift(); if (distance(p, before)) this.changed(p); else p.path = []; noteHostStep(this,p); }
      tickTravel(this,p);
      trackForcedDisplacement(this,p);
      if (p.gmAuthorized && !p.dead) {
        if (p.profile.gm?.god) p.hp = p.maxHp;
        if (p.profile.gm?.infmp) p.mp = p.stats.maxMp || 0;
      }
      if (!p.dead) {
        // HP, MP and shield regenerate through the same step the local game uses (MP and shield used to be skipped
        // online). HP keeps the server's established 3x out-of-combat factor; shield runs out of combat only.
        const idle = now - (p.lastCombat || 0) > 10000;
        p.maxShield = Number(p.stats.maxShield) || 0;
        if (regenStep(p, p.stats, idle ? 3 : 1, idle, dt)) this.changed(p);
        tickFury(this, p, dt);
      }
      if (!this.npcPeriodicOwner(p) && p.dirty && now - p.lastSave >= 5000) { p.lastSave = now; void this.persistPeriodic(p).catch(() => {}); }
    }
    this.scheduleNpcPeriodic(now);
    tickDungeons(this,dt);
    tickEvents(this,dt);
    void tickOxQuiz(this).catch(()=>{});
    void tickZuto(this).catch(error=>console.warn('[zuto] tick failed',error?.message||error));
    void Promise.resolve(tickSiegeRenew(this)).catch(()=>{});
    tickGuildWarHunting(this);void tickGuildTournament(this).catch(()=>{});void tickDkrPvp(this).catch(()=>{});
    void Promise.resolve(tickGuildFrontier(this)).catch(()=>{});   // scheduled Guild Frontier settlement (guild-frontier.mjs)
    void tickPvp(this).catch(()=>{});void tickPartyPvp(this).catch(()=>{});void tickTrainingCamp(this).catch(()=>{});void tickDkSquare(this).catch(()=>{});
    void tickColosseum(this).catch(()=>{});void Promise.resolve().then(()=>tickSiege(this)).catch(()=>{});void Promise.resolve().then(()=>tickGuildWarPvp(this)).catch(()=>{});
    disposeEmptyInstances(this);
    // Keep player insertion order; eligibility is still checked for each monster.
    // Build only after player movement and event/instance transitions finish.
    const buildMapPlayers=()=>{
      const buckets=new Map();
      for(const p of this.players.values()){
        const scene=mapFor(this,p);let bucket=buckets.get(scene);
        if(!bucket)buckets.set(scene,bucket=[]);bucket.push(p);
      }
      return buckets;
    };
    let mapPlayers=buildMapPlayers();
    // Monster AI: every rule below is the monster's OWN data through src/game/monster-rules.js (shared with the offline brain
    // src/game/ai.js): info.csv sight / pursuit, monster.dat run speed, monsterbattle reach and blocks, the pattern files'
    // call / range behaviour; no global caps. The per-tick cost stays O(monsters x players of that scene): the player list is
    // bucketed per scene above and each monster only tests those players (eligibility is re-checked per monster because an
    // earlier monster's march arrival may move a player).
    const aggroData=this.data.skillCommon?.aggro,TARGET_RADIUS=MONSTER_AI.reach.targetRadius,fb=this.follow;
    // hidden players (skill statuses with ACTION_INVISIBLE: Invisible Shadow 763 / 1563 -> status 3481+; "No one can see you
    // except party members", skilldesc summoner.csv L695) cannot be acquired or kept, derived from the live status list
    const hidden=new Set();for(const p of this.players.values())if(p._skills&&skillControls(p).invisible)hidden.add(p.id);
    // 2.2.1 server load: what a monster may target is the same for every monster of a scene, so the
    // expensive tests (scene key, observer modes, GM hide, invisibility) run once per scene and tick; per monster only the flags
    // that a swing in this very loop can change (dead / leaving / transitions) are re-tested. Rebuilt with mapPlayers.
    let sceneViews=new Map();
    const viewOf=map=>{let v=sceneViews.get(map);if(!v){const list=(mapPlayers.get(map)||[]).filter(p=>!p.leaving&&!p.sceneTransition&&!p.tradeCommitting&&mapFor(this,p)===map&&!p.dead&&!isObserver(this,p)&&!(p.gmAuthorized&&p.profile.gm?.hide)&&!hidden.has(p.id));v={list,byId:new Map(list.map(p=>[p.id,p]))};sceneViews.set(map,v);}return v;};
    // ENGINE-CHOSEN broadphase cells/budget affect work only; original predicates and player order decide results.
    const PLAYER_GRID_CELLS=32,PLAYER_GRID_QUERY_CELLS=4096;let playerGrids=new WeakMap();
    // A caller that only needs a yes/no answer can stop at the first match.
    // Acquiring a target still needs the original insertion order below.
    const nearbyPlayers=(list,m,radius,match)=>{
      const fallback=()=>match?list.some(match):list;
      if(list.length<16||!Number.isFinite(radius)||radius<0||!Number.isFinite(m.x)||!Number.isFinite(m.z))return fallback();
      const x0=Math.floor((m.x-radius)/PLAYER_GRID_CELLS)-1,x1=Math.floor((m.x+radius)/PLAYER_GRID_CELLS)+1,z0=Math.floor((m.z-radius)/PLAYER_GRID_CELLS)-1,z1=Math.floor((m.z+radius)/PLAYER_GRID_CELLS)+1;
      const cells=(x1-x0+1)*(z1-z0+1);
      if(![x0,x1,z0,z1].every(Number.isSafeInteger)||cells>PLAYER_GRID_QUERY_CELLS||cells*2>=list.length)return fallback();
      let grid=playerGrids.get(list);
      if(grid===undefined){
        grid=new Map();
        for(let index=0;index<list.length;index++){
          const p=list[index],x=Object.getOwnPropertyDescriptor(p,'x'),z=Object.getOwnPropertyDescriptor(p,'z');
          if(!x||!z||!Object.hasOwn(x,'value')||!Object.hasOwn(z,'value')||!Number.isFinite(x.value)||!Number.isFinite(z.value)){grid=null;break;}
          const cx=Math.floor(x.value/PLAYER_GRID_CELLS),cz=Math.floor(z.value/PLAYER_GRID_CELLS);
          if(!Number.isSafeInteger(cx)||!Number.isSafeInteger(cz)){grid=null;break;}
          let column=grid.get(cx);if(!column)grid.set(cx,column=new Map());let cell=column.get(cz);if(!cell)column.set(cz,cell=[]);cell.push({p,index});
        }
        playerGrids.set(list,grid);
      }
      if(!grid)return fallback();
      const found=match?null:[];
      for(let x=x0;x<=x1;x++){const column=grid.get(x);if(!column)continue;for(let z=z0;z<=z1;z++){const cell=column.get(z);if(cell)for(const row of cell){if(match){if(match(row.p))return true;}else found.push(row);}}}
      if(match)return false;
      if(found.length===list.length)return list;
      found.sort((a,b)=>a.index-b.index);return found.map(row=>row.p);
    };
    const live=p=>!!p&&!p.leaving&&!p.sceneTransition&&!p.tradeCommitting&&!p.dead;
    // An idle monster only wanders while someone of its scene (any viewer, observers included) is within VIEW_CELLS, the
    // snapshot radius: beyond it nobody can see the walk. 18,313 loaded vs 747 near a player in the 100-player dungeon run.
    const watched=(map,m)=>{const list=mapPlayers.get(map);return !!list?.length&&nearbyPlayers(list,m,VIEW_CELLS,p=>!p.leaving&&Math.abs(p.x-m.x)<VIEW_CELLS&&Math.abs(p.z-m.z)<VIEW_CELLS&&distance(p,m)<VIEW_CELLS);};
    for (const map of this.maps.values()) {
     // the original-map edit freeze is a state of the scene: tested once per scene (it scanned every player for every monster,
     // ~20 % of the tick with thousands of monsters)
     if(this.originalMapEdits?.isFrozen(map.index))continue;
     // follower cap: a member still follows `key` while it is alive, targets it and is still a monster of THIS scene (heals a missed release)
     const fvalid=(o,key)=>!o.dead&&o.targetId===key&&map.monsters.get(o.id)===o;
     for (const m of map.monsters.values()) {
      if(m.renewGuard){tickSiegeRenewGuardCombat(this,m,dt);if(tickSiegeRenewGuardDeath(this,m))continue;}
      if(m.boxOwner&&((m.expiresAt&&m.expiresAt<=now)||(m.dead&&now-(m.boxDiedAt??now)>=10000))){map.monsters.delete(m.id);continue;}
      if(m.boxOwner&&m.dead&&!m.boxDiedAt)m.boxDiedAt=now;
      if (this.gmFrozen) continue;
      if (m.dead) { if(m._fk!=null)fb.release(m); if(m.oneShot){m.corpseObservedAt??=now;if(now-m.corpseObservedAt>=8000)map.monsters.delete(m.id);continue;} if (now >= m.respawnAt) { m.dead = false; m.hp = m.maxHp; m.x = m.home.x; m.z = m.home.z; m.anchor=null;m.idleMove=null;m.targetId=null;m.aiState=REST_STATE;clearHate(m);m.called=false;this.emit(m.map, { type: 'respawn', actorId: m.id }); } continue; }
      if(m.isBrick)continue;
      if(m.oxSpike&&tickOxSpikeCombat(this,m,map,viewOf(map).list))continue;
      const def=m.def,flags=statusFlags(m.statuses),speedMul=statusSpeedMul(m.statuses);
      if(m.eventMarch&&!m.targetId){if(stepEventMarch(this,m,map,dt,{blocked:flags.move,speedMul})){mapPlayers=buildMapPlayers();sceneViews=new Map();playerGrids=new WeakMap();}continue;}
      // objects (role object / pattern 7 event.csv: EXPLORE on every row), traps (13) and attack-less creatures never fight
      if(isNonCombatant(def)||!canAttack(def)){if(m.targetId||m.hate?.size){m.targetId=null;clearHate(m);}if(watched(map,m))idleMonster(this,m,map,dt,speedMul,flags);continue;}
      const sight=aggroRadius(def),pursuit=leashRange(def),immobile=isImmobile(def),mRadius=bodyRadius(def),flim=followLimit(def);
      const sourceV=viewOf(map),eligible=m.oxSpike||m.renewGuard?sourceV.list.filter(p=>(!m.oxSpike||oxSpikeCanTarget(this,m,p))&&(!m.renewGuard||siegeRenewGuardCanTarget(this,m,p))):null,
        V=eligible?{list:eligible,byId:new Map(eligible.map(p=>[p.id,p]))}:sourceV;
      let target=null;
        // 1. the hostility table (aggrosetting.csv keep tick / 20 % switch): the most hated eligible player
        if(m.hate?.size){const id=pickTarget(m,m.targetId,aggroData,now,id=>live(V.byId.get(id)));if(id)target=V.byId.get(id)||null;}
        // 2. a target taken without hostility data (hit before any hate, or recruited by a call)
        if(!target&&m.targetId){const q=V.byId.get(m.targetId);if(live(q))target=q;}
        // 3. SIGHT_IN (aggressive patterns): the first eligible player within DwSight and within DwPersuitRange of its roaming centre (roamCentre(m): where its last chase ended, else its spawn)
        //    (insertion order; which player the original picks when several are in sight is unknown)
        if(!target&&def.ai?.aggressive)target=nearbyPlayers(V.list,m,sight).find(p=>live(p)&&canAcquire({sight,pursuit},m,roamCentre(m),p)&&fb.available(m,p.id,flim,fvalid))||null;
      let d=0,stop=0;
      if(target){d=distance(m,target);stop=preferredReach(def,mRadius,TARGET_RADIUS);if(shouldLeash({sight,pursuit,immobile,forgetRange:Math.max(sight,stop)},m,roamCentre(m),target,{attacking:d<=stop}))target=null;}
      // FOLLOWER CAP (src/game/follow-cap.js): at most dwFollowTarget monsters follow ONE target. Over the cap the monster does not chase / attack it
      // (it keeps its hostility, takes damage as usual, explores) and takes the first free slot; one that already follows another target keeps that one
      if(target&&!fb.claim(m,target.id,flim,fvalid)){const prev=m._fk!=null?V.byId.get(m._fk):null;if(prev&&prev!==target&&live(prev)&&!shouldLeash({sight,pursuit,immobile,forgetRange:Math.max(sight,stop)},m,roamCentre(m),prev,{attacking:distance(m,prev)<=stop})){target=prev;d=distance(m,target);}else{let alt=null;const cand=hatedAlternatives(m,target.id,aggroData,now,id=>live(V.byId.get(id)));if(cand)for(const id of cand){const q=V.byId.get(id);if(!q||shouldLeash({sight,pursuit,immobile,forgetRange:Math.max(sight,stop)},m,roamCentre(m),q,{attacking:distance(m,q)<=stop}))continue;if(fb.claim(m,id,flim,fvalid)){alt=q;break;}}if(alt){target=alt;d=distance(m,alt);}else{if(watched(map,m))idleMonster(this,m,map,dt,speedMul,flags);continue;}}}   // fix: the top hated target is full -> the next hated eligible player with a free slot (party members are separate targets), else wait
      if(!target){
        if(m.renewGuard){m.anchor=null;m.targetId=null;clearHate(m);if(distance(m,m.home)>1){if(!flags.move)this.step(m,m.home,chaseSpeed(def)*speedMul,dt,map);continue;}}
        if(m._fk!=null)fb.release(m);if(m.targetId||m.hate?.size){const out=persuitOutRule(def);m.aiState=out?out.state:REST_STATE;m.idleMove=null;clearHate(m);m.called=false;if(rehomes(def)&&!m.eventMarch)m.anchor={x:m.x,z:m.z};}   // RE-HOME (ENGINE-CHOSEN): a monster that roams (explore range and WalkSpeed > 0, not an event marcher) takes the point where it stands as its roaming centre AND as the origin its pursuit range / leash is measured from (roamCentre(m)), so it keeps following a player it still sees and never walks back; m.home stays the ORIGINAL spawn = the respawn point (only death returns it); only here, never in an explore leg   // PERSUIT_OUT (pattern table NEXT_STATE, mode EXPLORE): hostility dropped, call re-armed; the monster stops chasing and resumes ordinary EXPLORE roaming (idleMonster), hittable, no heal, no evade, no teleport
        m.targetId=null;
        if(watched(map,m))idleMonster(this,m,map,dt,speedMul,flags);
        continue;
      }
      m.idleMove=null;
      m.targetId = target.id;
      // chase at the monster's own run speed (monster.dat) up to its longest base reach; a rooted monster waits in place
      if (d > stop) { if(!immobile&&!flags.move)this.step(m, target, chaseSpeed(def)*speedMul, dt, map); continue; }
      if (now < m.attackAt || flags.attack || (map.collision?.lineOfSight && !map.collision.lineOfSight(m.x, m.z, target.x, target.z))) continue;
      // the attack block: special / power by their rates, aggro1-4 by dwAttackN_Rate, else the base block (range patterns
      // prefer the range block); nothing in reach from here -> close in
      const pick=chooseAttack(def,{dist:d,hpPct:m.maxHp>0?m.hp/m.maxHp*100:100,nowMs:now,specialReadyAt:m.specialReadyAt||0,powerReadyAt:m.powerReadyAt||0,rng:()=>this.random(),mRadius,tRadius:TARGET_RADIUS});
      if(!pick){if(!immobile&&!flags.move)this.step(m,target,chaseSpeed(def)*speedMul,dt,map);continue;}
      m.specialReadyAt=pick.specialReadyAt;m.powerReadyAt=pick.powerReadyAt;
      const attack=pick.block,kind=attackKind(pick.key);
      m.attackAt = now + Math.max(MONSTER_AI.serverSwing.minDelayMs, attack[5] || MONSTER_AI.serverSwing.defaultDelayMs);
      this.emit(m.map,{type:'attack',actorId:m.id,targetId:target.id,instanceId:m.instanceId||null,attackKey:pick.key,variant:attackVariant(pick.key)});
      if(m.renewGuard){attackSiegeRenewGuard(this,m,target,pick.key);continue;}
      if(m.deadIslandRun&&!(target.gmAuthorized&&target.profile.gm?.god)&&deadIslandSuicide(this,m,target,pick.key)){playerGrids=new WeakMap();continue;}
      let damage = target.gmAuthorized && target.profile.gm?.god ? 0 : Math.max(1, Math.round((attack[0] + attack[1]) / 2 * 100 / (100 + (target.stats.defense || 0))));
      // MAP-CAPS: block 2 (a monster attacking a character) of the map's level-difference ability caps.
      let capMiss=false;if(!(target.gmAuthorized&&target.profile.gm?.god)){const c=applyAbilityCap(this.data.abilityCap?.(m.map),{attackerLevel:m.def.level,defenderLevel:target.profile.level,attackerIsPlayer:false,kind:'melee'},damage,()=>this.random());damage=c.amount;capMiss=c.miss;}
      if(!capMiss&&!(target.gmAuthorized&&target.profile.gm?.god)){damage=incomingSkillDamage(this,target,m,damage,kind);playerGrids=new WeakMap();}
      target.hp = Math.max(0, target.hp - damage); target.lastCombat = now; target.dead = target.hp === 0;
      if (damage > 0) furyHurt(this, target);
      if (target.dead) { target.path = []; target.profile.deaths = (target.profile.deaths || 0) + 1; }
      this.changed(target);
      this.emit(m.map, { type: 'damage', sourceId: m.id, targetId: target.id, amount: damage, dead: target.dead, ...(capMiss ? { miss: true } : {}) });
      if(m.deadIslandRun&&!capMiss&&damage>0)deadIslandMonsterAttack(this,m,target,pick.key);
      if (target.dead) void this.persist(target).catch(() => {});
     }
    }
  }
  persistMany(players) {
    if(players.length===1)return this.persist(players[0]);
    if(!this.saveProfiles)throw new WorldError(503,'Atomic party progress storage is unavailable.');
    const updates=players.map(p=>({accountId:p.account,characterId:p.characterId,profile:this.canonical(p)})),versions=players.map(p=>p.revision);
    // The account store takes at most 7 characters per transaction (the party size); larger groups (a 16-player Colosseum Battle Royale) are saved in groups of 7 inside the same queued task.
    const task=this.saveQueue.catch(()=>{}).then(async()=>{for(let i=0;i<updates.length;i+=7)if(await this.saveProfiles(updates.slice(i,i+7))===false)throw new WorldError(503,'Party progress could not be saved.');players.forEach((p,i)=>{if(p.revision===versions[i])p.dirty=false;});});this.saveQueue=task;return this._trackSceneSave(task);
  }
  /** A save of p's NEWEST state: while one waits in the save queue, further calls join it (kills under load collapse into one
   *  write); its record is taken when it starts. Same save, error and dirty handling as persist. */
  persistLatest(p) {
    if(this.saveProfiles&&/^npc_[a-f0-9]{32}$/.test(p.account)&&this.npcPeriodicAccount?.(p.account)===true&&this.players.get(p.account)===p&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.characterId)return this.persistNpcLatest(p);
    if (p._latestSave) return p._latestSave;
    const task = this.saveQueue.catch(() => {}).then(async () => {
      p._latestSave = null;
      const generation = p.revision, record = this.canonical(p);
      try {
        const ok = await this.saveProfile(p.account, p.characterId, record);
        if (ok === false) throw new WorldError(503, 'Authoritative progress could not be saved.');
        p.saveError = null;
        if (p.revision === generation) p.dirty = false;
      } catch (err) { p.dirty = true; p.saveError = 'Server save failed. Keep playing only after storage recovers; current progress is pending.'; throw err; }
    });
    p._latestSave = task; this.saveQueue = task;
    return this._trackSceneSave(task);
  }
  // ENGINE-CHOSEN <=64 trusted NPC latest snapshots, captured at request.
  // Refresh only the unstarted current tail and exact same actor/session;
  // any immediate/other queue task fences it, never recapture future state.
  persistNpcLatest(p) { return this.persistNpcProgress(p,true); }
  // ENGINE-CHOSEN adjacent trusted live NPC captures share one <=64 commit.
  // Humans, staged clones, other queue families and repeated immediate accounts fence it.
  // ENGINE-CHOSEN mixed trusted NPC tail; each entry retains its own custody,
  // outcome and receipt. Staged/immediate boundaries fence latest refresh.
  _queueNpcDurableCheckpoint(entry,kind,hooks,latest=false) {
    const actor=entry.player||entry.original,account=entry.update.accountId;
    const field=p=>!p.instanceId&&!p.profile?.instance&&(p.channel??0)===0&&!p.profile?.dkReturn&&!p.customMapPending&&!this.data.customMaps?.has?.(p.map)&&!this.data.requiresInstance?.(p.map)&&!p.arenaId&&!p.dkSquareId&&!p.colosseumId&&!p.partyPvpId&&!p.trainingCampId&&!p.duelId&&!p.raceRun&&!p.tradeId&&!p.charTradeId&&!p.tradeCommitting&&!p.progressCommitting&&!p.pcShopOpen&&!p.smartWarp&&!p.fishing&&!p.mount;
    const row={entry,kind,hooks,actor},pending=this._npcDurableBatch,old=pending?.entries.get(account);
    const refresh=latest&&kind==='progress'&&pending?.latestRefresh.has(account)&&old?.kind==='progress'&&old.actor===actor&&old.entry.token===entry.token&&old.entry.characterId===entry.characterId&&old.entry.id===entry.id;
    const cross=pending&&[...pending.entries.values()].some(e=>e.kind!==kind);
    if(pending&&!pending.started&&this.saveQueue===pending.task&&((!old&&pending.entries.size<64)||refresh)&&(!cross||field(actor)&&[...pending.entries.values()].every(e=>field(e.actor)))) {
      pending.entries.set(account,row);if(cross)pending.mixed=true;
      if(latest)pending.latestRefresh.add(account);else pending.latestRefresh.clear();
      return pending.task;
    }
    const batch={entries:new Map([[account,row]]),latestRefresh:new Set(latest?[account]:[]),mixed:false,started:false,task:null};
    const task=this.saveQueue.catch(()=>{}).then(async()=>{
      // Collect adjacent trusted NPC captures for one event-loop turn. The
      // existing FIFO tail/custody fences and durable receipts still apply.
      await new Promise(resolve=>setImmediate(resolve));
      batch.started=true;if(this._npcDurableBatch===batch)this._npcDurableBatch=null;
      const rows=[...batch.entries.values()];
      for(const r of rows)r.hooks.start?.(r.entry,task);
      try {
        for(const r of rows){if(batch.mixed&&!field(r.actor))throw new WorldError(503,'Canonical mixed bot progress is unavailable.');r.hooks.validate(r.entry);}
        if(await this.saveProfiles(rows.map(r=>r.entry.update))===false)throw new WorldError(503,'Authoritative progress could not be saved.');
        for(const r of rows)r.hooks.success(r.entry);
      }catch(error){for(const r of rows)r.hooks.failure(r.entry);throw error;}
      finally{for(const r of rows)r.hooks.finish?.(r.entry,task);}
    });
    batch.task=task;this._npcDurableBatch=batch;this.saveQueue=task;return this._trackSceneSave(task);
  }
  persistNpcProgress(p,latest) {
    const entry={player:p,token:p.token,id:p.id,characterId:p.characterId,generation:p.revision,update:{accountId:p.account,characterId:p.characterId,profile:this.canonical(p)}};
    const current=e=>{const player=e.player;return this.players.get(e.update.accountId)===player&&player.token===e.token&&player.id===e.id&&player.characterId===e.characterId&&player.profile?.id===e.characterId;};
    const task=this._queueNpcDurableCheckpoint(entry,'progress',{
      start:(e,task)=>{if(e.player._latestSave===task)e.player._latestSave=null;},
      validate:e=>{if(!current(e)||e.player.profile?.authority!=='server'||e.player.profile?.npcPlayer!==true||this.npcPeriodicAccount?.(e.update.accountId)!==true)throw new WorldError(503,'Canonical bot progress is unavailable.');},
      success:e=>{if(current(e)){e.player.saveError=null;if(e.player.revision===e.generation)e.player.dirty=false;}},
      failure:e=>{if(current(e)){e.player.dirty=true;e.player.saveError='Server save failed. Keep playing only after storage recovers; current progress is pending.';}},
      finish:(e,task)=>{if(e.player._npcLatestFlight?.task===task)e.player._npcLatestFlight=null;}
    },latest);
    if(latest){p._latestSave=task;p._npcLatestFlight={task,token:p.token,id:p.id,characterId:p.characterId};}return task;
  }
  // ENGINE-CHOSEN automatic NPC checkpoint backpressure only. Immediate,
  // learning, life transactions and every human save retain their FIFO paths.
  npcPeriodicOwner(p) { return !!(this.saveProfiles&&p&&/^npc_[a-f0-9]{32}$/.test(p.account)&&this.npcPeriodicAccount?.(p.account)===true&&this.players.get(p.account)===p&&p.npcPlayer===true&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.characterId); }
  scheduleNpcPeriodic(now) {
    if(this._npcPeriodicFlight||this.originalMapEdits?.isCommitting||!Number.isFinite(now))return 0;
    const players=[...this.players.values()];if(!players.length)return 0;
    let cursor=(this._npcPeriodicCursor||0)%players.length,accepted=0;
    for(let scanned=0;scanned<players.length&&accepted<64;scanned++){
      const p=players[cursor];cursor=(cursor+1)%players.length;
      // Ordinary earned transactions remain immediate. Live NPC-only playtime,
      // position and regeneration checkpoints can share a wider batch window.
      if(!this.npcPeriodicOwner(p)||p.leaving||p.progressCommitting||p.tradeCommitting||p.sceneTransition||!p.dirty||now-p.lastSave<15000)continue;
      const task=this.persistPeriodic(p);if(!task)continue;
      p.lastSave=now;accepted++;void task.catch(()=>{});
    }
    this._npcPeriodicCursor=cursor;return accepted;
  }
  persistPeriodic(p) {
    if(!this.npcPeriodicOwner(p))return this.persist(p);
    const pending=this._npcPeriodicBatch;
    if(this._npcPeriodicFlight&&(!pending||pending.started||this.saveQueue!==pending.task||!pending.entries.has(p.account)&&pending.entries.size>=64))return null;
    const entry={player:p,profile:p.profile,token:p.token,id:p.id,characterId:p.characterId,generation:p.revision,update:{accountId:p.account,characterId:p.characterId,profile:this.canonical(p)}};
    if(pending&&!pending.started&&this.saveQueue===pending.task&&(pending.entries.has(p.account)||pending.entries.size<64)){
      pending.entries.set(p.account,entry);return pending.task;
    }
    const batch={entries:new Map([[p.account,entry]]),started:false,task:null};
    const custody=e=>this.npcPeriodicOwner(e.player)&&e.player.profile===e.profile&&e.player.token===e.token&&e.player.id===e.id&&e.player.characterId===e.characterId;
    const task=this.saveQueue.catch(()=>{}).then(async()=>{
      batch.started=true;if(this._npcPeriodicBatch===batch)this._npcPeriodicBatch=null;
      const entries=[...batch.entries.values()].filter(entry=>{
        const {player,generation}=entry;
        if(!custody(entry)||player.revision!==generation||player.progressCommitting||player.tradeCommitting||player.sceneTransition||player.leaving||this.originalMapEdits?.isCommitting){
          if(this.players.get(player.account)===player&&player.token===entry.token&&player.id===entry.id&&player.characterId===entry.characterId&&player.profile===entry.profile)player.dirty=true;
          return false;
        }
        return true;
      });
      if(!entries.length)return;
      try{
        if(await this.saveProfiles(entries.map(e=>e.update))===false)throw new WorldError(503,'Authoritative progress could not be saved.');
        for(const e of entries)if(custody(e)){e.player.saveError=null;if(e.player.revision===e.generation)e.player.dirty=false;}
      }catch(error){
        for(const e of entries)if(custody(e)){e.player.dirty=true;e.player.saveError='Server save failed. Keep playing only after storage recovers; current progress is pending.';}
        throw error;
      }
    });
    batch.task=task;this._npcPeriodicBatch=batch;this._npcPeriodicFlight=task;this.saveQueue=task;
    void task.finally(()=>{if(this._npcPeriodicFlight===task)this._npcPeriodicFlight=null;}).catch(()=>{});
    return this._trackSceneSave(task);
  }
  // ENGINE-CHOSEN <=64 distinct trusted NPC immediate snapshots at the
  // unchanged saveQueue tail. Duplicate accounts always create a later batch.
  // Staged transaction candidates and all humans keep ordinary single saves.
  persistNpcImmediate(p) { return this.persistNpcProgress(p,false); }
  // ENGINE-CHOSEN <=64 distinct ordinary NPC learn checkpoints at the current
  // unstarted saveQueue tail. Capture the staged transaction at request; the
  // original actor owns publication only after its own durable receipt settles.
  // ENGINE-CHOSEN bounded distinct trusted NPC staged life checkpoints.
  persistNpcLifeCheckpoint(original,staged) {
    const field=p=>!p.instanceId&&!p.profile?.instance&&(p.channel??0)===0&&!p.profile?.dkReturn&&!p.customMapPending&&!this.data.customMaps?.has?.(p.map)&&!this.data.requiresInstance?.(p.map)&&!p.arenaId&&!p.dkSquareId&&!p.colosseumId&&!p.partyPvpId&&!p.trainingCampId&&!p.duelId&&!p.raceRun&&!p.tradeId&&!p.charTradeId&&!p.tradeCommitting&&!p.progressCommitting&&!p.pcShopOpen&&!p.smartWarp&&!p.fishing&&!p.mount;
    const owned=()=>field(original)&&this.players.get(original.account)===original&&/^npc_[a-f0-9]{32}$/.test(original.account)&&this.npcPeriodicAccount?.(original.account)===true&&original.npcPlayer===true&&original.profile?.authority==='server'&&original.profile?.npcPlayer===true&&original.characterId===original.profile.id&&original.id===original.account+':'+original.characterId;
    if(typeof this.saveProfiles!=='function'||!owned()||staged===original||staged.account!==original.account||staged.id!==original.id||staged.token!==original.token||staged.characterId!==original.characterId||staged.profile===original.profile||staged.profile?.id!==original.characterId||staged.profile?.authority!=='server'||staged.profile?.npcPlayer!==true||!original.sceneTransition||!(original.commandActive>0))throw new WorldError(503,'Canonical bot life progress is unavailable.');
    const entry={original,staged,profile:original.profile,stagedProfile:staged.profile,token:original.token,id:original.id,characterId:original.characterId,generation:staged.revision,update:{accountId:original.account,characterId:original.characterId,profile:this.canonical(staged)}};
    const custody=e=>field(e.original)&&this.players.get(e.update.accountId)===e.original&&e.original.token===e.token&&e.original.id===e.id&&e.original.characterId===e.characterId&&e.original.profile===e.profile&&e.profile.id===e.characterId&&e.profile.authority==='server'&&e.profile.npcPlayer===true&&e.original.npcPlayer===true&&this.npcPeriodicAccount?.(e.update.accountId)===true;
    const stage=e=>e.staged.profile===e.stagedProfile&&e.staged.account===e.update.accountId&&e.staged.token===e.token&&e.staged.id===e.id&&e.staged.characterId===e.characterId&&e.stagedProfile.id===e.characterId;
    const receipt=(task,e)=>task.then(()=>{if(!custody(e)){const error=new WorldError(409,'Saved bot life progress awaits original actor reconciliation.');Object.defineProperty(error,'npcLifeCheckpointCommitted',{value:true});throw error;}return {isCurrent:()=>custody(e),hasQueuedSuccessor:()=>this.saveQueue!==task};});
    const task=this._queueNpcDurableCheckpoint(entry,'life',{
      validate:e=>{if(!custody(e)||!stage(e))throw new WorldError(503,'Canonical bot life progress is unavailable.');},
      success:e=>{if(stage(e)){e.staged.saveError=null;if(e.staged.revision===e.generation)e.staged.dirty=false;}},
      failure:e=>{if(stage(e)){e.staged.dirty=true;e.staged.saveError='Server save failed. Keep playing only after storage recovers; current progress is pending.';}}
    });return receipt(task,entry);
  }
  persistNpcSkillCheckpoint(original,staged) {
    const owned=()=>this.players.get(original.account)===original&&/^npc_[a-f0-9]{32}$/.test(original.account)&&this.npcPeriodicAccount?.(original.account)===true&&original.npcPlayer===true&&original.profile?.authority==='server'&&original.profile?.npcPlayer===true&&original.characterId===original.profile.id&&original.id===original.account+':'+original.characterId;
    if(typeof this.saveProfiles!=='function'||!owned()||staged===original||staged.account!==original.account||staged.id!==original.id||staged.token!==original.token||staged.characterId!==original.characterId||staged.profile===original.profile||staged.profile?.id!==original.characterId||staged.profile?.authority!=='server'||staged.profile?.npcPlayer!==true||!original.sceneTransition||!(original.commandActive>0))throw new WorldError(503,'Canonical bot learning is unavailable.');
    const entry={original,staged,profile:original.profile,stagedProfile:staged.profile,token:original.token,id:original.id,characterId:original.characterId,generation:staged.revision,update:{accountId:original.account,characterId:original.characterId,profile:this.canonical(staged)}};
    const custody=e=>this.players.get(e.update.accountId)===e.original&&e.original.token===e.token&&e.original.id===e.id&&e.original.characterId===e.characterId&&e.original.profile===e.profile&&e.profile.id===e.characterId&&e.profile.authority==='server'&&e.profile.npcPlayer===true&&e.original.npcPlayer===true&&this.npcPeriodicAccount?.(e.update.accountId)===true;
    const stage=e=>e.staged.profile===e.stagedProfile&&e.staged.account===e.update.accountId&&e.staged.token===e.token&&e.staged.id===e.id&&e.staged.characterId===e.characterId&&e.stagedProfile.id===e.characterId;
    const receipt=(task,e)=>task.then(()=>{if(!custody(e)){const error=new WorldError(409,'Saved bot learning awaits original actor reconciliation.');Object.defineProperty(error,'npcSkillCheckpointCommitted',{value:true});throw error;}return {hasQueuedSuccessor:()=>this.saveQueue!==task};});
    const task=this._queueNpcDurableCheckpoint(entry,'skill',{
      validate:e=>{if(!custody(e)||!stage(e))throw new WorldError(503,'Canonical bot learning is unavailable.');},
      success:e=>{if(stage(e)){e.staged.saveError=null;if(e.staged.revision===e.generation)e.staged.dirty=false;}},
      failure:e=>{if(stage(e)){e.staged.dirty=true;e.staged.saveError='Server save failed. Keep playing only after storage recovers; current progress is pending.';}}
    });return receipt(task,entry);
  }
  persist(p, storeObserver=null) {
    if(this.saveProfiles&&/^npc_[a-f0-9]{32}$/.test(p.account)&&this.npcPeriodicAccount?.(p.account)===true&&this.players.get(p.account)===p&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.characterId)return this.persistNpcImmediate(p);
    const generation = p.revision, record = this.canonical(p);
    const task = this.saveQueue.catch(() => {}).then(async () => {
      try {
        if(typeof storeObserver==='function'){try{const pending=storeObserver();if(pending&&typeof pending.then==='function')void Promise.resolve(pending).catch(()=>{});}catch{}}
        const ok = await this.saveProfile(p.account, p.characterId, record);
        if (ok === false) throw new WorldError(503, 'Authoritative progress could not be saved.');
        p.saveError = null;
        if (p.revision === generation) p.dirty = false;
      } catch (err) { p.dirty = true; p.saveError = 'Server save failed. Keep playing only after storage recovers; current progress is pending.'; throw err; }
    });
    this.saveQueue = task;
    return this._trackSceneSave(task);
  }
  _trackSceneSave(task){this._saveFlights++;void task.finally(()=>{this._saveFlights--;}).catch(()=>{});return task;}
  leaveNpcWave(rows) {
    if(!Array.isArray(rows)||!rows.length||rows.length>64||typeof this.saveProfiles!=='function')throw new WorldError(503,'Bounded NPC departure storage is unavailable.');
    const seen=new Set(),input=rows.map(row=>{
      const p=row?.player,token=row?.token;
      if(!p||seen.has(p.account))throw new WorldError(409,'NPC departure participants must be distinct.');
      seen.add(p.account);return {player:p,account:p.account,characterId:p.characterId,actorId:p.id,token};
    });
    for(const row of input)this.checkNpcDeparture(row);
    const accounts=[...seen].sort(),release=this.acquireSceneLease(null);
    const previous=accounts.map(account=>(this.accountQueues.get(account)||Promise.resolve()).catch(()=>{}));
    const task=Promise.all(previous).then(()=>this._leaveNpcWave(input));
    for(const account of accounts)this.accountQueues.set(account,task);
    void task.finally(()=>{for(const account of accounts)if(this.accountQueues.get(account)===task)this.accountQueues.delete(account);release();}).catch(()=>{});
    return task;
  }
  checkNpcDeparture(row,{reserved=false}={}) {
    const p=row.player;
    if(this.players.get(row.account)!==p||p.account!==row.account||!/^npc_[a-f0-9]{32}$/.test(row.account)||this.npcPeriodicAccount?.(row.account)!==true||p.npcPlayer!==true||p.profile?.authority!=='server'||p.profile?.npcPlayer!==true||p.characterId!==row.characterId||p.profile.id!==row.characterId||p.id!==row.actorId||p.id!==row.account+':'+row.characterId||typeof row.token!=='string'||!row.token||p.token!==row.token||p.leaving||p.revoked||p.commandActive||p.progressCommitting||p.tradeCommitting||(!reserved&&p.sceneTransition)||p.pendingDisconnect||p.disconnectRetry||this._npcAdmissionEvents?.has(p.id)||p.instanceId||p.tradeId||p.charTradeId)throw new WorldError(409,'NPC departure is not quiescent. Use ordinary departure after accepted work finishes.');
    if(reserved&&(p._npcDepartureFence!==row.fence||p.sceneTransition!==true||p.profile!==row.profile))throw new WorldError(409,'NPC departure reservation changed.');
  }
  async _leaveNpcWave(input) {
    const check=()=>{for(const row of input)this.checkNpcDeparture(row);};
    check();
    // Await the real life-queue stop. It follows accepted life commits, never
    // races them. Instance actors deliberately keep the ordinary path.
    for(const row of input){await battleSupportCommand(this,row.player,{type:'battlesupport',operation:'stop',token:row.token});check();await flushInstanceProgress(this,row.player);check();}
    const fence=Symbol('owned NPC departure reservation');let committed=false;
    for(const row of input){row.fence=fence;row.profile=row.player.profile;row.player._npcDepartureFence=fence;row.player.sceneTransition=true;}
    try{
      const task=this.saveQueue.catch(()=>{}).then(async()=>{
        for(const row of input)this.checkNpcDeparture(row,{reserved:true});
        const entries=input.map(row=>({row,generation:row.player.revision,update:{accountId:row.account,characterId:row.characterId,profile:this.canonical(row.player)}}));
        for(const {row,generation}of entries){this.checkNpcDeparture(row,{reserved:true});if(row.player.revision!==generation)throw new WorldError(409,'NPC progress changed while preparing departure.');}
        if(await this.saveProfiles(entries.map(entry=>entry.update))===false)throw new WorldError(503,'NPC departures could not be checkpointed.');
        committed=true;
        // No partial detach: validate the complete wave after the await. Any
        // intervening earned state remains live/dirty for ordinary departure.
        for(const {row,generation}of entries){this.checkNpcDeparture(row,{reserved:true});if(row.player.revision!==generation)throw new WorldError(409,'NPC progress changed during departure checkpoint.');}
        for(const {row}of entries){const p=row.player;p.saveError=null;p.dirty=false;p.leaving=true;cancelTrade(this,p,'disconnected');cancelCharTrade(this,p,'disconnected');leaveParty(this,p);this.players.delete(row.account);this.emit(p.map,{type:'leave',actorId:p.id,instanceId:p.instanceId||null});}
        disposeEmptyInstances(this);return {departed:entries.length,checkpointed:entries.length};
      });
      this.saveQueue=task;return await this._trackSceneSave(task);
    }catch(error){
      for(const row of input){const p=row.player;if(this.players.get(row.account)===p){p.dirty=true;p.saveError='NPC departure is pending. Keep the actor until storage and accepted progress settle.';}}
      if(committed)error.npcDepartureCommitted=true;
      throw error;
    }finally{
      for(const row of input){const p=row.player;if(p._npcDepartureFence===fence){delete p._npcDepartureFence;if(p.sceneTransition===true)p.sceneTransition=false;}}
    }
  }
  async detachPlayer(p) {
    if(this.players.get(p.account)!==p)return;
    await battleSupportCommand(this,p,{type:'battlesupport',operation:'stop',token:p.token});
    await flushInstanceProgress(this,p);
    if(this.players.get(p.account)!==p)return;
    p.leaving=true;
    try{await this.persist(p);}catch(error){if(!p.revoked)p.leaving=false;throw error;}
    if(this.players.get(p.account)===p){cancelTrade(this,p,'disconnected');cancelCharTrade(this,p,'disconnected');leaveParty(this,p);this.players.delete(p.account);this.emit(p.map,{type:'leave',actorId:p.id,instanceId:p.instanceId||null});disposeEmptyInstances(this);}
  }
  async leave(account, token) {
    const p=this.lease(account,token);
    return this.serializeAccount(account,()=>this.detachPlayer(p));
  }
  finishDisconnect(p,{commandAllowance=0}={}) {
    if(this.players.get(p.account)!==p)return Promise.resolve();
    if(p.pendingDisconnect)return p.pendingDisconnect;
    const task=this.serializeAccount(p.account,async()=>{if(this.players.get(p.account)!==p)return;if((p.commandActive||0)>commandAllowance)throw Object.assign(new WorldError(409,'Wait for accepted commands before disconnect cleanup.'),{code:'WORLD_BUSY'});return this.detachPlayer(p);});
    p.pendingDisconnect=task;
    void task.finally(()=>{if(p.pendingDisconnect===task)p.pendingDisconnect=null;}).catch(()=>{});
    return task;
  }
  async close() { await Promise.allSettled([...this.accountQueues.values(),...[...this.players.values()].map(p=>p.disconnectRetry).filter(Boolean)]); for(const p of this.players.values()){await battleSupportCommand(this,p,{type:"battlesupport",operation:"stop",token:p.token});await flushInstanceProgress(this,p);} await Promise.all([...this.players.values()].filter(p => p.dirty).map(p => this.persist(p))); await this.saveQueue; this.players.clear();for(const [index,owner]of this._fieldMapOwners)this.data.releaseMapReference?.(index,owner);this._fieldMapOwners.clear(); }
}
