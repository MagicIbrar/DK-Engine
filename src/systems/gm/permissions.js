// Server profiles keep their permission boundary even during a disconnect.
export function hasGMPanelPermission(game) {
  return !(game.save?.authority==='server'||game.network?.active) || !!game.accountPermissions?.capabilities?.includes('gm:panel');
}
export function requireGMPanelPermission(game) {
  if(!hasGMPanelPermission(game))throw new Error('GM permission is required.');
}
