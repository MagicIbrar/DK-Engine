// Install once after the private map library loads, before any world join.
export function installCustomMapData(data,library){
 if(data.customMaps===library)return;
 const map=data.map.bind(data),spawns=data.spawns.bind(data),gates=data.gates.bind(data),requiresInstance=data.requiresInstance?.bind(data);
 data.customMaps=library;
 data.map=async(index,opts)=>{index=Number(index);if(library.isDeploying(index))throw Object.assign(new Error('Map publication is in progress. Retry entry after it finishes.'),{status:409});return library.map(index)||map(index,opts);};
 data.spawns=index=>library.has(index)?library.spawns(index):spawns(index);
 data.gates=index=>library.has(index)?library.gates(index):gates(index);
 data.requiresInstance=index=>library.has(index)?false:!!requiresInstance?.(index);
 data.customNpcPlacements=index=>library.placements(index);
 // Shared consumers use this for custom name/job overrides; original tables
 // remain unchanged. Root/gameplay must route NPC proximity/services through it.
 data.npcPlacement=(index,npcIndex)=>library.placements(index).filter(n=>n.npcIndex===Number(npcIndex));
 // Gameplay owns npc-services.mjs and routes service proximity through these
 // canonical placements. Explicit [] removes jobs; absent jobs inherits them.
 return data;
}
