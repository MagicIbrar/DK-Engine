import * as saves from '../../game/save.js';
import { RemotePlayer, RemoteMonster, RemoteServant, setServerPose, advanceServerPose } from './actors.js';
import { eventDefeat, defeatSeconds } from '../../game/hit-reaction.js';
import { openBuilder } from '../gm/builders.js';
import { keepClientLocalGM } from '../gm/online-support.js';
import { MOVEMENT_SYNC } from './movement-config.js';
import { ServerClockFilter, syncActive, syncMoveBlocked, movementReport, syncShouldSend, syncLeadAllows, syncSelfSnapshot, moveSyncState, syncNeedsResync, syncArrived, syncDead, syncTrack } from './movement-sync.js';
import { ATTACK_REQUESTS_IN_FLIGHT, ATTACK_MIN_GAP_MS } from '../../game/attack-timing.js';
import { captureAttackRecovery } from '../../game/attack-recovery.js';
import { NetRttMeter } from './net-rtt.js';
import { str, fmtInt, plainMarkup } from '../hud-options/util.js';
import {itemPickupText, dilPickupText} from '../hud-options/chat-notice-colors.js';
import { pkNotice } from './field-pk.js';
import {simulationPopulationView} from './simulation-population.js';
import {visibleActorRows,initialSceneActors} from './visual-interest.js';
import {scenePreparation} from './scene-readiness.js';
import { RowsDeltaDecoder } from './rows-delta.js';

const API = '/api/world/';

// SAFE LOAD-FAILURE METADATA. A failed shared-world admission is described by integers and allowlisted names only: the HTTP status, the
// error name and code, the phase it happened in and a category derived from those. Server text, browser text and error messages are
// never copied, so the loading screen can show a category (sign-in, permission, busy, offline ...) without echoing untrusted text.
const FAILURE_PHASES = new Set(['ready', 'preparation', 'join', 'commit', 'poll', 'action', 'request']);
const FAILURE_NAMES = new Set(['Error', 'AbortError', 'TypeError', 'SyntaxError', 'NetworkError', 'TimeoutError', 'SecurityError']);
const FAILURE_CODES = new Set(['WORLD_BUSY','OWNER_GUILD_SETUP_FAILED','OWNER_GUILD_SETUP_TIMEOUT']);
const OWNER_GUILD_FAILURE_MESSAGES = Object.freeze({OWNER_GUILD_SETUP_FAILED:'Owner guild setup could not finish. Sign out of other owner games, then return to Client, check host setup status and retry owner sign-in.',OWNER_GUILD_SETUP_TIMEOUT:'Owner guild setup timed out. Return to Client, check host setup status and retry owner sign-in.'});
export const NETWORK_FAILURE_CATEGORIES = Object.freeze(['auth', 'forbidden', 'conflict', 'rate-limited', 'busy', 'unavailable', 'incompatible', 'rejected', 'timeout', 'network', 'protocol', 'preparation-failed', 'client', 'unknown']);
const failureMeta = new WeakMap();   // Error -> { status, protocol }: facts noted where the error is created, never parsed from its text
const safeStatus = value => Number.isInteger(value) && value >= 100 && value <= 599 ? value : null;
function failureCategory({ phase, status, name, code, protocol }) {
  if (phase === 'commit') return 'client';             // the server accepted the join; this client could not install the answer
  if (code === 'WORLD_BUSY') return 'busy';
  if (status !== null) {
    if (status === 401) return 'auth';
    if (status === 403) return 'forbidden';
    if (status === 409) return 'conflict';
    if (status === 429) return 'rate-limited';
    if (status === 404 || status === 405 || status === 410) return 'incompatible';   // this server does not speak the shared-world protocol
    if (status === 408 || status >= 500) return 'unavailable';
    if (status >= 400) return 'rejected';
  }
  if (protocol || name === 'SyntaxError') return 'protocol';   // a 2xx answer that is not the expected JSON, or a proxy page
  if (name === 'AbortError' || name === 'TimeoutError') return 'timeout';
  if (name === 'TypeError' || name === 'NetworkError' || name === 'SecurityError') return 'network';   // fetch failed before any answer
  return 'unknown';
}
/** { phase, category, status, name, code, generation } for a failed request. status / name / code are null when the failure was not
 *  an exception (preparation reported failed). The record is frozen and holds no message text. */
export function describeFailure(error, { phase = 'request', generation = null } = {}) {
  const meta = error && typeof error === 'object' ? failureMeta.get(error) : null;
  const status = safeStatus(error?.status) ?? safeStatus(meta?.status);
  const name = FAILURE_NAMES.has(error?.name) ? error.name : 'Error';
  const code = FAILURE_CODES.has(error?.code) ? error.code : null;
  const kind = FAILURE_PHASES.has(phase) ? phase : 'request';
  return Object.freeze({ phase: kind, category: failureCategory({ phase: kind, status, name, code, protocol: !!meta?.protocol }), status, name, code, generation: Number.isSafeInteger(generation) ? generation : null });
}
function protocolError(message, status = null) { const error = new Error(message); failureMeta.set(error, { status: safeStatus(status), protocol: true }); return error; }
/** Remember on `network` why its last request failed (admission() reports it). A plain function, not a method: tools/test-C13-native-editor.mjs
 *  builds a fake network out of SharedWorld.prototype._error and .poll alone, and _error must keep working on such an object. */
export function noteNetworkFailure(network, error, phase, generation = network._leaseGeneration) { return network._admissionFailure = describeFailure(error, { phase, generation }); }
export class SharedWorld {
  constructor(game, options = {}) {
    const { request = globalThis.fetch.bind(globalThis), EventSourceClass = globalThis.EventSource } = options;
    this.game = game; this.request = request; this.EventSourceClass = EventSourceClass;
    this.prepareWorld=options.prepareWorld===true;
    this.active = game.save?.authority === 'server'; this.ready = false; this.token = null;
    if (this.active) game.accountPermissions = { role: 'player', capabilities: [] };
    this.self = null; this.players = new Map(); this.monsters = new Map(); this.servants=new Map(); this.sequence = -1;
    this.status = this.active ? 'connecting' : 'solo'; this.disposed = false;
    this._lastMove = null; this._nextMove = 0; this._lastAttack = -Infinity; this._pollAt = 0;
    this._inputRelease = () => { if (this.game.controller?._wasd) { this.game.controller._wasd = false; this.stop(); } };
    game.input?.canvas?.addEventListener?.('inputrelease', this._inputRelease);
    this._commandSequence=0;this._serverClock=null;this._loads = []; this._loading = 0; this._generation = 0;
    this._leaseGeneration = 0;
    this._motionClock = new ServerClockFilter();
    // PING LABEL (network/net-rtt.js): the displayed ping is the browser's own network timing of these requests, not the main-thread wait.
    // Only for the real fetch (an injected request function has no resource timing); tests may pass PerformanceObserverClass.
    this._rttMeter = null;
    if (this.active) { const meter = new NetRttMeter(options.PerformanceObserverClass ? { ObserverClass: options.PerformanceObserverClass } : options.request === undefined ? {} : { ObserverClass: null }); if (meter.start()) this._rttMeter = meter; }
  }
  actors() { return [...this.players.values(), ...this.monsters.values(), ...this.servants.values()]; }
  unavailable(feature = 'This action') {
    const now = Date.now();
    if (now - (this._noticeAt || 0) > 1200) { this._noticeAt = now; this.game.chat?.system?.(`${feature} is not available in the shared world yet.`, 'err'); }
    return false;
  }
  _status(state, message) {
    if(state!=='connected')this._simulationPopulationView=null;
    this.status = state;
    try {this.game.events?.emit?.('network', { state, message });this._paintStatus?.();}
    finally {this._signalVisuals();}
    // Connection state belongs beside the minimap; do not interrupt play with a second overlay.
  }
  /** MOVEMENT: smoothed request round trip of this link (join, polls, actions); seeds the movement report spacing
   *  before the first movement answer arrives (movement-sync.js syncShouldSend). */
  _noteRoundTrip(ms) { if (ms >= 0 && ms < 15000) this._linkRtt = Number.isFinite(this._linkRtt) ? this._linkRtt * 0.8 + ms * 0.2 : ms; }
  /** Browser network timing to this authoritative game origin; never frame-time fallback. */
  displayRtt() { return this.active && this.ready && !this.disposed ? this._rttMeter?.value() ?? null : null; }
  _cancelInitialJoin() {
    const request=this._joinRequest;this._joinRequest=null;this._joinBudget=null;
    try{request?.controller.abort();}catch{}
  }
  async _request(route, body, keepalive = false, joinGeneration = null) {
    const headers={};if(body)headers['Content-Type']='application/json';
    if(body&&['action','gm'].includes(route)){headers['X-Dekaron-Command-Sequence']=String(++this._commandSequence);headers['X-Dekaron-Command-Time']=String(Math.floor(this._serverClock?this._serverClock.time+performance.now()-this._serverClock.at:Date.now()));}
    const initialJoin=route==='join'&&Number.isSafeInteger(joinGeneration)&&joinGeneration===this._leaseGeneration&&this._joining&&!this.disposed;
    const timeoutMs=initialJoin&&this._joinBudget?.generation===joinGeneration?[60000,120000].includes(this._joinBudget.timeoutMs)?this._joinBudget.timeoutMs:15000:15000;
    const controller=new AbortController(),timeout=setTimeout(()=>controller.abort(),timeoutMs);
    const ownedJoin=initialJoin?{controller,generation:joinGeneration}:null;
    if(ownedJoin){this._joinRequest?.controller.abort();this._joinRequest=ownedJoin;}
    const sentAt=performance.now();
    const failureTicket={lease:this.token,generation:this._leaseGeneration,snapshotRevision:this._snapshotRevision||0,sentAt:Date.now()};
    let response,data;try{response=await this.request(API+route,{credentials:'same-origin',signal:controller.signal,...(body?{method:'POST',headers,body:JSON.stringify(body),keepalive}:{})});
      // A proxy / relay error page is not JSON: keep the HTTP status next to the parse failure (the thrown error itself is unchanged).
      try{data=await response.json();}catch(parseError){if(parseError&&typeof parseError==='object'&&parseError.name!=='AbortError')failureMeta.set(parseError,{status:safeStatus(response.status),protocol:true});throw parseError;}}
    catch(error){if(error?.name==='AbortError'){this._requestFailures ||= new WeakMap();this._requestFailures.set(error,failureTicket);}throw error;}
    finally{clearTimeout(timeout);if(ownedJoin&&this._joinRequest===ownedJoin)this._joinRequest=null;}
    this._noteRoundTrip(performance.now()-sentAt);
    this._rttMeter?.noteRequest();
    if (!response.ok) { const error = new Error(typeof data?.error === 'string' && data.error || 'Shared world request failed.'); error.status = response.status; if(['WORLD_BUSY','OX_QUIZ_REFUSED','OX_QUIZ_REJECTED','SIEGE_RENEW_REFUSED'].includes(data?.code))error.code=data.code; throw error; }
    return data;
  }
  async _prepareWorld(generation) {
    while(!this.disposed&&generation===this._leaseGeneration){
      this._status('preparing','Preparing the shared world before joining.');
      const state=await this._request('ready');
      if(this.disposed||generation!==this._leaseGeneration)return false;
      if(!state||typeof state.ready!=='boolean'||!['ready','preparing','failed'].includes(state.phase)||state.ready!==(state.phase==='ready')||!Number.isInteger(state.retryAfterMs)||state.retryAfterMs<0||state.retryAfterMs>3000)throw protocolError('Invalid world readiness response.');
      if(state.ready){
        const timeoutMs=state.joinTimeoutMs===undefined?15000:state.joinTimeoutMs;
        if(![15000,60000,120000].includes(timeoutMs))throw protocolError('Invalid initial join wait budget.');
        this._joinBudget={generation,timeoutMs};return true;
      }
      if(state.phase==='failed'){
        const code=Object.hasOwn(OWNER_GUILD_FAILURE_MESSAGES,state.code)?state.code:null;
        this._admissionFailure=Object.freeze({phase:'preparation',category:'preparation-failed',status:null,name:null,code,generation});
        this._lastCommandError={message:OWNER_GUILD_FAILURE_MESSAGES[code]||'Shared world preparation failed. Retrying shortly.',at:Date.now()};
        this._pollAt=Date.now()+3000;this._status('preparation-failed',this._lastCommandError.message);return false;
      }
      await new Promise(resolve=>{
        const finish=()=>{clearTimeout(timer);if(this._preparationWait===finish)this._preparationWait=null;resolve();};
        const timer=setTimeout(finish,Math.max(250,state.retryAfterMs));this._preparationWait=finish;
      });
    }
    return false;
  }
  /** Shared-world admission for the loading screen. { ok: true, generation, token, actorId, characterId, map } once the lease and its first
   *  snapshot are installed. Otherwise { ok: false, error } plus at most one of: pending: true (an attempt is still in flight; join() and
   *  joinMap() resolve with its outcome) or failure: { phase, category, status, name, code, generation } (why the last attempt failed; see
   *  describeFailure: integers and allowlisted names only, never server or browser text). */
  admission() {
    if(!this.active)return {ok:this.game.save.authority!=='server',local:true};
    const self=this.self,map=Number(self?.map);
    if(this.disposed||this._joining||this._fatal||!this.ready||typeof this.token!=='string'||!this.token||
      this.game.save.authority!=='server'||!self||typeof self.id!=='string'||!self.id||
      self.characterId!==this.game.save.id||!Number.isSafeInteger(map)||map<0||
      this._snapshotLease!==this.token||this._snapshotLeaseGeneration!==this._leaseGeneration)
      return this._refusedAdmission('Shared world admission is not ready. Retry loading.');
    return {ok:true,generation:this._leaseGeneration,token:this.token,actorId:self.id,characterId:self.characterId,map};
  }
  /** Why admission is refused, as safe metadata only. While an attempt is still in flight there is no verdict yet (pending); a settled
   *  failure is reported only when it belongs to the attempt that just ended, never as a stale answer from an older one. */
  _refusedAdmission(error, attempt = null) {
    const refused = { ok: false, error };
    if (this.disposed) return refused;
    if (attempt === null) { if (this._joining) refused.pending = true; else if (this._admissionFailure) refused.failure = this._admissionFailure; }
    else if (attempt === this._leaseGeneration && this._admissionFailure?.generation === attempt) refused.failure = this._admissionFailure;
    return refused;
  }
  /** One join at a time. A caller that arrives while an attempt is in flight shares its outcome instead of reading a half-finished state. */
  join() {
    if (!this.active || this.disposed) return Promise.resolve(this.admission());
    if (this._joining) return this._joinFlight || Promise.resolve(this.admission());
    const flight = this._join(), done = () => { if (this._joinFlight === flight) this._joinFlight = null; };
    this._joinFlight = flight; flight.then(done, done);
    return flight;
  }
  async _join() {
    // (the active / disposed / already-joining guards live in join(), which shares one attempt between its callers)
    this._simulationPopulationView=null;
    this._cancelInitialJoin();
    const generation = ++this._leaseGeneration;
    this._joinBudget={generation,timeoutMs:15000};
    this._joining = true;
    let stage = this.prepareWorld ? 'ready' : 'join';   // where a failure happened: the readiness probe, the join request or installing its answer
    try {
      if(this.prepareWorld&&!await this._prepareWorld(generation))return this._refusedAdmission('Shared world preparation is not ready. Retry loading.',generation);
      if(this.disposed||generation!==this._leaseGeneration)return this._refusedAdmission('Shared world admission is not ready. Retry loading.',generation);
      if(this._joinBudget?.timeoutMs===120000)this._status('preparing','World prepared. Waiting for your saved character to join (up to two minutes).');
      else if(this._joinBudget?.timeoutMs===60000)this._status('preparing','Loading players on your map before entering (up to one minute).');
      stage = 'join';
      const result = await this._request('join', { characterId: this.game.save.id,cursorVersion:1,...(Number.isInteger(this.game.initialChannel)?{channel:this.game.initialChannel}:{}) }, false, generation);
      if (this.disposed || generation !== this._leaseGeneration) {
        if (result?.token) await this._request('leave', { token: result.token }, true).catch(() => {});
        return this._refusedAdmission('Shared world admission is not ready. Retry loading.', generation);
      }
      // The server always answers a join with a lease and the character. Anything else (a proxy page, another service) is a protocol failure.
      if (!result || typeof result !== 'object' || typeof result.token !== 'string' || !result.token || !result.self || typeof result.self !== 'object') throw protocolError('Invalid shared world join response.');
      stage = 'commit';
      this._fatal = false; this._admissionFailure = null;
      this.transport=result.transport==='polling'?'polling':'sse';this.token = result.token;this._commandSequence=0;this._serverClock=null; this.ready = true; this.sequence = Number(result.state?.sequence) || 0;
      this._seenEvents = new Set((result.state?.events || []).map(event => Number(event.sequence)).filter(Number.isSafeInteger));
      this.self = result.self; this._receiveSnapshot(result.state || { self: result.self, players: [], monsters: [], sequence: 0 });
      this.game.initialChannel=undefined; // Selection applies to this admission, not later in-world reconnects.
      this._status('connected', 'Connected to the shared world.'); this._connectEvents();
    } catch (error) { if (generation === this._leaseGeneration) this._error(error, stage); }
    finally { if(generation===this._leaseGeneration)this._joining=false;if(this._joinBudget?.generation===generation)this._joinBudget=null; }
    return this.admission();
  }
  async joinMap() {
    if (!this.active) return this.admission();
    if (!this.token) await this.join();
    if (this.token && this.self && this.game.player) {   // a failed join must not place the body from a lease that no longer exists
      if (Number(this.game.world?.info?.index) === Number(this.self.map)) {
        setServerPose(this.game.player, this.self); this.game.player.networkId = this.self.id;
        this.game.player.setPosition(this.self.x, this.self.z); this.game.cam?.snap?.();
        await this.poll();
      }
    }
    return this.admission();
  }
  _connectEvents() {
    this.stream?.close();this.stream=null;this._streamAt=0;
    if (this.transport==='polling'||!this.EventSourceClass || !this.token || this.disposed) return;
    try {
      this.stream = new this.EventSourceClass(API + `events?token=${encodeURIComponent(this.token)}`, { withCredentials: true });
      const stream = this.stream, lease = this.token, generation = this._leaseGeneration;
      const rowsDelta = new RowsDeltaDecoder();
      const current = () => !this.disposed && generation === this._leaseGeneration && this.token === lease && this.stream === stream;
      stream.addEventListener('snapshot', event => {
        if (!current()) return;
        let snapshot; try { snapshot = rowsDelta.expand(JSON.parse(event.data)); } catch (error) { rowsDelta.reset(); console.warn('[network] snapshot stream out of step; reconnecting', error); this._connectEvents(); return; }
        try { this._receiveSnapshot(snapshot); this._streamAt = Date.now(); }
        catch (error) { console.warn('[network] invalid snapshot', error); }
      });
      stream.onopen = () => { rowsDelta.reset(); if (current()) this._streamAt = Date.now(); };
      stream.onerror = () => { if (current()) { this._streamAt = 0; this._pollAt = 0; } };
    } catch { this.stream = null; }
  }
  _error(error, phase = 'request') {
    if (this.disposed) return;
    if (!error || typeof error !== 'object') error = new Error('Shared world request failed.');   // a non-Error rejection must not break the failure path
    this._lastCommandError = { message: error.message, at: Date.now() };
    // A generation commit temporarily rejects polling; it does not revoke the
    // authenticated lease or the native editor attached to that lease.
    if (error.status === 409 && error.code === 'WORLD_BUSY') {
      noteNetworkFailure(this, error, phase);
      this._pollAt = Date.now() + 500;
      return;
    }
    // ENGINE-CHOSEN: reuse the HUD's4s freshness window. Failed actions stay failed.
    // Only an actual request ticket and newer accepted same-lease snapshot prove live transport.
    const request=this._requestFailures?.get(error);this._requestFailures?.delete(error);
    const snapshotAge=Date.now()-this._snapshotAt;
    if(error.name==='AbortError' && error.status==null && request && this.ready && this.token &&
        request.lease===this.token && request.generation===this._leaseGeneration &&
        this._snapshotRevision>request.snapshotRevision && this._snapshotAt>=request.sentAt &&
        Date.now()>=request.sentAt && snapshotAge>=0 && snapshotAge<=4000){
      this._pollAt=Date.now()+500;this._paintStatus?.();return;
    }
    noteNetworkFailure(this, error, phase);
    this._pollAt = Date.now() + 3000;
    if ([401, 403, 409].includes(error.status)) {
      this.ready = false; this.stream?.close(); this.token = null; this._fatal = true;
      this.game.accountPermissions = { role: 'player', capabilities: [] };
      this._status('expired', `${error.message} Return to the character screen and sign in again.`);
    } else if (this.status !== 'disconnected') {
      this.ready = false; this._status('disconnected', 'Shared world connection interrupted. Reconnectingâ€¦');
    }
  }
  async poll() {
    if (!this.token || this._polling || this.disposed || this._joining) return;
    this._polling = true;
    const lease = this.token, generation = this._leaseGeneration;
    try {
      const snapshot = await this._request(`state?token=${encodeURIComponent(this.token)}`);
      if (this.disposed || generation !== this._leaseGeneration || lease !== this.token) return;
      this.ready = true; this._admissionFailure = null; this._receiveSnapshot(snapshot);
      if (this.status !== 'connected') this._status('connected', 'Shared world connection restored.');
    } catch (error) {
      // A renewed lease can outlive an outstanding response from its predecessor.
      if (!this.disposed && generation === this._leaseGeneration && lease === this.token) this._error(error, 'poll');
    } finally { this._polling = false; }
  }
  async action(type, data = {}, { onAccepted = null } = {}) {
    if (!this.active || !this.ready || !this.token || this._joining) { this.unavailable('Shared world connection'); return null; }
    const lease = this.token, generation = this._leaseGeneration;
    try {
      const result = await this._request('action', { token: this.token, type, ...data });
      if (this.disposed || generation !== this._leaseGeneration || lease !== this.token) return null;
      if (type === 'attack') {
        captureAttackRecovery(this, result.state || result);
        // Host acceptance precedes optional local presentation. A failed UI or
        // snapshot wrapper must not turn an accepted kill into a rejected hit.
        onAccepted?.(result);
      }
      if (result.self || result.players) this._receiveSnapshot(result.state || result);
      return result;
    } catch (error) {
      if (this.disposed || generation !== this._leaseGeneration || lease !== this.token) return null;
      if(type==='move')this._moveErrorStatus=error.status;
      this._lastCommandError = { message: error.message, at: Date.now() }; this._paintStatus?.();
      if (type === 'attack' && error.status === 429 && /combo step is cooling/i.test(error.message || '')) void this.poll?.();
      if ([400, 403, 404, 422, 429].includes(error.status) || error.status===409&&(error.code==='WORLD_BUSY'||['mail','guild','consign','supply'].includes(type)||type==='oxquiz'&&['OX_QUIZ_REFUSED','OX_QUIZ_REJECTED'].includes(error.code)||type==='siegerenew'&&error.code==='SIEGE_RENEW_REFUSED')) {
        if(error.status===409)void this.poll();
      // A just-arrived movement snapshot can leave one attack request a few
      // centimetres ahead of the server pose.  The controller retries that
      // bounded race; don't turn it into a scary red combat error while the
      // retry is pending.  Other authoritative errors remain visible.
      // A movement report already in flight when the host killed the body is refused, and a stop overtaken by a newer
      // movement report is superseded by it; neither is a player error.
      // siege refusals arrive as string codes ('siege:700:73'); src/systems/extras/siege.js shows their original text
      if (type !== 'move' && !(type === 'stop' && /revive before acting|older movement command/i.test(error.message || '')) && !(type === 'attack' && /outside attack range/i.test(error.message || '')) && !/^siege:\w+:\d+$/.test(error.message || '') && !(type==='oxquiz'&&/^oxquiz:(22|654):\d+$/.test(error.message||'')) && !(type==='zuto'&&/^zuto:\d+:\d+$/.test(error.message||''))) this.game.chat?.system?.(error.message, 'err');
      }
      else this._error(error, 'action');
      return null;
    }
  }
  move(x, z, { direct = false } = {}) {
    if (!Number.isFinite(x) || !Number.isFinite(z) || !this.ready) return false;
    const now = performance.now();
    if (syncActive(this)) return this._syncMove(x, z, now);
    if (this._movePending) return true;
    if (now < this._nextMove) return true;
    // R walk: the host moves a walking player at the class walk stride (hud-options walkMode -> player.walking())
    const walk = typeof this.game.player?.walking === 'function' ? this.game.player.walking() || null : null;
    if (!direct && this._lastMove && Math.hypot(x - this._lastMove.x, z - this._lastMove.z) < 0.03 && (this._lastMove.walk || null) === walk) return true;
    this._nextMove = now + 175; this._movePending = true;
    this._moveErrorStatus=null;this._movementIntentAt=now;const sentAt=now,generation=this._motionGeneration||0;
    // Only accepted commands suppress identical destinations. A rate-limit/transient failure
    // must allow the controller's next frame to retry instead of running in place forever.
    void this.action('move', walk ? { x, z, walk } : { x, z }).then(result => { const elapsed=performance.now()-sentAt;if(result)this._moveRoundTrip=elapsed;
      if(generation!==(this._motionGeneration||0))return;this._lastMove = result ? { x, z, walk } : null; if (!result&&this._moveErrorStatus!==429) this._cancelPrediction(); })
      .finally(() => {
        this._movePending = false;
        if (this._queuedStop) { this._queuedStop = false; this.stop(); }
      });
    return true;
  }
  // MOVE-NO-RUBBERBAND: client-predicted intent. Sent every SEND_INTERVAL_MS while the body moves (sooner on a turn),
  // pipelined (no wait for the previous reply), carrying the body's real position; the host validates and echoes it.
  // A failed/late intent never moves the body: only a host posRev bump does (movement-sync.js).
  _syncMove(x, z, now) {
    if (syncMoveBlocked(this) || syncDead(this)) return true;   // the host refuses movement while dead
    if (now < this._nextMove) return true;
    const walk = typeof this.game.player?.walking === 'function' ? this.game.player.walking() || null : null;
    if (!this.game.player || !syncShouldSend(this, x, z, now, walk)) return true;
    this._nextMove = now + 33; this._moveErrorStatus = null; this._movementIntentAt = now;
    const report = movementReport(this, now), ms = moveSyncState(this); ms.moving = true;
    void syncTrack(this, this.action('move', walk ? { x, z, walk, ...report } : { x, z, ...report })).then(result => {
      if (result) { this._moveRoundTrip = performance.now() - now; this._lastMove = { x, z, walk }; } else this._lastMove = null;
    });
    return true;
  }
  // MOVE-NO-RUBBERBAND: mount/dismount first settle the body where it really is (stop report), then hold local
  // movement until the host answers, so the host's stand-still / cast rules never pull the rider back.
  async settleMovement(fn) {
    if (!syncActive(this)) return fn();
    this._settling = (this._settling || 0) + 1;
    try {
      const c = this.game.controller; if (c) { c.order = null; c.combo = null; c._holdMove = false; }
      if (this._moveSync?.moving) await this.stop();
      return await fn();
    } finally { this._settling--; }
  }
  // Visual-only prediction. Server position, path/collision, combat and saves remain authoritative.
  // Click lead stays250ms. Held input additionally budgets measured transport,
  // bounded at400ms. Mounted lead uses the canonical stride for this time window;
  // ordinary movement retains its1.5cell cap. No authoritative position is changed.
  predictAdvance(x, z, distance) {
    const p = this.game.player, now = performance.now();
    if (!this.ready || !this.self || !p || p.dead || now < (this._predictionBlockedUntil || 0)) return false;
    if (syncActive(this)) return this._syncPredict(p, x, z, distance, now);
    const d = Math.hypot(x - p.x, z - p.z);
    if (!(d > 0) || !(distance > 0)) return false;
    const step = Math.min(d, distance), nx = p.x + (x-p.x)/d*step, nz = p.z + (z-p.z)/d*step;
    if (this.game.controller?._walkable && !this.game.controller._walkable(nx, nz)) return false;
    if (this.game.controller?._lineClear && !this.game.controller._lineClear(p.x, p.z, nx, nz)) return false;
    // A valid attempted step stays fresh when the bounded lead temporarily stops
    // advancing. This timestamp never authorizes a position or enlarges the cap.
    this._predictionIntentAt = now;
    const lead = this._predictionLead();this._visualLead=lead;
    if (Math.hypot(nx - this.self.x, nz - this.self.z) > lead) return false;
    this._localStopped=false;this._stopServer=null;p.setPosition(nx,nz); p._serverPose = null; this._predictionAt = now;
    return true;
  }
  // MOVE-NO-RUBBERBAND: the local body moves at the host's canonical speed with local collision and no lead cap;
  // only a physically impossible lead over the last acknowledged report (host gone) or a host lock stops it.
  _syncPredict(p, x, z, distance, now) {
    if (this.self.dead || syncMoveBlocked(this) || now < (moveSyncState(this).holdUntil || 0)) return false;
    const d = Math.hypot(x - p.x, z - p.z);
    if (!(d > 0) || !(distance > 0)) return false;
    const step = Math.min(d, distance), nx = p.x + (x-p.x)/d*step, nz = p.z + (z-p.z)/d*step;
    if (this.game.controller?._walkable && !this.game.controller._walkable(nx, nz)) return false;
    if (this.game.controller?._lineClear && !this.game.controller._lineClear(p.x, p.z, nx, nz)) return false;
    if (!syncLeadAllows(this, nx, nz, now)) return false;
    this._predictionIntentAt = now; this._predictionAt = now; this._localStopped = false; this._stopServer = null;
    p.setPosition(nx, nz); p._serverPose = null;
    return true;
  }
  _predictionLead() {
    const speed = Number(this.game.player?.groundSpeed?.('run')) || 3.445;
    const seconds=this.game.controller?._wasd?Math.min(.4,.3+Math.max(0,Number(this._moveRoundTrip)||0)/1000):.25;
    const mounted=this.self?.mount?.phase==='on'&&Number.isFinite(Number(this.self.moveSpeed))&&Number(this.self.moveSpeed)>0;
    if(mounted)return Math.max(.25,Number(this.self.moveSpeed)*seconds);
    return Math.min(1.5, Math.max(0.25, speed * seconds));
  }
  _cancelPrediction(block = true) {
    this._predictionAt = -Infinity;
    this._predictionIntentAt = -Infinity;
    if(block)this._localStopped=false;
    const now=performance.now();
    this._predictionBlockedUntil = block ? now + 200 : 0;
    if (this.self && this.game.player) setServerPose(this.game.player, this.self, now, !block);
  }
  stop() {
    if (!this.self || !this.ready) return;
    if (syncActive(this)) {
      // MOVE-NO-RUBBERBAND: the stop carries where the body stopped, so host and client end on the same point.
      this._queuedStop = false; this._lastMove = null; this._motionGeneration = (this._motionGeneration || 0) + 1;
      this._predictionAt = -Infinity; this._predictionIntentAt = -Infinity; this._predictionBlockedUntil = 0;
      if (this.game.player) this.game.player._serverPose = null;
      if (!this.game.player) return this.action('stop');
      const ms = moveSyncState(this); ms.moving = false; ms.lastHeading = null;
      if (syncDead(this)) return;   // dead: nothing to report; one resync goes out after revive (syncNeedsResync)
      return syncTrack(this, this.action('stop', movementReport(this)));
    }
    this._queuedStop = false;
    // A release does not reset the server's 150ms move throttle. Preserve
    // its local send window while new held input predicts immediately.
    this._lastMove = null;
    this._motionGeneration=(this._motionGeneration||0)+1;
    this._predictionAt=-Infinity;this._predictionIntentAt=-Infinity;this._predictionBlockedUntil=0;this._localStopped=true;this._stopServer=null;this._stoppedLead=this._visualLead||this._predictionLead();
    // Freeze the bounded visual offset at release. Older walking snapshots must
    // not create a fresh correction tween after keyup. The authoritative pose
    // remains in self; the next input or an out-of-bound correction reconciles it.
    if(this.game.player)this.game.player._serverPose=null;
    // A release must not wait for an in-flight move or hit its 150ms throttle.
    // Stop carries no position: the server clears its own path at its own pose.
    const generation=this._motionGeneration;
    void this.action('stop').then(result=>{
      if(generation!==this._motionGeneration||!this._localStopped)return;
      const self=result?.self;
      if(self&&Number.isFinite(self.x)&&Number.isFinite(self.z))this._stopServer={x:self.x,z:self.z,sequence:Number(result.sequence)};
      else this._localStopped=false;
    });
  }
  attack(target, { retry = false, step = null, rootPrediction = null, onSettled = null } = {}) {
    const owner = rootPrediction?.prediction?.controller;
    let settled = false;
    const settle = accepted => {
      if (settled) return;
      settled = true;
      owner?.settleAttackRoot?.(rootPrediction, accepted);
      onSettled?.(accepted);
    };
    if (!target?.networkId || !this.ready) { settle(false); return false; }
    const now = performance.now();
    // The host admits hits at the combo cadence of the game data (src/game/attack-timing.js) and sends the client's own
    // request spacing as self.attackCooldownMs (shorter than the combo's fastest step). The host's next-attack time is not
    // compared with the local estimate of the host clock: that estimate trails by the network delay, held back on-time
    // combo hits, and the host decides anyway. A few requests may be in flight, so a round trip longer than a fast combo
    // step does not drop its hit.
    const pending=Number(this._attackPending)||0;
    if (pending >= ATTACK_REQUESTS_IN_FLIGHT || now < (this._nextAttack || 0) || now - (this._lastAttack ?? -Infinity) < ATTACK_MIN_GAP_MS) { settle(false); return false; }
    const spacing=Number(this.self?.attackCooldownMs),cooldown=Number.isFinite(spacing)&&spacing>=0?spacing:1000;
    this._lastAttack = now; this._nextAttack=now+cooldown;this._attackPending=pending+1;
    if (rootPrediction?.prediction?.status === 'windup') rootPrediction.prediction.status = 'submitted';
    // step: the combo step whose clip root curve the host moves the record along (server/world/attack-root-motion.mjs)
    void this.action('attack', { targetId: target.networkId, ...(Number.isInteger(step) && step >= 0 && step <= 63 ? { step } : {}), ...(this.fieldPk?.forcedFor?.(target) ? { forced: true } : {}) }, {onAccepted: () => settle(true)}).then(result=>{
      settle(!!result);
      if (result) return;
      this._nextAttack = performance.now() + 250;
      const message = this._lastCommandError?.message || '';
      // The server is authoritative.  If its pose advanced between the
      // client's range check and the request, give the accepted movement one
      // short retry instead of dropping the first-person swing.  This is one
      // retry only, and only while the same live target is still selected.
      // A root-bearing swing has already been rolled back on refusal. Its normal controller
      // order may start another swing; an orphan delayed retry must not move only the host.
      if (!rootPrediction && !onSettled && !retry && /outside attack range/i.test(message) && this.game.controller?.player?.target === target && !target.dead && !target.disposed) {
        setTimeout(() => {
          if (this.disposed || !this.ready || target.dead || target.disposed || this.game.controller?.player?.target !== target) return;
          this._nextAttack = 0;
          this.attack(target, { retry: true, step });
        }, 140);
      }
    }).catch(()=>{settle(false);}).finally(()=>{this._attackPending=Math.max(0,(Number(this._attackPending)||0)-1);});
    return true;
  }
  travel(map, gateId) { return this.action('travel', { map: Number(map), ...(Number.isSafeInteger(gateId) ? { gateId } : {}) }); }
  revive(uid) { return this.action('revive',uid==null?{}:{uid}); }
  chat(text,channel='normal') {
    text = String(text || '').trim();
    if (!text) return false;
    let targetName;
    if(channel==='whisper'){
      const match=/^(\S+)\s+(.+)$/.exec(text);
      if(!match){this.game.chat?.system?.('Enter a character name followed by your whisper.', 'err');return false;}
      targetName=match[1];text=match[2];this.game.chat&&(this.game.chat.lastWhisper=targetName);
    }
    if (text.length > 250) { this.game.chat?.system?.('Messages can contain at most 250 characters.', 'err'); return false; }
    void this.action(channel==='party'?'party':'chat',channel==='party'?{operation:'chat',text}:{text,...(channel==='normal'?{}:{channel}),...(targetName?{targetName}:{})}); return true;
  }
  _profile(self) {
    const g = this.game, profile = self.profile;
    const previousDil = Number(g.save.dil) || 0;
    if (self.permissions) g.accountPermissions = self.permissions;
    if (profile && profile.id === g.save.id) {
      const changed = g.save.level !== profile.level || JSON.stringify(g.save.stats) !== JSON.stringify(profile.stats);
      const inventoryChanged=JSON.stringify(g.save.inventory || []) !== JSON.stringify(profile.inventory || []);
      const questsChanged=JSON.stringify(g.save.quests || {}) !== JSON.stringify(profile.quests || {});
      // The server's profile.equipment view is built without the animated-weapon action tables (skeleton + loop
      // clip), so assigning it would strip every animated weapon of its own skeleton (and with it the bone its
      // authored effects attach to). The client re-derives its view from the canonical save.equip instead.
      const localEquipment = g.save.equipment, localGM = g.save.gm;
      Object.assign(g.save, profile, { authority: 'server' });
      if (localEquipment) g.save.equipment = localEquipment;
      keepClientLocalGM(localGM, g.save);   // client-only GM toggles (Ctrl+click teleport) are not in the server profile
      // Containers retain their original array. A canonical snapshot replaces it;
      // rebind before refreshing UI so server starter kits/rewards actually appear.
      for(const [key,field] of [['bag','inventory'],['stash','storage'],['costumeBag','costumeBag']]) {
        if(g.items?.[key] && Array.isArray(g.save[field])) g.items[key].list=g.save[field];
      }
      saves.applyServerCharacter?.(profile);
      if(inventoryChanged) {g.events?.emit?.('inventory',{reason:'server'});g.events?.emit?.('items',{reason:'server'});}
      if(questsChanged) g.events?.emit?.('quest:changed',{server:true});
      if (changed && g.player) { g.refreshPlayerStats?.(false); g.events?.emit?.('stats', { server: true }); }
    } else Object.assign(g.save, { level: self.level, exp: self.exp, dil: self.dil, map: self.map, authority: 'server' });
    g.save.hp = self.hp;
    if ((Number(g.save.dil) || 0) !== previousDil) g.events?.emit?.('dil', { amount: (Number(g.save.dil) || 0) - previousDil, total: Number(g.save.dil) || 0, server: true });
    g.events?.emit?.('server:profile', { profile: g.save });
  }
  _receiveSnapshot(snapshot) {
    if (this.disposed || !snapshot?.self || !Number.isFinite(Number(snapshot.sequence))) return;
    if (this._fatal && !this.token) return;
    captureAttackRecovery(this, snapshot);
    // Presentation wrappers may reject old world state. Recover its unseen events
    // at transport ingress, before those wrappers can discard a late HTTP/SSE reply.
    // The event receiver retains character/map/instance/channel checks and deduplication.
    if (Number(snapshot.sequence) < this.sequence) { this._deliverSnapshotEvents(snapshot); return; }
    this._snapshot(snapshot);
  }
  _snapshot(snapshot) {
    if (this.disposed || !snapshot?.self || !Number.isFinite(Number(snapshot.sequence))) return;
    if (this._fatal && !this.token) return;
    if (Number(snapshot.sequence) < this.sequence) { this._deliverSnapshotEvents(snapshot); return; }
    if(Number.isFinite(snapshot.serverTime)){this._serverClock={time:snapshot.serverTime,at:performance.now()};this._motionClock.sample(snapshot.serverTime,performance.now());}
    this._snapshotRevision=(this._snapshotRevision||0)+1;
    this._signalVisuals();
    this._snapshotLease=this.token;this._snapshotLeaseGeneration=this._leaseGeneration;
    this.sequence = Number(snapshot.sequence); this.self = snapshot.self;
    this._scenePreparationInvalid=false;
    try {
      const required=snapshot.npcScenePreparationRequired===undefined?false:snapshot.npcScenePreparationRequired;
      this._scenePreparation=scenePreparation(snapshot.npcSceneReadiness,this.self,required);
      this._scenePreparationRequired=required;
    }
    catch { this._scenePreparation=null;this._scenePreparationRequired=false;this._scenePreparationInvalid=true; }
    this.onlineCount = Number.isSafeInteger(snapshot.onlineCount) && snapshot.onlineCount >= 0 ? snapshot.onlineCount : (snapshot.players || []).length || 1;
    this._simulationPopulationView=this.active&&this.token?simulationPopulationView(snapshot.simulationPopulation):null;
    this.ready = true; this._profile(this.self);
    if(snapshot.party && JSON.stringify(snapshot.party)!==JSON.stringify(this.party)){
      this.party=snapshot.party;this.game.events?.emit?.('server:party',this.party);
    }
    if(snapshot.expedition && JSON.stringify(snapshot.expedition)!==JSON.stringify(this.expedition)){
      this.expedition=snapshot.expedition;this.game.events?.emit?.('server:expedition',this.expedition);
    }
    if (this.status !== 'connected') this._status('connected');
    this._snapshotAt = Date.now(); this._paintStatus?.();
    if ((this.self.saveError || null) !== (this._saveError || null)) {
      this._saveError = this.self.saveError || null;
      this.game.chat?.system?.(this._saveError ? `Server save delayed: ${this._saveError}` : 'Server progress saving recovered.', this._saveError ? 'err' : 'sys');
      this.game.events?.emit?.('server:persistence', { error: this._saveError });
    }
    const g = this.game, map = Number(g.world?.info?.index);
    if (!g.world || map !== Number(this.self.map)) {
      if (g.world && !g._loadingMap && !this._transferring) {
        this._transferring = true; this._clearActors();
        Promise.resolve(g.enterMap(this.self.map, { x: this.self.x, z: this.self.z }, null, { serverTransfer: true }))
          .finally(() => { this._transferring = false; });
      }
      return;
    }
    const scene=`${map}:${this.self.instanceId||''}`;
    if (this._actorMap !== map || this._actorScene !== scene) { this._clearActors(); this._actorMap = map; this._actorScene=scene; }
    if (g.player) {
      const wasDead = g.player.dead;
      g.player.networkId = this.self.id;
      const now = performance.now(), previous = this._authoritativeSelf;
      if (!previous || Math.hypot(this.self.x-previous.x,this.self.z-previous.z) > 0.005) this._serverMotionAt = now;
      this._authoritativeSelf = { x: this.self.x, z: this.self.z };
      // MOVE-NO-RUBBERBAND: in client-predicted mode our own echoed report is acknowledged without moving the body;
      // only a host posRev bump (forced displacement / impossible report) moves it. Else: legacy reconciliation.
      if (!syncSelfSnapshot(this, this.self, now, setServerPose)) {
      // Once stop is acknowledged, later authoritative movement is a forced
      // displacement (or another server action), not an old walking snapshot.
      if(this._localStopped&&this._stopServer&&Number(snapshot.sequence)>this._stopServer.sequence&&Math.hypot(this.self.x-this._stopServer.x,this.self.z-this._stopServer.z)>.005){this._localStopped=false;this._stopServer=null;this._predictionIntentAt=-Infinity;}
      const stopped = this._localStopped && Math.hypot(g.player.x-this.self.x,g.player.z-this.self.z)<=(this._stoppedLead||this._predictionLead());
      const inputActive = !!(g.controller?._wasd || g.controller?.order) && !this._localStopped;
      const predictionAt = Math.max(this._predictionAt ?? -Infinity, inputActive ? (this._predictionIntentAt ?? -Infinity) : -Infinity);
      // A skill clip's root curve carries the body here and on the host (engine root motion): the host pose of the same
      // curve is a few frames behind or ahead, so it must not tween the body while the curve runs; afterwards it reconciles.
      const rootHold = !!(g.skills?.rootHolding?.() || g.controller?.attackRootHolding?.()) && Math.hypot(g.player.x-this.self.x,g.player.z-this.self.z) <= 16;
      const predict = !this.self.dead && !g.player.dead && (stopped || rootHold || now - predictionAt < 200 &&
        (now - (this._serverMotionAt ?? now) < 400||now-(this._movementIntentAt??-Infinity)<400) && Math.hypot(g.player.x-this.self.x,g.player.z-this.self.z) <= this._predictionLead());
      const yaw = g.player._yawGoal;
      setServerPose(g.player, this.self,now,predict);
      if (predict) { g.player._serverPose = null; g.player._yawGoal = yaw; }
      else if (g.player._serverPose) g.player._serverPose.duration = 100;
      if (!predict&&now-(this._predictionAt??-Infinity)<200&&now-(this._movementIntentAt??-Infinity)>=400&&now - (this._serverMotionAt ?? now) >= 400){this._predictionBlockedUntil=now+200;this._predictionAt=-Infinity;}
      }
      g.player.level = this.self.level;
      if (g.player.dead && !wasDead) { g.controller?.onPlayerDeath?.(); g.hud?.showDeath?.(uid => this.revive(uid)); }
    }
    // Keep only this frame's referenced damage targets through reconciliation.
    // Presentation may outlive removal; this local map never retains ghost actors between frames.
    const damageTargets=new Map();
    for(const event of snapshot.events||[])if(event.type==='damage'){
      const target=this.players.get(event.targetId)||this.monsters.get(event.targetId)||this.servants.get(event.targetId);
      if(target)damageTargets.set(event.targetId,target);
    }
    const required=new Set((snapshot.party?.members||[]).map(member=>typeof member==='string'?member:member.id));
    // The selected actor lives on the player. PlayerController has no target
    // property; reading it there let a followed bot drop out of the bounded
    // visual cohort, which disposed the actor and canceled Follow.
    const target=g.player?.target?.networkId;if(target)required.add(target);
    for(const event of snapshot.events||[])if([event.actorId,event.sourceId,event.targetId].includes(this.self.id))for(const id of [event.actorId,event.sourceId,event.targetId])if(id)required.add(id);
    this._reconcile(this.players, visibleActorRows((snapshot.players || []).filter(p => p.id !== this.self.id && Number(p.map) === map),this.self,{required,prior:new Set(this.players.keys())}), RemotePlayer);
    // monsters / summons move on the host tick: their poses are stamped with that tick (older hosts: the snapshot time)
    const poseTime = Number.isFinite(snapshot.tickAt) ? snapshot.tickAt : Number.isFinite(snapshot.serverTime) ? snapshot.serverTime : null;
    // Retain nearby monster bodies through small movements, including
    // pending loads; the wider exit radius still unloads distant bodies.
    this._reconcile(this.monsters, visibleActorRows((snapshot.monsters || []).filter(m => Number(m.map) === map),this.self,{kind:'monster',required,prior:new Set(this.monsters.keys())}), RemoteMonster, poseTime);
    this._reconcile(this.servants,(snapshot.summons||[]).filter(s=>Number(s.map)===map),RemoteServant, poseTime);
    this.servantSnapshot?.((snapshot.summons||[]).filter(s=>Number(s.map)===map));
    this._deliverSnapshotEvents(snapshot,damageTargets);
  }
  _deliverSnapshotEvents(snapshot,damageTargets=null) {
    // HTTP replies and SSE snapshots can arrive in either order. Receiving a
    // newer pose does not acknowledge events carried by an older stream frame.
    if (!this.self || snapshot.self?.id !== this.self.id || Number(snapshot.self.map) !== Number(this.self.map) ||
        (snapshot.self.instanceId || null) !== (this.self.instanceId || null) ||
        (snapshot.self.channel ?? 0) !== (this.self.channel ?? 0)) return;
    const seen = this._seenEvents ||= new Set();
    for (const event of snapshot.events || []) {
      const sequence = Number(event.sequence);
      if (!Number.isSafeInteger(sequence) || sequence < 0 || seen.has(sequence)) continue;
      seen.add(sequence);
      // Older presentation wrappers forward only the event argument. Keep the
      // reconciled-away damage targets scoped to this synchronous delivery so
      // the base handler can still show a lethal hit, without retaining ghosts.
      const previousDamageTargets=this._eventDamageTargets;
      this._eventDamageTargets=damageTargets;
      try { this._event(event,damageTargets); }
      catch (error) {
        // A presentation failure must not drop the rest of an accepted host
        // batch or turn its command receipt into a transport failure. Do not
        // replay a partially presented event: it may already have emitted cues.
        const failure=this._eventPresentationFailure ||= {count:0,reportedCount:0,reportedAt:-Infinity};
        failure.count++;failure.sequence=sequence;failure.type=event.type;
        const now=Date.now();
        // Keep a visible original exception, while bounding repeated failures
        // to one console report per five seconds. Counts remain inspectable.
        if(now-failure.reportedAt>=5000){
          console.error('[network] event presentation failed; continuing batch', {sequence,type:event.type,failures:failure.count-failure.reportedCount}, error);
          failure.reportedAt=now;failure.reportedCount=failure.count;
        }
      } finally {
        if(previousDamageTargets===undefined)delete this._eventDamageTargets;
        else this._eventDamageTargets=previousDamageTargets;
        // ENGINE-CHOSEN bounded duplicate history, including failed attempts.
        if (seen.size > 8192) seen.delete(seen.values().next().value);
      }
    }
  }
  _reconcile(collection, rows, Type, poseTime = null) {
    const live = new Set();
    for (const row of rows) {
      live.add(row.id); let actor = collection.get(row.id);
      if (!actor) {
        actor = new Type(this.game, row); collection.set(row.id, actor);
        this._loads.push({ actor, generation: this._generation });
      }
      if(actor.kind==='player')actor.npcPlayer=row.npcPlayer===true;
      setServerPose(actor, row, performance.now(), false, poseTime);
      if(actor.setAppearance?.(row)){
        if(actor._appearanceQueued)actor._appearanceDirty=true;
        else{actor._appearanceQueued=true;this._loads.push({actor,generation:this._generation,appearance:true});}
      }
      if(actor.kind==='servant'&&row.state==='attack'&&actor._networkState!=='attack'){
        actor._networkAnimHold=performance.now()+700;actor.play('attack',{loop:false});
      }
      actor._networkState=row.state;
      this.actorMount?.(actor,row);
      this.actorSkillState?.(actor,row);
    }
    for (const [id, actor] of collection) if (!live.has(id)) { actor.dispose(); collection.delete(id); }
    this._loadActors();
  }
  _signalVisuals() {
    const waiters=this._visualWaiters;
    if(waiters){for(const wake of [...waiters])wake();}
  }
  captureInitialActors(admission) {
    const current=this.admission();
    if(!current.ok||!admission?.ok||current.generation!==admission.generation||current.token!==admission.token||current.actorId!==admission.actorId||current.characterId!==admission.characterId||current.map!==admission.map)
      throw new Error('Initial shared actor admission changed. Retry loading.');
    return {network:this,admission:{...admission},generation:this._generation,world:this.game.world,instanceId:this.self.instanceId||null,channel:this.self.channel??0,actors:initialSceneActors(this.actors(),this.self)};
  }
  async awaitInitialActors(capture,{timeoutMs=20000,onProgress=()=>{}}={}) {
    const initial=new Set(capture.actors);
    const deadline=performance.now()+(Number.isFinite(timeoutMs)?Math.max(1,timeoutMs):20000);
    let sceneCaptured=false,capturedPreparation=null;
    this._initialVisualActors=initial;
    try {
      for(;;){
        const current=this.admission(),a=capture.admission;
        if(capture.network!==this||this.game.network!==this||this.game.world!==capture.world||this._generation!==capture.generation||!this._installationComplete||!current.ok||current.generation!==a.generation||current.token!==a.token||current.actorId!==a.actorId||current.characterId!==a.characterId||current.map!==a.map||(this.self.instanceId||null)!==capture.instanceId||(this.self.channel??0)!==capture.channel||Number(capture.world?.info?.index)!==a.map)
          throw new Error('Initial shared actor scene or lease changed. Retry loading.');
        if(this._scenePreparationInvalid)throw new Error('Scene preparation is invalid. Retry loading.');
        const preparation=this._scenePreparation;
        if(preparation?.phase==='incomplete')throw new Error('Players on this map did not finish preparing. Retry loading.');
        const preparing=preparation?.phase==='warming'||(this._scenePreparationRequired&&!preparation);
        const preparationRevision=preparation?.revision??null;
        if(sceneCaptured&&(preparing||preparationRevision!==capturedPreparation)){
          initial.clear();sceneCaptured=false;
        }
        if(!preparing&&!sceneCaptured){
          // Capture after host admissions finish. Fixed membership prevents
          // new arrivals/moving crowds from endlessly extending the barrier.
          for(const actor of initialSceneActors(this.actors(),this.self))initial.add(actor);
          sceneCaptured=true;capturedPreparation=preparationRevision;
        }
        this._loadActors();
        let pending=false,clip=null;
        for(const actor of initial){
          if(actor.disposed||!(this.players.get(actor.networkId)===actor||this.monsters.get(actor.networkId)===actor||this.servants.get(actor.networkId)===actor))continue;
          if(actor._networkVisualPending||this._loads.some(job=>job.actor===actor&&job.generation===capture.generation)||actor._appearanceQueued||actor._appearanceDirty){pending=true;continue;}
          if(actor._clipPending){pending=true;clip ||= actor._clipFlight;continue;}
          const model=actor.model;
          if(!actor.loaded||!model||actor._appearanceFailed||actor._networkVisualRevision!==(actor._appearanceRevision||0)||model.missingPartKeys?.length||(!model.empty&&model.skelKey&&model.missingSkeleton))
            throw new Error('An initial shared actor body did not finish loading. Retry loading.');
          const weapon=actor.weapon;
          if(actor.kind==='player'&&((weapon?.def?.mesh&&!weapon.main)||(weapon?.def?.leftMesh&&!weapon.second)))
            throw new Error('An initial shared actor weapon did not finish loading. Retry loading.');
          if(!model.empty&&model.skelKey&&actor._clipRequested&&!actor.animator?.current)
            throw new Error('An initial shared actor animation did not finish loading. Retry loading.');
        }
        onProgress(preparing?{phase:'warming',active:preparation?.active??0,target:preparation?.target??0}:{phase:'models',actors:initial.size,pending});
        if(!preparing&&!pending)return {ok:true,generation:capture.generation,actors:initial.size,sceneRevision:preparation?.revision??null};
        // A bounded deadline is a retryable failure, never permission to enter
        // with required bodies still pending. Their native load jobs keep their
        // exact generation/disposal fences and may populate the cache for retry.
        if(performance.now()>=deadline)throw new Error('Nearby players or creatures did not finish loading. Retry loading.');
        await new Promise(resolve=>{
          const wake=()=>{clearTimeout(timer);this._visualWaiters?.delete(wake);resolve();};
          const timer=setTimeout(wake,Math.max(1,Math.min(250,deadline-performance.now())));
          (this._visualWaiters ||= new Set()).add(wake);
          if(clip)Promise.resolve(clip).then(wake,wake);
        });
      }
    } finally {if(this._initialVisualActors===initial)this._initialVisualActors=null;}
  }
  _loadActors() {
    while (this._loading < 2 && this._loads.length) {
      let next=this._initialVisualActors?this._loads.findIndex(job=>this._initialVisualActors.has(job.actor)&&!job.actor._networkVisualPending):-1;
      if(next<0)next=this._loads.findIndex(job=>!job.actor._networkVisualPending);
      if(next<0)break;
      const { actor, generation, appearance } = this._loads.splice(next,1)[0];
      if (actor.disposed || generation !== this._generation) continue;
      this._loading++;
      if(actor.kind==='player')actor._appearanceQueued=true;
      const revision=actor._appearanceRevision||0;
      actor._networkVisualPending=true;
      Promise.resolve().then(()=>appearance?actor.refreshAppearance():actor.load()).then(result=>{
        if(!actor.disposed&&generation===this._generation&&revision===(actor._appearanceRevision||0)&&(!appearance||result===true))actor._networkVisualRevision=revision;
      }).catch(error => console.warn('[network] actor visuals', error))
        .finally(() => {
          actor._networkVisualPending=false;
          actor._appearanceQueued=false;
          if(actor._appearanceDirty&&!actor.disposed&&generation===this._generation){
            actor._appearanceDirty=false;actor._appearanceQueued=true;
            this._loads.push({actor,generation,appearance:true});
          }
          this._loading--; this._loadActors();this._signalVisuals();
        });
    }
  }
  _event(event,damageTargets=this._eventDamageTargets??null) {
    const g = this.game;
    if (event.type === 'gm:notice') {
      if (event.text) { g.gm?.windows?.showNotice?.(event.text); g.chat?.system?.(event.text, 'gm'); }
      else g.gm?.windows?.hideNotice?.();
    }
    const byId = id => id === this.self?.id ? g.player : this.players.get(id) || this.monsters.get(id) || this.servants.get(id) || this.dungeonActor?.(id) || this.eventActor?.(id);
    const actor = byId(event.actorId || event.sourceId), target = byId(event.targetId)||(event.type==='damage'?damageTargets?.get(event.targetId):null);
    if(event.type==='itemuse')this.itemUseEvent?.(event,actor);
    // Recovery numbers (green HP / blue MP digits): the host reports what an item or heal skill actually restored.
    if(event.type==='itemuse'&&actor){
      if(Number(event.hp)>0)g.hud?.floater?.(actor,`+${Math.round(event.hp)}`,'heal');
      if(Number(event.mp)>0)g.hud?.floater?.(actor,`+${Math.round(event.mp)} MP`,'heal');
    }
    if(event.type==='heal'&&target&&Number(event.amount)>0)g.hud?.floater?.(target,`+${Math.round(event.amount)}`,'heal');
    if(event.type==='megaphone')g.superchat?.receive?.(event);   // Megaphone broadcast (hud-options/superchat.js)
    if(event.type==='emote'&&actor&&actor!==g.player)g.life?.emotes?.playRemote?.(actor,event.motion);
    this.skillEvent?.(event,actor,target);
    if (event.type === 'attack' && actor && actor !== g.player) {
      // a monster's swing carries the chosen attack block's ATTACK clip index (monsters.json attackActionIndex) so aggro /
      // power / range blocks play their own clip, as the offline brain does
      // 2.2.1: a monster holds its swing for the clip's own TimeLength (monster.dat action set, Monster.attackTiming), as the
      // offline brain does; the old flat 700 ms cut every range shot (1.3-2 s clips, e.g. Yetarian Bow 1.4 s) at half-draw.
      // Server movement releases the hold (actors.js advanceServerPose) so a chasing monster never slides in its swing pose.
      const variant = Number.isInteger(event.variant) ? event.variant : 0;
      // a player's swing (the host now names its combo step) is held for that clip's TimeLength: the host's record slides
      // along the clip's root curve meanwhile (attack-root-motion.mjs) and must not switch the body to its run cycle
      const playerClip = actor.kind === 'player' && Number.isInteger(event.variant) ? actor.classDef?.anims?.attack?.[event.variant % Math.max(1, actor.classDef?.anims?.attack?.length || 1)] : null;
      const swing = actor.kind === 'monster' && typeof actor.attackTiming === 'function' ? actor.attackTiming(variant).len * 1000 : (Number(playerClip?.timeLength) || 0) * 1000;
      actor._networkAnimHold = performance.now() + Math.max(700, swing || 0); actor._networkAttackHold = actor.kind === 'monster';
      // turn to the target on every swing, as the offline brain (ai.js _startSwing): snapshot rows carry no yaw, so a monster that
      // never had to step (an archer in bow range, a GM-called monster) otherwise shot in its random spawn direction
      if (actor.kind === 'monster' && target && target !== actor) actor.faceTowards?.(target.x, target.z);
      actor.play('attack', { loop: false, ...(Number.isInteger(event.variant) ? { variant: event.variant } : {}) });
      g.events?.emit?.('server:attack', { actor, index: event.index ?? event.step ?? 0 });
    }
    if (event.type === 'damage' && target) {
      actor && (actor.lastCombat = g.time); target.lastCombat = g.time;
      const blocked = !!(event.guard || event.block);
      const kind = event.miss ? 'miss' : blocked ? 'guard' : event.crit ? 'crit' : event.dot ? 'dot' : target === g.player ? 'dmg-in' : 'dmg-out';
      const amount = String(event.amount || 0);
      g.hud?.floater?.(target, event.miss ? 'Miss' : blocked ? `Block ${amount}` : amount, kind);
      if (!target.disposed && !target.dead && target !== g.player) {
        // A player flinches only on the host's DEFEAT row (event.defeat; absent = no reaction) and holds it for
        // that row's TimeLength, exactly as the victim's own controller does (src/game/hit-reaction.js); like the victim's
        // own skills.busy guard, a running NO_CANCEL skill of that player is not interrupted (remoteSkillBusy).
        if (target.kind === 'player') {
          const defeat = eventDefeat(event);
          if (defeat != null && !this.remoteSkillBusy?.(target)) { target._networkAnimHold = performance.now() + defeatSeconds(target, defeat) * 1000; target.play('hit', { variant: defeat, loop: false }); }
        } else if (!(target._networkAttackHold && (target._networkAnimHold || 0) > performance.now())) {
          // a monster mid-swing does not flinch, as offline (ai.js onDamaged: hit reaction only when not mid-swing)
          target._networkAnimHold = performance.now() + 250; target.play('hit', { loop: false });
        }
      }
      if (target === g.player) g.controller?.onDamaged?.(actor, event.amount, event);
      // Cosmetic event only; local damage/death listeners must not award trusted progression.
      g.events?.emit?.('server:damage', { source: actor, target, amount: event.amount,
        crit: !!event.crit, miss: !!event.miss, guard: !!(event.guard || event.block), dot: !!event.dot,
        skill: event.skillId != null ? { index: event.skillId } : null });
    }
    if (event.type === 'chat') {
      g.chat?.say?.(['party','shout','world','whisper'].includes(event.channel)?event.channel:'normal', event.name || actor?.name || 'Player', event.text,event.channel==='whisper'&&event.actorId===this.self?.id?{to:event.targetName}:{});
      if (actor&&event.channel!=='whisper') g.chat?.bubble?.(actor, event.text, ['party','shout'].includes(event.channel)?event.channel:'normal');
    }
    if (event.type === 'reward' && event.actorId === this.self.id && (Number(event.exp) || Number(event.dil))) {   // objects (siege stones / gates) give nothing
      // The game's own lines (string table 40:3 "Obtained EXP", 40:83 "Acquired DIL"). event.dil is only what the host really credited
      // (a monster's DIL lies on the ground as a pile and is announced when picked up), so no DIL number is shown for a kill that paid none.
      if (Number(event.exp)) g.chat?.system?.(`${str(40, 3) || 'Obtained EXP: ['} ${fmtInt(event.exp)} ]`, 'exp');
      if (Number(event.dil) > 0) g.chat?.system?.(dilPickupText(str(40, 83) || 'Acquired DIL: [ %lld DIL].', event.dil), 'item');
    }
    if ((event.type === 'loot' || event.type === 'petinventory') && event.actorId === this.self.id && Number(event.dil) > 0) {   // own (or own pet's) ground-DIL pickup, amount = what the bag gained
      g.chat?.system?.(dilPickupText(str(40, 83) || 'Acquired DIL: [ %lld DIL].', event.dil), 'item');
    }
    if ((event.type === 'loot' || event.type === 'petinventory') && event.actorId === this.self.id && event.item?.name) {   // own item pickup: string 40:42, as the offline HUD 'loot' line
      g.chat?.system?.(itemPickupText(plainMarkup(str(40, 42) || '[Message] <NAME> has acquired <VALUE>.').replace('<NAME>', g.player?.name || this.self.name || ''), event.item.name, event.item.count, event.item.grade), 'item');
    }
    if (event.type === 'pk') {   // FIELD-PK notices (stringtable_pc 1003), only for the two players they name
      const note = pkNotice(event, this.self.id, id => byId(id)?.name || this.players.get(id)?.name || '', code => str(1003, code) || null);
      if (note) g.chat?.system?.(note.text, note.kind);
    }
    if (event.type === 'levelup' && actor && Number.isInteger(event.level) && event.level > 0) {
      // Local progression listeners also update HUD/audio/quests/skills. A
      // remote player's gain gets only its actor-owned native visual effect.
      if(event.actorId===this.self?.id&&actor===g.player)g.events?.emit?.('levelup',{level:event.level,actor,server:true});
      else if(this.players.get(event.actorId)===actor&&!actor.disposed)g.events?.emit?.('remote:levelup',{level:event.level,actor,server:true});
    }
    if(event.type==='quest' && event.actorId===this.self.id && ['quest:accept','quest:complete','quest:abandon'].includes(event.kind)) g.events?.emit?.(event.kind,{id:event.questId,server:true});
    if(event.type==='box' && event.actorId===this.self.id) {
      for(const entry of event.got || []) g.hud?.log?.(`${g.items?.db?.def(entry.item)?.name || `Item ${entry.item}`} ${entry.count}x obtained.`,'item');
      // Accepted, sequence-deduped own box event. Only authored item-use cues
      // play; this is separate from local BoxSystem's existing itemUse call.
      g.audio?.itemUse?.({itemIndex:event.itemIndex});
      g.events?.emit?.('box:open',{item:event.itemIndex,got:event.got,server:true});
    }
  }
  _clearActors() {
    this._generation++; this._loads = [];this._signalVisuals();
    for (const actor of this.actors()) actor.dispose();
    this.players.clear(); this.monsters.clear(); this.servants.clear();
    this.servantSnapshot?.([]);
    this._actorMap = null;
  }
  /** MOVE-NO-RUBBERBAND per-frame upkeep: re-send a lost stop report, and pin the host pose with a final report
   *  when a click-move or chase reached its goal (the last periodic report was sent before arrival). */
  syncMaintenance() {
    if (!this.ready || !this.game.player) return;
    if (syncNeedsResync(this)) { void syncTrack(this, this.action('stop', movementReport(this))); return; }
    if (syncArrived(this)) { const p = this.game.player; moveSyncState(this).moving = false; this._lastMove = null; void syncTrack(this, this.action('move', { x: p.x, z: p.z, ...movementReport(this) })); }
  }
  update(dt) {
    if (!this.active || this.disposed) return;
    const now = Date.now();
    if(this.ready&&this.token&&this.game._launcherReadiness?.condition()&&!this._toolPolling&&now>=(this._toolPollAt||0)){
      this._toolPollAt=now+1000;this._toolPolling=true;const lease=this.token;
      void this._request('launcher-tools?token='+encodeURIComponent(lease)).then(async result=>{
        if(this.disposed||this.token!==lease||!this.game._launcherReadiness?.condition())return;
        for(const command of result.commands||[])try{await openBuilder(this.game,command.tool);}catch(error){this.game.chat?.system?.(error.message,'err');}
      }).catch(()=>{}).finally(()=>{this._toolPolling=false;});
    }
    if (!this._fatal && now >= this._pollAt && (!this.stream || !this._streamAt || now - this._streamAt > 2500)) {
      this._pollAt = now + (this.transport === 'polling' && this.ready ? MOVEMENT_SYNC.POLL_INTERVAL_MS : 500);
      if (this.token) void this.poll(); else void this.join();
    }
    this.syncMaintenance();
    if (this.game.player && this.self && Number(this.game.world?.info?.index) === Number(this.self.map)) advanceServerPose(this.game.player);
    for (const actor of this.actors()) {
      try { actor.update(dt); }
      catch {
        // ENGINE-CHOSEN: isolate visual update failures; retry on later frames without dropping the authoritative actor.
        const seen = (this._actorUpdateErrors ||= new WeakSet());
        if (!seen.has(actor)) {
          seen.add(actor);
          console.error('[network] remote actor update failed; other actors kept running');
        }
      }
    }
    this._paintStatus?.();
  }
  leave({ keepalive = false } = {}) {
    if (this._leaving) return this._leaving;
    this.game._launcherReadiness?.dispose({keepalive});
    this.disposed = true; this.ready = false; this._cancelInitialJoin();this._preparationWait?.();this.stream?.close(); this._clearActors();
    this._simulationPopulationView=null;
    this._rttMeter?.dispose();
    if (this.active) this.game.accountPermissions = { role: 'player', capabilities: [] };
    this._offMap?.(); globalThis.removeEventListener?.('pagehide', this._pagehide);
    this._statusPanel?.remove();
    const token = this.token; this.token = null;
    this._leaving = token ? this._request('leave', { token }, keepalive).then(() => true, () => false) : Promise.resolve(true);
    return this._leaving;
  }
  dispose() { this.game.input?.canvas?.removeEventListener?.('inputrelease', this._inputRelease); return this.leave({ keepalive: true }); }
}
