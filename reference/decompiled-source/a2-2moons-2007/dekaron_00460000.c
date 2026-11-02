// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x460000-0x46ffff

// ==== FUN_00460130 @ 0x00460130 ====

void FUN_00460130(undefined1 param_1)

{
  FUN_00460680(&param_1);
  return;
}


// ==== FUN_00460140 @ 0x00460140 ====

void FUN_00460140(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c82a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0ba4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  local_4 = 2;
  FUN_0045fc10();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a840 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a840 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004601d0 @ 0x004601d0 ====

void FUN_004601d0(undefined4 param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c6c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x1d) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00460250 @ 0x00460250 ====

void FUN_00460250(void)

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
  puStack_8 = &LAB_0097c848;
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


// ==== FUN_004602c0 @ 0x004602c0 ====

void FUN_004602c0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c848;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  FUN_00401740(s_deque<T>_too_long_0099d358,0x11);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c48c);
}


// ==== FUN_00460330 @ 0x00460330 ====

void FUN_00460330(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00460250();
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


// ==== FUN_00460510 @ 0x00460510 ====

void FUN_00460510(uint param_1)

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
    uVar2 = FUN_004602c0();
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
    if (param_1 == 0) goto LAB_0046063c;
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
    if (uVar4 == 0) goto LAB_0046063c;
    puVar5 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
LAB_0046063c:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00460660 @ 0x00460660 ====

void FUN_00460660(byte param_1)

{
  void *in_ECX;
  
  FUN_0045f8e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00460680 @ 0x00460680 ====

void FUN_00460680(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10) & 3U) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 4U >> 2)) {
    FUN_00460510(1);
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


// ==== FUN_00460700 @ 0x00460700 ====

void FUN_00460700(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0d70;
  return;
}


// ==== FUN_00460710 @ 0x00460710 ====

void FUN_00460710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0d70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00460730 @ 0x00460730 ====

void FUN_00460730(void)

{
  int in_ECX;
  
  FUN_007cab90();
  SuspendThread(*(HANDLE *)(in_ECX + 4));
  return;
}


// ==== FUN_00460760 @ 0x00460760 ====

undefined8 FUN_00460760(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48;
  }
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      if (DAT_00b5a9a1 == '\x01') break;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return CONCAT44(DAT_00b5a99c,DAT_00b5a998);
}


// ==== FUN_004607b0 @ 0x004607b0 ====

undefined8 FUN_004607b0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar2 = (undefined4 *)*DAT_00b5a9b8;
  while (puVar2 != DAT_00b5a9b8) {
    uVar5 = puVar2[4];
    uVar6 = puVar2[5];
    if (*(int *)puVar2[6] != 0) goto LAB_0046081a;
    if (*(char *)((int)puVar2 + 0x21) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x21);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x21);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x21);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x21);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  uVar5 = 0;
  uVar6 = 0;
LAB_0046081a:
  return CONCAT44(uVar6,uVar5);
}


// ==== FUN_00460820 @ 0x00460820 ====

undefined4 FUN_00460820(uint param_1,int param_2)

{
  int *piVar1;
  int local_4;
  
  local_4 = FUN_00462340(&param_1);
  piVar1 = &local_4;
  if (((local_4 == DAT_00b5a9b8) || (param_2 < *(int *)(local_4 + 0x14))) ||
     ((param_2 <= *(int *)(local_4 + 0x14) && (param_1 < *(uint *)(local_4 + 0x10))))) {
    piVar1 = (int *)&param_1;
  }
  if (*piVar1 == DAT_00b5a9b8) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x18);
}


// ==== FUN_00460880 @ 0x00460880 ====

undefined4 FUN_00460880(undefined4 param_1)

{
  char cVar1;
  undefined4 extraout_EAX;
  char *pcVar2;
  int *piVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 uVar4;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined1 *unaff_EBX;
  int in_stack_00000014;
  undefined4 *in_stack_00000018;
  undefined1 auStack_130 [4];
  uint local_12c;
  undefined1 *puStack_128;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined1 *local_11c;
  undefined1 *local_118;
  undefined1 auStack_f6 [14];
  uint uStack_e8;
  undefined1 auStack_e4 [4];
  void *pvStack_e0;
  undefined4 uStack_d0;
  uint uStack_cc;
  void *pvStack_c4;
  undefined1 local_bc;
  uint uStack_b0;
  undefined4 local_ac;
  void *local_a8;
  undefined1 local_a0;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined1 local_84 [4];
  void *local_80;
  undefined4 local_70;
  void *local_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c8af;
  pvStack_c = ExceptionList;
  local_a8 = (void *)0xf;
  local_ac = 0;
  local_bc = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  if (*(undefined **)(in_stack_00000014 + 4) == &DAT_00b7e238) {
    *in_stack_00000018 = 1;
    FUN_00401740();
  }
  else {
    *in_stack_00000018 = 0;
  }
  local_88 = auStack_130;
  local_118 = (undefined1 *)0xf;
  local_11c = (undefined1 *)0x0;
  local_12c = local_12c & 0xffffff00;
  FUN_00401740(s__I64d_009a0c68,5);
  FUN_00404230(local_84);
  local_4._0_1_ = 1;
  local_118 = (undefined1 *)0x46095a;
  FUN_00405bd0();
  local_4._0_1_ = 3;
  if (0xf < local_6c) {
    _free(local_80);
    return extraout_EAX;
  }
  local_6c = (void *)0xf;
  local_8c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  local_90 = 0;
  local_a0 = 0;
  pcVar2 = PTR_s_RealDataPath_00ae03ec;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  local_4 = CONCAT31(local_4._1_3_,4);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  local_118 = (undefined1 *)(**(code **)(*piVar3 + 8))();
  local_11c = auStack_54;
  pvStack_c._0_1_ = 5;
  puStack_120 = (undefined1 *)0x460a08;
  uStack_124 = FUN_00402220();
  puStack_120 = auStack_e4;
  puStack_128 = auStack_f6 + -10;
  pvStack_c._0_1_ = 6;
  local_12c = 0x460a20;
  FUN_00405bd0();
  if (0xf < uStack_3c) {
    local_118 = (undefined1 *)0x460a39;
    _free(pvStack_50);
    return extraout_EAX_00;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (0xf < uStack_58) {
    local_118 = (undefined1 *)0x460a6c;
    _free(local_6c);
    return extraout_EAX_01;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffffff00);
  pvStack_c._0_1_ = 8;
  if (0xf < uStack_94) {
    local_118 = (undefined1 *)0x460a9c;
    _free(local_a8);
    return extraout_EAX_02;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  local_a8 = (void *)((uint)local_a8 & 0xffffff00);
  FUN_004400d0();
  pvStack_c._0_1_ = 0xb;
  local_118 = unaff_EBX;
  if (uStack_e8 < 0x10) {
    local_118 = auStack_f6 + -6;
  }
  local_11c = (undefined1 *)0x460adc;
  FUN_00440100();
  local_118 = (undefined1 *)param_1;
  local_11c = (undefined1 *)0x460af8;
  cVar1 = FUN_00440420();
  FUN_00440260();
  if (cVar1 == '\0') {
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,8);
    FUN_0043ff50();
    if (0xf < uStack_e8) {
      local_118 = (undefined1 *)0x460bb3;
      _free(unaff_EBX);
      return extraout_EAX_06;
    }
    if (0xf < uStack_cc) {
      local_118 = (undefined1 *)0x460bd2;
      _free(pvStack_e0);
      return extraout_EAX_07;
    }
    uStack_cc = 0xf;
    uStack_d0 = 0;
    pvStack_e0 = (void *)((uint)pvStack_e0 & 0xffffff00);
    if (0xf < uStack_b0) {
      local_118 = (undefined1 *)0x460bf1;
      _free(pvStack_c4);
      return extraout_EAX_08;
    }
    uVar4 = 0;
  }
  else {
    local_118 = (undefined1 *)0x0;
    local_11c = auStack_e4;
    puStack_120 = (undefined1 *)0x460b26;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,8);
    FUN_0043ff50();
    if (0xf < uStack_e8) {
      local_118 = (undefined1 *)0x460b4a;
      _free(unaff_EBX);
      return extraout_EAX_03;
    }
    if (0xf < uStack_cc) {
      local_118 = (undefined1 *)0x460b69;
      _free(pvStack_e0);
      return extraout_EAX_04;
    }
    uStack_cc = 0xf;
    uStack_d0 = 0;
    pvStack_e0 = (void *)((uint)pvStack_e0 & 0xffffff00);
    if (0xf < uStack_b0) {
      local_118 = (undefined1 *)0x460b88;
      _free(pvStack_c4);
      return extraout_EAX_05;
    }
    uVar4 = 1;
  }
  ExceptionList = pvStack_14;
  return uVar4;
}


// ==== FUN_00460c10 @ 0x00460c10 ====

void FUN_00460c10(void)

{
  DWORD DVar1;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c8c1;
  local_c = ExceptionList;
  if (*(HANDLE *)(in_ECX + 4) != (HANDLE)0x0) {
    ExceptionList = &local_c;
    SetThreadPriority(*(HANDLE *)(in_ECX + 4),0);
    DAT_00b5a9a0 = 1;
    DVar1 = WaitForSingleObject(*(HANDLE *)(in_ECX + 4),0);
    if (DVar1 != 0) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401740(s_Timeout_waiting_for_Radial_Threa_009a0c74,0x2a);
      local_4 = 0;
      FUN_00796d50(local_28);
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
      TerminateThread(*(HANDLE *)(in_ECX + 4),0);
    }
    CloseHandle(*(HANDLE *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00460cd0 @ 0x00460cd0 ====

void FUN_00460cd0(undefined1 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  time_t *_Time;
  char cVar1;
  undefined4 uVar2;
  time_t tVar3;
  __time32_t _Var4;
  tm *_Tm;
  char *pcVar5;
  char local_64 [32];
  void *local_44;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c8e3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  _Var4 = FID_conflict___time32((__time32_t *)0x0);
  *(__time32_t *)(param_1 + 0x28) = _Var4;
  *(undefined4 *)(param_1 + 0x24) = param_2[6];
  *(undefined4 *)(param_1 + 0x14) = param_4;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  _Time = (time_t *)(param_1 + 0x24);
  tVar3 = *_Time;
  *(undefined4 *)(param_1 + 8) = *param_2;
  *(undefined4 *)(param_1 + 4) = param_2[2];
  *(int *)(param_1 + 0x18) = (int)param_2[7] / 1000;
  *(undefined4 *)(param_1 + 0x1c) = param_2[8];
  uVar2 = param_2[9];
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  FID_conflict___time32((__time32_t *)0x0);
  FUN_00401740();
  FUN_00404230();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  if (0xf < local_30) {
    _free(local_44);
    return;
  }
  if (*(int *)(param_1 + 0x18) < *(int *)(param_1 + 0x28) - (int)*_Time) {
    FUN_007caf70();
    local_14 = 0xf;
    local_18 = 0;
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    local_4 = 1;
    _localtime(_Time);
    _Tm = _localtime(_Time);
    _strftime(local_64,0x19,s__Y__m__d__H__M__S_009a0d44,_Tm);
    pcVar5 = local_64;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    local_10 = (_Var4 - (int)tVar3) * 1000;
    FUN_00401660();
    local_4._0_1_ = 2;
    FUN_00401660(param_2 + 10,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    (**(code **)(*DAT_00b5a838 + 0x1c))();
    _Var4 = FID_conflict___time32((__time32_t *)0x0);
    param_2[6] = _Var4;
    if (0xf < local_14) {
      _free(local_28);
      return;
    }
  }
  if (*(HGDIOBJ *)(param_1 + 0x2c) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00460f50 @ 0x00460f50 ====

void FUN_00460f50(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  LPCSTR ****lpFileName;
  undefined4 *puVar8;
  int *piVar9;
  undefined1 auStack_82 [2];
  void *pvStack_80;
  undefined1 local_7c [4];
  undefined1 local_78;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined4 local_68;
  LPCSTR ****local_64 [4];
  undefined4 uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c90d;
  pvStack_c = ExceptionList;
  local_64[0] = (LPCSTR ****)0xf;
  local_68 = 0;
  local_78 = 0;
  pcVar4 = PTR_s_RealDataPath_00ae03ec;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740(PTR_s_RealDataPath_00ae03ec,(int)pcVar4 - (int)(PTR_s_RealDataPath_00ae03ec + 1));
  local_4 = 0;
  piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar6 = (**(code **)(*piVar5 + 8))(auStack_44,local_7c);
  pvStack_c._0_1_ = 1;
  FUN_00402220(auStack_30,uVar6,&DAT_009a0cc8);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  if (0xf < uStack_6c) {
    _free(pvStack_80);
    return;
  }
  uStack_6c = 0xf;
  uStack_70 = 0;
  iVar7 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  piVar5 = (int *)*DAT_00b5a9b8;
  piVar9 = DAT_00b5a9b8;
  if (piVar5 != DAT_00b5a9b8) {
    do {
      if ((uint)(iVar7 - *(int *)(piVar5[6] + 4)) < 0x5265c01) {
        if (*(char *)((int)piVar5 + 0x21) == '\0') {
          piVar2 = (int *)piVar5[2];
          if (*(char *)((int)piVar2 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x21);
              piVar5 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x21);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
            while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x21);
              piVar3 = (int *)piVar5[1];
              piVar2 = piVar5;
            }
          }
        }
      }
      else {
        FUN_00405bd0(&local_68,auStack_30,piVar5[6] + 0xc);
        pvStack_c._0_1_ = 5;
        lpFileName = local_64[0];
        if (uStack_50 < 0x10) {
          lpFileName = (LPCSTR ****)local_64;
        }
        DeleteFileA((LPCSTR)lpFileName);
        puVar8 = (undefined4 *)FUN_00459c20(auStack_82 + -6,piVar5);
        piVar5 = (int *)*puVar8;
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
        if (0xf < uStack_50) {
          _free(local_64[0]);
          return;
        }
        uStack_50 = 0xf;
        uStack_54 = 0;
        local_64[0] = (LPCSTR ****)((uint)local_64[0] & 0xffffff00);
        piVar9 = DAT_00b5a9b8;
      }
    } while (piVar5 != piVar9);
  }
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_00461150 @ 0x00461150 ====

void FUN_00461150(void)

{
  undefined4 *in_ECX;
  uint local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097c91f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0d8c;
  local_4 = 0;
  FUN_007cab90();
  SuspendThread((HANDLE)in_ECX[1]);
  FUN_00460c10();
  FUN_00460f50();
  if (DAT_00b5a9bc != 0) {
    local_14 = local_14 & 0xffffff00;
    FUN_004624f0(*DAT_00b5a9b8,DAT_00b5a9b8,local_14);
    FUN_004593a0(DAT_00b5a9b8[1]);
    DAT_00b5a9b8[1] = DAT_00b5a9b8;
    DAT_00b5a9bc = 0;
    *DAT_00b5a9b8 = DAT_00b5a9b8;
    DAT_00b5a9b8[2] = DAT_00b5a9b8;
  }
  *in_ECX = &PTR_FUN_009a0d70;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00461210 @ 0x00461210 ====

/* WARNING: Removing unreachable block (ram,0x00461271) */
/* WARNING: Removing unreachable block (ram,0x00461281) */
/* WARNING: Removing unreachable block (ram,0x00461286) */
/* WARNING: Removing unreachable block (ram,0x0046128f) */
/* WARNING: Removing unreachable block (ram,0x004612af) */
/* WARNING: Removing unreachable block (ram,0x004612b7) */
/* WARNING: Removing unreachable block (ram,0x004612ea) */
/* WARNING: Removing unreachable block (ram,0x004612fa) */
/* WARNING: Removing unreachable block (ram,0x00461347) */
/* WARNING: Removing unreachable block (ram,0x00461366) */
/* WARNING: Removing unreachable block (ram,0x00461355) */
/* WARNING: Removing unreachable block (ram,0x00461368) */
/* WARNING: Removing unreachable block (ram,0x0046138a) */
/* WARNING: Removing unreachable block (ram,0x004614ee) */
/* WARNING: Removing unreachable block (ram,0x004614f2) */
/* WARNING: Removing unreachable block (ram,0x004614f8) */
/* WARNING: Removing unreachable block (ram,0x00461504) */
/* WARNING: Removing unreachable block (ram,0x0046151a) */
/* WARNING: Removing unreachable block (ram,0x0046131f) */

undefined8 FUN_00461210(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097c93f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_007cabe0();
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00461530 @ 0x00461530 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461530(void)

{
  undefined8 uVar1;
  void *_Memory;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined1 local_58 [4];
  void *local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c [12];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c951;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  _Memory = operator_new(0x100000);
  if (DAT_00b5a9c4 != (void *)0x0) {
    _free(DAT_00b5a9c4);
    return;
  }
  DAT_00b5a9c4 = (void *)0x0;
  DAT_00b5a9c8 = 0;
  _DAT_00b5a9cc = 0;
  do {
    uVar1 = CONCAT44(DAT_00b5a99c,DAT_00b5a998);
    uVar5 = 0;
    while( true ) {
      DAT_00b5a99c = (undefined4)((ulonglong)uVar1 >> 0x20);
      DAT_00b5a998 = (undefined4)uVar1;
      if ((DAT_00b5a9a8 == 0) || ((uint)((DAT_00b5a9ac - DAT_00b5a9a8) / 0x48) <= uVar5)) break;
      while( true ) {
        DAT_00b5a99c = (undefined4)((ulonglong)uVar1 >> 0x20);
        DAT_00b5a998 = (undefined4)uVar1;
        if (DAT_00b5a9c4 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = (DAT_00b5a9c8 - (int)DAT_00b5a9c4) / 0x30;
        }
        if ((DAT_00b5a9a8 == 0) || ((uint)((DAT_00b5a9ac - DAT_00b5a9a8) / 0x48) <= uVar3)) break;
        puVar6 = local_3c;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        FUN_00462b70();
        uVar1 = CONCAT44(DAT_00b5a99c,DAT_00b5a998);
      }
      FUN_00401740(s__ppl___d_stock_009a0cb8,0xe);
      uVar2 = FUN_00404230(local_58);
      local_4 = 0;
      FUN_00796d50(uVar2);
      local_4 = 0xffffffff;
      if (0xf < local_40) {
        _free(local_54);
        return;
      }
      local_40 = 0xf;
      local_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      uVar7 = FUN_00461210();
      uVar1 = CONCAT44(DAT_00b5a99c,DAT_00b5a998);
      if (uVar5 == 0) {
        uVar1 = uVar7;
      }
      uVar5 = uVar5 + 1;
    }
    DAT_00b5a9a1 = 1;
    Sleep(5000);
    if (DAT_00b5a9a0 != '\0') {
      _free(_Memory);
      return;
    }
  } while( true );
}


// ==== FUN_00461740 @ 0x00461740 ====

/* WARNING: Removing unreachable block (ram,0x00461aec) */
/* WARNING: Removing unreachable block (ram,0x00461b2b) */
/* WARNING: Removing unreachable block (ram,0x00461b38) */
/* WARNING: Removing unreachable block (ram,0x00461b7a) */
/* WARNING: Removing unreachable block (ram,0x00461aaf) */
/* WARNING: Removing unreachable block (ram,0x00461a72) */
/* WARNING: Removing unreachable block (ram,0x00461a35) */
/* WARNING: Removing unreachable block (ram,0x004619ea) */
/* WARNING: Removing unreachable block (ram,0x004619f5) */
/* WARNING: Removing unreachable block (ram,0x004619f0) */
/* WARNING: Removing unreachable block (ram,0x004619f8) */
/* WARNING: Removing unreachable block (ram,0x0046199a) */
/* WARNING: Removing unreachable block (ram,0x004619b9) */
/* WARNING: Removing unreachable block (ram,0x004619a8) */
/* WARNING: Removing unreachable block (ram,0x004619bb) */
/* WARNING: Removing unreachable block (ram,0x0046191d) */
/* WARNING: Removing unreachable block (ram,0x004619c7) */
/* WARNING: Removing unreachable block (ram,0x00461be3) */
/* WARNING: Removing unreachable block (ram,0x00461a13) */
/* WARNING: Removing unreachable block (ram,0x00461bec) */
/* WARNING: Removing unreachable block (ram,0x00461a50) */
/* WARNING: Removing unreachable block (ram,0x00461bf5) */
/* WARNING: Removing unreachable block (ram,0x00461a8d) */
/* WARNING: Removing unreachable block (ram,0x00461bfe) */
/* WARNING: Removing unreachable block (ram,0x00461aca) */
/* WARNING: Removing unreachable block (ram,0x00461c07) */
/* WARNING: Removing unreachable block (ram,0x00461b58) */
/* WARNING: Removing unreachable block (ram,0x00461973) */

void FUN_00461740(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined1 auStack_ce [2];
  uint uStack_cc;
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  void *pvStack_98;
  undefined1 local_94 [4];
  undefined1 local_90;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  void *pvStack_34;
  undefined1 auStack_30 [16];
  uint uStack_20;
  void *pvStack_1c;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c994;
  pvStack_c = ExceptionList;
  local_7c = 0xf;
  local_80 = 0;
  local_90 = 0;
  pcVar2 = PTR_s_RealDataPath_00ae03ec;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740(PTR_s_RealDataPath_00ae03ec,(int)pcVar2 - (int)(PTR_s_RealDataPath_00ae03ec + 1));
  local_4 = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_44,local_94);
  pvStack_c._0_1_ = 1;
  uVar4 = FUN_00402220(auStack_68,uVar4,&DAT_009a0d30);
  pvStack_c._0_1_ = 2;
  FUN_00402220(auStack_30,uVar4,s_cache_csv_009a0d24);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return;
  }
  uStack_50 = 0xf;
  uStack_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  if (0xf < pvStack_34) {
    _free(pvStack_48);
    return;
  }
  pvStack_34 = (void *)0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a740 + 4))(auStack_30,9);
  if (puVar5 != (undefined4 *)0x0) {
    uStack_cc = 1;
    uVar6 = FUN_00411430();
    if (1 < uVar6) {
      do {
        uStack_14 = 7;
        uVar4 = FUN_00411510(uStack_cc);
        uStack_b0 = 0xf;
        uStack_b4 = 0;
        pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
        FUN_00401660(uVar4,0,0xffffffff);
        uStack_14 = 8;
        FUN_00404fb0(auStack_c8,0x2c,auStack_ce + -0x12);
        if (0xf < uStack_b0) {
          _free(pvStack_c4);
          return;
        }
        pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
        uStack_14 = 4;
        uStack_b0 = 0xf;
        uStack_b4 = 0;
        uStack_cc = uStack_cc + 1;
        uVar6 = FUN_00411430();
      } while (uStack_cc < uVar6);
    }
    (**(code **)*puVar5)(1);
  }
  if (uStack_20 < 0x10) {
    ExceptionList = pvStack_1c;
    return;
  }
  _free(pvStack_34);
  return;
}


// ==== FUN_00461c10 @ 0x00461c10 ====

void FUN_00461c10(void)

{
  HANDLE pvVar1;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097c9a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00461530,(LPVOID)0x0,0,
                        (LPDWORD)(in_ECX + 8));
  *(HANDLE *)(in_ECX + 4) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_Failed_Create_Thread_009a0ca0,0x15);
    local_4 = 0;
    FUN_00796d50(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  else {
    DAT_00b5a9a0 = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00461cc0 @ 0x00461cc0 ====

/* WARNING: Removing unreachable block (ram,0x00462096) */
/* WARNING: Removing unreachable block (ram,0x00461e5e) */
/* WARNING: Removing unreachable block (ram,0x00462184) */
/* WARNING: Type propagation algorithm not settling */

void FUN_00461cc0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int *piVar7;
  LPCSTR ******lpFileName;
  uint uStack_c8;
  LPCSTR ******local_c0 [2];
  undefined4 uStack_b8;
  uint uStack_b4;
  uint uStack_ac;
  undefined4 uStack_a4;
  void *pvStack_9c;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined1 auStack_84 [4];
  void *pvStack_80;
  undefined4 uStack_70;
  uint uStack_6c;
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ca1d;
  pvStack_c = ExceptionList;
  local_4 = 1;
  local_c0[0] = (LPCSTR ******)0xf;
  pcVar6 = PTR_s_RealDataPath_00ae03ec;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = CONCAT31(local_4._1_3_,2);
  piVar7 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar7 + 8))();
  pvStack_c._0_1_ = 3;
  FUN_00402220();
  pvStack_c._0_1_ = 4;
  FUN_00402220();
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (0xf < uStack_88) {
    _free(pvStack_9c);
    return;
  }
  uStack_88 = 0xf;
  uStack_8c = 0;
  pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
  pvStack_c._0_1_ = 6;
  if (0xf < uStack_c8) {
    _free((void *)0x0);
    return;
  }
  FUN_00401740();
  pvStack_c._0_1_ = 9;
  FUN_00411630();
  puVar4 = DAT_00b5a9b8;
  puVar2 = (undefined4 *)*DAT_00b5a9b8;
  while( true ) {
    if (puVar2 == puVar4) {
      pvStack_c._0_1_ = 6;
      lpFileName = local_c0[0];
      if (uStack_ac < 0x10) {
        lpFileName = (LPCSTR ******)local_c0;
      }
      DeleteFileA((LPCSTR)lpFileName);
      (**(code **)(*DAT_00b5a740 + 0xc))();
      if (uStack_b4 < 0x10) {
        uStack_b4 = 0xf;
        uStack_b8 = 0;
        FUN_00405de0();
        _free(&PTR_FUN_0099d55c);
        return;
      }
      _free((void *)0xf);
      return;
    }
    pvStack_c._0_1_ = 6;
    uStack_a4 = puVar2[5];
    piVar7 = (int *)puVar2[6];
    FUN_00401740();
    pvStack_c._0_1_ = 10;
    FUN_00401740(s__I64d__009a0d04,6);
    FUN_00404230(auStack_84);
    pvStack_c._0_1_ = 0xb;
    FUN_00401ff0();
    pvStack_c._0_1_ = 10;
    if (0xf < uStack_6c) {
      _free(pvStack_80);
      return;
    }
    uStack_6c = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    FUN_00401740(&DAT_009a0d0c);
    FUN_00404230();
    pvStack_c._0_1_ = 0xc;
    FUN_00401ff0();
    pvStack_c._0_1_ = 10;
    if (0xf < uStack_50) break;
    uStack_50 = 0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    pcVar6 = s_true__009a0d10;
    if (*piVar7 == 0) {
      pcVar6 = &DAT_009a0d18;
    }
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0();
    FUN_00401740(&DAT_009a0d20);
    FUN_00404230();
    pvStack_c._0_1_ = 0xd;
    FUN_00401ff0();
    pvStack_c._0_1_ = 10;
    if (0xf < uStack_18) {
      _free(pvStack_2c);
      return;
    }
    uStack_18 = 0xf;
    uStack_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    FUN_00401ff0();
    FUN_00411630();
    if (*(char *)((int)puVar2 + 0x21) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x21);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x21);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x21);
        puVar5 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x21);
          puVar5 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  _free(pvStack_64);
  return;
}


// ==== FUN_004621a0 @ 0x004621a0 ====

void FUN_004621a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ca2f;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0d8c;
  in_ECX[1] = 0;
  DAT_00b5a9a0 = 0;
  DAT_00b5a9a1 = 0;
  FUN_00461740();
  FUN_00461c10();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00462200 @ 0x00462200 ====

void FUN_00462200(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ca41;
  pvStack_c = ExceptionList;
  DAT_00b5a998 = 0;
  DAT_00b5a99c = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  FUN_007ca890();
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  FUN_00401740(s_RadStart__d_009a0bfc,0xb);
  uVar1 = FUN_00404230(auStack_28);
  uStack_4 = 0;
  FUN_00403e50(uVar1);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    (**(code **)(*DAT_00b5a6ac + 0x18))();
    DAT_00b5a9a1 = 0;
    FUN_00462c00();
    ResumeThread(*(HANDLE *)(in_ECX + 4));
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00462310 @ 0x00462310 ====

void FUN_00462310(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0xc;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0xc; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00462340 @ 0x00462340 ====

undefined4 * FUN_00462340(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x21) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((int)param_1[1] < (int)puVar2[5]) ||
         (((int)param_1[1] <= (int)puVar2[5] && (*param_1 <= (uint)puVar2[4])))) {
        puVar3 = (undefined4 *)*puVar2;
      }
      else {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  return puVar2;
}


// ==== FUN_00462380 @ 0x00462380 ====

void FUN_00462380(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0xc;
    param_3 = param_3 + -0xc;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_004623b0 @ 0x004623b0 ====

void FUN_004623b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 0xc;
  }
  return;
}


// ==== FUN_004623e0 @ 0x004623e0 ====

void FUN_004623e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[4] = *param_4;
    puVar1[5] = param_4[1];
    puVar1[6] = param_4[2];
    puVar1[7] = param_4[3];
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  return;
}


// ==== FUN_00462430 @ 0x00462430 ====

void FUN_00462430(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 0xc;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_00462460 @ 0x00462460 ====

void FUN_00462460(int *param_1,uint *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00462340(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(int *)(iVar1 + 0x14) <= (int)param_2[1]) &&
       ((*(int *)(iVar1 + 0x14) < (int)param_2[1] || (*(uint *)(iVar1 + 0x10) <= *param_2)))) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_004624c0 @ 0x004624c0 ====

int FUN_004624c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00462430(param_1,param_2,param_3);
  return param_2 * 0x30 + param_1;
}


// ==== FUN_004624f0 @ 0x004624f0 ====

uint FUN_004624f0(int *param_1,int *param_2,byte param_3)

{
  char cVar1;
  void *_Memory;
  int *piVar2;
  int *piVar3;
  uint extraout_EAX;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    _Memory = (void *)param_1[6];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x21) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x21) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x21);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x21);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x21);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  FUN_00446f40();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00462570 @ 0x00462570 ====

void FUN_00462570(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097ca58;
  local_c = ExceptionList;
  if (0xffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004623e0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_00462669:
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
      if ((char)piVar6[8] == '\0') goto LAB_00462669;
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


// ==== FUN_00462750 @ 0x00462750 ====

void FUN_00462750(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 local_4;
  
  puVar3 = param_2;
  puVar5 = *(undefined4 **)(in_ECX + 4);
  bVar2 = true;
  local_4 = 1;
  if (*(char *)((int)puVar5[1] + 0x21) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      if (((int)puVar5[5] < (int)param_2[1]) ||
         (((int)puVar5[5] <= (int)param_2[1] && ((uint)puVar5[4] <= *param_2)))) {
        puVar4 = (undefined4 *)puVar5[2];
        bVar2 = false;
        local_4 = 0;
      }
      else {
        puVar4 = (undefined4 *)*puVar5;
        bVar2 = true;
        local_4 = 1;
      }
    } while (*(char *)((int)puVar4 + 0x21) == '\0');
  }
  param_2 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_00462570(&param_2,1,puVar5,puVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (((int)puVar3[1] < (int)param_2[5]) ||
     (((int)puVar3[1] <= (int)param_2[5] && (*puVar3 <= param_2[4])))) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
  puVar5 = (undefined4 *)FUN_00462570(&param_2,local_4,puVar5,puVar3);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00462830 @ 0x00462830 ====

void FUN_00462830(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint extraout_ECX;
  undefined4 *puVar6;
  undefined4 local_44;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ca70;
  local_10 = ExceptionList;
  puVar6 = &local_44;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x30;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x30;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
    if (0x5555555U - iVar1 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
      FUN_00459bb0();
      uVar5 = extraout_ECX;
    }
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x30;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x5555555 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0x30;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_004ab760();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x30);
      local_8 = 0;
      iVar4 = FUN_004623b0(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_00462430(iVar4,param_2,&local_44);
      FUN_004623b0(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x30);
      iVar4 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x30;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x30 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar4) * 0x30 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)((iVar4 - param_1) / 0x30) < param_2) {
      FUN_004623b0(param_1,iVar4,param_2 * 0x30 + param_1);
      local_8 = 2;
      FUN_004624c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x30,&local_44)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x30;
      FUN_00462310(param_1,*(int *)(in_ECX + 8) + param_2 * -0x30,&local_44);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar4 + param_2 * -0x30;
    uVar3 = FUN_004623b0(iVar1,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_00462380(param_1,iVar1,iVar4);
    FUN_00462310(param_1,param_2 * 0x30 + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004629e3 @ 0x004629e3 ====

void Catch_004629e3(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_00462ae0 @ 0x00462ae0 ====

void FUN_00462ae0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x30 != 0) {
      iVar1 = (param_2 - iVar1) / 0x30;
      goto LAB_00462b25;
    }
  }
  iVar1 = 0;
LAB_00462b25:
  FUN_00462830(param_2,1,param_3);
  *param_1 = iVar1 * 0x30 + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00462b50 @ 0x00462b50 ====

void FUN_00462b50(byte param_1)

{
  void *in_ECX;
  
  FUN_00461150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00462b70 @ 0x00462b70 ====

void FUN_00462b70(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x30) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x30))) {
    FUN_00462ae0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00462430(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x30;
  return;
}


// ==== FUN_00462c00 @ 0x00462c00 ====

void FUN_00462c00(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar6 = *(int *)(param_1 + 8) - iVar1;
    iVar2 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x48 + iVar2;
    uVar7 = iVar6 - iVar2;
    if (iVar6 != iVar2) {
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
      }
      if (uVar7 <= uVar4) {
        uVar5 = FUN_00459ed0(iVar1,*(undefined4 *)(param_1 + 8),iVar2,param_1);
        FUN_0045a330(uVar5,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48) * 0x48;
        return;
      }
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x48;
      }
      if (uVar7 <= uVar4) {
        iVar6 = FUN_00868440();
        iVar6 = iVar1 + iVar6 * 0x48;
        FUN_00459ed0(iVar1,iVar6,iVar2,iVar6);
        uVar5 = FUN_00459fb0(iVar6,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (iVar2 != 0) {
        FUN_0045a330(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar5 = FUN_00868440();
      cVar3 = FUN_0045a0b0(uVar5);
      if (cVar3 == '\0') {
        return;
      }
      uVar5 = FUN_0045a3b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  FUN_0045a360();
  return;
}


// ==== FUN_00462d90 @ 0x00462d90 ====

void FUN_00462d90(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 unaff_EDI;
  
  iVar1 = (**(code **)(*(int *)in_ECX[0x21] + 0xc))();
  if (iVar1 != 0) {
    in_ECX[1] = param_1;
    _AIL_service_stream_8(in_ECX[0x20],1);
    _AIL_set_stream_loop_count_8(in_ECX[0x20],param_1);
    iVar1 = DAT_0099d080;
    if (in_ECX[0x2f] == 0) {
      in_ECX[0x2e] = 1;
    }
    else {
      iVar1 = 0;
      in_ECX[0x2e] = 0;
    }
    in_ECX[0x32] = iVar1;
    *(undefined1 *)(in_ECX + 0x2d) = 1;
    (**(code **)(*in_ECX + 0x14))(unaff_EDI);
    _AIL_start_stream_4(in_ECX[0x20]);
    in_ECX[0x38] = 0;
    in_ECX[0x30] = in_ECX[0x31];
  }
  return;
}


// ==== FUN_00462e40 @ 0x00462e40 ====

void FUN_00462e40(void)

{
  uint *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb4) = 2;
  *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
  if (*(int *)(in_ECX + 0x80) != 0) {
    puVar1 = (uint *)(in_ECX + 0xe0);
    *puVar1 = *puVar1 ^ 1;
    if (*puVar1 == 0) {
      *(undefined1 *)(in_ECX + 0xb4) = 1;
    }
    _AIL_pause_stream_8(*(int *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0xe0));
  }
  return;
}


// ==== FUN_00462e80 @ 0x00462e80 ====

void FUN_00462e80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
  *(undefined4 *)(in_ECX + 0xb8) = 1;
  return;
}


// ==== FUN_00462ea0 @ 0x00462ea0 ====

void FUN_00462ea0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined1 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 200) = uVar1;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  if (*(int *)(in_ECX + 0x80) != 0) {
    _AIL_close_stream_4(*(int *)(in_ECX + 0x80));
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
  return;
}


// ==== FUN_00462f00 @ 0x00462f00 ====

float10 FUN_00462f00(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  
  uVar1 = _AIL_ms_count_0();
  if (*(uint *)(in_ECX + 0xcc) < uVar1) {
    iVar2 = _AIL_stream_position_4(*(undefined4 *)(in_ECX + 0x80));
    fVar3 = ((float)iVar2 * DAT_0099de78) / (float)*(int *)(in_ECX + 0xd4);
    iVar2 = _AIL_ms_count_0();
    *(int *)(in_ECX + 0xcc) = iVar2 + 0xfa;
    if (fVar3 != *(float *)(in_ECX + 0xd0)) {
      *(float *)(in_ECX + 0xd0) = fVar3;
      return (float10)fVar3;
    }
  }
  return (float10)DAT_0099d0dc;
}


// ==== FUN_00462f80 @ 0x00462f80 ====

void FUN_00462f80(float param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x78) = param_1;
  _AIL_set_stream_volume_pan_12
            (*(undefined4 *)(in_ECX + 0x80),*(float *)(in_ECX + 200) * param_1,0x3f000000);
  return;
}


// ==== FUN_00462fc0 @ 0x00462fc0 ====

void FUN_00462fc0(float param_1,char param_2)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0xe8) = param_2;
  *(float *)(in_ECX + 0x78) = param_1;
  if (param_2 == '\0') {
    _AIL_set_stream_volume_pan_12
              (*(undefined4 *)(in_ECX + 0x80),*(float *)(in_ECX + 200) * param_1,0x3f000000);
    return;
  }
  _AIL_set_stream_volume_pan_12(*(undefined4 *)(in_ECX + 0x80),0,0x3f000000);
  return;
}


// ==== FUN_00463020 @ 0x00463020 ====

bool FUN_00463020(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 2;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x84) + 0xc))();
  if (iVar1 != 0) {
    iVar2 = _AIL_stream_status_4(*(undefined4 *)(in_ECX + 0x80));
  }
  return iVar2 == 4;
}


// ==== FUN_00463060 @ 0x00463060 ====

void FUN_00463060(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb4) = 1;
  _AIL_start_stream_4(*(undefined4 *)(in_ECX + 0x80));
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
  return;
}


// ==== FUN_00463090 @ 0x00463090 ====

void FUN_00463090(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[0x21] + 0xc))();
  if (iVar1 != 0) {
    _AIL_service_stream_8(in_ECX[0x20],1);
    _AIL_set_stream_loop_count_8(in_ECX[0x20],in_ECX[1]);
    iVar1 = DAT_0099d080;
    if (in_ECX[0x2f] == 0) {
      in_ECX[0x2e] = 0;
    }
    else {
      iVar1 = 0;
      in_ECX[0x2e] = 1;
    }
    in_ECX[0x32] = iVar1;
    (**(code **)(*in_ECX + 0x14))(in_ECX[0x1e]);
    *(undefined1 *)(in_ECX + 0x2d) = 1;
    _AIL_start_stream_4(in_ECX[0x20]);
    in_ECX[0x38] = 0;
    in_ECX[0x30] = in_ECX[0x31];
  }
  return;
}


// ==== FUN_00463130 @ 0x00463130 ====

void FUN_00463130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0e38;
  if (in_ECX[0x20] != 0) {
    _AIL_close_stream_4(in_ECX[0x20]);
    in_ECX[0x20] = 0;
  }
  if ((uint)in_ECX[0x2b] < 0x10) {
    in_ECX[0x2b] = 0xf;
    in_ECX[0x2a] = 0;
    *(undefined1 *)(in_ECX + 0x26) = 0;
    FUN_004679d0();
    return;
  }
  _free((void *)in_ECX[0x26]);
  return;
}


// ==== FUN_00463190 @ 0x00463190 ====

void FUN_00463190(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00467a60();
  in_ECX[0x21] = param_1;
  *in_ECX = &PTR_FUN_009a0e38;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0xf;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  *(undefined1 *)(in_ECX + 0x3a) = 0;
  in_ECX[0x30] = 0;
  *(undefined1 *)(in_ECX + 0x2d) = 3;
  in_ECX[0x34] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x32] = 0;
  return;
}


// ==== FUN_00463240 @ 0x00463240 ====

uint FUN_00463240(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  undefined4 ****_Memory;
  int iVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  int in_ECX;
  uint unaff_EBX;
  void *unaff_retaddr;
  undefined4 uStack_4c;
  undefined4 ****local_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  uint uStack_1c;
  void *pvStack_18;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097cab8;
  pvStack_c = ExceptionList;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = (undefined4 ****)((uint)local_40 & 0xffffff00);
  local_4 = 1;
  if (param_1 == 2) {
    ExceptionList = &pvStack_c;
    uVar2 = FUN_00405bd0(local_28,in_ECX + 0x40,&param_2);
    local_4._0_1_ = 2;
    FUN_00401660(uVar2,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401660(&param_2,0,0xffffffff);
  }
  _Memory = local_40;
  if (local_2c < 0x10) {
    _Memory = &local_40;
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 0x84) + 0xc))(_Memory,0);
  iVar3 = _AIL_open_stream_12(uVar2);
  if (iVar3 != 0) {
    _AIL_stream_info_20(iVar3,local_28 + -0x2c,0,&puStack_8,local_28 + -0x30);
    uVar1 = *(uint *)(iVar3 + 0x84);
    _AIL_close_stream_4(iVar3);
    if (0xf < unaff_EBX) {
      _free(_Memory);
      return extraout_EAX_02;
    }
    if (local_4 < 0x10) {
      ExceptionList = local_30;
      return uStack_1c / uVar1;
    }
    _free(pvStack_18);
    return extraout_EAX_03;
  }
  if (0xf < uStack_38) {
    _free(uStack_4c);
    return extraout_EAX_00;
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  if (param_5 < 0x10) {
    ExceptionList = pvStack_18;
    return 0;
  }
  _free(unaff_retaddr);
  return extraout_EAX_01;
}


// ==== FUN_004633d0 @ 0x004633d0 ====

uint FUN_004633d0(undefined4 param_1,void *param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7)

{
  int iVar1;
  uint extraout_EAX;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  int in_ECX;
  void *unaff_EBX;
  undefined1 auStack_2a [6];
  void *local_24;
  uint uStack_1c;
  void *pvStack_18;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_0097cada;
  local_c = ExceptionList;
  local_4 = (void *)0x0;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620();
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    uVar3 = 0;
  }
  else {
    FUN_00405bd0();
    local_4._0_1_ = 1;
    FUN_00401660();
    local_4 = (void *)((uint)local_4._1_3_ << 8);
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX;
    }
    FUN_00401660();
    if (*(int *)(in_ECX + 0x80) != 0) {
      *(undefined1 *)(in_ECX + 0xb4) = 0;
      *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
      *(undefined4 *)(in_ECX + 0xb8) = 1;
    }
    (**(code **)(**(int **)(in_ECX + 0x84) + 0xc))();
    iVar1 = _AIL_open_stream_12();
    *(int *)(in_ECX + 0x80) = iVar1;
    if (iVar1 == 0) {
      FUN_00401740(s__s_file_not_load_009a0de0,0x12);
      uVar2 = FUN_00404230(auStack_2a + -10);
      uVar3 = FUN_00796d50(uVar2);
      if (0xf < uStack_1c) {
        _free(unaff_EBX);
        return extraout_EAX_00;
      }
      if (param_4 < 0x10) {
        ExceptionList = pvStack_18;
        return uVar3 & 0xffffff00;
      }
      _free(local_4);
      return extraout_EAX_01;
    }
    _AIL_stream_info_20();
    uVar3 = *(uint *)(in_ECX + 0xd4) / *(uint *)(*(int *)(in_ECX + 0x80) + 0x84);
    *(uint *)(in_ECX + 0xe4) = uVar3;
  }
  if (param_7 < 0x10) {
    ExceptionList = local_c;
    return CONCAT31((int3)(uVar3 >> 8),1);
  }
  _free(param_2);
  return extraout_EAX_02;
}


// ==== FUN_004635d0 @ 0x004635d0 ====

uint FUN_004635d0(undefined4 param_1,void *param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5,void *param_6,uint param_7,undefined4 param_8,void *param_9,
                 undefined4 param_10,uint param_11,undefined4 param_12,undefined4 param_13,
                 uint param_14)

{
  int iVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  int in_ECX;
  void *unaff_EBX;
  undefined1 auStack_2a [6];
  void *local_24;
  uint uStack_1c;
  void *pvStack_18;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_0097cb04;
  local_c = ExceptionList;
  local_4 = (void *)0x1;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620();
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    if (0xf < param_7) {
      _free(param_2);
      return extraout_EAX;
    }
    uVar3 = 0;
  }
  else {
    FUN_00405bd0();
    local_4._0_1_ = 2;
    FUN_00401660();
    local_4 = (void *)CONCAT31(local_4._1_3_,1);
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX_00;
    }
    FUN_00401660();
    if (*(int *)(in_ECX + 0x80) != 0) {
      *(undefined1 *)(in_ECX + 0xb4) = 0;
      *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
      *(undefined4 *)(in_ECX + 0xb8) = 1;
    }
    (**(code **)(**(int **)(in_ECX + 0x84) + 0xc))();
    iVar1 = _AIL_open_stream_12();
    *(int *)(in_ECX + 0x80) = iVar1;
    if (iVar1 == 0) {
      FUN_00401740(s__s_file_not_load_009a0df4,0x12);
      uVar2 = FUN_00404230(auStack_2a + -10);
      uVar3 = FUN_00796d50(uVar2);
      if (0xf < uStack_1c) {
        _free(unaff_EBX);
        return extraout_EAX_01;
      }
      if (0xf < param_4) {
        _free(local_4);
        return extraout_EAX_02;
      }
      if (param_11 < 0x10) {
        ExceptionList = pvStack_18;
        return uVar3 & 0xffffff00;
      }
      _free(param_6);
      return extraout_EAX_03;
    }
    _AIL_stream_info_20();
    uVar3 = *(uint *)(in_ECX + 0xd4) / *(uint *)(*(int *)(in_ECX + 0x80) + 0x84);
    *(uint *)(in_ECX + 0xe4) = uVar3;
    if (0xf < param_7) {
      _free(param_2);
      return extraout_EAX_04;
    }
  }
  if (param_14 < 0x10) {
    ExceptionList = local_c;
    return CONCAT31((int3)(uVar3 >> 8),1);
  }
  _free(param_9);
  return extraout_EAX_05;
}


// ==== FUN_00463810 @ 0x00463810 ====

void FUN_00463810(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined1 *in_stack_00000028;
  undefined1 auStack_58 [12];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined4 *puStack_40;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097cb26;
  local_c = ExceptionList;
  local_4 = 0;
  puStack_40 = param_2;
  if (in_stack_0000001c < 0x10) {
    puStack_40 = &param_2;
  }
  puStack_44 = *(undefined1 **)(in_ECX + 0x38);
  uStack_48 = 0;
  uStack_4c = 0x46385c;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620();
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    *(undefined1 *)(in_ECX + 0xb4) = 1;
    puStack_40 = (undefined4 *)0x463878;
    _AIL_start_stream_4();
    *(undefined4 *)(in_ECX + 0xe0) = 0;
    *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
  }
  else {
    puStack_44 = &param_1;
    if (*(int *)(in_ECX + 0x80) == 0) {
      puStack_40 = (undefined4 *)(in_ECX + 0x40);
      puStack_44 = local_28;
      uStack_48 = 0x463921;
      puStack_44 = (undefined1 *)FUN_00405bd0();
      puStack_40 = (undefined4 *)0x0;
      local_4._0_1_ = 1;
      uStack_48 = 0x463937;
      FUN_00401660();
      local_4 = (uint)local_4._1_3_ << 8;
      if (0xf < local_10) {
        puStack_40 = (undefined4 *)0x46394c;
        _free(local_24);
        return;
      }
      puStack_40 = (undefined4 *)0x0;
      puStack_44 = &param_1;
      uStack_48 = 0x46395e;
      FUN_00401660();
      *(undefined1 **)(in_ECX + 0xbc) = in_stack_00000028;
      *(undefined4 *)(in_ECX + 4) = in_stack_00000020;
      if (*(uint *)(in_ECX + 0x74) < 0x10) {
        puStack_40 = (undefined4 *)(in_ECX + 0x60);
      }
      else {
        puStack_40 = *(undefined4 **)(in_ECX + 0x60);
      }
      puStack_44 = (undefined1 *)0x46398e;
      puStack_44 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 0x84) + 0xc))();
      uStack_48 = 0x463995;
      iVar1 = _AIL_open_stream_12();
      *(int *)(in_ECX + 0x80) = iVar1;
      if (iVar1 == 0) {
        in_stack_00000028 = auStack_58;
        FUN_00401830(s__s_file_not_load_009a0e08);
        uVar2 = FUN_00404230(local_28);
        local_4._0_1_ = 2;
        FUN_00796d50(uVar2);
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_10) {
          puStack_40 = (undefined4 *)0x4639ef;
          _free(local_24);
          return;
        }
      }
      *(undefined4 *)(in_ECX + 0x78) = in_stack_00000024;
      FUN_00463090();
    }
    else {
      puStack_40 = (undefined4 *)0x0;
      *(undefined4 *)(in_ECX + 0xb8) = 1;
      *(undefined4 *)(in_ECX + 0x88) = 1;
      *(undefined1 *)(in_ECX + 0xb4) = 0;
      *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
      *(undefined4 *)(in_ECX + 0x8c) = in_stack_00000020;
      *(undefined4 *)(in_ECX + 0x90) = in_stack_00000024;
      uStack_48 = 0x4638f4;
      FUN_00401660();
      *(undefined1 **)(in_ECX + 0xb0) = in_stack_00000028;
    }
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  puStack_40 = (undefined4 *)0x463a14;
  _free(param_2);
  return;
}


// ==== FUN_00463a30 @ 0x00463a30 ====

undefined4
FUN_00463a30(void *param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5,
            void *param_6,undefined4 param_7,void *param_8,undefined4 param_9,undefined4 param_10,
            uint param_11,undefined4 param_12,uint param_13,undefined4 param_14,undefined4 param_15)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar2;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  int in_ECX;
  void *unaff_EBP;
  undefined1 auStack_26 [2];
  void *local_24;
  uint uStack_1c;
  void *pvStack_18;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_0097cb50;
  pvStack_c = ExceptionList;
  local_4 = (void *)0x1;
  ExceptionList = &pvStack_c;
  iVar1 = FUN_00403620();
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    *(undefined1 *)(in_ECX + 0xb4) = 1;
    _AIL_start_stream_4();
    *(undefined4 *)(in_ECX + 0xe0) = 0;
    *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(in_ECX + 0xc4);
    if ((void *)0xf < param_6) {
      _free(param_1);
      return extraout_EAX;
    }
  }
  else {
    if (*(int *)(in_ECX + 0x80) != 0) {
      FUN_00462ea0();
    }
    FUN_00405bd0();
    local_4._0_1_ = 2;
    FUN_00401660();
    local_4 = (void *)CONCAT31(local_4._1_3_,1);
    if ((void *)0xf < local_10) {
      _free(local_24);
      return extraout_EAX_00;
    }
    FUN_00401660();
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    *(undefined4 *)(in_ECX + 4) = param_15;
    (**(code **)(**(int **)(in_ECX + 0x84) + 0xc))();
    iVar1 = _AIL_open_stream_12();
    *(int *)(in_ECX + 0x80) = iVar1;
    if (iVar1 == 0) {
      FUN_00401740(s__s_file_not_load_009a0e1c,0x12);
      uVar2 = FUN_00404230(auStack_26 + -0xe);
      FUN_00796d50(uVar2);
      if (0xf < uStack_1c) {
        _free(unaff_EBP);
        return extraout_EAX_01;
      }
      if (0xf < param_4) {
        _free(local_4);
        return extraout_EAX_02;
      }
      if (param_11 < 0x10) {
        ExceptionList = pvStack_18;
        return 0;
      }
      _free(param_6);
      return extraout_EAX_03;
    }
    *(uint *)(in_ECX + 0x78) = param_13;
    _AIL_stream_info_20();
    *(uint *)(in_ECX + 0xe4) = *(uint *)(in_ECX + 0xd4) / *(uint *)(*(int *)(in_ECX + 0x80) + 0x84);
    FUN_00463090();
    if ((void *)0xf < param_6) {
      _free(param_1);
      return extraout_EAX_04;
    }
  }
  if (param_13 < 0x10) {
    ExceptionList = local_10;
    return 1;
  }
  _free(param_8);
  return extraout_EAX_05;
}


// ==== FUN_00463ca0 @ 0x00463ca0 ====

void FUN_00463ca0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x80) != 0) {
    _AIL_close_stream_4();
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  if (*(int *)(in_ECX + 0x88) == 1) {
    *(undefined4 *)(in_ECX + 0x88) = 0;
    FUN_00401660(in_ECX + 0x94,0,0xffffffff);
    FUN_00463810();
  }
  return;
}


// ==== FUN_00463d20 @ 0x00463d20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463d20(int param_1)

{
  char cVar1;
  int iVar2;
  float fVar3;
  int *in_ECX;
  float fVar4;
  
  iVar2 = in_ECX[0x2f];
  in_ECX[0x31] = param_1;
  if ((iVar2 == 0) || (in_ECX[0x2e] == 0)) {
    in_ECX[0x32] = (int)DAT_0099d080;
    return;
  }
  fVar4 = (float)(param_1 - in_ECX[0x30]);
  if (param_1 - in_ECX[0x30] < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  fVar3 = (float)iVar2;
  if (iVar2 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  fVar4 = fVar4 / fVar3;
  cVar1 = (char)in_ECX[0x2d];
  if (cVar1 == '\0') {
    fVar4 = DAT_0099d080 - fVar4;
    in_ECX[0x32] = (int)fVar4;
    if (fVar4 <= 0.0) {
      in_ECX[0x32] = 0;
      in_ECX[0x2e] = 0;
      FUN_00463ca0();
    }
  }
  else {
    if (cVar1 == '\x01') {
      if (DAT_0099d080 <= fVar4) {
        in_ECX[0x32] = (int)DAT_0099d080;
        in_ECX[0x2e] = 0;
        (**(code **)(*in_ECX + 0x14))(in_ECX[0x1e]);
        return;
      }
      in_ECX[0x32] = (int)fVar4;
      (**(code **)(*in_ECX + 0x14))(in_ECX[0x1e]);
      return;
    }
    if ((cVar1 == '\x02') && (fVar4 = DAT_0099d080 - fVar4, in_ECX[0x32] = (int)fVar4, fVar4 <= 0.0)
       ) {
      in_ECX[0x32] = 0;
      FUN_00462e40();
      (**(code **)(*in_ECX + 0x14))(in_ECX[0x1e]);
      return;
    }
  }
  (**(code **)(*in_ECX + 0x14))(in_ECX[0x1e]);
  return;
}


// ==== FUN_00463e80 @ 0x00463e80 ====

float10 FUN_00463e80(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x78);
}


// ==== FUN_00463e90 @ 0x00463e90 ====

void FUN_00463e90(byte param_1)

{
  void *in_ECX;
  
  FUN_00463130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00463eb0 @ 0x00463eb0 ====

int FUN_00463eb0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x40,0,0xffffffff);
  return param_1;
}


// ==== FUN_00463ee0 @ 0x00463ee0 ====

int FUN_00463ee0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x5c,0,0xffffffff);
  return param_1;
}


// ==== FUN_00463f10 @ 0x00463f10 ====

void FUN_00463f10(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ca88;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00463f70 @ 0x00463f70 ====

void FUN_00463f70(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ca88;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00463fd0 @ 0x00463fd0 ====

void FUN_00463fd0(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ca88;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00464030 @ 0x00464030 ====

void FUN_00464030(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xac) != 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    iVar1 = _AIL_sample_status_4(*(int *)(in_ECX + 0x80));
    if (iVar1 == 4) {
      _AIL_stop_sample_4(*(undefined4 *)(in_ECX + 0x80));
    }
  }
  return;
}


// ==== FUN_00464070 @ 0x00464070 ====

void FUN_00464070(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xac) != 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    _AIL_end_sample_4(*(int *)(in_ECX + 0x80));
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  return;
}


// ==== FUN_004640a0 @ 0x004640a0 ====

void FUN_004640a0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xac) != 0) && (*(int *)(in_ECX + 0x80) != 0)) {
    iVar1 = _AIL_sample_status_4(*(int *)(in_ECX + 0x80));
    if (iVar1 == 4) {
      _AIL_resume_sample_4(*(undefined4 *)(in_ECX + 0x80));
    }
  }
  return;
}


// ==== FUN_00464110 @ 0x00464110 ====

bool FUN_00464110(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x80) == 0) || (*(int *)(in_ECX + 0xac) == 0)) {
    return false;
  }
  iVar1 = _AIL_sample_status_4(*(int *)(in_ECX + 0x80));
  return iVar1 == 4;
}


// ==== FUN_00464140 @ 0x00464140 ====

void FUN_00464140(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  float unaff_retaddr;
  
  *(undefined4 *)(in_ECX + 0x78) = param_2;
  if ((*(int *)(in_ECX + 0x80) != 0) && (*(int *)(in_ECX + 0xac) != 0)) {
    iVar1 = _AIL_sample_status_4(*(int *)(in_ECX + 0x80));
    if (iVar1 == 4) {
      _AIL_set_sample_volume_pan_12
                (*(undefined4 *)(in_ECX + 0x80),
                 *(float *)(in_ECX + 0x78) * DAT_009a09b8 * unaff_retaddr,param_2);
    }
  }
  return;
}


// ==== FUN_004641a0 @ 0x004641a0 ====

void FUN_004641a0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cb76;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a0eac;
  local_4 = 1;
  if ((in_ECX[0x2b] != 0) && (in_ECX[0x20] != 0)) {
    _AIL_end_sample_4(in_ECX[0x20]);
    in_ECX[0x20] = 0;
  }
  if (in_ECX[0x22] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x22]);
    in_ECX[0x22] = 0;
  }
  if ((uint)in_ECX[0x29] < 0x10) {
    in_ECX[0x29] = 0xf;
    in_ECX[0x28] = 0;
    *(undefined1 *)(in_ECX + 0x24) = 0;
    local_4 = 0xffffffff;
    FUN_004679d0();
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[0x24]);
  return;
}


// ==== FUN_00464260 @ 0x00464260 ====

void FUN_00464260(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097cb96;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00467a60();
  *in_ECX = &PTR_FUN_009a0eac;
  in_ECX[0x29] = 0xf;
  in_ECX[0x28] = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  local_4 = 1;
  in_ECX[0x2b] = param_1;
  in_ECX[0x20] = 0;
  in_ECX[0x22] = 0;
  FUN_00401740(&DAT_009a0ea2,0);
  in_ECX[0x2a] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004642f0 @ 0x004642f0 ====

undefined4 FUN_004642f0(undefined1 param_1,void *param_2)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  int in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cbb0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  iVar1 = FUN_00464400(in_ECX + 0x24);
  *(int *)(in_ECX + 0x88) = iVar1;
  if (iVar1 == 0) {
    if (in_stack_0000001c < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    _free(param_2);
    return extraout_EAX;
  }
  uVar2 = FUN_00405b90(local_28,in_stack_00000018 + -3,in_stack_00000018);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return 1;
  }
  _free(param_2);
  return extraout_EAX_01;
}


// ==== FUN_004643d0 @ 0x004643d0 ====

void FUN_004643d0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x78) = param_1;
  return;
}


// ==== FUN_004643e0 @ 0x004643e0 ====

void FUN_004643e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004641a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00464400 @ 0x00464400 ====

undefined4 FUN_00464400(undefined4 param_1)

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
  puStack_8 = &LAB_0097cbc8;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x1a;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 0xc))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_00464490 @ 0x00464490 ====

void FUN_00464490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0f64;
  return;
}


// ==== FUN_004644a0 @ 0x004644a0 ====

void FUN_004644a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0f64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004644d0 @ 0x004644d0 ====

void FUN_004644d0(void)

{
  int iVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))();
  iVar1 = in_ECX[4];
  in_ECX[4] = in_ECX[5];
  in_ECX[5] = iVar1;
                    /* WARNING: Could not recover jumptable at 0x004644ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a990 + 0x14))();
  return;
}


// ==== FUN_004644f0 @ 0x004644f0 ====

uint FUN_004644f0(void)

{
  uint in_EAX;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0xc) == 0) &&
      ((in_EAX = *(uint *)(in_ECX + 0x10), in_EAX == 0 || (*(int *)(in_EAX + 0x10) == 0)))) &&
     ((*(int *)(in_ECX + 0x14) == 0 || (*(int *)(*(int *)(in_ECX + 0x14) + 0x10) == 0)))) {
    return CONCAT31((int3)(in_EAX >> 8),1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00464520 @ 0x00464520 ====

void FUN_00464520(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  int local_8;
  undefined4 uStack_4;
  
  local_8 = *(int *)(in_ECX + 0xc);
  if (local_8 != 0) {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x10001;
    *(undefined2 *)((int)pvVar2 + 6) = 0x10;
    uStack_4 = FUN_004244d0();
    (**(code **)(*DAT_00b5a71c + 4))(&local_8);
  }
  return;
}


// ==== FUN_00464580 @ 0x00464580 ====

void FUN_00464580(int param_1)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    local_10 = *(undefined4 *)(param_1 + 0x10);
    local_c = *(undefined4 *)(param_1 + 0x14);
    local_8 = *(undefined4 *)(param_1 + 0x18);
    local_4 = *(undefined4 *)(param_1 + 0x1c);
    if (*(char *)(in_ECX + 10) == '\0') {
      (**(code **)(*DAT_00b5a6ac + 4))();
      *(undefined1 *)(in_ECX + 10) = 1;
      return;
    }
    (**(code **)(*DAT_00b5a6ac + 8))(&local_10);
  }
  return;
}


// ==== FUN_004645e0 @ 0x004645e0 ====

undefined4 FUN_004645e0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if (*(int *)(iVar1 + 0x10) == 0) {
    return 0;
  }
  uVar3 = *(uint *)(iVar1 + 0xc) >> 2;
  iVar4 = uVar3 * -4;
  if (*(uint *)(iVar1 + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(iVar1 + 8);
  }
  uVar2 = *(undefined4 *)
           (*(int *)(*(int *)(iVar1 + 4) + uVar3 * 4) + (*(uint *)(iVar1 + 0xc) + iVar4) * 4);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
    if ((uint)(*(int *)(iVar1 + 8) * 4) <= *(uint *)(iVar1 + 0xc)) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    iVar4 = *(int *)(iVar1 + 0x10) + -1;
    *(int *)(iVar1 + 0x10) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
  }
  return uVar2;
}


// ==== __break @ 0x00464649 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00464650 @ 0x00464650 ====

void FUN_00464650(void)

{
  int *piVar1;
  void *_Memory;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)**(int **)(in_ECX + 0x24);
  if (piVar1 == *(int **)(in_ECX + 0x24)) {
    FUN_00465630(*(undefined4 *)(*(int *)(in_ECX + 0x24) + 4));
    *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
    return;
  }
  _Memory = (void *)piVar1[4];
  if (*(int *)((int)_Memory + 0x10) == 0) {
    thunk_FUN_0046cfc0();
    _free(_Memory);
    return;
  }
  uVar3 = *(uint *)((int)_Memory + 0xc) >> 1;
  iVar2 = uVar3 * -2;
  if (*(uint *)((int)_Memory + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)((int)_Memory + 8);
  }
  _free(*(void **)(*(int *)(*(int *)((int)_Memory + 4) + uVar3 * 4) + 4 +
                  (*(uint *)((int)_Memory + 0xc) + iVar2) * 8));
  return;
}


// ==== FUN_00464750 @ 0x00464750 ====

void FUN_00464750(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_2c;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cc08;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(in_ECX + 8) = *(undefined2 *)(param_1 + 8);
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x10000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  local_2c = FUN_004244d0();
  *(undefined4 *)(local_2c + 0x14) = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(local_2c + 0x18) = *(undefined2 *)(in_ECX + 8);
  *(undefined1 *)(local_2c + 0x10) = 0;
  (**(code **)(*DAT_00b5a71c + 4))();
  FUN_00401740(s___Controller___Connecting_to__u__009a0f20,0x2e);
  uVar2 = FUN_00404230(&local_2c);
  puStack_8 = (undefined1 *)0x0;
  FUN_00796d20(uVar2);
  if (uStack_14 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_00464850 @ 0x00464850 ====

void FUN_00464850(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cc1a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a990 + 0xc))();
  if (param_1 != 0) {
    FUN_00424500();
    FUN_00401740(s_packet_send__X_009a0f50,0xe);
    uVar1 = FUN_00404230(auStack_2c);
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d50(uVar1);
    puStack_8 = (undefined1 *)0xffffffff;
    if ((void *)0xf < pvStack_14) {
      _free(pvStack_28);
      return;
    }
    pvStack_14 = (void *)0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  }
  (**(code **)(*DAT_00b5a71c + 4))();
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00464920 @ 0x00464920 ====

void FUN_00464920(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 *in_ECX;
  int iVar5;
  undefined1 local_34 [4];
  int local_30;
  undefined4 local_2c;
  void *pvStack_28;
  undefined1 uStack_24;
  uint uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cc3f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a0fb4;
  local_4 = 1;
  if (in_ECX[3] != 0) {
    local_30 = in_ECX[3];
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = 0;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x10001;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    local_2c = FUN_004244d0();
    (**(code **)(*DAT_00b5a71c + 4))(&local_30);
    in_ECX[3] = 0;
  }
  iVar1 = *(int *)(in_ECX[4] + 0x10);
  while (iVar1 != 0) {
    iVar1 = in_ECX[4];
    uVar4 = *(uint *)(iVar1 + 0xc) >> 2;
    iVar5 = uVar4 * -4;
    if (*(uint *)(iVar1 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar1 + 8);
    }
    puVar2 = *(undefined4 **)
              (*(int *)(*(int *)(iVar1 + 4) + uVar4 * 4) + (*(uint *)(iVar1 + 0xc) + iVar5) * 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    iVar1 = in_ECX[4];
    if (*(int *)(iVar1 + 0x10) != 0) {
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
      if ((uint)(*(int *)(iVar1 + 8) * 4) <= *(uint *)(iVar1 + 0xc)) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      iVar5 = *(int *)(iVar1 + 0x10) + -1;
      *(int *)(iVar1 + 0x10) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
    }
    iVar1 = *(int *)(in_ECX[4] + 0x10);
  }
  iVar1 = *(int *)(in_ECX[5] + 0x10);
  while (iVar1 != 0) {
    iVar1 = in_ECX[5];
    uVar4 = *(uint *)(iVar1 + 0xc) >> 2;
    iVar5 = uVar4 * -4;
    if (*(uint *)(iVar1 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar1 + 8);
    }
    puVar2 = *(undefined4 **)
              (*(int *)(*(int *)(iVar1 + 4) + uVar4 * 4) + (*(uint *)(iVar1 + 0xc) + iVar5) * 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    iVar1 = in_ECX[5];
    if (*(int *)(iVar1 + 0x10) != 0) {
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
      if ((uint)(*(int *)(iVar1 + 8) * 4) <= *(uint *)(iVar1 + 0xc)) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      iVar5 = *(int *)(iVar1 + 0x10) + -1;
      *(int *)(iVar1 + 0x10) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
    }
    iVar1 = *(int *)(in_ECX[5] + 0x10);
  }
  pvVar3 = (void *)in_ECX[4];
  if (pvVar3 != (void *)0x0) {
    FUN_0046cfc0();
    _free(pvVar3);
    return;
  }
  pvVar3 = (void *)in_ECX[5];
  in_ECX[4] = 0;
  if (pvVar3 != (void *)0x0) {
    FUN_0046cfc0();
    _free(pvVar3);
    return;
  }
  in_ECX[5] = 0;
  FUN_00464650();
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  FUN_00401740(s_setdelaypacket_009a0eec,0xe);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_28);
  if (uStack_14 < 0x10) {
    DAT_00b5a83c = 0;
    puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
    FUN_00465b00(local_34,*(undefined4 *)in_ECX[9],(undefined4 *)in_ECX[9]);
    _free((void *)in_ECX[9]);
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_00464b50 @ 0x00464b50 ====

void FUN_00464b50(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cc64;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a0fb4;
  in_ECX[1] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[7] = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[9] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  local_4._0_1_ = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a83c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a83c = in_ECX;
  }
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  }
  in_ECX[4] = pvVar2;
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  }
  in_ECX[5] = pvVar2;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  FUN_00401740(s_setdelaypacket_009a0edc,0xe);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_28,2);
  if (uStack_18 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00464c90 @ 0x00464c90 ====

void FUN_00464c90(undefined4 param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  void *pvVar3;
  int aiStack_10 [2];
  int iStack_8;
  void *pvStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  iVar1 = iVar1 + *(int *)(in_ECX + 0x1c);
  iStack_8 = param_2;
  pvStack_4 = (void *)param_1;
  aiStack_10[0] = iVar1;
  FUN_0079bba0(&param_2,aiStack_10);
  if (param_2 != *(int *)(in_ECX + 0x24)) {
    FUN_00465e40(&iStack_8);
    return;
  }
  pvVar2 = operator_new(0x14);
  pvVar3 = (void *)0x0;
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
    pvVar3 = pvVar2;
  }
  FUN_00465e40(&iStack_8);
  iStack_8 = iVar1;
  pvStack_4 = pvVar3;
  FUN_00465c30(aiStack_10,&iStack_8);
  return;
}


// ==== FUN_00464d40 @ 0x00464d40 ====

void FUN_00464d40(void)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puStack_14;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cc85;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if ((*(int *)(in_ECX + 0x28) == 0) ||
     (iStack_10 = **(int **)(in_ECX + 0x24), uVar4 < *(uint *)(iStack_10 + 0xc))) {
    ExceptionList = pvStack_c;
    return;
  }
  _Memory = *(void **)(iStack_10 + 0x10);
  iVar7 = *(int *)((int)_Memory + 0x10);
  while (iVar7 != 0) {
    uVar4 = *(uint *)((int)_Memory + 0xc) >> 1;
    iVar7 = *(uint *)((int)_Memory + 0xc) + uVar4 * -2;
    if (*(uint *)((int)_Memory + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)((int)_Memory + 8);
    }
    iVar1 = *(int *)(*(int *)((int)_Memory + 4) + uVar4 * 4);
    iVar2 = *(int *)(iVar1 + iVar7 * 8);
    uVar3 = *(undefined4 *)(iVar1 + 4 + iVar7 * 8);
    if (iVar2 == 1) {
      FUN_00464850(uVar3);
    }
    else if (iVar2 == 2) {
      (**(code **)(*DAT_00b5a990 + 0x10))(uVar3);
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        uStack_4 = 1;
        *puVar5 = &PTR_FUN_009a0f78;
        *(undefined1 *)(puVar5 + 1) = 0;
        puStack_14 = puVar5;
        uVar6 = FUN_00424500();
        puVar5[2] = uVar6;
        puVar5[3] = uVar3;
      }
      uStack_4 = 0xffffffff;
      puStack_14 = puVar5;
      FUN_00460680(&puStack_14);
    }
    if (*(int *)((int)_Memory + 0x10) != 0) {
      *(int *)((int)_Memory + 0xc) = *(int *)((int)_Memory + 0xc) + 1;
      if ((uint)(*(int *)((int)_Memory + 8) * 2) <= *(uint *)((int)_Memory + 0xc)) {
        *(undefined4 *)((int)_Memory + 0xc) = 0;
      }
      iVar7 = *(int *)((int)_Memory + 0x10) + -1;
      *(int *)((int)_Memory + 0x10) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)((int)_Memory + 0xc) = 0;
      }
    }
    iVar7 = *(int *)((int)_Memory + 0x10);
  }
  FUN_0046cfc0();
  _free(_Memory);
  return;
}


// ==== FUN_00464eb0 @ 0x00464eb0 ====

void FUN_00464eb0(void)

{
  int *piVar1;
  void *_Memory;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  int iVar8;
  undefined4 *puStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cca6;
  local_c = ExceptionList;
  piVar1 = (int *)**(int **)(in_ECX + 0x24);
  if (piVar1 == *(int **)(in_ECX + 0x24)) {
    ExceptionList = &local_c;
    FUN_00465630(*(undefined4 *)(*(int *)(in_ECX + 0x24) + 4));
    *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
    ExceptionList = local_c;
    return;
  }
  _Memory = (void *)piVar1[4];
  iVar8 = *(int *)((int)_Memory + 0x10);
  ExceptionList = &local_c;
  while (iVar8 != 0) {
    uVar5 = *(uint *)((int)_Memory + 0xc) >> 1;
    iVar8 = *(uint *)((int)_Memory + 0xc) + uVar5 * -2;
    if (*(uint *)((int)_Memory + 8) <= uVar5) {
      uVar5 = uVar5 - *(uint *)((int)_Memory + 8);
    }
    iVar2 = *(int *)(*(int *)((int)_Memory + 4) + uVar5 * 4);
    iVar3 = *(int *)(iVar2 + iVar8 * 8);
    uVar4 = *(undefined4 *)(iVar2 + 4 + iVar8 * 8);
    if (iVar3 == 1) {
      FUN_00464850(uVar4);
    }
    else if (iVar3 == 2) {
      (**(code **)(*DAT_00b5a990 + 0x10))(uVar4);
      puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        uStack_4 = 1;
        *puVar6 = &PTR_FUN_009a0f78;
        *(undefined1 *)(puVar6 + 1) = 0;
        puStack_10 = puVar6;
        uVar7 = FUN_00424500();
        puVar6[2] = uVar7;
        puVar6[3] = uVar4;
      }
      uStack_4 = 0xffffffff;
      puStack_10 = puVar6;
      FUN_00460680(&puStack_10);
    }
    if (*(int *)((int)_Memory + 0x10) != 0) {
      *(int *)((int)_Memory + 0xc) = *(int *)((int)_Memory + 0xc) + 1;
      if ((uint)(*(int *)((int)_Memory + 8) * 2) <= *(uint *)((int)_Memory + 0xc)) {
        *(undefined4 *)((int)_Memory + 0xc) = 0;
      }
      iVar8 = *(int *)((int)_Memory + 0x10) + -1;
      *(int *)((int)_Memory + 0x10) = iVar8;
      if (iVar8 == 0) {
        *(undefined4 *)((int)_Memory + 0xc) = 0;
      }
    }
    iVar8 = *(int *)((int)_Memory + 0x10);
  }
  FUN_0046cfc0();
  _free(_Memory);
  return;
}


// ==== FUN_00465070 @ 0x00465070 ====

undefined4 FUN_00465070(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int iVar3;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ccc0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_setdelaypacket_009a0f10,0xe);
  if (iVar1 != 0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_00459160(local_28,0);
  local_4 = 0;
  iVar1 = thunk_FUN_00796e60(uVar2);
  local_4 = 0xffffffff;
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX;
  }
  uVar2 = FUN_00459160(auStack_44,1);
  local_4 = 1;
  iVar3 = thunk_FUN_00796fb0(uVar2);
  local_4 = 0xffffffff;
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return extraout_EAX_00;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (((bool)*(char *)(in_ECX + 0x18) != (iVar1 != 0)) || (*(int *)(in_ECX + 0x1c) != iVar3)) {
    *(bool *)(in_ECX + 0x18) = iVar1 != 0;
    *(int *)(in_ECX + 0x1c) = iVar3;
    FUN_00464eb0();
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00465190 @ 0x00465190 ====

void FUN_00465190(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    uVar2 = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(in_ECX + 0x18);
    *(undefined4 *)(param_1 + 4) = 0;
    if (cVar1 != '\x01') {
      FUN_00464850();
      return;
    }
    FUN_00464c90(uVar2,1);
  }
  return;
}


// ==== FUN_00465210 @ 0x00465210 ====

void FUN_00465210(undefined4 *param_1)

{
  int in_ECX;
  
  if (((*(int *)((int)param_1 + 0x10) == *(int *)(in_ECX + 4)) &&
      (*(short *)((int)param_1 + 0x14) == *(short *)(in_ECX + 8))) &&
     (*(char *)((int)param_1 + 0x16) != '\x01')) {
    param_1 = operator_new(8);
    if (param_1 == (undefined4 *)0x0) {
      param_1 = (undefined4 *)0x0;
    }
    else {
      *param_1 = &PTR_FUN_009a0f8c;
      param_1[1] = 0;
    }
    param_1[1] = 1;
    FUN_00460680(&param_1);
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined2 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00465280 @ 0x00465280 ====

void FUN_00465280(void)

{
  int in_ECX;
  undefined4 *local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    local_4 = operator_new(4);
    if (local_4 == (undefined4 *)0x0) {
      local_4 = (undefined4 *)0x0;
    }
    else {
      *local_4 = &PTR_FUN_009a0fa0;
    }
    FUN_00460680(&local_4);
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  return;
}


// ==== FUN_004652c0 @ 0x004652c0 ====

void FUN_004652c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int local_30;
  void *pvStack_2c;
  undefined1 auStack_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cce1;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  do {
    while ((**(code **)(*DAT_00b5a71c + 8))(), pvStack_2c == (void *)0x0) {
      if (local_30 == 0) {
        ExceptionList = pvStack_c;
        return;
      }
    }
    iVar1 = FUN_00424500();
    if (iVar1 == 0x10002) {
      *(int *)(in_ECX + 0xc) = local_30;
      *(undefined1 *)(in_ECX + 10) = 0;
      puVar2 = operator_new(8);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009a0f8c;
        puVar2[1] = 0;
      }
      puVar2[1] = 0;
      FUN_00460680();
LAB_00465357:
      _free(pvStack_2c);
      return;
    }
    iVar1 = FUN_00424500();
    if (iVar1 == 0x10004) {
      FUN_00465210();
      _free(pvStack_2c);
      return;
    }
    if (local_30 != *(int *)(in_ECX + 0xc)) {
      _free(pvStack_2c);
      return;
    }
    iVar1 = FUN_00424500();
    if (iVar1 == 0x10003) {
      FUN_00465280();
      goto LAB_00465357;
    }
    iVar1 = FUN_00424500();
    if (iVar1 == 0x10005) {
      FUN_00464580();
      _free(pvStack_2c);
      return;
    }
    if (pvStack_2c != (void *)0x0) {
      FUN_00424500();
      FUN_00401830(s_packet_receive__X_009a0efc);
      uVar3 = FUN_00404230(auStack_28);
      uStack_4 = 0;
      FUN_00796d50(uVar3);
      uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (*(char *)(in_ECX + 0x18) == '\x01') {
      FUN_00464c90();
    }
    else {
      (**(code **)(*DAT_00b5a990 + 0x10))();
      iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
      uStack_4 = 1;
      if (iVar1 != 0) {
        FUN_00465540();
      }
      uStack_4 = 0xffffffff;
      FUN_00460680();
    }
  } while( true );
}


// ==== FUN_004654c0 @ 0x004654c0 ====

undefined4 FUN_004654c0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70005) {
    if (uVar1 == 0x70004) {
      uVar2 = FUN_00465070(param_1);
      return uVar2;
    }
    if (uVar1 == 0x40001) {
      FUN_00464d40();
    }
    else if (uVar1 == 0x50012) {
      FUN_00465190(param_1);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x80000000) {
      FUN_00464750(param_1);
      return 1;
    }
    if (uVar1 == 0x80000002) {
      FUN_00464520(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00465540 @ 0x00465540 ====

void FUN_00465540(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cbe8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a0f78;
  *(undefined1 *)(in_ECX + 1) = 0;
  uVar1 = FUN_00424500();
  in_ECX[3] = param_1;
  in_ECX[2] = uVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004655a0 @ 0x004655a0 ====

undefined4 FUN_004655a0(void)

{
  return 0x50011;
}


// ==== FUN_004655b0 @ 0x004655b0 ====

undefined4 FUN_004655b0(void)

{
  return 0x80000001;
}


// ==== FUN_004655c0 @ 0x004655c0 ====

undefined4 FUN_004655c0(void)

{
  return 0x80000003;
}


// ==== FUN_004655d0 @ 0x004655d0 ====

void FUN_004655d0(byte param_1)

{
  FUN_00465600();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00465600 @ 0x00465600 ====

void FUN_00465600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a0f78;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00465630 @ 0x00465630 ====

void FUN_00465630(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00465630(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00465670 @ 0x00465670 ====

/* WARNING: Removing unreachable block (ram,0x00465783) */
/* WARNING: Removing unreachable block (ram,0x00465793) */
/* WARNING: Removing unreachable block (ram,0x0046579c) */
/* WARNING: Removing unreachable block (ram,0x0046579f) */
/* WARNING: Removing unreachable block (ram,0x0046578f) */
/* WARNING: Removing unreachable block (ram,0x004657ad) */
/* WARNING: Removing unreachable block (ram,0x004657ba) */
/* WARNING: Removing unreachable block (ram,0x004657c5) */
/* WARNING: Removing unreachable block (ram,0x004657c1) */
/* WARNING: Removing unreachable block (ram,0x004657b5) */
/* WARNING: Removing unreachable block (ram,0x004657c8) */

void FUN_00465670(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097ccf8;
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
            goto LAB_00465895;
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
LAB_00465895:
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


// ==== FUN_00465920 @ 0x00465920 ====

void FUN_00465920(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097ccf8;
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
LAB_00465a19:
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
      if ((char)piVar6[5] == '\0') goto LAB_00465a19;
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


// ==== FUN_00465b00 @ 0x00465b00 ====

void FUN_00465b00(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00465630(piVar6[1]);
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
    FUN_00465670(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00465bc0 @ 0x00465bc0 ====

void FUN_00465bc0(void)

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
  puStack_8 = &LAB_0097ccf8;
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


// ==== FUN_00465c30 @ 0x00465c30 ====

void FUN_00465c30(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00465920(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00465920(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00465cf0 @ 0x00465cf0 ====

void FUN_00465cf0(uint param_1)

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
    uVar2 = FUN_00465bc0();
  }
  uVar4 = uVar2 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  if ((param_1 < uVar4) && (uVar2 <= 0xfffffff - uVar4)) {
    param_1 = uVar4;
  }
  uVar4 = *(uint *)(in_ECX + 0xc) >> 1;
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
    if (param_1 == 0) goto LAB_00465e1b;
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
    if (uVar4 == 0) goto LAB_00465e1b;
    puVar5 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
LAB_00465e1b:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00465e40 @ 0x00465e40 ====

void FUN_00465e40(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10) & 1U) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 2U >> 1)) {
    FUN_00465cf0(1);
  }
  uVar3 = *(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10);
  uVar4 = uVar3 >> 1;
  if (*(uint *)(in_ECX + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(in_ECX + 8);
  }
  if (*(int *)(*(int *)(in_ECX + 4) + uVar4 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)(in_ECX + 4) + uVar4 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + uVar4 * 4) + (uVar3 & 1) * 8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  return;
}


// ==== FUN_00465ec0 @ 0x00465ec0 ====

void FUN_00465ec0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00465b00(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00465ef0 @ 0x00465ef0 ====

void FUN_00465ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00464920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00465f10 @ 0x00465f10 ====

undefined1 FUN_00465f10(void)

{
  return 0;
}


// ==== FUN_00465f20 @ 0x00465f20 ====

void FUN_00465f20(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 0x18);
  while (iVar3 != 0) {
    uVar2 = *(uint *)(in_ECX + 0x14) >> 2;
    iVar3 = uVar2 * -4;
    if (*(uint *)(in_ECX + 0x10) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(in_ECX + 0x10);
    }
    puVar1 = *(undefined4 **)
              (*(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4) + (*(uint *)(in_ECX + 0x14) + iVar3) * 4
              );
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    if (*(int *)(in_ECX + 0x18) != 0) {
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
      if ((uint)(*(int *)(in_ECX + 0x10) * 4) <= *(uint *)(in_ECX + 0x14)) {
        *(undefined4 *)(in_ECX + 0x14) = 0;
      }
      iVar3 = *(int *)(in_ECX + 0x18) + -1;
      *(int *)(in_ECX + 0x18) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(in_ECX + 0x14) = 0;
      }
    }
    iVar3 = *(int *)(in_ECX + 0x18);
  }
  return;
}


// ==== FUN_00465f90 @ 0x00465f90 ====

undefined4 FUN_00465f90(void)

{
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    return 0;
  }
  uVar2 = *(uint *)(in_ECX + 0x14) >> 2;
  iVar3 = uVar2 * -4;
  if (*(uint *)(in_ECX + 0x10) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(in_ECX + 0x10);
  }
  uVar1 = *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4) + (*(uint *)(in_ECX + 0x14) + iVar3) * 4);
  if (*(int *)(in_ECX + 0x18) != 0) {
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    if ((uint)(*(int *)(in_ECX + 0x10) * 4) <= *(uint *)(in_ECX + 0x14)) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
    iVar3 = *(int *)(in_ECX + 0x18) + -1;
    *(int *)(in_ECX + 0x18) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00465ff0 @ 0x00465ff0 ====

void FUN_00465ff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1050;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00466010 @ 0x00466010 ====

void FUN_00466010(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cd23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1050;
  local_4 = 1;
  FUN_00465f20();
  FUN_0046cfc0();
  *in_ECX = &PTR_FUN_009a0f64;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00466060 @ 0x00466060 ====

void FUN_00466060(void)

{
  undefined4 uVar1;
  int in_ECX;
  void *unaff_ESI;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  uint uStack_18;
  void *pvStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cd35;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a6ac + 0x14))();
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  uStack_10 = 0xf;
  pvStack_14 = (void *)0x0;
  uStack_24 = 0;
  FUN_00401740(s_>_Timer_Controller_Initialized_009a0fd0,0x1e);
  uStack_4 = 0;
  (**(code **)(*DAT_00b5a6c0 + 4))(0,auStack_28);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00466110 @ 0x00466110 ====

void FUN_00466110(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  char *pcStack_bc;
  undefined1 *puStack_b8;
  undefined1 auStack_b4 [4];
  uint uStack_b0;
  void *pvStack_74;
  uint uStack_6c;
  uint uStack_60;
  void *pvStack_50;
  void *pvStack_48;
  undefined1 auStack_44 [4];
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cd6f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a6ac + 0x14))();
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar1 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 4) = iVar3;
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar5 != (undefined4 *)0x0) {
    uVar2 = *(undefined4 *)(in_ECX + 4);
    *puVar5 = &PTR_FUN_009a103c;
    puVar5[1] = iVar3 - iVar1;
    puVar5[2] = uVar2;
    puVar5[3] = uVar4;
  }
  FUN_00460680();
  FUN_00401740();
  uStack_4 = 0;
  (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(*DAT_00b5a6ac + 0x20))();
  puStack_b8 = (undefined1 *)0x7;
  pcStack_bc = s__u____u_009a0ff0;
  uStack_b0 = uStack_b0 & 0xffffff00;
  FUN_00401740();
  puStack_b8 = auStack_44;
  pcStack_bc = (char *)0x4661fb;
  FUN_00404230();
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_c = (void *)0xffffffff;
  if (0xf < uStack_6c) {
    _free(auStack_b4);
    return;
  }
  FUN_00401740();
  pvStack_c = (void *)0x2;
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  puStack_b8 = (undefined1 *)((uint)puStack_b8 & 0xffffff00);
  FUN_00401740();
  FUN_00404230();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < pvStack_3c) {
    _free(pvStack_50);
    return;
  }
  pvStack_3c = (void *)0xf;
  uStack_40 = 0;
  uStack_14 = 0xffffffff;
  if ((void *)0xf < pvStack_74) {
    _free(&pcStack_bc);
    return;
  }
  FUN_00401740();
  uStack_14 = 4;
  (**(code **)(*DAT_00b5a6ac + 0x1c))();
  (**(code **)(*DAT_00b5a6ac + 0x1c))();
  uStack_b0 = 0;
  FUN_00401740(s__u____u_009a1020,7);
  FUN_00404230(&uStack_38);
  uStack_14 = CONCAT31(uStack_14._1_3_,5);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_28) {
    uStack_b0 = 0x4663ad;
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (uStack_60 < 0x10) {
    ExceptionList = pvStack_24;
    return;
  }
  uStack_b0 = 0x4663cf;
  _free(pvStack_74);
  return;
}


// ==== FUN_004663f0 @ 0x004663f0 ====

undefined4 FUN_004663f0(void)

{
  return 0x40001;
}


// ==== FUN_00466400 @ 0x00466400 ====

void FUN_00466400(byte param_1)

{
  void *in_ECX;
  
  FUN_00466010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00466420 @ 0x00466420 ====

void FUN_00466420(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00466425. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_00466430 @ 0x00466430 ====

void FUN_00466430(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00466435. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  return;
}


// ==== FUN_00466440 @ 0x00466440 ====

bool FUN_00466440(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(param_1);
  return cVar1 != '\0';
}


// ==== FUN_00466460 @ 0x00466460 ====

void FUN_00466460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1064;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_00466480 @ 0x00466480 ====

void FUN_00466480(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cd88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1064;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_009a0f64;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004664e0 @ 0x004664e0 ====

void FUN_004664e0(void)

{
  void *pvVar1;
  int *piVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097cd9d;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 4) == 0) {
    if (*(int *)(in_ECX + 8) == 0) {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x48);
      local_4 = 0;
      if (pvVar1 == (void *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)FUN_004685f0();
      }
      *(int **)(in_ECX + 8) = piVar2;
      local_4 = 0xffffffff;
      (**(code **)(*piVar2 + 4))();
    }
    *(undefined4 *)(in_ECX + 4) = 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00466560 @ 0x00466560 ====

void FUN_00466560(byte param_1)

{
  void *in_ECX;
  
  FUN_00466480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00466590 @ 0x00466590 ====

bool FUN_00466590(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_00468d60(param_1);
  return cVar1 != '\0';
}


// ==== FUN_004665b0 @ 0x004665b0 ====

void FUN_004665b0(void)

{
  SHORT SVar1;
  SHORT SVar2;
  int in_ECX;
  
  SVar1 = GetKeyState(0x10);
  SVar2 = GetKeyState(0x11);
  if ((char)((ushort)SVar1 >> 8) == '\0') {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) & 0xfffffffd;
  }
  else {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) | 2;
  }
  if ((char)((ushort)SVar2 >> 8) == '\0') {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) & 0xfffffffe;
    return;
  }
  *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) | 1;
  return;
}


// ==== FUN_00466600 @ 0x00466600 ====

void FUN_00466600(undefined2 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009a1114;
    puVar1[2] = 0;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
  }
  puVar3 = (undefined4 *)(in_ECX + 8);
  puVar4 = puVar1 + 2;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)(puVar1 + 1) = param_1;
  FUN_00797a20(puVar1);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x1c);
  return;
}


// ==== FUN_004666a0 @ 0x004666a0 ====

bool FUN_004666a0(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = (int *)FUN_004e3300(local_4,&param_1);
  return *piVar1 != *(int *)(in_ECX + 0x40);
}


// ==== FUN_004666d0 @ 0x004666d0 ====

undefined4 FUN_004666d0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  
  iVar1 = *(int *)(in_ECX + 0x30);
  if (*(int *)(iVar1 + 0x10) == 0) {
    return 0;
  }
  uVar3 = *(uint *)(iVar1 + 0xc) >> 2;
  iVar4 = uVar3 * -4;
  if (*(uint *)(iVar1 + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(iVar1 + 8);
  }
  uVar2 = *(undefined4 *)
           (*(int *)(*(int *)(iVar1 + 4) + uVar3 * 4) + (*(uint *)(iVar1 + 0xc) + iVar4) * 4);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
    if ((uint)(*(int *)(iVar1 + 8) * 4) <= *(uint *)(iVar1 + 0xc)) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    iVar4 = *(int *)(iVar1 + 0x10) + -1;
    *(int *)(iVar1 + 0x10) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
  }
  return uVar2;
}


// ==== FUN_00466740 @ 0x00466740 ====

void FUN_00466740(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 *in_ECX;
  int iVar5;
  undefined1 local_14 [8];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cde3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a1180;
  in_ECX[1] = &PTR_FUN_009a1178;
  DAT_00b5a994 = 0;
  local_4 = 1;
  (**(code **)(*DAT_00b5a688 + 0x20))(in_ECX + 1);
  if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe])(1);
  }
  in_ECX[0xe] = 0;
  iVar1 = *(int *)(in_ECX[0xc] + 0x10);
  while (iVar1 != 0) {
    iVar1 = in_ECX[0xc];
    uVar4 = *(uint *)(iVar1 + 0xc) >> 2;
    iVar5 = uVar4 * -4;
    if (*(uint *)(iVar1 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar1 + 8);
    }
    puVar2 = *(undefined4 **)
              (*(int *)(*(int *)(iVar1 + 4) + uVar4 * 4) + (*(uint *)(iVar1 + 0xc) + iVar5) * 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    iVar1 = in_ECX[0xc];
    if (*(int *)(iVar1 + 0x10) != 0) {
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
      if ((uint)(*(int *)(iVar1 + 8) * 4) <= *(uint *)(iVar1 + 0xc)) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      iVar5 = *(int *)(iVar1 + 0x10) + -1;
      *(int *)(iVar1 + 0x10) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
    }
    iVar1 = *(int *)(in_ECX[0xc] + 0x10);
  }
  iVar1 = *(int *)(in_ECX[0xd] + 0x10);
  while (iVar1 != 0) {
    iVar1 = in_ECX[0xd];
    uVar4 = *(uint *)(iVar1 + 0xc) >> 2;
    iVar5 = uVar4 * -4;
    if (*(uint *)(iVar1 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar1 + 8);
    }
    puVar2 = *(undefined4 **)
              (*(int *)(*(int *)(iVar1 + 4) + uVar4 * 4) + (*(uint *)(iVar1 + 0xc) + iVar5) * 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    iVar1 = in_ECX[0xd];
    if (*(int *)(iVar1 + 0x10) != 0) {
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
      if ((uint)(*(int *)(iVar1 + 8) * 4) <= *(uint *)(iVar1 + 0xc)) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      iVar5 = *(int *)(iVar1 + 0x10) + -1;
      *(int *)(iVar1 + 0x10) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
    }
    iVar1 = *(int *)(in_ECX[0xd] + 0x10);
  }
  pvVar3 = (void *)in_ECX[0xc];
  if (pvVar3 != (void *)0x0) {
    FUN_0046cfc0();
    _free(pvVar3);
    return;
  }
  pvVar3 = (void *)in_ECX[0xd];
  in_ECX[0xc] = 0;
  if (pvVar3 == (void *)0x0) {
    in_ECX[0xd] = 0;
    puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
    FUN_00467860(local_14,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
    _free((void *)in_ECX[0x10]);
    return;
  }
  FUN_0046cfc0();
  _free(pvVar3);
  return;
}


// ==== FUN_004668f0 @ 0x004668f0 ====

void FUN_004668f0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ce0b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  in_ECX[1] = &PTR_FUN_009a10e0;
  *in_ECX = &PTR_FUN_009a1180;
  in_ECX[1] = &PTR_FUN_009a1178;
  in_ECX[2] = 0;
  in_ECX[3] = 0xffffffff;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  local_4 = 0;
  in_ECX[0xb] = 0;
  iVar1 = FUN_00751a80();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4._0_1_ = 1;
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  }
  in_ECX[0xc] = pvVar2;
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  }
  in_ECX[0xd] = pvVar2;
  pvVar2 = operator_new(0x20);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00468a40();
  }
  in_ECX[0xe] = uVar3;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a688 + 0x1c))(in_ECX + 1);
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a994 = (undefined4 *)0x0;
    ExceptionList = pvVar2;
    return;
  }
  DAT_00b5a994 = in_ECX;
  ExceptionList = pvVar2;
  return;
}


// ==== FUN_00466a50 @ 0x00466a50 ====

void FUN_00466a50(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009a1100;
    puVar1[1] = param_1;
    puVar1[2] = 0;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
  }
  puVar3 = (undefined4 *)(in_ECX + 8);
  puVar4 = puVar1 + 2;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1 = puVar1;
  FUN_00460680(&param_1);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x1c);
  return;
}


// ==== FUN_00466ae0 @ 0x00466ae0 ====

void FUN_00466ae0(void)

{
  undefined4 uVar1;
  SHORT SVar2;
  SHORT SVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined1 auStack_78 [4];
  undefined1 local_74;
  undefined4 local_64;
  char cStack_47;
  uint uStack_34;
  undefined1 local_28 [12];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ce25;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  SVar2 = GetKeyState(0x10);
  SVar3 = GetKeyState(0x11);
  cStack_47 = (char)((ushort)SVar2 >> 8);
  if (cStack_47 == '\0') {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) & 0xfffffffd;
  }
  else {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) | 2;
  }
  if ((char)((ushort)SVar3 >> 8) == '\0') {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) & 0xfffffffe;
  }
  else {
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x2c) | 1;
  }
  FUN_00466a50();
  FUN_00401740();
  local_64 = 0;
  local_4 = 0;
  local_74 = 0;
  FUN_00401740(s__d___d_009a10b0,6);
  FUN_00404230(local_28);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_18) {
    local_64 = 0x466bb5;
    _free((void *)0xf);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_c = (void *)0xffffffff;
  if (0xf < uStack_34) {
    local_64 = 0x466bdd;
    _free(auStack_78);
    return;
  }
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = &PTR_FUN_009a10e8;
    puVar5 = puVar4;
  }
  uVar1 = *(undefined4 *)(in_ECX + 0x18);
  puVar5[2] = *(undefined4 *)(in_ECX + 0x1c);
  puVar5[1] = uVar1;
  local_64 = 0x466c14;
  FUN_00460680();
  uVar1 = *(undefined4 *)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00466c40 @ 0x00466c40 ====

undefined4 FUN_00466c40(uint param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  uVar2 = (uint)param_2;
  uVar1 = param_1;
  if (0x200 < param_1) {
    switch(param_1) {
    case 0x201:
      *(uint *)(in_ECX + 0x14) = param_3 & 0xffff;
      *(uint *)(in_ECX + 0x18) = param_3 >> 0x10;
      FUN_004665b0();
      FUN_00466a50(1);
      return 1;
    case 0x202:
      *(uint *)(in_ECX + 0x14) = param_3 & 0xffff;
      *(uint *)(in_ECX + 0x18) = param_3 >> 0x10;
      FUN_004665b0();
      FUN_00466a50(2);
      return 1;
    case 0x204:
      *(uint *)(in_ECX + 0x14) = param_3 & 0xffff;
      *(uint *)(in_ECX + 0x18) = param_3 >> 0x10;
      FUN_004665b0();
      FUN_00466a50(3);
      return 1;
    case 0x205:
      *(uint *)(in_ECX + 0x14) = param_3 & 0xffff;
      *(uint *)(in_ECX + 0x18) = param_3 >> 0x10;
      FUN_004665b0();
      FUN_00466a50(4);
      return 1;
    case 0x207:
      *(uint *)(in_ECX + 0x14) = param_3 & 0xffff;
      *(uint *)(in_ECX + 0x18) = param_3 >> 0x10;
      FUN_004665b0();
      FUN_00466a50(5);
      return 1;
    case 0x208:
      *(uint *)(in_ECX + 0x14) = param_3 & 0xffff;
      *(uint *)(in_ECX + 0x18) = param_3 >> 0x10;
      FUN_004665b0();
      FUN_00466a50(6);
      return 1;
    case 0x20a:
      FUN_004665b0();
      FUN_00466600(uVar2 >> 0x10);
    }
    goto switchD_00466c77_caseD_21;
  }
  if (param_1 == 0x200) {
    *(int *)(in_ECX + 0x14) = (int)(short)param_3;
    *(int *)(in_ECX + 0x18) = (int)(short)(param_3 >> 0x10);
    return 1;
  }
  switch(param_1) {
  case 0x20:
    SetCursor((HCURSOR)0x0);
    if ((DAT_00b5a9d0 != (int *)0x0) && (iVar4 = (**(code **)(*DAT_00b5a9d0 + 0x20))(), iVar4 != 0))
    {
      piVar5 = (int *)(**(code **)(*DAT_00b5a9d0 + 0x20))();
      (**(code **)(*piVar5 + 0x30))(piVar5,1);
    }
    return 1;
  case 0x100:
  case 0x104:
    if ((param_2 == (undefined4 *)0xd) ||
       (piVar5 = (int *)FUN_004e3300(&param_1,&param_2), *piVar5 == *(int *)(in_ECX + 0x3c))) {
      FUN_004677a0(local_8,&param_2);
      param_2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (param_2 == (undefined4 *)0x0) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        *param_2 = &PTR_FUN_009a1164;
        param_2[1] = uVar2;
      }
      FUN_00460680(&param_2);
      return 1;
    }
    break;
  case 0x101:
  case 0x105:
    piVar5 = (int *)FUN_004e3300(local_c,&param_2);
    if (*piVar5 != *(int *)(in_ECX + 0x3c)) {
      FUN_00467950(&param_2);
      puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        *puVar6 = &PTR_FUN_009a113c;
        puVar6[1] = param_2;
      }
      param_2 = puVar6;
      FUN_00460680(&param_2);
      return 1;
    }
    break;
  case 0x102:
    param_2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (uVar2 == 0x1b) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = &PTR_FUN_009a1128;
        goto LAB_00466cff;
      }
    }
    else if (param_2 != (undefined4 *)0x0) {
      *param_2 = &PTR_FUN_009a1150;
      param_2[1] = uVar2;
      goto LAB_00466cff;
    }
    param_2 = (undefined4 *)0x0;
LAB_00466cff:
    FUN_00460680(&param_2);
    return 1;
  case 0x112:
    if (param_2 == (undefined4 *)0xf100) {
      return 1;
    }
  default:
switchD_00466c77_caseD_21:
    cVar3 = FUN_00469090(uVar1,uVar2,param_3);
    if (cVar3 != '\x01') {
      return 0;
    }
    param_2 = (undefined4 *)FUN_004689e0();
    while (param_2 != (undefined4 *)0x0) {
      FUN_00460680(&param_2);
      param_2 = (undefined4 *)FUN_004689e0();
    }
  }
  return 1;
}


// ==== FUN_004670e0 @ 0x004670e0 ====

void FUN_004670e0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x11);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x11);
  }
  return;
}


// ==== FUN_00467100 @ 0x00467100 ====

undefined4 FUN_00467100(void)

{
  return 0x10021;
}


// ==== FUN_00467110 @ 0x00467110 ====

undefined4 FUN_00467110(void)

{
  return 0x10050001;
}


// ==== FUN_00467120 @ 0x00467120 ====

undefined4 FUN_00467120(void)

{
  return 0x10050002;
}


// ==== FUN_00467130 @ 0x00467130 ====

undefined4 FUN_00467130(void)

{
  return 0x10050003;
}


// ==== FUN_00467140 @ 0x00467140 ====

void FUN_00467140(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x11) == '\0') {
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


// ==== FUN_004671a0 @ 0x004671a0 ====

undefined4 FUN_004671a0(void)

{
  return 0x20002;
}


// ==== FUN_004671b0 @ 0x004671b0 ====

undefined4 FUN_004671b0(void)

{
  return 0x20003;
}


// ==== FUN_004671c0 @ 0x004671c0 ====

void FUN_004671c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    *(undefined1 *)(puVar1 + 4) = param_5;
    *(undefined1 *)((int)puVar1 + 0x11) = 0;
  }
  return;
}


// ==== FUN_00467200 @ 0x00467200 ====

undefined4 FUN_00467200(void)

{
  return 0x20001;
}


// ==== FUN_00467210 @ 0x00467210 ====

void FUN_00467210(void *param_1)

{
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    FUN_00467210(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00467250 @ 0x00467250 ====

void FUN_00467250(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    *param_3 = *param_3 + 1;
    if (*(char *)((int)param_1 + 0x11) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x11) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x11);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x11);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x11);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return;
}


// ==== FUN_004672b0 @ 0x004672b0 ====

void FUN_004672b0(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x11) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if (*param_2 < (uint)puVar1[3]) {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      else {
        puVar2 = (undefined4 *)puVar1[2];
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x11) == '\0');
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar1[1] + 0x11) == '\0') {
    puVar2 = (undefined4 *)puVar1[1];
    do {
      if ((uint)puVar2[3] < *param_2) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar1 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x11) == '\0');
  }
  *param_1 = (int)puVar1;
  param_1[1] = (int)puVar4;
  return;
}


// ==== FUN_00467310 @ 0x00467310 ====

void FUN_00467310(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097cdb8;
  local_c = ExceptionList;
  if (0x3ffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004671c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x10);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x10) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[4] == '\0') {
LAB_00467409:
        *(undefined1 *)(*piVar5 + 0x10) = 1;
        *(undefined1 *)(piVar6 + 4) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x10) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004e2f90(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x10) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x10) = 0;
        FUN_00467140(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[4] == '\0') goto LAB_00467409;
      if (piVar7 == (int *)*piVar2) {
        FUN_00467140(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x10) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x10) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x11) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x10);
  } while( true );
}


// ==== FUN_004674f0 @ 0x004674f0 ====

/* WARNING: Removing unreachable block (ram,0x00467603) */
/* WARNING: Removing unreachable block (ram,0x00467613) */
/* WARNING: Removing unreachable block (ram,0x0046761c) */
/* WARNING: Removing unreachable block (ram,0x0046761f) */
/* WARNING: Removing unreachable block (ram,0x0046760f) */
/* WARNING: Removing unreachable block (ram,0x0046762d) */
/* WARNING: Removing unreachable block (ram,0x0046763a) */
/* WARNING: Removing unreachable block (ram,0x00467645) */
/* WARNING: Removing unreachable block (ram,0x00467641) */
/* WARNING: Removing unreachable block (ram,0x00467635) */
/* WARNING: Removing unreachable block (ram,0x00467648) */

void FUN_004674f0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097cdb8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x11) != '\0') {
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
  FUN_007519c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
    if (*(char *)(param_2[2] + 0x11) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x11) == '\0') {
      piVar3 = (int *)FUN_004670e0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x11) == '\0') {
      uVar4 = FUN_00751930(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[4] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[4] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[4] == '\0') {
            *(undefined1 *)(piVar5 + 4) = 1;
            *(undefined1 *)(piVar3 + 4) = 0;
            FUN_004e2f90(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x11) == '\0') {
            if ((*(char *)(*piVar5 + 0x10) == '\x01') && (*(char *)(piVar5[2] + 0x10) == '\x01'))
            goto LAB_00467715;
            if (*(char *)(piVar5[2] + 0x10) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x10) = 1;
              *(undefined1 *)(piVar5 + 4) = 0;
              FUN_00467140(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 4) = (char)piVar3[4];
            *(undefined1 *)(piVar3 + 4) = 1;
            *(undefined1 *)(piVar5[2] + 0x10) = 1;
            FUN_004e2f90(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[4] == '\0') {
            *(undefined1 *)(piVar5 + 4) = 1;
            *(undefined1 *)(piVar3 + 4) = 0;
            FUN_00467140(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x11) == '\0') {
            if ((*(char *)(piVar5[2] + 0x10) != '\x01') || (*(char *)(*piVar5 + 0x10) != '\x01')) {
              if (*(char *)(*piVar5 + 0x10) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x10) = 1;
                *(undefined1 *)(piVar5 + 4) = 0;
                FUN_004e2f90(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 4) = (char)piVar3[4];
              *(undefined1 *)(piVar3 + 4) = 1;
              *(undefined1 *)(*piVar5 + 0x10) = 1;
              FUN_00467140(piVar3);
              break;
            }
LAB_00467715:
            *(undefined1 *)(piVar5 + 4) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 4) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004677a0 @ 0x004677a0 ====

void FUN_004677a0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x11) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x11) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00467310(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00751950();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00467310(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00467860 @ 0x00467860 ====

void FUN_00467860(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00467210(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x11) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x11) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x11);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x11);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x11);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004674f0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00467920 @ 0x00467920 ====

void FUN_00467920(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00467860(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00467950 @ 0x00467950 ====

undefined4 FUN_00467950(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004672b0(&local_8,param_1);
  param_1 = 0;
  FUN_00467250(local_8,local_4,&param_1,0);
  FUN_00467860(&local_8,local_8,local_4);
  return param_1;
}


// ==== FUN_004679b0 @ 0x004679b0 ====

void FUN_004679b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00466740();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004679d0 @ 0x004679d0 ====

void FUN_004679d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a11b4;
  if (0xf < (uint)in_ECX[0x1d]) {
    _free((void *)in_ECX[0x18]);
    return;
  }
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  if (0xf < (uint)in_ECX[0x16]) {
    _free((void *)in_ECX[0x11]);
    return;
  }
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  if (0xf < (uint)in_ECX[0xf]) {
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00467a60 @ 0x00467a60 ====

void FUN_00467a60(void)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *in_ECX;
  undefined1 local_60 [4];
  undefined1 local_5c;
  uint uStack_50;
  undefined4 local_4c;
  void *local_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  undefined1 auStack_28 [12];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ce74;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a11b4;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  local_4 = 3;
  in_ECX[1] = 1;
  FUN_00401740(&DAT_009a1196,0);
  FUN_00401740(&DAT_009a1197,0);
  puVar2 = PTR_s_RealDataPath_00ae08a4;
  in_ECX[0x1e] = DAT_0099de78;
  local_48 = (void *)0xf;
  local_4c = 0;
  local_5c = 0;
  pcVar3 = puVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar3 - (int)(puVar2 + 1));
  local_4 = CONCAT31(local_4._1_3_,4);
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 8))(auStack_28,local_60);
  pvStack_c._0_1_ = 5;
  uVar5 = FUN_00402220(&local_4c,uVar5,s_Sound__009a1198);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,6);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < uStack_34) {
    _free(local_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  if (uStack_50 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00467be0 @ 0x00467be0 ====

void FUN_00467be0(byte param_1)

{
  void *in_ECX;
  
  FUN_004679d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00467c00 @ 0x00467c00 ====

void FUN_00467c00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a12ec;
  return;
}


// ==== FUN_00467c10 @ 0x00467c10 ====

void FUN_00467c10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a12ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00467c30 @ 0x00467c30 ====

void FUN_00467c30(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0x24) + 0x18))(*(undefined4 *)(in_ECX + 0x20));
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_00467c50 @ 0x00467c50 ====

void FUN_00467c50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 1) {
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x2c))(2,1,*(undefined4 *)(in_ECX + 0x20));
  }
  else if (*(int *)(in_ECX + 0x10) == 2) {
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x28))(2,*(undefined4 *)(in_ECX + 0x20));
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_00467ca0 @ 0x00467ca0 ====

void FUN_00467ca0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 1) {
    if (*(int *)(in_ECX + 0xc) == 0) {
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    }
    if (2 < *(uint *)(in_ECX + 0x14)) {
      (**(code **)(*(int *)(in_ECX + 0x24) + 0x28))(1,*(undefined4 *)(in_ECX + 0x20));
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
  }
  else if (*(int *)(in_ECX + 0x10) == 2) {
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x2c))(1,2,*(undefined4 *)(in_ECX + 0x20));
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  return;
}


// ==== FUN_00467d00 @ 0x00467d00 ====

void FUN_00467d00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 1) {
    if (*(int *)(in_ECX + 0xc) == 0) {
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    }
  }
  else if (*(int *)(in_ECX + 0x10) == 2) {
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x28))(2,*(undefined4 *)(in_ECX + 0x20));
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  return;
}


// ==== FUN_00467db0 @ 0x00467db0 ====

void FUN_00467db0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ce88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a1304;
  local_4 = 0;
  if ((void *)in_ECX[0xf] == (void *)0x0) {
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    FUN_0046a1f0();
    *in_ECX = &PTR_FUN_009a12ec;
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[0xf]);
  return;
}


// ==== FUN_00467e20 @ 0x00467e20 ====

void FUN_00467e20(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar1 + 0x10))(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 0x1c);
  return;
}


// ==== FUN_00467e50 @ 0x00467e50 ====

void FUN_00467e50(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x40);
  puVar2 = *(undefined4 **)(in_ECX + 0x3c);
  if (puVar2 != puVar1) {
    do {
      (**(code **)(*(int *)(in_ECX + 0x24) + 0x18))(*puVar2);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar1);
  }
  if (*(void **)(in_ECX + 0x3c) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x3c));
  return;
}


// ==== FUN_00467eb0 @ 0x00467eb0 ====

void FUN_00467eb0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_2c [4];
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = (undefined1 *)0x1;
  uStack_c = 0xffffffff;
  uStack_10 = 0x467ec0;
  (**(code **)(*(int *)(in_ECX + 0x24) + 0x14))();
  uStack_10 = 0xffffffff;
  uStack_14 = 0x467ec9;
  piVar2 = (int *)(**(code **)(*(int *)(in_ECX + 0x24) + 0x38))();
  if (piVar2 != (int *)0x0) {
    puVar1 = (undefined4 *)((int)puStack_8 + 4);
    puStack_8 = auStack_2c;
    uStack_14 = 0xf;
    uStack_18 = 0;
    uStack_28 = 0;
    FUN_00401660(*puVar1,0,0xffffffff);
    (**(code **)(*piVar2 + 0x14))();
  }
  return;
}


// ==== FUN_00467f10 @ 0x00467f10 ====

void FUN_00467f10(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  thunk_FUN_00796e60();
  (**(code **)(*(int *)(in_ECX + 0x24) + 0x14))();
  piVar1 = (int *)(**(code **)(*(int *)(in_ECX + 0x24) + 0x38))();
  if (piVar1 != (int *)0x0) {
    FUN_00401660(*(int *)(param_1 + 4) + 0x1c,0,0xffffffff);
    (**(code **)(*piVar1 + 0x14))();
  }
  return;
}


// ==== FUN_00467f80 @ 0x00467f80 ====

void FUN_00467f80(void)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_44 [28];
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cea2;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 4) != 0)) {
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*(int *)(in_ECX + 0x24) + 8))();
    if (iVar1 == 0) {
      if (*(int *)(in_ECX + 0x10) == 1) {
        iVar1 = (**(code **)(*(int *)(in_ECX + 0x24) + 0x30))(1);
        if (iVar1 == 0) {
          FUN_00401830(s_pList____NULL_009a11e4);
          uStack_4 = 0;
          FUN_00406880(auStack_44);
          uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 8);
      }
      if ((*(int *)(in_ECX + 0x10) == 2) || (*(int *)(in_ECX + 0x1c) == 0)) {
        iVar1 = (**(code **)(*(int *)(in_ECX + 0x24) + 0x30))(2);
        if (iVar1 == 0) {
          FUN_00401830(s_pList____NULL_009a11f4);
          uStack_4 = 1;
          FUN_00406880(auStack_28);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar1 = *(int *)(iVar1 + 8);
        *(int *)(in_ECX + 0x1c) = iVar1;
        if (iVar1 == 0) {
          *(undefined4 *)(in_ECX + 8) = 0;
          *(undefined4 *)(in_ECX + 0xc) = 0;
          *(undefined4 *)(in_ECX + 0x10) = 0;
          *(undefined4 *)(in_ECX + 0x14) = 0;
          *(undefined4 *)(in_ECX + 0x18) = 0;
          *(undefined4 *)(in_ECX + 0x1c) = 0;
          *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
          *(undefined4 *)(in_ECX + 0x10) = 1;
          ExceptionList = local_c;
          return;
        }
      }
      *(undefined4 *)(in_ECX + 8) = 1;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004680b0 @ 0x004680b0 ====

undefined4 FUN_004680b0(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x1c) <= *(uint *)(in_ECX + 0x18)) {
    if (*(int *)(in_ECX + 0x10) == 1) {
      *(undefined4 *)(in_ECX + 8) = 0;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 0x10) = 0;
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(undefined4 *)(in_ECX + 0x18) = 0;
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x10) = 2;
      FUN_00467f80();
      if (*(int *)(in_ECX + 8) == 0) {
        return 1;
      }
    }
    else if (*(int *)(in_ECX + 0x10) == 2) {
      *(undefined4 *)(in_ECX + 8) = 0;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 0x10) = 0;
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(undefined4 *)(in_ECX + 0x18) = 0;
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x10) = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00468130 @ 0x00468130 ====

void FUN_00468130(void)

{
  void *unaff_ESI;
  uint unaff_EDI;
  void *_Memory;
  uint *puStack_94;
  char *pcStack_90;
  undefined4 uStack_8c;
  uint local_7c;
  uint local_78;
  undefined4 uStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  void *local_64;
  undefined1 auStack_5c [4];
  void *pvStack_58;
  void *pvStack_54;
  uint uStack_50;
  void *pvStack_4c;
  uint uStack_48;
  uint local_44;
  uint local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ceec;
  pvStack_c = ExceptionList;
  uStack_8c = (uint *)0x1f;
  pcStack_90 = s_set_property__key_word___value__009a1204;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  puStack_94 = (uint *)0x46816e;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  uStack_8c = (uint *)0xc;
  pcStack_90 = s_set_property_009a1224;
  local_4 = 0;
  local_64 = (void *)0xf;
  local_68 = 0;
  local_78 = local_78 & 0xffffff00;
  puStack_94 = (uint *)0x468191;
  FUN_00401740();
  uStack_8c = &local_44;
  pcStack_90 = (void *)0x2;
  puStack_94 = &local_7c;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_70) {
    _free(unaff_ESI);
    return;
  }
  uStack_70 = 0xf;
  uStack_74 = 0;
  uStack_10 = 0xffffffff;
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401740(s_load_script__file_name__009a1234,0x17);
  uStack_10 = 2;
  uStack_70 = 0xf;
  uStack_74 = 0;
  FUN_00401740(s_load_script_009a124c,0xb);
  _Memory = (void *)0x1;
  uStack_10 = CONCAT31(uStack_10._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_5c + -0x2c,1,&uStack_50);
  if (0xf < local_7c) {
    _free(pcStack_90);
    return;
  }
  local_7c = 0xf;
  pcStack_90 = (char *)((uint)pcStack_90 & 0xffffff00);
  uStack_1c = 0xffffffff;
  if (0xf < local_44) {
    _free(pvStack_58);
    return;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  FUN_00401740(s_create_script__ID___file_name__009a1258,0x1e);
  uStack_1c = 4;
  local_7c = 0xf;
  pcStack_90 = (char *)((uint)pcStack_90 & 0xffffff00);
  FUN_00401740(s_create_script_009a1278,0xd);
  uStack_1c = CONCAT31(uStack_1c._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_94,2,auStack_5c);
  if (0xf < unaff_EDI) {
    _free(_Memory);
    return;
  }
  uStack_8c = (void *)0x0;
  uStack_28 = 0xffffffff;
  if (0xf < uStack_50) {
    _free(local_64);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  uStack_48 = uStack_48 & 0xffffff00;
  FUN_00401740(s_destroy_script__ID__009a1288,0x13);
  uStack_28 = 6;
  uStack_6c = 0xf;
  uStack_70 = 0;
  FUN_00401740(s_destroy_script_009a129c,0xe);
  uStack_28 = CONCAT31(uStack_28._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_5c + -0x28,1,&pvStack_4c);
  if (0xf < local_78) {
    _free(uStack_8c);
    return;
  }
  local_78 = 0xf;
  local_7c = 0;
  uStack_8c = (uint *)((uint)uStack_8c & 0xffffff00);
  if (local_40 < 0x10) {
    ExceptionList = pvStack_3c;
    return;
  }
  _free(pvStack_54);
  return;
}


// ==== FUN_004683e0 @ 0x004683e0 ====

void FUN_004683e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    (**(code **)(*(int *)(in_ECX + 0x24) + 4))();
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x10))(1);
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x10))(2);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x10) = 1;
    FUN_00468130();
    *(undefined4 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00468440 @ 0x00468440 ====

undefined4 FUN_00468440(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0;
  FUN_00467f80();
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  iVar2 = *(int *)(in_ECX + 0x10);
  uVar6 = 0;
  if (iVar2 == 1) {
    uVar6 = 3;
  }
  else if (iVar2 == 2) {
    uVar6 = 1;
  }
  if (*(uint *)(in_ECX + 0x14) < uVar6) {
    piVar1 = (int *)(in_ECX + 0x24);
    while( true ) {
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      piVar4 = (int *)(**(code **)(*piVar1 + 0x34))(*(undefined4 *)(in_ECX + 0x10));
      if (piVar4 == (int *)0x0) break;
      uVar5 = (**(code **)(*piVar4 + 0xc))();
      *(undefined4 *)(in_ECX + 0x20) = uVar5;
      local_10 = (**(code **)(*piVar4 + 8))(&local_c);
      switch(local_8) {
      case 1:
      case 2:
        (**(code **)(*piVar1 + 0x18))(*(undefined4 *)(in_ECX + 0x20));
LAB_00468517:
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
        *(undefined4 *)(in_ECX + 0x14) = 0;
        break;
      case 3:
        FUN_00467c50();
        break;
      case 4:
        FUN_00467ca0();
        return local_10;
      case 5:
        FUN_00467d00();
        break;
      case 6:
        *(int *)(in_ECX + 0xc) = local_c;
        if (local_c == 0) {
          (**(code **)(*piVar1 + 0x28))
                    (*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x20));
          goto LAB_00468517;
        }
      }
      cVar3 = FUN_004680b0();
      if (cVar3 != '\0') {
        return 0;
      }
    }
    if (*(int *)(in_ECX + 0x10) == 1) {
      *(undefined4 *)(in_ECX + 0x10) = 2;
      return local_10;
    }
    if (*(int *)(in_ECX + 0x10) == 2) {
      *(undefined4 *)(in_ECX + 0x10) = 1;
      return local_10;
    }
  }
  else {
    uVar6 = 0;
    if (iVar2 == 1) {
      uVar6 = 3;
    }
    else if (iVar2 == 2) {
      uVar6 = 1;
    }
    if (uVar6 <= *(uint *)(in_ECX + 0x14)) {
      *(undefined4 *)(in_ECX + 8) = 0;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 0x10) = 0;
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(undefined4 *)(in_ECX + 0x18) = 0;
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x10) = 1;
    }
  }
  return local_10;
}


// ==== FUN_004685f0 @ 0x004685f0 ====

void FUN_004685f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cf09;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1304;
  FUN_0046a270();
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00468650 @ 0x00468650 ====

void FUN_00468650(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  param_1 = thunk_FUN_00796e60(*(undefined4 *)(param_1 + 4));
  iVar1 = *(int *)(in_ECX + 0x3c);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x44) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x40) - iVar1 >> 2)))
  {
    FUN_0042f3e0(*(undefined4 *)(in_ECX + 0x40),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x40);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x40) = puVar2 + 1;
  return;
}


// ==== FUN_004686c0 @ 0x004686c0 ====

undefined4 FUN_004686c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097cf1b;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(param_1 + 8,0,0xffffffff);
  local_4 = 0;
  iVar2 = FUN_00403620(0,local_14,s_load_script_009a12ac,0xb);
  if (iVar2 == 0) {
    FUN_00467eb0(param_1 + 0x24);
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX;
    }
  }
  else {
    iVar2 = FUN_00403620(0,local_14,s_create_script_009a12b8,0xd);
    if (iVar2 == 0) {
      FUN_00467f10(param_1 + 0x24);
      if (0xf < local_10) {
        _free(local_24);
        return extraout_EAX_00;
      }
    }
    else {
      iVar2 = FUN_00403620(0,local_14,s_destroy_script_009a12c8,0xe);
      if (iVar2 != 0) {
        cVar1 = FUN_004036a0(local_28,s_set_property_009a12d8);
        if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00467e20(param_1 + 0x24);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00468650(param_1 + 0x24);
      if (0xf < local_10) {
        _free(local_24);
        return extraout_EAX_01;
      }
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00468860 @ 0x00468860 ====

uint FUN_00468860(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70004) {
    uVar1 = FUN_004686c0(param_1);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00468890 @ 0x00468890 ====

void FUN_00468890(byte param_1)

{
  void *in_ECX;
  
  FUN_00467db0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004688f0 @ 0x004688f0 ====

void FUN_004688f0(undefined4 param_1,ushort param_2)

{
  int iVar1;
  ulong uVar2;
  int in_ECX;
  WCHAR local_10 [8];
  
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  iVar1 = GetLocaleInfoW((uint)param_2,0x1004,local_10,8);
  if (iVar1 != 0) {
    uVar2 = _wcstoul(local_10,(wchar_t **)0x0,0);
    *(ulong *)(in_ECX + 0x1c) = uVar2;
  }
  return;
}


// ==== FUN_00468940 @ 0x00468940 ====

int FUN_00468940(LPCWSTR param_1,int param_2,LPSTR param_3)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = WideCharToMultiByte(*(UINT *)(in_ECX + 0x1c),0,param_1,param_2,(LPSTR)0x0,0,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  if (iVar1 < 0x101) {
    iVar1 = WideCharToMultiByte(*(UINT *)(in_ECX + 0x1c),0,param_1,param_2,param_3,0x100,(LPCSTR)0x0
                                ,(LPBOOL)0x0);
    return iVar1;
  }
  return 0;
}


// ==== FUN_004689a0 @ 0x004689a0 ====

void FUN_004689a0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009a1338;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004689e0 @ 0x004689e0 ====

undefined4 FUN_004689e0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    return 0;
  }
  uVar2 = *(uint *)(in_ECX + 0x14) >> 2;
  iVar3 = uVar2 * -4;
  if (*(uint *)(in_ECX + 0x10) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(in_ECX + 0x10);
  }
  uVar1 = *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4) + (*(uint *)(in_ECX + 0x14) + iVar3) * 4);
  if (*(int *)(in_ECX + 0x18) != 0) {
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    if ((uint)(*(int *)(in_ECX + 0x10) * 4) <= *(uint *)(in_ECX + 0x14)) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
    iVar3 = *(int *)(in_ECX + 0x18) + -1;
    *(int *)(in_ECX + 0x18) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00468a40 @ 0x00468a40 ====

void FUN_00468a40(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  HWND pHVar5;
  HIMC pHVar6;
  undefined4 *in_ECX;
  undefined1 local_44 [4];
  undefined1 local_40;
  uint uStack_34;
  undefined4 local_30;
  void *local_2c;
  undefined1 auStack_28 [12];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cf6b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a1388;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  local_4 = 0;
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = 0;
  pcVar2 = PTR_s_WindowHandle_00ae08e8;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_WindowHandle_00ae08e8,(int)pcVar2 - (int)(PTR_s_WindowHandle_00ae08e8 + 1));
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_28,local_44);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  pHVar5 = (HWND)thunk_FUN_00796e90(uVar4);
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  if (uStack_34 < 0x10) {
    pHVar6 = ImmGetContext(pHVar5);
    in_ECX[1] = pHVar6;
    in_ECX[7] = 0;
    ExceptionList = pvStack_14;
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00468b40 @ 0x00468b40 ====

void FUN_00468b40(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  HWND pHVar5;
  undefined4 *in_ECX;
  undefined1 local_44 [4];
  undefined1 local_40;
  uint uStack_34;
  undefined4 local_30;
  void *local_2c;
  undefined1 auStack_28 [12];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cf90;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a1388;
  local_4 = 0;
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = 0;
  pcVar2 = PTR_s_WindowHandle_00ae08e8;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_WindowHandle_00ae08e8,(int)pcVar2 - (int)(PTR_s_WindowHandle_00ae08e8 + 1));
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_28,local_44);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  pHVar5 = (HWND)thunk_FUN_00796e90(uVar4);
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  if (uStack_34 < 0x10) {
    ImmReleaseContext(pHVar5,(HIMC)in_ECX[1]);
    FUN_0046cfc0();
    ExceptionList = pvStack_14;
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00468c30 @ 0x00468c30 ====

void FUN_00468c30(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  HWND pHVar5;
  int in_ECX;
  void *unaff_EBX;
  undefined1 local_44 [4];
  undefined1 local_40;
  uint uStack_34;
  undefined4 local_30;
  void *local_2c;
  undefined1 auStack_28 [12];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097cfaa;
  pvStack_c = ExceptionList;
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = 0;
  pcVar2 = PTR_s_WindowHandle_00ae08e8;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740(PTR_s_WindowHandle_00ae08e8,(int)pcVar2 - (int)(PTR_s_WindowHandle_00ae08e8 + 1));
  local_4 = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar4 = (**(code **)(*piVar3 + 8))(auStack_28,local_44);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  pHVar5 = (HWND)thunk_FUN_00796e90(uVar4);
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  if (0xf < uStack_34) {
    _free(unaff_EBX);
    return;
  }
  if (*(char *)(local_4 + 4) == '\0') {
    ImmNotifyIME(*(HIMC *)(in_ECX + 4),0x15,4,0);
    ImmAssociateContext(pHVar5,(HIMC)0x0);
    ExceptionList = pvStack_14;
    return;
  }
  ImmAssociateContext(pHVar5,*(HIMC *)(in_ECX + 4));
  ImmNotifyIME(*(HIMC *)(in_ECX + 4),0x15,2,0);
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00468d60 @ 0x00468d60 ====

undefined4 FUN_00468d60(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x20007) {
    FUN_00468c30(param_1);
    return 1;
  }
  if (iVar1 != 0x20009) {
    return 0;
  }
  if ((char)param_1[1] == '\0') {
    ImmNotifyIME(*(HIMC *)(in_ECX + 4),0x15,2,0);
    return 1;
  }
  ImmNotifyIME(*(HIMC *)(in_ECX + 4),0x15,4,0);
  return 1;
}


// ==== FUN_00468dd0 @ 0x00468dd0 ====

undefined4 FUN_00468dd0(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  ushort uVar5;
  ushort uVar6;
  char acStack_312 [6];
  undefined1 local_30c [256];
  undefined2 local_20c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097cfea;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (((param_1 & 0x800) != 0) &&
     (ExceptionList = &pvStack_c,
     uVar2 = ImmGetCompositionStringW(*(HIMC *)(in_ECX + 4),0x800,local_20c,0x200), 0 < (int)uVar2))
  {
    *(undefined2 *)((int)local_20c + (uVar2 & 0xfffffffe)) = 0;
    FUN_00803417();
    iVar3 = FUN_00468940();
    if (0 < iVar3) {
      local_30c[iVar3] = 0;
      iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
      uStack_4 = 0;
      if (iVar3 != 0) {
        FUN_00401830(local_30c);
        FUN_00469660();
      }
      uStack_4 = 0xffffffff;
      FUN_00460680();
    }
  }
  uVar5 = 0;
  if ((param_1 & 8) != 0) {
    uVar2 = ImmGetCompositionStringW(*(HIMC *)(in_ECX + 4),8,local_20c,0x200);
    if ((int)uVar2 < 1) {
      iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
      uStack_4 = 2;
      if (iVar3 != 0) {
        FUN_00401830(&DAT_009a1322);
        FUN_00469560();
      }
    }
    else {
      *(undefined2 *)((int)local_20c + (uVar2 & 0xfffffffe)) = 0;
      FUN_00803417();
      iVar3 = FUN_00468940();
      if (iVar3 < 1) goto LAB_00468fc7;
      local_30c[iVar3] = 0;
      iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
      uStack_4 = 1;
      if (iVar3 != 0) {
        FUN_00401830(local_30c);
        FUN_00469560();
      }
    }
    uStack_4 = 0xffffffff;
    FUN_00460680();
  }
LAB_00468fc7:
  if (((param_1 & 0x10) != 0) && (iVar3 = ImmGetCompositionString(), 0 < iVar3)) {
    ImmGetCompositionString();
    acStack_312[iVar3 + -10] = '\0';
    if (0 < iVar3) {
      uVar2 = 0;
      do {
        if ((acStack_312[uVar2 - 10] == '\x01') || (acStack_312[uVar2 - 10] == '\x03')) break;
        uVar5 = uVar5 + 1;
        uVar2 = (uint)uVar5;
      } while ((int)uVar2 < iVar3);
    }
    uVar2 = (uint)uVar5;
    uVar6 = uVar5;
    if ((int)uVar2 < iVar3) {
      iVar1 = uVar2 - 10;
      do {
        if (acStack_312[uVar2 - 10] != acStack_312[iVar1]) break;
        uVar6 = uVar6 + 1;
        uVar2 = (uint)uVar6;
      } while ((int)uVar2 < iVar3);
    }
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = &PTR_FUN_009a134c;
      *(ushort *)(puVar4 + 1) = uVar5;
      *(ushort *)((int)puVar4 + 6) = uVar6;
    }
    FUN_00460680();
  }
  ExceptionList = pvStack_c;
  return 1;
}


// ==== FUN_00469090 @ 0x00469090 ====

undefined4 FUN_00469090(uint param_1,int param_2)

{
  LPCANDIDATELIST ptVar1;
  char cVar2;
  int iVar3;
  DWORD DVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_194;
  undefined *puStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined1 *local_160;
  DWORD local_15c;
  undefined1 auStack_158 [4];
  LPCANDIDATELIST ptStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 *puStack_148;
  int local_144;
  undefined1 *puStack_140;
  int iStack_13c;
  undefined1 auStack_138 [4];
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined1 auStack_128 [28];
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097d073;
  local_c = ExceptionList;
  if (param_1 < 0x110) {
    if (param_1 == 0x10f) {
      ExceptionList = &local_c;
      cVar2 = FUN_00468dd0();
      if (cVar2 == '\0') {
        ExceptionList = local_c;
        return 0;
      }
    }
    else if (param_1 != 0x10d) {
      if (param_1 != 0x10e) {
        return 0;
      }
      uStack_184 = (undefined1 *)0x4690f9;
      ExceptionList = &local_c;
      iVar3 = ImmGetCompositionString();
      if (iVar3 < 1) {
        local_160 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        uStack_4 = 0;
        if (local_160 == (undefined1 *)0x0) {
          local_15c = 0;
        }
        else {
          puStack_148 = (undefined1 *)&uStack_18c;
          puStack_190 = &DAT_009a131a;
          uStack_194 = 0x469134;
          FUN_00401830();
          puStack_190 = (undefined *)0x46913b;
          local_15c = FUN_00469660();
        }
        uStack_4 = 0xffffffff;
        FUN_00460680();
      }
    }
  }
  else if (param_1 != 0x281) {
    if (param_1 != 0x282) {
      return 0;
    }
    switch(param_2 + -3) {
    case 0:
    case 2:
      ExceptionList = &local_c;
      local_144 = in_ECX;
      iVar3 = (**(code **)(*DAT_00b5a6b0 + 8))();
      if (iVar3 == 1) {
        ExceptionList = local_c;
        return 0;
      }
      uStack_184 = (undefined1 *)0x469204;
      DVar4 = ImmGetCandidateListW(*(HIMC *)(in_ECX + 4),0,(LPCANDIDATELIST)0x0,0);
      uStack_14c = 0;
      uStack_150 = 0;
      ptStack_154 = (LPCANDIDATELIST)0x0;
      if (DVar4 != 0) {
        uStack_4 = 3;
        FUN_00469950();
        ptVar1 = ptStack_154;
        uStack_184 = (undefined1 *)0x4692ae;
        ImmGetCandidateListW(*(HIMC *)(in_ECX + 4),0,ptStack_154,DVar4);
        uStack_134 = 0;
        uStack_130 = 0;
        uStack_12c = 0;
        local_160 = (undefined1 *)ptVar1->dwSelection;
        uVar6 = ptVar1->dwPageSize;
        puStack_148 = (undefined1 *)ptVar1->dwPageStart;
        local_15c = ptVar1->dwCount;
        uStack_4._0_1_ = 4;
        DVar4 = ((uint)local_160 / uVar6) * uVar6;
        if (puStack_148 == (undefined1 *)DVar4) {
          uVar5 = local_15c;
          if (uVar6 + (int)puStack_148 < local_15c) {
            uVar5 = uVar6 + (int)puStack_148;
          }
          if (puStack_148 < uVar5) {
            iStack_13c = uVar5 - (int)puStack_148;
            FUN_00803417();
            iVar3 = FUN_00468940();
            local_10c[iVar3] = 0;
            puStack_140 = (undefined1 *)&uStack_194;
            FUN_00401830(s__d__s_009a131c);
            FUN_00404230(auStack_128);
            uStack_4._0_1_ = 5;
            FUN_00406720();
            uStack_4 = CONCAT31(uStack_4._1_3_,4);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          uVar6 = (int)local_160 - (int)puStack_148;
          if (*(int *)(local_144 + 0x1c) == 0x3b5) {
            uVar6 = local_15c;
          }
          puStack_140 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
          uStack_4._0_1_ = 6;
          if (puStack_140 == (undefined1 *)0x0) {
            local_160 = (undefined1 *)0x0;
          }
          else {
            local_160 = auStack_158 + -0x28;
            uStack_184 = auStack_138;
            uStack_188 = 0x4693ea;
            FUN_00406600();
            uStack_188 = 1;
            uStack_18c = 0x4693f4;
            uStack_184 = (undefined1 *)uVar6;
            local_160 = (undefined1 *)FUN_004699c0();
          }
          uStack_4._0_1_ = 4;
          FUN_00460680();
        }
        else {
          uStack_184 = (undefined1 *)0x4692f6;
          ImmNotifyIME(*(HIMC *)(local_144 + 4),0x16,0,DVar4);
        }
        FUN_00406250();
        FUN_00412dc0();
        ExceptionList = local_c;
        return 1;
      }
      uStack_4 = 1;
      local_160 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      uStack_4._0_1_ = 2;
      if (local_160 == (undefined1 *)0x0) {
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        local_15c = 0;
      }
      else {
        puStack_148 = auStack_158 + -0x28;
        uStack_184 = auStack_158;
        uStack_188 = 0x469251;
        FUN_00406600();
        uStack_184 = (undefined1 *)0x0;
        uStack_188 = 0;
        uStack_18c = 0x46925a;
        local_15c = FUN_004699c0();
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
      }
      break;
    case 1:
      ExceptionList = &local_c;
      iVar3 = (**(code **)(*DAT_00b5a6b0 + 8))();
      if (iVar3 == 1) {
        ExceptionList = local_c;
        return 0;
      }
      ptStack_154 = (LPCANDIDATELIST)0x0;
      uStack_150 = 0;
      uStack_14c = 0;
      uStack_4 = 7;
      puStack_140 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      uStack_4._0_1_ = 8;
      if (puStack_140 == (undefined1 *)0x0) {
        local_160 = (undefined1 *)0x0;
      }
      else {
        local_160 = auStack_158 + -0x28;
        uStack_184 = auStack_158;
        uStack_188 = 0x469485;
        FUN_00406600();
        uStack_184 = (undefined1 *)0x0;
        uStack_188 = 0;
        uStack_18c = 0x46948e;
        local_160 = (undefined1 *)FUN_004699c0();
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,7);
      break;
    case 3:
    case 5:
      ExceptionList = &local_c;
      FUN_004688f0();
      ImmGetConversionStatus(*(HIMC *)(in_ECX + 4),&local_15c,(LPDWORD)&local_160);
      if ((local_15c & 1) != 0) {
        FUN_004689a0();
        ExceptionList = local_c;
        return 0;
      }
      FUN_004689a0();
    default:
      ExceptionList = local_c;
      return 0;
    }
    FUN_00460680();
    FUN_00406250();
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_004694f0 @ 0x004694f0 ====

void FUN_004694f0(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a6a8 + 8))(param_1);
  return;
}


// ==== FUN_00469510 @ 0x00469510 ====

undefined4 FUN_00469510(void)

{
  return 0x20008;
}


// ==== FUN_00469520 @ 0x00469520 ====

undefined4 FUN_00469520(void)

{
  return 0x20010;
}


// ==== FUN_00469530 @ 0x00469530 ====

undefined1 * FUN_00469530(undefined1 *param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_2 != 0) {
    puVar1 = param_1;
    iVar2 = param_2;
    do {
      *puVar1 = *param_3;
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return param_1 + param_2;
}


// ==== FUN_00469560 @ 0x00469560 ====

void FUN_00469560(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cf40;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1360;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_004695e0 @ 0x004695e0 ====

undefined4 FUN_004695e0(void)

{
  return 0x20005;
}


// ==== FUN_004695f0 @ 0x004695f0 ====

void FUN_004695f0(byte param_1)

{
  FUN_00469620();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00469620 @ 0x00469620 ====

void FUN_00469620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1360;
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


// ==== FUN_00469660 @ 0x00469660 ====

void FUN_00469660(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097cf40;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1374;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_004696e0 @ 0x004696e0 ====

undefined4 FUN_004696e0(void)

{
  return 0x20006;
}


// ==== FUN_004696f0 @ 0x004696f0 ====

void FUN_004696f0(byte param_1)

{
  FUN_00469720();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00469720 @ 0x00469720 ====

void FUN_00469720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1374;
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


// ==== FUN_00469760 @ 0x00469760 ====

void FUN_00469760(byte param_1)

{
  void *in_ECX;
  
  FUN_00468b40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00469780 @ 0x00469780 ====

void FUN_00469780(void *param_1,uint param_2,undefined1 *param_3)

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
      iVar1 = FUN_00412e70();
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


// ==== FUN_00469950 @ 0x00469950 ====

void FUN_00469950(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2;
    }
    FUN_00469780(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2))) &&
     ((void *)(iVar2 + param_1) != pvVar3)) {
    pvVar3 = _memmove((void *)(iVar2 + param_1),pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_004699c0 @ 0x004699c0 ====

void FUN_004699c0(undefined4 param_1,undefined4 param_2,undefined1 param_3,void *param_4,
                 undefined4 param_5)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d090;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[2] = param_2;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009a1390;
  in_ECX[1] = param_1;
  FUN_00406600(&param_3);
  _Memory = param_4;
  if (param_4 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  FUN_00405de0(param_4,param_5,&param_3,param_1);
  _free(_Memory);
  return;
}


// ==== FUN_00469a50 @ 0x00469a50 ====

undefined4 FUN_00469a50(void)

{
  return 0x20011;
}


// ==== FUN_00469a60 @ 0x00469a60 ====

void FUN_00469a60(byte param_1)

{
  FUN_00469a90();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00469a90 @ 0x00469a90 ====

void FUN_00469a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1390;
  if (in_ECX[4] == 0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  FUN_00405de0(in_ECX[4],in_ECX[5],in_ECX + 3);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00469ae0 @ 0x00469ae0 ====

void FUN_00469ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a13cc;
  return;
}


// ==== FUN_00469af0 @ 0x00469af0 ====

void FUN_00469af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a13cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00469b10 @ 0x00469b10 ====

void FUN_00469b10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00469b20 @ 0x00469b20 ====

bool FUN_00469b20(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x10) == 0;
}


// ==== FUN_00469b30 @ 0x00469b30 ====

void FUN_00469b30(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *_Memory;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((undefined4 *)puVar2[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[2])(1);
    }
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (_Memory == *(void **)(param_1 + 4)) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00469b90 @ 0x00469b90 ====

undefined4 FUN_00469b90(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_2 + 4);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    iVar3 = (**(code **)(*(int *)puVar2[2] + 0xc))();
    if (param_1 == iVar3) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return 1;
}


// ==== FUN_00469bd0 @ 0x00469bd0 ====

int * FUN_00469bd0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(param_2 + 4);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return (int *)0x0;
    }
    piVar3 = (int *)puVar2[2];
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    if (param_1 == iVar4) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return piVar3;
}


// ==== FUN_00469c10 @ 0x00469c10 ====

undefined4 FUN_00469c10(int param_1,int param_2)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  undefined4 extraout_EAX;
  
  piVar1 = *(int **)(param_2 + 4);
  _Memory = (int *)*piVar1;
  while( true ) {
    if (_Memory == piVar1) {
      return 0;
    }
    iVar2 = (**(code **)(*(int *)_Memory[2] + 0xc))();
    if (param_1 == iVar2) break;
    _Memory = (int *)*_Memory;
  }
  if ((undefined4 *)_Memory[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[2])(1);
  }
  if (_Memory == *(int **)(param_2 + 4)) {
    return 1;
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00469c80 @ 0x00469c80 ====

int FUN_00469c80(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return local_4 + 0x10;
}


// ==== FUN_00469cb0 @ 0x00469cb0 ====

undefined4 FUN_00469cb0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e00(&local_4,&param_1);
  if ((local_4 == *(int *)(in_ECX + 0xc)) || (*(int *)(local_4 + 0x18) == 0)) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(local_4 + 0x14) + 8);
}


// ==== FUN_00469cf0 @ 0x00469cf0 ====

void FUN_00469cf0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *in_ECX;
  
  puVar2 = (undefined4 *)in_ECX[3];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*in_ECX + 0xc))(puVar3 + 4);
    if (*(char *)((int)puVar3 + 0x1d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x1d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x1d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x1d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x1d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x1d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00469d60 @ 0x00469d60 ====

void FUN_00469d60(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void **ppvVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  int *in_ECX;
  int *piVar9;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097d0ab;
  puVar2 = (undefined4 *)in_ECX[3];
  puVar3 = (undefined4 *)*puVar2;
  ppvVar5 = &pvStack_c;
  pvStack_c = ExceptionList;
  while( true ) {
    ExceptionList = ppvVar5;
    if (puVar3 == puVar2) {
      pvVar8 = operator_new(0x50);
      piVar9 = (int *)0x0;
      uStack_4 = 0;
      if (pvVar8 != (void *)0x0) {
        piVar9 = (int *)FUN_0046ae50();
      }
      uStack_4 = 0xffffffff;
      (**(code **)(*piVar9 + 4))(param_1);
      (**(code **)(*in_ECX + 0x1c))(pvVar8,piVar9);
      piVar9 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      (**(code **)(*piVar9 + 0x14))(param_1);
      ExceptionList = pvStack_c;
      return;
    }
    iVar7 = (**(code **)(*in_ECX + 0x24))(param_1,puVar3 + 4);
    if (iVar7 != 0) break;
    ppvVar5 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x1d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x1d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x1d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x1d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x1d);
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x1d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00469e50 @ 0x00469e50 ====

void FUN_00469e50(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int *piVar6;
  
  piVar5 = (int *)in_ECX[3];
  piVar6 = (int *)*piVar5;
  if (piVar6 != piVar5) {
    while (iVar4 = (**(code **)(*in_ECX + 0x20))(param_1,piVar6 + 4), iVar4 == 0) {
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x1d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x1d);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x1d);
          piVar3 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x1d);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
      if (piVar6 == piVar5) {
        return;
      }
    }
    piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    (**(code **)(*piVar5 + 0x18))(param_1);
  }
  return;
}


// ==== FUN_00469ee0 @ 0x00469ee0 ====

int FUN_00469ee0(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int *in_ECX;
  
  puVar2 = (undefined4 *)in_ECX[3];
  puVar3 = (undefined4 *)*puVar2;
  while( true ) {
    if (puVar3 == puVar2) {
      return 0;
    }
    iVar6 = (**(code **)(*in_ECX + 0x3c))(param_1,puVar3 + 4);
    if (iVar6 != 0) break;
    if (*(char *)((int)puVar3 + 0x1d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x1d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x1d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x1d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x1d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x1d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return iVar6;
}


// ==== FUN_00469f60 @ 0x00469f60 ====

void FUN_00469f60(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int *unaff_EBX;
  int *_Memory;
  undefined4 unaff_retaddr;
  undefined1 local_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097d0bd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar4 = (**(code **)(*in_ECX + 0x30))(param_2);
  if (iVar4 != 0) {
    piVar1 = *(int **)(iVar4 + 4);
    _Memory = (int *)*piVar1;
    if (_Memory != piVar1) {
      while( true ) {
        piVar2 = (int *)_Memory[2];
        iVar5 = (**(code **)(*piVar2 + 0xc))();
        if (param_2 == iVar5) break;
        _Memory = (int *)*_Memory;
        if (_Memory == piVar1) {
          ExceptionList = pvStack_10;
          return;
        }
      }
      if (_Memory != *(int **)(iVar4 + 4)) {
        *(int *)_Memory[1] = *_Memory;
        *(int *)(*_Memory + 4) = _Memory[1];
        _free(_Memory);
        return;
      }
      (**(code **)(*unaff_EBX + 0x1c))(unaff_retaddr,piVar2);
    }
    ExceptionList = pvStack_10;
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401740(s_pList____NULL_009a13b4,0xd);
  puStack_8 = (undefined1 *)0x0;
  FUN_00406880(local_2c);
  puStack_8 = (undefined1 *)0xffffffff;
  if (uStack_14 < 0x10) {
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_0046a070 @ 0x0046a070 ====

void FUN_0046a070(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0xc)) {
    iVar1 = *(int *)(local_4 + 0x14);
    iVar2 = FUN_00448300(iVar1,*(undefined4 *)(iVar1 + 4),&param_2);
    FUN_0046a450(1);
    *(int *)(iVar1 + 4) = iVar2;
    **(int **)(iVar2 + 4) = iVar2;
  }
  return;
}


// ==== FUN_0046a0d0 @ 0x0046a0d0 ====

/* WARNING: Removing unreachable block (ram,0x0046a13c) */

void FUN_0046a0d0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  int *_Memory;
  undefined1 uStack00000000;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097d0cf;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*in_ECX + 0x30))(param_1);
  if (iVar3 == 0) {
    FUN_00401740(s_pList____NULL_009a13a4,0xd);
    puStack_8 = (undefined1 *)0x0;
    FUN_00406880(auStack_26 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (1 < *(uint *)(iVar3 + 8)) {
    piVar1 = *(int **)(iVar3 + 4);
    _Memory = (int *)*piVar1;
    if (_Memory != piVar1) {
      while (iVar4 = (**(code **)(*(int *)_Memory[2] + 0xc))(), param_1 != iVar4) {
        _Memory = (int *)*_Memory;
        if (_Memory == piVar1) {
          ExceptionList = pvStack_10;
          return;
        }
      }
      if (_Memory != *(int **)(iVar3 + 4)) {
        *(int *)_Memory[1] = *_Memory;
        *(int *)(*_Memory + 4) = _Memory[1];
        _free(_Memory);
        return;
      }
      iVar3 = *(int *)(iVar3 + 4);
      iVar4 = FUN_00448300(iVar3,*(undefined4 *)(iVar3 + 4),&uStack00000000);
      FUN_0046a450(1);
      *(int *)(iVar3 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0046a1f0 @ 0x0046a1f0 ====

void FUN_0046a1f0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097d0ec;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a1414;
  local_4 = 1;
  FUN_00469cf0();
  local_4 = local_4 & 0xffffff00;
  FUN_0046a920(local_10,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0046a270 @ 0x0046a270 ====

void FUN_0046a270(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d0fe;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1414;
  iVar1 = FUN_004af930();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046a2e0 @ 0x0046a2e0 ====

void FUN_0046a2e0(undefined4 param_1)

{
  undefined1 local_30 [8];
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d118;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_24 = FUN_00415c90();
  local_20 = 0;
  local_4 = 0;
  local_1c[0] = param_1;
  FUN_0046a8a0(local_28);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0046acb0(local_30,local_1c);
  FUN_008984a0();
  FUN_008984a0();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0046a370 @ 0x0046a370 ====

void FUN_0046a370(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x1d) == '\0') {
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


// ==== FUN_0046a3c0 @ 0x0046a3c0 ====

void FUN_0046a3c0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x1d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x1d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x1d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x1d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x1d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x1d) == '\0');
    if (*(char *)((int)piVar4 + 0x1d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0046a430 @ 0x0046a430 ====

void FUN_0046a430(void)

{
  FUN_008984a0();
  return;
}


// ==== FUN_0046a440 @ 0x0046a440 ====

void FUN_0046a440(void)

{
  FUN_008984a0();
  return;
}


// ==== FUN_0046a450 @ 0x0046a450 ====

void FUN_0046a450(uint param_1)

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
  puStack_8 = &LAB_0097d178;
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


// ==== FUN_0046a4f0 @ 0x0046a4f0 ====

/* WARNING: Removing unreachable block (ram,0x0046a603) */
/* WARNING: Removing unreachable block (ram,0x0046a613) */
/* WARNING: Removing unreachable block (ram,0x0046a61c) */
/* WARNING: Removing unreachable block (ram,0x0046a61f) */
/* WARNING: Removing unreachable block (ram,0x0046a60f) */
/* WARNING: Removing unreachable block (ram,0x0046a62d) */
/* WARNING: Removing unreachable block (ram,0x0046a63a) */
/* WARNING: Removing unreachable block (ram,0x0046a645) */
/* WARNING: Removing unreachable block (ram,0x0046a641) */
/* WARNING: Removing unreachable block (ram,0x0046a635) */
/* WARNING: Removing unreachable block (ram,0x0046a648) */

void FUN_0046a4f0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097d178;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x1d) != '\0') {
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
  FUN_005038e0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x1d) == '\0') {
    if (*(char *)(param_2[2] + 0x1d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x1d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      piVar3 = (int *)FUN_004af910(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      uVar4 = FUN_0088f320(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[7] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[7] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[7] == '\0') {
            *(undefined1 *)(piVar5 + 7) = 1;
            *(undefined1 *)(piVar3 + 7) = 0;
            FUN_0046a370(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x1d) == '\0') {
            if ((*(char *)(*piVar5 + 0x1c) == '\x01') && (*(char *)(piVar5[2] + 0x1c) == '\x01'))
            goto LAB_0046a715;
            if (*(char *)(piVar5[2] + 0x1c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x1c) = 1;
              *(undefined1 *)(piVar5 + 7) = 0;
              FUN_004e1270(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 7) = (char)piVar3[7];
            *(undefined1 *)(piVar3 + 7) = 1;
            *(undefined1 *)(piVar5[2] + 0x1c) = 1;
            FUN_0046a370(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[7] == '\0') {
            *(undefined1 *)(piVar5 + 7) = 1;
            *(undefined1 *)(piVar3 + 7) = 0;
            FUN_004e1270(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x1d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x1c) != '\x01') || (*(char *)(*piVar5 + 0x1c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x1c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x1c) = 1;
                *(undefined1 *)(piVar5 + 7) = 0;
                FUN_0046a370(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 7) = (char)piVar3[7];
              *(undefined1 *)(piVar3 + 7) = 1;
              *(undefined1 *)(*piVar5 + 0x1c) = 1;
              FUN_004e1270(piVar3);
              break;
            }
LAB_0046a715:
            *(undefined1 *)(piVar5 + 7) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 7) = 1;
  }
  FUN_008984a0();
  _free(param_2);
  return;
}


// ==== FUN_0046a7b0 @ 0x0046a7b0 ====

void FUN_0046a7b0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x1d) == '\0') {
    FUN_0046a7b0(*(undefined4 *)((int)param_1 + 8));
    FUN_0046a440();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0046a7f0 @ 0x0046a7f0 ====

void FUN_0046a7f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0097d130;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != param_3; param_2 = (undefined4 *)*param_2) {
    iVar1 = FUN_00448300(param_1,*(undefined4 *)(param_1 + 4),param_2 + 2);
    FUN_0046a450(1);
    *(int *)(param_1 + 4) = iVar1;
    **(int **)(iVar1 + 4) = iVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0046a855 @ 0x0046a855 ====

void Catch_0046a855(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
  for (puVar1 = *(undefined4 **)(unaff_EBP + -0x18); puVar1 != puVar2;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_005171c0(unaff_EBP + 0xc,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0046a8a0 @ 0x0046a8a0 ====

void FUN_0046a8a0(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097d140;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00415c90();
  *(undefined4 **)(in_ECX + 4) = puVar1;
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_0046a7f0(*puVar1,**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4),param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@0046a909 @ 0x0046a909 ====

void Catch_0046a909(void)

{
  FUN_008984a0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0046a920 @ 0x0046a920 ====

void FUN_0046a920(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0046a7b0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x1d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x1d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x1d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x1d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0046a4f0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0046a9e0 @ 0x0046a9e0 ====

undefined4 *
FUN_0046a9e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097d161;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_0046a8a0(param_4 + 1);
    *(undefined1 *)(puVar1 + 7) = param_5;
    *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0046aa66 @ 0x0046aa66 ====

void Catch_0046aa66(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0046aa80 @ 0x0046aa80 ====

void FUN_0046aa80(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0046a920(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0046aab0 @ 0x0046aab0 ====

void FUN_0046aab0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097d178;
  local_c = ExceptionList;
  if (0xffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0046a9e0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x1c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1c) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[7] == '\0') {
LAB_0046aba9:
        *(undefined1 *)(*piVar5 + 0x1c) = 1;
        *(undefined1 *)(piVar6 + 7) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x1c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0046a370(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x1c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
        FUN_004e1270(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[7] == '\0') goto LAB_0046aba9;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e1270(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x1c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x1d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x1c);
  } while( true );
}


// ==== FUN_0046ac90 @ 0x0046ac90 ====

void FUN_0046ac90(byte param_1)

{
  void *in_ECX;
  
  FUN_0046a1f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046acb0 @ 0x0046acb0 ====

void FUN_0046acb0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0046aab0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0046a3c0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0046aab0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0046ad70 @ 0x0046ad70 ====

void FUN_0046ad70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a14c8;
  return;
}


// ==== FUN_0046ad80 @ 0x0046ad80 ====

void FUN_0046ad80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a14c8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046ada0 @ 0x0046ada0 ====

void FUN_0046ada0(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,undefined4 param_6,void *param_7,undefined1 param_8)

{
  int *piVar1;
  int in_ECX;
  void *unaff_retaddr;
  uint in_stack_00000030;
  undefined1 *puStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d1a0;
  pvStack_c = ExceptionList;
  local_4 = 1;
  if (*(int *)(in_ECX + 4) == -1) {
    ExceptionList = &pvStack_c;
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    (**(code **)(*piVar1 + 0x10))(&param_1);
  }
  else {
    ExceptionList = &pvStack_c;
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    (**(code **)(*piVar1 + 0xc))(*(undefined4 *)(in_ECX + 4),&param_1);
  }
  puStack_14 = &param_8;
  if (0xf < param_5) {
    _free(unaff_retaddr);
    return;
  }
  param_5 = 0xf;
  param_4 = 0;
  if (in_stack_00000030 < 0x10) {
    ExceptionList = puStack_14;
    return;
  }
  _free(param_7);
  return;
}


// ==== FUN_0046ae50 @ 0x0046ae50 ====

void FUN_0046ae50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d1bd;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a14e4;
  FUN_0046c330();
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[1] = 0xffffffff;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046aeb0 @ 0x0046aeb0 ====

/* WARNING: Removing unreachable block (ram,0x0046af10) */

void FUN_0046aeb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d1cf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a14e4;
  local_4 = 0;
  if (in_ECX[0x11] == 0) {
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
    FUN_0046c390();
    *in_ECX = &PTR_FUN_009a14c8;
    ExceptionList = local_c;
    return;
  }
  FUN_00405de0(in_ECX[0x11],in_ECX[0x12],in_ECX + 0x10);
  _free((void *)in_ECX[0x11]);
  return;
}


// ==== FUN_0046af60 @ 0x0046af60 ====

void FUN_0046af60(undefined4 param_1)

{
  int in_ECX;
  undefined4 unaff_retaddr;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  (**(code **)(*(int *)(in_ECX + 8) + 4))(param_1);
  if (*(int *)(in_ECX + 0x44) == 0) {
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = 0;
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 0x44),*(undefined4 *)(in_ECX + 0x48),in_ECX + 0x40,unaff_retaddr);
  _free(*(void **)(in_ECX + 0x44));
  return;
}


// ==== FUN_0046afc0 @ 0x0046afc0 ====

void FUN_0046afc0(void *param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  uint in_stack_00000018;
  int in_stack_00000020;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097d1e9;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_00410500(&param_1);
  if (iVar2 != 0) {
    FUN_0040c1c0(*(int *)(in_ECX + 0x44) + in_stack_00000020 * 0x1c,*(undefined4 *)(iVar2 + 0x40),
                 *(undefined4 *)(iVar2 + 0x44),in_stack_00000020);
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
    if (in_stack_00000018 < 0x10) {
      ExceptionList = local_10;
      return;
    }
    _free(param_1);
    return;
  }
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_pScriptRes____NULL_009a14ac,0x12);
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


// ==== FUN_0046b0a0 @ 0x0046b0a0 ====

/* WARNING: Removing unreachable block (ram,0x0046b142) */

undefined4 FUN_0046b0a0(void)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097d203;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00405670();
  iVar1 = FUN_00403620();
  if (iVar1 == 0) {
    FUN_00401660();
    FUN_0046afc0();
    ExceptionList = local_c;
    return 1;
  }
  iVar1 = FUN_00403620();
  if (iVar1 == 0) {
    FUN_00401660();
    local_4._0_1_ = 1;
    FUN_00401660(0x1c,0,0xffffffff);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046ada0();
    FUN_00406250();
    ExceptionList = local_c;
    return 1;
  }
  FUN_00406250();
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0046b230 @ 0x0046b230 ====

void FUN_0046b230(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d215;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_0046afc0();
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0046b2d0 @ 0x0046b2d0 ====

undefined4 * FUN_0046b2d0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_3c [4];
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  int iStack_1c;
  undefined1 local_c [8];
  undefined4 *puStack_4;
  
  iStack_1c = in_ECX + 0x40;
  puStack_20 = local_c;
  uStack_24 = 0x46b2ea;
  puVar3 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 8) + 8))();
  puVar2 = puStack_4;
  *puStack_4 = *puVar3;
  puStack_4[1] = puVar3[1];
  puStack_4[2] = puVar3[2];
  if (puStack_4[1] == 4) {
    piVar1 = puStack_4 + 2;
    puStack_4 = (undefined4 *)auStack_3c;
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = 0;
    FUN_00401660(*(int *)(in_ECX + 0x44) + *piVar1 * 0x1c,0,0xffffffff);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6c8 + 0x18))();
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = FUN_0046b0a0(puVar2[2]);
      if (iVar4 == 0) {
        puVar3[1] = *(undefined4 *)(in_ECX + 4);
        return puVar3;
      }
      puVar2[1] = 5;
      (**(code **)*puVar3)(1);
    }
  }
  return (undefined4 *)0x0;
}


// ==== FUN_0046b390 @ 0x0046b390 ====

void FUN_0046b390(byte param_1)

{
  void *in_ECX;
  
  FUN_0046aeb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046b3b0 @ 0x0046b3b0 ====

void FUN_0046b3b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a15d8;
  return;
}


// ==== FUN_0046b3c0 @ 0x0046b3c0 ====

void FUN_0046b3c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a15d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046b3e0 @ 0x0046b3e0 ====

void FUN_0046b3e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0046b450 @ 0x0046b450 ====

undefined4 FUN_0046b450(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x30),s_begin_009a15c8,5);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x30),&PTR_LAB_009a15d0,3);
  if (iVar1 == 0) {
    return 0;
  }
  return 0;
}


// ==== FUN_0046b4f0 @ 0x0046b4f0 ====

undefined4 FUN_0046b4f0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  uint in_stack_0000001c;
  int *in_stack_00000020;
  char local_e8 [80];
  undefined1 local_98 [28];
  undefined1 local_7c [28];
  undefined1 local_60 [28];
  undefined1 auStack_44 [28];
  undefined1 auStack_28 [24];
  undefined1 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar5 = in_stack_00000020;
  puStack_8 = &LAB_0097d253;
  local_c = ExceptionList;
  iVar1 = *in_stack_00000020;
  iVar8 = 0;
  ExceptionList = &local_c;
  *in_stack_00000020 = iVar1 + 1;
  local_4 = 0;
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  cVar7 = *(char *)((int)puVar6 + iVar1);
  while (('\0' < cVar7 && (iVar1 = _isspace((int)cVar7), iVar1 != 0))) {
    iVar1 = *piVar5;
    *piVar5 = iVar1 + 1;
    puVar6 = param_2;
    if (in_stack_0000001c < 0x10) {
      puVar6 = &param_2;
    }
    cVar7 = *(char *)((int)puVar6 + iVar1);
  }
  switch(cVar7) {
  case '\0':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '!':
    iVar1 = *piVar5;
    *piVar5 = iVar1 + 1;
    pcVar2 = (char *)FUN_0043fec0(iVar1);
    if (*pcVar2 == '=') {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    *piVar5 = iVar1;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '&':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '(':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case ')':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '+':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '-':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '<':
    iVar1 = *piVar5;
    *piVar5 = iVar1 + 1;
    pcVar2 = (char *)FUN_0043fec0(iVar1);
    if (*pcVar2 == '=') {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    *piVar5 = iVar1;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '=':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '>':
    iVar1 = *piVar5;
    *piVar5 = iVar1 + 1;
    pcVar2 = (char *)FUN_0043fec0(iVar1);
    if (*pcVar2 == '=') {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    *piVar5 = iVar1;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case '|':
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  while ((((((iVar1 = _isalnum((int)cVar7), iVar1 != 0 || (cVar7 == '#')) || (cVar7 == '-')) ||
           (((cVar7 == '_' || (cVar7 == '@')) || (cVar7 == '%')))) && ('\0' < cVar7)) ||
         (cVar7 < '\0'))) {
    iVar1 = *piVar5;
    local_e8[iVar8] = cVar7;
    iVar8 = iVar8 + 1;
    *piVar5 = iVar1 + 1;
    puVar6 = param_2;
    if (in_stack_0000001c < 0x10) {
      puVar6 = &param_2;
    }
    cVar7 = *(char *)((int)puVar6 + iVar1);
  }
  *piVar5 = *piVar5 + -1;
  local_e8[iVar8] = '\0';
  iVar1 = __stricmp(local_e8,&DAT_009a1544);
  if (iVar1 == 0) {
    if (0xf < in_stack_0000001c) {
      _free(param_2);
      return extraout_EAX;
    }
    uVar3 = 0x10;
  }
  else {
    iVar1 = __stricmp(local_e8,s_elseif_009a1548);
    if (iVar1 != 0) {
      iVar1 = __stricmp(local_e8,&DAT_009a1550);
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      iVar1 = 0;
      if (0 < iVar8) {
        do {
          iVar4 = _isdigit((int)local_e8[iVar1]);
          if (iVar4 == 0) {
            if (*(int *)(in_ECX + 4) == -1) {
              FUN_00401830(local_e8);
              local_4 = CONCAT31(local_4._1_3_,1);
              piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
              uVar3 = (**(code **)(*piVar5 + 8))(auStack_44,local_60);
              local_c = (void *)CONCAT31(local_c._1_3_,2);
              uVar3 = thunk_FUN_00796e60(uVar3);
              *(undefined4 *)(in_ECX + 0x1c) = uVar3;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00401830(local_e8);
            local_4 = CONCAT31(local_4._1_3_,3);
            piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
            uVar3 = (**(code **)(*piVar5 + 4))(auStack_28,*(undefined4 *)(in_ECX + 4),local_7c);
            uStack_10 = 4;
            uVar3 = thunk_FUN_00796e60(uVar3);
            *(undefined4 *)(in_ECX + 0x1c) = uVar3;
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar8);
      }
      FUN_00401830(local_e8);
      local_4 = CONCAT31(local_4._1_3_,5);
      uVar3 = thunk_FUN_00796e60(local_98);
      *(undefined4 *)(in_ECX + 0x1c) = uVar3;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (0xf < in_stack_0000001c) {
      _free(param_2);
      return extraout_EAX_00;
    }
    uVar3 = 0x11;
  }
  ExceptionList = local_c;
  return uVar3;
}


// ==== FUN_0046ba40 @ 0x0046ba40 ====

int FUN_0046ba40(undefined1 param_1,void *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int iVar3;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int in_ECX;
  int iVar4;
  uint in_stack_0000001c;
  undefined4 *in_stack_00000020;
  undefined1 auStack_40 [4];
  undefined1 local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar1 = in_stack_00000020;
  puStack_8 = &LAB_0097d265;
  local_c = ExceptionList;
  in_stack_00000020 = (undefined4 *)auStack_40;
  local_28 = 0xf;
  local_2c = 0;
  local_4 = 0;
  iVar4 = 0;
  local_3c = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  uVar2 = FUN_0046b4f0();
  switch(uVar2) {
  case 5:
    in_stack_00000020 = (undefined4 *)auStack_40;
    local_28 = 0xf;
    local_2c = 0;
    local_3c = 0;
    FUN_00401660(&param_1,0,0xffffffff);
    iVar4 = FUN_0046ba40();
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 9:
    in_stack_00000020 = (undefined4 *)auStack_40;
    local_28 = 0xf;
    local_2c = 0;
    local_3c = 0;
    FUN_00401660(&param_1,0,0xffffffff);
    iVar4 = FUN_0046ba40();
    in_stack_00000020 = (undefined4 *)auStack_40;
    local_28 = 0xf;
    local_2c = 0;
    local_3c = 0;
    FUN_00401660(&param_1,0,0xffffffff);
    FUN_0046b4f0();
    if (0xf < in_stack_0000001c) {
      local_28 = 0x46bb88;
      _free(param_2);
      return extraout_EAX;
    }
    break;
  case 0xd:
  case 0xe:
    iVar4 = *(int *)(in_ECX + 0x1c);
  default:
    in_stack_00000020 = (undefined4 *)*puVar1;
    local_28 = 0xf;
    local_2c = 0;
    local_3c = 0;
    FUN_00401660(&param_1,0,0xffffffff);
    iVar3 = FUN_0046b4f0();
    if (iVar3 == 0xb) {
      in_stack_00000020 = (undefined4 *)auStack_40;
      local_28 = 0xf;
      local_2c = 0;
      local_3c = 0;
      FUN_00401660(&param_1,0,0xffffffff);
      FUN_0046b4f0();
      if (in_stack_0000001c < 0x10) {
        ExceptionList = local_c;
        return *(int *)(in_ECX + 0x1c) + iVar4;
      }
      local_28 = 0x46bc95;
      _free(param_2);
      return extraout_EAX_01;
    }
    if (iVar3 == 0xc) {
      in_stack_00000020 = (undefined4 *)auStack_40;
      local_28 = 0xf;
      local_2c = 0;
      local_3c = 0;
      FUN_00401660(&param_1,0,0xffffffff);
      FUN_0046b4f0();
      iVar4 = iVar4 - *(int *)(in_ECX + 0x1c);
    }
    else if (iVar3 != 0xf) {
      *puVar1 = in_stack_00000020;
    }
    if (0xf < in_stack_0000001c) {
      local_28 = 0x46bbfc;
      _free(param_2);
      return extraout_EAX_00;
    }
  }
  ExceptionList = local_c;
  return iVar4;
}


// ==== FUN_0046bcd0 @ 0x0046bcd0 ====

undefined4 FUN_0046bcd0(undefined1 param_1,void *param_2)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  uint in_stack_0000001c;
  undefined1 *puStack00000020;
  undefined1 auStack_3c [4];
  undefined1 local_38;
  undefined4 local_28;
  undefined4 local_24;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d277;
  local_c = ExceptionList;
  puStack00000020 = auStack_3c;
  local_24 = 0xf;
  local_28 = 0;
  local_4 = 0;
  local_38 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_0046ba40();
  puStack00000020 = auStack_3c;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  uVar1 = FUN_0046b4f0();
  switch(uVar1) {
  case 0:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 6:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 7:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 8:
    puStack00000020 = auStack_3c;
    FUN_00765c50(&param_1);
    FUN_0046ba40();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xf:
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  local_24 = 0x46bfaa;
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_0046c010 @ 0x0046c010 ====

void FUN_0046c010(void)

{
  int iVar1;
  int in_ECX;
  
  while( true ) {
    if (*(int *)(in_ECX + 0x24) != 0) {
      if ((*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24)) / 0x1c != 0) {
        return;
      }
    }
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    iVar1 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
    if ((iVar1 == 0) ||
       ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar1) / 0x1c) <= *(uint *)(in_ECX + 0x30)))
    break;
    FUN_00405670(iVar1 + *(uint *)(in_ECX + 0x30) * 0x1c,in_ECX + 0x20);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_0046c090 @ 0x0046c090 ====

/* WARNING: Removing unreachable block (ram,0x0046c0de) */
/* WARNING: Removing unreachable block (ram,0x0046c133) */
/* WARNING: Removing unreachable block (ram,0x0046c183) */

void FUN_0046c090(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  int local_4;
  
  uVar4 = (*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x14)) - 1;
  uVar1 = uVar4 >> 2;
  iVar3 = uVar1 * -4;
  if (*(uint *)(in_ECX + 0x10) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(in_ECX + 0x10);
  }
  if (*(int *)(*(int *)(*(int *)(in_ECX + 0xc) + uVar1 * 4) + (uVar4 + iVar3) * 4) == 0) {
    return;
  }
  local_4 = 0;
  do {
    iVar3 = *(int *)(in_ECX + 0x24);
    uVar1 = *(uint *)(iVar3 + 0x14);
    if (uVar1 != 0) {
      uVar4 = uVar1;
      if (4 < uVar1) {
        uVar4 = 5;
      }
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar3 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar3 + 4);
      }
      bVar7 = false;
      iVar2 = 0;
      bVar8 = true;
      pbVar6 = (byte *)s_endif_009a157c;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if ((((iVar2 == 0) && (4 < uVar1)) && (uVar1 == 5)) && (local_4 < 1)) {
        return;
      }
    }
    uVar1 = *(uint *)(iVar3 + 0x14);
    if (uVar1 != 0) {
      uVar4 = uVar1;
      if (1 < uVar1) {
        uVar4 = 2;
      }
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar3 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar3 + 4);
      }
      bVar7 = false;
      iVar2 = 0;
      bVar8 = true;
      pbVar6 = &DAT_009a1584;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar2 == 0) && (1 < uVar1)) && (uVar1 == 2)) {
        local_4 = local_4 + 1;
      }
    }
    uVar1 = *(uint *)(iVar3 + 0x14);
    if (uVar1 != 0) {
      uVar4 = uVar1;
      if (4 < uVar1) {
        uVar4 = 5;
      }
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar3 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar3 + 4);
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      pbVar6 = (byte *)s_endif_009a1588;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar3 == 0) && (4 < uVar1)) && (uVar1 == 5)) {
        local_4 = local_4 + -1;
      }
    }
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    iVar3 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
    if ((iVar3 == 0) ||
       ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar3) / 0x1c) <= *(uint *)(in_ECX + 0x30)))
    {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00405670(iVar3 + *(uint *)(in_ECX + 0x30) * 0x1c,in_ECX + 0x20);
    FUN_0046c010();
  } while( true );
}


// ==== FUN_0046c230 @ 0x0046c230 ====

bool FUN_0046c230(void)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_38 [4];
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *puStack_1c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_8 = 0;
  iVar1 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
  puStack_1c = &local_8;
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar1) / 0x1c) <= *(uint *)(in_ECX + 0x30))) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  local_4 = auStack_38;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401660(iVar1 + *(uint *)(in_ECX + 0x30) * 0x1c,0,0xffffffff);
  FUN_0046b4f0();
  iVar1 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
  puStack_1c = &local_8;
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar1) / 0x1c) <= *(uint *)(in_ECX + 0x30))) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  local_4 = auStack_38;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401660(iVar1 + *(uint *)(in_ECX + 0x30) * 0x1c,0,0xffffffff);
  iVar1 = FUN_0046bcd0();
  return iVar1 != 0;
}


// ==== FUN_0046c330 @ 0x0046c330 ====

void FUN_0046c330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a15e8;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[7] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[1] = 0xffffffff;
  return;
}


// ==== FUN_0046c390 @ 0x0046c390 ====

void FUN_0046c390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a15e8;
  if (in_ECX[9] == 0) {
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    FUN_0046cfc0();
    *in_ECX = &PTR_FUN_009a15d8;
    return;
  }
  FUN_00405de0(in_ECX[9],in_ECX[10],in_ECX + 8);
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_0046c3f0 @ 0x0046c3f0 ====

/* WARNING: Removing unreachable block (ram,0x0046c45d) */

int FUN_0046c3f0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  void **ppvVar3;
  int iVar4;
  undefined4 *puVar5;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  int local_28;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d2ae;
  local_c = ExceptionList;
  local_28 = -1;
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  iVar7 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
  iVar1 = *(int *)(*(int *)(in_ECX + 0x34) + 8);
  local_4 = 1;
  ExceptionList = &local_c;
  ppvVar3 = &local_c;
  if (iVar7 != iVar1) {
    do {
      FUN_00405670(iVar7,local_1c);
      uVar2 = *(uint *)((int)local_18 + 0x14);
      if (uVar2 != 0) {
        uVar6 = uVar2;
        if (4 < uVar2) {
          uVar6 = 5;
        }
        if (*(uint *)((int)local_18 + 0x18) < 0x10) {
          pbVar8 = (byte *)((int)local_18 + 4);
        }
        else {
          pbVar8 = *(byte **)((int)local_18 + 4);
        }
        bVar10 = false;
        iVar4 = 0;
        bVar11 = true;
        pbVar9 = (byte *)s_label_009a153c;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar10 = *pbVar8 < *pbVar9;
          bVar11 = *pbVar8 == *pbVar9;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        if (((iVar4 == 0) && (4 < uVar2)) && (uVar2 == 5)) {
          puVar5 = param_2;
          if (in_stack_0000001c < 0x10) {
            puVar5 = &param_2;
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x30),puVar5,in_stack_00000018);
          if (iVar4 == 0) {
            local_28 = (iVar7 - *(int *)(*(int *)(in_ECX + 0x34) + 4)) / 0x1c;
            break;
          }
        }
      }
      iVar7 = iVar7 + 0x1c;
    } while (iVar7 != iVar1);
    ppvVar3 = ExceptionList;
    if (local_18 != (void *)0x0) {
      FUN_00405de0(local_18,local_14,local_1c,param_1);
      _free(local_18);
      return extraout_EAX;
    }
  }
  ExceptionList = ppvVar3;
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return local_28;
  }
  _free(param_2);
  return extraout_EAX_00;
}


// ==== FUN_0046c560 @ 0x0046c560 ====

/* WARNING: Removing unreachable block (ram,0x0046c6ed) */
/* WARNING: Removing unreachable block (ram,0x0046c777) */
/* WARNING: Removing unreachable block (ram,0x0046c7c7) */

void FUN_0046c560(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  undefined1 auStack_38 [4];
  undefined1 local_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  char *local_20;
  undefined1 **ppuStack_1c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0;
  iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
  ppuStack_1c = (undefined1 **)&local_4;
  if ((iVar4 == 0) ||
     ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30))) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  local_8 = auStack_38;
  local_20 = (char *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401660(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c,0,0xffffffff);
  FUN_0046b4f0();
  iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
  ppuStack_1c = (undefined1 **)&local_4;
  if ((iVar4 == 0) ||
     ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30))) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  local_8 = auStack_38;
  local_20 = (char *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401660(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c,0,0xffffffff);
  local_8 = (undefined1 *)FUN_0046bcd0();
  ppuStack_1c = &local_8;
  local_20 = (char *)0x46c65a;
  FUN_0046d1f0();
  uVar1 = (*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x14)) - 1;
  uVar2 = uVar1 >> 2;
  iVar4 = uVar2 * -4;
  if (*(uint *)(in_ECX + 0x10) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(in_ECX + 0x10);
  }
  if (*(int *)(*(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4) + (uVar1 + iVar4) * 4) != 0) {
    return;
  }
  *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
  local_8 = (undefined1 *)0x0;
  iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
  if ((iVar4 == 0) ||
     ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30))) {
LAB_0046c6bc:
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  local_20 = (char *)(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c);
  do {
    ppuStack_1c = (undefined1 **)(in_ECX + 0x20);
    local_24 = 0x46c6d9;
    FUN_00405670();
    ppuStack_1c = (undefined1 **)0x46c6e3;
    FUN_0046c010();
    iVar4 = *(int *)(in_ECX + 0x24);
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (uVar1 == 0) {
LAB_0046c731:
      local_24 = *(undefined4 *)(iVar4 + 0x14);
      ppuStack_1c = (undefined1 **)0x6;
      local_20 = s_elseif_009a1560;
      uStack_28 = 0;
      uStack_2c = 0x46c745;
      iVar4 = FUN_00403620();
      if (iVar4 == 0) goto LAB_0046c762;
      local_24 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14);
      ppuStack_1c = (undefined1 **)0x5;
      local_20 = s_endif_009a1568;
      uStack_28 = 0;
      uStack_2c = 0x46c75e;
      iVar4 = FUN_00403620();
      if (iVar4 == 0) goto LAB_0046c762;
    }
    else {
      uVar2 = uVar1;
      if (3 < uVar1) {
        uVar2 = 4;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      pbVar6 = &DAT_009a1558;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar3 != 0) || (uVar1 < 4)) || (uVar1 != 4)) goto LAB_0046c731;
LAB_0046c762:
      if ((int)local_8 < 1) {
        *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + -1;
        return;
      }
    }
    iVar4 = *(int *)(in_ECX + 0x24);
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (uVar1 != 0) {
      uVar2 = uVar1;
      if (1 < uVar1) {
        uVar2 = 2;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      pbVar6 = &DAT_009a1570;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar3 == 0) && (1 < uVar1)) && (uVar1 == 2)) {
        local_8 = local_8 + 1;
      }
    }
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (uVar1 != 0) {
      uVar2 = uVar1;
      if (4 < uVar1) {
        uVar2 = 5;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar7 = false;
      iVar4 = 0;
      bVar8 = true;
      pbVar6 = (byte *)s_endif_009a1574;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar4 == 0) && (4 < uVar1)) && (uVar1 == 5)) {
        local_8 = local_8 + -1;
      }
    }
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
    if ((iVar4 == 0) ||
       ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30)))
    goto LAB_0046c6bc;
    local_20 = (char *)(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c);
  } while( true );
}


// ==== FUN_0046c870 @ 0x0046c870 ====

/* WARNING: Removing unreachable block (ram,0x0046c8bd) */
/* WARNING: Removing unreachable block (ram,0x0046c912) */
/* WARNING: Removing unreachable block (ram,0x0046c962) */

void FUN_0046c870(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  undefined1 auStack_38 [4];
  undefined1 local_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  char *local_20;
  undefined1 **ppuStack_1c;
  undefined1 *local_8;
  undefined4 local_4;
  
  uVar1 = (*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x14)) - 1;
  uVar2 = uVar1 >> 2;
  iVar4 = uVar2 * -4;
  if (*(uint *)(in_ECX + 0x10) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(in_ECX + 0x10);
  }
  if (*(int *)(*(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4) + (uVar1 + iVar4) * 4) == 0) {
    local_8 = *(undefined1 **)(in_ECX + 0x34);
    ppuStack_1c = (undefined1 **)&local_4;
    local_4 = 0;
    iVar4 = *(int *)(local_8 + 4);
    if ((iVar4 == 0) || ((uint)((*(int *)(local_8 + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30))
       ) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    local_8 = auStack_38;
    local_20 = (char *)0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401660(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c,0,0xffffffff);
    FUN_0046b4f0();
    if ((*(int *)(in_ECX + 0x18) != 0) &&
       (iVar4 = *(int *)(in_ECX + 0x18) + -1, *(int *)(in_ECX + 0x18) = iVar4, iVar4 == 0)) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
    local_8 = *(undefined1 **)(in_ECX + 0x34);
    iVar4 = *(int *)(local_8 + 4);
    ppuStack_1c = (undefined1 **)&local_4;
    if ((iVar4 == 0) || ((uint)((*(int *)(local_8 + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30))
       ) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    local_8 = auStack_38;
    local_20 = (char *)0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401660(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c,0,0xffffffff);
    local_8 = (undefined1 *)FUN_0046bcd0();
    ppuStack_1c = &local_8;
    local_20 = (char *)0x46cb1b;
    FUN_0046d1f0();
    uVar1 = (*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x14)) - 1;
    uVar2 = uVar1 >> 2;
    iVar4 = uVar2 * -4;
    if (*(uint *)(in_ECX + 0x10) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(in_ECX + 0x10);
    }
    if (*(int *)(*(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4) + (uVar1 + iVar4) * 4) != 0) {
      return;
    }
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    local_20 = *(char **)(in_ECX + 0x30);
    ppuStack_1c = (undefined1 **)(in_ECX + 0x20);
    local_24 = 0x46cb63;
    local_20 = (char *)FUN_00405d30();
    local_24 = 0x46cb69;
    FUN_00405670();
    ppuStack_1c = (undefined1 **)0x46cb73;
    FUN_0046c010();
    local_8 = (undefined1 *)0x0;
    do {
      local_24 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14);
      ppuStack_1c = (undefined1 **)0x4;
      local_20 = &DAT_009a15a4;
      uStack_28 = 0;
      uStack_2c = 0x46cb8c;
      iVar4 = FUN_00403620();
      if (iVar4 == 0) {
LAB_0046cbc2:
        if ((int)local_8 < 1) {
          *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + -1;
          return;
        }
      }
      else {
        local_24 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14);
        ppuStack_1c = (undefined1 **)0x6;
        local_20 = s_elseif_009a15ac;
        uStack_28 = 0;
        uStack_2c = 0x46cba5;
        iVar4 = FUN_00403620();
        if (iVar4 == 0) goto LAB_0046cbc2;
        local_24 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14);
        ppuStack_1c = (undefined1 **)0x5;
        local_20 = s_endif_009a15b4;
        uStack_28 = 0;
        uStack_2c = 0x46cbbe;
        iVar4 = FUN_00403620();
        if (iVar4 == 0) goto LAB_0046cbc2;
      }
      local_24 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14);
      ppuStack_1c = (undefined1 **)0x2;
      local_20 = &DAT_009a15bc;
      uStack_28 = 0;
      uStack_2c = 0x46cbe2;
      iVar4 = FUN_00403620();
      if (iVar4 == 0) {
        local_8 = local_8 + 1;
      }
      local_24 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14);
      ppuStack_1c = (undefined1 **)0x5;
      local_20 = s_endif_009a15c0;
      uStack_28 = 0;
      uStack_2c = 0x46cbff;
      iVar4 = FUN_00403620();
      if (iVar4 == 0) {
        local_8 = local_8 + -1;
      }
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
      iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
      if ((iVar4 == 0) ||
         ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30)
         )) goto LAB_0046cc5f;
      ppuStack_1c = (undefined1 **)(in_ECX + 0x20);
      local_20 = (char *)(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c);
      local_24 = 0x46cc49;
      FUN_00405670();
      ppuStack_1c = (undefined1 **)0x46cc53;
      FUN_0046c010();
    } while( true );
  }
  local_8 = (undefined1 *)0x0;
  do {
    iVar4 = *(int *)(in_ECX + 0x24);
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (uVar1 != 0) {
      uVar2 = uVar1;
      if (4 < uVar1) {
        uVar2 = 5;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      pbVar6 = (byte *)s_endif_009a1590;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if ((((iVar3 == 0) && (4 < uVar1)) && (uVar1 == 5)) && ((int)local_8 < 1)) {
        *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
        return;
      }
    }
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (uVar1 != 0) {
      uVar2 = uVar1;
      if (1 < uVar1) {
        uVar2 = 2;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      pbVar6 = &DAT_009a1598;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar3 == 0) && (1 < uVar1)) && (uVar1 == 2)) {
        local_8 = local_8 + 1;
      }
    }
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (uVar1 != 0) {
      uVar2 = uVar1;
      if (4 < uVar1) {
        uVar2 = 5;
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        pbVar5 = (byte *)(iVar4 + 4);
      }
      else {
        pbVar5 = *(byte **)(iVar4 + 4);
      }
      bVar7 = false;
      iVar4 = 0;
      bVar8 = true;
      pbVar6 = (byte *)s_endif_009a159c;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar4 == 0) && (4 < uVar1)) && (uVar1 == 5)) {
        local_8 = local_8 + -1;
      }
    }
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
    if ((iVar4 == 0) ||
       ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar4) / 0x1c) <= *(uint *)(in_ECX + 0x30)))
    {
LAB_0046cc5f:
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    ppuStack_1c = (undefined1 **)(in_ECX + 0x20);
    local_20 = (char *)(iVar4 + *(uint *)(in_ECX + 0x30) * 0x1c);
    local_24 = 0x46c9f6;
    FUN_00405670();
    ppuStack_1c = (undefined1 **)0x46ca00;
    FUN_0046c010();
  } while( true );
}


// ==== FUN_0046cc70 @ 0x0046cc70 ====

void FUN_0046cc70(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00401660(*(int *)(in_ECX + 0x24) + 0x1c,0,0xffffffff);
  iVar2 = FUN_0046c3f0();
  if (iVar2 != -1) {
    iVar1 = *(int *)(in_ECX + 0x18);
    *(int *)(in_ECX + 0x30) = iVar2;
    while (iVar1 != 0) {
      if ((*(int *)(in_ECX + 0x18) != 0) &&
         (iVar2 = *(int *)(in_ECX + 0x18) + -1, *(int *)(in_ECX + 0x18) = iVar2, iVar2 == 0)) {
        *(undefined4 *)(in_ECX + 0x14) = 0;
      }
      iVar1 = *(int *)(in_ECX + 0x18);
    }
  }
  return;
}


// ==== FUN_0046ccd0 @ 0x0046ccd0 ====

void FUN_0046ccd0(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_c = 0;
  local_4 = 0;
  if ((*(int *)(param_2 + 4) == 0) || ((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c == 0))
  {
    *param_1 = 0;
    param_1[1] = 1;
    param_1[2] = 0;
    return;
  }
  local_8 = 2;
  *(int *)(in_ECX + 0x34) = param_2;
LAB_0046cd40:
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
          if ((iVar2 == 0) ||
             ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar2) / 0x1c) <=
              *(uint *)(in_ECX + 0x30))) goto LAB_0046cf9a;
          if (*(int *)(in_ECX + 0x24) != 0) {
            FUN_00405de0(*(int *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x20,
                         param_1);
            _free(*(void **)(in_ECX + 0x24));
            return;
          }
          *(undefined4 *)(in_ECX + 0x24) = 0;
          *(undefined4 *)(in_ECX + 0x28) = 0;
          *(undefined4 *)(in_ECX + 0x2c) = 0;
          iVar2 = *(int *)(*(int *)(in_ECX + 0x34) + 4);
          if ((iVar2 == 0) ||
             ((uint)((*(int *)(*(int *)(in_ECX + 0x34) + 8) - iVar2) / 0x1c) <=
              *(uint *)(in_ECX + 0x30))) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          FUN_00405670(iVar2 + *(uint *)(in_ECX + 0x30) * 0x1c,in_ECX + 0x20);
          if ((*(int *)(in_ECX + 0x24) != 0) &&
             ((*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24)) / 0x1c != 0)) break;
          *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
        }
        iVar2 = FUN_00403620(0,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14),&DAT_009a1500,2);
        if (iVar2 != 0) break;
        FUN_0046c560();
        *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14),&DAT_009a1504,4);
      if (iVar2 != 0) break;
      FUN_0046c090();
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14),s_elseif_009a150c,6);
    if (iVar2 != 0) break;
    FUN_0046c870();
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14),s_endif_009a1514,5);
  if (iVar2 == 0) {
    if ((*(int *)(in_ECX + 0x18) != 0) &&
       (iVar2 = *(int *)(in_ECX + 0x18) + -1, *(int *)(in_ECX + 0x18) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
      goto LAB_0046cd40;
    }
  }
  else {
    cVar1 = FUN_004036a0(*(undefined4 *)(in_ECX + 0x24),&DAT_009a151c);
    if (cVar1 != '\0') {
      FUN_0046cc70();
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
      goto LAB_0046cd40;
    }
    cVar1 = FUN_004036a0(*(undefined4 *)(in_ECX + 0x24),s_label_009a1524);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(*(undefined4 *)(in_ECX + 0x24),s_block_009a152c);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(*(undefined4 *)(in_ECX + 0x24),&DAT_009a1534);
        if (cVar1 != '\0') {
          iVar2 = FUN_0046c230();
          if (iVar2 != 0) goto LAB_0046cf45;
          local_4 = *(int *)(in_ECX + 0x30);
          local_c = 0;
          local_8 = 3;
          goto LAB_0046cf9a;
        }
        local_8 = 4;
      }
      else {
        local_c = FUN_0046b450();
        local_8 = 6;
      }
      local_4 = *(int *)(in_ECX + 0x30);
      *(int *)(in_ECX + 0x30) = local_4 + 1;
LAB_0046cf9a:
      *param_1 = local_c;
      param_1[1] = local_8;
      param_1[2] = local_4;
      return;
    }
  }
LAB_0046cf45:
  *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
  goto LAB_0046cd40;
}


// ==== FUN_0046cfc0 @ 0x0046cfc0 ====

void FUN_0046cfc0(void)

{
  void *_Memory;
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  while (iVar1 != 0) {
    if ((*(int *)(in_ECX + 0x10) != 0) &&
       (iVar1 = *(int *)(in_ECX + 0x10) + -1, *(int *)(in_ECX + 0x10) = iVar1, iVar1 == 0)) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
    iVar1 = *(int *)(in_ECX + 0x10);
  }
  iVar1 = *(int *)(in_ECX + 8);
  while (iVar1 != 0) {
    _Memory = *(void **)(*(int *)(in_ECX + 4) + -4 + iVar1 * 4);
    iVar1 = iVar1 + -1;
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0046d030 @ 0x0046d030 ====

void FUN_0046d030(void)

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
  puStack_8 = &LAB_0097d2c8;
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


// ==== FUN_0046d0a0 @ 0x0046d0a0 ====

void FUN_0046d0a0(uint param_1)

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
    uVar2 = FUN_0046d030();
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
    if (param_1 == 0) goto LAB_0046d1cc;
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
    if (uVar4 == 0) goto LAB_0046d1cc;
    puVar5 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
LAB_0046d1cc:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0046d1f0 @ 0x0046d1f0 ====

void FUN_0046d1f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10) & 3U) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 4U >> 2)) {
    FUN_0046d0a0(1);
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


// ==== FUN_0046d270 @ 0x0046d270 ====

void FUN_0046d270(byte param_1)

{
  void *in_ECX;
  
  FUN_0046c390();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d290 @ 0x0046d290 ====

void FUN_0046d290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a15f8;
  return;
}


// ==== FUN_0046d2a0 @ 0x0046d2a0 ====

void FUN_0046d2a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a15f8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d2c0 @ 0x0046d2c0 ====

void FUN_0046d2c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d364;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00475010();
  }
  local_4 = 0xffffffff;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(0xa0);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004745f0();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00473770();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004734b0();
  }
  local_4 = 0xffffffff;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0x2c);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00473140();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x8c);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004721d0();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046e9d0();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x38);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046e5c0();
  }
  local_4 = 0xffffffff;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046e390();
  }
  local_4 = 0xffffffff;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046e1d0();
  }
  local_4 = 0xffffffff;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(0x24);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046df20();
  }
  local_4 = 0xffffffff;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    *in_ECX = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0046d7c0();
  *in_ECX = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046d520 @ 0x0046d520 ====

void FUN_0046d520(void)

{
  int *in_ECX;
  
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  return;
}


// ==== FUN_0046d5f0 @ 0x0046d5f0 ====

void FUN_0046d5f0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d381;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1600;
  pvVar1 = operator_new(0x30);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0046d2c0();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046d670 @ 0x0046d670 ====

void FUN_0046d670(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_0097d393;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1600;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009a15f8;
    ExceptionList = pvVar1;
    return;
  }
  FUN_0046d520();
  _free(_Memory);
  return;
}


// ==== FUN_0046d6e0 @ 0x0046d6e0 ====

void FUN_0046d6e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0046d670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d700 @ 0x0046d700 ====

void FUN_0046d700(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1608;
  return;
}


// ==== FUN_0046d710 @ 0x0046d710 ====

void FUN_0046d710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1608;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d730 @ 0x0046d730 ====

void FUN_0046d730(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0046d735. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  return;
}


// ==== FUN_0046d740 @ 0x0046d740 ====

bool FUN_0046d740(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x28))(param_1);
  return iVar1 == 0;
}


// ==== FUN_0046d760 @ 0x0046d760 ====

void FUN_0046d760(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d3a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a168c;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5a9ec = 0;
  *in_ECX = &PTR_FUN_009a1608;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046d7c0 @ 0x0046d7c0 ====

void FUN_0046d7c0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d3c5;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a168c;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a9ec = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a9ec = in_ECX;
  }
  pvVar2 = operator_new(0x2028);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0046dbe0();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046d860 @ 0x0046d860 ====

void FUN_0046d860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a161c;
  return;
}


// ==== FUN_0046d870 @ 0x0046d870 ====

void FUN_0046d870(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1674;
  return;
}


// ==== FUN_0046d880 @ 0x0046d880 ====

void FUN_0046d880(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a161c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d8a0 @ 0x0046d8a0 ====

void FUN_0046d8a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1674;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d8c0 @ 0x0046d8c0 ====

void FUN_0046d8c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0046d760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046d8e0 @ 0x0046d8e0 ====

void FUN_0046d8e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a169c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0046d900 @ 0x0046d900 ====

void FUN_0046d900(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d3e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a16a4;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a169c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a1674;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_0046d980 @ 0x0046d980 ====

undefined4 FUN_0046d980(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d3fb;
  local_c = ExceptionList;
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a16b8,0xa9);
      FUN_00797b80(uVar2);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      ExceptionList = local_c;
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x2014);
    *(int *)(in_ECX + 0x200c) = *(int *)(in_ECX + 0x200c) + -1;
    *(int *)(in_ECX + 0x2014) = param_2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0046da30 @ 0x0046da30 ====

void FUN_0046da30(byte param_1)

{
  void *in_ECX;
  
  FUN_0046d8e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046da50 @ 0x0046da50 ====

void FUN_0046da50(byte param_1)

{
  void *in_ECX;
  
  FUN_0046d900();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046da70 @ 0x0046da70 ====

undefined4 * FUN_0046da70(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a16b8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x2014);
  *(int *)(in_ECX + 0x200c) = *(int *)(in_ECX + 0x200c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x2010);
    *(undefined4 **)(in_ECX + 0x2010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_0046db30 @ 0x0046db30 ====

void FUN_0046db30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a16a4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a169c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x802] = 0;
  in_ECX[0x802] = in_ECX[0x802] + 0x100;
  in_ECX[0x805] = in_ECX + 2;
  in_ECX[0x803] = 0;
  in_ECX[0x804] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x7ff] = 0;
  in_ECX[0x800] = 0;
  in_ECX[0x801] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046dbe0 @ 0x0046dbe0 ====

void FUN_0046dbe0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d438;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a174c;
  FUN_0046db30();
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046dc40 @ 0x0046dc40 ====

void FUN_0046dc40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0046dc60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0046dc60 @ 0x0046dc60 ====

void FUN_0046dc60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0046dc60(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0046dc60(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0046dca0 @ 0x0046dca0 ====

uint * FUN_0046dca0(void)

{
  uint *puVar1;
  int in_ECX;
  uint *puVar2;
  uint unaff_EBX;
  uint *puVar3;
  
  puVar1 = (uint *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *puVar1 = unaff_EBX;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar3 = *(uint **)(in_ECX + 4);
  if (*(uint **)(in_ECX + 4) == (uint *)0x0) {
    *(uint **)(in_ECX + 4) = puVar1;
    return (uint *)0x0;
  }
  do {
    if (unaff_EBX < *puVar3) {
      puVar2 = (uint *)puVar3[2];
      if (puVar2 == (uint *)0x0) {
        puVar1[4] = (uint)puVar3;
        puVar3[2] = (uint)puVar1;
        FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
        return (uint *)0x0;
      }
    }
    else {
      if (unaff_EBX <= *puVar3) {
        (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,puVar1);
        return puVar3;
      }
      puVar2 = (uint *)puVar3[3];
      if (puVar2 == (uint *)0x0) {
        puVar1[4] = (uint)puVar3;
        puVar3[3] = (uint)puVar1;
        FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
        return (uint *)0x0;
      }
    }
    puVar3 = puVar2;
  } while( true );
}


// ==== FUN_0046dd40 @ 0x0046dd40 ====

void FUN_0046dd40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0046dd60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0046dd60 @ 0x0046dd60 ====

void FUN_0046dd60(int *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0046dd60(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0046dd60(param_1[3]);
  }
  puVar1 = (undefined4 *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,puVar1);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0046ddd0 @ 0x0046ddd0 ====

uint * FUN_0046ddd0(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int in_ECX;
  uint *puVar3;
  uint *puVar4;
  
  puVar1 = *(uint **)(in_ECX + 4);
  puVar4 = puVar1;
  if (puVar1 == (uint *)0x0) {
    return (uint *)0x0;
  }
  do {
    puVar3 = puVar4;
    if (param_1 < *puVar3) {
      iVar2 = -1;
    }
    else {
      if (param_1 <= *puVar3) {
        FUN_0061f0e0(puVar3,puVar1);
        return puVar3;
      }
      iVar2 = 1;
    }
    if (iVar2 < 0) {
      puVar4 = (uint *)puVar3[2];
    }
    else {
      puVar4 = (uint *)puVar3[3];
    }
  } while (puVar4 != (uint *)0x0);
  FUN_0061f0e0(puVar3,puVar1);
  return (uint *)0x0;
}


// ==== FUN_0046de40 @ 0x0046de40 ====

void FUN_0046de40(byte param_1)

{
  void *in_ECX;
  
  FUN_0046de60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046de60 @ 0x0046de60 ====

void FUN_0046de60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097d463;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a174c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0046dd60(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0046d900();
  *in_ECX = &PTR_FUN_009a161c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046ded0 @ 0x0046ded0 ====

void FUN_0046ded0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17a4;
  return;
}


// ==== FUN_0046dee0 @ 0x0046dee0 ====

void FUN_0046dee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046df00 @ 0x0046df00 ====

void FUN_0046df00(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc + param_1 * 4) + 4))(param_2);
  return;
}


// ==== FUN_0046df20 @ 0x0046df20 ====

void FUN_0046df20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d4c8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a17b0;
  FUN_0046dfe0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9f0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a9f0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046df90 @ 0x0046df90 ====

void FUN_0046df90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d4da;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a17b0;
  local_4 = 0;
  DAT_00b5a9f0 = 0;
  FUN_0046e140();
  *in_ECX = &PTR_FUN_009a17a4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046dfe0 @ 0x0046dfe0 ====

void FUN_0046dfe0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d4b2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00476270();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00475d20();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00475be0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004757d0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00475510();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_004750d0();
  *(undefined4 *)(in_ECX + 0x20) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e140 @ 0x0046e140 ====

void FUN_0046e140(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 0xc);
  iVar2 = 6;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_0046e170 @ 0x0046e170 ====

void FUN_0046e170(byte param_1)

{
  void *in_ECX;
  
  FUN_0046df90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e190 @ 0x0046e190 ====

void FUN_0046e190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17bc;
  return;
}


// ==== FUN_0046e1a0 @ 0x0046e1a0 ====

void FUN_0046e1a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e1c0 @ 0x0046e1c0 ====

void FUN_0046e1c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0046e1c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0046e1d0 @ 0x0046e1d0 ====

void FUN_0046e1d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d518;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a17c8;
  FUN_0046e2a0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9f4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a9f4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e240 @ 0x0046e240 ====

void FUN_0046e240(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d52a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a17c8;
  DAT_00b5a9f4 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009a17bc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e2a0 @ 0x0046e2a0 ====

void FUN_0046e2a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d4fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00476390();
  *(undefined4 *)(in_ECX + 4) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e310 @ 0x0046e310 ====

void FUN_0046e310(byte param_1)

{
  void *in_ECX;
  
  FUN_0046e240();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e330 @ 0x0046e330 ====

void FUN_0046e330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17d4;
  return;
}


// ==== FUN_0046e340 @ 0x0046e340 ====

void FUN_0046e340(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e360 @ 0x0046e360 ====

void FUN_0046e360(void)

{
  FUN_00477180();
  return;
}


// ==== FUN_0046e370 @ 0x0046e370 ====

void FUN_0046e370(void)

{
  FUN_00477590();
  return;
}


// ==== FUN_0046e380 @ 0x0046e380 ====

void FUN_0046e380(void)

{
  FUN_004777d0();
  return;
}


// ==== FUN_0046e390 @ 0x0046e390 ====

void FUN_0046e390(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d578;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a17e8;
  FUN_0046e480();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9f8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a9f8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e400 @ 0x0046e400 ====

void FUN_0046e400(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d58a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a17e8;
  DAT_00b5a9f8 = 0;
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
  *in_ECX = &PTR_FUN_009a17d4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0046e480 @ 0x0046e480 ====

void FUN_0046e480(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d561;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00476680();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00477570();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_004777b0();
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e550 @ 0x0046e550 ====

void FUN_0046e550(byte param_1)

{
  void *in_ECX;
  
  FUN_0046e400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e570 @ 0x0046e570 ====

void FUN_0046e570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17fc;
  return;
}


// ==== FUN_0046e580 @ 0x0046e580 ====

void FUN_0046e580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a17fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e5a0 @ 0x0046e5a0 ====

void FUN_0046e5a0(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4 + *param_1 * 4) + 4))(param_2);
  return;
}


// ==== FUN_0046e5c0 @ 0x0046e5c0 ====

void FUN_0046e5c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d648;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1808;
  FUN_0046e680();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aa00 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa00 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e630 @ 0x0046e630 ====

void FUN_0046e630(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d65a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1808;
  local_4 = 0;
  DAT_00b5aa00 = 0;
  FUN_0046e930();
  *in_ECX = &PTR_FUN_009a17fc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e680 @ 0x0046e680 ====

void FUN_0046e680(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d62f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00479d10();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00479cd0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004799e0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00479760();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00479580();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004794a0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00478bb0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00478980();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x20) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004786f0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00478490();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00478270();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00477d80();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x30) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0xc;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00477ae0();
  *(undefined4 *)(in_ECX + 0x34) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046e930 @ 0x0046e930 ====

void FUN_0046e930(void)

{
  int *in_ECX;
  int iVar1;
  
  iVar1 = 0xd;
  do {
    in_ECX = in_ECX + 1;
    if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*in_ECX)(1);
    }
    *in_ECX = 0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== FUN_0046e960 @ 0x0046e960 ====

void FUN_0046e960(byte param_1)

{
  void *in_ECX;
  
  FUN_0046e630();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e980 @ 0x0046e980 ====

void FUN_0046e980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1814;
  return;
}


// ==== FUN_0046e990 @ 0x0046e990 ====

void FUN_0046e990(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a1814;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046e9b0 @ 0x0046e9b0 ====

void FUN_0046e9b0(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4 + *param_1 * 4) + 4))(param_2);
  return;
}


// ==== FUN_0046e9d0 @ 0x0046e9d0 ====

void FUN_0046e9d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d698;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1820;
  FUN_0046ea90();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aa04 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa04 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046ea40 @ 0x0046ea40 ====

void FUN_0046ea40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d6aa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a1820;
  local_4 = 0;
  DAT_00b5aa04 = 0;
  FUN_0046eb30();
  *in_ECX = &PTR_FUN_009a1814;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046ea90 @ 0x0046ea90 ====

void FUN_0046ea90(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d686;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047a3d0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00479f50();
  *(undefined4 *)(in_ECX + 8) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046eb30 @ 0x0046eb30 ====

void FUN_0046eb30(void)

{
  int *in_ECX;
  int iVar1;
  
  iVar1 = 2;
  do {
    in_ECX = in_ECX + 1;
    if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*in_ECX)(1);
    }
    *in_ECX = 0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== FUN_0046eb60 @ 0x0046eb60 ====

void FUN_0046eb60(byte param_1)

{
  void *in_ECX;
  
  FUN_0046ea40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046eb80 @ 0x0046eb80 ====

void FUN_0046eb80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3724;
  return;
}


// ==== FUN_0046eb90 @ 0x0046eb90 ====

void FUN_0046eb90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3724;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046ebb0 @ 0x0046ebb0 ====

void FUN_0046ebb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3734;
  return;
}


// ==== FUN_0046ebc0 @ 0x0046ebc0 ====

void FUN_0046ebc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a378c;
  return;
}


// ==== FUN_0046ebd0 @ 0x0046ebd0 ====

void FUN_0046ebd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a37a4;
  return;
}


// ==== FUN_0046ebe0 @ 0x0046ebe0 ====

void FUN_0046ebe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3734;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046ec00 @ 0x0046ec00 ====

void FUN_0046ec00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a378c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046ec20 @ 0x0046ec20 ====

void FUN_0046ec20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a37a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0046ec40 @ 0x0046ec40 ====

void FUN_0046ec40(void)

{
  int iVar1;
  int in_ECX;
  
  for (iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 8))(); iVar1 != 0;
      iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x40))(iVar1)) {
  }
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


// ==== FUN_0046ec90 @ 0x0046ec90 ====

void FUN_0046ec90(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc + *param_1 * 4) + 4))(param_2);
  return;
}


// ==== FUN_0046ecb0 @ 0x0046ecb0 ====

void FUN_0046ecb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d828;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a37c4;
  local_4 = 0;
  DAT_00b5aa08 = 0;
  FUN_00472850();
  FUN_0046ec40();
  *in_ECX = &PTR_FUN_009a3724;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0046ed00 @ 0x0046ed00 ====

uint FUN_0046ed00(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  undefined1 local_202 [254];
  undefined1 auStack_104 [260];
  
  FUN_00483b60(param_1);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_202);
  if (piVar1 == (int *)0x0) {
    auStack_104[0] = 0;
    FUN_0044a580(auStack_104,s_Wrong_Option_Code____s_009a182c,param_1);
    FUN_00797b80(auStack_104);
    uVar2 = FUN_0044a580(local_202 + -4,s_File___s__Line___d_009a186c,
                         s___Loader_Article_Facade_Provider_009a1844,0x9d);
    FUN_00797b80(uVar2);
    uVar3 = FUN_00797a40();
    return uVar3 & 0xffff0000;
  }
  return CONCAT22((short)((uint)*piVar1 >> 0x10),*(undefined2 *)(*piVar1 + 0x100));
}


// ==== FUN_0046edb0 @ 0x0046edb0 ====

void FUN_0046edb0(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *****pppppuStack_698;
  char *pcStack_694;
  undefined4 *****pppppuStack_690;
  undefined4 *****pppppuStack_68c;
  char *pcStack_688;
  undefined4 *****pppppuStack_684;
  undefined4 *****pppppuStack_680;
  char *pcStack_67c;
  undefined4 *****pppppuStack_678;
  undefined4 *****pppppuStack_674;
  char *pcStack_670;
  undefined4 *****pppppuStack_66c;
  undefined4 *****pppppuStack_668;
  char *pcStack_664;
  undefined4 *****pppppuStack_660;
  undefined4 *****pppppuStack_65c;
  char *pcStack_658;
  undefined4 *****pppppuStack_654;
  undefined4 *****pppppuStack_650;
  char *pcStack_64c;
  undefined4 *****pppppuStack_648;
  undefined4 *****pppppuStack_644;
  char *pcStack_640;
  undefined4 *****pppppuStack_63c;
  undefined4 *****pppppuStack_638;
  char *pcStack_634;
  undefined4 *****pppppuStack_630;
  undefined4 *****pppppuStack_62c;
  char *pcStack_628;
  undefined4 *****pppppuStack_624;
  undefined4 *****pppppuStack_620;
  char *pcStack_61c;
  undefined4 *****pppppuStack_618;
  undefined4 *****pppppuStack_614;
  char *pcStack_610;
  undefined4 *****pppppuStack_60c;
  undefined4 *****pppppuStack_608;
  char *pcStack_604;
  undefined4 *****pppppuStack_600;
  undefined4 *****pppppuStack_5fc;
  char *pcStack_5f8;
  undefined4 *****pppppuStack_5f4;
  undefined4 *****pppppuStack_5f0;
  char *pcStack_5ec;
  undefined4 *****pppppuStack_5e8;
  undefined4 *****pppppuStack_5e4;
  char *pcStack_5e0;
  undefined4 *****pppppuStack_5dc;
  undefined4 *****pppppuStack_5d8;
  char *pcStack_5d4;
  undefined4 *****pppppuStack_5d0;
  undefined4 *****pppppuStack_5cc;
  char *pcStack_5c8;
  undefined4 *****pppppuStack_5c4;
  undefined4 *****pppppuStack_5c0;
  char *pcStack_5bc;
  undefined4 *****pppppuStack_5b8;
  undefined4 *****pppppuStack_5b4;
  char *pcStack_5b0;
  undefined4 *****pppppuStack_5ac;
  undefined4 *****pppppuStack_5a8;
  char *pcStack_5a4;
  undefined4 *****pppppuStack_5a0;
  undefined4 *****pppppuStack_59c;
  char *pcStack_598;
  undefined4 *****pppppuStack_594;
  undefined4 *****pppppuStack_590;
  char *pcStack_58c;
  undefined4 *****pppppuStack_588;
  undefined4 *****pppppuStack_584;
  char *pcStack_580;
  undefined4 *****pppppuStack_57c;
  undefined4 *****pppppuStack_578;
  char *pcStack_574;
  undefined4 *****pppppuStack_570;
  undefined4 *****pppppuStack_56c;
  char *pcStack_568;
  undefined4 *****pppppuStack_564;
  undefined4 *****pppppuStack_560;
  char *pcStack_55c;
  undefined4 *****pppppuStack_558;
  undefined4 *****pppppuStack_554;
  char *pcStack_550;
  undefined4 *****pppppuStack_54c;
  undefined4 *****pppppuStack_548;
  char *pcStack_544;
  undefined4 *****pppppuStack_540;
  undefined4 *****pppppuStack_53c;
  char *pcStack_538;
  undefined4 *****pppppuStack_534;
  undefined4 *****pppppuStack_530;
  char *pcStack_52c;
  undefined4 *****pppppuStack_528;
  undefined4 *****pppppuStack_524;
  char *pcStack_520;
  undefined4 *****pppppuStack_51c;
  undefined4 *****pppppuStack_518;
  char *pcStack_514;
  undefined4 *****pppppuStack_510;
  undefined4 *****pppppuStack_50c;
  char *pcStack_508;
  undefined4 *****pppppuStack_504;
  undefined4 *****pppppuStack_500;
  char *pcStack_4fc;
  undefined4 *****pppppuStack_4f8;
  undefined4 *****pppppuStack_4f4;
  char *pcStack_4f0;
  undefined4 *****pppppuStack_4ec;
  undefined4 *****pppppuStack_4e8;
  char *pcStack_4e4;
  undefined4 *****pppppuStack_4e0;
  undefined4 *****pppppuStack_4dc;
  char *pcStack_4d8;
  undefined4 *****pppppuStack_4d4;
  undefined4 *****pppppuStack_4d0;
  char *pcStack_4cc;
  undefined4 *****pppppuStack_4c8;
  undefined4 *****pppppuStack_4c4;
  char *pcStack_4c0;
  undefined4 *****pppppuStack_4bc;
  undefined4 *****pppppuStack_4b8;
  char *pcStack_4b4;
  undefined4 *****pppppuStack_4b0;
  undefined4 *****pppppuStack_4ac;
  char *pcStack_4a8;
  undefined4 *****pppppuStack_4a4;
  undefined4 *****pppppuStack_4a0;
  char *pcStack_49c;
  undefined4 *****pppppuStack_498;
  undefined4 *****pppppuStack_494;
  char *pcStack_490;
  undefined4 *****pppppuStack_48c;
  undefined4 *****pppppuStack_488;
  char *pcStack_484;
  undefined4 *****pppppuStack_480;
  undefined4 *****pppppuStack_47c;
  char *pcStack_478;
  undefined4 *****pppppuStack_474;
  undefined4 *****pppppuStack_470;
  char *pcStack_46c;
  undefined4 *****pppppuStack_468;
  undefined4 *****pppppuStack_464;
  char *pcStack_460;
  undefined4 *****pppppuStack_45c;
  undefined4 *****pppppuStack_458;
  char *pcStack_454;
  undefined4 *****pppppuStack_450;
  undefined4 *****pppppuStack_44c;
  char *pcStack_448;
  undefined4 *****pppppuStack_444;
  undefined4 *****pppppuStack_440;
  char *pcStack_43c;
  undefined4 *****pppppuStack_438;
  undefined4 *****pppppuStack_434;
  char *pcStack_430;
  undefined4 *****pppppuStack_42c;
  undefined4 *****pppppuStack_428;
  char *pcStack_424;
  undefined4 *****pppppuStack_420;
  undefined4 *****pppppuStack_41c;
  char *pcStack_418;
  undefined4 *****pppppuStack_414;
  undefined4 *****pppppuStack_410;
  char *pcStack_40c;
  undefined4 *****pppppuStack_408;
  undefined4 *****pppppuStack_404;
  char *pcStack_400;
  undefined4 *****pppppuStack_3fc;
  undefined4 *****pppppuStack_3f8;
  char *pcStack_3f4;
  undefined4 *****pppppuStack_3f0;
  undefined4 *****pppppuStack_3ec;
  char *pcStack_3e8;
  undefined4 *****pppppuStack_3e4;
  undefined4 *****pppppuStack_3e0;
  char *pcStack_3dc;
  undefined4 *****pppppuStack_3d8;
  undefined4 *****pppppuStack_3d4;
  char *pcStack_3d0;
  undefined4 *****pppppuStack_3cc;
  undefined4 *****pppppuStack_3c8;
  char *pcStack_3c4;
  undefined4 *****pppppuStack_3c0;
  undefined4 *****pppppuStack_3bc;
  char *pcStack_3b8;
  undefined4 *****pppppuStack_3b4;
  undefined4 *****pppppuStack_3b0;
  char *pcStack_3ac;
  undefined4 *****pppppuStack_3a8;
  undefined4 *****pppppuStack_3a4;
  char *pcStack_3a0;
  undefined4 *****pppppuStack_39c;
  undefined4 *****pppppuStack_398;
  char *pcStack_394;
  undefined4 *****pppppuStack_390;
  undefined4 *****pppppuStack_38c;
  char *pcStack_388;
  undefined4 *****pppppuStack_384;
  undefined4 *****pppppuStack_380;
  char *pcStack_37c;
  undefined4 *****pppppuStack_378;
  undefined4 *****pppppuStack_374;
  char *pcStack_370;
  undefined4 *****pppppuStack_36c;
  undefined4 *****pppppuStack_368;
  char *pcStack_364;
  undefined4 *****pppppuStack_360;
  undefined4 *****pppppuStack_35c;
  char *pcStack_358;
  undefined4 *****pppppuStack_354;
  undefined4 *****pppppuStack_350;
  char *pcStack_34c;
  undefined4 *****pppppuStack_348;
  undefined4 *****pppppuStack_344;
  char *pcStack_340;
  undefined4 *****pppppuStack_33c;
  undefined4 *****pppppuStack_338;
  char *pcStack_334;
  undefined4 *****pppppuStack_330;
  undefined4 *****pppppuStack_32c;
  char *pcStack_328;
  undefined4 *****pppppuStack_324;
  undefined4 *****pppppuStack_320;
  char *pcStack_31c;
  undefined4 *****pppppuStack_318;
  undefined4 *****pppppuStack_314;
  char *pcStack_310;
  undefined4 *****pppppuStack_30c;
  undefined4 *****pppppuStack_308;
  char *pcStack_304;
  undefined4 *****pppppuStack_300;
  undefined4 *****pppppuStack_2fc;
  char *pcStack_2f8;
  undefined4 *****pppppuStack_2f4;
  undefined4 *****pppppuStack_2f0;
  char *pcStack_2ec;
  undefined4 *****pppppuStack_2e8;
  undefined4 *****pppppuStack_2e4;
  char *pcStack_2e0;
  undefined4 *****pppppuStack_2dc;
  undefined4 *****pppppuStack_2d8;
  char *pcStack_2d4;
  undefined4 *****pppppuStack_2d0;
  undefined4 *****pppppuStack_2cc;
  char *pcStack_2c8;
  undefined4 *****pppppuStack_2c4;
  undefined4 *****pppppuStack_2c0;
  char *pcStack_2bc;
  uint ****ppppuStack_2b8;
  char ****ppppcStack_2b4;
  char *pcStack_2b0;
  uint ****ppppuStack_2ac;
  char ****ppppcStack_2a8;
  char *pcStack_2a4;
  undefined4 ****ppppuStack_2a0;
  char ****ppppcStack_29c;
  char *pcStack_298;
  undefined ****ppppuStack_294;
  char ****ppppcStack_290;
  char *pcStack_28c;
  undefined ****ppppuStack_288;
  undefined4 ***pppuStack_284;
  char *pcStack_280;
  char ***pppcStack_27c;
  undefined ***pppuStack_278;
  char *pcStack_274;
  char ***pppcStack_270;
  undefined ***pppuStack_26c;
  char *pcStack_268;
  undefined4 **ppuStack_264;
  char **ppcStack_260;
  char *pcStack_25c;
  undefined **ppuStack_258;
  char **ppcStack_254;
  char *pcStack_250;
  undefined **ppuStack_24c;
  undefined4 *puStack_248;
  char *pcStack_244;
  char *pcStack_240;
  undefined *puStack_23c;
  char *pcStack_238;
  char *pcStack_234;
  undefined *puStack_230;
  char *pcStack_22c;
  undefined4 uStack_228;
  char acStack_20e [514];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d84e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar2 = operator_new(0x11018);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004728c0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = uVar3;
  uStack_228 = 0x46ee14;
  pvVar2 = operator_new(0x2028);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uStack_228 = 0x46ee38;
    uVar3 = FUN_00472e90();
  }
  *(undefined4 *)(in_ECX + 8) = uVar3;
  uStack_228 = 1;
  local_4 = 0xffffffff;
  pcStack_22c = (char *)0x46ee51;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_22c = &DAT_009a1880;
  pcStack_234 = acStack_20e + -10;
  puStack_230 = &DAT_009a371c;
  pcStack_238 = (char *)0x46ee67;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-10 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046ee8d;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046ee8d:
  pcVar4[0x100] = '\0';
  pcVar4[0x101] = '\0';
  puStack_230 = (undefined *)0x46ee9d;
  pcStack_22c = pcVar4;
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  puStack_230 = (undefined *)0x0;
  pcStack_234 = (char *)0x1;
  pcStack_238 = (char *)0x46eea8;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_238 = s_STAT_STR_ADD_009a1888;
  pcStack_240 = acStack_20e + -0x16;
  puStack_23c = &DAT_009a371c;
  pcStack_244 = (char *)0x46eebe;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x16 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046eee9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046eee9:
  pcVar4[0x100] = '\x01';
  pcVar4[0x101] = '\0';
  puStack_23c = (undefined *)0x46eefb;
  pcStack_238 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    puStack_23c = (undefined *)0xc3;
    pcStack_240 = s___Loader_Article_Facade_Provider_009a1898;
    puStack_248 = &uStack_228;
    pcStack_244 = s_File___s__Line___d_009a18c0;
    uStack_228 = uStack_228 & 0xffffff00;
    ppuStack_24c = (undefined **)0x46ef1c;
    ppuStack_24c = (undefined **)FUN_0044a580();
    pcStack_250 = (char *)0x46ef22;
    FUN_00797b80();
    puStack_23c = (undefined *)0x46ef2a;
    FUN_00797a40();
  }
  puStack_23c = (undefined *)0x0;
  pcStack_240 = (char *)0x1;
  pcStack_244 = (char *)0x46ef35;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_244 = s_STAT_DEX_ADD_009a18d4;
  ppuStack_24c = &puStack_230;
  puStack_248 = (undefined4 *)&DAT_009a371c;
  pcStack_250 = (char *)0x46ef4b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&puStack_230 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046ef71;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046ef71:
  pcVar4[0x100] = '\x02';
  pcVar4[0x101] = '\0';
  puStack_248 = (undefined4 *)0x46ef83;
  pcStack_244 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    puStack_248 = (undefined4 *)0xc4;
    ppuStack_24c = (undefined **)s___Loader_Article_Facade_Provider_009a18e4;
    ppcStack_254 = &pcStack_234;
    pcStack_250 = s_File___s__Line___d_009a190c;
    pcStack_234 = (char *)((uint)pcStack_234 & 0xffffff00);
    ppuStack_258 = (undefined **)0x46efa4;
    ppuStack_258 = (undefined **)FUN_0044a580();
    pcStack_25c = (char *)0x46efaa;
    FUN_00797b80();
    puStack_248 = (undefined4 *)0x46efb2;
    FUN_00797a40();
  }
  puStack_248 = (undefined4 *)0x0;
  ppuStack_24c = (undefined **)0x1;
  pcStack_250 = (char *)0x46efbd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_250 = s_STAT_CON_ADD_009a1920;
  ppuStack_258 = &puStack_23c;
  ppcStack_254 = (char **)&DAT_009a371c;
  pcStack_25c = (char *)0x46efd3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&puStack_23c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046eff9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046eff9:
  pcVar4[0x100] = '\x03';
  pcVar4[0x101] = '\0';
  ppcStack_254 = (char **)0x46f00b;
  pcStack_250 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    ppcStack_254 = (char **)0xc5;
    ppuStack_258 = (undefined **)s___Loader_Article_Facade_Provider_009a1930;
    ppcStack_260 = &pcStack_240;
    pcStack_25c = s_File___s__Line___d_009a1958;
    pcStack_240 = (char *)((uint)pcStack_240 & 0xffffff00);
    ppuStack_264 = (undefined4 **)0x46f02c;
    ppuStack_264 = (undefined4 **)FUN_0044a580();
    pcStack_268 = (char *)0x46f032;
    FUN_00797b80();
    ppcStack_254 = (char **)0x46f03a;
    FUN_00797a40();
  }
  ppcStack_254 = (char **)0x0;
  ppuStack_258 = (undefined **)0x1;
  pcStack_25c = (char *)0x46f045;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_25c = s_STAT_SPR_ADD_009a196c;
  ppuStack_264 = &puStack_248;
  ppcStack_260 = (char **)&DAT_009a371c;
  pcStack_268 = (char *)0x46f05b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x3a - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f081;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f081:
  pcVar4[0x100] = '\x04';
  pcVar4[0x101] = '\0';
  ppcStack_260 = (char **)0x46f093;
  pcStack_25c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    ppcStack_260 = (char **)0xc6;
    ppuStack_264 = (undefined4 **)s___Loader_Article_Facade_Provider_009a197c;
    pppuStack_26c = &ppuStack_24c;
    pcStack_268 = s_File___s__Line___d_009a19a4;
    ppuStack_24c = (undefined **)((uint)ppuStack_24c & 0xffffff00);
    pppcStack_270 = (char ***)0x46f0b4;
    pppcStack_270 = (char ***)FUN_0044a580();
    pcStack_274 = (char *)0x46f0ba;
    FUN_00797b80();
    ppcStack_260 = (char **)0x46f0c2;
    FUN_00797a40();
  }
  ppcStack_260 = (char **)0x0;
  ppuStack_264 = (undefined4 **)0x1;
  pcStack_268 = (char *)0x46f0cd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_268 = s_HP_MAX_ADD_009a19b8;
  pppcStack_270 = &ppcStack_254;
  pppuStack_26c = (undefined ***)&DAT_009a371c;
  pcStack_274 = (char *)0x46f0e3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x46 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f109;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f109:
  pcVar4[0x100] = '\b';
  pcVar4[0x101] = '\0';
  pppuStack_26c = (undefined ***)0x46f11b;
  pcStack_268 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppuStack_26c = (undefined ***)0xc8;
    pppcStack_270 = (char ***)s___Loader_Article_Facade_Provider_009a19c4;
    pppuStack_278 = &ppuStack_258;
    pcStack_274 = s_File___s__Line___d_009a19ec;
    ppuStack_258 = (undefined **)((uint)ppuStack_258 & 0xffffff00);
    pppcStack_27c = (char ***)0x46f13c;
    pppcStack_27c = (char ***)FUN_0044a580();
    pcStack_280 = (char *)0x46f142;
    FUN_00797b80();
    pppuStack_26c = (undefined ***)0x46f14a;
    FUN_00797a40();
  }
  pppuStack_26c = (undefined ***)0x0;
  pppcStack_270 = (char ***)0x1;
  pcStack_274 = "h";
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_274 = s_HP_MAX_MUL_009a1a00;
  pppcStack_27c = &ppcStack_260;
  pppuStack_278 = (undefined ***)&DAT_009a371c;
  pcStack_280 = (char *)0x46f16b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x52 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f191;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f191:
  pcVar4[0x100] = '\t';
  pcVar4[0x101] = '\0';
  pppuStack_278 = (undefined ***)0x46f1a3;
  pcStack_274 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppuStack_278 = (undefined ***)0xc9;
    pppcStack_27c = (char ***)s___Loader_Article_Facade_Provider_009a1a0c;
    pppuStack_284 = &ppuStack_264;
    pcStack_280 = s_File___s__Line___d_009a1a34;
    ppuStack_264 = (undefined4 **)((uint)ppuStack_264 & 0xffffff00);
    ppppuStack_288 = (undefined ****)0x46f1c4;
    ppppuStack_288 = (undefined ****)FUN_0044a580();
    pcStack_28c = (char *)0x46f1ca;
    FUN_00797b80();
    pppuStack_278 = (undefined ***)0x46f1d2;
    FUN_00797a40();
  }
  pppuStack_278 = (undefined ***)0x0;
  pppcStack_27c = (char ***)0x1;
  pcStack_280 = (char *)0x46f1dd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_280 = s_HP_RECOVERY_ADD_009a1a48;
  ppppuStack_288 = &pppuStack_26c;
  pppuStack_284 = (undefined4 ***)&DAT_009a371c;
  pcStack_28c = (char *)0x46f1f3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x5e - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f219;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f219:
  pcVar4[0x100] = '\n';
  pcVar4[0x101] = '\0';
  pppuStack_284 = (undefined4 ***)0x46f22b;
  pcStack_280 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppuStack_284 = (undefined4 ***)0xca;
    ppppuStack_288 = (undefined ****)s___Loader_Article_Facade_Provider_009a1a58;
    ppppcStack_290 = &pppcStack_270;
    pcStack_28c = s_File___s__Line___d_009a1a80;
    pppcStack_270 = (char ***)((uint)pppcStack_270 & 0xffffff00);
    ppppuStack_294 = (undefined ****)0x46f24c;
    ppppuStack_294 = (undefined ****)FUN_0044a580();
    pcStack_298 = (char *)0x46f252;
    FUN_00797b80();
    pppuStack_284 = (undefined4 ***)0x46f25a;
    FUN_00797a40();
  }
  pppuStack_284 = (undefined4 ***)0x0;
  ppppuStack_288 = (undefined ****)0x1;
  pcStack_28c = (char *)0x46f265;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_28c = s_HP_RECOVERYRATE_MUL_009a1a94;
  ppppuStack_294 = &pppuStack_278;
  ppppcStack_290 = (char ****)&DAT_009a371c;
  pcStack_298 = (char *)0x46f27b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x6a - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f2a1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f2a1:
  pcVar4[0x100] = '\v';
  pcVar4[0x101] = '\0';
  ppppcStack_290 = (char ****)0x46f2b3;
  pcStack_28c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    ppppcStack_290 = (char ****)0xcb;
    ppppuStack_294 = (undefined ****)s___Loader_Article_Facade_Provider_009a1aa8;
    ppppcStack_29c = &pppcStack_27c;
    pcStack_298 = s_File___s__Line___d_009a1ad0;
    pppcStack_27c = (char ***)((uint)pppcStack_27c & 0xffffff00);
    ppppuStack_2a0 = (undefined4 ****)0x46f2d4;
    ppppuStack_2a0 = (undefined4 ****)FUN_0044a580();
    pcStack_2a4 = (char *)0x46f2da;
    FUN_00797b80();
    ppppcStack_290 = (char ****)0x46f2e2;
    FUN_00797a40();
  }
  ppppcStack_290 = (char ****)0x0;
  ppppuStack_294 = (undefined ****)0x1;
  pcStack_298 = (char *)0x46f2ed;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_298 = s_HP_DECREASE_ADD_009a1ae4;
  ppppuStack_2a0 = &pppuStack_284;
  ppppcStack_29c = (char ****)&DAT_009a371c;
  pcStack_2a4 = (char *)0x46f303;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(acStack_20e + (-0x76 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f329;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f329:
  pcVar4[0x100] = '\f';
  pcVar4[0x101] = '\0';
  ppppcStack_29c = (char ****)0x46f33b;
  pcStack_298 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    ppppcStack_29c = (char ****)0xcc;
    ppppuStack_2a0 = (undefined4 ****)s___Loader_Article_Facade_Provider_009a1af4;
    ppppcStack_2a8 = (char ****)&ppppuStack_288;
    pcStack_2a4 = s_File___s__Line___d_009a1b1c;
    ppppuStack_288 = (undefined ****)((uint)ppppuStack_288 & 0xffffff00);
    ppppuStack_2ac = (undefined4 ****)0x46f35c;
    ppppuStack_2ac = (uint ****)FUN_0044a580();
    pcStack_2b0 = (char *)0x46f362;
    FUN_00797b80();
    ppppcStack_29c = (char ****)0x46f36a;
    FUN_00797a40();
  }
  ppppcStack_29c = (char ****)0x0;
  ppppuStack_2a0 = (undefined4 ****)0x1;
  pcStack_2a4 = (char *)0x46f375;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2a4 = s_HP_DECREASERATE_MUL_009a1b30;
  ppppuStack_2ac = (uint ****)&ppppcStack_290;
  ppppcStack_2a8 = (char ****)&DAT_009a371c;
  pcStack_2b0 = (char *)0x46f38b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&ppppcStack_290 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f3b1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f3b1:
  pcVar4[0x100] = '\r';
  pcVar4[0x101] = '\0';
  ppppcStack_2a8 = (char ****)0x46f3c3;
  pcStack_2a4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    ppppcStack_2a8 = (char ****)0xcd;
    ppppuStack_2ac = (uint ****)s___Loader_Article_Facade_Provider_009a1b44;
    ppppcStack_2b4 = (char ****)&ppppuStack_294;
    pcStack_2b0 = s_File___s__Line___d_009a1b6c;
    ppppuStack_294 = (undefined ****)((uint)ppppuStack_294 & 0xffffff00);
    ppppuStack_2b8 = (undefined4 ****)0x46f3e4;
    ppppuStack_2b8 = (uint ****)FUN_0044a580();
    pcStack_2bc = (char *)0x46f3ea;
    FUN_00797b80();
    ppppcStack_2a8 = (char ****)0x46f3f2;
    FUN_00797a40();
  }
  ppppcStack_2a8 = (char ****)0x0;
  ppppuStack_2ac = (undefined4 ****)0x1;
  pcStack_2b0 = (char *)0x46f3fd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2b0 = s_SHIELD_MAX_MUL_009a1b80;
  ppppuStack_2b8 = (uint ****)&ppppcStack_29c;
  ppppcStack_2b4 = (char ****)&DAT_009a371c;
  pcStack_2bc = (char *)0x46f413;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&ppppcStack_29c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f439;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f439:
  pcVar4[0x100] = 'a';
  pcVar4[0x101] = '\0';
  ppppcStack_2b4 = (char ****)0x46f44b;
  pcStack_2b0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    ppppcStack_2b4 = (char ****)0xcf;
    ppppuStack_2b8 = (uint ****)s___Loader_Article_Facade_Provider_009a1b90;
    pppppuStack_2c0 = &ppppuStack_2a0;
    pcStack_2bc = s_File___s__Line___d_009a1bb8;
    ppppuStack_2a0 = (undefined4 ****)((uint)ppppuStack_2a0 & 0xffffff00);
    pppppuStack_2c4 = (undefined4 *****)0x46f46c;
    pppppuStack_2c4 = (undefined4 *****)FUN_0044a580();
    pcStack_2c8 = (char *)0x46f472;
    FUN_00797b80();
    ppppcStack_2b4 = (char ****)0x46f47a;
    FUN_00797a40();
  }
  ppppcStack_2b4 = (char ****)0x0;
  ppppuStack_2b8 = (undefined4 ****)0x1;
  pcStack_2bc = (char *)0x46f485;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2bc = s_SHIELD_RECOVERYRATE_MUL_009a1bcc;
  pppppuStack_2c4 = (undefined4 *****)&ppppcStack_2a8;
  pppppuStack_2c0 = (undefined4 *****)&DAT_009a371c;
  pcStack_2c8 = (char *)0x46f49b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&ppppcStack_2a8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f4c1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f4c1:
  pcVar4[0x100] = 'c';
  pcVar4[0x101] = '\0';
  pppppuStack_2c0 = (undefined4 *****)0x46f4d3;
  pcStack_2bc = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_2c0 = (undefined4 *****)0xd0;
    pppppuStack_2c4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1be4;
    pppppuStack_2cc = &ppppuStack_2ac;
    pcStack_2c8 = s_File___s__Line___d_009a1c0c;
    ppppuStack_2ac = (uint ****)((uint)ppppuStack_2ac & 0xffffff00);
    pppppuStack_2d0 = (undefined4 *****)0x46f4f4;
    pppppuStack_2d0 = (undefined4 *****)FUN_0044a580();
    pcStack_2d4 = (char *)0x46f4fa;
    FUN_00797b80();
    pppppuStack_2c0 = (undefined4 *****)0x46f502;
    FUN_00797a40();
  }
  pppppuStack_2c0 = (undefined4 *****)0x0;
  pppppuStack_2c4 = (undefined4 *****)0x1;
  pcStack_2c8 = (char *)0x46f50d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2c8 = s_MP_MAX_ADD_009a1c20;
  pppppuStack_2d0 = (undefined4 *****)&ppppcStack_2b4;
  pppppuStack_2cc = (undefined4 *****)&DAT_009a371c;
  pcStack_2d4 = (char *)0x46f523;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&ppppcStack_2b4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f549;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f549:
  pcVar4[0x100] = '\x10';
  pcVar4[0x101] = '\0';
  pppppuStack_2cc = (undefined4 *****)0x46f55b;
  pcStack_2c8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_2cc = (undefined4 *****)0xd2;
    pppppuStack_2d0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1c2c;
    pppppuStack_2d8 = &ppppuStack_2b8;
    pcStack_2d4 = s_File___s__Line___d_009a1c54;
    ppppuStack_2b8 = (uint ****)((uint)ppppuStack_2b8 & 0xffffff00);
    pppppuStack_2dc = (undefined4 *****)0x46f57c;
    pppppuStack_2dc = (undefined4 *****)FUN_0044a580();
    pcStack_2e0 = (char *)0x46f582;
    FUN_00797b80();
    pppppuStack_2cc = (undefined4 *****)0x46f58a;
    FUN_00797a40();
  }
  pppppuStack_2cc = (undefined4 *****)0x0;
  pppppuStack_2d0 = (undefined4 *****)0x1;
  pcStack_2d4 = (char *)0x46f595;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2d4 = s_MP_MAX_MUL_009a1c68;
  pppppuStack_2dc = &pppppuStack_2c0;
  pppppuStack_2d8 = (undefined4 *****)&DAT_009a371c;
  pcStack_2e0 = (char *)0x46f5ab;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2c0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f5d1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f5d1:
  pcVar4[0x100] = '\x11';
  pcVar4[0x101] = '\0';
  pppppuStack_2d8 = (undefined4 *****)0x46f5e3;
  pcStack_2d4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_2d8 = (undefined4 *****)0xd3;
    pppppuStack_2dc = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1c74;
    pppppuStack_2e4 = &pppppuStack_2c4;
    pcStack_2e0 = s_File___s__Line___d_009a1c9c;
    pppppuStack_2c4 = (undefined4 *****)((uint)pppppuStack_2c4 & 0xffffff00);
    pppppuStack_2e8 = (undefined4 *****)0x46f604;
    pppppuStack_2e8 = (undefined4 *****)FUN_0044a580();
    pcStack_2ec = (char *)0x46f60a;
    FUN_00797b80();
    pppppuStack_2d8 = (undefined4 *****)0x46f612;
    FUN_00797a40();
  }
  pppppuStack_2d8 = (undefined4 *****)0x0;
  pppppuStack_2dc = (undefined4 *****)0x1;
  pcStack_2e0 = (char *)0x46f61d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2e0 = s_MP_RECOVERY_ADD_009a1cb0;
  pppppuStack_2e8 = &pppppuStack_2cc;
  pppppuStack_2e4 = (undefined4 *****)&DAT_009a371c;
  pcStack_2ec = (char *)0x46f633;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2cc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f659;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f659:
  pcVar4[0x100] = '\x12';
  pcVar4[0x101] = '\0';
  pppppuStack_2e4 = (undefined4 *****)0x46f66b;
  pcStack_2e0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_2e4 = (undefined4 *****)0xd4;
    pppppuStack_2e8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1cc0;
    pppppuStack_2f0 = &pppppuStack_2d0;
    pcStack_2ec = s_File___s__Line___d_009a1ce8;
    pppppuStack_2d0 = (undefined4 *****)((uint)pppppuStack_2d0 & 0xffffff00);
    pppppuStack_2f4 = (undefined4 *****)0x46f68c;
    pppppuStack_2f4 = (undefined4 *****)FUN_0044a580();
    pcStack_2f8 = (char *)0x46f692;
    FUN_00797b80();
    pppppuStack_2e4 = (undefined4 *****)0x46f69a;
    FUN_00797a40();
  }
  pppppuStack_2e4 = (undefined4 *****)0x0;
  pppppuStack_2e8 = (undefined4 *****)0x1;
  pcStack_2ec = (char *)0x46f6a5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2ec = s_MP_RECOVERYRATE_MUL_009a1cfc;
  pppppuStack_2f4 = &pppppuStack_2d8;
  pppppuStack_2f0 = (undefined4 *****)&DAT_009a371c;
  pcStack_2f8 = (char *)0x46f6bb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2d8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f6e1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f6e1:
  pcVar4[0x100] = '\x13';
  pcVar4[0x101] = '\0';
  pppppuStack_2f0 = (undefined4 *****)0x46f6f3;
  pcStack_2ec = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_2f0 = (undefined4 *****)0xd5;
    pppppuStack_2f4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1d10;
    pppppuStack_2fc = &pppppuStack_2dc;
    pcStack_2f8 = s_File___s__Line___d_009a1d38;
    pppppuStack_2dc = (undefined4 *****)((uint)pppppuStack_2dc & 0xffffff00);
    pppppuStack_300 = (undefined4 *****)0x46f714;
    pppppuStack_300 = (undefined4 *****)FUN_0044a580();
    pcStack_304 = (char *)0x46f71a;
    FUN_00797b80();
    pppppuStack_2f0 = (undefined4 *****)0x46f722;
    FUN_00797a40();
  }
  pppppuStack_2f0 = (undefined4 *****)0x0;
  pppppuStack_2f4 = (undefined4 *****)0x1;
  pcStack_2f8 = (char *)0x46f72d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_2f8 = s_MP_DECREASE_ADD_009a1d4c;
  pppppuStack_300 = &pppppuStack_2e4;
  pppppuStack_2fc = (undefined4 *****)&DAT_009a371c;
  pcStack_304 = (char *)0x46f743;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2e4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f769;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f769:
  pcVar4[0x100] = '\x14';
  pcVar4[0x101] = '\0';
  pppppuStack_2fc = (undefined4 *****)0x46f77b;
  pcStack_2f8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_2fc = (undefined4 *****)0xd6;
    pppppuStack_300 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1d5c;
    pppppuStack_308 = &pppppuStack_2e8;
    pcStack_304 = s_File___s__Line___d_009a1d84;
    pppppuStack_2e8 = (undefined4 *****)((uint)pppppuStack_2e8 & 0xffffff00);
    pppppuStack_30c = (undefined4 *****)0x46f79c;
    pppppuStack_30c = (undefined4 *****)FUN_0044a580();
    pcStack_310 = (char *)0x46f7a2;
    FUN_00797b80();
    pppppuStack_2fc = (undefined4 *****)0x46f7aa;
    FUN_00797a40();
  }
  pppppuStack_2fc = (undefined4 *****)0x0;
  pppppuStack_300 = (undefined4 *****)0x1;
  pcStack_304 = (char *)0x46f7b5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_304 = s_MP_DECREASERATE_MUL_009a1d98;
  pppppuStack_30c = &pppppuStack_2f0;
  pppppuStack_308 = (undefined4 *****)&DAT_009a371c;
  pcStack_310 = (char *)0x46f7cb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2f0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f7f1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f7f1:
  pcVar4[0x100] = '\x15';
  pcVar4[0x101] = '\0';
  pppppuStack_308 = (undefined4 *****)0x46f803;
  pcStack_304 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_308 = (undefined4 *****)0xd7;
    pppppuStack_30c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1dac;
    pppppuStack_314 = &pppppuStack_2f4;
    pcStack_310 = s_File___s__Line___d_009a1dd4;
    pppppuStack_2f4 = (undefined4 *****)((uint)pppppuStack_2f4 & 0xffffff00);
    pppppuStack_318 = (undefined4 *****)0x46f824;
    pppppuStack_318 = (undefined4 *****)FUN_0044a580();
    pcStack_31c = (char *)0x46f82a;
    FUN_00797b80();
    pppppuStack_308 = (undefined4 *****)0x46f832;
    FUN_00797a40();
  }
  pppppuStack_308 = (undefined4 *****)0x0;
  pppppuStack_30c = (undefined4 *****)0x1;
  pcStack_310 = (char *)0x46f83d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_310 = s_RESIST_FIRE_ADD_009a1de8;
  pppppuStack_318 = &pppppuStack_2fc;
  pppppuStack_314 = (undefined4 *****)&DAT_009a371c;
  pcStack_31c = (char *)0x46f853;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_2fc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f879;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f879:
  pcVar4[0x100] = '\x18';
  pcVar4[0x101] = '\0';
  pppppuStack_314 = (undefined4 *****)0x46f88b;
  pcStack_310 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_314 = (undefined4 *****)0xd9;
    pppppuStack_318 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1df8;
    pppppuStack_320 = &pppppuStack_300;
    pcStack_31c = s_File___s__Line___d_009a1e20;
    pppppuStack_300 = (undefined4 *****)((uint)pppppuStack_300 & 0xffffff00);
    pppppuStack_324 = (undefined4 *****)0x46f8ac;
    pppppuStack_324 = (undefined4 *****)FUN_0044a580();
    pcStack_328 = (char *)0x46f8b2;
    FUN_00797b80();
    pppppuStack_314 = (undefined4 *****)0x46f8ba;
    FUN_00797a40();
  }
  pppppuStack_314 = (undefined4 *****)0x0;
  pppppuStack_318 = (undefined4 *****)0x1;
  pcStack_31c = (char *)0x46f8c5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_31c = s_RESIST_ICE_ADD_009a1e34;
  pppppuStack_324 = &pppppuStack_308;
  pppppuStack_320 = (undefined4 *****)&DAT_009a371c;
  pcStack_328 = (char *)0x46f8db;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_308 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f901;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f901:
  pcVar4[0x100] = '\x19';
  pcVar4[0x101] = '\0';
  pppppuStack_320 = (undefined4 *****)0x46f913;
  pcStack_31c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_320 = (undefined4 *****)0xda;
    pppppuStack_324 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1e44;
    pppppuStack_32c = &pppppuStack_30c;
    pcStack_328 = s_File___s__Line___d_009a1e6c;
    pppppuStack_30c = (undefined4 *****)((uint)pppppuStack_30c & 0xffffff00);
    pppppuStack_330 = (undefined4 *****)0x46f934;
    pppppuStack_330 = (undefined4 *****)FUN_0044a580();
    pcStack_334 = (char *)0x46f93a;
    FUN_00797b80();
    pppppuStack_320 = (undefined4 *****)0x46f942;
    FUN_00797a40();
  }
  pppppuStack_320 = (undefined4 *****)0x0;
  pppppuStack_324 = (undefined4 *****)0x1;
  pcStack_328 = (char *)0x46f94d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_328 = s_RESIST_LIGHTNING_ADD_009a1e80;
  pppppuStack_330 = &pppppuStack_314;
  pppppuStack_32c = (undefined4 *****)&DAT_009a371c;
  pcStack_334 = (char *)0x46f963;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_314 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046f989;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046f989:
  pcVar4[0x100] = '\x1a';
  pcVar4[0x101] = '\0';
  pppppuStack_32c = (undefined4 *****)0x46f99b;
  pcStack_328 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_32c = (undefined4 *****)0xdb;
    pppppuStack_330 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1e98;
    pppppuStack_338 = &pppppuStack_318;
    pcStack_334 = s_File___s__Line___d_009a1ec0;
    pppppuStack_318 = (undefined4 *****)((uint)pppppuStack_318 & 0xffffff00);
    pppppuStack_33c = (undefined4 *****)0x46f9bc;
    pppppuStack_33c = (undefined4 *****)FUN_0044a580();
    pcStack_340 = (char *)0x46f9c2;
    FUN_00797b80();
    pppppuStack_32c = (undefined4 *****)0x46f9ca;
    FUN_00797a40();
  }
  pppppuStack_32c = (undefined4 *****)0x0;
  pppppuStack_330 = (undefined4 *****)0x1;
  pcStack_334 = (char *)0x46f9d5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_334 = s_RESIST_POISON_ADD_009a1ed4;
  pppppuStack_33c = &pppppuStack_320;
  pppppuStack_338 = (undefined4 *****)&DAT_009a371c;
  pcStack_340 = (char *)0x46f9eb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_320 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fa11;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fa11:
  pcVar4[0x100] = '\x1b';
  pcVar4[0x101] = '\0';
  pppppuStack_338 = (undefined4 *****)0x46fa23;
  pcStack_334 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_338 = (undefined4 *****)0xdc;
    pppppuStack_33c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1ee8;
    pppppuStack_344 = &pppppuStack_324;
    pcStack_340 = s_File___s__Line___d_009a1f10;
    pppppuStack_324 = (undefined4 *****)((uint)pppppuStack_324 & 0xffffff00);
    pppppuStack_348 = (undefined4 *****)0x46fa44;
    pppppuStack_348 = (undefined4 *****)FUN_0044a580();
    pcStack_34c = (char *)0x46fa4a;
    FUN_00797b80();
    pppppuStack_338 = (undefined4 *****)0x46fa52;
    FUN_00797a40();
  }
  pppppuStack_338 = (undefined4 *****)0x0;
  pppppuStack_33c = (undefined4 *****)0x1;
  pcStack_340 = (char *)0x46fa5d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_340 = s_RESIST_CURSE_ADD_009a1f24;
  pppppuStack_348 = &pppppuStack_32c;
  pppppuStack_344 = (undefined4 *****)&DAT_009a371c;
  pcStack_34c = (char *)0x46fa73;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_32c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fa99;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fa99:
  pcVar4[0x100] = '\x1c';
  pcVar4[0x101] = '\0';
  pppppuStack_344 = (undefined4 *****)0x46faab;
  pcStack_340 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_344 = (undefined4 *****)0xdd;
    pppppuStack_348 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1f38;
    pppppuStack_350 = &pppppuStack_330;
    pcStack_34c = s_File___s__Line___d_009a1f60;
    pppppuStack_330 = (undefined4 *****)((uint)pppppuStack_330 & 0xffffff00);
    pppppuStack_354 = (undefined4 *****)0x46facc;
    pppppuStack_354 = (undefined4 *****)FUN_0044a580();
    pcStack_358 = (char *)0x46fad2;
    FUN_00797b80();
    pppppuStack_344 = (undefined4 *****)0x46fada;
    FUN_00797a40();
  }
  pppppuStack_344 = (undefined4 *****)0x0;
  pppppuStack_348 = (undefined4 *****)0x1;
  pcStack_34c = (char *)0x46fae5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_34c = s_RESIST_ALL_ADD_009a1f74;
  pppppuStack_354 = &pppppuStack_338;
  pppppuStack_350 = (undefined4 *****)&DAT_009a371c;
  pcStack_358 = (char *)0x46fafb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_338 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fb21;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fb21:
  pcVar4[0x100] = '\x1f';
  pcVar4[0x101] = '\0';
  pppppuStack_350 = (undefined4 *****)0x46fb33;
  pcStack_34c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_350 = (undefined4 *****)0xde;
    pppppuStack_354 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1f84;
    pppppuStack_35c = &pppppuStack_33c;
    pcStack_358 = s_File___s__Line___d_009a1fac;
    pppppuStack_33c = (undefined4 *****)((uint)pppppuStack_33c & 0xffffff00);
    pppppuStack_360 = (undefined4 *****)0x46fb54;
    pppppuStack_360 = (undefined4 *****)FUN_0044a580();
    pcStack_364 = (char *)0x46fb5a;
    FUN_00797b80();
    pppppuStack_350 = (undefined4 *****)0x46fb62;
    FUN_00797a40();
  }
  pppppuStack_350 = (undefined4 *****)0x0;
  pppppuStack_354 = (undefined4 *****)0x1;
  pcStack_358 = (char *)0x46fb6d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_358 = s_RESIST_MELEE_ADD_009a1fc0;
  pppppuStack_360 = &pppppuStack_344;
  pppppuStack_35c = (undefined4 *****)&DAT_009a371c;
  pcStack_364 = (char *)0x46fb83;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_344 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fba9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fba9:
  pcVar4[0x100] = '\x1d';
  pcVar4[0x101] = '\0';
  pppppuStack_35c = (undefined4 *****)0x46fbbb;
  pcStack_358 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_35c = (undefined4 *****)0xe0;
    pppppuStack_360 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a1fd4;
    pppppuStack_368 = &pppppuStack_348;
    pcStack_364 = s_File___s__Line___d_009a1ffc;
    pppppuStack_348 = (undefined4 *****)((uint)pppppuStack_348 & 0xffffff00);
    pppppuStack_36c = (undefined4 *****)0x46fbdc;
    pppppuStack_36c = (undefined4 *****)FUN_0044a580();
    pcStack_370 = (char *)0x46fbe2;
    FUN_00797b80();
    pppppuStack_35c = (undefined4 *****)0x46fbea;
    FUN_00797a40();
  }
  pppppuStack_35c = (undefined4 *****)0x0;
  pppppuStack_360 = (undefined4 *****)0x1;
  pcStack_364 = (char *)0x46fbf5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_364 = s_DAMAGE_MINPHYSICAL_ADD_009a2010;
  pppppuStack_36c = &pppppuStack_350;
  pppppuStack_368 = (undefined4 *****)&DAT_009a371c;
  pcStack_370 = (char *)0x46fc0b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_350 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fc31;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fc31:
  pcVar4[0x100] = ' ';
  pcVar4[0x101] = '\0';
  pppppuStack_368 = (undefined4 *****)0x46fc43;
  pcStack_364 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_368 = (undefined4 *****)0xe2;
    pppppuStack_36c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2028;
    pppppuStack_374 = &pppppuStack_354;
    pcStack_370 = s_File___s__Line___d_009a2050;
    pppppuStack_354 = (undefined4 *****)((uint)pppppuStack_354 & 0xffffff00);
    pppppuStack_378 = (undefined4 *****)0x46fc64;
    pppppuStack_378 = (undefined4 *****)FUN_0044a580();
    pcStack_37c = (char *)0x46fc6a;
    FUN_00797b80();
    pppppuStack_368 = (undefined4 *****)0x46fc72;
    FUN_00797a40();
  }
  pppppuStack_368 = (undefined4 *****)0x0;
  pppppuStack_36c = (undefined4 *****)0x1;
  pcStack_370 = (char *)0x46fc7d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_370 = s_DAMAGE_MAXPHYSICAL_ADD_009a2064;
  pppppuStack_378 = &pppppuStack_35c;
  pppppuStack_374 = (undefined4 *****)&DAT_009a371c;
  pcStack_37c = (char *)0x46fc93;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_35c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fcb9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fcb9:
  pcVar4[0x100] = '!';
  pcVar4[0x101] = '\0';
  pppppuStack_374 = (undefined4 *****)0x46fccb;
  pcStack_370 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_374 = (undefined4 *****)0xe3;
    pppppuStack_378 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a207c;
    pppppuStack_380 = &pppppuStack_360;
    pcStack_37c = s_File___s__Line___d_009a20a4;
    pppppuStack_360 = (undefined4 *****)((uint)pppppuStack_360 & 0xffffff00);
    pppppuStack_384 = (undefined4 *****)0x46fcec;
    pppppuStack_384 = (undefined4 *****)FUN_0044a580();
    pcStack_388 = (char *)0x46fcf2;
    FUN_00797b80();
    pppppuStack_374 = (undefined4 *****)0x46fcfa;
    FUN_00797a40();
  }
  pppppuStack_374 = (undefined4 *****)0x0;
  pppppuStack_378 = (undefined4 *****)0x1;
  pcStack_37c = (char *)0x46fd05;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_37c = s_DAMAGE_PHYSICAL_MUL_009a20b8;
  pppppuStack_384 = &pppppuStack_368;
  pppppuStack_380 = (undefined4 *****)&DAT_009a371c;
  pcStack_388 = (char *)0x46fd1b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_368 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fd41;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fd41:
  pcVar4[0x100] = '\"';
  pcVar4[0x101] = '\0';
  pppppuStack_380 = (undefined4 *****)0x46fd53;
  pcStack_37c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_380 = (undefined4 *****)0xe4;
    pppppuStack_384 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a20cc;
    pppppuStack_38c = &pppppuStack_36c;
    pcStack_388 = s_File___s__Line___d_009a20f4;
    pppppuStack_36c = (undefined4 *****)((uint)pppppuStack_36c & 0xffffff00);
    pppppuStack_390 = (undefined4 *****)0x46fd74;
    pppppuStack_390 = (undefined4 *****)FUN_0044a580();
    pcStack_394 = (char *)0x46fd7a;
    FUN_00797b80();
    pppppuStack_380 = (undefined4 *****)0x46fd82;
    FUN_00797a40();
  }
  pppppuStack_380 = (undefined4 *****)0x0;
  pppppuStack_384 = (undefined4 *****)0x1;
  pcStack_388 = (char *)0x46fd8d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_388 = s_DAMAGE_MINMAGICAL_ADD_009a2108;
  pppppuStack_390 = &pppppuStack_374;
  pppppuStack_38c = (undefined4 *****)&DAT_009a371c;
  pcStack_394 = (char *)0x46fda3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_374 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fdc9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fdc9:
  pcVar4[0x100] = '#';
  pcVar4[0x101] = '\0';
  pppppuStack_38c = (undefined4 *****)0x46fddb;
  pcStack_388 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_38c = (undefined4 *****)0xe5;
    pppppuStack_390 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2120;
    pppppuStack_398 = &pppppuStack_378;
    pcStack_394 = s_File___s__Line___d_009a2148;
    pppppuStack_378 = (undefined4 *****)((uint)pppppuStack_378 & 0xffffff00);
    pppppuStack_39c = (undefined4 *****)0x46fdfc;
    pppppuStack_39c = (undefined4 *****)FUN_0044a580();
    pcStack_3a0 = (char *)0x46fe02;
    FUN_00797b80();
    pppppuStack_38c = (undefined4 *****)0x46fe0a;
    FUN_00797a40();
  }
  pppppuStack_38c = (undefined4 *****)0x0;
  pppppuStack_390 = (undefined4 *****)0x1;
  pcStack_394 = (char *)0x46fe15;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_394 = s_DAMAGE_MAXMAGICAL_ADD_009a215c;
  pppppuStack_39c = &pppppuStack_380;
  pppppuStack_398 = (undefined4 *****)&DAT_009a371c;
  pcStack_3a0 = (char *)0x46fe2b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_380 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fe51;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fe51:
  pcVar4[0x100] = '$';
  pcVar4[0x101] = '\0';
  pppppuStack_398 = (undefined4 *****)0x46fe63;
  pcStack_394 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_398 = (undefined4 *****)0xe6;
    pppppuStack_39c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2174;
    pppppuStack_3a4 = &pppppuStack_384;
    pcStack_3a0 = s_File___s__Line___d_009a219c;
    pppppuStack_384 = (undefined4 *****)((uint)pppppuStack_384 & 0xffffff00);
    pppppuStack_3a8 = (undefined4 *****)0x46fe84;
    pppppuStack_3a8 = (undefined4 *****)FUN_0044a580();
    pcStack_3ac = (char *)0x46fe8a;
    FUN_00797b80();
    pppppuStack_398 = (undefined4 *****)0x46fe92;
    FUN_00797a40();
  }
  pppppuStack_398 = (undefined4 *****)0x0;
  pppppuStack_39c = (undefined4 *****)0x1;
  pcStack_3a0 = (char *)0x46fe9d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3a0 = s_DAMAGE_MAGICAL_MUL_009a21b0;
  pppppuStack_3a8 = &pppppuStack_38c;
  pppppuStack_3a4 = (undefined4 *****)&DAT_009a371c;
  pcStack_3ac = (char *)0x46feb3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_38c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046fed9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046fed9:
  pcVar4[0x100] = '%';
  pcVar4[0x101] = '\0';
  pppppuStack_3a4 = (undefined4 *****)0x46feeb;
  pcStack_3a0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3a4 = (undefined4 *****)0xe7;
    pppppuStack_3a8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a21c4;
    pppppuStack_3b0 = &pppppuStack_390;
    pcStack_3ac = s_File___s__Line___d_009a21ec;
    pppppuStack_390 = (undefined4 *****)((uint)pppppuStack_390 & 0xffffff00);
    pppppuStack_3b4 = (undefined4 *****)0x46ff0c;
    pppppuStack_3b4 = (undefined4 *****)FUN_0044a580();
    pcStack_3b8 = (char *)0x46ff12;
    FUN_00797b80();
    pppppuStack_3a4 = (undefined4 *****)0x46ff1a;
    FUN_00797a40();
  }
  pppppuStack_3a4 = (undefined4 *****)0x0;
  pppppuStack_3a8 = (undefined4 *****)0x1;
  pcStack_3ac = "h";
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3ac = s_SPEED_ATTACK_MUL_009a2200;
  pppppuStack_3b4 = &pppppuStack_398;
  pppppuStack_3b0 = (undefined4 *****)&DAT_009a371c;
  pcStack_3b8 = (char *)0x46ff3b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_398 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046ff61;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046ff61:
  pcVar4[0x100] = '(';
  pcVar4[0x101] = '\0';
  pppppuStack_3b0 = (undefined4 *****)0x46ff73;
  pcStack_3ac = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3b0 = (undefined4 *****)0xe9;
    pppppuStack_3b4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2214;
    pppppuStack_3bc = &pppppuStack_39c;
    pcStack_3b8 = s_File___s__Line___d_009a223c;
    pppppuStack_39c = (undefined4 *****)((uint)pppppuStack_39c & 0xffffff00);
    pppppuStack_3c0 = (undefined4 *****)0x46ff94;
    pppppuStack_3c0 = (undefined4 *****)FUN_0044a580();
    pcStack_3c4 = (char *)0x46ff9a;
    FUN_00797b80();
    pppppuStack_3b0 = (undefined4 *****)0x46ffa2;
    FUN_00797a40();
  }
  pppppuStack_3b0 = (undefined4 *****)0x0;
  pppppuStack_3b4 = (undefined4 *****)0x1;
  pcStack_3b8 = (char *)0x46ffad;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3b8 = s_SPEED_CASTING_MUL_009a2250;
  pppppuStack_3c0 = &pppppuStack_3a4;
  pppppuStack_3bc = (undefined4 *****)&DAT_009a371c;
  pcStack_3c4 = (char *)0x46ffc3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3a4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_0046ffe9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_0046ffe9:
  pcVar4[0x100] = ')';
  pcVar4[0x101] = '\0';
  pppppuStack_3bc = (undefined4 *****)0x46fffb;
  pcStack_3b8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3bc = (undefined4 *****)0xea;
    pppppuStack_3c0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2264;
    pppppuStack_3c8 = &pppppuStack_3a8;
    pcStack_3c4 = s_File___s__Line___d_009a228c;
    pppppuStack_3a8 = (undefined4 *****)((uint)pppppuStack_3a8 & 0xffffff00);
    pppppuStack_3cc = (undefined4 *****)0x47001c;
    pppppuStack_3cc = (undefined4 *****)FUN_0044a580();
    pcStack_3d0 = (char *)0x470022;
    FUN_00797b80();
    pppppuStack_3bc = (undefined4 *****)0x47002a;
    FUN_00797a40();
  }
  pppppuStack_3bc = (undefined4 *****)0x0;
  pppppuStack_3c0 = (undefined4 *****)0x1;
  pcStack_3c4 = (char *)0x470035;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3c4 = s_SPEED_COOLTIME_MUL_009a22a0;
  pppppuStack_3cc = &pppppuStack_3b0;
  pppppuStack_3c8 = (undefined4 *****)&DAT_009a371c;
  pcStack_3d0 = (char *)0x47004b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3b0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470071;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470071:
  pcVar4[0x100] = '*';
  pcVar4[0x101] = '\0';
  pppppuStack_3c8 = (undefined4 *****)0x470083;
  pcStack_3c4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3c8 = (undefined4 *****)0xeb;
    pppppuStack_3cc = (undefined4 *****)s___Loader_Article_Facade_Provider_009a22b4;
    pppppuStack_3d4 = &pppppuStack_3b4;
    pcStack_3d0 = s_File___s__Line___d_009a22dc;
    pppppuStack_3b4 = (undefined4 *****)((uint)pppppuStack_3b4 & 0xffffff00);
    pppppuStack_3d8 = (undefined4 *****)0x4700a4;
    pppppuStack_3d8 = (undefined4 *****)FUN_0044a580();
    pcStack_3dc = (char *)0x4700aa;
    FUN_00797b80();
    pppppuStack_3c8 = (undefined4 *****)0x4700b2;
    FUN_00797a40();
  }
  pppppuStack_3c8 = (undefined4 *****)0x0;
  pppppuStack_3cc = (undefined4 *****)0x1;
  pcStack_3d0 = (char *)0x4700bd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3d0 = s_SPEED_MOVE_MUL_009a22f0;
  pppppuStack_3d8 = &pppppuStack_3bc;
  pppppuStack_3d4 = (undefined4 *****)&DAT_009a371c;
  pcStack_3dc = (char *)0x4700d3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3bc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004700f9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004700f9:
  pcVar4[0x100] = '+';
  pcVar4[0x101] = '\0';
  pppppuStack_3d4 = (undefined4 *****)0x47010b;
  pcStack_3d0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3d4 = (undefined4 *****)0xec;
    pppppuStack_3d8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2300;
    pppppuStack_3e0 = &pppppuStack_3c0;
    pcStack_3dc = s_File___s__Line___d_009a2328;
    pppppuStack_3c0 = (undefined4 *****)((uint)pppppuStack_3c0 & 0xffffff00);
    pppppuStack_3e4 = (undefined4 *****)0x47012c;
    pppppuStack_3e4 = (undefined4 *****)FUN_0044a580();
    pcStack_3e8 = (char *)0x470132;
    FUN_00797b80();
    pppppuStack_3d4 = (undefined4 *****)0x47013a;
    FUN_00797a40();
  }
  pppppuStack_3d4 = (undefined4 *****)0x0;
  pppppuStack_3d8 = (undefined4 *****)0x1;
  pcStack_3dc = (char *)0x470145;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3dc = s_RATING_ATTACK_ADD_009a233c;
  pppppuStack_3e4 = &pppppuStack_3c8;
  pppppuStack_3e0 = (undefined4 *****)&DAT_009a371c;
  pcStack_3e8 = (char *)0x47015b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3c8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470181;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470181:
  pcVar4[0x100] = '0';
  pcVar4[0x101] = '\0';
  pppppuStack_3e0 = (undefined4 *****)0x470193;
  pcStack_3dc = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3e0 = (undefined4 *****)0xee;
    pppppuStack_3e4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2350;
    pppppuStack_3ec = &pppppuStack_3cc;
    pcStack_3e8 = s_File___s__Line___d_009a2378;
    pppppuStack_3cc = (undefined4 *****)((uint)pppppuStack_3cc & 0xffffff00);
    pppppuStack_3f0 = (undefined4 *****)0x4701b4;
    pppppuStack_3f0 = (undefined4 *****)FUN_0044a580();
    pcStack_3f4 = (char *)0x4701ba;
    FUN_00797b80();
    pppppuStack_3e0 = (undefined4 *****)0x4701c2;
    FUN_00797a40();
  }
  pppppuStack_3e0 = (undefined4 *****)0x0;
  pppppuStack_3e4 = (undefined4 *****)0x1;
  pcStack_3e8 = (char *)0x4701cd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3e8 = s_RATING_CRITICAL_ADD_009a238c;
  pppppuStack_3f0 = &pppppuStack_3d4;
  pppppuStack_3ec = (undefined4 *****)&DAT_009a371c;
  pcStack_3f4 = (char *)0x4701e3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3d4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470209;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470209:
  pcVar4[0x100] = '1';
  pcVar4[0x101] = '\0';
  pppppuStack_3ec = (undefined4 *****)0x47021b;
  pcStack_3e8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3ec = (undefined4 *****)0xef;
    pppppuStack_3f0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a23a0;
    pppppuStack_3f8 = &pppppuStack_3d8;
    pcStack_3f4 = s_File___s__Line___d_009a23c8;
    pppppuStack_3d8 = (undefined4 *****)((uint)pppppuStack_3d8 & 0xffffff00);
    pppppuStack_3fc = (undefined4 *****)0x47023c;
    pppppuStack_3fc = (undefined4 *****)FUN_0044a580();
    pcStack_400 = (char *)0x470242;
    FUN_00797b80();
    pppppuStack_3ec = (undefined4 *****)0x47024a;
    FUN_00797a40();
  }
  pppppuStack_3ec = (undefined4 *****)0x0;
  pppppuStack_3f0 = (undefined4 *****)0x1;
  pcStack_3f4 = (char *)0x470255;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_3f4 = s_RATING_BLOCKING_ADD_009a23dc;
  pppppuStack_3fc = &pppppuStack_3e0;
  pppppuStack_3f8 = (undefined4 *****)&DAT_009a371c;
  pcStack_400 = (char *)0x47026b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3e0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470291;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470291:
  pcVar4[0x100] = '2';
  pcVar4[0x101] = '\0';
  pppppuStack_3f8 = (undefined4 *****)0x4702a3;
  pcStack_3f4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_3f8 = (undefined4 *****)0xf0;
    pppppuStack_3fc = (undefined4 *****)s___Loader_Article_Facade_Provider_009a23f0;
    pppppuStack_404 = &pppppuStack_3e4;
    pcStack_400 = s_File___s__Line___d_009a2418;
    pppppuStack_3e4 = (undefined4 *****)((uint)pppppuStack_3e4 & 0xffffff00);
    pppppuStack_408 = (undefined4 *****)0x4702c4;
    pppppuStack_408 = (undefined4 *****)FUN_0044a580();
    pcStack_40c = (char *)0x4702ca;
    FUN_00797b80();
    pppppuStack_3f8 = (undefined4 *****)0x4702d2;
    FUN_00797a40();
  }
  pppppuStack_3f8 = (undefined4 *****)0x0;
  pppppuStack_3fc = (undefined4 *****)0x1;
  pcStack_400 = (char *)0x4702dd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_400 = s_RATING_GUARD_ADD_009a242c;
  pppppuStack_408 = &pppppuStack_3ec;
  pppppuStack_404 = (undefined4 *****)&DAT_009a371c;
  pcStack_40c = (char *)0x4702f3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3ec - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470319;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470319:
  pcVar4[0x100] = '3';
  pcVar4[0x101] = '\0';
  pppppuStack_404 = (undefined4 *****)0x47032b;
  pcStack_400 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_404 = (undefined4 *****)0xf1;
    pppppuStack_408 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2440;
    pppppuStack_410 = &pppppuStack_3f0;
    pcStack_40c = s_File___s__Line___d_009a2468;
    pppppuStack_3f0 = (undefined4 *****)((uint)pppppuStack_3f0 & 0xffffff00);
    pppppuStack_414 = (undefined4 *****)0x47034c;
    pppppuStack_414 = (undefined4 *****)FUN_0044a580();
    pcStack_418 = (char *)0x470352;
    FUN_00797b80();
    pppppuStack_404 = (undefined4 *****)0x47035a;
    FUN_00797a40();
  }
  pppppuStack_404 = (undefined4 *****)0x0;
  pppppuStack_408 = (undefined4 *****)0x1;
  pcStack_40c = (char *)0x470365;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_40c = s_RATING_FISHING_CASTING_ADD_009a247c;
  pppppuStack_414 = &pppppuStack_3f8;
  pppppuStack_410 = (undefined4 *****)&DAT_009a371c;
  pcStack_418 = (char *)0x47037b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_3f8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004703a1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004703a1:
  pcVar4[0x100] = '4';
  pcVar4[0x101] = '\0';
  pppppuStack_410 = (undefined4 *****)0x4703b3;
  pcStack_40c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_410 = (undefined4 *****)0xf2;
    pppppuStack_414 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2498;
    pppppuStack_41c = &pppppuStack_3fc;
    pcStack_418 = s_File___s__Line___d_009a24c0;
    pppppuStack_3fc = (undefined4 *****)((uint)pppppuStack_3fc & 0xffffff00);
    pppppuStack_420 = (undefined4 *****)0x4703d4;
    pppppuStack_420 = (undefined4 *****)FUN_0044a580();
    pcStack_424 = (char *)0x4703da;
    FUN_00797b80();
    pppppuStack_410 = (undefined4 *****)0x4703e2;
    FUN_00797a40();
  }
  pppppuStack_410 = (undefined4 *****)0x0;
  pppppuStack_414 = (undefined4 *****)0x1;
  pcStack_418 = (char *)0x4703ed;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_418 = s_RATING_ANTI_STATUS_ADD_009a24d4;
  pppppuStack_420 = &pppppuStack_404;
  pppppuStack_41c = (undefined4 *****)&DAT_009a371c;
  pcStack_424 = (char *)0x470403;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_404 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470429;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470429:
  pcVar4[0x100] = '5';
  pcVar4[0x101] = '\0';
  pppppuStack_41c = (undefined4 *****)0x47043b;
  pcStack_418 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_41c = (undefined4 *****)0xf4;
    pppppuStack_420 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a24ec;
    pppppuStack_428 = &pppppuStack_408;
    pcStack_424 = s_File___s__Line___d_009a2514;
    pppppuStack_408 = (undefined4 *****)((uint)pppppuStack_408 & 0xffffff00);
    pppppuStack_42c = (undefined4 *****)0x47045c;
    pppppuStack_42c = (undefined4 *****)FUN_0044a580();
    pcStack_430 = (char *)0x470462;
    FUN_00797b80();
    pppppuStack_41c = (undefined4 *****)0x47046a;
    FUN_00797a40();
  }
  pppppuStack_41c = (undefined4 *****)0x0;
  pppppuStack_420 = (undefined4 *****)0x1;
  pcStack_424 = (char *)0x470475;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_424 = s_DAMAGERATE_FIRE_ADD_009a2528;
  pppppuStack_42c = &pppppuStack_410;
  pppppuStack_428 = (undefined4 *****)&DAT_009a371c;
  pcStack_430 = (char *)0x47048b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_410 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004704b1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004704b1:
  pcVar4[0x100] = '8';
  pcVar4[0x101] = '\0';
  pppppuStack_428 = (undefined4 *****)0x4704c3;
  pcStack_424 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_428 = (undefined4 *****)0xf6;
    pppppuStack_42c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a253c;
    pppppuStack_434 = &pppppuStack_414;
    pcStack_430 = s_File___s__Line___d_009a2564;
    pppppuStack_414 = (undefined4 *****)((uint)pppppuStack_414 & 0xffffff00);
    pppppuStack_438 = (undefined4 *****)0x4704e4;
    pppppuStack_438 = (undefined4 *****)FUN_0044a580();
    pcStack_43c = (char *)0x4704ea;
    FUN_00797b80();
    pppppuStack_428 = (undefined4 *****)0x4704f2;
    FUN_00797a40();
  }
  pppppuStack_428 = (undefined4 *****)0x0;
  pppppuStack_42c = (undefined4 *****)0x1;
  pcStack_430 = (char *)0x4704fd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_430 = s_DAMAGERATE_ICE_ADD_009a2578;
  pppppuStack_438 = &pppppuStack_41c;
  pppppuStack_434 = (undefined4 *****)&DAT_009a371c;
  pcStack_43c = (char *)0x470513;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_41c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470539;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470539:
  pcVar4[0x100] = '9';
  pcVar4[0x101] = '\0';
  pppppuStack_434 = (undefined4 *****)0x47054b;
  pcStack_430 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_434 = (undefined4 *****)0xf7;
    pppppuStack_438 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a258c;
    pppppuStack_440 = &pppppuStack_420;
    pcStack_43c = s_File___s__Line___d_009a25b4;
    pppppuStack_420 = (undefined4 *****)((uint)pppppuStack_420 & 0xffffff00);
    pppppuStack_444 = (undefined4 *****)0x47056c;
    pppppuStack_444 = (undefined4 *****)FUN_0044a580();
    pcStack_448 = (char *)0x470572;
    FUN_00797b80();
    pppppuStack_434 = (undefined4 *****)0x47057a;
    FUN_00797a40();
  }
  pppppuStack_434 = (undefined4 *****)0x0;
  pppppuStack_438 = (undefined4 *****)0x1;
  pcStack_43c = (char *)0x470585;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_43c = s_DAMAGERATE_LIGHTNING_ADD_009a25c8;
  pppppuStack_444 = &pppppuStack_428;
  pppppuStack_440 = (undefined4 *****)&DAT_009a371c;
  pcStack_448 = (char *)0x47059b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_428 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004705c1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004705c1:
  pcVar4[0x100] = ':';
  pcVar4[0x101] = '\0';
  pppppuStack_440 = (undefined4 *****)0x4705d3;
  pcStack_43c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_440 = (undefined4 *****)0xf8;
    pppppuStack_444 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a25e4;
    pppppuStack_44c = &pppppuStack_42c;
    pcStack_448 = s_File___s__Line___d_009a260c;
    pppppuStack_42c = (undefined4 *****)((uint)pppppuStack_42c & 0xffffff00);
    pppppuStack_450 = (undefined4 *****)0x4705f4;
    pppppuStack_450 = (undefined4 *****)FUN_0044a580();
    pcStack_454 = (char *)0x4705fa;
    FUN_00797b80();
    pppppuStack_440 = (undefined4 *****)0x470602;
    FUN_00797a40();
  }
  pppppuStack_440 = (undefined4 *****)0x0;
  pppppuStack_444 = (undefined4 *****)0x1;
  pcStack_448 = (char *)0x47060d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_448 = s_DAMAGERATE_POISON_ADD_009a2620;
  pppppuStack_450 = &pppppuStack_434;
  pppppuStack_44c = (undefined4 *****)&DAT_009a371c;
  pcStack_454 = (char *)0x470623;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_434 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470649;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470649:
  pcVar4[0x100] = ';';
  pcVar4[0x101] = '\0';
  pppppuStack_44c = (undefined4 *****)0x47065b;
  pcStack_448 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_44c = (undefined4 *****)0xf9;
    pppppuStack_450 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2638;
    pppppuStack_458 = &pppppuStack_438;
    pcStack_454 = s_File___s__Line___d_009a2660;
    pppppuStack_438 = (undefined4 *****)((uint)pppppuStack_438 & 0xffffff00);
    pppppuStack_45c = (undefined4 *****)0x47067c;
    pppppuStack_45c = (undefined4 *****)FUN_0044a580();
    pcStack_460 = (char *)0x470682;
    FUN_00797b80();
    pppppuStack_44c = (undefined4 *****)0x47068a;
    FUN_00797a40();
  }
  pppppuStack_44c = (undefined4 *****)0x0;
  pppppuStack_450 = (undefined4 *****)0x1;
  pcStack_454 = (char *)0x470695;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_454 = s_DAMAGERATE_CURSE_ADD_009a2674;
  pppppuStack_45c = &pppppuStack_440;
  pppppuStack_458 = (undefined4 *****)&DAT_009a371c;
  pcStack_460 = (char *)0x4706ab;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_440 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004706d1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004706d1:
  pcVar4[0x100] = '<';
  pcVar4[0x101] = '\0';
  pppppuStack_458 = (undefined4 *****)0x4706e3;
  pcStack_454 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_458 = (undefined4 *****)0xfa;
    pppppuStack_45c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a268c;
    pppppuStack_464 = &pppppuStack_444;
    pcStack_460 = s_File___s__Line___d_009a26b4;
    pppppuStack_444 = (undefined4 *****)((uint)pppppuStack_444 & 0xffffff00);
    pppppuStack_468 = (undefined4 *****)0x470704;
    pppppuStack_468 = (undefined4 *****)FUN_0044a580();
    pcStack_46c = (char *)0x47070a;
    FUN_00797b80();
    pppppuStack_458 = (undefined4 *****)0x470712;
    FUN_00797a40();
  }
  pppppuStack_458 = (undefined4 *****)0x0;
  pppppuStack_45c = (undefined4 *****)0x1;
  pcStack_460 = (char *)0x47071d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_460 = s_DAMAGERATE_CRITICAL_ADD_009a26c8;
  pppppuStack_468 = &pppppuStack_44c;
  pppppuStack_464 = (undefined4 *****)&DAT_009a371c;
  pcStack_46c = (char *)0x470733;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_44c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470759;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470759:
  pcVar4[0x100] = '=';
  pcVar4[0x101] = '\0';
  pppppuStack_464 = (undefined4 *****)0x47076b;
  pcStack_460 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_464 = (undefined4 *****)0xfb;
    pppppuStack_468 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a26e0;
    pppppuStack_470 = &pppppuStack_450;
    pcStack_46c = s_File___s__Line___d_009a2708;
    pppppuStack_450 = (undefined4 *****)((uint)pppppuStack_450 & 0xffffff00);
    pppppuStack_474 = (undefined4 *****)0x47078c;
    pppppuStack_474 = (undefined4 *****)FUN_0044a580();
    pcStack_478 = (char *)0x470792;
    FUN_00797b80();
    pppppuStack_464 = (undefined4 *****)0x47079a;
    FUN_00797a40();
  }
  pppppuStack_464 = (undefined4 *****)0x0;
  pppppuStack_468 = (undefined4 *****)0x1;
  pcStack_46c = (char *)0x4707a5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_46c = s_SIZEDAMAGERATE_SMALL_ADD_009a271c;
  pppppuStack_474 = &pppppuStack_458;
  pppppuStack_470 = (undefined4 *****)&DAT_009a371c;
  pcStack_478 = (char *)0x4707bb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_458 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004707e1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004707e1:
  pcVar4[0x100] = '@';
  pcVar4[0x101] = '\0';
  pppppuStack_470 = (undefined4 *****)0x4707f3;
  pcStack_46c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_470 = (undefined4 *****)0xfd;
    pppppuStack_474 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2738;
    pppppuStack_47c = &pppppuStack_45c;
    pcStack_478 = s_File___s__Line___d_009a2760;
    pppppuStack_45c = (undefined4 *****)((uint)pppppuStack_45c & 0xffffff00);
    pppppuStack_480 = (undefined4 *****)0x470814;
    pppppuStack_480 = (undefined4 *****)FUN_0044a580();
    pcStack_484 = (char *)0x47081a;
    FUN_00797b80();
    pppppuStack_470 = (undefined4 *****)0x470822;
    FUN_00797a40();
  }
  pppppuStack_470 = (undefined4 *****)0x0;
  pppppuStack_474 = (undefined4 *****)0x1;
  pcStack_478 = (char *)0x47082d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_478 = s_SIZEDAMAGERATE_NORMAL_ADD_009a2774;
  pppppuStack_480 = &pppppuStack_464;
  pppppuStack_47c = (undefined4 *****)&DAT_009a371c;
  pcStack_484 = (char *)0x470843;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_464 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470869;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470869:
  pcVar4[0x100] = 'A';
  pcVar4[0x101] = '\0';
  pppppuStack_47c = (undefined4 *****)0x47087b;
  pcStack_478 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_47c = (undefined4 *****)0xfe;
    pppppuStack_480 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2790;
    pppppuStack_488 = &pppppuStack_468;
    pcStack_484 = s_File___s__Line___d_009a27b8;
    pppppuStack_468 = (undefined4 *****)((uint)pppppuStack_468 & 0xffffff00);
    pppppuStack_48c = (undefined4 *****)0x47089c;
    pppppuStack_48c = (undefined4 *****)FUN_0044a580();
    pcStack_490 = (char *)0x4708a2;
    FUN_00797b80();
    pppppuStack_47c = (undefined4 *****)0x4708aa;
    FUN_00797a40();
  }
  pppppuStack_47c = (undefined4 *****)0x0;
  pppppuStack_480 = (undefined4 *****)0x1;
  pcStack_484 = (char *)0x4708b5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_484 = s_SIZEDAMAGERATE_LARGE_ADD_009a27cc;
  pppppuStack_48c = &pppppuStack_470;
  pppppuStack_488 = (undefined4 *****)&DAT_009a371c;
  pcStack_490 = (char *)0x4708cb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_470 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004708f1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004708f1:
  pcVar4[0x100] = 'B';
  pcVar4[0x101] = '\0';
  pppppuStack_488 = (undefined4 *****)0x470903;
  pcStack_484 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_488 = (undefined4 *****)0xff;
    pppppuStack_48c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a27e8;
    pppppuStack_494 = &pppppuStack_474;
    pcStack_490 = s_File___s__Line___d_009a2810;
    pppppuStack_474 = (undefined4 *****)((uint)pppppuStack_474 & 0xffffff00);
    pppppuStack_498 = (undefined4 *****)0x470924;
    pppppuStack_498 = (undefined4 *****)FUN_0044a580();
    pcStack_49c = (char *)0x47092a;
    FUN_00797b80();
    pppppuStack_488 = (undefined4 *****)0x470932;
    FUN_00797a40();
  }
  pppppuStack_488 = (undefined4 *****)0x0;
  pppppuStack_48c = (undefined4 *****)0x1;
  pcStack_490 = (char *)0x47093d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_490 = s_SIZEDAMAGERATE_BOSS_ADD_009a2824;
  pppppuStack_498 = &pppppuStack_47c;
  pppppuStack_494 = (undefined4 *****)&DAT_009a371c;
  pcStack_49c = (char *)0x470953;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_47c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470979;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470979:
  pcVar4[0x100] = 'C';
  pcVar4[0x101] = '\0';
  pppppuStack_494 = (undefined4 *****)0x47098b;
  pcStack_490 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_494 = (undefined4 *****)0x100;
    pppppuStack_498 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a283c;
    pppppuStack_4a0 = &pppppuStack_480;
    pcStack_49c = s_File___s__Line___d_009a2864;
    pppppuStack_480 = (undefined4 *****)((uint)pppppuStack_480 & 0xffffff00);
    pppppuStack_4a4 = (undefined4 *****)0x4709ac;
    pppppuStack_4a4 = (undefined4 *****)FUN_0044a580();
    pcStack_4a8 = (char *)0x4709b2;
    FUN_00797b80();
    pppppuStack_494 = (undefined4 *****)0x4709ba;
    FUN_00797a40();
  }
  pppppuStack_494 = (undefined4 *****)0x0;
  pppppuStack_498 = (undefined4 *****)0x1;
  pcStack_49c = (char *)0x4709c5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_49c = s_SIZEDAMAGERATE_UNDEAD_ADD_009a2878;
  pppppuStack_4a4 = &pppppuStack_488;
  pppppuStack_4a0 = (undefined4 *****)&DAT_009a371c;
  pcStack_4a8 = (char *)0x4709db;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_488 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470a01;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470a01:
  pcVar4[0x100] = 'D';
  pcVar4[0x101] = '\0';
  pppppuStack_4a0 = (undefined4 *****)0x470a13;
  pcStack_49c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4a0 = (undefined4 *****)0x101;
    pppppuStack_4a4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2894;
    pppppuStack_4ac = &pppppuStack_48c;
    pcStack_4a8 = s_File___s__Line___d_009a28bc;
    pppppuStack_48c = (undefined4 *****)((uint)pppppuStack_48c & 0xffffff00);
    pppppuStack_4b0 = (undefined4 *****)0x470a34;
    pppppuStack_4b0 = (undefined4 *****)FUN_0044a580();
    pcStack_4b4 = (char *)0x470a3a;
    FUN_00797b80();
    pppppuStack_4a0 = (undefined4 *****)0x470a42;
    FUN_00797a40();
  }
  pppppuStack_4a0 = (undefined4 *****)0x0;
  pppppuStack_4a4 = (undefined4 *****)0x1;
  pcStack_4a8 = (char *)0x470a4d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4a8 = s_DEFENSE_MIN_ADD_009a28d0;
  pppppuStack_4b0 = &pppppuStack_494;
  pppppuStack_4ac = (undefined4 *****)&DAT_009a371c;
  pcStack_4b4 = (char *)0x470a63;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_494 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470a89;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470a89:
  pcVar4[0x100] = 'H';
  pcVar4[0x101] = '\0';
  pppppuStack_4ac = (undefined4 *****)0x470a9b;
  pcStack_4a8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4ac = (undefined4 *****)0x103;
    pppppuStack_4b0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a28e0;
    pppppuStack_4b8 = &pppppuStack_498;
    pcStack_4b4 = s_File___s__Line___d_009a2908;
    pppppuStack_498 = (undefined4 *****)((uint)pppppuStack_498 & 0xffffff00);
    pppppuStack_4bc = (undefined4 *****)0x470abc;
    pppppuStack_4bc = (undefined4 *****)FUN_0044a580();
    pcStack_4c0 = (char *)0x470ac2;
    FUN_00797b80();
    pppppuStack_4ac = (undefined4 *****)0x470aca;
    FUN_00797a40();
  }
  pppppuStack_4ac = (undefined4 *****)0x0;
  pppppuStack_4b0 = (undefined4 *****)0x1;
  pcStack_4b4 = (char *)0x470ad5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4b4 = s_DEFENSE_MAX_ADD_009a291c;
  pppppuStack_4bc = &pppppuStack_4a0;
  pppppuStack_4b8 = (undefined4 *****)&DAT_009a371c;
  pcStack_4c0 = (char *)0x470aeb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4a0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470b11;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470b11:
  pcVar4[0x100] = 'I';
  pcVar4[0x101] = '\0';
  pppppuStack_4b8 = (undefined4 *****)0x470b23;
  pcStack_4b4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4b8 = (undefined4 *****)0x104;
    pppppuStack_4bc = (undefined4 *****)s___Loader_Article_Facade_Provider_009a292c;
    pppppuStack_4c4 = &pppppuStack_4a4;
    pcStack_4c0 = s_File___s__Line___d_009a2954;
    pppppuStack_4a4 = (undefined4 *****)((uint)pppppuStack_4a4 & 0xffffff00);
    pppppuStack_4c8 = (undefined4 *****)0x470b44;
    pppppuStack_4c8 = (undefined4 *****)FUN_0044a580();
    pcStack_4cc = (char *)0x470b4a;
    FUN_00797b80();
    pppppuStack_4b8 = (undefined4 *****)0x470b52;
    FUN_00797a40();
  }
  pppppuStack_4b8 = (undefined4 *****)0x0;
  pppppuStack_4bc = (undefined4 *****)0x1;
  pcStack_4c0 = (char *)0x470b5d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4c0 = s_DEFENSE_MUL_009a2968;
  pppppuStack_4c8 = &pppppuStack_4ac;
  pppppuStack_4c4 = (undefined4 *****)&DAT_009a371c;
  pcStack_4cc = (char *)0x470b73;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4ac - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470b99;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470b99:
  pcVar4[0x100] = 'J';
  pcVar4[0x101] = '\0';
  pppppuStack_4c4 = (undefined4 *****)0x470bab;
  pcStack_4c0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4c4 = (undefined4 *****)0x105;
    pppppuStack_4c8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2974;
    pppppuStack_4d0 = &pppppuStack_4b0;
    pcStack_4cc = s_File___s__Line___d_009a299c;
    pppppuStack_4b0 = (undefined4 *****)((uint)pppppuStack_4b0 & 0xffffff00);
    pppppuStack_4d4 = (undefined4 *****)0x470bcc;
    pppppuStack_4d4 = (undefined4 *****)FUN_0044a580();
    pcStack_4d8 = (char *)0x470bd2;
    FUN_00797b80();
    pppppuStack_4c4 = (undefined4 *****)0x470bda;
    FUN_00797a40();
  }
  pppppuStack_4c4 = (undefined4 *****)0x0;
  pppppuStack_4c8 = (undefined4 *****)0x1;
  pcStack_4cc = (char *)0x470be5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4cc = s_DEFENSE_DEFEATRATE_MUL_009a29b0;
  pppppuStack_4d4 = &pppppuStack_4b8;
  pppppuStack_4d0 = (undefined4 *****)&DAT_009a371c;
  pcStack_4d8 = (char *)0x470bfb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4b8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470c21;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470c21:
  pcVar4[0x100] = 'K';
  pcVar4[0x101] = '\0';
  pppppuStack_4d0 = (undefined4 *****)0x470c33;
  pcStack_4cc = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4d0 = (undefined4 *****)0x106;
    pppppuStack_4d4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a29c8;
    pppppuStack_4dc = &pppppuStack_4bc;
    pcStack_4d8 = s_File___s__Line___d_009a29f0;
    pppppuStack_4bc = (undefined4 *****)((uint)pppppuStack_4bc & 0xffffff00);
    pppppuStack_4e0 = (undefined4 *****)0x470c54;
    pppppuStack_4e0 = (undefined4 *****)FUN_0044a580();
    pcStack_4e4 = (char *)0x470c5a;
    FUN_00797b80();
    pppppuStack_4d0 = (undefined4 *****)0x470c62;
    FUN_00797a40();
  }
  pppppuStack_4d0 = (undefined4 *****)0x0;
  pppppuStack_4d4 = (undefined4 *****)0x1;
  pcStack_4d8 = (char *)0x470c6d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4d8 = s_REFLECT_DAMAGEHP_MUL_009a2a04;
  pppppuStack_4e0 = &pppppuStack_4c4;
  pppppuStack_4dc = (undefined4 *****)&DAT_009a371c;
  pcStack_4e4 = (char *)0x470c83;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4c4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470ca9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470ca9:
  pcVar4[0x100] = 'P';
  pcVar4[0x101] = '\0';
  pppppuStack_4dc = (undefined4 *****)0x470cbb;
  pcStack_4d8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4dc = (undefined4 *****)0x108;
    pppppuStack_4e0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2a1c;
    pppppuStack_4e8 = &pppppuStack_4c8;
    pcStack_4e4 = s_File___s__Line___d_009a2a44;
    pppppuStack_4c8 = (undefined4 *****)((uint)pppppuStack_4c8 & 0xffffff00);
    pppppuStack_4ec = (undefined4 *****)0x470cdc;
    pppppuStack_4ec = (undefined4 *****)FUN_0044a580();
    pcStack_4f0 = (char *)0x470ce2;
    FUN_00797b80();
    pppppuStack_4dc = (undefined4 *****)0x470cea;
    FUN_00797a40();
  }
  pppppuStack_4dc = (undefined4 *****)0x0;
  pppppuStack_4e0 = (undefined4 *****)0x1;
  pcStack_4e4 = (char *)0x470cf5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4e4 = s_REFLECT_DAMAGEHP_ADD_009a2a58;
  pppppuStack_4ec = &pppppuStack_4d0;
  pppppuStack_4e8 = (undefined4 *****)&DAT_009a371c;
  pcStack_4f0 = (char *)0x470d0b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4d0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470d31;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470d31:
  pcVar4[0x100] = 'Q';
  pcVar4[0x101] = '\0';
  pppppuStack_4e8 = (undefined4 *****)0x470d43;
  pcStack_4e4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4e8 = (undefined4 *****)0x109;
    pppppuStack_4ec = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2a70;
    pppppuStack_4f4 = &pppppuStack_4d4;
    pcStack_4f0 = s_File___s__Line___d_009a2a98;
    pppppuStack_4d4 = (undefined4 *****)((uint)pppppuStack_4d4 & 0xffffff00);
    pppppuStack_4f8 = (undefined4 *****)0x470d64;
    pppppuStack_4f8 = (undefined4 *****)FUN_0044a580();
    pcStack_4fc = (char *)0x470d6a;
    FUN_00797b80();
    pppppuStack_4e8 = (undefined4 *****)0x470d72;
    FUN_00797a40();
  }
  pppppuStack_4e8 = (undefined4 *****)0x0;
  pppppuStack_4ec = (undefined4 *****)0x1;
  pcStack_4f0 = (char *)0x470d7d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4f0 = s_REFLECT_DAMAGEMP_MUL_009a2aac;
  pppppuStack_4f8 = &pppppuStack_4dc;
  pppppuStack_4f4 = (undefined4 *****)&DAT_009a371c;
  pcStack_4fc = (char *)0x470d93;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4dc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470db9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470db9:
  pcVar4[0x100] = 'R';
  pcVar4[0x101] = '\0';
  pppppuStack_4f4 = (undefined4 *****)0x470dcb;
  pcStack_4f0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_4f4 = (undefined4 *****)0x10a;
    pppppuStack_4f8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2ac4;
    pppppuStack_500 = &pppppuStack_4e0;
    pcStack_4fc = s_File___s__Line___d_009a2aec;
    pppppuStack_4e0 = (undefined4 *****)((uint)pppppuStack_4e0 & 0xffffff00);
    pppppuStack_504 = (undefined4 *****)0x470dec;
    pppppuStack_504 = (undefined4 *****)FUN_0044a580();
    pcStack_508 = (char *)0x470df2;
    FUN_00797b80();
    pppppuStack_4f4 = (undefined4 *****)0x470dfa;
    FUN_00797a40();
  }
  pppppuStack_4f4 = (undefined4 *****)0x0;
  pppppuStack_4f8 = (undefined4 *****)0x1;
  pcStack_4fc = "h";
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_4fc = s_REFLECT_DAMAGEMP_ADD_009a2b00;
  pppppuStack_504 = &pppppuStack_4e8;
  pppppuStack_500 = (undefined4 *****)&DAT_009a371c;
  pcStack_508 = (char *)0x470e1b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4e8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470e41;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470e41:
  pcVar4[0x100] = 'S';
  pcVar4[0x101] = '\0';
  pppppuStack_500 = (undefined4 *****)0x470e53;
  pcStack_4fc = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_500 = (undefined4 *****)0x10b;
    pppppuStack_504 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2b18;
    pppppuStack_50c = &pppppuStack_4ec;
    pcStack_508 = s_File___s__Line___d_009a2b40;
    pppppuStack_4ec = (undefined4 *****)((uint)pppppuStack_4ec & 0xffffff00);
    pppppuStack_510 = (undefined4 *****)0x470e74;
    pppppuStack_510 = (undefined4 *****)FUN_0044a580();
    pcStack_514 = (char *)0x470e7a;
    FUN_00797b80();
    pppppuStack_500 = (undefined4 *****)0x470e82;
    FUN_00797a40();
  }
  pppppuStack_500 = (undefined4 *****)0x0;
  pppppuStack_504 = (undefined4 *****)0x1;
  pcStack_508 = (char *)0x470e8d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_508 = s_DAMAGEADD_FIRE_ADD_009a2b54;
  pppppuStack_510 = &pppppuStack_4f4;
  pppppuStack_50c = (undefined4 *****)&DAT_009a371c;
  pcStack_514 = (char *)0x470ea3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_4f4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470ec9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470ec9:
  pcVar4[0x100] = 'X';
  pcVar4[0x101] = '\0';
  pppppuStack_50c = (undefined4 *****)0x470edb;
  pcStack_508 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_50c = (undefined4 *****)0x10d;
    pppppuStack_510 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2b68;
    pppppuStack_518 = &pppppuStack_4f8;
    pcStack_514 = s_File___s__Line___d_009a2b90;
    pppppuStack_4f8 = (undefined4 *****)((uint)pppppuStack_4f8 & 0xffffff00);
    pppppuStack_51c = (undefined4 *****)0x470efc;
    pppppuStack_51c = (undefined4 *****)FUN_0044a580();
    pcStack_520 = (char *)0x470f02;
    FUN_00797b80();
    pppppuStack_50c = (undefined4 *****)0x470f0a;
    FUN_00797a40();
  }
  pppppuStack_50c = (undefined4 *****)0x0;
  pppppuStack_510 = (undefined4 *****)0x1;
  pcStack_514 = (char *)0x470f15;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_514 = s_DAMAGEADD_ICE_ADD_009a2ba4;
  pppppuStack_51c = &pppppuStack_500;
  pppppuStack_518 = (undefined4 *****)&DAT_009a371c;
  pcStack_520 = (char *)0x470f2b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_500 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470f51;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470f51:
  pcVar4[0x100] = 'Y';
  pcVar4[0x101] = '\0';
  pppppuStack_518 = (undefined4 *****)0x470f63;
  pcStack_514 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_518 = (undefined4 *****)0x10e;
    pppppuStack_51c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2bb8;
    pppppuStack_524 = &pppppuStack_504;
    pcStack_520 = s_File___s__Line___d_009a2be0;
    pppppuStack_504 = (undefined4 *****)((uint)pppppuStack_504 & 0xffffff00);
    pppppuStack_528 = (undefined4 *****)0x470f84;
    pppppuStack_528 = (undefined4 *****)FUN_0044a580();
    pcStack_52c = (char *)0x470f8a;
    FUN_00797b80();
    pppppuStack_518 = (undefined4 *****)0x470f92;
    FUN_00797a40();
  }
  pppppuStack_518 = (undefined4 *****)0x0;
  pppppuStack_51c = (undefined4 *****)0x1;
  pcStack_520 = (char *)0x470f9d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_520 = s_DAMAGEADD_LIGHTNING_ADD_009a2bf4;
  pppppuStack_528 = &pppppuStack_50c;
  pppppuStack_524 = (undefined4 *****)&DAT_009a371c;
  pcStack_52c = (char *)0x470fb3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_50c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00470fd9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00470fd9:
  pcVar4[0x100] = 'Z';
  pcVar4[0x101] = '\0';
  pppppuStack_524 = (undefined4 *****)0x470feb;
  pcStack_520 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_524 = (undefined4 *****)0x10f;
    pppppuStack_528 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2c0c;
    pppppuStack_530 = &pppppuStack_510;
    pcStack_52c = s_File___s__Line___d_009a2c34;
    pppppuStack_510 = (undefined4 *****)((uint)pppppuStack_510 & 0xffffff00);
    pppppuStack_534 = (undefined4 *****)0x47100c;
    pppppuStack_534 = (undefined4 *****)FUN_0044a580();
    pcStack_538 = (char *)0x471012;
    FUN_00797b80();
    pppppuStack_524 = (undefined4 *****)0x47101a;
    FUN_00797a40();
  }
  pppppuStack_524 = (undefined4 *****)0x0;
  pppppuStack_528 = (undefined4 *****)0x1;
  pcStack_52c = (char *)0x471025;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_52c = s_DAMAGEADD_POISON_ADD_009a2c48;
  pppppuStack_534 = &pppppuStack_518;
  pppppuStack_530 = (undefined4 *****)&DAT_009a371c;
  pcStack_538 = (char *)0x47103b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_518 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471061;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471061:
  pcVar4[0x100] = '[';
  pcVar4[0x101] = '\0';
  pppppuStack_530 = (undefined4 *****)0x471073;
  pcStack_52c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_530 = (undefined4 *****)0x110;
    pppppuStack_534 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2c60;
    pppppuStack_53c = &pppppuStack_51c;
    pcStack_538 = s_File___s__Line___d_009a2c88;
    pppppuStack_51c = (undefined4 *****)((uint)pppppuStack_51c & 0xffffff00);
    pppppuStack_540 = (undefined4 *****)0x471094;
    pppppuStack_540 = (undefined4 *****)FUN_0044a580();
    pcStack_544 = (char *)0x47109a;
    FUN_00797b80();
    pppppuStack_530 = (undefined4 *****)0x4710a2;
    FUN_00797a40();
  }
  pppppuStack_530 = (undefined4 *****)0x0;
  pppppuStack_534 = (undefined4 *****)0x1;
  pcStack_538 = (char *)0x4710ad;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_538 = s_DAMAGEADD_CURSE_ADD_009a2c9c;
  pppppuStack_540 = &pppppuStack_524;
  pppppuStack_53c = (undefined4 *****)&DAT_009a371c;
  pcStack_544 = (char *)0x4710c3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_524 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004710e9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004710e9:
  pcVar4[0x100] = '\\';
  pcVar4[0x101] = '\0';
  pppppuStack_53c = (undefined4 *****)0x4710fb;
  pcStack_538 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_53c = (undefined4 *****)0x111;
    pppppuStack_540 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2cb0;
    pppppuStack_548 = &pppppuStack_528;
    pcStack_544 = s_File___s__Line___d_009a2cd8;
    pppppuStack_528 = (undefined4 *****)((uint)pppppuStack_528 & 0xffffff00);
    pppppuStack_54c = (undefined4 *****)0x47111c;
    pppppuStack_54c = (undefined4 *****)FUN_0044a580();
    pcStack_550 = (char *)0x471122;
    FUN_00797b80();
    pppppuStack_53c = (undefined4 *****)0x47112a;
    FUN_00797a40();
  }
  pppppuStack_53c = (undefined4 *****)0x0;
  pppppuStack_540 = (undefined4 *****)0x1;
  pcStack_544 = (char *)0x471135;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_544 = s_BEAST_HP_MAX_ADD_009a2cec;
  pppppuStack_54c = &pppppuStack_530;
  pppppuStack_548 = (undefined4 *****)&DAT_009a371c;
  pcStack_550 = (char *)0x47114b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_530 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471171;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471171:
  pcVar4[0x100] = 'h';
  pcVar4[0x101] = '\0';
  pppppuStack_548 = (undefined4 *****)0x471183;
  pcStack_544 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_548 = (undefined4 *****)0x114;
    pppppuStack_54c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2d00;
    pppppuStack_554 = &pppppuStack_534;
    pcStack_550 = s_File___s__Line___d_009a2d28;
    pppppuStack_534 = (undefined4 *****)((uint)pppppuStack_534 & 0xffffff00);
    pppppuStack_558 = (undefined4 *****)0x4711a4;
    pppppuStack_558 = (undefined4 *****)FUN_0044a580();
    pcStack_55c = (char *)0x4711aa;
    FUN_00797b80();
    pppppuStack_548 = (undefined4 *****)0x4711b2;
    FUN_00797a40();
  }
  pppppuStack_548 = (undefined4 *****)0x0;
  pppppuStack_54c = (undefined4 *****)0x1;
  pcStack_550 = (char *)0x4711bd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_550 = s_BEAST_HP_MAX_MUL_009a2d3c;
  pppppuStack_558 = &pppppuStack_53c;
  pppppuStack_554 = (undefined4 *****)&DAT_009a371c;
  pcStack_55c = (char *)0x4711d3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_53c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004711f9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004711f9:
  pcVar4[0x100] = 'i';
  pcVar4[0x101] = '\0';
  pppppuStack_554 = (undefined4 *****)0x47120b;
  pcStack_550 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_554 = (undefined4 *****)0x115;
    pppppuStack_558 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2d50;
    pppppuStack_560 = &pppppuStack_540;
    pcStack_55c = s_File___s__Line___d_009a2d78;
    pppppuStack_540 = (undefined4 *****)((uint)pppppuStack_540 & 0xffffff00);
    pppppuStack_564 = (undefined4 *****)0x47122c;
    pppppuStack_564 = (undefined4 *****)FUN_0044a580();
    pcStack_568 = (char *)0x471232;
    FUN_00797b80();
    pppppuStack_554 = (undefined4 *****)0x47123a;
    FUN_00797a40();
  }
  pppppuStack_554 = (undefined4 *****)0x0;
  pppppuStack_558 = (undefined4 *****)0x1;
  pcStack_55c = (char *)0x471245;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_55c = s_BEAST_HP_RECOVERY_ADD_009a2d8c;
  pppppuStack_564 = &pppppuStack_548;
  pppppuStack_560 = (undefined4 *****)&DAT_009a371c;
  pcStack_568 = (char *)0x47125b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_548 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471281;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471281:
  pcVar4[0x100] = 'j';
  pcVar4[0x101] = '\0';
  pppppuStack_560 = (undefined4 *****)0x471293;
  pcStack_55c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_560 = (undefined4 *****)0x116;
    pppppuStack_564 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2da4;
    pppppuStack_56c = &pppppuStack_54c;
    pcStack_568 = s_File___s__Line___d_009a2dcc;
    pppppuStack_54c = (undefined4 *****)((uint)pppppuStack_54c & 0xffffff00);
    pppppuStack_570 = (undefined4 *****)0x4712b4;
    pppppuStack_570 = (undefined4 *****)FUN_0044a580();
    pcStack_574 = (char *)0x4712ba;
    FUN_00797b80();
    pppppuStack_560 = (undefined4 *****)0x4712c2;
    FUN_00797a40();
  }
  pppppuStack_560 = (undefined4 *****)0x0;
  pppppuStack_564 = (undefined4 *****)0x1;
  pcStack_568 = (char *)0x4712cd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_568 = s_BEAST_HP_RECOVERY_MUL_009a2de0;
  pppppuStack_570 = &pppppuStack_554;
  pppppuStack_56c = (undefined4 *****)&DAT_009a371c;
  pcStack_574 = (char *)0x4712e3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_554 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471309;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471309:
  pcVar4[0x100] = 'k';
  pcVar4[0x101] = '\0';
  pppppuStack_56c = (undefined4 *****)0x47131b;
  pcStack_568 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_56c = (undefined4 *****)0x117;
    pppppuStack_570 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2df8;
    pppppuStack_578 = &pppppuStack_558;
    pcStack_574 = s_File___s__Line___d_009a2e20;
    pppppuStack_558 = (undefined4 *****)((uint)pppppuStack_558 & 0xffffff00);
    pppppuStack_57c = (undefined4 *****)0x47133c;
    pppppuStack_57c = (undefined4 *****)FUN_0044a580();
    pcStack_580 = (char *)0x471342;
    FUN_00797b80();
    pppppuStack_56c = (undefined4 *****)0x47134a;
    FUN_00797a40();
  }
  pppppuStack_56c = (undefined4 *****)0x0;
  pppppuStack_570 = (undefined4 *****)0x1;
  pcStack_574 = (char *)0x471355;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_574 = s_BEAST_RATING_CRITICAL_ADD_009a2e34;
  pppppuStack_57c = &pppppuStack_560;
  pppppuStack_578 = (undefined4 *****)&DAT_009a371c;
  pcStack_580 = (char *)0x47136b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_560 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471391;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471391:
  pcVar4[0x100] = 'p';
  pcVar4[0x101] = '\0';
  pppppuStack_578 = (undefined4 *****)0x4713a3;
  pcStack_574 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_578 = (undefined4 *****)0x119;
    pppppuStack_57c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2e50;
    pppppuStack_584 = &pppppuStack_564;
    pcStack_580 = s_File___s__Line___d_009a2e78;
    pppppuStack_564 = (undefined4 *****)((uint)pppppuStack_564 & 0xffffff00);
    pppppuStack_588 = (undefined4 *****)0x4713c4;
    pppppuStack_588 = (undefined4 *****)FUN_0044a580();
    pcStack_58c = (char *)0x4713ca;
    FUN_00797b80();
    pppppuStack_578 = (undefined4 *****)0x4713d2;
    FUN_00797a40();
  }
  pppppuStack_578 = (undefined4 *****)0x0;
  pppppuStack_57c = (undefined4 *****)0x1;
  pcStack_580 = (char *)0x4713dd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_580 = s_BEAST_RATING_BLOCKING_ADD_009a2e8c;
  pppppuStack_588 = &pppppuStack_56c;
  pppppuStack_584 = (undefined4 *****)&DAT_009a371c;
  pcStack_58c = (char *)0x4713f3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_56c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471419;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471419:
  pcVar4[0x100] = 'q';
  pcVar4[0x101] = '\0';
  pppppuStack_584 = (undefined4 *****)0x47142b;
  pcStack_580 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_584 = (undefined4 *****)0x11a;
    pppppuStack_588 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2ea8;
    pppppuStack_590 = &pppppuStack_570;
    pcStack_58c = s_File___s__Line___d_009a2ed0;
    pppppuStack_570 = (undefined4 *****)((uint)pppppuStack_570 & 0xffffff00);
    pppppuStack_594 = (undefined4 *****)0x47144c;
    pppppuStack_594 = (undefined4 *****)FUN_0044a580();
    pcStack_598 = (char *)0x471452;
    FUN_00797b80();
    pppppuStack_584 = (undefined4 *****)0x47145a;
    FUN_00797a40();
  }
  pppppuStack_584 = (undefined4 *****)0x0;
  pppppuStack_588 = (undefined4 *****)0x1;
  pcStack_58c = (char *)0x471465;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_58c = s_BEAST_RATING_GUARD_ADD_009a2ee4;
  pppppuStack_594 = &pppppuStack_578;
  pppppuStack_590 = (undefined4 *****)&DAT_009a371c;
  pcStack_598 = (char *)0x47147b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_578 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004714a1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004714a1:
  pcVar4[0x100] = 'r';
  pcVar4[0x101] = '\0';
  pppppuStack_590 = (undefined4 *****)0x4714b3;
  pcStack_58c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_590 = (undefined4 *****)0x11b;
    pppppuStack_594 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2efc;
    pppppuStack_59c = &pppppuStack_57c;
    pcStack_598 = s_File___s__Line___d_009a2f24;
    pppppuStack_57c = (undefined4 *****)((uint)pppppuStack_57c & 0xffffff00);
    pppppuStack_5a0 = (undefined4 *****)0x4714d4;
    pppppuStack_5a0 = (undefined4 *****)FUN_0044a580();
    pcStack_5a4 = (char *)0x4714da;
    FUN_00797b80();
    pppppuStack_590 = (undefined4 *****)0x4714e2;
    FUN_00797a40();
  }
  pppppuStack_590 = (undefined4 *****)0x0;
  pppppuStack_594 = (undefined4 *****)0x1;
  pcStack_598 = (char *)0x4714ed;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_598 = s_BEAST_RESIST_FIRE_ADD_009a2f38;
  pppppuStack_5a0 = &pppppuStack_584;
  pppppuStack_59c = (undefined4 *****)&DAT_009a371c;
  pcStack_5a4 = (char *)0x471503;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_584 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471529;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471529:
  pcVar4[0x100] = 'x';
  pcVar4[0x101] = '\0';
  pppppuStack_59c = (undefined4 *****)0x47153b;
  pcStack_598 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_59c = (undefined4 *****)0x11d;
    pppppuStack_5a0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2f50;
    pppppuStack_5a8 = &pppppuStack_588;
    pcStack_5a4 = s_File___s__Line___d_009a2f78;
    pppppuStack_588 = (undefined4 *****)((uint)pppppuStack_588 & 0xffffff00);
    pppppuStack_5ac = (undefined4 *****)0x47155c;
    pppppuStack_5ac = (undefined4 *****)FUN_0044a580();
    pcStack_5b0 = (char *)0x471562;
    FUN_00797b80();
    pppppuStack_59c = (undefined4 *****)0x47156a;
    FUN_00797a40();
  }
  pppppuStack_59c = (undefined4 *****)0x0;
  pppppuStack_5a0 = (undefined4 *****)0x1;
  pcStack_5a4 = (char *)0x471575;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5a4 = s_BEAST_RESIST_ICE_ADD_009a2f8c;
  pppppuStack_5ac = &pppppuStack_590;
  pppppuStack_5a8 = (undefined4 *****)&DAT_009a371c;
  pcStack_5b0 = (char *)0x47158b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_590 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004715b1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004715b1:
  pcVar4[0x100] = 'y';
  pcVar4[0x101] = '\0';
  pppppuStack_5a8 = (undefined4 *****)0x4715c3;
  pcStack_5a4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5a8 = (undefined4 *****)0x11e;
    pppppuStack_5ac = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2fa4;
    pppppuStack_5b4 = &pppppuStack_594;
    pcStack_5b0 = s_File___s__Line___d_009a2fcc;
    pppppuStack_594 = (undefined4 *****)((uint)pppppuStack_594 & 0xffffff00);
    pppppuStack_5b8 = (undefined4 *****)0x4715e4;
    pppppuStack_5b8 = (undefined4 *****)FUN_0044a580();
    pcStack_5bc = (char *)0x4715ea;
    FUN_00797b80();
    pppppuStack_5a8 = (undefined4 *****)0x4715f2;
    FUN_00797a40();
  }
  pppppuStack_5a8 = (undefined4 *****)0x0;
  pppppuStack_5ac = (undefined4 *****)0x1;
  pcStack_5b0 = (char *)0x4715fd;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5b0 = s_BEAST_RESIST_LIGHTNING_ADD_009a2fe0;
  pppppuStack_5b8 = &pppppuStack_59c;
  pppppuStack_5b4 = (undefined4 *****)&DAT_009a371c;
  pcStack_5bc = (char *)0x471613;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_59c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471639;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471639:
  pcVar4[0x100] = 'z';
  pcVar4[0x101] = '\0';
  pppppuStack_5b4 = (undefined4 *****)0x47164b;
  pcStack_5b0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5b4 = (undefined4 *****)0x11f;
    pppppuStack_5b8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a2ffc;
    pppppuStack_5c0 = &pppppuStack_5a0;
    pcStack_5bc = s_File___s__Line___d_009a3024;
    pppppuStack_5a0 = (undefined4 *****)((uint)pppppuStack_5a0 & 0xffffff00);
    pppppuStack_5c4 = (undefined4 *****)0x47166c;
    pppppuStack_5c4 = (undefined4 *****)FUN_0044a580();
    pcStack_5c8 = (char *)0x471672;
    FUN_00797b80();
    pppppuStack_5b4 = (undefined4 *****)0x47167a;
    FUN_00797a40();
  }
  pppppuStack_5b4 = (undefined4 *****)0x0;
  pppppuStack_5b8 = (undefined4 *****)0x1;
  pcStack_5bc = (char *)0x471685;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5bc = s_BEAST_RESIST_POISON_ADD_009a3038;
  pppppuStack_5c4 = &pppppuStack_5a8;
  pppppuStack_5c0 = (undefined4 *****)&DAT_009a371c;
  pcStack_5c8 = (char *)0x47169b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5a8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004716c1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004716c1:
  pcVar4[0x100] = '{';
  pcVar4[0x101] = '\0';
  pppppuStack_5c0 = (undefined4 *****)0x4716d3;
  pcStack_5bc = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5c0 = (undefined4 *****)0x120;
    pppppuStack_5c4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3050;
    pppppuStack_5cc = &pppppuStack_5ac;
    pcStack_5c8 = s_File___s__Line___d_009a3078;
    pppppuStack_5ac = (undefined4 *****)((uint)pppppuStack_5ac & 0xffffff00);
    pppppuStack_5d0 = (undefined4 *****)0x4716f4;
    pppppuStack_5d0 = (undefined4 *****)FUN_0044a580();
    pcStack_5d4 = (char *)0x4716fa;
    FUN_00797b80();
    pppppuStack_5c0 = (undefined4 *****)0x471702;
    FUN_00797a40();
  }
  pppppuStack_5c0 = (undefined4 *****)0x0;
  pppppuStack_5c4 = (undefined4 *****)0x1;
  pcStack_5c8 = (char *)0x47170d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5c8 = s_BEAST_RESIST_CURSE_ADD_009a308c;
  pppppuStack_5d0 = &pppppuStack_5b4;
  pppppuStack_5cc = (undefined4 *****)&DAT_009a371c;
  pcStack_5d4 = (char *)0x471723;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5b4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471749;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471749:
  pcVar4[0x100] = '|';
  pcVar4[0x101] = '\0';
  pppppuStack_5cc = (undefined4 *****)0x47175b;
  pcStack_5c8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5cc = (undefined4 *****)0x121;
    pppppuStack_5d0 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a30a4;
    pppppuStack_5d8 = &pppppuStack_5b8;
    pcStack_5d4 = s_File___s__Line___d_009a30cc;
    pppppuStack_5b8 = (undefined4 *****)((uint)pppppuStack_5b8 & 0xffffff00);
    pppppuStack_5dc = (undefined4 *****)0x47177c;
    pppppuStack_5dc = (undefined4 *****)FUN_0044a580();
    pcStack_5e0 = (char *)0x471782;
    FUN_00797b80();
    pppppuStack_5cc = (undefined4 *****)0x47178a;
    FUN_00797a40();
  }
  pppppuStack_5cc = (undefined4 *****)0x0;
  pppppuStack_5d0 = (undefined4 *****)0x1;
  pcStack_5d4 = (char *)0x471795;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5d4 = s_BEAST_RESIST_MELEE_ADD_009a30e0;
  pppppuStack_5dc = &pppppuStack_5c0;
  pppppuStack_5d8 = (undefined4 *****)&DAT_009a371c;
  pcStack_5e0 = (char *)0x4717ab;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5c0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004717d1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004717d1:
  pcVar4[0x100] = '}';
  pcVar4[0x101] = '\0';
  pppppuStack_5d8 = (undefined4 *****)0x4717e3;
  pcStack_5d4 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5d8 = (undefined4 *****)0x122;
    pppppuStack_5dc = (undefined4 *****)s___Loader_Article_Facade_Provider_009a30f8;
    pppppuStack_5e4 = &pppppuStack_5c4;
    pcStack_5e0 = s_File___s__Line___d_009a3120;
    pppppuStack_5c4 = (undefined4 *****)((uint)pppppuStack_5c4 & 0xffffff00);
    pppppuStack_5e8 = (undefined4 *****)0x471804;
    pppppuStack_5e8 = (undefined4 *****)FUN_0044a580();
    pcStack_5ec = (char *)0x47180a;
    FUN_00797b80();
    pppppuStack_5d8 = (undefined4 *****)0x471812;
    FUN_00797a40();
  }
  pppppuStack_5d8 = (undefined4 *****)0x0;
  pppppuStack_5dc = (undefined4 *****)0x1;
  pcStack_5e0 = (char *)0x47181d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5e0 = s_BEAST_RESIST_RANGE_ADD_009a3134;
  pppppuStack_5e8 = &pppppuStack_5cc;
  pppppuStack_5e4 = (undefined4 *****)&DAT_009a371c;
  pcStack_5ec = (char *)0x471833;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5cc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471859;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471859:
  pcVar4[0x100] = '~';
  pcVar4[0x101] = '\0';
  pppppuStack_5e4 = (undefined4 *****)0x47186b;
  pcStack_5e0 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5e4 = (undefined4 *****)0x123;
    pppppuStack_5e8 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a314c;
    pppppuStack_5f0 = &pppppuStack_5d0;
    pcStack_5ec = s_File___s__Line___d_009a3174;
    pppppuStack_5d0 = (undefined4 *****)((uint)pppppuStack_5d0 & 0xffffff00);
    pppppuStack_5f4 = (undefined4 *****)0x47188c;
    pppppuStack_5f4 = (undefined4 *****)FUN_0044a580();
    pcStack_5f8 = (char *)0x471892;
    FUN_00797b80();
    pppppuStack_5e4 = (undefined4 *****)0x47189a;
    FUN_00797a40();
  }
  pppppuStack_5e4 = (undefined4 *****)0x0;
  pppppuStack_5e8 = (undefined4 *****)0x1;
  pcStack_5ec = (char *)0x4718a5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5ec = s_BEAST_RESIST_MAGIC_ADD_009a3188;
  pppppuStack_5f4 = &pppppuStack_5d8;
  pppppuStack_5f0 = (undefined4 *****)&DAT_009a371c;
  pcStack_5f8 = (char *)0x4718bb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5d8 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004718e1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004718e1:
  pcVar4[0x100] = '\x7f';
  pcVar4[0x101] = '\0';
  pppppuStack_5f0 = (undefined4 *****)0x4718f3;
  pcStack_5ec = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5f0 = (undefined4 *****)0x124;
    pppppuStack_5f4 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a31a0;
    pppppuStack_5fc = &pppppuStack_5dc;
    pcStack_5f8 = s_File___s__Line___d_009a31c8;
    pppppuStack_5dc = (undefined4 *****)((uint)pppppuStack_5dc & 0xffffff00);
    pppppuStack_600 = (undefined4 *****)0x471914;
    pppppuStack_600 = (undefined4 *****)FUN_0044a580();
    pcStack_604 = (char *)0x47191a;
    FUN_00797b80();
    pppppuStack_5f0 = (undefined4 *****)0x471922;
    FUN_00797a40();
  }
  pppppuStack_5f0 = (undefined4 *****)0x0;
  pppppuStack_5f4 = (undefined4 *****)0x1;
  pcStack_5f8 = (char *)0x47192d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_5f8 = s_LIBIDO_HP_MAX_ADD_009a31dc;
  pppppuStack_600 = &pppppuStack_5e4;
  pppppuStack_5fc = (undefined4 *****)&DAT_009a371c;
  pcStack_604 = (char *)0x471943;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5e4 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471969;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471969:
  pcVar4[0x100] = -0x80;
  pcVar4[0x101] = '\0';
  pppppuStack_5fc = (undefined4 *****)0x47197b;
  pcStack_5f8 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_5fc = (undefined4 *****)0x126;
    pppppuStack_600 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a31f0;
    pppppuStack_608 = &pppppuStack_5e8;
    pcStack_604 = s_File___s__Line___d_009a3218;
    pppppuStack_5e8 = (undefined4 *****)((uint)pppppuStack_5e8 & 0xffffff00);
    pppppuStack_60c = (undefined4 *****)0x47199c;
    pppppuStack_60c = (undefined4 *****)FUN_0044a580();
    pcStack_610 = (char *)0x4719a2;
    FUN_00797b80();
    pppppuStack_5fc = (undefined4 *****)0x4719aa;
    FUN_00797a40();
  }
  pppppuStack_5fc = (undefined4 *****)0x0;
  pppppuStack_600 = (undefined4 *****)0x1;
  pcStack_604 = (char *)0x4719b5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_604 = s_LIBIDO_HP_MAX_MUL_009a322c;
  pppppuStack_60c = &pppppuStack_5f0;
  pppppuStack_608 = (undefined4 *****)&DAT_009a371c;
  pcStack_610 = (char *)0x4719cb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5f0 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004719f1;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004719f1:
  pcVar4[0x100] = -0x7f;
  pcVar4[0x101] = '\0';
  pppppuStack_608 = (undefined4 *****)0x471a03;
  pcStack_604 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_608 = (undefined4 *****)0x127;
    pppppuStack_60c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3240;
    pppppuStack_614 = &pppppuStack_5f4;
    pcStack_610 = s_File___s__Line___d_009a3268;
    pppppuStack_5f4 = (undefined4 *****)((uint)pppppuStack_5f4 & 0xffffff00);
    pppppuStack_618 = (undefined4 *****)0x471a24;
    pppppuStack_618 = (undefined4 *****)FUN_0044a580();
    pcStack_61c = (char *)0x471a2a;
    FUN_00797b80();
    pppppuStack_608 = (undefined4 *****)0x471a32;
    FUN_00797a40();
  }
  pppppuStack_608 = (undefined4 *****)0x0;
  pppppuStack_60c = (undefined4 *****)0x1;
  pcStack_610 = (char *)0x471a3d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_610 = s_LIBIDO_HP_RECOVERY_ADD_009a327c;
  pppppuStack_618 = &pppppuStack_5fc;
  pppppuStack_614 = (undefined4 *****)&DAT_009a371c;
  pcStack_61c = (char *)0x471a53;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_5fc - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471a79;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471a79:
  pcVar4[0x100] = -0x7e;
  pcVar4[0x101] = '\0';
  pppppuStack_614 = (undefined4 *****)0x471a8b;
  pcStack_610 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_614 = (undefined4 *****)0x128;
    pppppuStack_618 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3294;
    pppppuStack_620 = &pppppuStack_600;
    pcStack_61c = s_File___s__Line___d_009a32bc;
    pppppuStack_600 = (undefined4 *****)((uint)pppppuStack_600 & 0xffffff00);
    pppppuStack_624 = (undefined4 *****)0x471aac;
    pppppuStack_624 = (undefined4 *****)FUN_0044a580();
    pcStack_628 = (char *)0x471ab2;
    FUN_00797b80();
    pppppuStack_614 = (undefined4 *****)0x471aba;
    FUN_00797a40();
  }
  pppppuStack_614 = (undefined4 *****)0x0;
  pppppuStack_618 = (undefined4 *****)0x1;
  pcStack_61c = (char *)0x471ac5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_61c = s_LIBIDO_HP_RECOVERY_MUL_009a32d0;
  pppppuStack_624 = &pppppuStack_608;
  pppppuStack_620 = (undefined4 *****)&DAT_009a371c;
  pcStack_628 = (char *)0x471adb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_608 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471b01;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471b01:
  pcVar4[0x100] = -0x7d;
  pcVar4[0x101] = '\0';
  pppppuStack_620 = (undefined4 *****)0x471b13;
  pcStack_61c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_620 = (undefined4 *****)0x129;
    pppppuStack_624 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a32e8;
    pppppuStack_62c = &pppppuStack_60c;
    pcStack_628 = s_File___s__Line___d_009a3310;
    pppppuStack_60c = (undefined4 *****)((uint)pppppuStack_60c & 0xffffff00);
    pppppuStack_630 = (undefined4 *****)0x471b34;
    pppppuStack_630 = (undefined4 *****)FUN_0044a580();
    pcStack_634 = (char *)0x471b3a;
    FUN_00797b80();
    pppppuStack_620 = (undefined4 *****)0x471b42;
    FUN_00797a40();
  }
  pppppuStack_620 = (undefined4 *****)0x0;
  pppppuStack_624 = (undefined4 *****)0x1;
  pcStack_628 = (char *)0x471b4d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_628 = s_LIBIDO_RATING_CRITICAL_ADD_009a3324;
  pppppuStack_630 = &pppppuStack_614;
  pppppuStack_62c = (undefined4 *****)&DAT_009a371c;
  pcStack_634 = (char *)0x471b63;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_614 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471b89;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471b89:
  pcVar4[0x100] = -0x78;
  pcVar4[0x101] = '\0';
  pppppuStack_62c = (undefined4 *****)0x471b9b;
  pcStack_628 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_62c = (undefined4 *****)0x12b;
    pppppuStack_630 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3340;
    pppppuStack_638 = &pppppuStack_618;
    pcStack_634 = s_File___s__Line___d_009a3368;
    pppppuStack_618 = (undefined4 *****)((uint)pppppuStack_618 & 0xffffff00);
    pppppuStack_63c = (undefined4 *****)0x471bbc;
    pppppuStack_63c = (undefined4 *****)FUN_0044a580();
    pcStack_640 = (char *)0x471bc2;
    FUN_00797b80();
    pppppuStack_62c = (undefined4 *****)0x471bca;
    FUN_00797a40();
  }
  pppppuStack_62c = (undefined4 *****)0x0;
  pppppuStack_630 = (undefined4 *****)0x1;
  pcStack_634 = (char *)0x471bd5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_634 = s_LIBIDO_RATING_BLOCKING_ADD_009a337c;
  pppppuStack_63c = &pppppuStack_620;
  pppppuStack_638 = (undefined4 *****)&DAT_009a371c;
  pcStack_640 = (char *)0x471beb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_620 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471c11;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471c11:
  pcVar4[0x100] = -0x77;
  pcVar4[0x101] = '\0';
  pppppuStack_638 = (undefined4 *****)0x471c23;
  pcStack_634 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_638 = (undefined4 *****)0x12c;
    pppppuStack_63c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3398;
    pppppuStack_644 = &pppppuStack_624;
    pcStack_640 = s_File___s__Line___d_009a33c0;
    pppppuStack_624 = (undefined4 *****)((uint)pppppuStack_624 & 0xffffff00);
    pppppuStack_648 = (undefined4 *****)0x471c44;
    pppppuStack_648 = (undefined4 *****)FUN_0044a580();
    pcStack_64c = (char *)0x471c4a;
    FUN_00797b80();
    pppppuStack_638 = (undefined4 *****)0x471c52;
    FUN_00797a40();
  }
  pppppuStack_638 = (undefined4 *****)0x0;
  pppppuStack_63c = (undefined4 *****)0x1;
  pcStack_640 = (char *)0x471c5d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_640 = s_LIBIDO_RATING_GUARD_ADD_009a33d4;
  pppppuStack_648 = &pppppuStack_62c;
  pppppuStack_644 = (undefined4 *****)&DAT_009a371c;
  pcStack_64c = (char *)0x471c73;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_62c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471c99;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471c99:
  pcVar4[0x100] = -0x76;
  pcVar4[0x101] = '\0';
  pppppuStack_644 = (undefined4 *****)0x471cab;
  pcStack_640 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_644 = (undefined4 *****)0x12d;
    pppppuStack_648 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a33ec;
    pppppuStack_650 = &pppppuStack_630;
    pcStack_64c = s_File___s__Line___d_009a3414;
    pppppuStack_630 = (undefined4 *****)((uint)pppppuStack_630 & 0xffffff00);
    pppppuStack_654 = (undefined4 *****)0x471ccc;
    pppppuStack_654 = (undefined4 *****)FUN_0044a580();
    pcStack_658 = (char *)0x471cd2;
    FUN_00797b80();
    pppppuStack_644 = (undefined4 *****)0x471cda;
    FUN_00797a40();
  }
  pppppuStack_644 = (undefined4 *****)0x0;
  pppppuStack_648 = (undefined4 *****)0x1;
  pcStack_64c = (char *)0x471ce5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_64c = s_LIBIDO_RESIST_FIRE_ADD_009a3428;
  pppppuStack_654 = &pppppuStack_638;
  pppppuStack_650 = (undefined4 *****)&DAT_009a371c;
  pcStack_658 = (char *)0x471cfb;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_638 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471d21;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471d21:
  pcVar4[0x100] = -0x70;
  pcVar4[0x101] = '\0';
  pppppuStack_650 = (undefined4 *****)0x471d33;
  pcStack_64c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_650 = (undefined4 *****)0x12f;
    pppppuStack_654 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3440;
    pppppuStack_65c = &pppppuStack_63c;
    pcStack_658 = s_File___s__Line___d_009a3468;
    pppppuStack_63c = (undefined4 *****)((uint)pppppuStack_63c & 0xffffff00);
    pppppuStack_660 = (undefined4 *****)0x471d54;
    pppppuStack_660 = (undefined4 *****)FUN_0044a580();
    pcStack_664 = (char *)0x471d5a;
    FUN_00797b80();
    pppppuStack_650 = (undefined4 *****)0x471d62;
    FUN_00797a40();
  }
  pppppuStack_650 = (undefined4 *****)0x0;
  pppppuStack_654 = (undefined4 *****)0x1;
  pcStack_658 = (char *)0x471d6d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_658 = s_LIBIDO_RESIST_ICE_ADD_009a347c;
  pppppuStack_660 = &pppppuStack_644;
  pppppuStack_65c = (undefined4 *****)&DAT_009a371c;
  pcStack_664 = (char *)0x471d83;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_644 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471da9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471da9:
  pcVar4[0x100] = -0x6f;
  pcVar4[0x101] = '\0';
  pppppuStack_65c = (undefined4 *****)0x471dbb;
  pcStack_658 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_65c = (undefined4 *****)0x130;
    pppppuStack_660 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3494;
    pppppuStack_668 = &pppppuStack_648;
    pcStack_664 = s_File___s__Line___d_009a34bc;
    pppppuStack_648 = (undefined4 *****)((uint)pppppuStack_648 & 0xffffff00);
    pppppuStack_66c = (undefined4 *****)0x471ddc;
    pppppuStack_66c = (undefined4 *****)FUN_0044a580();
    pcStack_670 = (char *)0x471de2;
    FUN_00797b80();
    pppppuStack_65c = (undefined4 *****)0x471dea;
    FUN_00797a40();
  }
  pppppuStack_65c = (undefined4 *****)0x0;
  pppppuStack_660 = (undefined4 *****)0x1;
  pcStack_664 = (char *)0x471df5;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_664 = s_LIBIDO_RESIST_LIGHTNING_ADD_009a34d0;
  pppppuStack_66c = &pppppuStack_650;
  pppppuStack_668 = (undefined4 *****)&DAT_009a371c;
  pcStack_670 = (char *)0x471e0b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_650 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471e31;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471e31:
  pcVar4[0x100] = -0x6e;
  pcVar4[0x101] = '\0';
  pppppuStack_668 = (undefined4 *****)0x471e43;
  pcStack_664 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_668 = (undefined4 *****)0x131;
    pppppuStack_66c = (undefined4 *****)s___Loader_Article_Facade_Provider_009a34ec;
    pppppuStack_674 = &pppppuStack_654;
    pcStack_670 = s_File___s__Line___d_009a3514;
    pppppuStack_654 = (undefined4 *****)((uint)pppppuStack_654 & 0xffffff00);
    pppppuStack_678 = (undefined4 *****)0x471e64;
    pppppuStack_678 = (undefined4 *****)FUN_0044a580();
    pcStack_67c = (char *)0x471e6a;
    FUN_00797b80();
    pppppuStack_668 = (undefined4 *****)0x471e72;
    FUN_00797a40();
  }
  pppppuStack_668 = (undefined4 *****)0x0;
  pppppuStack_66c = (undefined4 *****)0x1;
  pcStack_670 = (char *)0x471e7d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_670 = s_LIBIDO_RESIST_POISON_ADD_009a3528;
  pppppuStack_678 = &pppppuStack_65c;
  pppppuStack_674 = (undefined4 *****)&DAT_009a371c;
  pcStack_67c = (char *)0x471e93;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_65c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471eb9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471eb9:
  pcVar4[0x100] = -0x6d;
  pcVar4[0x101] = '\0';
  pppppuStack_674 = (undefined4 *****)0x471ecb;
  pcStack_670 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_674 = (undefined4 *****)0x132;
    pppppuStack_678 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3544;
    pppppuStack_680 = &pppppuStack_660;
    pcStack_67c = s_File___s__Line___d_009a356c;
    pppppuStack_660 = (undefined4 *****)((uint)pppppuStack_660 & 0xffffff00);
    pppppuStack_684 = (undefined4 *****)0x471eec;
    pppppuStack_684 = (undefined4 *****)FUN_0044a580();
    pcStack_688 = (char *)0x471ef2;
    FUN_00797b80();
    pppppuStack_674 = (undefined4 *****)0x471efa;
    FUN_00797a40();
  }
  pppppuStack_674 = (undefined4 *****)0x0;
  pppppuStack_678 = (undefined4 *****)0x1;
  pcStack_67c = (char *)0x471f05;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_67c = s_LIBIDO_RESIST_CURSE_ADD_009a3580;
  pppppuStack_684 = &pppppuStack_668;
  pppppuStack_680 = (undefined4 *****)&DAT_009a371c;
  pcStack_688 = (char *)0x471f1b;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_668 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471f41;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471f41:
  pcVar4[0x100] = -0x6c;
  pcVar4[0x101] = '\0';
  pppppuStack_680 = (undefined4 *****)0x471f53;
  pcStack_67c = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_680 = (undefined4 *****)0x133;
    pppppuStack_684 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a3598;
    pppppuStack_68c = &pppppuStack_66c;
    pcStack_688 = s_File___s__Line___d_009a35c0;
    pppppuStack_66c = (undefined4 *****)((uint)pppppuStack_66c & 0xffffff00);
    pppppuStack_690 = (undefined4 *****)0x471f74;
    pppppuStack_690 = (undefined4 *****)FUN_0044a580();
    pcStack_694 = (char *)0x471f7a;
    FUN_00797b80();
    pppppuStack_680 = (undefined4 *****)0x471f82;
    FUN_00797a40();
  }
  pppppuStack_680 = (undefined4 *****)0x0;
  pppppuStack_684 = (undefined4 *****)0x1;
  pcStack_688 = (char *)0x471f8d;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_688 = s_LIBIDO_RESIST_MELEE_ADD_009a35d4;
  pppppuStack_690 = &pppppuStack_674;
  pppppuStack_68c = (undefined4 *****)&DAT_009a371c;
  pcStack_694 = (char *)0x471fa3;
  FUN_0044a580();
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_674 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00471fc9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00471fc9:
  pcVar4[0x100] = -0x6b;
  pcVar4[0x101] = '\0';
  pppppuStack_68c = (undefined4 *****)0x471fdb;
  pcStack_688 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_68c = (undefined4 *****)0x134;
    pppppuStack_690 = (undefined4 *****)s___Loader_Article_Facade_Provider_009a35ec;
    pppppuStack_698 = &pppppuStack_678;
    pcStack_694 = s_File___s__Line___d_009a3614;
    pppppuStack_678 = (undefined4 *****)((uint)pppppuStack_678 & 0xffffff00);
    uVar3 = FUN_0044a580();
    FUN_00797b80(uVar3);
    pppppuStack_68c = (undefined4 *****)0x47200a;
    FUN_00797a40();
  }
  pppppuStack_68c = (undefined4 *****)0x0;
  pppppuStack_690 = (undefined4 *****)0x1;
  pcStack_694 = (char *)0x472015;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pcStack_694 = s_LIBIDO_RESIST_RANGE_ADD_009a3628;
  pppppuStack_698 = (undefined4 *****)&DAT_009a371c;
  FUN_0044a580(&pppppuStack_680);
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_680 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00472051;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00472051:
  pcVar4[0x100] = -0x6a;
  pcVar4[0x101] = '\0';
  pppppuStack_698 = (undefined4 *****)0x472063;
  pcStack_694 = pcVar4;
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  if (iVar6 != 0) {
    pppppuStack_698 = (undefined4 *****)0x135;
    pppppuStack_684 = (undefined4 *****)((uint)pppppuStack_684 & 0xffffff00);
    uVar3 = FUN_0044a580(&pppppuStack_684,s_File___s__Line___d_009a3668,
                         s___Loader_Article_Facade_Provider_009a3640);
    FUN_00797b80(uVar3);
    pppppuStack_698 = (undefined4 *****)0x472092;
    FUN_00797a40();
  }
  pppppuStack_698 = (undefined4 *****)0x0;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1);
  FUN_0044a580(&pppppuStack_68c,&DAT_009a371c,s_LIBIDO_RESIST_MAGIC_ADD_009a367c);
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_68c - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_004720d9;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_004720d9:
  pcVar4[0x100] = -0x69;
  pcVar4[0x101] = '\0';
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(pcVar4);
  if (iVar6 != 0) {
    pppppuStack_690 = (undefined4 *****)((uint)pppppuStack_690 & 0xffffff00);
    uVar3 = FUN_0044a580(&pppppuStack_690,s_File___s__Line___d_009a36bc,
                         s___Loader_Article_Facade_Provider_009a3694,0x136);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_0044a580(&pppppuStack_698,&DAT_009a371c,s_SKILL_USESKILL_009a36d0);
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)&pppppuStack_698 - (int)pcVar4];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00472161;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x100);
  *pcVar4 = '\0';
LAB_00472161:
  pcVar4[0x100] = -0x68;
  pcVar4[0x101] = '\0';
  iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(pcVar4);
  if (iVar6 != 0) {
    pcStack_598 = (char *)((uint)pcStack_598 & 0xffffff00);
    uVar3 = FUN_0044a580(&pcStack_598,s_File___s__Line___d_009a3708,
                         s___Loader_Article_Facade_Provider_009a36e0,0x138);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  ExceptionList = pppppuStack_498;
  return;
}


