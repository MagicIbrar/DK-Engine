// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x6a0000-0x6affff

// ==== FUN_006a0000 @ 0x006a0000 ====

void FUN_006a0000(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  (**(code **)(*piVar1 + 0x30))();
  FUN_0055a260(param_1);
  return;
}


// ==== FUN_006a0060 @ 0x006a0060 ====

undefined4 FUN_006a0060(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  cVar1 = *(char *)(iVar2 + 0x1e);
  piVar3 = (int *)(**(code **)(*param_1 + 0x48))();
  if (piVar3 != (int *)0x0) {
    switch((byte)(cVar1 + 1) - 1) {
    case 0:
      iVar2 = (**(code **)(*piVar3 + 4))();
      bVar4 = *(char *)(iVar2 + 0xa5) == '\0';
      break;
    case 1:
      iVar2 = (**(code **)(*piVar3 + 4))();
      bVar4 = *(char *)(iVar2 + 0xa6) == '\0';
      break;
    case 2:
      iVar2 = (**(code **)(*piVar3 + 4))();
      bVar4 = *(char *)(iVar2 + 0xa7) == '\0';
      break;
    case 3:
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (*(char *)(iVar2 + 0xa8) == '\0') {
        return 0;
      }
      return 1;
    default:
      goto switchD_006a008b_default;
    }
    if (!bVar4) {
      return 1;
    }
  }
switchD_006a008b_default:
  return 0;
}


// ==== FUN_006a00f0 @ 0x006a00f0 ====

undefined4 FUN_006a00f0(void)

{
  (**(code **)(*DAT_00b5b0f0 + 0x18))();
  return 1;
}


// ==== FUN_006a0100 @ 0x006a0100 ====

undefined4 FUN_006a0100(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 != 0) {
    if (param_1 != 4) {
      return 0;
    }
    iVar3 = (**(code **)(*DAT_00b5a78c + 0x48))();
    if ((iVar3 == 0) && (iVar3 = FUN_0057f270(), iVar3 == 0)) {
      return 1;
    }
    cVar1 = FUN_006a0060(iVar3);
    if (cVar1 != '\0') {
      FUN_0057f390(0x40000060);
      return 1;
    }
    FUN_0057f390(0x60b00000);
  }
  return 1;
}


// ==== FUN_006a0180 @ 0x006a0180 ====

void FUN_006a0180(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a78c + 0x1c))
            (CONCAT13((char)((uint)(in_ECX + 0xa8) >> 0x18),*(undefined3 *)(in_ECX + 0xa8)),param_1)
  ;
  return;
}


// ==== FUN_006a0200 @ 0x006a0200 ====

undefined4 FUN_006a0200(int param_1,undefined2 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2) {
    case 1:
      iVar1 = *DAT_00b5a78c;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x28))(uVar2);
      return 1;
    case 3:
      iVar1 = *DAT_00b5b114;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x34))(uVar2);
      return 1;
    case 4:
      (**(code **)(*DAT_00b5a78c + 4))((int3)in_ECX[0x2a]);
      return 1;
    case 5:
      uVar2 = thunk_FUN_00796f80(param_4);
      FUN_006a0180(uVar2);
      return 1;
    case 0xb:
      (**(code **)(*DAT_00b5b0f0 + 0x1c))();
    }
  }
  return 1;
}


// ==== FUN_006a0310 @ 0x006a0310 ====

undefined4 FUN_006a0310(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0xffff0000;
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 0x2c))();
    cVar1 = FUN_006a0060(param_1);
    if (((cVar1 != '\0') || (*(int *)(iVar2 + 8) == 0x100)) || (*(int *)(iVar2 + 8) == 0x102)) {
      uVar5 = 0xffffffff;
    }
  }
  iVar2 = (**(code **)(*DAT_00b5b0f4 + 4))();
  if ((iVar2 != 0) &&
     (puVar3 = (undefined4 *)(**(code **)(*DAT_00b5b0f0 + 0x2c))(), (int *)*puVar3 == param_1)) {
    return 0xaa333333;
  }
  iVar2 = (**(code **)(*DAT_00b5b0f4 + 8))();
  if ((iVar2 != 0) &&
     (puVar3 = (undefined4 *)(**(code **)(*DAT_00b5b0f4 + 8))(), (int *)*puVar3 == param_1)) {
    return 0xaa333333;
  }
  uVar4 = (**(code **)(*DAT_00b5b0f4 + 0x10))();
  if ((uVar4 != 0) && (uVar6 = 0, uVar4 != 0)) {
    do {
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5b0f4 + 0xc))(uVar6);
      if ((puVar3 != (undefined4 *)0x0) &&
         (((int *)*puVar3 != (int *)0x0 && ((int *)*puVar3 == param_1)))) {
        return 0xaa333333;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
  }
  return uVar5;
}


// ==== FUN_006a03e0 @ 0x006a03e0 ====

void FUN_006a03e0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 uVar4;
  void *pvStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  FUN_005811f0();
  cVar1 = (**(code **)(*DAT_00b5b0f0 + 0x44))();
  if (cVar1 == '\x01') {
    cVar1 = (**(code **)(*DAT_00b5b0f0 + 0x48))();
    if (cVar1 == '\0') {
      uVar4 = 100;
    }
    else {
      uVar4 = 0x65;
    }
    FUN_004dd240(0x16,uVar4,0,0,0);
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    FUN_00401740(s_pan_effect_009de6fc,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      uVar4 = (**(code **)(*piVar2 + 4))();
      *puVar3 = &PTR_FUN_009bba08;
      puVar3[1] = uVar4;
      puVar3[3] = 1;
      puVar3[5] = 0;
      *(undefined1 *)(puVar3 + 6) = 0;
    }
    *(undefined1 *)((int)puVar3 + 0x19) = 1;
    puVar3[2] = 0x80014;
    puVar3[3] = unaff_ESI;
    puVar3[4] = 1000;
    *(undefined1 *)(puVar3 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar3);
    (**(code **)*puVar3)(1);
    (**(code **)(*DAT_00b5b0f0 + 0x40))(0);
  }
  return;
}


// ==== FUN_006a0510 @ 0x006a0510 ====

void FUN_006a0510(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  undefined1 auStack_32 [2];
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_upgrade_item_009de718,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  piVar1 = (int *)(**(code **)(*DAT_00b5b0f4 + 4))();
  if (piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0(auStack_32 + -6,&uStack_30);
    FUN_00580870(0,1);
    pcVar4 = s_pan_upgradeItem_bg_009de728;
  }
  else {
    if (*piVar1 != 0) {
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401740(s_pan_upgradeItem_bg_009de750,0x12);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(1);
      }
      if (uStack_c < 0x10) {
        (**(code **)(*(int *)*piVar1 + 0x1c))();
        iVar3 = (**(code **)(*(int *)*piVar1 + 0x2c))();
        uStack_28 = (uint)*(byte *)(iVar3 + 0x31);
        uStack_2c = (uint)*(byte *)(iVar3 + 0x30);
        FUN_005802c0(auStack_32 + -6,&uStack_2c);
        FUN_00580870(*piVar1,1);
        return;
      }
      _free(pvStack_20);
      return;
    }
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0(auStack_32 + -6,&uStack_30);
    FUN_00580870(0,1);
    pcVar4 = s_pan_upgradeItem_bg_009de73c;
  }
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  uStack_c = 0;
  local_8 = 0xf;
  FUN_00401740(pcVar4,0x12);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006a06e0 @ 0x006a06e0 ====

void FUN_006a06e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_32 [2];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_stone_special_socket_009de764,0x14);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      piVar1 = (int *)(**(code **)(*DAT_00b5b0f0 + 0x30))();
      if (piVar1 != (int *)0x0) {
        if (*piVar1 == 0) {
          uStack_30 = 1;
          uStack_2c = 1;
          FUN_005802c0(auStack_32 + -6,&uStack_30);
          FUN_00580870(0,1);
          FUN_00401830(s_pan_special_bg_009de78c);
          piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x24))(0);
          }
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00401830(s_pan_special_bg_009de79c);
        piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x24))(1);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uStack_30 = 1;
      uStack_2c = 1;
      FUN_005802c0(auStack_32 + -6,&uStack_30);
      FUN_00580870(0,1);
      FUN_00401830(s_pan_special_bg_009de77c);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(0);
      }
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006a08c0 @ 0x006a08c0 ====

void FUN_006a08c0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint in_ECX;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iStack_a0;
  uint local_9c [2];
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  uint uStack_80;
  uint uStack_7c;
  undefined1 local_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint auStack_60 [2];
  void *pvStack_58;
  undefined4 uStack_48;
  uint auStack_44 [2];
  void *pvStack_3c;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar5 = 0;
  local_9c[0] = in_ECX;
  do {
    FUN_00401740(s_stone_socket__d_009de7ac,0xf);
    puVar6 = local_78;
    uVar1 = FUN_00404230(puVar6);
    piVar2 = (int *)(**(code **)(**(int **)(local_9c[0] + 4) + 0x34))(uVar1);
    if (0xf < auStack_60[0]) {
      _free(pvStack_74);
      return;
    }
    auStack_60[0] = 0xf;
    uStack_64 = 0;
    pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 != 0) {
        piVar2 = (int *)(**(code **)(*DAT_00b5b0f0 + 0x34))(uVar5);
        if (piVar2 == (int *)0x0) {
          local_9c[0] = 0;
          uStack_8c = 1;
          uStack_88 = 1;
          FUN_005802c0(local_9c,&uStack_8c);
          FUN_00580870(0,1);
          uVar7 = 0;
          FUN_00401740(s_pan_socket__d_bg_009de7bc,0x10);
          uVar1 = FUN_00404230(auStack_44,puVar6,uVar7);
          piVar2 = (int *)(**(code **)(**(int **)(iStack_a0 + 4) + 0x34))(uVar1);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0x24))(0);
          }
          if ((void *)0xf < apvStack_28[0]) {
            _free(pvStack_3c);
            return;
          }
          apvStack_28[0] = (void *)0xf;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
        }
        else if (*piVar2 == 0) {
          local_9c[0] = 0;
          uStack_94 = 1;
          uStack_90 = 1;
          FUN_005802c0(local_9c,&uStack_94);
          FUN_00580870(0,1);
          uVar7 = 0;
          FUN_00401740(s_pan_socket__d_bg_009de7d0,0x10);
          uVar1 = FUN_00404230(auStack_60,puVar6,uVar7);
          piVar2 = (int *)(**(code **)(**(int **)(iStack_a0 + 4) + 0x34))(uVar1);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0x24))(0);
          }
          if (0xf < auStack_44[0]) {
            _free(pvStack_58);
            return;
          }
          auStack_44[0] = 0xf;
          uStack_48 = 0;
          pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
        }
        else {
          uVar7 = 0;
          FUN_00401740(s_pan_socket__d_bg_009de7e4,0x10);
          uVar1 = FUN_00404230(apvStack_28,puVar6,uVar7);
          piVar4 = (int *)(**(code **)(**(int **)(iStack_a0 + 4) + 0x34))(uVar1);
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 0x24))(1);
          }
          if (0xf < uStack_14) {
            _free(apvStack_28[0]);
            return;
          }
          uStack_14 = 0xf;
          uStack_18 = 0;
          apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
          local_9c[0] = (**(code **)(*(int *)*piVar2 + 0x1c))();
          local_9c[0] = local_9c[0] & 0xffff;
          iVar3 = (**(code **)(*(int *)*piVar2 + 0x2c))();
          uStack_7c = (uint)*(byte *)(iVar3 + 0x31);
          uStack_80 = (uint)*(byte *)(iVar3 + 0x30);
          FUN_005802c0(&uStack_94,&uStack_80);
          FUN_00580870(*piVar2,1);
        }
      }
    }
    uVar5 = uVar5 + 1;
    if (4 < uVar5) {
      return;
    }
  } while( true );
}


// ==== FUN_006a0b80 @ 0x006a0b80 ====

void FUN_006a0b80(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5b0f0 + 0x28))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_cost_009de7f8,8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0((int)register0x00000010 + -0x20,uVar1);
  FUN_0055a260(uVar1);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_006a0c30 @ 0x006a0c30 ====

void FUN_006a0c30(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  (**(code **)(*DAT_00b5b0f4 + 0x2c))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_percent_009de804,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00401740(s__d____009de810,5);
  uVar2 = FUN_00404230((int)register0x00000010 + -0x20);
  FUN_0055a260(uVar2);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_006a0d00 @ 0x006a0d00 ====

void FUN_006a0d00(byte param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  bVar1 = (**(code **)(*DAT_00b5ad1c + 0x7c))();
  uStack_20 = (void *)CONCAT13(bVar1,(undefined3)uStack_20);
  if ((param_1 < bVar1) &&
     (uStack_20 = (void *)(CONCAT13(bVar1,(undefined3)uStack_20) & 0xff00ffff), bVar1 != 0)) {
    do {
      FUN_00401740(s_btn_changebag__d_009de840,0x10);
      uVar2 = FUN_00404230(&pvStack_1c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_00558730(uStack_20._2_1_ == param_1);
      }
      bVar1 = uStack_20._2_1_ + 1;
      uStack_20._0_3_ = CONCAT12(bVar1,(undefined2)uStack_20);
    } while (bVar1 < uStack_20._3_1_);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_changebag_2_009de854,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(2 < (byte)((uint)unaff_EBX >> 0x18));
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_btn_changebag_3_009de864,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_20);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(3 < (byte)((uint)unaff_EBP >> 0x18));
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(uStack_20);
  return;
}


// ==== FUN_006a0e80 @ 0x006a0e80 ====

void FUN_006a0e80(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar2 = 0;
  iVar6 = 0;
  piVar7 = (int *)(in_ECX + 0x50);
  do {
    if ((uVar2 < 0xd) || (0x12 < uVar2)) {
      iVar3 = (**(code **)(*DAT_00b5a78c + 0x44))(iVar6);
      *piVar7 = iVar3;
      FUN_00401740(s_suititem__d_009de8a0,0xb);
      uVar4 = FUN_00404230(apvStack_28);
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
      if (0xf < uStack_14) {
        _free(apvStack_28[0]);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
      (**(code **)(*piVar5 + 0x30))();
      if ((int *)*piVar7 == (int *)0x0) {
        auStack_3c[1] = 0;
        uStack_2c = 1;
        apvStack_28[0] = (void *)0x1;
        FUN_005802c0(auStack_3c + 1,&uStack_2c);
        FUN_00580870(0,1);
      }
      else {
        auStack_3c[0] = (**(code **)(*(int *)*piVar7 + 0x1c))();
        auStack_3c[0] = auStack_3c[0] & 0xffff;
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x2c))();
        uStack_30 = (uint)*(byte *)(iVar3 + 0x31);
        auStack_3c[2] = (uint)*(byte *)(iVar3 + 0x30);
        FUN_005802c0(auStack_3c,auStack_3c + 2);
        FUN_00580870(*piVar7,1);
        FUN_0057f430(0xffffffff);
      }
    }
    uVar2 = uVar2 + 1;
    iVar6 = iVar6 + 1;
    piVar7 = piVar7 + 1;
  } while (uVar2 < 0x15);
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x54))();
  *(undefined1 *)(in_ECX + 0xac) = uVar1;
  return;
}


// ==== FUN_006a0fe0 @ 0x006a0fe0 ====

undefined4 FUN_006a0fe0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined2 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_slotbag_009de9bc,7);
  if (iVar2 != 0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x2c))();
    uStack_20 = CONCAT11(uStack_20._1_1_,*(undefined1 *)(in_ECX + 0xab));
    uVar1 = FUN_00802534();
    uStack_20 = CONCAT11(uVar1,(undefined1)uStack_20);
    uVar1 = FUN_00802534();
    (**(code **)(*DAT_00b5a78c + 4))(CONCAT12(uVar1,uStack_20));
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_Call_________IINVEN__IUIHANDLER__009de9c4,0x3c);
    FUN_00796d50(&uStack_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_006a1150 @ 0x006a1150 ====

void FUN_006a1150(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009dea1c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 4;
  puVar2 = in_ECX + 0x15;
  do {
    if ((void *)puVar2[-4] != (void *)0x0) {
      _free((void *)puVar2[-4]);
      return;
    }
    iVar1 = iVar1 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2 = puVar2 + -4;
  } while (iVar1 != 0);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006a11a0 @ 0x006a11a0 ====

void FUN_006a11a0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBP;
  undefined4 uStack_a8;
  undefined1 uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  undefined4 uStack_84;
  uint uStack_80;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined1 auStack_3c [16];
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  uStack_90 = 0xf;
  pvStack_94 = (void *)0x0;
  uStack_a4 = 0;
  FUN_00401740(s_lbl_money_009de874,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_a8);
  if (0xf < pvStack_94) {
    _free(uStack_a8);
    return;
  }
  pvStack_94 = (void *)0xf;
  uStack_98 = 0;
  uStack_a8 = (void *)((uint)uStack_a8 & 0xffffff00);
  (**(code **)(*DAT_00b5ad20 + 0x48))(auStack_3c,uVar1);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0(auStack_28,uVar1,s_<_color>_009de880);
  uVar1 = FUN_004022a0(auStack_7c,s_<color__009de890,auStack_44,&DAT_009de88c,uVar1);
  uVar1 = FUN_00402220(&uStack_98,uVar1);
  uVar1 = FUN_00405bd0(auStack_60,uVar1);
  uVar1 = FUN_00402220(auStack_7c + -0x38,uVar1);
  FUN_0055a260(uVar1);
  if (0xf < uStack_9c) {
    _free(unaff_EBP);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006a1360 @ 0x006a1360 ====

void FUN_006a1360(void)

{
  byte bVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_EBX;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uStack_2c;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  void *local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  puVar4 = (undefined4 *)(in_ECX + 0x14);
  iVar3 = 4;
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      _free((void *)*puVar4);
      return;
    }
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4 = puVar4 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_24);
  uStack_14 = 0xffffffff;
  if (local_24 != (void *)0x0) {
    uStack_1c = (uint)bStack_27;
    uStack_18 = (uint)bStack_26;
    pvStack_20 = local_24;
    uStack_14 = FUN_006a0310(local_24);
    iVar5 = (bStack_28 + 1) * 0x10 + in_ECX;
    iVar3 = *(int *)(iVar5 + 4);
    if ((iVar3 == 0) ||
       ((uint)(*(int *)(iVar5 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar3 >> 4))) {
      FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&pvStack_20);
    }
    else {
      iVar3 = *(int *)(iVar5 + 8);
      FUN_00680b80(iVar3,1,&pvStack_20,iVar5,unaff_EBX);
      *(int *)(iVar5 + 8) = iVar3 + 0x10;
    }
    (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    while (uStack_2c != (void *)0x0) {
      uStack_1c = unaff_EBX >> 8 & 0xff;
      uStack_18 = unaff_EBX >> 0x10 & 0xff;
      pvStack_20 = uStack_2c;
      uStack_14 = FUN_006a0310(uStack_2c);
      iVar5 = ((unaff_EBX & 0xff) + 1) * 0x10 + in_ECX;
      iVar3 = *(int *)(iVar5 + 4);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar3 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&pvStack_20);
      }
      else {
        iVar3 = *(int *)(iVar5 + 8);
        FUN_00680b80(iVar3,1,&pvStack_20,iVar5,unaff_EBX);
        *(int *)(iVar5 + 8) = iVar3 + 0x10;
      }
      (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    }
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotbag_009de898,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    (**(code **)(*piVar2 + 0x30))();
    bVar1 = (**(code **)(*DAT_00b5a78c + 0x50))();
    *(byte *)(in_ECX + 0xab) = bVar1;
    FUN_005817e0((bVar1 + 1) * 0x10 + in_ECX,1);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006a1590 @ 0x006a1590 ====

/* WARNING: Removing unreachable block (ram,0x006a1617) */

void FUN_006a1590(undefined4 param_1,byte *param_2,ushort param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  puVar2 = operator_new(0x58);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b5340;
    puVar2[6] = 0;
    puVar2[7] = 0xf;
    *(undefined1 *)(puVar2 + 2) = 0;
    puVar2[0xe] = 0xf;
    puVar2[0xd] = 0;
    *(undefined1 *)(puVar2 + 9) = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0x12] = 0;
    *(undefined2 *)(puVar2 + 0x13) = 0;
    puVar2[0x14] = 0;
    puVar2[0x15] = 10000;
  }
  uVar3 = (**(code **)(*in_ECX + 0x14))();
  puVar2[0x14] = uVar3;
  FUN_00401660(param_1,0,0xffffffff);
  bVar1 = *param_2;
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  puVar2[0x15] = 2000;
  *(ushort *)(puVar2 + 0x13) = (ushort)bVar1 << 8 | param_3;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_006a1640 @ 0x006a1640 ====

void FUN_006a1640(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  void *local_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_006a11a0();
  FUN_006a1360();
  FUN_006a0e80();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009de818,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0xac));
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_EBX);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_tab_chang_weapon_009de82c,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (uStack_c < 0x10) {
    FUN_006a0d00(*(undefined1 *)(in_ECX + 0xab));
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006a1730 @ 0x006a1730 ====

void FUN_006a1730(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_006a0510();
  FUN_006a08c0();
  FUN_006a06e0();
  FUN_006a0c30();
  FUN_006a0b80();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_btn_strength_009de708,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  cVar1 = (**(code **)(*DAT_00b5b0f0 + 0x24))();
  if (cVar1 == '\0') {
    (**(code **)(*piVar2 + 0x44))(0);
    FUN_006a1640();
    return;
  }
  (**(code **)(*piVar2 + 0x44))(1);
  FUN_006a1640();
  return;
}


// ==== FUN_006a17f0 @ 0x006a17f0 ====

undefined4 FUN_006a17f0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 uVar7;
  int *in_ECX;
  char *pcVar8;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_24 [4];
  uint local_20;
  undefined1 local_1c [28];
  
  iVar2 = param_2;
  if (param_1 == 1) {
    if (param_3 != 1) {
      return 0;
    }
    iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_strength_009de8ac,0xc);
    if (iVar6 != 0) {
      cVar3 = FUN_004036a0(iVar2,s_btn_exit_009de8d4);
      if (cVar3 != '\0') {
        (**(code **)(*in_ECX + 0x10))();
        return 1;
      }
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      FUN_00404fb0(iVar2,0x5f,local_48);
      pcVar8 = s_changebag_009de8e0;
      uVar7 = FUN_00405d30(1);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(2);
        uVar7 = thunk_FUN_00796f50(uVar7);
        *(char *)((int)in_ECX + 0xab) = (char)uVar7;
        (**(code **)(*DAT_00b5a78c + 0x30))(uVar7);
        FUN_006a1730();
        FUN_00406250();
        return 1;
      }
LAB_006a1d52:
      FUN_00406250();
      return 0;
    }
    param_3 = CONCAT31(param_3._1_3_,0x20);
    FUN_00401830(s_ui_upgradeprogress_txt_009de8bc);
    FUN_006a1590(local_38,&param_3,0xb);
    if (0xf < local_20) {
      _free(local_34);
      return extraout_EAX;
    }
  }
  else if (param_1 == 10) {
    if (param_3 != 1) {
      return 0;
    }
    cVar3 = FUN_006a0fe0(param_2,param_4);
    if (cVar3 == '\0') {
      return 0;
    }
  }
  else {
    if (param_1 != 0xf) {
      if (((param_1 == 0xb) && (param_3 == 1)) &&
         ((cVar3 = FUN_004036a0(param_2,s_tab_chang_weapon_009de994), cVar3 != '\0' ||
          (cVar3 = FUN_004036a0(iVar2,s_tab_chang_shield_009de9a8), cVar3 != '\0')))) {
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280025);
        FUN_00765c50(uVar7);
        iVar2 = *DAT_00b5ad0c;
        FUN_00765c50(auStack_24);
        (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 0;
    }
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    FUN_00404fb0(param_2,0x5f,local_48);
    if (param_3 == 1) {
      pcVar8 = s_upgrade_009de8ec;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        (**(code **)(*DAT_00b5b0f4 + 0x20))();
        FUN_006a1730();
        FUN_00406250();
        return 1;
      }
      pcVar8 = s_stone_009de8f4;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 == '\0') {
        pcVar8 = s_suititem_009de90c;
        uVar7 = FUN_00405d30(0);
        cVar3 = FUN_004036a0(uVar7,pcVar8);
        if (cVar3 != '\0') {
          uVar7 = FUN_00405d30(1);
          uVar4 = thunk_FUN_00796f50(uVar7);
          (**(code **)(*DAT_00b5a78c + 0xc))(uVar4);
          FUN_00406250();
          return 1;
        }
        pcVar8 = s_slotbag_009de918;
        uVar7 = FUN_00405d30(0);
        cVar3 = FUN_004036a0(uVar7,pcVar8);
        if (cVar3 != '\0') {
          uVar7 = FUN_00405d30(1);
          uVar4 = thunk_FUN_00796f50(uVar7);
          uVar7 = FUN_00405d30(2);
          uVar5 = thunk_FUN_00796f50(uVar7);
          piVar1 = in_ECX + 0x2a;
          *(undefined1 *)piVar1 = *(undefined1 *)((int)in_ECX + 0xab);
          *(undefined1 *)((int)in_ECX + 0xa9) = uVar4;
          *(undefined1 *)((int)in_ECX + 0xaa) = uVar5;
          cVar3 = (**(code **)(*DAT_00b5a78c + 0x34))(piVar1);
          if (cVar3 == '\0') {
            (**(code **)(*DAT_00b5a78c + 4))((int3)*piVar1);
            FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009de930);
            FUN_00796d50(&local_40);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          param_2 = CONCAT31(param_2._1_3_,3);
          FUN_00401830(s_ui_socket_txt_009de920);
          FUN_006a1590(&local_3c,&param_2,4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        goto LAB_006a1d52;
      }
      pcVar8 = s_special_009de8fc;
      uVar7 = FUN_00405d30(1);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        (**(code **)(*DAT_00b5b0f4 + 0x24))();
        FUN_006a1730();
        FUN_00406250();
        return 1;
      }
      pcVar8 = s_socket_009de904;
      uVar7 = FUN_00405d30(1);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(2);
        uVar7 = thunk_FUN_00796fb0(uVar7);
        (**(code **)(*DAT_00b5b0f4 + 0x28))(uVar7);
        FUN_006a1730();
        FUN_00406250();
        return 1;
      }
    }
    else if (param_3 == 2) {
      pcVar8 = s_slotbag_009de970;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        local_34 = (void *)0x0;
        local_30 = 0;
        local_2c = 0;
        FUN_00404fb0(iVar2,0x5f,local_38);
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        uVar7 = FUN_00405d30(2);
        uVar5 = thunk_FUN_00796f50(uVar7);
        param_3._0_2_ = CONCAT11(uVar4,*(undefined1 *)((int)in_ECX + 0xab));
        (**(code **)(*DAT_00b5a78c + 8))(CONCAT12(uVar5,(undefined2)param_3));
        FUN_00406250();
      }
    }
    else if (param_3 == 0xd) {
      pcVar8 = s_slotbag_009de978;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        param_3 = CONCAT31(param_3._1_3_,4);
        FUN_00401830(s_ui_stackcount_txt_009de980);
        FUN_006a1590(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else if (((param_3 != 4) && (param_3 != 5)) ||
            (cVar3 = FUN_006a0100(iVar2,param_3,param_4), cVar3 == '\0')) goto LAB_006a1d52;
    FUN_00406250();
  }
  return 1;
}


// ==== FUN_006a1e00 @ 0x006a1e00 ====

void FUN_006a1e00(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStack_38 [4];
  undefined4 local_1c;
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_itemaddsocketwnd_txt_009de6c8,0x20);
  iVar1 = FUN_00410500(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_slotbag_009de6ec,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0x10);
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  (**(code **)(*piVar2 + 0x30))();
  FUN_00580be0(1);
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  FUN_00401740(s_slotbag_009de6f4,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0xc);
  if (local_18 < 0x10) {
    local_18 = (void *)0xf;
    local_1c = 0;
    uVar3 = (**(code **)(*piVar2 + 0x30))();
    *(undefined4 *)(in_ECX + 0xa4) = uVar3;
    FUN_006a1730();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_006a1f30 @ 0x006a1f30 ====

uint FUN_006a1f30(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = (**(code **)(*in_ECX + 0x30))(param_1);
  }
  else if (uVar1 == 0x70370002) {
    uVar1 = FUN_006a1730();
    return uVar1 & 0xffffff00;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a1f70 @ 0x006a1f70 ====

void FUN_006a1f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dea1c;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  *(undefined1 *)((int)in_ECX + 0xa9) = 0;
  *(undefined1 *)((int)in_ECX + 0xaa) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  *(undefined1 *)((int)in_ECX + 0xab) = 0;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  *(undefined1 *)((int)in_ECX + 0xa9) = 0;
  *(undefined1 *)((int)in_ECX + 0xaa) = 0;
  FUN_006a1e00();
  return;
}


// ==== FUN_006a1ff0 @ 0x006a1ff0 ====

undefined4 FUN_006a1ff0(void)

{
  return 0x3c;
}


// ==== FUN_006a2000 @ 0x006a2000 ====

void FUN_006a2000(byte param_1)

{
  void *in_ECX;
  
  FUN_006a1150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a2020 @ 0x006a2020 ====

void FUN_006a2020(void)

{
  return;
}


// ==== FUN_006a2030 @ 0x006a2030 ====

undefined1 FUN_006a2030(void)

{
  return 0;
}


// ==== FUN_006a2050 @ 0x006a2050 ====

void FUN_006a2050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009deae8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006a2070 @ 0x006a2070 ====

uint FUN_006a2070(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a2080 @ 0x006a2080 ====

uint FUN_006a2080(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 1) {
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (uVar2 == 2) goto LAB_006a20c5;
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    bVar3 = uVar2 == 3;
  }
  else {
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    bVar3 = uVar2 == 2;
  }
  if (!bVar3) {
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
  }
LAB_006a20c5:
  return uVar2 & 0xffffff00;
}


// ==== FUN_006a20d0 @ 0x006a20d0 ====

uint FUN_006a20d0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0) {
    uVar1 = FUN_006a2080(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a2100 @ 0x006a2100 ====

/* WARNING: Removing unreachable block (ram,0x006a22cf) */
/* WARNING: Removing unreachable block (ram,0x006a2253) */
/* WARNING: Removing unreachable block (ram,0x006a21e4) */

void FUN_006a2100(void)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int in_ECX;
  undefined1 auStack_9e [18];
  undefined1 auStack_8c [4];
  void *pvStack_88;
  undefined4 uStack_78;
  uint uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  undefined1 uStack_60;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_40;
  undefined4 uStack_3c;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  
  uVar3 = (**(code **)(*DAT_00b5ac1c + 8))();
  FUN_006a2450(uVar3);
  iVar4 = (**(code **)(*DAT_00b5ac80 + 8))(uStack_3c);
  (**(code **)(*DAT_00b5ac1c + 0xc))();
  uStack_68 = (**(code **)(*DAT_00b5ac78 + 8))(auStack_9e + -6);
  uStack_4c = 0xf;
  uStack_50 = 0;
  uStack_60 = 0;
  FUN_00401740(s_lbl_server_009deaac,10);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_64);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return;
  }
  uStack_50 = 0xf;
  uStack_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  if (piVar5 == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009deab8,0x12);
    FUN_00406880(auStack_9e + -10);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uStack_70 = (**(code **)(*piVar5 + 0x30))();
  uStack_74 = 0xf;
  uStack_78 = 0;
  pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
  if (iVar4 == 0) {
    FUN_00401740(&DAT_009deacb,0);
  }
  else {
    pcVar6 = (char *)(iVar4 + 1);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iVar4 + 1),(int)pcVar6 - (iVar4 + 2));
    FUN_00401660(auStack_9e + -10,0,0xffffffff);
  }
  if (iStack_6c != 0) {
    FUN_004020e0(&DAT_009deacc,3);
    pcVar6 = (char *)(iStack_6c + 10);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iStack_6c + 10),(int)pcVar6 - (iStack_6c + 0xb));
    FUN_00401ff0(auStack_9e + -10,0,0xffffffff);
  }
  FUN_0055a260(auStack_8c);
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uStack_74 = 0xf;
  uStack_78 = 0;
  pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006a2360 @ 0x006a2360 ====

void FUN_006a2360(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_servernamewnd_txt_009dea8c,0x1d);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006a2100();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006a23e0 @ 0x006a23e0 ====

void FUN_006a23e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009deae8;
  FUN_006a2360();
  return;
}


// ==== FUN_006a2400 @ 0x006a2400 ====

undefined4 FUN_006a2400(void)

{
  return 0x39;
}


// ==== FUN_006a2410 @ 0x006a2410 ====

void FUN_006a2410(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009deae8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a2450 @ 0x006a2450 ====

void FUN_006a2450(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined1 *)(in_ECX + 1) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)((int)in_ECX + 5) = *(undefined1 *)((int)param_1 + 5);
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1 + 2,0,0xffffffff);
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  FUN_00401660(param_1 + 9,0,0xffffffff);
  return;
}


// ==== FUN_006a24b0 @ 0x006a24b0 ====

void FUN_006a24b0(void)

{
  return;
}


// ==== FUN_006a24c0 @ 0x006a24c0 ====

undefined1 FUN_006a24c0(void)

{
  return 0;
}


// ==== FUN_006a24e0 @ 0x006a24e0 ====

void FUN_006a24e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009debe0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006a2500 @ 0x006a2500 ====

uint FUN_006a2500(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 1) {
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (uVar2 == 2) goto LAB_006a2545;
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    bVar3 = uVar2 == 3;
  }
  else {
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    bVar3 = uVar2 == 2;
  }
  if (!bVar3) {
    uVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
  }
LAB_006a2545:
  return uVar2 & 0xffffff00;
}


// ==== FUN_006a2550 @ 0x006a2550 ====

uint FUN_006a2550(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0) {
    uVar1 = FUN_006a2500(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a2580 @ 0x006a2580 ====

void FUN_006a2580(void)

{
  uint uVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  void *pvVar6;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_20;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uVar1 = *(uint *)(in_ECX + 8);
  if (uVar1 < 0x33) {
    pvVar6 = (void *)0x10;
  }
  else if (uVar1 < 0x65) {
    pvVar6 = (void *)0xf;
  }
  else if (uVar1 < 0xc9) {
    pvVar6 = (void *)0xe;
  }
  else if (uVar1 < 0x191) {
    pvVar6 = (void *)0xd;
  }
  else {
    pvVar6 = (void *)(0xc - (uint)(800 < uVar1));
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740(s_pan_reception_009deb74,0xd);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 == 0) {
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c._1_3_ << 8);
      FUN_00401740(s_pPanel____NULL_009deb98,0xe);
      FUN_00406880(&pvStack_20);
      if (local_8 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(local_1c);
      return;
    }
    uStack_28 = *(void **)(iVar4 + 0x90);
    uStack_24 = *(uint *)(iVar4 + 0x94);
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c._1_3_ << 8);
    FUN_00401740(s_Pantheon_009deba8,8);
    (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_20);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uStack_28 = pvVar6;
    FUN_00587d40((int)register0x00000010 + -0x30);
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = uStack_24 & 0xffffff00;
    FUN_00401740(s_lbl_ping_009debb4,8);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_28);
    if (0xf < uStack_14) {
      _free(uStack_28);
      return;
    }
    uStack_14 = 0xf;
    local_18 = 0;
    uStack_28 = (void *)((uint)uStack_28 & 0xffffff00);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x30))();
      FUN_00401740(s__u_ms_009debc0,5);
      uVar5 = FUN_00404230((int)register0x00000010 + -0x2c);
      FUN_0055a260(uVar5);
      if (0xf < uStack_14) {
        _free(uStack_28);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006a27a0 @ 0x006a27a0 ====

void FUN_006a27a0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a6ac + 0x10))();
  if (*(int *)(in_ECX + 8) != *piVar1) {
    *(int *)(in_ECX + 8) = *piVar1;
    FUN_006a2580();
  }
  return;
}


// ==== FUN_006a27d0 @ 0x006a27d0 ====

void FUN_006a27d0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_receptionwnd_txt_009deb54,0x1c);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006a2580();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006a2850 @ 0x006a2850 ====

uint FUN_006a2850(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    puVar2 = (uint *)(**(code **)(*DAT_00b5a6ac + 0x10))();
    uVar1 = *puVar2;
    if (*(uint *)(in_ECX + 8) != uVar1) {
      *(uint *)(in_ECX + 8) = uVar1;
      uVar1 = FUN_006a2580();
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a2890 @ 0x006a2890 ====

void FUN_006a2890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009debe0;
  in_ECX[2] = 0;
  FUN_006a27d0();
  return;
}


// ==== FUN_006a28b0 @ 0x006a28b0 ====

undefined4 FUN_006a28b0(void)

{
  return 0x38;
}


// ==== FUN_006a28c0 @ 0x006a28c0 ====

void FUN_006a28c0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009debe0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a2900 @ 0x006a2900 ====

void FUN_006a2900(void)

{
  return;
}


// ==== FUN_006a2a10 @ 0x006a2a10 ====

undefined4 FUN_006a2a10(void)

{
  (**(code **)(*DAT_00b5b0fc + 0x18))();
  return 1;
}


// ==== FUN_006a2a20 @ 0x006a2a20 ====

undefined4 FUN_006a2a20(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 != 0) {
    if (param_1 != 4) {
      return 0;
    }
    iVar3 = (**(code **)(*DAT_00b5a78c + 0x48))();
    if ((iVar3 == 0) && (iVar3 = FUN_0057f270(), iVar3 == 0)) {
      return 1;
    }
    cVar1 = (**(code **)(*DAT_00b5ad20 + 0x34))(iVar3);
    if (cVar1 != '\0') {
      FUN_0057f390(0x40000060);
      return 1;
    }
    FUN_0057f390(0x60b00000);
  }
  return 1;
}


// ==== FUN_006a2aa0 @ 0x006a2aa0 ====

void FUN_006a2aa0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a78c + 0x1c))
            (CONCAT13((char)((uint)(in_ECX + 0xa8) >> 0x18),*(undefined3 *)(in_ECX + 0xa8)),param_1)
  ;
  return;
}


// ==== FUN_006a2ad0 @ 0x006a2ad0 ====

undefined4 FUN_006a2ad0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffff0000;
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x2c))();
    if (((*(int *)(iVar1 + 4) == 4) || (*(int *)(iVar1 + 4) == 5)) || (*(int *)(iVar1 + 8) == 0x101)
       ) {
      uVar3 = 0xffffffff;
    }
  }
  iVar1 = (**(code **)(*DAT_00b5b0fc + 0x2c))();
  if ((iVar1 != 0) &&
     (puVar2 = (undefined4 *)(**(code **)(*DAT_00b5b0fc + 0x2c))(), (int *)*puVar2 == param_1)) {
    uVar3 = 0xaa333333;
  }
  iVar1 = (**(code **)(*DAT_00b5b0fc + 0x30))();
  if ((iVar1 != 0) &&
     (puVar2 = (undefined4 *)(**(code **)(*DAT_00b5b0fc + 0x30))(), (int *)*puVar2 == param_1)) {
    uVar3 = 0xaa333333;
  }
  iVar1 = (**(code **)(*DAT_00b5b0fc + 0x34))();
  if ((iVar1 == 0) ||
     (puVar2 = (undefined4 *)(**(code **)(*DAT_00b5b0fc + 0x34))(), (int *)*puVar2 != param_1)) {
    return uVar3;
  }
  return 0xaa333333;
}


// ==== FUN_006a2b70 @ 0x006a2b70 ====

undefined4 FUN_006a2b70(int param_1,undefined2 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2) {
    case 1:
      iVar1 = *DAT_00b5a78c;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x28))(uVar2);
      return 1;
    case 3:
      iVar1 = *DAT_00b5b114;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x34))(uVar2);
      return 1;
    case 4:
      (**(code **)(*DAT_00b5a78c + 4))((int3)in_ECX[0x2a]);
      return 1;
    case 5:
      uVar2 = thunk_FUN_00796f80(param_4);
      FUN_006a2aa0(uVar2);
      return 1;
    case 0xb:
      (**(code **)(*DAT_00b5b0fc + 0x1c))();
    }
  }
  return 1;
}


// ==== FUN_006a2c80 @ 0x006a2c80 ====

void FUN_006a2c80(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 uVar4;
  void *pvStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  FUN_005811f0();
  cVar1 = (**(code **)(*DAT_00b5b0fc + 0x44))();
  if (cVar1 == '\x01') {
    cVar1 = (**(code **)(*DAT_00b5b0fc + 0x48))();
    if (cVar1 == '\0') {
      uVar4 = 100;
    }
    else {
      uVar4 = 0x65;
    }
    FUN_004dd240(0x16,uVar4,0,0,0);
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    FUN_00401740(s_pan_effect_009dec78,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      uVar4 = (**(code **)(*piVar2 + 4))();
      *puVar3 = &PTR_FUN_009bba08;
      puVar3[1] = uVar4;
      puVar3[3] = 1;
      puVar3[5] = 0;
      *(undefined1 *)(puVar3 + 6) = 0;
    }
    *(undefined1 *)((int)puVar3 + 0x19) = 1;
    puVar3[2] = 0x80014;
    puVar3[3] = unaff_ESI;
    puVar3[4] = 1000;
    *(undefined1 *)(puVar3 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar3);
    (**(code **)*puVar3)(1);
    (**(code **)(*DAT_00b5b0fc + 0x40))(0);
  }
  return;
}


// ==== FUN_006a2db0 @ 0x006a2db0 ====

void FUN_006a2db0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_upgrade_item_009deca8,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  piVar1 = (int *)(**(code **)(*DAT_00b5b0fc + 0x2c))();
  if (piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  if ((int *)*piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  uStack_34 = (**(code **)(*(int *)*piVar1 + 0x1c))();
  uStack_34 = uStack_34 & 0xffff;
  iVar2 = (**(code **)(*(int *)*piVar1 + 0x2c))();
  uStack_24 = (uint)*(byte *)(iVar2 + 0x31);
  uStack_28 = (uint)*(byte *)(iVar2 + 0x30);
  FUN_005802c0(&uStack_34,&uStack_28);
  FUN_00580870(*piVar1,1);
  return;
}


// ==== FUN_006a2ee0 @ 0x006a2ee0 ====

void FUN_006a2ee0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_stone_item_009decb8,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  piVar1 = (int *)(**(code **)(*DAT_00b5b0fc + 0x30))();
  if (piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  if ((int *)*piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  uStack_34 = (**(code **)(*(int *)*piVar1 + 0x1c))();
  uStack_34 = uStack_34 & 0xffff;
  iVar2 = (**(code **)(*(int *)*piVar1 + 0x2c))();
  uStack_24 = (uint)*(byte *)(iVar2 + 0x31);
  uStack_28 = (uint)*(byte *)(iVar2 + 0x30);
  FUN_005802c0(&uStack_34,&uStack_28);
  FUN_00580870(*piVar1,1);
  return;
}


// ==== FUN_006a3010 @ 0x006a3010 ====

void FUN_006a3010(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_cash_item_009decc4,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  piVar1 = (int *)(**(code **)(*DAT_00b5b0fc + 0x34))();
  if (piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  if ((int *)*piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  uStack_34 = (**(code **)(*(int *)*piVar1 + 0x1c))();
  uStack_34 = uStack_34 & 0xffff;
  iVar2 = (**(code **)(*(int *)*piVar1 + 0x2c))();
  uStack_24 = (uint)*(byte *)(iVar2 + 0x31);
  uStack_28 = (uint)*(byte *)(iVar2 + 0x30);
  FUN_005802c0(&uStack_34,&uStack_28);
  FUN_00580870(*piVar1,0);
  return;
}


// ==== FUN_006a3140 @ 0x006a3140 ====

void FUN_006a3140(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5b0fc + 0x28))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_cost_009decd0,8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0((int)register0x00000010 + -0x20,uVar1);
  FUN_0055a260(uVar1);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_006a31f0 @ 0x006a31f0 ====

void FUN_006a31f0(byte param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  bVar1 = (**(code **)(*DAT_00b5ad1c + 0x7c))();
  uStack_20 = (void *)CONCAT13(bVar1,(undefined3)uStack_20);
  if ((param_1 < bVar1) &&
     (uStack_20 = (void *)(CONCAT13(bVar1,(undefined3)uStack_20) & 0xff00ffff), bVar1 != 0)) {
    do {
      FUN_00401740(s_btn_changebag__d_009ded04,0x10);
      uVar2 = FUN_00404230(&pvStack_1c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_00558730(uStack_20._2_1_ == param_1);
      }
      bVar1 = uStack_20._2_1_ + 1;
      uStack_20._0_3_ = CONCAT12(bVar1,(undefined2)uStack_20);
    } while (bVar1 < uStack_20._3_1_);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_changebag_2_009ded18,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(2 < (byte)((uint)unaff_EBX >> 0x18));
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_btn_changebag_3_009ded28,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_20);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(3 < (byte)((uint)unaff_EBP >> 0x18));
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(uStack_20);
  return;
}


// ==== FUN_006a3370 @ 0x006a3370 ====

void FUN_006a3370(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar2 = 0;
  iVar6 = 0;
  piVar7 = (int *)(in_ECX + 0x50);
  do {
    if ((uVar2 < 0xd) || (0x12 < uVar2)) {
      iVar3 = (**(code **)(*DAT_00b5a78c + 0x44))(iVar6);
      *piVar7 = iVar3;
      FUN_00401740(s_suititem__d_009ded64,0xb);
      uVar4 = FUN_00404230(apvStack_28);
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
      if (0xf < uStack_14) {
        _free(apvStack_28[0]);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
      (**(code **)(*piVar5 + 0x30))();
      if ((int *)*piVar7 == (int *)0x0) {
        auStack_3c[1] = 0;
        uStack_2c = 1;
        apvStack_28[0] = (void *)0x1;
        FUN_005802c0(auStack_3c + 1,&uStack_2c);
        FUN_00580870(0,1);
      }
      else {
        auStack_3c[0] = (**(code **)(*(int *)*piVar7 + 0x1c))();
        auStack_3c[0] = auStack_3c[0] & 0xffff;
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x2c))();
        uStack_30 = (uint)*(byte *)(iVar3 + 0x31);
        auStack_3c[2] = (uint)*(byte *)(iVar3 + 0x30);
        FUN_005802c0(auStack_3c,auStack_3c + 2);
        FUN_00580870(*piVar7,1);
        FUN_0057f430(0xffffffff);
      }
    }
    uVar2 = uVar2 + 1;
    iVar6 = iVar6 + 1;
    piVar7 = piVar7 + 1;
  } while (uVar2 < 0x15);
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x54))();
  *(undefined1 *)(in_ECX + 0xac) = uVar1;
  return;
}


// ==== FUN_006a34d0 @ 0x006a34d0 ====

undefined4 FUN_006a34d0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined2 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_slotbag_009dee78,7);
  if (iVar2 != 0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x2c))();
    uStack_20 = CONCAT11(uStack_20._1_1_,*(undefined1 *)(in_ECX + 0xab));
    uVar1 = FUN_00802534();
    uStack_20 = CONCAT11(uVar1,(undefined1)uStack_20);
    uVar1 = FUN_00802534();
    (**(code **)(*DAT_00b5a78c + 4))(CONCAT12(uVar1,uStack_20));
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_Call_________IINVEN__IUIHANDLER__009dee80,0x3c);
    FUN_00796d50(&uStack_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_006a3640 @ 0x006a3640 ====

void FUN_006a3640(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009deed8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 4;
  puVar2 = in_ECX + 0x15;
  do {
    if ((void *)puVar2[-4] != (void *)0x0) {
      _free((void *)puVar2[-4]);
      return;
    }
    iVar1 = iVar1 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2 = puVar2 + -4;
  } while (iVar1 != 0);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006a3690 @ 0x006a3690 ====

void FUN_006a3690(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBP;
  undefined4 uStack_a8;
  undefined1 uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  undefined4 uStack_84;
  uint uStack_80;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined1 auStack_3c [16];
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  uStack_90 = 0xf;
  pvStack_94 = (void *)0x0;
  uStack_a4 = 0;
  FUN_00401740(s_lbl_money_009ded38,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_a8);
  if (0xf < pvStack_94) {
    _free(uStack_a8);
    return;
  }
  pvStack_94 = (void *)0xf;
  uStack_98 = 0;
  uStack_a8 = (void *)((uint)uStack_a8 & 0xffffff00);
  (**(code **)(*DAT_00b5ad20 + 0x48))(auStack_3c,uVar1);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0(auStack_28,uVar1,s_<_color>_009ded44);
  uVar1 = FUN_004022a0(auStack_7c,s_<color__009ded54,auStack_44,&DAT_009ded50,uVar1);
  uVar1 = FUN_00402220(&uStack_98,uVar1);
  uVar1 = FUN_00405bd0(auStack_60,uVar1);
  uVar1 = FUN_00402220(auStack_7c + -0x38,uVar1);
  FUN_0055a260(uVar1);
  if (0xf < uStack_9c) {
    _free(unaff_EBP);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006a3850 @ 0x006a3850 ====

void FUN_006a3850(void)

{
  byte bVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_EBX;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uStack_2c;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  void *local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  puVar4 = (undefined4 *)(in_ECX + 0x14);
  iVar3 = 4;
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      _free((void *)*puVar4);
      return;
    }
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4 = puVar4 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_24);
  uStack_14 = 0xffffffff;
  if (local_24 != (void *)0x0) {
    uStack_1c = (uint)bStack_27;
    uStack_18 = (uint)bStack_26;
    pvStack_20 = local_24;
    uStack_14 = FUN_006a2ad0(local_24);
    iVar5 = (bStack_28 + 1) * 0x10 + in_ECX;
    iVar3 = *(int *)(iVar5 + 4);
    if ((iVar3 == 0) ||
       ((uint)(*(int *)(iVar5 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar3 >> 4))) {
      FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&pvStack_20);
    }
    else {
      iVar3 = *(int *)(iVar5 + 8);
      FUN_00680b80(iVar3,1,&pvStack_20,iVar5,unaff_EBX);
      *(int *)(iVar5 + 8) = iVar3 + 0x10;
    }
    (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    while (uStack_2c != (void *)0x0) {
      uStack_1c = unaff_EBX >> 8 & 0xff;
      uStack_18 = unaff_EBX >> 0x10 & 0xff;
      pvStack_20 = uStack_2c;
      uStack_14 = FUN_006a2ad0(uStack_2c);
      iVar5 = ((unaff_EBX & 0xff) + 1) * 0x10 + in_ECX;
      iVar3 = *(int *)(iVar5 + 4);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar3 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&pvStack_20);
      }
      else {
        iVar3 = *(int *)(iVar5 + 8);
        FUN_00680b80(iVar3,1,&pvStack_20,iVar5,unaff_EBX);
        *(int *)(iVar5 + 8) = iVar3 + 0x10;
      }
      (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    }
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotbag_009ded5c,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    (**(code **)(*piVar2 + 0x30))();
    bVar1 = (**(code **)(*DAT_00b5a78c + 0x50))();
    *(byte *)(in_ECX + 0xab) = bVar1;
    FUN_005817e0((bVar1 + 1) * 0x10 + in_ECX,1);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006a3a80 @ 0x006a3a80 ====

/* WARNING: Removing unreachable block (ram,0x006a3b07) */

void FUN_006a3a80(undefined4 param_1,byte *param_2,ushort param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  puVar2 = operator_new(0x58);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b5340;
    puVar2[6] = 0;
    puVar2[7] = 0xf;
    *(undefined1 *)(puVar2 + 2) = 0;
    puVar2[0xe] = 0xf;
    puVar2[0xd] = 0;
    *(undefined1 *)(puVar2 + 9) = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0x12] = 0;
    *(undefined2 *)(puVar2 + 0x13) = 0;
    puVar2[0x14] = 0;
    puVar2[0x15] = 10000;
  }
  uVar3 = (**(code **)(*in_ECX + 0x14))();
  puVar2[0x14] = uVar3;
  FUN_00401660(param_1,0,0xffffffff);
  bVar1 = *param_2;
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  puVar2[0x15] = 2000;
  *(ushort *)(puVar2 + 0x13) = (ushort)bVar1 << 8 | param_3;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_006a3b30 @ 0x006a3b30 ====

void FUN_006a3b30(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  void *local_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_006a3690();
  FUN_006a3850();
  FUN_006a3370();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009decdc,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0xac));
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_EBX);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_tab_chang_weapon_009decf0,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (uStack_c < 0x10) {
    FUN_006a31f0(*(undefined1 *)(in_ECX + 0xab));
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006a3c20 @ 0x006a3c20 ====

void FUN_006a3c20(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_EBX;
  void *local_38;
  undefined1 local_34 [8];
  undefined4 uStack_2c;
  uint uStack_28;
  uint local_24;
  undefined4 local_20;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  FUN_006a2db0();
  FUN_006a2ee0();
  FUN_006a3010();
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = 0;
  FUN_00401740(s_lbl_percent_009dec8c,0xb);
  (**(code **)(*DAT_00b5b0fc + 0x38))();
  FUN_00401740(s____d___009dec84,6);
  uVar2 = FUN_00404230(apvStack_1c);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  (**(code **)(*piVar3 + 0x30))();
  FUN_0055a260(uVar2);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  FUN_006a3140();
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_btn_strength_009dec98,0xc);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c + -8);
  if (0xf < uStack_28) {
    _free(unaff_EBX);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  cVar1 = (**(code **)(*DAT_00b5b0fc + 0x24))();
  if (cVar1 == '\0') {
    (**(code **)(*piVar3 + 0x44))(0);
    FUN_006a3b30();
    return;
  }
  (**(code **)(*piVar3 + 0x44))(1);
  FUN_006a3b30();
  return;
}


// ==== FUN_006a3d80 @ 0x006a3d80 ====

undefined4 FUN_006a3d80(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 uVar7;
  int *in_ECX;
  char *pcVar8;
  undefined *puVar9;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_24 [4];
  uint local_20;
  undefined1 local_1c [28];
  
  iVar2 = param_2;
  if (param_1 == 1) {
    if (param_3 != 1) {
      return 0;
    }
    iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_strength_009ded70,0xc);
    if (iVar6 != 0) {
      cVar3 = FUN_004036a0(iVar2,s_btn_exit_009ded98);
      if (cVar3 != '\0') {
        (**(code **)(*in_ECX + 0x10))();
        return 1;
      }
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      FUN_00404fb0(iVar2,0x5f,local_48);
      pcVar8 = s_changebag_009deda4;
      uVar7 = FUN_00405d30(1);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(2);
        uVar7 = thunk_FUN_00796f50(uVar7);
        *(char *)((int)in_ECX + 0xab) = (char)uVar7;
        (**(code **)(*DAT_00b5a78c + 0x30))(uVar7);
        FUN_006a3c20();
        FUN_00406250();
        return 1;
      }
LAB_006a42ad:
      FUN_00406250();
      return 0;
    }
    param_3 = CONCAT31(param_3._1_3_,0x20);
    FUN_00401830(s_ui_upgradeprogress_txt_009ded80);
    FUN_006a3a80(local_38,&param_3,0xb);
    if (0xf < local_20) {
      _free(local_34);
      return extraout_EAX;
    }
  }
  else if (param_1 == 10) {
    if (param_3 != 1) {
      return 0;
    }
    cVar3 = FUN_006a34d0(param_2,param_4);
    if (cVar3 == '\0') {
      return 0;
    }
  }
  else {
    if (param_1 != 0xf) {
      if (((param_1 == 0xb) && (param_3 == 1)) &&
         ((cVar3 = FUN_004036a0(param_2,s_tab_chang_weapon_009dee50), cVar3 != '\0' ||
          (cVar3 = FUN_004036a0(iVar2,s_tab_chang_shield_009dee64), cVar3 != '\0')))) {
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x28001c);
        FUN_00765c50(uVar7);
        iVar2 = *DAT_00b5ad0c;
        FUN_00765c50(auStack_24);
        (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 0;
    }
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    FUN_00404fb0(param_2,0x5f,local_48);
    if (param_3 == 1) {
      pcVar8 = s_upgrade_009dedb0;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        (**(code **)(*DAT_00b5b100 + 0x1c))();
        FUN_006a3c20();
        FUN_00406250();
        return 1;
      }
      pcVar8 = s_stone_009dedb8;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        (**(code **)(*DAT_00b5b100 + 0x20))();
        FUN_006a3c20();
        FUN_00406250();
        return 1;
      }
      puVar9 = &DAT_009dedc0;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,puVar9);
      if (cVar3 != '\0') {
        (**(code **)(*DAT_00b5b100 + 0x24))();
        FUN_006a3c20();
        FUN_00406250();
        return 1;
      }
      pcVar8 = s_suititem_009dedc8;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        (**(code **)(*DAT_00b5a78c + 0xc))(uVar4);
        FUN_00406250();
        return 1;
      }
      pcVar8 = s_slotbag_009dedd4;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        uVar7 = FUN_00405d30(2);
        uVar5 = thunk_FUN_00796f50(uVar7);
        piVar1 = in_ECX + 0x2a;
        *(undefined1 *)piVar1 = *(undefined1 *)((int)in_ECX + 0xab);
        *(undefined1 *)((int)in_ECX + 0xa9) = uVar4;
        *(undefined1 *)((int)in_ECX + 0xaa) = uVar5;
        cVar3 = (**(code **)(*DAT_00b5a78c + 0x34))(piVar1);
        if (cVar3 == '\0') {
          (**(code **)(*DAT_00b5a78c + 4))((int3)*piVar1);
          FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009dedec);
          FUN_00796d50(&local_40);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        param_2 = CONCAT31(param_2._1_3_,3);
        FUN_00401830(s_ui_socket_txt_009deddc);
        FUN_006a3a80(&local_3c,&param_2,4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      goto LAB_006a42ad;
    }
    if (param_3 == 2) {
      pcVar8 = s_slotbag_009dee2c;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        local_34 = (void *)0x0;
        local_30 = 0;
        local_2c = 0;
        FUN_00404fb0(iVar2,0x5f,local_38);
        uVar7 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar7);
        uVar7 = FUN_00405d30(2);
        uVar5 = thunk_FUN_00796f50(uVar7);
        param_3._0_2_ = CONCAT11(uVar4,*(undefined1 *)((int)in_ECX + 0xab));
        (**(code **)(*DAT_00b5a78c + 8))(CONCAT12(uVar5,(undefined2)param_3));
        FUN_00406250();
      }
    }
    else if (param_3 == 0xd) {
      pcVar8 = s_slotbag_009dee34;
      uVar7 = FUN_00405d30(0);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        param_3 = CONCAT31(param_3._1_3_,4);
        FUN_00401830(s_ui_stackcount_txt_009dee3c);
        FUN_006a3a80(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else if (((param_3 != 4) && (param_3 != 5)) ||
            (cVar3 = FUN_006a2a20(iVar2,param_3,param_4), cVar3 == '\0')) goto LAB_006a42ad;
    FUN_00406250();
  }
  return 1;
}


// ==== FUN_006a4350 @ 0x006a4350 ====

void FUN_006a4350(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStack_38 [4];
  undefined4 local_1c;
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_upgradewnd_txt_009dec4c,0x1a);
  iVar1 = FUN_00410500(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_slotbag_009dec68,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0x10);
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  (**(code **)(*piVar2 + 0x30))();
  FUN_00580be0(1);
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  FUN_00401740(s_slotbag_009dec70,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0xc);
  if (local_18 < 0x10) {
    local_18 = (void *)0xf;
    local_1c = 0;
    uVar3 = (**(code **)(*piVar2 + 0x30))();
    *(undefined4 *)(in_ECX + 0xa4) = uVar3;
    FUN_006a3c20();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_006a4480 @ 0x006a4480 ====

uint FUN_006a4480(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = (**(code **)(*in_ECX + 0x30))(param_1);
  }
  else if (uVar1 == 0x70330002) {
    uVar1 = FUN_006a3c20();
    return uVar1 & 0xffffff00;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a44c0 @ 0x006a44c0 ====

void FUN_006a44c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009deed8;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  *(undefined1 *)((int)in_ECX + 0xa9) = 0;
  *(undefined1 *)((int)in_ECX + 0xaa) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  *(undefined1 *)((int)in_ECX + 0xab) = 0;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  *(undefined1 *)((int)in_ECX + 0xa9) = 0;
  *(undefined1 *)((int)in_ECX + 0xaa) = 0;
  FUN_006a4350();
  return;
}


// ==== FUN_006a4540 @ 0x006a4540 ====

undefined4 FUN_006a4540(void)

{
  return 0x2b;
}


// ==== FUN_006a4550 @ 0x006a4550 ====

void FUN_006a4550(byte param_1)

{
  void *in_ECX;
  
  FUN_006a3640();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a4570 @ 0x006a4570 ====

void FUN_006a4570(void)

{
  return;
}


// ==== FUN_006a4630 @ 0x006a4630 ====

undefined4 FUN_006a4630(void)

{
  (**(code **)(*DAT_00b5b108 + 0x30))();
  return 1;
}


// ==== FUN_006a4640 @ 0x006a4640 ====

undefined4 FUN_006a4640(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 != 0) {
    if (param_1 != 4) {
      return 0;
    }
    iVar3 = (**(code **)(*DAT_00b5a78c + 0x48))();
    if ((iVar3 == 0) && (iVar3 = FUN_0057f270(), iVar3 == 0)) {
      return 1;
    }
    cVar1 = (**(code **)(*DAT_00b5ad20 + 0x34))(iVar3);
    if (cVar1 != '\0') {
      FUN_0057f390(0x40000060);
      return 1;
    }
    FUN_0057f390(0x60b00000);
  }
  return 1;
}


// ==== FUN_006a46f0 @ 0x006a46f0 ====

void FUN_006a46f0(void)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_slotbag_009def6c,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    (**(code **)(*piVar1 + 0x30))();
    FUN_005811f0();
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_006a4770 @ 0x006a4770 ====

void FUN_006a4770(byte param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  bVar1 = (**(code **)(*DAT_00b5ad1c + 0x7c))();
  uStack_20 = (void *)CONCAT13(bVar1,(undefined3)uStack_20);
  if ((param_1 < bVar1) &&
     (uStack_20 = (void *)(CONCAT13(bVar1,(undefined3)uStack_20) & 0xff00ffff), bVar1 != 0)) {
    do {
      FUN_00401740(s_btn_changebag__d_009defb0,0x10);
      uVar2 = FUN_00404230(&pvStack_1c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_00558730(uStack_20._2_1_ == param_1);
      }
      bVar1 = uStack_20._2_1_ + 1;
      uStack_20._0_3_ = CONCAT12(bVar1,(undefined2)uStack_20);
    } while (bVar1 < uStack_20._3_1_);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_changebag_2_009defc4,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(2 < (byte)((uint)unaff_EBX >> 0x18));
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_btn_changebag_3_009defd4,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_20);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(3 < (byte)((uint)unaff_EBP >> 0x18));
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(uStack_20);
  return;
}


// ==== FUN_006a48f0 @ 0x006a48f0 ====

void FUN_006a48f0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_money_009defe4,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0((int)register0x00000010 + -0x20,uVar1);
  FUN_0055a260(uVar1);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_006a49a0 @ 0x006a49a0 ====

void FUN_006a49a0(void)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar3 = 0;
  iVar7 = 0;
  piVar8 = (int *)(in_ECX + 0x68);
  do {
    if ((uVar3 < 0xd) || (0x12 < uVar3)) {
      iVar4 = (**(code **)(*DAT_00b5a78c + 0x44))(iVar7);
      *piVar8 = iVar4;
      FUN_00401740(s_suititem__d_009deff8,0xb);
      uVar5 = FUN_00404230(apvStack_28);
      piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar5);
      if (0xf < uStack_14) {
        _free(apvStack_28[0]);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
      (**(code **)(*piVar6 + 0x30))();
      if ((int *)*piVar8 == (int *)0x0) {
        uStack_2c = 1;
        apvStack_28[0] = (void *)0x1;
        auStack_3c[1] = 0;
        FUN_005802c0(auStack_3c + 1,&uStack_2c);
        FUN_00580870(0,1);
      }
      else {
        auStack_3c[0] = (**(code **)(*(int *)*piVar8 + 0x1c))();
        auStack_3c[0] = auStack_3c[0] & 0xffff;
        iVar4 = (**(code **)(*(int *)*piVar8 + 0x2c))();
        uStack_30 = (uint)*(byte *)(iVar4 + 0x31);
        auStack_3c[2] = (uint)*(byte *)(iVar4 + 0x30);
        FUN_005802c0(auStack_3c,auStack_3c + 2);
        FUN_00580870(*piVar8,1);
        iVar4 = FUN_0057f270();
        if (iVar4 != 0) {
          piVar6 = (int *)FUN_0057f270();
          cVar1 = (**(code **)(*piVar6 + 100))();
          if (cVar1 == '\x01') {
            FUN_0057f430(0xaa333333);
          }
          else {
            FUN_0057f430(0xffffffff);
          }
        }
      }
    }
    uVar3 = uVar3 + 1;
    iVar7 = iVar7 + 1;
    piVar8 = piVar8 + 1;
  } while (uVar3 < 0x15);
  uVar2 = (**(code **)(*DAT_00b5a78c + 0x54))();
  *(undefined1 *)(in_ECX + 0xc0) = uVar2;
  return;
}


// ==== FUN_006a4b30 @ 0x006a4b30 ====

void FUN_006a4b30(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009df0b0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 4;
  puVar2 = in_ECX + 0x1b;
  do {
    if ((void *)puVar2[-4] != (void *)0x0) {
      _free((void *)puVar2[-4]);
      return;
    }
    iVar1 = iVar1 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2 = puVar2 + -4;
  } while (iVar1 != 0);
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006a4bc0 @ 0x006a4bc0 ====

void FUN_006a4bc0(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int in_ECX;
  uint unaff_EBX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_2c;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  int *local_24;
  int *piStack_20;
  uint uStack_1c;
  uint uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  puVar6 = (undefined4 *)(in_ECX + 0x2c);
  iVar5 = 4;
  do {
    if ((void *)*puVar6 != (void *)0x0) {
      _free((void *)*puVar6);
      return;
    }
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = puVar6 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_24);
  iStack_14 = -1;
  if (local_24 != (int *)0x0) {
    uStack_1c = (uint)bStack_27;
    uStack_18 = (uint)bStack_26;
    piStack_20 = local_24;
    cVar2 = (**(code **)(*local_24 + 100))();
    iStack_14 = (-(uint)(cVar2 != '\x01') & 0x55cccccc) + 0xaa333333;
    iVar5 = (uint)bStack_28 * 0x10 + 0x28 + in_ECX;
    iVar1 = *(int *)(iVar5 + 4);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(iVar5 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar1 >> 4))) {
      FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&piStack_20);
    }
    else {
      iVar1 = *(int *)(iVar5 + 8);
      FUN_00680b80(iVar1,1,&piStack_20,iVar5,unaff_EBX);
      *(int *)(iVar5 + 8) = iVar1 + 0x10;
    }
    (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    while (uStack_2c != (int *)0x0) {
      uStack_1c = unaff_EBX >> 8 & 0xff;
      uStack_18 = unaff_EBX >> 0x10 & 0xff;
      piStack_20 = uStack_2c;
      cVar2 = (**(code **)(*uStack_2c + 100))();
      iStack_14 = (-(uint)(cVar2 != '\x01') & 0x55cccccc) + 0xaa333333;
      iVar5 = (unaff_EBX & 0xff) * 0x10 + 0x28 + in_ECX;
      iVar1 = *(int *)(iVar5 + 4);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar1 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&piStack_20);
      }
      else {
        iVar1 = *(int *)(iVar5 + 8);
        FUN_00680b80(iVar1,1,&piStack_20,iVar5,unaff_EBX);
        *(int *)(iVar5 + 8) = iVar1 + 0x10;
      }
      (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    }
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotbag_009deff0,7);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&piStack_20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    piStack_20 = (int *)((uint)piStack_20 & 0xffffff00);
    (**(code **)(*piVar4 + 0x30))();
    bVar3 = (**(code **)(*DAT_00b5a78c + 0x50))();
    *(byte *)(in_ECX + 0xbf) = bVar3;
    FUN_005817e0((uint)bVar3 * 0x10 + 0x28 + in_ECX,1);
    return;
  }
  _free(piStack_20);
  return;
}


// ==== FUN_006a4e10 @ 0x006a4e10 ====

void FUN_006a4e10(void)

{
  int *piVar1;
  void *in_ECX;
  void *pvVar2;
  int unaff_EBX;
  int iVar3;
  uint local_2c;
  undefined1 auStack_28 [8];
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (*(void **)((int)in_ECX + 0xc) != (void *)0x0) {
    _free(*(void **)((int)in_ECX + 0xc));
    return;
  }
  *(undefined4 *)((int)in_ECX + 0xc) = 0;
  *(undefined4 *)((int)in_ECX + 0x10) = 0;
  *(undefined4 *)((int)in_ECX + 0x14) = 0;
  (**(code **)(*DAT_00b5b108 + 0x38))(&local_2c);
  iVar3 = 0;
  if (in_ECX != (void *)0x0) {
    uStack_14 = 0xffffffff;
    pvVar2 = in_ECX;
    do {
      uStack_18 = local_2c >> 0x10 & 0xff;
      uStack_1c = local_2c >> 8 & 0xff;
      iVar3 = *(int *)((int)in_ECX + 0xc);
      pvStack_20 = pvVar2;
      if ((iVar3 == 0) ||
         ((uint)(*(int *)((int)in_ECX + 0x14) - iVar3 >> 4) <=
          (uint)(*(int *)((int)in_ECX + 0x10) - iVar3 >> 4))) {
        FUN_00680c50(*(undefined4 *)((int)in_ECX + 0x10),1,&pvStack_20);
      }
      else {
        iVar3 = *(int *)((int)in_ECX + 0x10);
        FUN_00680b80(iVar3,1,&pvStack_20,(int)in_ECX + 8,unaff_EBX);
        *(int *)((int)in_ECX + 0x10) = iVar3 + 0x10;
      }
      piVar1 = (int *)(**(code **)(*DAT_00b5b108 + 0x3c))(auStack_28);
      pvVar2 = (void *)*piVar1;
      local_2c = piVar1[1];
    } while (pvVar2 != (void *)0x0);
    iVar3 = unaff_EBX;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotRepair_009df004,10);
  piVar1 = (int *)(**(code **)(**(int **)(iVar3 + 4) + 0x34))(&pvStack_20);
  (**(code **)(*piVar1 + 0x30))();
  if (uStack_c < 0x10) {
    FUN_005817e0((int)in_ECX + 8,0);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006a4f60 @ 0x006a4f60 ====

/* WARNING: Removing unreachable block (ram,0x006a4fe7) */

void FUN_006a4f60(undefined4 param_1,byte *param_2,ushort param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b5340;
    puVar1[6] = 0;
    puVar1[7] = 0xf;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[0xe] = 0xf;
    puVar1[0xd] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    *(undefined2 *)(puVar1 + 0x13) = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 10000;
  }
  uVar2 = (**(code **)(*in_ECX + 0x14))();
  puVar1[0x14] = uVar2;
  FUN_00401660(param_1,0,0xffffffff);
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  *(ushort *)(puVar1 + 0x13) = (ushort)*param_2 << 8 | param_3;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006a5010 @ 0x006a5010 ====

void FUN_006a5010(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  void *local_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_006a48f0();
  FUN_006a4bc0();
  FUN_006a49a0();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009def88,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0xc0));
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_EBX);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_tab_chang_weapon_009def9c,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (uStack_c < 0x10) {
    FUN_006a4770(*(undefined1 *)(in_ECX + 0xbf));
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006a5100 @ 0x006a5100 ====

void FUN_006a5100(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_lbl_repairCost_009def78,0xe);
  (**(code **)(*DAT_00b5b108 + 0x34))();
  FUN_00401740(&DAT_009def74,2);
  uVar1 = FUN_00404230(apvStack_1c);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  (**(code **)(*piVar2 + 0x30))();
  FUN_0055a260(uVar1);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (local_24 < 0x10) {
    FUN_006a4e10();
    FUN_006a5010();
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_006a51d0 @ 0x006a51d0 ====

undefined4 FUN_006a51d0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  char *pcVar6;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_24 [8];
  undefined1 local_1c [28];
  
  if (param_1 == 1) {
    if (param_3 != 1) {
      return 0;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_Repair_009df010,10);
    if (iVar4 == 0) {
      (**(code **)(*DAT_00b5b108 + 0x24))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_RepairAll_009df01c);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5b108 + 0x28))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_exit_009df02c);
    if (cVar1 != '\0') {
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    FUN_00404fb0(param_2,0x5f,local_3c);
    pcVar6 = s_changebag_009df038;
    uVar5 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar5,pcVar6);
    if (cVar1 != '\0') {
      uVar5 = FUN_00405d30(2);
      uVar5 = thunk_FUN_00796f50(uVar5);
      *(char *)((int)in_ECX + 0xbf) = (char)uVar5;
      (**(code **)(*DAT_00b5a78c + 0x30))(uVar5);
      FUN_006a5100();
      FUN_00406250();
      return 1;
    }
  }
  else {
    if (param_1 != 0xf) {
      if (param_1 != 0xb) {
        return 0;
      }
      if (param_3 != 1) {
        return 0;
      }
      cVar1 = FUN_004036a0(param_2,s_tab_chang_weapon_009df080);
      if ((cVar1 != '\0') ||
         (cVar1 = FUN_004036a0(param_2,s_tab_chang_shield_009df094), cVar1 != '\0')) {
        uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280026);
        FUN_00765c50(uVar5);
        iVar4 = *DAT_00b5ad0c;
        FUN_00765c50(auStack_24);
        (**(code **)(iVar4 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 0;
    }
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    FUN_00404fb0(param_2,0x5f,local_3c);
    if (param_3 != 1) {
      if (param_3 == 0xd) {
        pcVar6 = s_slotbag_009df064;
        uVar5 = FUN_00405d30(0);
        cVar1 = FUN_004036a0(uVar5,pcVar6);
        if (cVar1 != '\0') {
          param_3 = CONCAT31(param_3._1_3_,4);
          FUN_00401830(s_ui_stackcount_txt_009df06c);
          FUN_006a4f60(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else if (((param_3 != 4) && (param_3 != 5)) ||
              (cVar1 = FUN_006a4640(param_2,param_3,param_4), cVar1 == '\0')) goto LAB_006a556a;
      FUN_00406250();
      return 1;
    }
    iVar4 = FUN_00405d30(0);
    iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),s_suititem_009df044,8);
    if (iVar4 == 0) {
      uVar5 = FUN_00405d30(1);
      uVar2 = thunk_FUN_00796f50(uVar5);
      param_3 = CONCAT31(param_3._1_3_,uVar2);
      (**(code **)(*DAT_00b5b108 + 0x18))(param_3,1);
      FUN_00406250();
      return 1;
    }
    pcVar6 = s_slotbag_009df050;
    uVar5 = FUN_00405d30(0);
    cVar1 = FUN_004036a0(uVar5,pcVar6);
    if (cVar1 != '\0') {
      uVar5 = FUN_00405d30(1);
      uVar2 = thunk_FUN_00796f50(uVar5);
      uVar5 = FUN_00405d30(2);
      uVar3 = thunk_FUN_00796f50(uVar5);
      param_3._0_2_ = CONCAT11(uVar2,*(undefined1 *)((int)in_ECX + 0xbf));
      (**(code **)(*DAT_00b5b108 + 0x1c))(CONCAT12(uVar3,(undefined2)param_3),1);
      FUN_00406250();
      return 1;
    }
    pcVar6 = s_slotRepair_009df058;
    uVar5 = FUN_00405d30(0);
    cVar1 = FUN_004036a0(uVar5,pcVar6);
    if (cVar1 != '\0') {
      uVar5 = FUN_00405d30(1);
      uVar2 = thunk_FUN_00796f50(uVar5);
      param_3 = (uint)CONCAT21((short)((uint)param_3 >> 0x10),uVar2) << 8;
      uVar5 = FUN_00405d30(2);
      uVar2 = thunk_FUN_00796f50(uVar5);
      (**(code **)(*DAT_00b5b108 + 0x20))(CONCAT12(uVar2,(undefined2)param_3));
      FUN_00406250();
      return 1;
    }
  }
LAB_006a556a:
  FUN_00406250();
  return 0;
}


// ==== FUN_006a5600 @ 0x006a5600 ====

void FUN_006a5600(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_34 [4];
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_repairwnd_txt_009def48,0x19);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_slotbag_009def64,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  if (uStack_14 < 0x10) {
    uStack_14 = 0xf;
    local_18 = (void *)0x0;
    (**(code **)(*piVar2 + 0x30))();
    FUN_00580be0(1);
    FUN_006a5100();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_006a56e0 @ 0x006a56e0 ====

uint FUN_006a56e0(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = (**(code **)(*in_ECX + 0x30))(param_1);
  }
  else if (uVar1 == 0x70310002) {
    uVar1 = FUN_006a5100();
    return uVar1 & 0xffffff00;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006a5720 @ 0x006a5720 ====

void FUN_006a5720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009df0b0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  *(undefined1 *)((int)in_ECX + 0xbd) = 0;
  *(undefined1 *)((int)in_ECX + 0xbe) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)((int)in_ECX + 0xbf) = 0;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  *(undefined1 *)((int)in_ECX + 0xbd) = 0;
  *(undefined1 *)((int)in_ECX + 0xbe) = 0;
  FUN_006a5600();
  return;
}


// ==== FUN_006a57b0 @ 0x006a57b0 ====

undefined4 FUN_006a57b0(void)

{
  return 0x2a;
}


// ==== FUN_006a57c0 @ 0x006a57c0 ====

void FUN_006a57c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006a4b30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a57e0 @ 0x006a57e0 ====

undefined4 FUN_006a57e0(void)

{
  return 0x70300004;
}


// ==== FUN_006a57f0 @ 0x006a57f0 ====

undefined4 FUN_006a57f0(void)

{
  return 0x70300006;
}


// ==== FUN_006a5800 @ 0x006a5800 ====

void FUN_006a5800(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x006a580c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006a5810 @ 0x006a5810 ====

undefined4 FUN_006a5810(int param_1,short param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if ((param_1 == iVar1) && (param_3 == 1)) {
    if (param_2 == 0) {
      uVar3 = thunk_FUN_00796fb0(param_4);
      puVar2 = operator_new(8);
      if (puVar2 == (undefined4 *)0x0) {
        uRam00000004 = uVar3;
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009df25c;
      puVar2[1] = uVar3;
      FUN_00797a20(puVar2);
      return 1;
    }
    if (param_2 == 1) {
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009df270;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006a5930 @ 0x006a5930 ====

undefined4 FUN_006a5930(void)

{
  (**(code **)(*DAT_00b5adc4 + 0x18))();
  return 1;
}


// ==== FUN_006a5940 @ 0x006a5940 ====

undefined4 FUN_006a5940(undefined4 param_1,ushort param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  float fStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x2c))();
    bVar1 = *(byte *)(iVar3 + 0x31);
    fStack_4 = (float)param_2 * DAT_009a09bc - (float)(bVar1 >> 1);
    if ((bVar1 == 2) || (bVar1 == 4)) {
      if (fStack_4 <= 0.0) {
        fStack_4 = 0.0;
      }
      fStack_4 = fStack_4 + DAT_0099d0b4;
    }
    uStack_8 = 0;
    uStack_7 = FUN_00802534();
    uStack_6 = FUN_00802534();
    (**(code **)(*DAT_00b5adc4 + 0x20))(&uStack_8);
  }
  return 1;
}


// ==== FUN_006a5a30 @ 0x006a5a30 ====

void FUN_006a5a30(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined4 uVar3;
  undefined1 auStack_6e [2];
  void *pvStack_6c;
  undefined1 auStack_68 [4];
  undefined1 auStack_52 [2];
  void *local_50;
  void *pvStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *local_40;
  uint local_3c;
  uint uStack_38;
  void *pvStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  
  local_3c = 0xf;
  local_40 = (void *)0x0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  iVar1 = (**(code **)(*DAT_00b5adc4 + 8))();
  if (iVar1 == 2) {
    pvStack_6c = (void *)0x0;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    uStack_28 = 0xf;
    uStack_2c = 0;
    local_3c = local_3c & 0xffffff00;
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x30))();
      FUN_0055a260();
    }
    if (0xf < uStack_2c) {
      _free(local_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x44))();
    }
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
    uStack_30 = 0xf;
    pvStack_34 = (void *)0x0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    FUN_00401740(s_btn_close_009df158);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if ((void *)0xf < pvStack_34) {
      _free(pvStack_48);
      return;
    }
    pvStack_34 = (void *)0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s_btn_open_009df164,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_4c);
    if (piVar2 != (int *)0x0) {
      uVar3 = 1;
LAB_006a5ce8:
      (**(code **)(*piVar2 + 0x24))(uVar3);
    }
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5adc4 + 8))();
    if (iVar1 != 3) goto LAB_006a5d02;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280015);
    FUN_00401660(uVar3,0,0xffffffff);
    local_40 = (void *)0xf;
    pvStack_44 = (void *)0x0;
    FUN_00401740(s_lbl_pcname_009df170,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_52 + -6);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x30))();
      FUN_0055a260(auStack_6e + -10);
    }
    if (0xf < pvStack_44) {
      _free(unaff_EBX);
      return;
    }
    pvStack_44 = (void *)0xf;
    pvStack_48 = (void *)0x0;
    unaff_EBX = (void *)((uint)unaff_EBX & 0xffffff00);
    FUN_00401740(s_btn_get_009df17c,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_68 + 0xc);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x44))(0);
    }
    if (0xf < pvStack_48) {
      _free(unaff_EBP);
      return;
    }
    pvStack_48 = (void *)0xf;
    pvStack_4c = (void *)0x0;
    FUN_00401740(s_btn_close_009df184,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_68 + 8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if ((void *)0xf < pvStack_4c) {
      _free(unaff_ESI);
      return;
    }
    pvStack_4c = (void *)0xf;
    local_50 = (void *)0x0;
    FUN_00401740(s_btn_open_009df190,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_68 + 4);
    if (piVar2 != (int *)0x0) {
      uVar3 = 0;
      goto LAB_006a5ce8;
    }
  }
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return;
  }
LAB_006a5d02:
  uStack_38 = 0xf;
  local_3c = 0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401740(s_lbl_imcome_009df1a0,10);
  (**(code **)(*DAT_00b5adc4 + 0x40))();
  FUN_00401740(&DAT_009df19c,2);
  uVar3 = FUN_00404230(&pvStack_34);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_50);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(uVar3);
  }
  if (0xf < uStack_20) {
    _free(pvStack_34);
    return;
  }
  uStack_20 = 0xf;
  uStack_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  if (unaff_EBX < (void *)0x10) {
    return;
  }
  _free(pvStack_6c);
  return;
}


// ==== FUN_006a5dd0 @ 0x006a5dd0 ====

void FUN_006a5dd0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *unaff_ESI;
  void *local_38;
  undefined1 local_34 [8];
  uint uStack_2c;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20 [3];
  undefined4 uStack_14;
  uint uStack_10;
  
  local_20[0] = 0xf;
  local_24 = (void *)0x0;
  local_34[0] = 0;
  FUN_00401740(s_pan_store_2_009df1ac,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_lbl_pcname_009df1b8,10);
  uVar2 = (**(code **)(*DAT_00b5adc4 + 0x48))(local_20);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_20 + -8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(uVar2);
  }
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  uStack_10 = 0xf;
  if (uStack_2c < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_006a5ec0 @ 0x006a5ec0 ====

int FUN_006a5ec0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009df1cd,0);
    return unaff_retaddr;
  }
  (**(code **)(*piVar1 + 0x30))();
  uVar2 = FUN_00550150();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(uVar2,0,0xffffffff);
  return unaff_retaddr;
}


// ==== FUN_006a5f30 @ 0x006a5f30 ====

void FUN_006a5f30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009df284;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006a5f80 @ 0x006a5f80 ====

void FUN_006a5f80(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint in_ECX;
  uint unaff_ESI;
  uint uStack_24;
  uint local_20;
  void *pvStack_1c;
  uint uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  local_20 = in_ECX;
  iVar3 = (**(code **)(*DAT_00b5adc4 + 8))();
  if (iVar3 == 1) {
    FUN_006a5dd0();
  }
  else {
    FUN_006a5a30();
  }
  if (*(void **)(in_ECX + 0xc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xc));
    return;
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  uVar4 = (**(code **)(*DAT_00b5adc4 + 0x28))();
  uVar1 = local_20;
  while (uVar4 != 0) {
    uStack_24 = uStack_24 & 0xff000000;
    cVar2 = (**(code **)(*DAT_00b5adc4 + 0x30))(uVar4,&uStack_24);
    if (cVar2 != '\0') {
      pvStack_1c = (void *)(unaff_ESI >> 0x10 & 0xff);
      local_20 = unaff_ESI >> 8 & 0xff;
      iVar3 = *(int *)(in_ECX + 0xc);
      uStack_18 = 0xffffffff;
      uStack_24 = uVar4;
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x14) - iVar3 >> 4) <=
          (uint)(*(int *)(in_ECX + 0x10) - iVar3 >> 4))) {
        FUN_00680c50(*(undefined4 *)(in_ECX + 0x10),1,&uStack_24);
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x10);
        FUN_00680b80(iVar3,1,&uStack_24,in_ECX + 8,uVar1);
        *(int *)(in_ECX + 0x10) = iVar3 + 0x10;
      }
    }
    uVar4 = (**(code **)(*DAT_00b5adc4 + 0x2c))();
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  FUN_00401740(s_itemlist_009df1c4,8);
  piVar5 = (int *)(**(code **)(**(int **)(local_20 + 4) + 0x34))(&pvStack_1c);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x30))();
    FUN_005817e0(in_ECX + 8,0);
  }
  return;
}


// ==== FUN_006a6100 @ 0x006a6100 ====

void FUN_006a6100(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b5340;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[0xe] = 0xf;
    puVar1[0xd] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    *(undefined2 *)(puVar1 + 0x13) = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 10000;
  }
  uVar2 = (**(code **)(*in_ECX + 0x14))();
  puVar1[0x14] = uVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_ui_sellprice_txt_009df230,0x10);
  FUN_00401660(auStack_1c,0,0xffffffff);
  if (uStack_4 < 0x10) {
    *(undefined2 *)(puVar1 + 0x13) = 0xc00;
    FUN_00797a20(puVar1);
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_006a61c0 @ 0x006a61c0 ====

void FUN_006a61c0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b5340;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[0xe] = 0xf;
    puVar1[0xd] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    *(undefined2 *)(puVar1 + 0x13) = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 10000;
  }
  uVar2 = (**(code **)(*in_ECX + 0x14))();
  puVar1[0x14] = uVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_ui_buyitem_txt_009df244,0xe);
  FUN_00401660(auStack_1c,0,0xffffffff);
  if (uStack_4 < 0x10) {
    *(undefined2 *)(puVar1 + 0x13) = 0xc01;
    FUN_00797a20(puVar1);
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_006a6280 @ 0x006a6280 ====

void FUN_006a6280(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Auction_ui_auctionwnd_t_009df120,0x22);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006a5f80();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006a6300 @ 0x006a6300 ====

undefined4 FUN_006a6300(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70300002) {
    FUN_006a5f80();
    return 1;
  }
  if (iVar1 == 0x70300003) {
    FUN_006a6100(param_1);
    return 1;
  }
  if (iVar1 == 0x70300005) {
    FUN_006a61c0();
    return 1;
  }
  return 0;
}


// ==== FUN_006a6360 @ 0x006a6360 ====

void FUN_006a6360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009df284;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[1] = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    FUN_006a6280();
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006a63a0 @ 0x006a63a0 ====

undefined4 FUN_006a63a0(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [28];
  undefined1 local_1c [28];
  
  uVar1 = param_2;
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009df1d0,8);
      if ((iVar4 == 0) || (cVar2 = FUN_004036a0(uVar1,s_btn_close_009df1dc), cVar2 != '\0')) {
        (**(code **)(*DAT_00b5adc4 + 0x18))();
        return 1;
      }
      cVar2 = FUN_004036a0(uVar1,s_btn_open_009df1e8);
      if (cVar2 != '\0') {
        FUN_00401830(s_edt_storename_009df1f4);
        FUN_006a5ec0(local_38,local_1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_004036a0(uVar1,s_btn_get_009df228);
      if (cVar2 == '\0') {
        return 0;
      }
      (**(code **)(*DAT_00b5adc4 + 0x44))();
      return 1;
    }
  }
  else if (param_1 == 10) {
    if ((param_3 == 1) && (cVar2 = FUN_006a5940(param_2,param_4), cVar2 != '\0')) {
      return 1;
    }
  }
  else if (param_1 == 0xf) {
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    FUN_00404fb0(param_2,0x5f,local_48);
    if (param_3 == 1) {
      param_2 = param_2 & 0xff000000;
      uVar5 = FUN_00405d30(1);
      uVar3 = thunk_FUN_00796f50(uVar5);
      param_2._0_2_ = CONCAT11(uVar3,(undefined1)param_2);
      uVar5 = FUN_00405d30(2);
      uVar3 = thunk_FUN_00796f50(uVar5);
      param_2._0_3_ = CONCAT12(uVar3,(undefined2)param_2);
      (**(code **)(*DAT_00b5adc4 + 0x20))(&param_2);
    }
    FUN_00406250();
    return 1;
  }
  return 0;
}


// ==== FUN_006a66b0 @ 0x006a66b0 ====

void FUN_006a66b0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009df284;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[3] != (void *)0x0) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a6710 @ 0x006a6710 ====

undefined4 FUN_006a6710(void)

{
  return 0x30030110;
}


// ==== FUN_006a6720 @ 0x006a6720 ====

undefined4 FUN_006a6720(void)

{
  return 0xa0000000;
}


// ==== FUN_006a6730 @ 0x006a6730 ====

void FUN_006a6730(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x006a673c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006a6740 @ 0x006a6740 ====

undefined1 FUN_006a6740(void)

{
  return 0;
}


// ==== FUN_006a6750 @ 0x006a6750 ====

void FUN_006a6750(char param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (param_1 != '\x01') {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return;
    }
    *puVar1 = &PTR_FUN_009b629c;
    FUN_00797a20(puVar1);
    return;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b6288;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006a67b0 @ 0x006a67b0 ====

void FUN_006a67b0(char param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (param_1 != '\x01') {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return;
    }
    *puVar1 = &PTR_FUN_009b6274;
    FUN_00797a20(puVar1);
    return;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b6260;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006a68d0 @ 0x006a68d0 ====

void FUN_006a68d0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00579b10(param_1);
    }
  }
  return;
}


// ==== FUN_006a6960 @ 0x006a6960 ====

float10 FUN_006a6960(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      fVar3 = (float10)FUN_005796d0();
      return fVar3;
    }
  }
  return (float10)DAT_0099cdc8;
}


// ==== FUN_006a6990 @ 0x006a6990 ====

float10 FUN_006a6990(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      fVar3 = (float10)FUN_005796c0();
      return fVar3;
    }
  }
  return (float10)DAT_0099cdc8;
}


// ==== FUN_006a69c0 @ 0x006a69c0 ====

void FUN_006a69c0(void *param_1)

{
  int *piVar1;
  int in_ECX;
  void *unaff_retaddr;
  uint in_stack_00000014;
  uint in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  if (piVar1 == (int *)0x0) {
    if (0xf < in_stack_00000018) {
      _free(param_1);
      return;
    }
  }
  else {
    (**(code **)(*piVar1 + 0x44))(in_stack_0000001c);
    if (0xf < in_stack_00000014) {
      _free(unaff_retaddr);
      return;
    }
  }
  return;
}


// ==== FUN_006a6a10 @ 0x006a6a10 ====

void FUN_006a6a10(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_3a [26];
  void *pvStack_20;
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_005041e0(uVar2);
    (**(code **)(*piVar1 + 0xc))(auStack_3a + -6);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_006a6a70 @ 0x006a6a70 ====

void FUN_006a6a70(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_3a [26];
  void *pvStack_20;
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_005041e0(uVar2);
    (**(code **)(*piVar1 + 0xc))(auStack_3a + -6);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_006a6ad0 @ 0x006a6ad0 ====

void FUN_006a6ad0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  BOOL BVar5;
  LONG LVar6;
  undefined4 *puVar7;
  int in_ECX;
  DEVMODEA *pDVar8;
  undefined4 *puVar9;
  char cStack_131;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined1 uStack_11c;
  undefined1 auStack_118 [4];
  void *pvStack_114;
  undefined4 uStack_104;
  uint uStack_100;
  undefined1 auStack_fc [4];
  void *pvStack_f8;
  undefined4 uStack_e8;
  uint uStack_e4;
  undefined1 auStack_e0 [4];
  void *pvStack_dc;
  undefined4 uStack_cc;
  uint uStack_c8;
  undefined1 auStack_c4 [4];
  void *pvStack_c0;
  undefined4 uStack_b0;
  uint uStack_ac;
  DEVMODEA DStack_a8;
  
  if ((((*(int *)(in_ECX + 0xcc) != *(int *)(in_ECX + 0x68)) ||
       (*(int *)(in_ECX + 0xd0) != *(int *)(in_ECX + 0x6c))) ||
      (*(char *)(in_ECX + 0xd8) != *(char *)(in_ECX + 0x74))) ||
     (*(char *)(in_ECX + 0x81) != *(char *)(in_ECX + 0x1d))) {
    iVar4 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if (iVar4 == 1) {
      pDVar8 = &DStack_a8;
      for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
        pDVar8->dmDeviceName[0] = '\0';
        pDVar8->dmDeviceName[1] = '\0';
        pDVar8->dmDeviceName[2] = '\0';
        pDVar8->dmDeviceName[3] = '\0';
        pDVar8 = (DEVMODEA *)(pDVar8->dmDeviceName + 4);
      }
      BVar5 = EnumDisplaySettingsA((LPCSTR)0x0,0xffffffff,&DStack_a8);
      if (BVar5 == 0) {
        FUN_00401830(s_EnumDisplaySettings__NULL__ENUM__009dfa90);
        FUN_00406880(auStack_e0);
        if (uStack_c8 < 0x10) {
          uStack_c8 = 0xf;
          uStack_cc = 0;
          pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        _free(pvStack_dc);
        return;
      }
      DStack_a8.dmPelsWidth = *(DWORD *)(in_ECX + 0x68);
      DStack_a8.dmPelsHeight = *(DWORD *)(in_ECX + 0x6c);
      LVar6 = ChangeDisplaySettingsA(&DStack_a8,4);
      if (LVar6 != 0) {
        FUN_00401830(s_ChangeDisplaySettings___dmSettin_009dfad0);
        FUN_00406880(auStack_fc);
        if (uStack_e4 < 0x10) {
          uStack_e4 = 0xf;
          uStack_e8 = 0;
          pvStack_f8 = (void *)((uint)pvStack_f8 & 0xffffff00);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        _free(pvStack_f8);
        return;
      }
      *(undefined1 *)(in_ECX + 0x1d) = 0;
    }
    else if ((iVar4 == 2) || (iVar4 == 4)) {
      if (*(char *)(in_ECX + 0x1d) == '\x01') {
        pDVar8 = &DStack_a8;
        for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
          pDVar8->dmDeviceName[0] = '\0';
          pDVar8->dmDeviceName[1] = '\0';
          pDVar8->dmDeviceName[2] = '\0';
          pDVar8->dmDeviceName[3] = '\0';
          pDVar8 = (DEVMODEA *)(pDVar8->dmDeviceName + 4);
        }
        BVar5 = EnumDisplaySettingsA((LPCSTR)0x0,0xffffffff,&DStack_a8);
        if (BVar5 == 0) {
          FUN_00401830(s_EnumDisplaySettings__NULL__ENUM__009dfb20);
          FUN_00406880(auStack_c4);
          if (uStack_ac < 0x10) {
            uStack_ac = 0xf;
            uStack_b0 = 0;
            pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          _free(pvStack_c0);
          return;
        }
        DStack_a8.dmPelsWidth = *(DWORD *)(in_ECX + 0x68);
        DStack_a8.dmPelsHeight = *(DWORD *)(in_ECX + 0x6c);
        LVar6 = ChangeDisplaySettingsA(&DStack_a8,4);
        if (LVar6 != 0) {
          FUN_00401830(s_ChangeDisplaySettings___dmSettin_009dfb60);
          FUN_00406880(auStack_118);
          if (uStack_100 < 0x10) {
            uStack_100 = 0xf;
            uStack_104 = 0;
            pvStack_114 = (void *)((uint)pvStack_114 & 0xffffff00);
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          _free(pvStack_114);
          return;
        }
      }
      else {
        uStack_11c = *(undefined1 *)(in_ECX + 0x74);
        uStack_124 = *(undefined4 *)(in_ECX + 0x68);
        uStack_120 = *(undefined4 *)(in_ECX + 0x6c);
        cStack_131 = '\0';
        (**(code **)(*DAT_00b5b144 + 8))(&uStack_130,&uStack_124,&cStack_131);
        if (cStack_131 == '\0') {
          iVar4 = *DAT_00b5ad0c;
          FUN_00401830(&DAT_009dfbb0);
          (**(code **)(iVar4 + 0x28))(2);
        }
        *(undefined4 *)(in_ECX + 0x68) = uStack_130;
        *(undefined4 *)(in_ECX + 0x6c) = uStack_12c;
        ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
      }
    }
    else if (*(char *)(in_ECX + 0x1d) == '\0') {
      uStack_11c = *(undefined1 *)(in_ECX + 0x74);
      uStack_120 = *(undefined4 *)(in_ECX + 0x6c);
      uStack_124 = *(undefined4 *)(in_ECX + 0x68);
      cStack_131 = '\0';
      (**(code **)(*DAT_00b5b144 + 8))(&uStack_130,&uStack_124,&cStack_131);
      if (cStack_131 == '\0') {
        iVar4 = *DAT_00b5ad0c;
        FUN_00401830(&DAT_009dfbf8);
        (**(code **)(iVar4 + 0x28))(2);
      }
      *(undefined4 *)(in_ECX + 0x68) = uStack_130;
      *(undefined4 *)(in_ECX + 0x6c) = uStack_12c;
    }
    uVar1 = *(undefined4 *)(in_ECX + 0x68);
    uVar2 = *(undefined4 *)(in_ECX + 0x6c);
    uStack_128._0_2_ = CONCAT11(*(undefined1 *)(in_ECX + 0x1d),*(undefined1 *)(in_ECX + 0x74));
    puVar7 = operator_new(0x10);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7[1] = uVar1;
      puVar7[2] = uVar2;
      *puVar7 = &PTR_FUN_009dfcbc;
      puVar7[3] = uStack_128;
    }
    FUN_00797a20(puVar7);
  }
  (**(code **)(*DAT_00b5a6e4 + 0x10))((undefined4 *)(in_ECX + 0x18));
  puVar7 = (undefined4 *)(in_ECX + 0x18);
  puVar9 = (undefined4 *)(in_ECX + 0x7c);
  for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  return;
}


// ==== FUN_006a6e50 @ 0x006a6e50 ====

void FUN_006a6e50(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint uStack_6c;
  int iStack_68;
  char cStack_5c;
  int *piStack_54;
  int *piStack_50;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  void *local_40;
  undefined1 local_3c;
  undefined4 uStack_34;
  uint uStack_30;
  uint local_2c;
  uint local_28;
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  local_28 = 0xf;
  local_2c = 0;
  local_3c = 0;
  FUN_00401740(s_com_display_009df614,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_40);
  if (piVar3 == (int *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (**(code **)(*piVar3 + 0x30))();
  }
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  if (iVar5 != 0) {
    FUN_00578750(1);
    (**(code **)(*DAT_00b5b144 + 4))(&piStack_54);
    uVar6 = 0;
    uStack_6c = 0;
    piVar3 = piStack_54;
    if (piStack_54 != piStack_50) {
      do {
        iVar5 = *piVar3;
        iVar1 = piVar3[1];
        iVar2 = piVar3[2];
        uStack_c = 0xf;
        uStack_10 = 0;
        pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
        local_2c = uVar6;
        local_28 = uVar6;
        FUN_00401740(s__d____d___d__009df620,0xc);
        uVar4 = FUN_00404230(auStack_48);
        FUN_00401660(uVar4,0,0xffffffff);
        if (0xf < uStack_30) {
          _free(pvStack_44);
          return;
        }
        uStack_30 = 0xf;
        uStack_34 = 0;
        pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
        FUN_00577d70(&local_2c,0);
        if (((iVar5 == *(int *)(iStack_68 + 0x68)) && (iVar1 == *(int *)(iStack_68 + 0x6c))) &&
           (cStack_5c = (char)iVar2, cStack_5c == *(char *)(iStack_68 + 0x74))) {
          uStack_6c = local_28;
        }
        if (0xf < uStack_c) {
          _free(pvStack_20);
          return;
        }
        piVar3 = piVar3 + 3;
        uVar6 = uVar6 + 1;
        uStack_c = 0xf;
        uStack_10 = 0;
        pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      } while (piVar3 != piStack_50);
    }
    FUN_00578700();
    FUN_00577df0(uStack_6c);
    if (piStack_54 != (int *)0x0) {
      _free(piStack_54);
      return;
    }
  }
  return;
}


// ==== FUN_006a7030 @ 0x006a7030 ====

void FUN_006a7030(void)

{
  char cVar1;
  void *_Memory;
  void *_Memory_00;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  undefined4 in_EDX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  float fVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  void **ppvVar11;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 in_stack_ffffffa8;
  ulonglong uVar12;
  uint in_stack_ffffffb0;
  undefined4 uVar13;
  undefined4 uStack_38;
  undefined4 uStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffa8 >> 0x20);
  if (DAT_00b5a97c != (int *)0x0) {
    uStack_38 = (void *)CONCAT31((int3)((uint)in_EDX >> 8),*(undefined1 *)(in_ECX + 0x73));
    (**(code **)(*DAT_00b5a97c + 0x38))();
  }
  uStack_38 = (void *)(uint)(*(char *)(in_ECX + 0x1a) != '\0');
  uVar8 = in_stack_ffffffb0 & 0xffffff00;
  FUN_00401740();
  uVar9 = CONCAT44(uVar2,&pvStack_1c);
  uStack_38 = (void *)FUN_00404230(&pvStack_1c,uVar2,uVar8);
  (**(code **)(*DAT_00b5a688 + 4))();
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uVar12 = CONCAT35((int3)((ulonglong)uVar9 >> 0x28),(uint5)(uint)uVar9);
  FUN_00401740(s_rc_specularmap__d_009df9f0,0x11);
  ppvVar11 = &pvStack_20;
  _Memory = (void *)FUN_00404230();
  (**(code **)(*DAT_00b5a688 + 4))();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uVar12 = uVar12 & 0xffffffffffffff00;
  FUN_00401740(s_rc_bumpmap__d_009dfa04,0xd);
  uVar9 = CONCAT44(ppvVar11,&uStack_24);
  _Memory_00 = (void *)FUN_00404230(&uStack_24,ppvVar11,uVar12);
  (**(code **)(*DAT_00b5a688 + 4))();
  if (0xf < uStack_10) {
    _free(uStack_24);
    return;
  }
  uVar10 = CONCAT35((int3)((ulonglong)uVar9 >> 0x28),(uint5)(uint)uVar9);
  FUN_00401740(s_ds_lodlevel__d_009dfa14,0xe);
  uVar8 = (int)register0x00000010 - 0x28;
  uVar2 = FUN_00404230(uVar8);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (0xf < uStack_14) {
    _free(unaff_EBX);
    return;
  }
  uVar4 = (uint)*(byte *)(in_ECX + 0x70);
  uVar13 = 0xf;
  uVar2 = 0;
  uVar10 = uVar10 & 0xffffffffffffff00;
  FUN_00401740(s_settracealone__d_009dfa24,0x10);
  uVar7 = (int)register0x00000010 - 0x2c;
  uVar2 = FUN_00404230(uVar7,uVar8,uVar10,uVar12,uVar2,uVar13,uVar4);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (0xf < uStack_18) {
    _free(unaff_EBP);
    return;
  }
  uVar8 = uVar8 & 0xffffff00;
  FUN_00401740(s_rc_covermap__d_009dfa38,0xe);
  iVar6 = (int)register0x00000010 + -0x30;
  uVar2 = FUN_00404230(iVar6,uVar7,uVar8);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if ((void *)0xf < pvStack_1c) {
    _free(unaff_ESI);
    return;
  }
  uVar7 = uVar7 & 0xffffff00;
  FUN_00401740(s_rc_shadowlevel__d_009dfa48,0x11);
  uVar2 = FUN_00404230((int)register0x00000010 + -0x34,iVar6,uVar7);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if ((void *)0xf < pvStack_20) {
    _free(unaff_EDI);
    return;
  }
  FUN_00401740(s_rc_gamma___2f_009dfa5c,0xd);
  FUN_00404230(&uStack_38);
  (**(code **)(*DAT_00b5a688 + 4))();
  if ((void *)0xf < uStack_24) {
    _free(uStack_38);
    return;
  }
  FUN_00401740(s_rc_waterlevel__d_009dfa6c,0x10);
  uVar2 = FUN_00404230((int)register0x00000010 + -0x3c);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if ((void *)0xf < unaff_EBX) {
    _free(_Memory);
    return;
  }
  FUN_00401740(s_ds_clipfar___2f_009dfa80,0xf);
  FUN_00404230((int)register0x00000010 + -0x40);
  (**(code **)(*DAT_00b5a688 + 4))();
  if ((void *)0xf < unaff_EBP) {
    _free(_Memory_00);
    return;
  }
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    fVar5 = *(float *)(in_ECX + 0x30);
    *puVar3 = &PTR_FUN_009dfca8;
    puVar3[1] = (int)ROUND(fVar5);
  }
  FUN_00797a20(puVar3);
  fVar5 = *(float *)(in_ECX + 0x2c) * DAT_009a09b8;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009dc704;
    puVar3[1] = fVar5;
    puVar3[2] = 0;
    puVar3[3] = 2;
  }
  FUN_00797a20(puVar3);
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    if (*(char *)(in_ECX + 0x1c) == '\x01') {
      (**(code **)(*DAT_00b5ae88 + 8))();
    }
    else {
      (**(code **)(*DAT_00b5ae88 + 0xc))();
    }
    FUN_006a6750(*(undefined1 *)(in_ECX + 0x24));
    FUN_006a67b0(*(undefined1 *)(in_ECX + 0x25));
  }
  FUN_006a6ad0();
  return;
}


// ==== FUN_006a7440 @ 0x006a7440 ====

/* WARNING: Removing unreachable block (ram,0x006a7521) */

void FUN_006a7440(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_3e [2];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d1002b);
    FUN_00401660(uVar3,0,0xffffffff);
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_BLINK_009dfc40,5);
    FUN_00404440(auStack_3e + -6,auStack_28,uStack_4);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uVar3 = FUN_00405bd0(auStack_28,unaff_retaddr,auStack_3e + -6);
    FUN_0055a260(uVar3);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  return;
}


// ==== FUN_006a7540 @ 0x006a7540 ====

void FUN_006a7540(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *******pppppppuVar5;
  int in_ECX;
  void *unaff_EBP;
  int iVar6;
  int unaff_retaddr;
  undefined1 auStack_56 [2];
  undefined4 *******local_54;
  undefined4 *******local_50 [2];
  uint uStack_48;
  undefined4 uStack_44;
  uint local_40;
  uint local_3c;
  void *local_38 [4];
  undefined4 uStack_28;
  void *apvStack_24 [4];
  undefined4 uStack_14;
  uint uStack_10;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  iVar6 = *(int *)(in_ECX + 0xc);
  if (iVar6 != iVar1) {
    while( true ) {
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (undefined4 *******)((uint)local_50[0] & 0xffffff00);
      FUN_00401660(iVar6,0,0xffffffff);
      iVar4 = **(int **)(in_ECX + 4);
      uVar2 = FUN_004022a0(local_38,&DAT_009dfc48,&local_54);
      piVar3 = (int *)(**(code **)(iVar4 + 0x34))(uVar2);
      if ((void *)0xf < apvStack_24[0]) {
        _free(local_38[0]);
        return;
      }
      apvStack_24[0] = (void *)0xf;
      uStack_28 = 0;
      local_38[0] = (void *)((uint)local_38[0] & 0xffffff00);
      if (piVar3 == (int *)0x0) break;
      pppppppuVar5 = local_54;
      if (local_40 < 0x10) {
        pppppppuVar5 = &local_54;
      }
      iVar4 = FUN_00403620(0,*(undefined4 *)(unaff_retaddr + 0x14),pppppppuVar5,uStack_44);
      if (iVar4 == 0) {
        (**(code **)(*piVar3 + 0x24))(1);
      }
      else {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      iVar4 = **(int **)(in_ECX + 4);
      uVar2 = FUN_004022a0(apvStack_24,&DAT_009dfc50,auStack_56 + -6);
      piVar3 = (int *)(**(code **)(iVar4 + 0x34))(uVar2);
      if (0xf < uStack_10) {
        _free(apvStack_24[0]);
        return;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      apvStack_24[0] = (void *)((uint)apvStack_24[0] & 0xffffff00);
      if (piVar3 == (int *)0x0) {
        if (uStack_48 < 0x10) {
          return;
        }
        _free(unaff_EBP);
        return;
      }
      (**(code **)(*piVar3 + 0x30))();
      pppppppuVar5 = local_50[0];
      if (local_3c < 0x10) {
        pppppppuVar5 = local_50;
      }
      iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),pppppppuVar5,local_40);
      FUN_00558730(iVar4 == 0);
      if (0xf < local_3c) {
        _free(local_50[0]);
        return;
      }
      iVar6 = iVar6 + 0x1c;
      local_50[0] = (undefined4 *******)((uint)local_50[0] & 0xffffff00);
      if (iVar6 == iVar1) {
        return;
      }
    }
    if (0xf < local_40) {
      _free(local_54);
      return;
    }
  }
  return;
}


// ==== FUN_006a7720 @ 0x006a7720 ====

uint FUN_006a7720(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  int in_ECX;
  void *local_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  char acStack_40 [32];
  void *pvStack_20;
  uint uStack_c;
  
  iVar1 = **(int **)(in_ECX + 4);
  uVar2 = FUN_00402220(local_58,param_1,s__check_009dfc58);
  piVar3 = (int *)(**(code **)(iVar1 + 0x34))(uVar2);
  if (0xf < uStack_44) {
    _free(local_58[0]);
    return extraout_EAX;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(*piVar3 + 0x10))();
  FUN_005041e0(uVar2);
  acStack_40[0] = acStack_40[0] != '\x01';
  (**(code **)(*piVar3 + 0xc))(acStack_40);
  if (uStack_c < 0x10) {
    return uStack_44 & 0xff;
  }
  _free(pvStack_20);
  return extraout_EAX_00;
}


// ==== FUN_006a77d0 @ 0x006a77d0 ====

undefined4 FUN_006a77d0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  int iVar5;
  undefined4 extraout_EAX_00;
  undefined4 uVar6;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *pvStack_5c;
  void *local_58 [3];
  undefined4 uStack_4c;
  uint uStack_48;
  uint auStack_44 [2];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_30;
  void *pvStack_24;
  uint uStack_10;
  undefined4 uStack_8;
  
  iVar5 = **(int **)(in_ECX + 4);
  uVar3 = FUN_004022a0(local_58,s_pan_trace__009dfc60,param_1);
  piVar4 = (int *)(**(code **)(iVar5 + 0x34))(uVar3);
  if (0xf < auStack_44[0]) {
    _free(local_58[0]);
    return extraout_EAX;
  }
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  iVar5 = (**(code **)(*piVar4 + 0x10))();
  uVar3 = *(undefined4 *)(iVar5 + 8);
  uVar1 = *(undefined4 *)(iVar5 + 0xc);
  uVar2 = *(undefined4 *)(iVar5 + 0x10);
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
  FUN_00401740(s_pan_trace_check_009dfc6c,0xf);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_5c);
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return extraout_EAX_00;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  uVar6 = (**(code **)(*piVar4 + 0x10))();
  FUN_005041e0(uVar6);
  uStack_3c = uVar3;
  uStack_38 = uVar1;
  uStack_30 = uVar2;
  (**(code **)(*piVar4 + 0xc))(auStack_44);
  uVar3 = thunk_FUN_00796f80(uStack_8);
  if (uStack_10 < 0x10) {
    return uVar3;
  }
  _free(pvStack_24);
  return extraout_EAX_01;
}


// ==== FUN_006a7930 @ 0x006a7930 ====

undefined4 FUN_006a7930(undefined4 param_1)

{
  int iVar1;
  void *_Memory;
  undefined4 uVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  int iVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *local_58;
  uint uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint auStack_44 [3];
  int iStack_38;
  int iStack_30;
  void *pvStack_24;
  uint uStack_10;
  undefined4 uStack_8;
  
  iVar1 = **(int **)(in_ECX + 4);
  uVar2 = FUN_004022a0(&local_58,s_pan_control__009dfc7c,param_1);
  piVar3 = (int *)(**(code **)(iVar1 + 0x34))(uVar2);
  if (0xf < auStack_44[0]) {
    _free(local_58);
    return extraout_EAX;
  }
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  _Memory = *(void **)(iVar4 + 8);
  iVar1 = *(int *)(iVar4 + 0xc);
  uStack_54 = *(undefined4 *)(iVar4 + 0x10);
  uStack_50 = *(undefined4 *)(iVar4 + 0x14);
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_pan_control_check_009dfc8c,0x11);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_44 + -6);
  if (0xf < uStack_48) {
    _free(_Memory);
    return extraout_EAX_00;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  uVar2 = (**(code **)(*piVar3 + 0x10))();
  FUN_005041e0(uVar2);
  iStack_30 = iStack_30 - iStack_38;
  iVar1 = iVar1 + -7;
  if (iStack_38 != iVar1) {
    iStack_38 = iVar1;
  }
  iStack_30 = iStack_38 + iStack_30;
  (**(code **)(*piVar3 + 0xc))(auStack_44);
  uVar2 = thunk_FUN_00796f50(uStack_8);
  if (uStack_10 < 0x10) {
    return uVar2;
  }
  _free(pvStack_24);
  return extraout_EAX_01;
}


// ==== FUN_006a7a80 @ 0x006a7a80 ====

/* WARNING: Removing unreachable block (ram,0x006a8806) */
/* WARNING: Removing unreachable block (ram,0x006a877f) */

void FUN_006a7a80(void)

{
  void *pvVar1;
  void *_Memory;
  undefined1 uVar2;
  float fVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined2 in_FPUControlWord;
  void *_Memory_00;
  undefined1 auStack_1a4 [8];
  void **ppvVar10;
  void **_Memory_01;
  void **_Memory_02;
  void **_Memory_03;
  void **_Memory_04;
  void **ppvVar11;
  uint uVar12;
  undefined4 uStack_158;
  void *pvStack_154;
  void *pvStack_150;
  void *pvStack_14c;
  void *pvStack_148;
  uint uStack_144;
  uint uStack_140;
  uint uStack_13c;
  uint uStack_138;
  void *pvStack_134;
  void *pvStack_130;
  void *apvStack_12c [2];
  undefined4 uStack_124;
  uint uStack_120;
  uint uStack_11c;
  uint uStack_118;
  void *pvStack_114;
  void *pvStack_110;
  undefined4 uStack_104;
  uint uStack_100;
  uint uStack_fc;
  void *pvStack_f8;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  uint uStack_e4;
  void *pvStack_dc;
  undefined4 uStack_cc;
  uint uStack_c8;
  void *pvStack_c0;
  undefined4 uStack_b0;
  uint uStack_ac;
  void *pvStack_a4;
  undefined4 uStack_94;
  uint uStack_90;
  void *pvStack_88;
  undefined4 uStack_78;
  uint uStack_74;
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  void *pvStack_54;
  undefined1 uStack_50;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar8 = puVar4;
  puVar9 = (undefined4 *)(in_ECX + 0x18);
  for (iVar7 = 0x19; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar8 = (undefined4 *)(in_ECX + 0x7c);
  for (iVar7 = 0x19; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  iVar7 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar7 == 1) {
    uStack_c8 = 0xf;
    uStack_cc = 0;
    pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
    FUN_00401740();
    FUN_006a6a10();
    if (0xf < uStack_c8) {
      _free(pvStack_dc);
      return;
    }
    uStack_c8 = 0xf;
    uStack_cc = 0;
    pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
    uStack_90 = 0xf;
    uStack_94 = 0;
    pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
    FUN_00401740();
    FUN_006a6a10();
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_90 = 0xf;
    uStack_94 = 0;
    pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    FUN_00401740();
    FUN_006a6a10();
    if (0xf < uStack_20) {
      _free(pvStack_34);
      return;
    }
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401740();
    FUN_006a6a10();
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    uStack_11c = 0xf;
    uStack_120 = 0;
    pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
    FUN_00401740();
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x44))();
    }
    if (0xf < uStack_120) {
      _free(pvStack_134);
      return;
    }
    uStack_120 = 0xf;
    uStack_124 = 0;
    pvStack_134 = (void *)((uint)pvStack_134 & 0xffffff00);
    uStack_140 = 0xf;
    uStack_144 = 0;
    pvStack_154 = (void *)((uint)pvStack_154 & 0xffffff00);
    FUN_00401740();
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x44))();
    }
    if (0xf < uStack_13c) {
      pvStack_f8 = pvStack_150;
      goto LAB_006a80af;
    }
  }
  else {
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740();
    FUN_006a6a10();
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    if (*(char *)(in_ECX + 0x19) == '\x01') {
      uStack_ac = 0xf;
      uStack_b0 = 0;
      pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
      FUN_00401740();
      FUN_006a6a10();
      if (0xf < uStack_ac) {
        _free(pvStack_c0);
        return;
      }
      uStack_ac = 0xf;
      uStack_b0 = 0;
      pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
      uStack_74 = 0xf;
      uStack_78 = 0;
      pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
      FUN_00401740();
      FUN_006a6a10();
      if (0xf < uStack_74) {
        _free(pvStack_88);
        return;
      }
      uStack_74 = 0xf;
      uStack_78 = 0;
      pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
      uStack_3c = 0xf;
      uStack_40 = 0;
      uStack_50 = 0;
      FUN_00401740();
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x44))();
      }
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      uStack_e8 = 0xf;
      uStack_ec = 0;
      uStack_fc = uStack_fc & 0xffffff00;
      FUN_00401740();
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x44))();
      }
      if (0xf < uStack_e4) goto LAB_006a80af;
    }
    else {
      uStack_100 = 0xf;
      uStack_104 = 0;
      pvStack_114 = (void *)((uint)pvStack_114 & 0xffffff00);
      FUN_00401740();
      FUN_006a6a10();
      if (0xf < uStack_100) {
        pvStack_f8 = pvStack_114;
LAB_006a80af:
        _free(pvStack_f8);
        return;
      }
    }
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  uStack_13c = 0xf;
  uStack_140 = 0;
  pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
  FUN_00401740();
  FUN_006a6a10();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  FUN_00401740(&DAT_009df530,2);
  FUN_00404230(&pvStack_154);
  FUN_006a77d0();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  FUN_006a6e50();
  FUN_00401740(&DAT_009df534,2);
  FUN_00404230(&pvStack_154);
  FUN_006a7930();
  if (0xf < uStack_13c) {
    _free(pvStack_150);
    return;
  }
  FUN_00401830();
  uStack_138 = *(uint *)(in_ECX + 0x2c);
  ppvVar11 = &pvStack_154;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00579b10();
  }
  if (0xf < uStack_140) {
    _free(pvStack_154);
    return;
  }
  FUN_00401830();
  uStack_13c = CONCAT22(uStack_13c._2_2_,in_FPUControlWord);
  FUN_006a6a70();
  if (0xf < uStack_140) {
    _free(pvStack_154);
    return;
  }
  FUN_00401830();
  pvVar1 = *(void **)(in_ECX + 0x30);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00579b10();
  }
  if (0xf < uStack_144) {
    _free(uStack_158);
    return;
  }
  FUN_00401830();
  uStack_140 = CONCAT22(uStack_140._2_2_,in_FPUControlWord);
  FUN_006a6a70();
  if (0xf < uStack_144) {
    _free(uStack_158);
    return;
  }
  FUN_00401830();
  _Memory_00 = (void *)(*(float *)(in_ECX + 0x34) * DAT_0099de78);
  _Memory_04 = apvStack_12c + -0xc;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    thunk_FUN_005799c0();
  }
  if ((void *)0xf < pvStack_148) {
    _free(pvVar1);
    return;
  }
  FUN_00401830();
  pvVar1 = *(void **)(in_ECX + 0x60);
  _Memory_03 = apvStack_12c + -0xd;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    thunk_FUN_005799c0();
  }
  if ((void *)0xf < pvStack_14c) {
    _free(_Memory_00);
    return;
  }
  FUN_00401830();
  _Memory = *(void **)(in_ECX + 100);
  _Memory_02 = apvStack_12c + -0xe;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    thunk_FUN_005799c0();
  }
  if ((void *)0xf < pvStack_150) {
    _free(pvVar1);
    return;
  }
  FUN_00401830();
  FUN_00401830();
  FUN_00401830();
  _Memory_01 = apvStack_12c;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_005796b0();
  }
  ppvVar10 = &pvStack_14c;
  FUN_00401830(&DAT_009df5a0);
  uVar6 = FUN_00404230(&pvStack_114);
  FUN_006a7440(auStack_1a4 + 0x38,uVar6,ppvVar10);
  if (0xf < uStack_fc) {
    _free(pvStack_110);
    return;
  }
  uStack_fc = 0xf;
  uStack_100 = 0;
  pvStack_110 = (void *)((uint)pvStack_110 & 0xffffff00);
  if ((void *)0xf < pvStack_154) {
    _free(_Memory);
    return;
  }
  pvStack_154 = (void *)0xf;
  if (0xf < uStack_118) {
    _free(apvStack_12c[0]);
    return;
  }
  uStack_118 = 0xf;
  uStack_11c = 0;
  apvStack_12c[0] = (void *)((uint)apvStack_12c[0] & 0xffffff00);
  if ((void *)0xf < pvStack_134) {
    _free(pvStack_148);
    return;
  }
  FUN_00401830(&DAT_009df5b4);
  FUN_00401830(s_sld_mp_009df5b8);
  FUN_00401830(s_lbl_mpLimit_009df5c8);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_130);
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_005796b0();
  }
  ppvVar10 = &pvStack_150;
  FUN_00401830(&DAT_009df5c0);
  uVar6 = FUN_00404230(&uStack_118);
  FUN_006a7440(auStack_1a4 + 0x34,uVar6,ppvVar10);
  if (0xf < uStack_100) {
    _free(pvStack_114);
    return;
  }
  uStack_100 = 0xf;
  uStack_104 = 0;
  pvStack_114 = (void *)((uint)pvStack_114 & 0xffffff00);
  uVar12 = (uint)ppvVar11 & 0xffffff00;
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  if (0xf < uStack_138) {
    _free(pvStack_14c);
    return;
  }
  FUN_00401830(s_com_water_009df5d4);
  uVar2 = *(undefined1 *)(in_ECX + 0x76);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a4 + 0x34);
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00577df0(uVar2);
  }
  FUN_00401830(s_com_trace_009df5e0);
  uVar2 = *(undefined1 *)(in_ECX + 0x70);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a4 + 0x30);
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00577df0(uVar2);
  }
  if ((void *)0xf < _Memory_00) {
    _free(_Memory_04);
    return;
  }
  FUN_00401830(s_com_shadow_009df5ec);
  uVar2 = *(undefined1 *)(in_ECX + 0x77);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a4 + 0x2c);
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00577df0(uVar2);
  }
  if ((void *)0xf < pvVar1) {
    _free(_Memory_03);
    return;
  }
  FUN_00401830(s_com_lod_009df5f8);
  uVar2 = *(undefined1 *)(in_ECX + 0x78);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a4 + 0x28);
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00577df0(uVar2);
  }
  if (0xf < ((uint)_Memory & 0xffffff00)) {
    _free(_Memory_02);
    return;
  }
  fVar3 = (*(float *)(in_ECX + 0x38) - DAT_0099de7c) * DAT_009b02b0;
  FUN_00401830(s_com_far_009df600);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a4 + 0x24);
  if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x30))(), iVar7 != 0)) {
    FUN_00577df0((int)ROUND(fVar3));
  }
  if (uVar12 < 0x10) {
    FUN_00401830(s_btn_apply_009df608);
    FUN_006a69c0();
    return;
  }
  _free(_Memory_01);
  return;
}


// ==== FUN_006a8990 @ 0x006a8990 ====

undefined4 FUN_006a8990(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 0xc))();
  puVar3 = (undefined4 *)(in_ECX + 0x18);
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_006a7030();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009b624c;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_006a89f0 @ 0x006a89f0 ====

void FUN_006a89f0(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_ESI;
  
  *in_ECX = &PTR_FUN_009dfcd0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[3] == 0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_00405de0(in_ECX[3],in_ECX[4],in_ECX + 2,unaff_ESI);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006a8a50 @ 0x006a8a50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006a8a50(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int *in_ECX;
  float10 fVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 auStack_3c [4];
  undefined1 local_38 [24];
  undefined1 auStack_20 [4];
  undefined1 local_1c [28];
  
  if (param_1 == 1) {
    if (param_3 != 1) {
      return 0;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009df630,8);
    if ((iVar4 == 0) || (cVar2 = FUN_004036a0(param_2,s_btn_cancel_009df63c), cVar2 != '\0')) {
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_btn_ok_009df648);
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00b5a6e4 + 0x10))(in_ECX + 6);
      (**(code **)(*DAT_00b5a6e4 + 0x14))();
      FUN_006a7030();
      puVar5 = operator_new(4);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar5 = &PTR_FUN_009b624c;
      FUN_00797a20(puVar5);
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_btn_apply_009df650);
    if (cVar2 != '\0') {
      FUN_006a7030();
      return 1;
    }
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    FUN_00404fb0(param_2,0x5f,&local_54);
    cVar2 = FUN_004036a0(param_2,s_btn_screen_009df65c);
    if ((((cVar2 != '\0') || (cVar2 = FUN_004036a0(param_2,s_btn_screen2_009df668), cVar2 != '\0'))
        || (cVar2 = FUN_004036a0(param_2,s_btn_sound_009df674), cVar2 != '\0')) ||
       (((cVar2 = FUN_004036a0(param_2,s_btn_game_009df680), cVar2 != '\0' ||
         (cVar2 = FUN_004036a0(param_2,s_btn_see_009df68c), cVar2 != '\0')) ||
        (cVar2 = FUN_004036a0(param_2,s_btn_game2_009df694), cVar2 != '\0')))) {
      uVar6 = FUN_00405d30(1);
      FUN_006a7540(uVar6);
      FUN_00406250();
      return 1;
    }
LAB_006a8bf5:
    FUN_00406250();
    return 0;
  }
  if (param_1 != 0) {
    if (param_1 != 0x15) {
      if (param_1 != 0x14) {
        return 0;
      }
      if (param_3 != 7) {
        return 0;
      }
      cVar2 = FUN_004036a0(param_2,s_sld_gamma_009df91c);
      if (cVar2 != '\0') {
        fVar8 = (float10)FUN_006a6990(param_2);
        in_ECX[0xd] = (int)(float)(fVar8 * (float10)DAT_009a09b8);
        FUN_00401830(s_btn_apply_009df928);
        FUN_006a69c0();
        return 1;
      }
      cVar2 = FUN_004036a0(param_2,s_sld_sound_009df934);
      if (cVar2 != '\0') {
        fVar8 = (float10)FUN_006a6960(param_2);
        in_ECX[0xb] = (int)(float)fVar8;
        FUN_00401830(s_pan_nosound_check_009df940);
        FUN_006a6a70(local_1c,(int)ROUND((float)in_ECX[0xb]));
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_004036a0(param_2,s_sld_hp_009df960);
      if (cVar2 != '\0') {
        FUN_006a6990(param_2);
        FUN_00401830(&DAT_009df968);
        FUN_00401830(s_lbl_hpLimit_009df974);
        puVar10 = local_38;
        FUN_00401830(&DAT_009df96c);
        uVar6 = FUN_00404230(&local_54);
        FUN_006a7440(local_1c,uVar6,puVar10);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_004036a0(param_2,s_sld_mp_009df98c);
      if (cVar2 != '\0') {
        FUN_006a6990(param_2);
        FUN_00401830(&DAT_009df994);
        FUN_00401830(s_lbl_mpLimit_009df9a0);
        puVar10 = local_38;
        FUN_00401830(&DAT_009df998);
        uVar6 = FUN_00404230(&local_54);
        FUN_006a7440(local_1c,uVar6,puVar10);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_004036a0(param_2,s_sld_effect_009df9b8);
      if (cVar2 != '\0') {
        fVar8 = (float10)FUN_006a6960(param_2);
        in_ECX[0xc] = (int)(float)fVar8;
        FUN_00401830(s_pan_noeffect_check_009df9c4);
        FUN_006a6a70(local_1c,(int)ROUND((float)in_ECX[0xc]));
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    cVar2 = FUN_004036a0(param_2,s_com_display_009df890);
    if (cVar2 != '\0') {
      piVar7 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(param_2);
      if (piVar7 == (int *)0x0) {
        return 1;
      }
      iVar4 = (**(code **)(*piVar7 + 0x30))();
      if (iVar4 != 0) {
        FUN_005778b0(auStack_20);
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        FUN_00401830(&DAT_009df89c);
        FUN_00405160(auStack_20,auStack_3c,auStack_3c + -0x1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_com_shadow_009df8ac);
    if (cVar2 != '\0') {
      *(undefined1 *)((int)in_ECX + 0x77) = (undefined1)param_4;
      FUN_00401830(s_btn_apply_009df8b8);
      FUN_006a69c0();
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_com_water_009df8c4);
    if (cVar2 != '\0') {
      *(undefined1 *)((int)in_ECX + 0x76) = (undefined1)param_4;
      FUN_00401830(s_btn_apply_009df8d0);
      FUN_006a69c0();
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_com_trace_009df8dc);
    if (cVar2 != '\0') {
      *(undefined1 *)(in_ECX + 0x1c) = (undefined1)param_4;
      FUN_00401830(s_btn_apply_009df8e8);
      FUN_006a69c0();
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_com_lod_009df8f4);
    if (cVar2 != '\0') {
      *(undefined1 *)(in_ECX + 0x1e) = (undefined1)param_4;
      FUN_00401830(s_btn_apply_009df8fc);
      FUN_006a69c0();
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_com_far_009df908);
    if (cVar2 == '\0') {
      return 0;
    }
    fVar1 = (float)param_4;
    if (param_4 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    in_ECX[0xe] = (int)(fVar1 * DAT_0099de80 + DAT_0099de7c);
    FUN_00401830(s_btn_apply_009df910);
    FUN_006a69c0();
    return 1;
  }
  if (param_3 != 1) {
    return 0;
  }
  iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_pan_minihelp_009df6a0,0xc);
  if (iVar4 == 0) {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)(in_ECX + 7) = uVar3;
    FUN_00401830(s_btn_apply_009df6b0);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_trade_009df6bc);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)(in_ECX + 8) = uVar3;
    FUN_00401830(s_btn_apply_009df6c8);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_party_009df6d4);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x21) = uVar3;
    FUN_00401830(s_btn_apply_009df6e0);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_guild_009df6ec);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x22) = uVar3;
    FUN_00401830(s_btn_apply_009df6f8);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_friend_009df704);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x23) = uVar3;
    FUN_00401830(s_btn_apply_009df710);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_server_009df71c);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)(in_ECX + 9) = uVar3;
    FUN_00401830(s_btn_apply_009df728);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_reception_009df734);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x25) = uVar3;
    FUN_00401830(s_btn_apply_009df744);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_winmode_009df750);
  if (cVar2 != '\0') {
    cVar2 = FUN_006a7720(param_2);
    *(bool *)((int)in_ECX + 0x1d) = cVar2 == '\0';
    FUN_00401830(s_btn_apply_009df75c);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_bloom_009df768);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x1a) = uVar3;
    FUN_00401830(s_btn_apply_009df774);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_blood_009df780);
  if (cVar2 != '\0') {
    iVar4 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar4 == 1) || (*(char *)((int)in_ECX + 0x19) == '\x01')) {
      return 1;
    }
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)(in_ECX + 6) = uVar3;
    FUN_00401830(s_btn_apply_009df78c);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_specular_009df798);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x1b) = uVar3;
    FUN_00401830(s_btn_apply_009df7a8);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_cloud_009df7b4);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x79) = uVar3;
    FUN_00401830(s_btn_apply_009df7c0);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_bump_009df7cc);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x7a) = uVar3;
    FUN_00401830(s_btn_apply_009df7d8);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_pvp_009df7e4);
  if (cVar2 != '\0') {
    cVar2 = FUN_006a7720(param_2);
    *(bool *)((int)in_ECX + 0x27) = cVar2 == '\0';
    FUN_00401830(s_btn_apply_009df7ec);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_ppl_009df7f8);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)((int)in_ECX + 0x7b) = uVar3;
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_autodrink_009df800);
  if (cVar2 != '\0') {
    uVar3 = FUN_006a7720(param_2);
    *(undefined1 *)(in_ECX + 10) = uVar3;
    FUN_00401830(s_btn_apply_009df810);
    FUN_006a69c0();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_pan_mp3_009df81c);
  if (cVar2 == '\0') {
    cVar2 = FUN_004036a0(param_2,s_pan_nosound_009df830);
    if (cVar2 != '\0') {
      cVar2 = FUN_006a7720(param_2);
      if (cVar2 != '\0') {
        in_ECX[0xb] = 0;
        FUN_00401830(s_sld_sound_009df83c);
        FUN_006a68d0(local_38,in_ECX[0xb]);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00401830(s_btn_apply_009df848);
      FUN_006a69c0();
      return 1;
    }
    cVar2 = FUN_004036a0(param_2,s_pan_noeffect_009df854);
    if (cVar2 != '\0') {
      cVar2 = FUN_006a7720(param_2);
      if (cVar2 != '\0') {
        in_ECX[0xc] = 0;
        FUN_00401830(s_sld_effect_009df864);
        FUN_006a68d0(local_38,in_ECX[0xc]);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00401830(s_btn_apply_009df870);
      FUN_006a69c0();
      return 1;
    }
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    FUN_00404fb0(param_2,0x5f,&local_54);
    pcVar9 = s_control_009df87c;
    uVar6 = FUN_00405d30(1);
    cVar2 = FUN_004036a0(uVar6,pcVar9);
    if (cVar2 != '\0') {
      uVar6 = FUN_00405d30(2);
      uVar3 = FUN_006a7930(uVar6);
      *(undefined1 *)((int)in_ECX + 0x73) = uVar3;
      FUN_00401830(s_btn_apply_009df884);
      FUN_006a69c0();
      FUN_00406250();
      return 1;
    }
    goto LAB_006a8bf5;
  }
  cVar2 = FUN_006a7720(param_2);
  *(char *)(in_ECX + 0x16) = cVar2;
  if (cVar2 == '\0') {
    puVar5 = operator_new(4);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &PTR_FUN_009b45dc;
      goto LAB_006a908f;
    }
  }
  else {
    puVar5 = operator_new(4);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &PTR_FUN_009b6224;
      goto LAB_006a908f;
    }
  }
  puVar5 = (undefined4 *)0x0;
LAB_006a908f:
  FUN_00797a20(puVar5);
  FUN_00401830(s_btn_apply_009df824);
  FUN_006a69c0();
  return 1;
}


// ==== FUN_006a97a0 @ 0x006a97a0 ====

/* WARNING: Removing unreachable block (ram,0x006a9aeb) */
/* WARNING: Removing unreachable block (ram,0x006a9a59) */
/* WARNING: Removing unreachable block (ram,0x006a99b6) */
/* WARNING: Removing unreachable block (ram,0x006a9934) */
/* WARNING: Removing unreachable block (ram,0x006a98bc) */
/* WARNING: Removing unreachable block (ram,0x006a9844) */
/* WARNING: Removing unreachable block (ram,0x006a9880) */
/* WARNING: Removing unreachable block (ram,0x006a98f8) */
/* WARNING: Removing unreachable block (ram,0x006a9974) */
/* WARNING: Removing unreachable block (ram,0x006a9a11) */
/* WARNING: Removing unreachable block (ram,0x006a9aa1) */
/* WARNING: Removing unreachable block (ram,0x006a97e2) */

void FUN_006a97a0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_34;
  
  uStack_34 = s_UI_Game2_Option_ui_optionwnd_txt_009df2f4;
  FUN_00401740();
  uStack_34 = (char *)0x6a97d6;
  iVar2 = FUN_00410500();
  uStack_34 = (char *)(iVar2 + 0x3c);
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  FUN_00419fb0();
  FUN_00401740(s_screen_009df318,6);
  FUN_00406720((int)register0x00000010 + -0x28);
  FUN_00401740(s_screen2_009df320,7);
  FUN_00406720((int)register0x00000010 + -0x28);
  FUN_00401740(s_sound_009df328,5);
  FUN_00406720((int)register0x00000010 + -0x28);
  FUN_00401740(&DAT_009df330,4);
  FUN_00406720((int)register0x00000010 + -0x28);
  FUN_00401740(&DAT_009df338,3);
  FUN_00406720((int)register0x00000010 + -0x28);
  FUN_00401740(s_game2_009df33c,5);
  FUN_00406720((int)register0x00000010 + -0x28);
  FUN_006a7a80();
  FUN_00401740(s_screen_009df344,6);
  FUN_006a7540((int)register0x00000010 + -0x28);
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 != '\0') {
    FUN_00401740(s_btn_see_009df34c,7);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x28);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x44))(0);
    }
    FUN_00401740(s_pan_mp3_009df354,7);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x2c);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    FUN_00401740(s_pan_mp3_check_009df35c,0xd);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x30);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    FUN_00401740(s_lbl_mp3_009df36c,7);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_34);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
  }
  return;
}


// ==== FUN_006a9b00 @ 0x006a9b00 ====

void FUN_006a9b00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dfcd0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  FUN_006a97a0();
  return;
}


// ==== FUN_006a9b20 @ 0x006a9b20 ====

void FUN_006a9b20(byte param_1)

{
  void *in_ECX;
  
  FUN_006a89f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006a9b40 @ 0x006a9b40 ====

void FUN_006a9b40(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x006a9b4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006a9b50 @ 0x006a9b50 ====

undefined1 FUN_006a9b50(void)

{
  return 0;
}


// ==== FUN_006a9b60 @ 0x006a9b60 ====

void FUN_006a9b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dfda0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006a9b80 @ 0x006a9b80 ====

void FUN_006a9b80(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_help_009dfd70,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(unaff_retaddr);
  }
  return;
}


// ==== FUN_006a9c00 @ 0x006a9c00 ====

void FUN_006a9c00(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_58;
  undefined1 local_54;
  undefined4 uStack_48;
  uint local_44;
  undefined4 local_40 [8];
  void *pvStack_20;
  uint uStack_c;
  
  local_40[0] = 0xf;
  local_44 = 0;
  local_54 = 0;
  FUN_00401740(s_lbl_help_009dfd8c,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_58);
  if (0xf < local_44) {
    _free(local_58);
    return;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_005041e0(uVar2);
    (**(code **)(*piVar1 + 0xc))(local_40);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_006a9cb0 @ 0x006a9cb0 ====

void FUN_006a9cb0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_50;
  undefined1 local_4c;
  undefined4 uStack_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  void *pvStack_30;
  undefined1 uStack_2c;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  FUN_00401740(s_lbl_help_009dfd64,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_50);
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = 0xf;
  uStack_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    uStack_14 = 1;
    uStack_c = 1;
    local_38 = 0;
    uStack_34 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = 0;
    uStack_10 = 0;
    uStack_8 = 0;
    uStack_7 = 0;
    FUN_0056fe50(&local_38);
    iVar2 = FUN_00802534();
    uStack_10 = iVar2 << 0x18 | 0xffffff;
    (**(code **)(*piVar1 + 8))(&local_38);
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
  }
  return;
}


// ==== FUN_006a9db0 @ 0x006a9db0 ====

/* WARNING: Removing unreachable block (ram,0x006a9ea4) */
/* WARNING: Removing unreachable block (ram,0x006a9f4f) */

void FUN_006a9db0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int in_ECX;
  undefined1 auStack_7e [2];
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined1 uStack_74;
  undefined4 uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  void *pvStack_5c;
  undefined1 local_50 [8];
  uint uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  (**(code **)(*DAT_00b5ae88 + 0x20))(local_50,param_1,param_2);
  uStack_60 = 0xf;
  uStack_64 = 0;
  uStack_74 = 0;
  FUN_00401740(s_lbl_help_009dfd7c,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_78);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    uStack_64 = 0xf;
    uStack_68 = 0;
    pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    FUN_00401740(&DAT_009dfd88,1);
    FUN_00405300(&uStack_60,auStack_7c,auStack_7e + -0xe);
    if (0xf < uStack_64) {
      _free(pvStack_78);
      return;
    }
    FUN_006a9c00(0);
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    uStack_20 = 1;
    uStack_1c = 0;
    uStack_18 = 1;
    uStack_14 = 0;
    uStack_13 = 0;
    FUN_0056fe50(&uStack_44);
    FUN_0055a260(&uStack_60);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  }
  if (uStack_48 < 0x10) {
    return;
  }
  _free(pvStack_5c);
  return;
}


// ==== FUN_006a9fa0 @ 0x006a9fa0 ====

/* WARNING: Removing unreachable block (ram,0x006a9fe2) */

void FUN_006a9fa0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 auStack_3c [4];
  
  FUN_00401740(s_UI_Game2_MiniHelp_ui_minihelpwnd_009dfd3c);
  iVar1 = FUN_00410500();
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5ae88 + 0x14))(auStack_3c + 8);
  *(undefined4 *)(in_ECX + 0x18) = *puVar3;
  *(undefined4 *)(in_ECX + 0x1c) = puVar3[1];
  *(undefined4 *)(in_ECX + 0x20) = puVar3[2];
  iVar1 = (uint)*(ushort *)(in_ECX + 0x22) + (uint)*(ushort *)(in_ECX + 0x20) +
          (uint)*(ushort *)(in_ECX + 0x1e) + (uint)*(ushort *)(in_ECX + 0x1c);
  *(int *)(in_ECX + 8) = iVar1;
  FUN_006a9db0(*(undefined2 *)(in_ECX + 0x18),
               CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(in_ECX + 0x1a)));
  FUN_006a9b80(0);
  return;
}


// ==== FUN_006aa070 @ 0x006aa070 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006aa070(int param_1)

{
  float fVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined1 local_c [12];
  
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + *(int *)(param_1 + 4);
  if (*(uint *)(in_ECX + 8) < *(uint *)(in_ECX + 0x10)) {
    *(undefined4 *)(in_ECX + 0x10) = 0;
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5ae88 + 0x1c))(local_c);
    *(undefined4 *)(in_ECX + 0x18) = *puVar2;
    *(undefined4 *)(in_ECX + 0x1c) = puVar2[1];
    *(undefined4 *)(in_ECX + 0x20) = puVar2[2];
    iVar3 = (uint)*(ushort *)(in_ECX + 0x22) + (uint)*(ushort *)(in_ECX + 0x20) +
            (uint)*(ushort *)(in_ECX + 0x1e) + (uint)*(ushort *)(in_ECX + 0x1c);
    *(int *)(in_ECX + 8) = iVar3;
    FUN_006a9db0(*(undefined2 *)(in_ECX + 0x18),
                 CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(in_ECX + 0x1a)));
    FUN_006a9b80(0);
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0:
    if ((uint)*(ushort *)(in_ECX + 0x22) <= *(uint *)(in_ECX + 0x10)) {
      *(undefined4 *)(in_ECX + 0x14) = 1;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      return;
    }
    break;
  case 1:
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
    if ((uint)*(ushort *)(in_ECX + 0x1c) <= *(uint *)(in_ECX + 0xc)) {
      *(undefined4 *)(in_ECX + 0x14) = 2;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      return;
    }
    FUN_006a9b80(1);
    fVar1 = (float)*(int *)(in_ECX + 0xc);
    if (*(int *)(in_ECX + 0xc) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    FUN_006a9cb0(fVar1 / (float)*(ushort *)(in_ECX + 0x1c));
    return;
  case 2:
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
    if (*(uint *)(in_ECX + 0xc) < (uint)*(ushort *)(in_ECX + 0x1e)) {
      FUN_006a9b80(1);
      FUN_006a9cb0(0x3f800000);
      return;
    }
    *(undefined4 *)(in_ECX + 0x14) = 3;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  case 3:
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
    if ((uint)*(ushort *)(in_ECX + 0x20) <= *(uint *)(in_ECX + 0xc)) {
      *(undefined4 *)(in_ECX + 0x14) = 4;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      return;
    }
    FUN_006a9b80(1);
    fVar1 = (float)*(int *)(in_ECX + 0xc);
    if (*(int *)(in_ECX + 0xc) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    FUN_006a9cb0(DAT_0099d080 - fVar1 / (float)*(ushort *)(in_ECX + 0x20));
    return;
  case 4:
    FUN_006a9cb0(0);
  }
  return;
}


// ==== FUN_006aa250 @ 0x006aa250 ====

void FUN_006aa250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dfda0;
  in_ECX[1] = 0;
  in_ECX[5] = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[3] = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *(undefined2 *)((int)in_ECX + 0x1a) = 0;
  *(undefined2 *)(in_ECX + 7) = 0;
  *(undefined2 *)((int)in_ECX + 0x1e) = 0;
  *(undefined2 *)(in_ECX + 8) = 0;
  FUN_006a9fa0();
  return;
}


// ==== FUN_006aa290 @ 0x006aa290 ====

uint FUN_006aa290(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_006aa070(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006aa2c0 @ 0x006aa2c0 ====

void FUN_006aa2c0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dfda0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006aa300 @ 0x006aa300 ====

void FUN_006aa300(void)

{
  return;
}


// ==== FUN_006aa310 @ 0x006aa310 ====

void FUN_006aa310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dfe84;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5a838 + 0x10))();
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006aa340 @ 0x006aa340 ====

void FUN_006aa340(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [24];
  char cStack_1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  if (cStack_1 != '\0') {
    (**(code **)(*DAT_00b5a838 + 0xc))(2);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  return;
}


// ==== FUN_006aa390 @ 0x006aa390 ====

undefined4 FUN_006aa390(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_rebirth_009dfe60,0xb);
    if (iVar1 == 0) {
      pvVar2 = operator_new(0x400);
      *(undefined4 *)((int)pvVar2 + 8) = 0;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0x5060007;
      *(undefined2 *)((int)pvVar2 + 6) = 0x10;
      uVar3 = FUN_004244d0();
      FUN_004d8570(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006aa400 @ 0x006aa400 ====

void FUN_006aa400(void)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 uVar4;
  int in_ECX;
  uint *puVar5;
  undefined1 local_80 [4];
  void *local_7c;
  uint auStack_70 [24];
  char cStack_d;
  
  auStack_70[2] = 0xf;
  auStack_70[1] = 0;
  local_7c = (void *)((uint)local_7c & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_deathwnd_txt_009dfe0c,0x18);
  iVar1 = FUN_00410500(local_80);
  if (0xf < auStack_70[2]) {
    _free(local_7c);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  *(undefined4 *)(in_ECX + 0xc) = 15000;
  *(undefined4 *)(in_ECX + 0x14) = 0xf;
  puVar3 = (uint *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar5 = auStack_70;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  if (cStack_d != '\0') {
    (**(code **)(*DAT_00b5a838 + 0xc))(2);
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 8) = uVar4;
  }
  return;
}


// ==== FUN_006aa4d0 @ 0x006aa4d0 ====

int FUN_006aa4d0(void)

{
  int *piVar1;
  int extraout_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_EAX_00;
  int in_ECX;
  uint uVar5;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  uint uStack_10;
  
  uVar5 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 0x10);
  iVar4 = uVar5 * 0x10624dd3;
  uVar5 = uVar5 / 1000;
  if (*(uint *)(in_ECX + 0x14) != uVar5) {
    *(uint *)(in_ECX + 0x14) = uVar5;
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = 0;
    FUN_00401740(s_lbl_waittime_009dfe50,0xc);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
      return extraout_EAX;
    }
    local_24 = (void *)0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    iVar4 = 0;
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      iVar4 = 0;
      if (iVar2 != 0) {
        uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220029,*(undefined4 *)(in_ECX + 0x14));
        FUN_00401660(uVar3,0,0xffffffff);
        FUN_00404230(&uStack_28);
        iVar4 = FUN_0055a260(&uStack_28);
        if (0xf < uStack_10) {
          _free(local_24);
          return extraout_EAX_00;
        }
      }
    }
  }
  return iVar4;
}


// ==== FUN_006aa5c0 @ 0x006aa5c0 ====

void FUN_006aa5c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dfe84;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[2] = 0;
  FUN_006aa400();
  return;
}


// ==== FUN_006aa5e0 @ 0x006aa5e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006aa5e0(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar6 = DAT_00b5a6ac;
  if (*(int *)(in_ECX + 8) != 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a838 + 4))(2);
    iVar4 = (**(code **)(*piVar6 + 0x18))();
    iVar7 = *(int *)(in_ECX + 8);
    uVar5 = (**(code **)(*piVar3 + 0xc))();
    if (uVar5 < (uint)(iVar4 - iVar7)) {
      (**(code **)(*DAT_00b5a838 + 0x10))();
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  uVar5 = *(uint *)(in_ECX + 0xc);
  if ((uVar5 != 0) && (*(uint *)(in_ECX + 0x10) < uVar5)) {
    uVar8 = *(uint *)(in_ECX + 0x10) + *(int *)(param_1 + 4);
    *(uint *)(in_ECX + 0x10) = uVar8;
    if (uVar5 < uVar8) {
      *(uint *)(in_ECX + 0x10) = uVar5;
    }
    if (*(uint *)(in_ECX + 0x10) < uVar5) {
      FUN_00401830(s_processbar_009dfe28);
      piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c);
      if (0xf < uStack_8) {
        _free(apvStack_1c[0]);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
      if (piVar6 != (int *)0x0) {
        iVar7 = (**(code **)(*piVar6 + 0x30))();
        if (iVar7 != 0) {
          fVar1 = (float)*(int *)(in_ECX + 0x10);
          if (*(int *)(in_ECX + 0x10) < 0) {
            fVar1 = fVar1 + _DAT_0099d104;
          }
          fVar2 = (float)*(int *)(in_ECX + 0xc);
          if (*(int *)(in_ECX + 0xc) < 0) {
            fVar2 = fVar2 + _DAT_0099d104;
          }
          FUN_00587ba0((fVar1 / fVar2) * DAT_0099de78);
          FUN_006aa4d0();
          return;
        }
      }
    }
    else if (*(uint *)(in_ECX + 0x10) == uVar5) {
      FUN_00401830(s_pan_waittime_009dfe34);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return;
}


// ==== FUN_006aa770 @ 0x006aa770 ====

uint FUN_006aa770(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_006aa5e0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006aa7a0 @ 0x006aa7a0 ====

void FUN_006aa7a0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dfe84;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5a838 + 0x10))();
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006aa7e0 @ 0x006aa7e0 ====

undefined4 FUN_006aa7e0(void)

{
  return 0x30030119;
}


// ==== FUN_006aa7f0 @ 0x006aa7f0 ====

undefined4 FUN_006aa7f0(void)

{
  return 0x70150003;
}


// ==== FUN_006aa800 @ 0x006aa800 ====

void FUN_006aa800(void)

{
  return;
}


// ==== FUN_006aa810 @ 0x006aa810 ====

undefined1 FUN_006aa810(void)

{
  return 0;
}


// ==== FUN_006aa820 @ 0x006aa820 ====

void FUN_006aa820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dff7c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006aa840 @ 0x006aa840 ====

void FUN_006aa840(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009dff54;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006aa880 @ 0x006aa880 ====

undefined4 FUN_006aa880(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if ((param_3 != 1) || (param_1 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_briken_009dff2c,10);
  if (iVar2 == 0) {
    uVar4 = 10;
  }
  else {
    cVar1 = FUN_004036a0(param_2,s_btn_loa_009dff38);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(param_2,s_btn_exit_009dff40);
      if (cVar1 == '\0') {
        return 0;
      }
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar3 = &PTR_FUN_009dff68;
      FUN_00797a20(puVar3);
      return 1;
    }
    uVar4 = 0xb;
  }
  FUN_006aa840(uVar4,0);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009dff68;
  }
  FUN_00797a20(puVar3);
  FUN_006aa840(1,0);
  return 1;
}


// ==== FUN_006aa960 @ 0x006aa960 ====

/* WARNING: Removing unreachable block (ram,0x006aaa8c) */

void FUN_006aa960(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_50;
  undefined1 auStack_36 [2];
  void *local_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 local_24;
  uint local_20;
  undefined4 uStack_1c;
  
  uStack_50 = s_UI_Game2_ui_charstartwnd_txt_009dfef0;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  uStack_50 = (char *)0x6aa996;
  iVar1 = FUN_00410500();
  if (0xf < local_20) {
    uStack_50 = (char *)0x6aa9ac;
    _free(local_34);
    return;
  }
  uStack_50 = (char *)(iVar1 + 0x3c);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_2c = 0xf;
  uStack_30 = 0;
  FUN_00401740(s_textbox_briken_009dff10,0xe);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -0xe);
  if (0xf < uStack_30) {
    _free(unaff_ESI);
    return;
  }
  uStack_30 = 0xf;
  local_34 = (void *)0x0;
  (**(code **)(*piVar2 + 0x30))();
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3ef000b);
  uStack_1c = 0xf;
  local_20 = 0;
  uStack_30 = uStack_30 & 0xffffff00;
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_005569f0(&local_34,1);
  FUN_00401740(s_textbox_loa_009dff20,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_50);
  uStack_50 = (char *)((uint)uStack_50 & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3ef000c);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_005569f0(auStack_36 + -10,1);
  if (uStack_28 < 0x10) {
    return;
  }
  _free((void *)0xf);
  return;
}


// ==== FUN_006aab00 @ 0x006aab00 ====

void FUN_006aab00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dff7c;
  FUN_006aa960();
  return;
}


// ==== FUN_006aab20 @ 0x006aab20 ====

void FUN_006aab20(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dff7c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006aab60 @ 0x006aab60 ====

undefined4 FUN_006aab60(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_1) {
  case 0:
    return 0x15;
  case 1:
    return 0x16;
  case 2:
    return 0x18;
  case 3:
    return 0x19;
  case 4:
    uVar1 = 0x1a;
  }
  return uVar1;
}


// ==== FUN_006aabb0 @ 0x006aabb0 ====

void FUN_006aabb0(void)

{
  return;
}


// ==== FUN_006aabc0 @ 0x006aabc0 ====

void FUN_006aabc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e03b0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006aabe0 @ 0x006aabe0 ====

int FUN_006aabe0(int param_1,undefined4 param_2)

{
  int extraout_EAX;
  undefined4 uVar1;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  switch(param_2) {
  case 0:
    uVar1 = 0x1900001;
    break;
  case 1:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1900002);
    goto LAB_006aac4c;
  case 2:
    uVar1 = 0x1900004;
    break;
  case 3:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1900005);
    goto LAB_006aac4c;
  case 4:
    uVar1 = 0x1900006;
    break;
  default:
    goto switchD_006aac00_default;
  }
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar1);
LAB_006aac4c:
  FUN_00401660(uVar1,0,0xffffffff);
switchD_006aac00_default:
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_1c,0,0xffffffff);
  if (local_4 < 0x10) {
    return param_1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_006aacb0 @ 0x006aacb0 ====

void FUN_006aacb0(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBP;
  void *unaff_EDI;
  undefined4 local_38;
  uint local_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = local_34 & 0xffffff00;
  FUN_00401740(s_btn_showcom_009e0130,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e013c,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  (**(code **)(*piVar2 + 0x24))(1);
  uStack_28 = 0xf;
  pvStack_2c = (void *)0x0;
  FUN_00401740(s_btn_hidecom_009e0150,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
  if (0xf < pvStack_2c) {
    _free(unaff_EBP);
    return;
  }
  pvStack_2c = (void *)0xf;
  uStack_30 = 0;
  if (piVar2 == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e015c,0x12);
    FUN_00406880(&uStack_28);
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_24);
    return;
  }
  (**(code **)(*piVar2 + 0x24))(0);
  uStack_30 = 0xf;
  local_34 = 0;
  FUN_00401740(s_pan_command_009e0170,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x48);
  if (0xf < local_34) {
    _free(unaff_EDI);
    return;
  }
  local_34 = 0xf;
  local_38 = (void *)0x0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
    (**(code **)(*piVar2 + 0x20))();
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e017c,0x12);
  FUN_00406880(&uStack_30);
  if (uStack_18 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_006aaea0 @ 0x006aaea0 ====

/* WARNING: Removing unreachable block (ram,0x006ab54d) */
/* WARNING: Removing unreachable block (ram,0x006ab422) */

void FUN_006aaea0(void)

{
  void *pvVar1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  undefined4 uStack_84;
  undefined4 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_50;
  void *pvStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  void *pvStack_3c;
  void *local_38;
  void *local_34;
  uint uStack_30;
  void *pvStack_2c;
  uint uStack_28;
  void *local_24;
  uint local_20;
  void *pvStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_64 = (void **)0xb;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  uStack_6c = (char *)0x6aaecc;
  FUN_00401740();
  uStack_64 = &local_38;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_24) {
    uStack_6c = (char *)0x6aaeec;
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_6c = s_pComposite____NULL_009e019c;
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740();
    uStack_6c = (char *)0x6aaf25;
    FUN_00406880();
    if (uStack_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uStack_6c = (char *)0x6aaf39;
    _free(pvStack_1c);
    return;
  }
  uStack_6c = (char *)0x6aaf46;
  (**(code **)(*piVar3 + 0x24))();
  uStack_6c = (char *)0x6aaf4d;
  (**(code **)(*piVar3 + 0x20))();
  uStack_6c = (char *)0xb;
  uStack_28 = 0xf;
  pvStack_2c = (void *)0x0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  uStack_74 = (char *)0x6aaf69;
  FUN_00401740();
  uStack_6c = (char *)&pvStack_40;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < pvStack_2c) {
    uStack_74 = (char *)0x6aaf89;
    _free(pvStack_40);
    return;
  }
  pvStack_2c = (void *)0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_74 = s_pComposite____NULL_009e01bc;
    uStack_10 = 0xf;
    uStack_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740();
    uStack_74 = (char *)0x6aafc2;
    FUN_00406880();
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uStack_74 = (char *)0x6aafd6;
    _free(local_24);
    return;
  }
  uStack_74 = (char *)0x6aafe2;
  (**(code **)(*piVar3 + 0x24))();
  uStack_74 = (char *)0xb;
  uStack_30 = 0xf;
  local_34 = (void *)0x0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  uStack_7c = (char *)0x6aaffe;
  FUN_00401740();
  uStack_74 = (char *)&pvStack_48;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_34) {
    uStack_7c = (char *)0x6ab01e;
    _free(pvStack_48);
    return;
  }
  local_34 = (void *)0xf;
  local_38 = (void *)0x0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_7c = s_pComposite____NULL_009e01dc;
    uStack_18 = 0xf;
    pvStack_1c = (void *)0x0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    FUN_00401740();
    uStack_7c = (char *)0x6ab057;
    FUN_00406880();
    if (uStack_18 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uStack_7c = (char *)0x6ab06b;
    _free(pvStack_2c);
    return;
  }
  uStack_7c = (char *)0x6ab078;
  (**(code **)(*piVar3 + 0x24))();
  uStack_7c = (char *)0xa;
  local_38 = (void *)0xf;
  pvStack_3c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  uStack_84 = (char *)0x6ab094;
  FUN_00401740();
  uStack_7c = (char *)&uStack_50;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < pvStack_3c) {
    uStack_84 = (char *)0x6ab0b4;
    _free(uStack_50);
    return;
  }
  pvStack_3c = (void *)0xf;
  pvStack_40 = (void *)0x0;
  uStack_50 = (void *)((uint)uStack_50 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_84 = s_pComposite____NULL_009e01fc;
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740();
    uStack_84 = (char *)0x6ab0ed;
    FUN_00406880();
    if (local_20 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uStack_84 = (char *)0x6ab101;
    _free(local_34);
    return;
  }
  uStack_6c = (char *)(**(code **)(*piVar3 + 0x30))();
  if (uStack_6c == (char *)0x0) {
    uStack_84 = s_pButton____NULL_009e0210;
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740();
    uStack_84 = (char *)0x6ab139;
    FUN_00406880();
    if (local_20 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uStack_84 = (char *)0x6ab14d;
    _free(local_34);
    return;
  }
  uStack_84 = (char *)&uStack_64;
  piVar4 = (int *)FUN_00558e00();
  pvVar1 = *(void **)(*piVar4 + 0x18);
  uStack_84 = (char *)0x6ab1a1;
  FUN_005581c0();
  uStack_84 = (char *)0x6ab1a8;
  (**(code **)(*piVar3 + 0x20))();
  uStack_84 = (char *)0x8;
  pvStack_40 = (void *)0xf;
  pvStack_44 = (void *)0x0;
  FUN_00401740();
  uStack_84 = (char *)((int)register0x00000010 + -0x58);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < pvStack_44) {
    _free(pvVar1);
    return;
  }
  pvStack_44 = (void *)0xf;
  pvStack_48 = (void *)0x0;
  if (piVar3 == (int *)0x0) {
    uStack_28 = 0xf;
    pvStack_2c = (void *)0x0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e022c);
    FUN_00406880();
    if (uStack_28 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_3c);
    return;
  }
  uStack_74 = (char *)(**(code **)(*piVar3 + 0x30))();
  if (uStack_74 == (char *)0x0) {
    uStack_28 = 0xf;
    pvStack_2c = (void *)0x0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    FUN_00401740(s_pButton____NULL_009e0240);
    FUN_00406880();
    if (uStack_28 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_3c);
    return;
  }
  piVar4 = (int *)FUN_00558e00(&uStack_6c);
  uStack_64 = *(void ***)(*piVar4 + 0x14);
  pvVar1 = *(void **)(*piVar4 + 0x18);
  FUN_005581c0();
  (**(code **)(*piVar3 + 0x20))();
  pvStack_48 = (void *)0xf;
  pvStack_4c = (void *)0x0;
  FUN_00401740(s_btn_call_009e0250,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x60);
  if (0xf < pvStack_4c) {
    _free(pvVar1);
    return;
  }
  pvStack_4c = (void *)0xf;
  uStack_50 = (void *)0x0;
  if (piVar3 == (int *)0x0) {
    uStack_30 = 0xf;
    local_34 = (void *)0x0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e025c,0x12);
    FUN_00406880(&pvStack_48);
    if (uStack_30 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_44);
    return;
  }
  uStack_7c = (char *)(**(code **)(*piVar3 + 0x30))();
  if (uStack_7c == (char *)0x0) {
    uStack_30 = 0xf;
    local_34 = (void *)0x0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    FUN_00401740(s_pButton____NULL_009e0270,0xf);
    FUN_00406880(&pvStack_48);
    if (uStack_30 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_44);
    return;
  }
  piVar4 = (int *)FUN_00558e00(&uStack_74,(int)register0x00000010 + -0x78);
  uStack_6c = *(char **)(*piVar4 + 0x14);
  FUN_005581c0((int)register0x00000010 + -0x70);
  (**(code **)(*piVar3 + 0x20))();
  uStack_50 = (void *)0xf;
  uStack_64 = (void **)((uint)uStack_64 & 0xffffff00);
  FUN_00401740(s_btn_stop_009e0280,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x68);
  if (piVar3 == (int *)0x0) {
    local_38 = (void *)0xf;
    pvStack_3c = (void *)0x0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e028c,0x12);
    FUN_00406880(&uStack_50);
    if (local_38 < (void *)0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_4c);
    return;
  }
  uStack_84 = (char *)(**(code **)(*piVar3 + 0x30))();
  if (uStack_84 == (char *)0x0) {
    local_38 = (void *)0xf;
    pvStack_3c = (void *)0x0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(s_pButton____NULL_009e02a0,0xf);
    FUN_00406880(&uStack_50);
    if (local_38 < (void *)0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_4c);
    return;
  }
  piVar4 = (int *)FUN_00558e00(&uStack_7c,(int)register0x00000010 + -0x80);
  uStack_74 = *(char **)(*piVar4 + 0x14);
  FUN_005581c0((int)register0x00000010 + -0x78);
  (**(code **)(*piVar3 + 0x20))();
  uStack_6c = (char *)((uint)uStack_6c & 0xffffff00);
  FUN_00401740(s_btn_destroy_009e02b0,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x70);
  if (piVar3 == (int *)0x0) {
    pvStack_40 = (void *)0xf;
    pvStack_44 = (void *)0x0;
    FUN_00401740(s_pComposite____NULL_009e02bc,0x12);
    FUN_00406880((int)register0x00000010 + -0x58);
    if (pvStack_40 < (void *)0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free((void *)0x0);
    return;
  }
  iVar5 = (**(code **)(*piVar3 + 0x30))();
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_00558e00(&uStack_84,(int)register0x00000010 + -0x88);
    uStack_7c = *(char **)(*piVar4 + 0x14);
    FUN_005581c0((int)register0x00000010 + -0x80);
    (**(code **)(*piVar3 + 0x20))();
    return;
  }
  pvStack_40 = (void *)0xf;
  pvStack_44 = (void *)0x0;
  FUN_00401740(s_pButton____NULL_009e02d0,0xf);
  FUN_00406880((int)register0x00000010 + -0x58);
  if (pvStack_40 < (void *)0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_006ab640 @ 0x006ab640 ====

void FUN_006ab640(void)

{
  float fVar1;
  int *piVar2;
  int in_ECX;
  float unaff_ESI;
  void **ppvVar3;
  void *local_24;
  uint local_20 [3];
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  
  ppvVar3 = &local_24;
  local_20[0] = 0;
  local_24 = (void *)0x0;
  (**(code **)(*DAT_00b5ae90 + 0x28))(ppvVar3);
  if ((*(float *)(in_ECX + 0xc) != (float)local_20) || (*(float *)(in_ECX + 8) != unaff_ESI)) {
    *(uint **)(in_ECX + 0xc) = local_20;
    fVar1 = DAT_009e03a4;
    *(float *)(in_ECX + 8) = unaff_ESI;
    if (fVar1 <= unaff_ESI) {
      uStack_c = 0xf;
      uStack_10 = 0;
      local_20[0] = local_20[0] & 0xffffff00;
      FUN_00401740(s_bar_hp_009e02e0,6);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_24);
      if (0xf < uStack_10) {
        _free(local_24);
        return;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      (**(code **)(*piVar2 + 0x30))();
      FUN_00587ba0(((float)ppvVar3 / (float)local_20) * DAT_0099de78);
    }
  }
  return;
}


// ==== FUN_006ab740 @ 0x006ab740 ====

/* WARNING: Removing unreachable block (ram,0x006ab796) */

void FUN_006ab740(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_52 [18];
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined1 local_38 [16];
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  (**(code **)(*DAT_00b5ae90 + 0x2c))(local_38);
  uStack_40 = 0xf;
  FUN_00401740(s_lbl_name_009e02e8,8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_52 + -6);
  if (piVar2 == (int *)0x0) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e02f4,0x12);
    FUN_00406880(auStack_24);
    if (uStack_c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_20);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    FUN_00401740(s_pLabel____NULL_009e0308,0xe);
    FUN_00406880(auStack_24);
    if (uStack_c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_20);
    return;
  }
  FUN_0055a260(&uStack_40);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_006ab870 @ 0x006ab870 ====

void FUN_006ab870(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_42 [10];
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  void *local_20;
  void *pvStack_1c;
  uint uStack_c;
  uint uStack_8;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_pan_servant_009e0318,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e0324,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 != 0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);
    FUN_00401740(s_pcpop_009e0348,5);
    (**(code **)(*DAT_00b5a7c0 + 8))(&local_20);
    if (uStack_c < 0x10) {
      (**(code **)(*DAT_00b5ae90 + 0x30))();
      FUN_00587d40(auStack_42 + -10);
      return;
    }
    _free(local_20);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);
  FUN_00401740(s_pPanel____NULL_009e0338,0xe);
  FUN_00406880(&local_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006aba00 @ 0x006aba00 ====

void FUN_006aba00(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  void *in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStack_8a [2];
  undefined1 auStack_7e [2];
  void **ppvVar6;
  undefined4 uStack_74;
  void *_Memory;
  undefined4 local_58;
  void *pvStack_54;
  void *local_50;
  void *pvStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *local_40;
  void *local_3c;
  void *local_38;
  void *local_34;
  void *pvStack_30;
  uint uStack_2c;
  void *pvStack_28;
  void *local_24;
  uint local_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_3c = (void *)0xf;
  local_40 = (void *)0x0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  uStack_74 = (char *)0x6aba3c;
  local_58 = in_ECX;
  FUN_00401740();
  piVar2 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (0xf < local_24) {
    uStack_74 = (char *)0x6aba60;
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_74 = s_pComposite____NULL_009e0010;
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740();
    uStack_74 = (char *)0x6aba99;
    FUN_00406880();
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uStack_74 = (char *)0x6abaac;
    _free(pvStack_1c);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    uStack_74 = s_pButton____NULL_009e0024;
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740();
    uStack_74 = (char *)0x6abae3;
    FUN_00406880();
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uStack_74 = (char *)0x6abaf6;
    _free(pvStack_1c);
    return;
  }
  _Memory = (void *)0x1900001;
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  uStack_74 = (char *)0x0;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401660();
  if (0xf < uStack_2c) {
    _free(local_40);
    return;
  }
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401660();
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  FUN_00401660();
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740();
  ppvVar6 = &pvStack_44;
  piVar2 = (int *)(**(code **)(**(int **)((int)unaff_ESI + 4) + 0x34))();
  if (0xf < pvStack_30) {
    _free(pvStack_44);
    return;
  }
  pvStack_30 = (void *)0xf;
  local_34 = (void *)0x0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (uStack_14 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_28);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (uStack_14 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_28);
    return;
  }
  iVar3 = 0x1900002;
  pvStack_30 = (void *)0xf;
  local_34 = (void *)0x0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_1c = (void *)0xf;
  local_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401660();
  if (0xf < local_38) {
    _free(pvStack_4c);
    return;
  }
  local_38 = (void *)0xf;
  local_3c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401660();
  if (0xf < pvStack_1c) {
    _free(pvStack_30);
    return;
  }
  FUN_00401660();
  local_38 = (void *)0xf;
  local_3c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401740();
  piVar2 = (int *)(**(code **)(**(int **)((int)_Memory + 4) + 0x34))();
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = (void *)0xf;
  local_40 = (void *)0x0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (local_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_34);
    return;
  }
  iVar4 = (**(code **)(*piVar2 + 0x30))();
  if (iVar4 == 0) {
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (local_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_34);
    return;
  }
  iVar4 = 0x1900004;
  local_3c = (void *)0xf;
  local_40 = (void *)0x0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660(uVar5,0);
  pvStack_28 = (void *)0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  FUN_00401660(auStack_7e + 0x22,0);
  if ((void *)0xf < pvStack_44) {
    _free(local_58);
    return;
  }
  pvStack_44 = (void *)0xf;
  pvStack_48 = (void *)0x0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401660(&local_40,0);
  if (0xf < pvStack_28) {
    _free(local_3c);
    return;
  }
  FUN_00401660(auStack_7e + 6,0);
  pvStack_44 = (void *)0xf;
  pvStack_48 = (void *)0x0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_btn_stop_009e0094);
  piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 4) + 0x34))();
  if (0xf < pvStack_48) {
    _free(unaff_EBX);
    return;
  }
  pvStack_48 = (void *)0xf;
  pvStack_4c = (void *)0x0;
  if (piVar2 == (int *)0x0) {
    uStack_2c = 0xf;
    pvStack_30 = (void *)0x0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e00a0,0x12);
    FUN_00406880(&pvStack_44);
    if (uStack_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    uStack_2c = 0xf;
    pvStack_30 = (void *)0x0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740(s_pButton____NULL_009e00b4,0xf);
    FUN_00406880(&pvStack_44);
    if (uStack_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  pvStack_48 = (void *)0xf;
  pvStack_4c = (void *)0x0;
  uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1900005);
  FUN_00401660(uVar5,0,0xffffffff);
  local_34 = (void *)0xf;
  local_38 = (void *)0x0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  FUN_00401660(auStack_7e + 0x16,0,0xffffffff);
  if ((void *)0xf < local_50) {
    _free(unaff_ESI);
    return;
  }
  local_50 = (void *)0xf;
  pvStack_54 = (void *)0x0;
  FUN_00401660(&pvStack_4c,0,0xffffffff);
  if (0xf < local_34) {
    _free(pvStack_48);
    return;
  }
  FUN_00401660(auStack_8a + 6,0,0xffffffff);
  local_50 = (void *)0xf;
  pvStack_54 = (void *)0x0;
  FUN_00401740(s_btn_destroy_009e00c4,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 4) + 0x34))(auStack_7e + 0x16);
  if (0xf < pvStack_54) {
    _free(unaff_EDI);
    return;
  }
  pvStack_54 = (void *)0xf;
  local_58 = (void *)0x0;
  if (piVar2 == (int *)0x0) {
    local_38 = (void *)0xf;
    local_3c = (void *)0x0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e00d0,0x12);
    FUN_00406880(&local_50);
    if (local_38 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_4c);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    local_38 = (void *)0xf;
    local_3c = (void *)0x0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(s_pButton____NULL_009e00e4,0xf);
    FUN_00406880(&local_50);
    if (local_38 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_4c);
    return;
  }
  pvStack_54 = (void *)0xf;
  local_58 = (void *)0x0;
  uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1900006);
  FUN_00401660(uVar5,0,0xffffffff);
  local_40 = (void *)0xf;
  pvStack_44 = (void *)0x0;
  pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  FUN_00401660(&uStack_74,0,0xffffffff);
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free(_Memory);
    return;
  }
  FUN_00401660(&local_58,0,0xffffffff);
  if ((void *)0xf < local_40) {
    _free(pvStack_54);
    return;
  }
  FUN_00401660(auStack_8a + -6,0,0xffffffff);
  if (ppvVar6 < (void **)0x10) {
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_006ac180 @ 0x006ac180 ====

void FUN_006ac180(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_5e [10];
  void *local_54;
  undefined1 local_50;
  void *pvStack_44;
  uint local_40;
  undefined4 local_3c;
  uint uStack_30;
  void *pvStack_20;
  void *pvStack_1c;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  FUN_006aacb0();
  local_3c = 0xf;
  local_40 = 0;
  local_50 = 0;
  FUN_00401740(s_pan_curcommand_009e00f4,0xe);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_54);
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  local_40 = 0xf;
  pvStack_44 = (void *)0x0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e0104,0x12);
    FUN_00406880(&pvStack_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 == 0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);
    FUN_00401740(s_pPanel____NULL_009e0118,0xe);
    FUN_00406880(&pvStack_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);
  FUN_00401740(s_pcpop_009e0128,5);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_20);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_006aab60(uStack_4);
  FUN_00587d40(auStack_5e + -10);
  FUN_006aabe0(&pvStack_44,uStack_4);
  FUN_00401660(&pvStack_44,0,0xffffffff);
  (**(code **)(*DAT_00b5ae90 + 0x20))(uStack_4);
  if (uStack_30 < 0x10) {
    return;
  }
  _free(pvStack_44);
  return;
}


// ==== FUN_006ac340 @ 0x006ac340 ====

undefined4 FUN_006ac340(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_3 == 1) && (param_1 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_attack_009e0350,10);
    if (iVar2 == 0) {
      FUN_006ac180(0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_free_009e035c);
    if (cVar1 != '\0') {
      FUN_006ac180(1);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_call_009e0368);
    if (cVar1 != '\0') {
      FUN_006ac180(2);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_stop_009e0374);
    if (cVar1 != '\0') {
      FUN_006ac180(3);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_destroy_009e0380);
    if (cVar1 != '\0') {
      FUN_006ac180(4);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_showcom_009e038c);
    if (cVar1 != '\0') {
      FUN_006aaea0();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_hidecom_009e0398);
    if (cVar1 != '\0') {
      FUN_006aacb0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006ac460 @ 0x006ac460 ====

undefined4 FUN_006ac460(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_006ab640();
  }
  else if (iVar1 == 0x70240003) {
    FUN_006ac180((char)param_1[1]);
    return 1;
  }
  return 0;
}


// ==== FUN_006ac4a0 @ 0x006ac4a0 ====

void FUN_006ac4a0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_servantwnd_txt_009dffe8,0x1a);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006aba00();
    FUN_006ac180(1);
    FUN_006ab740();
    FUN_006ab870();
    FUN_006ab640();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006ac540 @ 0x006ac540 ====

void FUN_006ac540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e03b0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  FUN_006ac4a0();
  return;
}


// ==== FUN_006ac560 @ 0x006ac560 ====

void FUN_006ac560(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e03b0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ac5a0 @ 0x006ac5a0 ====

undefined4 FUN_006ac5a0(void)

{
  return 0x50000003;
}


// ==== FUN_006ac5b0 @ 0x006ac5b0 ====

undefined4 FUN_006ac5b0(void)

{
  return 0x70290000;
}


// ==== FUN_006ac5c0 @ 0x006ac5c0 ====

void FUN_006ac5c0(void)

{
  return;
}


// ==== FUN_006ac5d0 @ 0x006ac5d0 ====

void FUN_006ac5d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b6238;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006ac600 @ 0x006ac600 ====

void FUN_006ac600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e04b4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5a838 + 0x10))();
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006ac630 @ 0x006ac630 ====

void FUN_006ac630(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  
  piVar2 = DAT_00b5a6ac;
  if (*(int *)(in_ECX + 8) != 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a838 + 4))(3);
    iVar4 = (**(code **)(*piVar2 + 0x18))();
    iVar1 = *(int *)(in_ECX + 8);
    uVar5 = (**(code **)(*piVar3 + 0xc))();
    if (uVar5 < (uint)(iVar4 - iVar1)) {
      (**(code **)(*DAT_00b5a838 + 0x10))();
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_006ac680 @ 0x006ac680 ====

undefined4 FUN_006ac680(int param_1,short param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_2 == 2) {
    (**(code **)(*DAT_00b5a838 + 0x10))();
  }
  if (param_3 == 1) {
    if (param_2 == 0) {
      puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = &PTR_FUN_009e048c;
        FUN_00797a20(puVar2);
        return 1;
      }
    }
    else if (param_2 == 1) {
      puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = &PTR_FUN_009b3920;
        FUN_00797a20(puVar2);
        return 1;
      }
    }
    else {
      if (param_2 != 2) {
        return 1;
      }
      puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = &PTR_FUN_009b5318;
        FUN_00797a20(puVar2);
        return 1;
      }
    }
    FUN_00797a20(0);
  }
  return 1;
}


// ==== FUN_006ac750 @ 0x006ac750 ====

void FUN_006ac750(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [24];
  char cStack_1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  if (cStack_1 != '\0') {
    (**(code **)(*DAT_00b5a838 + 0xc))(3);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  return;
}


// ==== FUN_006ac7a0 @ 0x006ac7a0 ====

uint FUN_006ac7a0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_006ac630(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006ac7d0 @ 0x006ac7d0 ====

undefined4 FUN_006ac7d0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  void *unaff_EDI;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 != '\x01') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar2 != (int *)0x0) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      FUN_00401740(&DAT_009e047f,0);
      (**(code **)*piVar2)(0x1a,auStack_1c);
      if (0xf < uStack_c) {
        _free(unaff_EDI);
        return extraout_EAX;
      }
      (**(code **)(*piVar2 + 4))(0);
      (**(code **)(*DAT_00b5a9dc + 0xc))();
      FUN_006ac750();
    }
  }
  return 1;
}


// ==== FUN_006ac860 @ 0x006ac860 ====

undefined4 FUN_006ac860(void)

{
  char cVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  void *unaff_ESI;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 != '\x01') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar2 != (int *)0x0) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      FUN_00401740(&DAT_009e0480,0);
      (**(code **)*piVar2)(0x19,auStack_1c);
      if (0xf < uStack_c) {
        _free(unaff_ESI);
        return extraout_EAX;
      }
      (**(code **)(*piVar2 + 4))(0);
      (**(code **)(*DAT_00b5a9dc + 0xc))();
    }
  }
  return 1;
}


// ==== FUN_006ac8f0 @ 0x006ac8f0 ====

undefined4 FUN_006ac8f0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  void *unaff_ESI;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 != '\x01') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar2 != (int *)0x0) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      FUN_00401740(&DAT_009e0481,0);
      (**(code **)*piVar2)(0x18,auStack_1c);
      if (0xf < uStack_c) {
        _free(unaff_ESI);
        return extraout_EAX;
      }
      (**(code **)(*piVar2 + 4))(0);
      (**(code **)(*DAT_00b5a9dc + 0xc))();
    }
  }
  return 1;
}


// ==== FUN_006ac980 @ 0x006ac980 ====

void FUN_006ac980(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_SystemWnd_ui_systemwnd__009e041c,0x23);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))();
  return;
}


// ==== FUN_006aca10 @ 0x006aca10 ====

undefined4 FUN_006aca10(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_option_009e0440,10);
    if (iVar2 == 0) {
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = &PTR_FUN_009e04a0;
      }
      FUN_00797a20(puVar3);
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar3 = &PTR_FUN_009b6238;
      FUN_00797a20(puVar3);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_logout_009e044c);
    if (cVar1 != '\0') {
      uVar4 = FUN_006ac7d0();
      return uVar4;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_charselect_009e0458);
    if (cVar1 != '\0') {
      uVar4 = FUN_006ac860();
      return uVar4;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_exit_009e0468);
    if (cVar1 != '\0') {
      uVar4 = FUN_006ac8f0();
      return uVar4;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_cancel_009e0474);
    if (cVar1 != '\0') {
      FUN_006ac5d0();
      (**(code **)(*DAT_00b5a838 + 0x10))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006acb30 @ 0x006acb30 ====

void FUN_006acb30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e04b4;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  FUN_006ac980();
  return;
}


// ==== FUN_006acb50 @ 0x006acb50 ====

void FUN_006acb50(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e04b4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5a838 + 0x10))();
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006acb90 @ 0x006acb90 ====

void FUN_006acb90(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x006acb9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006acc30 @ 0x006acc30 ====

void FUN_006acc30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e05bc;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006acc60 @ 0x006acc60 ====

uint FUN_006acc60(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_006acc80 @ 0x006acc80 ====

void FUN_006acc80(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_textbox_009e0574,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401740(&DAT_009e057c,0);
      FUN_005569f0((int)register0x00000010 + -0x20,0);
      if (0xf < local_8) {
        _free(local_1c);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006acd40 @ 0x006acd40 ====

int FUN_006acd40(void)

{
  int *piVar1;
  int extraout_EAX;
  int iVar2;
  int in_ECX;
  int unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_textbox_009e0580,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009e0588,0);
    return unaff_retaddr;
  }
  iVar2 = (**(code **)(*piVar1 + 0x30))();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(iVar2 + 200,0,0xffffffff);
  return unaff_retaddr;
}


// ==== FUN_006ace00 @ 0x006ace00 ====

void FUN_006ace00(void)

{
  int *piVar1;
  int in_ECX;
  void *unaff_EBP;
  undefined4 unaff_retaddr;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_back_009e058c,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x24))(unaff_retaddr);
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_btn_view_009e0598,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    (**(code **)(*piVar1 + 0x24))((char)local_8 == '\0');
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_006aced0 @ 0x006aced0 ====

void FUN_006aced0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_GMTool_ui_gmtoolwnd_txt_009e0520,0x20);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006acf50 @ 0x006acf50 ====

undefined4 FUN_006acf50(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  void *local_1c [5];
  uint uStack_8;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_send_009e0544,8);
    if (iVar2 == 0) {
      FUN_006acd40(local_1c);
      (**(code **)(*DAT_00b5ae0c + 0x20))(local_1c);
      if (uStack_8 < 0x10) {
        return 1;
      }
      _free(local_1c[0]);
      return extraout_EAX;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_delete_009e0550);
    if (cVar1 != '\0') {
      FUN_006acc80();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_exit_009e055c);
    if (cVar1 != '\0') {
      FUN_006acc80();
      FUN_006ace00(0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_view_009e0568);
    if (cVar1 != '\0') {
      FUN_006ace00(1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006ad050 @ 0x006ad050 ====

void FUN_006ad050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e05bc;
  in_ECX[1] = 0;
  FUN_006aced0();
  return;
}


// ==== FUN_006ad070 @ 0x006ad070 ====

void FUN_006ad070(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e05bc;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ad0b0 @ 0x006ad0b0 ====

void FUN_006ad0b0(void)

{
  return;
}


// ==== FUN_006ad0c0 @ 0x006ad0c0 ====

undefined1 FUN_006ad0c0(void)

{
  return 0;
}


// ==== FUN_006ad100 @ 0x006ad100 ====

void FUN_006ad100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e070c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006ad120 @ 0x006ad120 ====

uint FUN_006ad120(void)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5ae98 + 0x20))();
  if ((char)uVar1 == '\0') {
    uVar1 = (**(code **)(*DAT_00b5acb8 + 0x10))();
    if ((char)uVar1 == '\0') {
      uVar1 = (**(code **)(*DAT_00b5aefc + 0xc))();
      if ((char)uVar1 == '\x01') {
        uVar1 = (**(code **)(*DAT_00b5aefc + 8))();
        if ((char)uVar1 == '\x01') {
          return uVar1;
        }
      }
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006ad190 @ 0x006ad190 ====

int FUN_006ad190(int param_1,undefined4 param_2)

{
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_004020e0(s_<font_3>_009e06f0,8);
  FUN_00401ff0(param_2,0,0xffffffff);
  FUN_004020e0(s_<_font>_009e06fc,7);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_1c,0,0xffffffff);
  if (local_4 < 0x10) {
    return param_1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_006ad220 @ 0x006ad220 ====

/* WARNING: Removing unreachable block (ram,0x006ad750) */
/* WARNING: Removing unreachable block (ram,0x006ad6a8) */
/* WARNING: Removing unreachable block (ram,0x006ada26) */
/* WARNING: Removing unreachable block (ram,0x006ad577) */
/* WARNING: Removing unreachable block (ram,0x006ad4cf) */

void FUN_006ad220(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint unaff_EBX;
  uint unaff_ESI;
  undefined1 auStack_da [6];
  undefined1 **ppuStack_c4;
  uint uStack_c0;
  undefined1 **ppuStack_b8;
  undefined1 *puStack_b4;
  undefined1 *puStack_a8;
  void *pvStack_9c;
  undefined1 *puStack_94;
  void *pvStack_90;
  undefined1 *puStack_88;
  undefined4 uStack_84;
  void **ppvStack_7c;
  undefined4 uStack_78;
  uint uVar4;
  void **ppvStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_54;
  void *pvStack_50;
  void *pvStack_4c;
  void *pvStack_48;
  uint uStack_44;
  void *pvStack_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *pvStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_14;
  uint uStack_10;
  
  uStack_68 = 0x320001;
  uStack_6c = 0;
  ppvStack_70 = (void **)0x6ad23c;
  uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
  ppvStack_70 = (void **)0xffffffff;
  uStack_44 = 0xf;
  pvStack_48 = (void *)0x0;
  ppvStack_7c = (void **)0x6ad25a;
  FUN_00401660();
  ppvStack_70 = (void **)0x6;
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  uStack_78 = 0x6ad276;
  FUN_00401740();
  ppvStack_70 = (void **)(auStack_da + 0x7e);
  uStack_78 = 0x6ad287;
  FUN_006ad190();
  ppvStack_70 = &pvStack_40;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uStack_78 = 0x6ad2ad;
    FUN_0057a4a0();
  }
  if (0xf < uStack_10) {
    uStack_78 = 0x6ad2c2;
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (0xf < uStack_2c) {
    uStack_78 = 0x6ad2e1;
    _free(pvStack_40);
    return;
  }
  uStack_78 = 0;
  ppvStack_7c = (void **)0x6ad2f5;
  uStack_84 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  ppvStack_7c = (void **)0xffffffff;
  puStack_88 = (undefined1 *)0x6ad302;
  FUN_00401660();
  ppvStack_7c = (void **)0x6;
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  uStack_84 = (void *)0x6ad31e;
  FUN_00401740();
  ppvStack_7c = (void **)&uStack_68;
  uStack_84 = (void *)0x6ad32f;
  FUN_006ad190();
  ppvStack_7c = &pvStack_4c;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uStack_84 = (void *)0x6ad355;
    FUN_0057a4a0();
  }
  if (0xf < uStack_1c) {
    uStack_84 = (void *)0x6ad36a;
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if (0xf < uStack_38) {
    uStack_84 = (void *)0x6ad389;
    _free(pvStack_4c);
    return;
  }
  uStack_84 = (void *)0x0;
  puStack_88 = (undefined1 *)0x6ad39d;
  pvStack_90 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_88 = (undefined1 *)0xffffffff;
  puStack_94 = (undefined1 *)0x6ad3aa;
  FUN_00401660();
  puStack_88 = (undefined1 *)0x6;
  pvStack_40 = (void *)0xf;
  uStack_44 = 0;
  uStack_54 = (void *)((uint)uStack_54 & 0xffffff00);
  pvStack_90 = (void *)0x6ad3c6;
  FUN_00401740();
  puStack_88 = auStack_da + 0x66;
  pvStack_90 = (void *)0x6ad3d7;
  FUN_006ad190();
  puStack_88 = auStack_da + 0x82;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    pvStack_90 = (void *)0x6ad3fd;
    FUN_0057a4a0();
  }
  if (0xf < uStack_28) {
    pvStack_90 = (void *)0x6ad412;
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (0xf < uStack_44) {
    pvStack_90 = (void *)0x6ad431;
    _free((void *)(unaff_EBX & 0xffffff00));
    return;
  }
  pvStack_90 = (void *)0x0;
  puStack_94 = (undefined1 *)0x6ad445;
  pvStack_9c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_94 = (undefined1 *)0xffffffff;
  FUN_00401660();
  puStack_94 = (undefined1 *)0x6;
  pvStack_4c = (void *)0xf;
  pvStack_9c = (void *)0x6ad46e;
  FUN_00401740();
  puStack_94 = auStack_da + 0x5a;
  pvStack_9c = (void *)0x6ad47f;
  FUN_006ad190();
  puStack_94 = auStack_da + 0x76;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    pvStack_9c = (void *)0x6ad4a5;
    FUN_0057a4a0();
  }
  if (0xf < uStack_34) {
    pvStack_9c = (void *)0x6ad4ba;
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  pvStack_9c = (void *)0x0;
  puStack_a8 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  uStack_6c = uStack_6c & 0xffffff00;
  puStack_a8 = (void *)0x6ad516;
  FUN_00401740();
  puStack_a8 = (void *)0x6ad527;
  FUN_006ad190();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    puStack_a8 = (void *)0x6ad54d;
    FUN_0057a4a0();
  }
  if ((void *)0xf < pvStack_40) {
    puStack_a8 = (void *)0x6ad562;
    _free(uStack_54);
    return;
  }
  pvStack_40 = (void *)0xf;
  uStack_44 = 0;
  puStack_a8 = (void *)0x0;
  puStack_b4 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  ppuStack_b8 = (undefined1 **)0x6ad5a2;
  FUN_00401660();
  uStack_68 = 0;
  uStack_78 = uStack_78 & 0xffffff00;
  puStack_b4 = (undefined1 *)0x6ad5be;
  FUN_00401740();
  puStack_b4 = (undefined1 *)0x6ad5cf;
  FUN_006ad190();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    puStack_b4 = (undefined1 *)0x6ad5f5;
    FUN_0057a4a0();
  }
  if ((void *)0xf < pvStack_4c) {
    puStack_b4 = (undefined1 *)0x6ad60a;
    _free((void *)(unaff_ESI & 0xffffff00));
    return;
  }
  pvStack_4c = (void *)0xf;
  if (0xf < uStack_68) {
    puStack_b4 = (undefined1 *)0x6ad629;
    _free(ppvStack_7c);
    return;
  }
  puStack_b4 = (undefined1 *)0x0;
  ppuStack_b8 = (undefined1 **)0x6ad63d;
  uStack_c0 = (**(code **)(*DAT_00b5a794 + 0xc))();
  ppuStack_b8 = (undefined1 **)0xffffffff;
  ppuStack_c4 = (undefined1 **)0x6ad64a;
  FUN_00401660();
  ppuStack_b8 = (undefined1 **)0x6;
  ppvStack_70 = (void **)0xf;
  uVar4 = 0;
  uStack_84 = (void *)((uint)uStack_84 & 0xffffff00);
  uStack_c0 = 0x6ad666;
  FUN_00401740();
  ppuStack_b8 = (undefined1 **)(auStack_da + 0x36);
  uStack_c0 = 0x6ad677;
  FUN_006ad190();
  ppuStack_b8 = &puStack_88;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uStack_c0 = 0x6ad69d;
    FUN_0057a4a0();
  }
  uStack_6c = uStack_6c & 0xffffff00;
  if (0xf < uVar4) {
    uStack_c0 = 0x6ad6d1;
    _free(puStack_88);
    return;
  }
  uStack_c0 = 0;
  ppuStack_c4 = (undefined1 **)0x6ad6e5;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  ppuStack_c4 = (undefined1 **)0xffffffff;
  FUN_00401660();
  ppuStack_c4 = (undefined1 **)0x6;
  ppvStack_7c = (void **)0xf;
  uVar4 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  FUN_00401740();
  ppuStack_c4 = (undefined1 **)(auStack_da + 0x2a);
  FUN_006ad190();
  ppuStack_c4 = &puStack_94;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0057a4a0();
  }
  uStack_68 = 0;
  uStack_78 = uStack_78 & 0xffffff00;
  if (0xf < uVar4) {
    _free(puStack_94);
    return;
  }
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  puStack_88 = (undefined1 *)0xf;
  uVar4 = 0;
  pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
  FUN_00401740();
  FUN_006ad190();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0057a4a0();
  }
  if ((void **)0xf < ppvStack_70) {
    _free(uStack_84);
    return;
  }
  ppvStack_70 = (void **)0xf;
  uStack_84 = (void *)((uint)uStack_84 & 0xffffff00);
  if (0xf < uVar4) {
    _free(&ppvStack_70);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660(uVar3);
  puStack_94 = (undefined1 *)0xf;
  uVar4 = 0;
  puStack_a8 = (undefined1 *)((uint)puStack_a8 & 0xffffff00);
  FUN_00401740();
  FUN_006ad190();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0057a4a0();
  }
  if ((void **)0xf < ppvStack_7c) {
    _free(pvStack_90);
    return;
  }
  ppvStack_7c = (void **)0xf;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if (0xf < uVar4) {
    _free(&ppvStack_7c);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
  FUN_00401660(uVar3,0,0xffffffff);
  uVar4 = 0;
  puStack_b4 = (undefined1 *)((uint)puStack_b4 & 0xffffff00);
  FUN_00401740(s_emo_20_009e06e0,6);
  uVar3 = FUN_006ad190(&pvStack_9c,auStack_da + 6);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&ppuStack_b8);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0057a4a0(uVar3);
  }
  if ((undefined1 *)0xf < puStack_88) {
    _free(pvStack_9c);
    return;
  }
  puStack_88 = (undefined1 *)0xf;
  pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
  if (0xf < uVar4) {
    _free(ppuStack_b8);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x32000c);
  FUN_00401660(uVar3,0,0xffffffff);
  uVar4 = 0;
  uStack_c0 = uStack_c0 & 0xffffff00;
  FUN_00401740(s_emo_21_009e06e8,6);
  uVar3 = FUN_006ad190(&puStack_a8,auStack_da + -6);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&ppuStack_c4);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0057a4a0(uVar3);
  }
  if ((undefined1 *)0xf < puStack_94) {
    _free(puStack_a8);
    return;
  }
  puStack_94 = (undefined1 *)0xf;
  puStack_a8 = (undefined1 *)((uint)puStack_a8 & 0xffffff00);
  if (uVar4 < 0x10) {
    return;
  }
  _free(ppuStack_c4);
  return;
}


// ==== FUN_006ada40 @ 0x006ada40 ====

void FUN_006ada40(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_34 [4];
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_CharWindow_ui_emotionwn_009e0628,0x25);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_btn_action_009e0650,10);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00558730(1);
  if (uStack_14 < 0x10) {
    FUN_006ad220();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_006adb10 @ 0x006adb10 ====

void FUN_006adb10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e070c;
  in_ECX[1] = 0;
  FUN_006ada40();
  return;
}


// ==== FUN_006adb30 @ 0x006adb30 ====

undefined4 FUN_006adb30(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  undefined4 unaff_retaddr;
  undefined4 local_10;
  void *local_c;
  int local_8;
  undefined4 local_4;
  
  local_c = (void *)0x0;
  local_8 = 0;
  local_4 = 0;
  FUN_00404fb0(param_1,0x5f,&local_10);
  if (local_c != (void *)0x0) {
    iVar1 = (local_8 - (int)local_c) / 0x1c;
    if (iVar1 != 0) {
      iVar2 = FUN_00403620(0,*(undefined4 *)((int)local_c + 0x14),&DAT_009e068c,3);
      if (iVar2 != 0) {
        if (local_c == (void *)0x0) {
          return 0;
        }
        FUN_00405de0(local_c,local_8,&local_10,iVar1);
        _free(local_c);
        return extraout_EAX;
      }
      if ((local_c == (void *)0x0) || ((uint)((local_8 - (int)local_c) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar1 = *DAT_00b5aefc;
      uVar3 = thunk_FUN_00796fb0((int)local_c + 0x1c);
      (**(code **)(iVar1 + 0x10))(uVar3);
      if (local_10 == (void *)0x0) {
        return 1;
      }
      FUN_00405de0(local_10,local_c,(int)register0x00000010 + -0x14,unaff_retaddr);
      _free(local_10);
      return extraout_EAX_00;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_006adc60 @ 0x006adc60 ====

undefined4 FUN_006adc60(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_state_009e065c,9);
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5aefc + 8))();
        (**(code **)(*DAT_00b5ae98 + 8))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_skill_009e0668);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5aefc + 8))();
        (**(code **)(*DAT_00b5acb8 + 8))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_action_009e0674);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(param_2,s_btn_exit_009e0680);
        if (cVar1 == '\0') {
          return 0;
        }
        (**(code **)(*in_ECX + 0x10))();
      }
      return 1;
    }
  }
  else if ((param_1 == 0x13) &&
          (((param_3 == 1 || (param_3 == 2)) && (cVar1 = FUN_006adb30(param_2), cVar1 == '\x01'))))
  {
    return 1;
  }
  return 0;
}


// ==== FUN_006add40 @ 0x006add40 ====

void FUN_006add40(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e070c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006add80 @ 0x006add80 ====

void FUN_006add80(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_006addc0 @ 0x006addc0 ====

uint FUN_006addc0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5acb8 + 0xc))();
  if ((char)uVar1 == '\x01') {
    *(undefined1 *)(in_ECX + 0x2c) = 0;
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006ade10 @ 0x006ade10 ====

void FUN_006ade10(void)

{
  void *_Memory;
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x20);
  while (puVar1 != *(undefined4 **)(in_ECX + 0x24)) {
    _Memory = (void *)*puVar1;
    puVar1 = puVar1 + 1;
    if (_Memory != (void *)0x0) {
      if (*(uint *)((int)_Memory + 0x44) < 0x10) {
        *(undefined4 *)((int)_Memory + 0x44) = 0xf;
        *(undefined4 *)((int)_Memory + 0x40) = 0;
        *(undefined1 *)((int)_Memory + 0x30) = 0;
        *(undefined ***)((int)_Memory + 4) = &PTR_FUN_009a51c4;
        _free(_Memory);
        return;
      }
      _free(*(void **)((int)_Memory + 0x30));
      return;
    }
  }
  if (*(void **)(in_ECX + 0x20) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_006ade90 @ 0x006ade90 ====

void FUN_006ade90(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  (**(code **)(*DAT_00b5acc4 + 0x30))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_point_009e07a8,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00401740(&DAT_009e07b4,2);
  uVar2 = FUN_00404230((int)register0x00000010 + -0x20);
  FUN_0055a260(uVar2);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_006adf60 @ 0x006adf60 ====

void FUN_006adf60(void)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  char *pcStack_50;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  pcStack_50 = s_btn_skill_tab__009e0998;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  uStack_54 = 0x6adf8a;
  FUN_00401740();
  uVar2 = 1;
  if (*(char *)(in_ECX + 0xb) != '\0') {
    do {
      FUN_00402220(auStack_68,local_38,&DAT_009e09a8);
      FUN_00404230(local_1c);
      pcStack_50 = (char *)0x6adfd1;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      pcStack_50 = (char *)0x6adfd8;
      (**(code **)(*piVar1 + 0x30))();
      pcStack_50 = (char *)0x6adfe4;
      FUN_00558730();
      if (0xf < uStack_4) {
        pcStack_50 = (char *)0x6adff5;
        _free(pvStack_18);
        return;
      }
      uVar2 = uVar2 + 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while (uVar2 <= *(byte *)(in_ECX + 0xb));
  }
  if (local_20 < 0x10) {
    return;
  }
  pcStack_50 = (char *)0x6ae024;
  _free(local_34);
  return;
}


// ==== FUN_006ae030 @ 0x006ae030 ====

undefined4 FUN_006ae030(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort *puVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 extraout_EAX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined1 auStack_26 [18];
  uint uStack_14;
  
  iVar3 = FUN_00589780();
  if (*(int *)(iVar3 + 4) != 0) {
    return 0;
  }
  puVar4 = (ushort *)FUN_00589780();
  uVar1 = *puVar4;
  piVar5 = (int *)(**(code **)(*DAT_00b5acc4 + 0x3c))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x18))(uVar1);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  piVar6 = (int *)(**(code **)(*piVar5 + 0x18))();
  piVar7 = (int *)(**(code **)(*piVar6 + 0x10))();
  if ((*piVar7 == 0) || (*piVar7 == 3)) {
    piVar5 = (int *)(**(code **)(*piVar5 + 0x10))();
    iVar3 = (**(code **)(*piVar5 + 4))();
    (**(code **)(*piVar6 + 0xc))();
    uVar8 = (**(code **)(*DAT_00b5ace8 + 8))(*(undefined2 *)(iVar3 + 0x2bb8),0);
    FUN_00401660(uVar8,0,0xffffffff);
    uVar2 = *(undefined2 *)(iVar3 + 0x2b88);
    puVar9 = operator_new(0x2c);
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      *puVar9 = &PTR_FUN_009e09cc;
      puVar9[9] = 0xf;
      puVar9[8] = 0;
      *(undefined1 *)(puVar9 + 4) = 0;
    }
    puVar9[1] = unaff_EBP;
    puVar9[2] = unaff_ESI;
    FUN_00401660(auStack_26 + -6,0,0xffffffff);
    *(undefined2 *)(puVar9 + 10) = uVar2;
    FUN_00797a20(puVar9);
    if (0xf < uStack_14) {
      _free((void *)(uint)uVar1);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_006ae190 @ 0x006ae190 ====

uint FUN_006ae190(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  uVar2 = iVar1 - 1;
  if (uVar2 == 0) {
    uVar2 = FUN_006ae030(param_1);
    if ((char)uVar2 == '\x01') {
      return uVar2;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_006ae1c0 @ 0x006ae1c0 ====

void FUN_006ae1c0(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009e09e0;
  FUN_006ade10();
  if (in_ECX[4] != 0) {
    FUN_00405de0(in_ECX[4],in_ECX[5],in_ECX + 3,in_ECX);
    _free((void *)in_ECX[4]);
    return;
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  if ((void *)in_ECX[8] != (void *)0x0) {
    _free((void *)in_ECX[8]);
    return;
  }
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[8] != (void *)0x0) {
    _free((void *)in_ECX[8]);
    return;
  }
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  if (in_ECX[4] == 0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_00405de0(in_ECX[4],in_ECX[5],in_ECX + 3,unaff_EBX);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_006ae280 @ 0x006ae280 ====

void FUN_006ae280(void)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  iVar4 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  uVar8 = 0;
  if (*(int **)(iVar4 + 4) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 4) + 0x18))();
  }
  pbVar6 = (byte *)(**(code **)(*piVar5 + 8))();
  bVar1 = *pbVar6;
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(&DAT_009e07b8,1);
  FUN_00406720(auStack_1c);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5aa30 + 0xc))();
  if (piVar5 != (int *)0x0) {
    do {
      cVar2 = (**(code **)(*piVar5 + 0x14))(uVar3);
      if (cVar2 != '\0') {
        iVar4 = (**(code **)(*piVar5 + 4))();
        if (uVar8 < *(byte *)(iVar4 + 0x2b8a)) {
          uVar8 = (uint)*(byte *)(iVar4 + 0x2b8a);
        }
      }
      piVar5 = (int *)(**(code **)(*DAT_00b5aa30 + 0x10))();
    } while (piVar5 != (int *)0x0);
    if (uVar8 != 0) {
      uStack_4 = 0xf;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if (uVar8 != 0) {
        uVar7 = 0;
        uStack_8 = 0;
        do {
          uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar7 + (uint)bVar1 * 100 + 0x3c0064);
          FUN_00401660(uVar3,0,0xffffffff);
          FUN_00406720(auStack_1c);
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
      }
    }
  }
  if (*(int *)(in_ECX + 0x10) == 0) {
    *(undefined1 *)(in_ECX + 0xb) = 0xff;
    return;
  }
  *(char *)(in_ECX + 0xb) = (char)((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x1c) + -1;
  return;
}


// ==== FUN_006ae410 @ 0x006ae410 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006ae410(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  byte *pbVar7;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int extraout_EAX_07;
  int extraout_EAX_08;
  int extraout_EAX_09;
  int extraout_EAX_10;
  int iVar8;
  ushort *puVar9;
  int extraout_EAX_11;
  int extraout_EAX_12;
  int extraout_EAX_13;
  int extraout_EAX_14;
  int extraout_EAX_15;
  int extraout_EAX_16;
  int extraout_EAX_17;
  void *unaff_EBX;
  uint uVar10;
  bool bVar11;
  byte unaff_retaddr;
  undefined4 *puVar12;
  uint in_stack_ffffd32c;
  undefined1 auStack_2c9a [14];
  uint uStack_2c8c;
  undefined1 auStack_2c88 [4];
  void *pvStack_2c84;
  undefined4 local_2c80;
  void *local_2c7c;
  undefined4 uStack_2c74;
  uint uStack_2c70;
  undefined4 uStack_2c6c;
  uint uStack_2c68;
  void *pvStack_2c64;
  undefined4 uStack_2c60;
  undefined4 local_2c54;
  uint local_2c50;
  undefined **local_2c4c;
  void *apvStack_2c48 [4];
  uint uStack_2c38;
  uint uStack_2c34;
  undefined1 auStack_2c30 [4];
  void *pvStack_2c2c;
  uint local_2c1c;
  uint uStack_2c18;
  undefined1 auStack_2c14 [4];
  void *pvStack_2c10;
  undefined4 local_2c0c;
  undefined4 local_2c08;
  uint local_2c00;
  uint uStack_2bfc;
  undefined1 auStack_2bf8 [8];
  undefined4 local_2bf0;
  undefined4 local_2bec;
  undefined **ppuStack_23d4;
  undefined2 uStack_24;
  int iStack_c;
  int iStack_4;
  
  iStack_4 = 0x6ae41a;
  local_2c7c = (void *)0xf;
  local_2c80 = 0;
  FUN_00401740(&DAT_009e07ba,0);
  if (*(char *)(param_3 + 2) == '\0') {
    FUN_004020e0(s_<font_3>_009e07bc,8);
    FUN_004020e0(s_<color_C1C1FF>_009e07c8,0xe);
    uVar4 = (**(code **)(*DAT_00b5ace8 + 8))(*(undefined2 *)(param_2 + 0x2bb8),0);
    FUN_00401ff0(uVar4,0,0xffffffff);
    FUN_004020e0(s_<_color>_009e07d8,8);
    FUN_004020e0(s_<_font>_009e07e4,7);
    FUN_004020e0(s_<font_2>__009e07ec,9);
    FUN_004020e0(s_<color_FDDE5C>_009e07f8,0xe);
    uVar4 = (**(code **)(*DAT_00b5ace8 + 8))(*(undefined2 *)(param_2 + 0x2bb8),1);
    FUN_00401ff0(uVar4,0,0xffffffff);
    FUN_004020e0(s_<_color>_009e0808,8);
    param_2 = (uint)unaff_retaddr * 0x80 + 0x3c + param_2;
    uVar2 = *(uint *)(param_2 + 0x14);
    apvStack_2c48[0] = *(void **)(param_2 + 4);
    apvStack_2c48[1] = *(void **)(param_2 + 8);
    apvStack_2c48[2] = *(void **)(param_2 + 0xc);
    apvStack_2c48[3] = *(void **)(param_2 + 0x10);
    uVar10 = 0;
    local_2c4c = &PTR_FUN_009a51c4;
    uStack_2c34 = CONCAT31(uStack_2c34._1_3_,*(undefined1 *)(param_2 + 0x18));
    uStack_2c38 = uVar2;
    if (uVar2 != 0) {
      FUN_004020e0(&DAT_009e0814,1);
      uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(2,0x74);
      FUN_00401ff0(uVar4,0,0xffffffff);
      if (uVar2 != 0) {
        do {
          bVar11 = *(char *)(iStack_4 + 3) == '\0';
          pvVar3 = apvStack_2c48[uVar10];
          piVar5 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(pvVar3);
          if (piVar5 != (int *)0x0) {
            if (uVar10 != 0) {
              FUN_004020e0(s__009e0818,0xb);
            }
            if ((*(char *)(iStack_4 + 3) == '\0') &&
               (piVar6 = (int *)(**(code **)(*DAT_00b5acc0 + 0x18))(pvVar3), piVar6 != (int *)0x0))
            {
              piVar6 = (int *)(**(code **)(*piVar6 + 0x18))();
              pbVar7 = (byte *)(**(code **)(*piVar6 + 0xc))();
              if ((*pbVar7 & 0xf) < (byte)((uint)pvVar3 >> 0x10)) goto LAB_006ae61b;
              bVar11 = false;
            }
            else {
LAB_006ae61b:
              if (bVar11) {
                FUN_004020e0(s_<color_FF8080>_009e0824,0xe);
              }
            }
            uVar4 = (**(code **)(*piVar5 + 4))();
            FUN_006afd30(uVar4);
            uVar4 = (**(code **)(*DAT_00b5ace8 + 8))(uStack_24,0);
            FUN_00401ff0(uVar4,0,0xffffffff);
            FUN_00401740(s_Lv_d__009e0834,6);
            uVar4 = FUN_00404230(&uStack_2c68);
            FUN_00401ff0(uVar4,0,0xffffffff);
            if (0xf < local_2c50) {
              _free(pvStack_2c64);
              return extraout_EAX;
            }
            local_2c50 = 0xf;
            local_2c54 = 0;
            pvStack_2c64 = (void *)((uint)pvStack_2c64 & 0xffffff00);
            if (bVar11) {
              FUN_004020e0(s_<_color>_009e083c,8);
            }
            ppuStack_23d4 = &PTR_FUN_009a51d4;
            FUN_0047f180();
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uStack_2c38);
      }
    }
    FUN_004020e0(s_<_font>_009e0848,7);
  }
  else {
    local_2c54 = 0;
    local_2c50 = 0;
    local_2c4c = (undefined **)0x0;
    local_2c08 = 0xf;
    local_2c0c = 0;
    local_2c1c = local_2c1c & 0xffffff00;
    local_2bec = 0xf;
    local_2bf0 = 0;
    local_2c00 = local_2c00 & 0xffffff00;
    FUN_004020e0(s_<font_3>_009e0850,8);
    FUN_004020e0(s_<color_C1C1FF>_009e085c,0xe);
    uVar4 = (**(code **)(*DAT_00b5ace8 + 8))(*(undefined2 *)(param_2 + 0x2bb8),0);
    FUN_00401ff0(uVar4,0,0xffffffff);
    FUN_00401740(s_Lv__d_009e086c,7);
    puVar12 = &local_2c80;
    uVar4 = FUN_00404230(puVar12);
    FUN_00401ff0(uVar4,0,0xffffffff);
    if (0xf < uStack_2c68) {
      _free(local_2c7c);
      return extraout_EAX_00;
    }
    FUN_004020e0(s_<_color>_009e0874,8);
    FUN_004020e0(s_<_font>_009e0880,7);
    FUN_004020e0(s_<font_2>__009e0888,9);
    if (*(short *)((uint)*(byte *)(param_1 + 2) * 0x80 + 0x5e + param_2) != 0) {
      FUN_00401740(s_<VALUE>_009e0894,7);
      FUN_00401740(&DAT_009e089c,3);
      puVar12 = &local_2c80;
      uVar4 = FUN_00404230(puVar12);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_2c68) {
        _free(local_2c7c);
        return extraout_EAX_01;
      }
      FUN_004e6c20();
      uVar4 = (**(code **)(*DAT_00b5a794 + 8))(&local_2c80,2,0x70);
      FUN_00401ff0(uVar4,0,0xffffffff);
      if (0xf < uStack_2c68) {
        _free(local_2c7c);
        return extraout_EAX_02;
      }
      FUN_004e67a0();
    }
    if (*(short *)((uint)*(byte *)(param_1 + 2) * 0x80 + 0x60 + param_2) != 0) {
      FUN_00401740(s_<VALUE>_009e08a0,7);
      FUN_00401740(&DAT_009e08a8,3);
      puVar12 = &local_2c80;
      uVar4 = FUN_00404230(puVar12);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_2c68) {
        _free(local_2c7c);
        return extraout_EAX_03;
      }
      FUN_004e6c20();
      uVar4 = (**(code **)(*DAT_00b5a794 + 8))(&local_2c80,2,0x71);
      FUN_00401ff0(uVar4,0,0xffffffff);
      if (0xf < uStack_2c68) {
        _free(local_2c7c);
        return extraout_EAX_04;
      }
      FUN_004e67a0();
    }
    if (*(int *)((uint)*(byte *)(param_1 + 2) * 0x80 + 0x68 + param_2) != 0) {
      FUN_00401740(s_<VALUE>_009e08ac,7);
      pvStack_2c64 = *(void **)((uint)*(byte *)(param_1 + 2) * 0x80 + param_2 + 0x68);
      in_stack_ffffd32c = in_stack_ffffd32c & 0xffffff00;
      FUN_00401740(s__4_1f__009e08b4,6);
      uVar4 = FUN_00404230(&local_2c80,puVar12,in_stack_ffffd32c);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_2c68) {
        _free(local_2c7c);
        return extraout_EAX_05;
      }
      FUN_004e6c20();
      uVar4 = (**(code **)(*DAT_00b5a794 + 8))(&local_2c80,2,0x72);
      FUN_00401ff0(uVar4,0,0xffffffff);
      if (0xf < uStack_2c68) {
        _free(local_2c7c);
        return extraout_EAX_06;
      }
      FUN_004e67a0();
    }
    FUN_004020e0(s_<color_FDDE5C>_009e08bc,0xe);
    uVar4 = (**(code **)(*DAT_00b5ace8 + 8))(*(undefined2 *)(param_2 + 0x2bb8),1);
    FUN_00401ff0(uVar4,0,0xffffffff);
    FUN_004020e0(s_<_color>_009e08cc,8);
    FUN_004020e0(s_<_font>_009e08d8,7);
    if (*(byte *)(iStack_4 + 2) < unaff_retaddr) {
      FUN_004020e0(s_<font_2>___009e08e0,10);
      FUN_00401740(s_<VALUE>_009e08ec,7);
      FUN_00401740(s_Lv__u__009e08f4,6);
      uVar4 = FUN_00404230(auStack_2c88);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_2c70) {
        _free(pvStack_2c84);
        return extraout_EAX_07;
      }
      if (*(char *)(iStack_4 + 3) == '\0') {
        uVar4 = FUN_004022a0(auStack_2c88,s_<color_FF8080>_009e0908,auStack_2c14,s_<_color>_009e08fc
                            );
        uVar4 = FUN_00402220(&local_2c4c,uVar4);
        FUN_00401660(uVar4,0,0xffffffff);
        if (0xf < uStack_2c34) {
          _free(apvStack_2c48[0]);
          return extraout_EAX_08;
        }
        uStack_2c34 = 0xf;
        uStack_2c38 = 0;
        apvStack_2c48[0] = (void *)((uint)apvStack_2c48[0] & 0xffffff00);
        if (0xf < uStack_2c70) {
          _free(pvStack_2c84);
          return extraout_EAX_09;
        }
      }
      FUN_004e6c20(auStack_2c30);
      uVar4 = (**(code **)(*DAT_00b5a794 + 8))(auStack_2c88,2,0x75,&uStack_2c68);
      FUN_00401ff0(uVar4,0,0xffffffff);
      if (0xf < uStack_2c70) {
        _free(pvStack_2c84);
        return extraout_EAX_10;
      }
      FUN_004e67a0();
      param_2 = (uint)unaff_retaddr * 0x80 + 0x3c + param_2;
      uVar2 = *(uint *)(param_2 + 0x14);
      apvStack_2c48[0] = *(void **)(param_2 + 4);
      apvStack_2c48[1] = *(void **)(param_2 + 8);
      apvStack_2c48[2] = *(void **)(param_2 + 0xc);
      apvStack_2c48[3] = *(void **)(param_2 + 0x10);
      local_2c4c = &PTR_FUN_009a51c4;
      uStack_2c34 = CONCAT31(uStack_2c34._1_3_,*(char *)(param_2 + 0x18));
      uStack_2c38 = uVar2;
      if (*(char *)(param_2 + 0x18) != '\0') {
        iVar8 = (**(code **)(*DAT_00b5ac1c + 0x14))();
        piVar5 = (int *)(**(code **)(**(int **)(iVar8 + 0x48) + 0x28))();
        puVar9 = (ushort *)(**(code **)(*piVar5 + 8))();
        uVar1 = *puVar9;
        FUN_00401740(s_<VALUE>_009e0918,7);
        FUN_00401830(s_Lv__u__009e0920);
        uVar4 = FUN_00404230(auStack_2c88);
        FUN_00401660(uVar4,0,0xffffffff);
        if (0xf < uStack_2c70) {
          _free(pvStack_2c84);
          return extraout_EAX_11;
        }
        if (uVar1 < (byte)uStack_2c34) {
          uVar4 = FUN_004022a0(auStack_2bf8,s_<color_FF8080>_009e0934,auStack_2c14,
                               s_<_color>_009e0928);
          uVar4 = FUN_00402220(auStack_2c88,uVar4);
          FUN_00401660(uVar4,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_004e6c20(auStack_2c30);
        uVar4 = (**(code **)(*DAT_00b5a794 + 8))(auStack_2c88,2,0x76,&uStack_2c68);
        FUN_00401ff0(uVar4,0,0xffffffff);
        if (0xf < uStack_2c70) {
          _free(pvStack_2c84);
          return extraout_EAX_12;
        }
        FUN_004e67a0();
      }
      uVar10 = 0;
      if (uVar2 != 0) {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(2,0x74);
        FUN_00401ff0(uVar4,0,0xffffffff);
        if (uVar2 != 0) {
          do {
            pvVar3 = apvStack_2c48[uVar10];
            bVar11 = *(char *)(iStack_4 + 3) == '\0';
            uStack_2c6c = pvVar3;
            piVar5 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(pvVar3);
            if (piVar5 != (int *)0x0) {
              if (uVar10 != 0) {
                FUN_004020e0(s__009e0944,0xe);
              }
              if ((*(char *)(iStack_4 + 3) == '\0') &&
                 (piVar6 = (int *)(**(code **)(*DAT_00b5acc0 + 0x18))(pvVar3), piVar6 != (int *)0x0)
                 ) {
                piVar6 = (int *)(**(code **)(*piVar6 + 0x18))();
                pbVar7 = (byte *)(**(code **)(*piVar6 + 0xc))();
                if ((*pbVar7 & 0xf) < uStack_2c6c._2_1_) goto LAB_006aeeb1;
                bVar11 = false;
              }
              else {
LAB_006aeeb1:
                if (bVar11) {
                  FUN_004020e0(s_<color_FF8080>_009e0954,0xe);
                }
              }
              uVar4 = (**(code **)(*piVar5 + 4))();
              FUN_006afd30(uVar4);
              uVar4 = (**(code **)(*DAT_00b5ace8 + 8))(uStack_24,0);
              FUN_00401ff0(uVar4,0,0xffffffff);
              FUN_00401740(s_Lv_d__009e0964,6);
              uVar4 = FUN_00404230(auStack_2c88);
              FUN_00401ff0(uVar4,0,0xffffffff);
              if (0xf < uStack_2c70) {
                _free(pvStack_2c84);
                return extraout_EAX_13;
              }
              uStack_2c70 = 0xf;
              uStack_2c74 = 0;
              pvStack_2c84 = (void *)((uint)pvStack_2c84 & 0xffffff00);
              if (bVar11) {
                FUN_004020e0(s_<_color>_009e096c,8);
              }
              ppuStack_23d4 = &PTR_FUN_009a51d4;
              FUN_0047f180();
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < uStack_2c38);
        }
      }
      FUN_004020e0(s_<_font>_009e0978,7);
    }
    if (0xf < uStack_2bfc) {
      _free(pvStack_2c10);
      return extraout_EAX_14;
    }
    uStack_2bfc = 0xf;
    local_2c00 = 0;
    pvStack_2c10 = (void *)((uint)pvStack_2c10 & 0xffffff00);
    if (0xf < uStack_2c18) {
      _free(pvStack_2c2c);
      return extraout_EAX_15;
    }
    uStack_2c18 = 0xf;
    local_2c1c = 0;
    pvStack_2c2c = (void *)((uint)pvStack_2c2c & 0xffffff00);
    if (pvStack_2c64 != (void *)0x0) {
      FUN_004e65b0(pvStack_2c64,uStack_2c60,&uStack_2c68,uStack_2c6c);
      _free(pvStack_2c64);
      return extraout_EAX_16;
    }
  }
  *(undefined4 *)(iStack_c + 0x18) = 0xf;
  *(undefined4 *)(iStack_c + 0x14) = 0;
  *(undefined1 *)(iStack_c + 4) = 0;
  FUN_00401660(auStack_2c9a + -10,0,0xffffffff);
  if (uStack_2c8c < 0x10) {
    return iStack_c;
  }
  _free(unaff_EBX);
  return extraout_EAX_17;
}


// ==== FUN_006af080 @ 0x006af080 ====

void FUN_006af080(void)

{
  void *_Memory;
  int *piVar1;
  uint in_ECX;
  int iVar2;
  undefined1 auStack_1b0 [12];
  undefined4 uStack_1a4;
  undefined3 *puStack_1a0;
  uint *puStack_19c;
  uint local_17c;
  int local_16c;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  int iStack_14c;
  uint uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined1 uStack_138;
  undefined1 uStack_137;
  uint local_134;
  undefined4 uStack_130;
  int iStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  void *pvStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  uint uStack_110;
  void *pvStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  uint uStack_f8;
  int iStack_f4;
  void *local_e8;
  void *pvStack_e4;
  undefined4 uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  undefined4 uStack_cc;
  int iStack_c8;
  undefined4 uStack_c4;
  void *pvStack_bc;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 uStack_98;
  undefined1 uStack_97;
  undefined4 uStack_94;
  int iStack_90;
  undefined4 uStack_8c;
  void *pvStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0xf;
  local_10 = 0;
  local_20 = 0;
  puStack_19c = (uint *)0x6af0c5;
  local_134 = in_ECX;
  FUN_00401740();
  local_17c = 1;
  _Memory = (void *)FUN_00503ac0();
  *(undefined1 *)((int)_Memory + 0x45) = 1;
  *(void **)((int)_Memory + 4) = _Memory;
  *(void **)_Memory = _Memory;
  *(void **)((int)_Memory + 8) = _Memory;
  if (*(char *)(in_ECX + 0xb) != '\0') {
    local_16c = 0x1c;
    do {
      FUN_00504d50();
      *(void **)((int)_Memory + 4) = _Memory;
      *(void **)_Memory = _Memory;
      *(void **)((int)_Memory + 8) = _Memory;
      iVar2 = **(int **)(in_ECX + 4);
      FUN_00402220(auStack_1b0,local_24,&DAT_009e0990);
      FUN_00404230(&local_e8);
      piVar1 = (int *)(**(code **)(iVar2 + 0x34))();
      if (0xf < uStack_d0) {
        _free(pvStack_e4);
        return;
      }
      uStack_d0 = 0xf;
      uStack_d4 = 0;
      pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
      if (piVar1 != (int *)0x0) {
        iStack_f4 = (**(code **)(*piVar1 + 0x30))();
        if (iStack_f4 != 0) {
          iVar2 = *(int *)(in_ECX + 0x10);
          uStack_148 = 0xf;
          iStack_14c = 0;
          pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
          uStack_13c = 1;
          uStack_138 = 0;
          uStack_137 = 0;
          uStack_140 = 0xff929292;
          uStack_144 = 2;
          if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x14) - iVar2) / 0x1c) <= local_17c)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          puStack_19c = (uint *)(local_16c + iVar2);
          puStack_1a0 = (undefined3 *)0x6af233;
          FUN_00401660();
          iVar2 = 5;
          if (iStack_14c == 4) {
            iVar2 = 0x10;
          }
          else if (iStack_14c == 6) {
            iVar2 = 0xb;
          }
          puStack_19c = (uint *)auStack_160;
          uStack_94 = 0;
          uStack_8c = 9;
          uStack_70 = 0xf;
          uStack_74 = 0;
          pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
          puStack_1a0 = (undefined3 *)0x6af29f;
          iStack_90 = iVar2;
          FUN_00401660();
          uStack_6c = uStack_144;
          uStack_64 = uStack_13c;
          uStack_60 = uStack_138;
          uStack_68 = uStack_140;
          uStack_5f = uStack_137;
          puStack_19c = (uint *)0x6af2ef;
          FUN_00505600();
          if (0xf < uStack_70) {
            _free(pvStack_84);
            return;
          }
          puStack_19c = (uint *)auStack_160;
          uStack_70 = 0xf;
          uStack_74 = 0;
          pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
          uStack_140 = 0xffffffff;
          uStack_cc = 1;
          uStack_c4 = 9;
          uStack_a8 = 0xf;
          uStack_ac = 0;
          pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
          puStack_1a0 = (undefined3 *)0x6af36f;
          iStack_c8 = iVar2;
          FUN_00401660();
          uStack_a4 = uStack_144;
          uStack_9c = uStack_13c;
          uStack_98 = uStack_138;
          uStack_a0 = uStack_140;
          uStack_97 = uStack_137;
          puStack_19c = (uint *)0x6af3bf;
          FUN_00505600();
          if (0xf < uStack_a8) {
            _free(pvStack_bc);
            return;
          }
          puStack_19c = (uint *)auStack_160;
          uStack_54 = 9;
          uStack_a8 = 0xf;
          uStack_ac = 0;
          pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
          uStack_5c = 4;
          uStack_38 = 0xf;
          uStack_3c = 0;
          pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
          puStack_1a0 = (undefined3 *)0x6af437;
          iStack_58 = iVar2;
          FUN_00401660();
          uStack_34 = uStack_144;
          uStack_30 = uStack_140;
          uStack_2c = uStack_13c;
          uStack_28 = uStack_138;
          uStack_27 = uStack_137;
          puStack_19c = (uint *)0x6af487;
          FUN_00505600();
          if (0xf < uStack_38) {
            _free(pvStack_4c);
            return;
          }
          iStack_12c = iVar2 + 2;
          puStack_19c = (uint *)auStack_160;
          uStack_128 = 0xb;
          uStack_38 = 0xf;
          uStack_3c = 0;
          pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
          uStack_140 = 0xff929292;
          uStack_130 = 2;
          pvStack_10c = (void *)0xf;
          uStack_110 = 0;
          pvStack_120 = (void *)((uint)pvStack_120 & 0xffffff00);
          puStack_1a0 = (undefined3 *)0x6af500;
          FUN_00401660();
          uStack_108 = uStack_144;
          uStack_104 = uStack_140;
          uStack_100 = uStack_13c;
          uStack_fc._0_2_ = CONCAT11(uStack_137,uStack_138);
          puStack_19c = (uint *)0x6af54d;
          FUN_00505600();
          if (0xf < pvStack_10c) {
            _free(pvStack_120);
            return;
          }
          pvStack_10c = (void *)0xf;
          uStack_110 = 0;
          pvStack_120 = (void *)((uint)pvStack_120 & 0xffffff00);
          FUN_00558a80();
          if (0xf < uStack_148) {
            _free(pvStack_15c);
            return;
          }
          uStack_148 = 0xf;
          iStack_14c = 0;
          pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
          in_ECX = local_134;
        }
      }
      local_16c = local_16c + 0x1c;
      local_17c = local_17c + 1;
    } while (local_17c <= *(byte *)(in_ECX + 0xb));
    if (5 < local_17c) goto LAB_006af70b;
  }
  do {
    iVar2 = **(int **)(in_ECX + 4);
    FUN_00402220(auStack_1b0,local_24,&DAT_009e0994);
    FUN_00404230(&local_e8);
    piVar1 = (int *)(**(code **)(iVar2 + 0x34))();
    if (0xf < uStack_d4) {
      puStack_19c = (uint *)0x6af625;
      _free(local_e8);
      return;
    }
    uStack_d4 = 0xf;
    uStack_d8 = 0;
    local_e8 = (void *)((uint)local_e8 & 0xffffff00);
    puStack_1a0 = (undefined3 *)(**(code **)(*piVar1 + 0x10))();
    local_134 = CONCAT13(local_134._3_1_,*puStack_1a0);
    uStack_130 = *(undefined4 *)(puStack_1a0 + 1);
    iStack_12c = *(int *)(puStack_1a0 + 2);
    uStack_128 = *(undefined4 *)(puStack_1a0 + 3);
    uStack_124 = *(undefined4 *)(puStack_1a0 + 4);
    pvStack_120 = *(void **)(puStack_1a0 + 5);
    uStack_11c = *(undefined4 *)(puStack_1a0 + 6);
    uStack_118 = *(undefined4 *)(puStack_1a0 + 7);
    puStack_19c = (uint *)0x0;
    puStack_1a0 = puStack_1a0 + 8;
    uStack_fc = 0xf;
    uStack_100 = 0;
    uStack_110 = uStack_110 & 0xffffff00;
    uStack_1a4 = 0x6af6b8;
    FUN_00401660();
    local_134 = local_134 & 0xffffff00;
    puStack_19c = (uint *)0x6af6c8;
    (**(code **)(*piVar1 + 0xc))();
    if (0xf < uStack_f8) {
      _free(pvStack_10c);
      return;
    }
    local_17c = local_17c + 1;
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
  } while (local_17c < 6);
LAB_006af70b:
  FUN_006adf60();
  puStack_19c = &local_134;
  puStack_1a0 = (undefined3 *)0x6af728;
  FUN_005054c0();
  _free(_Memory);
  return;
}


// ==== FUN_006af770 @ 0x006af770 ====

void FUN_006af770(char param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  undefined2 *puVar11;
  undefined2 extraout_var;
  undefined4 *puVar12;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 uVar13;
  byte bVar14;
  int iStack_30;
  undefined2 *puStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  int local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  uStack_24 = uVar5;
  piVar6 = (int *)(**(code **)(*DAT_00b5acc4 + 0x3c))();
  piStack_28 = piVar6;
  piVar7 = (int *)(**(code **)(*DAT_00b5aa30 + 0xc))();
  if (piVar7 != (int *)0x0) {
    while( true ) {
      iVar8 = (**(code **)(*piVar7 + 4))();
      if ((param_1 == *(char *)(iVar8 + 0x2b8a)) &&
         (cVar4 = (**(code **)(*piVar7 + 0x14))(uVar5), cVar4 != '\0')) {
        piVar6 = (int *)(**(code **)(*piVar6 + 0x18))
                                  (CONCAT22(extraout_var,*(undefined2 *)(iVar8 + 0x2bb8)));
        bVar14 = 0;
        uVar13 = extraout_var_00;
        if (piVar6 != (int *)0x0) {
          piVar6 = (int *)(**(code **)(*piVar6 + 0x18))();
          pbVar9 = (byte *)(**(code **)(*piVar6 + 0xc))();
          bVar14 = *pbVar9 & 0xf;
          uVar13 = extraout_var_01;
        }
        iVar10 = (**(code **)(*DAT_00b5acc8 + 0xc))
                           (uVar5,CONCAT22(uVar13,*(undefined2 *)(iVar8 + 0x2bb8)));
        bVar2 = bVar14;
        if (iVar10 != 1) {
          bVar2 = bVar14 + 1;
        }
        puVar11 = operator_new(0x48);
        iVar3 = local_20;
        if (puVar11 == (undefined2 *)0x0) {
          puVar11 = (undefined2 *)0x0;
        }
        else {
          *(undefined ***)(puVar11 + 2) = &PTR_FUN_009a51c4;
          *(undefined4 *)(puVar11 + 0xc) = 0;
          *(undefined4 *)(puVar11 + 0x22) = 0xf;
          *(undefined4 *)(puVar11 + 0x20) = 0;
          *(undefined1 *)(puVar11 + 0x18) = 0;
        }
        *puVar11 = *(undefined2 *)(iVar8 + 0x2bb8);
        *(undefined4 *)(puVar11 + 0x14) = *(undefined4 *)(iVar8 + 0x2bc4);
        iVar1 = (uint)bVar2 * 0x80 + 0x3c + iVar8;
        *(bool *)((int)puVar11 + 3) = iVar10 == 0;
        *(byte *)(puVar11 + 1) = bVar14;
        puVar12 = (undefined4 *)(puVar11 + 4);
        iStack_30 = 4;
        do {
          *puVar12 = *(undefined4 *)((int)puVar12 + (iVar1 - (int)(puVar11 + 2)));
          puVar12 = puVar12 + 1;
          iStack_30 = iStack_30 + -1;
        } while (iStack_30 != 0);
        *(undefined4 *)(puVar11 + 0xc) = *(undefined4 *)(iVar1 + 0x14);
        *(undefined1 *)(puVar11 + 0xe) = *(undefined1 *)(iVar1 + 0x18);
        *(undefined4 *)(puVar11 + 0x10) = *(undefined4 *)(iVar8 + 0x2b88);
        puVar11[0x12] = *(undefined2 *)(iVar8 + 0x2b8c);
        puStack_2c = puVar11;
        uVar5 = FUN_006ae410(auStack_1c,iVar8,puVar11,bVar2);
        FUN_00401660(uVar5,0,0xffffffff);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        iVar8 = *(int *)(iVar3 + 0x20);
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        if ((iVar8 == 0) ||
           ((uint)(*(int *)(iVar3 + 0x28) - iVar8 >> 2) <=
            (uint)(*(int *)(iVar3 + 0x24) - iVar8 >> 2))) {
          FUN_006afe40(*(undefined4 *)(iVar3 + 0x24),1,&puStack_2c);
        }
        else {
          puVar12 = *(undefined4 **)(iVar3 + 0x24);
          *puVar12 = puVar11;
          *(undefined4 **)(iVar3 + 0x24) = puVar12 + 1;
        }
      }
      piVar7 = (int *)(**(code **)(*DAT_00b5aa30 + 0x10))();
      if (piVar7 == (int *)0x0) break;
      piVar6 = piStack_28;
      uVar5 = uStack_24;
    }
  }
  return;
}


// ==== FUN_006af990 @ 0x006af990 ====

void FUN_006af990(void)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_006ade10();
  FUN_006af770(*(undefined1 *)(in_ECX + 9));
  FUN_006ade90();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_skill_tree_009e079c,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    (**(code **)(*piVar1 + 0x30))();
    FUN_0057df80(in_ECX + 0x1c);
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_006afa20 @ 0x006afa20 ====

undefined4 FUN_006afa20(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70140002) {
    FUN_006af990();
    return 1;
  }
  return 0;
}


// ==== FUN_006afa50 @ 0x006afa50 ====

undefined4 FUN_006afa50(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009e09ac,8);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5acb8 + 0xc))();
      *(undefined1 *)(in_ECX + 0x2c) = 0;
      return 1;
    }
    iVar2 = FUN_00405850(s_skill_tab_009e09b8,0,9);
    if (-1 < iVar2) {
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      FUN_00404fb0(param_2,0x5f,local_10);
      uVar3 = FUN_00405d30(3);
      cVar1 = thunk_FUN_00796f50(uVar3);
      if (cVar1 != *(char *)(in_ECX + 9)) {
        *(char *)(in_ECX + 9) = cVar1;
        FUN_006adf60();
        FUN_006af990();
      }
      FUN_00406250();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006afb20 @ 0x006afb20 ====

void FUN_006afb20(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_CharWindow_ui_skillwnd__009e0778,0x23);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006ae280();
    FUN_006af080();
    FUN_006af990();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006afbb0 @ 0x006afbb0 ====

void FUN_006afbb0(void)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009e09e0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[1] = 0;
  *(undefined1 *)((int)in_ECX + 9) = 1;
  *(undefined1 *)(in_ECX + 0xb) = 1;
  FUN_006afb20();
  return;
}


// ==== FUN_006afbf0 @ 0x006afbf0 ====

void FUN_006afbf0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = &PTR_FUN_009a51cc;
  iVar1 = 0xc;
  puVar2 = param_1;
  puVar3 = in_ECX;
  while( true ) {
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *puVar3 = *puVar2;
  }
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = &PTR_FUN_009a51c4;
  in_ECX[0xf] = param_1[0xf];
  in_ECX[0x10] = param_1[0x10];
  in_ECX[0x11] = param_1[0x11];
  in_ECX[0x12] = param_1[0x12];
  in_ECX[0x13] = param_1[0x13];
  *(undefined1 *)(in_ECX + 0x14) = *(undefined1 *)(param_1 + 0x14);
  in_ECX[0x15] = param_1[0x15];
  in_ECX[0x16] = param_1[0x16];
  in_ECX[0x17] = param_1[0x17];
  *(undefined1 *)(in_ECX + 0x18) = *(undefined1 *)(param_1 + 0x18);
  *(undefined1 *)((int)in_ECX + 0x61) = *(undefined1 *)((int)param_1 + 0x61);
  in_ECX[0x19] = param_1[0x19];
  in_ECX[0x1a] = param_1[0x1a];
  in_ECX[0x1b] = param_1[0x1b];
  in_ECX[0x1c] = param_1[0x1c];
  in_ECX[0x1d] = param_1[0x1d];
  in_ECX[0x1e] = param_1[0x1e];
  *(undefined1 *)(in_ECX + 0x1f) = *(undefined1 *)(param_1 + 0x1f);
  return;
}


// ==== FUN_006afca0 @ 0x006afca0 ====

void FUN_006afca0(int param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = in_ECX + 1;
  *in_ECX = &PTR_FUN_009a521c;
  iVar3 = (param_1 + 4) - (int)puVar2;
  iVar1 = 0x10;
  do {
    FUN_006afbf0(iVar3 + (int)puVar2);
    puVar2 = puVar2 + 0x20;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0x201] = *(undefined4 *)(param_1 + 0x804);
  return;
}


// ==== FUN_006afcf0 @ 0x006afcf0 ====

undefined4 FUN_006afcf0(void)

{
  return 0x70140009;
}


// ==== FUN_006afd00 @ 0x006afd00 ====

void FUN_006afd00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e09cc;
  FUN_006c1c60();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006afd30 @ 0x006afd30 ====

void FUN_006afd30(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_006afca0(param_1);
  *(undefined ***)(in_ECX + 0x808) = &PTR_FUN_009a51d4;
  puVar2 = (undefined4 *)(param_1 + 0x80c);
  puVar3 = (undefined4 *)(in_ECX + 0x80c);
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x85c) = *(undefined4 *)(param_1 + 0x85c);
  puVar2 = (undefined4 *)(param_1 + 0x860);
  puVar3 = (undefined4 *)(in_ECX + 0x860);
  for (iVar1 = 0x8ca; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x2b88) = *(undefined4 *)(param_1 + 0x2b88);
  *(undefined2 *)(in_ECX + 0x2b8c) = *(undefined2 *)(param_1 + 0x2b8c);
  *(undefined4 *)(in_ECX + 0x2b90) = *(undefined4 *)(param_1 + 0x2b90);
  *(undefined4 *)(in_ECX + 0x2b94) = *(undefined4 *)(param_1 + 0x2b94);
  *(undefined4 *)(in_ECX + 0x2b98) = *(undefined4 *)(param_1 + 0x2b98);
  *(undefined4 *)(in_ECX + 0x2b9c) = *(undefined4 *)(param_1 + 0x2b9c);
  *(undefined4 *)(in_ECX + 0x2ba0) = *(undefined4 *)(param_1 + 0x2ba0);
  *(undefined4 *)(in_ECX + 0x2ba4) = *(undefined4 *)(param_1 + 0x2ba4);
  *(undefined4 *)(in_ECX + 0x2ba8) = *(undefined4 *)(param_1 + 0x2ba8);
  *(undefined4 *)(in_ECX + 0x2bac) = *(undefined4 *)(param_1 + 0x2bac);
  *(undefined4 *)(in_ECX + 0x2bb0) = *(undefined4 *)(param_1 + 0x2bb0);
  *(undefined4 *)(in_ECX + 0x2bb4) = *(undefined4 *)(param_1 + 0x2bb4);
  *(undefined2 *)(in_ECX + 0x2bb8) = *(undefined2 *)(param_1 + 0x2bb8);
  *(undefined4 *)(in_ECX + 0x2bbc) = *(undefined4 *)(param_1 + 0x2bbc);
  *(undefined1 *)(in_ECX + 0x2bc0) = *(undefined1 *)(param_1 + 0x2bc0);
  *(undefined2 *)(in_ECX + 0x2bc2) = *(undefined2 *)(param_1 + 0x2bc2);
  *(undefined4 *)(in_ECX + 0x2bc4) = *(undefined4 *)(param_1 + 0x2bc4);
  *(undefined4 *)(in_ECX + 0x2bc8) = *(undefined4 *)(param_1 + 0x2bc8);
  return;
}


// ==== FUN_006afe40 @ 0x006afe40 ====

void FUN_006afe40(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 auStack_2a [18];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c770;
  local_10 = ExceptionList;
  local_14 = auStack_2a + -0xe;
  local_18 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 2;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    uVar7 = param_2;
    ExceptionList = &local_10;
    puVar1 = auStack_2a + -0xe;
    if (0x3fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar8 = FUN_0085b3b0();
      uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
      uVar2 = (uint)uVar8;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    if (uVar2 < iVar6 + uVar7) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
      }
      if (uVar2 < iVar6 + uVar7) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 2;
        }
        uVar2 = iVar3 + uVar7;
      }
      pvVar4 = operator_new(uVar2 * 4);
      local_8 = 0;
      uVar5 = FUN_005a6d90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00845740(uVar5,param_2,&local_18);
      FUN_005a6d90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)(iVar3 - param_1 >> 2) < uVar7) {
      FUN_005a6d90(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005a6d90(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00822d20(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006affa1 @ 0x006affa1 ====

void Catch_006affa1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


