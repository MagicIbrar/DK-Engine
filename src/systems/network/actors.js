import { Player } from '../../actors/player.js';
import { Monster } from '../../actors/monster.js';
import { Actor } from '../../actors/actor.js';
import { Servant } from '../skills/summons.js';
import { SkillData } from '../skills/data.js';
import { remoteAppearance } from './appearance.js';
import { RemoteMotion, remoteLocomotionState, placeRemote } from './movement-sync.js';

export function setServerPose(actor, row, now = performance.now(), preservePosition=false, poseTime=null) {
  if (!Number.isFinite(row.x) || !Number.isFinite(row.z)) return;
  if(Number.isFinite(Number(row.map)))actor._serverScene={map:Number(row.map),instanceId:row.instanceId||null,channel:row.channel??0};
  if(actor.kind==='monster'){actor.renewGuard=row.renewGuard===true;actor.guardGuild=actor.renewGuard?row.guardGuild||null:null;}
  // MOVE-NO-RUBBERBAND: a client-predicted remote player (row.pt = host pose time) renders from a time-stamped
  // buffer (RemotePlayer.update) instead of re-targeted 200ms tweens, so delivery jitter never shows as stutter.
  // Monsters and summons (no row.pt) used the
  // 200 ms tween re-aimed at every snapshot (speed saw-toothed with every arrival, stalls on late ones). They now use the
  // same buffer, stamped with the host tick that produced the position (snapshot.tickAt, poseTime from _reconcile).
  const clock = actor.game?.network?._motionClock;
  const remotePlayer = actor.remote && actor.kind === 'player' && actor !== actor.game?.player && Number.isFinite(row.pt) && clock;
  const remoteOther = actor.remote && actor.kind !== 'player' && Number.isFinite(poseTime) && clock && !globalThis.__dekaronLegacyMonsterTween;   // kill switch / A-B measurement (test client)
  const buffered = remotePlayer || remoteOther;
  if (buffered) {
    const motion = (actor._motion ||= new RemoteMotion());
    let pose = row;
    if (remoteOther) {
      const last = motion.samples.at(-1), moved = !!last && Math.hypot(row.x - last.x, row.z - last.z) > 1e-4;
      pose = { pt: poseTime, x: row.x, z: row.z, moving: moved };
      // standing still on consecutive ticks adds nothing (the buffer keeps showing its last pose)
      if (last && !last.moving && !moved && poseTime > motion.lastPt) pose = null;
    }
    if (pose) motion.push(pose, clock.now(now), actor._serverPose ? actor : null);
    if (!actor._serverPose) actor.setPosition(row.x, row.z);
  }
  else if (actor._motion && actor.remote) actor._motion = null;
  if (!buffered && !preservePosition&&(!actor._serverPose || Math.hypot(row.x - actor.x, row.z - actor.z) > 10)) actor.setPosition(row.x, row.z);
  actor._serverPose = { x: actor.x, z: actor.z, tx: row.x, tz: row.z, at: now, duration: 200 };
  actor._serverYaw = Number.isFinite(row.yaw) ? row.yaw : null;
  if (actor._serverYaw != null) actor._yawGoal = actor._serverYaw;
  actor._serverWalk = row.walk === 'peace' || row.walk === 'battle';   // R walk: the host moves it at the walk stride
  // sitting (server/world/emotes.mjs): a player seen sitting keeps the sit loop; standing up releases the hold
  if (actor.kind === 'player' && actor !== actor.game?.player && !!row.sitting !== !!actor._remoteSit) {
    if (row.sitting) actor.game?.life?.emotes?.playRemote?.(actor, 'sit-keep');
    else { actor._remoteSit = false; if (actor._networkAnimHold === Infinity) actor._networkAnimHold = 0; }
  }
  const dead = !!row.dead || row.hp <= 0, wasDead = actor.dead;
  actor.hp = Math.max(0, Number(row.hp) || 0); actor.maxHp = Math.max(1, Number(row.maxHp) || 1);
  if(Number.isFinite(row.mp))actor.mp=Math.max(0,row.mp);
  if(Number.isFinite(row.maxMp))actor.maxMp=Math.max(0,row.maxMp);
  if(Number.isFinite(row.fury))actor.fury=Math.max(0,row.fury);   // Half Bagi fury gauge: the host owns it (server/world/fury.mjs); only the owner's own row carries it
  if(Number.isFinite(row.shield))actor.shield=Math.max(0,row.shield);
  if(Number.isFinite(row.maxShield))actor.maxShield=Math.max(0,row.maxShield);
  if (typeof row.name === 'string') { actor.name = row.name; if (actor.save) actor.save.name = row.name; }
  if(actor.kind==='player'){actor.nameplate=row.nameplate||null;actor.nameColor=row.nameplate?.nameColor||(row.nameplate?.wanted?('wanted'+row.nameplate.wanted):(row.nameColor||'white'));if(actor.save)actor.save.nameColor=actor.nameColor;}
  actor.level = Number(row.level) || actor.level;
  actor.dead = dead;
  if (dead && !wasDead) actor.play('die', { loop: false });
  else if (!dead && wasDead) { actor.faded = false; actor.setOpacity(1); actor.play('idleCombat'); }
}

export function advanceServerPose(actor, now = performance.now()) {
  const p = actor._serverPose;
  if (!p) return;
  const u = Math.max(0, Math.min(1, (now - p.at) / p.duration));
  const x = p.x + (p.tx - p.x) * u, z = p.z + (p.tz - p.z) * u;
  const moving = Math.hypot(x - actor.x, z - actor.z) > 0.001;
  if (!actor.dead && moving && !Number.isFinite(actor._serverYaw)) actor.faceTowards(p.tx, p.tz);
  placeRemote(actor, x, z);
  const ownCombo = actor === actor.game?.player && actor.game?.controller?.combo;
  const ownController = actor === actor.game?.player && actor.game?.controller;
  // a monster's swing hold (client.js 'attack', the clip's TimeLength) ends as soon as the host moves it again
  if (moving && actor._networkAttackHold) { actor._networkAttackHold = false; actor._networkAnimHold = 0; }
  // Local input controls locomotion animation. A small server correction after release
  // must not restart running; remote actors still derive motion from authoritative poses.
  if (!actor.dead && !ownController && !ownCombo && (actor._networkAnimHold || 0) <= now) {
    // (a late host pose leaves the body standing for a frame or two: remoteLocomotionState keeps its stride through that)
    const state = remoteLocomotionState(actor, moving, actor._serverWalk, now, actor.kind === 'player' ? 'idleCombat' : 'idle');
    if (actor.state !== state) actor.play(state);
  }
}

// What a remote player's body depends on: the published worn items and the viewer's own "Display Costume Look"
// (Options - View, settings.showCostume), so toggling the option re-builds the players it changes.
const remoteLookSignature=(game,row)=>JSON.stringify([row.appearance||[],game?.settings?.showCostume!==false]);

export class RemotePlayer extends Player {
  constructor(game, row) {
    const cls = game.data.classByIndex?.get(Number(row.classIndex)) || game.data.classes?.find(c => Number(c.index) === Number(row.classIndex)) || game.classDef;
    const visual=remoteAppearance(game,row,cls);
    super(game, visual.save, visual.classDef);
    this._appearanceSignature=remoteLookSignature(game,row);
    this.networkId = row.id; this.remote = true; this.cullable = true;
  }
  // Remote server motion, rather than the local controller, determines its stride speed.
  _nominalSpeed() { return 0; }
  setAppearance(row){
    const signature=remoteLookSignature(this.game,row);
    const same=signature===this._appearanceSignature;
    if(same&&(!this._appearanceFailed||(this._appearanceAttempts||0)>=3||performance.now()<(this._appearanceRetryAt||0)))return false;
    if(!same){this._appearanceRevision=(this._appearanceRevision||0)+1;this._appearanceAttempts=0;}
    this._appearanceFailed=false;
    this._appearanceSignature=signature;
    const visual=remoteAppearance(this.game,row,this.classDef?._base||this.classDef);
    this.save=visual.save;this.classDef=visual.classDef;
    return true;
  }
  // ENGINE-CHOSEN remote visuals only: at most three attempts for an unchanged canonical look.
  // Initial failure waits 1s, second failure 2s; a genuine changed row starts a new budget.
  async _appearanceWork(initial) {
    const revision=this._appearanceRevision||0;
    const attempt=this._appearanceAttempts=(this._appearanceAttempts||0)+1;
    let ok=false;
    try {
      const result=await (initial?super._load():super.refreshAppearance());
      ok=initial?!!this.model:result===true;
      return result;
    } finally {
      if(!this.disposed&&revision===(this._appearanceRevision||0)){
        this._appearanceFailed=!ok;
        this._appearanceRetryAt=ok?0:performance.now()+(attempt===1?1000:2000);
      }
    }
  }
  _load(){return this._appearanceWork(true);}
  refreshAppearance(){return this._appearanceWork(false);}
  update(dt) {
    const now = performance.now(), clock = this.game?.network?._motionClock;
    if (!(this._motion && clock && this._motion.apply(this, clock.now(now), now))) advanceServerPose(this);
    super.update(dt);
  }
}

export class RemoteMonster extends Monster {
  constructor(game, row) {
    const def = game.data.monsters?.monsters?.[row.monsterIndex] || { index: row.monsterIndex, name: row.name, hp: row.maxHp };
    super(game, def, { monsterIndex: row.monsterIndex, x: row.x, z: row.z });
    this.networkId = row.id; this.remote = true; this.brain = null;
  }
  update(dt) { advanceRemoteActor(this, 'idle'); super.update(dt); }
}
// Servant rows (shape mesh / texture pack / skeleton / clips: share/creature/servant.csv, docs/formats/skills.md section 9) are compiled only
// into the SUMMONER classes' skill packs (gamedata/skills/class_3.json Vicious Summoner, class_10.json Conserra Summoner); the SkillData
// of every other class has none. A player of any other class who saw a summoner's servant therefore built the actor from
// {index, name} alone: no model, only the floating name plate.
// The row is now fetched from the owner's summoner class pack on demand (same cached fetchJSON the remote skill playback uses).
const SUMMONER_CLASSES = [3, 10];
const servantPacks = new Map();
/** (tests) forget the fetched class packs. */
export function resetServantPackCache() { servantPacks.clear(); }
function servantPack(classIndex) {
  let pack = servantPacks.get(classIndex);
  if (!pack) { pack = Promise.resolve(SkillData.classPack(classIndex)).catch(error => { servantPacks.delete(classIndex); throw error; }); servantPacks.set(classIndex, pack); }
  return pack;
}
/** The servant row for a published summon: this client's own pack first, else the owner's (summoner) class pack. null = unknown.
 *  ENGINE-CHOSEN (network robustness, no game data involved): a failed pack fetch is retried `tries` = 3 times with a 400 ms, 800 ms back-off. */
export async function resolveServantDef(game, { servantIndex, ownerId }, { tries = 3, wait = ms => new Promise(resolve => setTimeout(resolve, ms)) } = {}) {
  const own = game.skills?.data?.servant?.(servantIndex);
  if (own) return own;
  const ownerClass = Number(game.network?.players?.get?.(ownerId)?.save?.classIndex);
  const order = [ownerClass, ...SUMMONER_CLASSES].filter((c, i, list) => SUMMONER_CLASSES.includes(c) && list.indexOf(c) === i);
  for (let attempt = 0; attempt < tries; attempt++) {
    let failed = false;
    for (const classIndex of order) {
      try {
        const pack = await servantPack(classIndex), def = pack?.servants?.[servantIndex];
        if (def) {
          // The observer may not have this class's status scene (e.g. Gigantes 100:1295).
          const data = game.skills?.data, ref = def.statusEffect;
          const key = ref ? `${ref.cate ?? 100}:${ref.id}` : null;
          const scene = key && pack.effects?.scenes?.[key];
          if (scene && data?.scenes instanceof Map && data?.units instanceof Map) {
            if (!data.scenes.has(key)) data.scenes.set(key, scene);
            for (const unit of Object.values(scene.res || {}))
              if (typeof unit === 'string' && !data.units.has(unit) && pack.effects?.units?.[unit]) data.units.set(unit, pack.effects.units[unit]);
          }
          return def;
        }
      }
      catch (error) { failed = true; console.warn('[network] servant pack', classIndex, error); }
    }
    if (!failed) return null;                       // every pack answered and none lists this servant: unknown, not a transient failure
    await wait(400 * 2 ** attempt);
  }
  return null;
}
export class RemoteServant extends Servant {
  constructor(game,row){
    const known=game.skills?.data?.servant?.(row.servantIndex)||null;
    super(game,known||{index:row.servantIndex,name:row.name},null,game.skills?.summons);this.networkId=row.id;this.remote=true;this.cullable=true;
    this.ownerId=row.ownerId;this._defPending=!known;
  }
  async _load(){
    if(this._defPending){
      const def=await resolveServantDef(this.game,{servantIndex:this.servantIndex,ownerId:this.ownerId});
      if(this.disposed)return;
      if(def){this._applyDef(def);this._defPending=false;}
      else console.warn('[network] servant has no model data (no summoner pack lists it)',this.servantIndex,this.name);
    }
    await super._load();
    if (!this.disposed) { this._statusReady = true; this._statusRetry = .5; this.startStatusEffect(); }
  }
  update(dt){
    advanceRemoteActor(this,'idle');Actor.prototype.update.call(this,dt);
    this.updateEffects(dt);
    // A distant observer can load the body outside the effect player's spawn range.
    // Retry a missing persistent effect at most twice per second after the body is ready.
    if(this._statusReady&&!this.disposed&&(!this._statusFx||this._statusFx.done)){
      this._statusRetry=Math.max(0,(this._statusRetry||0)-Math.max(0,Number(dt)||0));
      if(!this._statusRetry){this._statusRetry=.5;this.startStatusEffect();}
    }
  }
}
/** A remote monster / summon: its time-stamped buffer when it has one (setServerPose), else the legacy tween. */
function advanceRemoteActor(actor, rest) {
  const now = performance.now(), clock = actor.game?.network?._motionClock;
  if (!(actor._motion && clock && actor._motion.apply(actor, clock.now(now), now, rest))) advanceServerPose(actor);
}
