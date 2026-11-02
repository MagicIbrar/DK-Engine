import {fetchBuffer} from '../engine/assets.js';
import {decodeImageAsync} from '../formats/image.js';
import {AuthoredEffectsData} from '../systems/items/authored-effects-data.js';
import {evalKeys} from '../systems/skills/effects.js';
import {flipFrame} from '../systems/skills/fx-units.js';
import {GUILD_GLORY_ART_CHOSEN as CHOSEN} from '../config/engine-chosen-guild.js';
import {globalEmitCount,globalSpawnRotation,globalStepRotation,globalAgeFraction} from '../systems/skills/global-particle-rules.js'; // LANE-63

// Native Guild / Alliance of Glory illumination: itemcash Type0 Code16/30 EventType -> effectscene cate 8 ("UI") scene 1.
// UI-attached cate-8 scenes are authored x right / y up (3019's side flashes sit at (+-.3,0)/(0,+-.3), 3004's lights orbit
// (-.31,.35)..(.31,-.29), fire/ice particles rise along spawndirection 0 1 0) and their camera sprites span x wide by z HIGH
// (3019/3022 left/right lines scale (.2,.2,1..2) while the top/bottom ones are (1..2,.2,.2); 3020's (2,0,1)..(5,0,3); 8:1125's
// button flash (1,1.5,.05)); y is depth there. Blend 'add' is added light. Attachment scale / cycle / draw order:
// src/config/engine-chosen-guild.js GUILD_GLORY_ART_CHOSEN. Absent scenes, inactive controls and other unit families stay absent.
const MARK_PX=18;   // .dk-plate-mark (src/ui/style.css); the Glory column scales the whole crest and its native effect to 24 px
export const GUILD_ART_LAYOUT=Object.freeze({markPixels:MARK_PX,borderUnits:CHOSEN.EMBLEM_BORDER_UNITS,unitPixels:MARK_PX/(2*CHOSEN.EMBLEM_BORDER_UNITS),maxDpr:CHOSEN.MAX_DPR,maxMarks:64,maxTextures:128,cycleMs:CHOSEN.CYCLE_MS,maxExtentUnits:CHOSEN.MAX_EXTENT_UNITS,maxStepMs:CHOSEN.MAX_STEP_MS});
const U=GUILD_ART_LAYOUT.unitPixels,clamp01=v=>Math.max(0,Math.min(1,v));
/** Control state at `elapsed` ms of the repeating scene: native life window, keys over 0..999 of it, sprite size [x, z]. */
export function sampleGuildSprite(control,unit,elapsed,period,frames=1){
 if(control.active===false)return null;const time=((elapsed%period)+period)%period,start=(Number(control.life?.[0])||0)*period/1000,end=(Number(control.life?.[1])||1000)*period/1000;
 if(time<start||time>=end||end<=start)return null;const age=time-start,key=Math.min(999,age/(end-start)*999),scale=evalKeys(control.scale,key,3)||[1,1,1],pos=evalKeys(control.position,key,3)||control.pos||[0,0,0];
 return {alpha:clamp01(evalKeys(control.alpha,key,1)?.[0]??1),color:evalKeys(control.color,key,3)||[1,1,1],scale:[scale[0],scale[2]??scale[0]],rotation:evalKeys(control.rotation,key,1)?.[0]||0,position:[pos[0]||0,pos[1]||0],origin:[pos[0]||0,pos[1]||0,pos[2]||0],frame:flipFrame(unit,age,frames,0),size:Number(unit.size)||1,cycle:Math.floor(elapsed/period)};
}
// Native sprite colour keys multiply texture RGB; they do not replace its colour or alpha. Use the original decoded pixels.
export function tintGuildPixels(source,target,color){for(let i=0;i<source.length;i+=4){target[i]=source[i]*color[0];target[i+1]=source[i+1]*color[1];target[i+2]=source[i+2]*color[2];target[i+3]=source[i+3];}return target;}
/** Spawn `count` native particles (effectdata activestate/lifetime/velocity/spawndirection/startrange/endposition/particlesize/
 * colorrange) at the control origin, with the shared world ParticleUnit's reading of those fields (src/systems/skills/fx-units.js). */
export function spawnGuildParticles(parts,unit,state,count,random=Math.random){
 const e=unit.emitter||{},max=Math.max(1,Math.min(160,Number(e.max)||20)),st=e.state||'explode',planar=st==='explodeplane'||st==='directplane'||st==='plane',o=state.origin,span=(r,i=0)=>r[i]+random()*Math.max(0,(r[1]??r[0])-r[0]),unitv=v=>{const l=Math.hypot(...v);return l>1e-6?v.map(x=>x/l):null;};
 for(let i=0;i<count&&parts.length<max;i++){
  const lr=e.lifetimeMs||[500,500],life=(lr[0]+random()*Math.max(0,(lr[1]||lr[0])-lr[0]))/1000,speed=span(e.velocity||[0,0]),sd=e.spawnDir||[0,0,0];
  let d=unitv(sd);if(!d)d=unitv([random()*2-1,planar?0:random()*2-1,random()*2-1])||[1,0,0];else d=unitv(d.map(v=>v+(random()-.5)*.3))||d;
  const sr=e.startRange||[0,0],rad=span(sr)*(state.scale[0]||1),p=o.slice();
  if(rad>0){const a=random()*Math.PI*2,off=st==='exploderange'||planar||st==='gather'?[Math.cos(a)*rad,0,Math.sin(a)*rad]:d.map(v=>v*rad);if(st==='gather'&&!planar)off[1]=(random()-.5)*rad;for(let k=0;k<3;k++)p[k]+=off[k];}
  let v=d.map(x=>x*speed);if(st==='gather'){const ep=e.endPos||[0,0,0];v=ep.map((x,k)=>(x+o[k]-p[k])/Math.max(.05,life));}
  const ps=e.particleSize||[0,0],size=(Number(unit.size)||1)*((ps[0]||ps[1])?span(ps):1),cr=(Number(e.colorRange)||0)/100;
  parts.push({p,v,t:0,life,size,rot:globalSpawnRotation(e.addRotate,random),tint:cr>0?[1-random()*cr,1-random()*cr,1-random()*cr]:null});
 }
}
/** Advance particles dt seconds: acceleration along the velocity, gravity, addrotate spin (Global FUN_011a7980: addrotate x age
 * fraction before this tick, LANE-63); expired ones leave. */
export function stepGuildParticles(parts,unit,dt){
 const e=unit.emitter||{},g=e.gravity||[0,0,0],acc=Number(e.acceleration)||0;
 for(let i=parts.length-1;i>=0;i--){const q=parts[i],age0=globalAgeFraction(q.t,q.life);q.t+=dt;if(q.t>=q.life){parts.splice(i,1);continue;}const l=Math.hypot(...q.v);if(acc&&l>1e-4)for(let k=0;k<3;k++)q.v[k]+=q.v[k]/l*acc*dt;for(let k=0;k<3;k++){q.v[k]+=(g[k]||0)*dt;q.p[k]+=q.v[k]*dt;}q.rot=globalStepRotation(e.addRotate,age0,q.rot);}
 return parts;
}
// Farthest scene distance a layer can light (rotation-safe half-diagonal; particles: spawn ring + flight + streak).
const keysMax=(keys,i,fallback)=>keys?.length?Math.max(...keys.map(k=>Math.abs(k[i]??k[k.length-1]))):fallback;
/** Preserve the authored UI origin. Majesty and Best Guild deliberately sit beside the crest. */
export function guildSceneOffset(){return [0,0];}
function layerExtent({control:c,unit:u},[ox,oy]=[0,0]){
 const pos=c.position?.length?Math.max(...c.position.map(k=>Math.hypot((k[1]||0)-ox,(k[2]||0)-oy))):Math.hypot((c.pos?.[0]||0)-ox,(c.pos?.[1]||0)-oy),s=Math.max(keysMax(c.scale,1,1),keysMax(c.scale,3,keysMax(c.scale,1,1))),size=Number(u.size)||1;
 if(u.type!=='particle')return pos+size*s*Math.SQRT1_2;
 const e=u.emitter||{},life=Math.max(...(e.lifetimeMs||[500]))/1000,ps=Math.max(1,...(e.particleSize||[1]).map(Math.abs)),g=Math.hypot(...(e.gravity||[0,0,0])),v=Math.max(0,...(e.velocity||[0]).map(Math.abs))+Math.max(0,Number(e.acceleration)||0)*life;
 return pos+Math.max(0,...(e.startRange||[0]))*keysMax(c.scale,1,1)+v*life+g*life*life/2+Math.hypot(...(e.endPos||[0,0,0]))+size*ps*s*(e.followDir?2:1)*Math.SQRT1_2;
}
export class GuildNameplateArt{
 constructor({db,data=new AuthoredEffectsData(),image=async key=>decodeImageAsync(await fetchBuffer(key)),makeCanvas=()=>document.createElement('canvas'),dpr=()=>globalThis.devicePixelRatio||1,onUnsupported=()=>{},visible=()=>true,random=Math.random}={}){Object.assign(this,{db,data,image,makeCanvas,dpr,onUnsupported,visible,random});this.entries=new Map();this.prepared=new Map();this.images=new Map();this.closed=false;}
 async prepare(itemIndex,kind='guild'){
  const key=kind+':'+itemIndex;if(this.prepared.has(key))return this.prepared.get(key);if(this.prepared.size>=64)return {supported:false,reason:'bounded art cache full'};
  const pending=(async()=>{const db=typeof this.db==='function'?this.db():this.db,def=db?.def(Number(itemIndex));if(!def||Number(def.type)!==0||Number(def.code)!==(kind==='alliance'?30:16))return {supported:false,reason:'not a native registered glory item'};
   const id=Number(def.eventType);if(!Number.isInteger(id)||id<=0)return {supported:false,reason:'native EventType binding unavailable'};
   await this.data.load({cate:8,id});const scene=this.data.scene('8:'+id),controls=scene?.scenes?.[1]?.controls;if(!controls)return {supported:false,reason:'matching native UI scene unavailable',scene:id};
   const layers=[],unsupported=[];for(const control of controls){if(control.active===false)continue;const unit=this.data.unit(scene.res[control.unit]);
    const particle=unit?.type==='particle'&&(!unit.leaf||unit.leaf==='sprite');if(!(unit?.type==='sprite'||particle)||control.bone||control.boneAnim||control.animPath||control.randomStart||control.color?.some(k=>k.length!==4||k.some(v=>!Number.isFinite(v)))||!['add','modulate',undefined].includes(unit.blend)){unsupported.push({unit:control.unit,type:unit?.type||'missing',reason:'unsupported authored UI control'});continue;}
    const keys=unit.frames?.length?unit.frames:unit.texture?[unit.texture]:[];if(!keys.length){unsupported.push({unit:control.unit,reason:'missing native texture'});continue;}
    try{const images=await Promise.all(keys.map(key=>this.texture(key)));if(images.some(i=>!i))throw Error('Native texture unavailable');layers.push({kind:particle?'particle':'sprite',add:unit.blend!=='modulate',control,unit,images});}catch{unsupported.push({unit:control.unit,reason:'native resource unavailable'});}
   }
   const period=GUILD_ART_LAYOUT.cycleMs,offset=guildSceneOffset(layers),extent=Math.min(GUILD_ART_LAYOUT.maxExtentUnits,Math.max(CHOSEN.EMBLEM_BORDER_UNITS,...layers.map(l=>layerExtent(l,offset)))),result={supported:layers.length>0,itemIndex:Number(itemIndex),scene:id,period,offset,extent,layers,sprites:layers.filter(l=>l.kind==='sprite'),particles:layers.filter(l=>l.kind==='particle'),unsupported,reason:layers.length?'native authored sprite/particle controls':'no supported active native controls',policy:'native scene; ENGINE-CHOSEN attachment (GUILD_GLORY_ART_CHOSEN)'};if(unsupported.length)this.onUnsupported({itemIndex:Number(itemIndex),scene:id,unsupported});return result;
  })().catch(()=>({supported:false,reason:'native art loading failed'}));this.prepared.set(key,pending);return pending;
 }
 async texture(key){if(this.images.has(key))return this.images.get(key);if(this.images.size>=GUILD_ART_LAYOUT.maxTextures)throw Error('Bounded native art texture cache full');const task=Promise.resolve(this.image(key)).then(image=>{if(!image?.width||!image?.height||!image.data)throw Error('Native image unavailable');const canvas=this.makeCanvas(),ctx=canvas.getContext('2d');canvas.width=image.width;canvas.height=image.height;const pixels=ctx.createImageData(image.width,image.height);pixels.data.set(image.data);ctx.putImageData(pixels,0,0);canvas._guildPixels=pixels.data;return canvas;});this.images.set(key,task);return task;}
 tint(sprite,image,color){if(color.every(c=>c===1))return image;let t=sprite.tint;if(!t||t.canvas.width!==image.width||t.canvas.height!==image.height){const canvas=this.makeCanvas();canvas.width=image.width;canvas.height=image.height;const context=canvas.getContext('2d');t=sprite.tint={canvas,context,pixels:context.createImageData(image.width,image.height)};}const key=color.join(':');if(t.image!==image||t.key!==key){tintGuildPixels(image._guildPixels,t.pixels.data,color);t.context.putImageData(t.pixels,0,0);t.image=image;t.key=key;}return t.canvas;}
 set(mark,itemIndex,{kind='guild',now=performance.now()}={}){
  if(!mark||this.closed)return Promise.resolve(null);const key=itemIndex?kind+':'+Number(itemIndex):'';const old=this.entries.get(mark);if(old?.key===key)return old.ready;if(old)this.remove(mark);if(!key)return Promise.resolve(null);if(this.entries.size>=GUILD_ART_LAYOUT.maxMarks)return Promise.resolve(null);
  const entry={key,start:now,last:undefined,canvases:[],emitters:new Map(),prepared:null,ready:null};this.entries.set(mark,entry);entry.ready=this.prepare(Number(itemIndex),kind).then(prepared=>{if(this.closed||this.entries.get(mark)!==entry)return null;entry.prepared=prepared;if(!prepared.supported)return prepared;
   // Above the native crest (bg z1 < symbol z2 < effect z3), retaining authored positions; modulate units under added light.
   const side=Math.ceil(2*prepared.extent*U)+2;entry.side=side;entry.previous={isolation:mark.style.isolation,filter:mark.style.filter,z:[]};mark.style.isolation='isolate';mark.style.filter='';for(const child of [...mark.children]){entry.previous.z.push([child,child.style.zIndex]);child.style.zIndex=String(child.className).split(/\s+/).includes('icon')?'2':'1';}
   for(const add of [false,true]){if(!prepared.layers.some(l=>l.add===add))continue;const canvas=this.makeCanvas();canvas.className='dk-guild-native-art';canvas.setAttribute?.('aria-hidden','true');Object.assign(canvas.style,{position:'absolute',left:'50%',top:'50%',width:side+'px',height:side+'px',transform:'translate(-50%, -50%)',pointerEvents:'none',zIndex:CHOSEN.DRAW_OVER_EMBLEM?'3':'1',mixBlendMode:add?'plus-lighter':'normal'});mark.appendChild(canvas);entry.canvases.push({canvas,add});}
   entry.canvas=entry.canvases.at(-1).canvas;mark.classList?.toggle('dk-plate-glory',true);if(this.visible(mark))this.paint(entry,now);return prepared;
  });return entry.ready;
 }
 paint(entry,now){if(!entry.canvases.length||!entry.prepared?.supported)return;const {prepared}=entry,ratio=Math.max(1,Math.min(GUILD_ART_LAYOUT.maxDpr,Number(this.dpr())||1)),side=entry.side,px=Math.round(side*ratio),elapsed=now-entry.start,cx=side/2-(prepared.offset?.[0]||0)*U,cy=side/2+(prepared.offset?.[1]||0)*U,dt=entry.last===undefined?0:Math.max(0,Math.min(GUILD_ART_LAYOUT.maxStepMs,now-entry.last))/1000;entry.last=now;
  const contexts=new Map();for(const {canvas,add}of entry.canvases){if(canvas.width!==px||canvas.height!==px){canvas.width=px;canvas.height=px;}const ctx=canvas.getContext('2d');ctx.setTransform(ratio,0,0,ratio,0,0);ctx.clearRect(0,0,side,side);contexts.set(add,ctx);}
  prepared.layers.forEach((layer,index)=>{const {control,unit,images}=layer,ctx=contexts.get(layer.add),state=sampleGuildSprite(control,unit,elapsed,prepared.period,images.length);
   ctx.save();ctx.globalCompositeOperation=layer.add?'lighter':'source-over';
   if(layer.kind==='sprite'){if(state&&state.alpha>0)this.draw(ctx,layer,images[state.frame],state.color,state.alpha,cx+state.position[0]*U,cy-state.position[1]*U,U*state.size*state.scale[0],U*state.size*state.scale[1],-state.rotation*Math.PI/180);}
   else{const em=entry.emitters.get(index)||{parts:[],emitAcc:0,state:null};entry.emitters.set(index,em);stepGuildParticles(em.parts,unit,dt);
    if(state){em.state=state;const e=unit.emitter||{};
      // LANE-63: Global emit tick FUN_011a65e0 for every state (emitrate > 0 = ms per particle, < 0 = per frame, max 10 per tick);
      // the burst-per-cycle and the pool-fill rate were engine choices.
      const k=globalEmitCount(em,dt*1000,e.rate);if(k>0)spawnGuildParticles(em.parts,unit,state,k,this.random);}
    const s=em.state;if(s)for(const q of em.parts){const k=q.t/q.life,alpha=s.alpha*(k>.7?1-(k-.7)/.3:1),speed=Math.hypot(q.v[0],q.v[1]),follow=unit.emitter?.followDir&&speed>1e-3;if(alpha<=0)continue;
     this.draw(ctx,layer,images[flipFrame(unit,elapsed,images.length,.5)],q.tint?s.color.map((c,i)=>c*q.tint[i]):s.color,alpha,cx+q.p[0]*U,cy-q.p[1]*U,U*q.size*s.scale[0],U*q.size*s.scale[1]*(follow?2:1),follow?Math.atan2(q.v[0],q.v[1]):-q.rot);}}
   ctx.restore();});
 }
 draw(ctx,layer,image,color,alpha,x,y,w,h,rotation){if(!(w>0&&h>0)||!image||!(alpha>0))return;ctx.save();ctx.globalAlpha=clamp01(alpha);ctx.translate(x,y);ctx.rotate(rotation);ctx.drawImage(this.tint(layer,image,color),-w/2,-h/2,w,h);ctx.restore();}
 tick(now=performance.now()){if(this.closed)return;for(const [mark,entry] of this.entries)if(this.visible(mark))this.paint(entry,now);}
 remove(mark){const entry=this.entries.get(mark);if(!entry)return;this.entries.delete(mark);for(const {canvas}of entry.canvases)canvas.remove();entry.canvases=[];entry.canvas=null;entry.emitters.clear();mark.classList?.toggle('dk-plate-glory',false);if(entry.previous){mark.style.isolation=entry.previous.isolation||'';mark.style.filter=entry.previous.filter||'';for(const[child,z]of entry.previous.z)child.style.zIndex=z||'';}entry.prepared=null;}
 dispose(){for(const mark of [...this.entries.keys()])this.remove(mark);this.closed=true;this.prepared.clear();this.images.clear();}
}
