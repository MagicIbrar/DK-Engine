// Client channel data, read from the ORIGINAL client files under /data/ (never a /gamedata/ file, so test or
// player gamedata folders without channels.json load cleanly): share/channellist.csv, share/dkmaplist.csv,
// 9000|DK_Index (SYSTEM) and 230|94-95. Parsing is shared with the host/builder (./channel-rules.js parseChannelTables).
import {fetchCSV} from '../../engine/assets.js';
import {strAsync} from '../hud-options/util.js';
import {parseChannelTables,dkIndexesOf} from './channel-rules.js';
let pending=null;
export function loadChannelData(){
  return pending||=(async()=>{
    const [channellist,dkmaplist]=await Promise.all([fetchCSV('share/channellist.csv'),fetchCSV('share/dkmaplist.csv')]);
    const dkNames={};await Promise.all(dkIndexesOf(dkmaplist).map(async i=>{const v=await strAsync(9000,i,'SYSTEM');if(v)dkNames[i]=v;}));
    const [moved,movedDk]=await Promise.all([strAsync(230,94),strAsync(230,95)]);
    return parseChannelTables({channellist,dkmaplist,dkNames,texts:{moved,movedDk}});
  })().catch(error=>{pending=null;throw error;});
}