// Node reader for the original channel tables (read-only): used by tools/build-channels.mjs and, when
// gamedata/channels.json is absent (test gamedata folders), by server/world/channels.mjs directly.
import fs from 'node:fs';
import path from 'node:path';
import {parseCSV} from '../../src/formats/binreader.js';
import {parseChannelTables} from '../../src/systems/channels/channel-rules.js';
function cate(text,id){const out={};const m=new RegExp(`<cate>\\s*${id}\\b([\\s\\S]*?)</cate>`).exec(text);if(!m)return out;for(const c of m[1].matchAll(/code\s+(\d+)[^\n]*\r?\n\{\r?\n([^}]*)\}/g))out[c[1]]=c[2].replace(/\r/g,'').trim();return out;}
export function readChannelTables(dataRoot){
  const raw=rel=>fs.readFileSync(path.join(dataRoot,rel),'latin1');
  const chat=cate(raw('script/string/normal/stringtable_chat.txt'),230);
  return parseChannelTables({channellist:parseCSV(raw('share/channellist.csv')),dkmaplist:parseCSV(raw('share/dkmaplist.csv')),
    dkNames:cate(raw('script/string/system/stringtable_system.txt'),9000),texts:{moved:chat['94'],movedDk:chat['95']}});
}