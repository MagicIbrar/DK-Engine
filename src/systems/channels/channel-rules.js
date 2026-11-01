// Channel rules shared by the host (server/world/channels.mjs) and the client (sysmenu channel list, DK portal chooser).
// Data: gamedata/channels.json (tools/build-channels.mjs) = share/channellist.csv group 15 field channels,
// share/dkmaplist.csv DK maps, stringtable_system 9000|DK_Index names, stringtable_chat 230|94-95.
// A channel value is the field Channel Index (0..3) or the DK channel key `dk<DK_Index>` (dk100 = 9000|100 "Server 1").
export const dkChannelKey=dkIndex=>`dk${Number(dkIndex)}`;
export const isDkChannel=channel=>typeof channel==='string'&&/^dk\d+$/.test(channel);
export const dkIndexOf=channel=>isDkChannel(channel)?Number(channel.slice(2)):null;
export const fieldChannel=(data,channel)=>Number.isInteger(channel)?data?.field?.find(c=>c.index===channel)||null:null;
export function validChannel(data,channel){return isDkChannel(channel)?Object.hasOwn(data?.dkNames||{},String(dkIndexOf(channel))):!!fieldChannel(data,channel);}
export function channelName(data,channel){
  if(isDkChannel(channel))return data?.dkNames?.[dkIndexOf(channel)]??null;
  return fieldChannel(data,channel)?.name??null;
}
/** 230|94 "You have moved to the <CHANNEL>." for field channels, 230|95 for a DK channel. */
export function movedText(data,channel){
  if(isDkChannel(channel))return data?.texts?.movedDk||'';
  return String(data?.texts?.moved||'').replace('<CHANNEL>',channelName(data,channel)||'');
}
export const dkMap=(data,map)=>data?.dkMaps?.[Number(map)]||null;
/** Entry choices of a DK map: one per LocateCount slot (LocateDscript label, 9000|DK_Index name). */
export function dkLocates(data,map){const row=dkMap(data,map);return (row?.locates||[]).map((l,i)=>({index:i,dkIndex:l.dkIndex,channel:dkChannelKey(l.dkIndex),script:l.script,name:data?.dkNames?.[l.dkIndex]??l.script}));}
/** dkmaplist RespawnType: DEFAULT -> RespawnPos 0, NEARBY -> the closest listed RespawnPos, NONE (or no row) -> no DK respawn. */
export function dkRespawn(data,map,x,z){
  const row=dkMap(data,map),list=(row?.respawn||[]).filter(r=>Number(r[0])===Number(map));
  if(!row||!list.length||row.respawnType==='NONE')return null;
  const pick=row.respawnType==='NEARBY'?list.reduce((a,b)=>Math.hypot(b[1]-x,b[2]-z)<Math.hypot(a[1]-x,a[2]-z)?b:a):list[0];
  return {map:Number(pick[0]),x:Number(pick[1]),z:Number(pick[2])};
}
// ---- table parsing (shared by tools/build-channels.mjs, server/world/channel-data.mjs and the client loader ./data.js)
const num=v=>v===''||v==null?0:Number(v);
const cell=v=>String(v??'').trim();
const rowsOf=t=>(t||[]).map(r=>r.map(cell)).filter(r=>r.join(''));
/** DK_Index values referenced by dkmaplist (LocateCount x LocateDK_Index), i.e. the 9000|code names needed. */
export function dkIndexesOf(dkmaplist){const out=new Set();for(const r of rowsOf(dkmaplist).slice(1))for(let k=0;k<num(r[1]);k++)if(num(r[4+k*3]))out.add(num(r[4+k*3]));return [...out].sort((a,b)=>a-b);}
/**
 * share/channellist.csv: groups 8/9/15/16 carry the same 4 channels; group 15 (newest, IsFreePK on PK) is the field list
 * and group 16 must match. share/dkmaplist.csv is read by position (its header repeats RespawnPosX_00).
 * dkNames = {DK_Index: 9000|DK_Index}, texts = {moved: 230|94, movedDk: 230|95}.
 */
export function parseChannelTables({channellist,dkmaplist,dkNames={},texts={}}){
  const [ch=[],...cl]=rowsOf(channellist),col=n=>ch.indexOf(n);
  const group=g=>cl.filter(r=>num(r[col('Group')])===g).map(r=>({index:num(r[col('Channel Index')]),name:r[col('Name')],nonPkLevelCap:num(r[col('Non_PK_LevelCap')]),freePk:num(r[col('IsFreePK')])===1}));
  const field=group(15);
  if(!field.length||JSON.stringify(field)!==JSON.stringify(group(16)))throw Error('channellist groups 15/16 differ');
  const dkMaps={};
  for(const r of rowsOf(dkmaplist).slice(1)){const map=num(r[0]),count=num(r[1]);if(!count)continue;const locates=[];for(let k=0;k<count;k++)locates.push({dkChannel:num(r[2+k*3]),script:r[3+k*3],dkIndex:num(r[4+k*3])});
    const respawn=[];for(let k=0;k<Math.min(2,num(r[17]));k++)respawn.push([num(r[18+k*3]),num(r[19+k*3]),num(r[20+k*3])]);
    dkMaps[map]={locates,locate:[num(r[14]),num(r[15])],respawnType:r[16],respawn,costItems:[num(r[24]),num(r[25])].filter(Boolean),cashCostItems:[num(r[26]),num(r[27])].filter(Boolean),cashLocate:[num(r[28]),num(r[29])]};}
  const names={};for(const i of dkIndexesOf(dkmaplist))if(dkNames[i])names[i]=dkNames[i];
  return {format:1,field,dkNames:names,dkMaps,texts:{moved:texts.moved||'',movedDk:texts.movedDk||''}};
}