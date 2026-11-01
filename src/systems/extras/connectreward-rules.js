// Reward Event ("Connect Reward"): pure rules shared by the host (server/world/support-rewards.mjs)
// and the client window (connectreward.js). Every value comes from the original client files:
//
//   share/support/connectreward/connectreward.csv  Index, Type, Count, then Count x (Value_k_1, Value_k_2, ItemIndex_k, ItemStack_k)
//                                                  (gamedata boxes.json connectReward = the same rows, tools/build-boxes.mjs)
//     Type 1 "Connection Time Reward"  (5000:1 / memo 5000:4)  Value_1 = connection seconds of the stage (1800 x 6)
//     Type 2 "Target Monster Hunting"  (5000:2 / memo 5000:5)  Value_1 = monsters to hunt for the stage (100..1000),
//                                                              Value_2 = 40 (see HUNT_LEVEL_GAP)
//     Type 3 "Key Item"                (5000:3 / memo 5000:6)  Value_1 = the key item, Value_2 = how many to possess
//   script/string/normal/StringTable_ConnectReward.txt (NORMAL cate 5000): titles 1..3, memos 4..6, subtitles 7..9 in Type
//     order; 10 "<VALUE1>/<VALUE2> monsters"; 11 "<VALUE1>hours <VALUE2>minutes", 16 "<VALUE1>hours", 17 "<VALUE2>minutes",
//     18 "<VALUE2>mins or less."; 12 "Reward Event will be reset every morning at 07:00 CEST regardless of connection.";
//     13 "Reward" (button); 14 "Reward Event" (assist title); 15 "<color=ff0000><VALUE1>/<VALUE2>" (key item count).
//   script/string/normal/stringtable_event.txt (NORMAL cate 2300): 15 "Not enough inventory space." 16 "Task not yet
//     completed." 17 "Reward already received." 18 "Item data not found." 20 "Reward received!" (shared with Attendance).
//   script/ui/game2/connectreward/ui_new_connectrewardwnd.txt (window), ui_connectreward_alarm.txt (HUD gift box btn_alarm,
//     tooltip 5000:0), ui_connectreward_assist.txt (the small "Reward Event" tracker), imagetable ConnectRewardwnd
//     (4 = normal reward line, 5 = key item reward line, 11 = clear, 12/14 = gauges, 21..23 = gift box alarm).
//
// ASSUMPTIONS (the client data does not state them; documented in the gate evidence):
//   * Progress counts since the daily reset and each stage needs its own Value_1 on top of the earlier stages
//     (stage k of Type 1 = 1800 x k seconds, Type 2 = 100+200+..+Value_k kills); claims go in stage order.
//   * Type 2 Value_2 (40) is read as the allowed level gap: 2310:1000 "Monster Hunt ... (Only monsters close to your level
//     count)". Monster indexes 100/200/300/500/700/1000 do not exist in share/creature/monster.csv, so Value_1 is a count.
//   * Type 3 checks possession only (the memo says "once you have" the item); the key items are not consumed.
//   * The event has no period in the data: it is always running. CEST is taken as UTC+2 (the zone the string names).
export const CONNECT_REWARD_SCRIPT = 'game2/connectreward/ui_new_connectrewardwnd.txt';
export const CONNECT_REWARD_ALARM_SCRIPT = 'game2/connectreward/ui_connectreward_alarm.txt';
export const CONNECT_REWARD_ASSIST_SCRIPT = 'game2/connectreward/ui_connectreward_assist.txt';
export const CONNECT_REWARD_CATE = 5000;
export const REWARD_MESSAGE_CATE = 2300;
export const TYPE_ONLINE = 1, TYPE_HUNT = 2, TYPE_KEYITEM = 3;
export const HUNT_LEVEL_GAP_COLUMN = 'Value_2';
/** String codes of cate 5000 by line part and Type. */
export const titleCode = type => type;
export const memoCode = type => 3 + type;
export const subtitleCode = type => 6 + type;
/** imagetable ConnectRewardwnd: line background by Type (4 normal reward, 5 key item reward). */
export const lineImage = type => (type === TYPE_KEYITEM ? 5 : 4);
/** Messages of cate 2300 (text = the original string, used by the host where the client tables are not loaded). */
export const REWARD_MESSAGES = {
  bagFull: { code: 15, text: 'Not enough inventory space.' },
  notDone: { code: 16, text: 'Task not yet completed.' },
  already: { code: 17, text: 'Reward already received.' },
  noItem: { code: 18, text: 'Item data not found.' },
  unknown: { code: 19, text: 'Unknown error.' },
  received: { code: 20, text: 'Reward received!' },
  waitPeriod: { code: 26, text: 'Please wait until the next event period.' },
};

// ------------------------------------------------------------------------------------------ daily reset (5000:12)
export const CEST_OFFSET_MS = 2 * 3600 * 1000;
export const RESET_HOUR_CEST = 7;
const DAY_MS = 86400000;
const RESET_SHIFT_MS = RESET_HOUR_CEST * 3600 * 1000 - CEST_OFFSET_MS;   // 07:00 CEST = 05:00 UTC
/** Reward day number: changes every day at 07:00 CEST. */
export const rewardDay = now => Math.floor((Number(now) - RESET_SHIFT_MS) / DAY_MS);
/** Epoch ms of the next 07:00 CEST reset. */
export const nextResetAt = now => (rewardDay(now) + 1) * DAY_MS + RESET_SHIFT_MS;

// ------------------------------------------------------------------------------------------ events
const int = v => (Number.isSafeInteger(v) ? v : Number.isFinite(Number(v)) ? Math.trunc(Number(v)) : 0);
/** Event rows from boxes.json connectReward ({index, type, steps: [[v1, v2, item, stack], ...]}) or the raw CSV text. */
export function connectRewardEvents(source) {
  if (typeof source === 'string') return parseConnectRewardCsv(source);
  return (Array.isArray(source) ? source : []).filter(e => e && Number.isInteger(e.index) && [1, 2, 3].includes(e.type) && Array.isArray(e.steps) && e.steps.length)
    .map(e => ({ index: e.index, type: e.type, steps: e.steps.map(s => ({ value1: int(s[0]), value2: int(s[1]), item: int(s[2]), stack: int(s[3]) })) }));
}
/** Independent parse of connectreward.csv (Count groups of 4 columns after Index, Type, Count). */
export function parseConnectRewardCsv(text) {
  const out = [];
  for (const line of String(text).split(/\r?\n/).slice(1)) {
    const c = line.split(',').map(s => s.trim());
    if (!/^\d+$/.test(c[0] || '')) continue;
    const n = int(c[2]), steps = [];
    for (let k = 0; k < n; k++) steps.push({ value1: int(c[3 + 4 * k]), value2: int(c[4 + 4 * k]), item: int(c[5 + 4 * k]), stack: int(c[6 + 4 * k]) });
    out.push({ index: int(c[0]), type: int(c[1]), steps });
  }
  return out;
}

// ------------------------------------------------------------------------------------------ state
/** Per-character state (profile.life.connectReward): {day, online, kills, claimed: {eventIndex: stagesClaimed}}. */
export function normalizeState(raw, now) {
  const day = rewardDay(now);
  if (!raw || typeof raw !== 'object' || raw.day !== day) return { day, online: 0, kills: 0, claimed: {} };
  const claimed = {};
  for (const [k, v] of Object.entries(raw.claimed || {})) if (/^\d+$/.test(k) && Number.isSafeInteger(v) && v > 0) claimed[k] = v;
  return { day, online: Math.max(0, int(raw.online)), kills: Math.max(0, int(raw.kills)), claimed };
}
export const claimedStages = (st, event) => Math.max(0, int(st.claimed?.[String(event.index)]));
/** Requirement total up to and including stage k (Types 1 and 2 count since the reset). */
export const prefixValue = (event, k) => event.steps.slice(0, k + 1).reduce((n, s) => n + s.value1, 0);
export const finalValue = event => prefixValue(event, event.steps.length - 1);

/**
 * The line of one event: the first unclaimed stage and its progress.
 * countItem(index) -> owned count (Type 3).
 * Returns {event, stage, step, done (all claimed), have, need, inStage, stageNeed, ready}.
 */
export function eventLine(event, st, countItem = () => 0) {
  const stage = claimedStages(st, event);
  if (stage >= event.steps.length) return { event, stage, step: null, done: true, ready: false, have: 0, need: 0, inStage: 0, stageNeed: 0 };
  const step = event.steps[stage];
  if (event.type === TYPE_KEYITEM) {
    const have = Math.max(0, int(countItem(step.value1)));
    return { event, stage, step, done: false, have, need: step.value2, inStage: Math.min(have, step.value2), stageNeed: step.value2, ready: step.value2 > 0 && have >= step.value2 };
  }
  const counter = event.type === TYPE_ONLINE ? st.online : st.kills;
  const before = stage ? prefixValue(event, stage - 1) : 0, need = prefixValue(event, stage);
  const inStage = Math.max(0, Math.min(step.value1, counter - before));
  return { event, stage, step, done: false, have: counter, need, inStage, stageNeed: step.value1, ready: step.value1 > 0 && counter >= need };
}

/** Add connected seconds (capped at the last Type 1 stage). Returns true when the state changed. */
export function addOnline(st, events, seconds) {
  const cap = Math.max(0, ...events.filter(e => e.type === TYPE_ONLINE).map(finalValue));
  const next = Math.min(cap, st.online + Math.max(0, Math.floor(seconds)));
  if (next === st.online) return false;
  st.online = next; return true;
}
/** Level gap allowed for a Type 2 kill: Value_2 of the current stage (40 in the data). */
export function huntLevelGap(event, st) {
  const stage = claimedStages(st, event);
  return stage < event.steps.length ? event.steps[stage].value2 : null;
}
/**
 * Count one monster kill for the Type 2 events: the monster's level must be within Value_2 levels of the character.
 * Returns true when the state changed.
 */
export function countKill(st, events, playerLevel, monsterLevel) {
  if (!Number.isFinite(playerLevel) || !Number.isFinite(monsterLevel)) return false;
  let counted = false;
  for (const event of events.filter(e => e.type === TYPE_HUNT)) {
    const gap = huntLevelGap(event, st);
    if (gap == null || Math.abs(monsterLevel - playerLevel) > gap) continue;
    if (st.kills >= finalValue(event)) continue;
    counted = true;
  }
  if (!counted) return false;
  st.kills += 1; return true;
}

/** Remaining connection seconds -> the original string ref + values (5000:11 / 16 / 17 / 18). */
export function remainingTimeText(seconds) {
  const s = Math.max(0, Math.ceil(Number(seconds) || 0));
  if (s < 60) return { code: 18, values: { VALUE1: 0, VALUE2: 1 } };
  const h = Math.floor(s / 3600), m = Math.floor((s % 3600) / 60);
  if (h && m) return { code: 11, values: { VALUE1: h, VALUE2: m } };
  if (h) return { code: 16, values: { VALUE1: h, VALUE2: 0 } };
  return { code: 17, values: { VALUE1: 0, VALUE2: m } };
}
/** Fill <VALUE1>/<VALUE2> tokens of a cate 5000 string. */
export const fillValues = (text, values) => String(text ?? '').replace(/<VALUE([12])>/g, (m, n) => (values[`VALUE${n}`] != null ? String(values[`VALUE${n}`]) : m));

/**
 * What the window shows for one line (pure). str(code) resolves a cate 5000 string. Types 1/2 use the 143 px gauge with
 * lbl_line_subtitle/submemo; Type 3 shows the key item (item_require + lbl_requireitem_count) and the 106 px item gauge with
 * the *_item labels (the key item line image 5 has that slot). A fully claimed event shows pan_clear.
 */
export function lineView(line, str) {
  const e = line.event, step = line.step || e.steps[e.steps.length - 1], key = e.type === TYPE_KEYITEM;
  const v = { image: lineImage(e.type), title: str(titleCode(e.type)), memo: str(memoCode(e.type)), subtitle: str(subtitleCode(e.type)), submemo: '',
    rewardItem: step.item, rewardCount: step.stack, requireItem: key ? step.value1 : 0, requireCount: key ? step.value2 : 0,
    keyItem: key, gauge: 1, button: !!line.ready, clear: !!line.done };
  if (line.done) return v;
  if (e.type === TYPE_ONLINE) {
    const t = remainingTimeText(line.need - line.have);
    v.submemo = fillValues(str(t.code), t.values); v.gauge = line.stageNeed ? line.inStage / line.stageNeed : 0;
  } else if (e.type === TYPE_HUNT) {
    v.submemo = fillValues(str(10), { VALUE1: line.inStage, VALUE2: line.stageNeed }); v.gauge = line.stageNeed ? line.inStage / line.stageNeed : 0;
  } else {
    // 5000:15 is the red "<VALUE1>/<VALUE2>" counter: red while the key items are missing, plain once they are owned
    const s = str(15);
    v.submemo = fillValues(line.ready ? s.replace(/<\/?color[^>]*>/gi, '') : s, { VALUE1: line.have, VALUE2: line.need });
    v.gauge = line.need ? Math.min(1, line.have / line.need) : 0;
  }
  return v;
}

/**
 * Validate a claim of an event's current stage. Returns {ok, error, step} (error = a REWARD_MESSAGES key).
 * hasItem(index) -> item definition exists.
 */
export function checkClaim(events, st, eventIndex, { countItem = () => 0, hasItem = () => true } = {}) {
  const event = events.find(e => e.index === eventIndex);
  if (!event) return { ok: false, error: 'unknown' };
  const line = eventLine(event, st, countItem);
  if (line.done) return { ok: false, error: 'already' };
  if (!line.ready) return { ok: false, error: 'notDone' };
  if (!line.step.item || !hasItem(line.step.item) || !(line.step.stack > 0)) return { ok: false, error: 'noItem' };
  return { ok: true, event, step: line.step, stage: line.stage };
}
export function markClaimed(st, event) { st.claimed = { ...(st.claimed || {}), [String(event.index)]: claimedStages(st, event) + 1 }; return st; }
