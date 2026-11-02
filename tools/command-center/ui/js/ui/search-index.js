// Everything the search box can jump to directly: pages, tabs, settings and actions. route = page/tab, anchor = element id.
export const PAGES = [
  {id: 'home', label: 'Home', ico: 'home', title: 'Command Center', subtitle: 'Your world, players and what needs attention', tabs: []},
  {id: 'play', label: 'Play & Connect', ico: 'play', title: 'Play & Connect', subtitle: 'Sign in, open the game, host or join a world', tabs: [['play', 'Play'], ['join', 'Join'], ['host', 'Host'], ['bench', 'Test Bench']]},
  {id: 'server', label: 'Server', ico: 'server', title: 'Server', subtitle: 'Lifecycle, players, world settings and capacity', tabs: [['overview', 'Overview'], ['players', 'Players & accounts'], ['world', 'World settings'], ['capacity', 'Capacity']]},
  {id: 'sql', label: 'SQL & Storage', ico: 'database', title: 'SQL & Storage', subtitle: 'Storage mode, live database explorer, monitor, queries and backups', tabs: [['overview', 'Storage & connections'], ['explorer', 'Explorer'], ['monitor', 'Monitor'], ['query', 'Query'], ['backup', 'Backup & migration']]},
  {id: 'content', label: 'Game & Content', ico: 'layers', title: 'Game & Content', subtitle: 'Launch options, Global data, tools and authored content', tabs: [['launch', 'Game window'], ['global', 'Global data'], ['tools', 'Tools'], ['overrides', 'Content']]},
  {id: 'updates', label: 'Updates & Diagnostics', ico: 'pulse', title: 'Updates & Diagnostics', subtitle: 'Updates, health, live logs, files and performance', tabs: [['updates', 'Updates'], ['health', 'Health'], ['logs', 'Live logs'], ['files', 'Code & files'], ['timeline', 'Timeline'], ['performance', 'Performance']]},
  {id: 'settings', label: 'Settings & About', ico: 'gear', title: 'Settings & About', subtitle: 'Appearance, launcher behaviour, advanced options and credits', tabs: [['appearance', 'Appearance'], ['launcher', 'Launcher'], ['advanced', 'Advanced'], ['about', 'About']]}];
/** "Play & Connect › Test Bench" for a route such as play/bench. */
export function routeLabel(route) { const [pid, tab] = String(route).split('/'); const p = PAGES.find(x => x.id === pid); if (!p) return route; const t = tab && p.tabs.find(x => x[0] === tab); return p.label + (t ? ' › ' + t[1] : ''); }
export const ENTRIES = [
  // Home
  ['Start world', 'launch play begin server first start one click', 'home', 'act-start'], ['GameGuard', 'nprotect game guard anticheat on off dx11 client launch', 'home', 'act-gameguard'], ['Local files or SQL Server', 'storage switch local sql server database tick option where saves', 'home', 'act-start'], ['Day / night mode', 'theme dark light day night sun moon', 'settings/appearance', 'theme-toggle'], ['Stop world', 'save shutdown stop', 'home', 'act-stop'], ['Players online', 'humans bots population count', 'home', 'card-pop'],
  ['Recent events', 'timeline history activity', 'home', 'card-events'], ['Problems', 'errors warnings attention', 'home', 'card-problems'], ['Quick settings', 'bots pk starter pack toggle', 'home', 'card-quick'],
  // Play
  ['Sign in and play', 'login account password dx11 fullscreen desktop browser launch', 'play/play', 'signin'], ['Create account', 'sign up register new account', 'play/play', 'signup'],
  ['Saved accounts', 'remember forget saved login token', 'play/play', 'saved'], ['Local admin auto sign-in', 'owner admin gm auto', 'play/play', 'owner'],
  ['Join a server', 'connect address remote friends lan', 'play/join', 'join-address'], ['Saved servers', 'remembered worlds list', 'play/join', 'saved-servers'], ['Public server list', 'directory listed servers browse', 'play/join', 'directory'],
  ['Open another client', 'extra second window multi client', 'play/join', 'extra'], ['Host friends', 'host invite open world gm account rates', 'play/host', 'host-setup'], ['Invite address', 'share invite copy address', 'play/host', 'invite'],
  ['Phone / tablet QR', 'android phone tablet qr code scan', 'play/host', 'qr'], ['Online relay', 'cloudflare tunnel https relay token hide ip', 'play/host', 'relay'], ['Public listing', 'list directory publish consent', 'play/host', 'listing'],
  ['Allow direct LAN connections', 'lan bind 0.0.0.0 local network', 'play/host', 'lan'], ['Hosting setup kits', 'vps vercel cloudflare guide kit', 'play/host', 'kits'], ['Test Bench', 'embedded client dev admin watcher sidebar tools', 'play/bench', 'bench'],
  // Server
  ['World lifecycle', 'start stop restart readiness', 'server/overview', 'lifecycle'], ['Server metrics', 'cpu memory latency uptime tick', 'server/overview', 'metrics'],
  ['Player accounts and Admin / GM / Dev', 'grant revoke gm admin dev staff role accounts', 'server/players', 'accounts'], ['Character roster', 'characters list level class', 'server/players', 'roster'],
  ['Server name', 'name world display', 'server/world', 'set-name'], ['Starter pack', 'new characters starter kit', 'server/world', 'set-starter'], ['Player killing (PK)', 'pk ctrl attack pvp', 'server/world', 'set-pk'],
  ['Bots', 'npc players experimental population', 'server/world', 'set-bots'], ['Bot chat language', 'english spanish portuguese german french', 'server/world', 'set-lang'],
  ['Server capacity', 'max players memory upload bandwidth', 'server/capacity', 'cap'], ['Hosting configuration', 'port bind relay mode', 'server/overview', 'hosting-summary'],
  // SQL
  ['Storage mode', 'local files sql server json storage', 'sql/overview', 'storage-mode'], ['SQL instance', 'sqlexpress instance server host port', 'sql/overview', 'storage-instance'],
  ['Set up SQL world', 'create schema database setup check', 'sql/overview', 'sql-setup'], ['Connection profiles', 'sql connections windows auth password', 'sql/overview', 'profiles'],
  ['Database explorer', 'tables schema columns rows browse', 'sql/explorer', 'explorer'], ['SQL monitor', 'sessions blocking waits slow queries live', 'sql/monitor', 'monitor'],
  ['Query workspace', 'sql editor run select read only', 'sql/query', 'query'], ['Backups and restore', 'backup restore verify rehearsal', 'sql/backup', 'backup'], ['Migration preview', 'schema version migrate upgrade', 'sql/backup', 'migration'],
  // Content
  ['Game window options', 'windowed fullscreen resolution graphics uncapped fps', 'content/launch', 'launch-opts'], ['Global data', 'prepared generation source fingerprint', 'content/global', 'global'],
  ['Verify prepared data', 'integrity checksum sha256 repair', 'content/global', 'verify'], ['Compatibility report', 'global format compatible tables', 'content/global', 'compat'],
  ['Item Builder', 'items custom builder gm', 'content/tools', 'tools'], ['Map Builder', 'maps custom builder', 'content/tools', 'tools'], ['Content overrides', 'custom items maps models overlays precedence', 'content/overrides', 'overrides'], ['Content preview', 'maps classes list browse', 'content/overrides', 'preview'],
  // Updates & diagnostics
  ['Updates', 'update install release notes version', 'updates/updates', 'upd'], ['Health check', 'diagnostics health status checks', 'updates/health', 'health'], ['Live logs', 'log reader errors tail real time', 'updates/logs', 'logs'],
  ['Code and file finder', 'search code files binary hex viewer', 'updates/files', 'files'], ['Event timeline', 'timeline history events', 'updates/timeline', 'timeline'], ['Performance', 'cpu memory startup tab latency measurements', 'updates/performance', 'perf'],
  ['Support export', 'export zip redacted support bundle', 'updates/health', 'support'], ['Recovery and rollback', 'rollback restore recovery backup', 'updates/health', 'recovery'], ['Verify Main unchanged', 'installed game untouched snapshot', 'updates/health', 'main-check'],
  // Settings
  ['Theme', 'dark light appearance colors', 'settings/appearance', 'set-theme'], ['Interface scale', 'zoom size text bigger dpi', 'settings/appearance', 'set-scale'], ['Reduce motion', 'animation motion accessibility', 'settings/appearance', 'set-reducedMotion'],
  ['Density', 'compact comfortable spacing', 'settings/appearance', 'set-density'], ['Startup page', 'open on start launcher', 'settings/launcher', 'set-startupPage'], ['Measure upload before start', 'speed test internet upload', 'settings/launcher', 'set-measureUploadBeforeStart'],
  ['Notifications', 'notify toast taskbar flash', 'settings/launcher', 'set-notifyWorld'], ['Advanced settings', 'poll refresh interval row limit timeout history', 'settings/advanced', 'adv'], ['Paths', 'folders locations logs sandbox', 'settings/advanced', 'paths'],
  ['About and version', 'version license credits', 'settings/about', 'about'], ['Contributors', 'credits shadow cyber magic ibrar', 'settings/about', 'contributors'], ['Documentation', 'docs readme guide sql hosting', 'settings/about', 'docs']].map(([title, keywords, route, anchor]) => ({title, keywords, route, anchor}));
