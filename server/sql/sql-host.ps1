# Long-running SQL helper process for the Dekaron engine (Windows PowerShell 5.1 + built-in System.Data.SqlClient).
# Protocol: one request per stdin line = base64(UTF-8 JSON); one reply per stdout line = base64(UTF-8 JSON). ASCII-only on the wire.
#   request : { id, op: 'query'|'exec'|'ping'|'bye', db, sql, params: {name: value}, timeout }
#   reply   : { id, ok: true, sets: [[{col: value}, ...], ...], rows: <rowsAffected> }  |  { id, ok: false, error, number }
# Parameter values: string | number | boolean | null | {"$hex":"AB12"} (varbinary) | {"$big":"123"} (bigint) | {"$dt":"ISO"} (datetime).
# The instance comes from DEKARON_SQL_INSTANCE (default .\SQLEXPRESS); only Windows authentication is used. No secrets live here.
param([string]$Instance = $(if ($env:DEKARON_SQL_INSTANCE) { $env:DEKARON_SQL_INSTANCE } else { '.\SQLEXPRESS' }))
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Data
Add-Type -AssemblyName System.Web.Extensions
[Console]::InputEncoding = New-Object System.Text.UTF8Encoding($false)
$ser = New-Object System.Web.Script.Serialization.JavaScriptSerializer
$ser.MaxJsonLength = [int]::MaxValue
$ser.RecursionLimit = 200
$conns = @{}

function Get-Conn([string]$db) {
  if (-not $db) { $db = 'master' }
  if ($conns.ContainsKey($db) -and $conns[$db].State -eq 'Open') { return $conns[$db] }
  $c = New-Object System.Data.SqlClient.SqlConnection "Server=$Instance;Database=$db;Integrated Security=true;TrustServerCertificate=true;Application Name=dekaron-engine;Connect Timeout=15"
  $c.Open(); $conns[$db] = $c; return $c
}
function To-Plain($v) {
  if ($v -is [System.DBNull] -or $null -eq $v) { return $null }
  if ($v -is [byte[]]) { return ([System.BitConverter]::ToString($v) -replace '-', '') }
  if ($v -is [datetime]) { return $v.ToString('yyyy-MM-ddTHH:mm:ss.fff') }
  if ($v -is [int64]) { if ([math]::Abs($v) -le 9007199254740991) { return [double]$v } else { return [string]$v } }
  if ($v -is [decimal]) { return [double]$v }
  if ($v -is [guid]) { return $v.ToString() }
  if ($v -is [bool] -or $v -is [string] -or $v -is [int] -or $v -is [double] -or $v -is [int16] -or $v -is [byte] -or $v -is [single]) { return $v }
  return [string]$v
}
function Add-Params($cmd, $params) {
  if ($null -eq $params) { return }
  foreach ($k in @($params.Keys)) {
    $v = $params[$k]; $p = $cmd.Parameters.Add('@' + $k, [System.Data.SqlDbType]::Variant)
    if ($null -eq $v) { $p.SqlDbType = 'NVarChar'; $p.Value = [System.DBNull]::Value; continue }
    if ($v -is [System.Collections.IDictionary]) {
      if ($v.ContainsKey('$hex')) { $hex = [string]$v['$hex']; $b = New-Object byte[] ($hex.Length / 2); for ($i = 0; $i -lt $b.Length; $i++) { $b[$i] = [Convert]::ToByte($hex.Substring($i * 2, 2), 16) }; $p.SqlDbType = 'VarBinary'; $p.Size = -1; $p.Value = $b; continue }
      if ($v.ContainsKey('$big')) { $p.SqlDbType = 'BigInt'; $p.Value = [int64]::Parse([string]$v['$big']); continue }
      # Datetimes are exchanged as UTC wall-clock text; the server never applies a time zone.
      if ($v.ContainsKey('$dt'))  { $d = [datetime]::Parse([string]$v['$dt'], [Globalization.CultureInfo]::InvariantCulture, [Globalization.DateTimeStyles]::AssumeUniversal -bor [Globalization.DateTimeStyles]::AdjustToUniversal); $p.SqlDbType = 'DateTime'; $p.Value = [datetime]::SpecifyKind($d, [DateTimeKind]::Unspecified); continue }
      throw "Unsupported parameter object for @$k"
    }
    if ($v -is [string]) { $p.SqlDbType = 'NVarChar'; $p.Size = -1; $p.Value = $v; continue }
    if ($v -is [bool])   { $p.SqlDbType = 'Bit'; $p.Value = $v; continue }
    if ($v -is [int])    { $p.SqlDbType = 'BigInt'; $p.Value = [int64]$v; continue }
    if ($v -is [int64])  { $p.SqlDbType = 'BigInt'; $p.Value = $v; continue }
    if ($v -is [decimal] -or $v -is [double]) { $p.SqlDbType = 'Float'; $p.Value = [double]$v; continue }
    throw "Unsupported parameter type for @$k : $($v.GetType().Name)"
  }
}
# Explicit JSON writer: JavaScriptSerializer cannot walk PowerShell-wrapped (PSObject) collections, so only plain strings go
# through it (cast to [string] first) and everything else is emitted here.
function To-Json($v) {
  if ($null -eq $v) { return 'null' }
  if ($v -is [string]) { return $ser.Serialize([string]$v) }
  if ($v -is [bool]) { if ($v) { return 'true' } else { return 'false' } }
  if ($v -is [double] -or $v -is [single]) {
    if ([double]::IsNaN([double]$v) -or [double]::IsInfinity([double]$v)) { return 'null' }
    return ([double]$v).ToString('R', [Globalization.CultureInfo]::InvariantCulture)
  }
  if ($v -is [int] -or $v -is [int16] -or $v -is [byte] -or $v -is [int64]) { return ([int64]$v).ToString([Globalization.CultureInfo]::InvariantCulture) }
  if ($v -is [System.Collections.IDictionary]) {
    $parts = foreach ($k in $v.Keys) { ($ser.Serialize([string]$k)) + ':' + (To-Json $v[$k]) }
    return '{' + ($parts -join ',') + '}'
  }
  if ($v -is [System.Collections.IEnumerable]) {
    $parts = foreach ($x in $v) { To-Json $x }
    return '[' + ($parts -join ',') + ']'
  }
  return $ser.Serialize([string]$v)
}
function Reply($obj) {
  $json = To-Json $obj
  [Console]::Out.WriteLine([Convert]::ToBase64String([Text.Encoding]::UTF8.GetBytes($json)))
  [Console]::Out.Flush()
}

[Console]::Error.WriteLine("sql-host ready ($Instance)")
Reply @{ id = 0; ok = $true; ready = $true; pid = $PID }
while ($true) {
  $line = [Console]::In.ReadLine()
  if ($null -eq $line) { break }
  if ($line.Length -eq 0) { continue }
  $id = -1
  try {
    $req = $ser.DeserializeObject([Text.Encoding]::UTF8.GetString([Convert]::FromBase64String($line)))
    $id = $req['id']; $op = $req['op']
    if ($op -eq 'bye') { Reply @{ id = $id; ok = $true }; break }
    if ($op -eq 'ping') { Reply @{ id = $id; ok = $true; pong = $true }; continue }
    $conn = Get-Conn $req['db']
    $cmd = $conn.CreateCommand(); $cmd.CommandText = [string]$req['sql']
    $cmd.CommandTimeout = if ($req['timeout']) { [int]$req['timeout'] } else { 60 }
    Add-Params $cmd $req['params']
    $sets = New-Object System.Collections.ArrayList
    $rd = $cmd.ExecuteReader()
    try {
      do {
        $rows = New-Object System.Collections.ArrayList
        $names = @(for ($i = 0; $i -lt $rd.FieldCount; $i++) { $rd.GetName($i) })
        while ($rd.Read()) {
          $row = New-Object 'System.Collections.Generic.Dictionary[string,object]'
          for ($i = 0; $i -lt $names.Count; $i++) { $row[$names[$i]] = To-Plain ($rd.GetValue($i)) }
          [void]$rows.Add($row)
        }
        if ($names.Count -gt 0) { [void]$sets.Add($rows) }
      } while ($rd.NextResult())
      $affected = $rd.RecordsAffected
    } finally { $rd.Dispose() }
    Reply @{ id = $id; ok = $true; sets = $sets; rows = $affected }
  } catch {
    $e = $_.Exception; while ($e.InnerException) { $e = $e.InnerException }
    $num = 0; if ($e -is [System.Data.SqlClient.SqlException]) { $num = $e.Number }
    Reply @{ id = $id; ok = $false; error = $e.Message; number = $num }
    # a broken connection must not poison later requests
    foreach ($k in @($conns.Keys)) { if ($conns[$k].State -ne 'Open') { $conns.Remove($k) } }
  }
}
foreach ($c in $conns.Values) { try { $c.Dispose() } catch {} }
