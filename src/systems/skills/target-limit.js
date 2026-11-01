// share/support/targetlimitskill/targetlimitskill.csv (Global pack.d04, 122 bytes; client g1/g2 sha256 e94b77ca...).
// Columns: SkillIndex,PC,Monster,Brick (0/1 per target kind). All 8 Global rows are 1,0,0 on single-target PC-support /
// PvP-control skills (Revive, Recover, Recall x2, Divide Pain, Separatum, Mental Split, Hella).
// PARSED ONLY, NOT ENFORCED: whether 1 means "allowed" or "limited" is not verifiable from data alone (no client RE), and
// enforcing it would change who these skills can hit. Exposed for review; combat, damage, rewards and timing untouched.
import { parseCSV, decodeText } from '../../formats/binreader.js';
export function parseTargetLimitSkill(src) {
  const rows = parseCSV(typeof src === 'string' ? src : decodeText(src)).map(r => (r || []).map(c => String(c ?? '').trim())).filter(r => r.length && r[0] !== '');
  const head = rows.shift() || [];
  if (head.join(',').toLowerCase() !== 'skillindex,pc,monster,brick') throw Error(`targetlimitskill: unexpected header ${head.join(',')}`);
  const out = new Map();
  for (const r of rows) {
    const id = Number(r[0]); if (!Number.isInteger(id) || id <= 0) throw Error(`targetlimitskill: bad SkillIndex ${r[0]}`);
    const [pc, monster, brick] = r.slice(1, 4).map(v => { const n = Number(v); if (n !== 0 && n !== 1) throw Error(`targetlimitskill ${id}: flag ${v}`); return n === 1; });
    out.set(id, { pc, monster, brick });
  }
  return out;
}
