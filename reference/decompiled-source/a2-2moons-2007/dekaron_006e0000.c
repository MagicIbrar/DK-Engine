// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x6e0000-0x6effff

// ==== FUN_006e0000 @ 0x006e0000 ====

int FUN_006e0000(undefined4 param_1,undefined4 param_2)

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
    FUN_00401740(&DAT_009e5e61,0);
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


// ==== __break @ 0x006e006b ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x006e006e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_006e00e0 @ 0x006e00e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e00e0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined8 uVar5;
  undefined1 auStack_46 [10];
  void *apvStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  void *apvStack_20 [5];
  uint uStack_c;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 == 0) {
      return;
    }
    thunk_FUN_005799c0();
    FUN_00404fb0(param_1,0x5f,auStack_46 + -6);
    iVar3 = FUN_00405d30();
    iVar3 = FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009e5e20,4);
    if (iVar3 != 0) {
      uVar4 = FUN_00405d30(1);
      cVar1 = FUN_004036a0(uVar4);
      if (cVar1 == '\0') {
        FUN_00401830(&DAT_009e5e54);
        uVar4 = FUN_00404230(apvStack_3c);
        uVar5 = CONCAT44(uVar4,&DAT_009e5e5c);
        goto LAB_006e020f;
      }
    }
    iVar3 = FUN_00405d30();
    iVar3 = FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009e5e2c,3);
    if (iVar3 != 0) {
      uVar4 = FUN_00405d30(2);
      cVar1 = FUN_004036a0(uVar4);
      if (cVar1 == '\0') {
        FUN_00401830(&DAT_009e5e44);
        uVar4 = FUN_00404230(apvStack_3c);
        uVar5 = CONCAT44(uVar4,&DAT_009e5e4c);
LAB_006e020f:
        uVar4 = FUN_00402220(apvStack_20,param_1,uVar5);
        FUN_006dfef0(uVar4,(int)((ulonglong)uVar5 >> 0x20));
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    FUN_00401830(&DAT_009e5e34);
    uVar4 = FUN_00404230(apvStack_20);
    FUN_00402220(apvStack_3c,param_1,&DAT_009e5e3c);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
      FUN_0055a260(uVar4);
    }
    if (0xf < uStack_28) {
      _free(apvStack_3c[0]);
      return;
    }
    uStack_28 = 0xf;
    uStack_2c = 0;
    apvStack_3c[0] = (void *)((uint)apvStack_3c[0] & 0xffffff00);
    if (0xf < uStack_c) {
      _free(apvStack_20[0]);
      return;
    }
    FUN_00406250();
  }
  return;
}


// ==== FUN_006e0300 @ 0x006e0300 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006e0300(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_46 [10];
  void *apvStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  void *apvStack_20 [5];
  uint uStack_c;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 == 0)) {
    return 0;
  }
  FUN_00404fb0(param_1,0x5f,auStack_46 + -6);
  iVar3 = FUN_00405d30();
  iVar3 = FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009e5e64,3);
  if (iVar3 != 0) {
    uVar4 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar4);
    if (cVar1 == '\0') {
      uVar4 = FUN_00405d30(1);
      cVar1 = FUN_004036a0(uVar4);
      if (cVar1 == '\0') {
        uVar4 = FUN_00405d30(1);
        cVar1 = FUN_004036a0(uVar4);
        if (cVar1 == '\0') {
          FUN_00406250();
          return 0;
        }
      }
    }
  }
  FUN_005796c0();
  iVar3 = FUN_00405d30();
  iVar3 = FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009e5e7c,3);
  if (iVar3 != 0) {
    uVar4 = FUN_00405d30(2);
    cVar1 = FUN_004036a0(uVar4);
    if (cVar1 == '\0') {
      FUN_00401830(&DAT_009e5e94);
      uVar4 = FUN_00404230(apvStack_3c);
      uVar5 = FUN_00402220(apvStack_20,param_1,&DAT_009e5e9c,uVar4);
      FUN_006dfef0(uVar5,uVar4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  FUN_00401830(&DAT_009e5e84);
  uVar4 = FUN_00404230(apvStack_20);
  FUN_00402220(apvStack_3c,param_1,&DAT_009e5e8c);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(uVar4);
  }
  if (0xf < uStack_28) {
    _free(apvStack_3c[0]);
    return extraout_EAX;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  apvStack_3c[0] = (void *)((uint)apvStack_3c[0] & 0xffffff00);
  if (uStack_c < 0x10) {
    uVar4 = FUN_006e11e0(param_1);
    FUN_006e1390(uStack_4,uVar4);
    FUN_00406250();
    return 1;
  }
  _free(apvStack_20[0]);
  return extraout_EAX_00;
}


// ==== FUN_006e0560 @ 0x006e0560 ====

undefined4 FUN_006e0560(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  
  if ((param_1 == 0x14) && (param_3 == 7)) {
    cVar1 = FUN_006e0300(param_2);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006e0590 @ 0x006e0590 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e0590(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))();
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5ae24 + 8))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_cam_v_009e5d88,9);
  FUN_006e00e0(auStack_1c,puVar1[1]);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_cam_h_009e5d94,9);
  FUN_006e00e0(auStack_1c,puVar1[2]);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_cam_d_009e5da0,9);
  FUN_006e00e0(auStack_1c,*puVar1);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_near_d_009e5dac,10);
  FUN_006e00e0(auStack_1c,*puVar2);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_near_min_009e5db8,0xc);
  FUN_006e00e0(auStack_1c,(float)puVar2[2] * _DAT_00b33480 + _DAT_009e5ec8);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_near_max_009e5dc8,0xc);
  FUN_006e00e0(auStack_1c,(float)puVar2[3] * _DAT_00b33480 + _DAT_009e5ec8);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_near_h_009e5dd8,10);
  FUN_006e00e0(auStack_1c,puVar2[4]);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_far_d_009e5de4,9);
  FUN_006e00e0(auStack_1c,puVar2[1]);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_far_min_009e5df0,0xb);
  FUN_006e00e0(auStack_1c,(float)puVar2[2] * _DAT_00b33480 + _DAT_009e5ec8);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_far_max_009e5dfc,0xb);
  FUN_006e00e0(auStack_1c,(float)puVar2[3] * _DAT_00b33480 + _DAT_009e5ec8);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_sld_far_h_009e5e08,9);
  FUN_006e00e0(auStack_1c,puVar2[4]);
  if (uStack_4 < 0x10) {
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_006e0910 @ 0x006e0910 ====

void FUN_006e0910(int *param_1,undefined4 param_2,ushort param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint in_ECX;
  undefined4 *puVar5;
  undefined1 auStack_4d2 [38];
  undefined4 local_4ac;
  undefined1 local_4a6;
  undefined4 local_4a4;
  void *local_4a0;
  undefined4 local_49c;
  int local_498;
  undefined4 local_494;
  undefined4 local_490;
  uint local_48c [2];
  undefined1 local_484;
  undefined1 auStack_47c [4];
  undefined4 uStack_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined1 uStack_364;
  undefined1 uStack_363;
  undefined1 auStack_360 [4];
  undefined4 *puStack_35c;
  undefined4 uStack_10;
  
  if (param_1 != (int *)0x0) {
    local_4a6 = 1;
    local_4a4 = 0;
    local_4a0 = (void *)0x0;
    local_49c = 0;
    local_498 = 0;
    local_494 = 0;
    local_490 = 0;
    local_48c[0] = 0;
    local_470 = 0xf;
    local_474 = 0;
    local_484 = 0;
    local_4ac = 0;
    piVar1 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
    uVar3 = (**(code **)(*param_1 + 0x10))();
    FUN_004fed70(uVar3);
    FUN_00401660(param_2,0,0xffffffff);
    FUN_00401660(local_48c,0,0xffffffff);
    local_4a0 = (void *)((int)local_4a0 + (uint)param_3);
    local_498 = local_498 + (uint)param_3;
    puVar5 = &local_4ac;
    (**(code **)(*piVar1 + 8))();
    (**(code **)(*piVar2 + 0x38))(piVar1);
    (**(code **)(*piVar2 + 0x1c))(auStack_4d2 + -10);
    iVar4 = (**(code **)(*param_1 + 0x30))();
    FUN_00505f10();
    uStack_364 = *(undefined1 *)(iVar4 + 0x7c);
    uStack_363 = *(undefined1 *)(iVar4 + 0x7d);
    if (auStack_360 != (undefined1 *)(iVar4 + 0x80)) {
      FUN_00504490(auStack_47c,*puStack_35c,puStack_35c);
      FUN_005040e0(iVar4 + 0x80);
    }
    uStack_478 = *(undefined4 *)(iVar4 + 0x8c);
    local_474 = *(undefined4 *)(iVar4 + 0x90);
    local_470 = *(undefined4 *)(iVar4 + 0x94);
    (**(code **)(*piVar2 + 0x24))(&uStack_478);
    (**(code **)(*piVar1 + 0x2c))(piVar2);
    iVar4 = (**(code **)(*(int *)puVar5[1] + 0x34))(uStack_10);
    if (iVar4 == 0) {
      FUN_00505d80();
      if (0xf < in_ECX) {
        _free((void *)0x0);
        return;
      }
    }
    else {
      FUN_00557b50(iVar4);
      FUN_00505d80();
      if (0xf < in_ECX) {
        _free((void *)0x0);
        return;
      }
    }
    if (0xf < local_48c[0]) {
      _free(local_4a0);
      return;
    }
  }
  return;
}


// ==== FUN_006e0b50 @ 0x006e0b50 ====

void FUN_006e0b50(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 unaff_retaddr;
  int iVar4;
  undefined1 local_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
  if ((iVar1 != 0) && (1 < (ushort)param_2)) {
    param_2 = param_2 - 1 & 0xffff;
    iVar3 = 0x16;
    do {
      iVar4 = iVar3;
      FUN_00401740(&DAT_009e5d84,2);
      uVar2 = FUN_00404230(auStack_20);
      uVar2 = FUN_00405bd0(local_3c,param_1,uVar2);
      FUN_006e0910(iVar1,unaff_retaddr,uVar2,iVar4);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      iVar3 = iVar3 + 0x16;
      param_2 = param_2 - 1;
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_006e0c50 @ 0x006e0c50 ====

void FUN_006e0c50(void)

{
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pan_cam_base_line_009e5d20,0x11);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_cam_009e5d34,7);
  FUN_006e0b50(local_38,local_1c,3);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pan_near_line_009e5d3c,0xd);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_cam_009e5d4c,7);
  FUN_006e0b50(local_38,local_1c,4);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pan_far_line_009e5d54,0xc);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_cam_009e5d64,7);
  FUN_006e0b50(local_38,local_1c,4);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pan_bloom_line_009e5d6c,0xe);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_etc_009e5d7c,7);
  FUN_006e0b50(local_38,local_1c,3);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (local_4 < 0x10) {
    FUN_006e0590();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006e0e70 @ 0x006e0e70 ====

void FUN_006e0e70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  in_ECX[3] = param_3;
  *in_ECX = &PTR_FUN_009e5ebc;
  in_ECX[1] = param_1;
  in_ECX[4] = 0;
  in_ECX[2] = param_2;
  FUN_006e0c50();
  return;
}


// ==== FUN_006e0eb0 @ 0x006e0eb0 ====

void FUN_006e0eb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5ebc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e0ed0 @ 0x006e0ed0 ====

void FUN_006e0ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6134;
  return;
}


// ==== FUN_006e0ef0 @ 0x006e0ef0 ====

byte FUN_006e0ef0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_sld_amb_r_009e5f08,9);
  if (iVar2 == 0) {
    return 3;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_sld_amb_g_009e5f14,9);
  if (iVar2 == 0) {
    return 4;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_sld_amb_b_009e5f20,9);
  if (iVar2 == 0) {
    return 5;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_dir_r_009e5f2c);
  if (cVar1 != '\0') {
    return 9;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_dir_g_009e5f38);
  if (cVar1 != '\0') {
    return 10;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_dir_b_009e5f44);
  if (cVar1 != '\0') {
    return 0xb;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_dir_x_009e5f50);
  if (cVar1 != '\0') {
    return 6;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_dir_y_009e5f5c);
  if (cVar1 != '\0') {
    return 7;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_dir_z_009e5f68);
  if (cVar1 != '\0') {
    return 8;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_fog_r_009e5f74);
  if (cVar1 != '\0') {
    return 0xc;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_fog_g_009e5f80);
  if (cVar1 != '\0') {
    return 0xd;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_fog_b_009e5f8c);
  if (cVar1 != '\0') {
    return 0xe;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_fog_near_009e5f98);
  if (cVar1 != '\0') {
    return 0xf;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_fog_far_009e5fa8);
  if (cVar1 != '\0') {
    return 0x10;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_shade_d_009e5fb4);
  if (cVar1 != '\0') {
    return 2;
  }
  cVar1 = FUN_004036a0(param_1,s_pan_night_enable_009e5fc0);
  if (cVar1 != '\0') {
    return 0x11;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_bloom_p_009e5fd4);
  if (cVar1 != '\0') {
    return 0x14;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_bloom_w_009e5fe0);
  if (cVar1 != '\0') {
    return 0x15;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_bloom_f_009e5fec);
  if (cVar1 != '\0') {
    return 0x16;
  }
  cVar1 = FUN_004036a0(param_1,s_combo_size_009e5ff8);
  if (cVar1 != '\0') {
    return 0x17;
  }
  cVar1 = FUN_004036a0(param_1,s_pan_bloom_enable_009e6004);
  if (cVar1 != '\0') {
    return 0x18;
  }
  cVar1 = FUN_004036a0(param_1,s_btn_weather_e_009e6018);
  if (cVar1 != '\0') {
    return 0x19;
  }
  cVar1 = FUN_004036a0(param_1,s_combo_weather_s_009e6028);
  if (cVar1 != '\0') {
    return 0x1a;
  }
  cVar1 = FUN_004036a0(param_1,s_edit_weather_time_009e6038);
  if (cVar1 != '\0') {
    return 0x1b;
  }
  cVar1 = FUN_004036a0(param_1,s_pan_weather_enable_009e604c);
  if (cVar1 != '\0') {
    return 0x1c;
  }
  cVar1 = FUN_004036a0(param_1,s_combo_skybox_009e6060);
  if (cVar1 == '\0') {
    cVar1 = FUN_004036a0(param_1,s_pan_skybox_enable_009e6070);
    return -(cVar1 != '\0') & 0x13;
  }
  return 0x12;
}


// ==== FUN_006e11e0 @ 0x006e11e0 ====

byte FUN_006e11e0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_sld_cam_v_009e6084,9);
  if (iVar2 == 0) {
    return 2;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_sld_cam_h_009e6090,9);
  if (iVar2 == 0) {
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_sld_cam_d_009e609c,9);
  if (iVar2 == 0) {
    return 3;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_near_d_009e60a8);
  if (cVar1 != '\0') {
    return 4;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_near_min_009e60b4);
  if (cVar1 != '\0') {
    return 5;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_near_max_009e60c4);
  if (cVar1 != '\0') {
    return 6;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_near_h_009e60d4);
  if (cVar1 != '\0') {
    return 7;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_far_d_009e60e0);
  if (cVar1 != '\0') {
    return 8;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_far_min_009e60ec);
  if (cVar1 != '\0') {
    return 9;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_far_max_009e60f8);
  if (cVar1 != '\0') {
    return 10;
  }
  cVar1 = FUN_004036a0(param_1,s_sld_far_h_009e6104);
  if (cVar1 == '\0') {
    cVar1 = FUN_004036a0(param_1,s_sld_cull_d_009e6110);
    return -(cVar1 != '\0') & 0xc;
  }
  return 0xb;
}


// ==== FUN_006e1340 @ 0x006e1340 ====

void FUN_006e1340(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6134;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e1360 @ 0x006e1360 ====

void FUN_006e1360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6324;
  return;
}


// ==== FUN_006e1390 @ 0x006e1390 ====

void FUN_006e1390(float param_1,undefined4 param_2)

{
  float *pfVar1;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar1 = (float *)(**(code **)(*DAT_00b5a988 + 0xc))();
  fStack_14 = *pfVar1;
  fStack_10 = pfVar1[1];
  fStack_c = pfVar1[2];
  fStack_8 = pfVar1[3];
  fStack_4 = pfVar1[4];
  pfVar1 = (float *)(**(code **)(*DAT_00b5ae24 + 8))();
  fStack_28 = *pfVar1;
  fStack_24 = pfVar1[1];
  fStack_20 = pfVar1[2];
  fStack_1c = pfVar1[3];
  fStack_18 = pfVar1[4];
  switch(param_2) {
  case 1:
    fStack_c = param_1;
    break;
  case 2:
    fStack_10 = param_1;
    break;
  case 3:
    fStack_14 = param_1;
    break;
  case 4:
    fStack_28 = param_1;
    break;
  case 8:
    fStack_24 = param_1;
    break;
  case 9:
    fStack_20 = DAT_00b33534 * param_1;
    break;
  case 10:
    fStack_1c = DAT_00b33534 * param_1;
    break;
  case 0xb:
    fStack_18 = param_1;
  }
  (**(code **)(*DAT_00b5ae24 + 4))(&fStack_28);
  (**(code **)(*DAT_00b5a988 + 0x10))(&fStack_18);
  return;
}


// ==== FUN_006e14e0 @ 0x006e14e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e14e0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  float fVar6;
  float afStack_90 [4];
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined4 uStack_34;
  undefined1 uStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined1 uStack_1c;
  undefined4 uStack_14;
  undefined1 uStack_10;
  
  piVar1 = DAT_00b5ac58;
  pfVar2 = (float *)(**(code **)(*DAT_00b5ac58 + 0x30))();
  pfVar4 = afStack_90;
  for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  switch(param_2) {
  case 1:
    uStack_14 = thunk_FUN_00796fb0(param_1);
    break;
  case 2:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_40 = (float)fVar5;
    break;
  case 3:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_4c = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 4:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_48 = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 5:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_44 = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 6:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_7c = (float)((fVar5 - (float10)_DAT_009e5ccc) * (float10)DAT_00b33534);
    break;
  case 7:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_78 = (float)((fVar5 - (float10)_DAT_009e5ccc) * (float10)DAT_00b33534);
    break;
  case 8:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_74 = (float)((fVar5 - (float10)_DAT_009e5ccc) * (float10)DAT_00b33534);
    break;
  case 9:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_70 = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 10:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_6c = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 0xb:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_68 = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 0xc:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    afStack_90[2] = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 0xd:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    afStack_90[3] = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 0xe:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_80 = (float)(fVar5 * (float10)_DAT_009ae954);
    break;
  case 0xf:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fVar6 = (float)fVar5;
    if ((float10)afStack_90[1] <= fVar5) {
LAB_006e16d7:
      afStack_90[1] = fVar6;
      (**(code **)(*piVar1 + 0x38))(afStack_90);
      return;
    }
    goto LAB_006e1698;
  case 0x10:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fVar6 = (float)fVar5;
    if (afStack_90[0] < fVar6) goto LAB_006e16d7;
LAB_006e1698:
    afStack_90[0] = fVar6;
    (**(code **)(*piVar1 + 0x38))(afStack_90);
    return;
  case 0x11:
    iVar3 = thunk_FUN_00796e60(param_1);
    uStack_10 = iVar3 != 0;
    (**(code **)(*piVar1 + 0x38))(afStack_90);
    return;
  case 0x12:
    uStack_1c = thunk_FUN_00796f50(param_1);
    break;
  case 0x14:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_2c = (float)ABS(fVar5);
    break;
  case 0x15:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_28 = (float)ABS(fVar5);
    break;
  case 0x16:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_24 = (float)ABS(fVar5);
    break;
  case 0x17:
    fVar5 = (float10)thunk_FUN_00796ec0(param_1);
    fStack_20 = DAT_009b8324;
    if ((float)ABS(fVar5) <= DAT_009b8324) {
      fStack_20 = (float)ABS(fVar5);
    }
    (**(code **)(*piVar1 + 0x38))(afStack_90);
    return;
  case 0x18:
    iVar3 = thunk_FUN_00796e60(param_1);
    uStack_30 = iVar3 != 0;
    (**(code **)(*piVar1 + 0x38))(afStack_90);
    return;
  case 0x19:
    uStack_3a = thunk_FUN_00796f80(param_1);
    break;
  case 0x1a:
    uStack_38 = thunk_FUN_00796f80(param_1);
    break;
  case 0x1b:
    uStack_34 = thunk_FUN_00796fb0(param_1);
    break;
  case 0x1c:
    iVar3 = thunk_FUN_00796e60(param_1);
    uStack_3c = iVar3 != 0;
    (**(code **)(*piVar1 + 0x38))(afStack_90);
    return;
  }
  (**(code **)(*piVar1 + 0x38))(afStack_90);
  return;
}


// ==== FUN_006e18d0 @ 0x006e18d0 ====

void FUN_006e18d0(void)

{
                    /* WARNING: Could not recover jumptable at 0x006e18d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac58 + 0x20))();
  return;
}


// ==== FUN_006e18e0 @ 0x006e18e0 ====

void FUN_006e18e0(void)

{
  char cVar1;
  undefined1 local_c0 [4];
  void *local_bc;
  undefined4 local_ac;
  uint local_a8;
  undefined1 local_a4 [4];
  void *local_a0;
  undefined4 local_90;
  uint local_8c;
  undefined1 local_88 [4];
  void *local_84;
  undefined4 local_74;
  uint local_70;
  undefined1 local_6c [4];
  void *local_68;
  undefined4 local_58;
  uint local_54;
  undefined1 local_30 [28];
  undefined4 local_14;
  
  FUN_0089d500();
  local_54 = 0xf;
  local_58 = 0;
  local_68 = (void *)((uint)local_68 & 0xffffff00);
  FUN_00401740(s_File_Load_009e62d4,9);
  FUN_00401660(local_6c,0,0xffffffff);
  if (0xf < local_54) {
    _free(local_68);
    return;
  }
  FUN_00401740(&DAT_009e62e0,4);
  FUN_006e2300();
  local_14 = 1;
  FUN_0089d680();
  local_8c = 0xf;
  local_90 = 0;
  local_a0 = (void *)((uint)local_a0 & 0xffffff00);
  FUN_00401740(s___txt_Light__009e62e8,0xc);
  local_a8 = 0xf;
  local_ac = 0;
  local_bc = (void *)((uint)local_bc & 0xffffff00);
  FUN_00401740(s___txt_009e62f8,5);
  FUN_0089d450(local_a4,local_c0);
  cVar1 = FUN_0089cfb0();
  if (cVar1 == '\0') {
    if (0xf < local_a8) {
      _free(local_bc);
      return;
    }
  }
  else {
    local_70 = 0xf;
    local_74 = 0;
    local_84 = (void *)((uint)local_84 & 0xffffff00);
    FUN_00401660(local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ac58 + 0xc))(local_88);
    if (0xf < local_70) {
      _free(local_84);
      return;
    }
    local_70 = 0xf;
    local_74 = 0;
    local_84 = (void *)((uint)local_84 & 0xffffff00);
    if (0xf < local_a8) {
      _free(local_bc);
      return;
    }
  }
  local_bc = (void *)((uint)local_bc & 0xffffff00);
  if (local_8c < 0x10) {
    local_a8 = 0xf;
    local_ac = 0;
    local_a0 = (void *)((uint)local_a0 & 0xffffff00);
    local_90 = 0;
    local_8c = 0xf;
    FUN_0089d3c0();
    return;
  }
  local_a8 = 0xf;
  local_ac = 0;
  _free(local_a0);
  return;
}


// ==== FUN_006e1ab0 @ 0x006e1ab0 ====

void FUN_006e1ab0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined8 in_stack_fffffd98;
  undefined4 uVar8;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong in_stack_fffffda0;
  double dVar9;
  undefined8 uVar10;
  double dVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined1 local_238 [4];
  void *local_234;
  undefined4 local_224;
  uint local_220;
  undefined **local_218;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  void *pvStack_1f8;
  undefined4 uStack_1e8;
  uint uStack_1e4;
  void *pvStack_1dc;
  undefined4 uStack_1cc;
  uint uStack_1c8;
  undefined1 auStack_1c4 [4];
  void *pvStack_1c0;
  undefined4 uStack_1b0;
  uint uStack_1ac;
  undefined1 auStack_1a8 [4];
  void *pvStack_1a4;
  undefined4 uStack_194;
  uint uStack_190;
  undefined1 auStack_18c [4];
  void *pvStack_188;
  undefined4 uStack_178;
  uint uStack_174;
  undefined1 auStack_170 [4];
  void *pvStack_16c;
  undefined4 uStack_15c;
  uint uStack_158;
  undefined1 auStack_154 [4];
  void *pvStack_150;
  undefined4 uStack_140;
  uint uStack_13c;
  undefined1 auStack_138 [4];
  void *pvStack_134;
  undefined4 uStack_124;
  uint uStack_120;
  undefined1 auStack_11c [4];
  void *pvStack_118;
  undefined4 uStack_108;
  uint uStack_104;
  undefined1 auStack_100 [4];
  void *pvStack_fc;
  undefined4 uStack_ec;
  uint uStack_e8;
  undefined1 auStack_e4 [4];
  void *pvStack_e0;
  undefined4 uStack_d0;
  uint uStack_cc;
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 local_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 local_1c;
  
  uVar8 = (undefined4)((ulonglong)in_stack_fffffd98 >> 0x20);
  FUN_0089d500();
  local_220 = 0xf;
  local_224 = 0;
  local_234 = (void *)((uint)local_234 & 0xffffff00);
  FUN_00401740(s_File_Save_009e6174,9);
  uVar10 = CONCAT44(local_238,0x6e1b03);
  FUN_00401660();
  if (0xf < local_220) {
    _free(local_234);
    return;
  }
  in_stack_fffffda0 = in_stack_fffffda0 & 0xffffffffffffff00;
  FUN_00401740(&DAT_009e6180,4);
  FUN_006e2300();
  local_1c = 0;
  cVar2 = FUN_0089cfb0();
  if (cVar2 != '\0') {
    uVar13 = 0xf00000000;
    in_stack_fffffda0 = in_stack_fffffda0 & 0xffffffffffffff00;
    FUN_00401740(&DAT_009e6188,4);
    uVar6 = CONCAT44(uVar8,local_90);
    FUN_0089d270(local_90,uVar8,in_stack_fffffda0,uVar10,uVar13);
    local_218 = &PTR_FUN_0099d55c;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    iVar3 = (**(code **)(*DAT_00b5ac58 + 0x10))();
    piVar1 = DAT_00b5a740;
    while (DAT_00b5a740 = piVar1, iVar3 != 0) {
      uStack_1e4 = 0xf;
      uStack_1e8 = 0;
      pvStack_1f8 = (void *)((uint)pvStack_1f8 & 0xffffff00);
      FUN_00401740(s_<light>_009e6190,7);
      FUN_00411630();
      if (0xf < uStack_1e4) {
        _free(pvStack_1f8);
        return;
      }
      uStack_1e4 = 0xf;
      uStack_1e8 = 0;
      pvStack_1f8 = (void *)((uint)pvStack_1f8 & 0xffffff00);
      uVar7 = CONCAT35((int3)((ulonglong)uVar6 >> 0x28),(uint5)(uint)uVar6);
      FUN_00401740(s_time__d_009e6198,9);
      puVar4 = auStack_74;
      FUN_00404230(puVar4);
      FUN_00411630();
      if (0xf < uStack_5c) {
        _free(pvStack_70);
        return;
      }
      uStack_5c = 0xf;
      uStack_60 = 0;
      pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
      if (*(float *)(iVar3 + 0x50) != DAT_0099cdc8) {
        dVar11 = (double)*(float *)(iVar3 + 0x50);
        uVar10 = 0xf00000000;
        uVar7 = uVar7 & 0xffffffffffffff00;
        FUN_00401740(s_lightdistance___2f_009e61a4,0x13);
        FUN_00404230(auStack_18c,puVar4,uVar7,in_stack_fffffda0,uVar10,dVar11);
        FUN_00411630();
        if (0xf < uStack_174) {
          _free(pvStack_188);
          return;
        }
        uStack_174 = 0xf;
        uStack_178 = 0;
        pvStack_188 = (void *)((uint)pvStack_188 & 0xffffff00);
      }
      FUN_00401740(s_ambient_color___2f___2f___2f_009e61b8,0x1d);
      FUN_00404230(auStack_e4);
      FUN_00411630();
      if (0xf < uStack_cc) {
        _free(pvStack_e0);
        return;
      }
      uStack_cc = 0xf;
      uStack_d0 = 0;
      pvStack_e0 = (void *)((uint)pvStack_e0 & 0xffffff00);
      FUN_00401740(s_dirlight_color___2f___2f___2f_009e61d8,0x1e);
      FUN_00404230(auStack_154);
      FUN_00411630();
      if (0xf < uStack_13c) {
        _free(pvStack_150);
        return;
      }
      uStack_13c = 0xf;
      uStack_140 = 0;
      pvStack_150 = (void *)((uint)pvStack_150 & 0xffffff00);
      FUN_00401740(s_dirlight_dir___4f___4f___4f_009e61f8,0x1c);
      FUN_00404230(auStack_1c4);
      FUN_00411630();
      if (0xf < uStack_1ac) {
        _free(pvStack_1c0);
        return;
      }
      uStack_1ac = 0xf;
      uStack_1b0 = 0;
      pvStack_1c0 = (void *)((uint)pvStack_1c0 & 0xffffff00);
      FUN_00401740(s_fog_value___2f___2f_009e6218,0x14);
      FUN_00404230(auStack_11c);
      FUN_00411630();
      if (0xf < uStack_104) {
        _free(pvStack_118);
        return;
      }
      uStack_104 = 0xf;
      uStack_108 = 0;
      pvStack_118 = (void *)((uint)pvStack_118 & 0xffffff00);
      FUN_00401740(s_fog_color___2f___2f___2f_009e6230,0x19);
      FUN_00404230(auStack_ac);
      FUN_00411630();
      if (0xf < uStack_94) {
        _free(pvStack_a8);
        return;
      }
      uStack_94 = 0xf;
      uStack_98 = 0;
      pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      FUN_00401740(s_weather_value__d__d__d__d_009e624c,0x1a);
      puVar4 = auStack_1a8;
      FUN_00404230(puVar4);
      FUN_00411630();
      if (0xf < uStack_190) {
        _free(pvStack_1a4);
        return;
      }
      dVar11 = (double)*(float *)(iVar3 + 0x6c);
      uStack_190 = 0xf;
      dVar9 = (double)*(float *)(iVar3 + 0x68);
      uStack_194 = 0;
      pvStack_1a4 = (void *)((uint)pvStack_1a4 & 0xffffff00);
      uVar5 = SUB84((double)*(float *)(iVar3 + 100),0);
      FUN_00401740(s_bloom_value__d___2f___2f___2f____009e6268,0x23);
      FUN_00404230(auStack_170);
      FUN_00411630();
      if (0xf < uStack_158) {
        _free(pvStack_16c);
        return;
      }
      uVar10 = CONCAT44((uint)*(byte *)(iVar3 + 0x74),0xf);
      uVar12 = (ulonglong)dVar11 & 0xffffffff;
      uStack_158 = 0xf;
      uStack_15c = 0;
      pvStack_16c = (void *)((uint)pvStack_16c & 0xffffff00);
      uVar7 = (ulonglong)uVar5;
      uVar5 = 0x6e2051;
      FUN_00401740(s_sky_type__d_009e628c,0xc);
      FUN_00404230(auStack_138,uVar7,dVar9,uVar12,uVar10);
      FUN_00411630();
      if (0xf < uStack_120) {
        _free(pvStack_134);
        return;
      }
      in_stack_fffffda0 = CONCAT44((uint)*(byte *)(iVar3 + 0x75),0xf);
      uVar7 = uVar7 & 0xffffffff;
      uStack_120 = 0xf;
      uStack_124 = 0;
      pvStack_134 = (void *)((uint)pvStack_134 & 0xffffff00);
      uVar5 = uVar5 & 0xffffff00;
      FUN_00401740(s_cloud_type__d__d__d__d__d_009e629c,0x1a);
      FUN_00404230(auStack_100,puVar4,uVar5);
      FUN_00411630();
      if (0xf < uStack_e8) {
        _free(pvStack_fc);
        return;
      }
      uStack_e8 = 0xf;
      uStack_ec = 0;
      pvStack_fc = (void *)((uint)pvStack_fc & 0xffffff00);
      uVar6 = CONCAT35((int3)(uVar7 >> 0x28),(uint5)(uint)uVar7);
      FUN_00401740(s_night__d_009e62b8,10);
      FUN_00404230(auStack_c8);
      FUN_00411630();
      if (0xf < uStack_b0) {
        _free(pvStack_c4);
        return;
      }
      uStack_b0 = 0xf;
      uStack_b4 = 0;
      pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
      uStack_1c8 = 0xf;
      uStack_1cc = 0;
      pvStack_1dc = (void *)((uint)pvStack_1dc & 0xffffff00);
      FUN_00401740(s_<_light>_009e62c4,8);
      FUN_00411630();
      if (0xf < uStack_1c8) {
        _free(pvStack_1dc);
        return;
      }
      uStack_1c8 = 0xf;
      uStack_1cc = 0;
      pvStack_1dc = (void *)((uint)pvStack_1dc & 0xffffff00);
      local_220 = 0xf;
      local_224 = 0;
      local_234 = (void *)((uint)local_234 & 0xffffff00);
      FUN_00401740(&DAT_009e62d0,1);
      FUN_00411630();
      if (0xf < local_220) {
        _free(local_234);
        return;
      }
      local_220 = 0xf;
      local_224 = 0;
      local_234 = (void *)((uint)local_234 & 0xffffff00);
      iVar3 = (**(code **)(*DAT_00b5ac58 + 0x14))();
      piVar1 = DAT_00b5a740;
    }
    local_220 = 0xf;
    local_224 = 0;
    local_234 = (void *)((uint)local_234 & 0xffffff00);
    FUN_00401660();
    (**(code **)(*piVar1 + 0xc))(local_238);
    if (0xf < local_220) {
      _free(local_234);
      return;
    }
    FUN_004137c0();
    if (0xf < uStack_78) {
      _free(pvStack_8c);
      return;
    }
    uStack_78 = 0xf;
    uStack_7c = 0;
    pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  }
  FUN_0089d3c0();
  return;
}


// ==== FUN_006e22e0 @ 0x006e22e0 ====

void FUN_006e22e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6324;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e2300 @ 0x006e2300 ====

void FUN_006e2300(undefined1 param_1)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  void *unaff_EBX;
  void *unaff_retaddr;
  uint in_stack_00000014;
  undefined1 local_54 [4];
  undefined1 local_50;
  uint uStack_44;
  undefined4 local_40;
  void *local_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_20;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  uint uStack_c;
  
  local_3c = (void *)0xf;
  local_40 = 0;
  local_50 = 0;
  pcVar2 = PTR_s_DataPath_00b33530;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_DataPath_00b33530,(int)pcVar2 - (int)(PTR_s_DataPath_00b33530 + 1));
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_1c,local_54,&param_1);
  uVar4 = FUN_00405bd0(&local_40,uVar4);
  FUN_00401660(uVar4,0,0xffffffff);
  if (0xf < uStack_28) {
    _free(local_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (0xf < uStack_44) {
    _free(unaff_EBX);
    return;
  }
  if (in_stack_00000014 < 0x10) {
    return;
  }
  _free(unaff_retaddr);
  return;
}


// ==== FUN_006e23f0 @ 0x006e23f0 ====

undefined4 FUN_006e23f0(void)

{
  return 0x70130006;
}


// ==== FUN_006e2400 @ 0x006e2400 ====

void FUN_006e2400(void)

{
  return;
}


// ==== FUN_006e2410 @ 0x006e2410 ====

undefined1 FUN_006e2410(void)

{
  return 0;
}


// ==== FUN_006e2520 @ 0x006e2520 ====

void FUN_006e2520(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  
  uVar1 = param_1[1];
  uVar2 = *param_1;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x44))();
  if (piVar3[1] != 0) {
    iVar4 = (**(code **)(*piVar3 + 0x14))();
    if (iVar4 != 10) {
      iVar4 = (**(code **)(*piVar3 + 0x14))();
      if (iVar4 != 0x7b) {
        (**(code **)(*(int *)piVar3[1] + 0x54))(uVar2,uVar1,1);
        return;
      }
    }
    (**(code **)(*(int *)piVar3[1] + 0x54))(uVar2,uVar1,0);
  }
  return;
}


// ==== FUN_006e2580 @ 0x006e2580 ====

void FUN_006e2580(void)

{
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e661c;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_stat_increase_009e639c,0xd);
  (**(code **)(*DAT_00b5a7d8 + 8))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x15])(1);
  }
  in_ECX[0x15] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006e2610 @ 0x006e2610 ====

void FUN_006e2610(undefined4 param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  piVar4 = *(int **)(param_2 + 0x24);
  if (piVar4 == (int *)0x0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_pSuit____NULL_009e6564,0xd);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  piVar3 = (int *)(**(code **)(*piVar4 + 0x2c))(4);
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))(5);
  iVar7 = **(int **)(param_2 + 0x50);
  iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar6 = (int *)(**(code **)(iVar7 + 0x14))(iVar5 + 2);
  piVar6 = (int *)(**(code **)(*piVar6 + 0x1c))();
  if (piVar3 == (int *)0x0) {
LAB_006e26d2:
    if (piVar4 == (int *)0x0) goto LAB_006e280e;
    iVar7 = (**(code **)(*piVar4 + 0x2c))();
    uVar1 = *(uint *)(iVar7 + 8);
    if (((uVar1 >> 8 != 4) || (uVar1 == 0x40f)) || ((uVar1 == 0x410 || (uVar1 == 0x40e))))
    goto LAB_006e280e;
    piVar3 = (int *)(**(code **)(*piVar4 + 0x48))();
    iVar7 = (**(code **)(*piVar3 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x40a) goto LAB_006e290f;
    piVar3 = (int *)(**(code **)(*piVar4 + 0x48))();
    iVar7 = (**(code **)(*piVar3 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x40b) goto LAB_006e290f;
    piVar3 = (int *)(**(code **)(*piVar4 + 0x48))();
    iVar7 = (**(code **)(*piVar3 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x40f) goto LAB_006e290f;
    iVar7 = *piVar4;
  }
  else {
    iVar7 = (**(code **)(*piVar3 + 0x2c))();
    uVar1 = *(uint *)(iVar7 + 8);
    if ((((uVar1 >> 8 != 4) || (uVar1 == 0x40f)) || (uVar1 == 0x410)) || (uVar1 == 0x40e))
    goto LAB_006e26d2;
    if (piVar4 != (int *)0x0) {
      iVar7 = (**(code **)(*piVar4 + 0x2c))();
      uVar1 = *(uint *)(iVar7 + 8);
      if (((uVar1 >> 8 == 4) && (uVar1 != 0x40f)) && ((uVar1 != 0x410 && (uVar1 != 0x40e)))) {
        piVar8 = (int *)(**(code **)(*piVar3 + 0x48))();
        iVar7 = (**(code **)(*piVar8 + 4))();
        if (*(int *)(iVar7 + 0xc) != 0x40a) {
          piVar8 = (int *)(**(code **)(*piVar4 + 0x48))();
          iVar7 = (**(code **)(*piVar8 + 4))();
          if (*(int *)(iVar7 + 0xc) != 0x40a) {
            piVar8 = (int *)(**(code **)(*piVar3 + 0x48))();
            iVar7 = (**(code **)(*piVar8 + 4))();
            if (*(int *)(iVar7 + 0xc) != 0x40b) {
              piVar8 = (int *)(**(code **)(*piVar4 + 0x48))();
              iVar7 = (**(code **)(*piVar8 + 4))();
              if (*(int *)(iVar7 + 0xc) != 0x40b) {
                piVar8 = (int *)(**(code **)(*piVar3 + 0x48))();
                iVar7 = (**(code **)(*piVar8 + 4))();
                if (*(int *)(iVar7 + 0xc) != 0x40f) {
                  piVar8 = (int *)(**(code **)(*piVar4 + 0x48))();
                  iVar7 = (**(code **)(*piVar8 + 4))();
                  if (*(int *)(iVar7 + 0xc) != 0x40f) {
                    piVar3 = (int *)(**(code **)(*piVar3 + 0x48))();
                    iVar7 = (**(code **)(*piVar3 + 4))();
                    if (*(int *)(iVar7 + 0xc) != 0x412) {
                      piVar4 = (int *)(**(code **)(*piVar4 + 0x48))();
                      iVar7 = (**(code **)(*piVar4 + 4))();
                      if (*(int *)(iVar7 + 0xc) != 0x412) {
                        iVar7 = *piVar6;
                        if (piVar6[2] < *piVar6) {
                          iVar7 = piVar6[2];
                        }
                        iVar5 = piVar6[3];
                        if (piVar6[3] < piVar6[1]) {
                          iVar5 = piVar6[1];
                        }
                        *(int *)(local_8 + 0x14) = iVar7;
                        *(int *)(local_8 + 0x18) = iVar5;
                        return;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_006e290f;
      }
    }
    piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
    iVar7 = (**(code **)(*piVar4 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x40a) goto LAB_006e290f;
    piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
    iVar7 = (**(code **)(*piVar4 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x40b) goto LAB_006e290f;
    piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
    iVar7 = (**(code **)(*piVar4 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x40f) goto LAB_006e290f;
    iVar7 = *piVar3;
  }
  piVar4 = (int *)(**(code **)(iVar7 + 0x48))();
  iVar7 = (**(code **)(*piVar4 + 4))();
  if (*(int *)(iVar7 + 0xc) == 0x412) {
LAB_006e290f:
    *(int *)(local_8 + 0x14) = piVar6[6];
    *(int *)(local_8 + 0x18) = piVar6[7];
    return;
  }
LAB_006e280e:
  *(int *)(local_8 + 0x14) = piVar6[4];
  *(int *)(local_8 + 0x18) = piVar6[5];
  return;
}


// ==== FUN_006e2930 @ 0x006e2930 ====

void FUN_006e2930(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  uint uStack_74;
  short sStack_6e;
  short sStack_6c;
  short sStack_6a;
  short local_68 [2];
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_54;
  short sStack_4c;
  int iStack_48;
  int iStack_40;
  short sStack_3a;
  short sStack_38;
  short sStack_36;
  short sStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_20;
  short sStack_18;
  int iStack_14;
  int iStack_c;
  
  (**(code **)(*DAT_00b5aea0 + 0x1c))(local_68);
  (**(code **)(*DAT_00b5aea0 + 0x18))(&sStack_38);
  FUN_00401740(s__d__d_009e6574,5);
  uVar1 = FUN_00404230(auStack_8c);
  if (*(int **)(in_ECX + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar3 = 0;
  FUN_00401740(s__d__d_009e657c,5);
  uVar1 = FUN_00404230(auStack_8c);
  if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x3c) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e6584,2);
  puVar2 = auStack_8c;
  uVar1 = FUN_00404230(puVar2,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar3 = 0;
  FUN_00401740(s__d__d_009e6588,5);
  uVar1 = FUN_00404230(auStack_8c,puVar2,uVar3);
  if (*(int **)(in_ECX + 0x4c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x4c) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e6590,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e6594,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e6598,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e659c,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    FUN_00559170(0xffffffff);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65a0,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
    if (sStack_6e == sStack_3a) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65a4,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x30))();
    if (sStack_6c == sStack_38) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65a8,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x14) + 0x30))();
    if (sStack_6a == sStack_36) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65ac,2);
  puVar2 = auStack_8c;
  uVar1 = FUN_00404230(puVar2,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x18) + 0x30))();
    if (local_68[0] == sStack_34) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar3 = 0;
  FUN_00401740(s__d__d_009e65b0,5);
  uVar1 = FUN_00404230(auStack_8c,puVar2,uVar3);
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x38) + 0x30))();
    if (iStack_5c == iStack_28) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar3 = 0;
  FUN_00401740(s__d__d_009e65b8,5);
  uVar1 = FUN_00404230(auStack_8c,puVar2,uVar3);
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x30))();
    if (iStack_54 == iStack_20) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65c0,2);
  puVar2 = auStack_8c;
  uVar1 = FUN_00404230(puVar2,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x48) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x48) + 0x30))();
    if (sStack_4c == sStack_18) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar3 = 0;
  FUN_00401740(s__d__d_009e65c4,5);
  uVar1 = FUN_00404230(auStack_8c,puVar2,uVar3);
  if (*(int **)(in_ECX + 0x50) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x30))();
    if (iStack_48 == iStack_14) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65cc,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x30))();
    if (iStack_64 == iStack_30) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65d0,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))();
    if (iStack_60 == iStack_2c) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return;
  }
  uVar4 = 0;
  FUN_00401740(&DAT_009e65d4,2);
  uVar1 = FUN_00404230(auStack_8c,uVar3,uVar4);
  if (*(int **)(in_ECX + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x30) + 0x30))();
    if (iStack_40 == iStack_c) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0xff00ffff;
    }
    FUN_00559170(uVar5);
    FUN_0055a260(uVar1);
  }
  if (uStack_74 < 0x10) {
    return;
  }
  _free(pvStack_88);
  return;
}


// ==== FUN_006e3260 @ 0x006e3260 ====

void FUN_006e3260(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined2 *in_ECX;
  undefined4 unaff_retaddr;
  int iStack_c;
  
  piVar3 = *(int **)(param_2 + 0x50);
  iVar5 = *piVar3;
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar5 + 0x18))(iVar2 + 1);
  iVar5 = *piVar3;
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(iVar5 + 0x14))(iVar2 + 2);
  puVar4 = (undefined2 *)(**(code **)(*piVar3 + 0x14))();
  iVar5 = (**(code **)(*piVar3 + 0x1c))();
  puVar6 = (undefined2 *)(**(code **)(*piVar3 + 0x34))();
  puVar7 = (undefined4 *)(**(code **)(*piVar3 + 0x20))();
  iVar2 = (**(code **)(*piVar3 + 0x18))();
  *(int *)(in_ECX + 6) = (int)*(float *)(iVar2 + 0xc);
  *(int *)(in_ECX + 8) = (int)*(float *)(iVar2 + 0x10);
  *(undefined4 *)(in_ECX + 0xe) = *(undefined4 *)(iVar5 + 0x20);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar5 + 0x24);
  *(undefined4 *)(in_ECX + 0x14) = *puVar7;
  *(undefined4 *)(in_ECX + 0x16) = puVar7[1];
  in_ECX[0x12] = *puVar6;
  puVar6 = (undefined2 *)(**(code **)(**(int **)(*(int *)(iStack_c + 0x54) + 0xc) + 0x14))();
  *in_ECX = *puVar6;
  in_ECX[1] = *puVar4;
  in_ECX[2] = puVar4[1];
  in_ECX[4] = puVar4[3];
  in_ECX[3] = puVar4[2];
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar1 == '\x01') {
    iVar5 = (**(code **)(*piVar3 + 0x18))();
    *(int *)(in_ECX + 0x18) = (int)*(float *)(iVar5 + 0x14);
  }
  FUN_006e2610(in_ECX,unaff_retaddr);
  return;
}


// ==== FUN_006e3380 @ 0x006e3380 ====

void FUN_006e3380(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined1 auStack_68 [2];
  undefined1 auStack_66 [2];
  undefined4 auStack_64 [10];
  undefined1 auStack_3c [60];
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5aea0 + 0x1c))(auStack_68);
    FUN_006e3260(auStack_68 + -4,iVar1);
    (**(code **)(*DAT_00b5aea0 + 0x14))(auStack_68 + -4);
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5aea0 + 0x18))(auStack_3c);
    puVar3 = (undefined4 *)(auStack_68 + -0xc);
    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_006e3260(auStack_68 + -0xc,*(undefined4 *)(in_ECX + 0x54));
    (**(code **)(*DAT_00b5aea0 + 0x10))(auStack_68 + -0xc);
    FUN_006e2930();
  }
  return;
}


// ==== FUN_006e3420 @ 0x006e3420 ====

undefined4 FUN_006e3420(int param_1)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 uVar5;
  undefined4 extraout_EAX_02;
  int *piVar6;
  ushort *puVar7;
  undefined4 extraout_EAX_03;
  short *psVar8;
  int iVar9;
  int in_ECX;
  ushort uVar10;
  short unaff_SI;
  short unaff_DI;
  short unaff_retaddr;
  undefined4 uStack_54;
  void *local_50;
  void *pvStack_4c;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [52];
  
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_stat_increase_009e65d8,0xd);
  if (iVar3 != 0) {
    return 0;
  }
  uVar4 = FUN_00459160(&local_50,0);
  FUN_00796f80(uVar4);
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return extraout_EAX;
  }
  uVar4 = FUN_00459160(&local_50,1);
  FUN_00796f80(uVar4);
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return extraout_EAX_00;
  }
  uVar4 = FUN_00459160(&local_50,2);
  uVar4 = FUN_00796f80(uVar4);
  uStack_54 = uVar4;
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return extraout_EAX_01;
  }
  uVar5 = FUN_00459160(&local_50,3);
  sVar2 = FUN_00796f80(uVar5);
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return extraout_EAX_02;
  }
  (**(code **)(*DAT_00b5aea0 + 0x1c))(auStack_34);
  piVar1 = *(int **)(*(int *)(in_ECX + 0x54) + 0xc);
  piVar6 = (int *)(**(code **)(*piVar1 + 0x24))();
  uVar10 = sVar2 + (short)uVar4 + unaff_SI + unaff_retaddr;
  puVar7 = (ushort *)(**(code **)(*piVar1 + 0x14))();
  if (uVar10 <= *puVar7) {
    iVar3 = *piVar6;
    psVar8 = (short *)(**(code **)(iVar3 + 0xc))();
    (**(code **)(iVar3 + 0x14))(*psVar8 + unaff_retaddr);
    iVar3 = *piVar6;
    iVar9 = (**(code **)(iVar3 + 0xc))();
    (**(code **)(iVar3 + 0x18))(*(short *)(iVar9 + 2) + unaff_DI);
    iVar3 = *piVar6;
    iVar9 = (**(code **)(iVar3 + 0xc))();
    (**(code **)(iVar3 + 0x20))(*(short *)(iVar9 + 6) + unaff_DI);
    iVar3 = *piVar6;
    iVar9 = (**(code **)(iVar3 + 0xc))();
    (**(code **)(iVar3 + 0x1c))(*(short *)(iVar9 + 4) + unaff_DI);
    iVar3 = *piVar1;
    psVar8 = (short *)(**(code **)(iVar3 + 0x14))();
    (**(code **)(iVar3 + 0x18))(*psVar8 - uVar10);
    return 1;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_greater_than_statpoint_009e65e8,0x16);
  FUN_00796d20(&uStack_54);
  if (uStack_3c < 0x10) {
    return 1;
  }
  _free(local_50);
  return extraout_EAX_03;
}


// ==== FUN_006e3620 @ 0x006e3620 ====

/* WARNING: Removing unreachable block (ram,0x006e3840) */
/* WARNING: Removing unreachable block (ram,0x006e37c2) */
/* WARNING: Removing unreachable block (ram,0x006e3801) */
/* WARNING: Removing unreachable block (ram,0x006e387f) */
/* WARNING: Removing unreachable block (ram,0x006e3783) */
/* WARNING: Removing unreachable block (ram,0x006e3705) */
/* WARNING: Removing unreachable block (ram,0x006e36c6) */
/* WARNING: Removing unreachable block (ram,0x006e3744) */
/* WARNING: Removing unreachable block (ram,0x006e3668) */

void FUN_006e3620(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint in_ECX;
  undefined1 auStackY_10c [128];
  undefined1 *_Memory;
  undefined1 *_Memory_00;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *_Memory_01;
  undefined1 *_Memory_02;
  undefined4 *_Memory_03;
  uint *_Memory_04;
  undefined4 *_Memory_05;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uVar6;
  undefined1 auStack_1e [30];
  
  uStack_38 = s_UI_Game2_CharWindow_ui_statesett_009e63ac;
  uStack_3c = 0x6e364c;
  FUN_00401740();
  uStack_38 = (char *)0x6e3656;
  iVar1 = FUN_00410500();
  uStack_38 = (char *)(iVar1 + 0x3c);
  uStack_3c = 0x6e3689;
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar2;
  uStack_40 = (undefined1 *)0x6e3694;
  uStack_3c = in_ECX;
  (**(code **)(*piVar2 + 0x40))();
  uStack_40 = (undefined1 *)0xd;
  FUN_00401740();
  uStack_40 = auStack_1e + -10;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00401740();
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  FUN_00401740();
  puVar5 = auStack_1e + -0x12;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  FUN_00401740();
  puVar4 = auStack_1e + -0x16;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  FUN_00401740();
  _Memory_05 = &uStack_38;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  uStack_38 = (char *)((uint)uStack_38 & 0xffffff00);
  FUN_00401740();
  _Memory_04 = &uStack_3c;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  uStack_3c = uStack_3c & 0xffffff00;
  FUN_00401740();
  _Memory_03 = &uStack_40;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  uStack_40 = (undefined1 *)((uint)uStack_40 & 0xffffff00);
  FUN_00401740();
  _Memory_02 = auStack_1e + -0x26;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  uVar6 = 0;
  FUN_00401740();
  _Memory_01 = auStack_1e + -0x2a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  if (0xf < uVar6) {
    _free(puVar5);
    return;
  }
  uStack_38 = (char *)0x0;
  FUN_00401740();
  puVar5 = auStack_1e + -0x2e;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  if (0xf < uStack_38) {
    _free(puVar4);
    return;
  }
  uStack_38 = (char *)0xf;
  uStack_3c = 0;
  FUN_00401740();
  puVar4 = auStack_1e + -0x32;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  if (0xf < uStack_3c) {
    _free(_Memory_05);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = (undefined1 *)0x0;
  FUN_00401740();
  _Memory_00 = auStack_1e + -0x36;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  if (0xf < uStack_40) {
    _free(_Memory_04);
    return;
  }
  uStack_40 = (undefined1 *)0xf;
  uVar6 = 0;
  FUN_00401740(s_lbl_damage_after_009e6484);
  _Memory = auStackY_10c + 0xb4;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  if (0xf < uVar6) {
    _free(_Memory_03);
    return;
  }
  uVar6 = 0;
  FUN_00401740(s_lbl_magicdamage_before_009e6498,0x16);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_10c + 0xb0);
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  if (0xf < uVar6) {
    _free(_Memory_02);
    return;
  }
  uVar6 = 0;
  FUN_00401740(s_lbl_magicdamage_after_009e64b0,0x15);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_10c + 0xac);
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  if (0xf < uVar6) {
    _free(_Memory_01);
    return;
  }
  uVar6 = 0;
  FUN_00401740(s_lbl_defense_before_009e64c8,0x12);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_10c + 0xa8);
  *(undefined4 *)(in_ECX + 0x4c) = uVar3;
  if (0xf < uVar6) {
    _free(puVar5);
    return;
  }
  uVar6 = 0;
  FUN_00401740(s_lbl_defense_after_009e64dc,0x11);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_10c + 0xa4);
  *(undefined4 *)(in_ECX + 0x50) = uVar3;
  if (0xf < uVar6) {
    _free(puVar4);
    return;
  }
  uVar6 = 0;
  FUN_00401740(s_lbl_damagerate_before_009e64f0,0x15);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_10c + 0xa0);
  *(undefined4 *)(in_ECX + 0x44) = uVar3;
  if (0xf < uVar6) {
    _free(_Memory_00);
    return;
  }
  uVar6 = 0;
  FUN_00401740(s_lbl_damagerate_after_009e6508,0x14);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_10c + 0x9c);
  *(undefined4 *)(in_ECX + 0x48) = uVar3;
  if (uVar6 < 0x10) {
    FUN_006e3380();
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006e3b50 @ 0x006e3b50 ====

undefined4 FUN_006e3b50(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_006e3380();
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_006e3420(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006e3b90 @ 0x006e3b90 ====

void FUN_006e3b90(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 *in_ECX;
  int iVar7;
  uint *puVar8;
  undefined4 uStack_f8;
  void *pvStack_f0;
  void *pvStack_ec;
  undefined1 auStack_e8 [4];
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined1 local_d8 [4];
  undefined1 local_d4;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_b4;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 local_9c [4];
  void *local_98;
  uint local_88 [33];
  
  uStack_f8 = local_88 + 0x21;
  *in_ECX = &PTR_FUN_009e661c;
  in_ECX[1] = 0;
  local_88[1] = 0xf;
  local_88[0] = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  FUN_00401740(s_stat_increase_009e6364,0xd);
  local_c0 = 0xf;
  local_c4 = 0;
  local_d4 = 0;
  FUN_00401660(local_9c,0,0xffffffff);
  local_bc = 4;
  local_bb = 4;
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4 = 0;
  FUN_00401740(&DAT_0099cf70,0);
  if (0xf < local_88[1]) {
    _free(local_98);
    return;
  }
  FUN_00401740(s_stat_increase__str___dex___con____009e6374,0x25);
  (**(code **)(*DAT_00b5a7d8 + 4))(local_d8);
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_e0 = uVar3;
    pvVar4 = operator_new(0x174);
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_0062f3b0();
    }
    in_ECX[0x15] = uVar5;
    (**(code **)(*piVar2 + 0x78))(uVar3);
    puVar6 = (uint *)(**(code **)(*piVar2 + 0x74))();
    puVar8 = local_88;
    for (iVar7 = 0x1e; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    (**(code **)(*(int *)in_ECX[0x15] + 0x18))(local_88,uStack_e4);
    iVar7 = *(int *)in_ECX[0x15];
    uVar3 = (**(code **)(*piVar2 + 8))();
    (**(code **)(iVar7 + 0xc))(uVar3);
    uStack_f8 = (uint *)0x400;
    operator_new(0x400);
    sVar1 = (**(code **)(*DAT_00b5aa18 + 0x10))(&uStack_f8,piVar2);
    if (sVar1 != 0) {
      (**(code **)(*(int *)in_ECX[0x15] + 0x20))(auStack_e8);
      pvStack_f0 = operator_new(0x400);
      sVar1 = (**(code **)(*DAT_00b5aa18 + 0x70))(auStack_e8 + -0xc,piVar2);
      if (sVar1 != 0) {
        (**(code **)(*(int *)in_ECX[0x15] + 0x50))(&pvStack_f0);
        piVar2 = (int *)(**(code **)(*(int *)in_ECX[0x15] + 0x10))();
        (**(code **)(*piVar2 + 0x28))(uStack_e4);
        _free(pvStack_ec);
        return;
      }
    }
  }
  FUN_0040bf20();
  return;
}


// ==== FUN_006e3da0 @ 0x006e3da0 ====

/* WARNING: Removing unreachable block (ram,0x006e3f56) */
/* WARNING: Removing unreachable block (ram,0x006e3dfb) */
/* WARNING: Removing unreachable block (ram,0x006e3e22) */
/* WARNING: Removing unreachable block (ram,0x006e3e3f) */
/* WARNING: Removing unreachable block (ram,0x006e3e54) */
/* WARNING: Removing unreachable block (ram,0x006e3e8c) */
/* WARNING: Removing unreachable block (ram,0x006e3ec0) */
/* WARNING: Removing unreachable block (ram,0x006e3ef4) */
/* WARNING: Removing unreachable block (ram,0x006e3f11) */
/* WARNING: Removing unreachable block (ram,0x006e3edd) */
/* WARNING: Removing unreachable block (ram,0x006e3ea9) */
/* WARNING: Removing unreachable block (ram,0x006e3e73) */
/* WARNING: Removing unreachable block (ram,0x006e3f26) */
/* WARNING: Removing unreachable block (ram,0x006e3f4e) */
/* WARNING: Removing unreachable block (ram,0x006e3f74) */
/* WARNING: Removing unreachable block (ram,0x006e3f7d) */
/* WARNING: Removing unreachable block (ram,0x006e40fe) */
/* WARNING: Removing unreachable block (ram,0x006e3f9e) */
/* WARNING: Removing unreachable block (ram,0x006e3ff0) */
/* WARNING: Removing unreachable block (ram,0x006e4042) */
/* WARNING: Removing unreachable block (ram,0x006e408d) */
/* WARNING: Removing unreachable block (ram,0x006e40aa) */
/* WARNING: Removing unreachable block (ram,0x006e40c1) */
/* WARNING: Removing unreachable block (ram,0x006e405f) */
/* WARNING: Removing unreachable block (ram,0x006e4076) */
/* WARNING: Removing unreachable block (ram,0x006e400d) */
/* WARNING: Removing unreachable block (ram,0x006e4028) */
/* WARNING: Removing unreachable block (ram,0x006e3fbd) */
/* WARNING: Removing unreachable block (ram,0x006e3fd7) */
/* WARNING: Removing unreachable block (ram,0x006e40d6) */
/* WARNING: Removing unreachable block (ram,0x006e40ea) */

void FUN_006e3da0(void)

{
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_42 [14];
  undefined1 local_34 [52];
  
  (**(code **)(*DAT_00b5aea0 + 0x1c))(local_34);
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x54) + 0xc) + 0x24))();
  FUN_00404fb0(unaff_retaddr,0x5f,auStack_42 + -6);
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_006e4110 @ 0x006e4110 ====

undefined4 FUN_006e4110(int param_1,int param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_apply_009e6520,9);
  piVar1 = DAT_00b5aea0;
  if (iVar3 == 0) {
    iVar3 = *DAT_00b5ae98;
    uVar4 = (**(code **)(*DAT_00b5aea0 + 0x2c))();
    uVar4 = (**(code **)(*piVar1 + 0x28))(uVar4);
    uVar4 = (**(code **)(*piVar1 + 0x24))(uVar4);
    uVar4 = (**(code **)(*piVar1 + 0x20))(uVar4);
    (**(code **)(iVar3 + 0x1c))(uVar4);
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_btn_exit_009e652c);
  if (cVar2 == '\0') {
    cVar2 = FUN_006e3da0(param_2);
    if (cVar2 != '\x01') {
      return 0;
    }
  }
  else {
    puVar5 = operator_new(4);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &PTR_FUN_009e6608;
      FUN_00797a20(puVar5);
      return 1;
    }
    FUN_00797a20(0);
  }
  return 1;
}


// ==== FUN_006e41f0 @ 0x006e41f0 ====

undefined4 FUN_006e41f0(void)

{
  return 0xe;
}


// ==== FUN_006e4200 @ 0x006e4200 ====

void FUN_006e4200(byte param_1)

{
  void *in_ECX;
  
  FUN_006e2580();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e4220 @ 0x006e4220 ====

void FUN_006e4220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e674c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e4240 @ 0x006e4240 ====

undefined1 FUN_006e4240(void)

{
  return 0;
}


// ==== FUN_006e4280 @ 0x006e4280 ====

void FUN_006e4280(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  
  iVar1 = param_2;
  FUN_006e5150(&local_5c,&param_2);
  if ((local_5c != *(int *)(in_ECX + 0x2c)) && (*(char *)(local_5c + 0xe) != '\x01')) {
    uVar2 = (**(code **)(*DAT_00b5ac40 + 0x18))(iVar1);
    if (uVar2 != 0) {
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(1,iVar1 << 0x10 | uVar2);
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_00401660(uVar3,0,0xffffffff);
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      FUN_00401830(s_<COUNT0>_009e66c0);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<COUNT1>_009e66cc);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<COUNT2>_009e66d8);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<COUNT3>_009e66e4);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<NAME>_009e66f0);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<CLASS>_009e66f8);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<LEVEL>_009e6700);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<GUILDNAME>_009e6708);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      local_5c = 0;
      uStack_58 = 0;
      FUN_00401830(&DAT_009e6714);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6718);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e671c);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6720);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6724);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e672c);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6734);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6738);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      uVar3 = FUN_00404a40(auStack_28,auStack_44,auStack_54,auStack_54 + -0x10);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00406250();
      FUN_00406250();
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006e46c0 @ 0x006e46c0 ====

undefined4 FUN_006e46c0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar2;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  void *pvStack_78;
  void *local_74;
  undefined1 local_70;
  undefined4 uStack_68;
  void *pvStack_64;
  uint local_60;
  undefined4 local_5c;
  undefined1 uStack_58;
  uint uStack_50;
  undefined4 uStack_48;
  undefined4 auStack_44 [7];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  
  if ((param_1 != 5) || ((param_3 != 9 && (param_3 != 8)))) {
    return 0;
  }
  local_5c = 0xf;
  local_60 = 0;
  local_70 = 0;
  FUN_00401740(s_textbox_009e66a8,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(&local_74);
  if (0xf < local_60) {
    _free(local_74);
    return extraout_EAX;
  }
  local_60 = 0xf;
  pvStack_64 = (void *)0x0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  uStack_58 = 0;
  FUN_00401740(&DAT_009e66b0,0);
  if (param_3 == 9) {
    FUN_006e4280(&local_5c,9);
  }
  FUN_005569f0(&local_5c,0);
  local_60 = 0xf;
  pvStack_64 = (void *)0x0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  FUN_00401740(s_btn_cancel_009e66b4,10);
  piVar1 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x38) + 0x34))(&pvStack_78);
  if (0xf < pvStack_64) {
    _free(pvStack_78);
    return extraout_EAX_00;
  }
  pvStack_64 = (void *)0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  if (param_3 == 9) {
    if ((char)auStack_44[0] == '\0') goto LAB_006e4826;
  }
  else if ((param_3 != 8) || ((char)auStack_44[0] != '\0')) goto LAB_006e4826;
  auStack_44[0] = CONCAT31(auStack_44[0]._1_3_,(char)auStack_44[0] == '\0');
  (**(code **)(*piVar1 + 0xc))(auStack_44);
LAB_006e4826:
  *(short *)(unaff_EDI + 0x24) = (short)param_2;
  (**(code **)(*DAT_00b5ac38 + 0x10))(unaff_ESI,param_2);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return extraout_EAX_01;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (uStack_50 < 0x10) {
    return 1;
  }
  _free(pvStack_64);
  return extraout_EAX_02;
}


// ==== FUN_006e48a0 @ 0x006e48a0 ====

void FUN_006e48a0(void)

{
  uint *puVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  ushort *puVar8;
  uint in_ECX;
  uint uVar9;
  uint *puVar10;
  undefined4 uStack_a8;
  uint uStack_a0;
  uint uStack_98;
  undefined4 uStack_90;
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined2 uStack_74;
  undefined1 uStack_72;
  undefined1 auStack_70 [4];
  uint *puStack_6c;
  uint *puStack_68;
  int iStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined2 uStack_40;
  undefined4 uStack_3e;
  undefined1 uStack_3a;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 auStack_18 [20];
  
  uVar4 = (**(code **)(*DAT_00b5ac38 + 0xc))();
  uVar9 = 0;
  uStack_90 = 0;
  pvStack_8c = (void *)uVar4;
  uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1e001c);
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401660(uVar5,0,0xffffffff);
  if (uVar4 != 0) {
    do {
      piVar6 = (int *)(**(code **)(*DAT_00b5ac38 + 4))(uVar9);
      cVar3 = (**(code **)(*piVar6 + 0x1c))();
      if (cVar3 == '\0') {
        uStack_78 = 0xf;
        uStack_7c = 0;
        pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
        puStack_6c = (uint *)0x0;
        puStack_68 = (uint *)0x0;
        iStack_64 = 0;
        uStack_72 = (**(code **)(*piVar6 + 0x14))();
        uStack_74 = (**(code **)(*piVar6 + 0x10))();
        iVar7 = (**(code **)(*piVar6 + 0x10))();
        uVar9 = (**(code **)(*DAT_00b5ac40 + 0x14))(iVar7);
        uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(1,uVar9 | iVar7 << 0x10);
        FUN_00401660(uVar5,0,0xffffffff);
        uStack_38 = (**(code **)(*piVar6 + 0xc))();
        uStack_a0 = 0;
        if (uStack_38 != 0) {
          do {
            uStack_48 = 0xf;
            uStack_4c = 0;
            pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
            puVar8 = (ushort *)(**(code **)(*piVar6 + 8))(uStack_a0);
            uStack_48 = CONCAT22(uStack_48._2_2_,*puVar8);
            uVar2 = *puVar8;
            uVar9 = (**(code **)(*DAT_00b5ac40 + 0x14))(uVar2);
            uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(1,uVar9 | (uint)uVar2 << 0x10);
            FUN_00401660(uVar5,0,0xffffffff);
            iVar7 = *(int *)(puVar8 + 2);
            if (iVar7 == 3) {
              uStack_42 = 0xc;
            }
            else if (iVar7 == 1) {
              uStack_42 = 10;
            }
            else if (iVar7 == 2) {
              uStack_42 = 0xb;
              FUN_00401ff0(auStack_34,0,0xffffffff);
            }
            else {
              uStack_42 = 9;
            }
            puVar10 = puStack_68;
            if ((puStack_6c == (uint *)0x0) ||
               ((uint)(iStack_64 - (int)puStack_6c >> 5) <=
                (uint)((int)puStack_68 - (int)puStack_6c >> 5))) {
              FUN_006e5800(puStack_68,1,auStack_60);
            }
            else {
              FUN_006e5720(puStack_68,1,auStack_60,auStack_70,in_ECX);
              puStack_68 = puVar10 + 8;
            }
            uStack_3a = *(undefined1 *)((int)puVar8 + 0xb);
            uStack_a8 = CONCAT13((char)puVar8[5],
                                 CONCAT12(*(undefined1 *)((int)puVar8 + 9),
                                          CONCAT11((char)puVar8[4],(char)puVar8[2])));
            uStack_40 = uStack_44;
            uStack_3e = uStack_a8;
            FUN_006e5510(auStack_18,&uStack_40);
            if (0xf < uStack_48) {
              _free(pvStack_5c);
              return;
            }
            uStack_a0 = uStack_a0 + 1;
            uStack_48 = 0xf;
            uStack_4c = 0;
            pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
          } while (uStack_a0 < uStack_38);
        }
        FUN_006e6310(&uStack_90);
        if (puStack_6c != (uint *)0x0) {
          if (puStack_6c != puStack_68) {
            puVar10 = puStack_6c + 6;
            do {
              if (0xf < *puVar10) {
                _free((void *)puVar10[-5]);
                return;
              }
              *puVar10 = 0xf;
              puVar10[-1] = 0;
              *(undefined1 *)(puVar10 + -5) = 0;
              puVar1 = puVar10 + 2;
              puVar10 = puVar10 + 8;
            } while (puVar1 != puStack_68);
          }
          _free(puStack_6c);
          return;
        }
        puStack_6c = (uint *)0x0;
        puStack_68 = (uint *)0x0;
        iStack_64 = 0;
        if (0xf < uStack_78) {
          _free(pvStack_8c);
          return;
        }
        uStack_78 = 0xf;
        uStack_7c = 0;
        pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
        uVar9 = uStack_98;
      }
      uVar9 = uVar9 + 1;
      uStack_98 = uVar9;
    } while (uVar9 < in_ECX);
  }
  if (uStack_1c < 0x10) {
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_006e4bf0 @ 0x006e4bf0 ====

void FUN_006e4bf0(void)

{
  int iVar1;
  void *_Memory;
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  iVar1 = in_ECX[0xd];
  *in_ECX = &PTR_FUN_009e676c;
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),iVar1);
    _free(*(void **)(iVar1 + 4));
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  _Memory = (void *)in_ECX[0xd];
  if (_Memory == (void *)0x0) {
    in_ECX[0xd] = 0;
    FUN_006e5620(local_4,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
    _free((void *)in_ECX[0xb]);
    return;
  }
  if (*(int *)((int)_Memory + 4) == 0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  FUN_006c2e00(*(int *)((int)_Memory + 4),*(undefined4 *)((int)_Memory + 8),_Memory);
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_006e4cc0 @ 0x006e4cc0 ====

void FUN_006e4cc0(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 unaff_ESI;
  void **ppvVar5;
  char cVar6;
  undefined1 auStack_7a [2];
  undefined4 local_78;
  void *local_74;
  uint local_70;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint local_60;
  undefined4 local_5c;
  uint uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  
  FUN_006e4fe0(*(undefined4 *)(*(int *)(in_ECX + 0x2c) + 4));
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  iVar2 = *(int *)(in_ECX + 0x34);
  if (*(int *)(iVar2 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8),iVar2,local_78);
    _free(*(void **)(iVar2 + 4));
    return;
  }
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  FUN_006e48a0();
  local_5c = 0xf;
  local_60 = 0;
  local_70 = local_70 & 0xffffff00;
  FUN_00401740(s_quest_tree_009e6688,10);
  ppvVar5 = &local_74;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(ppvVar5);
  cVar6 = (char)((uint)ppvVar5 >> 0x18);
  if (0xf < local_60) {
    _free(local_74);
    return;
  }
  local_60 = 0xf;
  uStack_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  (**(code **)(*piVar3 + 0x30))();
  FUN_00587630(*(undefined4 *)(in_ECX + 0x34),0);
  *(undefined1 *)(in_ECX + 5) = 1;
  (**(code **)(*DAT_00b5ac38 + 0x14))(auStack_7a + -3,(short *)(in_ECX + 0x24));
  uStack_4c = 0xf;
  uStack_50 = 0;
  local_60 = local_60 & 0xffffff00;
  FUN_00401740(&DAT_009e6693,0);
  if (((char)((uint)unaff_ESI >> 0x18) != '\0') && (sVar1 = *(short *)(in_ECX + 0x24), sVar1 != -1))
  {
    FUN_006e4280(&uStack_64,sVar1);
  }
  uStack_68 = 0xf;
  pvStack_6c = (void *)0x0;
  FUN_00401740(s_textbox_009e6694,7);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_7a + -6);
  if (0xf < pvStack_6c) {
    _free(unaff_EBX);
    return;
  }
  pvStack_6c = (void *)0xf;
  local_70 = 0;
  (**(code **)(*piVar3 + 0x30))();
  FUN_005569f0(&uStack_68,0);
  pvStack_6c = (void *)0xf;
  local_70 = 0;
  FUN_00401740(s_btn_cancel_009e669c,10);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_7a + -10);
  if (0xf < local_70) {
    _free(unaff_EBP);
    return;
  }
  local_70 = 0xf;
  local_74 = (void *)0x0;
  uVar4 = (**(code **)(*piVar3 + 0x10))();
  FUN_005041e0(uVar4);
  uStack_50 = CONCAT31(uStack_50._1_3_,cVar6 == '\0');
  (**(code **)(*piVar3 + 0xc))(&uStack_50);
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if (uStack_58 < 0x10) {
    return;
  }
  _free(pvStack_6c);
  return;
}


// ==== FUN_006e4f00 @ 0x006e4f00 ====

void FUN_006e4f00(void)

{
  void *pvVar1;
  int in_ECX;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    FUN_006e4cc0();
    return;
  }
  *(undefined4 *)((int)pvVar1 + 4) = 0;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  *(void **)(in_ECX + 0x34) = pvVar1;
  FUN_006e4cc0();
  return;
}


// ==== FUN_006e4f50 @ 0x006e4f50 ====

void FUN_006e4f50(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e676c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  iVar1 = FUN_006e50b0();
  in_ECX[0xb] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xb] + 4) = in_ECX[0xb];
  *(undefined4 *)in_ECX[0xb] = in_ECX[0xb];
  *(undefined4 *)(in_ECX[0xb] + 8) = in_ECX[0xb];
  in_ECX[0xc] = 0;
  in_ECX[0xe] = param_1;
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    in_ECX[0xd] = 0;
    FUN_006e4cc0();
    return;
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  in_ECX[0xd] = pvVar2;
  FUN_006e4cc0();
  return;
}


// ==== FUN_006e4fe0 @ 0x006e4fe0 ====

void FUN_006e4fe0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_006e4fe0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006e5020 @ 0x006e5020 ====

void * FUN_006e5020(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c9a0;
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


// ==== Catch@006e5095 @ 0x006e5095 ====

void Catch_006e5095(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006e50b0 @ 0x006e50b0 ====

void FUN_006e50b0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c9b0;
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


// ==== Catch@006e513a @ 0x006e513a ====

void Catch_006e513a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006e5150 @ 0x006e5150 ====

void FUN_006e5150(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_006e51c0 @ 0x006e51c0 ====

void FUN_006e51c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_006e5020(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_006e52c5:
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
      if ((char)piVar6[5] == '\0') goto LAB_006e52c5;
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


// ==== FUN_006e53a0 @ 0x006e53a0 ====

int FUN_006e53a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x20;
    iVar2 = param_3 + -0x20;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined2 *)(param_3 + -4) = *(undefined2 *)(param_2 + -4);
    *(undefined1 *)(param_3 + -2) = *(undefined1 *)(param_2 + -2);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_006e53f0 @ 0x006e53f0 ====

void FUN_006e53f0(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
    *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_2 + 0x1e);
  }
  return;
}


// ==== FUN_006e5430 @ 0x006e5430 ====

int FUN_006e5430(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c9c0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_006e53f0(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@006e549a @ 0x006e549a ====

void Catch_006e549a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e54c0 @ 0x006e54c0 ====

int FUN_006e54c0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined2 *)(param_3 + 0x1c) = *(undefined2 *)(param_1 + 0x1c);
    *(undefined1 *)(param_3 + 0x1e) = *(undefined1 *)(param_1 + 0x1e);
    param_1 = param_1 + 0x20;
    param_3 = param_3 + 0x20;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_006e5510 @ 0x006e5510 ====

void FUN_006e5510(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_006e51c0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_006e51c0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_006e55d0 @ 0x006e55d0 ====

undefined4 FUN_006e55d0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x7ffffff < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x20);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x20 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_006e5620 @ 0x006e5620 ====

void FUN_006e5620(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006e4fe0(piVar6[1]);
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


// ==== FUN_006e56e0 @ 0x006e56e0 ====

void FUN_006e56e0(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_3 + 0x1c);
    *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_3 + 0x1e);
  }
  return;
}


// ==== FUN_006e5720 @ 0x006e5720 ====

void FUN_006e5720(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c9d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_006e53f0(param_1,param_3);
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006e578a @ 0x006e578a ====

void Catch_006e578a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e57b0 @ 0x006e57b0 ====

void FUN_006e57b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006e5430(param_1,param_2,param_3);
  return;
}


// ==== FUN_006e57d0 @ 0x006e57d0 ====

int FUN_006e57d0(int param_1,int param_2,undefined4 param_3)

{
  FUN_006e5720(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_006e5800 @ 0x006e5800 ====

void FUN_006e5800(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined1 local_5c [2];
  undefined1 auStack_5a [2];
  void *local_58;
  undefined4 local_48;
  uint local_44;
  undefined2 local_40;
  undefined1 local_3e;
  undefined4 local_3c;
  int local_2c;
  void *local_28;
  uint local_24;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c9e0;
  local_10 = ExceptionList;
  local_14 = local_5c + -0xc;
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_40 = *(undefined2 *)(param_3 + 0x1c);
  local_3e = *(undefined1 *)(param_3 + 0x1e);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - iVar2 >> 5;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (0x7ffffffU - iVar5 < param_2) {
      uVar1 = FUN_0085b3b0();
      iVar2 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (uVar1 < iVar5 + param_2) {
      if (0x7ffffff - (uVar1 >> 1) < uVar1) {
        local_24 = 0;
      }
      else {
        local_24 = uVar1 + (uVar1 >> 1);
      }
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (local_24 < iVar5 + param_2) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 5;
        }
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 << 5;
      pvVar3 = operator_new(local_24);
      local_8 = 0;
      local_28 = pvVar3;
      local_18 = pvVar3;
      local_18 = (void *)FUN_006e57b0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_18 = (void *)FUN_006e57d0(local_18,param_2,local_5c);
      FUN_006e57b0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (iVar2 != 0) {
        FUN_0068e630(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)pvVar3;
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)(local_2c - param_1 >> 5) < param_2) {
        local_1c = param_2 * 0x20;
        FUN_006e5430(param_1,local_2c,local_1c + param_1);
        local_8 = 2;
        FUN_006e57d0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),local_5c);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_006e56e0(param_1,*(int *)(in_ECX + 8) - local_1c,local_5c);
      }
      else {
        local_1c = param_2 * 0x20;
        iVar2 = local_2c + param_2 * -0x20;
        uVar4 = FUN_006e5430(iVar2,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_006e53a0(param_1,iVar2,local_2c,local_3c);
        FUN_006e56e0(param_1,local_1c + param_1,local_5c);
      }
    }
  }
  if (local_44 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_58);
  return;
}


// ==== Catch@006e598d @ 0x006e598d ====

void Catch_006e598d(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x24);
  FUN_0068e800(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@006e5a1f @ 0x006e5a1f ====

void Catch_006e5a1f(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_0068e800(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e5ab0 @ 0x006e5ab0 ====

void FUN_006e5ab0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c9f0;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x7ffffff < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 0x20);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x20 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_006e57b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006e5b67 @ 0x006e5b67 ====

void Catch_006e5b67(void)

{
  FUN_006e5b80();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e5b80 @ 0x006e5b80 ====

void FUN_006e5b80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_0068e630(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006e5bc0 @ 0x006e5bc0 ====

void FUN_006e5bc0(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    uVar6 = *(int *)(param_1 + 8) - iVar5 >> 5;
    if (uVar6 != 0) {
      iVar1 = *(int *)(in_ECX + 4);
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 8) - iVar1 >> 5;
      }
      if (uVar6 <= uVar3) {
        uVar4 = FUN_006e54c0(iVar5,*(int *)(param_1 + 8),iVar1,param_1);
        FUN_0068e630(uVar4,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5) * 0x20 + *(int *)(in_ECX + 4);
        return;
      }
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 0xc) - iVar1 >> 5;
      }
      if (uVar6 <= uVar3) {
        if (iVar1 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar1 >> 5;
        }
        iVar5 = iVar5 * 0x20 + *(int *)(param_1 + 4);
        FUN_006e54c0(*(int *)(param_1 + 4),iVar5,iVar1,param_1);
        uVar4 = FUN_006e5430(iVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (iVar1 != 0) {
        FUN_0068e800(iVar1,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5;
      }
      cVar2 = FUN_006e55d0(iVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar4 = FUN_006e57b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  FUN_006e5b80();
  return;
}


// ==== FUN_006e5d20 @ 0x006e5d20 ====

int FUN_006e5d20(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x30;
    iVar2 = param_3 + -0x30;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined2 *)(param_3 + -0x14) = *(undefined2 *)(param_2 + -0x14);
    *(undefined1 *)(param_3 + -0x12) = *(undefined1 *)(param_2 + -0x12);
    FUN_006e5bc0(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_006e5d70 @ 0x006e5d70 ====

void FUN_006e5d70(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
    *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_2 + 0x1e);
    FUN_006e5ab0(param_2 + 0x20);
  }
  return;
}


// ==== FUN_006e5dc0 @ 0x006e5dc0 ====

void FUN_006e5dc0(int param_1,int param_2,int param_3)

{
  if (param_1 != param_2) {
    do {
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_3 + 0x1c);
      *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_3 + 0x1e);
      FUN_006e5bc0(param_3 + 0x20);
      param_1 = param_1 + 0x30;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_006e5e10 @ 0x006e5e10 ====

int FUN_006e5e10(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098ca00;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x30) {
    FUN_006e5d70(param_3,param_1);
    param_3 = param_3 + 0x30;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@006e5e7a @ 0x006e5e7a ====

void Catch_006e5e7a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x30) {
    FUN_006c2da0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e5ea0 @ 0x006e5ea0 ====

void FUN_006e5ea0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098ca10;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_006e5d70(param_1,param_3);
    param_1 = param_1 + 0x30;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006e5f0a @ 0x006e5f0a ====

void Catch_006e5f0a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x30) {
    FUN_006c2da0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e5f30 @ 0x006e5f30 ====

void FUN_006e5f30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006e5e10(param_1,param_2,param_3);
  return;
}


// ==== FUN_006e5f50 @ 0x006e5f50 ====

int FUN_006e5f50(int param_1,int param_2,undefined4 param_3)

{
  FUN_006e5ea0(param_1,param_2,param_3);
  return param_2 * 0x30 + param_1;
}


// ==== FUN_006e5f80 @ 0x006e5f80 ====

void FUN_006e5f80(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_70 [2];
  undefined1 auStack_6e [2];
  undefined1 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined1 local_52;
  undefined4 local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  void *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098ca20;
  local_10 = ExceptionList;
  local_14 = local_70 + -0xc;
  local_58 = 0xf;
  local_5c = 0;
  local_6c = 0;
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_54 = *(undefined2 *)(param_3 + 0x1c);
  local_52 = *(undefined1 *)(param_3 + 0x1e);
  FUN_006e5ab0(param_3 + 0x20);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x30;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x30;
    }
    if (0x5555555U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x30;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x5555555 - (uVar4 >> 1) < uVar4) {
        local_24 = 0;
      }
      else {
        local_24 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x30;
      }
      if (local_24 < iVar2 + param_2) {
        iVar2 = FUN_004ab760();
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 * 0x30;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_006e5f30(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_006e5f50(local_18,param_2,local_70);
      FUN_006e5f30(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x30;
      }
      if (iVar2 != 0) {
        FUN_006c2e00(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar1) * 0x30 + (int)local_1c);
      *(void **)(in_ECX + 4) = local_1c;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x30) < param_2) {
        local_28 = param_2 * 0x30;
        FUN_006e5e10(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_006e5f50(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x30,local_70
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_006e5dc0(param_1,*(int *)(in_ECX + 8) - local_28,local_70);
      }
      else {
        local_30 = local_2c + param_2 * -0x30;
        uVar3 = FUN_006e5e10(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_006e5d20(param_1,local_30,local_2c,local_40);
        FUN_006e5dc0(param_1,param_2 * 0x30 + param_1,local_70);
      }
    }
  }
  FUN_006c2da0();
  ExceptionList = local_10;
  return;
}


// ==== Catch@006e6160 @ 0x006e6160 ====

void Catch_006e6160(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_006c2e70(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@006e6213 @ 0x006e6213 ====

void Catch_006e6213(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x30;
  FUN_006c2e70(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006e62a0 @ 0x006e62a0 ====

void FUN_006e62a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x30 != 0) {
      iVar1 = (param_2 - iVar1) / 0x30;
      goto LAB_006e62e5;
    }
  }
  iVar1 = 0;
LAB_006e62e5:
  FUN_006e5f80(param_2,1,param_3);
  *param_1 = iVar1 * 0x30 + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_006e6310 @ 0x006e6310 ====

void FUN_006e6310(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x30) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x30))) {
    FUN_006e62a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_006e5ea0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x30;
  return;
}


// ==== FUN_006e63a0 @ 0x006e63a0 ====

undefined2 FUN_006e63a0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x24);
}


// ==== FUN_006e63b0 @ 0x006e63b0 ====

void FUN_006e63b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006e4bf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e63d0 @ 0x006e63d0 ====

undefined1 FUN_006e63d0(void)

{
  return 0;
}


// ==== FUN_006e6410 @ 0x006e6410 ====

void FUN_006e6410(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  
  iVar1 = param_2;
  FUN_006e5150(&local_5c,&param_2);
  if ((local_5c != *(int *)(in_ECX + 0x2c)) && (*(char *)(local_5c + 0xe) != '\x01')) {
    uVar2 = (**(code **)(*DAT_00b5ac40 + 0x18))(iVar1);
    if (uVar2 != 0) {
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(1,iVar1 << 0x10 | uVar2);
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_00401660(uVar3,0,0xffffffff);
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      FUN_00401830(s_<COUNT0>_009e67fc);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<COUNT1>_009e6808);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<COUNT2>_009e6814);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<COUNT3>_009e6820);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<NAME>_009e682c);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<CLASS>_009e6834);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<LEVEL>_009e683c);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(s_<GUILDNAME>_009e6844);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      local_5c = 0;
      uStack_58 = 0;
      FUN_00401830(&DAT_009e6850);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6854);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6858);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e685c);
      uVar3 = FUN_00404230(auStack_28);
      FUN_00406720(uVar3);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6860);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6868);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6870);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00401830(&DAT_009e6874);
      FUN_00406720(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      uVar3 = FUN_00404a40(auStack_28,auStack_44,auStack_54,auStack_54 + -0x10);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      FUN_00406250();
      FUN_00406250();
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006e6850 @ 0x006e6850 ====

undefined4 FUN_006e6850(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar2;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  void *pvStack_78;
  void *local_74;
  undefined1 local_70;
  undefined4 uStack_68;
  void *pvStack_64;
  uint local_60;
  undefined4 local_5c;
  undefined1 uStack_58;
  uint uStack_50;
  undefined4 uStack_48;
  undefined4 auStack_44 [7];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  
  if ((param_1 != 5) || ((param_3 != 9 && (param_3 != 8)))) {
    return 0;
  }
  local_5c = 0xf;
  local_60 = 0;
  local_70 = 0;
  FUN_00401740(s_textbox_009e67e4,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(&local_74);
  if (0xf < local_60) {
    _free(local_74);
    return extraout_EAX;
  }
  local_60 = 0xf;
  pvStack_64 = (void *)0x0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  uStack_58 = 0;
  FUN_00401740(&DAT_009e67ec,0);
  if (param_3 == 9) {
    FUN_006e6410(&local_5c,9);
  }
  FUN_005569f0(&local_5c,0);
  local_60 = 0xf;
  pvStack_64 = (void *)0x0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  FUN_00401740(s_btn_cancel_009e67f0,10);
  piVar1 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x38) + 0x34))(&pvStack_78);
  if (0xf < pvStack_64) {
    _free(pvStack_78);
    return extraout_EAX_00;
  }
  pvStack_64 = (void *)0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  if (param_3 == 9) {
    if ((char)auStack_44[0] == '\0') goto LAB_006e69b6;
  }
  else if ((param_3 != 8) || ((char)auStack_44[0] != '\0')) goto LAB_006e69b6;
  auStack_44[0] = CONCAT31(auStack_44[0]._1_3_,(char)auStack_44[0] == '\0');
  (**(code **)(*piVar1 + 0xc))(auStack_44);
LAB_006e69b6:
  *(short *)(unaff_EDI + 0x24) = (short)param_2;
  (**(code **)(*DAT_00b5ac38 + 0x10))(unaff_ESI,param_2);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return extraout_EAX_01;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (uStack_50 < 0x10) {
    return 1;
  }
  _free(pvStack_64);
  return extraout_EAX_02;
}


// ==== FUN_006e6a30 @ 0x006e6a30 ====

void FUN_006e6a30(void)

{
  uint *puVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  ushort *puVar8;
  uint in_ECX;
  uint uVar9;
  uint *puVar10;
  undefined4 uStack_a8;
  uint uStack_a0;
  uint uStack_98;
  undefined4 uStack_90;
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined2 uStack_74;
  undefined1 uStack_72;
  undefined1 auStack_70 [4];
  uint *puStack_6c;
  uint *puStack_68;
  int iStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined2 uStack_40;
  undefined4 uStack_3e;
  undefined1 uStack_3a;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 auStack_18 [20];
  
  uVar4 = (**(code **)(*DAT_00b5ac38 + 0xc))();
  uVar9 = 0;
  uStack_90 = 0;
  pvStack_8c = (void *)uVar4;
  uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1e001c);
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401660(uVar5,0,0xffffffff);
  if (uVar4 != 0) {
    do {
      piVar6 = (int *)(**(code **)(*DAT_00b5ac38 + 4))(uVar9);
      cVar3 = (**(code **)(*piVar6 + 0x1c))();
      if (cVar3 != '\0') {
        uStack_78 = 0xf;
        uStack_7c = 0;
        pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
        puStack_6c = (uint *)0x0;
        puStack_68 = (uint *)0x0;
        iStack_64 = 0;
        uStack_72 = (**(code **)(*piVar6 + 0x14))();
        uStack_74 = (**(code **)(*piVar6 + 0x10))();
        iVar7 = (**(code **)(*piVar6 + 0x10))();
        uVar9 = (**(code **)(*DAT_00b5ac40 + 0x14))(iVar7);
        uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(1,uVar9 | iVar7 << 0x10);
        FUN_00401660(uVar5,0,0xffffffff);
        uStack_38 = (**(code **)(*piVar6 + 0xc))();
        uStack_a0 = 0;
        if (uStack_38 != 0) {
          do {
            uStack_48 = 0xf;
            uStack_4c = 0;
            pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
            puVar8 = (ushort *)(**(code **)(*piVar6 + 8))(uStack_a0);
            uStack_48 = CONCAT22(uStack_48._2_2_,*puVar8);
            uVar2 = *puVar8;
            uVar9 = (**(code **)(*DAT_00b5ac40 + 0x14))(uVar2);
            uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(1,uVar9 | (uint)uVar2 << 0x10);
            FUN_00401660(uVar5,0,0xffffffff);
            iVar7 = *(int *)(puVar8 + 2);
            if (iVar7 == 3) {
              uStack_42 = 0xc;
            }
            else if (iVar7 == 1) {
              uStack_42 = 10;
            }
            else if (iVar7 == 2) {
              uStack_42 = 0xb;
              FUN_00401ff0(auStack_34,0,0xffffffff);
            }
            else {
              uStack_42 = 9;
            }
            puVar10 = puStack_68;
            if ((puStack_6c == (uint *)0x0) ||
               ((uint)(iStack_64 - (int)puStack_6c >> 5) <=
                (uint)((int)puStack_68 - (int)puStack_6c >> 5))) {
              FUN_006e5800(puStack_68,1,auStack_60);
            }
            else {
              FUN_006e5720(puStack_68,1,auStack_60,auStack_70,in_ECX);
              puStack_68 = puVar10 + 8;
            }
            uStack_3a = *(undefined1 *)((int)puVar8 + 0xb);
            uStack_a8 = CONCAT13((char)puVar8[5],
                                 CONCAT12(*(undefined1 *)((int)puVar8 + 9),
                                          CONCAT11((char)puVar8[4],(char)puVar8[2])));
            uStack_40 = uStack_44;
            uStack_3e = uStack_a8;
            FUN_006e74c0(auStack_18,&uStack_40);
            if (0xf < uStack_48) {
              _free(pvStack_5c);
              return;
            }
            uStack_a0 = uStack_a0 + 1;
            uStack_48 = 0xf;
            uStack_4c = 0;
            pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
          } while (uStack_a0 < uStack_38);
        }
        FUN_006e6310(&uStack_90);
        if (puStack_6c != (uint *)0x0) {
          if (puStack_6c != puStack_68) {
            puVar10 = puStack_6c + 6;
            do {
              if (0xf < *puVar10) {
                _free((void *)puVar10[-5]);
                return;
              }
              *puVar10 = 0xf;
              puVar10[-1] = 0;
              *(undefined1 *)(puVar10 + -5) = 0;
              puVar1 = puVar10 + 2;
              puVar10 = puVar10 + 8;
            } while (puVar1 != puStack_68);
          }
          _free(puStack_6c);
          return;
        }
        puStack_6c = (uint *)0x0;
        puStack_68 = (uint *)0x0;
        iStack_64 = 0;
        if (0xf < uStack_78) {
          _free(pvStack_8c);
          return;
        }
        uStack_78 = 0xf;
        uStack_7c = 0;
        pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
        uVar9 = uStack_98;
      }
      uVar9 = uVar9 + 1;
      uStack_98 = uVar9;
    } while (uVar9 < in_ECX);
  }
  if (uStack_1c < 0x10) {
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_006e6d80 @ 0x006e6d80 ====

void FUN_006e6d80(void)

{
  int iVar1;
  void *_Memory;
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  iVar1 = in_ECX[0xd];
  *in_ECX = &PTR_FUN_009e6888;
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),iVar1);
    _free(*(void **)(iVar1 + 4));
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  _Memory = (void *)in_ECX[0xd];
  if (_Memory == (void *)0x0) {
    in_ECX[0xd] = 0;
    FUN_006e7580(local_4,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
    _free((void *)in_ECX[0xb]);
    return;
  }
  if (*(int *)((int)_Memory + 4) == 0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  FUN_006c2e00(*(int *)((int)_Memory + 4),*(undefined4 *)((int)_Memory + 8),_Memory);
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_006e6e50 @ 0x006e6e50 ====

void FUN_006e6e50(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 unaff_ESI;
  void **ppvVar5;
  char cVar6;
  undefined1 auStack_7a [2];
  undefined4 local_78;
  void *local_74;
  uint local_70;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint local_60;
  undefined4 local_5c;
  uint uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  
  FUN_006e7170(*(undefined4 *)(*(int *)(in_ECX + 0x2c) + 4));
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  iVar2 = *(int *)(in_ECX + 0x34);
  if (*(int *)(iVar2 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8),iVar2,local_78);
    _free(*(void **)(iVar2 + 4));
    return;
  }
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  FUN_006e6a30();
  local_5c = 0xf;
  local_60 = 0;
  local_70 = local_70 & 0xffffff00;
  FUN_00401740(s_quest_tree_009e67c4,10);
  ppvVar5 = &local_74;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(ppvVar5);
  cVar6 = (char)((uint)ppvVar5 >> 0x18);
  if (0xf < local_60) {
    _free(local_74);
    return;
  }
  local_60 = 0xf;
  uStack_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  (**(code **)(*piVar3 + 0x30))();
  FUN_00587630(*(undefined4 *)(in_ECX + 0x34),0);
  *(undefined1 *)(in_ECX + 5) = 1;
  (**(code **)(*DAT_00b5ac38 + 0x14))(auStack_7a + -3,(short *)(in_ECX + 0x24));
  uStack_4c = 0xf;
  uStack_50 = 0;
  local_60 = local_60 & 0xffffff00;
  FUN_00401740(&DAT_009e67cf,0);
  if (((char)((uint)unaff_ESI >> 0x18) != '\0') && (sVar1 = *(short *)(in_ECX + 0x24), sVar1 != -1))
  {
    FUN_006e6410(&uStack_64,sVar1);
  }
  uStack_68 = 0xf;
  pvStack_6c = (void *)0x0;
  FUN_00401740(s_textbox_009e67d0,7);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_7a + -6);
  if (0xf < pvStack_6c) {
    _free(unaff_EBX);
    return;
  }
  pvStack_6c = (void *)0xf;
  local_70 = 0;
  (**(code **)(*piVar3 + 0x30))();
  FUN_005569f0(&uStack_68,0);
  pvStack_6c = (void *)0xf;
  local_70 = 0;
  FUN_00401740(s_btn_cancel_009e67d8,10);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_7a + -10);
  if (0xf < local_70) {
    _free(unaff_EBP);
    return;
  }
  local_70 = 0xf;
  local_74 = (void *)0x0;
  uVar4 = (**(code **)(*piVar3 + 0x10))();
  FUN_005041e0(uVar4);
  uStack_50 = CONCAT31(uStack_50._1_3_,cVar6 == '\0');
  (**(code **)(*piVar3 + 0xc))(&uStack_50);
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if (uStack_58 < 0x10) {
    return;
  }
  _free(pvStack_6c);
  return;
}


// ==== FUN_006e7090 @ 0x006e7090 ====

void FUN_006e7090(void)

{
  void *pvVar1;
  int in_ECX;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    FUN_006e6e50();
    return;
  }
  *(undefined4 *)((int)pvVar1 + 4) = 0;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  *(void **)(in_ECX + 0x34) = pvVar1;
  FUN_006e6e50();
  return;
}


// ==== FUN_006e70e0 @ 0x006e70e0 ====

void FUN_006e70e0(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6888;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  iVar1 = FUN_006e7240();
  in_ECX[0xb] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xb] + 4) = in_ECX[0xb];
  *(undefined4 *)in_ECX[0xb] = in_ECX[0xb];
  *(undefined4 *)(in_ECX[0xb] + 8) = in_ECX[0xb];
  in_ECX[0xc] = 0;
  in_ECX[0xe] = param_1;
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    in_ECX[0xd] = 0;
    FUN_006e6e50();
    return;
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  in_ECX[0xd] = pvVar2;
  FUN_006e6e50();
  return;
}


// ==== FUN_006e7170 @ 0x006e7170 ====

void FUN_006e7170(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_006e7170(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006e71b0 @ 0x006e71b0 ====

void * FUN_006e71b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098ca30;
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


// ==== Catch@006e7225 @ 0x006e7225 ====

void Catch_006e7225(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006e7240 @ 0x006e7240 ====

void FUN_006e7240(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098ca40;
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


// ==== Catch@006e72ca @ 0x006e72ca ====

void Catch_006e72ca(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006e72e0 @ 0x006e72e0 ====

void FUN_006e72e0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_006e71b0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_006e73e5:
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
      if ((char)piVar6[5] == '\0') goto LAB_006e73e5;
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


// ==== FUN_006e74c0 @ 0x006e74c0 ====

void FUN_006e74c0(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_006e72e0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_006e72e0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_006e7580 @ 0x006e7580 ====

void FUN_006e7580(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006e7170(piVar6[1]);
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


// ==== FUN_006e7640 @ 0x006e7640 ====

void FUN_006e7640(byte param_1)

{
  void *in_ECX;
  
  FUN_006e6d80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e7660 @ 0x006e7660 ====

undefined1 FUN_006e7660(void)

{
  return 0;
}


// ==== FUN_006e76a0 @ 0x006e76a0 ====

/* WARNING: Removing unreachable block (ram,0x006e793a) */

void FUN_006e76a0(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iStack_64;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_4;
  
  iStack_64 = param_2;
  uVar1 = (**(code **)(*DAT_00b5ac40 + 0x1c))();
  if (uVar1 != 0) {
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(1,param_2 << 0x10 | uVar1);
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401660(uVar2,0,0xffffffff);
    pvStack_50 = (void *)0x0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_<NAME>_009e6924,6);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_<CLASS>_009e692c,7);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_<LEVEL>_009e6934,7);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_<GUILDNAME>_009e693c,0xb);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(&DAT_009e6948,6);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(&DAT_009e6950,4);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(&DAT_009e6958,2);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(&DAT_009e695c,8);
    FUN_00406720(auStack_44);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uVar2 = FUN_00404a40(auStack_44,auStack_28,auStack_54,&iStack_64);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    if (pvStack_50 != (void *)0x0) {
      FUN_00405de0(pvStack_50,uStack_4c,auStack_54,uStack_4);
      _free(pvStack_50);
      return;
    }
    pvStack_50 = (void *)0x0;
    uStack_4c = 0;
    uStack_48 = 0;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  return;
}


// ==== FUN_006e79c0 @ 0x006e79c0 ====

undefined4 FUN_006e79c0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  if ((param_1 != 5) || ((param_3 != 9 && (param_3 != 8)))) {
    return 0;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_textbox_009e68e0,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return extraout_EAX;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(&DAT_009e68e8,0);
  FUN_006e76a0(&local_20,param_3);
  FUN_005569f0(&local_20,0);
  if (uStack_8 < 0x10) {
    return 1;
  }
  _free(pvStack_1c);
  return extraout_EAX_00;
}


// ==== FUN_006e7ab0 @ 0x006e7ab0 ====

void FUN_006e7ab0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  void *pvVar8;
  void *unaff_EBX;
  void *unaff_EBP;
  byte *unaff_ESI;
  byte *pbVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  undefined4 uStack_ac;
  void *pvStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_84;
  uint uStack_80;
  undefined2 uStack_7c;
  undefined1 uStack_7a;
  undefined1 auStack_78 [4];
  void *pvStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  void *pvStack_64;
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  uint uStack_50;
  uint auStack_48 [8];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  
  FUN_006e81c0(*(undefined4 *)(*(int *)(in_ECX + 0x2c) + 4));
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  iVar3 = *(int *)(in_ECX + 0x34);
  if (*(int *)(iVar3 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),iVar3,local_8c);
    _free(*(void **)(iVar3 + 4));
    return;
  }
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  uStack_90 = (**(code **)(*DAT_00b5ac38 + 0x30))();
  if ((short)uStack_90 == 0) {
    pvStack_94 = (void *)0xf;
    uStack_98 = 0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    FUN_00401740(s_quest_tree_009e68ec,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(&uStack_ac);
    if (0xf < uStack_98) {
      _free(uStack_ac);
      return;
    }
    uStack_98 = 0xf;
    uStack_9c = 0;
    uStack_ac = (void *)((uint)uStack_ac & 0xffffff00);
    (**(code **)(*piVar2 + 0x30))();
    FUN_00587630(*(undefined4 *)(in_ECX + 0x34),1);
    uStack_98 = 0xf;
    uStack_9c = 0;
    uStack_ac = (void *)((uint)uStack_ac & 0xffffff00);
    FUN_00401740(s_textbox_009e68f8,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_78 + -0x38);
    if (0xf < uStack_9c) {
      _free(unaff_EBX);
      return;
    }
    uStack_9c = 0xf;
    uStack_a0 = 0;
    (**(code **)(*piVar2 + 0x30))();
    uStack_9c = 0xf;
    uStack_a0 = 0;
    FUN_00401740(&DAT_009e6900,0);
    FUN_005569f0(auStack_78 + -0x3c,0);
    if (0xf < uStack_9c) {
      _free((void *)((uint)unaff_EBX & 0xffffff00));
      return;
    }
  }
  else {
    *(undefined2 *)(in_ECX + 0x24) = 0;
    do {
      uVar10 = uStack_90;
      cVar1 = FUN_006ef730(uStack_90);
      if (cVar1 == '\0') {
        iVar3 = (**(code **)(*DAT_00b5ac40 + 4))(uVar10);
        uVar4 = (**(code **)(*DAT_00b5ac40 + 0x14))(iVar3);
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(1,iVar3 << 0x10 | uVar4);
        uStack_a4 = 0xf;
        pvStack_a8 = (void *)0x0;
        unaff_ESI = (byte *)((uint)unaff_ESI & 0xffffff00);
        FUN_00401660(uVar7,0,0xffffffff);
        iVar3 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
        uStack_9c = *(int *)(*(int *)(in_ECX + 0x34) + 8);
        if (iVar3 != uStack_9c) {
          do {
            if (*(uint *)(iVar3 + 0x18) < 0x10) {
              pbVar9 = (byte *)(iVar3 + 4);
            }
            else {
              pbVar9 = *(byte **)(iVar3 + 4);
            }
            if (pvStack_a8 == (void *)0x0) {
LAB_006e7d08:
              if ((*(void **)(iVar3 + 0x14) <= pvStack_a8) &&
                 (pvStack_a8 == *(void **)(iVar3 + 0x14))) {
                if (iVar3 != uStack_9c) {
                  if (*(short *)(in_ECX + 0x24) == *(short *)(iVar3 + 0x1c)) {
                    *(undefined2 *)(iVar3 + 0x1c) = (undefined2)uStack_a0;
                    *(undefined2 *)(in_ECX + 0x24) = (undefined2)uStack_a0;
                  }
                  else {
                    *(undefined2 *)(iVar3 + 0x1c) = (undefined2)uStack_a0;
                  }
                  goto LAB_006e7dfa;
                }
                break;
              }
            }
            else {
              pvVar8 = pvStack_a8;
              if (*(void **)(iVar3 + 0x14) <= pvStack_a8) {
                pvVar8 = *(void **)(iVar3 + 0x14);
              }
              pbVar5 = unaff_ESI;
              if (uStack_a4 < 0x10) {
                pbVar5 = auStack_78 + -0x40;
              }
              bVar11 = false;
              iVar6 = 0;
              bVar12 = true;
              do {
                if (pvVar8 == (void *)0x0) break;
                pvVar8 = (void *)((int)pvVar8 - 1);
                bVar11 = *pbVar5 < *pbVar9;
                bVar12 = *pbVar5 == *pbVar9;
                pbVar5 = pbVar5 + 1;
                pbVar9 = pbVar9 + 1;
              } while (bVar12);
              if (!bVar12) {
                iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
              }
              if (iVar6 == 0) goto LAB_006e7d08;
            }
            iVar3 = iVar3 + 0x30;
          } while (iVar3 != uStack_9c);
          uVar10 = uStack_a0;
        }
        uStack_80 = 0xf;
        uStack_84 = 0;
        pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
        pvStack_74 = (void *)0x0;
        uStack_70 = 0;
        uStack_6c = 0;
        uStack_7a = 0;
        uStack_7c = (undefined2)uVar10;
        if (*(short *)(in_ECX + 0x24) == 0) {
          *(undefined2 *)(in_ECX + 0x24) = uStack_7c;
        }
        FUN_00401660(auStack_78 + -0x44,0,0xffffffff);
        FUN_006e6310(&uStack_98);
        if (pvStack_74 != (void *)0x0) {
          FUN_0068e630(pvStack_74,uStack_70,auStack_78,uStack_9c);
          _free(pvStack_74);
          return;
        }
        pvStack_74 = (void *)0x0;
        uStack_70 = 0;
        uStack_6c = 0;
        if (0xf < uStack_80) {
          _free(pvStack_94);
          return;
        }
        uStack_80 = 0xf;
        uStack_84 = 0;
        pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
LAB_006e7dfa:
        uStack_90 = (**(code **)(*DAT_00b5ac38 + 0x34))();
        if (0xf < pvStack_94) {
          _free(pvStack_a8);
          return;
        }
        pvStack_94 = (void *)0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      }
      else {
        uStack_90 = (**(code **)(*DAT_00b5ac38 + 0x34))();
      }
    } while ((short)uStack_90 != 0);
    pvStack_94 = (void *)0xf;
    uStack_98 = 0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    FUN_00401740(s_quest_tree_009e6904,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(&uStack_ac);
    if (0xf < uStack_98) {
      _free(uStack_ac);
      return;
    }
    uStack_98 = 0xf;
    uStack_9c = 0;
    uStack_ac = (void *)((uint)uStack_ac & 0xffffff00);
    (**(code **)(*piVar2 + 0x30))();
    FUN_00587630(*(undefined4 *)(in_ECX + 0x34),1);
    *(undefined1 *)(in_ECX + 4) = 1;
    auStack_48[1] = 0xf;
    auStack_48[0] = 0;
    uStack_58 = 0;
    FUN_00401740(&DAT_009e690f,0);
    if (*(short *)(in_ECX + 0x24) != -1) {
      FUN_006e76a0(auStack_5c,*(short *)(in_ECX + 0x24));
    }
    uStack_98 = 0xf;
    uStack_9c = 0;
    uStack_ac = (void *)((uint)uStack_ac & 0xffffff00);
    FUN_00401740(s_textbox_009e6910,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_78 + -0x38);
    if (0xf < uStack_9c) {
      _free(unaff_EBX);
      return;
    }
    uStack_9c = 0xf;
    uStack_a0 = 0;
    (**(code **)(*piVar2 + 0x30))();
    FUN_005569f0(auStack_60,0);
    uStack_9c = 0xf;
    uStack_a0 = 0;
    FUN_00401740(s_btn_cancel_009e6918,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 0x34))(auStack_78 + -0x3c);
    if (0xf < uStack_a0) {
      _free(unaff_EBP);
      return;
    }
    uStack_a0 = 0xf;
    uStack_a4 = 0;
    uVar7 = (**(code **)(*piVar2 + 0x10))();
    FUN_005041e0(uVar7);
    auStack_48[0] = auStack_48[0] & 0xffffff00;
    (**(code **)(*piVar2 + 0xc))(auStack_48);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
  }
  return;
}


// ==== FUN_006e8010 @ 0x006e8010 ====

void FUN_006e8010(void)

{
  int iVar1;
  void *_Memory;
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  iVar1 = in_ECX[0xd];
  *in_ECX = &PTR_FUN_009e6970;
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),iVar1);
    _free(*(void **)(iVar1 + 4));
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  _Memory = (void *)in_ECX[0xd];
  if (_Memory == (void *)0x0) {
    in_ECX[0xd] = 0;
    FUN_006e82a0(local_4,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
    _free((void *)in_ECX[0xb]);
    return;
  }
  if (*(int *)((int)_Memory + 4) == 0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  FUN_006c2e00(*(int *)((int)_Memory + 4),*(undefined4 *)((int)_Memory + 8),_Memory);
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_006e80e0 @ 0x006e80e0 ====

void FUN_006e80e0(void)

{
  void *pvVar1;
  int in_ECX;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    FUN_006e7ab0();
    return;
  }
  *(undefined4 *)((int)pvVar1 + 4) = 0;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  *(void **)(in_ECX + 0x34) = pvVar1;
  FUN_006e7ab0();
  return;
}


// ==== FUN_006e8130 @ 0x006e8130 ====

void FUN_006e8130(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6970;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  iVar1 = FUN_006e8200();
  in_ECX[0xb] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xb] + 4) = in_ECX[0xb];
  *(undefined4 *)in_ECX[0xb] = in_ECX[0xb];
  *(undefined4 *)(in_ECX[0xb] + 8) = in_ECX[0xb];
  in_ECX[0xc] = 0;
  in_ECX[0xe] = param_1;
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    in_ECX[0xd] = 0;
    FUN_006e7ab0();
    return;
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  in_ECX[0xd] = pvVar2;
  FUN_006e7ab0();
  return;
}


// ==== FUN_006e81c0 @ 0x006e81c0 ====

void FUN_006e81c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_006e81c0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006e8200 @ 0x006e8200 ====

void FUN_006e8200(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098ca50;
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


// ==== Catch@006e828a @ 0x006e828a ====

void Catch_006e828a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006e82a0 @ 0x006e82a0 ====

void FUN_006e82a0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006e81c0(piVar6[1]);
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


// ==== FUN_006e8360 @ 0x006e8360 ====

void FUN_006e8360(byte param_1)

{
  void *in_ECX;
  
  FUN_006e8010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e8380 @ 0x006e8380 ====

void FUN_006e8380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6aa0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006e83a0 @ 0x006e83a0 ====

uint FUN_006e83a0(undefined4 *param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    *(undefined4 *)(in_ECX + 8) = *param_1;
    *(undefined4 *)(in_ECX + 0xc) = param_1[1];
    *(undefined4 *)(in_ECX + 0x10) = param_1[2];
    *(undefined1 *)(in_ECX + 4) = 1;
    return CONCAT31((int3)((uint)(in_ECX + 8) >> 8),1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006e83d0 @ 0x006e83d0 ====

int FUN_006e83d0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_006e83e0 @ 0x006e83e0 ====

undefined1 FUN_006e83e0(void)

{
  return 0;
}


// ==== FUN_006e83f0 @ 0x006e83f0 ====

undefined4 FUN_006e83f0(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 4) == '\0') || (*(char *)(in_ECX + 0x14) == '\0')) {
    return 0;
  }
  (**(code **)(*DAT_00b5ad24 + 0x10))(*(undefined4 *)(in_ECX + 0x1c));
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  return 1;
}


// ==== FUN_006e8430 @ 0x006e8430 ====

undefined4 FUN_006e8430(undefined4 param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x14) == '\0') {
    (**(code **)(*DAT_00b5ad24 + 8))(param_1);
    *(undefined4 *)(in_ECX + 0x1c) = param_1;
    *(undefined1 *)(in_ECX + 0x14) = 1;
    return 1;
  }
  return 0;
}


// ==== FUN_006e8460 @ 0x006e8460 ====

undefined4 FUN_006e8460(char *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char cVar14;
  undefined4 *puVar15;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    return 0;
  }
  if ((((*(char *)(in_ECX + 0x20) == *param_1) && (*(int *)(in_ECX + 0x24) == *(int *)(param_1 + 4))
       ) && (cVar14 = FUN_006e9e60(param_1 + 8), cVar14 != '\0')) &&
     (((cVar14 = FUN_006e9e60(param_1 + 0x18), cVar14 != '\0' &&
       (*(int *)(in_ECX + 0x48) == *(int *)(param_1 + 0x28))) &&
      ((*(int *)(in_ECX + 0x4c) == *(int *)(param_1 + 0x2c) &&
       (*(int *)(in_ECX + 0x50) == *(int *)(param_1 + 0x30))))))) {
    return 1;
  }
  FUN_006e9e90(param_1);
  if (*(char *)(in_ECX + 0x14) == '\0') {
    return 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  uVar3 = *(undefined4 *)(param_1 + 0x10);
  uVar4 = *(undefined4 *)(in_ECX + 0x1c);
  cVar14 = *param_1;
  uVar5 = *(undefined4 *)(param_1 + 0x14);
  uVar6 = *(undefined4 *)(param_1 + 0x20);
  uVar7 = *(undefined4 *)(param_1 + 0x18);
  uVar8 = *(undefined4 *)(param_1 + 0x1c);
  uVar9 = *(undefined4 *)(param_1 + 0x2c);
  uVar10 = *(undefined4 *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar12 = *(undefined4 *)(param_1 + 0x30);
  uVar13 = *(undefined4 *)(param_1 + 4);
  puVar15 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar15 == (undefined4 *)0x0) {
    puVar15 = (undefined4 *)0x0;
  }
  else {
    *puVar15 = &PTR_FUN_009e6ad8;
  }
  puVar15[1] = uVar4;
  *(char *)(puVar15 + 2) = cVar14;
  puVar15[3] = uVar1;
  puVar15[4] = uVar2;
  puVar15[5] = uVar3;
  puVar15[6] = uVar5;
  puVar15[7] = uVar7;
  puVar15[8] = uVar8;
  puVar15[9] = uVar6;
  puVar15[10] = uVar10;
  puVar15[0xb] = uVar13;
  puVar15[0xc] = uVar12;
  puVar15[0xd] = uVar11;
  puVar15[0xe] = uVar9;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar15);
  if (puVar15 != (undefined4 *)0x0) {
    (**(code **)*puVar15)(1);
  }
  return 1;
}


// ==== FUN_006e85d0 @ 0x006e85d0 ====

bool FUN_006e85d0(int *param_1)

{
  char cVar1;
  int in_ECX;
  
  if ((((*(int *)(in_ECX + 0xb4) == param_1[10]) && (*(int *)(in_ECX + 0xb0) == param_1[9])) &&
      (*(int *)(in_ECX + 0xa8) == *param_1)) && (*(int *)(in_ECX + 0xac) == param_1[1])) {
    cVar1 = FUN_004a1f80(in_ECX + 0x8c,param_1 + 2);
    return cVar1 == '\0';
  }
  return false;
}


// ==== FUN_006e8620 @ 0x006e8620 ====

undefined4 FUN_006e8620(void)

{
  int iVar1;
  void *_Memory;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    return 0;
  }
  if ((char)in_ECX[5] != '\0') {
    (**(code **)(*in_ECX + 0x20))();
  }
  iVar1 = in_ECX[0x1e];
  if (iVar1 != 0) {
    if (*(void **)(iVar1 + 4) != (void *)0x0) {
      _free(*(void **)(iVar1 + 4));
      return extraout_EAX;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    _Memory = (void *)in_ECX[0x1e];
    if (_Memory != (void *)0x0) {
      if (*(void **)((int)_Memory + 4) == (void *)0x0) {
        *(undefined4 *)((int)_Memory + 4) = 0;
        *(undefined4 *)((int)_Memory + 8) = 0;
        *(undefined4 *)((int)_Memory + 0xc) = 0;
        _free(_Memory);
        return extraout_EAX_01;
      }
      _free(*(void **)((int)_Memory + 4));
      return extraout_EAX_00;
    }
    in_ECX[0x1e] = 0;
  }
  *(undefined1 *)(in_ECX + 1) = 0;
  return 1;
}


// ==== FUN_006e86a0 @ 0x006e86a0 ====

void FUN_006e86a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6b08;
  if (*(char *)(in_ECX + 1) != '\0') {
    FUN_006e8620();
  }
  FUN_006e9f70();
  if ((void *)in_ECX[0x20] != (void *)0x0) {
    _free((void *)in_ECX[0x20]);
    return;
  }
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  if ((uint)in_ECX[0x1d] < 0x10) {
    in_ECX[0x1c] = 0;
    in_ECX[0x1d] = 0xf;
    *(undefined1 *)(in_ECX + 0x18) = 0;
    *in_ECX = &PTR_FUN_009e6aa0;
    return;
  }
  _free((void *)in_ECX[0x18]);
  return;
}


// ==== FUN_006e8710 @ 0x006e8710 ====

void FUN_006e8710(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6b08;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 0x15) = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[9] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  FUN_006e9f10();
  return;
}


// ==== FUN_006e8780 @ 0x006e8780 ====

void FUN_006e8780(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint uVar3;
  int iStack_4;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009bdce4;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
  }
  puVar2[1] = *(undefined4 *)(in_ECX + 0x1c);
  if (*(int *)(in_ECX + 0x80) != 0) {
    if ((*(int *)(in_ECX + 0x84) - *(int *)(in_ECX + 0x80)) / 0x18 != 0) {
      uVar3 = 0;
      iStack_4 = 0;
      while( true ) {
        if ((*(int *)(in_ECX + 0x80) == 0) ||
           ((uint)((*(int *)(in_ECX + 0x84) - *(int *)(in_ECX + 0x80)) / 0x18) <= uVar3)) {
          (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
          (**(code **)*puVar2)(1);
          return;
        }
        iVar1 = *(int *)(in_ECX + 0x80);
        if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x84) - iVar1) / 0x18) <= uVar3)) break;
        FUN_0057f1c0(iStack_4 + iVar1);
        iStack_4 = iStack_4 + 0x18;
        uVar3 = uVar3 + 1;
      }
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
  }
  (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
  (**(code **)*puVar2)(1);
  return;
}


// ==== FUN_006e8880 @ 0x006e8880 ====

void FUN_006e8880(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int in_ECX;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  byte ****ppppbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined1 local_88 [4];
  void *local_84;
  int local_80;
  undefined4 local_7c;
  undefined1 local_78 [4];
  int local_74;
  int local_70;
  int local_6c;
  uint local_68;
  undefined1 local_64 [4];
  byte ****local_60 [4];
  uint local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  int local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_44 = (void *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_70 = in_ECX;
  FUN_00404fb0(param_1,0x2c,local_48);
  local_84 = (void *)0x0;
  local_80 = 0;
  local_7c = 0;
  piVar6 = (int *)(in_ECX + 0x60);
  if (*(uint *)(in_ECX + 0x74) < 0x10) {
    piVar8 = piVar6;
  }
  else {
    piVar8 = (int *)*piVar6;
  }
  if (0xf < *(uint *)(in_ECX + 0x74)) {
    piVar6 = (int *)*piVar6;
  }
  FUN_004bdb30(&local_74,piVar6,*(int *)(in_ECX + 0x70) + (int)piVar8);
  local_68 = 0;
  local_6c = 0;
  do {
    if ((local_44 == (void *)0x0) || ((uint)((local_40 - (int)local_44) / 0x1c) <= local_68)) {
      if (local_84 != (void *)0x0) {
        FUN_00405de0(local_84,local_80,local_88,local_74);
        _free(local_84);
        return;
      }
      local_84 = (void *)0x0;
      local_80 = 0;
      local_7c = 0;
      if (local_44 == (void *)0x0) {
        return;
      }
      FUN_00405de0(local_44,local_40,local_48,local_74);
      _free(local_44);
      return;
    }
    local_4c = 0xf;
    local_50 = 0;
    local_60[0] = (byte ****)((uint)local_60[0] & 0xffffff00);
    FUN_00401660(local_6c + (int)local_44,0,0xffffffff);
    if (local_84 != (void *)0x0) {
      FUN_00405de0(local_84,local_80,local_88,local_74);
      _free(local_84);
      return;
    }
    local_84 = (void *)0x0;
    local_80 = 0;
    local_7c = 0;
    FUN_00404fb0(local_64,0x20,local_88);
    if ((local_84 == (void *)0x0) || (local_74 = (local_80 - (int)local_84) / 0x1c, local_74 == 0))
    {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00401660(local_84,0,0xffffffff);
    if (local_50 == 0) {
LAB_006e8a2f:
      iVar2 = FUN_00403620(0,local_50,&DAT_009e6a5c,3);
      if (iVar2 == 0) {
        if ((local_84 == (void *)0x0) || ((uint)((local_80 - (int)local_84) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar3 = thunk_FUN_00796fb0((int)local_84 + 0x1c);
        *(undefined4 *)(local_70 + 0x58) = uVar3;
      }
      else {
        iVar2 = FUN_00403620(0,local_50,&DAT_009e6a60,4);
        if (iVar2 == 0) {
          iVar2 = 0x1c;
          for (uVar7 = 1;
              (local_84 != (void *)0x0 && (uVar7 < (uint)((local_80 - (int)local_84) / 0x1c)));
              uVar7 = uVar7 + 1) {
            iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_84 + iVar2 + 0x14),&DAT_009e6a68,1);
            if (iVar4 != 0) {
              if ((local_84 == (void *)0x0) || ((uint)((local_80 - (int)local_84) / 0x1c) <= uVar7))
              {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uVar3 = FUN_004022a0(local_1c,&DAT_009e6a6c,(int)local_84 + iVar2);
              FUN_00401ff0(uVar3,0,0xffffffff);
              if (0xf < local_4) {
                _free(local_18);
                return;
              }
              local_4 = 0xf;
              local_8 = 0;
              local_18 = (void *)((uint)local_18 & 0xffffff00);
            }
            iVar2 = iVar2 + 0x1c;
          }
        }
        else {
          iVar2 = FUN_00403620(0,local_50,&DAT_009e6a70,3);
          if (iVar2 == 0) {
            pvVar5 = operator_new(0x10);
            if (pvVar5 == (void *)0x0) {
              pvVar5 = (void *)0x0;
            }
            else {
              *(undefined4 *)((int)pvVar5 + 4) = 0;
              *(undefined4 *)((int)pvVar5 + 8) = 0;
              *(undefined4 *)((int)pvVar5 + 0xc) = 0;
            }
            *(void **)(local_70 + 0x78) = pvVar5;
            iVar2 = 0x1c;
            for (uVar7 = 1;
                (local_84 != (void *)0x0 && (uVar7 < (uint)((local_80 - (int)local_84) / 0x1c)));
                uVar7 = uVar7 + 1) {
              iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_84 + iVar2 + 0x14),&DAT_009e6a74,1);
              if (iVar4 != 0) {
                if ((local_84 == (void *)0x0) ||
                   ((uint)((local_80 - (int)local_84) / 0x1c) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
                  FUN_00405ca0();
                }
                local_20 = 0xf;
                local_24 = 0;
                local_34 = (void *)((uint)local_34 & 0xffffff00);
                FUN_00401660((int)local_84 + iVar2,0,0xffffffff);
                local_78[0] = 0x3e;
                iVar4 = FUN_00405850(local_78,0,1);
                if (iVar4 != -1) {
                  FUN_00401390(iVar4,0xffffffff);
                }
                local_74 = thunk_FUN_00796fb0(local_38);
                iVar4 = *(int *)(local_70 + 0x78);
                iVar1 = *(int *)(iVar4 + 4);
                if ((iVar1 == 0) ||
                   ((uint)(*(int *)(iVar4 + 0xc) - iVar1 >> 2) <=
                    (uint)(*(int *)(iVar4 + 8) - iVar1 >> 2))) {
                  FUN_0042f3e0(*(undefined4 *)(iVar4 + 8),1,&local_74);
                }
                else {
                  piVar6 = *(int **)(iVar4 + 8);
                  *piVar6 = local_74;
                  *(int **)(iVar4 + 8) = piVar6 + 1;
                }
                if (0xf < local_20) {
                  _free(local_34);
                  return;
                }
                local_20 = 0xf;
                local_24 = 0;
                local_34 = (void *)((uint)local_34 & 0xffffff00);
              }
              iVar2 = iVar2 + 0x1c;
            }
          }
        }
      }
    }
    else {
      uVar7 = local_50;
      if (5 < local_50) {
        uVar7 = 6;
      }
      ppppbVar9 = local_60[0];
      if (local_4c < 0x10) {
        ppppbVar9 = (byte ****)local_60;
      }
      bVar11 = false;
      iVar2 = 0;
      bVar12 = true;
      pbVar10 = (byte *)s_<guage_009e6a54;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *(byte *)ppppbVar9 < *pbVar10;
        bVar12 = *(byte *)ppppbVar9 == *pbVar10;
        ppppbVar9 = (byte ****)((int)ppppbVar9 + 1);
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar2 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (((iVar2 != 0) || (local_50 < 6)) || (local_50 != 6)) goto LAB_006e8a2f;
      *(undefined1 *)(local_70 + 0x54) = 1;
    }
    if (0xf < local_4c) {
      _free(local_60[0]);
      return;
    }
    local_68 = local_68 + 1;
    local_6c = local_6c + 0x1c;
    local_4c = 0xf;
    local_50 = 0;
    local_60[0] = (byte ****)((uint)local_60[0] & 0xffffff00);
  } while( true );
}


// ==== FUN_006e8e10 @ 0x006e8e10 ====

void FUN_006e8e10(int param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  byte ****ppppbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  undefined1 local_54 [4];
  void *local_50;
  int local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  void *local_40;
  int local_3c;
  undefined4 local_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 local_1c [4];
  byte ****local_18 [4];
  uint local_8;
  uint local_4;
  
  local_40 = (void *)0x0;
  local_3c = 0;
  local_38 = 0;
  FUN_00404fb0(param_1,0x20,local_44);
  local_50 = (void *)0x0;
  local_4c = 0;
  local_48 = 0;
  uVar3 = 1;
  param_1 = 0x1c;
  do {
    if ((local_40 == (void *)0x0) || ((uint)((local_3c - (int)local_40) / 0x1c) <= uVar3)) {
      iStack_34 = *param_2;
      iStack_30 = param_2[1];
      if (*(char *)(in_ECX + 0x15) == '\0') {
        *param_2 = *param_2 + uStack_2c + 2;
      }
      else if (*(uint *)(in_ECX + 0x18) < uStack_2c) {
        *(uint *)(in_ECX + 0x18) = uStack_2c;
      }
      FUN_0057f1c0(&iStack_34);
      if (local_50 != (void *)0x0) {
        FUN_00405de0(local_50,local_4c,local_54,param_1);
        _free(local_50);
        return;
      }
      local_50 = (void *)0x0;
      local_4c = 0;
      local_48 = 0;
      if (local_40 == (void *)0x0) {
        return;
      }
      FUN_00405de0(local_40,local_3c,local_44,param_1);
      _free(local_40);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18[0] = (byte ****)((uint)local_18[0] & 0xffffff00);
    FUN_00401660(param_1 + (int)local_40,0,0xffffffff);
    if (local_50 != (void *)0x0) {
      FUN_00405de0(local_50,local_4c,local_54,param_1);
      _free(local_50);
      return;
    }
    local_50 = (void *)0x0;
    local_4c = 0;
    local_48 = 0;
    FUN_00404fb0(local_1c,0x3d,local_54);
    if ((local_50 == (void *)0x0) || ((local_4c - (int)local_50) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00401660(local_50,0,0xffffffff);
    if (local_8 == 0) {
LAB_006e8fcb:
      iVar1 = FUN_00403620(0,local_8,s_index_009e6a80,5);
      if (iVar1 == 0) {
        if ((local_50 == (void *)0x0) || ((uint)((local_4c - (int)local_50) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_20 = thunk_FUN_00796fb0((int)local_50 + 0x1c);
      }
      else {
        iVar1 = FUN_00403620(0,local_8,s_width_009e6a88,5);
        if (iVar1 == 0) {
          if ((local_50 == (void *)0x0) || ((uint)((local_4c - (int)local_50) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uStack_2c = thunk_FUN_00796e60((int)local_50 + 0x1c);
        }
        else {
          iVar1 = FUN_00403620(0,local_8,s_height_009e6a90,6);
          if (iVar1 == 0) {
            if ((local_50 == (void *)0x0) || ((uint)((local_4c - (int)local_50) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uStack_28 = thunk_FUN_00796e60((int)local_50 + 0x1c);
          }
        }
      }
    }
    else {
      uVar2 = local_8;
      if (5 < local_8) {
        uVar2 = 6;
      }
      ppppbVar4 = local_18[0];
      if (local_4 < 0x10) {
        ppppbVar4 = (byte ****)local_18;
      }
      bVar6 = false;
      iVar1 = 0;
      bVar7 = true;
      pbVar5 = (byte *)s_screen_009e6a78;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar6 = *(byte *)ppppbVar4 < *pbVar5;
        bVar7 = *(byte *)ppppbVar4 == *pbVar5;
        ppppbVar4 = (byte ****)((int)ppppbVar4 + 1);
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar1 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      }
      if (((iVar1 != 0) || (local_8 < 6)) || (local_8 != 6)) goto LAB_006e8fcb;
      if ((local_50 == (void *)0x0) || ((uint)((local_4c - (int)local_50) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_24 = (**(code **)(*DAT_00b5a7c0 + 8))((int)local_50 + 0x1c);
    }
    if (0xf < local_4) {
      _free(local_18[0]);
      return;
    }
    uVar3 = uVar3 + 1;
    param_1 = param_1 + 0x1c;
    local_4 = 0xf;
    local_8 = 0;
    local_18[0] = (byte ****)((uint)local_18[0] & 0xffffff00);
  } while( true );
}


// ==== FUN_006e91e0 @ 0x006e91e0 ====

void FUN_006e91e0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar3 = 0;
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = *(uint *)(param_1 + 0x18);
      if (uVar2 < 0x10) {
        iVar4 = param_1 + 4;
      }
      else {
        iVar4 = *(int *)(param_1 + 4);
      }
      if (*(char *)(iVar4 + uVar5) == '<') {
LAB_006e9231:
        if (uVar2 < 0x10) {
          iVar4 = param_1 + 4;
        }
        else {
          iVar4 = *(int *)(param_1 + 4);
        }
        if (*(char *)(iVar4 + uVar5) == '<') {
          local_20 = 0xf;
          local_24 = 0;
          local_34 = (void *)((uint)local_34 & 0xffffff00);
          FUN_00401660(param_1,uVar3,uVar5 - uVar3);
          FUN_00406720(local_38);
          if (0xf < local_20) {
            _free(local_34);
            return;
          }
          local_20 = 0xf;
          local_24 = 0;
          local_34 = (void *)((uint)local_34 & 0xffffff00);
          uVar3 = uVar5;
        }
        else {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          FUN_00401660(param_1,uVar3,(uVar5 + 1) - uVar3);
          FUN_00406720(local_1c);
          if (0xf < local_4) {
            _free(local_18);
            return;
          }
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          uVar3 = uVar5 + 1;
        }
        uVar5 = uVar3;
      }
      else {
        if (uVar2 < 0x10) {
          iVar4 = param_1 + 4;
        }
        else {
          iVar4 = *(int *)(param_1 + 4);
        }
        if (*(char *)(iVar4 + uVar5) == '>') goto LAB_006e9231;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
    if (uVar3 < uVar1) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(param_1,uVar3,uVar1 - uVar3);
      FUN_00406720(local_1c);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006e9350 @ 0x006e9350 ====

uint FUN_006e9350(undefined4 param_1,int param_2,int *param_3,undefined4 param_4,char param_5)

{
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  void *pvVar1;
  undefined4 uVar2;
  uint extraout_EAX_03;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  undefined1 local_fc [4];
  void *local_f8;
  uint local_e8;
  uint local_e4;
  undefined4 local_e0;
  void *local_dc;
  int local_d8;
  undefined1 local_d4 [4];
  void *local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  int local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined1 local_b8 [4];
  undefined1 local_b4 [4];
  void *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  uint local_a4;
  undefined1 local_a0 [4];
  void *local_9c;
  int local_98;
  undefined4 local_94;
  undefined1 local_90 [4];
  undefined1 local_8c [28];
  undefined1 local_70 [28];
  undefined1 local_54 [28];
  undefined1 local_38 [28];
  undefined1 local_1c [28];
  
  local_b0 = (void *)0x0;
  local_ac = 0;
  local_a8 = 0;
  local_e4 = 0xf;
  local_e8 = 0;
  local_f8 = (void *)((uint)local_f8 & 0xffffff00);
  FUN_00401740(s___GT___009e69d8,6);
  FUN_00406720(local_fc);
  if (0xf < local_e4) {
    _free(local_f8);
    return extraout_EAX;
  }
  local_e4 = 0xf;
  local_e8 = 0;
  local_f8 = (void *)((uint)local_f8 & 0xffffff00);
  FUN_00401740(s___LT___009e69e0,6);
  FUN_00406720(local_fc);
  if (0xf < local_e4) {
    _free(local_f8);
    return extraout_EAX_00;
  }
  local_d0 = (void *)0x0;
  local_cc = 0;
  local_c8 = 0;
  local_e4 = 0xf;
  local_e8 = 0;
  local_f8 = (void *)((uint)local_f8 & 0xffffff00);
  FUN_00401740(&DAT_009e69e8,1);
  FUN_00406720(local_fc);
  if (0xf < local_e4) {
    _free(local_f8);
    return extraout_EAX_01;
  }
  local_e4 = 0xf;
  local_e8 = 0;
  local_f8 = (void *)((uint)local_f8 & 0xffffff00);
  FUN_00401740(&DAT_009e69ec,1);
  FUN_00406720(local_fc);
  if (0xf < local_e4) {
    _free(local_f8);
    return extraout_EAX_02;
  }
  if (param_5 == '\0') {
    iVar5 = *param_3;
    local_c0 = param_3[1];
    local_9c = (void *)0x0;
    local_98 = 0;
    local_94 = 0;
    local_c4 = iVar5;
    FUN_006e91e0(param_4,local_a0);
    pvVar1 = local_9c;
    if ((local_9c != (void *)0x0) && ((local_98 - (int)local_9c) / 0x1c == 1)) {
      FUN_00406250();
      FUN_00406250();
      uVar3 = FUN_00406250();
      return uVar3 & 0xffffff00;
    }
    uVar2 = *(undefined4 *)(param_2 + 0x28);
    local_bc = *(undefined4 *)(param_2 + 0x24);
    local_a4 = 0;
    local_dc = local_9c;
    while (pvVar1 != (void *)0x0) {
      if ((uint)((local_98 - (int)pvVar1) / 0x1c) <= local_a4) {
        if (pvVar1 != (void *)0x0) {
          FUN_00405de0(pvVar1,local_98,local_a0,local_e0);
          _free(pvVar1);
          return extraout_EAX_05;
        }
        break;
      }
      local_e4 = 0xf;
      local_e8 = 0;
      local_f8 = (void *)((uint)local_f8 & 0xffffff00);
      FUN_00401660(local_dc,0,0xffffffff);
      iVar4 = FUN_00403620(0,local_e8,&DAT_009e69ee,0);
      if (iVar4 != 0) {
        iVar4 = FUN_00403620(0,local_e8,s_<_font>_009e69f0,7);
        if (iVar4 == 0) {
          local_bc = *(undefined4 *)(param_2 + 0x24);
        }
        else {
          iVar4 = FUN_00403620(0,local_e8,s_<_color>_009e69f8,8);
          if (iVar4 == 0) {
            uVar2 = *(undefined4 *)(param_2 + 0x28);
          }
          else {
            iVar4 = FUN_00403620(0,5,s_<font_009e6a04,5);
            if (iVar4 == 0) {
              if (5 < local_e8) {
                uVar2 = FUN_00405b90(local_70,6,local_e8 - 1);
                local_bc = thunk_FUN_00796fb0(uVar2);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
            }
            else {
              iVar4 = FUN_00557ba0(0,6,s_<color_009e6a0c);
              if (iVar4 == 0) {
                if (0xb < local_e8) {
                  uVar2 = FUN_00405b90(local_38,7,local_e8 - 1);
                  thunk_FUN_00796e90(uVar2);
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
              }
              else {
                iVar4 = FUN_004233d0(s_<guage_009e6a14,0);
                if (iVar4 == -1) {
                  iVar4 = FUN_00557ba0(0,6,s_<space_009e6a1c);
                  if (iVar4 == 0) {
                    uVar2 = FUN_00405b90(local_8c,7,local_e8 - 1);
                    local_c4 = thunk_FUN_00796fb0(uVar2);
                    local_c4 = iVar5 + local_c4;
                    /* WARNING: Subroutine does not return */
                    FUN_00446f10();
                  }
                  iVar4 = FUN_00557ba0(0,4,&DAT_009e6a24);
                  if (iVar4 == 0) {
                    uVar2 = FUN_00405b90(local_54,5,local_e8 - 1);
                    local_c4 = thunk_FUN_00796fb0(uVar2);
                    /* WARNING: Subroutine does not return */
                    FUN_00446f10();
                  }
                  iVar4 = FUN_00557ba0(0,7,s_<center_009e6a2c);
                  if (iVar4 != 0) {
                    iVar4 = FUN_004233d0(&DAT_009e6a34,0);
                    if (iVar4 == -1) {
                      iVar4 = FUN_004233d0(s_<overlab_009e6a3c,0);
                      if (iVar4 == -1) {
                        iVar4 = FUN_004233d0(s_<_overlab>_009e6a48,0);
                        if (iVar4 == -1) {
                          pvVar1 = operator_new(0x2c);
                          if (pvVar1 == (void *)0x0) {
                            iVar5 = 0;
                          }
                          else {
                            iVar5 = FUN_006e9f10();
                          }
                          *(undefined4 *)(iVar5 + 0x24) = local_bc;
                          *(undefined4 *)(iVar5 + 0x28) = uVar2;
                          uVar2 = FUN_00404a40(local_1c,local_fc,local_b4,local_d4);
                          FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
                          FUN_00446f10();
                        }
                        iVar5 = iVar5 + 2 + *(int *)(local_d8 + 0x18);
                        *(undefined1 *)(local_d8 + 0x15) = 0;
                        local_c4 = iVar5;
                      }
                      else {
                        *(undefined1 *)(local_d8 + 0x15) = 1;
                      }
                    }
                    else {
                      FUN_006e8e10(local_fc,&local_c4);
                      iVar5 = local_c4;
                    }
                  }
                }
                else {
                  FUN_006e8880(local_fc);
                }
              }
            }
          }
        }
      }
      if (0xf < local_e4) {
        _free(local_f8);
        return extraout_EAX_04;
      }
      local_a4 = local_a4 + 1;
      local_dc = (void *)((int)local_dc + 0x1c);
      local_e4 = 0xf;
      local_e8 = 0;
      local_f8 = (void *)((uint)local_f8 & 0xffffff00);
    }
  }
  else {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = (void *)FUN_006e9f10();
    }
    *(undefined4 *)((int)pvVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)((int)pvVar1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
    uVar2 = FUN_00404a40(local_fc,param_4,local_b4,local_d4);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_e4) {
      _free(local_f8);
      return extraout_EAX_03;
    }
    (**(code **)(*DAT_00b5a688 + 0x34))
              (*(undefined4 *)((int)pvVar1 + 0x24),pvVar1,local_b8,local_90);
    *(int *)((int)pvVar1 + 0x1c) = *param_3;
    *(int *)((int)pvVar1 + 0x20) = param_3[1];
    local_dc = pvVar1;
    FUN_00846af0(&local_dc);
  }
  if (local_d0 != (void *)0x0) {
    FUN_00405de0(local_d0,local_cc,local_d4,local_e0);
    _free(local_d0);
    return extraout_EAX_06;
  }
  local_d0 = (void *)0x0;
  local_cc = 0;
  local_c8 = 0;
  if (local_b0 == (void *)0x0) {
    return 1;
  }
  FUN_00405de0(local_b0,local_ac,local_b4,local_e0);
  _free(local_b0);
  return extraout_EAX_07;
}


// ==== FUN_006e9a70 @ 0x006e9a70 ====

void FUN_006e9a70(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  void *pvVar4;
  undefined4 *puStack_80;
  int iStack_7c;
  void *pvStack_78;
  void *pvStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  void *pvStack_68;
  undefined4 uStack_64;
  void *pvStack_60;
  void *pvStack_5c;
  void *pvStack_58;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  cVar1 = FUN_006e85d0(param_1);
  if (cVar1 != '\x01') {
    *(undefined4 *)(in_ECX + 0xb4) = param_1[10];
    *(undefined4 *)(in_ECX + 0xb0) = param_1[9];
    *(undefined4 *)(in_ECX + 0xa8) = *param_1;
    *(undefined4 *)(in_ECX + 0xac) = param_1[1];
    pvVar4 = (void *)0x0;
    FUN_00401660(param_1 + 2,0,0xffffffff);
    puStack_80 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puStack_80 == (undefined4 *)0x0) {
      puStack_80 = (undefined4 *)0x0;
    }
    else {
      *puStack_80 = &PTR_FUN_009e6af0;
      puStack_80[3] = 0;
      puStack_80[4] = 0;
      puStack_80[5] = 0;
      puStack_80[6] = 0;
    }
    puStack_80[1] = *(undefined4 *)(in_ECX + 0x1c);
    uStack_6c = *param_1;
    pvStack_68 = (void *)param_1[1];
    iStack_7c = 0;
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    FUN_00401740(s___BS___009e69c8,6);
    pvStack_3c = (void *)0xf;
    uStack_40 = 0;
    uStack_50 = 0;
    FUN_00401740(&DAT_009e69d0,1);
    if ((*(char *)(param_1 + 0xc) == '\0') ||
       (iVar2 = FUN_00403620(0,param_1[7],&DAT_009e69d2,0), iVar2 == 0)) {
      pvVar3 = operator_new(0x2c);
      if (pvVar3 != (void *)0x0) {
        pvVar4 = (void *)FUN_006e9f10();
      }
      *(undefined4 *)((int)pvVar4 + 0x28) = param_1[10];
      *(undefined4 *)((int)pvVar4 + 0x24) = param_1[9];
      *(undefined4 *)((int)pvVar4 + 0x1c) = *param_1;
      *(undefined4 *)((int)pvVar4 + 0x20) = param_1[1];
      FUN_00401660(param_1 + 2,0,0xffffffff);
      FUN_00404440(pvVar4,auStack_38,auStack_54);
      cVar1 = FUN_006e9350(puStack_80,param_1,&uStack_6c,pvVar4,param_2);
      if ((cVar1 != '\0') ||
         (iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvVar4 + 0x14),&DAT_009e69d3,0), iVar2 == 0))
      {
        FUN_006e9f70();
        _free(pvVar4);
        return;
      }
      *(undefined4 *)((int)pvVar4 + 0x1c) = uStack_6c;
      *(void **)((int)pvVar4 + 0x20) = pvStack_68;
      pvStack_70 = pvVar4;
      FUN_00846af0(&pvStack_70);
      (**(code **)(*DAT_00b5ad24 + 4))(puStack_80);
      (**(code **)*puStack_80)(1);
      if (0xf < uStack_44) {
        _free(pvStack_58);
        return;
      }
    }
    else {
      FUN_00412dc0();
      pvStack_60 = (void *)0x0;
      pvStack_5c = (void *)0x0;
      pvStack_58 = (void *)0x0;
      FUN_00401830(&DAT_009e69d4);
      FUN_00405300(param_1 + 2,auStack_1c,&uStack_64);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      pvStack_78 = pvStack_60;
      pvStack_70 = pvStack_5c;
      if (pvStack_60 != pvStack_5c) {
        do {
          pvVar3 = (void *)0x0;
          pvVar4 = operator_new(0x2c);
          if (pvVar4 != (void *)0x0) {
            pvVar3 = (void *)FUN_006e9f10();
          }
          *(undefined4 *)((int)pvVar3 + 0x28) = param_1[10];
          *(undefined4 *)((int)pvVar3 + 0x24) = param_1[9];
          FUN_00401660(pvStack_78,0,0xffffffff);
          pvVar4 = (void *)(param_1[0xb] * iStack_7c + param_1[1]);
          pvStack_68 = pvVar4;
          FUN_00404440(pvVar3,auStack_38,auStack_54);
          cVar1 = FUN_006e9350(puStack_80,param_1,&uStack_6c,pvVar3,param_2);
          if ((cVar1 != '\0') ||
             (iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvVar3 + 0x14),&DAT_009e69d6,0),
             iVar2 == 0)) {
            FUN_006e9f70();
            _free(pvVar3);
            return;
          }
          *(undefined4 *)((int)pvVar3 + 0x1c) = uStack_6c;
          *(void **)((int)pvVar3 + 0x20) = pvVar4;
          pvStack_74 = pvVar3;
          FUN_00846af0(&pvStack_74);
          iStack_7c = iStack_7c + 1;
          pvStack_78 = (void *)((int)pvStack_78 + 0x1c);
        } while (pvStack_78 != pvStack_70);
      }
      (**(code **)(*DAT_00b5ad24 + 4))(puStack_80);
      (**(code **)*puStack_80)(1);
      FUN_006e8780();
      if (pvStack_68 != (void *)0x0) {
        FUN_00405de0(pvStack_68,uStack_64,&uStack_6c,pvStack_78);
        _free(pvStack_68);
        return;
      }
      if (0xf < uStack_44) {
        _free(pvStack_58);
        return;
      }
      pvStack_68 = (void *)0x0;
    }
    if (0xf < uStack_28) {
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
      _free(pvStack_3c);
      return;
    }
  }
  return;
}


// ==== FUN_006e9e60 @ 0x006e9e60 ====

undefined4 FUN_006e9e60(int *param_1)

{
  int *in_ECX;
  
  if ((((*in_ECX == *param_1) && (in_ECX[1] == param_1[1])) && (in_ECX[2] == param_1[2])) &&
     (in_ECX[3] == param_1[3])) {
    return 1;
  }
  return 0;
}


// ==== FUN_006e9e90 @ 0x006e9e90 ====

void FUN_006e9e90(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  return;
}


// ==== FUN_006e9ef0 @ 0x006e9ef0 ====

undefined4 FUN_006e9ef0(void)

{
  return 0x60000002;
}


// ==== FUN_006e9f00 @ 0x006e9f00 ====

undefined4 FUN_006e9f00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_006e9f10 @ 0x006e9f10 ====

void FUN_006e9f10(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined1 local_4 [4];
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  puVar1 = (undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)puVar1 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0xffffff;
  *(undefined4 *)(in_ECX + 0x24) = 0xffffffff;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_4,puVar1,*(int *)(in_ECX + 0x14) + (int)puVar2);
  return;
}


// ==== FUN_006e9f70 @ 0x006e9f70 ====

void FUN_006e9f70(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_4 [4];
  
  puVar1 = (undefined4 *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    puVar3 = puVar1;
  }
  else {
    puVar3 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_4,puVar3,(undefined1 *)(*(int *)(in_ECX + 0x14) + (int)puVar2));
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)puVar1 = 0;
    return;
  }
  _free((void *)*puVar1);
  return;
}


// ==== FUN_006e9fd0 @ 0x006e9fd0 ====

undefined4 FUN_006e9fd0(void)

{
  return 0x60000003;
}


// ==== FUN_006e9fe0 @ 0x006e9fe0 ====

void FUN_006e9fe0(byte param_1)

{
  FUN_006ea010();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_006ea010 @ 0x006ea010 ====

void FUN_006ea010(void)

{
  void *_Memory;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = in_ECX[6];
  *in_ECX = &PTR_FUN_009e6af0;
  while( true ) {
    if (iVar4 == 0) {
      FUN_0046cfc0();
      *in_ECX = &PTR_FUN_0099cf40;
      return;
    }
    puVar1 = (undefined4 *)FUN_006ea150();
    _Memory = (void *)*puVar1;
    if (_Memory != (void *)0x0) break;
    FUN_006ea180();
    iVar4 = in_ECX[6];
  }
  puVar1 = (undefined4 *)((int)_Memory + 4);
  if (*(uint *)((int)_Memory + 0x18) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  puVar3 = (undefined1 *)((int)puVar2 + *(uint *)((int)_Memory + 0x14));
  if (*(uint *)((int)_Memory + 0x18) < 0x10) {
    puVar6 = puVar1;
    puVar2 = puVar1;
  }
  else {
    puVar6 = (undefined4 *)*puVar1;
    puVar2 = (undefined4 *)*puVar1;
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (int)puVar2 - (int)puVar6;
  }
  if (puVar3 == (undefined1 *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = (int)puVar3 - (int)puVar2;
  }
  if (*(uint *)((int)_Memory + 0x14) < uVar7) {
    FUN_0079dba3();
  }
  uVar5 = *(int *)((int)_Memory + 0x14) - uVar7;
  if (uVar5 < uVar8) {
    uVar8 = uVar5;
  }
  if (uVar8 != 0) {
    if (*(uint *)((int)_Memory + 0x18) < 0x10) {
      puVar6 = puVar1;
      puVar2 = puVar1;
    }
    else {
      puVar6 = (undefined4 *)*puVar1;
      puVar2 = (undefined4 *)*puVar1;
    }
    _memmove((void *)((int)puVar6 + uVar7),(void *)((int)puVar2 + uVar7 + uVar8),
             (*(int *)((int)_Memory + 0x14) - uVar8) - uVar7);
    iVar4 = *(int *)((int)_Memory + 0x14) - uVar8;
    *(int *)((int)_Memory + 0x14) = iVar4;
    if (*(uint *)((int)_Memory + 0x18) < 0x10) {
      puVar2 = puVar1;
    }
    else {
      puVar2 = (undefined4 *)*puVar1;
    }
    *(undefined1 *)((int)puVar2 + iVar4) = 0;
  }
  if (*(uint *)((int)_Memory + 0x18) < 0x10) {
    *(undefined4 *)((int)_Memory + 0x18) = 0xf;
    *(undefined4 *)((int)_Memory + 0x14) = 0;
    *(undefined1 *)puVar1 = 0;
    _free(_Memory);
    return;
  }
  _free((void *)*puVar1);
  return;
}


// ==== FUN_006ea150 @ 0x006ea150 ====

int FUN_006ea150(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  
  uVar3 = (uint)in_ECX[1] >> 2;
  iVar2 = uVar3 * -4;
  uVar1 = *(uint *)(*in_ECX + 8);
  if (uVar1 <= uVar3) {
    uVar3 = uVar3 - uVar1;
  }
  return *(int *)(*(int *)(*in_ECX + 4) + uVar3 * 4) + (in_ECX[1] + iVar2) * 4;
}


// ==== FUN_006ea180 @ 0x006ea180 ====

void FUN_006ea180(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
    if ((uint)(*(int *)(in_ECX + 8) * 4) <= *(uint *)(in_ECX + 0xc)) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
    iVar1 = *(int *)(in_ECX + 0x10) + -1;
    *(int *)(in_ECX + 0x10) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
  }
  return;
}


// ==== FUN_006ea1c0 @ 0x006ea1c0 ====

undefined1 FUN_006ea1c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x54);
}


// ==== FUN_006ea1d0 @ 0x006ea1d0 ====

undefined4 FUN_006ea1d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x58);
}


// ==== FUN_006ea1e0 @ 0x006ea1e0 ====

undefined4 FUN_006ea1e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x78);
}


// ==== FUN_006ea1f0 @ 0x006ea1f0 ====

int FUN_006ea1f0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x5c,0,0xffffffff);
  return param_1;
}


// ==== FUN_006ea220 @ 0x006ea220 ====

void FUN_006ea220(uint param_1)

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
    uVar2 = FUN_004eb8e0();
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
    if (param_1 == 0) goto LAB_006ea34c;
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
    if (uVar4 == 0) goto LAB_006ea34c;
    puVar5 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
LAB_006ea34c:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006ea370 @ 0x006ea370 ====

void FUN_006ea370(byte param_1)

{
  void *in_ECX;
  
  FUN_006e86a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ea390 @ 0x006ea390 ====

void FUN_006ea390(void)

{
  void *_Memory;
  undefined1 local_28 [4];
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ca68;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_gh_addquest_009e6b78,0xb);
  _Memory = (void *)0x1;
  local_4 = 0;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_28);
  if (uStack_18 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006ea410 @ 0x006ea410 ====

void FUN_006ea410(void)

{
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ca7a;
  pvStack_c = ExceptionList;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_gh_addquest_009e6b84,0xb);
  local_4 = 0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_006ea490 @ 0x006ea490 ====

void FUN_006ea490(void)

{
  FUN_006f32a0();
  FUN_006f31f0();
  FUN_006f3170();
  FUN_006f30c0();
  FUN_006f2fb0();
  FUN_006f2e70();
  FUN_006f2a00();
  FUN_006f28c0();
  FUN_006f27d0();
  FUN_006f26e0();
  FUN_006f25a0();
  FUN_006f24f0();
  FUN_006f25a0();
  FUN_006f2400();
  FUN_006f2310();
  FUN_006f21d0();
  FUN_006f20d0();
  FUN_006f1fd0();
  FUN_006f1ee0();
  FUN_006f1e30();
  FUN_006f1d80();
  FUN_006f1c90();
  FUN_006f1c20();
  FUN_006f1bb0();
  FUN_006f1ac0();
  FUN_006f1980();
  FUN_006f1910();
  FUN_006f18a0();
  FUN_006f1830();
  FUN_006f1780();
  FUN_006f1710();
  FUN_006f16a0();
  FUN_006f15b0();
  FUN_006f14b0();
  FUN_006f1440();
  FUN_006f1350();
  FUN_006f1210();
  FUN_006f1120();
  FUN_006f1030();
  FUN_006f0f40();
  FUN_006f0e00();
  FUN_006f0d10();
  FUN_006f0ca0();
  FUN_006f0bb0();
  FUN_006f0b00();
  FUN_006ea970();
  FUN_006f0a90();
  FUN_006f09a0();
  FUN_006f08c0();
  FUN_006f0770();
  FUN_006f06b0();
  FUN_006f05c0();
  FUN_006f0510();
  FUN_006f0450();
  FUN_006f0310();
  FUN_006f02a0();
  FUN_006f01b0();
  FUN_006f00c0();
  FUN_006effd0();
  FUN_006efee0();
  FUN_006efe30();
  FUN_006ea390();
  return;
}


// ==== FUN_006ea5d0 @ 0x006ea5d0 ====

void FUN_006ea5d0(void)

{
  FUN_006f32f0();
  FUN_006f3270();
  FUN_006f31c0();
  FUN_006f3070();
  FUN_006f29b0();
  FUN_006f2f60();
  FUN_006f2d40();
  FUN_006f29b0();
  FUN_006f2880();
  FUN_006f2790();
  FUN_006f2570();
  FUN_006f2690();
  FUN_006f24b0();
  FUN_006f23c0();
  FUN_006f22c0();
  FUN_006f2190();
  FUN_006f2090();
  FUN_006f1f90();
  FUN_006f1eb0();
  FUN_006f1e00();
  FUN_006f1d40();
  FUN_006f1c70();
  FUN_006f1c00();
  FUN_006f1b70();
  FUN_006f1a70();
  FUN_006f1960();
  FUN_006f18f0();
  FUN_006f1880();
  FUN_006f1800();
  FUN_006f1760();
  FUN_006f16f0();
  FUN_006f1660();
  FUN_006f1570();
  FUN_006f1490();
  FUN_006f1400();
  FUN_006f1300();
  FUN_006f11d0();
  FUN_006f10e0();
  FUN_006f0ff0();
  FUN_006f0ef0();
  FUN_006f0dc0();
  FUN_006f0cf0();
  FUN_006f0c60();
  FUN_006f0b80();
  FUN_006eaa60();
  FUN_006f0ae0();
  FUN_006f0970();
  FUN_006f3140();
  FUN_006f0940();
  FUN_006f0860();
  FUN_006f0730();
  FUN_006f0670();
  FUN_006f0590();
  FUN_006f04d0();
  FUN_006f0400();
  FUN_006f02f0();
  FUN_006f0260();
  FUN_006f0170();
  FUN_006f0080();
  FUN_006eff90();
  FUN_006efeb0();
  FUN_006ea410();
  return;
}


// ==== FUN_006ea710 @ 0x006ea710 ====

void FUN_006ea710(void)

{
  FUN_006ea5d0();
  FUN_006ea490();
  return;
}


// ==== FUN_006ea720 @ 0x006ea720 ====

undefined4 FUN_006ea720(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ca9b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x28);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_006edeb0(param_1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_006ea780 @ 0x006ea780 ====

undefined4 FUN_006ea780(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cab0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x2c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_006ed650(param_1,param_2);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_006ea7e0 @ 0x006ea7e0 ====

undefined4
FUN_006ea7e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cac5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x40);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_006ee810(param_1,param_2,param_3,param_4,param_5);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_006ea850 @ 0x006ea850 ====

undefined4 FUN_006ea850(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cada;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x28);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_006ee2b0(param_1,param_2);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_006ea8b0 @ 0x006ea8b0 ====

undefined4 FUN_006ea8b0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098caef;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x38);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_006f34b0(param_1,param_2);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_006ea910 @ 0x006ea910 ====

undefined4 FUN_006ea910(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cb04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_006f3570(pvVar1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_006ea970 @ 0x006ea970 ====

void FUN_006ea970(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cb3a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5ad9c == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006f5a40(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5ad94 == 0) {
    pvVar1 = operator_new(4);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_006f4ff0(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5ad98 == 0) {
    pvVar1 = operator_new(0x38);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      FUN_006f4dc0(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5ad90 == 0) {
    pvVar1 = operator_new(8);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      FUN_006f3a20(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006eaa60 @ 0x006eaa60 ====

void FUN_006eaa60(void)

{
  if (DAT_00b5ad9c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad9c)(1);
  }
  if (DAT_00b5ad94 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad94)(1);
  }
  if (DAT_00b5ad98 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad98)(1);
  }
  if (DAT_00b5ad90 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad90)(1);
  }
  return;
}


// ==== FUN_006eaab0 @ 0x006eaab0 ====

void FUN_006eaab0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cb5b;
  local_c = ExceptionList;
  if (DAT_00b5ae04 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006f5cd0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006eab00 @ 0x006eab00 ====

void FUN_006eab00(void)

{
  if (DAT_00b5ae04 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae04)(1);
  }
  return;
}


// ==== FUN_006eab20 @ 0x006eab20 ====

void FUN_006eab20(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cb7b;
  local_c = ExceptionList;
  if (DAT_00b5ae08 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006f6ea0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006eab70 @ 0x006eab70 ====

void FUN_006eab70(void)

{
  if (DAT_00b5ae08 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae08)(1);
  }
  return;
}


// ==== FUN_006eab90 @ 0x006eab90 ====

void FUN_006eab90(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cb9b;
  local_c = ExceptionList;
  if (DAT_00b5ae0c == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006f7310(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006eabe0 @ 0x006eabe0 ====

void FUN_006eabe0(void)

{
  if (DAT_00b5ae0c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae0c)(1);
  }
  return;
}


// ==== FUN_006eac00 @ 0x006eac00 ====

void FUN_006eac00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b240c;
  return;
}


// ==== FUN_006eac10 @ 0x006eac10 ====

void FUN_006eac10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6be8;
  return;
}


// ==== FUN_006eac40 @ 0x006eac40 ====

uint FUN_006eac40(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x20001) && (param_1[1] == 0x20)) {
    uVar1 = (**(code **)(*DAT_00b5b190 + 4))();
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006eac80 @ 0x006eac80 ====

void FUN_006eac80(byte param_1)

{
  void *in_ECX;
  
  FUN_006eac00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eaca0 @ 0x006eaca0 ====

void FUN_006eaca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b240c;
  return;
}


// ==== FUN_006eacb0 @ 0x006eacb0 ====

void FUN_006eacb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6c48;
  return;
}


// ==== FUN_006eacc0 @ 0x006eacc0 ====

undefined4 FUN_006eacc0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 != '\0') {
    return 0;
  }
  if (*(int *)(param_1 + 4) == 9) {
    cVar1 = (**(code **)(*DAT_00b5a78c + 0x54))();
    (**(code **)(*DAT_00b5a78c + 0x10))(cVar1 == '\0');
  }
  else {
    if (*(int *)(param_1 + 4) != 0x49) {
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5aef4 + 0x58))();
    if (cVar1 != '\x01') {
      cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
      if (cVar1 == '\0') {
        (**(code **)(*DAT_00b5a78c + 0x20))();
        return 1;
      }
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009e6c34;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  return 1;
}


// ==== FUN_006ead70 @ 0x006ead70 ====

uint FUN_006ead70(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x20001) {
    uVar1 = FUN_006eacc0(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006eada0 @ 0x006eada0 ====

undefined4 FUN_006eada0(void)

{
  return 0x70080004;
}


// ==== FUN_006eadb0 @ 0x006eadb0 ====

void FUN_006eadb0(byte param_1)

{
  void *in_ECX;
  
  FUN_006eaca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eadd0 @ 0x006eadd0 ====

void FUN_006eadd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b240c;
  return;
}


// ==== FUN_006eade0 @ 0x006eade0 ====

void FUN_006eade0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6ca8;
  return;
}


// ==== FUN_006eadf0 @ 0x006eadf0 ====

undefined4 FUN_006eadf0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    switch(*(undefined4 *)(param_1 + 4)) {
    case 0x4a:
      (**(code **)(*DAT_00b5ad84 + 0x14))();
      return 1;
    case 0x52:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009e6c94;
      FUN_00797a20(puVar2);
      return 1;
    case 0x70:
      (**(code **)(*DAT_00b5ad54 + 0x10))(0xf);
      return 1;
    case 0x71:
      (**(code **)(*DAT_00b5ad54 + 0x10))(0x10);
      return 1;
    case 0x72:
      (**(code **)(*DAT_00b5ad54 + 0x10))(0x11);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006eaef0 @ 0x006eaef0 ====

uint FUN_006eaef0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x20001) {
    uVar1 = FUN_006eadf0(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006eaf20 @ 0x006eaf20 ====

undefined4 FUN_006eaf20(void)

{
  return 0x70050007;
}


// ==== FUN_006eaf30 @ 0x006eaf30 ====

void FUN_006eaf30(byte param_1)

{
  void *in_ECX;
  
  FUN_006eadd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eaf50 @ 0x006eaf50 ====

void FUN_006eaf50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b240c;
  return;
}


// ==== FUN_006eaf60 @ 0x006eaf60 ====

void FUN_006eaf60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6cf4;
  *(undefined1 *)(in_ECX + 1) = 1;
  return;
}


// ==== FUN_006eaf70 @ 0x006eaf70 ====

undefined4 FUN_006eaf70(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  bool bVar5;
  undefined4 local_8;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 0xd) {
    cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
    if (cVar1 == '\0') {
      iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(4);
      if (iVar3 != 0) {
        FUN_00668370();
        return 1;
      }
      (**(code **)(*DAT_00b5ad0c + 0x30))();
    }
    return 1;
  }
  if (iVar3 == 0x12) {
    uVar4 = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    puVar2 = operator_new(0x10);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
      goto LAB_006eaff3;
    }
  }
  else {
    if (iVar3 != 0x56) {
      return 0;
    }
    bVar5 = *(char *)(in_ECX + 4) == '\0';
    *(bool *)(in_ECX + 4) = bVar5;
    uVar4 = 0;
    local_8 = CONCAT31(local_8._1_3_,bVar5);
    puVar2 = operator_new(0x10);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
      goto LAB_006eaff3;
    }
  }
  puVar2 = (undefined4 *)0x0;
LAB_006eaff3:
  puVar2[1] = uVar4;
  puVar2[2] = local_8;
  puVar2[3] = 0;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_006eb060 @ 0x006eb060 ====

undefined4 FUN_006eb060(int param_1)

{
  undefined4 *puVar1;
  uint local_8;
  
  if (*(int *)(param_1 + 4) != 0x12) {
    return 0;
  }
  local_8 = local_8 & 0xffffff00;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7964;
    puVar1[3] = 0;
    *(undefined1 *)(puVar1 + 2) = 1;
  }
  puVar1[1] = 1;
  puVar1[2] = local_8;
  puVar1[3] = 0;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_006eb0d0 @ 0x006eb0d0 ====

uint FUN_006eb0d0(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x20001) {
    uVar2 = FUN_006eaf70(param_1);
    if ((char)uVar2 == '\x01') {
      return uVar2;
    }
  }
  else {
    uVar2 = iVar1 - 0x20002;
    if (uVar2 == 0) {
      uVar2 = FUN_006eb060(param_1);
      if ((char)uVar2 == '\x01') {
        return uVar2;
      }
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_006eb120 @ 0x006eb120 ====

void FUN_006eb120(byte param_1)

{
  void *in_ECX;
  
  FUN_006eaf50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eb140 @ 0x006eb140 ====

void FUN_006eb140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006eb150 @ 0x006eb150 ====

void FUN_006eb150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eb170 @ 0x006eb170 ====

void FUN_006eb170(char param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x20) == '\0') {
    if ((param_1 != '\0') && (param_1 == '\x01')) {
      pvVar1 = operator_new(0x400);
      *(undefined4 *)((int)pvVar1 + 8) = 0;
      *(undefined4 *)((int)pvVar1 + 0xc) = 0x3020002;
      *(undefined2 *)((int)pvVar1 + 6) = 0x2c;
      iVar2 = FUN_004244d0();
      if (*(uint *)(in_ECX + 0x1c) < 0x10) {
        iVar3 = in_ECX + 8;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8);
      }
      FUN_0047aa30(iVar2 + 0x10,&DAT_009e6d38,iVar3);
      FUN_004d8570(iVar2);
    }
    *(undefined1 *)(in_ECX + 0x20) = 1;
  }
  return;
}


// ==== FUN_006eb1f0 @ 0x006eb1f0 ====

void FUN_006eb1f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d60;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009e6d54;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_006eb230 @ 0x006eb230 ====

void FUN_006eb230(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cbc0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e6d60;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  local_4 = 1;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 8) = 0;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_006eb2b0 @ 0x006eb2b0 ====

void FUN_006eb2b0(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cbd5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x24);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00401660(param_1,0,0xffffffff);
    FUN_006eb230();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006eb320 @ 0x006eb320 ====

void FUN_006eb320(byte param_1)

{
  void *in_ECX;
  
  FUN_006eb1f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eb380 @ 0x006eb380 ====

void FUN_006eb380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e7094;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af44 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af44 = in_ECX;
  return;
}


// ==== FUN_006eb3f0 @ 0x006eb3f0 ====

undefined4 FUN_006eb3f0(undefined2 param_1,undefined2 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  if (DAT_00b5ac1c != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    if (piVar1 != (int *)0x0) {
      _uStack_4 = CONCAT22(param_2,param_1);
      uVar2 = (**(code **)(*piVar1 + 0x14))(&uStack_4);
      return uVar2;
    }
  }
  return 1;
}


// ==== FUN_006eb430 @ 0x006eb430 ====

uint FUN_006eb430(int param_1)

{
  uint in_EAX;
  int *piVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (DAT_00b5ac1c != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    in_EAX = 0;
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar1 + 0xc))(param_1);
      return uVar2;
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006eb460 @ 0x006eb460 ====

uint FUN_006eb460(int param_1)

{
  uint in_EAX;
  int *piVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (DAT_00b5ac1c != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    in_EAX = 0;
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar1 + 0x10))(param_1);
      return uVar2;
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006eb490 @ 0x006eb490 ====

undefined4 FUN_006eb490(int *param_1)

{
  int *piVar1;
  undefined4 extraout_EAX;
  int iVar2;
  undefined4 extraout_EAX_00;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX_01;
  undefined2 extraout_var;
  undefined1 *puVar5;
  ushort uVar6;
  ushort uVar7;
  undefined1 auStack_9c [4];
  undefined1 uStack_98;
  undefined4 uStack_88;
  undefined4 uStack_84;
  ushort *puStack_80;
  ushort uStack_6c;
  ushort uStack_6a;
  int iStack_68;
  uint uStack_64;
  int iStack_60;
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  undefined1 uStack_54;
  undefined1 uStack_53;
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  uint uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0098cbf8;
  local_14 = ExceptionList;
  uVar6 = 0;
  if (param_1 != (int *)0x0) {
    ExceptionList = &local_14;
    piVar1 = (int *)(**(code **)(*param_1 + 0x2c))();
    if (piVar1 == (int *)0x0) {
      puStack_80 = (ushort *)&DAT_009e6df8;
      uStack_38 = 0xf;
      uStack_3c = 0;
      pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
      uStack_84 = 0x6eb4e7;
      FUN_00401740();
      uStack_c = 0;
      puStack_80 = (ushort *)0x6eb4f5;
      FUN_00403e50();
      if (0xf < uStack_38) {
        puStack_80 = (ushort *)0x6eb50d;
        _free(pvStack_4c);
        return extraout_EAX;
      }
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 4))();
      iStack_68 = iVar2;
      if (iVar2 != 0) {
        puVar5 = (undefined1 *)CONCAT22(extraout_var,*(short *)(iVar2 + 8));
        uVar3 = CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar2 + 4));
        uStack_64 = uVar3;
        puStack_5c = puVar5;
        if (*(short *)(iVar2 + 8) != 0) {
          do {
            uVar7 = 0;
            if ((short)uVar3 != 0) {
              iStack_60 = (uint)uVar6 * (uVar3 & 0xffff);
              do {
                piVar1 = *(int **)(iVar2 + 0xc + ((uint)uVar7 + iStack_60) * 4);
                if (piVar1 == (int *)0x0) {
                  puStack_80 = (ushort *)(uint)uVar7;
                  puStack_5c = auStack_9c;
                  uStack_84 = 0xf;
                  uStack_88 = 0;
                  uStack_98 = 0;
                  FUN_00401740(s_NULL_Cell_Flyweight___poscell_____009e6e18,0x29);
                  uVar4 = FUN_00404230(auStack_34);
                  uStack_c = 2;
                  FUN_00403e50(uVar4);
                  if (uStack_1c < 0x10) {
                    ExceptionList = local_14;
                    return 0;
                  }
                  puStack_80 = (ushort *)0x6eb6b2;
                  _free(pvStack_30);
                  return extraout_EAX_01;
                }
                uStack_58 = 1;
                uStack_6c = uVar7;
                uStack_6a = uVar6;
                iVar2 = (**(code **)(*piVar1 + 4))();
                uStack_54 = *(char *)(iVar2 + 8) == '\0';
                iVar2 = (**(code **)(*piVar1 + 4))();
                uStack_53 = *(char *)(iVar2 + 9) == '\0';
                puStack_80 = &uStack_6c;
                uStack_84 = 0x6eb61c;
                (**(code **)(*DAT_00b5a718 + 0xc))();
                uVar7 = uVar7 + 1;
                iVar2 = iStack_68;
              } while (uVar7 < (ushort)uStack_64);
              uVar3 = uStack_64;
              puVar5 = puStack_5c;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < (ushort)puVar5);
        }
        ExceptionList = local_14;
        return 1;
      }
      puStack_80 = (ushort *)0x6eb545;
      FUN_00401830();
      uStack_c = 1;
      puStack_80 = (ushort *)0x6eb557;
      FUN_00403e50();
      if (0xf < uStack_38) {
        puStack_80 = (ushort *)0x6eb56f;
        _free(pvStack_4c);
        return extraout_EAX_00;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}


// ==== FUN_006eb6d0 @ 0x006eb6d0 ====

undefined4 FUN_006eb6d0(int *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 extraout_EAX;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack_54;
  uint uStack_50;
  ushort uStack_4c;
  uint uStack_48;
  undefined4 uStack_44;
  int *piStack_40;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0098cc12;
  local_14 = ExceptionList;
  if (DAT_00b5ac1c != (int *)0x0) {
    ExceptionList = &local_14;
    piStack_40 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    if (piStack_40 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piStack_40 + 0x2c))();
      if (piVar4 == (int *)0x0) {
        uStack_1c = 0xf;
        uStack_20 = 0;
        pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
        FUN_00401740(&DAT_009e6e44,0xd);
        uStack_c = 0;
      }
      else {
        iVar5 = (**(code **)(*piVar4 + 4))();
        if (iVar5 != 0) {
          uStack_48._0_2_ = *(undefined2 *)(iVar5 + 4);
          uStack_4c = *(ushort *)(iVar5 + 8);
          if ((int *)param_1[0x13] == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)(**(code **)(*(int *)param_1[0x13] + 0x18))();
          }
          puVar6 = (ushort *)(**(code **)(*piVar4 + 0x3c))(0);
          uVar1 = *puVar6;
          uVar2 = puVar6[1];
          iVar5 = (**(code **)(*param_1 + 0x24))();
          uStack_48 = CONCAT22(uStack_48._2_2_,(ushort)*(byte *)(iVar5 + 0x3c));
          iVar5 = (**(code **)(*param_1 + 0x24))();
          uVar7 = (uint)(uVar1 >> 7) - (uStack_48 & 0xffff);
          uVar7 = ((int)uVar7 < 1) - 1 & uVar7;
          uVar8 = (uint)(uVar2 >> 7) - (uint)*(byte *)(iVar5 + 0x3d);
          iVar9 = (uStack_48 & 0xffff) + (uint)(uVar1 >> 7);
          uVar8 = ((int)uVar8 < 1) - 1 & uVar8;
          uStack_54 = uStack_4c - 1;
          if (iVar9 <= (int)(uStack_4c - 1)) {
            uStack_54 = iVar9;
          }
          uStack_50 = (uStack_50 & 0xffff) - 1;
          iVar5 = (uint)*(byte *)(iVar5 + 0x3d) + (uint)(uVar2 >> 7);
          if (iVar5 <= (int)uStack_50) {
            uStack_50 = iVar5;
          }
          if ((ushort)uVar8 <= (ushort)uStack_50) {
            uStack_48 = uVar7;
            do {
              if ((ushort)uVar7 <= (ushort)uStack_54) {
                do {
                  piVar4 = uStack_44;
                  piStack_40 = (int *)0x1;
                  uVar3 = (**(code **)(*uStack_44 + 0x14))(auStack_34 + -0x24);
                  piStack_40 = (int *)CONCAT31(piStack_40._1_3_,uVar3);
                  uVar3 = (**(code **)(*piVar4 + 0x18))(auStack_34 + -0x28);
                  uStack_44._0_2_ = CONCAT11(uVar3,(undefined1)uStack_44);
                  uStack_54 = CONCAT22((short)uVar8,(short)uVar7);
                  (**(code **)(*DAT_00b5a718 + 0xc))(&uStack_54,&uStack_48);
                  uVar7 = uVar7 + 1;
                } while ((ushort)uVar7 <= (ushort)uStack_54);
                uVar7 = uStack_48;
              }
              uVar8 = uVar8 + 1;
            } while ((ushort)uVar8 <= (ushort)uStack_50);
          }
          ExceptionList = pvStack_18;
          return 1;
        }
        FUN_00401830(&DAT_009e6e54);
        uStack_c = 1;
      }
      FUN_00403e50(auStack_34);
      if (0xf < uStack_1c) {
        _free(pvStack_30);
        return extraout_EAX;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}


// ==== FUN_006eb900 @ 0x006eb900 ====

int FUN_006eb900(void)

{
  int *piVar1;
  int iVar2;
  int extraout_EAX;
  void *_Memory;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cc2c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((DAT_00b5ac1c == (int *)0x0) ||
     (ExceptionList = &pvStack_c, piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))(),
     piVar1 == (int *)0x0)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740(&DAT_009e7068,0x12);
    uStack_4 = 0;
    FUN_00403e50(local_44);
    if (0xf < local_2c) {
      _Memory = local_40;
      goto LAB_006eb9b9;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
    if (iVar2 != 0) {
      ExceptionList = pvStack_c;
      return iVar2;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(&DAT_009e707c,0xd);
    uStack_4 = 1;
    FUN_00403e50(auStack_28);
    if (0xf < uStack_10) {
      _Memory = pvStack_24;
LAB_006eb9b9:
      _free(_Memory);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== FUN_006eb9e0 @ 0x006eb9e0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_006eb9e0(int *param_1)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uStack_1084;
  undefined1 auStack_1080 [4];
  undefined1 uStack_107c;
  undefined4 uStack_1074;
  uint uStack_1070;
  undefined4 uStack_106c;
  void *pvStack_1068;
  undefined1 auStack_1064 [4];
  void *pvStack_1060;
  uint uStack_1054;
  undefined4 uStack_1050;
  uint uStack_104c;
  undefined1 auStack_1048 [4];
  void *pvStack_1044;
  undefined4 uStack_1034;
  uint uStack_1030;
  undefined4 uStack_102c;
  void *pvStack_1028;
  uint uStack_1014;
  undefined4 auStack_1008 [256];
  char acStack_c06 [3050];
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0098cc86;
  local_14 = ExceptionList;
  pvStack_1c = (void *)0x6eba06;
  if (param_1 != (int *)0x0) {
    ExceptionList = &local_14;
    piVar3 = (int *)(**(code **)(*param_1 + 0x2c))();
    if (piVar3 == (int *)0x0) {
      uStack_1030 = 0xf;
      uStack_1034 = 0;
      pvStack_1044 = (void *)((uint)pvStack_1044 & 0xffffff00);
      FUN_00401740(s_pFlyweight____NULL_009e6da4,0x12);
      uStack_c = 0;
      FUN_00406880(auStack_1048);
      uStack_c = 0xffffffff;
      if (uStack_1030 < 0x10) {
        pcVar2 = (code *)swi(3);
        uVar4 = (*pcVar2)();
        return uVar4;
      }
      _free(pvStack_1044);
      return extraout_EAX;
    }
    puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
    puVar8 = auStack_1008;
    for (iVar7 = 0x3fb; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
    pcVar6 = acStack_c06;
    uStack_102c = auStack_1008[0];
    uStack_104c = 0xf;
    uStack_1050 = 0;
    pvStack_1060 = (void *)((uint)pvStack_1060 & 0xffffff00);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_c06,(int)pcVar6 - (int)(acStack_c06 + 1));
    uStack_c = 1;
    iVar7 = FUN_00403620(0,uStack_1050,s_<<_Emtpy_>>_009e6db8,0xb);
    if (iVar7 != 0) {
      pvStack_1068 = (void *)0xf;
      uStack_106c = 0;
      uStack_107c = 0;
      FUN_00401740(s_MapRedCell__009e6dc4,0xb);
      uStack_c._0_1_ = 2;
      FUN_00401ff0(auStack_1064,0,0xffffffff);
      uVar4 = FUN_00402220(auStack_1048,auStack_1080,s_Loading____009e6dd0);
      uStack_c._0_1_ = 3;
      FUN_00796d50(uVar4);
      uStack_c._0_1_ = 2;
      if (0xf < uStack_1030) {
        _free(pvStack_1044);
        return extraout_EAX_01;
      }
      pvStack_1028 = operator_new(0x10);
      uStack_c._0_1_ = 4;
      if (pvStack_1028 == (void *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5 = (undefined4 *)FUN_0081d3a0(auStack_1080);
      }
      uStack_c._0_1_ = 2;
      if (puVar5 == (undefined4 *)0x0) {
        FUN_00401830(s_pReader____NULL_009e6ddc);
        uStack_c._0_1_ = 5;
        FUN_00406880(auStack_1048);
        uStack_c = CONCAT31(uStack_c._1_3_,2);
        if (uStack_1030 < 0x10) {
          pcVar2 = (code *)swi(3);
          uVar4 = (*pcVar2)();
          return uVar4;
        }
        _free(pvStack_1044);
        return extraout_EAX_02;
      }
      (**(code **)(*DAT_00b5a9f8 + 8))(uStack_102c,puVar5);
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
      uVar4 = FUN_00402220(&uStack_102c,auStack_1080 + -8,s_Loading_OK_009e6dec);
      local_14 = (void *)CONCAT31(local_14._1_3_,6);
      FUN_00796d50(uVar4);
      if (0xf < uStack_1014) {
        _free(pvStack_1028);
        return extraout_EAX_03;
      }
      if (0xf < uStack_1070) {
        _free(uStack_1084);
        return extraout_EAX_04;
      }
      uStack_1070 = 0xf;
      uStack_1074 = 0;
      if (uStack_1054 < 0x10) {
        ExceptionList = pvStack_1c;
        return 1;
      }
      _free(pvStack_1068);
      return extraout_EAX_05;
    }
    if (0xf < uStack_104c) {
      _free(pvStack_1060);
      return extraout_EAX_00;
    }
  }
  ExceptionList = local_14;
  return 0;
}


// ==== FUN_006ebcc0 @ 0x006ebcc0 ====

uint FUN_006ebcc0(ushort param_1,ushort param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ccb0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_006eb900();
  if (piVar1 == (int *)0x0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    local_4 = 0;
    FUN_00403e50();
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740();
      local_4 = 1;
      FUN_00403e50();
    }
    else {
      if ((param_1 < *(ushort *)(iVar2 + 4)) && (param_2 < *(ushort *)(iVar2 + 8))) {
        piVar1 = *(int **)(iVar2 + 0xc +
                          ((uint)*(ushort *)(iVar2 + 4) * (uint)param_2 + (uint)param_1) * 4);
        if (piVar1 == (int *)0x0) {
          FUN_00401830(s_NULL_Cell_Flyweight___poscell_____009e6ea8);
          uVar3 = FUN_00404230(auStack_28);
          local_4 = 3;
          FUN_00403e50(uVar3);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar2 = (**(code **)(*piVar1 + 4))();
        ExceptionList = local_c;
        return (uint)*(byte *)(iVar2 + 10);
      }
      FUN_00401830(s_poscell___d___d___is_out_of_boun_009e6e84);
      uVar3 = FUN_00404230(local_44);
      local_4 = 2;
      FUN_00403e50(uVar3);
    }
  }
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_40);
  return extraout_EAX;
}


// ==== FUN_006ebe50 @ 0x006ebe50 ====

uint FUN_006ebe50(ushort param_1,ushort param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ccda;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_006eb900();
  if (piVar1 == (int *)0x0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    local_4 = 0;
    FUN_00403e50();
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740();
      local_4 = 1;
      FUN_00403e50();
    }
    else {
      if ((param_1 < *(ushort *)(iVar2 + 4)) && (param_2 < *(ushort *)(iVar2 + 8))) {
        piVar1 = *(int **)(iVar2 + 0xc +
                          ((uint)*(ushort *)(iVar2 + 4) * (uint)param_2 + (uint)param_1) * 4);
        if (piVar1 == (int *)0x0) {
          FUN_00401830(s_NULL_Cell_Flyweight___poscell_____009e6f18);
          uVar3 = FUN_00404230(auStack_28);
          local_4 = 3;
          FUN_00403e50(uVar3);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar2 = (**(code **)(*piVar1 + 4))();
        ExceptionList = local_c;
        return (uint)*(byte *)(iVar2 + 8);
      }
      FUN_00401830(s_poscell___d___d___is_out_of_boun_009e6ef4);
      uVar3 = FUN_00404230(local_44);
      local_4 = 2;
      FUN_00403e50(uVar3);
    }
  }
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_40);
  return extraout_EAX;
}


// ==== FUN_006ebfe0 @ 0x006ebfe0 ====

uint FUN_006ebfe0(ushort param_1,ushort param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cd04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_006eb900();
  if (piVar1 == (int *)0x0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    local_4 = 0;
    FUN_00403e50();
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740();
      local_4 = 1;
      FUN_00403e50();
    }
    else {
      if ((param_1 < *(ushort *)(iVar2 + 4)) && (param_2 < *(ushort *)(iVar2 + 8))) {
        piVar1 = *(int **)(iVar2 + 0xc +
                          ((uint)*(ushort *)(iVar2 + 4) * (uint)param_2 + (uint)param_1) * 4);
        if (piVar1 == (int *)0x0) {
          FUN_00401830(s_NULL_Cell_Flyweight___poscell_____009e6f88);
          uVar3 = FUN_00404230(auStack_28);
          local_4 = 3;
          FUN_00403e50(uVar3);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar2 = (**(code **)(*piVar1 + 4))();
        ExceptionList = local_c;
        return (uint)*(byte *)(iVar2 + 9);
      }
      FUN_00401830(s_poscell___d___d___is_out_of_boun_009e6f64);
      uVar3 = FUN_00404230(local_44);
      local_4 = 2;
      FUN_00403e50(uVar3);
    }
  }
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_40);
  return extraout_EAX;
}


// ==== FUN_006ec2b0 @ 0x006ec2b0 ====

uint FUN_006ec2b0(ushort param_1,ushort param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  uint extraout_EAX;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cd50;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_006eb900();
  if (piVar1 == (int *)0x0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    local_4 = 0;
    FUN_00403e50();
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740();
      local_4 = 1;
      FUN_00403e50();
    }
    else {
      if ((param_1 < *(ushort *)(iVar2 + 4)) && (param_2 < *(ushort *)(iVar2 + 8))) {
        piVar1 = *(int **)(iVar2 + 0xc +
                          ((uint)*(ushort *)(iVar2 + 4) * (uint)param_2 + (uint)param_1) * 4);
        if (piVar1 == (int *)0x0) {
          FUN_00401830(s_NULL_Cell_Flyweight___poscell_____009e703c);
          uVar3 = FUN_00404230(auStack_28);
          local_4 = 3;
          FUN_00403e50(uVar3);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        puVar4 = (ushort *)(**(code **)(*piVar1 + 4))();
        ExceptionList = local_c;
        return (uint)*puVar4;
      }
      FUN_00401830(s_poscell___d___d___is_out_of_boun_009e7018);
      uVar3 = FUN_00404230(local_44);
      local_4 = 2;
      FUN_00403e50(uVar3);
    }
  }
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_40);
  return extraout_EAX;
}


// ==== FUN_006ec440 @ 0x006ec440 ====

void FUN_006ec440(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e7094;
  DAT_00b5af44 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec470 @ 0x006ec470 ====

void FUN_006ec470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e70b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec490 @ 0x006ec490 ====

undefined4 FUN_006ec490(void)

{
  return DAT_00b5b194;
}


// ==== FUN_006ec4a0 @ 0x006ec4a0 ====

void FUN_006ec4a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e70bc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b194 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b194 = in_ECX;
  return;
}


// ==== FUN_006ec4d0 @ 0x006ec4d0 ====

void FUN_006ec4d0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b194 = 0;
  *in_ECX = &PTR_FUN_009e70b0;
  return;
}


// ==== FUN_006ec4f0 @ 0x006ec4f0 ====

void FUN_006ec4f0(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5110006;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_006ec540 @ 0x006ec540 ====

void FUN_006ec540(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec4d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec560 @ 0x006ec560 ====

void FUN_006ec560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec580 @ 0x006ec580 ====

void FUN_006ec580(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5a9e4 + 0x50))();
    }
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_006ec5b0 @ 0x006ec5b0 ====

undefined4 * FUN_006ec5b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009e7118;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_006ec5d0 @ 0x006ec5d0 ====

void FUN_006ec5d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec5f0 @ 0x006ec5f0 ====

void FUN_006ec5f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec610 @ 0x006ec610 ====

void FUN_006ec610(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5a9e4 + 0x4c))();
    }
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_006ec640 @ 0x006ec640 ====

undefined4 * FUN_006ec640(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009e7174;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_006ec660 @ 0x006ec660 ====

void FUN_006ec660(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec5f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec680 @ 0x006ec680 ====

void FUN_006ec680(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec6a0 @ 0x006ec6a0 ====

void FUN_006ec6a0(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5a9e4 + 0x48))();
    }
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_006ec6d0 @ 0x006ec6d0 ====

undefined4 * FUN_006ec6d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009e71d0;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_006ec6f0 @ 0x006ec6f0 ====

void FUN_006ec6f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec680();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec710 @ 0x006ec710 ====

void FUN_006ec710(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec730 @ 0x006ec730 ====

void FUN_006ec730(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5a9e4 + 0x44))();
    }
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_006ec780 @ 0x006ec780 ====

void FUN_006ec780(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec7a0 @ 0x006ec7a0 ====

void FUN_006ec7a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec7d0 @ 0x006ec7d0 ====

void FUN_006ec7d0(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5a9e4 + 0x38))(*(undefined4 *)(in_ECX + 4));
    }
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_006ec830 @ 0x006ec830 ====

void FUN_006ec830(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec7a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec850 @ 0x006ec850 ====

void FUN_006ec850(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x20) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5a9e4 + 0x34))();
    }
    *(undefined1 *)(in_ECX + 0x20) = 1;
  }
  return;
}


// ==== FUN_006ec8a0 @ 0x006ec8a0 ====

void FUN_006ec8a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e72e4;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009e6d54;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_006ec910 @ 0x006ec910 ====

void FUN_006ec910(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec8a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec930 @ 0x006ec930 ====

void FUN_006ec930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec950 @ 0x006ec950 ====

void FUN_006ec950(char param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    piVar1 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 8))();
      if ((iVar2 == 6) && (param_1 == '\x01')) {
        (**(code **)(*DAT_00b5b0d4 + 100))();
      }
      *(undefined1 *)(in_ECX + 4) = 1;
    }
  }
  return;
}


// ==== FUN_006ec9b0 @ 0x006ec9b0 ====

void FUN_006ec9b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec930();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ec9d0 @ 0x006ec9d0 ====

void FUN_006ec9d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ec9f0 @ 0x006ec9f0 ====

void FUN_006ec9f0(char param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    piVar1 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 8))();
      if ((iVar2 == 7) && (param_1 == '\x01')) {
        (**(code **)(*DAT_00b5ae74 + 0x24))();
      }
      *(undefined1 *)(in_ECX + 4) = 1;
    }
  }
  return;
}


// ==== FUN_006eca30 @ 0x006eca30 ====

undefined4 * FUN_006eca30(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009e739c;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_006eca50 @ 0x006eca50 ====

void FUN_006eca50(byte param_1)

{
  void *in_ECX;
  
  FUN_006ec9d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eca70 @ 0x006eca70 ====

void FUN_006eca70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e73f8;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009e6d54;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_006ecab0 @ 0x006ecab0 ====

void FUN_006ecab0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cd70;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e73f8;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  local_4 = 1;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 8) = 0;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_006ecb30 @ 0x006ecb30 ====

void FUN_006ecb30(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x20) == '\0') {
    FUN_00401660(in_ECX + 4,0,0xffffffff);
    (**(code **)(*DAT_00b5ae3c + 0x9c))();
    *(undefined1 *)(in_ECX + 0x20) = 1;
  }
  return;
}


// ==== FUN_006ecb80 @ 0x006ecb80 ====

void FUN_006ecb80(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098cd85;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x24);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00401660(param_1,0,0xffffffff);
    FUN_006ecab0();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ecbf0 @ 0x006ecbf0 ====

void FUN_006ecbf0(byte param_1)

{
  void *in_ECX;
  
  FUN_006eca70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ecc10 @ 0x006ecc10 ====

void FUN_006ecc10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ecc30 @ 0x006ecc30 ====

void FUN_006ecc30(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5aca8 + 0xd4))();
    }
    else {
      (**(code **)(*DAT_00b5aca8 + 0xd8))();
    }
    (**(code **)(*DAT_00b5aca8 + 0x90))();
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_006ecc70 @ 0x006ecc70 ====

undefined4 * FUN_006ecc70(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009e7454;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_006ecc90 @ 0x006ecc90 ====

void FUN_006ecc90(byte param_1)

{
  void *in_ECX;
  
  FUN_006ecc10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006eccb0 @ 0x006eccb0 ====

void FUN_006eccb0(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5aca8 + 0xf4))
                (CONCAT31((int3)((uint)(in_ECX + 8) >> 8),*(undefined1 *)(in_ECX + 4)),in_ECX + 8,
                 *(undefined4 *)(in_ECX + 0x24));
    }
    (**(code **)(*DAT_00b5aca8 + 100))();
    *(undefined1 *)(in_ECX + 0x28) = 1;
  }
  return;
}


// ==== FUN_006eccf0 @ 0x006eccf0 ====

void FUN_006eccf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e74b0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009e6d54;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006ecd30 @ 0x006ecd30 ====

void FUN_006ecd30(undefined1 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  undefined4 in_stack_00000024;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cdab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e74b0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  local_4 = 2;
  *(undefined1 *)(in_ECX + 1) = param_1;
  FUN_00401660(&param_2,0,0xffffffff);
  in_ECX[9] = in_stack_00000024;
  *(undefined1 *)(in_ECX + 10) = 0;
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_006ecdc0 @ 0x006ecdc0 ====

undefined4 FUN_006ecdc0(undefined4 param_1,undefined1 param_2,void *param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  uint in_stack_00000020;
  undefined4 in_stack_00000024;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cdc8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x2c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    FUN_00401660(&param_2,0,0xffffffff);
    uVar2 = FUN_006ecd30(param_1);
  }
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return uVar2;
  }
  _free(param_3);
  return extraout_EAX;
}


// ==== FUN_006ece60 @ 0x006ece60 ====

void FUN_006ece60(byte param_1)

{
  void *in_ECX;
  
  FUN_006eccf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ece80 @ 0x006ece80 ====

void FUN_006ece80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_006ecea0 @ 0x006ecea0 ====

void FUN_006ecea0(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    if (param_1 == '\x01') {
      (**(code **)(*DAT_00b5aca8 + 0xa8))();
    }
    (**(code **)(*DAT_00b5aca8 + 0x54))();
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_006ecf00 @ 0x006ecf00 ====

void FUN_006ecf00(byte param_1)

{
  void *in_ECX;
  
  FUN_006ece80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ecf20 @ 0x006ecf20 ====

void FUN_006ecf20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e7568;
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
    *in_ECX = &PTR_FUN_009e6d54;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_006ecf80 @ 0x006ecf80 ====

void FUN_006ecf80(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  undefined4 *unaff_FS_OFFSET;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ce03;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *in_ECX = &PTR_FUN_009e7568;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  local_4 = 2;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(&uStack00000020,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0xf) = 0;
  if (0xf < in_stack_0000001c) {
    _free(param_2);
  }
  if (0xf < in_stack_00000038) {
    _free(in_stack_00000024);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}


// ==== FUN_006ed030 @ 0x006ed030 ====

void FUN_006ed030(char param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ce1d;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 0x3c) == '\0') {
    if (param_1 == '\0') {
      ExceptionList = &local_c;
      FUN_00401660();
      local_4 = 0;
      FUN_00401660(in_ECX + 4,0,0xffffffff);
      local_4 = 0xffffffff;
      (**(code **)(*DAT_00b5aca8 + 0xb0))();
    }
    else if (param_1 == '\x01') {
      ExceptionList = &local_c;
      FUN_00401660();
      local_4 = 1;
      FUN_00401660(in_ECX + 4,0,0xffffffff);
      local_4 = 0xffffffff;
      (**(code **)(*DAT_00b5aca8 + 0xb0))();
    }
    *(undefined1 *)(in_ECX + 0x3c) = 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ed140 @ 0x006ed140 ====

undefined4 FUN_006ed140(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ce3a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pvVar1 = operator_new(0x40);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  FUN_00401660();
  local_4._0_1_ = 1;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  uVar2 = FUN_006ecf80();
  *unaff_FS_OFFSET = local_c;
  return uVar2;
}


// ==== FUN_006ed1f0 @ 0x006ed1f0 ====

void FUN_006ed1f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ecf20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ed210 @ 0x006ed210 ====

void FUN_006ed210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e75d8;
  return;
}


// ==== FUN_006ed220 @ 0x006ed220 ====

void FUN_006ed220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e75d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ed250 @ 0x006ed250 ====

undefined4 FUN_006ed250(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar1 + 0x88) == (int *)0x0) {
    return 0;
  }
  uStack_4 = 2;
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x88) + 0x14))();
  (**(code **)(*piVar2 + 0x10))(&uStack_4);
  return 1;
}


// ==== FUN_006ed290 @ 0x006ed290 ====

void FUN_006ed290(void)

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
  char acStack_19 [25];
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5220005;
    *(undefined2 *)((int)pvVar4 + 6) = 0x34;
    iVar5 = FUN_004244d0();
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(in_ECX + 0xc);
    if (*(uint *)(in_ECX + 0x28) < 0x10) {
      iVar8 = in_ECX + 0x14;
    }
    else {
      iVar8 = *(int *)(in_ECX + 0x14);
    }
    FUN_0047aa30(acStack_19,&DAT_009e75ac,iVar8);
    pcVar1 = (char *)(iVar5 + 0x10);
    uVar7 = 0;
    pcVar6 = pcVar1;
    do {
      cVar2 = pcVar6[(int)(acStack_19 + -(int)pcVar1)];
      *pcVar6 = cVar2;
      if (cVar2 == '\0') goto LAB_006ed327;
      uVar7 = uVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (uVar7 < 0x19);
    *pcVar1 = '\0';
LAB_006ed327:
    *(undefined1 *)(iVar5 + 0x30) = 0;
    cVar2 = (**(code **)(*DAT_00b5ad90 + 0x30))();
    if (cVar2 == '\x01') {
      (**(code **)(*DAT_00b5ad90 + 0x1c))();
    }
    FUN_004d8570(iVar5);
    FUN_004de2a0(0,0x4b0);
  }
  return;
}


// ==== FUN_006ed370 @ 0x006ed370 ====

void FUN_006ed370(void)

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
  char acStack_19 [25];
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5220005;
    *(undefined2 *)((int)pvVar4 + 6) = 0x34;
    iVar5 = FUN_004244d0();
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(in_ECX + 0xc);
    if (*(uint *)(in_ECX + 0x28) < 0x10) {
      iVar8 = in_ECX + 0x14;
    }
    else {
      iVar8 = *(int *)(in_ECX + 0x14);
    }
    FUN_0047aa30(acStack_19,&DAT_009e75ac,iVar8);
    pcVar1 = (char *)(iVar5 + 0x10);
    uVar7 = 0;
    pcVar6 = pcVar1;
    do {
      cVar2 = pcVar6[(int)(acStack_19 + -(int)pcVar1)];
      *pcVar6 = cVar2;
      if (cVar2 == '\0') goto LAB_006ed407;
      uVar7 = uVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (uVar7 < 0x19);
    *pcVar1 = '\0';
LAB_006ed407:
    *(undefined1 *)(iVar5 + 0x30) = 1;
    cVar2 = (**(code **)(*DAT_00b5ad90 + 0x30))();
    if (cVar2 == '\x01') {
      (**(code **)(*DAT_00b5ad90 + 0x1c))();
    }
    FUN_004d8570(iVar5);
  }
  return;
}


// ==== FUN_006ed440 @ 0x006ed440 ====

void FUN_006ed440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e75f0;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_009e75d8;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_006ed480 @ 0x006ed480 ====

void FUN_006ed480(void)

{
  char cVar1;
  undefined4 uVar2;
  void *_Memory;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ce58;
  pvStack_c = ExceptionList;
  uStack_2c = 0x6ed4a3;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5ad90 + 0x30))();
  if (cVar1 == '\x01') {
    uStack_2c = 0x6ed4b2;
    (**(code **)(*DAT_00b5ad90 + 0x1c))();
  }
  uStack_2c = 0x3f00004;
  uStack_30 = 0;
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401660(uVar2,0,0xffffffff);
  _Memory = (void *)0x1388;
  pvStack_c = (void *)0x0;
  (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,&uStack_30);
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006ed530 @ 0x006ed530 ====

void FUN_006ed530(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  undefined4 uStack_78;
  uint uStack_74;
  undefined4 auStack_70 [3];
  char cStack_61;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ce6d;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 4) != '\x01') {
    ExceptionList = &local_c;
    cVar1 = (**(code **)(*DAT_00b5ad90 + 0x30))();
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5ad90 + 0x1c))();
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 0xc));
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0xc))(), iVar3 == 0)) {
      *(undefined1 *)(in_ECX + 4) = 1;
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
      iVar3 = *piVar2;
      puVar7 = auStack_70;
      for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      piVar2 = (int *)(**(code **)(iVar3 + 0x14))();
      uVar5 = (**(code **)(*piVar2 + 0x40))(auStack_8c);
      uStack_4 = 0;
      FUN_00401660(uVar5,0,0xffffffff);
      uStack_4 = 0xffffffff;
      if (0xf < uStack_74) {
        _free(pvStack_88);
        return;
      }
      uStack_74 = 0xf;
      uStack_78 = 0;
      pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
      if (cStack_61 == '\0') {
        FUN_006ed370();
      }
      else {
        (**(code **)(*DAT_00b5ad90 + 0xc))
                  (in_ECX + 0x10,*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 8));
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ed650 @ 0x006ed650 ====

void FUN_006ed650(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ce8a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e75f0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = param_2;
  in_ECX[3] = param_1;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  local_4 = 1;
  FUN_006ed530();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ed6c0 @ 0x006ed6c0 ====

undefined1 FUN_006ed6c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_006ed6d0 @ 0x006ed6d0 ====

undefined4 FUN_006ed6d0(void)

{
  return 3;
}


// ==== FUN_006ed6e0 @ 0x006ed6e0 ====

void FUN_006ed6e0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ed440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ed750 @ 0x006ed750 ====

void FUN_006ed750(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ad90 + 0x30))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ad90 + 0x1c))();
  }
  FUN_004de2a0(0,0x4b0);
  return;
}


// ==== FUN_006ed780 @ 0x006ed780 ====

undefined4 FUN_006ed780(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar1 + 0x88) == (int *)0x0) {
    return 0;
  }
  uStack_4 = 1;
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x88) + 0x14))();
  (**(code **)(*piVar2 + 0x10))(&uStack_4);
  return 1;
}


// ==== FUN_006ed7c0 @ 0x006ed7c0 ====

void FUN_006ed7c0(void)

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
  char acStack_19 [25];
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5220002;
    *(undefined2 *)((int)pvVar4 + 6) = 0x30;
    iVar5 = FUN_004244d0();
    if (*(uint *)(in_ECX + 0x24) < 0x10) {
      iVar8 = in_ECX + 0x10;
    }
    else {
      iVar8 = *(int *)(in_ECX + 0x10);
    }
    FUN_0047aa30(acStack_19,&DAT_009e7640,iVar8);
    pcVar1 = (char *)(iVar5 + 0x10);
    uVar7 = 0;
    pcVar6 = pcVar1;
    do {
      cVar2 = pcVar6[(int)(acStack_19 + -(int)pcVar1)];
      *pcVar6 = cVar2;
      if (cVar2 == '\0') goto LAB_006ed84a;
      uVar7 = uVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (uVar7 < 0x19);
    *pcVar1 = '\0';
LAB_006ed84a:
    FUN_004d8570(iVar5);
  }
  return;
}


// ==== FUN_006ed860 @ 0x006ed860 ====

void FUN_006ed860(void)

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
  char acStack_1a [26];
  
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))(7);
  if (cVar2 == '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5220000;
    *(undefined2 *)((int)pvVar4 + 6) = 0x30;
    iVar5 = FUN_004244d0();
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(in_ECX + 8);
    if (*(uint *)(in_ECX + 0x24) < 0x10) {
      iVar8 = in_ECX + 0x10;
    }
    else {
      iVar8 = *(int *)(in_ECX + 0x10);
    }
    FUN_0047aa30(acStack_1a + -3,&DAT_009e7640,iVar8);
    pcVar1 = (char *)(iVar5 + 0x14);
    uVar7 = 0;
    pcVar6 = pcVar1;
    do {
      cVar2 = pcVar6[(int)(acStack_1a + (-3 - (int)pcVar1))];
      *pcVar6 = cVar2;
      if (cVar2 == '\0') goto LAB_006ed8fb;
      uVar7 = uVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (uVar7 < 0x19);
    *pcVar1 = '\0';
LAB_006ed8fb:
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5af2c + 4))(7);
  }
  return;
}


// ==== FUN_006ed920 @ 0x006ed920 ====

void FUN_006ed920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e766c;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009e75d8;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_006ed960 @ 0x006ed960 ====

void FUN_006ed960(void)

{
  char cVar1;
  undefined4 uVar2;
  void *_Memory;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cea8;
  pvStack_c = ExceptionList;
  uStack_2c = 0x3f00007;
  uStack_30 = 0;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401660(uVar2,0,0xffffffff);
  pvStack_c = (void *)0x0;
  cVar1 = (**(code **)(*DAT_00b5ad90 + 0x30))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ad90 + 0x1c))();
  }
  _Memory = (void *)0x1388;
  (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,&uStack_30);
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006eda10 @ 0x006eda10 ====

void FUN_006eda10(void)

{
  char cVar1;
  undefined4 uVar2;
  void *_Memory;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ceba;
  pvStack_c = ExceptionList;
  uStack_2c = 0x3f00004;
  uStack_30 = 0;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401660(uVar2,0,0xffffffff);
  pvStack_c = (void *)0x0;
  cVar1 = (**(code **)(*DAT_00b5ad90 + 0x30))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ad90 + 0x1c))();
  }
  _Memory = (void *)0x1388;
  (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,&uStack_30);
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006edac0 @ 0x006edac0 ====

undefined4 FUN_006edac0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *_Memory;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [16];
  void *pvStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cf0c;
  pvStack_c = ExceptionList;
  switch(param_1) {
  case 0:
    uStack_48 = 0x6edaf7;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5ad90 + 8))();
    ExceptionList = pvStack_c;
    return 1;
  case 1:
    uStack_48 = 0x3f00002;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x1;
    goto LAB_006edca0;
  default:
    uStack_48 = 0x7d50004;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_34 = 0xf;
    uStack_38 = 0;
    uStack_48 = uStack_48 & 0xffffff00;
    FUN_00401660(uVar1,0,0xffffffff);
    _Memory = (void *)0x1388;
    pvStack_c = (void *)0x8;
    (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,&uStack_4c);
    if (uStack_40 < 0x10) {
      ExceptionList = pvStack_20;
      return 0;
    }
    _free(_Memory);
    return extraout_EAX;
  case 3:
    uStack_48 = 0x3f00001;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x0;
    break;
  case 4:
    uStack_48 = 0x3f00004;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x2;
    break;
  case 5:
    uStack_48 = 0x3f00010;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x3;
    (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,auStack_30);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 6:
  case 7:
    uStack_48 = 0x3f00011;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x4;
    break;
  case 8:
    uStack_48 = 0x6e0104;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x5;
    goto LAB_006edca0;
  case 9:
    uStack_48 = 0x320003c;
    uStack_4c = 8;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x6;
    break;
  case 10:
    uStack_48 = 0x7d50012;
    uStack_4c = 0;
    ExceptionList = &pvStack_c;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar1);
    pvStack_c = (void *)0x7;
LAB_006edca0:
    (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,auStack_30);
    goto LAB_006edc14;
  }
  (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,auStack_30);
LAB_006edc14:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_006edd70 @ 0x006edd70 ====

void FUN_006edd70(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_42 [2];
  void *pvStack_40;
  uint uStack_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cf26;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 4) != '\x01') {
    ExceptionList = &local_c;
    piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    if (*(char *)(iVar2 + 0x962) == '\0') {
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
      FUN_00401660(uVar3,0,0xffffffff);
      local_c = (void *)0x0;
      (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,auStack_42 + -10);
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
    }
    else {
      piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 0)) {
        piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
        uVar3 = (**(code **)(*piVar1 + 0x40))(auStack_28);
        puStack_8 = (undefined1 *)0x1;
        FUN_00401660(uVar3,0,0xffffffff);
        puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006edeb0 @ 0x006edeb0 ====

void FUN_006edeb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cf43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e766c;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = param_1;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  local_4 = 1;
  FUN_006edd70();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006edf10 @ 0x006edf10 ====

void FUN_006edf10(byte param_1)

{
  void *in_ECX;
  
  FUN_006ed920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006edfa0 @ 0x006edfa0 ====

undefined4 FUN_006edfa0(void)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  int in_ECX;
  float fVar4;
  
  if ((DAT_00b5a97c != (int *)0x0) &&
     (piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))(), piVar2 != (int *)0x0)) {
    fVar4 = *(float *)(in_ECX + 0x1c);
    fVar1 = *(float *)(in_ECX + 0x20);
    pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
    fVar4 = fVar4 - *pfVar3;
    fVar1 = fVar1 - pfVar3[1];
    fVar4 = SQRT(fVar4 * fVar4 + fVar1 * fVar1);
    if (fVar4 <= DAT_0099cdc8) {
      fVar4 = 0.0 - fVar4;
    }
    if (fVar4 <= *(float *)(in_ECX + 0x18)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006ee040 @ 0x006ee040 ====

undefined4 FUN_006ee040(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00826ee0(uVar1);
  return 1;
}


// ==== FUN_006ee0a0 @ 0x006ee0a0 ====

void FUN_006ee0a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cf58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e76e4;
  local_4 = 0;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
    (**(code **)(*DAT_00b5a804 + 0x18))(0);
  }
  *in_ECX = &PTR_FUN_009e75d8;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ee100 @ 0x006ee100 ====

void FUN_006ee100(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    *(undefined1 *)(in_ECX + 4) = 1;
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar1 = DAT_009b30d4;
    *(undefined4 *)(in_ECX + 8) = uVar2;
    *(undefined4 *)(in_ECX + 0x14) = 10000;
    *(undefined4 *)(in_ECX + 0x18) = uVar1;
    (**(code **)(*DAT_00b5ad90 + 0x34))(0x7d4,1,0x5dc);
    FUN_004de2a0(0,0x4b1);
    (**(code **)(*DAT_00b5a804 + 0x18))(1);
  }
  return;
}


// ==== FUN_006ee170 @ 0x006ee170 ====

void FUN_006ee170(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(7);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x522000a;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(7);
  }
  return;
}


// ==== FUN_006ee1e0 @ 0x006ee1e0 ====

void FUN_006ee1e0(void)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))(7);
  if ((cVar2 != '\0') || (uVar1 = *(uint *)(in_ECX + 0x24), (uVar1 & 1) != 0)) {
    return;
  }
  if (((uVar1 & 2) != 0) && (*(uint *)(in_ECX + 0x24) = uVar1 & 0xfffffffd, (uVar1 & 4) != 0)) {
    *(uint *)(in_ECX + 0x24) = uVar1 & 0xfffffff9;
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if ((*(uint *)(in_ECX + 0x24) & 1) == 0) {
    *(uint *)(in_ECX + 0x24) = *(uint *)(in_ECX + 0x24) | 1;
  }
                    /* WARNING: Could not recover jumptable at 0x006ee229. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad90 + 0x20))();
  return;
}


// ==== FUN_006ee240 @ 0x006ee240 ====

void FUN_006ee240(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  if ((*(byte *)(in_ECX + 0x24) & 4) == 0) {
    iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar2 = iVar1 - *(int *)(in_ECX + 0xc);
    if (uVar2 < *(uint *)(in_ECX + 0x14)) {
      *(uint *)(in_ECX + 0x10) = (*(uint *)(in_ECX + 0x14) - uVar2) + iVar1;
    }
    else {
      *(int *)(in_ECX + 0x10) = iVar1;
    }
    if ((*(uint *)(in_ECX + 0x24) & 4) == 0) {
      *(uint *)(in_ECX + 0x24) = *(uint *)(in_ECX + 0x24) | 4;
    }
  }
  return;
}


// ==== FUN_006ee280 @ 0x006ee280 ====

uint FUN_006ee280(void)

{
  uint in_EAX;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x24) & 4) != 0) {
    in_EAX = (**(code **)(*DAT_00b5a6ac + 0x20))();
    if (*(uint *)(in_ECX + 0x10) <= in_EAX) {
      *(uint *)(in_ECX + 0x10) = in_EAX + 0x5dc;
      return CONCAT31((int3)(in_EAX + 0x5dc >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006ee2b0 @ 0x006ee2b0 ====

void FUN_006ee2b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cf6a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = param_1;
  local_4 = 0;
  *in_ECX = &PTR_FUN_009e76e4;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[8] = param_2;
  in_ECX[9] = 0;
  FUN_006ee100();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ee320 @ 0x006ee320 ====

undefined4 FUN_006ee320(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  
  cVar2 = FUN_006edfa0();
  if (cVar2 == '\x01') {
    bVar1 = *(byte *)(in_ECX + 0x24) & 1;
  }
  else {
    bVar1 = *(byte *)(in_ECX + 0x24) & 2;
  }
  if (bVar1 == 0) {
    FUN_006ee170();
  }
  if ((*(byte *)(in_ECX + 0x24) & 4) != 0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    if (*(uint *)(in_ECX + 0x10) <= uVar3) {
      *(uint *)(in_ECX + 0x10) = uVar3 + 0x5dc;
      FUN_006ee170();
    }
  }
  return 1;
}


// ==== FUN_006ee370 @ 0x006ee370 ====

void FUN_006ee370(void)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_2e [2];
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cf7c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if ((cVar2 == '\0') && (uVar1 = *(uint *)(in_ECX + 0x24), (uVar1 & 2) == 0)) {
    if ((uVar1 & 1) != 0) {
      *(uint *)(in_ECX + 0x24) = uVar1 & 0xfffffffe;
    }
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 0xc) = uVar3;
    if ((*(uint *)(in_ECX + 0x24) & 2) == 0) {
      *(uint *)(in_ECX + 0x24) = *(uint *)(in_ECX + 0x24) | 2;
    }
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    FUN_00401660(uVar3,0,0xffffffff);
    pvStack_10 = (void *)0x0;
    (**(code **)(*DAT_00b5ad90 + 0x10))(1,*(undefined4 *)(in_ECX + 0x14),auStack_2e + -6);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_006ee450 @ 0x006ee450 ====

void FUN_006ee450(byte param_1)

{
  void *in_ECX;
  
  FUN_006ee0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ee480 @ 0x006ee480 ====

void FUN_006ee480(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(char *)(in_ECX + 5) != '\x01') {
    iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar2 = iVar1 - *(int *)(in_ECX + 0xc);
    if (uVar2 < *(uint *)(in_ECX + 0x14)) {
      *(uint *)(in_ECX + 8) = (*(uint *)(in_ECX + 0x14) - uVar2) + iVar1;
      *(undefined1 *)(in_ECX + 5) = 1;
      return;
    }
    *(int *)(in_ECX + 8) = iVar1;
    *(undefined1 *)(in_ECX + 5) = 1;
  }
  return;
}


// ==== FUN_006ee4c0 @ 0x006ee4c0 ====

uint FUN_006ee4c0(void)

{
  uint in_EAX;
  int in_ECX;
  
  if (*(char *)(in_ECX + 5) != '\0') {
    in_EAX = (**(code **)(*DAT_00b5a6ac + 0x20))();
    if (*(uint *)(in_ECX + 8) <= in_EAX) {
      *(uint *)(in_ECX + 8) = in_EAX + 0x5dc;
      return CONCAT31((int3)(in_EAX + 0x5dc >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006ee4f0 @ 0x006ee4f0 ====

void FUN_006ee4f0(void)

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
  char acStack_19 [25];
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x5220008;
  *(undefined2 *)((int)pvVar4 + 6) = 0x30;
  iVar5 = FUN_004244d0();
  *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  if (*(uint *)(in_ECX + 0x34) < 0x10) {
    iVar8 = in_ECX + 0x20;
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x20);
  }
  FUN_0047aa30(acStack_19,&DAT_009e7744,iVar8);
  pcVar1 = (char *)(iVar5 + 0x14);
  uVar7 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_19 + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_006ee577;
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 < 0x19);
  *pcVar1 = '\0';
LAB_006ee577:
  FUN_004d8570(iVar5);
  return;
}


// ==== FUN_006ee590 @ 0x006ee590 ====

undefined4 FUN_006ee590(void)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  short sStack_24;
  undefined4 uStack_20;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  uVar1 = FUN_00802534();
  uStack_34 = CONCAT22(uStack_34._2_2_,uVar1);
  uVar1 = FUN_00802534();
  uStack_34 = CONCAT22(uVar1,(undefined2)uStack_34);
  uStack_20 = *(undefined4 *)(in_ECX + 0xc);
  uStack_28 = uStack_34;
  uStack_2c = *(undefined4 *)(in_ECX + 0x18);
  uStack_30 = (ushort)uStack_30._1_1_ << 8;
  sStack_24 = uStack_30;
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x88) + 0x14))();
  (**(code **)(*piVar3 + 0x18))(*(undefined4 *)(in_ECX + 0x10));
  if (*(uint *)(in_ECX + 0x34) < 0x10) {
    iVar4 = in_ECX + 0x20;
  }
  else {
    iVar4 = *(int *)(in_ECX + 0x20);
  }
  FUN_0047aa30((int)&uStack_20 + 3,&DAT_009e7744,iVar4);
  (**(code **)(*piVar3 + 0x20))((int)&uStack_20 + 3);
  FUN_00826f20(iVar2,&uStack_34);
  return 1;
}


// ==== FUN_006ee640 @ 0x006ee640 ====

void FUN_006ee640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e7750;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
    *(undefined1 *)((int)in_ECX + 5) = 0;
  }
  if ((uint)in_ECX[0xd] < 0x10) {
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0xf;
    *(undefined1 *)(in_ECX + 8) = 0;
    *in_ECX = &PTR_FUN_009e75d8;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_006ee680 @ 0x006ee680 ====

undefined4 FUN_006ee680(void)

{
  uint uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 5) != '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    if (*(uint *)(in_ECX + 8) <= uVar1) {
      *(uint *)(in_ECX + 8) = uVar1 + 0x5dc;
      FUN_006ee4f0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006ee6b0 @ 0x006ee6b0 ====

void FUN_006ee6b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_26 [2];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cf98;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 4) != '\x01') {
    ExceptionList = &local_c;
    *(undefined1 *)(in_ECX + 4) = 1;
    iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(int *)(in_ECX + 0xc) = iVar1;
    *(undefined4 *)(in_ECX + 0x14) = 5000;
    *(int *)(in_ECX + 8) = iVar1 + 5000;
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    FUN_00401660(uVar2,0,0xffffffff);
    local_c = (void *)0x0;
    (**(code **)(*DAT_00b5ad90 + 0x10))(1,*(undefined4 *)(in_ECX + 0x14),auStack_26 + -10);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ee770 @ 0x006ee770 ====

void FUN_006ee770(void)

{
  undefined4 uVar1;
  void *_Memory;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098cfaa;
  pvStack_c = ExceptionList;
  uStack_2c = 0x6ee793;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ad90 + 0x20))();
  uStack_2c = 0x3f00004;
  uStack_30 = 0;
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401660(uVar1,0,0xffffffff);
  _Memory = (void *)0x1388;
  pvStack_c = (void *)0x0;
  (**(code **)(*DAT_00b5ad90 + 0x10))(0,5000,&uStack_30);
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006ee810 @ 0x006ee810 ====

void FUN_006ee810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cfc7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[4] = param_1;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009e7750;
  in_ECX[6] = param_3;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  in_ECX[0xe] = param_4;
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0xf] = param_5;
  FUN_006ee6b0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ee8a0 @ 0x006ee8a0 ====

undefined4 FUN_006ee8a0(void)

{
  return 4;
}


// ==== FUN_006ee8b0 @ 0x006ee8b0 ====

void FUN_006ee8b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ee640();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ee8d0 @ 0x006ee8d0 ====

void FUN_006ee8d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e782c;
  return;
}


// ==== FUN_006ee8e0 @ 0x006ee8e0 ====

void FUN_006ee8e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e782c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ee930 @ 0x006ee930 ====

void FUN_006ee930(void)

{
  return;
}


// ==== FUN_006ee940 @ 0x006ee940 ====

void FUN_006ee940(void)

{
  return;
}


// ==== FUN_006ee950 @ 0x006ee950 ====

void FUN_006ee950(void)

{
  return;
}


// ==== FUN_006ee9a0 @ 0x006ee9a0 ====

undefined4 FUN_006ee9a0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 4) != 0x20) {
    return 0;
  }
  if ((*(int *)(in_ECX + 0x20) != 0) && (*(char *)(in_ECX + 10) != '\x01')) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_006f8850(0);
  }
  return 1;
}


// ==== FUN_006ee9e0 @ 0x006ee9e0 ====

undefined4 FUN_006ee9e0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 4) != 0x20) {
    return 0;
  }
  if ((*(int *)(in_ECX + 0x20) != 1) && (*(char *)(in_ECX + 10) != '\x01')) {
    *(undefined4 *)(in_ECX + 0x20) = 1;
    FUN_006f8850(1);
  }
  return 1;
}


// ==== FUN_006eea40 @ 0x006eea40 ====

void FUN_006eea40(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (((iVar1 != 0) && (piVar3 = *(int **)(iVar1 + 0x84), piVar3 != (int *)0x0)) &&
     (piVar2 = (int *)(**(code **)(*piVar3 + 0x3c))(), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 4))();
    iVar1 = FUN_006ef620(param_1);
    if (iVar1 != 0) {
      piVar3 = (int *)(**(code **)(*piVar3 + 0x38))();
      (**(code **)(*piVar3 + 0xc))(param_1,*(undefined4 *)(in_ECX + 0x20));
    }
  }
  return;
}


// ==== FUN_006eeaa0 @ 0x006eeaa0 ====

void FUN_006eeaa0(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((((iVar3 != 0) && (piVar1 = *(int **)(iVar3 + 0x84), piVar1 != (int *)0x0)) &&
      (piVar4 = (int *)(**(code **)(*piVar1 + 0x3c))(), piVar4 != (int *)0x0)) &&
     (iVar5 = (**(code **)(*piVar1 + 0x18))(), iVar5 != 0)) {
    (**(code **)(*piVar4 + 4))();
    iVar5 = FUN_006ef620(param_1);
    if (iVar5 != 0) {
      iVar3 = FUN_00826fc0(iVar3,*(undefined4 *)(iVar5 + 8),*(undefined4 *)(in_ECX + 0x20));
      if (iVar3 != 0) {
        *(undefined1 *)(in_ECX + 10) = 1;
      }
      if (*(int *)(iVar5 + 8) == 1) {
        *(undefined1 *)(in_ECX + 0xb) = 0;
        if (*(char *)(in_ECX + 9) == '\0') {
          *(undefined1 *)(in_ECX + 9) = 1;
          return;
        }
      }
      else {
        uVar2 = FUN_006ef660(param_1,param_1 + 400);
        *(undefined1 *)(in_ECX + 0xb) = uVar2;
        if (*(char *)(in_ECX + 9) == '\x01') {
          *(undefined1 *)(in_ECX + 9) = 0;
        }
      }
    }
  }
  return;
}


// ==== FUN_006eeb60 @ 0x006eeb60 ====

undefined4 FUN_006eeb60(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab78 + 8))(*(undefined2 *)(in_ECX + 0xc));
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  return *(undefined4 *)(iVar2 + 4);
}


// ==== FUN_006eeb90 @ 0x006eeb90 ====

undefined4 FUN_006eeb90(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) == 1) {
    if ((*(int *)(in_ECX + 0x20) != 0) && (*(char *)(in_ECX + 10) != '\x01')) {
      *(undefined4 *)(in_ECX + 0x20) = 0;
      FUN_006f8850(0);
    }
  }
  else {
    if (*(int *)(param_1 + 8) != 2) {
      return 0;
    }
    if ((*(int *)(in_ECX + 0x20) != 1) && (*(char *)(in_ECX + 10) != '\x01')) {
      *(undefined4 *)(in_ECX + 0x20) = 1;
      FUN_006f8850(1);
      return 1;
    }
  }
  return 1;
}


// ==== FUN_006eebf0 @ 0x006eebf0 ====

undefined4 FUN_006eebf0(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0x18) == 1)) {
    if ((*(int *)(in_ECX + 0x20) != 1) && (*(char *)(in_ECX + 10) != '\x01')) {
      *(undefined4 *)(in_ECX + 0x20) = 1;
      FUN_006f8850(1);
    }
    return 1;
  }
  if ((*(int *)(param_1 + 8) != 0) || (*(int *)(param_1 + 0x18) != 1)) {
    return 0;
  }
  if ((*(int *)(in_ECX + 0x20) != 0) && (*(char *)(in_ECX + 10) != '\x01')) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_006f8850(0);
  }
  return 1;
}


// ==== FUN_006eec50 @ 0x006eec50 ====

void FUN_006eec50(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((((iVar2 != 0) && (piVar3 = *(int **)(iVar2 + 0x84), piVar3 != (int *)0x0)) &&
      (cVar1 = (**(code **)(*piVar3 + 0x34))(), cVar1 != '\0')) &&
     (piVar3 = (int *)(**(code **)(*piVar3 + 0x3c))(), piVar3 != (int *)0x0)) {
    (**(code **)(*piVar3 + 8))(param_1 + 0x10);
    (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  }
  return;
}


// ==== FUN_006eece0 @ 0x006eece0 ====

void FUN_006eece0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009e7850;
    *(undefined1 *)(puVar1 + 1) = 0;
  }
  FUN_00797a20(puVar1);
  *(undefined4 *)(DAT_00b5b19c + 8) = param_1;
  FUN_006f86c0(DAT_00b5b19c);
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_006eed30 @ 0x006eed30 ====

void FUN_006eed30(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098cfe8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009e7878;
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  in_ECX[6] = 0x2ee;
  in_ECX[8] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b140 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b140 = in_ECX;
  }
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  in_ECX[4] = uVar1;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  in_ECX[5] = uVar1;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  in_ECX[7] = uVar1;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006eede0 @ 0x006eede0 ====

void FUN_006eede0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b140 = 0;
  *in_ECX = &PTR_FUN_009e782c;
  return;
}


// ==== FUN_006eee00 @ 0x006eee00 ====

void FUN_006eee00(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x84) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x84) + 0x38))();
    (**(code **)(*piVar2 + 4))();
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (4 < *(uint *)(iVar1 + 0x28)) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iVar1 = FUN_006ef5f0(uVar3);
      puVar4 = (undefined4 *)(**(code **)(*piVar2 + 4))();
      puVar6 = (undefined4 *)(iVar1 + 0x10);
      for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      FUN_004d8570(iVar1);
                    /* WARNING: Could not recover jumptable at 0x006eee75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar2 + 8))();
      return;
    }
  }
  return;
}


// ==== FUN_006eee80 @ 0x006eee80 ====

void FUN_006eee80(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((((iVar3 != 0) && (piVar1 = *(int **)(iVar3 + 0x84), piVar1 != (int *)0x0)) &&
      (piVar4 = (int *)(**(code **)(*piVar1 + 0x3c))(), piVar4 != (int *)0x0)) &&
     (iVar5 = (**(code **)(*piVar1 + 0x18))(), iVar5 != 0)) {
    (**(code **)(*piVar4 + 4))();
    iVar5 = FUN_006ef620(param_1);
    if ((iVar5 != 0) && (*(char *)(in_ECX + 10) != '\x01')) {
      iVar3 = FUN_00826fc0(iVar3,*(undefined4 *)(iVar5 + 8),*(undefined4 *)(in_ECX + 0x20));
      if (iVar3 != 0) {
        *(undefined1 *)(in_ECX + 10) = 1;
      }
      if (*(int *)(iVar5 + 8) == 1) {
        *(undefined1 *)(in_ECX + 0xb) = 0;
        *(undefined1 *)(in_ECX + 9) = 1;
      }
      else {
        uVar2 = FUN_006ef660(param_1,param_1 + 400);
        *(undefined1 *)(in_ECX + 0xb) = uVar2;
        *(undefined1 *)(in_ECX + 9) = 0;
      }
      iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      if (*(uint *)(in_ECX + 0x18) < (uint)(iVar3 - *(int *)(in_ECX + 0x1c))) {
        uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        *(undefined4 *)(in_ECX + 0x1c) = uVar6;
        if (*(int *)(iVar5 + 8) == 1) {
          *(undefined4 *)(in_ECX + 0x20) = 1;
          FUN_006f8850(1);
          return;
        }
        *(undefined4 *)(in_ECX + 0x20) = 0;
        FUN_006f8850(0);
      }
    }
  }
  return;
}


// ==== FUN_006eef90 @ 0x006eef90 ====

void FUN_006eef90(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar3 = (**(code **)(*piVar2 + 0x40))();
  if (iVar3 == 8) {
    FUN_006f86c0(DAT_00b5b1a0);
    FUN_006f8c40();
    (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
    return;
  }
  if (200 < (uint)(*(int *)(param_1 + 0xc) - *(int *)(in_ECX + 0x10))) {
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 0x10) = uVar4;
    FUN_006eea40(uVar4);
    FUN_006eee00();
    cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x44))();
    if (cVar1 == '\0') {
      FUN_006eeaa0(*(undefined4 *)(in_ECX + 0x10));
    }
    cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x44))();
    if (cVar1 == '\x01') {
      FUN_006eee80(*(undefined4 *)(in_ECX + 0x10));
    }
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  return;
}


// ==== FUN_006ef040 @ 0x006ef040 ====

void FUN_006ef040(int param_1)

{
  void **ppvVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_26 [2];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098cffa;
  local_c = ExceptionList;
  cVar2 = *(char *)(param_1 + 0x10);
  if (cVar2 == '\x01') {
    uStack_3c = 0x6ef06f;
    ExceptionList = &local_c;
    puVar3 = operator_new(8);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009e7850;
      *(undefined1 *)(puVar3 + 1) = 1;
    }
    uStack_3c = 0x6ef08c;
    FUN_00797a20();
    uStack_3c = 0x6ef09e;
    FUN_006f86c0();
    *(undefined1 *)(in_ECX + 8) = 0;
    ppvVar1 = ExceptionList;
  }
  else {
    if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
      uStack_3c = 0x6ef0b8;
      ExceptionList = &local_c;
      FUN_006eece0();
    }
    else {
      if (cVar2 != '\x05') {
        ppvVar1 = &local_c;
        if (cVar2 == '\0') {
          return;
        }
        goto LAB_006ef1ae;
      }
      uStack_3c = 0x6ef139;
      ExceptionList = &local_c;
      FUN_006f86c0();
      FUN_006f8c40();
      (**(code **)(**(int **)(in_ECX + 4) + 0x3c))();
    }
    uStack_3c = 5;
    puStack_40 = (undefined1 *)0x6ef0c6;
    uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_40 = (undefined1 *)0xffffffff;
    puStack_44 = (undefined1 *)0x0;
    uStack_4c = 0x6ef0e6;
    FUN_00401660();
    puStack_44 = auStack_26 + -10;
    puStack_40 = &DAT_00b34194;
    local_c = (void *)0x0;
    uStack_48 = 0x6ef0f9;
    cVar2 = FUN_00404900();
    if (cVar2 == '\x01') {
      puStack_40 = auStack_26 + -10;
      puStack_44 = (undefined1 *)0x2710;
      uStack_48 = 0x6ef112;
      (**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
    }
    else {
      puStack_4 = auStack_58;
      puStack_40 = (undefined1 *)0xf;
      puStack_44 = (undefined1 *)0x0;
      uStack_54 = 0;
      FUN_00401660(auStack_26 + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    }
    puStack_4 = (undefined1 *)0xffffffff;
    ppvVar1 = ExceptionList;
    if (0xf < uStack_10) {
      uStack_3c = 0x6ef19f;
      _free(pvStack_24);
      return;
    }
  }
LAB_006ef1ae:
  ExceptionList = ppvVar1;
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 0x10) = uVar4;
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 0x14) = uVar4;
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar5 != 0) {
    (**(code **)(**(int **)(iVar5 + 0x84) + 0x28))();
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined1 *)(in_ECX + 10) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006ef200 @ 0x006ef200 ====

void FUN_006ef200(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_1c;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098d014;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004de2a0(1,1000);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  uVar5 = param_1;
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009e77ac,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar4 = *(int **)(iVar3 + 0x84);
  if (piVar4 == (int *)0x0) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_pIFishManager____NULL_009e77b8,0x15);
    uStack_4 = 1;
    FUN_00406880(auStack_44);
    uStack_4 = 0xffffffff;
    if (uStack_2c < 0x10) {
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_40);
    return;
  }
  (**(code **)(*piVar4 + 0x24))(param_1,param_2);
  *(short *)(in_ECX + 0xc) = (short)uVar5;
  piVar4 = (int *)(**(code **)(*piVar4 + 0x3c))();
  (**(code **)(*piVar4 + 8))(&param_1);
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 0x10) = uVar5;
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 0x1c) = uVar5;
  *(undefined1 *)(in_ECX + 8) = 1;
  FUN_004de2a0(0,0x3e9);
  cVar2 = (**(code **)(*DAT_00b5a994 + 0x10))(0x20);
  if (cVar2 == '\x01') {
    if ((*(int *)(in_ECX + 0x20) == 0) || (*(char *)(in_ECX + 10) == '\x01')) goto LAB_006ef38b;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    uVar5 = 0;
  }
  else {
    if ((*(int *)(in_ECX + 0x20) == 1) || (*(char *)(in_ECX + 10) == '\x01')) goto LAB_006ef38b;
    *(undefined4 *)(in_ECX + 0x20) = 1;
    uVar5 = 1;
  }
  FUN_006f8850(uVar5);
LAB_006ef38b:
  puVar6 = operator_new(4);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = &PTR_FUN_009e7864;
  }
  FUN_00797a20(puVar6);
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_006ef4e0 @ 0x006ef4e0 ====

undefined4 FUN_006ef4e0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5210006) {
    FUN_006eec50(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5210008) {
    FUN_006ef040(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_006ef530 @ 0x006ef530 ====

undefined4 FUN_006ef530(int *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x20003) {
    if (uVar2 == 0x20002) {
      cVar1 = FUN_006ee9e0(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x10001) {
      cVar1 = FUN_006eeb90(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x10003) {
      cVar1 = FUN_006eebf0(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x20001) {
      cVar1 = FUN_006ee9a0(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  else if (uVar2 == 0x40001) {
    FUN_006eef90(param_1);
  }
  else if (uVar2 == 0x50011) {
    cVar1 = FUN_006ef4e0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006ef5f0 @ 0x006ef5f0 ====

void FUN_006ef5f0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5210007;
  *(undefined2 *)((int)pvVar1 + 6) = 0x3c;
  FUN_004244d0();
  return;
}


// ==== FUN_006ef620 @ 0x006ef620 ====

int FUN_006ef620(uint param_1)

{
  uint uVar1;
  int in_ECX;
  uint *puVar2;
  
  uVar1 = 0;
  puVar2 = (uint *)(in_ECX + 8);
  while ((param_1 < puVar2[-1] || (*puVar2 <= param_1))) {
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 3;
    if (6 < uVar1) {
      return 0;
    }
  }
  return in_ECX + 4 + uVar1 * 0xc;
}


// ==== FUN_006ef660 @ 0x006ef660 ====

undefined4 FUN_006ef660(uint param_1,uint param_2)

{
  int in_ECX;
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  puVar1 = (uint *)(in_ECX + 4);
  while( true ) {
    uVar3 = param_2;
    if (puVar1[1] <= param_2) {
      uVar3 = puVar1[1];
    }
    uVar2 = *puVar1;
    if (*puVar1 <= param_1) {
      uVar2 = param_1;
    }
    if ((uVar2 <= uVar3) && (puVar1[2] == 1)) break;
    uVar4 = uVar4 + 1;
    puVar1 = puVar1 + 3;
    if (6 < uVar4) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_006ef6b0 @ 0x006ef6b0 ====

undefined4 FUN_006ef6b0(void)

{
  return 0x70390004;
}


// ==== FUN_006ef6c0 @ 0x006ef6c0 ====

undefined4 FUN_006ef6c0(void)

{
  return 0x70390005;
}


// ==== FUN_006ef6d0 @ 0x006ef6d0 ====

void FUN_006ef6d0(void)

{
  return;
}


// ==== FUN_006ef6e0 @ 0x006ef6e0 ====

void FUN_006ef6e0(byte param_1)

{
  void *in_ECX;
  
  FUN_006eede0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ef700 @ 0x006ef700 ====

void FUN_006ef700(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e78c4;
  return;
}


// ==== FUN_006ef710 @ 0x006ef710 ====

void FUN_006ef710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e78c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ef730 @ 0x006ef730 ====

undefined2 FUN_006ef730(ushort param_1)

{
  if ((param_1 < 5000) || (0x2aee < param_1)) {
    return 0;
  }
  return 1;
}


// ==== FUN_006ef750 @ 0x006ef750 ====

short FUN_006ef750(void)

{
  ushort uVar1;
  byte bVar2;
  int in_ECX;
  
  uVar1 = *(ushort *)(in_ECX + 4);
  bVar2 = (byte)(uVar1 >> 8);
  if ((uVar1 < 5000) || (0x2aee < uVar1)) {
    return (ushort)bVar2 << 8;
  }
  return CONCAT11(bVar2,1);
}


// ==== FUN_006ef770 @ 0x006ef770 ====

undefined2 FUN_006ef770(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 4);
}


// ==== FUN_006ef780 @ 0x006ef780 ====

undefined1 FUN_006ef780(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_006ef790 @ 0x006ef790 ====

void FUN_006ef790(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 6) = param_1;
  return;
}


// ==== FUN_006ef7a0 @ 0x006ef7a0 ====

int FUN_006ef7a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0xc;
}


// ==== FUN_006ef7c0 @ 0x006ef7c0 ====

uint FUN_006ef7c0(short param_1)

{
  short *psVar1;
  int in_ECX;
  
  psVar1 = *(short **)(in_ECX + 0xc);
  while( true ) {
    if (psVar1 == *(short **)(in_ECX + 0x10)) {
      return (uint)psVar1 & 0xffffff00;
    }
    if (*psVar1 == param_1) break;
    psVar1 = psVar1 + 6;
  }
  return CONCAT31((int3)((uint)psVar1 >> 8),1);
}


// ==== FUN_006ef7f0 @ 0x006ef7f0 ====

/* WARNING: Removing unreachable block (ram,0x006ef81b) */

void FUN_006ef7f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e78ec;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009e78c4;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006ef840 @ 0x006ef840 ====

int FUN_006ef840(uint param_1)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098d078;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 0xc) == 0) ||
     ((uint)((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0xc) <= param_1)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_i_index_<_m_vecSubQuestList_size_009e789c,0x22);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
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
  iVar2 = *(int *)(in_ECX + 0xc);
  if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x10) - iVar2) / 0xc) <= param_1)) {
    ExceptionList = &local_c;
    FUN_006ef990();
  }
  ExceptionList = local_c;
  return iVar2 + param_1 * 0xc;
}


// ==== FUN_006ef930 @ 0x006ef930 ====

void FUN_006ef930(undefined2 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e78ec;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *(undefined2 *)(in_ECX + 1) = param_1;
  *(undefined1 *)((int)in_ECX + 6) = 1;
  return;
}


// ==== FUN_006ef980 @ 0x006ef980 ====

void FUN_006ef980(undefined1 param_1)

{
  FUN_006efdb0(&param_1);
  return;
}


// ==== FUN_006ef990 @ 0x006ef990 ====

void FUN_006ef990(void)

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
  puStack_8 = &LAB_0098d048;
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


// ==== FUN_006efa00 @ 0x006efa00 ====

void FUN_006efa00(void)

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
  puStack_8 = &LAB_0098d048;
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


// ==== FUN_006efa70 @ 0x006efa70 ====

void FUN_006efa70(int param_1,uint param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098d060;
  local_10 = ExceptionList;
  local_20 = *param_3;
  local_1c = param_3[1];
  iVar3 = *(int *)(in_ECX + 4);
  local_18 = param_3[2];
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x15555555U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_006efa00();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (uVar6 < iVar2 + param_2) {
      if (0x15555555 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
      }
      if (uVar6 < iVar3 + param_2) {
        iVar3 = FUN_004a3750();
        uVar6 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar6 * 0xc);
      local_8 = 0;
      iVar3 = FUN_0042eab0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_0042ea70(iVar3,param_2,&local_20);
      FUN_0042eab0(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 0xc);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xc;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0xc + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0xc) < param_2) {
      FUN_0042eab0(param_1,iVar3,param_2 * 0xc + param_1);
      local_8 = 2;
      FUN_0042edf0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0xc;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) + param_2 * -0xc,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + param_2 * -0xc;
    uVar5 = FUN_0042eab0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_004ab780(param_1,iVar2,iVar3,iVar2);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006efc22 @ 0x006efc22 ====

void Catch_006efc22(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_006efd20 @ 0x006efd20 ====

void FUN_006efd20(byte param_1)

{
  void *in_ECX;
  
  FUN_006ef7f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006efd40 @ 0x006efd40 ====

void FUN_006efd40(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_006efd83;
    }
  }
  iVar1 = 0;
LAB_006efd83:
  FUN_006efa70(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_006efdb0 @ 0x006efdb0 ====

void FUN_006efdb0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_006efd40(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_006efe30 @ 0x006efe30 ====

void FUN_006efe30(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098d0b6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5ae20 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006f9b60(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5ae1c == 0) {
    pvVar1 = operator_new(4);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_006f96c0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006efeb0 @ 0x006efeb0 ====

void FUN_006efeb0(void)

{
  if (DAT_00b5ae1c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae1c)(1);
  }
  if (DAT_00b5ae20 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae20)(1);
  }
  return;
}


// ==== FUN_006efee0 @ 0x006efee0 ====

void FUN_006efee0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098d0e1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5ae78 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006fdca0(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5ae74 == 0) {
    pvVar1 = operator_new(0x14);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_006fca90(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5ae7c == 0) {
    pvVar1 = operator_new(4);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      FUN_006fa7f0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_006eff90 @ 0x006eff90 ====

void FUN_006eff90(void)

{
  if (DAT_00b5ae78 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae78)(1);
  }
  if (DAT_00b5ae74 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae74)(1);
  }
  if (DAT_00b5ae7c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae7c)(1);
  }
  return;
}


// ==== FUN_006effd0 @ 0x006effd0 ====

void FUN_006effd0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098d111;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5b0d0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x44);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006ffeb0(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b0cc == 0) {
    pvVar1 = operator_new(0xc);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_006ff260(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b0c8 == 0) {
    pvVar1 = operator_new(4);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      FUN_006fe5b0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


