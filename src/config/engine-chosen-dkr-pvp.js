// Lane 47 (2026-10-29): DKR_PVP_CHOSEN is removed. Every value it held (calendar zone, group size, allocation, league pairs,
// points, rank order, advance count, Round of 16 seeding, max rounds, rounds to win, round timeout, tournament tiebreak, count /
// round result / break / match result seconds, minimum entrants, observer point and speed unit, NPC radius, revive rule) was
// ENGINE-CHOSEN with no Global evidence. DK Rumble is now GM-run with the Global dkrpvp_* commands (server/world/dkr-pvp.mjs).
// This file stays only because dedicated-install.json lists it (workers do not edit that list).
export {};
