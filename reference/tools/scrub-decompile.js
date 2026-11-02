// Line-preserving scrub of decompiled source for release (node scrub-decompile.js IN OUT).
// Every line is kept (so file:line refs in the opcode docs stay valid); only internal
// provenance text is rewritten: work-folder names, absolute paths, run notes and dates.
const fs = require('fs'), readline = require('readline');
const [,, IN, OUT] = process.argv;
if (!IN || !OUT || IN === OUT) { console.error('usage: node scrub-decompile.js IN OUT'); process.exit(1); }
const rules = [
  [/\/\* ===== Added \d{4}-\d\d-\d\d:[^*]*\*\//g, '/* ===== Additional functions recovered in a later pass ===== */'],
  [/added from VERIFY \([^)]*\)/g, 'added in a later pass'],
  [/\(added-functions pass, VERIFY bodies\)/g, '(later pass)'],
  [/dekaron64-[a-z]+/g, 'dekaron64'],
  [/\b[A-Z]{6,}-NAMES[\\\/][^\s,;)"*]*/g, '<work>'],
  [/\b[A-Za-z]:\\Users\\[^\s,;)"*]*/g, '<path>'],
  [/\/(?:workspace|home\/box|tmp)\/[^\s,;)"*]*/g, '<path>'],
  [/\bVERIFY\b/g, 'later pass'],
  [/\b20\d\d-\d\d-\d\d\b/g, '<date>'],
  [/\[added 20\d\d-[^\]]*\]?/g, '[added later]'],
  [/\b20\d\d-(?=\s|\*|$)/g, ''],
];
let n = 0, changed = 0;
const out = fs.createWriteStream(OUT);
const rl = readline.createInterface({ input: fs.createReadStream(IN), crlfDelay: Infinity });
rl.on('line', l => { n++; let m = l; for (const [re, s] of rules) m = m.replace(re, s); if (m !== l) changed++; out.write(m + '\n'); });
rl.on('close', () => { out.end(); console.log(`${IN}: ${n} lines, ${changed} scrubbed`); });
