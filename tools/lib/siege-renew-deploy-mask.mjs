import {parseDDS,decodeToRGBA} from '../../src/formats/dds.js';
export function compileSiegeDeployMask(buffer){
 const image=decodeToRGBA(parseDDS(buffer));if(image.width!==512||image.height!==512)throw Error('Native Siege deployment mask must be 512 x 512.');
 const bits=new Uint8Array(512*512/8);let allowed=0;
 for(let i=0;i<512*512;i++)if(image.data[i*4+3]<128){bits[i>>3]|=1<<(i&7);allowed++;}
 return {width:512,height:512,bits:Buffer.from(bits).toString('base64'),allowed,coordinates:'u=z,v=x',source:'minimap_red alpha < 128'};
}
