// Optional glow halo. World color/depth stay full resolution; only the halo is
// quarter-resolution. No tone mapping, DOF, or extra per-object rendering.
import * as T from 'three';
const vertexShader='varying vec2 uv0; void main(){uv0=uv;gl_Position=vec4(position.xy,0.,1.);}';
const fragmentShader=`varying vec2 uv0; uniform sampler2D base; uniform sampler2D halo;
uniform vec2 stepUV; uniform float mode; uniform float strength;
vec3 bright(vec2 p){vec3 c=texture2D(base,p).rgb; return c*max(0.,max(c.r,max(c.g,c.b))-.8);}
void main(){ if(mode>1.5){vec4 c=texture2D(base,uv0);gl_FragColor=vec4(c.rgb+texture2D(halo,uv0).rgb*strength,c.a);}
else if(mode<.5){gl_FragColor=vec4(bright(uv0)*.4+(bright(uv0-stepUV)+bright(uv0+stepUV))*.24+(bright(uv0-stepUV*2.)+bright(uv0+stepUV*2.))*.06,1.);}
else {gl_FragColor=vec4(texture2D(base,uv0).rgb*.4+(texture2D(base,uv0-stepUV).rgb+texture2D(base,uv0+stepUV).rgb)*.24+(texture2D(base,uv0-stepUV*2.).rgb+texture2D(base,uv0+stepUV*2.).rgb)*.06,1.);}}`;
export class Bloom {
  constructor(renderer){
    this.renderer=renderer;this.failed=false;this.size=new T.Vector2();this.viewport=new T.Vector4();this.scissor=new T.Vector4();
    this.camera=new T.Camera();this.scene=new T.Scene();
    this.material=new T.ShaderMaterial({vertexShader,fragmentShader,depthTest:false,depthWrite:false,toneMapped:false,
      uniforms:{base:{value:null},halo:{value:null},stepUV:{value:new T.Vector2()},mode:{value:0},strength:{value:.18}}});
    this.geometry=new T.PlaneGeometry(2,2);this.scene.add(new T.Mesh(this.geometry,this.material));
  }
  render(scene,camera){
    const r=this.renderer;if(this.failed){r.render(scene,camera);return;}
    const target=r.getRenderTarget(),test=r.getScissorTest(),auto=r.autoClear;
    r.getViewport(this.viewport);r.getScissor(this.scissor);
    try{
      r.getDrawingBufferSize(this.size);const w=this.size.x,h=this.size.y;
      if(!this.base){this.base=new T.WebGLRenderTarget(w,h,{depthBuffer:true});this.a=new T.WebGLRenderTarget(1,1,{depthBuffer:false});this.b=new T.WebGLRenderTarget(1,1,{depthBuffer:false});}
      if(this.base.width!==w||this.base.height!==h)this.base.setSize(w,h);
      const bw=Math.max(1,Math.ceil(w/4)),bh=Math.max(1,Math.ceil(h/4));
      if(this.a.width!==bw||this.a.height!==bh){this.a.setSize(bw,bh);this.b.setSize(bw,bh);}
      r.autoClear=true;r.setScissorTest(false);r.setRenderTarget(this.base);r.render(scene,camera);
      const u=this.material.uniforms;u.base.value=this.base.texture;u.mode.value=0;u.stepUV.value.set(1/bw,0);
      r.setRenderTarget(this.a);r.render(this.scene,this.camera);
      u.base.value=this.a.texture;u.mode.value=1;u.stepUV.value.set(0,1/bh);
      r.setRenderTarget(this.b);r.render(this.scene,this.camera);
      u.base.value=this.base.texture;u.halo.value=this.b.texture;u.mode.value=2;
      r.setRenderTarget(target);r.setViewport(this.viewport);r.setScissor(this.scissor);r.setScissorTest(test);r.render(this.scene,this.camera);
    }catch(error){this.failed=true;console.warn('[graphics] bloom unavailable; using direct rendering',error);r.setRenderTarget(target);r.setViewport(this.viewport);r.setScissor(this.scissor);r.setScissorTest(test);r.render(scene,camera);}
    finally{r.setRenderTarget(target);r.setViewport(this.viewport);r.setScissor(this.scissor);r.setScissorTest(test);r.autoClear=auto;}
  }
  dispose(){for(const t of [this.base,this.a,this.b])t?.dispose();this.geometry.dispose();this.material.dispose();}
}
