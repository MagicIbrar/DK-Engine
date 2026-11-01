// Skill client messages: <cate> 60 of script/string/normal/stringtable_skill.txt (SkillEngine.msg(code) reads them), plus the
// <cate> 150 rows as "150:<code>". Pure parser shared by the browser loader (skills/index.js) and the headless host
// (server/world/skills.mjs): the host's SkillEngine never loaded them, so every engine message that reached a player through
// the host (a queued press that could not start, a refused cast) arrived as the bare code "(NN)".
export function parseSkillMessages(text) {
  const out = {};
  let cate = null;
  const re = /<cate>\s*(\d+)|code\s+(\d+)[^\n]*\n\s*\{([\s\S]*?)\n\s*\}/g;
  let m;
  while ((m = re.exec(String(text || '')))) {
    if (m[1]) { cate = Number(m[1]); continue; }
    // keep leading spaces (code 75 is " Lv %u"); drop the line breaks around the block
    const body = m[3].replace(/\r/g, '').replace(/^\n+/, '').replace(/\s+$/, '');
    if (cate === 60) out[Number(m[2])] = body;
    else if (cate === 150) out[`150:${m[2]}`] = body;
  }
  return out;
}
