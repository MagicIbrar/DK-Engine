// Separate integration; completed custom-map publication hooks stay unchanged.
export function installOriginalMapWorld(world,edits){
 world.originalMapEdits=edits;
 const originalMap=world.map;
 world.map=async function(index,...rest){if(edits.isCommitting||edits.isFrozen(index))throw Object.assign(Error('The original field is being edited or loading.'),{status:409,code:'WORLD_BUSY'});const result=await originalMap.call(this,index,...rest);if(edits.isCommitting||edits.isFrozen(index))throw Object.assign(Error('The original field changed during entry.'),{status:409,code:'WORLD_BUSY'});return result;};
 const dataMap=world.data.map.bind(world.data);world.data.map=async(index,opts)=>edits.map(index,await dataMap(index,opts));
 for(const method of ['action','detachPlayer','close']){const original=world[method];world[method]=function(...args){if(edits.isCommitting)return Promise.reject(Object.assign(Error('An original field overlay is committing.'),{status:409,code:'WORLD_BUSY'}));return original.apply(this,args);};}
 const join=world._join;world._join=async function(...args){if(edits.isCommitting)throw Object.assign(Error('An original overlay is committing.'),{status:409});const result=await join.apply(this,args),p=this.players.get(args[0]);if(p){await edits.onJoin(p);result.self=this.publicPlayer(p,true);result.state=this.snapshot(p);}return result;};
 const player=world.publicPlayer;world.publicPlayer=function(p,self=false){const value=player.call(this,p,self);if(self)value.originalEditPending=p.originalEditPending?{...p.originalEditPending}:null;return value;};
 return world;
}
