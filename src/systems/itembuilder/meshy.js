import {loadImportedGLB,transformGLB,GLB_LIMITS} from './glb-import.js';
import {glbTarget,applyRigidGLB} from './glb-target.js';

export function openMeshyImport(builder) {
  if(builder._meshyClose)builder._meshyClose();
  const panel=document.createElement('div');
  Object.assign(panel.style,{position:'absolute',left:'282px',top:'72px',width:'310px',padding:'12px',background:'#171b21',color:'#eee',border:'1px solid #615338',zIndex:'100',font:'12px sans-serif',pointerEvents:'auto'});
  for(const event of ['mousedown','pointerdown','wheel'])panel.addEventListener(event,e=>e.stopPropagation());
  const title=document.createElement('strong');title.textContent='Meshy GLB equipment import';panel.append(title);
  const hint=document.createElement('p');hint.textContent='Export GLB with embedded textures. Rigid weapons/offhands use the selected item kind’s native hand/sheath bones. Armor needs compatible rigging and is not auto-skinned.';panel.append(hint);
  const file=document.createElement('input');file.type='file';file.accept='.glb,.fbx,.obj,.gltf';file.style.width='100%';panel.append(file);
  const inputs={};
  function field(label,type,value,opts={}){const row=document.createElement('label');Object.assign(row.style,{display:'flex',justifyContent:'space-between',margin:'5px 0'});row.append(document.createTextNode(label));const input=document.createElement(type==='select'?'select':'input');if(type==='select')for(const choice of opts.choices){const option=document.createElement('option');option.value=choice[0];option.textContent=choice[1];input.append(option);}else{input.type=type;if(type==='number'){input.step=opts.step||'0.01';input.min=opts.min??'-1000';input.max=opts.max??'1000';}}input.value=value;input.style.width='108px';row.append(input);panel.append(row);inputs[label]=input;return input;}
  field('Source up','select','y',{choices:[['y','Y-up(GLB)'],['z','Z-up correction']]});
  field('Unit scale','number','1',{min:'0.001',max:'1000',step:'0.001'});
  for(const axis of ['X','Y','Z'])field(`Rotate ${axis}`,'number','0',{min:'-360',max:'360',step:'1'});
  for(const axis of ['X','Y','Z'])field(`Offset ${axis}`,'number','0');
  field('Mirror X','checkbox','');field('Material tint','color','#ffffff');
  const status=document.createElement('p');status.style.whiteSpace='pre-wrap';status.textContent='Select a static .glb (maximum32MiB). No model is uploaded until Apply.';panel.append(status);
  const targetStatus=document.createElement('p');panel.append(targetStatus);
  const apply=document.createElement('button');apply.textContent='Upload + apply to draft';apply.disabled=true;
  const cancel=document.createElement('button');cancel.textContent='Cancel';cancel.style.marginLeft='8px';panel.append(apply,cancel);builder.win.el.append(panel);
  let source=null,imported=null,revision=0,closed=false,busy=false,transformValid=false;
  let targetTimer;
  const close=()=>{if(closed)return;closed=true;++revision;clearInterval(targetTimer);panel.remove();builder._meshyClose=null;builder.preview?.refresh();};builder._meshyClose=close;cancel.onclick=close;
  function options(){const color=inputs['Material tint'].value;return{scale:Number(inputs['Unit scale'].value),up:inputs['Source up'].value,rotation:['X','Y','Z'].map(axis=>Number(inputs[`Rotate ${axis}`].value)),translation:['X','Y','Z'].map(axis=>Number(inputs[`Offset ${axis}`].value)),mirror:inputs['Mirror X'].checked,tint:[1,3,5].map(offset=>parseInt(color.slice(offset,offset+2),16)/255)};}
  // Changes mutate only the import wrapper/material factors; texture images remain resident.
  const originals=new Map();
  function update(){transformValid=false;if(!imported)return;try{const o=options();if(!Number.isFinite(o.scale)||o.scale<=0||o.scale>1000||![...o.rotation,...o.translation,...o.tint].every(v=>Number.isFinite(v)&&Math.abs(v)<=1e6))throw Error('Choose a finite positive scale and transforms.');const object=imported.object;object.scale.set(o.mirror?-o.scale:o.scale,o.scale,o.scale);object.rotation.set(o.rotation[0]*Math.PI/180+(o.up==='z'?-Math.PI/2:0),o.rotation[1]*Math.PI/180,o.rotation[2]*Math.PI/180);object.position.set(...o.translation);object.traverse(node=>{for(const material of Array.isArray(node.material)?node.material:[node.material])if(material?.color){if(!originals.has(material))originals.set(material,material.color.clone());material.color.copy(originals.get(material));material.color.r*=o.tint[0];material.color.g*=o.tint[1];material.color.b*=o.tint[2];}});object.updateMatrixWorld(true);transformValid=true;builder.preview?.reframeImported();apply.disabled=busy||imported.report.skins>0||imported.report.animations>0||imported.report.json.meshes?.some(mesh=>mesh.primitives?.some(p=>p.targets?.length));}catch(error){status.textContent=error.message;apply.disabled=true;}}
  function checkTarget(){try{const target=glbTarget(builder);targetStatus.textContent=target.label;apply.disabled=busy||!transformValid||!imported||imported.report.skins>0||imported.report.animations>0||!!imported.report.json.meshes?.some(mesh=>mesh.primitives?.some(p=>p.targets?.length));return target;}catch(error){targetStatus.textContent=error.message;apply.disabled=true;return null;}}
  for(const input of Object.values(inputs))input.oninput=()=>{update();checkTarget();};
  targetTimer=setInterval(checkTarget,250);checkTarget();
  file.onchange=async()=>{const chosen=file.files[0],stamp=++revision;source=null;imported=null;originals.clear();builder.preview?._clear();apply.disabled=true;if(!chosen)return;if(!/\.glb$/i.test(chosen.name)){status.textContent='FBX/OBJ/glTF separate resources must be converted to one GLB with embedded textures.';return;}if(chosen.size>GLB_LIMITS.bytes){status.textContent='Model exceeds32MiB. Reduce meshes/textures first.';return;}try{const bytes=await chosen.arrayBuffer();if(closed||stamp!==revision)return;const loaded=await loadImportedGLB(bytes);if(closed||stamp!==revision){loaded.dispose();return;}source=bytes;imported=loaded;originals.clear();builder.preview.showImported(imported);status.textContent=`${loaded.report.triangles.toLocaleString()} triangles, ${loaded.report.materials} materials, ${loaded.report.images} textures\nDimensions: ${loaded.report.bounds.map(v=>v.toFixed(3)).join(' × ')}\n${loaded.report.warnings.join('\n')}`;update();}catch(error){if(!closed&&stamp===revision)status.textContent=error.message;}};
  apply.onclick=async()=>{if(busy||!source||!imported||apply.disabled)return;busy=true;const stamp=revision,draft=builder.draft,target=builder.target,lookClass=builder.lookClass;apply.disabled=true;file.disabled=true;for(const input of Object.values(inputs))input.disabled=true;try{
    if(builder.game.save?.authority!=='server')throw Error('Connect to your authenticated GM world to store and share imported equipment.');
    const attachment=glbTarget(builder);
    const bytes=transformGLB(source,options());
    const response=await fetch('/api/world/custom-assets',{method:'POST',headers:{'Content-Type':'model/gltf-binary'},body:bytes});
    const result=await response.json();if(!response.ok)throw Error(result.error||'Model upload failed.');
    if(closed||stamp!==revision)return;
    if(builder.draft!==draft||builder.target!==target||builder.lookClass!==lookClass)throw Error('Draft or attachment target changed during upload. Reopen the import for this draft.');
    if(glbTarget(builder).signature!==attachment.signature)throw Error('Item kind, classes or model properties changed during upload. Reopen the import for this draft.');
    applyRigidGLB(builder,result.mesh);
    close();builder.msg('GLB stored and applied to draft. Save the custom item, then Spawn + Equip.');
  }catch(error){if(!closed)status.textContent=error.message;}finally{busy=false;if(!closed){file.disabled=false;for(const input of Object.values(inputs))input.disabled=false;update();}}};
  return close;
}
