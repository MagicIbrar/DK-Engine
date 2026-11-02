/* Function: FUN_00ee86b0 at 00ee86b0 | UNRECOVERED | class: LogicObject::Article::Item::Cursor::Cursor */

undefined4 __fastcall FUN_00ee86b0(int param_1)

{
  if (*(char *)(param_1 + 0xc) == '\x01') {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0xc) = 0;
  }
  return 1;
}


