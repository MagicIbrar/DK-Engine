// GUILD-BOARD shared rules (client windows src/systems/extras/guildboard.js + host server/world/guild-board.mjs). Every value and its
// ORIGINAL source (read-only client data; re-parsed and compared by tools/test-guild-board.mjs):
//   windows   game2/guild/ui_guildboardwnd.txt (title 100:172 'Guild publicity sign', NPC job 134 GUILD_ADVERTISE_LIST = the 13 'Guild sign'
//             NPCs 6092..6104), ui_guildrequestjoinwnd.txt (100:173 'More information', opened by the board's btn_detail 134:29 'More Info'),
//             ui_guildmanagejoinwnd.txt (100:174 'Guild Publicity Management', NPC job 135 GUILD_ADVERTISE_APPLICATION = Blake 135),
//             ui_guildhistorywnd.txt (guild window tab btn_history 130:463 'Record'), ui_bestguildwnd.txt (guild window btn_bestbattle
//             130:449 'Best Guild War', title 130:440 'Apply to participate Guild War').
//   promotion 134:20 '7 days' + 134:22 '1,000,000 DIL' (manage window, fixed labels), paid from the GUILD's DIL (134:51 'Guild Holder',
//             134:602 'Insufficient guild holding DIL', 130:477 'Guild promotion cost %lld DIL has been deducted.'), guild leader only (134:604),
//             one promotion per guild (134:601), modify (134:44) and delete (134:45 / 134:618).
//   limits    edit_level_limit maxlength 3 numeric -> level 0..999 (0 = 134:27 'No Restrictions'); edit_notice_title maxlength 39;
//             textbox_content maxlength 500; the applicant's edit_comment maxlength 40; 15 class check boxes btn_class_0..14 (class index order).
//   rating    'Rating' = the awakening grade (share/pc/awakening/grade.csv: Grade Division d has the 4 grades (d-1)*4+1..(d-1)*4+4, named
//             New / - / Senior / Elite). The manage window's two combos: com_grade0 = the step 134:1100..1103 (Newcomer, General, Advanced
//             Level, Elite) and com_grade1 = the division 134:1000..1014 (15 names) -> minimum grade (d-1)*4+s.
//   join      134:15 Subs.Type: 134:16 'Immediate Subscription' (joins at once) / 134:17 'Sign Up After Approval' (List of Applications,
//             approve 134:40 / refuse 134:41, leader only 134:616). One application at a time (134:31, 134:52), conditions 134:614 / 134:608,
//             already in a guild 134:615, promotion over 134:610, full guild 130:104.
//   history   130:464 '<NAME> has donated <COUNT> of <TYPE>.' with 130:465 ADV / 130:466 DIL (the guild's DIL and Adventure donations) and
//             130:481 '<NAME> has used <COUNT>.' (guild DIL spent on the promotion); columns 130:467 Time, 130:151 Name, 130:470 Type,
//             130:473 Donation Amount.
//   best war  share/guild/guild.csv BEST_GUILD = 7 representatives (the 7 btnmainlist rows), guild master only (130:444), exactly that
//             many (130:445), one per class (130:448), success 130:447.
// NOT IN THE CLIENT DATA (documented, not invented): the applicant cap behind 134:611 (engine bound APPLICATION_LIMIT, same as the
// invitation bound), the Best Guild War schedule / selection period (130:446) and its level requirement (130:484): the war itself has
// no data in this client, so the registration is stored for that mode and nothing else is derived from it; the history length
// (engine storage bound HISTORY_LIMIT, the window scrolls).

export const SCRIPTS = {
  board: 'game2/guild/ui_guildboardwnd.txt', detail: 'game2/guild/ui_guildrequestjoinwnd.txt', manage: 'game2/guild/ui_guildmanagejoinwnd.txt',
  history: 'game2/guild/ui_guildhistorywnd.txt', best: 'game2/guild/ui_bestguildwnd.txt',
};
export const JOB = { list: 134, manage: 135 };          // share/creature/jobtypeconfig.csv
export const ROLE = { list: 'GUILD_ADVERTISE_LIST', manage: 'GUILD_ADVERTISE_APPLICATION' };
export const PROMOTION_DAYS = 7;                         // 134:20
export const PROMOTION_COST = 1_000_000;                 // 134:22
export const DAY_MS = 86_400_000;
export const LEVEL_MAX = 999, TITLE_MAX = 39, CONTENT_MAX = 500, COMMENT_MAX = 40, CLASS_COUNT = 15;
export const DIVISIONS = 15, STEPS = 4;
export const APPLICATION_LIMIT = 100, HISTORY_LIMIT = 200;
export const CLASS_ICON = { group: 'guildwar_apply', first: 11 };   // imagetable guildwar_apply 11..25 = 15 class cells 26x20
export const ROWS = { board: 20, requests: 17, history: 22 };      // list heights / row heights of the scripts (see guildboard.js)

/** [cate, code] of every original string the windows and the host use. */
export const STR = {
  noLimit: [134, 27], none: [134, 49], applying: [134, 31], cancelAsk: [134, 32], applyAsk: [134, 34], registerAsk: [134, 35],
  joined: [134, 43], modifyAsk: [134, 44], deleteAsk: [134, 45], approveAsk: [134, 47], rejectAsk: [134, 48],
  waitingCreate: [134, 52], registered: [134, 600], already: [134, 601], noDil: [134, 602], noGuild: [134, 603], leaderOnly: [134, 604],
  applied: [134, 607], conditions: [134, 608], subscribed: [134, 609], ended: [134, 610], applicantsFull: [134, 611], meet: [134, 614],
  member: [134, 615], approveLeader: [134, 616], deleted: [134, 618], approved: [134, 613], refused: [134, 619], canceled: [134, 620],
  processed: [134, 621], immediate: [134, 16], approval: [134, 17], days: [134, 20], cost: [134, 22],
  donated: [130, 464], adv: [130, 465], dil: [130, 466], used: [130, 481], costDeducted: [130, 477], full: [130, 104], dilLabel: [130, 329],
  bestMaster: [130, 444], bestCount: [130, 445], bestClass: [130, 448], bestDone: [130, 447],
};
export const DIVISION_NAME = code => [134, 1000 + code - 1];   // division 1..15
export const STEP_NAME = step => [134, 1100 + step - 1];       // step 1..4

/** Host refusal / result texts = the original strings with markup and [message] tags removed (asserted by the test). */
export const TEXT = {
  leaderOnly: 'Guild promotional registration is only available to guild leaders.',
  already: 'Guild promotions are already registered.',
  noDil: 'Insufficient guild holding DIL required for guild promotion registration.',
  noGuild: 'Guild does not exist.',
  conditions: 'There are insufficient conditions for the registration application.',
  ended: 'The recruitment of the guild has ended and the subscription has failed.',
  applicantsFull: 'The number of applicants for guild membership is full, so you cannot apply for it.',
  meet: 'This user does not meet the subscription criteria.',
  member: 'You are already a member of the guild.',
  approveLeader: 'Only guild leaders can approve/reject the subscription.',
  applying: 'You are currently applying to join the guild.',
  waitingCreate: 'Guild creation failed because we are waiting to apply for guild membership.',
  full: 'You cannot join the guild because it has reached the maximum number of members.',
  bestMaster: 'Only Guild Master can do this.',
  bestCount: 'The numbers of attending members don’t match.',
  bestClass: 'The selected class has already been registered.',
};

export const plain = s => String(s ?? '').replace(/\[message\]/gi, '').replace(/<[^>]+>/g, '').replace(/\\/g, ' ').replace(/\s*\n\s*/g, ' ').replace(/\s+/g, ' ').trim();
export const gradeOf = (division, step) => (division >= 1 && division <= DIVISIONS && step >= 1 && step <= STEPS) ? (division - 1) * STEPS + step : 0;
export const divisionOf = grade => grade > 0 ? { division: Math.floor((grade - 1) / STEPS) + 1, step: ((grade - 1) % STEPS) + 1 } : null;
export const classIcon = classIndex => CLASS_ICON.first + (Number.isInteger(classIndex) && classIndex >= 0 && classIndex < CLASS_COUNT ? classIndex : 0);

/** Validate a promotion form (host and window share this). Returns {value} or {error}. */
export function checkPromotion(input) {
  const { levelLimit, grade, classes, approval, title, content } = input || {};
  if (!Number.isInteger(levelLimit) || levelLimit < 0 || levelLimit > LEVEL_MAX) return { error: 'level' };
  if (!Number.isInteger(grade) || grade < 0 || grade > DIVISIONS * STEPS) return { error: 'grade' };
  if (!Array.isArray(classes) || classes.length < 1 || classes.length > CLASS_COUNT || classes.some(c => !Number.isInteger(c) || c < 0 || c >= CLASS_COUNT) || new Set(classes).size !== classes.length) return { error: 'classes' };
  if (typeof approval !== 'boolean') return { error: 'approval' };
  if (typeof title !== 'string' || !title.trim() || [...title].length > TITLE_MAX || /[\x00-\x1f\x7f]/.test(title)) return { error: 'title' };
  if (typeof content !== 'string' || [...content].length > CONTENT_MAX || /[\x00-\x08\x0b-\x1f\x7f]/.test(content)) return { error: 'content' };
  return { value: { levelLimit, grade, classes: [...classes].sort((a, b) => a - b), approval, title: title.trim(), content } };
}
export function checkComment(comment) {
  if (comment === undefined || comment === '') return { value: '' };
  if (typeof comment !== 'string' || [...comment].length > COMMENT_MAX || /[\x00-\x1f\x7f]/.test(comment)) return { error: 'comment' };
  return { value: comment.trim() };
}
/** Does a character meet a promotion's terms of accession? */
export const meets = (promotion, { level, classIndex, grade }) => (Number(level) || 0) >= promotion.levelLimit && (Number(grade) || 0) >= promotion.grade && promotion.classes.includes(classIndex);

/** Best Guild War representatives: exactly `count` distinct members, one per class. Returns {value} or {error: 'bestCount'|'bestClass'}. */
export function checkBest(refs, members, count) {
  if (!Array.isArray(refs) || refs.length !== count || new Set(refs).size !== refs.length) return { error: 'bestCount' };
  const rows = refs.map(ref => members.find(m => m.ref === ref));
  if (rows.some(m => !m)) return { error: 'bestCount' };
  const classes = rows.map(m => m.classIndex);
  if (classes.some(c => !Number.isInteger(c)) || new Set(classes).size !== classes.length) return { error: 'bestClass' };
  return { value: [...refs] };
}

/** One history line: 130:464 (donation of ADV / DIL) or 130:481 (guild DIL used). `text(cate, code)` resolves an original string. */
export function historyLine(entry, text, num = n => Number(n || 0).toLocaleString('en-US')) {
  if (entry.type === 'use') return String(text(...STR.used) || '').replace('<NAME>', entry.name).replace('<COUNT>', `${num(entry.amount)} ${plain(text(...STR.dilLabel)) || 'DIL'}`);
  return String(text(...STR.donated) || '').replace('<NAME>', entry.name).replace('<COUNT>', num(entry.amount)).replace('<TYPE>', text(...(entry.type === 'ADV' ? STR.adv : STR.dil)) || entry.type);
}
/** Sort helper of the list windows: key -> comparator; dir 1 asc, -1 desc. */
export function sortRows(rows, key, dir = 1) {
  return [...rows].sort((a, b) => { const x = a[key], y = b[key]; const c = typeof x === 'number' && typeof y === 'number' ? x - y : String(x ?? '').localeCompare(String(y ?? '')); return c * dir || 0; });
}
export const pageCount = (n, per) => Math.max(1, Math.ceil(n / per));
export const dateText = ms => { if (!Number.isFinite(ms) || ms <= 0) return '-'; const d = new Date(ms), p = n => String(n).padStart(2, '0'); return `${d.getFullYear()}-${p(d.getMonth() + 1)}-${p(d.getDate())}`; };
export const timeText = ms => { if (!Number.isFinite(ms) || ms <= 0) return '-'; const d = new Date(ms), p = n => String(n).padStart(2, '0'); return `${dateText(ms)} ${p(d.getHours())}:${p(d.getMinutes())}`; };
