// Address-only offline QR generation. No server request, account, password or third-party service.
import {qrcodegen} from './vendor/qrcodegen.mjs';
import {pathToFileURL} from 'node:url';
import path from 'node:path';
function privateIp(host){const parts=host.split('.');if(parts.length!==4||parts.some(p=>!/^\d{1,3}$/.test(p)||String(Number(p))!==p||Number(p)>255))return false;const [a,b]=parts.map(Number);return a===10||a===172&&b>=16&&b<=31||a===192&&b===168;}
export function canonicalJoinAddress(value){
 if(typeof value!=='string'||!value||value.length>512||/[\s\\]/.test(value))throw Error('Use the current server address without credentials or extra data.');
 const hostMatch=/^https?:\/\/(\[[^\]]+\]|[^:/%?#]+)(?::\d+)?(?:\/|$)/i.exec(value);if(!hostMatch)throw Error('Use an HTTPS or private LAN server address.');
 const uri=new URL(value);if(uri.hostname.toLowerCase()!==hostMatch[1].toLowerCase()||uri.username||uri.password||uri.search||uri.hash||!['/','/join','/join.html'].includes(uri.pathname)||uri.hostname.toLowerCase()==='localhost'||uri.hostname.startsWith('127.')||['[::1]','::1'].includes(uri.hostname))throw Error('Share only a reachable server address. Passwords stay separate.');
 if(uri.protocol!=='https:'&&!(uri.protocol==='http:'&&privateIp(uri.hostname)))throw Error('Use HTTPS, or HTTP with a private LAN IP.');
 if(uri.port==='0')throw Error('Invalid server port.');
 return uri.origin+'/join';
}
export function connectionQr(value){
 const address=canonicalJoinAddress(value),payload='dekaron://join?address='+encodeURIComponent(address);
 const qr=qrcodegen.QrCode.encodeText(payload,qrcodegen.QrCode.Ecc.MEDIUM);
 return {address,payload,size:qr.size,quietZone:4,matrix:Array.from({length:qr.size},(_,y)=>Array.from({length:qr.size},(_,x)=>qr.getModule(x,y)?'1':'0').join(''))};
}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){
 try{let input='';for await(const chunk of process.stdin){input+=chunk;if(input.length>2048)throw Error('Invalid QR input.');}const request=JSON.parse(input);if(Object.keys(request).join(',')!=='address')throw Error('QR input must contain only an address.');process.stdout.write(JSON.stringify(connectionQr(request.address)));}catch(e){console.error(e.message);process.exitCode=1;}
}
