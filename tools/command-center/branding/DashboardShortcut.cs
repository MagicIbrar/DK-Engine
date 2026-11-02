using System;
using System.IO;
using System.Text;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Web.Script.Serialization;
[ComImport,Guid("00021401-0000-0000-C000-000000000046")] class ShellLink {}
[ComImport,Guid("000214F9-0000-0000-C000-000000000046"),InterfaceType(ComInterfaceType.InterfaceIsIUnknown)] interface IShellLink {
 void GetPath([Out,MarshalAs(UnmanagedType.LPWStr)] StringBuilder p,int n,IntPtr data,uint flags); void GetIDList(out IntPtr p); void SetIDList(IntPtr p);
 void GetDescription([Out,MarshalAs(UnmanagedType.LPWStr)] StringBuilder p,int n); void SetDescription([MarshalAs(UnmanagedType.LPWStr)]string s);
 void GetWorkingDirectory([Out,MarshalAs(UnmanagedType.LPWStr)] StringBuilder p,int n); void SetWorkingDirectory([MarshalAs(UnmanagedType.LPWStr)]string s);
 void GetArguments([Out,MarshalAs(UnmanagedType.LPWStr)] StringBuilder p,int n); void SetArguments([MarshalAs(UnmanagedType.LPWStr)]string s);
 void GetHotkey(out short p); void SetHotkey(short p); void GetShowCmd(out int p); void SetShowCmd(int p);
 void GetIconLocation([Out,MarshalAs(UnmanagedType.LPWStr)]StringBuilder p,int n,out int index); void SetIconLocation([MarshalAs(UnmanagedType.LPWStr)]string p,int index);
 void SetRelativePath([MarshalAs(UnmanagedType.LPWStr)]string p,uint r); void Resolve(IntPtr window,uint flags); void SetPath([MarshalAs(UnmanagedType.LPWStr)]string p);
}
[StructLayout(LayoutKind.Sequential,Pack=4)] struct PropertyKey {public Guid Format;public uint Id;public PropertyKey(Guid f,uint i){Format=f;Id=i;}}
[StructLayout(LayoutKind.Explicit,Size=24)] struct PropVariant {[FieldOffset(0)] public ushort Type;[FieldOffset(8)]public IntPtr Value;}
[ComImport,Guid("886D8EEB-8CF2-4446-8D02-CDBA1DBDCF99"),InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]interface IPropertyStore{void GetCount(out uint n);void GetAt(uint i,out PropertyKey key);void GetValue(ref PropertyKey key,out PropVariant value);void SetValue(ref PropertyKey key,ref PropVariant value);void Commit();}
internal static class DashboardShortcut {
 [DllImport("ole32.dll")]static extern int PropVariantClear(ref PropVariant p);
 static PropertyKey AppId=new PropertyKey(new Guid("9F4C2855-9F79-4B39-A8D0-E1D42DE1D5F3"),5);
 static string Read(IShellLink link,int field){var b=new StringBuilder(32768);int index;switch(field){case 0:link.GetPath(b,b.Capacity,IntPtr.Zero,4);break;case 1:link.GetArguments(b,b.Capacity);break;case 2:link.GetWorkingDirectory(b,b.Capacity);break;case 3:link.GetIconLocation(b,b.Capacity,out index);break;default:link.GetDescription(b,b.Capacity);break;}return b.ToString();}
 [STAThread]static int Main(string[] a){object obj=null;try{
  if(a.Length!=2&&a.Length!=8)throw new Exception("Expected inspect <link> or create <link> <target> <arguments> <working directory> <icon> <description> <app id>.");
  string path=Path.GetFullPath(a[1]);obj=new ShellLink();var link=(IShellLink)obj;var persist=(IPersistFile)obj;var store=(IPropertyStore)obj;
  if(a[0]=="create"&&a.Length==8){if(!File.Exists(a[2])||!File.Exists(a[5])||!Directory.Exists(a[4]))throw new Exception("The dashboard shortcut target, icon and folder must exist.");link.SetPath(Path.GetFullPath(a[2]));link.SetArguments(a[3]);link.SetWorkingDirectory(Path.GetFullPath(a[4]));link.SetIconLocation(Path.GetFullPath(a[5]),0);link.SetDescription(a[6]);link.SetShowCmd(1);var value=new PropVariant{Type=31,Value=Marshal.StringToCoTaskMemUni(a[7])};try{store.SetValue(ref AppId,ref value);store.Commit();}finally{PropVariantClear(ref value);}persist.Save(path,true);
  }else if(a[0]=="inspect"&&a.Length==2){persist.Load(path,0);}else throw new Exception("Invalid shortcut operation.");
  PropVariant id;store.GetValue(ref AppId,out id);string appId;try{appId=id.Type==31?Marshal.PtrToStringUni(id.Value):null;}finally{PropVariantClear(ref id);}
  Console.WriteLine(new JavaScriptSerializer().Serialize(new{shortcut=path,target=Read(link,0),arguments=Read(link,1),workingDirectory=Read(link,2),icon=Read(link,3),description=Read(link,4),appUserModelId=appId}));return 0;
 }catch(Exception e){Console.Error.WriteLine(e.Message);return 1;}finally{if(obj!=null)Marshal.FinalReleaseComObject(obj);}}
}
