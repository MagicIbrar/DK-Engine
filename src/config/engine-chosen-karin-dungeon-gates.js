// User-selected positions for generated dungeon entrances near Karin in Ardeca.
// Original Global fallback/exit points remain in the source tables. These
// positions only move the synthetic entrance actors and their server entry check.
const KARIN_GATES = new Map([
  ['304,120', [325,112]], // Nunvice Shrine
  ['349,129', [328,109]], // Honeymoon Island / shared instance entrance
  ['393,91', [331,106]], // Phoenix Tower
  ['311,118', [334,104]], // seasonal event dungeons
  ['310,121', [337,102]], // anniversary theme park
  ['310,123', [342,100]], // monster summon altar
  ['255,255', [345,99]], // Agacion / Oread / Tritone
  ['167,108', [349,97]], // generated castle entrance (native siege NPCs stay put)
  ['68,70', [373,116]], // ????? / Office Dungeon
  ['216,88', [375,121]], // Deka Island / Blue Dragon Sanctuary
]);

export function dungeonGatePlacement(fallback, dungeonId) {
  if (!fallback) return fallback;
  // Sakura shares its native fallback with other seasonal events, but gets
  // its own requested entrance while that other group stays near Karin.
  if (Number(fallback.map) === 150 && String(dungeonId) === '564')
    return {...fallback, x:370, y:111, relocated:true};
  // Halloween Fortune shares the original seasonal fallback but has its own entrance.
  if (Number(fallback.map) === 150 && String(dungeonId) === '565')
    return {...fallback, x:376, y:125, relocated:true};
  if (Number(fallback.map) === 150 && String(dungeonId) === '567')
    return {...fallback, x:375, y:139, relocated:true};
  const at = Number(fallback.map) === 150 && KARIN_GATES.get(`${Number(fallback.x)},${Number(fallback.y)}`);
  return at ? {...fallback,x:at[0],y:at[1],relocated:true} : fallback;
}
