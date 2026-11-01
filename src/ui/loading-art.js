// A loading window's native script points at map art 0. Keep its contents covered
// until the requested art wins, including when the map changes during decoding.
export function loadingArtGate({load,paint,hide,show}){
 let generation=0,closed=false;
 return {
  async select(index){const mine=++generation;hide();paint(null);let sprite=null;
   try{sprite=await load(index)}catch{/* A missing map image stays black. */}
   if(closed||mine!==generation)return false;
   paint(sprite);show();return true;
  },
  close(){closed=true;generation++;hide();}
 };
}
