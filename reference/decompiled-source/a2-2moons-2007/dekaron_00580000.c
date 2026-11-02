// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x580000-0x58ffff

// ==== FUN_00580010 @ 0x00580010 ====

void FUN_00580010(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  void **ppvVar5;
  void *apvStack_5c [2];
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  uint uStack_44;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  void *apvStack_24 [2];
  undefined1 uStack_1c;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  
  if (*(int *)(in_ECX + 0xd4) != 0) {
    puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    ppvVar5 = apvStack_5c;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppvVar5 = (void *)*puVar2;
      puVar2 = puVar2 + 1;
      ppvVar5 = ppvVar5 + 1;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = 0;
    uStack_34 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    if ((*(int *)(in_ECX + 0x74) == 1) || (*(char *)(in_ECX + 0x8a) == '\x01')) {
      iStack_2c = ((iStack_48 - *(int *)(in_ECX + 0x7c) * *(int *)(in_ECX + 0x84)) - iStack_50) / 2;
      iStack_30 = ((iStack_4c - *(int *)(in_ECX + 0x78) * *(int *)(in_ECX + 0x80)) - iStack_54) / 2;
      FUN_00401740(s_item__d__d____d__d____d__d_009bddec,0x1b);
      uVar3 = FUN_00404230(apvStack_5c);
      FUN_00796d50(uVar3);
      if (0xf < uStack_44) {
        _free(apvStack_5c[1]);
        return;
      }
    }
    else {
      iStack_30 = 0;
      iStack_2c = 0;
    }
    iStack_28 = *(int *)(in_ECX + 0x80) * *(int *)(in_ECX + 0x78);
    apvStack_24[0] = (void *)(*(int *)(in_ECX + 0x84) * *(int *)(in_ECX + 0x7c));
    FUN_00401740(s_Item___4d_txt_009bde08,0xd);
    uVar3 = FUN_00404230(apvStack_5c);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < uStack_44) {
      _free(apvStack_5c[1]);
      return;
    }
    uStack_4 = *(undefined1 *)(in_ECX + 0x70);
    uVar1 = (**(code **)(*DAT_00b5ad20 + 0x68))(*(undefined4 *)(in_ECX + 0xd4));
    uStack_8._0_2_ = CONCAT11(uVar1,(undefined1)uStack_8);
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009bde74;
      puVar2[0xc] = 0xf;
      puVar2[0xb] = 0;
      *(undefined1 *)(puVar2 + 7) = 0;
    }
    puVar2[1] = uStack_38;
    puVar2[2] = uStack_34;
    puVar2[3] = iStack_30;
    puVar2[4] = iStack_2c;
    puVar2[5] = iStack_28;
    FUN_00401660(apvStack_24,0,0xffffffff);
    *(undefined1 *)(puVar2 + 0xd) = (undefined1)uStack_8;
    *(undefined1 *)((int)puVar2 + 0x35) = uStack_8._1_1_;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    if (0xf < uStack_10) {
      _free(apvStack_24[0]);
      return;
    }
  }
  return;
}


// ==== FUN_00580260 @ 0x00580260 ====

void FUN_00580260(int *param_1)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = param_1 + 0x70;
  piVar3 = in_ECX + 0x1d;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  in_ECX[0x31] = *param_1;
  in_ECX[0x32] = param_1[1];
  in_ECX[0x33] = param_1[2];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  in_ECX[0x35] = in_ECX[0x23];
  FUN_00580010();
  return;
}


// ==== FUN_005802c0 @ 0x005802c0 ====

void FUN_005802c0(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xd4) != 0) || (*param_1 != 0)) {
    *(int *)(in_ECX + 0xd4) = *param_1;
    *(undefined4 *)(in_ECX + 0x80) = *param_2;
    *(undefined4 *)(in_ECX + 0x84) = param_2[1];
    if (*(int *)(in_ECX + 0xd4) != 0) {
      FUN_00580010();
      return;
    }
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      *puVar1 = &PTR_FUN_009bde5c;
      puVar1[1] = uVar2;
    }
    (**(code **)(*DAT_00b5ad24 + 4))(puVar1);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  }
  return;
}


// ==== FUN_00580350 @ 0x00580350 ====

void FUN_00580350(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_009bdce4;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar3 = puVar1;
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  puVar3[1] = uVar2;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar3);
  (**(code **)*puVar3)(1);
  FUN_0057f5c0();
  return;
}


// ==== FUN_005803b0 @ 0x005803b0 ====

void FUN_005803b0(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  byte bVar6;
  undefined4 *unaff_EBX;
  undefined4 *puVar7;
  uint unaff_EDI;
  undefined1 auStack_26 [10];
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  if ((*(int *)(in_ECX + 0xe4) == 0) ||
     (iVar3 = (**(code **)(**(int **)(in_ECX + 0xe4) + 0x48))(), iVar3 == 0)) {
    FUN_00580350();
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  FUN_00401740(s_Socket_009bde18,6);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_1c);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  puVar7 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = &PTR_FUN_009bdce4;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar7 = puVar4;
  }
  uVar5 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  puVar7[1] = uVar5;
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  bVar6 = 0;
  cVar1 = (**(code **)(*DAT_00b5ad20 + 0x58))(*(undefined4 *)(in_ECX + 0xe4));
  puVar4 = puVar7;
  if (cVar1 != '\0') {
    pvStack_1c = (void *)0x20;
    uStack_18 = 0x20;
    do {
      puVar4 = unaff_EBX;
      (**(code **)(*DAT_00b5ad20 + 0x5c))(auStack_26 + -10,*(undefined4 *)(in_ECX + 0xe4),puVar7);
      pvStack_1c = (void *)(unaff_EDI >> 0x10);
      unaff_EBX = puVar4;
      FUN_0057f1c0(auStack_26 + -10);
      bVar6 = bVar6 + 1;
      bVar2 = (**(code **)(*DAT_00b5ad20 + 0x58))(*(undefined4 *)(in_ECX + 0xe4));
    } while (bVar6 < bVar2);
  }
  (**(code **)(*DAT_00b5ad24 + 4))(puVar4);
  (**(code **)*puVar4)(1);
  FUN_0057f6d0();
  return;
}


// ==== FUN_00580580 @ 0x00580580 ====

void FUN_00580580(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005803b0();
  FUN_0057fd50();
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0xc4);
    local_8 = *(undefined4 *)(in_ECX + 200);
    local_4 = *(undefined4 *)(in_ECX + 0xcc);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_18 = *(undefined4 *)(in_ECX + 100);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00580660 @ 0x00580660 ====

void FUN_00580660(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_EBP;
  void *unaff_ESI;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_50 [2];
  undefined1 auStack_4e [2];
  void *local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_4c = (void *)(in_ECX + 0x24);
  FUN_00401740();
  if (*(int *)(in_ECX + 0xe4) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xe4) + 0x48))();
    if (iVar1 != 0) {
      uVar4 = *(undefined4 *)(in_ECX + 0xe4);
      iVar1 = (**(code **)(*DAT_00b5ad20 + 0x4c))(uVar4);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      iVar1 = iVar1 + 0x20;
      iVar5 = 0x1c;
      do {
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
        FUN_00401660(iVar1 + -0x1c,0,0xffffffff);
        if (*(char *)(iVar1 + -0x20) == '\0') {
          FUN_00401740(&DAT_009bdde8,0);
        }
        else {
          FUN_00401660(iVar1,0,0xffffffff);
        }
        FUN_004e6c20(auStack_3c);
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        iVar1 = iVar1 + 0x3c;
        iVar5 = iVar5 + -1;
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      } while (iVar5 != 0);
      uVar2 = (**(code **)(*DAT_00b5ad20 + 0x24))(*(undefined4 *)(in_ECX + 0xe4));
      uVar3 = (**(code **)(*DAT_00b5a794 + 8))(&uStack_40,0,uVar2 & 0xffff | 0x140000,auStack_50);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < pvStack_38) {
        _free(local_4c);
        return;
      }
      if (unaff_ESI != (void *)0x0) {
        FUN_004e65b0(unaff_ESI,unaff_EBP,auStack_50 + -0x10,uVar4);
        _free(unaff_ESI);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00580800 @ 0x00580800 ====

void FUN_00580800(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *in_ECX;
  
  if ((int *)in_ECX[0x39] != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*(int *)in_ECX[0x39] + 0x7c))();
    if (*piVar3 != 0) {
      FUN_00580660();
    }
  }
  *(undefined1 *)(in_ECX + 0x1c) = 1;
  iVar1 = *(int *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0x14);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar3 + 0x80))(4,iVar1 << 0x10 | uVar2);
  FUN_0057f620();
  return;
}


// ==== FUN_00580870 @ 0x00580870 ====

void FUN_00580870(undefined4 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xe4) = param_1;
  *(undefined1 *)(in_ECX + 0xe8) = param_2;
  FUN_005803b0();
  FUN_0057fd50();
  FUN_00580660();
  return;
}


// ==== FUN_005808a0 @ 0x005808a0 ====

undefined4 FUN_005808a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    if ((param_1[0xc] == 2) && (param_1[2] == 1)) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(0xd,0);
      return 1;
    }
    switch(param_1[2] + -1) {
    case 0:
      FUN_0057ffb0(param_1 + 3);
      return 1;
    case 2:
      FUN_0057f280(param_1 + 3);
      return 1;
    case 6:
      FUN_00580800(param_1 + 3);
      return 1;
    case 7:
      FUN_0057f690();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00580970 @ 0x00580970 ====

undefined4 FUN_00580970(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_005808a0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_0057f2a0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005809d0 @ 0x005809d0 ====

undefined4 FUN_005809d0(void)

{
  return 0x60000021;
}


// ==== FUN_005809e0 @ 0x005809e0 ====

void FUN_005809e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00580a10 @ 0x00580a10 ====

undefined4 FUN_00580a10(void)

{
  return 0x60000023;
}


// ==== FUN_00580a20 @ 0x00580a20 ====

undefined4 FUN_00580a20(void)

{
  return 0x60000022;
}


// ==== FUN_00580a30 @ 0x00580a30 ====

undefined4 FUN_00580a30(void)

{
  return 0x60000020;
}


// ==== FUN_00580a40 @ 0x00580a40 ====

void FUN_00580a40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bde74;
  FUN_00713800();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00580a70 @ 0x00580a70 ====

void FUN_00580a70(byte param_1)

{
  void *in_ECX;
  
  FUN_0057f810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00580a90 @ 0x00580a90 ====

void FUN_00580a90(int *param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int aiStack_28 [10];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  piVar3 = aiStack_28;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *piVar1;
    piVar1 = piVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x80))
            (1,(int)ROUND(((float)(*param_1 - aiStack_28[2]) / (float)*(int *)(in_ECX + 0x78)) *
                          DAT_0099d100) << 0x10 |
               (int)ROUND(((float)(param_1[1] - aiStack_28[3]) / (float)*(int *)(in_ECX + 0x7c)) *
                          DAT_0099d100));
  return;
}


// ==== FUN_00580b60 @ 0x00580b60 ====

void FUN_00580b60(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  in_ECX[0x1e] = param_1[0x6a];
  in_ECX[0x1f] = param_1[0x6b];
  in_ECX[0x20] = *param_1;
  in_ECX[0x21] = param_1[1];
  in_ECX[0x22] = param_1[2];
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  in_ECX[0x1c] = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) / in_ECX[0x1f];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_00580be0 @ 0x00580be0 ====

void FUN_00580be0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xc4) = param_1;
  return;
}


// ==== FUN_00580bf0 @ 0x00580bf0 ====

undefined4 FUN_00580bf0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  return 1;
}


// ==== FUN_00580c20 @ 0x00580c20 ====

undefined4 FUN_00580c20(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 != iVar1) {
    return 0;
  }
  if (param_1[2] == 1) {
    FUN_00580a90(param_1 + 7);
  }
  else if (param_1[2] == 3) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x80))(2,0);
    return 1;
  }
  return 1;
}


// ==== FUN_00580c80 @ 0x00580c80 ====

void FUN_00580c80(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x80);
    local_8 = *(undefined4 *)(in_ECX + 0x84);
    local_4 = *(undefined4 *)(in_ECX + 0x88);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00580d50 @ 0x00580d50 ====

undefined4 FUN_00580d50(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = FUN_0057f420();
  if (cVar1 != '\0') {
    iVar3 = *DAT_00b5ad20;
    uVar2 = FUN_0057f270();
    iVar3 = (**(code **)(iVar3 + 0x18))(uVar2);
    if (param_1 == 1) {
      if (iVar3 == 0xc) {
        return 1;
      }
    }
    else if (param_1 == 0) {
      if ((((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 0xc)) || ((iVar3 == 0x11 || (iVar3 == 0x12)))
         ) {
        return 1;
      }
    }
    else if ((param_1 == 3) && (iVar3 == 0x900)) {
      return 0x901;
    }
  }
  return 0;
}


// ==== FUN_00580dd0 @ 0x00580dd0 ====

undefined4 FUN_00580dd0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    if (*(char *)(iVar2 + 1) != '\0') {
      iVar2 = (**(code **)(*param_1 + 4))();
      if (iVar2 == 0x10001) {
        cVar1 = FUN_00580c20(param_1);
        if (cVar1 != '\0') {
          return 1;
        }
      }
      return 0;
    }
  }
  return 0;
}


// ==== FUN_00580e20 @ 0x00580e20 ====

void FUN_00580e20(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  void *_Memory;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int in_ECX;
  undefined4 *puVar8;
  
  puVar2 = *(undefined4 **)(in_ECX + 0xd0);
  puVar4 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar8 = puVar4;
          if (puVar8 == puVar2) {
            _Memory = *(void **)(*(int *)(in_ECX + 0xd0) + 4);
            if (*(char *)((int)_Memory + 0x19) == '\0') {
              FUN_00581820(*(undefined4 *)((int)_Memory + 8));
              _free(_Memory);
              return;
            }
            *(int *)(*(int *)(in_ECX + 0xd0) + 4) = *(int *)(in_ECX + 0xd0);
            *(undefined4 *)(in_ECX + 0xd4) = 0;
            *(undefined4 *)*(undefined4 *)(in_ECX + 0xd0) = *(undefined4 *)(in_ECX + 0xd0);
            *(int *)(*(int *)(in_ECX + 0xd0) + 8) = *(int *)(in_ECX + 0xd0);
                    /* WARNING: Could not recover jumptable at 0x00580eef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
            return;
          }
          piVar3 = (int *)puVar8[5];
          iVar5 = (**(code **)(*piVar3 + 0x3c))();
          if (iVar5 != 0) {
            piVar6 = (int *)(**(code **)(*piVar3 + 0x3c))();
            (**(code **)(*piVar6 + 0x7c))(piVar3);
          }
          puVar4 = puVar8;
        } while (*(char *)((int)puVar8 + 0x19) != '\0');
        puVar4 = (undefined4 *)puVar8[2];
        if (*(char *)((int)puVar4 + 0x19) != '\0') break;
        cVar1 = *(char *)((int)*puVar4 + 0x19);
        puVar8 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar8 + 0x19);
          puVar4 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
        }
      }
      puVar4 = (undefined4 *)puVar8[1];
    } while (*(char *)((int)puVar4 + 0x19) != '\0');
    do {
      puVar7 = puVar4;
      puVar4 = puVar7;
      if (puVar8 != (undefined4 *)puVar7[2]) break;
      puVar4 = (undefined4 *)puVar7[1];
      puVar8 = puVar7;
    } while (*(char *)((int)puVar4 + 0x19) == '\0');
  } while( true );
}


// ==== FUN_00580f00 @ 0x00580f00 ====

void FUN_00580f00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  int in_ECX;
  
  if (*(char *)(param_1 + 0xc5 + in_ECX) != '\0') {
    puVar1 = *(undefined4 **)(in_ECX + 0xd0);
    puVar2 = (undefined4 *)*puVar1;
    while (puVar2 != puVar1) {
      iVar6 = (**(code **)(*(int *)puVar2[5] + 0x30))();
      cVar5 = FUN_00580d50(iVar6,param_1);
      if (cVar5 != '\0') {
        *(undefined1 *)(iVar6 + 0xe0) = 0;
      }
      if (*(char *)((int)puVar2 + 0x19) == '\0') {
        puVar3 = (undefined4 *)puVar2[2];
        if (*(char *)((int)puVar3 + 0x19) == '\0') {
          cVar5 = *(char *)((int)*puVar3 + 0x19);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
          while (cVar5 == '\0') {
            cVar5 = *(char *)((int)*puVar3 + 0x19);
            puVar2 = puVar3;
            puVar3 = (undefined4 *)*puVar3;
          }
        }
        else {
          cVar5 = *(char *)((int)puVar2[1] + 0x19);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
          while ((puVar2 = puVar4, cVar5 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
            cVar5 = *(char *)((int)puVar2[1] + 0x19);
            puVar4 = (undefined4 *)puVar2[1];
            puVar3 = puVar2;
          }
        }
      }
    }
    *(undefined1 *)(param_1 + 0xc5 + in_ECX) = 0;
  }
  return;
}


// ==== FUN_00580fb0 @ 0x00580fb0 ====

void FUN_00580fb0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  int in_ECX;
  
  iVar8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar9 = (int *)(**(code **)(*param_1 + 0x18))();
  iVar1 = *piVar9;
  piVar9 = (int *)(**(code **)(*param_1 + 0x18))();
  iVar10 = (**(code **)(*param_1 + 0x18))();
  puVar2 = *(undefined4 **)(in_ECX + 0xd0);
  iVar10 = *(int *)(iVar10 + 4);
  puVar3 = (undefined4 *)*puVar2;
  iVar4 = *piVar9;
  while (puVar3 != puVar2) {
    uVar11 = (**(code **)(*(int *)puVar3[5] + 0x30))();
    cVar7 = FUN_00580d50(uVar11,param_2);
    if (cVar7 != '\0') {
      FUN_0057f480(iVar8 - iVar1,iVar10 - iVar4);
    }
    if (*(char *)((int)puVar3 + 0x19) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x19) == '\0') {
        cVar7 = *(char *)((int)*puVar5 + 0x19);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar7 == '\0') {
          cVar7 = *(char *)((int)*puVar5 + 0x19);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar7 = *(char *)((int)puVar3[1] + 0x19);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar7 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar7 = *(char *)((int)puVar3[1] + 0x19);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00581080 @ 0x00581080 ====

undefined4 FUN_00581080(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00581120 @ 0x00581120 ====

void FUN_00581120(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_005523f0(param_1);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00581150 @ 0x00581150 ====

/* WARNING: Removing unreachable block (ram,0x005811a2) */

void FUN_00581150(int *param_1,int param_2)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  piVar3 = (int *)(**(code **)(*param_1 + 0x20))(param_2);
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s_pCoolTime____NULL_009bdf64,0x11);
    FUN_00406880(auStack_1a + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  cVar2 = (**(code **)(*piVar3 + 0xc))();
  if (cVar2 == '\0') {
    *(undefined1 *)(param_2 + 0xc5 + in_ECX) = 1;
    FUN_00580fb0(piVar3,param_2);
    return;
  }
  FUN_00580f00(param_2);
  return;
}


// ==== FUN_005811f0 @ 0x005811f0 ====

void FUN_005811f0(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 0xc4) != '\0') {
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    if (iVar3 != 0) {
      piVar1 = *(int **)(iVar3 + 0x78);
      if (piVar1 == (int *)0x0) {
        FUN_00401830(s_pCoolTimeManager____NULL_009bdf48);
        FUN_00406880(auStack_1c);
        if (uStack_4 < 0x10) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        _free(pvStack_18);
        return;
      }
      iVar3 = *piVar1;
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      (**(code **)(iVar3 + 0x18))(uVar4);
      FUN_00581150(piVar1,0);
      FUN_00581150(piVar1,1);
      FUN_00581150(piVar1,3);
    }
  }
  return;
}


// ==== FUN_00581280 @ 0x00581280 ====

void FUN_00581280(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009bdf84;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  FUN_00581c40(local_4,*(undefined4 *)in_ECX[0x34],(undefined4 *)in_ECX[0x34]);
  _free((void *)in_ECX[0x34]);
  return;
}


// ==== FUN_00581310 @ 0x00581310 ====

void FUN_00581310(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bdf84;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x2b] = 0xf;
  in_ECX[0x2a] = 0;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  in_ECX[0x2c] = 1;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 1;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  *(undefined1 *)((int)in_ECX + 0xbd) = 0;
  iVar1 = FUN_005818f0();
  in_ECX[0x34] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[0x34] + 4) = in_ECX[0x34];
  *(undefined4 *)in_ECX[0x34] = in_ECX[0x34];
  *(undefined4 *)(in_ECX[0x34] + 8) = in_ECX[0x34];
  in_ECX[0x35] = 0;
  in_ECX[0x1c] = 1;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x30] = 0;
  *(undefined1 *)(in_ECX + 0x31) = 0;
  *(undefined1 *)((int)in_ECX + 0xc9) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  in_ECX[0x1d] = 1;
  return;
}


// ==== FUN_005813f0 @ 0x005813f0 ====

void FUN_005813f0(void)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 *_Memory;
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int in_ECX;
  char *pcVar10;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined4 *unaff_retaddr;
  undefined1 uStack_90;
  undefined1 uStack_8f;
  undefined1 uStack_8e;
  undefined4 uStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 uStack_6c;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  (**(code **)(*DAT_00b5a7ac + 4))();
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0xf);
  uStack_8e = 1;
  uStack_8c = 0;
  iStack_88 = 0;
  iStack_84 = 0;
  iStack_80 = 0;
  iStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_58 = 0xf;
  uStack_5c = 0;
  uStack_6c = 0;
  uStack_3c = 0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    _Memory = (undefined4 *)0x0;
  }
  else {
    _Memory = (undefined4 *)FUN_00505f10();
  }
  _Memory[0x71] = 0x20;
  _Memory[0x72] = 0x20;
  _Memory[0x70] = 0;
  *(undefined1 *)(_Memory + 0x75) = 0;
  *(undefined1 *)((int)_Memory + 0x1d5) = 0;
  *(undefined1 *)((int)_Memory + 0x1d6) = 0;
  _Memory[0x76] = 0;
  _Memory[0x73] = 1;
  _Memory[0x74] = 1;
  iStack_84 = unaff_retaddr[2] * *(int *)(in_ECX + 0x7c);
  iStack_88 = unaff_retaddr[1] * *(int *)(in_ECX + 0x78);
  iVar6 = (**(code **)(*(int *)*unaff_retaddr + 0x2c))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x50))();
  FUN_00401740(s__s__d__d_009bdf3c,8);
  iVar7 = FUN_00404230(auStack_20);
  if (*(uint *)(iVar7 + 0x18) < 0x10) {
    pcVar10 = (char *)(iVar7 + 4);
  }
  else {
    pcVar10 = *(char **)(iVar7 + 4);
  }
  pcVar8 = pcVar10;
  do {
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar3 != '\0');
  FUN_00401740(pcVar10,(int)pcVar8 - (int)(pcVar10 + 1));
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  FUN_00401660(auStack_54,0,0xffffffff);
  iStack_80 = (uint)*(byte *)(iVar6 + 0x30) * *(int *)(in_ECX + 0x78) + iStack_88;
  iStack_7c = (uint)*(byte *)(iVar6 + 0x31) * *(int *)(in_ECX + 0x7c) + iStack_84;
  uStack_8c = 100;
  uStack_90 = 1;
  uStack_8f = 1;
  *_Memory = *(undefined4 *)(in_ECX + 0x80);
  _Memory[1] = *(undefined4 *)(in_ECX + 0x84);
  _Memory[2] = *(undefined4 *)(in_ECX + 0x88);
  _Memory[0x71] = *(undefined4 *)(in_ECX + 0x78);
  _Memory[0x72] = *(undefined4 *)(in_ECX + 0x7c);
  bVar1 = *(byte *)(iVar6 + 0x31);
  _Memory[0x73] = (uint)*(byte *)(iVar6 + 0x30);
  _Memory[0x74] = (uint)bVar1;
  uVar9 = (**(code **)(*(int *)*unaff_retaddr + 0x1c))();
  _Memory[0x76] = uVar9 & 0xffff;
  (**(code **)(*unaff_EBX + 8))(&uStack_90);
  piVar2 = *(int **)(in_ECX + 4);
  if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*unaff_EBP + 0x74))(piVar2), cVar3 != '\0')) {
    cVar3 = (**(code **)(*piVar2 + 0x78))(unaff_EBP);
    if (cVar3 == '\0') {
      (**(code **)(*unaff_ESI + 0x74))(0);
    }
    else {
      iVar6 = (**(code **)(*piVar4 + 0x38))();
      unaff_EBP[1] = iVar6;
    }
  }
  (**(code **)(*unaff_EBX + 0x38))(unaff_EBP);
  (**(code **)(*unaff_EBP + 0x1c))(&uStack_5c);
  (**(code **)(*unaff_EDI + 0x2c))(unaff_ESI);
  (**(code **)(*unaff_EDI + 0x24))(_Memory);
  FUN_00580870(*unaff_retaddr,1);
  FUN_0057f430(unaff_retaddr[3]);
  if ((*(char *)(in_ECX + 0xc4) == '\x01') &&
     (((((iVar6 = unaff_EDI[2], iVar6 == 1 || (iVar6 == 2)) || (iVar6 == 0xc)) ||
       ((iVar6 == 0x11 || (iVar6 == 0x12)))) ||
      ((iVar6 == 0x900 || ((iVar6 == 0x901 || (iVar6 == 0x902)))))))) {
    FUN_0057f910(0);
  }
  FUN_00505d80();
  _free(_Memory);
  return;
}


// ==== FUN_005817b0 @ 0x005817b0 ====

void FUN_005817b0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc0) + 8);
  for (iVar2 = *(int *)(*(int *)(in_ECX + 0xc0) + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
    FUN_005813f0(iVar2);
  }
  return;
}


// ==== FUN_005817e0 @ 0x005817e0 ====

void FUN_005817e0(int param_1,undefined1 param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  *(undefined1 *)(in_ECX + 0xc9) = param_2;
  FUN_00580e20();
  *(int *)(in_ECX + 0xc0) = param_1;
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
    FUN_005813f0(iVar2);
  }
  return;
}


// ==== FUN_00581820 @ 0x00581820 ====

void FUN_00581820(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_00581820(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00581860 @ 0x00581860 ====

void * FUN_00581860(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982170;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00894570(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005818d5 @ 0x005818d5 ====

void Catch_005818d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005818f0 @ 0x005818f0 ====

void FUN_005818f0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982180;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0058197a @ 0x0058197a ====

void Catch_0058197a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00581c40 @ 0x00581c40 ====

void FUN_00581c40(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00581820(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x19);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x19);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x19);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00850bf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00581d00 @ 0x00581d00 ====

void FUN_00581d00(byte param_1)

{
  void *in_ECX;
  
  FUN_00581280();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00581d20 @ 0x00581d20 ====

undefined1 FUN_00581d20(void)

{
  return 0;
}


// ==== FUN_00581d30 @ 0x00581d30 ====

undefined4 FUN_00581d30(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  return 1;
}


// ==== FUN_00581d60 @ 0x00581d60 ====

void FUN_00581d60(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x84);
    local_8 = *(undefined4 *)(in_ECX + 0x88);
    local_4 = *(undefined4 *)(in_ECX + 0x8c);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00581e30 @ 0x00581e30 ====

undefined4 FUN_00581e30(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00581ed0 @ 0x00581ed0 ====

void FUN_00581ed0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_005523f0(param_1);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00581f60 @ 0x00581f60 ====

undefined4 FUN_00581f60(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 ****ppppuVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_1c [4];
  undefined4 ****appppuStack_18 [4];
  undefined4 uStack_8;
  uint uStack_4;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__tab1_009be030);
    FUN_00402220(auStack_1c,uVar2);
    ppppuVar3 = appppuStack_18[0];
    if (uStack_4 < 0x10) {
      ppppuVar3 = appppuStack_18;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppuVar3,uStack_8);
    if (0xf < uStack_4) {
      _free(appppuStack_18[0]);
      return extraout_EAX;
    }
    if (iVar4 == 0) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x80))(1,0);
      return 1;
    }
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__tab2_009be038);
    FUN_00402220(auStack_1c,uVar2);
    cVar1 = FUN_00423420(param_2,auStack_1c);
    if (0xf < uStack_4) {
      _free(appppuStack_18[0]);
      return extraout_EAX_00;
    }
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(in_ECX + 4) + 0x80))(1,1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00582060 @ 0x00582060 ====

void FUN_00582060(undefined1 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  void *unaff_EBX;
  undefined4 local_20;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  
  FUN_00558e00(&local_20,&param_1);
  in_ECX[0x21] = *(int *)((int)local_20 + 0x10);
  in_ECX[0x22] = *(int *)((int)local_20 + 0x14);
  in_ECX[0x23] = *(int *)((int)local_20 + 0x18);
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__tab1_009be030);
  FUN_00402220(&local_20,uVar1);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x4c))(&local_20);
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00558730(1);
  uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__tab2_009be038);
  FUN_00402220((int)register0x00000010 + -0x24,uVar1);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x4c))((int)register0x00000010 + -0x24);
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    (**(code **)(*piVar2 + 0x30))();
    FUN_00558730(0);
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_00582170 @ 0x00582170 ====

void FUN_00582170(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__tab1_009be030);
  FUN_00402220(&uStack_1c,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00558730(0);
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__tab2_009be038);
  FUN_00402220((int)register0x00000010 + -0x20,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))((int)register0x00000010 + -0x20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    (**(code **)(*piVar2 + 0x30))();
    FUN_00558730(1);
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_00582240 @ 0x00582240 ====

void FUN_00582240(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009be04c;
  *(undefined2 *)(in_ECX + 0x1c) = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x1f] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x1f] + 4) = in_ECX[0x1f];
  *(undefined4 *)in_ECX[0x1f] = in_ECX[0x1f];
  *(undefined4 *)(in_ECX[0x1f] + 8) = in_ECX[0x1f];
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0xf;
  *(undefined1 *)(in_ECX + 0x27) = 0;
  in_ECX[0x2e] = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)((int)in_ECX + 0xc1) = 0;
  in_ECX[0x2d] = 1;
  in_ECX[0x2f] = 1;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00582300 @ 0x00582300 ====

void FUN_00582300(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_4 [4];
  
  *in_ECX = &PTR_FUN_009be04c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  if ((uint)in_ECX[0x2c] < 0x10) {
    in_ECX[0x2c] = 0xf;
    in_ECX[0x2b] = 0;
    *(undefined1 *)(in_ECX + 0x27) = 0;
    FUN_00504490(auStack_4,*(undefined4 *)in_ECX[0x1f],(undefined4 *)in_ECX[0x1f]);
    _free((void *)in_ECX[0x1f]);
    return;
  }
  _free((void *)in_ECX[0x27]);
  return;
}


// ==== FUN_00582390 @ 0x00582390 ====

void FUN_00582390(int param_1)

{
  int *piVar1;
  int *in_ECX;
  int *local_4;
  
  piVar1 = (int *)(param_1 + 0x1b4);
  *(undefined1 *)(in_ECX + 0x1d) = *(undefined1 *)(param_1 + 0x1b0);
  local_4 = in_ECX;
  if (in_ECX + 0x1e != piVar1) {
    FUN_00504490(&param_1,*(undefined4 *)in_ECX[0x1f],(undefined4 *)in_ECX[0x1f]);
    FUN_005040e0(piVar1);
  }
  param_1 = 9;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 == (int *)in_ECX[0x1f]) {
    in_ECX[0x21] = 0;
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    return;
  }
  in_ECX[0x21] = local_4[4];
  in_ECX[0x22] = local_4[5];
  in_ECX[0x23] = local_4[6];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_00582440 @ 0x00582440 ====

void FUN_00582440(char param_1)

{
  if (param_1 == '\0') {
    FUN_00582060();
    return;
  }
  if (param_1 == '\x01') {
    FUN_00582060();
    return;
  }
  return;
}


// ==== FUN_00582470 @ 0x00582470 ====

void FUN_00582470(byte param_1)

{
  void *in_ECX;
  
  FUN_00582300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005824f0 @ 0x005824f0 ====

void FUN_005824f0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00582510 @ 0x00582510 ====

undefined4 FUN_00582510(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00582560 @ 0x00582560 ====

undefined4 FUN_00582560(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 == iVar2) {
    iVar2 = param_1[2];
    if ((iVar2 == 1) || (iVar2 == 2)) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar1 + 0x80))(1,0);
      return 1;
    }
    if (iVar2 == 3) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar1 + 0x80))(2,0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005825e0 @ 0x005825e0 ====

undefined4 FUN_005825e0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if ((iVar3 != iVar2) || (param_1[2] != 1)) {
    return 0;
  }
  if (param_1[6] == 1) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(1,0);
  }
  iVar2 = (**(code **)(*(int *)in_ECX[1] + 4))();
  if (param_1[0xb] == iVar2) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(10,0);
    return 1;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(10,1);
  return 1;
}


// ==== FUN_00582680 @ 0x00582680 ====

undefined4 FUN_00582680(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x3c))();
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00582560(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_005825e0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005826e0 @ 0x005826e0 ====

void FUN_005826e0(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x70);
    local_8 = *(undefined4 *)(in_ECX + 0x74);
    local_4 = *(undefined4 *)(in_ECX + 0x78);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_005827b0 @ 0x005827b0 ====

undefined4 FUN_005827b0(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00582840 @ 0x00582840 ====

void FUN_00582840(int *param_1)

{
  code *pcVar1;
  int *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 != (int *)0x0) {
    *(char *)(in_ECX + 0x1f) = (char)param_1[0x69];
    *(undefined1 *)((int)in_ECX + 0x7d) = *(undefined1 *)((int)param_1 + 0x1a5);
    in_ECX[0x1c] = *param_1;
    in_ECX[0x1d] = param_1[1];
    in_ECX[0x1e] = param_1[2];
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pProperty_009be130,0xb);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00582910 @ 0x00582910 ====

void FUN_00582910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = param_1;
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  FUN_0056ac60(&param_2,&local_10);
  return;
}


// ==== FUN_00582a70 @ 0x00582a70 ====

void FUN_00582a70(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009be194;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00504490(local_4,*(undefined4 *)in_ECX[0x21],(undefined4 *)in_ECX[0x21]);
  _free((void *)in_ECX[0x21]);
  return;
}


// ==== FUN_00582ad0 @ 0x00582ad0 ====

void FUN_00582ad0(char param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *apvStack_50 [4];
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  undefined1 uStack_2c;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__pcname_009be154);
  FUN_00402220(apvStack_50,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(apvStack_50);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x30))();
  }
  if (0xf < uStack_3c) {
    _free(apvStack_50[0]);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  apvStack_50[0] = (void *)((uint)apvStack_50[0] & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    uStack_18 = 0xf;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_1c = 0;
    uStack_2c = 0;
    uStack_14 = 1;
    iStack_10 = 0;
    uStack_c = 1;
    uStack_8 = 0;
    uStack_7 = 0;
    FUN_0056fe50(&uStack_38);
    FUN_00401660(unaff_retaddr,0,0xffffffff);
    iStack_10 = (-(uint)(param_1 != '\0') & 0xffffff01) - 1;
    (**(code **)(*piVar2 + 8))(&uStack_38);
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
  }
  return;
}


// ==== FUN_00582bc0 @ 0x00582bc0 ====

/* WARNING: Removing unreachable block (ram,0x00582d31) */

int FUN_00582bc0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int in_ECX;
  int iVar3;
  int unaff_retaddr;
  undefined1 auStack_6a [22];
  undefined1 auStack_54 [4];
  void *apvStack_50 [4];
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__pcname_009be154);
  FUN_00402220(apvStack_50,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(apvStack_50);
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
  }
  if (0xf < uStack_3c) {
    _free(apvStack_50[0]);
    return extraout_EAX;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  apvStack_50[0] = (void *)((uint)apvStack_50[0] & 0xffffff00);
  if (iVar3 == 0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009be13c,0);
    return unaff_retaddr;
  }
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  uStack_14 = 1;
  uStack_10 = 0;
  uStack_c = 1;
  uStack_8 = 0;
  uStack_7 = 0;
  FUN_0056fe50(&uStack_38);
  iVar3 = FUN_00405850(&DAT_009be140,0,2);
  FUN_00401660(auStack_30,0,0xffffffff);
  if (iVar3 != -1) {
    uStack_3c = 0xf;
    uStack_40 = 0;
    apvStack_50[0] = (void *)((uint)apvStack_50[0] & 0xffffff00);
    FUN_00401660(auStack_6a + -6,iVar3 + 2,0xffffffff);
    FUN_00401660(auStack_54,0,0xffffffff);
    if (0xf < uStack_3c) {
      _free(apvStack_50[0]);
      return extraout_EAX_00;
    }
  }
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(auStack_6a + -6,0,0xffffffff);
  if (uStack_18 < 0x10) {
    return unaff_retaddr;
  }
  _free(pvStack_2c);
  return extraout_EAX_01;
}


// ==== FUN_00582d70 @ 0x00582d70 ====

void FUN_00582d70(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__follow_009be168);
  FUN_00402220(apvStack_1c,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(apvStack_1c);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00558730(unaff_retaddr);
    }
  }
  return;
}


// ==== FUN_00582df0 @ 0x00582df0 ====

void FUN_00582df0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *apvStack_6c [4];
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  undefined1 uStack_2c;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__level_009be15c);
  FUN_00402220(apvStack_6c,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(apvStack_6c);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x30))();
  }
  if (0xf < uStack_58) {
    _free(apvStack_6c[0]);
    return;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  apvStack_6c[0] = (void *)((uint)apvStack_6c[0] & 0xffffff00);
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  uStack_14 = 1;
  uStack_10 = 0;
  uStack_c = 1;
  uStack_8 = 0;
  uStack_7 = 0;
  FUN_0056fe50(&uStack_38);
  FUN_00401740(s_LV__d_009be144,5);
  uVar1 = FUN_00404230(auStack_54);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  (**(code **)(*piVar2 + 8))(&uStack_38);
  if (uStack_1c < 0x10) {
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_00582f10 @ 0x00582f10 ====

void FUN_00582f10(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&PTR_LAB_009be164);
  FUN_00402220(apvStack_1c,uVar1);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x4c))(apvStack_1c);
  if (uStack_8 < 0x10) {
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    uStack_8 = 0xf;
    (**(code **)(*piVar2 + 0x30))();
    FUN_00587ba0(unaff_retaddr);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    return;
  }
  _free(apvStack_1c[0]);
  return;
}


// ==== FUN_00582f90 @ 0x00582f90 ====

undefined4 FUN_00582f90(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if (param_1 == 0) {
    if ((param_3 == 1) || (param_3 == 3)) {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar2 + 0x80))(1,0);
      return 1;
    }
    if (param_3 == 2) {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar2 + 0x80))(2,0);
    }
    return 1;
  }
  if ((param_1 == 1) && (param_3 == 1)) {
    uVar3 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__follow_009be168);
    FUN_00402220(auStack_1c,uVar3);
    cVar1 = FUN_00423420(param_2,auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
    if (cVar1 != '\0') {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar2 + 0x80))(1,100);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00583070 @ 0x00583070 ====

void FUN_00583070(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009be194;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x21] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x21] + 4) = in_ECX[0x21];
  *(undefined4 *)in_ECX[0x21] = in_ECX[0x21];
  *(undefined4 *)(in_ECX[0x21] + 8) = in_ECX[0x21];
  in_ECX[0x22] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_005830e0 @ 0x005830e0 ====

/* WARNING: Removing unreachable block (ram,0x0058331e) */
/* WARNING: Removing unreachable block (ram,0x0058312f) */

void FUN_005830e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined1 *puVar1;
  code *pcVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uStack_520;
  void *local_4ec;
  undefined1 auStack_4e0 [4];
  undefined4 uStack_4dc;
  uint uStack_4d8;
  undefined1 local_4cc;
  undefined4 local_4bc;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined4 local_4b0;
  undefined4 local_4ac;
  undefined1 local_4a6;
  void *local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined4 local_494;
  uint local_490 [3];
  undefined1 local_484 [4];
  undefined4 uStack_480;
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined4 uStack_418;
  undefined1 auStack_414 [4];
  undefined4 *puStack_410;
  undefined1 uStack_368;
  undefined1 uStack_367;
  undefined1 auStack_364 [4];
  undefined4 *puStack_360;
  int iStack_c;
  undefined4 uStack_4;
  
  if (param_4 == (int *)0x0) {
    uStack_520 = s_i_pBaseComposite____NULL_009be114;
    FUN_00401740();
    uStack_520 = (char *)0x583125;
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  local_4a6 = 1;
  local_4a4 = (void *)0x0;
  local_4a0 = 0;
  local_49c = 0;
  local_498 = 0;
  local_494 = 0;
  local_490[0] = 0;
  local_490[1] = 0;
  local_470 = 0xf;
  local_474 = 0;
  local_484[0] = 0;
  local_4b8 = 0xf;
  local_4bc = 0;
  local_4cc = 0;
  local_4b4 = 0;
  local_4b0 = 0;
  local_4ac = 0;
  uStack_520 = (char *)0x5831a3;
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_520 = (char *)param_2;
  piVar5 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  piVar6 = (int *)(**(code **)(*param_4 + 0x4c))(param_2);
  uVar7 = (**(code **)(*piVar6 + 0x10))();
  FUN_004fed70(uVar7);
  FUN_00401660(uStack_4,0,0xffffffff);
  FUN_00401660(local_490,0,0xffffffff);
  puVar9 = &local_4b0;
  (**(code **)(*piVar4 + 8))();
  (**(code **)(*piVar5 + 0x38))(piVar4);
  (**(code **)(*piVar5 + 0x1c))(auStack_4e0);
  FUN_00505f10();
  if (iStack_c == 1) {
    iVar8 = (**(code **)(*piVar6 + 0x30))();
    FUN_00505cc0(iVar8 + 200);
    uStack_480 = *(undefined4 *)(iVar8 + 0x78);
    uStack_47c = *(undefined4 *)(iVar8 + 0x7c);
    uStack_478 = *(undefined4 *)(iVar8 + 0x80);
  }
  else if (iStack_c == 3) {
    iVar8 = (**(code **)(*piVar6 + 0x30))();
    uStack_418 = *(undefined4 *)(iVar8 + 0x70);
    puVar1 = (undefined1 *)(iVar8 + 0x74);
    if (auStack_414 != puVar1) {
      FUN_00504490(local_484,*puStack_410,puStack_410);
      FUN_005040e0(puVar1);
    }
    uStack_480 = *(undefined4 *)(iVar8 + 0x80);
    uStack_47c = *(undefined4 *)(iVar8 + 0x84);
    uStack_478 = *(undefined4 *)(iVar8 + 0x88);
  }
  else {
    iVar8 = (**(code **)(*piVar6 + 0x30))();
    uStack_368 = *(undefined1 *)(iVar8 + 0x7c);
    uStack_367 = *(undefined1 *)(iVar8 + 0x7d);
    if (auStack_364 != (undefined1 *)(iVar8 + 0x80)) {
      FUN_00504490(&uStack_520,*puStack_360,puStack_360);
      FUN_005040e0(iVar8 + 0x80);
    }
    uStack_47c = *(undefined4 *)(iVar8 + 0x8c);
    uStack_478 = *(undefined4 *)(iVar8 + 0x90);
    local_474 = *(undefined4 *)(iVar8 + 0x94);
    local_4ec = (void *)0x1;
    FUN_0056fe50(auStack_4e0 + -0x38);
    (**(code **)(*piVar5 + 8))(auStack_4e0 + -0x38);
  }
  (**(code **)(*piVar5 + 0x24))(&uStack_480);
  (**(code **)(*piVar4 + 0x2c))(piVar5);
  piVar5 = (int *)puVar9[1];
  if ((piVar5 != (int *)0x0) && (cVar3 = (**(code **)(*piVar4 + 0x74))(piVar5), cVar3 != '\0')) {
    cVar3 = (**(code **)(*piVar5 + 0x78))(piVar4);
    if (cVar3 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar8 = (**(code **)(*piVar5 + 0x38))();
      piVar4[1] = iVar8;
    }
  }
  FUN_00505d80();
  if (0xf < uStack_4d8) {
    _free(local_4ec);
    return;
  }
  uStack_4dc = 0;
  uStack_4d8 = 0xf;
  if (local_490[0] < 0x10) {
    return;
  }
  _free(local_4a4);
  return;
}


// ==== FUN_00583480 @ 0x00583480 ====

void FUN_00583480(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puStack_4a4;
  undefined4 *puStack_4a0;
  undefined4 uStack_49c;
  undefined1 auStack_498 [4];
  undefined1 local_494 [4];
  undefined4 uStack_490;
  undefined4 local_48c;
  undefined4 local_488;
  void *apvStack_484 [4];
  undefined4 uStack_474;
  uint uStack_470;
  undefined4 uStack_46c;
  undefined4 uStack_468;
  undefined4 uStack_464;
  undefined1 uStack_358;
  undefined1 uStack_357;
  undefined4 *puStack_350;
  
  piVar3 = (int *)FUN_00558e00(local_494,&param_1);
  iVar1 = *piVar3;
  uVar2 = *(undefined4 *)(iVar1 + 0x10);
  local_48c = *(undefined4 *)(iVar1 + 0x14);
  local_488 = *(undefined4 *)(iVar1 + 0x18);
  uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__class_009be14c);
  FUN_00402220(apvStack_484,uVar4);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(apvStack_484);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
  }
  if (0xf < uStack_470) {
    _free(apvStack_484[0]);
    return;
  }
  uStack_470 = 0xf;
  uStack_474 = 0;
  apvStack_484[0] = (void *)((uint)apvStack_484[0] & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    return;
  }
  FUN_00505f10();
  puStack_4a0 = (undefined4 *)FUN_00503b60();
  *(undefined1 *)((int)puStack_4a0 + 0x1d) = 1;
  puStack_4a0[1] = puStack_4a0;
  *puStack_4a0 = puStack_4a0;
  puStack_4a0[2] = puStack_4a0;
  uStack_49c = 0;
  iVar1 = piVar3[0x1f];
  if (&puStack_4a4 != (undefined4 **)(piVar3 + 0x20)) {
    FUN_00504490(auStack_498,*puStack_4a0,puStack_4a0);
    FUN_005040e0(piVar3 + 0x20);
  }
  uStack_357 = (undefined1)((uint)iVar1 >> 8);
  uStack_358 = (undefined1)iVar1;
  FUN_00504490(auStack_498,*puStack_350,puStack_350);
  FUN_005040e0(&puStack_4a4);
  uStack_468 = uStack_490;
  uStack_464 = local_48c;
  uStack_46c = uVar2;
  (**(code **)(*piVar3 + 0x24))(&uStack_46c);
  FUN_00504490(&uStack_49c,*puStack_4a4,puStack_4a4);
  _free(puStack_4a4);
  return;
}


// ==== FUN_00583640 @ 0x00583640 ====

void FUN_00583640(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = param_1;
  if (param_1 == (int *)0x0) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_i_pBaseComposite____NULL_009be0f8,0x18);
    FUN_00406880(local_38);
    if (local_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_34);
    return;
  }
  iVar3 = (**(code **)(*param_1 + 0x30))();
  uVar4 = (**(code **)(**(int **)(iVar3 + 4) + 0x50))(&PTR_LAB_009be170);
  FUN_00402220(auStack_1c,uVar4);
  uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&PTR_LAB_009be170);
  FUN_00402220(local_38,uVar4);
  FUN_005830e0(local_38,0,auStack_1c,param_1);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar4 = (**(code **)(**(int **)(iVar3 + 4) + 0x50))(s__pcname_009be154);
  FUN_00402220(auStack_1c,uVar4);
  uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__pcname_009be154);
  FUN_00402220(local_38,uVar4);
  FUN_005830e0(local_38,0,auStack_1c,param_1);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar4 = (**(code **)(**(int **)(iVar3 + 4) + 0x50))(&PTR_LAB_009be164);
  FUN_00402220(auStack_1c,uVar4);
  uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&PTR_LAB_009be164);
  FUN_00402220(local_38,uVar4);
  FUN_005830e0(local_38,3,auStack_1c,param_1);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar4 = (**(code **)(**(int **)(iVar3 + 4) + 0x50))(s__class_009be14c);
  FUN_00402220(auStack_1c,uVar4);
  uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__class_009be14c);
  FUN_00402220(local_38,uVar4);
  FUN_005830e0(local_38,0,auStack_1c,param_1);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar4 = (**(code **)(**(int **)(iVar3 + 4) + 0x50))(s__follow_009be168);
  FUN_00402220(auStack_1c,uVar4);
  uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__follow_009be168);
  FUN_00402220(local_38,uVar4);
  FUN_005830e0(local_38,1,auStack_1c,param_1);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  param_1 = (int *)0x8;
  while( true ) {
    local_20 = 0xf;
    local_24 = 0;
    (**(code **)(*piVar2 + 0x30))();
    FUN_00401740(s_pan_status__d_009be174,0xd);
    FUN_00404230(auStack_1c);
    FUN_00401740(s_pan_status__d_009be174,0xd);
    FUN_00404230(local_38);
    FUN_005830e0(local_38,0,auStack_1c,piVar2);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    if (0xf < uStack_4) break;
    param_1 = (int *)((int)param_1 + -1);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    if (param_1 == (int *)0x0) {
      (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
      return;
    }
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_00583a20 @ 0x00583a20 ====

void FUN_00583a20(byte param_1)

{
  void *in_ECX;
  
  FUN_00582a70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00583a60 @ 0x00583a60 ====

void FUN_00583a60(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00583a80 @ 0x00583a80 ====

void FUN_00583a80(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x70);
    local_8 = *(undefined4 *)(in_ECX + 0x74);
    local_4 = *(undefined4 *)(in_ECX + 0x78);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00583b50 @ 0x00583b50 ====

undefined4 FUN_00583b50(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  FUN_00585420(in_ECX + 0xec);
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00583b90 @ 0x00583b90 ====

undefined4 FUN_00583b90(undefined4 param_1)

{
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 == (int *)in_ECX[0x38]) {
    return 0;
  }
  in_ECX[0x1c] = local_4[4];
  in_ECX[0x1d] = local_4[5];
  in_ECX[0x1e] = local_4[6];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return 1;
}


// ==== FUN_00583bf0 @ 0x00583bf0 ====

undefined1 FUN_00583bf0(void)

{
  int in_ECX;
  
  if (((*(char *)(in_ECX + 0xea) == '\0') || (*(char *)(in_ECX + 0xeb) == '\0')) &&
     ((*(char *)(in_ECX + 0xe9) != '\0' || (*(char *)(in_ECX + 0xeb) == '\0')))) {
    return 0;
  }
  FUN_00583b90(0);
  return 1;
}


// ==== FUN_00583c30 @ 0x00583c30 ====

undefined1 FUN_00583c30(void)

{
  int in_ECX;
  
  if (((*(char *)(in_ECX + 0xea) == '\0') || (*(char *)(in_ECX + 0xeb) == '\0')) &&
     ((*(char *)(in_ECX + 0xe9) != '\0' || (*(char *)(in_ECX + 0xeb) == '\0')))) {
    return 0;
  }
  FUN_00583b90(1);
  return 1;
}


// ==== FUN_00583c70 @ 0x00583c70 ====

undefined4 FUN_00583c70(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00583d00 @ 0x00583d00 ====

undefined4 FUN_00583d00(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int *piVar3;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  switch(param_2) {
  case 0:
    FUN_00403810(s__hp_processbar_009be2a0);
    break;
  case 1:
    FUN_00403810(s__level_panel_009be2b0);
    break;
  case 2:
    FUN_00403810(s__mapname_panel_009be2c0);
    break;
  case 3:
    FUN_00403810(s__pcname_panel_009be2d0);
    break;
  case 4:
    FUN_00403810(s__classtype_panel_009be2e0);
    break;
  case 5:
    FUN_00403810(s__forceleave_btn_009be2f4);
    break;
  default:
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_FALSE_009be30c,5);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    _free(local_18);
    return extraout_EAX;
  case 8:
    FUN_00403810(s__hp_bg_009be304);
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar3 + 0x50))(local_38);
  FUN_00405bd0(param_1,uVar2);
  if (local_20 < 0x10) {
    return param_1;
  }
  _free(local_34);
  return extraout_EAX_00;
}


// ==== FUN_00583f80 @ 0x00583f80 ====

undefined4 FUN_00583f80(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 extraout_EAX;
  int iVar10;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 ***pppuVar11;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  int *in_ECX;
  undefined1 local_c4 [4];
  void *local_c0;
  undefined4 local_b0;
  uint local_ac;
  undefined1 auStack_a8 [4];
  undefined4 ***apppuStack_a4 [4];
  undefined4 uStack_94;
  uint uStack_90;
  undefined1 auStack_8c [4];
  undefined4 ***apppuStack_88 [4];
  undefined4 uStack_78;
  uint uStack_74;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  undefined4 ***apppuStack_50 [4];
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  local_ac = 0xf;
  local_b0 = 0;
  local_c0 = (void *)((uint)local_c0 & 0xffffff00);
  FUN_00403810(s__mapname_panel_009be2c0);
  piVar8 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar9 = (**(code **)(*piVar8 + 0x50))(local_c4);
  FUN_00405bd0(auStack_54,uVar9);
  if (0xf < local_ac) {
    _free(local_c0);
    return extraout_EAX;
  }
  local_ac = 0xf;
  local_b0 = 0;
  local_c0 = (void *)((uint)local_c0 & 0xffffff00);
  pppuVar11 = apppuStack_50[0];
  if (uStack_3c < 0x10) {
    pppuVar11 = apppuStack_50;
  }
  iVar10 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppuVar11,uStack_40);
  if (iVar10 != 0) {
    bVar6 = true;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_ac = 0xf;
    local_b0 = 0;
    local_c0 = (void *)((uint)local_c0 & 0xffffff00);
    FUN_00403810(s__pcname_panel_009be2d0);
    piVar8 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar9 = (**(code **)(*piVar8 + 0x50))(local_c4);
    FUN_00405bd0(auStack_a8,uVar9);
    if (0xf < local_ac) {
      _free(local_c0);
      return extraout_EAX_00;
    }
    local_ac = 0xf;
    local_b0 = 0;
    local_c0 = (void *)((uint)local_c0 & 0xffffff00);
    pppuVar11 = apppuStack_a4[0];
    if (uStack_90 < 0x10) {
      pppuVar11 = apppuStack_a4;
    }
    iVar10 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppuVar11,uStack_94);
    if (iVar10 != 0) {
      bVar6 = true;
      bVar5 = true;
      bVar4 = false;
      bVar3 = false;
      bVar2 = false;
      local_ac = 0xf;
      local_b0 = 0;
      local_c0 = (void *)((uint)local_c0 & 0xffffff00);
      FUN_00403810(s__hp_bg_009be304);
      piVar8 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar9 = (**(code **)(*piVar8 + 0x50))(local_c4);
      FUN_00405bd0(auStack_8c,uVar9);
      if (0xf < local_ac) {
        _free(local_c0);
        return extraout_EAX_01;
      }
      local_ac = 0xf;
      local_b0 = 0;
      local_c0 = (void *)((uint)local_c0 & 0xffffff00);
      pppuVar11 = apppuStack_88[0];
      if (uStack_74 < 0x10) {
        pppuVar11 = apppuStack_88;
      }
      iVar10 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppuVar11,uStack_78);
      if (iVar10 != 0) {
        bVar6 = true;
        bVar5 = true;
        bVar4 = true;
        bVar3 = false;
        bVar2 = false;
        local_ac = 0xf;
        local_b0 = 0;
        local_c0 = (void *)((uint)local_c0 & 0xffffff00);
        FUN_00403810(s__classtype_panel_009be2e0);
        piVar8 = (int *)(**(code **)(*in_ECX + 0x3c))();
        uVar9 = (**(code **)(*piVar8 + 0x50))(local_c4);
        FUN_00405bd0(auStack_70,uVar9);
        if (0xf < local_ac) {
          _free(local_c0);
          return extraout_EAX_02;
        }
        local_ac = 0xf;
        local_b0 = 0;
        local_c0 = (void *)((uint)local_c0 & 0xffffff00);
        cVar7 = FUN_00423420(param_2,auStack_70);
        if (cVar7 == '\0') {
          bVar6 = true;
          bVar5 = true;
          bVar4 = true;
          bVar3 = true;
          bVar2 = false;
          uVar9 = FUN_00583d00(auStack_1c,0);
          cVar7 = FUN_00423420(param_2,uVar9);
          if (cVar7 == '\0') {
            bVar6 = true;
            bVar5 = true;
            bVar4 = true;
            bVar3 = true;
            bVar2 = true;
            local_ac = 0xf;
            local_b0 = 0;
            local_c0 = (void *)((uint)local_c0 & 0xffffff00);
            FUN_00403810(s__forceleave_btn_009be2f4);
            piVar8 = (int *)(**(code **)(*in_ECX + 0x3c))();
            uVar9 = (**(code **)(*piVar8 + 0x50))(local_c4);
            FUN_00405bd0(auStack_38,uVar9);
            if (0xf < local_ac) {
              _free(local_c0);
              return extraout_EAX_03;
            }
            local_ac = 0xf;
            local_b0 = 0;
            local_c0 = (void *)((uint)local_c0 & 0xffffff00);
            cVar7 = FUN_00423420(param_2,auStack_38);
            bVar1 = false;
            if (cVar7 == '\0') goto LAB_00584273;
          }
        }
      }
    }
  }
  bVar1 = true;
LAB_00584273:
  if (bVar2) {
    if (0xf < uStack_20) {
      _free(pvStack_34);
      return extraout_EAX_04;
    }
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  }
  if (bVar3) {
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_05;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  }
  if (bVar4) {
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return extraout_EAX_06;
    }
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  }
  if (bVar5) {
    if (0xf < uStack_74) {
      _free(apppuStack_88[0]);
      return extraout_EAX_07;
    }
    uStack_74 = 0xf;
    uStack_78 = 0;
    apppuStack_88[0] = (undefined4 ***)((uint)apppuStack_88[0] & 0xffffff00);
  }
  if (bVar6) {
    if (0xf < uStack_90) {
      _free(apppuStack_a4[0]);
      return extraout_EAX_08;
    }
    uStack_90 = 0xf;
    uStack_94 = 0;
    apppuStack_a4[0] = (undefined4 ***)((uint)apppuStack_a4[0] & 0xffffff00);
  }
  if (0xf < uStack_3c) {
    _free(apppuStack_50[0]);
    return extraout_EAX_09;
  }
  if (bVar1) {
    if ((param_1 == 0) || (param_1 == 3)) {
      if (param_3 == 1) {
        if (*(char *)((int)in_ECX + 0xe9) == '\0') {
          (**(code **)(*(int *)in_ECX[1] + 0x80))(1,7);
        }
        return 1;
      }
      if (param_3 == 4) {
        if (*(char *)((int)in_ECX + 0xe9) == '\0') {
          FUN_00583b90(1);
        }
        return 1;
      }
      if (param_3 == 5) {
        if (*(char *)((int)in_ECX + 0xe9) == '\0') {
          FUN_00583b90(0);
        }
        return 1;
      }
    }
    else if ((param_1 == 1) && (param_3 == 1)) {
      (**(code **)(*(int *)in_ECX[1] + 0x80))(1,5);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00584480 @ 0x00584480 ====

undefined4 FUN_00584480(undefined1 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int iVar4;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  undefined4 ****ppppuVar5;
  undefined4 uStack_40;
  undefined4 local_3c;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  undefined4 ****appppuStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  local_3c = 7;
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x48))(&param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00403810(s__forceleave_btn_009be2f4);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar3 = (**(code **)(*piVar2 + 0x50))(&local_3c);
  FUN_00405bd0(auStack_20,uVar3);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  iVar4 = (**(code **)(*piVar1 + 0x50))();
  ppppuVar5 = appppuStack_1c[0];
  if (uStack_8 < 0x10) {
    ppppuVar5 = appppuStack_1c;
  }
  iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),ppppuVar5,uStack_c);
  if (0xf < uStack_8) {
    _free(appppuStack_1c[0]);
    return extraout_EAX_00;
  }
  uVar3 = 5;
  if (iVar4 != 0) {
    uVar3 = uStack_40;
  }
  (**(code **)(*(int *)in_ECX[1] + 0x80))(1,uVar3);
  return 1;
}


// ==== FUN_00584590 @ 0x00584590 ====

void FUN_00584590(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_10 = param_1;
  local_c = param_2;
  FUN_005856f0(local_8,&local_10);
  return;
}


// ==== FUN_005845c0 @ 0x005845c0 ====

void FUN_005845c0(char param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  uint unaff_EBX;
  undefined4 in_stack_ffffff78;
  undefined1 in_stack_ffffff7c;
  undefined1 uVar4;
  undefined1 in_stack_ffffff80;
  undefined4 in_stack_ffffff84;
  undefined4 in_stack_ffffff88;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_54;
  void *pvStack_50;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_40;
  void *pvStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *pvStack_20;
  void *local_1c;
  void *local_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  uint local_4;
  
  if (param_1 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401660(in_ECX + 0x23,0,0xffffffff);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    pvStack_3c = (void *)0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    FUN_00403810(s__pcname_panel_009be2d0);
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar3 = (**(code **)(*piVar2 + 0x50))(&uStack_54);
    uVar5 = 0x584653;
    FUN_00405bd0(&pvStack_38,uVar3);
    if ((void *)0xf < pvStack_3c) {
      _free(pvStack_50);
      return;
    }
    pvStack_3c = (void *)0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&pvStack_38);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      uVar3 = 0xffffffff;
      if ((char)in_ECX[0x3a] == '\0') {
        if ((char)in_ECX[0x32] == '\0') {
          uVar3 = 0xff909090;
        }
      }
      else {
        uVar3 = 0xffffff00;
      }
      uVar7 = 0xf;
      uVar6 = 0;
      in_stack_ffffff80 = 0;
      FUN_00401660(&pvStack_20,0,0xffffffff);
      in_stack_ffffff78 = 0x5846ff;
      FUN_00588340(in_stack_ffffff7c,in_stack_ffffff80,in_stack_ffffff84,in_stack_ffffff88,uVar5,
                   uVar6,uVar7);
      FUN_00587d70(uVar3);
    }
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    FUN_00401740(s____s___009be298,6);
    FUN_00404230(&pvStack_3c);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uStack_40 = 0xf;
    uStack_44 = 0;
    uStack_54 = (void *)((uint)uStack_54 & 0xffffff00);
    FUN_00403810(s__mapname_panel_009be2c0);
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar3 = (**(code **)(*piVar2 + 0x50))((int)register0x00000010 + -0x58);
    uVar5 = 0x58479f;
    FUN_00405bd0(&pvStack_20,uVar3);
    if (0xf < uStack_40) {
      _free(uStack_54);
      return;
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    uStack_54 = (void *)((uint)uStack_54 & 0xffffff00);
    piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&pvStack_20);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      local_4 = 0xffffffff;
      if ((char)in_ECX[0x32] == '\0') {
        local_4 = 0xff909090;
      }
      uVar6 = 0xf;
      uVar3 = 0;
      uVar4 = 0;
      FUN_00401660(&uStack_40,0,0xffffffff);
      FUN_00588340(in_stack_ffffff78,uVar4,in_stack_ffffff80,in_stack_ffffff84,uVar5,uVar3,uVar6);
      FUN_00587d70(local_4);
    }
    if (0xf < uStack_28) {
      _free(pvStack_3c);
      return;
    }
    uStack_28 = 0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    FUN_00401740(&DAT_009be29f,0);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uStack_44 = 0xf;
    uStack_48 = 0;
    FUN_00403810(s__hp_processbar_009be2a0);
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar3 = (**(code **)(*piVar2 + 0x50))((int)register0x00000010 + -0x5c);
    FUN_00405bd0(&uStack_24,uVar3);
    if (0xf < uStack_44) {
      _free((void *)(unaff_EBX & 0xffffff00));
      return;
    }
    uStack_44 = 0xf;
    uStack_48 = 0;
    piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&uStack_24);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      FUN_00587ba0((float)in_ECX[0x31] * DAT_0099de78);
    }
    if ((void *)0xf < pvStack_20) {
      _free(pvStack_34);
      return;
    }
    if (*(char *)((int)in_ECX + 0xe9) != '\0') {
      FUN_00583b90(4);
      return;
    }
  }
  else if (*(char *)((int)in_ECX + 0xeb) == '\0') {
    FUN_00583b90(2);
    return;
  }
  FUN_00583b90(0);
  return;
}


// ==== FUN_00584970 @ 0x00584970 ====

undefined4 FUN_00584970(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  iVar3 = param_1[2];
  if (iVar3 == 1) {
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    iVar4 = (**(code **)(*param_1 + 0x10))();
    if (iVar3 == iVar4) {
      uVar5 = (**(code **)(*param_1 + 0x10))();
      cVar2 = FUN_00584480(uVar5);
      if (cVar2 != '\0') {
        return 1;
      }
    }
  }
  else if (iVar3 == 7) {
    piVar1 = *(int **)(in_ECX + 4);
    iVar3 = (**(code **)(*param_1 + 0x10))();
    iVar4 = (**(code **)(*piVar1 + 4))();
    if (iVar4 == iVar3) {
      uVar5 = (**(code **)(*param_1 + 0x10))();
      cVar2 = FUN_00583c30(uVar5);
      if (cVar2 != '\0') {
        return 1;
      }
    }
  }
  else if (iVar3 == 8) {
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    iVar4 = (**(code **)(*param_1 + 0x10))();
    if (iVar3 == iVar4) {
      uVar5 = (**(code **)(*param_1 + 0x10))();
      cVar2 = FUN_00583bf0(uVar5);
      if (cVar2 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00584a30 @ 0x00584a30 ====

void FUN_00584a30(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009be324;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    FUN_00585420(in_ECX + 0x3b);
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00585920(local_4,*(undefined4 *)in_ECX[0x3c],(undefined4 *)in_ECX[0x3c]);
  _free((void *)in_ECX[0x3c]);
  return;
}


// ==== FUN_00584ab0 @ 0x00584ab0 ====

void FUN_00584ab0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = param_1;
  if (param_1 != 0) {
    FUN_00585a50(param_1 + 0x124);
    if (in_ECX + 0x37 != (int *)(iVar2 + 0x184)) {
      FUN_00504490(&param_1,*(undefined4 *)in_ECX[0x38],(undefined4 *)in_ECX[0x38]);
      FUN_005040e0((int *)(iVar2 + 0x184));
    }
    param_1 = 0;
    FUN_00558e00(&local_20,&param_1);
    if (local_20 == in_ECX[0x38]) {
      in_ECX[0x1c] = 0;
    }
    else {
      in_ECX[0x1c] = *(int *)(local_20 + 0x10);
      in_ECX[0x1d] = *(int *)(local_20 + 0x14);
      in_ECX[0x1e] = *(int *)(local_20 + 0x18);
    }
    FUN_005845c0(*(undefined1 *)((int)in_ECX + 0xea));
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pProperty_009be28c,0xb);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00584ba0 @ 0x00584ba0 ====

undefined4 FUN_00584ba0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00584970(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00584bd0 @ 0x00584bd0 ====

void FUN_00584bd0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009be324;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x29] = 0xf;
  in_ECX[0x28] = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  in_ECX[0x30] = 0xf;
  in_ECX[0x2f] = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x38] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x38] + 4) = in_ECX[0x38];
  *(undefined4 *)in_ECX[0x38] = in_ECX[0x38];
  *(undefined4 *)(in_ECX[0x38] + 8) = in_ECX[0x38];
  in_ECX[0x39] = 0;
  iVar1 = FUN_00585340();
  in_ECX[0x3c] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x3c] + 4) = in_ECX[0x3c];
  *(undefined4 *)in_ECX[0x3c] = in_ECX[0x3c];
  *(undefined4 *)(in_ECX[0x3c] + 8) = in_ECX[0x3c];
  in_ECX[0x3d] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00584c90 @ 0x00584c90 ====

void FUN_00584c90(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  puVar3 = param_3;
  if (param_2 == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_i_pBaseCtrl_009be240,0xb);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  if (param_1 == 0) {
    puVar1 = param_3 + 0x45;
    FUN_00503950(*(undefined4 *)(param_3[0x47] + 4));
    *(undefined4 *)(puVar3[0x47] + 4) = puVar3[0x47];
    puVar3[0x48] = 0;
    *(undefined4 *)puVar3[0x47] = puVar3[0x47];
    *(undefined4 *)(puVar3[0x47] + 8) = puVar3[0x47];
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar3 + 0x115) = 0;
    FUN_0056f420(puVar1);
    *puVar3 = *(undefined4 *)(param_2 + 0x8c);
    puVar3[1] = *(undefined4 *)(param_2 + 0x90);
    puVar3[2] = *(undefined4 *)(param_2 + 0x94);
    return;
  }
  if (param_1 == 1) {
    *(undefined1 *)(param_3 + 0x41) = 0;
    *(undefined1 *)((int)param_3 + 0x105) = 0;
    *(undefined1 *)((int)param_3 + 0x107) = 0;
    *(undefined1 *)(param_3 + 0x43) = 0;
    param_3[0x42] = 0xc;
    param_3[0x44] = 500;
    *(undefined1 *)((int)param_3 + 0x106) = 0;
    FUN_00505cc0(param_2 + 200);
    *puVar3 = *(undefined4 *)(param_2 + 0x78);
    puVar3[1] = *(undefined4 *)(param_2 + 0x7c);
    puVar3[2] = *(undefined4 *)(param_2 + 0x80);
    return;
  }
  if (param_1 == 3) {
    param_3[0x1a] = 100;
    param_3[0x1a] = *(undefined4 *)(param_2 + 0x70);
    if (param_3 + 0x1b != (undefined4 *)(param_2 + 0x74)) {
      FUN_00504490(&param_3,*(undefined4 *)param_3[0x1c],(undefined4 *)param_3[0x1c]);
      FUN_005040e0((undefined4 *)(param_2 + 0x74));
    }
    *puVar3 = *(undefined4 *)(param_2 + 0x80);
    puVar3[1] = *(undefined4 *)(param_2 + 0x84);
    puVar3[2] = *(undefined4 *)(param_2 + 0x88);
    return;
  }
  FUN_00401830(s_FALSE_009be24c);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00584e60 @ 0x00584e60 ====

void FUN_00584e60(int *param_1,int param_2,char *param_3)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcStack_53c;
  void *apvStack_520 [2];
  void *local_518;
  undefined4 uStack_510;
  uint uStack_50c;
  undefined4 local_508;
  uint local_504;
  undefined1 local_4fc;
  undefined4 local_4ec;
  undefined4 local_4e8;
  undefined4 local_4e4;
  void *local_4e0;
  void *local_4dc;
  undefined4 uStack_4d0;
  uint uStack_4cc;
  uint uStack_4c8;
  undefined4 uStack_4c4;
  undefined4 uStack_4c0;
  undefined1 uStack_4bc;
  undefined1 uStack_4bb;
  undefined1 auStack_4ac [10];
  undefined1 local_4a2;
  undefined4 local_4a0;
  void *local_49c;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 local_490;
  undefined4 local_48c;
  uint local_488;
  undefined1 local_480;
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 local_470;
  undefined4 local_46c;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    pcStack_53c = s_i_pBaseCtrl____i_pPCInfo_009be254;
    local_504 = 0xf;
    local_508 = 0;
    local_518 = (void *)((uint)local_518 & 0xffffff00);
    FUN_00401740();
    pcStack_53c = (char *)0x584eae;
    FUN_00406880();
    if (local_504 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pcStack_53c = (char *)0x584ec2;
    _free(local_518);
    return;
  }
  local_4a2 = 1;
  local_4a0 = 0;
  local_49c = (void *)0x0;
  local_498 = 0;
  local_494 = 0;
  local_490 = 0;
  local_48c = 0;
  local_488 = 0;
  local_46c = 0xf;
  local_470 = 0;
  local_480 = 0;
  local_4e8 = 0xf;
  local_4ec = 0;
  local_4fc = 0;
  local_4e4 = 0;
  local_4e0 = (void *)0x0;
  local_4dc = (void *)0x0;
  pcStack_53c = (char *)0x584f3f;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  pcStack_53c = param_3;
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  piVar5 = (int *)(**(code **)(*param_1 + 0x3c))();
  iVar8 = *piVar5;
  iVar6 = FUN_00583d00(apvStack_520,param_3);
  piVar5 = (int *)(**(code **)(iVar8 + 0x4c))();
  if (0xf < uStack_50c) {
    _free(apvStack_520[0]);
    return;
  }
  uStack_50c = 0xf;
  uStack_510 = 0;
  apvStack_520[0] = (void *)((uint)apvStack_520[0] & 0xffffff00);
  uVar7 = (**(code **)(*piVar5 + 0x10))();
  FUN_004fed70(uVar7);
  uVar7 = FUN_00583d00(&local_4e0,param_2);
  FUN_00401660(uVar7,0,0xffffffff);
  if (0xf < uStack_4c8) {
    _free(local_4dc);
    return;
  }
  FUN_00401660(&local_48c,0,0xffffffff);
  (**(code **)(*piVar3 + 8))(auStack_4ac);
  (**(code **)(*piVar4 + 0x38))(piVar3);
  (**(code **)(*piVar4 + 0x1c))(&uStack_510);
  FUN_00505f10();
  puVar9 = &uStack_47c;
  uVar7 = (**(code **)(*piVar5 + 0x30))(puVar9);
  FUN_00584c90(iStack_8,uVar7,puVar9);
  if (iStack_8 == 0) {
    (**(code **)(*piVar5 + 0x30))();
    uStack_4c8 = 1;
    uStack_4c0 = 1;
    local_4ec = 0;
    local_4e8 = 0;
    uStack_4cc = 0xf;
    uStack_4d0 = 0;
    local_4e0 = (void *)((uint)local_4e0 & 0xffffff00);
    uStack_4c4 = 0;
    uStack_4bc = 0;
    uStack_4bb = 0;
    FUN_0056fe50(&local_4ec);
    (**(code **)(*piVar4 + 8))(&local_4ec);
    if (0xf < uStack_4cc) {
      _free(local_4e0);
      return;
    }
    if (iStack_4 == 4) {
      pcStack_53c = *(char **)(iStack_c + 0xc);
      piVar5 = (int *)FUN_005859e0(&pcStack_53c);
      puVar9 = (undefined4 *)*piVar5;
      uStack_47c = *puVar9;
      uStack_478 = puVar9[1];
      uStack_474 = puVar9[2];
    }
  }
  (**(code **)(*piVar4 + 0x24))(&uStack_47c);
  (**(code **)(*piVar3 + 0x2c))(piVar4);
  piVar4 = *(int **)(iVar6 + 4);
  if ((piVar4 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 0x74))(piVar4), cVar2 != '\0')) {
    cVar2 = (**(code **)(*piVar4 + 0x78))(piVar3);
    if (cVar2 == '\0') {
      (**(code **)(*piVar3 + 0x74))(0);
    }
    else {
      iVar8 = (**(code **)(*piVar4 + 0x38))();
      piVar3[1] = iVar8;
    }
  }
  FUN_00505d80();
  if (0xf < local_504) {
    _free(local_518);
    return;
  }
  local_508 = 0;
  local_518 = (void *)((uint)local_518 & 0xffffff00);
  local_504 = 0xf;
  if (local_488 < 0x10) {
    return;
  }
  _free(local_49c);
  return;
}


// ==== FUN_005851f0 @ 0x005851f0 ====

void FUN_005851f0(int param_1,int param_2)

{
  code *pcVar1;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_00584e60(param_1,param_2,0,4);
    FUN_00584e60(param_1,param_2,0,3);
    FUN_00584e60(param_1,param_2,0,2);
    FUN_00584e60(param_1,param_2,1,5);
    FUN_00584e60(param_1,param_2,0,8);
    FUN_00584e60(param_1,param_2,3,0);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pBaseCtrl____i_pPCInfo_009be270,0x18);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005852b0 @ 0x005852b0 ====

void * FUN_005852b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982190;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x18);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00535310(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00585325 @ 0x00585325 ====

void Catch_00585325(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00585340 @ 0x00585340 ====

void FUN_00585340(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009821a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 5) = 1;
  *(undefined1 *)((int)puVar1 + 0x15) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@005853ca @ 0x005853ca ====

void Catch_005853ca(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005853e0 @ 0x005853e0 ====

void FUN_005853e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_005853e0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00585420 @ 0x00585420 ====

void FUN_00585420(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    puVar1 = (undefined4 *)(param_1 + 4);
    param_1 = param_1 & 0xffffff00;
    FUN_004c3cc0(*(undefined4 *)*puVar1,(undefined4 *)*puVar1,param_1);
    FUN_005853e0(*(undefined4 *)(*(int *)(uVar2 + 4) + 4));
    *(int *)(*(int *)(uVar2 + 4) + 4) = *(int *)(uVar2 + 4);
    *(undefined4 *)(uVar2 + 8) = 0;
    *(undefined4 *)*(undefined4 *)(uVar2 + 4) = *(undefined4 *)(uVar2 + 4);
    *(int *)(*(int *)(uVar2 + 4) + 8) = *(int *)(uVar2 + 4);
  }
  return;
}


// ==== FUN_00585470 @ 0x00585470 ====

void FUN_00585470(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0x1ffffffd < *(uint *)(in_ECX + 8)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c48c);
  }
  piVar4 = (int *)FUN_005852b0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[5] == '\0') {
LAB_00585575:
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
      if ((char)piVar6[5] == '\0') goto LAB_00585575;
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


// ==== FUN_00585650 @ 0x00585650 ====

void FUN_00585650(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  FUN_00401660(param_1 + 4,0,0xffffffff);
  FUN_00401660(param_1 + 0xb,0,0xffffffff);
  in_ECX[0x12] = param_1[0x12];
  *(undefined1 *)(in_ECX + 0x13) = *(undefined1 *)(param_1 + 0x13);
  in_ECX[0x14] = param_1[0x14];
  in_ECX[0x15] = param_1[0x15];
  *(undefined1 *)(in_ECX + 0x16) = *(undefined1 *)(param_1 + 0x16);
  *(undefined1 *)((int)in_ECX + 0x59) = *(undefined1 *)((int)param_1 + 0x59);
  *(undefined1 *)((int)in_ECX + 0x5a) = *(undefined1 *)((int)param_1 + 0x5a);
  *(undefined1 *)((int)in_ECX + 0x5b) = *(undefined1 *)((int)param_1 + 0x5b);
  *(undefined1 *)(in_ECX + 0x17) = *(undefined1 *)(param_1 + 0x17);
  *(undefined1 *)((int)in_ECX + 0x5d) = *(undefined1 *)((int)param_1 + 0x5d);
  *(undefined1 *)((int)in_ECX + 0x5e) = *(undefined1 *)((int)param_1 + 0x5e);
  *(undefined1 *)((int)in_ECX + 0x5f) = *(undefined1 *)((int)param_1 + 0x5f);
  return;
}


// ==== FUN_005856f0 @ 0x005856f0 ====

void FUN_005856f0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00585470(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00585470(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005857b0 @ 0x005857b0 ====

undefined4 * FUN_005857b0(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00585470(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_00585470(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_00585470(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_0058d720();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x15) == '\0') {
          FUN_00585470(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00585470(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_00458720();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x15) == '\0') {
          FUN_00585470(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00585470(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_005856f0(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_00585920 @ 0x00585920 ====

void FUN_00585920(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005853e0(piVar6[1]);
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
    FUN_0051a2a0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_005859e0 @ 0x005859e0 ====

undefined4 * FUN_005859e0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint local_8 [2];
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar4[3])) {
    local_8[0] = *param_1;
    local_8[1] = 0;
    piVar3 = (int *)FUN_005857b0(&param_1,puVar4,local_8);
    return (undefined4 *)(*piVar3 + 0x10);
  }
  return puVar4 + 4;
}


// ==== FUN_00585a50 @ 0x00585a50 ====

void FUN_00585a50(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  FUN_00585650(param_1);
  if (in_ECX + 0x60 != iVar1 + 0x60) {
    FUN_00504490(&param_1,**(undefined4 **)(in_ECX + 100),*(undefined4 **)(in_ECX + 100));
    FUN_005040e0(iVar1 + 0x60);
  }
  *(undefined1 *)(in_ECX + 0x6c) = *(undefined1 *)(iVar1 + 0x6c);
  *(undefined1 *)(in_ECX + 0x6d) = *(undefined1 *)(iVar1 + 0x6d);
  *(undefined1 *)(in_ECX + 0x6e) = *(undefined1 *)(iVar1 + 0x6e);
  *(undefined1 *)(in_ECX + 0x6f) = *(undefined1 *)(iVar1 + 0x6f);
  return;
}


// ==== FUN_00585ab0 @ 0x00585ab0 ====

void FUN_00585ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_00584a30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00585ae0 @ 0x00585ae0 ====

void FUN_00585ae0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00585b00 @ 0x00585b00 ====

undefined4 FUN_00585b00(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00585b30 @ 0x00585b30 ====

uint FUN_00585b30(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  uVar2 = (**(code **)(*param_1 + 0x10))();
  if (uVar2 == uVar1) {
    uVar2 = param_1[2] - 1;
    switch(uVar2) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_00585b90 @ 0x00585b90 ====

uint FUN_00585b90(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  uVar2 = (**(code **)(*param_1 + 0x10))();
  if (((uVar2 != uVar1) || (uVar2 = 1, param_1[2] != 1)) || (param_1[6] != 1)) {
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}


// ==== FUN_00585bd0 @ 0x00585bd0 ====

void FUN_00585bd0(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0xcc);
    local_8 = *(undefined4 *)(in_ECX + 0xd0);
    local_4 = *(undefined4 *)(in_ECX + 0xd4);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00585cf0 @ 0x00585cf0 ====

undefined4 FUN_00585cf0(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  if ((char)in_ECX[0x11] != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  in_ECX[0x10] = (int)piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = *(int *)in_ECX[0x10];
      uVar4 = (**(code **)(*(int *)in_ECX[1] + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x11) = 1;
        (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(in_ECX[0x10]);
    in_ECX[0x10] = 0;
  }
  return 0;
}


// ==== FUN_00585db0 @ 0x00585db0 ====

void FUN_00585db0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined3 *puVar7;
  int *in_ECX;
  char *pcVar8;
  int iVar9;
  undefined1 local_74 [4];
  void *local_70;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_58 [4];
  void *local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_5c = 0xf;
  iVar9 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  uStack_3c._0_3_ = CONCAT12(1,(undefined2)uStack_3c);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  if (iVar9 != iVar2) {
    do {
      FUN_00401740(s__x_quest_009be40c,8);
      iVar4 = FUN_00404230(local_58);
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pcVar8 = (char *)(iVar4 + 4);
      }
      else {
        pcVar8 = *(char **)(iVar4 + 4);
      }
      pcVar5 = pcVar8;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar8,(int)pcVar5 - (int)(pcVar8 + 1));
      if (0xf < local_40) {
        _free(local_54);
        return;
      }
      local_40 = 0xf;
      local_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      piVar6 = (int *)(**(code **)(*in_ECX + 0x3c))();
      piVar6 = (int *)(**(code **)(*piVar6 + 0x4c))(local_74);
      puVar7 = (undefined3 *)(**(code **)(*piVar6 + 0x10))();
      local_40 = CONCAT13(local_40._3_1_,*puVar7);
      uStack_3c = *(undefined4 *)(puVar7 + 1);
      local_38 = *(undefined4 *)(puVar7 + 2);
      local_34 = *(int *)(puVar7 + 3);
      local_30 = *(undefined4 *)(puVar7 + 4);
      local_2c = *(int *)(puVar7 + 5);
      local_28 = *(undefined4 *)(puVar7 + 6);
      local_24 = *(undefined4 *)(puVar7 + 7);
      FUN_00401660(puVar7 + 8,0,0xffffffff);
      uVar3 = local_40 >> 8;
      local_40 = local_40 & 0xffffff00;
      if ((char)param_1 != '\0') {
        if ((param_2 <= in_ECX[0x1d]) && (iVar4 = in_ECX[0x1c], iVar4 < in_ECX[0x1e])) {
          local_34 = in_ECX[0x30] * iVar4 + in_ECX[0x21];
          local_2c = in_ECX[0x30] + -2 + local_34;
          local_40 = CONCAT31((int3)uVar3,1);
          in_ECX[0x1c] = iVar4 + 1;
        }
        in_ECX[0x1d] = in_ECX[0x1d] + 1;
      }
      (**(code **)(*piVar6 + 0xc))(&local_40);
      iVar9 = iVar9 + 0x20;
    } while (iVar9 != iVar2);
    if (0xf < local_5c) {
      _free(local_70);
      return;
    }
  }
  local_5c = 0xf;
  local_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00585fc0 @ 0x00585fc0 ====

void FUN_00585fc0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined4 ***pppuVar6;
  int *piVar7;
  undefined1 auStack_1c [4];
  undefined4 ***apppuStack_18 [4];
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x58))();
  piVar7 = *(int **)(iVar2 + 4);
  if ((piVar7 == (int *)0x0) || (*(int *)(iVar2 + 8) - (int)piVar7 >> 2 != 1)) {
    if (piVar7 != *(int **)(iVar2 + 8)) {
      do {
        piVar1 = (int *)*piVar7;
        if (piVar1 == (int *)0x0) {
LAB_0058609d:
          piVar7 = piVar7 + 1;
        }
        else {
          uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009be3f0);
          FUN_00402220(auStack_1c,uVar3);
          iVar4 = (**(code **)(*piVar1 + 0x50))();
          pppuVar6 = apppuStack_18[0];
          if (uStack_4 < 0x10) {
            pppuVar6 = apppuStack_18;
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),pppuVar6,uStack_8);
          if (0xf < uStack_4) {
            _free(apppuStack_18[0]);
            return;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          apppuStack_18[0] = (undefined4 ***)((uint)apppuStack_18[0] & 0xffffff00);
          if (iVar4 == 0) goto LAB_0058609d;
          iVar4 = (**(code **)(*piVar1 + 0x3c))();
          if (iVar4 != 0) {
            piVar5 = (int *)(**(code **)(*piVar1 + 0x3c))();
            (**(code **)(*piVar5 + 0x7c))(piVar1);
          }
        }
      } while (piVar7 != *(int **)(iVar2 + 8));
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    if (*(void **)(in_ECX + 0x90) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x90));
      return;
    }
    *(undefined4 *)(in_ECX + 0x90) = 0;
    *(undefined4 *)(in_ECX + 0x94) = 0;
    *(undefined4 *)(in_ECX + 0x98) = 0;
  }
  return;
}


// ==== FUN_005860f0 @ 0x005860f0 ====

void FUN_005860f0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *apvStack_1c [5];
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009be3f0);
  FUN_00402220(apvStack_1c,uVar2);
  iVar3 = (**(code **)(*piVar1 + 0x4c))(apvStack_1c);
  in_ECX[0x28] = iVar3;
  if (uStack_8 < 0x10) {
    return;
  }
  _free(apvStack_1c[0]);
  return;
}


// ==== FUN_00586150 @ 0x00586150 ====

undefined4 FUN_00586150(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar1 = param_1;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar3 = (**(code **)(*piVar2 + 4))();
  if (iVar4 != iVar3) {
    param_1 = iVar4;
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar4 = (**(code **)(*piVar2 + 0x48))(&param_1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  if (in_ECX[1] != 0) {
    uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009be3f0);
    FUN_00402220(apvStack_1c,uVar5);
    piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x4c))(apvStack_1c);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return extraout_EAX;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar2 + 0x30))();
      iVar4 = FUN_00803725(uVar5,0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                           &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
      if (iVar4 != 0) {
        if (0 < *(short *)(iVar1 + 4)) {
          FUN_0055aa00();
          return 1;
        }
        if (*(short *)(iVar1 + 4) < 0) {
          FUN_0055aa60();
        }
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00586250 @ 0x00586250 ====

void FUN_00586250(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined3 *puVar6;
  char *pcVar7;
  int *in_ECX;
  char *pcVar8;
  int *piVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  int iStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  int iStack_e4;
  undefined4 uStack_e0;
  int iStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  void *pvStack_c8;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  int aiStack_74 [2];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  iVar2 = (**(code **)(*(int *)in_ECX[0x28] + 0x30))();
  iStack_f0 = *(int *)(iVar2 + 0x88);
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  uStack_58 = 0xf;
  uStack_5c = 0;
  pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  uStack_ec._0_3_ = CONCAT12(1,(undefined2)uStack_ec);
  uStack_e8 = 0;
  iStack_e4 = 0;
  uStack_e0 = 0;
  iStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  uStack_b0._0_3_ = CONCAT12(1,(undefined2)uStack_b0);
  uStack_ac = 0;
  iStack_a8 = 0;
  uStack_a4 = 0;
  iStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  iVar2 = *(int *)(in_ECX[0x27] + 4);
  aiStack_74[0] = *(int *)(in_ECX[0x27] + 8);
  piVar9 = (int *)0x0;
  if (iVar2 != aiStack_74[0]) {
    do {
      FUN_00401740(s__x_qtitle_009be3f8,9);
      puVar10 = auStack_38;
      iVar3 = FUN_00404230(puVar10);
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pcVar8 = (char *)(iVar3 + 4);
      }
      else {
        pcVar8 = *(char **)(iVar3 + 4);
      }
      pcVar4 = pcVar8;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return;
      }
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
      piVar5 = (int *)(**(code **)(*piVar5 + 0x4c))(auStack_54);
      puVar6 = (undefined3 *)(**(code **)(*piVar5 + 0x10))();
      iStack_f0 = CONCAT13(iStack_f0._3_1_,*puVar6);
      uStack_ec = *(undefined4 *)(puVar6 + 1);
      uStack_e8 = *(undefined4 *)(puVar6 + 2);
      iStack_e4 = *(int *)(puVar6 + 3);
      uStack_e0 = *(undefined4 *)(puVar6 + 4);
      iStack_dc = *(int *)(puVar6 + 5);
      uStack_d8 = *(undefined4 *)(puVar6 + 6);
      uStack_d4 = *(undefined4 *)(puVar6 + 7);
      FUN_00401660(puVar6 + 8,0,0xffffffff);
      if ((char)in_ECX[0x22] == '\0') {
        uVar11 = 0;
        FUN_00401740(s__x_qbtn_009be404,7);
        iVar3 = FUN_00404230(&uStack_20,puVar10,uVar11);
        if (*(uint *)(iVar3 + 0x18) < 0x10) {
          pcVar4 = (char *)(iVar3 + 4);
        }
        else {
          pcVar4 = *(char **)(iVar3 + 4);
        }
        pcVar7 = pcVar4;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(pcVar4,(int)pcVar7 - (int)(pcVar4 + 1));
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
        piVar9 = (int *)(**(code **)(*in_ECX + 0x3c))();
        piVar9 = (int *)(**(code **)(*piVar9 + 0x4c))(aiStack_74);
        (**(code **)(*piVar9 + 0x30))();
        FUN_00558730(*(undefined1 *)(iVar2 + 0x1e));
        puVar6 = (undefined3 *)(**(code **)(*piVar9 + 0x10))();
        uStack_b4 = CONCAT13(uStack_b4._3_1_,*puVar6);
        uStack_b0 = *(undefined4 *)(puVar6 + 1);
        uStack_ac = *(undefined4 *)(puVar6 + 2);
        iStack_a8 = *(int *)(puVar6 + 3);
        uStack_a4 = *(undefined4 *)(puVar6 + 4);
        iStack_a0 = *(int *)(puVar6 + 5);
        uStack_9c = *(undefined4 *)(puVar6 + 6);
        uStack_98 = *(undefined4 *)(puVar6 + 7);
        FUN_00401660(puVar6 + 8,0,0xffffffff);
      }
      if ((in_ECX[0x1d] < (int)(pcVar8 + 1)) || (iVar3 = in_ECX[0x1c], in_ECX[0x1e] <= iVar3)) {
        iStack_f0 = (uint)iStack_f0._1_3_ << 8;
        if ((char)in_ECX[0x22] == '\0') {
          uStack_b4 = (uint)uStack_b4._1_3_ << 8;
        }
      }
      else {
        iStack_e4 = in_ECX[0x30] * iVar3 + in_ECX[0x21];
        iStack_dc = in_ECX[0x30] + -2 + iStack_e4;
        iStack_f0 = CONCAT31(iStack_f0._1_3_,1);
        if ((char)in_ECX[0x22] == '\0') {
          iStack_a0 = in_ECX[0x32] + iStack_e4;
          uStack_b4 = CONCAT31(uStack_b4._1_3_,1);
          iStack_a8 = iStack_e4;
        }
        in_ECX[0x1c] = iVar3 + 1;
      }
      (**(code **)(*piVar5 + 0xc))(&iStack_f0);
      if ((char)in_ECX[0x22] == '\0') {
        (**(code **)(*piVar9 + 0xc))(&uStack_b0);
      }
      in_ECX[0x1d] = in_ECX[0x1d] + 1;
      if ((char)in_ECX[0x22] == '\0') {
        FUN_00585db0(iVar2 + 0x20,*(undefined1 *)(iVar2 + 0x1e),iStack_f0);
      }
      iVar2 = iVar2 + 0x30;
    } while (iVar2 != aiStack_74[0]);
  }
  iVar2 = 0;
  if (in_ECX[0x1e] < in_ECX[0x1d]) {
    iVar2 = in_ECX[0x1d] - in_ECX[0x1e];
  }
  if (in_ECX[0x20] != iVar2) {
    iVar3 = iVar2;
    (**(code **)(*(int *)in_ECX[0x28] + 0x30))(iVar2);
    FUN_0055aac0(iVar3);
  }
  in_ECX[0x20] = iVar2;
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < uStack_b4) {
    _free(pvStack_c8);
    return;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  if (uStack_3c < 0x10) {
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_00586710 @ 0x00586710 ====

undefined4 FUN_00586710(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00585b30(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_00585b90(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if ((iVar2 == 0x10010) && (cVar1 = FUN_00586150(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_00586790 @ 0x00586790 ====

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_00586790(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *******pppppppuVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  undefined4 *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 unaff_retaddr;
  undefined *puVar13;
  int *local_40;
  void *local_3c;
  undefined4 uStack_38;
  undefined4 *******local_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  bVar12 = false;
  local_3c = (void *)0x0;
  local_40 = in_ECX;
  if (param_1 == 4) {
    bVar12 = true;
    uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009be3f0);
    FUN_00402220(&uStack_38,uVar4);
    pppppppuVar5 = local_34;
    if (local_20 < 0x10) {
      pppppppuVar5 = &local_34;
    }
    iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppppppuVar5,uStack_24);
    if ((iVar6 == 0) && (param_3 == 6)) {
      bVar2 = true;
      goto LAB_0058680d;
    }
  }
  bVar2 = false;
LAB_0058680d:
  if ((bVar12) && (0xf < local_20)) {
    _free(local_34);
    return extraout_EAX;
  }
  if (bVar2) {
    FUN_00586250();
    return 1;
  }
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  local_34 = (undefined4 *******)0x0;
  iStack_30 = 0;
  uStack_2c = 0;
  FUN_00401830(&DAT_009be3cc);
  FUN_00405300(param_2,auStack_1c,&uStack_38);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_00;
  }
  puVar13 = &DAT_009be3d0;
  uVar4 = FUN_00405d30(1);
  cVar3 = FUN_004036a0(uVar4,puVar13);
  if (cVar3 != '\0') {
    uVar4 = FUN_00405d30(0);
    uVar4 = thunk_FUN_00796e90(uVar4);
    iVar8 = *(int *)(in_ECX[0x27] + 8);
    iVar6 = *(int *)(in_ECX[0x27] + 4);
    in_ECX = local_40;
    for (; local_40 = in_ECX, iVar6 != iVar8; iVar6 = iVar6 + 0x30) {
      if ((*(short *)(iVar6 + 0x1c) == (short)uVar4) &&
         (piVar7 = (int *)(**(code **)(*DAT_00b5ac38 + 8))(uVar4), piVar7 != (int *)0x0)) {
        bVar12 = *(char *)(iVar6 + 0x1e) == '\0';
        *(bool *)(iVar6 + 0x1e) = bVar12;
        (**(code **)(*piVar7 + 0x18))(bVar12);
        FUN_00586250();
        FUN_00406250();
        return 1;
      }
      in_ECX = local_40;
    }
  }
  if ((local_34 == (undefined4 *******)0x0) || ((uint)((iStack_30 - (int)local_34) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  iVar6 = FUN_00403620(0,local_34[0xc],s_quest_009be3d8,5);
  if (iVar6 != 0) {
    iVar6 = FUN_00405d30(1);
    iVar6 = FUN_00403620(0,*(undefined4 *)(iVar6 + 0x14),s_qtitle_009be3e0,6);
    if (iVar6 != 0) {
      FUN_00406250();
      return 0;
    }
  }
  puVar11 = (undefined4 *)in_ECX[0x24];
  puVar1 = (undefined4 *)in_ECX[0x25];
  if (puVar11 != puVar1) {
    do {
      piVar7 = (int *)*puVar11;
      iVar6 = (**(code **)(*piVar7 + 0x30))();
      iVar8 = (**(code **)(*piVar7 + 0x50))();
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        puVar10 = (undefined4 *)(param_2 + 4);
      }
      else {
        puVar10 = *(undefined4 **)(param_2 + 4);
      }
      iVar8 = FUN_00403620(0,*(undefined4 *)(iVar8 + 0x14),puVar10,*(undefined4 *)(param_2 + 0x14));
      if (iVar8 == 0) {
        uVar4 = 1;
LAB_00586a09:
        FUN_00558730(uVar4);
      }
      else if (*(char *)(iVar6 + 0x72) != '\0') {
        uVar4 = 0;
        goto LAB_00586a09;
      }
      puVar11 = puVar11 + 1;
    } while (puVar11 != puVar1);
  }
  if ((local_34 == (undefined4 *******)0x0) || ((iStack_30 - (int)local_34) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  uVar9 = thunk_FUN_00796e90(local_34);
  if ((local_34 == (undefined4 *******)0x0) || ((uint)((iStack_30 - (int)local_34) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  iVar6 = FUN_00403620(0,local_34[0xc],s_qtitle_009be3e8,6);
  if (iVar6 == 0) {
    piVar7 = (int *)(**(code **)(*local_40 + 0x3c))();
    (**(code **)(*piVar7 + 0x80))(8,uVar9);
    iVar8 = *(int *)(local_40[0x27] + 8);
    for (iVar6 = *(int *)(local_40[0x27] + 4); iVar6 != iVar8; iVar6 = iVar6 + 0x30) {
      if ((*(ushort *)(iVar6 + 0x1c) == uVar9) &&
         (piVar7 = (int *)(**(code **)(*DAT_00b5ac38 + 8))(uVar9), piVar7 != (int *)0x0)) {
        *(undefined1 *)(iVar6 + 0x1e) = 1;
        (**(code **)(*piVar7 + 0x18))(1);
        FUN_00586250();
      }
    }
  }
  else {
    piVar7 = (int *)(**(code **)(*local_40 + 0x3c))();
    (**(code **)(*piVar7 + 0x80))(9,uVar9);
  }
  if (local_3c == (void *)0x0) {
    return 1;
  }
  FUN_00405de0(local_3c,uStack_38,&local_40,unaff_retaddr);
  _free(local_3c);
  return extraout_EAX_01;
}


// ==== FUN_00586b50 @ 0x00586b50 ====

void FUN_00586b50(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009be474;
  in_ECX[0x1c] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0x12;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  FUN_00505940();
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00586be0 @ 0x00586be0 ====

void FUN_00586be0(void)

{
  undefined4 *in_ECX;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009be474;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((void *)in_ECX[0x24] != (void *)0x0) {
      _free((void *)in_ECX[0x24]);
      return;
    }
    in_ECX[0x24] = 0;
    in_ECX[0x25] = 0;
    in_ECX[0x26] = 0;
    if (*(char *)(in_ECX + 0x11) == '\0') {
      FUN_0044a580(local_100,&DAT_009be464,s_VScroll_Close_Fail_009be3b8);
      FUN_00797b80(local_100);
    }
    else {
      *(undefined1 *)(in_ECX + 0x11) = 0;
      if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[0x10])(1);
      }
      in_ECX[0x10] = 0;
    }
  }
  FUN_005059a0();
  if ((void *)in_ECX[0x24] == (void *)0x0) {
    in_ECX[0x24] = 0;
    in_ECX[0x25] = 0;
    in_ECX[0x26] = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x24]);
  return;
}


// ==== FUN_00586ca0 @ 0x00586ca0 ====

void FUN_00586ca0(int param_1)

{
  int iVar1;
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_00587800(param_1 + 0x40);
  param_1 = 0;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 != (int *)in_ECX[0x2d]) {
    in_ECX[0x33] = local_4[4];
    in_ECX[0x34] = local_4[5];
    in_ECX[0x35] = local_4[6];
  }
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  in_ECX[0x1e] = ((*(int *)(iVar1 + 0x14) + in_ECX[0x21] * -2) - *(int *)(iVar1 + 0xc)) /
                 in_ECX[0x30];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_00586d40 @ 0x00586d40 ====

void FUN_00586d40(uint param_1)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  void *unaff_EBP;
  undefined1 uStack00000000;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 uStack_88;
  int aiStack_84 [2];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  int *piStack_70;
  undefined4 uStack_6c;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined1 uStack_66;
  undefined4 uStack_64;
  int iStack_60;
  int iStack_5c;
  void *pvStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  void *pvStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_6c = (**(code **)(*DAT_00b5a7ac + 8))(1);
  uStack_66 = 1;
  uStack_64 = 0;
  iStack_60 = 0;
  iStack_5c = 0;
  pvStack_58 = (void *)0x0;
  iStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_30 = 0xf;
  uStack_34 = 0;
  uStack_44 = uStack_44 & 0xffffff00;
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = uStack_28 & 0xffffff00;
  pvStack_10 = (void *)0x0;
  uStack_c = 0;
  uStack_8 = 0;
  pvVar3 = operator_new(0x468);
  if (pvVar3 != (void *)0x0) {
    FUN_00505f10();
  }
  uStack_88 = 7;
  FUN_00558e00(aiStack_84,&uStack_88);
  uStack_78 = *(undefined4 *)(aiStack_84[0] + 0x10);
  uStack_74 = *(undefined4 *)(aiStack_84[0] + 0x14);
  piStack_70 = *(int **)(aiStack_84[0] + 0x18);
  uStack_7c = 0;
  FUN_0056ac60(aiStack_84,&uStack_7c);
  uStack_88 = 8;
  piVar4 = (int *)FUN_00558e00(aiStack_84,&uStack_88);
  iVar5 = *piVar4;
  uStack_78 = *(undefined4 *)(iVar5 + 0x10);
  uStack_74 = *(undefined4 *)(iVar5 + 0x14);
  piStack_70 = *(int **)(iVar5 + 0x18);
  uStack_7c = 4;
  FUN_0056ac60(aiStack_84,&uStack_7c);
  FUN_00401660(&uStack00000000,0,0xffffffff);
  FUN_00401660(&uStack00000000,0,0xffffffff);
  iStack_60 = in_stack_0000001c;
  iStack_5c = in_stack_00000020;
  pvStack_58 = (void *)(in_stack_0000001c + *(int *)(in_ECX + 200));
  iStack_54 = in_stack_00000020 + *(int *)(in_ECX + 200);
  uStack_64 = 100;
  uStack_68 = 1;
  uStack_67 = 1;
  (**(code **)(*piVar2 + 8))(&uStack_68);
  piVar4 = *(int **)(in_ECX + 4);
  if ((piVar4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x74))(piVar4), cVar1 != '\0')) {
    cVar1 = (**(code **)(*piVar4 + 0x78))(piVar2);
    if (cVar1 == '\0') {
      (**(code **)(*piVar2 + 0x74))(0);
    }
    else {
      iVar5 = (**(code **)(*piVar4 + 0x38))();
      piVar2[1] = iVar5;
    }
  }
  piVar4 = piStack_70;
  (**(code **)(*piStack_70 + 0x38))(piVar2);
  (**(code **)(*piVar4 + 0x1c))(&uStack_34);
  (**(code **)(*piVar2 + 0x2c))(piVar4);
  (**(code **)(*piVar4 + 0x24))(unaff_EBP);
  if (unaff_EBP != (void *)0x0) {
    FUN_00505d80();
    _free(unaff_EBP);
    return;
  }
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (0xf < uStack_44) {
    _free(pvStack_58);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  if (param_1 < 0x10) {
    return;
  }
  _free(pvStack_10);
  return;
}


// ==== FUN_00586ff0 @ 0x00586ff0 ====

void FUN_00586ff0(int param_1,undefined4 param_2,void *param_3,char param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  int in_ECX;
  char cStack00000020;
  int *apiStack_138 [2];
  uint uStack_130;
  undefined1 *puStack_12c;
  int *piStack_128;
  undefined4 *puStack_124;
  int *piStack_120;
  char *pcStack_11c;
  int iStack_f0;
  void *pvStack_ec;
  int iStack_e8;
  undefined4 uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  undefined4 uStack_d4;
  void *pvStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  int *piStack_bc;
  undefined1 uStack_b4;
  undefined1 uStack_b3;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_80 [4];
  void *pvStack_7c;
  undefined1 auStack_78 [8];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 uStack_64;
  void *pvStack_60;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_3c [20];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  
  if ((param_1 != 0) && (iVar4 = FUN_00403620(), iVar4 != 0)) {
    uStack_e0 = (**(code **)(*DAT_00b5a7ac + 4))();
    iStack_a8 = (**(code **)(*DAT_00b5a7ac + 8))();
    uStack_a4._0_3_ = CONCAT12(1,(undefined2)uStack_a4);
    iStack_a0 = 0;
    uStack_9c = 0;
    uStack_98 = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    uStack_8c = 0;
    uStack_88 = 0;
    uStack_6c = 0xf;
    uStack_70 = 0;
    auStack_80[0] = 0;
    uStack_50 = 0xf;
    uStack_54 = 0;
    uStack_64 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    pvVar5 = operator_new(0x468);
    if (pvVar5 == (void *)0x0) {
      iStack_e8 = 0;
    }
    else {
      iStack_e8 = FUN_00505f10();
    }
    *(undefined1 *)(iStack_e8 + 0x104) = 0;
    *(undefined1 *)(iStack_e8 + 0x105) = 0;
    *(undefined1 *)(iStack_e8 + 0x107) = 0;
    *(undefined1 *)(iStack_e8 + 0x10c) = 0;
    *(undefined4 *)(iStack_e8 + 0x108) = 0xc;
    *(undefined4 *)(iStack_e8 + 0x110) = 500;
    *(undefined1 *)(iStack_e8 + 0x106) = 0;
    FUN_00557be0();
    FUN_00504250();
    if (cStack00000020 == '\n') {
      FUN_00401740();
    }
    else {
      FUN_00401660();
    }
    uStack_d8 = 0;
    uStack_dc = 0xffffff;
    uStack_e0 = 0;
    uStack_d4 = 0;
    FUN_0056ac60();
    FUN_00558e00();
    uStack_dc = *(uint *)(iStack_f0 + 0x10);
    uStack_d8 = *(uint *)(iStack_f0 + 0x14);
    uStack_d4 = *(undefined4 *)(iStack_f0 + 0x18);
    uStack_e0 = 4;
    FUN_0056ac60();
    uStack_e0 = 0;
    FUN_00504250();
    FUN_00505600();
    if ((int *)0xf < piStack_bc) {
      _free(pvStack_d0);
      return;
    }
    FUN_00557be0();
    uStack_e0 = 1;
    FUN_00504250();
    FUN_00505600();
    if ((int *)0xf < piStack_bc) {
      _free(pvStack_d0);
      return;
    }
    uStack_e0 = 4;
    FUN_00504250();
    FUN_00505600();
    if ((int *)0xf < piStack_bc) {
      _free(pvStack_d0);
      return;
    }
    uStack_c8 = 0xf;
    uStack_cc = 0;
    uStack_dc = uStack_dc & 0xffffff00;
    FUN_00401740();
    (**(code **)(*DAT_00b5a688 + 0x34))();
    if (0xf < uStack_d8) {
      pcStack_11c = (char *)0x58731a;
      _free(pvStack_ec);
      return;
    }
    apiStack_138[0] = (int *)0x2;
    pcStack_11c = (char *)0xf;
    piStack_120 = (int *)0x0;
    uStack_130 = uStack_130 & 0xffffff00;
    FUN_00401740(&DAT_009be440);
    apiStack_138[0] = &iStack_f0;
    iVar4 = FUN_00404230();
    if (*(uint *)(iVar4 + 0x18) < 0x10) {
      pcStack_11c = (char *)(iVar4 + 4);
    }
    else {
      pcStack_11c = *(char **)(iVar4 + 4);
    }
    pcVar6 = pcStack_11c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    piStack_120 = (int *)0x587379;
    FUN_00401740();
    if (0xf < uStack_d8) {
      pcStack_11c = (char *)0x587389;
      _free(pvStack_ec);
      return;
    }
    iVar4 = *(int *)(in_ECX + 0xc0);
    iVar2 = *(int *)(in_ECX + 0x70);
    iVar3 = *(int *)(in_ECX + 0x84);
    pcStack_11c = auStack_78;
    if (param_4 != '\b') {
      piStack_120 = &iStack_f0;
      puStack_124 = (undefined4 *)0x587437;
      piStack_120 = (int *)FUN_00402220();
      pcStack_11c = (char *)0x0;
      puStack_124 = (undefined4 *)0x58744a;
      FUN_00401660();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piStack_120 = &iStack_f0;
    puStack_124 = (undefined4 *)0x5873be;
    piStack_120 = (int *)FUN_00402220();
    pcStack_11c = (char *)0x0;
    puStack_124 = (undefined4 *)0x5873d1;
    FUN_00401660();
    if (0xf < uStack_d8) {
      pcStack_11c = (char *)0x5873e1;
      _free(pvStack_ec);
      return;
    }
    uStack_ac = *(undefined4 *)(in_ECX + 0xc4);
    pcStack_11c = (char *)0x5;
    FUN_00402220(apiStack_138,auStack_78,s__qbtn_009be44c);
    FUN_00586d40();
    uStack_a4 = *(undefined4 *)(in_ECX + 0xbc);
    iStack_a0 = (*(int *)(in_ECX + 0x70) + 1) * *(int *)(in_ECX + 0xc0);
    uStack_b0 = 100;
    uStack_b4 = 1;
    uStack_b3 = 1;
    pcStack_11c = (char *)0x58749f;
    iStack_a8 = iVar4 * iVar2 + iVar3;
    (**(code **)(iRam00000001 + 8))();
    pcStack_11c = *(char **)(in_ECX + 4);
    piStack_120 = (int *)0x5874aa;
    FUN_00557b50();
    piStack_120 = (int *)0x5874b6;
    pcStack_11c = (char *)1;
    (**(code **)(*piStack_bc + 0x38))();
    piStack_120 = (int *)auStack_80;
    puStack_124 = (undefined4 *)0x5874c5;
    (**(code **)(*piStack_bc + 0x1c))();
    puStack_124 = &uStack_54;
    piStack_128 = (int *)0x5874d4;
    (**(code **)(*piStack_bc + 8))();
    piStack_128 = piStack_bc;
    puStack_12c = (undefined1 *)0x5874dd;
    (**(code **)(iRam00000001 + 0x2c))();
    uStack_130 = 0x5874e9;
    puStack_12c = auStack_3c;
    (**(code **)(*piStack_bc + 0x24))();
    if (auStack_3c != (undefined1 *)0x0) {
      FUN_00505d80();
      _free(auStack_3c);
      return;
    }
    FUN_00558010();
    *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + 1;
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    if (0xf < uStack_68) {
      _free(pvStack_7c);
      return;
    }
    uStack_68 = 0xf;
    uStack_6c = 0;
    pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  }
  if (_cStack00000020 < 0x10) {
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_005875e0 @ 0x005875e0 ====

void FUN_005875e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00401660(iVar2,0,0xffffffff);
    FUN_00586ff0(*(undefined2 *)(iVar2 + 0x1c));
  }
  return;
}


// ==== FUN_00587630 @ 0x00587630 ====

void FUN_00587630(int param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  *(char *)(in_ECX + 0x22) = param_2;
  FUN_00585fc0();
  in_ECX[0x1c] = 0;
  in_ECX[0x27] = param_1;
  local_3c = 0;
  iVar4 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(param_1 + 8);
  if (iVar4 != iVar1) {
    uVar3 = extraout_ECX;
    do {
      if (param_2 == '\0') {
        FUN_00401660(iVar4,0,0xffffffff);
        FUN_00586ff0(*(undefined2 *)(iVar4 + 0x1c));
        FUN_005875e0(iVar4 + 0x20);
        uVar3 = extraout_ECX_01;
      }
      else {
        if ((short)local_3c == 0) {
          local_3c = CONCAT22((short)((uint)uVar3 >> 0x10),*(undefined2 *)(iVar4 + 0x1c));
        }
        FUN_00401660(iVar4,0,0xffffffff);
        FUN_00586ff0(*(undefined2 *)(iVar4 + 0x1c));
        uVar3 = extraout_ECX_00;
      }
      iVar4 = iVar4 + 0x30;
    } while (iVar4 != iVar1);
  }
  if (param_2 == '\0') {
    param_2 = '\0';
    (**(code **)(*DAT_00b5ac38 + 0x14))(&param_2,&local_3c);
    if (param_2 == '\0') goto LAB_005877e5;
    FUN_00401740(s__x_quest_009be424,8);
    FUN_00404230(local_1c);
  }
  else {
    FUN_00401740(s__x_qtitle_009be418,9);
    FUN_00404230(local_1c);
  }
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_24 = 0;
  local_20 = 0xf;
  FUN_00401660(local_1c,0,0xffffffff);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(local_38);
  if (piVar2 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar2 + 0x30))();
    if (iVar4 != 0) {
      FUN_00558730(1);
    }
  }
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
LAB_005877e5:
  FUN_00586250();
  return;
}


// ==== FUN_00587800 @ 0x00587800 ====

void FUN_00587800(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  if (in_ECX != param_1) {
    FUN_005054c0(&param_1,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
    FUN_00505580(iVar1);
  }
  if (in_ECX + 0xc != iVar1 + 0xc) {
    FUN_00504490(&param_1,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
    FUN_005040e0(iVar1 + 0xc);
  }
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(iVar1 + 0x24);
  return;
}


// ==== FUN_00587870 @ 0x00587870 ====

void FUN_00587870(byte param_1)

{
  void *in_ECX;
  
  FUN_00586be0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00587890 @ 0x00587890 ====

void FUN_00587890(int *param_1)

{
  int *in_ECX;
  
  in_ECX[0x1c] = param_1[0x1a];
  in_ECX[0x20] = *param_1;
  in_ECX[0x21] = param_1[1];
  in_ECX[0x22] = param_1[2];
                    /* WARNING: Could not recover jumptable at 0x005878bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_005878f0 @ 0x005878f0 ====

undefined1 FUN_005878f0(void)

{
  return 0;
}


// ==== FUN_00587900 @ 0x00587900 ====

undefined4 FUN_00587900(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    iVar1 = param_1[2];
    if (iVar1 == 1) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(1,0);
      return 1;
    }
    if (iVar1 == 7) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(4,0);
      return 1;
    }
    if (iVar1 == 8) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(5,0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00587990 @ 0x00587990 ====

void FUN_00587990(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_005879b0 @ 0x005879b0 ====

undefined4 FUN_005879b0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_005879e0 @ 0x005879e0 ====

undefined4 FUN_005879e0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if ((iVar2 == 0x10001) && (cVar1 = FUN_00587900(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_00587a30 @ 0x00587a30 ====

void FUN_00587a30(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x80);
    local_8 = *(undefined4 *)(in_ECX + 0x84);
    local_4 = *(undefined4 *)(in_ECX + 0x88);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00587b00 @ 0x00587b00 ====

undefined4 FUN_00587b00(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  if ((char)in_ECX[0x11] != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  in_ECX[0x10] = (int)piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = *(int *)in_ECX[0x10];
      uVar4 = (**(code **)(*(int *)in_ECX[1] + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x11) = 1;
        uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
        FUN_00552120(uVar4);
        (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(in_ECX[0x10]);
    in_ECX[0x10] = 0;
  }
  return 0;
}


// ==== FUN_00587ba0 @ 0x00587ba0 ====

void FUN_00587ba0(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  float fVar3;
  float fVar4;
  undefined1 auStack_3c [8];
  int iStack_34;
  int iStack_2c;
  void *pvStack_20;
  uint uStack_c;
  
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x10))();
  FUN_005041e0(uVar2);
  fVar4 = (float)in_ECX[0x1c];
  fVar3 = param_1 * DAT_009a09b8 * fVar4;
  if (fVar4 < fVar3) {
    fVar3 = fVar4;
  }
  iStack_2c = (int)fVar3 + iStack_34;
  (**(code **)(*(int *)in_ECX[1] + 0xc))(auStack_3c);
  iVar1 = *in_ECX;
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  (**(code **)(iVar1 + 0xc))(uVar2);
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_00587c20 @ 0x00587c20 ====

void FUN_00587c20(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009be52c;
  iVar1 = FUN_00503b60();
  in_ECX[0x1e] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x1e] + 4) = in_ECX[0x1e];
  *(undefined4 *)in_ECX[0x1e] = in_ECX[0x1e];
  *(undefined4 *)(in_ECX[0x1e] + 8) = in_ECX[0x1e];
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00587c90 @ 0x00587c90 ====

void FUN_00587c90(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009be52c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00504490(local_4,*(undefined4 *)in_ECX[0x1e],(undefined4 *)in_ECX[0x1e]);
  _free((void *)in_ECX[0x1e]);
  return;
}


// ==== FUN_00587cf0 @ 0x00587cf0 ====

void FUN_00587cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00587c90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00587d10 @ 0x00587d10 ====

void FUN_00587d10(int param_1)

{
  int *in_ECX;
  
  in_ECX[0x23] = param_1 * 0x1000000 + (in_ECX[0x23] & 0xffffffU);
                    /* WARNING: Could not recover jumptable at 0x00587d35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00587d40 @ 0x00587d40 ====

void FUN_00587d40(int *param_1)

{
  int *in_ECX;
  
  in_ECX[0x23] = *param_1;
  in_ECX[0x24] = param_1[1];
  in_ECX[0x25] = param_1[2];
                    /* WARNING: Could not recover jumptable at 0x00587d65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00587d70 @ 0x00587d70 ====

void FUN_00587d70(int param_1)

{
  int *in_ECX;
  
  if ((int *)in_ECX[0x10] != (int *)0x0) {
    in_ECX[0x30] = param_1;
    (**(code **)(*(int *)in_ECX[0x10] + 0x14))(in_ECX + 0x26,0);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_00587db0 @ 0x00587db0 ====

undefined4 FUN_00587db0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  return 1;
}


// ==== FUN_00587de0 @ 0x00587de0 ====

undefined4 FUN_00587de0(int *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int *in_ECX;
  uint uVar10;
  undefined4 *puVar11;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  undefined4 auStack_2c [11];
  
  piVar5 = (int *)in_ECX[1];
  iVar3 = (**(code **)(*param_1 + 0x10))();
  iVar4 = (**(code **)(*piVar5 + 4))();
  if (iVar3 == iVar4) {
    if (param_1[2] == 1) {
      piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
      iVar3 = (**(code **)(*piVar5 + 0x14))();
      iStack_3c = param_1[0xe] - *(int *)(iVar3 + 8);
      uStack_38 = param_1[0xf] - *(int *)(iVar3 + 0xc);
      FUN_005897f0();
      piVar6 = (int *)(**(code **)(*in_ECX + 0x3c))();
      piVar5 = &iStack_3c;
      uVar7 = (**(code **)(*piVar6 + 0x50))(piVar5);
      uVar8 = (**(code **)(*in_ECX + 0x18))(uVar7);
      FUN_00589850(uVar8,uVar7,piVar5);
      piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar5 + 0x84))(auStack_2c);
      if (param_1[6] == 1) {
        piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
        (**(code **)(*piVar5 + 0x80))(3,0);
      }
      FUN_00589810();
    }
    if ((char)in_ECX[0x1f] == '\0') {
      if (param_1[2] == 1) {
        piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
        (**(code **)(*piVar5 + 0x80))(10,0);
      }
    }
    else {
      puVar9 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
      iVar3 = param_1[2];
      puVar11 = auStack_2c;
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      iStack_34 = param_1[0xc];
      iVar4 = param_1[0xe];
      uVar1 = param_1[0xf];
      if ((iVar3 == 0) && (param_1[6] == 1)) {
        iStack_3c = iVar4;
        uStack_38 = uVar1;
        if ((char)in_ECX[0x1c] != '\0') {
          uVar10 = (int)(uVar1 - param_1[0xd]) >> 0x1f;
          if (0 < (int)((uVar1 - param_1[0xd] ^ uVar10) - uVar10)) {
            piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
            (**(code **)(*piVar5 + 0x80))(7,iVar4 << 0x10 | uVar1);
          }
          if (((char)in_ECX[0x1c] != '\0') &&
             (uVar10 = iVar4 - iStack_34 >> 0x1f, 0 < (int)((iVar4 - iStack_34 ^ uVar10) - uVar10)))
          {
            piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
            (**(code **)(*piVar5 + 0x80))(7,iVar4 << 0x10 | uVar1);
          }
        }
        cVar2 = FUN_0053bf70(&iStack_3c);
        if (cVar2 != '\0') {
          *(undefined1 *)(in_ECX + 0x1c) = 1;
        }
        return 1;
      }
      if ((iVar3 == 1) && ((param_1[6] == 1 && ((char)in_ECX[0x1c] != '\0')))) {
        *(undefined1 *)(in_ECX + 0x1c) = 0;
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00587fd0 @ 0x00587fd0 ====

void FUN_00587fd0(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_c = *(undefined4 *)(in_ECX + 0x8c);
    local_8 = *(undefined4 *)(in_ECX + 0x90);
    local_4 = *(undefined4 *)(in_ECX + 0x94);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_005880a0 @ 0x005880a0 ====

void FUN_005880a0(undefined1 param_1)

{
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 != (int *)in_ECX[0x21]) {
    in_ECX[0x23] = local_4[4];
    in_ECX[0x24] = local_4[5];
    in_ECX[0x25] = local_4[6];
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_005880f0 @ 0x005880f0 ====

void FUN_005880f0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(1,0);
  if (*(char *)((int)in_ECX + 0x7d) == '\x01') {
    FUN_005880a0(2);
  }
  return;
}


// ==== FUN_00588120 @ 0x00588120 ====

void FUN_00588120(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x10);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar3 + 0x80))(4,iVar2 << 0x10 | uVar1);
  if (*(char *)((int)in_ECX + 0x7d) == '\x01') {
    FUN_005880a0(1);
  }
  return;
}


// ==== FUN_00588160 @ 0x00588160 ====

void FUN_00588160(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(5,0);
  if (*(char *)((int)in_ECX + 0x7d) == '\x01') {
    FUN_005880a0(0);
  }
  return;
}


// ==== FUN_00588190 @ 0x00588190 ====

undefined4 FUN_00588190(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    switch(param_1[2] + -1) {
    case 0:
      FUN_005880f0();
      return 1;
    case 1:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(3,0);
      return 1;
    case 2:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(2,0);
      return 1;
    case 6:
      FUN_00588120(param_1 + 3);
      return 1;
    case 7:
      FUN_00588160();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00588260 @ 0x00588260 ====

undefined4 FUN_00588260(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00588300 @ 0x00588300 ====

void FUN_00588300(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[0x10] != 0) {
    FUN_005523f0(param_1);
    (**(code **)(*(int *)in_ECX[0x10] + 0x14))(param_1,0);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_00588340 @ 0x00588340 ====

void FUN_00588340(undefined1 param_1,void *param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7)

{
  int *in_ECX;
  void *unaff_ESI;
  
  if (in_ECX[0x10] == 0) {
    if (0xf < param_7) {
      _free(param_2);
      return;
    }
  }
  else {
    FUN_00401660(&param_1,0,0xffffffff);
    (**(code **)(*(int *)in_ECX[0x10] + 0x14))(in_ECX + 0x26,0);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    if (0xf < param_4) {
      _free(unaff_ESI);
      return;
    }
  }
  return;
}


// ==== FUN_005883b0 @ 0x005883b0 ====

undefined4 FUN_005883b0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00588190(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_00587de0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00588410 @ 0x00588410 ====

void FUN_00588410(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009be5e4;
  iVar1 = FUN_00503b60();
  in_ECX[0x21] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x21] + 4) = in_ECX[0x21];
  *(undefined4 *)in_ECX[0x21] = in_ECX[0x21];
  *(undefined4 *)(in_ECX[0x21] + 8) = in_ECX[0x21];
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0xf;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  in_ECX[0x30] = 0;
  *(undefined1 *)(in_ECX + 0x32) = 0;
  *(undefined1 *)((int)in_ECX + 0xc9) = 0;
  in_ECX[0x2f] = 1;
  in_ECX[0x31] = 1;
  in_ECX[0x1d] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x1e] = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_005884d0 @ 0x005884d0 ====

void FUN_005884d0(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_4 [4];
  
  *in_ECX = &PTR_FUN_009be5e4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  if ((uint)in_ECX[0x2e] < 0x10) {
    in_ECX[0x2e] = 0xf;
    in_ECX[0x2d] = 0;
    *(undefined1 *)(in_ECX + 0x29) = 0;
    FUN_00504490(auStack_4,*(undefined4 *)in_ECX[0x21],(undefined4 *)in_ECX[0x21]);
    _free((void *)in_ECX[0x21]);
    return;
  }
  _free((void *)in_ECX[0x29]);
  return;
}


// ==== FUN_00588560 @ 0x00588560 ====

void FUN_00588560(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *in_ECX;
  
  piVar2 = param_1;
  *(char *)(in_ECX + 0x1f) = (char)param_1[0x45];
  piVar1 = param_1 + 0x46;
  *(undefined1 *)((int)in_ECX + 0x7d) = *(undefined1 *)((int)param_1 + 0x115);
  if (in_ECX + 0x20 != piVar1) {
    FUN_00504490(&param_1,*(undefined4 *)in_ECX[0x21],(undefined4 *)in_ECX[0x21]);
    FUN_005040e0(piVar1);
  }
  in_ECX[0x23] = *piVar2;
  in_ECX[0x24] = piVar2[1];
  in_ECX[0x25] = piVar2[2];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_005885d0 @ 0x005885d0 ====

void FUN_005885d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005884d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005885f0 @ 0x005885f0 ====

bool FUN_005885f0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) != 0;
}


// ==== FUN_00588600 @ 0x00588600 ====

int FUN_00588600(int param_1)

{
  int extraout_EAX;
  int in_ECX;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 8) == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009be63e,0);
    return param_1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(**(int **)(in_ECX + 4) + 8,0,0xffffffff);
  FUN_00588ab0(local_20,**(undefined4 **)(in_ECX + 4));
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


// ==== FUN_00588700 @ 0x00588700 ====

void FUN_00588700(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 4);
  iVar2 = FUN_00588950(iVar1,*(undefined4 *)(iVar1 + 4),param_1);
  FUN_005889e0(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_00588740 @ 0x00588740 ====

void FUN_00588740(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  iVar2 = FUN_00588950(iVar1,*(undefined4 *)(iVar1 + 4),param_1);
  FUN_005889e0(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_00588780 @ 0x00588780 ====

void FUN_00588780(void)

{
  int in_ECX;
  
  FUN_0059c2f0();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005887a0 @ 0x005887a0 ====

int FUN_005887a0(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  int iVar3;
  undefined1 local_10 [4];
  void *local_c;
  int local_8;
  undefined4 local_4;
  
  local_c = (void *)0x0;
  local_8 = 0;
  local_4 = 0;
  iVar1 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 4);
  iVar2 = param_1;
  if (iVar3 != iVar1) {
    do {
      iVar2 = FUN_00405670(iVar3,local_10);
      if (local_c != (void *)0x0) {
        iVar2 = (local_8 - (int)local_c) * -0x6db6db6d;
        param_1 = (local_8 - (int)local_c) / 0x1c;
        if (param_1 != 0) {
          iVar2 = FUN_00588b10(*(undefined4 *)(in_ECX + 4),local_c,local_8,param_1);
        }
      }
      iVar3 = iVar3 + 0x1c;
    } while (iVar3 != iVar1);
    if (local_c != (void *)0x0) {
      FUN_00405de0(local_c,local_8,local_10,param_1);
      _free(local_c);
      return extraout_EAX;
    }
  }
  return iVar2;
}


// ==== FUN_00588850 @ 0x00588850 ====

void FUN_00588850(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00588880();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined4 *)(in_ECX + 8) = 0;
  FUN_005887a0(param_1);
  return;
}


// ==== FUN_00588880 @ 0x00588880 ====

void FUN_00588880(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009821b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005888ef @ 0x005888ef ====

void Catch_005888ef(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00588910 @ 0x00588910 ====

void FUN_00588910(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_3,0,0xffffffff);
  return;
}


// ==== FUN_00588950 @ 0x00588950 ====

void * FUN_00588950(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009821c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00588910(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005889bd @ 0x005889bd ====

void Catch_005889bd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005889e0 @ 0x005889e0 ====

void FUN_005889e0(uint param_1)

{
  int in_ECX;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0x9249249U - *(int *)(in_ECX + 8) < param_1) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c48c);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_00588a70 @ 0x00588a70 ====

void FUN_00588a70(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00588950(param_1,*(undefined4 *)(param_1 + 4),param_2);
  FUN_005889e0(1);
  *(int *)(param_1 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}


// ==== FUN_00588ab0 @ 0x00588ab0 ====

void FUN_00588ab0(int *param_1,int *param_2)

{
  int in_ECX;
  
  if (param_2 == *(int **)(in_ECX + 4)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  if ((uint)param_2[8] < 0x10) {
    param_2[8] = 0xf;
    param_2[7] = 0;
    *(undefined1 *)(param_2 + 3) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[3]);
  return;
}


// ==== FUN_00588b10 @ 0x00588b10 ====

void FUN_00588b10(undefined4 param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009821d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != param_3; param_2 = param_2 + 0x1c) {
    FUN_00588a70(param_1,param_2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00588b76 @ 0x00588b76 ====

void Catch_00588b76(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    FUN_00588ab0(unaff_EBP + -0x1c,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00588bb0 @ 0x00588bb0 ====

void FUN_00588bb0(void)

{
  int in_ECX;
  
  FUN_0059c2f0();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00588bd0 @ 0x00588bd0 ====

void FUN_00588bd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be6f4;
  return;
}


// ==== FUN_00588be0 @ 0x00588be0 ====

undefined1 FUN_00588be0(void)

{
  return 0;
}


// ==== FUN_00588bf0 @ 0x00588bf0 ====

void FUN_00588bf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be6f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00588c10 @ 0x00588c10 ====

undefined4 FUN_00588c10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00588c20 @ 0x00588c20 ====

int FUN_00588c20(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_00588c30 @ 0x00588c30 ====

int FUN_00588c30(void)

{
  int iVar1;
  undefined1 *puVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x68) + 0x10))();
  *(undefined1 *)(in_ECX + 0x51) = *(undefined1 *)(iVar1 + 1);
  puVar2 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 0x68) + 0x10))();
  *(undefined1 *)(in_ECX + 0x50) = *puVar2;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x68) + 0x10))();
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(iVar1 + 0x14);
  return in_ECX + 0x44;
}


// ==== FUN_00588c80 @ 0x00588c80 ====

void FUN_00588c80(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [5];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  (**(code **)(*in_ECX + 0x54))
            (param_1 - (iStack_8 - iStack_10) / 2,param_2 - (iStack_4 - iStack_c) / 2,1);
  return;
}


// ==== FUN_00588ce0 @ 0x00588ce0 ====

undefined4 * FUN_00588ce0(undefined4 *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  *param_1 = *(undefined4 *)(iVar1 + 0x14);
  param_1[1] = *(undefined4 *)(iVar1 + 0x18);
  return param_1;
}


// ==== FUN_00588d00 @ 0x00588d00 ====

void FUN_00588d00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x6c) = param_1;
  return;
}


// ==== FUN_00588d10 @ 0x00588d10 ====

undefined4 FUN_00588d10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x6c);
}


// ==== FUN_00588d20 @ 0x00588d20 ====

void FUN_00588d20(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x70) = param_1;
  return;
}


// ==== FUN_00588d30 @ 0x00588d30 ====

undefined4 FUN_00588d30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70);
}


// ==== FUN_00588d40 @ 0x00588d40 ====

void FUN_00588d40(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00588d45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x68) + 0x48))();
  return;
}


// ==== FUN_00588d50 @ 0x00588d50 ====

void FUN_00588d50(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00588d55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x68) + 0x4c))();
  return;
}


// ==== FUN_00588d60 @ 0x00588d60 ====

void FUN_00588d60(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [20];
  uint uStack_14;
  uint uStack_10;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if (*(int *)(iVar1 + 4) == 1) {
    *param_1 = *param_1 + (uStack_14 >> 1);
  }
  else if (*(int *)(iVar1 + 4) == 2) {
    *param_1 = *param_1 + uStack_14;
  }
  if (*(int *)(iVar1 + 8) == 1) {
    param_1[1] = param_1[1] + (uStack_10 >> 1);
  }
  else if (*(int *)(iVar1 + 8) == 2) {
    param_1[1] = param_1[1] + uStack_10;
  }
  if (*param_1 < 0) {
    *param_1 = 0;
  }
  else if (uStack_14 < (uint)((*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x14)) + *param_1)) {
    *param_1 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0x1c)) + uStack_14;
  }
  if (param_1[1] < 0) {
    param_1[1] = 0;
  }
  else if (uStack_10 < (uint)((*(int *)(iVar1 + 0x20) - *(int *)(iVar1 + 0x18)) + param_1[1])) {
    param_1[1] = (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x20)) + uStack_10;
  }
  if (*(int *)(iVar1 + 4) == 1) {
    uStack_14 = uStack_14 >> 1;
  }
  else if (*(int *)(iVar1 + 4) != 2) goto LAB_00588e1f;
  *param_1 = *param_1 - uStack_14;
LAB_00588e1f:
  if (*(int *)(iVar1 + 8) == 1) {
    param_1[1] = param_1[1] - (uStack_10 >> 1);
  }
  else if (*(int *)(iVar1 + 8) == 2) {
    param_1[1] = param_1[1] - uStack_10;
    return;
  }
  return;
}


// ==== FUN_00588e50 @ 0x00588e50 ====

void FUN_00588e50(int *param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  int iStack_8;
  int iStack_4;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  iStack_8 = *(int *)(iVar1 + 0x14) + *param_2;
  iStack_4 = *(int *)(iVar1 + 0x18) + param_2[1];
  FUN_00588d60(&iStack_8);
  *param_1 = iStack_8;
  param_1[1] = iStack_4;
  return;
}


// ==== FUN_00588ea0 @ 0x00588ea0 ====

void FUN_00588ea0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int *unaff_retaddr;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  int iStack_78;
  undefined1 auStack_74 [16];
  undefined4 auStack_64 [20];
  int iStack_14;
  int iStack_10;
  int *piStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar3 = auStack_64;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  iStack_78 = iStack_10;
  iStack_7c = iStack_14;
  uStack_84 = 0;
  uStack_80 = 0;
  (**(code **)(**(int **)(in_ECX + 0x68) + 0x6c))(auStack_74,&uStack_84);
  iVar2 = unaff_retaddr[1];
  *piStack_4 = *unaff_retaddr - iStack_7c;
  piStack_4[1] = iVar2 - iStack_78;
  return;
}


// ==== FUN_00588f20 @ 0x00588f20 ====

uint FUN_00588f20(undefined4 param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x6c) != 0) {
    in_EAX = (**(code **)(**(int **)(in_ECX + 0x6c) + 0x1c))(param_1);
    if ((char)in_EAX == '\x01') {
      return in_EAX;
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00588f40 @ 0x00588f40 ====

undefined4 FUN_00588f40(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x68);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  cVar2 = (**(code **)(*param_1 + 0x74))(piVar1);
  if (cVar2 != '\0') {
    cVar2 = (**(code **)(*piVar1 + 0x78))(param_1);
    if (cVar2 == '\0') {
      (**(code **)(*param_1 + 0x74))(0);
      return 1;
    }
    iVar3 = (**(code **)(*piVar1 + 0x38))();
    param_1[1] = iVar3;
  }
  return 1;
}


// ==== FUN_00588f90 @ 0x00588f90 ====

undefined4 FUN_00588f90(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x68) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x3c))();
  if (*(int *)(in_ECX + 0x68) == iVar2) {
    iVar2 = (**(code **)(*param_1 + 0x3c))();
    if (iVar2 != 0) {
      piVar3 = (int *)(**(code **)(*param_1 + 0x3c))();
      cVar1 = (**(code **)(*piVar3 + 0x7c))(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00588fe0 @ 0x00588fe0 ====

undefined4 FUN_00588fe0(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    if ((DAT_00b5a7a0 != (int *)0x0) && (cVar1 = (**(code **)(*DAT_00b5a7a0 + 8))(), cVar1 == '\0'))
    {
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5a7ac + 0xc))(*(undefined4 *)(in_ECX + 0x68));
    if (cVar1 != '\0') {
      *(undefined4 *)(in_ECX + 0x68) = 0;
      *(undefined1 *)(in_ECX + 8) = 0;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00589030 @ 0x00589030 ====

void FUN_00589030(int param_1,int param_2,char param_3)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [5];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = iStack_8 - iStack_10;
  if (param_3 != '\0') {
    FUN_00588d60(&param_1);
  }
  iStack_10 = param_1;
  iStack_8 = param_1 + iVar2;
  iStack_4 = (iStack_4 - iStack_c) + param_2;
  iStack_c = param_2;
  (**(code **)(*in_ECX + 0x18))(auStack_24);
  return;
}


// ==== FUN_005890a0 @ 0x005890a0 ====

undefined4 FUN_005890a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int in_ECX;
  
  if ((DAT_00b5ac48 != (int *)0x0) &&
     (cVar1 = (**(code **)(*DAT_00b5ac48 + 0x18))(), cVar1 == '\x01')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0x6c) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x6c) + 0x20))(param_1,param_2,param_3,param_4),
     cVar1 != '\x01')) {
    return 0;
  }
  return 1;
}


// ==== FUN_00589100 @ 0x00589100 ====

void FUN_00589100(void)

{
  char cVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be75c;
  if (*(char *)(in_ECX + 2) != '\0') {
    if (DAT_00b5a7a0 != (int *)0x0) {
      cVar1 = (**(code **)(*DAT_00b5a7a0 + 8))();
      if (cVar1 == '\0') goto LAB_0058913e;
    }
    cVar1 = (**(code **)(*DAT_00b5a7ac + 0xc))(in_ECX[0x1a]);
    if (cVar1 != '\0') {
      in_ECX[0x1a] = 0;
      *(undefined1 *)(in_ECX + 2) = 0;
    }
  }
LAB_0058913e:
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0xf;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_009be6f4;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00589170 @ 0x00589170 ====

undefined4 FUN_00589170(undefined4 *param_1)

{
  char cVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    *(undefined4 *)(in_ECX + 0x44) = *param_1;
    *(undefined4 *)(in_ECX + 0x48) = param_1[1];
    *(undefined4 *)(in_ECX + 0x4c) = param_1[2];
    *(undefined1 *)(in_ECX + 0x50) = *(undefined1 *)(param_1 + 3);
    *(undefined1 *)(in_ECX + 0x51) = *(undefined1 *)((int)param_1 + 0xd);
    *(undefined4 *)(in_ECX + 0x54) = param_1[4];
    *(undefined4 *)(in_ECX + 0x58) = param_1[5];
    *(undefined4 *)(in_ECX + 0x5c) = param_1[6];
    *(undefined4 *)(in_ECX + 0x60) = param_1[7];
    *(undefined4 *)(in_ECX + 100) = param_1[8];
    if (*(int *)(in_ECX + 0x68) != 0) {
      local_38 = *(int *)(in_ECX + 0x54) + *(int *)(in_ECX + 0x44);
      local_8 = 0;
      local_18 = 0;
      local_3c = *(undefined1 *)(in_ECX + 0x50);
      local_3b = *(undefined1 *)(in_ECX + 0x51);
      local_20 = *(undefined4 *)(in_ECX + 0x4c);
      local_24 = *(undefined4 *)(in_ECX + 0x48);
      local_30 = *(undefined4 *)(in_ECX + 0x5c);
      local_34 = *(undefined4 *)(in_ECX + 0x58);
      local_28 = *(undefined4 *)(in_ECX + 100);
      local_2c = *(undefined4 *)(in_ECX + 0x60);
      local_3a = 1;
      local_4 = 0xf;
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x68) + 0xc))(&local_3c);
      if (cVar1 != '\0') {
        if (local_8 < 0x10) {
          return 1;
        }
        _free(pvStack_1c);
        return extraout_EAX_00;
      }
      if (0xf < local_8) {
        _free(pvStack_1c);
        return extraout_EAX;
      }
    }
  }
  return 0;
}


// ==== FUN_00589270 @ 0x00589270 ====

void FUN_00589270(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be75c;
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  FUN_0056a840();
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  return;
}


// ==== FUN_005892b0 @ 0x005892b0 ====

uint FUN_005892b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint in_EAX;
  int iVar5;
  uint uVar6;
  int *in_ECX;
  int iStack_24;
  int iStack_20;
  undefined1 auStack_1c [28];
  
  if (*(char *)((int)in_ECX + 9) != '\0') {
    iVar1 = *(int *)(param_1 + 0x38);
    iVar2 = *(int *)(param_1 + 0x3c);
    iVar3 = *(int *)(param_1 + 0x30);
    iVar4 = *(int *)(param_1 + 0x34);
    iVar5 = (**(code **)(*in_ECX + 0x14))();
    iStack_24 = *(int *)(iVar5 + 0x14) + (iVar1 - iVar3);
    iStack_20 = *(int *)(iVar5 + 0x18) + (iVar2 - iVar4);
    FUN_00588d60(&iStack_24);
    in_EAX = *(uint *)(param_1 + 8);
    if ((in_EAX == 0) && (*(int *)(param_1 + 0x18) == 1)) {
      iVar1 = in_ECX[0x16];
      iVar2 = in_ECX[0x17];
      in_ECX[0x16] = iStack_24;
      in_ECX[0x17] = iStack_20;
      in_ECX[0x19] = in_ECX[0x17] + (in_ECX[0x19] - iVar2);
      in_ECX[0x18] = in_ECX[0x16] + (in_ECX[0x18] - iVar1);
      uVar6 = (**(code **)(*in_ECX + 0x18))(in_ECX + 0x11);
      return uVar6 & 0xffffff00;
    }
    if ((in_EAX == 1) && (*(int *)(param_1 + 0x18) == 1)) {
      *(undefined1 *)((int)in_ECX + 9) = 0;
      FUN_00401830(&DAT_009be67c);
      FUN_00796d50(auStack_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_005893c0 @ 0x005893c0 ====

void FUN_005893c0(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int *in_ECX;
  int unaff_ESI;
  undefined1 *puStack_2c;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_4;
  
  puStack_2c = &param_2;
  iVar2 = (**(code **)(*in_ECX + 0x30))();
  if (iVar2 != 0) {
    (**(code **)(*DAT_00b5a7a0 + 0x10))(in_ECX + 1);
    FUN_00588ea0(&puStack_2c,uStack_4);
    puVar1 = puStack_2c;
    if ((((in_ECX[0xc] <= (int)puStack_2c) && (in_ECX[0xd] <= unaff_ESI)) &&
        ((int)puStack_2c < in_ECX[0xe])) && (unaff_ESI < in_ECX[0xf])) {
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      FUN_00401740(&DAT_009be6b0,0x1b);
      FUN_00796d50(auStack_24);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
      *(undefined1 *)((int)in_ECX + 9) = 1;
      in_ECX[3] = (int)puVar1;
      in_ECX[4] = unaff_ESI;
    }
  }
  return;
}


// ==== FUN_00589470 @ 0x00589470 ====

undefined4 FUN_00589470(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  void *pvStack_20;
  uint uStack_18;
  uint uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((char)in_ECX[2] != '\0') {
    return 0;
  }
  FUN_005896d0(param_1);
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_3c = *(undefined1 *)(param_1 + 0x3c);
  uStack_3b = *(undefined1 *)(param_1 + 0x3d);
  uStack_38 = *(undefined4 *)(param_1 + 0x40);
  uStack_34 = *(undefined4 *)(param_1 + 0x44);
  pvStack_24 = *(void **)(param_1 + 0x34);
  pvStack_20 = *(void **)(param_1 + 0x38);
  uStack_28 = *(undefined4 *)(param_1 + 0x50);
  uStack_30 = *(undefined4 *)(param_1 + 0x48);
  pvStack_2c = *(void **)(param_1 + 0x4c);
  uStack_3a = 1;
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  cVar1 = (**(code **)(*piVar2 + 8))(&uStack_3c);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5a7ac + 0xc))(piVar2);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return extraout_EAX;
    }
  }
  else {
    cVar1 = (**(code **)(*DAT_00b5a7a0 + 4))();
    if (cVar1 != '\0') {
      in_ECX[0x1a] = (int)piVar2;
      (**(code **)(*piVar2 + 0x34))();
      *(undefined1 *)(in_ECX + 2) = 1;
      (**(code **)(*in_ECX + 0x18))(in_ECX + 0x11);
      (**(code **)(*DAT_00b5a7a0 + 0x10))(in_ECX + 1);
      if (uStack_18 < 0x10) {
        return 1;
      }
      _free(pvStack_2c);
      return extraout_EAX_01;
    }
    (**(code **)(*DAT_00b5a7ac + 0xc))(piVar2);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX_00;
    }
  }
  return 0;
}


// ==== FUN_005895f0 @ 0x005895f0 ====

undefined4 FUN_005895f0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    if (param_1[2] == 1) {
      uVar3 = (**(code **)(*param_1 + 0x10))();
      FUN_005893c0(param_1 + 7,uVar3);
    }
  }
  else if ((iVar2 == 0x10003) && (cVar1 = FUN_005892b0(param_1), cVar1 != '\0')) {
    return 1;
  }
  cVar1 = (**(code **)(*(int *)in_ECX[0x1a] + 0x1c))(param_1);
  if (cVar1 == '\x01') {
    return 1;
  }
  cVar1 = (**(code **)(*in_ECX + 0x50))();
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 == 0x10001) {
      return 1;
    }
    if (iVar2 == 0x10003) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00589670 @ 0x00589670 ====

undefined4 FUN_00589670(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x68);
}


// ==== FUN_00589680 @ 0x00589680 ====

void FUN_00589680(byte param_1)

{
  void *in_ECX;
  
  FUN_00589100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005896a0 @ 0x005896a0 ====

int FUN_005896a0(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  return param_1;
}


// ==== FUN_005896d0 @ 0x005896d0 ====

void FUN_005896d0(int param_1)

{
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined1 *)(in_ECX + 0x2c) = *(undefined1 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined1 *)(in_ECX + 0x3c) = *(undefined1 *)(param_1 + 0x3c);
  *(undefined1 *)(in_ECX + 0x3d) = *(undefined1 *)(param_1 + 0x3d);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  return;
}


// ==== FUN_00589750 @ 0x00589750 ====

void FUN_00589750(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be804;
  return;
}


// ==== FUN_00589760 @ 0x00589760 ====

void FUN_00589760(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_00589780 @ 0x00589780 ====

int FUN_00589780(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00589790 @ 0x00589790 ====

void FUN_00589790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be810;
  return;
}


// ==== FUN_005897a0 @ 0x005897a0 ====

void FUN_005897a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be804;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005897d0 @ 0x005897d0 ====

int FUN_005897d0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_005897e0 @ 0x005897e0 ====

int FUN_005897e0(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_005897f0 @ 0x005897f0 ====

void FUN_005897f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be85c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  return;
}


// ==== FUN_00589810 @ 0x00589810 ====

void FUN_00589810(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be85c;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009be804;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00589850 @ 0x00589850 ====

void FUN_00589850(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x24) = *param_3;
  *(undefined4 *)(in_ECX + 0x28) = param_3[1];
  return;
}


// ==== FUN_00589880 @ 0x00589880 ====

void FUN_00589880(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be85c;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009be804;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005898d0 @ 0x005898d0 ====

void FUN_005898d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be8c0;
  return;
}


// ==== FUN_005898e0 @ 0x005898e0 ====

void FUN_005898e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be8c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00589940 @ 0x00589940 ====

void FUN_00589940(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00982209;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009be8f8;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0058dad0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0058d030();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x1c);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0058b4c0();
  }
  in_ECX[3] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6b4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6b4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00589a20 @ 0x00589a20 ====

bool FUN_00589a20(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  undefined1 auStack_12 [18];
  
  cVar1 = (**(code **)(*DAT_00b5af50 + 4))(param_1);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(param_1,auStack_12 + -6);
    return cVar1 != '\0';
  }
  return true;
}


// ==== FUN_00589a60 @ 0x00589a60 ====

char FUN_00589a60(int param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  char cVar8;
  int *in_ECX;
  float unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float fStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  cVar7 = (**(code **)(*(int *)in_ECX[2] + 0x10))(param_1,param_2);
  if (cVar7 == '\x01') {
    return '\x01';
  }
  cVar7 = (**(code **)(*(int *)in_ECX[1] + 0x10))(param_1,&fStack_30);
  cVar8 = (**(code **)(*in_ECX + 0xc))(param_1,&fStack_24);
  if (cVar8 == '\0') {
    if (cVar7 == '\x01') {
      *param_2 = unaff_EDI;
      param_2[1] = unaff_ESI;
      param_2[2] = unaff_EBP;
      param_2[3] = fStack_34;
      param_2[4] = fStack_30;
    }
    return cVar7;
  }
  if (cVar7 == '\0') {
    if (cVar8 == '\x01') {
      *param_2 = uStack_2c;
      param_2[1] = uStack_28;
      param_2[2] = fStack_24;
      param_2[3] = fStack_20;
      param_2[4] = fStack_1c;
      return '\x01';
    }
  }
  else {
    fVar1 = unaff_EBP - *(float *)(param_1 + 0xc);
    fVar3 = fStack_34 - *(float *)(param_1 + 0x10);
    fVar2 = fStack_30 - *(float *)(param_1 + 0x14);
    fVar4 = fStack_24 - *(float *)(param_1 + 0xc);
    fVar5 = fStack_20 - *(float *)(param_1 + 0x10);
    fVar6 = fStack_1c - *(float *)(param_1 + 0x14);
    if (SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2) <
        SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6)) {
      *param_2 = unaff_EDI;
      param_2[1] = unaff_ESI;
      param_2[2] = unaff_EBP;
      param_2[3] = fStack_34;
      param_2[4] = fStack_30;
      return '\x01';
    }
    *param_2 = uStack_2c;
    param_2[1] = uStack_28;
    param_2[2] = fStack_24;
    param_2[3] = fStack_20;
    param_2[4] = fStack_1c;
    cVar8 = '\x01';
  }
  return cVar8;
}


// ==== FUN_00589bf0 @ 0x00589bf0 ====

char FUN_00589bf0(int *param_1)

{
  char cVar1;
  char cVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 *puStack_c;
  
  cVar1 = (**(code **)(*DAT_00b5af50 + 8))(param_1,&local_28,*param_1 == 8);
  cVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(param_1,&fStack_20);
  if (cVar2 == '\0') {
    if (cVar1 == '\x01') {
      *puStack_c = unaff_ESI;
      puStack_c[1] = unaff_EBX;
      puStack_c[2] = fStack_34;
      puStack_c[3] = fStack_30;
      puStack_c[4] = fStack_2c;
    }
    return cVar1;
  }
  if (cVar1 == '\0') {
    if (cVar2 == '\x01') {
      *puStack_c = local_28;
      puStack_c[1] = uStack_24;
      puStack_c[2] = fStack_20;
      puStack_c[3] = fStack_1c;
      puStack_c[4] = fStack_18;
      return '\x01';
    }
  }
  else {
    if (SQRT((fStack_34 - (float)param_1[3]) * (fStack_34 - (float)param_1[3]) +
             (fStack_30 - (float)param_1[4]) * (fStack_30 - (float)param_1[4]) +
             (fStack_2c - (float)param_1[5]) * (fStack_2c - (float)param_1[5])) <
        SQRT((fStack_20 - (float)param_1[3]) * (fStack_20 - (float)param_1[3]) +
             (fStack_1c - (float)param_1[4]) * (fStack_1c - (float)param_1[4]) +
             (fStack_18 - (float)param_1[5]) * (fStack_18 - (float)param_1[5]))) {
      *puStack_c = unaff_ESI;
      puStack_c[1] = unaff_EBX;
      puStack_c[2] = fStack_34;
      puStack_c[3] = fStack_30;
      puStack_c[4] = fStack_2c;
      return '\x01';
    }
    *puStack_c = local_28;
    puStack_c[1] = uStack_24;
    puStack_c[2] = fStack_20;
    puStack_c[3] = fStack_1c;
    puStack_c[4] = fStack_18;
    cVar2 = '\x01';
  }
  return cVar2;
}


// ==== FUN_00589d80 @ 0x00589d80 ====

float10 FUN_00589d80(undefined4 *param_1)

{
  char cVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  cVar1 = (**(code **)(*DAT_00b5af50 + 0xc))();
  if (cVar1 == '\0') {
    return (float10)DAT_0099cdc8;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x18))(param_1,(int)register0x00000010 + -0xc);
  if (cVar1 == '\0') {
    return (float10)(float)param_1;
  }
  puVar2 = &local_8;
  if ((float)&local_8 <= (float)param_1) {
    puVar2 = param_1;
  }
  return (float10)(float)puVar2;
}


// ==== FUN_00589e10 @ 0x00589e10 ====

undefined4 FUN_00589e10(undefined4 *param_1)

{
  char cVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *unaff_retaddr;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = (float *)0x0;
  local_4 = 0;
  cVar1 = (**(code **)(*DAT_00b5af50 + 0xc))();
  if (cVar1 == '\0') {
    *unaff_retaddr = 0;
    return 0;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x18))(param_1,(int)register0x00000010 + -0xc);
  if (cVar1 != '\0') {
    puVar2 = &local_8;
    if ((float)&local_8 <= (float)param_1) {
      puVar2 = param_1;
    }
    *local_8 = (float)puVar2;
  }
  *local_8 = (float)param_1;
  return 1;
}


// ==== FUN_00589e90 @ 0x00589e90 ====

void FUN_00589e90(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(param_1,param_2);
  if (cVar1 == '\x01') {
    return;
  }
  (**(code **)(*DAT_00b5af50 + 0x10))(param_1,param_2);
  return;
}


// ==== FUN_00589ec0 @ 0x00589ec0 ====

float10 FUN_00589ec0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return (float10)DAT_0099cdc8;
  }
  fVar2 = (float10)(**(code **)(*piVar1 + 0x14))();
  return fVar2;
}


// ==== FUN_00589ef0 @ 0x00589ef0 ====

char FUN_00589ef0(float *param_1,ushort *param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort local_30;
  ushort local_2e;
  ushort local_28;
  ushort uStack_26;
  undefined2 local_24;
  undefined2 uStack_22;
  float local_20;
  short sStack_1c;
  short sStack_1a;
  undefined2 local_18;
  undefined2 local_16;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  uVar2 = *param_2;
  uVar3 = param_2[1];
  FUN_004f5730(&local_24);
  local_14 = (float)CONCAT22(uStack_22,local_24) + *param_1;
  local_10 = local_20 + param_1[1];
  local_28 = SUB42(local_20,0);
  uStack_26 = (ushort)((uint)local_20 >> 0x10);
  local_30 = uVar2 >> 7;
  local_2e = uVar3 >> 7;
  local_18 = FUN_00802534();
  local_16 = FUN_00802534();
  cVar1 = (**(code **)(*DAT_00b5a800 + 8))(&local_30,&local_18,local_c,0);
  local_30 = SUB42(local_14,0);
  local_2e = (ushort)((uint)local_14 >> 0x10);
  FUN_004ef0e0(&local_28);
  uVar2 = (sStack_1c + 1) * 0x80 - 1;
  if (local_28 <= uVar2) {
    uVar2 = local_28;
  }
  uVar3 = sStack_1c << 7;
  if ((ushort)(sStack_1c << 7) <= uVar2) {
    uVar3 = uVar2;
  }
  uVar2 = (sStack_1a + 1) * 0x80 - 1;
  *param_2 = uVar3;
  if (uStack_26 <= uVar2) {
    uVar2 = uStack_26;
  }
  if (uVar2 < (ushort)(sStack_1a << 7)) {
    uVar2 = sStack_1a << 7;
  }
  param_2[1] = uVar2;
  return (cVar1 != '\0') + '\x01';
}


// ==== FUN_0058a080 @ 0x0058a080 ====

void FUN_0058a080(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  float local_8;
  float local_4;
  
  iVar4 = *param_2;
  if (DAT_009a09b8 <= (float)param_2[2] - (float)iVar4) {
    if ((float)param_2[2] - (float)iVar4 <= DAT_0099d0e4) {
      iVar2 = 1;
    }
    else {
      iVar2 = 2;
      iVar4 = iVar4 + 1;
    }
  }
  else {
    iVar2 = 0;
    iVar4 = iVar4 + -1;
  }
  local_14 = param_2[1];
  if (DAT_009a09b8 <= (float)param_2[3] - (float)local_14) {
    if ((float)param_2[3] - (float)local_14 <= DAT_0099d0e4) {
      iVar3 = 1;
      iVar5 = local_14;
    }
    else {
      iVar3 = 2;
      iVar5 = local_14 + 1;
    }
  }
  else {
    iVar3 = 0;
    iVar5 = local_14 + -1;
  }
  if ((iVar2 == 1) && (iVar3 == 1)) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    return;
  }
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = (float)param_2[2];
  local_4 = (float)param_2[3];
  local_18 = iVar4;
  if (iVar2 == 0) {
    cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
    if (cVar1 != '\0') {
      local_18 = iVar4;
      local_14 = iVar5;
      cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
      if (cVar1 != '\0') goto LAB_0058a1ec;
    }
    local_8 = (float)*param_2 + DAT_009a09b8;
  }
  else if (iVar2 == 2) {
    cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
    if (cVar1 != '\0') {
      local_18 = iVar4;
      local_14 = iVar5;
      cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
      if (cVar1 != '\0') goto LAB_0058a1ec;
    }
    local_8 = (float)(*param_2 + 1) - DAT_009a09b8;
  }
LAB_0058a1ec:
  if (iVar3 == 0) {
    local_18 = *param_2;
    local_14 = iVar5;
    cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
    if (cVar1 != '\0') {
      local_18 = iVar4;
      local_14 = iVar5;
      cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
      if (cVar1 != '\0') goto LAB_0058a294;
    }
    local_4 = (float)param_2[1] + DAT_009a09b8;
  }
  else if (iVar3 == 2) {
    local_18 = *param_2;
    local_14 = iVar5;
    cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
    if (cVar1 != '\0') {
      local_18 = iVar4;
      local_14 = iVar5;
      cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_18);
      if (cVar1 != '\0') goto LAB_0058a294;
    }
    local_4 = (float)(param_2[1] + 1) - DAT_009a09b8;
  }
LAB_0058a294:
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = (int)local_8;
  param_1[3] = (int)local_4;
  return;
}


// ==== FUN_0058a2c0 @ 0x0058a2c0 ====

void FUN_0058a2c0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098221b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009be8f8;
  DAT_00b5a6b4 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009be8c0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0058a340 @ 0x0058a340 ====

bool FUN_0058a340(undefined4 param_1)

{
  char cVar1;
  int *in_ECX;
  undefined1 local_14 [20];
  
  cVar1 = (**(code **)(*(int *)in_ECX[1] + 0x10))(param_1,local_14);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*in_ECX + 0x20))(param_1);
    return cVar1 != '\0';
  }
  return true;
}


// ==== FUN_0058a380 @ 0x0058a380 ====

char FUN_0058a380(float *param_1,uint *param_2)

{
  char cVar1;
  undefined2 uVar2;
  uint *puVar3;
  undefined2 local_34;
  undefined2 local_32;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined1 local_1c [28];
  
  local_34 = (undefined2)*param_2;
  local_30 = (float)param_2[2];
  local_2c = (float)param_2[3];
  local_24 = *param_1 + local_30;
  local_32 = (undefined2)param_2[1];
  local_20 = param_1[1] + local_2c;
  uVar2 = FUN_00802534();
  local_28 = CONCAT22(local_28._2_2_,uVar2);
  uVar2 = FUN_00802534();
  local_28 = CONCAT22(uVar2,(undefined2)local_28);
  cVar1 = (**(code **)(*DAT_00b5a800 + 8))(&local_34,&local_28,local_1c,0);
  *param_2 = (uint)local_2c & 0xffff;
  param_2[2] = local_28;
  param_2[1] = (uint)local_2c >> 0x10;
  param_2[3] = (uint)local_24;
  puVar3 = (uint *)FUN_0058a080(&local_20,param_2);
  *param_2 = *puVar3;
  param_2[1] = puVar3[1];
  param_2[2] = puVar3[2];
  param_2[3] = puVar3[3];
  return (cVar1 != '\0') + '\x01';
}


// ==== FUN_0058a490 @ 0x0058a490 ====

/* WARNING: Removing unreachable block (ram,0x0058a5f5) */

uint FUN_0058a490(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  uint extraout_EAX;
  int *piVar6;
  int iVar7;
  int unaff_EDI;
  float fVar8;
  int local_70;
  int local_6c;
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  int aiStack_50 [16];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098222d;
  pvStack_c = ExceptionList;
  local_70 = *param_1;
  local_6c = param_1[1];
  ExceptionList = &pvStack_c;
  uVar5 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_70);
  if ((char)uVar5 == '\x01') {
    ExceptionList = pvStack_10;
    return uVar5 & 0xffffff00;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  FUN_00401740(s_ChangeMoveableCell_009be8a0,0x12);
  puStack_8 = (undefined1 *)0x0;
  FUN_00796d50(&local_6c);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_54) {
    _free(pvStack_68);
    return extraout_EAX;
  }
  aiStack_50[4] = unaff_EDI + 1;
  aiStack_50[6] = unaff_EDI + -1;
  aiStack_50[1] = local_70 + 1;
  aiStack_50[3] = local_70 + -1;
  aiStack_50[5] = local_70;
  aiStack_50[7] = local_70;
  aiStack_50[0xd] = local_70;
  iVar7 = 0;
  piVar6 = aiStack_50;
  aiStack_50[8] = aiStack_50[4];
  aiStack_50[9] = aiStack_50[1];
  aiStack_50[10] = aiStack_50[4];
  aiStack_50[0xb] = aiStack_50[3];
  aiStack_50[0xe] = aiStack_50[6];
  aiStack_50[0xf] = aiStack_50[1];
  do {
    cVar4 = (**(code **)(*DAT_00b5af50 + 0x14))(piVar6);
    fVar3 = DAT_009be92c;
    fVar2 = DAT_009a09bc;
    fVar8 = DAT_0099d0b4;
    if (cVar4 == '\x01') {
      local_70 = aiStack_50[iVar7 * 2];
      iVar1 = aiStack_50[iVar7 * 2 + 1];
      iVar7 = aiStack_50[iVar7 * 2 + 1];
      fVar8 = (float)iVar7;
      *param_1 = local_70;
      param_1[1] = iVar1;
      param_1[2] = (int)(float)local_70;
      param_1[3] = (int)fVar8;
      param_1[2] = (int)((float)local_70 + fVar3);
      if (param_1[1] < iVar7) {
        fVar8 = fVar8 + fVar2;
      }
      else {
        fVar8 = fVar8 + fVar3;
      }
      goto LAB_0058a64d;
    }
    iVar7 = iVar7 + 1;
    piVar6 = piVar6 + 2;
  } while (iVar7 < 8);
  if (unaff_EDI < 0x100) {
    iVar7 = unaff_EDI + 1;
  }
  else {
    iVar7 = unaff_EDI + -1;
  }
  if (local_70 < 0x100) {
    local_70 = local_70 + 1;
  }
  else {
    local_70 = local_70 + -1;
  }
  param_1[2] = (int)((float)iVar7 + DAT_0099d0b4);
  *param_1 = iVar7;
  param_1[1] = local_70;
  fVar8 = (float)local_70 + fVar8;
LAB_0058a64d:
  param_1[3] = (int)fVar8;
  ExceptionList = pvStack_10;
  return CONCAT31((int3)((uint)local_70 >> 8),1);
}


// ==== FUN_0058a670 @ 0x0058a670 ====

undefined4 FUN_0058a670(int param_1,float *param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  float unaff_retaddr;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  cVar2 = FUN_0058a490(param_1);
  if (cVar2 != '\0') {
    *param_2 = 0.0;
    return 0;
  }
  if (*param_2 <= DAT_009be8b4 && DAT_009be8b4 != *param_2) {
    return 0;
  }
  local_18 = *(float *)(param_1 + 0x10) - *(float *)(param_1 + 8);
  local_14 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0xc);
  fVar1 = SQRT(local_18 * local_18 + local_14 * local_14);
  if (fVar1 < DAT_009be8b4) {
    return 3;
  }
  if (*param_2 <= fVar1) {
    uVar4 = 1;
  }
  else {
    uVar4 = 3;
  }
  thunk_FUN_0079de77(&local_10,&local_18);
  local_10 = local_18 * unaff_retaddr;
  fStack_c = local_14 * unaff_retaddr;
  iVar3 = (**(code **)(*in_ECX + 0x30))(&local_10,param_1);
  if (iVar3 == 2) {
    return 2;
  }
  *param_2 = *param_2 - fStack_8;
  return uVar4;
}


// ==== FUN_0058a790 @ 0x0058a790 ====

undefined1 FUN_0058a790(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined **local_82c;
  undefined **local_828 [3];
  undefined4 local_81c;
  undefined **local_818 [511];
  uint uStack_1c;
  void *pvStack_18;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00982242;
  pvStack_c = ExceptionList;
  local_82c = *(undefined ***)(param_1 + 8);
  local_828[0] = *(undefined ***)(param_1 + 0xc);
  local_81c = *(undefined4 *)(param_1 + 0x10);
  local_818[0] = *(undefined ***)(param_1 + 0x14);
  local_818[1] = &PTR_FUN_0099ffa8;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5a800 + 4))(&local_82c,&local_81c,local_818 + 1);
  if (cVar1 == '\0') {
    ExceptionList = pvStack_18;
    return 0;
  }
  if (uStack_1c == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = 1;
    if (1 < uStack_1c) {
      do {
        local_82c = local_818[uVar3 * 2];
        FUN_0058ac00(local_818 + -6);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uStack_1c);
    }
    uVar2 = 1;
  }
  ExceptionList = pvStack_18;
  return uVar2;
}


// ==== FUN_0058a8a0 @ 0x0058a8a0 ====

void FUN_0058a8a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ffa8;
  return;
}


// ==== FUN_0058a8b0 @ 0x0058a8b0 ====

void FUN_0058a8b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0058a2c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058a8d0 @ 0x0058a8d0 ====

void FUN_0058a8d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00751a10(param_1,param_2,param_3);
  return;
}


// ==== FUN_0058a8f0 @ 0x0058a8f0 ====

void FUN_0058a8f0(void)

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
  puStack_8 = &LAB_00982258;
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


// ==== FUN_0058a960 @ 0x0058a960 ====

void FUN_0058a960(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982270;
  local_10 = ExceptionList;
  local_1c = param_3[1];
  local_20 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 3;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar2 = FUN_0058a8f0();
      iVar3 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 3;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 8);
      local_8 = 0;
      local_18 = pvVar4;
      iVar3 = FUN_00751a10(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00429bc0(iVar3,param_2,&local_20);
      FUN_00751a10(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 8);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 8);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 8;
    if ((uint)(iVar6 - param_1 >> 3) < param_2) {
      FUN_00751a10(param_1,iVar6,iVar3 + param_1);
      local_8 = 2;
      FUN_004b9150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) + param_2 * -8,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_2 * -8;
    uVar5 = FUN_00751a10(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00576790(param_1,iVar7,iVar6);
    FUN_00686630(param_1,iVar3 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0058aad1 @ 0x0058aad1 ====

void Catch_0058aad1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0058abb0 @ 0x0058abb0 ====

void FUN_0058abb0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (*(int *)(in_ECX + 8) - iVar1 >> 3 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - iVar1 >> 3;
  }
  FUN_0058a960(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 8;
  return;
}


// ==== FUN_0058ac00 @ 0x0058ac00 ====

void FUN_0058ac00(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_0058a960(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00429bc0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_0058ac70 @ 0x0058ac70 ====

void FUN_0058ac70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be974;
  return;
}


// ==== FUN_0058ac80 @ 0x0058ac80 ====

void FUN_0058ac80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009be974;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058aca0 @ 0x0058aca0 ====

void FUN_0058aca0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x25) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x25) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x25);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x25);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x25) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x25) == '\0');
    if (*(char *)((int)piVar4 + 0x25) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0058ad30 @ 0x0058ad30 ====

char FUN_0058ad30(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  char cVar8;
  int in_ECX;
  char cVar9;
  float local_1c;
  undefined4 local_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x14);
  puVar2 = (undefined4 *)*puVar1;
  cVar9 = '\0';
  local_1c = 0.0;
  while (puVar2 != puVar1) {
    cVar8 = (**(code **)(*(int *)puVar2[4] + 0x18))(param_1,&local_14);
    if (cVar8 != '\0') {
      if (cVar9 == '\0') {
        *param_2 = local_14;
        param_2[1] = uStack_10;
        param_2[2] = fStack_c;
        param_2[3] = fStack_8;
        param_2[4] = fStack_4;
        fVar4 = (float)param_2[2] - *(float *)(param_1 + 0xc);
        cVar9 = '\x01';
        fVar6 = (float)param_2[3] - *(float *)(param_1 + 0x10);
        fVar5 = (float)param_2[4] - *(float *)(param_1 + 0x14);
        local_1c = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);
      }
      else {
        fVar4 = fStack_c - *(float *)(param_1 + 0xc);
        fVar6 = fStack_8 - *(float *)(param_1 + 0x10);
        fVar5 = fStack_4 - *(float *)(param_1 + 0x14);
        fVar4 = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);
        if (fVar4 < local_1c) {
          *param_2 = local_14;
          param_2[1] = uStack_10;
          param_2[2] = fStack_c;
          param_2[3] = fStack_8;
          param_2[4] = fStack_4;
          local_1c = fVar4;
        }
      }
    }
    if (*(char *)((int)puVar2 + 0x25) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x25) == '\0') {
        cVar8 = *(char *)((int)*puVar3 + 0x25);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar8 == '\0') {
          cVar8 = *(char *)((int)*puVar3 + 0x25);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar8 = *(char *)((int)puVar2[1] + 0x25);
        puVar7 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar7, cVar8 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar8 = *(char *)((int)puVar2[1] + 0x25);
          puVar7 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return cVar9;
}


// ==== FUN_0058aea0 @ 0x0058aea0 ====

void FUN_0058aea0(float *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  float unaff_retaddr;
  float local_38;
  float fStack_34;
  float fStack_30;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_20 = 0.0;
  local_1c = 0.0;
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_c = param_1[3];
  local_8 = param_1[4];
  local_4 = param_1[5];
  puVar1 = *(undefined4 **)(in_ECX + 0x14);
  local_24 = 6;
  puVar2 = (undefined4 *)*puVar1;
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar2;
          if (puVar5 == puVar1) {
            return;
          }
          cVar3 = (**(code **)(*(int *)puVar5[4] + 0x18))(&local_24,&local_38);
          local_4 = (float)CONCAT31(local_4._1_3_,cVar3);
          if ((cVar3 == '\x01') &&
             (unaff_retaddr <
              SQRT((local_20 - local_38) * (local_20 - local_38) +
                   (local_1c - fStack_34) * (local_1c - fStack_34) +
                   (local_18 - fStack_30) * (local_18 - fStack_30)))) {
            local_4 = (float)((uint)local_4._1_3_ << 8);
          }
          (**(code **)(*(int *)puVar5[4] + 0x14))(local_4);
          puVar2 = puVar5;
        } while (*(char *)((int)puVar5 + 0x25) != '\0');
        puVar2 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar2 + 0x25) != '\0') break;
        cVar3 = *(char *)((int)*puVar2 + 0x25);
        puVar5 = (undefined4 *)*puVar2;
        while (cVar3 == '\0') {
          cVar3 = *(char *)((int)*puVar5 + 0x25);
          puVar2 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar2 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar2 + 0x25) != '\0');
    do {
      puVar4 = puVar2;
      puVar2 = puVar4;
      if (puVar5 != (undefined4 *)puVar4[2]) break;
      puVar2 = (undefined4 *)puVar4[1];
      puVar5 = puVar4;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  } while( true );
}


// ==== FUN_0058afc0 @ 0x0058afc0 ====

void FUN_0058afc0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x14);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[4] + 0x10))();
    if (*(char *)((int)puVar3 + 0x25) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x25);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x25);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x25);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x25);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_0058b020 @ 0x0058b020 ====

undefined4 FUN_0058b020(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0058b9b0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x14)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_0058b050 @ 0x0058b050 ====

uint FUN_0058b050(float *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  int in_ECX;
  uint uVar3;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar3 = ((int)(*param_1 * DAT_009af898) < 0) - 1 & (int)(*param_1 * DAT_009af898);
  uVar1 = (int)(param_1[1] * DAT_009af898) & ((int)(param_1[1] * DAT_009af898) < 0) - 1;
  local_8 = uVar3;
  local_4 = uVar1;
  local_c = FUN_0058b840(&local_8);
  if (((local_c == *(uint *)(in_ECX + 8)) || ((int)uVar3 < *(int *)(local_c + 0xc))) ||
     (((int)uVar3 <= *(int *)(local_c + 0xc) && ((int)uVar1 < *(int *)(local_c + 0x10))))) {
    local_8 = *(uint *)(in_ECX + 8);
    puVar2 = &local_8;
  }
  else {
    puVar2 = &local_c;
  }
  if (*puVar2 == *(uint *)(in_ECX + 8)) {
    return *puVar2 & 0xffffff00;
  }
  uVar1 = FUN_0058e350(param_1,param_2);
  return uVar1;
}


// ==== FUN_0058b110 @ 0x0058b110 ====

uint FUN_0058b110(float *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  int in_ECX;
  uint uVar3;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar3 = ((int)(*param_1 * DAT_009af898) < 0) - 1 & (int)(*param_1 * DAT_009af898);
  uVar1 = (int)(param_1[1] * DAT_009af898) & ((int)(param_1[1] * DAT_009af898) < 0) - 1;
  local_8 = uVar3;
  local_4 = uVar1;
  local_c = FUN_0058b840(&local_8);
  if (((local_c == *(uint *)(in_ECX + 8)) || ((int)uVar3 < *(int *)(local_c + 0xc))) ||
     (((int)uVar3 <= *(int *)(local_c + 0xc) && ((int)uVar1 < *(int *)(local_c + 0x10))))) {
    local_8 = *(uint *)(in_ECX + 8);
    puVar2 = &local_8;
  }
  else {
    puVar2 = &local_c;
  }
  if (*puVar2 == *(uint *)(in_ECX + 8)) {
    return *puVar2 & 0xffffff00;
  }
  uVar1 = FUN_0058e410(param_1,param_2);
  return uVar1;
}


// ==== FUN_0058b230 @ 0x0058b230 ====

void FUN_0058b230(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined1 local_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009822bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0058b950(&param_1,param_1);
  if (param_1 == *(undefined4 **)(in_ECX + 8)) {
    param_1 = operator_new(0x24);
    local_4 = 0;
    if (param_1 == (undefined4 *)0x0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_0058e670(puVar1);
    }
    local_18 = *puVar1;
    local_14 = puVar1[1];
    local_4 = 0xffffffff;
    FUN_0058bfe0(local_20,&local_18);
  }
  FUN_0058e540(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0058b2f0 @ 0x0058b2f0 ====

undefined4 FUN_0058b2f0(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  int in_ECX;
  int *piVar5;
  uint local_18;
  undefined4 *local_14;
  undefined4 *puStack_10;
  int local_c;
  int *local_8;
  int local_4;
  
  local_4 = in_ECX + 0x10;
  local_c = in_ECX;
  FUN_0058b9b0(&local_18,&param_1);
  if (local_18 == *(uint *)(in_ECX + 0x14)) {
    return 0;
  }
  local_8 = *(int **)(local_18 + 0x1c);
  piVar5 = *(int **)(local_18 + 0x18);
  if (piVar5 != local_8) {
    do {
      local_14 = *(undefined4 **)(in_ECX + 8);
      if (*(char *)((int)local_14[1] + 0x19) == '\0') {
        puVar2 = (undefined4 *)local_14[1];
        do {
          if (((int)puVar2[3] < *piVar5) ||
             (((int)puVar2[3] <= *piVar5 && ((int)puVar2[4] < piVar5[1])))) {
            puVar3 = (undefined4 *)puVar2[2];
          }
          else {
            puVar3 = (undefined4 *)*puVar2;
            local_14 = puVar2;
          }
          puVar2 = puVar3;
        } while (*(char *)((int)puVar3 + 0x19) == '\0');
      }
      if (local_14 == *(undefined4 **)(in_ECX + 8)) {
LAB_0058b394:
        puStack_10 = *(undefined4 **)(in_ECX + 8);
        ppuVar4 = &puStack_10;
      }
      else {
        if ((*piVar5 < (int)local_14[3]) ||
           ((*piVar5 <= (int)local_14[3] && (piVar5[1] < (int)local_14[4])))) goto LAB_0058b394;
        ppuVar4 = &local_14;
      }
      puVar2 = *ppuVar4;
      if (puVar2 != *(undefined4 **)(local_c + 8)) {
        puVar3 = (undefined4 *)puVar2[5];
        FUN_0058e4d0(param_1);
        cVar1 = FUN_0058e1d0();
        if (cVar1 != '\0') {
          if (puVar3 != (undefined4 *)0x0) {
            (**(code **)*puVar3)(1);
          }
          FUN_0058ba20(&local_14,puVar2);
        }
      }
      piVar5 = piVar5 + 2;
    } while (piVar5 != local_8);
  }
  FUN_0058c430(&param_1,local_18);
  return 1;
}


// ==== FUN_0058b410 @ 0x0058b410 ====

void FUN_0058b410(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009822d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009be99c;
  DAT_00b5a720 = 0;
  local_4 = 1;
  FUN_0058c7b0(local_10,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_0058b4c0 @ 0x0058b4c0 ====

void FUN_0058b4c0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009822f5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009be99c;
  iVar1 = FUN_0058b910();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar1 = FUN_00412d20();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a720 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a720 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0058b580 @ 0x0058b580 ====

undefined4 FUN_0058b580(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  bool bVar7;
  undefined4 uStack_3c;
  undefined4 *local_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  uStack_3c = (**(code **)(*param_1 + 4))();
  piVar1 = (int *)FUN_0058b9b0(&iStack_34,&uStack_3c);
  if (*piVar1 != *(int *)(in_ECX + 0x14)) {
    return 0;
  }
  (**(code **)(*param_1 + 0xc))(&iStack_28);
  iVar5 = iStack_20;
  iVar4 = iStack_24;
  iVar3 = iStack_28;
  iVar2 = iStack_2c;
  if (iStack_2c < 0x201) {
    bVar7 = -1 < iStack_2c;
    iStack_2c = 0;
    if (bVar7) goto LAB_0058b5ee;
  }
  else {
    iVar2 = 0x200;
LAB_0058b5ee:
    iStack_2c = iVar2;
  }
  if (iStack_28 < 0x201) {
    bVar7 = -1 < iStack_28;
    iStack_28 = 0;
    if (bVar7) goto LAB_0058b60c;
  }
  else {
    iVar3 = 0x200;
LAB_0058b60c:
    iStack_28 = iVar3;
  }
  if (iStack_24 < 0x201) {
    bVar7 = -1 < iStack_24;
    iStack_24 = 0;
    if (bVar7) goto LAB_0058b62a;
  }
  else {
    iVar4 = 0x200;
LAB_0058b62a:
    iStack_24 = iVar4;
  }
  if (iStack_20 < 0x201) {
    bVar7 = iStack_20 < 0;
    iStack_20 = 0;
    if (bVar7) goto LAB_0058b64c;
  }
  else {
    iVar5 = 0x200;
  }
  iStack_20 = iVar5;
LAB_0058b64c:
  FUN_0058b740(&iStack_1c,&iStack_2c);
  puVar6 = (undefined4 *)FUN_0058cc80((int)register0x00000010 + -0x40);
  *puVar6 = param_1;
  iVar2 = iStack_1c;
  local_38 = puVar6;
  if (iStack_1c < iStack_14) {
    do {
      if (iStack_18 < iStack_10) {
        iVar3 = iStack_18;
        do {
          iStack_34 = iVar2;
          iStack_30 = iVar3;
          FUN_0058b230(&iStack_34,param_1);
          iVar4 = puVar6[2];
          if ((iVar4 == 0) || ((uint)(puVar6[4] - iVar4 >> 3) <= (uint)(puVar6[3] - iVar4 >> 3))) {
            FUN_0058c0b0(puVar6[3],1,&iStack_34);
          }
          else {
            iVar4 = puVar6[3];
            FUN_00429bc0(iVar4,1,&iStack_34,puVar6 + 1,local_38);
            puVar6[3] = iVar4 + 8;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iStack_10);
        puVar6 = local_38;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iStack_14);
  }
  return 1;
}


// ==== FUN_0058b740 @ 0x0058b740 ====

void FUN_0058b740(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_2 >> 4;
  uVar2 = param_2[1] >> 4;
  if ((int)(param_2[2] - *param_2) < 1) {
    uVar4 = uVar1;
  }
  else {
    uVar4 = (param_2[2] - 1 >> 4) + 1;
  }
  if ((int)(param_2[3] - param_2[1]) < 1) {
    uVar3 = uVar2;
  }
  else {
    uVar3 = (param_2[3] - 1 >> 4) + 1;
  }
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar4;
  param_1[3] = uVar3;
  return;
}


// ==== FUN_0058b7a0 @ 0x0058b7a0 ====

void FUN_0058b7a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x19) == '\0') {
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


// ==== FUN_0058b7f0 @ 0x0058b7f0 ====

void FUN_0058b7f0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x25) == '\0') {
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


// ==== FUN_0058b840 @ 0x0058b840 ====

undefined4 * FUN_0058b840(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x19) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((int)puVar2[3] < *param_1) ||
         (((int)puVar2[3] <= *param_1 && ((int)puVar2[4] < param_1[1])))) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  return puVar2;
}


// ==== FUN_0058b880 @ 0x0058b880 ====

void FUN_0058b880(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_0058b880(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0058b8c0 @ 0x0058b8c0 ====

void FUN_0058b8c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    puVar1[5] = param_4[2];
    *(undefined1 *)(puVar1 + 6) = param_5;
    *(undefined1 *)((int)puVar1 + 0x19) = 0;
  }
  return;
}


// ==== FUN_0058b910 @ 0x0058b910 ====

void FUN_0058b910(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  return;
}


// ==== FUN_0058b950 @ 0x0058b950 ====

void FUN_0058b950(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0058b840(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(int *)(iVar1 + 0xc) <= *param_2) &&
       ((*(int *)(iVar1 + 0xc) < *param_2 || (*(int *)(iVar1 + 0x10) <= param_2[1])))) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0058b9b0 @ 0x0058b9b0 ====

void FUN_0058b9b0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0058ba20 @ 0x0058ba20 ====

/* WARNING: Removing unreachable block (ram,0x0058bb33) */
/* WARNING: Removing unreachable block (ram,0x0058bb43) */
/* WARNING: Removing unreachable block (ram,0x0058bb4c) */
/* WARNING: Removing unreachable block (ram,0x0058bb4f) */
/* WARNING: Removing unreachable block (ram,0x0058bb3f) */
/* WARNING: Removing unreachable block (ram,0x0058bb5d) */
/* WARNING: Removing unreachable block (ram,0x0058bb6a) */
/* WARNING: Removing unreachable block (ram,0x0058bb75) */
/* WARNING: Removing unreachable block (ram,0x0058bb71) */
/* WARNING: Removing unreachable block (ram,0x0058bb65) */
/* WARNING: Removing unreachable block (ram,0x0058bb78) */

void FUN_0058ba20(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00982288;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x19) != '\0') {
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
  FUN_00832d10();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
    if (*(char *)(param_2[2] + 0x19) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      piVar3 = (int *)FUN_00894550(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      uVar4 = FUN_00832cf0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[6] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[6] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar3 + 6) = 0;
            FUN_0058b7a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(*piVar5 + 0x18) == '\x01') && (*(char *)(piVar5[2] + 0x18) == '\x01'))
            goto LAB_0058bc45;
            if (*(char *)(piVar5[2] + 0x18) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x18) = 1;
              *(undefined1 *)(piVar5 + 6) = 0;
              FUN_004b8340(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 6) = (char)piVar3[6];
            *(undefined1 *)(piVar3 + 6) = 1;
            *(undefined1 *)(piVar5[2] + 0x18) = 1;
            FUN_0058b7a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar3 + 6) = 0;
            FUN_004b8340(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(piVar5[2] + 0x18) != '\x01') || (*(char *)(*piVar5 + 0x18) != '\x01')) {
              if (*(char *)(*piVar5 + 0x18) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x18) = 1;
                *(undefined1 *)(piVar5 + 6) = 0;
                FUN_0058b7a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 6) = (char)piVar3[6];
              *(undefined1 *)(piVar3 + 6) = 1;
              *(undefined1 *)(*piVar5 + 0x18) = 1;
              FUN_004b8340(piVar3);
              break;
            }
LAB_0058bc45:
            *(undefined1 *)(piVar5 + 6) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 6) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_0058bcd0 @ 0x0058bcd0 ====

void FUN_0058bcd0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00982288;
  local_c = ExceptionList;
  if (0x15555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0058b8c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x18);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x18) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[6] == '\0') {
LAB_0058bdc9:
        *(undefined1 *)(*piVar5 + 0x18) = 1;
        *(undefined1 *)(piVar6 + 6) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x18) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x18) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
        FUN_004b8340(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[6] == '\0') goto LAB_0058bdc9;
      if (piVar7 == (int *)*piVar2) {
        FUN_004b8340(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x18) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x19) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x18);
  } while( true );
}


// ==== FUN_0058beb0 @ 0x0058beb0 ====

void FUN_0058beb0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0058b880(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x19);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x19);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x19);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0058ba20(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0058bf70 @ 0x0058bf70 ====

void FUN_0058bf70(void)

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
  puStack_8 = &LAB_00982288;
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


// ==== FUN_0058bfe0 @ 0x0058bfe0 ====

void FUN_0058bfe0(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  piVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x19) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (int)puVar4[3]) ||
         ((*param_2 <= (int)puVar4[3] && (param_2[1] < (int)puVar4[4])))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_0058c035;
    }
    FUN_004b83a0();
  }
  if ((*piVar2 <= param_2[3]) && ((*piVar2 < param_2[3] || (piVar2[1] <= param_2[4])))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_0058c035:
  puVar4 = (undefined4 *)FUN_0058bcd0(&param_2,local_4,puVar4,piVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0058c0b0 @ 0x0058c0b0 ====

void FUN_0058c0b0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009822a0;
  local_10 = ExceptionList;
  local_1c = param_3[1];
  local_20 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 3;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar2 = FUN_0058bf70();
      iVar3 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 3;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 8);
      local_8 = 0;
      local_18 = pvVar4;
      iVar3 = FUN_00751a10(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00429bc0(iVar3,param_2,&local_20);
      FUN_00751a10(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 8);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 8);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 8;
    if ((uint)(iVar6 - param_1 >> 3) < param_2) {
      FUN_00751a10(param_1,iVar6,iVar3 + param_1);
      local_8 = 2;
      FUN_004b9150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) + param_2 * -8,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_2 * -8;
    uVar5 = FUN_00751a10(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00576790(param_1,iVar7,iVar6);
    FUN_00686630(param_1,iVar3 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0058c221 @ 0x0058c221 ====

void Catch_0058c221(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0058c300 @ 0x0058c300 ====

void FUN_0058c300(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982300;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x1fffffff < uVar1) {
      uVar1 = FUN_0058bf70();
    }
    pvVar2 = operator_new(uVar1 * 8);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 8 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00751a10(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0058c3a6 @ 0x0058c3a6 ====

void Catch_0058c3a6(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0058c3c0 @ 0x0058c3c0 ====

void FUN_0058c3c0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0058beb0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0058c3f0 @ 0x0058c3f0 ====

void FUN_0058c3f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_0058c3f0(*(undefined4 *)((int)param_1 + 8));
    FUN_00705010();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0058c430 @ 0x0058c430 ====

/* WARNING: Removing unreachable block (ram,0x0058c540) */
/* WARNING: Removing unreachable block (ram,0x0058c551) */
/* WARNING: Removing unreachable block (ram,0x0058c55a) */
/* WARNING: Removing unreachable block (ram,0x0058c55d) */
/* WARNING: Removing unreachable block (ram,0x0058c54d) */
/* WARNING: Removing unreachable block (ram,0x0058c56b) */
/* WARNING: Removing unreachable block (ram,0x0058c578) */
/* WARNING: Removing unreachable block (ram,0x0058c583) */
/* WARNING: Removing unreachable block (ram,0x0058c57f) */
/* WARNING: Removing unreachable block (ram,0x0058c573) */
/* WARNING: Removing unreachable block (ram,0x0058c586) */

void FUN_0058c430(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00982288;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x25) != '\0') {
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
  FUN_0051b6b0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
    if (*(char *)(param_2[2] + 0x25) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      piVar3 = (int *)FUN_00412870(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      uVar4 = FUN_004ae4e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[9] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[9] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_0058b7f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(*piVar5 + 0x24) == '\x01') && (*(char *)(piVar5[2] + 0x24) == '\x01'))
            goto LAB_0058c657;
            if (*(char *)(piVar5[2] + 0x24) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              *(undefined1 *)(piVar5 + 9) = 0;
              FUN_00412890(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 9) = (char)piVar3[9];
            *(undefined1 *)(piVar3 + 9) = 1;
            *(undefined1 *)(piVar5[2] + 0x24) = 1;
            FUN_0058b7f0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_00412890(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(piVar5[2] + 0x24) != '\x01') || (*(char *)(*piVar5 + 0x24) != '\x01')) {
              if (*(char *)(*piVar5 + 0x24) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x24) = 1;
                *(undefined1 *)(piVar5 + 9) = 0;
                FUN_0058b7f0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 9) = (char)piVar3[9];
              *(undefined1 *)(piVar3 + 9) = 1;
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              FUN_00412890(piVar3);
              break;
            }
LAB_0058c657:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 9) = 1;
  }
  if ((void *)param_2[6] == (void *)0x0) {
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[6]);
  return;
}


// ==== FUN_0058c700 @ 0x0058c700 ====

undefined4 *
FUN_0058c700(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982321;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x28);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    FUN_0058c300(param_4 + 2);
    *(undefined1 *)(puVar1 + 9) = param_5;
    *(undefined1 *)((int)puVar1 + 0x25) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0058c78c @ 0x0058c78c ====

void Catch_0058c78c(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0058c7b0 @ 0x0058c7b0 ====

void FUN_0058c7b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0058c3f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x25);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x25);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x25);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0058c430(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0058c870 @ 0x0058c870 ====

void FUN_0058c870(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00982288;
  local_c = ExceptionList;
  if (0xaaaaaa8 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0058c700(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x24);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x24) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[9] == '\0') {
LAB_0058c969:
        *(undefined1 *)(*piVar5 + 0x24) = 1;
        *(undefined1 *)(piVar6 + 9) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x24) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7f0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
        FUN_00412890(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[9] == '\0') goto LAB_0058c969;
      if (piVar7 == (int *)*piVar2) {
        FUN_00412890(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x24) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x25) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x24);
  } while( true );
}


// ==== FUN_0058ca50 @ 0x0058ca50 ====

void FUN_0058ca50(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x25) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x25) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0058c870(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058aca0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0058c870(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0058cb10 @ 0x0058cb10 ====

undefined4 * FUN_0058cb10(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_0058c870(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_0058c870(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_0058c870(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_0058aca0();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x25) == '\0') {
          FUN_0058c870(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_0058c870(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_0051b6b0();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x25) == '\0') {
          FUN_0058c870(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_0058c870(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_0058ca50(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_0058cc80 @ 0x0058cc80 ====

undefined4 * FUN_0058cc80(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24 [3];
  void *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00982340;
  local_c = ExceptionList;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar3[3])) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24[0] = *param_1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_0058c300(local_34);
    local_4 = CONCAT31(local_4._1_3_,1);
    puVar3 = (undefined4 *)FUN_0058cb10(&param_1,puVar3,local_24);
    puVar3 = (undefined4 *)*puVar3;
    if (local_18 != (void *)0x0) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return puVar3 + 4;
}


// ==== FUN_0058cd40 @ 0x0058cd40 ====

void FUN_0058cd40(byte param_1)

{
  void *in_ECX;
  
  FUN_0058b410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058cd60 @ 0x0058cd60 ====

void FUN_0058cd60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bea04;
  return;
}


// ==== FUN_0058cd70 @ 0x0058cd70 ====

void FUN_0058cd70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bea04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058cd90 @ 0x0058cd90 ====

void FUN_0058cd90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0058cd90(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0058cdd0 @ 0x0058cdd0 ====

char FUN_0058cdd0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  int in_ECX;
  char cVar8;
  int iVar9;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  cVar8 = '\0';
  iVar9 = 0;
  while (puVar2 != puVar1) {
    piVar3 = (int *)puVar2[4];
    cVar6 = (**(code **)(*piVar3 + 4))(param_1,&local_14);
    if (cVar6 != '\0') {
      iVar7 = (**(code **)(*piVar3 + 0xc))();
      if (cVar8 == '\0') {
        *param_2 = local_14;
        param_2[1] = uStack_10;
        param_2[2] = uStack_c;
        param_2[3] = uStack_8;
        cVar8 = '\x01';
        param_2[4] = uStack_4;
        iVar9 = iVar7;
      }
      else if (iVar9 < iVar7) {
        *param_2 = local_14;
        param_2[1] = uStack_10;
        param_2[2] = uStack_c;
        param_2[3] = uStack_8;
        param_2[4] = uStack_4;
        iVar9 = iVar7;
      }
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar6 = *(char *)((int)*puVar4 + 0x15);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar6 == '\0') {
          cVar6 = *(char *)((int)*puVar4 + 0x15);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar6 = *(char *)((int)puVar2[1] + 0x15);
        puVar5 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar5, cVar6 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar6 = *(char *)((int)puVar2[1] + 0x15);
          puVar5 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  return cVar8;
}


// ==== FUN_0058ced0 @ 0x0058ced0 ====

undefined4 FUN_0058ced0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_0058cf00 @ 0x0058cf00 ====

undefined4 FUN_0058cf00(undefined1 param_1)

{
  uint in_ECX;
  uint local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(uint *)(in_ECX + 8)) {
    return 0;
  }
  FUN_0058d0c0(&param_1,local_4);
  return 1;
}


// ==== FUN_0058cf40 @ 0x0058cf40 ====

undefined4 FUN_0058cf40(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = param_1;
  uVar2 = (**(code **)(*param_1 + 8))();
  param_1 = (int *)uVar2;
  piVar3 = (int *)FUN_0079bba0(&uStack_10,&param_1);
  if (*piVar3 == *(int *)(in_ECX + 8)) {
    piStack_c = piVar1;
    uStack_10 = uVar2;
    FUN_0058d610(auStack_8,&uStack_10);
    return 1;
  }
  return 0;
}


// ==== FUN_0058cfb0 @ 0x0058cfb0 ====

void FUN_0058cfb0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00982378;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bea1c;
  DAT_00b5a724 = 0;
  local_4 = 0;
  FUN_0058d550(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0058d030 @ 0x0058d030 ====

void FUN_0058d030(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098238a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bea1c;
  iVar1 = FUN_0058d7c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a724 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a724 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0058d0c0 @ 0x0058d0c0 ====

/* WARNING: Removing unreachable block (ram,0x0058d1d3) */
/* WARNING: Removing unreachable block (ram,0x0058d1e3) */
/* WARNING: Removing unreachable block (ram,0x0058d1ec) */
/* WARNING: Removing unreachable block (ram,0x0058d1ef) */
/* WARNING: Removing unreachable block (ram,0x0058d1df) */
/* WARNING: Removing unreachable block (ram,0x0058d1fd) */
/* WARNING: Removing unreachable block (ram,0x0058d20a) */
/* WARNING: Removing unreachable block (ram,0x0058d215) */
/* WARNING: Removing unreachable block (ram,0x0058d211) */
/* WARNING: Removing unreachable block (ram,0x0058d205) */
/* WARNING: Removing unreachable block (ram,0x0058d218) */

void FUN_0058d0c0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00982358;
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
            goto LAB_0058d2e5;
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
LAB_0058d2e5:
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


// ==== FUN_0058d370 @ 0x0058d370 ====

void FUN_0058d370(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00982358;
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
LAB_0058d469:
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
      if ((char)piVar6[5] == '\0') goto LAB_0058d469;
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


// ==== FUN_0058d550 @ 0x0058d550 ====

void FUN_0058d550(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0058cd90(piVar6[1]);
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
    FUN_0058d0c0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0058d610 @ 0x0058d610 ====

void FUN_0058d610(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_0058d370(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0058d370(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0058d6d0 @ 0x0058d6d0 ====

void FUN_0058d6d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0058cfb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058d6f0 @ 0x0058d6f0 ====

void FUN_0058d6f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bea74;
  return;
}


// ==== FUN_0058d700 @ 0x0058d700 ====

void FUN_0058d700(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bea74;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058d720 @ 0x0058d720 ====

void FUN_0058d720(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x15) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x15) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x15);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x15);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x15) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x15) == '\0');
    if (*(char *)((int)piVar4 + 0x15) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0058d780 @ 0x0058d780 ====

void FUN_0058d780(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0058d780(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0058d7c0 @ 0x0058d7c0 ====

void FUN_0058d7c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 5) = 1;
  *(undefined1 *)((int)puVar1 + 0x15) = 0;
  return;
}


// ==== FUN_0058d800 @ 0x0058d800 ====

char FUN_0058d800(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  char cVar8;
  int in_ECX;
  char cVar9;
  float local_1c;
  undefined4 local_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  cVar9 = '\0';
  local_1c = 0.0;
  while (puVar2 != puVar1) {
    cVar8 = (**(code **)(*(int *)puVar2[4] + 4))(param_1,&local_14);
    if (cVar8 != '\0') {
      if (cVar9 == '\0') {
        *param_2 = local_14;
        param_2[1] = uStack_10;
        param_2[2] = fStack_c;
        param_2[3] = fStack_8;
        param_2[4] = fStack_4;
        fVar4 = (float)param_2[2] - *(float *)(param_1 + 0xc);
        cVar9 = '\x01';
        fVar6 = (float)param_2[3] - *(float *)(param_1 + 0x10);
        fVar5 = (float)param_2[4] - *(float *)(param_1 + 0x14);
        local_1c = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);
      }
      else {
        fVar4 = fStack_c - *(float *)(param_1 + 0xc);
        fVar6 = fStack_8 - *(float *)(param_1 + 0x10);
        fVar5 = fStack_4 - *(float *)(param_1 + 0x14);
        fVar4 = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);
        if (fVar4 < local_1c) {
          *param_2 = local_14;
          param_2[1] = uStack_10;
          param_2[2] = fStack_c;
          param_2[3] = fStack_8;
          param_2[4] = fStack_4;
          local_1c = fVar4;
        }
      }
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar8 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar8 == '\0') {
          cVar8 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar8 = *(char *)((int)puVar2[1] + 0x15);
        puVar7 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar7, cVar8 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar8 = *(char *)((int)puVar2[1] + 0x15);
          puVar7 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return cVar9;
}


// ==== FUN_0058d970 @ 0x0058d970 ====

undefined4 FUN_0058d970(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_0058d9a0 @ 0x0058d9a0 ====

undefined4 FUN_0058d9a0(undefined1 param_1)

{
  uint in_ECX;
  uint local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(uint *)(in_ECX + 8)) {
    return 0;
  }
  FUN_0058db60(&param_1,local_4);
  return 1;
}


// ==== FUN_0058d9e0 @ 0x0058d9e0 ====

undefined4 FUN_0058d9e0(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = param_1;
  uVar2 = (**(code **)(*param_1 + 0x18))();
  param_1 = (int *)uVar2;
  piVar3 = (int *)FUN_0079bba0(&uStack_10,&param_1);
  if (*piVar3 == *(int *)(in_ECX + 8)) {
    piStack_c = piVar1;
    uStack_10 = uVar2;
    FUN_0058e0b0(auStack_8,&uStack_10);
    return 1;
  }
  return 0;
}


// ==== FUN_0058da50 @ 0x0058da50 ====

void FUN_0058da50(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009823c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bea8c;
  DAT_00b5a728 = 0;
  local_4 = 0;
  FUN_0058dff0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0058dad0 @ 0x0058dad0 ====

void FUN_0058dad0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009823da;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bea8c;
  iVar1 = FUN_0058d7c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a728 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a728 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0058db60 @ 0x0058db60 ====

/* WARNING: Removing unreachable block (ram,0x0058dc73) */
/* WARNING: Removing unreachable block (ram,0x0058dc83) */
/* WARNING: Removing unreachable block (ram,0x0058dc8c) */
/* WARNING: Removing unreachable block (ram,0x0058dc8f) */
/* WARNING: Removing unreachable block (ram,0x0058dc7f) */
/* WARNING: Removing unreachable block (ram,0x0058dc9d) */
/* WARNING: Removing unreachable block (ram,0x0058dcaa) */
/* WARNING: Removing unreachable block (ram,0x0058dcb5) */
/* WARNING: Removing unreachable block (ram,0x0058dcb1) */
/* WARNING: Removing unreachable block (ram,0x0058dca5) */
/* WARNING: Removing unreachable block (ram,0x0058dcb8) */

void FUN_0058db60(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009823a8;
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
            goto LAB_0058dd85;
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
LAB_0058dd85:
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


// ==== FUN_0058de10 @ 0x0058de10 ====

void FUN_0058de10(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009823a8;
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
LAB_0058df09:
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
      if ((char)piVar6[5] == '\0') goto LAB_0058df09;
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


// ==== FUN_0058dff0 @ 0x0058dff0 ====

void FUN_0058dff0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0058d780(piVar6[1]);
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
    FUN_0058db60(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0058e0b0 @ 0x0058e0b0 ====

void FUN_0058e0b0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_0058de10(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0058de10(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0058e170 @ 0x0058e170 ====

void FUN_0058e170(byte param_1)

{
  void *in_ECX;
  
  FUN_0058da50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058e190 @ 0x0058e190 ====

void FUN_0058e190(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0058e190(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0058e1d0 @ 0x0058e1d0 ====

bool FUN_0058e1d0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x14) == 0;
}


// ==== FUN_0058e1e0 @ 0x0058e1e0 ====

char FUN_0058e1e0(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined4 *puVar6;
  int in_ECX;
  char cVar7;
  float local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  cVar7 = '\0';
  local_18 = 0.0;
  if (*param_1 == 2) {
    puVar6 = *(undefined4 **)(in_ECX + 0x1c);
  }
  else {
    puVar6 = *(undefined4 **)(in_ECX + 0x10);
  }
  puVar1 = (undefined4 *)*puVar6;
  while (puVar1 != puVar6) {
    cVar5 = (**(code **)(*(int *)puVar1[4] + 0x18))(param_1,&local_14);
    if (cVar5 != '\0') {
      if (cVar7 == '\0') {
        *param_2 = local_14;
        param_2[1] = uStack_10;
        param_2[2] = fStack_c;
        param_2[3] = fStack_8;
        param_2[4] = fStack_4;
        cVar7 = '\x01';
        local_18 = SQRT(((float)param_2[2] - (float)param_1[3]) *
                        ((float)param_2[2] - (float)param_1[3]) +
                        ((float)param_2[3] - (float)param_1[4]) *
                        ((float)param_2[3] - (float)param_1[4]) +
                        ((float)param_2[4] - (float)param_1[5]) *
                        ((float)param_2[4] - (float)param_1[5]));
      }
      else {
        fVar3 = SQRT((fStack_c - (float)param_1[3]) * (fStack_c - (float)param_1[3]) +
                     (fStack_8 - (float)param_1[4]) * (fStack_8 - (float)param_1[4]) +
                     (fStack_4 - (float)param_1[5]) * (fStack_4 - (float)param_1[5]));
        if (fVar3 < local_18) {
          *param_2 = local_14;
          param_2[1] = uStack_10;
          param_2[2] = fStack_c;
          param_2[3] = fStack_8;
          param_2[4] = fStack_4;
          local_18 = fVar3;
        }
      }
    }
    if (*(char *)((int)puVar1 + 0x15) == '\0') {
      puVar2 = (undefined4 *)puVar1[2];
      if (*(char *)((int)puVar2 + 0x15) == '\0') {
        cVar5 = *(char *)((int)*puVar2 + 0x15);
        puVar1 = puVar2;
        puVar2 = (undefined4 *)*puVar2;
        while (cVar5 == '\0') {
          cVar5 = *(char *)((int)*puVar2 + 0x15);
          puVar1 = puVar2;
          puVar2 = (undefined4 *)*puVar2;
        }
      }
      else {
        cVar5 = *(char *)((int)puVar1[1] + 0x15);
        puVar4 = (undefined4 *)puVar1[1];
        puVar2 = puVar1;
        while ((puVar1 = puVar4, cVar5 == '\0' && (puVar2 == (undefined4 *)puVar1[2]))) {
          cVar5 = *(char *)((int)puVar1[1] + 0x15);
          puVar4 = (undefined4 *)puVar1[1];
          puVar2 = puVar1;
        }
      }
    }
  }
  return cVar7;
}


// ==== FUN_0058e350 @ 0x0058e350 ====

undefined4 FUN_0058e350(float param_1,float *param_2)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  int *piVar4;
  char cVar5;
  int in_ECX;
  int *piVar6;
  float local_4;
  
  fVar3 = param_1;
  piVar1 = *(int **)(in_ECX + 0x1c);
  piVar6 = (int *)*piVar1;
  local_4 = DAT_009beae0;
  if (piVar6 != piVar1) {
    do {
      cVar5 = (**(code **)(*(int *)piVar6[4] + 0x1c))(fVar3,&param_1);
      if ((cVar5 != '\0') && (local_4 < param_1)) {
        local_4 = param_1;
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar5 = *(char *)(*piVar2 + 0x15);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar5 == '\0') {
            cVar5 = *(char *)(*piVar2 + 0x15);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar5 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar4, cVar5 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar5 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != piVar1);
    if (DAT_009beae0 < local_4) {
      *param_2 = local_4;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0058e410 @ 0x0058e410 ====

undefined4 FUN_0058e410(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char cVar6;
  int in_ECX;
  
  uVar4 = param_1;
  puVar1 = *(undefined4 **)(in_ECX + 0x1c);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar6 = (**(code **)(*(int *)puVar2[4] + 0x20))(uVar4,&param_1);
    if (cVar6 != '\0') break;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar6 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar6 == '\0') {
          cVar6 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar6 = *(char *)((int)puVar2[1] + 0x15);
        puVar5 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar5, cVar6 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar6 = *(char *)((int)puVar2[1] + 0x15);
          puVar5 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  *param_2 = param_1;
  return 1;
}


// ==== FUN_0058e4d0 @ 0x0058e4d0 ====

undefined4 FUN_0058e4d0(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  FUN_0058e720(&local_4,local_4);
  piVar1 = (int *)FUN_0079bba0((int)register0x00000010 + -0xc,&local_4);
  if (*piVar1 != *(int *)(in_ECX + 0x1c)) {
    FUN_0058e720(&local_4,*piVar1);
  }
  return 1;
}


// ==== FUN_0058e540 @ 0x0058e540 ====

undefined4 FUN_0058e540(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = param_1;
  uVar3 = (**(code **)(*param_1 + 4))();
  param_1 = (int *)uVar3;
  piVar4 = (int *)FUN_0079bba0(&uStack_10,&param_1);
  if (*piVar4 != *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  piStack_c = piVar1;
  uStack_10 = uVar3;
  FUN_0058ec70(auStack_8,&uStack_10);
  cVar2 = (**(code **)(*piVar1 + 8))();
  if (cVar2 != '\0') {
    piStack_c = piVar1;
    uStack_10 = uVar3;
    FUN_0058ec70(auStack_8,&uStack_10);
  }
  return 1;
}


// ==== FUN_0058e5d0 @ 0x0058e5d0 ====

void FUN_0058e5d0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098241b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009beae8;
  local_4 = 0;
  FUN_0058ebb0(local_10,*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_0058e670 @ 0x0058e670 ====

void FUN_0058e670(undefined4 *param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00982430;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009beae8;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[1];
  iVar1 = FUN_0058d7c0();
  in_ECX[4] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  local_4 = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[7] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
  *(undefined4 *)in_ECX[7] = in_ECX[7];
  *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  in_ECX[8] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0058e720 @ 0x0058e720 ====

/* WARNING: Removing unreachable block (ram,0x0058e833) */
/* WARNING: Removing unreachable block (ram,0x0058e843) */
/* WARNING: Removing unreachable block (ram,0x0058e84c) */
/* WARNING: Removing unreachable block (ram,0x0058e84f) */
/* WARNING: Removing unreachable block (ram,0x0058e83f) */
/* WARNING: Removing unreachable block (ram,0x0058e85d) */
/* WARNING: Removing unreachable block (ram,0x0058e86a) */
/* WARNING: Removing unreachable block (ram,0x0058e875) */
/* WARNING: Removing unreachable block (ram,0x0058e871) */
/* WARNING: Removing unreachable block (ram,0x0058e865) */
/* WARNING: Removing unreachable block (ram,0x0058e878) */

void FUN_0058e720(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009823f8;
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
            goto LAB_0058e945;
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
LAB_0058e945:
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


// ==== FUN_0058e9d0 @ 0x0058e9d0 ====

void FUN_0058e9d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009823f8;
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
LAB_0058eac9:
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
      if ((char)piVar6[5] == '\0') goto LAB_0058eac9;
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


// ==== FUN_0058ebb0 @ 0x0058ebb0 ====

void FUN_0058ebb0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0058e190(piVar6[1]);
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
    FUN_0058e720(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0058ec70 @ 0x0058ec70 ====

void FUN_0058ec70(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_0058e9d0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0058e9d0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0058ed30 @ 0x0058ed30 ====

void FUN_0058ed30(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0058ebb0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0058ed60 @ 0x0058ed60 ====

void FUN_0058ed60(byte param_1)

{
  void *in_ECX;
  
  FUN_0058e5d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058ed80 @ 0x0058ed80 ====

undefined4 FUN_0058ed80(void)

{
  return 2;
}


// ==== FUN_0058ed90 @ 0x0058ed90 ====

void FUN_0058ed90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beaf0;
  return;
}


// ==== FUN_0058edb0 @ 0x0058edb0 ====

undefined4 FUN_0058edb0(void)

{
  return 0x21;
}


// ==== FUN_0058edc0 @ 0x0058edc0 ====

void FUN_0058edc0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009beafc;
  in_ECX[2] = 0;
  in_ECX[3] = 0x20;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0058ee00 @ 0x0058ee00 ====

undefined4 FUN_0058ee00(void)

{
  return 0x10;
}


// ==== FUN_0058ee10 @ 0x0058ee10 ====

undefined4 FUN_0058ee10(void)

{
  return 0x11;
}


// ==== FUN_0058ee20 @ 0x0058ee20 ====

void FUN_0058ee20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb08;
  return;
}


// ==== FUN_0058ee40 @ 0x0058ee40 ====

void FUN_0058ee40(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb14;
  in_ECX[1] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[2] = DAT_0099d080;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  in_ECX[5] = uVar1;
  return;
}


// ==== FUN_0058ee80 @ 0x0058ee80 ====

undefined4 FUN_0058ee80(void)

{
  return 0x20;
}


// ==== FUN_0058eea0 @ 0x0058eea0 ====

void FUN_0058eea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb20;
  in_ECX[2] = 0;
  in_ECX[3] = 0x20;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0058eec0 @ 0x0058eec0 ====

void FUN_0058eec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb2c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0058eef0 @ 0x0058eef0 ====

void FUN_0058eef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb2c;
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
    *in_ECX = &PTR_FUN_009b655c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0058ef50 @ 0x0058ef50 ====

undefined4 FUN_0058ef50(void)

{
  return 0x60;
}


// ==== FUN_0058ef60 @ 0x0058ef60 ====

void FUN_0058ef60(byte param_1)

{
  void *in_ECX;
  
  FUN_0058eef0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058ef80 @ 0x0058ef80 ====

undefined4 FUN_0058ef80(void)

{
  return 0x41;
}


// ==== FUN_0058ef90 @ 0x0058ef90 ====

void FUN_0058ef90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb38;
  return;
}


// ==== FUN_0058efb0 @ 0x0058efb0 ====

undefined4 FUN_0058efb0(void)

{
  return 0x31;
}


// ==== FUN_0058efc0 @ 0x0058efc0 ====

undefined4 FUN_0058efc0(void)

{
  return 0x30;
}


// ==== FUN_0058efd0 @ 0x0058efd0 ====

void FUN_0058efd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb48;
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
    *in_ECX = &PTR_FUN_009b655c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0058f030 @ 0x0058f030 ====

void FUN_0058f030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb48;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401740(&DAT_009beb42,0);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401740(&DAT_009beb43,0);
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0x11;
  *(undefined2 *)(in_ECX + 0x13) = 0;
  FUN_00403ea0(in_ECX + 0x12,0,8);
  return;
}


// ==== FUN_0058f0a0 @ 0x0058f0a0 ====

void FUN_0058f0a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5,undefined4 param_6)

{
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x3c) = param_3;
  *(undefined4 *)(in_ECX + 0x48) = *param_4;
  *(undefined4 *)(in_ECX + 0x4c) = param_4[1];
  *(undefined1 *)(in_ECX + 0x40) = param_5;
  *(undefined4 *)(in_ECX + 0x44) = param_6;
  return;
}


// ==== FUN_0058f100 @ 0x0058f100 ====

void FUN_0058f100(byte param_1)

{
  void *in_ECX;
  
  FUN_0058efd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f120 @ 0x0058f120 ====

undefined4 FUN_0058f120(void)

{
  return 0x40;
}


// ==== FUN_0058f130 @ 0x0058f130 ====

void FUN_0058f130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb54;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  return;
}


// ==== FUN_0058f150 @ 0x0058f150 ====

void FUN_0058f150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb54;
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_009b655c;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_0058f190 @ 0x0058f190 ====

void FUN_0058f190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb54;
  if (0xf < (uint)in_ECX[10]) {
    _free((void *)in_ECX[5]);
    return;
  }
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *in_ECX = &PTR_FUN_009b655c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f1e0 @ 0x0058f1e0 ====

undefined4 FUN_0058f1e0(void)

{
  return 1;
}


// ==== FUN_0058f1f0 @ 0x0058f1f0 ====

void FUN_0058f1f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb60;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0058f230 @ 0x0058f230 ====

void FUN_0058f230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb60;
  if (in_ECX[10] != 0) {
    FUN_004ff020(in_ECX[10],in_ECX[0xb],in_ECX + 9);
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009b655c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0058f2a0 @ 0x0058f2a0 ====

void FUN_0058f2a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0058f230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f2c0 @ 0x0058f2c0 ====

undefined4 FUN_0058f2c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    FUN_0058f4e0();
    return 0;
  }
  uVar2 = FUN_0058f310();
  FUN_0058f4e0();
  return uVar2;
}


// ==== FUN_0058f2f0 @ 0x0058f2f0 ====

void FUN_0058f2f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beb90;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f310 @ 0x0058f310 ====

void FUN_0058f310(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beba0;
  in_ECX[1] = 0;
  uVar1 = FUN_0084d880();
  in_ECX[2] = uVar1;
  return;
}


// ==== FUN_0058f330 @ 0x0058f330 ====

void FUN_0058f330(void)

{
  int in_ECX;
  
  FUN_0058f9c0();
  FUN_0058f7a0();
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0058f370 @ 0x0058f370 ====

void FUN_0058f370(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a988 + 8))();
  (**(code **)(*DAT_00b5afac + 0x14))();
  (**(code **)(**(int **)(in_ECX + 8) + 4))();
  (**(code **)(*DAT_00b5afac + 0x18))(*(undefined4 *)(in_ECX + 8));
  (**(code **)(*DAT_00b5afa8 + 8))(*(undefined4 *)(in_ECX + 8));
  (**(code **)(*DAT_00b5a9d0 + 0xc))(*(undefined4 *)(in_ECX + 8));
                    /* WARNING: Could not recover jumptable at 0x0058f3c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a9d0 + 0x10))();
  return;
}


// ==== FUN_0058f3d0 @ 0x0058f3d0 ====

bool FUN_0058f3d0(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if ((uVar2 & 0xffff0000) == 0x50000) {
    return false;
  }
  cVar1 = (**(code **)(*DAT_00b5afb4 + 8))(param_1);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5afc0 + 4))(param_1);
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(*DAT_00b5afa4 + 4))(param_1);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*DAT_00b5afcc + 4))(param_1);
        if (cVar1 == '\0') {
          cVar1 = (**(code **)(*DAT_00b5a988 + 4))(param_1);
          if (cVar1 == '\0') {
            cVar1 = (**(code **)(*DAT_00b5afb0 + 4))(param_1);
            if (cVar1 == '\0') {
              cVar1 = (**(code **)(*DAT_00b5afa8 + 4))(param_1);
              if (cVar1 == '\0') {
                cVar1 = (**(code **)(*DAT_00b5a9d0 + 0x18))(param_1);
                if (cVar1 == '\0') {
                  cVar1 = (**(code **)(*DAT_00b5af48 + 4))(param_1);
                  return cVar1 != '\0';
                }
              }
            }
          }
        }
      }
    }
  }
  return true;
}


// ==== FUN_0058f490 @ 0x0058f490 ====

void FUN_0058f490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beba0;
  FUN_0058f9c0();
  FUN_0058f7a0();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009beb90;
  return;
}


// ==== FUN_0058f4e0 @ 0x0058f4e0 ====

void FUN_0058f4e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005920f0();
  }
  *(undefined4 *)(in_ECX + 4) = uVar2;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(&DAT_009beb6c,1);
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_setmovement_009beb70,0xb);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar3 + 0x10))(local_38,local_1c);
  if (0xf < uStack_28) {
    _free(unaff_EBX);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  if (uStack_c < 0x10) {
    FUN_00590ce0();
    FUN_0058f8d0();
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_0058f5b0 @ 0x0058f5b0 ====

void FUN_0058f5b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009beba0;
  FUN_0058f9c0();
  FUN_0058f7a0();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009beb90;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f610 @ 0x0058f610 ====

void FUN_0058f610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bebb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f630 @ 0x0058f630 ====

undefined4 FUN_0058f630(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x60100001) {
    *(int *)(in_ECX + 0xf8) = param_1[1];
    iVar2 = param_1[2];
    *(int *)(in_ECX + 0xfc) = iVar2;
    *(int *)(in_ECX + 0x100) = param_1[3];
    iVar1 = param_1[4];
    *(char *)(in_ECX + 0xf4) = (char)iVar1;
    (**(code **)(*DAT_00b5a988 + 0x38))(CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar1));
    return 1;
  }
  return 0;
}


// ==== FUN_0058f690 @ 0x0058f690 ====

void FUN_0058f690(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  
  iVar6 = (**(code **)(*DAT_00b5af48 + 8))();
  fVar1 = *(float *)(iVar6 + 8);
  fVar2 = *(float *)(iVar6 + 0xc);
  fVar3 = *(float *)(iVar6 + 0x10);
  uVar4 = *(undefined4 *)(iVar6 + 0x14);
  *(float *)(in_ECX + 0x10) = *(float *)(in_ECX + 0xf8);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0xfc);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x100);
  *(float *)(in_ECX + 0x14) = fVar1 + *(float *)(in_ECX + 0x14);
  uVar5 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x2c) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  *(undefined4 *)(in_ECX + 0x30) = DAT_009bac80;
  *(undefined4 *)(in_ECX + 0x20) = uVar5;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(float *)(in_ECX + 4) = *(float *)(in_ECX + 0x10) + fVar2;
  *(float *)(in_ECX + 8) = *(float *)(in_ECX + 0x14) + fVar2 * fVar3;
  *(float *)(in_ECX + 0xc) = *(float *)(in_ECX + 0x18) + fVar2 * 0.0;
  return;
}


// ==== FUN_0058f7a0 @ 0x0058f7a0 ====

void FUN_0058f7a0(void)

{
  if (DAT_00b5afa8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afa8)(1);
  }
  return;
}


// ==== FUN_0058f810 @ 0x0058f810 ====

void FUN_0058f810(int *param_1)

{
  int in_ECX;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  
  local_f8 = CONCAT31(local_f8._1_3_,*(undefined1 *)(in_ECX + 0xf4));
  (**(code **)(*param_1 + 0x60))(&local_f8);
  if (*(char *)(in_ECX + 0xf4) != '\0') {
    FUN_0058f690();
    uStack_d4 = *(undefined4 *)(in_ECX + 0x28);
    local_f8 = *(undefined4 *)(in_ECX + 4);
    uStack_f4 = *(undefined4 *)(in_ECX + 8);
    uStack_f0 = *(undefined4 *)(in_ECX + 0xc);
    uStack_ec = *(undefined4 *)(in_ECX + 0x10);
    uStack_e8 = *(undefined4 *)(in_ECX + 0x14);
    uStack_e4 = *(undefined4 *)(in_ECX + 0x18);
    uStack_e0 = *(undefined4 *)(in_ECX + 0x1c);
    uStack_dc = *(undefined4 *)(in_ECX + 0x20);
    uStack_d8 = *(undefined4 *)(in_ECX + 0x24);
    uStack_d0 = *(undefined4 *)(in_ECX + 0x2c);
    uStack_cc = *(undefined4 *)(in_ECX + 0x30);
    (**(code **)(*param_1 + 0x10c))(&local_f8);
  }
  return;
}


// ==== FUN_0058f8d0 @ 0x0058f8d0 ====

void FUN_0058f8d0(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5afa8 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x104);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009bebc4;
      if (puVar1 != (undefined4 *)0xfffffffc) {
        DAT_00b5afa8 = puVar1;
        *(undefined1 *)(puVar1 + 0x3d) = 0;
        return;
      }
      DAT_00b5afa8 = (undefined4 *)0x0;
      uRam000000f0 = 0;
    }
  }
  return;
}


// ==== FUN_0058f920 @ 0x0058f920 ====

void FUN_0058f920(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 4);
  param_1[1] = *(undefined4 *)(in_ECX + 8);
  param_1[2] = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_0058f940 @ 0x0058f940 ====

void FUN_0058f940(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afa8 = 0;
  *in_ECX = &PTR_FUN_009bebb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f970 @ 0x0058f970 ====

void FUN_0058f970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf3bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0058f990 @ 0x0058f990 ====

void FUN_0058f990(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  *(undefined4 *)(in_ECX + 0x10) = param_2;
  *(undefined4 *)(in_ECX + 0x14) = param_3;
  return;
}


// ==== FUN_0058f9c0 @ 0x0058f9c0 ====

void FUN_0058f9c0(void)

{
  if (DAT_00b5af48 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af48)(1);
  }
  return;
}


// ==== FUN_0058f9e0 @ 0x0058f9e0 ====

/* WARNING: Removing unreachable block (ram,0x00590116) */
/* WARNING: Removing unreachable block (ram,0x00590157) */
/* WARNING: Removing unreachable block (ram,0x00590037) */
/* WARNING: Removing unreachable block (ram,0x0058fd90) */
/* WARNING: Removing unreachable block (ram,0x0058fccf) */

void FUN_0058f9e0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_ESI;
  uint unaff_EDI;
  uint **ppuStack_15c;
  void *pvStack_158;
  undefined4 uStack_154;
  int iStack_14c;
  undefined4 uStack_140;
  uint *_Memory;
  char **ppcStack_138;
  undefined4 uStack_134;
  undefined4 *_Memory_00;
  uint uStack_128;
  char **ppcStack_120;
  undefined4 uStack_11c;
  uint **_Memory_01;
  uint uVar2;
  char *pcStack_10c;
  char **ppcStack_104;
  char *pcStack_100;
  char *pcStack_f4;
  char *pcStack_e8;
  undefined4 *puStack_e0;
  undefined4 uStack_dc;
  undefined4 ***_Memory_02;
  undefined4 uStack_c4;
  char **_Memory_03;
  uint uVar3;
  char **ppcStack_b4;
  uint uVar4;
  uint uVar5;
  undefined4 ***pppuStack_9c;
  char *pcStack_90;
  undefined4 ***pppuStack_80;
  char *pcStack_78;
  char **ppcStack_68;
  void *pvVar6;
  void *_Memory_04;
  undefined4 uStack_60;
  void *pvVar7;
  void *pvVar8;
  char *pcStack_50;
  undefined4 uStack_4c;
  undefined4 local_38;
  uint local_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  
  *in_ECX = &PTR_FUN_009bf3fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af48 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5af48 = in_ECX;
  }
  uStack_4c = (void *)0x6;
  pcStack_50 = s_ds_lod_009bebd8;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  FUN_00401740();
  uStack_4c = (void *)0x1;
  pcStack_50 = (char *)&local_38;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_28) {
    _free(unaff_EBX);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  FUN_00401740();
  pvVar8 = (void *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_30) {
    uStack_60 = (char *)0x58fa92;
    _free(unaff_ESI);
    return;
  }
  uStack_60 = s_ds_fov_009bebec;
  uStack_30 = 0xf;
  local_34 = 0;
  FUN_00401740();
  pvVar7 = (void *)0x1;
  uStack_60 = (char *)((int)register0x00000010 - 0x48);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_38) {
    ppcStack_68 = (char **)0x58fad3;
    _free(uStack_4c);
    return;
  }
  ppcStack_68 = (char **)s_ds_znear_009bebf4;
  local_38 = 0xf;
  uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
  FUN_00401740();
  pvVar6 = (void *)0x1;
  ppcStack_68 = &pcStack_50;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_EBP) {
    _free(pvVar8);
    return;
  }
  FUN_00401740();
  pvVar8 = (void *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_EDI) {
    pcStack_78 = (char *)0x58fb55;
    _free(pvVar7);
    return;
  }
  pcStack_78 = s_ds_clipfar_009bec08;
  uStack_4c = (void *)0x0;
  FUN_00401740();
  pvVar7 = (void *)0x1;
  pcStack_78 = (char *)&uStack_60;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char *)0xf < pcStack_50) {
    pppuStack_80 = (undefined4 ***)0x58fb96;
    _free(pvVar6);
    return;
  }
  pppuStack_80 = (undefined4 ***)s_ds_frustum_009bec14;
  pcStack_50 = (char *)0xf;
  FUN_00401740();
  pvVar6 = (void *)0x1;
  pppuStack_80 = (undefined4 ***)&ppcStack_68;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < (int)register0x00000010 - 0x40U) {
    _free(pvVar8);
    return;
  }
  uVar5 = (uint)pvVar8 & 0xffffff00;
  FUN_00401740();
  uVar2 = 0;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_60) {
    pcStack_90 = (char *)0x58fc17;
    _free(pvVar7);
    return;
  }
  pcStack_90 = s__min___max__009bec30;
  FUN_00401740();
  pcStack_90 = s_3dcamera_distance_009bec3c;
  uStack_60 = (char *)0xf;
  _Memory_04 = (void *)0x0;
  pvVar7 = (void *)((uint)pvVar7 & 0xffffff00);
  FUN_00401740();
  pvVar8 = (void *)((int)register0x00000010 + -0x5c);
  pcStack_90 = (char *)0x2;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uVar5) {
    pppuStack_9c = (undefined4 ***)0x58fc79;
    _free(pppuStack_80);
    return;
  }
  pppuStack_80 = (undefined4 ***)((uint)pppuStack_80 & 0xffffff00);
  if ((char *)0xf < pcStack_50) {
    pppuStack_9c = (undefined4 ***)0x58fc98;
    _free(_Memory_04);
    return;
  }
  pppuStack_9c = (undefined4 ***)s_3dcamera_culldistance_009bec50;
  pcStack_50 = (char *)0xf;
  FUN_00401740();
  pppuStack_9c = (undefined4 ***)&ppcStack_68;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  FUN_00401740();
  uVar5 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_60) {
    _free(pvVar7);
    return;
  }
  uStack_60 = (char *)0xf;
  FUN_00401740();
  uVar4 = 0;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char **)0xf < ppcStack_68) {
    _free(pvVar6);
    return;
  }
  ppcStack_68 = (char **)0xf;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  uVar2 = uVar2 & 0xffffff00;
  FUN_00401740();
  uVar3 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char *)0xf < pcStack_78) {
    uStack_c4 = (char *)0x58fddb;
    _free(pvVar8);
    return;
  }
  uStack_c4 = s__id___doll___effectid__009beca8;
  pcStack_78 = (char *)0xf;
  FUN_00401740();
  uStack_c4 = s_effectreg_009becc0;
  pvVar8 = (void *)0x0;
  uVar4 = uVar4 & 0xffffff00;
  FUN_00401740();
  _Memory_03 = &pcStack_90;
  uStack_c4 = (char *)0x3;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uVar5) {
    _free(&pppuStack_80);
    return;
  }
  ppcStack_b4 = &pcStack_100;
  if (0xf < uVar2) {
    _free(pvVar8);
    return;
  }
  FUN_00401740();
  FUN_00401740();
  _Memory_02 = &pppuStack_9c;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((char **)0xf < &pcStack_78) {
    uStack_dc = (char *)0x58febe;
    _free(_Memory_03);
    return;
  }
  uVar2 = (uint)_Memory_03 & 0xffffff00;
  if ((char *)0xf < pcStack_90) {
    uStack_dc = (char *)0x58fedd;
    _free((void *)0x0);
    return;
  }
  uStack_dc = s__id___doll___effectid___scene____009bed00;
  pcStack_90 = (char *)0xf;
  puStack_e0 = (undefined4 *)0x58fefc;
  FUN_00401740();
  uStack_dc = s_effectregplay_009bed34;
  pvVar7 = (void *)0x0;
  uVar2 = uVar2 & 0xffffff00;
  puStack_e0 = (undefined4 *)0x58ff18;
  FUN_00401740();
  pvVar8 = (void *)((int)register0x00000010 + -0xa8);
  uStack_dc = (char *)0x6;
  puStack_e0 = &uStack_c4;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uVar3) {
    pcStack_e8 = (char *)0x58ff3f;
    _free(_Memory_02);
    return;
  }
  if ((undefined4 ***)0xf < pppuStack_9c) {
    pcStack_e8 = (char *)0x58ff5e;
    _free(pvVar7);
    return;
  }
  pcStack_e8 = s__id___scene___start___lifetime____009bed44;
  pppuStack_9c = (undefined4 ***)0xf;
  FUN_00401740();
  pcStack_e8 = s_effectplayp2p_009bed84;
  FUN_00401740();
  pcStack_e8 = (char *)0xb;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_c4) {
    pcStack_f4 = (char *)0x58ffc0;
    _free(pvVar8);
    return;
  }
  uStack_c4 = (char *)0xf;
  if (0xf < uVar4) {
    pcStack_f4 = (char *)0x58ffdf;
    _free((void *)0x0);
    return;
  }
  pcStack_f4 = s__id___scene___start___lifetime____009bed94;
  FUN_00401740();
  pcStack_f4 = s_effectplayp2d_009bedd4;
  uStack_c4 = (char *)0xf;
  FUN_00401740();
  pvVar8 = (void *)((int)register0x00000010 + -0xc0);
  pcStack_f4 = (char *)0x9;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((char **)0xf < ppcStack_b4) {
    pcStack_100 = (char *)0x590060;
    _free((void *)0x0);
    return;
  }
  pcStack_100 = &DAT_009bede2;
  ppcStack_104 = (char **)0x59007e;
  FUN_00401740();
  pcStack_100 = s_refresh_effect_009bede4;
  ppcStack_104 = (char **)0x59009a;
  FUN_00401740();
  pvVar7 = (void *)((int)register0x00000010 + -0xcc);
  pcStack_100 = (char *)0x0;
  ppcStack_104 = &pcStack_e8;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_dc) {
    pcStack_10c = (char *)0x5900c0;
    _free(pvVar8);
    return;
  }
  uStack_dc = (char *)0xf;
  puStack_e0 = (undefined4 *)0x0;
  pvVar8 = (void *)((uint)pvVar8 & 0xffffff00);
  if (0xf < uVar2) {
    pcStack_10c = (char *)0x5900df;
    _free((void *)0x0);
    return;
  }
  pcStack_10c = s_camera_export_009bedf4;
  uStack_c4 = (char *)0x0;
  FUN_00401740();
  pvVar6 = (void *)0x1;
  pcStack_10c = (char *)((int)register0x00000010 + -0xd8);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  uStack_dc = (char *)((uint)uStack_dc & 0xffffff00);
  FUN_00401740();
  uVar2 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  uStack_11c = (void *)0x590172;
  FUN_00401830();
  uStack_11c = (void *)0x590180;
  FUN_00401830();
  _Memory_01 = (uint **)&ppcStack_104;
  uStack_11c = (void *)0x3;
  ppcStack_120 = &pcStack_e8;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_dc) {
    uStack_128 = 0x5901a7;
    _free(pvVar8);
    return;
  }
  uStack_dc = (char *)0xf;
  puStack_e0 = (undefined4 *)0x0;
  if ((undefined4 *)0xf < &uStack_dc) {
    uStack_128 = 0x5901c6;
    _free(pcStack_10c);
    return;
  }
  uStack_128 = 0x5901d7;
  FUN_00401830();
  uStack_128 = 0x5901e5;
  FUN_00401830();
  pvVar8 = (void *)((int)register0x00000010 + -0x110);
  uStack_128 = 3;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((char *)0xf < pcStack_e8) {
    uStack_134 = (void *)0x59020c;
    _free(pvVar7);
    return;
  }
  pcStack_e8 = (char *)0xf;
  if ((char **)0xf < ppcStack_104) {
    uStack_134 = (void *)0x59022b;
    _free(_Memory_01);
    return;
  }
  uStack_134 = (void *)0x59023c;
  FUN_00401830();
  uStack_134 = (void *)0x59024a;
  FUN_00401830();
  _Memory_00 = &uStack_11c;
  uStack_134 = (void *)0x3;
  ppcStack_138 = &pcStack_100;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((char *)0xf < pcStack_f4) {
    uStack_140 = 0x590271;
    _free(pvVar6);
    return;
  }
  pcStack_f4 = (char *)0xf;
  uVar5 = (uint)pvVar6 & 0xffffff00;
  if (0xf < uVar2) {
    uStack_140 = 0x590290;
    _free(pvVar8);
    return;
  }
  uStack_140 = 0x5902a1;
  FUN_00401830();
  uStack_140 = 0x5902af;
  FUN_00401830();
  _Memory = &uStack_128;
  uStack_140 = 1;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((char *)0xf < pcStack_100) {
    iStack_14c = 0x5902d6;
    _free(&puStack_e0);
    return;
  }
  pcStack_100 = (char *)0xf;
  ppcStack_104 = (char **)0x0;
  if ((void *)0xf < uStack_11c) {
    iStack_14c = 0x5902f5;
    _free(_Memory_00);
    return;
  }
  iStack_14c = 0x590306;
  FUN_00401830();
  pvVar8 = (void *)0x1;
  iStack_14c = (int)register0x00000010 + -0x118;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar5) {
    uStack_154 = 0x590328;
    _free(uStack_11c);
    return;
  }
  uStack_154 = 0x590339;
  FUN_00401830();
  uStack_154 = 0x590347;
  FUN_00401830();
  pvVar7 = (void *)((int)register0x00000010 - 0x13c);
  uStack_154 = 1;
  pvStack_158 = (void *)0x1;
  ppuStack_15c = (uint **)&ppcStack_120;
  (**(code **)(*DAT_00b5a6c8 + 4))();
  if ((uint **)0xf < _Memory_01) {
    _free(&pcStack_f4);
    return;
  }
  uStack_11c = (void *)0x0;
  if ((void *)0xf < uStack_134) {
    _free(pvVar8);
    return;
  }
  FUN_00401830(s_reload_split_009bef68);
  pvVar6 = (void *)((int)register0x00000010 + -0x130);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(pvVar6,0);
  if ((char **)0xf < ppcStack_120) {
    _free(uStack_134);
    return;
  }
  FUN_00401830(s_refresh_damage_009bef78);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&ppcStack_138,0);
  if (0xf < uStack_128) {
    _free(_Memory);
    return;
  }
  FUN_00401830(s__time__009bef88);
  FUN_00401830(s_sp_delaytime_009bef90);
  (**(code **)(*DAT_00b5a6c8 + 8))(&uStack_140,1,&ppuStack_15c);
  if ((void *)0xf < uStack_134) {
    _free(pvVar8);
    return;
  }
  uStack_134 = (void *)0xf;
  ppcStack_138 = (char **)0x0;
  if ((void *)0xf < pvVar7) {
    _free(pvVar6);
    return;
  }
  FUN_00401830(s_previewcamera_009befa0);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&iStack_14c,4);
  if ((uint *)0xf < _Memory) {
    _free(pvVar7);
    return;
  }
  FUN_00401830(s_ds_showdamage_009befb0);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&uStack_154,1);
  if (&pcStack_10c < (char **)0x10) {
    FUN_00591fd0();
    iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
    *(undefined1 *)(in_ECX + 7) = *(undefined1 *)(iVar1 + 0x60);
    return;
  }
  _free(pvStack_158);
  return;
}


