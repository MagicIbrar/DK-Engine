import fs from 'node:fs/promises';
import { execFile } from 'node:child_process';
import { promisify } from 'node:util';
const run = promisify(execFile);
export function installationOwnerAllowed(ownerSid, currentSid) {
  // Administrators ownership is a Windows installer convention, not a person.
  // For that case the running server's sole-SID private file defines its owner.
  return ownerSid === currentSid || ownerSid === 'S-1-5-32-544' && typeof currentSid==='string' && currentSid.startsWith('S-1-');
}

// Forwarding headers are never evidence of local ownership, even on loopback.
export function ownerLocalRequest(req) {
  return !req.relay && ['127.0.0.1','::1','::ffff:127.0.0.1'].includes(req.socket.remoteAddress)
    && !Object.keys(req.headers).some(k => /^(forwarded|x-forwarded-|x-real-ip|via)/i.test(k));
}

// Create the empty file first, remove inherited access, then write the token.
// The directory owner is the installation owner; another Windows user cannot opt in.
export async function protectLauncherFile(file, engine) {
  if (process.platform !== 'win32') {
    await fs.chmod(file, 0o600);
    return (await fs.stat(engine)).uid === process.getuid();
  }
  const quote = s => "'" + s.replaceAll("'", "''") + "'";
  const script = `$ErrorActionPreference='Stop';$identity=[Security.Principal.WindowsIdentity]::GetCurrent();$sid=$identity.User;`+
    `$owner=[IO.Directory]::GetAccessControl(${quote(engine)}).GetOwner([Security.Principal.SecurityIdentifier]);`+
    `$acl=New-Object Security.AccessControl.FileSecurity;$acl.SetOwner($sid);$acl.SetAccessRuleProtection($true,$false);`+
    `$acl.AddAccessRule((New-Object Security.AccessControl.FileSystemAccessRule($sid,'FullControl','Allow')));`+
    `[IO.File]::SetAccessControl(${quote(file)},$acl);[pscustomobject]@{owner=$owner.Value;current=$sid.Value}|ConvertTo-Json -Compress`;
  const { stdout } = await run('powershell.exe', ['-NoProfile','-NonInteractive','-EncodedCommand',Buffer.from(script,'utf16le').toString('base64')], { windowsHide:true });
  const identity=JSON.parse(stdout.trim());
  return installationOwnerAllowed(identity.owner,identity.current);
}
