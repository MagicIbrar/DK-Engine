// ENGINE-CHOSEN player-commerce preferences. Native item prices are anchors,
// not evidence of a Global player-market price or a native rank multiplier.
export const NPC_COMMERCE_VALUE_POLICY=Object.freeze({discountEvery:10,discountPercent:15,buyPercent:70,budgetPercent:25,wealthyDil:100000000});
export function commerceHash(value){let h=2166136261;for(const c of String(value)){h^=c.charCodeAt(0);h=Math.imul(h,16777619);}return h>>>0;}
export function nativeCommerceAnchor(db,item){const d=db?.def(item?.itemIndex),v=Number(d?.price)>0?Number(d.price):Number(d?.sell);return Number.isSafeInteger(v)&&v>0&&v<=10000000000?v:null;}
export function commerceAskPrice(db,item,{owner='',policy=NPC_COMMERCE_VALUE_POLICY}={}){const anchor=nativeCommerceAnchor(db,item);if(anchor===null)return null;const discounted=commerceHash(owner+':'+item.uid)%policy.discountEvery===0;return Math.max(1,Math.floor(anchor*(discounted?100-policy.discountPercent:100)/100));}
export function npcPublicHighTierGear(db,item,price,minPrice=10000000){const d=db?.def(item?.itemIndex);return !!d&&['weapon','offhand','helmet','armor','pants','glove','boots','accessory'].includes(d.slot)&&Number.isSafeInteger(price)&&price>=minPrice&&(Number(d.reqLv)>=150||Number(d.itemLv)>=6||Number(d.rank)>=6);}
export function commerceBuyBudget(profile,{policy=NPC_COMMERCE_VALUE_POLICY}={}){const funds=profile?.dil;return Number.isSafeInteger(funds)&&funds>0?Math.floor(funds*policy.budgetPercent/100):0;}
export function commerceWealth(profile,{policy=NPC_COMMERCE_VALUE_POLICY}={}){return Number.isSafeInteger(profile?.dil)&&profile.dil>=policy.wealthyDil?'funded trader':'ordinary trader';}
