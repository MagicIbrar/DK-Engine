// Read-only QA evidence for the conservative parking refusal. Keys and types
// only: no account identifiers, private values, getters or relaxed eligibility.
// Caller supplies its already observed ordinary refusal; this helper makes no
// parking decision and never invokes a native lifecycle callback for diagnosis.
export function npcFieldParkingDiagnostics(world, scene, {refusal=null}={}) {
  const descriptors = Object.getOwnPropertyDescriptors(scene || {});
  const keys = Object.keys(descriptors).sort();
  const shape = descriptor => Object.hasOwn(descriptor, 'value') ?
    (descriptor.value instanceof Map ? 'Map' : descriptor.value instanceof Set ? 'Set' :
      ArrayBuffer.isView(descriptor.value) ? 'TypedView' : typeof descriptor.value) : 'accessor';
  const monsterKeys = new Map(), references = [];
  const monsters = descriptors.monsters?.value;
  if (monsters instanceof Map) for (const monster of monsters.values()) {
    if (!monster || typeof monster !== 'object') continue;
    for (const [key, descriptor] of Object.entries(Object.getOwnPropertyDescriptors(monster))) {
      const id = key + ':' + shape(descriptor);
      monsterKeys.set(id, (monsterKeys.get(id) || 0) + 1);
    }
  }
  const ownerScene = value => value && typeof value === 'object' &&
    Object.getOwnPropertyDescriptor(value, 'scene')?.value === scene;
  for (const [key, descriptor] of Object.entries(Object.getOwnPropertyDescriptors(world || {}))) {
    if (['maps', '_parkedFieldScenes', 'data'].includes(key)) continue;
    if (!Object.hasOwn(descriptor, 'value')) { references.push({key, type:'accessor not read'}); continue; }
    const value=descriptor.value;
    if (value === scene) references.push({key, type:'direct scene'});
    else if (ownerScene(value)) references.push({key, type:'holder scene'});
    else if (value instanceof Map && [...value.values()].some(v=>v===scene||ownerScene(v)))
      references.push({key, type:'Map value scene'});
  }
  return {map:Number.isInteger(descriptors.index?.value)?descriptors.index.value:null,
    refusal:typeof refusal==='string'?refusal:'parking decision not evaluated',
    fields:keys.map(key=>({key,type:shape(descriptors[key]),configurable:descriptors[key].configurable===true})),
    monsterCount:monsters instanceof Map?monsters.size:null,
    monsterFields:[...monsterKeys].sort(([a],[b])=>a.localeCompare(b)).map(([field,count])=>({field,count})),
    references};
}
