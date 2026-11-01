import net from 'node:net';
import os from 'node:os';

// Reserve each local IPv4 address while setup runs. On Windows a wildcard
// listener can coexist with an address-specific one, so reserve exact addresses.
export async function reserveStoppedWorld({port=7996,hosts}={}) {
  hosts??=['127.0.0.1',...Object.values(os.networkInterfaces()).flat().filter(row=>row?.family==='IPv4').map(row=>row.address)];
  const guards=[];
  const close=async()=>{await Promise.all(guards.map(guard=>new Promise(resolve=>guard.close(resolve))));};
  try {
    for(const host of new Set(hosts)){
      const guard=net.createServer(socket=>socket.destroy());
      await new Promise((resolve,reject)=>{
        guard.once('error',reject);
        guard.listen({host,port,exclusive:true},resolve);
      });
      guards.push(guard);port=guard.address().port;
    }
  } catch(error) {
    await close();
    if(error.code==='EADDRINUSE')throw new Error('Stop the dedicated world before setting up SQL. Its game port is already in use.');
    throw error;
  }
  return {port,close};
}
