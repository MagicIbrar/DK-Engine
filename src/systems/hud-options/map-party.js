// Native ui_new_mapwnd.txt pan_party: mainbar_minimap126,10x10; FILE Z→u,
// FILE X→v. Shared authority already limits visible actors to the current scene.
export function worldMapPartyRows(game){
 const net=game.network,self=net?.self,index=Number(game.world?.info?.index);
 if(!game.player||!net?.active||!net.ready||net.party?.active!==true||!self||Number(self.map)!==index)return [];
 const rows=[];
 for(const member of net.party.members||[]){
  if(!member?.id||member.id===self.id||Number(member.map)!==index)continue;
  const actor=net.players?.get?.(member.id),scene=actor?._serverScene,pose=actor?._serverPose;
  if(actor?.kind!=='player'||actor.networkId!==member.id||actor.disposed||!scene||!pose||Number(scene.map)!==index||(scene.instanceId||null)!==(self.instanceId||null)||!self.instanceId&&(scene.channel||0)!==(self.channel||0)||![pose.tx,pose.tz].every(Number.isFinite))continue;
  rows.push({id:member.id,name:member.name||actor.name||'',x:pose.tx,z:pose.tz});
 }
 return rows;
}
export function drawWorldMapParty(game,data,{paintIcon,toTex,width=512,height=512}){
 const elements=data.partyEls||=new Map(),seen=new Set();
 for(const member of worldMapPartyRows(game)){
  seen.add(member.id);let el=elements.get(member.id);
  if(!el){el=document.createElement('div');el.className='uw-icon';el.style.width=el.style.height='10px';el.style.pointerEvents='none';paintIcon(el,{sprite:['mainbar_minimap',126]});data.layer.appendChild(el);elements.set(member.id,el);}
  const point=toTex(member.x,member.z),u=Math.max(0,Math.min(width-1,point.u)),v=Math.max(0,Math.min(height-1,point.v));
  el.title=member.name;el.style.left=`${Math.round(u-5)}px`;el.style.top=`${Math.round(v-5)}px`;
 }
 for(const [id,el]of elements)if(!seen.has(id)){el.remove();elements.delete(id);}
}
