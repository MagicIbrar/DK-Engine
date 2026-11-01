import {PreviewReferences} from '../../ui/preview-cache.js';

async function decodeIcon(icon) {
  if (typeof Image !== 'function') return;
  const image = new Image(); image.src = icon.url;
  if (typeof image.decode === 'function') await image.decode();
}

// Only the finite authored reward/key identities, at their actual native slot
// dimensions. Keep canonical preview leases until disposal/catalog replacement.
export class RewardPanelAssets {
  constructor(load, {generation=()=>0, decode=decodeIcon, tooltip=()=>null}={}) {
    this.load=load; this.generation=generation; this.decode=decode; this.tooltip=tooltip;
    this.current=generation(); this.cache=new PreviewReferences(); this.pending=new Map();
    this.painted=new WeakMap(); this.disposed=false;
  }
  sync() {
    const next=this.generation();
    if(next!==this.current){this.current=next;this.cache.clear();this.pending.clear();}
    return next;
  }
  dimensions(control) {return {w:control?.box?.w||control?.spec?.rect?.[2]||32,h:control?.box?.h||control?.spec?.rect?.[3]||32};}
  key(index, control) {const {w,h}=this.dimensions(control);return `${Number(index)}:${w}x${h}`;}
  now(index,control) {this.sync();const value=this.cache.get(this.key(index,control));return value?.url?value:null;}
  get(index,control) {
    if(this.disposed||!(Number(index)>0))return Promise.resolve(null);
    const epoch=this.sync(),key=this.key(index,control),ready=this.now(index,control);
    if(ready)return Promise.resolve(ready);
    if(this.pending.has(key))return this.pending.get(key);
    const {w,h}=this.dimensions(control);
    const job=Promise.resolve().then(()=>this.load(Number(index),w,h)).then(async icon=>{
      if(!icon?.url)throw new Error('Reward image did not finish preparation. Retry loading.');
      // Borrow before decode: the canonical cache can otherwise trim a completed
      // render while the browser still owns its pending image decode.
      if(this.disposed||epoch!==this.sync())return null;
      this.cache.set(key,icon);
      try{await this.decode(icon);}catch(error){if(this.cache.get(key)===icon)this.cache.delete(key);throw error;}
      if(this.disposed||epoch!==this.sync())return null;
      return icon;
    }).finally(()=>{if(this.pending.get(key)===job)this.pending.delete(key);});
    this.pending.set(key,job);return job;
  }
  async prepare(requests) {
    for(let attempt=0;attempt<3;attempt++){
      const epoch=this.sync(),unique=[...new Map(requests.filter(r=>Number(r.index)>0).map(r=>[this.key(r.index,r.control),r])).values()];
      let cursor=0;
      await Promise.all(Array.from({length:Math.min(2,unique.length)},async()=>{
        while(cursor<unique.length&&!this.disposed){const r=unique[cursor++];await this.get(r.index,r.control);}
      }));
      if(this.disposed)return;
      if(epoch===this.sync())return;
    }
    throw new Error('Reward image catalog changed during preparation. Retry loading.');
  }
  paint(control,index,count=0) {
    if(!control||this.disposed)return;
    const epoch=this.sync(),key=this.key(index,control),icon=Number(index)>0?this.now(index,control):null;
    const previous=this.painted.get(control);
    if(previous?.key===key&&previous.epoch===epoch&&previous.count===count&&previous.icon===icon&&icon?.url)return;
    const request={key,epoch,count,icon};this.painted.set(control,request);
    control.setIcon?.(icon);control.setCount?.(count>1?count:null);control.setTooltip?.(Number(index)>0?this.tooltip(Number(index),count):null);
    if(Number(index)>0&&!icon)void this.get(index,control).then(value=>{
      if(value&&!this.disposed&&epoch===this.sync()&&this.painted.get(control)===request){request.icon=value;control.setIcon?.(value);}
    }).catch(error=>console.warn('[rewards] image preparation',error));
  }
  dispose(){this.disposed=true;this.cache.clear();this.pending.clear();}
}
