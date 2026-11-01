// Native minimap_red alpha: transparent cells allow guard deployment; opaque red
// cells prohibit it. The game's minimap convention is u=FILE Z, v=FILE X.
const cache=new WeakMap();
export function siegeDeployCellAllowed(mask,x,z){
 if(!mask||!Number.isInteger(x)||!Number.isInteger(z)||x<0||z<0||x>=mask.height||z>=mask.width)return false;
 let bits=cache.get(mask);if(!bits){try{bits=Uint8Array.from(atob(mask.bits),c=>c.charCodeAt(0));}catch{return false;}if(bits.length!==Math.ceil(mask.width*mask.height/8))return false;cache.set(mask,bits);}
 const i=x*mask.width+z;return !!(bits[i>>3]&(1<<(i&7)));
}
export function siegeDeployPoint(rect,x,z){return {u:rect.x+(z+.5)*rect.width/512,v:rect.y+(x+.5)*rect.height/512};}
export function siegeDeployCell(rect,u,v){return {x:Math.floor((v-rect.y)*512/rect.height),z:Math.floor((u-rect.x)*512/rect.width)};}
