import {NPC} from '../../actors/npc.js';
import {fetchText} from '../../engine/assets.js';
import {parseCSV} from '../../formats/binreader.js';
import {AuthoredEffectsData} from '../items/authored-effects-data.js';
import {EffectPlayer} from '../skills/effects.js';
import {globalConfirm} from '../../ui/uiwin/global-windows.js';
// Entering asks Global's msgbox/cashitem/ui_potaluse first: 100:30 "Portal", lbl_text 170:36 "Would you like to use the Portal?"
export const PORTAL_USE_BOX='game2:msgbox:cashitem:ui_potaluse';
const portalQuestion=game=>String(game.uiwin?.strings?.get?.({group:'NORMAL',cate:170,code:36})||'Would you like to use the Portal?');

// The portal picking body and the sustain scene are native portal_shape and
// modeleffect31/1/<portal effect>/2 resources, not the fixed town portal art.
const library=new AuthoredEffectsData();let effectRows;
async function sustain(shape){
 const rows=await(effectRows||=(fetchText('script/effect/modeleffect.csv').then(parseCSV).catch(e=>{effectRows=null;throw e;})));
 const r=rows.find(r=>Number(r[0])===31&&Number(r[1])===1&&Number(r[2])===Number(shape.fieldEffect)&&Number(r[3])===2);
 if(!r)throw Error('The original personal portal effect is unavailable.');
 const ref={cate:Number(r[4]),id:Number(r[5]),scene:Number(r[6]),timeMs:Number(r[7])};await library.load(ref);return ref;
}
export function personalPortalClientState(network,now=performance.now()){
 const self=network.self,r=self?.profile?.personalPortal,c=network._serverClock,server=c?c.time+(now-c.at):Date.now();
 return network.active&&network.ready&&!self.instanceId&&r?.v===1&&r.characterId===self.characterId&&typeof r.id==='string'&&['origin','away'].includes(r.stage)&&Number.isFinite(r.expiresAt)&&server<r.expiresAt?r:null;
}
class PersonalPortalActor extends NPC{
 constructor(game,record,shape,expired){super(game,{index:-1,name:'Personal Portal',roles:[],jobs:[]},{x:record.x,z:record.z,dirDeg:0});this.personalPortalId=record.id;this.portalShape=shape;this.expired=expired;this.portalWorld=game.world;}
 async _load(){
  const s=this.portalShape;if(!s?.fieldMesh||!s?.fieldTpack)throw Error('The original personal portal body is unavailable.');
  const [model,ref]=await Promise.all([this.game.models.loadStatic(s.fieldMesh,{tpackKey:s.fieldTpack}),sustain(s)]);
  if(this.disposed||this.game.world!==this.portalWorld)return;
  this._setStatic(model);this._measure();this.scale=Number(s.scale)||1;
  this.portalFx=new EffectPlayer(this.game,library);this.portalRef=ref;
 }
 update(dt){
  if(this.disposed)return;if(this.expired()){this.dispose();return;}
  super.update(dt);if(!this.portalFx)return;
  const s=this.portalShape,offset=s.offset||[0,0,0];
  if(!this.portalHandle||this.portalHandle.done)this.portalHandle=this.portalFx.playAt({x:this.x+Number(offset[0]||0),y:this.y+Number(offset[1]||0),z:this.z+Number(offset[2]||0),yaw:this.yaw,height:0},this.portalRef,{loop:true,scale:this.scale});
  this.portalFx.update(dt);
 }
 dispose(){this.portalFx?.dispose();this.portalFx=null;super.dispose();}
}
export function installPersonalPortal(game,network,travelData){
 let actor=null,disposed=false;
 const clear=()=>{if(!actor)return;const a=actor;actor=null;const n=game.npcs?.indexOf(a);if(n>=0)game.npcs.splice(n,1);if(game.controller?.order?.npc===a)game.controller.stop?.();if(game.player?.target===a)game.controller?.setTarget?.(null);a.dispose();};
 const sync=()=>{
  const r=personalPortalClientState(network),self=network.self;
  const visible=!disposed&&r?.stage==='origin'&&r.map===self.map&&r.channel===(self.channel??0)&&game.world?.info?.index===r.map;
  if(!visible){clear();return;}
  if(actor&&!actor.disposed&&actor.personalPortalId===r.id&&actor.portalWorld===game.world)return;
  clear();const id=r.id;actor=new PersonalPortalActor(game,r,travelData.portalShape,()=>{const current=personalPortalClientState(network),expired=disposed||current?.id!==id||current.stage!=='origin'||game.world!==actor?.portalWorld;if(expired)clear();return expired;});
  game.npcs.push(actor);void actor.load();
 };
 const wrap=()=>{const w=game.windows;if(!w?.openNpc||w.openNpc._personalPortal)return;const inner=w.openNpc.bind(w);const open=npc=>{if(!npc?.personalPortalId)return inner(npc);if(npc===actor&&!npc.disposed)void globalConfirm(game,PORTAL_USE_BOX,portalQuestion(game),{body:'lbl_text'}).then(yes=>{if(yes&&npc===actor&&!npc.disposed)return network.action('npctravel',{operation:'personal-out',portalId:npc.personalPortalId});});return true;};open._personalPortal=true;w.openNpc=open;};
 const snapshot=network._snapshot.bind(network);network._snapshot=record=>{const revision=network._snapshotRevision;snapshot(record);if(!disposed&&network._snapshotRevision!==revision)sync();};
 const offMap=game.events?.on?.('map',sync),offSystems=game.events?.on?.('systems',wrap),dispose=network.dispose.bind(network);
 network.dispose=()=>{disposed=true;clear();offMap?.();offSystems?.();dispose();};wrap();sync();
 return {sync,clear};
}
