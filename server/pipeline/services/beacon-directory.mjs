// LINK + BEACON directory (Phase B step 3, docs/SERVER-SPLIT-DESIGN.md): who is online, and on which map / channel.
// Pure data structure, no I/O, so it is unit-testable and the worker (beacon.mjs) stays a thin bus wrapper.
// Fed by Realm's presence table (server/pipeline/presence-feed.mjs): rows = [id, account, characterId, name, map, channel, instanced].
// Read-only for every other service: nothing here can change the game; Realm stays the authority.
export function createDirectory() {
  let byId = new Map(), byName = new Map(), byAccount = new Map(), at = 0, revision = 0, updates = 0;
  const norm = v => String(v ?? '').trim().toLowerCase();
  const view = r => ({ online: true, characterId: r.characterId, name: r.name, map: r.map, channel: r.channel, instanced: r.instanced });
  return {
    /** Replace the whole table (Realm sends full tables on the coalesced STATE lane, so a lost message never leaves a hole). */
    load(table) {
      if (!table || !Array.isArray(table.rows)) return false;
      if (Number.isFinite(table.revision) && table.revision < revision) return false;   // stale (out-of-order) table
      const ids = new Map(), names = new Map(), accts = new Map();
      for (const row of table.rows) {
        if (!Array.isArray(row) || row.length < 7) continue;
        const [id, account, characterId, name, map, channel, instanced] = row;
        const r = { id: String(id), account: String(account ?? ''), characterId: String(characterId ?? ''), name: String(name ?? ''), map: Number(map) || 0, channel: Number(channel) || 0, instanced: instanced === 1 || instanced === true };
        ids.set(r.id, r); if (r.name && !names.has(norm(r.name))) names.set(norm(r.name), r);
        if (r.account) { const list = accts.get(r.account) || []; list.push(r); accts.set(r.account, list); }
      }
      byId = ids; byName = names; byAccount = accts; at = Number(table.at) || Date.now(); revision = Number(table.revision) || revision; updates++;
      return true;
    },
    where({ name, characterId } = {}) {
      let r = null;
      if (characterId != null) { for (const row of byId.values()) if (row.characterId === String(characterId)) { r = row; break; } }
      else if (name != null) r = byName.get(norm(name)) || null;
      return r ? view(r) : { online: false };
    },
    account({ account } = {}) { const list = byAccount.get(String(account ?? '')) || []; return { online: list.length > 0, characters: list.map(view) }; },
    /** Population per channel and map (counts only: no names leave the directory in bulk). */
    population() {
      const channels = {};
      for (const r of byId.values()) { const c = channels[r.channel] ||= { players: 0, maps: {} }; c.players++; c.maps[r.map] = (c.maps[r.map] || 0) + 1; }
      return { at, players: byId.size, channels };
    },
    count() { return byId.size; },
    stats() { return { players: byId.size, accounts: byAccount.size, updates, revision, ageMs: at ? Date.now() - at : null }; },
  };
}
