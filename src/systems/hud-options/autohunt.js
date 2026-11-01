// Battle Support / AutoHunt bridge. The original window script is data-driven,
// but its Start button still needs a client controller. It only selects live
// monsters and calls the same controller/skill APIs as manual play; the shared
// server remains authoritative for range, cooldown, damage and rewards.

import {staminaState,consumeStamina,MINUTE_MS} from './stamina-rules.js';
import {slotIcon} from '../items/ui/common.js';
const RADII = [8, 12, 16, 20];
export const RADIUS_BY_ROW = [8, 12, 16];
const SKILL_ONLY = ['check_resetpos', 'check_normalattack', 'check_selftarget', 'check_nontarget', 'check_allskill', 'edit_return_time', 'lbl_return_time_second'];
const ITEM_ONLY = ['check_returntofield', 'check_allitem'];
const HOTKEY_ONLY = ['lbl_shortcut_key', 'lbl_shortcut_reg_key', 'lbl_shortcut_desc', 'lbl_keymap', 'btn_keymap'];
const NOT_HOTKEY = ['pan_startposname', 'lbl_startpos', 'pan_radius', 'lbl_radius'];
// tab button -> panels it shows (ids from ui_autohuntconfig.txt)
const TABS = [['btn_skill_tab', ['pan_skill']], ['btn_buff_tab', ['pan_skill']], ['btn_item_tab', ['pan_item']], ['btn_item_sp_tab', ['pan_item_sp']], ['btn_hotkey_tab', ['pan_hotkey']]];
const alive = m => !!m && m.kind === 'monster' && !m.dead && !m.disposed && Number(m.hp ?? 1) > 0;
// Potion Set (Potion/Scroll tab of ui_autohuntconfig.txt): HP set 1 / 2 and MP set 1 / 2 = a tick box, a % slider (with -/+ buttons) and a
// potion picker each. Original rule (stringtable_autohunt 370:68): "You can use the potion set only while the Holy Water of Almighty is
// active" (its item text 701: "Auto-use normal potion of Battle helper"). The Almighty services are the remote ones (StoreIndex / Post /
// Brokerage), the same test as the Holy Water menu. While Battle Support runs, a ticked set uses its chosen potion when HP / MP is below
// the slider %. ENGINE-CHOSEN: the slider defaults (50 % / 30 %), the 5 % step of -/+, and at most one try per set per second.
export const POTION_SETS = [
  { key: 'hp1', kind: 'hp', check: 'check_hp1', slider: 'sld_hp1', combo: 'com_hp_sp_1', clear: 'btn_hp_sp_1_clear', pct: 50 },
  { key: 'hp2', kind: 'hp', check: 'check_hp2', slider: 'sld_hp2', combo: 'com_hp_sp_2', clear: 'btn_hp_sp_2_clear', pct: 30 },
  { key: 'mp1', kind: 'mp', check: 'check_mp1', slider: 'sld_mp1', combo: 'com_mp_sp_1', clear: 'btn_mp_sp_1_clear', pct: 50 },
  { key: 'mp2', kind: 'mp', check: 'check_mp2', slider: 'sld_mp2', combo: 'com_mp_sp_2', clear: 'btn_mp_sp_2_clear', pct: 30 },
];
export const POTION_SET_TEXT = 'You can use the potion set only while the Holy Water of Almighty is active.';   // 370:68
export const almightyActive = game => ['storeIndex', 'post', 'brokerage'].some(k => !!game?.premium?.any?.(k));
/** Owned potions of a kind ('hp' | 'mp'): one row per item index, [{value: itemIndex, text: 'name (count)'}]. */
export function ownedPotions(game, kind) {
  const bag = game?.items?.bag, db = game?.items?.db, rows = new Map();
  for (const inst of bag?.list || []) {
    const def = db?.def?.(inst.itemIndex), use = def?.use;
    if (!def || !use || inst.expiresAt && inst.expiresAt < Date.now()) continue;
    if (!(Number(use[kind]) > 0)) continue;
    const r = rows.get(inst.itemIndex) || { value: inst.itemIndex, name: def.name, count: 0 };
    r.count += Number(inst.count) || 1; rows.set(inst.itemIndex, r);
  }
  return [...rows.values()].map(r => ({ value: r.value, text: `${r.name} (${r.count})` }));
}
/** The potion set that should fire now, or null (pure: hp / mp / maxima, the sets, last-try times). */
export function potionToUse({ hp, maxHp, mp, maxMp }, sets, now, lastTry = {}) {
  for (const s of sets) {
    if (!s.on || !s.item) continue;
    const cur = s.kind === 'hp' ? hp : mp, max = s.kind === 'hp' ? maxHp : maxMp;
    if (!(max > 0) || cur / max * 100 >= s.pct) continue;
    if (now - (lastTry[s.key] ?? -Infinity) < 1000) continue;
    return s;
  }
  return null;
}

export function selectTarget(game, radius = 12, origin = game?.player) {
  const p = game?.player;
  if (!p) return null;
  const source = game.network?.active ? [...(game.network.monsters?.values?.() || [])] : [...(game.spawner?.monsters || [])];
  const map = Number(game.world?.info?.index);
  return source.filter(m => alive(m) && (m.map == null || Number(m.map) === map))
    .map(m => ({ m, d: Math.hypot(Number(m.x) - origin.x, Number(m.z) - origin.z) }))
    .filter(row => Number.isFinite(row.d) && row.d <= radius)
    .sort((a, b) => a.d - b.d)[0]?.m || null;
}

function skillFromHotbar(game, slot) {
  const row = game?.save?.hotbar?.[Number(slot)];
  if (!row || row.type === 'item') return null;
  const id = Number(row.skillIndex ?? row.index ?? row.id);
  return Number.isInteger(id) && id > 0 ? id : null;
}

export class AutoHunt {
  constructor(game) {
    this.game = game; this.active = false; this.radius = 12; this.skillSlot = 0;
    this.skillEnabled = true; this.itemEnabled = false; this.normalAttack = true; this.tab = 'btn_skill_tab'; this.target = null; this.next = 0; this.win = null; this._bound = new WeakSet();
    this.potionSets = POTION_SETS.map(s => ({ ...s, on: false, item: null })); this.potionTry = {};
    // Native UI: 14 shared controls on Skill Set 1/2, three com_preset rows. Publisher guide confirms 28 ordered
    // entries, duplicates allowed, per-entry enable and cooldown >= skill's authored cooldown:
    // https://wiki.papayaplay.com/dekaron/doku.php?id=battlesupport
    this.preset = 0; this.presets = Array.from({ length: 3 }, () => Array(28).fill(null)); this.cursor = 0;
    this.selfTarget = false; this.returnEnabled = false; this.returnSeconds = 180; this.origin = null; this.returnAt = 0; // current Global guide31 default3min.
    this.settingsKey = String(game.save?.id || 'guest'); this.returning = false;
    this.autoReturn = false; this.startGeneration = 0; this.starting = false; this.offlineProfile = game.save || {};
    this.itemSets=Array.from({length:3},()=>Array(10).fill(null));this.hotkeys=Array(10).fill(null);this.itemCursor=0;this.itemFlight=false;this.hotkeyBusy=false;this.itemNext=0;
    const saved = game.settings?.battleSupport?.[this.settingsKey];
    for(let n=0;n<3;n++)for(let i=0;i<10;i++){const row=saved?.itemSets?.[n]?.[i];if(Number.isSafeInteger(row?.index)&&row.index>0)this.itemSets[n][i]={index:row.index,on:row.on!==false,mode:['cooldown','duration','seconds'].includes(row.mode)?row.mode:'duration',seconds:Math.max(0,Math.min(9999,Number(row.seconds)||0)),last:null};}
    for(let i=0;i<10;i++){const row=saved?.hotkeys?.[i];if(Number.isSafeInteger(row?.index)&&row.index>0&&!this.hotkeys.some(e=>e?.index===row.index))this.hotkeys[i]={index:row.index,on:row.on!==false};}
    if (Array.isArray(saved?.presets)) for (let n = 0; n < 3; n++) for (let i = 0; i < 28; i++) {
      const entry = saved.presets[n]?.[i];
      if (Number.isSafeInteger(entry?.index) && entry.index > 0) this.presets[n][i] = { index: entry.index, on: entry.on !== false, seconds: Math.max(0, Math.min(9999, Number(entry.seconds) || 0)), last: null };
    }
    const self = this;
    game.autoHunt = { get active() { return self.active; }, get target() { return self.target; }, start: () => self.start(), stop: () => self.stop(), toggle: () => self.active||self.starting ? self.stop() : self.start(), hotkeyItems:()=>self.useHotkeys(), setRadius: value => { self.radius = RADII.includes(Number(value)) ? Number(value) : 12; self.paint(); } };
  }
  register() {
    const ui = this.game.uiwin; if (!ui || ui.has('autohunt')) return;
    // The HUD system ticks the service every frame even when the option window
    // is minimized, so a hidden panel cannot pause an active hunt.
    // ui_autohuntconfig.txt is the script whose art matches the shipped imagetable (auto_hunt 1..20, 497 px wide
    // panel + etc_01 close button + tabs). The older autohuntoption.txt is an art-less debug layout ("AutoHunt Wnd")
    // and ui_autohuntoption.txt references auto_hunt indices 22/23/26-29 that do not exist in imagetable.txt.
    ui.registerWindow('autohunt', { script: 'game2/autohunt/ui_autohuntconfig.txt', remember: true, create: win => this.bind(win), onOpen: win => { this.bind(win); this.paint(); }, onClose: () => { this.win = null; } });
    // Original HUD alarm (autohunt/ui_autohunt_alarm.txt, 90 100 under the clock) opens the Battle Support window.
    ui.registerWindow('autohunt_alarm', { script: 'game2/autohunt/ui_autohunt_alarm.txt', hud: true, band: 'hud', escClose: false, remember: false,
      create: win => win.control('btn_alarm')?.onClick?.(() => ui.toggle('autohunt')) });
    this.game.events?.on?.('map', () => { if (!ui.isOpen('autohunt_alarm')) ui.open('autohunt_alarm'); });
  }
  bind(win) {
    this.win = win; if (this._bound.has(win)) return; this._bound.add(win); const c = id => win.control(id);
    c('btn_going')?.onClick?.(() => this.toggle()); c('btn_exit')?.onClick?.(() => { this.stop(); win.close('close'); });
    // com_radius rows 0/1/2 = Narrow / Middle / Wide Range (stringtable_autohunt 370:13-15). The script carries no metres;
    // RADIUS_BY_ROW reuses the 8/12/16 steps of the legacy script's radius buttons. ENGINE-CHOSEN.
    c('com_radius')?.onChange?.(row => this.setRadius(RADIUS_BY_ROW[Number(row)] ?? 12));
    c('check_normalattack')?.onClick?.(() => { this.normalAttack = !!c('check_normalattack').isChecked(); });
    c('com_preset')?.onChange?.(row => { const n = Number(row); if (!Number.isInteger(n) || n < 0 || n > 2) return; this.preset = n; this.cursor = 0; this.itemCursor=0;this.paintSkills();this.paintItems(); });
    c('check_selftarget')?.onClick?.(() => { this.selfTarget = !!c('check_selftarget')?.isChecked?.(); });
    c('check_resetpos')?.onClick?.(() => { this.returnEnabled = !!c('check_resetpos')?.isChecked?.(); });
    c('check_returntofield')?.onClick?.(() => { this.autoReturn = !!c('check_returntofield')?.isChecked?.(); });
    c('btn_keymap')?.onClick?.(()=>this.game.uiwin?.open?.('keymap'));
    c('edit_return_time')?.on?.('change', value => { this.returnSeconds = Math.max(0, Math.min(9999, Number(value) || 0)); });
    c('check_allskill')?.onClick?.(() => { const on = !!c('check_allskill')?.isChecked?.(); for (const entry of this.presets[this.preset]) if (entry) entry.on = on; this.saveSkills(); this.paintSkills(); });
    c('check_allitem')?.onClick?.(()=>{const on=!!c('check_allitem')?.isChecked?.();for(const entry of this.itemSets[this.preset])if(entry)entry.on=on;this.saveSkills();this.paintItems();});
    // The five tabs (Skill Set 1/2, Item, Potion/Scroll, Hotkey) each own one panel in the script.
    TABS.forEach(([tab]) => c(tab)?.onClick?.(() => this.showTab(tab)));
    for (let i = 0; i < 14; i++) {
      c(`skill_slot_${i}`)?.acceptDrop?.({ accept: data => this.registrationSkill(data) !== null, drop: data => this.registerSkill(i, data) });
      c(`skill_slot_${i}`)?.on?.('rclick', () => { this.presets[this.preset][this.skillPage() * 14 + i] = null; this.saveSkills(); this.paintSkills(); });
      c(`check_skill_${i}`)?.onClick?.(() => { const entry = this.skillEntry(i); if (entry) { entry.on = !!c(`check_skill_${i}`)?.isChecked?.(); this.saveSkills(); } });
      c(`edit_skill_${i}`)?.on?.('change', value => { const entry = this.skillEntry(i); if (entry) { entry.seconds = Math.max(this.skillCooldown(entry.index), Math.min(9999, Number(value) || 0)); c(`edit_skill_${i}`)?.setValue?.(entry.seconds); this.saveSkills(); } });
    }
    for(let i=0;i<10;i++){
      for(const [id,hotkey]of [[`btn_item_${i}`,false],[`hotkey_${i}`,true]]){
        c(id)?.acceptDrop?.({accept:data=>!!this.registrationItem(data)&&(!hotkey||!this.hotkeyBusy),drop:data=>this.registerItem(i,data,hotkey)});
        c(id)?.on?.('rclick',()=>{if(hotkey&&this.hotkeyBusy)return;(hotkey?this.hotkeys:this.itemSets[this.preset])[i]=null;this.saveSkills();this.paintItems();});
      }
      c(`check_item_${i}`)?.onClick?.(()=>{const entry=this.itemSets[this.preset][i];if(entry){entry.on=!!c(`check_item_${i}`)?.isChecked?.();this.saveSkills();}});
      c(`check_hotkey_${i}`)?.onClick?.(()=>{const entry=this.hotkeys[i];if(entry&&!this.hotkeyBusy){entry.on=!!c(`check_hotkey_${i}`)?.isChecked?.();this.saveSkills();}});
      c(`combobox_item_${i}`)?.setItems?.([{value:'cooldown',text:'Repeat Cool Time'},{value:'duration',text:'Repeat Duration Time'},{value:'seconds',text:'Per second.'}]); // native370:8/9/28.
      c(`combobox_item_${i}`)?.onChange?.((row,item)=>{const entry=this.itemSets[this.preset][i],mode=item?.value||['cooldown','duration','seconds'][row];if(entry&&['cooldown','duration','seconds'].includes(mode)){entry.mode=mode;this.saveSkills();this.paintItems();}});
      c(`edit_item_${i}`)?.on?.('change',value=>{const entry=this.itemSets[this.preset][i];if(entry){entry.seconds=Math.max(this.itemCooldown(entry.index)/1000,Math.min(9999,Number(value)||0));this.saveSkills();this.paintItems();}});
      c(`btn_hotkey_${i}`)?.onClick?.(()=>{if(!this.hotkeyBusy){this.hotkeys[i]=null;this.saveSkills();this.paintItems();}});
    }
    for (const s of this.potionSets) {
      c(s.slider)?.setRange?.(1, 99); c(s.slider)?.setValue?.(s.pct);
      c(s.slider)?.on?.('change', v => { s.pct = Math.max(1, Math.min(99, Number(v) || s.pct)); });
      for (const [id, d] of [[s.slider + '_minus', -5], [s.slider + '_plus', 5]]) c(id)?.onClick?.(() => { s.pct = Math.max(1, Math.min(99, s.pct + d)); c(s.slider)?.setValue?.(s.pct); });
      c(s.combo)?.onChange?.((row, it) => { s.item = it?.value ?? null; });
      c(s.clear)?.onClick?.(() => { s.item = null; c(s.combo)?.select?.(-1); });
      c(s.check)?.onClick?.(() => {
        const want = !!c(s.check)?.isChecked?.();
        if (want && !almightyActive(this.game)) { c(s.check)?.setChecked?.(false); s.on = false; this.game.hud?.log?.(POTION_SET_TEXT) ?? this.game.chat?.system?.(POTION_SET_TEXT); return; }
        s.on = want;
      });
    }
    this.showTab(this.tab);
  }
  skillPage() { return this.tab === 'btn_buff_tab' ? 1 : 0; }
  saveSkills() {
    if (!this.game.setSettings) return;
    const presets = this.presets.map(rows => rows.map(entry => entry ? { index: entry.index, on: entry.on, seconds: entry.seconds } : null));
    const itemSets=this.itemSets.map(rows=>rows.map(row=>row?{index:row.index,on:row.on,mode:row.mode,seconds:row.seconds}:null)),hotkeys=this.hotkeys.map(row=>row?{index:row.index,on:row.on}:null);
    this.game.setSettings({ battleSupport: { ...(this.game.settings?.battleSupport || {}), [this.settingsKey]: { presets,itemSets,hotkeys } } });
  }
  ownedItem(index,now=this.now()){return(this.game.items?.bag?.list||[]).find(inst=>inst.itemIndex===index&&(inst.count??1)>0&&!(inst.expiresAt&&inst.expiresAt<=now));}
  itemCooldown(index){return Math.max(0,Number(this.game.items?.db?.def?.(index)?.appraisal)||0);}
  itemDuration(index){const db=this.game.items?.db,def=db?.def?.(index);return Math.max(0,Number(db?.T?.itemStatus?.[def?.use?.itemStatus]?.lifeTimeMs)||0);}
  registrationItem(data){
    if(data?.kind!=='item'&&data?.type!=='item')return null;const index=Number(data.itemIndex??data.inst?.itemIndex??data.index),def=this.game.items?.db?.def?.(index);
    return Number.isSafeInteger(index)&&index>0&&def?.use?.itemStatus!=null&&this.ownedItem(index)?def:null; // native370:33 buff items only.
  }
  registerItem(row,data,hotkey=false){
    const def=this.registrationItem(data);if(!def||!Number.isInteger(row)||row<0||row>=10||hotkey&&this.hotkeyBusy)return false;
    if(hotkey&&this.hotkeys.some((entry,i)=>i!==row&&entry?.index===def.index))return false; // native370:65.
    (hotkey?this.hotkeys:this.itemSets[this.preset])[row]=hotkey?{index:def.index,on:true}:{index:def.index,on:true,mode:'duration',seconds:this.itemCooldown(def.index)/1000,last:null};
    void this.game.items.db.tables?.().then?.(()=>this.paintItems());this.saveSkills();this.paintItems();return true;
  }
  paintItems(){
    const w=this.win,g=this.game;if(!w)return;
    w.control('lbl_shortcut_reg_key')?.setText?.(g.keymap?.get?.('hotkeyitem')||'Unbound');
    for(let i=0;i<10;i++){
      const entry=this.itemSets[this.preset][i],def=entry&&g.items?.db?.def?.(entry.index),hot=this.hotkeys[i],hd=hot&&g.items?.db?.def?.(hot.index);
      for(const [id,row]of [[`btn_item_${i}`,entry],[`hotkey_${i}`,hot]]){const ctrl=w.control(id),inst=row&&this.ownedItem(row.index);if(ctrl&&g.items?.icons)slotIcon(g.items,ctrl,inst);else if(!inst)ctrl?.setIcon?.(null);}
      for(const prefix of ['lbl_item_name_','lbl_item_cool_','edit_item_','check_item_','combobox_item_'])w.control(prefix+i)?.setVisible?.(!!def);
      if(def){w.control(`lbl_item_name_${i}`)?.setText?.(def.name);w.control(`check_item_${i}`)?.setChecked?.(entry.on);w.control(`combobox_item_${i}`)?.selectValue?.(entry.mode);w.control(`edit_item_${i}`)?.setValue?.(Math.max(entry.seconds,this.itemCooldown(entry.index)/1000));w.control(`edit_item_${i}`)?.setEnabled?.(entry.mode==='seconds');w.control(`lbl_item_cool_${i}`)?.setText?.('sec');}
      w.control(`lbl_hotkey_name_${i}`)?.setText?.(hd?.name||'');w.control(`check_hotkey_${i}`)?.setChecked?.(!!hot?.on);
    }
  }
  async itemStep(now=this.now()){
    if(!this.active||this.itemFlight||now<this.itemNext)return false;
    if(this.game.network?.active&&(!this.game.network.ready||!this.game.network.self?.battleSupport?.active))return false;
    const rows=this.itemSets[this.preset];
    for(let offset=0;offset<10;offset++){
      const at=(this.itemCursor+offset)%10,entry=rows[at];if(!entry?.on)continue;const inst=this.ownedItem(entry.index,now);if(!inst)continue;
      const period=entry.mode==='duration'?this.itemDuration(entry.index):entry.mode==='seconds'?Math.max(this.itemCooldown(entry.index),entry.seconds*1000):this.itemCooldown(entry.index);
      if(entry.mode==='duration'&&(this.game.save?.buffs||[]).some(buff=>buff.key===`item:${entry.index}`&&(buff.expiresAt!=null?buff.expiresAt>now:buff.remaining>0)))continue;
      if(entry.mode==='duration'&&!(period>0)||entry.last!=null&&now-entry.last<period)continue;
      this.itemFlight=true;this.itemNext=now+250; // ENGINE-CHOSEN request pacing, one ordinary item intent at a time.
      try{const ok=!!await this.game.items?.use?.(inst);if(ok){entry.last=now;this.itemCursor=(at+1)%10;}return ok;}catch(error){this.game.chat?.system?.(error.message,'err');return false;}finally{this.itemFlight=false;}
    }
    return false;
  }
  async useHotkeys(){
    const g=this.game;if(this.hotkeyBusy||this.itemFlight||g.player?.dead||g.network?.active&&(!g.network.ready||!g.network.token))return false;
    this.hotkeyBusy=true;let used=false;const owner=g.save?.id,network=g.network,token=network?.token;
    try{for(const entry of this.hotkeys){if(g.player?.dead||g.save?.id!==owner||g.network!==network||network?.active&&network.token!==token)break;if(!entry?.on)continue;const inst=this.ownedItem(entry.index);try{if(inst&&await g.items?.use?.(inst))used=true;}catch(error){g.chat?.system?.(error.message,'err');}}return used;}finally{this.hotkeyBusy=false;}
  }
  skillEntry(row) { return this.presets[this.preset][this.skillPage() * 14 + row]; }
  registrationSkill(data) {
    if (data?.type !== 'skill' && data?.kind !== 'skill') return null;
    const index = Number(data.skillIndex ?? data.index), skills = this.game.skills, def = skills?.skillDef?.(index);
    return Number.isSafeInteger(index) && index > 0 && def && skills.skillLevel?.(index) > 0 && !skills.isPassive?.(def) ? def : null;
  }
  skillCooldown(index) {
    const skills = this.game.skills, def = skills?.skillDef?.(index), row = def && skills.levelData?.(def, skills.skillLevel?.(index));
    return Math.max(0, Number(row?.cooldownMs ?? def?.cooldownMs) || 0) / 1000;
  }
  registerSkill(row, data) {
    const def = this.registrationSkill(data); if (!def || !Number.isInteger(row) || row < 0 || row >= 14) return false;
    this.presets[this.preset][this.skillPage() * 14 + row] = { index: def.index, on: true, seconds: this.skillCooldown(def.index), last: null };
    this.saveSkills(); this.paintSkills(); return true;
  }
  paintSkills() {
    const w = this.win; if (!w) return;
    for (let i = 0; i < 14; i++) {
      const entry = this.skillEntry(i), skills = this.game.skills, def = entry && skills?.skillDef?.(entry.index);
      w.control(`skill_slot_${i}`)?.setIcon?.(def ? { sprite: ['skill_icon', Number(def.iconIndex ?? def.index)] } : null);
      for (const prefix of ['lbl_skill_name_', 'lbl_skill_num_', 'lbl_skill_cool_', 'lbl_skill_mp_', 'edit_skill_', 'check_skill_']) w.control(prefix + i)?.setVisible?.(!!def);
      // Native lock option remains hidden: its effect on reduced skill cooldown is not established by the files/guide.
      w.control(`check_skilllock_${i}`)?.setVisible?.(false);
      if (!def) continue;
      const level = skills.skillLevel?.(entry.index), row = skills.levelData?.(def, level);
      w.control(`lbl_skill_name_${i}`)?.setText?.(def.name || `#${def.index}`);
      w.control(`lbl_skill_num_${i}`)?.setText?.(`Lv ${level}`);
      w.control(`lbl_skill_mp_${i}`)?.setText?.(`MP ${Number(row?.mp ?? def.mpCost) || 0}`);
      w.control(`edit_skill_${i}`)?.setValue?.(Math.max(entry.seconds, this.skillCooldown(entry.index)));
      w.control(`check_skill_${i}`)?.setChecked?.(entry.on);
    }
  }
  /** One successful cast advances the ordered 28-slot sequence. The ordinary skill API validates every cast. */
  skillStep(now = Date.now()) {
    const g = this.game, skills = g.skills, entries = this.presets[this.preset];
    if (!this.skillEnabled || !skills?.useSkill || skills.busy || skills.casting) return false;
    for (let offset = 0; offset < entries.length; offset++) {
      const at = (this.cursor + offset) % entries.length, entry = entries[at]; if (!entry?.on) continue;
      const def = skills.skillDef?.(entry.index); if (!def || !(skills.skillLevel?.(entry.index) > 0) || skills.isPassive?.(def)) continue;
      if (entry.last != null && now - entry.last < Math.max(entry.seconds, this.skillCooldown(entry.index)) * 1000) continue;
      if (skills.usability && !skills.usability(entry.index)?.ok) continue;
      const mask = Number(def.targetMask) || (def.target || []).reduce((a, b) => a | b, 0);
      const target = this.selfTarget && (mask & (2 | 16)) ? g.player : this.target;
      if (!target && !(mask & (8 | 16))) continue;
      if (skills.useSkill(entry.index, { target })) { entry.last = now; this.cursor = (at + 1) % entries.length; return true; }
    }
    return false;
  }
  returnToOrigin() {
    const p = this.game.player, at = this.origin;
    if (!at || Number(this.game.world?.info?.index) !== at.map) return false;
    if (Math.hypot(p.x - at.x, p.z - at.z) <= .3) { this.returning = false; return false; }
    if (this.game.controller?.order?.type !== 'move') this.returning = !!this.game.controller?.moveTo?.(at.x, at.z);
    else this.returning = true;
    return this.returning;
  }
  /** Fill the potion pickers with what the bag holds now (keeps a still-owned choice). */
  fillPotions() {
    const w = this.win; if (!w) return;
    for (const s of this.potionSets) {
      const combo = w.control(s.combo); if (!combo?.setItems) continue;
      combo.setItems(ownedPotions(this.game, s.kind));
      if (s.item != null && combo.items?.some?.(it => it.value === s.item)) combo.selectValue?.(s.item); else { s.item = null; combo.select?.(-1); }
    }
  }
  /** One Potion Set step (Battle Support running): the first ticked set below its % uses its potion; no Holy Water = no sets. */
  potionStep(now = Date.now()) {
    const g = this.game, p = g.player; if (!p || p.dead) return false;
    if (!almightyActive(g)) { for (const s of this.potionSets) s.on = false; return false; }
    const s = potionToUse({ hp: p.hp, maxHp: p.maxHp, mp: p.mp, maxMp: p.maxMp }, this.potionSets, now, this.potionTry);
    if (!s) return false;
    this.potionTry[s.key] = now;
    const inst = (g.items?.bag?.list || []).find(i => i.itemIndex === s.item && !(i.expiresAt && i.expiresAt < now));
    if (!inst) { s.item = null; return false; }
    void g.items?.use?.(inst);
    return true;
  }
  showTab(tab) {
    const w = this.win; if (!w) return; this.tab = tab;
    const shown = new Set(TABS.find(t => t[0] === tab)?.[1] || []);
    for (const [id, panels] of TABS) { w.control(id)?.setChecked?.(id === tab); for (const p of panels) w.control(p)?.setVisible?.(shown.has(p)); }
    // The script stacks controls of different tabs on the same rectangle (Start Location / Farming range vs the
    // shortcut text at y 88-108; Auto Return / Select All vs Reset/Self-target at y 134-158), so each group is
    // shown only on the tab(s) it belongs to. Which tab owns a group is read from the overlap in the script.
    const sets = tab === 'btn_skill_tab' || tab === 'btn_buff_tab', items = tab === 'btn_item_tab', hot = tab === 'btn_hotkey_tab';
    const vis = (ids, on) => ids.forEach(id => w.control(id)?.setVisible?.(on));
    vis(SKILL_ONLY, sets); vis(ITEM_ONLY, items); vis(HOTKEY_ONLY, hot); vis(NOT_HOTKEY, !hot); this.paintSkills();this.paintItems(); }
  toggle() { return this.active ? this.stop() : this.start(); }
  setRadius(radius) { this.radius = RADII.includes(Number(radius)) ? Number(radius) : 12; this.paint(); }
  start() {
    const g = this.game; if (!g.player || g.player.dead || this.starting) return false;
    if(g.network?.active){
      const net=g.network,token=net.token,generation=++this.startGeneration;
      if(!net.ready||!token||typeof net.action!=='function')return false;
      this.starting=true;
      return net.action('battlesupport',{operation:'start'}).then(result=>{
        if(g.network!==net||net.token!==token)return false;
        if(generation!==this.startGeneration){if(result)void net.action('battlesupport',{operation:'stop'});return false;}
        if(!result||!net.self?.battleSupport?.active)return false;
        return this.activate();
      }).catch(error=>{g.chat?.system?.(error.message,'err');return false;}).finally(()=>{if(generation===this.startGeneration)this.starting=false;});
    }
    staminaState(this.offlineProfile,this.now());if(!almightyActive(g)&&!(this.offlineProfile.stamina>0))return false;
    return this.activate();
  }
  now(){return typeof this.game.now==='function'?this.game.now():Date.now();}
  activate(){
    const g=this.game;this.active=true;
    this.origin = { x: g.player.x, z: g.player.z, map: Number(g.world?.info?.index) }; this.returnAt = Date.now(); this.cursor = 0;
    this.returning = false;
    for (const entry of this.presets[this.preset]) if (entry) entry.last = null;
    this.target = selectTarget(g, this.radius, this.origin); this.next = 0;
    g.events?.emit?.('autohunt', { active: true, target: this.target }); this.paint(); return true;
  }
  stop(notify=true) {
    ++this.startGeneration;this.starting=false;
    if (!this.active && !this.target) return false; this.active = false; this.target = null; this.next = 0; this.game.controller?.stop?.();
    if(notify&&this.game.network?.active)void this.game.network.action?.('battlesupport',{operation:'stop'}).catch?.(()=>{});
    this.game.events?.emit?.('autohunt', { active: false }); this.paint(); return true;
  }
  depleted(){
    this.stop(false);if(!this.autoReturn)return;
    const g=this.game,now=this.now(),scroll=(g.items?.bag?.list||[]).find(inst=>!(inst.expiresAt&&inst.expiresAt<=now)&&Number(g.items?.db?.def?.(inst.itemIndex)?.use?.teleport)===0);
    if(scroll)void g.items?.use?.(scroll); // ordinary owned-item API applies map, PK, cooldown and travel rules.
  }
  update(dt = 0) {
    if (!this.active) return; const g = this.game, p = g.player; if (!p || p.dead) { this.stop(); return; }
    if(g.network?.active){const state=g.network.self?.battleSupport;if(!g.network.ready||!state?.active){if(state&&state.stamina<=0&&!state.unlimited)this.depleted();else this.stop(false);return;}}
    else{
      const state=staminaState(this.offlineProfile,this.now());
      if(!almightyActive(g)){state.partialMs+=Math.max(0,Number(dt)||0)*1000;const cost=Math.floor(state.partialMs/MINUTE_MS);if(cost){consumeStamina(this.offlineProfile,cost,this.now());state.partialMs%=MINUTE_MS;}if(!(this.offlineProfile.stamina>0)){this.depleted();return;}}
    }
    if (this.origin && Number(g.world?.info?.index) !== this.origin.map) { this.stop(); return; }
    this.potionStep();
    void this.itemStep();
    this.next -= Number(dt) || 0; if (this.next > 0) return;
    if (g.skills?.busy || g.skills?.casting || g.controller?.order?.type === 'approach') { this.next = 0.25; return; }
    const now = Date.now();
    if (this.returning && this.returnToOrigin()) { this.next = .25; return; }
    if (this.returnEnabled && this.returnSeconds > 0 && now - this.returnAt >= this.returnSeconds * 1000) { this.returnAt = now; this.target = null; if (this.returnToOrigin()) { this.next = .25; return; } }
    if (!alive(this.target) || (this.target.map != null && Number(this.target.map) !== Number(g.world?.info?.index))) { this.target = selectTarget(g, this.radius, this.origin || p); if (this.target) g.controller?.setTarget?.(this.target); }
    let issued = this.skillStep(now);
    // Legacy integrations may still supply a hotbar slot when no native entries have been registered.
    const skill = !this.presets[this.preset].some(Boolean) && this.skillEnabled ? skillFromHotbar(g, this.skillSlot) : null;
    if (!issued && this.target && skill && typeof g.skills?.useSkill === 'function') issued = !!g.skills.useSkill(skill, { target: this.target });
    if (!issued && this.target && this.normalAttack && g.controller?.order?.type !== 'attack') issued = !!g.controller?.attack?.(this.target);
    if (!issued && !this.target) issued = this.returnToOrigin();
    this.next = issued ? 0.25 : 0.5;
  }
  paint() {
    const w = this.win; if (!w) return; w.control('btn_going')?.setChecked?.(this.active); w.control('check_normalattack')?.setChecked?.(this.normalAttack);
    w.control('check_selftarget')?.setChecked?.(this.selfTarget); w.control('check_resetpos')?.setChecked?.(this.returnEnabled); this.paintSkills();
    w.control('check_returntofield')?.setChecked?.(this.autoReturn);
    const row = RADIUS_BY_ROW.indexOf(this.radius); if (row >= 0) w.control('com_radius')?.select?.(row);
    this.fillPotions();
    this.paintItems();
    for (const s of this.potionSets) { w.control(s.check)?.setChecked?.(s.on); w.control(s.slider)?.setValue?.(s.pct); }
  }
  dispose() { this.stop(); this.game.autoHunt = null; this.win = null; }
}

export function installAutoHunt(game) { const service = new AutoHunt(game); service.register(); return service; }
