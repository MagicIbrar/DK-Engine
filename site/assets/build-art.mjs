// Website presentation uses the generated client-assets illustration and CSS.
// Keep the preparation interface without reading or extracting game artwork.
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
const engine=fileURLToPath(new URL('../../',import.meta.url));
const out=process.env.DEKARON_SITE_ASSETS||path.join(engine,'site/assets');
fs.mkdirSync(out,{recursive:true});
fs.writeFileSync(path.join(out,'website-art.json'),JSON.stringify({version:1,source:'generated-and-css',hero:'/client-assets/launcher-background-v1.png'},null,2));
console.log('Website presentation ready: generated illustration and CSS; no game artwork extracted.');
