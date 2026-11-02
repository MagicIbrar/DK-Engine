// AUTO-REPORT host route for the pcpop row 240:12 "Report" (lane 62, docs/global-parity-420/PLAYER-CARD-PARITY.md).
// Source: Global 64-bit decompile, PCDialog AutoReport command: after the 80:46 / 81:46 confirm box the client sends
// a 0x18-byte message (type 0x052B0005) carrying only the reporter id and the target id. No reply string is evidenced,
// so the host answers with no chat line: it validates the pair and records it in the host log.
// Wiring (done): server/world/core.mjs imports AUTO_REPORT_SCHEMAS / autoReportCommand, spreads the schemas and dispatches
//   input.type 'autoreport' to autoReportCommand.
import {WorldError} from './core.mjs';
export const AUTO_REPORT_SCHEMAS={autoreport:['token','type','targetId']};
/** Validate one report; returns the record written to the host log. */
export function autoReportCommand(world,p,input,log=console){
  const target=[...world.players.values()].find(q=>q.id===input?.targetId&&!q.leaving);
  if(!target)throw new WorldError(404,'That character is not connected.');
  if(target===p)throw new WorldError(400,'Invalid report target.');
  const record={reporterId:p.id,reporter:p.profile?.name||'',targetId:target.id,target:target.profile?.name||'',map:p.map,at:new Date(world.now?.()??Date.now()).toISOString()};
  log?.info?.('[autoreport]',JSON.stringify(record));
  return {ok:true};
}
