import {createHash} from 'node:crypto';

// Explicit compatibility supplement, not a claim of a recovered Global server.
// Rising 26.10.100 primary awakening/transform.csv agrees with ALL 84 native
// rows and adds these 21 rows. Shape/material assets already ship in Global.
export const TRANSFORM_COMPATIBILITY = Object.freeze({
  source: 'Rising 26.10.100 share/skill/awakening/transform.csv',
  referenceSHA256: '2dfad30ea90755967f26bfdd390d4e9c4afeff96c81e6997ee6460b39cae0132',
  nativeSHA256: '768e6786c0d326afa86d8d51871591d299a384529a9f699b610b4a6dd8914220',
  skillShapes: Object.freeze({2481:40201,2681:51041,2901:51503}),
});

export function supplementTransforms(raw, transforms, shapes, has) {
  if (createHash('sha256').update(raw).digest('hex') !== TRANSFORM_COMPATIBILITY.nativeSHA256) return [];
  if ([...transforms.values()].reduce((n,rows)=>n+rows.length,0)!==84) return [];
  const pending=[];
  for (const [key,base] of Object.entries(TRANSFORM_COMPATIBILITY.skillShapes)) {
    const id=Number(key);if(transforms.has(id))return [];
    const rows=[];
    for(let level=1;level<=7;level++) {
      const shape=shapes.get(base+level-1);
      if(!shape?.mesh||!shape?.tpack||!has(shape.mesh)||!has(shape.tpack))return [];
      rows.push({level,endEffect:0,transType:level<=3?1:level<=5?2:3,args:[base+level-1,...Array(15).fill(0)],
        compatibilitySource:TRANSFORM_COMPATIBILITY.source});
    }
    pending.push([id,rows]);
  }
  for(const [id,rows] of pending)transforms.set(id,rows);
  return pending.map(([id,rows])=>({skill:id,levels:rows.length,source:TRANSFORM_COMPATIBILITY.source,referenceSHA256:TRANSFORM_COMPATIBILITY.referenceSHA256}));
}
