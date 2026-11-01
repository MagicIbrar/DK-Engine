using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

public static class LauncherIdentity {
    [System.Runtime.InteropServices.DllImport("shell32.dll", CharSet=System.Runtime.InteropServices.CharSet.Unicode)]
    static extern int SetCurrentProcessExplicitAppUserModelID(string id);
    public static void Initialize(){SetCurrentProcessExplicitAppUserModelID("DK.Engine.Launcher");}
    public static void Apply(Form form,string engine){
        Initialize();
        string iconPath=System.IO.Path.Combine(engine,"client-assets","dk-engine.ico");
        if(!System.IO.File.Exists(iconPath))throw new System.IO.FileNotFoundException("DK launcher icon is missing. Restore the complete engine package.");
        using(var original=new Icon(iconPath))form.Icon=(Icon)original.Clone();
        var ownedIcon=form.Icon;form.FormClosed+=delegate{ownedIcon.Dispose();};
    }
}
public static class RoundedSurface {
    public static GraphicsPath Path(RectangleF r, float radius) {
        var p = new GraphicsPath(); float d = Math.Min(radius * 2, Math.Min(r.Width, r.Height));
        p.AddArc(r.Left,r.Top,d,d,180,90);p.AddArc(r.Right-d,r.Top,d,d,270,90);
        p.AddArc(r.Right-d,r.Bottom-d,d,d,0,90);p.AddArc(r.Left,r.Bottom-d,d,d,90,90);p.CloseFigure();return p;
    }
}
// Artwork is background, never foreground Paint content replayed by child controls.
public sealed class LauncherWindow : Form {
    public Image Artwork { get; set; }
    public bool AnimatePanels { get; set; }
    public LauncherWindow(){SetStyle(ControlStyles.OptimizedDoubleBuffer|ControlStyles.AllPaintingInWmPaint|ControlStyles.ResizeRedraw,true);}
    protected override void OnPaintBackground(PaintEventArgs e){PaintBackdrop(e.Graphics);}
    public void PaintBackdrop(Graphics g){
        var r=ClientRectangle;if(r.Width<1||r.Height<1)return;
        using(var gradient=new LinearGradientBrush(r,Color.FromArgb(12,18,28),Color.FromArgb(46,20,26),35f))g.FillRectangle(gradient,r);
        if(Artwork!=null){
            float scale=Math.Max(r.Width/(float)Artwork.Width,r.Height/(float)Artwork.Height);
            float width=Artwork.Width*scale,height=Artwork.Height*scale;
            g.DrawImage(Artwork,r.Right-width,r.Top,width,height);
            using(var shade=new LinearGradientBrush(r,Color.FromArgb(60,9,12,26),Color.FromArgb(245,9,12,26),90f))g.FillRectangle(shade,r);
        }
    }
}
public static class LauncherBackdrop {
    public static string Key(Control target){
        string key=target.Width+"|"+target.Height+"|"+target.DeviceDpi;
        for(var control=target;control!=null;control=control.Parent){
            key+="|"+control.GetHashCode()+":"+control.Left+":"+control.Top+":"+control.ClientSize+":"+control.BackColor.ToArgb();
            var window=control as LauncherWindow;if(window!=null&&window.Artwork!=null)key+="|art:"+System.Runtime.CompilerServices.RuntimeHelpers.GetHashCode(window.Artwork);
        }
        return key;
    }
    public static void Paint(Control target,Graphics g){
        int x=target.Left,y=target.Top;var parent=target.Parent;
        while(parent!=null){
            var window=parent as LauncherWindow;
            if(window!=null){var state=g.Save();try{g.TranslateTransform(-x,-y);window.PaintBackdrop(g);}finally{g.Restore(state);}return;}
            var galaxy=parent as GalaxyPanel;if(galaxy!=null){var state=g.Save();try{g.TranslateTransform(-x,-y);galaxy.PaintSurface(g);}finally{g.Restore(state);}return;}
            if(parent.BackColor.A==255){using(var brush=new SolidBrush(parent.BackColor))g.FillRectangle(brush,target.ClientRectangle);return;}
            x+=parent.Left;y+=parent.Top;parent=parent.Parent;
        }
        g.Clear(SystemColors.Control);
    }
}
// A small shared sky atlas: texture generation happens once, never on a timer.
// Fine stellar points and slowly displaced dust layers give depth without flashing sparkles.
public sealed class GalaxyNightSky : IDisposable {
    struct Star {public float X,Y,Size,Depth,Phase;public bool Warm;}
    static readonly Bitmap[] clouds={Cloud(0,1f),Cloud(1,1f),Cloud(0,.36f),Cloud(1,.36f)};
    static readonly Bitmap halo=Halo();
    static readonly Star[] stars=Stars();
    Bitmap[] layers;Size layerSize;
    void PrepareLayers(Size size){
        if(layers!=null&&layerSize==size)return;
        Dispose();layerSize=size;layers=new Bitmap[clouds.Length];
        for(int i=0;i<layers.Length;i++){
            layers[i]=new Bitmap(size.Width,size.Height,System.Drawing.Imaging.PixelFormat.Format32bppPArgb);
            using(var g=Graphics.FromImage(layers[i])){g.CompositingMode=CompositingMode.SourceCopy;g.InterpolationMode=InterpolationMode.HighQualityBilinear;g.DrawImage(clouds[i],new Rectangle(0,0,size.Width,size.Height));}
        }
    }
    public void Dispose(){if(layers!=null){foreach(var layer in layers)if(layer!=null)layer.Dispose();layers=null;}}
    static float Smooth(float t){return t*t*(3-2*t);}
    static float Hash(int x,int y){unchecked{uint n=(uint)(x*374761393+y*668265263+1937);n=(n^(n>>13))*1274126177;return (n^(n>>16))/4294967295f;}}
    static float Noise(float x,float y){int ix=(int)Math.Floor(x),iy=(int)Math.Floor(y);float u=Smooth(x-ix),v=Smooth(y-iy);float a=Hash(ix,iy),b=Hash(ix+1,iy),c=Hash(ix,iy+1),d=Hash(ix+1,iy+1);return (a+(b-a)*u)*(1-v)+(c+(d-c)*u)*v;}
    static float Dust(float x,float y){return Noise(x,y)*.52f+Noise(x*2.07f+13,y*2.07f+7)*.28f+Noise(x*4.19f+5,y*4.19f+17)*.14f+Noise(x*8.31f+19,y*8.31f+11)*.06f;}
    static Bitmap Cloud(int layer,float opacity){
        const int w=384,h=128;var image=new Bitmap(w,h,System.Drawing.Imaging.PixelFormat.Format32bppPArgb);var bytes=new byte[w*h*4];
        for(int y=0;y<h;y++)for(int x=0;x<w;x++){
            float u=x/(float)(w-1),v=y/(float)(h-1);
            float noise=Dust(u*5+layer*31,v*3+layer*19);
            double spine=.50+.15*Math.Sin(u*5.2+layer*.9)+.04*Math.Sin(u*13.5);
            double distance=(v-spine)/(.22+noise*.13);
            double edge=Math.Pow(Math.Sin(u*Math.PI)*Math.Sin(v*Math.PI),.65);
            double density=Math.Exp(-distance*distance*2.8)*Math.Max(0,noise*1.75-.4)*edge;
            int at=(y*w+x)*4;
            byte alpha=(byte)Math.Min(100,density*(layer==0?88:56)*opacity);
            bytes[at]=(byte)((layer==0?185+noise*50:175+noise*56)*alpha/255);
            bytes[at+1]=(byte)((layer==0?105+noise*76:100+noise*45)*alpha/255);
            bytes[at+2]=(byte)((layer==0?62+noise*50:131+noise*66)*alpha/255);
            bytes[at+3]=alpha;
        }
        var bits=image.LockBits(new Rectangle(0,0,w,h),System.Drawing.Imaging.ImageLockMode.WriteOnly,System.Drawing.Imaging.PixelFormat.Format32bppPArgb);
        try{System.Runtime.InteropServices.Marshal.Copy(bytes,0,bits.Scan0,bytes.Length);}finally{image.UnlockBits(bits);}return image;
    }
    static Bitmap Halo(){
        var image=new Bitmap(25,25,System.Drawing.Imaging.PixelFormat.Format32bppPArgb);
        for(int y=0;y<25;y++)for(int x=0;x<25;x++){double dx=(x-12)/4.0,dy=(y-12)/4.0;int alpha=(int)(80*Math.Exp(-(dx*dx+dy*dy)*.7));image.SetPixel(x,y,Color.FromArgb(alpha,157,195,255));}return image;
    }
    static Star[] Stars(){var random=new Random(1937);var result=new Star[128];for(int i=0;i<result.Length;i++)result[i]=new Star{X=(float)random.NextDouble(),Y=(float)random.NextDouble(),Size=i%19==0?.95f:.3f+(float)random.NextDouble()*.36f,Depth=.35f+(float)random.NextDouble()*.65f,Phase=(float)random.NextDouble()*6.283f,Warm=i%13==0};return result;}
    public static void PaintBeacon(Graphics g,float x,float y){g.DrawImage(halo,new RectangleF(x-12,y-12,24,24));using(var core=new SolidBrush(Color.FromArgb(180,210,230,255)))g.FillEllipse(core,x-1,y-1,2,2);}
    public void Paint(Graphics g,RectangleF bounds,float seconds,bool enabled,Rectangle quiet){
        if(bounds.Width<2||bounds.Height<2)return;
        PrepareLayers(new Size((int)Math.Ceiling(bounds.Width)+16,(int)Math.Ceiling(bounds.Height)+10));
        var state=g.Save();try{
            g.SetClip(bounds,CombineMode.Intersect);g.InterpolationMode=InterpolationMode.Bilinear;
            for(int layer=0;layer<2;layer++){
                float x=bounds.X-8+(float)Math.Sin(seconds*.065+layer*2.7)*7;
                float y=bounds.Y-5+(float)Math.Cos(seconds*.055+layer*2.4)*4;
                var image=layers[layer+(enabled?0:2)];
                g.DrawImage(image,new RectangleF(x,y,image.Width,image.Height),new RectangleF(0,0,image.Width,image.Height),GraphicsUnit.Pixel);
            }
            int count=Math.Min(stars.Length,Math.Max(24,(int)(bounds.Width*bounds.Height/360)));
            using(var brush=new SolidBrush(Color.White))for(int i=0;i<count;i++){
                var star=stars[i];float u=(star.X+seconds*.0014f*star.Depth)%1f;
                if(u<0)u+=1;float v=star.Y+(float)Math.Sin(seconds*.09+star.Phase)*.009f;
                float x=bounds.X+u*bounds.Width,y=bounds.Y+v*bounds.Height;
                float edge=(float)Math.Min(1,Math.Max(0,Math.Min(Math.Min(u,1-u)*12,Math.Min(v,1-v)*10)));
                int alpha=(int)((enabled?172:65)*edge*(.88+.12*Math.Sin(seconds*.55+star.Phase)));
                float size=star.Size;
                if(!quiet.IsEmpty&&quiet.IntersectsWith(Rectangle.Ceiling(new RectangleF(x-5,y-5,10,10))))continue;
                if(i%19==0&&enabled)g.DrawImage(halo,new RectangleF(x-6,y-6,12,12));
                brush.Color=Color.FromArgb(Math.Max(0,Math.Min(255,alpha)),star.Warm?246:200,star.Warm?219:219,star.Warm?190:255);
                g.FillEllipse(brush,x-size,y-size,size*2,size*2);
            }
        }finally{g.Restore(state);}
    }
}
public sealed class RoundedLauncherButton : Button {
    bool hover;
    Color accentColor=Color.Empty;
    public Color AccentColor { get {return accentColor;} set {accentColor=value;Invalidate();} }
    readonly GalaxyNightSky sky=new GalaxyNightSky();
    readonly Timer animation=new Timer();
    readonly System.Diagnostics.Stopwatch clock=System.Diagnostics.Stopwatch.StartNew();
    bool animated=true;
    Bitmap glyphs,frame,backdrop;string glyphKey,backdropKey;Rectangle glyphBounds;
    public int BackdropBuilds { get; private set; }
    bool nativePainting;
    public event Action<Control,Graphics,Rectangle> NativePaintProbe;
    protected override void WndProc(ref Message m){bool previous=nativePainting;nativePainting=m.Msg==0x000f;try{base.WndProc(ref m);}finally{nativePainting=previous;}}
    public int TextRasterBuilds { get; private set; }
    public float? AnimationPhase { get; set; }
    public bool AnimationEnabled { get {return animated;} set {animated=value;UpdateAnimation();Invalidate();} }
    public float AnimationTime { get {return AnimationPhase??(animated?(float)clock.Elapsed.TotalSeconds:1.5f);} }
    public RoundedLauncherButton(){
        SetStyle(ControlStyles.UserPaint|ControlStyles.AllPaintingInWmPaint|ControlStyles.OptimizedDoubleBuffer|ControlStyles.SupportsTransparentBackColor,true);FlatStyle=FlatStyle.Flat;FlatAppearance.BorderSize=0;BackColor=Color.Transparent;
        animation.Interval=33;animation.Tick+=delegate{var form=FindForm();if(Visible&&form!=null&&form.WindowState!=FormWindowState.Minimized)Invalidate();};
    }
    void UpdateAnimation(){animation.Enabled=animated&&Visible&&IsHandleCreated;}
    protected override void OnVisibleChanged(EventArgs e){base.OnVisibleChanged(e);UpdateAnimation();}
    protected override void OnHandleCreated(EventArgs e){base.OnHandleCreated(e);UpdateAnimation();}
    protected override void OnHandleDestroyed(EventArgs e){animation.Stop();base.OnHandleDestroyed(e);}
    protected override void OnResize(EventArgs e){base.OnResize(e);if(Width>2&&Height>2)using(var p=RoundedSurface.Path(new RectangleF(0,0,Width,Height),18)){var previous=Region;Region=new Region(p);if(previous!=null)previous.Dispose();}}
    protected override void OnMouseEnter(EventArgs e){hover=true;Invalidate();base.OnMouseEnter(e);}
    protected override void OnMouseLeave(EventArgs e){hover=false;Invalidate();base.OnMouseLeave(e);}
    protected override void OnBackColorChanged(EventArgs e){if(BackColor!=Color.Transparent)BackColor=Color.Transparent;base.OnBackColorChanged(e);}
    void PrepareGlyphs(){
        Color color=Enabled?(ForeColor.GetBrightness()<.35f?Color.FromArgb(234,235,255):ForeColor):Color.FromArgb(150,165,160,151);
        string key=Text+"|"+Font.ToString()+"|"+color.ToArgb()+"|"+Width+"|"+Height+"|"+DeviceDpi;
        if(glyphs!=null&&key==glyphKey)return;
        if(glyphs!=null)glyphs.Dispose();glyphs=null;glyphKey=key;glyphBounds=Rectangle.Empty;
        if(Width<1||Height<1)return;
        glyphs=new Bitmap(Width,Height,System.Drawing.Imaging.PixelFormat.Format32bppArgb);glyphs.SetResolution(DeviceDpi,DeviceDpi);
        using(var g=Graphics.FromImage(glyphs))using(var brush=new SolidBrush(color))using(var format=new StringFormat()){
            // Grayscale alpha is independent of the animated backdrop; no ClearType subpixel colors.
            g.TextRenderingHint=System.Drawing.Text.TextRenderingHint.AntiAliasGridFit;
            format.Alignment=StringAlignment.Center;format.LineAlignment=StringAlignment.Center;format.FormatFlags=StringFormatFlags.NoWrap;
            g.DrawString(Text,Font,brush,new RectangleF(0,0,Width,Height),format);
        }
        int left=Width,top=Height,right=-1,bottom=-1;
        for(int y=0;y<Height;y++)for(int x=0;x<Width;x++)if(glyphs.GetPixel(x,y).A!=0){left=Math.Min(left,x);top=Math.Min(top,y);right=Math.Max(right,x);bottom=Math.Max(bottom,y);}
        if(right>=left)glyphBounds=Rectangle.FromLTRB(left,top,right+1,bottom+1);
        TextRasterBuilds++;
    }
    protected override void OnPaintBackground(PaintEventArgs e){
        // OnPaint writes a complete opaque surface. Never replay native parent painting
        // into WinForms' shared buffer: GDI background fills can ignore GDI+ translation.
    }
    protected override void OnPaint(PaintEventArgs e){
        if(Width<1||Height<1)return;
        if(frame==null||frame.Width!=Width||frame.Height!=Height){if(frame!=null)frame.Dispose();frame=new Bitmap(Width,Height,System.Drawing.Imaging.PixelFormat.Format32bppArgb);}
        PrepareGlyphs();
        string backgroundKey=LauncherBackdrop.Key(this);
        if(backdrop==null||backdropKey!=backgroundKey){
            if(backdrop!=null)backdrop.Dispose();backdrop=new Bitmap(Width,Height,System.Drawing.Imaging.PixelFormat.Format32bppArgb);
            using(var backgroundGraphics=Graphics.FromImage(backdrop))LauncherBackdrop.Paint(this,backgroundGraphics);
            backdropKey=backgroundKey;BackdropBuilds++;
        }
        using(var g=Graphics.FromImage(frame)){
        g.CompositingMode=CompositingMode.SourceCopy;g.DrawImageUnscaled(backdrop,0,0);g.CompositingMode=CompositingMode.SourceOver;g.SmoothingMode=SmoothingMode.AntiAlias;
        bool primary=ForeColor.GetBrightness()<.35f;
        // Feather every edge into the artwork; focus/hover brighten the fill only.
        // No contour or focus ring is drawn in any state.
        int alpha=Enabled?(hover||Focused?185:145):64;
        Color core=Color.FromArgb(alpha,primary?42:25,24,primary?72:54);
        if(!accentColor.IsEmpty)core=Color.FromArgb(Enabled?(hover||Focused?235:205):64,accentColor);
        var state=g.Save();
        using(var p=RoundedSurface.Path(new RectangleF(1,1,Width-2,Height-2),17)){
            g.SetClip(p,CombineMode.Intersect);
            using(var fill=new PathGradientBrush(p)){fill.CenterPoint=new PointF(Width/2f,Height/2f);fill.CenterColor=core;fill.SurroundColors=new[]{Color.FromArgb(0,core.R,core.G,core.B)};fill.FocusScales=new PointF(.48f,.34f);g.FillPath(fill,p);}
            var quiet=glyphBounds;if(!quiet.IsEmpty)quiet.Inflate(3,3);
            sky.Paint(g,new RectangleF(4,2,Width-8,Height-4),AnimationTime,Enabled,quiet);
        }
        g.Restore(state);
        // Composite one cached layer once, at integral coordinates, after the animation.
        if(glyphs!=null)g.DrawImageUnscaled(glyphs,0,0);
        }
        var outputState=e.Graphics.Save();try{e.Graphics.CompositingMode=CompositingMode.SourceCopy;e.Graphics.DrawImageUnscaled(frame,0,0);}finally{e.Graphics.Restore(outputState);}
        var probe=NativePaintProbe;if(nativePainting&&probe!=null)probe(this,e.Graphics,e.ClipRectangle);
    }
    protected override void Dispose(bool disposing){if(disposing){animation.Dispose();clock.Stop();sky.Dispose();if(glyphs!=null){glyphs.Dispose();glyphs=null;}if(frame!=null){frame.Dispose();frame=null;}if(backdrop!=null){backdrop.Dispose();backdrop=null;}}base.Dispose(disposing);}
}

// Only this small double-buffered surface repaints at 30 fps. No form-wide animation.
public sealed class GalaxyProgress : Control {
    readonly Timer timer = new Timer();
    readonly GalaxyNightSky sky=new GalaxyNightSky();
    readonly System.Diagnostics.Stopwatch clock = System.Diagnostics.Stopwatch.StartNew();
    int progress; float displayed; bool running; string detailText = "";
    public float DisplayedValue { get { return displayed; } }
    public float? AnimationPhase { get; set; }
    public int Value { get { return progress; } set { progress = Math.Max(0, Math.Min(100, value)); if(displayed>progress)displayed=progress;UpdateTimer();Invalidate(); } }
    public string DetailText { get { return detailText; } set { detailText = value ?? ""; Invalidate(); } }
    public bool Running { get { return running; } set { running = value; UpdateTimer(); Invalidate(); } }
    public GalaxyProgress() {
        SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.SupportsTransparentBackColor, true);
        BackColor = Color.Transparent;
        timer.Interval = 33; timer.Tick += delegate {float difference=progress-displayed;if(Math.Abs(difference)<.05f)displayed=progress;else displayed+=Math.Sign(difference)*Math.Min(5f,Math.Abs(difference)*.18f);UpdateTimer();if(Visible&&FindForm()!=null&&FindForm().WindowState!=FormWindowState.Minimized)Invalidate();};
        AccessibleName = "Preparation progress";
    }
    void UpdateTimer() { timer.Enabled = (running || Math.Abs(progress-displayed)>.01f) && Visible; }
    protected override void OnVisibleChanged(EventArgs e) { base.OnVisibleChanged(e); UpdateTimer(); }
    protected override void OnPaint(PaintEventArgs e) {
        var g = e.Graphics; g.SmoothingMode = SmoothingMode.AntiAlias;
        var state=g.Save();
        using(var round=RoundedSurface.Path(new RectangleF(1,1,Width-2,Height-2),24))g.SetClip(round,CombineMode.Intersect);
        float t = AnimationPhase ?? (running ? (float)clock.Elapsed.TotalSeconds : 1.5f);
        int left = 18, right = Math.Max(left + 1, Width - 18), trackY = Height - 23;
        float edge = left + (right - left) * displayed / 100f;
        using(var p=RoundedSurface.Path(new RectangleF(1,1,Width-2,Height-2),24))using(var brush=new PathGradientBrush(p)){brush.CenterColor=Color.FromArgb(145,25,24,54);brush.SurroundColors=new[]{Color.FromArgb(0,25,24,54)};brush.FocusScales=new PointF(.45f,.3f);g.FillPath(brush,p);}
        if (progress > 0) {
            using(var shape=RoundedSurface.Path(new RectangleF(left,1,Math.Max(1,edge-left),Height-2),22))using(var haze=new PathGradientBrush(shape)){
                haze.CenterColor=Color.FromArgb(115,130,96,225);haze.SurroundColors=new[]{Color.FromArgb(0,65,156,255)};haze.FocusScales=new PointF(.25f,.22f);g.FillPath(haze,shape);
            }
        }
        sky.Paint(g,new RectangleF(left,6,right-left,Math.Max(2,Height-34)),t,true,new Rectangle(Width/2-65,Height/2-19,130,29));
        using(var track=new LinearGradientBrush(new RectangleF(left,trackY-2,right-left,4),Color.Transparent,Color.Transparent,0f)){
            track.InterpolationColors=new ColorBlend{Colors=new[]{Color.FromArgb(0,48,76,105),Color.FromArgb(50,78,98,142),Color.FromArgb(0,48,76,105)},Positions=new[]{0f,.5f,1f}};
            using(var pen=new Pen(track,2))g.DrawLine(pen,left,trackY,right,trackY);
        }
        if (progress > 0) {
            using(var b=new LinearGradientBrush(new RectangleF(left,trackY-2,Math.Max(1,edge-left),4),Color.Transparent,Color.Transparent,0f)){
                b.InterpolationColors=new ColorBlend{Colors=new[]{Color.FromArgb(0,64,192,255),Color.FromArgb(160,115,166,255),Color.FromArgb(0,191,115,255)},Positions=new[]{0f,.65f,1f}};
                g.FillRectangle(b,left,trackY-2,edge-left,4);
            }
            GalaxyNightSky.PaintBeacon(g,edge,trackY);
        }
        using (var f = new Font("Segoe UI",12,FontStyle.Bold)) using(var b = new SolidBrush(Color.FromArgb(234,235,255))) {
            int shown=Math.Min(progress,(int)Math.Floor(displayed));if(Math.Abs(displayed-progress)<.01f)shown=progress;
            string text=detailText.Length>0?detailText:shown.ToString()+" / 100%";var size=g.MeasureString(text,f);g.DrawString(text,f,b,(Width-size.Width)/2,Height/2-17);
        }
        g.Restore(state);
    }
    protected override void Dispose(bool disposing) { if (disposing) {timer.Dispose();clock.Stop();sky.Dispose();}base.Dispose(disposing); }
}

// Keep EDIT's native text, selection, password masking, IME and caret painting.
public sealed class GalaxyTextBox : TextBox {
 [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential)] struct NativeRect {public int Left,Top,Right,Bottom;}
 [System.Runtime.InteropServices.DllImport("user32.dll",CharSet=System.Runtime.InteropServices.CharSet.Unicode)] static extern IntPtr SendMessage(IntPtr handle,int msg,IntPtr w,string text);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern IntPtr SendMessage(IntPtr handle,int msg,IntPtr w,IntPtr value);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern bool SetWindowPos(IntPtr handle,IntPtr after,int x,int y,int width,int height,uint flags);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern IntPtr GetWindowDC(IntPtr handle);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern int ReleaseDC(IntPtr handle,IntPtr dc);
 int topInset,bottomInset;bool framing;
 string hint;public string Hint {get{return hint;}set{hint=value;if(IsHandleCreated)SendMessage(Handle,0x1501,IntPtr.Zero,hint);}}
 public new BorderStyle BorderStyle {get{return BorderStyle.None;}set{base.BorderStyle=BorderStyle.None;}}
 public GalaxyTextBox(){AutoSize=false;base.BorderStyle=BorderStyle.None;BackColor=Color.FromArgb(23,27,42);ForeColor=Color.FromArgb(235,229,217);}
 protected override void OnHandleCreated(EventArgs e){base.OnHandleCreated(e);if(hint!=null)SendMessage(Handle,0x1501,IntPtr.Zero,hint);UpdateFrame();}
 void UpdateFrame(){if(!IsHandleCreated||framing)return;framing=true;try{int margin=Math.Max(8,DeviceDpi/12);SendMessage(Handle,0xD3,new IntPtr(3),new IntPtr(margin|(margin<<16)));SetWindowPos(Handle,IntPtr.Zero,0,0,0,0,0x37);UpdateOutline();Invalidate();}finally{framing=false;}}
 void UpdateOutline(){if(Width>2&&Height>2)using(var p=RoundedSurface.Path(new Rectangle(0,0,Width,Height),8)){var old=Region;Region=new Region(p);if(old!=null)old.Dispose();}}
 protected override void OnResize(EventArgs e){base.OnResize(e);UpdateFrame();}
 protected override void OnFontChanged(EventArgs e){base.OnFontChanged(e);UpdateFrame();}
 void PaintOutline(Graphics g){if(Width<2||Height<2)return;using(var fill=new SolidBrush(BackColor)){if(topInset>0)g.FillRectangle(fill,0,0,Width,topInset);if(bottomInset>0)g.FillRectangle(fill,0,Height-bottomInset,Width,bottomInset);}g.SmoothingMode=SmoothingMode.AntiAlias;using(var p=RoundedSurface.Path(new RectangleF(.75f,.75f,Width-1.5f,Height-1.5f),8))using(var pen=new Pen(Focused?Color.FromArgb(214,177,115):Color.FromArgb(82,70,111),1.5f))g.DrawPath(pen,p);}
 void PaintWindowOutline(){var dc=GetWindowDC(Handle);if(dc==IntPtr.Zero)return;try{using(var g=Graphics.FromHdc(dc))PaintOutline(g);}finally{ReleaseDC(Handle,dc);}}
 protected override void WndProc(ref Message m){
  base.WndProc(ref m);
  if(m.Msg==0x83&&m.LParam!=IntPtr.Zero){
   // Give the native single-line EDIT a centered client area. Its own text,
   // caret, selection, password masking and IME all share this same origin.
   var r=(NativeRect)System.Runtime.InteropServices.Marshal.PtrToStructure(m.LParam,typeof(NativeRect));
   int spare=Multiline?0:Math.Max(0,r.Bottom-r.Top-Font.Height);topInset=spare/2;bottomInset=spare-topInset;r.Top+=topInset;r.Bottom-=bottomInset;
   System.Runtime.InteropServices.Marshal.StructureToPtr(r,m.LParam,false);
  }else if(m.Msg==0xf||m.Msg==0x85){PaintWindowOutline();}
  else if(m.Msg==0x317&&m.WParam!=IntPtr.Zero){using(var g=Graphics.FromHdc(m.WParam))PaintOutline(g);}
  else if(m.Msg==7||m.Msg==8){Invalidate();PaintWindowOutline();}
 }
}
public sealed class GalaxyListBox : ListBox {
 protected override void OnHandleCreated(EventArgs e){base.OnHandleCreated(e);GalaxyNativeTheme.Apply(this);}
 public GalaxyListBox(){BackColor=Color.FromArgb(18,22,35);ForeColor=Color.FromArgb(235,229,217);BorderStyle=BorderStyle.None;DrawMode=DrawMode.OwnerDrawFixed;IntegralHeight=false;ItemHeight=26;}
 protected override void OnDrawItem(DrawItemEventArgs e){if(e.Index<0)return;bool selected=(e.State&DrawItemState.Selected)!=0;using(var brush=new SolidBrush(selected?Color.FromArgb(61,49,83):BackColor))e.Graphics.FillRectangle(brush,e.Bounds);TextRenderer.DrawText(e.Graphics,GetItemText(Items[e.Index]),Font,new Rectangle(e.Bounds.X+8,e.Bounds.Y,e.Bounds.Width-12,e.Bounds.Height),selected?Color.FromArgb(255,220,159):ForeColor,TextFormatFlags.VerticalCenter|TextFormatFlags.EndEllipsis|TextFormatFlags.NoPrefix);if((e.State&DrawItemState.Focus)!=0)e.DrawFocusRectangle();}
 protected override void OnFontChanged(EventArgs e){base.OnFontChanged(e);ItemHeight=Math.Max(26,Font.Height+10);}
}
public sealed class GalaxyPanel : Panel {
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern bool SystemParametersInfo(uint action,uint parameter,ref bool enabled,uint flags);
 static bool AllowsAnimation(){bool enabled=false;return !SystemInformation.HighContrast&&SystemParametersInfo(0x1042,0,ref enabled,0)&&enabled;}
 readonly Timer slideTimer;readonly System.Diagnostics.Stopwatch slideClock=new System.Diagnostics.Stopwatch();
 Point slideTarget;bool sliding,applyingSlide;
 public GalaxyPanel(){SetStyle(ControlStyles.UserPaint|ControlStyles.AllPaintingInWmPaint|ControlStyles.OptimizedDoubleBuffer|ControlStyles.ResizeRedraw,true);BackColor=Color.FromArgb(18,22,35);slideTimer=new Timer();slideTimer.Interval=15;slideTimer.Tick+=(s,e)=>AdvanceSlide();}
 void SetSlidePosition(Point position){applyingSlide=true;try{Location=position;}finally{applyingSlide=false;}}
 void FinishSlide(bool restore){if(slideTimer==null)return;slideTimer.Stop();slideClock.Stop();if(!sliding)return;sliding=false;if(restore)SetSlidePosition(slideTarget);}
 void AdvanceSlide(){if(!Visible){FinishSlide(true);return;}double t=Math.Min(1,slideClock.Elapsed.TotalMilliseconds/180);if(t>=1){FinishSlide(true);return;}int offset=(int)Math.Round(Math.Max(6,8*DeviceDpi/96.0)*Math.Pow(1-t,3));SetSlidePosition(new Point(slideTarget.X,slideTarget.Y+offset));}
 void BeginSlide(){FinishSlide(true);slideTarget=Location;sliding=true;slideClock.Restart();AdvanceSlide();slideTimer.Start();}
 protected override void OnVisibleChanged(EventArgs e){base.OnVisibleChanged(e);if(!Visible){FinishSlide(true);return;}var window=Parent as LauncherWindow;if(slideTimer==null||!IsHandleCreated||window==null||!window.Visible||!window.AnimatePanels||!AllowsAnimation())return;BeginSlide();}
 protected override void OnLocationChanged(EventArgs e){if(sliding&&!applyingSlide)FinishSlide(false);base.OnLocationChanged(e);}
 protected override void OnControlAdded(ControlEventArgs e){base.OnControlAdded(e);if(e.Control is Label||e.Control is CheckBox)e.Control.BackColor=Color.Transparent;var check=e.Control as CheckBox;if(check!=null)check.UseCompatibleTextRendering=true;}
 public void PaintSurface(Graphics g){
  if(Width<2||Height<2)return;
  // Repaint only the ancestor's background, never its labels or child controls.
  // Children resolve this same surface, so their edges meet the artwork exactly.
  LauncherBackdrop.Paint(this,g);
  var state=g.Save();try{
   g.SmoothingMode=SmoothingMode.AntiAlias;
   using(var p=RoundedSurface.Path(new RectangleF(0,0,Width,Height),14))using(var shade=new PathGradientBrush(p)){
    shade.CenterColor=Color.FromArgb(164,13,17,29);shade.SurroundColors=new[]{Color.FromArgb(0,13,17,29)};
    shade.FocusScales=new PointF(.82f,.72f);g.FillPath(shade,p);
   }
  }finally{g.Restore(state);}
 }
 protected override void OnPaintBackground(PaintEventArgs e){PaintSurface(e.Graphics);}
 protected override void OnResize(EventArgs e){base.OnResize(e);if(Width>2&&Height>2)using(var p=RoundedSurface.Path(ClientRectangle,14)){var old=Region;Region=new Region(p);if(old!=null)old.Dispose();}}
 protected override void Dispose(bool disposing){if(disposing){FinishSlide(true);if(slideTimer!=null)slideTimer.Dispose();}base.Dispose(disposing);}
}
public sealed class GalaxyComboBox : ComboBox {
 [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential)] struct ComboInfo {public int size;public Rectangle item,button;public int buttonState;public IntPtr combo,edit,list;}
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern bool GetComboBoxInfo(IntPtr handle,ref ComboInfo info);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern IntPtr GetWindowDC(IntPtr handle);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern int ReleaseDC(IntPtr handle,IntPtr dc);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern bool GetClientRect(IntPtr handle,out Rectangle rect);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern bool GetWindowRect(IntPtr handle,out Rectangle rect);
 readonly PopupSurface popup;bool sizing;
 [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential)] struct PaintData {public IntPtr dc;public int erase;public Rectangle rect;public int restore,update;[System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.ByValArray,SizeConst=32)]public byte[] reserved;}
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern IntPtr BeginPaint(IntPtr handle,out PaintData data);
 [System.Runtime.InteropServices.DllImport("user32.dll")] static extern bool EndPaint(IntPtr handle,ref PaintData data);
 public GalaxyComboBox(){popup=new PopupSurface();BackColor=Color.FromArgb(23,27,42);ForeColor=Color.FromArgb(235,229,217);FlatStyle=FlatStyle.Flat;DrawMode=DrawMode.OwnerDrawFixed;DropDownStyle=ComboBoxStyle.DropDownList;}
 protected override void OnHandleCreated(EventArgs e){base.OnHandleCreated(e);GalaxyNativeTheme.Apply(this);StylePopup();UpdateOutline();}
 protected override void OnHandleDestroyed(EventArgs e){if(popup!=null)popup.Detach();base.OnHandleDestroyed(e);}
 void StylePopup(){if(!IsHandleCreated||popup==null)return;var info=new ComboInfo();info.size=System.Runtime.InteropServices.Marshal.SizeOf(info);if(GetComboBoxInfo(Handle,ref info)&&info.list!=IntPtr.Zero){popup.Attach(info.list);GalaxyNativeTheme.Apply(info.list);}}
 protected override void OnDropDown(EventArgs e){StylePopup();base.OnDropDown(e);Invalidate();}
 protected override void SetBoundsCore(int x,int y,int width,int height,BoundsSpecified specified){if(!sizing&&(specified&BoundsSpecified.Height)!=0&&height>6){sizing=true;try{ItemHeight=Math.Max(Font.Height,height-6);}finally{sizing=false;}}base.SetBoundsCore(x,y,width,height,specified);}
 protected override void ScaleControl(SizeF factor,BoundsSpecified specified){var before=Bounds;base.ScaleControl(factor,specified);if((specified&BoundsSpecified.Size)!=0)SetBounds(Left,Top,(int)Math.Round(before.Width*factor.Width),(int)Math.Round(before.Height*factor.Height),specified&BoundsSpecified.Size);}
 void UpdateOutline(){if(Width>2&&Height>2)using(var p=RoundedSurface.Path(ClientRectangle,8)){var old=Region;Region=new Region(p);if(old!=null)old.Dispose();}}
 protected override void OnResize(EventArgs e){base.OnResize(e);UpdateOutline();}
 void PaintFace(Graphics g){if(Width<2||Height<2)return;g.SmoothingMode=SmoothingMode.AntiAlias;using(var fill=new SolidBrush(BackColor))g.FillRectangle(fill,ClientRectangle);using(var p=RoundedSurface.Path(new RectangleF(.75f,.75f,Width-1.5f,Height-1.5f),8))using(var edge=new Pen(Focused?Color.FromArgb(214,177,115):Color.FromArgb(82,70,111),1.5f))g.DrawPath(edge,p);TextRenderer.DrawText(g,SelectedItem==null?Text:GetItemText(SelectedItem),Font,new Rectangle(8,0,Math.Max(0,Width-36),Height),Enabled?ForeColor:Color.FromArgb(140,142,160),TextFormatFlags.VerticalCenter|TextFormatFlags.SingleLine|TextFormatFlags.EndEllipsis|TextFormatFlags.NoPrefix);using(var pen=new Pen(ForeColor,1.5f)){float x=Width-17,y=Height/2f;g.DrawLines(pen,new[]{new PointF(x-4,y-2),new PointF(x,y+2),new PointF(x+4,y-2)});}}
 protected override void WndProc(ref Message m){if(m.Msg==0xf){PaintData paint;var dc=BeginPaint(Handle,out paint);try{if(dc!=IntPtr.Zero)using(var g=Graphics.FromHdc(dc))PaintFace(g);}finally{EndPaint(Handle,ref paint);}m.Result=IntPtr.Zero;return;}if((m.Msg==0x317||m.Msg==0x318)&&m.WParam!=IntPtr.Zero){using(var g=Graphics.FromHdc(m.WParam))PaintFace(g);m.Result=IntPtr.Zero;return;}base.WndProc(ref m);if(m.Msg==7||m.Msg==8)Invalidate();}
 protected override void OnSelectedIndexChanged(EventArgs e){base.OnSelectedIndexChanged(e);Invalidate();}
 protected override void OnDrawItem(DrawItemEventArgs e){if(e.Bounds.Width<1||e.Bounds.Height<1)return;bool selected=(e.State&DrawItemState.Selected)!=0;using(var brush=new LinearGradientBrush(e.Bounds,selected?Color.FromArgb(61,49,83):Color.FromArgb(23,27,42),selected?Color.FromArgb(42,37,66):Color.FromArgb(29,26,44),0f))e.Graphics.FillRectangle(brush,e.Bounds);if(e.Index<0||e.Index>=Items.Count)return;var text=e.Bounds;text.X+=8;text.Width=Math.Max(0,text.Width-16);TextRenderer.DrawText(e.Graphics,GetItemText(Items[e.Index]),Font,text,Enabled?ForeColor:Color.FromArgb(140,142,160),TextFormatFlags.VerticalCenter|TextFormatFlags.SingleLine|TextFormatFlags.EndEllipsis|TextFormatFlags.NoPrefix);if((e.State&DrawItemState.Focus)!=0)ControlPaint.DrawFocusRectangle(e.Graphics,Rectangle.Inflate(e.Bounds,-2,-2),Color.FromArgb(214,177,115),Color.FromArgb(42,37,66));}
 sealed class PopupSurface : NativeWindow {
  public void Attach(IntPtr handle){if(Handle==handle)return;Detach();AssignHandle(handle);}
  public void Detach(){if(Handle!=IntPtr.Zero)ReleaseHandle();}
  void PaintBackground(IntPtr dc){Rectangle r;if(dc==IntPtr.Zero||!GetClientRect(Handle,out r)||r.Width<1||r.Height<1)return;using(var g=Graphics.FromHdc(dc))using(var fill=new LinearGradientBrush(r,Color.FromArgb(23,27,42),Color.FromArgb(29,26,44),0f))g.FillRectangle(fill,r);}
  void PaintBorder(IntPtr supplied){Rectangle r;if(!GetWindowRect(Handle,out r))return;int width=r.Width-r.X,height=r.Height-r.Y;var dc=supplied==IntPtr.Zero?GetWindowDC(Handle):supplied;if(dc==IntPtr.Zero)return;try{using(var g=Graphics.FromHdc(dc))using(var edge=new Pen(Color.FromArgb(82,70,111)))g.DrawRectangle(edge,0,0,Math.Max(0,width-1),Math.Max(0,height-1));}finally{if(supplied==IntPtr.Zero)ReleaseDC(Handle,dc);}}
  protected override void WndProc(ref Message m){if(m.Msg==0x14){PaintBackground(m.WParam);m.Result=new IntPtr(1);return;}base.WndProc(ref m);if(m.Msg==0x85)PaintBorder(IntPtr.Zero);else if(m.Msg==0x317&&m.WParam!=IntPtr.Zero)PaintBorder(m.WParam);}
 }
 protected override void Dispose(bool disposing){if(disposing&&popup!=null)popup.Detach();base.Dispose(disposing);}
}
public sealed class GalaxyNumberBox : NumericUpDown {
 public GalaxyNumberBox(){BackColor=Color.FromArgb(23,27,42);ForeColor=Color.FromArgb(235,229,217);BorderStyle=BorderStyle.FixedSingle;}
}

public static class GalaxyNativeTheme {
 [System.Runtime.InteropServices.DllImport("uxtheme.dll",CharSet=System.Runtime.InteropServices.CharSet.Unicode)] static extern int SetWindowTheme(IntPtr handle,string app,string id);
 public static void Apply(Control control){SetWindowTheme(control.Handle,"DarkMode_Explorer",null);}
 public static void Apply(IntPtr handle){SetWindowTheme(handle,"DarkMode_Explorer",null);}
}
