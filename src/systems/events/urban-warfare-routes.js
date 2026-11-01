import {plain} from './text.js';

// Native share/urbanwarfare/respawn.csv owns battlefield 650. The SOLO
// dungeon 653 uses WORLDBY exits (651/652). Its disclosed dedicated Checkpoint
// ticket/admission service owns eligibility; ordinary travel and a synthesized
// dungeon gate must never bypass either event's admission.
// Lobby maps 651/652 remain ordinary destinations; this does not assign a side.
export const urbanWarfareRequiresAdmission = map => [650,653].includes(Number(map));

// Guide row 1305:9 has no HELPER body in this client. Its dedicated
// help window still exists in the original script/atlas.
export const URBAN_WARFARE_HELP = Object.freeze({
  cate: 1305, code: 9, window: 'urbanwarfarehelp',
  script: 'game2/dksquare/ui_urbanwarfarehelp.txt',
});

// The artwork is preserved; explain the host's disclosed schedule interpretation beside it.
export function urbanWarfareHelpScheduleText(rows) {
  const times = (rows || []).filter(row => Number(row.MapIndex) === 650)
    .map(row => `Day ${row.Day}, ${String(row.Hour).padStart(2, '0')}:${String(row.Min).padStart(2, '0')}`);
  return times.length
    ? `Original help artwork says Saturday.\nOriginal event schedule: ${times.join('; ')}.\nServer time: UTC+1. Tuesday and Saturday 23:40 preparation; entry opens at 00:00 and battle starts at 00:10 the following day. This phase mapping is an engine choice.`
    : 'Original help artwork says Saturday. The original event schedule could not be read.';
}

export function urbanWarfareUnavailableText(data) {
 return plain(data?.mapTxt?.(650,10000) || data?.txt?.('stringtable_map_string_02.txt',650,10000)
  || 'The entrance of Zuto’s Battlefield is unavailable right now.');
}
