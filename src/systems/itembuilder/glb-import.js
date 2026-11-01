// Meshy GLB import: inspect before loading, keep original glTF materials/textures/node transforms.
// No external resource fetches, native auto-skinning or silently dropping unsupported compression.
export const GLB_LIMITS = { bytes: 32 * 1024 * 1024, triangles: 200000, textureEdge: 4096, texturePixels: 32 * 1024 * 1024, inspectionValues: 2000000 };
export const GLB_SKIN_LIMITS = Object.freeze({ skins:16, jointsPerSkin:256, totalJoints:2048, bindings:64, uniqueBindings:32 });
function imageSize(bytes) {
  if(bytes.length>=24&&bytes[0]===137&&bytes[1]===80&&bytes[2]===78&&bytes[3]===71){const v=new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength);return[v.getUint32(16),v.getUint32(20)];}
  if(bytes[0]===255&&bytes[1]===216){for(let offset=2;offset+4<bytes.length;){if(bytes[offset++]!==255)throw Error('Invalid embedded JPEG.');let marker=bytes[offset++];while(marker===255)marker=bytes[offset++];if(marker===0xd9||marker===0xda)break;const length=(bytes[offset]<<8)|bytes[offset+1];if(length<2||offset+length>bytes.length)throw Error('Truncated embedded JPEG.');if([0xc0,0xc1,0xc2,0xc3,0xc5,0xc6,0xc7,0xc9,0xca,0xcb,0xcd,0xce,0xcf].includes(marker))return[(bytes[offset+5]<<8)|bytes[offset+6],(bytes[offset+3]<<8)|bytes[offset+4]];offset+=length;}}
  throw Error('Embedded textures must be PNG or JPEG with readable dimensions.');
}
// Bound metadata before traversing it or decoding any repeated geometry/skin values.
function validateSkinMetadata(json) {
  for(const key of ['nodes','meshes','skins'])if(json[key]!==undefined&&!Array.isArray(json[key]))throw Error(`GLB ${key} must be an array.`);
  const skins=json.skins||[],nodes=json.nodes||[],meshes=json.meshes||[];
  if(skins.length>GLB_SKIN_LIMITS.skins)throw Error('GLB skin count exceeds inspection budget.');
  for(const [key,entries]of [['node',nodes],['mesh',meshes],['skin',skins]])for(const entry of entries)if(!entry||typeof entry!=='object'||Array.isArray(entry))throw Error(`Invalid GLB ${key} object.`);
  const validNode=i=>Number.isInteger(i)&&i>=0&&i<nodes.length;
  let totalJoints=0,bindings=0;const uniqueBindings=new Set();
  for(const skin of skins){
    if(!Array.isArray(skin.joints)||!skin.joints.length)throw Error('Invalid GLB skin joint references.');
    if(skin.joints.length>GLB_SKIN_LIMITS.jointsPerSkin||skin.joints.length>GLB_SKIN_LIMITS.totalJoints-totalJoints)throw Error('GLB skin joints exceed inspection budget.');
    totalJoints+=skin.joints.length;
    if(skin.joints.some(i=>!validNode(i))||new Set(skin.joints).size!==skin.joints.length)throw Error('Invalid GLB skin joint references.');
    if(skin.skeleton!=null&&!validNode(skin.skeleton))throw Error('Invalid GLB skin skeleton reference.');
  }
  for(const node of nodes){
    if(node.skin===undefined)continue;
    if(!Number.isInteger(node.skin)||!skins[node.skin]||!Number.isInteger(node.mesh)||!meshes[node.mesh])throw Error('Invalid GLB skinned mesh reference.');
    if(++bindings>GLB_SKIN_LIMITS.bindings)throw Error('GLB skin bindings exceed inspection budget.');
    uniqueBindings.add(`${node.mesh}:${node.skin}`);
    if(uniqueBindings.size>GLB_SKIN_LIMITS.uniqueBindings)throw Error('GLB unique skin bindings exceed inspection budget.');
  }
}
// Structural preview safety only. This does not prove compatibility with any native rig.
function inspectSkinStructure(json, bin, consumeWork) {
  const skins=json.skins||[],nodes=json.nodes||[],values=new DataView(bin.buffer,bin.byteOffset,bin.byteLength);
  const read=(accessor,vertex,component)=>{
    const range=json.bufferViews[accessor.bufferView],size={5121:1,5123:2,5126:4}[accessor.componentType];
    const offset=(range.byteOffset||0)+(accessor.byteOffset||0)+vertex*(range.byteStride||size*({VEC4:4,MAT4:16}[accessor.type]))+component*size;
    const value=size===1?values.getUint8(offset):size===2?values.getUint16(offset,true):values.getFloat32(offset,true);
    return accessor.normalized?value/(size===1?255:65535):value;
  };
  let skinJointNamesComplete=skins.length>0;
  for(const skin of skins){
    const names=skin.joints.map(i=>nodes[i].name);
    if(names.some(name=>typeof name!=='string'||!name.trim())||new Set(names).size!==names.length)skinJointNamesComplete=false;
    if(skin.inverseBindMatrices!=null){
      const accessor=json.accessors?.[skin.inverseBindMatrices];
      if(!Number.isInteger(skin.inverseBindMatrices)||!accessor||accessor.type!=='MAT4'||accessor.componentType!==5126||accessor.normalized||accessor.count<skin.joints.length)throw Error('Invalid GLB inverse-bind matrix accessor.');
      consumeWork(skin.joints.length*16);
      for(let joint=0;joint<skin.joints.length;joint++)for(let axis=0;axis<16;axis++)if(!Number.isFinite(read(accessor,joint,axis)))throw Error('GLB inverse-bind matrices must be finite.');
    }
  }
  const checked=new Set();let skinBindings=0;
  for(const node of nodes){
    if(node.skin==null)continue;
    const skin=skins[node.skin],mesh=json.meshes?.[node.mesh];
    if(!Number.isInteger(node.skin)||!skin||!Number.isInteger(node.mesh)||!mesh)throw Error('Invalid GLB skinned mesh reference.');
    skinBindings++;
    const key=`${node.mesh}:${node.skin}`;if(checked.has(key))continue;checked.add(key);
    for(const primitive of mesh.primitives||[]){
      const attributes=primitive.attributes||{},joints=json.accessors?.[attributes.JOINTS_0],weights=json.accessors?.[attributes.WEIGHTS_0];
      if(Object.keys(attributes).some(name=>/^(?:JOINTS|WEIGHTS)_/.test(name)&&!['JOINTS_0','WEIGHTS_0'].includes(name)))throw Error('Additional GLB skin influence sets need a deformation adapter; export at most four weights per vertex.');
      if(!Number.isInteger(attributes.JOINTS_0)||!joints||joints.type!=='VEC4'||![5121,5123].includes(joints.componentType)||joints.normalized)throw Error('Skinned GLB requires unsigned VEC4 JOINTS_0.');
      if(!Number.isInteger(attributes.WEIGHTS_0)||!weights||weights.type!=='VEC4'||!([5126].includes(weights.componentType)&&!weights.normalized||[5121,5123].includes(weights.componentType)&&weights.normalized===true))throw Error('Skinned GLB requires float or normalized unsigned VEC4 WEIGHTS_0.');
      const count=json.accessors?.[attributes.POSITION]?.count;
      if(joints.count!==count||weights.count!==count)throw Error('GLB skin attribute vertex counts must match POSITION.');
      consumeWork(count*8);
      for(let vertex=0;vertex<count;vertex++){
        let sum=0;
        for(let component=0;component<4;component++){
          const joint=read(joints,vertex,component),weight=read(weights,vertex,component);
          if(joint>=skin.joints.length)throw Error('GLB skin index exceeds joint palette bounds.');
          if(!Number.isFinite(weight)||weight<0||weight>1)throw Error('GLB skin weights must be finite and between zero and one.');
          sum+=weight;
        }
        if(!(sum>0))throw Error('GLB skinned vertices require a positive total weight.');
      }
    }
  }
  return {skinJointNamesComplete,skinBindings};
}
export function inspectGLB(buffer, limits = GLB_LIMITS) {
  if (!(buffer instanceof ArrayBuffer) || buffer.byteLength < 20 || buffer.byteLength > limits.bytes) throw Error('GLB must be a complete file under32MiB.');
  const view = new DataView(buffer);
  if (view.getUint32(0,true)!==0x46546c67 || view.getUint32(4,true)!==2 || view.getUint32(8,true)!==buffer.byteLength) throw Error('Use a valid GLB2 export. FBX/OBJ must be converted to GLB with embedded textures.');
  let json=null,bin=null;
  for(let offset=12;offset<buffer.byteLength;){
    if(offset+8>buffer.byteLength)throw Error('Truncated GLB chunk.');
    const length=view.getUint32(offset,true),type=view.getUint32(offset+4,true);offset+=8;
    if(length%4||offset+length>buffer.byteLength)throw Error('Invalid GLB chunk length.');
    if(type===0x4e4f534a){if(json||offset!==20)throw Error('GLB JSON must be first and unique.');json=JSON.parse(new TextDecoder().decode(new Uint8Array(buffer,offset,length)).trim());}
    else if(type===0x004e4942){if(bin)throw Error('Duplicate GLB binary chunk.');bin=new Uint8Array(buffer,offset,length);}
    offset+=length;
  }
  if(!json||json.asset?.version!=='2.0')throw Error('GLB2 asset metadata is required.');
  if((json.nodes?.length||0)>4096||(json.meshes?.length||0)>512||(json.materials?.length||0)>128||(json.images?.length||0)>64||(json.scenes?.length||0)>16)throw Error('GLB scene exceeds equipment complexity limits.');
  validateSkinMetadata(json);
  const workLimit=limits.inspectionValues??GLB_LIMITS.inspectionValues;
  if(!Number.isSafeInteger(workLimit)||workLimit<=0||workLimit>GLB_LIMITS.inspectionValues)throw Error('GLB inspection budget must be a positive integer within the hard limit.');
  let inspectionValues=0;
  const consumeWork=count=>{if(!Number.isSafeInteger(count)||count<0||count>workLimit-inspectionValues)throw Error('GLB numeric inspection work exceeds budget.');inspectionValues+=count;};
  const visiting=new Set(),visited=new Set();
  const visit=index=>{if(!Number.isInteger(index)||index<0||index>=(json.nodes?.length||0))throw Error('Invalid GLB node reference.');if(visiting.has(index))throw Error('GLB scene contains a node cycle.');if(visited.has(index))return;visiting.add(index);const node=json.nodes[index];for(const name of ['matrix','translation','rotation','scale'])if(node[name]!=null&&(!Array.isArray(node[name])||node[name].length!==({matrix:16,translation:3,rotation:4,scale:3}[name])||node[name].some(value=>!Number.isFinite(value)||Math.abs(value)>1e6)))throw Error('GLB node transforms must be finite.');for(const child of node.children||[])visit(child);visiting.delete(index);visited.add(index);};
  for(let i=0;i<(json.nodes?.length||0);i++)visit(i);
  for(const resource of [...json.buffers||[],...json.images||[]])if(resource.uri && !/^data:(?:image\/(?:png|jpeg)|application\/octet-stream);base64,/i.test(resource.uri))throw Error('External texture/buffer paths are unsupported. Export GLB with embedded textures.');
  const supported=new Set(['KHR_materials_unlit','KHR_materials_clearcoat','KHR_materials_transmission','KHR_materials_ior','KHR_materials_specular','KHR_materials_sheen','KHR_materials_volume','KHR_materials_emissive_strength','KHR_texture_transform','KHR_mesh_quantization']);
  for(const extension of new Set([...(json.extensionsRequired||[]),...(json.extensionsUsed||[])]))if(!supported.has(extension))throw Error(`${extension} needs a decoder/conversion. Export an uncompressed GLB.`);
  // Also reject decoder extensions omitted from extensionsUsed by malformed exporters.
  const checkExtensions=value=>{if(!value||typeof value!=='object')return;for(const key of Object.keys(value.extensions||{}))if(!supported.has(key))throw Error(`${key} needs a decoder/conversion. Export an uncompressed GLB.`);for(const [key,child] of Object.entries(value))if(key!=='extensions'){if(Array.isArray(child))child.forEach(checkExtensions);else checkExtensions(child);}};
  checkExtensions(json);
  for(const resource of json.buffers||[])if(resource.uri)throw Error('GLB buffers must use the embedded binary chunk.');
  if(json.buffers?.length!==1||!bin||!Number.isSafeInteger(json.buffers[0].byteLength)||json.buffers[0].byteLength<=0||json.buffers[0].byteLength>bin.length||bin.length-json.buffers[0].byteLength>3)throw Error('GLB requires one complete embedded binary buffer.');
  for(const range of json.bufferViews||[]){const start=range.byteOffset||0;if(range.buffer!==0||!Number.isSafeInteger(start)||start<0||!Number.isSafeInteger(range.byteLength)||range.byteLength<0||!bin||start+range.byteLength>json.buffers[0].byteLength)throw Error('Invalid embedded buffer range.');}
  const componentBytes={5120:1,5121:1,5122:2,5123:2,5125:4,5126:4},elements={SCALAR:1,VEC2:2,VEC3:3,VEC4:4,MAT2:4,MAT3:9,MAT4:16};
  for(const accessor of json.accessors||[]){const range=json.bufferViews?.[accessor.bufferView],size=componentBytes[accessor.componentType]*elements[accessor.type],offset=accessor.byteOffset||0,stride=range?.byteStride||size;if(accessor.sparse||!range||!size||!Number.isSafeInteger(accessor.count)||accessor.count<0||accessor.count>600000||!Number.isSafeInteger(offset)||offset<0||!Number.isSafeInteger(stride)||stride<size||offset+Math.max(0,accessor.count-1)*stride+size>range.byteLength)throw Error('Invalid/oversized/sparse GLB accessor; export dense equipment geometry.');}
  let texturePixels=0;
  for(const image of json.images||[]){
    let bytes;
    if(image.uri){const raw=atob(image.uri.slice(image.uri.indexOf(',')+1));bytes=Uint8Array.from(raw,c=>c.charCodeAt(0));}
    else{const range=json.bufferViews?.[image.bufferView];if(!range)throw Error('Embedded texture buffer range is missing.');bytes=bin.subarray(range.byteOffset||0,(range.byteOffset||0)+range.byteLength);}
    const [width,height]=imageSize(bytes);texturePixels+=width*height;
    if(!width||!height||width>limits.textureEdge||height>limits.textureEdge||texturePixels>limits.texturePixels)throw Error('Embedded textures exceed4096px or32 megapixels. Resize before importing.');
  }
  const meshTriangles=[];
  for(const mesh of json.meshes||[]){let triangles=0;for(const primitive of mesh.primitives||[]){
    const mode=primitive.mode??4,count=json.accessors?.[primitive.indices??primitive.attributes?.POSITION]?.count;
    if(![4,5,6].includes(mode))throw Error('Equipment imports require triangle geometry. Convert lines/points first.');
    if(!Number.isSafeInteger(count)||count<3||(mode===4&&count%3!==0))throw Error('Empty/incomplete triangle geometry.');
    const position=json.accessors?.[primitive.attributes?.POSITION];if(!position||position.type!=='VEC3'||position.componentType!==5126)throw Error('Export equipment positions as uncompressed float VEC3.');
    const range=json.bufferViews[position.bufferView],stride=range.byteStride||12,start=(range.byteOffset||0)+(position.byteOffset||0),values=new DataView(bin.buffer,bin.byteOffset,bin.byteLength);
    consumeWork(position.count*3+(primitive.indices==null?0:json.accessors?.[primitive.indices]?.count));
    for(const index of Object.values(primitive.attributes||{})){const attribute=json.accessors?.[index];if(!attribute||attribute.count!==position.count)throw Error('Mesh attribute vertex counts must match POSITION.');}
    if(primitive.indices!=null){const indices=json.accessors?.[primitive.indices];if(!indices||indices.type!=='SCALAR'||![5121,5123,5125].includes(indices.componentType)||indices.normalized)throw Error('Triangle indices must be unsigned integer SCALAR.');const r=json.bufferViews[indices.bufferView],size=componentBytes[indices.componentType],step=r.byteStride||size,base=(r.byteOffset||0)+(indices.byteOffset||0);for(let i=0;i<indices.count;i++){const offset=base+i*step,value=size===1?values.getUint8(offset):size===2?values.getUint16(offset,true):values.getUint32(offset,true);if(value>=position.count)throw Error('Triangle index exceeds POSITION vertex bounds.');}}
    for(let vertex=0;vertex<position.count;vertex++)for(let axis=0;axis<3;axis++){const value=values.getFloat32(start+vertex*stride+axis*4,true);if(!Number.isFinite(value)||Math.abs(value)>1e6)throw Error('Equipment vertices must be finite and within safe bounds.');}
    triangles+=mode===4?Math.floor(count/3):mode===5||mode===6?Math.max(0,count-2):0;
  }meshTriangles.push(triangles);}
  // Budget rendered node instances, including repeated references to the same mesh.
  const subtree=new Map(),parents=new Set();
  for(const node of json.nodes||[])for(const child of node.children||[]){if(parents.has(child))throw Error('GLB nodes must form a tree, without duplicate parents.');parents.add(child);}
  const countNode=index=>{visit(index);if(subtree.has(index))return subtree.get(index);const node=json.nodes[index];if(node.mesh!=null&&(!Number.isInteger(node.mesh)||meshTriangles[node.mesh]==null))throw Error('Invalid GLB mesh reference.');let total=node.mesh==null?0:meshTriangles[node.mesh];for(const child of node.children||[])total+=countNode(child);subtree.set(index,total);return total;};
  if(!json.scenes?.length||!Number.isInteger(json.scene??0)||!json.scenes[json.scene??0])throw Error('GLB requires a valid visible scene.');
  let triangles=0;
  for(const scene of json.scenes){const roots=scene.nodes||[];if(new Set(roots).size!==roots.length||roots.some(index=>parents.has(index)))throw Error('Invalid/duplicate GLB scene roots.');triangles=Math.max(triangles,roots.reduce((sum,index)=>sum+countNode(index),0));}
  if(!triangles||(json.scenes[json.scene??0].nodes||[]).reduce((sum,index)=>sum+countNode(index),0)===0)throw Error('GLB has no visible triangle geometry.');
  if(triangles>limits.triangles)throw Error(`Model has ${triangles.toLocaleString()} triangles; hard import limit is ${limits.triangles.toLocaleString()}. Remesh it first.`);
  const skinStructure=inspectSkinStructure(json,bin,consumeWork);
  const bones=[...new Set((json.skins||[]).flatMap(skin=>skin.joints||[]).map(i=>json.nodes?.[i]?.name).filter(Boolean))];
  const warnings=[];
  if(triangles>50000)warnings.push('Over50k triangles: reduce detail for equipment used by many players.');
  if((json.skins||[]).length)warnings.push('Rigged model: bone names/weights must be mapped to the target Dekaron class; no automatic armor binding.');
  if((json.animations||[]).length)warnings.push('Animated GLB equipment needs a runtime animation adapter. Export a rigid static weapon to apply it.');
  if(json.meshes?.some(mesh=>mesh.primitives?.some(primitive=>primitive.targets?.length)))warnings.push('Morphing GLB equipment needs a runtime deformation adapter. Export a rigid static weapon to apply it.');
  return {json,bin,triangles,bones,skins:(json.skins||[]).length,...skinStructure,inspectionValues,animations:(json.animations||[]).length,materials:(json.materials||[]).length,images:(json.images||[]).length,texturePixels,warnings};
}

export async function loadImportedGLB(buffer, {scale=1,up='y',limits=GLB_LIMITS}={}) {
  if(up!=='z'&&up!=='y')throw Error('Choose Y-up(GLB standard) or explicit Z-up correction.');
  if(!Number.isFinite(scale)||scale<=0||scale>1000)throw Error('Unit scale must be between0 and1000.');
  const report=inspectGLB(buffer,limits);
  const [THREE,{GLTFLoader}]=await Promise.all([import('three'),import('three/addons/loaders/GLTFLoader.js')]);
  const manager=new THREE.LoadingManager();
  manager.setURLModifier(url=>{if(!/^(?:blob:|data:)/i.test(url))throw Error('External GLB resource blocked.');return url;});
  const gltf=await new GLTFLoader(manager).parseAsync(buffer,'');
  const object=new THREE.Group();object.name='Imported GLB normalization';object.add(gltf.scene);
  if(up==='z')object.rotation.x=-Math.PI/2;else if(up!=='y')throw Error('Choose Y-up(GLB standard) or explicit Z-up correction.');
  if(!Number.isFinite(scale)||scale<=0||scale>1000)throw Error('Unit scale must be between0 and1000.');
  object.scale.setScalar(scale);object.updateMatrixWorld(true);
  const textures=new Set(),materials=new Set(),geometries=new Set();let pixels=0;
  object.traverse(node=>{if(node.geometry)geometries.add(node.geometry);for(const material of Array.isArray(node.material)?node.material:[node.material])if(material){materials.add(material);for(const value of Object.values(material))if(value?.isTexture)textures.add(value);}});
  const dispose=()=>{for(const texture of textures)texture.dispose();for(const material of materials)material.dispose();for(const geometry of geometries)geometry.dispose();object.removeFromParent();};
  for(const texture of textures){const image=texture.image;const w=image?.width||image?.videoWidth||0,h=image?.height||image?.videoHeight||0;pixels+=w*h;if(w>limits.textureEdge||h>limits.textureEdge){dispose();throw Error('Texture exceeds4096px. Resize textures before importing.');}}
  if(pixels>limits.texturePixels){dispose();throw Error('Combined decoded textures exceed32 megapixels. Reduce texture sizes.');}
  const box=new THREE.Box3().setFromObject(object);
  if(box.isEmpty()){dispose();throw Error('GLB has no visible mesh geometry.');}
  return {object,scene:gltf.scene,animations:gltf.animations,report:{...report,texturePixels:pixels,bounds:box.getSize(new THREE.Vector3()).toArray()},dispose};
}

export function validateImportedAttachment(report, {kind='weapon',bone='',nativeBones=[]}={}) {
  if(kind==='weapon')return bone&&nativeBones.includes(bone)?{valid:true,rigid:true}:{valid:false,reason:'Choose an existing target class hand/sheath bone for a rigid weapon.'};
  const missing=report.bones.filter(name=>!nativeBones.includes(name));
  return {valid:false,matchingNames:report.skins>0&&report.skinBindings>0&&report.skinJointNamesComplete===true&&!missing.length&&report.bones.length>0,reason:report.skins?`Armor requires native bind-pose/weight verification (${missing.length} unmatched bone names; names alone do not prove binding).`:'Armor has no skin weights. Rig it to the target class before equipment import.'};
}

/** Bake an explicit import wrapper into GLB; original node TRS and embedded image bytes are retained. */
export function transformGLB(buffer,{scale=1,up='y',rotation=[0,0,0],translation=[0,0,0],mirror=false,tint=[1,1,1]}={}) {
  const report=inspectGLB(buffer),json=report.json;
  if(!Number.isFinite(scale)||scale<=0||scale>1000||![...rotation,...translation,...tint].every(Number.isFinite)||rotation.length!==3||translation.length!==3||tint.length!==3)throw Error('Invalid import transform.');
  if(up!=='y'&&up!=='z')throw Error('Choose Y-up or explicit Z-up correction.');
  const [x,y,z]=rotation.map((v,i)=>v*Math.PI/180+(i===0&&up==='z'?-Math.PI/2:0));
  const c1=Math.cos(x/2),c2=Math.cos(y/2),c3=Math.cos(z/2),s1=Math.sin(x/2),s2=Math.sin(y/2),s3=Math.sin(z/2);
  const quaternion=[s1*c2*c3+c1*s2*s3,c1*s2*c3-s1*c2*s3,c1*c2*s3+s1*s2*c3,c1*c2*c3-s1*s2*s3];
  json.nodes ||= [];
  const wrappers=new Map();
  for(const scene of json.scenes||[])scene.nodes=(scene.nodes||[]).map(root=>{if(!wrappers.has(root)){const index=json.nodes.length;json.nodes.push({name:'Equipment import transform',children:[root],translation,rotation:quaternion,scale:[mirror?-scale:scale,scale,scale]});wrappers.set(root,index);}return wrappers.get(root);});
  if(tint.some(v=>v!==1))for(const material of json.materials||[]){material.pbrMetallicRoughness ||= {};const base=material.pbrMetallicRoughness.baseColorFactor||[1,1,1,1];material.pbrMetallicRoughness.baseColorFactor=base.map((value,i)=>i<3?value*Math.max(0,Math.min(1,tint[i])):value);}
  const encoded=new TextEncoder().encode(JSON.stringify(json)),jsonLength=Math.ceil(encoded.length/4)*4,bin=report.bin,binLength=bin?Math.ceil(bin.length/4)*4:0;
  const result=new ArrayBuffer(12+8+jsonLength+(bin?8+binLength:0)),view=new DataView(result),bytes=new Uint8Array(result);
  view.setUint32(0,0x46546c67,true);view.setUint32(4,2,true);view.setUint32(8,result.byteLength,true);view.setUint32(12,jsonLength,true);view.setUint32(16,0x4e4f534a,true);bytes.fill(32,20,20+jsonLength);bytes.set(encoded,20);
  if(bin){const start=20+jsonLength;view.setUint32(start,binLength,true);view.setUint32(start+4,0x004e4942,true);bytes.set(bin,start+8);}
  inspectGLB(result);return result;
}
