import * as THREE from 'three';

// A single scene-entry adjustment avoids starting behind an authored wall while
// keeping continuous camera push-in disabled. The player/geometry never moves.
export function applyDungeonArrivalView(game){
 const cam=game.cam,p=game.player,objects=game.world?.objects,row=game.mapRow?.(game.world?.info?.index);
 if(!cam||!p||!objects?.cameraClip||cam.mode==='first-person'||game.gm?.freecam?.on||row?.Default_H_Angle==null||row.Default_H_Angle==='')return null;
 const degrees=Number(row.Default_H_Angle),values=[degrees,p.x,p.y,p.z,cam.yaw,cam.pitch,cam.distance,cam.height];
 if(!values.every(Number.isFinite)||cam.distance<=0)return null;
 const yaw=Math.abs(degrees)<2?degrees:degrees*Math.PI/180,look=new THREE.Vector3(p.x,p.y+cam.height,-p.z),point=a=>new THREE.Vector3(look.x+Math.sin(a)*Math.cos(cam.pitch)*cam.distance,look.y+Math.sin(cam.pitch)*cam.distance,look.z+Math.cos(a)*Math.cos(cam.pitch)*cam.distance);
 try{
  const oldYaw=cam.yaw,current=objects.cameraClip(look,point(oldYaw));
  if(!Number.isFinite(current)||current>=.99)return {applied:false,yaw:oldYaw,current};
  const authored=objects.cameraClip(look,point(yaw));
  if(!Number.isFinite(authored)||authored<.99)return {applied:false,yaw:oldYaw,current,authored};
  cam.yaw=yaw;cam.snap();return {applied:true,oldYaw,yaw,current,authored};
 }catch{return null;}
}
