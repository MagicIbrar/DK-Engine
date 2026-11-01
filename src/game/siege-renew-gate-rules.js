// ENGINE-CHOSEN reconstruction where all supplied clients omit gate placements.
// UIDs/groups/prices/models and default/max HP are native. Cells are the actual
// MAC doorways adjoining native strongholds; sizes use native half extents.
// See sol-parity-siege-sweep-20261013.md for proof and remaining provenance limits.
const rows={
 193:[
  [19301,36998,360.5,278.5,0],[19302,36998,360.5,286.5,0],[19303,36998,360.5,294.5,0],
  [19304,37000,314.5,286.5,0],[19305,36999,313.5,210.5,90],[19306,37001,313.5,357.5,90],[19307,37002,165.5,285.5,0],
 ],
 194:[
  [19401,37005,384.5,248.5,0],[19402,37006,384.5,242.5,0],[19403,37006,384.5,254.5,0],
  [19404,37003,384.5,158.5,0],[19405,37004,384.5,152.5,0],[19406,37004,384.5,164.5,0],
  [19407,37007,384.5,338.5,0],[19408,37008,384.5,332.5,0],[19409,37008,384.5,344.5,0],
  [19410,37009,299.5,246.5,0],[19411,37010,199.5,246.5,0],
 ],
 195:[[19501,37011,289.5,236.5,0],[19502,37012,243.5,237.5,0]],
};
export const RENEW_GATE_LAYOUT=Object.freeze(Object.fromEntries(Object.entries(rows).map(([map,list])=>[map,Object.freeze(list.map(([uid,brick,x,z,dir])=>Object.freeze({uid,brick,x,z,dir})))])));
export function renewGateLevel(level,max=5){return Math.max(0,Math.min(max,Math.trunc(Number(level)||0)));}
// Five native upgrade prices, no native per-level HP formula: interpolate within
// the original default/max range; never invent stronger HP than the source cap.
export function renewGateHP(def,level,steps=5){const min=Math.max(1,Number(def?.defaultHP)||Number(def?.maxHP)||1),max=Math.max(min,Number(def?.maxHP)||min);return Math.round(min+(max-min)*renewGateLevel(level,steps)/Math.max(1,steps));}
export function renewGateRows(castle,eventData){
 const rows=RENEW_GATE_LAYOUT[castle?.map]||[],ev=eventData?.ev||eventData||{};
 return rows.map(row=>({...row,group:castle.groups.findIndex(ids=>ids.includes(row.uid)),def:ev.bricks?.[row.brick]||null}));
}
