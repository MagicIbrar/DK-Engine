import {slotForKind} from './registry.js';

/** A rigid import must resolve to the original catalog's actual attachment. */
export function glbTarget(builder) {
  const {draft:d,db,target,lookClass,pvClass}=builder;
  const className=ci=>db?.enums.classes?.[ci]?.name||`class #${ci}`;
  if(!d||!db)throw Error('Choose an item draft first.');
  if(!['main','left','inv'].includes(target))throw Error('Choose a supported model target.');
  const slot=slotForKind(db,Number(d.type),Number(d.code));
  const signature=JSON.stringify([d.type,d.code,d.classMask,target,lookClass,pvClass,d.look,d.shape,d.action]);
  if(target==='inv')return{signature,label:'Inventory model (no equipped attachment)'};
  if(Number(d.type)!==4||!['weapon','offhand'].includes(slot))throw Error('Equipped GLB requires a rigid weapon/offhand slot. Armor needs verified native rig mapping.');
  const rule=db.weaponRule(d);
  if(!rule)throw Error('This item kind has no original weapon attachment rule.');
  if(target==='left'&&rule.column!=='both')throw Error('Left model is used only by paired weapons. Choose the main target for this kind.');
  const ci=Number(lookClass==='all'||target==='left'?pvClass:lookClass),mask=Number(d.classMask)||0;
  if(!Number.isInteger(ci)||ci<0||ci>14||!db.enums.classes?.[ci]||!((mask>>>ci)&1))throw Error('Choose a preview/attachment class allowed by the item.');
  const classes=lookClass==='all'||target==='left'?Array.from({length:15},(_,i)=>i).filter(i=>(mask>>>i)&1):[ci];
  const side=target==='left'||rule.column==='left'?'Left':'Right';
  for(const index of classes){
    // The runtime resolver has cross-class fallbacks; import acceptance requires a real row for this class.
    const bones=db.equipment.weaponBones?.[index]?.[1024+Number(d.code)];
    if(!bones?.[`battle${side}`])throw Error(`No native ${side.toLowerCase()} attachment for ${className(index)}. Restrict the item classes or choose another kind.`);
  }
  const animated=!!db._actionsData?.item?.[d.look?.action]?.skel;
  if(animated&&(target==='left'||lookClass!=='all'))throw Error('This animated weapon shares its action across model targets. Clone a static weapon before importing a left/class-specific model.');
  return{signature,label:`${slot} · ${target} · ${className(ci)} · ${classes.length} allowed class(es)`};
}

/** Keep animation/model fields belonging to the other attachment targets. */
export function applyRigidGLB(builder, mesh) {
  glbTarget(builder);
  const d=builder.draft;
  if(builder.target==='main'){
    if(d.look.left&&d.look.leftAction==null&&d.look.action!=null)d.look.leftAction=d.look.action;
    builder.setAsset({mesh},{action:null});
    if(builder.lookClass==='all'){d.shape.inv={mesh};d.shape.field={mesh};delete d.shape.invAnim;delete d.shape.invSkel;}
    builder.lookChanged();
  }else builder.setAsset({mesh});
}
