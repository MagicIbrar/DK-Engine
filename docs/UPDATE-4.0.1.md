# DK Engine 4.0.1 — Community fixes, startup and exchange

Version 4.0.1 updates 4.0.0 with the following fixes. The 4.0.0 notes remain available in the [previous release](https://github.com/waveforgemp3app-cmyk/Tool/releases/tag/v4.0.0).

[4.0.1 release notes and downloads](https://github.com/waveforgemp3app-cmyk/Tool/releases/tag/v4.0.1)

<details>
<summary>Contributors</summary>

Thanks to DEV ShadoW, CYBER and Magic Ibrar for helping with the project, and to everyone contributing, testing and sharing feedback.

</details>

<details>
<summary>01 | Event stability and combat feedback</summary>

- Siege and Team Stones use bounded shared actor lookup, preventing recursive event lookups from growing over time.
- An effect presentation failure no longer discards the remaining events in the same batch or rejects an accepted action receipt.
- Final-hit damage text keeps the defeated target long enough to display the hit.

</details>

<details>
<summary>02 | Map effects and readiness</summary>

- Restored the authored Ardeca firefly weather effect at its native placement and with its native scene settings.
- A normal map-transition readiness conflict keeps the usual heartbeat interval; lease or permission invalidation still prompts immediate recovery.

</details>

<details>
<summary>03 | Startup and saved data</summary>

- SQLite startup now checks whether a saved document exists without reading every stored document twice.
- Startup progress follows completed file and byte work from 0% to 100%, reaching 100% only when required work is ready. UI and scene preparation run in parallel while retaining the full required checks.
- Native-data verification avoids redundant end-of-file reads and batches callbacks while retaining full validation. This reduces verification overhead in the tested startup path.

</details>

<details>
<summary>04 | Exchange and verification</summary>

- Fixed online purchases for supported exchange, exchange-store and material-exchange offers; corrected More’s menu labels.
- Exchange actions are server-authoritative transactions, so inventory, currency and reward changes commit together or are rolled back together on refusal or failure.
- Automated checks cover event lifetimes, startup readiness and exchange transactions. They do not replace in-game testing or establish full Global parity.

</details>
