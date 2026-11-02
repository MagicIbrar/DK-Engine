// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x570000-0x57ffff

// ==== FUN_00570010 @ 0x00570010 ====

void FUN_00570010(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  in_ECX[0x26] = *(int *)(param_1 + 0x338);
  in_ECX[0x27] = *(int *)(param_1 + 0x33c);
  in_ECX[0x28] = *(int *)(param_1 + 0x340);
  in_ECX[0x29] = *(int *)(param_1 + 0x344);
  in_ECX[0x2a] = *(int *)(param_1 + 0x348);
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  in_ECX[0x1c] = ((*(int *)(iVar1 + 0x14) + in_ECX[0x29] * -2) - *(int *)(iVar1 + 0xc)) /
                 in_ECX[0x27];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_005700d0 @ 0x005700d0 ====

void FUN_005700d0(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0xac);
    local_8 = *(undefined4 *)(in_ECX + 0xb0);
    local_4 = *(undefined4 *)(in_ECX + 0xb4);
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


// ==== FUN_005701a0 @ 0x005701a0 ====

undefined4 FUN_005701a0(int param_1)

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


// ==== FUN_00570230 @ 0x00570230 ====

void FUN_00570230(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x80);
  for (puVar5 = *(undefined4 **)(in_ECX + 0x7c); puVar5 != puVar1; puVar5 = puVar5 + 2) {
    piVar2 = (int *)*puVar5;
    iVar3 = (**(code **)(*piVar2 + 0x3c))();
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*piVar2 + 0x3c))();
      (**(code **)(*piVar4 + 0x7c))(piVar2);
    }
  }
  if (*(void **)(in_ECX + 0x7c) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
    *(undefined4 *)(in_ECX + 0x84) = 0;
                    /* WARNING: Could not recover jumptable at 0x00570290. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    return;
  }
  _free(*(void **)(in_ECX + 0x7c));
  return;
}


// ==== FUN_005702d0 @ 0x005702d0 ====

void FUN_005702d0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  int local_44;
  undefined1 auStack_3c [12];
  int iStack_30;
  int iStack_28;
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 0xb8) != 0) {
    if (*(int *)(in_ECX + 0x7c) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 3;
    }
    uVar4 = iVar6 - *(int *)(in_ECX + 0x70);
    FUN_0055aac0(uVar4 & ((int)uVar4 < 1) - 1);
    iVar1 = *(int *)(*(int *)(in_ECX + 0xb8) + 0x88);
    uVar4 = 0;
    if (0 < iVar6) {
      local_44 = -iVar1;
      do {
        iVar2 = *(int *)(in_ECX + 0x7c);
        if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x80) - iVar2 >> 3) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        piVar3 = *(int **)(iVar2 + uVar4 * 8);
        uVar5 = (**(code **)(*piVar3 + 0x10))();
        FUN_005041e0(uVar5);
        if ((int)uVar4 < iVar1) {
          auStack_3c[0] = 0;
        }
        else if ((int)uVar4 < *(int *)(in_ECX + 0x70) + iVar1) {
          iStack_30 = local_44 * *(int *)(in_ECX + 0x9c) + *(int *)(in_ECX + 0xa4);
          auStack_3c[0] = 1;
          iStack_28 = *(int *)(in_ECX + 0x9c) + -2 + iStack_30;
        }
        else {
          auStack_3c[0] = 0;
        }
        (**(code **)(*piVar3 + 0xc))(auStack_3c);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        local_44 = local_44 + 1;
        uVar4 = uVar4 + 1;
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      } while ((int)uVar4 < iVar6);
    }
  }
  return;
}


// ==== FUN_00570410 @ 0x00570410 ====

void FUN_00570410(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd25c);
  FUN_00402220(apvStack_1c,uVar2);
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(apvStack_1c);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
    iVar3 = FUN_00803725(uVar2);
    in_ECX[0x2e] = iVar3;
  }
  return;
}


// ==== FUN_005704a0 @ 0x005704a0 ====

undefined4 FUN_005704a0(int param_1)

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
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar2 != (int *)0x0) {
    uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd25c);
    FUN_00402220(apvStack_1c,uVar5);
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(apvStack_1c);
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


// ==== FUN_005705a0 @ 0x005705a0 ====

undefined4 FUN_005705a0(int *param_1)

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
    cVar1 = FUN_0056ffb0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_0056ff00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if ((iVar2 == 0x10010) && (cVar1 = FUN_005704a0(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_00570620 @ 0x00570620 ====

void FUN_00570620(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd2cc;
  in_ECX[0x1c] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00570690 @ 0x00570690 ====

void FUN_00570690(void)

{
  undefined4 *in_ECX;
  undefined4 local_104;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009bd2cc;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((void *)in_ECX[0x1f] != (void *)0x0) {
      _free((void *)in_ECX[0x1f]);
      return;
    }
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
    if (*(char *)(in_ECX + 0x11) == '\0') {
      FUN_0044a580(local_100,&DAT_009bd2bc,s_VScroll_Close_Fail_009bd238);
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
  if (in_ECX[0x23] != 0) {
    FUN_00405de0(in_ECX[0x23],in_ECX[0x24],in_ECX + 0x22,local_104);
    _free((void *)in_ECX[0x23]);
    return;
  }
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  if ((void *)in_ECX[0x1f] == (void *)0x0) {
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x1f]);
  return;
}


// ==== FUN_00570770 @ 0x00570770 ====

/* WARNING: Removing unreachable block (ram,0x00570811) */

void FUN_00570770(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009bd264,1);
  FUN_00405300(param_1,local_1c,local_2c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  puVar7 = *(undefined4 **)(in_ECX + 0x7c);
  puVar1 = *(undefined4 **)(in_ECX + 0x80);
  do {
    if (puVar7 == puVar1) {
      if (local_28 == (void *)0x0) {
        return;
      }
      FUN_00405de0(local_28,local_24,local_2c,param_1);
      _free(local_28);
      return;
    }
    iVar4 = (**(code **)(*(int *)*puVar7 + 0x50))();
    uVar2 = *(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      pbVar8 = (byte *)(param_1 + 4);
    }
    else {
      pbVar8 = *(byte **)(param_1 + 4);
    }
    uVar3 = *(uint *)(iVar4 + 0x14);
    if (uVar3 == 0) {
LAB_0057083f:
      if ((uVar3 < uVar2) || (uVar3 != uVar2)) goto LAB_0057084e;
      uVar11 = 1;
    }
    else {
      uVar6 = uVar3;
      if (uVar2 <= uVar3) {
        uVar6 = uVar2;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar9 = false;
      iVar4 = 0;
      bVar10 = true;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar9 = *pbVar5 < *pbVar8;
        bVar10 = *pbVar5 == *pbVar8;
        pbVar5 = pbVar5 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (!bVar10) {
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
      if (iVar4 == 0) goto LAB_0057083f;
LAB_0057084e:
      uVar11 = 0;
    }
    FUN_00571900(uVar11);
    puVar7 = puVar7 + 2;
  } while( true );
}


// ==== FUN_005708a0 @ 0x005708a0 ====

undefined4 FUN_005708a0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 ****ppppuVar4;
  int iVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *piVar6;
  int *in_ECX;
  bool bVar7;
  char *pcVar8;
  undefined1 auStack_38 [4];
  undefined4 ****local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  bVar7 = false;
  if (param_1 == 4) {
    bVar7 = true;
    uVar3 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd25c);
    FUN_00402220(auStack_38,uVar3);
    ppppuVar4 = local_34;
    if (local_20 < 0x10) {
      ppppuVar4 = &local_34;
    }
    iVar5 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppuVar4,uStack_24);
    if ((iVar5 == 0) && (bVar1 = true, param_3 == 6)) goto LAB_00570913;
  }
  bVar1 = false;
LAB_00570913:
  if ((bVar7) && (0xf < local_20)) {
    _free(local_34);
    return extraout_EAX;
  }
  if (bVar1) {
    FUN_005702d0();
    return 1;
  }
  if ((param_1 != 0x17) || (param_3 != 1)) {
    return 0;
  }
  local_34 = (undefined4 ****)0x0;
  uStack_30 = 0;
  uStack_2c = 0;
  FUN_00401830(&DAT_009bd24c);
  FUN_00405300(param_2,auStack_1c,auStack_38);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_00;
  }
  pcVar8 = s_listcontent_009bd250;
  uVar3 = FUN_00405d30(0);
  cVar2 = FUN_004036a0(uVar3,pcVar8);
  if (cVar2 != '\0') {
    FUN_00570770(param_2);
    piVar6 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar5 = *piVar6;
    uVar3 = FUN_00405d30(1);
    uVar3 = thunk_FUN_00796fb0(uVar3);
    (**(code **)(iVar5 + 0x80))(1,uVar3);
  }
  FUN_00406250();
  return 1;
}


// ==== FUN_00570a10 @ 0x00570a10 ====

void FUN_00570a10(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  FUN_0043b3d0(param_1);
  iVar3 = *(int *)(in_ECX + 0x7c);
  iVar1 = *(int *)(in_ECX + 0x80);
  iVar2 = *(int *)(param_1 + 4);
  do {
    if (iVar3 == iVar1) {
      return;
    }
    if (iVar2 != *(int *)(param_1 + 8)) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar2,0,0xffffffff);
      if (local_8 != 0) {
        FUN_00571c80(local_1c);
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      local_18 = (void *)((uint)local_18 & 0xffffff00);
    }
    iVar3 = iVar3 + 8;
    iVar2 = iVar2 + 0x1c;
  } while( true );
}


// ==== FUN_00570b90 @ 0x00570b90 ====

void FUN_00570b90(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  void *local_94;
  undefined1 local_90;
  undefined4 uStack_84;
  uint local_80;
  undefined4 local_7c [31];
  
  local_7c[0] = 0xf;
  local_80 = 0;
  local_90 = 0;
  FUN_00401740(s_maillist_listcontent_0_009bd278,0x16);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&local_94);
  if (0xf < local_80) {
    _free(local_94);
    return;
  }
  local_80 = 0xf;
  uStack_84 = 0;
  local_94 = (void *)((uint)local_94 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    FUN_00571490(iVar2 + 0x80);
    FUN_00571580(local_7c);
    FUN_00505210();
  }
  return;
}


// ==== FUN_00570c40 @ 0x00570c40 ====

void FUN_00570c40(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  char *pcVar7;
  int unaff_EBX;
  int *unaff_retaddr;
  int *local_c8;
  undefined4 local_b8;
  undefined4 uStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 uStack_94;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [4];
  undefined1 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_48;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  int iStack_10;
  uint uStack_8;
  
  local_b8 = in_ECX + 0x78;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  (**(code **)(*DAT_00b5a7ac + 8))();
  local_b8._0_3_ = CONCAT12(1,(undefined2)local_b8);
  uStack_b4 = 0;
  iStack_b0 = 0;
  iStack_ac = 0;
  iStack_a8 = 0;
  iStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_80 = 0xf;
  uStack_84 = 0;
  uStack_94 = 0;
  uStack_64 = 0xf;
  uStack_68 = 0;
  uStack_78 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    local_c8 = (int *)0x0;
  }
  else {
    local_c8 = (int *)FUN_00505f10();
  }
  FUN_0056b080();
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_34 = 0xf;
  uStack_38 = 0;
  uStack_48 = 0;
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = 1;
  uStack_24 = 0;
  uStack_23 = 0;
  FUN_00570b90(local_c8);
  local_c8[0xb2] = *unaff_retaddr;
  FUN_00406720(unaff_retaddr + 2);
  FUN_00406720(unaff_retaddr + 0x10);
  FUN_00406720(unaff_retaddr + 9);
  FUN_00401740(s_listcontent__x_009bd268,0xe);
  iVar5 = FUN_00404230(auStack_20);
  if (*(uint *)(iVar5 + 0x18) < 0x10) {
    pcVar7 = (char *)(iVar5 + 4);
  }
  else {
    pcVar7 = *(char **)(iVar5 + 4);
  }
  pcVar6 = pcVar7;
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(pcVar7,(int)pcVar6 - (int)(pcVar7 + 1));
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  FUN_00401660(auStack_7c,0,0xffffffff);
  iStack_b0 = *(int *)(in_ECX + 0xa0);
  iStack_ac = *(int *)(in_ECX + 0x9c) * unaff_EBX + *(int *)(in_ECX + 0xa4);
  if (unaff_EBX != 0) {
    iStack_ac = iStack_ac + *(int *)(in_ECX + 0xa8) * unaff_EBX;
  }
  iStack_a8 = *(int *)(in_ECX + 0x98) + iStack_b0;
  iStack_a4 = *(int *)(in_ECX + 0x9c) + iStack_ac;
  uStack_b4 = 0x32;
  local_b8 = CONCAT22(local_b8._2_2_,0x101);
  (**(code **)(*piVar3 + 8))(&local_b8);
  piVar1 = *(int **)(in_ECX + 4);
  if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 0x74))(piVar1), cVar2 != '\0')) {
    cVar2 = (**(code **)(*piVar1 + 0x78))(piVar3);
    if (cVar2 == '\0') {
      (**(code **)(*piVar3 + 0x74))(0);
    }
    else {
      iVar5 = (**(code **)(*piVar1 + 0x38))();
      piVar3[1] = iVar5;
    }
  }
  (**(code **)(*local_c8 + 0x38))(piVar3);
  (**(code **)(*local_c8 + 0x1c))(&uStack_84);
  (**(code **)(*local_c8 + 8))(&uStack_60);
  *(undefined1 *)((int)local_c8 + 0x71) = *(undefined1 *)(iStack_10 + 4);
  (**(code **)(*piVar3 + 0x2c))(local_c8);
  (**(code **)(*local_c8 + 0x24))(0x17);
  FUN_00505d80();
  _free((void *)0x17);
  return;
}


// ==== FUN_00570fc0 @ 0x00570fc0 ====

void FUN_00570fc0(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_00570230();
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x78) {
    FUN_00570c40(iVar2);
  }
  FUN_005702d0();
  return;
}


// ==== FUN_00571000 @ 0x00571000 ====

int FUN_00571000(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982040;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    FUN_005767c0(param_3,param_1);
    param_3 = param_3 + 8;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00571066 @ 0x00571066 ====

void Catch_00571066(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00571070 @ 0x00571070 ====

void FUN_00571070(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982050;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005767c0(param_1,param_3);
    param_1 = param_1 + 8;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005710d6 @ 0x005710d6 ====

void Catch_005710d6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005710e0 @ 0x005710e0 ====

void FUN_005710e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00571000(param_1,param_2,param_3);
  return;
}


// ==== FUN_00571100 @ 0x00571100 ====

int FUN_00571100(int param_1,int param_2,undefined4 param_3)

{
  FUN_00571070(param_1,param_2,param_3);
  return param_1 + param_2 * 8;
}


// ==== FUN_00571130 @ 0x00571130 ====

void FUN_00571130(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  int local_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982060;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
  local_38 = *param_3;
  local_34 = param_3[1];
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(in_ECX + 0xc) - iVar2 >> 3;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    uVar5 = param_2;
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x44);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_0085b3b0();
      uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
      local_20 = (uint)uVar7;
      iVar2 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    if (local_20 < iVar6 + uVar5) {
      if (0x1fffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar2 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
      }
      if (local_20 < iVar6 + uVar5) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 3;
        }
        local_20 = iVar2 + uVar5;
      }
      local_20 = local_20 * 8;
      pvVar3 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar3;
      local_1c = FUN_005710e0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_1c = FUN_00571100(local_1c,param_2,&local_38);
      FUN_005710e0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar3;
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 8);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar2 = *(int *)(in_ECX + 8);
    if ((uint)(iVar2 - param_1 >> 3) < uVar5) {
      local_18 = uVar5 * 8;
      FUN_00571000(param_1,iVar2,local_18 + param_1);
      local_8 = 2;
      FUN_00571100(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_38);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) - local_18,&local_38);
      ExceptionList = local_10;
      return;
    }
    local_18 = uVar5 * 8;
    local_28 = iVar2 + uVar5 * -8;
    uVar4 = FUN_00571000(local_28,iVar2,iVar2);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00576790(param_1,local_28,iVar2);
    FUN_00686630(param_1,local_18 + param_1,&local_38);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00571299 @ 0x00571299 ====

void Catch_00571299(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_00571390 @ 0x00571390 ====

void FUN_00571390(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982070;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_005040e0(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@00571408 @ 0x00571408 ====

void Catch_00571408(void)

{
  FUN_00504550();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00571420 @ 0x00571420 ====

void FUN_00571420(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_00571130(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00571070(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_00571490 @ 0x00571490 ====

void FUN_00571490(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  FUN_00571390(param_1 + 3);
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  in_ECX[0xf] = param_1[0xf];
  in_ECX[0x10] = param_1[0x10];
  in_ECX[0x11] = param_1[0x11];
  in_ECX[0x12] = param_1[0x12];
  in_ECX[0x13] = param_1[0x13];
  in_ECX[0x14] = param_1[0x14];
  in_ECX[0x15] = param_1[0x15];
  FUN_00406600(param_1 + 0x16);
  in_ECX[0x1a] = param_1[0x1a];
  in_ECX[0x1b] = param_1[0x1b];
  in_ECX[0x1c] = param_1[0x1c];
  in_ECX[0x1d] = param_1[0x1d];
  return;
}


// ==== FUN_00571560 @ 0x00571560 ====

void FUN_00571560(byte param_1)

{
  void *in_ECX;
  
  FUN_00570690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00571580 @ 0x00571580 ====

void FUN_00571580(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  puVar2 = param_1;
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  puVar1 = param_1 + 3;
  in_ECX[2] = param_1[2];
  if (in_ECX + 3 != puVar1) {
    FUN_00504490(&param_1,*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4]);
    FUN_005040e0(puVar1);
  }
  in_ECX[6] = puVar2[6];
  in_ECX[7] = puVar2[7];
  in_ECX[8] = puVar2[8];
  in_ECX[9] = puVar2[9];
  in_ECX[10] = puVar2[10];
  in_ECX[0xb] = puVar2[0xb];
  in_ECX[0xc] = puVar2[0xc];
  in_ECX[0xd] = puVar2[0xd];
  in_ECX[0xe] = puVar2[0xe];
  in_ECX[0xf] = puVar2[0xf];
  in_ECX[0x10] = puVar2[0x10];
  in_ECX[0x11] = puVar2[0x11];
  in_ECX[0x12] = puVar2[0x12];
  in_ECX[0x13] = puVar2[0x13];
  in_ECX[0x14] = puVar2[0x14];
  in_ECX[0x15] = puVar2[0x15];
  FUN_0043b3d0(puVar2 + 0x16);
  in_ECX[0x1a] = puVar2[0x1a];
  in_ECX[0x1b] = puVar2[0x1b];
  in_ECX[0x1c] = puVar2[0x1c];
  in_ECX[0x1d] = puVar2[0x1d];
  return;
}


// ==== FUN_00571660 @ 0x00571660 ====

void FUN_00571660(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00571680 @ 0x00571680 ====

undefined4 FUN_00571680(void)

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


// ==== FUN_005716e0 @ 0x005716e0 ====

void FUN_005716e0(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0x74);
    local_8 = *(undefined4 *)(in_ECX + 0x78);
    local_4 = *(undefined4 *)(in_ECX + 0x7c);
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


// ==== FUN_005717b0 @ 0x005717b0 ====

void FUN_005717b0(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 local_8;
  int local_4;
  
  if ((char)in_ECX[0x1c] == '\0') {
    local_8 = 1;
    FUN_00558e00(&local_4,&local_8);
    if (local_4 != in_ECX[0x24]) {
      in_ECX[0x1d] = *(int *)(local_4 + 0x10);
      in_ECX[0x1e] = *(int *)(local_4 + 0x14);
      in_ECX[0x1f] = *(int *)(local_4 + 0x18);
      (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    }
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(4,0);
  }
  return;
}


// ==== FUN_00571820 @ 0x00571820 ====

void FUN_00571820(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 local_8;
  int local_4;
  
  if ((char)in_ECX[0x1c] == '\0') {
    local_8 = 1;
    FUN_00558e00(&local_4,&local_8);
    if (local_4 != in_ECX[0x24]) {
      in_ECX[0x1d] = *(int *)(local_4 + 0x10);
      in_ECX[0x1e] = *(int *)(local_4 + 0x14);
      in_ECX[0x1f] = *(int *)(local_4 + 0x18);
      (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    }
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(1,0);
  }
  return;
}


// ==== FUN_00571890 @ 0x00571890 ====

void FUN_00571890(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 local_8;
  int local_4;
  
  if ((char)in_ECX[0x1c] == '\0') {
    local_8 = 0;
    FUN_00558e00(&local_4,&local_8);
    if (local_4 != in_ECX[0x24]) {
      in_ECX[0x1d] = *(int *)(local_4 + 0x10);
      in_ECX[0x1e] = *(int *)(local_4 + 0x14);
      in_ECX[0x1f] = *(int *)(local_4 + 0x18);
      (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    }
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(5,0);
  }
  return;
}


// ==== FUN_00571900 @ 0x00571900 ====

void FUN_00571900(char param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 local_4 [4];
  
  *(char *)(in_ECX + 0x1c) = param_1;
  if (param_1 == '\0') {
    _param_1 = 0;
  }
  else {
    _param_1 = 4;
  }
  piVar2 = (int *)FUN_00558e00(local_4,&param_1);
  iVar1 = *piVar2;
  if (iVar1 != in_ECX[0x24]) {
    in_ECX[0x1d] = *(int *)(iVar1 + 0x10);
    in_ECX[0x1e] = *(int *)(iVar1 + 0x14);
    in_ECX[0x1f] = *(int *)(iVar1 + 0x18);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_00571970 @ 0x00571970 ====

undefined4 FUN_00571970(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    iVar1 = param_1[2];
    if (iVar1 == 1) {
      FUN_00571820();
      return 1;
    }
    if (iVar1 == 7) {
      FUN_005717b0();
      return 1;
    }
    if (iVar1 == 8) {
      FUN_00571890();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005719e0 @ 0x005719e0 ====

undefined4 FUN_005719e0(int param_1,undefined4 param_2,int param_3)

{
  if ((param_1 == 0) || (param_1 == 8)) {
    if (param_3 == 1) {
      FUN_00571820();
      return 1;
    }
    if (param_3 == 4) {
      FUN_005717b0();
      return 1;
    }
    if (param_3 == 5) {
      FUN_00571890();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00571a30 @ 0x00571a30 ====

undefined4 FUN_00571a30(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00571970(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00571a60 @ 0x00571a60 ====

undefined4 FUN_00571a60(int param_1)

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


// ==== FUN_00571c80 @ 0x00571c80 ====

void FUN_00571c80(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined4 unaff_retaddr;
  undefined1 auStack_54 [2];
  undefined1 auStack_52 [2];
  void *local_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  void *local_40;
  void *local_3c;
  void *pvStack_38;
  undefined1 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  FUN_00401660(param_1,0,0xffffffff);
  local_3c = (void *)0xf;
  local_40 = (void *)0x0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar1 + 0x50))(s__icon_009bd384);
  uVar2 = FUN_00402220(&pvStack_1c,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  pvStack_20 = (void *)0xf;
  pvStack_24 = (void *)0x0;
  uStack_34 = 0;
  FUN_00401660(auStack_54,0,0xffffffff);
  if ((void *)0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = (void *)0xf;
  local_40 = (void *)0x0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&pvStack_38);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
  }
  if ((void *)0xf < pvStack_24) {
    _free(pvStack_38);
    return;
  }
  pvStack_24 = (void *)0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 0x18))();
    if (iVar3 == 0) {
      FUN_00401660(unaff_retaddr,0,0xffffffff);
    }
  }
  pvStack_24 = (void *)0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar1 + 0x50))(s__title_009bd38c);
  uVar2 = FUN_00402220(&pvStack_20,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  local_40 = (void *)0xf;
  uStack_44 = 0;
  auStack_54[0] = 0;
  FUN_00401660(&local_3c,0,0xffffffff);
  if ((void *)0xf < pvStack_24) {
    _free(pvStack_38);
    return;
  }
  pvStack_24 = (void *)0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(auStack_54 + -4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
  }
  if (0xf < uStack_44) {
    _free(unaff_EBX);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 0x18))();
    if (iVar3 == 8) {
      FUN_00401660(uStack_4,0,0xffffffff);
    }
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar1 + 0x50))(s__time_009bd394);
  uVar2 = FUN_00402220(&pvStack_24,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  uStack_44 = 0xf;
  uStack_48 = 0;
  FUN_00401660(&local_40,0,0xffffffff);
  if (0xf < uStack_28) {
    _free(local_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(auStack_54 + -8);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
  }
  if (0xf < uStack_48) {
    _free(unaff_EBP);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 0x18))();
    if (iVar3 == 8) {
      FUN_00401660(uStack_8,0,0xffffffff);
    }
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar1 + 0x50))(s__content_009bd39c);
  uVar2 = FUN_00402220(&uStack_28,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_48 = 0xf;
  uStack_4c = 0;
  FUN_00401660(&uStack_44,0,0xffffffff);
  if (0xf < uStack_2c) {
    _free(local_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(auStack_54 + -0xc);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
  }
  if (0xf < uStack_4c) {
    _free(unaff_ESI);
    return;
  }
  uStack_4c = 0xf;
  local_50 = (void *)0x0;
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 0x18))();
    if (iVar3 == 8) {
      FUN_00401660(uStack_c,0,0xffffffff);
    }
  }
  return;
}


// ==== FUN_005720b0 @ 0x005720b0 ====

void FUN_005720b0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd3b4;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x24] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x24] + 4) = in_ECX[0x24];
  *(undefined4 *)in_ECX[0x24] = in_ECX[0x24];
  *(undefined4 *)(in_ECX[0x24] + 8) = in_ECX[0x24];
  in_ECX[0x25] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)((int)in_ECX + 0x71) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00572150 @ 0x00572150 ====

void FUN_00572150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd3b4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00505210();
  FUN_00552170();
  return;
}


// ==== FUN_00572190 @ 0x00572190 ====

void FUN_00572190(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 ***pppuVar5;
  void *pvVar6;
  int *_Memory;
  int *in_ECX;
  undefined1 auStack_134 [4];
  undefined4 ***apppuStack_130 [4];
  undefined4 uStack_120;
  uint uStack_11c;
  undefined1 auStack_118 [4];
  undefined4 ***pppuStack_114;
  int *piStack_110;
  int *piStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  uint uStack_100;
  int *piStack_fc;
  undefined1 auStack_f8 [4];
  void *pvStack_f4;
  undefined4 uStack_e4;
  uint uStack_e0;
  undefined1 uStack_dc;
  undefined1 uStack_db;
  undefined1 uStack_da;
  int iStack_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  undefined4 uStack_c4;
  undefined4 auStack_c0 [2];
  undefined1 uStack_b8;
  undefined1 auStack_b0 [8];
  undefined4 uStack_a8;
  int *piStack_a4;
  int *piStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 uStack_8c;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined1 uStack_64;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 uStack_3a;
  undefined4 uStack_3c;
  int iStack_38;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return;
  }
  piStack_fc = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piStack_fc + 0x10))();
  FUN_005041e0(uVar2);
  uStack_9c = (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_da = 1;
  iStack_d8 = 0;
  iStack_d4 = 0;
  iStack_d0 = 0;
  iStack_cc = 0;
  iStack_c8 = 0;
  uStack_c4 = 0;
  auStack_c0[0] = 0;
  piStack_a4 = (int *)0xf;
  uStack_a8 = 0;
  uStack_b8 = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_78 = 0xf;
  uStack_7c = 0;
  uStack_8c = 0;
  iStack_74 = 1;
  iStack_70 = 0;
  uStack_6c = 1;
  uStack_68 = 0;
  uStack_67 = 0;
  uStack_100 = 0xf;
  uStack_104 = 0;
  pppuStack_114 = (undefined4 ***)((uint)pppuStack_114 & 0xffffff00);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar3 + 0x50))(s__icon_009bd384);
  uVar2 = FUN_00402220(auStack_f8,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_e0) {
    _free(pvStack_f4);
    return;
  }
  uStack_e0 = 0xf;
  uStack_e4 = 0;
  pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
  uStack_11c = 0xf;
  uStack_120 = 0;
  apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
  FUN_00401660(auStack_118,0,0xffffffff);
  if (0xf < uStack_100) {
    _free(pppuStack_114);
    return;
  }
  uStack_100 = 0xf;
  uStack_104 = 0;
  pppuStack_114 = (undefined4 ***)((uint)pppuStack_114 & 0xffffff00);
  pppuVar5 = apppuStack_130[0];
  if (uStack_11c < 0x10) {
    pppuVar5 = apppuStack_130;
  }
  iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),pppuVar5,uStack_120);
  if (0xf < uStack_11c) {
    _free(apppuStack_130[0]);
    return;
  }
  if (iVar4 == 0) {
    iStack_d4 = in_ECX[0x26];
    iStack_d0 = in_ECX[0x27];
    iStack_cc = in_ECX[0x28];
    iStack_c8 = in_ECX[0x29];
  }
  else {
    uStack_11c = 0xf;
    uStack_120 = 0;
    apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar2 = (**(code **)(*piVar3 + 0x50))(s__title_009bd38c);
    uVar2 = FUN_00402220(auStack_f8,uVar2);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_e0) {
      _free(pvStack_f4);
      return;
    }
    uStack_e0 = 0xf;
    uStack_e4 = 0;
    pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
    uStack_100 = 0xf;
    uStack_104 = 0;
    pppuStack_114 = (undefined4 ***)((uint)pppuStack_114 & 0xffffff00);
    FUN_00401660(auStack_134,0,0xffffffff);
    if (0xf < uStack_11c) {
      _free(apppuStack_130[0]);
      return;
    }
    uStack_11c = 0xf;
    uStack_120 = 0;
    apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
    pppuVar5 = pppuStack_114;
    if (uStack_100 < 0x10) {
      pppuVar5 = &pppuStack_114;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),pppuVar5,uStack_104);
    if (0xf < uStack_100) {
      _free(pppuStack_114);
      return;
    }
    if (iVar4 == 0) {
      iStack_d4 = in_ECX[0x2a];
      iStack_d0 = in_ECX[0x2b];
      iStack_cc = in_ECX[0x2c];
      iStack_c8 = in_ECX[0x2d];
      iStack_70 = in_ECX[0x3a];
    }
    else {
      uStack_11c = 0xf;
      uStack_120 = 0;
      apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar2 = (**(code **)(*piVar3 + 0x50))(s__time_009bd394);
      uVar2 = FUN_00402220(auStack_f8,uVar2);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < uStack_e0) {
        _free(pvStack_f4);
        return;
      }
      uStack_e0 = 0xf;
      uStack_e4 = 0;
      pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
      uStack_100 = 0xf;
      uStack_104 = 0;
      pppuStack_114 = (undefined4 ***)((uint)pppuStack_114 & 0xffffff00);
      FUN_00401660(auStack_134,0,0xffffffff);
      if (0xf < uStack_11c) {
        _free(apppuStack_130[0]);
        return;
      }
      uStack_11c = 0xf;
      uStack_120 = 0;
      apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
      cVar1 = FUN_00423420(param_1,auStack_118);
      if (0xf < uStack_100) {
        _free(pppuStack_114);
        return;
      }
      if (cVar1 == '\0') {
        uStack_11c = 0xf;
        uStack_120 = 0;
        apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
        piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
        uVar2 = (**(code **)(*piVar3 + 0x50))(s__content_009bd39c);
        uVar2 = FUN_00402220(auStack_f8,uVar2);
        FUN_00401660(uVar2,0,0xffffffff);
        if (0xf < uStack_e0) {
          _free(pvStack_f4);
          return;
        }
        uStack_e0 = 0xf;
        uStack_e4 = 0;
        pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
        uStack_100 = 0xf;
        uStack_104 = 0;
        pppuStack_114 = (undefined4 ***)((uint)pppuStack_114 & 0xffffff00);
        FUN_00401660(auStack_134,0,0xffffffff);
        if (uStack_11c < 0x10) {
          uStack_11c = 0xf;
          uStack_120 = 0;
          apppuStack_130[0] = (undefined4 ***)((uint)apppuStack_130[0] & 0xffffff00);
          FUN_00423420(param_1,auStack_118);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        _free(apppuStack_130[0]);
        return;
      }
      iStack_d4 = in_ECX[0x2e];
      iStack_d0 = in_ECX[0x2f];
      iStack_cc = in_ECX[0x30];
      iStack_c8 = in_ECX[0x31];
      iStack_70 = in_ECX[0x3c];
    }
  }
  FUN_00401660(param_1,0,0xffffffff);
  uStack_db = (undefined1)((uint)uStack_3c >> 8);
  uStack_dc = (undefined1)uStack_3c;
  iStack_d8 = iStack_38 + 10;
  uStack_da = uStack_3a;
  uStack_c4 = 0;
  auStack_c0[0] = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(param_3);
  uStack_50 = 0xf;
  uStack_54 = 0;
  uStack_64 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  piStack_a4 = piVar3;
  pvVar6 = operator_new(0x468);
  if (pvVar6 == (void *)0x0) {
    _Memory = (int *)0x0;
  }
  else {
    _Memory = (int *)FUN_00505f10();
  }
  if (param_2 == 0) {
    FUN_00503950(*(undefined4 *)(_Memory[0x47] + 4));
    *(int *)(_Memory[0x47] + 4) = _Memory[0x47];
    _Memory[0x48] = 0;
    *(int *)_Memory[0x47] = _Memory[0x47];
    *(int *)(_Memory[0x47] + 8) = _Memory[0x47];
    *(undefined1 *)(_Memory + 0x45) = 0;
    *(undefined1 *)((int)_Memory + 0x115) = 0;
    *(undefined1 *)(_Memory + 0x45) = 0;
    *(undefined1 *)((int)_Memory + 0x115) = 0;
    *_Memory = in_ECX[0x20];
    _Memory[1] = in_ECX[0x21];
    _Memory[2] = in_ECX[0x22];
    piVar3 = piStack_a4;
  }
  else if (param_2 == 8) {
    FUN_00401660(param_1,0,0xffffffff);
    uStack_78 = 2;
    _Memory[0x66] = 5;
    _Memory[0x67] = 5;
    *(undefined1 *)(_Memory + 0x65) = 0;
    *(undefined1 *)((int)_Memory + 0x195) = 0;
    *(undefined1 *)((int)_Memory + 0x196) = 0;
    _Memory[0x68] = 0xc;
    if (*(char *)((int)in_ECX + 0x71) == '\x01') {
      iStack_74 = in_ECX[0x3d];
    }
  }
  *(undefined1 *)(_Memory + 3) = 0;
  FUN_00401660(auStack_c0,0,0xffffffff);
  (**(code **)(*piStack_a0 + 8))(&uStack_e0);
  (**(code **)(*piStack_a0 + 0x2c))(piVar3);
  cVar1 = (**(code **)(*piStack_a0 + 0x74))(uStack_108);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*piStack_10c + 0x78))(piStack_a0);
    if (cVar1 == '\0') {
      (**(code **)(*piStack_a0 + 0x74))(0);
    }
    else {
      iVar4 = (**(code **)(*piStack_110 + 0x38))();
      piStack_a0[1] = iVar4;
    }
  }
  (**(code **)(*piVar3 + 0x38))(piStack_a0);
  (**(code **)(*piVar3 + 0x1c))(&uStack_78);
  (**(code **)(*piVar3 + 8))(auStack_b0);
  (**(code **)(*piVar3 + 0x24))(_Memory);
  FUN_00505d80();
  _free(_Memory);
  return;
}


// ==== FUN_005729b0 @ 0x005729b0 ====

void FUN_005729b0(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  int *local_7c;
  int local_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *local_54;
  void *local_50;
  undefined4 uStack_44;
  uint local_40;
  uint local_3c;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  if (param_1 == 0) {
    local_3c = 0xf;
    local_40 = 0;
    local_50 = (void *)((uint)local_50 & 0xffffff00);
    FUN_00401740(s_i_pProperty_009bd374,0xb);
    FUN_00406880(&local_54);
    if (local_3c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_50);
    return;
  }
  FUN_00571580(param_1 + 0x2c0);
  local_7c = (int *)(param_1 + 0x2cc);
  if (in_ECX + 0x23 != local_7c) {
    FUN_00504490(&local_78,*(undefined4 *)in_ECX[0x24],(undefined4 *)in_ECX[0x24]);
    FUN_005040e0(local_7c);
  }
  local_7c = (int *)0x0;
  FUN_00558e00(&local_78,&local_7c);
  if (local_78 == in_ECX[0x24]) {
    in_ECX[0x1d] = 0;
  }
  else {
    in_ECX[0x1d] = *(int *)(local_78 + 0x10);
    in_ECX[0x1e] = *(int *)(local_78 + 0x14);
    in_ECX[0x1f] = *(int *)(local_78 + 0x18);
  }
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  if ((in_ECX[0x37] == 0) ||
     (iVar6 = in_ECX[0x38] - in_ECX[0x37], iVar2 = iVar6 >> 0x1f, iVar6 / 0x1c + iVar2 == iVar2)) {
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(&DAT_009bd380,0);
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar5 = (**(code **)(*piVar4 + 0x50))(s__icon_009bd384);
  uVar5 = FUN_00402220(auStack_20,uVar5);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  local_40 = 0xf;
  uStack_44 = 0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  FUN_00401660(auStack_74,0,0xffffffff);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  FUN_00572190(auStack_58,&local_3c,0);
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  local_40 = 0xf;
  uStack_44 = 0;
  uVar3 = (uint)local_54 >> 8;
  local_54 = (void *)(uVar3 << 8);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  local_7c = (int *)in_ECX[0x37];
  if (local_7c != (int *)0x0) {
    local_78 = (in_ECX[0x38] - (int)local_7c) / 0x1c;
    if (local_78 != 0) {
      local_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)(uVar3 << 8);
      piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar5 = (**(code **)(*piVar4 + 0x50))(s__title_009bd38c);
      uVar5 = FUN_00402220(auStack_20,uVar5);
      FUN_00401660(uVar5,0,0xffffffff);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      FUN_00401660(auStack_58,0,0xffffffff);
      if (0xf < local_40) {
        _free(local_54);
        return;
      }
      local_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      FUN_00572190(&local_3c,local_7c,8);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      if ((in_ECX[0x37] == 0) || ((uint)((in_ECX[0x38] - in_ECX[0x37]) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_7c = (int *)(in_ECX[0x37] + 0x1c);
      local_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar5 = (**(code **)(*piVar4 + 0x50))(s__time_009bd394);
      uVar5 = FUN_00402220(auStack_20,uVar5);
      FUN_00401660(uVar5,0,0xffffffff);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      FUN_00401660(auStack_58,0,0xffffffff);
      if (0xf < local_40) {
        _free(local_54);
        return;
      }
      local_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      FUN_00572190(&local_3c,local_7c,8);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      local_7c = (int *)in_ECX[0x37];
      if ((local_7c == (int *)0x0) || ((uint)((in_ECX[0x38] - (int)local_7c) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_7c = local_7c + 0xe;
      local_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar5 = (**(code **)(*piVar4 + 0x50))(s__content_009bd39c);
      uVar5 = FUN_00402220(auStack_20,uVar5);
      FUN_00401660(uVar5,0,0xffffffff);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      FUN_00401660(auStack_58,0,0xffffffff);
      if (0xf < local_40) {
        _free(local_54);
        return;
      }
      local_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      FUN_00572190(&local_3c,local_7c,8);
      if (uStack_24 < 0x10) {
        return;
      }
      _free(pvStack_38);
      return;
    }
    local_78 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00572ef0 @ 0x00572ef0 ====

void FUN_00572ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd3b4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00505210();
  FUN_00552170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00572f50 @ 0x00572f50 ====

void FUN_00572f50(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00572fa0 @ 0x00572fa0 ====

uint FUN_00572fa0(int *param_1)

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


// ==== FUN_00573000 @ 0x00573000 ====

uint FUN_00573000(int *param_1)

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


// ==== FUN_00573090 @ 0x00573090 ====

void FUN_00573090(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0x88);
    local_8 = *(undefined4 *)(in_ECX + 0x8c);
    local_4 = *(undefined4 *)(in_ECX + 0x90);
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


// ==== FUN_00573160 @ 0x00573160 ====

void FUN_00573160(void)

{
  void *_Memory;
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xbc);
  while (puVar1 != *(undefined4 **)(in_ECX + 0xc0)) {
    _Memory = (void *)*puVar1;
    puVar1 = puVar1 + 1;
    if (_Memory != (void *)0x0) {
      if (*(uint *)((int)_Memory + 0x20) < 0x10) {
        *(undefined4 *)((int)_Memory + 0x20) = 0xf;
        *(undefined4 *)((int)_Memory + 0x1c) = 0;
        *(undefined1 *)((int)_Memory + 0xc) = 0;
        _free(_Memory);
        return;
      }
      _free(*(void **)((int)_Memory + 0xc));
      return;
    }
  }
  if (*(void **)(in_ECX + 0xbc) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    *(undefined4 *)(in_ECX + 0xc0) = 0;
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xbc));
  return;
}


// ==== FUN_005731f0 @ 0x005731f0 ====

undefined4 FUN_005731f0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  FUN_00573160();
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00573220 @ 0x00573220 ====

undefined4 FUN_00573220(int param_1)

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


// ==== FUN_005732b0 @ 0x005732b0 ====

void FUN_005732b0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined4 unaff_retaddr;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined4 local_1c;
  uint uStack_c;
  uint uStack_8;
  
  FUN_00401740(s_lbl_name__d_009bd45c,0xb);
  puVar4 = &local_1c;
  uVar1 = FUN_00404230(puVar4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00559170(param_1);
    }
  }
  if (0xf < uStack_8) {
    _free(local_1c);
    return;
  }
  uVar5 = 0;
  FUN_00401740(s_lbl_channel__d_009bd468,0xe);
  uVar1 = FUN_00404230((int)register0x00000010 + -0x20,puVar4,uVar5);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00559170(unaff_retaddr);
    }
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_005733c0 @ 0x005733c0 ====

void FUN_005733c0(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  void **ppvVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 auStack_42 [10];
  void *local_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  void *apvStack_20 [4];
  undefined4 uStack_10;
  uint uStack_c;
  int *piStack_4;
  
  uVar7 = 0;
  FUN_00401740(s_pan_icon__d_009bd48c,0xb);
  ppvVar5 = local_38;
  uVar1 = FUN_00404230(ppvVar5);
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar1);
  if (0xf < uStack_24) {
    _free(local_38[0]);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  local_38[0] = (void *)((uint)local_38[0] & 0xffffff00);
  if (iVar2 != 0) {
    uVar6 = 0;
    FUN_00401740(s_pan_iconbox__d_009bd498,0xe);
    uVar1 = FUN_00404230(apvStack_20,ppvVar5,uVar6,uVar7);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar1);
    if (0xf < uStack_c) {
      _free(apvStack_20[0]);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    apvStack_20[0] = (void *)((uint)apvStack_20[0] & 0xffffff00);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(iVar2 != 100);
    }
    iVar4 = (**(code **)(*piStack_4 + 0x30))();
    if (iVar4 != 0) {
      if (iVar2 != 100) {
        FUN_00401830(s_messenger_d_009bd4a8);
        (**(code **)(*DAT_00b5a7c0 + 8))(&uStack_24);
        if (0xf < uStack_c) {
          _free(apvStack_20[0]);
          return;
        }
      }
      FUN_00587d40(auStack_42 + -10);
    }
  }
  return;
}


// ==== FUN_00573530 @ 0x00573530 ====

void FUN_00573530(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 ***pppuVar5;
  int *_Dst;
  int *piStack_24;
  undefined1 auStack_1c [4];
  undefined4 ***apppuStack_18 [4];
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x58))();
  _Dst = *(int **)(iVar2 + 4);
  if ((_Dst == (int *)0x0) || (*(int *)(iVar2 + 8) - (int)_Dst >> 2 != 1)) {
    if (_Dst != *(int **)(iVar2 + 8)) {
      piStack_24 = _Dst + 1;
      do {
        piVar1 = (int *)*_Dst;
        if (piVar1 != (int *)0x0) {
          uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009bd484);
          FUN_00402220(auStack_1c,uVar3);
          iVar4 = (**(code **)(*piVar1 + 0x50))();
          pppuVar5 = apppuStack_18[0];
          if (uStack_4 < 0x10) {
            pppuVar5 = apppuStack_18;
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),pppuVar5,uStack_8);
          if (0xf < uStack_4) {
            _free(apppuStack_18[0]);
            return;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          apppuStack_18[0] = (undefined4 ***)((uint)apppuStack_18[0] & 0xffffff00);
          if (iVar4 == 0) {
            _Dst = _Dst + 1;
            piStack_24 = piStack_24 + 1;
          }
          else {
            (**(code **)*piVar1)(1);
            _memmove(_Dst,piStack_24,(*(int *)(iVar2 + 8) - (int)piStack_24 >> 2) * 4);
            *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;
          }
        }
      } while (_Dst != *(int **)(iVar2 + 8));
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
  }
  return;
}


// ==== FUN_00573640 @ 0x00573640 ====

undefined4 FUN_00573640(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = 0;
  if ((*(int *)(in_ECX + 0xbc) != 0) &&
     (param_1 < (uint)(*(int *)(in_ECX + 0xc0) - *(int *)(in_ECX + 0xbc) >> 2))) {
    iVar1 = *(int *)(in_ECX + 0xbc);
    if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xc0) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    uVar2 = *(undefined4 *)(iVar1 + param_1 * 4);
  }
  return uVar2;
}


// ==== FUN_00573680 @ 0x00573680 ====

undefined4 FUN_00573680(int param_1)

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
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  iVar3 = (**(code **)(*piVar2 + 4))();
  if ((iVar4 != iVar3) &&
     (param_1 = iVar4, iVar4 = (**(code **)(*piVar2 + 0x48))(&param_1), iVar4 == 0)) {
    return 0;
  }
  uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd484);
  FUN_00402220(apvStack_1c,uVar5);
  piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(apvStack_1c);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return extraout_EAX;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (((piVar2 == (int *)0x0) || (iVar4 = (**(code **)(*piVar2 + 0x30))(), iVar4 == 0)) ||
     (iVar4 = FUN_00803725(iVar4,0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                           &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0), iVar4 == 0)) {
    return 0;
  }
  if (0 < *(short *)(iVar1 + 4)) {
    FUN_0055aa00();
    return 1;
  }
  if (*(short *)(iVar1 + 4) < 0) {
    FUN_0055aa60();
  }
  return 1;
}


// ==== FUN_00573780 @ 0x00573780 ====

undefined4 FUN_00573780(int *param_1)

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
    cVar1 = FUN_00572fa0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_00573000(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if ((iVar2 == 0x10010) && (cVar1 = FUN_00573680(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_00573800 @ 0x00573800 ====

void FUN_00573800(void)

{
  char cVar1;
  undefined3 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined1 *puVar8;
  char *pcVar9;
  uint uVar10;
  int in_ECX;
  char *pcVar11;
  undefined1 *puVar12;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  void *pvVar13;
  void **ppvVar14;
  undefined1 *in_stack_fffffe78;
  undefined1 uVar15;
  undefined4 uVar16;
  undefined4 uStack_150;
  uint uStack_14c;
  uint uStack_148;
  void *pvStack_144;
  undefined4 uStack_140;
  undefined2 uStack_13c;
  undefined1 uStack_13a;
  char *pcStack_138;
  undefined4 uStack_134;
  void *pvStack_130;
  undefined4 uStack_120;
  uint uStack_11c;
  void *pvStack_118;
  undefined1 uStack_114;
  undefined1 auStack_10c [4];
  void *pvStack_108;
  uint uStack_104;
  undefined4 uStack_100;
  undefined1 auStack_fc [4];
  undefined4 uStack_f8;
  uint uStack_f4;
  void *apvStack_e8 [4];
  undefined4 uStack_d8;
  uint uStack_d4;
  void *pvStack_d0;
  undefined1 auStack_c8 [8];
  undefined4 uStack_c0;
  uint uStack_bc;
  void *apvStack_b4 [4];
  undefined4 uStack_a4;
  uint uStack_a0;
  void *pvStack_98;
  undefined1 auStack_90 [8];
  undefined4 uStack_88;
  uint uStack_84;
  void *pvStack_7c;
  undefined1 auStack_74 [8];
  undefined4 uStack_6c;
  uint uStack_68;
  void *pvStack_60;
  undefined1 auStack_58 [8];
  undefined4 uStack_50;
  uint uStack_4c;
  void *apvStack_38 [4];
  undefined4 uStack_28;
  void *apvStack_24 [4];
  undefined4 uStack_14;
  uint uStack_10;
  
  FUN_00573160();
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x74) + 0x30))();
  uStack_148 = *(uint *)(iVar3 + 0x88);
  puVar12 = (undefined1 *)0x0;
  if ((int)uStack_148 < 0) {
    uStack_148 = 0;
  }
  *(uint *)(in_ECX + 0xb4) = uStack_148;
  pvVar13 = (void *)0x0;
  uStack_14c = 0;
  piVar4 = (int *)(**(code **)(*DAT_00b5ae3c + 0x6c))();
  pvStack_144 = *(void **)(in_ECX + 0x70);
  while (piVar4 != (int *)0x0) {
    if (pvStack_144 <= pvVar13) goto LAB_00573edf;
    if (uStack_148 <= uStack_14c) {
      puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x14))();
      uStack_13c = *(undefined2 *)(puVar5 + 1);
      uStack_140 = *puVar5;
      if ((char)((ushort)uStack_13c >> 8) == '\0') {
        FUN_005733c0(pvVar13,100);
        uStack_100 = 0xf;
        uStack_104 = 0;
        uStack_114 = 0;
        FUN_00401740(&DAT_009bd4d3,0);
        FUN_00401740(s_lbl_channel__d_009bd4d4,0xe);
        ppvVar14 = apvStack_38;
        uVar6 = FUN_00404230(ppvVar14);
        piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
        if ((piVar7 != (int *)0x0) && (iVar3 = (**(code **)(*piVar7 + 0x30))(), iVar3 != 0)) {
          FUN_0055a260(&uStack_11c);
        }
        if ((void *)0xf < apvStack_24[0]) {
          _free(apvStack_38[0]);
          return;
        }
        apvStack_24[0] = (void *)0xf;
        uStack_28 = 0;
        apvStack_38[0] = (void *)((uint)apvStack_38[0] & 0xffffff00);
        if (0xf < uStack_104) {
          _free(pvStack_118);
          return;
        }
        uStack_104 = 0xf;
        pvStack_108 = (void *)0x0;
        pvStack_118 = (void *)((uint)pvStack_118 & 0xffffff00);
        (**(code **)(*piVar4 + 0xc))();
        uVar15 = 0;
        if ((short)pvStack_144 == 0) {
          FUN_00401740(&DAT_009bd4f4,2);
          FUN_00404230(auStack_58);
          uVar16 = 0;
          uVar15 = 0;
          FUN_00401740(s_lbl_name__d_009bd4f8,0xb);
          in_stack_fffffe78 = auStack_90;
          uVar6 = FUN_00404230(in_stack_fffffe78,ppvVar14,uVar15);
          piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
          if ((piVar7 != (int *)0x0) && (iVar3 = (**(code **)(*piVar7 + 0x30))(uVar16), iVar3 != 0))
          {
            FUN_0055a260(unaff_EDI);
          }
          if (0xf < uStack_84) {
            _free(pvStack_98);
            return;
          }
          uStack_84 = 0xf;
          uStack_88 = 0;
          pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
          if (0xf < uStack_4c) {
            _free(pvStack_60);
            return;
          }
          uStack_4c = 0xf;
          uStack_50 = 0;
          pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
        }
        else {
          FUN_00401740(&DAT_009bd4e4,2);
          FUN_00404230(auStack_c8,ppvVar14,uVar15);
          uVar16 = 0;
          uVar15 = 0;
          FUN_00401740(s_lbl_name__d_009bd4e8,0xb);
          in_stack_fffffe78 = auStack_74;
          uVar6 = FUN_00404230(in_stack_fffffe78,ppvVar14,uVar15);
          piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
          if ((piVar7 != (int *)0x0) && (iVar3 = (**(code **)(*piVar7 + 0x30))(uVar16), iVar3 != 0))
          {
            FUN_0055a260(unaff_EDI);
          }
          if (0xf < uStack_68) {
            _free(pvStack_7c);
            return;
          }
          uStack_68 = 0xf;
          uStack_6c = 0;
          pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
          if (0xf < uStack_bc) {
            _free(pvStack_d0);
            return;
          }
          uStack_bc = 0xf;
          uStack_c0 = 0;
          pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
        }
        FUN_005732b0(pvVar13,0xff888888);
      }
      else {
        uStack_140._3_1_ = (undefined1)((uint)uStack_140 >> 0x18);
        uVar2 = CONCAT21(uStack_13c,uStack_140._3_1_);
        (**(code **)(*DAT_00b5ad1c + 0x30))(auStack_fc,CONCAT13(uStack_13a,uVar2));
        FUN_005733c0(pvVar13,(uint)pvStack_144 & 0xff);
        (**(code **)(*piVar4 + 0xc))();
        FUN_00401740(&DAT_009bd4b4,2);
        FUN_00404230(apvStack_24);
        FUN_00401740(s_lbl_name__d_009bd4b8,0xb);
        ppvVar14 = apvStack_e8;
        uVar6 = FUN_00404230(ppvVar14);
        piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
        if ((piVar7 != (int *)0x0) && (iVar3 = (**(code **)(*piVar7 + 0x30))(), iVar3 != 0)) {
          FUN_0055a260(unaff_ESI);
        }
        if (0xf < uStack_d4) {
          _free(apvStack_e8[0]);
          return;
        }
        uStack_d4 = 0xf;
        uStack_d8 = 0;
        apvStack_e8[0] = (void *)((uint)apvStack_e8[0] & 0xffffff00);
        if (0xf < uStack_10) {
          _free(apvStack_24[0]);
          return;
        }
        uStack_10 = 0xf;
        uStack_14 = 0;
        apvStack_24[0] = (void *)((uint)apvStack_24[0] & 0xffffff00);
        in_stack_fffffe78 = (undefined1 *)((uint)in_stack_fffffe78 & 0xffffff00);
        FUN_00401740(s_lbl_channel__d_009bd4c4,0xe);
        uVar6 = FUN_00404230(apvStack_b4,ppvVar14,in_stack_fffffe78);
        piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
        if ((piVar7 != (int *)0x0) && (iVar3 = (**(code **)(*piVar7 + 0x30))(), iVar3 != 0)) {
          FUN_0055a260(auStack_10c);
        }
        if (0xf < uStack_a0) {
          _free(apvStack_b4[0]);
          return;
        }
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        apvStack_b4[0] = (void *)((uint)apvStack_b4[0] & 0xffffff00);
        if (pvVar13 == *(void **)(in_ECX + 0x94)) {
          uVar6 = 0xff00ff00;
        }
        else {
          uVar6 = 0xffffffff;
        }
        FUN_005732b0(pvVar13,uVar6);
        if (0xf < uStack_f4) {
          _free(pvStack_108);
          return;
        }
        uStack_f4 = 0xf;
        uStack_f8 = 0;
        pvStack_108 = (void *)((uint)pvStack_108 & 0xffffff00);
      }
      FUN_00401740(s_btn_list__d_009bd504,0xb);
      uVar6 = FUN_00404230(&pvStack_144);
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 0x24))(1);
      }
      if ((void *)0xf < pvStack_130) {
        _free(pvStack_144);
        return;
      }
      pvStack_130 = (void *)0xf;
      uStack_134 = 0;
      pvStack_144 = (void *)((uint)pvStack_144 & 0xffffff00);
      puVar8 = operator_new(0x24);
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = puVar12;
      }
      else {
        *(undefined4 *)(puVar8 + 0x20) = 0xf;
        *(undefined4 *)(puVar8 + 0x1c) = 0;
        puVar8[0xc] = 0;
      }
      *(undefined4 *)(puVar8 + 4) = unaff_EDI;
      *puVar8 = uStack_150._1_1_;
      pcVar9 = (char *)(**(code **)(*piVar4 + 0xc))();
      pcStack_138 = pcVar9 + 1;
      pcVar11 = pcVar9;
      do {
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar9,(int)pcVar11 - (int)pcStack_138);
      iVar3 = *(int *)(in_ECX + 0xbc);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(in_ECX + 0xc4) - iVar3 >> 2) <=
          (uint)(*(int *)(in_ECX + 0xc0) - iVar3 >> 2))) {
        FUN_00575160(*(undefined4 *)(in_ECX + 0xc0),1,&uStack_150);
      }
      else {
        puVar5 = *(undefined4 **)(in_ECX + 0xc0);
        *puVar5 = uStack_150;
        *(undefined4 **)(in_ECX + 0xc0) = puVar5 + 1;
      }
      pvVar13 = (void *)((int)pvVar13 + 1);
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5ae3c + 0x70))();
    uStack_14c = uStack_14c + 1;
  }
  if (pvVar13 < pvStack_144) {
    do {
      FUN_00401740(s_btn_list__d_009bd510,0xb);
      uVar6 = FUN_00404230(&uStack_134);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar6);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x24))(0);
      }
      if (0xf < uStack_11c) {
        _free(pvStack_130);
        return;
      }
      pvVar13 = (void *)((int)pvVar13 + 1);
      uStack_11c = 0xf;
      uStack_120 = 0;
      pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
    } while (pvVar13 < pvStack_144);
  }
LAB_00573edf:
  uVar10 = (**(code **)(*DAT_00b5ae3c + 0x78))();
  if (*(uint *)(in_ECX + 0x70) < uVar10) {
    puVar12 = (undefined1 *)(uVar10 - *(uint *)(in_ECX + 0x70));
  }
  (**(code **)(**(int **)(in_ECX + 0x74) + 0x30))(puVar12);
  FUN_0055aac0(puVar12);
  return;
}


// ==== FUN_00573f10 @ 0x00573f10 ====

undefined4 FUN_00573f10(int param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *******pppppppuVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int *piVar5;
  undefined4 extraout_EAX_00;
  char *pcVar6;
  undefined4 uVar7;
  int *in_ECX;
  bool bVar8;
  undefined1 auStack_38 [4];
  undefined4 *******local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  bVar8 = false;
  if (param_1 == 4) {
    bVar8 = true;
    uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd484);
    FUN_00402220(auStack_38,uVar2);
    pppppppuVar3 = local_34;
    if (local_20 < 0x10) {
      pppppppuVar3 = &local_34;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppppppuVar3,uStack_24);
    if ((iVar4 != 0) || (param_3 != 6)) goto LAB_00573f84;
    bVar1 = true;
  }
  else {
LAB_00573f84:
    bVar1 = false;
  }
  if ((bVar8) && (0xf < local_20)) {
    _free(local_34);
    return extraout_EAX;
  }
  if (bVar1) {
    FUN_00573800();
    piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar5 + 0x80))(param_3,0);
    return 1;
  }
  if (param_1 != 1) {
    if (param_3 != 1) {
      return 0;
    }
    pcVar6 = (char *)FUN_00573640(in_ECX[0x25]);
    uVar2 = 0xff888888;
    if (pcVar6 != (char *)0x0) {
      if (*pcVar6 != '\0') {
        uVar2 = 0xffffffff;
      }
      FUN_005732b0(in_ECX[0x25],uVar2);
      piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar5 + 0x80))(6,0);
    }
    return 1;
  }
  local_34 = (undefined4 *******)0x0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(&DAT_009bd478,1);
  FUN_00405300(param_2,auStack_1c,auStack_38);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_00;
  }
  iVar4 = FUN_00405d30(1);
  iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),&DAT_009bd47c,4);
  if (iVar4 != 0) {
LAB_00574191:
    FUN_00406250();
    return 0;
  }
  if (param_3 == 4) {
    uVar2 = FUN_00405d30(2);
    uVar2 = thunk_FUN_00796fb0(uVar2);
    pcVar6 = (char *)FUN_00573640(uVar2);
    uVar2 = 0xff888888;
    if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
      uVar2 = 0xfff2c100;
    }
    uVar7 = FUN_00405d30(2);
    iVar4 = thunk_FUN_00796fb0(uVar7,uVar2);
  }
  else {
    if (param_3 != 5) {
      if ((param_3 == 1) || (param_3 == 2)) {
        uVar2 = FUN_00405d30(2);
        iVar4 = thunk_FUN_00796fb0(uVar2);
        pcVar6 = (char *)FUN_00573640(iVar4);
        uVar2 = 0xff888888;
        if (pcVar6 != (char *)0x0) {
          if (*pcVar6 != '\0') {
            uVar2 = 0xfff2c100;
          }
          FUN_005732b0(iVar4,uVar2);
          in_ECX[0x25] = iVar4;
          FUN_00401660(pcVar6 + 8,0,0xffffffff);
          piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
          (**(code **)(*piVar5 + 0x80))(param_3,param_4);
        }
        FUN_00406250();
        return 1;
      }
      goto LAB_00574191;
    }
    uVar2 = FUN_00405d30(2);
    iVar4 = thunk_FUN_00796fb0(uVar2);
    if (iVar4 == in_ECX[0x25]) goto LAB_005740e8;
    pcVar6 = (char *)FUN_00573640(iVar4);
    uVar2 = 0xff888888;
    if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
      uVar2 = 0xffffffff;
    }
  }
  FUN_005732b0(iVar4,uVar2);
LAB_005740e8:
  FUN_00406250();
  return 1;
}


// ==== FUN_00574200 @ 0x00574200 ====

void FUN_00574200(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd58c;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  iVar1 = FUN_00503ac0();
  in_ECX[0x1f] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[0x1f] + 4) = in_ECX[0x1f];
  *(undefined4 *)in_ECX[0x1f] = in_ECX[0x1f];
  *(undefined4 *)(in_ECX[0x1f] + 8) = in_ECX[0x1f];
  in_ECX[0x20] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0xffffffff;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0xf;
  *(undefined1 *)(in_ECX + 0x27) = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_005742b0 @ 0x005742b0 ====

void FUN_005742b0(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_4 [4];
  
  *in_ECX = &PTR_FUN_009bd58c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    FUN_00573160();
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  if ((void *)in_ECX[0x2f] != (void *)0x0) {
    _free((void *)in_ECX[0x2f]);
    return;
  }
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  if ((uint)in_ECX[0x2c] < 0x10) {
    in_ECX[0x2c] = 0xf;
    in_ECX[0x2b] = 0;
    *(undefined1 *)(in_ECX + 0x27) = 0;
    FUN_005054c0(auStack_4,*(undefined4 *)in_ECX[0x1f],(undefined4 *)in_ECX[0x1f]);
    _free((void *)in_ECX[0x1f]);
    return;
  }
  _free((void *)in_ECX[0x27]);
  return;
}


// ==== FUN_00574370 @ 0x00574370 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00574370(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int in_ECX;
  int unaff_EBP;
  void **ppvVar10;
  int **ppiVar11;
  undefined4 uVar12;
  void **ppvStack_29c;
  int *piStack_298;
  undefined1 *puStack_294;
  void **ppvStack_290;
  undefined4 *puStack_28c;
  int *piStack_288;
  undefined4 uStack_284;
  int *piVar13;
  undefined1 auStack_272 [2];
  undefined1 *puStack_270;
  int *piStack_26c;
  int *piStack_268;
  undefined1 *puStack_25c;
  int *piStack_258;
  undefined4 uStack_254;
  int *piStack_250;
  undefined4 uStack_24c;
  int iVar14;
  void *pvVar15;
  int aiStack_238 [2];
  undefined1 uStack_230;
  undefined1 uStack_22f;
  int iStack_22c;
  int iStack_228;
  int local_224 [2];
  int iStack_21c;
  undefined2 uStack_218;
  undefined1 uStack_216;
  undefined1 uStack_215;
  int iStack_214;
  int iStack_210;
  int iStack_20c;
  void *pvStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined1 auStack_1f8 [4];
  uint uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 auStack_1ec [2];
  uint uStack_1e4;
  undefined4 auStack_1e0 [3];
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  void *pvStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined1 uStack_1c0;
  undefined1 uStack_1bf;
  undefined4 uStack_1bc;
  uint uStack_1b8;
  void *pvStack_1b0;
  int aiStack_1ac [7];
  undefined4 uStack_190;
  uint uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  void *pvStack_17c;
  undefined4 uStack_16c;
  uint uStack_168;
  void *pvStack_150;
  void *pvStack_148;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  uint uStack_13c;
  undefined4 uStack_138;
  uint uStack_134;
  undefined4 uStack_130;
  uint uStack_12c;
  undefined1 auStack_11c [8];
  undefined1 auStack_114 [4];
  undefined1 uStack_110;
  void *pvStack_10c;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  uint uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_e8;
  void *pvStack_e4;
  undefined4 uStack_e0;
  void *pvStack_dc;
  undefined4 uStack_d8;
  void *pvStack_d4;
  uint uStack_d0;
  undefined4 uStack_cc;
  uint uStack_c8;
  void *pvStack_c4;
  undefined4 uStack_c0;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  void *pvStack_60;
  undefined4 uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [36];
  
  puStack_25c = auStack_28 + 0x24;
  uStack_24c = 0x574391;
  local_224[0] = in_ECX;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  _uStack_218 = CONCAT12(1,uStack_218);
  iStack_214 = 0;
  iStack_210 = 0;
  iStack_20c = 0;
  pvStack_208 = (void *)0x0;
  uStack_204 = 0;
  uStack_200 = 0;
  uStack_1fc = 0;
  auStack_1e0[0] = 0xf;
  uStack_1e4 = 0;
  uStack_1f4 = uStack_1f4 & 0xffffff00;
  uStack_24c = 0;
  piStack_250 = (int *)0x5743d3;
  iVar3 = (**(code **)(*DAT_00b5a7ac + 8))();
  piStack_250 = (int *)0x8;
  uStack_254 = s_pan_back_009bd51c;
  uStack_18c = 0xf;
  uStack_190 = 0;
  aiStack_1ac[3] = aiStack_1ac[3] & 0xffffff00;
  uStack_188 = 0;
  uStack_184 = 0;
  uStack_180 = 0;
  piStack_258 = (int *)0x574414;
  FUN_00401740();
  piStack_250 = (int *)0xffffffff;
  uStack_254 = (char *)0x0;
  piStack_258 = aiStack_1ac + 2;
  FUN_00401660();
  iStack_214 = 0;
  iStack_210 = 0;
  piStack_250 = (int *)0x57443a;
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  iVar14 = *(int *)(iVar4 + 0x14);
  iVar4 = *(int *)(iVar4 + 0xc);
  piStack_250 = (int *)0x57444f;
  iVar5 = (**(code **)(**(int **)(iStack_228 + 4) + 0x14))();
  iStack_20c = (*(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 8)) + iStack_214;
  pvStack_208 = (void *)(iStack_210 + (iVar14 - iVar4));
  piStack_250 = &iStack_21c;
  _uStack_218 = 10;
  iStack_21c = CONCAT22(iStack_21c._2_2_,0x101);
  uStack_254 = (char *)0x57448a;
  (**(code **)(*piVar2 + 8))();
  piVar6 = *(int **)(iStack_22c + 4);
  if (piVar6 != (int *)0x0) {
    piStack_258 = (int *)0x57449d;
    uStack_254 = (char *)piVar6;
    cVar1 = (**(code **)(*piVar2 + 0x74))();
    if (cVar1 != '\0') {
      piStack_258 = (int *)0x5744a9;
      uStack_254 = (char *)piVar2;
      cVar1 = (**(code **)(*piVar6 + 0x78))();
      if (cVar1 == '\0') {
        piStack_258 = (int *)0x0;
        (**(code **)(*piVar2 + 0x74))();
      }
      else {
        piStack_258 = (int *)0x5744be;
        iVar14 = (**(code **)(*piVar6 + 0x38))();
        piVar2[1] = iVar14;
      }
    }
  }
  piStack_258 = (int *)0x5744cd;
  uStack_254 = (char *)piVar2;
  (**(code **)(unaff_EBP + 0x38))();
  piStack_258 = aiStack_1ac;
  (**(code **)(unaff_EBP + 0x1c))();
  (**(code **)(*piVar2 + 0x2c))();
  uStack_18c = *(uint *)(aiStack_238[0] + 0x70);
  iVar14 = 0;
  if (uStack_18c != 0) {
    uStack_d8 = 0;
    uStack_c8 = 1;
    uStack_e8 = 2;
    do {
      piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
      piVar2 = (int *)&DAT_00000000_1;
      piStack_250 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
      uStack_fc = 0xf;
      uStack_100 = 0;
      uStack_110 = 0;
      uStack_f8 = 0;
      uStack_f4 = 0;
      uStack_f0 = 0;
      uStack_284 = (int *)0xb;
      piStack_268 = (int *)0xf;
      piStack_26c = (int *)0x0;
      piStack_288 = (int *)s_btn_list__d_009bd528;
      puStack_28c = (undefined4 *)0x574586;
      FUN_00401740();
      uStack_284 = (int *)auStack_68;
      piStack_288 = (int *)0x574593;
      piStack_26c = (int *)FUN_00404230();
      piStack_268 = (int *)0x0;
      puStack_270 = (undefined1 *)0x5745a6;
      FUN_00401660();
      if (0xf < uStack_50) {
        piStack_268 = (int *)0x5745bd;
        _free(pvStack_64);
        return;
      }
      piStack_268 = (int *)0x0;
      piStack_26c = (int *)auStack_114;
      uStack_50 = 0xf;
      uStack_54 = 0;
      pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
      puStack_270 = (undefined1 *)0x5745e9;
      FUN_00401660();
      local_224[0] = *(int *)(iVar3 + 0x84) * iVar14 + 4;
      iStack_228 = 10;
      iStack_21c = local_224[0] + *(int *)(iVar3 + 0x84);
      local_224[1] = 0xd6;
      iStack_22c = 100;
      uStack_230 = 1;
      uStack_22f = 1;
      pvVar15 = (void *)0x0;
      piStack_268 = (int *)0x574640;
      pvVar7 = operator_new(0x468);
      if (pvVar7 == (void *)0x0) {
        pvVar7 = (void *)0x0;
      }
      else {
        pvVar7 = (void *)FUN_00505f10();
      }
      *(undefined1 *)((int)pvVar7 + 0x104) = 0;
      *(undefined1 *)((int)pvVar7 + 0x105) = 0;
      *(undefined1 *)((int)pvVar7 + 0x107) = 0;
      *(undefined1 *)((int)pvVar7 + 0x10c) = 0;
      *(undefined4 *)((int)pvVar7 + 0x108) = 0xc;
      *(undefined4 *)((int)pvVar7 + 0x110) = 500;
      *(undefined1 *)((int)pvVar7 + 0x106) = 0;
      uStack_d8 = 0xff000000;
      uStack_d0 = 0;
      piStack_268 = aiStack_238;
      piStack_26c = (int *)0x5746c4;
      pvStack_d4 = pvVar15;
      FUN_0056ac60();
      uStack_c8 = 0xff;
      piStack_268 = (int *)auStack_30;
      uStack_c0 = 0;
      piStack_26c = (int *)0x574705;
      pvStack_c4 = pvVar15;
      FUN_0056ac60();
      piStack_268 = (int *)auStack_28;
      uStack_e0 = 0;
      piStack_26c = (int *)0x574741;
      uStack_e8 = 0xff;
      pvStack_e4 = pvVar15;
      FUN_0056ac60();
      piStack_268 = (int *)0x57474d;
      (**(code **)(*piVar6 + 8))();
      piVar13 = piRam00000004;
      piStack_268 = piRam00000004;
      if (piRam00000004 != (int *)0x0) {
        piStack_26c = (int *)0x574764;
        cVar1 = (**(code **)(*piVar6 + 0x74))();
        if (cVar1 != '\0') {
          piStack_26c = (int *)0x574772;
          piStack_268 = piVar6;
          cVar1 = (**(code **)(*piVar13 + 0x78))();
          if (cVar1 == '\0') {
            piStack_26c = (int *)0x0;
            puStack_270 = (undefined1 *)0x57477e;
            (**(code **)(*piVar6 + 0x74))();
          }
          else {
            piStack_26c = (int *)0x574789;
            iVar14 = (**(code **)(_DAT_00000000 + 0x38))();
            piVar6[1] = iVar14;
          }
        }
      }
      piStack_26c = (int *)0x574796;
      piStack_268 = piVar6;
      (**(code **)(*(int *)uStack_254 + 0x38))();
      piStack_26c = (int *)auStack_11c;
      puStack_270 = (undefined1 *)0x5747a7;
      (**(code **)(*piStack_258 + 0x1c))();
      puStack_270 = puStack_25c;
      (**(code **)(*piVar6 + 0x2c))();
      (**(code **)(*piVar2 + 0x24))();
      if (pvVar7 != (void *)0x0) {
        FUN_00505d80();
        _free(pvVar7);
        return;
      }
      piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
      piVar13 = (int *)0x0;
      piStack_268 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
      ppvStack_29c = (void **)0xe;
      uStack_284 = (int *)0x0;
      puStack_294 = (undefined1 *)((uint)puStack_294 & 0xffffff00);
      FUN_00401740(s_pan_iconbox__d_009bd534);
      ppvStack_29c = &pvStack_64;
      uStack_284 = (int *)FUN_00404230();
      piStack_288 = (int *)0x57482d;
      FUN_00401660();
      if (0xf < uStack_4c) {
        _free(pvStack_60);
        return;
      }
      uStack_284 = &uStack_1d0;
      uStack_4c = 0xf;
      uStack_50 = 0;
      pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
      piStack_288 = (int *)0x574870;
      FUN_00401660();
      aiStack_238[1] = 0x14;
      aiStack_238[0] = 0x14;
      piStack_258 = (int *)0x2;
      uStack_130 = 0xf;
      uStack_134 = 0;
      auStack_144[0] = 0;
      uStack_284 = (int *)0x5748d1;
      FUN_00401740();
      ppvVar10 = &pvStack_148;
      (**(code **)(*DAT_00b5a7c0 + 8))();
      if (0xf < uStack_134) {
        uStack_284 = (int *)0x5748ff;
        _free(pvStack_148);
        return;
      }
      uStack_134 = 0xf;
      uStack_138 = 0;
      pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
      uStack_284 = (int *)0x574923;
      (**(code **)(*piVar2 + 8))();
      piStack_288 = (int *)0x57492b;
      uStack_284 = piVar6;
      cVar1 = (**(code **)(*piVar2 + 0x74))();
      if (cVar1 != '\0') {
        puStack_28c = (undefined4 *)0x574937;
        piStack_288 = piVar2;
        cVar1 = (**(code **)(*piVar6 + 0x78))();
        if (cVar1 == '\0') {
          puStack_28c = (undefined4 *)0x0;
          ppvStack_290 = (void **)0x574943;
          (**(code **)(*piVar2 + 0x74))();
        }
        else {
          puStack_28c = (undefined4 *)0x57494c;
          iVar14 = (**(code **)(*piVar6 + 0x38))();
          piVar2[1] = iVar14;
        }
      }
      puStack_28c = (undefined4 *)0x574959;
      piStack_288 = piVar2;
      (**(code **)(_DAT_00000000 + 0x38))();
      puStack_28c = auStack_1e0;
      ppvStack_290 = (void **)0x57496a;
      (**(code **)(*piVar13 + 0x1c))();
      ppvStack_290 = ppvVar10;
      puStack_294 = (undefined1 *)0x574976;
      (**(code **)(*piVar2 + 0x2c))();
      puStack_294 = auStack_272 + -6;
      piStack_298 = (int *)0x574984;
      FUN_00587d40();
      piStack_298 = (int *)0x57498f;
      piStack_26c = (int *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (piStack_26c == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piStack_298 = (int *)0x57499e;
        iVar14 = (**(code **)(*piVar2 + 4))();
        *piStack_26c = (int)&PTR_FUN_009bcd68;
        piStack_26c[1] = iVar14;
        piVar2 = piStack_26c;
      }
      *(undefined1 *)(piVar2 + 2) = 0;
      ppvStack_29c = (void **)0x5749be;
      piStack_298 = piVar2;
      (**(code **)(*DAT_00b5ad24 + 4))();
      ppvStack_29c = (void **)&DAT_00000000_1;
      (**(code **)*piVar2)();
      piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
      uVar12 = 0;
      ppvStack_290 = (void **)(**(code **)(*DAT_00b5a7ac + 8))(0);
      FUN_00401740(s_pan_icon__d_009bd554,0xb);
      uVar8 = FUN_00404230(&uStack_e0);
      FUN_00401660(uVar8,0,0xffffffff);
      if (0xf < uStack_c8) {
        _free(pvStack_dc);
        return;
      }
      uStack_c8 = 0xf;
      uStack_cc = 0;
      pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
      FUN_00401660(auStack_1f8,0,0xffffffff);
      piStack_268 = (int *)0x1;
      puStack_25c = (undefined1 *)0x10;
      piStack_26c = (int *)0x64;
      puStack_270 = (undefined1 *)CONCAT22(puStack_270._2_2_,0x101);
      piStack_288 = (int *)0x0;
      (**(code **)(*piVar2 + 8))(&puStack_270);
      cVar1 = (**(code **)(*piVar2 + 0x74))(piVar6);
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(*piVar6 + 0x78))(piVar2);
        if (cVar1 == '\0') {
          (**(code **)(*piVar2 + 0x74))(0);
        }
        else {
          iVar14 = (**(code **)(*piVar6 + 0x38))();
          piVar2[1] = iVar14;
        }
      }
      (**(code **)(*piStack_298 + 0x38))(piVar2);
      (**(code **)((int)*ppvStack_29c + 0x1c))(&uStack_204);
      (**(code **)(*piVar2 + 0x2c))(uVar12);
      FUN_00587d40(&ppvStack_29c);
      ppvStack_290 = (void **)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (ppvStack_290 == (void **)0x0) {
        ppvVar10 = (void **)0x0;
      }
      else {
        iVar14 = (**(code **)(*piVar2 + 4))();
        *ppvStack_290 = &PTR_FUN_009bcd68;
        ppvStack_290[1] = (void *)iVar14;
        ppvVar10 = ppvStack_290;
      }
      *(undefined1 *)(ppvVar10 + 2) = 0;
      (**(code **)(*DAT_00b5ad24 + 4))();
      (**(code **)*ppvVar10)();
      piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
      uStack_254._0_3_ = CONCAT12(1,(undefined2)uStack_254);
      piStack_250 = (int *)0x0;
      uStack_24c = 0;
      iVar3 = 0;
      aiStack_238[0] = 0;
      iStack_21c = 0xf;
      local_224[1] = 0;
      uStack_230 = 0;
      piVar13 = (int *)0x8;
      (**(code **)(*DAT_00b5a7ac + 8))();
      aiStack_1ac[2] = 0xf;
      aiStack_1ac[1] = 0;
      uStack_1b8 = uStack_1b8 & 0xffffff00;
      aiStack_1ac[3] = 0;
      aiStack_1ac[4] = 0;
      aiStack_1ac[5] = 0;
      FUN_00401740(s_lbl_name__d_009bd560,0xb);
      uVar8 = FUN_00404230(&uStack_e8);
      FUN_00401660(uVar8,0,0xffffffff);
      if (0xf < uStack_d0) {
        _free(pvStack_e4);
        return;
      }
      uStack_d0 = 0xf;
      pvStack_d4 = (void *)0x0;
      pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
      FUN_00401660(&uStack_1bc,0,0xffffffff);
      piStack_250 = (int *)0x12;
      uStack_24c = 2;
      uStack_254 = (char *)0x64;
      piStack_258 = (int *)CONCAT22(piStack_258._2_2_,0x101);
      uStack_1d0 = 0xf;
      uStack_1d4 = 0;
      uStack_1e4 = uStack_1e4 & 0xffffff00;
      uStack_1c4 = 1;
      uStack_1bf = 0;
      uStack_1c0 = 0;
      uStack_1c8 = 0xffffffff;
      uStack_1f0 = 0;
      auStack_1ec[0] = 0;
      pvStack_1cc = (void *)((int)&DAT_00000000_1 + 1);
      FUN_00401740(&DAT_009bd56c,0);
      ppiVar11 = &piStack_258;
      (**(code **)(*piVar2 + 8))(ppiVar11);
      cVar1 = (**(code **)(*piVar2 + 0x74))(piVar6);
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(*piVar6 + 0x78))(piVar2);
        if (cVar1 == '\0') {
          (**(code **)(*piVar2 + 0x74))(0);
        }
        else {
          iVar14 = (**(code **)(*piVar6 + 0x38))();
          piVar2[1] = iVar14;
        }
      }
      (**(code **)((int)*ppvVar10 + 0x38))(piVar2);
      (**(code **)(CONCAT13(piRam00000004._0_1_,DAT_00000000_1) + 0x1c))(&uStack_1c8);
      (**(code **)(*piVar13 + 8))(&uStack_200);
      (**(code **)(*piVar2 + 0x2c))(ppiVar11);
      piVar13 = (int *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (piVar13 == (int *)0x0) {
        piVar13 = (int *)0x0;
      }
      else {
        iVar14 = (**(code **)(*piVar2 + 4))();
        *piVar13 = (int)&PTR_FUN_009bcd68;
        piVar13[1] = iVar14;
      }
      *(undefined1 *)(piVar13 + 2) = 0;
      (**(code **)(*DAT_00b5ad24 + 4))();
      (**(code **)*piVar13)(1);
      piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
      (**(code **)(*DAT_00b5a7ac + 8))(8);
      FUN_00401740(s_lbl_channel__d_009bd570,0xe);
      uVar8 = FUN_00404230(auStack_144);
      FUN_00401660(uVar8,0,0xffffffff);
      if (0xf < uStack_12c) {
        _free(pvStack_140);
        return;
      }
      uStack_12c = 0xf;
      uStack_130 = 0;
      pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
      FUN_00401660(auStack_1e0,0,0xffffffff);
      puStack_270 = (undefined1 *)0x2;
      piStack_26c = (int *)0xc2;
      piStack_268 = (int *)0xf;
      uStack_1e4 = uStack_1e4 & 0xffffff00;
      auStack_1ec[0] = 0xffffffff;
      iStack_214 = 0;
      iStack_210 = 0;
      uStack_1f0 = 2;
      FUN_00401740(&DAT_009bd57f,0);
      (**(code **)(*piVar2 + 8))(auStack_272 + -10);
      cVar1 = (**(code **)(*piVar2 + 0x74))(piVar6);
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(*piVar6 + 0x78))(piVar2);
        if (cVar1 == '\0') {
          (**(code **)(*piVar2 + 0x74))(0);
        }
        else {
          iVar14 = (**(code **)(*piVar6 + 0x38))();
          piVar2[1] = iVar14;
        }
      }
      (**(code **)(*piVar13 + 0x38))(piVar2);
      (**(code **)(*piVar13 + 0x1c))(auStack_1ec);
      (**(code **)(*piVar13 + 8))(local_224);
      (**(code **)(*piVar2 + 0x2c))(piVar13);
      puVar9 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        uVar8 = (**(code **)(*piVar2 + 4))();
        *puVar9 = &PTR_FUN_009bcd68;
        puVar9[1] = uVar8;
      }
      *(undefined1 *)(puVar9 + 2) = 0;
      (**(code **)(*DAT_00b5ad24 + 4))(puVar9);
      (**(code **)*puVar9)(1);
      if (0xf < uStack_168) {
        _free(pvStack_17c);
        return;
      }
      uStack_168 = 0xf;
      uStack_16c = 0;
      pvStack_17c = (void *)((uint)pvStack_17c & 0xffffff00);
      if (0xf < uStack_13c) {
        _free(pvStack_150);
        return;
      }
      uStack_13c = 0xf;
      pvStack_140 = (void *)0x0;
      pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
      if (0xf < uStack_1b8) {
        _free(pvStack_1cc);
        return;
      }
      uStack_1b8 = 0xf;
      uStack_1bc = 0;
      pvStack_1cc = (void *)((uint)pvStack_1cc & 0xffffff00);
      if (0xf < uStack_f8) {
        _free(pvStack_10c);
        return;
      }
      iVar14 = 0x88;
      uStack_f8 = 0xf;
      uStack_fc = 0;
      pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    } while (0x88 < uStack_18c);
  }
  if (0xf < (uint)aiStack_1ac[4]) {
    _free(pvStack_1b0);
    return;
  }
  aiStack_1ac[4] = 0xf;
  aiStack_1ac[3] = 0;
  pvStack_1b0 = (void *)((uint)pvStack_1b0 & 0xffffff00);
  if (uStack_1f4 < 0x10) {
    return;
  }
  _free(pvStack_208);
  return;
}


// ==== FUN_00575090 @ 0x00575090 ====

void FUN_00575090(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  void *apvStack_1c [5];
  uint uStack_8;
  
  iVar2 = param_1;
  piVar3 = (int *)(param_1 + 0x2b0);
  if (in_ECX + 0x1e != piVar3) {
    FUN_005054c0(&param_1,*(undefined4 *)in_ECX[0x1f],(undefined4 *)in_ECX[0x1f]);
    FUN_00505580(piVar3);
  }
  in_ECX[0x21] = *(int *)(iVar2 + 700);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd484);
  FUN_00402220(apvStack_1c,uVar1);
  iVar2 = (**(code **)(*piVar3 + 0x4c))(apvStack_1c);
  in_ECX[0x1d] = iVar2;
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  iVar2 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  iVar2 = ((*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + -8) / in_ECX[0x21];
  in_ECX[0x1c] = iVar2;
  if (iVar2 < 0) {
    in_ECX[0x1c] = 0;
  }
  FUN_00573530();
  FUN_00574370();
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_00575160 @ 0x00575160 ====

void FUN_00575160(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982080;
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


// ==== Catch@005752c1 @ 0x005752c1 ====

void Catch_005752c1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005753b0 @ 0x005753b0 ====

void FUN_005753b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005742b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005753f0 @ 0x005753f0 ====

void FUN_005753f0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00575410 @ 0x00575410 ====

undefined4 FUN_00575410(void)

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


// ==== FUN_00575440 @ 0x00575440 ====

uint FUN_00575440(int *param_1)

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


// ==== FUN_005754e0 @ 0x005754e0 ====

undefined4 FUN_005754e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xe8) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0xe8) + 0x88);
}


// ==== FUN_00575500 @ 0x00575500 ====

void FUN_00575500(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xe8) == 0) {
    return;
  }
  FUN_0055ab10();
  return;
}


// ==== FUN_00575530 @ 0x00575530 ====

void FUN_00575530(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xe8) == 0) {
    return;
  }
  FUN_0055a920();
  return;
}


// ==== FUN_00575540 @ 0x00575540 ====

undefined4 FUN_00575540(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar2 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar2 != '\0')) {
    return 1;
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x10001) {
    cVar2 = FUN_00575440(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if (iVar3 == 0x10003) {
    piVar1 = *(int **)(in_ECX + 4);
    iVar3 = (**(code **)(*param_1 + 0x10))();
    iVar4 = (**(code **)(*piVar1 + 4))();
    if (((iVar3 == iVar4) && (param_1[2] == 1)) && (param_1[6] == 1)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005755c0 @ 0x005755c0 ====

void FUN_005755c0(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0xdc);
    local_8 = *(undefined4 *)(in_ECX + 0xe0);
    local_4 = *(undefined4 *)(in_ECX + 0xe4);
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


// ==== FUN_00575690 @ 0x00575690 ====

void FUN_00575690(uint param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 0x7c);
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 0x80) - iVar2 >> 3))) {
    iVar1 = *(int *)(in_ECX + 0x80);
    *(undefined4 *)(in_ECX + 0xec) = 0;
    for (; iVar2 != iVar1; iVar2 = iVar2 + 8) {
      if (*(int *)(iVar2 + 4) != 0) {
        FUN_00558730(*(uint *)(in_ECX + 0xec) == param_1);
        *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
      }
    }
  }
  return;
}


// ==== FUN_00575700 @ 0x00575700 ====

void FUN_00575700(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  
  iVar1 = *(int *)(in_ECX + 0x80);
  iVar4 = *(int *)(in_ECX + 0x7c);
  *(undefined4 *)(in_ECX + 0xec) = 0;
  for (; iVar4 != iVar1; iVar4 = iVar4 + 8) {
    if (*(int *)(iVar4 + 4) != 0) {
      iVar2 = FUN_00558120();
      puVar3 = param_2;
      if (in_stack_0000001c < 0x10) {
        puVar3 = &param_2;
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x1c),puVar3,in_stack_00000018);
      FUN_00558730(iVar2 == 0);
      *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
    }
  }
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00575790 @ 0x00575790 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00575790(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  if ((_DAT_00b5afa0 & 1) == 0) {
    _DAT_00b5afa0 = _DAT_00b5afa0 | 1;
    DAT_00b5af9c = 0xf;
    DAT_00b5af98 = 0;
    DAT_00b5af88 = (undefined4 *)((uint)DAT_00b5af88 & 0xffffff00);
    _atexit((_func_4879 *)&LAB_0099b060);
  }
  if ((*(int *)(in_ECX + 0x7c) == 0) ||
     (local_4 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 3, local_4 == 0)) {
    puVar1 = DAT_00b5af88;
    if (DAT_00b5af9c < 0x10) {
      puVar1 = &DAT_00b5af88;
    }
    puVar2 = DAT_00b5af88;
    if (DAT_00b5af9c < 0x10) {
      puVar2 = &DAT_00b5af88;
    }
    FUN_004bdb30(&local_4,puVar2,DAT_00b5af98 + (int)puVar1);
    return &DAT_00b5af84;
  }
  iVar3 = *(int *)(in_ECX + 0x7c);
  while( true ) {
    if (iVar3 == *(int *)(in_ECX + 0x80)) {
      puVar1 = DAT_00b5af88;
      if (DAT_00b5af9c < 0x10) {
        puVar1 = &DAT_00b5af88;
      }
      iVar3 = DAT_00b5af98 + (int)puVar1;
      if (DAT_00b5af9c < 0x10) {
        puVar1 = &DAT_00b5af88;
      }
      else {
        puVar1 = DAT_00b5af88;
      }
      if (iVar3 != 0) {
        iVar3 = iVar3 - (int)puVar1;
      }
      FUN_00401390(0,iVar3);
      return &DAT_00b5af84;
    }
    if ((*(int *)(iVar3 + 4) != 0) && (*(char *)(*(int *)(iVar3 + 4) + 0x72) == '\x01')) break;
    iVar3 = iVar3 + 8;
  }
  iVar3 = FUN_00558120();
  return (undefined *)(iVar3 + 8);
}


// ==== FUN_005758f0 @ 0x005758f0 ====

void FUN_005758f0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x80);
  for (puVar5 = *(undefined4 **)(in_ECX + 0x7c); puVar5 != puVar1; puVar5 = puVar5 + 2) {
    piVar2 = (int *)*puVar5;
    iVar3 = (**(code **)(*piVar2 + 0x3c))();
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*piVar2 + 0x3c))();
      (**(code **)(*piVar4 + 0x7c))(piVar2);
    }
  }
  if (*(void **)(in_ECX + 0x7c) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
    *(undefined4 *)(in_ECX + 0x84) = 0;
                    /* WARNING: Could not recover jumptable at 0x00575950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    return;
  }
  _free(*(void **)(in_ECX + 0x7c));
  return;
}


// ==== FUN_00575960 @ 0x00575960 ====

void FUN_00575960(uint param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 0x7c);
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 0x80) - iVar2 >> 3))) {
    iVar1 = *(int *)(in_ECX + 0x80);
    *(undefined4 *)(in_ECX + 0xec) = 0;
    for (; iVar2 != iVar1; iVar2 = iVar2 + 8) {
      if (*(int *)(iVar2 + 4) != 0) {
        if (*(uint *)(in_ECX + 0xec) == param_1) {
          FUN_00401660(param_2,0,0xffffffff);
        }
        *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
      }
    }
  }
  return;
}


// ==== FUN_005759d0 @ 0x005759d0 ====

void FUN_005759d0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bd644);
  FUN_00402220(apvStack_1c,uVar2);
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(apvStack_1c);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
    iVar3 = FUN_00803725(uVar2);
    in_ECX[0x3a] = iVar3;
  }
  return;
}


// ==== FUN_00575a60 @ 0x00575a60 ====

void FUN_00575a60(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  int local_44;
  undefined1 auStack_3c [12];
  int iStack_30;
  int iStack_28;
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 0xe8) != 0) {
    if (*(int *)(in_ECX + 0x7c) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 3;
    }
    uVar4 = iVar6 - *(int *)(in_ECX + 0x70);
    FUN_0055aac0(uVar4 & ((int)uVar4 < 1) - 1);
    iVar1 = *(int *)(*(int *)(in_ECX + 0xe8) + 0x88);
    uVar4 = 0;
    if (0 < iVar6) {
      local_44 = -iVar1;
      do {
        iVar2 = *(int *)(in_ECX + 0x7c);
        if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x80) - iVar2 >> 3) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        piVar3 = *(int **)(iVar2 + uVar4 * 8);
        uVar5 = (**(code **)(*piVar3 + 0x10))();
        FUN_005041e0(uVar5);
        if ((int)uVar4 < iVar1) {
          auStack_3c[0] = 0;
        }
        else if ((int)uVar4 < *(int *)(in_ECX + 0x70) + iVar1) {
          iStack_30 = local_44 * *(int *)(in_ECX + 0xa4) + 10;
          iStack_28 = *(int *)(in_ECX + 0xa4) + -2 + iStack_30;
          auStack_3c[0] = 1;
        }
        else {
          auStack_3c[0] = 0;
        }
        (**(code **)(*piVar3 + 0xc))(auStack_3c);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        local_44 = local_44 + 1;
        uVar4 = uVar4 + 1;
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      } while ((int)uVar4 < iVar6);
    }
  }
  return;
}


// ==== FUN_00575b90 @ 0x00575b90 ====

void FUN_00575b90(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 local_1c;
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_1c = 0;
  piVar3 = (int *)FUN_00558e00(local_18,&local_1c);
  iVar1 = *(int *)(in_ECX + 0x98);
  iVar2 = *piVar3;
  local_10 = 0;
  if (iVar2 == iVar1) {
    local_c = 0xffffff;
    local_8 = 0;
    local_4 = 0;
  }
  else {
    local_c = *(undefined4 *)(iVar2 + 0x10);
    local_8 = *(undefined4 *)(iVar2 + 0x14);
    local_4 = *(undefined4 *)(iVar2 + 0x18);
  }
  FUN_0056ac60(local_18,&local_10);
  local_1c = 1;
  piVar3 = (int *)FUN_00558e00(&param_1,&local_1c);
  iVar2 = *piVar3;
  if (iVar2 != iVar1) {
    local_c = *(undefined4 *)(iVar2 + 0x10);
    local_8 = *(undefined4 *)(iVar2 + 0x14);
    local_4 = *(undefined4 *)(iVar2 + 0x18);
    local_10 = 1;
    FUN_0056ac60(local_18,&local_10);
  }
  local_1c = 4;
  piVar3 = (int *)FUN_00558e00(&param_1,&local_1c);
  iVar2 = *piVar3;
  if (iVar2 != iVar1) {
    local_c = *(undefined4 *)(iVar2 + 0x10);
    local_8 = *(undefined4 *)(iVar2 + 0x14);
    local_4 = *(undefined4 *)(iVar2 + 0x18);
    local_10 = 4;
    FUN_0056ac60(local_18,&local_10);
  }
  return;
}


// ==== FUN_00575cc0 @ 0x00575cc0 ====

undefined4 FUN_00575cc0(int param_1)

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
        FUN_005759d0();
        (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(in_ECX[0x10]);
    in_ECX[0x10] = 0;
  }
  return 0;
}


// ==== FUN_00575d60 @ 0x00575d60 ====

/* WARNING: Removing unreachable block (ram,0x00575dff) */

void FUN_00575d60(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  undefined4 uVar7;
  int *in_ECX;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined1 local_2c [4];
  void *local_28;
  int local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009bd64c,1);
  FUN_00405300(param_1,local_1c,local_2c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  puVar9 = (undefined4 *)in_ECX[0x1f];
  puVar1 = (undefined4 *)in_ECX[0x20];
  do {
    if (puVar9 == puVar1) {
      if (local_28 == (void *)0x0) {
        return;
      }
      FUN_00405de0(local_28,local_24,local_2c,param_1);
      _free(local_28);
      return;
    }
    iVar4 = (**(code **)(*(int *)*puVar9 + 0x50))();
    uVar2 = *(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      pbVar10 = (byte *)(param_1 + 4);
    }
    else {
      pbVar10 = *(byte **)(param_1 + 4);
    }
    uVar3 = *(uint *)(iVar4 + 0x14);
    if (uVar3 == 0) {
LAB_00575e31:
      if ((uVar3 < uVar2) || (uVar3 != uVar2)) goto LAB_00575e40;
      FUN_00558730(1);
      piVar6 = (int *)(**(code **)(*in_ECX + 0x3c))();
      if ((local_28 == (void *)0x0) || ((uint)((local_24 - (int)local_28) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar4 = *piVar6;
      uVar7 = thunk_FUN_00796fb0((int)local_28 + 0x1c);
      (**(code **)(iVar4 + 0x80))(1,uVar7);
    }
    else {
      uVar8 = uVar3;
      if (uVar2 <= uVar3) {
        uVar8 = uVar2;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar11 = false;
      iVar4 = 0;
      bVar12 = true;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar11 = *pbVar5 < *pbVar10;
        bVar12 = *pbVar5 == *pbVar10;
        pbVar5 = pbVar5 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (iVar4 == 0) goto LAB_00575e31;
LAB_00575e40:
      FUN_00558730(0);
    }
    puVar9 = puVar9 + 2;
  } while( true );
}


// ==== FUN_00575f00 @ 0x00575f00 ====

undefined4 FUN_00575f00(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 ****ppppuVar4;
  int iVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  bool bVar6;
  char *pcVar7;
  undefined1 auStack_38 [4];
  undefined4 ****local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  bVar6 = false;
  if (param_1 == 4) {
    bVar6 = true;
    uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009bd644);
    FUN_00402220(auStack_38,uVar3);
    ppppuVar4 = local_34;
    if (local_20 < 0x10) {
      ppppuVar4 = &local_34;
    }
    iVar5 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppuVar4,uStack_24);
    if ((iVar5 == 0) && (bVar1 = true, param_3 == 6)) goto LAB_00575f73;
  }
  bVar1 = false;
LAB_00575f73:
  if ((bVar6) && (0xf < local_20)) {
    _free(local_34);
    return extraout_EAX;
  }
  if (bVar1) {
    FUN_00575a60();
    return 1;
  }
  if ((param_1 == 1) && (param_3 == 1)) {
    local_34 = (undefined4 ****)0x0;
    uStack_30 = 0;
    uStack_2c = 0;
    FUN_00401830(&DAT_009bd634);
    FUN_00405300(param_2,auStack_1c,auStack_38);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_00;
    }
    pcVar7 = s_listItem_009bd638;
    uVar3 = FUN_00405d30(0);
    cVar2 = FUN_004036a0(uVar3,pcVar7);
    if (cVar2 != '\0') {
      FUN_00575d60(param_2);
      FUN_00406250();
      return 1;
    }
    FUN_00406250();
  }
  return 0;
}


// ==== FUN_00576050 @ 0x00576050 ====

void FUN_00576050(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 local_44;
  undefined1 local_40 [8];
  undefined4 local_38 [4];
  void *local_28;
  uint local_14;
  
  local_44 = 0;
  piVar3 = (int *)FUN_00557be0(local_40,&local_44);
  iVar2 = param_2;
  iVar1 = *(int *)(in_ECX + 0x8c);
  if (*piVar3 == iVar1) {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined4 *)(iVar2 + 0x28) = 0xff000000;
    *(undefined4 *)(iVar2 + 0x24) = 2;
  }
  else {
    FUN_005523f0(*piVar3 + 0x10);
    FUN_00401660(param_1,0,0xffffffff);
  }
  *(undefined1 *)(iVar2 + 0x31) = *(undefined1 *)(in_ECX + 0xac);
  local_38[0] = 0;
  FUN_00504250(iVar2);
  FUN_00505600(local_40,local_38);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_44 = 1;
  piVar3 = (int *)FUN_00557be0(&param_1,&local_44);
  if (*piVar3 != iVar1) {
    local_38[0] = 1;
    FUN_00504250(*piVar3 + 0x10);
    FUN_00505600(local_40,local_38);
    if (0xf < local_14) {
      _free(local_28);
      return;
    }
  }
  local_44 = 4;
  piVar3 = (int *)FUN_00557be0(&param_1,&local_44);
  if (*piVar3 != iVar1) {
    local_38[0] = 4;
    FUN_00504250(*piVar3 + 0x10);
    FUN_00505600(local_40,local_38);
    if (0xf < local_14) {
      _free(local_28);
      return;
    }
  }
  return;
}


// ==== FUN_005761d0 @ 0x005761d0 ====

void FUN_005761d0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd66c;
  in_ECX[0x1c] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  FUN_00505ba0();
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00576240 @ 0x00576240 ====

void FUN_00576240(void)

{
  undefined4 *in_ECX;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009bd66c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((void *)in_ECX[0x1f] != (void *)0x0) {
      _free((void *)in_ECX[0x1f]);
      return;
    }
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
    if (*(char *)(in_ECX + 0x11) == '\0') {
      FUN_0044a580(local_100,&DAT_009bd65c,s_VScroll_Close_Fail_009bd620);
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
  FUN_00505c10();
  if ((void *)in_ECX[0x1f] == (void *)0x0) {
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x1f]);
  return;
}


// ==== FUN_005762f0 @ 0x005762f0 ====

void FUN_005762f0(int param_1)

{
  int iVar1;
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_00576be0(param_1 + 0x25c);
  param_1 = 0;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 != (int *)in_ECX[0x26]) {
    in_ECX[0x37] = local_4[4];
    in_ECX[0x38] = local_4[5];
    in_ECX[0x39] = local_4[6];
  }
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  in_ECX[0x1c] = ((*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + -0x14) / in_ECX[0x29];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_00576380 @ 0x00576380 ====

/* WARNING: Removing unreachable block (ram,0x00576727) */

void FUN_00576380(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  int in_ECX;
  char *pcVar6;
  undefined1 auStack_fa [10];
  int *local_d8;
  void *pvStack_a0;
  undefined1 uStack_9c;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 uStack_78;
  void *pvStack_74;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint auStack_60 [3];
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  uint uStack_18;
  
  iVar3 = FUN_00403620();
  if (iVar3 != 0) {
    if (*(int *)(in_ECX + 0x7c) == 0) {
      local_d8 = (int *)0x0;
    }
    else {
      local_d8 = (int *)(*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 3);
    }
    (**(code **)(*DAT_00b5a7ac + 4))();
    (**(code **)(*DAT_00b5a7ac + 8))();
    uStack_88 = 0xf;
    uStack_8c = 0;
    uStack_9c = 0;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    pvStack_2c = (void *)0x0;
    pvVar4 = operator_new(0x468);
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = (void *)FUN_00505f10();
    }
    *(undefined1 *)((int)pvVar4 + 0x104) = 0;
    *(undefined1 *)((int)pvVar4 + 0x105) = 0;
    *(undefined1 *)((int)pvVar4 + 0x107) = 0;
    *(undefined1 *)((int)pvVar4 + 0x10c) = 0;
    *(undefined4 *)((int)pvVar4 + 0x108) = 0xc;
    *(undefined4 *)((int)pvVar4 + 0x110) = 500;
    *(undefined1 *)((int)pvVar4 + 0x106) = 0;
    uStack_84 = 0;
    uStack_80 = 0;
    uStack_64 = 0xf;
    uStack_68 = 0;
    uStack_78 = 0;
    auStack_60[0] = 1;
    auStack_60[1] = 0;
    auStack_60[2] = 1;
    uStack_54 = 0;
    uStack_53 = 0;
    FUN_00576050();
    FUN_00575b90();
    (**(code **)(*DAT_00b5a688 + 0x34))();
    FUN_00401740(s_listItem__x_009bd650,0xb);
    iVar3 = FUN_00404230(&uStack_30);
    if (*(uint *)(iVar3 + 0x18) < 0x10) {
      pcVar5 = (char *)(iVar3 + 4);
    }
    else {
      pcVar5 = *(char **)(iVar3 + 4);
    }
    pcVar6 = pcVar5;
    do {
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(pcVar5);
    if (0xf < uStack_18) {
      _free(pvStack_2c);
      return;
    }
    FUN_00401660(auStack_60,0);
    (**(code **)(*local_d8 + 8))();
    piVar1 = *(int **)(in_ECX + 4);
    if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*local_d8 + 0x74))(piVar1), cVar2 != '\0'))
    {
      cVar2 = (**(code **)(*piVar1 + 0x78))(local_d8);
      if (cVar2 == '\0') {
        (**(code **)(*local_d8 + 0x74))(0);
      }
      else {
        iVar3 = (**(code **)(*piVar1 + 0x38))();
        local_d8[1] = iVar3;
      }
    }
    (**(code **)(*local_d8 + 0x38))(local_d8);
    (**(code **)(*local_d8 + 0x1c))(&uStack_68);
    (**(code **)(*local_d8 + 8))(&pvStack_a0);
    (**(code **)(*local_d8 + 0x2c))(local_d8);
    (**(code **)(*local_d8 + 0x24))(pvVar4);
    if (pvVar4 != (void *)0x0) {
      FUN_00505d80();
      _free(pvVar4);
      return;
    }
    FUN_00576b70(auStack_fa + -6);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return;
    }
    uStack_8c = 0xf;
    uStack_90 = 0;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    if (0xf < auStack_60[0]) {
      _free(pvStack_74);
      return;
    }
  }
  return;
}


// ==== FUN_00576750 @ 0x00576750 ====

void FUN_00576750(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_005758f0();
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    FUN_00576380(iVar2);
  }
  FUN_00575a60();
  return;
}


// ==== FUN_00576790 @ 0x00576790 ====

void FUN_00576790(int param_1,int param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_2 = param_2 + -8) {
    param_3[-2] = *(undefined4 *)(param_2 + -8);
    param_3[-1] = *(undefined4 *)(param_2 + -4);
    param_3 = param_3 + -2;
  }
  return;
}


// ==== FUN_005767c0 @ 0x005767c0 ====

void FUN_005767c0(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
  }
  return;
}


// ==== FUN_005767e0 @ 0x005767e0 ====

int FUN_005767e0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982090;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    FUN_005767c0(param_3,param_1);
    param_3 = param_3 + 8;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00576846 @ 0x00576846 ====

void Catch_00576846(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00576850 @ 0x00576850 ====

void FUN_00576850(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009820a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005767c0(param_1,param_3);
    param_1 = param_1 + 8;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005768b6 @ 0x005768b6 ====

void Catch_005768b6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005768c0 @ 0x005768c0 ====

void FUN_005768c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005767e0(param_1,param_2,param_3);
  return;
}


// ==== FUN_005768e0 @ 0x005768e0 ====

int FUN_005768e0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00576850(param_1,param_2,param_3);
  return param_1 + param_2 * 8;
}


// ==== FUN_00576910 @ 0x00576910 ====

void FUN_00576910(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  int local_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009820b0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
  local_38 = *param_3;
  local_34 = param_3[1];
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(in_ECX + 0xc) - iVar2 >> 3;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    uVar5 = param_2;
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x44);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_0085b3b0();
      uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
      local_20 = (uint)uVar7;
      iVar2 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    if (local_20 < iVar6 + uVar5) {
      if (0x1fffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar2 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
      }
      if (local_20 < iVar6 + uVar5) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 3;
        }
        local_20 = iVar2 + uVar5;
      }
      local_20 = local_20 * 8;
      pvVar3 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar3;
      local_1c = FUN_005768c0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_1c = FUN_005768e0(local_1c,param_2,&local_38);
      FUN_005768c0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar3;
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 8);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar2 = *(int *)(in_ECX + 8);
    if ((uint)(iVar2 - param_1 >> 3) < uVar5) {
      local_18 = uVar5 * 8;
      FUN_005767e0(param_1,iVar2,local_18 + param_1);
      local_8 = 2;
      FUN_005768e0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_38);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) - local_18,&local_38);
      ExceptionList = local_10;
      return;
    }
    local_18 = uVar5 * 8;
    local_28 = iVar2 + uVar5 * -8;
    uVar4 = FUN_005767e0(local_28,iVar2,iVar2);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00576790(param_1,local_28,iVar2);
    FUN_00686630(param_1,local_18 + param_1,&local_38);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00576a79 @ 0x00576a79 ====

void Catch_00576a79(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_00576b70 @ 0x00576b70 ====

void FUN_00576b70(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_00576910(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00576850(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_00576be0 @ 0x00576be0 ====

void FUN_00576be0(int param_1)

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
  *(undefined1 *)(in_ECX + 0x24) = *(undefined1 *)(iVar1 + 0x24);
  FUN_0043b3d0(iVar1 + 0x28);
  FUN_00401660(iVar1 + 0x38,0,0xffffffff);
  return;
}


// ==== FUN_00576c70 @ 0x00576c70 ====

void FUN_00576c70(byte param_1)

{
  void *in_ECX;
  
  FUN_00576240();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00576ca0 @ 0x00576ca0 ====

undefined4 FUN_00576ca0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  if (iVar1 == *param_1) {
    return *(undefined4 *)(in_ECX + 4);
  }
                    /* WARNING: Could not recover jumptable at 0x00576cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x48))();
  return uVar2;
}


// ==== FUN_00576cd0 @ 0x00576cd0 ====

void FUN_00576cd0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00576cf0 @ 0x00576cf0 ====

void FUN_00576cf0(undefined1 *param_1)

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


// ==== FUN_00576dc0 @ 0x00576dc0 ====

uint FUN_00576dc0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_00576dd0 @ 0x00576dd0 ====

void FUN_00576dd0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  if (iVar1 == param_1) {
    piVar2 = *(int **)(in_ECX + 4);
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x48))(&param_1);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 100))();
  }
  return;
}


// ==== FUN_00576f10 @ 0x00576f10 ====

undefined4 FUN_00576f10(int param_1)

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


// ==== FUN_00576fa0 @ 0x00576fa0 ====

int * FUN_00576fa0(undefined1 *param_1,undefined4 *param_2,char param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *unaff_EBP;
  undefined4 unaff_ESI;
  int *unaff_EDI;
  undefined4 local_9c;
  undefined4 uStack_98;
  void *pvStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  undefined1 auStack_7c [4];
  undefined1 uStack_78;
  void *apvStack_70 [2];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 uStack_54;
  void *pvStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_9c = *(int *)(param_1 + 0x5c);
  if (local_9c == 0) {
    return (int *)0x0;
  }
  if (param_3 == '\0') {
    piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(8);
    param_2[0x66] = 5;
    param_2[0x67] = 5;
    *(undefined1 *)(param_2 + 0x65) = 0;
    *(undefined1 *)((int)param_2 + 0x195) = 0;
    *(undefined1 *)((int)param_2 + 0x196) = 0;
    param_2[0x68] = 0xc;
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined1 *)(param_2 + 0x65) = 0;
    *(undefined1 *)((int)param_2 + 0x196) = 1;
    puVar1 = *(undefined4 **)(param_1 + 0x20);
    if (puVar1 == (undefined4 *)0x0) {
      *param_2 = 0;
      param_2[1] = 0;
    }
    else {
      *param_2 = *puVar1;
      param_2[1] = puVar1[1];
      param_2[2] = puVar1[2];
    }
  }
  else {
    piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(1);
  }
  local_9c._0_3_ = CONCAT12(1,(undefined2)local_9c);
  uStack_98 = 0;
  pvStack_94 = (void *)0x0;
  iStack_90 = 0;
  iStack_8c = 0;
  iStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_64 = 0xf;
  uStack_68 = 0;
  uStack_78 = 0;
  FUN_00401660(param_1 + 0x24,0,0xffffffff);
  uStack_98 = *(undefined4 *)(param_1 + 0xc);
  iStack_90 = *(int *)(param_1 + 0x14);
  pvStack_94 = *(void **)(param_1 + 0x10);
  iStack_8c = *(int *)(param_1 + 0x18) + (int)pvStack_94;
  uStack_38 = *(undefined4 *)(param_1 + 4);
  iStack_88 = *(int *)(param_1 + 0x1c) + iStack_90;
  uStack_3c = *(undefined4 *)(param_1 + 8);
  uStack_5c = (*(int *)(param_1 + 0x1c) + -0xc) / 2;
  local_9c._0_2_ = CONCAT11(1,*param_1);
  uStack_40 = 0xf;
  pvStack_44 = (void *)0x0;
  uStack_54 = 0;
  uStack_34 = 1;
  uStack_30 = (uint)uStack_30._2_2_ << 0x10;
  uStack_60 = 0;
  FUN_00401660(param_1 + 0x40,0,0xffffffff);
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  FUN_00401660(auStack_7c,0,0xffffffff);
  (**(code **)(*piVar4 + 8))(&local_9c);
  cVar2 = (**(code **)(*piVar4 + 0x74))(unaff_ESI);
  if (cVar2 != '\0') {
    cVar2 = (**(code **)(*unaff_EBP + 0x78))(piVar4);
    if (cVar2 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar5 = (**(code **)(*unaff_EDI + 0x38))();
      piVar4[1] = iVar5;
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar4);
  (**(code **)(*piVar3 + 0x1c))(&uStack_38);
  (**(code **)(*piVar3 + 8))(apvStack_70);
  (**(code **)(*piVar4 + 0x2c))(piVar3);
  (**(code **)(*piVar3 + 0x24))(param_2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return extraout_EAX;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  if (0xf < uStack_5c) {
    _free(apvStack_70[0]);
    return extraout_EAX_00;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  apvStack_70[0] = (void *)((uint)apvStack_70[0] & 0xffffff00);
  if (uStack_80 < 0x10) {
    return piVar4;
  }
  _free(pvStack_94);
  return extraout_EAX_01;
}


// ==== FUN_005772c0 @ 0x005772c0 ====

void FUN_005772c0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_98 [4];
  void *pvStack_94;
  undefined4 uStack_84;
  uint uStack_80;
  int aiStack_7c [2];
  int iStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  uint uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar1 = *(int **)(in_ECX + 0xe0);
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  uStack_70 = *(uint *)(iVar2 + 8);
  uStack_6c = *(undefined4 *)(iVar2 + 0xc);
  uStack_68 = *(undefined4 *)(iVar2 + 0x10);
  uStack_64 = *(undefined4 *)(iVar2 + 0x14);
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  uStack_40 = 0;
  auStack_60[0] = 1;
  uStack_5c = 0xffffffff;
  iStack_54 = 100;
  uStack_58 = 3;
  piStack_4 = (int *)0x0;
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  iStack_54 = *(int *)(iVar2 + 4) + 1;
  piStack_4 = piVar1;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__body_009bd768);
  uVar3 = FUN_00402220(auStack_98,uVar3);
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  FUN_00401740(s_board_body_009bd770,10);
  piVar4 = (int *)FUN_0069a470(aiStack_7c,auStack_98);
  if (*piVar4 == *(int *)(in_ECX + 0xd8)) {
    uStack_40 = 0;
  }
  else {
    uStack_40 = *(undefined4 *)(*piVar4 + 0x28);
  }
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_50 = uStack_70;
  uStack_48 = uStack_68;
  iStack_44 = param_6;
  iStack_4c = param_2;
  FUN_00576fa0(auStack_60,param_1,0);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(&DAT_009bd77c);
  uVar3 = FUN_00402220(auStack_98,uVar3);
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  FUN_00401740(s_board_tag_009bd784,9);
  piVar4 = (int *)FUN_0069a470(aiStack_7c,auStack_98);
  if (*piVar4 == *(int *)(in_ECX + 0xd8)) {
    uStack_40 = 0;
  }
  else {
    uStack_40 = *(undefined4 *)(*piVar4 + 0x28);
  }
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_48 = uStack_68;
  uStack_50 = uStack_70;
  iStack_4c = param_6 + param_2;
  iStack_44 = 9;
  FUN_00576fa0(auStack_60,param_1,0);
  if ((*(int *)(in_ECX + 0xa0) == 0) ||
     (aiStack_7c[0] = *(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2, aiStack_7c[0] == 0)) {
    FUN_00578ce0();
    return;
  }
  uStack_5c = 0xffffffff;
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  iStack_54 = *(int *)(iVar2 + 4) + 2;
  uStack_50 = param_3;
  uStack_48 = param_4;
  iStack_44 = param_5;
  uStack_40 = 0;
  for (uVar5 = 0;
      (iVar2 = *(int *)(in_ECX + 0xa0), iStack_74 = param_2, iVar2 != 0 &&
      (uVar5 < (uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2))); uVar5 = uVar5 + 1) {
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    iVar2 = *(int *)(iVar2 + uVar5 * 4);
    aiStack_7c[0] = *(int *)(iVar2 + 4);
    (**(code **)(**(int **)(in_ECX + 4) + 0x50))();
    FUN_00401740(s__s_n__d_009bd79c,7);
    FUN_00404230(auStack_98);
    FUN_00401660(auStack_98,0,0xffffffff);
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return;
    }
    uStack_80 = 0xf;
    uStack_84 = 0;
    pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
    FUN_00401660(iVar2 + 8,0,0xffffffff);
    param_2 = iStack_74;
    iStack_4c = iStack_74;
    uStack_70 = uVar5;
    uStack_6c = FUN_00576fa0(auStack_60,param_1,0);
    FUN_00578f10(aiStack_7c,&uStack_70);
    param_2 = param_2 + param_5;
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  if (uStack_24 < 0x10) {
    return;
  }
  _free(pvStack_38);
  return;
}


// ==== FUN_00577700 @ 0x00577700 ====

undefined4 FUN_00577700(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  if (in_ECX == -0x8c) {
    return 0;
  }
  if ((*(int *)(in_ECX + 0xa0) == 0) ||
     ((uint)(*(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2) <= param_1)) {
    return 0;
  }
  iVar1 = *(int *)(in_ECX + 0xa0);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_00577750 @ 0x00577750 ====

int FUN_00577750(int param_1)

{
  int iVar1;
  undefined4 ****ppppuVar2;
  int iVar3;
  int extraout_EAX;
  int in_ECX;
  uint uVar4;
  uint local_24;
  undefined1 auStack_1c [4];
  undefined4 ****appppuStack_18 [4];
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar4 = 0;
  if (in_ECX != -0x8c) {
    if (*(int *)(in_ECX + 0xa0) == 0) {
      local_24 = 0;
    }
    else {
      local_24 = *(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2;
    }
    if (local_24 != 0) {
      do {
        if (((in_ECX != -0x8c) && (iVar1 = *(int *)(in_ECX + 0xa0), iVar1 != 0)) &&
           (uVar4 < (uint)(*(int *)(in_ECX + 0xa4) - iVar1 >> 2))) {
          if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar1 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          iVar1 = *(int *)(iVar1 + uVar4 * 4);
          if (iVar1 != 0) {
            (**(code **)(**(int **)(in_ECX + 4) + 0x50))();
            FUN_00401740(s__s_n__d_009bd79c,7);
            FUN_00404230(auStack_1c);
            ppppuVar2 = appppuStack_18[0];
            if (uStack_4 < 0x10) {
              ppppuVar2 = appppuStack_18;
            }
            iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),ppppuVar2,uStack_8);
            if (0xf < uStack_4) {
              _free(appppuStack_18[0]);
              return extraout_EAX;
            }
            uStack_4 = 0xf;
            uStack_8 = 0;
            appppuStack_18[0] = (undefined4 ****)((uint)appppuStack_18[0] & 0xffffff00);
            if (iVar3 == 0) {
              return iVar1;
            }
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_24);
    }
  }
  return 0;
}


// ==== FUN_005778b0 @ 0x005778b0 ====

int FUN_005778b0(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xd0);
  if (((in_ECX != -0x8c) && (iVar2 = *(int *)(in_ECX + 0xa0), iVar2 != 0)) &&
     (uVar1 < (uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2))) {
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    iVar2 = *(int *)(iVar2 + uVar1 * 4);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(iVar2 + 8,0,0xffffffff);
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_009bd799,0);
  return param_1;
}


// ==== FUN_00577950 @ 0x00577950 ====

undefined4 FUN_00577950(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (((in_ECX != -0x8c) && (iVar1 = *(int *)(in_ECX + 0xa0), iVar1 != 0)) &&
     (param_1 < (uint)(*(int *)(in_ECX + 0xa4) - iVar1 >> 2))) {
    if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    puVar2 = *(undefined4 **)(iVar1 + param_1 * 4);
    if (puVar2 != (undefined4 *)0x0) {
      return *puVar2;
    }
  }
  return 0xffffffff;
}


// ==== FUN_005779a0 @ 0x005779a0 ====

void FUN_005779a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((*(int **)(in_ECX + 0xe4) != (int *)0x0) &&
      (iVar1 = (**(code **)(**(int **)(in_ECX + 0xe4) + 0x30))(), iVar1 != 0)) &&
     (iVar1 = FUN_00577700(param_1), iVar1 != 0)) {
    FUN_0055a260(iVar1 + 8);
    iVar1 = FUN_00577950(param_1);
    if (-1 < iVar1) {
      *(undefined4 *)(in_ECX + 0xd0) = param_1;
    }
  }
  return;
}


// ==== FUN_005779f0 @ 0x005779f0 ====

undefined1 FUN_005779f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 local_d;
  undefined4 local_8;
  uint local_4;
  
  if (in_ECX == -0x8c) {
    return 0;
  }
  if (*(int *)(in_ECX + 0xa0) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2;
  }
  uVar4 = 0;
  local_d = 0;
  if (uVar3 != 0) {
    do {
      if (((in_ECX != -0x8c) && (iVar2 = *(int *)(in_ECX + 0xa0), iVar2 != 0)) &&
         (uVar4 < (uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2))) {
        if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        iVar2 = *(int *)(iVar2 + uVar4 * 4);
        if (iVar2 != 0) {
          local_8 = *(undefined4 *)(iVar2 + 4);
          FUN_0079bba0(&local_4,&local_8);
          if (((local_4 != *(uint *)(in_ECX + 0xec)) &&
              (piVar1 = *(int **)(local_4 + 0x10), piVar1 != (int *)0x0)) &&
             (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
            iVar2 = (**(code **)(*piVar1 + 4))();
            if (iVar2 == param_1) {
              uVar5 = 0x551e90ff;
            }
            else {
              uVar5 = 0;
            }
            FUN_00558ff0(uVar5);
            local_d = 1;
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return local_d;
}


// ==== FUN_00577b00 @ 0x00577b00 ====

void FUN_00577b00(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005779a0(param_1);
    iVar1 = FUN_00577950(*(undefined4 *)(in_ECX + 0xd0));
    if (-1 < iVar1) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x80))(1,iVar1);
    }
  }
  return;
}


// ==== FUN_00577b40 @ 0x00577b40 ====

void FUN_00577b40(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int in_ECX;
  undefined1 auStack_7c [4];
  undefined4 uStack_78;
  undefined4 uStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_54;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  piVar1 = *(int **)(in_ECX + 0xe0);
  if (piVar1 != (int *)0x0) {
    iVar7 = (**(code **)(*piVar1 + 0x3c))();
    if (iVar7 != 0) {
      piVar8 = (int *)(**(code **)(*piVar1 + 0x3c))();
      (**(code **)(*piVar8 + 0x7c))(piVar1);
    }
    *(undefined4 *)(in_ECX + 0xe0) = 0;
  }
  if ((*(int *)(in_ECX + 0xa0) != 0) &&
     (*(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2 != 0)) {
    iVar7 = *(int *)(in_ECX + 0x74);
    iVar2 = *(int *)(in_ECX + 0x7c);
    piVar1 = *(int **)(in_ECX + 4);
    if (*(int *)(in_ECX + 0xa0) == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2;
    }
    iVar3 = *(int *)(in_ECX + 0x98);
    uVar4 = *(undefined4 *)(in_ECX + 0x8c);
    uVar5 = *(undefined4 *)(in_ECX + 0x90);
    iVar9 = iVar3 * iVar9;
    uVar6 = *(undefined4 *)(in_ECX + 0x94);
    uStack_40 = 0xf;
    uStack_44 = 0;
    uStack_54 = 0;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = 0;
    uStack_5c = 0;
    uStack_78 = 0xffffffff;
    iStack_70 = 100;
    uStack_74 = 3;
    piStack_20 = (int *)0x0;
    auStack_7c[0] = 0;
    iVar10 = (**(code **)(*piVar1 + 0x10))();
    iStack_70 = *(int *)(iVar10 + 4) + 1;
    piStack_20 = piVar1;
    uVar11 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__list_009bd760);
    uVar11 = FUN_00402220(auStack_1c,uVar11);
    FUN_00401660(uVar11,0,0xffffffff);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_64 = *(undefined4 *)(in_ECX + 0xc4);
    uStack_6c = *(undefined4 *)(in_ECX + 0xbc);
    iStack_68 = (iVar2 - iVar7) + -1;
    iStack_60 = iVar9 + 9;
    uVar11 = FUN_00576fa0(auStack_7c,param_1,0);
    *(undefined4 *)(in_ECX + 0xe0) = uVar11;
    FUN_005772c0(param_1,uVar5,uVar4,uVar6,iVar3,iVar9);
    FUN_00578ce0();
  }
  return;
}


// ==== FUN_00577d20 @ 0x00577d20 ====

undefined4 FUN_00577d20(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xd0);
  if (((in_ECX != -0x8c) && (iVar2 = *(int *)(in_ECX + 0xa0), iVar2 != 0)) &&
     (uVar1 < (uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2))) {
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar2 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    puVar3 = *(undefined4 **)(iVar2 + uVar1 * 4);
    if (puVar3 != (undefined4 *)0x0) {
      return *puVar3;
    }
  }
  return 0xffffffff;
}


// ==== FUN_00577d70 @ 0x00577d70 ====

void FUN_00577d70(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  puVar1 = param_1;
  if ((in_ECX != -0x8c) && (iVar2 = FUN_00577700(param_1[1]), iVar2 == 0)) {
    param_1 = operator_new(0x24);
    if (param_1 == (undefined4 *)0x0) {
      param_1 = (undefined4 *)0x0;
    }
    else {
      param_1[8] = 0xf;
      param_1[7] = 0;
      *(undefined1 *)(param_1 + 3) = 0;
    }
    *param_1 = *puVar1;
    param_1[1] = puVar1[1];
    FUN_00401660(puVar1 + 2,0,0xffffffff);
    FUN_0056b030(&param_1);
  }
  return;
}


// ==== FUN_00577df0 @ 0x00577df0 ====

void FUN_00577df0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((*(int **)(in_ECX + 0xe4) != (int *)0x0) &&
      (iVar1 = (**(code **)(**(int **)(in_ECX + 0xe4) + 0x30))(), iVar1 != 0)) &&
     (iVar1 = FUN_00577700(param_1), iVar1 != 0)) {
    FUN_0055a260(iVar1 + 8);
    iVar1 = FUN_00577950(param_1);
    if (-1 < iVar1) {
      *(undefined4 *)(in_ECX + 0xd0) = param_1;
    }
  }
  return;
}


// ==== FUN_00577e40 @ 0x00577e40 ====

void FUN_00577e40(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_4c;
  int local_48;
  char cStack_3c;
  char cStack_3b;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_8;
  uint uStack_4;
  
  if (*(int **)(in_ECX + 0xe0) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xe0) + 0x10))();
    FUN_005041e0(uVar1);
    cStack_3c = param_1;
    cStack_3b = param_1;
    (**(code **)(**(int **)(in_ECX + 0xe0) + 0xc))(&cStack_3c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  *(char *)(in_ECX + 0xcc) = param_1;
  if (param_1 != '\x01') {
    uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    FUN_005041e0(uVar1);
    uStack_34 = *(undefined4 *)(in_ECX + 0x70);
    uStack_30 = *(undefined4 *)(in_ECX + 0x74);
    uStack_2c = *(undefined4 *)(in_ECX + 0x78);
    uStack_28 = *(undefined4 *)(in_ECX + 0x7c);
    (**(code **)(**(int **)(in_ECX + 4) + 0xc))(&cStack_3c);
    FUN_005779f0(0);
    if (uStack_8 < 0x10) {
      return;
    }
    _free(pvStack_1c);
    return;
  }
  local_4c = *(undefined4 *)(in_ECX + 0x78);
  if (*(int *)(in_ECX + 0xa0) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xa4) - *(int *)(in_ECX + 0xa0) >> 2;
  }
  local_48 = *(int *)(in_ECX + 0x98) * iVar2 + 9 + *(int *)(in_ECX + 0x7c);
  (**(code **)(**(int **)(in_ECX + 4) + 0x68))(&local_4c);
  return;
}


// ==== FUN_00577f60 @ 0x00577f60 ====

undefined4 FUN_00577f60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  undefined1 auStack_1c [28];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar1 = FUN_005789b0(s_drop_btn_009bd790,0xffffffff,8);
      if (iVar1 != -1) {
        if (*(char *)(in_ECX + 0xcc) == '\0') {
          FUN_00577e40(1);
          return 1;
        }
        FUN_00577e40(0);
        return 1;
      }
    }
  }
  else if (param_1 == 8) {
    if (param_3 == 1) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))();
      iVar1 = param_2;
      if (*(uint *)(iVar2 + 0x18) < 0x10) {
        iVar3 = iVar2 + 4;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
      }
      iVar2 = FUN_004059c0(iVar3,0,*(undefined4 *)(iVar2 + 0x14));
      if (iVar2 != -1) {
        if (*(char *)(in_ECX + 0xcc) != '\0') {
          param_2 = CONCAT31(param_2._1_3_,0x5f);
          iVar2 = FUN_00405920(&param_2,0xffffffff,1);
          uVar4 = FUN_00405b90(auStack_1c,iVar2 + 1,*(int *)(iVar1 + 0x14) - (iVar2 + 1));
          thunk_FUN_00796fb0(uVar4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
    }
    else if (param_3 == 4) {
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(param_2);
      if (piVar5 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar5 + 4))();
        FUN_005779f0(uVar4);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_005780b0 @ 0x005780b0 ====

void FUN_005780b0(undefined4 param_1,int param_2)

{
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  int local_4;
  
  if (param_2 != 0) {
    local_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    local_8 = 0xf;
    FUN_00401660(param_1,0,0xffffffff);
    local_4 = param_2;
    FUN_005793b0(local_28,local_20);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  return;
}


// ==== FUN_00578120 @ 0x00578120 ====

void FUN_00578120(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd7e4;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  iVar1 = FUN_00578b30();
  in_ECX[0x36] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[0x36] + 4) = in_ECX[0x36];
  *(undefined4 *)in_ECX[0x36] = in_ECX[0x36];
  *(undefined4 *)(in_ECX[0x36] + 8) = in_ECX[0x36];
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  iVar1 = FUN_00578bd0();
  in_ECX[0x3b] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x3b] + 4) = in_ECX[0x3b];
  *(undefined4 *)in_ECX[0x3b] = in_ECX[0x3b];
  *(undefined4 *)(in_ECX[0x3b] + 8) = in_ECX[0x3b];
  in_ECX[0x3c] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x34] = 0;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_005781f0 @ 0x005781f0 ====

void FUN_005781f0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int *piVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined4 *apuStack_98 [2];
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int *piStack_4;
  
  piVar1 = *(int **)(in_ECX + 4);
  iVar4 = (**(code **)(*piVar1 + 0x10))();
  uVar8 = *(undefined4 *)(iVar4 + 0xc);
  uVar2 = *(undefined4 *)(iVar4 + 0x10);
  uVar3 = *(undefined4 *)(iVar4 + 0x14);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(iVar4 + 8);
  *(undefined4 *)(in_ECX + 0x74) = uVar8;
  *(undefined4 *)(in_ECX + 0x78) = uVar2;
  *(undefined4 *)(in_ECX + 0x7c) = uVar3;
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = (void *)FUN_00505f10();
  }
  pvVar6 = operator_new(0x468);
  if (pvVar6 == (void *)0x0) {
    uStack_64 = 0;
  }
  else {
    uStack_64 = FUN_00505f10();
  }
  *(undefined1 *)((int)pvVar5 + 0x104) = 0;
  *(undefined1 *)((int)pvVar5 + 0x105) = 0;
  *(undefined1 *)((int)pvVar5 + 0x107) = 0;
  *(undefined1 *)((int)pvVar5 + 0x10c) = 0;
  *(undefined4 *)((int)pvVar5 + 0x108) = 0xc;
  *(undefined4 *)((int)pvVar5 + 0x110) = 500;
  *(undefined1 *)((int)pvVar5 + 0x106) = 0;
  *(undefined1 *)((int)pvVar5 + 0xc) = 1;
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  FUN_00401740(s_btn_none_009bd718,8);
  piVar7 = (int *)FUN_0069a470(apuStack_98,auStack_90);
  if (*piVar7 == *(int *)(in_ECX + 0xd8)) {
    apuStack_98[0] = (undefined4 *)0x0;
  }
  else {
    apuStack_98[0] = *(undefined4 **)(*piVar7 + 0x28);
  }
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (apuStack_98[0] != (undefined4 *)0x0) {
    uStack_70 = *apuStack_98[0];
    uStack_6c = apuStack_98[0][1];
    uStack_68 = apuStack_98[0][2];
    uStack_74 = 0;
    FUN_0056ac60(apuStack_98,&uStack_74);
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  FUN_00401740(s_btn_over_009bd724,8);
  piVar7 = (int *)FUN_0069a470(apuStack_98,auStack_90);
  if (*piVar7 == *(int *)(in_ECX + 0xd8)) {
    apuStack_98[0] = (undefined4 *)0x0;
  }
  else {
    apuStack_98[0] = *(undefined4 **)(*piVar7 + 0x28);
  }
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (apuStack_98[0] != (undefined4 *)0x0) {
    uStack_70 = *apuStack_98[0];
    uStack_6c = apuStack_98[0][1];
    uStack_68 = apuStack_98[0][2];
    uStack_74 = 1;
    FUN_0056ac60(apuStack_98,&uStack_74);
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  FUN_00401740(s_btn_down_009bd730,8);
  piVar7 = (int *)FUN_0069a470(apuStack_98,auStack_90);
  if (*piVar7 == *(int *)(in_ECX + 0xd8)) {
    apuStack_98[0] = (undefined4 *)0x0;
  }
  else {
    apuStack_98[0] = *(undefined4 **)(*piVar7 + 0x28);
  }
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (apuStack_98[0] != (undefined4 *)0x0) {
    uStack_70 = *apuStack_98[0];
    uStack_6c = apuStack_98[0][1];
    uStack_68 = apuStack_98[0][2];
    uStack_74 = 2;
    FUN_0056ac60(apuStack_98,&uStack_74);
  }
  uStack_24 = 0xf;
  uStack_8 = 0xf;
  uStack_28 = 0;
  uStack_38 = 0;
  uStack_c = 0;
  uStack_1c = 0;
  uStack_40 = 0;
  auStack_60[0] = 1;
  uStack_5c = 0xffffffff;
  iStack_54 = 100;
  uStack_58 = 3;
  piStack_4 = (int *)0x0;
  iVar4 = (**(code **)(*piVar1 + 0x10))();
  uStack_50 = *(undefined4 *)(in_ECX + 0xac);
  uStack_4c = *(undefined4 *)(in_ECX + 0xb0);
  iStack_54 = *(int *)(iVar4 + 4) + 2;
  uStack_48 = *(undefined4 *)(in_ECX + 0xb4);
  uStack_44 = *(undefined4 *)(in_ECX + 0xb8);
  piStack_4 = piVar1;
  uVar8 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__drop_btn_009bd73c);
  uVar8 = FUN_00402220(auStack_90,uVar8);
  FUN_00401660(uVar8,0,0xffffffff);
  if (uStack_78 < 0x10) {
    FUN_00576fa0(auStack_60,pvVar5,1);
    FUN_00505d80();
    _free(pvVar5);
    return;
  }
  _free(pvStack_8c);
  return;
}


// ==== FUN_00578700 @ 0x00578700 ====

void FUN_00578700(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x468);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = (void *)FUN_00505f10();
  }
  FUN_00577b40(pvVar1);
  if (pvVar1 == (void *)0x0) {
    return;
  }
  FUN_00505d80();
  _free(pvVar1);
  return;
}


// ==== FUN_00578750 @ 0x00578750 ====

void FUN_00578750(char param_1)

{
  void *_Memory;
  int in_ECX;
  undefined4 *puVar1;
  
  if (in_ECX != -0x8c) {
    puVar1 = *(undefined4 **)(in_ECX + 0xa0);
    if (puVar1 != *(undefined4 **)(in_ECX + 0xa4)) {
      do {
        _Memory = (void *)*puVar1;
        if (_Memory != (void *)0x0) {
          if (*(uint *)((int)_Memory + 0x20) < 0x10) {
            *(undefined4 *)((int)_Memory + 0x20) = 0xf;
            *(undefined4 *)((int)_Memory + 0x1c) = 0;
            *(undefined1 *)((int)_Memory + 0xc) = 0;
            _free(_Memory);
            return;
          }
          _free(*(void **)((int)_Memory + 0xc));
          return;
        }
        puVar1 = puVar1 + 1;
      } while (puVar1 != *(undefined4 **)(in_ECX + 0xa4));
    }
    if (*(void **)(in_ECX + 0xa0) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0xa0));
      return;
    }
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    *(undefined4 *)(in_ECX + 0xa4) = 0;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    if (param_1 != '\0') {
      FUN_00578700();
    }
  }
  return;
}


// ==== FUN_005787e0 @ 0x005787e0 ====

void FUN_005787e0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x70))();
  FUN_00578a60(*(undefined4 *)(*(int *)(in_ECX + 0xec) + 4));
  *(int *)(*(int *)(in_ECX + 0xec) + 4) = *(int *)(in_ECX + 0xec);
  *(undefined4 *)(in_ECX + 0xf0) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xec) = *(undefined4 *)(in_ECX + 0xec);
  *(int *)(*(int *)(in_ECX + 0xec) + 8) = *(int *)(in_ECX + 0xec);
  FUN_00578750(0);
  return;
}


// ==== FUN_00578830 @ 0x00578830 ====

undefined4 FUN_00578830(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  FUN_00578750(0);
  FUN_00579360(in_ECX + 0xd4);
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00578880 @ 0x00578880 ====

void FUN_00578880(int *param_1)

{
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    FUN_005787e0();
    in_ECX[0x20] = *param_1;
    in_ECX[0x21] = param_1[1];
    in_ECX[0x22] = param_1[2];
    FUN_005795e0(param_1 + 0x87);
    FUN_005781f0();
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_005788e0 @ 0x005788e0 ====

void FUN_005788e0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009bd7e4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    FUN_00578750(0);
    FUN_00579360(in_ECX + 0x35);
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00579060(local_4,*(undefined4 *)in_ECX[0x3b],(undefined4 *)in_ECX[0x3b]);
  _free((void *)in_ECX[0x3b]);
  return;
}


// ==== FUN_005789b0 @ 0x005789b0 ====

int FUN_005789b0(void *param_1,uint param_2,size_t param_3)

{
  uint uVar1;
  void *pvVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  char *pcVar5;
  
  if ((param_3 != 0) && (uVar1 = *(uint *)(in_ECX + 0x14), uVar1 != 0)) {
    if (uVar1 <= param_2) {
      param_2 = uVar1 - 1;
    }
    pcVar5 = (char *)(in_ECX + 4);
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      pcVar4 = pcVar5;
    }
    else {
      pcVar4 = *(char **)pcVar5;
    }
    pcVar4 = pcVar4 + param_2;
    pvVar2 = _memchr(param_1,(int)*pcVar4,param_3);
    while( true ) {
      if (pvVar2 != (void *)0x0) {
        if (0xf < *(uint *)(in_ECX + 0x18)) {
          pcVar5 = *(char **)pcVar5;
        }
        return (int)pcVar4 - (int)pcVar5;
      }
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        pcVar3 = pcVar5;
      }
      else {
        pcVar3 = *(char **)pcVar5;
      }
      if (pcVar4 == pcVar3) break;
      pcVar3 = pcVar4 + -1;
      pcVar4 = pcVar4 + -1;
      pvVar2 = _memchr(param_1,(int)*pcVar3,param_3);
    }
  }
  return -1;
}


// ==== FUN_00578a40 @ 0x00578a40 ====

void FUN_00578a40(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x2d) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x2d) == '\0');
  }
  return;
}


// ==== FUN_00578a60 @ 0x00578a60 ====

void FUN_00578a60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00578a60(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00578aa0 @ 0x00578aa0 ====

void * FUN_00578aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009820c0;
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


// ==== Catch@00578b15 @ 0x00578b15 ====

void Catch_00578b15(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00578b30 @ 0x00578b30 ====

void FUN_00578b30(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009820d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xb) = 1;
  *(undefined1 *)((int)puVar1 + 0x2d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@00578bba @ 0x00578bba ====

void Catch_00578bba(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00578bd0 @ 0x00578bd0 ====

void FUN_00578bd0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009820e0;
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


// ==== Catch@00578c5a @ 0x00578c5a ====

void Catch_00578c5a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00578c70 @ 0x00578c70 ====

uint FUN_00578c70(int param_1,int param_2,byte param_3)

{
  uint extraout_EAX;
  
  if (param_1 == param_2) {
    return (uint)param_3;
  }
  _free(*(void **)(param_1 + 0x28));
  return extraout_EAX;
}


// ==== FUN_00578ce0 @ 0x00578ce0 ====

void FUN_00578ce0(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x58)) {
    _free(*(void **)(in_ECX + 0x44));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0xf;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(uint *)(in_ECX + 0x3c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0xf;
    *(undefined1 *)(in_ECX + 0x28) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x28));
  return;
}


// ==== FUN_00578d30 @ 0x00578d30 ====

void FUN_00578d30(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00578aa0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00578e35:
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
      if ((char)piVar6[5] == '\0') goto LAB_00578e35;
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


// ==== FUN_00578f10 @ 0x00578f10 ====

void FUN_00578f10(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00578d30(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00578d30(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00578fd0 @ 0x00578fd0 ====

void * FUN_00578fd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009820f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004bbcf0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00579045 @ 0x00579045 ====

void Catch_00579045(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00579060 @ 0x00579060 ====

void FUN_00579060(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00578a60(piVar6[1]);
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


// ==== FUN_00579120 @ 0x00579120 ====

void FUN_00579120(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_00579120(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x24) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x24) = 0xf;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined1 *)((int)param_1 + 0x10) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x10));
  return;
}


// ==== FUN_00579180 @ 0x00579180 ====

void FUN_00579180(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x7fffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00578fd0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x2c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x2c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xb] == '\0') {
LAB_00579285:
        *(undefined1 *)(*piVar5 + 0x2c) = 1;
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x2c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004eb7a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x2c) = 0;
        FUN_005a3430(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xb] == '\0') goto LAB_00579285;
      if (piVar7 == (int *)*piVar2) {
        FUN_005a3430(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x2c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x2d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x2c);
  } while( true );
}


// ==== FUN_00579360 @ 0x00579360 ====

void FUN_00579360(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    puVar1 = (undefined4 *)(param_1 + 4);
    param_1 = param_1 & 0xffffff00;
    FUN_00578c70(*(undefined4 *)*puVar1,(undefined4 *)*puVar1,param_1);
    FUN_00579120(*(undefined4 *)(*(int *)(uVar2 + 4) + 4));
    *(int *)(*(int *)(uVar2 + 4) + 4) = *(int *)(uVar2 + 4);
    *(undefined4 *)(uVar2 + 8) = 0;
    *(undefined4 *)*(undefined4 *)(uVar2 + 4) = *(undefined4 *)(uVar2 + 4);
    *(int *)(*(int *)(uVar2 + 4) + 8) = *(int *)(uVar2 + 4);
  }
  return;
}


// ==== FUN_005793b0 @ 0x005793b0 ====

/* WARNING: Removing unreachable block (ram,0x0057940f) */

void FUN_005793b0(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x2d) == '\0') {
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
LAB_00579440:
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
        if (uVar5 == 0) goto LAB_00579440;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x2d) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_00579180(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0079c420();
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
    puVar6 = (undefined4 *)FUN_00579180(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_005795e0 @ 0x005795e0 ====

void FUN_005795e0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  FUN_005ddad0(param_1 + 4);
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  in_ECX[0xf] = param_1[0xf];
  return;
}


// ==== FUN_00579650 @ 0x00579650 ====

void FUN_00579650(byte param_1)

{
  void *in_ECX;
  
  FUN_005788e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00579670 @ 0x00579670 ====

void FUN_00579670(int param_1)

{
  int *in_ECX;
  
  in_ECX[0x1c] = *(int *)(param_1 + 0x20c);
  in_ECX[0x1d] = *(int *)(param_1 + 0x210);
  in_ECX[0x1e] = *(int *)(param_1 + 0x214);
  in_ECX[0x1f] = *(int *)(param_1 + 0x218);
                    /* WARNING: Could not recover jumptable at 0x0057969d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_005796a0 @ 0x005796a0 ====

undefined1 FUN_005796a0(void)

{
  return 0;
}


// ==== FUN_005796b0 @ 0x005796b0 ====

int FUN_005796b0(void)

{
  int in_ECX;
  
  return (int)*(float *)(in_ECX + 0x8c);
}


// ==== FUN_005796c0 @ 0x005796c0 ====

float10 FUN_005796c0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x8c);
}


// ==== FUN_005796d0 @ 0x005796d0 ====

float10 FUN_005796d0(void)

{
  int in_ECX;
  
  return ((float10)*(float *)(in_ECX + 0x8c) / (float10)*(int *)(in_ECX + 0x74)) *
         (float10)DAT_0099de78;
}


// ==== FUN_005796e0 @ 0x005796e0 ====

void FUN_005796e0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00579700 @ 0x00579700 ====

undefined4 FUN_00579700(void)

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


// ==== FUN_00579730 @ 0x00579730 ====

void FUN_00579730(undefined1 *param_1)

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


// ==== FUN_00579800 @ 0x00579800 ====

void FUN_00579800(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd8b4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00552170();
  return;
}


// ==== FUN_00579830 @ 0x00579830 ====

void FUN_00579830(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd8b4;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x24] = 0;
  return;
}


// ==== FUN_00579890 @ 0x00579890 ====

undefined4 FUN_00579890(int param_1)

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


// ==== FUN_00579990 @ 0x00579990 ====

undefined4 FUN_00579990(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__minus_009bd8a0);
  FUN_00402220(param_1,uVar1);
  return param_1;
}


// ==== FUN_005799c0 @ 0x005799c0 ====

void FUN_005799c0(float param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  uint uStack_40;
  undefined1 auStack_3c [8];
  int iStack_34;
  int iStack_2c;
  void *pvStack_1c;
  uint uStack_8;
  
  if ((float)in_ECX[0x23] == param_1) {
    return;
  }
  if (in_ECX[0x24] == 0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&DAT_009bd890);
    FUN_00402220(auStack_58,uVar2);
    iVar3 = (**(code **)(*piVar1 + 0x4c))(auStack_58);
    in_ECX[0x24] = iVar3;
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return;
    }
  }
  if ((int *)in_ECX[0x24] == (int *)0x0) {
    return;
  }
  if (param_1 <= (float)in_ECX[0x1d]) {
    if ((float)in_ECX[0x1c] <= param_1) {
      in_ECX[0x23] = (int)param_1;
    }
    else {
      in_ECX[0x23] = (int)(float)in_ECX[0x1c];
    }
  }
  else {
    in_ECX[0x23] = (int)(float)in_ECX[0x1d];
  }
  uVar2 = (**(code **)(*(int *)in_ECX[0x24] + 0x10))();
  FUN_005041e0(uVar2);
  iStack_2c = iStack_2c - iStack_34;
  iVar3 = in_ECX[0x1e];
  iStack_34 = in_ECX[0x1f] - iStack_2c;
  iVar4 = (int)(((float)((in_ECX[0x1f] - iVar3) - iStack_2c) / (float)(in_ECX[0x1d] - in_ECX[0x1c]))
               * (float)in_ECX[0x23]) + iVar3;
  if ((iVar4 < iStack_34) && (iStack_34 = iVar4, iVar4 <= iVar3)) {
    iStack_34 = iVar3;
  }
  iStack_2c = iStack_34 + iStack_2c;
  (**(code **)(*(int *)in_ECX[0x24] + 0xc))(auStack_3c);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00579b10 @ 0x00579b10 ====

void FUN_00579b10(float param_1)

{
  int in_ECX;
  
  FUN_005799c0((float)*(int *)(in_ECX + 0x74) * param_1 * DAT_009a09b8);
  return;
}


// ==== FUN_00579b40 @ 0x00579b40 ====

void FUN_00579b40(int param_1)

{
  FUN_005799c0((float)param_1);
  return;
}


// ==== FUN_00579b70 @ 0x00579b70 ====

undefined4 FUN_00579b70(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 extraout_EAX_00;
  undefined4 ******ppppppuVar5;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  int iVar6;
  undefined4 ******appppppuStack_28 [2];
  int iStack_20;
  undefined4 uStack_14;
  uint uStack_10;
  
  if (param_1 == 0) {
    if (param_3 == 7) {
      uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&DAT_009bd890);
      FUN_00402220(appppppuStack_28,uVar1);
      ppppppuVar5 = appppppuStack_28[1];
      if (uStack_10 < 0x10) {
        ppppppuVar5 = appppppuStack_28 + 1;
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppppuVar5,uStack_14);
      if (0xf < uStack_10) {
        _free(appppppuStack_28[1]);
        return extraout_EAX;
      }
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
        iVar2 = in_ECX[0x1d];
        ppppppuVar5 = appppppuStack_28;
        for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *ppppppuVar5 = (undefined4 *****)*puVar3;
          puVar3 = puVar3 + 1;
          ppppppuVar5 = ppppppuVar5 + 1;
        }
        FUN_005799c0(((float)(int)((param_4 >> 0x10) - iStack_20) /
                     (float)(in_ECX[0x1f] - in_ECX[0x1e])) * (float)(iVar2 - in_ECX[0x1c]));
        piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
        goto LAB_00579dde;
      }
    }
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__plus_009bd898);
      FUN_00402220(appppppuStack_28,uVar1);
      ppppppuVar5 = appppppuStack_28[1];
      if (uStack_10 < 0x10) {
        ppppppuVar5 = appppppuStack_28 + 1;
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppppuVar5,uStack_14);
      if (0xf < uStack_10) {
        _free(appppppuStack_28[1]);
        return extraout_EAX_00;
      }
      if (iVar2 != 0) {
        uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__minus_009bd8a0);
        FUN_00402220(appppppuStack_28,uVar1);
        FUN_00423420(param_2,appppppuStack_28);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      if (param_3 != 0) {
        return 0;
      }
      uVar1 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__plus_009bd898);
      FUN_00402220(appppppuStack_28,uVar1);
      ppppppuVar5 = appppppuStack_28[1];
      if (uStack_10 < 0x10) {
        ppppppuVar5 = appppppuStack_28 + 1;
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppppuVar5,uStack_14);
      if (0xf < uStack_10) {
        _free(appppppuStack_28[1]);
        return extraout_EAX_01;
      }
      if (iVar2 != 0) {
        uVar1 = FUN_00579990(appppppuStack_28);
        FUN_00423420(param_2,uVar1);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    FUN_005799c0((float)in_ECX[0x23] + DAT_0099d080);
    piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
LAB_00579dde:
    (**(code **)(*piVar4 + 0x80))(7,0);
    return 1;
  }
  return 0;
}


// ==== FUN_00579e10 @ 0x00579e10 ====

void FUN_00579e10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd8b4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00552170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00579e80 @ 0x00579e80 ====

undefined4 FUN_00579e80(void)

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


// ==== FUN_00579eb0 @ 0x00579eb0 ====

void FUN_00579eb0(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0x78);
    local_8 = *(undefined4 *)(in_ECX + 0x7c);
    local_4 = *(undefined4 *)(in_ECX + 0x80);
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


// ==== FUN_00579f80 @ 0x00579f80 ====

void FUN_00579f80(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),&DAT_009bd960,0), iVar1 != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_00579fc0 @ 0x00579fc0 ====

void FUN_00579fc0(int *param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = param_1;
  if (in_ECX[0x1d] != *param_1) {
    FUN_00558e00(&param_1,param_1);
    if (param_1 != (int *)in_ECX[0x32]) {
      in_ECX[0x1e] = param_1[4];
      in_ECX[0x1f] = param_1[5];
      in_ECX[0x20] = param_1[6];
      (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    }
    FUN_00557be0(&param_1,piVar1);
    if (param_1 != (int *)in_ECX[0x2f]) {
      in_ECX[0x2b] = param_1[0xe];
      in_ECX[0x2a] = param_1[0xd];
      *(undefined1 *)(in_ECX + 0x2d) = *(undefined1 *)((int)in_ECX + 0xf9);
      (**(code **)(*in_ECX + 8))(in_ECX + 0x21);
    }
    in_ECX[0x1d] = *piVar1;
  }
  return;
}


// ==== FUN_0057a070 @ 0x0057a070 ====

void FUN_0057a070(int *param_1)

{
  int *piVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  int aiStack_28 [4];
  int iStack_18;
  int iStack_14;
  
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  piVar3 = aiStack_28;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *piVar1;
    piVar1 = piVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  if ((((*param_1 < aiStack_28[2]) || (param_1[1] < aiStack_28[3])) || (iStack_18 <= *param_1)) ||
     (iStack_14 <= param_1[1])) {
    *(undefined1 *)((int)in_ECX + 0x71) = 0;
    param_1 = (int *)0x0;
  }
  else {
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    param_1 = (int *)0x1;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(1,0);
  }
  if (*(char *)((int)in_ECX + 0x72) == '\0') {
    FUN_00579fc0(&param_1);
  }
  return;
}


// ==== FUN_0057a100 @ 0x0057a100 ====

void FUN_0057a100(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 uStack_c;
  
  if ((*(char *)((int)in_ECX + 0x72) == '\0') && ((char)in_ECX[0x3e] != '\x02')) {
    *(undefined1 *)(in_ECX + 0x1c) = 1;
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    uStack_c = 0x57a128;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uStack_c = 0;
    (**(code **)(*piVar1 + 0x80))(1);
    FUN_00579fc0(&uStack_c);
  }
  return;
}


// ==== FUN_0057a150 @ 0x0057a150 ====

void FUN_0057a150(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 uStack_c;
  
  if ((*(char *)((int)in_ECX + 0x72) == '\0') && ((char)in_ECX[0x3e] != '\x02')) {
    *(undefined1 *)(in_ECX + 0x1c) = 1;
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    uStack_c = 0x57a178;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uStack_c = 0;
    (**(code **)(*piVar1 + 0x80))(2);
    FUN_00579fc0(&uStack_c);
  }
  return;
}


// ==== FUN_0057a1a0 @ 0x0057a1a0 ====

void FUN_0057a1a0(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 local_4;
  
  if ((*(char *)((int)in_ECX + 0x72) == '\0') && ((char)in_ECX[0x3e] != '\x02')) {
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    local_4 = 1;
    *(undefined1 *)(in_ECX + 0x1c) = 0;
    FUN_00579fc0(&local_4);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(4,0);
  }
  return;
}


// ==== FUN_0057a1f0 @ 0x0057a1f0 ====

void FUN_0057a1f0(void)

{
  int in_ECX;
  undefined4 local_4;
  
  if ((*(char *)(in_ECX + 0x72) == '\0') && (*(char *)(in_ECX + 0xf8) != '\x02')) {
    *(undefined1 *)(in_ECX + 0x70) = 0;
    *(undefined1 *)(in_ECX + 0x71) = 0;
    local_4 = 0;
    FUN_00579fc0(&local_4);
  }
  return;
}


// ==== FUN_0057a220 @ 0x0057a220 ====

void FUN_0057a220(char param_1)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0x45) = param_1;
  if (param_1 == '\0') {
    _param_1 = 3;
    FUN_00579fc0(&param_1);
    return;
  }
  _param_1 = 0;
  FUN_00579fc0(&param_1);
  return;
}


// ==== FUN_0057a260 @ 0x0057a260 ====

undefined4 FUN_0057a260(int param_1,undefined4 param_2,int param_3)

{
  if (param_1 != 0) {
    return 0;
  }
  if (param_3 == 1) {
    FUN_0057a100();
    return 1;
  }
  if (param_3 == 4) {
    FUN_0057a1a0();
    return 1;
  }
  if (param_3 == 5) {
    FUN_0057a1f0();
    return 1;
  }
  if (param_3 == 2) {
    FUN_0057a150();
  }
  return 1;
}


// ==== FUN_0057a2b0 @ 0x0057a2b0 ====

undefined4 FUN_0057a2b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    switch(param_1[2] + -1) {
    case 0:
      FUN_0057a100();
      return 1;
    case 2:
      FUN_0057a150();
      return 1;
    case 6:
      FUN_0057a1a0();
      return 1;
    case 7:
      FUN_0057a1f0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0057a350 @ 0x0057a350 ====

undefined4 FUN_0057a350(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 != iVar1) {
    return 0;
  }
  if ((param_1[2] == 1) && (param_1[6] == 1)) {
    FUN_0057a070(param_1 + 0xe);
  }
  return 1;
}


// ==== FUN_0057a3a0 @ 0x0057a3a0 ====

undefined4 FUN_0057a3a0(int param_1)

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


// ==== FUN_0057a440 @ 0x0057a440 ====

undefined4 FUN_0057a440(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0) || (*(char *)(in_ECX + 0x45) == '\0')) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_0057a2b0(param_1);
  }
  else {
    if (iVar2 != 0x10003) {
      return 0;
    }
    cVar1 = FUN_0057a350(param_1);
  }
  if (cVar1 == '\0') {
    return 0;
  }
  return 1;
}


// ==== FUN_0057a4a0 @ 0x0057a4a0 ====

void FUN_0057a4a0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_8;
  uint uStack_4;
  
  if (in_ECX[0x43] == 0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar2 = (**(code **)(*piVar1 + 0x50))(s__emoti_009bd964);
    FUN_00402220(&pvStack_1c,uVar2);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&pvStack_1c);
    if (piVar1 == (int *)0x0) {
      if (uStack_8 < 0x10) {
        return;
      }
      _free(pvStack_1c);
      return;
    }
    uVar2 = (**(code **)(*piVar1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Panel::RTTI_Type_Descriptor,0);
    iVar3 = FUN_00803725(uVar2);
    in_ECX[0x43] = iVar3;
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  FUN_00401660(param_1,0,0xffffffff);
  if (in_ECX[0x43] != 0) {
    FUN_00401660(in_ECX + 9,0,0xffffffff);
  }
  return;
}


// ==== FUN_0057a570 @ 0x0057a570 ====

void FUN_0057a570(void)

{
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd97c;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)((int)in_ECX + 0x71) = 0;
  *(undefined1 *)((int)in_ECX + 0x72) = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x29] = 0xf;
  in_ECX[0x28] = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  in_ECX[0x2a] = 1;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 1;
  *(undefined1 *)(in_ECX + 0x2d) = 0;
  *(undefined1 *)((int)in_ECX + 0xb5) = 0;
  FUN_00505a60();
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x43] = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_0057a610 @ 0x0057a610 ====

void FUN_0057a610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd97c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00505af0();
  if ((uint)in_ECX[0x29] < 0x10) {
    in_ECX[0x28] = 0;
    in_ECX[0x29] = 0xf;
    *(undefined1 *)(in_ECX + 0x24) = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x24]);
  return;
}


// ==== FUN_0057a680 @ 0x0057a680 ====

void FUN_0057a680(int param_1)

{
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_00505cc0(param_1 + 0xc4);
  param_1 = 0;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 == (int *)in_ECX[0x32]) {
    in_ECX[0x1e] = 0;
  }
  else {
    in_ECX[0x1e] = local_4[4];
    in_ECX[0x1f] = local_4[5];
    in_ECX[0x20] = local_4[6];
  }
  FUN_00557be0(&local_4,&param_1);
  if (local_4 != (int *)in_ECX[0x2f]) {
    FUN_005523f0(local_4 + 4);
  }
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_0057a730 @ 0x0057a730 ====

void FUN_0057a730(byte param_1)

{
  void *in_ECX;
  
  FUN_0057a610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0057a750 @ 0x0057a750 ====

void FUN_0057a750(void)

{
  int *in_ECX;
  int *piStack00000004;
  
  piStack00000004 = in_ECX + 0x12;
                    /* WARNING: Could not recover jumptable at 0x0057a759. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_0057a760 @ 0x0057a760 ====

undefined4 FUN_0057a760(void)

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


// ==== FUN_0057a790 @ 0x0057a790 ====

void FUN_0057a790(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0x90);
    local_8 = *(undefined4 *)(in_ECX + 0x94);
    local_4 = *(undefined4 *)(in_ECX + 0x98);
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


// ==== FUN_0057a860 @ 0x0057a860 ====

void FUN_0057a860(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  *(undefined1 *)(in_ECX + 0x1c) = 1;
  in_ECX[0x27] = *param_1;
  in_ECX[0x28] = param_1[1];
  in_ECX[0x29] = param_1[2];
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar1 = *piVar3;
  uVar4 = (**(code **)(*piVar2 + 0x50))(s__skill_009bda2c);
  uVar4 = FUN_00402220(&uStack_1c,uVar4);
  piVar2 = (int *)(**(code **)(iVar1 + 0x4c))(uVar4);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar4 = (**(code **)(*piVar2 + 0x50))(&DAT_009bda34);
    uVar4 = FUN_00402220((int)register0x00000010 + -0x20,uVar4);
    FUN_00796d50(uVar4);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
  }
  else {
    (**(code **)(*piVar2 + 0x24))(1);
    (**(code **)(*piVar2 + 0x30))();
    FUN_00587d40(in_ECX + 0x27);
  }
  return;
}


// ==== FUN_0057a960 @ 0x0057a960 ====

void FUN_0057a960(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_38 [8];
  uint auStack_30 [3];
  int iStack_24;
  undefined1 auStack_20 [4];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_cooltime_009bda48,8);
  (**(code **)(*DAT_00b5a7c0 + 8))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  FUN_0056a6d0();
  uVar2 = 0;
  do {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_newMainbar_009bda54,10);
    uVar1 = (**(code **)(*DAT_00b5a7c0 + 8))(auStack_20);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    iStack_24 = uVar2 + 0x79;
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    auStack_30[1] = 0;
    auStack_30[0] = uVar2;
    auStack_30[2] = uVar1;
    FUN_0056ac60(auStack_38,auStack_30);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  return;
}


// ==== FUN_0057aa60 @ 0x0057aa60 ====

void FUN_0057aa60(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  if (((char)in_ECX[0x1c] != '\0') && ((char)in_ECX[0x37] != '\x02')) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar1 = *piVar3;
    uVar4 = (**(code **)(*piVar2 + 0x50))(s__cool_009bda60);
    uVar4 = FUN_00402220(&uStack_1c,uVar4);
    piVar2 = (int *)(**(code **)(iVar1 + 0x4c))(uVar4);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar4 = (**(code **)(*piVar2 + 0x50))(&DAT_009bda68);
      uVar4 = FUN_00402220((int)register0x00000010 + -0x20,uVar4);
      FUN_00796d50(uVar4);
      if (0xf < uStack_8) {
        _free(uStack_1c);
        return;
      }
    }
    else {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        uVar4 = (**(code **)(*piVar2 + 4))();
        *puVar5 = &PTR_FUN_009bba08;
        puVar5[1] = uVar4;
        puVar5[3] = 1;
        puVar5[5] = 0;
        *(undefined1 *)(puVar5 + 6) = 0;
      }
      *(undefined1 *)((int)puVar5 + 0x19) = 1;
      puVar5[5] = unaff_retaddr;
      puVar5[4] = param_1;
      *(undefined1 *)(puVar5 + 6) = 1;
      puVar5[2] = 8;
      (**(code **)(*DAT_00b5ad24 + 4))(puVar5);
      (**(code **)*puVar5)(1);
      *(undefined1 *)(in_ECX + 0x37) = 2;
    }
  }
  return;
}


// ==== FUN_0057abb0 @ 0x0057abb0 ====

void FUN_0057abb0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *in_ECX;
  void *pvStack_20;
  void *apvStack_1c [3];
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  if ((char)in_ECX[0x37] != '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    pvStack_20 = (void *)*piVar3;
    uVar4 = (**(code **)(*piVar2 + 0x50))(s__cool_009bda9c);
    uVar4 = FUN_00402220(apvStack_1c,uVar4);
    piVar2 = (int *)(**(code **)((int)pvStack_20 + 0x4c))(uVar4);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        uVar4 = (**(code **)(*piVar2 + 4))();
        *puVar5 = &PTR_FUN_009bba08;
        puVar5[1] = uVar4;
        puVar5[3] = 1;
        puVar5[5] = 0;
        *(undefined1 *)(puVar5 + 6) = 0;
      }
      *(undefined1 *)((int)puVar5 + 0x19) = 0;
      FUN_00797a20(puVar5);
    }
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar1 = *piVar3;
    uVar4 = (**(code **)(*piVar2 + 0x50))(s__skill_009bdaa4);
    uVar4 = FUN_00402220(&pvStack_20,uVar4);
    piVar2 = (int *)(**(code **)(iVar1 + 0x4c))(uVar4);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        uVar4 = (**(code **)(*piVar2 + 4))();
        *puVar5 = &PTR_FUN_009bba08;
        puVar5[1] = uVar4;
        puVar5[3] = 1;
        puVar5[5] = 0;
        *(undefined1 *)(puVar5 + 6) = 0;
      }
      *(undefined1 *)((int)puVar5 + 0x19) = 0;
      FUN_00797a20(puVar5);
    }
    *(undefined1 *)(in_ECX + 0x37) = 0;
  }
  return;
}


// ==== FUN_0057ad20 @ 0x0057ad20 ====

void FUN_0057ad20(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *in_ECX;
  int iStack_20;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  if (((char)in_ECX[0x37] != '\x01') && ((char)in_ECX[0x1c] != '\0')) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iStack_20 = *piVar2;
    uVar3 = (**(code **)(*piVar1 + 0x50))(s__cool_009bdaac);
    uVar3 = FUN_00402220(apvStack_1c,uVar3);
    piVar1 = (int *)(**(code **)(iStack_20 + 0x4c))(uVar3);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar3 = (**(code **)(*piVar1 + 0x50))(&DAT_009bdab4);
      uVar3 = FUN_00402220(&iStack_20,uVar3);
      FUN_00796d50(uVar3);
      if (0xf < uStack_8) {
        _free(apvStack_1c[0]);
        return;
      }
    }
    else {
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        uVar3 = (**(code **)(*piVar1 + 4))();
        *puVar4 = &PTR_FUN_009bba08;
        puVar4[1] = uVar3;
        puVar4[3] = 1;
        puVar4[5] = 0;
        *(undefined1 *)(puVar4 + 6) = 0;
      }
      *(undefined1 *)((int)puVar4 + 0x19) = 1;
      puVar4[4] = 2000;
      puVar4[2] = 8;
      puVar4[3] = 2;
      FUN_00797a20(puVar4);
      *(undefined1 *)(in_ECX + 0x37) = 1;
    }
  }
  return;
}


// ==== FUN_0057ae50 @ 0x0057ae50 ====

void FUN_0057ae50(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  int iStack_4;
  
  piVar1 = in_ECX + 9;
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = *piVar4;
  uVar5 = (**(code **)(*piVar3 + 0x50))(s__cool_009bdae4);
  uVar5 = FUN_00402220(&uStack_1c,uVar5);
  piVar3 = (int *)(**(code **)(iVar2 + 0x4c))(uVar5);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar3 + 0x30))();
  FUN_00401660(piVar1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = *piVar4;
  uVar5 = (**(code **)(*piVar3 + 0x50))(&DAT_009bdaec);
  uVar5 = FUN_00402220((int)register0x00000010 + -0x20,uVar5);
  piVar3 = (int *)(**(code **)(iVar2 + 0x4c))(uVar5);
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00401660(piVar1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iStack_4 = *piVar4;
  uVar5 = (**(code **)(*piVar3 + 0x50))(s__skill_009bdaf4);
  uVar5 = FUN_00402220((int)register0x00000010 + -0x24,uVar5);
  piVar3 = (int *)(**(code **)(iStack_4 + 0x4c))(uVar5);
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    (**(code **)(*piVar3 + 0x30))();
    FUN_00401660(piVar1,0,0xffffffff);
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_0057aff0 @ 0x0057aff0 ====

undefined4 FUN_0057aff0(int param_1)

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
        *(undefined4 *)(in_ECX + 0x90) = 0;
        *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(in_ECX + 0x90);
        *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(in_ECX + 0x94);
        *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(in_ECX + 0x98);
        FUN_0057a960();
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_0057b0c0 @ 0x0057b0c0 ====

void FUN_0057b0c0(char param_1)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0x71) = param_1;
  if (param_1 == '\x01') {
    *(undefined4 *)(in_ECX + 0x74) = 3;
    FUN_0057ad20();
    return;
  }
  *(undefined4 *)(in_ECX + 0x74) = 0;
  FUN_0057abb0();
  return;
}


// ==== FUN_0057b0f0 @ 0x0057b0f0 ====

void FUN_0057b0f0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar1 = *piVar3;
  uVar4 = (**(code **)(*piVar2 + 0x50))(&DAT_009bda7c);
  uVar4 = FUN_00402220(&uStack_1c,uVar4);
  piVar2 = (int *)(**(code **)(iVar1 + 0x4c))(uVar4);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar4 = (**(code **)(*piVar2 + 0x50))(&DAT_009bda84);
    uVar4 = FUN_00402220((int)register0x00000010 + -0x20,uVar4);
    FUN_00796d50(uVar4);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
  }
  else {
    (**(code **)(*piVar2 + 0x24))((char)in_ECX[0x1c]);
    if ((char)in_ECX[0x1c] == '\x01') {
      (**(code **)(*piVar2 + 0x30))();
      uVar4 = FUN_0056f1d0(in_ECX + 0x1d);
      FUN_00587d40(uVar4);
      FUN_00401660(in_ECX + 9,0,0xffffffff);
    }
  }
  return;
}


// ==== FUN_0057b1f0 @ 0x0057b1f0 ====

void FUN_0057b1f0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  if (((char)in_ECX[0x37] != '\x01') && ((char)in_ECX[0x37] != '\0')) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar1 = *piVar3;
    uVar4 = (**(code **)(*piVar2 + 0x50))(s__skill_009bda94);
    uVar4 = FUN_00402220(apvStack_1c,uVar4);
    piVar2 = (int *)(**(code **)(iVar1 + 0x4c))(uVar4);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        uVar4 = (**(code **)(*piVar2 + 4))();
        *puVar5 = &PTR_FUN_009bba08;
        puVar5[1] = uVar4;
        puVar5[3] = 1;
        puVar5[5] = 0;
        *(undefined1 *)(puVar5 + 6) = 0;
      }
      *(undefined1 *)((int)puVar5 + 0x19) = 1;
      puVar5[4] = 600;
      puVar5[2] = 9;
      *(undefined1 *)(puVar5 + 6) = 1;
      FUN_00797a20(puVar5);
    }
    if (*(char *)((int)in_ECX + 0x71) == '\x01') {
      FUN_0057ad20();
    }
    *(undefined1 *)(in_ECX + 0x37) = 1;
  }
  return;
}


// ==== FUN_0057b2f0 @ 0x0057b2f0 ====

void FUN_0057b2f0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  int iStack_20;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  in_ECX[0x27] = 0xffffff;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iStack_20 = *piVar2;
  uVar3 = (**(code **)(*piVar1 + 0x50))(s__skill_009bdac8);
  uVar3 = FUN_00402220(apvStack_1c,uVar3);
  piVar1 = (int *)(**(code **)(iStack_20 + 0x4c))(uVar3);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar3 = (**(code **)(*piVar1 + 0x50))(&DAT_009bdad0);
    uVar3 = FUN_00402220(&iStack_20,uVar3);
    FUN_00796d50(uVar3);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
  }
  else {
    (**(code **)(*piVar1 + 0x30))();
    FUN_00587d40(in_ECX + 0x27);
    (**(code **)(*piVar1 + 0x24))(0);
    FUN_0057b0f0();
    FUN_0057abb0();
  }
  return;
}


// ==== FUN_0057b400 @ 0x0057b400 ====

void FUN_0057b400(void)

{
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bdb0c;
  FUN_00505150();
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0xf;
  *(undefined1 *)(in_ECX + 0x2d) = 0;
  in_ECX[0x34] = 0;
  *(undefined1 *)(in_ECX + 0x36) = 0;
  *(undefined1 *)((int)in_ECX + 0xd9) = 0;
  in_ECX[0x33] = 1;
  in_ECX[0x35] = 1;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)((int)in_ECX + 0x71) = 0;
  in_ECX[0x1d] = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  return;
}


// ==== FUN_0057b4c0 @ 0x0057b4c0 ====

void FUN_0057b4c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bdb0c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  if ((uint)in_ECX[0x32] < 0x10) {
    in_ECX[0x32] = 0xf;
    in_ECX[0x31] = 0;
    *(undefined1 *)(in_ECX + 0x2d) = 0;
    FUN_005051b0();
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x2d]);
  return;
}


// ==== FUN_0057b530 @ 0x0057b530 ====

void FUN_0057b530(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  in_ECX[0x1d] = (-(uint)(*(char *)((int)in_ECX + 0x71) != '\x01') & 0xfffffffd) + 4;
  FUN_0057b0f0();
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(4,param_1);
  return;
}


// ==== FUN_0057b570 @ 0x0057b570 ====

void FUN_0057b570(void)

{
  int *piVar1;
  int *in_ECX;
  
  in_ECX[0x1d] = (-(uint)(*(char *)((int)in_ECX + 0x71) != '\x01') & 0xfffffffd) + 3;
  FUN_0057b0f0();
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(5,0);
  return;
}


// ==== FUN_0057b5a0 @ 0x0057b5a0 ====

void FUN_0057b5a0(void)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x74) = (-(uint)(*(char *)(in_ECX + 0x71) != '\x01') & 0xfffffffd) + 5;
  FUN_0057b0f0();
  return;
}


// ==== FUN_0057b5c0 @ 0x0057b5c0 ====

void FUN_0057b5c0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(1,0);
  in_ECX[0x1d] = (-(uint)(*(char *)((int)in_ECX + 0x71) != '\x01') & 0xfffffffd) + 3;
  FUN_0057b0f0();
  return;
}


// ==== FUN_0057b5f0 @ 0x0057b5f0 ====

void FUN_0057b5f0(void)

{
  int *piVar1;
  int *in_ECX;
  
  in_ECX[0x1d] = (-(uint)(*(char *)((int)in_ECX + 0x71) != '\x01') & 0xfffffffd) + 5;
  FUN_0057b0f0();
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(2,0);
  return;
}


// ==== FUN_0057b620 @ 0x0057b620 ====

undefined4 FUN_0057b620(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *in_ECX;
  
  if (param_1 != 0) {
    return 0;
  }
  if (param_3 == 1) {
    in_ECX[0x1d] = (-(uint)(*(char *)((int)in_ECX + 0x71) != '\x01') & 0xfffffffd) + 5;
    FUN_0057b0f0();
    return 1;
  }
  if (param_3 == 3) {
    FUN_0057b5c0();
    return 1;
  }
  if (param_3 == 4) {
    FUN_0057b530(param_4);
    return 1;
  }
  if (param_3 == 5) {
    FUN_0057b570();
    return 1;
  }
  if (param_3 == 2) {
    FUN_0057b5f0();
    return 1;
  }
  if (param_3 == 10) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(10,0);
  }
  return 1;
}


// ==== FUN_0057b6c0 @ 0x0057b6c0 ====

undefined4 FUN_0057b6c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    if (param_1[2] == 0) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(0xb,0);
      return 1;
    }
    if (param_1[2] == 1) {
      if (param_1[6] == 1) {
        FUN_0057b5c0();
      }
      iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
      if (param_1[0xb] == iVar1) {
        piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
        (**(code **)(*piVar3 + 0x80))(10,0);
        return 1;
      }
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(10,1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0057b770 @ 0x0057b770 ====

undefined4 FUN_0057b770(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    switch(param_1[2] + -1) {
    case 0:
      FUN_0057b5a0();
      return 1;
    case 1:
      FUN_0057b5c0();
      return 1;
    case 2:
      FUN_0057b5f0();
      return 1;
    case 6:
      FUN_0057b530(0);
      return 1;
    case 7:
      FUN_0057b570();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0057b820 @ 0x0057b820 ====

undefined4 FUN_0057b820(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_0057b770(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_0057b6c0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0057b880 @ 0x0057b880 ====

void FUN_0057b880(byte param_1)

{
  void *in_ECX;
  
  FUN_0057b4c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0057b8a0 @ 0x0057b8a0 ====

uint FUN_0057b8a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  uVar2 = (**(code **)(*param_1 + 0x10))();
  if (uVar2 == uVar1) {
    uVar2 = 0;
    switch(param_1[2]) {
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
      return 1;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_0057b940 @ 0x0057b940 ====

void FUN_0057b940(int *param_1)

{
  int *in_ECX;
  
  in_ECX[0x1f] = *param_1;
  in_ECX[0x20] = param_1[1];
  in_ECX[0x21] = param_1[2];
                    /* WARNING: Could not recover jumptable at 0x0057b962. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_0057b970 @ 0x0057b970 ====

undefined4 FUN_0057b970(void)

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


// ==== FUN_0057b9a0 @ 0x0057b9a0 ====

undefined4 FUN_0057b9a0(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar2 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar2 != '\0')) {
    return 1;
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x10001) {
    cVar2 = FUN_0057b8a0(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if (iVar3 == 0x10003) {
    piVar1 = *(int **)(in_ECX + 4);
    iVar3 = (**(code **)(*param_1 + 0x10))();
    iVar4 = (**(code **)(*piVar1 + 4))();
    if (((iVar3 == iVar4) && (param_1[2] == 1)) && (param_1[6] == 1)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0057ba20 @ 0x0057ba20 ====

void FUN_0057ba20(undefined1 *param_1)

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
    local_c = *(undefined4 *)(in_ECX + 0x7c);
    local_8 = *(undefined4 *)(in_ECX + 0x80);
    local_4 = *(undefined4 *)(in_ECX + 0x84);
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


// ==== FUN_0057baf0 @ 0x0057baf0 ====

undefined4 FUN_0057baf0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined2 local_14 [2];
  int local_10;
  undefined1 local_c [12];
  
  if (param_1 == 8) {
    return 1;
  }
  if (param_1 != 1) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_LevelUp_009bdba0,7);
  if ((iVar1 == 0) && (param_3 == 1)) {
    local_14[0] = (undefined2)in_ECX[0x1e];
    local_10 = 0;
    FUN_00589790();
    FUN_00589760(local_14);
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  }
  else {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_Button_009bdba8,6);
    if (iVar1 != 0) {
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    local_14[0] = (undefined2)in_ECX[0x1e];
    local_10 = param_3;
    FUN_00589790();
    FUN_00589760(local_14);
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  }
  (**(code **)(*piVar2 + 0x84))(local_c);
  FUN_00589750();
  return 1;
}


// ==== FUN_0057bbe0 @ 0x0057bbe0 ====

void FUN_0057bbe0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bdc14;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  *(undefined2 *)(in_ECX + 0x1e) = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  return;
}


// ==== FUN_0057bc30 @ 0x0057bc30 ====

void FUN_0057bc30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bdc14;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00552170();
  return;
}


// ==== FUN_0057bc60 @ 0x0057bc60 ====

undefined4 FUN_0057bc60(int param_1)

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


// ==== FUN_0057bd00 @ 0x0057bd00 ====

/* WARNING: Removing unreachable block (ram,0x0057c182) */
/* WARNING: Removing unreachable block (ram,0x0057c457) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0057bd00(undefined2 *param_1)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *_Memory;
  int *in_ECX;
  int *unaff_ESI;
  int *unaff_EDI;
  int *piVar10;
  int iVar11;
  undefined4 uStack_260;
  int *piStack_25c;
  undefined4 *puStack_258;
  void **ppvStack_254;
  int *piStack_244;
  int *piStack_240;
  undefined4 *puStack_23c;
  int *piStack_238;
  void **ppvVar12;
  uint uVar13;
  void *pvStack_20c;
  int *piStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  int *piStack_1fc;
  int *piStack_1f8;
  int *piStack_1f4;
  undefined1 auStack_1f0 [4];
  undefined4 uStack_1ec;
  undefined1 uStack_1e8;
  undefined1 uStack_1e7;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  void *pvStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  uint uStack_1c0;
  undefined1 uStack_1b8;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  void *pvStack_198;
  undefined1 uStack_18c;
  undefined1 uStack_18b;
  undefined4 uStack_188;
  uint uStack_184;
  undefined4 uStack_180;
  void *pvStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  uint uStack_168;
  undefined1 uStack_164;
  undefined1 auStack_158 [4];
  void *pvStack_154;
  undefined4 uStack_150;
  undefined1 auStack_14c [4];
  undefined1 uStack_148;
  undefined4 uStack_144;
  uint uStack_140;
  undefined1 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  void *pvStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  uint uStack_118;
  undefined1 auStack_110 [4];
  undefined1 uStack_10c;
  undefined1 uStack_10b;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 auStack_ec [2];
  undefined1 auStack_e4 [8];
  undefined1 uStack_dc;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  int *piStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  uint uStack_b4;
  undefined1 uStack_b0;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 uStack_84;
  uint uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  int iStack_50;
  int iStack_20;
  int iStack_4;
  
  *(undefined2 *)(in_ECX + 0x1e) = *param_1;
  *(undefined1 *)(in_ECX + 0x22) = *(undefined1 *)(param_1 + 1);
  in_ECX[0x23] = *(int *)(param_1 + 0x14);
  in_ECX[0x1c] = (uint)*(byte *)((int)param_1 + 0x23);
  in_ECX[0x1d] = (uint)*(byte *)(param_1 + 0x12);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar2 + 0x50))();
  uStack_60 = 0xf;
  uStack_64 = 0;
  uStack_74 = uStack_74 & 0xffffff00;
  piStack_238 = (int *)0x57bd74;
  FUN_00401660();
  uStack_1ec = (**(code **)(*DAT_00b5a7ac + 4))();
  pvVar3 = (void *)(**(code **)(*DAT_00b5a7ac + 8))();
  uStack_1e4._0_3_ = CONCAT12(1,(undefined2)uStack_1e4);
  uStack_1e0 = 0;
  uStack_1dc = 0;
  uStack_1d8 = 0;
  pvStack_1d4 = (void *)0x0;
  uStack_1d0 = 0;
  uStack_1cc = 0;
  uStack_1c8 = 0;
  uStack_1ac = 0xf;
  uStack_1b0 = 0;
  uStack_1c0 = uStack_1c0 & 0xffffff00;
  piStack_c8 = &iRam0000000f;
  uStack_cc = 0;
  uStack_dc = 0;
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00505f10();
  }
  *(undefined1 *)(piVar2 + 0x41) = 0;
  *(undefined1 *)((int)piVar2 + 0x105) = 0;
  *(undefined1 *)((int)piVar2 + 0x107) = 0;
  *(undefined1 *)(piVar2 + 0x43) = 0;
  piVar2[0x42] = 0xc;
  piVar2[0x44] = 500;
  *(undefined1 *)((int)piVar2 + 0x106) = 0;
  piStack_1f4 = &iRam0000000f;
  piStack_1f8 = (int *)0x0;
  piStack_208 = (int *)((uint)piStack_208 & 0xffffff00);
  piStack_238 = (int *)0x57be6d;
  FUN_00401740();
  ppvVar12 = &pvStack_20c;
  piVar5 = (int *)(**(code **)(*DAT_00b5a7c0 + 8))();
  if (0xf < piStack_1f8) {
    piStack_238 = (int *)0x57be92;
    _free(pvStack_20c);
    return;
  }
  uStack_204 = 0x33;
  piStack_238 = (int *)auStack_1f0;
  puStack_23c = (undefined4 *)0x57becd;
  pvStack_20c = pvVar3;
  piStack_208 = piVar5;
  FUN_0056ac60();
  uStack_204 = 0x34;
  piStack_238 = (int *)auStack_1f0;
  puStack_23c = (undefined4 *)0x57bf03;
  pvStack_20c = pvVar3;
  piStack_208 = piVar5;
  FUN_0056ac60();
  uStack_204 = 0x35;
  piStack_238 = (int *)auStack_1f0;
  puStack_23c = (undefined4 *)0x57bf39;
  pvStack_20c = pvVar3;
  piStack_208 = piVar5;
  FUN_0056ac60();
  uStack_204 = 0x36;
  piStack_238 = (int *)auStack_1f0;
  puStack_23c = (undefined4 *)0x57bf6f;
  pvStack_20c = pvVar3;
  piStack_208 = piVar5;
  FUN_0056ac60();
  piStack_238 = (int *)s_LevelUp_009bdbbc;
  puStack_23c = (undefined4 *)0x57bf82;
  FUN_00401740();
  piStack_238 = (int *)0x0;
  puStack_23c = (undefined4 *)auStack_e4;
  piStack_240 = (int *)0x57bf96;
  FUN_00401660();
  piVar6 = piStack_1f4;
  uStack_1e0 = 0x2b;
  uStack_1dc = 0x2b;
  uStack_1d8 = 0x3d;
  uStack_1e7 = *(undefined1 *)(iStack_4 + 3);
  pvStack_1d4 = (void *)0x3f;
  uStack_1e4 = 400;
  uStack_1e8 = 1;
  piStack_238 = (int *)0x57bfde;
  (**(code **)(*piStack_1f4 + 8))();
  piStack_238 = (int *)in_ECX[1];
  piStack_1f8 = piStack_238;
  if (piStack_238 != (int *)0x0) {
    puStack_23c = (undefined4 *)0x57bff1;
    cVar1 = (**(code **)(*piVar6 + 0x74))();
    if (cVar1 != '\0') {
      piStack_238 = piVar6;
      puStack_23c = (undefined4 *)0x57bfff;
      cVar1 = (**(code **)(*piStack_1f8 + 0x78))();
      if (cVar1 == '\0') {
        puStack_23c = (undefined4 *)0x0;
        piStack_240 = (int *)0x57c00b;
        (**(code **)(*piVar6 + 0x74))();
      }
      else {
        puStack_23c = (undefined4 *)0x57c016;
        iVar11 = (**(code **)(*piStack_1fc + 0x38))();
        piVar6[1] = iVar11;
      }
    }
  }
  piStack_238 = piVar6;
  puStack_23c = (undefined4 *)0x57c023;
  (**(code **)(*unaff_ESI + 0x38))();
  puStack_23c = auStack_ec;
  piStack_240 = (int *)0x57c034;
  (**(code **)(*unaff_EDI + 0x1c))();
  piStack_240 = (int *)0x1;
  piStack_244 = (int *)0x57c040;
  (**(code **)(*piVar6 + 0x2c))();
  piStack_244 = piVar2;
  (**(code **)((int)*ppvVar12 + 0x24))();
  if (piVar2 != (int *)0x0) {
    FUN_00505d80();
    _free(piVar2);
    return;
  }
  piStack_208 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  piVar2 = (int *)0x1;
  piStack_238 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  uStack_188._0_3_ = CONCAT12(1,(undefined2)uStack_188);
  uStack_184 = 0;
  uStack_180 = 0;
  pvStack_17c = (void *)0x0;
  uStack_178 = 0;
  uStack_174 = 0;
  uStack_170 = 0;
  uStack_16c = 0;
  uStack_150 = 0xf;
  pvStack_154 = (void *)0x0;
  uStack_164 = 0;
  uStack_134 = 0xf;
  uStack_138 = 0;
  uStack_148 = 0;
  uStack_130 = 0;
  pvStack_12c = (void *)0x0;
  uStack_128 = 0;
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_00505f10();
  }
  *(undefined1 *)((int)pvVar3 + 0x104) = 0;
  *(undefined1 *)((int)pvVar3 + 0x105) = 0;
  *(undefined1 *)((int)pvVar3 + 0x107) = 0;
  *(undefined1 *)((int)pvVar3 + 0x10c) = 0;
  *(undefined4 *)((int)pvVar3 + 0x108) = 0xc;
  *(undefined4 *)((int)pvVar3 + 0x110) = 500;
  *(undefined1 *)((int)pvVar3 + 0x106) = 0;
  ppvStack_254 = (void **)0x57c167;
  FUN_00401740();
  piVar6 = (int *)(auStack_1f0 + -0x38);
  (**(code **)(*DAT_00b5a7c0 + 8))();
  ppvStack_254 = &pvStack_20c;
  puStack_258 = (undefined4 *)0x57c1c7;
  FUN_0056ac60();
  ppvStack_254 = &pvStack_20c;
  puStack_258 = (undefined4 *)0x57c1fd;
  FUN_0056ac60();
  ppvStack_254 = &pvStack_20c;
  puStack_258 = (undefined4 *)0x57c233;
  FUN_0056ac60();
  ppvStack_254 = &pvStack_20c;
  puStack_258 = (undefined4 *)0x57c269;
  FUN_0056ac60();
  puStack_258 = (undefined4 *)(iStack_20 + 0x2c);
  ppvStack_254 = (void **)0x0;
  piStack_25c = (int *)0x57c282;
  FUN_00401660();
  ppvStack_254 = (void **)s_Button_009bdbd0;
  puStack_258 = (undefined4 *)0x57c295;
  FUN_00401740();
  ppvStack_254 = (void **)0x0;
  puStack_258 = &uStack_150;
  piStack_25c = (int *)0x57c2ac;
  FUN_00401660();
  uStack_184 = 10;
  uStack_180 = 10;
  pvStack_17c = (void *)0x3d;
  uStack_178 = 0x3d;
  uStack_188 = 0x96;
  uStack_18c = 1;
  uStack_18b = 1;
  ppvStack_254 = (void **)0x57c304;
  (**(code **)(iRam0000000f + 8))();
  piVar9 = (int *)in_ECX[1];
  if (piVar9 != (int *)0x0) {
    puStack_258 = (undefined4 *)0x57c318;
    ppvStack_254 = (void **)piVar9;
    cVar1 = (**(code **)(iRam0000000f + 0x74))();
    if (cVar1 != '\0') {
      ppvStack_254 = (void **)0xf;
      puStack_258 = (undefined4 *)0x57c326;
      cVar1 = (**(code **)(*piVar9 + 0x78))();
      if (cVar1 == '\0') {
        puStack_258 = (undefined4 *)0x0;
        piStack_25c = (int *)0x57c333;
        (**(code **)(iRam0000000f + 0x74))();
      }
      else {
        puStack_258 = (undefined4 *)0x57c33e;
        uRam00000013 = (**(code **)(*piVar5 + 0x38))();
      }
    }
  }
  ppvStack_254 = (void **)0xf;
  puStack_258 = (undefined4 *)0x57c34b;
  (**(code **)(*piStack_240 + 0x38))();
  puStack_258 = (undefined4 *)auStack_158;
  piStack_25c = (int *)0x57c35c;
  (**(code **)(*piStack_244 + 0x1c))();
  piStack_25c = piVar2;
  uStack_260 = (void *)0x57c369;
  piVar2 = piStack_25c;
  (**(code **)(iRam0000000f + 0x2c))();
  uStack_260 = pvVar3;
  (**(code **)(*piVar6 + 0x24))();
  if (pvVar3 != (void *)0x0) {
    FUN_00505d80();
    _free(pvVar3);
    return;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_1dc._0_3_ = CONCAT12(1,(undefined2)uStack_1dc);
  uStack_1d8 = 0;
  pvStack_1d4 = (void *)0x0;
  uStack_1d0 = 0;
  uStack_1cc = 0;
  uStack_1c8 = 0;
  uStack_1c4 = 0;
  uStack_1c0 = 0;
  uStack_1a4 = 0xf;
  uStack_1a8 = 0;
  uStack_1b8 = 0;
  iVar11 = 0;
  piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  uStack_128 = 0xf;
  pvStack_12c = (void *)0x0;
  uStack_13c = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  uStack_11c = 0;
  uVar7 = FUN_00402220(&piStack_244,&uStack_b4,s__skPanel_009bdbd8);
  FUN_00401660(uVar7,0,0xffffffff);
  FUN_00401660(&uStack_140,0,0xffffffff);
  pvStack_1d4 = (void *)0xd;
  uStack_1d8 = 0xd;
  uStack_1cc = 0x35;
  uStack_1d0 = 0x35;
  uStack_1dc = 100;
  uStack_1e0 = CONCAT22(uStack_1e0._2_2_,0x101);
  uVar13 = 0;
  piStack_240 = (int *)((uint)piStack_240 & 0xffffff00);
  FUN_00401740(s_skill_icon_009bdbe4,10);
  (**(code **)(*DAT_00b5a7c0 + 8))(&piStack_244);
  if (0xf < uVar13) {
    _free(piStack_244);
    return;
  }
  (**(code **)(*piVar5 + 8))(&uStack_1e4);
  piVar9 = (int *)in_ECX[1];
  if ((piVar9 != (int *)0x0) && (cVar1 = (**(code **)(*piVar5 + 0x74))(piVar9), cVar1 != '\0')) {
    cVar1 = (**(code **)(*piVar9 + 0x78))(piVar5);
    if (cVar1 == '\0') {
      (**(code **)(*piVar5 + 0x74))(0);
    }
    else {
      iVar8 = (**(code **)(*piVar9 + 0x38))();
      piVar5[1] = iVar8;
    }
  }
  (**(code **)(*piVar6 + 0x38))(piVar5);
  (**(code **)(*piVar6 + 0x1c))(auStack_14c);
  (**(code **)(*piVar5 + 0x2c))(piVar6);
  FUN_00587d40();
  if (*(char *)(iStack_50 + 2) != '\0') {
    piVar5 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
    uStack_108._0_3_ = CONCAT12(1,(undefined2)uStack_108);
    uStack_104 = 0;
    uStack_100 = 0;
    uStack_fc = 0;
    uStack_f8 = 0;
    uStack_f4 = 0;
    uStack_f0 = 0;
    auStack_ec[0] = 0;
    uStack_d0 = 0xf;
    uStack_d4 = 0;
    auStack_e4[0] = 0;
    piVar10 = (int *)0x8;
    piVar9 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
    uStack_9c = 0xf;
    uStack_a0 = 0;
    uStack_b0 = 0;
    uStack_98 = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    pvVar3 = operator_new(0x468);
    if (pvVar3 == (void *)0x0) {
      _Memory = (undefined4 *)0x0;
    }
    else {
      _Memory = (undefined4 *)FUN_00505f10();
    }
    _Memory[0x66] = 5;
    _Memory[0x67] = 5;
    *(undefined1 *)(_Memory + 0x65) = 0;
    *(undefined1 *)((int)_Memory + 0x195) = 0;
    *(undefined1 *)((int)_Memory + 0x196) = 0;
    _Memory[0x68] = 0xc;
    uVar7 = FUN_00402220(&uStack_260,&uStack_d0,s__skLbl_009bdbf0);
    FUN_00401660(uVar7,0,0xffffffff);
    if (&iRam0000000f < piVar2) {
      _free(piStack_25c);
      return;
    }
    FUN_00401660(&uStack_b4,0,0xffffffff);
    uStack_100 = 0;
    uStack_104 = 0;
    uStack_f8 = 0x15;
    uStack_fc = 0x18;
    uStack_108 = 100;
    uStack_10c = 1;
    uStack_10b = 1;
    *_Memory = 0;
    uVar13 = 0;
    piStack_25c = (int *)((uint)piStack_25c & 0xffffff00);
    FUN_00401740(s_new_skill_009bdbf8,9);
    uVar7 = (**(code **)(*DAT_00b5a7c0 + 8))(&uStack_260);
    _Memory[1] = uVar7;
    if (0xf < uVar13) {
      _free(uStack_260);
      return;
    }
    _Memory[2] = 0x29;
    uStack_90 = 0;
    uStack_70 = 0xf;
    uStack_74 = 0;
    uStack_84 = 0;
    uStack_64 = 1;
    uStack_60 = uStack_60 & 0xffff0000;
    uStack_68 = 0xffffffff;
    uStack_8c = 0;
    uStack_6c = 2;
    FUN_00401740(&DAT_009bdc04,2);
    uVar7 = FUN_00404230(auStack_1f0 + -0x74);
    FUN_00401660(uVar7,0,0xffffffff);
    if (0xf < uVar13) {
      _free(uStack_260);
      return;
    }
    (**(code **)(*piVar5 + 8))(auStack_110);
    cVar1 = (**(code **)(*piVar5 + 0x74))(piVar6);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(iVar11 + 0x78))(piVar5);
      if (cVar1 == '\0') {
        (**(code **)(*piVar5 + 0x74))(0);
      }
      else {
        iVar11 = (**(code **)(*piVar10 + 0x38))();
        piVar5[1] = iVar11;
      }
    }
    (**(code **)(*piVar9 + 0x38))(piVar5);
    (**(code **)(*piVar9 + 0x1c))(&uStack_c4);
    (**(code **)(*piVar9 + 8))(&uStack_a0);
    (**(code **)(*piVar5 + 0x2c))(piVar9);
    *(undefined1 *)((int)_Memory + 0x196) = 1;
    (**(code **)(*piVar9 + 0x24))(_Memory);
    FUN_00505d80();
    _free(_Memory);
    return;
  }
  if (0xf < uStack_140) {
    _free(pvStack_154);
    return;
  }
  uStack_140 = 0xf;
  uStack_144 = 0;
  pvStack_154 = (void *)((uint)pvStack_154 & 0xffffff00);
  if (0xf < uStack_1c0) {
    _free(pvStack_1d4);
    return;
  }
  uStack_1c0 = 0xf;
  uStack_1c4 = 0;
  pvStack_1d4 = (void *)((uint)pvStack_1d4 & 0xffffff00);
  if (0xf < uStack_168) {
    _free(pvStack_17c);
    return;
  }
  uStack_168 = 0xf;
  uStack_16c = 0;
  pvStack_17c = (void *)((uint)pvStack_17c & 0xffffff00);
  if (0xf < uStack_184) {
    _free(pvStack_198);
    return;
  }
  uStack_184 = 0xf;
  uStack_188 = 0;
  pvStack_198 = (void *)((uint)pvStack_198 & 0xffffff00);
  if (0xf < uStack_118) {
    _free(pvStack_12c);
    return;
  }
  uStack_118 = 0xf;
  uStack_11c = 0;
  pvStack_12c = (void *)((uint)pvStack_12c & 0xffffff00);
  if (&iRam0000000f < piStack_1fc) {
    _free(&iRam0000000f);
    return;
  }
  piStack_1fc = (int *)0xf;
  uStack_200 = 0;
  if (uStack_b4 < 0x10) {
    return;
  }
  _free(piStack_c8);
  return;
}


// ==== FUN_0057cbf0 @ 0x0057cbf0 ====

void FUN_0057cbf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bdc14;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00552170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0057cc50 @ 0x0057cc50 ====

undefined4 FUN_0057cc50(void)

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


// ==== FUN_0057cc80 @ 0x0057cc80 ====

void FUN_0057cc80(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_0057cca0 @ 0x0057cca0 ====

uint FUN_0057cca0(int *param_1)

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


// ==== FUN_0057cd00 @ 0x0057cd00 ====

uint FUN_0057cd00(int *param_1)

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


// ==== FUN_0057cd40 @ 0x0057cd40 ====

void FUN_0057cd40(undefined1 *param_1)

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


// ==== FUN_0057ce90 @ 0x0057ce90 ====

void FUN_0057ce90(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x98);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    piVar4 = (int *)puVar3[4];
    iVar8 = (**(code **)(*piVar4 + 0x3c))();
    if (iVar8 != 0) {
      piVar9 = (int *)(**(code **)(*piVar4 + 0x3c))();
      (**(code **)(*piVar9 + 0x7c))(piVar4);
    }
    if (*(char *)((int)puVar3 + 0x19) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x19) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x19);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x19);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x19);
        puVar7 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x19);
          puVar7 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  pvVar6 = *(void **)(*(int *)(in_ECX + 0x98) + 4);
  if (*(char *)((int)pvVar6 + 0x19) == '\0') {
    FUN_0057e100(*(undefined4 *)((int)pvVar6 + 8));
    _free(pvVar6);
    return;
  }
  *(int *)(*(int *)(in_ECX + 0x98) + 4) = *(int *)(in_ECX + 0x98);
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(in_ECX + 0x98);
  *(int *)(*(int *)(in_ECX + 0x98) + 8) = *(int *)(in_ECX + 0x98);
  (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
  pvVar6 = *(void **)(*(int *)(in_ECX + 0x78) + 4);
  if (*(char *)((int)pvVar6 + 0x21) == '\0') {
    FUN_0057e0c0(*(undefined4 *)((int)pvVar6 + 8));
    _free(pvVar6);
    return;
  }
  *(int *)(*(int *)(in_ECX + 0x78) + 4) = *(int *)(in_ECX + 0x78);
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x78);
  *(int *)(*(int *)(in_ECX + 0x78) + 8) = *(int *)(in_ECX + 0x78);
  return;
}


// ==== FUN_0057cfc0 @ 0x0057cfc0 ====

void FUN_0057cfc0(uint param_1,uint param_2,char param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_c;
  uint local_8;
  undefined1 local_4 [4];
  
  bVar2 = *(byte *)(param_1 + 0x23);
  bVar3 = *(byte *)(param_1 + 0x24);
  uVar7 = (uint)bVar2;
  param_1 = CONCAT31(param_1._1_3_,*(undefined1 *)(param_2 + 0x23));
  param_2 = CONCAT31(param_2._1_3_,*(undefined1 *)(param_2 + 0x24));
  local_c = (uint)bVar3;
  piVar5 = (int *)FUN_00558e70(&local_8,&local_c);
  iVar4 = *piVar5;
  if (iVar4 != *(int *)(in_ECX + 0x78)) {
    if (param_3 == '\0') {
      pbVar1 = (byte *)(iVar4 + 0x18 + uVar7 * 2);
      *pbVar1 = *pbVar1 | 4;
    }
    else {
      pbVar1 = (byte *)(iVar4 + 0x10 + uVar7 * 2);
      *pbVar1 = *pbVar1 | 4;
    }
  }
  local_c = param_2 & 0xff;
  uVar6 = bVar3 + 1;
  if (bVar2 < (byte)param_1) {
    local_c = local_c - 1;
  }
  if (uVar6 < local_c) {
    do {
      local_8 = uVar6;
      piVar5 = (int *)FUN_00558e70(local_4,&local_8);
      iVar4 = *piVar5;
      if (iVar4 != *(int *)(in_ECX + 0x78)) {
        if (param_3 == '\0') {
          pbVar1 = (byte *)(iVar4 + 0x18 + uVar7 * 2);
          *pbVar1 = *pbVar1 | 5;
        }
        else {
          pbVar1 = (byte *)(iVar4 + 0x10 + uVar7 * 2);
          *pbVar1 = *pbVar1 | 5;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_c);
  }
  if (bVar2 == (byte)param_1) {
    param_1 = uVar6;
    piVar5 = (int *)FUN_00558e70(&param_2,&param_1);
    iVar4 = *piVar5;
    if (iVar4 != *(int *)(in_ECX + 0x78)) {
      if (param_3 == '\0') {
        pbVar1 = (byte *)(iVar4 + 0x18 + uVar7 * 2);
        *pbVar1 = *pbVar1 | 1;
        return;
      }
      pbVar1 = (byte *)(iVar4 + 0x10 + uVar7 * 2);
      *pbVar1 = *pbVar1 | 1;
      return;
    }
  }
  else {
    local_8 = uVar6;
    piVar5 = (int *)FUN_00558e70(local_4,&local_8);
    local_c = param_1;
    iVar4 = *piVar5;
    if (iVar4 != *(int *)(in_ECX + 0x78)) {
      if (param_3 == '\0') {
        pbVar1 = (byte *)(iVar4 + 0x18 + uVar7 * 2);
        *pbVar1 = *pbVar1 | 1;
      }
      else {
        pbVar1 = (byte *)(iVar4 + 0x10 + uVar7 * 2);
        *pbVar1 = *pbVar1 | 1;
      }
    }
    if (bVar2 < (byte)param_1) {
      uVar8 = uVar7;
      param_1 = param_1 & 0xff;
    }
    else {
      uVar8 = param_1 & 0xff;
      param_1 = uVar7;
    }
    local_c = local_c & 0xff;
    local_8 = uVar6;
    piVar5 = (int *)FUN_00558e70(local_4,&local_8);
    iVar4 = *piVar5;
    if (iVar4 != *(int *)(in_ECX + 0x78)) {
      if (param_3 == '\0') {
        pbVar1 = (byte *)(iVar4 + 0x18 + uVar8 * 2);
        *pbVar1 = *pbVar1 | 2;
      }
      else {
        pbVar1 = (byte *)(iVar4 + 0x10 + uVar8 * 2);
        *pbVar1 = *pbVar1 | 2;
      }
    }
    local_8 = uVar6;
    piVar5 = (int *)FUN_00558e70(local_4,&local_8);
    iVar4 = *piVar5;
    if (iVar4 != *(int *)(in_ECX + 0x78)) {
      if (param_3 == '\0') {
        pbVar1 = (byte *)(iVar4 + 0x18 + param_1 * 2);
        *pbVar1 = *pbVar1 | 8;
      }
      else {
        pbVar1 = (byte *)(iVar4 + 0x10 + param_1 * 2);
        *pbVar1 = *pbVar1 | 8;
      }
    }
    uVar8 = uVar8 + 1;
    if (uVar8 < param_1) {
      local_8 = uVar6;
      do {
        piVar5 = (int *)FUN_00558e70(local_4,&local_8);
        iVar4 = *piVar5;
        if (iVar4 != *(int *)(in_ECX + 0x78)) {
          if (param_3 == '\0') {
            pbVar1 = (byte *)(iVar4 + 0x18 + uVar8 * 2);
            *pbVar1 = *pbVar1 | 10;
          }
          else {
            pbVar1 = (byte *)(iVar4 + 0x10 + uVar8 * 2);
            *pbVar1 = *pbVar1 | 10;
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_1);
    }
    uVar7 = param_2 & 0xff;
    if (uVar6 == uVar7 - 1) {
      param_1 = uVar6;
      piVar5 = (int *)FUN_00558e70(&param_2,&param_1);
      uVar6 = local_c;
      iVar4 = *piVar5;
      if (iVar4 != *(int *)(in_ECX + 0x78)) {
        if (param_3 == '\0') {
          pbVar1 = (byte *)(iVar4 + 0x18 + local_c * 2);
          *pbVar1 = *pbVar1 | 4;
        }
        else {
          pbVar1 = (byte *)(iVar4 + 0x10 + local_c * 2);
          *pbVar1 = *pbVar1 | 4;
        }
      }
      param_1 = uVar7;
      piVar5 = (int *)FUN_00558e70(&param_2,&param_1);
      iVar4 = *piVar5;
      if (iVar4 != *(int *)(in_ECX + 0x78)) {
        if (param_3 != '\0') {
          pbVar1 = (byte *)(iVar4 + 0x10 + uVar6 * 2);
          *pbVar1 = *pbVar1 | 1;
          return;
        }
        pbVar1 = (byte *)(iVar4 + 0x18 + uVar6 * 2);
        *pbVar1 = *pbVar1 | 1;
      }
    }
  }
  return;
}


// ==== FUN_0057d240 @ 0x0057d240 ====

undefined4 FUN_0057d240(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint in_ECX;
  uint local_4;
  
  uVar4 = param_1;
  local_4 = in_ECX;
  iVar2 = FUN_00589780();
  if (*(int *)(iVar2 + 4) == 1) {
    puVar3 = (undefined2 *)FUN_00589780();
    uVar1 = *puVar3;
    param_1 = CONCAT22((short)((uint)uVar4 >> 0x10),uVar1);
    FUN_0057e410(&local_4,&param_1);
    if (local_4 != *(uint *)(in_ECX + 0x98)) {
      iVar2 = *(int *)(*(int *)(local_4 + 0x14) + 0x8c);
      if (*(char *)(*(int *)(local_4 + 0x14) + 0x88) == '\0') {
        return 1;
      }
      if (iVar2 == 2) {
        iVar2 = *DAT_00b5acb8;
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,10);
      }
      else {
        if (iVar2 != 1) {
          puVar5 = operator_new(8);
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            *puVar5 = &PTR_FUN_009ba8ac;
            *(undefined2 *)(puVar5 + 1) = 0;
          }
          *(undefined2 *)(puVar5 + 1) = uVar1;
          FUN_00797a20(puVar5);
          return 1;
        }
        iVar2 = *DAT_00b5acb8;
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,10);
      }
      FUN_00765c50(uVar4);
      (**(code **)(iVar2 + 0x18))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0057d330 @ 0x0057d330 ====

undefined4 FUN_0057d330(int param_1)

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


// ==== FUN_0057d3d0 @ 0x0057d3d0 ====

uint FUN_0057d3d0(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  uVar2 = iVar1 - 1;
  if (uVar2 == 0) {
    uVar2 = FUN_0057d240(param_1);
    if ((char)uVar2 == '\x01') {
      return uVar2;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_0057d430 @ 0x0057d430 ====

void FUN_0057d430(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int *unaff_retaddr;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bdca8);
  FUN_00402220(apvStack_1c,uVar2);
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(apvStack_1c);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
    iVar3 = FUN_00803725(uVar2);
    in_ECX[0x24] = iVar3;
  }
  in_ECX[0x21] = *unaff_retaddr;
  in_ECX[0x22] = unaff_retaddr[1];
  in_ECX[0x23] = unaff_retaddr[2];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_0057d4e0 @ 0x0057d4e0 ====

void FUN_0057d4e0(void)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  short *psVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  byte *pbVar6;
  int iVar7;
  int iStack_38;
  undefined4 *puStack_34;
  undefined4 *local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar7 = 0;
  if (0 < *(int *)(in_ECX + 0x70)) {
    do {
      iVar4 = 0;
      do {
        *(undefined2 *)((int)&local_1c + iVar4 * 2) = 0;
        *(undefined2 *)((int)local_2c + iVar4 * 2 + 8) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      local_c = local_20;
      local_8 = local_1c;
      local_10 = local_24;
      local_4 = local_18;
      local_14 = iVar7;
      FUN_0057eb40(local_2c,&local_14);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(in_ECX + 0x70));
  }
  iVar7 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar7 != 0) {
    puStack_34 = *(undefined4 **)(*(int *)(in_ECX + 0x80) + 4);
    puVar5 = *(undefined4 **)(*(int *)(in_ECX + 0x80) + 8);
    local_2c[0] = puVar5;
    if (puStack_34 != puVar5) {
      do {
        puVar2 = (undefined2 *)*puStack_34;
        if ((puVar2 != (undefined2 *)0x0) && (iStack_38 = *(int *)(puVar2 + 0xc), iStack_38 != 0)) {
          pbVar6 = (byte *)(puVar2 + 5);
          do {
            if (*(short *)(pbVar6 + -2) != 0) {
              for (puVar5 = *(undefined4 **)(*(int *)(in_ECX + 0x80) + 4);
                  puVar5 != *(undefined4 **)(*(int *)(in_ECX + 0x80) + 8); puVar5 = puVar5 + 1) {
                psVar3 = (short *)*puVar5;
                if ((psVar3 != (short *)0x0) && (*psVar3 == *(short *)(pbVar6 + -2))) {
                  uVar1 = 0;
                  iVar4 = (**(code **)(*DAT_00b5acc8 + 8))
                                    (iVar7,CONCAT22((short)((uint)puVar5 >> 0x10),*puVar2));
                  if (iVar4 == 0) {
LAB_0057d60b:
                    uVar1 = 1;
                  }
                  else if (iVar4 == 1) {
                    uVar1 = *(undefined1 *)((int)puVar2 + 3);
                  }
                  else if ((iVar4 == 3) && (*pbVar6 <= *(byte *)(psVar3 + 1))) goto LAB_0057d60b;
                  FUN_0057cfc0(psVar3,puVar2,uVar1);
                  break;
                }
              }
            }
            pbVar6 = pbVar6 + 4;
            iStack_38 = iStack_38 + -1;
          } while (iStack_38 != 0);
          puVar5 = local_2c[0];
        }
        puStack_34 = puStack_34 + 1;
      } while (puStack_34 != puVar5);
    }
  }
  return;
}


// ==== FUN_0057d650 @ 0x0057d650 ====

undefined4 FUN_0057d650(int param_1)

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
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar2 != (int *)0x0) {
    uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bdca8);
    FUN_00402220(apvStack_1c,uVar5);
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(apvStack_1c);
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


// ==== FUN_0057d750 @ 0x0057d750 ====

undefined4 FUN_0057d750(int *param_1)

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
    cVar1 = FUN_0057cca0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_0057cd00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if ((iVar2 == 0x10010) && (cVar1 = FUN_0057d650(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_0057d7d0 @ 0x0057d7d0 ====

void FUN_0057d7d0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009bdcfc;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_0057f050(local_4,*(undefined4 *)in_ECX[0x26],(undefined4 *)in_ECX[0x26]);
  _free((void *)in_ECX[0x26]);
  return;
}


// ==== FUN_0057d860 @ 0x0057d860 ====

void FUN_0057d860(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int *unaff_retaddr;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined1 local_3c [4];
  uint uStack_38;
  uint uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_2c = 0x3e;
  local_28 = 0x3e;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_skill_line_009bdcb0,10);
  local_28 = (**(code **)(*DAT_00b5a7c0 + 8))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009bdce4;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  puVar1[1] = uVar2;
  iStack_48 = 0;
  uVar4 = 0;
  do {
    iStack_44 = *unaff_retaddr + iStack_48;
    piVar3 = (int *)FUN_00558e70(local_3c,&iStack_44);
    if (*piVar3 != *(int *)(in_ECX + 0x78)) {
      puVar6 = (ushort *)(*piVar3 + 0x10);
      uVar5 = 0;
      do {
        uStack_24 = 0;
        uStack_38 = uVar5;
        uStack_34 = uVar4;
        if ((puVar6[4] != 0) && (uStack_24 = puVar6[4] | 0x10, uStack_24 != 0)) {
          FUN_0057f1c0(&uStack_38);
        }
        if ((*puVar6 != 0) && (uStack_24 = (uint)*puVar6, uStack_24 != 0)) {
          FUN_0057f1c0(&uStack_38);
        }
        uVar5 = uVar5 + 0x3e;
        puVar6 = puVar6 + 1;
      } while (uVar5 < 0xf8);
      in_ECX = iStack_40;
    }
    iStack_48 = iStack_48 + 1;
    uVar4 = uVar4 + 0x3e;
  } while (uVar4 < 0x136);
  (**(code **)(*DAT_00b5ad24 + 4))(puVar1);
  (**(code **)*puVar1)(1);
  return;
}


// ==== FUN_0057d9d0 @ 0x0057d9d0 ====

void FUN_0057d9d0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int in_ECX;
  int *piVar6;
  int local_4c;
  int *local_48;
  undefined4 uStack_44;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4c = *(int *)(*(int *)(in_ECX + 0x90) + 0x88);
  FUN_0057d860(&local_4c);
  if (*(int *)(in_ECX + 0x70) != 0) {
    local_48 = *(int **)(in_ECX + 0x98);
    local_3a = 1;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    piVar6 = (int *)*local_48;
    if (piVar6 != local_48) {
      do {
        piVar2 = (int *)piVar6[4];
        iVar3 = piVar6[5];
        puVar5 = (undefined1 *)(**(code **)(*piVar2 + 0x10))();
        uStack_3c = *puVar5;
        uStack_3b = puVar5[1];
        local_3a = puVar5[2];
        local_38 = *(undefined4 *)(puVar5 + 4);
        local_34 = *(undefined4 *)(puVar5 + 8);
        local_30 = *(int *)(puVar5 + 0xc);
        local_2c = *(undefined4 *)(puVar5 + 0x10);
        local_28 = *(int *)(puVar5 + 0x14);
        local_24 = *(undefined4 *)(puVar5 + 0x18);
        local_20 = *(undefined4 *)(puVar5 + 0x1c);
        FUN_00401660(puVar5 + 0x20,0,0xffffffff);
        uStack_44 = *(undefined4 *)(iVar3 + 0x70);
        iVar3 = *(int *)(iVar3 + 0x74);
        if ((iVar3 < local_4c) || (local_4c + 5 <= iVar3)) {
          uStack_3c = 0;
        }
        else {
          local_30 = (iVar3 - local_4c) * 0x3e;
          local_28 = local_30 + 0x3e;
          uStack_3c = 1;
        }
        (**(code **)(*piVar2 + 0xc))(&uStack_3c);
        if (*(char *)((int)piVar6 + 0x19) == '\0') {
          piVar2 = (int *)piVar6[2];
          if (*(char *)((int)piVar2 + 0x19) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x19);
              piVar6 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x19);
            piVar4 = (int *)piVar6[1];
            piVar2 = piVar6;
            while ((piVar6 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0x19);
              piVar4 = (int *)piVar6[1];
              piVar2 = piVar6;
            }
          }
        }
      } while (piVar6 != local_48);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0057db50 @ 0x0057db50 ====

void FUN_0057db50(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bdcfc;
  iVar1 = FUN_0057e260();
  in_ECX[0x1e] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[0x1e] + 4) = in_ECX[0x1e];
  *(undefined4 *)in_ECX[0x1e] = in_ECX[0x1e];
  *(undefined4 *)(in_ECX[0x1e] + 8) = in_ECX[0x1e];
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  iVar1 = FUN_0057e300();
  in_ECX[0x26] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[0x26] + 4) = in_ECX[0x26];
  *(undefined4 *)in_ECX[0x26] = in_ECX[0x26];
  *(undefined4 *)(in_ECX[0x26] + 8) = in_ECX[0x26];
  in_ECX[0x27] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_0057dbf0 @ 0x0057dbf0 ====

undefined4 FUN_0057dbf0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 ****ppppuVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  bool bVar5;
  undefined1 auStack_1c [4];
  undefined4 ****local_18 [4];
  undefined4 uStack_8;
  uint local_4;
  
  bVar5 = false;
  if (param_1 == 4) {
    bVar5 = true;
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009bdca8);
    FUN_00402220(auStack_1c,uVar2);
    ppppuVar3 = local_18[0];
    if (local_4 < 0x10) {
      ppppuVar3 = local_18;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppuVar3,uStack_8);
    if ((iVar4 == 0) && (bVar1 = true, param_3 == 6)) goto LAB_0057dc5d;
  }
  bVar1 = false;
LAB_0057dc5d:
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18[0]);
    return extraout_EAX;
  }
  if (bVar1) {
    FUN_0057d9d0();
    return 1;
  }
  return 0;
}


// ==== FUN_0057dca0 @ 0x0057dca0 ====

void FUN_0057dca0(undefined2 *param_1)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  undefined4 *unaff_EBX;
  int *unaff_EBP;
  undefined1 *_Memory;
  undefined4 uVar8;
  undefined4 uStack_9c;
  undefined1 uStack_90;
  undefined1 uStack_8f;
  undefined4 uStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 uStack_68;
  undefined1 auStack_5c [4];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  undefined4 uStack_40;
  int *piStack_3c;
  int *piStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_20 [4];
  undefined1 local_1c [28];
  
  FUN_00401740(s_SKILLNODE__d_009bdcbc,0xc);
  FUN_00404230(local_1c);
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_8c._0_3_ = CONCAT12(1,(undefined2)uStack_8c);
  iStack_88 = 0;
  uStack_84 = 0;
  iStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_54 = 0xf;
  uStack_58 = 0;
  uStack_68 = 0;
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    uStack_9c = 0;
  }
  else {
    uStack_9c = FUN_00505f10();
  }
  uVar8 = 0xd;
  piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0xd);
  piStack_3c = (int *)0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  piStack_38 = (int *)0x0;
  uStack_34 = 0;
  uStack_30 = 0;
  *unaff_EBX = 0;
  FUN_00401660(auStack_20,0,0xffffffff);
  FUN_00401660(&uStack_54,0,0xffffffff);
  iStack_88 = (uint)*(byte *)((int)param_1 + 0x23) * 0x3e;
  uStack_84 = 0;
  iStack_80 = iStack_88 + 0x3e;
  uStack_7c = 0x3e;
  _Memory = &uStack_90;
  uStack_8c = 100;
  uStack_90 = 1;
  uStack_8f = 1;
  (**(code **)(*piVar4 + 8))();
  piVar2 = *(int **)(uStack_9c + 4);
  if (piVar2 != (int *)0x0) {
    cVar3 = (**(code **)(*piVar4 + 0x74))(piVar2);
    if (cVar3 != '\0') {
      cVar3 = (**(code **)(*piVar2 + 0x78))(piVar4);
      if (cVar3 == '\0') {
        (**(code **)(*piVar4 + 0x74))(0);
      }
      else {
        iVar7 = (**(code **)(*unaff_EBP + 0x38))();
        piVar4[1] = iVar7;
      }
    }
  }
  (**(code **)(*piVar6 + 0x38))(piVar4);
  (**(code **)(*piVar6 + 0x1c))(auStack_5c);
  (**(code **)(*piVar4 + 0x2c))(piVar6);
  (**(code **)(*piVar6 + 0x24))(uVar8);
  bVar1 = *(byte *)((int)param_1 + 0x23);
  piVar6[0x1d] = (uint)*(byte *)(param_1 + 0x12);
  piVar6[0x1c] = (uint)bVar1;
  FUN_0057bd00(param_1);
  uStack_40 = CONCAT22(uStack_40._2_2_,*param_1);
  piStack_3c = piVar4;
  piStack_38 = piVar6;
  FUN_0057ec00(auStack_5c + -0x50,&uStack_40);
  FUN_00505d80();
  _free(_Memory);
  return;
}


// ==== FUN_0057df20 @ 0x0057df20 ====

void FUN_0057df20(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  byte bVar3;
  int *piVar4;
  
  piVar4 = *(int **)(*(int *)(in_ECX + 0x80) + 4);
  piVar1 = *(int **)(*(int *)(in_ECX + 0x80) + 8);
  bVar3 = 0;
  if (piVar4 != piVar1) {
    do {
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        if (bVar3 < *(byte *)(iVar2 + 0x24)) {
          bVar3 = *(byte *)(iVar2 + 0x24);
        }
        FUN_0057dca0(iVar2);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != piVar1);
    if (bVar3 != 0) {
      *(uint *)(in_ECX + 0x70) = bVar3 + 1;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0x70) = 0;
  return;
}


// ==== FUN_0057df80 @ 0x0057df80 ====

void FUN_0057df80(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_0057ce90();
  *(undefined4 *)(in_ECX + 0x80) = param_1;
  FUN_0057df20();
  iVar1 = *(int *)(in_ECX + 0x70);
  if (0 < iVar1) {
    iVar2 = 0;
    if (5 < iVar1) {
      iVar2 = iVar1 + -5;
    }
    FUN_0055aac0(iVar2);
    FUN_0057d4e0();
  }
  FUN_0057d9d0();
  return;
}


// ==== FUN_0057dfd0 @ 0x0057dfd0 ====

int FUN_0057dfd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x18;
}


// ==== FUN_0057dff0 @ 0x0057dff0 ====

void FUN_0057dff0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x21) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x21) == '\0');
  }
  return;
}


// ==== FUN_0057e010 @ 0x0057e010 ====

void FUN_0057e010(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
  }
  return;
}


// ==== FUN_0057e050 @ 0x0057e050 ====

int FUN_0057e050(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982100;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x18) {
    FUN_0057e010(param_3,param_1);
    param_3 = param_3 + 0x18;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0057e0b6 @ 0x0057e0b6 ====

void Catch_0057e0b6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0057e0c0 @ 0x0057e0c0 ====

void FUN_0057e0c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_0057e0c0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0057e100 @ 0x0057e100 ====

void FUN_0057e100(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_0057e100(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0057e140 @ 0x0057e140 ====

void * FUN_0057e140(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982110;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0065ddc0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0057e1b5 @ 0x0057e1b5 ====

void Catch_0057e1b5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0057e1d0 @ 0x0057e1d0 ====

void * FUN_0057e1d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982120;
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


// ==== Catch@0057e245 @ 0x0057e245 ====

void Catch_0057e245(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0057e260 @ 0x0057e260 ====

void FUN_0057e260(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982130;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 8) = 1;
  *(undefined1 *)((int)puVar1 + 0x21) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0057e2ea @ 0x0057e2ea ====

void Catch_0057e2ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0057e300 @ 0x0057e300 ====

void FUN_0057e300(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982140;
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


// ==== Catch@0057e38a @ 0x0057e38a ====

void Catch_0057e38a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0057e3a0 @ 0x0057e3a0 ====

void FUN_0057e3a0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982150;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0057e010(param_1,param_3);
    param_1 = param_1 + 0x18;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0057e406 @ 0x0057e406 ====

void Catch_0057e406(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0057e410 @ 0x0057e410 ====

void FUN_0057e410(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0057e480 @ 0x0057e480 ====

void FUN_0057e480(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0057e050(param_1,param_2,param_3);
  return;
}


// ==== FUN_0057e4a0 @ 0x0057e4a0 ====

int FUN_0057e4a0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0057e3a0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x18;
}


// ==== FUN_0057e4d0 @ 0x0057e4d0 ====

void FUN_0057e4d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0057e140(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x20);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x20) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_0057e5d5:
        *(undefined1 *)(*piVar5 + 0x20) = 1;
        *(undefined1 *)(piVar6 + 8) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x20) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004bdf70(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x20) = 0;
        FUN_004bdfc0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[8] == '\0') goto LAB_0057e5d5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004bdfc0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x20) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x20) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x21) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x20);
  } while( true );
}


// ==== FUN_0057e6b0 @ 0x0057e6b0 ====

void FUN_0057e6b0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x15555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0057e1d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[6] == '\0') {
LAB_0057e7b5:
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
      if ((char)piVar6[6] == '\0') goto LAB_0057e7b5;
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


// ==== FUN_0057e890 @ 0x0057e890 ====

/* WARNING: Removing unreachable block (ram,0x0057e9ac) */
/* WARNING: Removing unreachable block (ram,0x0057e9bc) */
/* WARNING: Removing unreachable block (ram,0x0057e9c5) */
/* WARNING: Removing unreachable block (ram,0x0057e9c8) */
/* WARNING: Removing unreachable block (ram,0x0057e9b8) */
/* WARNING: Removing unreachable block (ram,0x0057e9d6) */
/* WARNING: Removing unreachable block (ram,0x0057e9e3) */
/* WARNING: Removing unreachable block (ram,0x0057e9ee) */
/* WARNING: Removing unreachable block (ram,0x0057e9ea) */
/* WARNING: Removing unreachable block (ram,0x0057e9de) */
/* WARNING: Removing unreachable block (ram,0x0057e9f1) */

void FUN_0057e890(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x21) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_004dde50();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004128f0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      uVar4 = FUN_0057dff0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdf70(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) == '\x01') && (*(char *)(piVar5[2] + 0x20) == '\x01'))
            goto LAB_0057eac0;
            if (*(char *)(piVar5[2] + 0x20) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              *(undefined1 *)(piVar5 + 8) = 0;
              FUN_004bdfc0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 8) = (char)piVar3[8];
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar5[2] + 0x20) = 1;
            FUN_004bdf70(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdfc0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(piVar5[2] + 0x20) != '\x01') || (*(char *)(*piVar5 + 0x20) != '\x01')) {
              if (*(char *)(*piVar5 + 0x20) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x20) = 1;
                *(undefined1 *)(piVar5 + 8) = 0;
                FUN_004bdf70(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 8) = (char)piVar3[8];
              *(undefined1 *)(piVar3 + 8) = 1;
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              FUN_004bdfc0(piVar3);
              break;
            }
LAB_0057eac0:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_0057eb40 @ 0x0057eb40 ====

void FUN_0057eb40(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0057e4d0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0057e4d0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0057ec00 @ 0x0057ec00 ====

void FUN_0057ec00(undefined4 *param_1,ushort *param_2)

{
  undefined4 uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x19) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < *(ushort *)(puVar4 + 3);
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0057e6b0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004b83a0();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_0057e6b0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0057ecc0 @ 0x0057ecc0 ====

void FUN_0057ecc0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982160;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  local_50 = *param_3;
  local_4c = param_3[1];
  local_48 = param_3[2];
  local_44 = param_3[3];
  local_40 = param_3[4];
  local_3c = param_3[5];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x18;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x5c);
    if (0xaaaaaaaU - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xaaaaaaa - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0057dfd0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x18;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_0057e480(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_0057e4a0(local_1c,param_2,&local_50);
      FUN_0057e480(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x18) < param_2) {
      local_24 = param_2 * 0x18;
      FUN_0057e050(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_0057e4a0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x18,&local_50)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_004dcf10(param_1,*(int *)(in_ECX + 8) - local_24,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x18;
    uVar4 = FUN_0057e050(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0085d5a0(param_1,local_2c,local_28,local_38);
    FUN_004dcf10(param_1,param_2 * 0x18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0057ee81 @ 0x0057ee81 ====

void Catch_0057ee81(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0057f050 @ 0x0057f050 ====

void FUN_0057f050(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0057e100(piVar6[1]);
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


// ==== FUN_0057f110 @ 0x0057f110 ====

void FUN_0057f110(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x18 != 0) {
      iVar1 = (param_2 - iVar1) / 0x18;
      goto LAB_0057f155;
    }
  }
  iVar1 = 0;
LAB_0057f155:
  FUN_0057ecc0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x18;
  return;
}


// ==== FUN_0057f180 @ 0x0057f180 ====

undefined4 FUN_0057f180(void)

{
  return 0x60000040;
}


// ==== FUN_0057f190 @ 0x0057f190 ====

void FUN_0057f190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bdce4;
  FUN_00412dc0();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0057f1c0 @ 0x0057f1c0 ====

void FUN_0057f1c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x18) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x18))) {
    FUN_0057f110(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0057e3a0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x18;
  return;
}


// ==== FUN_0057f250 @ 0x0057f250 ====

void FUN_0057f250(byte param_1)

{
  void *in_ECX;
  
  FUN_0057d7d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0057f270 @ 0x0057f270 ====

undefined4 FUN_0057f270(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe4);
}


// ==== FUN_0057f280 @ 0x0057f280 ====

void FUN_0057f280(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(2,0);
  return;
}


// ==== FUN_0057f2a0 @ 0x0057f2a0 ====

undefined4 FUN_0057f2a0(int *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  int iStack_30;
  uint uStack_2c;
  undefined4 auStack_28 [10];
  
  iVar3 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if ((iVar4 != iVar3) || (*(char *)((int)in_ECX + 0x89) == '\0')) {
    return 0;
  }
  puVar5 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  iVar3 = param_1[2];
  puVar8 = auStack_28;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar4 = param_1[0xe];
  uVar1 = param_1[0xf];
  if ((iVar3 != 0) || (param_1[6] != 1)) {
    if ((iVar3 == 1) && ((param_1[6] == 1 && ((char)in_ECX[0x34] != '\0')))) {
      *(undefined1 *)(in_ECX + 0x34) = 0;
      return 1;
    }
    return 0;
  }
  iStack_30 = iVar4;
  uStack_2c = uVar1;
  if (((char)in_ECX[0x34] != '\0') &&
     (uVar7 = (int)(uVar1 - param_1[0xd]) >> 0x1f, 0 < (int)((uVar1 - param_1[0xd] ^ uVar7) - uVar7)
     )) {
    piVar6 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar6 + 0x80))(7,iVar4 << 0x10 | uVar1);
  }
  cVar2 = FUN_0053bf70(&iStack_30);
  if (cVar2 != '\0') {
    *(undefined1 *)(in_ECX + 0x34) = 1;
  }
  return 1;
}


// ==== FUN_0057f390 @ 0x0057f390 ====

void FUN_0057f390(int param_1)

{
  int *in_ECX;
  
  if (in_ECX[0x31] == param_1) {
    return;
  }
  in_ECX[0x31] = param_1;
                    /* WARNING: Could not recover jumptable at 0x0057f3ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_0057f420 @ 0x0057f420 ====

bool FUN_0057f420(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xec) != 0;
}


// ==== FUN_0057f430 @ 0x0057f430 ====

void FUN_0057f430(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (**(code **)(*piVar1 + 4))();
    *puVar2 = &PTR_FUN_009bde44;
    puVar2[1] = uVar3;
  }
  puVar2[2] = param_1;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
  (**(code **)*puVar2)(1);
  return;
}


// ==== FUN_0057f480 @ 0x0057f480 ====

void FUN_0057f480(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0xe0) != '\x01') &&
     (piVar1 = *(int **)(in_ECX + 0xec), piVar1 != (int *)0x0)) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar3 = (**(code **)(*piVar1 + 4))();
      *puVar2 = &PTR_FUN_009bba08;
      puVar2[1] = uVar3;
      puVar2[3] = 1;
      puVar2[5] = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
    }
    *(undefined1 *)((int)puVar2 + 0x19) = 1;
    puVar2[4] = param_2;
    puVar2[5] = param_1;
    puVar2[2] = 10;
    puVar2[3] = (uint)*(ushort *)(in_ECX + 0xf0);
    *(undefined1 *)(puVar2 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
    (**(code **)*puVar2)(1);
    *(undefined1 *)(in_ECX + 0xe0) = 1;
  }
  return;
}


// ==== FUN_0057f520 @ 0x0057f520 ====

undefined4 FUN_0057f520(void)

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


// ==== FUN_0057f550 @ 0x0057f550 ====

void FUN_0057f550(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    *puVar1 = &PTR_FUN_009bba08;
    puVar1[1] = uVar2;
    puVar1[3] = 1;
    puVar1[5] = 0;
    *(undefined1 *)(puVar1 + 6) = 0;
  }
  *(undefined1 *)((int)puVar1 + 0x19) = 1;
  puVar1[2] = param_1;
  puVar1[4] = param_2;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar1);
  (**(code **)*puVar1)(1);
  return;
}


// ==== FUN_0057f5c0 @ 0x0057f5c0 ====

void FUN_0057f5c0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    *puVar1 = &PTR_FUN_009bba08;
    puVar1[1] = uVar2;
    puVar1[3] = 1;
    puVar1[5] = 0;
    *(undefined1 *)(puVar1 + 6) = 0;
  }
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar1);
  (**(code **)*puVar1)(1);
  return;
}


// ==== FUN_0057f620 @ 0x0057f620 ====

void FUN_0057f620(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xd4) != 0) {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      *puVar1 = &PTR_FUN_009bde2c;
      puVar1[1] = uVar2;
    }
    *(undefined1 *)(puVar1 + 2) = *(undefined1 *)(in_ECX + 0x70);
    (**(code **)(*DAT_00b5ad24 + 4))(puVar1);
    (**(code **)*puVar1)(1);
  }
  return;
}


// ==== FUN_0057f670 @ 0x0057f670 ====

void FUN_0057f670(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x70) != param_1) {
    *(char *)(in_ECX + 0x70) = param_1;
    FUN_0057f620();
  }
  return;
}


// ==== FUN_0057f690 @ 0x0057f690 ====

void FUN_0057f690(void)

{
  int *piVar1;
  int *in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(5,0);
  if (in_ECX[0x31] != 0xffffff) {
    in_ECX[0x31] = 0xffffff;
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  FUN_0057f620();
  return;
}


// ==== FUN_0057f6d0 @ 0x0057f6d0 ====

void FUN_0057f6d0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5ad20 + 0x18))(*(undefined4 *)(in_ECX + 0xe4));
  if (iVar1 == 0x101) {
    FUN_0057f550(7,2000);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5ad20 + 0x60))(*(undefined4 *)(in_ECX + 0xe4));
  if (uVar2 < 7) {
    FUN_0057f550(uVar2,3000);
  }
  else {
    FUN_0057f5c0();
    iVar1 = (**(code **)(*DAT_00b5ad20 + 100))(*(undefined4 *)(in_ECX + 0xe4));
    if (iVar1 != 0) {
      FUN_0057f550(iVar1,2000);
      return;
    }
  }
  return;
}


// ==== FUN_0057f750 @ 0x0057f750 ====

void FUN_0057f750(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bde8c;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x2c] = 0xf;
  in_ECX[0x2b] = 0;
  *(undefined1 *)(in_ECX + 0x27) = 0;
  in_ECX[0x2e] = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)((int)in_ECX + 0xc1) = 0;
  in_ECX[0x2d] = 1;
  in_ECX[0x2f] = 1;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x37] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  in_ECX[0x39] = 0;
  *(undefined1 *)(in_ECX + 0x3a) = 1;
  *(undefined1 *)(in_ECX + 0x38) = 0;
  in_ECX[0x3b] = 0;
  *(undefined2 *)(in_ECX + 0x3c) = 1;
  return;
}


// ==== FUN_0057f810 @ 0x0057f810 ====

void FUN_0057f810(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bde8c;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  if ((uint)in_ECX[0x2c] < 0x10) {
    in_ECX[0x2b] = 0;
    in_ECX[0x2c] = 0xf;
    *(undefined1 *)(in_ECX + 0x27) = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x27]);
  return;
}


// ==== FUN_0057f870 @ 0x0057f870 ====

undefined4 FUN_0057f870(int param_1)

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


// ==== FUN_0057f910 @ 0x0057f910 ====

void FUN_0057f910(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *in_ECX;
  int *unaff_EBX;
  int *unaff_EDI;
  char unaff_retaddr;
  undefined4 uStack_a4;
  undefined4 uStack_88;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  int iStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined1 auStack_2c [4];
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_a4 = 0x57f921;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uStack_a4 = 0x57f932;
  iVar3 = (**(code **)(*DAT_00b5a7ac + 4))();
  in_ECX[0x3b] = iVar3;
  uStack_80._0_3_ = CONCAT12(1,(undefined2)uStack_80);
  uStack_7c = 0;
  uStack_78 = 0;
  iStack_74 = 0;
  iStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  pvStack_48 = (void *)0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  uStack_a4 = 0;
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  FUN_00401740(s_pan_cooltime_009bdda4,0xc);
  uVar5 = FUN_00404230(&pvStack_48);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  FUN_00401660(auStack_2c,0,0xffffffff);
  uStack_7c = 0;
  uStack_78 = 0;
  if (unaff_retaddr == '\x01') {
    iStack_74 = in_ECX[0x1e];
    iStack_70 = in_ECX[0x1f];
    unaff_EBX = piVar2;
  }
  else {
    iStack_74 = in_ECX[0x1e] * in_ECX[0x20];
    iStack_70 = in_ECX[0x1f] * in_ECX[0x21];
    if ((in_ECX[0x20] == 1) && (in_ECX[0x21] == 2)) {
      *(undefined2 *)(in_ECX + 0x3c) = 2;
    }
  }
  uStack_80 = (void *)0x64;
  uStack_84 = 1;
  uStack_83 = 1;
  uStack_88 = 0;
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_cooltime_009bddb4,8);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_48);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  (**(code **)(*(int *)in_ECX[0x3b] + 8))(&uStack_88);
  piVar2 = (int *)in_ECX[0x3b];
  if ((unaff_EBX != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x74))(unaff_EBX), cVar1 != '\0')
     ) {
    cVar1 = (**(code **)(*unaff_EBX + 0x78))(piVar2);
    if (cVar1 == '\0') {
      (**(code **)(*unaff_EDI + 0x74))(0);
    }
    else {
      iVar3 = (**(code **)(*unaff_EBX + 0x38))();
      piVar2[1] = iVar3;
    }
  }
  (**(code **)(*piVar4 + 0x38))(in_ECX[0x3b]);
  (**(code **)(*piVar4 + 0x1c))(&uStack_38);
  (**(code **)(*(int *)in_ECX[0x3b] + 0x2c))(piVar4);
  FUN_00587d40(&uStack_a4);
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    uVar5 = (**(code **)(*(int *)in_ECX[0x3b] + 4))();
    *puVar6 = &PTR_FUN_009bcd68;
    puVar6[1] = uVar5;
  }
  *(undefined1 *)(puVar6 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar6);
  (**(code **)*puVar6)(1);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (uStack_6c < 0x10) {
    return;
  }
  _free(uStack_80);
  return;
}


// ==== FUN_0057fc10 @ 0x0057fc10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057fc10(float param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int in_ECX;
  uint uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_8;
  uint uStack_4;
  
  if (*(int **)(in_ECX + 0xec) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(in_ECX + 0xec) + 0x30))();
    if (iVar3 == 0) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18._1_3_ << 8);
      FUN_00401740(s_pPanel____NULL_009bddc0,0xe);
      FUN_00406880(&pvStack_1c);
      if (uStack_4 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_18);
      return;
    }
    uVar1 = (uint)ROUND((DAT_0099d080 - param_1) * _DAT_009bdee4);
    if (uVar1 != *(uint *)(iVar3 + 0x94)) {
      uStack_24 = *(undefined4 *)(iVar3 + 0x90);
      uStack_20 = *(undefined4 *)(iVar3 + 0x94);
      uStack_28 = 0;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18._1_3_ << 8);
      uStack_2c = uVar1;
      FUN_00401740(s_cooltime_009bddd0,8);
      uStack_28 = (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_1c);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_2c = (uVar1 != 0x23) - 1 & 0xffffff;
      uStack_24 = uVar1;
      FUN_00587d40(&uStack_2c);
    }
  }
  return;
}


// ==== FUN_0057fd50 @ 0x0057fd50 ====

void FUN_0057fd50(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined *puVar5;
  undefined1 auStack_60 [44];
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  
  local_34 = 0;
  local_30 = 0;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  local_8 = 1;
  local_4 = 0;
  local_3 = 0;
  local_10 = 2;
  local_c = 0xffffffff;
  if (in_ECX[0x39] == 0) {
    FUN_00401740(&DAT_009bddd9,0);
    (**(code **)(*in_ECX + 8))(&local_34);
    if (0xf < local_18) {
      _free(local_2c);
      return;
    }
  }
  else {
    iVar3 = (**(code **)(*(int *)in_ECX[0x39] + 0x48))();
    if (iVar3 == 0) {
      puVar5 = &DAT_009bddda;
    }
    else {
      if ((char)in_ECX[0x3a] != '\0') {
        cVar1 = (**(code **)(*DAT_00b5ad20 + 0x50))(in_ECX[0x39]);
        if (cVar1 != '\0') {
          uVar2 = (**(code **)(*DAT_00b5ad20 + 0x54))(in_ECX[0x39]);
          if (uVar2 < 10000) {
            FUN_00401830(&DAT_009bdddc);
            uVar4 = FUN_00404230(auStack_60);
            FUN_00401660(uVar4,0,0xffffffff);
          }
          else {
            FUN_00403810(&DAT_009bdde0);
            FUN_00401830(&DAT_009bdde4);
            uVar4 = FUN_00404230(auStack_60);
            FUN_00401ff0(uVar4,0,0xffffffff);
          }
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      puVar5 = &DAT_009bdddb;
    }
    FUN_00401740(puVar5,0);
    (**(code **)(*in_ECX + 8))(&local_34);
    if (0xf < local_18) {
      _free(local_2c);
      return;
    }
  }
  return;
}


// ==== FUN_0057ffb0 @ 0x0057ffb0 ====

void FUN_0057ffb0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar1 + 0x80))(1,0);
  FUN_0057fc10(0);
  return;
}


// ==== FUN_0057ffe0 @ 0x0057ffe0 ====

void FUN_0057ffe0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_005523f0(param_1);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


