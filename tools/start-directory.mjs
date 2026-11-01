import http from 'node:http';
import {createDirectory} from '../server/directory.mjs';
const directory=createDirectory({adminToken:process.env.DEKARON_DIRECTORY_TOKEN,relayHosts:(process.env.DEKARON_DIRECTORY_RELAY_HOSTS||'').split(',').filter(Boolean),contentVersion:process.env.DEKARON_DIRECTORY_CONTENT_VERSION});
const port=Number(process.env.PORT||7790);if(!Number.isInteger(port)||port<1||port>65535)throw new Error('Invalid directory port.');
http.createServer(async(req,res)=>{try{if(!await directory.handle(req,res,new URL(req.url,'http://directory').pathname)){res.writeHead(404);res.end();}}catch{res.writeHead(500);res.end('Directory request failed.');}}).listen(port,process.env.HOST||'127.0.0.1',()=>console.log('Dekaron directory ready.'));
