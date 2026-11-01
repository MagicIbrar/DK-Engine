import {ORIGINAL_EDIT_LIMITS} from '../../src/systems/mapbuilder/original-overlay.js';
const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
const json=(res,value)=>{res.writeHead(200,{'Content-Type':'application/json; charset=utf-8','Cache-Control':'no-store','X-Content-Type-Options':'nosniff'});res.end(JSON.stringify(value));};
const schemas={begin:['token','index','epoch','expectedVersion'],patch:['token','session','epoch','expectedVersion','requestId','changes'],finish:['token','session','epoch','expectedVersion','save'],ready:['token','index','epoch','version','generation']};
// These explicit structured operations only read the audited GM routers. Their
// existing permission/schema/rate validation still runs; no line shortcut.
export function originalEditReadOnlyGM(input){if(typeof input?.operation!=='string')return false;const fields={players:['token','operation'],npcRoster:['token','operation','map','offset','limit'],characterDirectory:['token','operation','query','offset'],inspectInventory:['token','operation','ref','targetId']},allowed=Object.hasOwn(fields,input.operation)?fields[input.operation]:null;return !!allowed&&Object.hasOwn(input,'token')&&Object.keys(input).every(k=>allowed.includes(k));}
// Inside the existing authenticated same-origin API. No separate listener.
export async function handleOriginalMapRequest({req,res,pathname,user,world,resolveUser,serialize}){
 if(!/^\/api\/world\/original-map-edits(?:\/|$)/.test(pathname))return false;
 if(!user?.id)fail('Sign in to read original overlays.',401);
 const api=world.originalMapEdits;if(!api)fail('Original-map editing is not configured.',503);
 if(req.method==='GET'&&pathname==='/api/world/original-map-edits'){json(res,{epoch:api.epoch,maps:api.allowedMaps});return true;}
 const read=/^\/api\/world\/original-map-edits\/(\d+)$/.exec(pathname);
 if(req.method==='GET'&&read){json(res,await api.read(Number(read[1])));return true;}
 const op=pathname.split('/').at(-1);if(req.method!=='POST'||!schemas[op])fail('Unknown original edit operation.',404);
 if(op!=='ready'&&!user.capabilities?.includes('gm:commands'))fail('GM editing authority is required.',403);
 if(!/^application\/json(?:;|$)/i.test(req.headers['content-type']||''))fail('Expected a JSON edit command.',415);
 const chunks=[];let size=0;for await(const chunk of req){size+=chunk.length;if(size>ORIGINAL_EDIT_LIMITS.body)fail('Original edit command exceeds its bound.',413);chunks.push(chunk);}
 let input;try{input=JSON.parse(Buffer.concat(chunks).toString());}catch{fail('Invalid edit JSON.');}
 const keys=schemas[op];if(!input||typeof input!=='object'||Array.isArray(input)||Object.keys(input).length!==keys.length||keys.some(k=>!Object.hasOwn(input,k))||Object.keys(input).some(k=>!keys.includes(k))||typeof input.token!=='string'||input.token.length>256||typeof input.epoch!=='string'||!Number.isSafeInteger(input.expectedVersion??input.version)||(input.expectedVersion??input.version)<0)fail('Invalid edit fields.');
 if((op==='begin'||op==='ready')&&(!Number.isInteger(input.index)||input.index<0||input.index>=90000))fail('Invalid original map index.');
 if(op==='ready'&&(typeof input.generation!=='string'||input.generation.length!==36))fail('Invalid ready generation.');
 if((op==='patch'||op==='finish')&&(typeof input.session!=='string'||input.session.length!==36))fail('Invalid edit session.');
 const result=await serialize(user.id,async()=>{
  const authorize=async()=>{const current=await resolveUser(req);if(current?.id!==user.id)fail('The account session expired.',401);const p=world.players.get(user.id);if(p){p.capabilities=current.capabilities||[];p.gmAuthorized=p.capabilities.includes('gm:commands');}return current;};
  await authorize();if(op==='ready')return api.ready(user.id,input.token,input);
  return api[op](user.id,input.token,input,authorize);
 });json(res,result);return true;
}
