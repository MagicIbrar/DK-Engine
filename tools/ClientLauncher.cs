using System;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Text;
using System.Windows.Forms;

internal static class ClientLauncher
{
    // Windows command-line escaping, including trailing backslashes before the closing quote.
    private static string Quote(string value)
    {
        StringBuilder result = new StringBuilder("\"");
        int slashes = 0;
        foreach (char ch in value)
        {
            if (ch == '\\') { slashes++; continue; }
            if (ch == '"') { result.Append('\\', slashes * 2 + 1); result.Append(ch); }
            else { result.Append('\\', slashes); result.Append(ch); }
            slashes = 0;
        }
        result.Append('\\', slashes * 2); result.Append('"');
        return result.ToString();
    }

    [STAThread]
    private static int Main(string[] args)
    {
        try
        {
            string ownFolder = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string script = Path.Combine(ownFolder, "tools", "client-ui.ps1");
            if (!File.Exists(script)) script = Path.Combine(ownFolder, "engine", "tools", "client-ui.ps1");
            if (!File.Exists(script)) throw new FileNotFoundException("Keep Client.exe beside engine, data and bin, or open the copy inside engine. The client window script is missing.");
            string powershell = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.System), "WindowsPowerShell", "v1.0", "powershell.exe");
            if (!File.Exists(powershell)) throw new FileNotFoundException("Windows PowerShell is required to open the client window.");
            if (args.Length == 1 && args[0] == "--validate-only") return 0;
            bool resume = args.Length == 1 && args[0] == "--resume";
            bool setup = args.Length == 1 && args[0] == "--setup";
            if (args.Length != 0 && !resume && !setup) throw new ArgumentException("Unknown launcher argument.");
            ProcessStartInfo start = new ProcessStartInfo(powershell);
            start.Arguments = "-NoProfile -ExecutionPolicy Bypass -WindowStyle Hidden -STA -File " + Quote(Path.GetFullPath(script));
            if (resume) start.Arguments += " -Resume";
            if (setup) start.Arguments += " -Setup";
            start.WorkingDirectory = Path.GetDirectoryName(Path.GetDirectoryName(script));
            start.UseShellExecute = false;
            start.CreateNoWindow = true;
            start.WindowStyle = ProcessWindowStyle.Hidden;
            Process process = Process.Start(start);
            if (process == null) throw new InvalidOperationException("Windows could not start the client window.");
            process.Dispose();
            return 0;
        }
        catch (Exception error)
        {
            MessageBox.Show(error.Message, "Dekaron Online | Client", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return 1;
        }
    }
}
