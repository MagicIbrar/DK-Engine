// Dekaron.exe - the native DX11 game client window.
//
// A Windows Forms window that hosts the engine in Microsoft's installed WebView2 runtime (the Edge engine shipped with
// Windows; WebGL on ANGLE / Direct3D 11). No browser frame, no address bar, its own icon and title, its own persistent
// profile per account (keeps the GPU shader cache between sessions, so later loads compile less).
//
// Login gate: it only opens a launcher sign-in ticket URL (http(s)://<server>/launch#ticket=<64 hex>, issued by the server
// after a real sign-in in Client.exe, one use, 45 s). Double-click opens the host launcher when installed beside it,
// or asks for the server address when this EXE was copied alone to a player's PC.
//
// The WebView2 SDK is not bundled, so the runtime is reached directly: the
// installed runtime's EmbeddedBrowserWebView.dll export CreateWebViewEnvironmentWithOptionsInternal - the same entry point the
// SDK's WebView2Loader calls and the one the open-source webview library (MIT) uses - plus the documented COM interfaces of
// WebView2.h (ICoreWebView2Environment / Controller / CoreWebView2 / Settings; vtable order and IIDs from WebView2.h).
// ENGINE-CHOSEN: window behaviour (1280 x 720 game area by default; Options > resolution sizes the window and it is remembered for the next start; F11 / game
// fullscreen; title polling for "Return to Client"). Everywhere Windows names it, it is "Dekaron.exe": the window title,
// the file description (Task Manager) and the game's audio sessions in the volume mixer (otherwise the volume
// control names the WebView2 runtime). The audio comes from the WebView2 runtime's own child
// process, so Dekaron.exe names those sessions itself (Core Audio IAudioSessionControl::SetDisplayName / SetIconPath).
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Net;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using Microsoft.Win32;

[assembly: AssemblyTitle("DK Client")]
[assembly: AssemblyProduct("DK Engine")]
[assembly: AssemblyDescription("DK Client - native DX11 game window")]
// no AssemblyVersion / default manifest: their "x.x.x.x" version text reads as an IPv4 address to the release privacy audit
[assembly: AssemblyFileVersion("4.0.1")]

namespace DekaronNative {
  // User-local artwork only: inspect icon resources, never start or redistribute Global executables.
  internal static class UserGlobalIcon {
    static bool UnlinkedLocal(string value) {
      try {
        string full=Path.GetFullPath(value);
        if(!Path.IsPathRooted(full)||full.StartsWith(@"\\"))return false;
        for(string current=full;!String.IsNullOrEmpty(current);current=Path.GetDirectoryName(current))
          if((File.Exists(current)||Directory.Exists(current))&&(File.GetAttributes(current)&FileAttributes.ReparsePoint)!=0)return false;
        return true;
      } catch { return false; }
    }
    static string InGame(string folder) {
      try {
        if(!UnlinkedLocal(folder))return null;
        string game=Path.GetFullPath(folder);
        if(File.Exists(Path.Combine(game,"pack.hdr"))||File.Exists(Path.Combine(game,"share","maplist.csv")))game=Path.GetDirectoryName(game);
        if(!File.Exists(Path.Combine(game,"data","pack.hdr"))&&!File.Exists(Path.Combine(game,"data","share","maplist.csv")))return null;
        foreach(string name in new[]{"dekaron64.exe","dekaron.exe"}){
          string exe=Path.Combine(game,"bin",name);
          if(File.Exists(exe)&&UnlinkedLocal(exe))return exe;
        }
      } catch { }
      return null;
    }
    internal static string FindExecutable(string engine,string configured) {
      if(!String.IsNullOrWhiteSpace(configured)){
        try {
          string value=Path.GetFullPath(configured.Trim());
          if(File.Exists(value)){
            string name=Path.GetFileName(value);
            if((name.Equals("dekaron.exe",StringComparison.OrdinalIgnoreCase)||name.Equals("dekaron64.exe",StringComparison.OrdinalIgnoreCase))&&UnlinkedLocal(value)&&InGame(Path.GetDirectoryName(Path.GetDirectoryName(value)))!=null)return value;
          }else{string found=InGame(value)??InGame(Path.Combine(value,"Dekaron"));if(found!=null)return found;}
        } catch { }
        return null; // Invalid explicit selection must not silently pick a different installation.
      }
      try {
        foreach(string parent in new[]{Path.GetFullPath(engine),Path.GetDirectoryName(Path.GetFullPath(engine))}){
          if(String.IsNullOrEmpty(parent)||!UnlinkedLocal(parent))continue;
          string found=InGame(parent);if(found!=null)return found;
          var children=Directory.GetDirectories(parent);Array.Sort(children,StringComparer.OrdinalIgnoreCase);int checkedFolders=0;
          foreach(string child in children){
            string name=Path.GetFileName(child);
            if(name.IndexOf("global",StringComparison.OrdinalIgnoreCase)<0&&!name.Equals("Dekaron",StringComparison.OrdinalIgnoreCase))continue;
            if(++checkedFolders>64)break;
            found=InGame(child)??InGame(Path.Combine(child,"Dekaron"));if(found!=null)return found;
          }
        }
      } catch { }
      return null;
    }
    internal static Icon Load(string engine,string configured) {
      string exe=FindExecutable(engine,configured);if(exe==null)return null;
      try { return Icon.ExtractAssociatedIcon(exe); } catch { return null; }
    }
  }

  // Windows Shell fullscreen recognition; never changes global taskbar settings or topmost state.
  // https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist2-markfullscreenwindow
  static class FullscreenShell {
    [ComImport, Guid("602D4995-B13A-429B-A66E-1935E44F4317"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    interface ITaskbarList2 {
      [PreserveSig] int HrInit();
      [PreserveSig] int AddTab(IntPtr hwnd);
      [PreserveSig] int DeleteTab(IntPtr hwnd);
      [PreserveSig] int ActivateTab(IntPtr hwnd);
      [PreserveSig] int SetActiveAlt(IntPtr hwnd);
      [PreserveSig] int MarkFullscreenWindow(IntPtr hwnd, [MarshalAs(UnmanagedType.Bool)] bool fullscreen);
    }
    internal static void Mark(IntPtr hwnd, bool fullscreen) {
      if (hwnd == IntPtr.Zero) return;
      object shell = null;
      try {
        shell = Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid("56FDF344-FD6D-11D0-958A-006097C9A090")));
        var taskbar = (ITaskbarList2)shell;
        if (taskbar.HrInit() >= 0) taskbar.MarkFullscreenWindow(hwnd, fullscreen);
      } catch { /* Shell unavailable: retain normal borderless/windowed behavior. */ }
      finally { if (shell != null && Marshal.IsComObject(shell)) Marshal.ReleaseComObject(shell); }
    }
  }

  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int left, top, right, bottom; }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("4E8A3389-C9D8-4BD2-B6B5-124FEE6CC14D")]
  public interface ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler { void Invoke(int errorCode, [MarshalAs(UnmanagedType.Interface)] ICoreWebView2Environment environment); }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("6C4819F3-C9B7-4260-8127-C9F5BDE7F68C")]
  public interface ICoreWebView2CreateCoreWebView2ControllerCompletedHandler { void Invoke(int errorCode, [MarshalAs(UnmanagedType.Interface)] ICoreWebView2Controller controller); }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("B96D755E-0319-4E92-A296-23436F46A1FC")]
  public interface ICoreWebView2Environment {
    void CreateCoreWebView2Controller(IntPtr parentWindow, [MarshalAs(UnmanagedType.Interface)] ICoreWebView2CreateCoreWebView2ControllerCompletedHandler handler);
  }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("4D00C0D1-9434-4EB6-8078-8697A560334F")]
  public interface ICoreWebView2Controller {
    void get_IsVisible(out int value);
    void put_IsVisible(int value);
    void get_Bounds(out RECT value);
    void put_Bounds(RECT value);
    void get_ZoomFactor(out double value);
    void put_ZoomFactor(double value);
    void add_ZoomFactorChanged(IntPtr handler, out long token);
    void remove_ZoomFactorChanged(long token);
    void SetBoundsAndZoomFactor(RECT bounds, double zoom);
    void MoveFocus(int reason);
    void add_MoveFocusRequested(IntPtr handler, out long token);
    void remove_MoveFocusRequested(long token);
    void add_GotFocus(IntPtr handler, out long token);
    void remove_GotFocus(long token);
    void add_LostFocus(IntPtr handler, out long token);
    void remove_LostFocus(long token);
    void add_AcceleratorKeyPressed(IntPtr handler, out long token);
    void remove_AcceleratorKeyPressed(long token);
    void get_ParentWindow(out IntPtr value);
    void put_ParentWindow(IntPtr value);
    void NotifyParentWindowPositionChanged();
    void Close();
    void get_CoreWebView2([MarshalAs(UnmanagedType.Interface)] out ICoreWebView2 value);
  }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("76ECEACB-0462-4D94-AC83-423A6793775E")]
  public interface ICoreWebView2 {
    void get_Settings([MarshalAs(UnmanagedType.Interface)] out ICoreWebView2Settings value);   // 3
    void get_Source([MarshalAs(UnmanagedType.LPWStr)] out string value);                        // 4
    void Navigate([MarshalAs(UnmanagedType.LPWStr)] string uri);                                // 5
    void _06(); void _07(); void _08(); void _09(); void _10(); void _11(); void _12(); void _13(); void _14();
    void _15(); void _16(); void _17(); void _18(); void _19(); void _20(); void _21(); void _22(); void _23();
    void _24(); void _25(); void _26(); void _27(); void _28(); void ExecuteScript([MarshalAs(UnmanagedType.LPWStr)] string javaScript, [MarshalAs(UnmanagedType.Interface)] ICoreWebView2ExecuteScriptCompletedHandler handler); void _30(); void _31(); void _32();
    void _33(); void _34(); void _35(); void _36();
    void get_BrowserProcessId(out uint value);                                                  // 37
    void _38(); void _39(); void _40(); void _41(); void _42(); void _43(); void _44(); void _45(); void _46(); void _47();
    void get_DocumentTitle([MarshalAs(UnmanagedType.LPWStr)] out string value);                 // 48
    void _49(); void _50(); void _51(); void _52(); void _53();
    void get_ContainsFullScreenElement(out int value);                                          // 54
  }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("E562E4F0-D7FA-43AC-8D71-C05150499F00")]
  public interface ICoreWebView2Settings {
    void get_IsScriptEnabled(out int v); void put_IsScriptEnabled(int v);
    void get_IsWebMessageEnabled(out int v); void put_IsWebMessageEnabled(int v);
    void get_AreDefaultScriptDialogsEnabled(out int v); void put_AreDefaultScriptDialogsEnabled(int v);
    void get_IsStatusBarEnabled(out int v); void put_IsStatusBarEnabled(int v);
    void get_AreDevToolsEnabled(out int v); void put_AreDevToolsEnabled(int v);
    void get_AreDefaultContextMenusEnabled(out int v); void put_AreDefaultContextMenusEnabled(int v);
    void get_AreHostObjectsAllowed(out int v); void put_AreHostObjectsAllowed(int v);
    void get_IsZoomControlEnabled(out int v); void put_IsZoomControlEnabled(int v);
  }

  // ---- Core Audio (mmdeviceapi.h / audiopolicy.h; IIDs and vtable order from those headers): the volume mixer name
  [ComImport, Guid("BCDE0395-E52F-467C-8E3D-C4579291692E")] class MMDeviceEnumeratorCo { }
  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("A95664D2-9614-4F35-A746-DE8DB63617E6")]
  interface IMMDeviceEnumerator { void EnumAudioEndpoints(int dataFlow, int stateMask, out IMMDeviceCollection devices); }
  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("0BD7A1BE-7A1A-44DB-8397-CC5392387B5E")]
  interface IMMDeviceCollection { void GetCount(out uint count); void Item(uint index, out IMMDevice device); }
  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("D666063F-1587-4E43-81F1-B948E807363F")]
  interface IMMDevice { void Activate(ref Guid iid, int clsCtx, IntPtr activationParams, [MarshalAs(UnmanagedType.IUnknown)] out object iface); }
  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("77AA99A0-1BD6-484F-8BC7-2C654C9A9B6F")]
  interface IAudioSessionManager2 { void _GetAudioSessionControl(); void _GetSimpleAudioVolume(); void GetSessionEnumerator(out IAudioSessionEnumerator sessions); }
  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("E2F5BB11-0570-40CA-ACDD-3AA01277DEE8")]
  interface IAudioSessionEnumerator { void GetCount(out int count); void GetSession(int index, out IAudioSessionControl2 session); }
  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("BFB7FF88-7239-4FC9-8FA2-07C950BE9C6D")]
  interface IAudioSessionControl2 {
    void GetState(out int state);
    void GetDisplayName([MarshalAs(UnmanagedType.LPWStr)] out string name);
    void SetDisplayName([MarshalAs(UnmanagedType.LPWStr)] string name, [In] ref Guid eventContext);
    void GetIconPath([MarshalAs(UnmanagedType.LPWStr)] out string path);
    void SetIconPath([MarshalAs(UnmanagedType.LPWStr)] string path, [In] ref Guid eventContext);
    void GetGroupingParam(out Guid grouping);
    void SetGroupingParam([In] ref Guid grouping, [In] ref Guid eventContext);
    void RegisterAudioSessionNotification(IntPtr client);
    void UnregisterAudioSessionNotification(IntPtr client);
    void GetSessionIdentifier([MarshalAs(UnmanagedType.LPWStr)] out string id);
    void GetSessionInstanceIdentifier([MarshalAs(UnmanagedType.LPWStr)] out string id);
    void GetProcessId(out uint pid);
  }

  static class AudioNames {
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
    struct PROCESSENTRY32 { public uint dwSize, cntUsage, th32ProcessID; public IntPtr th32DefaultHeapID; public uint th32ModuleID, cntThreads, th32ParentProcessID; public int pcPriClassBase; public uint dwFlags; [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 260)] public string szExeFile; }
    [DllImport("kernel32", SetLastError = true)] static extern IntPtr CreateToolhelp32Snapshot(uint flags, uint pid);
    [DllImport("kernel32", CharSet = CharSet.Unicode)] static extern bool Process32FirstW(IntPtr snapshot, ref PROCESSENTRY32 entry);
    [DllImport("kernel32", CharSet = CharSet.Unicode)] static extern bool Process32NextW(IntPtr snapshot, ref PROCESSENTRY32 entry);
    [DllImport("kernel32")] static extern bool CloseHandle(IntPtr handle);

    /** This process and every process started under it (the WebView2 browser, GPU, renderer and audio processes). */
    public static HashSet<uint> Family(uint root) {
      var parent = new Dictionary<uint, uint>(); var snap = CreateToolhelp32Snapshot(2, 0);
      if (snap != IntPtr.Zero && snap != new IntPtr(-1)) {
        try { var e = new PROCESSENTRY32 { dwSize = (uint)Marshal.SizeOf(typeof(PROCESSENTRY32)) }; if (Process32FirstW(snap, ref e)) do { parent[e.th32ProcessID] = e.th32ParentProcessID; } while (Process32NextW(snap, ref e)); }
        finally { CloseHandle(snap); }
      }
      var family = new HashSet<uint> { root }; bool grew = true;
      while (grew) { grew = false; foreach (var kv in parent) if (!family.Contains(kv.Key) && family.Contains(kv.Value) && kv.Key != kv.Value) { family.Add(kv.Key); grew = true; } }
      return family;
    }

    /** Names this process family's audio sessions on every active output device. Returns how many now carry the name. */
    public static int Apply(HashSet<uint> family, string name, string icon, Action<string> log) {
      int named = 0;
      var devices = (IMMDeviceEnumerator)new MMDeviceEnumeratorCo(); IMMDeviceCollection list; devices.EnumAudioEndpoints(0, 1, out list);
      uint count; list.GetCount(out count);
      for (uint i = 0; i < count; i++) {
        try {
          IMMDevice device; list.Item(i, out device); var iid = typeof(IAudioSessionManager2).GUID; object o; device.Activate(ref iid, 23, IntPtr.Zero, out o);
          IAudioSessionEnumerator sessions; ((IAudioSessionManager2)o).GetSessionEnumerator(out sessions); int n; sessions.GetCount(out n);
          for (int k = 0; k < n; k++) {
            try {
              IAudioSessionControl2 s; sessions.GetSession(k, out s); uint pid; s.GetProcessId(out pid);
              if (!family.Contains(pid)) continue;
              string shown, shownIcon; s.GetDisplayName(out shown); s.GetIconPath(out shownIcon);
              var context = Guid.Empty;
              if (shown != name) s.SetDisplayName(name, ref context);
              if (!String.Equals(shownIcon, icon, StringComparison.OrdinalIgnoreCase)) s.SetIconPath(icon, ref context);
              if (shown != name || !String.Equals(shownIcon, icon, StringComparison.OrdinalIgnoreCase)) {
                s.GetDisplayName(out shown);s.GetIconPath(out shownIcon);
                if (log != null) log("audio session of process " + pid + " named \"" + shown + "\" with icon " + (String.Equals(shownIcon, icon, StringComparison.OrdinalIgnoreCase) ? "confirmed" : "unconfirmed"));
              }
              if (shown == name) named++;
            } catch (Exception error) { if (log != null) log("audio session not named: " + error.Message); }
          }
        } catch { }
      }
      return named;
    }
  }

  [UnmanagedFunctionPointer(CallingConvention.StdCall)]
  delegate int CreateEnvironmentInternal([MarshalAs(UnmanagedType.U1)] bool checkRunningInstance, int runtimeType, [MarshalAs(UnmanagedType.LPWStr)] string userDataDir, IntPtr environmentOptions, [MarshalAs(UnmanagedType.Interface)] ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler handler);

  static class Native {
    [DllImport("kernel32", CharSet = CharSet.Unicode, SetLastError = true)] public static extern IntPtr LoadLibraryW(string path);
    [DllImport("kernel32", CharSet = CharSet.Ansi, SetLastError = true)] public static extern IntPtr GetProcAddress(IntPtr module, string name);
    [DllImport("kernel32", CharSet = CharSet.Unicode)] public static extern bool SetDllDirectoryW(string path);
  }

  [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("49511172-CC67-4BCA-9923-137112F4C4CC")]
  public interface ICoreWebView2ExecuteScriptCompletedHandler { void Invoke(int errorCode, [MarshalAs(UnmanagedType.LPWStr)] string resultObjectAsJson); }
  [ComVisible(true)]
  public sealed class ScriptDone : ICoreWebView2ExecuteScriptCompletedHandler {
    readonly Action<string> done; public ScriptDone(Action<string> d) { done = d; }
    public void Invoke(int errorCode, string resultObjectAsJson) { done(errorCode < 0 ? null : resultObjectAsJson); }
  }
  [ComVisible(true)]
  public sealed class EnvironmentDone : ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler {
    readonly Action<int, ICoreWebView2Environment> done; public EnvironmentDone(Action<int, ICoreWebView2Environment> d) { done = d; }
    public void Invoke(int errorCode, ICoreWebView2Environment environment) { done(errorCode, environment); }
  }
  [ComVisible(true)]
  public sealed class ControllerDone : ICoreWebView2CreateCoreWebView2ControllerCompletedHandler {
    readonly Action<int, ICoreWebView2Controller> done; public ControllerDone(Action<int, ICoreWebView2Controller> d) { done = d; }
    public void Invoke(int errorCode, ICoreWebView2Controller controller) { done(errorCode, controller); }
  }

  // Opaque, double-buffered surface: scaling occurs only when its size/art changes.
  public sealed class NativeLoadingPanel : Panel {
    Image artwork; Bitmap backdrop;
    public NativeLoadingPanel(){SetStyle(ControlStyles.UserPaint|ControlStyles.AllPaintingInWmPaint|ControlStyles.OptimizedDoubleBuffer|ControlStyles.Opaque,true);}
    public Rectangle ProgressBounds {get{return new Rectangle(Math.Max(0,(Width-640)/2),Math.Max(0,Height-78),Math.Min(640,Width),56);}}
    public void SetArtwork(Image value){artwork=value;RebuildBackdrop();}
    void RebuildBackdrop(){if(backdrop!=null){backdrop.Dispose();backdrop=null;}if(artwork!=null&&Width>0&&Height>0){backdrop=new Bitmap(Width,Height);using(var g=Graphics.FromImage(backdrop)){g.DrawImage(artwork,new Rectangle(0,0,Width,Height));}}Invalidate();}
    protected override void OnResize(EventArgs e){base.OnResize(e);RebuildBackdrop();}
    protected override void OnPaintBackground(PaintEventArgs e){}
    protected override void OnPaint(PaintEventArgs e){if(backdrop!=null)e.Graphics.DrawImageUnscaled(backdrop,0,0);else e.Graphics.Clear(Color.Black);base.OnPaint(e);}
    protected override void Dispose(bool disposing){if(disposing&&backdrop!=null){backdrop.Dispose();backdrop=null;}base.Dispose(disposing);}
  }

  public static class NativeStartupProgress {
    // Verification costs both opening files and reading bytes. Tiny native
    // records count too; these are completed work units, not an ETA.
    public static bool TryVerification(string command, out double percent) {
      percent=0;if(command==null||!command.StartsWith("VERIFY ",StringComparison.Ordinal))return false;
      var parts=command.Substring(7).Split(' ');long files,totalFiles,bytes,totalBytes;
      if(parts.Length!=4||!long.TryParse(parts[0],out files)||!long.TryParse(parts[1],out totalFiles)||!long.TryParse(parts[2],out bytes)||!long.TryParse(parts[3],out totalBytes)||files<0||totalFiles<=0||files>totalFiles||bytes<0||totalBytes<=0||bytes>totalBytes)return false;
      percent=10+32.5*((double)files/totalFiles+(double)bytes/totalBytes);return true;
    }
    public static double Advance(double current,double target,double elapsedMs) {
      target=Math.Max(0,Math.Min(100,target));current=Math.Max(0,Math.Min(target,current));
      return Math.Min(target,current+Math.Max(0,Math.Min(64,elapsedMs))*.05);
    }
  }

  public sealed class GameWindow : Form {
    string url; readonly string profile;
    readonly Screen launchScreen=Screen.FromPoint(Cursor.Position); readonly int startupMode;
    readonly string preloadImage, preloadOrigin; Image loadingArt; double loadingPercent, displayedPercent; readonly Timer loadingPulse=new Timer(); bool preloadLaunched, frontendReady, preloadFailed; ScriptDone preloadHandler; bool preloadAsking;
    readonly NativeLoadingPanel loadingPanel = new NativeLoadingPanel();
    readonly object progressLock=new object(); string pendingProgress; bool pulseScheduled, hasByteProgress, hasInventoryProgress; long inventoryDone, inventoryTotal;
    readonly Stopwatch loadingClock=Stopwatch.StartNew(); double lastLoadingPulse;
    readonly bool standalone;
    bool returningToJoin;
    ICoreWebView2Controller controller; ICoreWebView2 webview;
    EnvironmentDone envHandler; ControllerDone controllerHandler;   // kept alive while the runtime holds them
    readonly Timer poll = new Timer(); readonly string sizeFile; ScriptDone sizeHandler; string sizeSeen = ""; bool sizeAsking;
    ScriptDone modeHandler, syncHandler; bool modeAsking; int lastModeV, lastToggles; bool pageFull;
    bool fullscreen, savedFull; Size windowedClient; FormWindowState savedState; Rectangle savedBounds;
    readonly Label status = new Label();

    public GameWindow(string url, string profile, bool standalone = false, string preloadImage = null, string preloadOrigin = null, int startupMode = 0) {
      this.url = url; this.profile = profile; this.standalone = standalone; this.preloadImage=preloadImage; this.preloadOrigin=preloadOrigin; this.startupMode=startupMode;
      Text = "DK Client"; BackColor = Color.Black; StartPosition = FormStartPosition.CenterScreen;
      // the game area is 1280 x 720 by default, or the resolution last applied in Options (saved beside the profile), as a
      // bordered window; full screen only when the player left it full screen (F11 / Options window mode), 2.2.1
      sizeFile = profile + ".window";
      var saved = SavedState(sizeFile, out savedFull);
      if(startupMode!=0){savedFull=startupMode==2;saved=new Size(1280,720);}
      MinimumSize = new Size(800, 500); KeyPreview = true;
      // 2.2.0 saved a desktop-sized "windowed" area (1920x1080 on a 1080p screen): the window filled the screen on every start
      if (!Fits(saved.Width, saved.Height)) { Log("saved window size " + saved.Width + "x" + saved.Height + " does not fit the screen as a window; using 1280x720"); saved = new Size(1280, 720); }
      FitClient(saved.Width, saved.Height);
      windowedClient = ClientSize;
      try {
        Icon = UserGlobalIcon.Load(Path.GetDirectoryName(Application.ExecutablePath), Environment.GetEnvironmentVariable("DEKARON_GLOBAL_CLIENT"))
          ?? Icon.ExtractAssociatedIcon(Application.ExecutablePath);
      } catch { /* Keep the framework icon if both resource sources are unavailable. */ }
      status.Dock = DockStyle.Fill; status.ForeColor = Color.FromArgb(212, 175, 92); status.BackColor = Color.Black;
      status.TextAlign = ContentAlignment.MiddleCenter; status.Font = new Font("Segoe UI", 14f); status.Text = "";
      Controls.Add(status);
      if(preloadImage!=null){using(var source=Image.FromFile(preloadImage))loadingArt=new Bitmap(source);loadingPanel.Dock=DockStyle.Fill;loadingPanel.Paint+=(sender,e)=>PaintLoading(e.Graphics);Controls.Add(loadingPanel);loadingPanel.SetArtwork(loadingArt);loadingPanel.BringToFront();loadingPulse.Interval=16;loadingPulse.Tick+=(sender,e)=>PulseLoading();}
      poll.Interval = 400; poll.Tick += (s, e) => Poll();
    }

    protected override void OnShown(EventArgs e) { base.OnShown(e); if(preloadImage==null)StartRuntime();else {Console.Out.WriteLine("PRELOAD_READY");Console.Out.Flush();ReadPreloadPipe();} if (savedFull) SetFullscreen(true); }

    // Private parent-owned stdin protocol. Never opens an HTTP control endpoint or stores a ticket.
    void PaintLoading(Graphics graphics) {
      // ui_preloadwnd lbl_count: center/bottom, rect -80 -70 160 40, white.
      using(var font=new Font("Tahoma",12f,FontStyle.Regular,GraphicsUnit.Pixel))
      using(var format=new StringFormat{Alignment=StringAlignment.Center,LineAlignment=StringAlignment.Center})
        graphics.DrawString(preloadFailed?"Loading stopped - return to the launcher":"LOADING..."+displayedPercent.ToString("F1",System.Globalization.CultureInfo.InvariantCulture)+"%",font,Brushes.White,new RectangleF(0,Math.Max(0,loadingPanel.Height-70),loadingPanel.Width,40),format);
    }
    static bool ValidProgress(string command){double percent;if(command.StartsWith("VERIFY ",StringComparison.Ordinal))return NativeStartupProgress.TryVerification(command,out percent);var parts=command.Substring(command.StartsWith("INVENTORY ",StringComparison.Ordinal)?10:9).Split(' ');long done,total;return parts.Length==2&&long.TryParse(parts[0],out done)&&long.TryParse(parts[1],out total)&&done>=0&&total>0&&done<=total;}
    void QueueProgress(string command){bool wake=false;lock(progressLock){pendingProgress=command;if(!pulseScheduled){pulseScheduled=true;wake=true;}}if(wake)BeginInvoke(new Action(()=>WakeLoadingPulse()));}
    void DrainProgress(){string command;lock(progressLock){command=pendingProgress;pendingProgress=null;}if(command!=null)ApplyPreloadCommand(command);}
    void WakeLoadingPulse(){lock(progressLock){pulseScheduled=true;}if(!loadingPulse.Enabled)lastLoadingPulse=loadingClock.Elapsed.TotalMilliseconds;loadingPulse.Start();}
    void PulseLoading(){
      // The existing cover painted 100% after real frontend readiness. Reveal
      // login on the next UI pulse so that completion is actually presented.
      if(frontendReady){loadingPulse.Stop();loadingPanel.Visible=false;controller.put_IsVisible(1);controller.MoveFocus(0);return;}
      DrainProgress();var before=displayedPercent.ToString("F1",System.Globalization.CultureInfo.InvariantCulture);
      double now=loadingClock.Elapsed.TotalMilliseconds;displayedPercent=NativeStartupProgress.Advance(displayedPercent,loadingPercent,now-lastLoadingPulse);lastLoadingPulse=now;
      if(before!=displayedPercent.ToString("F1",System.Globalization.CultureInfo.InvariantCulture))loadingPanel.Invalidate(loadingPanel.ProgressBounds);
      lock(progressLock){if(pendingProgress==null&&displayedPercent>=loadingPercent){pulseScheduled=false;loadingPulse.Stop();}}
    }
    void ReadPreloadPipe(){
      var thread=new System.Threading.Thread(()=>{try{while(true){var line=new System.Text.StringBuilder();int next;while((next=Console.In.Read())!=-1&&next!='\n'){if(line.Length>=4096)throw new IOException("Oversize preload command");if(next!='\r')line.Append((char)next);}if(next==-1){if(!IsDisposed)BeginInvoke(new Action(()=>{if(!preloadLaunched)Close();}));return;}string command=line.ToString();if(IsDisposed)return;
        if(command.StartsWith("PROGRESS ",StringComparison.Ordinal)||command.StartsWith("INVENTORY ",StringComparison.Ordinal)||command.StartsWith("VERIFY ",StringComparison.Ordinal)){if(!ValidProgress(command))throw new IOException("Invalid preload count");QueueProgress(command);}
        else BeginInvoke(new Action(()=>{DrainProgress();ApplyPreloadCommand(command);}));
      }}catch{if(!IsDisposed)try{BeginInvoke(new Action(()=>Close()));}catch{}}});thread.IsBackground=true;thread.Start();
    }
    void ApplyPreloadCommand(string command){
      if(preloadFailed||frontendReady)return;
      if(command.StartsWith("INVENTORY ",StringComparison.Ordinal)&&!preloadLaunched){if(!ValidProgress(command)){Close();return;}if(hasByteProgress)return;var counts=command.Substring(10).Split(' ');inventoryDone=long.Parse(counts[0]);inventoryTotal=long.Parse(counts[1]);hasInventoryProgress=true;loadingPercent=Math.Max(loadingPercent,10.0*inventoryDone/inventoryTotal);loadingPanel.Invalidate(loadingPanel.ProgressBounds);return;}
      if(command.StartsWith("VERIFY ",StringComparison.Ordinal)&&!preloadLaunched){double value;if(!NativeStartupProgress.TryVerification(command,out value)){Close();return;}loadingPercent=Math.Max(loadingPercent,value);hasByteProgress=true;return;}
      if(command.StartsWith("PROGRESS ",StringComparison.Ordinal)&&!preloadLaunched){var parts=command.Substring(9).Split(' ');long done,total;if(parts.Length!=2||!long.TryParse(parts[0],out done)||!long.TryParse(parts[1],out total)||done<0||total<=0||done>total){Close();return;}loadingPercent=Math.Max(loadingPercent,10.0+65.0*done/total);if(!hasByteProgress){hasByteProgress=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);}return;}
      if(command.StartsWith("LAUNCH ",StringComparison.Ordinal)&&!preloadLaunched&&loadingPercent>=75){var candidate=command.Substring(7);Uri parsed;if(!Program.ValidTicket(candidate)||!Uri.TryCreate(candidate,UriKind.Absolute,out parsed)||parsed.GetLeftPart(UriPartial.Authority)!=preloadOrigin){Close();return;}url=candidate;preloadLaunched=true;StartRuntime();return;}
      Close();
    }
    void AskPreload(){
      if(preloadImage==null||frontendReady||preloadAsking||webview==null)return;preloadAsking=true;
      preloadHandler=new ScriptDone(json=>{preloadAsking=false;var match=Regex.Match(json??"",@"(\d+):(true|false):(true|false)");if(!match.Success)return;int value=int.Parse(match.Groups[1].Value);loadingPercent=Math.Max(loadingPercent,Math.Min(99.9,75+Math.Min(10000,value)*.0025));if(match.Groups[3].Value=="true"){preloadFailed=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);return;}WakeLoadingPulse();if(match.Groups[2].Value=="true"){loadingPercent=displayedPercent=100;frontendReady=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);loadingPanel.Update();loadingPulse.Start();}});
      try{webview.ExecuteScript("(()=>{const p=globalThis.__dkStartupLoad;return p?Math.round(Math.max(0,Math.min(1,p.fraction))*10000)+':'+!!p.ready+':'+!!p.failed:''})()",preloadHandler);}catch{preloadAsking=false;}
    }

    // ---- window size: 1280 x 720 game area by default; Options > resolution (Apply / OK) resizes and is remembered.
    // The file holds "<w>x<h>" of the WINDOWED game area, followed by " fullscreen" when the player left the game full screen.
    static Size SavedState(string file, out bool fullscreen) {
      fullscreen = false;
      try {
        var m = Regex.Match(File.ReadAllText(file).Trim(), @"^(\d{3,5})x(\d{3,5})( fullscreen)?$");
        if (m.Success) { fullscreen = m.Groups[3].Success; return new Size(int.Parse(m.Groups[1].Value), int.Parse(m.Groups[2].Value)); }
      } catch { }
      return new Size(1280, 720);
    }
    /** A w x h game area fits the screen's working area as a bordered window (frame included). */
    bool Fits(int w, int h) {
      var area = (IsHandleCreated?Screen.FromControl(this):launchScreen).WorkingArea; var outer = SizeFromClientSize(new Size(w, h));
      return outer.Width <= area.Width && outer.Height <= area.Height;
    }
    void SaveState() {
      var c = fullscreen ? windowedClient : ClientSize;
      try { File.WriteAllText(sizeFile, c.Width + "x" + c.Height + (fullscreen ? " fullscreen" : "")); } catch { }
    }
    /** Client area w x h (bounded by the screen's working area), centred. */
    void FitClient(int w, int h) {
      var area = (IsHandleCreated?Screen.FromControl(this):launchScreen).WorkingArea;
      var frame = SizeFromClientSize(new Size(w, h)) - new Size(w, h);
      w = Math.Max(MinimumSize.Width - frame.Width, Math.Min(w, area.Width - frame.Width)); h = Math.Max(MinimumSize.Height - frame.Height, Math.Min(h, area.Height - frame.Height));
      if (WindowState != FormWindowState.Normal) WindowState = FormWindowState.Normal;
      ClientSize = new Size(w, h);
      Location = new Point(area.X + Math.Max(0, (area.Width - Width) / 2), area.Y + Math.Max(0, (area.Height - Height) / 2));
    }
    /** The game publishes the applied resolution as globalThis.__dekaronWindowSize {w, h, v} (hud-options/apply.js). */
    void AskSize() {
      if (webview == null || sizeAsking || fullscreen) return;
      sizeAsking = true;
      sizeHandler = new ScriptDone(json => {
        sizeAsking = false;
        var m = Regex.Match(json ?? "", @"(\d{3,5})x(\d{3,5}):(\d+)");
        if (!m.Success) return;
        int w = int.Parse(m.Groups[1].Value), h = int.Parse(m.Groups[2].Value);
        if (m.Value == sizeSeen) return; sizeSeen = m.Value;   // a page reload restarts v at 1, so the size is part of the key
        // a mode that only fits the screen as full screen never becomes the windowed size (Options shows the client's own note)
        if (!Fits(w, h)) { Log("window size " + w + "x" + h + " does not fit the screen as a window; kept " + ClientSize.Width + "x" + ClientSize.Height); return; }
        FitClient(w, h); windowedClient = ClientSize;
        SaveState();
        Log("window size " + w + "x" + h + " applied and saved");
      });
      try { webview.ExecuteScript("(()=>{const s=globalThis.__dekaronWindowSize;return s&&s.w&&s.h?s.w+'x'+s.h+':'+(s.v||0):''})()", sizeHandler); }
      catch { sizeAsking = false; }
    }
    /** Options > window mode publishes globalThis.__dekaronWindowMode {fullscreen, v} and F11 in the page counts
     *  globalThis.__dekaronToggleFullscreen (hud-options/apply.js, ui/browser-fullscreen.js); a page reload resets both. */
    void AskMode() {
      if (webview == null || modeAsking) return;
      modeAsking = true;
      modeHandler = new ScriptDone(json => {
        modeAsking = false;
        var m = Regex.Match(json ?? "", @"([01-]):(\d+):(\d+)");
        if (!m.Success) return;
        int v = int.Parse(m.Groups[2].Value), toggles = int.Parse(m.Groups[3].Value);
        if (v < lastModeV) lastModeV = v;                 // the page restarted (character select, log out)
        if (toggles < lastToggles) lastToggles = toggles;
        if (v > lastModeV) { lastModeV = v; SetFullscreen(m.Groups[1].Value == "1"); }
        if (toggles > lastToggles) { lastToggles = toggles; SetFullscreen(!fullscreen); }
      });
      try { webview.ExecuteScript("(()=>{" + (startupMode==0?"":"if(!globalThis.__dkLaunchWindowModeApplied){const w=globalThis.dekaron;if(!w||!w.options||!w.options.set)return 'pending';w.options.set({winmode:"+(startupMode==2?"false":"true")+"});globalThis.__dkLaunchWindowModeApplied=true;}") + "const m=globalThis.__dekaronWindowMode,t=globalThis.__dekaronToggleFullscreen||0;return (m?(m.fullscreen?'1':'0')+':'+(m.v||0):'-:0')+':'+t})()", modeHandler); }
      catch { modeAsking = false; }
    }

    static string RuntimeLibrary() {
      foreach (var hive in new[] { Registry.LocalMachine, Registry.CurrentUser }) {
        foreach (var key in new[] { @"SOFTWARE\WOW6432Node\Microsoft\EdgeUpdate\Clients\{F3017226-FE2A-4295-8BDF-00C3A9A7E4C5}", @"SOFTWARE\Microsoft\EdgeUpdate\Clients\{F3017226-FE2A-4295-8BDF-00C3A9A7E4C5}" }) {
          using (var k = hive.OpenSubKey(key)) {
            if (k == null) continue;
            var version = k.GetValue("pv") as string; var location = k.GetValue("location") as string;
            if (string.IsNullOrEmpty(version) || version.Replace(".0", "") == "0") continue;
            if (string.IsNullOrEmpty(location)) location = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86), @"Microsoft\EdgeWebView\Application");
            var arch = Environment.Is64BitProcess ? "x64" : "x86";
            var dll = Path.Combine(location, version, "EBWebView", arch, "EmbeddedBrowserWebView.dll");
            if (File.Exists(dll)) return dll;
          }
        }
      }
      return null;
    }

    void Fail(string message) {
      if(preloadImage!=null){preloadFailed=true;loadingPanel.Invalidate();}
      status.Text = message + (standalone ? "\r\n\r\nInstall the Microsoft Edge WebView2 Runtime, then reopen Client.exe." : "\r\n\r\nUse the Desktop App or Web Browser button in the launcher instead.");
      try { File.AppendAllText(Path.Combine(Path.GetDirectoryName(profile), "native-client.log"), DateTime.Now.ToString("s") + " " + message + Environment.NewLine); } catch { }
    }

    void StartRuntime() {
      var dll = RuntimeLibrary();
      if (dll == null) { Fail("The Microsoft Edge WebView2 Runtime is not installed on this PC."); return; }
      Native.SetDllDirectoryW(Path.GetDirectoryName(dll));
      var module = Native.LoadLibraryW(dll);
      if (module == IntPtr.Zero) { Fail("The WebView2 runtime could not be loaded (" + Marshal.GetLastWin32Error() + ")."); return; }
      var entry = Native.GetProcAddress(module, "CreateWebViewEnvironmentWithOptionsInternal");
      if (entry == IntPtr.Zero) { Fail("This WebView2 runtime version does not offer the expected entry point."); return; }
      var create = (CreateEnvironmentInternal)Marshal.GetDelegateForFunctionPointer(entry, typeof(CreateEnvironmentInternal));
      Directory.CreateDirectory(profile);
      envHandler = new EnvironmentDone((hr, environment) => {
        if (hr < 0 || environment == null) { Fail("The WebView2 environment could not start (0x" + hr.ToString("X8") + ")."); return; }
        controllerHandler = new ControllerDone((hr2, created) => {
          if (hr2 < 0 || created == null) { Fail("The game view could not be created (0x" + hr2.ToString("X8") + ")."); return; }
          controller = created; controller.get_CoreWebView2(out webview);
          try {
            ICoreWebView2Settings settings; webview.get_Settings(out settings);
            settings.put_IsStatusBarEnabled(0); settings.put_AreDefaultContextMenusEnabled(0); settings.put_IsZoomControlEnabled(0);
          } catch { }
          status.Visible = false; Resize2(); controller.put_IsVisible(1); if(preloadImage!=null)loadingPanel.BringToFront();
          webview.Navigate(url);
          controller.MoveFocus(0);
          poll.Start();
        });
        environment.CreateCoreWebView2Controller(Handle, controllerHandler);
      });
      int result = create(true, 0, profile, IntPtr.Zero, envHandler);
      if (result < 0) Fail("The WebView2 environment could not start (0x" + result.ToString("X8") + ").");
    }

    void Resize2() { if (controller == null) return; var r = ClientRectangle; controller.put_Bounds(new RECT { left = 0, top = 0, right = r.Width, bottom = r.Height }); }
    protected override void OnResize(EventArgs e) { base.OnResize(e); Resize2(); }
    protected override void OnMove(EventArgs e) { base.OnMove(e); if (controller != null) controller.NotifyParentWindowPositionChanged(); }
    protected override void OnHandleCreated(EventArgs e) { base.OnHandleCreated(e); if (fullscreen) FullscreenShell.Mark(Handle, true); }
    protected override void OnHandleDestroyed(EventArgs e) { if (IsHandleCreated) FullscreenShell.Mark(Handle, false); base.OnHandleDestroyed(e); }
    protected override void OnActivated(EventArgs e) { base.OnActivated(e); if (fullscreen) FullscreenShell.Mark(Handle, true); if (controller != null) try { controller.MoveFocus(0); } catch { } }

    void Poll() {
      if (webview == null) return;
      AskPreload();
      try {
        string title; webview.get_DocumentTitle(out title); title = title ?? "";
        // the game asks the launcher to take over (same signal as the Desktop App window)
        bool returnRequested = title == "Dekaron - Return to Client" || title.StartsWith("Dekaron - Return to Client - ", StringComparison.Ordinal);
        if (!returnRequested) returningToJoin = false;
        if (returnRequested) {
          if (standalone) {
            if (!returningToJoin) { returningToJoin = true; webview.Navigate(new Uri(url).GetLeftPart(UriPartial.Authority) + Program.JoinPath); }
          } else { poll.Stop(); Close(); }
          return;
        }
        // a page fullscreen element (the browser button) follows on its CHANGES only: 2.2.0 compared it with the window state,
        // which undid every F11 within 400 ms
        int full; webview.get_ContainsFullScreenElement(out full);
        bool pageFullNow = full != 0;
        if (pageFullNow != pageFull) { pageFull = pageFullNow; SetFullscreen(pageFullNow); }
      } catch { }
      if (polls % 2 == 0) AskSize(); else AskMode();   // about every 0.8 s each: a resolution / window mode applied in Options, F11
      // every 2 s: the game's audio sessions (created when sound starts) carry the name Dekaron.exe in the volume mixer
      if (++polls % 5 == 1) {
        try {
          string ownIcon = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "client-assets", "dk-engine.ico");
          string iconPath = File.Exists(ownIcon) ? ownIcon + ",0" : Application.ExecutablePath + ",0";
          AudioNames.Apply(AudioNames.Family((uint)Process.GetCurrentProcess().Id), "DK Client", iconPath, Log);
        } catch (Exception error) { Log("volume mixer naming unavailable: " + error.Message); }
      }
    }
    int polls; readonly HashSet<string> logged = new HashSet<string>();
    void Log(string line) {
      if (!logged.Add(line) || logged.Count > 200) return;
      try { File.AppendAllText(Path.Combine(Path.GetDirectoryName(profile), "native-client.log"), DateTime.Now.ToString("s") + " " + line + Environment.NewLine); } catch { }
    }

    void SetFullscreen(bool on) {
      if (on == fullscreen) return; fullscreen = on;
      if (on) { windowedClient = ClientSize; savedState = WindowState; savedBounds = Bounds; FormBorderStyle = FormBorderStyle.None; WindowState = FormWindowState.Normal; Bounds = Screen.FromControl(this).Bounds; }
      else { FormBorderStyle = FormBorderStyle.Sizable; Bounds = savedBounds; WindowState = savedState; }
      Resize2();
      if (IsHandleCreated) FullscreenShell.Mark(Handle, on);
      SaveState();   // remembered for the next start (full screen only when the player chose it)
      // the Options window-mode checkbox follows the window (winmode true = windowed); no change when it already agrees
      if (webview != null) {
        try {
          syncHandler = new ScriptDone(_ => { });
          webview.ExecuteScript("(()=>{try{const win=" + (on ? "false" : "true") + ";const o=window.dekaron&&window.dekaron.options;if(o&&o.set){if(o.get('winmode')!==win)o.set({winmode:win});}else{const k='dekaron-solo:options:v1',s=JSON.parse(localStorage.getItem(k)||'{}');s.winmode=win;localStorage.setItem(k,JSON.stringify(s));}}catch(e){}})()", syncHandler);
        } catch { }
      }
    }

    protected override bool ProcessCmdKey(ref Message msg, Keys keyData) {
      if (keyData == Keys.F11) { SetFullscreen(!fullscreen); return true; }
      return base.ProcessCmdKey(ref msg, keyData);
    }

    protected override void OnFormClosed(FormClosedEventArgs e) { poll.Stop(); loadingPulse.Stop();loadingPulse.Dispose(); if(loadingArt!=null)loadingArt.Dispose(); try { if (controller != null) controller.Close(); } catch { } base.OnFormClosed(e); }
  }

  // When shipped alone, this EXE is a player-only client. The host serves the
  // current game and login; no server files or local Node runtime are needed.
  sealed class ServerPrompt : Form {
    readonly TextBox address = new TextBox();
    readonly Label error = new Label();
    public string ServerUrl { get; private set; }
    static bool PrivateHost(string host) {
      if (host.Equals("localhost", StringComparison.OrdinalIgnoreCase)) return true;
      IPAddress ip;
      if (!IPAddress.TryParse(host, out ip) || ip.AddressFamily != System.Net.Sockets.AddressFamily.InterNetwork) return false;
      var octets = ip.GetAddressBytes();
      return octets[0] == 10 || octets[0] == 127 || octets[0] == 192 && octets[1] == 168 || octets[0] == 172 && octets[1] >= 16 && octets[1] <= 31;
    }
    /** The host's LAN friends port (docs/MULTIPLAYER.md), used when a bare LAN IP is typed, as on the web connect page. */
    const int LanPort = 7778;
    /**
     * The same address rule as web/public/connect.js serverAddress and the launcher's Connect field: a bare IP/localhost
     * means http on the LAN (port 7778 when none is typed), a bare name means https, and only the server address itself
     * (optionally ending in /join) is accepted. Returns the origin, or null with a message for the player.
     */
    static string Normalize(string text, out string message) {
      message = "Enter a server address and optional port.";
      string value = (text ?? "").Trim();
      if (value.Length == 0 || value.Length > 512 || Regex.IsMatch(value, @"\s")) return null;
      bool schemeGiven = Regex.IsMatch(value, @"^[a-z][a-z0-9+.-]*://", RegexOptions.IgnoreCase);
      bool local = !schemeGiven && Regex.IsMatch(value, @"^(?:localhost(?::|/|$)|\d{1,3}(?:\.\d{1,3}){3}(?::|/|$)|\[)", RegexOptions.IgnoreCase);
      bool portGiven = Regex.IsMatch(schemeGiven ? value.Substring(value.IndexOf("://", StringComparison.Ordinal) + 3) : value, @"^(?:\[[^\]/]*\]|[^/:?#\[\]]*):\d+(?:[/?#]|$)");
      if (!schemeGiven) value = (local ? "http://" : "https://") + value;
      Uri uri;
      if (!Uri.TryCreate(value, UriKind.Absolute, out uri) ||
          (uri.Scheme != Uri.UriSchemeHttp && uri.Scheme != Uri.UriSchemeHttps) ||
          string.IsNullOrWhiteSpace(uri.Host) || !string.IsNullOrEmpty(uri.UserInfo) ||
          (uri.AbsolutePath != "/" && uri.AbsolutePath != "/join") || uri.Query.Length != 0 || uri.Fragment.Length != 0 ||
          uri.Port < 1 || uri.Port > 65535) return null;
      if (uri.Scheme == Uri.UriSchemeHttp && !uri.IsLoopback && !PrivateHost(uri.Host)) { message = "Use HTTPS for servers outside your LAN."; return null; }
      if (local && !portGiven) uri = new UriBuilder(uri) { Port = LanPort }.Uri;
      message = "";
      return uri.GetLeftPart(UriPartial.Authority);
    }
    public ServerPrompt(string saved) {
      Text = "DK Client | Connect"; Width = 430; Height = 225;
      StartPosition = FormStartPosition.CenterScreen; FormBorderStyle = FormBorderStyle.FixedDialog;
      MaximizeBox = false; MinimizeBox = false;
      var title = new Label { Text = "Server address", Left = 24, Top = 22, Width = 360, Height = 25 };
      address.Left = 24; address.Top = 53; address.Width = 360; address.Text = saved;
      var hint = new Label { Text = "Enter the host's LAN IP and port (7778 if none is typed)", Left = 24, Top = 82, Width = 360, Height = 20 };
      error.Left = 24; error.Top = 108; error.Width = 360; error.Height = 32; error.ForeColor = Color.DarkRed;
      var connect = new Button { Text = "Connect", Left = 274, Top = 142, Width = 110, Height = 30 };
      connect.Click += (s, e) => {
        string message, origin = Normalize(address.Text, out message);
        if (origin == null) { error.Text = message; return; }
        ServerUrl = origin;
        DialogResult = DialogResult.OK; Close();
      };
      AcceptButton = connect;
      Controls.AddRange(new Control[] { title, address, hint, error, connect });
    }
    public static string Choose(string settings) {
      string previous = "";
      try { previous = File.ReadAllText(settings).Trim(); } catch { }
      using (var prompt = new ServerPrompt(previous)) {
        if (prompt.ShowDialog() != DialogResult.OK) return null;
        try {
          Directory.CreateDirectory(Path.GetDirectoryName(settings));
          File.WriteAllText(settings, prompt.ServerUrl);
        } catch { /* A locked-down profile can still connect for this session. */ }
        return prompt.ServerUrl;
      }
    }
  }

  static class Program {
    internal static bool ValidTicket(string value){return value!=null&&Ticket.IsMatch(value);}
    static readonly Regex Ticket = new Regex(@"^https?://[^/?#\s]+/launch(\?[^#\s]*)?#ticket=[a-f0-9]{64}$", RegexOptions.CultureInvariant);
    // The host's connector as the one-file client opens it. shell=native (as the launcher adds for its Dekaron.exe windows)
    // hands Options resolution / window mode and F11 to this window: WebView2 ignores window.resizeTo.
    internal const string JoinPath = "/join?client=desktop&shell=native";

    [STAThread]
    static int Main(string[] args) {
      string url = null, profileName = "player", preloadImage=null, preloadOrigin=null; bool noLauncher = false; int startupMode=0;
      for (int i = 0; i < args.Length; i++) {
        if (args[i] == "--url" && i + 1 < args.Length) url = args[++i];
        else if (args[i] == "--profile" && i + 1 < args.Length) profileName = args[++i];
        else if (args[i] == "--preload-image" && i+1<args.Length) preloadImage=args[++i];
        else if (args[i] == "--preload-origin" && i+1<args.Length) preloadOrigin=args[++i];
        else if (args[i] == "--borderless") startupMode=2;
        else if (args[i] == "--windowed") startupMode=1;
        else if (args[i] == "--no-launcher") noLauncher = true;   // automated checks: refuse without opening the launcher
      }
      var engine = Path.GetDirectoryName(Application.ExecutablePath);
      bool standalone = false;
      if(preloadImage!=null){Uri origin;if(!Uri.TryCreate(preloadOrigin,UriKind.Absolute,out origin)||!origin.IsLoopback||origin.Scheme!="http"||origin.GetLeftPart(UriPartial.Authority)!=preloadOrigin||!Console.IsInputRedirected||!File.Exists(preloadImage))return 2;}
      // A full host installation keeps its dashboard. A single EXE opens the
      // remote world directly through the same native WebView2 game window.
      // DEDICATED: permit only this copy's loopback sign-in page without the main launcher ticket.
      bool dedicatedJoin = url == "http://127.0.0.1:7996/?screen=login&credentials=1&client=desktop&shell=native";
      if (preloadImage==null && (url == null || (!Ticket.IsMatch(url) && !dedicatedJoin))) {
        if (noLauncher) return 2;
        var launcher = Path.Combine(Path.GetDirectoryName(engine) ?? engine, "Client.exe");
        if (!File.Exists(launcher)) launcher = Path.Combine(engine, "Client.exe");
        if (File.Exists(launcher)) { Process.Start(new ProcessStartInfo(launcher) { UseShellExecute = true, WorkingDirectory = Path.GetDirectoryName(launcher) }); return 0; }
        var settings = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "DekaronPlayer", "server.txt");
        var server = ServerPrompt.Choose(settings);
        if (server == null) return 0;
        url = server + JoinPath;
        standalone = true;
      }
      if (!Regex.IsMatch(profileName, "^[a-z0-9_-]{1,40}$")) profileName = "player";
      var profile = standalone
        ? Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "DekaronPlayer", "native-profile")
        : Path.Combine(engine, "runtime", "native-profiles", profileName);
      Application.EnableVisualStyles();
      Application.Run(new GameWindow(url, profile, standalone, preloadImage, preloadOrigin, startupMode));
      return 0;
    }
  }
}
