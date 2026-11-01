import {siegeRenewCastles} from '../../src/game/siege-renew-rules.js';

// Native entrance job21's index identifies the Renew castle. The classic
// controller must not reinterpret it as a map23 tunnel. Until original gate
// placements and admission/progression rules are available, native 701:214
// ("No information.") refuses this route without charging or storing anything.
export function siegeRenewData(world) {
 return siegeRenewCastles(world.data?.eventData);
}
export function assertSiegeRenewAdmissionAvailable(world,map) {
 if(!siegeRenewData(world).some(row=>row.map===Number(map)))return;
 throw Object.assign(Error('siege:701:214'),{status:503,code:'SIEGE_RENEW_UNAVAILABLE'});
}
