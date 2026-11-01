// PC room / NetCafe EXP. Sources:
//   audit/global-re/SERVER-RE.md §7: player state `PCRoomChecking` (Client\Player\State\PCRoomChecking.cpp), the
//     NetCafe checks OnNexonNetCafe / OnInternetCafeCheck / OnMemberIPCheck / OnAccountingCoin, the live log
//     "PCRoomExpRatio changed : %d Per -> %d Per.", fields wPCRoomExpRatio, wFreePCRoomExpRatio, wPaidPCRoomExpRatio,
//     wNetCafeExpRatio, fNetCafeItemDropRatio.
//   g2 share/formula.ini:82-84 (wPCRoomExpRatio 20, wFreePCRoomExpRatio 10, wPaidPCRoomExpRatio 30), :119-120
//     (wNetCafeExpRatio 1, fNetCafeItemDropRatio 1.0); share/server/exppolicy.csv:2-3 (PCROOMUSER 0, PREMIUMPCROOM 0).
// State machine per player: 'checking' (on entering the world) -> one verdict: 'none' | 'pcroom' | 'free' | 'paid' |
// 'netcafe'. The verdict comes from the operator's cafe check (IP / NetCafe accounting); this engine has no such service,
// so the default check answers 'none'. EXP: pcroom/free need policy PCROOMUSER, paid needs PREMIUMPCROOM, each adds its
// ratio in percent ("%d Per"); netcafe applies wNetCafeExpRatio as a multiplier (1 = unchanged, matching
// fNetCafeItemDropRatio's 1.0). With Global's exppolicy (0/0) every bonus is 0.
import fs from 'node:fs/promises';
import path from 'node:path';
import { decodeText } from '../../src/formats/binreader.js';

export const PCROOM_DEFAULTS = Object.freeze({ policy: { PCROOMUSER: 0, PREMIUMPCROOM: 0 }, ratios: { pcRoom: 0, free: 0, paid: 0, netCafe: 1, netCafeDrop: 1 } });

export function pcRoomRulesFrom(iniText, policyCsv) {
  const v = k => { const m = new RegExp(`^${k}\\s*,\\s*([\\d.]+)`, 'm').exec(iniText || ''); return m ? Number(m[1]) : null; };
  const policy = {};
  for (const line of String(policyCsv || '').split(/\r?\n/).slice(1)) { const [n, d] = line.split(','); if (d) policy[d.replace(/"/g, '').trim()] = Number(n) || 0; }
  return {
    policy: { PCROOMUSER: policy.PCROOMUSER ?? 0, PREMIUMPCROOM: policy.PREMIUMPCROOM ?? 0 },
    ratios: { pcRoom: v('wPCRoomExpRatio') ?? 0, free: v('wFreePCRoomExpRatio') ?? 0, paid: v('wPaidPCRoomExpRatio') ?? 0, netCafe: v('wNetCafeExpRatio') ?? 1, netCafeDrop: v('fNetCafeItemDropRatio') ?? 1 },
  };
}
export async function loadPcRoomRules(dataRoot) {
  try {
    const ini = decodeText(await fs.readFile(path.join(dataRoot, 'share/formula.ini')));
    const csv = decodeText(await fs.readFile(path.join(dataRoot, 'share/server/exppolicy.csv')));
    return pcRoomRulesFrom(ini, csv);
  } catch { return PCROOM_DEFAULTS; }
}

const VERDICTS = new Set(['none', 'pcroom', 'free', 'paid', 'netcafe']);
/** The operator's cafe check; none exists here. */
export function defaultCafeCheck() { return 'none'; }

export class PCRoomChecking {
  constructor(rules = PCROOM_DEFAULTS, { check = defaultCafeCheck, log = () => {} } = {}) { this.rules = rules; this.check = check; this.log = log; this.states = new Map(); }
  async enter(player) {
    this.states.set(player.id, 'checking');
    let v = 'none';
    try { v = await this.check(player); } catch { v = 'none'; }
    if (this.states.get(player.id) !== 'checking') return this.states.get(player.id);
    this.states.set(player.id, VERDICTS.has(v) ? v : 'none');
    return this.states.get(player.id);
  }
  leave(player) { this.states.delete(player.id); }
  state(player) { return this.states.get(player.id) || 'none'; }
  /** Additive EXP percent for this player. */
  expPercent(player) {
    const s = this.state(player), { policy, ratios } = this.rules;
    if (s === 'pcroom') return policy.PCROOMUSER ? ratios.pcRoom : 0;
    if (s === 'free') return policy.PCROOMUSER ? ratios.free : 0;
    if (s === 'paid') return policy.PREMIUMPCROOM ? ratios.paid : 0;
    if (s === 'netcafe') return policy.PCROOMUSER || policy.PREMIUMPCROOM ? Math.round((ratios.netCafe - 1) * 100) : 0;
    return 0;
  }
  /** GM live change (gradelist PCROOMEXPRATIO right); logs Global's message. */
  setRatio(percent) {
    const before = this.rules.ratios.pcRoom, after = Math.max(0, Math.trunc(Number(percent) || 0));
    this.rules = { ...this.rules, ratios: { ...this.rules.ratios, pcRoom: after } };
    this.log(`PCRoomExpRatio changed : ${before} Per -> ${after} Per.`);
    return after;
  }
}
