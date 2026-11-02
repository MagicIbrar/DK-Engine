// Lane 57 follow-up 3: Global has no Phantom Castle entrance (no NPC job, warp, teleport or location targets
// map 653), so the ENGINE-CHOSEN Checkpoint 5913 "Enter Phantom Castle" service was removed. Checkpoint 5913
// keeps only its Global jobs (teleport 133 to Zuto's Battlefield, quest 8073). The installer is kept so
// events.js keeps its import; it registers no NPC role and sends nothing.
export function installSharedPhantomCastle() {
 return {open:()=>false};
}
