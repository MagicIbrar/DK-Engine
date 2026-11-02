using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;

internal static class RenderDashboardIcons {
    sealed class Brand { public string Key, Label, Sub, Color; public Brand(string k,string l,string s,string c){Key=k;Label=l;Sub=s;Color=c;} }
    static readonly Brand[] Brands={new Brand("2005","2005","","#5BD9F6"),new Brand("a2","A2","","#F7C56E"),new Brand("global","GLOBAL","0.0.1","#65E3AD"),new Brand("4.2","4.2","","#BDA0FF"),new Brand("a9","A9","","#FF867B")};
    static Color Mix(Color a,Color b,float t){return Color.FromArgb(255,(int)(a.R+(b.R-a.R)*t),(int)(a.G+(b.G-a.G)*t),(int)(a.B+(b.B-a.B)*t));}
    static GraphicsPath Crest(){var p=new GraphicsPath(FillMode.Alternate);p.AddPolygon(new[]{new PointF(63,27),new PointF(140,20),new PointF(201,66),new PointF(188,133),new PointF(126,181),new PointF(58,159),new PointF(74,122),new PointF(49,137),new PointF(57,67),new PointF(80,39)});p.AddPolygon(new[]{new PointF(101,62),new PointF(132,57),new PointF(163,80),new PointF(153,119),new PointF(122,145),new PointF(98,135)});return p;}
    static void DrawLabel(Graphics g,string text,float y,float height,Color accent){
        using(var family=new FontFamily("Segoe UI"))using(var p=new GraphicsPath()){
            p.AddString(text,family,(int)FontStyle.Bold,height,new PointF(0,0),StringFormat.GenericTypographic);var box=p.GetBounds();float x=(256-box.Width)/2-box.X;using(var m=new Matrix()){m.Translate(x,y-box.Y);p.Transform(m);}using(var edge=new Pen(Color.FromArgb(220,12,19,31),4.2f)){edge.LineJoin=LineJoin.Round;g.DrawPath(edge,p);}using(var fill=new LinearGradientBrush(new RectangleF(0,y,256,height),Color.White,Mix(accent,Color.White,.25f),90)){g.FillPath(fill,p);}
        }
    }
    static Bitmap Draw(Brand b,int pixels){int scale=4;var large=new Bitmap(pixels*scale,pixels*scale,PixelFormat.Format32bppArgb);using(var g=Graphics.FromImage(large)){
        g.Clear(Color.Transparent);g.SmoothingMode=SmoothingMode.AntiAlias;g.CompositingQuality=CompositingQuality.HighQuality;g.PixelOffsetMode=PixelOffsetMode.HighQuality;g.ScaleTransform(pixels*scale/256f,pixels*scale/256f);
        Color a=ColorTranslator.FromHtml(b.Color);using(var path=Crest()){
            using(var glow=new Pen(Color.FromArgb(28,a),13)){glow.LineJoin=LineJoin.Round;g.DrawPath(glow,path);}using(var outline=new Pen(Color.FromArgb(240,14,24,38),7)){outline.LineJoin=LineJoin.Round;g.DrawPath(outline,path);}using(var fill=new LinearGradientBrush(new RectangleF(44,18,161,170),Mix(a,Color.White,.72f),Mix(a,Color.Black,.5f),62)){g.FillPath(fill,path);}using(var edge=new Pen(Mix(a,Color.White,.62f),2.5f)){edge.LineJoin=LineJoin.Round;g.DrawPath(edge,path);}
        }
        using(var facet=new GraphicsPath()){facet.AddPolygon(new[]{new PointF(64,29),new PointF(85,41),new PointF(75,119),new PointF(60,156),new PointF(67,76)});using(var f=new SolidBrush(Color.FromArgb(90,255,255,255)))g.FillPath(f,facet);}
        using(var pen=new Pen(Color.FromArgb(180,255,255,255),1.6f))g.DrawLines(pen,new[]{new PointF(84,35),new PointF(140,27),new PointF(191,67)});
        if(b.Sub.Length==0)DrawLabel(g,b.Label,200,b.Label.Length>3?34:44,a);else{DrawLabel(g,b.Label,192,29,a);DrawLabel(g,b.Sub,225,19,a);}
    }var result=new Bitmap(pixels,pixels,PixelFormat.Format32bppArgb);using(var g=Graphics.FromImage(result)){g.Clear(Color.Transparent);g.InterpolationMode=InterpolationMode.HighQualityBicubic;g.CompositingQuality=CompositingQuality.HighQuality;g.PixelOffsetMode=PixelOffsetMode.HighQuality;g.DrawImage(large,new Rectangle(0,0,pixels,pixels));}large.Dispose();return result;}
    static byte[] Png(Bitmap b){using(var m=new MemoryStream()){b.Save(m,ImageFormat.Png);return m.ToArray();}}
    static void Icon(string path,Brand b){int[] sizes={16,24,32,48,64,128,256};var payloads=new List<byte[]>();foreach(int n in sizes)using(var image=Draw(b,n))payloads.Add(Png(image));using(var s=File.Create(path))using(var w=new BinaryWriter(s)){w.Write((ushort)0);w.Write((ushort)1);w.Write((ushort)sizes.Length);int off=6+16*sizes.Length;for(int i=0;i<sizes.Length;i++){w.Write((byte)(sizes[i]==256?0:sizes[i]));w.Write((byte)(sizes[i]==256?0:sizes[i]));w.Write((byte)0);w.Write((byte)0);w.Write((ushort)1);w.Write((ushort)32);w.Write(payloads[i].Length);w.Write(off);off+=payloads[i].Length;}foreach(var p in payloads)w.Write(p);}}
    static string Svg(Brand b){return "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"256\" height=\"256\" viewBox=\"0 0 256 256\"><defs><linearGradient id=\"metal\" x2=\".6\" y2=\"1\"><stop stop-color=\"#ffffff\"/><stop offset=\".42\" stop-color=\""+b.Color+"\"/><stop offset=\"1\" stop-color=\"#24364b\"/></linearGradient></defs><path fill-rule=\"evenodd\" d=\"M63 27 140 20 201 66 188 133 126 181 58 159 74 122 49 137 57 67 80 39Z M101 62 132 57 163 80 153 119 122 145 98 135Z\" fill=\"url(#metal)\" stroke=\""+b.Color+"\" stroke-width=\"2.5\" stroke-linejoin=\"round\"/><g font-family=\"Segoe UI,Arial,sans-serif\" font-weight=\"700\" text-anchor=\"middle\" fill=\"#ffffff\" stroke=\"#111d2d\" stroke-width=\"3\" paint-order=\"stroke\"><text x=\"128\" y=\""+(b.Sub.Length==0?"237":"215")+"\" font-size=\""+(b.Sub.Length==0?(b.Label.Length>3?"34":"44"):"29")+"\">"+b.Label+"</text>"+(b.Sub.Length>0?"<text x=\"128\" y=\"243\" font-size=\"19\">"+b.Sub+"</text>":"")+"</g></svg>";}
    static void Main(string[] args){string outdir=Path.GetFullPath(args[0]);Directory.CreateDirectory(outdir);foreach(var b in Brands){using(var image=Draw(b,256))image.Save(Path.Combine(outdir,b.Key+"-dashboard.png"),ImageFormat.Png);using(var image=Draw(b,512))image.Save(Path.Combine(outdir,b.Key+"-dashboard-logo.png"),ImageFormat.Png);Icon(Path.Combine(outdir,b.Key+"-dashboard.ico"),b);File.WriteAllText(Path.Combine(outdir,b.Key+"-dashboard.svg"),Svg(b),new UTF8Encoding(false));}
        using(var preview=new Bitmap(1250,660,PixelFormat.Format32bppArgb))using(var g=Graphics.FromImage(preview)){
            g.Clear(Color.FromArgb(20,26,38));for(int row=0;row<2;row++)for(int col=0;col<5;col++){int x=col*250,y=row*330;for(int cy=0;cy<280;cy+=20)for(int cx=0;cx<250;cx+=20){int v=row==0?(cx/20+cy/20)%2==0?35:43:(cx/20+cy/20)%2==0?226:244;using(var brush=new SolidBrush(Color.FromArgb(v,v+(row==0?4:0),v+(row==0?12:0))))g.FillRectangle(brush,x+cx,y+cy,20,20);}using(var image=Draw(Brands[col],240))g.DrawImage(image,x+5,y+8);using(var font=new Font("Segoe UI",13,FontStyle.Bold))using(var brush=new SolidBrush(Color.White))g.DrawString(Brands[col].Label+(Brands[col].Sub.Length>0?" "+Brands[col].Sub:""),font,brush,x+18,y+290);}preview.Save(Path.Combine(outdir,"dashboard-icons-preview.png"),ImageFormat.Png);
        }
    }
}
