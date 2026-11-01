// geometry.fx vsBump: T=vertex.tangent.xyz, B=cross(N,T). The stored
// tangent.w is not used. Transform B itself, rather than reconstructing it
// after the engine's Z mirror (which reverses the cross-product sign).
import * as THREE from 'three';
const patched = new WeakSet();

export function hasObjectTangentBasis(mesh) {
  return !!mesh?.tangents && mesh.tangents.length === mesh.vertexCount * 4;
}

export function patchObjectNormalBasis(material) {
  if (patched.has(material)) return material;
  patched.add(material);
  const prior = material.onBeforeCompile;
  const priorKey = Object.prototype.hasOwnProperty.call(material, 'customProgramCacheKey') ? material.customProgramCacheKey : null;
  material.onBeforeCompile = function (shader, renderer) {
    prior.call(this, shader, renderer);
    const anchor = '#include <normal_vertex>';
    if (!shader.vertexShader.includes(anchor)) throw Error('Object normal-map shader lacks native tangent-basis hook');
    const chunk = THREE.ShaderChunk.normal_vertex.replace(
      'vBitangent = normalize( cross( vNormal, vTangent ) * tangent.w );',
      `vec3 dkObjectBitangent = cross( objectNormal, objectTangent );
       #ifdef USE_BATCHING
         dkObjectBitangent = mat3( batchingMatrix ) * dkObjectBitangent;
       #endif
       #ifdef USE_INSTANCING
         dkObjectBitangent = mat3( instanceMatrix ) * dkObjectBitangent;
       #endif
       vBitangent = normalize( ( modelViewMatrix * vec4( dkObjectBitangent, 0.0 ) ).xyz );`
    );
    if (chunk === THREE.ShaderChunk.normal_vertex) throw Error('Object normal-map shader tangent convention changed');
    shader.vertexShader = shader.vertexShader.replace(anchor, chunk);
  };
  material.customProgramCacheKey = function () { return `${priorKey ? priorKey.call(this) : ''}|dk-object-native-normal-v1`; };
  material.userData.dkObjectNormalBasis = true;
  material.userData.dkObjectNormalScale ||= material.normalScale?.toArray() || [1, 1];
  material.needsUpdate = true;
  return material;
}
