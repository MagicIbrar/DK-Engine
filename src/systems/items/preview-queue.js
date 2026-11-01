// One shared renderer bake at a time; visible stills precede queued rotation sheets.
// Background work (a shop page prefetch, Icons.background) is baked in the same order but idle() does not wait for it: the
// loading screen's "await icons.queue" waited for D-Shop prefetch bakes too (6.3 s back in Ardeca in 2.2.0, measured).
export class PreviewQueue {
 constructor(){this.jobs=[];this.running=false;this.pending=new Set();this.backgroundPending=new Set();this.active=null;}
 track(promise,background=false){const set=background?this.backgroundPending:this.pending;set.add(promise);promise.then(()=>set.delete(promise),()=>set.delete(promise));return promise;}
 add(work,priority=1,background=false){return new Promise((resolve,reject)=>{this.jobs.push({work,priority,background,resolve,reject});if(!this.running){this.running=true;queueMicrotask(()=>this.drain());}});}
 busy(){return this.pending.size>0||this.jobs.some(job=>!job.background)||!!(this.active&&!this.active.background);}
 async idle(){do{await new Promise(resolve=>setTimeout(resolve,0));}while(this.busy());}
 then(resolve,reject){return this.idle().then(resolve,reject);}
 async run(job){const previous=this.active;this.active=job;try{job.resolve(await job.work(()=>this.checkpoint(job)));}catch(error){job.reject(error);}finally{this.active=previous;}}
 // Service urgent jobs only when the bake explicitly returns a restored renderer; bounded bursts resume rotation.
 async checkpoint(job){if(this.active!==job||!(job.priority>0))return;for(let n=0;n<4;n++){this.jobs.sort((a,b)=>a.priority-b.priority);const index=this.jobs.findIndex(next=>next.priority<job.priority);if(index<0)break;await this.run(this.jobs.splice(index,1)[0]);}}
 async drain(){while(this.jobs.length){this.jobs.sort((a,b)=>a.priority-b.priority);await this.run(this.jobs.shift());}this.running=false;}
}

// Hold a preparation slot until its renderer bake finishes. This bounds live
// instances as well as requests, without holding the renderer during asset IO.
export class PreviewPreparation {
 constructor(limit=4){this.limit=limit;this.active=0;this.background=0;this.jobs=[];}
 add(work,priority=0){return new Promise((resolve,reject)=>{this.jobs.push({work,priority,resolve,reject});this.drain();});}
 drain(){while(this.active<this.limit&&this.jobs.length){this.jobs.sort((a,b)=>a.priority-b.priority);let index=this.jobs.findIndex(job=>job.priority===0||this.background===0);if(index<0)return;const background=this.jobs.findIndex(job=>job.priority>0);if(this.active===this.limit-1&&this.background===0&&background>=0)index=background;const job=this.jobs.splice(index,1)[0];this.active++;if(job.priority>0)this.background++;Promise.resolve().then(job.work).then(job.resolve,job.reject).finally(()=>{this.active--;if(job.priority>0)this.background--;this.drain();});}}
}
