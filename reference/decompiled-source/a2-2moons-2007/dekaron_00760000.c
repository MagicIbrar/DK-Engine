// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x760000-0x76ffff

// ==== FUN_00760020 @ 0x00760020 ====

undefined4 FUN_00760020(int param_1)

{
  undefined4 extraout_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994cd4;
  local_c = ExceptionList;
  if (((param_1 == 0xf) || (param_1 == 0x10)) || (param_1 == 0x11)) {
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    uVar2 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x2c))(param_1);
    ExceptionList = local_10;
    return uVar2;
  }
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009f3538,0x20);
  local_4 = 0;
  FUN_00796d50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_007600e0 @ 0x007600e0 ====

/* WARNING: Removing unreachable block (ram,0x00760168) */

void FUN_007600e0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  int unaff_retaddr;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994ce6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    if (((unaff_retaddr == 0xf) || (unaff_retaddr == 0x10)) || (unaff_retaddr == 0x11)) {
      piVar2 = (int *)(**(code **)(*in_ECX + 4))(unaff_retaddr);
      if ((piVar2 != (int *)0x0) && (cVar1 = FUN_0075f870(piVar2,unaff_retaddr), cVar1 != '\x01')) {
        iVar3 = (**(code **)(*piVar2 + 0x2c))();
        if (*(int *)(iVar3 + 8) == 0x800) {
          uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          iVar3 = FUN_00760710(uVar4);
          uVar4 = (**(code **)(*DAT_00b5adc0 + 0x24))();
          *(undefined4 *)(iVar3 + 0x10) = uVar4;
          uVar4 = (**(code **)(*DAT_00b5adc0 + 0x18))();
          *(undefined4 *)(iVar3 + 0x14) = uVar4;
          *(int *)(iVar3 + 0x18) = unaff_retaddr;
          FUN_004ef210(iVar3);
          ExceptionList = pvStack_10;
          return;
        }
        uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar3 = FUN_00705730(uVar4);
        *(int *)(iVar3 + 0x10) = unaff_retaddr;
        FUN_004ef210(iVar3);
        (**(code **)(*DAT_00b5af2c + 4))(0);
      }
    }
    else {
      FUN_00401740(&DAT_009f355c,0x20);
      puStack_8 = (undefined1 *)0x0;
      FUN_00796d50(auStack_26 + -6);
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00760250 @ 0x00760250 ====

void FUN_00760250(int param_1)

{
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994cf8;
  local_c = ExceptionList;
  if (((param_1 == 0xf) || (param_1 == 0x10)) || (param_1 == 0x11)) {
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5a78c + 0xc))(param_1);
  }
  else {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(&DAT_009f3580,0x20);
    local_4 = 0;
    FUN_00796d50(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00760300 @ 0x00760300 ====

void FUN_00760300(uint param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994d0a;
  local_c = ExceptionList;
  if (param_1 < 9) {
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
    (**(code **)(*piVar2 + 0x18))(param_1);
    (**(code **)(*DAT_00b5ad58 + 8))();
  }
  else {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(&DAT_009f35ac,0x1c);
    local_4 = 0;
    FUN_00796d50(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_007603c0 @ 0x007603c0 ====

int FUN_007603c0(void)

{
  char *pcVar1;
  int *piVar2;
  int extraout_EAX;
  int iVar3;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  uint uVar4;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int *in_ECX;
  int unaff_retaddr;
  undefined1 auStack_d0 [4];
  undefined1 uStack_cc;
  undefined4 uStack_c8;
  uint *puStack_c4;
  undefined4 uStack_c0;
  char *pcStack_bc;
  uint *puStack_b8;
  undefined4 local_98;
  void *local_94;
  undefined1 local_90;
  uint local_80 [6];
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  void *pvStack_2c;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 *puStack_18;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994d3f;
  pvStack_c = ExceptionList;
  local_98 = 0;
  local_80[1] = 0xf;
  local_80[0] = 0;
  local_90 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  piVar2 = (int *)(**(code **)(*in_ECX + 4))();
  if (piVar2 == (int *)0x0) {
    puStack_b8 = &local_98;
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    pcStack_bc = (char *)0x760446;
    FUN_00401660();
    if (0xf < local_80[0]) {
      _free(local_94);
      return extraout_EAX;
    }
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 0x48))();
    if (iVar3 == 0) {
      puStack_b8 = &local_98;
      *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
      *(undefined4 *)(unaff_retaddr + 0x14) = 0;
      *(undefined1 *)(unaff_retaddr + 4) = 0;
      pcStack_bc = (char *)0x76048c;
      FUN_00401660();
      if (0xf < local_80[0]) {
        _free(local_94);
        return extraout_EAX_00;
      }
    }
    else {
      local_80[0] = (**(code **)(*DAT_00b5ad20 + 0x4c))();
      local_80[2] = 0;
      local_80[3] = 0;
      local_80[4] = 0;
      iVar3 = 0;
      do {
        uStack_54 = 0xf;
        uStack_58 = 0;
        pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
        uStack_38 = 0xf;
        uStack_3c = 0;
        pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
        pcVar1 = (char *)(local_80[0] + iVar3 * 0x3c);
        puStack_b8 = (uint *)0x0;
        pcStack_bc = pcVar1 + 4;
        pvStack_c._0_1_ = 2;
        uStack_c0 = 0x76050e;
        FUN_00401660();
        if (*pcVar1 == '\0') {
          if (iVar3 == 0x18) {
            puStack_b8 = (uint *)0x76052e;
            (**(code **)(*in_ECX + 8))();
            puStack_18 = auStack_d0;
            puStack_b8 = (uint *)0xf;
            pcStack_bc = (char *)0x0;
            uStack_cc = 0;
            FUN_00401740(&DAT_009f35a4,5);
            pcStack_bc = (char *)FUN_00404230(auStack_34);
            puStack_b8 = (uint *)0x0;
            pvStack_c._0_1_ = 3;
            uStack_c0 = 0x76057a;
            FUN_00401660();
            pvStack_c._0_1_ = 2;
            if (0xf < uStack_1c) {
              puStack_b8 = (uint *)0x760599;
              _free(pvStack_30);
              return extraout_EAX_01;
            }
            uStack_1c = 0xf;
            uStack_20 = 0;
            pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
          }
          else {
            puStack_b8 = (uint *)&DAT_009f35aa;
            pcStack_bc = (char *)0x7605c2;
            FUN_00401740();
          }
        }
        else {
          puStack_b8 = (uint *)0x0;
          pcStack_bc = pcVar1 + 0x20;
          uStack_c0 = 0x7605d4;
          FUN_00401660();
        }
        puStack_b8 = (uint *)0x7605e7;
        FUN_004e6c20();
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
        if (0xf < uStack_38) {
          puStack_b8 = (uint *)0x760600;
          _free(pvStack_4c);
          return extraout_EAX_02;
        }
        uStack_38 = 0xf;
        uStack_3c = 0;
        pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
        if (0xf < uStack_54) {
          puStack_b8 = (uint *)0x760620;
          _free(pvStack_68);
          return extraout_EAX_03;
        }
        iVar3 = iVar3 + 1;
        uStack_54 = 0xf;
        uStack_58 = 0;
        pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
      } while (iVar3 < 0x1c);
      puStack_b8 = (uint *)0x76064b;
      uVar4 = (**(code **)(*DAT_00b5ad20 + 0x24))();
      pcStack_bc = (char *)(uVar4 & 0xffff | 0x140000);
      puStack_b8 = local_80;
      uStack_c0 = 0;
      puStack_c4 = &uStack_38;
      uStack_c8 = 0x76066d;
      puStack_b8 = (uint *)(**(code **)(*DAT_00b5a794 + 8))();
      puStack_8._0_1_ = 4;
      pcStack_bc = (char *)0x760682;
      FUN_00401660();
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
      if ((undefined1 *)0xf < puStack_18) {
        _free(pvStack_2c);
        return extraout_EAX_04;
      }
      puStack_b8 = &local_98;
      *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
      *(undefined4 *)(unaff_retaddr + 0x14) = 0;
      *(undefined1 *)(unaff_retaddr + 4) = 0;
      pcStack_bc = (char *)0x7606cb;
      FUN_00401660();
      FUN_004e67a0();
      if (0xf < local_80[0]) {
        _free(local_94);
        return extraout_EAX_05;
      }
    }
  }
  ExceptionList = pvStack_10;
  return unaff_retaddr;
}


// ==== FUN_00760710 @ 0x00760710 ====

void FUN_00760710(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5010002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  FUN_004244d0();
  return;
}


// ==== FUN_00760740 @ 0x00760740 ====

undefined4 FUN_00760740(void)

{
  return 0x70050000;
}


// ==== FUN_00760750 @ 0x00760750 ====

undefined4 FUN_00760750(void)

{
  return 0x70050001;
}


// ==== FUN_00760760 @ 0x00760760 ====

void FUN_00760760(byte param_1)

{
  void *in_ECX;
  
  FUN_0075ff40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00760780 @ 0x00760780 ====

void FUN_00760780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f36f8;
  return;
}


// ==== FUN_00760790 @ 0x00760790 ====

void FUN_00760790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f36f8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007607b0 @ 0x007607b0 ====

undefined4 FUN_007607b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_007607c0 @ 0x007607c0 ====

void FUN_007607c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994d63;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3734;
  pvVar1 = operator_new(4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00791bc0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad58 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ad58 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00760850 @ 0x00760850 ====

void FUN_00760850(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f370c;
  *(undefined1 *)(puVar1 + 1) = 0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00760880 @ 0x00760880 ====

void FUN_00760880(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f3720;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007608b0 @ 0x007608b0 ====

void FUN_007608b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994d75;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3734;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5ad58 = 0;
  *in_ECX = &PTR_FUN_009f36f8;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00760910 @ 0x00760910 ====

undefined4 FUN_00760910(void)

{
  return 0x70050002;
}


// ==== FUN_00760920 @ 0x00760920 ====

undefined4 FUN_00760920(void)

{
  return 0x7005000b;
}


// ==== FUN_00760930 @ 0x00760930 ====

void FUN_00760930(byte param_1)

{
  void *in_ECX;
  
  FUN_007608b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00760990 @ 0x00760990 ====

undefined4 FUN_00760990(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_0069a470(&param_1,param_1);
  if ((*piVar2 == *(int *)(in_ECX + 8)) || (iVar1 = *(int *)(*piVar2 + 0x28), iVar1 == 0)) {
    return 0;
  }
  (**(code **)(*DAT_00b5aefc + 0x10))(iVar1);
  return 1;
}


// ==== FUN_007609d0 @ 0x007609d0 ====

void FUN_007609d0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009f3864;
  DAT_00b5b1a8 = 0;
  FUN_004a7020(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00760a20 @ 0x00760a20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00760a20(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  undefined4 uStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  char *pcStack_bc;
  undefined1 local_9c [4];
  void *local_98;
  undefined4 local_88;
  uint local_84;
  undefined1 *puStack_80;
  int local_7c;
  int iStack_78;
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  void *pvStack_58;
  uint uStack_54;
  uint uStack_44;
  undefined4 uStack_40;
  int local_3c;
  int iStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00994e04;
  pvStack_14 = ExceptionList;
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  pcStack_bc = (char *)0x760a6c;
  ExceptionList = &pvStack_14;
  FUN_00401740();
  local_c = 0;
  iVar3 = FUN_0059a1e0();
  local_c = 0xffffffff;
  local_3c = iVar3;
  if (0xf < local_84) {
    _free(local_98);
    return;
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  uVar4 = (**(code **)(*DAT_00b5a6bc + 8))();
  if (*(uint *)(iVar3 + 0x54) < 0x10) {
    pcStack_bc = (char *)(iVar3 + 0x40);
  }
  else {
    pcStack_bc = *(char **)(iVar3 + 0x40);
  }
  uStack_c4 = 0x760adc;
  uStack_c0 = uVar4;
  iVar3 = FUN_007bb860();
  if (iVar3 != 0) {
    pcStack_bc = (char *)0x760aef;
    pcVar5 = (char *)FUN_007bc230();
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pcStack_bc = (char *)0x760b1b;
    FUN_00401740();
    pcStack_bc = auStack_34;
    local_c = 1;
    uStack_c0 = 0x760b3d;
    uStack_c0 = FUN_004022a0();
    local_c._0_1_ = 2;
    uStack_c4 = 0x760b4b;
    FUN_00796d50();
    local_c._0_1_ = 1;
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    pcStack_bc = (char *)0x760b90;
    FUN_00401740();
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_00406880();
    if (uStack_5c < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_70);
    return;
  }
  pcStack_bc = (char *)0x0;
  uStack_c4 = 0x760be0;
  uStack_c0 = uVar4;
  iVar3 = FUN_007bca30();
  if (iVar3 != 0) {
    pcStack_bc = (char *)0x760bf3;
    pcVar5 = (char *)FUN_007bc230();
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pcStack_bc = (char *)0x760c26;
    FUN_00401740();
    pcStack_bc = auStack_34;
    local_c = 4;
    uStack_c0 = 0x760c48;
    uStack_c0 = FUN_004022a0();
    local_c._0_1_ = 5;
    uStack_c4 = 0x760c56;
    FUN_00796d50();
    local_c._0_1_ = 4;
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    pcStack_bc = (char *)0x760c9b;
    FUN_00401740();
    local_c = CONCAT31(local_c._1_3_,6);
    FUN_00406880();
    if (uStack_5c < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_70);
    return;
  }
  pcStack_bc = (char *)0x760ced;
  FUN_007bc470();
  pcStack_bc = (char *)0xffffd8ef;
  uStack_c4 = 0x760cf8;
  uStack_c0 = uVar4;
  FUN_007bc620();
  uStack_c4 = 0xffffffff;
  uStack_cc = 0x760d00;
  uStack_c8 = uVar4;
  iVar3 = FUN_007bbfa0();
  if (iVar3 != 5) {
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    pcStack_bc = (char *)0x760d24;
    FUN_00401740();
    local_c = 7;
    FUN_00406880();
    if (uStack_5c < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_70);
    return;
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  uStack_54 = uStack_54 & 0xffffff00;
  local_c = 8;
  iStack_78 = 1;
  uStack_c0 = 0x760d82;
  pcStack_bc = (char *)uVar4;
  FUN_007bc400();
  uStack_c0 = 0xfffffffe;
  uStack_c8 = 0x760d8a;
  uStack_c4 = uVar4;
  FUN_007bc620();
  uStack_c8 = 0xffffffff;
  uStack_d0 = 0x760d92;
  uStack_cc = uVar4;
  iVar3 = FUN_007bbfa0();
  if (iVar3 == 5) {
    iStack_38 = local_7c + 4;
    do {
      pcStack_bc = (char *)0x760dbb;
      FUN_007bc470();
      pcStack_bc = (char *)0xfffffffe;
      uStack_c4 = 0x760dc3;
      uStack_c0 = uVar4;
      FUN_007bc620();
      uStack_c4 = 0xffffffff;
      uStack_cc = 0x760dcb;
      uStack_c8 = uVar4;
      pcVar5 = (char *)FUN_007bc230();
      local_84 = 0xf;
      local_88 = 0;
      local_98 = (void *)((uint)local_98 & 0xffffff00);
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcStack_bc = (char *)0x760df7;
      FUN_00401740();
      pcStack_bc = local_9c;
      local_c._0_1_ = 9;
      uStack_c0 = 0x760e10;
      FUN_00401660();
      local_c._0_1_ = 8;
      if (0xf < local_84) {
        _free(local_98);
        return;
      }
      local_84 = 0xf;
      local_88 = 0;
      local_98 = (void *)((uint)local_98 & 0xffffff00);
      pcStack_bc = (char *)0x760e48;
      FUN_007bbdf0();
      pcStack_bc = s_motion_009f3824;
      uStack_c4 = 0x760e53;
      uStack_c0 = uVar4;
      FUN_007bc470();
      uStack_c4 = 0xfffffffe;
      uStack_cc = 0x760e5b;
      uStack_c8 = uVar4;
      FUN_007bc620();
      uStack_cc = 0xffffffff;
      uStack_d4 = 0x760e63;
      uStack_d0 = uVar4;
      fVar8 = (float10)FUN_007bc1a0();
      local_7c = CONCAT22(local_7c._2_2_,in_FPUControlWord);
      uStack_d4 = 0xfffffffe;
      puStack_80 = (undefined1 *)(int)ROUND(fVar8);
      FUN_007bbdf0(uVar4);
      FUN_007bbdf0(uVar4,0xfffffffe);
      piVar6 = (int *)FUN_007611f0();
      *piVar6 = (int)ROUND(fVar8);
      puStack_80 = (undefined1 *)&uStack_d4;
      pcStack_bc = (char *)0xf;
      uStack_c0 = 0;
      uStack_d0 = uStack_d0 & 0xffffff00;
      FUN_00401740(s_Read_Emotimotion_Macro___s____d_009f382c,0x1f);
      uVar7 = FUN_00404230(auStack_34);
      local_c._0_1_ = 10;
      FUN_00796d50(uVar7);
      local_c = CONCAT31(local_c._1_3_,8);
      if (0xf < uStack_1c) {
        _free(pvStack_30);
        return;
      }
      iStack_78 = iStack_78 + 1;
      uStack_1c = 0xf;
      uStack_20 = 0;
      pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
      uStack_c0 = 0x760f45;
      pcStack_bc = (char *)uVar4;
      FUN_007bc400();
      uStack_c0 = 0xfffffffe;
      uStack_c8 = 0x760f4d;
      uStack_c4 = uVar4;
      FUN_007bc620();
      uStack_c8 = 0xffffffff;
      uStack_d0 = 0x760f55;
      uStack_cc = uVar4;
      iVar3 = FUN_007bbfa0();
    } while (iVar3 == 5);
  }
  pcStack_bc = (char *)0x760f69;
  FUN_007bbdf0();
  pcStack_bc = (char *)0xfffffffe;
  uStack_c4 = 0x760f71;
  uStack_c0 = uVar4;
  FUN_007bbdf0();
  (**(code **)(*DAT_00b5a7cc + 0x14))();
  if (uStack_44 < 0x10) {
    ExceptionList = pvStack_18;
    return;
  }
  pcStack_bc = (char *)0x760f98;
  _free(pvStack_58);
  return;
}


// ==== FUN_00760fc0 @ 0x00760fc0 ====

void FUN_00760fc0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994e19;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3864;
  iVar1 = FUN_004a37b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b1a8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b1a8 = in_ECX;
  }
  FUN_00760a20();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00761040 @ 0x00761040 ====

undefined4 * FUN_00761040(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_004a6cd0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_004a6cd0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    cVar2 = FUN_0040a6d0(piVar1[2] + 0xc,param_3);
    if (cVar2 != '\0') {
      FUN_004a6cd0(param_1,0,*(undefined4 *)(*(int *)(in_ECX + 4) + 8),param_3);
      return param_1;
    }
  }
  else {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_0079c420();
      cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
      if (cVar2 != '\0') {
        if (*(char *)(param_2[2] + 0x2d) == '\0') {
          FUN_004a6cd0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_004a6cd0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
    if (cVar2 != '\0') {
      FUN_00699bf0();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
        if (cVar2 == '\0') goto LAB_007611c3;
      }
      if (*(char *)(param_2[2] + 0x2d) == '\0') {
        FUN_004a6cd0(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_004a6cd0(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_007611c3:
  puVar3 = (undefined4 *)FUN_004a6eb0(local_8,param_3);
  *param_1 = *puVar3;
  return param_1;
}


// ==== FUN_007611f0 @ 0x007611f0 ====

int FUN_007611f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994d88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_004bb4d0(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0x24) < 0x10) {
      iVar3 = iVar2 + 0x10;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x10);
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),iVar3,*(undefined4 *)(iVar2 + 0x20));
    if (-1 < iVar3) goto LAB_00761293;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_10 = 0;
  local_4 = 0;
  piVar4 = (int *)FUN_00761040(&param_1,iVar2,local_2c);
  iVar2 = *piVar4;
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX;
  }
LAB_00761293:
  ExceptionList = local_c;
  return iVar2 + 0x28;
}


// ==== FUN_007612b0 @ 0x007612b0 ====

void FUN_007612b0(byte param_1)

{
  void *in_ECX;
  
  FUN_007609d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007612d0 @ 0x007612d0 ====

void FUN_007612d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3964;
  return;
}


// ==== FUN_007612e0 @ 0x007612e0 ====

void FUN_007612e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3964;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00761300 @ 0x00761300 ====

void FUN_00761300(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (*(char *)(in_ECX + 0x10) != '\0') {
    puVar1 = param_1;
    do {
      *puVar1 = puVar1[(in_ECX + 0x14) - (int)param_1];
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar2 < *(byte *)(in_ECX + 0x10));
  }
  param_1[*(byte *)(in_ECX + 0x10)] = 0;
  uVar2 = 0;
  if (*(char *)(in_ECX + 0x11) == '\0') {
    *(undefined1 *)((uint)*(byte *)(in_ECX + 0x11) + param_2) = 0;
    return;
  }
  do {
    *(undefined1 *)(uVar2 + param_2) =
         *(undefined1 *)(*(byte *)(in_ECX + 0x10) + uVar2 + in_ECX + 0x14);
    uVar2 = uVar2 + 1;
  } while (uVar2 < *(byte *)(in_ECX + 0x11));
  *(undefined1 *)((uint)*(byte *)(in_ECX + 0x11) + param_2) = 0;
  return;
}


// ==== FUN_00761390 @ 0x00761390 ====

void FUN_00761390(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (*(char *)(in_ECX + 0x10) != '\0') {
    puVar1 = param_1;
    do {
      *puVar1 = puVar1[(in_ECX + 0x14) - (int)param_1];
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar2 < *(byte *)(in_ECX + 0x10));
  }
  param_1[*(byte *)(in_ECX + 0x10)] = 0;
  uVar2 = 0;
  if (*(char *)(in_ECX + 0x12) == '\0') {
    *(undefined1 *)((uint)*(byte *)(in_ECX + 0x12) + param_2) = 0;
    return;
  }
  do {
    *(undefined1 *)(uVar2 + param_2) =
         *(undefined1 *)
          ((uint)*(byte *)(in_ECX + 0x11) + *(byte *)(in_ECX + 0x10) + uVar2 + in_ECX + 0x14);
    uVar2 = uVar2 + 1;
  } while (uVar2 < *(byte *)(in_ECX + 0x12));
  *(undefined1 *)((uint)*(byte *)(in_ECX + 0x12) + param_2) = 0;
  return;
}


// ==== FUN_00761420 @ 0x00761420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00761420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3970;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad08 = (undefined4 *)0x0;
    _DAT_00000000 = 0;
    return;
  }
  DAT_00b5ad08 = in_ECX;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00761450 @ 0x00761450 ====

void FUN_00761450(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994e38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3970;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
    in_ECX[1] = 0;
  }
  DAT_00b5ad08 = 0;
  *in_ECX = &PTR_FUN_009f3964;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007614b0 @ 0x007614b0 ====

void FUN_007614b0(int param_1)

{
  void **unaff_EDI;
  undefined4 uStack_9c;
  undefined1 auStack_98 [4];
  undefined1 uStack_94;
  void *pvStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  void **ppvStack_80;
  void **ppvStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  uint uStack_5c;
  uint uStack_58;
  void *apvStack_54 [5];
  uint uStack_40;
  void *pvStack_3c;
  undefined1 auStack_38 [12];
  undefined1 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994e5a;
  puStack_c = ExceptionList;
  pvStack_70 = (void *)0x0;
  if (*(int *)(param_1 + 0x10) == 0) {
    pvStack_70 = (void *)0x8360015;
  }
  else if (*(int *)(param_1 + 0x10) == 1) {
    pvStack_70 = (void *)0x8360016;
  }
  uStack_74 = 0;
  uStack_78 = 0x7614f8;
  ExceptionList = &puStack_c;
  ppvStack_80 = (void **)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_78 = 0xffffffff;
  ppvStack_7c = (void **)0x0;
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  uStack_84 = 0x761516;
  FUN_00401660();
  puStack_c = (undefined1 *)0x0;
  if (*(byte *)(param_1 + 0x14) == 0) {
    uStack_78 = 0;
  }
  else {
    uStack_78 = *(byte *)(param_1 + 0x14) - 1;
  }
  ppvStack_7c = apvStack_54 + -5;
  ppvStack_80 = (void **)0x76153c;
  (**(code **)(*DAT_00b5ad1c + 0x30))();
  uStack_14 = 1;
  if (uStack_58 < 0x10) {
    unaff_EDI = apvStack_54 + -6;
  }
  puStack_c = (undefined1 *)&uStack_9c;
  uStack_84 = 0xf;
  uStack_88 = 0;
  auStack_98[0] = 0;
  ppvStack_80 = unaff_EDI;
  FUN_00401660(auStack_38,0,0xffffffff);
  FUN_00404230(apvStack_54);
  puStack_c = auStack_98;
  uStack_9c = 0xffffffff;
  ppvStack_80 = (void **)0xf;
  uStack_84 = 0;
  uStack_14 = 2;
  uStack_94 = 0;
  FUN_00401660(apvStack_54,0);
  uStack_9c = 2;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return;
  }
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return;
  }
  uStack_78 = 0xf;
  ppvStack_7c = (void **)0x0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (uStack_40 < 0x10) {
    ExceptionList = pvStack_3c;
    return;
  }
  _free(apvStack_54[0]);
  return;
}


// ==== FUN_00761620 @ 0x00761620 ====

/* WARNING: Removing unreachable block (ram,0x007616ea) */

undefined4 FUN_00761620(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  undefined4 uStack_54;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  undefined1 uStack_2c;
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994e74;
  pvStack_c = ExceptionList;
  uStack_54 = 0x280016;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
  FUN_00401660(uVar1,0,0xffffffff);
  uStack_34 = 0;
  pvStack_18 = (void *)0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  uStack_38 = 3;
  pvStack_c = (void *)0x1;
  uStack_34 = (**(code **)(*DAT_00b5ad10 + 0xc))();
  FUN_00401660(&uStack_54,0,0xffffffff);
  (**(code **)(*DAT_00b5ad10 + 8))(&uStack_38);
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return 1;
  }
  _free(pvStack_30);
  return extraout_EAX;
}


// ==== FUN_00761710 @ 0x00761710 ====

undefined4 FUN_00761710(int param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 extraout_EAX;
  char *pcVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_4c [4];
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00994e99;
  pvStack_c = ExceptionList;
  local_2c = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_30 = 0xb;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  local_2c = (**(code **)(*DAT_00b5ad10 + 0xc))();
  if (((*(ushort *)(param_1 + 0x10) == 0) || (0x1ff < *(ushort *)(param_1 + 0x10))) ||
     (pcVar1 = (char *)(param_1 + 0x14), pcVar1 == (char *)0x0)) {
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(&DAT_009f391c,0xe);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00796d50(auStack_4c);
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return extraout_EAX;
    }
  }
  else {
    pcVar3 = pcVar1;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(pcVar1,(int)pcVar3 - (param_1 + 0x15));
    (**(code **)(*DAT_00b5ad10 + 8))(&local_30);
    if (*(int *)(in_ECX + 4) == 0) {
      pvVar4 = operator_new(0x10);
      local_4._0_1_ = 2;
      if (pvVar4 == (void *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_0089fcc0();
      }
      local_4 = (uint)local_4._1_3_ << 8;
      *(undefined4 *)(in_ECX + 4) = uVar5;
    }
    FUN_0089fbe0(auStack_28);
  }
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return 1;
  }
  _free(local_24);
  return extraout_EAX_00;
}


// ==== FUN_00761870 @ 0x00761870 ====

/* WARNING: Removing unreachable block (ram,0x00761968) */

void FUN_00761870(void)

{
  undefined1 auStack_98 [4];
  undefined1 uStack_94;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  uint uStack_3c;
  void *local_30;
  undefined4 local_2c;
  undefined1 local_24;
  uint uStack_1c;
  void *pvStack_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  puStack_8 = &LAB_00994ebb;
  pvStack_c = ExceptionList;
  local_2c = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_30 = (void *)0xb;
  local_4 = (undefined1 *)0x0;
  ExceptionList = &pvStack_c;
  local_2c = (**(code **)(*DAT_00b5ad10 + 0xc))();
  uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_88 = 0x7618e6;
  FUN_00401660();
  local_4 = auStack_98;
  uStack_84 = 0;
  pvStack_c._0_1_ = 1;
  uStack_94 = 0;
  FUN_00401660(auStack_54 + -0x1c,0,0xffffffff);
  uStack_84 = FUN_00404230(auStack_54);
  pvStack_c._0_1_ = 2;
  uStack_88 = 0x761938;
  FUN_00401660();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  (**(code **)(*DAT_00b5ad10 + 8))();
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return;
  }
  uStack_84 = 0x761992;
  _free(local_30);
  return;
}


// ==== FUN_007619b0 @ 0x007619b0 ====

undefined4 FUN_007619b0(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 local_184;
  undefined4 local_180;
  void *pvStack_17c;
  undefined1 local_178;
  uint local_168;
  undefined4 local_164;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  undefined4 uStack_130;
  uint uStack_12c;
  char local_128 [28];
  char local_10c [252];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994ee6;
  pvStack_c = ExceptionList;
  local_128[0] = '\0';
  local_10c[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_00761300(local_128,local_10c);
  local_180 = 0;
  local_164 = 0xf;
  local_168 = 0;
  local_178 = 0;
  local_184 = 1;
  local_4 = 0;
  local_180 = (**(code **)(*DAT_00b5ad10 + 0xc))();
  pcVar2 = local_128;
  uStack_148 = 0xf;
  uStack_14c = 0;
  pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(local_128,(int)pcVar2 - (int)(local_128 + 1));
  local_4._0_1_ = 1;
  uVar3 = FUN_00402220(auStack_144,auStack_160,&DAT_009f38d8);
  local_4._0_1_ = 2;
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_12c) {
    _free(pvStack_140);
    return extraout_EAX;
  }
  uStack_12c = 0xf;
  uStack_130 = 0;
  pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < uStack_148) {
    _free(pvStack_15c);
    return extraout_EAX_00;
  }
  pcVar2 = local_10c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_004020e0(local_10c,(int)pcVar2 - (int)(local_10c + 1));
  (**(code **)(*DAT_00b5ad10 + 8))(&local_184);
  if (local_168 < 0x10) {
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(pvStack_17c);
  return extraout_EAX_01;
}


// ==== FUN_00761b30 @ 0x00761b30 ====

void FUN_00761b30(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  void *_Memory;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994f00;
  local_c = ExceptionList;
  if (DAT_00b5acd8 != (int *)0x0) {
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
    if (iVar1 == 0) {
      uStack_30 = 0xf;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      FUN_00401740(&DAT_009f38dc,0x1d);
      uStack_4 = 0;
      FUN_00796d50(auStack_48);
      if (0xf < uStack_30) {
        _Memory = pvStack_44;
LAB_00761c2e:
        _free(_Memory);
        return;
      }
    }
    else {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      uStack_4 = 1;
      uStack_2c = param_1;
      FUN_00401660(param_2,0,0xffffffff);
      puVar2 = operator_new(0x24);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009f397c;
        puVar2[8] = 0xf;
        puVar2[7] = 0;
        *(undefined1 *)(puVar2 + 3) = 0;
      }
      puVar2[1] = uStack_2c;
      FUN_00401660(auStack_28,0,0xffffffff);
      FUN_00797a20(puVar2);
      if (0xf < uStack_10) {
        _Memory = pvStack_24;
        goto LAB_00761c2e;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00761c50 @ 0x00761c50 ====

undefined4 FUN_00761c50(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined1 local_1a0 [4];
  void *pvStack_19c;
  undefined4 uStack_18c;
  uint uStack_188;
  undefined4 local_184;
  undefined4 local_180;
  void *pvStack_17c;
  undefined1 local_178;
  uint local_168;
  undefined4 local_164;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  undefined4 uStack_130;
  uint uStack_12c;
  char local_128 [28];
  char local_10c [252];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994f36;
  pvStack_c = ExceptionList;
  local_128[0] = '\0';
  local_1a0[0] = 0;
  local_10c[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0075e390(local_1a0);
  FUN_00761390(local_128,local_10c);
  local_180 = 0;
  local_164 = 0xf;
  local_168 = 0;
  local_178 = 0;
  local_184 = 3;
  local_4 = 0;
  local_180 = (**(code **)(*DAT_00b5ad10 + 0xc))();
  pcVar2 = local_128;
  uStack_188 = 0xf;
  uStack_18c = 0;
  pvStack_19c = (void *)((uint)pvStack_19c & 0xffffff00);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(local_128,(int)pcVar2 - (int)(local_128 + 1));
  local_4._0_1_ = 1;
  uVar3 = FUN_004022a0(auStack_144,s_From_009f3900,local_1a0);
  local_4._0_1_ = 2;
  uVar3 = FUN_00402220(auStack_160,uVar3,&DAT_009f38fc);
  local_4._0_1_ = 3;
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_148) {
    _free(pvStack_15c);
    return extraout_EAX;
  }
  uStack_148 = 0xf;
  uStack_14c = 0;
  pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
  if (0xf < uStack_12c) {
    _free(pvStack_140);
    return extraout_EAX_00;
  }
  uStack_12c = 0xf;
  uStack_130 = 0;
  pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < uStack_188) {
    _free(pvStack_19c);
    return extraout_EAX_01;
  }
  pcVar2 = local_10c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_004020e0(local_10c,(int)pcVar2 - (int)(local_10c + 1));
  (**(code **)(*DAT_00b5ad10 + 8))(&local_184);
  if (local_168 < 0x10) {
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(pvStack_17c);
  return extraout_EAX_02;
}


// ==== FUN_00761e30 @ 0x00761e30 ====

undefined4 FUN_00761e30(int param_1)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 extraout_EAX;
  undefined4 uVar7;
  undefined4 extraout_EAX_00;
  char *pcVar8;
  undefined4 extraout_EAX_01;
  uint uVar9;
  void *pvStack_4c;
  void *apvStack_48 [3];
  undefined4 uStack_3c;
  uint uStack_38;
  uint auStack_34 [3];
  void *pvStack_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00994f58;
  pvStack_c = ExceptionList;
  auStack_34[2] = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  auStack_34[1] = 4;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  auStack_34[2] = (**(code **)(*DAT_00b5ad10 + 0xc))();
  piVar3 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
  uVar9 = 0;
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  if (iVar4 != 0) {
    do {
      piVar5 = (int *)(**(code **)(*piVar3 + 4))();
      if (*piVar5 == *(int *)(param_1 + 0x10)) {
        uVar7 = FUN_00402220(&pvStack_4c,piVar5 + 4,&DAT_009f3908);
        local_4._0_1_ = 1;
        FUN_00401660(uVar7,0,0xffffffff);
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < auStack_34[0]) {
          _free(apvStack_48[0]);
          return extraout_EAX_00;
        }
        break;
      }
      (**(code **)(*piVar3 + 0xc))();
      uVar9 = uVar9 + 1;
      uVar6 = (**(code **)(*piVar3 + 0x10))();
    } while (uVar9 < uVar6);
  }
  (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar3);
  if (((*(ushort *)(param_1 + 0x14) == 0) || (0xff < *(ushort *)(param_1 + 0x14))) ||
     (pcVar1 = (char *)(param_1 + 0x18), pcVar1 == (char *)0x0)) {
    uStack_38 = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(&DAT_009f390c,0xe);
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    FUN_00796d50(auStack_34 + -7);
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return extraout_EAX;
    }
    if (local_14 < 0x10) {
      ExceptionList = local_10;
      return 1;
    }
  }
  else {
    pcVar8 = pcVar1;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    FUN_004020e0(pcVar1,(int)pcVar8 - (param_1 + 0x19));
    (**(code **)(*DAT_00b5ad10 + 8))(auStack_34);
    if (local_14 < 0x10) {
      ExceptionList = local_10;
      return 1;
    }
  }
  _free(pvStack_28);
  return extraout_EAX_01;
}


// ==== FUN_00761ff0 @ 0x00761ff0 ====

undefined4 FUN_00761ff0(int param_1)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  char *pcVar5;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined1 auStack_84 [4];
  void *pvStack_80;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 auStack_4c [4];
  void *pvStack_48;
  uint uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00994f9b;
  local_c = ExceptionList;
  if (DAT_00b5acd8 != (int *)0x0) {
    local_2c = 0;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_30 = 0;
    local_4 = 0;
    ExceptionList = &local_c;
    local_2c = (**(code **)(*DAT_00b5ad10 + 0xc))();
    piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x10));
    if (piVar3 == (int *)0x0) {
      uStack_6c = 0xf;
      uStack_70 = 0;
      pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
      FUN_00401740(&DAT_009f38a4,0x1d);
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_00796d50(auStack_84);
      if (0xf < uStack_6c) {
        _free(pvStack_80);
        return extraout_EAX;
      }
    }
    else {
      piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
      uVar4 = (**(code **)(*piVar3 + 0x40))(auStack_4c);
      local_4._0_1_ = 2;
      uVar4 = FUN_00402220(auStack_84,uVar4,&DAT_009f38c4);
      local_4._0_1_ = 3;
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_6c) {
        _free(pvStack_80);
        return extraout_EAX_00;
      }
      uStack_6c = 0xf;
      uStack_70 = 0;
      pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
      local_4 = (uint)local_4._1_3_ << 8;
      if (0xf < uStack_34) {
        _free(pvStack_48);
        return extraout_EAX_01;
      }
      if (((*(ushort *)(param_1 + 0x14) == 0) || (0xff < *(ushort *)(param_1 + 0x14))) ||
         (pcVar1 = (char *)(param_1 + 0x18), pcVar1 == (char *)0x0)) {
        FUN_00401830(&DAT_009f38c8);
        local_4 = CONCAT31(local_4._1_3_,4);
        FUN_00796d50(auStack_84);
        if (0xf < uStack_6c) {
          _free(pvStack_80);
          return extraout_EAX_02;
        }
      }
      else {
        pcVar5 = pcVar1;
        do {
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        FUN_004020e0(pcVar1,(int)pcVar5 - (param_1 + 0x19));
        (**(code **)(*DAT_00b5ad10 + 8))(&local_30);
        FUN_00401830(pcVar1);
        local_4 = CONCAT31(local_4._1_3_,5);
        FUN_00761b30(*(undefined4 *)(param_1 + 0x10),auStack_68);
        if (0xf < uStack_50) {
          _free(pvStack_64);
          return extraout_EAX_03;
        }
        uStack_50 = 0xf;
        uStack_54 = 0;
        pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
      }
    }
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX_04;
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00762250 @ 0x00762250 ====

undefined4 FUN_00762250(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_00424500();
  if (uVar2 < 0x511000d) {
    if (uVar2 == 0x511000c) {
      cVar1 = FUN_00761e30(*(undefined4 *)(param_1 + 0xc));
    }
    else if (uVar2 < 0x50d0004) {
      if (uVar2 == 0x50d0003) {
        cVar1 = FUN_00761ff0(*(undefined4 *)(param_1 + 0xc));
      }
      else {
        if (uVar2 != 0x5060000) {
          if (uVar2 != 0x5060001) {
            return 0;
          }
          FUN_00761620(*(undefined4 *)(param_1 + 0xc));
          goto LAB_00762291;
        }
        cVar1 = FUN_00761c50(*(undefined4 *)(param_1 + 0xc));
      }
    }
    else {
      if (uVar2 != 0x50d0006) {
        return 0;
      }
      cVar1 = FUN_007619b0(*(undefined4 *)(param_1 + 0xc));
    }
  }
  else {
    if (uVar2 == 0x5310005) {
      FUN_007614b0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar2 != 0x7000002) {
      if (uVar2 != 0x7000008) {
        return 0;
      }
      FUN_00761870(*(undefined4 *)(param_1 + 0xc));
      goto LAB_00762291;
    }
    cVar1 = FUN_00761710(*(undefined4 *)(param_1 + 0xc));
  }
  if (cVar1 == '\0') {
    return 0;
  }
LAB_00762291:
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar3 = &PTR_FUN_009ee8cc;
  FUN_00797a20(puVar3);
  return 1;
}


// ==== FUN_00762370 @ 0x00762370 ====

undefined4 FUN_00762370(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if ((iVar2 == 0x50011) && (cVar1 = FUN_00762250(param_1), cVar1 != '\0')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))(param_1), cVar1 == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_007623c0 @ 0x007623c0 ====

void FUN_007623c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00761450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007623e0 @ 0x007623e0 ====

undefined4 FUN_007623e0(void)

{
  return 0x7004000d;
}


// ==== FUN_007623f0 @ 0x007623f0 ====

void FUN_007623f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00762410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00762410 @ 0x00762410 ====

void FUN_00762410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f397c;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00762450 @ 0x00762450 ====

void FUN_00762450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3b6c;
  return;
}


// ==== FUN_00762460 @ 0x00762460 ====

void FUN_00762460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3b6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00762480 @ 0x00762480 ====

undefined4 FUN_00762480(void)

{
  return 0x70040003;
}


// ==== FUN_00762490 @ 0x00762490 ====

undefined4 FUN_00762490(void)

{
  return 0x70040004;
}


// ==== FUN_007624a0 @ 0x007624a0 ====

undefined4 FUN_007624a0(void)

{
  return 0x70040005;
}


// ==== FUN_007624b0 @ 0x007624b0 ====

undefined4 FUN_007624b0(void)

{
  return 0x70040011;
}


// ==== FUN_007624c0 @ 0x007624c0 ====

undefined4 FUN_007624c0(void)

{
  return 0x70040018;
}


// ==== FUN_007624d0 @ 0x007624d0 ====

undefined4 FUN_007624d0(void)

{
  return 0x70910015;
}


// ==== FUN_007624e0 @ 0x007624e0 ====

undefined4 FUN_007624e0(void)

{
  return 0x70910016;
}


// ==== FUN_007624f0 @ 0x007624f0 ====

undefined4 FUN_007624f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x58);
}


// ==== FUN_00762500 @ 0x00762500 ====

void FUN_00762500(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = param_1;
  return;
}


// ==== FUN_00762510 @ 0x00762510 ====

void FUN_00762510(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ee8cc;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00762540 @ 0x00762540 ====

void FUN_00762540(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_00762550 @ 0x00762550 ====

void FUN_00762550(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 4);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = *(undefined4 *)(in_ECX + 0x5c);
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f3c20;
  puVar1[1] = 0;
  puVar1[1] = *(undefined4 *)(in_ECX + 0x5c);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007625a0 @ 0x007625a0 ====

undefined4 FUN_007625a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x5c);
}


// ==== FUN_007625b0 @ 0x007625b0 ====

void FUN_007625b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f3be4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007625e0 @ 0x007625e0 ====

void FUN_007625e0(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994fc6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009d9984;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f3bf8;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f3c48;
  }
  FUN_00797a20(puVar1);
  iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar2 == 1) {
    iVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if ((iVar2 != 2) && (iVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar2 != 1)) {
      ExceptionList = pvStack_c;
      return;
    }
    pvVar3 = operator_new(8);
    uStack_4 = 0;
    if (pvVar3 != (void *)0x0) {
      uVar4 = FUN_006ad050();
      *(undefined4 *)(in_ECX + 0x20) = uVar4;
      ExceptionList = pvStack_c;
      return;
    }
  }
  else {
    iVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if ((iVar2 != 2) && (iVar2 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar2 != 4)) {
      ExceptionList = pvStack_c;
      return;
    }
    pvVar3 = operator_new(8);
    uStack_4 = 1;
    if (pvVar3 != (void *)0x0) {
      uVar4 = FUN_006ad050();
      *(undefined4 *)(in_ECX + 0x20) = uVar4;
      ExceptionList = pvStack_c;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00762720 @ 0x00762720 ====

void FUN_00762720(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009d9998;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f3c0c;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f3c5c;
  }
  FUN_00797a20(puVar1);
  if (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_007627a0 @ 0x007627a0 ====

void FUN_007627a0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007627a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad10 + 4))();
  return;
}


// ==== FUN_007627b0 @ 0x007627b0 ====

undefined4 FUN_007627b0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994fdb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_refresh_chatwnd_009f3ae4,0xf);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x14))();
    ExceptionList = local_c;
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_chatwnd_009f3af4,0xc);
  if (iVar2 == 0) {
    puVar3 = operator_new(4);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009d9984;
      FUN_00797a20(puVar3);
      ExceptionList = local_c;
      return 1;
    }
  }
  else {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_chatwnd_009f3b04,0xc);
    if (iVar2 != 0) {
      cVar1 = FUN_004036a0(param_1 + 8,s_show_gmtool_009f3b14);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(param_1 + 8,s_hide_gmtool_009f3b20);
        if (cVar1 != '\0') {
          if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)in_ECX[8])(1);
          }
          in_ECX[8] = 0;
        }
        ExceptionList = local_c;
        return 0;
      }
      pvVar4 = operator_new(8);
      local_4 = 0;
      if (pvVar4 == (void *)0x0) {
        in_ECX[8] = 0;
        ExceptionList = local_c;
        return 0;
      }
      iVar2 = FUN_006ad050();
      in_ECX[8] = iVar2;
      ExceptionList = local_c;
      return 0;
    }
    puVar3 = operator_new(4);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009d9998;
      FUN_00797a20(puVar3);
      ExceptionList = local_c;
      return 1;
    }
  }
  FUN_00797a20(0);
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00762960 @ 0x00762960 ====

undefined4 FUN_00762960(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x20008) {
    FUN_00762550(param_1);
    return 1;
  }
  if ((iVar2 == 0x70004) && (cVar1 = FUN_007627b0(param_1), cVar1 != '\0')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0x20) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 8))(param_1), cVar1 != '\x01')) {
    return 0;
  }
  return 1;
}


// ==== FUN_007629c0 @ 0x007629c0 ====

void FUN_007629c0(int param_1)

{
  int *_Dst;
  int in_ECX;
  
  _Dst = *(int **)(in_ECX + 0x2c);
  if (_Dst != *(int **)(in_ECX + 0x30)) {
    while (*_Dst != param_1) {
      _Dst = _Dst + 1;
      if (_Dst == *(int **)(in_ECX + 0x30)) {
        return;
      }
    }
    _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x30) - (int)(_Dst + 1) >> 2) * 4);
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + -4;
  }
  return;
}


// ==== FUN_00762a10 @ 0x00762a10 ====

uint FUN_00762a10(undefined4 param_1,byte *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void **ppvVar3;
  void *pvVar4;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  int in_ECX;
  uint uVar5;
  byte ****ppppbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  byte ****local_24 [4];
  uint local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_00994ff5;
  puVar1 = *(undefined4 **)(in_ECX + 0x40);
  puVar2 = (undefined4 *)*puVar1;
  uStack_3 = 0;
  ppvVar3 = &local_c;
  local_c = ExceptionList;
  pvVar4 = ExceptionList;
  do {
    ExceptionList = ppvVar3;
    if (puVar2 == puVar1) {
      local_4 = 0;
      if (in_stack_0000001c < 0x10) {
        ExceptionList = local_c;
        return (uint)pvVar4 & 0xffffff00;
      }
      _free(param_2);
      return extraout_EAX_00;
    }
    local_4 = 0;
    local_10 = 0xf;
    local_14 = 0;
    local_24[0] = (byte ****)((uint)local_24[0] & 0xffffff00);
    FUN_00401660(puVar2 + 2,0,0xffffffff);
    pvVar4 = (void *)0x0;
    _local_4 = CONCAT31(uStack_3,1);
    pbVar7 = param_2;
    if (in_stack_0000001c < 0x10) {
      pbVar7 = (byte *)&param_2;
    }
    if (local_14 == 0) {
LAB_00762aac:
      if ((in_stack_00000018 <= local_14) &&
         (pvVar4 = (void *)(uint)(local_14 != in_stack_00000018), pvVar4 == (void *)0x0)) {
        if (0xf < local_10) {
          _free(local_24[0]);
          return extraout_EAX_01;
        }
        local_10 = 0xf;
        local_14 = 0;
        local_24[0] = (byte ****)((uint)local_24[0]._1_3_ << 8);
        if (in_stack_0000001c < 0x10) {
          ExceptionList = local_c;
          return 1;
        }
        _free(param_2);
        return extraout_EAX_02;
      }
    }
    else {
      uVar5 = in_stack_00000018;
      if (local_14 < in_stack_00000018) {
        uVar5 = local_14;
      }
      ppppbVar6 = local_24[0];
      if (local_10 < 0x10) {
        ppppbVar6 = (byte ****)local_24;
      }
      bVar8 = false;
      pvVar4 = (void *)0x0;
      bVar9 = true;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar8 = *(byte *)ppppbVar6 < *pbVar7;
        bVar9 = *(byte *)ppppbVar6 == *pbVar7;
        ppppbVar6 = (byte ****)((int)ppppbVar6 + 1);
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        pvVar4 = (void *)((1 - (uint)bVar8) - (uint)(bVar8 != 0));
      }
      if (pvVar4 == (void *)0x0) goto LAB_00762aac;
    }
    local_4 = 0;
    if (0xf < local_10) {
      _free(local_24[0]);
      return extraout_EAX;
    }
    puVar2 = (undefined4 *)*puVar2;
    local_10 = 0xf;
    local_14 = 0;
    local_24[0] = (byte ****)((uint)local_24[0]._1_3_ << 8);
    ppvVar3 = ExceptionList;
  } while( true );
}


// ==== FUN_00762b80 @ 0x00762b80 ====

void FUN_00762b80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099500a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x20);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_007651e0(param_1);
  }
  local_4 = 0xffffffff;
  FUN_00797a20(uVar2,pvVar1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00762be0 @ 0x00762be0 ====

int FUN_00762be0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int extraout_EAX;
  int in_ECX;
  int iVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099501c;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009f3a8c,0);
  puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 0x40);
  iVar2 = 0;
  local_4 = 0;
  do {
    if (puVar1 == *(undefined4 **)(in_ECX + 0x40)) {
LAB_00762c53:
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
    if (iVar2 == param_2) {
      FUN_00401660(puVar1 + 2,0,0xffffffff);
      goto LAB_00762c53;
    }
    puVar1 = (undefined4 *)*puVar1;
    iVar2 = iVar2 + 1;
  } while( true );
}


// ==== FUN_00762ca0 @ 0x00762ca0 ====

undefined4 FUN_00762ca0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00762be0(param_1,*(undefined4 *)(in_ECX + 0x38));
  return param_1;
}


// ==== FUN_00762cc0 @ 0x00762cc0 ====

undefined4 FUN_00762cc0(undefined4 param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + 1;
  if (*(uint *)(in_ECX + 0x44) <= *(uint *)(in_ECX + 0x38)) {
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  FUN_00762be0(param_1,*(undefined4 *)(in_ECX + 0x38));
  return param_1;
}


// ==== FUN_00762cf0 @ 0x00762cf0 ====

undefined4 FUN_00762cf0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x38);
  if (iVar1 == 0) {
    iVar1 = *(int *)(in_ECX + 0x44);
  }
  *(int *)(in_ECX + 0x38) = iVar1 + -1;
  FUN_00762be0(param_1,iVar1 + -1);
  return param_1;
}


// ==== FUN_00762d30 @ 0x00762d30 ====

int FUN_00762d30(int param_1,int param_2)

{
  undefined4 *puVar1;
  int extraout_EAX;
  int in_ECX;
  int iVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099502e;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009f3a8d,0);
  puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 0x50);
  iVar2 = 0;
  local_4 = 0;
  do {
    if (puVar1 == *(undefined4 **)(in_ECX + 0x50)) {
LAB_00762da3:
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
    if (iVar2 == param_2) {
      FUN_00401660(puVar1 + 2,0,0xffffffff);
      goto LAB_00762da3;
    }
    puVar1 = (undefined4 *)*puVar1;
    iVar2 = iVar2 + 1;
  } while( true );
}


// ==== FUN_00762df0 @ 0x00762df0 ====

undefined4 FUN_00762df0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00762d30(param_1,*(undefined4 *)(in_ECX + 0x48));
  return param_1;
}


// ==== FUN_00762e10 @ 0x00762e10 ====

undefined4 FUN_00762e10(undefined4 param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + 1;
  if (*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x54)) {
    if (9 < *(int *)(in_ECX + 0x48)) {
      *(undefined4 *)(in_ECX + 0x48) = 9;
    }
  }
  else {
    *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x54) + -1;
  }
  FUN_00762d30(param_1,*(undefined4 *)(in_ECX + 0x48));
  return param_1;
}


// ==== FUN_00762e50 @ 0x00762e50 ====

undefined4 FUN_00762e50(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x48);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x48) = 0xffffffff;
  }
  FUN_00762d30(param_1,*(undefined4 *)(in_ECX + 0x48));
  return param_1;
}


// ==== FUN_00762e80 @ 0x00762e80 ====

/* WARNING: Removing unreachable block (ram,0x00762f00) */

void FUN_00762e80(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 auStack_2e [34];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995040;
  pvStack_c = ExceptionList;
  uVar3 = 0;
  ExceptionList = &pvStack_c;
  do {
    local_4 = 0;
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar3 | 0x3ed0000);
    FUN_00401660(uVar1,0,0xffffffff);
    (**(code **)(*DAT_00b5ad10 + 8))(auStack_2e + -10);
    local_4 = 0xffffffff;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ee8cc;
  }
  FUN_00797a20(puVar2);
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00762f60 @ 0x00762f60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00762f60(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int *in_ECX;
  void *unaff_EBX;
  uint unaff_ESI;
  undefined4 uStack_19c;
  int iStack_194;
  undefined1 auStack_16a [14];
  uint uStack_15c;
  undefined1 uStack_155;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined1 auStack_14c [4];
  void *pvStack_148;
  undefined1 auStack_13c [8];
  uint uStack_134;
  void *pvStack_3c;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995081;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar3 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar3 == 1) {
    if ((uint)(iVar2 - in_ECX[0x18]) < 10000) {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_150 = 0xf;
      uStack_154 = 0;
      FUN_00401660();
      pvStack_c = (void *)0x0;
      FUN_00401740(&DAT_009f3aa0,4);
      FUN_00404230(auStack_14c);
      pvStack_c._0_1_ = 1;
      FUN_00401ff0();
      pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
      if (0xf < uStack_134) {
        _free(pvStack_148);
        return;
      }
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401ff0();
      FUN_00401660(auStack_16a + -6,0,0xffffffff);
      (**(code **)(*in_ECX + 0x28))(2);
      if (unaff_ESI < 0x10) {
        ExceptionList = pvStack_3c;
        return;
      }
      _free((void *)0x0);
      return;
    }
  }
  else if (((iVar3 == 0) && (iVar3 = FUN_00403620(), iVar3 == 0)) &&
          ((uint)(iVar2 - in_ECX[0x18]) < 10000)) {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x2;
    FUN_00401830(&DAT_009f3aa8);
    FUN_00404230(auStack_14c);
    pvStack_c._0_1_ = 3;
    FUN_00401ff0();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  pvVar4 = operator_new(0x400);
  *(int *)((int)pvVar4 + 8) = iVar2;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x50d0006;
  *(undefined2 *)((int)pvVar4 + 6) = 0x14;
  FUN_004244d0();
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
  FUN_0044a580();
  iVar2 = (**(code **)(*piVar5 + 0x40))();
  uStack_34 = 4;
  if (*(uint *)(iVar2 + 0x18) < 0x10) {
    iVar2 = iVar2 + 4;
  }
  else {
    iVar2 = *(int *)(iVar2 + 4);
  }
  FUN_0047aa30(&uStack_155,&DAT_009f3b30,iVar2);
  cVar1 = FUN_00764ff0(&uStack_155,auStack_13c);
  uStack_34 = 0xffffffff;
  if (0xf < uStack_15c) {
    _free(unaff_EBX);
    return;
  }
  if (cVar1 != '\0') {
    FUN_004d8570(uStack_19c);
    FUN_00401660(param_1,0,0xffffffff);
    in_ECX[0x18] = iStack_194;
  }
  ExceptionList = pvStack_3c;
  return;
}


// ==== FUN_00763320 @ 0x00763320 ====

/* WARNING: Removing unreachable block (ram,0x00763430) */
/* WARNING: Removing unreachable block (ram,0x007636cd) */

void FUN_00763320(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int *in_ECX;
  uint unaff_ESI;
  uint uVar5;
  uint in_stack_00000010;
  undefined4 uStack_214;
  undefined4 *****pppppuStack_210;
  undefined1 *puStack_20c;
  undefined4 uStack_208;
  uint *puStack_204;
  undefined4 *****pppppuStack_200;
  undefined4 *****pppppuStack_1fc;
  undefined1 local_1e8 [4];
  char acStack_1e4 [4];
  void *pvStack_1e0;
  uint uStack_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  uint uStack_1ac;
  undefined1 auStack_184 [4];
  void *pvStack_180;
  undefined4 uStack_170;
  uint uStack_16c;
  char acStack_168 [28];
  undefined1 auStack_14c [4];
  void *pvStack_148;
  undefined1 local_144;
  uint auStack_134 [57];
  void *pvStack_50;
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 uStack_24;
  undefined4 *****pppppuStack_20;
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *****local_4;
  
  puStack_8 = &LAB_009950e8;
  pvStack_c = ExceptionList;
  local_1d4 = 0xf;
  local_1d8 = 0;
  local_4 = (undefined4 *****)0x1;
  local_144 = 0;
  local_1e8[0] = 0;
  pppppuStack_1fc = (undefined4 *****)0x76337c;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  (**(code **)*DAT_00b5b18c)();
  if (uStack_1ac != 0) {
    unaff_ESI = 0;
    uStack_1dc = uStack_1dc & 0xffffff00;
    uVar5 = 0;
    uStack_24 = 3;
    if (uStack_1ac != 0) {
      if (uStack_1ac == 0) {
        FUN_0079dba3();
      }
      do {
        cVar1 = FUN_00403d70();
        if (cVar1 != '\0') {
          uVar5 = uVar5 + 1;
        }
        pppppuStack_1fc = (undefined4 *****)0x7633fd;
        FUN_004020e0();
        uVar5 = uVar5 + 1;
      } while (uVar5 < uStack_1ac);
    }
    pppppuStack_1fc = (undefined4 *****)auStack_1c;
    pppppuStack_200 = (undefined4 *****)0x76341f;
    FUN_00404440();
  }
  uStack_24 = 2;
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = uVar2;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x5060000;
  *(undefined2 *)((int)pvVar3 + 6) = 0x14;
  uVar2 = FUN_004244d0();
  piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
  (**(code **)(*piVar4 + 0x40))();
  uStack_28._0_1_ = 4;
  pppppuStack_200 = (undefined4 *****)acStack_1e4;
  pppppuStack_1fc = (undefined4 *****)&DAT_009f3b30;
  puStack_204 = (uint *)0x7634b3;
  FUN_0047aa30();
  uVar5 = 0;
  do {
    acStack_168[uVar5] = acStack_1e4[uVar5];
    if (acStack_1e4[uVar5] == '\0') goto LAB_007634de;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x19);
  acStack_168[0] = '\0';
LAB_007634de:
  if (0xf < uStack_16c) {
    pppppuStack_1fc = (undefined4 *****)0x7634f1;
    _free(pvStack_180);
    return;
  }
  pppppuStack_200 = (undefined4 *****)auStack_14c;
  pppppuStack_1fc = (undefined4 *****)&DAT_009f3ab8;
  uStack_28._0_1_ = 5;
  puStack_204 = (uint *)0x763532;
  uStack_208 = FUN_004022a0();
  puStack_204 = (uint *)&DAT_009f3ab4;
  puStack_20c = auStack_184;
  uStack_28._0_1_ = 6;
  pppppuStack_210 = (undefined4 *****)0x76354d;
  uStack_214 = FUN_00402220();
  pppppuStack_210 = &pppppuStack_20;
  uStack_28._0_1_ = 7;
  pppppuStack_200 = (undefined4 *****)FUN_00405bd0(acStack_1e4);
  pppppuStack_1fc = (undefined4 *****)0x0;
  uStack_28._0_1_ = 8;
  puStack_204 = (uint *)0x763580;
  FUN_00401660();
  if (0xf < unaff_ESI) {
    pppppuStack_1fc = (undefined4 *****)0x763590;
    _free(pvStack_1e0);
    return;
  }
  pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
  if (0xf < uStack_16c) {
    pppppuStack_1fc = (undefined4 *****)0x7635b6;
    _free(pvStack_180);
    return;
  }
  uStack_16c = 0xf;
  uStack_170 = 0;
  pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
  uStack_28 = CONCAT31(uStack_28._1_3_,5);
  if (0xf < auStack_134[0]) {
    pppppuStack_1fc = (undefined4 *****)0x7635ed;
    _free(pvStack_148);
    return;
  }
  pppppuStack_1fc = (undefined4 *****)0x0;
  pppppuStack_200 = &local_4;
  puStack_204 = (uint *)0x763603;
  FUN_00401660();
  pppppuStack_1fc = (undefined4 *****)0x763613;
  (**(code **)(*DAT_00b5ad10 + 8))();
  pppppuStack_1fc = pppppuStack_20;
  if (pvStack_c < (void *)0x10) {
    pppppuStack_1fc = &pppppuStack_20;
  }
  puStack_204 = auStack_134;
  pppppuStack_200 = (undefined4 *****)&DAT_009f3b2c;
  uStack_208 = 0x76363d;
  FUN_0044a580();
  pppppuStack_1fc = local_4;
  if (in_stack_00000010 < 0x10) {
    pppppuStack_1fc = &local_4;
  }
  puStack_204 = (uint *)local_1e8;
  pppppuStack_200 = (undefined4 *****)&DAT_009f3b30;
  uStack_208 = 0x763667;
  FUN_0047aa30();
  pppppuStack_1fc = (undefined4 *****)auStack_134;
  pppppuStack_200 = (undefined4 *****)local_1e8;
  puStack_204 = &uStack_16c;
  uStack_208 = 0x763686;
  FUN_007650b0();
  pppppuStack_200 = (undefined4 *****)0x763692;
  pppppuStack_1fc = (undefined4 *****)uVar2;
  FUN_004d8570();
  pppppuStack_1fc = (undefined4 *****)0xf;
  pppppuStack_200 = (undefined4 *****)0x0;
  pppppuStack_210 = (undefined4 *****)((uint)pppppuStack_210 & 0xffffff00);
  FUN_00401660(&puStack_8,0,0xffffffff);
  (**(code **)(*in_ECX + 0x4c))();
  (**(code **)(*in_ECX + 0x14))();
  if ((undefined1 *)0xf < &uStack_214) {
    _free(pvStack_1e0);
    return;
  }
  pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (pvStack_c < (void *)0x10) {
    ExceptionList = pvStack_50;
    return;
  }
  _free(pppppuStack_20);
  return;
}


// ==== FUN_00763770 @ 0x00763770 ====

void FUN_00763770(int param_1,void *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  uint in_stack_0000001c;
  int local_30 [2];
  void *local_28;
  undefined1 local_24;
  undefined4 uStack_18;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995102;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = FUN_00404900(&param_2,&DAT_00b3fd8c);
  if ((cVar1 == '\x01') && (param_1 == 2)) {
    puVar2 = operator_new(0x24);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009e8aac;
      puVar2[8] = 0xf;
      puVar2[7] = 0;
      *(undefined1 *)(puVar2 + 3) = 0;
    }
    puVar2[1] = 7000;
    FUN_00401660(&param_2,0,0xffffffff);
    FUN_00797a20(puVar2);
  }
  local_30[1] = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(&param_2,0,0xffffffff);
  local_30[0] = param_1;
  (**(code **)(*DAT_00b5ad10 + 8))(local_30);
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ee8cc;
  }
  FUN_00797a20(puVar2);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_14 = 0xf;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_007638b0 @ 0x007638b0 ====

void FUN_007638b0(int *param_1)

{
  void **ppvVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  int *unaff_EBP;
  undefined4 *puVar7;
  undefined4 uStack_1fc;
  undefined1 *puStack_1f8;
  undefined4 uStack_1f4;
  undefined *puStack_1f0;
  uint *puStack_1ec;
  char *pcStack_1e8;
  undefined1 auStack_1bc [4];
  void *pvStack_1b8;
  undefined1 *puStack_1a8;
  uint uStack_1a4;
  undefined1 *puStack_1a0;
  undefined4 uStack_19c;
  void *pvStack_194;
  undefined4 uStack_190;
  uint uStack_18c;
  undefined4 uStack_184;
  uint uStack_180;
  undefined1 auStack_17c [4];
  void *pvStack_178;
  int iStack_168;
  uint uStack_164;
  void *pvStack_15c;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  void *pvStack_148;
  undefined4 uStack_138;
  uint uStack_134;
  undefined1 auStack_130 [4];
  void *pvStack_12c;
  undefined4 uStack_11c;
  uint uStack_118;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995159;
  puVar6 = *(undefined4 **)(in_ECX + 0x30);
  ppvVar1 = &pvStack_c;
  pvStack_c = ExceptionList;
  for (puVar7 = *(undefined4 **)(in_ECX + 0x2c); ExceptionList = ppvVar1, puVar7 != puVar6;
      puVar7 = puVar7 + 1) {
    cVar2 = (**(code **)(*(int *)*puVar7 + 4))();
    if (cVar2 == '\x01') {
      ExceptionList = pvStack_c;
      return;
    }
    ppvVar1 = ExceptionList;
  }
  cVar2 = FUN_00760990();
  if (cVar2 == '\0') {
    uStack_1a4 = 0xf;
    puStack_1a8 = (undefined1 *)0x0;
    pvStack_1b8 = (void *)((uint)pvStack_1b8 & 0xffffff00);
    iVar5 = *param_1;
    uStack_4 = 0;
    pcStack_1e8 = (char *)0x763946;
    FUN_00401660();
    puStack_1a0 = (undefined1 *)&uStack_1f4;
    puStack_1f8 = (undefined1 *)0xffffffff;
    uStack_1fc = 0;
    puStack_1f0 = (undefined *)((uint)puStack_1f0 & 0xffffff00);
    FUN_00401660(auStack_1bc);
    puStack_1f8 = auStack_17c;
    uStack_1fc = 0x763974;
    (**(code **)*DAT_00b5b18c)();
    uStack_4._0_1_ = 1;
    if (iStack_168 == 0) {
      if (iVar5 == 0) {
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar4 = operator_new(0x400);
        *(undefined4 *)((int)pvVar4 + 8) = uVar3;
        *(undefined4 *)((int)pvVar4 + 0xc) = 0x50d0003;
        *(undefined2 *)((int)pvVar4 + 6) = 0x18;
        iVar5 = FUN_004244d0();
        uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
        *(undefined4 *)(iVar5 + 0x10) = uVar3;
        pcStack_1e8 = (char *)0x763c2e;
        FUN_0044a580();
        FUN_00764f90();
        FUN_004d8570();
        uStack_180 = 0xf;
        uStack_184 = 0;
        pvStack_194 = (void *)((uint)pvStack_194 & 0xffffff00);
        uStack_4._0_1_ = 6;
        uStack_19c = (**(code **)(*DAT_00b5a97c + 0xc))();
        pcStack_1e8 = (char *)0x763c80;
        FUN_00401660();
        puVar6 = operator_new(0x24);
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          *puVar6 = &PTR_FUN_009f397c;
          puVar6[8] = 0xf;
          puVar6[7] = 0;
          *(undefined1 *)(puVar6 + 3) = 0;
        }
        puVar6[1] = uStack_19c;
        pcStack_1e8 = (char *)0x763cba;
        FUN_00401660();
        FUN_00797a20();
        if (0xf < uStack_180) {
          _free(pvStack_194);
          return;
        }
      }
      else if (iVar5 == 1) {
        FUN_00762f60();
      }
      else if (iVar5 == 4) {
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar4 = operator_new(0x400);
        *(undefined4 *)((int)pvVar4 + 8) = uVar3;
        *(undefined4 *)((int)pvVar4 + 0xc) = 0x511000c;
        *(undefined2 *)((int)pvVar4 + 6) = 0x18;
        iVar5 = FUN_004244d0();
        uVar3 = (**(code **)(*DAT_00b5a7b4 + 0x54))();
        *(undefined4 *)(iVar5 + 0x10) = uVar3;
        pcStack_1e8 = (char *)0x763b96;
        FUN_0044a580();
        FUN_00764f90();
        FUN_004d8570();
      }
    }
    else {
      puStack_1ec = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
      pcStack_1e8 = (char *)0x0;
      uStack_150 = 0xf;
      uStack_154 = 0;
      uStack_164 = uStack_164 & 0xffffff00;
      puStack_1f0 = (undefined *)0x7639bc;
      FUN_00401660();
      pcStack_1e8 = s__SLANG__009f3a98;
      pvStack_c._0_1_ = 2;
      uStack_134 = 0xf;
      uStack_138 = 0;
      pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
      puStack_1ec = (uint *)0x7639ec;
      FUN_00401740();
      puStack_1ec = &uStack_1a4;
      pcStack_1e8 = &DAT_009f3a94;
      pvStack_c._0_1_ = 3;
      puStack_1f0 = (undefined *)0x763a08;
      uStack_1f4 = FUN_004022a0();
      puStack_1f0 = &DAT_009f3a90;
      puStack_1f8 = auStack_130;
      pvStack_c._0_1_ = 4;
      uStack_1fc = 0x763a23;
      uStack_1fc = FUN_00402220();
      pvStack_c._0_1_ = 5;
      FUN_00404440(&iStack_168,&uStack_14c);
      if (0xf < uStack_118) {
        pcStack_1e8 = (char *)0x763a5f;
        _free(pvStack_12c);
        return;
      }
      uStack_118 = 0xf;
      uStack_11c = 0;
      pvStack_12c = (void *)((uint)pvStack_12c & 0xffffff00);
      if (0xf < uStack_18c) {
        pcStack_1e8 = (char *)0x763a87;
        _free(puStack_1a0);
        return;
      }
      uStack_18c = 0xf;
      uStack_190 = 0;
      puStack_1a0 = (undefined1 *)((uint)puStack_1a0 & 0xffffff00);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
      if (0xf < uStack_134) {
        pcStack_1e8 = (char *)0x763ab4;
        _free(pvStack_148);
        return;
      }
      puStack_1a8 = (undefined1 *)&uStack_1fc;
      pcStack_1e8 = (char *)0x0;
      puStack_1f8 = (undefined1 *)((uint)puStack_1f8 & 0xffffff00);
      FUN_00401660(&iStack_168,0,0xffffffff);
      (**(code **)(*unaff_EBP + 0x28))(2);
      if ((void *)0xf < pvStack_148) {
        _free(pvStack_15c);
        return;
      }
      pvStack_148 = (void *)0xf;
      uStack_14c = 0;
      pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
    }
    if (0xf < uStack_164) {
      _free(pvStack_178);
      return;
    }
    uStack_164 = 0xf;
    iStack_168 = 0;
    pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
    if (0xf < uStack_1a4) {
      _free(pvStack_1b8);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00763d30 @ 0x00763d30 ====

void FUN_00763d30(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int *piVar3;
  uint unaff_EBX;
  int *piVar4;
  void *unaff_ESI;
  uint unaff_EDI;
  undefined1 auStack_7e [6];
  undefined1 *puStack_74;
  char *pcStack_70;
  uint *puStack_68;
  undefined4 uStack_64;
  void *_Memory;
  undefined4 local_4c;
  uint local_44;
  void *local_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  uint local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009951fa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f3c84;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  local_4 = 2;
  uVar2 = FUN_00588880();
  in_ECX[0x10] = uVar2;
  in_ECX[0x11] = 0;
  local_4._0_1_ = 3;
  uVar2 = FUN_00588880();
  in_ECX[0x14] = uVar2;
  in_ECX[0x15] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x1f] = 0xf;
  in_ECX[0x1e] = 0;
  *(undefined1 *)(in_ECX + 0x1a) = 0;
  local_4._0_1_ = 5;
  if (DAT_00b5ad10 == 0) {
    uStack_64 = s_IChat__IREFERENCE______NULL_009f39d4;
    local_2c = 0xf;
    local_30 = (void *)0x0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    puStack_68 = (uint *)0x763dd6;
    FUN_00401740();
    local_4._0_1_ = 6;
    uStack_64 = (char *)0x763de5;
    FUN_00406880();
    local_4 = CONCAT31(local_4._1_3_,5);
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uStack_64 = (char *)0x763dfe;
    _free(local_40);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad0c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ad0c = in_ECX;
  }
  uStack_64 = &DAT_009f39f0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  puStack_68 = (uint *)0x763e32;
  FUN_00401740();
  uStack_64 = s_refresh_chatwnd_009f39f4;
  local_4._0_1_ = 7;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  puStack_68 = (uint *)0x763e52;
  FUN_00401740();
  uStack_64 = (void *)0x0;
  puStack_68 = &local_44;
  local_4 = CONCAT31(local_4._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_38) {
    pcStack_70 = (char *)0x763e7e;
    _free(in_ECX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_4c = (uint)in_ECX & 0xffffff00;
  local_10._0_1_ = 5;
  if (0xf < uStack_1c) {
    pcStack_70 = (char *)0x763ea3;
    _free(local_30);
    return;
  }
  pcStack_70 = &DAT_009f3a04;
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  puStack_74 = (undefined1 *)0x763ec1;
  FUN_00401740();
  pcStack_70 = s_show_chatwnd_009f3a08;
  local_10._0_1_ = 9;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  puStack_74 = (undefined1 *)0x763ee2;
  FUN_00401740();
  pcStack_70 = (void *)0x0;
  puStack_74 = auStack_7e + 0x2e;
  local_10 = CONCAT31(local_10._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    _free(unaff_ESI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 5;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740();
  uStack_1c._0_1_ = 0xb;
  local_44 = 0xf;
  FUN_00401740();
  uStack_1c = CONCAT31(uStack_1c._1_3_,0xc);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < unaff_EBX) {
    _free(uStack_64);
    return;
  }
  uStack_64 = (char *)((uint)uStack_64 & 0xffffff00);
  local_28._0_1_ = 5;
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  FUN_00401740(&DAT_009f3a25);
  local_28._0_1_ = 0xd;
  uStack_64 = (char *)((uint)uStack_64 & 0xffffff00);
  FUN_00401740(s_show_gmtool_009f3a28);
  local_28 = CONCAT31(local_28._1_3_,0xe);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_68,0);
  if (0xf < unaff_EDI) {
    _free(pcStack_70);
    return;
  }
  pcStack_70 = (char *)((uint)pcStack_70 & 0xffffff00);
  uStack_34._0_1_ = 5;
  if (0xf < local_40) {
    _free((void *)0x0);
    return;
  }
  local_40 = (void *)0xf;
  local_44 = 0;
  FUN_00401740(&DAT_009f3a34,0);
  uStack_34._0_1_ = 0xf;
  _Memory = (void *)0x0;
  pcStack_70 = (char *)((uint)pcStack_70 & 0xffffff00);
  FUN_00401740(s_hide_gmtool_009f3a38,0xb);
  uStack_34 = CONCAT31(uStack_34._1_3_,0x10);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_74,0,auStack_7e + 0x26);
  if ((uint *)0xf < puStack_68) {
    _free((void *)0x0);
    return;
  }
  puStack_68 = (uint *)0xf;
  local_40 = (void *)CONCAT31(local_40._1_3_,5);
  if (0xf < local_4c) {
    _free(_Memory);
    return;
  }
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x16] = 0x7f010101;
  piVar3 = in_ECX + 2;
  if ((uint)in_ECX[7] < 0x10) {
    piVar4 = piVar3;
  }
  else {
    piVar4 = (int *)*piVar3;
  }
  if (0xf < (uint)in_ECX[7]) {
    piVar3 = (int *)*piVar3;
  }
  FUN_004bdb30(auStack_7e + -6,piVar3,in_ECX[6] + (int)piVar4);
  in_ECX[0xe] = 0;
  FUN_0059c2f0();
  in_ECX[0x12] = 0;
  FUN_0059c2f0();
  piVar3 = in_ECX + 0x1a;
  if ((uint)in_ECX[0x1f] < 0x10) {
    piVar4 = piVar3;
  }
  else {
    piVar4 = (int *)*piVar3;
  }
  if (0xf < (uint)in_ECX[0x1f]) {
    piVar3 = (int *)*piVar3;
  }
  FUN_004bdb30(auStack_7e + -6,piVar3,in_ECX[0x1e] + (int)piVar4);
  ExceptionList = (void *)0x0;
  return;
}


// ==== FUN_00764180 @ 0x00764180 ====

void FUN_00764180(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined4 local_2c;
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
  
  puStack_8 = &LAB_0099526b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f3c84;
  local_4 = 5;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  local_2c = in_ECX;
  FUN_00401740(s_refresh_chatwnd_009f3a44,0xf);
  local_4 = CONCAT31(local_4._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 5;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_show_chatwnd_009f3a54,0xc);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c._0_1_ = 5;
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_hide_chatwnd_009f3a64,0xc);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10._0_1_ = 5;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740(s_show_gmtool_009f3a74,0xb);
  local_10 = CONCAT31(local_10._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  local_14._0_1_ = 5;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  FUN_00401740(s_hide_gmtool_009f3a80,0xb);
  local_14 = CONCAT31(local_14._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x38);
  uStack_18 = CONCAT31(uStack_18._1_3_,5);
  if (0xf < local_24) {
    _free(unaff_ESI);
    return;
  }
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
    in_ECX[8] = 0;
  }
  DAT_00b5ad0c = 0;
  if ((uint)in_ECX[0x1f] < 0x10) {
    in_ECX[0x1f] = 0xf;
    in_ECX[0x1e] = 0;
    *(undefined1 *)(in_ECX + 0x1a) = 0;
    FUN_0059c2f0();
    _free((void *)in_ECX[0x14]);
    return;
  }
  _free((void *)in_ECX[0x1a]);
  return;
}


// ==== FUN_007643e0 @ 0x007643e0 ====

void FUN_007643e0(undefined1 param_1,void *param_2)

{
  int *_Memory;
  int iVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099527d;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  cVar2 = FUN_00762a10();
  if (cVar2 != '\x01') {
    if ((9 < *(uint *)(in_ECX + 0x44)) &&
       (_Memory = (int *)**(int **)(in_ECX + 0x40), _Memory != *(int **)(in_ECX + 0x40))) {
      *(int *)_Memory[1] = *_Memory;
      *(int *)(*_Memory + 4) = _Memory[1];
      if ((uint)_Memory[8] < 0x10) {
        _Memory[8] = 0xf;
        _Memory[7] = 0;
        *(undefined1 *)(_Memory + 3) = 0;
        _free(_Memory);
        return;
      }
      _free((void *)_Memory[3]);
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x40);
    iVar3 = FUN_00588950();
    FUN_005889e0();
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_007644d0 @ 0x007644d0 ====

void FUN_007644d0(undefined1 param_1,undefined4 *param_2)

{
  int *_Memory;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099528f;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (*(int *)(in_ECX + 0x54) != 0) {
    puVar1 = param_2;
    if (in_stack_0000001c < 0x10) {
      puVar1 = &param_2;
    }
    ExceptionList = &local_c;
    iVar2 = FUN_00403620(0,*(undefined4 *)(**(int **)(in_ECX + 0x50) + 0x1c),puVar1,
                         in_stack_00000018);
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 0x48) = 0xffffffff;
      goto joined_r0x00764534;
    }
  }
  iVar2 = **(int **)(in_ECX + 0x50);
  iVar3 = FUN_00588950(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  FUN_005889e0(1);
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  if ((9 < *(uint *)(in_ECX + 0x54)) &&
     (_Memory = (int *)(*(int **)(in_ECX + 0x50))[1], _Memory != *(int **)(in_ECX + 0x50))) {
    *(int *)_Memory[1] = *_Memory;
    *(int *)(*_Memory + 4) = _Memory[1];
    if ((uint)_Memory[8] < 0x10) {
      _Memory[8] = 0xf;
      _Memory[7] = 0;
      *(undefined1 *)(_Memory + 3) = 0;
      _free(_Memory);
      return;
    }
    _free((void *)_Memory[3]);
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0xffffffff;
joined_r0x00764534:
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_007645f0 @ 0x007645f0 ====

void FUN_007645f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x2c);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x34) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x30) - iVar1 >> 2)))
  {
    FUN_00765320(*(undefined4 *)(in_ECX + 0x30),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x30);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x30) = puVar2 + 1;
  return;
}


// ==== FUN_00764640 @ 0x00764640 ====

void FUN_00764640(int param_1,undefined1 param_2,void *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint in_stack_00000020;
  undefined1 local_119;
  int local_118;
  undefined1 local_114 [4];
  void *local_110;
  int local_10c;
  undefined4 local_108;
  undefined1 local_104 [4];
  void *local_100;
  int local_fc;
  undefined4 local_f8;
  undefined1 local_f4 [4];
  void *local_f0;
  int local_ec;
  undefined4 local_e8;
  uint local_e4;
  undefined1 local_e0 [4];
  void *local_dc;
  undefined4 local_cc;
  uint local_c8;
  undefined1 local_c4 [4];
  void *local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined1 local_b4 [4];
  void *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_a4 [4];
  void *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 local_94 [4];
  void *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84 [3];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  undefined1 local_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 local_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995327;
  pvStack_c = ExceptionList;
  local_c0 = (void *)0x0;
  local_bc = 0;
  local_b8 = 0;
  local_4 = 1;
  local_c8 = 0xf;
  local_cc = 0;
  local_dc = (void *)((uint)local_dc & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(&DAT_009f3abc,1);
  local_4._0_1_ = 2;
  FUN_00405300(&param_2,local_e0,local_c4);
  local_4._0_1_ = 1;
  if (0xf < local_c8) {
    _free(local_dc);
    return;
  }
  local_e4 = 0;
  do {
    local_4._0_1_ = 1;
    if (local_c0 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (local_bc - (int)local_c0) / 0x1c;
    }
    uVar8 = local_e4 & 0xffff;
    if (uVar2 <= uVar8) {
      if (local_c0 != (void *)0x0) {
        FUN_00405de0(local_c0,local_bc,local_c4,local_118);
        _free(local_c0);
        return;
      }
      local_c0 = (void *)0x0;
      local_bc = 0;
      local_b8 = 0;
      if (in_stack_00000020 < 0x10) {
        ExceptionList = pvStack_c;
        return;
      }
      _free(param_3);
      return;
    }
    if ((local_c0 == (void *)0x0) || ((uint)((local_bc - (int)local_c0) / 0x1c) <= uVar8)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    local_c8 = 0xf;
    local_cc = 0;
    local_dc = (void *)((uint)local_dc & 0xffffff00);
    FUN_00401660((void *)((int)local_c0 + uVar8 * 0x1c),0,0xffffffff);
    local_4._0_1_ = 3;
    iVar3 = FUN_00405850(s_<effectsound>_009f3ac0,0,0xd);
    if (iVar3 == 0) {
      FUN_00405b90(local_60,0xd,0xffffffff);
      local_b0 = (void *)0x0;
      local_ac = 0;
      local_a8 = 0;
      local_4._0_1_ = 5;
      local_119 = 0x2c;
      FUN_00417f70(0,1,&local_119);
      local_110 = (void *)0x0;
      local_10c = 0;
      local_108 = 0;
      local_4 = CONCAT31(local_4._1_3_,6);
      FUN_00404b60(local_60,local_114,local_b4);
      if (local_110 == (void *)0x0) {
LAB_00764ec4:
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_118 = (local_10c - (int)local_110) / 0x1c;
      if (local_118 == 0) goto LAB_00764ec4;
      local_118 = thunk_FUN_00796fb0(local_110);
      if ((local_110 == (void *)0x0) || ((uint)((local_10c - (int)local_110) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar4 = thunk_FUN_00796fb0((int)local_110 + 0x1c);
      if ((local_110 == (void *)0x0) || ((uint)((local_10c - (int)local_110) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar5 = thunk_FUN_00796fb0((int)local_110 + 0x38);
      if ((local_110 == (void *)0x0) || ((uint)((local_10c - (int)local_110) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar6 = thunk_FUN_00796fb0((int)local_110 + 0x54);
      FUN_004dd240(local_118,uVar4,uVar5,uVar6,0);
      if (local_110 != (void *)0x0) {
        FUN_00405de0(local_110,local_10c,local_114,local_118);
        _free(local_110);
        return;
      }
      local_110 = (void *)0x0;
      local_10c = 0;
      local_108 = 0;
      if (local_b0 != (void *)0x0) {
        _free(local_b0);
        return;
      }
      local_b0 = (void *)0x0;
      local_ac = 0;
      local_a8 = 0;
      if (0xf < uStack_48) {
        _free(pvStack_5c);
        return;
      }
      uStack_48 = 0xf;
      uStack_4c = 0;
      pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    }
    else {
      iVar3 = FUN_00405850(s_<sound>_009f3ad0,0,7);
      if (iVar3 == 0) {
        FUN_00405b90(local_28,7,0xffffffff);
        local_a0 = (void *)0x0;
        local_9c = 0;
        local_98 = 0;
        local_4._0_1_ = 8;
        local_119 = 0x2c;
        FUN_00417f70(0,1,&local_119);
        local_f0 = (void *)0x0;
        local_ec = 0;
        local_e8 = 0;
        local_4 = CONCAT31(local_4._1_3_,9);
        FUN_00404b60(local_28,local_f4,local_a4);
        if (local_f0 == (void *)0x0) {
LAB_00764ee8:
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_118 = (local_ec - (int)local_f0) / 0x1c;
        if (local_118 == 0) goto LAB_00764ee8;
        uVar4 = thunk_FUN_00796fb0(local_f0);
        if ((local_f0 == (void *)0x0) || ((uint)((local_ec - (int)local_f0) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar5 = thunk_FUN_00796fb0((int)local_f0 + 0x1c);
        FUN_004de2a0(uVar4,uVar5);
        if (local_f0 != (void *)0x0) {
          FUN_00405de0(local_f0,local_ec,local_f4,local_118);
          _free(local_f0);
          return;
        }
        local_f0 = (void *)0x0;
        local_ec = 0;
        local_e8 = 0;
        if (local_a0 != (void *)0x0) {
          _free(local_a0);
          return;
        }
        local_a0 = (void *)0x0;
        local_9c = 0;
        local_98 = 0;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      }
      else {
        iVar3 = FUN_00405850(s_<effectui>_009f3ad8,0,10);
        if (iVar3 == 0) {
          FUN_00405b90(local_44,10,0xffffffff);
          local_90 = (void *)0x0;
          local_8c = 0;
          local_88 = 0;
          local_4._0_1_ = 0xb;
          local_119 = 0x2c;
          FUN_00417f70(0,1,&local_119);
          local_100 = (void *)0x0;
          local_fc = 0;
          local_f8 = 0;
          local_4 = CONCAT31(local_4._1_3_,0xc);
          FUN_00404b60(local_44,local_104,local_94);
          if (local_100 == (void *)0x0) {
LAB_00764efa:
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          local_118 = (local_fc - (int)local_100) / 0x1c;
          if (local_118 == 0) goto LAB_00764efa;
          uVar2 = thunk_FUN_00796fb0(local_100);
          if ((local_100 == (void *)0x0) || ((uint)((local_fc - (int)local_100) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          local_118 = thunk_FUN_00796fb0((int)local_100 + 0x1c);
          if ((local_100 == (void *)0x0) || ((uint)((local_fc - (int)local_100) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar4 = thunk_FUN_00796fb0((int)local_100 + 0x38);
          if ((local_100 == (void *)0x0) || ((uint)((local_fc - (int)local_100) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar5 = thunk_FUN_00796fb0((int)local_100 + 0x54);
          puVar7 = operator_new(0x14);
          if (puVar7 == (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            *puVar7 = &PTR_FUN_009f3c34;
          }
          puVar7[1] = uVar2 | 0x80000;
          puVar7[2] = local_118;
          puVar7[3] = uVar4;
          puVar7[4] = uVar5;
          FUN_00797a20(puVar7);
          if (local_100 != (void *)0x0) {
            FUN_00405de0(local_100,local_fc,local_104,local_118);
            _free(local_100);
            return;
          }
          local_100 = (void *)0x0;
          local_fc = 0;
          local_f8 = 0;
          if (local_90 != (void *)0x0) {
            _free(local_90);
            return;
          }
          local_90 = (void *)0x0;
          local_8c = 0;
          local_88 = 0;
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return;
          }
          uStack_2c = 0xf;
          uStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
        }
        else {
          cVar1 = FUN_00404900(local_e0,&DAT_00b3fd8c);
          if ((cVar1 == '\x01') && (param_1 == 2)) {
            puVar7 = operator_new(0x24);
            if (puVar7 == (undefined4 *)0x0) {
              puVar7 = (undefined4 *)0x0;
            }
            else {
              *puVar7 = &PTR_FUN_009e8aac;
              puVar7[8] = 0xf;
              puVar7[7] = 0;
              *(undefined1 *)(puVar7 + 3) = 0;
            }
            puVar7[1] = 7000;
            FUN_00401660(local_e0,0,0xffffffff);
            FUN_00797a20(puVar7);
          }
          local_84[1] = 0;
          local_64 = 0xf;
          local_68 = 0;
          local_78 = (void *)((uint)local_78 & 0xffffff00);
          local_4 = CONCAT31(local_4._1_3_,0xd);
          FUN_00401660(local_e0,0,0xffffffff);
          local_84[0] = param_1;
          (**(code **)(*DAT_00b5ad10 + 8))(local_84);
          puVar7 = operator_new(4);
          if (puVar7 == (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            *puVar7 = &PTR_FUN_009ee8cc;
          }
          FUN_00797a20(puVar7);
          if (0xf < local_64) {
            _free(local_78);
            return;
          }
          local_64 = 0xf;
          local_68 = 0;
          local_78 = (void *)((uint)local_78 & 0xffffff00);
        }
      }
    }
    local_4._0_1_ = 1;
    if (0xf < local_c8) {
      _free(local_dc);
      return;
    }
    local_e4 = local_e4 + 1;
    local_c8 = 0xf;
    local_cc = 0;
    local_dc = (void *)((uint)local_dc & 0xffffff00);
  } while( true );
}


// ==== FUN_00764f90 @ 0x00764f90 ====

void FUN_00764f90(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 0x18);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_00764fba;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x100);
  *pcVar1 = '\0';
LAB_00764fba:
  uVar4 = 0;
  do {
    if (pcVar1[uVar4] == '\0') goto LAB_00764fd2;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  uVar4 = 0;
LAB_00764fd2:
  *(short *)(in_ECX + 0x14) = (short)uVar4 + 1;
  *(short *)(in_ECX + 6) = (short)uVar4 + 0x19;
  return;
}


// ==== FUN_00764ff0 @ 0x00764ff0 ====

uint FUN_00764ff0(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int in_ECX;
  byte bVar5;
  
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_1) == '\0') {
      bVar5 = (byte)uVar3;
      goto LAB_00765008;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  bVar5 = 0;
LAB_00765008:
  *(byte *)(in_ECX + 0x10) = bVar5;
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_2) == '\0') goto LAB_00765023;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  uVar3 = 0;
LAB_00765023:
  *(char *)(in_ECX + 0x11) = (char)uVar3;
  uVar3 = (uVar3 & 0xff) + (uint)bVar5;
  if (0xfe < uVar3) {
    return uVar3 & 0xffffff00;
  }
  uVar3 = 0;
  puVar1 = (undefined1 *)(in_ECX + 0x14);
  if (bVar5 != 0) {
    puVar4 = puVar1;
    do {
      *puVar4 = puVar4[param_1 - (int)puVar1];
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < *(byte *)(in_ECX + 0x10));
  }
  uVar3 = 0;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    do {
      puVar1[*(byte *)(in_ECX + 0x10) + uVar3] = *(undefined1 *)(uVar3 + param_2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(byte *)(in_ECX + 0x11));
  }
  iVar2 = CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(in_ECX + 0x10)) + 0x14 +
          (uint)*(byte *)(in_ECX + 0x11);
  *(short *)(in_ECX + 6) = (short)iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== FUN_007650b0 @ 0x007650b0 ====

undefined4 FUN_007650b0(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int in_ECX;
  byte bVar5;
  
  iVar2 = param_1;
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_1) == '\0') {
      param_1._0_1_ = (byte)uVar3;
      goto LAB_007650d6;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  param_1._0_1_ = 0;
LAB_007650d6:
  *(byte *)(in_ECX + 0x10) = (byte)param_1;
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_2) == '\0') {
      bVar5 = (byte)uVar3;
      goto LAB_007650f4;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  bVar5 = 0;
LAB_007650f4:
  *(byte *)(in_ECX + 0x11) = bVar5;
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_3) == '\0') goto LAB_00765117;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  uVar3 = 0;
LAB_00765117:
  *(char *)(in_ECX + 0x12) = (char)uVar3;
  if (0x12e < (uint)bVar5 + (uVar3 & 0xff) + (uint)(byte)param_1) {
    return 0;
  }
  uVar3 = 0;
  puVar1 = (undefined1 *)(in_ECX + 0x14);
  if ((byte)param_1 != 0) {
    puVar4 = puVar1;
    do {
      *puVar4 = puVar4[iVar2 - (int)puVar1];
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < *(byte *)(in_ECX + 0x10));
  }
  uVar3 = 0;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    do {
      puVar1[*(byte *)(in_ECX + 0x10) + uVar3] = *(undefined1 *)(uVar3 + param_2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(byte *)(in_ECX + 0x11));
  }
  uVar3 = 0;
  if (*(char *)(in_ECX + 0x12) != '\0') {
    do {
      puVar1[(uint)*(byte *)(in_ECX + 0x11) + *(byte *)(in_ECX + 0x10) + uVar3] =
           *(undefined1 *)(uVar3 + param_3);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(byte *)(in_ECX + 0x12));
  }
  iVar2 = CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(in_ECX + 0x10)) +
          (uint)*(byte *)(in_ECX + 0x12) + 0x14 + (uint)*(byte *)(in_ECX + 0x11);
  *(short *)(in_ECX + 6) = (short)iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== FUN_007651e0 @ 0x007651e0 ====

void FUN_007651e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3c70;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00765240 @ 0x00765240 ====

undefined4 FUN_00765240(void)

{
  return 0x70040007;
}


// ==== FUN_00765250 @ 0x00765250 ====

void FUN_00765250(byte param_1)

{
  void *in_ECX;
  
  FUN_00765270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765270 @ 0x00765270 ====

void FUN_00765270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3c70;
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


// ==== FUN_007652b0 @ 0x007652b0 ====

void FUN_007652b0(void)

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
  puStack_8 = &LAB_00995368;
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


// ==== FUN_00765320 @ 0x00765320 ====

void FUN_00765320(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_007652b0();
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


// ==== FUN_00765500 @ 0x00765500 ====

undefined1 FUN_00765500(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x24);
}


// ==== FUN_00765510 @ 0x00765510 ====

int FUN_00765510(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 4,0,0xffffffff);
  return param_1;
}


// ==== FUN_00765540 @ 0x00765540 ====

void FUN_00765540(byte param_1)

{
  void *in_ECX;
  
  FUN_00764180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765560 @ 0x00765560 ====

void FUN_00765560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3cfc;
  return;
}


// ==== FUN_00765570 @ 0x00765570 ====

void FUN_00765570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3cfc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765590 @ 0x00765590 ====

undefined4 FUN_00765590(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_007655a0 @ 0x007655a0 ====

void FUN_007655a0(int param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = (**(code **)(*in_ECX + 0xc))();
    *(undefined4 *)(param_1 + 4) = uVar1;
  }
  (**(code **)(*(int *)in_ECX[1] + 4))(param_1);
  return;
}


// ==== FUN_007655d0 @ 0x007655d0 ====

int FUN_007655d0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == -1) {
    *(undefined4 *)(in_ECX + 8) = 1;
    return -1;
  }
  *(int *)(in_ECX + 8) = iVar1 + 1;
  return iVar1;
}


// ==== FUN_007655f0 @ 0x007655f0 ====

void FUN_007655f0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995393;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3d10;
  in_ECX[2] = 1;
  pvVar1 = operator_new(0x4c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00792230();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad10 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ad10 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00765690 @ 0x00765690 ====

void FUN_00765690(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009953a5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3d10;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5ad10 = 0;
  *in_ECX = &PTR_FUN_009f3cfc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007656f0 @ 0x007656f0 ====

void FUN_007656f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00765690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765710 @ 0x00765710 ====

void FUN_00765710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3d74;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765740 @ 0x00765740 ====

void FUN_00765740(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3d80;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aebc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aebc = in_ECX;
  return;
}


// ==== FUN_007657b0 @ 0x007657b0 ====

void FUN_007657b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aebc = 0;
  *in_ECX = &PTR_FUN_009f3d74;
  return;
}


// ==== FUN_007657d0 @ 0x007657d0 ====

void FUN_007657d0(void)

{
  int iVar1;
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
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009953c0;
  pvStack_c = ExceptionList;
  uStack_50 = 3;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    uStack_58 = CONCAT13((char)((uint)DAT_00b5a980 >> 0x18),*(undefined3 *)(unaff_retaddr + 0x14));
    uStack_5c = 0x76582d;
    uStack_5c = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_60 = 0x765833;
    FUN_00827440();
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00511760();
    }
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(unaff_retaddr + 0x18);
    *(undefined2 *)(iVar1 + 8) = *(undefined2 *)(unaff_retaddr + 0x1c);
    *(undefined1 *)(iVar1 + 10) = 1;
    uStack_58 = 0x76586c;
    FUN_00797a20();
    ExceptionList = pvStack_10;
    return;
  case 1:
    uStack_58 = 0;
    uStack_5c = 0x7658a9;
    uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0x7658b3;
    FUN_00765c50();
    puStack_8 = auStack_74;
    pvStack_10 = (void *)0x0;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
  }
  uStack_58 = 9;
  uStack_5c = 0x76590a;
  uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_5c = 0xffffffff;
  uStack_60 = 0;
  uStack_68 = 0x76592e;
  FUN_00401660();
  puStack_8 = auStack_74;
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_10 = (void *)0x1;
  uStack_70 = 0;
  FUN_00401660(&uStack_50,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_30 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  uStack_58 = 0x765979;
  _free(pvStack_44);
  return;
}


// ==== FUN_007659b0 @ 0x007659b0 ====

void FUN_007659b0(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int *piVar3;
  uint unaff_EBX;
  undefined1 auStack_c4 [4];
  undefined1 uStack_c0;
  void *pvStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined1 auStack_9c [4];
  undefined1 uStack_98;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  char *pcStack_7c;
  undefined1 auStack_62 [2];
  void *pvStack_60;
  undefined1 auStack_5c [12];
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 *puStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009953e2;
  pvStack_c = ExceptionList;
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  piVar3 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
  if (piVar3 == (int *)0x0) {
    pcStack_7c = s_pDialog____NULL_009f3d5c;
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    uStack_80 = 0x765a06;
    FUN_00401740();
    puStack_4 = (undefined1 *)0x0;
    pcStack_7c = (char *)0x765a14;
    FUN_00406880();
    if (uStack_30 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    pcStack_7c = (char *)0x765a28;
    _free(pvStack_44);
    return;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  pcStack_7c = (void *)0x9;
  puStack_4 = (undefined1 *)0x1;
  uStack_80 = 0x765a52;
  uStack_88 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_80 = 0xffffffff;
  uStack_84 = 0;
  uStack_8c = 0x765a5f;
  FUN_00401660();
  uStack_84 = 0x765a65;
  uStack_80 = uVar1;
  uStack_80 = FUN_007927e0();
  puStack_4 = auStack_9c;
  uStack_a0 = 0xffffffff;
  uStack_a4 = 0;
  puStack_a8 = auStack_62 + -10;
  uStack_84 = 0xf;
  uStack_88 = 0;
  uStack_98 = 0;
  uStack_ac = 0x765a8b;
  FUN_00401660();
  uStack_a0 = 0x765a92;
  (**(code **)(*piVar3 + 4))();
  uStack_3c = 0xf;
  uStack_40 = 0;
  uStack_50 = uStack_50 & 0xffffff00;
  uStack_a0 = 0xc8006a;
  uStack_a4 = 9;
  puStack_2c = (undefined1 *)CONCAT31(puStack_2c._1_3_,2);
  puStack_a8 = (undefined1 *)0x765ab5;
  uStack_b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_a8 = (undefined1 *)0xffffffff;
  uStack_ac = 0;
  pvStack_b4 = (void *)0x765ac2;
  FUN_00401660();
  puStack_2c = auStack_c4;
  uStack_40 = 0;
  uStack_ac = 0xf;
  uStack_b0 = 0;
  uStack_c0 = 0;
  FUN_00401660(auStack_5c,0,0xffffffff);
  puStack_a8 = (undefined1 *)uStack_40;
  (**(code **)(*piVar3 + 8))();
  (**(code **)(*DAT_00b5aee8 + 0x10))();
  (**(code **)(*DAT_00b5acd4 + 4))(3);
  if (0xf < unaff_EBX) {
    _free(pcStack_7c);
    return;
  }
  pcStack_7c = (char *)((uint)pcStack_7c & 0xffffff00);
  if (uStack_a0 < 0x10) {
    ExceptionList = pvStack_60;
    return;
  }
  _free(pvStack_b4);
  return;
}


// ==== FUN_00765b70 @ 0x00765b70 ====

undefined4 FUN_00765b70(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5300000) {
    FUN_007659b0(*(undefined4 *)(param_1 + 0xc));
  }
  else {
    if (iVar1 == 0x5300006) {
      FUN_007657d0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (iVar1 != 0x530001a) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0xc);
    (**(code **)(*DAT_00b5af2c + 8))(4);
    if (*(int *)(iVar1 + 0x10) == 0) {
      (**(code **)(*DAT_00b5aee8 + 0x14))();
      (**(code **)(*DAT_00b5acd4 + 4))(0);
      return 1;
    }
  }
  return 1;
}


// ==== FUN_00765c00 @ 0x00765c00 ====

undefined4 FUN_00765c00(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00765b70(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00765c30 @ 0x00765c30 ====

void FUN_00765c30(byte param_1)

{
  void *in_ECX;
  
  FUN_007657b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765c50 @ 0x00765c50 ====

void FUN_00765c50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_00765c80 @ 0x00765c80 ====

void FUN_00765c80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3ddc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00765cb0 @ 0x00765cb0 ====

void FUN_00765cb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3de8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aeb8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aeb8 = in_ECX;
  return;
}


// ==== FUN_00765d20 @ 0x00765d20 ====

void FUN_00765d20(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aeb8 = 0;
  *in_ECX = &PTR_FUN_009f3ddc;
  return;
}


// ==== FUN_00765d40 @ 0x00765d40 ====

void FUN_00765d40(void)

{
  int unaff_retaddr;
  void *pvStack_54;
  undefined1 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  void *pvStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009953f8;
  pvStack_c = ExceptionList;
  uStack_30 = 4;
  uStack_34 = 0x765d66;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    uStack_34 = 0x640001;
    break;
  case 1:
    uStack_34 = 0x640005;
    break;
  case 2:
    uStack_34 = 0x640004;
    break;
  case 3:
    uStack_34 = 0x640003;
    break;
  case 4:
    uStack_34 = 0x64000d;
    break;
  case 5:
    uStack_34 = 0x640002;
    break;
  case 6:
    uStack_34 = 0x640006;
    break;
  case 7:
    uStack_34 = 0x640007;
    break;
  case 8:
    uStack_34 = 0x640008;
    break;
  case 9:
    uStack_34 = 0x640009;
    break;
  case 10:
    uStack_34 = 0x64000e;
    break;
  default:
    uStack_34 = 0x64000a;
  }
  uStack_38 = 9;
  pvStack_3c = (void *)0x765dd9;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  pvStack_3c = (void *)0xffffffff;
  uStack_40 = 0;
  uStack_30 = uStack_30 & 0xffffff00;
  uStack_48 = 0x765df8;
  FUN_00401660();
  puStack_8 = (undefined1 *)&pvStack_54;
  pvStack_3c = (void *)0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  (**(code **)(*DAT_00b5aee8 + 0x14))();
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  if (uStack_40 < 0x10) {
    ExceptionList = pvStack_3c;
    return;
  }
  _free(pvStack_54);
  return;
}


// ==== FUN_00765ea0 @ 0x00765ea0 ====

void FUN_00765ea0(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int *piVar3;
  uint unaff_EBX;
  undefined1 auStack_c4 [4];
  undefined1 uStack_c0;
  void *pvStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined1 auStack_9c [4];
  undefined1 uStack_98;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  char *pcStack_7c;
  undefined1 auStack_62 [2];
  void *pvStack_60;
  undefined1 auStack_5c [12];
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 *puStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0099541a;
  pvStack_c = ExceptionList;
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  piVar3 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
  if (piVar3 == (int *)0x0) {
    pcStack_7c = s_pDialog____NULL_009f3dc4;
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    uStack_80 = 0x765ef6;
    FUN_00401740();
    puStack_4 = (undefined1 *)0x0;
    pcStack_7c = (char *)0x765f04;
    FUN_00406880();
    if (uStack_30 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    pcStack_7c = (char *)0x765f18;
    _free(pvStack_44);
    return;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  pcStack_7c = (void *)0x9;
  puStack_4 = (undefined1 *)0x1;
  uStack_80 = 0x765f42;
  uStack_88 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_80 = 0xffffffff;
  uStack_84 = 0;
  uStack_8c = 0x765f4f;
  FUN_00401660();
  uStack_84 = 0x765f55;
  uStack_80 = uVar1;
  uStack_80 = FUN_00792940();
  puStack_4 = auStack_9c;
  uStack_a0 = 0xffffffff;
  uStack_a4 = 0;
  puStack_a8 = auStack_62 + -10;
  uStack_84 = 0xf;
  uStack_88 = 0;
  uStack_98 = 0;
  uStack_ac = 0x765f7b;
  FUN_00401660();
  uStack_a0 = 0x765f82;
  (**(code **)(*piVar3 + 4))();
  uStack_3c = 0xf;
  uStack_40 = 0;
  uStack_50 = uStack_50 & 0xffffff00;
  uStack_a0 = 0x64006c;
  uStack_a4 = 9;
  puStack_2c = (undefined1 *)CONCAT31(puStack_2c._1_3_,2);
  puStack_a8 = (undefined1 *)0x765fa5;
  uStack_b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_a8 = (undefined1 *)0xffffffff;
  uStack_ac = 0;
  pvStack_b4 = (void *)0x765fb2;
  FUN_00401660();
  puStack_2c = auStack_c4;
  uStack_40 = 0;
  uStack_ac = 0xf;
  uStack_b0 = 0;
  uStack_c0 = 0;
  FUN_00401660(auStack_5c,0,0xffffffff);
  puStack_a8 = (undefined1 *)uStack_40;
  (**(code **)(*piVar3 + 8))();
  (**(code **)(*DAT_00b5aee8 + 0x10))();
  (**(code **)(*DAT_00b5acd4 + 4))(3);
  if (0xf < unaff_EBX) {
    _free(pcStack_7c);
    return;
  }
  pcStack_7c = (char *)((uint)pcStack_7c & 0xffffff00);
  if (uStack_a0 < 0x10) {
    ExceptionList = pvStack_60;
    return;
  }
  _free(pvStack_b4);
  return;
}


// ==== FUN_00766060 @ 0x00766060 ====

undefined4 FUN_00766060(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5300001) {
    FUN_00765ea0(*(undefined4 *)(param_1 + 0xc));
  }
  else {
    if (iVar1 == 0x5300003) {
      FUN_00765d40(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (iVar1 != 0x530001a) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0xc);
    (**(code **)(*DAT_00b5af2c + 8))(4);
    if (*(int *)(iVar1 + 0x10) == 0) {
      (**(code **)(*DAT_00b5aee8 + 0x14))();
      (**(code **)(*DAT_00b5acd4 + 4))(0);
      return 1;
    }
  }
  return 1;
}


// ==== FUN_007660f0 @ 0x007660f0 ====

undefined4 FUN_007660f0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00766060(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00766120 @ 0x00766120 ====

void FUN_00766120(byte param_1)

{
  void *in_ECX;
  
  FUN_00765d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00766140 @ 0x00766140 ====

void FUN_00766140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3f18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00766160 @ 0x00766160 ====

void FUN_00766160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3f24;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aea8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aea8 = in_ECX;
  return;
}


// ==== FUN_007661c0 @ 0x007661c0 ====

void FUN_007661c0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aea8 = 0;
  *in_ECX = &PTR_FUN_009f3f18;
  return;
}


// ==== FUN_007661e0 @ 0x007661e0 ====

/* WARNING: Removing unreachable block (ram,0x00766b61) */
/* WARNING: Removing unreachable block (ram,0x00766610) */
/* WARNING: Removing unreachable block (ram,0x00766570) */
/* WARNING: Removing unreachable block (ram,0x007664d0) */
/* WARNING: Removing unreachable block (ram,0x00766520) */
/* WARNING: Removing unreachable block (ram,0x007665c0) */
/* WARNING: Removing unreachable block (ram,0x00766660) */
/* WARNING: Removing unreachable block (ram,0x007663f6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007661e0(int param_1)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  uint unaff_ESI;
  undefined1 auStack_108 [4];
  undefined1 uStack_104;
  undefined4 uStack_100;
  undefined4 uVar8;
  undefined1 *puStack_d8;
  int *piStack_d0;
  int *piStack_b0;
  void *pvStack_a4;
  int local_98;
  int *piStack_94;
  uint uStack_90;
  void *pvStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  void *pvStack_68;
  undefined4 local_64;
  void *pvStack_60;
  void *pvStack_5c;
  uint uStack_54;
  undefined4 uStack_50;
  void *pvStack_4c;
  undefined1 uStack_40;
  uint uStack_38;
  void *pvStack_34;
  undefined1 uStack_28;
  undefined1 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995513;
  pvStack_c = ExceptionList;
  local_64 = CONCAT22((short)(unaff_ESI >> 0x10),*(undefined2 *)(param_1 + 0x14));
  local_98 = *(int *)(param_1 + 0x14);
  piStack_d0 = &local_98;
  ExceptionList = &pvStack_c;
  piStack_94 = (int *)(**(code **)(*DAT_00b5ab58 + 8))();
  if (piStack_94 == (int *)0x0) {
    uStack_100 = 0x766265;
    FUN_00401740();
    FUN_00404230();
    puStack_8 = (undefined1 *)0x0;
    uStack_100 = 0x76627f;
    FUN_00796d50();
    puStack_8 = (undefined1 *)0xffffffff;
    if ((void *)0xf < pvStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_100 = 0x7662c4;
    FUN_00401740();
    FUN_00404230();
    puStack_8 = (undefined1 *)0x2;
    FUN_00401660();
    piVar4 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    FUN_00792c00();
    uStack_100 = 0x766347;
    FUN_00401660();
    (**(code **)(*piVar4 + 4))();
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))();
    if (0xf < unaff_ESI) {
      _free((void *)0x0);
      return;
    }
    if (uStack_54 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    pvVar6 = pvStack_68;
  }
  else {
    local_98 = (**(code **)(*DAT_00b5aee8 + 8))();
    if (local_98 == 0) {
      FUN_00401740();
      puStack_8 = (undefined1 *)0x3;
      FUN_00406880();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    uStack_28 = 0;
    puStack_8 = (undefined1 *)0x4;
    (**(code **)(*piStack_94 + 4))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    (**(code **)(*DAT_00b5ac40 + 0x20))();
    uStack_54 = 0;
    uStack_50 = 0;
    pvStack_4c = (void *)0x0;
    uStack_18._0_1_ = 5;
    FUN_00401740();
    uStack_18._0_1_ = 6;
    FUN_00406720();
    uStack_18._0_1_ = 5;
    FUN_00401740();
    uStack_18._0_1_ = 7;
    FUN_00406720();
    uStack_18._0_1_ = 5;
    FUN_00401740();
    uStack_18._0_1_ = 8;
    FUN_00406720();
    uStack_18._0_1_ = 5;
    FUN_00401740();
    uStack_18._0_1_ = 9;
    FUN_00406720();
    uStack_18._0_1_ = 5;
    FUN_00401740();
    uStack_18._0_1_ = 10;
    FUN_00406720();
    uStack_18._0_1_ = 5;
    FUN_00401740();
    uStack_18._0_1_ = 0xb;
    FUN_00406720();
    uStack_18 = CONCAT31(uStack_18._1_3_,5);
    iVar5 = *DAT_00b5ad00;
    (**(code **)(*DAT_00b5a97c + 0xc))();
    (**(code **)(iVar5 + 4))();
    piVar4 = (int *)(**(code **)(*DAT_00b5ab84 + 8))();
    iVar5 = (**(code **)(*piVar4 + 4))();
    piStack_d0 = *(int **)(iVar5 + 4);
    piVar4 = *(int **)(iVar5 + 8);
    pvStack_78 = (void *)0x0;
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_20 = 0xc;
    uStack_104 = 0;
    FUN_00401740();
    FUN_00404230();
    uStack_20 = 0xd;
    FUN_00406720();
    uStack_20 = 0xc;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_104 = 0;
    FUN_00401740();
    FUN_00404230();
    uStack_20 = 0xe;
    FUN_00406720();
    uStack_20 = 0xc;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_104 = 0;
    FUN_00401740();
    FUN_00404230();
    uStack_20 = 0xf;
    FUN_00406720();
    uStack_20 = 0xc;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_104 = 0;
    FUN_00401740();
    FUN_00404230();
    uStack_20 = 0x10;
    FUN_00406720();
    uStack_20 = 0xc;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_104 = 0;
    FUN_00401740();
    FUN_00404230();
    uStack_20 = 0x11;
    FUN_00406720();
    uStack_20 = 0xc;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_104 = 0;
    FUN_00401740();
    FUN_00404230();
    uStack_20 = 0x12;
    FUN_00406720();
    uStack_20 = 0xc;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    FUN_00404a40();
    uStack_20 = 0x13;
    FUN_00401660();
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    if (pvStack_78 != (void *)0x0) {
      FUN_00405de0();
      uStack_100 = 0x766979;
      _free(pvStack_78);
      return;
    }
    pvStack_78 = (void *)0x0;
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_20 = 4;
    if (pvStack_5c != (void *)0x0) {
      FUN_00405de0();
      uStack_100 = 0x7669c3;
      _free(pvStack_5c);
      return;
    }
    pvVar6 = (void *)FUN_00792aa0();
    puStack_d8 = auStack_108;
    uStack_104 = 0;
    FUN_00401660();
    (**(code **)(*piStack_b0 + 4))();
    uVar8 = 0;
    cVar2 = (**(code **)(*piVar4 + 8))();
    if (cVar2 != '\0') {
      do {
        (**(code **)(*piVar4 + 0xc))();
        piVar7 = (int *)(**(code **)(*DAT_00b5ab58 + 8))();
        if (piVar7 == (int *)0x0) {
          FUN_00401740();
          uStack_40 = 0x14;
          FUN_00796d50();
          uStack_40 = 4;
          break;
        }
        uStack_40 = 0x15;
        (**(code **)(*piVar7 + 4))();
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00401660();
        FUN_00401660(&piStack_d0,0,0xffffffff);
        (**(code **)(*piStack_b0 + 8))();
        pvStack_68 = (void *)CONCAT31(pvStack_68._1_3_,4);
        if ((undefined1 *)0xf < puStack_d8) {
          _free(pvVar6);
          return;
        }
        puStack_d8 = (undefined1 *)0xf;
        pvVar6 = (void *)((uint)pvVar6 & 0xffffff00);
        bVar3 = (**(code **)(_DAT_00000000 + 8))();
      } while ((byte)uVar8 < bVar3);
    }
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))();
    if (uStack_38 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    pvVar6 = pvStack_4c;
  }
  _free(pvVar6);
  return;
}


// ==== FUN_00766bf0 @ 0x00766bf0 ====

undefined4 FUN_00766bf0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x5260002) {
      FUN_007661e0(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00766c30 @ 0x00766c30 ====

void FUN_00766c30(byte param_1)

{
  void *in_ECX;
  
  FUN_007661c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00766c50 @ 0x00766c50 ====

void FUN_00766c50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3f70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00766c70 @ 0x00766c70 ====

void FUN_00766c70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3f7c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aeac = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aeac = in_ECX;
  return;
}


// ==== FUN_00766cd0 @ 0x00766cd0 ====

void FUN_00766cd0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aeac = 0;
  *in_ECX = &PTR_FUN_009f3f70;
  return;
}


// ==== FUN_00766d30 @ 0x00766d30 ====

undefined4 FUN_00766d30(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x5230000) {
      (**(code **)(*DAT_00b5a9e4 + 0x30))(*(undefined4 *)(param_1[3] + 0x10));
      (**(code **)(*DAT_00b5a9e4 + 0x4c))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00766d80 @ 0x00766d80 ====

void FUN_00766d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00766cd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00766da0 @ 0x00766da0 ====

void FUN_00766da0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3ff0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00766dc0 @ 0x00766dc0 ====

void FUN_00766dc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3ffc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aeb0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aeb0 = in_ECX;
  return;
}


// ==== FUN_00766df0 @ 0x00766df0 ====

void FUN_00766df0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aeb0 = 0;
  *in_ECX = &PTR_FUN_009f3ff0;
  return;
}


// ==== FUN_00766e10 @ 0x00766e10 ====

void FUN_00766e10(void)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined *puStack_a4;
  undefined1 auStack_a0 [12];
  undefined4 uStack_94;
  undefined4 *puStack_90;
  undefined1 *puStack_8c;
  undefined4 uStack_68;
  uint uStack_54;
  void *pvStack_50;
  void *local_4c;
  undefined4 local_48;
  undefined1 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  uint uStack_1c;
  void *pvStack_18;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995550;
  pvStack_c = ExceptionList;
  local_48 = 0xf;
  local_4c = (void *)0x0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  piVar3 = (int *)(**(code **)(*DAT_00b5ab34 + 8))();
  if (piVar3 == (int *)0x0) {
    puStack_90 = (undefined4 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_8c = (undefined1 *)0x0;
    uStack_94 = 0x766e7f;
    FUN_00401660();
    puStack_8 = (undefined1 *)&puStack_a4;
    puStack_8c = (undefined1 *)0xf;
    puStack_90 = (undefined4 *)0x0;
    auStack_a0[0] = 0;
    FUN_00401660(auStack_a0 + 0x34,0,0xffffffff);
    uVar4 = FUN_00404230(&uStack_34);
    uStack_10 = 1;
    FUN_00796d50(uVar4);
    if (0xf < uStack_1c) {
      puStack_8c = (undefined1 *)0x766eda;
      _free(pvStack_30);
      return;
    }
  }
  else {
    iVar5 = (**(code **)(*piVar3 + 4))();
    pcVar6 = (char *)(iVar5 + 2);
    pvStack_30 = (void *)0xf;
    uStack_34 = 0;
    uStack_44 = 0;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    puStack_90 = (undefined4 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_8c = (undefined1 *)0x0;
    uStack_94 = 0x766f39;
    FUN_00401660();
    puStack_8c = auStack_a0 + 0x34;
    puStack_90 = &uStack_34;
    uStack_94 = 0x766f4d;
    uVar4 = FUN_00405bd0();
    puStack_8 = auStack_a0;
    puStack_a4 = &DAT_009f3fc0;
    uStack_10 = 3;
    FUN_00402220(auStack_a0,uVar4);
    puStack_a4 = (undefined *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    pvStack_30 = (void *)CONCAT31(pvStack_30._1_3_,2);
    if (0xf < uStack_3c) {
      _free(pvStack_50);
      return;
    }
    uStack_94 = 0;
    puStack_90 = (undefined4 *)((uint)puStack_90 & 0xffff0000);
    iVar5 = (**(code **)(*piVar3 + 4))();
    uStack_94 = CONCAT22(uStack_94._2_2_,*(undefined2 *)(iVar5 + 0x102));
    iVar5 = (**(code **)(*piVar3 + 4))();
    uStack_94 = CONCAT22(*(undefined2 *)(iVar5 + 0x104),(undefined2)uStack_94);
    iVar5 = (**(code **)(*piVar3 + 4))();
    puStack_90 = (undefined4 *)CONCAT22(puStack_90._2_2_,*(undefined2 *)(iVar5 + 0x106));
    iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar5 == 0) {
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
      FUN_00401740(s_pIPC____NULL_009f3fc4,0xc);
      pvStack_30._0_1_ = 4;
      FUN_00406880(&uStack_54);
      pvStack_30 = (void *)CONCAT31(pvStack_30._1_3_,2);
      if (uStack_3c < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_50);
      return;
    }
    if ((*(int **)(iVar5 + 0x8c) == (int *)0x0) ||
       (piVar3 = (int *)(**(code **)(**(int **)(iVar5 + 0x8c) + 0x18))(), piVar3 == (int *)0x0)) {
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
      FUN_00401740(s_pPosition_L____NULL_009f3fd4,0x13);
      pvStack_30._0_1_ = 5;
      FUN_00406880(&uStack_54);
      pvStack_30 = (void *)CONCAT31(pvStack_30._1_3_,2);
      if (uStack_3c < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_50);
      return;
    }
    (**(code **)(*piVar3 + 0x14))(&uStack_94);
    if (0xf < uStack_38) {
      puStack_8c = (undefined1 *)0x7670bb;
      _free(local_4c);
      return;
    }
    uStack_38 = 0xf;
    uStack_3c = 0;
    local_4c = (void *)((uint)local_4c & 0xffffff00);
  }
  if (uStack_54 < 0x10) {
    ExceptionList = pvStack_18;
    return;
  }
  puStack_8c = (undefined1 *)0x7670da;
  _free(uStack_68);
  return;
}


// ==== FUN_00767130 @ 0x00767130 ====

undefined4 FUN_00767130(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x506000a) {
      FUN_00766e10(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00767170 @ 0x00767170 ====

void FUN_00767170(byte param_1)

{
  void *in_ECX;
  
  FUN_00766df0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00767190 @ 0x00767190 ====

void FUN_00767190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4080;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007671c0 @ 0x007671c0 ====

void FUN_007671c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f408c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aeb4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aeb4 = in_ECX;
  return;
}


// ==== FUN_00767200 @ 0x00767200 ====

void FUN_00767200(void)

{
  (**(code **)(*DAT_00b5af2c + 8))(4);
  (**(code **)(*DAT_00b5aee8 + 0x14))();
  (**(code **)(*DAT_00b5ae48 + 0xc))();
  (**(code **)(*DAT_00b5ae48 + 0x1c))();
                    /* WARNING: Could not recover jumptable at 0x0076723e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acd4 + 4))();
  return;
}


// ==== FUN_00767250 @ 0x00767250 ====

void FUN_00767250(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aeb4 = 0;
  *in_ECX = &PTR_FUN_009f4080;
  return;
}


// ==== FUN_00767270 @ 0x00767270 ====

void FUN_00767270(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  void *unaff_EBP;
  uint unaff_ESI;
  void *pvStack_48;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 uStack_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995578;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Mail_SN_Open_received___npc_Inde_009f4040,0x25);
  uVar2 = FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(uVar2);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
  if (piVar3 == (int *)0x0) {
    local_10 = 0xf;
    uStack_14 = 0;
    local_24 = (void *)((uint)local_24._1_3_ << 8);
    FUN_00401740();
    local_4 = 1;
    FUN_00406880();
    if (local_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24._1_3_ << 8);
  local_4 = 2;
  FUN_00792d50();
  FUN_00401660(local_28,0,0xffffffff);
  (**(code **)(*piVar3 + 4))();
  (**(code **)(*DAT_00b5ae48 + 0x34))();
  (**(code **)(*DAT_00b5acd4 + 4))(10);
  if (unaff_ESI < 0x10) {
    ExceptionList = unaff_EBP;
    return;
  }
  _free(pvStack_48);
  return;
}


// ==== FUN_007673d0 @ 0x007673d0 ====

undefined4 FUN_007673d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x51f0000) {
    FUN_00767270(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x51f0002) {
    FUN_00767200(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_00767420 @ 0x00767420 ====

undefined4 FUN_00767420(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007673d0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00767450 @ 0x00767450 ====

void FUN_00767450(byte param_1)

{
  void *in_ECX;
  
  FUN_00767250();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00767470 @ 0x00767470 ====

void FUN_00767470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4104;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007674a0 @ 0x007674a0 ====

void FUN_007674a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4110;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aec0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aec0 = in_ECX;
  return;
}


// ==== FUN_00767500 @ 0x00767500 ====

void FUN_00767500(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aec0 = 0;
  *in_ECX = &PTR_FUN_009f4104;
  return;
}


// ==== FUN_00767520 @ 0x00767520 ====

void FUN_00767520(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_10c [16];
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 *puStack_e8;
  undefined1 *puStack_dc;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 *puStack_c4;
  undefined4 uStack_a0;
  char *pcStack_9c;
  void *local_7c;
  undefined1 auStack_78 [12];
  void *local_6c;
  uint local_68;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined1 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995608;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x14)) {
  case 0:
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    ExceptionList = &pvStack_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (piVar2 == (int *)0x0) {
      pcStack_9c = (char *)0x767578;
      FUN_00401830();
      local_4 = 0;
      pcStack_9c = (char *)0x767589;
      FUN_00406880();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    uStack_60 = 0;
    pcStack_9c = (char *)0x8;
    local_4 = 1;
    uStack_a0 = 0x7675c4;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0xffffffff;
    FUN_00401660();
    uStack_a0 = uVar1;
    uStack_a0 = FUN_00792f10();
    puStack_c4 = (undefined4 *)0x7675ee;
    FUN_00765c50();
    (**(code **)(*piVar2 + 4))();
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    puStack_c4 = (undefined4 *)0x8;
    uStack_2c = 2;
    uStack_c8 = 0x76761b;
    uStack_d0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c8 = 0xffffffff;
    uStack_cc = 0;
    uStack_d4 = 0x767628;
    FUN_00401660();
    puStack_e8 = auStack_78;
    uStack_5c = 0;
    uStack_ec = 0x767642;
    FUN_0068e600();
    puStack_e8 = (undefined1 *)0x767649;
    (**(code **)(*piVar2 + 8))();
    puStack_e8 = (undefined1 *)0x12c0065;
    uStack_ec = 8;
    uStack_f0 = 0x76765b;
    uStack_f8 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_f0 = 0xffffffff;
    uStack_f4 = 0;
    uStack_fc = 0x767668;
    FUN_00401660();
    puStack_dc = auStack_10c;
    FUN_0068e600(&uStack_a0);
    (**(code **)(*piVar2 + 8))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x7676d6;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x3;
    break;
  case 2:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767804;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x8;
    goto LAB_007678c6;
  case 3:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767830;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x9;
    break;
  case 4:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x76785c;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0xa;
    goto LAB_007678c6;
  case 5:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767885;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0xb;
    break;
  case 6:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x76772b;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x4;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  default:
    pcStack_9c = s_Teleport_SN_Open_Fail_____009f40e0;
    local_68 = 0xf;
    local_6c = (void *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    uStack_a0 = 0x767917;
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_4 = 0xd;
    pcStack_9c = (char *)0x76792c;
    FUN_00796d50();
    local_4 = 0xffffffff;
    if (0xf < local_68) {
      pcStack_9c = (char *)0x76794f;
      _free(local_7c);
      return;
    }
    local_68 = 0xf;
    local_6c = (void *)0x0;
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767970;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0xffffffff;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    FUN_00401660();
    puStack_c4 = &uStack_50;
    uStack_a0 = 0xf;
    pvStack_c = (void *)0xe;
    uStack_c8 = 0x7679b3;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_58 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    puStack_c4 = (undefined4 *)0x7679d0;
    _free(local_6c);
    return;
  case 8:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767780;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x5;
    break;
  case 9:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x7677ac;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x6;
    goto LAB_007678c6;
  case 10:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x7677d8;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x7;
    break;
  case 0xb:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x7678b1;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0xc;
LAB_007678c6:
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  FUN_00765c50();
  (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00767a20 @ 0x00767a20 ====

undefined4 FUN_00767a20(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0xf020009) {
    FUN_00767520(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0xf02000b) {
    (**(code **)(*DAT_00b5af2c + 8))(4);
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
  return 0;
}


// ==== FUN_00767a90 @ 0x00767a90 ====

undefined4 FUN_00767a90(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00767a20(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00767ac0 @ 0x00767ac0 ====

void FUN_00767ac0(byte param_1)

{
  void *in_ECX;
  
  FUN_00767500();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00767ae0 @ 0x00767ae0 ====

void FUN_00767ae0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4188;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00767b10 @ 0x00767b10 ====

void FUN_00767b10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4194;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aecc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aecc = in_ECX;
  return;
}


// ==== FUN_00767b70 @ 0x00767b70 ====

void FUN_00767b70(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aecc = 0;
  *in_ECX = &PTR_FUN_009f4188;
  return;
}


// ==== FUN_00767b90 @ 0x00767b90 ====

void FUN_00767b90(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_10c [16];
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 *puStack_e8;
  undefined1 *puStack_dc;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 *puStack_c4;
  undefined4 uStack_a0;
  char *pcStack_9c;
  void *local_7c;
  undefined1 auStack_78 [12];
  void *local_6c;
  uint local_68;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined1 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995698;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x14)) {
  case 0:
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    ExceptionList = &pvStack_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (piVar2 == (int *)0x0) {
      pcStack_9c = (char *)0x767be8;
      FUN_00401830();
      local_4 = 0;
      pcStack_9c = (char *)0x767bf9;
      FUN_00406880();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    uStack_60 = 0;
    pcStack_9c = (char *)0x8;
    local_4 = 1;
    uStack_a0 = 0x767c34;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0xffffffff;
    FUN_00401660();
    uStack_a0 = uVar1;
    uStack_a0 = FUN_00793010();
    puStack_c4 = (undefined4 *)0x767c5e;
    FUN_00765c50();
    (**(code **)(*piVar2 + 4))();
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    puStack_c4 = (undefined4 *)0x8;
    uStack_2c = 2;
    uStack_c8 = 0x767c8b;
    uStack_d0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c8 = 0xffffffff;
    uStack_cc = 0;
    uStack_d4 = 0x767c98;
    FUN_00401660();
    puStack_e8 = auStack_78;
    uStack_5c = 0;
    uStack_ec = 0x767cb2;
    FUN_0068e600();
    puStack_e8 = (undefined1 *)0x767cb9;
    (**(code **)(*piVar2 + 8))();
    puStack_e8 = (undefined1 *)0xc80065;
    uStack_ec = 8;
    uStack_f0 = 0x767ccb;
    uStack_f8 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_f0 = 0xffffffff;
    uStack_f4 = 0;
    uStack_fc = 0x767cd8;
    FUN_00401660();
    puStack_dc = auStack_10c;
    FUN_0068e600(&uStack_a0);
    (**(code **)(*piVar2 + 8))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767d46;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x3;
    break;
  case 2:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767e74;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x8;
    goto LAB_00767f36;
  case 3:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767ea0;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x9;
    break;
  case 4:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767ecc;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0xa;
    goto LAB_00767f36;
  case 5:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767ef5;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0xb;
    break;
  case 6:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767f21;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0xc;
    goto LAB_00767f36;
  case 7:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767d9b;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x4;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  default:
    pcStack_9c = s_Teleport_SN_Open_Fail_____009f4164;
    local_68 = 0xf;
    local_6c = (void *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    uStack_a0 = 0x767f87;
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_4 = 0xd;
    pcStack_9c = (char *)0x767f9c;
    FUN_00796d50();
    local_4 = 0xffffffff;
    if (0xf < local_68) {
      pcStack_9c = (char *)0x767fbf;
      _free(local_7c);
      return;
    }
    local_68 = 0xf;
    local_6c = (void *)0x0;
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767fe0;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0xffffffff;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    FUN_00401660();
    puStack_c4 = &uStack_50;
    uStack_a0 = 0xf;
    pvStack_c = (void *)0xe;
    uStack_c8 = 0x768023;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_58 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    puStack_c4 = (undefined4 *)0x768040;
    _free(local_6c);
    return;
  case 9:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767df0;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x5;
    break;
  case 10:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767e1c;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x6;
LAB_00767f36:
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xb:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x767e48;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x7;
  }
  FUN_00765c50();
  (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00768090 @ 0x00768090 ====

undefined4 FUN_00768090(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0xf020006) {
    FUN_00767b90(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0xf020008) {
    (**(code **)(*DAT_00b5af2c + 8))(4);
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
  return 0;
}


// ==== FUN_00768100 @ 0x00768100 ====

undefined4 FUN_00768100(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00768090(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00768130 @ 0x00768130 ====

void FUN_00768130(byte param_1)

{
  void *in_ECX;
  
  FUN_00767b70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00768150 @ 0x00768150 ====

void FUN_00768150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f420c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00768180 @ 0x00768180 ====

void FUN_00768180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4218;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aec4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aec4 = in_ECX;
  return;
}


// ==== FUN_007681e0 @ 0x007681e0 ====

void FUN_007681e0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aec4 = 0;
  *in_ECX = &PTR_FUN_009f420c;
  return;
}


// ==== FUN_00768200 @ 0x00768200 ====

void FUN_00768200(int param_1)

{
  int *piVar1;
  undefined1 auStack_108 [16];
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined1 *puStack_e4;
  undefined1 *puStack_dc;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 *puStack_c0;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  char *pcStack_98;
  void *local_7c;
  undefined1 auStack_78 [12];
  void *local_6c;
  uint local_68;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined1 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995720;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x14)) {
  case 0:
    ExceptionList = &pvStack_c;
    piVar1 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (piVar1 == (int *)0x0) {
      pcStack_98 = (char *)0x768254;
      FUN_00401830();
      local_4 = 0;
      pcStack_98 = (char *)0x768265;
      FUN_00406880();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    uStack_60 = 0;
    pcStack_98 = (char *)0x8;
    local_4 = 1;
    uStack_9c = 0x7682a0;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_9c = 0xffffffff;
    uStack_a0 = 0;
    FUN_00401660();
    uStack_9c = 0x7682b2;
    uStack_9c = FUN_00793110();
    puStack_c0 = (undefined4 *)0x7682c6;
    FUN_00765c50();
    (**(code **)(*piVar1 + 4))();
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    puStack_c0 = (undefined4 *)0x8;
    uStack_2c = 2;
    uStack_c4 = 0x7682f3;
    uStack_cc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c4 = 0xffffffff;
    uStack_c8 = 0;
    uStack_d0 = 0x768300;
    FUN_00401660();
    puStack_e4 = auStack_78;
    uStack_5c = 0;
    uStack_e8 = 0x76831a;
    FUN_0068e600();
    puStack_e4 = (undefined1 *)0x768321;
    (**(code **)(*piVar1 + 8))();
    puStack_e4 = (undefined1 *)0x1f4000c;
    uStack_e8 = 8;
    uStack_ec = 0x768333;
    uStack_f4 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_ec = 0xffffffff;
    uStack_f0 = 0;
    uStack_f8 = 0x768340;
    FUN_00401660();
    puStack_dc = auStack_108;
    FUN_0068e600(&uStack_a0);
    (**(code **)(*piVar1 + 8))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x7683ae;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x7683b8;
    FUN_00765c50();
    pvStack_c = (void *)0x3;
    break;
  case 2:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x768403;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x76840d;
    FUN_00765c50();
    pvStack_c = (void *)0x4;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x768458;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x768462;
    FUN_00765c50();
    pvStack_c = (void *)0x5;
    break;
  case 4:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x768484;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x76848e;
    FUN_00765c50();
    pvStack_c = (void *)0x6;
    goto LAB_00768546;
  case 5:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x768505;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x76850f;
    FUN_00765c50();
    pvStack_c = (void *)0x9;
    break;
  case 6:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x7684b0;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x7684ba;
    FUN_00765c50();
    pvStack_c = (void *)0x7;
    break;
  case 7:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x7684dc;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x7684e6;
    FUN_00765c50();
    pvStack_c = (void *)0x8;
    goto LAB_00768546;
  case 8:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x768531;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x76853b;
    FUN_00765c50();
    pvStack_c = (void *)0xa;
LAB_00768546:
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 9:
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x768586;
    ExceptionList = &pvStack_c;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0x768590;
    FUN_00765c50();
    pvStack_c = (void *)0xb;
    break;
  default:
    pcStack_98 = s_Siege_Info_SN_Open_Fail_____009f41e8;
    local_68 = 0xf;
    local_6c = (void *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    uStack_9c = 0x7685c3;
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_4 = 0xc;
    pcStack_98 = (char *)0x7685d8;
    FUN_00796d50();
    local_4 = 0xffffffff;
    if (0xf < local_68) {
      pcStack_98 = (char *)0x7685fb;
      _free(local_7c);
      return;
    }
    local_68 = 0xf;
    local_6c = (void *)0x0;
    pcStack_98 = (char *)0x8;
    uStack_9c = 0x76861c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_9c = 0xffffffff;
    uStack_a0 = 0;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    FUN_00401660();
    puStack_c0 = &uStack_50;
    uStack_9c = 0xf;
    uStack_a0 = 0;
    pvStack_c = (void *)0xd;
    uStack_c4 = 0x76865f;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_58 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    puStack_c0 = (undefined4 *)0x76867c;
    _free(local_6c);
    return;
  }
  FUN_00765c50();
  (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_007686d0 @ 0x007686d0 ====

undefined4 FUN_007686d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0xf02000f) {
    FUN_00768200(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0xf020011) {
    (**(code **)(*DAT_00b5af2c + 8))(4);
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
  return 0;
}


// ==== FUN_00768740 @ 0x00768740 ====

undefined4 FUN_00768740(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007686d0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00768770 @ 0x00768770 ====

void FUN_00768770(byte param_1)

{
  void *in_ECX;
  
  FUN_007681e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00768790 @ 0x00768790 ====

void FUN_00768790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f43a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007687c0 @ 0x007687c0 ====

void FUN_007687c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f43b0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aec8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aec8 = in_ECX;
  return;
}


// ==== FUN_00768820 @ 0x00768820 ====

void FUN_00768820(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aec8 = 0;
  *in_ECX = &PTR_FUN_009f43a4;
  return;
}


// ==== FUN_00768840 @ 0x00768840 ====

/* WARNING: Removing unreachable block (ram,0x007688c6) */

void FUN_00768840(int param_1)

{
  code *pcVar1;
  int *piVar2;
  void *pvStack_78;
  void *local_6c;
  uint uStack_64;
  void *pvStack_60;
  undefined1 auStack_5c [4];
  uint uStack_58;
  undefined1 uStack_54;
  void *pvStack_50;
  uint uStack_4c;
  undefined1 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995760;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (piVar2 == (int *)0x0) {
      FUN_00401830();
      local_4 = 0;
      FUN_00406880();
      if (uStack_4c < 0x10) {
        uStack_4c = 0xf;
        pvStack_50 = (void *)0x0;
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_60);
      return;
    }
    uStack_30 = 0xf;
    pvStack_34 = (void *)0x0;
    uStack_44 = 0;
    local_4 = 1;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_007931c0();
    FUN_00401660();
    (**(code **)(*piVar2 + 4))();
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    uStack_2c = 2;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    uStack_40 = 0;
    FUN_00401660(auStack_5c,0,0xffffffff);
    (**(code **)(*piVar2 + 8))();
    uStack_54 = 1;
    if (0xf < uStack_64) {
      _free(pvStack_78);
      return;
    }
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))(3);
    if (uStack_58 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
  }
  else if (*(char *)(param_1 + 0x10) == '\x01') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    FUN_00401660();
    pvStack_c = (void *)0x3;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_58 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_4 = 4;
    FUN_00796d50();
    local_4 = 0xffffffff;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    FUN_00401660();
    pvStack_c = (void *)0x5;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_3c < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    local_6c = pvStack_50;
  }
  _free(local_6c);
  return;
}


// ==== FUN_00768b80 @ 0x00768b80 ====

int FUN_00768b80(int param_1)

{
  int iVar1;
  int extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995772;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  iVar1 = (**(code **)(*DAT_00b5ac98 + 4))();
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660();
  }
  else {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401660(local_28,0,0xffffffff);
    FUN_00404230(param_1);
  }
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00768ce0 @ 0x00768ce0 ====

void FUN_00768ce0(void)

{
  char cVar1;
  code *pcVar2;
  char *pcVar3;
  int iVar4;
  uint unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool bVar7;
  int unaff_retaddr;
  undefined1 auStack_3d0 [4];
  undefined1 uStack_3cc;
  undefined4 uStack_3c8;
  undefined4 *puStack_3c4;
  undefined4 uStack_3c0;
  undefined4 *puStack_3bc;
  char *pcStack_3a8;
  undefined1 *puStack_3a4;
  char *pcStack_3a0;
  void *pvVar8;
  undefined4 local_378;
  undefined1 *local_374;
  undefined1 auStack_368 [4];
  uint uStack_364;
  uint uStack_360;
  void *pvStack_358;
  undefined4 uStack_354;
  undefined4 uStack_350;
  uint uStack_348;
  uint uStack_344;
  void *pvStack_340;
  undefined4 uStack_338;
  undefined4 uStack_334;
  undefined4 uStack_330;
  uint uStack_32c;
  void *apvStack_324 [3];
  undefined1 uStack_318;
  uint uStack_310;
  void *pvStack_308;
  undefined4 uStack_304;
  undefined1 uStack_2fc;
  undefined4 uStack_2f8;
  uint uStack_2f4;
  undefined1 auStack_2f0 [4];
  void *pvStack_2ec;
  undefined4 uStack_2e8;
  undefined1 uStack_2e0;
  undefined4 uStack_2dc;
  uint uStack_2d8;
  void *pvStack_2d0;
  undefined4 uStack_2cc;
  undefined1 uStack_2c4;
  undefined4 uStack_2c0;
  uint uStack_2bc;
  void *pvStack_2b4;
  undefined4 uStack_2b0;
  undefined1 uStack_2a8;
  undefined4 uStack_2a4;
  uint uStack_2a0;
  void *pvStack_298;
  undefined4 uStack_294;
  undefined1 uStack_28c;
  undefined4 uStack_288;
  uint uStack_284;
  void *pvStack_27c;
  undefined4 uStack_278;
  undefined1 uStack_270;
  undefined4 uStack_26c;
  uint uStack_268;
  void *pvStack_260;
  undefined4 uStack_25c;
  undefined1 uStack_254;
  undefined4 uStack_250;
  uint uStack_24c;
  void *pvStack_244;
  undefined4 uStack_240;
  undefined1 uStack_238;
  undefined4 uStack_234;
  uint uStack_230;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined1 uStack_21c;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  void *pvStack_200;
  undefined4 uStack_1f0;
  uint uStack_1ec;
  void *pvStack_1e4;
  undefined4 uStack_1d4;
  uint uStack_1d0;
  void *pvStack_1c8;
  undefined4 uStack_1b8;
  uint uStack_1b4;
  void *pvStack_194;
  undefined4 uStack_184;
  uint uStack_180;
  undefined1 auStack_168 [4];
  void *pvStack_164;
  void *pvStack_160;
  undefined4 uStack_154;
  uint uStack_150;
  uint uStack_14c;
  void *pvStack_12c;
  int iStack_128;
  undefined4 uStack_11c;
  uint uStack_118;
  undefined1 auStack_114 [4];
  void *pvStack_110;
  undefined4 uStack_100;
  uint uStack_fc;
  undefined1 auStack_dc [20];
  undefined1 auStack_c8 [36];
  char acStack_a4 [12];
  undefined4 auStack_98 [5];
  char acStack_83 [75];
  void *pvStack_38;
  undefined1 uStack_2c;
  undefined1 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009958e9;
  pvStack_c = ExceptionList;
  local_374 = (undefined1 *)0x0;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(char *)(unaff_retaddr + 0x10) == '\0') {
    local_374 = (undefined1 *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (local_374 == (void *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      if (uStack_1b4 < 0x10) {
        uStack_1b4 = 0xf;
        uStack_1b8 = 0;
        pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_1c8);
      return;
    }
    uStack_2e8 = 0xf;
    pvStack_2ec = (void *)0x0;
    uStack_2fc = 0;
    puStack_8 = (undefined1 *)0x0;
    uStack_224 = 0xf;
    uStack_228 = 0;
    uStack_238 = 0;
    uStack_208 = 0xf;
    uStack_20c = 0;
    uStack_21c = 0;
    uStack_294 = 0xf;
    pvStack_298 = (void *)0x0;
    uStack_2a8 = 0;
    uStack_278 = 0xf;
    pvStack_27c = (void *)0x0;
    uStack_28c = 0;
    uStack_25c = 0xf;
    pvStack_260 = (void *)0x0;
    uStack_270 = 0;
    uStack_2cc = 0xf;
    pvStack_2d0 = (void *)0x0;
    uStack_2e0 = 0;
    uStack_240 = 0xf;
    pvStack_244 = (void *)0x0;
    uStack_254 = 0;
    uStack_304 = 0xf;
    pvStack_308 = (void *)0x0;
    uStack_318 = 0;
    uStack_2b0 = 0xf;
    pvStack_2b4 = (void *)0x0;
    uStack_2c4 = 0;
    puVar5 = (undefined4 *)(unaff_retaddr + 0x1a);
    puVar6 = auStack_98;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,10);
    (**(code **)(*DAT_00b5ad1c + 0x2c))();
    pvStack_c._0_1_ = 0xb;
    pcStack_3a0 = (char *)0x7690b3;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,10);
    if (0xf < uStack_180) {
      _free(pvStack_194);
      return;
    }
    uStack_180 = 0xf;
    uStack_184 = 0;
    pvStack_194 = (void *)((uint)pvStack_194 & 0xffffff00);
    puStack_3a4 = (undefined1 *)(**(code **)(*DAT_00b5ad1c + 0x30))();
    pcStack_3a0 = (char *)0x0;
    uStack_14._0_1_ = 0xc;
    pcStack_3a8 = (char *)0x76912f;
    FUN_00401660();
    pvVar8 = pvStack_c;
    uStack_14 = CONCAT31(uStack_14._1_3_,10);
    if (0xf < uStack_118) {
      pcStack_3a0 = (char *)0x76914d;
      _free(pvStack_12c);
      return;
    }
    uStack_118 = 0xf;
    uStack_11c = 0;
    pvStack_12c = (void *)((uint)pvStack_12c & 0xffffff00);
    if (*(char *)((int)pvStack_c + 0x12) == '\0') {
      bVar7 = *(char *)((int)pvStack_c + 0x11) == '\0';
      if (bVar7) {
        pcStack_3a0 = (char *)0x7691d5;
        puStack_3a4 = (undefined1 *)FUN_00401830();
        uStack_14 = 0xe;
      }
      else {
        pcStack_3a0 = auStack_dc;
        puStack_3a4 = (undefined1 *)0x7691b2;
        puStack_3a4 = (undefined1 *)FUN_00768b80();
        uStack_14 = CONCAT31(uStack_14._1_3_,0xd);
      }
      pcStack_3a0 = (char *)0x0;
      pcStack_3a8 = (char *)0x7691f8;
      FUN_00401660();
      if (!bVar7) {
        uStack_14 = 10;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    pcStack_3a0 = (char *)0x8;
    puStack_3a4 = (undefined1 *)0x769183;
    puStack_3a4 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    pcStack_3a0 = (char *)0x0;
    pcStack_3a8 = (char *)0x769193;
    FUN_00401660();
    if (*(char *)((int)pvVar8 + 0x18) == '\0') {
      pcStack_3a0 = &DAT_009f429c;
      puStack_3a4 = (undefined1 *)0x769246;
      FUN_00401740();
      pcStack_3a0 = &DAT_009f42a0;
      puStack_3a4 = (undefined1 *)0x769259;
      FUN_00401740();
      pcStack_3a0 = (char *)0x8;
      puStack_3a4 = (undefined1 *)0x76926b;
      puStack_3a4 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
      pcStack_3a0 = (char *)0x0;
      pcStack_3a8 = (char *)0x76927b;
      FUN_00401660();
      pcStack_3a0 = (char *)0x0;
      puStack_3a4 = auStack_2f0;
      pcStack_3a8 = (char *)0x769292;
      FUN_00401660();
    }
    else {
      puStack_3bc = (undefined4 *)&DAT_009f42a4;
      uStack_3c0 = 0x7692b3;
      FUN_00401830();
      puStack_3bc = (undefined4 *)auStack_114;
      uStack_3c0 = 0x7692c0;
      puStack_3a4 = (undefined1 *)FUN_00404230();
      pcStack_3a0 = (char *)0x0;
      uStack_14._0_1_ = 0xf;
      pcStack_3a8 = (char *)0x7692db;
      FUN_00401660();
      uStack_14._0_1_ = 10;
      if (0xf < uStack_fc) {
        pcStack_3a0 = (char *)0x7692f9;
        _free(pvStack_110);
        return;
      }
      puStack_3bc = (undefined4 *)&DAT_009f42a8;
      uStack_fc = 0xf;
      uStack_100 = 0;
      pvStack_110 = (void *)((uint)pvStack_110 & 0xffffff00);
      uStack_3c0 = 0x76932d;
      FUN_00401830();
      puStack_3bc = (undefined4 *)auStack_168;
      uStack_3c0 = 0x76933a;
      puStack_3a4 = (undefined1 *)FUN_00404230();
      pcStack_3a0 = (char *)0x0;
      uStack_14._0_1_ = 0x10;
      pcStack_3a8 = (char *)0x769355;
      FUN_00401660();
      uStack_14 = CONCAT31(uStack_14._1_3_,10);
      if (0xf < uStack_150) {
        pcStack_3a0 = (char *)0x769373;
        _free(pvStack_164);
        return;
      }
      pcVar3 = acStack_a4;
      uStack_150 = 0xf;
      uStack_154 = 0;
      pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcStack_3a0 = acStack_a4;
      puStack_3a4 = (undefined1 *)0x7693b5;
      FUN_00401740();
      pcVar3 = acStack_83;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcStack_3a0 = acStack_83;
      puStack_3a4 = (undefined1 *)0x7693e0;
      FUN_00401740();
    }
    if (*(char *)((int)pvVar8 + 0x13) == '\0') {
      pcStack_3a0 = (char *)0x8;
      puStack_3a4 = (undefined1 *)0x76962f;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_3a4 = (undefined1 *)0xffffffff;
      pcStack_3a8 = (char *)0x0;
      FUN_00401660();
      pcStack_3a8 = &DAT_009f42b9;
    }
    else {
      if (*(char *)((int)pvVar8 + 0x5c) != '\0') {
        pcStack_3a0 = (char *)0x8;
        puStack_3a4 = (undefined1 *)0x769404;
        (**(code **)(*DAT_00b5a794 + 0xc))();
        puStack_3a4 = (undefined1 *)0xffffffff;
        pcStack_3a8 = (char *)0x0;
        FUN_00401660();
        puStack_3a4 = (undefined1 *)(uint)*(byte *)((int)pvVar8 + 0x5c);
        puStack_3c4 = &uStack_330;
        uStack_3c8 = 0x76942c;
        FUN_00765c50();
        puStack_3c4 = (undefined4 *)auStack_c8;
        uStack_3c8 = 0x769439;
        FUN_00404230();
        puStack_3a4 = (undefined1 *)0xffffffff;
        pcStack_3a8 = (char *)0x0;
        uStack_1c = 0x11;
        FUN_00401660();
                    /* WARNING: Subroutine does not return */
        puStack_3a4 = (undefined1 *)0x76945d;
        FUN_00446f10();
      }
      pcStack_3a0 = (char *)0x8;
      puStack_3a4 = (undefined1 *)0x76960e;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_3a4 = (undefined1 *)0xffffffff;
      pcStack_3a8 = (char *)0x0;
      FUN_00401660();
      pcStack_3a8 = &DAT_009f42b8;
    }
    puStack_3a4 = (undefined1 *)0x0;
    FUN_00401740();
    local_378 = 0;
    uStack_350 = 0xf;
    uStack_354 = 0;
    uStack_364 = uStack_364 & 0xffffff00;
    uStack_334 = 0xf;
    uStack_338 = 0;
    uStack_348 = uStack_348 & 0xffffff00;
    puStack_3a4 = (undefined1 *)0xc;
    pcStack_3a8 = s_<SERVERNAME>_009f42bc;
    uStack_1c = 0x17;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x7696ac;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0xd;
    pcStack_3a8 = s_<CHANNELNAME>_009f42cc;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x7696de;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0x10;
    pcStack_3a8 = s_<NEXT_SIEGETIME>_009f42dc;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x76970f;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0x9;
    pcStack_3a8 = s_<MARK_BG>_009f42f0;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x769741;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0xb;
    pcStack_3a8 = s_<MARK_ICON>_009f42fc;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x769773;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0x10;
    pcStack_3a8 = s_<ATTACKER_GUILD>_009f4308;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x7697a4;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0xf;
    pcStack_3a8 = s_<ATTACKER_NAME>_009f431c;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x7697d5;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0xd;
    pcStack_3a8 = s_<SIEGE_STATE>_009f432c;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x769804;
    FUN_004e6c20();
    puStack_3a4 = (undefined1 *)0xb;
    pcStack_3a8 = s_<SEAL_LIST>_009f433c;
    FUN_00401740();
    puStack_3a4 = (undefined1 *)0xffffffff;
    pcStack_3a8 = (char *)0x0;
    FUN_00401660();
    puStack_3a4 = auStack_368;
    pcStack_3a8 = (char *)0x769836;
    FUN_004e6c20();
    puStack_3a4 = auStack_368 + -0x1c;
    pcStack_3a8 = (char *)0x1f400c8;
    puStack_3bc = (undefined4 *)(**(code **)(*DAT_00b5a794 + 8))();
    uStack_2c = 0x18;
    uStack_3c0 = 0x76986d;
    FUN_00401660();
    if (0xf < uStack_14c) {
      _free(pvStack_160);
      return;
    }
    uStack_14c = 0xf;
    uStack_150 = 0;
    pvStack_160 = (void *)((uint)pvStack_160 & 0xffffff00);
    if (0xf < uStack_344) {
      _free(pvStack_358);
      return;
    }
    uStack_344 = 0xf;
    uStack_348 = 0;
    pvStack_358 = (void *)((uint)pvStack_358 & 0xffffff00);
    if (0xf < uStack_360) {
      _free(local_374);
      return;
    }
    uStack_360 = 0xf;
    uStack_364 = 0;
    local_374 = (undefined1 *)((uint)local_374 & 0xffffff00);
    uStack_2c = 10;
    FUN_004e67a0();
    FUN_007932d0();
    pcStack_3a0 = auStack_3d0;
    puStack_3bc = (undefined4 *)0x0;
    uStack_3cc = 0;
    FUN_00401660(apvStack_324,0,0xffffffff);
    (**(code **)(iStack_128 + 4))();
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))(3);
    if (0xf < uStack_2d8) {
      puStack_3bc = (undefined4 *)0x769949;
      _free(pvStack_2ec);
      return;
    }
    uStack_2d8 = 0xf;
    uStack_2dc = 0;
    pvStack_2ec = (void *)((uint)pvStack_2ec & 0xffffff00);
    if (0xf < uStack_32c) {
      puStack_3bc = (undefined4 *)0x769974;
      _free(pvStack_340);
      return;
    }
    uStack_32c = 0xf;
    uStack_330 = 0;
    pvStack_340 = (void *)((uint)pvStack_340 & 0xffffff00);
    if (0xf < uStack_268) {
      puStack_3bc = (undefined4 *)0x76999f;
      _free(pvStack_27c);
      return;
    }
    uStack_268 = 0xf;
    uStack_26c = 0;
    pvStack_27c = (void *)((uint)pvStack_27c & 0xffffff00);
    if (0xf < uStack_2f4) {
      puStack_3bc = (undefined4 *)0x7699cd;
      _free(pvStack_308);
      return;
    }
    uStack_2f4 = 0xf;
    uStack_2f8 = 0;
    pvStack_308 = (void *)((uint)pvStack_308 & 0xffffff00);
    if (0xf < uStack_284) {
      puStack_3bc = (undefined4 *)0x7699fb;
      _free(pvStack_298);
      return;
    }
    uStack_284 = 0xf;
    uStack_288 = 0;
    pvStack_298 = (void *)((uint)pvStack_298 & 0xffffff00);
    if (0xf < uStack_2a0) {
      puStack_3bc = (undefined4 *)0x769a29;
      _free(pvStack_2b4);
      return;
    }
    uStack_2a0 = 0xf;
    uStack_2a4 = 0;
    pvStack_2b4 = (void *)((uint)pvStack_2b4 & 0xffffff00);
    if (0xf < uStack_2bc) {
      puStack_3bc = (undefined4 *)0x769a57;
      _free(pvStack_2d0);
      return;
    }
    uStack_2bc = 0xf;
    uStack_2c0 = 0;
    pvStack_2d0 = (void *)((uint)pvStack_2d0 & 0xffffff00);
    if (0xf < uStack_230) {
      puStack_3bc = (undefined4 *)0x769a85;
      _free(pvStack_244);
      return;
    }
    uStack_230 = 0xf;
    uStack_234 = 0;
    pvStack_244 = (void *)((uint)pvStack_244 & 0xffffff00);
    if (0xf < uStack_24c) {
      puStack_3bc = (undefined4 *)0x769ab3;
      _free(pvStack_260);
      return;
    }
    uStack_24c = 0xf;
    uStack_250 = 0;
    pvStack_260 = (void *)((uint)pvStack_260 & 0xffffff00);
  }
  else {
    if (*(char *)(unaff_retaddr + 0x10) != '\x01') {
      uStack_1ec = 0xf;
      uStack_1f0 = 0;
      pvStack_200 = (void *)((uint)pvStack_200 & 0xffffff00);
      FUN_00401740();
      puStack_8 = (undefined1 *)0x1b;
      FUN_00796d50();
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_1ec) {
        _free(pvStack_200);
        return;
      }
      uStack_1ec = 0xf;
      uStack_1f0 = 0;
      pvStack_200 = (void *)((uint)pvStack_200 & 0xffffff00);
      pvVar8 = (void *)0x8;
      pcStack_3a0 = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_360 = 0xf;
      uStack_364 = 0;
      local_374 = (undefined1 *)((uint)local_374 & 0xffffff00);
      puStack_3a4 = (undefined1 *)0x768de3;
      FUN_00401660();
      puStack_3bc = &local_378;
      uStack_10 = 0x1c;
      uStack_3c0 = 0x768e0d;
      FUN_00401660();
      apvStack_324[0] = pvVar8;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (unaff_EBP < 0x10) {
        ExceptionList = pvStack_38;
        return;
      }
      goto LAB_00769adb;
    }
    uStack_1d0 = 0xf;
    uStack_1d4 = 0;
    pvStack_1e4 = (void *)((uint)pvStack_1e4 & 0xffffff00);
    FUN_00401740();
    puStack_8 = (undefined1 *)0x19;
    FUN_00796d50();
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_1d0) {
      _free(pvStack_1e4);
      return;
    }
    uStack_1d0 = 0xf;
    uStack_1d4 = 0;
    pvStack_1e4 = (void *)((uint)pvStack_1e4 & 0xffffff00);
    uStack_2e8 = 0xf;
    pvStack_2ec = (void *)0x0;
    uStack_2fc = 0;
    FUN_00401740();
    local_374 = (undefined1 *)&pcStack_3a8;
    puStack_8 = (undefined1 *)0x1a;
    puStack_3a4 = (undefined1 *)((uint)puStack_3a4 & 0xffffff00);
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  if (uStack_310 < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
LAB_00769adb:
  puStack_3bc = (undefined4 *)0x769ae1;
  _free(apvStack_324[0]);
  return;
}


// ==== FUN_00769b00 @ 0x00769b00 ====

undefined4 FUN_00769b00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5280007) {
    FUN_00768840(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5280009) {
    (**(code **)(*DAT_00b5af2c + 8))(4);
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
  if (iVar1 == 0x528000b) {
    FUN_00768ce0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_00769b80 @ 0x00769b80 ====

undefined4 FUN_00769b80(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00769b00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00769bb0 @ 0x00769bb0 ====

void FUN_00769bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00768820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00769bd0 @ 0x00769bd0 ====

void FUN_00769bd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4428;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00769c00 @ 0x00769c00 ====

void FUN_00769c00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4434;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aed0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aed0 = in_ECX;
  return;
}


// ==== FUN_00769c60 @ 0x00769c60 ====

void FUN_00769c60(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aed0 = 0;
  *in_ECX = &PTR_FUN_009f4428;
  return;
}


// ==== FUN_00769c80 @ 0x00769c80 ====

void FUN_00769c80(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_10c [16];
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 *puStack_e8;
  undefined1 *puStack_dc;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 *puStack_c4;
  undefined4 uStack_a0;
  char *pcStack_9c;
  void *local_7c;
  undefined1 auStack_78 [12];
  void *local_6c;
  uint local_68;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined1 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995950;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x14)) {
  case 0:
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    ExceptionList = &pvStack_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (piVar2 == (int *)0x0) {
      pcStack_9c = (char *)0x769cd8;
      FUN_00401830();
      local_4 = 0;
      pcStack_9c = (char *)0x769ce9;
      FUN_00406880();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    uStack_60 = 0;
    pcStack_9c = (char *)0x8;
    local_4 = 1;
    uStack_a0 = 0x769d24;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0xffffffff;
    FUN_00401660();
    uStack_a0 = uVar1;
    uStack_a0 = FUN_00793390();
    puStack_c4 = (undefined4 *)0x769d4e;
    FUN_00765c50();
    (**(code **)(*piVar2 + 4))();
    uStack_58 = 0xf;
    uStack_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    puStack_c4 = (undefined4 *)0x8;
    uStack_2c = 2;
    uStack_c8 = 0x769d7b;
    uStack_d0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c8 = 0xffffffff;
    uStack_cc = 0;
    uStack_d4 = 0x769d88;
    FUN_00401660();
    puStack_e8 = auStack_78;
    uStack_5c = 0;
    uStack_ec = 0x769da2;
    FUN_0068e600();
    puStack_e8 = (undefined1 *)0x769da9;
    (**(code **)(*piVar2 + 8))();
    puStack_e8 = (undefined1 *)0x1900065;
    uStack_ec = 8;
    uStack_f0 = 0x769dbb;
    uStack_f8 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_f0 = 0xffffffff;
    uStack_f4 = 0;
    uStack_fc = 0x769dc8;
    FUN_00401660();
    puStack_dc = auStack_10c;
    FUN_0068e600(&uStack_a0);
    (**(code **)(*piVar2 + 8))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x769e36;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x3;
    break;
  case 2:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x769e8b;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x4;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x769f0c;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x6;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x769f61;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x7;
    break;
  case 5:
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x769ee0;
    ExceptionList = &pvStack_c;
    uStack_a0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x5;
    break;
  default:
    pcStack_9c = s_Teleport_SN_Open_Fail_____009f4404;
    local_68 = 0xf;
    local_6c = (void *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    uStack_a0 = 0x769f9e;
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_4 = 8;
    pcStack_9c = (char *)0x769fb3;
    FUN_00796d50();
    local_4 = 0xffffffff;
    if (0xf < local_68) {
      pcStack_9c = (char *)0x769fd6;
      _free(local_7c);
      return;
    }
    local_68 = 0xf;
    local_6c = (void *)0x0;
    pcStack_9c = (char *)0x8;
    uStack_a0 = 0x769ff7;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a0 = 0xffffffff;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    FUN_00401660();
    puStack_c4 = &uStack_50;
    uStack_a0 = 0xf;
    pvStack_c = (void *)0x9;
    uStack_c8 = 0x76a03a;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_58 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    puStack_c4 = (undefined4 *)0x76a057;
    _free(local_6c);
    return;
  }
  FUN_00765c50();
  (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0076a090 @ 0x0076a090 ====

undefined4 FUN_0076a090(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0xf02000c) {
    FUN_00769c80(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0xf02000e) {
    (**(code **)(*DAT_00b5af2c + 8))(4);
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
  return 0;
}


// ==== FUN_0076a100 @ 0x0076a100 ====

undefined4 FUN_0076a100(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0076a090(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0076a130 @ 0x0076a130 ====

void FUN_0076a130(byte param_1)

{
  void *in_ECX;
  
  FUN_00769c60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076a150 @ 0x0076a150 ====

void FUN_0076a150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f44ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076a180 @ 0x0076a180 ====

void FUN_0076a180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f44f8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aed4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aed4 = in_ECX;
  return;
}


// ==== FUN_0076a1b0 @ 0x0076a1b0 ====

void FUN_0076a1b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aed4 = 0;
  *in_ECX = &PTR_FUN_009f44ec;
  return;
}


// ==== FUN_0076a1d0 @ 0x0076a1d0 ====

void FUN_0076a1d0(void)

{
  int iVar1;
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  uint uStack_4c;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009959d8;
  pvStack_c = ExceptionList;
  uStack_4c = 3;
  iStack_50 = 0x76a1f6;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x16)) {
  case 0:
    iStack_50 = 0x76a219;
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 == 0) {
      iStack_50 = 0;
    }
    else {
      iStack_50 = 0x76a224;
      iStack_50 = FUN_00511760();
    }
    *(undefined4 *)(iStack_50 + 4) = *(undefined4 *)(unaff_retaddr + 0x10);
    *(undefined2 *)(iStack_50 + 8) = *(undefined2 *)(unaff_retaddr + 0x14);
    *(undefined1 *)(iStack_50 + 10) = 1;
    uStack_54 = 0x76a244;
    FUN_00797a20();
    ExceptionList = pvStack_10;
    return;
  case 1:
    iStack_50 = 0x2bc002e;
    uStack_54 = 8;
    uStack_58 = 0x76a26b;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a275;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    break;
  case 2:
    iStack_50 = 0x2bc002f;
    uStack_54 = 8;
    uStack_58 = 0x76a329;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a333;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
    break;
  case 3:
    iStack_50 = 0x2bc0004;
    uStack_54 = 8;
    uStack_58 = 0x76a352;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a35c;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    goto LAB_0076a4fb;
  case 4:
    iStack_50 = 0x2bc002c;
    uStack_54 = 8;
    uStack_58 = 0x76a37b;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a385;
    FUN_00765c50();
    pvStack_10 = (void *)0x4;
    break;
  case 5:
    iStack_50 = 0x2bc002c;
    uStack_54 = 8;
    uStack_58 = 0x76a3a4;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a3ae;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    goto LAB_0076a4fb;
  case 6:
    iStack_50 = 0x2bc0031;
    uStack_54 = 8;
    uStack_58 = 0x76a3cd;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a3d7;
    FUN_00765c50();
    pvStack_10 = (void *)0x6;
    break;
  case 7:
    iStack_50 = 0x2bc0030;
    uStack_54 = 8;
    uStack_58 = 0x76a3f6;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a400;
    FUN_00765c50();
    pvStack_10 = (void *)0x7;
    goto LAB_0076a4fb;
  case 8:
    iStack_50 = 0x2bc0065;
    uStack_54 = 8;
    uStack_58 = 0x76a41f;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a429;
    FUN_00765c50();
    pvStack_10 = (void *)0x8;
    break;
  case 9:
    iStack_50 = 0x2bc0066;
    uStack_54 = 8;
    uStack_58 = 0x76a448;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a452;
    FUN_00765c50();
    pvStack_10 = (void *)0x9;
    goto LAB_0076a4fb;
  case 10:
    iStack_50 = 0x2bc007d;
    uStack_54 = 8;
    uStack_58 = 0x76a471;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a47b;
    FUN_00765c50();
    pvStack_10 = (void *)0xa;
    break;
  case 0xb:
    iStack_50 = 0x2bc0032;
    uStack_54 = 8;
    uStack_58 = 0x76a2ca;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a2d4;
    FUN_00765c50();
    puStack_8 = auStack_70;
    pvStack_10 = (void *)0x1;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xc:
    iStack_50 = 0x2bc006b;
    uStack_54 = 8;
    uStack_58 = 0x76a49a;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a4a4;
    FUN_00765c50();
    pvStack_10 = (void *)0xb;
    goto LAB_0076a4fb;
  case 0xd:
    iStack_50 = 0x2bc0077;
    uStack_54 = 8;
    uStack_58 = 0x76a4c0;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a4ca;
    FUN_00765c50();
    pvStack_10 = (void *)0xc;
    break;
  case 0xe:
    iStack_50 = 0x7d50005;
    uStack_54 = 0;
    uStack_58 = 0x76a4e9;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x76a4f3;
    FUN_00765c50();
    pvStack_10 = (void *)0xd;
LAB_0076a4fb:
    puStack_8 = auStack_70;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0076a29d;
  default:
    iStack_50 = 0x2bc002d;
    uStack_54 = 8;
    uStack_58 = 0x76a532;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_64 = 0x76a556;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0xe;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401660(&iStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (uStack_58 < 0x10) {
      ExceptionList = (void *)0xf;
      return;
    }
    _free(pvStack_6c);
    return;
  }
  puStack_8 = auStack_70;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0076a29d:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0076a600 @ 0x0076a600 ====

int FUN_0076a600(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int unaff_retaddr;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ab34 + 8))(param_2);
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(s_Invalid_Location_009f44d0,0x10);
    return unaff_retaddr;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  pcVar4 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar4 - (iVar3 + 3));
  return unaff_retaddr;
}


// ==== FUN_0076a690 @ 0x0076a690 ====

/* WARNING: Removing unreachable block (ram,0x0076a968) */

void FUN_0076a690(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  void *pvStack_188;
  uint uStack_138;
  void *pvStack_124;
  uint uStack_110;
  undefined1 auStack_a8 [20];
  void *pvStack_94;
  undefined4 uStack_8c;
  undefined4 uStack_84;
  uint uStack_80;
  undefined1 uStack_74;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 uStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  void *pvStack_38;
  undefined1 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995a76;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    ExceptionList = &pvStack_c;
    iVar1 = (**(code **)(*DAT_00b5ac98 + 4))();
    if (iVar1 == 0) {
      FUN_00401830();
      uStack_4 = 0;
      FUN_00406880();
      uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
    if (piVar2 == (int *)0x0) {
      FUN_00401830();
      uStack_4 = 1;
      FUN_00406880();
      uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar3 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (piVar3 == (int *)0x0) {
      FUN_00401830();
      uStack_4 = 2;
      FUN_00406880();
      uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    iVar1 = (**(code **)(*piVar2 + 0x14))();
    if (iVar1 == 0) {
      FUN_00401830();
      uStack_4 = 3;
      FUN_00406880();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_4 = 4;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    pvStack_188 = (void *)0x76a84b;
    FUN_00401660();
    FUN_00793480();
    FUN_00401660();
    (**(code **)(*piVar3 + 4))();
    iVar1 = (**(code **)(*DAT_00b5ac98 + 8))();
    piVar2 = (int *)(**(code **)(*DAT_00b5ab04 + 8))();
    while (piVar2 != (int *)0x0) {
      puVar4 = (undefined4 *)(**(code **)(*piVar2 + 4))();
      uStack_40 = *puVar4;
      if (puVar4[2] == iVar1) {
        uStack_80 = 0xf;
        uStack_84 = 0;
        pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
        uStack_60 = 0xf;
        uStack_64 = 0;
        uStack_74 = 0;
        uStack_44 = 0xf;
        uStack_48 = 0;
        uStack_58 = 0;
        uStack_2c = 7;
        FUN_00401740();
        FUN_0076a600();
        uStack_2c = 8;
        FUN_00401660();
        uStack_2c = 7;
        FUN_004e6c20();
        (**(code **)(*DAT_00b5a794 + 8))();
        uStack_3c = 9;
        FUN_00401660();
        uStack_3c = 7;
        if (0xf < uStack_138) {
          _free((void *)0x0);
          return;
        }
        uStack_138 = 0xf;
        uStack_8c = 8;
        FUN_00401660(auStack_a8,0,0xffffffff);
        (**(code **)(*piVar3 + 8))();
        FUN_0040a7d0();
        FUN_004e67a0();
        uStack_2c = 4;
        if (0xf < uStack_80) {
          _free(pvStack_94);
          return;
        }
        uStack_80 = 0xf;
        uStack_84 = 0;
        pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
      }
      piVar2 = (int *)(**(code **)(*DAT_00b5ab04 + 0xc))();
    }
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))();
    pvStack_124 = pvStack_188;
    break;
  default:
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0xd;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_110 < 0x10) {
      ExceptionList = pvStack_38;
      return;
    }
    break;
  case 2:
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    pvStack_188 = (void *)0x76aaf9;
    FUN_00401660();
    pvStack_c = (void *)0xa;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    pvStack_124 = pvStack_188;
    break;
  case 3:
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    pvStack_188 = (void *)0x76ab76;
    FUN_00401660();
    pvStack_c = (void *)0xb;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    pvStack_124 = pvStack_188;
    break;
  case 4:
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    pvStack_188 = (void *)0x76abf3;
    FUN_00401660();
    pvStack_c = (void *)0xc;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    pvStack_124 = pvStack_188;
  }
  _free(pvStack_124);
  return;
}


// ==== FUN_0076ad00 @ 0x0076ad00 ====

undefined4 FUN_0076ad00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5280000) {
    FUN_0076a690(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5280002) {
    FUN_0076a1d0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0076ad50 @ 0x0076ad50 ====

undefined4 FUN_0076ad50(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0076ad00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0076ad80 @ 0x0076ad80 ====

void FUN_0076ad80(byte param_1)

{
  void *in_ECX;
  
  FUN_0076a1b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076ada0 @ 0x0076ada0 ====

void FUN_0076ada0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4618;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076add0 @ 0x0076add0 ====

void FUN_0076add0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4624;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aed8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aed8 = in_ECX;
  return;
}


// ==== FUN_0076ae00 @ 0x0076ae00 ====

void FUN_0076ae00(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aed8 = 0;
  *in_ECX = &PTR_FUN_009f4618;
  return;
}


// ==== FUN_0076ae20 @ 0x0076ae20 ====

void FUN_0076ae20(void)

{
  undefined4 *puVar1;
  int unaff_retaddr;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995aa8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    uStack_5c = 0x76ae6e;
    uStack_5c = (**(code **)(*DAT_00b5ac1c + 0x14))();
    uStack_60 = 0x76ae74;
    FUN_00827bf0();
    (**(code **)(*DAT_00b5a790 + 4))();
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b64f0;
      *(undefined2 *)(puVar1 + 1) = 0;
      *(undefined2 *)((int)puVar1 + 6) = 0;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined1 *)((int)puVar1 + 10) = 1;
    }
    puVar1[1] = *(undefined4 *)(unaff_retaddr + 0x14);
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(unaff_retaddr + 0x18);
    *(undefined1 *)((int)puVar1 + 10) = 1;
    uStack_5c = 0x76aec9;
    FUN_00797a20();
    ExceptionList = pvStack_10;
    return;
  case 1:
    uStack_5c = 0;
    uStack_60 = 0x76af3e;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0x76af48;
    FUN_00765c50();
    puStack_8 = auStack_78;
    pvStack_10 = (void *)0x1;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    uStack_5c = 0;
    uStack_60 = 0x76aee1;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0x76aeeb;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    break;
  default:
    uStack_5c = 0;
    uStack_60 = 0x76b012;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_6c = 0x76b030;
    FUN_00401660();
    puStack_8 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    pvStack_10 = (void *)0x4;
    uStack_74 = 0;
    FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_10;
      return;
    }
    uStack_5c = 0x76b075;
    _free(pvStack_44);
    return;
  case 5:
    uStack_5c = 0;
    uStack_60 = 0x76af9f;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0x76afa9;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
    break;
  case 6:
    uStack_5c = 0;
    uStack_60 = 0x76afc8;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0x76afd2;
    FUN_00765c50();
    puStack_8 = auStack_78;
    pvStack_10 = (void *)0x3;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0076af0f;
  }
  puStack_8 = auStack_78;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0076af0f:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0076b0b0 @ 0x0076b0b0 ====

int FUN_0076b0b0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int unaff_retaddr;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ab34 + 8))(param_2);
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(s_Invalid_Location_009f45fc,0x10);
    return unaff_retaddr;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  pcVar4 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar4 - (iVar3 + 3));
  return unaff_retaddr;
}


// ==== FUN_0076b140 @ 0x0076b140 ====

/* WARNING: Removing unreachable block (ram,0x0076b336) */
/* WARNING: Removing unreachable block (ram,0x0076b415) */
/* WARNING: Removing unreachable block (ram,0x0076b260) */
/* WARNING: Removing unreachable block (ram,0x0076b667) */
/* WARNING: Removing unreachable block (ram,0x0076b834) */
/* WARNING: Removing unreachable block (ram,0x0076b694) */
/* WARNING: Removing unreachable block (ram,0x0076b69e) */
/* WARNING: Removing unreachable block (ram,0x0076b6a1) */
/* WARNING: Removing unreachable block (ram,0x0076b6a6) */
/* WARNING: Removing unreachable block (ram,0x0076b6b2) */
/* WARNING: Removing unreachable block (ram,0x0076b6c0) */
/* WARNING: Removing unreachable block (ram,0x0076b6cc) */
/* WARNING: Removing unreachable block (ram,0x0076b6df) */
/* WARNING: Removing unreachable block (ram,0x0076b6e3) */

void FUN_0076b140(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *unaff_EBX;
  byte bStack_14d;
  int *piStack_118;
  uint uStack_114;
  int iStack_10c;
  void *pvStack_100;
  uint uStack_ec;
  void *pvStack_c4;
  undefined1 auStack_bc [8];
  undefined4 uStack_b4;
  uint uStack_b0;
  void *pvStack_a8;
  uint uStack_a0;
  void *pvStack_98;
  uint uStack_94;
  undefined4 uStack_88;
  uint uStack_84;
  void *pvStack_6c;
  void *local_5c;
  uint uStack_58;
  void *pvStack_50;
  uint local_48;
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined1 uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995b3d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  FUN_00404230();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
    return;
  }
  if (*(char *)(param_1 + 0x14) == '\0') {
    piVar2 = (int *)(**(code **)(*DAT_00b5ab38 + 8))();
    iVar3 = (**(code **)(*piVar2 + 4))();
    iVar4 = (**(code **)(*DAT_00b5aee8 + 8))();
    if (iVar4 == 0) {
      FUN_00401740();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puStack_8 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    bStack_14d = 0;
    FUN_00401660();
    FUN_00793600();
    FUN_00401660();
    (**(code **)(iRam0000000f + 4))();
    if ((uint)*(byte *)(iVar3 + 4) != *(uint *)(iVar3 + 0x9c)) {
      FUN_00401740();
      uStack_30 = 3;
      FUN_00406880();
      uStack_30 = 2;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(char *)(iVar3 + 4) != '\0') {
      while( true ) {
        uStack_94 = 0xf;
        pvStack_98 = (void *)0x0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
        uStack_b0 = 0xf;
        uStack_b4 = 0;
        pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
        uStack_30 = 6;
        FUN_00401740();
        FUN_0076b0b0();
        uStack_30 = 7;
        FUN_00401660();
        uStack_30 = 6;
        FUN_004e6c20();
        FUN_00401740();
        FUN_00401740();
        FUN_00404230();
        uStack_30 = 8;
        FUN_00401660();
        uStack_30 = 6;
        if ((void *)0xf < pvStack_3c) {
          _free(pvStack_50);
          return;
        }
        pvStack_3c = (void *)0xf;
        uStack_40 = 0;
        pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
        FUN_004e6c20();
        FUN_00401740();
        FUN_00401740();
        FUN_00404230();
        uStack_30 = 9;
        FUN_00401660();
        uStack_30 = 6;
        if (0xf < uStack_58) {
          _free(pvStack_6c);
          return;
        }
        uStack_58 = 0xf;
        local_5c = (void *)0x0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
        FUN_004e6c20();
        (**(code **)(*DAT_00b5a794 + 8))();
        uStack_40._0_1_ = 10;
        FUN_00401660();
        uStack_40 = CONCAT31(uStack_40._1_3_,6);
        if (0xf < uStack_84) {
          _free(pvStack_98);
          return;
        }
        uStack_a0 = (uint)*(ushort *)((uint)bStack_14d * 0x10 + 0xc + iVar3);
        uStack_84 = 0xf;
        uStack_88 = 0;
        pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
        FUN_00401660(auStack_bc,0,0xffffffff);
        (**(code **)(*piStack_118 + 8))();
        if (0xf < uStack_b0) {
          _free(pvStack_c4);
          return;
        }
        uStack_b0 = 0xf;
        uStack_b4 = 0;
        uStack_30 = 2;
        if (0xf < uStack_94) {
          _free(pvStack_a8);
          return;
        }
        bStack_14d = bStack_14d + 1;
        uStack_94 = 0xf;
        pvStack_98 = (void *)0x0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
        if (*(byte *)(iStack_10c + 4) <= bStack_14d) break;
        iVar3 = iStack_10c;
      }
    }
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))();
    if (uStack_114 < 0x10) {
      ExceptionList = pvStack_3c;
      return;
    }
  }
  else if (*(char *)(param_1 + 0x14) == '\x01') {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0xb;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_114 < 0x10) {
      ExceptionList = pvStack_3c;
      return;
    }
  }
  else {
    FUN_00401740();
    local_4 = 0xc;
    FUN_00796d50();
    local_4 = 0xffffffff;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0xd;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_ec < 0x10) {
      ExceptionList = pvStack_3c;
      return;
    }
    unaff_EBX = pvStack_100;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_0076b8e0 @ 0x0076b8e0 ====

undefined4 FUN_0076b8e0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5170000) {
    FUN_0076b140(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5170002) {
    FUN_0076ae20(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0076b930 @ 0x0076b930 ====

undefined4 FUN_0076b930(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0076b8e0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0076b960 @ 0x0076b960 ====

void FUN_0076b960(byte param_1)

{
  void *in_ECX;
  
  FUN_0076ae00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076b980 @ 0x0076b980 ====

void FUN_0076b980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4878;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076b9a0 @ 0x0076b9a0 ====

void FUN_0076b9a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4884;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aedc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aedc = in_ECX;
  return;
}


// ==== FUN_0076ba00 @ 0x0076ba00 ====

void FUN_0076ba00(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aedc = 0;
  *in_ECX = &PTR_FUN_009f4878;
  return;
}


// ==== FUN_0076ba20 @ 0x0076ba20 ====

/* WARNING: Removing unreachable block (ram,0x0076bdd4) */
/* WARNING: Removing unreachable block (ram,0x0076bd72) */
/* WARNING: Removing unreachable block (ram,0x0076bcd8) */
/* WARNING: Removing unreachable block (ram,0x0076bc3e) */
/* WARNING: Removing unreachable block (ram,0x0076bc8b) */
/* WARNING: Removing unreachable block (ram,0x0076bd25) */
/* WARNING: Removing unreachable block (ram,0x0076c06b) */
/* WARNING: Removing unreachable block (ram,0x0076bbf1) */

void FUN_0076ba20(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char ****ppppcVar4;
  void *local_8c;
  void *local_88;
  void *pvStack_78;
  uint local_74;
  undefined4 uStack_6c;
  void *pvStack_68;
  uint uStack_54;
  char ****appppcStack_40 [3];
  undefined2 local_34;
  undefined2 local_32;
  undefined1 uStack_30;
  uint uStack_2c;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995bf8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  FUN_00404230();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  if (0xf < local_74) {
    _free(local_88);
    return;
  }
  local_32 = *(undefined2 *)(param_1 + 0x12);
  local_34 = *(undefined2 *)(param_1 + 0x10);
  piVar3 = (int *)(**(code **)(*DAT_00b5ab94 + 8))();
  if (piVar3 == (int *)0x0) {
    FUN_00401740();
    FUN_00404230();
    puStack_8 = (undefined1 *)0x1;
    FUN_00796d50();
    if (pvStack_78 < (void *)0x10) {
      ExceptionList = pvStack_10;
      return;
    }
  }
  else {
    (**(code **)(*piVar3 + 4))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    FUN_00401660();
    pvStack_10 = (void *)0x2;
    (**(code **)(*DAT_00b5ac40 + 0x20))();
    uStack_6c = 0;
    pvStack_68 = (void *)0x0;
    uStack_18 = 3;
    FUN_00401740();
    uStack_18 = 4;
    FUN_00406720();
    uStack_18 = 3;
    FUN_00401740();
    uStack_18 = 5;
    FUN_00406720();
    uStack_18 = 3;
    FUN_00401740();
    uStack_18 = 6;
    FUN_00406720();
    uStack_18 = 3;
    FUN_00401740();
    uStack_18 = 7;
    FUN_00406720();
    uStack_18 = 3;
    FUN_00401740();
    uStack_18 = 8;
    FUN_00406720();
    uStack_18 = 3;
    FUN_00401740();
    uStack_18 = 9;
    FUN_00406720();
    uStack_18 = 3;
    iVar2 = *DAT_00b5ad00;
    (**(code **)(*DAT_00b5a97c + 0xc))();
    (**(code **)(iVar2 + 4))();
    piVar3 = (int *)(**(code **)(*DAT_00b5ab84 + 8))();
    (**(code **)(*piVar3 + 4))();
    uStack_20._0_1_ = 10;
    FUN_00401740(&DAT_009f472c,2);
    FUN_00404230(&uStack_6c);
    uStack_20._0_1_ = 0xb;
    FUN_00406720();
    uStack_20._0_1_ = 10;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401740(&DAT_009f4730,2);
    FUN_00404230(&uStack_6c);
    uStack_20._0_1_ = 0xc;
    FUN_00406720();
    uStack_20._0_1_ = 10;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401740(&DAT_009f4734,2);
    FUN_00404230(&uStack_6c);
    uStack_20._0_1_ = 0xd;
    FUN_00406720();
    uStack_20._0_1_ = 10;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401740(&DAT_009f4738,2);
    FUN_00404230(&uStack_6c);
    uStack_20._0_1_ = 0xe;
    FUN_00406720();
    uStack_20._0_1_ = 10;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401740(&DAT_009f473c,2);
    FUN_00404230(&uStack_6c);
    uStack_20._0_1_ = 0xf;
    FUN_00406720();
    uStack_20._0_1_ = 10;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401740(&DAT_009f4740,2);
    FUN_00404230(&uStack_6c);
    uStack_20._0_1_ = 0x10;
    FUN_00406720();
    uStack_20._0_1_ = 10;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00404a40();
    uStack_20._0_1_ = 0x11;
    FUN_00401660();
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    uStack_20 = CONCAT31(uStack_20._1_3_,2);
    if (pvStack_78 != (void *)0x0) {
      FUN_00405de0();
      _free(pvStack_78);
      return;
    }
    if (uStack_2c < 0x10) {
      appppcStack_40[0] = (char ****)appppcStack_40;
    }
    ppppcVar4 = appppcStack_40[0];
    do {
      cVar1 = *(char *)ppppcVar4;
      ppppcVar4 = (char ****)((int)ppppcVar4 + 1);
    } while (cVar1 != '\0');
    FUN_00401740(appppcStack_40[0]);
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (uStack_14 < 0x10) {
      ExceptionList = pvStack_10;
      return;
    }
    local_8c = pvStack_28;
  }
  _free(local_8c);
  return;
}


// ==== FUN_0076c150 @ 0x0076c150 ====

/* WARNING: Removing unreachable block (ram,0x0076c6dd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0076c150(int param_1)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  undefined2 extraout_var;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  int *unaff_EBP;
  undefined1 *puVar9;
  uint unaff_EDI;
  undefined1 auStack_140 [4];
  undefined1 uStack_13c;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined1 *puStack_124;
  undefined *puStack_120;
  void **ppvStack_f8;
  uint uStack_f4;
  int *local_f0;
  undefined4 uStack_ec;
  uint uVar10;
  undefined1 *local_e0;
  int *local_dc;
  void *local_c0;
  undefined1 *local_bc;
  void *pvStack_b4;
  int *piStack_b0;
  uint uStack_ac;
  uint local_a8;
  undefined1 *puStack_a4;
  undefined1 *local_a0;
  int *local_98;
  undefined1 *puStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  void *pvStack_68;
  undefined1 *local_64;
  void *pvStack_60;
  uint uStack_54;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined1 auStack_48 [16];
  uint uStack_38;
  void *pvStack_34;
  undefined1 uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995d06;
  pvStack_c = ExceptionList;
  local_a0 = (undefined1 *)&uStack_f4;
  ppvStack_f8 = (void **)0x35;
  local_dc = (int *)0xf;
  local_e0 = (undefined1 *)0x0;
  local_f0 = (int *)((uint)local_f0 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740();
  ppvStack_f8 = &local_c0;
  FUN_00404230();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  if (0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_a0 = (undefined1 *)CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x16));
  uVar4 = *(ushort *)(param_1 + 0x14);
  local_98 = *(int **)(param_1 + 0x14);
  puVar9 = (undefined1 *)CONCAT22((short)((uint)param_1 >> 0x10),uVar4);
  local_64 = puVar9;
  local_98 = (int *)(**(code **)(*DAT_00b5ab94 + 8))();
  if (local_98 == (int *)0x0) {
    puStack_a4 = (undefined1 *)((uint)puStack_a4 & 0xffff);
    puStack_74 = (undefined1 *)&ppvStack_f8;
    local_e0 = (undefined1 *)0xf;
    uStack_f4 = uStack_f4 & 0xffffff00;
    local_dc = (int *)(uint)uVar4;
    FUN_00401740();
    FUN_00404230();
    puStack_8 = (undefined1 *)0x1;
    FUN_00796d50();
    puStack_8 = (undefined1 *)0xffffffff;
    if ((void *)0xf < pvStack_4c) {
      local_dc = (int *)0x76c28d;
      _free(pvStack_60);
      return;
    }
    puStack_a4 = (undefined1 *)&ppvStack_f8;
    local_e0 = (undefined1 *)0xf;
    uStack_f4 = uStack_f4 & 0xffffff00;
    local_dc = (int *)(uint)uVar4;
    FUN_00401740();
    FUN_00404230();
    uStack_ac = 0xf;
    piStack_b0 = (int *)0x0;
    local_c0 = (void *)((uint)local_c0 & 0xffffff00);
    local_dc = (int *)0x0;
    local_e0 = auStack_48;
    puStack_8 = (undefined1 *)0x3;
    FUN_00401660();
    piVar5 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
    local_dc = (int *)0x76c314;
    FUN_00792c00();
    puStack_a4 = (undefined1 *)&uStack_f4;
    ppvStack_f8 = (void **)0xffffffff;
    local_dc = (int *)0xf;
    local_e0 = (undefined1 *)0x0;
    local_f0 = (int *)((uint)local_f0 & 0xffffff00);
    FUN_00401660();
    ppvStack_f8 = (void **)0x76c33e;
    (**(code **)(*piVar5 + 4))();
    ppvStack_f8 = (void **)0x76c349;
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    ppvStack_f8 = (void **)0x3;
    (**(code **)(*DAT_00b5acd4 + 4))();
    if (0xf < unaff_EDI) {
      _free((void *)0x76c2f7);
      return;
    }
    if (uStack_54 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    pvVar8 = pvStack_68;
  }
  else {
    puStack_a4 = (undefined1 *)(**(code **)(*DAT_00b5aee8 + 8))();
    if (puStack_a4 == (undefined1 *)0x0) {
      local_dc = (int *)s_pDialog____NULL_009f47d4;
      uStack_ac = 0xf;
      piStack_b0 = (int *)0x0;
      local_c0 = (void *)((uint)local_c0 & 0xffffff00);
      local_e0 = (undefined1 *)0x76c3bc;
      FUN_00401740();
      puStack_8 = (undefined1 *)0x4;
      local_dc = (int *)0x76c3d1;
      FUN_00406880();
      if (uStack_ac < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      local_dc = (int *)0x76c3e4;
      _free(local_c0);
      return;
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    uStack_28 = 0;
    puStack_74 = (undefined1 *)((uint)uVar4 << 0x10);
    puStack_8 = (undefined1 *)0x5;
    (**(code **)(*local_98 + 4))();
    local_dc = (int *)0x1;
    local_e0 = (undefined1 *)0x76c430;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    local_e0 = (undefined1 *)0xffffffff;
    uStack_ec = (char *)0x76c440;
    FUN_00401660();
    local_e0 = puVar9;
    (**(code **)(*DAT_00b5ac40 + 0x20))();
    uStack_70 = 0;
    uStack_6c = 0;
    pvStack_68 = (void *)0x0;
    uStack_ec = s_<COUNT0>_009f47e4;
    uStack_18._0_1_ = 6;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    uVar10 = unaff_EDI >> 8;
    local_f0 = (int *)0x76c481;
    FUN_00401740();
    uStack_18._0_1_ = 7;
    uStack_ec = (char *)0x76c497;
    FUN_00406720();
    uStack_18._0_1_ = 6;
    if (0xf < local_bc) {
      uStack_ec = (char *)0x76c4af;
      _free((void *)(uVar10 << 8));
      return;
    }
    uStack_ec = s_<COUNT1>_009f47f0;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    local_f0 = (int *)0x76c4ce;
    FUN_00401740();
    uStack_18._0_1_ = 8;
    uStack_ec = (char *)0x76c4e4;
    FUN_00406720();
    uStack_18._0_1_ = 6;
    if (0xf < local_bc) {
      uStack_ec = (char *)0x76c4fc;
      _free((void *)(uVar10 << 8));
      return;
    }
    uStack_ec = s_<COUNT2>_009f47fc;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    local_f0 = (int *)0x76c51b;
    FUN_00401740();
    uStack_18._0_1_ = 9;
    uStack_ec = (char *)0x76c531;
    FUN_00406720();
    uStack_18._0_1_ = 6;
    if (0xf < local_bc) {
      uStack_ec = (char *)0x76c549;
      _free((void *)(uVar10 << 8));
      return;
    }
    uStack_ec = s_<COUNT3>_009f4808;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    local_f0 = (int *)0x76c568;
    FUN_00401740();
    uStack_18._0_1_ = 10;
    uStack_ec = (char *)0x76c57e;
    FUN_00406720();
    uStack_18._0_1_ = 6;
    if (0xf < local_bc) {
      uStack_ec = (char *)0x76c596;
      _free((void *)(uVar10 << 8));
      return;
    }
    uStack_ec = s_<CHAOTICNUM>_009f4814;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    local_f0 = (int *)0x76c5b5;
    FUN_00401740();
    uStack_18._0_1_ = 0xb;
    uStack_ec = (char *)0x76c5cb;
    FUN_00406720();
    uStack_18._0_1_ = 6;
    if (0xf < local_bc) {
      uStack_ec = (char *)0x76c5e3;
      _free((void *)(uVar10 << 8));
      return;
    }
    uStack_ec = s_<CHAOSTANDARD>_009f4824;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    local_f0 = (int *)0x76c602;
    FUN_00401740();
    uStack_18._0_1_ = 0xc;
    uStack_ec = (char *)0x76c618;
    FUN_00406720();
    uStack_18._0_1_ = 6;
    if (0xf < local_bc) {
      uStack_ec = (char *)0x76c630;
      _free((void *)(uVar10 << 8));
      return;
    }
    uStack_ec = s_<CHIPPOINT>_009f4834;
    local_bc = (undefined1 *)0xf;
    local_c0 = (void *)0x0;
    local_f0 = (int *)0x76c64f;
    FUN_00401740();
    uStack_18._0_1_ = 0xd;
    uStack_ec = (char *)0x76c665;
    FUN_00406720();
    uStack_18 = CONCAT31(uStack_18._1_3_,6);
    if ((undefined1 *)0xf < local_bc) {
      uStack_ec = (char *)0x76c67d;
      _free((void *)(uVar10 << 8));
      return;
    }
    iVar7 = *DAT_00b5ad00;
    piStack_b0 = DAT_00b5ad00;
    (**(code **)(*DAT_00b5a97c + 0xc))();
    uStack_ec = (char *)0x76c69e;
    (**(code **)(iVar7 + 4))();
    uStack_ec = (char *)0x64;
    local_f0 = (int *)0x76c6ad;
    piVar5 = (int *)(**(code **)(*DAT_00b5ab84 + 8))();
    local_f0 = (int *)0x76c6b4;
    puVar6 = (undefined4 *)(**(code **)(*piVar5 + 4))();
    local_dc = (int *)*puVar6;
    local_f0 = (int *)0x76c6e3;
    iVar7 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar7 == 0) {
      FUN_00406250();
    }
    else {
      FUN_0082a2d0();
      pvStack_68 = (void *)0x0;
      local_64 = (undefined1 *)0x0;
      pvStack_60 = (void *)0x0;
      puStack_120 = &DAT_009f4840;
      uStack_2c = 0xe;
      puStack_124 = (undefined1 *)0x76c743;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c74d;
      FUN_00404230();
      uStack_2c = 0xf;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      puStack_120 = &DAT_009f4844;
      puStack_124 = (undefined1 *)0x76c7a4;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c7ae;
      FUN_00404230();
      uStack_2c = 0x10;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      puStack_120 = &DAT_009f4848;
      puStack_124 = (undefined1 *)0x76c805;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c80f;
      FUN_00404230();
      uStack_2c = 0x11;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      puStack_120 = &DAT_009f484c;
      puStack_124 = (undefined1 *)0x76c866;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c870;
      FUN_00404230();
      uStack_2c = 0x12;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      puStack_120 = &DAT_009f4850;
      puStack_124 = (undefined1 *)0x76c8c2;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c8cc;
      FUN_00404230();
      uStack_2c = 0x13;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      puStack_120 = &DAT_009f4854;
      puStack_124 = (undefined1 *)0x76c922;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c92c;
      FUN_00404230();
      uStack_2c = 0x14;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      puStack_120 = &DAT_009f4858;
      puStack_124 = (undefined1 *)0x76c982;
      FUN_00401740();
      puStack_120 = (undefined *)0x76c98c;
      FUN_00404230();
      uStack_2c = 0x15;
      FUN_00406720();
      uStack_2c = 0xe;
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      FUN_00404a40();
      uStack_2c = 0x16;
      FUN_00401660();
      if (0xf < local_a0) {
        _free(pvStack_b4);
        return;
      }
      FUN_00406250();
      uStack_2c = 5;
      FUN_00406250();
      pvVar8 = (void *)FUN_00793770();
      puStack_120 = (undefined *)0x0;
      puStack_124 = auStack_50;
      uStack_128 = 0x76ca64;
      FUN_00401660();
      (**(code **)(*unaff_EBP + 4))();
      piVar5 = local_dc;
      uStack_ec = (char *)((uint)uStack_ec & 0xffffff00);
      cVar2 = (**(code **)(*local_dc + 8))();
      if (cVar2 != '\0') {
        while( true ) {
          puStack_120 = (undefined *)0x76ca9c;
          uVar4 = (**(code **)(*piVar5 + 0xc))();
          puStack_120 = auStack_140 + 0x58;
          uVar10 = CONCAT22(uVar4,(short)piStack_b0);
          puStack_124 = (undefined1 *)0x76cabd;
          piVar5 = (int *)(**(code **)(*DAT_00b5ab94 + 8))();
          if (piVar5 == (int *)0x0) break;
          local_c0 = (void *)0xf;
          pvStack_4c = (void *)CONCAT31(pvStack_4c._1_3_,0x18);
          (**(code **)(*piVar5 + 4))();
          puStack_120 = (undefined *)0x1;
          puStack_124 = (undefined1 *)0x76caf5;
          uStack_12c = (**(code **)(*DAT_00b5a794 + 0xc))();
          puStack_124 = (undefined1 *)0xffffffff;
          uStack_128 = 0;
          uStack_130 = 0x76cb02;
          FUN_00401660();
          local_bc = auStack_140;
          uStack_128 = 0xf;
          uStack_12c = 0;
          uStack_13c = 0;
          FUN_00401660(&local_e0,0,0xffffffff);
          puStack_124 = (undefined1 *)(uint)uVar4;
          (**(code **)(*local_f0 + 8))();
          puStack_74 = (undefined1 *)CONCAT31(puStack_74._1_3_,5);
          if (0xf < uVar10) {
            _free(pvVar8);
            return;
          }
          uStack_ec = (char *)0x0;
          pvVar8 = (void *)((uint)pvVar8 & 0xffffff00);
          bVar3 = (**(code **)(_DAT_00000000 + 8))();
          if (bVar3 <= (byte)uStack_ec) goto LAB_0076cbcd;
          piVar5 = local_dc;
        }
        puStack_120 = &DAT_009f485c;
        local_f0 = (int *)0xf;
        uStack_f4 = 0;
        puStack_124 = (undefined1 *)0x76cb9d;
        FUN_00401740();
        pvStack_4c._0_1_ = 0x17;
        puStack_120 = (undefined *)0x76cbaf;
        FUN_00796d50();
        pvStack_4c = (void *)CONCAT31(pvStack_4c._1_3_,5);
        if ((int *)0xf < local_f0) {
          puStack_120 = (undefined *)0x76cbca;
          _free((void *)0x0);
          return;
        }
      }
LAB_0076cbcd:
      (**(code **)(*DAT_00b5aee8 + 0x10))();
      puStack_120 = (undefined *)0x76cbe5;
      (**(code **)(*DAT_00b5acd4 + 4))();
    }
    if (uStack_38 < 0x10) {
      ExceptionList = pvStack_34;
      return;
    }
    pvVar8 = pvStack_4c;
  }
  _free(pvVar8);
  return;
}


// ==== FUN_0076cc20 @ 0x0076cc20 ====

undefined4 FUN_0076cc20(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x50f0006) {
    FUN_0076ba20(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x50f0007) {
    FUN_0076c150(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0076cc70 @ 0x0076cc70 ====

undefined4 FUN_0076cc70(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0076cc20(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0076cca0 @ 0x0076cca0 ====

void FUN_0076cca0(byte param_1)

{
  void *in_ECX;
  
  FUN_0076ba00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076ccc0 @ 0x0076ccc0 ====

void FUN_0076ccc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4974;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076ccf0 @ 0x0076ccf0 ====

void FUN_0076ccf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4980;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aee0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aee0 = in_ECX;
  return;
}


// ==== FUN_0076cd60 @ 0x0076cd60 ====

void FUN_0076cd60(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aee0 = 0;
  *in_ECX = &PTR_FUN_009f4974;
  return;
}


// ==== FUN_0076cd80 @ 0x0076cd80 ====

void FUN_0076cd80(int param_1)

{
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00995d18;
  local_c = ExceptionList;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 2:
    break;
  case 3:
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  default:
    goto switchD_0076cdac_default;
  }
  uStack_34 = 0;
  uStack_38 = 0x76cddc;
  ExceptionList = &local_c;
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_38 = 0xffffffff;
  uStack_3c = 0;
  uStack_44 = 0x76cdf9;
  FUN_00401660();
  puStack_4 = auStack_50;
  uStack_38 = 0xf;
  uStack_3c = 0;
  local_c = (void *)0x0;
  uStack_4c = 0;
  FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_10) {
    uStack_34 = 0x76ce3e;
    _free(pvStack_24);
    return;
  }
switchD_0076cdac_default:
  ExceptionList = local_c;
  return;
}


// ==== FUN_0076ce70 @ 0x0076ce70 ====

/* WARNING: Removing unreachable block (ram,0x0076d4c3) */
/* WARNING: Removing unreachable block (ram,0x0076d71c) */
/* WARNING: Removing unreachable block (ram,0x0076d6de) */
/* WARNING: Removing unreachable block (ram,0x0076d5fb) */

void FUN_0076ce70(int param_1)

{
  char cVar1;
  code *pcVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  char *pcVar11;
  undefined4 *puStack_168;
  uint uStack_164;
  undefined1 *puStack_160;
  byte *pbStack_15c;
  undefined4 *puStack_158;
  undefined4 uStack_138;
  void **ppvStack_134;
  void **ppvStack_130;
  void *pvStack_104;
  void *pvStack_fc;
  undefined1 auStack_f8 [4];
  void *pvStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  undefined4 uStack_e4;
  uint uStack_e0;
  undefined4 uStack_dc;
  void *pvStack_d8;
  int *piStack_d4;
  undefined1 auStack_d0 [4];
  void *pvStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  void *pvStack_b4;
  void *pvStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  int *piStack_9c;
  undefined1 auStack_98 [4];
  void *pvStack_94;
  uint uStack_80;
  byte abStack_7c [4];
  void *apvStack_78 [3];
  int *piStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  uint uStack_50;
  uint auStack_4c [4];
  undefined1 uStack_3c;
  undefined1 uStack_34;
  undefined1 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995dd4;
  local_c = ExceptionList;
  if (((DAT_00b5acd8 != (int *)0x0) &&
      (ExceptionList = &local_c, piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(),
      piVar4 != (int *)0x0)) && (iVar5 = (**(code **)(*piVar4 + 0xc))(), iVar5 == 4)) {
    bVar3 = *(byte *)(param_1 + 0x14);
    if (bVar3 != 0) {
      puVar9 = (uint *)(param_1 + 0x15);
      puVar10 = auStack_4c;
      for (uVar8 = (uint)(bVar3 >> 2); uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar8 = bVar3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(char *)puVar10 = (char)*puVar9;
        puVar9 = (uint *)((int)puVar9 + 1);
        puVar10 = (uint *)((int)puVar10 + 1);
      }
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x24))();
    if (piVar4 == (int *)0x0) {
      uStack_e8 = 0xf;
      uStack_ec = 0;
      pvStack_fc = (void *)((uint)pvStack_fc & 0xffffff00);
      FUN_00401740();
      uStack_4 = 0;
      FUN_00406880();
      uStack_4 = 0xffffffff;
      if (uStack_e8 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_fc);
      return;
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x20))();
    piStack_6c = piVar4;
    (**(code **)(*piVar4 + 4))();
    ppvStack_130 = (void **)0x76cf88;
    FUN_004dd240();
    uStack_c4 = (**(code **)(*DAT_00b5aee8 + 8))();
    if (uStack_c4 == 0) {
      uStack_e8 = 0xf;
      uStack_ec = 0;
      pvStack_fc = (void *)((uint)pvStack_fc & 0xffffff00);
      FUN_00401740();
      uStack_4 = 1;
      FUN_00406880();
      if (uStack_e8 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_fc);
      return;
    }
    uStack_50 = 0xf;
    pvStack_54 = (void *)0x0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    uStack_4 = 2;
    (**(code **)(*piVar4 + 4))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    ppvStack_130 = (void **)0x76d03b;
    FUN_00401660();
    uStack_c4 = 0;
    uStack_c0 = 0;
    uStack_bc = 0;
    local_c._0_1_ = 3;
    uStack_f0 = 0xf;
    pvStack_f4 = (void *)0x0;
    pvStack_104 = (void *)((uint)pvStack_104 & 0xffffff00);
    FUN_00401740();
    local_c._0_1_ = 4;
    FUN_00406720();
    local_c._0_1_ = 3;
    if (0xf < uStack_f0) {
      _free(pvStack_104);
      return;
    }
    uStack_f0 = 0xf;
    pvStack_f4 = (void *)0x0;
    FUN_00401740();
    local_c._0_1_ = 5;
    FUN_00406720();
    local_c = (void *)CONCAT31(local_c._1_3_,3);
    if (0xf < uStack_f0) {
      _free(pvStack_104);
      return;
    }
    iVar5 = *DAT_00b5ad00;
    (**(code **)(*DAT_00b5a97c + 0xc))();
    (**(code **)(iVar5 + 4))();
    piVar6 = (int *)(**(code **)(*DAT_00b5ab84 + 8))();
    (**(code **)(*piVar6 + 4))();
    pvStack_b0 = (void *)0x0;
    uStack_ac = 0;
    uStack_a8 = 0;
    ppvStack_130 = (void **)0xf;
    ppvStack_134 = (void **)0x0;
    uStack_14 = 6;
    FUN_00401740();
    FUN_00404230();
    uStack_14 = 7;
    ppvStack_130 = (void **)0x76d190;
    FUN_00406720();
    uStack_14 = 6;
    if (0xf < uStack_80) {
      ppvStack_130 = (void **)0x76d1af;
      _free(pvStack_94);
      return;
    }
    ppvStack_130 = (void **)0xf;
    ppvStack_134 = (void **)0x0;
    FUN_00401740();
    FUN_00404230();
    uStack_14 = 8;
    ppvStack_130 = (void **)0x76d1f3;
    FUN_00406720();
    uStack_14 = 6;
    if (0xf < uStack_80) {
      ppvStack_130 = (void **)0x76d216;
      _free(pvStack_94);
      return;
    }
    ppvStack_130 = (void **)auStack_d0;
    ppvStack_134 = apvStack_78;
    uStack_138 = auStack_98;
    ppvStack_134 = (void **)FUN_00404a40();
    ppvStack_130 = (void **)0x0;
    uStack_14 = 9;
    uStack_138 = (undefined1 *)0x76d253;
    FUN_00401660();
    if (0xf < uStack_80) {
      ppvStack_130 = (void **)0x76d269;
      _free(pvStack_94);
      return;
    }
    if (pvStack_b0 != (void *)0x0) {
      ppvStack_130 = &pvStack_b4;
      ppvStack_134 = (void **)uStack_ac;
      uStack_138 = pvStack_b0;
      FUN_00405de0();
      _free(pvStack_b0);
      return;
    }
    pvStack_b0 = (void *)0x0;
    uStack_ac = 0;
    uStack_a8 = 0;
    uStack_14 = 2;
    if (pvStack_cc != (void *)0x0) {
      ppvStack_130 = (void **)auStack_d0;
      ppvStack_134 = (void **)uStack_c8;
      uStack_138 = pvStack_cc;
      FUN_00405de0();
      _free(pvStack_cc);
      return;
    }
    ppvStack_130 = (void **)0x76d2ed;
    FUN_00792c00();
    ppvStack_130 = (void **)0xf;
    ppvStack_134 = (void **)0x0;
    puStack_158 = (undefined4 *)0x76d313;
    FUN_00401660();
    (**(code **)(*piStack_d4 + 4))();
    uStack_138._0_3_ = (uint3)(ushort)uStack_138;
    if (uStack_138._3_1_ != '\0') {
      do {
        bVar3 = abStack_7c[(uint)uStack_138 >> 0x10 & 0xff];
        iVar5 = (**(code **)(*piVar4 + 4))();
        cVar1 = *(char *)(iVar5 + 0x128 + (uint)bVar3 * 4);
        uStack_34 = 10;
        if (cVar1 == '\x04') {
          piVar4 = (int *)(**(code **)(*DAT_00b5ab34 + 8))();
          if (piVar4 == (int *)0x0) {
            uStack_34 = 2;
            break;
          }
          iVar5 = (**(code **)(*piVar4 + 4))();
          pcVar11 = (char *)(iVar5 + 2);
          pvStack_d8 = (void *)0xf;
          uStack_dc = 0;
          uStack_ec = uStack_ec & 0xffffff00;
          do {
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          FUN_00401740();
          uStack_34 = 0xb;
          pbStack_15c = (byte *)(**(code **)(*DAT_00b5a794 + 0xc))();
          puStack_158 = (undefined4 *)0x0;
          ppvStack_134 = (void **)((uint)ppvStack_134 & 0xffffff00);
          puStack_160 = (undefined1 *)0x76d40c;
          FUN_00401660();
          puStack_158 = &uStack_138;
          pbStack_15c = abStack_7c;
          uStack_3c = 0xc;
          puStack_160 = (undefined1 *)0x76d42b;
          uStack_164 = FUN_00402220();
          puStack_160 = auStack_f8;
          puStack_168 = &uStack_dc;
          uStack_3c = 0xd;
          pbStack_15c = (byte *)FUN_00405bd0();
          puStack_158 = (undefined4 *)0x0;
          uStack_3c = 0xe;
          puStack_160 = (undefined1 *)0x76d45e;
          FUN_00401660();
          if (0xf < uStack_c4) {
            puStack_158 = (undefined4 *)0x76d476;
            _free(pvStack_d8);
            return;
          }
          uStack_c4 = 0xf;
          uStack_c8 = 0;
          pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
          if ((void *)0xf < pvStack_64) {
            puStack_158 = (undefined4 *)0x76d4a1;
            _free(apvStack_78[0]);
            return;
          }
          pvStack_64 = (void *)0xf;
          uStack_68 = 0;
          apvStack_78[0] = (void *)((uint)apvStack_78[0] & 0xffffff00);
          ppvStack_134 = (void **)((uint)ppvStack_134 & 0xffffff00);
          uStack_3c = 10;
          if (0xf < uStack_e0) {
            puStack_158 = (undefined4 *)0x76d4f4;
            _free(pvStack_f4);
            return;
          }
          uStack_e0 = 0xf;
          uStack_e4 = 0;
          pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
LAB_0076d69e:
          puStack_158 = (undefined4 *)0xf;
          pbStack_15c = (byte *)0x0;
          FUN_00401660(auStack_f8 + -0x24,0,0xffffffff);
          (**(code **)(iRam0000000f + 8))();
          uStack_34 = 2;
        }
        else {
          if (cVar1 != '\x01') {
            if ((cVar1 == '\x13') || (cVar1 == '\"')) {
LAB_0076d683:
              pbStack_15c = (byte *)(**(code **)(*DAT_00b5a794 + 0xc))();
            }
            else {
              if (cVar1 == '\x1f') {
                (**(code **)(*DAT_00b5ae14 + 0x18))();
                goto LAB_0076d683;
              }
              if (cVar1 == '#') goto LAB_0076d683;
              pbStack_15c = (byte *)(**(code **)(*DAT_00b5a794 + 0xc))();
            }
            puStack_158 = (undefined4 *)0x0;
            puStack_160 = (undefined1 *)0x76d695;
            FUN_00401660();
            goto LAB_0076d69e;
          }
          piVar4 = (int *)(**(code **)(*DAT_00b5ab9c + 8))();
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 8))();
            goto LAB_0076d683;
          }
          ppvStack_134 = &puStack_168;
          uStack_164 = uStack_164 & 0xffffff00;
          FUN_00401740();
          FUN_00404230();
          uStack_34 = 0xf;
          uVar7 = FUN_004022a0(auStack_58,&DAT_009f4928);
          uStack_34 = 0x10;
          FUN_00796d50(uVar7);
          if (0xf < auStack_4c[3]) {
            _free(pvStack_54);
            return;
          }
          auStack_4c[3] = 0xf;
          auStack_4c[2] = 0;
          pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
          if (0xf < uStack_a0) {
            _free(pvStack_b4);
            return;
          }
          uStack_a0 = 0xf;
          uStack_a4 = 0;
          pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
          uStack_34 = 2;
        }
        uStack_34 = 2;
        bVar3 = uStack_138._2_1_ + 1;
        uStack_138._0_3_ = CONCAT12(bVar3,(ushort)uStack_138);
        if (uStack_138._3_1_ <= bVar3) break;
        piVar4 = piStack_9c;
      } while( true );
    }
    (**(code **)(*DAT_00b5aee8 + 0x10))();
    (**(code **)(*DAT_00b5acd4 + 4))();
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0076d780 @ 0x0076d780 ====

undefined4 FUN_0076d780(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5050002) {
    FUN_0076ce70(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5050004) {
    FUN_0076cd80(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5050008) {
    (**(code **)(*DAT_00b5af2c + 8))(4);
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
  return 0;
}


// ==== FUN_0076d800 @ 0x0076d800 ====

undefined4 FUN_0076d800(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0076d780(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0076d830 @ 0x0076d830 ====

void FUN_0076d830(byte param_1)

{
  void *in_ECX;
  
  FUN_0076cd60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076d850 @ 0x0076d850 ====

void FUN_0076d850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4a18;
  return;
}


// ==== FUN_0076d860 @ 0x0076d860 ====

void FUN_0076d860(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076d880 @ 0x0076d880 ====

undefined4 FUN_0076d880(void)

{
  return 0x70020000;
}


// ==== FUN_0076d890 @ 0x0076d890 ====

undefined4 FUN_0076d890(void)

{
  return 0x70020001;
}


// ==== FUN_0076d8a0 @ 0x0076d8a0 ====

undefined4 FUN_0076d8a0(void)

{
  return 0x70020002;
}


// ==== FUN_0076d8b0 @ 0x0076d8b0 ====

undefined4 FUN_0076d8b0(void)

{
  return 0x70020004;
}


// ==== FUN_0076d8c0 @ 0x0076d8c0 ====

void FUN_0076d8c0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
  (**(code **)(*piVar1 + 0x18))(param_1);
  (**(code **)(*DAT_00b5aee8 + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0076d8f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acd4 + 4))();
  return;
}


// ==== FUN_0076d900 @ 0x0076d900 ====

void FUN_0076d900(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0076d90f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x1c))();
  return;
}


// ==== FUN_0076d920 @ 0x0076d920 ====

void FUN_0076d920(void)

{
                    /* WARNING: Could not recover jumptable at 0x0076d928. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aee8 + 0x18))();
  return;
}


// ==== FUN_0076d930 @ 0x0076d930 ====

void FUN_0076d930(void)

{
                    /* WARNING: Could not recover jumptable at 0x0076d938. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aee8 + 8))();
  return;
}


// ==== FUN_0076d940 @ 0x0076d940 ====

void FUN_0076d940(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f4a68;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0076d970 @ 0x0076d970 ====

undefined4 FUN_0076d970(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_dialog_009f49f8,0xb);
  if (iVar1 == 0) {
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009f4a40;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  else {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_dialog_009f4a04,0xb);
    if (iVar1 != 0) {
      return 0;
    }
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009f4a54;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  FUN_00797a20(0);
  return 1;
}


// ==== FUN_0076da10 @ 0x0076da10 ====

undefined4 FUN_0076da10(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0076d970(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0076da40 @ 0x0076da40 ====

void FUN_0076da40(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_26 [2];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00995de8;
  local_c = ExceptionList;
  if ((char)in_ECX[2] != '\0') {
    uStack_3c = 0x76da6f;
    ExceptionList = &local_c;
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f4a7c;
    }
    uStack_3c = 0x76da86;
    FUN_00797a20();
    iVar2 = 0;
    if (param_1 == 0) {
      uStack_3c = 0x76dac4;
      (**(code **)(*in_ECX + 4))();
    }
    else if (param_1 == 1) {
      iVar2 = 0x3200047;
      (**(code **)(*in_ECX + 8))();
    }
    else if (param_1 == 2) {
      iVar2 = 0x3200048;
      (**(code **)(*in_ECX + 8))();
    }
    *(undefined1 *)(in_ECX + 2) = 0;
    in_ECX[3] = 0;
    if (iVar2 != 0) {
      uStack_3c = 8;
      uStack_40 = 0x76dadc;
      uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_40 = 0xffffffff;
      uStack_44 = 0;
      uStack_4c = 0x76dafa;
      FUN_00401660();
      puStack_4 = auStack_58;
      uStack_40 = 0xf;
      uStack_44 = 0;
      local_c = (void *)0x0;
      uStack_54 = 0;
      FUN_00401660(auStack_26 + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_10) {
        uStack_3c = 0x76db3b;
        _free(pvStack_24);
        return;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0076db60 @ 0x0076db60 ====

void FUN_0076db60(void)

{
  undefined4 *puVar1;
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
  void *local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995e25;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009f4ab0;
  *puVar1 = &PTR_FUN_009f4aa4;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aee4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5aee4 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009f49c2,0);
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_dialog_009f49c4,0xb);
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
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
  FUN_00401740(&DAT_009f49d0,0);
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_dialog_009f49d4,0xb);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = CONCAT31(uStack_1c._1_3_,1);
  if (local_28 < (void *)0x10) {
    (**(code **)(*DAT_00b5aee8 + 0x1c))(puVar1);
    *(undefined1 *)(in_ECX + 2) = 0;
    in_ECX[3] = 0;
    ExceptionList = local_28;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_0076dd10 @ 0x0076dd10 ====

void FUN_0076dd10(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  void *pvStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995e6e;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f4ab0;
  *puVar1 = &PTR_FUN_009f4aa4;
  local_4 = 1;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_dialog_009f49e0,0xb);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  pvStack_18 = (void *)0x0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_dialog_009f49ec,0xb);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  if (pvStack_18 < (void *)0x10) {
    DAT_00b5aee4 = 0;
    (**(code **)(*DAT_00b5aee8 + 0x20))(puVar1);
    *puVar1 = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009f4a18;
    ExceptionList = pvStack_18;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_0076de20 @ 0x0076de20 ====

void FUN_0076de20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    puVar1 = operator_new(0x28);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009f4a90;
      puVar1[7] = 0xf;
      puVar1[6] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
    }
    FUN_00401660(param_1,0,0xffffffff);
    puVar1[8] = param_2;
    puVar1[9] = param_4;
    FUN_00797a20(puVar1);
    *(undefined1 *)(in_ECX + 8) = 1;
    *(undefined4 *)(in_ECX + 0xc) = param_3;
  }
  return;
}


// ==== FUN_0076de90 @ 0x0076de90 ====

undefined4 FUN_0076de90(void)

{
  return 0x70020003;
}


// ==== FUN_0076dea0 @ 0x0076dea0 ====

void FUN_0076dea0(byte param_1)

{
  void *in_ECX;
  
  FUN_0076dec0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076dec0 @ 0x0076dec0 ====

void FUN_0076dec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4a90;
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


// ==== FUN_0076df00 @ 0x0076df00 ====

void FUN_0076df00(void)

{
  FUN_0076df10();
  return;
}


// ==== FUN_0076df10 @ 0x0076df10 ====

void FUN_0076df10(byte param_1)

{
  void *in_ECX;
  
  FUN_0076dd10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076df30 @ 0x0076df30 ====

void FUN_0076df30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4b18;
  return;
}


// ==== FUN_0076df40 @ 0x0076df40 ====

void FUN_0076df40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4b18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076df60 @ 0x0076df60 ====

undefined4 FUN_0076df60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0076df70 @ 0x0076df70 ====

undefined4 FUN_0076df70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0076df80 @ 0x0076df80 ====

undefined1 FUN_0076df80(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x14);
}


// ==== FUN_0076df90 @ 0x0076df90 ====

void FUN_0076df90(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f4a40;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x14) = 1;
  iVar2 = (**(code **)(*DAT_00b5adc4 + 8))();
  if (iVar2 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0076dfd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5adc4 + 0x1c))();
  return;
}


// ==== FUN_0076dfe0 @ 0x0076dfe0 ====

void FUN_0076dfe0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x14) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009f4a54;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_0076e020 @ 0x0076e020 ====

void FUN_0076e020(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[3] + 4))();
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_0076e080 @ 0x0076e080 ====

void FUN_0076e080(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_0076e0a0 @ 0x0076e0a0 ====

void FUN_0076e0a0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00995e93;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f4b40;
  local_4 = 1;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5aee8 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_007520f0(local_10,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0076e130 @ 0x0076e130 ====

void FUN_0076e130(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_0076e140 @ 0x0076e140 ====

void FUN_0076e140(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995ebb;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f4b40;
  iVar1 = FUN_00751a80();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  local_4._0_1_ = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aee8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5aee8 = in_ECX;
  }
  pvVar2 = operator_new(0x38);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00793990();
  }
  in_ECX[1] = uVar3;
  *(undefined1 *)(in_ECX + 5) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0076e1f0 @ 0x0076e1f0 ====

void FUN_0076e1f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0076e0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076e210 @ 0x0076e210 ====

void FUN_0076e210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4c60;
  return;
}


// ==== FUN_0076e220 @ 0x0076e220 ====

void FUN_0076e220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4c60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076e240 @ 0x0076e240 ====

int FUN_0076e240(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 10;
}


// ==== FUN_0076e260 @ 0x0076e260 ====

void FUN_0076e260(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = (undefined4 *)((int)param_1 + 10)) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_3 + 2);
  }
  return;
}


// ==== FUN_0076e2a0 @ 0x0076e2a0 ====

void FUN_0076e2a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  while (param_1 != param_2) {
    *(undefined4 *)((int)param_3 + -10) = *(undefined4 *)((int)param_2 + -10);
    *(undefined4 *)((int)param_3 + -6) = *(undefined4 *)((int)param_2 + -6);
    *(undefined2 *)((int)param_3 + -2) = *(undefined2 *)((int)param_2 + -2);
    param_2 = (undefined4 *)((int)param_2 + -10);
    param_3 = (undefined4 *)((int)param_3 + -10);
  }
  return;
}


// ==== FUN_0076e2e0 @ 0x0076e2e0 ====

void FUN_0076e2e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = (undefined4 *)((int)param_1 + 10)) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(param_1 + 2);
    }
    param_3 = (undefined4 *)((int)param_3 + 10);
  }
  return;
}


// ==== FUN_0076e320 @ 0x0076e320 ====

void FUN_0076e320(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0076e320(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0076e360 @ 0x0076e360 ====

void FUN_0076e360(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = *param_3;
        param_1[1] = param_3[1];
        *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_3 + 2);
      }
      param_1 = (undefined4 *)((int)param_1 + 10);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_0076e3a0 @ 0x0076e3a0 ====

void FUN_0076e3a0(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  int *piVar4;
  int *in_ECX;
  short *psVar5;
  undefined4 *unaff_retaddr;
  undefined1 auStack_2 [2];
  
  uVar2 = param_2;
  sVar3 = (**(code **)(*in_ECX + 4))(param_2);
  if (sVar3 == (short)uVar2) {
    piVar4 = (int *)FUN_006e5150(auStack_2 + -6,&param_1);
    if (*piVar4 != in_ECX[2]) {
      psVar5 = *(short **)(*piVar4 + 0x10);
LAB_0076e3d4:
      *unaff_retaddr = *(undefined4 *)psVar5;
      unaff_retaddr[1] = *(undefined4 *)(psVar5 + 2);
      *(short *)(unaff_retaddr + 2) = psVar5[4];
      return;
    }
  }
  else {
    piVar4 = (int *)FUN_006e5150(&param_1,auStack_2 + -6);
    if (*piVar4 != in_ECX[2]) {
      iVar1 = *(int *)(*piVar4 + 0x10);
      for (psVar5 = *(short **)(iVar1 + 0x10); psVar5 != *(short **)(iVar1 + 0x14);
          psVar5 = psVar5 + 5) {
        if (*psVar5 == (short)uVar2) goto LAB_0076e3d4;
      }
    }
  }
  *unaff_retaddr = 0;
  unaff_retaddr[1] = 0;
  *(undefined2 *)(unaff_retaddr + 2) = 0;
  return;
}


// ==== FUN_0076e440 @ 0x0076e440 ====

uint FUN_0076e440(int param_1)

{
  undefined1 local_c [4];
  ushort local_8;
  
  FUN_0076e3a0(local_c,param_1);
  return param_1 << 0x10 | (uint)local_8;
}


// ==== FUN_0076e470 @ 0x0076e470 ====

uint FUN_0076e470(int param_1)

{
  undefined1 local_c [6];
  ushort local_6;
  
  FUN_0076e3a0(local_c,param_1);
  return param_1 << 0x10 | (uint)local_6;
}


// ==== FUN_0076e4a0 @ 0x0076e4a0 ====

uint FUN_0076e4a0(int param_1)

{
  undefined1 local_c [8];
  ushort local_4;
  
  FUN_0076e3a0(local_c,param_1);
  return param_1 << 0x10 | (uint)local_4;
}


// ==== FUN_0076e4d0 @ 0x0076e4d0 ====

uint FUN_0076e4d0(void)

{
  ushort *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint extraout_EAX_00;
  int in_ECX;
  ushort *puVar7;
  int local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995f08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_006e5150();
  if (local_48 == *(int *)(in_ECX + 8)) {
    FUN_00401740(s_GetCurrentQuest_Failed__ID___d_009f4bc8,0x1e);
    uVar3 = FUN_00404230(local_44);
    local_4 = 0;
    FUN_00403e50(uVar3);
    if (local_2c < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
  }
  else {
    iVar5 = *(int *)(local_48 + 0x10);
    if (iVar5 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740();
      local_4 = 1;
      FUN_00406880();
      local_4 = 0xffffffff;
      if (local_2c < 0x10) {
        pcVar2 = (code *)swi(3);
        uVar4 = (*pcVar2)();
        return uVar4;
      }
      _free(local_40);
      return extraout_EAX;
    }
    puVar1 = *(ushort **)(iVar5 + 0x14);
    for (puVar7 = *(ushort **)(iVar5 + 0x10); puVar7 != puVar1; puVar7 = puVar7 + 5) {
      iVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
      piVar6 = (int *)(**(code **)(**(int **)(iVar5 + 0x60) + 0x14))();
      iVar5 = (**(code **)(*piVar6 + 0xc))();
      if (iVar5 != 0) {
        ExceptionList = local_c;
        return (uint)*puVar7;
      }
    }
    FUN_00401740(&DAT_009f4bf4);
    uVar3 = FUN_00404230();
    local_4 = 2;
    FUN_00403e50(uVar3);
    if (uStack_10 < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    local_40 = pvStack_24;
  }
  _free(local_40);
  return extraout_EAX_00;
}


// ==== FUN_0076e670 @ 0x0076e670 ====

uint * FUN_0076e670(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint *extraout_EAX;
  uint *puVar3;
  uint *unaff_retaddr;
  uint uStack_30;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995f1a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x60) + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))(param_2);
  if (piVar2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar2 + 0xc))();
    puVar3 = (uint *)(**(code **)(*piVar2 + 4))();
    *unaff_retaddr = *puVar3;
    unaff_retaddr[1] = puVar3[1];
    ExceptionList = pvStack_10;
    return unaff_retaddr;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401740(&DAT_009f4c1c,0x3d);
  puStack_8 = (undefined1 *)0x0;
  FUN_00403e50(auStack_2c);
  if (uStack_14 < 0x10) {
    uStack_30 = uStack_30 & 0xffff0000;
    *unaff_retaddr = param_2 & 0xffff;
    unaff_retaddr[1] = uStack_30;
    ExceptionList = pvStack_10;
    return unaff_retaddr;
  }
  _free(pvStack_28);
  return extraout_EAX;
}


// ==== FUN_0076e760 @ 0x0076e760 ====

void FUN_0076e760(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while( true ) {
    if (puVar3 == puVar2) {
      pvVar4 = *(void **)(*(int *)(in_ECX + 8) + 4);
      if (*(char *)((int)pvVar4 + 0x15) == '\0') {
        FUN_0076e320(*(undefined4 *)((int)pvVar4 + 8));
        _free(pvVar4);
        return;
      }
      *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
      *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
      return;
    }
    pvVar4 = (void *)puVar3[4];
    if (*(void **)((int)pvVar4 + 0x10) != (void *)0x0) break;
    *(undefined4 *)((int)pvVar4 + 0x10) = 0;
    *(undefined4 *)((int)pvVar4 + 0x14) = 0;
    *(undefined4 *)((int)pvVar4 + 0x18) = 0;
    if (pvVar4 != (void *)0x0) {
      FUN_0076f410();
      _free(pvVar4);
      return;
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  _free(*(void **)((int)pvVar4 + 0x10));
  return;
}


// ==== FUN_0076e840 @ 0x0076e840 ====

void FUN_0076e840(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00995f37;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f4c88;
  local_4 = 1;
  DAT_00b5ac40 = 0;
  FUN_0076e760();
  local_4 = local_4 & 0xffffff00;
  FUN_0076f7c0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0076e8c0 @ 0x0076e8c0 ====

void FUN_0076e8c0(int param_1,int *param_2,undefined2 param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  short sVar4;
  int local_50;
  int local_4c;
  undefined2 local_48;
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
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995f5c;
  local_c = ExceptionList;
  sVar4 = (short)param_1;
  if (sVar4 != (short)((uint)param_1 >> 0x10)) {
    ExceptionList = &local_c;
    FUN_006e5150(&local_50,(int)&param_1 + 2);
    if (local_50 != *(int *)(in_ECX + 8)) {
      local_4c = (int)param_2;
      local_50 = iVar2;
      local_48 = param_3;
      FUN_0076f8f0(&local_50);
      ExceptionList = local_c;
      return;
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740(s_mapit____m_pMapTitle_end___009f4bac,0x1a);
    local_4 = 2;
    FUN_00406880(local_44);
    local_4 = 0xffffffff;
    if (local_2c < 0x10) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  ExceptionList = &local_c;
  FUN_006e5150(&local_50,&param_1);
  if (local_50 != *(int *)(in_ECX + 8)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_mapit____m_pMapTitle_end___009f4b90,0x1a);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_24);
    return;
  }
  piVar3 = operator_new(0x1c);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3[4] = 0;
    piVar3[5] = 0;
    piVar3[6] = 0;
  }
  *piVar3 = iVar2;
  piVar3[1] = (int)param_2;
  *(undefined2 *)(piVar3 + 2) = param_3;
  local_4 = 0xffffffff;
  if ((void *)piVar3[4] == (void *)0x0) {
    piVar3[4] = 0;
    piVar3[5] = 0;
    piVar3[6] = 0;
    param_1 = CONCAT22(param_1._2_2_,sVar4);
    param_2 = piVar3;
    FUN_0076f440(&local_50,&param_1);
    ExceptionList = local_c;
    return;
  }
  _free((void *)piVar3[4]);
  return;
}


// ==== FUN_0076eaa0 @ 0x0076eaa0 ====

void FUN_0076eaa0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  
  FUN_0076e760();
  piVar1 = (int *)(**(code **)(*DAT_00b5ab9c + 0xc))();
  while (piVar1 != (int *)0x0) {
    uVar3 = 0x76;
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 8))();
    FUN_0076e8c0(*puVar2,puVar2[1],CONCAT22(uVar3,*(undefined2 *)(puVar2 + 2)));
    piVar1 = (int *)(**(code **)(*DAT_00b5ab9c + 0x10))();
  }
  return;
}


// ==== FUN_0076eaf0 @ 0x0076eaf0 ====

undefined4 FUN_0076eaf0(short param_1,undefined4 param_2)

{
  short *psVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  short *psVar3;
  void *_Memory;
  undefined4 unaff_retaddr;
  undefined4 local_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  short *psStack_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995f6e;
  pvStack_c = ExceptionList;
  local_24 = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*in_ECX + 4))(param_2);
  piVar2 = (int *)FUN_006e5150(&local_24,auStack_20 + -8);
  _Memory = (void *)0x0;
  pvStack_1c = (void *)0x0;
  psStack_18 = (short *)0x0;
  iStack_14 = 0;
  psVar3 = *(short **)(*(int *)(*piVar2 + 0x10) + 0x10);
  psVar1 = *(short **)(*(int *)(*piVar2 + 0x10) + 0x14);
  puStack_8 = (undefined1 *)0x0;
  for (; (psVar3 != psVar1 && (*psVar3 != param_1)); psVar3 = psVar3 + 5) {
    if ((_Memory == (void *)0x0) ||
       ((uint)(iStack_14 - (int)_Memory >> 1) <= (uint)((int)psStack_18 - (int)_Memory >> 1))) {
      FUN_00427290(psStack_18,1,psVar3);
      _Memory = pvStack_1c;
    }
    else {
      *psStack_18 = *psVar3;
      psStack_18 = psStack_18 + 1;
    }
  }
  FUN_00427460(auStack_20);
  if (_Memory == (void *)0x0) {
    ExceptionList = pvStack_10;
    return unaff_retaddr;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0076ebe0 @ 0x0076ebe0 ====

undefined4 FUN_0076ebe0(short param_1,undefined4 param_2)

{
  short *psVar1;
  bool bVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  int *in_ECX;
  short *psVar4;
  short *psVar5;
  void *_Memory;
  undefined4 unaff_retaddr;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  short *psStack_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00995f80;
  pvStack_c = ExceptionList;
  local_24 = 0;
  ExceptionList = &pvStack_c;
  uStack_28 = (**(code **)(*in_ECX + 4))(param_2);
  piVar3 = (int *)FUN_006e5150(&local_24,&uStack_28);
  _Memory = (void *)0x0;
  psVar4 = (short *)0x0;
  pvStack_1c = (void *)0x0;
  psStack_18 = (short *)0x0;
  iStack_14 = 0;
  psVar5 = *(short **)(*(int *)(*piVar3 + 0x10) + 0x10);
  psVar1 = *(short **)(*(int *)(*piVar3 + 0x10) + 0x14);
  puStack_8 = (undefined1 *)0x0;
  bVar2 = false;
  for (; psVar5 != psVar1; psVar5 = psVar5 + 5) {
    if (*psVar5 == param_1) {
      bVar2 = true;
    }
    else if (bVar2) {
      if ((_Memory == (void *)0x0) ||
         ((uint)(iStack_14 - (int)_Memory >> 1) <= (uint)((int)psVar4 - (int)_Memory >> 1))) {
        FUN_00427290(psVar4,1,psVar5);
        psVar4 = psStack_18;
        _Memory = pvStack_1c;
      }
      else {
        *psVar4 = *psVar5;
        psStack_18 = psVar4 + 1;
        psVar4 = psStack_18;
      }
    }
  }
  FUN_00427460(auStack_20);
  if (_Memory == (void *)0x0) {
    ExceptionList = pvStack_10;
    return unaff_retaddr;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0076ece0 @ 0x0076ece0 ====

void FUN_0076ece0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00995f9d;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f4c88;
  iVar1 = FUN_0058d7c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0076e320(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  FUN_0076eaa0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac40 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac40 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0076eda0 @ 0x0076eda0 ====

uint FUN_0076eda0(ushort param_1)

{
  char cVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint extraout_EAX;
  int in_ECX;
  ushort *puVar7;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00995faf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(in_ECX + 0xc) == 0) {
    ExceptionList = &local_c;
    FUN_0076eaa0();
  }
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 8);
  while (puVar2 != *(undefined4 **)(in_ECX + 8)) {
    if (param_1 == *(ushort *)(puVar2 + 3)) {
      ExceptionList = local_c;
      return (uint)param_1;
    }
    puVar7 = *(ushort **)(puVar2[4] + 0x10);
    puVar3 = *(ushort **)(puVar2[4] + 0x14);
    if (puVar7 != puVar3) {
      do {
        if (*puVar7 == param_1) {
          ExceptionList = local_c;
          return (uint)puVar7[1];
        }
        puVar7 = puVar7 + 5;
      } while (puVar7 != puVar3);
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar5 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar5 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  FUN_00401740(s_GetParent_Failed__d__no_such_par_009f4b68,0x24);
  uVar6 = FUN_00404230(local_28);
  local_4 = 0;
  FUN_00403e50(uVar6);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_0076eee0 @ 0x0076eee0 ====

int FUN_0076eee0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0076e360(param_1,param_2,param_3);
  return param_1 + param_2 * 10;
}


// ==== FUN_0076ef10 @ 0x0076ef10 ====

void FUN_0076ef10(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00995ed8;
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
LAB_0076f009:
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
      if ((char)piVar6[5] == '\0') goto LAB_0076f009;
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


// ==== FUN_0076f0f0 @ 0x0076f0f0 ====

void FUN_0076f0f0(void)

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
  puStack_8 = &LAB_00995ed8;
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


// ==== FUN_0076f160 @ 0x0076f160 ====

/* WARNING: Removing unreachable block (ram,0x0076f273) */
/* WARNING: Removing unreachable block (ram,0x0076f283) */
/* WARNING: Removing unreachable block (ram,0x0076f28c) */
/* WARNING: Removing unreachable block (ram,0x0076f28f) */
/* WARNING: Removing unreachable block (ram,0x0076f27f) */
/* WARNING: Removing unreachable block (ram,0x0076f29d) */
/* WARNING: Removing unreachable block (ram,0x0076f2aa) */
/* WARNING: Removing unreachable block (ram,0x0076f2b5) */
/* WARNING: Removing unreachable block (ram,0x0076f2b1) */
/* WARNING: Removing unreachable block (ram,0x0076f2a5) */
/* WARNING: Removing unreachable block (ram,0x0076f2b8) */

void FUN_0076f160(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00995ed8;
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
            goto LAB_0076f385;
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
LAB_0076f385:
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


// ==== FUN_0076f410 @ 0x0076f410 ====

void FUN_0076f410(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x10) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_0076f440 @ 0x0076f440 ====

void FUN_0076f440(undefined4 *param_1,ushort *param_2)

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
      puVar4 = (undefined4 *)FUN_0076ef10(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_0076ef10(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0076f500 @ 0x0076f500 ====

void FUN_0076f500(int param_1,uint param_2,undefined4 *param_3)

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
  undefined2 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00995fc0;
  local_10 = ExceptionList;
  local_20 = *param_3;
  local_1c = param_3[1];
  iVar3 = *(int *)(in_ECX + 4);
  local_18 = *(undefined2 *)(param_3 + 2);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 10;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 10;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x19999999U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0076f0f0();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 10;
    }
    if (uVar6 < iVar2 + param_2) {
      if (0x19999999 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 10;
      }
      if (uVar6 < iVar3 + param_2) {
        iVar3 = FUN_0076e240();
        uVar6 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar6 * 10);
      local_8 = 0;
      iVar3 = FUN_0076e2e0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_0076e360(iVar3,param_2,&local_20);
      FUN_0076e2e0(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 10);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 10;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 10 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 10);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 10) < param_2) {
      FUN_0076e2e0(param_1,iVar3,param_2 * 10 + param_1);
      local_8 = 2;
      FUN_0076eee0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 10,&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 10;
      FUN_0076e260(param_1,*(int *)(in_ECX + 8) + param_2 * -10,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + param_2 * -10;
    uVar5 = FUN_0076e2e0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0076e2a0(param_1,iVar2,iVar3,iVar2);
    FUN_0076e260(param_1,param_2 * 10 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0076f6b7 @ 0x0076f6b7 ====

void Catch_0076f6b7(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_0076f7c0 @ 0x0076f7c0 ====

void FUN_0076f7c0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0076e320(piVar6[1]);
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
    FUN_0076f160(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0076f880 @ 0x0076f880 ====

void FUN_0076f880(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 10 != 0) {
      iVar1 = (param_2 - iVar1) / 10;
      goto LAB_0076f8c5;
    }
  }
  iVar1 = 0;
LAB_0076f8c5:
  FUN_0076f500(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 10;
  return;
}


// ==== FUN_0076f8f0 @ 0x0076f8f0 ====

void FUN_0076f8f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 10) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 10)))
  {
    FUN_0076f880(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0076e360(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 10;
  return;
}


// ==== FUN_0076f980 @ 0x0076f980 ====

void FUN_0076f980(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0076f7c0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0076f9b0 @ 0x0076f9b0 ====

void FUN_0076f9b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0076e840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076f9d0 @ 0x0076f9d0 ====

void FUN_0076f9d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4e44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0076f9f0 @ 0x0076f9f0 ====

undefined4 FUN_0076f9f0(void)

{
  return 0x30060120;
}


// ==== FUN_0076fa00 @ 0x0076fa00 ====

void FUN_0076fa00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f4e64;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac34 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac34 = in_ECX;
  return;
}


// ==== FUN_0076fa80 @ 0x0076fa80 ====

void FUN_0076fa80(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac34 = 0;
  *in_ECX = &PTR_FUN_009f4e44;
  return;
}


// ==== FUN_0076faa0 @ 0x0076faa0 ====

void FUN_0076faa0(int param_1)

{
  undefined4 uVar1;
  undefined2 extraout_var;
  undefined1 *puStack_70;
  undefined1 uStack_6c;
  void *local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00995fe0;
  pvStack_c = ExceptionList;
  puStack_70 = (undefined1 *)0x1a;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = (void *)((uint)local_68 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_Cancel_Receivedt___d_009f4cec);
  puStack_70 = local_28;
  uVar1 = FUN_00404230();
  local_4 = (undefined1 *)0x0;
  FUN_00796d50(uVar1);
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_10) {
    local_54 = 0x76fb17;
    _free(local_24);
    return;
  }
  local_54 = 0;
  local_58 = 0x76fb2b;
  uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
  local_58 = 0xffffffff;
  uStack_5c = 0;
  uStack_64 = 0x76fb48;
  FUN_00401660();
  local_4 = (undefined1 *)&puStack_70;
  local_58 = 0xf;
  uStack_5c = 0;
  pvStack_c = (void *)0x1;
  uStack_6c = 0;
  FUN_00401660(local_28 + -0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  FUN_004dd240(0x16,10,0,3,0);
  if (*(char *)(param_1 + 0x12) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    FUN_0082a300(uVar1,CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x10)));
  }
  (**(code **)(*DAT_00b5ac3c + 0x18))();
  if (local_54 < 0x10) {
    ExceptionList = (void *)0xf;
    return;
  }
  _free(local_68);
  return;
}


// ==== FUN_0076fbe0 @ 0x0076fbe0 ====

void FUN_0076fbe0(int param_1)

{
  short sVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  void *pvVar5;
  void *_Memory;
  undefined4 *puStack_70;
  undefined1 uStack_6c;
  undefined1 local_68;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  void *pvStack_44;
  undefined4 local_28;
  void *local_24;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00995ffa;
  pvStack_c = ExceptionList;
  puStack_70 = (undefined4 *)0x1f;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_Start_Received__Quest___d_009f4d08);
  puStack_70 = &local_28;
  uVar4 = FUN_00404230();
  local_4 = (undefined1 *)0x0;
  FUN_00796d50(uVar4);
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_10) {
    local_54 = 0x76fc57;
    _free(local_24);
    return;
  }
  local_54 = 0;
  local_58 = 0x76fc6b;
  uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
  local_58 = 0xffffffff;
  uStack_5c = 0;
  uStack_64 = 0x76fc88;
  FUN_00401660();
  local_4 = (undefined1 *)&puStack_70;
  local_58 = 0xf;
  uStack_5c = 0;
  pvStack_c = (void *)0x1;
  uStack_6c = 0;
  FUN_00401660((int)register0x00000010 + -0x4c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  FUN_004dd240(0x16,10,0,1,0);
  sVar1 = *(short *)(param_1 + 0x10);
  pvVar5 = (void *)CONCAT22((short)((uint)param_1 >> 0x10),sVar1);
  uVar4 = (**(code **)(*DAT_00b5ac1c + 0x14))(pvVar5);
  FUN_0082a330(uVar4);
  _Memory = pvVar5;
  sVar3 = (**(code **)(*DAT_00b5ac40 + 4))();
  local_28 = CONCAT31(local_28._1_3_,sVar3 != sVar1);
  (**(code **)(*DAT_00b5ac38 + 0x10))(local_28,pvVar5);
  (**(code **)(*DAT_00b5ac3c + 0x18))();
  cVar2 = FUN_006ef730(pvVar5);
  if (cVar2 == '\x01') {
    (**(code **)(*DAT_00b5ac38 + 0x5c))(2);
  }
  else {
    (**(code **)(*DAT_00b5ac38 + 0x5c))(1);
  }
  (**(code **)(*DAT_00b5ac38 + 0x38))();
  if (uStack_64 < 0x10) {
    ExceptionList = pvStack_44;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0076fd70 @ 0x0076fd70 ====

void FUN_0076fd70(void)

{
  undefined4 uVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099600c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_SN_Count_Received__Quest____009f4d28,0x42);
  uVar1 = FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(uVar1);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5ac1c + 0x14))();
    FUN_0082a3b0();
    (**(code **)(*DAT_00b5ac3c + 0x18))();
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0076fe50 @ 0x0076fe50 ====

void FUN_0076fe50(void)

{
  undefined4 uVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099601e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_SN_State_Received__Quest____009f4d6c,0x2d);
  uVar1 = FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(uVar1);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5ac1c + 0x14))();
    FUN_0082a3f0();
    (**(code **)(*DAT_00b5ac3c + 0x18))();
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0076ff20 @ 0x0076ff20 ====

void FUN_0076ff20(int param_1)

{
  undefined4 uVar1;
  undefined2 extraout_var;
  undefined1 *puStack_70;
  undefined1 uStack_6c;
  void *local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00996038;
  pvStack_c = ExceptionList;
  puStack_70 = (undefined1 *)0x20;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = (void *)((uint)local_68 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_Finish_Received__Quest___d_009f4d9c);
  puStack_70 = local_28;
  uVar1 = FUN_00404230();
  local_4 = (undefined1 *)0x0;
  FUN_00796d50(uVar1);
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_10) {
    local_54 = 0x76ff97;
    _free(local_24);
    return;
  }
  local_54 = 0;
  local_58 = 0x76ffab;
  uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
  local_58 = 0xffffffff;
  uStack_5c = 0;
  uStack_64 = 0x76ffc8;
  FUN_00401660();
  local_4 = (undefined1 *)&puStack_70;
  local_58 = 0xf;
  uStack_5c = 0;
  pvStack_c = (void *)0x1;
  uStack_6c = 0;
  FUN_00401660(local_28 + -0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  FUN_004dd240(0x16,10,0,2,0);
  uVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  FUN_0082a420(uVar1,CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x10)));
  (**(code **)(*DAT_00b5ac3c + 0x18))();
  if (local_54 < 0x10) {
    ExceptionList = (void *)0xf;
    return;
  }
  _free(local_68);
  return;
}


