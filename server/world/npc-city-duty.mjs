// ENGINE-CHOSEN quiet-city planner quotas. These are runtime intentions only,
// never native rewards, durable profile edits or authority to admit an actor.
export const NPC_CITY_DUTY_POLICY=Object.freeze({map:150,residents:55,quest:2,services:8,maintenanceMs:5000});
export function npcCityResidentTarget({map,native,interest,optionalWorkAllowed,scaled}){return interest&&map===150&&native>=55&&optionalWorkAllowed===true?55:scaled;}
export function npcCityDamageWake(p,b,event,now){if(p?.map!==150||p.npcPlayer!==true||event?.targetId!==p.id||event.type!=='damage'||!(Number(event.amount)>0)||!(b?.cityQuietUntil>now))return false;b.next=Math.min(b.next,now);b.cityQuietUntil=0;return true;}
export function npcCityDutyEligible(p,b,{protectedActor=false}={}){
 return !!p&&!!b&&p.map===150&&!p.instanceId&&!p.channel&&p.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile.authority==='server'
  &&!p.leaving&&!p.revoked&&!p.dead&&!protectedActor&&!p.partyId&&!p.tradeId&&!p.commandActive&&!p.progressCommitting&&!p.sceneTransition
  &&!p.attackTarget&&!p._skills?.engine?.casting&&!p._skills?.engine?.active&&!b.objectiveFlight&&!b.refineRestore&&!b.fishingReserved
  &&p.profile.npcEquipment?.phase!=='working'&&!b.follow&&!['follow','lure','wait'].includes(b.mode)&&!b.queue?.length&&!b.questId
  &&!Object.keys(p.profile.quests?.active||{}).length;
}
export function npcCityDuties(rows,{eligible=npcCityDutyEligible,policy=NPC_CITY_DUTY_POLICY}={}){
 const candidates=rows.filter(([p,b])=>eligible(p,b)).sort(([a],[b])=>String(a.account).localeCompare(String(b.account))),result=new Map();
 const accepted=rows.filter(([p,b])=>p?.map===150&&p.npcPlayer===true&&p.profile?.npcPlayer===true&&!p.instanceId&&!p.channel&&!p.leaving&&!p.dead&&(b?.questId||Object.keys(p.profile?.quests?.active||{}).length)).length;
 const questSlots=Math.max(0,policy.quest-accepted);
 // Real open stalls retain ownership rather than being reassigned a quest.
 const planners=candidates.filter(([p])=>!p.pcShopOpen);
 for(const [p]of candidates)if(p.pcShopOpen)result.set(p.account,'shop');
 for(let i=0;i<planners.length;i++)result.set(planners[i][0].account,i<questSlots?'quest':i<questSlots+policy.services?'service':'rest');
 return result;
}
// `preference` (optional, archetype mode): {now, caps:{quest,service}, order(p,epoch)
// -> ordered duty kinds, dwell(p,kind,epoch) -> ms}. Without it the legacy fixed
// quotas (2 quest / 8 service / rest) apply unchanged. With it each resident gets
// its archetype's preferred EXISTING duty while bounded caps remain, assignments
// rotate after a finite dwell (held actors keep custody), and residents denied
// their preference are served first next time (no indefinite starvation).
export function createNpcCityDutyPlanner({policy=NPC_CITY_DUTY_POLICY,preference=null}={}){
 const assigned=new Map(),epochs=new Map(),denied=new Map();
 return {
  update(rows,{eligible=npcCityDutyEligible}={}){
   rows=rows.filter(([p,b])=>p&&b); // a brain can briefly outlive its departed player
   const live=new Map(rows.filter(([p])=>p&&p.map===150&&!p.instanceId&&!p.channel&&!p.dead&&!p.leaving).map(([p])=>[p.account,p]));
   for(const [id,row]of assigned)if(live.get(id)!==row.player){assigned.delete(id);epochs.delete(id);denied.delete(id);}
   if(preference){const at=preference.now();for(const [p,b]of rows)if(live.get(p?.account)===p&&assigned.get(p.account)?.player===p&&at>=assigned.get(p.account).until&&eligible(p,b)){assigned.delete(p.account);epochs.set(p.account,(epochs.get(p.account)||0)+1);}}
   const accepted=rows.filter(([p,b])=>live.get(p?.account)===p&&(b?.questId||Object.keys(p.profile.quests?.active||{}).length)).length;
   const count=kind=>[...assigned.values()].filter(row=>row.kind===kind&&!rows.some(([p,b])=>p===row.player&&(b?.questId||Object.keys(p.profile.quests?.active||{}).length))).length;
   const stock=p=>p.profile.npcInitialMarketStock?.version===1&&p.profile.npcInitialMarketStock.uids?.some(uid=>p.profile.inventory?.some(i=>i.uid===uid&&!i.bound));
   for(const [p,b]of rows.filter(([p,b])=>eligible(p,b)).sort(([a],[b])=>Number(stock(b))-Number(stock(a))||(preference?(denied.get(b.account)||0)-(denied.get(a.account)||0):0)||String(a.account).localeCompare(String(b.account)))){
    if(assigned.has(p.account))continue;
    if(!preference){
     const kind=p.pcShopOpen?'shop':!stock(p)&&count('quest')+accepted<policy.quest?'quest':count('service')<policy.services?'service':'rest';
     assigned.set(p.account,{player:p,kind});continue;
    }
    const epoch=epochs.get(p.account)||0,order=preference.order(p,epoch)||['rest'],open={quest:!stock(p)&&count('quest')+accepted<preference.caps.quest,service:count('service')<preference.caps.service,rest:true};
    let kind=p.pcShopOpen?'shop':stock(p)&&open.service?'service':order.find(k=>open[k])||'rest',reason=p.pcShopOpen?'open-stall':stock(p)&&kind==='service'?'owned-stock':kind===order[0]?'preferred':order[0]+'-cap';
    if(kind!==order[0]&&!p.pcShopOpen&&!(stock(p)&&kind==='service'))denied.set(p.account,(denied.get(p.account)||0)+1);else denied.delete(p.account);
    assigned.set(p.account,{player:p,kind,reason,epoch,until:preference.now()+Math.max(1000,Number(preference.dwell(p,kind,epoch))||120000)});
   }
   return new Map(rows.filter(([p,b])=>eligible(p,b)&&assigned.get(p.account)?.player===p).map(([p])=>[p.account,p.pcShopOpen?'shop':assigned.get(p.account).kind]));
  },
  assigned:p=>assigned.get(p?.account)?.player===p?assigned.get(p.account).kind:null,
  detail:p=>{const row=assigned.get(p?.account);return row?.player===p?{kind:row.kind,reason:row.reason||'legacy-quota',epoch:row.epoch??0,until:row.until??null}:null;},
  clear:()=>{assigned.clear();epochs.clear();denied.clear();}
 };
}
export function npcCityBeggarIdentity(p){
 // One canonical birth slot per200; use saved identity, never reroll by scene.
 const seed=p?.profile?.npcSeed,id=p?.profile?.npcRosterId;
 const slot=Number.isSafeInteger(seed?.birthSlot)?seed.birthSlot:/^r[a-f0-9]{24}$/.test(id||'')?Number(BigInt('0x'+id.slice(1))%200n):seed?.slot;
 return Number.isSafeInteger(slot)&&slot>=0&&slot%200===199;
}
export function createNpcCityRequester({now,eligible=npcCityBeggarIdentity,live=()=>true,cooldownMs=1200000,ignoreMs=8000,followMs=20000}={}){
 let active=null;const next=new Map();
 return {
  observe(p,other,text){if(active?.player!==p||active.target!==other)return;const body=String(text).trim();if(/\b(no|stop|leave|ignore|decline|go away)\b/i.test(body))active.until=now();else if(body)active.until=Math.min(active.started+followMs,now()+followMs);},
  step(p,{valid=true,canRequest=true,humans=[]}={}){
   const at=now();
   if(active&&(!live(active.player,active.target)||at>=active.until)){const own=active.player===p;active=null;if(own)return {kind:'finish'};}
   if(active?.player===p){if(!valid||!humans.includes(active.target)||at>=active.until){active=null;return {kind:'finish'};}return {kind:'follow',target:active.target};}
   if(active||!valid||!canRequest||!eligible(p)||at<(next.get(p.account)||0))return null;
   const target=humans[0];if(!target)return null;
   active={player:p,target,started:at,until:at+ignoreMs};next.set(p.account,at+cooldownMs);
   return {kind:'request',target,text:'anyone got a few spare dil?'};
  },
  clear(){active=null;next.clear();},
 };
}
