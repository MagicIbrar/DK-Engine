// Global PcPopWnd click refusals shared by the pcpop rows (lane 62, docs/global-parity-420/PLAYER-CARD-PARITY.md).
// Sources (Global 64-bit decompile, Ghost::UIHandler::Handler::Common::PcPopWnd click handler + its helpers):
//   240:31  Duel (row 5) and Party PvP (row 8): the current (server group, channel) row is looked up in
//           share/channellist.csv; no row, or a nonzero Non_PK_LevelCap on that row, refuses with 240:31.
//           4.2.0 field channels are channellist group 15 (channel-rules.js); a DK channel key has no channellist row.
//           An older host that sends no channel is not refused here (the host still owns the rule).
//   101:167 Duel (row 5) and Trade (row 2): OX Quiz map (Connect map index 22, maplist 22 ScriptName Map_22_OX_Quiz).
//   280:65  Party PvP (row 8): siege map (maplist IsSiege) or party-war map (LogicObject::PartyWar::Provider).
//   556:38  Character Transfer (row 11): while a Party PvP is running.
import {fieldChannel,isDkChannel} from '../channels/channel-rules.js';
export const PCPOP_OX_MAP=22;
let channelData=null,channelLoad=null;
/** Inject (tests) or lazily load the client channel tables. */
export function setPcPopChannelData(data){channelData=data||null;channelLoad=null;}
async function channels(){
  if(channelData)return channelData;
  channelLoad||=import('../channels/data.js').then(m=>m.loadChannelData()).then(d=>channelData=d).catch(()=>{channelLoad=null;return null;});
  return channelLoad;
}
/** true when Global would print 240:31 for the current channel; null when the channel or data is unknown. */
export async function nonPkChannel(network){
  const ch=network?.self?.channel;
  if(ch===undefined||ch===null)return null;
  if(isDkChannel(ch))return true;
  const data=await channels();
  if(!data)return null;
  const row=fieldChannel(data,Number(ch));
  return !row||Number(row.nonPkLevelCap)!==0;
}
export const onOxMap=network=>Number(network?.self?.map)===PCPOP_OX_MAP;
export const siegeOrPartyWarMap=(game,network)=>!!game?.zones?.flags?.siege||!!game?.eventsSystem?.ownsMap?.(Number(network?.self?.map));
export const partyWarMap=(game,network)=>!!game?.eventsSystem?.ownsMap?.(Number(network?.self?.map));
/** PartyPVP::Handler state nonzero: any live Party PvP record (invited, setup, wait, fight); a finished one is not. */
export const partyPvpRunning=network=>{const s=network?.partyPvp?.state?.()||{};return !!s.id&&!!s.phase&&s.phase!=='over';};
