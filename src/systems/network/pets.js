import {PetActor} from '../mounts/pet.js';
import {setServerPose,advanceServerPose} from './actors.js';
import {installSharedPetServices} from './pet-services.js';

/** Original pet meshes/actions are cosmetic; inventory, options and pickup run only on the server. */
export function installSharedPets(game,network){
 const api=game.mounts,sys=api?.system,pets=sys?.pet;if(!pets)return;
 installSharedPetServices(game,network);
 const send=(type,body)=>network.action(type,body);
 api.summonPet=pets.summon=()=>send('pet',{on:true});
 api.unsummonPet=pets.unsummon=()=>send('pet',{on:false});
 api.togglePet=pets.toggle=()=>send('pet',{on:!network.self?.pet});
 pets.state=(eq=pets.equipped())=>eq?.inst?.pet?structuredClone(eq.inst.pet):null;
 api.petState=()=>pets.state();
 const states=new Map();let loading=0;const queue=[];
 const drain=()=>{while(loading<2&&queue.length){const job=queue.shift();loading++;Promise.resolve().then(job).catch(error=>console.warn('[network] pet visual',error)).finally(()=>{loading--;drain()})}};
 function apply(owner,row,self=false){let state=states.get(owner);if(!state){state={actor:null,item:null,generation:0};states.set(owner,state);if(!self){const update=owner.update.bind(owner),dispose=owner.dispose.bind(owner);owner.update=dt=>{update(dt);if(state.actor){advanceServerPose(state.actor);state.actor.update(dt)}};owner.dispose=()=>{state.generation++;state.actor?.dispose();states.delete(owner);dispose()};}}
  const item=row?.phase==='on'?(row.appearance||row.item):null;
  if(item!==state.item||item&&!state.actor&&!state.pending){state.item=item;state.generation++;state.actor?.depart();state.actor?.dispose();state.actor=null;if(self)pets.actor=null;
   if(item){const def=sys.data.pet(item);if(!def)return;const generation=state.generation,world=game.world;state.pending=true;queue.push(async()=>{if(network.disposed||owner.disposed||generation!==state.generation)return;const actor=new PetActor(game,def,{name:row.name},sys.data,{deferEffects:true});actor.setPosition(row.x,row.z);await actor.load();if(generation===state.generation)state.pending=false;if(network.disposed||owner.disposed||game.world!==world||state.item!==item||generation!==state.generation){actor.dispose();return}state.actor=actor;actor.networkId=`pet:${owner.networkId||owner.id}`;actor.setPosition(row.x,row.z);actor.appear();actor.play(row.state||'idle',{loop:true});if(self){pets.actor=actor;pets.item=row.item;sys.setMenuChecked('btn_petsummon',true)}});drain();}
  }
  if(state.actor&&row){setServerPose(state.actor,{...row,name:row.name||sys.data.name(item),hp:1,maxHp:1,dead:false});const motion=row.state||'idle';if(state.actor.state!==motion)state.actor.play(motion,{loop:true});}
  if(self&&!item){pets.item=null;sys.setMenuChecked('btn_petsummon',false)}
 }
 pets.update=dt=>{const state=states.get(game.player);if(state?.actor){advanceServerPose(state.actor);state.actor.update(dt)}};
 let signature='';const off=game.events?.on?.('server:profile',()=>{if(game.player)apply(game.player,network.self?.pet,true);const s=pets.state(),next=JSON.stringify(s?{...s,blessLeft:undefined}:null);if(next!==signature){signature=next;game.events?.emit?.('petinventory',{reason:'server'});const win=game.uiwin?.window?.('petinfo');if(win?.isOpen)win.data.refresh?.();}});
 const prior=network.actorMount;network.actorMount=(actor,row)=>{prior?.(actor,row);if(actor.kind==='player')apply(actor,row.pet)};
 const dispose=network.dispose.bind(network);network.dispose=()=>{off?.();for(const state of states.values()){state.generation++;state.actor?.dispose()}states.clear();dispose()};
}
