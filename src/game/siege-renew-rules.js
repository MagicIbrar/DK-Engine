// Native Renew data shape only. Do not inherit classic map23 combat/admission
// constants: the supplied Help Book describes the old Zenoa rules, not these
// three GUILD castles. This parser does not define undocumented server rules.
const first=value=>Array.isArray(value)?value[0]:value;
const number=value=>{const n=Number(first(value));return Number.isFinite(n)?n:0;};

export function siegeRenewConfig(mode) {
 const c=mode?.config||{};
 return {guildLevel:number(c.LEVEL),members:number(c.MEMBERCOUNT),capacity:number(c.ENTERPCCOUNT),startWeekday:number(c.START_WEEK),startHour:number(c.START_HOUR),durationMs:number(c.PLAY_KEEP_TIME)*1000,
  maxSentry:number(c.MAXSENTRY),sentryUpgradeCost:number(c.SENTRY_UPGRADE_COST),sentryIndexes:(c.SENTRY_INDEX||[]).slice(0,number(c.SENTRY_COUNT)).map(Number),observerCapacity:number(c.OBSERVER_COUNT),
  taxRatio:number(c.TAX_RATIO),taxHour:number(c.TAX_HOUR),taxMinute:number(c.TAX_MINUTE),
  castles:Array.from({length:number(c.MAP_COUNT)},(_,index)=>({map:number(c[`MAP_${index+1}_INDEX`]),channel:number(c[`MAP_${index+1}_CHANNEL`])})).filter(row=>row.map>0)};
}

export function siegeRenewGateGroups(mode,map) {
 const rows=mode?.gateUpgrade||[],header=rows.find(row=>row[0]==='Name'&&row[1]==='MapIndex'),row=rows.find(row=>Number(row[1])===Number(map));
 if(!header||!row)return [];
 return Array.from({length:number(row[2])},(_,group)=>header.flatMap((key,index)=>key.startsWith(`GateIndex${group}_`)&&number(row[index])>0?[number(row[index])]:[]));
}

export function siegeRenewUpgradePrices(mode) {
 const rows=mode?.gateUpgrade||[],count=number(rows.find(row=>row[0]==='UpgradeCount')?.[1]),header=rows.findIndex(row=>row[0]==='UpgradePrice0');
 return header<0?[]:rows[header+1]?.slice(0,count).map(number)||[];
}

export function siegeRenewCastles(eventData) {
 const ev=eventData?.ev||eventData||{},mode=ev.modes?.siegeRenew,cfg=siegeRenewConfig(mode);
 return cfg.castles.map(({map,channel})=>{
  const row=ev.maps?.[map]||{},placements=(row.bricks||[]).map(([uid,brick,x,z,dir,isCreate])=>({uid,brick,x,z,dir,isCreate,def:ev.bricks?.[brick]||null})),groups=siegeRenewGateGroups(mode,map);
  const missingGates=groups.flat().filter(uid=>!placements.some(row=>Number(row.uid)===uid));
  // location.csv's MapIndex identifies the castle service, while the resolved
  // LocationIndex can lead out to Ardeca (types3/6). Keep both identities.
  const locations=(mode?.locationsResolved||[]).filter(row=>Number(mode?.location?.find(raw=>Number(raw.Index)===Number(row.index))?.MapIndex??row.location?.mapIndex)===map&&row.location).map(row=>({index:Number(row.index),type:Number(row.type),map:Number(row.location.mapIndex),x:Number(row.location.x)+.5,z:Number(row.location.y)+.5,dirDeg:Number(row.location.directionDeg)||0,name:row.location.name}));
  return {map,channel,name:row.name||`Map ${map}`,active:Number(row.flags?.isUseMap)===1,cfg,groups,upgradePrices:siegeRenewUpgradePrices(mode),locations,placements,missingGates,deployMask:mode?.deployMasks?.[map]||null};
 });
}
