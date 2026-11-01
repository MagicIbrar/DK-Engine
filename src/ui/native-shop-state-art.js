// Narrow repairs for authored native controls with missing state rows. No atlas
// bounds are inferred: coinexchange18 is the real plus-Click row. Supply and VIP
// reuse existing states (ENGINE-CHOSEN presentation), retaining hitboxes/actions.
const controls = {
  coinPlus: {group:'coinexchange',states:{none:16,over:17,down:108},fallback:{down:18}},
  supplyPurchase: {group:'supplymachine_1',states:{none:10,over:11,down:12},fallback:{over:10,down:10}},
  vipDown: {group:'itemchoice',states:{none:7,over:8,down:9},fallback:{down:8}},
};
export function repairNativeShopStateArt(button,kind,table) {
  const rule=controls[kind],images=button?.spec?.images;
  if(!rule||!button?.setImage||images?.length!==Object.keys(rule.states).length||!images.every(i=>i.screen?.toLowerCase()===rule.group&&i.index===rule.states[i.key]))return;
  for(const image of images) {
    const to=rule.fallback[image.key];
    if(to!==undefined&&!table?.has(`${rule.group}#${image.index}`)&&table?.has(`${rule.group}#${to}`))button.setImage(image.key,image.screen,to);
  }
}
