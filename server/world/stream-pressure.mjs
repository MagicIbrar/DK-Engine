// ENGINE-CHOSEN transport limits. Do not generate another snapshot while a
// client's existing output is stalled; allow brief congestion to drain.
export const STREAM_PRESSURE=Object.freeze({highBytes:1024*1024,lowBytes:256*1024,timeoutMs:30000});
export function streamPressure(stream,queuedBytes,now){
 if(stream.pressureSince==null&&queuedBytes<=STREAM_PRESSURE.highBytes)return 'write';
 stream.pressureSince??=now;
 if(queuedBytes<=STREAM_PRESSURE.lowBytes){stream.pressureSince=null;return 'write';}
 return now-stream.pressureSince>=STREAM_PRESSURE.timeoutMs?'close':'wait';
}
