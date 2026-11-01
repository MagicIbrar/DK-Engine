// BLACKLIST (C29): the Messenger window's second tab. Global evidence:
//   script/ui/game2/messenger/ui_messengerwnd.txt:62 btn_tab_0 (text2 1006 49 "Friend", L83) / :105 btn_tab_1 (text2 1006 50 "Blacklist", L126)
//   / :192 btn_add (1006 51 "Add"); script/string/normal/stringtable_messenger.txt (cate 1006, prepared g2 copy):
//   53 "Add to Blacklist", 54 "is added to the blacklist.", 55 "Already in the blacklist.", 56 "My blacklist is already full.",
//   57 "is removed from the blacklist.", 58 "is not registered in the block list.", 59 "Cannot register yourself.",
//   63/70 "Cannot block/blacklist ... on this map", 68 "Cannot blacklist users from other servers."
// Persisted on the character profile (profile.blacklist, names). Own module + own 'blacklist' message; it does not touch the
// friend list, friend requests or ui_addfriend (lane-world). What a blacklisted name is barred from is NOT stated by the Global UI
// or strings, so nothing is suppressed here; isBlacklisted() is exported for a single guarded caller (see REPORT.md).
import {WorldError} from './core.mjs';
export const BLACKLIST_SCHEMAS={blacklist:['token','type','operation','targetName']};
// Cap 30: Global server per-PC blacklist map Segment<30, Coupler<String<25>, IBlackList*>> (audit/global-re/SERVER-RE.md §6,
// fo 0x82fe00); full-list reply 1006:56 "My blacklist is already full." (stringtable_messenger.txt:189).
export const BLACKLIST_MAX=30;
export const BLACKLIST_NAME_MAX=20;       // ui_messengerwnd.txt edit_text maxlength 20
export const BLACKLIST_CODES=Object.freeze({added:'1006:54',already:'1006:55',full:'1006:56',removed:'1006:57',notListed:'1006:58',self:'1006:59',notFound:'1006:24'});
const fail=m=>{throw new WorldError(400,m);};
const key=n=>String(n||'').trim().toLowerCase();
export function blacklistOf(profile){return Array.isArray(profile?.blacklist)?profile.blacklist.filter(n=>typeof n==='string'&&n.trim()):[];}
/** True when `owner` (a live player) has blacklisted the character named `name`. */
export function isBlacklisted(owner,name){const k=key(name);return !!k&&blacklistOf(owner?.profile).some(n=>key(n)===k);}
export async function blacklistCommand(world,p,input){
  const op=input.operation,list=blacklistOf(p.profile);
  if(op==='list'){if(input.targetName!==undefined)fail('Invalid blacklist request.');return {names:[...list],max:BLACKLIST_MAX};}
  if(!['add','remove'].includes(op))fail('This blacklist action is unavailable.');
  if(typeof input.targetName!=='string'||!input.targetName.trim()||input.targetName.length>BLACKLIST_NAME_MAX||/[\x00-\x1f\x7f]/.test(input.targetName))fail('Enter a character name.');
  const name=input.targetName.trim();
  if(key(name)===key(p.profile.name))return {ok:false,code:BLACKLIST_CODES.self,targetName:name};
  const at=list.findIndex(n=>key(n)===key(name));
  if(op==='remove'){
    if(at<0)return {ok:false,code:BLACKLIST_CODES.notListed,targetName:name};
    const removed=list[at];p.profile={...p.profile,blacklist:list.filter((_,i)=>i!==at)};p.dirty=true;world.changed?.(p);await world.persist?.(p);
    return {ok:true,code:BLACKLIST_CODES.removed,targetName:removed,names:[...p.profile.blacklist]};
  }
  if(at>=0)return {ok:false,code:BLACKLIST_CODES.already,targetName:list[at]};
  if(Number.isInteger(BLACKLIST_MAX)&&list.length>=BLACKLIST_MAX)return {ok:false,code:BLACKLIST_CODES.full,targetName:name};
  // ENGINE-CHOSEN: the name must belong to a connected character (offline lookup is not available to the world host).
  const target=[...world.players.values()].find(q=>!q.leaving&&key(q.profile?.name)===key(name));
  if(!target)return {ok:false,code:BLACKLIST_CODES.notFound,targetName:name};
  p.profile={...p.profile,blacklist:[...list,target.profile.name]};p.dirty=true;world.changed?.(p);await world.persist?.(p);
  return {ok:true,code:BLACKLIST_CODES.added,targetName:target.profile.name,names:[...p.profile.blacklist]};
}
