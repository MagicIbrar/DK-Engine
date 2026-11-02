// Supply machines (docs/formats/shops.md 3.3 "Supply machine"; strings cate 90/96):
//   orbis      the Orbis of Destiny, the single supply machine: privatesupply/ui_privatesupplywnd.txt
//              (NPC Tes / Grina "[Supplied Machine]", menu btn_single_supplymachine, HUD alarm
//              privatesupply/ui_privatesupplywnd_alarm.txt for Lv 80+). 10 slots around the turntable
//              (privatesupply#2 "rotating plate") = grade 1 x1, 2 x1, 3 x3, 4 x5 drawn by register_rate from
//              single_supplymachine_details.csv; a spin costs 1 Gear wheel (1756038 / 1192509 / 1756037) and wins one
//              remaining slot by win_rate (the plate stops with it under the needle privatesupply#3); won slots empty;
//              10 spins a day (gauge "%d / %d times" 96/105); daily re-initialisation at 00:00; "Mixing orders"
//              (btn_sort, 500,000 dil, 96/111) reshuffles the slot order. Level 80+ (96/5).
//   fieldboss  the field-boss roulette (fieldbosssupply/ui_fieldbosssupplywnd.txt): the same plate with the 10 fixed
//              fieldboss_supplymachine.csv prizes; weights per million (they sum to 1,000,000); pays 1 Gear wheel.
//   machine    the multi supply machine (supplymachine/ui_supplymachinewnd.txt, menu btn_supplymachine): all nine
//              machines ship Enable 0 / Usable 0 (server-fed in the original), so every machine shows "CLOSED"
//              (91/4) and Start answers 90/32; "extra purchase" (btn_addcash 90/6) opens the D-Shop.
import { T, itemInfo, itemInfoFull, itemIcon, itemTooltip, bag, dil, addDil, str, say, notice, confirmBox, fmtNum, COLORS, uiSound, weightedPick } from './common.js';
import { gfxC } from '../../ui/gfx-parity-c.js';
import {atlas} from '../../ui/atlas.js';
import {repairNativeShopStateArt} from '../../ui/native-shop-state-art.js';
import {
  ORBIS_PAY_ITEMS, ORBIS_SLOTS, ORBIS_DAILY, ORBIS_MIX_COST, ORBIS_MIN_LEVEL,
  multiMachinesClosed, multiMachineStartCode, multiMachineTagClosed,
} from './supply-rules.js';

const PAY_ITEMS = ORBIS_PAY_ITEMS;
const SLOTS = ORBIS_SLOTS, DAILY = ORBIS_DAILY, MIX_COST = ORBIS_MIX_COST, MIN_LEVEL = ORBIS_MIN_LEVEL;
const CX = 256, CY = 314, R = 121;          // plate centre and slot radius (from the slot rects of the script)
const S96 = (game, c, fb = '') => str(game, 96, c, T.shops?.supplyMachine?.strings?.[96]?.[c] ?? fb);
const S90 = (game, c, fb = '') => str(game, 90, c, T.shops?.supplyMachine?.strings?.[90]?.[c] ?? fb);
const today = () => { const d = new Date(); return `${d.getFullYear()}-${d.getMonth() + 1}-${d.getDate()}`; };

export function createSupply(game, api) {
  // ------------------------------------------------------------------------------------------ orbis state
  const orbisState = () => {
    if(game.save?.authority==='server')return game.sharedSupply?.state('orbis')||{slots:[],used:0};
    const s = (game.save.orbis ||= {});
    if (s.day !== today() || !Array.isArray(s.slots) || s.slots.length !== SLOTS || s.slots.every(x => x.won)) initOrbis(s);
    return s;
  };
  function initOrbis(s) {
    const M = T.shops?.supplyMachine;
    const entries = M?.entries || [];
    const slots = [];
    for (const [grade, , max] of M?.grades || []) {
      const pool = entries.filter(e => e[0] === grade);
      const used = new Set();
      for (let k = 0; k < max && pool.length; k++) {
        const pick = weightedPick(pool.filter(e => !used.has(e)).map(e => [e[2], e]));
        if (!pick) break;
        used.add(pick);
        slots.push({ grade, item: pick[1], winRate: pick[3], count: pick[5] || 1, won: false });
      }
    }
    while (slots.length < SLOTS) slots.push({ grade: 4, item: 0, winRate: 0, count: 0, won: true });
    s.slots = slots.slice(0, SLOTS);
    s.day = today();
    if (s.usedDay !== s.day) { s.used = 0; s.usedDay = s.day; }
  }

  // ------------------------------------------------------------------------------------------ the plate (shared)
  function makePlate(name, script, kind) {
    const st = { win: null, angle: 0, spinning: false, slots: [], tok: 0 };
    const home = []; // [angle] of each slot
    game.uiwin.registerWindow(name, {
      script,
      menuButton: kind === 'orbis' ? 'btn_single_supplymachine' : null,
      create(win) {
        st.win = win;
        home.length = 0; st.slots.length = 0;
        for (let k = 1; k <= SLOTS; k++) {
          const pan = win.control(`pan_item${k}`);
          // the script rect (the laid-out box is still empty while the window is being created)
          const [x, y] = Array.isArray(pan.spec?.rect) ? pan.spec.rect : pan.rect();
          home.push(Math.atan2(y + 16 - CY, x + 16 - CX));
          const slot = { pan, icon: win.control(`item_${k}`), lbl: win.control(`lbl_item${k}`), k: k - 1 };
          slot.icon.setTooltip(() => { const d = slot.data; if (!d || !d.item) return null; return itemTooltip(game, d.item, [d.count > 1 ? `x${d.count}` : '', d.won ? { text: S90(game, 25, 'Sold out.'), color: COLORS.RED } : '', d.weight ? { text: `${(d.weight / 10000).toFixed(2)}%`, color: COLORS.GOLD } : ''].filter(Boolean)); });
          st.slots.push(slot);
        }
        win.control('pan_roullete').el.style.transformOrigin = '50% 50%';
        win.control('btn_start').onClick(() => spin());
        win.find('btn_sort')?.onClick(() => mix());
        win.find('btn_help')?.onClick(() => notice(game, S96(game, 108, ''), S96(game, 101, 'the Orbis of Destiny')));
        win.control('pan_gaugeback_dummy').setTooltip(() => S96(game, 108, ''));
        win.control('pan_blink').hide();
      },
      async onOpen(win) {
        if (kind === 'orbis' && (game.save?.level || 1) < MIN_LEVEL) { win.close(); notice(game, S96(game, 5, 'Available for those above Level 80.')); return; }
        if(game.save?.authority==='server'&&!await game.sharedSupply?.load(kind)){win.close();return;}
        await render();
      },
      onClose() { st.tok++; st.spinning = false; },
    });
    const data = () => {
      if(game.save?.authority==='server')return game.sharedSupply?.state(kind)?.slots||[];
      if (kind === 'orbis') return orbisState().slots;
      const R0 = T.shops?.supplyMachine?.fieldBossRoulette?.[0];
      return (R0?.items || []).map(([item, weight, count]) => ({ item, weight, count, won: false }));
    };
    const payList = () => (kind === 'orbis' ? PAY_ITEMS : (T.shops?.supplyMachine?.fieldBossRoulette?.[0]?.payItems || PAY_ITEMS));
    const payCount = () => (kind === 'orbis' ? 1 : (T.shops?.supplyMachine?.fieldBossRoulette?.[0]?.payCount || 1));
    const payHave = () => payList().reduce((s, i) => s + bag.count(game, i), 0);

    async function render() {
      const w = st.win;
      if (!w) return;
      const tok = ++st.tok;
      const list = data();
      await Promise.all(list.filter(d => d.item).map(d => itemInfoFull(game, d.item)));
      if (tok !== st.tok) return;
      place();
      st.slots.forEach((s, k) => {
        const d = list[k] || null;
        s.data = d;
        s.icon.setIcon(null);
        s.lbl.setText(d?.count > 1 ? String(d.count) : '');
        s.pan.setVisible(!!d?.item);
        if (!d?.item) return;
        s.icon.el && (s.icon.el.style.opacity = d.won ? '0.3' : '');
        itemIcon(game, d.item, 32, 32).then(ic => { if (tok === st.tok) s.icon.setIcon(ic); });
      });
      const remain = list.filter(d => d.item && !d.won).length;
      w.control('num_remaingoods').setNumber?.(remain);
      if (kind === 'orbis') {
        const s = orbisState();
        w.control('lbl_remainsupplycount').setText(S96(game, 105, '%d / %d times').replace('%d', s.used || 0).replace('%d', DAILY));
        w.control('pan_gauge').setGauge?.(1 - (s.used || 0) / DAILY);
      } else {
        w.control('lbl_remainsupplycount').setText(`${fmtNum(payHave())}`);
        w.control('pan_gauge').setGauge?.(1);
      }
      // "need items: %s X %d" (hidden label of the script): the Start button's tooltip
      const needText = S90(game, 5, 'need items: %s X %d').replace('%s', itemInfo(game, payList()[0]).name).replace('%d', payCount());
      w.control('lbl_needitemcount').setText(needText);
      w.control('btn_start').setTooltip(`${needText}\n(${fmtNum(payHave())})`);
    }
    function place() {
      const rot = st.angle;
      st.win.control('pan_roullete').el.style.transform = `rotate(${rot}rad)`;
      st.slots.forEach((s, k) => {
        const a = home[k] + rot;
        s.pan.setRect(Math.round(CX + R * Math.cos(a) - 16), Math.round(CY + R * Math.sin(a) - 16), 32, 32);
      });
    }
    function message(text) {
      const w = st.win;
      w.control('lbl_message').setText(text);
      w.control('pan_messageback').show();
      clearTimeout(st._mt);
      st._mt = setTimeout(() => w.control('pan_messageback').hide(), 2500);
    }
    async function spin() {
      if (st.spinning) return;
      const list = data();
      if (kind === 'orbis') {
        const s = orbisState();
        if ((s.used || 0) >= DAILY) { message(S96(game, 4, 'Further use of the Orbis of Destiny is unavailable.')); return; }
      }
      const left = list.map((d, k) => [d, k]).filter(([d]) => d.item && !d.won);
      if (!left.length) { message(S90(game, 33, 'It is a sold-out machine.')); return; }
      if (payHave() < payCount()) { uiSound(game, 'unsuitableItem'); message(S96(game, 3, 'Gearwheel is not enough.')); return; }
      const shared=game.save?.authority==='server';let pick,won;const paid=[];
      if(shared){
        st.spinning=true;
        const result=await game.sharedSupply?.spin(kind);
        if(!result?.reward){st.spinning=false;return;}
        pick=result.pick;won={item:result.reward.item,count:result.reward.count};
      }else{
        pick=weightedPick(left.map(([d,k])=>[kind==='orbis'?(d.winRate||1):d.weight,k]));won=list[pick];
        if(!bag.canAdd(game,won.item,won.count)){uiSound(game,'lackOfSpace');message(S96(game,1,'There is not enough space in inventory.'));return;}
        let need=payCount();
        for(const i of payList()){const n=Math.min(bag.count(game,i),need);if(n>0){bag.remove(game,i,n);need-=n;paid.push({item:i,count:n});}}
        if(kind==='orbis'){const s=orbisState();s.used=(s.used||0)+1;}
      }
      // spin: the winning slot ends under the needle (angle -90 deg) after a few turns
      st.spinning = true;
      uiSound(game, 'buttonMain');
      const from = st.angle;
      let target = -Math.PI / 2 - home[pick];
      while (target < from + Math.PI * 6) target += Math.PI * 2;
      const T0 = performance.now(), DUR = 4200, tok = st.tok;
      await new Promise((res) => {
        const step = () => {
          if (tok !== st.tok) return res();
          const f = Math.min(1, (performance.now() - T0) / DUR);
          const e = 1 - Math.pow(1 - f, 3);
          st.angle = from + (target - from) * e;
          place();
          if (f >= 1) return res();
          requestAnimationFrame(step);
        };
        step();
      });
      st.angle %= Math.PI * 2;
      st.spinning = false;
      if(!shared){
        if(kind==='orbis')won.won=true;
        const added=bag.add(game,won.item,won.count,{from:kind==='orbis'?'orbis':'roulette'});
        if(!added){message(S96(game,1,'There is not enough space in inventory.'));return;}
        if(kind==='orbis'&&paid.some(x=>x.item===1756037))game.events?.emit?.('life:dekapass:event',{main:5,sub:22,value:1756037,count:1});
      }
      const blink = st.win.control('pan_blink');
      blink.setRect(CX - 6, CY - R - 6 - 22, 12, 12); blink.show();
      setTimeout(() => blink.hide(), 1500);
      message(`${itemInfo(game, won.item).name}${won.count > 1 ? ` x${won.count}` : ''}`);
      say(game, S96(game, 100, '[message] %s has acquired the item %s in the Orbis of Destiny.').replace('%s', game.save?.name || '').replace('%s', itemInfo(game, won.item).name), 'item');
      game.events?.emit?.('supply:win', { kind, itemIndex: won.item, count: won.count });
      render();
    }
    async function mix() {
      if (kind !== 'orbis' || st.spinning) return;
      const r = await confirmBox(game, S96(game, 111, `Mixing orders: ${fmtNum(MIX_COST)} Dil`), S96(game, 112, 'Mixing Order'));
      if (r !== 'yes') return;
      if(game.save?.authority==='server'){
        st.spinning=true;try{if(await game.sharedSupply?.mix())await render();}finally{st.spinning=false;}return;
      }
      if (dil(game) < MIX_COST) { uiSound(game, 'lackOfDil'); message(S96(game, 2, 'DIL is not enough.')); return; }
      addDil(game, -MIX_COST);
      const s = orbisState();
      for (let i = s.slots.length - 1; i > 0; i--) { const j = Math.floor(Math.random() * (i + 1)); [s.slots[i], s.slots[j]] = [s.slots[j], s.slots[i]]; }
      render();
    }
    return { open: () => game.uiwin.open(name), render };
  }

  const orbis = makePlate('shops.orbis', 'game2/privatesupply/ui_privatesupplywnd.txt', 'orbis');
  const fieldboss = makePlate('shops.fieldboss', 'game2/fieldbosssupply/ui_fieldbosssupplywnd.txt', 'fieldboss');

  // ------------------------------------------------------------------------------------------ the multi machine
  game.uiwin.registerWindow('shops.supplymachine', {
    script: 'game2/supplymachine/ui_supplymachinewnd.txt',
    menuButton: 'btn_supplymachine',
    create(win) {
      repairNativeShopStateArt(win.control('btn_addcash'),'supplyPurchase',atlas.table);
      const M = T.shops?.supplyMachine;
      const tabs = ['btn_normal', 'btn_special', 'btn_event'];
      const sel = (i) => tabs.forEach((t, k) => win.control(t).setChecked(k === i));
      tabs.forEach((t, i) => win.control(t).onClick(() => sel(i)));
      sel(0);
      const closed = str(game, 91, 4, 'CLOSED');
      for (let k = 0; k < 3; k++) {
        const on = !multiMachineTagClosed(M, k);
        win.control(`lbl_tagmachine_${k}`).setText(on ? str(game, 91, M.uiMachines[k][2], '') : closed);
        win.control(`btn_machine_${k}`).onClick(() => {
          for (let j = 0; j < 3; j++) win.control(`btn_machine_${j}`).setChecked(j === k);
          const m = M?.machines?.[k];
          showMsg(win, !m || !m[1] ? S90(game, 32, "It isn't a selling machine.") : S90(game, 33, 'It is a sold-out machine.'));
        });
      }
      win.control('btn_start').onClick(() => showMsg(win, S90(game, multiMachineStartCode(M), multiMachinesClosed(M) ? "It isn't a selling machine." : 'It is a sold-out machine.')));
      win.control('btn_addcash').onClick(() => api.dshop?.open());
      win.control('lbl_remainsupplycount').setText(S90(game, 4, 'Remaining Initialization : %d times').replace('%d', 0));
      win.control('lbl_needitemcount').setText('');
      win.control('num_remaingoods').setNumber?.(0);
    },
  });
  function showMsg(win, text) {
    win.control('lbl_message').setText(text);
    win.control('pan_messageback').show();
    clearTimeout(win.data._mt);
    win.data._mt = setTimeout(() => win.control('pan_messageback').hide(), 2500);
  }

  // ------------------------------------------------------------------------------------------ HUD alarm (Lv 80+)
  game.uiwin.registerWindow('shops.orbis_alarm', {
    script: 'game2/privatesupply/ui_privatesupplywnd_alarm.txt', hud: true, band: 'hud', escClose: false,
    create(win) { win.control('btn_alarm').onClick(() => orbis.open()); },
  });
  // Supply Machine alarm (supplymachine/ui_supplywnd_alarm.txt, 10 100 under the clock): opens the machine window.
  game.uiwin.registerWindow('shops.supply_alarm', {
    script: 'game2/supplymachine/ui_supplywnd_alarm.txt', hud: true, band: 'hud', escClose: false, remember: false,
    create(win) { win.control('btn_alarm').onClick(() => game.uiwin.toggle('shops.supplymachine')); },
  });
  let alarmChecked = false;
  function syncAlarm() {
    // gfxC4 [alarms]: Global shows the private-supply alarm at Lv 1 (recording, 50 100 under the clock); the Lv 80 rule
    // is enforced when it is used (96:5 "Available for those above Level 80." in open() above), not by hiding it.
    const on = (gfxC('alarms') || (game.save?.level || 1) >= MIN_LEVEL) && game.settings?.orbisAlarm !== false;
    if (on && !game.uiwin.isOpen('shops.orbis_alarm')) game.uiwin.open('shops.orbis_alarm');
    else if (!on && game.uiwin.isOpen('shops.orbis_alarm')) game.uiwin.close('shops.orbis_alarm');
    if (!game.uiwin.isOpen('shops.supply_alarm')) game.uiwin.open('shops.supply_alarm');
  }
  game.events?.on?.('levelup', syncAlarm);
  game.events?.on?.('map', () => { alarmChecked = true; syncAlarm(); });

  return {
    orbis, fieldboss,
    openOrbis: () => orbis.open(),
    openFieldBoss: () => fieldboss.open(),
    openMachine: () => game.uiwin.open('shops.supplymachine'),
    syncAlarm, get alarmChecked() { return alarmChecked; },
  };
}
