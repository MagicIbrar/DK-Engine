// Copy PNG pixels/color information without embedded generator IDs, certificates or textual metadata.
const SIGNATURE=Buffer.from([137,80,78,71,13,10,26,10]);
const PERMITTED=new Set(['IHDR','PLTE','IDAT','IEND','tRNS','gAMA','cHRM','sRGB']);
export function pngChunks(bytes){
 if(!bytes.subarray(0,8).equals(SIGNATURE))throw new Error('Invalid release PNG signature.');
 const result=[];let offset=8;
 while(offset<bytes.length){
  if(offset+12>bytes.length)throw new Error('Truncated release PNG chunk.');
  const length=bytes.readUInt32BE(offset),end=offset+length+12;
  if(end>bytes.length)throw new Error('Truncated release PNG data.');
  result.push({type:bytes.toString('ascii',offset+4,offset+8),bytes:bytes.subarray(offset,end)});offset=end;
 }
 if(result[0]?.type!=='IHDR'||result.at(-1)?.type!=='IEND'||!result.some(c=>c.type==='IDAT'))throw new Error('Incomplete release PNG.');
 return result;
}
export function sanitizeReleasePng(bytes){
 const chunks=pngChunks(bytes);
 for(const chunk of chunks)if(!PERMITTED.has(chunk.type)&&chunk.type[0]===chunk.type[0].toUpperCase())throw new Error('Unsupported critical release PNG chunk.');
 return Buffer.concat([SIGNATURE,...chunks.filter(c=>PERMITTED.has(c.type)).map(c=>c.bytes)]);
}
