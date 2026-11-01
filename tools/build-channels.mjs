// Builds gamedata/channels.json from the ORIGINAL client files (read-only; parsing in src/systems/channels/channel-rules.js):
//   share/channellist.csv  field channels (group 15, asserted equal to 16): Divine Valley, Kalibus, nonPK, PK.
//   share/dkmaplist.csv    DK maps: locates (LocateDKChannel, LocateDscript, LocateDK_Index), LocatePos, respawn, costs.
//   stringtable_system 9000|DK_Index names, stringtable_chat 230|94-95 move texts.
// The engine never needs this file: the host reads the same tables when it is absent and the client reads them from /data/.
// usage: node tools/build-channels.mjs [--data <unpacked data root>] [--out <dir>]   (prepare-client step 'channels')
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {readChannelTables} from '../server/world/channel-data.mjs';
const ENGINE=fileURLToPath(new URL('..',import.meta.url)),argv=process.argv.slice(2),arg=k=>{const i=argv.indexOf(k);return i>=0?argv[i+1]:null;};
const DEFAULT_DATA=path.resolve(arg('--data')||process.env.DEKARON_DATA||path.resolve(ENGINE,'..','data','unpacked','data'));
export function buildChannels(dataRoot=DEFAULT_DATA){
  return {generatedBy:'tools/build-channels.mjs',sources:['share/channellist.csv (group 15)','share/dkmaplist.csv','stringtable_system 9000','stringtable_chat 230|94-95'],...readChannelTables(dataRoot)};
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
  const out=buildChannels(),dir=path.resolve(arg('--out')||path.join(ENGINE,'gamedata'));fs.mkdirSync(dir,{recursive:true});fs.writeFileSync(path.join(dir,'channels.json'),JSON.stringify(out,null,1)+'\n');
  console.log(`channels.json: ${out.field.length} field channels (${out.field.map(c=>c.name).join(', ')}), ${Object.keys(out.dkMaps).length} DK maps, ${Object.keys(out.dkNames).length} DK names`);
}