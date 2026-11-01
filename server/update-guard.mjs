import fs from 'node:fs';
import path from 'node:path';
export function assertNoInstallUpdate(engine){
 if(fs.existsSync(path.resolve(engine)+'.update-lock'))throw Error('An update is in progress. Wait for Client to finish before starting the world.');
}
