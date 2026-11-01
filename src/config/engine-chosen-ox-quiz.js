import {serverDate,serverTimestamp} from '../game/server-time.js';
// Saturday17:00 comes from native Hani conv61770. The absent server script does
// not give a registration window, per-question timer or reward binding.
// ENGINE-CHOSEN:5min registration (other timed-event entry convention),30sec
// answer (standard event countdown), native5sec wall, twice that for solution.
// The latest dated native OX gift box is used once for a full15-round survivor.
export const OX_AUTOMATION=Object.freeze({day:6,hour:17,entryMs:300000,answerMs:30000,wallMs:5000,solutionMs:10000,returnMs:60000,rewardItem:1192809,rewardCount:1,label:'ENGINE-CHOSEN pacing and native OX gift-box binding; Hani Saturday17:00, fixed server UTC+1'});
export function oxScheduleWindow(now){const d=serverDate(now);if(d.getUTCDay()!==OX_AUTOMATION.day)return null;const startAt=serverTimestamp(d.getUTCFullYear(),d.getUTCMonth(),d.getUTCDate(),OX_AUTOMATION.hour),opensAt=startAt-OX_AUTOMATION.entryMs;return now>=opensAt&&now<startAt?{id:`ox-${d.getUTCFullYear()}-${d.getUTCMonth()+1}-${d.getUTCDate()}`,opensAt,startAt}:null;}
