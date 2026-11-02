import {fishingBusy} from './fishing.mjs';
import {sameScene} from './scene.mjs';
import {npcPlacements,offersOriginalJob} from './npc-services.mjs';
import {dkSquareDataFrom} from './dk-square.mjs';
import {rankForLevel,scheduleWindow,openRefusal,DK_SQUARE_JOB} from '../../src/systems/pvp/dksquare-rules.js';
import {DK_SQUARE_CHOSEN} from '../../src/config/engine-chosen-dk-square.js';

// ENGINE-CHOSEN ordinary player organizer. No GM tag, capability, schedule force,
// admission override, reward, auto-enrollment, or autonomous private instance.
const cached=new WeakMap(),isNpc=p=>p?.npcPlayer===true||p?.profile?.npcPlayer===true;
function rules(data){if(data.dkSquare)return data.dkSquare;if(!cached.has(data))cached.set(data,dkSquareDataFrom(data.eventData?.ev||{modes:data.eventData?.modes,maps:data.eventData?.maps}));return cached.get(data);}
function available(world,p,rank){return p&&!p.leaving&&!p.dead&&!p.sceneTransition&&!p.instanceId&&!p.arenaId&&!p.arenaQueued&&!p.duelId&&!p.partyPvpId&&!p.tradeId&&!fishingBusy(p)&&p.mount?.phase!=='on'&&(Number(p.profile.arena?.penaltyUntil)||0)<=world.now()&&Number(p.profile.dil||0)>=rank.enterCost;}
/** Root supplies an actual willing human team member; an invented partyId is insufficient. */
export function npcOrganizerPlan(world,p,{humanInitiator}={}){
 if(world.players.get(p?.account)!==p||!isNpc(p)||p.profile.authority!=='server'||p.gmAuthorized||p.capabilities?.includes('gm:commands')||p.dkSquareId)return null;
 const human=humanInitiator;if(!human||world.players.get(human.account)!==human||isNpc(human)||!sameScene(p,human))return null;
 const party=p.partyId&&world.parties.get(p.partyId);if(!party||human.partyId!==party.id||!party.members.includes(p.id)||!party.members.includes(human.id))return null;
 const data=rules(world.data),rank=rankForLevel(data,p.profile.level),humanRank=rankForLevel(data,human.profile.level);if(!rank||humanRank?.rank!==rank.rank||!available(world,p,rank)||!available(world,human,humanRank)||human.dkSquareId)return null;
 const window=scheduleWindow(data.schedule,world.now());if(!window.open)return null;
 const lobbies=[...(world.dkSquares?.values()||[])].filter(l=>l.rank===rank.rank&&!l.closing&&l.phase!=='over');if(openRefusal(lobbies,rank))return null;
 const officer=npcPlacements(world,p.map).filter(n=>n.jobs.some(([type,index])=>Number(type)===DK_SQUARE_JOB&&offersOriginalJob(world,n,DK_SQUARE_JOB,Number(index)))).sort((a,b)=>Math.hypot(p.x-a.x,p.z-a.z)-Math.hypot(p.x-b.x,p.z-b.z))[0];if(!officer)return null;
 return {kind:'ordinary-player-organizer',at:{map:p.map,x:officer.x,z:officer.z,npc:officer.npcIndex},near:Math.hypot(p.x-officer.x,p.z-officer.z)<=DK_SQUARE_CHOSEN.npcRadius,action:{type:'dksquare',operation:'open',npcIndex:officer.npcIndex},rank:rank.rank,levels:[rank.minLevel,rank.maxLevel],entryCost:rank.enterCost,window,humanId:human.id,provenance:{policy:'ENGINE-CHOSEN',source:'native placed ARENA_SQUARE job48, arena rank/conquest and DK schedule; existing ordinary lobby authority'}};
}
export async function npcOrdinaryOrganizerStep(world,p,b,act,options={}){
 const plan=npcOrganizerPlan(world,p,options);if(!plan?.near||world.now()<(b.ordinaryOrganizerAt||0))return false;
 b.ordinaryOrganizerAt=world.now()+30000; // ENGINE-CHOSEN bounded retry; native timing remains unchanged.
 await act(p,plan.action);if(p.dkSquareId)b.ordinaryOrganizer={kind:plan.kind,lobbyId:p.dkSquareId,humanId:plan.humanId,rank:plan.rank};
 return !!p.dkSquareId;
}
