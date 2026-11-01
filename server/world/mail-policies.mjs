import {socialError as fail} from './social-state.mjs';
import {isDeepStrictEqual} from 'node:util';

// Original stringtable_mail 250:16: inbox retention is 15 days, then the
// message and ALL attached items/DIL are deleted. No return-to-sender rule.
export const ORIGINAL_INBOX_POLICY='original-inbox-15d';
export const PRESERVED_SYSTEM_POLICY='engine-system-preserved';
export const INBOX_RETENTION_MS=15*24*60*60*1000;
const timestamp=value=>{if(!Number.isSafeInteger(value)||value<0)fail('Invalid mail policy timestamp; data preserved.',503);return value;};

export function mailDeliveryPolicy(policy,time){
  timestamp(time);
  if(policy===ORIGINAL_INBOX_POLICY){
    const expiresAt=timestamp(time+INBOX_RETENTION_MS);
    return {version:1,policy,createdAt:time,expiresAt,onExpiry:'delete-with-attachments'};
  }
  if(policy===PRESERVED_SYSTEM_POLICY)return {version:1,policy,createdAt:time,expiresAt:null,onExpiry:'preserve'};
  fail('That mail delivery/expiry policy has not been recovered.',503);
}
export function expiredMail(record,now){
  timestamp(now);
  // Never retrospectively erase legacy rewards or escrow with unknown policy.
  if(record.delivery===undefined)return false;
  const expected=mailDeliveryPolicy(record.delivery?.policy,record.time);
  if(!isDeepStrictEqual(record.delivery,expected))fail('Mail delivery policy metadata is invalid; data preserved.',503);
  return expected.expiresAt!==null&&now>=expected.expiresAt;
}
export function expireInboxOnClone(state,ref,now){
  const inbox=state.mail[ref]||[];
  if(!Array.isArray(inbox))fail('Mail inbox is invalid; data preserved.',503);
  const retained=inbox.filter(record=>!expiredMail(record,now));
  if(retained.length!==inbox.length)state.mail[ref]=retained;
  return inbox.length-retained.length;
}
export function rewardMailPolicy(family){
  if(family==='reward')return ORIGINAL_INBOX_POLICY;
  if(['cod','attendance','recovery','return'].includes(family))fail(`Original ${family} mail delivery, eligibility and settlement policy is unavailable; entitlement preserved.`,503);
  fail('Choose a known trusted mail producer family.');
}
