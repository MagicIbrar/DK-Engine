using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Diagnostics;
using System.Web.Script.Serialization;

// Static PE/CLI metadata edit only. No target assembly is loaded or executed.
internal static class DashboardIdentity {
    static readonly HashSet<string> Sources=new HashSet<string>(StringComparer.OrdinalIgnoreCase){"5fcf313221efe445ad91b82ee148118af6621061af58ce5beaa6e9a5bd034662","5f6980e3f27cd3c6bcb32d169ceb0c5301aa9bc6279f93f3d45430202b16d74b"};
    sealed class Literal { public int Offset; public string Value; }
    static ushort U16(byte[] b,int o){return BitConverter.ToUInt16(b,o);} static uint U32(byte[] b,int o){return BitConverter.ToUInt32(b,o);}
    static int Align(int n){return (n+3)&~3;}
    static int Rva(byte[] b,uint r){int p=(int)U32(b,60),sections=U16(b,p+6),s=p+24+U16(b,p+20);for(int i=0;i<sections;i++){int at=s+i*40;uint v=U32(b,at+12),size=U32(b,at+16);if(r>=v&&r-v<size)return checked((int)(U32(b,at+20)+r-v));}throw new Exception("Metadata address is outside file-backed sections.");}
    static int Compressed(byte[] b,ref int p){int n=b[p++];if((n&128)==0)return n;if((n&192)==128)return ((n&63)<<8)|b[p++];if((n&224)==192){int result=((n&31)<<24)|(b[p]<<16)|(b[p+1]<<8)|b[p+2];p+=3;return result;}throw new Exception("Invalid user-string length.");}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static List<Literal> Find(byte[] b){
        int pe=(int)U32(b,60),opt=pe+24,dd=U16(b,opt)==0x20b?112:96,cli=Rva(b,U32(b,opt+dd+14*8)),meta=Rva(b,U32(b,cli+8));
        if(U32(b,meta)!=0x424a5342)throw new Exception("Not CLI metadata.");int cursor=Align(meta+16+(int)U32(b,meta+12)),streams=U16(b,cursor+2);cursor+=4;int heap=0,length=0;
        for(int i=0;i<streams;i++){int off=(int)U32(b,cursor),size=(int)U32(b,cursor+4),start=cursor+8,end=start;while(b[end]!=0)end++;string name=Encoding.ASCII.GetString(b,start,end-start);if(name=="#US"){heap=meta+off;length=size;}cursor=Align(end+1);}
        if(heap==0||length<1)throw new Exception("Missing CLI user-string heap.");var result=new List<Literal>();int at=heap+1;
        while(at<heap+length){int size=Compressed(b,ref at);if(size==0)continue;if(size<1||at+size>heap+length)throw new Exception("User-string heap exceeds metadata.");string text=Encoding.Unicode.GetString(b,at,size-1);bool original=text=="DK.CommandCenter"||text=="DK.CommandCenter.TestPreview",scoped=(text.Length==16||text.Length==28)&&text.StartsWith("DK.Dash.",StringComparison.Ordinal)&&System.Text.RegularExpressions.Regex.IsMatch(text.Substring(8,8),"^[a-f0-9]{8}$")&&(text.Length==16||text.EndsWith(".TestPreview",StringComparison.Ordinal));if(original||scoped)result.Add(new Literal{Offset=at,Value=text});at+=size;}
        if(result.FindAll(v=>v.Value.Length==16).Count!=1)throw new Exception("Expected exactly one dashboard process identity literal.");return result;
    }
    static void Put(byte[] b,Literal l,string text){byte[] value=Encoding.Unicode.GetBytes(text);if(value.Length!=Encoding.Unicode.GetByteCount(l.Value))throw new Exception("Identity edit must preserve metadata length.");Buffer.BlockCopy(value,0,b,l.Offset,value.Length);}
    static bool Inside(string file,string folder){return file.StartsWith(folder.TrimEnd(Path.DirectorySeparatorChar)+Path.DirectorySeparatorChar,StringComparison.OrdinalIgnoreCase);}
    static int Main(string[] args){try{
        if(args.Length!=5||(args[0]!="apply"&&args[0]!="validate"))throw new Exception("Expected apply|validate, dashboard EXE, instance root, edition, receipt file.");
        bool apply=args[0]=="apply";string file=Path.GetFullPath(args[1]),root=Path.GetFullPath(args[2]).TrimEnd(Path.DirectorySeparatorChar),edition=args[3],receipt=Path.GetFullPath(args[4]);if(!Inside(file,root)||!Inside(receipt,root)||Path.GetFileName(file)!="DKCommandCenter.exe")throw new Exception("Dashboard identity paths must stay inside the named project.");
        byte[] original=File.ReadAllBytes(file),normalized=(byte[])original.Clone(),updated=(byte[])original.Clone();var literals=Find(original);foreach(var l in literals)Put(normalized,l,l.Value.Length==16?"DK.CommandCenter":"DK.CommandCenter.TestPreview");string sourceHash=Hash(normalized);if(!Sources.Contains(sourceHash))throw new Exception("Dashboard code hash is unreviewed; only the exact admitted host builds may receive this metadata edit.");
        string appId="DK.Dash."+Hash(Encoding.UTF8.GetBytes(edition+"|"+root.ToLowerInvariant()+"|"+Path.GetDirectoryName(receipt).ToLowerInvariant())).Substring(0,8);foreach(var l in literals)Put(updated,l,l.Value.Length==16?appId:appId+".TestPreview");bool changed=Hash(original)!=Hash(updated);string backup=null;
        if(apply&&changed){foreach(var p in Process.GetProcessesByName("DKCommandCenter")){try{if(String.Equals(Path.GetFullPath(p.MainModule.FileName),file,StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("Close this project's dashboard before updating its taskbar identity.");}catch(System.ComponentModel.Win32Exception){}finally{p.Dispose();}}
            string folder=Path.Combine(Path.GetDirectoryName(file),"branding-backups",DateTime.UtcNow.ToString("yyyyMMdd-HHmmss")+"-"+Guid.NewGuid().ToString("N").Substring(0,8));Directory.CreateDirectory(folder);backup=Path.Combine(folder,"DKCommandCenter.exe");File.Copy(file,backup);string temp=file+"."+Guid.NewGuid().ToString("N")+".tmp";try{File.WriteAllBytes(temp,updated);File.Replace(temp,file,null);}finally{if(File.Exists(temp))File.Delete(temp);}
        }
        var result=new{edition=edition,instanceRoot=root,dashboard=file,appUserModelId=appId,mode=apply?"apply":"validate",changed=changed,applied=apply,normalizedSourceSha256=sourceHash,beforeSha256=Hash(original),afterSha256=apply?Hash(File.ReadAllBytes(file)):Hash(updated),literalCount=literals.Count,backup=backup,nativeGameBinariesChanged=false};string json=new JavaScriptSerializer().Serialize(result);if(apply){Directory.CreateDirectory(Path.GetDirectoryName(receipt));File.WriteAllText(receipt,json+Environment.NewLine,new UTF8Encoding(false));}Console.WriteLine(json);return 0;
    }catch(Exception e){Console.Error.WriteLine(e.Message);return 1;}}
}
