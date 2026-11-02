// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x410000-0x41ffff

// ==== FUN_00410010 @ 0x00410010 ====

void FUN_00410010(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00410020 @ 0x00410020 ====

void FUN_00410020(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_00410040 @ 0x00410040 ====

void FUN_00410040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d2a0;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  DAT_00b5a6b0 = 0;
  *in_ECX = &PTR_FUN_0099d284;
  return;
}


// ==== FUN_00410060 @ 0x00410060 ====

void FUN_00410060(int param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_korea_0099d238,5);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    return;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_china_0099d240,5);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 8) = 1;
    return;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_japan_0099d248,5);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    return;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_0099d250);
  if (cVar1 == '\0') {
    cVar1 = FUN_004036a0(param_1,s_taiwan_0099d254);
    *(uint *)(in_ECX + 8) = -(uint)(cVar1 != '\0') & 4;
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 3;
  return;
}


// ==== FUN_00410110 @ 0x00410110 ====

int FUN_00410110(int param_1)

{
  int iVar1;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978758;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  iVar1 = *(int *)(in_ECX + 8);
  local_4 = 0;
  if (iVar1 == 2) {
    ExceptionList = &local_c;
    FUN_00401740(s_japan__0099d25c,6);
  }
  else if (iVar1 == 1) {
    ExceptionList = &local_c;
    FUN_00401740(s_china__0099d264,6);
  }
  else if (iVar1 == 3) {
    ExceptionList = &local_c;
    FUN_00401740(&DAT_0099d26c,4);
  }
  else {
    ExceptionList = &local_c;
    if (iVar1 == 4) {
      ExceptionList = &local_c;
      FUN_00403810(s_taiwan__0099d274);
    }
  }
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


// ==== FUN_004101f0 @ 0x004101f0 ====

void FUN_004101f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978772;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00405bd0(local_28,param_1,param_2);
  local_4 = 0;
  iVar2 = FUN_00410500(local_28);
  if (iVar2 == 0) {
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x44);
    for (iVar5 = *(int *)(iVar2 + 0x40); iVar5 != iVar1; iVar5 = iVar5 + 0x1c) {
      local_34 = (void *)0x0;
      local_30 = 0;
      local_2c = 0;
      local_4._1_3_ = (uint3)((uint)local_4 >> 8);
      local_4._0_1_ = 1;
      FUN_00405670(iVar5,local_38);
      if (local_34 == (void *)0x0) {
LAB_004102c7:
        local_4 = (uint)local_4._1_3_ << 8;
        if (local_34 != (void *)0x0) {
          FUN_00405de0(local_34,local_30,local_38,iVar1);
LAB_00410369:
          _free(local_34);
          return;
        }
      }
      else {
        iVar3 = local_30 - (int)local_34 >> 0x1f;
        iVar4 = (local_30 - (int)local_34) / 0x1c + iVar3;
        if ((uint)(iVar4 - iVar3) < 2) goto LAB_004102c7;
        if (iVar4 == iVar3) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_34 + 0x14),s_locale_0099d230,6);
        if (iVar3 == 0) {
          if ((local_34 == (void *)0x0) || ((uint)((local_30 - (int)local_34) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          FUN_00410060((int)local_34 + 0x1c);
        }
        local_4 = (uint)local_4._1_3_ << 8;
        if (local_34 != (void *)0x0) {
          FUN_00405de0(local_34,local_30,local_38,iVar1);
          goto LAB_00410369;
        }
      }
      local_34 = (void *)0x0;
      local_30 = 0;
      local_2c = 0;
    }
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004103e0 @ 0x004103e0 ====

void FUN_004103e0(undefined4 param_1)

{
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978784;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 4) != '\x01') {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_LocaleDefine__0099d220,0xd);
    local_4 = 0;
    FUN_004101f0(local_28,param_1);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 8);
    *(undefined1 *)(in_ECX + 4) = 1;
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00410470 @ 0x00410470 ====

void FUN_00410470(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978796;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d2a0;
  *(undefined1 *)(in_ECX + 1) = 0;
  local_4 = 0;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6b0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6b0 = in_ECX;
  }
  FUN_004103e0(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004104e0 @ 0x004104e0 ====

void FUN_004104e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00410040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00410500 @ 0x00410500 ====

undefined4 FUN_00410500(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978738;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x12;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_00410590 @ 0x00410590 ====

void FUN_00410590(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d2c0;
  return;
}


// ==== FUN_004105a0 @ 0x004105a0 ====

void FUN_004105a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d2c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004105c0 @ 0x004105c0 ====

void FUN_004105c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x48);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x11) = 1;
  *(undefined1 *)((int)puVar1 + 0x45) = 0;
  return;
}


// ==== FUN_00410600 @ 0x00410600 ====

void FUN_00410600(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    *param_3 = *param_3 + 1;
    if (*(char *)((int)param_1 + 0x45) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x45) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x45);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x45);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x45);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x45);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return;
}


// ==== FUN_00410660 @ 0x00410660 ====

/* WARNING: Removing unreachable block (ram,0x004106b8) */

undefined4 * FUN_00410660(int param_1)

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
  if (*(char *)((int)local_8[1] + 0x45) == '\0') {
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
LAB_004106e3:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_004106f0;
        }
LAB_004106f2:
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
        if (iVar4 == 0) goto LAB_004106e3;
LAB_004106f0:
        if (bVar9) goto LAB_004106f2;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x45) == '\0');
  }
  return local_8;
}


// ==== FUN_00410720 @ 0x00410720 ====

/* WARNING: Removing unreachable block (ram,0x0041076d) */

undefined4 * FUN_00410720(int param_1)

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
  undefined4 *local_c;
  
  local_c = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)local_c[1] + 0x45) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x14);
    puVar5 = (undefined4 *)local_c[1];
    do {
      uVar2 = puVar5[8];
      if ((uint)puVar5[9] < 0x10) {
        pbVar8 = (byte *)(puVar5 + 4);
      }
      else {
        pbVar8 = (byte *)puVar5[4];
      }
      if (uVar1 == 0) {
LAB_0041079c:
        if (uVar2 <= uVar1) {
          bVar9 = false;
          goto LAB_004107a9;
        }
LAB_004107ab:
        puVar6 = (undefined4 *)*puVar5;
        local_c = puVar5;
      }
      else {
        uVar3 = uVar1;
        if (uVar2 <= uVar1) {
          uVar3 = uVar2;
        }
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          pbVar7 = (byte *)(param_1 + 4);
        }
        else {
          pbVar7 = *(byte **)(param_1 + 4);
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
        if (iVar4 == 0) goto LAB_0041079c;
LAB_004107a9:
        if (bVar9) goto LAB_004107ab;
        puVar6 = (undefined4 *)puVar5[2];
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x45) == '\0');
  }
  return local_c;
}


// ==== FUN_004107d0 @ 0x004107d0 ====

void FUN_004107d0(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x40)) {
    _free(*(void **)(in_ECX + 0x2c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0xf;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x24) < 0x10) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0xf;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00410820 @ 0x00410820 ====

void FUN_00410820(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_00410660(param_2);
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


// ==== FUN_00410890 @ 0x00410890 ====

void FUN_00410890(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009787a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00410900 @ 0x00410900 ====

void FUN_00410900(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009787a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00410980 @ 0x00410980 ====

int FUN_00410980(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  FUN_00410820(&param_2,param_2);
  iVar1 = *(int *)(in_ECX + 8);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  if (param_2 == iVar1) {
    FUN_00401740(&DAT_0099d2ba,0);
    return param_1;
  }
  FUN_00401660(param_2 + 0x28,0,0xffffffff);
  return param_1;
}


// ==== FUN_004109e0 @ 0x004109e0 ====

void FUN_004109e0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00978813;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d2d0;
  local_4 = 1;
  FUN_00410b90(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  local_4 = local_4 & 0xffffff00;
  FUN_00410f60(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00410a80 @ 0x00410a80 ====

void FUN_00410a80(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_4c [12];
  void *local_40;
  uint local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978825;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00411370(param_1);
  uVar1 = FUN_00410890(param_1,param_2);
  local_4 = 0;
  FUN_00411200(local_4c,uVar1);
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_40);
  return;
}


// ==== FUN_00410b20 @ 0x00410b20 ====

void FUN_00410b20(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978837;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d2d0;
  iVar1 = FUN_004105c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00410b90 @ 0x00410b90 ====

void FUN_00410b90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x45) == '\0') {
    FUN_00410b90(*(undefined4 *)((int)param_1 + 8));
    FUN_004107d0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00410bd0 @ 0x00410bd0 ====

/* WARNING: Removing unreachable block (ram,0x00410cdd) */
/* WARNING: Removing unreachable block (ram,0x00410ced) */
/* WARNING: Removing unreachable block (ram,0x00410cf6) */
/* WARNING: Removing unreachable block (ram,0x00410cf9) */
/* WARNING: Removing unreachable block (ram,0x00410ce9) */
/* WARNING: Removing unreachable block (ram,0x00410d07) */
/* WARNING: Removing unreachable block (ram,0x00410d14) */
/* WARNING: Removing unreachable block (ram,0x00410d1f) */
/* WARNING: Removing unreachable block (ram,0x00410d1b) */
/* WARNING: Removing unreachable block (ram,0x00410d0f) */
/* WARNING: Removing unreachable block (ram,0x00410d22) */

void FUN_00410bd0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009787c8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x45) != '\0') {
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
  FUN_00503890();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
    if (*(char *)(param_2[2] + 0x45) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
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
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      piVar3 = (int *)FUN_00503810(piVar5);
    }
    else {
      piVar3 = piVar6;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      uVar4 = FUN_00868460(piVar5);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar6;
    }
  }
  if ((char)param_2[0x11] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        if ((char)piVar5[0x11] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x11] == '\0') {
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar6 + 0x11) = 0;
            FUN_00868500(piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x45) == '\0') {
            if ((*(char *)(*piVar3 + 0x44) == '\x01') && (*(char *)(piVar3[2] + 0x44) == '\x01'))
            goto LAB_00410df4;
            if (*(char *)(piVar3[2] + 0x44) == '\x01') {
              *(undefined1 *)(*piVar3 + 0x44) = 1;
              *(undefined1 *)(piVar3 + 0x11) = 0;
              FUN_00868550(piVar3);
              piVar3 = (int *)piVar6[2];
            }
            *(char *)(piVar3 + 0x11) = (char)piVar6[0x11];
            *(undefined1 *)(piVar6 + 0x11) = 1;
            *(undefined1 *)(piVar3[2] + 0x44) = 1;
            FUN_00868500(piVar6);
            break;
          }
        }
        else {
          if ((char)piVar3[0x11] == '\0') {
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar6 + 0x11) = 0;
            FUN_00868550(piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x45) == '\0') {
            if ((*(char *)(piVar3[2] + 0x44) != '\x01') || (*(char *)(*piVar3 + 0x44) != '\x01')) {
              if (*(char *)(*piVar3 + 0x44) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x44) = 1;
                *(undefined1 *)(piVar3 + 0x11) = 0;
                FUN_00868500(piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 0x11) = (char)piVar6[0x11];
              *(undefined1 *)(piVar6 + 0x11) = 1;
              *(undefined1 *)(*piVar3 + 0x44) = 1;
              FUN_00868550(piVar6);
              break;
            }
LAB_00410df4:
            *(undefined1 *)(piVar3 + 0x11) = 0;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x11) = 1;
  }
  if (0xf < (uint)param_2[0x10]) {
    _free((void *)param_2[0xb]);
    return;
  }
  param_2[0x10] = 0xf;
  param_2[0xf] = 0;
  *(undefined1 *)(param_2 + 0xb) = 0;
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


// ==== FUN_00410ec0 @ 0x00410ec0 ====

undefined4 *
FUN_00410ec0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009787f1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x48);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_00410900(param_4);
    *(undefined1 *)(puVar1 + 0x11) = param_5;
    *(undefined1 *)((int)puVar1 + 0x45) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00410f3e @ 0x00410f3e ====

void Catch_00410f3e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00410f60 @ 0x00410f60 ====

void FUN_00410f60(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00410b90(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x45) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x45) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x45);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x45);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x45);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x45);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00410bd0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00411020 @ 0x00411020 ====

void FUN_00411020(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009787c8;
  local_c = ExceptionList;
  if (0x4924922 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00410ec0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x44);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x44) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x11] == '\0') {
LAB_00411119:
        *(undefined1 *)(*piVar5 + 0x44) = 1;
        *(undefined1 *)(piVar6 + 0x11) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x44) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00868500(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x44) = 0;
        FUN_00868550(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x11] == '\0') goto LAB_00411119;
      if (piVar7 == (int *)*piVar2) {
        FUN_00868550(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x44) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x45) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x44);
  } while( true );
}


// ==== FUN_00411200 @ 0x00411200 ====

/* WARNING: Removing unreachable block (ram,0x0041125f) */

void FUN_00411200(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x45) == '\0') {
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
LAB_00411290:
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
        if (uVar5 == 0) goto LAB_00411290;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x45) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_00411020(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00503830();
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
    puVar6 = (undefined4 *)FUN_00411020(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00411370 @ 0x00411370 ====

undefined4 FUN_00411370(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_4 [4];
  
  uVar2 = param_1;
  uVar1 = FUN_00410720(param_1);
  uVar2 = FUN_00410660(uVar2);
  param_1 = 0;
  FUN_00410600(uVar2,uVar1,&param_1,0);
  FUN_00410f60(local_4,uVar2,uVar1);
  return param_1;
}


// ==== FUN_004113d0 @ 0x004113d0 ====

void FUN_004113d0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00410f60(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00411400 @ 0x00411400 ====

void FUN_00411400(byte param_1)

{
  void *in_ECX;
  
  FUN_004109e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00411420 @ 0x00411420 ====

undefined4 FUN_00411420(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00411430 @ 0x00411430 ====

int FUN_00411430(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x1c;
}


// ==== FUN_00411460 @ 0x00411460 ====

void FUN_00411460(void)

{
  undefined4 ***pppuVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_28 [4];
  undefined4 ***local_24 [4];
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978858;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 0x10);
  ExceptionList = &local_c;
  if (iVar2 != *(int *)(in_ECX + 0x14)) {
    do {
      local_4 = 0xffffffff;
      FUN_00402220(local_28,iVar2,&DAT_0099d2e0);
      local_4 = 0;
      pppuVar1 = local_24[0];
      if (local_10 < 0x10) {
        pppuVar1 = local_24;
      }
      FUN_004249c0(pppuVar1,local_14);
      local_4 = 0xffffffff;
      if (0xf < local_10) {
        _free(local_24[0]);
        return;
      }
      iVar2 = iVar2 + 0x1c;
      local_10 = 0xf;
      local_14 = 0;
      local_24[0] = (undefined4 ***)((uint)local_24[0] & 0xffffff00);
    } while (iVar2 != *(int *)(in_ECX + 0x14));
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00411510 @ 0x00411510 ====

int FUN_00411510(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0x14) - iVar1) / 0x1c)) {
      return iVar1 + param_1 * 0x1c;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00411560 @ 0x00411560 ====

void FUN_00411560(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978872;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar2;
  FUN_00424b00(param_1);
  local_4 = 0;
  cVar1 = FUN_00424b20();
  while( true ) {
    if (cVar1 != '\0') {
      local_4 = 0xffffffff;
      FUN_00424b10();
      ExceptionList = local_c;
      return;
    }
    FUN_00424b80(local_28);
    local_4._0_1_ = 1;
    FUN_00406720(local_28);
    local_4 = (uint)local_4._1_3_ << 8;
    if (0xf < local_10) break;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    cVar1 = FUN_00424b20();
  }
  _free(local_24);
  return;
}


// ==== FUN_00411630 @ 0x00411630 ====

void FUN_00411630(void)

{
  FUN_00406720();
  return;
}


// ==== FUN_00411640 @ 0x00411640 ====

void FUN_00411640(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x35) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x35) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x35);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x35);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x35);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x35);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004116a0 @ 0x004116a0 ====

int FUN_004116a0(char *param_1,undefined4 param_2)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int extraout_EAX;
  char *pcVar5;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int in_ECX;
  int local_80;
  undefined1 local_7c [8];
  undefined1 local_74 [4];
  void *local_70;
  undefined4 local_60;
  uint local_5c;
  int local_58;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009788d8;
  local_c = ExceptionList;
  if (*(uint *)(in_ECX + 0x40) < 0x65) {
    if (*(uint *)(in_ECX + 8) <= *(uint *)(in_ECX + 0xc)) {
      local_5c = 0xf;
      local_60 = 0;
      local_70 = (void *)((uint)local_70 & 0xffffff00);
      ExceptionList = &local_c;
      FUN_00401740(s_m_dwMaxGeneratedID_<_m_dwGenerat_0099d31c,0x26);
      local_4 = 0;
      FUN_00406880(local_74);
      if (local_5c < 0x10) {
        pcVar2 = (code *)swi(3);
        iVar4 = (*pcVar2)();
        return iVar4;
      }
      _free(local_70);
      return extraout_EAX;
    }
    local_80 = *(int *)(in_ECX + 0xc);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xc) = local_80 + 1;
  }
  else {
    uVar3 = *(uint *)(in_ECX + 0x3c) >> 2;
    iVar4 = uVar3 * -4;
    if (*(uint *)(in_ECX + 0x38) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(in_ECX + 0x38);
    }
    local_80 = *(int *)(*(int *)(*(int *)(in_ECX + 0x34) + uVar3 * 4) +
                       (*(uint *)(in_ECX + 0x3c) + iVar4) * 4);
    ExceptionList = &local_c;
    if (*(int *)(in_ECX + 0x40) != 0) {
      ExceptionList = &local_c;
      *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
      if ((uint)(*(int *)(in_ECX + 0x38) * 4) <= *(uint *)(in_ECX + 0x3c)) {
        *(undefined4 *)(in_ECX + 0x3c) = 0;
      }
      iVar4 = *(int *)(in_ECX + 0x40) + -1;
      *(int *)(in_ECX + 0x40) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(in_ECX + 0x3c) = 0;
      }
    }
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  local_4 = 1;
  local_58 = local_80;
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(param_1,(int)pcVar5 - (int)(param_1 + 1));
  local_38 = param_2;
  local_34 = local_58;
  local_30 = local_58;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_54,0,0xffffffff);
  local_10 = local_38;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004125f0(local_7c,&local_34);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_00;
  }
  if (local_3c < 0x10) {
    ExceptionList = local_c;
    return local_80;
  }
  _free(local_50);
  return extraout_EAX_01;
}


// ==== FUN_00411870 @ 0x00411870 ====

void FUN_00411870(uint param_1)

{
  int in_ECX;
  void *local_2c;
  undefined1 auStack_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009788ea;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00411c90();
  if (local_2c != *(void **)(in_ECX + 0x28)) {
    FUN_00411de0();
  }
  if ((param_1 < *(uint *)(in_ECX + 0xc)) && (*(uint *)(in_ECX + 4) <= param_1)) {
    FUN_004124b0();
    ExceptionList = pvStack_c;
    return;
  }
  FUN_00401740(s_Invalid_ID___d___0099d344,0x10);
  FUN_00404230(auStack_28);
  uStack_4 = 0;
  (**(code **)(*DAT_00b5a6c0 + 4))();
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00411960 @ 0x00411960 ====

void FUN_00411960(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00411870(param_3);
  return;
}


// ==== FUN_00411970 @ 0x00411970 ====

void FUN_00411970(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if (DAT_00b5a7e0 <= *(uint *)(in_ECX + 0x20)) {
    DAT_00b5a7e0 = *(uint *)(in_ECX + 0x20);
  }
  iVar2 = *(int *)(in_ECX + 0x20);
  while (iVar2 != 0) {
    uVar1 = *(uint *)(in_ECX + 0x1c) >> 2;
    iVar2 = uVar1 * -4;
    if (*(uint *)(in_ECX + 0x18) <= uVar1) {
      uVar1 = uVar1 - *(uint *)(in_ECX + 0x18);
    }
    FUN_004124b0(*(int *)(*(int *)(in_ECX + 0x14) + uVar1 * 4) +
                 (*(uint *)(in_ECX + 0x1c) + iVar2) * 4);
    if (*(int *)(in_ECX + 0x20) != 0) {
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
      if ((uint)(*(int *)(in_ECX + 0x18) * 4) <= *(uint *)(in_ECX + 0x1c)) {
        *(undefined4 *)(in_ECX + 0x1c) = 0;
      }
      iVar2 = *(int *)(in_ECX + 0x20) + -1;
      *(int *)(in_ECX + 0x20) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(in_ECX + 0x1c) = 0;
      }
    }
    iVar2 = *(int *)(in_ECX + 0x20);
  }
  return;
}


// ==== FUN_004119f0 @ 0x004119f0 ====

void FUN_004119f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *in_ECX;
  undefined1 auStack_68 [4];
  undefined1 local_64;
  undefined4 local_54;
  undefined1 **local_50;
  char *pcStack_4c;
  undefined1 *local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097892d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d370;
  local_4._0_1_ = 2;
  local_4._1_3_ = 0;
  if (in_ECX[0xb] != 0) {
    pcStack_4c = &DAT_0099d2e8;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_50 = (undefined1 **)0x411a4e;
    FUN_00401740();
    local_4._0_1_ = 3;
    pcStack_4c = (char *)0x411a5d;
    FUN_00796d50();
    local_4._0_1_ = 2;
    if (0xf < local_10) {
      pcStack_4c = (char *)0x411a7a;
      _free(local_24);
      return;
    }
    pcStack_4c = s_______________________0099d2fc;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_50 = (undefined1 **)0x411a99;
    FUN_00401740();
    local_4._0_1_ = 4;
    pcStack_4c = (char *)0x411aa8;
    FUN_00796d50();
    local_4._0_1_ = 2;
    if (0xf < local_10) {
      pcStack_4c = (char *)0x411ac0;
      _free(local_24);
      return;
    }
    puVar2 = (undefined4 *)in_ECX[10];
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      local_4._0_1_ = 2;
      if ((uint)puVar3[0xb] < 0x10) {
        pcStack_4c = (char *)(puVar3 + 6);
      }
      else {
        pcStack_4c = (char *)puVar3[6];
      }
      local_2c = auStack_68;
      local_50 = (undefined1 **)0xf;
      local_54 = 0;
      local_64 = 0;
      FUN_00401740(s__s__d__0099d314,7);
      uVar6 = FUN_00404230(local_28);
      local_4._0_1_ = 5;
      FUN_00796d50(uVar6);
      local_4._0_1_ = 2;
      if (0xf < local_10) {
        pcStack_4c = (char *)0x411b33;
        _free(local_24);
        return;
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      if (*(char *)((int)puVar3 + 0x35) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x35) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x35);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x35);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x35);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x35);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    local_4._0_1_ = 2;
    pcStack_4c = (char *)0x411b9c;
    FUN_004120b0();
    *(undefined4 *)(in_ECX[10] + 4) = in_ECX[10];
    in_ECX[0xb] = 0;
    *(undefined4 *)in_ECX[10] = in_ECX[10];
    *(undefined4 *)(in_ECX[10] + 8) = in_ECX[10];
  }
  FUN_0046cfc0();
  pcStack_4c = *(char **)in_ECX[10];
  local_50 = &local_2c;
  local_4 = (uint)local_4._1_3_ << 8;
  local_54 = 0x411bd2;
  FUN_00412530();
  pcStack_4c = (char *)0x411bdb;
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_00411c00 @ 0x00411c00 ====

void FUN_00411c00(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978942;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d370;
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  in_ECX[3] = param_1;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  local_4 = 0;
  iVar1 = FUN_00412ce0();
  in_ECX[10] = iVar1;
  *(undefined1 *)(iVar1 + 0x35) = 1;
  *(undefined4 *)(in_ECX[10] + 4) = in_ECX[10];
  *(undefined4 *)in_ECX[10] = in_ECX[10];
  *(undefined4 *)(in_ECX[10] + 8) = in_ECX[10];
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00411c90 @ 0x00411c90 ====

void FUN_00411c90(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x35) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x35) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00411d00 @ 0x00411d00 ====

void FUN_00411d00(void)

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
  puStack_8 = &LAB_00978888;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_deque<T>_too_long_0099d358,0x11);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c48c);
}


// ==== FUN_00411d70 @ 0x00411d70 ====

void FUN_00411d70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  *in_ECX = param_1;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  FUN_00401660(param_4 + 2,0,0xffffffff);
  in_ECX[0xc] = param_4[9];
  *(undefined1 *)(in_ECX + 0xd) = param_5;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  return;
}


// ==== FUN_00411de0 @ 0x00411de0 ====

/* WARNING: Removing unreachable block (ram,0x00411ef0) */
/* WARNING: Removing unreachable block (ram,0x00411f01) */
/* WARNING: Removing unreachable block (ram,0x00411f0a) */
/* WARNING: Removing unreachable block (ram,0x00411f0d) */
/* WARNING: Removing unreachable block (ram,0x00411efd) */
/* WARNING: Removing unreachable block (ram,0x00411f1b) */
/* WARNING: Removing unreachable block (ram,0x00411f28) */
/* WARNING: Removing unreachable block (ram,0x00411f33) */
/* WARNING: Removing unreachable block (ram,0x00411f2f) */
/* WARNING: Removing unreachable block (ram,0x00411f23) */
/* WARNING: Removing unreachable block (ram,0x00411f36) */

void FUN_00411de0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978888;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x35) != '\0') {
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
  FUN_00411640();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
    if (*(char *)(param_2[2] + 0x35) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      piVar3 = (int *)FUN_0087c940(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      uVar4 = FUN_00868480(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xd] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xd] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_008685b0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(*piVar5 + 0x34) == '\x01') && (*(char *)(piVar5[2] + 0x34) == '\x01'))
            goto LAB_00412007;
            if (*(char *)(piVar5[2] + 0x34) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              *(undefined1 *)(piVar5 + 0xd) = 0;
              FUN_00868600(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
            *(undefined1 *)(piVar3 + 0xd) = 1;
            *(undefined1 *)(piVar5[2] + 0x34) = 1;
            FUN_008685b0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_00868600(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(piVar5[2] + 0x34) != '\x01') || (*(char *)(*piVar5 + 0x34) != '\x01')) {
              if (*(char *)(*piVar5 + 0x34) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x34) = 1;
                *(undefined1 *)(piVar5 + 0xd) = 0;
                FUN_008685b0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
              *(undefined1 *)(piVar3 + 0xd) = 1;
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              FUN_00868600(piVar3);
              break;
            }
LAB_00412007:
            *(undefined1 *)(piVar5 + 0xd) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xd) = 1;
  }
  if ((uint)param_2[0xb] < 0x10) {
    param_2[0xb] = 0xf;
    param_2[10] = 0;
    *(undefined1 *)(param_2 + 6) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[6]);
  return;
}


// ==== FUN_004120b0 @ 0x004120b0 ====

void FUN_004120b0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x35) == '\0') {
    FUN_004120b0(*(undefined4 *)((int)param_1 + 8));
    FUN_00713800();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004120f0 @ 0x004120f0 ====

void * FUN_004120f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009788b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x38);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_00411d70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00412162 @ 0x00412162 ====

void Catch_00412162(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00412180 @ 0x00412180 ====

void FUN_00412180(uint param_1)

{
  size_t sVar1;
  uint uVar2;
  undefined4 *_Dst;
  void *pvVar3;
  int in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar2 = *(uint *)(in_ECX + 8);
  if (0xfffffff - uVar2 < param_1) {
    uVar2 = FUN_00411d00();
  }
  uVar4 = uVar2 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  if ((param_1 < uVar4) && (uVar2 <= 0xfffffff - uVar4)) {
    param_1 = uVar4;
  }
  uVar4 = *(uint *)(in_ECX + 0xc) >> 2;
  _Dst = operator_new((uVar2 + param_1) * 4);
  iVar6 = uVar4 * 4;
  pvVar3 = (void *)(iVar6 + *(int *)(in_ECX + 4));
  sVar1 = ((*(int *)(in_ECX + 8) * 4 - (int)pvVar3) + *(int *)(in_ECX + 4) >> 2) * 4;
  pvVar3 = _memmove(_Dst + uVar4,pvVar3,sVar1);
  pvVar3 = (void *)((int)pvVar3 + sVar1);
  if (param_1 < uVar4) {
    _memmove(pvVar3,*(void **)(in_ECX + 4),((int)(param_1 * 4) >> 2) * 4);
    pvVar3 = (void *)(*(int *)(in_ECX + 4) + param_1 * 4);
    sVar1 = ((iVar6 - (int)pvVar3) + *(int *)(in_ECX + 4) >> 2) * 4;
    pvVar3 = _memmove(_Dst,pvVar3,sVar1);
    puVar5 = (undefined4 *)((int)pvVar3 + sVar1);
    if (param_1 == 0) goto LAB_004122ac;
    uVar4 = param_1;
  }
  else {
    sVar1 = (iVar6 >> 2) * 4;
    iVar6 = param_1 - uVar4;
    pvVar3 = _memmove(pvVar3,*(void **)(in_ECX + 4),sVar1);
    if (iVar6 != 0) {
      puVar5 = (undefined4 *)((int)pvVar3 + sVar1);
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
    if (uVar4 == 0) goto LAB_004122ac;
    puVar5 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
LAB_004122ac:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004122d0 @ 0x004122d0 ====

void FUN_004122d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00978888;
  local_c = ExceptionList;
  if (0x6666664 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004120f0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x34);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x34) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xd] == '\0') {
LAB_004123c9:
        *(undefined1 *)(*piVar5 + 0x34) = 1;
        *(undefined1 *)(piVar6 + 0xd) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x34) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_008685b0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x34) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x34) = 0;
        FUN_00868600(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xd] == '\0') goto LAB_004123c9;
      if (piVar7 == (int *)*piVar2) {
        FUN_00868600(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x34) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x34) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x35) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x34);
  } while( true );
}


// ==== FUN_004124b0 @ 0x004124b0 ====

void FUN_004124b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10) & 3U) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 4U >> 2)) {
    FUN_00412180(1);
  }
  uVar3 = *(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10);
  uVar4 = uVar3 >> 2;
  if (*(uint *)(in_ECX + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(in_ECX + 8);
  }
  if (*(int *)(*(int *)(in_ECX + 4) + uVar4 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)(in_ECX + 4) + uVar4 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + uVar4 * 4) + (uVar3 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  return;
}


// ==== FUN_00412530 @ 0x00412530 ====

void FUN_00412530(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004120b0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x35) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x35) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x35);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x35);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x35);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x35);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00411de0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004125f0 @ 0x004125f0 ====

void FUN_004125f0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x35) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x35) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004122d0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00885cd0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004122d0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004126b0 @ 0x004126b0 ====

void FUN_004126b0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00412530(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004126e0 @ 0x004126e0 ====

void FUN_004126e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004119f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00412700 @ 0x00412700 ====

void FUN_00412700(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d3f4;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_00412720 @ 0x00412720 ====

undefined4 FUN_00412720(void)

{
  return 0x50012;
}


// ==== FUN_00412730 @ 0x00412730 ====

void FUN_00412730(byte param_1)

{
  FUN_00412760();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00412760 @ 0x00412760 ====

void FUN_00412760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d3f4;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00412790 @ 0x00412790 ====

void FUN_00412790(uint param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x2008b;
  *(undefined2 *)((int)pvVar1 + 6) = 0x50;
  iVar2 = FUN_004244d0();
  puVar6 = (undefined4 *)(iVar2 + 0x10);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = (undefined4 *)(iVar2 + 0x10);
  for (uVar5 = param_1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = *param_2;
    param_2 = param_2 + 1;
    puVar6 = puVar6 + 1;
  }
  for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
  if (iVar4 == 0) {
    FUN_00797a20(0);
    return;
  }
  uVar3 = FUN_00412700(iVar2);
  FUN_00797a20(uVar3);
  return;
}


// ==== FUN_00412820 @ 0x00412820 ====

void FUN_00412820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d408;
  return;
}


// ==== FUN_00412830 @ 0x00412830 ====

void FUN_00412830(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d408;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00412850 @ 0x00412850 ====

void FUN_00412850(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x39);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x39);
  }
  return;
}


// ==== FUN_00412870 @ 0x00412870 ====

void FUN_00412870(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x25);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x25);
  }
  return;
}


// ==== FUN_00412890 @ 0x00412890 ====

void FUN_00412890(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x25) == '\0') {
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


// ==== FUN_004128f0 @ 0x004128f0 ====

void FUN_004128f0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x21);
  }
  return;
}


// ==== FUN_00412910 @ 0x00412910 ====

void FUN_00412910(void *param_1)

{
  _free(param_1);
  return;
}


// ==== FUN_00412920 @ 0x00412920 ====

void FUN_00412920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d428;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a744 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a744 = in_ECX;
  return;
}


// ==== FUN_00412970 @ 0x00412970 ====

undefined4 FUN_00412970(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978b8a;
  local_c = ExceptionList;
  switch(param_1) {
  case 1:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xcc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004381b0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 2:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x7c);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004132f0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 3:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xa0);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00433ac0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 4:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00432f60();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 5:
  case 9:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 8;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00413750();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 6:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 4;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004133a0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 7:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xd8);
    local_4 = 5;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00414ea0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 8:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 6;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00413c20();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x34);
    local_4 = 9;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00413ca0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xb:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 10;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00413d50();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xc:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 0xb;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004134b0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xe:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 0xc;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00413550();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xf:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x24);
    local_4 = 7;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00413400();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 0xd;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004135f0();
      ExceptionList = local_c;
      return uVar2;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00412ce0 @ 0x00412ce0 ====

void FUN_00412ce0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x38);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xd) = 1;
  *(undefined1 *)((int)puVar1 + 0x35) = 0;
  return;
}


// ==== FUN_00412d20 @ 0x00412d20 ====

void FUN_00412d20(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 9) = 1;
  *(undefined1 *)((int)puVar1 + 0x25) = 0;
  return;
}


// ==== FUN_00412d60 @ 0x00412d60 ====

void FUN_00412d60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d428;
  DAT_00b5a744 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00412d90 @ 0x00412d90 ====

void FUN_00412d90(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00412dc0 @ 0x00412dc0 ====

void FUN_00412dc0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00412df0 @ 0x00412df0 ====

void FUN_00412df0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0xa8) {
    FUN_00412f30();
  }
  return;
}


// ==== FUN_00412e20 @ 0x00412e20 ====

void FUN_00412e20(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0xa8) {
    FUN_00412f30();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00412e70 @ 0x00412e70 ====

void FUN_00412e70(void)

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
  puStack_8 = &LAB_00978958;
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


// ==== FUN_00412ee0 @ 0x00412ee0 ====

void FUN_00412ee0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x20) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00412f30 @ 0x00412f30 ====

void FUN_00412f30(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978983;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_00412e20();
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    ExceptionList = local_c;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00412fc0 @ 0x00412fc0 ====

void FUN_00412fc0(void)

{
  undefined4 uVar1;
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
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009789a0;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s___d__usa_24_0_1_2__develop_modul_0099d448,0x4e);
  local_4 = 0;
  uVar1 = FUN_004022a0(local_28,s_Can_t_Save_this_Data_0099d430,local_44);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00796d50(uVar1);
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_40);
  return;
}


// ==== FUN_00413070 @ 0x00413070 ====

undefined4 FUN_00413070(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x3fffffff < param_1) {
    param_1 = FUN_00412e70();
  }
  pvVar1 = operator_new(param_1 * 4);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_004130c0 @ 0x004130c0 ====

undefined4 FUN_004130c0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x7fffffff < param_1) {
    param_1 = FUN_00412e70();
  }
  pvVar1 = operator_new(param_1 * 2);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 2 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00413110 @ 0x00413110 ====

undefined4 FUN_00413110(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x15555555 < param_1) {
    param_1 = FUN_00412e70();
  }
  pvVar1 = operator_new(param_1 * 0xc);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0xc + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00413160 @ 0x00413160 ====

undefined4 FUN_00413160(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x4444444 < param_1) {
    param_1 = FUN_00412e70();
  }
  pvVar1 = operator_new(param_1 * 0x3c);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x3c + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_004131c0 @ 0x004131c0 ====

undefined4 FUN_004131c0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x1fffffff < param_1) {
    param_1 = FUN_00412e70();
  }
  pvVar1 = operator_new(param_1 * 8);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 8 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00413210 @ 0x00413210 ====

undefined4 FUN_00413210(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  uint extraout_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x1861861 < param_1) {
    FUN_00412e70();
    param_1 = extraout_ECX;
  }
  pvVar1 = operator_new(param_1 * 0xa8);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0xa8 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00413270 @ 0x00413270 ====

void FUN_00413270(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x2c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x2c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  if (*(uint *)(in_ECX + 0x24) < 0x10) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0xf;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_004132c0 @ 0x004132c0 ====

void FUN_004132c0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x14) {
    FUN_00412d90();
  }
  return;
}


// ==== FUN_004132f0 @ 0x004132f0 ====

void FUN_004132f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d49c;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  return;
}


// ==== FUN_00413330 @ 0x00413330 ====

void FUN_00413330(byte param_1)

{
  void *in_ECX;
  
  FUN_00413350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413350 @ 0x00413350 ====

void FUN_00413350(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009789b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d49c;
  local_4 = 0;
  FUN_00412e20();
  *in_ECX = &PTR_FUN_0099d408;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004133a0 @ 0x004133a0 ====

void FUN_004133a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d4bc;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  return;
}


// ==== FUN_004133e0 @ 0x004133e0 ====

void FUN_004133e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00426470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413400 @ 0x00413400 ====

void FUN_00413400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d4dc;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  return;
}


// ==== FUN_00413440 @ 0x00413440 ====

undefined4 FUN_00413440(void)

{
  return 0xf;
}


// ==== FUN_00413450 @ 0x00413450 ====

void FUN_00413450(byte param_1)

{
  void *in_ECX;
  
  FUN_00413470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413470 @ 0x00413470 ====

void FUN_00413470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d4dc;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_004134b0 @ 0x004134b0 ====

void FUN_004134b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d4fc;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  return;
}


// ==== FUN_004134f0 @ 0x004134f0 ====

void FUN_004134f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00413510();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413510 @ 0x00413510 ====

void FUN_00413510(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d4fc;
  if ((void *)in_ECX[5] == (void *)0x0) {
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00413550 @ 0x00413550 ====

void FUN_00413550(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d51c;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00413590 @ 0x00413590 ====

void FUN_00413590(byte param_1)

{
  void *in_ECX;
  
  FUN_004135b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004135b0 @ 0x004135b0 ====

void FUN_004135b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d51c;
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_004135f0 @ 0x004135f0 ====

void FUN_004135f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d53c;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  return;
}


// ==== FUN_00413630 @ 0x00413630 ====

int FUN_00413630(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc);
}


// ==== FUN_00413640 @ 0x00413640 ====

void FUN_00413640(byte param_1)

{
  void *in_ECX;
  
  FUN_00413660();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413660 @ 0x00413660 ====

void FUN_00413660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d53c;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004136a0 @ 0x004136a0 ====

void FUN_004136a0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x3c) {
    FUN_00713830();
  }
  return;
}


// ==== FUN_004136d0 @ 0x004136d0 ====

void FUN_004136d0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_00446f40();
  }
  return;
}


// ==== FUN_00413700 @ 0x00413700 ====

void FUN_00413700(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    FUN_00412d90();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00413750 @ 0x00413750 ====

void FUN_00413750(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d55c;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00413790 @ 0x00413790 ====

undefined4 FUN_00413790(void)

{
  return 9;
}


// ==== FUN_004137a0 @ 0x004137a0 ====

void FUN_004137a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004137c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004137c0 @ 0x004137c0 ====

void FUN_004137c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d55c;
  if (in_ECX[4] == 0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  FUN_00405de0(in_ECX[4],in_ECX[5],in_ECX + 3);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00413810 @ 0x00413810 ====

void FUN_00413810(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x3c) {
    FUN_00713830();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00413860 @ 0x00413860 ====

void FUN_00413860(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_00446f40();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004138b0 @ 0x004138b0 ====

void FUN_004138b0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    FUN_00412d90();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004138d0 @ 0x004138d0 ====

void FUN_004138d0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_00446f40();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004138e0 @ 0x004138e0 ====

/* WARNING: Removing unreachable block (ram,0x004139ee) */
/* WARNING: Removing unreachable block (ram,0x004139ff) */
/* WARNING: Removing unreachable block (ram,0x00413a08) */
/* WARNING: Removing unreachable block (ram,0x00413a0b) */
/* WARNING: Removing unreachable block (ram,0x004139fb) */
/* WARNING: Removing unreachable block (ram,0x00413a19) */
/* WARNING: Removing unreachable block (ram,0x00413a26) */
/* WARNING: Removing unreachable block (ram,0x00413a31) */
/* WARNING: Removing unreachable block (ram,0x00413a2d) */
/* WARNING: Removing unreachable block (ram,0x00413a21) */
/* WARNING: Removing unreachable block (ram,0x00413a34) */

void FUN_004138e0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978958;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x39) != '\0') {
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
  FUN_004be1c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
    if (*(char *)(param_2[2] + 0x39) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      piVar3 = (int *)FUN_00412850(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      uVar4 = FUN_004be020(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xe] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xe] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar3 + 0xe) = 0;
            FUN_006c8fe0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(*piVar5 + 0x38) == '\x01') && (*(char *)(piVar5[2] + 0x38) == '\x01'))
            goto LAB_00413b05;
            if (*(char *)(piVar5[2] + 0x38) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x38) = 1;
              *(undefined1 *)(piVar5 + 0xe) = 0;
              FUN_006c9030(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xe) = (char)piVar3[0xe];
            *(undefined1 *)(piVar3 + 0xe) = 1;
            *(undefined1 *)(piVar5[2] + 0x38) = 1;
            FUN_006c8fe0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar3 + 0xe) = 0;
            FUN_006c9030(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(piVar5[2] + 0x38) != '\x01') || (*(char *)(*piVar5 + 0x38) != '\x01')) {
              if (*(char *)(*piVar5 + 0x38) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x38) = 1;
                *(undefined1 *)(piVar5 + 0xe) = 0;
                FUN_006c8fe0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xe) = (char)piVar3[0xe];
              *(undefined1 *)(piVar3 + 0xe) = 1;
              *(undefined1 *)(*piVar5 + 0x38) = 1;
              FUN_006c9030(piVar3);
              break;
            }
LAB_00413b05:
            *(undefined1 *)(piVar5 + 0xe) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xe) = 1;
  }
  if ((void *)param_2[0xb] != (void *)0x0) {
    _free((void *)param_2[0xb]);
    return;
  }
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
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


// ==== FUN_00413bd0 @ 0x00413bd0 ====

void FUN_00413bd0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x39) == '\0') {
    FUN_00413bd0(*(undefined4 *)((int)param_1 + 8));
    FUN_00413270();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00413c10 @ 0x00413c10 ====

void FUN_00413c10(void)

{
  FUN_00413700();
  return;
}


// ==== FUN_00413c20 @ 0x00413c20 ====

void FUN_00413c20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d57c;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  return;
}


// ==== FUN_00413c60 @ 0x00413c60 ====

void FUN_00413c60(byte param_1)

{
  void *in_ECX;
  
  FUN_00413c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413c80 @ 0x00413c80 ====

void FUN_00413c80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d57c;
  FUN_00413810();
  *in_ECX = &PTR_FUN_0099d408;
  return;
}


// ==== FUN_00413ca0 @ 0x00413ca0 ====

void FUN_00413ca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d59c;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_00413cf0 @ 0x00413cf0 ====

void FUN_00413cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00413d10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413d10 @ 0x00413d10 ====

void FUN_00413d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d59c;
  if ((void *)in_ECX[10] == (void *)0x0) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    FUN_00413810();
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_00413d50 @ 0x00413d50 ====

void FUN_00413d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d5bc;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00413d90 @ 0x00413d90 ====

undefined4 FUN_00413d90(void)

{
  return 0xb;
}


// ==== FUN_00413da0 @ 0x00413da0 ====

void FUN_00413da0(byte param_1)

{
  void *in_ECX;
  
  FUN_00413dc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00413dc0 @ 0x00413dc0 ====

void FUN_00413dc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d5bc;
  FUN_00413860();
  *in_ECX = &PTR_FUN_0099d408;
  return;
}


// ==== FUN_00413de0 @ 0x00413de0 ====

/* WARNING: Removing unreachable block (ram,0x00413ef0) */
/* WARNING: Removing unreachable block (ram,0x00413f01) */
/* WARNING: Removing unreachable block (ram,0x00413f0a) */
/* WARNING: Removing unreachable block (ram,0x00413f0d) */
/* WARNING: Removing unreachable block (ram,0x00413efd) */
/* WARNING: Removing unreachable block (ram,0x00413f1b) */
/* WARNING: Removing unreachable block (ram,0x00413f28) */
/* WARNING: Removing unreachable block (ram,0x00413f33) */
/* WARNING: Removing unreachable block (ram,0x00413f2f) */
/* WARNING: Removing unreachable block (ram,0x00413f23) */
/* WARNING: Removing unreachable block (ram,0x00413f36) */

void FUN_00413de0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978958;
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
            goto LAB_00414007;
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
LAB_00414007:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 9) = 1;
  }
  if ((void *)param_2[5] == (void *)0x0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_004140b0 @ 0x004140b0 ====

void FUN_004140b0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_004140b0(*(undefined4 *)((int)param_1 + 8));
    FUN_0081f240();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004140f0 @ 0x004140f0 ====

void FUN_004140f0(void)

{
  FUN_00413700();
  return;
}


// ==== FUN_00414100 @ 0x00414100 ====

void FUN_00414100(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00413bd0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x39) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x39);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x39);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x39);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x39);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004138e0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004141c0 @ 0x004141c0 ====

void FUN_004141c0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004140b0(piVar6[1]);
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
    FUN_00413de0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00414280 @ 0x00414280 ====

void FUN_00414280(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00414100(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004142b0 @ 0x004142b0 ====

/* WARNING: Removing unreachable block (ram,0x004143c4) */
/* WARNING: Removing unreachable block (ram,0x004143d5) */
/* WARNING: Removing unreachable block (ram,0x004143de) */
/* WARNING: Removing unreachable block (ram,0x004143e1) */
/* WARNING: Removing unreachable block (ram,0x004143d1) */
/* WARNING: Removing unreachable block (ram,0x004143ef) */
/* WARNING: Removing unreachable block (ram,0x004143fc) */
/* WARNING: Removing unreachable block (ram,0x00414407) */
/* WARNING: Removing unreachable block (ram,0x00414403) */
/* WARNING: Removing unreachable block (ram,0x004143f7) */
/* WARNING: Removing unreachable block (ram,0x0041440a) */

void FUN_004142b0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  int *piVar7;
  int iVar8;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978958;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
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
  FUN_004dde50();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      piVar4 = (int *)FUN_004128f0(piVar7);
    }
    else {
      piVar4 = piVar6;
    }
    *puVar1 = piVar4;
  }
  iVar8 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar8 + 8) == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      uVar5 = FUN_0057dff0(piVar7);
      *(undefined4 *)(iVar8 + 8) = uVar5;
    }
    else {
      *(int **)(iVar8 + 8) = piVar6;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar4 = piVar6;
        if ((char)piVar7[8] != '\x01') break;
        piVar6 = (int *)*piVar4;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar4[2];
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar4 + 8) = 0;
            FUN_004bdf70(piVar4);
            piVar6 = (int *)piVar4[2];
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(*piVar6 + 0x20) == '\x01') && (*(char *)(piVar6[2] + 0x20) == '\x01'))
            goto LAB_004144db;
            if (*(char *)(piVar6[2] + 0x20) == '\x01') {
              *(undefined1 *)(*piVar6 + 0x20) = 1;
              *(undefined1 *)(piVar6 + 8) = 0;
              FUN_004bdfc0(piVar6);
              piVar6 = (int *)piVar4[2];
            }
            *(char *)(piVar6 + 8) = (char)piVar4[8];
            *(undefined1 *)(piVar4 + 8) = 1;
            *(undefined1 *)(piVar6[2] + 0x20) = 1;
            FUN_004bdf70(piVar4);
            break;
          }
        }
        else {
          if ((char)piVar6[8] == '\0') {
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(piVar4 + 8) = 0;
            FUN_004bdfc0(piVar4);
            piVar6 = (int *)*piVar4;
          }
          if (*(char *)((int)piVar6 + 0x21) == '\0') {
            if ((*(char *)(piVar6[2] + 0x20) != '\x01') || (*(char *)(*piVar6 + 0x20) != '\x01')) {
              if (*(char *)(*piVar6 + 0x20) == '\x01') {
                *(undefined1 *)(piVar6[2] + 0x20) = 1;
                *(undefined1 *)(piVar6 + 8) = 0;
                FUN_004bdf70(piVar6);
                piVar6 = (int *)*piVar4;
              }
              *(char *)(piVar6 + 8) = (char)piVar4[8];
              *(undefined1 *)(piVar4 + 8) = 1;
              *(undefined1 *)(*piVar6 + 0x20) = 1;
              FUN_004bdfc0(piVar4);
              break;
            }
LAB_004144db:
            *(undefined1 *)(piVar6 + 8) = 0;
          }
        }
        piVar6 = (int *)piVar4[1];
        piVar7 = piVar4;
      } while (piVar4 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 8) = 1;
  }
  iVar8 = param_2[5];
  if (iVar8 == 0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  iVar2 = param_2[6];
  if (iVar8 != iVar2) {
    piVar7 = (int *)(iVar8 + 8);
    do {
      iVar3 = *piVar7;
      if (iVar3 != 0) {
        FUN_00412910(iVar3,piVar7[2] - iVar3 >> 2);
      }
      *piVar7 = 0;
      piVar7[1] = 0;
      piVar7[2] = 0;
      iVar8 = iVar8 + 0x14;
      piVar7 = piVar7 + 5;
    } while (iVar8 != iVar2);
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_004145c0 @ 0x004145c0 ====

void FUN_004145c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_004145c0(*(undefined4 *)((int)param_1 + 8));
    FUN_004140f0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00414600 @ 0x00414600 ====

void FUN_00414600(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004141c0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00414630 @ 0x00414630 ====

void FUN_00414630(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004145c0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x21) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x21) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x21);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x21);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x21);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004142b0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004146f0 @ 0x004146f0 ====

void FUN_004146f0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00414630(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00414720 @ 0x00414720 ====

void FUN_00414720(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009789f8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00414630(local_10,**(undefined4 **)(in_ECX + 0x20),*(undefined4 **)(in_ECX + 0x20));
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_004147a0 @ 0x004147a0 ====

void FUN_004147a0(void)

{
  FUN_00414720();
  return;
}


// ==== FUN_004147b0 @ 0x004147b0 ====

/* WARNING: Removing unreachable block (ram,0x004148c3) */
/* WARNING: Removing unreachable block (ram,0x004148d3) */
/* WARNING: Removing unreachable block (ram,0x004148dc) */
/* WARNING: Removing unreachable block (ram,0x004148df) */
/* WARNING: Removing unreachable block (ram,0x004148cf) */
/* WARNING: Removing unreachable block (ram,0x004148ed) */
/* WARNING: Removing unreachable block (ram,0x004148fa) */
/* WARNING: Removing unreachable block (ram,0x00414905) */
/* WARNING: Removing unreachable block (ram,0x00414901) */
/* WARNING: Removing unreachable block (ram,0x004148f5) */
/* WARNING: Removing unreachable block (ram,0x00414908) */

void FUN_004147b0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978958;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x35) != '\0') {
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
  FUN_00411640();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
    if (*(char *)(param_2[2] + 0x35) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      piVar3 = (int *)FUN_0087c940(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      uVar4 = FUN_00868480(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xd] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xd] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_008685b0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(*piVar5 + 0x34) == '\x01') && (*(char *)(piVar5[2] + 0x34) == '\x01'))
            goto LAB_004149d5;
            if (*(char *)(piVar5[2] + 0x34) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              *(undefined1 *)(piVar5 + 0xd) = 0;
              FUN_00868600(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
            *(undefined1 *)(piVar3 + 0xd) = 1;
            *(undefined1 *)(piVar5[2] + 0x34) = 1;
            FUN_008685b0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_00868600(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(piVar5[2] + 0x34) != '\x01') || (*(char *)(*piVar5 + 0x34) != '\x01')) {
              if (*(char *)(*piVar5 + 0x34) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x34) = 1;
                *(undefined1 *)(piVar5 + 0xd) = 0;
                FUN_008685b0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
              *(undefined1 *)(piVar3 + 0xd) = 1;
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              FUN_00868600(piVar3);
              break;
            }
LAB_004149d5:
            *(undefined1 *)(piVar5 + 0xd) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xd) = 1;
  }
  FUN_00414720();
  _free(param_2);
  return;
}


// ==== FUN_00414a70 @ 0x00414a70 ====

void FUN_00414a70(void *param_1)

{
  if (*(char *)((int)param_1 + 0x35) == '\0') {
    FUN_00414a70(*(undefined4 *)((int)param_1 + 8));
    FUN_004147a0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00414ab0 @ 0x00414ab0 ====

void FUN_00414ab0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00414a70(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x35) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x35) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x35);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x35);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x35);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x35);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004147b0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00414b70 @ 0x00414b70 ====

void FUN_00414b70(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00414ab0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00414ba0 @ 0x00414ba0 ====

void FUN_00414ba0(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978a76;
  pvStack_c = ExceptionList;
  local_4 = 8;
  if (*(uint *)(in_ECX + 0xb8) < 0x10) {
    ExceptionList = &pvStack_c;
    *(undefined4 *)(in_ECX + 0xb8) = 0xf;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined1 *)(in_ECX + 0xa4) = 0;
    FUN_004141c0(local_10,**(undefined4 **)(in_ECX + 0x98),*(undefined4 **)(in_ECX + 0x98));
    _free(*(void **)(in_ECX + 0x98));
    return;
  }
  ExceptionList = &pvStack_c;
  _free(*(void **)(in_ECX + 0xa4));
  return;
}


// ==== FUN_00414d80 @ 0x00414d80 ====

void FUN_00414d80(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978ae6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  local_4 = 5;
  iVar1 = FUN_00412ce0();
  *(int *)(in_ECX + 0x70) = iVar1;
  *(undefined1 *)(iVar1 + 0x35) = 1;
  *(int *)(*(int *)(in_ECX + 0x70) + 4) = *(int *)(in_ECX + 0x70);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 0x70);
  *(int *)(*(int *)(in_ECX + 0x70) + 8) = *(int *)(in_ECX + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = 0;
  local_4._0_1_ = 6;
  iVar1 = FUN_004be420();
  *(int *)(in_ECX + 0x7c) = iVar1;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(int *)(*(int *)(in_ECX + 0x7c) + 4) = *(int *)(in_ECX + 0x7c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 0x7c);
  *(int *)(*(int *)(in_ECX + 0x7c) + 8) = *(int *)(in_ECX + 0x7c);
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  local_4 = CONCAT31(local_4._1_3_,8);
  iVar1 = FUN_00412d20();
  *(int *)(in_ECX + 0x98) = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(int *)(*(int *)(in_ECX + 0x98) + 4) = *(int *)(in_ECX + 0x98);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(in_ECX + 0x98);
  *(int *)(*(int *)(in_ECX + 0x98) + 8) = *(int *)(in_ECX + 0x98);
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0xf;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  *(undefined1 *)(in_ECX + 0xa4) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00414ea0 @ 0x00414ea0 ====

void FUN_00414ea0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009789b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d5dc;
  FUN_00414d80();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00414ef0 @ 0x00414ef0 ====

void FUN_00414ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00414f10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00414f10 @ 0x00414f10 ====

void FUN_00414f10(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009789b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d5dc;
  local_4 = 0;
  FUN_00414ba0();
  *in_ECX = &PTR_FUN_0099d408;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00414f60 @ 0x00414f60 ====

void FUN_00414f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d648;
  return;
}


// ==== FUN_00414f70 @ 0x00414f70 ====

void FUN_00414f70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d648;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00414f90 @ 0x00414f90 ====

void FUN_00414f90(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978bb3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d670;
  pvVar1 = operator_new(4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0043e170();
  }
  in_ECX[1] = uVar2;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a740 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a740 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00415030 @ 0x00415030 ====

undefined4 FUN_00415030(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined1 local_10 [16];
  
  if (*(int *)(in_ECX + 8) != 0) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    puVar1 = (undefined4 *)FUN_0043e6d0(local_10,param_1);
    local_20 = *puVar1;
    local_1c = puVar1[1];
    local_18 = puVar1[2];
    local_14 = puVar1[3];
    if (local_14 != 0) {
      uVar2 = FUN_0043fda0(param_2,local_14,local_1c);
      FUN_0043e340(&local_20);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_004150b0 @ 0x004150b0 ====

undefined4 FUN_004150b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined1 local_10 [16];
  
  if (*(int *)(in_ECX + 4) != 0) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    puVar1 = (undefined4 *)FUN_0043e260(local_10,param_1);
    local_20 = *puVar1;
    local_1c = puVar1[1];
    local_18 = puVar1[2];
    local_14 = puVar1[3];
    if (local_14 != 0) {
      uVar2 = FUN_0043fda0(param_2,local_14,local_1c);
      FUN_0043e190(&local_20);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00415130 @ 0x00415130 ====

void FUN_00415130(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978bc5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d670;
  DAT_00b5a740 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099d648;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_004151a0 @ 0x004151a0 ====

void FUN_004151a0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00415030(param_1,param_2);
  if (iVar1 == 0) {
    FUN_004150b0(param_1,param_2);
  }
  return;
}


// ==== FUN_004151d0 @ 0x004151d0 ====

undefined1 FUN_004151d0(undefined4 param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_retaddr;
  undefined1 *puVar3;
  undefined1 local_3c [4];
  undefined4 uStack_38;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978bdf;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00424930(100000);
  puVar3 = local_3c;
  local_4 = 0;
  (**(code **)(*param_2 + 0xc))(local_3c);
  FUN_004400d0();
  puStack_8._0_1_ = 1;
  if (*(uint *)(unaff_retaddr + 0x18) < 0x10) {
    iVar2 = unaff_retaddr + 4;
  }
  else {
    iVar2 = *(int *)(unaff_retaddr + 4);
  }
  FUN_00440100(iVar2,1);
  uVar1 = FUN_00440420(uStack_38,puVar3);
  FUN_00440260();
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  FUN_0043ff50();
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_00424910();
  ExceptionList = pvStack_10;
  return uVar1;
}


// ==== FUN_00415290 @ 0x00415290 ====

int * FUN_00415290(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *extraout_EAX;
  int *extraout_EAX_00;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978bf9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_00440910(local_44,param_1);
  local_4 = 0;
  piVar2 = (int *)FUN_00415030(uVar1,param_1);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x18))(1);
    ExceptionList = local_10;
    return piVar2;
  }
  uVar1 = FUN_004407f0(local_28,param_1);
  local_4 = 1;
  piVar2 = (int *)FUN_004150b0(uVar1,param_1);
  local_4 = 0xffffffff;
  if ((void *)0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x18))(1);
  }
  ExceptionList = local_c;
  return piVar2;
}


// ==== FUN_004153a0 @ 0x004153a0 ====

void FUN_004153a0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00415030(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_004150b0(param_1,param_2);
    if (iVar1 == 0) {
      FUN_00415290(param_2);
    }
  }
  return;
}


// ==== FUN_004153e0 @ 0x004153e0 ====

void FUN_004153e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978c1e;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_Framework__DriverKernel__Data__L_0099d600,0x42);
  local_4 = 0;
  FUN_00401870(local_44);
  local_4._0_1_ = 2;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  pvVar1 = operator_new(0x60);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0043ec70();
  }
  *(undefined4 *)(in_ECX + 8) = uVar2;
  local_4 = 0xffffffff;
  FUN_00401630();
  ExceptionList = local_c;
  return;
}


// ==== FUN_004154a0 @ 0x004154a0 ====

undefined1 FUN_004154a0(void)

{
  return 1;
}


// ==== FUN_004154b0 @ 0x004154b0 ====

void FUN_004154b0(void)

{
  return;
}


// ==== FUN_004154c0 @ 0x004154c0 ====

undefined4 FUN_004154c0(void)

{
  return 0;
}


// ==== FUN_004154d0 @ 0x004154d0 ====

void FUN_004154d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00415130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00415530 @ 0x00415530 ====

undefined1 FUN_00415530(undefined4 param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_retaddr;
  undefined1 *puVar3;
  undefined1 local_3c [4];
  undefined4 uStack_38;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978c40;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00424930(100000);
  puVar3 = local_3c;
  local_4 = 0;
  (**(code **)(*param_2 + 0xc))(local_3c);
  FUN_004400d0();
  puStack_8._0_1_ = 1;
  if (*(uint *)(unaff_retaddr + 0x18) < 0x10) {
    iVar2 = unaff_retaddr + 4;
  }
  else {
    iVar2 = *(int *)(unaff_retaddr + 4);
  }
  FUN_00440100(iVar2,1);
  uVar1 = FUN_00440420(uStack_38,puVar3);
  FUN_00440260();
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  FUN_0043ff50();
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_00424910();
  ExceptionList = pvStack_10;
  return uVar1;
}


// ==== FUN_004155f0 @ 0x004155f0 ====

int FUN_004155f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) && (iVar1 = thunk_FUN_004409a0(param_1), iVar1 != 0)) {
    return iVar1;
  }
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  iVar1 = FUN_00442720(param_1);
  return iVar1;
}


// ==== FUN_00415630 @ 0x00415630 ====

undefined4 FUN_00415630(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[3] != 0) {
    (**(code **)(*(int *)in_ECX[3] + 0xc))();
  }
  if (in_ECX[2] != 0) {
    piVar1 = (int *)thunk_FUN_004409a0(param_1);
    if (piVar1 != (int *)0x0) goto LAB_00415675;
  }
  if (in_ECX[1] != 0) {
    piVar1 = (int *)FUN_00442720(param_1);
    if (piVar1 != (int *)0x0) {
LAB_00415675:
      (**(code **)(*piVar1 + 0x14))();
      (**(code **)(*piVar1 + 0xc))();
      uVar2 = (**(code **)(*piVar1 + 0x10))(param_2);
      (**(code **)(*in_ECX + 0x1c))(piVar1);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_004156b0 @ 0x004156b0 ====

uint FUN_004156b0(int *param_1)

{
  int *_Memory;
  char cVar1;
  uint extraout_EAX;
  uint uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  if (*(int **)(in_ECX + 0xc) == param_1) {
    return 1;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x14);
  do {
    if (_Memory == *(int **)(in_ECX + 0x14)) {
LAB_0041570e:
      *(int **)(in_ECX + 0xc) = param_1;
      uVar2 = (**(code **)(*param_1 + 0x14))();
      if ((char)uVar2 == '\0') {
        return uVar2;
      }
      cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      return (uint)(cVar1 != '\0');
    }
    if ((int *)_Memory[2] == param_1) {
      if (_Memory != *(int **)(in_ECX + 0x14)) {
        *(int *)_Memory[1] = *_Memory;
        *(int *)(*_Memory + 4) = _Memory[1];
        _free(_Memory);
        return extraout_EAX;
      }
      goto LAB_0041570e;
    }
    _Memory = (int *)*_Memory;
  } while( true );
}


// ==== FUN_00415740 @ 0x00415740 ====

void FUN_00415740(int param_1)

{
  int *_Memory;
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == param_1) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x14);
  do {
    if (_Memory == *(int **)(in_ECX + 0x14)) {
LAB_0041578e:
      if (((*(int *)(in_ECX + 8) == 0) || (cVar1 = FUN_00440980(param_1), cVar1 != '\x01')) &&
         (*(int *)(in_ECX + 4) != 0)) {
        FUN_004426b0(param_1);
      }
      return;
    }
    if (_Memory[2] == param_1) {
      if (_Memory != *(int **)(in_ECX + 0x14)) {
        *(int *)_Memory[1] = *_Memory;
        *(int *)(*_Memory + 4) = _Memory[1];
        _free(_Memory);
        return;
      }
      goto LAB_0041578e;
    }
    _Memory = (int *)*_Memory;
  } while( true );
}


// ==== FUN_004157c0 @ 0x004157c0 ====

void FUN_004157c0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978c5d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d6ec;
  DAT_00b5a740 = 0;
  local_4 = 1;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  FUN_008984a0();
  *in_ECX = &PTR_FUN_0099d648;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00415840 @ 0x00415840 ====

void FUN_00415840(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    cVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
    if (cVar3 == '\0') {
      return;
    }
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  while( true ) {
    if ((iVar1 != 0) || (*(int *)(in_ECX + 0x18) == 0)) {
      return;
    }
    piVar2 = *(int **)(**(int **)(in_ECX + 0x14) + 8);
    *(int **)(in_ECX + 0xc) = piVar2;
    cVar3 = (**(code **)(*piVar2 + 0x14))();
    if ((cVar3 == '\0') || (cVar3 = (**(code **)(**(int **)(in_ECX + 0xc) + 8))(), cVar3 != '\0')) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
    piVar2 = (int *)**(int **)(in_ECX + 0x14);
    if (piVar2 != *(int **)(in_ECX + 0x14)) break;
    iVar1 = *(int *)(in_ECX + 0xc);
  }
  *(int *)piVar2[1] = *piVar2;
  *(int *)(*piVar2 + 4) = piVar2[1];
  _free(piVar2);
  return;
}


// ==== FUN_004158c0 @ 0x004158c0 ====

int * FUN_004158c0(undefined4 param_1)

{
  undefined4 uVar1;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int in_ECX;
  int *piVar2;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978c77;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_00440910(local_44,param_1);
  local_4 = 0;
  if (*(int *)(in_ECX + 8) == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)thunk_FUN_004409a0(uVar1);
  }
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x18))(1);
    ExceptionList = local_10;
    return piVar2;
  }
  uVar1 = FUN_004407f0(local_28,param_1);
  local_4 = 1;
  if (*(int *)(in_ECX + 4) == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00442720(uVar1);
  }
  local_4 = 0xffffffff;
  if ((void *)0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x18))(1);
  }
  ExceptionList = local_c;
  return piVar2;
}


// ==== FUN_004159e0 @ 0x004159e0 ====

void FUN_004159e0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978c9f;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d6ec;
  in_ECX[3] = 0;
  uVar1 = FUN_00415c90();
  in_ECX[5] = uVar1;
  in_ECX[6] = 0;
  local_4._0_1_ = 1;
  pvVar2 = operator_new(0x14);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00442980();
  }
  in_ECX[1] = uVar1;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a740 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a740 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00415a90 @ 0x00415a90 ====

void FUN_00415a90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) && (iVar1 = thunk_FUN_004409a0(param_1), iVar1 != 0)) {
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) || (iVar1 = FUN_00442720(param_1), iVar1 == 0)) {
    FUN_004158c0(param_2);
    return;
  }
  return;
}


// ==== FUN_00415ad0 @ 0x00415ad0 ====

undefined4 FUN_00415ad0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[3] != 0) {
    (**(code **)(*(int *)in_ECX[3] + 0xc))();
  }
  if (in_ECX[2] != 0) {
    piVar1 = (int *)thunk_FUN_004409a0(param_1);
    if (piVar1 != (int *)0x0) goto LAB_00415b15;
  }
  if (in_ECX[1] != 0) {
    piVar1 = (int *)FUN_00442720(param_1);
    if (piVar1 != (int *)0x0) goto LAB_00415b15;
  }
  piVar1 = (int *)FUN_004158c0(param_2);
LAB_00415b15:
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x14))();
  (**(code **)(*piVar1 + 0xc))();
  uVar2 = (**(code **)(*piVar1 + 0x10))(param_2);
  (**(code **)(*in_ECX + 0x1c))(piVar1);
  return uVar2;
}


// ==== FUN_00415b50 @ 0x00415b50 ====

void FUN_00415b50(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978cc4;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_Framework__DriverKernel__Data__L_0099d6a0,0x45);
  local_4 = 0;
  FUN_00401870(local_44);
  local_4._0_1_ = 2;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  pvVar1 = operator_new(0x78);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00441100();
  }
  *(undefined4 *)(in_ECX + 8) = uVar2;
  local_4 = 0xffffffff;
  FUN_00401630();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00415c10 @ 0x00415c10 ====

int FUN_00415c10(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x20))();
  uVar2 = param_1;
  if (in_ECX[2] != 0) {
    iVar3 = thunk_FUN_004409a0(param_1);
    if (iVar3 != 0) goto LAB_00415c4c;
  }
  if (in_ECX[1] != 0) {
    iVar3 = FUN_00442720(uVar2);
    if (iVar3 != 0) goto LAB_00415c4c;
  }
  iVar3 = FUN_004158c0(param_2);
LAB_00415c4c:
  if (iVar3 == 0) {
    return 0;
  }
  iVar1 = in_ECX[5];
  param_1 = iVar3;
  iVar4 = FUN_00448300(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00415cd0(1);
  *(int *)(iVar1 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  return iVar3;
}


// ==== FUN_00415c90 @ 0x00415c90 ====

void FUN_00415c90(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_00415cb0 @ 0x00415cb0 ====

void FUN_00415cb0(byte param_1)

{
  void *in_ECX;
  
  FUN_004157c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00415cd0 @ 0x00415cd0 ====

void FUN_00415cd0(uint param_1)

{
  int in_ECX;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978cd8;
  local_c = ExceptionList;
  if (0x3fffffffU - *(int *)(in_ECX + 8) < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_00415d70 @ 0x00415d70 ====

void FUN_00415d70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d76c;
  return;
}


// ==== FUN_00415d80 @ 0x00415d80 ====

void FUN_00415d80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d76c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00415da0 @ 0x00415da0 ====

uint FUN_00415da0(int param_1,int param_2)

{
  uint3 uVar2;
  uint uVar1;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar2 = (uint3)(uVar1 >> 8);
  if (*(uint *)(param_2 + 0x14) < uVar1) {
    return CONCAT31(uVar2,1);
  }
  if (uVar1 < *(uint *)(param_2 + 0x14)) {
    return (uint)uVar2 << 8;
  }
  uVar5 = uVar1 - 4;
  if (-1 < (int)uVar5) {
    while( true ) {
      if (*(uint *)(param_1 + 0x14) <= uVar5) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar3 = param_1 + 4;
      }
      else {
        iVar3 = *(int *)(param_1 + 4);
      }
      puVar4 = (undefined4 *)(param_1 + 4);
      if (*(uint *)(param_2 + 0x14) <= uVar5) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        uVar1 = param_2 + 4;
      }
      else {
        uVar1 = *(uint *)(param_2 + 4);
      }
      puVar6 = (undefined4 *)(param_2 + 4);
      if (*(char *)(uVar1 + uVar5) < *(char *)(uVar5 + iVar3)) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      if (*(uint *)(param_1 + 0x14) <= uVar5) {
        uVar1 = FUN_0079dba3();
      }
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (*(uint *)(param_2 + 0x14) <= uVar5) {
        uVar1 = FUN_0079dba3();
      }
      if (0xf < *(uint *)(param_2 + 0x18)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (*(char *)((int)puVar4 + uVar5) < *(char *)((int)puVar6 + uVar5)) break;
      uVar5 = uVar5 - 1;
      if ((int)uVar5 < 0) {
        return uVar1 & 0xffffff00;
      }
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00415e80 @ 0x00415e80 ====

undefined4 * FUN_00415e80(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar2 = *(char *)((int)puVar3 + 0x29);
  puVar1 = *(undefined4 **)(in_ECX + 4);
  while (cVar2 == '\0') {
    cVar2 = FUN_00415da0(puVar3 + 3,param_1);
    if (cVar2 == '\0') {
      puVar4 = (undefined4 *)*puVar3;
    }
    else {
      puVar4 = (undefined4 *)puVar3[2];
      puVar3 = puVar1;
    }
    puVar1 = puVar3;
    puVar3 = puVar4;
    cVar2 = *(char *)((int)puVar4 + 0x29);
  }
  return puVar1;
}


// ==== FUN_00415ec0 @ 0x00415ec0 ====

void FUN_00415ec0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 10) = 1;
  *(undefined1 *)((int)puVar1 + 0x29) = 0;
  return;
}


// ==== FUN_00415f00 @ 0x00415f00 ====

int FUN_00415f00(undefined1 param_1,void *param_2)

{
  char cVar1;
  int *piVar2;
  uint3 uVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  uint in_stack_0000001c;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978cf8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  local_14 = FUN_00415e80(&param_1);
  if (local_14 != *(int *)(in_ECX + 8)) {
    cVar1 = FUN_00415da0(&param_1,local_14 + 0xc);
    if (cVar1 == '\0') {
      piVar2 = &local_14;
      goto LAB_00415f61;
    }
  }
  local_10 = *(int *)(in_ECX + 8);
  piVar2 = &local_10;
LAB_00415f61:
  uVar3 = (uint3)((uint)*piVar2 >> 8);
  if (*piVar2 != *(int *)(in_ECX + 8)) {
    if (in_stack_0000001c < 0x10) {
      ExceptionList = local_c;
      return CONCAT31(uVar3,1);
    }
    _free(param_2);
    return extraout_EAX_00;
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return (uint)uVar3 << 8;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_00415fc0 @ 0x00415fc0 ====

undefined4 FUN_00415fc0(void)

{
  char cVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 local_4c [8];
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
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978d12;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_DXTAlphaFilterTable_txt_0099d74c,0x17);
  local_4 = 0;
  FUN_00410500(local_44);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_0049d760();
  FUN_0049d780();
  cVar1 = FUN_0049d7c0();
  while( true ) {
    if (cVar1 != '\0') {
      ExceptionList = local_c;
      return 1;
    }
    FUN_0049d800(local_28);
    local_4 = 1;
    FUN_004167b0(local_4c,local_28);
    local_4 = 0xffffffff;
    if (0xf < local_10) break;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_0049d780();
    cVar1 = FUN_0049d7c0();
  }
  _free(local_24);
  return extraout_EAX_00;
}


// ==== FUN_004160e0 @ 0x004160e0 ====

void FUN_004160e0(void)

{
  code *pcVar1;
  char cVar2;
  
  cVar2 = FUN_00415fc0();
  if (cVar2 == '\0') {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  return;
}


// ==== FUN_004160f0 @ 0x004160f0 ====

void FUN_004160f0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978d24;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d77c;
  DAT_00b5a6cc = 0;
  local_4 = 0;
  FUN_00416880(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00416170 @ 0x00416170 ====

void FUN_00416170(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978d41;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d77c;
  iVar3 = FUN_00415ec0();
  in_ECX[2] = iVar3;
  *(undefined1 *)(iVar3 + 0x29) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6cc = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6cc = in_ECX;
  }
  cVar2 = FUN_00415fc0();
  if (cVar2 == '\0') {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00416210 @ 0x00416210 ====

undefined4 *
FUN_00416210(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00978d61;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x2c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[9] = 0xf;
    puVar1[8] = 0;
    *(undefined1 *)(puVar1 + 4) = 0;
    FUN_00401660(param_4,0,0xffffffff);
    *(undefined1 *)(puVar1 + 10) = param_5;
    *(undefined1 *)((int)puVar1 + 0x29) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0041629b @ 0x0041629b ====

void Catch_0041629b(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004162c0 @ 0x004162c0 ====

void FUN_004162c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00978d78;
  local_c = ExceptionList;
  if (0x9249247 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00416210(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x28);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x28) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[10] == '\0') {
LAB_004163b9:
        *(undefined1 *)(*piVar5 + 0x28) = 1;
        *(undefined1 *)(piVar6 + 10) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x28) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004c9300(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x28) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x28) = 0;
        FUN_0043e2e0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[10] == '\0') goto LAB_004163b9;
      if (piVar7 == (int *)*piVar2) {
        FUN_0043e2e0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x28) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x28) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x29) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x28);
  } while( true );
}


// ==== FUN_004164a0 @ 0x004164a0 ====

/* WARNING: Removing unreachable block (ram,0x004165b0) */
/* WARNING: Removing unreachable block (ram,0x004165c1) */
/* WARNING: Removing unreachable block (ram,0x004165ca) */
/* WARNING: Removing unreachable block (ram,0x004165cd) */
/* WARNING: Removing unreachable block (ram,0x004165bd) */
/* WARNING: Removing unreachable block (ram,0x004165db) */
/* WARNING: Removing unreachable block (ram,0x004165e8) */
/* WARNING: Removing unreachable block (ram,0x004165f3) */
/* WARNING: Removing unreachable block (ram,0x004165ef) */
/* WARNING: Removing unreachable block (ram,0x004165e3) */
/* WARNING: Removing unreachable block (ram,0x004165f6) */

void FUN_004164a0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978d78;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x29) != '\0') {
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
  FUN_00798b00();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x29) == '\0') {
    if (*(char *)(param_2[2] + 0x29) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x29) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x29) == '\0') {
      piVar3 = (int *)FUN_00441380(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x29) == '\0') {
      uVar4 = FUN_0043e2c0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[10] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[10] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[10] == '\0') {
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(piVar3 + 10) = 0;
            FUN_004c9300(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            if ((*(char *)(*piVar5 + 0x28) == '\x01') && (*(char *)(piVar5[2] + 0x28) == '\x01'))
            goto LAB_004166c7;
            if (*(char *)(piVar5[2] + 0x28) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x28) = 1;
              *(undefined1 *)(piVar5 + 10) = 0;
              FUN_0043e2e0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 10) = (char)piVar3[10];
            *(undefined1 *)(piVar3 + 10) = 1;
            *(undefined1 *)(piVar5[2] + 0x28) = 1;
            FUN_004c9300(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[10] == '\0') {
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(piVar3 + 10) = 0;
            FUN_0043e2e0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            if ((*(char *)(piVar5[2] + 0x28) != '\x01') || (*(char *)(*piVar5 + 0x28) != '\x01')) {
              if (*(char *)(*piVar5 + 0x28) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x28) = 1;
                *(undefined1 *)(piVar5 + 10) = 0;
                FUN_004c9300(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 10) = (char)piVar3[10];
              *(undefined1 *)(piVar3 + 10) = 1;
              *(undefined1 *)(*piVar5 + 0x28) = 1;
              FUN_0043e2e0(piVar3);
              break;
            }
LAB_004166c7:
            *(undefined1 *)(piVar5 + 10) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 10) = 1;
  }
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


// ==== FUN_00416770 @ 0x00416770 ====

void FUN_00416770(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    FUN_00416770(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004167b0 @ 0x004167b0 ====

void FUN_004167b0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  uVar2 = param_2;
  puVar5 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar3 = '\x01';
  cVar4 = *(char *)((int)puVar5 + 0x29);
  puVar1 = *(undefined4 **)(in_ECX + 4);
  while (cVar4 == '\0') {
    cVar3 = FUN_00415da0(uVar2,puVar5 + 3);
    if (cVar3 == '\0') {
      puVar6 = (undefined4 *)puVar5[2];
    }
    else {
      puVar6 = (undefined4 *)*puVar5;
    }
    puVar1 = puVar5;
    puVar5 = puVar6;
    cVar4 = *(char *)((int)puVar6 + 0x29);
  }
  param_2 = puVar1;
  if (cVar3 != '\0') {
    if (puVar1 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_004162c0(&param_2,1,puVar1,uVar2);
      *param_1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00798b50();
  }
  puVar5 = param_2;
  cVar4 = FUN_00415da0(param_2 + 3,uVar2);
  if (cVar4 == '\0') {
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  puVar5 = (undefined4 *)FUN_004162c0(&param_2,cVar3,puVar1,uVar2);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00416880 @ 0x00416880 ====

void FUN_00416880(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00416770(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x29) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x29) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x29);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x29);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x29);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x29);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004164a0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00416940 @ 0x00416940 ====

void FUN_00416940(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00416880(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00416970 @ 0x00416970 ====

void FUN_00416970(byte param_1)

{
  void *in_ECX;
  
  FUN_004160f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00416990 @ 0x00416990 ====

void FUN_00416990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d7a8;
  return;
}


// ==== FUN_004169a0 @ 0x004169a0 ====

void FUN_004169a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d7a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004169d0 @ 0x004169d0 ====

int FUN_004169d0(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0x1c)) {
      iVar1 = *(int *)(in_ECX + 8);
      if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c) <= param_1)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      return iVar1 + param_1 * 0x1c;
    }
  }
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c != 0) {
      return iVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00416a70 @ 0x00416a70 ====

/* WARNING: Removing unreachable block (ram,0x00416ab9) */

void FUN_00416a70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d7b4;
  DAT_00b5a6d0 = 0;
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_0099d7a8;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00416af0 @ 0x00416af0 ====

/* WARNING: Removing unreachable block (ram,0x00416d31) */
/* WARNING: Removing unreachable block (ram,0x00416df5) */
/* WARNING: Removing unreachable block (ram,0x00416d1f) */
/* WARNING: Removing unreachable block (ram,0x00416ccd) */
/* WARNING: Removing unreachable block (ram,0x00416d3a) */
/* WARNING: Removing unreachable block (ram,0x00416d4c) */
/* WARNING: Removing unreachable block (ram,0x00416d59) */
/* WARNING: Removing unreachable block (ram,0x00416d79) */
/* WARNING: Removing unreachable block (ram,0x00416d89) */

void FUN_00416af0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_8e [10];
  undefined1 auStack_84 [4];
  void *pvStack_80;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  void *local_2c;
  undefined1 local_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978dc3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = FUN_00404890(local_60);
  local_4 = 0;
  uVar1 = FUN_004045b0(local_44,uVar1);
  local_4._0_1_ = 1;
  FUN_00402220(local_28,uVar1,s__protect_msg_0099d78c);
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (0xf < local_48) {
    _free(local_5c);
    return;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a740 + 4))(local_28,9);
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),in_ECX + 4,puVar2);
    _free(*(void **)(in_ECX + 8));
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  uStack_6c = 0xf;
  uStack_70 = 0;
  pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
  FUN_00401740(s_error_0099d79c,5);
  pvStack_c._0_1_ = 5;
  FUN_00406720(auStack_84);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  if (0xf < uStack_6c) {
    _free(pvStack_80);
    return;
  }
  if (puVar2 != (undefined4 *)0x0) {
    uVar5 = 0;
    iVar3 = FUN_00411430();
    if (iVar3 != 0) {
      do {
        if (uVar5 != 0) {
          pvStack_c._0_1_ = 6;
          uVar1 = FUN_00411510(uVar5);
          uStack_6c = 0xf;
          uStack_70 = 0;
          pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
          FUN_00401660(uVar1,0,0xffffffff);
          pvStack_c._0_1_ = 7;
          FUN_00404fb0(auStack_84,0x2c,auStack_8e + -6);
          if (0xf < uStack_6c) {
            _free(pvStack_80);
            return;
          }
          pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
          pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
          uStack_6c = 0xf;
          uStack_70 = 0;
        }
        uVar5 = uVar5 + 1;
        uVar4 = FUN_00411430();
      } while (uVar5 < uVar4);
    }
    (**(code **)*puVar2)(1);
  }
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00416e00 @ 0x00416e00 ====

void FUN_00416e00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978de0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d7b4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6d0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6d0 = in_ECX;
  }
  FUN_00416af0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00416e70 @ 0x00416e70 ====

void FUN_00416e70(byte param_1)

{
  void *in_ECX;
  
  FUN_00416a70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00416e90 @ 0x00416e90 ====

void FUN_00416e90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d870;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00416ed0 @ 0x00416ed0 ====

undefined4 FUN_00416ed0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00416ee0 @ 0x00416ee0 ====

undefined1 FUN_00416ee0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}


// ==== FUN_00416ef0 @ 0x00416ef0 ====

undefined4 FUN_00416ef0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00416f00 @ 0x00416f00 ====

undefined1 FUN_00416f00(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x48);
}


// ==== FUN_00416f10 @ 0x00416f10 ====

void FUN_00416f10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d890;
  DAT_00b5a6d4 = 0;
  if (0xf < (uint)in_ECX[0x11]) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[9] = 0;
    in_ECX[10] = 0xf;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_0099d870;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00416f70 @ 0x00416f70 ====

void FUN_00416f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d890;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  in_ECX[1] = 2;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6d4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a6d4 = in_ECX;
  return;
}


// ==== FUN_00417040 @ 0x00417040 ====

void FUN_00417040(void)

{
  int in_ECX;
  
  FUN_00401660(in_ECX + 0x10,0,0xffffffff);
  FUN_00401660(in_ECX + 0x2c,0,0xffffffff);
  return;
}


// ==== FUN_00417070 @ 0x00417070 ====

void FUN_00417070(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00978e00;
  local_c = ExceptionList;
  local_34 = (void *)0x0;
  local_30 = 0;
  local_2c = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00404fb0(param_1,0x2c,local_38);
  if (local_34 != (void *)0x0) {
    if ((local_30 - (int)local_34) / 0x1c == 2) {
      if (local_34 != (void *)0x0) {
        iVar2 = (local_30 - (int)local_34) / 0x1c;
        if (iVar2 != 0) {
          FUN_00401660(local_34,0,0xffffffff);
          if ((local_34 == (void *)0x0) || ((uint)((local_30 - (int)local_34) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          FUN_00401660((int)local_34 + 0x1c,0,0xffffffff);
          *(undefined1 *)(in_ECX + 0xc) = 1;
          *(undefined4 *)(in_ECX + 8) = 2;
          if (local_34 == (void *)0x0) {
            ExceptionList = local_c;
            return;
          }
          FUN_00405de0(local_34,local_30,local_38,iVar2);
          _free(local_34);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_tokenizedString_size______2_0099d850,0x1b);
  local_4._0_1_ = 1;
  FUN_00406880(local_28);
  local_4 = (uint)local_4._1_3_ << 8;
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004171f0 @ 0x004171f0 ====

void FUN_004171f0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined1 local_2d;
  undefined1 local_2c [4];
  void *local_28;
  int local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978e1a;
  local_c = ExceptionList;
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  local_2d = 0x2c;
  ExceptionList = &local_c;
  FUN_00417f70(0,1,&local_2d);
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00404b60(param_1,local_2c,local_1c);
  if (local_28 != (void *)0x0) {
    iVar1 = local_24 - (int)local_28 >> 0x1f;
    iVar3 = (local_24 - (int)local_28) / 0x1c + iVar1;
    if (iVar3 != iVar1) {
      if (*(int *)((int)local_28 + 0x14) != 0) {
        if ((uint)(iVar3 - iVar1) < 2) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        if (*(int *)((int)local_28 + 0x30) != 0) {
          uVar2 = FUN_00405d30(0);
          FUN_00401660(uVar2,0,0xffffffff);
          uVar2 = FUN_00405d30(1);
          FUN_00401660(uVar2,0,0xffffffff);
          *(undefined1 *)(in_ECX + 0xc) = 1;
          *(undefined4 *)(in_ECX + 8) = 1;
        }
      }
      if (local_28 != (void *)0x0) {
        FUN_00405de0(local_28,local_24,local_2c,param_1);
        _free(local_28);
        return;
      }
      local_28 = (void *)0x0;
      local_24 = 0;
      local_20 = 0;
      if (local_18 == (void *)0x0) {
        ExceptionList = local_c;
        return;
      }
      _free(local_18);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00417340 @ 0x00417340 ====

uint FUN_00417340(char *param_1)

{
  uint *puVar1;
  code *pcVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  undefined4 uVar6;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint extraout_EAX_09;
  uint extraout_EAX_10;
  uint extraout_EAX_11;
  uint extraout_EAX_12;
  uint extraout_EAX_13;
  uint extraout_EAX_14;
  uint extraout_EAX_15;
  uint extraout_EAX_16;
  uint extraout_EAX_17;
  uint extraout_EAX_18;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  char local_142;
  byte local_141;
  undefined1 local_140 [4];
  uint *local_13c;
  uint *local_138;
  undefined4 local_134;
  uint local_130;
  int local_12c;
  void *local_124;
  uint local_114;
  uint local_110;
  undefined1 local_10c [4];
  void *local_108;
  undefined1 *local_104;
  int local_100;
  undefined4 local_f8;
  uint local_f4;
  undefined1 local_f0 [4];
  void *local_ec;
  undefined4 local_dc;
  uint local_d8;
  undefined1 local_d4 [4];
  void *local_d0;
  undefined4 local_c0;
  uint local_bc;
  int local_b8;
  undefined1 local_b4 [4];
  void *local_b0;
  undefined4 local_a0;
  uint local_9c;
  undefined1 local_98 [4];
  void *local_94;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c [4];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  undefined1 local_60 [28];
  undefined1 local_44 [28];
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978fab;
  local_c = ExceptionList;
  uVar7 = 0;
  local_130 = 0;
  local_13c = (uint *)0x0;
  local_138 = (uint *)0x0;
  local_134 = 0;
  local_4 = 0;
  local_9c = 0xf;
  local_a0 = 0;
  local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  pcVar4 = param_1;
  do {
    cVar3 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar3 != '\0');
  ExceptionList = &local_c;
  FUN_00401740(param_1,(int)pcVar4 - (int)(param_1 + 1));
  local_4._0_1_ = 1;
  FUN_00405670(local_b4,local_140);
  uVar8 = 0;
  local_141 = 0;
  local_b8 = 0;
  do {
    if ((local_13c == (uint *)0x0) || ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8))
    goto LAB_00417b8d;
    local_110 = 0xf;
    local_114 = 0;
    local_124 = (void *)((uint)local_124 & 0xffffff00);
    FUN_00401660(local_b8 + (int)local_13c,0,0xffffffff);
    local_4._0_1_ = 2;
    if (local_114 < 4) {
LAB_00417496:
      local_142 = '\0';
    }
    else {
      iVar5 = FUN_00405b90(local_98,0,4);
      uVar7 = uVar7 | 1;
      local_4 = CONCAT31(local_4._1_3_,3);
      local_130 = uVar7;
      iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),&DAT_0099d7c0,4);
      local_142 = '\x01';
      if (iVar5 != 0) goto LAB_00417496;
    }
    local_4._0_1_ = 2;
    local_4._1_3_ = 0;
    if ((uVar7 & 1) != 0) {
      uVar7 = uVar7 & 0xfffffffe;
      if (0xf < local_80) {
        _free(local_94);
        return extraout_EAX;
      }
      local_80 = 0xf;
      local_84 = 0;
      local_94 = (void *)((uint)local_94 & 0xffffff00);
    }
    if (local_142 != '\0') {
      uVar8 = uVar8 + 1;
      if ((local_13c == (uint *)0x0) || ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8))
      {
        local_d8 = 0xf;
        local_dc = 0;
        local_ec = (void *)((uint)local_ec & 0xffffff00);
        FUN_00401740(s_tokenIndex_<_vecToken_size()_0099d7c8,0x1c);
        local_4._0_1_ = 4;
        FUN_00406880(local_f0);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (local_d8 < 0x10) {
          pcVar2 = (code *)swi(3);
          uVar7 = (*pcVar2)();
          return uVar7;
        }
        _free(local_ec);
        return extraout_EAX_05;
      }
      if ((local_13c == (uint *)0x0) || ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8))
      {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00417070(local_13c + uVar8 * 7);
joined_r0x00417b7c:
      if (0xf < local_110) {
        local_141 = 1;
        _free(local_124);
        return extraout_EAX_09;
      }
      local_141 = 1;
LAB_00417b8d:
      if (0xf < local_9c) {
        _free(local_b0);
        return extraout_EAX_10;
      }
      local_9c = 0xf;
      local_a0 = 0;
      local_b0 = (void *)((uint)local_b0 & 0xffffff00);
      if (local_13c == (uint *)0x0) {
        ExceptionList = local_c;
        return (uint)local_141;
      }
      if (local_13c != local_138) {
        puVar9 = local_13c + 6;
        do {
          if (0xf < *puVar9) {
            _free((void *)puVar9[-5]);
            return extraout_EAX_11;
          }
          *puVar9 = 0xf;
          puVar9[-1] = 0;
          *(undefined1 *)(puVar9 + -5) = 0;
          puVar1 = puVar9 + 1;
          puVar9 = puVar9 + 7;
        } while (puVar1 != local_138);
      }
      _free(local_13c);
      return extraout_EAX_12;
    }
    if (local_114 < 4) {
LAB_0041752b:
      local_142 = '\0';
    }
    else {
      iVar5 = FUN_00405b90(local_f0,0,4);
      uVar7 = uVar7 | 2;
      local_4 = CONCAT31(local_4._1_3_,5);
      local_130 = uVar7;
      iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),&DAT_0099d7e8,4);
      local_142 = '\x01';
      if (iVar5 != 0) goto LAB_0041752b;
    }
    local_4 = 2;
    if ((uVar7 & 2) != 0) {
      uVar7 = uVar7 & 0xfffffffd;
      if (0xf < local_d8) {
        _free(local_ec);
        return extraout_EAX_00;
      }
      local_d8 = 0xf;
      local_dc = 0;
      local_ec = (void *)((uint)local_ec & 0xffffff00);
    }
    if (local_142 != '\0') {
      if ((local_13c == (uint *)0x0) || ((uint)(((int)local_138 - (int)local_13c) / 0x1c) < 3)) {
        local_d8 = 0xf;
        local_dc = 0;
        local_ec = (void *)((uint)local_ec & 0xffffff00);
        FUN_00401740(s_vecToken_size___>__3_0099d7f0,0x14);
        local_4._0_1_ = 6;
        FUN_00406880(local_f0);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (local_d8 < 0x10) {
          pcVar2 = (code *)swi(3);
          uVar7 = (*pcVar2)();
          return uVar7;
        }
        _free(local_ec);
        return extraout_EAX_06;
      }
      if ((local_13c == (uint *)0x0) ||
         ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8 + 1)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_bc = 0xf;
      local_c0 = 0;
      local_d0 = (void *)((uint)local_d0 & 0xffffff00);
      FUN_00401660(local_13c + (uVar8 + 1) * 7,0,0xffffffff);
      local_4._0_1_ = 7;
      if ((local_13c == (uint *)0x0) ||
         ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8 + 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_f4 = 0xf;
      local_f8 = 0;
      local_108 = (void *)((uint)local_108 & 0xffffff00);
      FUN_00401660(local_13c + (uVar8 + 2) * 7,0,0xffffffff);
      local_4._0_1_ = 8;
      FUN_00401660(local_d4,0,0xffffffff);
      FUN_00401660(local_10c,0,0xffffffff);
      *(undefined1 *)(local_12c + 0xc) = 1;
      *(undefined4 *)(local_12c + 8) = 3;
      local_141 = 1;
      if (0xf < local_f4) {
        _free(local_108);
        return extraout_EAX_07;
      }
      local_f4 = 0xf;
      local_f8 = 0;
      local_108 = (void *)((uint)local_108 & 0xffffff00);
      if (0xf < local_bc) {
        _free(local_d0);
        return extraout_EAX_08;
      }
      local_bc = 0xf;
      local_c0 = 0;
      local_d0 = (void *)((uint)local_d0 & 0xffffff00);
      goto joined_r0x00417b7c;
    }
    if (local_114 < 8) {
LAB_004175b5:
      local_142 = '\0';
    }
    else {
      iVar5 = FUN_00405b90(local_d4,0,8);
      uVar7 = uVar7 | 4;
      local_4 = CONCAT31(local_4._1_3_,9);
      local_130 = uVar7;
      iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),s_acclaim__0099d808,8);
      local_142 = '\x01';
      if (iVar5 != 0) goto LAB_004175b5;
    }
    local_4 = 2;
    if ((uVar7 & 4) != 0) {
      uVar7 = uVar7 & 0xfffffffb;
      if (0xf < local_bc) {
        _free(local_d0);
        return extraout_EAX_01;
      }
      local_bc = 0xf;
      local_c0 = 0;
      local_d0 = (void *)((uint)local_d0 & 0xffffff00);
    }
    if (local_142 != '\0') {
      if ((local_13c == (uint *)0x0) || ((uint)(((int)local_138 - (int)local_13c) / 0x1c) < 3)) {
        local_80 = 0xf;
        local_84 = 0;
        local_94 = (void *)((uint)local_94 & 0xffffff00);
        FUN_00401740(s_vecToken_size___>__3_0099d814,0x14);
        local_4 = CONCAT31(local_4._1_3_,10);
        FUN_00406880(local_98);
        if (local_80 < 0x10) {
          pcVar2 = (code *)swi(3);
          uVar7 = (*pcVar2)();
          return uVar7;
        }
        _free(local_94);
        return extraout_EAX_13;
      }
      local_108 = (void *)0x0;
      local_104 = (undefined1 *)0x0;
      local_100 = 0;
      local_4 = 0xb;
      local_142 = ' ';
      FUN_00417f70(0,1,&local_142);
      local_142 = ',';
      if ((local_108 == (void *)0x0) ||
         ((uint)(local_100 - (int)local_108) <= (uint)((int)local_104 - (int)local_108))) {
        FUN_00417f70(local_104,1,&local_142);
      }
      else {
        *local_104 = 0x2c;
        local_104 = local_104 + 1;
      }
      FUN_00404b60(local_b4,local_140,local_10c);
      if ((local_13c == (uint *)0x0) ||
         ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8 + 1)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_d8 = 0xf;
      local_dc = 0;
      local_ec = (void *)((uint)local_ec & 0xffffff00);
      FUN_00401660(local_13c + (uVar8 + 1) * 7,0,0xffffffff);
      local_4._0_1_ = 0xc;
      if ((local_13c == (uint *)0x0) ||
         ((uint)(((int)local_138 - (int)local_13c) / 0x1c) <= uVar8 + 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_bc = 0xf;
      local_c0 = 0;
      local_d0 = (void *)((uint)local_d0 & 0xffffff00);
      FUN_00401660(local_13c + (uVar8 + 2) * 7,0,0xffffffff);
      local_4._0_1_ = 0xd;
      FUN_00401660(local_f0,0,0xffffffff);
      FUN_00401660(local_d4,0,0xffffffff);
      *(undefined1 *)(local_12c + 0xc) = 1;
      *(undefined4 *)(local_12c + 8) = 4;
      local_141 = 1;
      if (0xf < local_bc) {
        _free(local_d0);
        return extraout_EAX_14;
      }
      local_bc = 0xf;
      local_c0 = 0;
      local_d0 = (void *)((uint)local_d0 & 0xffffff00);
      if (0xf < local_d8) {
        _free(local_ec);
        return extraout_EAX_15;
      }
      local_d8 = 0xf;
      local_dc = 0;
      local_ec = (void *)((uint)local_ec & 0xffffff00);
      if (local_108 != (void *)0x0) {
        _free(local_108);
        return extraout_EAX_16;
      }
      local_108 = (void *)0x0;
      local_104 = (undefined1 *)0x0;
      local_100 = 0;
      goto joined_r0x00417b7c;
    }
    if (local_114 < 3) {
LAB_0041764b:
      local_142 = '\0';
    }
    else {
      iVar5 = FUN_00405b90(local_10c,0,3);
      uVar7 = uVar7 | 8;
      local_4 = CONCAT31(local_4._1_3_,0xe);
      local_130 = uVar7;
      iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),&DAT_0099d82c,3);
      local_142 = '\x01';
      if (iVar5 != 0) goto LAB_0041764b;
    }
    local_4 = 2;
    if ((uVar7 & 8) != 0) {
      uVar7 = uVar7 & 0xfffffff7;
      if (0xf < local_f4) {
        _free(local_108);
        return extraout_EAX_02;
      }
      local_f4 = 0xf;
      local_f8 = 0;
      local_108 = (void *)((uint)local_108 & 0xffffff00);
    }
    if (local_142 != '\0') {
      uVar6 = FUN_00405b90(local_7c,3,0xffffffff);
      local_4._0_1_ = 0xf;
      FUN_004171f0(uVar6);
      if (0xf < local_64) {
        _free(local_78);
        return extraout_EAX_17;
      }
      local_141 = 1;
      if (0xf < local_110) {
        _free(local_124);
        return extraout_EAX_18;
      }
      goto LAB_00417b8d;
    }
    if (local_114 < 2) {
LAB_004176ce:
      local_142 = '\0';
    }
    else {
      uVar6 = FUN_00405b90(local_7c,0,2);
      uVar7 = uVar7 | 0x10;
      local_4 = CONCAT31(local_4._1_3_,0x10);
      local_130 = uVar7;
      cVar3 = FUN_004036a0(uVar6,&DAT_0099d830);
      local_142 = '\x01';
      if (cVar3 == '\0') goto LAB_004176ce;
    }
    local_4 = 2;
    if ((uVar7 & 0x10) != 0) {
      uVar7 = uVar7 & 0xffffffef;
      if (0xf < local_64) {
        _free(local_78);
        return extraout_EAX_03;
      }
      local_64 = 0xf;
      local_68 = 0;
      local_78 = (void *)((uint)local_78 & 0xffffff00);
    }
    if (local_142 == '\0') {
      if (local_114 < 2) {
LAB_00417768:
        local_142 = '\0';
      }
      else {
        uVar6 = FUN_00405b90(local_60,0,2);
        uVar7 = uVar7 | 0x20;
        local_4 = CONCAT31(local_4._1_3_,0x11);
        local_130 = uVar7;
        cVar3 = FUN_004036a0(uVar6,&DAT_0099d834);
        local_142 = '\x01';
        if (cVar3 == '\0') goto LAB_00417768;
      }
      local_4 = 2;
      if ((uVar7 & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (local_142 == '\0') {
        if (local_114 < 8) {
LAB_004177e0:
          local_142 = '\0';
        }
        else {
          uVar6 = FUN_00405b90(local_44,0,8);
          uVar7 = uVar7 | 0x40;
          local_4 = CONCAT31(local_4._1_3_,0x12);
          local_130 = uVar7;
          cVar3 = FUN_004036a0(uVar6,s__testsvr_0099d838);
          local_142 = '\x01';
          if (cVar3 == '\0') goto LAB_004177e0;
        }
        local_4 = 2;
        if ((uVar7 & 0x40) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        if (local_142 == '\0') {
          if (local_114 < 10) {
LAB_00417852:
            local_142 = '\0';
          }
          else {
            uVar6 = FUN_00405b90(local_28,0,10);
            uVar7 = uVar7 | 0x80;
            local_4 = CONCAT31(local_4._1_3_,0x13);
            local_130 = uVar7;
            cVar3 = FUN_004036a0(uVar6,s__preceding_0099d844);
            local_142 = '\x01';
            if (cVar3 == '\0') goto LAB_00417852;
          }
          local_4 = 2;
          if ((char)uVar7 < '\0') {
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          if (local_142 != '\0') {
            local_141 = 1;
          }
        }
        else {
          *(undefined1 *)(local_12c + 0x48) = 1;
        }
      }
      else {
        *(undefined4 *)(local_12c + 4) = 1;
      }
    }
    else {
      *(undefined4 *)(local_12c + 4) = 0;
    }
    local_4._0_1_ = 1;
    local_4._1_3_ = 0;
    if (0xf < local_110) {
      _free(local_124);
      return extraout_EAX_04;
    }
    uVar8 = uVar8 + 1;
    local_b8 = local_b8 + 0x1c;
    local_110 = 0xf;
    local_114 = 0;
    local_124 = (void *)((uint)local_124 & 0xffffff00);
  } while( true );
}


// ==== FUN_00417f30 @ 0x00417f30 ====

void FUN_00417f30(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_1 = *param_3;
  }
  return;
}


// ==== FUN_00417f50 @ 0x00417f50 ====

void FUN_00417f50(byte param_1)

{
  void *in_ECX;
  
  FUN_00416f10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00417f70 @ 0x00417f70 ====

void FUN_00417f70(void *param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  int in_ECX;
  uint extraout_ECX;
  int iVar4;
  size_t sVar5;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 4);
  param_3 = (undefined1 *)CONCAT31(param_3._1_3_,*param_3);
  if (iVar1 == 0) {
    local_4 = 0;
  }
  else {
    local_4 = *(int *)(in_ECX + 0xc) - iVar1;
  }
  if (param_2 != 0) {
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar1;
    }
    if (-iVar4 - 1U < param_2) {
      iVar1 = FUN_00405d70();
      local_4 = extraout_ECX;
    }
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar1;
    }
    if (local_4 < iVar4 + param_2) {
      if (-(local_4 >> 1) - 1 < local_4) {
        local_4 = 0;
      }
      else {
        local_4 = local_4 + (local_4 >> 1);
      }
      if (iVar1 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - iVar1;
      }
      if (local_4 < iVar4 + param_2) {
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(in_ECX + 8) - iVar1;
        }
        local_4 = iVar1 + param_2;
      }
      pvVar2 = operator_new(local_4);
      sVar5 = (int)param_1 - (int)*(void **)(in_ECX + 4);
      pvVar3 = _memmove(pvVar2,*(void **)(in_ECX + 4),sVar5);
      pvVar3 = (void *)FUN_00469530((int)pvVar3 + sVar5,param_2,&param_3);
      _memmove(pvVar3,param_1,*(int *)(in_ECX + 8) - (int)param_1);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - (int)pvVar3;
      }
      if (pvVar3 == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = (int)pvVar2 + local_4;
        *(uint *)(in_ECX + 8) = (int)pvVar2 + param_2 + iVar1;
        *(void **)(in_ECX + 4) = pvVar2;
        return;
      }
      _free(pvVar3);
      return;
    }
    pvVar3 = *(void **)(in_ECX + 8);
    if ((uint)((int)pvVar3 - (int)param_1) < param_2) {
      _memmove((void *)(param_2 + (int)param_1),param_1,(int)pvVar3 - (int)param_1);
      FUN_00469530(*(int *)(in_ECX + 8),(int)param_1 + (param_2 - *(int *)(in_ECX + 8)),&param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2;
      FUN_00417f30(param_1,*(int *)(in_ECX + 8) - param_2,&param_3);
      return;
    }
    sVar5 = (int)pvVar3 - (int)((int)pvVar3 - param_2);
    pvVar2 = _memmove(pvVar3,(void *)((int)pvVar3 - param_2),sVar5);
    *(size_t *)(in_ECX + 8) = (int)pvVar2 + sVar5;
    sVar5 = (int)pvVar3 + (-param_2 - (int)param_1);
    _memmove((void *)((int)pvVar3 - sVar5),param_1,sVar5);
    FUN_00417f30(param_1,param_2 + (int)param_1,&param_3);
  }
  return;
}


// ==== __break @ 0x00418139 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00418140 @ 0x00418140 ====

void FUN_00418140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099de60;
  return;
}


// ==== FUN_00418150 @ 0x00418150 ====

void FUN_00418150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099de60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00418170 @ 0x00418170 ====

void FUN_00418170(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x68);
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_004181a0 @ 0x004181a0 ====

void FUN_004181a0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a6e4 = 0;
  *in_ECX = &PTR_FUN_0099de60;
  return;
}


// ==== FUN_004181c0 @ 0x004181c0 ====

void FUN_004181c0(undefined1 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int *in_ECX;
  int iVar7;
  float10 fVar8;
  void *unaff_retaddr;
  uint in_stack_00000014;
  void *in_stack_0000001c;
  undefined1 uStack00000020;
  uint in_stack_00000030;
  char *pcVar9;
  undefined **ppuVar10;
  undefined *puVar11;
  uint uVar12;
  undefined1 auStack_5c [4];
  void *pvStack_58;
  int iStack_54;
  undefined4 uStack_50;
  void *pvStack_48;
  undefined1 local_44 [12];
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978fe8;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_00405bd0(local_44,&param_1,&uStack00000020);
  local_4 = CONCAT31(local_4._1_3_,2);
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a740 + 4))(local_44,9);
  if (puVar3 == (undefined4 *)0x0) {
    (**(code **)(*in_ECX + 0x14))();
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    if (0xf < in_stack_00000014) {
      _free(unaff_retaddr);
      return;
    }
    if (0xf < in_stack_00000030) {
      _free(in_stack_0000001c);
      return;
    }
  }
  else {
    uVar12 = 0;
    iVar4 = FUN_00411430();
    if (iVar4 != 0) {
      do {
        pvStack_58 = (void *)0x0;
        iStack_54 = 0;
        uStack_50 = 0;
        pvStack_c._0_1_ = 3;
        uVar5 = FUN_00411510(uVar12);
        uStack_18 = 0xf;
        uStack_1c = 0;
        pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
        FUN_00401660(uVar5,0,0xffffffff);
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
        FUN_00405670(auStack_30,auStack_5c);
        if (pvStack_58 != (void *)0x0) {
          iVar4 = iStack_54 - (int)pvStack_58 >> 0x1f;
          iVar7 = (iStack_54 - (int)pvStack_58) / 0x1c + iVar4;
          if (1 < (uint)(iVar7 - iVar4)) {
            if (iVar7 == iVar4) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            iVar4 = FUN_00403620(0,*(undefined4 *)((int)pvStack_58 + 0x14),s_blood_0099d8b8,5);
            if (iVar4 == 0) {
              if ((pvStack_58 == (void *)0x0) || ((uint)((iStack_54 - (int)pvStack_58) / 0x1c) < 2))
              {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uVar1 = thunk_FUN_00796fe0((int)pvStack_58 + 0x1c);
              *(undefined1 *)(in_ECX + 1) = uVar1;
            }
            else {
              if ((pvStack_58 == (void *)0x0) || ((iStack_54 - (int)pvStack_58) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              iVar4 = FUN_00403620(0,*(undefined4 *)((int)pvStack_58 + 0x14),s_bloom_0099d8c0,5);
              if (iVar4 == 0) {
                if ((pvStack_58 == (void *)0x0) ||
                   ((uint)((iStack_54 - (int)pvStack_58) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
                  FUN_00405ca0();
                }
                uVar1 = thunk_FUN_00796fe0((int)pvStack_58 + 0x1c);
                *(undefined1 *)((int)in_ECX + 6) = uVar1;
              }
              else {
                if ((pvStack_58 == (void *)0x0) || ((iStack_54 - (int)pvStack_58) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_00405ca0();
                }
                iVar4 = FUN_00403620(0,*(undefined4 *)((int)pvStack_58 + 0x14),s_waterlevel_0099d8c8
                                     ,10);
                if (iVar4 == 0) {
                  uVar5 = FUN_00405d30(1);
                  uVar1 = thunk_FUN_00796f50(uVar5);
                  *(undefined1 *)((int)in_ECX + 0x62) = uVar1;
                }
                else {
                  pcVar9 = s_specular_0099d8d4;
                  uVar5 = FUN_00405d30(0);
                  cVar2 = FUN_004036a0(uVar5,pcVar9);
                  if (cVar2 == '\0') {
                    pcVar9 = s_trace_0099d8e0;
                    uVar5 = FUN_00405d30(0);
                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                    if (cVar2 == '\0') {
                      ppuVar10 = &PTR_LAB_0099d8e8;
                      uVar5 = FUN_00405d30(0);
                      cVar2 = FUN_004036a0(uVar5,ppuVar10);
                      if (cVar2 == '\0') {
                        pcVar9 = s_backsound2_0099d8ec;
                        uVar5 = FUN_00405d30(0);
                        cVar2 = FUN_004036a0(uVar5,pcVar9);
                        if (cVar2 == '\0') {
                          pcVar9 = s_effectsound_0099d8f8;
                          uVar5 = FUN_00405d30(0);
                          cVar2 = FUN_004036a0(uVar5,pcVar9);
                          if (cVar2 == '\0') {
                            pcVar9 = s_gamma_0099d904;
                            uVar5 = FUN_00405d30(0);
                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                            if (cVar2 == '\0') {
                              pcVar9 = s_mapalpha_0099d90c;
                              uVar5 = FUN_00405d30(0);
                              cVar2 = FUN_004036a0(uVar5,pcVar9);
                              if (cVar2 == '\0') {
                                pcVar9 = s_chatalpha_0099d918;
                                uVar5 = FUN_00405d30(0);
                                cVar2 = FUN_004036a0(uVar5,pcVar9);
                                if (cVar2 == '\0') {
                                  pcVar9 = s_minihelp_0099d924;
                                  uVar5 = FUN_00405d30(0);
                                  cVar2 = FUN_004036a0(uVar5,pcVar9);
                                  if (cVar2 == '\0') {
                                    pcVar9 = s_controltype_0099d930;
                                    uVar5 = FUN_00405d30(0);
                                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                                    if (cVar2 == '\0') {
                                      pcVar9 = s_display_0099d93c;
                                      uVar5 = FUN_00405d30(0);
                                      cVar2 = FUN_004036a0(uVar5,pcVar9);
                                      if (cVar2 == '\0') {
                                        puVar11 = &DAT_0099d944;
                                        uVar5 = FUN_00405d30(0);
                                        cVar2 = FUN_004036a0(uVar5,puVar11);
                                        if (cVar2 == '\0') {
                                          pcVar9 = s_quality_0099d94c;
                                          uVar5 = FUN_00405d30(0);
                                          cVar2 = FUN_004036a0(uVar5,pcVar9);
                                          if (cVar2 == '\0') {
                                            pcVar9 = s_tri_filter_0099d954;
                                            uVar5 = FUN_00405d30(0);
                                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                                            if (cVar2 == '\0') {
                                              pcVar9 = s_high_shadow_0099d960;
                                              uVar5 = FUN_00405d30(0);
                                              cVar2 = FUN_004036a0(uVar5,pcVar9);
                                              if (cVar2 == '\0') {
                                                pcVar9 = s_trade_mode_0099d96c;
                                                uVar5 = FUN_00405d30(0);
                                                cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                if (cVar2 == '\0') {
                                                  pcVar9 = s_party_mode_0099d978;
                                                  uVar5 = FUN_00405d30(0);
                                                  cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                  if (cVar2 == '\0') {
                                                    pcVar9 = s_guild_mode_0099d984;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                    if (cVar2 == '\0') {
                                                      pcVar9 = s_friend_mode_0099d990;
                                                      uVar5 = FUN_00405d30(0);
                                                      cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                      if (cVar2 == '\0') {
                                                        pcVar9 = s_servername_mode_0099d99c;
                                                        uVar5 = FUN_00405d30(0);
                                                        cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                        if (cVar2 == '\0') {
                                                          pcVar9 = s_reception_mode_0099d9ac;
                                                          uVar5 = FUN_00405d30(0);
                                                          cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                          if (cVar2 == '\0') {
                                                            pcVar9 = s_mainmenu_show_0099d9bc;
                                                            uVar5 = FUN_00405d30(0);
                                                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                            if (cVar2 == '\0') {
                                                              pcVar9 = s_quickslot_pos_0099d9cc;
                                                              uVar5 = FUN_00405d30(0);
                                                              cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                              if (cVar2 == '\0') {
                                                                pcVar9 = s_belt_pos_0099d9dc;
                                                                uVar5 = FUN_00405d30(0);
                                                                cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                                if (cVar2 == '\0') {
                                                                  pcVar9 = s_hp_pos_0099d9e8;
                                                                  uVar5 = FUN_00405d30(0);
                                                                  cVar2 = FUN_004036a0(uVar5,pcVar9)
                                                                  ;
                                                                  if (cVar2 == '\0') {
                                                                    pcVar9 = s_mp3_show_0099d9f0;
                                                                    uVar5 = FUN_00405d30(0);
                                                                    cVar2 = FUN_004036a0(uVar5,
                                                  pcVar9);
                                                  if (cVar2 == '\0') {
                                                    pcVar9 = s_mp3_volume_0099d9fc;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                    if (cVar2 == '\0') {
                                                      pcVar9 = s_mp3_loop_0099da08;
                                                      uVar5 = FUN_00405d30(0);
                                                      cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                      if (cVar2 == '\0') {
                                                        pcVar9 = s_pvprequest_0099da14;
                                                        uVar5 = FUN_00405d30(0);
                                                        cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                        if (cVar2 == '\0') {
                                                          pcVar9 = s_autoUsePotion_0099da20;
                                                          uVar5 = FUN_00405d30(0);
                                                          cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                          if (cVar2 == '\0') {
                                                            pcVar9 = s_useHpPotionRatio_0099da30;
                                                            uVar5 = FUN_00405d30(0);
                                                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                            if (cVar2 == '\0') {
                                                              pcVar9 = s_useMpPotionRatio_0099da44;
                                                              uVar5 = FUN_00405d30(0);
                                                              cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                              if (cVar2 == '\0') {
                                                                pcVar9 = s_covermap_0099da58;
                                                                uVar5 = FUN_00405d30(0);
                                                                cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                                if (cVar2 == '\0') {
                                                                  pcVar9 = s_bumpmap_0099da64;
                                                                  uVar5 = FUN_00405d30(0);
                                                                  cVar2 = FUN_004036a0(uVar5,pcVar9)
                                                                  ;
                                                                  if (cVar2 == '\0') {
                                                                    pcVar9 = s_shadowlevel_0099da6c;
                                                                    uVar5 = FUN_00405d30(0);
                                                                    cVar2 = FUN_004036a0(uVar5,
                                                  pcVar9);
                                                  if (cVar2 == '\0') {
                                                    pcVar9 = s_clipfar_0099da78;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                                                    if (cVar2 == '\0') {
                                                      puVar11 = &DAT_0099da80;
                                                      uVar5 = FUN_00405d30(0);
                                                      cVar2 = FUN_004036a0(uVar5,puVar11);
                                                      if (cVar2 != '\0') {
                                                        uVar5 = FUN_00405d30(1);
                                                        uVar1 = thunk_FUN_00796fe0(uVar5);
                                                        *(undefined1 *)((int)in_ECX + 0x67) = uVar1;
                                                      }
                                                    }
                                                    else {
                                                      uVar5 = FUN_00405d30(1);
                                                      fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      in_ECX[9] = (int)(float)fVar8;
                                                    }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796f50(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 99) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0x66) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0x65) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    in_ECX[0x14] = (int)(float)fVar8;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    in_ECX[0x13] = (int)(float)fVar8;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(in_ECX + 5) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0x13) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796f50(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0x61) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    in_ECX[0x10] = (int)(float)fVar8;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(in_ECX + 0x11) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    iVar4 = thunk_FUN_00796e60(uVar5);
                                                    in_ECX[0xe] = iVar4;
                                                    uVar5 = FUN_00405d30(2);
                                                    iVar4 = thunk_FUN_00796e60(uVar5);
                                                    in_ECX[0xf] = iVar4;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    iVar4 = thunk_FUN_00796e60(uVar5);
                                                    in_ECX[0xc] = iVar4;
                                                    uVar5 = FUN_00405d30(2);
                                                    iVar4 = thunk_FUN_00796e60(uVar5);
                                                    in_ECX[0xd] = iVar4;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    iVar4 = thunk_FUN_00796e60(uVar5);
                                                    in_ECX[10] = iVar4;
                                                    uVar5 = FUN_00405d30(2);
                                                    iVar4 = thunk_FUN_00796e60(uVar5);
                                                    in_ECX[0xb] = iVar4;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0x12) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0x11) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(in_ECX + 4) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0xf) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0xe) = uVar1;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)in_ECX + 0xd) = uVar1;
                                                  }
                                                }
                                                else {
                                                  uVar5 = FUN_00405d30(1);
                                                  uVar1 = thunk_FUN_00796fe0(uVar5);
                                                  *(undefined1 *)(in_ECX + 3) = uVar1;
                                                }
                                              }
                                              else {
                                                uVar5 = FUN_00405d30(1);
                                                uVar1 = thunk_FUN_00796fe0(uVar5);
                                                *(undefined1 *)((int)in_ECX + 0xb) = uVar1;
                                              }
                                            }
                                            else {
                                              uVar5 = FUN_00405d30(1);
                                              uVar1 = thunk_FUN_00796fe0(uVar5);
                                              *(undefined1 *)((int)in_ECX + 10) = uVar1;
                                            }
                                          }
                                          else {
                                            uVar5 = FUN_00405d30(1);
                                            uVar6 = thunk_FUN_00796f80(uVar5);
                                            in_ECX[0x12] = uVar6 & 0xffff;
                                          }
                                        }
                                        else {
                                          uVar5 = FUN_00405d30(1);
                                          uVar1 = thunk_FUN_00796fe0(uVar5);
                                          *(undefined1 *)((int)in_ECX + 9) = uVar1;
                                        }
                                      }
                                      else {
                                        uVar5 = FUN_00405d30(1);
                                        iVar4 = thunk_FUN_00796fb0(uVar5);
                                        in_ECX[0x15] = iVar4;
                                        uVar5 = FUN_00405d30(2);
                                        iVar4 = thunk_FUN_00796fb0(uVar5);
                                        in_ECX[0x16] = iVar4;
                                        uVar5 = FUN_00405d30(3);
                                        uVar1 = thunk_FUN_00796f50(uVar5);
                                        *(undefined1 *)(in_ECX + 0x18) = uVar1;
                                      }
                                    }
                                    else {
                                      uVar5 = FUN_00405d30(1);
                                      uVar1 = thunk_FUN_00796f50(uVar5);
                                      *(undefined1 *)((int)in_ECX + 0x5f) = uVar1;
                                    }
                                  }
                                  else {
                                    uVar5 = FUN_00405d30(1);
                                    uVar1 = thunk_FUN_00796fe0(uVar5);
                                    *(undefined1 *)(in_ECX + 2) = uVar1;
                                  }
                                }
                                else {
                                  uVar5 = FUN_00405d30(1);
                                  uVar1 = thunk_FUN_00796f50(uVar5);
                                  *(undefined1 *)((int)in_ECX + 0x5e) = uVar1;
                                }
                              }
                              else {
                                uVar5 = FUN_00405d30(1);
                                uVar1 = thunk_FUN_00796f50(uVar5);
                                *(undefined1 *)((int)in_ECX + 0x5d) = uVar1;
                              }
                            }
                            else {
                              uVar5 = FUN_00405d30(1);
                              fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                              in_ECX[8] = (int)(float)fVar8;
                            }
                          }
                          else {
                            uVar5 = FUN_00405d30(1);
                            fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                            in_ECX[7] = (int)(float)fVar8;
                          }
                        }
                        else {
                          uVar5 = FUN_00405d30(1);
                          fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                          in_ECX[6] = (int)(float)fVar8;
                        }
                      }
                      else {
                        uVar5 = FUN_00405d30(1);
                        uVar1 = thunk_FUN_00796f50(uVar5);
                        *(undefined1 *)(in_ECX + 0x19) = uVar1;
                      }
                    }
                    else {
                      uVar5 = FUN_00405d30(1);
                      uVar1 = thunk_FUN_00796f50(uVar5);
                      *(undefined1 *)(in_ECX + 0x17) = uVar1;
                    }
                  }
                  else {
                    uVar5 = FUN_00405d30(1);
                    uVar1 = thunk_FUN_00796fe0(uVar5);
                    *(undefined1 *)((int)in_ECX + 7) = uVar1;
                  }
                }
              }
            }
          }
        }
        if (0xf < uStack_18) {
          _free(pvStack_2c);
          return;
        }
        uStack_18 = 0xf;
        uStack_1c = 0;
        pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
        if (pvStack_58 != (void *)0x0) {
          FUN_00405de0(pvStack_58,iStack_54,auStack_5c,local_4);
          _free(pvStack_58);
          return;
        }
        uVar12 = uVar12 + 1;
        pvStack_58 = (void *)0x0;
        iStack_54 = 0;
        uStack_50 = 0;
        uVar6 = FUN_00411430();
      } while (uVar12 < uVar6);
    }
    (**(code **)*puVar3)(1);
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    if (0xf < in_stack_00000014) {
      _free(unaff_retaddr);
      return;
    }
    if (0xf < in_stack_00000030) {
      _free(in_stack_0000001c);
      return;
    }
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00418d10 @ 0x00418d10 ====

void FUN_00418d10(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_7c [4];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097901d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00404890();
  local_4 = 0;
  FUN_004045b0();
  local_4._0_1_ = 2;
  if (0xf < local_48) {
    _free(local_5c);
    return;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_004046f0();
  local_4._0_1_ = 3;
  FUN_00402220();
  local_4._0_1_ = 5;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401660();
  local_4._0_1_ = 6;
  FUN_00401660(local_7c,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,5);
  FUN_004181c0();
  puVar2 = in_ECX + 0x1a;
  for (iVar1 = 0x19; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *in_ECX;
    puVar2 = puVar2 + 1;
  }
  if (0xf < local_64) {
    _free(local_78);
    return;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00418ea0 @ 0x00418ea0 ====

void FUN_00418ea0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_a4 [4];
  void *local_a0;
  undefined4 local_90;
  uint local_8c;
  undefined **local_88;
  undefined4 local_78;
  undefined4 local_74;
  void *local_70;
  undefined4 uStack_60;
  uint uStack_5c;
  void *local_4c;
  undefined4 local_3c;
  void *local_38;
  uint uStack_24;
  void *pvStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00979212;
  pvStack_14 = ExceptionList;
  puVar2 = in_ECX + 0x1a;
  ExceptionList = &pvStack_14;
  for (iVar1 = 0x19; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *puVar2;
    puVar2 = puVar2 + 1;
  }
  FUN_00404890();
  local_c = 0;
  FUN_004045b0();
  local_c._0_1_ = 2;
  if (0xf < local_38) {
    _free(local_4c);
    return;
  }
  local_38 = (void *)0xf;
  local_3c = 0;
  local_4c = (void *)((uint)local_4c & 0xffffff00);
  FUN_004046f0();
  local_c._0_1_ = 3;
  FUN_00402220();
  local_c._0_1_ = 5;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  local_8c = 0xf;
  local_90 = 0;
  local_a0 = (void *)((uint)local_a0 & 0xffffff00);
  FUN_004020e0();
  local_88 = &PTR_FUN_0099d55c;
  local_78 = 0;
  local_74 = 0;
  local_70 = (void *)0x0;
  local_c._0_1_ = 7;
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 8;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 9;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 10;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0xb;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0xc;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0xd;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0xe;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0xf;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740(s_backsound2___2f_0099db3c);
  FUN_00404230();
  local_c._0_1_ = 0x10;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740(s_effectsound___2f_0099db4c);
  FUN_00404230();
  local_c._0_1_ = 0x11;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740(s_gamma___2f_0099db60);
  FUN_00404230();
  local_c._0_1_ = 0x12;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740(s_clipfar___2f_0099db6c);
  FUN_00404230();
  local_c._0_1_ = 0x13;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x14;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x15;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x16;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740(s_display__d__d__d_0099dba8,0x11);
  FUN_00404230(local_a4);
  local_c._0_1_ = 0x17;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x18;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x19;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x1a;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x1b;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x1c;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x1d;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x1e;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x1f;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401740();
  FUN_00404230();
  local_c._0_1_ = 0x20;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x21;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x22;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x23;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x24;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x25;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x26;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x27;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x28;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x29;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x2a;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x2b;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x2c;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x2d;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x2e;
  FUN_00411630();
  local_c._0_1_ = 7;
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  FUN_00401830();
  FUN_00404230();
  local_c._0_1_ = 0x2f;
  FUN_00411630();
  local_c = CONCAT31(local_c._1_3_,7);
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  (**(code **)(*DAT_00b5a740 + 0xc))();
  FUN_004137c0();
  if (0xf < uStack_5c) {
    _free(local_70);
    return;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_1c;
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_00419f10 @ 0x00419f10 ====

void FUN_00419f10(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979224;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099de8c;
  FUN_00419fb0();
  FUN_00419fb0();
  FUN_00418d10(param_1);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6e4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6e4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00419fa0 @ 0x00419fa0 ====

void FUN_00419fa0(void)

{
  return;
}


// ==== FUN_00419fb0 @ 0x00419fb0 ====

void FUN_00419fb0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *in_ECX;
  
  uVar1 = DAT_0099de84;
  uVar2 = DAT_0099de80;
  *(undefined4 *)(in_ECX + 0x24) = 0x76;
  *(undefined4 *)(in_ECX + 0x28) = 0xffffffc5;
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x30) = 0xffffffc5;
  *(undefined4 *)(in_ECX + 0x1c) = uVar1;
  uVar1 = DAT_0099de7c;
  *(undefined4 *)(in_ECX + 0x38) = 0xffffffb1;
  *(undefined4 *)(in_ECX + 0x34) = 0x226;
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  uVar1 = DAT_0099de78;
  in_ECX[0x5f] = 2;
  in_ECX[0x58] = 2;
  *(undefined4 *)(in_ECX + 0x44) = 2;
  in_ECX[0x5d] = 2;
  *in_ECX = 1;
  in_ECX[1] = 0;
  in_ECX[2] = 1;
  in_ECX[3] = 1;
  in_ECX[4] = 1;
  in_ECX[0x60] = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  in_ECX[0x59] = 0xff;
  in_ECX[0x5a] = 0x50;
  in_ECX[0x5b] = 1;
  *(undefined4 *)(in_ECX + 0x50) = 0x400;
  *(undefined4 *)(in_ECX + 0x54) = 0x300;
  in_ECX[0x5c] = 0x10;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[5] = 1;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 1;
  in_ECX[0xd] = 1;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  in_ECX[0xe] = 1;
  *(undefined4 *)(in_ECX + 0x3c) = uVar1;
  in_ECX[0x40] = 1;
  in_ECX[0xf] = 1;
  in_ECX[0x10] = 1;
  *(undefined4 *)(in_ECX + 0x48) = uVar2;
  *(undefined4 *)(in_ECX + 0x4c) = uVar2;
  in_ECX[0x5e] = 1;
  in_ECX[0x61] = 1;
  in_ECX[0x62] = 0;
  in_ECX[99] = 0;
  return;
}


// ==== FUN_0041a0a0 @ 0x0041a0a0 ====

int FUN_0041a0a0(void)

{
  int in_ECX;
  
  return in_ECX + 0x68;
}


// ==== FUN_0041a0b0 @ 0x0041a0b0 ====

void FUN_0041a0b0(byte param_1)

{
  void *in_ECX;
  
  FUN_004181a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0041a0d0 @ 0x0041a0d0 ====

void FUN_0041a0d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e13c;
  return;
}


// ==== FUN_0041a0e0 @ 0x0041a0e0 ====

void FUN_0041a0e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e13c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0041a110 @ 0x0041a110 ====

uint FUN_0041a110(int param_1)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 5;
  iVar3 = 0;
  if (*(int *)(param_1 + 0x14) != 5) {
    return in_EAX & 0xffff0000;
  }
  uVar4 = 0;
  do {
    if (*(uint *)(param_1 + 0x14) <= uVar4) {
      FUN_0079dba3();
    }
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar1 = param_1 + 4;
    }
    else {
      iVar1 = *(int *)(param_1 + 4);
    }
    iVar1 = CONCAT22((short)((uint)iVar1 >> 0x10),(short)*(char *)(uVar4 + iVar1)) + -0x30 <<
            ((byte)uVar4 & 0x1f);
    iVar3 = iVar3 + iVar1;
    iVar2 = iVar2 + -1;
    uVar4 = uVar4 + 1;
  } while (iVar2 != 0);
  return CONCAT22((short)((uint)iVar1 >> 0x10),(short)iVar3);
}


// ==== FUN_0041a170 @ 0x0041a170 ====

int FUN_0041a170(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)**(int **)(in_ECX + 8);
  *(int **)(in_ECX + 0x28) = piVar1;
  if (piVar1 == *(int **)(in_ECX + 8)) {
    return 0;
  }
  return (int)(piVar1 + 4);
}


// ==== FUN_0041a190 @ 0x0041a190 ====

int FUN_0041a190(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != *(int *)(in_ECX + 8)) {
    FUN_0041e0c0();
    if (*(int *)(in_ECX + 0x28) != *(int *)(in_ECX + 8)) {
      return *(int *)(in_ECX + 0x28) + 0x10;
    }
  }
  return 0;
}


// ==== FUN_0041a1c0 @ 0x0041a1c0 ====

void FUN_0041a1c0(undefined4 param_1,int param_2,float param_3)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  param_3 = DAT_00adbeec * param_3;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_0099e098,1);
  if (iVar1 == 0) {
    local_2c = DAT_0099d080;
    local_28 = 0;
    local_24 = 0;
    thunk_FUN_007a095f(&local_10,&local_2c,param_3);
  }
  else {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_0099e09c,1);
    if (iVar1 == 0) {
      local_2c = 0;
      local_28 = DAT_0099d080;
      local_24 = 0;
      thunk_FUN_007a095f(&local_10,&local_2c,param_3);
    }
    else {
      iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_0099e0a0,1);
      if (iVar1 == 0) {
        local_2c = 0;
        local_28 = 0;
        local_24 = DAT_0099d080;
        thunk_FUN_007a095f(&local_10,&local_2c,param_3);
      }
      else {
        local_8 = (undefined4 *)0x0;
        local_c = 0;
        local_10 = 0;
        local_4 = DAT_0099d080;
      }
    }
  }
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_14 = DAT_0099d080;
  thunk_FUN_007a0af7(&local_20,&local_20,&local_10);
  *local_8 = local_2c;
  local_8[1] = local_28;
  local_8[2] = local_24;
  local_8[3] = local_20;
  return;
}


// ==== FUN_0041a350 @ 0x0041a350 ====

int FUN_0041a350(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = (int *)FUN_0041e8a0(local_4,&param_1);
  if (*piVar1 == *(int *)(in_ECX + 0x184)) {
    return 0;
  }
  return *piVar1 + 0x10;
}


// ==== FUN_0041a390 @ 0x0041a390 ====

int FUN_0041a390(byte param_1,uint param_2,undefined4 param_3)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009792c8;
  local_c = ExceptionList;
  if ((short)param_3 == 0) {
    return in_ECX + 0x1a4 + ((uint)param_1 * 5 + (param_2 & 0xff)) * 0x11c;
  }
  _param_1 = param_3;
  ExceptionList = &local_c;
  FUN_0041e730(&param_2,&param_1);
  if (param_2 != *(uint *)(in_ECX + 8)) {
    ExceptionList = local_c;
    return param_2 + 0x10;
  }
  FUN_00401830(s_GFALSE_0099e028);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_0041a460 @ 0x0041a460 ====

int FUN_0041a460(byte param_1,undefined1 param_2,undefined1 *param_3)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int in_ECX;
  int local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009792da;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041e7b0(&local_2c,&param_2);
  if (local_2c != *(int *)(in_ECX + 400)) {
    *param_3 = *(undefined1 *)(local_2c + 0x178);
    ExceptionList = local_c;
    return local_2c + 0x10 + (uint)param_1 * 0x3c;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_GFALSE_0099e030,6);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_0041a520 @ 0x0041a520 ====

int FUN_0041a520(uint param_1)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  int in_ECX;
  int local_48;
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
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009792f4;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0x18) == 0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_m_mapMoney_empty______GFALSE_0099e038,0x1c);
    local_4 = 0;
    FUN_00406880(local_44);
    local_4 = 0xffffffff;
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
    _free(local_40);
    return extraout_EAX;
  }
  if (param_1 < 10) {
    param_1 = 0;
  }
  else if (param_1 < 100) {
    param_1 = 1;
  }
  else if (param_1 < 1000) {
    param_1 = 2;
  }
  else {
    param_1 = 4 - (uint)(param_1 < 10000);
  }
  ExceptionList = &local_c;
  FUN_0041e730(&local_48,&param_1);
  if (local_48 != *(int *)(in_ECX + 0x14)) {
    ExceptionList = local_c;
    return local_48 + 0x10;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_GFALSE_0099e058,6);
  local_4 = 1;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_24);
  return extraout_EAX_00;
}


// ==== FUN_0041a650 @ 0x0041a650 ====

int FUN_0041a650(undefined1 param_1)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  int in_ECX;
  int local_48;
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
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097930e;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0x24) == 0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_m_mapPortal_empty______GFALSE_0099e060,0x1d);
    local_4 = 0;
    FUN_00406880(local_44);
    local_4 = 0xffffffff;
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
    _free(local_40);
    return extraout_EAX;
  }
  ExceptionList = &local_c;
  FUN_0041e730(&local_48,&param_1);
  if (local_48 != *(int *)(in_ECX + 0x20)) {
    ExceptionList = local_c;
    return local_48 + 0x10;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_GFALSE_0099e080,6);
  local_4 = 1;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_24);
  return extraout_EAX_00;
}


// ==== FUN_0041a750 @ 0x0041a750 ====

int FUN_0041a750(int param_1,undefined1 param_2)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979320;
  local_c = ExceptionList;
  if (param_1 == 0) {
    ExceptionList = &local_c;
    piVar1 = (int *)FUN_0041e730(&param_1,&param_2);
    iVar2 = *piVar1;
    if (iVar2 == *(int *)(in_ECX + 8)) {
      ExceptionList = local_c;
      return 0;
    }
  }
  else if (param_1 == 1) {
    ExceptionList = &local_c;
    piVar1 = (int *)FUN_0041e730(&param_1,&param_2);
    iVar2 = *piVar1;
    if (iVar2 == *(int *)(in_ECX + 0x14)) {
      ExceptionList = local_c;
      return 0;
    }
  }
  else {
    if (param_1 != 2) {
      ExceptionList = &local_c;
      FUN_00401830(s_GFALSE_0099e088);
      local_4 = 0;
      FUN_00406880(local_28);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    ExceptionList = &local_c;
    piVar1 = (int *)FUN_0041e730(&param_1,&param_2);
    iVar2 = *piVar1;
    if (iVar2 == *(int *)(in_ECX + 0x20)) {
      ExceptionList = local_c;
      return 0;
    }
  }
  ExceptionList = local_c;
  return iVar2 + 0x10;
}


// ==== FUN_0041a850 @ 0x0041a850 ====

int FUN_0041a850(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = 0;
  switch(param_1) {
  case 0:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0x34)) {
      return 0;
    }
    break;
  case 1:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0x5c)) {
      return 0;
    }
    break;
  case 2:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0x84)) {
      return 0;
    }
    break;
  case 3:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0xac)) {
      return 0;
    }
    break;
  case 4:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0xd4)) {
      return 0;
    }
    break;
  case 5:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0xfc)) {
      return 0;
    }
    break;
  case 6:
    FUN_0041ec50(&param_2,param_2);
    iVar1 = param_2;
    if (param_2 == *(int *)(in_ECX + 0x124)) {
      return 0;
    }
  }
  return iVar1 + 0x24;
}


// ==== FUN_0041a9a0 @ 0x0041a9a0 ====

int FUN_0041a9a0(undefined4 param_1,ushort param_2)

{
  code *pcVar1;
  int *piVar2;
  int extraout_EAX;
  int iVar3;
  int in_ECX;
  int local_2c;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979332;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041e830(&local_2c,&param_1);
  iVar3 = *(int *)(in_ECX + 0x19c);
  if (local_2c != iVar3) {
    ExceptionList = local_c;
    return local_2c + 0x10 + (uint)param_2 * 0x1c;
  }
  param_1 = 0;
  piVar2 = (int *)FUN_0041e830(&local_2c,&param_1);
  if (*piVar2 != iVar3) {
    ExceptionList = local_c;
    return *piVar2 + 0x10 + (uint)param_2 * 0x1c;
  }
  FUN_00401830(s_GFALSE_0099e090);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_0041aa90 @ 0x0041aa90 ====

int FUN_0041aa90(int param_1)

{
  int iVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097934c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401740(s__s__s_0099e10c,5);
  FUN_00404230(local_28);
  local_4 = 0;
  iVar1 = FUN_0049dcb0();
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740();
  }
  else {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740();
    local_4 = 1;
    iVar1 = FUN_0049db90();
    local_4 = 0xffffffff;
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX_00;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401740();
    }
    else {
      FUN_00405d30();
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660();
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== FUN_0041ac00 @ 0x0041ac00 ====

int FUN_0041ac00(int param_1)

{
  int iVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979366;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401740(s__s__s_0099e120,5);
  FUN_00404230(local_28);
  local_4 = 0;
  iVar1 = FUN_0049dcb0();
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740();
  }
  else {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740();
    local_4 = 1;
    iVar1 = FUN_0049db90();
    local_4 = 0xffffffff;
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX_00;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401740();
    }
    else {
      FUN_00405d30();
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660();
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== FUN_0041ad70 @ 0x0041ad70 ====

void FUN_0041ad70(void)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  undefined1 local_17c [4];
  void *local_178;
  undefined4 local_168;
  uint local_164;
  void *local_15c;
  undefined4 local_14c;
  uint local_148;
  void *local_140;
  undefined4 local_130;
  uint local_12c;
  undefined2 local_14;
  undefined1 local_12;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097939c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041ead0();
  local_4 = 0;
  FUN_00401740(s_Item_default_txt_0099e0f8,0x10);
  FUN_00404230(local_17c);
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar2 = FUN_0041f0e0(local_17c);
  if (iVar2 == 0) {
    if (0xf < local_164) {
      _free(local_178);
      return;
    }
  }
  else {
    bVar3 = 0;
    do {
      bVar1 = 0;
      do {
        FUN_0041aa90();
        local_4._0_1_ = 2;
        FUN_00401660();
        local_4._0_1_ = 1;
        if (0xf < local_148) {
          _free(local_15c);
          return;
        }
        local_148 = 0xf;
        local_14c = 0;
        local_15c = (void *)((uint)local_15c & 0xffffff00);
        FUN_0041ac00();
        local_4._0_1_ = 3;
        FUN_00401660();
        local_4 = CONCAT31(local_4._1_3_,1);
        if (0xf < local_12c) {
          _free(local_140);
          return;
        }
        local_12c = 0xf;
        local_130 = 0;
        local_140 = (void *)((uint)local_140 & 0xffffff00);
        local_14 = 0;
        local_12 = 1;
        FUN_0041f450();
        bVar1 = bVar1 + 1;
      } while (bVar1 < 5);
      bVar3 = bVar3 + 1;
    } while (bVar3 < 6);
    (**(code **)(*DAT_00b5a7cc + 0x14))();
    if (0xf < local_164) {
      _free(local_178);
      return;
    }
  }
  local_164 = 0xf;
  local_178 = (void *)((uint)local_178 & 0xffffff00);
  local_168 = 0;
  FUN_0041eb50();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041af90 @ 0x0041af90 ====

void FUN_0041af90(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_14c [4];
  void *local_148;
  int local_144;
  undefined4 local_140;
  int local_13c;
  undefined4 local_134;
  undefined1 local_130 [4];
  void *local_12c;
  undefined4 local_11c;
  uint local_118;
  int local_114 [2];
  undefined1 local_10c [4];
  void *local_108;
  undefined4 local_f8;
  uint local_f4;
  undefined1 local_f0 [112];
  uint uStack_80;
  undefined1 auStack_7c [108];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009793da;
  pvStack_c = ExceptionList;
  local_f4 = 0xf;
  local_f8 = 0;
  local_108 = (void *)((uint)local_108 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_weapon_bonename_csv_0099e000,0x13);
  local_4 = 0;
  iVar2 = FUN_00410500(local_10c);
  local_4 = 0xffffffff;
  local_13c = iVar2;
  if (0xf < local_f4) {
    _free(local_108);
    return;
  }
  local_f4 = 0xf;
  local_f8 = 0;
  local_108 = (void *)((uint)local_108 & 0xffffff00);
  local_134 = *(undefined4 *)(iVar2 + 0x4c);
  FUN_0049d760();
  FUN_0049d780();
  cVar1 = FUN_0049d7c0();
  if (cVar1 == '\0') {
    do {
      FUN_0049d800(local_130);
      local_148 = (void *)0x0;
      local_144 = 0;
      local_140 = 0;
      local_4 = 2;
      FUN_00404fb0(local_130,0x2c,local_14c);
      if (local_148 == (void *)0x0) {
        local_148 = (void *)0x0;
        local_144 = 0;
        local_140 = 0;
        local_4 = 0xffffffff;
        if (0xf < local_118) {
          _free(local_12c);
          return;
        }
      }
      else {
        if ((uint)((local_144 - (int)local_148) / 0x1c) < 2) {
          FUN_00405de0(local_148,local_144,local_14c,local_13c);
          _free(local_148);
          return;
        }
        _eh_vector_constructor_iterator_(local_f0,0x1c,4,FUN_00403720,FUN_00446f10);
        local_4._0_1_ = 3;
        if ((local_148 == (void *)0x0) ||
           (local_114[0] = (local_144 - (int)local_148) / 0x1c, local_114[0] == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar2 = thunk_FUN_00796f80(local_148);
        if ((local_148 == (void *)0x0) || ((uint)((local_144 - (int)local_148) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar3 = thunk_FUN_00796f80((int)local_148 + 0x1c);
        if ((local_148 == (void *)0x0) || ((uint)((local_144 - (int)local_148) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_148 + 0x38,0,0xffffffff);
        if ((local_148 == (void *)0x0) || ((uint)((local_144 - (int)local_148) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_148 + 0x54,0,0xffffffff);
        if ((local_148 == (void *)0x0) || ((uint)((local_144 - (int)local_148) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_148 + 0x70,0,0xffffffff);
        if ((local_148 == (void *)0x0) || ((uint)((local_144 - (int)local_148) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_148 + 0x8c,0,0xffffffff);
        uStack_80 = iVar2 << 0x10 | uVar3 & 0xffff;
        _eh_vector_copy_constructor_iterator_(auStack_7c,local_f0,0x1c,4,FUN_00765c50,FUN_00446f10);
        local_4._0_1_ = 4;
        FUN_00420dc0(local_114,&uStack_80);
        local_4._0_1_ = 3;
        _eh_vector_destructor_iterator_(auStack_7c,0x1c,4,FUN_00446f10);
        local_4 = CONCAT31(local_4._1_3_,2);
        _eh_vector_destructor_iterator_(local_f0,0x1c,4,FUN_00446f10);
        if (local_148 != (void *)0x0) {
          FUN_00405de0(local_148,local_144,local_14c,local_114[0]);
          _free(local_148);
          return;
        }
        local_148 = (void *)0x0;
        local_144 = 0;
        local_140 = 0;
        local_4 = 0xffffffff;
        if (0xf < local_118) {
          _free(local_12c);
          return;
        }
      }
      local_4 = 0xffffffff;
      local_140 = 0;
      local_144 = 0;
      local_148 = (void *)0x0;
      local_118 = 0xf;
      local_11c = 0;
      local_12c = (void *)((uint)local_12c & 0xffffff00);
      FUN_0049d780();
      cVar1 = FUN_0049d7c0();
    } while (cVar1 == '\0');
    iVar2 = local_13c;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0041b400 @ 0x0041b400 ====

void FUN_0041b400(void)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_128 [4];
  void *local_124;
  int local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 local_110 [4];
  void *local_10c;
  undefined4 local_fc;
  uint local_f8;
  undefined1 local_f4 [4];
  void *local_f0;
  undefined4 local_e0;
  uint local_dc;
  undefined1 auStack_d8 [4];
  undefined1 local_d4;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined2 uStack_a0;
  undefined1 local_98;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 uStack_80;
  undefined2 uStack_7e;
  undefined2 uStack_7c;
  undefined1 auStack_78 [8];
  undefined2 auStack_70 [48];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979418;
  pvStack_c = ExceptionList;
  local_dc = 0xf;
  local_e0 = 0;
  local_f0 = (void *)((uint)local_f0 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_vehicle_shape_csv_0099e014,0x11);
  local_4 = 0;
  uVar4 = FUN_00410500(local_f4);
  local_4 = 0xffffffff;
  local_118 = uVar4;
  if (0xf < local_dc) {
    _free(local_f0);
    return;
  }
  local_dc = 0xf;
  local_e0 = 0;
  local_f0 = (void *)((uint)local_f0 & 0xffffff00);
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  if (cVar2 == '\0') {
    do {
      FUN_0049d800(local_110);
      local_124 = (void *)0x0;
      local_120 = 0;
      local_11c = 0;
      local_4 = 2;
      FUN_00404fb0(local_110,0x2c,local_128);
      if (local_124 != (void *)0x0) {
        iVar1 = local_120 - (int)local_124 >> 0x1f;
        iVar5 = (local_120 - (int)local_124) / 0x1c + iVar1;
        if ((uint)(iVar5 - iVar1) < 2) {
          FUN_00405de0(local_124,local_120,local_128,local_118);
          _free(local_124);
          return;
        }
        local_c0 = 0xf;
        local_c4 = 0;
        local_d4 = 0;
        local_a4 = 0xf;
        local_a8 = 0;
        local_b8 = 0;
        local_84 = 0xf;
        local_88 = 0;
        local_98 = 0;
        local_4._0_1_ = 3;
        if (iVar5 == iVar1) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar3 = thunk_FUN_00796f80(local_124);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_124 + 0x1c,0,0xffffffff);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_124 + 0x38,0,0xffffffff);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_a0 = thunk_FUN_00796f80((int)local_124 + 0x54);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_124 + 0x70,0,0xffffffff);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_80 = thunk_FUN_00796fe0((int)local_124 + 0x8c);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 7)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_7e = thunk_FUN_00796f80((int)local_124 + 0xa8);
        if ((local_124 == (void *)0x0) || ((uint)((local_120 - (int)local_124) / 0x1c) < 8)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_7c = thunk_FUN_00796f80((int)local_124 + 0xc4);
        auStack_70[0] = uVar3;
        FUN_0041ee40(auStack_d8);
        local_4 = CONCAT31(local_4._1_3_,4);
        FUN_00420e80(auStack_78,auStack_70);
        FUN_0041e9e0();
        FUN_0041e9e0();
        if (local_124 != (void *)0x0) {
          FUN_00405de0(local_124,local_120,local_128,local_118);
          _free(local_124);
          return;
        }
      }
      if (0xf < local_f8) {
        local_4 = 0xffffffff;
        local_11c = 0;
        local_120 = 0;
        local_124 = (void *)0x0;
        _free(local_10c);
        return;
      }
      local_4 = 0xffffffff;
      local_11c = 0;
      local_120 = 0;
      local_124 = (void *)0x0;
      local_f8 = 0xf;
      local_fc = 0;
      local_10c = (void *)((uint)local_10c & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    } while (cVar2 == '\0');
    uVar4 = local_118;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(uVar4);
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0041b8d0 @ 0x0041b8d0 ====

void FUN_0041b8d0(void)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_34c [4];
  void *local_348;
  int local_344;
  undefined4 local_340;
  int local_33c;
  undefined4 local_338;
  int local_330 [2];
  undefined1 local_328 [4];
  void *local_324;
  undefined4 local_314;
  uint local_310;
  undefined1 local_30c [4];
  void *local_308;
  undefined4 local_2f8;
  uint local_2f4;
  undefined1 auStack_2f0 [4];
  void *pvStack_2ec;
  undefined4 uStack_2dc;
  uint uStack_2d8;
  undefined1 auStack_2d4 [4];
  void *pvStack_2d0;
  undefined4 uStack_2c0;
  uint uStack_2bc;
  undefined1 auStack_2b8 [4];
  void *pvStack_2b4;
  undefined4 uStack_2a4;
  uint uStack_2a0;
  undefined1 auStack_29c [4];
  void *pvStack_298;
  undefined4 uStack_288;
  uint uStack_284;
  undefined1 auStack_280 [4];
  void *pvStack_27c;
  undefined4 uStack_26c;
  uint uStack_268;
  undefined1 auStack_264 [4];
  void *pvStack_260;
  undefined4 uStack_250;
  uint uStack_24c;
  undefined1 local_248 [28];
  undefined1 auStack_22c [20];
  int iStack_218;
  int iStack_1fc;
  int iStack_1e0;
  undefined1 uStack_1d8;
  float fStack_1d4;
  undefined1 auStack_1d0 [48];
  int iStack_1a0;
  undefined2 uStack_198;
  int iStack_180;
  int iStack_164;
  undefined1 uStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  float fStack_13c;
  undefined2 uStack_138;
  undefined2 uStack_134;
  undefined1 uStack_132;
  undefined2 uStack_130;
  undefined2 uStack_12e;
  undefined2 auStack_12c [142];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097949b;
  pvStack_c = ExceptionList;
  local_2f4 = 0xf;
  local_2f8 = 0;
  local_308 = (void *)((uint)local_308 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Item_shape_csv_0099dfc0,0xe);
  local_4 = 0;
  local_33c = FUN_00410500(local_30c);
  local_4 = 0xffffffff;
  if (0xf < local_2f4) {
    _free(local_308);
    return;
  }
  local_2f4 = 0xf;
  local_2f8 = 0;
  local_308 = (void *)((uint)local_308 & 0xffffff00);
  local_338 = *(undefined4 *)(local_33c + 0x4c);
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  do {
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00b5a7cc + 0x14))(local_33c);
      ExceptionList = pvStack_10;
      return;
    }
    FUN_0049d800(local_328);
    local_348 = (void *)0x0;
    local_344 = 0;
    local_340 = 0;
    local_4 = 2;
    FUN_00404fb0(local_328,0x2c,local_34c);
    if (local_348 == (void *)0x0) {
      local_348 = (void *)0x0;
      local_344 = 0;
      local_340 = 0;
      local_4 = 0xffffffff;
      if (0xf < local_310) {
        _free(local_324);
        return;
      }
    }
    else {
      if ((uint)((local_344 - (int)local_348) / 0x1c) < 2) {
        FUN_00405de0(local_348,local_344,local_34c,local_33c);
        _free(local_348);
        return;
      }
      FUN_0041ead0();
      local_4._0_1_ = 3;
      if ((local_348 == (void *)0x0) ||
         (local_330[0] = (local_344 - (int)local_348) / 0x1c, local_330[0] == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_330[0] = thunk_FUN_00796f80(local_348);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0x1c,0,0xffffffff);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0x38,0,0xffffffff);
      if (iStack_1a0 == 0) {
        uVar3 = FUN_004047b0(auStack_264,auStack_1d0);
        local_4._0_1_ = 4;
        uVar3 = FUN_00402220(auStack_2b8,uVar3,s__tpack_0099dfd0);
        local_4._0_1_ = 5;
        FUN_00401660(uVar3,0,0xffffffff);
        if (0xf < uStack_2a0) {
          _free(pvStack_2b4);
          return;
        }
        uStack_2a0 = 0xf;
        uStack_2a4 = 0;
        pvStack_2b4 = (void *)((uint)pvStack_2b4 & 0xffffff00);
        local_4._0_1_ = 3;
        if (0xf < uStack_24c) {
          _free(pvStack_260);
          return;
        }
        uStack_24c = 0xf;
        uStack_250 = 0;
        pvStack_260 = (void *)((uint)pvStack_260 & 0xffffff00);
      }
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_198 = thunk_FUN_00796f80((int)local_348 + 0x54);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0x70,0,0xffffffff);
      FUN_004047b0(auStack_2f0,local_248);
      local_4._0_1_ = 6;
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0x8c,0,0xffffffff);
      if (iStack_218 == 0) {
        uVar3 = FUN_00402220(auStack_280,auStack_2f0,s__tpack_0099dfd8);
        local_4._0_1_ = 7;
        FUN_00401660(uVar3,0,0xffffffff);
        local_4._0_1_ = 6;
        if (0xf < uStack_268) {
          _free(pvStack_27c);
          return;
        }
        uStack_268 = 0xf;
        uStack_26c = 0;
        pvStack_27c = (void *)((uint)pvStack_27c & 0xffffff00);
      }
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 7)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0xa8,0,0xffffffff);
      if (iStack_1fc == 0) {
        uVar3 = FUN_00402220(auStack_2d4,auStack_2f0,s__skel_0099dfe0);
        local_4._0_1_ = 8;
        FUN_00401660(uVar3,0,0xffffffff);
        local_4._0_1_ = 6;
        if (0xf < uStack_2bc) {
          _free(pvStack_2d0);
          return;
        }
        uStack_2bc = 0xf;
        uStack_2c0 = 0;
        pvStack_2d0 = (void *)((uint)pvStack_2d0 & 0xffffff00);
      }
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 8)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0xc4,0,0xffffffff);
      if (iStack_1e0 == 0) {
        uVar3 = FUN_00402220(auStack_29c,auStack_2f0,s__anim_0099dfe8);
        local_4._0_1_ = 9;
        FUN_00401660(uVar3,0,0xffffffff);
        local_4._0_1_ = 6;
        if (0xf < uStack_284) {
          _free(pvStack_298);
          return;
        }
        uStack_284 = 0xf;
        uStack_288 = 0;
        pvStack_298 = (void *)((uint)pvStack_298 & 0xffffff00);
      }
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 9)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar6 = (float10)thunk_FUN_00796ec0((int)local_348 + 0xe0);
      fStack_1d4 = (float)fVar6;
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 10)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_1d8 = thunk_FUN_00796fe0((int)local_348 + 0xfc);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0xe)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar6 = (float10)thunk_FUN_00796ec0((int)local_348 + 0x16c);
      fStack_158 = (float)fVar6;
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0xf)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar6 = (float10)thunk_FUN_00796ec0((int)local_348 + 0x188);
      fStack_154 = (float)fVar6;
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x10)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar6 = (float10)thunk_FUN_00796ec0((int)local_348 + 0x1a4);
      fStack_150 = (float)fVar6;
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x11)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar6 = (float10)thunk_FUN_00796ec0((int)local_348 + 0x1c0);
      fStack_13c = (float)(fVar6 * (float10)DAT_0099e170);
      if ((local_348 == (void *)0x0) || (uVar1 = (local_344 - (int)local_348) / 0x1c, uVar1 < 0x13))
      {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      if (uVar1 < 0x12) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar5 = (int)local_348 + 0x1dc;
      fVar6 = (float10)thunk_FUN_00796ec0((int)local_348 + 0x1f8);
      puVar4 = (undefined4 *)FUN_0041a1c0(local_30c,iVar5,(float)fVar6);
      uStack_14c = *puVar4;
      uStack_148 = puVar4[1];
      uStack_144 = puVar4[2];
      uStack_140 = puVar4[3];
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0xb)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0x118,0,0xffffffff);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0xc)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660((int)local_348 + 0x134,0,0xffffffff);
      if (iStack_180 == 0) {
        FUN_00401660(local_248,0,0xffffffff);
      }
      if (iStack_164 == 0) {
        FUN_00401660(auStack_22c,0,0xffffffff);
      }
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0xd)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_348 + 0x164),&DAT_0099dfee,0);
      if (iVar5 == 0) {
        uStack_15c = uStack_1d8;
      }
      else {
        if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0xd)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_15c = thunk_FUN_00796fe0((int)local_348 + 0x150);
      }
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x14)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_138 = thunk_FUN_00796f80((int)local_348 + 0x214);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x15)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_132 = thunk_FUN_00796fe0((int)local_348 + 0x230);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x16)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_134 = FUN_0041a110((int)local_348 + 0x24c);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x17)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_130 = thunk_FUN_00796f80((int)local_348 + 0x268);
      if ((local_348 == (void *)0x0) || ((uint)((local_344 - (int)local_348) / 0x1c) < 0x18)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_12e = thunk_FUN_00796f80((int)local_348 + 0x284);
      auStack_12c[0] = (undefined2)local_330[0];
      FUN_0041f240(local_248);
      local_4 = CONCAT31(local_4._1_3_,10);
      FUN_004214c0(local_330,auStack_12c);
      FUN_0041eb50();
      if (0xf < uStack_2d8) {
        _free(pvStack_2ec);
        return;
      }
      uStack_2d8 = 0xf;
      uStack_2dc = 0;
      pvStack_2ec = (void *)((uint)pvStack_2ec & 0xffffff00);
      FUN_0041eb50();
      if (local_348 != (void *)0x0) {
        FUN_00405de0(local_348,local_344,local_34c,local_33c);
        _free(local_348);
        return;
      }
      local_348 = (void *)0x0;
      local_344 = 0;
      local_340 = 0;
      local_4 = 0xffffffff;
      if (0xf < local_310) {
        _free(local_324);
        return;
      }
    }
    local_4 = 0xffffffff;
    local_310 = 0xf;
    local_340 = 0;
    local_344 = 0;
    local_348 = (void *)0x0;
    local_314 = 0;
    local_324 = (void *)((uint)local_324 & 0xffffff00);
    FUN_0049d780();
    cVar2 = FUN_0049d7c0();
  } while( true );
}


// ==== FUN_0041c580 @ 0x0041c580 ====

void FUN_0041c580(void)

{
  uint *puVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined1 *puVar7;
  undefined1 local_344 [4];
  uint *local_340;
  uint *local_33c;
  undefined4 local_338;
  int local_334;
  int local_330 [2];
  undefined4 local_328;
  undefined1 local_320 [4];
  void *local_31c;
  undefined4 local_30c;
  uint local_308;
  undefined1 local_304 [4];
  void *local_300;
  undefined4 local_2f0;
  uint local_2ec;
  undefined1 local_2e8 [28];
  undefined1 auStack_2cc [332];
  undefined1 uStack_180;
  undefined2 auStack_17c [2];
  undefined1 auStack_178 [360];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009794dc;
  pvStack_c = ExceptionList;
  local_2ec = 0xf;
  local_2f0 = 0;
  local_300 = (void *)((uint)local_300 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_cos_shape_csv_0099dff0,0xd);
  local_4 = 0;
  iVar4 = FUN_00410500(local_304);
  local_4 = 0xffffffff;
  local_334 = iVar4;
  if (0xf < local_2ec) {
    _free(local_300);
    return;
  }
  local_2ec = 0xf;
  local_2f0 = 0;
  local_300 = (void *)((uint)local_300 & 0xffffff00);
  local_328 = *(undefined4 *)(iVar4 + 0x4c);
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  if (cVar2 == '\0') {
    do {
      FUN_0049d800(local_320);
      local_340 = (uint *)0x0;
      local_33c = (uint *)0x0;
      local_338 = 0;
      local_4 = 2;
      FUN_00404fb0(local_320,0x2c,local_344);
      if (local_340 == (uint *)0x0) {
        local_340 = (uint *)0x0;
        local_33c = (uint *)0x0;
        local_338 = 0;
        local_4 = 0xffffffff;
        if (0xf < local_308) {
          _free(local_31c);
          return;
        }
      }
      else {
        if ((uint)(((int)local_33c - (int)local_340) / 0x1c) < 2) {
          FUN_00405de0(local_340,local_33c,local_344,local_334);
          _free(local_340);
          return;
        }
        _eh_vector_constructor_iterator_(local_2e8,0x3c,6,FUN_0041e990,FUN_0040a7d0);
        local_4 = CONCAT31(local_4._1_3_,3);
        if ((local_340 == (uint *)0x0) ||
           (local_330[0] = ((int)local_33c - (int)local_340) / 0x1c, local_330[0] == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_330[0] = thunk_FUN_00796f80(local_340);
        puVar7 = auStack_2cc;
        uVar5 = 2;
        iVar4 = 0x38;
        do {
          if ((local_340 == (uint *)0x0) ||
             ((uint)(((int)local_33c - (int)local_340) / 0x1c) <= uVar5 - 1)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          FUN_00401660(iVar4 + -0x1c + (int)local_340,0,0xffffffff);
          if ((local_340 == (uint *)0x0) ||
             ((uint)(((int)local_33c - (int)local_340) / 0x1c) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          FUN_00401660(iVar4 + (int)local_340,0,0xffffffff);
          if ((local_340 == (uint *)0x0) ||
             ((uint)(((int)local_33c - (int)local_340) / 0x1c) <= uVar5 + 1)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar3 = thunk_FUN_00796f80(iVar4 + 0x1c + (int)local_340);
          *(undefined2 *)(puVar7 + 0x1c) = uVar3;
          iVar4 = iVar4 + 0x54;
          uVar5 = uVar5 + 3;
          puVar7 = puVar7 + 0x3c;
        } while (iVar4 < 0x230);
        if ((local_340 == (uint *)0x0) || ((uint)(((int)local_33c - (int)local_340) / 0x1c) < 0x14))
        {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_180 = thunk_FUN_00796fe0(local_340 + 0x85);
        auStack_17c[0] = (undefined2)local_330[0];
        _eh_vector_copy_constructor_iterator_
                  (auStack_178,local_2e8,0x3c,6,FUN_0041edc0,FUN_0040a7d0);
        pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,uStack_180);
        local_4._0_1_ = 4;
        FUN_00421590(local_330,auStack_17c);
        local_4._0_1_ = 3;
        _eh_vector_destructor_iterator_(auStack_178,0x3c,6,FUN_0040a7d0);
        local_4 = CONCAT31(local_4._1_3_,2);
        _eh_vector_destructor_iterator_(local_2e8,0x3c,6,FUN_0040a7d0);
        if (local_340 != (uint *)0x0) {
          if (local_340 != local_33c) {
            puVar6 = local_340 + 6;
            do {
              if (0xf < *puVar6) {
                _free((void *)puVar6[-5]);
                return;
              }
              *puVar6 = 0xf;
              puVar6[-1] = 0;
              *(undefined1 *)(puVar6 + -5) = 0;
              puVar1 = puVar6 + 1;
              puVar6 = puVar6 + 7;
            } while (puVar1 != local_33c);
          }
          _free(local_340);
          return;
        }
        local_340 = (uint *)0x0;
        local_33c = (uint *)0x0;
        local_338 = 0;
        local_4 = 0xffffffff;
        if (0xf < local_308) {
          _free(local_31c);
          return;
        }
      }
      local_4 = 0xffffffff;
      local_30c = 0;
      local_338 = 0;
      local_33c = (uint *)0x0;
      local_340 = (uint *)0x0;
      local_308 = 0xf;
      local_31c = (void *)((uint)local_31c & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    } while (cVar2 == '\0');
    iVar4 = local_334;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar4);
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0041ca10 @ 0x0041ca10 ====

void FUN_0041ca10(void *param_1)

{
  uint uVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  float10 fVar7;
  uint in_stack_00000018;
  undefined1 local_294 [4];
  void *local_290;
  int local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined1 local_27c [4];
  void *local_278;
  undefined4 local_268;
  uint local_264;
  int local_260 [2];
  undefined1 auStack_258 [16];
  undefined1 local_248 [176];
  undefined2 uStack_198;
  undefined1 uStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  float fStack_13c;
  undefined2 uStack_138;
  undefined1 uStack_132;
  undefined2 auStack_12c [142];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097951a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar4 = FUN_00410500(&param_1);
  local_284 = uVar4;
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  if (cVar2 == '\0') {
    do {
      FUN_0049d800(local_27c);
      local_290 = (void *)0x0;
      local_28c = 0;
      local_288 = 0;
      local_4._0_1_ = 2;
      FUN_00404fb0(local_27c,0x2c,local_294);
      if (local_290 != (void *)0x0) {
        if ((uint)((local_28c - (int)local_290) / 0x1c) < 2) {
          FUN_00405de0(local_290,local_28c,local_294,local_284);
          _free(local_290);
          return;
        }
        FUN_0041ead0();
        local_4._0_1_ = 3;
        if ((local_290 == (void *)0x0) ||
           (local_260[0] = (local_28c - (int)local_290) / 0x1c, local_260[0] == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar3 = thunk_FUN_00796f80(local_290);
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_198 = thunk_FUN_00796f80((int)local_290 + 0x54);
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0xe)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)local_290 + 0x16c);
        fStack_158 = (float)fVar7;
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0xf)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)local_290 + 0x188);
        fStack_154 = (float)fVar7;
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0x10)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)local_290 + 0x1a4);
        fStack_150 = (float)fVar7;
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0x11)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)local_290 + 0x1c0);
        fStack_13c = (float)fVar7;
        if ((local_290 == (void *)0x0) ||
           (uVar1 = (local_28c - (int)local_290) / 0x1c, uVar1 < 0x13)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        if (uVar1 < 0x12) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar6 = (int)local_290 + 0x1dc;
        fVar7 = (float10)thunk_FUN_00796ec0((int)local_290 + 0x1f8);
        puVar5 = (undefined4 *)FUN_0041a1c0(auStack_258,iVar6,(float)fVar7);
        uStack_14c = *puVar5;
        uStack_148 = puVar5[1];
        uStack_144 = puVar5[2];
        uStack_140 = puVar5[3];
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0xb)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_290 + 0x118,0,0xffffffff);
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0xc)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_290 + 0x134,0,0xffffffff);
        uStack_15c = 1;
        if ((local_290 == (void *)0x0) || ((uint)((local_28c - (int)local_290) / 0x1c) < 0x14)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_138 = thunk_FUN_00796f80((int)local_290 + 0x214);
        uStack_132 = 0;
        auStack_12c[0] = uVar3;
        FUN_0041f240(local_248);
        local_4._0_1_ = 4;
        FUN_004214c0(local_260,auStack_12c);
        FUN_0041eb50();
        FUN_0041eb50();
        if (local_290 != (void *)0x0) {
          FUN_00405de0(local_290,local_28c,local_294,local_260[0]);
          _free(local_290);
          return;
        }
      }
      local_4 = (uint)local_4._1_3_ << 8;
      if (0xf < local_264) {
        local_288 = 0;
        local_28c = 0;
        local_290 = (void *)0x0;
        _free(local_278);
        return;
      }
      local_288 = 0;
      local_28c = 0;
      local_290 = (void *)0x0;
      local_264 = 0xf;
      local_268 = 0;
      local_278 = (void *)((uint)local_278 & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    } while (cVar2 == '\0');
    uVar4 = local_284;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(uVar4);
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0041cf80 @ 0x0041cf80 ====

void FUN_0041cf80(void *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint in_stack_00000018;
  undefined1 local_f8 [4];
  void *local_f4;
  int local_f0;
  undefined4 local_ec;
  int local_e8;
  undefined4 local_e4;
  undefined1 local_e0 [4];
  void *local_dc;
  undefined4 local_cc;
  uint local_c8;
  undefined1 local_c4 [4];
  void *local_c0;
  undefined4 local_b0;
  uint local_ac;
  undefined1 local_a8 [4];
  void *local_a4;
  undefined4 local_94;
  uint local_90;
  void *local_88;
  undefined4 local_78;
  uint local_74;
  undefined2 uStack_70;
  undefined1 auStack_6c [8];
  undefined1 auStack_64 [4];
  undefined1 uStack_60;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00979568;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar3 = FUN_00410500(&param_1);
  local_e4 = *(undefined4 *)(iVar3 + 0x4c);
  local_e8 = iVar3;
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  if (cVar2 == '\0') {
    do {
      FUN_0049d800(local_e0);
      local_f4 = (void *)0x0;
      local_f0 = 0;
      local_ec = 0;
      local_4._0_1_ = 2;
      FUN_00404fb0(local_e0,0x2c,local_f8);
      if (local_f4 == (void *)0x0) {
        local_f4 = (void *)0x0;
        local_f0 = 0;
        local_ec = 0;
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_c8) {
          _free(local_dc);
          return;
        }
      }
      else {
        uVar1 = (local_f0 - (int)local_f4) / 0x1c;
        if (uVar1 < 2) {
          FUN_00405de0(local_f4,local_f0,local_f8,local_e8);
          _free(local_f4);
          return;
        }
        local_90 = 0xf;
        local_94 = 0;
        local_a4 = (void *)((uint)local_a4 & 0xffffff00);
        local_74 = 0xf;
        local_78 = 0;
        local_88 = (void *)((uint)local_88 & 0xffffff00);
        local_4._0_1_ = 3;
        if (uVar1 < 2) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_ac = 0xf;
        local_b0 = 0;
        local_c0 = (void *)((uint)local_c0 & 0xffffff00);
        FUN_00401660((int)local_f4 + 0x1c,0,0xffffffff);
        local_4._0_1_ = 4;
        if ((local_f4 == (void *)0x0) || ((uint)((local_f0 - (int)local_f4) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_f4 + 0x38,0,0xffffffff);
        if ((local_f4 == (void *)0x0) || ((uint)((local_f0 - (int)local_f4) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_f4 + 0x54,0,0xffffffff);
        if ((local_f4 == (void *)0x0) || ((uint)((local_f0 - (int)local_f4) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_70 = thunk_FUN_00796f80((int)local_f4 + 0x70);
        uStack_4c = 0xf;
        uStack_50 = 0;
        uStack_60 = 0;
        FUN_00401660(local_c4,0,0xffffffff);
        local_4._0_1_ = 5;
        FUN_0041edc0(local_a8);
        local_4._0_1_ = 6;
        FUN_00421820(auStack_6c,auStack_64);
        FUN_0040a820();
        if (0xf < local_ac) {
          _free(local_c0);
          return;
        }
        local_ac = 0xf;
        local_b0 = 0;
        local_c0 = (void *)((uint)local_c0 & 0xffffff00);
        if (0xf < local_74) {
          _free(local_88);
          return;
        }
        local_74 = 0xf;
        local_78 = 0;
        local_88 = (void *)((uint)local_88 & 0xffffff00);
        if (0xf < local_90) {
          _free(local_a4);
          return;
        }
        local_90 = 0xf;
        local_94 = 0;
        local_a4 = (void *)((uint)local_a4 & 0xffffff00);
        if (local_f4 != (void *)0x0) {
          FUN_00405de0(local_f4,local_f0,local_f8,local_e8);
          _free(local_f4);
          return;
        }
        local_f4 = (void *)0x0;
        local_f0 = 0;
        local_ec = 0;
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_c8) {
          _free(local_dc);
          return;
        }
      }
      local_ec = 0;
      local_f0 = 0;
      local_f4 = (void *)0x0;
      local_c8 = 0xf;
      local_cc = 0;
      local_dc = (void *)((uint)local_dc & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    } while (cVar2 == '\0');
    iVar3 = local_e8;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0041d370 @ 0x0041d370 ====

void FUN_0041d370(void *param_1)

{
  uint uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int in_ECX;
  uint in_stack_00000018;
  undefined1 local_bc [4];
  void *local_b8;
  int local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined1 local_a4 [4];
  void *local_a0;
  undefined4 local_90;
  uint local_8c;
  undefined1 local_88 [4];
  void *local_84;
  undefined4 local_74;
  uint local_70;
  undefined1 auStack_6c [8];
  undefined1 auStack_64 [4];
  undefined1 uStack_60;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009795ab;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar4 = FUN_00410500(&param_1);
  local_a8 = *(undefined4 *)(iVar4 + 0x4c);
  local_ac = iVar4;
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  if (cVar2 == '\0') {
    do {
      FUN_0049d800(local_a4);
      local_b8 = (void *)0x0;
      local_b4 = 0;
      local_b0 = 0;
      local_4._0_1_ = 2;
      FUN_00404fb0(local_a4,0x2c,local_bc);
      if (local_b8 == (void *)0x0) {
        local_b8 = (void *)0x0;
        local_b4 = 0;
        local_b0 = 0;
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_8c) {
          _free(local_a0);
          return;
        }
      }
      else {
        uVar1 = (local_b4 - (int)local_b8) / 0x1c;
        if (uVar1 < 2) {
          FUN_00405de0(local_b8,local_b4,local_bc,local_ac);
          _free(local_b8);
          return;
        }
        if (uVar1 < 2) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_70 = 0xf;
        local_74 = 0;
        local_84 = (void *)((uint)local_84 & 0xffffff00);
        FUN_00401660((int)local_b8 + 0x1c,0,0xffffffff);
        local_4._0_1_ = 3;
        if ((local_b8 == (void *)0x0) || ((uint)((local_b4 - (int)local_b8) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_b8 + 0x38,0,0xffffffff);
        if ((local_b8 == (void *)0x0) || ((uint)((local_b4 - (int)local_b8) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_b8 + 0x54,0,0xffffffff);
        if ((local_b8 == (void *)0x0) || ((uint)((local_b4 - (int)local_b8) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar3 = thunk_FUN_00796f80((int)local_b8 + 0x70);
        *(undefined2 *)(in_ECX + 0x17c) = uVar3;
        uStack_4c = 0xf;
        uStack_50 = 0;
        uStack_60 = 0;
        FUN_00401660(local_88,0,0xffffffff);
        local_4._0_1_ = 4;
        FUN_0041edc0(in_ECX + 0x144);
        local_4._0_1_ = 5;
        FUN_00421820(auStack_6c,auStack_64);
        FUN_0040a820();
        if (0xf < local_70) {
          _free(local_84);
          return;
        }
        local_70 = 0xf;
        local_74 = 0;
        local_84 = (void *)((uint)local_84 & 0xffffff00);
        if (local_b8 != (void *)0x0) {
          FUN_00405de0(local_b8,local_b4,local_bc,local_ac);
          _free(local_b8);
          return;
        }
        local_b8 = (void *)0x0;
        local_b4 = 0;
        local_b0 = 0;
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_8c) {
          _free(local_a0);
          return;
        }
      }
      local_8c = 0xf;
      local_b0 = 0;
      local_b4 = 0;
      local_b8 = (void *)0x0;
      local_90 = 0;
      local_a0 = (void *)((uint)local_a0 & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    } while (cVar2 == '\0');
    iVar4 = local_ac;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar4);
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0041d6f0 @ 0x0041d6f0 ====

void FUN_0041d6f0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097966f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e178;
  local_4 = 0xe;
  DAT_00b5a6dc = 0;
  _eh_vector_destructor_iterator_(in_ECX + 0x69,0x11c,0x1e,FUN_0041eb50);
  local_4 = CONCAT31(local_4._1_3_,0xd);
  FUN_00421380(local_10,*(undefined4 *)in_ECX[0x67],(undefined4 *)in_ECX[0x67]);
  _free((void *)in_ECX[0x67]);
  return;
}


// ==== FUN_0041da80 @ 0x0041da80 ====

void FUN_0041da80(void)

{
  FUN_0041b8d0();
  FUN_0041c580();
  FUN_0041af90();
  FUN_0041b400();
  FUN_00401740(s_money_shape_csv_0099dee0,0xf);
  FUN_0041ca10();
  FUN_00401740(s_etc_shape_csv_0099def0,0xd);
  FUN_0041ca10();
  FUN_0041ad70();
  FUN_00401740(s_Creature_npc_shape_csv_0099df00,0x16);
  FUN_0041cf80();
  FUN_00401740(s_Creature_monster_shape_csv_0099df18,0x1a);
  FUN_0041cf80();
  FUN_00401740(s_Creature_servant_shape_csv_0099df34,0x1a);
  FUN_0041cf80();
  FUN_00401740(s_Creature_guard_shape_csv_0099df50,0x18);
  FUN_0041cf80();
  FUN_00401740(s_Creature_brick_shape_csv_0099df6c,0x18);
  FUN_0041cf80();
  FUN_00401740(s_Creature_sentry_shape_csv_0099df88,0x19);
  FUN_0041cf80();
  FUN_00401740(s_Creature_observer_shape_csv_0099dfa4);
  FUN_0041d370();
  return;
}


// ==== FUN_0041dc30 @ 0x0041dc30 ====

void FUN_0041dc30(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined1 local_11 [5];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979733;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e178;
  iVar1 = FUN_0041e5c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x12d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4._0_1_ = 1;
  iVar1 = FUN_0041e5c0();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x12d) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  local_4._0_1_ = 2;
  iVar1 = FUN_0041e5c0();
  in_ECX[8] = iVar1;
  *(undefined1 *)(iVar1 + 0x12d) = 1;
  *(undefined4 *)(in_ECX[8] + 4) = in_ECX[8];
  *(undefined4 *)in_ECX[8] = in_ECX[8];
  *(undefined4 *)(in_ECX[8] + 8) = in_ECX[8];
  in_ECX[9] = 0;
  local_4._0_1_ = 3;
  in_ECX[10] = 0;
  FUN_00421660(local_11,local_11);
  local_4._0_1_ = 4;
  FUN_00421660(local_11,local_11);
  local_4._0_1_ = 5;
  FUN_00421660(local_11,local_11);
  local_4._0_1_ = 6;
  FUN_00421660(local_11,local_11);
  local_4._0_1_ = 7;
  FUN_00421660(local_11,local_11);
  local_4._0_1_ = 8;
  FUN_00421660(local_11,local_11);
  local_4._0_1_ = 9;
  FUN_00421660(local_11,local_11);
  in_ECX[0x57] = 0xf;
  in_ECX[0x56] = 0;
  *(undefined1 *)(in_ECX + 0x52) = 0;
  in_ECX[0x5e] = 0xf;
  in_ECX[0x5d] = 0;
  *(undefined1 *)(in_ECX + 0x59) = 0;
  local_4._0_1_ = 0xb;
  iVar1 = FUN_0041e6a0();
  in_ECX[0x61] = iVar1;
  *(undefined1 *)(iVar1 + 0x71) = 1;
  *(undefined4 *)(in_ECX[0x61] + 4) = in_ECX[0x61];
  *(undefined4 *)in_ECX[0x61] = in_ECX[0x61];
  *(undefined4 *)(in_ECX[0x61] + 8) = in_ECX[0x61];
  in_ECX[0x62] = 0;
  local_4._0_1_ = 0xc;
  iVar1 = FUN_0041e620();
  in_ECX[100] = iVar1;
  *(undefined1 *)(iVar1 + 0x17d) = 1;
  *(undefined4 *)(in_ECX[100] + 4) = in_ECX[100];
  *(undefined4 *)in_ECX[100] = in_ECX[100];
  *(undefined4 *)(in_ECX[100] + 8) = in_ECX[100];
  in_ECX[0x65] = 0;
  local_4._0_1_ = 0xd;
  iVar1 = FUN_0041e660();
  in_ECX[0x67] = iVar1;
  *(undefined1 *)(iVar1 + 0x81) = 1;
  *(undefined4 *)(in_ECX[0x67] + 4) = in_ECX[0x67];
  *(undefined4 *)in_ECX[0x67] = in_ECX[0x67];
  *(undefined4 *)(in_ECX[0x67] + 8) = in_ECX[0x67];
  in_ECX[0x68] = 0;
  local_4 = CONCAT31(local_4._1_3_,0xe);
  _eh_vector_constructor_iterator_(in_ECX + 0x69,0x11c,0x1e,FUN_0041ead0,FUN_0041eb50);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6dc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6dc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041deb0 @ 0x0041deb0 ====

void FUN_0041deb0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x12d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x12d);
  }
  return;
}


// ==== FUN_0041ded0 @ 0x0041ded0 ====

void FUN_0041ded0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x12d);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x12d);
  }
  return;
}


// ==== FUN_0041def0 @ 0x0041def0 ====

void FUN_0041def0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x17d);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x17d);
  }
  return;
}


// ==== FUN_0041df10 @ 0x0041df10 ====

void FUN_0041df10(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x17d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x17d);
  }
  return;
}


// ==== FUN_0041df30 @ 0x0041df30 ====

void FUN_0041df30(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x81);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x81);
  }
  return;
}


// ==== FUN_0041df50 @ 0x0041df50 ====

void FUN_0041df50(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x81);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x81);
  }
  return;
}


// ==== FUN_0041df70 @ 0x0041df70 ====

void FUN_0041df70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x71) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x71) == '\0');
  }
  return;
}


// ==== FUN_0041df90 @ 0x0041df90 ====

void FUN_0041df90(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x71);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x71);
  }
  return;
}


// ==== FUN_0041dfb0 @ 0x0041dfb0 ====

void FUN_0041dfb0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x17d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x17d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x17d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x17d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x17d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x17d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0041e010 @ 0x0041e010 ====

void FUN_0041e010(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x81) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x81) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x81);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x81);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x81);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x81);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0041e070 @ 0x0041e070 ====

void FUN_0041e070(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x71) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x71) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x71);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x71);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x71);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x71);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0041e0c0 @ 0x0041e0c0 ====

void FUN_0041e0c0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x12d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x12d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x12d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x12d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x12d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x12d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0041e120 @ 0x0041e120 ====

void FUN_0041e120(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x12d) == '\0') {
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


// ==== FUN_0041e180 @ 0x0041e180 ====

void FUN_0041e180(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x12d) == '\0') {
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


// ==== FUN_0041e1e0 @ 0x0041e1e0 ====

void FUN_0041e1e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x17d) == '\0') {
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


// ==== FUN_0041e240 @ 0x0041e240 ====

void FUN_0041e240(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x17d) == '\0') {
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


// ==== FUN_0041e2a0 @ 0x0041e2a0 ====

void FUN_0041e2a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x81) == '\0') {
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


// ==== FUN_0041e300 @ 0x0041e300 ====

void FUN_0041e300(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x81) == '\0') {
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


// ==== FUN_0041e360 @ 0x0041e360 ====

void FUN_0041e360(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x71) == '\0') {
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


// ==== FUN_0041e3b0 @ 0x0041e3b0 ====

void FUN_0041e3b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x71) == '\0') {
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


// ==== FUN_0041e410 @ 0x0041e410 ====

void FUN_0041e410(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x12d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x12d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x12d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x12d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x12d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x12d) == '\0');
    if (*(char *)((int)piVar4 + 0x12d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0041e480 @ 0x0041e480 ====

void FUN_0041e480(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x17d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x17d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x17d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x17d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x17d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x17d) == '\0');
    if (*(char *)((int)piVar4 + 0x17d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0041e4f0 @ 0x0041e4f0 ====

void FUN_0041e4f0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x81) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x81) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x81);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x81);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x81) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x81) == '\0');
    if (*(char *)((int)piVar4 + 0x81) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0041e560 @ 0x0041e560 ====

void FUN_0041e560(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x71) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x71) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x71);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x71);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x71) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x71) == '\0');
    if (*(char *)((int)piVar4 + 0x71) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0041e5c0 @ 0x0041e5c0 ====

void FUN_0041e5c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x130);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x4b) = 1;
  *(undefined1 *)((int)puVar1 + 0x12d) = 0;
  return;
}


// ==== FUN_0041e600 @ 0x0041e600 ====

void FUN_0041e600(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x60);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_0041e620 @ 0x0041e620 ====

void FUN_0041e620(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x180);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x5f) = 1;
  *(undefined1 *)((int)puVar1 + 0x17d) = 0;
  return;
}


// ==== FUN_0041e660 @ 0x0041e660 ====

void FUN_0041e660(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x84);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x20) = 1;
  *(undefined1 *)((int)puVar1 + 0x81) = 0;
  return;
}


// ==== FUN_0041e6a0 @ 0x0041e6a0 ====

void FUN_0041e6a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x74);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x1c) = 1;
  *(undefined1 *)((int)puVar1 + 0x71) = 0;
  return;
}


// ==== FUN_0041e6e0 @ 0x0041e6e0 ====

int FUN_0041e6e0(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  iVar3 = -0x21524111;
  if (uVar2 != 0) {
    iVar4 = (uVar2 >> 4) + 1;
    uVar5 = 0;
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        puVar6 = (undefined4 *)(param_1 + 4);
      }
      else {
        puVar6 = *(undefined4 **)(param_1 + 4);
      }
      pcVar1 = (char *)((int)puVar6 + uVar5);
      uVar5 = uVar5 + iVar4;
      iVar3 = iVar3 + *pcVar1;
    } while (uVar5 <= uVar2 - iVar4);
  }
  return iVar3;
}


// ==== FUN_0041e730 @ 0x0041e730 ====

void FUN_0041e730(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x12d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(ushort *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x12d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0041e7b0 @ 0x0041e7b0 ====

void FUN_0041e7b0(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x17d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(ushort *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x17d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0041e830 @ 0x0041e830 ====

void FUN_0041e830(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x81) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x81) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0041e8a0 @ 0x0041e8a0 ====

void FUN_0041e8a0(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x71) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(ushort *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x71) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0041e910 @ 0x0041e910 ====

void FUN_0041e910(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x6c)) {
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x6c) = 0xf;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined1 *)(in_ECX + 0x58) = 0;
  if (0xf < *(uint *)(in_ECX + 0x50)) {
    _free(*(void **)(in_ECX + 0x3c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x50) = 0xf;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0041e990 @ 0x0041e990 ====

void FUN_0041e990(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_0041e9b0 @ 0x0041e9b0 ====

void FUN_0041e9b0(void)

{
  void *in_ECX;
  
  _eh_vector_destructor_iterator_(in_ECX,0x1c,4,FUN_00446f10);
  return;
}


// ==== FUN_0041e9c0 @ 0x0041e9c0 ====

void FUN_0041e9c0(void)

{
  int in_ECX;
  
  _eh_vector_destructor_iterator_((void *)(in_ECX + 4),0x1c,4,FUN_00446f10);
  return;
}


// ==== FUN_0041e9e0 @ 0x0041e9e0 ====

void FUN_0041e9e0(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x54)) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined1 *)(in_ECX + 0x40) = 0;
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0041ea50 @ 0x0041ea50 ====

void FUN_0041ea50(void)

{
  FUN_0041e9e0();
  return;
}


// ==== FUN_0041ea60 @ 0x0041ea60 ====

int FUN_0041ea60(int param_1,int param_2,undefined4 param_3)

{
  FUN_0045d020(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0041ea90 @ 0x0041ea90 ====

void FUN_0041ea90(void)

{
  FUN_0040a820();
  return;
}


// ==== FUN_0041eaa0 @ 0x0041eaa0 ====

void FUN_0041eaa0(void)

{
  int in_ECX;
  
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x10),0x1c,4,FUN_00446f10);
  return;
}


// ==== FUN_0041eac0 @ 0x0041eac0 ====

void FUN_0041eac0(void)

{
  FUN_0041e9e0();
  return;
}


// ==== FUN_0041ead0 @ 0x0041ead0 ====

void FUN_0041ead0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0xf;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0xf;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined1 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0xf;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined1 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0xf;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined1 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0xcc) = 0xf;
  *(undefined4 *)(in_ECX + 200) = 0;
  *(undefined1 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xe8) = 0xf;
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined1 *)(in_ECX + 0xd4) = 0;
  return;
}


// ==== FUN_0041eb50 @ 0x0041eb50 ====

void FUN_0041eb50(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0xe8)) {
    _free(*(void **)(in_ECX + 0xd4));
    return;
  }
  *(undefined4 *)(in_ECX + 0xe8) = 0xf;
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined1 *)(in_ECX + 0xd4) = 0;
  if (0xf < *(uint *)(in_ECX + 0xcc)) {
    _free(*(void **)(in_ECX + 0xb8));
    return;
  }
  *(undefined4 *)(in_ECX + 0xcc) = 0xf;
  *(undefined4 *)(in_ECX + 200) = 0;
  *(undefined1 *)(in_ECX + 0xb8) = 0;
  if (0xf < *(uint *)(in_ECX + 0xac)) {
    _free(*(void **)(in_ECX + 0x98));
    return;
  }
  *(undefined4 *)(in_ECX + 0xac) = 0xf;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined1 *)(in_ECX + 0x98) = 0;
  if (*(uint *)(in_ECX + 0x90) < 0x10) {
    *(undefined4 *)(in_ECX + 0x90) = 0xf;
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    *(undefined1 *)(in_ECX + 0x7c) = 0;
    FUN_0041e910();
    return;
  }
  _free(*(void **)(in_ECX + 0x7c));
  return;
}


// ==== FUN_0041ec10 @ 0x0041ec10 ====

void FUN_0041ec10(void)

{
  FUN_0041eb50();
  return;
}


// ==== FUN_0041ec20 @ 0x0041ec20 ====

void FUN_0041ec20(void)

{
  void *in_ECX;
  
  _eh_vector_destructor_iterator_(in_ECX,0x3c,6,FUN_0040a7d0);
  return;
}


// ==== FUN_0041ec30 @ 0x0041ec30 ====

void FUN_0041ec30(void)

{
  int in_ECX;
  
  _eh_vector_destructor_iterator_((void *)(in_ECX + 4),0x3c,6,FUN_0040a7d0);
  return;
}


// ==== FUN_0041ec50 @ 0x0041ec50 ====

/* WARNING: Removing unreachable block (ram,0x0041ecca) */

void FUN_0041ec50(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  
  uVar1 = *(uint *)(in_ECX + 0x20);
  uVar3 = FUN_0041e6e0(param_2);
  uVar3 = uVar3 & uVar1;
  if (*(uint *)(in_ECX + 0x24) <= uVar3) {
    uVar3 = uVar3 + (-1 - (uVar1 >> 1));
  }
  iVar5 = *(int *)(in_ECX + 0x14);
  piVar7 = *(int **)(iVar5 + uVar3 * 4);
  if (piVar7 != *(int **)(iVar5 + 4 + uVar3 * 4)) {
    uVar1 = *(uint *)(param_2 + 0x14);
    do {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        pbVar10 = (byte *)(param_2 + 4);
      }
      else {
        pbVar10 = *(byte **)(param_2 + 4);
      }
      uVar2 = piVar7[7];
      if (uVar2 == 0) {
LAB_0041ecf5:
        if (uVar1 <= uVar2) {
          bVar11 = false;
          goto LAB_0041ed02;
        }
      }
      else {
        uVar6 = uVar2;
        if (uVar1 <= uVar2) {
          uVar6 = uVar1;
        }
        if ((uint)piVar7[8] < 0x10) {
          pbVar9 = (byte *)(piVar7 + 3);
        }
        else {
          pbVar9 = (byte *)piVar7[3];
        }
        bVar11 = false;
        iVar4 = 0;
        bVar12 = true;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        bVar11 = iVar4 < 0;
        if (iVar4 == 0) goto LAB_0041ecf5;
LAB_0041ed02:
        if (!bVar11) {
          if ((uint)piVar7[8] < 0x10) {
            piVar8 = piVar7 + 3;
          }
          else {
            piVar8 = (int *)piVar7[3];
          }
          iVar5 = FUN_00403620(0,uVar1,piVar8,piVar7[7]);
          if (iVar5 < 0) {
            *param_1 = *(undefined4 *)(in_ECX + 8);
            return;
          }
          *param_1 = piVar7;
          return;
        }
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)*(int *)(iVar5 + uVar3 * 4 + 4));
  }
  *param_1 = *(undefined4 *)(in_ECX + 8);
  return;
}


// ==== FUN_0041ed90 @ 0x0041ed90 ====

void FUN_0041ed90(void)

{
  FUN_0041eb50();
  return;
}


// ==== FUN_0041eda0 @ 0x0041eda0 ====

void FUN_0041eda0(void)

{
  int in_ECX;
  
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x10),0x3c,6,FUN_0040a7d0);
  return;
}


// ==== FUN_0041edc0 @ 0x0041edc0 ====

void FUN_0041edc0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0x38) = *(undefined2 *)(param_1 + 0x38);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041ee40 @ 0x0041ee40 ====

void FUN_0041ee40(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979263;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0x38) = *(undefined2 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined1 *)(in_ECX + 0x40) = 0;
  FUN_00401660(param_1 + 0x3c,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x58) = *(undefined1 *)(param_1 + 0x58);
  *(undefined2 *)(in_ECX + 0x5a) = *(undefined2 *)(param_1 + 0x5a);
  *(undefined2 *)(in_ECX + 0x5c) = *(undefined2 *)(param_1 + 0x5c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041eef0 @ 0x0041eef0 ====

void FUN_0041eef0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097928e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x50) = 0xf;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  local_4._0_1_ = 1;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  FUN_00401660(param_1 + 0x38,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x6c) = 0xf;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined1 *)(in_ECX + 0x58) = 0;
  FUN_00401660(param_1 + 0x54,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x70) = *(undefined1 *)(param_1 + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041efb0 @ 0x0041efb0 ====

void FUN_0041efb0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x38) = *(undefined1 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined2 *)(in_ECX + 0x5c) = *(undefined2 *)(param_1 + 0x5c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041f070 @ 0x0041f070 ====

void FUN_0041f070(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0041edc0(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041f0e0 @ 0x0041f0e0 ====

undefined4 FUN_0041f0e0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009792a8;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0xf;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_0041f170 @ 0x0041f170 ====

void FUN_0041f170(int param_1)

{
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  FUN_00401660(param_1 + 0x38,0,0xffffffff);
  FUN_00401660(param_1 + 0x54,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x70) = *(undefined1 *)(param_1 + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  return;
}


// ==== FUN_0041f1d0 @ 0x0041f1d0 ====

void FUN_0041f1d0(int param_1)

{
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x38) = *(undefined1 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined2 *)(in_ECX + 0x5c) = *(undefined2 *)(param_1 + 0x5c);
  return;
}


// ==== FUN_0041f240 @ 0x0041f240 ====

void FUN_0041f240(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979753;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041eef0(param_1);
  local_4 = 0;
  FUN_0041edc0(param_1 + 0x78);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0041efb0(param_1 + 0xb4);
  *(undefined2 *)(in_ECX + 0x114) = *(undefined2 *)(param_1 + 0x114);
  *(undefined1 *)(in_ECX + 0x116) = *(undefined1 *)(param_1 + 0x116);
  *(undefined2 *)(in_ECX + 0x118) = *(undefined2 *)(param_1 + 0x118);
  *(undefined2 *)(in_ECX + 0x11a) = *(undefined2 *)(param_1 + 0x11a);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0041f2e0 @ 0x0041f2e0 ====

void FUN_0041f2e0(uint param_1)

{
  int in_ECX;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979828;
  local_c = ExceptionList;
  if (0x2e8ba2eU - *(int *)(in_ECX + 8) < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_0041f380 @ 0x0041f380 ====

void FUN_0041f380(void)

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
  puStack_8 = &LAB_00979828;
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


// ==== FUN_0041f3f0 @ 0x0041f3f0 ====

void FUN_0041f3f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  in_ECX[3] = *param_4;
  _eh_vector_copy_constructor_iterator_(in_ECX + 4,param_4 + 1,0x1c,4,FUN_00765c50,FUN_00446f10);
  *(undefined1 *)(in_ECX + 0x20) = param_5;
  *(undefined1 *)((int)in_ECX + 0x81) = 0;
  return;
}


// ==== FUN_0041f450 @ 0x0041f450 ====

void FUN_0041f450(int param_1)

{
  int in_ECX;
  
  FUN_0041f170(param_1);
  FUN_00401660(param_1 + 0x78,0,0xffffffff);
  FUN_00401660(param_1 + 0x94,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0xb0) = *(undefined2 *)(param_1 + 0xb0);
  FUN_0041f1d0(param_1 + 0xb4);
  *(undefined2 *)(in_ECX + 0x114) = *(undefined2 *)(param_1 + 0x114);
  *(undefined1 *)(in_ECX + 0x116) = *(undefined1 *)(param_1 + 0x116);
  *(undefined2 *)(in_ECX + 0x118) = *(undefined2 *)(param_1 + 0x118);
  *(undefined2 *)(in_ECX + 0x11a) = *(undefined2 *)(param_1 + 0x11a);
  return;
}


// ==== FUN_0041f4e0 @ 0x0041f4e0 ====

void FUN_0041f4e0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979760;
  local_10 = ExceptionList;
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
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar5 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_0041f380();
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
      pvVar3 = operator_new(uVar2 * 4);
      local_8 = 0;
      iVar5 = FUN_0042ea40(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0045d020(iVar5,param_2,&param_3);
      FUN_0042ea40(param_1,*(undefined4 *)(in_ECX + 8),iVar5 + param_2 * 4);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar3);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - param_1 >> 2) < param_2) {
      FUN_0042ea40(param_1,iVar1,iVar5 + param_1);
      local_8 = 2;
      FUN_0041ea60(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_0042ea40(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0056bf90(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,iVar5 + param_1,&param_3);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0041f649 @ 0x0041f649 ====

void Catch_0041f649(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0041f720 @ 0x0041f720 ====

void * FUN_0041f720(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979781;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x84);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_0041f3f0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0041f795 @ 0x0041f795 ====

void Catch_0041f795(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0041f7b0 @ 0x0041f7b0 ====

undefined4 *
FUN_0041f7b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009797a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x74);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(undefined2 *)(puVar1 + 3) = *param_4;
    FUN_0041ee40(param_4 + 2);
    *(undefined1 *)(puVar1 + 0x1c) = param_5;
    *(undefined1 *)((int)puVar1 + 0x71) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0041f838 @ 0x0041f838 ====

void Catch_0041f838(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0041f850 @ 0x0041f850 ====

void FUN_0041f850(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  if (_Memory == *(void **)(in_ECX + 4)) {
    return;
  }
  FUN_0041ea90();
  _free(_Memory);
  return;
}


// ==== FUN_0041f890 @ 0x0041f890 ====

undefined4 * FUN_0041f890(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009797c1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x60);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_2;
    *puVar1 = param_1;
    FUN_0041f070(param_3);
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0041f8fe @ 0x0041f8fe ====

void Catch_0041f8fe(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0041f920 @ 0x0041f920 ====

void FUN_0041f920(uint param_1,undefined4 param_2)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009797d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    uVar1 = param_1;
    if (0x3fffffff < param_1) {
      uVar1 = FUN_0041f380();
    }
    uVar1 = uVar1 * 4;
    pvVar2 = operator_new(uVar1);
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 + (int)pvVar2);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    local_8 = 0;
    FUN_0045d020(pvVar2,param_1,param_2);
    *(void **)(in_ECX + 8) = (void *)(uVar1 + (int)pvVar2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0041f9b6 @ 0x0041f9b6 ====

void Catch_0041f9b6(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0041f9d0 @ 0x0041f9d0 ====

/* WARNING: Removing unreachable block (ram,0x0041faf9) */
/* WARNING: Removing unreachable block (ram,0x0041fb09) */
/* WARNING: Removing unreachable block (ram,0x0041fb15) */
/* WARNING: Removing unreachable block (ram,0x0041fb18) */
/* WARNING: Removing unreachable block (ram,0x0041fb05) */
/* WARNING: Removing unreachable block (ram,0x0041fb26) */
/* WARNING: Removing unreachable block (ram,0x0041fb33) */
/* WARNING: Removing unreachable block (ram,0x0041fb3e) */
/* WARNING: Removing unreachable block (ram,0x0041fb3a) */
/* WARNING: Removing unreachable block (ram,0x0041fb2e) */
/* WARNING: Removing unreachable block (ram,0x0041fb41) */

void FUN_0041f9d0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00979828;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x81) != '\0') {
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
  FUN_0041e010();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x81) == '\0') {
    if (*(char *)(param_2[2] + 0x81) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x81) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x81) == '\0') {
      piVar3 = (int *)FUN_0041df50(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x81) == '\0') {
      uVar4 = FUN_0041df30(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x20] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x20] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x20] == '\0') {
            *(undefined1 *)(piVar5 + 0x20) = 1;
            *(undefined1 *)(piVar3 + 0x20) = 0;
            FUN_0041e2a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x81) == '\0') {
            if ((*(char *)(*piVar5 + 0x80) == '\x01') && (*(char *)(piVar5[2] + 0x80) == '\x01'))
            goto LAB_0041fc6b;
            if (*(char *)(piVar5[2] + 0x80) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x80) = 1;
              *(undefined1 *)(piVar5 + 0x20) = 0;
              FUN_0041e300(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x20) = (char)piVar3[0x20];
            *(undefined1 *)(piVar3 + 0x20) = 1;
            *(undefined1 *)(piVar5[2] + 0x80) = 1;
            FUN_0041e2a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x20] == '\0') {
            *(undefined1 *)(piVar5 + 0x20) = 1;
            *(undefined1 *)(piVar3 + 0x20) = 0;
            FUN_0041e300(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x81) == '\0') {
            if ((*(char *)(piVar5[2] + 0x80) != '\x01') || (*(char *)(*piVar5 + 0x80) != '\x01')) {
              if (*(char *)(*piVar5 + 0x80) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x80) = 1;
                *(undefined1 *)(piVar5 + 0x20) = 0;
                FUN_0041e2a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x20) = (char)piVar3[0x20];
              *(undefined1 *)(piVar3 + 0x20) = 1;
              *(undefined1 *)(*piVar5 + 0x80) = 1;
              FUN_0041e300(piVar3);
              break;
            }
LAB_0041fc6b:
            *(undefined1 *)(piVar5 + 0x20) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x20) = 1;
  }
  _eh_vector_destructor_iterator_(param_2 + 4,0x1c,4,FUN_00446f10);
  _free(param_2);
  return;
}


// ==== FUN_0041fd20 @ 0x0041fd20 ====

/* WARNING: Removing unreachable block (ram,0x0041fe33) */
/* WARNING: Removing unreachable block (ram,0x0041fe43) */
/* WARNING: Removing unreachable block (ram,0x0041fe4c) */
/* WARNING: Removing unreachable block (ram,0x0041fe4f) */
/* WARNING: Removing unreachable block (ram,0x0041fe3f) */
/* WARNING: Removing unreachable block (ram,0x0041fe5d) */
/* WARNING: Removing unreachable block (ram,0x0041fe6a) */
/* WARNING: Removing unreachable block (ram,0x0041fe75) */
/* WARNING: Removing unreachable block (ram,0x0041fe71) */
/* WARNING: Removing unreachable block (ram,0x0041fe65) */
/* WARNING: Removing unreachable block (ram,0x0041fe78) */

void FUN_0041fd20(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00979828;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x71) != '\0') {
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
  FUN_0041e070();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x71) == '\0') {
    if (*(char *)(param_2[2] + 0x71) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x71) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x71) == '\0') {
      piVar3 = (int *)FUN_0041df90(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x71) == '\0') {
      uVar4 = FUN_0041df70(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x1c] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x1c] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x1c] == '\0') {
            *(undefined1 *)(piVar5 + 0x1c) = 1;
            *(undefined1 *)(piVar3 + 0x1c) = 0;
            FUN_0041e360(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x71) == '\0') {
            if ((*(char *)(*piVar5 + 0x70) == '\x01') && (*(char *)(piVar5[2] + 0x70) == '\x01'))
            goto LAB_0041ff45;
            if (*(char *)(piVar5[2] + 0x70) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x70) = 1;
              *(undefined1 *)(piVar5 + 0x1c) = 0;
              FUN_0041e3b0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x1c) = (char)piVar3[0x1c];
            *(undefined1 *)(piVar3 + 0x1c) = 1;
            *(undefined1 *)(piVar5[2] + 0x70) = 1;
            FUN_0041e360(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x1c] == '\0') {
            *(undefined1 *)(piVar5 + 0x1c) = 1;
            *(undefined1 *)(piVar3 + 0x1c) = 0;
            FUN_0041e3b0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x71) == '\0') {
            if ((*(char *)(piVar5[2] + 0x70) != '\x01') || (*(char *)(*piVar5 + 0x70) != '\x01')) {
              if (*(char *)(*piVar5 + 0x70) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x70) = 1;
                *(undefined1 *)(piVar5 + 0x1c) = 0;
                FUN_0041e360(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x1c) = (char)piVar3[0x1c];
              *(undefined1 *)(piVar3 + 0x1c) = 1;
              *(undefined1 *)(*piVar5 + 0x70) = 1;
              FUN_0041e3b0(piVar3);
              break;
            }
LAB_0041ff45:
            *(undefined1 *)(piVar5 + 0x1c) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x1c) = 1;
  }
  FUN_0041e9e0();
  _free(param_2);
  return;
}


// ==== FUN_0041ffe0 @ 0x0041ffe0 ====

void FUN_0041ffe0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  *(undefined2 *)(in_ECX + 3) = *param_4;
  _eh_vector_copy_constructor_iterator_(in_ECX + 4,param_4 + 2,0x3c,6,FUN_0041edc0,FUN_0040a7d0);
  *(undefined1 *)(in_ECX + 0x5e) = *(undefined1 *)(param_4 + 0xb6);
  *(undefined1 *)(in_ECX + 0x5f) = param_5;
  *(undefined1 *)((int)in_ECX + 0x17d) = 0;
  return;
}


