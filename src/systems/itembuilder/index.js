// Item builder system: registers the item builder window (window.js/layout.js draws it, preview.js renders the
// live 3D preview) and exposes the custom item library (registry.js) as game state. Custom items are already real
// items of the items database by the time this installs (items/db.js's ItemDB.load applies the stored library
// before any save is read), so this system only needs to add: the window + hotkey (Ctrl+B), a chat command, and a
// small API other code (a future GM panel, quests, shops, ...) can use to list / spawn / edit them.
//
// Public API: game.customItems = {
//   list()                         every saved custom item record (registry.js record shape: look/shape inlined)
//   get(index)                     one record, or null
//   save(record, editingIndex?)    normalise + apply to the database + persist; returns the saved record
//   remove(index)                  delete it (db + library) and every copy the character owns; returns copies removed
//   spawn(index, count?, {equip})  create instance(s) into the inventory, optionally equip one; {ok, inst, placed, equipped}
//   exportFile(indices?)           download the library (or a subset) as a .json file
//   importFile()                   file picker -> merge a library export into this one
//   openBuilder(arg?)              open the window ({index} to edit, {clone} to clone an item, nothing = last draft)
//   isCustom(index)                registry.js isCustomIndex
// }
// Chat: /itembuilder [open | new | <item index>] (an item index opens/edits it if it is one of ours, else clones
// it). Hotkey: Ctrl+B (registered by window.js's registerWindow call).
import { BuilderWindow } from './window.js';
import {
  loadLibrary, saveLibrary, applyItem, removeItem, normalizeRecord, exportLibrary, parseImport, nextIndex, isCustomIndex,
} from './registry.js';

let SYS = null;
const SERVER_IMPORT_MAX_BYTES = 1024 * 1024;
const SERVER_IMPORT_MAX_RECORDS = 100;

class ItemBuilderSystem {
  constructor(game, db) {
    this.game = game;
    this.db = db;
    this._disposed = false;
    // items/db.js already ran applyStoredCustomItems(db) while loading: reuse the library it built (same records,
    // already applied) instead of loading + re-applying a second copy.
    this.lib = game.save.authority==='server'?{items:(game.serverCustomItems?.items||[]).filter(r=>!r.deleted)}:db._customLibrary || loadLibrary();
    this.builder = null;
    game.events?.on?.('server:customitems',({items})=>{this.lib={items:items.filter(r=>!r.deleted)};if(this.builder?.win){this.builder.fillInfo();if(this.builder.pickTab==='lib')this.builder.fillPicker();}});
  }

  dispose() {
    if (this._disposed) return;
    this._disposed = true;
    this.builder?.onClose();
  }

  // ------------------------------------------------------------------------------------------ misc
  msg(text) { if (text) try { this.game.hud?.log?.(text, 'sys'); } catch { /* hud optional (headless tests) */ } }
  /** Forget a cached inventory icon (the draft item's icon changes as it is edited). */
  clearIcon(index) {
    const cache = this.game.items?.icons?.cache;
    if (!cache) return;
    const p = `${index}|`;
    // Model aliases omit textures from their keys; forget them too when an item changes texture.
    for (const k of [...cache.keys()]) {
      if (index == null || k.startsWith(p) || k.startsWith(`s|${p}`) || !/^(s\|)?\d+\|/.test(k)) cache.delete(k);
    }
  }

  // ------------------------------------------------------------------------------------------ library
  /** Save a draft record under `editingIndex` (an existing custom index) or a fresh one. Returns the saved record. */
  saveRecord(draft, editingIndex = null) {
    if (!draft) return null;
    if(this.game.save.authority==='server')return this.server('customSave',{record:draft,editingIndex}).then(result=>result?.record||null);
    const db = this.db;
    const has = editingIndex != null && this.lib.items.some(r => r.index === Number(editingIndex));
    const existing = has ? this.lib.items.find(r => r.index === Number(editingIndex)) : null;
    const rec = normalizeRecord({ ...draft, index: has ? Number(editingIndex) : nextIndex(this.lib) }, db);
    rec.created = existing?.created || Date.now();
    rec.updated = Date.now();
    const next={...this.lib,items:this.lib.items.filter(r=>r.index!==rec.index).concat(rec)};
    if(!saveLibrary(next)){this.msg('Save failed: browser storage is full or unavailable. The draft is still unsaved.');return null;}
    if (!applyItem(db, rec)) return null;
    this.lib=next;db._customLibrary=next;
    this.clearIcon(rec.index);
    this.game.items?.changed?.('equip:itembuilder', { itemIndex: rec.index });
    this.game.events?.emit?.('itembuilder:changed', { index: rec.index });
    return rec;
  }
  /** Delete a custom item from the database, the library, and every copy the character owns. Returns copies removed. */
  deleteRecord(index) {
    if(this.game.save.authority==='server')return this.server('customDelete',{index:Number(index)}).then(result=>result?result.removed:null);
    index = Number(index);
    if (!isCustomIndex(index)) return 0;
    const next={...this.lib,items:this.lib.items.filter(r=>r.index!==index)};
    if(!saveLibrary(next)){this.msg('Delete failed: browser storage is unavailable.');return null;}
    this.lib=next;this.db._customLibrary=next;
    removeItem(this.db, index);
    this.clearIcon(index);
    const n = this._purge(index);
    this.game.events?.emit?.('itembuilder:changed', { index, deleted: true });
    return n;
  }
  /** Strip every owned instance of a (removed) item index from equipment / bag / stash / costume bag / cash. */
  _purge(index) {
    const sys = this.game.items;
    if (!sys) return 0;
    let n = 0;
    const E = sys.equip;
    if (E) {
      for (const uid of Object.keys(E.data.items)) {
        if (E.data.items[uid].itemIndex !== index) continue;
        for (const p of E.data.presets) for (const s of Object.keys(p)) if (p[s] === uid) delete p[s];
        delete E.data.items[uid];
        n++;
      }
    }
    for (const c of [sys.bag, sys.stash, sys.shared, sys.costumeBag]) for (const inst of [...(c?.list || [])]) if (inst.itemIndex === index) { c.take(inst); n++; }
    const cl = this.game.save?.cashInv || [];
    for (let i = cl.length - 1; i >= 0; i--) if (cl[i].itemIndex === index) { cl.splice(i, 1); n++; }
    if (n) sys.changed('equip', { itemIndex: index });
    return n;
  }

  /** Create `count` of a saved custom item into the inventory (its own grade/sockets/roll), optionally equip one. */
  spawn(index, count = 1, { equip = false } = {}) {
    if(this.game.save.authority==='server')return this.server('customSpawn',{index:Number(index),count:Number(count),equip:!!equip}).then(result=>result||{ok:false});
    index = Number(index);
    const rec = this.lib.items.find(r => r.index === index);
    const sys = this.game.items;
    const def = this.db.def(index);
    if (!rec || !def || !sys) return { ok: false };
    // Passing the index lets ItemsSystem.add split non-stackable counts into separate unique instances.
    const amount = Math.max(1, Math.min(9999, Math.floor(Number(count) || 1)));
    const r = sys.add(index, amount, { grade: rec.grade || 'normal', sockets: rec.sockets || 0,
      roll: !!rec.roll, dropLeft: true, source: 'itembuilder', silent: true });
    let equipped = false;
    if (equip && def.slot && r.placed[0]) equipped = sys.equipItem(r.placed[0]);
    return { ok: r.ok || r.placed.length > 0, inst: r.placed[0] || null, placed: r.placed, left: r.left, equipped };
  }

  /** The library (or a subset of indices) as a downloaded .json file. */
  exportFile(indices = null) {
    const text = exportLibrary(this.lib, indices);
    const blob = new Blob([text], { type: 'application/json' });
    const a = document.createElement('a');
    const d = new Date(), pad = (n) => String(n).padStart(2, '0');
    a.href = URL.createObjectURL(blob);
    a.download = `DekaronOnline_CustomItems_${d.getFullYear()}${pad(d.getMonth() + 1)}${pad(d.getDate())}.json`;
    document.body.appendChild(a); a.click(); a.remove();
    setTimeout(() => URL.revokeObjectURL(a.href), 2000);
    this.msg(`Exported ${indices ? indices.length : this.lib.items.length} custom item(s).`);
  }
  /** File picker -> merge the chosen library export (or a bare record / array of records) into this library. */
  importFile() {
    const game = this.game, db = this.db, save = game.save, authority = save?.authority, id = save?.id;
    const network = game.network, token = network?.token, ready = network?.ready;
    const permissions = () => JSON.stringify([...(game.accountPermissions?.capabilities || [])].sort());
    const capabilities = permissions();
    const current = () => !this._disposed && this.game === game && this.db === db && game.save === save && save?.authority === authority && save?.id === id
      && game.network === network && network?.token === token && network?.ready === ready && !network?.disposed && permissions() === capabilities;
    const requireCurrent = () => { if (!current()) throw new Error('The Item Builder import session changed. Reopen Import for the current character.'); };
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = 'application/json,.json';
    input.style.display = 'none';
    input.addEventListener('change', async () => {
      const f = input.files?.[0];
      input.remove();
      if (!f) return;
      try {
        requireCurrent();
        const serverImport = authority === 'server';
        if (serverImport && f.size > SERVER_IMPORT_MAX_BYTES) throw new Error('Server imports are limited to 1 MiB. Split the export into smaller files.');
        const text = await f.text();
        requireCurrent();
        if(serverImport){const {records}=parseImport(text,this.lib,this.db,{maxRecords:SERVER_IMPORT_MAX_RECORDS});const result=await this.server('customImport',{records});if(!result)throw new Error('The server did not accept the imported library.');this.msg(`Imported ${result.records.length} server custom items.`);return;}
        const { records, renumbered } = parseImport(text, this.lib, this.db);
        const next={...this.lib,items:this.lib.items.filter(r=>!records.some(row=>row.index===r.index)).concat(records)};
        if(!saveLibrary(next))throw new Error('Browser storage is full or unavailable; no items imported.');
        for (const r of records) {
          if (!applyItem(this.db, r)) continue;
          const i = this.lib.items.findIndex(x => x.index === r.index);
          if (i >= 0) this.lib.items[i] = r; else this.lib.items.push(r);
        }
        this.clearIcon();
        this.game.items?.changed?.('equip:itembuilder', { imported: records.length });
        this.msg(`Imported ${records.length} custom item(s)${renumbered ? ` (${renumbered} renumbered)` : ''}.`);
        this.game.events?.emit?.('itembuilder:changed', { imported: records.length });
        if (this.builder?.win) { this.builder.fillInfo(); if (this.builder.pickTab === 'lib') this.builder.fillPicker(); }
      } catch (err) {
        console.error('[itembuilder] import', err);
        this.msg(`Import failed: ${err?.message || err}`);
      }
    });
    document.body.appendChild(input);
    input.click();
  }
  async server(operation,fields){try{const network=this.game.network;if(!network?.ready||!network.token)throw new Error('Wait for the shared world connection.');const token=network.token,revision=this.game.serverCustomItems?.revision;const result=await network._request('gm',{token,operation,...fields,...(operation!=='customSpawn'&&Number.isSafeInteger(revision)?{expectedRevision:revision}:{})});if(this.game.network!==network||network.token!==token||!network.ready||network.disposed)throw new Error('The Item Builder session changed. Reconnect and retry.');if(result.library){for(const record of result.library)applyItem(this.db,record);this.lib={items:result.library.filter(r=>!r.deleted)};this.game.serverCustomItems={items:result.library,revision:result.revision};this.game.events.emit('server:customitems',this.game.serverCustomItems);}if(result.state)network._receiveSnapshot(result.state);this.clearIcon();return result;}catch(error){if(error.status===409)void this.game.network?.refreshCustomItems?.();this.msg(`Item Builder: ${error.message}`);return null;}}
}

export async function install(game) {
  if (game.items?.ready) await game.items.ready;
  const db = game.items?.db;
  if (!db) { console.warn('[itembuilder] the items system is not installed; skipped'); return null; }
  dispose();
  const S = new ItemBuilderSystem(game, db);
  SYS = S;
  S.builder = new BuilderWindow(S);
  S.builder.register();

  // public API (docs/RESUME.md: "spawnable from the GM panel")
  game.customItems = {
    list: () => S.lib.items.slice(),
    get: (index) => S.lib.items.find(r => r.index === Number(index)) || null,
    save: (record, editingIndex = null) => S.saveRecord(record, editingIndex),
    remove: (index) => S.deleteRecord(index),
    spawn: (index, count = 1, opts = {}) => S.spawn(index, count, opts),
    exportFile: (indices = null) => S.exportFile(indices),
    importFile: () => S.importFile(),
    openBuilder: (arg = null) => game.uiwin.open('itembuilder', arg),
    isCustom: isCustomIndex,
  };

  // chat command
  if (game.chat?.registerCommand) {
    game.chat.registerCommand('/itembuilder', (args) => {
      const a = String(args || '').trim();
      if (!a || /^open$/i.test(a)) { game.uiwin.open('itembuilder'); return true; }
      if (/^new$/i.test(a)) { Promise.resolve(game.uiwin.open('itembuilder')).then(() => S.builder?.newItem()); return true; }
      const n = Number(a);
      if (Number.isFinite(n)) { game.uiwin.open('itembuilder', isCustomIndex(n) ? { index: n } : { clone: n }); return true; }
      game.chat.system('Usage: /itembuilder [open | new | <item index>]', 'err');
      return true;
    }, '[open | new | <item index>] -- create or clone items (Ctrl+B)');
  }

  return S;
}
export function dispose() { const sys = SYS; SYS = null; sys?.dispose(); }
export { ItemBuilderSystem };
