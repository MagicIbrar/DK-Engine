import {npcEventSupport} from './npc-event-support.mjs';
import {Container} from '../../src/systems/items/model.js';
import {S} from '../../src/systems/items/equip.js';
import {createNpcFishingDirectorHook} from './npc-fishing-objective.mjs';
import {randomUUID} from 'node:crypto';
import {NPC_PROFILE_LIMIT} from './npc-profiles.mjs';
import {characterRef} from '../accounts/character-ref.mjs';
import {performance} from 'node:perf_hooks';
import {setImmediate as yieldTurn,setTimeout as pause} from 'node:timers/promises';
import {sameScene,sceneKey,mapFor} from './scene.mjs';
import {createQuestContext,starterQuest} from './quests.mjs';
import {groundDrops} from './loot.mjs';
import {npcReply,dialogueIntent,npcDialogueContextFits} from './npc-dialogue.mjs';
import {isDkChannel} from './channels.mjs';
import {npcRecovery,npcSupport} from './npc-tactics.mjs';
import {npcPopulationChoice,npcNativeActivities,npcNativeActivityAnchors,npcPointBudget,seedNpcStartingStock,npcBuildStep,npcSpareStatPlan,npcRefinementPlan,npcSalePlan} from './npc-builds.mjs';
import {npcUsername,npcWantsParty,npcDecisionDelay,npcCombatSkillReady,npcFollowPoint,npcCompetenceTier} from './npc-personality.mjs';
import {npcArchetypeCityPreference,npcArchetypeSummary,npcArchetypeReactionWake} from './npc-archetypes.mjs';
import {npcSessionsEnabled,npcSessionOnline} from './npc-resident-schedule.mjs';
import {createNpcCityRetention} from './npc-city-retention.mjs';
import {NPC_CITY_DUTY_POLICY,createNpcCityDutyPlanner,npcCityDutyEligible,npcCityResidentTarget,npcCityBeggarIdentity,createNpcCityRequester,npcCityDamageWake} from './npc-city-duty.mjs';
import {npcNormalizeLocalizedInput,npcLocalizeText} from './npc-chat-localization.mjs';
import {createNpcEventParties} from './npc-event-parties.mjs';
import {npcEventWalkStage} from './npc-chain-fire-attendance.mjs';
import {npcPvpStep} from './npc-pvp.mjs';
import {npcPkSocialDecision} from './npc-pk-social.mjs';
import {npcGuildLifeStep,npcGuildWarTarget} from './npc-guild-life.mjs';
import {npcGenerosityStep} from './npc-generosity.mjs';
import {npcSceneDensity,npcScaledDensity} from './npc-density.mjs';
import {npcFriendHumans} from './npc-friends.mjs';
import {npcCombatPreparation,npcCombatSkills,npcCombatCadence,NPC_COMBAT_ATTEMPTS,npcCombatAttemptReady,npcCombatRefusal} from './npc-combat-strategy.mjs';
import {npcAddress} from './npc-addressing.mjs';
import {npcAssignActivity,npcTownMerchantInspection,npcRoutineWork,npcFarmEnemy,npcFieldTeam,npcPendingHumanInvite} from './npc-activities.mjs';
import {npcQuestSpawnMap} from './npc-quest-targets.mjs';
import {npcLootEligible,npcLootRefused} from './npc-loot.mjs';
import {npcBagPressure,npcStoragePlan} from './npc-bag.mjs';
import {npcQuestFeasible,npcQuestObjectiveRunnable,npcQuestTalkOnly,npcQuestStall,npcQuestDeferred,npcQuestProgressed} from './npc-quest-feasibility.mjs';
import {createNpcOptionalWorkPacer} from './npc-optional-work-pacer.mjs';
import {npcFreeplayPlan} from './npc-freeplay-plan.mjs';
import {npcMerchantStep,npcMerchantOpportunity,npcMerchantResidentPriority,npcMerchantOffers,npcMerchantReservationStep,npcMerchantReservedSaleUids,npcSupplyStep} from './npc-merchant.mjs';
import {npcPreferredCityMerchant} from './npc-city-merchant-selection.mjs';
import {npcRoutePlan} from './npc-routing.mjs';
import {npcDeadFrontObjectivePlan} from './npc-dead-front-objectives.mjs';
import {objectHitPoint} from './object-combat.mjs';
import {attackStepFor,previewAttackStep} from './attack-root-motion.mjs';
import {npcOrganizerPlan,npcOrdinaryOrganizerStep} from './npc-organizer.mjs';
import {npcReachableApproach,createNpcApproachCache} from './npc-navigation.mjs';
import {npcDungeonObjectivePlan} from './npc-dungeon-objectives.mjs';
import {ensureSkills} from './skills.mjs';
import {npcRememberCombatStart,createNpcQueueRequester,npcQueuePriorityReady,npcSettleQueuedCadence} from './npc-combat-queue.mjs';
import {npcCombatIntelEnabled,npcImmediateThreat,npcIntelSurvival,npcIntelUrgentSupport,npcIntelNoteCast} from './npc-combat-intel.mjs';
import {npcAllies} from './npc-tactics.mjs';
// LANE3 team/navigation hooks (DEKARON_NPC_TEAM=0 / DEKARON_NPC_NAV=0 restore lane2 behaviour exactly).
import {npcTeamEnabled,npcTeamMemberStep,npcTeamLeaderTarget,npcTeamForget} from './npc-team.mjs';
import {npcNavEnabled,npcNavBeforeMove,npcNavAfterMove,npcNavForget} from './npc-team-nav.mjs';
import {npcFollowPlan} from './npc-following.mjs';
import {npcReusableResidents,npcResidentHasAcceptedWork,nativeResidentBand} from './npc-roster-selection.mjs';
import {createNpcBackgroundSim} from './npc-background-sim.mjs';
import {npcRecruitmentCandidates} from './npc-recruitment.mjs';
import {createNpcConversations} from './npc-conversations.mjs';
import {npcPartyRecruitment} from './npc-language.mjs';
import {npcEquipmentServiceStep} from './npc-equipment-services.mjs';
import {npcRequestDecision,npcConversationAttention} from './npc-agency.mjs';
import {npcCommerceStep,npcCommerceAdvertise} from './npc-commerce.mjs';
import {npcCommerceConversationIntent,npcCommerceReply,npcCommerceGiftConsent} from './npc-commerce-conversation.mjs';
import {npcTownPartyPlan,npcTownServicePlan,npcTownYieldPlan,npcTownWaitPlan} from './npc-town-layout.mjs';
import {fishingBusy} from './fishing.mjs';
import {npcPullPlan} from './npc-pulling.mjs';
import {npcCanDiscussPull} from './npc-combat-talk.mjs';
import {ORDINARY_RESPAWN_WAIT_MS} from '../../src/config/engine-chosen-respawn.js';
import {createNpcResidentSchedule,NPC_RESIDENT_POLICY} from './npc-resident-schedule.mjs';
import {npcNativeResidentSpawn} from './npc-resident-spawn.mjs';
import {createNpcFieldVisitors,NPC_FIELD_VISITOR_POLICY,npcOccupiedField,npcFieldVisitorProtected,npcFieldCohortEligible,npcTownIdlePlan} from './npc-field-visitors.mjs';
import {npcGatheringRecruitment} from './npc-gathering-recruitment.mjs';
import {npcCoachingReply} from './npc-coaching.mjs';
import {npcKnowledgeReply,npcQuestTalkGoal} from './npc-chat-knowledge.mjs';
import {npcSituationReply} from './npc-situational-knowledge.mjs';
import {npcPersona,npcPersonaSpeech,npcTypingDelay,npcPersonaHelpQuestion} from './npc-persona.mjs';
import {npcQuestDecision} from './npc-quest-decision.mjs';
import {npcSocialReply,npcSocialIntent} from './npc-social-talk.mjs';
import {createNpcQuestAssistance} from './npc-quest-assistance.mjs';
import {createNpcBackgroundWork} from './npc-background-work.mjs';
import {createNpcBackgroundPopulation,npcBackgroundProfileEligible} from './npc-background-population.mjs';
import {createNpcFieldResidency} from './npc-field-residency.mjs';
import {npcRememberConversationOffer,npcConversationConsent,npcDialogueOffer} from './npc-social-dialogue.mjs';
import {npcConversationCue} from './npc-conversation-cues.mjs';
import {createNpcSceneWarming} from './npc-scene-warming.mjs';
import {createNpcAdmissionBudget} from './npc-admission-budget.mjs';
import {createNpcDecisionFlights} from './npc-decision-flights.mjs';

// ENGINE-CHOSEN optional NPC player population/decisions/dialogue. All game actions use ordinary server validation.
export const NPC_POLICY=Object.freeze({perScene:6,total:42,thinkMs:650,backgroundTickMs:150,chatDistance:24,ambientMs:45000,roamRadius:30,followDistance:2.8});
// ENGINE-CHOSEN interest-managed mode prepares human-occupied scenes. Ordinary
// accepted native work can retain an exact off-scene actor until it settles;
// that transient custody is not a background worker or human-visible cohort.
// Other saved residents remain dormant; presence summaries are intentions.
export const NPC_INTEREST_POLICY=Object.freeze({...NPC_POLICY,perScene:70,maxPerScene:70,total:150,orphanGraceMs:45000});
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
// ENGINE-CHOSEN bounded conversation staggering. Persistent roster identifiers
// do not represent thousands of seconds of typing or social delay.
export function npcConversationPhase(slot){const value=Number(slot);return Number.isFinite(value)?Math.max(0,Math.trunc(value))%12:0;}
// Prepared native metadata only. Choosing an intention never loads geometry,
// moves a character or awards progress; ordinary actions retain those powers.
export function npcFreeplayCatalog(data,indices){
 const maps=[...new Set(indices||[])].filter(index=>Number.isSafeInteger(index)&&index>=0&&data.mapRow?.(index)&&!data.requiresInstance?.(index)&&!data.eventData?.modeOf?.(index)&&!Number(data.mapRow(index).IsSiege)).sort((a,b)=>a-b);
 return {revision:JSON.stringify(maps),maps,areas:new Map(maps.map(index=>[index,{farmLevels:new Set((data.spawns?.(index)||[]).map(s=>data.monsterDef?.(s.monsterIndex)).filter(d=>d?.role==='creature'&&Number(d.exp)>0).map(d=>Number(d.level)).filter(Number.isInteger))}]))};
}
// ENGINE-CHOSEN lazy quest preference; native eligibility and approach callbacks
// remain authoritative. Try the explicit goal before computing alternatives.
// PRIVATE V2: structural bag probes reuse ordinary footprint/stack placement.
// Probe chunks never exceed one stack, so Container.add cannot allocate split UIDs.
// Random sockets on stackable equipment use the conservative unique shape.
export function npcQuestPlanningCanFit(inv,list){
 if(!Array.isArray(list)||!inv?.db||!Array.isArray(inv.profile?.inventory))return false;
 const db=inv.db,bag=new Container(structuredClone(inv.profile.inventory),db,{pages:7,cols:10,rows:5,unlocked:()=>inv.profile.bagsUnlocked||2,name:'quest planning'});
 for(const e of list){
  if(!e||typeof e!=='object')return false;
  const index=Number(e.item),def=db.def(index),count=e.count||1;
  if(!def||!Number.isInteger(count)||count<1||count>100000)return false;
  const stack=db.stackSize(def);if(!Number.isInteger(stack)||stack<1)return false;
  let left=count;while(left>0){
   const n=Math.min(left,stack),probe={itemIndex:index,count:n,grade:'normal'};
   if(e.bound)probe.bound=true;
   if(e.rnd){if(!Array.isArray(e.rnd)||e.rnd.some(o=>o==null))return false;probe.rnd=e.rnd.map(o=>[Number(o[0]),Number(o[1])]);}
   if(Array.isArray(e.sockets))probe.sockets=e.sockets.slice(0,4).map(v=>Number(v)||0);
   else if(Number.isFinite(e.sockets)&&e.sockets>0){if(!Number.isInteger(e.sockets))return false;probe.sockets=new Array(Math.min(4,e.sockets)).fill(0);}
   else if(e.roll&&def.slot&&(def.socketRates||[]).some(v=>Number(v)>0))probe.sockets=[0];
   if(e.brand?.length){if(!Array.isArray(e.brand)||e.brand.some(o=>o==null))return false;probe.brand=e.brand.map(o=>[Number(o[0]),Number(o[1])]);}
   if(def.period>0||e.period>0)probe.expiresAt=1;
   if(!bag.add(probe).ok)return false;
   left-=n;
  }
 }
 return true;
}
// Menu availability remains unchanged; only the NPC planning predicate is stricter.
export function npcQuestAcceptEligible(c,q){
 if(!c.engine.check(q.id).ok)return false;
 // Mirror the server accept rule (quests.mjs questCommand): plan only a quest that one of its
 // placed givers natively offers now, or the untouched Ardeca starter offer. Quests no original
 // NPC offers (e.g. untitled 6100-series rows) were otherwise chosen and refused in a loop.
 const givers=[q.giver?.npc,...(q.giver?.alt||[])].filter(n=>n!=null).map(Number);
 if(!givers.some(npc=>c.engine.offerPath(q.id,{npc}))&&!(Number(q.id)===Number(starterQuest(c.tables))&&Number(c.game?.world?.info?.index)===150&&!c.engine.st?.flags?.autoStarted))return false;
 const r=q.require||{},inv=c.engine.inv,num=v=>Number(v)||0;
 if(r.dil&&inv.dil<num(r.dil))return false;
 if((r.items||[]).some(it=>inv.count(it.item)<Math.max(1,num(it.count))))return false;
 if(r.status&&!c.engine._hasStatus(r.status))return false;
 if(r.giveOnAccept?.length&&!npcQuestPlanningCanFit(inv,r.giveOnAccept))return false;
 return true;
}
export function chooseNpcQuest({quests,seedId,slot=0,level=1,map,eligible,reachable,planning,context,now}){
 if(planning)return npcQuestDecision({quests,seedId,slot,level,map,eligible,reachable,planning,context,now});
 const seed=quests?.[seedId],offered=q=>q&&!q.isGroup&&!q.hidden&&eligible(q);
 if(offered(seed)&&reachable(seed))return seed;
 const candidates=Object.values(quests||{}).filter(q=>q!==seed&&Number(q.giver?.map)===Number(map)&&offered(q)).sort((a,b)=>Math.abs((a.level?.[0]||1)-level)-Math.abs((b.level?.[0]||1)-level));
 if(!candidates.length)return null;const offset=(Math.max(0,Math.trunc(Number(slot)||0))%Math.min(6,candidates.length));
 // Preserve varied starting preferences, then examine every eligible alternative.
 for(let i=0;i<candidates.length;i++){const q=candidates[(offset+i)%candidates.length];if(reachable(q))return q;}
 return null;
}
import {npcCapacityPolicy,npcSnapshotInterest,createNpcAdmissionFence} from './npc-capacity-policy.mjs';
import {npcSlotsAvailable,canonicalNpc} from './npc-human-slots.mjs';
import {findWorldPlayer} from './actor-lookup.mjs';
export function createNpcPlayers({world,profiles,dormantRoster,enabled=()=>false,population=()=>100,language=()=> 'en',command=(id,input)=>(world.npcAction||world.action).call(world,id,input),capacity=null,background=null,policy=background?NPC_INTEREST_POLICY:NPC_POLICY,onError=()=>{}}){
 if(background&&capacity)throw Error('Interest-managed bots and the native capacity tier are mutually exclusive');
 const capacityPolicy=npcCapacityPolicy(capacity),capacityStartup={phase:'not-started',pending:null,elapsedMs:0,deadlineExceeded:false,complete:false};
 world.npcSlotCapacity=capacityPolicy?.actorCap??policy.total;
 const physicalNpcCount=()=>[...world.players.values()].filter(p=>p.npcPlayer===true||p.profile?.npcPlayer===true).length;
 const foregroundCount=()=>[...brains.keys()].filter(id=>!populationWorkers?.owns(world.players.get(id))).length;
 const brains=new Map(),sceneRetry=new Map(),rosterBlocked=new Map(),ambientScenes=new Map(),socialScenes=new Map(),conversations=new Map(),moveIntents=new WeakMap();let busy=null,closed=false,epoch=0,eventCursor=world.sequence,rosterSerial=0,residentRoster,freeplayCatalog,lastPrime=null,cycleCursor=0,decisionCount=0,lastDecisionAt=0;
 const sceneWarming=createNpcSceneWarming({now:world.now});
 const cityRetention=createNpcCityRetention({now:world.now});
 const warmAdmissions=createNpcAdmissionBudget(world,{workerPlayers:()=>populationWorkers?.ownedPlayers?.()||[]});
 const admissionAvailable=count=>background?warmAdmissions.available(count):npcSlotsAvailable(world,count);
 const decisionFlights=createNpcDecisionFlights({world,enabled:()=>!closed&&!drain.pending&&!drain.failed&&enabled(),generation:()=>epoch,current:(p,b)=>world.players.get(p.account)===p&&brains.get(p.account)===b&&!p.leaving,onError:(error,p,b)=>{b.lastError=error.message;b.next=world.now()+2000;if(!error.status)onError(error);}});
 // Snapshot predicates are reads only. A supported observed scene requires
 // preparation even when its checkpoint has not yet been requested, or an
 // earlier generation's retirement must settle first.
 const scenePreparationRequired=p=>!!(background&&!closed&&enabled()&&p&&world.players.get(p.account)===p&&npcOccupiedField(world,p,human));
 const sceneReadiness=p=>scenePreparationRequired(p)&&!drain.pending&&!drain.failed?sceneWarming.snapshot(sceneKey(p.map,p.instanceId,p.channel)):null;
 if(background){world.npcSceneReadiness=sceneReadiness;world.npcScenePreparationRequired=scenePreparationRequired;}
 const fishingHook=createNpcFishingDirectorHook({world,enabled,closed:()=>closed,command,onError});
 // Opt-in sessions: prefer saved residents whose deterministic session is online;
 // never create a new identity only because every candidate is offline.
 const sessionsOn=npcSessionsEnabled(),sessionSeenOnline=new Map();let sessionRetireAt=0,sessionLogouts=0;
 const sessionAdmissible=list=>{if(!sessionsOn)return list;const online=list.filter(([,profile])=>npcSessionOnline(profile,Date.now()));return online.length?online:list;};
 async function leaveNpc(account,token){const p=world.players.get(account);if(p)await fishingHook.retire(p,brains.get(account)||{});return world.leave(account,token);}
 const human=p=>!!p&&!profiles.own(p.account)&&!p.leaving;
 const bot=p=>profiles.own(p.account);
 const optionalBuildDeferred=Symbol('NPC optional build deferred');
 const optionalBuildPacer=createNpcOptionalWorkPacer({now:world.now,hasHuman:()=>[...world.players.values()].some(human)});
 function optionalBuildAction(p,input){if(!optionalBuildPacer.take())throw optionalBuildDeferred;return act(p,input);}
 const questAssistance=createNpcQuestAssistance(world,{isNpc:bot,isHuman:human});
 // Interest mode uses only the explicit six-worker canonical scheduler below;
 // the older transient work pool stays disabled to avoid a second allowance.
 const backgroundWork=createNpcBackgroundWork(world,{additionalWorkers:()=>populationWorkers?.snapshot().workers||0,...(background?{maxLeases:0}:{})});
 // Presence only (see npc-background-sim.mjs): decides which public map each dormant saved bot is on.
 const simEligible=(account,p,map)=>{
  if(!npcBackgroundProfileEligible(world,account,{...p,map,channel:0}))return false;
  const row=world.data.mapRow?.(map);if(Number(row?.PeaceZone)===1&&Number(row?.PcStore)===1)return true;
  const band=nativeResidentBand(world.data,map);return !band||Number(p.level)>=band.min&&Number(p.level)<=band.max;
 };
 const backgroundSim=background?createNpcBackgroundSim({profiles:profiles.profiles,present:account=>world.players.has(account),candidateMaps:()=>[...profiles.profiles.values()].map(p=>Number(p.map)),eligible:simEligible,locked:(account,p)=>npcResidentHasAcceptedWork(world.data,p)||p.npcMerchantReservation?.phase==='held'||p.npcEquipment?.phase==='working',now:()=>world.now(),random:()=>world.random(),activeCount:()=>Math.min(1250,Math.max(250,Math.round(250+(Math.max(10,Math.min(100,Number(population())||100))-10)*1000/90))),policy:background===true?{}:background.policy}):null;
 const fieldResidency=createNpcFieldResidency(world,{capacity:capacityPolicy});let populationWorkers=null,parkAt=0;
 const cancelActor=id=>{questAssistance.cancel(id);backgroundWork.forget(typeof id==='string'?id:id?.account);};
 const approach=createNpcApproachCache(world.now);
 const residentSchedule=createNpcResidentSchedule(world.now,{joinSpacingMs:policy.joinSpacingMs??NPC_RESIDENT_POLICY.joinSpacingMs,lingerMs:policy.lingerMs??120000,startupMinMs:policy.startupMinMs??NPC_RESIDENT_POLICY.startupMinMs,startupSpanMs:policy.startupSpanMs??NPC_RESIDENT_POLICY.startupSpanMs});
 const visitors=createNpcFieldVisitors(world.now,{absenceMs:policy.fieldAbsenceMs??NPC_FIELD_VISITOR_POLICY.absenceMs});
 const actor=id=>findWorldPlayer(world,id);
 let guildRefCount=-1,guildRefs=new Set();
 const isNpcRef=ref=>{if(guildRefCount!==profiles.profiles.size){guildRefs=new Set([...profiles.profiles].map(([account,p])=>characterRef(account,p.id)));guildRefCount=profiles.profiles.size;}return guildRefs.has(ref);};
 const guildOptions={isNpc:bot,isNpcRef,brainFor:p=>brains.get(p.account)||{}};
 function privateAudience(p){const run=world.instances?.get(p.instanceId);if(!run||!['dungeon','deadFront','iceCastle'].includes(run.kind))return null;const party=world.parties?.get(p.partyId),participants=[...world.players.values()].filter(h=>human(h)&&!h.sceneTransition&&(run.kind!=='dungeon'||party?.members.includes(h.id))&&h.instanceId===run.id);return {run,participants};}
 const nativeEventParticipant=(p,run)=>['deadFront','iceCastle'].includes(run.kind)&&canonicalNpc(p)&&run.members?.has(p.id)&&run.admitted?.has(p.characterId);
 const eventTeams=createNpcEventParties(world,{isNpc:bot,act:(p,input)=>act(p,input),move:(p,to)=>toward(p,to),eligible:p=>p.profile.npcTraits?.social!=='solo',onError,attendanceHooks:{
  yieldToHuman(p){const b=brains.get(p.account),party=p.partyId&&world.parties.get(p.partyId);return !!(human(actor(b?.follow))||party?.members.some(id=>human(actor(id)))||npcPendingHumanInvite(world,p,human));},
  canAttend(p,{reserved=false}={}){const b=brains.get(p.account),party=p.partyId&&world.parties.get(p.partyId),invite=world.partyInvites?.get(p.id);if(!b||!canonicalNpc(p)||p.dead||p.leaving||p.revoked||human(actor(b.follow))||party?.members.some(id=>human(actor(id)))||invite?.expires>world.now()||npcPendingHumanInvite(world,p,human)||populationWorkers?.owns(p)||p.profile.npcTraits?.social==='solo')return false;if(reserved)return true;return !p.partyId&&!p.instanceId&&!p.commandActive&&!p.progressCommitting&&!p.sceneTransition&&!p.tradeId&&!p.pcShopOpen&&!p.path.length&&!p.attackTarget&&!p._skills?.engine.casting&&!b.objectiveFlight&&!b.refineRestore&&!fishingHook.protected(p)&&p.profile.npcEquipment?.phase!=='working';},
  capture(p){const b=brains.get(p.account);return {brain:b,taskGoal:b.taskGoal?structuredClone(b.taskGoal):null,activity:b.activity,mode:b.mode,freeplayState:b.freeplayState?structuredClone(b.freeplayState):null};},
  resume(p,intent){const b=brains.get(p.account),party=p.partyId&&world.parties.get(p.partyId);if(b!==intent?.brain||human(actor(b.follow))||party?.members.some(id=>human(actor(id)))||npcPendingHumanInvite(world,p,human))return;b.taskGoal=intent.taskGoal;b.activity=intent.activity;b.mode=intent.mode;b.freeplayState=intent.freeplayState;b.next=world.now();},
 }});
 const npcRequestNextSkill=createNpcQueueRequester({select:npcCombatSkills,cadence:npcCombatCadence,ready:npcCombatSkillReady,refusal:npcCombatRefusal,priority:(world,p,b,intent)=>npcQueuePriorityReady(world,p,b,intent)&&!eventTeams.attending(p)&&!npcPendingHumanInvite(world,p,human)});
 const groupChat=createNpcConversations({now:world.now,isNpc:bot,sameParty:(a,b,id)=>!!id&&a.partyId===id&&b.partyId===id&&world.parties.get(id)?.members.includes(a.id)&&world.parties.get(id)?.members.includes(b.id),context:(p,other)=>context(p,other,brains.get(p.account)||{},false),distance:policy.chatDistance,maxActors:2,maxTurns:4,intervalMs:7000,sceneCooldownMs:75000,
  typingDelay:(p,{text,topic,other})=>npcTypingDelay(p.profile,{text,topic,context:personaContext(p,other,brains.get(p.account)||{},false)}),
  present:(p,{text,topic,phase,other})=>{const b=brains.get(p.account),c=personaContext(p,other,b||{}),m=b?memory(b,other.id):{},maxLength=bot(other)?250-String(other?.profile?.name||'').length-2:250,facts=phase<2&&['gear','quest','trade'].includes(topic)?npcKnowledgeReply({world,player:p,requester:other,brain:b,text:topic==='trade'?'shop':topic,memory:m,maxLength}):null;const authored=npcDialogueContextFits(text,c,topic)?text:npcReply({text:topic,context:c,memory:m,random:world.random}).text;return localSpeech(npcPersonaSpeech(facts?.text||authored,{profile:p.profile,context:c,memory:m,topic,maxLength}));}});
 async function act(p,input){if(closed||!enabled()||world.players.get(p.account)!==p||p.leaving)return null;return command(p.account,{...input,token:p.token});}
 function context(p,other,b,validateCombat=true){const cls=world.data.classDef(p.profile.classIndex),preset=p.profile.equip?.presets?.[p.profile.equip?.active||0]||{},worn=Object.values(preset).map(uid=>p.profile.equip?.items?.[uid]).filter(Boolean),weapon=worn.map(i=>world.data.itemDB?.def(i.itemIndex)).find(d=>d?.slot==='weapon')?.name||'',armor=worn.map(i=>world.data.itemDB?.def(i.itemIndex)).find(d=>d?.slot==='armor')?.name||'',build=Object.entries(p.profile.stats||{}).sort((a,b)=>b[1]-a[1])[0]?.[0]?.toUpperCase()||cls?.name,q=npcQuestTalkGoal(world.data,p,b),party=p.partyId&&world.parties.get(p.partyId),invite=other&&world.partyInvites.get(other.id),map=mapFor(world,p),target=map?.monsters.get(b.target||b.farmTarget),canPull=validateCombat&&npcCanDiscussPull(world,p,b,map),run=p.instanceId&&world.instances?.get(p.instanceId),canDungeon=!!(run&&!run.closed&&run.expiresAt>world.now()&&['dungeon','deadFront','iceCastle'].includes(run.kind)&&run.members?.has(p.id)&&run.admitted?.has(p.characterId))||eventTeams.handles(p);return {weapon,armor,build,now:world.now(),name:p.profile.name,player:other?.profile.name||'friend',level:p.profile.level,playerLevel:other?.profile.level||p.profile.level,class:cls?.name||'adventurer',map:mapFor(world,p)?.name||`map ${p.map}`,quest:q?.text||'',questObjective:q?.text||'',activity:!canPull&&/\b(?:farm(?:ing)?|grind(?:ing)?|pull(?:s|ing)?)\b/i.test(b.activity||'')?'checking the next objective':b.activity||'getting ready',task:b.taskGoal?.kind==='farm'&&!canPull?'checking native objectives':b.taskGoal?.kind||'',enemy:target&&!target.dead?target.name:'',canPull,canDungeon,isParty:!!party,partyCount:party?.members.length||0,partyRole:party?.leader===p.id?'leader':'member',freeSlots:party?Math.max(0,7-party.members.length):6,solo:!npcWantsParty(p),hasShop:!!p.pcShopOpen,partyInvitePending:!!invite&&invite.party===p.partyId&&invite.expires>world.now(),hpPercent:p.maxHp?Math.round(p.hp/p.maxHp*100):0,mpPercent:(p.stats?.maxMp||p.maxMp)?Math.round(p.mp/(p.stats?.maxMp||p.maxMp)*100):0,style:(p.profile.npcSeed?.slot||0)%4,mood:world.now()<(b.frustratedUntil||0)?'frustrated':p.profile.npcTraits?.chat};}
 function memory(b,id){if(!b.memory.has(id)&&b.memory.size>=24)b.memory.delete(b.memory.keys().next().value);if(!b.memory.has(id))b.memory.set(id,{});return b.memory.get(id);}
 function personaContext(p,other,b,validateCombat=true){const c=context(p,other,b,validateCombat),threatened=[...(mapFor(world,p)?.monsters.values()||[])].some(m=>!m.dead&&m.targetId===p.id&&distance(p,m)<15);return {...c,dead:!!p.dead,danger:threatened,inCombat:!!p._skills?.engine.casting||!!p.attackTarget,busy:!!p.commandActive||p.profile.npcEquipment?.phase==='working',recovering:!p.dead&&c.hpPercent<30};}
 const localSpeech=text=>npcLocalizeText(text,language());
 async function say(p,b,text,{channel='normal',targetName,localized=false}={}){if(world.now()<b.chatReady)return;b.chatReady=world.now()+2500;if(!localized)text=localSpeech(text);if(channel==='messenger')return act(p,{type:'messenger',operation:'send',text:text.slice(0,60),targetName});return act(p,{type:'chat',text,channel,...(targetName?{targetName}:{})});}
 async function generous(p,b){const now=world.now();if(now<(b.giftAt||0))return false;b.giftAt=now+30000;const gift=await npcGenerosityStep({world,player:p,brain:b,act,isHuman:human,requested:true});if(gift.handled&&gift.text)await say(p,b,gift.text);return gift.handled;}
 function ambientSpeech(p,other,b,topic,c=personaContext(p,other,b)){
  const m=memory(b,other.id),persona=npcPersona(p.profile);delete b.offerCandidate;
  if(['bad','mid'].includes(persona.knowledgeTier)&&world.now()>=(b.helpAt||0)){
   const knowledge=npcKnowledgeReply({world,player:p,requester:other,brain:b,text:'quest',memory:{}}),ask=npcPersonaHelpQuestion(p.profile,{context:{...c,helpNeed:knowledge?.helpNeed}});
   if(ask){b.helpAt=world.now()+180000;b.helpCandidate={humanId:other.id,questId:knowledge.helpNeed.questId,text:localSpeech(ask)};return ask;}
  }
  const reply=npcReply({text:topic,context:c,memory:m,random:world.random}),text=npcPersonaSpeech(reply.text,{profile:p.profile,context:c,memory:m,topic}),offer=reply.offer||npcDialogueOffer(reply.text,reply.topic||topic);
  if(offer)b.offerCandidate={humanId:other.id,offer,text:localSpeech(text)};
  return text;
 }
 async function deliverAmbient(p,other,b,topic,c){
  const since=world.sequence,text=ambientSpeech(p,other,b,topic,c),spoken=await say(p,b,text),m=memory(b,other.id);
  const delivered=value=>spoken?.events?.some(e=>['chat','messenger'].includes(e.type)&&e.actorId===p.id&&e.text===value&&e.sequence>since&&e.channel==='normal'&&e.recipients?.includes(other.id))===true;
  if(b.helpCandidate?.humanId===other.id&&delivered(b.helpCandidate.text)){
   m.questHelpOffer={questId:b.helpCandidate.questId,until:world.now()+45000};
   npcRememberConversationOffer({world,player:p,requester:other,memory:m,offer:{type:'quest-help',questId:b.helpCandidate.questId},channel:'normal',delivered:true});
  }else if(b.offerCandidate?.humanId===other.id)npcRememberConversationOffer({world,player:p,requester:other,memory:m,offer:b.offerCandidate.offer,channel:'normal',delivered:delivered(b.offerCandidate.text)});
  delete b.helpCandidate;delete b.offerCandidate;
 }
 async function departNpcWave(rows,onDetached){
  if(!Array.isArray(rows)||!rows.length||rows.length>64||typeof onDetached!=='function')throw Object.assign(Error('Invalid bounded NPC departure caller'),{status:409});
  const seen=new Set(),input=rows.map(row=>({...row}));
  const current=row=>{const p=row.player;return p&&world.players.get(p.account)===p&&p.token===row.token&&profiles.own(p.account)&&p.profile.authority==='server'&&p.profile.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.characterId;};
  const refusal=()=>Object.assign(Error('NPC departure participant changed; retain exact caller custody.'),{status:409});
  for(const row of input){if(!current(row)||seen.has(row.player.account))throw refusal();seen.add(row.player.account);}
  const acknowledge=async row=>{if(world.players.has(row.player.account)||row.player.token!==row.token)throw refusal();await onDetached(row);};
  const ordinary=async row=>{
   if(!current(row)||row.player.commandActive||row.player.progressCommitting||row.player.tradeCommitting||row.player.sceneTransition||row.player.pendingDisconnect||row.player.disconnectRetry)throw refusal();
   await world.leave(row.player.account,row.token);await acknowledge(row);
  };
  const batch=[],fallback=[];
  for(const row of input){const p=row.player;(typeof world.leaveNpcWave!=='function'||p.pcShopOpen||fishingHook.protected(p)||p.instanceId||p.tradeId||p.charTradeId||p.leaving||p.revoked||p.commandActive||p.progressCommitting||p.tradeCommitting||p.sceneTransition||p.pendingDisconnect||p.disconnectRetry?fallback:batch).push(row);}
  if(batch.length){
   try{await world.leaveNpcWave(batch.map(({player,token})=>({player,token})));}
   catch(error){if(error.status!==409)throw error;for(const row of batch)await ordinary(row);batch.length=0;}
   for(const row of batch)await acknowledge(row);
  }
  for(const row of fallback)await ordinary(row);
 }
 function availableScenes(){const out=new Map();for(const p of world.players.values())if(npcOccupiedField(world,p,human)){const key=sceneKey(p.map,p.instanceId,p.channel);if(!out.has(key))out.set(key,[]);out.get(key).push(p)}return out;}
 function registerBrain(p,{slot=p.profile.npcSeed?.slot||0,saved=true,desiredChannel=0,seedScene=sceneKey(p.map,p.instanceId,p.channel)}={}){
  if(brains.has(p.account))return brains.get(p.account);
  p.npcPlayer=true;p.permissions={role:'player',capabilities:[]};p.gmAuthorized=false;
  p.profile.npcSeed={...p.profile.npcSeed,homeMap:p.profile.npcSeed?.homeMap??p.map,map:p.map,channel:p.channel||0,slot};
  p.profile.npcTraits||={policy:'ENGINE-CHOSEN',social:'solo'};p.profile.npcTraits.chat||=['relaxed','quiet','playful','competitive'][slot%4];
  p.profile.npcLongTermGoal||={version:1,policy:'ENGINE-CHOSEN objective; ordinary native earned progress',kind:'progress',targetLevel:world.data.maxLevel};world.changed(p);
  const phase=npcConversationPhase(slot),b={next:0,chatReady:0,ambient:world.now()+policy.ambientMs+phase*7000,memory:new Map(),mode:'roam',home:{x:p.x,z:p.z},homeScene:sceneKey(p.map,p.instanceId,p.channel),queue:[],activity:'exploring',learnAt:0,questAt:0,socialAt:world.now()+15000+phase*11000,supportAt:0,lastError:null,desiredChannel,channelStarted:world.now(),seedScene,...residentSchedule.startup(p.profile,{saved})};
  brains.set(p.account,b);return b;
 }
 const admissionFence=capacityPolicy?createNpcAdmissionFence({world,profiles,actorCap:capacityPolicy.actorCap,enabled}):null;
 const foregroundIds=new Set();
 const interestMandatory=p=>{const b=brains.get(p.account)||{},party=p.partyId&&world.parties.get(p.partyId);return !!(decisionFlights.owns(p)||populationWorkers?.inFlight(p)||p.instanceId||eventTeams.retains(p)||fishingHook.protected(p)||b.queue?.length||b.objectiveFlight||b.refineRestore||p.profile.npcEquipment?.phase==='working'||party?.members.some(id=>human(actor(id)))||human(actor(b.follow))||npcPendingHumanInvite(world,p,human));};
 world.npcHumanSlotProtected=interestMandatory;
 const snapshotInterest=viewer=>capacityPolicy&&!closed&&enabled()?npcSnapshotInterest(world,viewer,{events:world.snapshotEvents(viewer),mandatory:interestMandatory}):null;
 if(capacityPolicy)world.npcSnapshotInterest=snapshotInterest;
 const foregroundRequested=p=>foregroundIds.has(p?.id)&&world.players.get(p.account)===p;
 function refreshForegroundInterest(){foregroundIds.clear();if(!capacityPolicy||closed||!enabled())return;for(const viewer of world.players.values())if(human(viewer))for(const id of snapshotInterest(viewer)||[])foregroundIds.add(id);}
 function ensurePopulationWorkers(){if(populationWorkers)return populationWorkers;
  populationWorkers=createNpcBackgroundPopulation({world,profiles,enabled:()=>!closed&&!drain.pending&&!drain.failed&&enabled(),generation:()=>epoch,admissionBudget:warmAdmissions,optionalAdmissionAllowed:()=>!world.npcBackpressure?.admissionsPaused?.()/*LANE1-PERF backpressure hook*/&&!sceneWarming.pending()&&!world.npcHumanReservations?.size&&world.npcPreparationPending!==true&&(!world.npcOptionalWorkAllowed||world.npcOptionalWorkAllowed()===true),eligible:(profile,{account})=>!background||world.data.fieldParkingAllowed?.(profile.map)===true&&Number(backgroundSim?.locate(account))===Number(profile.map),admissionFence,isOccupied:p=>[...world.players.values()].some(h=>human(h)&&sameScene(h,p)),
   shouldHandoff:p=>{const b=brains.get(p.account)||{},party=p.partyId&&world.parties.get(p.partyId);return !!(party?.members.some(id=>human(actor(id)))||human(actor(b.follow))||npcPendingHumanInvite(world,p,human));},
   priority:p=>{const b=brains.get(p.account)||{},party=p.partyId&&world.parties.get(p.partyId);return !!(party?.members.some(id=>human(actor(id)))||human(actor(b.follow))||npcPendingHumanInvite(world,p,human)||b.queue?.length||foregroundRequested(p)&&(p.attackTarget||p._skills?.engine.casting||p.pvpLastHit?.by));},
   additionalWorkers:()=>backgroundWork.snapshot().active,
   additionalActors:()=>capacityPolicy?[...brains.keys()].map(id=>world.players.get(id)).filter(p=>p&&!p.leaving&&!populationWorkers?.owns(p)):[],
   isProtected:p=>{const b=brains.get(p.account)||{},party=p.partyId&&world.parties.get(p.partyId);return !!(fishingHook.protected(p)||p.commandActive||p.progressCommitting||p.sceneTransition||b.objectiveFlight||b.refineRestore||p.profile.npcEquipment?.phase==='working'||p.tradeId||p.pcShopOpen||b.queue?.length||party?.members.some(id=>human(actor(id)))||human(actor(b.follow))||npcPendingHumanInvite(world,p,human)||eventTeams.retains(p));},
   admitScene:async({map,channel=0,account,profile,actor})=>{if(background)return fieldResidency.acquireWorker(map,channel,{account,profile,actor});if(capacityPolicy)return fieldResidency.acquirePublic(map,channel,{account,profile,actor});const key=sceneKey(map,null,channel);if(world.data.fieldParkingAllowed?.(map)===true)return fieldResidency.acquire(map,channel);if(world.maps.has(key))return {ok:true,release:world.acquireSceneLease(map,null,channel)};return {ok:false,reason:'Native scripted field is not yet resident'};},
   leaveWave:capacityPolicy?departNpcWave:null,
   beforeLeave:async p=>{await fishingHook.retire(p,brains.get(p.account)||{});},
   onJoin:p=>{const b=registerBrain(p);b.sceneOccupied=false;},
   onLeave:(p,{reason})=>{if(reason==='occupied'||reason==='human-protected'||reason==='foreground-requested'){const b=brains.get(p.account);if(b)b.sceneOccupied=[...world.players.values()].some(h=>human(h)&&sameScene(h,p));if(b?.sceneOccupied)visitors.joined(sceneKey(p.map,p.instanceId,p.channel),p.account);return;}cancelActor(p.account);brains.delete(p.account);residentSchedule.forget(p.account);visitors.forget(p.account);groupChat.cancelPlayer(p);},
   ready:p=>{const b=brains.get(p.account);return !!b&&(world.now()>=b.next||b.queue?.some(q=>world.now()>=(q.due||0))||!!npcPendingHumanInvite(world,p,human));},
   step:async p=>{const b=brains.get(p.account),token=p.token;if(!b)return;if(!capacityPolicy&&!background){await think(p,b);return;}try{await think(p,b);if(b.objectiveFlight)await b.objectiveFlight;if(world.players.get(p.account)===p&&p.token===token&&brains.get(p.account)===b)b.lastError=null;}catch(error){if(world.players.get(p.account)===p&&p.token===token&&brains.get(p.account)===b){b.lastError=error.message;b.next=world.now()+2000;if(!error.status)onError(error);}if(background)throw error;}},onError},{tickMs:policy.backgroundTickMs??150,capacity:capacityPolicy,...(background?{boundedInterest:true}:{})});return populationWorkers;
 }
 // Interest-managed mode: a bot with no human in its scene has no witness. Only genuine in-flight transactions and human
 // companions keep it; idle-time protections (combat, chat, shops, death) lapse. Multi-step work (refinement, equipment
 // services, fishing, queued actions) gets a bounded grace to finish through the ordinary director, then departs normally.
 const orphanSince=new WeakMap();
 function interestOrphanProtected(p,b,{nearby,pendingHuman,pendingInvite,humanParty,leader}){
  if(!background||nearby){orphanSince.delete(b);delete b.orphanFinishing;return null;}
  const at=world.now();if(!orphanSince.has(b))orphanSince.set(b,at);
  if(pendingHuman||pendingInvite||humanParty||leader&&human(leader)||p.instanceId||eventTeams.retains(p)||world.data.requiresInstance?.(p.map)){delete b.orphanFinishing;return true;}
  if(p.commandActive||p.progressCommitting||p.tradeCommitting||p.sceneTransition||p.pendingDisconnect||p.disconnectRetry){delete b.orphanFinishing;return true;}
  const unfinished=!!(b.objectiveFlight||b.refineRestore||p.profile.npcEquipment?.phase==='working'||fishingHook.protected(p)||b.queue?.length);
  b.orphanFinishing=unfinished&&at-orphanSince.get(b)<(policy.orphanGraceMs??45000);
  return b.orphanFinishing;
 }
 // Interest-managed mode: the reusable cohort for a scene is the set of dormant bots the presence simulation currently
 // places on this map. A bot simulated elsewhere stays dormant here; one simulated on this map is relocated by spawn().
 function simulatedResidents(anchor,choice,base,cohort){
  if(!backgroundSim||anchor.instanceId||(anchor.channel||0)!==0||isDkChannel(anchor.channel)||world.data.requiresInstance?.(anchor.map))return base;
  const here=base.filter(([account])=>Number(backgroundSim.locate(account))===Number(anchor.map)),known=new Set(here.map(([account])=>account)),extra=[];
  for(const account of backgroundSim.residents(anchor.map)){const p=profiles.profiles.get(account);if(known.has(account)||!p||world.players.has(account)||!p.npcSeed?.stock||!simEligible(account,p,anchor.map))continue;const row=[account,p];if(cohort(row))extra.push(row);}
  const key=account=>{let n=2166136261;for(const c of account)n=Math.imul(n^c.charCodeAt(0),16777619)>>>0;return n;};
  extra.sort((a,b)=>Number(b[1].classIndex===choice.classIndex)-Number(a[1].classIndex===choice.classIndex)||key(a[0])-key(b[0]));
  return [...here,...extra];
 }
 async function spawn(anchor,slot){
  // Private instances only admit already-connected party members through their normal entry. Never spawn through admission checks.
  if(anchor.instanceId||isDkChannel(anchor.channel)||world.data.requiresInstance?.(anchor.map))return;
  const map=mapFor(world,anchor);if(!map)return;const offset=slot*2*Math.PI/policy.perScene;let at;
  let choice=npcPopulationChoice(world.data,anchor.profile.level,rosterSerial,{map,anchor,quests:world.data.progression?.quests,activities:npcNativeActivities(world.data,map)});
  // Reconcile durable profiles before reserving an identity. A recovered
  // profile write must prevent a second activation even if its roster write failed.
  if(residentRoster)await residentRoster.syncEarned(profiles.profiles);
  const friendNames=new Set([...world.players.values()].filter(p=>human(p)&&sameScene(p,anchor)).flatMap(p=>p.profile.npcFriends||[]).map(n=>String(n).toLowerCase())),cohort=([,profile])=>npcFieldCohortEligible(world.data,profile,anchor,choice,{friends:friendNames}),reusable=sessionAdmissible(simulatedResidents(anchor,choice,npcReusableResidents({data:world.data,profiles:profiles.profiles,players:world.players,anchor,choice,slot}).filter(cohort),cohort).filter(([account])=>!warmAdmissions.has(account)));
  // Prefer an existing friend, then a genuinely stocked local resident. This
  // changes admission order only; no inventory/location/level is manufactured.
  const saved=reusable.find(([,profile])=>friendNames.has(String(profile.name).toLowerCase()))||await npcPreferredCityMerchant(world,reusable,{map:anchor.map,channel:anchor.channel||0,allowQuestPause:true,yieldTurn})||(background?reusable.slice(0,40):reusable).find(([,profile])=>npcMerchantResidentPriority(world,profile,{map:anchor.map,channel:anchor.channel||0,allowQuestPause:true}))||visitors.select(sceneKey(anchor.map,anchor.instanceId,anchor.channel),{candidates:reusable,friends:friendNames,canCreate:profiles.profiles.size<NPC_PROFILE_LIMIT,slot});
  const identity=!saved&&profiles.profiles.size<NPC_PROFILE_LIMIT&&residentRoster?await residentRoster.candidate(anchor.map,{classIndex:choice.classIndex,levelMin:choice.levelBand?.min??choice.level,levelMax:choice.levelBand?.max??choice.level,excludeNames:[...profiles.profiles.values(),...[...world.players.values()].map(p=>p.profile)].map(p=>p.name)}):null;
  let admissionSlot=null;
  // Interest mode represents a fixed saved roster. A lower automatic cohort
  // must not mint a new identity merely because its current map has no
  // matching simulated resident; a full roster has no vacant identity to bind.
  if(background&&residentRoster&&!saved&&!identity)return;
  // A simulated bot saved on another map is moved onto this one (ordinary saved write) before its normal join.
  const relocating=!!saved&&Number(saved[1].map)!==Number(anchor.map);
  try{
  if(identity)choice={...choice,level:identity.level,traits:identity.traits};
  const {classIndex,level,traits}=choice,cls=world.data.classDef(classIndex);if(!cls)return;
  // Never recalculate or overwrite a saved actor's location. New residents
  // prefer reachable actual quest/creature work areas rather than the portal.
  if(saved&&!relocating)at=saved[1].pos;
  else{
   const placement=npcNativeResidentSpawn(world.data,map,{anchor,choice:relocating?{...choice,level:saved[1].level,classIndex:saved[1].classIndex,goal:undefined}:choice,serial:rosterSerial,occupied:[...world.players.values()]});
   if(placement)at=placement.at;
  }
  if(!saved&&!at&&choice.goal){
   // ENGINE-CHOSEN hub staging uses actual local teleporter/officer/giver
   // placements, with a native path from the occupied human area.
   for(const service of npcNativeActivityAnchors(world.data,map,{goal:choice.goal}).slice(0,2)){
    if(distance(anchor,service.at)>64||!npcReachableApproach(map,anchor,service.at,12))continue;
    const radius=4+slot%4,candidate=map.nearest(service.at.x+Math.cos(offset)*radius,service.at.z+Math.sin(offset)*radius);
    if(candidate&&![...world.players.values()].some(p=>sameScene(p,anchor)&&distance(p,candidate)<3.5)&&npcReachableApproach(map,anchor,candidate,1)){at=candidate;break;}
   }
  }
  if((!saved||relocating)&&!at)for(const radius of [8+slot*2,6]){const candidate=map.nearest(anchor.x+Math.cos(offset)*radius,anchor.z+Math.sin(offset)*radius);if(candidate&&![...world.players.values()].some(p=>sameScene(p,anchor)&&distance(p,candidate)<3.5)&&npcReachableApproach(map,anchor,candidate,1)){at=candidate;break;}}
  if(!at)return;
  // ENGINE-CHOSEN population draws varied levels from the native local spawn/quest band. Earned profiles are never relevelled.
  // Point budgets mirror SharedWorld.grantProgress (5 stat, 1 skill per level).
  const used=new Set([...profiles.profiles.values(),...[...world.players.values()].map(p=>p.profile)].map(p=>p.name));
  const profile={id:'c'+randomUUID().replaceAll('-',''),authority:'server',npcPlayer:true,...(identity?{npcRosterId:identity.npcRosterId,...(['generated-v1','generated-v2'].includes(identity.npcNameSource)?{npcNameSource:identity.npcNameSource}:{})}:{npcNameSource:'generated-v2'}),npcSeed:{map:anchor.map,homeMap:anchor.map,channel:anchor.channel||0,slot,...(choice.levelBand?{levelBand:choice.levelBand}:{}),...(choice.goal?{initialGoal:choice.goal}:{})},npcTraits:traits,name:identity?.name||npcUsername(rosterSerial,used),nameColor:'white',classIndex,className:cls.name,starterSkillPending:true,
   level,exp:0,dil:0,...npcPointBudget(world.data,level),stats:structuredClone(cls.stats.base),hp:null,mp:null,map:anchor.map,pos:{x:at.x,z:at.z,dirDeg:0},inventory:[],equipment:{},hotbar:[],skills:{},created:world.now(),lastPlayed:world.now(),kills:0,deaths:0,playSeconds:0};
  // Preserve legacy prototype profiles; new populated actors use the tested build policy and permanent earned progress.
  if(!saved&&profiles.profiles.size>=NPC_PROFILE_LIMIT){const key=sceneKey(anchor.map,anchor.instanceId,anchor.channel);sceneRetry.set(key,world.now()+60000);rosterBlocked.set(key,'Persistent NPC roster is full; earned profiles are preserved.');return;}
  if(!saved)seedNpcStartingStock(profile,world.data,{serial:rosterSerial,now:world.now,random:world.random,traits});
  rosterBlocked.delete(sceneKey(anchor.map,anchor.instanceId,anchor.channel));
  if(relocating){const old=saved[1],{initialGoal:unusedGoal,...seed}=old.npcSeed||{},moved={...structuredClone(old),map:anchor.map,channel:anchor.channel||0,pos:{x:at.x,z:at.z,dirDeg:0},npcSeed:{...seed,map:anchor.map,channel:anchor.channel||0}};delete moved.npcRoutine;await profiles.save(saved[0],old.id,moved);saved[1]=profiles.profiles.get(saved[0])||moved;}
  const account=saved?.[0]||await profiles.add(profile),stamp=epoch,character=saved?.[1]||profile;
  const releaseWarmAdmission=background?warmAdmissions.reserve([account]):null;if(background&&!releaseWarmAdmission)return;
  try{
  if(capacityPolicy){admissionSlot=admissionFence.reserve(account,character.id);if(!admissionSlot||!admissionSlot.valid())return;}
  await (world.joinNpc||world.join).call(world,account,character.id);const p=world.players.get(account);p.npcPlayer=true;p.permissions={role:'player',capabilities:[]};p.gmAuthorized=false;
  if(stamp!==epoch||closed||!enabled()){await leaveNpc(account,p.token);return;}
  p.profile.npcSeed={...p.profile.npcSeed,homeMap:p.profile.npcSeed.homeMap??p.profile.npcSeed.map,map:p.map,channel:p.channel||0,slot};world.changed(p);
  p.profile.npcTraits.chat||=['relaxed','quiet','playful','competitive'][slot%4];world.changed(p);
  // Two ordinary initial build transactions; the existing train decisions
  // finish allocation/equipment instead of bursting eighteen awaited saves.
  if(!saved)for(let n=0;n<2;n++){if(!await npcBuildStep({world,player:p,act:input=>act(p,input)}))break;}
  registerBrain(p,{slot,saved:!!saved,desiredChannel:anchor.channel||0,seedScene:sceneKey(anchor.map,anchor.instanceId,anchor.channel)});residentSchedule.joined(sceneKey(anchor.map,anchor.instanceId,anchor.channel));rosterSerial++;
  visitors.joined(sceneKey(p.map,p.instanceId,p.channel),account);backgroundSim?.place(account,p.map);
  if(identity){try{await world.persist(p);await residentRoster.bind(identity.npcRosterId,{account,profileId:p.profile.id,name:p.profile.name,map:p.map,level:p.profile.level,classIndex:p.profile.classIndex,traits:p.profile.npcTraits,activity:p.profile.npcRoutine});}catch(error){brains.get(account).lastError=error.message;onError(error);}}
  }finally{releaseWarmAdmission?.();}
  }finally{admissionSlot?.release();if(identity)residentRoster.release(identity.npcRosterId);}
 }
 // Fill only the occupied scene in bounded waves after the human is admitted.
 // One native upper-bound/automatic target for both preload and reconciliation.
 const effectiveSceneDensity=anchor=>{const native=npcSceneDensity(world,anchor,policy),scaled=npcScaledDensity(native,population(),background?70:42),desired=Math.max(npcCityResidentTarget({map:anchor.map,native,interest:!!background,optionalWorkAllowed:world.npcOptionalWorkAllowed?.(),scaled}),eventTeams.densityFor(anchor));return background?Math.min(policy.perScene,desired):desired;};
 // primeScene is awaited by preload; unrelated scenes keep running meanwhile.
 async function primeOccupiedScene(anchor,update=()=>{}){
  const preparationEpoch=epoch,key=sceneKey(anchor.map,anchor.instanceId,anchor.channel);
  const primeStarted=performance.now(),timing={selectionMs:0,admissionMs:0,registrationMs:0,fallbackMs:0,waves:0};
  if(!background||closed||!enabled()||!npcOccupiedField(world,anchor,human)||world.players.get(anchor.account)!==anchor)return {complete:false,target:0,actors:0};
  const stillHere=()=>epoch===preparationEpoch&&!closed&&!drain.pending&&enabled()&&world.players.get(anchor.account)===anchor&&!anchor.leaving&&!anchor.sceneTransition&&sceneKey(anchor.map,anchor.instanceId,anchor.channel)===key;
  await profiles.load();
  if(!residentRoster&&dormantRoster)residentRoster=typeof dormantRoster==='function'?await dormantRoster():dormantRoster;
  if(residentRoster)await residentRoster.syncEarned(profiles.profiles);
  if(!stillHere())return {complete:false,ceiling:0,eligible:0,target:0,actors:0,reason:'scene-changed'};
  // Exact observed workers settle accepted action + latest durable checkpoint
  // before this same actor contributes to prepared foreground readiness.
  if(populationWorkers)for(const worker of populationWorkers.ownedPlayers?.()||[]){if(sceneKey(worker.map,worker.instanceId,worker.channel)!==key)continue;const handed=await populationWorkers.handoffCurrent(worker,{requested:()=>stillHere()&&sceneKey(worker.map,worker.instanceId,worker.channel)===key});if(!handed)return {complete:false,ceiling:0,eligible:0,target:0,actors:0,reason:'native-admission'};if(!stillHere())return {complete:false,ceiling:0,eligible:0,target:0,actors:0,reason:'scene-changed'};}
  if(!rosterSerial)rosterSerial=profiles.profiles.size;
  backgroundSim?.tick();
  visitors.observe(availableScenes().keys());
  const map=mapFor(world,anchor);
  if(!map)return {complete:false,target:0,actors:0};
  const activities=npcNativeActivities(world.data,map);
  const localProfiles=[...profiles.profiles].filter(([account,profile])=>Number(profile.map)===Number(anchor.map)&&profile.npcSeed?.stock&&!world.players.has(account));
  const desired=effectiveSceneDensity(anchor);
  const ceiling=Math.min(policy.perScene,desired),friendNames=new Set([...world.players.values()].filter(p=>human(p)&&sameScene(p,anchor)).flatMap(p=>p.profile.npcFriends||[]).map(n=>String(n).toLowerCase()));
  const count=()=>[...brains].filter(([account])=>{const p=world.players.get(account);return p&&!populationWorkers?.owns(p)&&sceneKey(p.map,p.instanceId,p.channel)===key;}).length;
  // Reuse the same native eligibility choices for census and admission. Count
  // actual current-map residents only; a presence intention never teleports a
  // saved character or manufactures identities to fill a scene ceiling.
  const nativeTown=Number(world.data.mapRow?.(anchor.map)?.PeaceZone)===1&&Number(world.data.mapRow?.(anchor.map)?.PcStore)===1;
  // A sampled NEW character's quest preference is not a restriction on an
  // existing native farm/service resident. Saved authored goals are still
  // validated by npcResidentMatches; field cohorts retain native level bands.
  const choices=Array.from({length:ceiling},(_,slot)=>{const choice=npcPopulationChoice(world.data,anchor.profile.level,rosterSerial+slot,{map,anchor,quests:world.data.progression?.quests,activities});return {...choice,goal:undefined,...(nativeTown?{levelBand:null}:{})};});
  // Keep genuine premium merchants from being hidden by the random dormant
  // cohort before admission even sees them. These replace up to three dormant
  // hash picks; current actors, ordinary eligibility and capacity stay intact.
  if(backgroundSim&&anchor.map===150&&!anchor.channel&&choices.length){
   const choice=choices[0],merchants=[],candidates=npcReusableResidents({data:world.data,profiles:profiles.profiles,players:world.players,anchor,choice,slot:0,candidates:localProfiles}).filter(([,profile])=>npcFieldCohortEligible(world.data,profile,anchor,choice,{friends:friendNames}));
   for(let i=0;i<3;i++){const row=await npcPreferredCityMerchant(world,candidates.filter(([account])=>!merchants.includes(account)),{map:150,channel:0,allowQuestPause:true,yieldTurn});if(!row||!stillHere())break;merchants.push(row[0]);}
   if(stillHere())backgroundSim.prefer(merchants);
  }
  const eligibleAccounts=new Set([...brains.keys()].filter(account=>{const p=world.players.get(account);return p&&sceneKey(p.map,p.instanceId,p.channel)===key;}));
  for(const [slot,choice]of choices.entries())for(const [account]of npcReusableResidents({data:world.data,profiles:profiles.profiles,players:world.players,anchor,choice,slot,candidates:localProfiles}).filter(([,profile])=>npcFieldCohortEligible(world.data,profile,anchor,choice,{friends:friendNames})))if(!backgroundSim||Number(backgroundSim.locate(account))===Number(anchor.map))eligibleAccounts.add(account);
  const eligible=eligibleAccounts.size,target=Math.min(ceiling,eligible),targetStable=()=>effectiveSceneDensity(anchor)===ceiling;
  update({ceiling,eligible,target,active:count()});
  const admit=row=>{const p=world.players.get(row.account);if(!p||!profiles.own(row.account)||sceneKey(p.map,p.instanceId,p.channel)!==key)return false;
   p.profile.npcSeed={...p.profile.npcSeed,homeMap:p.profile.npcSeed?.homeMap??p.profile.npcSeed?.map,map:p.map,channel:p.channel||0,slot:row.slot};world.changed(p);
   p.profile.npcTraits.chat||=['relaxed','quiet','playful','competitive'][row.slot%4];world.changed(p);
   registerBrain(p,{slot:row.slot,saved:true,desiredChannel:p.channel||0,seedScene:key});visitors.joined(key,row.account);backgroundSim?.place(row.account,p.map);rosterSerial++;return true;};
  while(count()<target&&brains.size<policy.total&&admissionAvailable()){
   if(!stillHere()||!targetStable())break;
   const wave=[],reserved=new Set(),start=count();
   const selectionStarted=performance.now();
   for(let slot=start;slot<target&&wave.length<8&&brains.size+wave.length<policy.total;slot++){
    const choice=choices[slot];
    const cohort=([,profile])=>npcFieldCohortEligible(world.data,profile,anchor,choice,{friends:friendNames});
    const reusable=npcReusableResidents({data:world.data,profiles:profiles.profiles,players:world.players,anchor,choice,slot,candidates:localProfiles}).filter(cohort)
     .filter(([account])=>!reserved.has(account)&&!warmAdmissions.has(account)&&(!backgroundSim||Number(backgroundSim.locate(account))===Number(anchor.map)));
    const saved=reusable.find(([,profile])=>friendNames.has(String(profile.name).toLowerCase()))||await npcPreferredCityMerchant(world,reusable,{map:anchor.map,channel:anchor.channel||0,allowQuestPause:true,yieldTurn})||reusable.slice(0,40).find(([,profile])=>npcMerchantResidentPriority(world,profile,{map:anchor.map,channel:anchor.channel||0,allowQuestPause:true}))||visitors.select(key,{candidates:reusable,friends:friendNames,canCreate:false,slot});
    if(!saved)continue;
    reserved.add(saved[0]);wave.push({account:saved[0],characterId:saved[1].id,slot});
    if(wave.length%4===0){await yieldTurn();if(!stillHere())break;}
   }
   timing.selectionMs+=performance.now()-selectionStarted;
   if(!stillHere()||!targetStable())break;
   while(wave.length&&!admissionAvailable(wave.length))wave.pop();
   if(!wave.length)break;
   const releaseWarmAdmission=warmAdmissions.reserve(wave.map(row=>row.account));if(!releaseWarmAdmission)break;
   const admissionStarted=performance.now();
   try{await world.npcJoinWave(wave.map(({account,characterId})=>({account,characterId})));}
   catch(error){for(const row of wave)admit(row);update({active:count()});throw error;}
   finally{releaseWarmAdmission();}
   timing.admissionMs+=performance.now()-admissionStarted;timing.waves++;
   const registrationStarted=performance.now();for(const row of wave)admit(row);timing.registrationMs+=performance.now()-registrationStarted;update({active:count()});
   residentSchedule.joined(key);
   // Give existing players' requests room between durable admission waves.
   if(count()<target&&stillHere())await pause(40);
  }
  // Rare maps without enough saved residents still finish their normal,
  // validated admissions before the human's join response is released.
  const fallbackStarted=performance.now();
  while(count()<target&&brains.size<policy.total&&admissionAvailable()&&stillHere()&&targetStable()){
   const before=count();await spawn(anchor,before);update({active:count()});if(count()===before)break;
  }
  timing.fallbackMs=performance.now()-fallbackStarted;
  lastPrime={scene:key,durationMs:Math.round(performance.now()-primeStarted),selectionMs:Math.round(timing.selectionMs),admissionMs:Math.round(timing.admissionMs),registrationMs:Math.round(timing.registrationMs),fallbackMs:Math.round(timing.fallbackMs),waves:timing.waves,actors:count(),ceiling,eligible,target};
  if(stillHere()&&!targetStable()){const currentCeiling=effectiveSceneDensity(anchor);return {complete:false,ceiling:currentCeiling,eligible,target:Math.min(currentCeiling,eligible),actors:count(),reason:'target-changed'};}
  const complete=stillHere()&&count()>=target;
  return {complete,ceiling,eligible,target,actors:count(),...(!complete?{reason:!stillHere()?'scene-changed':!admissionAvailable()?'capacity':'native-admission'}:{})};
 }
 async function reconcile(){const retiring=[];refreshForegroundInterest();const scenes=availableScenes(),humans=[...world.players.values()].filter(p=>human(p)&&!p.dead&&!p.sceneTransition),talking=new Set(groupChat.snapshot().flatMap(s=>s.actors));visitors.observe(scenes.keys());if(!scenes.has(150))backgroundSim?.prefer([]);
  // Native/passive scene changes can publish before an API post-action prime.
  // Request at most one new observed-scene flight per cycle; do not await it
  // globally or automatically retry an explicit incomplete/save refusal.
  if(background&&!drain.pending&&!drain.failed)for(const [key,anchors]of scenes){if(sceneWarming.warming(key))continue;const state=sceneWarming.snapshot(key),anchor=anchors.find(scenePreparationRequired);if(state?.failed==='target-changed'&&state.targetRetries>=3)continue;if(state&&state.failed!=='target-changed'&&!(state.phase==='ready'&&anchor&&state.ceiling!==effectiveSceneDensity(anchor)))continue;if(anchor){void primeScene(anchor).catch(onError);break;}}
  for(const [id,b]of brains){const p=world.players.get(id);if(!p){cancelActor(id);brains.delete(id);continue}if(decisionFlights.owns(p)||(capacityPolicy||background)&&populationWorkers?.inFlight(p))continue;p.lastSeen=world.now();const leader=b.follow&&actor(b.follow);const nearby=humans.some(q=>sameScene(p,q));if(nearby)visitors.joined(sceneKey(p.map,p.instanceId,p.channel),id);
   if(background&&populationWorkers?.owns(p)){visitors.retirement(id,{present:nearby,protected:true});continue;}
   const humanParty=p.partyId&&world.parties.get(p.partyId)?.members.some(pid=>{const q=actor(pid);return q&&human(q)});
   if(b.desiredChannel&&world.now()-b.channelStarted>30000){sceneRetry.set(b.seedScene,world.now()+60000);await leaveNpc(id,p.token);cancelActor(id);brains.delete(id);continue;}
   const inside=privateAudience(p);if(inside&&!inside.participants.length&&b.objectiveFlight&&!nativeEventParticipant(p,inside.run)){await leaveNpc(id,p.token);cancelActor(id);brains.delete(id);continue;}
   if(capacityPolicy&&!b.desiredChannel){const scheduler=ensurePopulationWorkers();if(foregroundRequested(p))void scheduler.handoffCurrent(p,{requested:()=>foregroundRequested(p)}).catch(onError);else if(!scheduler.owns(p)&&!backgroundWork.owns(p))void scheduler.adoptCurrent(p,{requested:()=>!foregroundRequested(p)}).catch(onError);}
   b.sceneOccupied=nearby;
   if(capacityPolicy&&populationWorkers?.owns(p)&&!p.instanceId&&!isDkChannel(p.channel)&&!world.data.requiresInstance?.(p.map)&&!world.data.eventData?.modeOf?.(p.map)&&!Number(world.data.mapRow?.(p.map)?.IsSiege)&&!humanParty&&!(leader&&human(leader))&&!npcPendingHumanInvite(world,p,human)){visitors.retirement(id,{present:nearby,protected:true});continue;}
   const pendingHuman=b.desiredChannel&&scenes.has(b.seedScene),pendingInvite=npcPendingHumanInvite(world,p,human),protectedActor=interestOrphanProtected(p,b,{nearby,pendingHuman,pendingInvite,humanParty,leader})??(fishingHook.protected(p)||!!pendingHuman||!!pendingInvite||npcFieldVisitorProtected(world,p,b,{isHuman:human,talking,eventRetains:q=>eventTeams.retains(q)}));b.sceneOccupied=nearby;
   const ownedWorker=populationWorkers?.owns(p),working=ownedWorker||backgroundWork.observe(p,b,{occupied:nearby,protected:!!pendingHuman||!!pendingInvite||!!humanParty||!!(leader&&human(leader))||!!p.instanceId||eventTeams.retains(p)});
   if(visitors.retirement(id,{present:nearby,protected:protectedActor||working||foregroundRequested(p)})){
    // Interest-managed mode retires a whole map's residents in ONE durable batch (they all leave together when the human does).
    if(background){await fishingHook.retire(p,b);retiring.push({player:p,token:p.token,brain:b});}
    else{await leaveNpc(id,p.token);cancelActor(id);brains.delete(id);residentSchedule.forget(id);visitors.forget(id);groupChat.cancelPlayer(p);}
   }
  }
  for(let i=0;i<retiring.length;i+=64){try{await departNpcWave(retiring.slice(i,i+64),async row=>{const q=row.player;if(world.players.has(q.account)||q.token!==row.token||brains.get(q.account)!==row.brain)throw Object.assign(Error('Director departure custody changed.'),{status:409});cancelActor(q.account);brains.delete(q.account);residentSchedule.forget(q.account);visitors.forget(q.account);groupChat.cancelPlayer(q);});}catch(error){onError(error);}}
  for(const [key,anchors]of scenes){if(world.now()<(sceneRetry.get(key)||0))continue;sceneRetry.delete(key);const residents=[...brains].filter(([id,b])=>{const p=world.players.get(id);return p&&(!(capacityPolicy||background)||!populationWorkers?.owns(p))&&(sceneKey(p.map,p.instanceId,p.channel)===key||b.desiredChannel&&b.seedScene===key)});let n=residents.length;
   // Keep already admitted event crews and human companions. A lower setting
   // retires at most one idle ambient actor per cycle through ordinary leave,
   // preserving earned profiles and avoiding transaction/chat interruption.
   // Automatic target is identical to the scene preparation target.
   // Existing protected actions may temporarily remain above a reduced target.
   const ordinaryDensity=effectiveSceneDensity(anchors[0]),quiet=residents.filter(([id,b])=>{const p=world.players.get(id),duty=cityDutyPlanner.assigned(p);return (duty==='rest'||duty==='shop')&&!p.partyId&&!p.tradeId&&!b.follow&&!b.questId&&!Object.keys(p.profile.quests?.active||{}).length&&!eventTeams.retains(p)&&!eventTeams.handles(p);}).length;
   const density=background&&anchors[0].map===150?cityRetention.target(key,{scaled:ordinaryDensity,quiet,actual:n,optionalWorkAllowed:world.npcOptionalWorkAllowed?.(),percent:Number(population())}):ordinaryDensity;
   let talking;const quietIdle=([id,b])=>{talking??=new Set(groupChat.snapshot().flatMap(s=>s.actors));const p=world.players.get(id),party=p?.partyId&&world.parties.get(p.partyId),escort=b.follow&&actor(b.follow);return p&&!decisionFlights.owns(p)&&!populationWorkers?.inFlight(p)&&!foregroundRequested(p)&&!fishingHook.protected(p)&&!p.instanceId&&!p.dead&&!p.path.length&&!p.attackTarget&&!p._skills?.engine.casting&&!p.commandActive&&!p.progressCommitting&&!p.sceneTransition&&!b.objectiveFlight&&!b.refineRestore&&p.profile.npcEquipment?.phase!=='working'&&!p.pcShopOpen&&!p.tradeId&&!party&&!b.queue.length&&!talking.has(p.id)&&world.now()>=(b.quietUntil||0)&&!world.partyInvites.has(p.id)&&!npcPendingHumanInvite(world,p,human)&&!eventTeams.retains(p)&&!(escort&&human(escort))&&!party?.members.some(pid=>human(actor(pid)))&&! [...(mapFor(world,p)?.monsters.values()||[])].some(m=>!m.dead&&m.targetId===p.id&&distance(p,m)<15);};
   // Opt-in login/logout cycles: at most one quiet resident whose session ended
   // leaves through the same ordinary path per scene per cycle (global spacing 5s).
   const sessionScan=sessionsOn&&n<=density&&Date.now()>=sessionRetireAt,sessionEnded=sessionScan?residents.find(row=>{const p=world.players.get(row[0]);if(!p)return false;const online=npcSessionOnline(p.profile,Date.now()),seen=sessionSeenOnline.get(p.account);if(seen!==p&&online)sessionSeenOnline.set(p.account,p);
    // Only a resident first observed inside its session may log out; a resident admitted
    // off-schedule (to keep density when too few are online) is exempt, so no churn loop.
    return seen===p&&!online&&quietIdle(row);}):null;
   if(sessionScan){sessionRetireAt=Date.now()+(sessionEnded?5000:2000);if(sessionEnded){sessionLogouts++;sessionSeenOnline.delete(sessionEnded[0]);}if(sessionSeenOnline.size>4*policy.total)for(const [a,q]of sessionSeenOnline)if(world.players.get(a)!==q)sessionSeenOnline.delete(a);}
   if(n>density||sessionEnded){const idle=sessionEnded||residents.find(quietIdle);if(idle){const [id]=idle,p=world.players.get(id);await leaveNpc(id,p.token);cancelActor(id);brains.delete(id);groupChat.cancelPlayer(p);n--;}}
   if(n<density&&!sceneWarming.warming(key)&&(!background||sceneWarming.snapshot(key)?.phase==='ready')&&admissionAvailable()&&(capacityPolicy?foregroundCount()<policy.total&&physicalNpcCount()<capacityPolicy.actorCap:brains.size<policy.total)&&residentSchedule.ready(key))await spawn(anchors[n%anchors.length],n);
  }
 }
 function messages(){const events=world.events.filter(e=>e.sequence>eventCursor);eventCursor=world.sequence;
  for(const e of events)if(e.type==='damage'){const p=actor(e.targetId);if(p&&!npcCityDamageWake(p,brains.get(p.account),e,world.now()))npcArchetypeReactionWake(p,brains.get(p.account),e,world.now(),{tier:npcCompetenceTier(p)});}
  for(const e of events){if(e.type==='damage'&&Number(e.amount)>0&&actor(e.sourceId)){for(const [id,b]of brains){const p=world.players.get(id),party=p?.partyId&&world.parties.get(p.partyId);if(party?.members.includes(e.targetId))b.pkSocialHit=e;}continue;}if(e.type!=='chat'&&e.type!=='messenger')continue;const speaker=actor(e.actorId);if(!speaker)continue;
   // NPC ambient replies do not recursively generate replies. Private chat stays in its original audience.
   if(bot(speaker))continue;
   const candidates=[...brains].map(([id,b])=>({p:world.players.get(id),b})).filter(({p,b})=>p&&!p.dead&&(e.recipients?e.recipients.includes(p.id):sameScene(e,p))&&(e.type==='messenger'||e.channel==='whisper'||e.channel==='party'||sameScene(p,speaker)&&distance(p,speaker)<=policy.chatDistance));
   const named=npcAddress(e.text,[...brains].map(([id])=>world.players.get(id)).filter(Boolean));
   if(e.type!=='messenger'&&!['normal','whisper','party'].includes(e.channel||'normal'))continue;
   const key=speaker.id+':'+(e.type==='messenger'?'messenger':e.channel||'normal'),previous=conversations.get(key),offerChannel=e.type==='messenger'?'messenger':e.channel||'normal',offered=candidates.find(({p,b})=>{const offer=memory(b,speaker.id).conversationOffer;return offer?.requesterId===speaker.id&&offer.until>world.now()&&offer.channel===offerChannel&&(offerChannel!=='party'||offer.partyId===speaker.partyId);}),focused=previous&&previous.until>world.now()&&candidates.find(({p})=>p.id===previous.id)||offered;
   const audienceText=named.addressed?e.text:npcNormalizeLocalizedInput(e.text,language());
   const privateChat=e.type==='messenger'||e.channel==='whisper',recruiting=!privateChat&&!named.addressed&&npcPartyRecruitment(audienceText),volunteers=recruiting?npcRecruitmentCandidates(world,candidates,speaker):[];
   if(privateChat||named.addressed){groupChat.cancelPlayer(speaker);for(const {p}of candidates)if(privateChat||p.id===named.id)groupChat.cancelPlayer(p);}
   const grouped=!offered&&!privateChat&&!named.addressed&&groupChat.receive({speaker,text:audienceText,channel:e.channel||'normal',targets:candidates.map(c=>c.p),recipients:e.recipients});
   if(grouped&&!recruiting)continue;
   const partyCommand=e.channel==='party'&&!named.addressed&&['follow','stop','roam','prepare'].includes(dialogueIntent(audienceText));
   const chosen=privateChat?candidates:named.addressed?candidates.filter(({p})=>p.id===named.id):partyCommand?candidates.filter(({p})=>p.partyId===speaker.partyId&&world.parties.get(p.partyId)?.members.includes(p.id)):recruiting&&volunteers.length?volunteers.slice(0,1):focused?[focused]:candidates.sort((a,b)=>distance(a.p,speaker)-distance(b.p,speaker)).slice(0,1);
   if(chosen.length){conversations.set(key,{id:chosen[0].p.id,until:world.now()+60000});for(const {b}of candidates)b.quietUntil=world.now()+20000;}
   if(conversations.size>128)for(const [id,c]of conversations)if(c.until<world.now())conversations.delete(id);
   for(const [chosenIndex,{p,b}]of chosen.entries()){const body=named.id===p.id?e.text.replace(new RegExp('\\b'+named.word+'\\b','i'),'').trim():e.text,text=npcNormalizeLocalizedInput(body.replace(/[.!?\s]/g,'')?body:'attention',language()),duplicate=b.queue.some(m=>m.speaker===speaker.id&&m.text.toLowerCase()===text.toLowerCase());if(!duplicate){if(b.queue.length>=4)b.queue.shift();b.queue.push({speaker:speaker.id,text,channel:e.type==='messenger'?'messenger':e.channel==='whisper'?'whisper':e.channel==='party'?'party':'normal',...(e.channel==='party'?{partyId:e.partyId||speaker.partyId}:{}),directed:privateChat||named.addressed||!!focused,silentReply:partyCommand&&chosenIndex>0,at:world.now(),replyAt:world.now()+npcTypingDelay(p.profile,{text,topic:dialogueIntent(text),context:personaContext(p,speaker,b,false)})});b.next=Math.min(b.next,b.queue.at(-1).replyAt);}}
  }
 }
 async function conversation(p,b,msg){const other=actor(msg.speaker);if(!other||world.now()-msg.at>20000)return;
  cityRequester.observe(p,other,msg.text);
  if(msg.channel==='normal'&&(!sameScene(p,other)||distance(p,other)>policy.chatDistance))return;
  if(msg.channel==='party'&&(!msg.partyId||p.partyId!==msg.partyId||other.partyId!==msg.partyId||!world.parties.get(msg.partyId)?.members.includes(p.id)||!world.parties.get(msg.partyId)?.members.includes(other.id)))return;
  if(bot(other)&&(world.now()<(b.quietUntil||0)||!sameScene(p,other)||distance(p,other)>policy.chatDistance))return;
  // Resolve a delivered invitation before generic knowledge/agency matching.
  // A decline is speech only and leaves the actor's native objective running.
  // Silent companion copies must not consume a delivered offer or act on it.
  if(msg.silentReply&&memory(b,other.id).conversationOffer)return;
  const continuationMemory=memory(b,other.id);continuationMemory.followupTurn=Number.isSafeInteger(continuationMemory.followupTurn)&&continuationMemory.followupTurn<Number.MAX_SAFE_INTEGER?continuationMemory.followupTurn+1:1;
  const consent=npcConversationConsent({world,player:p,requester:other,memory:memory(b,other.id),text:msg.text,channel:msg.channel,partyId:msg.partyId});
  if(consent){
   if(msg.silentReply)return;
   let reply=consent.text;
   if(consent.decision==='accept'){
    const m=memory(b,other.id),isHelp=consent.type==='quest-help',goal=isHelp?npcQuestTalkGoal(world.data,p,b):null;
    if(isHelp)delete m.questHelpOffer;
    const decision=npcRequestDecision({world,player:p,brain:b,requester:other,intent:'party',...(isHelp?{questHelpId:consent.questId}:{})});
    async function ordinaryInvite(){
     let current=p.partyId&&world.parties.get(p.partyId),their=other.partyId&&world.parties.get(other.partyId);
     if(current?.members.includes(p.id)&&current===their&&current.members.includes(other.id))return {ready:true,text:isHelp?'Come with me. I will wait if you fall behind.':'Nice, we are already in the same party.'};
     if(their?.members.includes(other.id))return {ready:!current,text:their.leader===other.id?'Invite me from your party window, then we can group up.':'Ask your party leader to invite me.'};
     if(current&&(!current.members.includes(p.id)||current.leader!==p.id))return {ready:false,text:'My party leader needs to send the invite.'};
     const pending=world.partyInvites.get(other.id),incoming=world.partyInvites.get(p.id);
     if(pending?.expires>world.now()&&pending.party!==current?.id)return {ready:false,text:'You already have another party invite. Check that first.'};
     if(!current&&incoming?.expires>world.now())return {ready:false,text:'I already have an invite. Let me answer that first.'};
     try{
      if(!current){await act(p,{type:'party',operation:'create',name:isHelp?'Quest party':'Adventure party'});current=p.partyId&&world.parties.get(p.partyId);}
      if(!current||current.leader!==p.id||!current.members.includes(p.id))return {ready:false,text:'I cannot send a party invite right now.'};
      if(!(pending?.party===current.id&&pending.expires>world.now()))await act(p,{type:'party',operation:'invite',targetId:other.id});
      const invite=world.partyInvites.get(other.id);
      if(world.players.get(other.account)===other&&!other.leaving&&invite&&invite.party===current.id&&invite.expires>world.now())return {ready:true,text:isHelp?'Sent an invite. Come with me once you accept; I will wait.':'Sent an invite. Accept it when you are ready.'};
      return {ready:false,text:'I cannot confirm an invite right now. Try the party window.'};
     }catch(error){if(!error.status)throw error;return {ready:false,text:'I could not send the invite. Check the party window.'};}
    }
    if(!decision.accept)reply=decision.text;
    else if(isHelp&&(!goal||goal.questId!==consent.questId))reply='My quest changed. Let me check what I need first.';
    else if(isHelp&&!questAssistance.request(p,other,{explicit:true,questId:consent.questId}))reply='I cannot guide that quest right now. Let me check it.';
    else{const invitation=await ordinaryInvite();reply=invitation.text;if(isHelp&&!invitation.ready)questAssistance.cancel(p);}
   }
   const text=localSpeech(reply);
   if(msg.channel==='party'){if(world.now()>=b.chatReady){b.chatReady=world.now()+2500;await act(p,{type:'party',operation:'chat',text});}}
   else await say(p,b,text,{localized:true,...(['whisper','messenger'].includes(msg.channel)?{channel:msg.channel,targetName:other.profile.name}:{})});
   return;
  }
  const c=personaContext(p,other,b),m=memory(b,other.id);
  let result=npcReply({text:msg.text,context:c,memory:m,random:world.random});
  const maxLength=msg.channel==='messenger'?60:msg.channel==='normal'&&bot(other)?250-String(other.profile.name).length-2:250;
  if(result.topic==='smalltalk'&&human(other)){
   if(msg.silentReply||!msg.directed&&!npcConversationAttention({world,player:p,brain:b,requester:other,intent:null}).respond)return;
   delete m.knowledge;delete m.situation;delete m.coaching;delete m.social;
   const text=npcPersonaSpeech(result.text,{profile:p.profile,context:c,memory:m,topic:'smalltalk',maxLength});
   if(msg.channel==='party'){if(world.now()>=b.chatReady){b.chatReady=world.now()+2500;await act(p,{type:'party',operation:'chat',text:localSpeech(text)});}}
   else await say(p,b,text,['whisper','messenger'].includes(msg.channel)?{channel:msg.channel,targetName:other.profile.name}:{});
   return;
  }
  const socialIntent=npcSocialIntent(msg.text);
  if(socialIntent&&socialIntent!=='followup'){delete m.knowledge;delete m.situation;delete m.coaching;delete m.commerceConversation;delete m.questHelpOffer;}
  const commerceReply=npcCommerceReply({world,player:p,requester:other,text:msg.text,memory:m,maxLength,channel:msg.channel,brain:b}),commerceQuestion=msg.directed&&!!commerceReply;
  // This queue already selected its audience. Recognized directed information
  // and short conversation cues bypass silence; speech never cancels work.
  const situation=commerceReply?null:npcSituationReply({world,player:p,requester:other,brain:b,text:msg.text,memory:m,maxLength,directed:true,channel:msg.channel});
  const directedCue=msg.directed&&npcConversationCue(msg.text);
  if(!commerceQuestion&&!(msg.directed&&situation)&&!directedCue&&!npcConversationAttention({world,player:p,brain:b,requester:other,intent:result.intent}).respond)return;
  const coach=commerceReply||situation||npcCoachingReply({world,player:p,requester:other,brain:b,text:msg.text,memory:m,maxLength}),knowledge=coach||npcKnowledgeReply({world,player:p,requester:other,brain:b,text:msg.text,memory:m,maxLength,tier:npcPersona(p.profile).knowledgeTier});
  // A verified information answer is speech only. The helper excludes action
  // requests; legacy word matching must not turn skill questions into casts.
  if(knowledge){const help=/\b(?:help you|need help)\b/i.test(msg.text)?npcPersonaHelpQuestion(p.profile,{context:{...c,helpNeed:knowledge.helpNeed},maxLength}):'';result={...result,intent:null,text:help||knowledge.text,topic:knowledge.topic};}
  if(!knowledge){const social=npcSocialReply({world,player:p,requester:other,text:msg.text,memory:m,directed:true,channel:msg.channel,partyId:msg.partyId,context:c,maxLength});if(social)result={...result,intent:null,text:social.text,topic:social.topic};}
  else delete m.social;
  const decision=npcRequestDecision({world,player:p,brain:b,requester:other,intent:result.intent});
  if(!decision.accept){
   if(msg.channel==='party'){if(world.now()>=b.chatReady){b.chatReady=world.now()+2500;await act(p,{type:'party',operation:'chat',text:localSpeech(decision.text)});}return;}
   return say(p,b,decision.text,['whisper','messenger'].includes(msg.channel)?{channel:msg.channel,targetName:other.profile.name}:{});
  }
  const authoredOffer=npcDialogueOffer(result.text,result.topic||m.topic||result.intent);
  result.text=npcPersonaSpeech(result.text,{profile:p.profile,context:c,memory:m,topic:result.topic||result.intent,maxLength});
  if(human(other)&&/\b(?:dk\s*(?:square)?|square)\b/i.test(msg.text)&&/\b(?:organize|host|open|start|ready|dk\??)\b/i.test(msg.text)){b.organizerHuman=other.id;b.organizerUntil=world.now()+60000;}
  if(['follow','stop','roam','lure','party'].includes(result.intent)&&p.pcShopOpen){await npcMerchantStep({world,player:p,brain:b,act,cancel:true});b.queue.unshift(msg);return;}
  if(result.intent==='prepare')b.prepareUntil=world.now()+20000;
  if(result.intent==='pvp'&&sameScene(p,other)&&distance(p,other)<=20)b.duelTarget=other.id;
  if(['follow','stop','roam','lure'].includes(result.intent)){
   // Commands are accepted from nearby humans or a current party mate; remote whispers cannot move an actor across scenes.
   if(sameScene(p,other)&&distance(p,other)<=policy.chatDistance||p.partyId&&p.partyId===other.partyId){
    b.partyFollow=false;
    questAssistance.cancel(p);
    if(result.intent==='stop'){b.mode='wait';b.follow=null;await act(p,{type:'stop'});b.activity='waiting';}
    else if(result.intent==='roam'){b.mode='roam';b.follow=null;b.home={x:p.x,z:p.z};}
    else{b.mode=result.intent;b.follow=other.id;b.lureTarget=null;}
    b.closeFollow=result.intent==='follow';delete b.followMotion;
   }else return say(p,b,'Come near me or join my party before giving movement commands.',{channel:'whisper',targetName:other.profile.name});
  }
  if(result.intent==='party'){
   if(!p.partyId&&other.partyId){const party=world.parties?.get(other.partyId),leader=actor(party?.leader);if(leader?.id===other.id)return say(p,b,'Send me an invitation from the party window and I will accept it.',['whisper','messenger'].includes(msg.channel)?{channel:msg.channel,targetName:other.profile.name}:{});}
   if(!p.partyId&&!other.partyId){await act(p,{type:'party',operation:'create',name:'Adventure party'});await act(p,{type:'party',operation:'invite',targetId:other.id});memory(b,other.id).partyInvited=true;}
   else if(p.partyId&&!other.partyId&&world.parties.get(p.partyId)?.leader===p.id){await act(p,{type:'party',operation:'invite',targetId:other.id});memory(b,other.id).partyInvited=true;}
  }
  // Explicit quest-help acceptance requests only this NPC's ordinary party.
  // It never accepts an invitation or emits a command for the human.
  const helpText=String(msg.text).toLowerCase().trim(),helpYes=/^(?:yes|yeah|yep|sure|ok|okay|sounds good|i can help)[!? .]*$/.test(helpText)&&m.questHelpOffer?.until>world.now(),helpExplicit=/\b(?:i can help(?: you)?|i will help(?: you)?|i'll help(?: you)?|ill help(?: you)?|can i help you|let me help(?: you)?|i want to help you)\b/.test(helpText)&&! /\b(?:not|no|never|cannot|can't|dont|don't)\b/.test(helpText);
  const helpGoal=human(other)&&(helpYes||helpExplicit)?npcQuestTalkGoal(world.data,p,b):null;
  if(helpGoal&&npcRequestDecision({world,player:p,brain:b,requester:other,intent:'party',questHelpId:helpGoal.questId}).accept){
   const goal=helpGoal,crew=p.partyId&&world.parties.get(p.partyId),eligibleCrew=!crew||crew.leader===p.id||crew.members.includes(other.id);
   if(goal&&eligibleCrew&&(!helpYes||m.questHelpOffer.questId===goal.questId)&&questAssistance.request(p,other,{explicit:true,questId:goal.questId})){
    if(!p.partyId&&!other.partyId)await act(p,{type:'party',operation:'create',name:'Quest party'});
    const current=p.partyId&&world.parties.get(p.partyId);if(!other.partyId&&current?.leader===p.id)await act(p,{type:'party',operation:'invite',targetId:other.id});
    result.text=p.partyId&&p.partyId===other.partyId?'Nice, come with me. I will wait if you fall behind.':current?.leader===p.id?'Sent an invite. Come with me once you accept; I will wait if you fall behind.':'Invite me through the party window. Then I can show you where I am headed.';result.intent=null;delete m.questHelpOffer;
   }
  }
  // Speech continues alongside the current native path, skill and objective.
  // Only an accepted explicit movement request above may change that plan.
  const deliveredOffer=authoredOffer;
  if(!String(result.text||'').trim())return;
  result.text=localSpeech(result.text);
  if(msg.channel==='normal'&&bot(other))result.text=(other.profile.name+', '+result.text).slice(0,250);
  if(msg.silentReply)return;
  const since=world.sequence;let spoken;
  if(msg.channel==='party'&&p.partyId&&p.partyId===other.partyId){if(world.now()>=b.chatReady){b.chatReady=world.now()+2500;spoken=await act(p,{type:'party',operation:'chat',text:result.text})}}
  else spoken=await say(p,b,result.text,{localized:true,...(['whisper','messenger'].includes(msg.channel)?{channel:msg.channel,targetName:other.profile.name}:{})});
  const delivered=spoken?.events?.some(e=>['chat','messenger'].includes(e.type)&&e.actorId===p.id&&e.text===result.text&&e.sequence>since&&e.recipients?.includes(other.id)&&(msg.channel==='messenger'?e.type==='messenger'&&e.targetId===other.id:e.channel===msg.channel)&&(msg.channel!=='party'||e.partyId===msg.partyId))===true;
  for(const field of ['situation','commerceFollowup'])if(m[field]&&Number.isSafeInteger(m[field].turn)&&m[field].turn===m.followupTurn)m[field].delivered=delivered;
  if(deliveredOffer)npcRememberConversationOffer({world,player:p,requester:other,memory:m,offer:deliveredOffer,channel:msg.channel,partyId:msg.partyId,delivered});
  if(knowledge?.helpNeed?.questId&&/\b(?:help you|need help)\b/i.test(msg.text)&&!helpYes&&!helpExplicit&&delivered)m.questHelpOffer={questId:knowledge.helpNeed.questId,until:world.now()+45000};
  if(m.questHelpOffer&&delivered)npcRememberConversationOffer({world,player:p,requester:other,memory:m,offer:{type:'quest-help',questId:m.questHelpOffer.questId},channel:msg.channel,partyId:msg.partyId,delivered});
 }
 async function move(p,to,{tight=false}={}){const map=mapFor(world,p);if(!map||!Number.isFinite(to.x)||!Number.isFinite(to.z))return false;let at=map.isWalkable(to.x,to.z)?to:map.nearest(to.x,to.z);const minimum=tight?.15:.5,changed=tight?.2:.7;if(!at||distance(p,at)<minimum)return false;
  // LANE3 nav lease: reuse a still-valid native path, bounded stuck recovery. Advisory only; the ordinary move below stays the authority.
  const navBrain=npcNavEnabled(world)&&brains.get(p.account),navGoal=at,navTarget=to.id??null;
  if(navBrain){const nv=npcNavBeforeMove(world,p,navBrain,at,{map,targetId:navTarget,tight});if(nv.reuse)return true;if(nv.blocked){if(nv.stop&&p.path.length){await act(p,{type:'stop'});moveIntents.delete(p);}return false;}if(nv.force)moveIntents.delete(p);at=nv.at;}
  const intent=moveIntents.get(p),scene=sceneKey(p.map,p.instanceId,p.channel);if(p.path.length&&intent?.scene===scene&&distance(intent.at,at)<changed)return true;const last=p.path.at(-1);if(last&&distance(last,at)<changed)return true;
  // The ordinary movement authority permits one request per150ms. Keep the
  // current native path between polls instead of turning a429 into a long wait.
  if(tight&&world.now()-p.moveAt<150)return !!p.path.length;
  if(!npcReachableApproach(map,p,at,tight?.4:1)){if(navBrain)npcNavAfterMove(world,p,navBrain,{goal:navGoal,at,ok:false,targetId:navTarget});return false;}
  try{await act(p,{type:'move',x:at.x,z:at.z});moveIntents.set(p,{scene,at:{x:at.x,z:at.z}});if(navBrain)npcNavAfterMove(world,p,navBrain,{goal:navGoal,at,ok:true,targetId:navTarget});return true}catch(e){if(!e.status)throw e;if(navBrain)npcNavAfterMove(world,p,navBrain,{goal:navGoal,at,ok:false,targetId:navTarget});return false;}}
 async function toward(p,to){if((to.map==null||Number(to.map)===p.map)&&(to.channel==null||to.channel===(p.channel||0)))return move(p,to);const plan=npcRoutePlan(world,p,to),brain=brains.get(p.account);if(plan.blockedReason){if(brain){brain.travelBlockedReason=plan.blockedReason;brain.activity='travel unavailable: '+plan.blockedReason;}return false;}if(brain)delete brain.travelBlockedReason;if(plan.action){
  // Background travel reserves the actual next native edge's geometry before
  // the ordinary command publishes its new scene. Human-led companions are
  // handed to the foreground controller and retain ordinary travel authority.
  let reservation;const edge=plan.route?.[0];if((populationWorkers?.owns(p)||backgroundWork.owns(p))&&edge){const channel=edge.arrival?.channel??p.channel??0,key=sceneKey(edge.to,null,channel);reservation=background&&populationWorkers?.owns(p)?await fieldResidency.acquireWorker(edge.to,channel,{account:p.account,profile:p.profile,actor:p}):world.data.fieldParkingAllowed?.(edge.to)===true?await fieldResidency.acquire(edge.to,channel):world.maps.has(key)?{ok:true,release:world.acquireSceneLease(edge.to,null,channel)}:{ok:false};if(!reservation.ok){if(brain){brain.travelBlockedReason='Background destination is awaiting a safe resident field: '+(reservation.reason||'native refusal');brain.activity='waiting for native travel';}return false;}}
  try{await act(p,plan.action);}finally{reservation?.release?.();}
 }else return move(p,eventTeams.attending(p)&&!p.instanceId?npcEventWalkStage(mapFor(world,p),p,plan.at)||plan.at:plan.at);return true;}
 function publishFreeplay(p,b,plan){
  if(!plan)return;b.freeplayState=plan.nextState;
  const goal=p.profile.npcLongTermGoal||{version:1,policy:'ENGINE-CHOSEN objective; ordinary native earned progress',kind:'progress',targetLevel:world.data.maxLevel};
  if(JSON.stringify(goal.planning)!==JSON.stringify(plan.nextState)){p.profile.npcLongTermGoal={...goal,planning:{...plan.nextState}};world.changed(p);}
 }

 async function recoverOnwardTownWait(p,b){
  // ENGINE-CHOSEN waiting space only after this exact ordinary structural
  // refusal. The existing move contract catches status errors as false; this
  // helper never treats false as a successful arrival or changes that contract.
  const now=world.now();
  if(now<(b.prepareUntil||0)||now<(b.organizerUntil||0)||now<(b.pauseUntil||0)||now<(b.onwardTownRestRetryAt||0)||b.taskGoal&&['farm','merchant','dungeon','event'].includes(b.taskGoal.kind)&&now<Number(b.taskGoal.until)||b.travelBlockedReason!=="No affordable native ordinary field route meets the current level/admission requirements."||world.players.get(p.account)!==p||p.profile.authority!=='server'||p.profile.npcPlayer!==true||p.npcPlayer!==true||p.map!==150||p.profile.map!==p.map||mapFor(world,p)?.index!==p.map||p.dead||p.leaving||p.revoked||p.path.length||p.partyId||b.mode!=='roam'||b.follow||b.lure||p.instanceId||isDkChannel(p.channel)||p.tradeId||p.pcShopOpen||p.commandActive||p.progressCommitting||p.tradeCommitting||p.sceneTransition||p.smartWarp||p.mount||fishingBusy(p)||p.attackTarget||p._skills?.engine.casting||p._skills?.engine.busy||b.objectiveFlight||b.routeGoal||b.questId||b.target||b.farmTarget||b.refineRestore||p.profile.npcEquipment?.phase==='working'||p.profile.npcMerchantReservation?.phase==='held'||['listing','open','closing'].includes(p.profile.npcMerchant?.phase)||['prepared','invited','confirming'].includes(p.profile.npcGift?.phase)||b.queue.length||world.partyInvites.has(p.id)||npcPendingHumanInvite(world,p,human)||eventTeams.handles(p)||eventTeams.retains(p)||world.data.requiresInstance?.(p.map)||world.data.eventData?.modeOf?.(p.map)||Number(world.data.mapRow?.(p.map)?.IsSiege)||Object.keys(p.profile.quests?.active||{}).length)return false;
  // Only a currently clustered independent actor needs relocation. Real
  // standing peers are observed; their protected goals/positions are untouched.
  if(![...world.players.values()].some(q=>q!==p&&bot(q)&&!q.dead&&!q.leaving&&!q.path.length&&sameScene(p,q)&&distance(p,q)<12))return false;
  const previousActivity=b.activity;b.activity='looking for an available objective';
  try{const parking=npcTownIdlePlan({world,player:p,brain:b,isHuman:human});if(!parking)return false;b.idleTownPlan=parking;if(parking.near)return false;const moved=await move(p,parking.at);if(!moved)b.onwardTownRestRetryAt=now+15000;return moved;}
  finally{b.activity=previousActivity;}
 }
 async function onward(p,b){
  if(cityDuty(p,b)&&cityDuty(p,b)!=='quest')return false;
  if(!freeplayCatalog)return false;
  const plan=npcFreeplayPlan({world,player:p,brain:b,catalog:freeplayCatalog,state:b.freeplayState||p.profile.npcLongTermGoal?.planning||{}});
  if(!plan)return false;publishFreeplay(p,b,plan);
  if(plan.kind!=='route'){b.freeplayReason=plan.reason;return false;}
  b.forwardGoal={destinationMap:plan.destinationMap,mode:plan.mode,until:world.now()+120000,retryAt:0};b.activity='heading to the next leveling area';
  if(await toward(p,{map:plan.destinationMap}))return true;
  // A collision/admission refusal is not movement. Keep the native intention
  // for bounded reconsideration instead of creating an invented arrival.
  b.activity='waiting for an available onward route';await recoverOnwardTownWait(p,b);return true;
 }
 function npcAt(p,who){if(!who)return null;const map=Number(who.map??p.map),rows=world.data.progression.npcs.placements?.[map]?.rows||[],r=rows.find(r=>Number(r[0])===Number(who.npc));return r?{map,x:Number(r[1]),z:Number(r[2]),npc:Number(who.npc)}:null;}
 function serviceApproach({player:p,plan}){
  const id=plan.serviceAt?.npc||plan.action?.npcIndex||plan.npcIndex||plan.at?.npc,placed=id&&npcAt(p,{npc:id,map:plan.serviceAt?.map??plan.at?.map??p.map});
  if(!placed||placed.map!==p.map||p.instanceId||isDkChannel(p.channel))return plan;
  const crew=p.partyId&&world.parties.get(p.partyId);if(crew?.members.some(id=>human(actor(id))))return plan;
  const spaced=npcTownServicePlan(world,p,placed);if(spaced)return {...plan,at:spaced.at,near:spaced.near};
  const waiting=npcTownWaitPlan(world,p,placed);return waiting?{...plan,at:waiting.at,near:false,waiting:true}:null;
 }
 // Bounded quest-stall handling (npc-quest-feasibility.mjs): log, defer, or abandon through the player operation.
 async function questStall(p,b,q,{reason,permanent=false,claim=false}){const verdict=npcQuestStall(b,q.id,{reason,permanent,claim,now:world.now()});noteQuestStall(verdict.action+':'+reason);
  if(b.questId===Number(q.id)){b.questId=null;b.questTitle='';b.target=null;b.routeGoal=null;}
  const crew=p.partyId&&world.parties.get(p.partyId);
  if(verdict.action==='abandon'&&!crew?.members.some(id=>human(actor(id)))){try{await act(p,{type:'quest',operation:'abandon',questId:Number(q.id)});questStallTotals.abandoned++;npcQuestProgressed(b,q.id);}catch(e){if(!e.status)throw e;noteQuestStall('abandon-refused:'+(e.code??e.status));}}
  else questStallTotals.deferred++;
  return false;}
 async function quest(p,b,escort){if(!escort&&cityDuty(p,b)&&cityDuty(p,b)!=='quest')return false;if(world.now()<b.questAt)return !!b.routeGoal&&p.path.length>0;b.questAt=world.now()+2000;b.questSkills=[];b.routeGoal=null;const c=createQuestContext(world,p);if(!c)return false;
  const close=at=>at&&(!escort||at.map===escort.map&&distance(at,escort)<=12)&&(at.map!==p.map||!!approach(mapFor(world,p),p,at,7));
  const visit=at=>{if(at.map!==p.map)return toward(p,at);if(!escort&&!p.instanceId){const spaced=npcTownServicePlan(world,p,at)||npcTownWaitPlan(world,p,at);return spaced?(spaced.near?true:move(p,spaced.at)):true;}return move(p,approach(mapFor(world,p),p,at,7)||{});};
  const qNow=world.now(),active=c.engine.activeIds().map(id=>c.engine.db.quest(id)).filter(q=>q&&!npcQuestDeferred(b,q.id,qNow));let q=active.find(q=>c.engine.isComplete(q.id))||active.find(q=>q.id===b.questId)||active.find(q=>(q.objectives||[]).some(o=>!c.engine.objectiveDone(q,o)&&['talk','kill','killOnMap','collect','useSkill'].includes(o.kind)));
  if(!q){b.questId=null;b.questTitle='';b.target=null;q=chooseNpcQuest({quests:world.data.progression.quests.quests,seedId:b.taskGoal?.questId,slot:p.profile.npcSeed?.slot||0,level:p.profile.level,map:p.map,eligible:q=>npcQuestAcceptEligible(c,q)&&!npcQuestTalkOnly(c.engine,q)&&npcQuestFeasible(world,q,{classIndex:p.profile.classIndex}).ok,reachable:q=>close(npcAt(p,q.giver)),planning:b.questPlanning??={},context:{map:mapFor(world,p),sourceX:p.x,sourceZ:p.z,profile:p.profile},now:world.now()});if(!q)return false;
   const at=npcAt(p,q.giver);if(!at)return false;b.routeGoal=at;b.activity='walking to a quest giver';if(at.map===p.map&&distance(p,at)<=7){const result=await act(p,{type:'quest',operation:'accept',questId:Number(q.id),npc:at.npc});if(result?.result?.ok){b.questId=Number(q.id);b.questTitle=q.title;b.questAt=0;}return !!result?.result?.ok;}return visit(at);
  }
  b.questId=Number(q.id);b.questTitle=q.title||`quest ${q.id}`;
  b.questUnavailable=null;
  if(c.engine.isComplete(q.id)){const who=q.turnIn||q.giver,at=npcAt(p,who);if(!close(at))return false;b.target=null;b.routeGoal=at;b.activity='turning in a quest';if(at.map===p.map&&distance(p,at)<=7){const choice=q.rewardVariants?.mode==='choice'?q.rewardVariants.list.find(v=>v.classIndex==null||Number(v.classIndex)===p.profile.classIndex):null;try{await act(p,{type:'quest',operation:'claim',questId:Number(q.id),npc:at.npc,...(choice?{option:Number(choice.option)}:{})});}catch(e){if(!e.status)throw e;questStall(p,b,q,{reason:'claim-refused:'+(e.code??e.status),claim:true});return false;}if(c.engine.isDone(q.id)){b.questId=null;b.questTitle='';b.taskGoal=null;p.profile.npcRoutine=null;world.changed(p);}return true;}return visit(at);}
  const objective=(q.objectives||[]).find(o=>!c.engine.objectiveDone(q,o)&&['talk','kill','killOnMap','collect','useSkill'].includes(o.kind));if(!objective){b.questUnavailable={questId:q.id,map:p.map};const pending=(q.objectives||[]).find(o=>!c.engine.objectiveDone(q,o)),why=npcQuestObjectiveRunnable(world,q,pending,{classIndex:p.profile.classIndex});return await questStall(p,b,q,{reason:why.ok?'no-runnable-step':why.reason,permanent:!why.ok});}
  if(objective.kind==='talk'){const target=objective.targets?.[0];if(!target)return false;const at=npcAt(p,{npc:target.id,map:target.map??q.giver?.map??p.map,pos:target.pos});if(!close(at))return false;b.target=null;b.routeGoal=at;b.activity='visiting a quest NPC';if(at.map===p.map&&distance(p,at)<=7){await act(p,{type:'quest',operation:'talk',questId:Number(q.id),npc:at.npc});return true;}return visit(at);}
  if(objective.kind==='kill'||objective.kind==='killOnMap'){const ids=(objective.targets||[]).map(t=>Number(t.id)),map=mapFor(world,p);const targets=[...map.monsters.values()].filter(m=>!m.dead&&(objective.kind==='kill'?ids.includes(Number(m.monsterIndex)):ids.includes(p.map))).sort((a,q)=>Number(q.id===b.target)-Number(a.id===b.target)||distance(p,a)-distance(p,q));if(targets.length){b.target=targets[0].id;b.activity='hunting for a quest';return false;}b.target=null;const targetMap=npcQuestSpawnMap(world,q,objective,p.map);if(targetMap!==null&&targetMap!==p.map){b.routeGoal={map:targetMap};b.activity='traveling to a native quest target';if(await toward(p,b.routeGoal))return true;b.questUnavailable={questId:q.id,map:p.map};return await questStall(p,b,q,{reason:'route-unavailable:'+targetMap});}if(targetMap===null){b.questUnavailable={questId:q.id,map:p.map};return await questStall(p,b,q,{reason:'no-native-field-spawn:'+objective.kind,permanent:true});}return false;}
  if(objective.kind==='collect'){const items=new Set((objective.targets||[]).map(t=>Number(t.id))),ids=new Set([...(q.drops||[]).filter(d=>items.has(Number(d.item))).flatMap(d=>d.monsters||[]),...(objective.sources?.monsters||[]).map(r=>r[0])].map(Number)),map=mapFor(world,p);const targets=[...map.monsters.values()].filter(m=>!m.dead&&ids.has(Number(m.monsterIndex))).sort((a,q)=>Number(q.id===b.target)-Number(a.id===b.target)||distance(p,a)-distance(p,q));b.target=targets[0]?.id||null;if(targets[0]){b.activity='hunting a quest-item drop';return false;}const targetMap=npcQuestSpawnMap(world,q,objective,p.map);if(targetMap!==null&&targetMap!==p.map){b.routeGoal={map:targetMap};b.activity='traveling to a native quest-item source';if(await toward(p,b.routeGoal))return true;b.questUnavailable={questId:q.id,map:p.map};return await questStall(p,b,q,{reason:'route-unavailable:'+targetMap});}if(targetMap===null){b.questUnavailable={questId:q.id,map:p.map};return await questStall(p,b,q,{reason:'no-native-field-spawn:'+objective.kind,permanent:true});}return false;}
  if(objective.kind==='useSkill'&&(objective.map==null||Number(objective.map)===p.map)){b.questSkills=(objective.targets||[]).map(t=>Number(t.id));b.activity='practicing the quest skills';for(const id of b.questSkills){const s=world.data.skillPacks?.[p.profile.classIndex]?.skills?.[id];if(s&&Number(s.targetMask)===16){try{await act(p,{type:'cast',skillId:id});return true}catch(e){if(!e.status)throw e;}}}return false;}
  return false;
 }

 async function prepareSavedStock(p,b){
  const now=world.now(),stock=p.profile.npcSeed?.stock;
  if(b.savedBuildFinished||now<(b.savedBuildRetryAt||0)||stock?.policy!=='ENGINE-CHOSEN'||!Array.isArray(stock.uids)||!stock.uids.length||stock.uids.length>22)return false;
  if(world.players.get(p.account)!==p||!profiles.own(p.account)||p.characterId!==p.profile.id||p.profile.authority!=='server'||p.profile.npcPlayer!==true||p.npcPlayer!==true||p.leaving||p.dead||!(p.hp>0)||p.commandActive||p.progressCommitting||p.tradeCommitting||p.sceneTransition||p.instanceId||isDkChannel(p.channel)||p.partyId||b.follow||b.lure||b.mode!=='roam'||b.queue.length||world.partyInvites.has(p.id)||npcPendingHumanInvite(world,p,human)||eventTeams.handles(p)||eventTeams.retains(p)||b.fishingReserved||fishingHook.protected(p)||p.tradeId||p.pcShopOpen||p.path.length||p.attackTarget||p.mount||p.smartWarp||p._skills?.engine.casting||p._skills?.engine.busy||b.objectiveFlight||b.refineRestore||p.profile.npcEquipment?.phase==='working'||['listing','open','closing'].includes(p.profile.npcMerchant?.phase)||p.profile.npcMerchantReservation?.phase==='held'||now<(b.prepareUntil||0)||now<(b.organizerUntil||0)||now<(b.pauseUntil||0)||p.lastCombat!=null&&now-p.lastCombat<2000)return false;
  const map=mapFor(world,p);if(!map||world.data.requiresInstance?.(p.map)||world.data.eventData?.modeOf?.(p.map)||Number(world.data.mapRow?.(p.map)?.IsSiege))return false;
  if([...map.monsters.values()].some(m=>!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&m.targetId===p.id&&distance(p,m)<25))return false;
  const pending=p.profile.inventory?.some(i=>stock.uids.includes(i.uid)&&i.bound===true&&i.npcStartingStock==='ENGINE-CHOSEN'&&(!i.expiresAt||i.expiresAt>now));
  if(!pending||!world.data.itemDB||Number(b.savedBuildActions||0)>=stock.uids.length*4+2)return false;
  // Finish a saved character's usable weapon and armor first. Remaining
  // optional slots share the same bounded pace as spare points and learning.
  const eq=p.profile.equip,preset=eq?.presets?.[eq.active||0],has=slot=>Number.isSafeInteger(eq?.items?.[preset?.[slot]]?.itemIndex);
  if(has(S.weapon)&&has(S.armor)&&!optionalBuildPacer.take())return false;
  // ENGINE-CHOSEN finite optional phase. Ordinary authority owns all points,
  // UID transfers and persistence. No delay/stop/immunity or profile rewriting.
  let changed;
  try{changed=await npcBuildStep({world,player:p,act:input=>act(p,input)});}
  catch(error){b.savedBuildRetryAt=world.now()+5000;throw error;}
  if(!changed){b.savedBuildFinished=true;return false;}
  b.savedBuildActions=Number(b.savedBuildActions||0)+1;b.savedBuildRetryAt=world.now()+650;
  b.activity='preparing owned equipment';return true;
 }
  async function train(p,b){const now=world.now();if(now<b.learnAt)return false;
   // The shared optional-action gate can reject this turn before any action is
   // submitted. Skip the costly owned-gear plan until it opens again; later
   // take() calls stop pacing optional work when no human remains online.
   const readyAt=optionalBuildPacer.nextAt();
   if(readyAt>now){let hasViewer=false;for(const q of world.players.values())if(human(q)){hasViewer=true;break;}if(hasViewer){b.learnAt=readyAt;return false;}}
   b.learnAt=now+5000;
  let built;try{built=await npcBuildStep({world,player:p,act:input=>optionalBuildAction(p,input)});}catch(error){if(error===optionalBuildDeferred){b.learnAt=now+200;return false;}throw error;}
  if(built){b.activity='improving my equipment and build';b.learnAt=world.now()+650;return true;}
  if(p.profile.skillPoints>0){const {engine}=ensureSkills(world,p),skills=Object.values(world.data.skillPacks?.[p.profile.classIndex]?.skills||{}).filter(s=>!s.hidden&&s.levels?.length&&engine.canLevel(s.index).ok).sort((a,b)=>Number(!!p.profile.skills[a.index])-Number(!!p.profile.skills[b.index])||(a.levels[0].reqLevel||0));for(const s of skills){try{await optionalBuildAction(p,{type:'learn',skillId:Number(s.index)});return true}catch(e){if(e===optionalBuildDeferred){b.learnAt=now+200;return false;}if(!e.status)throw e;}}}return false;
 }
 // A fighting NPC never reaches train(), so its per-level stat points stayed unspent for the whole fight. Spend them
 // between swings through the ordinary 'allocate' action (same spare-point rule and optional-work pacing as train()).
 // Formulas, damage and hit timing are untouched: only the point budget the character already owns is applied.
 async function spendSparePoints(p,b){if(!(p.profile.statPoints>0)||p._skills?.engine.busy)return false;const spare=npcSpareStatPlan(world.data,p.profile);if(!spare)return false;
  try{await optionalBuildAction(p,{type:'allocate',...spare});}catch(error){if(error===optionalBuildDeferred)return false;throw error;}b.activity='spending stat points';return true;}
 async function fight(p,b,m,{forced=false}={}){if(await spendSparePoints(p,b))return true;const map=mapFor(world,p),reach=Math.min(8,p.stats.attackRange||5)+.3,edge=m.isBrick&&objectHitPoint(map,p,m),aim=edge||m.isBrick&&map.nearest(m.x,m.z)||m;
  if(distance(p,aim)>reach||!edge&&map.collision?.lineOfSight&&!map.collision.lineOfSight(p.x,p.z,m.x,m.z)){b.activity='approaching an enemy';return move(p,aim);}
  b.combatDecisionUntil=world.now()+2000;
  if(!npcCombatAttemptReady(world,p,b,m)){b.activity='waiting for combat command retry';return true;}
  const isPlayer=world.players.get(m.account)===m;
  if(await npcCombatPreparation(world,p,b,act,{target:m,isPlayer})){b.activity='preparing for the fight';return true;}
  const learned=npcCombatSkills(world,p,b,m,{isPlayer,forced}).sort((a,q)=>Number(!!b.questSkills?.includes(q.skill.index))-Number(!!b.questSkills?.includes(a.skill.index)));
  let attempts=0;
  // LANE2: authored skill reach exceeds the distance -> close in through ordinary navigation instead of an out-of-range cast.
  const approach=!learned.length&&b.combatApproach?.targetId===m.id&&world.now()-b.combatApproach.at<2000&&npcCombatIntelEnabled(world)&&b.combatApproach;
  if(approach&&npcCombatSkillReady(b,world.now())){const d=distance(p,m),want=Math.max(1,(approach.reach??Math.min(2.5,d))-.5);if(d>want+.2){b.activity='closing to skill range';return move(p,{x:m.x+(p.x-m.x)*want/d,z:m.z+(p.z-m.z)*want/d});}}
  if(npcCombatSkillReady(b,world.now()))for(const row of learned){const {skill:s,engine}=row,t=row.intelTarget||m;if(!engine.usability(s.index).ok)continue;if(attempts++>=NPC_COMBAT_ATTEMPTS)break;try{await act(p,{type:'cast',skillId:Number(s.index),targetId:t.id,x:t.x,z:t.z,...(forced?{forced:true}:{})});b.skillReady=world.now()+npcCombatCadence(p,b,world.now());npcRememberCombatStart(p,b,t,engine,forced);if(npcCombatIntelEnabled(world))npcIntelNoteCast(world,p,row,t,b);b.activity='using a combat skill';return true}catch(e){if(!e.status)throw e;if(npcCombatRefusal(world,p,b,t,Number(s.index),e)){b.activity='waiting for combat command retry';return true;}}}
  if(world.now()>=p.attackAt){
   const input={type:'attack',targetId:m.id,...(forced?{forced:true}:{})},now=world.now();
   // The average damage slot alone does not describe uneven authored combo hits. Wait for
   // the same phase admission the host uses; never send a knowingly premature bot attack.
   try{previewAttackStep(world,p,attackStepFor(world,p,input,now),now);}catch(error){if(error.status!==429)throw error;b.activity='waiting for the next attack';return false;}
   await act(p,input);b.activity='fighting';return true;
  }return false;
 }
 async function collectNearby(p,b,{onlyNear=false}={}){const now=world.now(),drops=groundDrops(world,p.map,p.instanceId,p.channel).filter(d=>npcLootEligible(world,p,b,d,now)&&distance(p,d)<(onlyNear?3:15)).sort((a,q)=>distance(p,a)-distance(p,q));if(!drops[0])return false;b.activity='collecting loot';if(distance(p,drops[0])<=3){try{await act(p,{type:'pickup',dropId:drops[0].id});}catch(e){if(!e.status)throw e;npcLootRefused(b,drops[0],e,world.now());return false;}}else return move(p,drops[0]);return true;}
 async function objective(p,b,goal){if(!goal||goal.blockedReason)return false;b.activity=goal.stage;if(await npcEventSupport(world,p,b,act,goal))return true;if(goal.waiting){if(goal.stage==='preparing during dungeon countdown'&&world.now()>=b.supportAt){b.supportAt=world.now()+5000;await npcSupport(world,p,act,{buff:true});}return true;}if(goal.targetId){if(await collectNearby(p,b,{onlyNear:true}))return true;if(goal.validate&&!goal.validate())return true;const m=mapFor(world,p)?.monsters.get(goal.targetId);if(m&&!m.dead)await fight(p,b,m);return true;}if(goal.action?.operation==='exit'&&await collectNearby(p,b))return true;if(goal.action){const token=p.token,flight=act(p,goal.action);b.objectiveFlight=flight;if(capacityPolicy){try{await flight;}finally{if(b.objectiveFlight===flight)b.objectiveFlight=null;}}else void flight.catch(e=>{if(world.players.get(p.account)===p&&p.token===token&&brains.get(p.account)===b){b.lastError=e.message;if(!e.status)onError(e);b.next=world.now()+2000;}}).finally(()=>{if(b.objectiveFlight===flight)b.objectiveFlight=null;});}else if(goal.at)await move(p,goal.at);return true;}
 const cityDutyPlanner=createNpcCityDutyPlanner({preference:npcArchetypeCityPreference(()=>world.now())});let cityDuties=new Map(),cityDutyAt=-Infinity;
 const cityRequester=createNpcCityRequester({now:world.now,live:(p,h)=>world.players.get(p.account)===p&&!p.dead&&!p.leaving&&p.map===150&&!p.instanceId&&world.players.get(h.account)===h&&!h.dead&&!h.leaving&&sameScene(p,h)});
 async function cityRequest(p,b){
  if(!npcCityBeggarIdentity(p))return false;
  const nearby=[...world.players.values()].filter(h=>human(h)&&!h.dead&&!h.sceneTransition&&sameScene(p,h)&&distance(p,h)<=15).sort((a,q)=>distance(p,a)-distance(p,q));
  const turn=cityRequester.step(p,{valid:cityEligible(p,b)&&!p.pcShopOpen&&(!p.profile.npcMerchant||p.profile.npcMerchant.phase==='cooldown')&&!b.routeGoal&&(!p.path.length||!!b.cityRequestMoving&&!!moveIntents.get(p)?.cityRequest),canRequest:world.now()>=b.chatReady&&world.now()>=(b.quietUntil||0),humans:nearby});
  if(!turn)return false;
  if(turn.kind==='finish'){if(b.cityRequestMoving&&p.path.length&&moveIntents.get(p)?.cityRequest)await act(p,{type:'stop'});delete b.cityRequestMoving;return false;}
  if(turn.kind==='request'){await say(p,b,turn.text);b.next=world.now()+1000;return true;}
  if(distance(p,turn.target)>4){await move(p,npcFollowPoint(p,turn.target,b,3));const intent=moveIntents.get(p);if(intent){intent.cityRequest=true;b.cityRequestMoving=true;}}
  b.next=world.now()+1000;return true;
 }
 function cityEligible(p,b){return !!background&&npcCityDutyEligible(p,b,{protectedActor:eventTeams.retains(p)||eventTeams.handles(p)||populationWorkers?.owns(p)||npcPendingHumanInvite(world,p,human)||world.partyInvites.has(p.id)||fishingHook.protected(p)||!!b.desiredChannel||!!b.organizerUntil&&world.now()<b.organizerUntil});}
 function cityDuty(p,b){if(!cityEligible(p,b))return null;const now=world.now();if(!cityDutyPlanner.assigned(p)||now<cityDutyAt||now-cityDutyAt>=1000){cityDutyAt=now;cityDuties=cityDutyPlanner.update([...brains].map(([id,b])=>[world.players.get(id),b]).filter(([p])=>p),{eligible:cityEligible});}return cityDuties.get(p.account)||null;}
 async function quietCityRest(p,b){
  if(cityDuty(p,b)!=='rest'||p.pcShopOpen||p.profile.npcMerchant&&p.profile.npcMerchant.phase!=='cooldown')return false;
  const map=mapFor(world,p),row=world.data.mapRow?.(p.map);if(!map||Number(row?.PeaceZone)!==1||Number(row?.PcStore)!==1||p.attackTarget||[...map.monsters.values()].some(m=>!m.dead&&m.targetId===p.id))return false;
  b.activity='taking a short break';b.target=null;b.farmTarget=null;
  const parking=npcTownIdlePlan({world,player:p,brain:b,isHuman:human});
  if(parking){b.idleTownPlan=parking;if(!parking.near){await toward(p,parking.at);b.next=world.now()+1000;return true;}}
  // Accepted unrelated movement retains custody. A rest policy cannot stop it.
  if(p.path.length)return false;
  if(!p.sitting)await act(p,{type:'emote',motion:'sit'});
  b.next=world.now()+NPC_CITY_DUTY_POLICY.maintenanceMs;b.cityQuietUntil=b.next;return true;
 }
 async function think(p,b){const now=world.now();
  npcSettleQueuedCadence(world,p,b,npcCombatCadence);
  if(!b.activityRestored&&!b.taskGoal){
  const savedRoutine=p.profile.npcRoutine,restoreParty=p.partyId&&world.parties.get(p.partyId),restoreInvite=world.partyInvites.get(p.id),restoreInviter=actor(world.parties.get(restoreInvite?.party)?.leader);
  if(world.players.get(p.account)===p&&p.profile.authority==='server'&&p.profile.npcPlayer===true&&!p.leaving&&!p.dead&&!p.commandActive&&!p.progressCommitting&&!p.sceneTransition&&!b.objectiveFlight&&!p.tradeId&&!p.pcShopOpen&&!p.instanceId&&!isDkChannel(p.channel)&&mapFor(world,p)?.index===p.map&&p.profile.map===p.map&&!['wait','follow','lure'].includes(b.mode)&&!human(actor(b.follow))&&!restoreParty?.members.some(id=>human(actor(id)))&&!(restoreInvite?.expires>now&&human(restoreInviter))&&!npcPendingHumanInvite(world,p,human)&&!eventTeams.handles(p)&&!eventTeams.retains(p)&&!b.questId&&!Object.keys(p.profile.quests?.active||{}).length&&savedRoutine?.version===2&&savedRoutine.map===p.map&&['farm','merchant'].includes(savedRoutine.kind))npcAssignActivity(world,p,b);
  }
 npcRoutineWork(world,p,b,{paused:cityDuty(p,b)==='rest'&&!p.pcShopOpen&&(!p.profile.npcMerchant||p.profile.npcMerchant.phase==='cooldown')});if(now<b.next||b.objectiveFlight||p.commandActive||p.sceneTransition||p.progressCommitting)return;decisionCount++;lastDecisionAt=now;b.next=now+npcDecisionDelay(p,b,policy,now);p.lastSeen=now;
  b.cityQuietUntil=0;
  const fishingTurn=await fishingHook.maintain(p,b);b.fishingReserved=fishingTurn.reserve;if(fishingTurn.hold){b.activity='finishing an owned fishing objective';return;}
  // Information can be typed alongside ordinary gear/service work. Native
  // commands/commits above still serialize; only accepted action requests
  // need the existing interruption/restoration path further below.
  const firstMessage=b.queue[0];
  if(firstMessage&&!p.dead&&now>=b.chatReady&&now>=(firstMessage.replyAt??firstMessage.at+1500)&&!['follow','stop','roam','lure','party','prepare','pvp'].includes(dialogueIntent(firstMessage.text)))await conversation(p,b,b.queue.shift());
  if(!p.dead&&eventTeams.attending(p)&&!b.queue.some(msg=>human(actor(msg.speaker)))){b.activity='attending the native Chain of Fire event';return;}
  if(b.homeScene!==sceneKey(p.map,p.instanceId,p.channel)){b.home={x:p.x,z:p.z};b.homeScene=sceneKey(p.map,p.instanceId,p.channel);}
  if(!p.instanceId&&(p.profile.npcSeed.map!==p.map||p.profile.npcSeed.channel!==(p.channel||0))){p.profile.npcSeed={...p.profile.npcSeed,map:p.map,channel:p.channel||0};b.home={x:p.x,z:p.z};world.changed(p);}
  // Keep owned service inputs reserved until completion or interruption.
  // Cancel before private objectives, merchant work or training, then restore
  // the same UID through ordinary equip before an alive actor resumes play.
  if(!b.fishingReserved&&!p.dead&&p.profile.npcEquipment?.phase==='working'){
   const crew=p.partyId&&world.parties.get(p.partyId),leader=actor(crew?.leader),explicit=actor(b.follow),invite=world.partyInvites.get(p.id),inviter=actor(world.parties.get(invite?.party)?.leader);
   const request=b.queue.some(m=>{const sender=actor(m.speaker),intent=dialogueIntent(m.text);return sender&&human(sender)&&['follow','lure','party','stop','roam'].includes(intent)&&npcRequestDecision({world,player:p,brain:b,requester:sender,intent}).accept;});
   const cancel=!!p.instanceId||!!leader&&leader!==p&&human(leader)||!!explicit&&human(explicit)||!!inviter&&human(inviter)&&npcWantsParty(p)||request,restore=p.profile.npcEquipment.plan;
   const services=await npcEquipmentServiceStep({world,player:p,brain:b,act,approachPlan:serviceApproach,requested:false,cancel});
   if(services.handled){b.activity='improving owned equipment';if(services.plan&&!services.plan.near)await toward(p,services.plan.at);return;}
   if(services.status==='interrupted'&&restore?.slot!=null&&p.profile.inventory?.some(i=>i.uid===restore.uid))await act(p,{type:'equip',uid:restore.uid,slot:restore.slot});
  }
  if(!b.fishingReserved&&!p.dead&&b.refineRestore){
   const restore=b.refineRestore,crew=p.partyId&&world.parties.get(p.partyId),leader=actor(crew?.leader),escort=actor(b.follow),invite=world.partyInvites.get(p.id),inviter=actor(world.parties.get(invite?.party)?.leader);
   const request=b.queue.some(m=>{const sender=actor(m.speaker),intent=dialogueIntent(m.text);return sender&&human(sender)&&['follow','lure','party','stop','roam'].includes(intent)&&npcRequestDecision({world,player:p,brain:b,requester:sender,intent}).accept;});
   const cancel=Boolean(p.instanceId)||Boolean(leader&&leader!==p&&human(leader))||Boolean(escort&&human(escort))||Boolean(inviter&&human(inviter)&&npcWantsParty(p))||request;
   const originalPending=cancel||restore.completed?null:npcRefinementPlan(world,p,{uid:restore.uid}),pending=originalPending&&serviceApproach({player:p,plan:originalPending});
   if(originalPending&&!pending){b.activity='waiting for a free native smith approach';return;}
   if(!pending){if(p.profile.inventory?.some(i=>i.uid===restore.uid))await act(p,{type:'equip',uid:restore.uid,slot:restore.slot});b.refineUid=null;b.refineRestore=null;}
   else if(pending.near){if(pending.stage!=='remove')b.refineRestore={...restore,completed:true};await act(p,pending.action);if(pending.stage!=='remove'){b.refineUid=null;b.serviceAt=now+15000;if(p.profile.inventory?.some(i=>i.uid===restore.uid))await act(p,{type:'equip',uid:restore.uid,slot:restore.slot});b.refineRestore=null;}return;}
   else{b.activity='finishing an owned refinement';await toward(p,pending.at);return;}
  }
  const inside=privateAudience(p);if(inside){if(!inside.participants.length&&(inside.run.kind==='dungeon'||!canonicalNpc(p)||!inside.run.members?.has(p.id)||!inside.run.admitted?.has(p.characterId))){if(p.dead){await leaveNpc(p.account,p.token);cancelActor(p);brains.delete(p.account);return;}if(await collectNearby(p,b))return;b.activity='leaving after the party';await act(p,{type:inside.run.kind==='dungeon'?'dungeon':'event',operation:'exit'});return;}if(inside.participants.length&&inside.participants.every(h=>h.dead)){b.activity='waiting for a teammate to revive';if(p.path.length&&!p.dead)await act(p,{type:'stop'});return;}}
  if(p.dead){if(!b.deadSeen){b.frustratedUntil=now+30000;b.deadReadyAt=Number.isFinite(p.respawnReadyAt)?p.respawnReadyAt:now+ORDINARY_RESPAWN_WAIT_MS;}b.deadSeen=true;b.activity='recovering';if((await npcPvpStep(world,p,b,{act,isNpc:bot})).handled)return;if(now<b.deadReadyAt)return;
   // ENGINE-CHOSEN (3.1.2): an ordinary revive inside a running native party
   // war leaves the event. While a living teammate of this party is still in
   // the war, wait for its resurrection or the native final-battle revival.
   {const war=p.instanceId&&world.instances?.get(p.instanceId);if(war&&nativeEventParticipant(p,war)&&!war.closeRequested&&!war.run?.ended&&war.run?.won==null&&p.partyId&&[...world.players.values()].some(q=>q!==p&&!q.leaving&&!q.dead&&q.instanceId===p.instanceId&&q.partyId===p.partyId)){b.activity='waiting for the team to revive me';return;}}
   await act(p,{type:'revive'});return;}b.deadSeen=false;delete b.deadReadyAt;
  if(b.desiredChannel&&(p.channel||0)!==b.desiredChannel){b.activity='changing channels';if(p.smartWarp?.kind==='channel'){if(now>=p.smartWarp.readyAt)await act(p,{type:'channel',operation:'movefinish',nonce:p.smartWarp.nonce});}else await act(p,{type:'channel',operation:'move',channel:b.desiredChannel});return;}
  if(b.desiredChannel&&(p.channel||0)===b.desiredChannel)b.desiredChannel=0;
  if(b.queue.length&&now>=b.chatReady&&now>=(b.queue[0].replyAt??b.queue[0].at+1500)){await conversation(p,b,b.queue.shift());return;}
  // An accepted movement/party request already cancelled owned service work.
  // Reserve that decision while its reply is being typed; do not unequip the
  // restored item or start another independent objective during the delay.
  const pendingPlan=b.queue.some(msg=>{const other=actor(msg.speaker),intent=dialogueIntent(msg.text);return other&&human(other)&&now-msg.at<=20000&&['follow','lure','party','stop','roam'].includes(intent)&&(msg.channel!=='party'||msg.partyId&&p.partyId===msg.partyId&&other.partyId===msg.partyId)&&npcRequestDecision({world,player:p,brain:b,requester:other,intent}).accept;});
  if(pendingPlan){b.activity='finishing a reply';if(p.path.length&&!p._skills?.engine.casting)await act(p,{type:'stop'});return;}
  const groupTurn=groupChat.take(p,{quietUntil:b.quietUntil||0,chatReady:b.chatReady});
  if(groupTurn){try{const before=world.sequence;if(groupTurn.channel==='party'){if(p.partyId===groupTurn.partyId&&world.parties.get(groupTurn.partyId)?.members.includes(p.id)&&now>=b.chatReady){b.chatReady=now+2500;await act(p,{type:'party',operation:'chat',text:groupTurn.text});}}else await say(p,b,groupTurn.text,{localized:true});groupChat.finish(groupTurn,world.events.some(e=>e.sequence>before&&e.actorId===p.id&&e.type==='chat'&&e.channel===groupTurn.channel&&e.text===groupTurn.text));}catch(error){groupChat.finish(groupTurn,false);throw error;}}
  // ENGINE-CHOSEN contextual speech observes actual native PK evidence. It
  // never changes hostility, wanted state, party membership or combat goals.
  const pkScene=sceneKey(p.map,p.instanceId,p.channel);
  if(!b.queue.length&&now>=b.chatReady&&now>=(b.quietUntil||0)&&now>=(socialScenes.get(pkScene)||0)&&(b.pkSocialHit||now>=(b.pkSocialScanAt||0))){
   b.pkSocialScanAt=now+15000;
   const visiblePlayers=[...world.players.values()].filter(q=>q!==p&&!q.leaving&&sameScene(p,q)&&distance(p,q)<=policy.chatDistance).map(q=>world.snapshotPublicPlayer(q));
   const decision=npcPkSocialDecision(world,p,b,{hit:b.pkSocialHit,visiblePlayers});delete b.pkSocialHit;
   if(decision){const text=localSpeech(decision.text),before=world.sequence;await say(p,b,text,{localized:true});if(world.events.some(e=>e.sequence>before&&e.actorId===p.id&&e.type==='chat'&&e.channel==='normal'&&e.text===text)){b.pkSocial=decision.memory;socialScenes.set(pkScene,now+60000);}}
  }
  if(world.partyInvites?.has(p.id)){const willing=npcWantsParty(p);await act(p,{type:'party',operation:willing?'accept':'decline'});if(willing){const party=world.parties.get(p.partyId);b.follow=party?.leader;b.partyFollow=true;b.mode='follow';b.prepareUntil=now+10000;}else await say(p,b,'Thanks, but I am running solo for a bit.');return;}
  const pendingCommerce=b.queue.some(msg=>{const c=b.memory.get(msg.speaker)?.commerceConversation;return msg.directed&&(npcCommerceConversationIntent(msg.text)||c?.teacher===p.id&&c.requester===msg.speaker&&c.until>now);});
  if(!b.fishingReserved&&!pendingCommerce){const commerce=await npcCommerceStep({world,player:p,brain:b,act,allowPartyGift:true,giftConsent:(requester,trade)=>npcCommerceGiftConsent({world,player:p,requester,memory:memory(b,requester.id),trade})});if(commerce.handled)return;}
  if(!b.fishingReserved)await npcCommerceAdvertise({world,player:p,brain:b,act,enabled:enabled(),channel:(p.profile.npcSeed?.slot||0)%4===0?'world':'shout'});
  if(now<(b.pauseUntil||0))return;
  if(npcPendingHumanInvite(world,p,human)){b.activity='waiting for a party reply';if(p.path.length)await act(p,{type:'stop'});return;}
  if(npcCombatIntelEnabled(world)){const survival=await npcIntelSurvival(world,p,b,act);if(survival){b.activity=survival==='potion'?'using a recovery potion':'using a defensive skill';return;}}else if(await npcRecovery(world,p,act)){b.activity='using a recovery potion';return;}
  const explicitLeader=b.closeFollow&&b.mode==='follow'&&actor(b.follow),explicitMap=explicitLeader&&mapFor(world,p);
  // Explicit Follow can cancel the same ACTION phases as ordinary movement.
  // Hard casts and every native movement/control check still own the actor.
  if(p._skills?.engine.casting&&!explicitLeader)await npcRequestNextSkill(world,p,b,act);
  if(p._skills?.engine.casting&&(!explicitLeader||!human(explicitLeader)||!sameScene(p,explicitLeader)||!explicitMap||p._skills.engine.busy)){b.activity='finishing a skill';return;}
  // Accepted explicit Follow is movement, including while a mob train is near.
  // Native speed, collision, control effects and event admission still apply;
  // autonomous preparation/combat must not repeatedly strand this follower.
  if(explicitLeader&&human(explicitLeader)&&sameScene(p,explicitLeader)&&explicitMap){
   const follow=npcFollowPlan(p,explicitLeader,b,{map:explicitMap,now});
   if(follow?.kind==='move'){b.activity='following closely';await move(p,follow.at,{tight:true});return;}
   if(follow?.kind==='continue'){b.activity='following closely';return;}
   if(follow?.kind==='stop'){await act(p,{type:'stop'});moveIntents.delete(p);}
   if(follow){b.activity='waiting beside the party';if(now<(b.prepareUntil||0)&&now>=b.supportAt){b.supportAt=now+5000;await npcSupport(world,p,act,{buff:true});}return;}
  }
  if(await cityRequest(p,b))return;
  if(await quietCityRest(p,b))return;
  const warEnemy=npcGuildWarTarget(world,p,b,guildOptions);if(warEnemy){b.activity='fighting with the guild';await fight(p,b,warEnemy);return;}
  const pvp=await npcPvpStep(world,p,b,{act,isNpc:bot});if(pvp.handled){if(pvp.target){b.activity='fighting another player';await fight(p,b,pvp.target,{forced:pvp.forced});}else if(now>=b.supportAt){b.supportAt=now+5000;await npcSupport(world,p,act,{buff:true});}return;}
  const recruitScene=sceneKey(p.map,p.instanceId,p.channel);
  if(!p.attackTarget&&!p.tradeId&&!p.pcShopOpen&&!b.queue.length&&now>=b.chatReady&&now>=(b.gatheringAdvertAt||0)&&now>=(socialScenes.get(recruitScene)||0)&&[...world.players.values()].some(q=>human(q)&&!q.dead&&sameScene(p,q)&&distance(p,q)<=policy.chatDistance)){
   b.gatheringAdvertAt=now+180000;
   const recruitment=npcGatheringRecruitment({world,player:p,brain:b,now});
   if(recruitment){socialScenes.set(recruitScene,now+60000);await say(p,b,recruitment.text);}
  }
  if(eventTeams.handles(p)){b.prepareUntil=now+12000;if(now>=b.supportAt){b.supportAt=now+5000;if(await npcSupport(world,p,act,{buff:true}))b.activity='preparing for the timed event';}return;}
  const canAssistEvent=q=>{const brain=brains.get(q.account);return !!brain&&!brain.queue?.length&&!['wait','lure'].includes(brain.mode)&&!brain.closeFollow&&(!brain.follow||brain.partyFollow)&&!human(actor(brain.follow))&&!npcPendingHumanInvite(world,q,human);};
  const nativeObjective=npcDeadFrontObjectivePlan(world,p,{isNpc:bot,canAssist:canAssistEvent})||npcDungeonObjectivePlan(world,p,{isNpc:bot}),objectiveTarget=nativeObjective?.targetId&&mapFor(world,p)?.monsters.get(nativeObjective.targetId);
  // Pulling may replace only a live ordinary combat phase. Authored channels,
  // scripts, countdowns, doors, statues, exits and unsupported phases win.
  const privatePull=b.mode==='lure'&&objectiveTarget&&!objectiveTarget.isBrick&&!objectiveTarget.eventObject&&objectiveTarget.def?.role==='creature';
  if(!privatePull&&await objective(p,b,nativeObjective))return;
  const party=p.partyId&&world.parties?.get(p.partyId);
  const guided=questAssistance.plan(p);
  if(guided&&!guided.cancelled){b.activity=guided.stage;b.questId=guided.questId;if(guided.waiting){if(guided.stop){await act(p,{type:'stop'});moveIntents.delete(p);}return;}if(await collectNearby(p,b))return;if(guided.action){await act(p,guided.action);return;}if(guided.targetId){const enemy=mapFor(world,p)?.monsters.get(guided.targetId);if(enemy&&!enemy.dead){await fight(p,b,enemy);return;}}if(guided.at){await toward(p,guided.at);return;}}
  if(b.partyFollow){if(!party){b.partyFollow=false;b.follow=null;b.mode='roam';delete b.followMotion;npcTeamForget(b);npcNavForget(b);}else b.follow=party.leader;}
  if(!party&&b.teamPull)npcTeamForget(b);
  const leader=actor(b.follow||party?.leader),map=mapFor(world,p);if(!map)return;
  const humanEscort=leader&&leader!==p&&human(leader),merchant=b.fishingReserved?{handled:false}:await npcMerchantStep({world,player:p,brain:b,act,cancel:!!humanEscort||!!p.instanceId,requested:false});if(merchant.handled){if(merchant.plan&&!merchant.plan.near)await toward(p,merchant.plan.at);if(merchant.status==='holding native stall'&&cityDuty(p,b)==='shop'){b.next=now+NPC_CITY_DUTY_POLICY.maintenanceMs;b.cityQuietUntil=b.next;}return;}
  if(now<(b.organizerUntil||0)){const h=actor(b.organizerHuman),plan=npcOrganizerPlan(world,p,{humanInitiator:h});if(plan){b.activity='gathering for DK Square';if(plan.near)await npcOrdinaryOrganizerStep(world,p,b,act,{humanInitiator:h});else await toward(p,plan.at);return;}}
  let immediateThreat=npcImmediateThreat(world,p,map,party,{lookup:actor,current:b.intelFocus});
  // LANE3: bot-only field parties (never human-led/escort, lure or towns): role target (peel / assist / leader commit) becomes the
  // immediate threat; followers move to formation slots, fall back to the party when attacked far away, or yield the leader's path.
  const teamStep=!humanEscort&&b.mode!=='wait'&&b.mode!=='lure'&&leader&&party&&npcTeamEnabled(world)?npcTeamMemberStep(world,p,b,{party,lookup:actor,map,brainOf:q=>brains.get(q.account),immediateThreat}):null;
  if(teamStep?.fight)immediateThreat=teamStep.fight;
  const urgent=!!immediateThreat,teamFollower=!!teamStep&&leader!==p;
  if(teamStep?.move&&(!urgent||teamStep.urgent)){b.activity=teamStep.kind==='fallback'?'falling back to the party':'keeping formation';await move(p,teamStep.move);return;}
  if(humanEscort&&b.mode==='follow'&&sameScene(p,leader)&&!urgent){
   // Settling must not suppress a finite explicit preparation request. Native
   // support selects only legal useful effects and retains party recipients.
   if(now<(b.prepareUntil||0)&&now>=b.supportAt){b.supportAt=now+5000;if(await npcSupport(world,p,act,{buff:true})){b.activity='preparing with the party';return;}}
   const follow=npcFollowPlan(p,leader,b,{map,now});
   if(follow?.kind==='move'){b.activity='following the party';await move(p,follow.at);return;}
   if(follow?.kind==='continue'){b.activity='following the party';return;}
   if(follow?.kind==='stop'){await act(p,{type:'stop'});moveIntents.delete(p);}
   if(follow){b.activity='waiting with the party';return;}
  }
  // Do not stop an escort to cycle through every learned buff or train in town.
  if(!teamFollower&&!humanEscort&&!urgent&&b.mode!=='wait'&&b.mode!=='lure'&&leader&&leader!==p&&sameScene(p,leader)&&!leader.path.length){const spaced=npcTownPartyPlan(world,p,leader);if(spaced){b.activity='waiting near the party';if(!spaced.near)await move(p,spaced.at);else if(p.path.length)await act(p,{type:'stop'});return;}}
  if(!teamFollower&&leader&&leader!==p&&b.mode!=='wait'&&b.mode!=='lure'&&sameScene(p,leader)&&distance(p,leader)>policy.followDistance&&!urgent){b.activity='following the party';await move(p,npcFollowPoint(p,leader,b));return;}
  const prePull=[...map.monsters.values()].some(m=>!m.dead&&!m.isBrick&&!m.eventObject&&distance(p,m)<20&&Math.abs((m.def.level||1)-p.profile.level)<=8);
  if(npcCombatIntelEnabled(world)&&await npcIntelUrgentSupport(world,p,b,act,npcAllies(world,p))){b.activity='healing the team';return;}
  if(now>=b.supportAt){b.supportAt=now+5000;if(await npcSupport(world,p,act,{buff:now<(b.prepareUntil||0)||prePull&&!urgent})){b.activity='buffing and supporting the team';return;}}
  // ENGINE-CHOSEN survival priority: ordinary threats interrupt optional build,
  // service and routine decisions. Native recovery/support and authored private
  // objectives above keep their priority; combat still uses ordinary validation.
  if(immediateThreat){await fight(p,b,immediateThreat);return;}
  if(await prepareSavedStock(p,b))return;
  if(leader&&leader!==p&&b.mode!=='wait'){
   if(p.instanceId&&!leader.instanceId){const i=world.instances?.get(p.instanceId);if(i?.kind==='dungeon'||['deadFront','iceCastle'].includes(i?.kind)){await act(p,{type:i.kind==='dungeon'?'dungeon':'event',operation:'exit'});return;}}
   if(!p.instanceId&&!leader.instanceId&&p.map===leader.map&&(p.channel||0)!==(leader.channel||0)&&!isDkChannel(leader.channel)){if(p.smartWarp?.kind==='channel'){if(now>=p.smartWarp.readyAt)await act(p,{type:'channel',operation:'movefinish',nonce:p.smartWarp.nonce});}else await act(p,{type:'channel',operation:'move',channel:leader.channel||0});return;}
   if(!sameScene(p,leader)){if(!p.instanceId&&!leader.instanceId)await toward(p,{map:leader.map,x:leader.x,z:leader.z,channel:leader.channel||0});return;}
   if(b.mode==='lure'){
    const pull=npcPullPlan({world,player:p,brain:b,leader,now});if(pull?.handled){b.activity=pull.stage;if(pull.callout?.partyId===p.partyId&&party?.members.includes(p.id)&&now>=b.chatReady){b.chatReady=now+2500;await act(p,{type:'party',operation:'chat',text:pull.callout.text});}if(pull.prepare)await npcSupport(world,p,act,{buff:true});else if(pull.at)await move(p,pull.at);else if(pull.targetId){const target=map.monsters.get(pull.targetId);if(target&&!target.dead)await fight(p,b,target);}if(pull.complete){b.mode='follow';delete b.pull;}return;}
   }
   const threats=[...map.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&party?.members.includes(m.targetId)).sort((a,b)=>distance(p,a)-distance(p,b));if(threats[0]&&distance(p,threats[0])<30){await fight(p,b,threats[0]);return;}
   if(teamFollower){b.activity='waiting with the party';return;}
   if(distance(p,leader)>policy.followDistance){b.activity='following the party';await move(p,npcFollowPoint(p,leader,b));return;}
  }
  if(b.fishingReserved){if(urgent&&immediateThreat)await fight(p,b,immediateThreat);b.activity='owned fishing cleanup pending';return;}
  if(b.mode==='wait'){b.activity='waiting';return;}
  // Saved crowd piles yield through ordinary collision-checked movement.
  // Human-led movement, active native work and seated shops were handled first.
  if(!humanEscort&&!urgent){const yielding=npcTownYieldPlan(world,p);if(yielding&&!yielding.near){b.activity='making room in town';await move(p,yielding.at);return;}}
  // A finite owned-surplus shop pause precedes rest/training. Accepted native
  // quests remain in the profile and resume after the existing merchant dwell.
  if(!p.partyId&&!p.instanceId&&!humanEscort&&npcMerchantOpportunity(world,p,b,{allowQuestPause:true})){
   const market=await npcMerchantStep({world,player:p,brain:b,act,requested:true});
   if(market.handled){b.activity=market.plan&&!market.plan.near?'walking to an owned personal shop':'selling owned drops in Ardeca';if(market.plan&&!market.plan.near)await toward(p,market.plan.at);return;}
  }
  const guildLife=await npcGuildLifeStep(world,p,b,{...guildOptions,socialProfileSupported:world.npcSocialProfileSupported===true,act,move:(member,at)=>toward(member,at)});if(guildLife.handled){b.activity=guildLife.plan?.at&&!guildLife.plan.near?'visiting the guild master':'organizing with the guild';return;}
  if(now>=(b.friendAt||0)){b.friendAt=now+30000;const friend=npcFriendHumans(world,p,human).find(q=>now>=(memory(b,q.id).friendReady||0));if(friend){memory(b,friend.id).friendReady=now+600000;const canPull=npcCanDiscussPull(world,p,b,mapFor(world,p));const lines=['Hey, up for a run?','I am '+b.activity+'. Want to team up later?',canPull?'Quick reminder: check potions before the next pull.':'How is your run going?'],index=Math.floor(world.random()*lines.length),text=localSpeech(lines[index]).slice(0,60),since=world.sequence,spoken=await say(p,b,text,{localized:true,channel:'messenger',targetName:friend.profile.name});if(index===0)npcRememberConversationOffer({world,player:p,requester:friend,memory:memory(b,friend.id),offer:{type:'party'},channel:'messenger',delivered:spoken?.events?.some(e=>e.type==='messenger'&&e.actorId===p.id&&e.text===text&&e.sequence>since&&e.targetId===friend.id&&e.recipients?.includes(friend.id))===true});return;}}
  const fishingStart=await fishingHook.start(p,b);if(fishingStart.hold){b.activity='taking a finite fishing opportunity';return;}
  const task=npcAssignActivity(world,p,b,{duty:cityDuty(p,b)});
  // ENGINE-CHOSEN minority market intention after observed farm work. Reserve
  // actual sale UIDs only while a native affordable return-to-market is valid.
  // The finite durable reservation never adds inventory, money or progress.
  const marketIntent=!leader&&!p.instanceId&&!p.partyId&&(task.kind==='merchant'||task.kind==='farm'&&Number(p.profile.npcSeed?.slot)%4===0&&task.version===2&&task.workedMs>=task.durationMs/2)?`market:${task.map}:${task.cycle}:${Math.trunc(task.started)}`:null;
  const heldMarket=marketIntent||p.profile.npcMerchantReservation?.phase==='held'?await npcMerchantReservationStep({world,player:p,intentKey:marketIntent,cancel:!!humanEscort}):null;
  b.merchantIntentKey=marketIntent;
  // A saved solo onward intention survives subsequent decisions. Accepted
  // quests, invitations, parties and explicit escort work keep their authority.
  if(b.forwardGoal&&Number(b.forwardGoal.destinationMap)===p.map)delete b.forwardGoal;
  if(b.forwardGoal&&!(p.map!==150&&heldMarket?.uids.size)&&!leader&&!p.instanceId&&!p.partyId&&!b.questId&&!Object.keys(p.profile.quests?.active||{}).length&&!world.partyInvites.has(p.id)&&!p.tradeId&&!p.pcShopOpen){
   if(now>=b.forwardGoal.until&&!p.path.length){delete b.forwardGoal;b.freeplayState={...b.freeplayState,retryAt:now+15000};delete b.freeplayState.destinationMap;publishFreeplay(p,b,{nextState:b.freeplayState});}
   else{if(now<b.forwardGoal.retryAt){await recoverOnwardTownWait(p,b);return;}b.activity='heading to the next leveling area';if(!await toward(p,{map:b.forwardGoal.destinationMap})){b.forwardGoal.retryAt=now+15000;await recoverOnwardTownWait(p,b);}return;}
  }
  // Genuine surplus can fund a merchant's ordinary trip back to Ardeca.
  // Saved quests/inventory/levels remain intact; native gates, fares and map
  // admission still decide whether the route is currently possible.
  if((task.kind==='merchant'||heldMarket?.uids.size)&&!leader&&!p.instanceId&&p.map!==150&&npcMerchantOffers(world,p).length){const catalog=world.data.progression?.npcs,service=catalog?.placements?.[150]?.rows?.find(([id,x,z])=>[x,z].every(Number.isFinite)&&catalog.npcs?.[id]?.jobs?.some(([type])=>Number(type)===4));if(service){b.activity='bringing owned drops to market';if(await toward(p,{map:150,x:service[1],z:service[2]}))return;await npcMerchantReservationStep({world,player:p,intentKey:marketIntent,cancel:true});}}
  if(task.kind==='rest'&&(!leader||leader===p)&&!p.instanceId){b.activity='taking a short break';if(await generous(p,b))return;b.target=null;b.farmTarget=null;const parking=npcTownIdlePlan({world,player:p,brain:b,isHuman:human});if(parking){b.idleTownPlan=parking;if(!parking.near){await toward(p,parking.at);return;}}else delete b.idleTownPlan;if(p.path.length)await act(p,{type:'stop'});if(!p.sitting&&!urgent)await act(p,{type:'emote',motion:'sit'});return;}
  if(!p.instanceId&&!humanEscort&&await npcFieldTeam(world,p,b,{act,isNpc:bot,brains}))return;
  if(!leader&&!p.instanceId&&distance(p,b.home)>65&&!b.routeGoal&&!b.taskGoal){b.activity='returning to the local route';if(await move(p,b.home))return;}
  if(await train(p,b))return;
  if(await generous(p,b))return;
  if((!leader||leader===p)&&!p.instanceId){const services=await npcEquipmentServiceStep({world,player:p,brain:b,act,approachPlan:serviceApproach,requested:true});if(services.handled){b.activity='improving owned equipment';if(services.plan&&!services.plan.near)await toward(p,services.plan.at);return;}}
  if((!leader||leader===p)&&!p.instanceId){const supplies=await npcSupplyStep({world,player:p,brain:b,act,approachPlan:serviceApproach,requested:true});if(supplies.handled){b.activity='restocking potions';if(supplies.plan&&!supplies.plan.near)await toward(p,supplies.plan.at);return;}if(task.kind==='merchant'){const market=await npcMerchantStep({world,player:p,brain:b,act,requested:true});if(market.handled){if(market.plan&&!market.plan.near)await toward(p,market.plan.at);return;}}}
  if((!leader||leader===p)&&!p.instanceId&&now>=(b.serviceAt||0)){
   const bag=npcBagPressure(world,p),reservedSale=npcMerchantReservedSaleUids(world,p,{intentKey:b.merchantIntentKey});b.bagFill=bag.fill;
   const nativePlan=npcRefinementPlan(world,p,b.refineUid?{uid:b.refineUid}:{} )||(task.kind!=='merchant'&&npcSalePlan(world,p,{reservedUids:reservedSale,pressure:bag.pressure}))||(bag.full&&npcStoragePlan(world,p,{reservedUids:reservedSale})),plan=nativePlan&&serviceApproach({player:p,plan:nativePlan});
   if(plan){b.activity=plan.action.type==='shopsell'?'selling unused drops':plan.action.type==='storage'?'storing spare gear':'visiting a gear smith';if(plan.near){b.serviceAt=now+15000;await act(p,plan.action);b.refineUid=plan.stage==='remove'?plan.uid:null;b.refineRestore=b.refineUid?{uid:plan.uid,slot:plan.action.slot}:null;b.serviceAt=now+(b.refineUid?650:15000);}else if(await toward(p,plan.at))return;else b.serviceAt=now+15000;if(plan.near)return;}else{b.refineUid=null;b.serviceAt=now+15000;}
  }
  const socialScene=sceneKey(p.map,p.instanceId,p.channel);
  if(now>=b.socialAt&&!p.instanceId&&now>=(socialScenes.get(socialScene)||0)){b.socialAt=now+90000+npcConversationPhase(p.profile.npcSeed?.slot)*7000;
   const other=[...world.players.values()].find(q=>human(q)&&!q.dead&&sameScene(p,q)&&distance(p,q)<18&&!q.partyId&&!world.partyInvites?.has(q.id)&&now>=(memory(b,q.id).partyAskedAt||0));
   const eventOpen=other&&eventTeams.densityFor(other)>0,hasQuest=Object.keys(p.profile.quests?.active||{}).length>0,canPull=!!other&&npcCanDiscussPull(world,p,b,map);
   if(other&&(eventOpen||hasQuest||canPull)&&npcWantsParty(p)&&(!p.partyId||party?.leader===p.id&&party.members.length<7)){memory(b,other.id).partyAskedAt=now+600000;socialScenes.set(socialScene,now+60000);if(!p.partyId)await act(p,{type:'party',operation:'create',name:p.profile.name+' crew'});const invitation=eventOpen?'Hey, want to group for the upcoming event?':hasQuest?'Hey, want to work on a quest together?':'Hey, want to party for a few pulls?';const since=world.sequence,text=localSpeech(invitation),spoken=await say(p,b,text,{localized:true});npcRememberConversationOffer({world,player:p,requester:other,memory:memory(b,other.id),offer:{type:'party'},channel:'normal',delivered:spoken?.events?.some(e=>e.type==='chat'&&e.channel==='normal'&&e.actorId===p.id&&e.text===text&&e.sequence>since&&e.recipients?.includes(other.id))===true});return;}
  }
  if(await collectNearby(p,b))return;
  if(task.kind==='quest'||task.kind==='dungeon'||b.questId||leader&&leader!==p){if(await quest(p,b,leader&&leader!==p?leader:null))return;}
  const wanted=b.target,assigned=npcFarmEnemy(world,p,b,{brains,isNpc:bot});const enemies=[...map.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&!m.eventObject&&!['invisible','object','npc','trap'].includes(m.def.role)&&((m.id===wanted)||(task.kind!=='rest'&&m.id===assigned?.id)||(m.targetId===p.id&&distance(p,m)<25))).sort((a,q)=>(a.id===wanted?-100:distance(p,a))-(q.id===wanted?-100:distance(p,q)));
  if(enemies[0]){
   // LANE3: a bot-only party leader finishes engaged monsters first and starts a new pull only when the party is ready (bounded wait).
   if(party&&leader===p&&npcTeamEnabled(world)){const reach=Math.min(8,p.stats.attackRange||5),g=npcTeamLeaderTarget(world,p,b,{party,lookup:actor,map,candidate:enemies[0],reach});
    if(g?.wait){b.activity=g.wait==='regroup'?'waiting for the party to regroup':g.wait==='health'?'waiting for the party to recover':'waiting for mana before the next pull';if(p.path.length){await act(p,{type:'stop'});moveIntents.delete(p);}return;}
    if(g?.fight){if(g.approach&&distance(p,g.fight)>reach+.3){b.activity='taking a careful approach';if(await move(p,g.approach))return;}await fight(p,b,g.fight);return;}}
   await fight(p,b,enemies[0]);return;}
  const scene=sceneKey(p.map,p.instanceId,p.channel);if(now>=b.ambient&&now>=(b.quietUntil||0)&&now>=(ambientScenes.get(scene)||0)){b.ambient=now+policy.ambientMs*(p.profile.npcTraits.chat==='quiet'?3:1)+Math.floor(world.random()*20000);const nearby=[...world.players.values()].filter(q=>q!==p&&!q.dead&&sameScene(p,q)&&distance(p,q)<policy.chatDistance),h=nearby.find(human),peers=nearby.filter(q=>bot(q)&&now>=(brains.get(q.account)?.quietUntil||0));const c=h?personaContext(p,h,b):null;if(h&&peers.length){const topic=p.pcShopOpen?'trade':b.questId?'quest':c.canPull?'grind':p.partyId?'party':'gear';if(groupChat.start({speaker:p,targets:peers,topic,human:h})){ambientScenes.set(scene,now+policy.ambientMs);return;}}const other=nearby.find(human);if(other){ambientScenes.set(scene,now+policy.ambientMs);const topic=p.profile.npcTraits.chat==='playful'?'joke':b.questId?'quest':c.canPull?'grind':'status';await deliverAmbient(p,other,b,topic,c);return;}}
  // A merchant without genuine surplus may make a finite native service visit.
  // This is observation/rest only; it never opens a shop or spends/grants goods.
  if(!p.path.length&&!leader&&npcTownMerchantInspection(world,p,b)){
   b.activity='looking for an available objective';const parking=npcTownIdlePlan({world,player:p,brain:b,isHuman:human});
   b.activity=parking?'checking the town services':'waiting for a reachable town service';
   if(parking){b.idleTownPlan=parking;if(!parking.near)await toward(p,parking.at);}else delete b.idleTownPlan;
   return;
  }
  if(!p.path.length&&(!leader||leader===p)){b.activity=task.kind==='rest'?'taking a short break':'looking for an available objective';if(task.kind!=='rest'&&!assigned&&task.kind!=='quest'){task.kind='quest';b.questAt=0;if(await quest(p,b,null))return;}else if(task.kind==='rest')await act(p,{type:'stop'});if(task.kind!=='rest'&&await onward(p,b))return;if(task.kind!=='rest')noteIdleCause(p,b,task,assigned);const parking=npcTownIdlePlan({world,player:p,brain:b,isHuman:human});if(parking){b.idleTownPlan=parking;if(!parking.near)await toward(p,parking.at);}else delete b.idleTownPlan;}
 }
 async function drain(previousCycle=null){
  if(drain.pending)return drain.pending;
  // Publish the retirement flight before its first await. A rapid ON request
  // cannot start new warming/decisions in the old checkpoint's custody.
  epoch++;const task=Promise.resolve().then(async()=>{if(previousCycle)await previousCycle;await decisionFlights.settle();await sceneWarming.settle();return drainOnce();});drain.pending=task;
  try{const result=await task;drain.failed=false;return result;}catch(error){drain.failed=true;throw error;}finally{if(drain.pending===task)drain.pending=null;}
 }
 async function drainOnce(){
  cityRequester.clear();cityDuties.clear();cityDutyPlanner.clear();cityRetention.clear();cityDutyAt=-Infinity;
  sceneWarming.clear();
  backgroundSim?.clear();
  if(!capacityPolicy){if(populationWorkers)await populationWorkers.settleAccepted();for(const[id,b]of brains){const p=world.players.get(id);if(p)await fishingHook.retire(p,b);}eventTeams.dispose();groupChat.clear();residentSchedule.clear();if(populationWorkers){await populationWorkers.close();populationWorkers=null;}backgroundWork.clear();socialScenes.clear();ambientScenes.clear();conversations.clear();const flights=[...brains.values()].map(b=>b.objectiveFlight).filter(Boolean);for(const [id]of brains){const p=world.players.get(id);if(p)await leaveNpc(id,p.token);cancelActor(id);brains.delete(id)}await Promise.allSettled(flights);await profiles.flush();fieldResidency.parkVacant();if(residentRoster){await residentRoster.syncEarned(profiles.profiles);await residentRoster.flush();}return;}
  if(populationWorkers)await populationWorkers.settleAccepted();
  const flights=[...brains.values()].map(b=>b.objectiveFlight).filter(Boolean);await Promise.allSettled(flights);
  for(const[id,b]of brains){const p=world.players.get(id);if(!p)continue;const token=p.token;await fishingHook.retire(p,b);if(world.players.get(id)!==p||p.token!==token||brains.get(id)!==b)throw Object.assign(Error('Director retirement custody changed.'),{status:409});}
  if(populationWorkers)await populationWorkers.close();
  const pending=[];
  for(const[id,b]of [...brains]){
   const p=world.players.get(id);
   if(!p){if(brains.get(id)===b){cancelActor(id);brains.delete(id);}continue;}
   pending.push({player:p,token:p.token,brain:b});
   if(pending.length===64){await finish(pending.splice(0));}
  }
  if(pending.length)await finish(pending);
  populationWorkers=null;eventTeams.dispose();groupChat.clear();residentSchedule.clear();backgroundWork.clear();socialScenes.clear();ambientScenes.clear();conversations.clear();sceneWarming.clear();await profiles.flush();fieldResidency.parkVacant();if(residentRoster){await residentRoster.syncEarned(profiles.profiles);await residentRoster.flush();}
  async function finish(rows){await departNpcWave(rows,async row=>{const p=row.player;if(world.players.has(p.account)||p.token!==row.token||brains.get(p.account)!==row.brain)throw Object.assign(Error('Director departure custody changed.'),{status:409});cancelActor(p.account);brains.delete(p.account);});}
 }
 async function cycle(){if(closed||drain.pending||drain.failed)return;if(!enabled()){if(brains.size||populationWorkers||sceneWarming.pending())await drain();eventCursor=world.sequence;return;}await profiles.load();if(!residentRoster&&dormantRoster)residentRoster=typeof dormantRoster==='function'?await dormantRoster():dormantRoster;if(!freeplayCatalog)freeplayCatalog=npcFreeplayCatalog(world.data,residentRoster?.summary().maps?.map(r=>r.map)||Object.keys(world.data.dungeonCatalog?.maps||{}).map(Number));if(!rosterSerial)rosterSerial=profiles.profiles.size;backgroundSim?.tick();await reconcile();messages();await eventTeams.tick();const scheduler=ensurePopulationWorkers();if(background)scheduler.schedule();else await scheduler.tick();const remoteWork=backgroundWork.next(world.players),entries=[...brains],start=background&&entries.length?cycleCursor%entries.length:0;let slice=performance.now(),processed=0;for(;processed<entries.length;processed++){if(closed||!enabled()||background&&decisionFlights.count()>=(world.npcBackpressure?.flightCap?.()??8))break;/*LANE1-PERF backpressure hook*/const [id,b]=entries[(start+processed)%entries.length],p=world.players.get(id);if(!p||populationWorkers?.owns(p)||capacityPolicy)continue;const crew=p.partyId&&world.parties.get(p.partyId),humanCrew=crew?.members.some(pid=>human(actor(pid)));if(b.sceneOccupied===false&&!b.orphanFinishing&&remoteWork?.player!==p&&!humanCrew&&!human(actor(b.follow))&&!p.instanceId&&!eventTeams.retains(p))continue;
  // Stagger autonomous starts, but let a genuine human party invitation reach
  // the existing accept/decline and owned-service restoration authority now.
  const invitation=world.partyInvites.get(p.id);if(invitation&&invitation.expires>world.now()&&human(actor(world.parties.get(invitation.party)?.leader)))b.next=Math.min(b.next,world.now());
  const work=async(current=()=>true)=>{try{await think(p,b);if(current())b.lastError=null}catch(e){if(current()){b.lastError=e.message;if(!e.status)onError(e);b.next=world.now()+2000;}}};
  if(background){decisionFlights.start(p,b,work);await Promise.resolve();}else await work();
  if(performance.now()-slice>=8){await yieldTurn();slice=performance.now();}}if(background&&entries.length)cycleCursor=(start+processed)%entries.length;if(world.now()>=parkAt){parkAt=world.now()+5000;fieldResidency.parkVacant();}}
 // Bounded task-selection failure log: why a bot fell through to idle parking
 // (city duty | map kind / elected task / farm target availability). Status only.
 // Bounded quest-stall log (verdict:reason -> count) and totals. Status only.
 const questStalls=new Map(),questStallTotals={deferred:0,abandoned:0};function noteQuestStall(key){if(questStalls.size<64||questStalls.has(key))questStalls.set(key,(questStalls.get(key)||0)+1);}
 const idleCauses=new Map();function noteIdleCause(p,b,task,assigned){const row=world.data.mapRow?.(p.map),where=cityDuty(p,b)?'city-'+cityDuty(p,b):Number(row?.PeaceZone)===1?'town':'field',key=`${where}/${task.kind}/${assigned?'farm-target':'no-farm-target'}${b.travelBlockedReason?'/route-blocked':''}`;if(idleCauses.size<64||idleCauses.has(key))idleCauses.set(key,(idleCauses.get(key)||0)+1);b.taskSelection={...b.taskSelection,idleCause:key};}
 function activitySnapshot(){let moving=0,shops=0,questFallback=0,errors=0;const byTask={},city={residents:0,stationary:0,sitting:0,ownedShops:0,acceptedQuests:0,byDuty:{}};for(const [id,b] of brains){const p=world.players.get(id);if(p?.path?.length)moving++;if(p?.pcShopOpen)shops++;if(b.questUnavailable)questFallback++;if(b.lastError)errors++;const kind=b.taskGoal?.kind||'none';byTask[kind]=(byTask[kind]||0)+1;if(p?.map===150&&!p.instanceId&&!p.channel&&!p.leaving){city.residents++;if(!p.path.length)city.stationary++;if(p.sitting)city.sitting++;if(p.pcShopOpen)city.ownedShops++;if(b.questId||Object.keys(p.profile.quests?.active||{}).length)city.acceptedQuests++;const duty=cityDuty(p,b)||'protected';city.byDuty[duty]=(city.byDuty[duty]||0)+1;}}const archetypes={...npcArchetypeSummary([...brains].map(([id,b])=>{const p=world.players.get(id);return {player:p,brain:b,duty:p&&cityDutyPlanner.assigned(p),dutyDetail:p&&cityDutyPlanner.detail?.(p)};})),idleCauses:Object.fromEntries(idleCauses),sessions:{enabled:sessionsOn,logouts:sessionLogouts}};const quests={...questStallTotals,reasons:Object.fromEntries(questStalls)};return {decisions:decisionCount,lastDecisionAt,scenePreparations:sceneWarming.pending(),decisionFlights:decisionFlights.count(),moving,shops,questFallback,errors,optionalBuildNextAt:optionalBuildPacer.nextAt(),byTask,city,archetypes,quests};}
 async function primeScene(anchor){const retirement=drain.pending||(drain.failed?drain(busy):null);if(retirement)await retirement;if(closed||!enabled()||world.players.get(anchor?.account)!==anchor)return {complete:false,ceiling:0,eligible:0,target:0,actors:0,reason:'scene-changed'};if(!background||!npcOccupiedField(world,anchor,human))return {complete:true,target:0,actors:0};const key=sceneKey(anchor.map,anchor.instanceId,anchor.channel);return sceneWarming.run({key,map:anchor.map,instanceId:anchor.instanceId,channel:anchor.channel||0},update=>primeOccupiedScene(anchor,update));}
 return {brains,cityDutyDetail:p=>cityDutyPlanner.detail?.(p)||null,simulation:()=>backgroundSim?.snapshot()||null,presence:backgroundSim,async preloadNative({wallBudgetMs=120000}={}){
   if(closed||!enabled())return {phase:'disabled',complete:false};
   if(!Number.isInteger(wallBudgetMs)||wallBudgetMs<1||wallBudgetMs>120000)throw Error('Invalid startup observation budget');
   const started=performance.now();Object.assign(capacityStartup,{phase:'preparing',pending:'canonical-profile-load',elapsedMs:0,deadlineExceeded:false,complete:false});
   const timer=setTimeout(()=>{capacityStartup.deadlineExceeded=true;capacityStartup.phase='deadline-exceeded-settling';},wallBudgetMs);
   try{await profiles.load();capacityStartup.elapsedMs=performance.now()-started;
    if(closed||!enabled()){capacityStartup.phase='disabled';return {...capacityStartup};}
    const remaining=Math.floor(wallBudgetMs-capacityStartup.elapsedMs);
    if(remaining<=0){capacityStartup.phase='deadline-incomplete';capacityStartup.deadlineExceeded=true;return {...capacityStartup};}
    capacityStartup.pending='native-admissions';const result=await ensurePopulationWorkers().preload({wallBudgetMs:remaining});
    Object.assign(capacityStartup,result,{elapsedMs:performance.now()-started,deadlineExceeded:capacityStartup.deadlineExceeded||result.deadlineExceeded});return {...capacityStartup};
   }catch(error){capacityStartup.phase='failed';throw error;}finally{clearTimeout(timer);capacityStartup.pending=null;capacityStartup.elapsedMs=performance.now()-started;}
  },activity:activitySnapshot,status:()=>({capacityStartup:{...capacityStartup},enabled:!!enabled(),players:brains.size,policy,lastPrime,activity:activitySnapshot(),background:backgroundWork.snapshot(),simulation:backgroundSim?.snapshot()||null,population:populationWorkers?.snapshot()||null,residency:fieldResidency.snapshot(),events:eventTeams.snapshot(),conversations:groupChat.snapshot(),rosterBlocked:[...rosterBlocked].map(([scene,reason])=>({scene,reason}))}),
  simulationState(){const scheduler=!closed&&enabled()?ensurePopulationWorkers():populationWorkers,workerIds=new Set(),visibleIds=new Set();for(const p of world.players.values()){if(!bot(p))continue;if(scheduler?.owns(p)||backgroundWork.owns(p))workerIds.add(p.id);else if(brains.has(p.account))visibleIds.add(p.id);}return {workerIds,visibleIds,queuedIds:scheduler?.queuedProfileIds({memoOccupiedByScene:true})||new Set()};},
   sceneReadiness,scenePreparationRequired,
   async settle(){if(busy)await busy;await sceneWarming.settle();await decisionFlights.settle();},
   primeScene,
  tick(){if(busy||closed)return busy;busy=cycle().catch(onError).finally(()=>{busy=null});return busy;},
  async sync(){const observedOff=!enabled(),previousCycle=busy;if(observedOff)await drain(previousCycle);else{if(previousCycle)await previousCycle;if(!enabled())await drain();else await this.tick();}return this.status();},
  async close(){closed=true;epoch++;if(busy)await busy;await sceneWarming.settle();await drain();},
 };
}
