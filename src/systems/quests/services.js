// NPC service menu entries (the non-quest lines of the NPC dialog: shop, stash, teleport, return point, ...).
// Other systems register the services they own:
//   game.npcServices.register(key, handler)
//     key     = JobType number (0 shop, 2 teleport, 3 storage, 4 return, 5 skill master, 6 repair, 11 upgrade, ...)
//               or the npcs.json jobTypes role name ('SHOP', 'STORAGE', 'TELEPORT', ...)
//     handler = (npcActor, {jobType, jobIndex, role, label, npcIndex}) => truthy when handled.
//               Return 'keep' to keep the NPC dialog open (e.g. a sub-page), anything else truthy closes it.
// Unregistered services fall back to: game.events 'npc:service' listeners ({..., handled:false} -> set handled),
// a uiwin window registered under the role name in lower case ('shop', 'storage', 'teleport', ...), the core
// windows (TELEPORT/PORTAL -> world map, SKILLMASTER -> skills), the RETURN point, and finally the original
// "cannot use" line.

const SHOPISH = /SHOP|EXCHANGE|STORE/;

export class NpcServices {
  constructor(game) {
    this.game = game;
    this.handlers = new Map();   // key (number | UPPER role) -> [handler]
  }

  register(key, handler) {
    const k = typeof key === 'number' || /^\d+$/.test(String(key)) ? Number(key) : String(key).toUpperCase();
    if (!this.handlers.has(k)) this.handlers.set(k, []);
    this.handlers.get(k).push(handler);
    return () => this.unregister(k, handler);
  }
  unregister(key, handler) {
    const list = this.handlers.get(key);
    if (list) this.handlers.set(key, list.filter(h => h !== handler));
  }
  /** One function running every handler of a key (compatibility with registries that chain a previous handler). */
  get(key) {
    const k = typeof key === 'number' || /^\d+$/.test(String(key)) ? Number(key) : String(key).toUpperCase();
    const list = this.handlers.get(k);
    if (!list?.length) return null;
    return (npc, info) => { for (const h of list) { const r = h(npc, info); if (r) return r; } return false; };
  }
  /** Take over the handlers of a registry another system created before this one was installed. */
  adopt(other) {
    if (!other || other === this) return;
    const src = other.handlers instanceof Map ? other.handlers : null;
    if (src) for (const [k, v] of src) for (const fn of Array.isArray(v) ? v : [v]) if (typeof fn === 'function') this.register(k, fn);
    for (const p of other.providers || []) if (typeof p === 'function') this.provide(p);
  }
  /**
   * Extra menu lines a system adds for an NPC that its original job list cannot express (shared-play services such as
   * the owner-directed Zuto registration): provider(npcIndex) -> [{role, label, jobIndex?}]. Dispatch uses the role.
   */
  provide(provider) {
    (this.providers ||= []).push(provider);
    return () => { this.providers = (this.providers || []).filter(p => p !== provider); };
  }
  extraEntries(n) {
    const out = [];
    for (const p of this.providers || []) {
      try { for (const e of p(n) || []) if (e?.role && e?.label) out.push(e); } catch (err) { console.error('[npc] entry provider', err); }
    }
    return out;
  }
  has(jobType, role) {
    return !!(this.handlers.get(Number(jobType))?.length || this.handlers.get(String(role || '').toUpperCase())?.length);
  }

  roleOf(jobType) { return this.game.data?.npcs?.jobTypes?.[jobType]?.name || null; }
  isShop(jobType) { return SHOPISH.test(this.roleOf(jobType) || ''); }

  /**
   * Run a service. Returns 'keep' (dialog stays), true (handled: close the dialog) or false (not available).
   */
  dispatch(npc, entry) {
    const g = this.game;
    const role = entry.role || this.roleOf(entry.jobType);
    const info = { jobType: entry.jobType, jobIndex: entry.jobIndex, role, label: entry.label, npcIndex: npc?.npcIndex ?? npc?.index };
    for (const k of [Number(entry.jobType), String(role || '').toUpperCase()]) {
      for (const h of this.handlers.get(k) || []) {
        try { const r = h(npc, info); if (r) return r === 'keep' ? 'keep' : true; } catch (err) { console.error('[npc] service handler', role, err); }
      }
    }
    const ev = { npc, ...info, handled: false };
    g.events?.emit?.('npc:service', ev);
    if (ev.handled) return ev.handled === 'keep' ? 'keep' : true;
    // a window registered under the role name
    const wname = String(role || '').toLowerCase();
    const W = g.uiwin;
    if (wname && W?.has?.(wname)) { W.open(wname, { npc, ...info }); return true; }
    switch (role) {
      case 'TELEPORT': case 'PORTAL': case 'SIEGE_TELEPORT': case 'SKY_TELEPORT':
        if (W?.has?.('teleport')) { W.open('teleport', { npc, ...info }); return true; }
        g.windows?.open?.('map'); return true;
      case 'SKILLMASTER': case 'SKILL_UPGRADE':
        g.windows?.open?.('skills'); return true;
      // boards and changers whose original window no system registers yet: open that window (honestly empty lists)
      case 'GUILD_ADVERTISE_LIST': return this._openScript('npc_guildpublicity', 'game2/guild/ui_guildrequestjoinwnd.txt', npc, info);
      case 'DECLARE_WAR': return this._openScript('npc_guildwarboard', 'game2/guildwar/ui_guildwarboardwnd.txt', npc, info);
      case 'CHANGESHAPE_JOB': return this._openScript('npc_changeshape', 'game2/changeshapewnd/changeshapewnd.txt', npc, info, (w) => w.control('btn_change').setEnabled(false));
      // guild services: the guild window when the character has a guild, else the server's "You are not in a guild."
      case 'DISBANDGUILD': case 'GUILDMARK': case 'DELETEGUILDMARK': case 'GUILD_LEVELUP': case 'GUILD_NAMECHANGE':
      case 'ALLIANCE_MARK': case 'DELETEALLIANCEMARK': case 'GUILD_DELIVER': case 'GUILD_ADVERTISE_APPLICATION': {
        const inGuild = !!(g.guild?.name || g.save?.guild || g.network?.guild?.founded);
        if (inGuild && role === 'GUILD_ADVERTISE_APPLICATION') return this._openScript('npc_guildpublicitymanage', 'game2/guild/ui_guildmanagejoinwnd.txt', npc, info);
        // Guild mark registration/deletion: the shared server guild's original mark windows.
        if (inGuild && role === 'GUILDMARK' && g.life?.guild?._markSelect) { void g.life.guild._markSelect(); return true; }
        if (inGuild && role === 'DELETEGUILDMARK' && g.life?.guild?._markDelete) { void g.life.guild._markDelete(); return true; }
        if (inGuild && role === 'GUILD_LEVELUP' && g.life?.guild?._levelUp) { void g.life.guild._levelUp(); return true; }
        if (inGuild && W?.has?.('guild')) { W.open('guild', { npc, ...info }); return true; }
        const t = String(W?.strings?.get?.({ group: 'NORMAL', cate: 130, code: 23 }) || 'You are not in a guild.').replace(/<[^>]+>/g, '').trim();
        try { g.hud?.log?.(t, 'err'); } catch { /* chat unavailable */ }
        W?.msgbox?.(t, { kind: 'ok' });
        return 'keep';
      }
      case 'RETURN': {
        const p = g.player;
        if (g.save && p && g.world) {
          g.save.returnPoint = { map: g.world.info.index, x: +p.x.toFixed(2), z: +p.z.toFixed(2) };
          // messagebox 81:87 "<center> %s has been set as the return point."
          const t = g.uiwin?.strings?.get({ group: 'NORMAL', cate: 81, code: 87 }) || '%s has been set as the return point.';
          const name = String(g.world.info.row?.Name || g.world.info.name || '').trim();
          const text = t.replace('%s', name).replace(/<center>/g, '').trim();
          try { g.hud?.log?.(text, 'sys'); } catch { /* chat unavailable */ }
          g.uiwin?.msgbox?.(text, { kind: 'ok' });
        }
        return true;
      }
      default: break;
    }
    return false;
  }

  /** Register (once) and open an original window script for an NPC service no system owns yet. */
  _openScript(name, script, npc, info, create = null) {
    const W = this.game.uiwin;
    if (!W?.registerWindow) return false;
    if (!W.has?.(name)) W.registerWindow(name, { script, create: (w) => { try { create?.(w); } catch (err) { console.error('[npc]', name, err); } } });
    W.open(name, { npc, ...info });
    return true;
  }
}
