// W99 monster chatter: Global share/support/monsterdialogue/monsterdialogue.csv (built into gamedata/dialogs.json
// `monsterTalk` by tools/build-quests.mjs:1265-1280). Columns: Index, Name, HasDlg, CreateDlg_1..3, IdleDlg_1..3,
// AttackDlg_1..3, DieDlg_1..3, timeMin, timeMax (ms), Probability (%).
// Triggers, as the columns define them:
//   create  once when the monster appears;  die  once when it dies;
//   idle    while it has no target, attack  while it has a target: every timeMin..timeMax ms (uniform) it rolls
//           Probability % and, on success, says one of that state's lines.
// Create/die also roll Probability. Only rows with HasDlg 1 talk. Lines show as the chat balloon over the monster
// (hud-options/bubbles.js via game.chat.bubble). Presentation only: no AI, damage or timing change.
import { fetchJSON } from '../../engine/assets.js';

export class MonsterTalk {
  constructor(game, life, { table = null, rand = Math.random } = {}) {
    this.game = game; this.table = table; this.rand = rand; this.state = new Map();
  }
  async install() {
    if (this.table) return;
    try { this.table = (await fetchJSON('/gamedata/dialogs.json'))?.monsterTalk || {}; } catch { this.table = {}; }
  }
  onMap() { this.state.clear(); }
  row(actor) { const r = this.table?.[actor?.monsterIndex ?? actor?.def?.index]; return r && r.has ? r : null; }
  _delay(r) { const [a, b] = r.time || [0, 0]; return (a + this.rand() * Math.max(0, b - a)) / 1000; }
  _say(actor, r, kind) {
    const lines = r[kind];
    if (!lines?.length || this.rand() * 100 >= (Number(r.chance) || 0)) return null;
    const text = lines[Math.min(lines.length - 1, Math.floor(this.rand() * lines.length))];
    const chat = this.game.chat;
    if (chat?.bubble) chat.bubble(actor, text, 'normal'); else this.game.hudOptions?.bubbles?.show?.(actor, text, 'normal');
    return text;
  }
  update(dt) {
    if (!this.table) return;
    const seen = new Set();
    for (const a of this.game.actors?.() || []) {
      if (a?.kind !== 'monster') continue;
      const r = this.row(a); if (!r) continue;
      seen.add(a);
      let s = this.state.get(a);
      if (!s) { s = { t: this._delay(r), dead: !!a.dead }; this.state.set(a, s); if (!a.dead) this._say(a, r, 'create'); continue; }
      if (a.dead) { if (!s.dead) { s.dead = true; this._say(a, r, 'die'); } continue; }
      s.dead = false;
      s.t -= dt;
      if (s.t <= 0) { s.t = this._delay(r); this._say(a, r, a.target ? 'attack' : 'idle'); }
    }
    for (const a of this.state.keys()) if (!seen.has(a)) this.state.delete(a);
  }
}
