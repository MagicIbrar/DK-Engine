// Native-only publication helper. Secrets arrive via stdin, never command arguments.
import readline from 'node:readline';
import {fileURLToPath} from 'node:url';import path from 'node:path';
export async function publishServer({directory,url,publicationSecret},{fetcher=fetch}={}){
 const endpoint=new URL(directory);if(endpoint.protocol!=='https:'||endpoint.username||endpoint.password||endpoint.pathname!=='/'||endpoint.search||endpoint.hash)throw new Error('Use an HTTPS directory origin.');
 if(!/^[a-f0-9]{64}$/.test(publicationSecret))throw new Error('Publication proof is required.');
 const response=await fetcher(new URL('/api/servers/register',endpoint),{method:'POST',headers:{'Content-Type':'application/json'},body:JSON.stringify({url,publicationSecret}),redirect:'error',signal:AbortSignal.timeout(10000)});
 if(!response.ok)throw new Error('Directory rejected publication. Verify approved relay and host opt-in.');const result=await response.json();if(result.registered!==true||!/^[a-f0-9]{24}$/.test(result.id))throw new Error('Invalid directory response.');return {registered:true,id:result.id};
}
export async function maintainPublication(value,{closed,fetcher=fetch,interval=30000}={}){
 let registration=await publishServer(value,{fetcher});let finished=false;const endpoint=new URL(value.directory);
 const stop=()=>{finished=true;};closed?.then(stop,stop);process.stdout.write(JSON.stringify(registration)+'\n');
 try{while(!finished){await Promise.race([new Promise(r=>{const t=setTimeout(r,interval);closed?.then(()=>{clearTimeout(t);r();},()=>{clearTimeout(t);r();});}),closed]);if(finished)break;try{const r=await fetcher(new URL('/api/servers/'+registration.id+'/heartbeat',endpoint),{method:'POST',headers:{'Content-Type':'application/json'},body:JSON.stringify({publicationSecret:value.publicationSecret}),redirect:'error',signal:AbortSignal.timeout(10000)});if(!r.ok)registration=await publishServer(value,{fetcher});}catch{try{registration=await publishServer(value,{fetcher});}catch{/* retry while host is active; do not print secrets */}}}}
 finally{try{await fetcher(new URL('/api/servers/'+registration.id,endpoint),{method:'DELETE',headers:{'Content-Type':'application/json'},body:JSON.stringify({publicationSecret:value.publicationSecret}),redirect:'error',signal:AbortSignal.timeout(10000)});}catch{/* directory independently evicts unhealthy or opted-out hosts */}}
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){try{const watch=process.argv.length===3&&process.argv[2]==='--watch';if(process.argv.length!==2&&!watch)throw new Error('Supply publication JSON on stdin.');let raw='',closed;
 if(watch){const reader=readline.createInterface({input:process.stdin,crlfDelay:Infinity});let finish;closed=new Promise(r=>finish=r);reader.once('close',finish);process.once('SIGTERM',()=>{reader.close();finish();});process.once('SIGINT',()=>{reader.close();finish();});raw=await new Promise((resolve,reject)=>{reader.once('line',resolve);reader.once('close',()=>reject(new Error('Missing publication input.')));});}
 else{for await(const chunk of process.stdin){raw+=chunk;if(Buffer.byteLength(raw)>4096)throw new Error('Publication input too large.');}}
 if(Buffer.byteLength(raw)>4096)throw new Error('Publication input too large.');const value=JSON.parse(raw);if(Object.keys(value).some(k=>!['directory','url','publicationSecret'].includes(k)))throw new Error('Invalid publication input.');if(watch)await maintainPublication(value,{closed});else process.stdout.write(JSON.stringify(await publishServer(value))+'\n');
 }catch{process.stderr.write('Publication failed. Verify the directory and relay settings.\n');process.exitCode=1;}}
