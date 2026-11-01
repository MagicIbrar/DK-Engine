// Repeat rates of the two looping gear effects (the authored `lifetime 0 1000` scenes play far faster than wanted).
//
// DATA: the gear refinement scene (effectscene cate 7 id 10 "item_upgrade") is authored as `lifetime 0 1000` with keyed alpha
// tracks (armor 0.1 -> 0.7 -> 0.1, weapon 0.5 -> 0.8 -> 0.5); each mesh_status unit scrolls its texture at `b` UV per second along
// direction `a`. The socket orb scenes (cate 7 ids 1-6, modeleffect.csv group 24) are `lifetime 0 1000`, timeMs 1000, looping.
// How long the original client plays the gear loop is compiled into the client (no modeleffect.csv row), so these two lengths are
// set from a judgement of the official look, not read from data. Change them here; nothing else needs to change.

/** One pulse ("wave") of the worn-gear refinement shine, in ms: every 3-4 seconds. */
export const REFINEMENT_LOOP_MS = 3500;
/** One pulse of the gem socket orbs / mist on weapons (in hand), in ms: every 4 seconds. */
export const SOCKET_ORB_LOOP_MS = 4000;

/** Worn-gear particle emission (the blue sparkle bubbles coming off weapons): 'authored' = the emit rate written in the effect data, read as particles per second; 'fill' = the older engine policy that keeps the whole particle pool alive (max(authored rate, pool / average life), about 9x the authored rate for the median particle unit). The UNIT of emitrate is not proven (the original exe is packed and there is no Global timing source on this PC); 'fill' made the sparkles too quick. Revert for testing with globalThis.__dekaronParticleFill = true. */
export const WORN_PARTICLE_RATE = 'authored';
