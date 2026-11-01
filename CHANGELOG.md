# DK Engine 4.1.0 — One-click Global Dekaron engine

<details>
<summary>Contributors</summary>

Franky, DEV ShadoW, CYBER, and Magic Ibrar. Thank you for testing, reports, investigation and contributions.

</details>

**4.1.0 release.** This list covers the merged work since 4.0.3 and the continuation fixes. Earlier launcher and gameplay improvements remain included. Known limitations are listed below.

<details>
<summary>01 | Accounts, inventory, items and market</summary>

1. Native second-password keypad and server-checked account rules after sign-in, before character selection, including the existing owner and NPC exemptions.
2. Native inventory and stash sorting warnings, including their saved warning preference.
3. Native DIL deposit interface for inventory-to-stash transfers.
4. Native equipment preset selection, preset removal selection and preset confirmation.
5. Preset confirmations are bound to the original character, connection and item; stale dialogs cannot operate on replacement equipment or a new session.
6. Native inventory, personal stash and shared-stash expansion confirmations and limit messages.
7. Native cash-item discard confirmation.
8. Native Portal Scroll and personal-portal entry confirmations.
9. Native stat, attribute and skill reset confirmations and refusal messages, with host-side validation.
10. Meister Change confirmation and item use, preserving earned Meister progress while applying the normal-skill reset.
11. Meister refunds cannot repeatedly generate skill points through automatic first-rank grants; paid re-learning remains available.
12. Successful resets publish passive changes after persistence; failed saves preserve the prior live state.
13. Learned passive HP and MP bonuses participate consistently in host-derived totals, including equipment changes, refreshes and resets.
14. Native warning before opening applicable cash packages.
15. Hatched-pet ownership check and native refusal for another egg where the source rule forbids it.
16. Native warning when buying supported transportation items.
17. Inventory removal treats a count-less single item as one.
18. Native consignment listing details, item preview, seller information, price and quantity-confirmation handoff.
19. Consignment confirmation keeps the original character and connection, rejects repeated pending clicks, and ignores replies belonging to an old window. Existing host pricing and seller fees are retained.

</details>

<details>
<summary>02 | Guilds, parties, social features and siege</summary>

20. Native guild join, leave, disband and rank-permission confirmations.
21. Native party formation/name entry, leave and disband prompts.
22. Native expedition invitations, formation/name wording, leave and disband prompts.
23. Incoming friend-request acceptance and decline, connected to blacklist checks.
24. Friend and blacklist limits follow the recorded 30-entry source evidence.
25. Native Guild of Glory confirmation uses the authored interface text.
26. Classic siege authority roster, with durable membership changes and its supported 50-member limit.
27. Native guild-leader delegation confirmation with a typed confirmation phrase.
28. Native declared siege-time notice.
29. Native siege force-attack alarm connected to live battle state.
30. Native renewed-siege gate upgrade confirmation, using the host's current gate and price information.
31. PvP challenge waiting uses the native waiting window, host deadline and cancellation flow.
32. Human recipients of resurrection skills receive a native consent prompt; accepted revival uses the host-authored result.
33. Party Match Buff Mode offers all 70 authored choices, with host validation, readiness updates, revival reapplication and cleanup on exit.
34. Older source data without Buff Mode does not require its separate buff catalog. Enabled modes still require valid source data.
35. Party Match observer confirmation and host-authorized admission, spectator isolation and return flow.
36. Point Target party sharing uses the native acceptance icon and authored bonus, with cleanup when its source, target, equipment, party or session becomes invalid.

</details>

<details>
<summary>03 | World, maps, combat and presentation</summary>

37. Skills can hit eligible role-object monsters such as supported boxes and treasure-chest actors.
38. Fighting NPC players spend their earned stat points through the ordinary allocation rules.
39. Authored monster create, idle, attack and death dialogue is connected to the presentation system.
40. Ground-loot ownership and Dead Island igniter protection use the authored ownership duration.
41. PC-room checking and bonus policy are read from the source; disabled Global bonus policy remains disabled by default.
42. Original field maps 1, 2, 4, 8 and 9 are available through the supported host/map-selection paths.
43. Fifteen blocked arrival locations resolve to exact walkable destinations present in Global's own warp or portal data.
44. Mixed-case map collision references resolve against normalized pack paths.
45. Known dungeon and monster references resolve to unique source files; rebuilt data verifies the redirected references.
46. Item effects skip only missing bone controls instead of discarding the whole effect scene.
47. Left-hand twin rigs use the appropriate left-side bones, including the investigated orb binding.
48. Animation references placed in an item's texture-pack column are resolved as animation references.
49. Verified relocated wing texture-pack references resolve to their actual source location. Five existing Typhoon/Vampiric wing animation references now resolve despite omitted extensions or misplaced spaces, without guessing missing assets.
50. Additive effect meshes with failed textures avoid the previous white fallback; the recorded rendering assumption remains identified in the technical evidence.

</details>

<details>
<summary>04 | Graphics, loading and performance</summary>

51. Global preload lists, including common preload entries, are parsed and sent through the model cache.
52. Scene compilation is divided into smaller batches with progress reporting.
53. Hidden scenes do not draw behind the loading cover during preparation.
54. Reused camera vectors and pose buffers reduce repeated frame allocations.
55. NPC placement and summon broadcasts reuse prepared results where their inputs are unchanged.
56. Party War snapshots reuse shared calculations within a broadcast.
57. Battle-support snapshot data is isolated from mutable source fields.
58. Movement interpolation uses the revised measured margin while retaining the existing pacing behavior.
59. Renderer settings follow the audited default-resolution, water and shadow settings; related renderer-state checks are included.
60. The authored post-water ripple shader has a ported implementation. Its original automatic trigger is not established and is not advertised as complete.
61. Optional SSE row-delta transport remains behind its explicit setting and is off by default.

</details>

<details>
<summary>05 | Global compatibility and preparation</summary>

62. Support for both inspected monster-table record layouts, which decode to the same current monster content.
63. Expanded format and table compatibility checks, including schema and record-size validation.
64. Preparation prefers the original packs; extracted content is reused only when its validation still matches.
65. Builder and dependency changes invalidate prepared-data fingerprints so stale generated tables are rebuilt.
66. Native server-list data is carried through parsing, preparation and world lookups.
67. Global data-update monitoring reports changes and applies them through the controlled preparation flow.
68. Optional host version gating follows the applied source version and remains off unless enabled.
69. A missing optional specificperiodschedule.csv no longer aborts quest preparation.
70. Ordinary quests are preserved when that calendar is absent; new acceptance/listing of dated Wanted quests remains unavailable without verified dates. Required quest tables still fail clearly if missing.
71. Dungeon tables, event-field data, level caps and font definitions are checked against source data; the fresh candidate run passed 556 comparisons with no pending inputs.

</details>

<details>
<summary>06 | Saves, SQL and operator tools</summary>

72. Per-entity save journals replace repeated whole-world rewrites in the default local persistence path.
73. Background checkpoints fold journal state into the main store, with a final checkpoint during shutdown.
74. Journal recovery preserves acknowledged state; an incomplete final record is handled distinctly from corruption in committed history.
75. Durable readers used by backup, permissions, storage and transfer tools include journal state.
76. SQL group commits batch eligible account changes into a shared transaction; acknowledgement still waits for durable local persistence and the corresponding SQL commit.
77. SQL delayed durability remains disabled.
78. Login/session updates avoid cloning and re-hashing every unrelated account.
79. Account-journal and SQL-group-commit rollback settings remain available.
80. Save-backup rotation, checksum validation and restore tooling are included; automatic scheduling is not implied.
81. Backup-first server transfer and merge tooling refuse unsupported or unresolved cases.
82. Structured server logging is connected to the host.
83. Updated SQL migrations and storage validation accompany the persistence changes.

</details>

<details>
<summary>07 | Compatibility and testing</summary>

84. Native-window coverage is recorded separately from implementation, equivalence, existing policy and unknown original rules.
85. Focused regression checks cover character/session changes, repeated requests, stale replies, persistence refusal and state cleanup.
86. REA analysis supplements source review and behavioral tests; protected executable code and unresolved original behavior remain recorded in the technical evidence.
87. A clean preparation completed all 22 preparation jobs from the supplied Global packs, followed by a reuse check.
88. A missing-calendar regression run passed 3,198 checks, preserving ordinary quest data and required-file failure behavior.

</details>

Known limitations: the original trigger/rules for the legacy Contribution Points error and fortune interface are not established; some publisher/platform services have no equivalent local engine service.

<details>
<summary>Bug reports</summary>

When reporting a bug, include:

- Engine version and Global client version.
- Local or SQL mode, plus the class, map and item if relevant.
- Steps to reproduce it.
- What you expected and what happened.
- A screenshot and the relevant error or log excerpt. Leave out passwords and personal details.

</details>

Supply your own compatible Global game files. The package contains engine code and redistributable runtimes. Back up accounts and databases before updating or changing storage.

More updates and refinements are planned over the coming weeks. Community reports and testing continue to guide the work.