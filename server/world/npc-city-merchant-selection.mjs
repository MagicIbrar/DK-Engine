import {npcMerchantOffers,npcMerchantResidentPriority} from './npc-merchant.mjs';
import {commerceAskPrice,npcPublicHighTierGear} from './npc-commerce-value.mjs';
import {sameScene} from './scene.mjs';

// ENGINE-CHOSEN admission order only. Inspect the complete already-eligible
// cohort, not its first forty quest/class matches. Cheap native stock screening
// precedes expensive equipment checks; yielding keeps other clients responsive.
// A selection grants no inventory, location, extra capacity or shop permission.
export async function npcPreferredCityMerchant(world,candidates,{map=150,channel=0,allowQuestPause=false,yieldTurn=()=>new Promise(resolve=>setImmediate(resolve))}={}){
 const scene={map,channel},audience=()=>[...world.players.values()].some(p=>p.profile?.npcPlayer!==true&&p.npcPlayer!==true&&!p.dead&&!p.leaving&&sameScene(p,scene));
 if(map!==150||!audience())return null;
 const db=world.data.itemDB;
 for(let i=0;i<candidates.length;i++){
  if(i&&i%40===0){await yieldTurn();if(!audience())return null;}
  const row=candidates[i],[account,profile]=row;
  if(world.players.has(account)||!profile.inventory?.some(item=>!item.bound&&!item.npcStartingStock&&npcPublicHighTierGear(db,item,commerceAskPrice(db,item,{owner:profile.id}))))continue;
  if(!npcMerchantResidentPriority(world,profile,{map,channel,allowQuestPause}))continue;
  const actor={profile,npcPlayer:true,characterId:profile.id};
  // Check the offers the ordinary shop would actually list, including its
  // three-offer cap and native ownership/equipment/quest/cooldown protections.
  if(npcMerchantOffers(world,actor).some(offer=>npcPublicHighTierGear(db,profile.inventory.find(item=>item.uid===offer.uid),offer.price)))return row;
 }
 return null;
}
