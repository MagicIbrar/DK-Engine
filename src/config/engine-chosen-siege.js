// SIEGE (Zenoa Castle siege war, map 23): the values the Global data does not define. Every entry is
// ENGINE-CHOSEN (not in Global data). The original numbers (fee, levels, gate / stone HP, WARTIME, REVIVALTICK, REIGNOCCUPYTIME,
// REIGNMAXDISTANCE, tax ratios, locations) are read from the data by src/game/siege-rules.js and are NOT repeated here.
export const SIEGE_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): the classic config has no start time. The battle uses the only start in the data
   *  (siege_renew/config.csv START_WEEK 0 / START_HOUR 19 = Sunday 19:00) in UTC, for WARTIME seconds. */
  ZONE: 'UTC',
  /** ENGINE-CHOSEN (not in Global data): UTC offset of the start time, in minutes. */
  ZONE_OFFSET_MIN: 0,
  /** ENGINE-CHOSEN (not in Global data): the hours the defending guild master may announce (Lorenzo SIEGE_STARTTIME, 700:30 / 40)
   *  for the coming Sunday; once per week (700:37), never during a battle (700:29). */
  ANNOUNCE_HOURS: Object.freeze([12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22]),
  /** ENGINE-CHOSEN (not in Global data): the seal list holds three guilds (500:206 shows GUILD_0..GUILD_2). Registration at Bastian
   *  (SIEGE_ENTRY) is the Seal Ritual too: a registered guild is confirmed at once (700:1 + 700:13). */
  MAX_SEALS: 3,
  /** ENGINE-CHOSEN (not in Global data): 700:2 / 700:3 charge the fee to the registering guild master's own DIL. */
  FEE_SOURCE: 'guild master character DIL',
  /** ENGINE-CHOSEN (not in Global data): sides. The castle owner defends; every registered guild attacks; guilds of one alliance
   *  never hit each other. Any two participants of different (non-allied) guilds are enemies on map 23 during the battle. */
  SIDES: 'owner defends; every sealed guild attacks; allies never hostile',
  /** ENGINE-CHOSEN (not in Global data): gates / guardian stones take damage only from sealed attacking guild members during the
   *  battle; other hits are restored on the next siege tick. Their damage uses the brick resist percentages (as event objects). */
  OBJECT_ATTACKERS: 'sealed attackers only',
  /** ENGINE-CHOSEN (not in Global data): a destroyed guardian stone gives its pendant (510:7..11) to the destroyer's guild and stands
   *  again after its brick lifeTime (= ZEOLITENONPKTIME 300000 ms); a later destruction moves the pendant. */
  STONE_RULE: 'pendant to the destroying guild; the stone returns after brick lifeTime',
  /** ENGINE-CHOSEN (not in Global data): empathy (Juto REIGN_SYSOP) lasts REIGNOCCUPYTIME; DESCREASETICKPERZEOLITE,
   *  REGINFAILZEOLITECOUNT and DAMAGEBONUSRATIO have no defined meaning in the data and are not applied (global parity). */
  EMPATHY_UNAPPLIED: Object.freeze(['DESCREASETICKPERZEOLITE', 'REGINFAILZEOLITECOUNT', 'DAMAGEBONUSRATIO', 'GATEMAXHP']),
  /** ENGINE-CHOSEN (not in Global data): seconds-left announcements of an empathy (700:129). */
  EMPATHY_ALARMS: Object.freeze([240, 180, 120, 60, 30, 10, 5]),
  /** ENGINE-CHOSEN (not in Global data): unwalkable map cells within this many cells of a castle object's brick footprint (the
   *  guardian stone pedestals of the map-23 collision) count as the object, so it is hit from the walkable ground around it. */
  HIT_RING: 2,
  /** ENGINE-CHOSEN (not in Global data): a won empathy hands the castle over; the battle goes on until WARTIME with the new owner
   *  defending after the 2-minute preparation of 100:12 (attackers on the castle map are moved to the outer castle centre). */
  CAPTURE: 'castle changes hands; battle continues with 2 min preparation (100:12)',
  /** ENGINE-CHOSEN (not in Global data): a participant downed on map 23 is respawned after REVIVALTICK at the inner castle centre
   *  (location 1, defenders) or the outer castle centre (location 2, attackers) (respawn window 290:40 / 41, 510:2 / 4). */
  RESPAWN: 'defenders location 1, attackers location 2',
  /** ENGINE-CHOSEN (not in Global data): siege tunnels (SIEGE_TELEPORT 21 at Braiken / Deneb / Loa) admit the defending guild
   *  (location 1) at any time (100:10) and sealed guilds (location 2) during the battle; siegeteleport.csv LocationIndex 100
   *  is a placeholder in the data. */
  TUNNEL: 'defenders -> location 1 any time; sealed attackers -> location 2 during the battle',
  /** ENGINE-CHOSEN (not in Global data): ENDWARACTIONTIME seconds after the end, non-owners still on map 23 go to their return
   *  point (the bound return location or the default town); owners go to ENDWARLOCATIONINDEX 201. */
  END_MOVE: 'non-owners to their return point; owners to location 201',
  /** ENGINE-CHOSEN (not in Global data): tax. NPC shop DIL purchases / sales on maps of the castle's TerritoryIndex accrue the
   *  tax.csv Buy / Sell ratio of the price to the owner's ledger (prices are unchanged); one ledger day per UTC day, 7 days kept
   *  (320:200..206); the defending guild master collects into their own DIL (701:400 / 401 / 402 / 404) outside a battle (701:380). */
  TAX: 'shop buy / sell in the territory, ledger only, 7 UTC days, master collects',
  /** ENGINE-CHOSEN (not in Global data): ledger days kept (the window shows lbl_day0..6). */
  TAX_DAYS: 7,
  /** ENGINE-CHOSEN (not in Global data): queued shop tax is written to the durable ledger at most this often. */
  TAX_FLUSH_MS: 10_000,
  /** ENGINE-CHOSEN (not in Global data): the tax window opens from Lorenzo (castle) and Bastian (Loa) for the owner's master; the
   *  classic data gives no TAX_INFO job to a classic NPC. */
  TAX_NPCS: Object.freeze([2202, 753]),
  /** ENGINE-CHOSEN (not in Global data): guard deployment (290:30..32) and the siege skills (100:42) need guard monsters / skill
   *  statuses the classic data does not list; Lorenzo answers 700:145 "Not yet available." */
  UNAVAILABLE: Object.freeze(['guards', 'siegeSkills']),
  /** ENGINE-CHOSEN (not in Global data): the host advances the siege lazily from snapshots / commands at most this often. */
  TICK_MS: 250,
  /** ENGINE-CHOSEN (not in Global data): the battle runs on field channel 0 (700:75 names one channel). */
  CHANNEL: 0,
});
