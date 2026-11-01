// Half Bagi (class 12) fury gauge. NATIVE: pcclass FURY_POINT_DPS 0.2 / FURY_POINT_MAX_TIME 10000 (class 12 only);
// stringtable_skill 150:2 "stays full for 10 seconds ... until you use a Fury skill"; skill ResourceFury costs; furywnd
// shows whole "cur / max". The Global server's gain rules are not in any supplied client table or string, so each value
// below is one tagged ENGINE-CHOSEN reading, not Global parity.
export const FURY_CHOICES = Object.freeze({
 maxFromMaxMp: true,      // ENGINE-CHOSEN: maximum = character max MP (ResourceFury 5 at Lv10 .. 2,093 at Lv170 follows the MP scale; fury skills cost 0 MP)
 hitGain: 0.02,           // ENGINE-CHOSEN: a landed non-DoT hit on a monster adds 2% of the maximum (the Aloken pcclass rate CHARGE_POINT_ADD 20 / MAX 1000)
 hurtGain: 0.03,          // ENGINE-CHOSEN: a monster hit taken adds 3% of the maximum
 dpsIsPercentOfMax: true, // ENGINE-CHOSEN: native FURY_POINT_DPS 0.2 read as 0.2% of the maximum lost per second
 holdSecFallback: 10,     // ENGINE-CHOSEN: hold when FURY_POINT_MAX_TIME is absent; the native 10000 ms row wins when present
 lossCorrection: 'FURY_DPS_CORRECTION_MUL', // ENGINE-CHOSEN reading of the native status option: loss x (1 - sum/100); Fury Control 50..90 halves..tenths the loss, Self Injury 600..10000 turns it into a recharge ("Rage recharge")
});
