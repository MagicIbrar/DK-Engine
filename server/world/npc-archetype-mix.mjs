// ENGINE-CHOSEN population realism configuration (the ONE file to tune the bot mix).
// These are behavioral preferences for server-owned bots only: they choose among
// EXISTING routines/duties and pace decisions. They grant no item, currency, EXP,
// admission, combat bonus or native rule change; every action still goes through
// the ordinary server validation that human players use.
//
// share      target fraction of the bot population (normalized; need not sum to 1)
// affinity   compatibility with the saved persona traits (social|solo|outlaw) and
//            level band (lt40|lt100|lt150|cap). Assignment is a deterministic
//            per-profile draw whose MARGINAL mix equals `share` (Sinkhorn balanced
//            against the trait distribution npcPopulationChoice produces).
// tasks      weights over the existing routine kinds chosen by npcAssignActivity
//            (quest|farm|merchant|rest). Saved accepted quests/instances still win.
// town       weights over the existing Ardeca city duties (quest = may head out to
//            an objective, service = town errands/market/gear, rest = seated/AFK).
// think      idle (non-combat) decision cadence: lognormal median ms and sigma. Combat
//            polling keeps the existing competence-tier cadence (unchanged).
// restMs     duration range of an elected rest/AFK routine.
// session    lognormal session length (minutes) and preferred login hours (local).
// risk       retreat tendency hint (0 = never voluntary, 1 = very cautious); exposed
//            for combat lanes, not applied to native combat math.
export const NPC_ARCHETYPE_MIX=Object.freeze({
 version:1,
 archetypes:{
  grinder:     {share:0.20,label:'grinder',            affinity:{social:0.8,solo:1.6,outlaw:1.0, lt40:0.7,lt100:1.2,lt150:1.2,cap:1.0},tasks:{farm:0.65,quest:0.10,merchant:0.10,rest:0.15},town:{quest:0.45,service:0.45,rest:0.10},think:{medianMs:700, sigma:0.30},restMs:[20000,45000],  session:{medianMin:170,sigma:0.45,hours:[18,19,20,21,22,23,0,1]},risk:0.35},
  pvper:       {share:0.08,label:'PvPer / PKer',       affinity:{social:0.4,solo:0.8,outlaw:3.0, lt40:0.3,lt100:1.0,lt150:1.4,cap:1.6},tasks:{farm:0.45,quest:0.10,merchant:0.05,rest:0.40},town:{quest:0.35,service:0.25,rest:0.40},think:{medianMs:560, sigma:0.30},restMs:[20000,40000],  session:{medianMin:120,sigma:0.50,hours:[19,20,21,22,23]},risk:0.15},
  partyRunner: {share:0.12,label:'party / dungeon runner',affinity:{social:2.6,solo:0.4,outlaw:0.6,lt40:0.6,lt100:1.2,lt150:1.3,cap:1.2},tasks:{quest:0.45,farm:0.35,merchant:0.05,rest:0.15},town:{quest:0.40,service:0.40,rest:0.20},think:{medianMs:650, sigma:0.30},restMs:[20000,40000],  session:{medianMin:140,sigma:0.45,hours:[18,19,20,21,22]},risk:0.45},
  quester:     {share:0.14,label:'quester / leveler',  affinity:{social:1.1,solo:1.3,outlaw:0.6, lt40:1.6,lt100:1.2,lt150:0.8,cap:0.4},tasks:{quest:0.70,farm:0.15,merchant:0.05,rest:0.10},town:{quest:0.55,service:0.35,rest:0.10},think:{medianMs:750, sigma:0.35},restMs:[20000,40000],  session:{medianMin:110,sigma:0.50,hours:[17,18,19,20,21,22]},risk:0.50},
  trader:      {share:0.08,label:'trader / merchant',  affinity:{social:1.4,solo:1.0,outlaw:0.6, lt40:0.5,lt100:1.0,lt150:1.2,cap:1.3},tasks:{merchant:0.60,rest:0.25,farm:0.10,quest:0.05},town:{quest:0.05,service:0.65,rest:0.30},think:{medianMs:1200,sigma:0.40},restMs:[30000,90000],  session:{medianMin:200,sigma:0.55,hours:[12,13,14,18,19,20,21,22]},risk:0.70},
  lifeskiller: {share:0.04,label:'fisher / lifeskiller',affinity:{social:0.8,solo:1.6,outlaw:0.5, lt40:0.8,lt100:1.2,lt150:1.0,cap:0.8},tasks:{rest:0.55,merchant:0.25,farm:0.15,quest:0.05},town:{quest:0.10,service:0.55,rest:0.35},think:{medianMs:1100,sigma:0.40},restMs:[30000,60000],  session:{medianMin:150,sigma:0.55,hours:[10,11,12,13,14,20,21]},risk:0.80},
  socialIdler: {share:0.10,label:'social / town idler',affinity:{social:2.0,solo:0.5,outlaw:1.0, lt40:0.8,lt100:1.0,lt150:1.0,cap:1.2},tasks:{rest:0.60,merchant:0.15,quest:0.15,farm:0.10},town:{quest:0.05,service:0.30,rest:0.65},think:{medianMs:1500,sigma:0.45},restMs:[45000,150000], session:{medianMin:130,sigma:0.55,hours:[19,20,21,22,23,0]},risk:0.60},
  afkVendor:   {share:0.10,label:'AFK / vendor-parked',affinity:{social:1.0,solo:1.2,outlaw:0.7, lt40:0.4,lt100:1.0,lt150:1.3,cap:1.5},tasks:{rest:0.85,merchant:0.15,farm:0.00,quest:0.00},town:{quest:0.00,service:0.10,rest:0.90},think:{medianMs:4000,sigma:0.50},restMs:[120000,360000],session:{medianMin:480,sigma:0.60,hours:[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23]},risk:0.90},
  newbie:      {share:0.14,label:'newbie / alt',       affinity:{social:1.2,solo:1.0,outlaw:0.5, lt40:3.0,lt100:0.9,lt150:0.3,cap:0.1},tasks:{quest:0.55,farm:0.25,rest:0.15,merchant:0.05},town:{quest:0.40,service:0.45,rest:0.15},think:{medianMs:1000,sigma:0.50},restMs:[20000,50000],  session:{medianMin:60, sigma:0.60,hours:[15,16,17,18,19,20,21]},risk:0.55}
 },
 // Orthogonal commitment axis; multiplies think cadence and session length.
 commitment:{
  hardcore:{share:0.25,think:0.85,session:1.6},
  regular: {share:0.50,think:1.00,session:1.0},
  casual:  {share:0.25,think:1.25,session:0.55}
 },
 // Reaction/think multiplier by the EXISTING competence tier (npcCompetenceTier).
 skill:{novice:1.30,regular:1.00,expert:0.85,elite:0.75},
 // Reaction to being hit while idle (damage -> next decision), separate from the idle
 // think cadence: lognormal median by the existing competence tier x archetype factor.
 // It can only bring a pending decision EARLIER; combat polling stays as is.
 reaction:{medianMs:{novice:650,regular:480,expert:360,elite:270},sigma:0.35,clampMs:[150,6000],
  archetype:{grinder:1.0,pvper:0.85,partyRunner:1.0,quester:1.05,trader:1.3,lifeskiller:1.3,socialIdler:1.4,afkVendor:3.0,newbie:1.2},
  commitment:{hardcore:0.9,regular:1.0,casual:1.15}},
 // While actively working a farm/quest/dungeon/event routine the think median is capped
 // (an AFK-type bot that is actually grinding plays at a normal pace; AFK slowness is for rest).
 activeThinkMedianCapMs:850,
 // Global clamp for an idle decision interval (ms). Combat cadence is not affected.
 thinkClampMs:[350,9000],
 // Ardeca city duty caps in archetype mode (legacy policy: quest 2, service 8, rest rest).
 // Bounded so heading-out bots cannot drain the hub and trigger an admission churn.
 city:{maxQuest:6,maxService:32,dwellMs:{quest:240000,service:[90000,240000],rest:[120000,420000]}},
 // Optional login/logout cycling (OFF by default: it adds join/leave persistence).
 sessions:{enabled:false,minOfflineMin:20}
});
