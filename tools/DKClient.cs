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
// ENGINE-CHOSEN: window behaviour (1024 x 768 game area by default; Options > resolution sizes the window and it is remembered for the next start; F11 / game
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

[assembly: AssemblyTitle("Dekaron(Win64)")]
[assembly: AssemblyProduct("DK Engine")]
[assembly: AssemblyDescription("Dekaron(Win64) - native DX11 game window")]
// no AssemblyVersion / default manifest: their "x.x.x.x" version text reads as an IPv4 address to the release privacy audit
[assembly: AssemblyFileVersion("4.2.0")]

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
    public bool Blank; // LAUNCH_PARITY: Global's window is plain gray (128,128,128) while GameGuard starts (take4 06:25:49.654-06:26:20.6)
    public float Reveal=1f; // LAUNCH_PARITY: Global's loading art fades in from black over ~1.1 s (take4 t112.0-113.1, YAVG 17->85)
    protected override void OnPaint(PaintEventArgs e){if(Blank){e.Graphics.Clear(Color.FromArgb(128,128,128));return;}if(backdrop!=null)e.Graphics.DrawImageUnscaled(backdrop,0,0);else e.Graphics.Clear(Color.Black);base.OnPaint(e);if(Reveal<1f){using(var b=new SolidBrush(Color.FromArgb((int)Math.Round(255*(1f-Math.Max(0f,Reveal))),0,0,0)))e.Graphics.FillRectangle(b,ClientRectangle);}}
    protected override void Dispose(bool disposing){if(disposing&&backdrop!=null){backdrop.Dispose();backdrop=null;}base.Dispose(disposing);}
  }

  public static class NativeStartupProgress {
    // Verification costs both opening files and reading bytes. Tiny native
    // records count too; these are completed work units, not an ETA.
    public static bool TryVerification(string command, out double percent) {
      percent=0;if(command==null||!command.StartsWith("VERIFY ",StringComparison.Ordinal))return false;
      var parts=command.Substring(7).Split(' ');long files,totalFiles,bytes,totalBytes;
      if(parts.Length!=4||!long.TryParse(parts[0],out files)||!long.TryParse(parts[1],out totalFiles)||!long.TryParse(parts[2],out bytes)||!long.TryParse(parts[3],out totalBytes)||files<0||totalFiles<=0||files>totalFiles||bytes<0||totalBytes<=0||bytes>totalBytes)return false;
      percent=20+27.5*((double)files/totalFiles+(double)bytes/totalBytes);return true;
    }
    public static bool TryCount(string command,string prefix,double offset,double span,out double percent) {
      percent=0;if(command==null||!command.StartsWith(prefix,StringComparison.Ordinal))return false;
      var parts=command.Substring(prefix.Length).Split(' ');long done,total;
      if(parts.Length!=2||!long.TryParse(parts[0],out done)||!long.TryParse(parts[1],out total)||done<0||total<=0||done>total)return false;
      percent=offset+span*(double)done/total;return true;
    }
    // Account preparation completed before this window opened; rescale only remaining work.
    // LAUNCH_CURVE 2026-10-29 (owner: "Copy Global's exact bar timing, stall included"). Fast mode: DEKARON_LAUNCH_GLOBAL_CURVE=0.
    // Every point is read from Global take4 video frames (global001-launch-take4.mkv; ms after the art fade starts at t112.000;
    // values from the 0.25 s per-percent read in GLOBAL-LAUNCH-SEQUENCE.md section 2, "~" readings left out, linear between samples).
    // The curve is only a cap: the bar shows min(real load, curve), so it never runs ahead of real work.
    public static readonly bool GlobalCurve=Environment.GetEnvironmentVariable("DEKARON_LAUNCH_GLOBAL_CURVE")!="0";
    static readonly double[] CurveMs={0,150,400,650,900,1150,1400,1650,1900,2150,2400,2650,3650,3900,4150,4400,4650,4900,5150,5400,5650,5900,6150,6400,6650,6900,7150,7400,7650,7900,8150,8400,8650,8900,9150,9400,10400,10650,11650,11900,12150,12400,12650,12900,13150,13400,13650,14150,14400,14650,14900,15150,15400,15650,15900};
    static readonly double[] CurvePct={0,2.3,4.7,6.8,8.2,9.8,11.3,13.3,14.8,16.7,18.7,20.4,28.3,29.9,32.0,34.1,36.0,38.1,40.0,41.9,44.3,46.1,48.7,50.6,53.1,54.7,56.9,58.9,60.9,63.1,64.8,66.6,68.7,70.0,71.6,71.7,71.7,71.8,71.8,72.0,72.2,74.2,76.1,78.2,80.8,82.8,85.1,88.9,89.6,90.2,92.5,94.7,96.7,99.1,99.9};
    public const double CurveWindowToRevealMs=30970; // first gray frame t81.033 -> art fade start t112.000
    public const double CurveTextLagMs=130;      // calibration from our curve1 take: our text read 0.09-0.15 s ahead of Global at the same offset after the fade start (median 0.13 s)
    public const double CurveFadeMs=967;             // YAVG 17 at t112.000 -> 100.5 at t112.967
    public const double CurveBlackMs=17450;          // last 99.9 frame t129.433, first black frame t129.467
    public const double CurveLoginMs=18480;          // first login frame t130.500 (black ~1.03 s)
    public static double CurveAt(double ms){if(ms<=0)return 0;int last=CurveMs.Length-1;if(ms>=CurveMs[last])return CurvePct[last];int i=1;while(CurveMs[i]<ms)i++;double a=(ms-CurveMs[i-1])/(CurveMs[i]-CurveMs[i-1]);return CurvePct[i-1]+(CurvePct[i]-CurvePct[i-1])*a;}
    public static double VisibleProgress(double internalPercent) {
      // LAUNCH_PARITY 2026-10-29: Global's 0-100 is its client asset load (take4 t112.0 0% -> t127.9 99.9%, holds 99.9 until the scene switch). Our 0-100 is the webview startup load (internal 75-100); verification before it runs behind the gray window (Global: gray window while pack.hdr index + GameGuard run).
      if(internalPercent<75.0)return 0;return Math.Max(0,Math.Min(99.9,(internalPercent-75.0)*4.0));
    }
    public static double Advance(double current,double target,double elapsedMs) {
      target=Math.Max(0,Math.Min(100,target));current=Math.Max(0,Math.Min(target,current));
      return target; // Display completed work immediately; do not fabricate a timed fill.
    }
  }

  // nProtect GameGuard thin host (Global/Scrubbed bin layout beside this EXE).
  // Verifies GameGuard.des + protect.msg + GameGuard\ companions. Does not P/Invoke
  // obfuscated Init exports, does not orphan-start GameMon, and never emulates
  // CSAuth3 0x00020093 / 0x00020094 / 0x00020095 (Scrubbed intentional exclusions).
  static class GameGuardHost {
    static string root;
    static bool ready;
    internal static bool Ready { get { return ready; } }
    internal static string Root { get { return root; } }
    static bool UnlinkedLocal(string value) {
      try {
        string full=Path.GetFullPath(value);
        if(!Path.IsPathRooted(full)||full.StartsWith(@"\\"))return false;
        for(string current=full;!String.IsNullOrEmpty(current);current=Path.GetDirectoryName(current))
          if((File.Exists(current)||Directory.Exists(current))&&(File.GetAttributes(current)&FileAttributes.ReparsePoint)!=0)return false;
        return true;
      } catch { return false; }
    }
    static bool LayoutOk(string bin) {
      if(String.IsNullOrEmpty(bin)||!UnlinkedLocal(bin))return false;
      try {
        if(!File.Exists(Path.Combine(bin,"GameGuard.des")))return false;
        if(!File.Exists(Path.Combine(bin,"protect.msg")))return false;
        string folder=Path.Combine(bin,"GameGuard");
        if(!Directory.Exists(folder))return false;
        // Global companion set (x64 client prefers GameMon64; 32-bit tree still ships GameMon).
        if(!File.Exists(Path.Combine(folder,"GameMon64.des"))&&!File.Exists(Path.Combine(folder,"GameMon.des")))return false;
        if(!File.Exists(Path.Combine(folder,"npgmup.des")))return false;
        return true;
      } catch { return false; }
    }
    static string Resolve(string engineDir) {
      if(LayoutOk(engineDir))return Path.GetFullPath(engineDir);
      try {
        string configured=Environment.GetEnvironmentVariable("DEKARON_GAMEGUARD_ROOT");
        if(!String.IsNullOrWhiteSpace(configured)){
          string value=Path.GetFullPath(configured.Trim());
          if(LayoutOk(value))return value;
          string asBin=Path.Combine(value,"bin");
          if(LayoutOk(asBin))return asBin;
        }
      } catch { }
      try {
        string globalClient=Environment.GetEnvironmentVariable("DEKARON_GLOBAL_CLIENT");
        if(!String.IsNullOrWhiteSpace(globalClient)){
          string value=Path.GetFullPath(globalClient.Trim());
          if(File.Exists(value))value=Path.GetDirectoryName(value);
          if(LayoutOk(value))return value;
          string asBin=Path.Combine(value,"bin");
          if(LayoutOk(asBin))return asBin;
        }
      } catch { }
      return null;
    }
    static bool IsEnabled(string engineDir) {
      string flag=Environment.GetEnvironmentVariable("DEKARON_GAMEGUARD");
      if(!string.IsNullOrEmpty(flag)){
        flag=flag.Trim();
        if(flag=="0"||string.Equals(flag,"off",StringComparison.OrdinalIgnoreCase)||string.Equals(flag,"false",StringComparison.OrdinalIgnoreCase)||string.Equals(flag,"no",StringComparison.OrdinalIgnoreCase))
          return false;
        if(flag=="1"||string.Equals(flag,"on",StringComparison.OrdinalIgnoreCase)||string.Equals(flag,"true",StringComparison.OrdinalIgnoreCase)||string.Equals(flag,"yes",StringComparison.OrdinalIgnoreCase))
          return true;
      }
      try {
        string path=Path.Combine(engineDir??"","runtime","gameguard.enabled");
        if(File.Exists(path)){
          string body=(File.ReadAllText(path)??"").Trim();
          if(body=="0"||string.Equals(body,"off",StringComparison.OrdinalIgnoreCase)||string.Equals(body,"false",StringComparison.OrdinalIgnoreCase))
            return false;
        }
      } catch { }
      return true;
    }
    static Process companion;
    static NotifyIcon tray;
    static Form splash;
    static Panel splashFill;
    static int splashBarW;
    static Form monitor;
    static Icon trayIcon;
    static void DisposeUi() {
      CloseUpdateBox();
      try { if(tray!=null){ tray.Visible=false; tray.Dispose(); } } catch { }
      tray=null;
      try { if(splash!=null&&!splash.IsDisposed)splash.Close(); } catch { }
      splash=null; splashFill=null; splashBarW=0;
      try { if(monitor!=null&&!monitor.IsDisposed)monitor.Close(); } catch { }
      monitor=null;
      try { if(trayIcon!=null)trayIcon.Dispose(); } catch { }
      trayIcon=null;
    }
    static void StopCompanion(Action<string> log) {
      try {
        if(companion!=null&&!companion.HasExited){
          try { companion.Kill(); } catch { }
          try { companion.WaitForExit(3000); } catch { }
          if(log!=null)log("GameGuard: companion stopped");
        }
      } catch (Exception error) {
        if(log!=null)log("GameGuard: companion stop: "+error.Message);
      }
      try { if(companion!=null)companion.Dispose(); } catch { }
      companion=null;
    }
    static Icon LoadTrayIcon(string folder) {
      try {
        string[] candidates=new string[]{
          Path.Combine(folder,"GameGuard.des"),
          Path.Combine(folder,"GameMon64.des"),
          Path.Combine(folder,"GameMon.des"),
          Path.Combine(root,"GameGuard.des")
        };
        foreach(string path in candidates){
          if(!File.Exists(path))continue;
          try {
            Icon ico=Icon.ExtractAssociatedIcon(path);
            if(ico!=null)return ico;
          } catch { }
        }
      } catch { }
      return SystemIcons.Shield;
    }
    static void Pump(int ms) {
      int until=Environment.TickCount+Math.Max(0,ms);
      while(Environment.TickCount-until<0){
        try { Application.DoEvents(); } catch { }
        System.Threading.Thread.Sleep(15);
      }
    }
    static void ShowSplash(string folder, Action<string> log) {
      try {
        if(splash!=null&&!splash.IsDisposed){ try{splash.Close();}catch{} splash=null; }
        splashFill=null; splashBarW=0;
        // Global true-size splash: NOT stacked bars - one bar plays 4-8 times quickly.
        splash=new Form();
        splash.Text="nProtect GameGuard";
        splash.FormBorderStyle=FormBorderStyle.None;
        splash.ShowInTaskbar=false;
        splash.TopMost=true;
        splash.StartPosition=FormStartPosition.Manual;
        splash.BackColor=Color.FromArgb(16,16,20);
        string splashPath=Path.Combine(folder,"splash.jpg");
        int w=346, h=131;
        Panel body=new Panel();
        body.Dock=DockStyle.Fill;
        body.BackColor=Color.FromArgb(16,16,20);
        splash.Controls.Add(body);
        Color track=Color.FromArgb(40,40,48);
        Color fill=Color.FromArgb(70,170,255);
        if(File.Exists(splashPath)){
          Image art=Image.FromFile(splashPath);
          // Global true pixel size - do not shrink.
          w=art.Width; h=art.Height;
          PictureBox pic=new PictureBox();
          pic.Image=art;
          pic.SizeMode=PictureBoxSizeMode.Normal;
          pic.Location=new Point(0, 0);
          pic.Size=new Size(w, h);
          body.Controls.Add(pic);
          int barH=6, gap=4;
          Panel trackP=new Panel();
          trackP.BackColor=track;
          trackP.Location=new Point(8, h+gap);
          trackP.Size=new Size(Math.Max(40, w-16), barH);
          Panel fillP=new Panel();
          fillP.BackColor=fill;
          fillP.Location=new Point(0,0);
          fillP.Size=new Size(0, barH);
          trackP.Controls.Add(fillP);
          body.Controls.Add(trackP);
          splashFill=fillP;
          splashBarW=trackP.Width;
          h=h+gap+barH+4;
        } else {
          Label lbl=new Label();
          lbl.Location=new Point(8,8);
          lbl.Size=new Size(w-16, 28);
          lbl.TextAlign=ContentAlignment.MiddleCenter;
          lbl.ForeColor=Color.White;
          lbl.Font=new Font("Tahoma",9f,FontStyle.Bold);
          lbl.Text="nProtect GameGuard";
          body.Controls.Add(lbl);
          Panel trackP=new Panel();
          trackP.BackColor=track;
          trackP.Location=new Point(12, 40);
          trackP.Size=new Size(w-24, 6);
          Panel fillP=new Panel();
          fillP.BackColor=fill;
          fillP.Location=new Point(0,0);
          fillP.Size=new Size(0, 6);
          trackP.Controls.Add(fillP);
          body.Controls.Add(trackP);
          splashFill=fillP;
          splashBarW=trackP.Width;
          h=54;
        }
        splash.ClientSize=new Size(w,h);
        Rectangle wa=Screen.PrimaryScreen.WorkingArea;
        splash.Location=new Point(wa.Left+16, wa.Top+16);
        splash.TopMost=true;
        splash.Show();
        splash.Activate();
        splash.BringToFront();
        Application.DoEvents();
        if(log!=null)log("GameGuard: splash shown at "+splash.Location.X+","+splash.Location.Y+" size "+w+"x"+h+" (Global true size, single sequential bar)");
      } catch (Exception error) {
        if(log!=null)log("GameGuard: splash: "+error.Message);
      }
    }
    // Play ONE loading bar 4-8 times quickly (not stacked).
    static void AnimateSplashBars(Action<string> log) {
      try {
        if(splash==null||splash.IsDisposed||splashFill==null||splashBarW<=0)return;
        int cycles=6;
        int stepMs=12;
        int steps=18;
        for(int c=0;c<cycles;c++){
          for(int s=0;s<=steps;s++){
            if(splash==null||splash.IsDisposed||splashFill==null||splashFill.IsDisposed)return;
            int width=splashBarW*s/steps;
            splashFill.Width=Math.Max(0,width);
            try { Application.DoEvents(); } catch { }
            System.Threading.Thread.Sleep(stepMs);
          }
          if(splashFill!=null&&!splashFill.IsDisposed)splashFill.Width=0;
          try { Application.DoEvents(); } catch { }
          System.Threading.Thread.Sleep(30);
        }
        if(splashFill!=null&&!splashFill.IsDisposed)splashFill.Width=splashBarW;
        if(log!=null)log("GameGuard: sequential bar played "+cycles+"x (not stacked)");
      } catch (Exception error) {
        if(log!=null)log("GameGuard: bar animate: "+error.Message);
      }
    }
    // Tray logo only (by the clock). No white Game Monitor box — that stole the client taskbar identity.
    static void ShowTrayLogo(string folder, Action<string> log) {
      try {
        if(monitor!=null&&!monitor.IsDisposed){ try{monitor.Close();}catch{} }
        monitor=null;
        if(tray!=null){ try{tray.Visible=false;tray.Dispose();}catch{} tray=null; }
        try { if(trayIcon!=null)trayIcon.Dispose(); } catch { }
        trayIcon=LoadTrayIcon(folder);
        tray=new NotifyIcon();
        tray.Icon=trayIcon;
        tray.Text="nProtect GameGuard";
        tray.Visible=true;
      } catch (Exception error) {
        if(log!=null)log("GameGuard: tray: "+error.Message);
      }
    }
    static void HideSplash() {
      try {
        if(splash!=null&&!splash.IsDisposed){
          splash.Hide();
          splash.Close();
        }
      } catch { }
      splash=null; splashFill=null; splashBarW=0;
    }
    static void StartCompanion(string folder, Action<string> log) {
      StopCompanion(null);
      string mon64=Path.Combine(folder,"GameMon64.des");
      string mon=Path.Combine(folder,"GameMon.des");
      string exe=File.Exists(mon64)?mon64:(File.Exists(mon)?mon:null);
      if(exe==null){ if(log!=null)log("GameGuard: no GameMon*.des to start"); return; }
      try {
        ProcessStartInfo psi=new ProcessStartInfo();
        psi.FileName=exe;
        psi.WorkingDirectory=folder;
        psi.UseShellExecute=false;
        psi.CreateNoWindow=true;
        companion=Process.Start(psi);
        if(companion!=null&&log!=null)log("GameGuard: companion started pid="+companion.Id+" ("+Path.GetFileName(exe)+")");
      } catch (Exception error) {
        if(log!=null)log("GameGuard: companion start skipped: "+error.Message);
        companion=null;
      }
    }
    // Global order: top-left splash (true size, sequential single bar 4-8x) -> hide to tray logo (clock) -> THEN client.
    internal static void Prologue(string engineDir, Action<string> log) {
      ready=false; root=null;
      DisposeUi();
      StopCompanion(null);
      try {
        if(!IsEnabled(engineDir)){
          if(log!=null)log("GameGuard: OFF (Command Center switch / DEKARON_GAMEGUARD) - client starts without Guard");
          return;
        }
        root=Resolve(engineDir);
        if(root==null){
          if(log!=null)log("GameGuard: layout missing beside client (need GameGuard.des, protect.msg, GameGuard\\GameMon*.des + npgmup.des). Run tools\\sync-gameguard.ps1");
          return;
        }
        string folder=Path.Combine(root,"GameGuard");
        string ver="";
        try {
          string verPath=Path.Combine(folder,"GameGuard.ver");
          if(File.Exists(verPath))ver=" ver="+File.ReadAllText(verPath).Trim();
        } catch { }
        ShowSplash(folder, log);
        Pump(80);
        try { if(splash!=null){ splash.Activate(); splash.BringToFront(); } } catch { }
        Application.DoEvents();
        if(log!=null)log("GameGuard: splash load (Global true size, sequential bars)"+ver);
        AnimateSplashBars(log);
        Pump(200);
        StartCompanion(folder, log);
        Pump(300);
        ShowTrayLogo(folder, log);
        HideSplash();
        Pump(400);
        if(log!=null){
          bool trayOk = tray!=null && tray.Visible;
          log("GameGuard: tray visible="+(trayOk?"yes":"no")+" (nProtect by clock)");
        }
        ready=true;
        if(log!=null)log("GameGuard: settled tray logo only; client may start (Dekaron taskbar separate)"+ver);
      } catch (Exception error) {
        ready=false; root=null;
        DisposeUi();
        StopCompanion(null);
        if(log!=null)log("GameGuard: prologue failed: "+error.Message);
      }
    }
    // LAUNCH_PARITY 2026-10-29 (observed, Global take4 video): game window first, then ~1.0 s later the GameGuard splash
    // CENTRED on the primary screen with no bar (06:25:50.654-06:25:57.088, 6.43 s) and, at the same time, the
    // "nProtect GameGuard Update / Checking" box at the primary top-left (0,0) for 1.87 s. Nothing blocks the UI thread.
    sealed class QuietForm : Form { protected override bool ShowWithoutActivation { get { return true; } } }
    static string deferEngine, stagedFolder; static Action<string> deferLog; static Form updateBox;
    internal static void Defer(string engineDir, Action<string> log) { deferEngine=engineDir; deferLog=log; ready=false; root=null; }
    internal static bool StageWanted { get { try { return deferEngine!=null && IsEnabled(deferEngine) && Resolve(deferEngine)!=null; } catch { return false; } } }
    internal static bool BeginStaged() {
      ready=false; root=null; DisposeUi(); StopCompanion(null); Action<string> log=deferLog;
      try {
        if(deferEngine==null||!IsEnabled(deferEngine)){ if(log!=null)log("GameGuard: OFF (Command Center switch / DEKARON_GAMEGUARD) - client starts without Guard"); return false; }
        root=Resolve(deferEngine);
        if(root==null){ if(log!=null)log("GameGuard: layout missing beside client - run tools\\sync-gameguard.ps1"); return false; }
        stagedFolder=Path.Combine(root,"GameGuard");
        ShowCentredSplash(stagedFolder, log);
        ShowUpdateBox(stagedFolder, log);
        StartCompanion(stagedFolder, log);
        return true;
      } catch (Exception error) { if(log!=null)log("GameGuard: staged start failed: "+error.Message); ready=false; root=null; DisposeUi(); StopCompanion(null); return false; }
    }
    internal static void CloseUpdateBox() { try { if(updateBox!=null&&!updateBox.IsDisposed){ updateBox.Hide(); updateBox.Close(); } } catch { } updateBox=null; }
    internal static void FinishStaged() {
      CloseUpdateBox();
      try { if(stagedFolder!=null) ShowTrayLogo(stagedFolder, deferLog); } catch { }
      HideSplash(); ready=root!=null;
      if(deferLog!=null) deferLog("GameGuard: staged sequence done (splash centred, update box top-left); tray="+(tray!=null&&tray.Visible?"yes":"no"));
    }
    static void ShowCentredSplash(string folder, Action<string> log) {
      if(splash!=null&&!splash.IsDisposed){ try{splash.Close();}catch{} } splash=null; splashFill=null; splashBarW=0;
      var f=new QuietForm(); f.Text="nProtect GameGuard"; f.FormBorderStyle=FormBorderStyle.None; f.ShowInTaskbar=false; f.TopMost=true; f.StartPosition=FormStartPosition.Manual; f.BackColor=Color.FromArgb(128,128,128);
      int w=346, h=131; string p=Path.Combine(folder,"splash.jpg");
      if(File.Exists(p)){ Image art=Image.FromFile(p); w=art.Width; h=art.Height; var pic=new PictureBox(); pic.Image=art; pic.SizeMode=PictureBoxSizeMode.Normal; pic.Location=new Point(0,0); pic.Size=new Size(w,h); f.Controls.Add(pic); }
      else { var l=new Label(); l.Dock=DockStyle.Fill; l.TextAlign=ContentAlignment.MiddleCenter; l.Font=new Font("Tahoma",9f,FontStyle.Bold); l.Text="nProtect GameGuard"; f.Controls.Add(l); }
      f.ClientSize=new Size(w,h); Rectangle b=Screen.PrimaryScreen.Bounds; f.Location=new Point(b.Left+(b.Width-w)/2, b.Top+(b.Height-h)/2);
      splash=f; f.Show();
      if(log!=null)log("GameGuard: splash centred at "+f.Location.X+","+f.Location.Y+" size "+w+"x"+h+" (Global take4: centred, no bar)");
    }
    static void ShowUpdateBox(string folder, Action<string> log) {
      CloseUpdateBox();
      // Global take4 frame 06:25:51: borderless 210x112 box at (0,0): icon + "nProtect GameGuard Update", "Checking" group with an empty bar, Cancel.
      var f=new QuietForm(); f.Text="nProtect GameGuard Update"; f.FormBorderStyle=FormBorderStyle.None; f.ShowInTaskbar=false; f.TopMost=true; f.StartPosition=FormStartPosition.Manual;
      f.BackColor=SystemColors.Control; f.ClientSize=new Size(210,112); Rectangle b=Screen.PrimaryScreen.Bounds; f.Location=new Point(b.Left,b.Top);
      f.Paint+=(s,e)=>{ using(var pen=new Pen(Color.FromArgb(160,160,160))) e.Graphics.DrawRectangle(pen,0,0,f.ClientSize.Width-1,f.ClientSize.Height-1); };
      try { Icon ic=LoadTrayIcon(folder); if(ic!=null){ var pic=new PictureBox(); pic.Image=ic.ToBitmap(); pic.SizeMode=PictureBoxSizeMode.StretchImage; pic.Location=new Point(16,8); pic.Size=new Size(18,18); f.Controls.Add(pic); } } catch { }
      var t=new Label(); t.AutoSize=true; t.Location=new Point(39,11); t.Text="nProtect GameGuard Update"; t.Font=new Font("Tahoma",8.25f); f.Controls.Add(t);
      var g=new GroupBox(); g.Text="Checking"; g.Location=new Point(9,30); g.Size=new Size(192,54); g.Font=new Font("Tahoma",8.25f); f.Controls.Add(g);
      var bar=new ProgressBar(); bar.Location=new Point(7,24); bar.Size=new Size(178,8); bar.Style=ProgressBarStyle.Continuous; bar.Value=0; g.Controls.Add(bar);
      var c=new Button(); c.Text="Cancel"; c.Location=new Point(156,89); c.Size=new Size(45,19); c.Font=new Font("Tahoma",8.25f); c.FlatStyle=FlatStyle.System; c.Click+=(s,e)=>CloseUpdateBox(); f.Controls.Add(c);
      updateBox=f; f.Show();
      if(log!=null)log("GameGuard: update box at "+f.Location.X+","+f.Location.Y+" (Global take4: top-left, 1.87 s)");
    }
    internal static void Begin(string engineDir, Action<string> log) {
      if(ready)return;
      Prologue(engineDir, log);
    }
    internal static void End(Action<string> log) {
      if(ready&&log!=null)log("GameGuard: session end");
      StopCompanion(log);
      DisposeUi();
      ready=false; root=null;
    }
  }
  public sealed class GameWindow : Form {
    string url; readonly string profile;
    readonly Screen launchScreen=Screen.PrimaryScreen; /* LAUNCH_PARITY: Global opens on the primary monitor; FromPoint(Cursor) put ours on the right screen (take5) */ readonly int startupMode;
    readonly string preloadImage, preloadOrigin; Image loadingArt; double loadingPercent, displayedPercent; string loadingPhase="Preparing session"; readonly Timer loadingPulse=new Timer(), preloadPoll=new Timer(); bool preloadLaunched, frontendReady, preloadFailed; ScriptDone preloadHandler; bool preloadAsking;
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
      Text = "Dekaron.exe"; /* Native caption, fixed window with minimize and close. */ FormBorderStyle = FormBorderStyle.FixedSingle; MaximizeBox = false; MinimizeBox = true; BackColor = Color.Black; StartPosition = FormStartPosition.Manual; /* LAUNCH_PARITY: CenterScreen re-centred on the screen under the mouse */ try { var pe=Icon.ExtractAssociatedIcon(Application.ExecutablePath); if(pe!=null) Icon=pe; } catch { } ShowInTaskbar = true;
      // the game area is 1024 x 768 by default (Global take4), or the resolution last applied in Options (saved beside the profile), as a
      // bordered window; full screen only when the player left it full screen (F11 / Options window mode), 2.2.1
      sizeFile = profile + ".window";
      var saved = SavedState(sizeFile, out savedFull);
      if(startupMode!=0){savedFull=startupMode==2;saved=new Size(1024,768);}
      MinimumSize = new Size(800, 500); KeyPreview = true;
      // 2.2.0 saved a desktop-sized "windowed" area (1920x1080 on a 1080p screen): the window filled the screen on every start
      if (!Fits(saved.Width, saved.Height)) { Log("saved window size " + saved.Width + "x" + saved.Height + " does not fit the screen as a window; using 1024x768"); saved = new Size(1024, 768); }
      FitClient(saved.Width, saved.Height);
      windowedClient = ClientSize;
      try {
        string ownIcon = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "client-assets", "dekaron-client.ico");
        Icon = File.Exists(ownIcon) ? new Icon(ownIcon) : Icon.ExtractAssociatedIcon(Application.ExecutablePath);
      } catch { /* Keep the framework icon if both resource sources are unavailable. */ }
      status.Dock = DockStyle.Fill; status.ForeColor = Color.FromArgb(212, 175, 92); status.BackColor = Color.Black;
      status.TextAlign = ContentAlignment.MiddleCenter; status.Font = new Font("Segoe UI", 14f); status.Text = "";
      Controls.Add(status);
      if(preloadImage!=null){using(var source=Image.FromFile(preloadImage))loadingArt=new Bitmap(source);loadingPanel.Dock=DockStyle.Fill;loadingPanel.Paint+=(sender,e)=>PaintLoading(e.Graphics);Controls.Add(loadingPanel);loadingPanel.SetArtwork(loadingArt);loadingPanel.Blank=true;loadingPanel.BringToFront();loadingPulse.Interval=16;loadingPulse.Tick+=(sender,e)=>PulseLoading();preloadPoll.Interval=100;preloadPoll.Tick+=(sender,e)=>AskPreload();}
      poll.Interval = 400; poll.Tick += (s, e) => Poll();
    }

    protected override void OnShown(EventArgs e) { base.OnShown(e); if (preloadImage != null) { try { Update(); loadingPanel.Update(); } catch { } uncloaked = true; Cloak(false); } /* standalone: Prologue settled before this window; preload: Guard is staged inside it */ if(preloadImage==null)StartRuntime();else {Console.Out.WriteLine("PRELOAD_READY");Console.Out.Flush();if(!grayDone){grayTimer=new Timer();grayTimer.Interval=(int)NativeStartupProgress.CurveWindowToRevealMs;grayTimer.Tick+=(gs,ge)=>{grayTimer.Stop();grayDone=true;MaybeReveal();};grayTimer.Start();}ReadPreloadPipe();StartGuardStage();} if (savedFull) SetFullscreen(true); }
    // LAUNCH_PARITY: offsets from Global take4: window 06:25:49.654, splash+update box +1.000 s, update box gone +2.867 s, splash gone +7.434 s.
    Timer guardStage, revealTimer; int guardStep; bool guardDone, artShown;
    // LAUNCH_CURVE: Global-curve mode (default) or fast mode (DEKARON_LAUNCH_GLOBAL_CURVE=0: whole numbers 0..100 at an even cadence).
    Timer curveTimer, grayTimer; bool grayDone=!NativeStartupProgress.GlobalCurve, blackout, loginShown; double revealAt=-1, readyAt=-1, launchAt=-1, fastStep, fastNextAt=-1, fastInterval=FastExpectedMs/100.0;
    const double FastExpectedMs=5450; // expected real load: after2 webview load 07:27:02.12 -> 07:27:07.57
    double NowMs(){ return loadingClock.Elapsed.TotalMilliseconds; }
    string ShownText(){
      if(NativeStartupProgress.GlobalCurve){ double v=revealAt<0?0:Math.Min(NativeStartupProgress.VisibleProgress(displayedPercent),NativeStartupProgress.CurveAt(NowMs()-revealAt-NativeStartupProgress.CurveTextLagMs)); return v.ToString("F1",System.Globalization.CultureInfo.InvariantCulture); }
      return ((int)fastStep).ToString(System.Globalization.CultureInfo.InvariantCulture);
    }
    void FastTick(){
      double now=NowMs();
      if(fastNextAt<0){fastNextAt=now+fastInterval;return;}
      if(fastStep>=100||now<fastNextAt)return;
      if(fastStep>=99&&readyAt<0)return; // 100 only once loading is really done
      fastStep++;
      double real=readyAt>=0?100:NativeStartupProgress.VisibleProgress(displayedPercent);
      double el=Math.Max(1,now-(launchAt>=0?launchAt:revealAt));
      double eta=readyAt>=0?0:(real>=1?el*(100-real)/real:Math.Max(0,FastExpectedMs-el));
      double target=Math.Max(16,eta/Math.Max(1,100-fastStep));
      double lead=fastStep-real; if(lead>0)target*=1+lead/5.0; // ahead of real work: stretch the cadence smoothly instead of stopping
      fastInterval=fastInterval*0.8+target*0.2;
      fastNextAt+=fastInterval; if(fastNextAt<now)fastNextAt=now;
    }
    void CurveTick(){
      if(IsDisposed||loginShown||preloadFailed){curveTimer.Stop();return;}
      double now=NowMs();
      if(NativeStartupProgress.GlobalCurve){
        if(readyAt>=0){double black=Math.Max(revealAt+NativeStartupProgress.CurveBlackMs,readyAt),login=Math.Max(revealAt+NativeStartupProgress.CurveLoginMs,readyAt+(NativeStartupProgress.CurveLoginMs-NativeStartupProgress.CurveBlackMs));
          if(now>=login){ReleaseLogin();return;}
          if(now>=black&&!blackout){blackout=true;loadingPanel.Reveal=0f;loadingPanel.Invalidate();return;}}
      } else { FastTick(); if(fastStep>=100&&readyAt>=0&&now>=fastNextAt){ReleaseLogin();return;} }
      if(!blackout)loadingPanel.Invalidate(loadingPanel.ProgressBounds);
    }
    void ReleaseLogin(){ loginShown=true; curveTimer.Stop(); loadingPulse.Start(); }
    // LAUNCH_PARITY: art + bar appear only once GameGuard's splash is gone AND the real asset load starts (LAUNCH), like Global (gray until t112.0).
    void GuardDone() { guardDone = true; MaybeReveal(); }
    void MaybeReveal() { if (artShown || !guardDone || !grayDone || !(preloadLaunched || preloadFailed)) return; artShown = true; RevealArt(); }
    void RevealArt() { revealAt = NowMs(); curveTimer = new Timer(); curveTimer.Interval = 16; curveTimer.Tick += (s, e) => CurveTick(); curveTimer.Start(); double fadeMs = NativeStartupProgress.GlobalCurve ? NativeStartupProgress.CurveFadeMs : 1100.0;
      loadingPanel.Reveal = 0f; loadingPanel.Blank = false; loadingPanel.Invalidate();
      var clock = Stopwatch.StartNew(); revealTimer = new Timer(); revealTimer.Interval = 16;
      revealTimer.Tick += (s, e) => { if (IsDisposed) { revealTimer.Stop(); return; } float r = (float)Math.Min(1.0, clock.Elapsed.TotalMilliseconds / fadeMs); loadingPanel.Reveal = r; loadingPanel.Invalidate(); if (r >= 1f) revealTimer.Stop(); };
      revealTimer.Start();
    }
    [DllImport("dwmapi.dll")] static extern int DwmSetWindowAttribute(IntPtr hwnd, int attr, ref int value, int size);
    // LAUNCH_PARITY: Global's window shows gray from its first frame; ours showed one white frame (after take, t2.333) before the first paint.
    void Cloak(bool on) { try { int v = on ? 1 : 0; DwmSetWindowAttribute(Handle, 13 /*DWMWA_CLOAK*/, ref v, 4); } catch { } }
    void StartGuardStage() {
      if (!GameGuardHost.StageWanted) { GuardDone(); return; }
      guardStage = new Timer(); guardStep = 0; guardStage.Interval = 1000;
      guardStage.Tick += (s, e) => {
        if (IsDisposed) { guardStage.Stop(); return; }
        guardStep++;
        if (guardStep == 1) { if (!GameGuardHost.BeginStaged()) { guardStage.Stop(); GuardDone(); return; } guardStage.Interval = 1867; }
        else if (guardStep == 2) { GameGuardHost.CloseUpdateBox(); guardStage.Interval = 4567; }
        else { guardStage.Stop(); GameGuardHost.FinishStaged(); GuardDone(); }
      };
      FormClosed += (s, e) => { try { guardStage.Stop(); } catch { } };
      guardStage.Start();
    }

    // Private parent-owned stdin protocol. Never opens an HTTP control endpoint or stores a ticket.
    void PaintLoading(Graphics graphics) {
      // ui_preloadwnd lbl_count: center/bottom, rect -80 -70 160 40, white.
      using(var font=new Font("Tahoma",12f,FontStyle.Regular,GraphicsUnit.Pixel))
      using(var format=new StringFormat{Alignment=StringAlignment.Center,LineAlignment=StringAlignment.Center}) {
        if(!blackout)graphics.DrawString(preloadFailed?"Loading stopped - return to the launcher":"LOADING... "+ShownText()+" %",font,Brushes.White,new RectangleF(0,Math.Max(0,loadingPanel.Height-78),loadingPanel.Width,32),format);

      }
    }
    static bool ValidProgress(string command){double percent;if(command.StartsWith("VERIFY ",StringComparison.Ordinal))return NativeStartupProgress.TryVerification(command,out percent);if(command.StartsWith("OWNER ",StringComparison.Ordinal))return NativeStartupProgress.TryCount(command,"OWNER ",0,5,out percent);if(command.StartsWith("FINGERPRINT ",StringComparison.Ordinal))return NativeStartupProgress.TryCount(command,"FINGERPRINT ",10,10,out percent);if(command.StartsWith("INVENTORY ",StringComparison.Ordinal))return NativeStartupProgress.TryCount(command,"INVENTORY ",5,5,out percent);return NativeStartupProgress.TryCount(command,"PROGRESS ",20,55,out percent);}
    void QueueProgress(string command){bool wake=false;lock(progressLock){pendingProgress=command;if(!pulseScheduled){pulseScheduled=true;wake=true;}}if(wake)BeginInvoke(new Action(()=>WakeLoadingPulse()));}
    void DrainProgress(){string command;lock(progressLock){command=pendingProgress;pendingProgress=null;}if(command!=null)ApplyPreloadCommand(command);}
    void WakeLoadingPulse(){lock(progressLock){pulseScheduled=true;}if(!loadingPulse.Enabled)lastLoadingPulse=loadingClock.Elapsed.TotalMilliseconds;loadingPulse.Start();}
    void PulseLoading(){
      // The existing cover painted 100% after real frontend readiness. Reveal
      // login on the next UI pulse so that completion is actually presented.
      if(frontendReady){if(!loginShown){if(readyAt<0)readyAt=NowMs();loadingPulse.Stop();return;}preloadPoll.Stop();loadingPulse.Stop();try{loadingPanel.Visible=false;controller.put_IsVisible(1);controller.MoveFocus(0);ReportPreloadState("FRONTEND_READY");}catch{frontendReady=false;preloadFailed=true;loadingPanel.Visible=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);ReportPreloadState("FRONTEND_FAILED");}return;}
      DrainProgress();var before=displayedPercent.ToString("F1",System.Globalization.CultureInfo.InvariantCulture);
      double now=loadingClock.Elapsed.TotalMilliseconds;displayedPercent=NativeStartupProgress.Advance(displayedPercent,loadingPercent,now-lastLoadingPulse);lastLoadingPulse=now;
      if(before!=displayedPercent.ToString("F1",System.Globalization.CultureInfo.InvariantCulture))loadingPanel.Invalidate(loadingPanel.ProgressBounds);
      lock(progressLock){if(pendingProgress==null&&displayedPercent>=loadingPercent){pulseScheduled=false;loadingPulse.Stop();}}
    }
    void ReadPreloadPipe(){
      var thread=new System.Threading.Thread(()=>{try{while(true){var line=new System.Text.StringBuilder();int next;while((next=Console.In.Read())!=-1&&next!='\n'){if(line.Length>=4096)throw new IOException("Oversize preload command");if(next!='\r')line.Append((char)next);}if(next==-1){if(!IsDisposed)BeginInvoke(new Action(()=>{if(!preloadLaunched)Close();}));return;}string command=line.ToString();if(IsDisposed)return;
        if(command.StartsWith("PROGRESS ",StringComparison.Ordinal)||command.StartsWith("INVENTORY ",StringComparison.Ordinal)||command.StartsWith("VERIFY ",StringComparison.Ordinal)||command.StartsWith("OWNER ",StringComparison.Ordinal)||command.StartsWith("FINGERPRINT ",StringComparison.Ordinal)){if(!ValidProgress(command))throw new IOException("Invalid preload count");QueueProgress(command);}
        else BeginInvoke(new Action(()=>{DrainProgress();ApplyPreloadCommand(command);}));
      }}catch{if(!IsDisposed)try{BeginInvoke(new Action(()=>Close()));}catch{}}});thread.IsBackground=true;thread.Start();
    }
    void ApplyPreloadCommand(string command){
      if(command=="CANCEL"&&preloadLaunched&&!frontendReady){Close();return;}
      if(preloadFailed||frontendReady)return;
      if(command=="STATUS receipt"&&!preloadLaunched){loadingPhase="Checking verification record";loadingPanel.Invalidate(loadingPanel.ProgressBounds);return;}
      if((command.StartsWith("OWNER ",StringComparison.Ordinal)||command.StartsWith("FINGERPRINT ",StringComparison.Ordinal))&&!preloadLaunched){double value;bool owner=command.StartsWith("OWNER ",StringComparison.Ordinal);if(!NativeStartupProgress.TryCount(command,owner?"OWNER ":"FINGERPRINT ",owner?0:10,owner?5:10,out value)){Close();return;}loadingPhase=owner?"Preparing account":"Checking engine files";loadingPercent=Math.Max(loadingPercent,value);loadingPanel.Invalidate(loadingPanel.ProgressBounds);return;}
      if(command.StartsWith("INVENTORY ",StringComparison.Ordinal)&&!preloadLaunched){if(!ValidProgress(command)){Close();return;}if(hasByteProgress)return;var counts=command.Substring(10).Split(' ');inventoryDone=long.Parse(counts[0]);inventoryTotal=long.Parse(counts[1]);hasInventoryProgress=true;loadingPhase="Counting installed files";loadingPercent=Math.Max(loadingPercent,5.0+5.0*inventoryDone/inventoryTotal);loadingPanel.Invalidate(loadingPanel.ProgressBounds);return;}
      if(command.StartsWith("VERIFY ",StringComparison.Ordinal)&&!preloadLaunched){double value;if(!NativeStartupProgress.TryVerification(command,out value)){Close();return;}loadingPhase="Checking installed assets";loadingPercent=Math.Max(loadingPercent,value);hasByteProgress=true;return;}
      if(command.StartsWith("PROGRESS ",StringComparison.Ordinal)&&!preloadLaunched){var parts=command.Substring(9).Split(' ');long done,total;if(parts.Length!=2||!long.TryParse(parts[0],out done)||!long.TryParse(parts[1],out total)||done<0||total<=0||done>total){Close();return;}loadingPhase="Checking installed assets";loadingPercent=Math.Max(loadingPercent,20.0+55.0*done/total);if(!hasByteProgress){hasByteProgress=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);}return;}
      if(command.StartsWith("LAUNCH ",StringComparison.Ordinal)&&!preloadLaunched&&loadingPercent>=75){var candidate=command.Substring(7);Uri parsed;if(!Program.ValidTicket(candidate)||!Uri.TryCreate(candidate,UriKind.Absolute,out parsed)||parsed.GetLeftPart(UriPartial.Authority)!=preloadOrigin){Close();return;}url=candidate;preloadLaunched=true;launchAt=NowMs();loadingPhase="Preparing game graphics";loadingPanel.Invalidate(loadingPanel.ProgressBounds);preloadPoll.Start();StartRuntime();MaybeReveal();return;}
      Close();
    }
    void ReportPreloadState(string state){try{Console.Out.WriteLine(state);Console.Out.Flush();}catch{}}
    void AskPreload(){
      if(preloadImage==null||frontendReady||preloadFailed||preloadAsking||webview==null)return;preloadAsking=true;
      preloadHandler=new ScriptDone(json=>{preloadAsking=false;var match=Regex.Match(json??"",@"(\d+):(true|false):(true|false)");if(!match.Success)return;int value=int.Parse(match.Groups[1].Value);loadingPercent=Math.Max(loadingPercent,Math.Min(99.9,75+Math.Min(10000,value)*.0025));if(match.Groups[3].Value=="true"){preloadPoll.Stop();preloadFailed=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);ReportPreloadState("FRONTEND_FAILED");return;}WakeLoadingPulse();if(match.Groups[2].Value=="true"){loadingPercent=displayedPercent=100;frontendReady=true;loadingPanel.Invalidate(loadingPanel.ProgressBounds);loadingPanel.Update();loadingPulse.Start();}});
      try{webview.ExecuteScript("(()=>{const p=globalThis.__dkStartupLoad;return p?Math.round(Math.max(0,Math.min(1,typeof p.displayed=='number'?Math.min(p.displayed,p.fraction):p.fraction))*10000)+':'+!!p.ready+':'+!!p.failed:''})()",preloadHandler);}catch{preloadAsking=false;}
    }

    // ---- window size: 1024 x 768 game area by default (Global take4); Options > resolution (Apply / OK) resizes and is remembered.
    // The file holds "<w>x<h>" of the WINDOWED game area, followed by " fullscreen" when the player left the game full screen.
    static Size SavedState(string file, out bool fullscreen) {
      fullscreen = false;
      try {
        var m = Regex.Match(File.ReadAllText(file).Trim(), @"^(\d{3,5})x(\d{3,5})( fullscreen)?$");
        if (m.Success) { fullscreen = m.Groups[3].Success; return new Size(int.Parse(m.Groups[1].Value), int.Parse(m.Groups[2].Value)); }
      } catch { }
      return new Size(1024, 768);
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
      if (!IsHandleCreated) {
        // LAUNCH_PARITY: Global take4 client sits at ((W-cw)/2,(H-ch)/2) of the primary screen bounds (1024x768 -> 448,156).
        var b = launchScreen.Bounds; var outer = new Rectangle(b.X + (b.Width - w) / 2 - (frame.Width / 2), b.Y + (b.Height - h) / 2 - (frame.Width / 2 - 3), Width, Height); /* WINDOW_PARITY: Global take4 puts the CAPTION top (not the client) at (H-768)/2 = 156 */
        if (area.Contains(outer)) Location = outer.Location;
      }
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
      if(preloadImage!=null){preloadFailed=true;loadingPanel.Blank=false;loadingPanel.Reveal=1f;loadingPanel.Invalidate();}
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
      // Game host: never throttle/background the renderer (timers, rAF, occlusion) - keeps frame pacing and ping probes steady.
      try { var extra = Environment.GetEnvironmentVariable("WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS") ?? ""; Environment.SetEnvironmentVariable("WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS", (extra + " --disable-renderer-backgrounding --disable-background-timer-throttling --disable-backgrounding-occluded-windows --disable-features=CalculateNativeWinOcclusion,IntensiveWakeUpThrottling --force-gpu-preference=high-performance").Trim()); } catch { }
      int result = create(true, 0, profile, IntPtr.Zero, envHandler);
      if (result < 0) Fail("The WebView2 environment could not start (0x" + result.ToString("X8") + ").");
    }

    void Resize2() { if (controller == null) return; var r = ClientRectangle; controller.put_Bounds(new RECT { left = 0, top = 0, right = r.Width, bottom = r.Height }); }
    protected override void OnResize(EventArgs e) { base.OnResize(e); Resize2(); }
    protected override void OnMove(EventArgs e) { base.OnMove(e); if (controller != null) controller.NotifyParentWindowPositionChanged(); }
    protected override void OnHandleCreated(EventArgs e) { base.OnHandleCreated(e); if (fullscreen) FullscreenShell.Mark(Handle, true); if (preloadImage != null && !uncloaked) Cloak(true); }
    bool uncloaked;
    protected override void OnHandleDestroyed(EventArgs e) { if (IsHandleCreated) FullscreenShell.Mark(Handle, false); base.OnHandleDestroyed(e); }
    protected override void OnActivated(EventArgs e) { base.OnActivated(e); if (fullscreen) FullscreenShell.Mark(Handle, true); if (controller != null) try { controller.MoveFocus(0); } catch { } }

    void Poll() {
      if (webview == null) return;
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
          string ownIcon = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "client-assets", "dekaron-client.ico");
          string iconPath = File.Exists(ownIcon) ? ownIcon + ",0" : Application.ExecutablePath + ",0";
          AudioNames.Apply(AudioNames.Family((uint)Process.GetCurrentProcess().Id), "Dekaron(Win64)", iconPath, Log);
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
      else { FormBorderStyle = FormBorderStyle.FixedSingle; MaximizeBox = false; Bounds = savedBounds; WindowState = savedState; }
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

    protected override void OnFormClosed(FormClosedEventArgs e) { poll.Stop(); preloadPoll.Stop();preloadPoll.Dispose(); loadingPulse.Stop();loadingPulse.Dispose(); if(loadingArt!=null)loadingArt.Dispose(); try { if (controller != null) controller.Close(); } catch { } GameGuardHost.End(Log); base.OnFormClosed(e); }
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
      Text = "Dekaron(Win64) | Connect"; Width = 430; Height = 225;
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
      // Global GameGuard order: splash -> load -> tray/monitor, THEN the DX11 client window.
      Action<string> ggLog = msg => { try { string dir=Path.Combine(engine,"runtime","native-profiles"); Directory.CreateDirectory(dir); File.AppendAllText(Path.Combine(dir,"native-client.log"), DateTime.Now.ToString("yyyy-MM-ddTHH:mm:ss")+" "+msg+Environment.NewLine); } catch { } };
      // LAUNCH_PARITY: with the native preload the window opens first and GameGuard is staged inside it (Global take4 order).
      if (preloadImage == null) GameGuardHost.Prologue(engine, ggLog); else GameGuardHost.Defer(engine, ggLog);
      Application.Run(new GameWindow(url, profile, standalone, preloadImage, preloadOrigin, startupMode));
      return 0;
    }
  }
}
