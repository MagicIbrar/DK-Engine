// Original three-dimensional structures for the seven remaining catalog families.
import * as THREE from 'three';
const TAU=Math.PI*2,mix=(a,b,t)=>a.map((x,i)=>x+(b[i]-x)*t),V=a=>new THREE.Vector3(...a);
export function buildAdditionalFamily(d,Surface){
 const s=[new Surface(),new Surface(),new Surface()],colors=d.palette.map(c=>new THREE.Color(c)),detail=d.lod?3:5;
 const tube=(slot,p,r=.025,c=colors[slot],steps=d.lod?5:8)=>s[slot].tube(p,r,c,4,steps);
 const ring=(slot,x,y,rx,ry,z=.2,tilt=0,r=.035)=>tube(slot,Array.from({length:17},(_,i)=>{const a=i/16*TAU;return[x+Math.cos(a)*rx,y+Math.sin(a)*ry,z+Math.sin(a)*tilt];}),r,colors[slot]);
 const leaf=(slot,a,b,w=.1,c=colors[slot])=>s[slot].feather(a,b,w,c,.04,d.lod?1:3,true);
 const sail=(slot,a,b,c,depth=.09,color=colors[slot])=>s[slot].skin((u,v)=>{const p=mix(a,mix(b,c,u),v);p[2]+=depth*Math.sin(Math.PI*u)*Math.sin(Math.PI*v);return p;},detail,detail,color,.008);
 const spike=(slot,a,b,w=.09,c=colors[slot])=>{const axis=V(b).sub(V(a)),n=new THREE.Vector3(-axis.y,axis.x,0).normalize().multiplyScalar(w),q=new THREE.Vector3(0,0,w*.7),root=V(a),mid=root.clone().lerp(V(b),.32),p=[mid.clone().add(n),mid.clone().add(q),mid.clone().sub(n),mid.clone().sub(q)];for(let i=0;i<4;i++){s[slot].facet(root.toArray(),p[(i+1)%4].toArray(),p[i].toArray(),c);s[slot].facet(p[i].toArray(),p[(i+1)%4].toArray(),b,c);}};
 const n=d.form==='sunwheel'?(d.lod?5:8):d.lod?Math.max(3,Math.floor(d.count*.7)):d.count;
 if(d.family==='machine'){
  if(d.form==='thruster'){for(const [x,y,r]of [[.58,.34,.26],[1.03,-.25,.21]]){ring(0,x,y,r,r,.19,.02,.075);ring(1,x,y,r*.72,r*.72,.28,0,.035);for(let i=0;i<5;i++){const a=i/5*TAU;spike(2,[x,y,.26],[x+Math.cos(a)*r*.65,y+Math.sin(a)*r*.65,.28],.035);}tube(0,[[.05,0,0],[.40,.37,.15],[1.3,.40,.16]],.055);}}
  else if(d.form==='magnetic'){for(let i=0;i<3;i++)ring(i,.72,.18,.43+i*.08,.65-i*.08,.15+i*.10,.17,.03);for(let i=0;i<n;i++){const a=i/n*TAU,x=.72+Math.cos(a)*.44,y=.18+Math.sin(a)*.57;spike(1,[x-.10,y-.07,.27],[x+.10,y+.12,.29],.08);}}
  else if(d.form==='sail'){for(let i=0;i<2;i++){const x=.55+i*.56,y=.45-i*.50,a=[.08,0,.08],b=[x,y+.50,.24],c=[x+.47,y-.42,.16];sail(i,a,b,c,.05);for(let j=1;j<4;j++)tube(2,[mix(a,b,j/4),mix(a,c,j/4)],.009,colors[1],4);tube(0,[a,b,c],.035);}}
  else if(d.form==='glider'){sail(0,[.06,0,.04],[d.span,.37,.20],[.95,-.48,.16],.13);tube(1,[[.06,0,.04],[d.span,.37,.20]],.048);tube(1,[[.06,0,.04],[.95,-.48,.16]],.030);for(let i=1;i<4;i++)tube(2,[[.18,0,.13],[.5+i*.25,.12-i*.12,.23]],.01);}
  else{ring(0,.33,.22,.14,.14,.19,.02,.034);for(let i=0;i<n;i++){const t=i/(n-1),a=[.22+t*.72,.33+Math.sin(t*Math.PI)*.2,.18],b=[.45+t*d.span*.68,.12-d.drop*t,.2];leaf(1,a,b,.09);tube(2,[a,b],.007); }tube(0,[[.07,0,.02],[.33,.22,.16],[1.1,.47,.20]],.055);}
 }else if(d.family==='crystal'){
  if(d.form==='antlers'){for(let i=0;i<3;i++){const root=[.08,0,.04],joint=[.34+i*.20,.45,.17],end=[.50+i*.44,.9+i*.2,.25];tube(1,[root,joint,end],.065);for(let j=0;j<2;j++)spike(0,joint,[end[0]+(j?.24:-.12),end[1]-.23,.22],.08);spike(2,end,[end[0]+.05,end[1]+.23,.27],.05);}}
  else if(d.form==='geode'){ring(1,.76,.10,.51,.66,.2,.12,.095);for(let i=0;i<n;i++){const a=i/n*TAU,x=.76+Math.cos(a)*.43,y=.10+Math.sin(a)*.55;spike(0,[x,y,.14],[x-.16*Math.cos(a),y-.27*Math.sin(a),.36],.07);}}
  else{for(let i=0;i<n;i++){const t=i/(n-1),a=[.18+t*d.span*.66,-.35+t*.18,.12],b=[a[0]+(d.form==='comet'?.45:.1),d.rise*(.32+.65*Math.sin(t*Math.PI)),.2+(i%3)*.06];spike(0,a,b,.06+(i%3)*.02);spike(2,mix(a,b,.14),mix(a,b,.7),.018);}if(d.form==='cathedral')ring(1,.7,.3,.42,.97,.19,.08,.038);if(d.form==='comet')tube(1,[[.08,.15,.04],[.7,-.35,.2],[d.span,-d.drop,.28]],.055);}
 }else if(d.family==='botanical'){
  if(d.form==='fern'){for(let branch=0;branch<3;branch++){const a=[.09,0,.03],b=[.5+branch*.4,.75+branch*.18,.2];tube(1,[a,mix(a,b,.6),b],.025);for(let j=1;j<4;j++){const t=j/4,c=mix(a,b,t),w=.28*(1-t*.6);s[0].feather(c,[c[0]+w,c[1]+.09,c[2]+.03],.05,colors[0],.04,d.lod?1:2,true);s[0].feather(c,[c[0]-.18,c[1]+.15,c[2]+.02],.045,colors[0],.04,d.lod?1:2,true);}}}
  else if(d.form==='maple'){for(let i=0;i<5;i++){const t=i/4,c=[.32+t*d.span*.6,.65*Math.sin(t*Math.PI)-.15,.16];tube(1,[[.09,-.1,.03],c],.022);s[0].skin((r,v)=>{const a=v*TAU,rad=.25*(.62+.38*Math.cos(a*5));return[c[0]+Math.cos(a)*rad*r,c[1]+Math.sin(a)*rad*r,c[2]+.07*Math.sin(Math.PI*r)];},d.lod?1:2,d.lod?10:15,colors[0],.007);}}
  else if(d.form==='lotus'){for(let i=0;i<n;i++){const a=-.65+i/(n-1)*1.9;leaf(i%2,[.08,-.06,.06],[.5+Math.cos(a)*.7,Math.sin(a)*1.03,.18+i%2*.1],.16);}ring(2,.26,.08,.11,.13,.29,0,.03);}
  else if(d.form==='rose'){ring(1,.73,.2,.5,.63,.18,.1,.027);for(let i=0;i<n;i++){const a=i/n*TAU,c=[.73+Math.cos(a)*.5,.2+Math.sin(a)*.63,.18];leaf(0,c,[c[0]+.20,c[1]+.16,.24],.105);spike(1,c,[c[0]-.07,c[1]+.1,.25],.025);ring(2,c[0],c[1],.035,.045,.25,.015,.025);}}
  else{tube(1,[[.08,0,.02],[.55,.6,.20],[d.span,.52,.21]],.030);for(let i=0;i<n;i++){const t=i/(n-1),a=[.22+t*d.span*.76,.51*Math.sin(t*Math.PI),.19];leaf(0,a,[a[0]+.11,a[1]-.33-d.drop*t*.4,.23],.047);}}
 }else if(d.family==='celestial'){
  if(d.form==='orrery'){for(let i=0;i<3;i++)ring(i,.7,.16,.46+i*.08,.68-i*.12,.15+i*.10,(i-1)*.32,.027);for(let i=0;i<4;i++){const a=i/4*TAU;spike(2,[.7+Math.cos(a)*.5,.16+Math.sin(a)*.7,.25],[.7+Math.cos(a)*.66,.16+Math.sin(a)*.86,.25],.06);}}
  else if(d.form==='crescent'){tube(0,Array.from({length:17},(_,i)=>{const a=-1.5+i/16*3;return[.67+Math.cos(a)*.52,.16+Math.sin(a)*.85,.17+Math.sin(a)*.12];}),.09);for(let i=0;i<3;i++){const x=.32+i*.26;tube(1,[[x,-.43,.2],[x,-.75-i*.10,.24]],.012);spike(2,[x,-.73-i*.1,.23],[x,-.9-i*.1,.23],.045);}}
  else if(d.form==='constellation'){const p=Array.from({length:n},(_,i)=>[.24+i%4*.35,.8-Math.floor(i/4)*.5+i%2*.14,.13+i%3*.07]);for(let i=0;i<p.length;i++){spike(2,p[i],[p[i][0],p[i][1]+.12,p[i][2]],.05);if(i)tube(1,[p[Math.floor((i-1)/2)],p[i]],.012);}}
  else{ring(1,.72,.17,.46,.63,.2,.15,.031);for(let i=0;i<n;i++){const a=i/n*TAU,root=[.72+Math.cos(a)*.46,.17+Math.sin(a)*.63,.20],tip=[.72+Math.cos(a)*(i%2?.72:.93),.17+Math.sin(a)*(i%2?.86:1.11),.22];leaf(0,root,tip,d.form==='eclipse'?.07:.04);}}
 }else if(d.family==='aquatic'){
  if(d.form==='coral'){for(let i=0;i<4;i++){const a=[.07,-.1,.03],b=[.4+i*.23,.36+i%3*.27,.20];tube(0,[a,mix(a,b,.6),b],.047);for(const off of [-.16,.18]){const end=[b[0]+off,b[1]+.2,.25];tube(1,[mix(a,b,.65),end],.026);ring(2,end[0],end[1],.024,.034,.26,0,.022);}}}
  else if(d.form==='nautilus'){const p=Array.from({length:25},(_,i)=>{const a=i/24*TAU*1.7,r=.07+i/24*.64;return[.66+Math.cos(a)*r,.13+Math.sin(a)*r,.13+i/24*.17];});tube(0,p,.09,colors[0],d.lod?16:24);for(let i=1;i<n;i++){const t=i/n,a=t*TAU*1.7,r=.07+t*.64;tube(1,[[.66+Math.cos(a)*r,.13+Math.sin(a)*r,.13+t*.17],[.66+Math.cos(a)*(r+.07),.13+Math.sin(a)*(r+.07),.18+t*.17]],.018,colors[2]);}}
  else if(d.form==='jelly'){s[0].skin((u,v)=>{const a=v*Math.PI*1.8-Math.PI*.4,r=Math.sin(u*Math.PI/2);return[.63+Math.cos(a)*.60*r,.18+Math.sin(a)*.74*r,.13+.25*Math.cos(u*Math.PI/2)];},detail,d.lod?8:12,colors[0],.008);for(let i=0;i<6;i++){const x=.23+i*.17;tube(1,[[x,-.1,.2],[x+.08,-.48,.29],[x-.04,-.9+i%3*.12,.24]],.015);}}
  else{const root=[.09,0,.07];sail(0,root,[d.span,.35,.22],[.56,-d.drop*.7,.17],.14);for(let i=0;i<n;i++){const t=i/(n-1),end=[.43+t*(d.span-.43),d.rise*(1-t)-d.drop*t*.37,.20];tube(1,[root,mix(root,end,.6),end],d.form==='lionfish'?.025:.012);if(d.form==='lionfish')spike(2,end,[end[0]+.12,end[1]+.24,.22],.028);}if(d.form==='manta')tube(2,[[.32,-.18,.17],[.82,-.61,.22],[1.1,-1,.26]],.026);}
 }else if(d.family==='spectral'){
  if(d.form==='lantern'){ring(0,.69,.22,.43,.65,.21,.15,.038);ring(1,.69,.22,.31,.49,.27,-.15,.032);spike(2,[.69,-.1,.25],[.69,.43,.28],.13);for(let i=0;i<3;i++)leaf(1,[.33+i*.26,-.32,.20],[.42+i*.22,-.9,.29],.044);}
  else if(d.form==='dream'){ring(1,.68,.22,.46,.6,.22,.1,.028);for(let i=0;i<n;i++){const a=i/n*TAU,b=a+TAU*.375;tube(2,[[.68+Math.cos(a)*.4,.22+Math.sin(a)*.54,.22],[.68+Math.cos(b)*.4,.22+Math.sin(b)*.54,.26]],.006);}for(let i=0;i<3;i++)leaf(0,[.34+i*.27,-.3,.18],[.40+i*.23,-1,.25],.055);}
  else if(d.form==='spiral'){for(let arm=0;arm<3;arm++){const points=Array.from({length:17},(_,i)=>{const a=i/16*4.5+arm*.33,r=.10+i/16*.74;return[.65+Math.cos(a)*r,.14+Math.sin(a)*r,.12+arm*.07+Math.sin(a)*.07];});tube(arm,points,.027,colors[arm],d.lod?10:16);}}
  else{const count=d.form==='ribbon'?3:Math.min(n,7);for(let i=0;i<count;i++){const h=d.rise*(.5+.45*Math.sin(i/(count-1)*Math.PI));s[i%3].skin((t,v)=>{const x=.10+t*d.span*(.65+i*.055),y=d.form==='fire'?-.25+Math.sin(t*Math.PI)*h:.05+Math.sin(t*TAU+i)*.17-t*d.drop*.45;return[x,y+(v-.5)*(d.form==='fire'?.31:.38)*Math.sin(Math.PI*t)**.55,.18+Math.sin(t*TAU+i)*.16];},d.lod?6:10,2,colors[i%3],.010);}}
 }else if(d.family==='heraldic'){
  if(d.form==='laurel'){tube(1,Array.from({length:17},(_,i)=>{const a=-1.4+i/16*3.2;return[.66+Math.cos(a)*.54,.17+Math.sin(a)*.74,.16+Math.sin(a)*.1];}),.025);for(let i=0;i<n;i++){const a=-1.3+i/(n-1)*2.8,c=[.66+Math.cos(a)*.54,.17+Math.sin(a)*.74,.17];leaf(0,c,[c[0]+Math.cos(a+.7)*.17,c[1]+Math.sin(a+.7)*.23,.23],.075);}}
  else if(d.form==='standard'){for(let i=0;i<3;i++){const x=.26+i*.38,h=d.rise*(1-i*.19);tube(1,[[x,-.7,.10],[x,h,.13]],.023);s[0].skin((u,v)=>[x+u*.32,h-.1-v*(h+.55)-u*.14,.16+Math.sin(u*Math.PI+v*4)*.09],detail,detail,colors[0],.006);spike(2,[x,h,.12],[x,h+.13,.13],.045);}}
  else if(d.form==='runeblade'){for(let i=0;i<n;i++){const t=i/(n-1),a=[.20+t*.68,.30,.13],b=[.38+t*d.span*.66,d.rise*(.6-t*.55)-.2,.20];spike(0,a,b,.067);const c=mix(a,b,.23);tube(1,[[c[0]-.10,c[1],.19],[c[0]+.10,c[1],.19]],.018);tube(2,[mix(a,b,.25),mix(a,b,.85)],.008);}}
  else{for(let i=0;i<n;i++){const t=i/(n-1),a=[.17+t*.72,.37+Math.sin(t*Math.PI)*.15,.16],b=[.34+t*d.span*.72,d.rise*(.56-t*.65)-d.drop*.25,.20];leaf(0,a,b,d.form==='aegis'?.13:.065);tube(1,[a,mix(a,b,.75),b],.008);if(d.form==='aegis')spike(2,mix(a,b,.55),mix(a,b,.68),.025);}}
 }
 // Layered wing mass under the ornamental armature; every family retains its own structure.
 const vane=(slot,a,b,w=.13,c=colors[slot])=>{s[slot].feather(a,b,w,c,.024,d.lod?1:3,false);tube(2,[a,mix(a,b,.55),b],.005,colors[2],d.lod?2:3);};
 const band=(slot,cx,cy,rx,ry,start,end,width,z=.16)=>s[slot].skin((u,v)=>{const a=start+(end-start)*v,r=1+(u-.5)*width;return[cx+Math.cos(a)*rx*r,cy+Math.sin(a)*ry*r,z+.04*Math.sin(Math.PI*u)+.09*Math.sin(a)];},d.lod?1:2,d.lod?8:16,colors[slot],.008);
 if(d.form==='thruster'){for(let i=0;i<5;i++){const t=i/4;vane(1,[.15+t*.55,.28+t*.09,.12],[.52+t*.99,-.36-t*.42,.17+t*.06],.115);}sail(0,[.12,.0,.08],[.76,.73,.16],[1.31,.36,.20],.04);}
 if(d.form==='magnetic'){for(let i=0;i<6;i++){const a=-1.15+i*.43;vane(i%2,[.65+Math.cos(a)*.28,.12+Math.sin(a)*.34,.17],[.65+Math.cos(a+.16)*.73,.12+Math.sin(a+.16)*.93,.28],.14);}for(let i=0;i<3;i++)vane(0,[.18+i*.22,-.17,.14],[.57+i*.25,-.98+i*.08,.20],.10);}
 if(d.family==='celestial'){
  if(d.form==='orrery'){band(0,.72,.15,.55,.78,-1.22,1.42,.45,.11);band(1,.72,.15,.67,.62,1.78,4.27,.43,.19);for(let i=0;i<3;i++)vane(0,[.24+i*.27,-.15,.13],[.51+i*.33,-1.12+i*.17,.22],.12);}
  else if(d.form==='crescent'){band(0,.66,.16,.58,.87,-1.55,1.55,.62,.12);for(let i=0;i<4;i++){const a=-.7+i*.43;vane(1,[.45+Math.cos(a)*.36,.13+Math.sin(a)*.55,.14],[.43+Math.cos(a)*.96,.13+Math.sin(a)*1.16,.22],.12);}}
  else if(d.form==='constellation'){for(let i=0;i<4;i++){const t=i/3;vane(0,[.12+t*.30,.25,.13],[.69+t*.82,.65-t*1.40,.21],.18);}sail(1,[.18,.13,.09],[1.28,.68,.19],[.91,-.63,.22],.035);}
  else{for(let i=0;i<7;i++){const t=i/6,a=[.14+t*.66,.37+.20*Math.sin(t*Math.PI),.13],b=[.35+t*1.26,.58-.98*t,.20];vane(0,a,b,d.form==='eclipse'?.15:.125);}if(d.form==='sunwheel')band(1,.72,.17,.46,.63,-1.3,1.3,.30,.22);}
 }
 if(d.family==='spectral'){
  if(d.form==='lantern'){for(let i=0;i<5;i++){const t=i/4;vane(0,[.17+t*.44,.24,.15],[.48+t*.91,.68-t*1.35,.25],.14);}band(1,.69,.22,.43,.65,-1.35,1.35,.38,.23);}
  else if(d.form==='dream'){s[0].skin((r,v)=>{const a=v*TAU;return[.68+Math.cos(a)*.42*r,.22+Math.sin(a)*.56*r,.15+.025*Math.sin(Math.PI*r)];},d.lod?1:2,d.lod?12:20,colors[0],.005);for(let i=0;i<4;i++)vane(0,[.23+i*.20,-.19,.14],[.35+i*.27,-1.05+i*.06,.25],.105);}
  else if(d.form==='ribbon'){for(let i=0;i<3;i++)vane(1,[.12+i*.19,-.10,.15],[.70+i*.34,-.74-i*.11,.24],.13,colors[0]);}
  else if(d.form==='spiral'){for(let arm=0;arm<3;arm++)s[arm].skin((t,v)=>{const a=t*4.5+arm*.33,r=.10+t*.74+(v-.5)*(.10+.15*Math.sin(Math.PI*t));return[.65+Math.cos(a)*r,.14+Math.sin(a)*r,.12+arm*.07+Math.sin(a)*.07+.03*Math.sin(Math.PI*v)];},d.lod?5:8,2,colors[arm],.008);}
 }
 return s;
}
