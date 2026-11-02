import {h} from '../core/dom.js';

// Local SVG drawings. Tiles use the shared visual direction; strokes stay dark
// on their luminous background in both themes. No font, image fetch or animation.
const INK='#182230';
const PALETTES={
 home:['#88E8D2','#77C9F3',135],connect:['#8CCFFF','#B2A7FF',35],
 accounts:['#C7AEFF','#F4B6DF',145],server:['#FFCA99','#FFAFB8',55],
 sql:['#99DCFA','#A2ADEE',155],content:['#ABE5B5','#78DAD2',25],
 gm:['#E5B8FA','#B6B2FF',125],library:['#F3D492','#EFB5CD',45],
 diagnostics:['#A8D7FF','#D1B9FF',150],settings:['#A2DED3','#B8CBDC',30]
};
const GLYPHS={
 home:'M3 10.5 12 3l9 7.5M5.5 9v11h5v-6h3v6h5V9',
 connect:'M8 3v5M16 3v5M6 8h12v3a6 6 0 0 1-12 0V8zM12 17v4',
 accounts:'M8.5 4.5a3.5 3.5 0 1 0 0 7 3.5 3.5 0 0 0 0-7M2.5 20v-1a6 6 0 0 1 12 0v1M16 5a3.5 3.5 0 0 1 0 7M17 15a5 5 0 0 1 4.5 5',
 server:'M4 3.5h16v7H4zM4 13.5h16v7H4zM7 7h.01M7 17h.01M11 7h6M11 17h6',
 sql:'M4.5 6c0-1.8 3.4-3.2 7.5-3.2s7.5 1.4 7.5 3.2-3.4 3.2-7.5 3.2S4.5 7.8 4.5 6M4.5 6v12c0 1.8 3.4 3.2 7.5 3.2s7.5-1.4 7.5-3.2V6M4.5 12c0 1.8 3.4 3.2 7.5 3.2s7.5-1.4 7.5-3.2',
 content:'M12 3 21 8v9l-9 5-9-5V8zM3 8l9 5 9-5M12 13v9M7.5 5.5l9 5',
 library:'M12 5.5C9.5 3.5 6 3 3 4v15c3-1 6.5-.5 9 1.5 2.5-2 6-2.5 9-1.5V4c-3-1-6.5-.5-9 1.5v15M6 8h3M6 11h3M15 8h3M15 11h3',
 updates:'M19.5 7A8.5 8.5 0 0 0 5 5.5L3 8M3 3.5V8h4.5M4.5 17A8.5 8.5 0 0 0 19 18.5l2-2.5M21 20.5V16h-4.5M12 7v9M8.5 12.5 12 16l3.5-3.5',
 settings:'M12 9a3 3 0 1 0 0 6 3 3 0 0 0 0-6M19.4 13.5l1.6 1.2-2 3.4-1.9-.7a7 7 0 0 1-2 1.2l-.3 2h-4l-.3-2a7 7 0 0 1-2-1.2l-1.9.7-2-3.4 1.6-1.2a7 7 0 0 1 0-3L3 9.3l2-3.4 1.9.7a7 7 0 0 1 2-1.2l.3-2h4l.3 2a7 7 0 0 1 2 1.2l1.9-.7 2 3.4-1.6 1.2a7 7 0 0 1 0 3z',
 about:'M12 3a9 9 0 1 0 0 18 9 9 0 0 0 0-18M12 7.5h.01M10.5 11H12v6M10 17h4',
 diagnostics:'M3 4h18v14H3zM8 21h8M12 18v3M5.5 11h3l2-4 3 8 2-4h3',
 gm:'M12 2.5 20 6v6c0 4.5-3.5 7.8-8 10-4.5-2.2-8-5.5-8-10V6zM8 12l2.5 2.5 5-5'
};
// 4.3.2: the Play & Connect page uses the 0.0.1 Connect tile.
const alias=id=>id==='guides'?'library':id==='play'?'connect':id;
export function navigationSpec(id){const glyph=alias(id),palette=glyph==='updates'?'diagnostics':glyph==='about'?'settings':glyph;const [from,to,angle]=PALETTES[palette]||PALETTES.settings;return{id:glyph,palette,from,to,angle,ink:INK,path:GLYPHS[glyph]||GLYPHS.about};}
export function navigationGlyph(id,size=21){const spec=navigationSpec(id);return h('svg',{class:'nav-glyph',viewBox:'0 0 24 24',preserveAspectRatio:'xMidYMid meet',width:size,height:size,fill:'none',stroke:'currentColor','stroke-width':1.75,'stroke-linecap':'round','stroke-linejoin':'round','aria-hidden':'true',focusable:'false'},h('path',{svg:true,d:spec.path}));}
export function navigationTile(id,size=21){const s=navigationSpec(id);return h('span',{class:`nav-ico nav-tile nav-tile--${s.palette}`,'data-nav-icon':s.id,'aria-hidden':'true'},navigationGlyph(id,size));}
