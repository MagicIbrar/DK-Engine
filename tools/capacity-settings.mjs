// Read / save the owner's server capacity settings while no server is running (dashboard > Settings > Server
// capacity; a running server takes them through /api/launcher/capacity and applies the player cap / upload at once).
// usage: node tools/capacity-settings.mjs --read            -> {settings, memoryRange, live:null}
//        node tools/capacity-settings.mjs --write '<json>'  -> {settings, memoryRange, live:null} (validated, atomic save)
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {capacityFile, readCapacitySettings, writeCapacitySettings, memoryRange} from '../server/capacity-settings.mjs';

const engine = path.resolve(fileURLToPath(new URL('../', import.meta.url))), file = capacityFile(engine);
try {
  let settings;
  if (process.argv[2] === '--read' && process.argv.length === 3) settings = await readCapacitySettings(file, {env: {}});
  else if (process.argv[2] === '--write' && process.argv.length === 4) {
    const input = JSON.parse(process.argv[3]);
    settings = await writeCapacitySettings(file, {...await readCapacitySettings(file, {env: {}}), ...input});
  } else throw new Error('Use --read or --write <json>.');
  console.log(JSON.stringify({settings, memoryRange: memoryRange(), live: null}));
} catch (error) {
  console.log(JSON.stringify({error: error.message}));
  process.exit(1);
}
