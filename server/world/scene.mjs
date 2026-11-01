// channel: field Channel Index (0 = the base scene key) or a DK channel key (channels.mjs). Instances ignore it.
export const sceneKey=(map,instanceId=null,channel=0)=>instanceId?`${Number(map)}@${instanceId}`:channel?`${Number(map)}#${channel}`:Number(map);
export const sameScene=(a,b)=>Number(a.map)===Number(b.map)&&(a.instanceId||null)===(b.instanceId||null)&&(!!a.instanceId||(a.channel||0)===(b.channel||0));
export const mapFor=(world,p)=>world.maps.get(sceneKey(p.map,p.instanceId,p.channel||0));
