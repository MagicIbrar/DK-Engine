// Native share/article/gage.csv. Keys include class: Conserra and Vicious
// Summoner share servant models but learn different Great skills.
export function parseServantGauges(rows = []) {
  const out = new Map();
  for (const r of rows) {
    const n = key => Number(r[key]);
    const row = { classIndex: n('Class'), servant: n('Servant_Index'), skill: n('Skill_Index'),
      max: n('Max_Gage'), attackPc: n('Attack_PC'), attackMonster: n('Attack_Monster'),
      killPc: n('Kill_PC'), killMonster: n('Kill_Monster'), icon: n('Icon_Index') };
    if (!Object.values(row).every(Number.isFinite) || ![3, 10].includes(row.classIndex) ||
      row.servant <= 0 || row.skill <= 0 || row.max <= 0 || row.icon <= 0 ||
      [row.attackPc, row.attackMonster, row.killPc, row.killMonster].some(v => v < 0)) continue;
    out.set(`${row.classIndex}:${row.servant}`, Object.freeze(row));
  }
  return out;
}

// ENGINE-CHOSEN trigger interpretation: a landed damaging non-Great hit earns
// Attack_*; the killing hit also earns Kill_*. Misses, DoTs, event objects and
// projectiles still in flight earn nothing. New summons start empty; no decay.
export function servantGaugeGain(row, { kind, killed = false } = {}) {
  if (!row || !['player', 'monster'].includes(kind)) return 0;
  return (kind === 'player' ? row.attackPc + (killed ? row.killPc : 0) :
    row.attackMonster + (killed ? row.killMonster : 0)) / row.max;
}
