# DK Engine 3.3.5 — Guild and dungeon entry fixes

## Guild and alliance emblems
Shared-server inventory use now routes Guild of Glory and alliance glory items to their existing registration services, rather than treating them as generic consumables. Guild leader permissions, confirmation, ownership checks and atomic server consumption remain enforced. Cancelling does not consume an item.

## Dungeon entrance menus
NPCs with both dungeon entrances and quests or other services now keep their original service menu. This restores access to admission-ticket conversations, including Norak Secret Arena, Cartel and Colosseum. Selecting the dungeon entry service still uses server-owned level, distance, party, ticket and fee checks.

## Solo admission compatibility
SOLO dungeons consistently admit one character. This resolves Stardion Infinite Battle's impossible combination of a two-member minimum and a one-member maximum. This is an engine compatibility rule, not a claim to recovered native server behavior. Valid tickets or the configured Super Pass cost remain required; groups are refused without consuming items.

## Verification and update
The changes were checked using disposable profiles, authored entrance records and prepared collision data, plus local admission, ticket issuance, guild authorization and persistence regressions. DK channel and DK Square, stream recovery and effect-body regressions also passed. These checks do not certify every dungeon clear, rendered native parity, or networking between independent DK hosts. DK scenes remain isolated within one authoritative host.

Close the world, game and launcher before applying the complete update. Existing accounts, settings and SQL data are preserved by the verified installer; keep your own backups. No original Global executables or game assets are included.

Thanks to Franky and DEV ShadoW for their contributions and testing reports.
