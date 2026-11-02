// Lane 47 (owner approved 2026-10-29: older server reference where Global has nothing). DK Square values that Global's
// client data does not ship, read as data only from the OLDER SERVER REFERENCE (server-ref, never run).
// Global ships no share/arena/lobbylist.csv; the Global GM command `set_dksquareInfo ... [LobbyIndex]` names a lobby index,
// and the older server reference keeps the lobby list keyed by that Index column.
//   Source: server-ref\Dekaron Server Arena\share\arena\lobbylist.csv
//           (Dekaron Server Normal\share\arena\lobbylist.csv is byte-identical).
//   Header: Index,MapIndex,Rank,EntryLimit,Pos_Radius,Pos_01_X,Pos_01_Y,Pos_02_X,Pos_02_Y,Pos_03_X,Pos_03_Y,Pos_04_X,Pos_04_Y
// Only the row is recorded and shown with the GM setting; nobody is moved to MapIndex / Pos_* (the 4.2.0 DK Square lobby
// list is used where the character stands), and the data does not show what EntryLimit limits, so it is not enforced (removed, lane 71).
// NOT wired (meaning not shown by the data): Option.csv CLOSINGWAIT_TIME 10 / VERIFYWAIT_TIME 60 (server-wide options next to
// FLUSHING_TIME / MAILCOUNTING_TIME, no DK Square link), Regist.csv ARENA_ROUND 0 (not one of rank.csv's Round values 1-3).
export const DK_SQUARE_SERVER_REF_TAG = 'older server reference';

/** older server reference: share/arena/lobbylist.csv rows (Index -> lobby row). */
export const DK_SQUARE_LOBBY_LIST = Object.freeze([
  Object.freeze({ index: 1, mapIndex: 100, rank: 1, entryLimit: 500, posRadius: 5,   // older server reference (lobbylist.csv row 1)
    positions: Object.freeze([[100, 100], [200, 200], [300, 300], [400, 400]].map((p) => Object.freeze(p))), source: DK_SQUARE_SERVER_REF_TAG }),
]);

/** The older-server-reference lobbylist.csv row for a set_dksquareInfo LobbyIndex, or null when that file has no such Index. */
export function lobbyListRow(index) {
  const n = Number(index);
  return DK_SQUARE_LOBBY_LIST.find((r) => r.index === n) || null;
}