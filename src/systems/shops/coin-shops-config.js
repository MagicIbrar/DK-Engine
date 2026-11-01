// COIN-SHOPS engine choices: the coin exchange (job 164 EXCHANGE_RANKUP_EXP_COIN, Karin) and the currency trade
// (job 165 EXCHANGE_GOLDITEM, Sinan). The original rates were server-side (docs/formats/shops.md 3.3); the client data
// only names the coins and, in their item descriptions, how much EXP / DIL each one is worth (coin-shops-rules.js reads
// those). Everything in this module is a value the Global client data does not carry.
export const COIN_SHOP_CONFIG = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): job 164 opens the Rankup Coin tab first; the Exp Coin tab is its pair
  rankJobFirstTab: 'rankup',
  // ENGINE-CHOSEN (not in Global data): job 165 opens the Sell tab first; the Buy tab is its pair
  goldJobFirstTab: 'sale',
  // ENGINE-CHOSEN (not in Global data): Grade (DK Rank) points one Rank-Up Coin (Bind) gives (item text 498 names no amount)
  rankPointsPerCoin: 100,
  // ENGINE-CHOSEN (not in Global data): sale fee, percent of the sale DIL (0 pays the DIL named in the item text in full)
  saleFeePercent: 0,
  // ENGINE-CHOSEN (not in Global data): purchase fee, percent added on top of the item's exchange value
  purchaseFeePercent: 1,
  // ENGINE-CHOSEN (not in Global data): the Buy tab sells the same gold items the Sell tab buys, at their exchange value
  purchaseSameAsSale: true,
  // ENGINE-CHOSEN (not in Global data): at most this many of one coin per exchange (the count edit's limit)
  maxPerRow: 9999,
  // ENGINE-CHOSEN (not in Global data): exchange range around the NPC (world units), the same as the NPC shops
  npcRadius: 12,
  // ENGINE-CHOSEN (not in Global data): label of the exp window's DIL tag (1001:241 is empty in the string table)
  dilTagText: 'DIL',
  // ENGINE-CHOSEN (not in Global data): notice when Exchange is pressed with every count at 0
  emptyText: 'Set how many items to exchange first.',
  // ENGINE-CHOSEN (not in Global data): notice when EXP coins are exchanged at the maximum level
  maxLevelText: 'You are already at the maximum level.',
  // ENGINE-CHOSEN (not in Global data): the question asked before an exchange is carried out
  confirmText: 'Exchange the selected items?',
});