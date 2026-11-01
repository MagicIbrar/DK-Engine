// Map zones: the .mac cell attributes (share/mapredcell/*.mac -> share/arrange/cell.csv, docs/formats/mac.md) and the
// maplist map flags (docs/formats/dungeons.md maps[m].flags), as one query API for every system:
//
//   game.zones.at(x, z)   -> { attr, safety, noPk, noSkill, tutorial, border, summon, fishing, blocked }
//   game.zones.current    -> the zone under the player (updated 5x/s), game.zones.flags -> the map flags
//   game.zones.canUseSkill() / canMount() / canSummonPet() / canPvP() / canReturnScroll() / canPortal() / revivalHere()
//   'zone' event {prev, cur} when the player crosses into another attribute (safety zone, NOT_USESKILL, ...)
//
// Cell values (cell.csv): 4 no-PK, 5 SAFETY (PvP lobbies / siege bases), 6 NOT_USESKILL, 7 TUTORIAL (Ardeca),
// 8 BORDER, 9 SUMMON_ENABLE (random monster summoning allowed: the walkable part of PvP fields), 100-310 fishing water.
// Enforcement done here: skills are refused on NOT_USESKILL cells (the skill system's use() is wrapped); mounts, pets
// and PvP ask these functions (their messages: stringtable_vehicle 25, stringtable_petui 208, stringtable_pc 822).
import { mapInfo, D } from './data.js';

export const MSG = {
  noSkill: '[message] You cannot use skill.',                         // stringtable_dungeon_22
  noMount: 'You cannot use the mount in this area.',                   // stringtable_vehicle
  noPet: 'You cannot summon a pet on this map.',                       // stringtable_petui
  noPvp: '[Message] You cannot PvP while in the Safety Zones.',        // stringtable_pc
};

export class Zones {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.current = null;
    this.flags = {};
    this._t = 0;
  }

  install() {
    const z = this;
    // the core EXP band table as loaded (the maps' own tables replace it while the player is on them)
    this._defaultLD = this.game.data?.exp?.levelDifference;
    this._capCache = new Map();
    this.sys.levelCaps = (key) => {
      if (!key) return null;
      if (!this._capCache.has(key)) {
        const t = D.dg?.levelCaps?.[key];
        this._capCache.set(key, Array.isArray(t) && t.length
          ? t.map((r, i) => ({ index: i + 1, diffFrom: r[0], diffTo: r[1], expRate: r[2], chaoticRate: r[3], blocking: r[4], blocked: r[5], color: r[6] }))
          : null);
      }
      return this._capCache.get(key);
    };
    this.game.zones = {
      at: (x, zz) => z.at(x, zz),
      get current() { return z.current; },
      get flags() { return z.flags; },
      canUseSkill: () => z.canUseSkill(),
      canMount: () => z.canMount(),
      canSummonPet: () => z.canSummonPet(),
      canPvP: () => z.canPvP(),
      canReturnScroll: () => z.flags.returnScroll !== 0,
      canPortal: () => !!z.flags.portal,
      revivalHere: () => !!z.flags.revivalCheck,
      isSafe: () => !!(z.current?.safety || z.flags.peace),
      MSG,
    };
    this._wrapSkills();
  }

  onMap(index) {
    const row = this.game.mapRow?.(index) || this.game.data?.mapByIndex?.(index) || {};
    const info = mapInfo(index);
    const n = (k) => Number(row[k]) || 0;
    this.flags = info?.flags ? { ...info.flags } : {
      portal: n('IsPortal'), pvp: n('IsPvP'), siege: n('IsSiege'), returnScroll: row.IsReturnScroll == null ? 1 : n('IsReturnScroll'),
      isReturn: n('IsReturn'), noChaoGain: n('IsNotIncreaseChao'), vehicle: row.IsVehicle == null ? 1 : n('IsVehicle'),
      pet: row.IsPet == null ? 1 : n('IsPet'), peace: n('PeaceZone'), pvpPeace: n('PVP_PeaceZone'), revivalCheck: n('PCRevivalChack'),
    };
    this.flags.map = Number(index);
    this.current = null;
    this._t = 0;
    this._levelCap(index);
  }

  /**
   * EXP by level difference of this map (maplist StrLevelCapPath -> share/pc/levelcap/*.csv, dungeons.json
   * levelCaps): instances and special fields have their own bands (Tower of Spell, Mitera, Sacred Claw ...).
   * Maps on default.csv keep the core table (exp.json). Event maps are left to the events system, which swaps the
   * same table while its run is up (it runs first, on the 'map' event; this runs once the map has loaded).
   */
  _levelCap(index) {
    const exp = this.game.data?.exp;
    if (!exp) return;
    if (this._defaultLD === undefined) this._defaultLD = exp.levelDifference;
    if (this.game.eventsSystem?.ownsMap?.(index)) return;
    const key = mapInfo(index)?.levelCap || mapInfo(index)?.files?.levelCap || '';
    const rows = !/\/default\.csv$/i.test(key) ? this.sys.levelCaps?.(key) : null;
    exp.levelDifference = rows || this._defaultLD;
    this.levelCap = rows ? key : null;
  }

  /** Attribute of a FILE-frame point. */
  at(x, z) {
    const w = this.game.world;
    const attr = w?.collision?.attrAt ? w.collision.attrAt(x, z) : 0;
    const info = w?.cellInfo ? w.cellInfo(x, z) : null;
    return {
      attr,
      safety: attr === 5,
      noPk: attr === 4,
      noSkill: attr === 6 || attr === 3,
      tutorial: attr === 7,
      border: attr === 8,
      summon: attr === 9,
      fishing: !!info?.fishing,
      blocked: !!info?.blocked,
      remoteOnly: attr === 1000,
      desc: info?.desc || info?.attribute || '',
    };
  }

  canUseSkill() { return !this.current?.noSkill; }
  canMount() { return this.flags.vehicle !== 0; }
  canSummonPet() { return this.flags.pet !== 0; }
  canPvP() { return !!this.flags.pvp && !this.current?.safety && !this.current?.noPk && !this.flags.peace; }

  _wrapSkills() {
    const sk = this.game.skills;
    if (!sk || sk._zoneWrapped) return;
    sk._zoneWrapped = true;
    const self = this;
    for (const fn of ['use', 'useSkill', 'useSlot']) {
      const orig = sk[fn];
      if (typeof orig !== 'function') continue;
      sk[fn] = function zoneChecked(...args) {
        if (!self.canUseSkill()) { self.game.hud?.log?.(MSG.noSkill, 'err'); return false; }
        return orig.apply(this, args);
      };
    }
  }

  update(dt) {
    this._t -= dt;
    if (this._t > 0) return;
    this._t = 0.2;
    const p = this.game.player;
    if (!p || !this.game.world) return;
    const cur = this.at(p.x, p.z);
    const prev = this.current;
    this.current = cur;
    if (!prev || prev.attr !== cur.attr) this.game.events?.emit?.('zone', { prev, cur, flags: this.flags });
  }
}
