import {describeResult} from '../build-skills.mjs';

// Sentry attack blocks only; the general 1100xxx family remains unchanged.
// A11 registration/RTTI proves MonsterFire/Ice/Lightning Area (1100301/3/5)
// and MonsterKnockBackMelee Area (1100331). SyncActorMgr +0x18 reads Arg1
// at 0x588c79, scaled by exactly 1/128 at 0x588c94.
const AREA=new Map([[1100301,'fire'],[1100303,'ice'],[1100305,'lightning'],[1100331,null]]);
function decodedArea(code,args){
 if(!AREA.has(Number(code)))return null;
 const a=(args||[]).map(Number),element=AREA.get(Number(code));
 const out={resultCode:Number(code),family:'damage',kind:'damage',shape:'area',damageClass:element?'magic':'melee',radius:(a[0]||0)/128,addDamage:a[2]||0};
 if(element){out.element=element;if(a[1])out.elementPct=a[1];}
 if(a[4]){out.statusIndex=a[4];out.chance=a[3];if(a[5])out.statusDurationMs=a[5];}
 if(Number(code)===1100331)out.knockback=true;
 return out;
}
export function describeSentryResult(code,args,ctx){
 const out=describeResult(code,args,ctx),direct=decodedArea(code,args);if(direct)return {...out,...direct};
 // A11 0x58A321 -> ctor0x5AA3C0 -> vtable0xA1B5F4 identifies
 // 1000112 as FireFar@Single@Attack. Preserve the shared decoder elsewhere.
 if(Number(code)===1000112)out.element='fire';
 if(out.family==='projectile'){
  const impactCode=ctx?.remotes?.get(Number(args?.[0]))?.resultType,impact=decodedArea(impactCode,args.slice(1));
  if(impact){out.impact={resultCode:impact.resultCode,family:impact.family,kind:impact.kind,shape:impact.shape};for(const [k,v]of Object.entries(impact))if(!['resultCode','family','kind','shape'].includes(k))out[k]=v;}
  if(Number(impactCode)===1000112)out.element='fire';
 }
 return out;
}
