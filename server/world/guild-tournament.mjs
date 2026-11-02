// GUILD-TOURNEY: server-authoritative Guild Tournament. Original data: share/guildtournament/config.csv (WAITING_TIME,
// DEFAULT_MATCH), match.csv (16-guild bracket), donation.csv (B/P coins 6804/6805), share/colosseum/guildmatch/list.csv
// (map 165, 7 per side, team starts, observer point); NPCs Ferdianand 5159 (90 info / 95 match enter / 100 observer),
// Donation Angel 5165 (87 donation / 86 donation rank), Gambler Egg 5166 (92 betting / 94 betting income / 100);
// Ferdianand also answers 88 (select players), 89 (seed info) and 91 (entry info) through his tournament service.
// Texts: stringtable_colosseum 360|*. Every value the data does not give is in src/config/engine-chosen-guild-tournament.js.
// Player-vs-player hits run through the shared PvP pipeline (server/world/pvp.mjs, rules src/game/pvp-rules.js).
import {GUILD_TOURNAMENT_ENGINE_CHOSEN as C} from '../../src/config/engine-chosen-guild-tournament.js';
const phaseTimersReady=()=>[C.readySec,C.countSec,C.roundSec,C.finishRoundSec,C.breakSec,C.finishMatchSec,C.registrationSec].every(v=>Number.isFinite(v)&&v>=0);
const noPhaseSchedule=()=>{throw Object.assign(Error('Guild Tournament match-phase seconds are missing from src/config/engine-chosen-guild-tournament.js (ONLINE no=589 values).'),{status:503});};
import {tournamentData,seedCount,buildBracket,playOrder,advance,walkover,roundOutcome,matchOutcome,matchPoints,scoreLabel,betPayout,betRatios} from '../../src/systems/events/guild-tournament-rules.js';
import {registerPvpMode} from './pvp.mjs';
import {registerObserverMode} from './observers.mjs';
import {createInstance,exitInstance,requestInstanceClose} from './instances.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {socialRef} from './social-state.mjs';
import {guildMark} from './guilds.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {serializeLife,commitLife} from './life-transactions.mjs';
import {sameScene} from './scene.mjs';
export const TOURNEY_SCHEMAS={tourney:['token','type','operation','npcIndex','seed','members','coin','score','amount']};
// Jobs 88 / 89 / 91 have no NPC in the data: Ferdianand's info service (job 90) opens those windows (ENGINE-CHOSEN).
export const TOURNEY_JOBS=Object.freeze({info:90,entries:90,seeds:90,roster:90,enter:95,observe:100,bet:92,claim:94,donate:87,ranking:86});
// Original texts (stringtable_colosseum.txt cate 360).
export const TOURNEY_TEXT={
  noGuild:'You are not in a guild.',                                                  // 360|30
  items:'You do not have enough items.',                                              // 360|31
  donated:'<VALUE> <ITEM> have been donated.',                                        // 360|34
  seeded:'Cid requested.',                                                            // 360|138
  registered:'Registration succeeded.',                                               // 360|144
  bet:'The bet has been processed.',                                                  // 360|156
  coins:'Not enough Coins.',                                                          // 360|157
  collected:'Prize money collected.',                                                 // 360|158
  contenders:'Only Guild Tournament contenders can enter the entry list.',           // 360|179
  open:'The Guild Tournament Round of %d - %d Match map is now available to enter.',  // 360|180
  sameClass:'You cannot register the same class more than once.',                    // 360|182
  master:'You are not a guild master.',                                               // 360|183
  pick:'Select a score and a coin quantity to make a bet.',                           // 360|184
  cannot:'You cannot enter.',                                                         // 360|185
  betClosed:'The betting service is not available at this hour of the day.',         // 360|186
  finalOpen:'The Guild Tournament Final Match map is now available to enter.',        // 360|188
  changed:'You cannot enter because you have changed your guild.',                   // 360|191
  ended:'You cannot enter because the match has ended.',                             // 360|192
  watchContender:'Guild Tournament contenders cannot watch the Tournament matches.', // 360|202
  over:'Guild Tournament has ended.',                                                 // 360|203
  failed:'The guild failed to enter the Guild Tournament.',                          // 360|204
  noWatch:'The Viewing service is not available at this hour of the day.',           // 360|205
  bagFull:'You cannot receive the won money because your inventory is full. Please make some room first.', // 360|209
  far:'Walk near the Guild Tournament NPC first.',                                   // engine text
  seedTaken:'That Cid is already taken.',                                             // engine text
};
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const dataOf=world=>{const d=world.data?.guildTournament||(world.data.guildTournament=tournamentData(world.data.eventData?.modes));if(!d)fail('Guild Tournament tables are unavailable on this host.',503);return d;};
const live=(world,p)=>!!p&&world.players.get(p.account)===p&&!p.leaving;
const T=world=>world.guildTournament||=({season:0,phase:'idle',seeds:[],guilds:new Map(),rosters:new Map(),bracket:null,order:[],cursor:0,current:null,bets:new Map(),pool:new Map(),donations:new Map(),results:[],champion:null});
const guildRow=(world,p)=>{const ref=socialRef(p);return Object.values(world.socialState?.guilds||{}).find(g=>g?.members?.some(m=>m.ref===ref))||null;};
const guildById=(world,id)=>world.socialState?.guilds?.[id]||Object.values(world.socialState?.guilds||{}).find(g=>String(g.id)===String(id))||null;
const guildLevel=(world,g)=>{if(Number.isInteger(g.level))return g.level;let l=1;for(let i=1;i<=15;i++)if((g.gpoint||0)>=Number(world.data.guild?.config?.[`LEVELSTEP${i}`]))l=i;return l;};
const masterName=(world,g)=>[...world.players.values()].find(q=>!q.leaving&&socialRef(q)===g.master)?.profile?.name||g.members.find(m=>m.ref===g.master)?.name||'';
const guildInfo=(world,g)=>g?{id:String(g.id),name:String(g.name||''),level:guildLevel(world,g),master:masterName(world,g),members:g.members.length,mark:guildMark(g.mark),server:C.serverName}:null;
const requireNpc=(world,p,job,input)=>{const npc=nearbyNpc(world,p,{jobType:job,radius:8,...(Number.isInteger(Number(input.npcIndex))&&input.npcIndex!=null?{npcIndex:Number(input.npcIndex)}:{})});if(!npc)fail(TOURNEY_TEXT.far,403);return npc;};
const fmt=(s,...v)=>{let i=0;return s.replace(/%[sd]/g,()=>String(v[i++]));};
const sideOf=(run,p)=>run?run.sides.findIndex(s=>s.ids.has(p.id)):-1;
const inRun=(run,p)=>!!run?.instance&&p.instanceId===run.instance.id;
const announce=(world,text)=>{for(const q of world.players.values())if(!q.leaving)world.emit(q.map,{type:'event:message',text,recipients:[q.id]});};
/** Spectators of the running match (job 100). */
export function isTourneyObserver(world,p){const run=world.guildTournament?.current;return inRun(run,p)&&run.observers.has(p.characterId);}
export const TOURNEY_OBSERVER_ACTIONS=new Set(['move','stop','chat','emote','tourney']);
registerObserverMode({is:isTourneyObserver,actions:TOURNEY_OBSERVER_ACTIONS});
// PvP: an enemy is a live entrant of the other side during a battle round.
export function tourneyEnemy(world,p,q){
  const run=world.guildTournament?.current;if(!run||run.phase!=='battle'||!q||!inRun(run,p)||!inRun(run,q))return false;
  const a=sideOf(run,p),b=sideOf(run,q);return a>=0&&b>=0&&a!==b&&!run.down.has(p.id)&&!run.down.has(q.id)&&sameScene(p,q);
}
function markDown(world,run,q,by){
  if(run.down.has(q.id))return;run.down.add(q.id);q.hp=0;q.dead=true;q.path=[];world.changed(q);
  const s=by?sideOf(run,by):-1;if(s>=0&&s!==sideOf(run,q)){run.roundKills[s]++;run.sides[s].kills++;if(run.firstKill==null){run.firstKill=s;run.sides[s].firstKills++;}}
}
registerPvpMode({enemy:tourneyEnemy,opponents:(world,p)=>{const run=world.guildTournament?.current;return run?[...world.players.values()].filter(q=>tourneyEnemy(world,p,q)&&!q.dead):[];},
  onDown:(world,attacker,target)=>{const run=world.guildTournament?.current;if(run&&inRun(run,target)&&sideOf(run,target)>=0)markDown(world,run,target,attacker);}});
/** Downed entrants stay down until the round ends; the host revive is refused inside a match. */
export function tourneyBlocksRevive(world,p){const run=world.guildTournament?.current;return inRun(run,p)&&sideOf(run,p)>=0;}
export const TOURNEY_REVIVE_TEXT='You cannot revive during a Guild Tournament round.'; // engine text
function openSeason(world){const t=T(world),d=dataOf(world),now=world.now();
  Object.assign(t,{season:t.season+1,phase:'registration',seeds:Array(seedCount(d)).fill(null),guilds:new Map(),rosters:new Map(),bracket:null,order:[],cursor:0,current:null,bets:new Map(),cancelled:false,results:[],champion:null,openedAt:now,locksAt:now+C.registrationSec*1000});}
const masterGuild=(world,p)=>{const g=guildRow(world,p);if(!g)fail(TOURNEY_TEXT.noGuild);if(g.master!==socialRef(p))fail(TOURNEY_TEXT.master,403);return g;};
function requestSeed(world,p,input){
  requireNpc(world,p,TOURNEY_JOBS.seeds,input);const g=masterGuild(world,p),t=T(world);
  if(t.phase==='running')fail(TOURNEY_TEXT.failed,409);
  if(t.phase!=='registration')openSeason(world);
  const seed=Number(input.seed);if(!Number.isInteger(seed)||seed<1||seed>t.seeds.length)fail('Choose a Cid.');
  const id=String(g.id),at=t.seeds[seed-1];if(at&&at!==id)fail(TOURNEY_TEXT.seedTaken,409);
  t.seeds=t.seeds.map(s=>s===id?null:s);t.seeds[seed-1]=id;t.guilds.set(id,guildInfo(world,g));
  return {operation:'seed',seed,text:TOURNEY_TEXT.seeded};
}
function setRoster(world,p,input){
  requireNpc(world,p,TOURNEY_JOBS.roster,input);const g=masterGuild(world,p),t=T(world),d=dataOf(world),id=String(g.id);
  if(!t.seeds.includes(id))fail(TOURNEY_TEXT.contenders,403);
  if(t.current&&t.current.sides.some(s=>s.guildId===id))fail(TOURNEY_TEXT.ended,409);
  const ids=Array.isArray(input.members)?input.members.map(String):null;if(!ids||!ids.length||ids.length>d.arena.members||new Set(ids).size!==ids.length)fail(`Choose 1-${d.arena.members} players.`);
  const refs=new Set(g.members.map(m=>m.ref)),rows=[];
  for(const cid of ids){const q=[...world.players.values()].find(x=>!x.leaving&&x.characterId===cid);if(!q||!refs.has(socialRef(q)))fail(TOURNEY_TEXT.contenders,403);rows.push({ref:socialRef(q),characterId:q.characterId,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:Number(q.profile.level)||1});}
  if(new Set(rows.map(r=>r.classIndex)).size!==rows.length)fail(TOURNEY_TEXT.sameClass);
  t.rosters.set(id,rows);return {operation:'roster',count:rows.length,text:TOURNEY_TEXT.registered};
}
function lock(world){const t=T(world),d=dataOf(world),taken=t.seeds.filter(Boolean).length;
  if(taken<C.minGuilds){endSeason(world,true);return;}
  t.bracket=buildBracket(d,t.seeds);t.order=playOrder(t.bracket);t.cursor=0;t.phase='running';}
// Donations count toward the season they were made before or during; the ranking is kept as the season's final list.
function endSeason(world,cancelled){const t=T(world);t.finalRanking=donationRanking(world);t.donations=new Map();t.phase='ended';t.cancelled=cancelled;announce(world,TOURNEY_TEXT.over);}
function side(world,guildId){const info=T(world).guilds.get(guildId)||guildInfo(world,guildById(world,guildId));return {guildId,name:info?.name||'',mark:info?.mark||null,ids:new Set(),kills:0,firstKills:0,wins:0};}
function startMatch(world,m){const d=dataOf(world),now=world.now();
  const run={id:`${T(world).season}:${m.key}`,key:m.key,match:m.match,order:m.order,phase:'entry',phaseEnd:now+d.waitingSec*1000,round:0,rounds:[],sides:[side(world,m.left),side(world,m.right)],down:new Set(),roundKills:[0,0],firstKill:null,instance:null,observers:new Set(),result:null};
  T(world).current=run;m.status='running';announce(world,m.match===2?TOURNEY_TEXT.finalOpen:fmt(TOURNEY_TEXT.open,m.match,m.order));return run;}
function finishMatch(world,run,winner,reason){
  const t=T(world),m=t.bracket.get(run.key),now=world.now(),wins=run.sides.map(s=>s.wins);
  const winId=winner==null?null:run.sides[winner].guildId;advance(t.bracket,m,winId);m.wins=wins;
  const label=scoreLabel(wins),fought=reason==='decided',points=matchPoints(run.rounds.map(r=>r.winner));
  const ratios=betRatios([...(t.bets.get(run.key)||new Map()).values()]);
  for(const [ref,bet] of t.bets.get(run.key)||[]){const got=fought?betPayout(bet,label,ratios):bet.amount;if(got>0){const pool=t.pool.get(ref)||{P:0,B:0};pool[bet.coin]+=got;t.pool.set(ref,pool);}bet.settled=label;}
  run.result={winner,reason,wins,points,label,names:run.sides.map(s=>s.name),rounds:run.rounds.map(r=>({...r})),firstKills:run.sides.map(s=>s.firstKills)};
  t.results.push({key:run.key,match:run.match,order:run.order,...run.result});
  run.phase='matchEnd';run.phaseEnd=now+C.finishMatchSec*1000;
}
function placeSide(world,run,s){const d=dataOf(world),starts=s===0?d.arena.teamA:d.arena.teamB,scene=run.instance.scene;let i=0;
  for(const id of run.sides[s].ids){const q=[...world.players.values()].find(x=>x.id===id);if(!q||!inRun(run,q))continue;const [x,z]=starts[i++%starts.length];const at=scene.nearest(x+.5,z+.5);if(at){q.x=at.x;q.z=at.z;q.path=[];}
    q.dead=false;q.hp=q.maxHp;q.mp=q.stats.maxMp||0;q.shield=Number(q.stats.maxShield)||0;delete q.pvpLastHit;world.changed(q);world.emit(q.map,{type:'revive',actorId:q.id,instanceId:q.instanceId});}}
function endRound(world,run,reason){
  const alive=run.sides.map(s=>[...s.ids].filter(id=>!run.down.has(id)).length),winner=roundOutcome({alive,kills:run.roundKills},reason);
  if(winner>=0)run.sides[winner].wins++;
  run.rounds.push({winner,kills:[...run.roundKills],firstKill:run.firstKill,reason});run.round++;
  run.phase='roundEnd';run.phaseEnd=world.now()+C.finishRoundSec*1000;
}
async function closeRun(world,run){const t=T(world);
  if(run.instance){const members=[...world.players.values()].filter(q=>inRun(run,q));for(const q of members){if(q.dead){q.dead=false;q.hp=q.maxHp;world.changed(q);}}if(members.length){run.closing=true;void requestInstanceClose(world,run.instance)?.catch?.(()=>{});if(members.some(q=>inRun(run,q)))return false;}}
  t.current=null;t.cursor++;return true;}
export async function tickGuildTournament(world){
  const t=world.guildTournament;if(!t||t.phase==='idle'||t.phase==='ended')return;const now=world.now();
  if(t.phase==='registration'){if(now>=t.locksAt||t.seeds.every(Boolean))lock(world);return;}
  for(let guard=0;guard<32&&!t.current&&t.phase==='running';guard++){
    if(t.cursor>=t.order.length){t.champion=t.bracket.get(t.order.at(-1))?.winner??null;endSeason(world,false);return;}
    const m=t.bracket.get(t.order[t.cursor]),w=walkover(m);
    if(w!==undefined){advance(t.bracket,m,w);t.results.push({key:m.key,match:m.match,order:m.order,winner:w?(w===m.left?0:1):null,reason:w?'bye':'empty',wins:[0,0]});t.cursor++;continue;}
    startMatch(world,m);
  }
  const run=t.current;if(!run)return;
  if(run.instance){for(const s of run.sides)for(const id of [...s.ids]){const q=[...world.players.values()].find(x=>x.id===id);if(!q||!live(world,q)||!inRun(run,q)){if(run.phase==='battle')run.down.add(id);}}}
  if(run.phase==='entry'&&now>=run.phaseEnd){
    const counts=run.sides.map(s=>s.ids.size);
    if(counts.every(c=>c<C.minimumEntrants)){finishMatch(world,run,null,'disqualified');return;}
    if(counts.some(c=>c<C.minimumEntrants)){const w=counts[0]>=C.minimumEntrants?0:1;run.sides[w].wins=C.roundsToWin;for(let i=0;i<C.roundsToWin;i++)run.rounds.push({winner:w,kills:[0,0],firstKill:null,reason:'forfeit'});finishMatch(world,run,w,'forfeit');return;}
    if(!phaseTimersReady())noPhaseSchedule();run.phase='ready';run.phaseEnd=now+C.readySec*1000;placeSide(world,run,0);placeSide(world,run,1);return;}
  if(run.phase==='ready'&&now>=run.phaseEnd){run.phase='count';run.phaseEnd=now+C.countSec*1000;return;}
  if(run.phase==='count'&&now>=run.phaseEnd){run.phase='battle';run.phaseEnd=now+C.roundSec*1000;run.down=new Set();run.roundKills=[0,0];run.firstKill=null;return;}
  if(run.phase==='battle'){
    for(const s of run.sides)for(const id of s.ids){const q=[...world.players.values()].find(x=>x.id===id);if(q&&inRun(run,q)&&(q.dead||q.hp<=0))markDown(world,run,q,q.pvpLastHit?.by&&[...world.players.values()].find(x=>x.id===q.pvpLastHit.by));}
    const alive=run.sides.map(s=>[...s.ids].filter(id=>!run.down.has(id)).length);
    if(alive.some(a=>a===0))endRound(world,run,'annihilation');else if(now>=run.phaseEnd)endRound(world,run,'time');return;}
  if(run.phase==='roundEnd'&&now>=run.phaseEnd){
    const w=matchOutcome({points:matchPoints(run.rounds.map(r=>r.winner))});
    if(w!=null){finishMatch(world,run,w,'decided');return;}
    // ONLINE no=589 rule 16 (3:3 = rematch): a round past maxRounds keeps the arena open for one more break + round.
    if(run.round>=C.maxRounds&&run.instance)run.instance.expiresAt=Math.max(run.instance.expiresAt||0,now+(C.breakSec+C.countSec+C.roundSec+C.finishRoundSec+C.finishMatchSec+300)*1000);
    run.phase='break';run.phaseEnd=now+C.breakSec*1000;placeSide(world,run,0);placeSide(world,run,1);return;}
  if(run.phase==='break'&&now>=run.phaseEnd){run.phase='count';run.phaseEnd=now+C.countSec*1000;return;}
  if(run.phase==='matchEnd'&&now>=run.phaseEnd)await closeRun(world,run);
}
async function enter(world,p,input,observer){
  requireNpc(world,p,observer?TOURNEY_JOBS.observe:TOURNEY_JOBS.enter,input);const t=T(world),d=dataOf(world),run=t.current;
  if(p.instanceId)fail(TOURNEY_TEXT.cannot,403);
  if(t.phase==='ended')fail(TOURNEY_TEXT.over,409);
  const g=guildRow(world,p),gid=g&&String(g.id);
  if(observer){
    if(gid&&t.seeds.includes(gid))fail(TOURNEY_TEXT.watchContender,403);
    if(!run||run.phase==='matchEnd')fail(TOURNEY_TEXT.noWatch,409);
  }else{
    if(!run)fail(TOURNEY_TEXT.cannot,409);if(run.phase!=='entry')fail(run.phase==='matchEnd'?TOURNEY_TEXT.ended:TOURNEY_TEXT.cannot,409);
    const s=run.sides.findIndex(x=>(t.rosters.get(x.guildId)||[]).some(r=>r.ref===socialRef(p)));
    if(s<0)fail(TOURNEY_TEXT.contenders,403);if(gid!==run.sides[s].guildId)fail(TOURNEY_TEXT.changed,403);
    run.sides[s].ids.add(p.id);
  }
  const exit={map:p.map,x:p.x,z:p.z};
  if(!run.instance){run.instance=await createInstance(world,{map:d.arena.map,members:[p],kind:'guildTournament',exit,durationMs:(d.waitingSec+C.readySec+C.maxRounds*(C.countSec+C.roundSec+C.finishRoundSec+C.breakSec)+C.finishMatchSec+300)*1000});}
  else{const instance=run.instance;world.emit(p.map,{type:'leave',actorId:p.id});p.instanceId=instance.id;p.map=instance.map;p.path=[];p.mount=null;p.pet=null;instance.admitted.add(p.characterId);instance.members.add(p.id);p.profile.instance={id:instance.id,kind:instance.kind,map:instance.map,exit:instance.exit};}
  const s=sideOf(run,p),[x,z]=observer?d.arena.observer:(s===0?d.arena.teamA:d.arena.teamB)[Math.max(0,run.sides[s].ids.size-1)%7];
  const at=run.instance.scene.nearest(Number(x)+.5,Number(z)+.5);if(at){p.x=at.x;p.z=at.z;}
  if(observer)run.observers.add(p.characterId);
  world.changed(p);await world.persist(p);if(!observer)world.emit(p.map,{type:'join',actorId:p.id});
  return {operation:observer?'observe':'enter'};
}
const coinOf=(d,coin)=>{const c=String(coin||'').toUpperCase();if(!['P','B'].includes(c)||!d.coins[c])fail(TOURNEY_TEXT.pick);return c;};
async function spendOrGive(world,p,changes){
  return serializeLife(p,async()=>{const db=world.data.itemDB;if(!db)fail('Item catalog is unavailable.',503);
    const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
    for(const [item,n] of changes){if(n<0&&!inv.remove(item,-n))return false;if(n>0&&!inv.add(item,n))fail(TOURNEY_TEXT.bagFull,409);}
    await commitLife(world,p,profile);world.emit(p.map,{type:'inventory',actorId:p.id,reason:'tourney'});return true;});
}
/** The match bets are taken on: the running match during its entry wait, else the next match with both sides known. */
function betMatch(t){
  if(t.phase!=='running'&&t.phase!=='registration')return null;
  if(t.current)return t.current.phase==='entry'?t.bracket.get(t.current.key):null;
  if(!t.bracket)return null;for(let i=t.cursor;i<t.order.length;i++){const m=t.bracket.get(t.order[i]);if(m.status==='pending'&&m.left&&m.right)return m;if(m.status==='pending')return null;}return null;
}
async function placeBet(world,p,input){
  requireNpc(world,p,TOURNEY_JOBS.bet,input);const t=T(world),d=dataOf(world),m=betMatch(t);if(!m)fail(TOURNEY_TEXT.betClosed,409);
  const coin=coinOf(d,input.coin),score=String(input.score),amount=Number(input.amount);
  if(!C.betScores.includes(score)||!Number.isInteger(amount)||amount<1||amount>C.betMax)fail(TOURNEY_TEXT.pick);
  if(!await spendOrGive(world,p,[[d.coins[coin],-amount]]))fail(TOURNEY_TEXT.coins);
  const bets=t.bets.get(m.key)||new Map();bets.set(socialRef(p),{coin,score,amount,at:world.now()});t.bets.set(m.key,bets); // an edited bet replaces the old one (207: those coins are lost)
  return {operation:'bet',key:m.key,text:TOURNEY_TEXT.bet};
}
async function claim(world,p,input){
  requireNpc(world,p,TOURNEY_JOBS.claim,input);const t=T(world),d=dataOf(world),coin=coinOf(d,input.coin),ref=socialRef(p),pool=t.pool.get(ref)||{P:0,B:0};
  const n=pool[coin]||0;if(n<=0)fail('There is no prize money to collect.');
  await spendOrGive(world,p,[[d.coins[coin],n]]);pool[coin]=0;t.pool.set(ref,pool);return {operation:'claim',coin,amount:n,text:TOURNEY_TEXT.collected};
}
async function donate(world,p,input){
  requireNpc(world,p,TOURNEY_JOBS.donate,input);const d=dataOf(world),coin=coinOf(d,input.coin),row=d.donation.find(r=>r.type===coin),amount=Number(input.amount);
  const g=guildRow(world,p);if(!g)fail(TOURNEY_TEXT.noGuild);if(!row.amounts.includes(amount))fail('Choose a donation amount.');
  if(!await spendOrGive(world,p,[[row.item,-amount]]))fail(TOURNEY_TEXT.items);
  const t=T(world),id=String(g.id),cur=t.donations.get(id)||{P:0,B:0};cur[coin]+=amount;t.donations.set(id,cur);
  const itemName=world.data.itemDB?.def?.(row.item)?.name||row.name;
  return {operation:'donate',coin,amount,text:TOURNEY_TEXT.donated.replace('<VALUE>',String(amount)).replace('<ITEM>',itemName)};
}
export function donationRanking(world){const t=T(world);return [...t.donations.entries()].map(([id,v])=>({id,total:v.P+v.B,P:v.P,B:v.B,...(guildInfo(world,guildById(world,id))||{name:''})}))
  .sort((a,b)=>b.total-a.total||String(a.name).localeCompare(String(b.name))).map((r,i)=>({...r,rank:i+1,candidate:i<C.candidateCount?24:25}));}
export async function tourneyCommand(world,p,input){
  dataOf(world);
  switch(input.operation){
    case 'seed':return requestSeed(world,p,input);
    case 'roster':return setRoster(world,p,input);
    case 'enter':return enter(world,p,input,false);
    case 'observe':return enter(world,p,input,true);
    case 'leave':{const run=T(world).current;if(!inRun(run,p))fail('You are not in a Guild Tournament match.');run.observers.delete(p.characterId);if(run.phase==='battle'&&sideOf(run,p)>=0)run.down.add(p.id);await exitInstance(world,p);return {operation:'leave'};}
    case 'bet':return placeBet(world,p,input);
    case 'claim':return claim(world,p,input);
    case 'donate':return donate(world,p,input);
    case 'info':requireNpc(world,p,TOURNEY_JOBS[input.operation],input);return {operation:'info'};
    case 'entries':case 'seeds':case 'ranking':case 'roster-info':{const job=TOURNEY_JOBS[input.operation==='roster-info'?'roster':input.operation];requireNpc(world,p,job,input);return {operation:input.operation};}
    default:fail('Choose a Guild Tournament operation.');
  }
}
const sideView=(world,run,s,t)=>({name:s.name,mark:s.mark,wins:s.wins,kills:s.kills,firstKills:s.firstKills,roster:t.rosters.get(s.guildId)||[],
  entrants:[...s.ids].map(id=>{const q=[...world.players.values()].find(x=>x.id===id);return q?{id,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:q.profile.level,down:run.down.has(id),hp:q.hp,maxHp:q.maxHp,shield:Number(q.shield)||0,maxShield:Number(q.stats?.maxShield)||0}:{id,down:true};})});
const coinCounts=(world,p)=>{try{const d=dataOf(world),inv=new AuthoritativeInventory(p.profile,world.data.itemDB);return {P:inv.count(d.coins.P),B:inv.count(d.coins.B)};}catch{return {P:0,B:0};}};
export function tourneySnapshot(world,p){
  const t=world.guildTournament;if(!t)return null;const now=world.now(),g=guildRow(world,p),gid=g&&String(g.id),ref=socialRef(p),run=t.current;
  const name=id=>id?(t.guilds.get(id)?.name||guildById(world,id)?.name||''):null;
  const out={season:t.season,phase:t.phase,locksAt:t.phase==='registration'?t.locksAt:null,cancelled:!!t.cancelled,champion:t.champion?{id:t.champion,name:name(t.champion)}:null,
    seeds:t.seeds.map((id,i)=>({seed:i+1,id,name:name(id)})),entries:[...t.guilds.values()].filter(r=>t.seeds.includes(r.id)).map((r,i)=>({...r,rank:i+1,seed:t.seeds.indexOf(r.id)+1})),
    bracket:t.bracket?[...t.bracket.values()].map(m=>({key:m.key,match:m.match,order:m.order,left:m.left?{id:m.left,name:name(m.left)}:null,right:m.right?{id:m.right,name:name(m.right)}:null,winner:m.winner===undefined?undefined:m.winner,wins:m.wins,status:m.status})):null,
    my:gid?{guildId:gid,seed:t.seeds.indexOf(gid)+1||null,master:g.master===ref,roster:t.rosters.get(gid)||[],
      members:g.master===ref?[...world.players.values()].filter(q=>!q.leaving&&g.members.some(m=>m.ref===socialRef(q))).map(q=>({characterId:q.characterId,name:q.profile.name,classIndex:Number(q.profile.classIndex)||0,level:q.profile.level})):undefined}:null,
    pool:t.pool.get(ref)||{P:0,B:0},coins:coinCounts(world,p),results:t.results.slice(-15),ranking:(t.donations.size?donationRanking(world):t.finalRanking||[]).slice(0,255)};
  const bm=betMatch(t);if(bm)out.betting={key:bm.key,match:bm.match,order:bm.order,left:name(bm.left),right:name(bm.right),scores:C.betScores,ratios:betRatios([...(t.bets.get(bm.key)||new Map()).values()]),mine:t.bets.get(bm.key)?.get(ref)||null};
  if(run)out.match={id:run.id,key:run.key,match:run.match,order:run.order,phase:run.phase,remainingMs:Math.max(0,run.phaseEnd-now),round:run.round,rounds:run.rounds,roundKills:run.roundKills,firstKill:run.firstKill,
    sides:run.sides.map(s=>sideView(world,run,s,t)),mySide:sideOf(run,p),inside:inRun(run,p),observer:isTourneyObserver(world,p),down:run.down.has(p.id),result:run.result};
  return out;
}