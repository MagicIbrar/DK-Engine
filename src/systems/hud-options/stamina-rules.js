// Current Global CombatHelper guide31: per-character 60/day, one/minute, full daily recovery at00:00.
// https://dekaron.ubifungames.com/Board/GameGuide?guideNo=31
// ENGINE-CHOSEN calendar zone: existing engine server-local date policy. The Global server timezone is unverified.
export const DAILY_STAMINA=60;
export const MINUTE_MS=60000;
export const DEFAULT_STAMINA_CAP=65530; // native item description1289; other item captions carry their own cap.
export const serverLocalDay=now=>{const d=new Date(now);return `${d.getFullYear()}-${d.getMonth()+1}-${d.getDate()}`;};
const nonnegative=v=>Number.isFinite(Number(v))?Math.max(0,Number(v)):0;
export function staminaState(profile,now){
 const day=serverLocalDay(now);let s=profile.battleSupport;
 if(!s||s.v!==1){
  // Legacy stamina was obtained from native potions; preserve it and add the newly implemented free allowance once.
  s=profile.battleSupport={v:1,day,dailyRemaining:DAILY_STAMINA,partialMs:0};
  profile.staminaMax=Math.max(DEFAULT_STAMINA_CAP,nonnegative(profile.staminaMax));profile.stamina=Math.min(profile.staminaMax,nonnegative(profile.stamina)+DAILY_STAMINA);
 }else{
  s.dailyRemaining=Math.min(DAILY_STAMINA,nonnegative(s.dailyRemaining));s.partialMs=Math.min(MINUTE_MS-1,nonnegative(s.partialMs));
  profile.stamina=nonnegative(profile.stamina);profile.staminaMax=Math.max(DAILY_STAMINA,nonnegative(profile.staminaMax)||DEFAULT_STAMINA_CAP);
  if(s.day!==day){profile.stamina=Math.min(profile.staminaMax,profile.stamina+DAILY_STAMINA-s.dailyRemaining);s.day=day;s.dailyRemaining=DAILY_STAMINA;s.partialMs=0;}
 }
 return s;
}
export function consumeStamina(profile,minutes,now){
 const s=staminaState(profile,now),cost=Math.min(nonnegative(minutes),profile.stamina);
 // ENGINE-CHOSEN accounting order: spend the daily allowance before paid stamina; preserve paid remainder on reset.
 s.dailyRemaining=Math.max(0,s.dailyRemaining-cost);profile.stamina=Math.max(0,profile.stamina-cost);return cost;
}
export function staminaRecoveryCap(db,def){
 const text=String(db?.description?.(def)||'').replace(/<[^>]*>/g,'');
 const match=/(?:maximum|max|up to)[^\d\n]{0,35}(\d{3,6})/i.exec(text),cap=Number(match?.[1]);
 return Number.isSafeInteger(cap)&&cap>0?cap:null;
}
export function recoverStamina(profile,amount,cap,now){
 if(!(Number.isFinite(amount)&&amount>0&&Number.isSafeInteger(cap)&&cap>0))return false;
 const staged=structuredClone(profile);staminaState(staged,now);const before=staged.stamina;
 if(before>=cap)return false;
 staged.staminaMax=cap;staged.stamina=Math.min(cap,before+amount);
 profile.stamina=staged.stamina;profile.staminaMax=staged.staminaMax;profile.battleSupport=staged.battleSupport;return true;
}
