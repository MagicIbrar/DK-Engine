// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x720000-0x72ffff

// ==== FUN_00720110 @ 0x00720110 ====

/* WARNING: Removing unreachable block (ram,0x007201a1) */

void FUN_00720110(void)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 unaff_ESI;
  void *pvStack_74;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009906c1;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  piVar3 = (int *)(**(code **)(*DAT_00b5ac4c + 0xc))();
  if (piVar3 == (int *)0x0) {
    FUN_00401740();
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar1 = *in_ECX;
  (**(code **)(*piVar3 + 0x10))();
  (**(code **)(iVar1 + 0x10))();
  iVar1 = *DAT_00b5ac54;
  (**(code **)(*piVar3 + 8))();
  (**(code **)(iVar1 + 8))();
  FUN_00401660();
  (**(code **)(*DAT_00b5ac54 + 0x30))();
  FUN_00401660(unaff_ESI,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  iVar1 = *DAT_00b5ac54;
  uVar4 = (**(code **)(*piVar3 + 8))(1);
  (**(code **)(iVar1 + 8))(uVar4);
  ExceptionList = pvStack_74;
  return;
}


// ==== FUN_00720260 @ 0x00720260 ====

void FUN_00720260(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009906d3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ed0a4;
  FUN_0071f6e0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac48 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac48 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007202d0 @ 0x007202d0 ====

void FUN_007202d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0071f640();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007202f0 @ 0x007202f0 ====

void FUN_007202f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed350;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00720310 @ 0x00720310 ====

void FUN_00720310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed364;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac50 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac50 = in_ECX;
  return;
}


// ==== FUN_00720340 @ 0x00720340 ====

void FUN_00720340(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac50 = 0;
  *in_ECX = &PTR_FUN_009ed350;
  return;
}


// ==== FUN_00720360 @ 0x00720360 ====

int FUN_00720360(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009906f0;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009ed130,4);
  local_4 = 0;
  switch(param_2) {
  case 0:
    FUN_00403810(s_PANEL_009ed138);
    break;
  case 1:
    FUN_00403810(s_BUTTON_009ed140);
    break;
  case 2:
    FUN_00403810(&DAT_009ed148);
    break;
  case 3:
    FUN_00403810(s_PROCESSBAR_009ed150);
    break;
  case 4:
    FUN_00403810(s_VSCROLL_009ed15c);
    break;
  case 5:
    FUN_00403810(s_TREECTRL_009ed164);
    break;
  case 6:
    FUN_00403810(s_TEXTBOX_009ed170);
    break;
  case 7:
    FUN_00403810(s_SLOTCTRL_009ed178);
    break;
  case 8:
    FUN_00403810(s_LABEL_009ed184);
    break;
  case 9:
    FUN_00403810(s_PARTYSTATE_009ed18c);
    break;
  case 10:
    FUN_00403810(s_ITEMSLOT_009ed198);
    break;
  case 0xb:
    FUN_00403810(s_TABBUTTON_009ed1a4);
    break;
  case 0xc:
    FUN_00403810(s_SKILLTREE_009ed1b0);
    break;
  case 0xd:
    FUN_00403810(s_SKILLTREENODE_009ed1bc);
    break;
  case 0xe:
    FUN_00403810(s_MESSENGERTREE_009ed1cc);
    break;
  case 0xf:
    FUN_00403810(&DAT_009ed1dc);
    break;
  case 0x10:
    FUN_00403810(s_SKILLSLOT_009ed1e4);
    break;
  case 0x11:
    FUN_00403810(s_SKILLSLOTBTN_009ed1f0);
    break;
  case 0x12:
    FUN_00403810(s_QUICKSLOTCTRL_009ed200);
    break;
  case 0x13:
    FUN_00403810(s_EMOTIBUTTON_009ed210);
    break;
  case 0x14:
    FUN_00403810(s_SLIDEBAR_009ed21c);
    break;
  case 0x15:
    FUN_00403810(s_COMBOBOX_009ed228);
    break;
  case 0x16:
    FUN_00403810(s_LISTBOX_009ed234);
    break;
  case 0x17:
    FUN_00403810(s_CASEBOX_009ed23c);
    break;
  case 0x18:
    FUN_00403810(s_MAILLIST_009ed244);
    break;
  default:
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_FALSE_009ed250,5);
    local_4._0_1_ = 1;
    FUN_00406880(local_28);
    local_4 = (uint)local_4._1_3_ << 8;
    if (local_10 < 0x10) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
    _free(local_24);
    return extraout_EAX;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_44,0,0xffffffff);
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_40);
  return extraout_EAX_00;
}


// ==== FUN_00720690 @ 0x00720690 ====

int FUN_00720690(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099070a;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009ed258,4);
  local_4 = 0;
  switch(param_2) {
  case 0:
    FUN_00403810(s_PRESSED_009ed260);
    break;
  case 1:
    FUN_00403810(s_CLICKED_009ed268);
    break;
  case 2:
    FUN_00403810(s_RCLICKED_009ed270);
    break;
  case 3:
    FUN_00403810(s_MOUSELUP_009ed27c);
    break;
  case 4:
    FUN_00403810(s_ENTER_009ed288);
    break;
  case 5:
    FUN_00403810(s_LEAVE_009ed290);
    break;
  case 6:
    FUN_00403810(s_UPDATE_009ed298);
    break;
  case 7:
    FUN_00403810(&DAT_009ed2a0);
    break;
  case 8:
    FUN_00403810(s_QUESTTITLE_009ed2a8);
    break;
  case 9:
    FUN_00403810(s_QUESTSUB_009ed2b4);
    break;
  case 10:
    FUN_00403810(&DAT_009ed2c0);
    break;
  case 0xb:
    FUN_00403810(&DAT_009ed2c8);
    break;
  case 0xc:
    FUN_00403810(s_WHISPER_009ed2d0);
    break;
  case 0xd:
    FUN_00403810(s_STACKCOUNT_009ed2d8);
    break;
  default:
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_FALSE_009ed2e4,5);
    local_4._0_1_ = 1;
    FUN_00406880(local_28);
    local_4 = (uint)local_4._1_3_ << 8;
    if (local_10 < 0x10) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
    _free(local_24);
    return extraout_EAX;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_44,0,0xffffffff);
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_40);
  return extraout_EAX_00;
}


// ==== FUN_007208c0 @ 0x007208c0 ====

void FUN_007208c0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  uint uStack_54;
  char acStack_50 [68];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099071c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  FUN_00401660();
  FUN_00401660();
  FUN_00401660();
  FUN_00401660();
  FUN_00401660();
  cVar1 = (**(code **)(*param_1 + 0xc))();
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 == 0x40001) {
      __itoa(param_1[1],acStack_50,10);
      FUN_00401740();
      FUN_00401740(&DAT_009ed334,2);
      FUN_00404230(auStack_6c);
      uStack_4 = 0;
      FUN_00401660();
      if (0xf < uStack_54) {
        _free(pvStack_68);
        return;
      }
    }
    else if (iVar2 == 0x70030002) {
      FUN_00401740();
      ExceptionList = pvStack_c;
      return;
    }
  }
  else {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 == 0x20001) {
      if (param_1[1] == 9) {
        FUN_00401740();
        ExceptionList = pvStack_c;
        return;
      }
      if (param_1[1] == 0xd) {
        FUN_00403810();
        ExceptionList = pvStack_c;
        return;
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00720a90 @ 0x00720a90 ====

void FUN_00720a90(byte param_1)

{
  void *in_ECX;
  
  FUN_00720340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00720ab0 @ 0x00720ab0 ====

void FUN_00720ab0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed404;
  return;
}


// ==== FUN_00720ac0 @ 0x00720ac0 ====

void FUN_00720ac0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed404;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00720ae0 @ 0x00720ae0 ====

void FUN_00720ae0(void)

{
  int in_ECX;
  
  FUN_007bbda0(*(undefined4 *)(in_ECX + 4));
  return;
}


// ==== FUN_00720af0 @ 0x00720af0 ====

void FUN_00720af0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_007bdd40(param_1,param_2);
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00720b10 @ 0x00720b10 ====

void FUN_00720b10(void)

{
  int in_ECX;
  
  FUN_007bcb60(*(undefined4 *)(in_ECX + 4),0);
  return;
}


// ==== FUN_00720b20 @ 0x00720b20 ====

void FUN_00720b20(void)

{
  int in_ECX;
  
  FUN_007bbdf0(*(undefined4 *)(in_ECX + 4),0);
  return;
}


// ==== FUN_00720b30 @ 0x00720b30 ====

int FUN_00720b30(void)

{
  int in_ECX;
  float10 fVar1;
  
  FUN_007bbba0(*(undefined4 *)(in_ECX + 4),0xffffffff);
  fVar1 = (float10)FUN_007bc1a0(*(undefined4 *)(in_ECX + 4),0xffffffff);
  FUN_007bbdf0(*(undefined4 *)(in_ECX + 4),0xfffffffe);
  return (int)ROUND(fVar1);
}


// ==== FUN_00720b90 @ 0x00720b90 ====

void FUN_00720b90(int param_1)

{
  int in_ECX;
  
  FUN_007bc400(*(undefined4 *)(in_ECX + 4),(double)param_1);
  return;
}


// ==== FUN_00720bb0 @ 0x00720bb0 ====

void FUN_00720bb0(undefined1 param_1)

{
  int in_ECX;
  
  FUN_007bc5d0(*(undefined4 *)(in_ECX + 4),param_1);
  return;
}


// ==== FUN_00720bd0 @ 0x00720bd0 ====

void FUN_00720bd0(undefined4 param_1)

{
  FUN_007bc710(param_1);
  FUN_007bc710(param_1);
  FUN_007bc420(param_1,s___index_009ed3e4,7);
  FUN_007bbf60(param_1,0xffffd8ef);
  FUN_007bc810(param_1,0xfffffffd);
  FUN_007bc910(param_1,0xfffffffe);
  FUN_007bbf10(param_1,0xffffd8ef);
  return;
}


// ==== FUN_00720c20 @ 0x00720c20 ====

void FUN_00720c20(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990738;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ed45c;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a6bc + 8))();
  in_ECX[1] = uVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac54 = (undefined4 *)0x0;
    ExceptionList = pvStack_c;
    return;
  }
  DAT_00b5ac54 = in_ECX;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00720ca0 @ 0x00720ca0 ====

void FUN_00720ca0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac54 = 0;
  *in_ECX = &PTR_FUN_009ed404;
  return;
}


// ==== FUN_00720cc0 @ 0x00720cc0 ====

void FUN_00720cc0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  FUN_007bc470(*(undefined4 *)(in_ECX + 4),puVar1);
  FUN_007bc540(*(undefined4 *)(in_ECX + 4),in_stack_00000020,0);
  FUN_007bc810(*(undefined4 *)(in_ECX + 4),0xffffd8ef);
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00720d20 @ 0x00720d20 ====

void FUN_00720d20(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  uint in_stack_0000001c;
  int in_stack_00000020;
  
  FUN_007bc400(*(undefined4 *)(in_ECX + 4),(double)in_stack_00000020);
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  FUN_007bc470(*(undefined4 *)(in_ECX + 4),puVar1);
  FUN_007bbeb0(*(undefined4 *)(in_ECX + 4),0xfffffffe);
  FUN_007bc810(*(undefined4 *)(in_ECX + 4),0xffffd8ef);
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00720d90 @ 0x00720d90 ====

undefined4 FUN_00720d90(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  uint in_stack_0000001c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099074a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  ExceptionList = &pvStack_c;
  FUN_007bc470(in_ECX[1],puVar1);
  FUN_007bc620(in_ECX[1],0xffffd8ef);
  uVar2 = (**(code **)(*in_ECX + 0x38))();
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return uVar2;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_00720e10 @ 0x00720e10 ====

void FUN_00720e10(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  uint in_stack_0000001c;
  
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  FUN_007bc470(*(undefined4 *)(in_ECX + 4),puVar1);
  FUN_007bc620(*(undefined4 *)(in_ECX + 4),0xffffd8ef);
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00720e60 @ 0x00720e60 ====

void FUN_00720e60(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  uint in_stack_0000001c;
  
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  FUN_007bc470(*(undefined4 *)(in_ECX + 4),puVar1);
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00720ea0 @ 0x00720ea0 ====

/* WARNING: Removing unreachable block (ram,0x0072123a) */

void FUN_00720ea0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_98 [4];
  void *local_94;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c [4];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990795;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_007bbde0();
  FUN_00401740();
  FUN_00404230();
  local_4._0_1_ = 2;
  FUN_00401660();
  local_4 = CONCAT31(local_4._1_3_,1);
  if (0xf < local_80) {
    _free(local_94);
    return;
  }
  iVar3 = 1;
  iVar1 = FUN_007bbde0();
  if (0 < iVar1) {
    do {
      uVar2 = FUN_007bbfa0();
      switch(uVar2) {
      case 0:
      case 1:
      case 5:
      case 6:
      case 7:
      case 8:
        FUN_007bc1f0();
        FUN_007bbfa0();
        FUN_007bbfd0();
        FUN_00401740(s___d__s__d_009ed384,0xb);
        FUN_00404230(local_7c);
        local_4._0_1_ = 3;
        FUN_00401660();
        local_4 = CONCAT31(local_4._1_3_,1);
        if (0xf < local_64) {
          _free(local_78);
          return;
        }
        local_64 = 0xf;
        local_68 = 0;
        local_78 = (void *)((uint)local_78 & 0xffffff00);
        break;
      case 2:
        FUN_007bbfa0();
        FUN_007bbfd0();
        FUN_00401740(s___d__s__009ed390);
        FUN_00404230();
        local_4._0_1_ = 4;
        FUN_00401660();
        local_4 = CONCAT31(local_4._1_3_,1);
        if (0xf < local_48) {
          _free(local_5c);
          return;
        }
        local_48 = 0xf;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffffff00);
        break;
      case 3:
        FUN_007bc1a0();
        FUN_007bbfa0();
        FUN_007bbfd0();
        FUN_00401740(s___d__s__d_009ed39c,0xb);
        FUN_00404230(local_44);
        local_4._0_1_ = 5;
        FUN_00401660();
        local_4 = CONCAT31(local_4._1_3_,1);
        if (0xf < local_2c) {
          _free(local_40);
          return;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        break;
      case 4:
        FUN_007bc230();
        FUN_007bbfa0();
        FUN_007bbfd0();
        FUN_00401740(s___d__s__s_009ed3a8,0xb);
        FUN_00404230(local_98);
        local_4._0_1_ = 6;
        FUN_00401660();
        local_4 = CONCAT31(local_4._1_3_,1);
        if (0xf < local_80) {
          _free(local_94);
          return;
        }
        local_80 = 0xf;
        local_84 = 0;
        local_94 = (void *)((uint)local_94 & 0xffffff00);
      }
      iVar3 = iVar3 + 1;
      iVar1 = FUN_007bbde0();
    } while (iVar3 <= iVar1);
  }
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_007212b0 @ 0x007212b0 ====

int FUN_007212b0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int extraout_EAX;
  int in_ECX;
  char *pcVar3;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009907a7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_007bbad0(*(undefined4 *)(in_ECX + 4),0xffffffff,0);
  pcVar2 = (char *)FUN_007bc230(*(undefined4 *)(in_ECX + 4),0xffffffff);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  local_4 = 0;
  FUN_007bbdf0(*(undefined4 *)(in_ECX + 4),0xfffffffe);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00721380 @ 0x00721380 ====

uint FUN_00721380(void)

{
  code *pcVar1;
  int iVar2;
  uint extraout_EAX;
  uint uVar3;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009907b9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_007bbfa0(*(undefined4 *)(in_ECX + 4),0xffffffff);
  if (iVar2 == 1) {
    iVar2 = FUN_007bc1f0(*(undefined4 *)(in_ECX + 4),0xffffffff);
    FUN_007bbdf0(*(undefined4 *)(in_ECX + 4),0xfffffffe);
    ExceptionList = local_c;
    return (uint)(iVar2 == 1);
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_FALSE_009ed3dc,5);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00721440 @ 0x00721440 ====

void FUN_00721440(int param_1)

{
  char cVar1;
  code *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcVar5;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009907db;
  local_c = ExceptionList;
  if (param_1 == 0) {
    return;
  }
  ExceptionList = &local_c;
  pcVar3 = (char *)FUN_007bc230(*(undefined4 *)(in_ECX + 4),0xffffffff);
  local_2c = 0xf;
  local_30 = 0;
  local_40 = 0;
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  local_4 = 0;
  uVar4 = FUN_004022a0(local_28,s_Lua_motion_macro_lua_error__009ed3b4,local_44);
  local_4._0_1_ = 1;
  FUN_00796d50(uVar4);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_FALSE_009ed3d4,5);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00721560 @ 0x00721560 ====

void FUN_00721560(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 uStack00000028;
  uint in_stack_0000003c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009907f5;
  local_c = ExceptionList;
  local_4 = 1;
  puVar3 = uStack00000028;
  if (in_stack_0000003c < 0x10) {
    puVar3 = &uStack00000028;
  }
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  ExceptionList = &local_c;
  uVar2 = FUN_007bb860(*(undefined4 *)(in_ECX + 4),puVar1,in_stack_00000020,puVar3);
  FUN_00721440(uVar2);
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  in_stack_0000001c = 0xf;
  in_stack_00000018 = 0;
  param_2 = (undefined4 *)((uint)param_2 & 0xffffff00);
  if (in_stack_0000003c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(uStack00000028);
  return;
}


// ==== FUN_00721610 @ 0x00721610 ====

void FUN_00721610(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 uStack0000002c;
  uint in_stack_00000040;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099080f;
  local_c = ExceptionList;
  local_4 = 1;
  puVar3 = uStack0000002c;
  if (in_stack_00000040 < 0x10) {
    puVar3 = &uStack0000002c;
  }
  puVar1 = param_3;
  if (in_stack_00000020 < 0x10) {
    puVar1 = &param_3;
  }
  ExceptionList = &local_c;
  uVar2 = FUN_007bb860(param_1,puVar1,in_stack_00000024,puVar3);
  FUN_00721440(uVar2);
  if (0xf < in_stack_00000020) {
    _free(param_3);
    return;
  }
  in_stack_00000020 = 0xf;
  in_stack_0000001c = 0;
  param_3 = (undefined4 *)((uint)param_3 & 0xffffff00);
  if (in_stack_00000040 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(uStack0000002c);
  return;
}


// ==== FUN_007216c0 @ 0x007216c0 ====

void FUN_007216c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_007bca30(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
  FUN_00721440(uVar1);
  return;
}


// ==== FUN_007216f0 @ 0x007216f0 ====

void FUN_007216f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00720ca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00721710 @ 0x00721710 ====

undefined1 FUN_00721710(undefined2 *param_1)

{
  int in_ECX;
  
  if (*(byte *)(in_ECX + 0x10) < 2) {
    *(undefined2 *)(in_ECX + 0x11) = *param_1;
    *(undefined1 *)(in_ECX + 0x13) = *(undefined1 *)(param_1 + 1);
    *(byte *)(in_ECX + 0x10) = *(byte *)(in_ECX + 0x10) + 1;
    return 1;
  }
  return 0;
}


// ==== FUN_00721740 @ 0x00721740 ====

void FUN_00721740(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed4f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00721760 @ 0x00721760 ====

undefined4 FUN_00721760(undefined2 *param_1,uint param_2)

{
  undefined2 *puVar1;
  int in_ECX;
  
  if (param_2 < 6) {
    puVar1 = (undefined2 *)(in_ECX + param_2 * 3);
    *puVar1 = *param_1;
    *(undefined1 *)(puVar1 + 1) = *(undefined1 *)(param_1 + 1);
    *(char *)(in_ECX + 0xf) = *(char *)(in_ECX + 0xf) + '\x01';
    return 1;
  }
  return 0;
}


// ==== FUN_007217a0 @ 0x007217a0 ====

void FUN_007217a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed4fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0ec = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0ec = in_ECX;
  return;
}


// ==== FUN_00721800 @ 0x00721800 ====

void FUN_00721800(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b0ec = 0;
  *in_ECX = &PTR_FUN_009ed4f0;
  return;
}


// ==== FUN_00721820 @ 0x00721820 ====

void FUN_00721820(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int unaff_retaddr;
  undefined1 *puStack_a4;
  undefined1 auStack_a0 [4];
  undefined1 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int *piStack_88;
  int *piStack_84;
  void *pvStack_5c;
  void *pvStack_58;
  uint uStack_48;
  void *pvStack_44;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_1c;
  undefined1 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990878;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  uVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  uVar1 = *(undefined1 *)(unaff_retaddr + 0x10);
  (**(code **)(*DAT_00b5b0f0 + 0x40))();
  uStack_34 = 0xf;
  uStack_38 = 0;
  uStack_48 = uStack_48 & 0xffffff00;
  piStack_84 = (int *)0x72188e;
  FUN_00401740();
  pvStack_c = (void *)0x0;
  (**(code **)(*DAT_00b5b0f0 + 0x3c))();
  switch(uVar1) {
  case 0:
    piStack_84 = (int *)0x7218c0;
    (**(code **)(*DAT_00b5b0f0 + 0x3c))();
    piStack_84 = (int *)0x7218c9;
    FUN_00721f80();
    piStack_84 = (int *)0x7218d4;
    uVar4 = (**(code **)(*DAT_00b5b0f4 + 0x10))();
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        piStack_88 = (int *)0x7218ec;
        piStack_84 = (int *)uVar6;
        piVar5 = (int *)(**(code **)(*DAT_00b5b0f4 + 0xc))();
        if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
          piStack_88 = piVar5 + 1;
          uStack_8c = 0x721902;
          piStack_84 = (int *)uVar6;
          FUN_00721760();
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    piStack_84 = (int *)0x721914;
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5b0f4 + 4))();
    piStack_84 = (int *)*puVar3;
    piStack_88 = (int *)0x721936;
    FUN_008282a0();
    piStack_84 = (int *)0x721944;
    piStack_84 = (int *)(**(code **)(*DAT_00b5b0f4 + 8))();
    if ((piStack_84 != (int *)0x0) && (*piStack_84 != 0)) {
      piStack_84 = piStack_84 + 1;
      piStack_88 = (int *)0x721959;
      FUN_00721710();
    }
    piStack_84 = (int *)(auStack_40 + -0x2c);
    uStack_8c = 0x721968;
    FUN_008281d0();
    piStack_84 = (int *)0x721976;
    (**(code **)(*DAT_00b5b0f4 + 0x20))();
    piStack_84 = (int *)0x3e90023;
    piStack_88 = (int *)0x0;
    uStack_8c = 0x721987;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_8c = 0xffffffff;
    uStack_90 = 0;
    uStack_28 = 0xf;
    uStack_2c = 0;
    auStack_3c[0] = 0;
    uStack_98 = 0x7219a0;
    FUN_00401660();
    uStack_1c = CONCAT31(uStack_1c._1_3_,1);
    break;
  case 1:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721b8e;
    piStack_88 = (int *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_8c = 0x721b98;
    FUN_00765c50();
    puStack_10 = auStack_a0;
    puStack_a4 = auStack_3c;
    uStack_18 = 4;
    FUN_00765c50();
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_38 = uStack_38 & 0xffffff00;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
  case 3:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721be1;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    piStack_88 = (int *)0xffffffff;
    uStack_8c = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffffff00;
    uStack_94 = 0x721bfa;
    FUN_00401660();
    puStack_10 = auStack_a0;
    puStack_a4 = (undefined1 *)0xffffffff;
    piStack_88 = (int *)0xf;
    uStack_8c = 0;
    uStack_18 = 5;
    uStack_9c = 0;
    FUN_00401660(auStack_3c,0);
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_38 = uStack_38 & 0xffffff00;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721b2b;
    piStack_88 = (int *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_8c = 0x721b35;
    FUN_00765c50();
    puStack_10 = auStack_a0;
    puStack_a4 = auStack_3c;
    uStack_18 = 3;
    FUN_00765c50();
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_38 = uStack_38 & 0xffffff00;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 5:
  case 7:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721c4f;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    piStack_88 = (int *)0xffffffff;
    uStack_8c = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffffff00;
    uStack_94 = 0x721c68;
    FUN_00401660();
    puStack_10 = auStack_a0;
    puStack_a4 = (undefined1 *)0xffffffff;
    piStack_88 = (int *)0xf;
    uStack_8c = 0;
    uStack_18 = 6;
    uStack_9c = 0;
    FUN_00401660(auStack_3c,0);
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    puStack_10 = (undefined1 *)((uint)puStack_10 & 0xffffff00);
    if (0xf < uStack_1c) {
      piStack_84 = (int *)0x721cb3;
      _free(pvStack_30);
      return;
    }
  case 6:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721cc7;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    piStack_88 = (int *)0xffffffff;
    uStack_8c = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffffff00;
    uStack_94 = 0x721ce0;
    FUN_00401660();
    puStack_10 = auStack_a0;
    puStack_a4 = (undefined1 *)0xffffffff;
    piStack_88 = (int *)0xf;
    uStack_8c = 0;
    uStack_18 = 7;
    uStack_9c = 0;
    FUN_00401660(auStack_3c,0);
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    puStack_10 = (undefined1 *)((uint)puStack_10 & 0xffffff00);
    if (0xf < uStack_1c) {
      piStack_84 = (int *)0x721d2b;
      _free(pvStack_30);
      return;
    }
  case 8:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721d3f;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    piStack_88 = (int *)0xffffffff;
    uStack_8c = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffffff00;
    uStack_94 = 0x721d58;
    FUN_00401660();
    puStack_10 = auStack_a0;
    puStack_a4 = (undefined1 *)0xffffffff;
    piStack_88 = (int *)0xf;
    uStack_8c = 0;
    uStack_18 = 8;
    uStack_9c = 0;
    FUN_00401660(auStack_3c,0);
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    puStack_10 = (undefined1 *)((uint)puStack_10 & 0xffffff00);
    if (0xf < uStack_1c) {
      piStack_84 = (int *)0x721da3;
      _free(pvStack_30);
      return;
    }
  case 9:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721db7;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    piStack_88 = (int *)0xffffffff;
    uStack_8c = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffffff00;
    uStack_94 = 0x721dd0;
    FUN_00401660();
    puStack_10 = auStack_a0;
    puStack_a4 = (undefined1 *)0xffffffff;
    piStack_88 = (int *)0xf;
    uStack_8c = 0;
    uStack_18 = 9;
    uStack_9c = 0;
    FUN_00401660(auStack_3c,0);
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    puStack_10 = (undefined1 *)((uint)puStack_10 & 0xffffff00);
    if (0xf < uStack_1c) {
      piStack_84 = (int *)0x721e1b;
      _free(pvStack_30);
      return;
    }
  default:
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721e2f;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    piStack_88 = (int *)0xffffffff;
    uStack_8c = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffffff00;
    uStack_94 = 0x721e48;
    FUN_00401660();
    puStack_10 = auStack_a0;
    puStack_a4 = (undefined1 *)0xffffffff;
    piStack_88 = (int *)0xf;
    uStack_8c = 0;
    uStack_18 = 10;
    uStack_9c = 0;
    FUN_00401660(auStack_3c,0);
    puStack_a4 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_38 = uStack_38 & 0xffffff00;
    if ((void *)0xf < pvStack_44) {
      _free(pvStack_58);
      return;
    }
    (**(code **)(*DAT_00b5b0f4 + 0x20))();
    goto LAB_007219fb;
  case 10:
    FUN_00721f80();
    uVar4 = (**(code **)(*DAT_00b5b0f4 + 0x10))();
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        piStack_84 = (int *)0x721a5c;
        piVar5 = (int *)(**(code **)(*DAT_00b5b0f4 + 0xc))();
        if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
          piStack_84 = piVar5 + 1;
          piStack_88 = (int *)0x721a72;
          FUN_00721760();
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    (**(code **)(*DAT_00b5b0f4 + 4))();
    piStack_84 = (int *)0x721aa6;
    FUN_00828190();
    piVar5 = (int *)(**(code **)(*DAT_00b5b0f4 + 8))();
    if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
      piStack_84 = (int *)0x721ac9;
      FUN_00721710();
    }
    piStack_88 = (int *)0x721ad8;
    FUN_008281d0();
    (**(code **)(*DAT_00b5b0f4 + 0x20))();
    piStack_84 = (int *)0x0;
    piStack_88 = (int *)0x721af7;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_8c = 0xffffffff;
    uStack_90 = 0;
    uStack_28 = 0xf;
    uStack_2c = 0;
    auStack_3c[0] = 0;
    uStack_98 = 0x721b10;
    FUN_00401660();
    uStack_1c = CONCAT31(uStack_1c._1_3_,2);
  }
  puStack_14 = (undefined1 *)&puStack_a4;
  uStack_8c = 0xf;
  uStack_90 = 0;
  auStack_a0[0] = 0;
  FUN_00401660(auStack_40,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  auStack_3c[0] = 0;
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  (**(code **)(*DAT_00b5a790 + 4))();
LAB_007219fb:
  (**(code **)(*DAT_00b5b0f0 + 8))();
  if (uVar2 < 0x10) {
    ExceptionList = pvStack_44;
    return;
  }
  _free((void *)0x1);
  return;
}


// ==== FUN_00721ee0 @ 0x00721ee0 ====

undefined4 FUN_00721ee0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x51e0000) {
    (**(code **)(*DAT_00b5b0f0 + 0xc))();
    return 1;
  }
  if (iVar1 == 0x51e0002) {
    FUN_00721820(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x51e0004) {
    (**(code **)(*DAT_00b5b0f4 + 0x20))();
    (**(code **)(*DAT_00b5b0f0 + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_00721f50 @ 0x00721f50 ====

undefined4 FUN_00721f50(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00721ee0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00721f80 @ 0x00721f80 ====

void FUN_00721f80(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  return;
}


// ==== FUN_00721fe0 @ 0x00721fe0 ====

void FUN_00721fe0(byte param_1)

{
  void *in_ECX;
  
  FUN_00721800();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00722000 @ 0x00722000 ====

void FUN_00722000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed5f4;
  return;
}


// ==== FUN_00722010 @ 0x00722010 ====

void FUN_00722010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed5f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00722030 @ 0x00722030 ====

undefined1 FUN_00722030(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00722050 @ 0x00722050 ====

void FUN_00722050(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ed66c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00722080 @ 0x00722080 ====

void FUN_00722080(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ed644;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 4) = 1;
  cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a78c + 0x24))();
  }
  (**(code **)(*DAT_00b5a78c + 0x60))(8);
  (**(code **)(*DAT_00b5acd4 + 4))(9);
  return;
}


// ==== FUN_007220e0 @ 0x007220e0 ====

void FUN_007220e0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x20))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ed658;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 1) = 0;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_00722130 @ 0x00722130 ====

void FUN_00722130(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00722149. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5b0f4 + 0x20))();
    return;
  }
  return;
}


// ==== FUN_00722150 @ 0x00722150 ====

bool FUN_00722150(void)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*in_ECX + 0x2c))();
    return iVar2 != 0;
  }
  return false;
}


// ==== FUN_00722180 @ 0x00722180 ====

undefined4 FUN_00722180(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  uint uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x2c))();
  if ((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) {
    iVar3 = (**(code **)(*piVar2 + 0x2c))();
    uVar1 = *(ushort *)(iVar3 + 0x28);
    iVar3 = (**(code **)(*piVar2 + 0x14))();
    uStack_8 = (uint)*(byte *)(iVar3 + 0x1f);
    uStack_4 = (uint)uVar1;
    piVar2 = (int *)(**(code **)(*DAT_00b5aa28 + 8))(&uStack_8);
    if (piVar2 != (int *)0x0) {
      puVar4 = (undefined4 *)(**(code **)(*piVar2 + 4))();
      return *puVar4;
    }
  }
  return 0;
}


// ==== FUN_007221e0 @ 0x007221e0 ====

void FUN_007221e0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007221e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0f4 + 4))();
  return;
}


// ==== FUN_007221f0 @ 0x007221f0 ====

void FUN_007221f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007221f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0f4 + 8))();
  return;
}


// ==== FUN_00722200 @ 0x00722200 ====

void FUN_00722200(void)

{
                    /* WARNING: Could not recover jumptable at 0x00722208. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0f4 + 0xc))();
  return;
}


// ==== FUN_00722210 @ 0x00722210 ====

void FUN_00722210(void)

{
                    /* WARNING: Could not recover jumptable at 0x00722218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0f4 + 0x10))();
  return;
}


// ==== FUN_00722220 @ 0x00722220 ====

void FUN_00722220(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x51e0003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00722260 @ 0x00722260 ====

undefined4 FUN_00722260(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_itemaddsocketwnd_009ed5a0,0x15);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_itemaddsocketwnd_009ed5b8,0x15);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_007222c0 @ 0x007222c0 ====

undefined4 FUN_007222c0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00722260(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007222f0 @ 0x007222f0 ====

void FUN_007222f0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  void *local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009908b8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ed684;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0f0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b0f0 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009ed53e,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_itemaddsocketwnd_009ed540,0x15);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009ed556,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_itemaddsocketwnd_009ed558,0x15);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_ESI);
    return;
  }
  local_44 = 0xf;
  if (local_28 < 0x10) {
    *(undefined1 *)(in_ECX + 1) = 0;
    *(undefined1 *)((int)in_ECX + 5) = 0;
    *(undefined1 *)((int)in_ECX + 6) = 0;
    in_ECX[2] = 0;
    ExceptionList = local_24;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_00722480 @ 0x00722480 ====

void FUN_00722480(void)

{
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009908da;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ed684;
  local_4 = 0;
  DAT_00b5b0f0 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_itemaddsocketwnd_009ed570,0x15);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = (void *)0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_itemaddsocketwnd_009ed588,0x15);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009ed5f4;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00722560 @ 0x00722560 ====

void FUN_00722560(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *in_ECX;
  undefined1 auStack_aa [2];
  void *pvStack_a8;
  uint uStack_94;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099091d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x2c))();
    if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
      uVar3 = (**(code **)(*in_ECX + 0x28))();
      uVar4 = (**(code **)(*DAT_00b5a78c + 0x40))();
      if (uVar4 < uVar3) {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00765c50();
        FUN_00765c50(auStack_aa + -10);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      puStack_8 = (undefined1 *)0x3;
      FUN_00403810();
      FUN_00401830();
      FUN_00404230();
      puStack_8._0_1_ = 4;
      FUN_00401660();
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_10 = (void *)0x0;
    FUN_00401660(auStack_aa + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007228e0 @ 0x007228e0 ====

undefined4 FUN_007228e0(void)

{
  return 0x70370000;
}


// ==== FUN_007228f0 @ 0x007228f0 ====

undefined4 FUN_007228f0(void)

{
  return 0x70370001;
}


// ==== FUN_00722900 @ 0x00722900 ====

undefined4 FUN_00722900(void)

{
  return 0x70370002;
}


// ==== FUN_00722910 @ 0x00722910 ====

void FUN_00722910(byte param_1)

{
  void *in_ECX;
  
  FUN_00722480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00722930 @ 0x00722930 ====

void FUN_00722930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed714;
  return;
}


// ==== FUN_00722940 @ 0x00722940 ====

void FUN_00722940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed714;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00722960 @ 0x00722960 ====

undefined4 FUN_00722960(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00722970 @ 0x00722970 ====

undefined4 FUN_00722970(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_00722980 @ 0x00722980 ====

void FUN_00722980(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_007229a0 @ 0x007229a0 ====

int FUN_007229a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2;
}


// ==== FUN_007229c0 @ 0x007229c0 ====

void FUN_007229c0(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00722a20 @ 0x00722a20 ====

void FUN_00722a20(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00722a80 @ 0x00722a80 ====

byte FUN_00722a80(void)

{
  char cVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  byte bVar7;
  uint uStack_8;
  uint uStack_4;
  
  bVar4 = 0;
  if (in_ECX[1] != 0) {
    piVar5 = (int *)(**(code **)(**(int **)in_ECX[1] + 0x48))();
    iVar6 = (**(code **)(*piVar5 + 4))();
    uVar2 = *(ushort *)(iVar6 + 0x2c);
    iVar6 = (**(code **)(**(int **)in_ECX[1] + 0x14))();
    uStack_8 = (uint)*(byte *)(iVar6 + 0x1f);
    uStack_4 = (uint)uVar2;
    piVar5 = (int *)(**(code **)(*DAT_00b5aa28 + 8))(&uStack_8);
    iVar6 = (**(code **)(*piVar5 + 4))();
    cVar1 = *(char *)(iVar6 + 4);
    iVar6 = (**(code **)(*piVar5 + 4))();
    cVar3 = (**(code **)(*in_ECX + 0x10))();
    bVar7 = cVar1 + *(char *)(iVar6 + 9) * cVar3;
    if (in_ECX[6] != 0) {
      iVar6 = (**(code **)(*piVar5 + 4))();
      bVar7 = bVar7 + *(char *)(iVar6 + 8);
    }
    bVar4 = 100;
    if (bVar7 < 0x65) {
      bVar4 = bVar7;
    }
  }
  return bVar4;
}


// ==== FUN_00722b20 @ 0x00722b20 ====

void FUN_00722b20(int param_1)

{
  void *_Memory;
  int in_ECX;
  undefined4 *_Src;
  undefined4 *_Dst;
  int local_8;
  
  _Dst = *(undefined4 **)(in_ECX + 0xc);
  local_8 = 0;
  if (_Dst != *(undefined4 **)(in_ECX + 0x10)) {
    _Src = _Dst;
    do {
      _Src = _Src + 1;
      if ((local_8 == param_1) && (_Memory = (void *)*_Dst, _Memory != (void *)0x0)) {
        _memmove(_Dst,_Src,(*(int *)(in_ECX + 0x10) - (int)_Src >> 2) * 4);
        *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -4;
        _free(_Memory);
        return;
      }
      local_8 = local_8 + 1;
      _Dst = _Dst + 1;
    } while (_Dst != *(undefined4 **)(in_ECX + 0x10));
  }
  return;
}


// ==== FUN_00722b90 @ 0x00722b90 ====

void FUN_00722b90(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00722bf0 @ 0x00722bf0 ====

void FUN_00722bf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed748;
  DAT_00b5b0f4 = 0;
  FUN_00722b90();
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009ed714;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00722c30 @ 0x00722c30 ====

undefined4 FUN_00722c30(uint param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int extraout_EDX;
  int iVar2;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     (param_1 < (uint)(*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2))) {
    iVar2 = *(int *)(in_ECX + 0xc);
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x10) - iVar2 >> 2) <= param_1)) {
      FUN_00722de0();
      iVar2 = extraout_EDX;
    }
    uVar1 = *(undefined4 *)(iVar2 + param_1 * 4);
  }
  return uVar1;
}


// ==== FUN_00722c70 @ 0x00722c70 ====

void FUN_00722c70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed748;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b0f4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0f4 = in_ECX;
  return;
}


// ==== FUN_00722ce0 @ 0x00722ce0 ====

void FUN_00722ce0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  
  piVar3 = param_1;
  piVar4 = *(int **)(in_ECX + 0xc);
  if (piVar4 != *(int **)(in_ECX + 0x10)) {
    do {
      iVar1 = *piVar4;
      if (((*(char *)(iVar1 + 4) == (char)param_1[1]) &&
          (*(char *)(iVar1 + 5) == *(char *)((int)param_1 + 5))) &&
         (*(char *)(iVar1 + 6) == *(char *)((int)param_1 + 6))) {
        return;
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(in_ECX + 0x10));
  }
  if ((*param_1 != 0) &&
     ((*(int *)(in_ECX + 0xc) == 0 ||
      ((uint)(*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2) < 5)))) {
    param_1 = operator_new(8);
    if (param_1 == (int *)0x0) {
      param_1 = (int *)0x0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
      *(undefined1 *)((int)param_1 + 5) = 0;
      *(undefined1 *)((int)param_1 + 6) = 0;
    }
    *param_1 = *piVar3;
    *(short *)(param_1 + 1) = (short)piVar3[1];
    *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)piVar3 + 6);
    iVar1 = *(int *)(in_ECX + 0xc);
    if ((iVar1 != 0) &&
       ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) < (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2))
       ) {
      puVar2 = *(undefined4 **)(in_ECX + 0x10);
      *puVar2 = param_1;
      *(undefined4 **)(in_ECX + 0x10) = puVar2 + 1;
      return;
    }
    FUN_00722ec0(*(undefined4 *)(in_ECX + 0x10),1,&param_1);
  }
  return;
}


// ==== FUN_00722dc0 @ 0x00722dc0 ====

void FUN_00722dc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00722bf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00722de0 @ 0x00722de0 ====

void FUN_00722de0(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00990938;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_invalid_vector<T>_subscript_0099ca88,0x1b);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c7c8);
}


// ==== FUN_00722e50 @ 0x00722e50 ====

void FUN_00722e50(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00990938;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_vector<T>_too_long_0099c99c,0x12);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c48c);
}


// ==== FUN_00722ec0 @ 0x00722ec0 ====

void FUN_00722ec0(void *param_1,uint param_2,undefined4 *param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar5 = *(int *)(in_ECX + 4);
  param_3 = (undefined4 *)*param_3;
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 2;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (0x3fffffffU - iVar5 < param_2) {
      uVar7 = FUN_00722e50();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
        }
        uVar2 = iVar5 + param_2;
      }
      _Dst = operator_new(uVar2 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_00845740((void *)((int)pvVar3 + _Size),param_2,&param_3);
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 2;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = _Dst;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - (int)param_1 >> 2) < param_2) {
      FUN_005a6d90(param_1,iVar1,(void *)(iVar5 + (int)param_1));
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - (int)param_1 >> 2),
                   &param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_005a6d90(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,(void *)(iVar5 + (int)param_1),&param_3);
  }
  return;
}


// ==== FUN_007230a0 @ 0x007230a0 ====

void FUN_007230a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed8e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007230d0 @ 0x007230d0 ====

void FUN_007230d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed8ec;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae44 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae44 = in_ECX;
  return;
}


// ==== FUN_00723100 @ 0x00723100 ====

void FUN_00723100(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae44 = 0;
  *in_ECX = &PTR_FUN_009ed8e0;
  return;
}


// ==== FUN_00723120 @ 0x00723120 ====

void FUN_00723120(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar3;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char *pcStack_58;
  undefined1 auStack_42 [2];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990998;
  pvStack_c = ExceptionList;
  pcStack_58 = s_>>>_MailListStart_009ed7b4;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  uStack_5c = 0x72315e;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  pcStack_58 = (char *)0x72316c;
  FUN_00796d20();
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_2c) {
    pcStack_58 = (char *)0x723188;
    _free(local_40);
    return;
  }
  uVar3 = extraout_var;
  if (*(char *)(param_1 + 0x1a) == '\0') {
    (**(code **)(*DAT_00b5ae48 + 8))();
    uVar3 = extraout_var_00;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0) {
    pcStack_58 = (char *)CONCAT22(uVar3,*(undefined2 *)(param_1 + 0x14));
    uStack_5c = 0x7231bb;
    (**(code **)(*DAT_00b5ae4c + 8))();
    if (9 < *(ushort *)(param_1 + 0x18)) {
      piVar2 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
      (**(code **)(*piVar2 + 0x1c))();
      ExceptionList = pvStack_c;
      return;
    }
  }
  else if (iVar1 == -1) {
    pcStack_58 = (char *)0x0;
    uStack_5c = 0x723206;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72321f;
    FUN_00401660();
    local_4 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_c = (void *)0x1;
    uStack_70 = 0;
    FUN_00401660(auStack_42 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < local_2c) {
      pcStack_58 = (char *)0x723268;
      _free(local_40);
      return;
    }
  }
  else {
    if (iVar1 != -2) {
      if (iVar1 == -3) {
        pcStack_58 = (char *)0x0;
        uStack_5c = 0x723328;
        uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_60 = 0x723332;
        FUN_00765c50();
        local_4 = auStack_74;
        pvStack_c = (void *)0x3;
        FUN_00765c50(auStack_42 + -10);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        (**(code **)(*DAT_00b5ae48 + 8))();
      }
      else {
        if (iVar1 != -4) {
          ExceptionList = pvStack_c;
          return;
        }
        pcStack_58 = (char *)0x0;
        uStack_5c = 0x723381;
        uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_60 = 0x72338b;
        FUN_00765c50();
        local_4 = auStack_74;
        pvStack_c = (void *)0x4;
        FUN_00765c50(&local_30);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    pcStack_58 = (char *)0x0;
    uStack_5c = 0x723299;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x7232b2;
    FUN_00401660();
    local_4 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_c = (void *)0x2;
    uStack_70 = 0;
    FUN_00401660(auStack_42 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < local_2c) {
      pcStack_58 = (char *)0x7232fb;
      _free(local_40);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_007233d0 @ 0x007233d0 ====

void FUN_007233d0(int param_1)

{
  int iVar1;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009909ba;
  local_c = ExceptionList;
  uStack_54 = s_>>>_SA_MailCount_009ed7d8;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  uStack_58 = 0x72340d;
  ExceptionList = &local_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  uStack_54 = (char *)0x72341b;
  FUN_00796d20();
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_2c) {
    uStack_54 = (char *)0x723437;
    _free(local_40);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0) {
    uStack_54 = (char *)CONCAT22((short)((uint)param_1 >> 0x10),*(undefined2 *)(param_1 + 0x14));
    uStack_58 = 0x72345a;
    (**(code **)(*DAT_00b5ae4c + 8))();
    ExceptionList = pvStack_14;
    return;
  }
  if (iVar1 == -1) {
    uStack_54 = (char *)0x0;
    uStack_58 = 0x723483;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x72349c;
    FUN_00401660();
    local_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_c = (void *)0x1;
    uStack_6c = 0;
    FUN_00401660(auStack_70 + 0x24,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < local_2c) {
LAB_0072354d:
      uStack_54 = (char *)0x723552;
      _free(local_40);
      return;
    }
  }
  else if (iVar1 == -2) {
    uStack_54 = (char *)0x0;
    uStack_58 = 0x7234f4;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = local_2c & 0xffffff00;
    uStack_64 = 0x72350d;
    FUN_00401660();
    local_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_c = (void *)0x2;
    uStack_6c = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_10) {
      local_40 = pvStack_24;
      goto LAB_0072354d;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00723570 @ 0x00723570 ====

void FUN_00723570(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iStack_30;
  int iStack_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009909cc;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_>>>_SA_MailList_009ed7fc,0x21);
  local_4 = 0;
  FUN_00796d20(local_28);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
  iVar3 = (**(code **)(*piVar2 + 0x20))();
  piVar1 = DAT_00b5aa18;
  piVar2 = DAT_00b5a980;
  if (iVar3 != 10) {
    uVar4 = FUN_00424520();
    iStack_30 = (uVar4 & 0xffff) - 0x18;
    iStack_2c = param_1 + 0x18;
    iVar3 = *piVar1;
    uVar5 = (**(code **)(*piVar2 + 8))();
    (**(code **)(iVar3 + 0x98))(&iStack_30,uVar5);
    (**(code **)(*DAT_00b5ae48 + 0x10))();
    (**(code **)(*DAT_00b5ae48 + 0x1c))();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00723660 @ 0x00723660 ====

void FUN_00723660(void)

{
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009909de;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_>>>_SA_MailListEnd_009ed820,0x24);
  local_4 = 0;
  FUN_00796d20(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5ae48 + 8))();
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00723700 @ 0x00723700 ====

void FUN_00723700(int param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  int *piVar4;
  int *piVar5;
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  char *pcStack_4c;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  void *local_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990a10;
  local_c = ExceptionList;
  pcStack_4c = s_>>>_SA_ReadMail_009ed848;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  iStack_50 = 0x72373d;
  ExceptionList = &local_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  pcStack_4c = (char *)0x72374b;
  FUN_00796d20();
  local_4 = (undefined1 *)0xffffffff;
  if ((void *)0xf < local_10) {
    pcStack_4c = (char *)0x723767;
    _free(local_24);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    local_30 = *(undefined4 *)(param_1 + 0x1c);
    local_2c = *(undefined2 *)(param_1 + 0x20);
    local_2a = *(undefined1 *)(param_1 + 0x22);
    piVar4 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
    pcStack_4c = (char *)0x7239ae;
    piVar4 = (int *)(**(code **)(*piVar4 + 0xc))();
    pcStack_4c = (char *)0x7239b7;
    cVar2 = (**(code **)(*piVar4 + 0x28))();
    if (cVar2 == '\0') {
      pcStack_4c = (char *)0x1;
      iStack_50 = 0x7239c4;
      (**(code **)(*piVar4 + 0x24))();
      iStack_50 = 0x7239cf;
      piVar5 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
      iStack_50 = 0x7239d6;
      uVar3 = (**(code **)(*piVar5 + 0x30))();
      iStack_50 = 0x7239e7;
      piVar5 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
      uStack_54 = 0x7239ef;
      iStack_50 = CONCAT22((short)((uint)piVar4 >> 0x10),uVar3) + -1;
      (**(code **)(*piVar5 + 0x2c))();
      uStack_54 = 0x7239fa;
      (**(code **)(*DAT_00b5ae4c + 0x18))();
    }
    pcStack_4c = (char *)0x723a05;
    cVar2 = (**(code **)(*DAT_00b5ae48 + 0x24))();
    if (cVar2 == '\x01') {
      pcStack_4c = (char *)0x723a14;
      (**(code **)(*DAT_00b5ae48 + 0x10))();
      pcStack_4c = (char *)0x723a1f;
      (**(code **)(*DAT_00b5ae48 + 0x20))();
      ExceptionList = local_10;
      return;
    }
    pcStack_4c = (char *)0x723a35;
    (**(code **)(*DAT_00b5ae48 + 0x18))();
    pcStack_4c = (char *)0x723a40;
    (**(code **)(*DAT_00b5ae48 + 0x10))();
  }
  else if (iVar1 == -1) {
    pcStack_4c = (char *)0x0;
    iStack_50 = 0x723793;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_50 = 0xffffffff;
    uStack_54 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_5c = 0x7237ac;
    FUN_00401660();
    local_4 = auStack_68;
    iStack_50 = 0xf;
    uStack_54 = 0;
    local_c = (void *)0x1;
    uStack_64 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if ((void *)0xf < local_10) {
      pcStack_4c = (char *)0x7237f5;
      _free(local_24);
      return;
    }
  }
  else if (iVar1 == -2) {
    pcStack_4c = (char *)0x0;
    iStack_50 = 0x723825;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_50 = 0xffffffff;
    uStack_54 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_5c = 0x72383e;
    FUN_00401660();
    local_4 = auStack_68;
    iStack_50 = 0xf;
    uStack_54 = 0;
    local_c = (void *)0x2;
    uStack_64 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if ((void *)0xf < local_10) {
      pcStack_4c = (char *)0x723887;
      _free(local_24);
      return;
    }
  }
  else {
    if (iVar1 == -3) {
      pcStack_4c = (char *)0x0;
      iStack_50 = 0x7238b3;
      iStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_54 = 0x7238bd;
      FUN_00765c50();
      local_4 = auStack_68;
      local_c = (void *)0x3;
      FUN_00765c50(&local_30);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (iVar1 == -100) {
      pcStack_4c = (char *)0x0;
      iStack_50 = 0x72391b;
      iStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_54 = 0x723925;
      FUN_00765c50();
      local_4 = auStack_68;
      local_c = (void *)0x4;
      FUN_00765c50(&local_30);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00723a60 @ 0x00723a60 ====

void FUN_00723a60(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined1 auStack_6c [4];
  undefined1 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  char *pcStack_50;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  void *local_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990a52;
  local_c = ExceptionList;
  pcStack_50 = s_>>>_SA_GETITEM_009ed86c;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  uStack_54 = 0x723a9e;
  ExceptionList = &local_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  pcStack_50 = (char *)0x723aac;
  FUN_00796d20();
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_10) {
    pcStack_50 = (char *)0x723acc;
    _free(local_24);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    local_30 = *(undefined4 *)(param_1 + 0x1c);
    local_2c = *(undefined2 *)(param_1 + 0x20);
    local_2a = *(undefined1 *)(param_1 + 0x22);
    piVar3 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
    pcStack_50 = (char *)0x723d8c;
    piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
    iVar1 = *DAT_00b5a790;
    pcStack_50 = (char *)0x723d9d;
    pcStack_50 = (char *)(**(code **)(*piVar3 + 0x14))();
    uStack_54 = 0x723da3;
    cVar2 = (**(code **)(iVar1 + 0x14))();
    if (cVar2 == '\x01') {
      (**(code **)(*piVar3 + 0x18))();
      (**(code **)(*DAT_00b5ae48 + 0x20))();
    }
    ExceptionList = local_c;
    return;
  }
  if (iVar1 == -1) {
    pcStack_50 = (char *)0x0;
    uStack_54 = 0x723af8;
    uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0xffffffff;
    uStack_58 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_60 = 0x723b11;
    FUN_00401660();
    local_4 = auStack_6c;
    uStack_54 = 0xf;
    uStack_58 = 0;
    local_c = (void *)0x1;
    uStack_68 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    pcStack_50 = (char *)0x723b59;
    _free(local_24);
    return;
  }
  if (iVar1 == -2) {
    pcStack_50 = (char *)0x0;
    uStack_54 = 0x723b8a;
    uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0xffffffff;
    uStack_58 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_60 = 0x723ba3;
    FUN_00401660();
    local_4 = auStack_6c;
    uStack_54 = 0xf;
    uStack_58 = 0;
    local_c = (void *)0x2;
    uStack_68 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    pcStack_50 = (char *)0x723beb;
    _free(local_24);
    return;
  }
  if (iVar1 == -3) {
    pcStack_50 = (char *)0x0;
    uStack_54 = 0x723c18;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x723c22;
    FUN_00765c50();
    local_c = (void *)0x3;
  }
  else {
    if (iVar1 == -100) {
      pcStack_50 = (char *)0x0;
      uStack_54 = 0x723c45;
      uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0x723c4f;
      FUN_00765c50();
      local_4 = auStack_6c;
      local_c = (void *)0x4;
      FUN_00765c50(&local_30);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (iVar1 != -0x65) {
      if (iVar1 != -0x66) {
        ExceptionList = local_c;
        return;
      }
      pcStack_50 = (char *)0x0;
      uStack_54 = 0x723d13;
      uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0x723d1d;
      FUN_00765c50();
      local_4 = auStack_6c;
      local_c = (void *)0x6;
      FUN_00765c50(&local_30);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      goto LAB_00723cdc;
    }
    pcStack_50 = (char *)0x0;
    uStack_54 = 0x723caa;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x723cb4;
    FUN_00765c50();
    local_c = (void *)0x5;
  }
  local_4 = auStack_6c;
  FUN_00765c50(&local_30);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_00723cdc:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00723dd0 @ 0x00723dd0 ====

void FUN_00723dd0(int param_1)

{
  int iVar1;
  undefined *_Memory;
  int *piVar2;
  undefined1 auStack_6c [4];
  undefined1 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  char *pcStack_50;
  uint local_38;
  void *local_34;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  void *local_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990a6c;
  pvStack_c = ExceptionList;
  pcStack_50 = s_>>>_SA_GETMONEY_009ed890;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  uStack_54 = 0x723e0e;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  pcStack_50 = (char *)0x723e1c;
  FUN_00796d20();
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_10) {
    pcStack_50 = (char *)0x723e3c;
    _free(local_24);
    return;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    local_34 = *(void **)(param_1 + 0x18);
    local_30 = *(undefined4 *)(param_1 + 0x1c);
    local_2c = *(undefined2 *)(param_1 + 0x20);
    local_2a = *(undefined1 *)(param_1 + 0x22);
    piVar2 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
    pcStack_50 = (char *)0x723f58;
    piVar2 = (int *)(**(code **)(*piVar2 + 0xc))();
    iVar1 = *DAT_00b5a784;
    pcStack_50 = (char *)0x723f69;
    pcStack_50 = (char *)(**(code **)(*piVar2 + 0x1c))();
    uStack_54 = 0x723f6f;
    (**(code **)(iVar1 + 0x14))();
    uStack_54 = 0x723f76;
    (**(code **)(*piVar2 + 0x20))();
    uStack_54 = 0x723f81;
    (**(code **)(*DAT_00b5ae48 + 0x20))();
  }
  else {
    _Memory = (undefined *)0x0;
    switch(*(int *)(param_1 + 0x24)) {
    case -0x66:
      _Memory = &DAT_006e0076;
      break;
    case -0x65:
      _Memory = &DAT_006e00aa;
      break;
    case -100:
      _Memory = &DAT_006e009a;
      break;
    case -3:
      _Memory = &DAT_006e0099;
      break;
    case -2:
      _Memory = &DAT_006e009b;
      break;
    case -1:
      _Memory = &DAT_006e0095;
    }
    pcStack_50 = (char *)0x0;
    uStack_54 = 0x723e9b;
    uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0xffffffff;
    uStack_58 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_60 = 0x723eb4;
    FUN_00401660();
    local_4 = auStack_6c;
    uStack_54 = 0xf;
    uStack_58 = 0;
    pvStack_c = (void *)0x1;
    uStack_68 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < local_38) {
      _free(_Memory);
      return;
    }
  }
  ExceptionList = local_34;
  return;
}


// ==== FUN_00724020 @ 0x00724020 ====

void FUN_00724020(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  char *pcStack_4c;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  void *local_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990ab6;
  local_c = ExceptionList;
  pcStack_4c = s_>>>_SA_DELETEMAIL_009ed8b4;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  uStack_50 = 0x72405d;
  ExceptionList = &local_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  pcStack_4c = (char *)0x72406b;
  FUN_00796d20();
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_10) {
    pcStack_4c = (char *)0x724087;
    _free(local_24);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    local_30 = *(undefined4 *)(param_1 + 0x1c);
    local_2c = *(undefined2 *)(param_1 + 0x20);
    local_2a = *(undefined1 *)(param_1 + 0x22);
    piVar2 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
    pcStack_4c = (char *)0x724372;
    uVar3 = (**(code **)(*piVar2 + 0xc))();
    pcStack_4c = (char *)0x72437f;
    piVar2 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
    uStack_50 = 0x724387;
    pcStack_4c = (char *)uVar3;
    (**(code **)(*piVar2 + 8))();
    uStack_50 = 0x724392;
    (**(code **)(*DAT_00b5ae48 + 0x34))();
    ExceptionList = local_c;
    return;
  }
  if (iVar1 == -1) {
    pcStack_4c = (char *)0x0;
    uStack_50 = 0x7240b3;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_50 = 0xffffffff;
    uStack_54 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_5c = 0x7240cc;
    FUN_00401660();
    local_4 = auStack_68;
    uStack_50 = 0xf;
    uStack_54 = 0;
    local_c = (void *)0x1;
    uStack_64 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    pcStack_4c = (char *)0x724115;
    _free(local_24);
    return;
  }
  if (iVar1 == -2) {
    pcStack_4c = (char *)0x0;
    uStack_50 = 0x724145;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_50 = 0xffffffff;
    uStack_54 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = (ushort)local_2c._1_1_ << 8;
    uStack_5c = 0x72415e;
    FUN_00401660();
    local_4 = auStack_68;
    uStack_50 = 0xf;
    uStack_54 = 0;
    local_c = (void *)0x2;
    uStack_64 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    pcStack_4c = (char *)0x7241a7;
    _free(local_24);
    return;
  }
  if (iVar1 == -3) {
    pcStack_4c = (char *)0x0;
    uStack_50 = 0x7241d3;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x7241dd;
    FUN_00765c50();
    local_c = (void *)0x3;
LAB_0072430b:
    local_4 = auStack_68;
    FUN_00765c50(&local_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  else {
    if (iVar1 == -4) {
      pcStack_4c = (char *)0x0;
      uStack_50 = 0x724200;
      uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_54 = 0x72420a;
      FUN_00765c50();
      local_c = (void *)0x4;
    }
    else {
      if (iVar1 == -100) {
        pcStack_4c = (char *)0x0;
        uStack_50 = 0x72422d;
        uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_54 = 0x724237;
        FUN_00765c50();
        local_4 = auStack_68;
        local_c = (void *)0x5;
        FUN_00765c50(&local_30);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (iVar1 != -0x65) {
        if (iVar1 != -0x66) {
          ExceptionList = local_c;
          return;
        }
        pcStack_4c = (char *)0x0;
        uStack_50 = 0x7242f9;
        uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_54 = 0x724303;
        FUN_00765c50();
        local_c = (void *)0x7;
        goto LAB_0072430b;
      }
      pcStack_4c = (char *)0x0;
      uStack_50 = 0x724291;
      uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_54 = 0x72429b;
      FUN_00765c50();
      local_c = (void *)0x6;
    }
    local_4 = auStack_68;
    FUN_00765c50(&local_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_007243b0 @ 0x007243b0 ====

undefined4 FUN_007243b0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0xc000007) {
    if (uVar1 == 0xc000006) {
      FUN_00723700(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0xc000003) {
      if (uVar1 == 0xc000002) {
        FUN_00723660(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x2070002) {
        FUN_00723570(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xc000001) {
        FUN_00723120(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else if (uVar1 == 0xc000004) {
      FUN_007233d0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    if (uVar1 == 0xc000008) {
      FUN_00723a60(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0xc00000a) {
      FUN_00723dd0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0xc00000c) {
      FUN_00724020(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00724490 @ 0x00724490 ====

undefined4 FUN_00724490(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007243b0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007244c0 @ 0x007244c0 ====

void FUN_007244c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00723100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007244e0 @ 0x007244e0 ====

void FUN_007244e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edbdc;
  return;
}


// ==== FUN_007244f0 @ 0x007244f0 ====

void FUN_007244f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edbdc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00724510 @ 0x00724510 ====

undefined1 FUN_00724510(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_00724520 @ 0x00724520 ====

undefined2 FUN_00724520(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 8);
}


// ==== FUN_00724530 @ 0x00724530 ====

void FUN_00724530(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0072453c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0x10))();
    return;
  }
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009edc30;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*in_ECX + 0x10))();
  *(undefined1 *)(in_ECX + 1) = 1;
  return;
}


// ==== FUN_00724570 @ 0x00724570 ====

void FUN_00724570(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009edc44;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_007245b0 @ 0x007245b0 ====

void FUN_007245b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009edc80;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007245e0 @ 0x007245e0 ====

void FUN_007245e0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 5) == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x007245ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0x20))();
    return;
  }
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)((int)in_ECX + 5) = 1;
    return;
  }
  *puVar1 = &PTR_FUN_009edc58;
  FUN_00797a20(puVar1);
  *(undefined1 *)((int)in_ECX + 5) = 1;
  return;
}


// ==== FUN_00724630 @ 0x00724630 ====

void FUN_00724630(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 5) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009edc6c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 5) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 5) = 0;
  }
  return;
}


// ==== FUN_00724670 @ 0x00724670 ====

void FUN_00724670(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009edc94;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007246a0 @ 0x007246a0 ====

void FUN_007246a0(undefined1 param_1,short param_2)

{
  int in_ECX;
  
  if (*(short *)(in_ECX + 8) == param_2) {
    *(short *)(in_ECX + 8) = param_2;
    *(undefined1 *)(in_ECX + 6) = param_1;
    return;
  }
  (**(code **)(*DAT_00b5ae4c + 0x18))();
  *(short *)(in_ECX + 8) = param_2;
  *(undefined1 *)(in_ECX + 6) = param_1;
  return;
}


// ==== FUN_007246e0 @ 0x007246e0 ====

undefined4 FUN_007246e0(int param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  iVar3 = param_1 + 8;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_letterwnd_009eda54,0xe);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 8))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_letterwnd_009eda64,0xe);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_readletterwnd_009eda74,0x12);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x18))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_hide_readletterwnd_009eda88);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x1c))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_refreshlist_009eda9c);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_refreshreading_009edaa8);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x20))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_start_maillist_009edab8);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x34))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_mailcount_009edac8);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x38))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_show_arrivemail_009edad4);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*DAT_00b5ae4c + 0x10))();
  return 1;
}


// ==== FUN_00724830 @ 0x00724830 ====

undefined4 FUN_00724830(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_007246e0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00724860 @ 0x00724860 ====

void FUN_00724860(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined1 auStackY_100 [56];
  undefined1 *_Memory;
  undefined1 auStack_9e [6];
  uint **ppuVar1;
  undefined1 *puVar2;
  undefined1 *puStack_88;
  undefined4 uStack_84;
  undefined1 *puVar3;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  uint *puVar4;
  undefined1 *puStack_70;
  undefined1 auStack_6c [4];
  uint *puVar5;
  uint *puStack_64;
  char *pcStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  uint local_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990b63;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009edcac;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  local_4 = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae48 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae48 = in_ECX;
  }
  uStack_5c = (uint *)0x0;
  pcStack_60 = &DAT_009ed92e;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[3] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  puStack_64 = (uint *)0x7248e4;
  FUN_00401740();
  uStack_5c = (uint *)0xe;
  pcStack_60 = s_start_maillist_009ed930;
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  puStack_64 = (uint *)0x724905;
  FUN_00401740();
  uStack_5c = &local_28;
  pcStack_60 = (char *)0x0;
  puStack_64 = &local_44;
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10._0_1_ = 1;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740();
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740();
  puVar5 = &uStack_34;
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    uStack_78 = (char *)0x7249c3;
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 1;
  if (0xf < local_28) {
    uStack_78 = (char *)0x7249e7;
    _free(pvStack_3c);
    return;
  }
  uStack_78 = &DAT_009ed94a;
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  puStack_7c = (undefined4 *)0x724a05;
  FUN_00401740();
  uStack_78 = s_show_letterwnd_009ed94c;
  uStack_1c._0_1_ = 6;
  local_44 = 0xf;
  puStack_7c = (undefined4 *)0x724a26;
  FUN_00401740();
  puVar4 = &local_40;
  uStack_78 = (char *)0x0;
  puStack_7c = &uStack_5c;
  uStack_1c = CONCAT31(uStack_1c._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < unaff_EBP) {
    uStack_84 = (char *)0x724a51;
    _free(puStack_64);
    return;
  }
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  local_28._0_1_ = 1;
  if (0xf < uStack_34) {
    uStack_84 = (char *)0x724a75;
    _free((void *)0x0);
    return;
  }
  uStack_84 = &DAT_009ed95b;
  uStack_34 = 0xf;
  uStack_38 = 0;
  puStack_88 = (undefined1 *)0x724a93;
  FUN_00401740();
  uStack_84 = s_hide_letterwnd_009ed95c;
  local_28._0_1_ = 8;
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  puStack_88 = (undefined1 *)0x724ab4;
  FUN_00401740();
  puVar3 = auStack_46 + -6;
  uStack_84 = (char *)0x0;
  puStack_88 = auStack_6c + 4;
  local_28 = CONCAT31(local_28._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < uStack_5c) {
    _free(auStack_46 + -10);
    return;
  }
  uStack_5c = (uint *)0xf;
  pcStack_60 = (char *)0x0;
  puStack_70 = auStackY_100;
  uStack_34._0_1_ = 1;
  if (0xf < local_40) {
    _free((void *)0x0);
    return;
  }
  local_40 = 0xf;
  local_44 = 0;
  FUN_00401740();
  uStack_34._0_1_ = 10;
  uStack_5c = (uint *)0xf;
  pcStack_60 = (void *)0x0;
  FUN_00401740();
  puVar2 = auStack_6c + 0x14;
  uStack_34 = CONCAT31(uStack_34._1_3_,0xb);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar5) {
    _free(puStack_7c);
    return;
  }
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  local_40._0_1_ = 1;
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free(pcStack_60);
    return;
  }
  pcStack_60 = (char *)((uint)pcStack_60 & 0xffffff00);
  FUN_00401740();
  local_40._0_1_ = 0xc;
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  FUN_00401740();
  ppuVar1 = &puStack_64;
  local_40 = CONCAT31(local_40._1_3_,0xd);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar4) {
    _free(puStack_88);
    return;
  }
  uStack_78 = (char *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  if (0xf < ((uint)unaff_EDI & 0xffffff00)) {
    _free((void *)0x0);
    return;
  }
  uStack_5c = (uint *)0x0;
  FUN_00401740(&DAT_009ed98b);
  uStack_78 = (void *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  FUN_00401740(s_show_readletterwnd_009ed98c);
  _Memory = auStack_9e + 0x12;
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if ((undefined1 *)0xf < puVar3) {
    _free(auStack_6c + -8);
    return;
  }
  uStack_84 = (char *)0x0;
  if ((uint *)0xf < puStack_64) {
    _free(uStack_78);
    return;
  }
  puStack_64 = (uint *)0xf;
  uStack_78 = (char *)((uint)uStack_78 & 0xffffff00);
  FUN_00401740(&DAT_009ed99f,0);
  uStack_84 = (void *)0x0;
  FUN_00401740(s_hide_readletterwnd_009ed9a0,0x12);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_9e + 6,0,&puStack_7c);
  if ((undefined1 *)0xf < puVar2) {
    _free(auStack_6c + -0x14);
    return;
  }
  puStack_64._0_1_ = 1;
  if ((undefined1 *)0xf < puStack_70) {
    _free(uStack_84);
    return;
  }
  uStack_84 = (char *)((uint)uStack_84 & 0xffffff00);
  FUN_00401740(&DAT_009ed9b3,0);
  puStack_64._0_1_ = 0x12;
  FUN_00401740(s_show_arrivemail_009ed9b4,0xf);
  puStack_64 = (uint *)CONCAT31(puStack_64._1_3_,0x13);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_9e + -6,0,&puStack_88);
  if ((uint **)0xf < ppuVar1) {
    _free(_Memory);
    return;
  }
  if (puStack_7c < (undefined4 *)0x10) {
    ExceptionList = uStack_78;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00724de0 @ 0x00724de0 ====

/* WARNING: Removing unreachable block (ram,0x007250a1) */
/* WARNING: Removing unreachable block (ram,0x0072505e) */
/* WARNING: Removing unreachable block (ram,0x00725015) */

void FUN_00724de0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 uStack_40;
  undefined1 auStack_2a [2];
  void *local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990bc8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009edcac;
  uStack_40 = (void **)0xe;
  local_4 = 1;
  DAT_00b5ae48 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401740();
  uStack_40 = &local_28;
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  pvStack_c._0_1_ = 1;
  if (0xf < uStack_18) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740(s_show_letterwnd_009ed9e0);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  local_10._0_1_ = 1;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740(s_hide_letterwnd_009ed9f0,0xe);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -10);
  local_14._0_1_ = 1;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  FUN_00401740(s_refreshlist_009eda00,0xb);
  local_14 = CONCAT31(local_14._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0xe);
  uStack_18._0_1_ = 1;
  if (0xf < local_24) {
    _free(unaff_ESI);
    return;
  }
  local_24 = 0xf;
  local_28 = (void *)0x0;
  FUN_00401740(s_refreshreading_009eda0c,0xe);
  uStack_18 = CONCAT31(uStack_18._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x12);
  uStack_1c._0_1_ = 1;
  if ((void *)0xf < local_28) {
    _free(unaff_EDI);
    return;
  }
  local_28 = (void *)0xf;
  FUN_00401740(s_show_readletterwnd_009eda1c,0x12);
  uStack_1c = CONCAT31(uStack_1c._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&uStack_40);
  uStack_20._0_1_ = 1;
  uStack_40 = (void **)((uint)uStack_40 & 0xffffff00);
  FUN_00401740(s_hide_readletterwnd_009eda30,0x12);
  uStack_20 = CONCAT31(uStack_20._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x1a);
  local_24._0_1_ = 1;
  FUN_00401740(s_show_arrivemail_009eda44,0xf);
  local_24 = CONCAT31(local_24._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x1e);
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_009edbdc;
    ExceptionList = (void *)0xf;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_007250f0 @ 0x007250f0 ====

void FUN_007250f0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990bda;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0xc000000;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_>>>_CQ_MailList_009edae4,0x21);
  uStack_4 = 0;
  FUN_00796d20(auStack_28);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_007251b0 @ 0x007251b0 ====

void FUN_007251b0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990bec;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0xc000003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_>>>_CQ_MailCount_009edb08,0x22);
  uStack_4 = 0;
  FUN_00796d20(auStack_28);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00725270 @ 0x00725270 ====

void FUN_00725270(int param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  char acStack_3b [19];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990bfe;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xc000005;
  *(undefined2 *)((int)pvVar4 + 6) = 0x24;
  iVar5 = FUN_004244d0();
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    iVar6 = param_1 + 4;
  }
  else {
    iVar6 = *(int *)(param_1 + 4);
  }
  FUN_006915e0(acStack_3b,&DAT_009edbbc,iVar6);
  pcVar1 = (char *)(iVar5 + 0x10);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_3b + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_0072530c;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x13);
  *pcVar1 = '\0';
LAB_0072530c:
  FUN_004d8570(iVar5);
  FUN_00401660(param_1,0,0xffffffff);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_>>>_CQ_ReadMail_009edb2c,0x21);
  uStack_4 = 0;
  FUN_00796d20(auStack_28);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00725390 @ 0x00725390 ====

void FUN_00725390(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  char acStack_3b [19];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990c10;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xc000007;
  *(undefined2 *)((int)pvVar4 + 6) = 0x24;
  iVar5 = FUN_004244d0();
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    iVar8 = in_ECX + 0x14;
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x14);
  }
  FUN_006915e0(acStack_3b,&DAT_009edbbc,iVar8);
  pcVar1 = (char *)(iVar5 + 0x10);
  uVar7 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_3b + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_00725427;
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 < 0x13);
  *pcVar1 = '\0';
LAB_00725427:
  FUN_004d8570(iVar5);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_>>>_CQ_GetItem_009edb50,0x20);
  uStack_4 = 0;
  FUN_00796d20(auStack_28);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_007254a0 @ 0x007254a0 ====

void FUN_007254a0(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  char acStack_3b [19];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990c22;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xc000009;
  *(undefined2 *)((int)pvVar4 + 6) = 0x24;
  iVar5 = FUN_004244d0();
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    iVar8 = in_ECX + 0x14;
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x14);
  }
  FUN_006915e0(acStack_3b,&DAT_009edbbc,iVar8);
  pcVar1 = (char *)(iVar5 + 0x10);
  uVar7 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_3b + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_00725537;
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 < 0x13);
  *pcVar1 = '\0';
LAB_00725537:
  FUN_004d8570(iVar5);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_>>>_CQ_GetMoney_009edb74,0x21);
  uStack_4 = 0;
  FUN_00796d20(auStack_28);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_007255b0 @ 0x007255b0 ====

void FUN_007255b0(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  char acStack_3b [19];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990c34;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xc00000b;
  *(undefined2 *)((int)pvVar4 + 6) = 0x24;
  iVar5 = FUN_004244d0();
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    iVar8 = in_ECX + 0x14;
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x14);
  }
  FUN_006915e0(acStack_3b,&DAT_009edbbc,iVar8);
  pcVar1 = (char *)(iVar5 + 0x10);
  uVar7 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_3b + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_00725647;
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 < 0x13);
  *pcVar1 = '\0';
LAB_00725647:
  FUN_004d8570(iVar5);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_>>>_CQ_DeleteMail_009edb98,0x23);
  uStack_4 = 0;
  FUN_00796d20(auStack_28);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_007256c0 @ 0x007256c0 ====

undefined4 FUN_007256c0(void)

{
  return 0x70360000;
}


// ==== FUN_007256d0 @ 0x007256d0 ====

undefined4 FUN_007256d0(void)

{
  return 0x70360001;
}


// ==== FUN_007256e0 @ 0x007256e0 ====

undefined4 FUN_007256e0(void)

{
  return 0x70360002;
}


// ==== FUN_007256f0 @ 0x007256f0 ====

undefined4 FUN_007256f0(void)

{
  return 0x70360003;
}


// ==== FUN_00725700 @ 0x00725700 ====

undefined4 FUN_00725700(void)

{
  return 0x70360004;
}


// ==== FUN_00725710 @ 0x00725710 ====

undefined4 FUN_00725710(void)

{
  return 0x70360005;
}


// ==== FUN_00725720 @ 0x00725720 ====

void FUN_00725720(byte param_1)

{
  void *in_ECX;
  
  FUN_00724de0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00725740 @ 0x00725740 ====

void FUN_00725740(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edd08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00725760 @ 0x00725760 ====

undefined4 FUN_00725760(void)

{
  return 0x70360006;
}


// ==== FUN_00725770 @ 0x00725770 ====

undefined4 FUN_00725770(void)

{
  return 0x70360007;
}


// ==== FUN_00725780 @ 0x00725780 ====

undefined4 FUN_00725780(void)

{
  return 0x70360008;
}


// ==== FUN_00725790 @ 0x00725790 ====

void FUN_00725790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edd64;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae4c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae4c = in_ECX;
  return;
}


// ==== FUN_007257c0 @ 0x007257c0 ====

void FUN_007257c0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *in_ECX;
  
  *(short *)(in_ECX + 1) = (short)param_1;
  if ((short)param_2 == 0) {
    (**(code **)(*DAT_00b5ae48 + 0x28))(0,0);
  }
  else {
    (**(code **)(*DAT_00b5ae48 + 0x28))(1,param_2);
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 4))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
    (**(code **)(*piVar1 + 0x2c))(param_2);
    (**(code **)(*in_ECX + 0x18))();
  }
  return;
}


// ==== FUN_00725820 @ 0x00725820 ====

void FUN_00725820(void)

{
  short sVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 6) == '\x01') {
    piVar2 = (int *)(**(code **)(*in_ECX + 4))();
    sVar1 = (**(code **)(*piVar2 + 0x30))();
    if (sVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0072583f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*in_ECX + 0x14))();
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x00725845. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0x18))();
    return;
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 4))();
  sVar1 = (**(code **)(*piVar2 + 0x30))();
  if (sVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0072585c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0x14))();
    return;
  }
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)((int)in_ECX + 6) = 1;
    return;
  }
  *puVar3 = &PTR_FUN_009edd28;
  FUN_00797a20(puVar3);
  *(undefined1 *)((int)in_ECX + 6) = 1;
  return;
}


// ==== FUN_007258a0 @ 0x007258a0 ====

void FUN_007258a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009edd3c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 6) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 6) = 0;
  }
  return;
}


// ==== FUN_007258e0 @ 0x007258e0 ====

void FUN_007258e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009edd50;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00725910 @ 0x00725910 ====

void FUN_00725910(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae4c = 0;
  *in_ECX = &PTR_FUN_009edd08;
  return;
}


// ==== FUN_00725930 @ 0x00725930 ====

undefined4 FUN_00725930(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00b5a97c == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0072594c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x70) + 0x14))();
  return uVar2;
}


// ==== FUN_00725950 @ 0x00725950 ====

void FUN_00725950(int param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 local_14 [20];
  
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    param_1 = param_1 + 4;
  }
  else {
    param_1 = *(int *)(param_1 + 4);
  }
  FUN_006915e0(local_14,&DAT_009edd00,param_1);
  piVar2 = (int *)(**(code **)(*in_ECX + 4))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))(local_14);
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x28))();
    if (cVar1 == '\0') {
      (**(code **)(*piVar2 + 0x24))(1);
    }
  }
  return;
}


// ==== FUN_007259b0 @ 0x007259b0 ====

void FUN_007259b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00725910();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007259d0 @ 0x007259d0 ====

void FUN_007259d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edde4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007259f0 @ 0x007259f0 ====

void FUN_007259f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eddf0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae38 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae38 = in_ECX;
  return;
}


// ==== FUN_00725a20 @ 0x00725a20 ====

void FUN_00725a20(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar1 != 0) {
    FUN_008282c0(iVar1,*(undefined1 *)(param_1 + 0x14));
    (**(code **)(*DAT_00b5ae3c + 4))();
  }
  return;
}


// ==== FUN_00725a50 @ 0x00725a50 ====

void FUN_00725a50(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar1 != 0) {
    FUN_00828310(iVar1,param_1 + 0x10);
    (**(code **)(*DAT_00b5ae3c + 4))();
  }
  return;
}


// ==== FUN_00725a80 @ 0x00725a80 ====

void FUN_00725a80(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae38 = 0;
  *in_ECX = &PTR_FUN_009edde4;
  return;
}


// ==== FUN_00725aa0 @ 0x00725aa0 ====

void FUN_00725aa0(void)

{
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990c48;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x3ee0015;
  uStack_38 = 0;
  uStack_3c = 0x725acc;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x725ae9;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_00725b50 @ 0x00725b50 ====

void FUN_00725b50(void)

{
  int iVar1;
  undefined1 auStack_2a [6];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990c5a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar1 != 0) {
    FUN_00828340();
    (**(code **)(*DAT_00b5ae3c + 4))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x0;
    FUN_00401660(auStack_2a + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00725c20 @ 0x00725c20 ====

void FUN_00725c20(int param_1)

{
  int *piVar1;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  char cStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990c6c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iStack_40 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iStack_40 != 0) {
    uStack_44 = 0x725c5d;
    piVar1 = (int *)FUN_00828360();
    if (piVar1 == (int *)0x0) {
      iStack_40 = 0;
      uStack_44 = 0x725c79;
      uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_44 = 0xffffffff;
      uStack_48 = 0;
      uStack_18 = 0xf;
      uStack_1c = 0;
      uStack_2c = 0;
      uStack_50 = 0x725c97;
      FUN_00401660();
      puStack_4 = auStack_5c;
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_c = (void *)0x0;
      uStack_58 = 0;
      FUN_00401660(&uStack_30,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_10) {
        iStack_40 = 0x725cd8;
        _free(pvStack_24);
        return;
      }
    }
    else {
      uStack_2e = *(undefined1 *)(param_1 + 0x30);
      uStack_30 = *(undefined2 *)(param_1 + 0x2e);
      uStack_2c = *(undefined1 *)(param_1 + 0x2c);
      cStack_2d = *(char *)(param_1 + 0x31);
      uStack_2b = 1;
      if (cStack_2d != '\0') {
        cStack_2d = cStack_2d + -1;
      }
      iStack_40 = 0x725d2a;
      (**(code **)(*piVar1 + 0x10))();
      iStack_40 = 0x725d35;
      (**(code **)(*DAT_00b5ae3c + 4))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00725d50 @ 0x00725d50 ====

void FUN_00725d50(int param_1)

{
  int *piVar1;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  char cStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990c7e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iStack_40 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iStack_40 != 0) {
    uStack_44 = 0x725d8d;
    piVar1 = (int *)FUN_00828360();
    if (piVar1 == (int *)0x0) {
      iStack_40 = 0;
      uStack_44 = 0x725da9;
      uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_44 = 0xffffffff;
      uStack_48 = 0;
      uStack_18 = 0xf;
      uStack_1c = 0;
      uStack_2c = 0;
      uStack_50 = 0x725dc7;
      FUN_00401660();
      puStack_4 = auStack_5c;
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_c = (void *)0x0;
      uStack_58 = 0;
      FUN_00401660(&uStack_30,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_10) {
        iStack_40 = 0x725e08;
        _free(pvStack_24);
        return;
      }
    }
    else {
      uStack_2e = *(undefined1 *)(param_1 + 0x30);
      uStack_30 = *(undefined2 *)(param_1 + 0x2e);
      uStack_2c = *(undefined1 *)(param_1 + 0x2c);
      cStack_2d = *(char *)(param_1 + 0x31);
      uStack_2b = 1;
      if (cStack_2d != '\0') {
        cStack_2d = cStack_2d + -1;
      }
      iStack_40 = 0x725e5a;
      (**(code **)(*piVar1 + 0x10))();
      iStack_40 = 0x725e65;
      (**(code **)(*DAT_00b5ae3c + 4))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00725e80 @ 0x00725e80 ====

void FUN_00725e80(int param_1)

{
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_30 [36];
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990cc8;
  local_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x2c)) {
  case 0:
    uStack_48 = 0x3ee001d;
    uStack_4c = 0;
    uStack_50 = 0x725ec2;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x725ecc;
    FUN_00765c50();
    local_c = (void *)0x0;
    break;
  case 1:
    uStack_48 = 0x3ee001e;
    uStack_4c = 0;
    uStack_50 = 0x725eeb;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x725ef5;
    FUN_00765c50();
    local_c = (void *)0x1;
    goto LAB_00725efd;
  case 2:
    uStack_48 = 0x3ee001f;
    uStack_4c = 0;
    uStack_50 = 0x725f37;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x725f41;
    FUN_00765c50();
    local_c = (void *)0x2;
    break;
  case 3:
    uStack_48 = 0x3ee001a;
    uStack_4c = 0;
    uStack_50 = 0x725f60;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x725f6a;
    FUN_00765c50();
    local_c = (void *)0x3;
LAB_00725efd:
    puStack_4 = auStack_68;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_00726077;
  case 4:
    uStack_48 = 0x3ee0020;
    uStack_4c = 0;
    uStack_50 = 0x725f86;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x725f90;
    FUN_00765c50();
    local_c = (void *)0x4;
    break;
  case 5:
    uStack_48 = 0x3ee0026;
    uStack_4c = 0;
    uStack_50 = 0x725fac;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x725fb6;
    FUN_00765c50();
    puStack_4 = auStack_68;
    local_c = (void *)0x5;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_00726077;
  case 6:
    uStack_48 = 0x3ee0027;
    uStack_4c = 0;
    uStack_50 = 0x725ff8;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x726002;
    FUN_00765c50();
    local_c = (void *)0x6;
    break;
  case 7:
    uStack_48 = 0x3ee0021;
    uStack_4c = 0;
    uStack_50 = 0x726041;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x72604b;
    FUN_00765c50();
    puStack_4 = auStack_68;
    local_c = (void *)0x7;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_00726077;
  default:
    return;
  }
  puStack_4 = auStack_68;
  FUN_00765c50(&uStack_4c);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_00726077:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_007260b0 @ 0x007260b0 ====

void FUN_007260b0(int param_1)

{
  int *piVar1;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  char cStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990cda;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puStack_40 = (undefined1 *)(**(code **)(*DAT_00b5a980 + 8))();
  if (puStack_40 != (undefined1 *)0x0) {
    uStack_44 = 0x7260ed;
    piVar1 = (int *)FUN_00828360();
    if (piVar1 == (int *)0x0) {
      puStack_40 = (undefined1 *)0x0;
      uStack_44 = 0x726109;
      uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_44 = 0xffffffff;
      uStack_48 = 0;
      uStack_18 = 0xf;
      uStack_1c = 0;
      uStack_2c = 0;
      uStack_50 = 0x726127;
      FUN_00401660();
      puStack_4 = auStack_5c;
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_c = (void *)0x0;
      uStack_58 = 0;
      FUN_00401660(&uStack_30,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_10) {
        puStack_40 = &LAB_00726168;
        _free(pvStack_24);
        return;
      }
    }
    else {
      uStack_2e = *(undefined1 *)(param_1 + 0x48);
      uStack_30 = *(undefined2 *)(param_1 + 0x46);
      uStack_2c = *(undefined1 *)(param_1 + 0x45);
      cStack_2d = *(char *)(param_1 + 0x49);
      uStack_2b = 1;
      if (cStack_2d != '\0') {
        cStack_2d = cStack_2d + -1;
      }
      puStack_40 = (undefined1 *)0x7261ba;
      (**(code **)(*piVar1 + 0x10))();
      puStack_40 = (undefined1 *)0x7261c5;
      (**(code **)(*DAT_00b5ae3c + 4))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_007261e0 @ 0x007261e0 ====

/* WARNING: Removing unreachable block (ram,0x00726223) */

void FUN_007261e0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 0x2d);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(param_1 + 0x2d),(int)pcVar2 - (param_1 + 0x2e));
  return;
}


// ==== FUN_00726240 @ 0x00726240 ====

void FUN_00726240(int param_1)

{
  char cVar1;
  int iVar2;
  void *unaff_EBX;
  uint unaff_ESI;
  char *pcVar3;
  void *pvStack_44;
  undefined1 local_28 [2];
  undefined1 auStack_26 [2];
  undefined1 local_24;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00990cec;
  pvStack_c = ExceptionList;
  pcVar3 = (char *)(param_1 + 0x10);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
    if (*(char *)(iVar2 + 0xb) == '\x01') {
      FUN_00401660(local_28,0,0xffffffff);
      (**(code **)(*DAT_00b5ae3c + 0x9c))();
    }
    else {
      cVar1 = (**(code **)(*DAT_00b5ae3c + 0x54))();
      if (cVar1 == '\x01') {
        FUN_00401660(local_28,0);
        (**(code **)(*DAT_00b5ae3c + 0xa8))();
      }
      else {
        (**(code **)(*DAT_00b5ae3c + 0x50))();
        FUN_00401660(local_28 + -4,0,0xffffffff);
        (**(code **)(*DAT_00b5ae3c + 0x48))();
      }
    }
  }
  else {
    FUN_00401660(local_28,0,0xffffffff);
    (**(code **)(*DAT_00b5ae3c + 0x9c))();
  }
  if (unaff_ESI < 0x10) {
    ExceptionList = unaff_EBX;
    return;
  }
  _free(pvStack_44);
  return;
}


// ==== FUN_007263d0 @ 0x007263d0 ====

void FUN_007263d0(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *unaff_ESI;
  undefined4 uStack_94;
  undefined1 *puStack_90;
  undefined1 auStack_8c [20];
  undefined1 *puStack_78;
  undefined4 ****ppppuStack_74;
  char *pcStack_70;
  undefined1 auStack_5e [2];
  void *local_5c;
  uint uStack_50;
  undefined4 ****local_48 [5];
  uint uStack_34;
  undefined1 auStack_30 [36];
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990d36;
  local_c = ExceptionList;
  pcStack_70 = (char *)(param_1 + 0x2d);
  local_48[0] = (undefined4 ****)0xf;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  pcVar2 = pcStack_70;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ppppuStack_74 = (undefined4 ****)0x726426;
  ExceptionList = &local_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  switch(*(undefined1 *)(param_1 + 0x2c)) {
  case 0:
    pcStack_70 = (char *)0x0;
    ppppuStack_74 = (undefined4 ****)0x726459;
    ppppuStack_74 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_78 = (undefined1 *)0x726463;
    FUN_00765c50();
    local_c._0_1_ = 1;
    ppppuStack_74 = local_48[0];
    if (uStack_34 < 0x10) {
      ppppuStack_74 = local_48;
    }
    if (uStack_50 < 0x10) {
      unaff_ESI = auStack_5e + -6;
    }
    local_4 = (undefined1 *)&uStack_94;
    puStack_78 = unaff_ESI;
    FUN_00401830(&DAT_009eddc0);
    FUN_00404230(auStack_30);
    local_4 = auStack_8c;
    puStack_90 = auStack_30;
    local_c = (void *)CONCAT31(local_c._1_3_,2);
    uStack_94 = 0x7264c4;
    FUN_00765c50();
    puStack_90 = (undefined1 *)0x2;
    uStack_94 = 0x7264d1;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    uStack_94 = 0x7264da;
    FUN_00446f10();
  case 1:
    pcStack_70 = (char *)0x0;
    ppppuStack_74 = (undefined4 ****)0x7264f5;
    ppppuStack_74 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_78 = (undefined1 *)0x7264ff;
    FUN_00765c50();
    local_c = (void *)CONCAT31(local_c._1_3_,3);
    break;
  case 2:
    pcStack_70 = (char *)0x0;
    ppppuStack_74 = (undefined4 ****)0x72651b;
    ppppuStack_74 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_78 = (undefined1 *)0x726525;
    FUN_00765c50();
    local_c = (void *)CONCAT31(local_c._1_3_,4);
    goto LAB_00726570;
  case 3:
    pcStack_70 = (char *)0x0;
    ppppuStack_74 = (undefined4 ****)0x72653e;
    ppppuStack_74 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_78 = (undefined1 *)0x726548;
    FUN_00765c50();
    local_c = (void *)CONCAT31(local_c._1_3_,5);
    break;
  case 4:
    pcStack_70 = (char *)0x0;
    ppppuStack_74 = (undefined4 ****)0x726561;
    ppppuStack_74 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_78 = (undefined1 *)0x72656b;
    FUN_00765c50();
    local_c = (void *)CONCAT31(local_c._1_3_,6);
LAB_00726570:
    local_4 = auStack_8c;
    puStack_90 = auStack_30;
    uStack_94 = 0x726586;
    FUN_00765c50();
    puStack_90 = (undefined1 *)0x2;
    uStack_94 = 0x726593;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_007265d9;
  case 5:
    pcStack_70 = (char *)0x0;
    ppppuStack_74 = (undefined4 ****)0x7265a7;
    ppppuStack_74 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_78 = (undefined1 *)0x7265b1;
    FUN_00765c50();
    local_c = (void *)CONCAT31(local_c._1_3_,7);
    break;
  default:
    if (local_48[0] < (undefined4 ****)0x10) {
      ExceptionList = local_c;
      return;
    }
    pcStack_70 = (char *)0x7265f2;
    _free(local_5c);
    return;
  }
  local_4 = auStack_8c;
  puStack_90 = auStack_30;
  uStack_94 = 0x7265cc;
  FUN_00765c50();
  puStack_90 = (undefined1 *)0x2;
  uStack_94 = 0x7265d9;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_007265d9:
                    /* WARNING: Subroutine does not return */
  uStack_94 = 0x7265e2;
  FUN_00446f10();
}


// ==== FUN_00726620 @ 0x00726620 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00726620(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack_dc;
  uint uStack_d8;
  undefined1 auStack_d4 [4];
  undefined1 uStack_d0;
  undefined4 uStack_c8;
  int iStack_c4;
  undefined4 *******pppppppuStack_c0;
  undefined4 *******pppppppuStack_bc;
  char *pcStack_b8;
  undefined1 auStack_9e [6];
  void *pvStack_98;
  undefined4 *******apppppppuStack_84 [2];
  void *pvStack_7c;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 *puStack_6c;
  uint auStack_68 [3];
  void *pvStack_5c;
  undefined4 uStack_4c;
  undefined4 *******apppppppuStack_48 [2];
  void *local_40;
  uint uStack_34;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00990d79;
  pvStack_c = ExceptionList;
  pcStack_b8 = (char *)(param_1 + 0x2d);
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  pcVar2 = pcStack_b8;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pppppppuStack_bc = (undefined4 *******)0x726686;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  cVar1 = *(char *)(param_1 + 0x2c);
  local_4 = 0;
  if (cVar1 == '\0') {
    pcStack_b8 = (char *)0x0;
    pppppppuStack_bc = (undefined4 *******)0x7267a0;
    iStack_c4 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pppppppuStack_bc = (undefined4 *******)0xffffffff;
    pppppppuStack_c0 = (undefined4 *******)0x0;
    uStack_70 = 0xf;
    uStack_74 = 0;
    apppppppuStack_84[0] = (undefined4 *******)((uint)apppppppuStack_84[0] & 0xffffff00);
    uStack_c8 = 0x7267b9;
    FUN_00401660();
    pvStack_c._0_1_ = 1;
    pppppppuStack_bc = apppppppuStack_84[0];
    if (uStack_70 < 0x10) {
      pppppppuStack_bc = apppppppuStack_84;
    }
    pppppppuStack_c0 = apppppppuStack_48[0];
    if (uStack_34 < 0x10) {
      pppppppuStack_c0 = apppppppuStack_48;
    }
    puStack_6c = (undefined1 *)&uStack_dc;
    iStack_c4 = 0xf;
    uStack_c8 = 0;
    uStack_d8 = uStack_d8 & 0xffffff00;
    FUN_00401740(&DAT_009eddc8,4);
    FUN_00404230(auStack_68);
    puStack_6c = auStack_d4;
    uStack_d8 = 0xffffffff;
    uStack_dc = 0;
    pppppppuStack_bc = (undefined4 *******)0xf;
    pppppppuStack_c0 = (undefined4 *******)0x0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
    uStack_d0 = 0;
    FUN_00401660(auStack_68);
    uStack_d8 = 2;
    uStack_dc = 0x72683e;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_dc = 0x726849;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      if ((undefined4 *******)0xf < apppppppuStack_48[0]) {
        pcStack_b8 = (char *)0x72685f;
        _free(pvStack_5c);
        return;
      }
      apppppppuStack_48[0] = (undefined4 *******)0xf;
      uStack_4c = 0;
      pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
      if (0xf < auStack_68[0]) {
        pcStack_b8 = (char *)0x72687e;
        _free(pvStack_7c);
        return;
      }
      auStack_68[0] = 0xf;
      puStack_6c = (undefined1 *)0x0;
      pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
    }
    else {
      pcStack_b8 = (char *)0x7268b2;
      FUN_00401830();
      local_4 = CONCAT31(local_4._1_3_,3);
      pppppppuStack_bc = (undefined4 *******)auStack_25;
      pcStack_b8 = &DAT_009eddd8;
      pppppppuStack_c0 = (undefined4 *******)0x7268db;
      FUN_0047aa30();
      pppppppuStack_c0 = (undefined4 *******)auStack_25;
      uStack_c8 = 0x7268e9;
      iStack_c4 = iVar3;
      FUN_00828380();
      (**(code **)(*DAT_00b5ae3c + 4))();
      if ((undefined4 *******)0xf < apppppppuStack_84[0]) {
        pcStack_b8 = (char *)0x726907;
        _free(pvStack_98);
        return;
      }
      apppppppuStack_84[0] = (undefined4 *******)0xf;
      if ((undefined4 *******)0xf < apppppppuStack_48[0]) {
        pcStack_b8 = (char *)0x726926;
        _free(pvStack_5c);
        return;
      }
      apppppppuStack_48[0] = (undefined4 *******)0xf;
      uStack_4c = 0;
      pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
      if (0xf < auStack_68[0]) {
        pvStack_98 = pvStack_7c;
        goto LAB_00726940;
      }
    }
  }
  else if (cVar1 == '\x01') {
    pcStack_b8 = (char *)0x0;
    pppppppuStack_bc = (undefined4 *******)0x72672f;
    iStack_c4 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pppppppuStack_bc = (undefined4 *******)0xffffffff;
    pppppppuStack_c0 = (undefined4 *******)0x0;
    uStack_c8 = 0x726748;
    FUN_00401660();
    uStack_d8 = 0xffffffff;
    uStack_dc = 0;
    pppppppuStack_bc = (undefined4 *******)0xf;
    pppppppuStack_c0 = (undefined4 *******)0x0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
    uStack_d0 = 0;
    FUN_00401660(auStack_9e + -6);
    uStack_d8 = 2;
    uStack_dc = 0x72677c;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if ((undefined4 *******)0xf < apppppppuStack_84[0]) {
LAB_00726940:
      pcStack_b8 = (char *)0x726945;
      _free(pvStack_98);
      return;
    }
  }
  else if (cVar1 == '\x02') {
    pcStack_b8 = (char *)0x0;
    pppppppuStack_bc = (undefined4 *******)0x7266bd;
    iStack_c4 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pppppppuStack_bc = (undefined4 *******)0xffffffff;
    pppppppuStack_c0 = (undefined4 *******)0x0;
    uStack_c8 = 0x7266d6;
    FUN_00401660();
    uStack_d8 = 0xffffffff;
    uStack_dc = 0;
    pppppppuStack_bc = (undefined4 *******)0xf;
    pppppppuStack_c0 = (undefined4 *******)0x0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
    uStack_d0 = 0;
    FUN_00401660(auStack_9e + -6);
    uStack_d8 = 2;
    uStack_dc = 0x72670a;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if ((undefined4 *******)0xf < apppppppuStack_84[0]) goto LAB_00726940;
  }
  if (local_2c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  pcStack_b8 = (char *)0x72695b;
  _free(local_40);
  return;
}


// ==== FUN_00726980 @ 0x00726980 ====

void FUN_00726980(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 ****ppppuStack_a8;
  char *pcStack_a4;
  undefined4 ****appppuStack_70 [3];
  undefined4 ****appppuStack_64 [2];
  void *pvStack_5c;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 ****appppuStack_48 [2];
  void *pvStack_40;
  uint uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990d9b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 != 0) {
    pcStack_a4 = (char *)(param_1 + 0x32);
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar3 = pcStack_a4;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    ppppuStack_a8 = (undefined4 ****)0x7269ee;
    FUN_00401740();
    pcStack_a4 = (char *)0x0;
    uStack_4 = 0;
    ppppuStack_a8 = (undefined4 ****)0x726a06;
    uStack_b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    ppppuStack_a8 = (undefined4 ****)0xffffffff;
    uStack_ac = (undefined4 ****)0x0;
    uStack_50 = 0xf;
    uStack_54 = 0;
    appppuStack_64[0] = (undefined4 ****)((uint)appppuStack_64[0] & 0xffffff00);
    FUN_00401660();
    pvStack_c._0_1_ = 1;
    ppppuStack_a8 = appppuStack_64[0];
    if (uStack_50 < 0x10) {
      ppppuStack_a8 = appppuStack_64;
    }
    uStack_ac = appppuStack_48[0];
    if (uStack_34 < 0x10) {
      uStack_ac = appppuStack_48;
    }
    uStack_b0 = 0xf;
    FUN_00401740(&DAT_009eddd0,4);
    FUN_00404230(&uStack_30);
    ppppuStack_a8 = (undefined4 ****)0xf;
    uStack_ac = (undefined4 ****)0x0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
    uStack_bc = uStack_bc & 0xffffff00;
    FUN_00401660(&uStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5ad1c + 0x28))(&uStack_b0);
    if (pvStack_5c < (void *)0x10) {
      appppuStack_70[0] = appppuStack_70;
    }
    FUN_0047aa30((int)&uStack_ac + 3,&DAT_009eddd8,appppuStack_70[0]);
    FUN_008283b0(0,(int)&uStack_ac + 3,*(undefined2 *)(uStack_2c + 0x2e),uStack_b8,uStack_bc,
                 *(undefined1 *)(uStack_2c + 0x2c),1);
    (**(code **)(*DAT_00b5ae3c + 4))();
    if (0xf < uStack_10) {
      pcStack_a4 = (char *)0x726b2b;
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    if ((undefined4 ****)0xf < appppuStack_48[0]) {
      pcStack_a4 = (char *)0x726b50;
      _free(pvStack_5c);
      return;
    }
    appppuStack_48[0] = (undefined4 ****)0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    if (0xf < uStack_2c) {
      pcStack_a4 = (char *)0x726b6f;
      _free(pvStack_40);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00726b90 @ 0x00726b90 ====

void FUN_00726b90(int param_1)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  undefined1 auStack_dc [4];
  undefined1 uStack_d8;
  undefined4 uStack_d0;
  undefined1 *puStack_cc;
  char **ppcStack_c8;
  uint *puStack_c4;
  char *pcStack_c0;
  int iStack_bc;
  undefined1 uStack_b8;
  undefined1 uStack_b4;
  undefined1 *puStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  char *pcStack_a4;
  int iStack_a0;
  void *pvStack_78;
  undefined1 auStack_6c [4];
  undefined4 uStack_68;
  uint uStack_64;
  void *pvStack_5c;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_48;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 uStack_28;
  void *pvStack_24;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990dc5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iStack_a0 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iStack_a0 != 0) {
    pcVar1 = (char *)(param_1 + 0x2c);
    pcStack_a4 = (char *)0x726bd2;
    piVar3 = (int *)FUN_00828360();
    if (piVar3 == (int *)0x0) {
      iStack_a0 = 0;
      pcStack_a4 = (char *)0x726bea;
      uStack_ac = (**(code **)(*DAT_00b5a794 + 0xc))();
      pcStack_a4 = (char *)0xffffffff;
      uStack_a8 = 0;
      uStack_50 = 0xf;
      uStack_54 = 0;
      uStack_64 = uStack_64 & 0xffffff00;
      puStack_b0 = (undefined1 *)0x726c08;
      FUN_00401660();
      pcStack_c0 = (char *)0xffffffff;
      puStack_c4 = (uint *)0x0;
      ppcStack_c8 = (char **)&uStack_68;
      pcStack_a4 = (char *)0xf;
      uStack_a8 = 0;
      pvStack_c = (void *)0x0;
      uStack_b8 = 0;
      puStack_cc = (undefined1 *)0x726c2e;
      FUN_00401660();
      pcStack_c0 = (char *)0x2;
      puStack_c4 = (uint *)0x726c3b;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (0xf < uStack_48) goto LAB_00726dd9;
    }
    else {
      iStack_a0 = 0x726c8c;
      (**(code **)(*piVar3 + 0x10))();
      iStack_a0 = 0x726c97;
      (**(code **)(*DAT_00b5ae3c + 4))();
      uStack_14 = 0xf;
      uStack_18 = 0;
      uStack_28 = 0;
      pcVar4 = pcVar1;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      iStack_a0 = (int)pcVar4 - (param_1 + 0x2d);
      uStack_a8 = 0x726cc9;
      pcStack_a4 = pcVar1;
      FUN_00401740();
      iStack_bc = 0xffffffff;
      pcStack_c0 = (char *)0x0;
      puStack_c4 = &uStack_2c;
      iStack_a0 = 0xf;
      pcStack_a4 = (char *)0x0;
      puStack_8 = (undefined1 *)0x1;
      uStack_b4 = 0;
      ppcStack_c8 = (char **)0x726cf6;
      FUN_00401660();
      iStack_bc = 0x726d04;
      (**(code **)(*DAT_00b5ae3c + 0x90))();
      pcVar4 = pcVar1;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      iStack_bc = (int)pcVar4 - (param_1 + 0x2d);
      puStack_c4 = (uint *)0x726d2b;
      pcStack_c0 = pcVar1;
      FUN_00401740();
      iStack_bc = 0x3ee002d;
      pcStack_c0 = (char *)0x0;
      pvStack_24 = (void *)CONCAT31(pvStack_24._1_3_,2);
      puStack_c4 = (uint *)0x726d44;
      puStack_c4 = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
      ppcStack_c8 = &pcStack_a4;
      puStack_cc = auStack_6c;
      uStack_d0 = 0x726d54;
      FUN_00405bd0();
      puStack_b0 = auStack_dc;
      puStack_c4 = (uint *)0xf;
      ppcStack_c8 = (char **)0x0;
      uStack_2c = CONCAT31(uStack_2c._1_3_,3);
      uStack_d8 = 0;
      FUN_00401660(auStack_6c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_2c) {
        iStack_a0 = 0x726d9d;
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      if (0xf < uStack_64) {
        iStack_a0 = 0x726dbc;
        _free(pvStack_78);
        return;
      }
      uStack_64 = 0xf;
      uStack_68 = 0;
      if (0xf < uStack_10) {
        pvStack_5c = pvStack_24;
LAB_00726dd9:
        iStack_a0 = 0x726dde;
        _free(pvStack_5c);
        return;
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00726e00 @ 0x00726e00 ====

void FUN_00726e00(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_ec [4];
  undefined1 uStack_e8;
  undefined4 uStack_e0;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  uint uStack_cc;
  undefined1 *puStack_c8;
  undefined4 uStack_c4;
  undefined1 *puStack_c0;
  undefined1 *puStack_bc;
  char *pcStack_b8;
  undefined1 auStack_a0 [4];
  void *pvStack_9c;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined1 auStack_84 [4];
  void *pvStack_80;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 *puStack_68;
  void *pvStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 *puStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990e05;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 != 0) {
    pcStack_b8 = (char *)(param_1 + 0x2c);
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    pcVar3 = pcStack_b8;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puStack_bc = (undefined1 *)0x726e69;
    FUN_00401740();
    pcStack_b8 = (char *)(param_1 + 0x10);
    uStack_4 = 0;
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    pcVar3 = pcStack_b8;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puStack_bc = (undefined1 *)0x726e9e;
    FUN_00401740();
    pcStack_b8 = (char *)(param_1 + 0x45);
    uStack_4._0_1_ = 1;
    uStack_6c = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    pcVar3 = pcStack_b8;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puStack_bc = (undefined1 *)0x726ed6;
    FUN_00401740();
    uStack_4._0_1_ = 2;
    cVar1 = (**(code **)(*DAT_00b5ae3c + 0x5c))();
    puStack_d8 = auStack_a0;
    if (cVar1 == '\0') {
      puStack_68 = (undefined1 *)&uStack_cc;
      uStack_d0 = 0xffffffff;
      uStack_d4 = 0;
      pcStack_b8 = (char *)0x0;
      puStack_c8 = (undefined1 *)((uint)puStack_c8 & 0xffffff00);
      puStack_dc = (undefined1 *)0x726f10;
      FUN_00401660();
      uStack_d0 = 0x726f1e;
      (**(code **)(*DAT_00b5ae3c + 0xac))();
      if (0xf < uStack_6c) {
        pcStack_b8 = (char *)0x726f33;
        _free(pvStack_80);
        return;
      }
      uStack_6c = 0xf;
      uStack_70 = 0;
      pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
      if (0xf < uStack_88) {
        pcStack_b8 = (char *)0x726f52;
        _free(pvStack_9c);
        return;
      }
    }
    else {
      puStack_bc = auStack_28;
      puStack_c0 = (undefined1 *)0x726f88;
      pcStack_b8 = puStack_d8;
      uStack_c4 = FUN_00402220();
      puStack_c0 = auStack_84;
      puStack_c8 = auStack_44;
      uStack_4._0_1_ = 3;
      uStack_cc = 0x726fa3;
      puStack_bc = (undefined1 *)FUN_00405bd0();
      pcStack_b8 = (char *)0x0;
      uStack_4._0_1_ = 4;
      puStack_c0 = (undefined1 *)0x726fbb;
      FUN_00401660();
      if (0xf < uStack_2c) {
        pcStack_b8 = (char *)0x726fd3;
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      uStack_4._0_1_ = 2;
      if (0xf < uStack_10) {
        pcStack_b8 = (char *)0x727006;
        _free(pvStack_24);
        return;
      }
      puStack_68 = (undefined1 *)&uStack_d0;
      uStack_d4 = 0xffffffff;
      puStack_d8 = (undefined1 *)0x0;
      puStack_dc = auStack_84;
      pcStack_b8 = (char *)0xf;
      puStack_bc = (undefined1 *)0x0;
      uStack_cc = uStack_cc & 0xffffff00;
      uStack_e0 = 0x727029;
      FUN_00401660();
      puStack_48 = auStack_ec;
      uStack_d4 = 0xf;
      puStack_d8 = (undefined1 *)0x0;
      uStack_4._0_1_ = 5;
      uStack_e8 = 0;
      FUN_00401660(auStack_a0,0,0xffffffff);
      uStack_4._0_1_ = 2;
      (**(code **)(*DAT_00b5ae40 + 0x14))();
      if (0xf < uStack_6c) {
        pcStack_b8 = (char *)0x727076;
        _free(pvStack_80);
      }
      uStack_6c = 0xf;
      uStack_70 = 0;
      pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
      if (0xf < uStack_88) {
        pcStack_b8 = (char *)0x727095;
        _free(pvStack_9c);
        return;
      }
    }
    if (0xf < uStack_4c) {
      uStack_6c = 0xf;
      uStack_70 = 0;
      uStack_88 = 0xf;
      uStack_8c = 0;
      pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
      pcStack_b8 = (char *)0x7270b4;
      _free(pvStack_60);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_007270e0 @ 0x007270e0 ====

void FUN_007270e0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_88;
  undefined4 *puStack_84;
  undefined4 *puStack_80;
  undefined1 *puStack_7c;
  char *pcStack_78;
  undefined1 auStack_5e [2];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990e27;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 != 0) {
    pcStack_78 = (char *)(param_1 + 0x10);
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar3 = pcStack_78;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puStack_7c = (undefined1 *)0x727146;
    FUN_00401740();
    pcStack_78 = (char *)0x0;
    puStack_4 = (undefined1 *)0x0;
    puStack_7c = (undefined1 *)0x72715b;
    puStack_84 = (undefined4 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_7c = (undefined1 *)0xffffffff;
    puStack_80 = (undefined4 *)0x0;
    uStack_88 = 0x727174;
    FUN_00401660();
    puStack_7c = auStack_5e + -10;
    puStack_80 = &uStack_30;
    puStack_84 = &uStack_4c;
    pvStack_c._0_1_ = 1;
    uStack_88 = 0x72718d;
    FUN_00405bd0();
    puStack_4 = auStack_94;
    puStack_7c = (undefined1 *)0xf;
    puStack_80 = (undefined4 *)0x0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
    uStack_90 = 0;
    FUN_00401660(&uStack_4c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_2c) {
      pcStack_78 = (char *)0x7271d9;
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    if (0xf < uStack_48) {
      pcStack_78 = (char *)0x7271f8;
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    if (0xf < uStack_10) {
      pcStack_78 = (char *)0x727217;
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00727230 @ 0x00727230 ====

undefined4 FUN_00727230(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0xa030001) {
    if (uVar1 == 0xa030000) {
      FUN_00725aa0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0xa020005) {
      if (uVar1 == 0xa020004) {
        FUN_00725e80(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 < 0xa020002) {
        if (uVar1 == 0xa020001) {
          FUN_007263d0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 == 0xa000000) {
          FUN_00726b90(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 == 0xa020000) {
          FUN_00726240(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
      else if (uVar1 == 0xa020002) {
        FUN_00725d50(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar1 == 0xa020006) {
        FUN_00726980(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xa020008) {
        FUN_00726620(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xa020009) {
        FUN_007260b0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else if (uVar1 < 0x14010003) {
    if (uVar1 == 0x14010002) {
      FUN_007261e0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0xa030001) {
      FUN_00725b50(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x14000002) {
      FUN_00725c20(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x14010001) {
      FUN_00726e00(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    if (uVar1 == 0x14010004) {
      FUN_00725a50(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x14010006) {
      FUN_007270e0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x14020000) {
      FUN_00725a20(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00727400 @ 0x00727400 ====

undefined4 FUN_00727400(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00727230(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00727430 @ 0x00727430 ====

void FUN_00727430(byte param_1)

{
  void *in_ECX;
  
  FUN_00725a80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00727450 @ 0x00727450 ====

void FUN_00727450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edf54;
  return;
}


// ==== FUN_00727460 @ 0x00727460 ====

void FUN_00727460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009edf54;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}


// ==== FUN_00727480 @ 0x00727480 ====

undefined1 FUN_00727480(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00727490 @ 0x00727490 ====

void FUN_00727490(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 5) = param_1;
  return;
}


// ==== FUN_007274a0 @ 0x007274a0 ====

undefined1 FUN_007274a0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 5);
}


// ==== FUN_007274b0 @ 0x007274b0 ====

void FUN_007274b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 6) = param_1;
  return;
}


// ==== FUN_007274c0 @ 0x007274c0 ====

undefined1 FUN_007274c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_007274d0 @ 0x007274d0 ====

void FUN_007274d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee030;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727500 @ 0x00727500 ====

void FUN_00727500(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee044;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727530 @ 0x00727530 ====

void FUN_00727530(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee058;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727560 @ 0x00727560 ====

void FUN_00727560(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee008;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727590 @ 0x00727590 ====

void FUN_00727590(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee01c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007275c0 @ 0x007275c0 ====

void FUN_007275c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee06c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007275f0 @ 0x007275f0 ====

void FUN_007275f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee080;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727620 @ 0x00727620 ====

void FUN_00727620(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
    return;
  }
  *puVar1 = &PTR_FUN_009ee094;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00727660 @ 0x00727660 ====

void FUN_00727660(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009ee0a8;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_007276a0 @ 0x007276a0 ====

void FUN_007276a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee0bc;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007276d0 @ 0x007276d0 ====

void FUN_007276d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee0d0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727700 @ 0x00727700 ====

void FUN_00727700(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee0e4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00727740 @ 0x00727740 ====

void FUN_00727740(void)

{
                    /* WARNING: Could not recover jumptable at 0x00727748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae40 + 4))();
  return;
}


// ==== FUN_00727750 @ 0x00727750 ====

void FUN_00727750(void)

{
                    /* WARNING: Could not recover jumptable at 0x00727758. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae40 + 8))();
  return;
}


// ==== FUN_00727760 @ 0x00727760 ====

void FUN_00727760(void)

{
                    /* WARNING: Could not recover jumptable at 0x00727768. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae40 + 0x10))();
  return;
}


// ==== FUN_00727770 @ 0x00727770 ====

void FUN_00727770(void)

{
                    /* WARNING: Could not recover jumptable at 0x00727778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae40 + 0x20))();
  return;
}


// ==== FUN_00727780 @ 0x00727780 ====

void FUN_00727780(void)

{
                    /* WARNING: Could not recover jumptable at 0x00727788. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae40 + 0x24))();
  return;
}


// ==== FUN_00727790 @ 0x00727790 ====

void FUN_00727790(void)

{
                    /* WARNING: Could not recover jumptable at 0x00727798. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae40 + 0x28))();
  return;
}


// ==== FUN_007277a0 @ 0x007277a0 ====

void FUN_007277a0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *in_ECX;
  undefined4 unaff_EDI;
  undefined1 local_2;
  undefined1 local_1;
  
  (**(code **)(*DAT_00b5ad1c + 0x28))(&local_2,&local_1);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x14000001;
  *(undefined2 *)((int)pvVar2 + 6) = 0x34;
  iVar3 = FUN_004244d0();
  *(char *)(iVar3 + 0x30) = (char)((uint)unaff_EDI >> 0x10);
  *(char *)(iVar3 + 0x31) = (char)((uint)unaff_EDI >> 0x18);
  FUN_004d8570(iVar3);
  (**(code **)(*in_ECX + 0x50))(0);
  return;
}


// ==== FUN_00727820 @ 0x00727820 ====

void FUN_00727820(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x14010005;
  *(undefined2 *)((int)pvVar2 + 6) = 0x34;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00727860 @ 0x00727860 ====

void FUN_00727860(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint in_stack_0000001c;
  char acStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990e48;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x14000002;
  *(undefined2 *)((int)pvVar4 + 6) = 0x4c;
  iVar5 = FUN_004244d0();
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  FUN_0047aa30(acStack_25,&DAT_009edf34,puVar6);
  pcVar1 = (char *)(iVar5 + 0x32);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_25 + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_007278fc;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_007278fc:
  FUN_004d8570(iVar5);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00727930 @ 0x00727930 ====

void FUN_00727930(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint in_stack_0000001c;
  char acStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990e5a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xa020000;
  *(undefined2 *)((int)pvVar4 + 6) = 0x48;
  iVar5 = FUN_004244d0();
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  FUN_0047aa30(acStack_25,&DAT_009edf34,puVar6);
  pcVar1 = (char *)(iVar5 + 0x2c);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_25 + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_007279cc;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_007279cc:
  FUN_004d8570(iVar5);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00727a00 @ 0x00727a00 ====

void FUN_00727a00(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint in_stack_0000001c;
  char acStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990e6c;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xa020005;
  *(undefined2 *)((int)pvVar4 + 6) = 0x48;
  iVar5 = FUN_004244d0();
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  FUN_0047aa30(acStack_25,&DAT_009edf34,puVar6);
  pcVar1 = (char *)(iVar5 + 0x2c);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_25 + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_00727a9c;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_00727a9c:
  FUN_004d8570(iVar5);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00727ad0 @ 0x00727ad0 ====

void FUN_00727ad0(void *param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int *in_ECX;
  uint uVar8;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 in_stack_00000020;
  char acStack_25 [21];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990e7e;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xa020003;
  *(undefined2 *)((int)pvVar4 + 6) = 0x48;
  iVar5 = FUN_004244d0();
  *(undefined1 *)(iVar5 + 0x45) = in_stack_00000020;
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  FUN_0047aa30(acStack_25,&DAT_009edf34,puVar6);
  pcVar1 = (char *)(iVar5 + 0x2c);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_25 + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_00727b77;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_00727b77:
  FUN_004d8570(iVar5);
  (**(code **)(*in_ECX + 0x50))(0);
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00727bc0 @ 0x00727bc0 ====

void FUN_00727bc0(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint in_stack_0000001c;
  char acStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990e90;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0xa020007;
  *(undefined2 *)((int)pvVar4 + 6) = 0x48;
  iVar5 = FUN_004244d0();
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  FUN_0047aa30(acStack_25,&DAT_009edf34,puVar6);
  pcVar1 = (char *)(iVar5 + 0x2c);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_25 + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_00727c5c;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_00727c5c:
  FUN_004d8570(iVar5);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00727c90 @ 0x00727c90 ====

undefined4 FUN_00727c90(undefined1 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *unaff_ESI;
  uint unaff_retaddr;
  void *pvStack_28;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990ea2;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(&param_1,0,0xffffffff);
  uVar1 = (**(code **)(*DAT_00b5ae40 + 0x1c))();
  if (unaff_retaddr < 0x10) {
    ExceptionList = pvStack_28;
    return uVar1;
  }
  _free(unaff_ESI);
  return extraout_EAX;
}


// ==== FUN_00727d10 @ 0x00727d10 ====

void FUN_00727d10(undefined1 param_1)

{
  uint unaff_retaddr;
  undefined1 auStack_2c [4];
  void *local_28;
  undefined4 local_18;
  void *local_14;
  undefined1 *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990eb4;
  pvStack_c = ExceptionList;
  local_10 = auStack_2c;
  local_18 = 0;
  local_14 = (void *)0xf;
  local_4 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401660(&param_1,0,0xffffffff);
  (**(code **)(*DAT_00b5ae40 + 0x2c))();
  if (unaff_retaddr < 0x10) {
    ExceptionList = local_28;
    return;
  }
  _free(local_14);
  return;
}


// ==== FUN_00727d80 @ 0x00727d80 ====

void FUN_00727d80(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined4 *_Memory;
  undefined1 auStack_6e [6];
  uint *puVar1;
  undefined4 uStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  uint local_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990f16;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ee14c;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae3c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae3c = in_ECX;
  }
  uStack_5c = (uint *)0x0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 1;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740();
  uStack_5c = (uint *)0xe;
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740();
  uStack_5c = &local_28;
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740();
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740();
  puVar1 = &uStack_34;
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = uStack_1c & 0xffffff00;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s__name__009ede58);
  uStack_1c._0_1_ = 5;
  local_44 = 0xf;
  FUN_00401740(s_friend_del_009ede60);
  _Memory = &uStack_5c;
  uStack_1c = CONCAT31(uStack_1c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,1);
  if (0xf < unaff_EBP) {
    _free(&local_44);
    return;
  }
  local_28 = local_28 & 0xffffff00;
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  FUN_00401740(s__name__0_or_1_009ede6c,0xd);
  local_28._0_1_ = 7;
  FUN_00401740(s_friend_accept_009ede7c,0xd);
  local_28 = CONCAT31(local_28._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + 6,2,auStack_46 + -6);
  if ((uint *)0xf < uStack_5c) {
    _free(auStack_46 + -10);
    return;
  }
  uStack_5c = (uint *)0xf;
  uStack_34 = uStack_34 & 0xffffff00;
  if (0xf < local_40) {
    _free((void *)0x0);
    return;
  }
  local_40 = 0xf;
  local_44 = 0;
  FUN_00401740(s__name___chat__009ede8c,0xd);
  uStack_34._0_1_ = 9;
  uStack_5c = (uint *)0xf;
  FUN_00401740(s_friend_chat_009ede9c,0xb);
  uStack_34 = CONCAT31(uStack_34._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + -6,2,auStack_6e + 0x16);
  if ((uint *)0xf < puVar1) {
    _free(_Memory);
    return;
  }
  if (((uint)unaff_EBX & 0xffffff00) < 0x10) {
    ExceptionList = (void *)0x0;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_007280c0 @ 0x007280c0 ====

void FUN_007280c0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined4 local_2c;
  void *local_28;
  uint local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990f50;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ee14c;
  local_4 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  local_2c = in_ECX;
  FUN_00401740(s_show_messenger_009edea8,0xe);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_friend_add_009edeb8,10);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_friend_del_009edec4,10);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  pvStack_20 = (void *)0x0;
  FUN_00401740(s_friend_accept_009eded0,0xd);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  local_14 = local_14 & 0xffffff00;
  if (0xf < pvStack_20) {
    _free(unaff_EBP);
    return;
  }
  pvStack_20 = (void *)0xf;
  local_24 = 0;
  FUN_00401740(s_friend_chat_009edee0,0xb);
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x38);
  if (local_24 < 0x10) {
    DAT_00b5ae3c = 0;
    *in_ECX = &PTR_FUN_009edf54;
    ExceptionList = pvStack_20;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00728280 @ 0x00728280 ====

void FUN_00728280(undefined4 param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990f62;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ddcdc;
    puVar2[7] = 0xf;
    puVar2[6] = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
  }
  pcVar4 = param_2;
  if (in_stack_0000001c < 0x10) {
    pcVar4 = (char *)&param_2;
  }
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
  FUN_00797a20(puVar2);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00728330 @ 0x00728330 ====

void FUN_00728330(undefined1 param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  void *unaff_EBX;
  uint unaff_retaddr;
  uint in_stack_0000001c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990f74;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  puVar2 = operator_new(0x20);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &PTR_FUN_009ee0f8;
    puVar2[7] = 0xf;
    puVar2[6] = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
  }
  pcVar3 = param_2;
  if (in_stack_0000001c < 0x10) {
    pcVar3 = (char *)&param_2;
  }
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  FUN_00797a20();
  FUN_00401660(&param_1,0,0xffffffff);
  (**(code **)(*DAT_00b5ae40 + 0x18))();
  if (unaff_retaddr < 0x10) {
    ExceptionList = (void *)0x7283a5;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_00728410 @ 0x00728410 ====

void FUN_00728410(undefined1 param_1,void *param_2)

{
  undefined4 *puVar1;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined1 uStack0000003c;
  void *in_stack_00000040;
  uint in_stack_00000054;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990f96;
  local_c = ExceptionList;
  local_4 = 2;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ee10c;
    puVar1[6] = 0;
    puVar1[7] = 0xf;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[0xe] = 0xf;
    puVar1[0xd] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
    puVar1[0x15] = 0xf;
    puVar1[0x14] = 0;
    *(undefined1 *)(puVar1 + 0x10) = 0;
  }
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_00401660(&uStack00000020,0,0xffffffff);
  FUN_00401660(&uStack0000003c,0,0xffffffff);
  FUN_00797a20(puVar1);
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (0xf < in_stack_00000038) {
    _free(in_stack_00000024);
    return;
  }
  if (in_stack_00000054 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000040);
  return;
}


// ==== FUN_00728500 @ 0x00728500 ====

void FUN_00728500(undefined1 param_1,void *param_2)

{
  undefined4 *puVar1;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990fb0;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x3c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ee120;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[0xe] = 0xf;
    puVar1[0xd] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
  }
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_00401660(&uStack00000020,0,0xffffffff);
  FUN_00797a20(puVar1);
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (in_stack_00000038 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_007285c0 @ 0x007285c0 ====

void FUN_007285c0(undefined1 param_1,void *param_2)

{
  undefined4 *puVar1;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990fc2;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ee134;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
  }
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_00797a20(puVar1);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00728650 @ 0x00728650 ====

undefined4 FUN_00728650(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  void *unaff_ESI;
  char *pcVar4;
  uint unaff_retaddr;
  uint in_stack_0000001c;
  void *pvStack_28;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990fd4;
  pvStack_c = ExceptionList;
  local_4 = 0;
  pcVar4 = param_2;
  if (in_stack_0000001c < 0x10) {
    pcVar4 = (char *)&param_2;
  }
  pcVar2 = pcVar4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740(pcVar4,(int)pcVar2 - (int)(pcVar4 + 1));
  uVar3 = (**(code **)(*DAT_00b5ae40 + 0xc))();
  if (unaff_retaddr < 0x10) {
    ExceptionList = pvStack_28;
    return uVar3;
  }
  _free(unaff_ESI);
  return extraout_EAX;
}


// ==== FUN_007286f0 @ 0x007286f0 ====

void FUN_007286f0(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined4 ****ppppuVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  uint uVar10;
  uint in_stack_0000001c;
  char acStack_41 [29];
  undefined4 ****appppuStack_24 [4];
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990fee;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x74))();
    uStack_10 = 0xf;
    uStack_14 = 0;
    appppuStack_24[0] = (undefined4 ****)((uint)appppuStack_24[0] & 0xffffff00);
    pcVar9 = (char *)(iVar3 + 0x5c);
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iVar3 + 0x5c),(int)pcVar9 - (iVar3 + 0x5d));
    local_4 = CONCAT31(local_4._1_3_,1);
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar5 = operator_new(0x400);
    *(undefined4 *)((int)pvVar5 + 8) = uVar4;
    *(undefined4 *)((int)pvVar5 + 0xc) = 0x14010006;
    *(undefined2 *)((int)pvVar5 + 6) = 0x48;
    iVar3 = FUN_004244d0();
    ppppuVar6 = appppuStack_24[0];
    if (uStack_10 < 0x10) {
      ppppuVar6 = appppuStack_24;
    }
    FUN_0047aa30(acStack_41,&DAT_009edf34,ppppuVar6);
    pcVar9 = (char *)(iVar3 + 0x10);
    uVar10 = 0;
    pcVar7 = pcVar9;
    do {
      cVar1 = pcVar7[(int)(acStack_41 + -(int)pcVar9)];
      *pcVar7 = cVar1;
      if (cVar1 == '\0') goto LAB_007287dd;
      uVar10 = uVar10 + 1;
      pcVar7 = pcVar7 + 1;
    } while (uVar10 < 0x19);
    *pcVar9 = '\0';
LAB_007287dd:
    puVar8 = param_2;
    if (in_stack_0000001c < 0x10) {
      puVar8 = &param_2;
    }
    FUN_0047aa30(acStack_41,&DAT_009edf34,puVar8);
    pcVar9 = (char *)(iVar3 + 0x2c);
    uVar10 = 0;
    pcVar7 = pcVar9;
    do {
      cVar1 = pcVar7[(int)(acStack_41 + -(int)pcVar9)];
      *pcVar7 = cVar1;
      if (cVar1 == '\0') goto LAB_00728826;
      uVar10 = uVar10 + 1;
      pcVar7 = pcVar7 + 1;
    } while (uVar10 < 0x19);
    *pcVar9 = '\0';
LAB_00728826:
    FUN_004d8570(iVar3);
    if (0xf < uStack_10) {
      _free(appppuStack_24[0]);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    appppuStack_24[0] = (undefined4 ****)((uint)appppuStack_24[0] & 0xffffff00);
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00728890 @ 0x00728890 ====

undefined4 FUN_00728890(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  uint local_64;
  void *local_28 [7];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991030;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00403620();
  if (iVar2 == 0) {
    if ((*(int *)(param_1 + 0x28) == 0) ||
       ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 0)) {
      (**(code **)(*in_ECX + 0x18))();
      ExceptionList = local_c;
      return 1;
    }
    ExceptionList = local_c;
    return 1;
  }
  iVar2 = FUN_00403620();
  if (iVar2 == 0) {
    if ((*(int *)(param_1 + 0x28) != 0) &&
       ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1)) {
      FUN_00459160();
      local_4 = 0;
      FUN_00401660();
      (**(code **)(*in_ECX + 0x98))();
      if (local_64 < 0x10) {
        ExceptionList = local_28[0];
        return 1;
      }
      _free((void *)0xf);
      return extraout_EAX;
    }
  }
  else {
    iVar2 = FUN_00403620();
    if (iVar2 == 0) {
      if ((*(int *)(param_1 + 0x28) != 0) &&
         ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1)) {
        FUN_00459160();
        local_4 = 1;
        FUN_00765c50();
        (**(code **)(*in_ECX + 0xa0))();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      cVar1 = FUN_004036a0();
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0();
        if (cVar1 == '\0') {
          ExceptionList = local_c;
          return 0;
        }
        iVar2 = FUN_004f45a0();
        if (iVar2 == 2) {
          FUN_00459160();
          local_4 = 4;
          FUN_00459160();
          local_4._0_1_ = 5;
          FUN_00765c50();
          local_4._0_1_ = 6;
          FUN_00765c50(local_28);
          local_4 = CONCAT31(local_4._1_3_,5);
          (**(code **)(*in_ECX + 0x94))();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else {
        iVar2 = FUN_004f45a0();
        if (iVar2 == 2) {
          FUN_00459160();
          local_4 = 2;
          FUN_00459160();
          local_4._0_1_ = 3;
          thunk_FUN_00796f50();
          local_4 = CONCAT31(local_4._1_3_,2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00728c00 @ 0x00728c00 ====

void FUN_00728c00(undefined1 param_1,void *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  void *unaff_EBP;
  uint unaff_retaddr;
  uint in_stack_0000001c;
  undefined1 auStack_1d8 [4];
  uint uStack_1d4;
  undefined4 *puStack_1d0;
  undefined4 uStack_1cc;
  undefined1 *puStack_1c8;
  int *piStack_1c4;
  uint uStack_1c0;
  uint uStack_1b8;
  undefined1 *puStack_1b4;
  undefined4 *puStack_1b0;
  undefined1 *puStack_1ac;
  undefined1 *puStack_1a8;
  undefined *puStack_1a4;
  undefined4 local_184;
  uint uStack_164;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  uint uStack_12c;
  undefined1 auStack_127 [255];
  void *pvStack_28;
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [4];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099108c;
  pvStack_c = ExceptionList;
  puStack_1a4 = (undefined *)0x0;
  puStack_1a8 = &param_1;
  local_184 = (undefined1 *)0xf;
  local_4 = 1;
  puStack_1ac = (undefined1 *)0x728c57;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  piVar1 = (int *)(**(code **)(*DAT_00b5ae40 + 0xc))();
  if (piVar1 == (int *)0x0) {
LAB_00728d54:
    if (0xf < unaff_retaddr) {
      puStack_1a4 = (undefined *)0x728d6f;
      _free(pvStack_14);
      return;
    }
  }
  else {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x14))();
    local_184 = (undefined1 *)*puVar2;
    if ((char)((ushort)*(undefined2 *)(puVar2 + 1) >> 8) == '\0') {
      puStack_1a4 = (undefined *)0x0;
      puStack_1a8 = (undefined1 *)0x728ca0;
      puStack_1a8 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_1ac = auStack_20;
      puStack_1b0 = &local_184;
      puStack_1b4 = (undefined1 *)0x728cb3;
      FUN_00405bd0();
      puStack_1a8 = (undefined1 *)0x1;
      puStack_1c8 = (undefined1 *)0xffffffff;
      uStack_1cc = 0;
      puStack_1d0 = &local_184;
      puStack_1ac = (undefined1 *)0xf;
      puStack_1b0 = (undefined4 *)0x0;
      pvStack_28._0_1_ = 2;
      uStack_1c0 = uStack_1c0 & 0xffffff00;
      uStack_1d4 = 0x728cdf;
      FUN_00401660();
      puStack_1c8 = (undefined1 *)0xf;
      uStack_1cc = 0;
      pvStack_28._0_1_ = 3;
      FUN_00401660(auStack_20,0,0xffffffff);
      pvStack_28 = (void *)CONCAT31(pvStack_28._1_3_,2);
      (**(code **)(*DAT_00b5ae40 + 0x14))();
      if (0xf < uStack_164) {
        puStack_1a4 = (undefined *)0x728d31;
        _free(unaff_EBP);
        return;
      }
    }
    else {
      piVar1 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      if (piVar1 == (int *)0x0) goto LAB_00728d54;
      (**(code **)(*piVar1 + 0x74))();
      puStack_1a4 = (undefined *)0x728db5;
      FUN_00401830();
      auStack_20[0] = 4;
      (**(code **)(*DAT_00b5a6ac + 0x20))();
      puStack_1a4 = (undefined *)0x728dce;
      FUN_00729000();
      puStack_1a8 = auStack_160 + -0x1c;
      puStack_1a4 = &DAT_009edf34;
      puStack_1ac = (undefined1 *)0x728dff;
      FUN_0047aa30();
      puStack_1a4 = (undefined *)0x728e0f;
      FUN_0047aa00();
      puStack_1a8 = auStack_127;
      puStack_1a4 = &DAT_009edf38;
      puStack_1ac = (undefined1 *)0x728e36;
      FUN_00729120();
      puStack_1a4 = (undefined *)0x728e46;
      FUN_007290f0();
      puStack_1a4 = (undefined *)0x728e52;
      FUN_004d8570();
      puStack_1a4 = auStack_160;
      puStack_1a8 = auStack_144;
      puStack_1ac = (undefined1 *)0x728e66;
      puStack_1b0 = (undefined4 *)FUN_00402220();
      puStack_1ac = &param_1;
      puStack_1b4 = auStack_160 + -0x1c;
      auStack_20[0] = 5;
      uStack_1b8 = 0x728e81;
      puStack_1a8 = (undefined1 *)FUN_00405bd0();
      puStack_1a4 = (undefined *)0x0;
      auStack_20[0] = 6;
      puStack_1ac = (undefined1 *)0x728e9c;
      FUN_00401660();
      if (0xf < uStack_164) {
        puStack_1a4 = (undefined *)0x728eac;
        _free(unaff_EBP);
        return;
      }
      auStack_20[0] = 4;
      if (0xf < uStack_12c) {
        puStack_1a4 = (undefined *)0x728ed3;
        _free(pvStack_140);
        return;
      }
      uStack_1c0 = 0xffffffff;
      piStack_1c4 = (int *)0x0;
      puStack_1c8 = &param_1;
      puStack_1a4 = (undefined *)0xf;
      puStack_1a8 = (undefined1 *)0x0;
      uStack_1b8 = uStack_1b8 & 0xffffff00;
      uStack_1cc = 0x728efa;
      FUN_00401660();
      local_184 = auStack_1d8;
      uStack_1c0 = 0xf;
      piStack_1c4 = (int *)0x0;
      auStack_20[0] = 7;
      uStack_1d4 = uStack_1d4 & 0xffffff00;
      FUN_00401660(auStack_18);
      auStack_20[0] = 4;
      (**(code **)(*DAT_00b5ae40 + 0x14))();
      (**(code **)(*piStack_1c4 + 0x34))();
      if (0xf < uStack_148) {
        puStack_1a4 = (undefined *)0x728f50;
        _free(pvStack_15c);
        return;
      }
      uStack_148 = 0xf;
      uStack_14c = 0;
      pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
    }
    if (0xf < unaff_retaddr) {
      puStack_1a4 = (undefined *)0x728f75;
      _free(pvStack_14);
      return;
    }
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_28;
    return;
  }
  local_4 = 0;
  pvStack_14 = (void *)((uint)pvStack_14 & 0xffffff00);
  puStack_1a4 = (undefined *)0x728fa3;
  _free(param_2);
  return;
}


// ==== FUN_00728fd0 @ 0x00728fd0 ====

undefined4 FUN_00728fd0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00728890(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00729000 @ 0x00729000 ====

void FUN_00729000(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x14010001;
  *(undefined2 *)((int)pvVar1 + 6) = 0x144;
  FUN_004244d0();
  return;
}


// ==== FUN_00729030 @ 0x00729030 ====

undefined4 FUN_00729030(void)

{
  return 0x70340000;
}


// ==== FUN_00729040 @ 0x00729040 ====

undefined4 FUN_00729040(void)

{
  return 0x70340001;
}


// ==== FUN_00729050 @ 0x00729050 ====

undefined4 FUN_00729050(void)

{
  return 0x70340002;
}


// ==== FUN_00729060 @ 0x00729060 ====

undefined4 FUN_00729060(void)

{
  return 0x70340020;
}


// ==== FUN_00729070 @ 0x00729070 ====

undefined4 FUN_00729070(void)

{
  return 0x70340021;
}


// ==== FUN_00729080 @ 0x00729080 ====

undefined4 FUN_00729080(void)

{
  return 0x70340030;
}


// ==== FUN_00729090 @ 0x00729090 ====

undefined4 FUN_00729090(void)

{
  return 0x70340031;
}


// ==== FUN_007290a0 @ 0x007290a0 ====

undefined4 FUN_007290a0(void)

{
  return 0x70340005;
}


// ==== FUN_007290b0 @ 0x007290b0 ====

undefined4 FUN_007290b0(void)

{
  return 0x70340006;
}


// ==== FUN_007290c0 @ 0x007290c0 ====

undefined4 FUN_007290c0(void)

{
  return 0x70340007;
}


// ==== FUN_007290d0 @ 0x007290d0 ====

undefined4 FUN_007290d0(void)

{
  return 0x70340008;
}


// ==== FUN_007290e0 @ 0x007290e0 ====

undefined4 FUN_007290e0(void)

{
  return 0x70340009;
}


// ==== FUN_007290f0 @ 0x007290f0 ====

void FUN_007290f0(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0xff);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00729120 @ 0x00729120 ====

char * FUN_00729120(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0xff,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0xff)) {
    param_1[0xfe] = '\0';
  }
  return param_1;
}


// ==== FUN_00729160 @ 0x00729160 ====

undefined4 FUN_00729160(void)

{
  return 0x70340004;
}


// ==== FUN_00729170 @ 0x00729170 ====

void FUN_00729170(byte param_1)

{
  void *in_ECX;
  
  FUN_00729190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00729190 @ 0x00729190 ====

void FUN_00729190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee0f8;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_007291d0 @ 0x007291d0 ====

undefined4 FUN_007291d0(void)

{
  return 0x70340010;
}


// ==== FUN_007291e0 @ 0x007291e0 ====

void FUN_007291e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00729200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00729200 @ 0x00729200 ====

void FUN_00729200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee10c;
  if (0xf < (uint)in_ECX[0x15]) {
    _free((void *)in_ECX[0x10]);
    return;
  }
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00729280 @ 0x00729280 ====

undefined4 FUN_00729280(void)

{
  return 0x70340011;
}


// ==== FUN_00729290 @ 0x00729290 ====

void FUN_00729290(byte param_1)

{
  void *in_ECX;
  
  FUN_007292b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007292b0 @ 0x007292b0 ====

void FUN_007292b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee120;
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00729310 @ 0x00729310 ====

undefined4 FUN_00729310(void)

{
  return 0x70340012;
}


// ==== FUN_00729320 @ 0x00729320 ====

void FUN_00729320(byte param_1)

{
  void *in_ECX;
  
  FUN_00729340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00729340 @ 0x00729340 ====

void FUN_00729340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee134;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00729380 @ 0x00729380 ====

void FUN_00729380(byte param_1)

{
  void *in_ECX;
  
  FUN_007280c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007293a0 @ 0x007293a0 ====

void FUN_007293a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee2a8;
  return;
}


// ==== FUN_007293b0 @ 0x007293b0 ====

void FUN_007293b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee2a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007293d0 @ 0x007293d0 ====

void FUN_007293d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x65) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x65) == '\0');
  }
  return;
}


// ==== FUN_007293f0 @ 0x007293f0 ====

void FUN_007293f0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x65);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x65);
  }
  return;
}


// ==== FUN_00729410 @ 0x00729410 ====

void FUN_00729410(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x65) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)(in_ECX + 4) + 4)) {
    *(int *)(*(int *)(in_ECX + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}


// ==== FUN_00729470 @ 0x00729470 ====

void FUN_00729470(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x65) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x65) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x65);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x65);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x65);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x65);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_007294c0 @ 0x007294c0 ====

void FUN_007294c0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x65) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x65) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x65);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x65);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x65) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x65) == '\0');
    if (*(char *)((int)piVar4 + 0x65) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00729530 @ 0x00729530 ====

undefined4 FUN_00729530(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00729560 @ 0x00729560 ====

void FUN_00729560(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x6c) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x00729577. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x14))();
  return;
}


// ==== FUN_00729580 @ 0x00729580 ====

void FUN_00729580(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x6c) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x00729597. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x18))();
  return;
}


// ==== FUN_007295a0 @ 0x007295a0 ====

void FUN_007295a0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x6c) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x007295b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x1c))();
  return;
}


// ==== FUN_007295c0 @ 0x007295c0 ====

undefined4 * FUN_007295c0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 8);
  iVar5 = 0;
  while( true ) {
    if (puVar2 == *(undefined4 **)(in_ECX + 8)) {
      return (undefined4 *)0x0;
    }
    if (iVar5 == param_1) break;
    iVar5 = iVar5 + 1;
    if (*(char *)((int)puVar2 + 0x65) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x65) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x65);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x65);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x65);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x65);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return puVar2 + 10;
}


// ==== FUN_00729630 @ 0x00729630 ====

int FUN_00729630(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 8);
  iVar5 = 0;
  while (puVar2 != *(undefined4 **)(in_ECX + 8)) {
    if (*(char *)(puVar2 + 10) == '\0') {
      iVar5 = iVar5 + 1;
    }
    if (*(char *)((int)puVar2 + 0x65) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x65) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x65);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x65);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x65);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x65);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return iVar5;
}


// ==== FUN_00729690 @ 0x00729690 ====

undefined4 FUN_00729690(void *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 auStack_25 [21];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009910a8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x6c) + 0x14))();
  puVar3 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar3 = &param_2;
  }
  FUN_0047aa30(auStack_25,&DAT_009ee28c,puVar3);
  uVar4 = (**(code **)(*piVar2 + 0xc))(auStack_25);
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return uVar4;
  }
  _free(param_1);
  return extraout_EAX;
}


// ==== FUN_00729720 @ 0x00729720 ====

int FUN_00729720(undefined1 param_1,void *param_2)

{
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  uint in_stack_0000001c;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009910ba;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  local_10 = in_ECX;
  FUN_0072a500(&local_10,&param_1);
  if (local_10 != *(int *)(in_ECX + 8)) {
    if (in_stack_0000001c < 0x10) {
      ExceptionList = local_c;
      return local_10 + 0x28;
    }
    _free(param_2);
    return extraout_EAX_00;
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_007297b0 @ 0x007297b0 ====

undefined4 FUN_007297b0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  FILE *_File;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009910cc;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004020e0(&DAT_009ee238,4);
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  _File = (FILE *)FUN_00803b27(puVar1,&DAT_009ee240);
  if (_File == (FILE *)0x0) {
    if (in_stack_0000001c < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    _free(param_2);
    return extraout_EAX_00;
  }
  _fclose(_File);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return 1;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_00729860 @ 0x00729860 ====

/* WARNING: Removing unreachable block (ram,0x00729b1e) */

int FUN_00729860(int param_1,undefined4 param_2,void *param_3)

{
  char cVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int iVar2;
  uint in_stack_00000020;
  void *local_b8;
  uint local_a4;
  void *local_98;
  uint local_84;
  _SYSTEMTIME local_80;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  void *local_34;
  undefined4 local_24;
  uint local_20;
  _SYSTEMTIME local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099111f;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00404890();
  local_4._0_1_ = 1;
  FUN_004045b0();
  local_4._0_1_ = 3;
  if (0xf < local_a4) {
    _free(local_b8);
    return extraout_EAX;
  }
  FUN_004046f0();
  local_4._0_1_ = 4;
  FUN_00402220();
  local_4._0_1_ = 6;
  if (0xf < local_20) {
    _free(local_34);
    return extraout_EAX_00;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  GetSystemTime(&local_1c);
  GetLocalTime(&local_80);
  FUN_00401740(s__s__02d_02d_02d__02d_02d_009ee25c,0x18);
  FUN_00404230(local_70);
  local_4._0_1_ = 7;
  FUN_00401ff0();
  local_4._0_1_ = 6;
  if (0xf < local_58) {
    _free(local_6c);
    return extraout_EAX_01;
  }
  FUN_00401660();
  cVar1 = FUN_007297b0();
  if (cVar1 == '\x01') {
    local_4._0_1_ = 8;
    iVar2 = 1;
    do {
      FUN_00401660();
      FUN_00401740();
      FUN_00404230();
      local_4._0_1_ = 9;
      FUN_00401ff0();
      local_4._0_1_ = 8;
      if (0xf < local_58) {
        _free(local_6c);
        return extraout_EAX_02;
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      FUN_00401660();
      cVar1 = FUN_007297b0();
      if (cVar1 == '\0') {
        FUN_00401660();
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 100);
    local_4._0_1_ = 6;
  }
  FUN_004020e0();
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660();
  if (0xf < local_84) {
    _free(local_98);
    return extraout_EAX_03;
  }
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_04;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX_05;
}


// ==== FUN_00729be0 @ 0x00729be0 ====

/* WARNING: Removing unreachable block (ram,0x00729e20) */

void FUN_00729be0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *in_ECX;
  int unaff_EBP;
  uint unaff_ESI;
  uint unaff_EDI;
  uint unaff_retaddr;
  char acStack_dc [28];
  uint uStack_9c;
  void *pvStack_94;
  uint uStack_80;
  void *pvStack_40;
  uint local_2c;
  void *pvStack_28;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099116f;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  FUN_00729860();
  local_2c = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_00401660();
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar2 == 0) {
    FUN_004137c0();
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return;
    }
  }
  else {
    FUN_0072a600();
    while (unaff_EBP != 0) {
      FUN_00401660();
      FUN_00401740();
      FUN_00404230();
      FUN_00411630();
      if (0xf < local_2c) {
        _free(pvStack_40);
        return;
      }
      local_2c = 0xf;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      if (unaff_EBP == 0) {
        unaff_EBP = 0;
      }
      else {
        iVar2 = *(int *)(unaff_ESI * 4 + 0xf);
        if (0xf < *(uint *)(iVar2 + 0x18)) {
          _free(*(void **)(iVar2 + 4));
          return;
        }
        *(undefined4 *)(iVar2 + 0x18) = 0xf;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined1 *)(iVar2 + 4) = 0;
        unaff_ESI = unaff_ESI + 1;
        if (unaff_EDI <= unaff_ESI) {
          unaff_ESI = 0;
        }
        unaff_EBP = unaff_EBP + -1;
        if (unaff_EBP == 0) {
          unaff_ESI = 0;
        }
      }
    }
    (**(code **)(*DAT_00b5a740 + 0xc))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pcVar3 = acStack_dc + 0x1c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_dc + 0x1c,(int)pcVar3 - (int)(acStack_dc + 0x1d));
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_9c) {
      _free((void *)0x0);
      return;
    }
    FUN_006dbc50();
    FUN_004137c0();
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return;
    }
  }
  if (unaff_retaddr < 0x10) {
    ExceptionList = pvStack_28;
    return;
  }
  _free(pvStack_14);
  return;
}


// ==== FUN_00729f60 @ 0x00729f60 ====

/* WARNING: Removing unreachable block (ram,0x00729fba) */

void FUN_00729f60(undefined4 param_1,byte *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void **ppvVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991181;
  local_c = ExceptionList;
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 8);
  local_4 = 0;
  do {
    ppvVar6 = &local_c;
    if (puVar2 == *(undefined4 **)(in_ECX + 8)) {
joined_r0x0072a081:
      ExceptionList = ppvVar6;
      if (in_stack_0000001c < 0x10) {
        ExceptionList = local_c;
        return;
      }
      _free(param_2);
      return;
    }
    pbVar10 = param_2;
    if (in_stack_0000001c < 0x10) {
      pbVar10 = (byte *)&param_2;
    }
    uVar3 = puVar2[0x12];
    if (uVar3 == 0) {
LAB_00729fe5:
      if ((in_stack_00000018 <= uVar3) && (uVar3 == in_stack_00000018)) {
        ExceptionList = &local_c;
        FUN_0072a7f0(local_10,puVar2);
        ppvVar6 = ExceptionList;
        goto joined_r0x0072a081;
      }
    }
    else {
      uVar8 = uVar3;
      if (in_stack_00000018 <= uVar3) {
        uVar8 = in_stack_00000018;
      }
      if ((uint)puVar2[0x13] < 0x10) {
        pbVar9 = (byte *)(puVar2 + 0xe);
      }
      else {
        pbVar9 = (byte *)puVar2[0xe];
      }
      bVar11 = false;
      iVar7 = 0;
      bVar12 = true;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar11 = *pbVar9 < *pbVar10;
        bVar12 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (iVar7 == 0) goto LAB_00729fe5;
    }
    if (*(char *)((int)puVar2 + 0x65) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x65) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x65);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x65);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x65);
        puVar5 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x65);
          puVar5 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  } while( true );
}


// ==== FUN_0072a090 @ 0x0072a090 ====

void FUN_0072a090(undefined1 param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined1 in_stack_0000003c;
  int local_a8 [2];
  undefined1 local_a0;
  undefined1 local_9f;
  undefined4 local_9c;
  undefined4 local_98;
  void *local_90;
  undefined4 local_80;
  uint local_7c;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009911ae;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_0072a500(local_a8,&param_1);
  if (local_a8[0] == *(int *)(in_ECX + 8)) {
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    local_a0 = in_stack_0000003c;
    local_98 = 0;
    local_4._0_1_ = 2;
    local_9f = 1;
    local_9c = 0;
    FUN_00401660(&param_1,0,0xffffffff);
    FUN_006dc180(&uStack00000020);
    uVar1 = FUN_0072a780(&param_1,&local_a0);
    local_4._0_1_ = 3;
    FUN_0072ae70(local_a8,uVar1);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_0072a5a0();
    (**(code **)(*DAT_00b5ae3c + 0x38))();
    FUN_004dd240(0x16,0xb,0,0,0);
    FUN_006dbc50();
    if (0xf < local_7c) {
      _free(local_90);
      return;
    }
  }
  else {
    FUN_006dc180(&uStack00000020);
    *(undefined1 *)(local_a8[0] + 0x29) = 1;
    if (0x32 < *(uint *)(local_a8[0] + 0x60)) {
      FUN_006dbc00();
    }
    if (*(char *)(local_a8[0] + 0x28) == '\x01') {
      (**(code **)(*DAT_00b5ae3c + 0x34))();
    }
  }
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  in_stack_00000018 = 0;
  param_2 = (void *)((uint)param_2 & 0xffffff00);
  in_stack_0000001c = 0xf;
  if (in_stack_00000038 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_0072a270 @ 0x0072a270 ====

void FUN_0072a270(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009911cb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ee2dc;
  local_4 = 1;
  FUN_0072aaf0(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  DAT_00b5ae40 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_0072adb0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0072a310 @ 0x0072a310 ====

void FUN_0072a310(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009911e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ee2dc;
  iVar1 = FUN_0072a400();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x65) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae40 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae40 = in_ECX;
  }
  FUN_0072aaf0(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072a3b0 @ 0x0072a3b0 ====

void FUN_0072a3b0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x65) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_0072a400 @ 0x0072a400 ====

void FUN_0072a400(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x68);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x19) = 1;
  *(undefined1 *)((int)puVar1 + 0x65) = 0;
  return;
}


// ==== FUN_0072a440 @ 0x0072a440 ====

/* WARNING: Removing unreachable block (ram,0x0072a498) */

undefined4 * FUN_0072a440(int param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)local_8[1] + 0x65) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x14);
    puVar5 = (undefined4 *)local_8[1];
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar8 = (byte *)(param_1 + 4);
      }
      else {
        pbVar8 = *(byte **)(param_1 + 4);
      }
      uVar2 = puVar5[8];
      if (uVar2 == 0) {
LAB_0072a4c3:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_0072a4d0;
        }
LAB_0072a4d2:
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
        uVar3 = uVar2;
        if (uVar1 <= uVar2) {
          uVar3 = uVar1;
        }
        if ((uint)puVar5[9] < 0x10) {
          pbVar7 = (byte *)(puVar5 + 4);
        }
        else {
          pbVar7 = (byte *)puVar5[4];
        }
        bVar9 = false;
        iVar4 = 0;
        bVar10 = true;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          bVar9 = *pbVar7 < *pbVar8;
          bVar10 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (!bVar10) {
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        bVar9 = iVar4 < 0;
        if (iVar4 == 0) goto LAB_0072a4c3;
LAB_0072a4d0:
        if (bVar9) goto LAB_0072a4d2;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x65) == '\0');
  }
  return local_8;
}


// ==== FUN_0072a500 @ 0x0072a500 ====

void FUN_0072a500(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0072a440(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar1 + 0x24) < 0x10) {
      iVar2 = iVar1 + 0x10;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),iVar2,*(undefined4 *)(iVar1 + 0x20));
    if (-1 < iVar2) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0072a570 @ 0x0072a570 ====

void FUN_0072a570(void)

{
  int in_ECX;
  
  FUN_006dbc50();
  if (*(uint *)(in_ECX + 0x24) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0xf;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_0072a5a0 @ 0x0072a5a0 ====

void FUN_0072a5a0(void)

{
  int in_ECX;
  
  FUN_006dbc50();
  if (0xf < *(uint *)(in_ECX + 0x40)) {
    _free(*(void **)(in_ECX + 0x2c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0xf;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0072a5f0 @ 0x0072a5f0 ====

void FUN_0072a5f0(void)

{
  FUN_0072a5a0();
  return;
}


// ==== FUN_0072a600 @ 0x0072a600 ====

void FUN_0072a600(int param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00991200;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  local_8 = 0;
  FUN_006dc200(in_ECX,0,param_1,*(int *)(param_1 + 0xc),param_1,
               *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc),param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@0072a668 @ 0x0072a668 ====

void Catch_0072a668(void)

{
  FUN_006dbc50();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0072a680 @ 0x0072a680 ====

void FUN_0072a680(undefined1 *param_1)

{
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099121b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = 0;
  FUN_00401660(param_1 + 0xc,0,0xffffffff);
  local_4 = 0;
  FUN_0072a600(param_1 + 0x28);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072a710 @ 0x0072a710 ====

void FUN_0072a710(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0072a680(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072a780 @ 0x0072a780 ====

void FUN_0072a780(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0072a680(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072a7f0 @ 0x0072a7f0 ====

/* WARNING: Removing unreachable block (ram,0x0072a8fd) */
/* WARNING: Removing unreachable block (ram,0x0072a90d) */
/* WARNING: Removing unreachable block (ram,0x0072a916) */
/* WARNING: Removing unreachable block (ram,0x0072a919) */
/* WARNING: Removing unreachable block (ram,0x0072a909) */
/* WARNING: Removing unreachable block (ram,0x0072a927) */
/* WARNING: Removing unreachable block (ram,0x0072a934) */
/* WARNING: Removing unreachable block (ram,0x0072a93f) */
/* WARNING: Removing unreachable block (ram,0x0072a93b) */
/* WARNING: Removing unreachable block (ram,0x0072a92f) */
/* WARNING: Removing unreachable block (ram,0x0072a942) */

void FUN_0072a7f0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991278;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x65) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &pvStack_c;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c7c8);
  }
  ExceptionList = &pvStack_c;
  FUN_00729470();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x65) == '\0') {
    if (*(char *)(param_2[2] + 0x65) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x65) == '\0') {
    piVar5[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar5;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar5;
  }
  else {
    piVar6[2] = (int)piVar5;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar5 + 0x65) == '\0') {
      piVar3 = (int *)FUN_007293f0(piVar5);
    }
    else {
      piVar3 = piVar6;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x65) == '\0') {
      uVar4 = FUN_007293d0(piVar5);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar6;
    }
  }
  if ((char)param_2[0x19] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        if ((char)piVar5[0x19] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x19] == '\0') {
            *(undefined1 *)(piVar3 + 0x19) = 1;
            *(undefined1 *)(piVar6 + 0x19) = 0;
            FUN_0072a3b0(piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x65) == '\0') {
            if ((*(char *)(*piVar3 + 100) == '\x01') && (*(char *)(piVar3[2] + 100) == '\x01'))
            goto LAB_0072aa14;
            if (*(char *)(piVar3[2] + 100) == '\x01') {
              *(undefined1 *)(*piVar3 + 100) = 1;
              *(undefined1 *)(piVar3 + 0x19) = 0;
              FUN_00729410(piVar3);
              piVar3 = (int *)piVar6[2];
            }
            *(char *)(piVar3 + 0x19) = (char)piVar6[0x19];
            *(undefined1 *)(piVar6 + 0x19) = 1;
            *(undefined1 *)(piVar3[2] + 100) = 1;
            FUN_0072a3b0(piVar6);
            break;
          }
        }
        else {
          if ((char)piVar3[0x19] == '\0') {
            *(undefined1 *)(piVar3 + 0x19) = 1;
            *(undefined1 *)(piVar6 + 0x19) = 0;
            FUN_00729410(piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x65) == '\0') {
            if ((*(char *)(piVar3[2] + 100) != '\x01') || (*(char *)(*piVar3 + 100) != '\x01')) {
              if (*(char *)(*piVar3 + 100) == '\x01') {
                *(undefined1 *)(piVar3[2] + 100) = 1;
                *(undefined1 *)(piVar3 + 0x19) = 0;
                FUN_0072a3b0(piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 0x19) = (char)piVar6[0x19];
              *(undefined1 *)(piVar6 + 0x19) = 1;
              *(undefined1 *)(*piVar3 + 100) = 1;
              FUN_00729410(piVar6);
              break;
            }
LAB_0072aa14:
            *(undefined1 *)(piVar3 + 0x19) = 0;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x19) = 1;
  }
  FUN_006dbc50();
  if (0xf < (uint)param_2[0x13]) {
    _free((void *)param_2[0xe]);
    return;
  }
  param_2[0x13] = 0xf;
  param_2[0x12] = 0;
  *(undefined1 *)(param_2 + 0xe) = 0;
  if ((uint)param_2[9] < 0x10) {
    param_2[9] = 0xf;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 4) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_0072aaf0 @ 0x0072aaf0 ====

void FUN_0072aaf0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x65) == '\0') {
    FUN_0072aaf0(*(undefined4 *)((int)param_1 + 8));
    FUN_0072a5f0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0072ab30 @ 0x0072ab30 ====

undefined4 *
FUN_0072ab30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00991261;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x68);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_0072a710(param_4);
    *(undefined1 *)(puVar1 + 0x19) = param_5;
    *(undefined1 *)((int)puVar1 + 0x65) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0072abae @ 0x0072abae ====

void Catch_0072abae(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0072abd0 @ 0x0072abd0 ====

void FUN_0072abd0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991278;
  local_c = ExceptionList;
  if (0x2e8ba2c < *(uint *)(in_ECX + 8)) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  ExceptionList = &local_c;
  piVar4 = (int *)FUN_0072ab30(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
                               param_4,0);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = piVar4;
    **(undefined4 **)(in_ECX + 4) = piVar4;
    *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar4;
    if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
      *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
    }
  }
  else {
    *param_3 = piVar4;
    if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      **(int **)(in_ECX + 4) = (int)piVar4;
    }
  }
  cVar1 = *(char *)(piVar4[1] + 100);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 100) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x19] == '\0') {
LAB_0072acc9:
        *(undefined1 *)(*piVar5 + 100) = 1;
        *(undefined1 *)(piVar6 + 0x19) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 100) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0072a3b0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 100) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 100) = 0;
        FUN_00729410(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x19] == '\0') goto LAB_0072acc9;
      if (piVar7 == (int *)*piVar2) {
        FUN_00729410(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 100) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 100) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x65) == '\0') {
        *(int *)(*piVar2 + 4) = iVar3;
      }
      piVar2[1] = *(int *)(iVar3 + 4);
      if (iVar3 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar6 = *(int **)(iVar3 + 4);
        if (iVar3 == *piVar6) {
          *piVar6 = (int)piVar2;
        }
        else {
          piVar6[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar7[1] + 100);
  } while( true );
}


// ==== FUN_0072adb0 @ 0x0072adb0 ====

void FUN_0072adb0(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_0072aaf0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x65) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x65) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x65);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x65);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x65);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x65);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0072a7f0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0072ae70 @ 0x0072ae70 ====

/* WARNING: Removing unreachable block (ram,0x0072aecf) */

void FUN_0072ae70(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  
  iVar3 = (int)param_2;
  puVar6 = *(undefined4 **)(in_ECX + 4);
  bVar11 = true;
  if (*(char *)((int)puVar6[1] + 0x65) == '\0') {
    uVar1 = *(uint *)((int)param_2 + 0x14);
    puVar9 = (undefined4 *)puVar6[1];
    do {
      puVar6 = puVar9;
      uVar2 = puVar6[8];
      if ((uint)puVar6[9] < 0x10) {
        pbVar4 = (byte *)(puVar6 + 4);
      }
      else {
        pbVar4 = (byte *)puVar6[4];
      }
      if (uVar1 == 0) {
LAB_0072af00:
        if (uVar1 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar1 != uVar2);
        }
      }
      else {
        uVar8 = uVar1;
        if (uVar2 <= uVar1) {
          uVar8 = uVar2;
        }
        if (*(uint *)((int)param_2 + 0x18) < 0x10) {
          pbVar10 = (byte *)((int)param_2 + 4);
        }
        else {
          pbVar10 = *(byte **)((int)param_2 + 4);
        }
        bVar11 = false;
        uVar5 = 0;
        bVar12 = true;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar11 = *pbVar10 < *pbVar4;
          bVar12 = *pbVar10 == *pbVar4;
          pbVar10 = pbVar10 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar12);
        if (!bVar12) {
          uVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (uVar5 == 0) goto LAB_0072af00;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x65) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_0072abd0(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_007294c0();
  }
  puVar9 = param_2;
  if (*(uint *)(iVar3 + 0x18) < 0x10) {
    iVar7 = iVar3 + 4;
  }
  else {
    iVar7 = *(int *)(iVar3 + 4);
  }
  iVar7 = FUN_00403620(0,param_2[8],iVar7,*(undefined4 *)(iVar3 + 0x14));
  if (iVar7 < 0) {
    puVar6 = (undefined4 *)FUN_0072abd0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0072afe0 @ 0x0072afe0 ====

void FUN_0072afe0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0072adb0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0072b010 @ 0x0072b010 ====

void FUN_0072b010(byte param_1)

{
  void *in_ECX;
  
  FUN_0072a270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072b030 @ 0x0072b030 ====

void FUN_0072b030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee378;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072b050 @ 0x0072b050 ====

void FUN_0072b050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee388;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acf8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5acf8 = in_ECX;
  return;
}


// ==== FUN_0072b080 @ 0x0072b080 ====

int FUN_0072b080(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5ad00 + 4))(param_1);
  if (iVar1 == 0) {
    return -1;
  }
  if (*(short *)(iVar1 + 0x14) == 0) {
    return (-(uint)(*(char *)(iVar1 + 0xc) != '\x01') & 0xff00) - 0xff01;
  }
  return -0x10000;
}


// ==== FUN_0072b0c0 @ 0x0072b0c0 ====

void FUN_0072b0c0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acf8 = 0;
  *in_ECX = &PTR_FUN_009ee378;
  return;
}


// ==== FUN_0072b0e0 @ 0x0072b0e0 ====

void FUN_0072b0e0(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00401660(param_1,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  return;
}


// ==== FUN_0072b120 @ 0x0072b120 ====

int FUN_0072b120(int param_1,undefined4 param_2)

{
  int *piVar1;
  int unaff_retaddr;
  
  if (DAT_00b5acd8 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009ee36e,0);
    return param_1;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_2);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009ee36f,0);
    return unaff_retaddr;
  }
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  (**(code **)(*piVar1 + 0x40))(unaff_retaddr);
  return unaff_retaddr;
}


// ==== FUN_0072b1b0 @ 0x0072b1b0 ====

void FUN_0072b1b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_202 [18];
  undefined1 auStack_1f0 [8];
  undefined1 local_1e8 [20];
  undefined1 auStack_1d4 [28];
  undefined1 auStack_1b8 [28];
  undefined1 auStack_19c [28];
  undefined1 auStack_180 [28];
  undefined1 auStack_164 [28];
  undefined1 auStack_148 [28];
  undefined1 auStack_12c [28];
  undefined1 auStack_110 [28];
  undefined1 auStack_f4 [28];
  undefined1 auStack_d8 [28];
  undefined1 auStack_bc [28];
  undefined1 auStack_a0 [28];
  undefined1 auStack_84 [28];
  undefined1 auStack_68 [28];
  undefined1 auStack_4c [28];
  undefined1 auStack_30 [36];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009913b8;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
    ExceptionList = &local_c;
    FUN_0072b120(local_1e8,param_2);
    local_4 = 0;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0001);
    FUN_00765c50(uVar1);
    local_c._0_1_ = 1;
    uVar1 = FUN_004022a0(auStack_164,&DAT_009ee34c,auStack_1f0);
    local_c._0_1_ = 2;
    uVar1 = FUN_00402220(auStack_84,uVar1,&DAT_009ee348);
    local_c._0_1_ = 3;
    uVar1 = FUN_00405bd0(auStack_4c,uVar1,auStack_202 + -10);
    local_c = (void *)CONCAT31(local_c._1_3_,4);
    FUN_00401660(uVar1,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    ExceptionList = &local_c;
    FUN_0072b120(local_1e8,param_2);
    local_4 = 5;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0002);
    FUN_00765c50(uVar1);
    local_c._0_1_ = 6;
    uVar1 = FUN_004022a0(auStack_1b8,&DAT_009ee354,auStack_1f0);
    local_c._0_1_ = 7;
    uVar1 = FUN_00402220(auStack_12c,uVar1,&DAT_009ee350);
    local_c._0_1_ = 8;
    uVar1 = FUN_00405bd0(auStack_bc,uVar1,auStack_202 + -10);
    local_c = (void *)CONCAT31(local_c._1_3_,9);
    FUN_00401660(uVar1,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    ExceptionList = &local_c;
    FUN_0072b120(local_1e8,param_2);
    local_4 = 10;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0003);
    FUN_00765c50(uVar1);
    local_c._0_1_ = 0xb;
    uVar1 = FUN_004022a0(auStack_180,&DAT_009ee35c,auStack_1f0);
    local_c._0_1_ = 0xc;
    uVar1 = FUN_00402220(auStack_19c,uVar1,&DAT_009ee358);
    local_c._0_1_ = 0xd;
    uVar1 = FUN_00405bd0(auStack_f4,uVar1,auStack_202 + -10);
    local_c = (void *)CONCAT31(local_c._1_3_,0xe);
    FUN_00401660(uVar1,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    ExceptionList = &local_c;
    FUN_0072b120(local_1e8,param_2);
    local_4 = 0xf;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0004);
    FUN_00765c50(uVar1);
    local_c._0_1_ = 0x10;
    uVar1 = FUN_004022a0(auStack_d8,&DAT_009ee364,auStack_1f0);
    local_c._0_1_ = 0x11;
    uVar1 = FUN_00402220(auStack_110,uVar1,&DAT_009ee360);
    local_c._0_1_ = 0x12;
    uVar1 = FUN_00405bd0(auStack_148,uVar1,auStack_202 + -10);
    local_c = (void *)CONCAT31(local_c._1_3_,0x13);
    FUN_00401660(uVar1,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    ExceptionList = &local_c;
    FUN_0072b120(local_1e8,param_2);
    local_4 = 0x14;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0005);
    FUN_00765c50(uVar1);
    local_c._0_1_ = 0x15;
    uVar1 = FUN_004022a0(auStack_30,&DAT_009ee36c,auStack_1f0);
    local_c._0_1_ = 0x16;
    uVar1 = FUN_00402220(auStack_68,uVar1,&DAT_009ee368);
    local_c._0_1_ = 0x17;
    uVar1 = FUN_00405bd0(auStack_a0,uVar1,auStack_202 + -10);
    local_c = (void *)CONCAT31(local_c._1_3_,0x18);
    FUN_00401660(uVar1,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 5:
    ExceptionList = &local_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0006);
    FUN_00765c50(uVar1);
    local_c = (void *)0x19;
    FUN_0072b0e0(auStack_1f0);
    break;
  case 6:
    ExceptionList = &local_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0007);
    FUN_00765c50(uVar1);
    local_c = (void *)0x1a;
    FUN_0072b0e0(auStack_1f0);
    break;
  case 7:
    return;
  case 8:
    ExceptionList = &local_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3eb0008);
    FUN_00765c50(uVar1);
    local_c = (void *)0x1b;
    FUN_0072b0e0(auStack_1d4);
    break;
  default:
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072b6f0 @ 0x0072b6f0 ====

void FUN_0072b6f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0072b0c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072b710 @ 0x0072b710 ====

void FUN_0072b710(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee398;
  return;
}


// ==== FUN_0072b720 @ 0x0072b720 ====

void FUN_0072b720(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee398;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072b740 @ 0x0072b740 ====

uint FUN_0072b740(int param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    return 0;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *(undefined2 *)((int)in_ECX + 0x1a) = 0;
  *(undefined2 *)(in_ECX + 7) = 0;
  in_ECX[8] = param_1;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x10))(param_1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  cVar1 = (**(code **)(*piVar2 + 0xc))(in_ECX + 2);
  return -(uint)(cVar1 != '\0') & (uint)(in_ECX + 2);
}


// ==== FUN_0072b7a0 @ 0x0072b7a0 ====

bool FUN_0072b7a0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    return false;
  }
  if (param_1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x10))(*(undefined4 *)(param_1 + 0x18));
    if (piVar2 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar2 + 8))(param_1);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_0072b7e0 @ 0x0072b7e0 ====

bool FUN_0072b7e0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    return false;
  }
  if (param_1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x10))(*(undefined4 *)(param_1 + 0x18));
    if (piVar2 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar2 + 4))(param_1);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_0072b820 @ 0x0072b820 ====

void FUN_0072b820(undefined1 *param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    if (DAT_00b5ac1c != (int *)0x0) {
      cVar1 = (**(code **)(*DAT_00b5ac1c + 0x30))();
      if (cVar1 == '\0') {
        *(undefined1 *)(in_ECX + 5) = 1;
        return;
      }
    }
    *(undefined1 *)(in_ECX + 5) = *param_1;
  }
  return;
}


// ==== FUN_0072b890 @ 0x0072b890 ====

undefined4 FUN_0072b890(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_00b5a97c != 0) {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0xac) == param_1)) {
      return 1;
    }
  }
  if (DAT_00b5acd8 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0xc))();
      if (iVar1 == 0) {
        return 2;
      }
      if (iVar1 == 2) {
        return 3;
      }
    }
  }
  return 0;
}


// ==== FUN_0072b900 @ 0x0072b900 ====

void FUN_0072b900(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  
  piVar4 = (int *)**(int **)(in_ECX + 0x28);
  if (piVar4 != *(int **)(in_ECX + 0x28)) {
    do {
      if ((undefined4 *)piVar4[4] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar4[4])(1);
      }
      if (*(char *)((int)piVar4 + 0x15) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x15);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x15);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(in_ECX + 0x28));
  }
  FUN_0072bc70(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 4));
  *(int *)(*(int *)(in_ECX + 0x28) + 4) = *(int *)(in_ECX + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x28);
  *(int *)(*(int *)(in_ECX + 0x28) + 8) = *(int *)(in_ECX + 0x28);
  return;
}


// ==== FUN_0072b9a0 @ 0x0072b9a0 ====

undefined4 FUN_0072b9a0(uint param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  param_1 = FUN_0072b890(param_1);
  if ((param_1 != 0) && (param_1 < 4)) {
    FUN_0079bba0(&local_4,&param_1);
    if (local_4 != *(int *)(in_ECX + 0x28)) {
      return *(undefined4 *)(local_4 + 0x10);
    }
  }
  return 0;
}


// ==== FUN_0072ba00 @ 0x0072ba00 ====

void FUN_0072ba00(void)

{
  void *local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991411;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_1c = operator_new(4);
  local_4 = 0;
  if (local_1c == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00789f80();
  }
  local_4 = 0xffffffff;
  local_1c = (void *)0x1;
  FUN_0072c140(local_14,&local_1c);
  local_1c = operator_new(4);
  local_4 = 1;
  if (local_1c == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00789d10();
  }
  local_4 = 0xffffffff;
  local_1c = (void *)0x2;
  FUN_0072c140(local_14,&local_1c);
  local_1c = operator_new(4);
  local_4 = 2;
  if (local_1c == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00789ae0();
  }
  local_4 = 0xffffffff;
  local_1c = (void *)0x3;
  FUN_0072c140(local_14,&local_1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072bb20 @ 0x0072bb20 ====

void FUN_0072bb20(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0099142e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ee3b8;
  local_4 = 1;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
    FUN_0072b900();
  }
  DAT_00b5ad00 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_0072c200(local_10,*(undefined4 *)in_ECX[10],(undefined4 *)in_ECX[10]);
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_0072bbb0 @ 0x0072bbb0 ====

void FUN_0072bbb0(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099144b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ee3b8;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  pcVar1 = (char *)(in_ECX + 1);
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *(undefined2 *)((int)in_ECX + 0x1a) = 0;
  *(undefined2 *)(in_ECX + 7) = 0;
  local_4 = 0;
  in_ECX[8] = 0;
  iVar2 = FUN_0058d7c0();
  in_ECX[10] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[10] + 4) = in_ECX[10];
  *(undefined4 *)in_ECX[10] = in_ECX[10];
  *(undefined4 *)(in_ECX[10] + 8) = in_ECX[10];
  in_ECX[0xb] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pcVar1 == (char *)0x0) {
    DAT_00b5ad00 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ad00 = in_ECX;
  }
  if (*pcVar1 != '\x01') {
    *pcVar1 = '\x01';
    FUN_0072ba00();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072bc70 @ 0x0072bc70 ====

void FUN_0072bc70(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0072bc70(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0072bcb0 @ 0x0072bcb0 ====

void FUN_0072bcb0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009913d8;
  local_c = ExceptionList;
  if (0x1ffffffd < *(uint *)(in_ECX + 8)) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  ExceptionList = &local_c;
  piVar4 = (int *)FUN_00448a90(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
                               param_4,0);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = piVar4;
    **(undefined4 **)(in_ECX + 4) = piVar4;
    *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar4;
    if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
      *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
    }
  }
  else {
    *param_3 = piVar4;
    if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      **(int **)(in_ECX + 4) = (int)piVar4;
    }
  }
  cVar1 = *(char *)(piVar4[1] + 0x14);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x14) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[5] == '\0') {
LAB_0072bda9:
        *(undefined1 *)(*piVar5 + 0x14) = 1;
        *(undefined1 *)(piVar6 + 5) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x14) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00448a00(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x14) = 0;
        FUN_00519c40(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[5] == '\0') goto LAB_0072bda9;
      if (piVar7 == (int *)*piVar2) {
        FUN_00519c40(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x14) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x14) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x15) == '\0') {
        *(int *)(*piVar2 + 4) = iVar3;
      }
      piVar2[1] = *(int *)(iVar3 + 4);
      if (iVar3 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar6 = *(int **)(iVar3 + 4);
        if (iVar3 == *piVar6) {
          *piVar6 = (int)piVar2;
        }
        else {
          piVar6[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar7[1] + 0x14);
  } while( true );
}


// ==== FUN_0072be90 @ 0x0072be90 ====

/* WARNING: Removing unreachable block (ram,0x0072bfa3) */
/* WARNING: Removing unreachable block (ram,0x0072bfb3) */
/* WARNING: Removing unreachable block (ram,0x0072bfbc) */
/* WARNING: Removing unreachable block (ram,0x0072bfbf) */
/* WARNING: Removing unreachable block (ram,0x0072bfaf) */
/* WARNING: Removing unreachable block (ram,0x0072bfcd) */
/* WARNING: Removing unreachable block (ram,0x0072bfda) */
/* WARNING: Removing unreachable block (ram,0x0072bfe5) */
/* WARNING: Removing unreachable block (ram,0x0072bfe1) */
/* WARNING: Removing unreachable block (ram,0x0072bfd5) */
/* WARNING: Removing unreachable block (ram,0x0072bfe8) */

void FUN_0072be90(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009913d8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x15) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &pvStack_c;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c7c8);
  }
  ExceptionList = &pvStack_c;
  FUN_00458720();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    if (*(char *)(param_2[2] + 0x15) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      piVar3 = (int *)FUN_004cf3b0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      uVar4 = FUN_004489e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[5] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[5] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00448a00(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(*piVar5 + 0x14) == '\x01') && (*(char *)(piVar5[2] + 0x14) == '\x01'))
            goto LAB_0072c0b5;
            if (*(char *)(piVar5[2] + 0x14) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              *(undefined1 *)(piVar5 + 5) = 0;
              FUN_00519c40(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 5) = (char)piVar3[5];
            *(undefined1 *)(piVar3 + 5) = 1;
            *(undefined1 *)(piVar5[2] + 0x14) = 1;
            FUN_00448a00(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00519c40(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(piVar5[2] + 0x14) != '\x01') || (*(char *)(*piVar5 + 0x14) != '\x01')) {
              if (*(char *)(*piVar5 + 0x14) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x14) = 1;
                *(undefined1 *)(piVar5 + 5) = 0;
                FUN_00448a00(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 5) = (char)piVar3[5];
              *(undefined1 *)(piVar3 + 5) = 1;
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              FUN_00519c40(piVar3);
              break;
            }
LAB_0072c0b5:
            *(undefined1 *)(piVar5 + 5) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 5) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_0072c140 @ 0x0072c140 ====

void FUN_0072c140(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < (uint)puVar4[3];
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0072bcb0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0072bcb0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0072c200 @ 0x0072c200 ====

void FUN_0072c200(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_0072bc70(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x15) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x15);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x15);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0072be90(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0072c2c0 @ 0x0072c2c0 ====

void FUN_0072c2c0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0072c200(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0072c2f0 @ 0x0072c2f0 ====

void FUN_0072c2f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0072bb20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072c310 @ 0x0072c310 ====

void FUN_0072c310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee3d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072c330 @ 0x0072c330 ====

void FUN_0072c330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee3e4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acfc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5acfc = in_ECX;
  return;
}


// ==== FUN_0072c360 @ 0x0072c360 ====

undefined4 FUN_0072c360(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined4 local_4;
  
  local_14 = 0;
  local_c = 0;
  local_a = 0;
  local_8 = 0;
  local_4 = *(undefined4 *)(param_1 + 0x10);
  local_1c = 0;
  local_18 = 0;
  local_10 = 1;
  (**(code **)(*DAT_00b5ad00 + 8))(&local_1c);
  return 1;
}


// ==== FUN_0072c3b0 @ 0x0072c3b0 ====

undefined4 FUN_0072c3b0(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined4 local_4;
  
  local_4 = *(undefined4 *)(param_1 + 0x10);
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_c = 0;
  local_a = 0;
  local_8 = 0;
  local_10 = 0;
  (**(code **)(*DAT_00b5ad00 + 8))(&local_1c);
  return 1;
}


// ==== FUN_0072c400 @ 0x0072c400 ====

undefined4 FUN_0072c400(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined4 local_4;
  
  local_14 = 0;
  local_10 = 0;
  local_a = 0;
  local_4 = *(undefined4 *)(param_1 + 0x10);
  local_c = *(undefined2 *)(param_1 + 0x16);
  local_8 = *(undefined2 *)(param_1 + 0x14);
  local_1c = 0;
  local_18 = 0;
  (**(code **)(*DAT_00b5ad00 + 0xc))(&local_1c);
  return 1;
}


// ==== FUN_0072c460 @ 0x0072c460 ====

undefined4 FUN_0072c460(int param_1)

{
  int iVar1;
  undefined1 auStack_1a [26];
  
  iVar1 = (**(code **)(*DAT_00b5ad04 + 0x18))(*(undefined4 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(*DAT_00b5ad00 + 0xc))(auStack_1a + -6);
  return 1;
}


// ==== FUN_0072c4e0 @ 0x0072c4e0 ====

void FUN_0072c4e0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acfc = 0;
  *in_ECX = &PTR_FUN_009ee3d8;
  return;
}


// ==== FUN_0072c500 @ 0x0072c500 ====

uint FUN_0072c500(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  iVar2 = FUN_00424500();
  switch(iVar2 + 0xfaf6fff9U) {
  case 0:
    uVar1 = FUN_0072c400(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 1:
    uVar1 = FUN_0072c360(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 2:
    uVar1 = FUN_0072c3b0(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  default:
    return iVar2 + 0xfaf6fff9U & 0xffffff00;
  case 5:
    uVar1 = FUN_0072c460(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  }
}


// ==== FUN_0072c5a0 @ 0x0072c5a0 ====

undefined4 FUN_0072c5a0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0072c500(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0072c5d0 @ 0x0072c5d0 ====

void FUN_0072c5d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0072c4e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072c5f0 @ 0x0072c5f0 ====

void FUN_0072c5f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee3f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072c610 @ 0x0072c610 ====

void FUN_0072c610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee414;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad04 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad04 = in_ECX;
  return;
}


// ==== FUN_0072c640 @ 0x0072c640 ====

void FUN_0072c640(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    (**(code **)(*DAT_00b5acf8 + 8))(0,*(undefined4 *)(param_1 + 8));
    return;
  case 1:
    iVar1 = *(int *)(param_1 + 8);
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    iVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
    if ((iVar1 == iVar3) || (iVar3 = (**(code **)(*DAT_00b5af10 + 0xc))(), iVar1 == iVar3)) {
      (**(code **)(*DAT_00b5acf8 + 8))(1,uVar2);
    }
    break;
  case 2:
    (**(code **)(*DAT_00b5acf8 + 8))(2,*(undefined4 *)(param_1 + 0xc));
    return;
  case 3:
    (**(code **)(*DAT_00b5acf8 + 8))(3,*(undefined4 *)(param_1 + 8));
    return;
  case 4:
    (**(code **)(*DAT_00b5acf8 + 8))(4,*(undefined4 *)(param_1 + 0xc));
    return;
  case 5:
    (**(code **)(*DAT_00b5acf8 + 8))(5,0);
    return;
  case 6:
    (**(code **)(*DAT_00b5acf8 + 8))(6,0);
    return;
  case 8:
    (**(code **)(*DAT_00b5acf8 + 8))(8,0);
    return;
  }
  return;
}


// ==== FUN_0072c740 @ 0x0072c740 ====

void FUN_0072c740(void)

{
                    /* WARNING: Could not recover jumptable at 0x0072c748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad00 + 0x14))();
  return;
}


// ==== FUN_0072c750 @ 0x0072c750 ====

undefined4 FUN_0072c750(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x10))(param_1);
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*DAT_00b5ad00 + 4))(param_1);
    if ((iVar2 != 0) && ((*(short *)(iVar2 + 0x14) != 0 || (*(char *)(iVar2 + 0xc) == '\x01')))) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0072c790 @ 0x0072c790 ====

undefined4 FUN_0072c790(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ad00 + 0x10))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    if (iVar3 == 2) {
      cVar1 = (**(code **)(*DAT_00b5a7b8 + 0x3c))(param_1);
    }
    else {
      if (iVar3 != 3) {
        return 0;
      }
      iVar3 = (**(code **)(*DAT_00b5af10 + 0xc))();
      if (iVar3 == param_1) {
        return 0;
      }
      cVar1 = (**(code **)(*DAT_00b5a7b8 + 0x40))(param_1);
    }
    if (cVar1 == '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0072c800 @ 0x0072c800 ====

bool FUN_0072c800(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5ad00 + 4))(param_1);
  if (iVar1 == 0) {
    return false;
  }
  return *(short *)(iVar1 + 0x14) != 0;
}


// ==== FUN_0072c830 @ 0x0072c830 ====

undefined1 FUN_0072c830(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5ad00 + 4))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined1 *)(iVar1 + 0xc);
}


// ==== FUN_0072c850 @ 0x0072c850 ====

void FUN_0072c850(void)

{
                    /* WARNING: Could not recover jumptable at 0x0072c858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad00 + 4))();
  return;
}


// ==== FUN_0072c860 @ 0x0072c860 ====

void FUN_0072c860(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad04 = 0;
  *in_ECX = &PTR_FUN_009ee3f0;
  return;
}


// ==== FUN_0072c880 @ 0x0072c880 ====

undefined4 FUN_0072c880(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70350000) {
    FUN_0072c640(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_0072c8b0 @ 0x0072c8b0 ====

void FUN_0072c8b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0072c860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072c8d0 @ 0x0072c8d0 ====

void FUN_0072c8d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee478;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072c900 @ 0x0072c900 ====

void FUN_0072c900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee484;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0f8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0f8 = in_ECX;
  return;
}


// ==== FUN_0072c950 @ 0x0072c950 ====

void FUN_0072c950(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b0f8 = 0;
  *in_ECX = &PTR_FUN_009ee478;
  return;
}


// ==== FUN_0072c970 @ 0x0072c970 ====

void FUN_0072c970(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 unaff_EBP;
  undefined1 *puStack_80;
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  void *pvStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined1 *puStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_32 [38];
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_00991468;
  pvStack_c = ExceptionList;
  uStack_48 = 0;
  uStack_4c = 0x72c99a;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  uStack_4c = 0x72c9a5;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  uStack_4c = 1;
  puStack_50 = (undefined1 *)0x72c9b4;
  (**(code **)(*DAT_00b5b0fc + 0x40))();
  uVar1 = *(undefined1 *)(iStack_4 + 0x16);
  uVar2 = *(undefined2 *)(iStack_4 + 0x14);
  puStack_50 = (undefined1 *)0x0;
  puStack_54 = &DAT_009ee46e;
  puStack_58 = (undefined1 *)0x72c9e6;
  iStack_4 = *(undefined4 *)(iStack_4 + 0x10);
  FUN_00401740();
  puStack_50 = (undefined1 *)0x0;
  pvStack_c = (void *)0x0;
  puStack_54 = (undefined1 *)0x72ca06;
  (**(code **)(*DAT_00b5b0fc + 0x3c))();
  switch(uVar1) {
  case 0:
    puStack_54 = (undefined1 *)0x72ca21;
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 4))();
    puStack_58 = (undefined1 *)*puVar5;
    puStack_5c = (undefined1 *)0x72ca2a;
    puStack_54 = (undefined1 *)CONCAT22((short)((uint)unaff_EBP >> 0x10),uVar2);
    FUN_00828550();
    puStack_54 = (undefined1 *)0x72ca38;
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 8))();
    puStack_54 = (undefined1 *)*puVar5;
    puStack_5c = (undefined1 *)0x72ca41;
    puStack_58 = (undefined1 *)iVar3;
    FUN_00828500();
    puStack_54 = (undefined1 *)0x72ca4f;
    iVar6 = (**(code **)(*DAT_00b5b100 + 0xc))();
    if (iVar6 != 0) {
      puStack_54 = (undefined1 *)0x72ca5e;
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 0xc))();
      puStack_54 = (undefined1 *)*puVar5;
      puStack_5c = (undefined1 *)0x72ca67;
      puStack_58 = (undefined1 *)iVar3;
      FUN_00828500();
    }
    puStack_54 = auStack_32 + -10;
    puStack_58 = (undefined1 *)0x72ca7a;
    (**(code **)(*DAT_00b5b100 + 0x14))();
    puStack_58 = auStack_32 + -0xe;
    puStack_5c = (undefined1 *)0x72ca8a;
    (**(code **)(*DAT_00b5b100 + 0x18))();
    puStack_5c = (undefined1 *)0x3e90006;
    uStack_60 = 0;
    uStack_64 = 0x72ca9b;
    uStack_6c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0xffffffff;
    pvStack_68 = (void *)0x0;
    uStack_70 = 0x72caa8;
    FUN_00401660();
    puStack_50 = (undefined1 *)&uStack_7c;
    puStack_80 = (undefined1 *)0xffffffff;
    uStack_64 = 0xf;
    pvStack_68 = (void *)0x0;
    uStack_78 = uStack_78 & 0xffffff00;
    FUN_00401660(auStack_32 + -0x12,0);
    puStack_80 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5b0fc + 0x3c))(1);
    goto LAB_0072cae5;
  default:
    puStack_54 = (undefined1 *)0x3e9000b;
    break;
  case 5:
    puStack_54 = (undefined1 *)0x72cb43;
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 4))();
    puStack_54 = (undefined1 *)*puVar5;
    puStack_5c = (undefined1 *)0x72cb4c;
    puStack_58 = (undefined1 *)iVar3;
    FUN_00828500();
    puStack_54 = (undefined1 *)0x72cb5a;
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 8))();
    puStack_54 = (undefined1 *)*puVar5;
    puStack_5c = (undefined1 *)0x72cb63;
    puStack_58 = (undefined1 *)iVar3;
    FUN_00828500();
    puStack_54 = (undefined1 *)0x72cb71;
    iVar6 = (**(code **)(*DAT_00b5b100 + 0xc))();
    if (iVar6 != 0) {
      puStack_54 = (undefined1 *)0x72cb80;
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 0xc))();
      puStack_54 = (undefined1 *)*puVar5;
      puStack_5c = (undefined1 *)0x72cb89;
      puStack_58 = (undefined1 *)iVar3;
      FUN_00828500();
    }
    puStack_54 = auStack_32 + -10;
    puStack_58 = (undefined1 *)0x72cb9c;
    (**(code **)(*DAT_00b5b100 + 0x10))();
    puStack_58 = auStack_32 + -0xe;
    puStack_5c = (undefined1 *)0x72cbac;
    (**(code **)(*DAT_00b5b100 + 0x14))();
    puStack_5c = auStack_32 + -0x12;
    uStack_60 = 0x72cbbc;
    (**(code **)(*DAT_00b5b100 + 0x18))();
    uStack_60 = 0x3e90007;
    goto LAB_0072cc58;
  case 6:
    puStack_54 = (undefined1 *)0x72cbdb;
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 8))();
    puStack_54 = (undefined1 *)*puVar5;
    puStack_5c = (undefined1 *)0x72cbe4;
    puStack_58 = (undefined1 *)iVar3;
    FUN_00828500();
    puStack_54 = (undefined1 *)0x72cbf2;
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 4))();
    puStack_54 = (undefined1 *)*puVar5;
    puStack_58 = (undefined1 *)0x72cbfa;
    FUN_00828440();
    puStack_54 = (undefined1 *)0x72cc08;
    iVar6 = (**(code **)(*DAT_00b5b100 + 0xc))();
    if (iVar6 != 0) {
      puStack_54 = (undefined1 *)0x72cc17;
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 0xc))();
      puStack_54 = (undefined1 *)*puVar5;
      puStack_5c = (undefined1 *)0x72cc20;
      puStack_58 = (undefined1 *)iVar3;
      FUN_00828500();
    }
    puStack_54 = auStack_32 + -10;
    puStack_58 = (undefined1 *)0x72cc33;
    (**(code **)(*DAT_00b5b100 + 0x14))();
    puStack_58 = auStack_32 + -0xe;
    puStack_5c = (undefined1 *)0x72cc43;
    (**(code **)(*DAT_00b5b100 + 0x18))();
    puStack_5c = auStack_32 + -0x12;
    uStack_60 = 0x72cc53;
    (**(code **)(*DAT_00b5b100 + 0x10))();
    uStack_60 = 0x3e9000c;
LAB_0072cc58:
    uStack_64 = 0;
    pvStack_68 = (void *)0x72cc64;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pvStack_68 = (void *)0xffffffff;
    uStack_6c = 0;
    uStack_74 = 0x72cc71;
    FUN_00401660();
    puStack_54 = (undefined1 *)&puStack_80;
    pvStack_68 = (void *)0xf;
    uStack_6c = 0;
    uStack_7c = uStack_7c & 0xffffff00;
    FUN_00401660(&uStack_48,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0072cae5:
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x20) + 0x54))();
    (**(code **)(*piVar4 + 8))(unaff_EBP);
    goto LAB_0072caf9;
  case 7:
    puStack_54 = (undefined1 *)0x3e90003;
  }
  puStack_58 = (undefined1 *)0x0;
  puStack_5c = (undefined1 *)0x72ccb7;
  uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_5c = (undefined1 *)0xffffffff;
  uStack_60 = 0;
  pvStack_68 = (void *)0x72ccc4;
  FUN_00401660();
  uStack_78 = 0xffffffff;
  puStack_5c = (undefined1 *)0xf;
  uStack_7c = 0;
  puStack_80 = auStack_32 + -10;
  uStack_60 = 0;
  uStack_70 = uStack_70 & 0xffffff00;
  FUN_00401660();
  uStack_78 = 2;
  uStack_7c = 0x72ccf4;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_0072caf9:
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5b0fc + 8))();
  if (puStack_54 < (undefined1 *)0x10) {
    ExceptionList = puStack_50;
    return;
  }
  _free(pvStack_68);
  return;
}


// ==== FUN_0072cd20 @ 0x0072cd20 ====

undefined4 FUN_0072cd20(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x51c0000) {
    (**(code **)(*DAT_00b5b0fc + 0xc))();
    return 1;
  }
  if (iVar1 == 0x51c0002) {
    FUN_0072c970(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x51c0004) {
    (**(code **)(*DAT_00b5b0fc + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_0072cd80 @ 0x0072cd80 ====

undefined4 FUN_0072cd80(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0072cd20(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0072cdb0 @ 0x0072cdb0 ====

void FUN_0072cdb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0072c950();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072cdd0 @ 0x0072cdd0 ====

void FUN_0072cdd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee54c;
  return;
}


// ==== FUN_0072cde0 @ 0x0072cde0 ====

void FUN_0072cde0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee54c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072ce00 @ 0x0072ce00 ====

undefined1 FUN_0072ce00(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0072ce20 @ 0x0072ce20 ====

void FUN_0072ce20(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee5c4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0072ce50 @ 0x0072ce50 ====

void FUN_0072ce50(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ee59c;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 4) = 1;
  cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a78c + 0x24))();
  }
  (**(code **)(*DAT_00b5a78c + 0x60))(6);
  (**(code **)(*DAT_00b5acd4 + 4))(7);
  return;
}


// ==== FUN_0072ceb0 @ 0x0072ceb0 ====

void FUN_0072ceb0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x20))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ee5b0;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 1) = 0;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_0072cf00 @ 0x0072cf00 ====

void FUN_0072cf00(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0072cf19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5b100 + 0x1c))();
    return;
  }
  return;
}


// ==== FUN_0072cf20 @ 0x0072cf20 ====

bool FUN_0072cf20(void)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*in_ECX + 0x2c))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*in_ECX + 0x30))();
      return iVar2 != 0;
    }
  }
  return false;
}


// ==== FUN_0072cf60 @ 0x0072cf60 ====

undefined4 FUN_0072cf60(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0x2c))();
    iVar1 = (**(code **)(*(int *)*puVar2 + 0x34))();
    puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0x2c))();
    iVar3 = (**(code **)(*(int *)*puVar2 + 0x2c))();
    piVar4 = (int *)(**(code **)(*DAT_00b5ab2c + 8))
                              (*(undefined4 *)(iVar3 + 8),*(undefined1 *)(iVar1 + 0x68));
    if (piVar4 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar4 + 4))();
      return *(undefined4 *)(iVar1 + 8);
    }
  }
  return 0;
}


// ==== FUN_0072cfc0 @ 0x0072cfc0 ====

undefined4 FUN_0072cfc0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x34))();
  if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
    return 0;
  }
  uVar2 = FUN_008285c0(*piVar1);
  return uVar2;
}


// ==== FUN_0072cff0 @ 0x0072cff0 ====

void FUN_0072cff0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0072cff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b100 + 4))();
  return;
}


// ==== FUN_0072d000 @ 0x0072d000 ====

void FUN_0072d000(void)

{
                    /* WARNING: Could not recover jumptable at 0x0072d008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b100 + 8))();
  return;
}


// ==== FUN_0072d010 @ 0x0072d010 ====

void FUN_0072d010(void)

{
                    /* WARNING: Could not recover jumptable at 0x0072d018. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b100 + 0xc))();
  return;
}


// ==== FUN_0072d020 @ 0x0072d020 ====

void FUN_0072d020(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x51c0003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_0072d060 @ 0x0072d060 ====

undefined4 FUN_0072d060(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_upgradewnd_009ee50c,0xf);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_upgradewnd_009ee51c,0xf);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_0072d0c0 @ 0x0072d0c0 ====

undefined4 FUN_0072d0c0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0072d060(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0072d0f0 @ 0x0072d0f0 ====

void FUN_0072d0f0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  void *local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009914a8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ee5dc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0fc = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b0fc = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009ee4c6,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_upgradewnd_009ee4c8,0xf);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009ee4d8,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_upgradewnd_009ee4dc,0xf);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (local_28 < 0x10) {
    *(undefined1 *)(in_ECX + 1) = 0;
    in_ECX[2] = 0;
    *(undefined1 *)((int)in_ECX + 6) = 0;
    *(undefined1 *)((int)in_ECX + 5) = 0;
    ExceptionList = local_24;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_0072d280 @ 0x0072d280 ====

void FUN_0072d280(void)

{
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009914ca;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ee5dc;
  local_4 = 0;
  DAT_00b5b0fc = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_upgradewnd_009ee4ec,0xf);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = (void *)0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_upgradewnd_009ee4fc,0xf);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009ee54c;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_0072d360 @ 0x0072d360 ====

/* WARNING: Removing unreachable block (ram,0x0072d3d7) */

void FUN_0072d360(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *in_ECX;
  undefined1 auStack_3c [4];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009914dc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    FUN_00401740();
    puStack_8 = (undefined1 *)0x0;
    iVar2 = (**(code **)(*in_ECX + 0x2c))();
    if ((iVar2 != 0) && (iVar2 = (**(code **)(*in_ECX + 0x30))(), iVar2 != 0)) {
      uVar3 = (**(code **)(*DAT_00b5a78c + 0x40))();
      uVar4 = (**(code **)(*in_ECX + 0x28))();
      if (uVar3 < uVar4) {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00401660();
        FUN_00765c50(auStack_3c + 8);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
      else {
        puVar5 = (undefined4 *)(**(code **)(*in_ECX + 0x2c))();
        cVar1 = (**(code **)(*(int *)*puVar5 + 0x80))();
        if (cVar1 == '\0') {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00401660();
          FUN_00765c50(auStack_3c + 8);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        }
        else {
          (**(code **)(*DAT_00b5a6ac + 0x20))();
          iVar2 = FUN_0072d560();
          iVar6 = (**(code **)(*in_ECX + 0x2c))();
          *(undefined2 *)(iVar2 + 0x14) = *(undefined2 *)(iVar6 + 4);
          *(undefined1 *)(iVar2 + 0x16) = *(undefined1 *)(iVar6 + 6);
          iVar6 = (**(code **)(*in_ECX + 0x30))();
          *(undefined2 *)(iVar2 + 0x17) = *(undefined2 *)(iVar6 + 4);
          *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)(iVar6 + 6);
          iVar6 = (**(code **)(*in_ECX + 0x34))();
          if (iVar6 == 0) {
            *(undefined1 *)(iVar2 + 0x1d) = 0;
          }
          else {
            *(undefined1 *)(iVar2 + 0x1d) = 1;
            iVar6 = (**(code **)(*in_ECX + 0x34))();
            *(undefined2 *)(iVar2 + 0x1a) = *(undefined2 *)(iVar6 + 4);
            *(undefined1 *)(iVar2 + 0x1c) = *(undefined1 *)(iVar6 + 6);
          }
          *(int *)(iVar2 + 0x10) = in_ECX[2];
          FUN_004ef210();
          *(undefined1 *)((int)in_ECX + 6) = 0;
          *(undefined1 *)((int)in_ECX + 5) = 0;
          (**(code **)(*DAT_00b5af2c + 4))();
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0072d560 @ 0x0072d560 ====

void FUN_0072d560(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x51c0001;
  *(undefined2 *)((int)pvVar1 + 6) = 0x20;
  FUN_004244d0();
  return;
}


// ==== FUN_0072d590 @ 0x0072d590 ====

undefined4 FUN_0072d590(void)

{
  return 0x70330000;
}


// ==== FUN_0072d5a0 @ 0x0072d5a0 ====

undefined4 FUN_0072d5a0(void)

{
  return 0x70330001;
}


// ==== FUN_0072d5b0 @ 0x0072d5b0 ====

undefined4 FUN_0072d5b0(void)

{
  return 0x70330002;
}


// ==== FUN_0072d5c0 @ 0x0072d5c0 ====

void FUN_0072d5c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0072d280();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072d5e0 @ 0x0072d5e0 ====

void FUN_0072d5e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee66c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072d600 @ 0x0072d600 ====

undefined4 FUN_0072d600(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0072d610 @ 0x0072d610 ====

undefined4 FUN_0072d610(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0072d620 @ 0x0072d620 ====

undefined4 FUN_0072d620(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0072d630 @ 0x0072d630 ====

void FUN_0072d630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee698;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b100 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b100 = in_ECX;
  return;
}


// ==== FUN_0072d660 @ 0x0072d660 ====

void FUN_0072d660(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_0072d680 @ 0x0072d680 ====

void FUN_0072d680(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_0072d6a0 @ 0x0072d6a0 ====

void FUN_0072d6a0(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0072d6e0 @ 0x0072d6e0 ====

void FUN_0072d6e0(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0072d740 @ 0x0072d740 ====

void FUN_0072d740(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_0072d7a0 @ 0x0072d7a0 ====

void FUN_0072d7a0(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_0072d800 @ 0x0072d800 ====

void FUN_0072d800(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee698;
  DAT_00b5b100 = 0;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_0072d850 @ 0x0072d850 ====

void FUN_0072d850(byte param_1)

{
  void *in_ECX;
  
  FUN_0072d800();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072d870 @ 0x0072d870 ====

void FUN_0072d870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee714;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072d890 @ 0x0072d890 ====

undefined1 FUN_0072d890(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0072d8a0 @ 0x0072d8a0 ====

void FUN_0072d8a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee778;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b188 = (undefined4 *)0x0;
    DAT_00000000 = 0;
    in_ECX[2] = 2;
    return;
  }
  DAT_00b5b188 = in_ECX;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 2;
  return;
}


// ==== FUN_0072d8e0 @ 0x0072d8e0 ====

void FUN_0072d8e0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined4 *)(in_ECX + 8) = 2;
    return;
  }
  *puVar1 = &PTR_FUN_009ee728;
  FUN_00797a20(puVar1);
  *(undefined4 *)(in_ECX + 8) = 2;
  return;
}


// ==== FUN_0072d960 @ 0x0072d960 ====

void FUN_0072d960(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee73c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0072d9c0 @ 0x0072d9c0 ====

void FUN_0072d9c0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) == 2) || (*(int *)(in_ECX + 8) == 3)) {
    FUN_0072d8e0();
  }
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_0072d9e0 @ 0x0072d9e0 ====

void FUN_0072d9e0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) == 2) || (*(int *)(in_ECX + 8) == 3)) {
    FUN_0072d960();
  }
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0072da00 @ 0x0072da00 ====

void FUN_0072da00(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b188 = 0;
  *in_ECX = &PTR_FUN_009ee714;
  return;
}


// ==== FUN_0072da20 @ 0x0072da20 ====

undefined4 FUN_0072da20(void)

{
  return 0x70010000;
}


// ==== FUN_0072da30 @ 0x0072da30 ====

undefined4 FUN_0072da30(void)

{
  return 0x70010001;
}


// ==== FUN_0072da40 @ 0x0072da40 ====

undefined4 FUN_0072da40(void)

{
  return 0x70320000;
}


// ==== FUN_0072da50 @ 0x0072da50 ====

undefined4 FUN_0072da50(void)

{
  return 0x70320001;
}


// ==== FUN_0072da60 @ 0x0072da60 ====

void FUN_0072da60(byte param_1)

{
  void *in_ECX;
  
  FUN_0072da00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072da80 @ 0x0072da80 ====

void FUN_0072da80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee8c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0072dae0 @ 0x0072dae0 ====

void FUN_0072dae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ee8e0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aca4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aca4 = in_ECX;
  return;
}


// ==== FUN_0072db60 @ 0x0072db60 ====

void FUN_0072db60(void)

{
  undefined4 uStack00000004;
  
  uStack00000004 = 5;
                    /* WARNING: Could not recover jumptable at 0x0072db70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af2c + 8))();
  return;
}


// ==== FUN_0072db80 @ 0x0072db80 ====

void FUN_0072db80(void)

{
  undefined4 uStack00000004;
  
  uStack00000004 = 5;
                    /* WARNING: Could not recover jumptable at 0x0072db90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af2c + 8))();
  return;
}


// ==== FUN_0072dbb0 @ 0x0072dbb0 ====

void FUN_0072dbb0(void)

{
  (**(code **)(*DAT_00b5aca8 + 0xc))(1);
  (**(code **)(*DAT_00b5acac + 0x10))();
  return;
}


// ==== FUN_0072dbd0 @ 0x0072dbd0 ====

void FUN_0072dbd0(void)

{
  (**(code **)(*DAT_00b5af2c + 8))(5);
  (**(code **)(*DAT_00b5aca8 + 0x50))();
  return;
}


// ==== FUN_0072dbf0 @ 0x0072dbf0 ====

void FUN_0072dbf0(void)

{
  (**(code **)(*DAT_00b5aca8 + 0xe4))();
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  return;
}


// ==== FUN_0072dc40 @ 0x0072dc40 ====

void FUN_0072dc40(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aca4 = 0;
  *in_ECX = &PTR_FUN_009ee8c0;
  return;
}


// ==== FUN_0072dc60 @ 0x0072dc60 ====

void FUN_0072dc60(int param_1)

{
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_40;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00991530;
  local_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x18)) {
  case 1:
    uStack_54 = 0;
    uStack_58 = 0x72dca8;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x72dcc6;
    FUN_00401660();
    puStack_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_c = (void *)0x0;
    uStack_6c = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_2c) {
      pvStack_24 = pvStack_40;
LAB_0072de65:
      uStack_54 = 0x72de6b;
      _free(pvStack_24);
      return;
    }
    break;
  case 2:
    uStack_54 = 0;
    uStack_58 = 0x72dd1d;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x72dd3b;
    FUN_00401660();
    puStack_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_c = (void *)0x1;
    uStack_6c = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_2c) {
      pvStack_24 = pvStack_40;
      goto LAB_0072de65;
    }
    break;
  case 3:
    uStack_54 = 0;
    uStack_58 = 0x72dd96;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x72ddb4;
    FUN_00401660();
    puStack_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_c = (void *)0x2;
    uStack_6c = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_2c) {
      pvStack_24 = pvStack_40;
      goto LAB_0072de65;
    }
    break;
  case 4:
    uStack_54 = 0;
    uStack_58 = 0x72de08;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_64 = 0x72de26;
    FUN_00401660();
    puStack_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_c = (void *)0x3;
    uStack_6c = 0;
    FUN_00401660(auStack_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_10) goto LAB_0072de65;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0072dea0 @ 0x0072dea0 ====

void FUN_0072dea0(int param_1)

{
  int iVar1;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_40;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00991552;
  local_c = ExceptionList;
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == 2) {
    uStack_54 = 0;
    uStack_58 = 0x72dfa3;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_64 = 0x72dfc1;
    FUN_00401660();
    local_c = (void *)0x0;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 != 4) {
        return;
      }
      uStack_54 = 0;
      uStack_58 = 0x72deef;
      ExceptionList = &local_c;
      uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0xffffffff;
      uStack_5c = 0;
      uStack_64 = 0x72df0d;
      FUN_00401660();
      puStack_4 = auStack_70;
      uStack_58 = 0xf;
      uStack_5c = 0;
      local_c = (void *)0x2;
      uStack_6c = 0;
      FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      if (uStack_2c < 0x10) {
        ExceptionList = local_c;
        return;
      }
      goto LAB_0072dffc;
    }
    uStack_54 = 0;
    uStack_58 = 0x72df68;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_64 = 0x72df86;
    FUN_00401660();
    local_c = (void *)0x1;
  }
  puStack_4 = auStack_70;
  uStack_5c = 0;
  uStack_58 = 0xf;
  uStack_6c = 0;
  FUN_00401660(auStack_30,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  if (uStack_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  pvStack_40 = pvStack_24;
LAB_0072dffc:
  uStack_54 = 0x72e002;
  _free(pvStack_40);
  return;
}


// ==== FUN_0072e020 @ 0x0072e020 ====

void FUN_0072e020(void)

{
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991564;
  pvStack_c = ExceptionList;
  uStack_34 = 0;
  puStack_38 = (undefined1 *)0x72e047;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5aca8 + 0xc))();
  puStack_38 = (undefined1 *)0x72e052;
  (**(code **)(*DAT_00b5acac + 0x10))();
  puStack_38 = (undefined1 *)0x72e05d;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  puStack_38 = (undefined1 *)0x820076;
  uStack_3c = 0;
  uStack_40 = 0x72e06e;
  uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_40 = 0xffffffff;
  uStack_44 = 0;
  uStack_4c = 0x72e08b;
  FUN_00401660();
  puStack_38 = auStack_58;
  uStack_40 = 0xf;
  uStack_44 = 0;
  uStack_54 = 0;
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  if (uStack_3c < 0x10) {
    ExceptionList = puStack_38;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_0072e0f0 @ 0x0072e0f0 ====

void FUN_0072e0f0(void)

{
  int unaff_retaddr;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_50;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099158e;
  pvStack_c = ExceptionList;
  uStack_50 = 5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x18)) {
  case 0:
    uStack_58 = 0;
    uStack_5c = 0x72e142;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72e160;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x0;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_30) {
      pvStack_28 = pvStack_44;
LAB_0072e2ff:
      uStack_58 = 0x72e305;
      _free(pvStack_28);
      return;
    }
    break;
  case 1:
    uStack_58 = 0;
    uStack_5c = 0x72e1b7;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72e1d5;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x1;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_30) {
      pvStack_28 = pvStack_44;
      goto LAB_0072e2ff;
    }
    break;
  case 2:
    uStack_58 = 0;
    uStack_5c = 0x72e230;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72e24e;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x2;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_30) {
      pvStack_28 = pvStack_44;
      goto LAB_0072e2ff;
    }
    break;
  case 3:
    uStack_58 = 0;
    uStack_5c = 0x72e2a2;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_68 = 0x72e2c0;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x3;
    uStack_70 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (0xf < uStack_14) goto LAB_0072e2ff;
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0072e330 @ 0x0072e330 ====

void FUN_0072e330(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009915c0;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  puStack_4c = (undefined *)0x72e355;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    puStack_4c = (undefined *)0x820055;
    uStack_50 = 0;
    uStack_54 = 0x72e37e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e388;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x0;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  case 1:
    puStack_4c = &DAT_0082000c;
    uStack_50 = 0;
    uStack_54 = 0x72e3ca;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e3d4;
    FUN_00765c50();
    pvStack_10 = (void *)0x1;
    goto LAB_0072e44e;
  case 2:
    puStack_4c = (undefined *)0x820057;
    uStack_50 = 0;
    uStack_54 = 0x72e3f0;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e3fa;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x2;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  case 3:
    puStack_4c = (undefined *)0x82000d;
    uStack_50 = 0;
    uStack_54 = 0x72e43c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e446;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
LAB_0072e44e:
    puStack_8 = auStack_6c;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  case 4:
    puStack_4c = (undefined *)0x820059;
    uStack_50 = 0;
    uStack_54 = 0x72e485;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e48f;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x4;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  default:
    ExceptionList = pvStack_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072e4f0 @ 0x0072e4f0 ====

void FUN_0072e4f0(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009915f2;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  puStack_4c = (undefined *)0x72e515;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    puStack_4c = (undefined *)0x82005a;
    uStack_50 = 0;
    uStack_54 = 0x72e53e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e548;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x0;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  case 1:
    puStack_4c = &DAT_0082000c;
    uStack_50 = 0;
    uStack_54 = 0x72e58a;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e594;
    FUN_00765c50();
    pvStack_10 = (void *)0x1;
    goto LAB_0072e60e;
  case 2:
    puStack_4c = (undefined *)0x820057;
    uStack_50 = 0;
    uStack_54 = 0x72e5b0;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e5ba;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x2;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  case 3:
    puStack_4c = (undefined *)0x82000d;
    uStack_50 = 0;
    uStack_54 = 0x72e5fc;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e606;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
LAB_0072e60e:
    puStack_8 = auStack_6c;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  case 4:
    puStack_4c = (undefined *)0x820059;
    uStack_50 = 0;
    uStack_54 = 0x72e645;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e64f;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x4;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    break;
  default:
    ExceptionList = pvStack_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072e6b0 @ 0x0072e6b0 ====

void FUN_0072e6b0(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099162c;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  puStack_4c = (undefined *)0x72e6d5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    puStack_4c = (undefined *)0x82005e;
    uStack_50 = 0;
    uStack_54 = 0x72e6fe;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e708;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    break;
  case 1:
    puStack_4c = &DAT_0082000c;
    uStack_50 = 0;
    uStack_54 = 0x72e727;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e731;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x1;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072e864;
  case 2:
    puStack_4c = (undefined *)0x820057;
    uStack_50 = 0;
    uStack_54 = 0x72e773;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e77d;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
    break;
  case 3:
    puStack_4c = (undefined *)0x82000d;
    uStack_50 = 0;
    uStack_54 = 0x72e799;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e7a3;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x3;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072e864;
  case 4:
    puStack_4c = (undefined *)0x820062;
    uStack_50 = 0;
    uStack_54 = 0x72e7e5;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e7ef;
    FUN_00765c50();
    pvStack_10 = (void *)0x4;
    break;
  case 5:
    puStack_4c = (undefined *)0x820059;
    uStack_50 = 0;
    uStack_54 = 0x72e82e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e838;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x5;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072e864;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8 = auStack_6c;
  FUN_00765c50(&uStack_50);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072e864:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072e8a0 @ 0x0072e8a0 ====

void FUN_0072e8a0(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991666;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  uStack_4c = 0x72e8c5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    uStack_4c = 0x820064;
    uStack_50 = 0;
    uStack_54 = 0x72e8ee;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e8f8;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    break;
  case 1:
    uStack_4c = 0x820065;
    uStack_50 = 0;
    uStack_54 = 0x72e917;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e921;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x1;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072ea54;
  case 2:
    uStack_4c = 0x820057;
    uStack_50 = 0;
    uStack_54 = 0x72e963;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e96d;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
    break;
  case 3:
    uStack_4c = 0x82000d;
    uStack_50 = 0;
    uStack_54 = 0x72e989;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e993;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x3;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072ea54;
  case 4:
    uStack_4c = 0x820066;
    uStack_50 = 0;
    uStack_54 = 0x72e9d5;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72e9df;
    FUN_00765c50();
    pvStack_10 = (void *)0x4;
    break;
  case 5:
    uStack_4c = 0x820059;
    uStack_50 = 0;
    uStack_54 = 0x72ea1e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ea28;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x5;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072ea54;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8 = auStack_6c;
  FUN_00765c50(&uStack_50);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072ea54:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072ea90 @ 0x0072ea90 ====

void FUN_0072ea90(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009916b8;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  puStack_4c = (undefined *)0x72eab5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    puStack_4c = (undefined *)0x820082;
    uStack_50 = 0;
    uStack_54 = 0x72eade;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72eae8;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    goto LAB_0072eaf0;
  case 1:
    puStack_4c = &DAT_0082000c;
    uStack_50 = 0;
    uStack_54 = 0x72eb2a;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72eb34;
    FUN_00765c50();
    pvStack_10 = (void *)0x1;
    break;
  case 2:
    puStack_4c = (undefined *)0x820057;
    uStack_50 = 0;
    uStack_54 = 0x72eb53;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72eb5d;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
    goto LAB_0072eaf0;
  case 3:
    puStack_4c = (undefined *)0x820058;
    uStack_50 = 0;
    uStack_54 = 0x72eb79;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72eb83;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    break;
  case 4:
    puStack_4c = (undefined *)0x820083;
    uStack_50 = 0;
    uStack_54 = 0x72eba2;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ebac;
    FUN_00765c50();
    pvStack_10 = (void *)0x4;
LAB_0072eaf0:
    puStack_8 = auStack_6c;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072ecbc;
  case 5:
    puStack_4c = (undefined *)0x820084;
    uStack_50 = 0;
    uStack_54 = 0x72ebcb;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ebd5;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    break;
  case 6:
    puStack_4c = (undefined *)0x820083;
    uStack_50 = 0;
    uStack_54 = 0x72ec3d;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ec47;
    FUN_00765c50();
    pvStack_10 = (void *)0x7;
    break;
  case 7:
    puStack_4c = (undefined *)0x8200ea;
    uStack_50 = 0;
    uStack_54 = 0x72ebf1;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ebfb;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x6;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072ecbc;
  case 8:
    puStack_4c = (undefined *)0x820063;
    uStack_50 = 0;
    uStack_54 = 0x72ec86;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ec90;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x8;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072ecbc;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8 = auStack_6c;
  FUN_00765c50(&uStack_50);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072ecbc:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072ed00 @ 0x0072ed00 ====

void FUN_0072ed00(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009916f2;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  puStack_4c = (undefined *)0x72ed25;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    puStack_4c = (undefined *)0x8200b1;
    uStack_50 = 0;
    uStack_54 = 0x72ed4e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ed58;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    break;
  case 1:
    puStack_4c = &DAT_0082000c;
    uStack_50 = 0;
    uStack_54 = 0x72ed77;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ed81;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x1;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072eeb4;
  case 2:
    puStack_4c = (undefined *)0x820057;
    uStack_50 = 0;
    uStack_54 = 0x72edc3;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72edcd;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
    break;
  case 3:
    puStack_4c = (undefined *)0x820058;
    uStack_50 = 0;
    uStack_54 = 0x72ede9;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72edf3;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x3;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072eeb4;
  case 4:
    puStack_4c = (undefined *)0x8200af;
    uStack_50 = 0;
    uStack_54 = 0x72ee35;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ee3f;
    FUN_00765c50();
    pvStack_10 = (void *)0x4;
    break;
  case 5:
    puStack_4c = (undefined *)0x820063;
    uStack_50 = 0;
    uStack_54 = 0x72ee7e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72ee88;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x5;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072eeb4;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8 = auStack_6c;
  FUN_00765c50(&uStack_50);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072eeb4:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072eef0 @ 0x0072eef0 ====

void FUN_0072eef0(void)

{
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_34 [36];
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991734;
  pvStack_c = ExceptionList;
  uStack_4c = 5;
  uStack_50 = 0x72ef16;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    uStack_50 = 0x72ef45;
    (**(code **)(*DAT_00b5aca8 + 0x80))();
    uStack_50 = 0x820010;
    uStack_54 = 0;
    uStack_58 = 0x72ef58;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72ef62;
    FUN_00765c50();
    puStack_8 = auStack_70;
    uStack_10 = 0;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    (**(code **)(*DAT_00b5aca8 + 0xc))(0);
    (**(code **)(*DAT_00b5acac + 0x10))();
    (**(code **)(*DAT_00b5aca8 + 0x2c))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    uStack_50 = 0x820067;
    uStack_54 = 0;
    uStack_58 = 0x72f093;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f09d;
    FUN_00765c50();
    uStack_10 = 3;
    break;
  case 2:
    uStack_50 = 0x82006f;
    uStack_54 = 0;
    uStack_58 = 0x72f034;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f03e;
    FUN_00765c50();
    puStack_8 = auStack_70;
    uStack_10 = 2;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffff2:
  case 0xfffffff3:
  case 0xfffffff4:
  case 0xfffffff5:
    uStack_50 = 0x8200e8;
    uStack_54 = 0;
    uStack_58 = 0x72f0bc;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f0c6;
    FUN_00765c50();
    puStack_8 = auStack_70;
    uStack_10 = 4;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072f007;
  case 0xfffffff6:
    uStack_50 = 0x820011;
    uStack_54 = 0;
    uStack_58 = 0x72f105;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f10f;
    FUN_00765c50();
    uStack_10 = 5;
    break;
  default:
    uStack_50 = 0x820012;
    uStack_54 = 0;
    uStack_58 = 0x72f12f;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_64 = 0x72f14c;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    uStack_10 = 6;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (uStack_58 < 0x10) {
      ExceptionList = (void *)0xf;
      return;
    }
    _free(pvStack_6c);
    return;
  case 0xfffffff8:
    uStack_50 = 0x820088;
    uStack_54 = 0;
    uStack_58 = 0x72efd5;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72efdf;
    FUN_00765c50();
    uStack_10 = 1;
  }
  puStack_8 = auStack_70;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072f007:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072f1e0 @ 0x0072f1e0 ====

void FUN_0072f1e0(void)

{
  int iVar1;
  void *_Memory;
  int unaff_retaddr;
  undefined4 uStack_78;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  uint uStack_3c;
  void *pvStack_38;
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099175e;
  puStack_c = ExceptionList;
  pvStack_50 = (void *)0x5;
  uStack_54 = 0x72f207;
  ExceptionList = &puStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (iVar1 == -0x20) {
    uStack_54 = 0x8200c0;
    uStack_58 = 0;
    uStack_5c = 0x72f32e;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    pvStack_6c = (void *)0x72f34c;
    FUN_00401660();
    uStack_14 = 2;
  }
  else if (iVar1 == -0x1f) {
    uStack_54 = 0x820044;
    uStack_58 = 0;
    uStack_5c = 0x72f2f5;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    pvStack_6c = (void *)0x72f313;
    FUN_00401660();
    uStack_14 = 1;
  }
  else {
    if (iVar1 != 0) {
      uStack_54 = 0x8200bf;
      uStack_58 = 0;
      uStack_5c = 0x72f237;
      uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0xffffffff;
      uStack_60 = 0;
      pvStack_38 = (void *)0xf;
      uStack_68 = 0x72f255;
      FUN_00401660();
      puStack_8 = auStack_74;
      uStack_78 = 0xffffffff;
      uStack_5c = 0xf;
      uStack_60 = 0;
      uStack_10 = 3;
      uStack_70 = 0;
      FUN_00401660(&pvStack_50,0);
      uStack_78 = 8;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (uStack_58 < 0x10) {
        ExceptionList = pvStack_38;
        return;
      }
      _Memory = pvStack_6c;
      goto LAB_0072f38b;
    }
    uStack_54 = *(undefined4 *)(unaff_retaddr + 0x18);
    uStack_58 = 0x72f2af;
    (**(code **)(*DAT_00b5ad1c + 0x90))();
    uStack_58 = 0x8200bd;
    uStack_5c = 0;
    uStack_60 = 0x72f2c0;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    pvStack_6c = (void *)0x72f2de;
    FUN_00401660();
    uStack_14 = 0;
  }
  puStack_c = (undefined1 *)&uStack_78;
  uStack_64 = 0;
  uStack_60 = 0xf;
  auStack_74[0] = 0;
  FUN_00401660(&pvStack_38,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
  _Memory = pvStack_50;
LAB_0072f38b:
  _free(_Memory);
  return;
}


// ==== FUN_0072f3b0 @ 0x0072f3b0 ====

void FUN_0072f3b0(void)

{
  int iVar1;
  int unaff_retaddr;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  uint uStack_3c;
  void *pvStack_38;
  undefined1 auStack_34 [4];
  uint uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991798;
  pvStack_c = ExceptionList;
  pvStack_50 = (void *)0x5;
  uStack_54 = 0x72f3d7;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (iVar1 < -300) {
    if (iVar1 == -0x12d) {
      uStack_54 = 0x820018;
      uStack_58 = 0;
      uStack_5c = 0x72f4f1;
      uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0xffffffff;
      uStack_60 = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      uStack_30 = uStack_30 & 0xffffff00;
      uStack_68 = 0x72f50f;
      FUN_00401660();
      uStack_10 = 2;
      goto LAB_0072f62b;
    }
    if (iVar1 != -0x12f) {
      if (iVar1 == -0x12e) {
        uStack_54 = 0x8200c4;
        uStack_58 = 0;
        uStack_5c = 0x72f414;
        uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_60 = 0x72f41e;
        FUN_00765c50();
        puStack_8 = auStack_74;
        uStack_10 = 4;
        FUN_00765c50(auStack_34);
        (**(code **)(*DAT_00b5ad0c + 0x28))(8);
        uStack_30 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
LAB_0072f52d:
      uStack_54 = 0x820012;
      uStack_58 = 0;
      uStack_5c = 0x72f53e;
      uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0xffffffff;
      uStack_60 = 0;
      pvStack_38 = (void *)0xf;
      uStack_68 = 0x72f55c;
      FUN_00401660();
      puStack_8 = auStack_74;
      uStack_5c = 0xf;
      uStack_60 = 0;
      uStack_10 = 5;
      uStack_70 = 0;
      FUN_00401660(&pvStack_50,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      uStack_30 = 0xffffffff;
      if (0xf < uStack_58) {
        _free(pvStack_6c);
        return;
      }
      uStack_58 = 0xf;
      uStack_5c = 0;
      pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
      goto LAB_0072f673;
    }
    uStack_54 = 0x8200c3;
    uStack_58 = 0;
    uStack_5c = 0x72f46f;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_68 = 0x72f48d;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    uStack_10 = 3;
    uStack_70 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  }
  else {
    if (iVar1 == -0x1f) {
      uStack_54 = 0x820044;
      uStack_58 = 0;
      uStack_5c = 0x72f605;
      uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0xffffffff;
      uStack_60 = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      uStack_30 = uStack_30 & 0xffffff00;
      uStack_68 = 0x72f623;
      FUN_00401660();
      uStack_10 = 1;
    }
    else {
      if (iVar1 != 0) goto LAB_0072f52d;
      uStack_54 = 0x8200be;
      uStack_58 = 0;
      uStack_5c = 0x72f5ce;
      uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0xffffffff;
      uStack_60 = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      uStack_30 = uStack_30 & 0xffffff00;
      uStack_68 = 0x72f5ec;
      FUN_00401660();
      uStack_10 = 0;
    }
LAB_0072f62b:
    puStack_8 = auStack_74;
    uStack_60 = 0;
    uStack_5c = 0xf;
    uStack_70 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  }
  if (0xf < uStack_3c) {
    uStack_30 = 0xffffffff;
    _free(pvStack_50);
    return;
  }
LAB_0072f673:
  uStack_30 = 0xffffffff;
  (**(code **)(*DAT_00b5aca8 + 0xa0))();
  ExceptionList = pvStack_38;
  return;
}


// ==== FUN_0072f6a0 @ 0x0072f6a0 ====

void FUN_0072f6a0(int param_1)

{
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  void *pvStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_30 [28];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009917ca;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x1c)) {
  case 0:
    uStack_50 = *(undefined4 *)(param_1 + 0x18);
    uStack_54 = (uint)*(ushort *)(param_1 + 0x14);
    uStack_58 = 0x72f6e6;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5aca8 + 0x4c))();
    ExceptionList = pvStack_14;
    return;
  case 1:
    uStack_50 = 0x820044;
    uStack_54 = 0;
    uStack_58 = 0x72f70c;
    ExceptionList = &pvStack_c;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f716;
    FUN_00765c50();
    pvStack_c = (void *)0x0;
    break;
  case 2:
    uStack_50 = 0x820018;
    uStack_54 = 0;
    uStack_58 = 0x72f768;
    ExceptionList = &pvStack_c;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f772;
    FUN_00765c50();
    puStack_4 = auStack_70;
    pvStack_c = (void *)0x1;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    uStack_50 = 0x8200c1;
    uStack_54 = 0;
    uStack_58 = 0x72f7c8;
    ExceptionList = &pvStack_c;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f7d2;
    FUN_00765c50();
    pvStack_c = (void *)0x2;
    break;
  case 4:
    uStack_50 = 0x8200c4;
    uStack_54 = 0;
    uStack_58 = 0x72f7f1;
    ExceptionList = &pvStack_c;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x72f7fb;
    FUN_00765c50();
    puStack_4 = auStack_70;
    pvStack_c = (void *)0x3;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072f73a;
  default:
    uStack_50 = 0x8200c9;
    uStack_54 = 0;
    uStack_58 = 0x72f83b;
    ExceptionList = &pvStack_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x72f859;
    FUN_00401660();
    puStack_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_c = (void *)0x4;
    uStack_6c = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (uStack_54 < 0x10) {
      ExceptionList = (void *)0xf;
      return;
    }
    _free(pvStack_68);
    return;
  }
  puStack_4 = auStack_70;
  FUN_00765c50(auStack_30);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072f73a:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072f8d0 @ 0x0072f8d0 ====

/* WARNING: Removing unreachable block (ram,0x0072fa4d) */

void FUN_0072f8d0(int param_1)

{
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_42 [2];
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009917fc;
  pvStack_c = ExceptionList;
  uStack_5c = 0x72f90e;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  switch(*(undefined1 *)(param_1 + 0x4a)) {
  case 0:
    uStack_5c = 0x72f940;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72f959;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
    break;
  case 1:
    uStack_5c = 0x72f974;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72f98d;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
    break;
  case 2:
    uStack_5c = 0x72f9a5;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72f9be;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
    break;
  case 3:
    uStack_5c = 0x72f9d6;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72f9ef;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
    break;
  default:
    goto switchD_0072f928_default;
  }
  local_4 = auStack_74;
  uStack_60 = 0;
  uStack_5c = 0xf;
  uStack_70 = 0;
  FUN_00401660(auStack_42 + -10,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  local_4 = (undefined1 *)((uint)local_4 & 0xffffff00);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
switchD_0072f928_default:
  (**(code **)(*DAT_00b5aca8 + 0x70))();
  ExceptionList = (void *)0xf;
  return;
}


// ==== FUN_0072fa80 @ 0x0072fa80 ====

void FUN_0072fa80(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099183e;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  uStack_4c = 0x72faa5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x10)) {
  case 0:
    uStack_4c = 0x820016;
    uStack_50 = 0;
    uStack_54 = 0x72facf;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fad9;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    goto LAB_0072fae1;
  case 1:
    uStack_4c = 0x820017;
    uStack_50 = 0;
    uStack_54 = 0x72fb1b;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fb25;
    FUN_00765c50();
    pvStack_10 = (void *)0x1;
    break;
  case 2:
    uStack_4c = 0x820018;
    uStack_50 = 0;
    uStack_54 = 0x72fb44;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fb4e;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
LAB_0072fae1:
    puStack_8 = auStack_6c;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072fc5b;
  case 3:
    uStack_4c = 0x820019;
    uStack_50 = 0;
    uStack_54 = 0x72fb6a;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fb74;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    break;
  case 4:
    uStack_4c = 0x82001a;
    uStack_50 = 0;
    uStack_54 = 0x72fb90;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fb9a;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x4;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072fc5b;
  case 5:
    uStack_4c = 0x820068;
    uStack_50 = 0;
    uStack_54 = 0x72fbdc;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fbe6;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    break;
  case 6:
    uStack_4c = 0x82001b;
    uStack_50 = 0;
    uStack_54 = 0x72fc25;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x72fc2f;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x6;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0072fc5b;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8 = auStack_6c;
  FUN_00765c50(&uStack_50);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0072fc5b:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0072fc90 @ 0x0072fc90 ====

void FUN_0072fc90(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint unaff_EBX;
  undefined4 uStack_94;
  undefined1 auStack_90 [4];
  undefined1 uStack_8c;
  undefined4 uStack_88;
  undefined1 *puStack_84;
  undefined1 *puStack_80;
  void *pvStack_7c;
  undefined4 uStack_78;
  undefined1 uStack_74;
  undefined1 uStack_70;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  char *pcStack_60;
  int iStack_5c;
  undefined1 *puStack_48;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined1 local_24;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991870;
  pvStack_c = ExceptionList;
  pcStack_60 = (char *)(param_1 + 0x10);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  pcVar2 = pcStack_60;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_5c = (int)pcVar2 - (param_1 + 0x11);
  uStack_64 = 0x72fce6;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  pcStack_60 = (char *)(param_1 + 0x31);
  local_4 = 0;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = 0;
  pcVar2 = pcStack_60;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_5c = (int)pcVar2 - (param_1 + 0x32);
  uStack_64 = 0x72fd16;
  FUN_00401740();
  local_4._0_1_ = 1;
  iStack_5c = 0x72fd26;
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 == '\0') {
    iStack_5c = 0x72fd98;
    iVar3 = (**(code **)(*DAT_00b5a6e4 + 8))();
    if (*(char *)(iVar3 + 10) == '\x01') {
      iStack_5c = 3;
      pvStack_7c = (void *)0xffffffff;
      puStack_80 = (undefined1 *)0x0;
      puStack_84 = local_44;
      pcStack_60 = (void *)0xf;
      uStack_64 = 0;
      uStack_74 = 0;
      uStack_88 = 0x72fdbf;
      FUN_00401660();
      puStack_48 = (undefined1 *)&uStack_94;
      pvStack_7c = (void *)0xf;
      puStack_80 = (undefined1 *)0x0;
      local_4._0_1_ = 3;
      auStack_90[0] = 0;
      FUN_00401660(local_28,0,0xffffffff);
      local_4 = CONCAT31(local_4._1_3_,1);
      (**(code **)(*DAT_00b5aca8 + 0xb0))();
    }
    else {
      uStack_78 = 0xffffffff;
      pvStack_7c = (void *)0x0;
      puStack_80 = local_44;
      iStack_5c = 0xf;
      pcStack_60 = (void *)0x0;
      uStack_70 = 0;
      puStack_84 = (undefined1 *)0x72fe1d;
      FUN_00401660();
      puStack_48 = auStack_90;
      uStack_94 = 0xffffffff;
      uStack_78 = 0xf;
      pvStack_7c = (void *)0x0;
      local_4._0_1_ = 4;
      uStack_8c = 0;
      FUN_00401660(local_28,0);
      local_4 = CONCAT31(local_4._1_3_,1);
      uStack_94 = 0x72fe57;
      (**(code **)(*DAT_00b5aca8 + 0x6c))();
    }
  }
  else {
    iStack_5c = 2;
    pvStack_7c = (void *)0xffffffff;
    puStack_80 = (undefined1 *)0x0;
    puStack_84 = local_44;
    pcStack_60 = (void *)0xf;
    uStack_64 = 0;
    uStack_74 = 0;
    uStack_88 = 0x72fd4b;
    FUN_00401660();
    puStack_48 = (undefined1 *)&uStack_94;
    pvStack_7c = (void *)0xf;
    puStack_80 = (undefined1 *)0x0;
    local_4._0_1_ = 2;
    auStack_90[0] = 0;
    FUN_00401660(local_28,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    (**(code **)(*DAT_00b5aca8 + 0xb0))();
  }
  if (0xf < uStack_68) {
    _free(pvStack_7c);
    return;
  }
  uStack_68 = 0xf;
  uStack_6c = 0;
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  if (unaff_EBX < 0x10) {
    ExceptionList = puStack_48;
    return;
  }
  _free(pcStack_60);
  return;
}


// ==== FUN_0072feb0 @ 0x0072feb0 ====

void FUN_0072feb0(void)

{
  int unaff_retaddr;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_50;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099189a;
  pvStack_c = ExceptionList;
  uStack_50 = 5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x18)) {
  case 0:
    (**(code **)(*DAT_00b5aca8 + 0x80))();
    uStack_58 = 0;
    uStack_5c = 0x72ff0f;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72ff2d;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x0;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    (**(code **)(*DAT_00b5aca8 + 0xc))(0);
    (**(code **)(*DAT_00b5acac + 0x10))();
    (**(code **)(*DAT_00b5aca8 + 0x2c))();
    (**(code **)(*DAT_00b5ac98 + 0x50))();
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_10;
      return;
    }
    pvStack_28 = pvStack_44;
    break;
  case 1:
    uStack_58 = 0;
    uStack_5c = 0x72ffb2;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x72ffd0;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x1;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_10;
      return;
    }
    pvStack_28 = pvStack_44;
    break;
  case 2:
    uStack_58 = 0;
    uStack_5c = 0x73002b;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x730049;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x2;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_10;
      return;
    }
    pvStack_28 = pvStack_44;
    break;
  case 3:
    uStack_58 = 0;
    uStack_5c = 0x73009d;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_68 = 0x7300bb;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x3;
    uStack_70 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    if (uStack_14 < 0x10) {
      ExceptionList = pvStack_10;
      return;
    }
    break;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  uStack_58 = 0x730100;
  _free(pvStack_28);
  return;
}


