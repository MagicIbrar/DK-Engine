// Native party status art/controls. ENGINE-CHOSEN: dock below the right minimap and
// separate buff/debuff lines avoid overlap in the authored shared status rect.
import { LS } from '../hud-options/util.js';
import { classSmallIcon, statusStrips } from './troopstate.js';
import { str, strNow } from './common.js';

export const PARTY_STATE_SCRIPT = 'game2/party/ui_partystate.txt';
export const PARTY_HUD_ROWS = 6; // The other members of a native seven-member party.
export const partyHudRowY = (i, expanded) => 24 + i * (32 + (expanded ? 44 : 0));
export function partyHudMembers(st, myId) {
  if (!st?.active || !myId || !st.members?.some(m => m.id === myId)) return [];
  return st.members.filter(m => m.id !== myId).slice(0, PARTY_HUD_ROWS);
}
// Geometry is in UIManager reference pixels; its existing scale fits the entire HUD.
// The fallback uses ui_minimapwnd.txt's authored 182x230 right/top box until it loads.
// Authored visible x span of ui_partystate.txt: state_menu/pan_bg start at 147, pan_bg ends at 147+243.
export const PARTY_HUD_ART_X = [147, 390];
// ENGINE-CHOSEN: the default quest tracker (ui_new_questassist, right column at y212) shares this
// right column. Stack below its visible extent, or beside it when no header+row fits below.
export function partyHudDock(screen, minimap, width=387, avoid=null, height=23) {
  const positive=(v,f)=>Number.isFinite(Number(v))&&Number(v)>0?Number(v):f;
  const sw=positive(screen?.w,1024),sh=positive(screen?.h,768);
  const box=b=>b&&[b.x,b.y,b.w,b.h].every(Number.isFinite)&&b.w>0&&b.h>0?b:null;
  const mini=box(minimap)||{x:sw-182,y:0,w:182,h:230};
  const obstacles=[mini,box(avoid)].filter(Boolean);
  const [left,right]=PARTY_HUD_ART_X,wanted=Math.max(23,positive(height,23)),need=Math.min(wanted,56);
  // Transparent leading space may lie off-screen; the entire authored header/art must fit.
  const lo=-left,hi=Math.floor(sw-Math.max(right,positive(width,387))),bottom=Math.floor(sh-need);
  const clamp=(v,a,b)=>Math.max(a,Math.min(b,Math.round(v)));
  const origin={x:clamp(mini.x+mini.w-width,lo,Math.max(lo,hi)),y:clamp(mini.y+mini.h+8,0,Math.max(0,bottom))};
  // At most two obstacles: test their edges and the viewport edges, rechecking after clamps.
  // Prefer ordinary 8px spacing; zero-gap edges are a last resort in a tight viewport.
  if(hi>=lo&&bottom>=0)for(const gap of [8,0]){
    const xs=new Set([origin.x,lo,hi]),ys=new Set([origin.y,0,bottom]);
    for(const b of obstacles){
      xs.add(clamp(Math.floor(b.x-gap-right),lo,hi));xs.add(clamp(Math.ceil(b.x+b.w+gap-left),lo,hi));
      ys.add(clamp(Math.ceil(b.y+b.h+gap),0,bottom));ys.add(clamp(Math.floor(b.y-gap-need),0,bottom));
    }
    let best=null,score=Infinity;
    for(const x of xs)for(const y of ys){
      let cap=sh-y-gap;
      for(const b of obstacles)if(x+left<b.x+b.w&&b.x<x+right){
        if(y>=b.y+b.h)continue;
        if(y<b.y)cap=Math.min(cap,b.y-y-gap);else cap=0;
      }
      if(cap<need)continue;
      const distance=Math.abs(x-origin.x)+Math.abs(y-origin.y);
      if(distance<score){score=distance;best={x,y,maxHeight:Math.floor(cap)};}
    }
    if(best)return best;
  }
  // No header(+one shown row) fits: retain the panel/rows and expose the limit, never hide it.
  return {...origin,maxHeight:Math.max(23,Math.floor(sh-origin.y)),layoutUnavailable:true};
}
// Visible extent of the open quest tracker: its window box, its unclipped growing pan_body,
// or only the minimized restore button. Closed/absent tracker => null (dock unchanged).
export function questTrackerBox(ui) {
  const w=ui?.window?.('questassist');
  if(!w?.isOpen||!w.box)return null;
  const b=w.box,body=w.find?.('pan_body'),redo=w.find?.('btn_redo');
  let h=b.h;
  if(body?.isVisible?.()&&Number(body.box?.h)>0)h=Math.max(b.h,Number(body.box.y||0)+Number(body.box.h));
  else if(redo?.isVisible?.()&&Number(redo.box?.h)>0)h=Number(redo.box.y||0)+Number(redo.box.h);
  return {x:b.x,y:b.y,w:b.w,h};
}
const ratio = (v, max) => Number(max) > 0 ? Math.max(0, Math.min(1, (Number(v) || 0) / Number(max))) : 0;

export class PartyHud {
  constructor(game, party) {
    this.game = game; this.party = party; this.rows = []; this.win = null;
    const saved = LS.load(this.key, {}) || {};
    this.expanded = !!saved.expanded; this.hidden = !!saved.hidden; this.locked = !!saved.locked;
    this.manualPosition = saved.position && Number.isFinite(saved.position.x) && Number.isFinite(saved.position.y) ? saved.position : null;
  }
  get key() { return `dekaron.partystate.${this.game.save?.id || 'guest'}`; }
  _save() { LS.save(this.key, { expanded: this.expanded, hidden: this.hidden, locked: this.locked, position: this.manualPosition }); }
  _lease() { const n = this.game.network; return JSON.stringify([n?.self?.id, n?._leaseGeneration, n?.token]); }
  _valid() { return !this.disposed && this.snapshotLease === this._lease() && this.game.save?.authority === 'server' && !this.game.network?.expedition?.active && !!this.party.st?.active && this.party.st.members?.some(m => m.id === this.game.network?.self?.id); }
  install() {
    const ui = this.game.uiwin;
    if (!ui?.registerWindow || !ui.get || !ui.openWindow) return;
    this.installed = true;
    ui.registerWindow('party_state', {
      script: PARTY_STATE_SCRIPT, hud: true, escClose: false, remember: false, pos: { x: 637, y: 238 },
      create: w => this._create(w), onOpen: () => this.render(), update: () => this.sync(),
    });
    void str(this.game,70,92).then(()=>{if(!this.disposed){this.signature=null;this.render();}});
  }
  apply() {
    const self=this.game.network?.self, current=self?.id?{id:self.id,channel:self.channel??0}:null, previous=this.channelSnapshot;
    this.channelSnapshot=current;
    this.snapshotLease = this._lease();
    // Native43.8.0 option2001:197 + checkbox2001:95 (View). Only an
    // observed channel transition of the same character reveals an existing party.
    if(current&&previous?.id===current.id&&previous.channel!==current.channel&&this._valid()&&this.game.options?.get?.('partyUiOpen')===true) this.setHidden(false);
    this.sync();
  }
  sync() {
    if (!this.installed) return;
    const ui = this.game.uiwin;
    if (!this._valid()) { if (this.win?.isOpen) ui.close('party_state', 'server'); return; }
    if (this.win?.isOpen) { this.render(); return; }
    if (this.opening) return;
    const lease = this.snapshotLease, partyId = this.party.st.id;
    this.opening = ui.get('party_state').then(w => {
      if (!this._valid() || lease !== this.snapshotLease || partyId !== this.party.st.id) {
        if (this.disposed) { w.close?.('server'); w.dispose?.(); if (ui.wins?.get('party_state') === w) ui.wins.delete('party_state'); }
        return;
      }
      ui.openWindow(w); this.render();
    }).catch(error => { if (this._valid()) console.warn('[party] status window', error?.message || error); }).finally(() => { this.opening = null; });
  }
  _create(w) {
    this.win = w;
    if(this.manualPosition)w._pos={...this.manualPosition};
    w.on?.('move',position=>{if(!this.locked){this.manualPosition={x:position.x,y:position.y};this._save();}});
    // Each window gets its own geometry, leaving the cached native spec untouched.
    w.spec = { ...w.spec, rect: [...w.spec.rect] };
    const c = id => w.control(id);
    c('btn_state_plus').onClick(() => this.setExpanded(true));
    c('btn_state_minus').onClick(() => this.setExpanded(false));
    c('btn_state_hide').onClick(() => this.setHidden(true));
    c('btn_state_show').onClick(() => this.setHidden(false));
    c('btn_lock').onClick(() => this.setLocked(!this.locked));
    const tpl = c('pan_state');
    for (let i = 0; i < PARTY_HUD_ROWS; i++) {
      const row = tpl.cloneAs(`_${i}`, { x: 0, y: partyHudRowY(i, this.expanded), visible: false });
      row.setEnabled(true); this.rows.push(row);
      // Authored Follow control, shared ordinary player-menu movement route.
      // Its two-cell movement gap remains ENGINE-CHOSEN, not a native formula.
      c(`btn_follow_${i}`).setEnabled(false).onClick(() => this.followMember(i));
      c(`pan_debuffstatus_${i}`).setRect(149, 54, 176, 22);
    }
    tpl.hide(); this.setLocked(this.locked, false);
  }
  setExpanded(on) { this.expanded = !!on; this._save(); this.signature = null; this.render(); }
  setHidden(on) { this.hidden = !!on; this._save(); this.signature = null; this.render(); }
  setLocked(on, save = true) {
    this.locked = !!on;
    if (this.win) {
      this.win.opts.movable = !this.locked;
      // Use the same original closed/open padlocks as the native quickslot
      // bar; a permanently closed icon made the working unlock look broken.
      const lock=this.win.control('btn_lock'),base=this.locked?70:73;
      for(const [key,offset] of [['none',0],['down',1],['over',2]])lock.setImage(key,'newMainbar',base+offset);
      // The native header has intersect=false, so its background cannot receive
      // pointerdown even when the window's movable flag is true. Keep the native
      // buttons clickable and expose the header itself only while unlocked.
      for (const id of ['state_menu', 'state_menu2']) {
        const header = this.win.control(id);
        if (header.el?.style) header.el.style.pointerEvents = this.locked ? 'none' : 'auto';
      }
    }
    if (save) this._save();
  }
  followTarget(id) {
    if (!this._valid() || !partyHudMembers(this.party.st,this.game.network?.self?.id).some(m=>m.id===id)) return null;
    const n=this.game.network,t=n?.players?.get?.(id),scene=t?._serverScene,self=n?.self;
    if (!scene || !self || Number(scene.map)!==Number(self.map) || (scene.instanceId||null)!==(self.instanceId||null) || (scene.channel||0)!==(self.channel||0)) return null;
    return n.playerFollow?.canFollow(t) ? t : null;
  }
  followMember(i) {
    const binding=this.followBindings?.[i],current=partyHudMembers(this.party.st,this.game.network?.self?.id)[i];
    if (!binding || binding.partyId!==this.party.st.id || binding.lease!==this.snapshotLease || current?.id!==binding.id) return false;
    const target=this.followTarget(binding.id);
    return target ? this.game.network.playerFollow.follow(target,{valid:()=>binding.partyId===this.party.st.id&&binding.lease===this.snapshotLease&&this.followTarget(binding.id)===target}) : false;
  }
  render() {
    const w = this.win;
    if (!w || !this._valid()) return;
    const members = partyHudMembers(this.party.st, this.game.network?.self?.id);
    // Actor availability changes independently of party HP/status snapshots.
    // Recheck before the geometry/status signature can skip a repaint.
    this.followBindings=members.map(member=>({id:member.id,partyId:this.party.st.id,lease:this.snapshotLease}));
    this.rows.forEach((_row,i)=>{const control=w.control(`btn_follow_${i}`),enabled=!!members[i]&&!this.hidden&&!!this.followTarget(members[i].id);if(control.enabled!==enabled)control.setEnabled(enabled);});
    const screen=w.mgr?.screen||this.game.uiwin?.screen;
    const minimap=this.game.uiwin?.window?.('hud_minimap')?.box;
    // An open quest tracker is considered when the party HUD first docks. Moving
    // the tracker later must never drag the independent party HUD along with it.
    if(!this.dockAvoidSet){this.dockAvoid=questTrackerBox(this.game.uiwin);this.dockAvoidSet=true;}
    const height=this.hidden ? 23 : Math.max(23, 24 + members.length * (32 + (this.expanded ? 44 : 0)));
    const dock=partyHudDock(screen,minimap,w.spec.rect[2]-w.spec.rect[0],this.dockAvoid,height);
    const signature = JSON.stringify([members, this.hidden, this.expanded, screen?.w,screen?.h,this.game.uiwin?.scale,minimap,dock]);
    if (signature === this.signature) return;
    this.signature = signature;
    const c = id => w.control(id);
    c('state_menu').setVisible(!this.hidden); c('state_menu2').setVisible(this.hidden);
    c('btn_state_plus').setVisible(!this.expanded); c('btn_state_minus').setVisible(this.expanded); c('btn_state_mid').hide();
    w.spec.rect[3] = height;
    w.opts.pos = this.manualPosition ? {...this.manualPosition} : { x: dock.x, y: dock.y };
    // Retain all native rows: unusually short logical viewports scroll instead of covering the minimap.
    if(w.el?.style){w.el.style.maxHeight=`${dock.maxHeight}px`;w.el.style.overflowY=w.spec.rect[3]>dock.maxHeight?'auto':'';w.el.style.overflowX=w.spec.rect[3]>dock.maxHeight?'hidden':'';w.el.style.pointerEvents=w.spec.rect[3]>dock.maxHeight?'auto':'';}
    w.place?.();
    this.rows.forEach((row, i) => {
      const member = members[i]; row.setVisible(!!member && !this.hidden);
      if (!member || this.hidden) return;
      row.setRect(0, partyHudRowY(i, this.expanded));
      // ENGINE-CHOSEN name/level formatting in the existing authored title;
      // native70:92 supplies Lv. No dedicated native HUD level control exists.
      const level=Number.isSafeInteger(member.level)&&member.level>0?member.level:null,label=strNow(this.game,70,92);
      c(`pan_pcname_${i}`).setText(`${member.name||''}${level!==null&&label?`  ${label} ${level}`:''}`);
      c(`pan_class_${i}`).setImage('none', 'etc_01', classSmallIcon(member.classIndex));
      c(`processbar_hp_${i}`).setGauge(ratio(member.hp, member.maxHp));
      c(`processbar_shield_${i}`).setGauge(ratio(member.shield, member.maxShield));
      const { buffs, debuffs } = statusStrips(member.statuses);
      c(`pan_buffstatus_${i}`).setVisible(this.expanded); c(`pan_debuffstatus_${i}`).setVisible(this.expanded);
      for (let k = 0; k < 8; k++) for (const [kind, statuses] of [['buff', buffs], ['debuff', debuffs]]) {
        const icon = c(`pan_${kind}icon_${k}_${i}`), status = statuses[k];
        icon.setVisible(this.expanded && !!status); if (status) icon.setImage('none', status.group || 'buffer', status.icon);
      }
    });
  }
  dispose() { this.disposed = true; this.game.uiwin?.unregisterWindow?.('party_state'); this.win = null; this.rows = []; }
}
