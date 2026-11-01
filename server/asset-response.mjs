import fs from 'node:fs';
import path from 'node:path';
import zlib from 'node:zlib';

// Text and map data compress 5-10x; the client loads ~300 MB of it uncompressed otherwise. Compressed bodies are built once per file
// version (weak ETag) and kept in a size-capped memory cache; ranges, HEAD and tiny / already-compressed files are sent as they are.
const COMPRESSIBLE=new Set(['.html','.js','.mjs','.css','.json','.svg','.csv','.txt','.ini','.map','.mol','.mel','.mac','.mal','.dds','.mesh','.anim','.skel','.tpack','.tga','.bmp']);
const MIN_COMPRESS=1024,MAX_COMPRESS_FILE=96*1024*1024,PACKED_LIMIT=384*1024*1024;
const packed=new Map(),packedSize=new Map();let packedTotal=0;
const encodingOf=req=>{const header=String(req.headers['accept-encoding']||'');return /(?:^|[\s,])br(?:[;,\s]|$)/i.test(header)?'br':/(?:^|[\s,])gzip(?:[;,\s]|$)/i.test(header)?'gzip':null;};
function packedBody(file,etag,encoding){
 const key=`${encoding}|${etag}|${file}`,hit=packed.get(key);
 if(hit){packed.delete(key);packed.set(key,hit);return hit;}
 const task=fs.promises.readFile(file).then(raw=>new Promise((resolve,reject)=>{
  const done=(error,body)=>error?reject(error):resolve(body.length<raw.length?body:null);
  if(encoding==='br')zlib.brotliCompress(raw,{params:{[zlib.constants.BROTLI_PARAM_QUALITY]:4,[zlib.constants.BROTLI_PARAM_SIZE_HINT]:raw.length}},done);
  else zlib.gzip(raw,{level:6},done);
 }));
 packed.set(key,task);
 task.then(body=>{const size=body?body.length:0;packedSize.set(key,size);packedTotal+=size;for(const old of packed.keys()){if(packedTotal<=PACKED_LIMIT)break;if(old===key)continue;packedTotal-=packedSize.get(old)||0;packed.delete(old);packedSize.delete(old);}},()=>{packed.delete(key);});
 return task;
}

const TYPES={'.html':'text/html; charset=utf-8','.js':'text/javascript; charset=utf-8','.mjs':'text/javascript; charset=utf-8','.css':'text/css; charset=utf-8','.json':'application/json; charset=utf-8','.png':'image/png','.jpg':'image/jpeg','.svg':'image/svg+xml','.mp3':'audio/mpeg','.wav':'audio/wav','.ttf':'font/ttf','.csv':'text/plain; charset=latin1','.txt':'text/plain; charset=latin1','.ini':'text/plain; charset=latin1'};
const opaqueTag=value=>String(value||'').replace(/^W\//,'');
export function assetETag(stat,generation=''){
 // Include the code/content generation: release timestamps are normalized and
 // equal-size updates must not inherit an older release's cached response.
 return `W/"${Buffer.from(generation).toString('hex')}-${stat.size.toString(16)}-${stat.mtimeMs.toString(16)}-${stat.ctimeMs.toString(16)}"`;
}
function notModified(req,etag,stat,generation){
 if(req.headers['if-none-match']!==undefined)return String(req.headers['if-none-match']).split(',').some(value=>value.trim()==='*'||opaqueTag(value.trim())===opaqueTag(etag));
 // Date validators cannot distinguish two writes in the same second. Only
 // honor a date once the file has aged past that resolution window.
 if(generation)return false; // Normalized release dates are not generation identifiers.
 const since=Date.parse(req.headers['if-modified-since']);
 return Number.isFinite(since)&&Date.now()-stat.mtimeMs>=1000&&Math.floor(stat.mtimeMs/1000)*1000<=since;
}
function byteRange(value,size){
 const match=/^bytes=(\d*)-(\d*)$/.exec(value||'');
 if(!match||(!match[1]&&!match[2]))return null;
 const first=match[1]?Number(match[1]):null,last=match[2]?Number(match[2]):null;
 if(first!==null&&!Number.isSafeInteger(first)||last!==null&&!Number.isSafeInteger(last)||size===0)return false;
 const start=first===null?Math.max(0,size-last):first,end=first!==null&&last!==null?Math.min(last,size-1):size-1;
 return start>=0&&start<=end&&start<size?{start,end}:false;
}
// Content generation is CLIENT_SOURCE.version; runtime ETag generation is deliberately separate.
// Exported so disposable fixtures exercise exactly the production cache decision.
export function contentAssetCacheControl(req, contentVersion, privateCache = false) {
 if (privateCache) return 'private, no-cache';
 const version = new URL(req.url, 'http://localhost').searchParams.get('v');
 return contentVersion && contentVersion !== 'legacy' && version === contentVersion
   ? 'public, max-age=31536000, immutable' : 'no-cache';
}
export function sendAssetFile(req,res,file,{optional=false,generation='',privateCache=false,maxAge=0,contentVersion=null,contentAsset=false}={}){
 fs.stat(file,(error,stat)=>{
  if(error||!stat.isFile()){
   if(optional){res.writeHead(204,{'X-Missing':'1','Access-Control-Allow-Origin':'*','Cache-Control':'no-cache'});return res.end();}
   res.writeHead(404,{'Access-Control-Allow-Origin':'*','Cache-Control':'no-store'});return res.end(req.method==='HEAD'?undefined:'not found');
  }
  const extension=path.extname(file).toLowerCase(),squeezable=COMPRESSIBLE.has(extension)&&stat.size>=MIN_COMPRESS&&stat.size<=MAX_COMPRESS_FILE;
  const etag=assetETag(stat,generation),headers={'Content-Type':TYPES[extension]||'application/octet-stream','Accept-Ranges':'bytes',...privateCache?{Vary:squeezable?'Cookie, Accept-Encoding':'Cookie'}:{'Access-Control-Allow-Origin':'*',...squeezable?{Vary:'Accept-Encoding'}:{}},'Cache-Control':contentAsset?contentAssetCacheControl(req,contentVersion,privateCache):privateCache?'private, no-cache':maxAge>0?`public, max-age=${Math.floor(maxAge)}`:'no-cache','ETag':etag,...generation?{}:{'Last-Modified':stat.mtime.toUTCString()}};
  if(notModified(req,etag,stat,generation)){res.writeHead(304,headers);return res.end();}
  // Weak validators cannot authorize partial reuse. A matching HTTP date may;
  // mismatched/weak If-Range requests receive the entire current file.
  const ifRange=req.headers['if-range'],date=Date.parse(ifRange);
  const rangeAllowed=!ifRange||!generation&&Number.isFinite(date)&&Math.floor(stat.mtimeMs/1000)*1000<=date&&Date.now()-stat.mtimeMs>=1000;
  const range=req.method==='GET'&&rangeAllowed?byteRange(req.headers.range,stat.size):null;
  if(range===false){res.writeHead(416,{...headers,'Content-Range':`bytes */${stat.size}`});return res.end();}
  if(range){
   res.writeHead(206,{...headers,'Content-Range':`bytes ${range.start}-${range.end}/${stat.size}`,'Content-Length':range.end-range.start+1});
   return fs.createReadStream(file,range).on('error',()=>res.destroy()).pipe(res);
  }
  const plain=()=>{res.writeHead(200,{...headers,'Content-Length':stat.size});fs.createReadStream(file).on('error',()=>res.destroy()).pipe(res);};
  if(req.method==='HEAD'){res.writeHead(200,{...headers,'Content-Length':stat.size});return res.end();}
  const encoding=squeezable?encodingOf(req):null;
  if(!encoding)return plain();
  packedBody(file,etag,encoding).then(body=>{
   if(res.destroyed)return;
   if(!body)return plain();
   res.writeHead(200,{...headers,'Content-Encoding':encoding,'Content-Length':body.length});res.end(body);
  },()=>{if(!res.destroyed)plain();});
 });
}
