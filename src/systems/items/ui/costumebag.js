// Costume bag (btn_CostumeBag of the inventory): game2/inven/ui_costum_wardrobe.txt, slotbag 198x264 / 33x33 =
// 6 x 8 cells that hold costume items only (260:71 "This item cannot be stored in the costume bag.").
import { gridItems, footprintAt, itemPayload, cursorActionResult } from './common.js';
import { buildTooltip } from '../tooltip.js';

export function registerCostumeBag(sys) {
  const g = sys.game;
  let W = null;
  const render = () => {
    if (!W?.isOpen) return;
    const grid = W.control('slotbag');
    grid.setItems(gridItems(sys, grid, sys.costumeBag, 0).items);
  };
  g.uiwin.registerWindow('costumebag', {
    script: 'game2/inven/ui_costum_wardrobe.txt',
    create(win) {
      W = win;
      const grid = win.control('slotbag');
      grid._itemsRefresh = render;
      grid.setItemTooltip(it => buildTooltip(sys, it.data, { where: 'costume' }));
      grid.makeDraggable((e, gr) => {
        const c = gr.cellAt(e.clientX, e.clientY), it = c && gr.itemAt(c.x, c.y);
        return it ? itemPayload(sys, it.data, 'costume', {}, [gr.cw, gr.ch]) : null;
      });
      grid.acceptDrop({
        accept: (d) => d?.kind === 'item',
        hover: (d, e) => { const [w, h] = sys.costumeBag.sizeOf(d.itemIndex); const p = footprintAt(grid, e, w, h); grid.highlight(p.x, p.y, w, h, sys.costumeBag.accept(sys.db.def(d.itemIndex)) && sys.costumeBag.inside(p.x, p.y, w, h)); },
        leave: () => grid.highlight(null),
        drop: async (d, e) => {
          grid.highlight(null);
          const def = sys.db.def(d.itemIndex);
          if (!sys.costumeBag.accept(def)) { sys.msg(260, 71); return false; }
          const [w, h] = sys.costumeBag.sizeOf(d.itemIndex);
          const cell=grid.cellAt(e.clientX,e.clientY),target=cell&&grid.itemAt(cell.x,cell.y);
          const p = target?{x:target.x,y:target.y}:footprintAt(grid, e, w, h);
          if(d.from==='cursor'){
            const occ=sys.costumeBag.occupants(0,p.x,p.y,w,h);if(occ.length>1)return false;
            return cursorActionResult(sys,sys.cursorPlace('costume',{page:0,x:p.x,y:p.y,targetUid:occ[0]?.uid??null}));
          }
          if(g.save.authority==='server') {
            const intent=d.from==='equip'?{operation:'unequip',slot:d.slot,preset:d.preset,page:0,x:p.x,y:p.y}
              :['bag','costume'].includes(d.from)?{operation:d.from==='bag'?'deposit':'move',uid:d.uid||d.inst?.uid,page:0,x:p.x,y:p.y}:null;
            if(!intent)return !!g.network?.unavailable?.('This costume destination');
            return !!(await g.network?.action?.('costume',intent));
          }
          if (d.from === 'costume') { const r = await sys.costumeBag.moveTo(d.inst, 0, p.x, p.y); if (r && g.save.authority!=='server') sys.changed('move'); return !!r; }
          if (d.from === 'equip') return !!(await sys.unequipTo(sys.costumeBag, d.slot, d.preset, { page: 0, x: p.x, y: p.y }));
          return sys.transfer(d, sys.costumeBag, 0, p.x, p.y);
        },
      });
      grid.on('cellrclick', (c, it) => { if (it) {if(g.save.authority==='server')void g.network?.action?.('costume',{operation:'equip',uid:it.data.uid});else sys.equipItem(it.data);} });
      g.events.on('inventory', render);
    },
    onOpen(win) {
      render();
      // beside the bag (the wardrobe button sits on the bag window)
      const inv = g.uiwin.window('inventory');
      if (inv?.isOpen) win.setPosition(Math.max(0, inv.box.x - win.box.w - 4), inv.box.y + Math.max(0, inv.box.h - win.box.h));
    },
  });
}
