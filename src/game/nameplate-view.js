// Three user-facing V views; hover reveals details without changing the saved mode.
export function playerNameplateName(name,info={}) {
 const text=String(name||'');
 if(info?.staffTag!=='ADMIN')return text;
 const bare=text.replace(/^(?:\[ADMIN\]\s*)+/i,'').replace(/^Admin(?=[A-Z])/,'');
 return '[ADMIN] '+(bare||text);
}
export function nameplateView(options) {
 if(options?.get?.('charName')===false)return 2;
 return options?.get?.('nameView')===1?1:0;
}
export function nextNameplateView(options) {
 const mode=(nameplateView(options)+1)%3;
 return {nameView:mode,charName:mode!==2};
}
export function playerNameplateDetails(info={},options,hovered=false) {
 const full=hovered||nameplateView(options)===0;
 const on=key=>hovered||options?.get?.(key)!==false;
 return {guild:full&&on('guildName')?info.guild:null,alliance:full&&on('allianceName')?info.alliance:null,
  title:full&&on('titleName')?info.title||'':'',rank:full&&on('ratingName')?[info.grade,Number.isSafeInteger(info.dkTier)&&info.dkTier>0?'DK Tier '+info.dkTier:''].filter(Boolean).join(' · '):''};
}
