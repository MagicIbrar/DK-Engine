// Compatibility recovery from an exact definition shipped in the original pack.
// This does not establish whether the native client loads backup tables.
export const ESCANA_BACKUP_SOURCE = 'property/effect/effectdata.01.bak';
export const ESCANA_TEXTURE = 'texture/effect/skill/aldebaran/eff_aldebaran_jin_02.dds';

export function recoverEscanaUnit(name, file, sceneKey, readUnits, has) {
  if (file !== '01' || !['100:10030', '100:10079'].includes(sceneKey) ||
      String(name).toLowerCase() !== 'dc_escana_jin_01' ||
      !has(ESCANA_BACKUP_SOURCE) || !has(ESCANA_TEXTURE)) return null;
  const matches = readUnits().filter(u => u.file === '01.bak' &&
    String(u.name).toLowerCase() === 'dc_escana_jin_01');
  if (matches.length !== 1) return null;
  const unit = matches[0];
  const texture = String(unit.fields?.texturefile ?? '').replaceAll('\\', '/').toLowerCase();
  if (unit.unittype !== 'decal' || texture !== ESCANA_TEXTURE.slice('texture/'.length) ||
      String(unit.fields?.texturepack ?? '').trim()) return null;
  return unit;
}
