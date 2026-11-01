// Monster bounty: the original Wanted Notice Board window (game2/monsterbounty/ui_monsterbountywnd.txt), opened by clicking the
// Wanted Notice Board NPC (6214, JobType 171 WANTED_EVENT). Every rule and its data source: bounty-rules.js. The board only shows
// quest state (posters + "completed" stamps); accepting and completing the wanted quests stays with their NPCs and the quest
// system (server-authoritative online), so nothing here changes game state.
import { BOUNTY_SCRIPT, DETAILS_STRING, WANTED_EVENT_JOB, wantedQuests, posterOf, pageCount, clampPage, pageItems, isBoardNpc } from './bounty-rules.js';

export class MonsterBounty {
  constructor(game) { this.game = game; this.win = null; this.page = 0; this.posters = []; this.slots = []; }

  async install() {
    const g = this.game;
    g.uiwin.registerWindow('monsterbounty', {
      script: BOUNTY_SCRIPT,
      create: w => this._create(w),
      onOpen: () => this.refresh({ resetPage: true }),
    });
    this._wireNpc();
    g.events?.on?.('systems', () => this._wireNpc());
    g.events?.on?.('quest:changed', () => { if (this.win?.isOpen) this.refresh(); });
    g.monsterBounty = this;
  }

  /** The board opens on the click of an NPC whose every job is WANTED_EVENT (no menu line exists for JobType 171). */
  _wireNpc() {
    const g = this.game, W = g.windows;
    if (W && typeof W.openNpc === 'function' && W._bountyOpenNpc !== W.openNpc) {
      const orig = W.openNpc.bind(W);
      W.openNpc = npc => { if (isBoardNpc(npc)) { void this.open(npc); return null; } return orig(npc); };
      W._bountyOpenNpc = W.openNpc;
    }
    const s = g.npcServices;
    if (s?.register && this._services !== s) { this._services = s; s.register(WANTED_EVENT_JOB, npc => { void this.open(npc); return true; }); }
  }

  open(npc = null) { return this.game.uiwin.open('monsterbounty', { npc }); }

  _create(w) {
    this.win = w;
    // the 7 poster panels of the script (pan_montage_1 and its clones), in id order
    this.slots = w.controls(c => /^pan_montage_\d+$/i.test(c.id)).sort((a, b) => Number(a.id.split('_').pop()) - Number(b.id.split('_').pop()));
    w.control('btn_prevpage').onClick(() => this.turn(-1));
    w.control('btn_nextpage').onClick(() => this.turn(1));
  }

  get perPage() { return this.slots.length || 7; }
  get now() { const e = this.game.quests?.engine; return Number(e?.now) || Date.now(); }

  /** Rebuild the poster list from the quest data and the character's quest state. */
  refresh({ resetPage = false } = {}) {
    const g = this.game, db = g.quests?.db;
    this.posters = db ? wantedQuests(db.quests, this.now).map(q => posterOf(q, db.str(q.id, DETAILS_STRING, { common: false }), n => db.npcName(n))) : [];
    this.page = resetPage ? 0 : clampPage(this.page, this.posters.length, this.perPage);
    this.render();
  }

  turn(dir) {
    const next = clampPage(this.page + dir, this.posters.length, this.perPage);
    if (next === this.page) return;
    this.page = next;
    this.render();
  }

  render() {
    const w = this.win;
    if (!w) return;
    const items = pageItems(this.posters, this.page, this.perPage);
    const done = id => !!this.game.quests?.isDone?.(id);
    this.slots.forEach((panel, i) => {
      const p = items[i];
      panel.setVisible(!!p);
      if (!p) return;
      panel.control('lbl_monstername')?.setText(p.name);
      panel.control('lbl_location')?.setText(p.location);
      panel.control('lbl_npc')?.setText(p.npcName);
      panel.control('pan_monster')?.setImage('none', p.monster != null ? { screen: 'monsterbounty', index: p.monster } : null);
      panel.control('pan_clear')?.setVisible(done(p.id));
    });
    w.control('lbl_page').setText(`${this.page + 1} / ${pageCount(this.posters.length, this.perPage)}`);
  }

  dispose() { this.win = null; }
}
