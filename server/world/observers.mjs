// Shared spectator registry for event modes with observers (GUILD-WAR-HUNT job 138, GUILD-TOURNEY job 100, OBSERVER job 40).
// A mode registers {is(world, p), actions:Set<type>}. SharedWorld hides observers from other players, keeps monsters
// and PvP off them, and refuses every action type the observing mode does not allow.
const MODES=[];
export function registerObserverMode(mode){if(!MODES.includes(mode))MODES.push(mode);return mode;}
export function isObserver(world,p){return !!p&&MODES.some(m=>m.is(world,p));}
export function observerAllows(world,p,type){const own=MODES.filter(m=>m.is(world,p));return !own.length||own.every(m=>m.actions.has(type));}
/** True when any registered mode lets its observers send this action type (the union SharedWorld's current guard checks). */
export function anyObserverAction(type){return MODES.some(m=>m.actions.has(type));}