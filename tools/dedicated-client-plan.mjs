// Read-only startup plan for the already prepared dedicated copy. Never an install/delete plan.
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {clientSource} from '../server/client-source.mjs';
import {clientStatus} from '../server/client-identity.mjs';
const engine=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const source=clientSource(engine);
console.log(JSON.stringify({root:engine,engine,remove:[],clientName:'Client.exe',serverUrl:'http://localhost:7996/',...clientStatus(engine,source.version)}));
