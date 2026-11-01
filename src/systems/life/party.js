import { declineBlockedInvitation } from '../hud-options/invitation-policy.js';
// Party presentation (share/partysearch/matchingmap.csv, share/pc/groupexpratio.csv via
// gamedata/life.json `party`). Main window `game2/party/ui_partyinfo_renew.txt` ("party", hotkey P / btn_party):
// Offline you can only ever be your own 1-member party; online membership comes from the server. The
// window still works - naming it, toggling the item-distribution mode, seeing your own slot with live HP - and
// `groupExpRatio` is exposed for other systems (progression) even though a solo party of 1 always resolves to its
// 100% ratio. `matchingMaps` (the party-finder board's map list) backs a read-only recruiting board
// (`game2/party/ui_partylistwnd_renew.txt`) that is honestly empty (no other players exist to post there) rather
// than faked with invented entries.
import { str, strNow, msg, state } from './common.js';
import { PartyHud } from './party-hud.js';
import { globalAsk } from '../../ui/uiwin/global-asks.js';
import { globalNotice } from '../../ui/uiwin/global-windows.js';
// Party name input: the renewed party UI's own window party/ui_partynameinputwnd_renew (party_renew art, like ui_partyinfo_renew)
// with the texts Global's msgbox/ui_partyunion and msgbox/ui_partyname define: title 100:7 "Form Party" when forming, 100:6
// "Change Party Name" when renaming, label 70:27 "Party slogan". (Those two msgbox scripts are the older etc_01-art versions.)
// Delegate with no member picked: msgbox/ui_partyleadertrust "Delegate" (70:32) "Please enter a party member to delegate." (70:28).
export const PARTY_NAME_INPUT = 'game2/party/ui_partynameinputwnd_renew.txt', PARTY_FORM_TITLE = 7, PARTY_RENAME_TITLE = 6;
export const PARTY_DELEGATE_BOX = 'game2:msgbox:ui_partyleadertrust';

// party_renew#1 (the 451x304 window art) has 7 member row plates at y 74 + 27 k, numbered by party_renew_num 1..7
// (active) / 8..14 (inactive); the btn_slot_ / pan_empty_ templates are 23 px high rows placed on those plates.
const MAX_SLOTS = 7;
const ROW_PITCH = 27;
export const PARTY_INVITATION_SCRIPT = 'game2/msgbox/ui_partyinvitation.txt';
const invitationKey = i => i ? JSON.stringify([i.id,i.from,i.expires]) : null;

export class Party {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.P = life.data?.party || null;
  }

  get st() {
    if(this.game.save?.authority==='server')return this.serverState||{active:false,name:'',itemway:0,members:[],connected:[]};
    const s = state(this.game);
    if (!s.party) s.party = { active: false, name: '', itemway: 0 };
    return s.party;
  }
  get active() { return !!this.st.active; }
  /** hud-options chat.js reads game.party.members directly. */
  get members() {
    if(this.game.save?.authority==='server')return this.st.members||[];
    if (!this.active) return [];
    const g = this.game;
    return [{ name: g.save?.name || g.player?.name || 'You', level: g.save?.level || 1, leader: true, hp: g.player?.hp, maxHp: g.player?.maxHp }];
  }
  groupExpRatio(size) {
    const row = this.P?.groupExpDefault;
    const n = Math.max(1, Math.min(18, size));
    return (Number(row?.[`GroupExpRatio${n}`]) || (n === 1 ? 100 : 0)) / 100;
  }

  async install() {
    const g = this.game;
    await Promise.all([str(g, 70, 178).catch(() => {}), str(g, 2000, 77).catch(() => {}), str(g, 100, 8).catch(() => {}), str(g, 100, 14).catch(() => {}),
      str(g, 100, PARTY_FORM_TITLE).catch(() => {}), str(g, 100, PARTY_RENAME_TITLE).catch(() => {}), str(g, 70, 27).catch(() => {})]);
    g.ui?.registerWindow?.('party', { script: 'game2/party/ui_partyinfo_renew.txt', menuButton: 'btn_party', create: (w) => this._create(w), onOpen: (w) => this._refresh(w), update: (w) => this._tick(w) });
    g.ui?.registerWindow?.('partyfind', { script: 'game2/party/ui_partylistwnd_renew.txt', create: (w) => this._createFind(w), onOpen: (w) => this._refreshFind(w) });
    g.party = this;
    this.partyHud = new PartyHud(g, this);
    this.partyHud.install();
    if(g.save?.authority==='server'){
      this._partyUnsubscribe=g.events?.on?.('server:party',s=>this.applyServer(s));
      if(g.network?.party)this.applyServer(g.network.party);
      g.chat?.registerCommand?.('/invite',args=>{void this.inviteName(args);return true;},'Invite a connected character to your party.');
    }
  }

  async command(operation,values={}){
    const result=await this.game.network?.action('party',{operation,...values});
    if(!result) return false;
    return true;
  }
  async inviteName(name){
    const candidates=(this.st.connected||[]).filter(p=>p.name.toLowerCase()===String(name||'').trim().toLowerCase()&&p.id!==this.game.network?.self?.id);
    if(candidates.length!==1){msg(this.game,candidates.length?'More than one connected character has that name. Use Find to select the exact character.':'That character is not connected.','err');return false;}
    // Chat and messenger invitations need the same create-before-invite flow
    // as the selected-player menu. Membership still comes from the host.
    const lease=this._invitationLease();
    if(!this.active){
      if(!this._invitePartyCreation)this._invitePartyCreation=this.command('create').finally(()=>{this._invitePartyCreation=null;});
      if(!await this._invitePartyCreation||!this._sameInvitationLease(lease))return false;
    }
    return this.command('invite',{targetId:candidates[0].id});
  }
  applyServer(s){
    if(this.disposed)return;
    this.serverState=s;
    if(this.win?.isOpen)this._refresh(this.win);
    if(this.findWin?.isOpen)this._refreshFind(this.findWin);
    this._syncInvitation();
    this.partyHud?.apply();
  }

  update() { this.partyHud?.sync(); }
  dispose() { this.disposed=true;this._invitationSerial=(this._invitationSerial||0)+1;if(typeof this._partyUnsubscribe==='function')this._partyUnsubscribe();this.game.uiwin?.close?.('partyinvite','server');this.partyHud?.dispose(); }

  _invitationLease() {const n=this.game.network;return {id:n?.self?.id,generation:n?._leaseGeneration,token:n?.token};}
  _sameInvitationLease(lease) {const n=this.game.network;return !!lease&&lease.id===n?.self?.id&&lease.generation===n?._leaseGeneration&&lease.token===n?.token;}
  _liveInvitation() {
    const i=this.st.invite,n=this.game.network,c=n?._serverClock;
    const now=c?c.time+performance.now()-c.at:Date.now();
    return i&&(!Number.isFinite(i.expires)||i.expires>now)?i:null;
  }
  _currentInvitation(marker) {
    return !!marker&&marker.serial===this._invitationSerial&&this._sameInvitationLease(marker.lease)&&marker.key===invitationKey(this._liveInvitation());
  }
  _invitationButtons(w,on) {for(const id of ['btn_yes','btn_no','btn_exit'])w.control(id).setEnabled?.(on);}
  async _answerInvitation(w,operation) {
    const marker=w.data.partyInvitation;
    if(!this._currentInvitation(marker)){w.close('server');return false;}
    if(marker.busy)return false;
    marker.busy=true;this._invitationButtons(w,false);
    try {
      const sent=await this.command(operation);
      // Network.action applies the authoritative party snapshot before returning.
      // A refusal must keep this invitation visible, with its native retry buttons.
      if(!sent&&this._currentInvitation(marker))msg(this.game,'The party invitation is still pending. Try Accept or Decline again.','err');
      return sent;
    }catch(error){if(this._currentInvitation(marker))msg(this.game,error?.message||String(error),'err');return false;}
    finally{marker.busy=false;if(this._currentInvitation(marker))this._invitationButtons(w,true);}
  }
  _registerInvitation() {
    if(this._invitationRegistered)return;
    this._invitationRegistered=true;
    this.game.uiwin.registerWindow('partyinvite',{
      script:PARTY_INVITATION_SCRIPT,modal:true,escClose:true,remember:false,autoClose:false,
      create:w=>{
        w.control('btn_yes').onClick(()=>{void this._answerInvitation(w,'accept');});
        for(const id of ['btn_no','btn_exit'])w.control(id).onClick(()=>{void this._answerInvitation(w,'decline');});
      },
      beforeClose:(w,reason)=>{if(reason==='server'||reason==='replaced')return true;void this._answerInvitation(w,'decline');return false;},
      update:w=>{if(!this._currentInvitation(w.data.partyInvitation))w.close('server');},
    });
  }
  _syncInvitation() {
    const invitation=this._liveInvitation(),key=invitationKey(invitation),ui=this.game.uiwin;
    if(invitation&&declineBlockedInvitation(this.game,'blockParty',key,()=>this.command('decline'))) { ui.close?.('partyinvite','server'); return; }
    if(key===this._shownInvite&&(!key||this._sameInvitationLease(this._shownInvitationLease)))return;
    this._invitationSerial=(this._invitationSerial||0)+1;
    this._shownInvite=key;this._shownInvitationLease=this._invitationLease();
    ui.close?.('partyinvite',invitation?'replaced':'server');
    if(!invitation)return;
    const marker={invitation:{...invitation},key,lease:this._shownInvitationLease,serial:this._invitationSerial,busy:false};
    if(!ui.registerWindow||!ui.get||!ui.openWindow){
      // Minimal UI embedders can still answer using the same authored prompt;
      // the actual game uses the persistent, authoritative window below.
      Promise.resolve(ui.msgbox(invitation.from,{script:PARTY_INVITATION_SCRIPT,kind:'yesno',title:strNow(this.game,100,14),name:'partyinvite'})).then(async answer=>{
        if(this._currentInvitation(marker)&&!await this.command(answer==='yes'?'accept':'decline'))this._shownInvite=null;
      }).catch(error=>msg(this.game,error?.message||String(error),'err'));
      return;
    }
    this._registerInvitation();
    void ui.get('partyinvite').then(w=>{
      if(!this._currentInvitation(marker))return;
      w.data.partyInvitation=marker;w.control('lbl_text').setText(invitation.from);
      this._invitationButtons(w,true);ui.openWindow(w);
    }).catch(error=>{if(this._currentInvitation(marker)){this._shownInvite=null;msg(this.game,error?.message||String(error),'err');}});
  }

  _create(w) {
    this.win = w;
    const g = this.game;
    w.control('btn_createparty_toggle').onClick(() => void this._confirmToggle());
    // PARTY-FINDER: online the toggle is Find / Cancel / Recruit / Cancel (src/systems/network/party-finder.js)
    w.control('btn_partyFind_toggle').onClick(() => g.partyFinder ? g.partyFinder.toggle() : g.uiwin.open('partyfind'));
    // the item-distribution combo keeps the script's own items (70:16 [Default], 17 [In turn], 18 [Free], 19 [Random],
    // 184 [Leader]); a change reports "The Party's item share type is set to [..]." (70:15 + item + 70:20)
    const combo = w.control('combo_partyitemway');
    combo.onChange?.((i) => {
      if(g.save?.authority==='server'){if(i!==this.st.itemway)void this.command('itemway',{itemway:i});return;}
      this.st.itemway = i; g.persist?.();
      const item = strNow(g, 70, [16, 17, 18, 19, 184][i] ?? 16);
      if (this.active) msg(g, `${strNow(g, 70, 15) || "The Party's item share type is set to"} ${item}${strNow(g, 70, 20) || '.'}`, 'sys');
    });
    w.control('btn_info_itemway').setTooltip?.(() => strNow(g, 70, [179, 180, 181, 182, 185][this.st.itemway || 0] ?? 179) || strNow(g, 70, 15));
    const pop = w.control('pan_Popup');
    pop.hide();
    // no other member picked: Global's ui_partyleadertrust (70:28) instead of a chat line
    w.control('btn_changeleader').onClick(() => { pop.hide(); if(g.save?.authority==='server'&&this.selectedMember&&this.selectedMember!==g.network?.self?.id){void this.command('lead',{targetId:this.selectedMember});return;}void globalNotice(g, PARTY_DELEGATE_BOX); });
    w.control('btn_forceleave').onClick(() => { pop.hide();if(g.save?.authority==='server'){void this.command(this.selectedMember===g.network?.self?.id?'leave':'kick',{targetId:this.selectedMember});return;} this._toggleParty(false); });
    w.control('btn_partyname').onClick(async () => {
      if (!this.active) return;
      const v = await this._askName(PARTY_RENAME_TITLE, this.st.name);
      if (v == null || !String(v).trim()) return;
      if(g.save?.authority==='server'){await this.command('rename',{name:String(v).trim()});return;}
      this.st.name = String(v).trim().slice(0, 24);
      g.persist?.();
      msg(g, (strNow(g, 70, 4) || 'The Party has changed its name to %s.').replace('%s', this.st.name), 'sys');
      this._refresh(w);
    });
    // 7 rows on the 7 plates of the art: row k = the member slot (btn_slot_) or the empty row (pan_empty_), numbered
    // party_renew_num k+1 (active) / k+8 (inactive). cloneAs suffixes every descendant id (lbl_pcname_ -> lbl_pcname_0).
    const tpl = w.control('btn_slot_'), etpl = w.control('pan_empty_');
    // (user: the empty slot rows were drawn from the top of the window) the template box reads 0,0 here, so fall back
    // to the script's own rect "8 74 435 23" for the first plate.
    const x0 = tpl.box?.x || 8, y0 = tpl.box?.y || 74;
    this.slot = tpl.cloneAs('_0', { x: x0, y: y0 });
    this.slot.setEnabled(true);   // a live member row: hover / select frame (party#5), right click = member menu
    w.control('btn_move_0').hide();
    w.control('pan_partynum_0').setSprite('party_renew_num', 1);
    w.control('pan_login_0').setSprite('party_renew', 13);
    w.control('lbl_pcname_0').setTextColor('ffffffff');
    this._setupMemberRow(w, 0);
    this.slot.onRightClick?.((e) => {
      if (!this.active) return;
      const [x, y, , hh] = this.slot.rect();
      pop.setRect(x + 60, y + hh, 100, 50);
      pop.setVisible(!pop.isVisible());
    });
    if(g.save?.authority==='server'){
      this.memberSlots=[this.slot];
      for(let i=1;i<MAX_SLOTS;i++)this.memberSlots.push(tpl.cloneAs(`_${i}`,{x:x0,y:y0+ROW_PITCH*i}));
      this.memberSlots.forEach((slot,i)=>{
        // Every live member row needs the enabled hover/right-click state of row 0; disabled
        // clones ignored right-click, so Change Leader/Kick could never open for other members.
        slot.setEnabled(true);
        this._setupMemberRow(w, i);
        w.control(`btn_move_${i}`).hide();w.control(`pan_partynum_${i}`).setSprite('party_renew_num',i+1);
        // Party Warp (Holy Water PartyWarp): the original per-member btn_move_ (2000:77) starts the server-owned premium cast
        w.control(`btn_move_${i}`).onClick(()=>{const member=this.members[i];if(member&&member.id!==g.network?.self?.id)void g.premium?.warpToMember?.(member);});
        slot.onRightClick?.(()=>{const member=this.members[i];if(!member)return;this.selectedMember=member.id;const[x,y,,h]=slot.rect();pop.setRect(x+60,y+h,100,50);pop.show();});
      });
    }
    this.empties = [];
    for (let i = 0; i < MAX_SLOTS; i++) {
      const e = etpl.cloneAs(`_${i}`, { x: x0, y: y0 + ROW_PITCH * i });
      w.control(`pan_emptypartynum_${i}`).setSprite('party_renew_num', 8 + i);
      this.empties.push(e);
    }
  }

  _mapName(index) {
    const g = this.game;
    const row = Number(index) === Number(g.world?.info?.index) ? g.world?.info?.row : g.data?.mapByIndex?.(Number(index));
    return String(row?.Name || row?.name || (Number(index) === Number(g.world?.info?.index) ? g.world?.info?.name : '') || `Map ${index}`).trim();
  }

  _setupMemberRow(w, i) {
    // Authored HP controls default to hidden; expose them for populated rows.
    w.control(`hp_bg_${i}`).show();
    w.control(`hp_processbar_${i}`).show();
    // The authored 80px map field cuts off names such as Dead Front [Doom].
    // Keep the native row art/font while giving both fields non-overlapping space.
    const name = w.control(`lbl_pcname_${i}`);
    name.setRect(60, 0, 178, 23);
    name.setClip(true);
    name.setTooltip?.(() => this.members[i] ? `${this.members[i].name} · ${this.members[i].leader ? 'Leader · ' : ''}${strNow(this.game, 70, 92) || 'Lv'} ${this.members[i].level}` : '');
    const map = w.control(`lbl_mapname_${i}`);
    map.setRect(244, 0, 160, 23);
    map.setClip(true);
    map.setTooltip?.(() => this.members[i] ? this._mapName(this.members[i].map ?? this.game.world?.info?.index) : '');
  }

  /** Leaving asks first with Global's box: ui_partydisband (the leader) or ui_partysecession (a member). */
  async _confirmToggle() {
    const g = this.game;
    if (this.active) {
      const online = g.save?.authority === 'server';
      const leader = !online || this.st?.leaderId === g.network?.self?.id;
      if (!await globalAsk(g, leader ? 'partyDisband' : 'partySecede')) return false;
      this._toggleParty();
      return true;
    }
    // forming asks the slogan first ("Form Party"); Cancel forms nothing, an empty slogan keeps the default name
    const slogan = await this._askName(PARTY_FORM_TITLE, this._defaultName());
    if (slogan == null) return false;
    this._toggleParty(undefined, String(slogan).trim());
    return true;
  }

  _defaultName() { const g = this.game; return `${g.save?.name || g.player?.name || ''}${strNow(g, 70, 67) || "'s Party"}`; }
  /** The party name input (see PARTY_NAME_INPUT); resolves the text, or null when cancelled. */
  _askName(titleCode, value) {
    const g = this.game;
    return g.uiwin?.msgbox?.(strNow(g, 70, 27) || 'Party slogan', { kind: 'edit', script: PARTY_NAME_INPUT, window: 'partynameinput', title: strNow(g, 100, titleCode) || (titleCode === PARTY_FORM_TITLE ? 'Form Party' : 'Change Party Name'), value }) ?? null;
  }

  _toggleParty(force, name = '') {
    if(this.game.save?.authority==='server'){void this.command(this.active?'leave':'create',!this.active&&name?{name}:undefined);return;}
    const g = this.game, st = this.st;
    const on = force != null ? force : !st.active;
    if (on === st.active) return;
    st.active = on;
    const me = g.save?.name || g.player?.name || '';
    if (on && name) st.name = name.slice(0, 24);
    if (on && !st.name) st.name = `${me}${strNow(g, 70, 67) || "'s Party"}`;
    msg(g, on ? (strNow(g, 70, 59) || 'The Party has been formed.') : `${me} ${strNow(g, 70, 1) || 'has left the Party.'}`, 'sys');
    g.persist?.();
    g.events?.emit?.('life:party', { active: on });
    if (this.win?.isOpen) this._refresh(this.win);
  }

  _refresh(w) {
    const st = this.st, g = this.game;
    const partyWarp = !!g.premium?.any?.('partyWarp');
    const signature = JSON.stringify([st.active, st.name, st.itemway, st.leaderId, g.partyFinder?.toggleText?.(), this.members, g.network?.self?.id, g.world?.info?.index, g.world?.info?.row?.Name, g.world?.info?.name, partyWarp]);
    if (w.data.presentationSignature === signature) return;
    w.data.presentationSignature = signature;
    w.control('lbl_partyname').setText(st.active ? st.name : '');
    w.control('btn_partyname').setEnabled?.(st.active);
    // the two toggles carry no caption in the script: Find (70:76) / Create (70:33) or Leave (70:34)
    w.control('btn_partyFind_toggle').setText(g.partyFinder?.toggleText?.() || strNow(g, 70, 76) || 'Find');
    w.control('btn_createparty_toggle').setText(st.active ? (strNow(g, 70, 34) || 'Leave') : (strNow(g, 70, 33) || 'Create'));
    w.control('combo_partyitemway').select?.(st.itemway || 0);
    if(g.save?.authority==='server'){
      if (!st.active || !this.members.some(m => m.id === this.selectedMember)) w.control('pan_Popup').hide();
      const isLeader=st.leaderId===g.network?.self?.id;
      w.control('btn_partyname').setEnabled?.(isLeader);w.control('combo_partyitemway').setEnabled?.(isLeader);
      w.control('btn_changeleader').setEnabled?.(isLeader);w.control('btn_forceleave').setEnabled?.(isLeader);
      this.memberSlots.forEach((slot,i)=>{const member=this.members[i];slot.setVisible(!!member);if(!member)return;
        w.control(`lbl_pcname_${i}`).setText(`${member.leader?'★ ':''}${member.name}  Lv ${member.level}`);
        w.control(`lbl_mapname_${i}`).setText(this._mapName(member.map));
        const ci = Number(member.classIndex);
        w.control(`pan_classtype_${i}`).setSprite('etc_01',Number.isInteger(ci) && ci >= 0 && ci <= 14 ? 100+ci : 34);
        w.control(`pan_login_${i}`).setSprite('party_renew',13);
        w.control(`hp_processbar_${i}`).setGauge(member.maxHp>0?Math.max(0,Math.min(1,member.hp/member.maxHp)):0);
        const warp=partyWarp&&member.id!==g.network?.self?.id,move=w.control(`btn_move_${i}`);move.setVisible(warp);move.setEnabled?.(warp);
      });this.empties.forEach((e,i)=>e.setVisible(!this.members[i]));return;
    }
    this.slot.setVisible(st.active);
    if (!st.active) w.control('pan_Popup').hide();
    w.control('lbl_pcname_0').setText(`${g.save?.name || g.player?.name || ''}${st.active ? `  ${strNow(g, 70, 92) || 'Lv'} ${g.save?.level || 1}` : ''}`);
    w.control('lbl_mapname_0').setText(String(g.world?.info?.row?.Name || g.world?.info?.name || '').trim());
    const ci = Number(g.save?.classIndex);
    if (w.data.cls !== ci) { w.data.cls = ci; w.control('pan_classtype_0').setSprite('etc_01', Number.isFinite(ci) && ci >= 0 && ci <= 14 ? 100 + ci : 34); }
    const hp = g.player?.hp, mhp = g.player?.maxHp;
    if (mhp > 0) w.control('hp_processbar_0').setGauge(Math.max(0, Math.min(1, hp / mhp)));
    this.empties.forEach((e, i) => e.setVisible(!st.active || i > 0));
  }
  _tick(w) { if (w.isOpen) this._refresh(w); }

  _createFind(w) {
    this.findWin=w;
    if(this.game.save?.authority==='server'){w.control('btn_refresh')?.onClick(()=>{void this.game.network?.poll();});return;}
    w.control('lbl_msg')?.setVisible?.(true);
    w.control('lbl_msg')?.setText?.('No other players are online to recruit.');
    w.control('btn_refresh')?.onClick(() => {});
  }
  _refreshFind(w) {
    if(this.game.save?.authority==='server'){
      const rows=(this.st.connected||[]).filter(p=>p.id!==this.game.network?.self?.id),board=w.control('freeboard');
      const signature=JSON.stringify([rows,this.st.leaderId,this.active]);if(signature===this._findSignature)return;this._findSignature=signature;
      w.control('lbl_msg')?.setText?.(rows.length?'Select a connected character to invite. Create a party first.':'No other characters are connected.');
      const el=board?.el;if(el){el.replaceChildren();el.style.overflowY='auto';for(const member of rows){const button=document.createElement('button');button.type='button';button.textContent=`${member.name} · Lv ${member.level} · Map ${member.map}${member.inParty?' · In party':''}`;Object.assign(button.style,{display:'block',width:'100%',padding:'7px',background:'#18191f',border:'1px solid #71634c',color:'#eee0c7',textAlign:'left',cursor:'pointer'});button.disabled=member.inParty||!this.active||this.st.leaderId!==this.game.network?.self?.id;button.onclick=()=>{void this.command('invite',{targetId:member.id});};el.appendChild(button);}}
      return;
    }
    w.control('freeboard').setRows?.([]);   // honestly empty board: no other players exist to post a recruitment here
    w.control('lbl_msg')?.setText?.('No other players are online to recruit.');
  }
}
