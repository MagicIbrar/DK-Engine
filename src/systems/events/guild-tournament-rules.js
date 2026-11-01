// Guild Tournament rules shared by the host (server/world/guild-tournament.mjs), the client windows and the tests.
// Data: gamedata/events.json modes.colosseum.guildMatch (share/colosseum/guildmatch/list.csv + share/guildtournament/*).
// ENGINE-CHOSEN values: src/config/engine-chosen-guild-tournament.js.
import {GUILD_TOURNAMENT_ENGINE_CHOSEN as C} from '../../config/engine-chosen-guild-tournament.js';
const n=v=>Number(Array.isArray(v)?v[0]:v);
/** Tournament tables from the event data (null when the data is missing). */
export function tournamentData(modes){
  const g=modes?.colosseum?.guildMatch,t=g?.tournament;if(!g||!t)return null;
  const listIndex=n(t.config.GUILDMATCH_LIST_INDEX)||1,arena=(g.maps||[]).find(m=>Number(m.index)===listIndex)||g.maps?.[0];if(!arena)return null;
  const donation=(t.donation||[]).map(r=>({type:String(r.Type).startsWith('P')?'P':'B',name:String(r.Type),item:Number(r.ItemIndex),
    amounts:Array.from({length:Number(r.DonationCount)||0},(_,i)=>Number(r[`Donation${i}`])).filter(v=>v>0)}));
  const bracket=(t.bracket||[]).map(r=>({match:Number(r.MATCH),order:Number(r.ORDER),nextMatch:Number(r.NEXTMATCH),nextOrder:Number(r.NEXTORDER),nextSeed:Number(r.NEXTSEED)}));
  return {listIndex,defaultMatch:n(t.config.DEFAULT_MATCH)||16,defaultOrder:n(t.config.DEFAULT_ORDER)||1,waitingSec:n(t.config.WAITING_TIME)||180,
    arena:{map:Number(arena.map),members:Number(arena.members)||7,teamA:arena.teamA,teamB:arena.teamB,observer:arena.observer},donation,bracket,
    coins:Object.fromEntries(donation.map(d=>[d.type,d.item]))};
}
export const matchKey=(match,order)=>`${match}:${order}`;
/** Seed slots of the first round (match.csv DEFAULT_MATCH rows x 2). */
export const seedCount=data=>data.bracket.filter(r=>r.match===data.defaultMatch).length*2;
/** Every bracket match with its sides; first-round sides come from the seeds (order k: seeds 2k-1 / 2k). */
export function buildBracket(data,seeds){
  const out=new Map();
  for(const r of [...data.bracket].sort((a,b)=>b.match-a.match||a.order-b.order)){
    const first=r.match===data.defaultMatch;
    out.set(matchKey(r.match,r.order),{key:matchKey(r.match,r.order),match:r.match,order:r.order,left:first?seeds[2*r.order-2]??null:null,right:first?seeds[2*r.order-1]??null:null,
      next:r.nextMatch?{key:matchKey(r.nextMatch,r.nextOrder),slot:r.nextSeed===1?'left':'right'}:null,winner:undefined,wins:[0,0],status:'pending'});
  }
  return out;
}
/** Play order: Round of 16 first (order 1..8), then 8, 4 and the final. */
export const playOrder=bracket=>[...bracket.values()].map(m=>m.key);
/** Put the winner (or null when nobody advances) into the next match slot. */
export function advance(bracket,m,winner){m.winner=winner??null;m.status='done';if(m.next){const nx=bracket.get(m.next.key);if(nx)nx[m.next.slot]=winner??null;}}
/** A match that can be decided without fighting: a bye (one side), nobody (no side). */
export function walkover(m){if(m.left&&m.right)return undefined;return m.left||m.right||null;}
/** Round result: 0 = left, 1 = right, -1 = draw. alive/kills = [left, right]. */
export function roundOutcome({alive,kills},reason){
  if(reason==='annihilation'){if(alive[0]>0&&alive[1]===0)return 0;if(alive[1]>0&&alive[0]===0)return 1;return -1;}
  return kills[0]>kills[1]?0:kills[1]>kills[0]?1:-1;
}
/** After a round: winner index when the match is decided, null to play on. */
export function matchOutcome({wins,rounds,kills,firstKills},roundsToWin=C.roundsToWin){
  if(wins[0]>=roundsToWin)return 0;if(wins[1]>=roundsToWin)return 1;
  if(rounds<roundsToWin*2-1)return null;
  if(wins[0]!==wins[1])return wins[0]>wins[1]?0:1;
  if(kills[0]!==kills[1])return kills[0]>kills[1]?0:1;
  if(firstKills[0]!==firstKills[1])return firstKills[0]>firstKills[1]?0:1;
  return 0; // the lower (left) seed
}
/** Final score label used by the betting window ('2:0' ...), left first. */
export const scoreLabel=wins=>`${wins[0]}:${wins[1]}`;
/** Round title string (stringtable_colosseum 360): 16 -> 130 Round of 16, 8 -> 131, 4 -> 132, 2 -> 133 Total Final. */
export const roundTitleCode=match=>({16:130,8:131,4:132,2:133})[Number(match)]||130;
/** Round label of a round inside a match (360|79 Round 1, 78 Round 2, 77 Round 3). */
export const roundCode=i=>[79,78,77][i]??76;
/** Betting payout for one bet. */
/** Pool split per coin: every coin bet on the match / the coins bet on each score (null = nobody bet that score). */
export function betRatios(bets){const total={P:0,B:0},on={P:{},B:{}};for(const b of bets){if(!(b.coin in total))continue;total[b.coin]+=b.amount;on[b.coin][b.score]=(on[b.coin][b.score]||0)+b.amount;}
  return Object.fromEntries(Object.keys(total).map(c=>[c,Object.fromEntries(C.betScores.map(s=>[s,on[c][s]?total[c]/on[c][s]:null]))]));}
export function betPayout(bet,result,ratios){return bet.score===result?Math.floor(bet.amount*(ratios?.[bet.coin]?.[bet.score]||0)):0;}
/** Bracket label positions (ui_tournamentinfownd / ui_requestseedwnd templates lbl_16_ / lbl_8_). */
export function bracketRect(base,round,i,layout=C.layout){const step=round===16?layout.bracket16:layout.bracket8;return [base[0],base[1]+i*step,base[2],base[3]];}
/** Class index -> class string (360|56-62, 210, 211). */
export const CLASS_CODES=Object.freeze([56,57,58,59,60,61,62,210,211]);