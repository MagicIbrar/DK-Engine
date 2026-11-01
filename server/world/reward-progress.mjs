// Keep the native level-up path. Sum only the earned interval, rather than two
// lifetime XP totals: the latter exceed Number's integer precision at high levels.
export function mergeRewardProgress(world,live,before,candidate,prepared){
 let exp=(live.profile.exp||0)-(before.exp||0);
 for(let level=before.level;level<live.profile.level;level++)exp+=world.data.expNeeded(level);
 const dil=(live.profile.dil||0)-(before.dil||0),notices=[];
 if(!(exp>0)&&!dil)return {notices,levelChanged:false,hpGain:0,mpGain:0};
 const hp=candidate.hp,mp=candidate.mp||0,initialLevel=candidate.profile.level;
 // A scene-specific writer may have already copied currency into the candidate.
 // Rebase on the prepared value so every accepted gain is applied exactly once.
 candidate.profile.dil=prepared.dil||0;
 const staged=Object.create(world);staged.emit=(map,event)=>{if(event.type!=='levelup'||event.level>live.profile.level)notices.push([map,event]);};
 staged.grantProgress(candidate,Math.max(0,exp),dil);
 return {notices,levelChanged:candidate.profile.level!==initialLevel,hpGain:Math.max(0,candidate.hp-hp),mpGain:Math.max(0,(candidate.mp||0)-mp)};
}
