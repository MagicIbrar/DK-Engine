import { createHash } from 'node:crypto';

// Character lookup keys do not expose account names, sessions or storage paths.
export const characterRef = (account, character) => createHash('sha256').update(JSON.stringify([account, character])).digest('hex');
