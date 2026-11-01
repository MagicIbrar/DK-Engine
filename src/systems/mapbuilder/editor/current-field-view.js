// Current standing character pose, captured before any asynchronous edit/load.
// Camera axes match existing GMBuildMode and fileToThree (Z is mirrored).
export function captureCurrentFieldView(game){
 const actor=game.player,index=Number(game.world?.info?.index),fly=game.gm?.freecam;
 if(!Number.isInteger(index)||!actor||![actor.x,actor.z,actor.y||0].every(Number.isFinite))throw Error('The current standing field pose is unavailable.');
 return {index,x:actor.x,z:actor.z,y:(actor.y||0)+1.8,yaw:Number.isFinite(fly?.yaw)?fly.yaw:0,pitch:Number.isFinite(fly?.pitch)?fly.pitch:-.12,speed:Number.isFinite(fly?.speed)?fly.speed:24};
}
export function placeCurrentFieldView(editor,pose){
 if(!pose||![pose.x,pose.y,pose.z,pose.yaw,pose.pitch].every(Number.isFinite))throw Error('Invalid current field view.');
 editor.cancelInput();editor.navigation='freefly';editor.cam.pos.set(pose.x,pose.y,-pose.z);editor.cam.yaw=pose.yaw;editor.cam.pitch=pose.pitch;if(Number.isFinite(pose.speed)&&pose.speed>0)editor.cam.speed=pose.speed;editor.syncCamera();editor.emit('navigation','freefly');
}
export function captureCurrentFieldDetails(game){const world=game.world,row=world?.info?.row||{};return {spawns:structuredClone(world?.spawns||[]),npcs:structuredClone(world?.npcPlacements||[]),start:world?.startPoint?.(false),env:{light:String(row.EnvironmentFile||''),envMap:String(row.EnvironmentMap||''),clipFar:Number(row.Clip_Far)||0}};}
