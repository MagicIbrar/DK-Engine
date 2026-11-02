// Three user-facing V views; hover reveals details without changing the saved mode.
// The tag is cosmetic and is never an authority source. Only the host/session can authorize it.
export function authorizedStaffTag(name,account,authorized) {
 if(authorized!==true)return null;
 const match=/^\[(ADMIN|GM|DEV)\]/i.exec(String(name||'').trim());
 if(match)return match[1].toUpperCase();
 const fallback=String(account||'').trim().toUpperCase();
 return ['ADMIN','GM','DEV'].includes(fallback)?fallback:'GM';
}
export function playerNameplateName(name,info={}) {
 const text=String(name||''),tag=['ADMIN','GM','DEV'].includes(info?.staffTag)?info.staffTag:null;
 let bare=text.replace(/^ *(?:\[(?:ADMIN|GM|DEV)\]\s*)+/i,'');
 if(tag==='ADMIN')bare=bare.replace(/^Admin(?=[A-Z])/,'');
 return tag?'['+tag+']'+(bare?' '+bare:''):bare;
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
