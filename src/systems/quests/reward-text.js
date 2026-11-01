// Shared by preparation and the compatibility overlay for already prepared data.
// Read one reward tier, never sum two alternative outcomes printed in a journal.
const clean = value => String(value).replace(/<[^>]*>/g, '').replace(/\[\/?[a-z]link\]/gi, '').replace(/(?:<\/?)?color>$/i, '').trim();
const number = value => Number(String(value).replace(/,/g, '')) || 0;
// "Adveture Pts" is the original spelling of one commission journal; it is the same adventure-point label.
const ADV_AFTER = /^\+?\s*([\d,]+)\s*Adv(?:en|e)ture (?:Points?|Pts)/i, ADV_BEFORE = /^Adv(?:en|e)ture (?:Points?|Pts)\s*:?\s*\+?\s*([\d,]+)/i;
const LABEL_ONLY = /^(?:Adv(?:en|e)ture (?:Points?|Pts)|EXP|DIL)\s*:?$/i;
export function parseRewardText(journal) {
  if (!journal) return null;
  const raw = String(journal).split('\n'), lines = raw.map(clean);
  let start = lines.findIndex((line, i) => /reward/i.test(line) && /<font=4>|^\s*<color/i.test(raw[i]));
  if (start < 0) start = lines.findIndex(line => /^rewards?\s*:?$/i.test(line));
  if (start < 0) return null;
  const out = { exp: 0, dil: 0, adv: 0, items: [], lines: [] };
  for (let i = start + 1; i < lines.length; i++) {
    const line = lines[i];
    if (!line) continue;
    if (out.lines.length && (/<font=4>/i.test(raw[i]) || /^(?:rewards?\s+for|if you|\d+ bottles successfully)/i.test(line))) break;
    out.lines.push(line);
    let match;
    if ((match = /^\+?\s*([\d,]+)\s*(?:EXP|Experience)\b/i.exec(line)) || (match = /^EXP\s*:?\s*\+?\s*([\d,]+)/i.exec(line))) out.exp += number(match[1]);
    else if ((match = /^\+?\s*([\d,]+)\s*DIL\b/i.exec(line)) || (match = /^DIL\s*:?\s*\+?\s*([\d,]+)/i.exec(line))) out.dil += number(match[1]);
    else if ((match = ADV_AFTER.exec(line)) || (match = ADV_BEFORE.exec(line))) out.adv += number(match[1]);
    else if (LABEL_ONLY.test(line) && /^\s*[\d,]+\s*(?:Given|Distributed)?\s*$/i.test(lines[i + 1] || '')) {
      const key = /^Adv/i.test(line) ? 'adv' : line.toLowerCase();
      out[key] += number(lines[++i].match(/[\d,]+/)[0]);
    } else if ((match = /^([\d,]+)\s*x?\s+(.+)$/.exec(line))) out.items.push([number(match[1]), match[2].trim()]);
    else if ((match = /^(.+?)\s+[x×]\s*([\d,]+)\s*(?:ea|pcs?)?\.?$/i.exec(line)) || (match = /^(.+?)\s+([\d,]+)\s*(?:ea|pcs?|x)\.?$/i.exec(line))) out.items.push([number(match[2]), match[1].trim()]);
    else out.items.push([null, line]);
  }
  return out;
}
