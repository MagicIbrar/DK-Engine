// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x700000-0x70ffff

// ==== FUN_00700060 @ 0x00700060 ====

void FUN_00700060(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  
  piVar3 = param_1;
  piVar4 = *(int **)(in_ECX + 0x10);
  if (piVar4 != *(int **)(in_ECX + 0x14)) {
    do {
      iVar1 = *piVar4;
      if (((*(char *)(iVar1 + 4) == (char)param_1[1]) &&
          (*(char *)(iVar1 + 5) == *(char *)((int)param_1 + 5))) &&
         (*(char *)(iVar1 + 6) == *(char *)((int)param_1 + 6))) {
        return;
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(in_ECX + 0x14));
  }
  if ((*param_1 != 0) &&
     ((*(int *)(in_ECX + 0x10) == 0 ||
      ((uint)(*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10) >> 2) < 5)))) {
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
    iVar1 = *(int *)(in_ECX + 0x10);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)
       )) {
      FUN_007002a0(*(undefined4 *)(in_ECX + 0x14),1,&param_1);
    }
    else {
      puVar2 = *(undefined4 **)(in_ECX + 0x14);
      *puVar2 = param_1;
      *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
    }
    iVar1 = *(int *)(in_ECX + 0x20);
    param_1 = (int *)0x1;
    if ((iVar1 != 0) &&
       ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) < (uint)(*(int *)(in_ECX + 0x28) - iVar1 >> 2))
       ) {
      puVar2 = *(undefined4 **)(in_ECX + 0x24);
      *puVar2 = 1;
      *(undefined4 **)(in_ECX + 0x24) = puVar2 + 1;
      return;
    }
    FUN_007002a0(*(undefined4 *)(in_ECX + 0x24),1,&param_1);
  }
  return;
}


// ==== FUN_007001a0 @ 0x007001a0 ====

void FUN_007001a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006ffdd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007001c0 @ 0x007001c0 ====

void FUN_007001c0(void)

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
  puStack_8 = &LAB_0098e678;
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


// ==== FUN_00700230 @ 0x00700230 ====

void FUN_00700230(void)

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
  puStack_8 = &LAB_0098e678;
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


// ==== FUN_007002a0 @ 0x007002a0 ====

void FUN_007002a0(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00700230();
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


// ==== FUN_00700480 @ 0x00700480 ====

void FUN_00700480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e99e4;
  return;
}


// ==== FUN_00700490 @ 0x00700490 ====

void FUN_00700490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e99e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007004b0 @ 0x007004b0 ====

void FUN_007004b0(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 5) {
    (**(code **)(**(int **)(in_ECX + 4 + param_1 * 4) + 0x14))();
  }
  return;
}


// ==== FUN_007004d0 @ 0x007004d0 ====

int FUN_007004d0(void)

{
  int in_ECX;
  
  return in_ECX + 0x1c;
}


// ==== FUN_007004e0 @ 0x007004e0 ====

void FUN_007004e0(void)

{
  int *piVar1;
  void *pvVar2;
  int in_ECX;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098e6e7;
  pvStack_c = ExceptionList;
  local_28 = 0;
  local_24 = 0;
  local_20 = (void *)0x64;
  local_1c = 100;
  local_14 = 0;
  local_10 = local_10 & 0xffffff00;
  local_18 = 15000;
  ExceptionList = &pvStack_c;
  local_2c = operator_new(0xc);
  local_4 = 0;
  if (local_2c == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00788220();
  }
  local_20 = (void *)0x280;
  local_28 = 0xc0;
  local_1c = 0x140;
  *(int **)(in_ECX + 4) = piVar1;
  local_24 = 0xe0;
  local_14 = 0;
  local_10 = CONCAT31(local_10._1_3_,1);
  local_4 = 0xffffffff;
  (**(code **)(*piVar1 + 8))(&local_28);
  pvVar2 = operator_new(0xc);
  puStack_8 = (undefined1 *)0x1;
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00788220();
  }
  local_24 = 0x280;
  local_2c = (void *)0xc0;
  local_20 = (void *)0x140;
  *(int **)(in_ECX + 8) = piVar1;
  local_28 = 0xe0;
  local_18 = 1;
  local_14 = CONCAT31(local_14._1_3_,1);
  puStack_8 = (undefined1 *)0xffffffff;
  (**(code **)(*piVar1 + 8))(&local_2c);
  pvVar2 = operator_new(0xc);
  pvStack_c = (void *)0x2;
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00788220();
  }
  local_28 = 400;
  local_24 = 300;
  *(int **)(in_ECX + 0xc) = piVar1;
  local_2c = (void *)0x50;
  local_1c = 2;
  local_18 = local_18 & 0xffffff00;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar1 + 8))((int)register0x00000010 + -0x30);
  pvVar2 = operator_new(0xc);
  local_10 = 3;
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00788220();
  }
  local_2c = (void *)0x190;
  local_28 = 300;
  *(int **)(in_ECX + 0x10) = piVar1;
  local_20 = (void *)0x3;
  local_1c = local_1c & 0xffffff00;
  local_10 = 0xffffffff;
  (**(code **)(*piVar1 + 8))((int)register0x00000010 + -0x34);
  pvVar2 = operator_new(0xc);
  local_14 = 4;
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00788220();
  }
  local_2c = (void *)0x80;
  *(int **)(in_ECX + 0x14) = piVar1;
  local_24 = 4;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  local_14 = 0xffffffff;
  (**(code **)(*piVar1 + 8))((int)register0x00000010 + -0x38);
  ExceptionList = local_20;
  return;
}


// ==== FUN_00700740 @ 0x00700740 ====

undefined4 FUN_00700740(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 5) {
    return *(undefined4 *)(in_ECX + 4 + param_1 * 4);
  }
  return 0;
}


// ==== FUN_00700760 @ 0x00700760 ====

void FUN_00700760(uint param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if ((iVar1 == 3) &&
     (((param_1 != 4 || ((char)in_ECX[6] == '\0')) && ((**(code **)(*in_ECX + 0x10))(), param_1 < 5)
      ))) {
    (**(code **)(*(int *)in_ECX[param_1 + 1] + 0x10))();
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_007007b0 @ 0x007007b0 ====

void FUN_007007b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098e6f9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if ((iVar1 == 3) && (*(char *)(in_ECX + 0x18) != '\0')) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009e9a10;
    }
    FUN_00797a20(puVar2);
    (**(code **)(*DAT_00b5a830 + 0xc))();
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_rc_ppl_off_009e99d4,10);
    uStack_4 = 0;
    (**(code **)(*DAT_00b5a688 + 4))(auStack_28);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    *(undefined1 *)(in_ECX + 0x18) = 0;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00700870 @ 0x00700870 ====

void FUN_00700870(void)

{
  int in_ECX;
  
  FUN_00700fc0(*(undefined4 *)(*(int *)(in_ECX + 0x20) + 4));
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  return;
}


// ==== FUN_007008a0 @ 0x007008a0 ====

void FUN_007008a0(undefined1 param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  int in_stack_0000003c;
  int local_50 [17];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098e71b;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_00857e00(local_50,&param_1);
  if (local_50[0] == *(int *)(in_ECX + 0x20)) {
    uVar1 = FUN_00700c50(&param_1,&uStack00000020);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_00701340(local_50,uVar1);
    FUN_0040a7d0();
  }
  else {
    *(int *)(local_50[0] + 0x44) = *(int *)(local_50[0] + 0x44) + in_stack_0000003c;
  }
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  in_stack_0000001c = 0xf;
  in_stack_00000018 = 0;
  param_2 = (void *)((uint)param_2 & 0xffffff00);
  if (in_stack_00000038 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_00700970 @ 0x00700970 ====

void FUN_00700970(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  undefined1 auStack_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098e738;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009e9a24;
  local_4 = 1;
  iVar1 = 5;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    *piVar2 = 0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  DAT_00b5a838 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_00701280(auStack_10,*(undefined4 *)in_ECX[8],(undefined4 *)in_ECX[8]);
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_00700a20 @ 0x00700a20 ====

void FUN_00700a20(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098e755;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009e9a24;
  iVar1 = FUN_00700b90();
  in_ECX[8] = iVar1;
  *(undefined1 *)(iVar1 + 0x49) = 1;
  *(undefined4 *)(in_ECX[8] + 4) = in_ECX[8];
  *(undefined4 *)in_ECX[8] = in_ECX[8];
  *(undefined4 *)(in_ECX[8] + 8) = in_ECX[8];
  in_ECX[9] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a838 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a838 = in_ECX;
  }
  FUN_007004e0();
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined1 *)((int)in_ECX + 0x19) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00700ab0 @ 0x00700ab0 ====

void FUN_00700ab0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x49) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x49) == '\0');
  }
  return;
}


// ==== FUN_00700ad0 @ 0x00700ad0 ====

void FUN_00700ad0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x49) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x49) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x49);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x49);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x49);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x49);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00700b20 @ 0x00700b20 ====

undefined4 FUN_00700b20(void)

{
  return 0x70940003;
}


// ==== FUN_00700b30 @ 0x00700b30 ====

void FUN_00700b30(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x49) == '\0') {
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


// ==== FUN_00700b90 @ 0x00700b90 ====

void FUN_00700b90(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x4c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x12) = 1;
  *(undefined1 *)((int)puVar1 + 0x49) = 0;
  return;
}


// ==== FUN_00700bd0 @ 0x00700bd0 ====

void FUN_00700bd0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098e768;
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
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x38);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00700c50 @ 0x00700c50 ====

void FUN_00700c50(undefined4 param_1,int param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098e768;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_2 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00700cd0 @ 0x00700cd0 ====

/* WARNING: Removing unreachable block (ram,0x00700ddd) */
/* WARNING: Removing unreachable block (ram,0x00700ded) */
/* WARNING: Removing unreachable block (ram,0x00700df6) */
/* WARNING: Removing unreachable block (ram,0x00700df9) */
/* WARNING: Removing unreachable block (ram,0x00700de9) */
/* WARNING: Removing unreachable block (ram,0x00700e07) */
/* WARNING: Removing unreachable block (ram,0x00700e14) */
/* WARNING: Removing unreachable block (ram,0x00700e1f) */
/* WARNING: Removing unreachable block (ram,0x00700e1b) */
/* WARNING: Removing unreachable block (ram,0x00700e0f) */
/* WARNING: Removing unreachable block (ram,0x00700e22) */

void FUN_00700cd0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0098e7a8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x49) != '\0') {
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
  FUN_00700ad0();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x49) == '\0') {
    if (*(char *)(param_2[2] + 0x49) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x49) == '\0') {
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
    if (*(char *)((int)piVar5 + 0x49) == '\0') {
      piVar3 = (int *)FUN_006830e0(piVar5);
    }
    else {
      piVar3 = piVar6;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x49) == '\0') {
      uVar4 = FUN_00700ab0(piVar5);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar6;
    }
  }
  if ((char)param_2[0x12] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        if ((char)piVar5[0x12] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x12] == '\0') {
            *(undefined1 *)(piVar3 + 0x12) = 1;
            *(undefined1 *)(piVar6 + 0x12) = 0;
            FUN_00857bf0(piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x49) == '\0') {
            if ((*(char *)(*piVar3 + 0x48) == '\x01') && (*(char *)(piVar3[2] + 0x48) == '\x01'))
            goto LAB_00700ef4;
            if (*(char *)(piVar3[2] + 0x48) == '\x01') {
              *(undefined1 *)(*piVar3 + 0x48) = 1;
              *(undefined1 *)(piVar3 + 0x12) = 0;
              FUN_00700b30(piVar3);
              piVar3 = (int *)piVar6[2];
            }
            *(char *)(piVar3 + 0x12) = (char)piVar6[0x12];
            *(undefined1 *)(piVar6 + 0x12) = 1;
            *(undefined1 *)(piVar3[2] + 0x48) = 1;
            FUN_00857bf0(piVar6);
            break;
          }
        }
        else {
          if ((char)piVar3[0x12] == '\0') {
            *(undefined1 *)(piVar3 + 0x12) = 1;
            *(undefined1 *)(piVar6 + 0x12) = 0;
            FUN_00700b30(piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x49) == '\0') {
            if ((*(char *)(piVar3[2] + 0x48) != '\x01') || (*(char *)(*piVar3 + 0x48) != '\x01')) {
              if (*(char *)(*piVar3 + 0x48) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x48) = 1;
                *(undefined1 *)(piVar3 + 0x12) = 0;
                FUN_00857bf0(piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 0x12) = (char)piVar6[0x12];
              *(undefined1 *)(piVar6 + 0x12) = 1;
              *(undefined1 *)(*piVar3 + 0x48) = 1;
              FUN_00700b30(piVar6);
              break;
            }
LAB_00700ef4:
            *(undefined1 *)(piVar3 + 0x12) = 0;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x12) = 1;
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


// ==== FUN_00700fc0 @ 0x00700fc0 ====

void FUN_00700fc0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x49) == '\0') {
    FUN_00700fc0(*(undefined4 *)((int)param_1 + 8));
    FUN_004107d0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00701000 @ 0x00701000 ====

undefined4 *
FUN_00701000(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098e791;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x4c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_00700bd0(param_4);
    *(undefined1 *)(puVar1 + 0x12) = param_5;
    *(undefined1 *)((int)puVar1 + 0x49) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0070107e @ 0x0070107e ====

void Catch_0070107e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_007010a0 @ 0x007010a0 ====

void FUN_007010a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0098e7a8;
  local_c = ExceptionList;
  if (0x4444442 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00701000(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x48);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x48) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x12] == '\0') {
LAB_00701199:
        *(undefined1 *)(*piVar5 + 0x48) = 1;
        *(undefined1 *)(piVar6 + 0x12) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x48) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00857bf0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x48) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x48) = 0;
        FUN_00700b30(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x12] == '\0') goto LAB_00701199;
      if (piVar7 == (int *)*piVar2) {
        FUN_00700b30(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x48) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x48) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x49) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x48);
  } while( true );
}


// ==== FUN_00701280 @ 0x00701280 ====

void FUN_00701280(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00700fc0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x49) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x49) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x49);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x49);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x49);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x49);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00700cd0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00701340 @ 0x00701340 ====

/* WARNING: Removing unreachable block (ram,0x0070139f) */

void FUN_00701340(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x49) == '\0') {
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
LAB_007013d0:
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
        if (uVar5 == 0) goto LAB_007013d0;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x49) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_007010a0(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00857c40();
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
    puVar6 = (undefined4 *)FUN_007010a0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_007014b0 @ 0x007014b0 ====

void FUN_007014b0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00701280(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_007014e0 @ 0x007014e0 ====

undefined1 FUN_007014e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x19);
}


// ==== FUN_007014f0 @ 0x007014f0 ====

void FUN_007014f0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x19) = param_1;
  return;
}


// ==== FUN_00701500 @ 0x00701500 ====

void FUN_00701500(byte param_1)

{
  void *in_ECX;
  
  FUN_00700970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00701520 @ 0x00701520 ====

void FUN_00701520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9aa4;
  return;
}


// ==== FUN_00701530 @ 0x00701530 ====

void FUN_00701530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9aa4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00701550 @ 0x00701550 ====

void FUN_00701550(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098e7c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009e9ab8;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  in_ECX[1] = uVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a834 = (undefined4 *)0x0;
    ExceptionList = pvStack_c;
    return;
  }
  DAT_00b5a834 = in_ECX;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_007015d0 @ 0x007015d0 ====

void FUN_007015d0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  DAT_00b5a834 = 0;
  *in_ECX = &PTR_FUN_009e9aa4;
  return;
}


// ==== FUN_007015f0 @ 0x007015f0 ====

void FUN_007015f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 auStack_64 [24];
  char cStack_1;
  
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 3) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
    puVar5 = auStack_64;
    for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    if (cStack_1 != '\0') {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x5330000;
      *(undefined2 *)((int)pvVar4 + 6) = 0x10;
      uVar3 = FUN_004244d0();
      FUN_004d8570(uVar3);
    }
  }
  return;
}


// ==== FUN_00701670 @ 0x00701670 ====

void FUN_00701670(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098e7da;
  pvStack_c = ExceptionList;
  bVar1 = *(byte *)(param_1 + 0x10);
  iVar3 = 0;
  if (bVar1 == 0) {
    iVar3 = 0x1e0032;
    uStack_38 = 0x7016bf;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a838 + 0x18))();
  }
  else {
    ExceptionList = &pvStack_c;
    if ((bVar1 != 0) && (ExceptionList = &pvStack_c, bVar1 < 4)) {
      uStack_38 = 0x7016ab;
      ExceptionList = &pvStack_c;
      (**(code **)(*DAT_00b5a838 + 0x18))();
    }
  }
  uStack_38 = 0x7016c6;
  puVar2 = operator_new(8);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &PTR_FUN_009e8a98;
  }
  uStack_38 = 0x7016dd;
  FUN_00797a20();
  if (iVar3 != 0) {
    uStack_38 = 0;
    uStack_3c = 0x7016f1;
    uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_3c = 0xffffffff;
    uStack_40 = 0;
    uStack_48 = 0x70170f;
    FUN_00401660();
    puStack_4 = auStack_54;
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_c = (void *)0x0;
    uStack_50 = 0;
    FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_10) {
      uStack_38 = 0x701750;
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_007017a0 @ 0x007017a0 ====

void FUN_007017a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  undefined4 ****ppppuVar7;
  int in_ECX;
  int iVar8;
  undefined4 *puVar9;
  int iStack_bc;
  undefined4 ****appppuStack_b4 [4];
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined4 ****appppuStack_98 [4];
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  int local_7c;
  char acStack_78 [25];
  char acStack_5f [27];
  undefined4 uStack_44;
  char acStack_3e [25];
  char acStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098e7fa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_7c = in_ECX;
  iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if ((iVar2 == 3) &&
     (iVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))(), 59999 < (uint)(iVar2 - *(int *)(in_ECX + 4))))
  {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5330005;
    *(undefined2 *)((int)pvVar4 + 6) = 0x19c;
    iVar2 = FUN_004244d0();
    iVar5 = (**(code **)(*DAT_00b5a838 + 0x20))();
    if (*(int *)(iVar5 + 8) != 0) {
      iVar1 = **(int **)(iVar5 + 4);
      puVar9 = (undefined4 *)(iVar2 + 0x10);
      for (iVar8 = 0x62; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      *(char *)(iVar2 + 0x198) = (char)*(undefined4 *)(iVar5 + 8);
      iVar8 = *(int *)(iVar5 + 4);
      iStack_bc = 0;
      while (iVar1 != iVar8) {
        uStack_84 = 0xf;
        uStack_88 = 0;
        appppuStack_98[0] = (undefined4 ****)((uint)appppuStack_98[0] & 0xffffff00);
        FUN_00401660(iVar1 + 0x28,0,0xffffffff);
        uStack_80 = *(undefined4 *)(iVar1 + 0x44);
        uStack_4 = 0;
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        appppuStack_b4[0] = (undefined4 ****)((uint)appppuStack_b4[0] & 0xffffff00);
        FUN_00401660(iVar1 + 0xc,0,0xffffffff);
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        acStack_78[0] = '\0';
        acStack_5f[0] = '\0';
        ppppuVar7 = appppuStack_98[0];
        if (uStack_84 < 0x10) {
          ppppuVar7 = appppuStack_98;
        }
        FUN_0047aa30(acStack_25,&DAT_009e9a98,ppppuVar7);
        uVar6 = 0;
        do {
          acStack_5f[uVar6] = acStack_25[uVar6];
          if (acStack_25[uVar6] == '\0') goto LAB_0070191d;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 0x19);
        acStack_5f[0] = '\0';
LAB_0070191d:
        uStack_44 = uStack_80;
        ppppuVar7 = appppuStack_b4[0];
        if (uStack_a0 < 0x10) {
          ppppuVar7 = appppuStack_b4;
        }
        FUN_0047aa30(acStack_3e,&DAT_009e9a98,ppppuVar7);
        uVar6 = 0;
        do {
          acStack_78[uVar6] = acStack_3e[uVar6];
          if (acStack_3e[uVar6] == '\0') goto LAB_0070196b;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 0x19);
        acStack_78[0] = '\0';
LAB_0070196b:
        FUN_00701ad0(acStack_78);
        iStack_bc = iStack_bc + 1;
        if (iStack_bc == 7) {
          if (0xf < uStack_a0) {
            _free(appppuStack_b4[0]);
            return;
          }
          uStack_a0 = 0xf;
          uStack_a4 = 0;
          appppuStack_b4[0] = (undefined4 ****)((uint)appppuStack_b4[0]._1_3_ << 8);
          uStack_4 = 0xffffffff;
          if (0xf < uStack_84) {
            _free(appppuStack_98[0]);
            return;
          }
          uStack_84 = 0xf;
          uStack_88 = 0;
          appppuStack_98[0] = (undefined4 ****)((uint)appppuStack_98[0]._1_3_ << 8);
          break;
        }
        if (0xf < uStack_a0) {
          _free(appppuStack_b4[0]);
          return;
        }
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        appppuStack_b4[0] = (undefined4 ****)((uint)appppuStack_b4[0]._1_3_ << 8);
        uStack_4 = 0xffffffff;
        if (0xf < uStack_84) {
          _free(appppuStack_98[0]);
          return;
        }
        uStack_84 = 0xf;
        uStack_88 = 0;
        appppuStack_98[0] = (undefined4 ****)((uint)appppuStack_98[0]._1_3_ << 8);
        FUN_00700ad0();
        iVar8 = *(int *)(iVar5 + 4);
      }
      FUN_004d8570(iVar2);
      (**(code **)(*DAT_00b5a838 + 0x24))();
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
      *(undefined4 *)(local_7c + 4) = uVar3;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00701a90 @ 0x00701a90 ====

undefined4 FUN_00701a90(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x5330001) {
      FUN_00701670(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00701ad0 @ 0x00701ad0 ====

void FUN_00701ad0(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = pcVar3[param_1 - (int)in_ECX];
    *pcVar3 = cVar1;
    if (cVar1 == '\0') goto LAB_00701af8;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x19);
  *in_ECX = '\0';
LAB_00701af8:
  uVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x19 + uVar2);
    in_ECX[uVar2 + 0x19] = cVar1;
    if (cVar1 == '\0') goto LAB_00701b18;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  in_ECX[0x19] = '\0';
LAB_00701b18:
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  return;
}


// ==== FUN_00701b30 @ 0x00701b30 ====

void FUN_00701b30(byte param_1)

{
  void *in_ECX;
  
  FUN_007015d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00701b50 @ 0x00701b50 ====

void FUN_00701b50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9ba8;
  return;
}


// ==== FUN_00701b60 @ 0x00701b60 ====

void FUN_00701b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9ba8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00701b80 @ 0x00701b80 ====

undefined4 FUN_00701b80(void)

{
  return 0x70940000;
}


// ==== FUN_00701b90 @ 0x00701b90 ====

undefined4 FUN_00701b90(void)

{
  return 0x70940001;
}


// ==== FUN_00701ba0 @ 0x00701ba0 ====

void FUN_00701ba0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009e9bd0;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00701be0 @ 0x00701be0 ====

void FUN_00701be0(int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  uVar2 = *(uint *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  switch(param_6) {
  default:
    if (uVar1 != 0x400) {
      param_2 = (uVar1 >> 1) - param_4 / 2;
    }
    if (uVar2 != 0x300) {
      *param_1 = param_2;
      param_1[1] = (uVar2 >> 1) - param_5 / 2;
      return;
    }
    break;
  case 2:
    if (uVar2 != 0x300) {
      param_3 = (uVar2 >> 1) - param_5 / 2;
    }
    break;
  case 3:
    if (uVar1 != 0x400) {
      *param_1 = (uVar1 >> 1) - param_4 / 2;
      param_1[1] = param_3;
      return;
    }
    break;
  case 4:
    if (uVar1 != 0x400) {
      *param_1 = param_2 + -0x400 + uVar1;
      param_1[1] = param_3;
      return;
    }
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ==== FUN_00701ce0 @ 0x00701ce0 ====

void FUN_00701ce0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    puVar4 = operator_new(0x14);
    uVar3 = param_4;
    uVar2 = param_3;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009e9bbc;
    }
    puVar5 = (undefined4 *)FUN_00701be0(&param_3,param_1,param_2,param_3,param_4,param_5);
    uVar1 = puVar5[1];
    puVar4[1] = *puVar5;
    puVar4[2] = uVar1;
    puVar4[3] = uVar2;
    puVar4[4] = uVar3;
    FUN_00797a20(puVar4);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00701d50 @ 0x00701d50 ====

void FUN_00701d50(void)

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
  
  puStack_8 = &LAB_0098e838;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009e9be4;
  *(undefined1 *)(in_ECX + 1) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s__position_X____position_Y____hei_009e9b04,0x2d);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_pplwnd_009e9b34,0xb);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,4,&local_28);
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
  FUN_00401740(&DAT_009e9b40,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_pplwnd_009e9b44,0xb);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a830 = (undefined4 *)0x0;
    ExceptionList = local_24;
    return;
  }
  DAT_00b5a830 = in_ECX;
  ExceptionList = local_24;
  return;
}


// ==== FUN_00701ee0 @ 0x00701ee0 ====

void FUN_00701ee0(void)

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
  
  puStack_8 = &LAB_0098e85a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009e9be4;
  local_4 = 0;
  DAT_00b5a830 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_pplwnd_009e9b50,0xb);
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
  FUN_00401740(s_hide_pplwnd_009e9b5c,0xb);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009e9ba8;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00701fc0 @ 0x00701fc0 ====

undefined4 FUN_00701fc0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  undefined4 uVar4;
  undefined4 extraout_EAX_01;
  undefined4 uVar5;
  undefined4 extraout_EAX_02;
  int *in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  void *pvStack_20;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098e884;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_pplwnd_009e9b68,0xb);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x28) != 0) {
      if ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 4) {
        uVar2 = FUN_00459160(local_28,0);
        local_4 = 0;
        uVar2 = thunk_FUN_00796e60(uVar2);
        local_4 = 0xffffffff;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return extraout_EAX;
        }
        uVar3 = FUN_00459160(local_28,1);
        local_4 = 1;
        uVar3 = thunk_FUN_00796e60(uVar3);
        local_4 = 0xffffffff;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return extraout_EAX_00;
        }
        uVar4 = FUN_00459160(local_28,2);
        local_4 = 2;
        uVar4 = thunk_FUN_00796e60(uVar4);
        local_4 = 0xffffffff;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return extraout_EAX_01;
        }
        uVar5 = FUN_00459160(auStack_44,3);
        local_4 = 3;
        uVar5 = thunk_FUN_00796e60(uVar5);
        local_4 = 0xffffffff;
        if (uStack_2c < 0x10) {
          uStack_2c = 0xf;
          uStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          (**(code **)(*in_ECX + 8))(uVar2,uVar3,uVar4,uVar5,5);
          ExceptionList = pvStack_20;
          return 1;
        }
        _free(pvStack_40);
        return extraout_EAX_02;
      }
    }
  }
  else {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_pplwnd_009e9b74,0xb);
    if (iVar1 != 0) {
      ExceptionList = local_c;
      return 0;
    }
    (**(code **)(*in_ECX + 0xc))();
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_007021b0 @ 0x007021b0 ====

undefined4 FUN_007021b0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00701fc0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007021e0 @ 0x007021e0 ====

void FUN_007021e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00701ee0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00702200 @ 0x00702200 ====

void FUN_00702200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9f40;
  return;
}


// ==== FUN_00702210 @ 0x00702210 ====

void FUN_00702210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9f40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00702240 @ 0x00702240 ====

void FUN_00702240(void)

{
                    /* WARNING: Could not recover jumptable at 0x00702257. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ada8 + 0x1c))();
  return;
}


// ==== FUN_00702260 @ 0x00702260 ====

void FUN_00702260(int param_1)

{
  undefined1 auStackY_94 [128];
  
  (**(code **)(*DAT_00b5ada8 + 0x24))(*(undefined1 *)(param_1 + 0x10));
  (**(code **)(*DAT_00b5ada8 + 0x30))(*(undefined4 *)(param_1 + 0x14));
  (**(code **)(*DAT_00b5ada4 + 0xc))(auStackY_94 + 0x90,0);
  return;
}


// ==== FUN_007022c0 @ 0x007022c0 ====

void FUN_007022c0(int param_1)

{
  undefined4 *puVar1;
  
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
  puVar1[1] = *(undefined4 *)(param_1 + 0x10);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 0x14);
  *(undefined1 *)((int)puVar1 + 10) = 1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00702320 @ 0x00702320 ====

void FUN_00702320(int param_1)

{
  undefined4 *puVar1;
  
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
  puVar1[1] = *(undefined4 *)(param_1 + 0x10);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 0x14);
  *(undefined1 *)((int)puVar1 + 10) = 1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00702380 @ 0x00702380 ====

void FUN_00702380(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_retaddr;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = (undefined1 *)&local_4;
  local_4 = 1;
  cVar2 = (**(code **)(*DAT_00b5ada4 + 0x1c))();
  if (cVar2 == '\0') {
    puStack_8 = (undefined1 *)0x1;
    (**(code **)(*DAT_00b5ada4 + 4))(&puStack_8,0);
  }
  uVar5 = *(uint *)(unaff_retaddr + 0x14);
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar4 = FUN_004244f0();
  if (uVar4 < uVar3) {
    if (uVar3 - uVar4 < uVar5) {
      uVar5 = uVar5 + (uVar4 - uVar3);
    }
    else {
      uVar5 = 0;
    }
  }
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5ada4 + 0x14))(3,uVar5);
  }
  else {
    if (iVar1 == 1) {
      (**(code **)(*DAT_00b5ada4 + 0x14))(2,uVar5);
      return;
    }
    if (iVar1 == 2) {
      (**(code **)(*DAT_00b5ada4 + 0x14))(1,uVar5);
      return;
    }
  }
  return;
}


// ==== FUN_00702440 @ 0x00702440 ====

undefined4 FUN_00702440(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_attachprocess_009e9f10,0x12);
  if (iVar1 == 0) {
    param_1 = 0x10;
    (**(code **)(*DAT_00b5ada4 + 4))(&param_1,0);
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x1c),s_hide_attachprocess_009e9f24,0x12);
  if (iVar2 == 0) {
    param_1 = 0x10;
    (**(code **)(*DAT_00b5ada4 + 8))(&param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_007024c0 @ 0x007024c0 ====

void FUN_007024c0(void)

{
  int iVar1;
  
  (**(code **)(*DAT_00b5ada8 + 0x18))();
  (**(code **)(*DAT_00b5ada8 + 0x58))(0);
  (**(code **)(*DAT_00b5ada8 + 0x2c))();
  (**(code **)(*DAT_00b5ada8 + 0x38))();
  iVar1 = (**(code **)(*DAT_00b5ada8 + 4))();
  if (iVar1 != 0) {
    if (*(void **)(iVar1 + 4) != (void *)0x0) {
      _free(*(void **)(iVar1 + 4));
      return;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  return;
}


// ==== FUN_00702530 @ 0x00702530 ====

void FUN_00702530(void)

{
  int iVar1;
  
  (**(code **)(*DAT_00b5ada8 + 0x18))();
  (**(code **)(*DAT_00b5ada8 + 0x58))(0);
  (**(code **)(*DAT_00b5ada8 + 0x60))(0);
  (**(code **)(*DAT_00b5ada8 + 0x2c))();
  (**(code **)(*DAT_00b5ada8 + 0x38))();
  iVar1 = (**(code **)(*DAT_00b5ada8 + 4))();
  if (iVar1 != 0) {
    if (*(void **)(iVar1 + 4) != (void *)0x0) {
      _free(*(void **)(iVar1 + 4));
      return;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  return;
}


// ==== FUN_007025b0 @ 0x007025b0 ====

void FUN_007025b0(int param_1)

{
  void *pvVar1;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098e898;
  pvStack_c = ExceptionList;
  if (*(int *)(param_1 + 0x10) == 0) {
    uStack_34 = 1;
    pvVar1 = (void *)0x640069;
    pvStack_38 = (void *)0x7025e7;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5ada8 + 0x60))();
  }
  else {
    uStack_34 = 0;
    pvVar1 = (void *)0x64006a;
    pvStack_38 = (void *)0x7025f4;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5ada8 + 0x60))();
  }
  uStack_3c = 9;
  uStack_40 = 0x702602;
  pvStack_38 = pvVar1;
  uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_40 = 0xffffffff;
  uStack_44 = 0;
  uStack_4c = 0x702620;
  FUN_00401660();
  puStack_8 = auStack_58;
  uStack_40 = 0xf;
  uStack_44 = 0;
  uStack_54 = 0;
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_00702680 @ 0x00702680 ====

void FUN_00702680(int param_1)

{
  int iVar1;
  undefined1 auStack_6c [4];
  undefined1 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  void *pvStack_40;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098e8b2;
  local_c = ExceptionList;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 1:
    if (*(int *)(param_1 + 0x14) == 0) {
      uStack_50 = 9;
      uStack_54 = 0x7026d0;
      ExceptionList = &local_c;
      uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0x7026da;
      FUN_00765c50();
      puStack_4 = auStack_6c;
      local_c = (void *)0x0;
      FUN_00765c50(auStack_30);
      (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    return;
  case 2:
    if (*(int *)(param_1 + 0x14) != 3) {
      return;
    }
    break;
  default:
    goto switchD_007026ac_caseD_3;
  case 7:
    iVar1 = *(int *)(param_1 + 0x14);
    if (((iVar1 != 1) && (iVar1 != 3)) && (iVar1 != 4)) {
      return;
    }
    break;
  case 8:
    if (*(int *)(param_1 + 0x14) != 1) {
      return;
    }
  }
  uStack_50 = 9;
  uStack_54 = 0x70276e;
  ExceptionList = &local_c;
  uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_54 = 0xffffffff;
  uStack_58 = 0;
  uStack_60 = 0x70278d;
  FUN_00401660();
  puStack_4 = auStack_6c;
  uStack_54 = 0xf;
  uStack_58 = 0;
  local_c = (void *)0x1;
  uStack_68 = 0;
  FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_2c) {
    uStack_50 = 0x7027d6;
    _free(pvStack_40);
    return;
  }
switchD_007026ac_caseD_3:
  ExceptionList = local_c;
  return;
}


// ==== FUN_00702810 @ 0x00702810 ====

void FUN_00702810(int param_1)

{
  int iVar1;
  char cVar2;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 **ppuStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_46 [6];
  void *pvStack_40;
  undefined4 auStack_34 [2];
  uint uStack_2c;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098e8d4;
  local_c = ExceptionList;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    uStack_5c = 9;
    uStack_60 = 0x70285b;
    ExceptionList = &local_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    ppuStack_64 = (undefined1 **)0x702865;
    FUN_00765c50();
    local_c = (void *)0x0;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x2c))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    break;
  default:
    goto switchD_00702842_caseD_2;
  case 4:
    iVar1 = *DAT_00b5add0;
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5ac1c + 0x38))();
    uStack_5c = 0x7028cd;
    cVar2 = (**(code **)(iVar1 + 0x44))();
    if (cVar2 != '\0') {
      uStack_5c = 1;
      uStack_60 = 0x7028de;
      (**(code **)(*DAT_00b5ada8 + 0x58))();
      uStack_60 = 0;
      ppuStack_64 = &puStack_4;
      puStack_4 = (undefined1 *)0x4;
      uStack_68 = 0x7028f8;
      (**(code **)(*DAT_00b5ada4 + 4))();
    }
    uStack_5c = 0x12c0064;
    uStack_60 = 9;
    ppuStack_64 = (undefined1 **)0x70290a;
    ppuStack_64 = (undefined1 **)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0x702914;
    FUN_00765c50();
    uStack_10 = 1;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 5:
    break;
  case 10:
  }
  uStack_5c = 9;
  uStack_60 = 0x702973;
  ExceptionList = &local_c;
  uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_60 = 0xffffffff;
  ppuStack_64 = (undefined1 **)0x0;
  auStack_34[0] = 0xf;
  uStack_6c = 0x702993;
  FUN_00401660();
  puStack_4 = auStack_78;
  uStack_60 = 0xf;
  ppuStack_64 = (undefined1 **)0x0;
  local_c = (void *)0x2;
  uStack_74 = 0;
  FUN_00401660(auStack_46 + -6,0);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  if (0xf < uStack_2c) {
    uStack_5c = 0x7029d8;
    _free(pvStack_40);
    return;
  }
switchD_00702842_caseD_2:
  ExceptionList = local_c;
  return;
}


// ==== FUN_00702a20 @ 0x00702a20 ====

void FUN_00702a20(int param_1)

{
  void **ppvVar1;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 **ppuStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098e8e6;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x10) == 0) {
    uStack_38 = 0x702a67;
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5ada8 + 0x3c))();
    uStack_38 = *(undefined4 *)(param_1 + 0x14);
    uStack_3c = 0x702a76;
    (**(code **)(*DAT_00b5ada8 + 0x48))();
    uStack_3c = 0;
    ppuStack_40 = &puStack_4;
    puStack_4 = (undefined1 *)0x10;
    uStack_44 = 0x702a8f;
    (**(code **)(*DAT_00b5ada4 + 4))();
    uStack_44 = 0x10;
    uStack_48 = 0x702a9c;
    (**(code **)(*DAT_00b5acd4 + 4))();
    ppvVar1 = ExceptionList;
  }
  else {
    ppvVar1 = &local_c;
    if (*(int *)(param_1 + 0x10) != 1) {
      return;
    }
  }
  ExceptionList = ppvVar1;
  uStack_38 = 9;
  uStack_3c = 0x702aaf;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  ppuStack_40 = (undefined1 **)0x0;
  uStack_48 = 0x702acd;
  FUN_00401660();
  puStack_4 = auStack_54;
  uStack_3c = 0xf;
  ppuStack_40 = (undefined1 **)0x0;
  local_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  uStack_38 = 0x702b0e;
  _free(pvStack_24);
  return;
}


// ==== FUN_00702b30 @ 0x00702b30 ====

void FUN_00702b30(void)

{
  int iVar1;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  void *local_2c [2];
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_18;
  void *pvStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_0098e8f8;
  puStack_c = ExceptionList;
  puStack_34 = (undefined1 *)local_2c;
  local_2c[0] = (void *)0x10;
  uStack_38 = 0x702b61;
  ExceptionList = &puStack_c;
  (**(code **)(*DAT_00b5ada4 + 8))();
  uStack_38 = 0;
  (**(code **)(*DAT_00b5acd4 + 4))();
  iVar1 = *(int *)(iStack_4 + 0x10);
  if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
    uStack_40 = 9;
    uStack_44 = 0x702ba9;
    uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_44 = 0xffffffff;
    uStack_48 = 0;
    uStack_20 = 0xf;
    uStack_24 = 0;
    puStack_34 = (undefined1 *)((uint)puStack_34 & 0xffffff00);
    uStack_50 = 0x702bc6;
    FUN_00401660();
    puStack_c = auStack_5c;
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_14 = (void *)0x0;
    uStack_58 = 0;
    FUN_00401660(&uStack_38,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_18) {
      uStack_40 = 0x702c0b;
      _free(local_2c[0]);
      return;
    }
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00702c20 @ 0x00702c20 ====

void FUN_00702c20(void)

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
  
  puStack_8 = &LAB_0098e92a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009e9f4c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ada0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ada0 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009e9c2e,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_attachprocess_009e9c30,0x12);
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
  FUN_00401740(&DAT_009e9c43,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_attachprocess_009e9c44,0x12);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (local_28 < 0x10) {
    ExceptionList = local_24;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_00702da0 @ 0x00702da0 ====

void FUN_00702da0(void)

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
  
  puStack_8 = &LAB_0098e94c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009e9f4c;
  local_4 = 0;
  DAT_00b5ada0 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_attachprocess_009e9c58,0x12);
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
  FUN_00401740(s_hide_attachprocess_009e9c6c,0x12);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009e9f40;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00702e80 @ 0x00702e80 ====

void FUN_00702e80(void)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_retaddr;
  undefined1 auStack_c0 [56];
  undefined1 auStack_88 [120];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098e997;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5ada4 + 0x1c))();
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5ada4 + 4))();
  }
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_004244f0();
    (**(code **)(*DAT_00b5ada4 + 0x10))();
    FUN_00401830(&DAT_009e9c80);
    uVar2 = FUN_00404230(auStack_c0);
    pvStack_10 = (void *)0x0;
    uVar2 = FUN_004022a0(auStack_88,s__debug__009e9c90,uVar2);
    pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,1);
    FUN_00796d50(uVar2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    (**(code **)(*DAT_00b5ada4 + 0x10))();
    ExceptionList = pvStack_10;
    return;
  case 2:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_10 = (void *)0x6;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x2c))();
    (**(code **)(*DAT_00b5ada4 + 0x10))(2,*(undefined4 *)(unaff_retaddr + 0x14));
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  default:
    goto switchD_00702ee7_default;
  }
  (**(code **)(*DAT_00b5ada4 + 0x10))();
switchD_00702ee7_default:
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00703150 @ 0x00703150 ====

void FUN_00703150(int param_1)

{
  int iVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar5;
  undefined1 *puStack_a8;
  void **ppvStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  undefined4 *puStack_98;
  undefined1 *puStack_94;
  uint uVar6;
  undefined4 uStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  undefined1 local_60 [4];
  void *local_5c;
  undefined1 uStack_54;
  undefined4 local_4c;
  void *local_48;
  undefined4 uStack_44;
  void *pvStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  uint uStack_20;
  undefined1 *puStack_18;
  undefined1 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098e9c9;
  puStack_c = ExceptionList;
  uStack_74 = (undefined4 *)0x0;
  puStack_78 = &DAT_009e9dfc;
  local_48 = (void *)0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  uStack_7c = 0x70318e;
  ExceptionList = &puStack_c;
  FUN_00401740();
  iVar1 = param_1;
  local_4 = 0;
  uStack_74 = (undefined4 *)0x7031a1;
  sVar3 = (**(code **)(*DAT_00b5ada8 + 0x40))();
  uVar5 = extraout_var;
  if (sVar3 == *(short *)(iVar1 + 0x12)) {
    uStack_74 = &param_1;
    param_1 = 0x10;
    puStack_78 = (undefined *)0x7031c4;
    (**(code **)(*DAT_00b5ada4 + 8))();
    puStack_78 = (undefined *)0x0;
    uStack_7c = 0x7031d0;
    (**(code **)(*DAT_00b5acd4 + 4))();
    uStack_7c = 0x7031db;
    cVar2 = (**(code **)(*DAT_00b5ada8 + 0x4c))();
    if (cVar2 == *(char *)(iVar1 + 0x10)) {
      uStack_7c = *(undefined4 *)(iVar1 + 0x18);
      uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_c = (undefined1 *)&uStack_a0;
      ppvStack_a4 = (void **)0xffffffff;
      puStack_a8 = (undefined1 *)0x0;
      uStack_9c = uStack_9c & 0xffffff00;
      FUN_00401660(uVar4);
      ppvStack_a4 = &pvStack_38;
      puStack_a8 = (undefined1 *)0x70321e;
      FUN_00404230();
      uStack_14 = 1;
      FUN_00401660();
      uStack_14 = 0;
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return;
      }
    }
    else {
      uStack_7c = 0x12c007b;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
    }
    puStack_c = (undefined1 *)&uStack_9c;
    uStack_a0 = 0xffffffff;
    ppvStack_a4 = (void **)0x0;
    puStack_a8 = local_60 + -0x10;
    puStack_98 = (undefined4 *)((uint)puStack_98 & 0xffffff00);
    FUN_00401660();
    uStack_a0 = 5;
    ppvStack_a4 = (void **)0x70329a;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uVar5 = extraout_var_00;
  }
  uStack_74 = (undefined4 *)CONCAT22(uVar5,*(undefined2 *)(iVar1 + 0x14));
  puStack_78 = (undefined *)CONCAT31((int3)((uint)uStack_74 >> 8),*(undefined1 *)(iVar1 + 0x10));
  uStack_7c = CONCAT22(uVar5,*(undefined2 *)(iVar1 + 0x12));
  (**(code **)(*DAT_00b5ada8 + 0x10))();
  (**(code **)(*DAT_00b5add0 + 0x58))();
  uVar6 = 0x12c0079;
  uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_10 = (undefined1 *)&ppvStack_a4;
  puStack_a8 = (undefined1 *)0xffffffff;
  uStack_a0 = uStack_a0 & 0xffffff00;
  FUN_00401660(uVar4,0);
  puStack_a8 = auStack_3c;
  FUN_00404230();
  puStack_18._0_1_ = 2;
  puStack_94 = (undefined1 *)0x703312;
  FUN_00401660();
  puStack_18 = (undefined1 *)((uint)puStack_18._1_3_ << 8);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  pvStack_40 = (void *)0xf;
  uStack_44 = 0;
  uStack_54 = 0;
  FUN_00401740();
  puStack_18 = (undefined1 *)CONCAT31(puStack_18._1_3_,3);
  (**(code **)(*DAT_00b5ada4 + 0x20))();
  puStack_94 = local_60;
  puStack_98 = &uStack_7c;
  uStack_20._0_1_ = 4;
  uStack_9c = 0x703373;
  FUN_00404440();
  if (0xf < uStack_2c) {
    puStack_94 = (undefined1 *)0x703386;
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  uStack_20 = (uint)uStack_20._1_3_ << 8;
  if ((void *)0xf < local_48) {
    puStack_94 = (undefined1 *)0x7033a9;
    _free(local_5c);
    return;
  }
  puStack_18 = (undefined1 *)&puStack_a8;
  puStack_94 = (undefined1 *)0x0;
  ppvStack_a4 = (void **)((uint)ppvStack_a4 & 0xffffff00);
  FUN_00401660(&uStack_7c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
  if (uVar6 < 0x10) {
    ExceptionList = local_48;
    return;
  }
  _free(puStack_98);
  return;
}


// ==== FUN_00703410 @ 0x00703410 ====

/* WARNING: Removing unreachable block (ram,0x007035af) */
/* WARNING: Removing unreachable block (ram,0x00703815) */

void FUN_00703410(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int unaff_EBP;
  char **unaff_EDI;
  char *pcStack_c0;
  uint uStack_bc;
  int *piStack_b8;
  char *pcStack_b4;
  char *pcStack_b0;
  undefined1 auStack_76 [42];
  void *pvStack_4c;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  void *pvStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 uStack_24;
  undefined1 uStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar3 = DAT_00b5a69c;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098e9f3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00424520();
  piVar3 = (int *)(**(code **)(*piVar3 + 4))();
  iVar4 = (**(code **)(*DAT_00b5ada4 + 0x18))();
  if (*(void **)(iVar4 + 4) != (void *)0x0) {
    _free(*(void **)(iVar4 + 4));
    return;
  }
  *(undefined4 *)(iVar4 + 4) = 0;
  *(undefined4 *)(iVar4 + 8) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 != 1) {
    pcStack_b4 = (char *)0x2d;
    piStack_b8 = (int *)s_fail_during_Read_Partywar_LastIn_009e9e0c;
    uStack_bc = 0x7034c3;
    FUN_00401740();
    pcStack_b4 = (char *)0x8;
    piStack_b8 = (int *)0x7034d0;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_bc = 0x7034dc;
    piStack_b8 = piVar3;
    (**(code **)(*DAT_00b5a69c + 8))();
    ExceptionList = pvStack_3c;
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401740();
  uStack_10 = 0;
  cVar1 = (char)puStack_8;
  do {
    if (cVar1 == '\0') {
LAB_0070370e:
      (**(code **)(*DAT_00b5a69c + 8))();
      (**(code **)(*DAT_00b5ada4 + 4))();
      pcStack_b4 = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
      pcStack_b0 = (char *)0x0;
      piStack_b8 = (int *)0x70375e;
      FUN_00401660();
      pcStack_b0 = s_<PARTYNAMES>_009e9f00;
      uStack_24 = 2;
      uStack_30 = 0xf;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      pcStack_b4 = (char *)0x703785;
      FUN_00401740();
      pcStack_b0 = auStack_48;
      pcStack_b4 = auStack_76 + -10;
      uStack_24 = 3;
      piStack_b8 = (int *)0x7037a1;
      FUN_00404440();
      uStack_24 = 2;
      if (0xf < uStack_30) {
        pcStack_b0 = (char *)0x7037c1;
        _free(pvStack_44);
        return;
      }
      pcStack_b0 = (char *)0x0;
      pcStack_c0 = (char *)((uint)pcStack_c0 & 0xffffff00);
      FUN_00401660(auStack_76 + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (unaff_EDI < (undefined1 *)0x10) {
        ExceptionList = pvStack_4c;
        return;
      }
      _free((void *)0x0);
      return;
    }
    pbVar5 = operator_new(0xc);
    if (pbVar5 == (byte *)0x0) {
      pbVar5 = (byte *)0x0;
    }
    else {
      *pbVar5 = 0;
      pbVar5[4] = 0;
      pbVar5[5] = 0;
      pbVar5[6] = 0;
      pbVar5[7] = 0;
      pbVar5[8] = 0;
      pbVar5[9] = 0;
      pbVar5[10] = 0;
      pbVar5[0xb] = 0;
    }
    iVar4 = (**(code **)(*piVar3 + 8))();
    if (iVar4 != 1) {
      pcStack_c0 = s_fail_during_Read_Partywar_LastIn_009e9e3c;
LAB_007036cc:
      uStack_bc = 0x2d;
      pcStack_b4 = (char *)((uint)pcStack_b4 & 0xffffff00);
      FUN_00401740();
      uStack_bc = 8;
      pcStack_c0 = (char *)0x7036e7;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      goto LAB_0070370e;
    }
    iVar4 = (**(code **)(*piVar3 + 8))();
    if (iVar4 != 4) {
      unaff_EDI = &pcStack_c0;
      uStack_bc = uStack_bc & 0xffffff00;
      FUN_00401740(s_fail_during_Read_Partywar_LastIn_009e9e6c);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      goto LAB_0070370e;
    }
    pcStack_b0 = (char *)0x703586;
    iVar4 = (**(code **)(*piVar3 + 8))();
    if (iVar4 != 4) {
      pcStack_c0 = s_fail_during_Read_Partywar_LastIn_009e9e9c;
      goto LAB_007036cc;
    }
    iVar4 = (**(code **)(*piVar3 + 8))();
    if (iVar4 != 1) {
      pcStack_b4 = s_fail_during_Read_Partywar_LastIn_009e9ecc;
      piStack_b8 = (int *)0x7036fc;
      FUN_00401830();
      pcStack_b4 = (char *)0x8;
      piStack_b8 = (int *)0x703709;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      goto LAB_0070370e;
    }
    if (*pbVar5 == 1) {
      (**(code **)(*DAT_00b5ada4 + 0x20))();
      uStack_18 = 1;
      FUN_00401ff0();
      uStack_18 = 0;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    puVar6 = *(undefined4 **)(unaff_EBP + 4);
    if (((puVar6 != (undefined4 *)0x0) &&
        (puVar2 = *(undefined4 **)(unaff_EBP + 8), (int)puVar2 - (int)puVar6 >> 2 != 0)) &&
       (puVar6 != puVar2)) {
      do {
        if (*pbVar5 < *(byte *)*puVar6) {
          if (puVar6 != puVar2) {
            FUN_00704100();
            goto LAB_0070364b;
          }
          break;
        }
        puVar6 = puVar6 + 1;
      } while (puVar6 != puVar2);
    }
    FUN_00704150();
LAB_0070364b:
    cVar1 = (char)puStack_8 + -1;
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,cVar1);
  } while( true );
}


// ==== FUN_00703840 @ 0x00703840 ====

/* WARNING: Removing unreachable block (ram,0x007038a7) */

void FUN_00703840(void)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  uint uVar8;
  undefined4 unaff_EBX;
  uint unaff_EBP;
  int *piStack_4d8;
  char *pcStack_4d4;
  undefined4 uStack_4cc;
  int **ppiVar9;
  undefined4 uVar10;
  uint uVar11;
  int iStack_494;
  void *pvStack_478;
  uint uStack_464;
  void *pvStack_440;
  void *pvStack_430;
  uint uStack_42c;
  uint uStack_41c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ea37;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*DAT_00b5ada8 + 4))(), iVar5 != 0)) {
    if (*(void **)(iVar5 + 4) != (void *)0x0) {
      _free(*(void **)(iVar5 + 4));
      return;
    }
    *(undefined4 *)(iVar5 + 4) = 0;
    *(undefined4 *)(iVar5 + 8) = 0;
    *(undefined4 *)(iVar5 + 0xc) = 0;
    piVar6 = DAT_00b5a69c;
    FUN_00424520();
    piVar6 = (int *)(**(code **)(*piVar6 + 4))();
    puStack_8 = (undefined1 *)0x1;
    iVar5 = (**(code **)(*piVar6 + 8))();
    if (iVar5 == 1) {
      (**(code **)(*piVar4 + 0x70))();
      FUN_00401830();
      ppiVar9 = (int **)(unaff_EBP & 0xffffff);
      uVar10 = CONCAT22((short)((uint)unaff_EBX >> 0x10),(ushort)(byte)unaff_EBX);
      if ((char)((uint)unaff_EBX >> 0x18) != '\0') {
        do {
          pvVar7 = operator_new(0x14);
          if (pvVar7 == (void *)0x0) {
            pvVar7 = (void *)0x0;
          }
          else {
            *(undefined4 *)((int)pvVar7 + 8) = 0;
            *(undefined4 *)((int)pvVar7 + 0xc) = 0;
            *(undefined4 *)((int)pvVar7 + 0x10) = 0;
          }
          if (*(int *)((int)pvVar7 + 8) != 0) {
            FUN_00405de0();
            uStack_4cc = 0x703a0c;
            _free(*(void **)((int)pvVar7 + 8));
            return;
          }
          *(undefined4 *)((int)pvVar7 + 8) = 0;
          *(undefined4 *)((int)pvVar7 + 0xc) = 0;
          *(undefined4 *)((int)pvVar7 + 0x10) = 0;
          iVar5 = (**(code **)(*piVar6 + 8))();
          if (iVar5 != 1) {
            pcStack_4d4 = (char *)((uint)pcStack_4d4 & 0xffffff00);
            FUN_00401740(s_fail_during_Read_Partywar_Member_009e9d3c,0x2f);
            (**(code **)(*DAT_00b5ad0c + 0x28))(8);
            break;
          }
          iVar5 = (**(code **)(*piVar6 + 8))();
          if (iVar5 != 1) {
            pcStack_4d4 = s_fail_during_Read_Partywar_Member_009e9d6c;
            piStack_4d8 = (int *)0x703c30;
            FUN_00401830();
            pcStack_4d4 = (char *)0x8;
            piStack_4d8 = (int *)0x703c3d;
            (**(code **)(*DAT_00b5ad0c + 0x28))();
            break;
          }
          uVar11 = CONCAT13((char)((uint)uVar10 >> 0x18),(uint3)(ushort)uVar10);
          if ((char)((uint)ppiVar9 >> 0x10) != '\0') {
            do {
              iVar5 = (**(code **)(*piVar6 + 8))();
              if (iVar5 != 1) {
                ppiVar9 = &piStack_4d8;
                pcStack_4d4 = (char *)((uint)pcStack_4d4 & 0xffffff00);
                FUN_00401740(s_fail_during_Read_Partywar_Member_009e9d9c,0x2f);
                (**(code **)(*DAT_00b5ad0c + 0x28))(8);
                goto LAB_00703bd6;
              }
              uVar8 = (**(code **)(*piVar6 + 8))();
              if (uVar8 != (uVar11 & 0xff)) {
                pcStack_4d4 = s_fail_during_Read_Partywar_Member_009e9dcc;
                piStack_4d8 = (int *)0x703b90;
                FUN_00401830();
                pcStack_4d4 = (char *)0x8;
                piStack_4d8 = (int *)0x703b9d;
                (**(code **)(*DAT_00b5ad0c + 0x28))();
                goto LAB_00703bd6;
              }
              FUN_00401830();
              FUN_00401660();
              if (0xf < uStack_41c) {
                _free(pvStack_430);
                return;
              }
              uStack_41c = 0xf;
              pvStack_430 = (void *)((uint)pvStack_430 & 0xffffff00);
              if (((char)((uint)ppiVar9 >> 0x18) == '\0') && (cVar2 = FUN_00423420(), cVar2 != '\0')
                 ) {
                (**(code **)(*DAT_00b5ada8 + 0x50))();
                ppiVar9 = (int **)CONCAT13(1,(int3)ppiVar9);
              }
              FUN_00406720();
              bVar3 = (char)(uVar11 >> 0x10) + 1;
              uVar11 = CONCAT13((char)(uVar11 >> 0x18),CONCAT12(bVar3,(short)uVar11));
            } while (bVar3 < (byte)((uint)ppiVar9 >> 0x10));
          }
          iVar5 = *(int *)(iStack_494 + 4);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(iStack_494 + 0xc) - iVar5 >> 2) <=
              (uint)(*(int *)(iStack_494 + 8) - iVar5 >> 2))) {
            FUN_00703f00();
          }
          else {
            puVar1 = *(undefined4 **)(iStack_494 + 8);
            *puVar1 = pvVar7;
            *(undefined4 **)(iStack_494 + 8) = puVar1 + 1;
          }
LAB_00703bd6:
          bVar3 = (char)(uVar11 >> 8) + 1;
          uVar10 = CONCAT22((short)(uVar11 >> 0x10),CONCAT11(bVar3,(char)uVar11));
        } while (bVar3 < (byte)(uVar11 >> 0x18));
      }
      (**(code **)(*DAT_00b5a69c + 8))();
      if (0xf < uStack_42c) {
        _free(pvStack_440);
        return;
      }
    }
    else {
      pcStack_4d4 = s_fail_during_Read_Partywar_Member_009e9d0c;
      piStack_4d8 = (int *)0x70396f;
      FUN_00401830();
      pcStack_4d4 = (char *)0x8;
      piStack_4d8 = (int *)0x70397c;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      piStack_4d8 = piVar6;
      (**(code **)(*DAT_00b5a69c + 8))();
    }
    if (0xf < uStack_464) {
      _free(pvStack_478);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00703ca0 @ 0x00703ca0 ====

undefined4 FUN_00703ca0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x5300004) {
  case 0:
    FUN_007025b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 3:
    FUN_00702240(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 4:
    FUN_007022c0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 5:
    FUN_00702680(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 6:
    FUN_00702810(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 7:
    FUN_00702a20(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 8:
    FUN_00703150(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 9:
    FUN_00702530(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 10:
    FUN_00702320(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xb:
    FUN_00703840(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xc:
    FUN_00702260(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xd:
    FUN_00703410(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xe:
    FUN_007024c0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xf:
    break;
  case 0x10:
    FUN_00702e80(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x17:
    FUN_00702380(*(undefined4 *)(param_1 + 0xc));
  }
  return 1;
}


// ==== FUN_00703e40 @ 0x00703e40 ====

undefined4 FUN_00703e40(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00703ca0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_00702440(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00703e90 @ 0x00703e90 ====

void FUN_00703e90(void)

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
  puStack_8 = &LAB_0098ea58;
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


// ==== FUN_00703f00 @ 0x00703f00 ====

void FUN_00703f00(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00703e90();
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


// ==== FUN_007040e0 @ 0x007040e0 ====

void FUN_007040e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00702da0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00704100 @ 0x00704100 ====

void FUN_00704100(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (*(int *)(in_ECX + 8) - iVar1 >> 2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - iVar1 >> 2;
  }
  FUN_00703f00(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 4;
  return;
}


// ==== FUN_00704150 @ 0x00704150 ====

void FUN_00704150(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00703f00(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_007041a0 @ 0x007041a0 ====

void FUN_007041a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9fac;
  return;
}


// ==== FUN_007041b0 @ 0x007041b0 ====

void FUN_007041b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e9fac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00704200 @ 0x00704200 ====

int FUN_00704200(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00704210 @ 0x00704210 ====

undefined4 FUN_00704210(uint *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 4);
  if (uVar1 == 0) {
    return 0;
  }
  return CONCAT31((int3)(uVar1 >> 8),(*param_1 & uVar1) != 0);
}


// ==== FUN_00704240 @ 0x00704240 ====

uint FUN_00704240(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (uVar1 = *(uint *)(in_ECX + 0x18), uVar1 != 0)) {
    if (uVar1 < (uint)param_1[1]) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
      return uVar1 & 0xffffff00;
    }
    uVar1 = uVar1 - param_1[1];
    *(uint *)(in_ECX + 0x18) = uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00704280 @ 0x00704280 ====

void FUN_00704280(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x1c))(param_1);
  if (cVar1 == '\0') {
    switch(*param_1) {
    case 1:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        in_ECX[1] = in_ECX[1] + 1;
        in_ECX[6] = (int)param_1;
        FUN_00797a20(0);
        return;
      }
      *puVar2 = &PTR_FUN_009ea024;
      in_ECX[1] = in_ECX[1] + 1;
      in_ECX[6] = (int)param_1;
      FUN_00797a20(puVar2);
      return;
    case 2:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        in_ECX[1] = in_ECX[1] + 2;
        FUN_00797a20(0);
        return;
      }
      *puVar2 = &PTR_FUN_009e9fe8;
      in_ECX[1] = in_ECX[1] + 2;
      FUN_00797a20(puVar2);
      return;
    case 4:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        in_ECX[1] = in_ECX[1] + 4;
        FUN_00797a20(0);
        return;
      }
      *puVar2 = &PTR_FUN_009ea060;
      in_ECX[1] = in_ECX[1] + 4;
      FUN_00797a20(puVar2);
      return;
    case 8:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        in_ECX[1] = in_ECX[1] + 8;
        FUN_00797a20(0);
        return;
      }
      *puVar2 = &PTR_FUN_009ea09c;
      in_ECX[1] = in_ECX[1] + 8;
      FUN_00797a20(puVar2);
      return;
    case 0x10:
      puVar2 = operator_new(4);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = &PTR_FUN_009ea0c4;
        in_ECX[1] = in_ECX[1] + 0x10;
        FUN_00797a20(puVar2);
        return;
      }
      in_ECX[1] = in_ECX[1] + 0x10;
      FUN_00797a20(0);
    }
  }
  return;
}


// ==== FUN_00704410 @ 0x00704410 ====

void FUN_00704410(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x1c))(param_1);
  if (cVar1 != '\0') {
    switch(*param_1) {
    case 1:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
        in_ECX[1] = in_ECX[1] + -1;
      }
      else {
        *puVar2 = &PTR_FUN_009ea038;
        in_ECX[1] = in_ECX[1] + -1;
      }
      break;
    case 2:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
        in_ECX[1] = in_ECX[1] + -2;
      }
      else {
        *puVar2 = &PTR_FUN_009e9ffc;
        in_ECX[1] = in_ECX[1] + -2;
      }
      break;
    default:
      goto switchD_0070443b_caseD_3;
    case 4:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
        in_ECX[1] = in_ECX[1] + -4;
      }
      else {
        *puVar2 = &PTR_FUN_009ea074;
        in_ECX[1] = in_ECX[1] + -4;
      }
      break;
    case 8:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
        in_ECX[1] = in_ECX[1] + -8;
      }
      else {
        *puVar2 = &PTR_FUN_009ea0b0;
        in_ECX[1] = in_ECX[1] + -8;
      }
      break;
    case 0x10:
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009ea0d8;
      }
      in_ECX[1] = in_ECX[1] + -0x10;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_00797a20(puVar2);
    }
  }
switchD_0070443b_caseD_3:
  return;
}


// ==== FUN_00704530 @ 0x00704530 ====

void FUN_00704530(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x1c))(param_1);
  if ((cVar1 != '\0') && (*param_1 == 4)) {
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009ea088;
      FUN_00797a20(puVar2);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_00704580 @ 0x00704580 ====

void FUN_00704580(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_2;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea010;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007045c0 @ 0x007045c0 ====

void FUN_007045c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_2;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea04c;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00704600 @ 0x00704600 ====

void FUN_00704600(void)

{
                    /* WARNING: Could not recover jumptable at 0x00704608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ada8 + 0x54))();
  return;
}


// ==== FUN_00704610 @ 0x00704610 ====

void FUN_00704610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea0ec;
  DAT_00b5ada4 = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009e9fac;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00704650 @ 0x00704650 ====

int FUN_00704650(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int extraout_EAX;
  char *pcVar3;
  int unaff_retaddr;
  undefined4 local_2c;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ea78;
  pvStack_c = ExceptionList;
  local_2c = 0;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5aae0 + 4))(param_2);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  pcVar3 = (char *)(iVar2 + 1);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar2 + 1),(int)pcVar3 - (iVar2 + 2));
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  puStack_8 = (undefined1 *)0x0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(&local_2c,0,0xffffffff);
  if (uStack_14 < 0x10) {
    ExceptionList = pvStack_10;
    return unaff_retaddr;
  }
  _free(pvStack_28);
  return extraout_EAX;
}


// ==== FUN_00704700 @ 0x00704700 ====

int FUN_00704700(int param_1,undefined1 param_2)

{
  int extraout_EAX;
  char *pcVar1;
  undefined4 uVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ea8a;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  switch(param_2) {
  case 0:
    uVar2 = 0xe;
    pcVar1 = s_<color_D800FF>_009e9f58;
    break;
  case 1:
    uVar2 = 0xe;
    pcVar1 = s_<color_FF6900>_009e9f68;
    break;
  case 2:
    uVar2 = 0xe;
    pcVar1 = s_<color_FFF600>_009e9f78;
    break;
  case 3:
    uVar2 = 0xe;
    pcVar1 = s_<color_00FFD2>_009e9f88;
    break;
  default:
    uVar2 = 0;
    pcVar1 = &DAT_009e9f97;
  }
  ExceptionList = &local_c;
  FUN_00401740(pcVar1,uVar2);
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


// ==== FUN_007047e0 @ 0x007047e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007047e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea0ec;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ada4 = (undefined4 *)0x0;
    _DAT_00000000 = 0;
    in_ECX[6] = 0;
    return;
  }
  DAT_00b5ada4 = in_ECX;
  in_ECX[1] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_00704850 @ 0x00704850 ====

undefined4 FUN_00704850(void)

{
  return 0x70490000;
}


// ==== FUN_00704860 @ 0x00704860 ====

undefined4 FUN_00704860(void)

{
  return 0x70490001;
}


// ==== FUN_00704870 @ 0x00704870 ====

undefined4 FUN_00704870(void)

{
  return 0x70490002;
}


// ==== FUN_00704880 @ 0x00704880 ====

undefined4 FUN_00704880(void)

{
  return 0x70490003;
}


// ==== FUN_00704890 @ 0x00704890 ====

undefined4 FUN_00704890(void)

{
  return 0x70490004;
}


// ==== FUN_007048a0 @ 0x007048a0 ====

undefined4 FUN_007048a0(void)

{
  return 0x70490012;
}


// ==== FUN_007048b0 @ 0x007048b0 ====

undefined4 FUN_007048b0(void)

{
  return 0x70490005;
}


// ==== FUN_007048c0 @ 0x007048c0 ====

undefined4 FUN_007048c0(void)

{
  return 0x70490006;
}


// ==== FUN_007048d0 @ 0x007048d0 ====

undefined4 FUN_007048d0(void)

{
  return 0x70490007;
}


// ==== FUN_007048e0 @ 0x007048e0 ====

undefined4 FUN_007048e0(void)

{
  return 0x70490008;
}


// ==== FUN_007048f0 @ 0x007048f0 ====

undefined4 FUN_007048f0(void)

{
  return 0x70490009;
}


// ==== FUN_00704900 @ 0x00704900 ====

undefined4 FUN_00704900(void)

{
  return 0x70490010;
}


// ==== FUN_00704910 @ 0x00704910 ====

undefined4 FUN_00704910(void)

{
  return 0x70490011;
}


// ==== FUN_00704920 @ 0x00704920 ====

undefined4 FUN_00704920(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_00704930 @ 0x00704930 ====

void FUN_00704930(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_00704940 @ 0x00704940 ====

void FUN_00704940(byte param_1)

{
  void *in_ECX;
  
  FUN_00704610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00704960 @ 0x00704960 ====

void FUN_00704960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea12c;
  return;
}


// ==== FUN_00704970 @ 0x00704970 ====

void FUN_00704970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea12c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00704990 @ 0x00704990 ====

int FUN_00704990(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_007049a0 @ 0x007049a0 ====

char * FUN_007049a0(char param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  while( true ) {
    if (puVar1 == *(undefined4 **)(in_ECX + 0xc)) {
      return (char *)0x0;
    }
    if (*(char *)*puVar1 == param_1) break;
    puVar1 = puVar1 + 1;
  }
  return (char *)*puVar1;
}


// ==== FUN_007049d0 @ 0x007049d0 ====

/* WARNING: Removing unreachable block (ram,0x00704a2c) */

int FUN_007049d0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  int *local_14;
  
  local_14 = *(int **)(in_ECX + 8);
  if (local_14 != *(int **)(in_ECX + 0xc)) {
    do {
      iVar1 = *local_14;
      iVar6 = *(int *)(iVar1 + 8);
      if (iVar6 != *(int *)(iVar1 + 0xc)) {
        uVar2 = *(uint *)(param_1 + 0x14);
        do {
          if (*(uint *)(param_1 + 0x18) < 0x10) {
            pbVar8 = (byte *)(param_1 + 4);
          }
          else {
            pbVar8 = *(byte **)(param_1 + 4);
          }
          uVar3 = *(uint *)(iVar6 + 0x14);
          if (uVar3 == 0) {
LAB_00704a5b:
            if ((uVar2 <= uVar3) && (uVar3 == uVar2)) {
              return iVar1;
            }
          }
          else {
            uVar4 = uVar3;
            if (uVar2 <= uVar3) {
              uVar4 = uVar2;
            }
            if (*(uint *)(iVar6 + 0x18) < 0x10) {
              pbVar7 = (byte *)(iVar6 + 4);
            }
            else {
              pbVar7 = *(byte **)(iVar6 + 4);
            }
            bVar9 = false;
            iVar5 = 0;
            bVar10 = true;
            do {
              if (uVar4 == 0) break;
              uVar4 = uVar4 - 1;
              bVar9 = *pbVar7 < *pbVar8;
              bVar10 = *pbVar7 == *pbVar8;
              pbVar7 = pbVar7 + 1;
              pbVar8 = pbVar8 + 1;
            } while (bVar10);
            if (!bVar10) {
              iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            }
            if (iVar5 == 0) goto LAB_00704a5b;
          }
          iVar6 = iVar6 + 0x1c;
        } while (iVar6 != *(int *)(iVar1 + 0xc));
      }
      local_14 = local_14 + 1;
    } while (local_14 != *(int **)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_00704ab0 @ 0x00704ab0 ====

short * FUN_00704ab0(short param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x18);
  while( true ) {
    if (puVar1 == *(undefined4 **)(in_ECX + 0x1c)) {
      return (short *)0x0;
    }
    if (*(short *)*puVar1 == param_1) break;
    puVar1 = puVar1 + 1;
  }
  return (short *)*puVar1;
}


// ==== FUN_00704ae0 @ 0x00704ae0 ====

void FUN_00704ae0(char param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *_Src;
  undefined4 *_Dst;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  _Dst = *(undefined4 **)(in_ECX + 8);
  _Src = _Dst;
  for (; _Dst != puVar1; _Dst = _Dst + 1) {
    _Src = _Src + 1;
    if (*(char *)*_Dst == param_1) {
      _memmove(_Dst,_Src,(*(int *)(in_ECX + 0xc) - (int)_Src >> 2) * 4);
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -4;
    }
  }
  return;
}


// ==== FUN_00704b30 @ 0x00704b30 ====

void FUN_00704b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea194;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ada8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ada8 = in_ECX;
  }
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  *(undefined1 *)((int)in_ECX + 0x25) = 1;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)((int)in_ECX + 0x32) = 0;
  *(undefined1 *)((int)in_ECX + 0x33) = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  return;
}


// ==== FUN_00704bb0 @ 0x00704bb0 ====

void FUN_00704bb0(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int *in_ECX;
  undefined1 uStack00000000;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))(param_1);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 2) = 1;
    *(undefined1 *)(iVar1 + 6) = (undefined1)param_1;
    *(undefined2 *)(iVar1 + 4) = param_2;
    return;
  }
  puVar2 = operator_new(8);
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    *puVar2 = 0;
    *(undefined1 *)(puVar2 + 1) = 0;
    puVar2[2] = 0;
    *(undefined1 *)(puVar2 + 3) = 0;
  }
  *(undefined1 *)(puVar2 + 1) = 1;
  *puVar2 = (short)param_1;
  *(undefined1 *)(puVar2 + 3) = (undefined1)param_1;
  puVar2[2] = param_2;
  FUN_00705040(&uStack00000000);
  return;
}


// ==== FUN_00704c30 @ 0x00704c30 ====

/* WARNING: Removing unreachable block (ram,0x00704c95) */

void FUN_00704c30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea194;
  DAT_00b5ada8 = 0;
  FUN_00705110(in_ECX + 1);
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  FUN_004f4a10(in_ECX + 5);
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009ea12c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00704cd0 @ 0x00704cd0 ====

void FUN_00704cd0(void)

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
  puStack_8 = &LAB_0098eab8;
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


// ==== FUN_00704d40 @ 0x00704d40 ====

void FUN_00704d40(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00704cd0();
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


// ==== FUN_00704f20 @ 0x00704f20 ====

void FUN_00704f20(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_00704f30 @ 0x00704f30 ====

void FUN_00704f30(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x25) = param_1;
  return;
}


// ==== FUN_00704f40 @ 0x00704f40 ====

undefined1 FUN_00704f40(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x25);
}


// ==== FUN_00704f50 @ 0x00704f50 ====

void FUN_00704f50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x25) = 1;
  return;
}


// ==== FUN_00704f60 @ 0x00704f60 ====

void FUN_00704f60(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_00704f70 @ 0x00704f70 ====

void FUN_00704f70(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = 0;
  return;
}


// ==== FUN_00704f80 @ 0x00704f80 ====

void FUN_00704f80(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_00704f90 @ 0x00704f90 ====

undefined2 FUN_00704f90(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x30);
}


// ==== FUN_00704fa0 @ 0x00704fa0 ====

void FUN_00704fa0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  return;
}


// ==== FUN_00704fb0 @ 0x00704fb0 ====

undefined1 FUN_00704fb0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x32);
}


// ==== FUN_00704fc0 @ 0x00704fc0 ====

void FUN_00704fc0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x32) = param_1;
  return;
}


// ==== FUN_00704fd0 @ 0x00704fd0 ====

undefined1 FUN_00704fd0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x33);
}


// ==== FUN_00704fe0 @ 0x00704fe0 ====

void FUN_00704fe0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x33) = param_1;
  return;
}


// ==== FUN_00704ff0 @ 0x00704ff0 ====

undefined1 FUN_00704ff0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x34);
}


// ==== FUN_00705000 @ 0x00705000 ====

void FUN_00705000(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x34) = param_1;
  return;
}


// ==== FUN_00705010 @ 0x00705010 ====

void FUN_00705010(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00705040 @ 0x00705040 ====

void FUN_00705040(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00704d40(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00705090 @ 0x00705090 ====

void FUN_00705090(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),in_ECX + 4);
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_007050d0 @ 0x007050d0 ====

undefined1 FUN_007050d0(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

{
  void *_Memory;
  undefined1 extraout_AL;
  
  while( true ) {
    if (param_1 == param_2) {
      return param_3;
    }
    _Memory = (void *)*param_1;
    if (_Memory != (void *)0x0) break;
    param_1 = param_1 + 1;
  }
  FUN_00705090();
  _free(_Memory);
  return extraout_AL;
}


// ==== FUN_00705110 @ 0x00705110 ====

void FUN_00705110(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    piVar1 = (int *)(param_1 + 8);
    iVar4 = *piVar1 - iVar2;
    if (iVar4 >> 2 != 0) {
      param_1._1_3_ = (uint3)(iVar4 >> 10);
      param_1 = (uint)param_1._1_3_ << 8;
      FUN_007050d0(iVar2,*piVar1,param_1);
      if (*(void **)(iVar3 + 4) != (void *)0x0) {
        _free(*(void **)(iVar3 + 4));
        return;
      }
      *(undefined4 *)(iVar3 + 4) = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
  }
  return;
}


// ==== FUN_00705160 @ 0x00705160 ====

void FUN_00705160(byte param_1)

{
  void *in_ECX;
  
  FUN_00704c30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00705180 @ 0x00705180 ====

void FUN_00705180(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea25c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007051a0 @ 0x007051a0 ====

void FUN_007051a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_007051d0 @ 0x007051d0 ====

void FUN_007051d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea274;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b130 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b130 = in_ECX;
  return;
}


// ==== FUN_00705220 @ 0x00705220 ====

void FUN_00705220(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b130 = 0;
  *in_ECX = &PTR_FUN_009ea25c;
  return;
}


// ==== FUN_00705240 @ 0x00705240 ====

void FUN_00705240(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5010000;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 4);
  FUN_004d8570(iVar3);
  (**(code **)(*DAT_00b5af2c + 4))(0);
                    /* WARNING: Could not recover jumptable at 0x0070529e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad84 + 0xc))();
  return;
}


// ==== FUN_007052b0 @ 0x007052b0 ====

void FUN_007052b0(void)

{
  int iVar1;
  int iVar2;
  void *unaff_ESI;
  int unaff_retaddr;
  undefined1 auStack_9a [2];
  undefined1 auStack_98 [4];
  uint uStack_94;
  undefined4 *puStack_90;
  undefined4 *puStack_8c;
  void *pvStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 *puStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_60;
  uint uStack_58;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined1 uStack_18;
  uint uStack_14;
  undefined1 *puStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098eb20;
  pvStack_c = ExceptionList;
  uStack_74 = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (*(char *)(unaff_retaddr + 0x1a) != '\0') {
    if (*(char *)(unaff_retaddr + 0x1a) == '\x02') {
      puStack_7c = (undefined1 *)0x0;
      uStack_80 = 0x7054c9;
      pvStack_88 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_80 = 0xffffffff;
      uStack_84 = 0;
      puStack_8c = (undefined4 *)0x7054e7;
      FUN_00401660();
      puStack_8 = auStack_98;
      uStack_80 = 0xf;
      uStack_84 = 0;
      puStack_10 = (undefined1 *)0x4;
      uStack_94 = uStack_94 & 0xffffff00;
      FUN_00401660(auStack_98 + 0x2c);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (uStack_74 < 0x10) {
        ExceptionList = pvStack_38;
        return;
      }
      unaff_ESI = pvStack_88;
    }
    else {
      puStack_7c = (undefined1 *)0x0;
      uStack_80 = 0x705536;
      pvStack_88 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_80 = 0xffffffff;
      uStack_84 = 0;
      pvStack_38 = (void *)0xf;
      uStack_3c = 0;
      uStack_4c = uStack_4c & 0xffffff00;
      puStack_8c = (undefined4 *)0x705554;
      FUN_00401660();
      puStack_8 = auStack_98;
      uStack_80 = 0xf;
      uStack_84 = 0;
      puStack_10 = (undefined1 *)0x5;
      uStack_94 = uStack_94 & 0xffffff00;
      FUN_00401660(&uStack_50);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (uStack_58 < 0x10) {
        ExceptionList = pvStack_38;
        return;
      }
    }
    _free(unaff_ESI);
    return;
  }
  if (*(char *)(unaff_retaddr + 0x19) == '\0') {
    puStack_7c = (undefined1 *)0x70530d;
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x2c))();
    if (iVar2 != 0) {
      puStack_7c = auStack_2c;
      uStack_80 = 0x705326;
      (**(code **)(*DAT_00b5ad20 + 0x40))();
      uStack_80 = 0x280034;
      uStack_84 = 0;
      puStack_10 = (undefined1 *)0x0;
      pvStack_88 = (void *)0x70533b;
      pvStack_88 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_8c = &uStack_3c;
      puStack_90 = &uStack_74;
      uStack_94 = 0x70534b;
      FUN_00405bd0();
      puStack_10 = auStack_9a + -6;
      pvStack_88 = (void *)0xf;
      puStack_8c = (undefined4 *)0x0;
      uStack_18 = 1;
      FUN_00401660(&uStack_74,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0);
      uStack_80 = 0x705390;
      puStack_7c = (undefined1 *)iVar1;
      FUN_008273e0();
      if (0xf < uStack_4c) {
        puStack_7c = (undefined1 *)0x7053a8;
        _free(uStack_60);
        return;
      }
      uStack_4c = 0xf;
      uStack_50 = 0;
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_14) {
        puStack_7c = (undefined1 *)0x7053d3;
        _free(pvStack_28);
        return;
      }
    }
  }
  else if (*(char *)(unaff_retaddr + 0x19) == '\x01') {
    puStack_7c = (undefined1 *)0x7053ef;
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x20) + 0x28))();
    if (iVar2 != 0) {
      puStack_7c = auStack_98 + 0x34;
      uStack_80 = 0x705408;
      (**(code **)(*DAT_00b5ad20 + 0x40))();
      uStack_80 = 0x280034;
      uStack_84 = 0;
      puStack_10 = (undefined1 *)0x2;
      pvStack_88 = (void *)0x705421;
      pvStack_88 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_8c = &uStack_74;
      puStack_90 = &uStack_3c;
      uStack_94 = 0x705431;
      FUN_00405bd0();
      uStack_18 = 3;
      pvStack_88 = (void *)CONCAT13(pvStack_88._3_1_,*(undefined3 *)(unaff_retaddr + 0x10));
      puStack_90 = (undefined4 *)0x70544d;
      puStack_8c = (undefined4 *)iVar1;
      FUN_00827380();
      puStack_10 = auStack_9a + -6;
      FUN_00765c50(&uStack_3c);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 8))();
  ExceptionList = puStack_10;
  return;
}


// ==== FUN_007055c0 @ 0x007055c0 ====

void FUN_007055c0(undefined4 param_1)

{
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_68;
  void **ppvStack_64;
  undefined1 *puStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  void *pvStack_54;
  undefined1 *puStack_50;
  undefined4 uStack_4c;
  uint uStack_40;
  void *pvStack_3c;
  undefined1 auStack_38 [16];
  undefined1 local_28 [20];
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098eb3a;
  puStack_c = ExceptionList;
  uStack_4c = param_1;
  puStack_50 = local_28;
  pvStack_54 = (void *)0x7055ee;
  ExceptionList = &puStack_c;
  (**(code **)(*DAT_00b5ad20 + 0x40))();
  pvStack_54 = (void *)0x280034;
  uStack_58 = 0;
  puStack_c = (undefined1 *)0x0;
  uStack_5c = 0x705605;
  uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_60 = auStack_38;
  ppvStack_64 = &pvStack_54;
  uStack_68 = 0x705615;
  FUN_00405bd0();
  puStack_c = auStack_74;
  uStack_5c = 0xf;
  puStack_60 = (undefined1 *)0x0;
  uStack_14 = 1;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  FUN_00401660(&pvStack_54,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(0);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return;
  }
  uStack_5c = 0xf;
  puStack_60 = (undefined1 *)0x0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (uStack_40 < 0x10) {
    ExceptionList = pvStack_3c;
    return;
  }
  _free(pvStack_54);
  return;
}


// ==== FUN_007056a0 @ 0x007056a0 ====

undefined4 FUN_007056a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x52f0000) {
    FUN_007052b0(*(undefined4 *)(param_1 + 0xc));
  }
  else if (iVar1 != 0x52f0001) {
    if (iVar1 == 0x52f0003) {
      (**(code **)(*DAT_00b5acd8 + 8))(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10));
      return 1;
    }
    return 0;
  }
  return 1;
}


// ==== FUN_00705700 @ 0x00705700 ====

undefined4 FUN_00705700(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007056a0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00705730 @ 0x00705730 ====

void FUN_00705730(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5010000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00705760 @ 0x00705760 ====

void FUN_00705760(byte param_1)

{
  void *in_ECX;
  
  FUN_00705220();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00705780 @ 0x00705780 ====

void FUN_00705780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea2e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007057a0 @ 0x007057a0 ====

void FUN_007057a0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_007057b0 @ 0x007057b0 ====

void FUN_007057b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea308;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae58 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae58 = in_ECX;
  return;
}


// ==== FUN_007057e0 @ 0x007057e0 ====

void FUN_007057e0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae58 = 0;
  *in_ECX = &PTR_FUN_009ea2e0;
  return;
}


// ==== FUN_00705800 @ 0x00705800 ====

void FUN_00705800(undefined2 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x52d0001;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined2 *)(iVar3 + 0x10) = param_1;
  FUN_004d8570(iVar3);
  (**(code **)(*DAT_00b5ae5c + 0x24))();
  return;
}


// ==== FUN_00705860 @ 0x00705860 ====

void FUN_00705860(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 2) {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5310001;
  }
  else {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x52d0003;
  }
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_007058c0 @ 0x007058c0 ====

void FUN_007058c0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 2) {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5310003;
  }
  else {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x52d0005;
  }
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00705920 @ 0x00705920 ====

void FUN_00705920(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  uint uVar8;
  undefined1 *unaff_EBP;
  uint unaff_EDI;
  undefined4 uStack_70;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined1 auStack_46 [10];
  uint uStack_3c;
  void *pvStack_38;
  undefined1 local_28 [16];
  int iStack_18;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098eb60;
  pvStack_c = ExceptionList;
  puStack_5c = local_28;
  uStack_60 = 0x70594c;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5adc0 + 0x10))();
  puStack_8 = (undefined1 *)0x0;
  if (iStack_18 == 0) {
    uStack_60 = 0x8360013;
    uStack_64 = 0;
    uStack_68 = 0x70596d;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    pvStack_6c = (void *)0x0;
    pvStack_38 = (void *)0xf;
    uStack_3c = 0;
    FUN_00401660();
    uStack_68 = 0xf;
    pvStack_6c = (void *)0x0;
    uStack_10 = 1;
    FUN_00401660(auStack_46 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < unaff_EDI) {
      _free(pvStack_6c);
      return;
    }
    puStack_5c = (undefined1 *)0x0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  }
  else {
    uStack_60 = 0x7059f4;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x52d0007;
    *(undefined2 *)((int)pvVar4 + 6) = 0x2c;
    iVar5 = FUN_004244d0();
    puVar6 = unaff_EBP;
    if (uStack_3c < 0x10) {
      puVar6 = auStack_46 + -10;
    }
    FUN_0047aa30(&uStack_70,&DAT_009ea2c4,puVar6);
    pcVar1 = (char *)(iVar5 + 0x10);
    uVar8 = 0;
    pcVar7 = pcVar1;
    do {
      cVar2 = pcVar7[(int)(auStack_46 + (-0x2a - (int)pcVar1))];
      *pcVar7 = cVar2;
      if (cVar2 == '\0') goto LAB_00705a66;
      uVar8 = uVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (uVar8 < 0x19);
    *pcVar1 = '\0';
LAB_00705a66:
    FUN_004d8570(iVar5);
  }
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_00705aa0 @ 0x00705aa0 ====

void FUN_00705aa0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00705ab0 @ 0x00705ab0 ====

void FUN_00705ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_007057e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00705ad0 @ 0x00705ad0 ====

void FUN_00705ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea348;
  return;
}


// ==== __break @ 0x00705adc ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00705ae0 @ 0x00705ae0 ====

void FUN_00705ae0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea348;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00705b00 @ 0x00705b00 ====

void FUN_00705b00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_00705b10 @ 0x00705b10 ====

void FUN_00705b10(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x14) = *param_1;
  *(undefined1 *)(in_ECX + 0x16) = *(undefined1 *)(param_1 + 1);
  return;
}


// ==== FUN_00705b30 @ 0x00705b30 ====

int FUN_00705b30(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= param_1)) {
    param_1 = FUN_00705e10();
  }
  return param_1 * 0x20 + iVar1;
}


// ==== FUN_00705b60 @ 0x00705b60 ====

void FUN_00705b60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ebf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ea374;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 1;
  *(undefined1 *)((int)in_ECX + 0x15) = 1;
  *(undefined1 *)((int)in_ECX + 0x16) = 1;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  FUN_00793e00();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae54 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ae54 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00705be0 @ 0x00705be0 ====

void FUN_00705be0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea374;
  FUN_00793e00();
  DAT_00b5ae54 = 0;
  FUN_00793e00();
  *in_ECX = &PTR_FUN_009ea348;
  return;
}


// ==== FUN_00705c10 @ 0x00705c10 ====

void FUN_00705c10(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 auStack_88 [4];
  void *pvStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ec1d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00793e00();
  piVar5 = *(int **)(iVar3 + 0x9c);
  if (piVar5 == (int *)0x0) {
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    FUN_00401740(s_pManager____NULL_009ea330,0x10);
    uStack_4 = 0;
    FUN_00406880(auStack_48);
    uStack_4 = 0xffffffff;
    if (uStack_30 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_44);
    return;
  }
  iVar3 = *piVar5;
  uVar4 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  (**(code **)(iVar3 + 0x18))(uVar4);
  piVar5 = (int *)(**(code **)(*piVar5 + 0x1c))();
  if ((piVar5 != (int *)0x0) &&
     (piVar5 = (int *)(**(code **)(*piVar5 + 0x14))(), piVar5 != (int *)0x0)) {
    uVar6 = (**(code **)(*piVar5 + 8))();
    uVar10 = 0;
    if (uVar6 != 0) {
      do {
        puVar7 = (undefined4 *)(**(code **)(*piVar5 + 0xc))(uVar10);
        puVar9 = &uStack_30;
        for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        uStack_54 = 0xf;
        uStack_58 = 0;
        pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
        uStack_50 = uStack_30 & 0xffff;
        pcVar8 = (char *)((int)&uStack_30 + 2);
        puStack_8 = (undefined1 *)0x1;
        uStack_70 = 0xf;
        uStack_74 = 0;
        pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_00401740((int)&uStack_30 + 2,(int)pcVar8 - ((int)&uStack_30 + 3));
        puStack_8._0_1_ = 2;
        FUN_00401660(auStack_88,0,0xffffffff);
        puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
        if (0xf < uStack_70) {
          _free(pvStack_84);
          return;
        }
        uStack_70 = 0xf;
        uStack_74 = 0;
        pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
        FUN_00706380(auStack_6c);
        puStack_8 = (undefined1 *)0xffffffff;
        if (0xf < uStack_54) {
          _free(pvStack_68);
          return;
        }
        uVar10 = uVar10 + 1;
        uStack_54 = 0xf;
        uStack_58 = 0;
        pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
      } while (uVar10 < uVar6);
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00705e10 @ 0x00705e10 ====

void FUN_00705e10(void)

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
  puStack_8 = &LAB_0098eb78;
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


// ==== FUN_00705e80 @ 0x00705e80 ====

void FUN_00705e80(void)

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
  puStack_8 = &LAB_0098eb78;
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


// ==== FUN_00705ef0 @ 0x00705ef0 ====

int FUN_00705ef0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0098eba1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    local_8 = 1;
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x18) = 0xf;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined1 *)(param_3 + 4) = 0;
      FUN_00401660(param_1,0,0xffffffff);
      *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    }
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00705f5c @ 0x00705f5c ====

void Catch_00705f5c(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 0x10);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x20;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_00705fb0 @ 0x00705fb0 ====

void FUN_00705fb0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0098ebc1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    }
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00706021 @ 0x00706021 ====

void Catch_00706021(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 8);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x20;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_00706070 @ 0x00706070 ====

int FUN_00706070(int param_1,int param_2,undefined4 param_3)

{
  FUN_00705fb0(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_007060a0 @ 0x007060a0 ====

void FUN_007060a0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined1 local_3c [2];
  undefined1 auStack_3a [2];
  void *local_38;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098ebd8;
  local_10 = ExceptionList;
  local_14 = local_3c + -0xc;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_20 = *(undefined4 *)(param_3 + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
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
      uVar1 = FUN_00705e80();
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
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 + (uVar1 >> 1);
      }
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (uVar1 < iVar5 + param_2) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 5;
        }
        uVar1 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar1 * 0x20);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00705ef0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00705fb0(iVar2,param_2,local_3c);
      FUN_00705ef0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x20);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (iVar2 != 0) {
        FUN_00793d10(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      local_1c = *(void **)(in_ECX + 8);
      if ((uint)((int)local_1c - param_1 >> 5) < param_2) {
        FUN_00705ef0(param_1,local_1c,param_2 * 0x20 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00706070(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),local_3c);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x20;
        local_8 = 0;
        FUN_00793c20(param_1,*(int *)(in_ECX + 8) + param_2 * -0x20,local_3c);
      }
      else {
        pvVar3 = (void *)((int)local_1c + param_2 * -0x20);
        uVar4 = FUN_00705ef0(pvVar3,local_1c,local_1c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0068e670(param_1,pvVar3,local_1c,param_1);
        FUN_00793c20(param_1,param_2 * 0x20 + param_1,local_3c);
      }
    }
  }
  if (local_24 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_38);
  return;
}


// ==== Catch@00706234 @ 0x00706234 ====

void Catch_00706234(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00793d10(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@007062c3 @ 0x007062c3 ====

void Catch_007062c3(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_00793d10(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00706350 @ 0x00706350 ====

int FUN_00706350(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_00706360 @ 0x00706360 ====

int FUN_00706360(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5;
}


// ==== FUN_00706380 @ 0x00706380 ====

void FUN_00706380(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_007060a0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00705fb0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_007063f0 @ 0x007063f0 ====

void FUN_007063f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00705be0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00706410 @ 0x00706410 ====

void FUN_00706410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea744;
  return;
}


// ==== FUN_00706420 @ 0x00706420 ====

void FUN_00706420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea744;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00706440 @ 0x00706440 ====

undefined4 FUN_00706440(void)

{
  return 0x70930000;
}


// ==== FUN_00706450 @ 0x00706450 ====

undefined4 FUN_00706450(void)

{
  return 0x70930001;
}


// ==== FUN_00706460 @ 0x00706460 ====

undefined4 FUN_00706460(void)

{
  return 0x70930002;
}


// ==== FUN_00706470 @ 0x00706470 ====

undefined4 FUN_00706470(void)

{
  return 0x70930003;
}


// ==== FUN_00706480 @ 0x00706480 ====

undefined4 FUN_00706480(void)

{
  return 0x70930004;
}


// ==== FUN_00706490 @ 0x00706490 ====

undefined4 FUN_00706490(void)

{
  return 0x70930005;
}


// ==== FUN_007064a0 @ 0x007064a0 ====

undefined4 FUN_007064a0(void)

{
  return 0x70930006;
}


// ==== FUN_007064b0 @ 0x007064b0 ====

undefined4 FUN_007064b0(void)

{
  return 0x70930007;
}


// ==== FUN_007064c0 @ 0x007064c0 ====

undefined4 FUN_007064c0(void)

{
  return 0x70930008;
}


// ==== FUN_007064d0 @ 0x007064d0 ====

undefined4 FUN_007064d0(void)

{
  return 0x70930009;
}


// ==== FUN_007064e0 @ 0x007064e0 ====

undefined4 FUN_007064e0(void)

{
  return 0x70930010;
}


// ==== FUN_007064f0 @ 0x007064f0 ====

undefined4 FUN_007064f0(void)

{
  return 0x70930011;
}


// ==== FUN_00706500 @ 0x00706500 ====

undefined4 FUN_00706500(void)

{
  return 0x70930012;
}


// ==== FUN_00706510 @ 0x00706510 ====

void FUN_00706510(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea788;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706540 @ 0x00706540 ====

void FUN_00706540(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea79c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706570 @ 0x00706570 ====

void FUN_00706570(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea7b0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007065a0 @ 0x007065a0 ====

void FUN_007065a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea7d8;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007065d0 @ 0x007065d0 ====

void FUN_007065d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea7ec;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706600 @ 0x00706600 ====

void FUN_00706600(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea800;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706630 @ 0x00706630 ====

void FUN_00706630(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea814;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706660 @ 0x00706660 ====

void FUN_00706660(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea828;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706690 @ 0x00706690 ====

void FUN_00706690(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea83c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007066c0 @ 0x007066c0 ====

void FUN_007066c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea850;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007066f0 @ 0x007066f0 ====

void FUN_007066f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ea864;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00706720 @ 0x00706720 ====

void FUN_00706720(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ea878;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*in_ECX + 0x24))();
                    /* WARNING: Could not recover jumptable at 0x00706750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x34))();
  return;
}


// ==== FUN_00706760 @ 0x00706760 ====

undefined4 FUN_00706760(int param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  iVar3 = param_1 + 8;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_observerenter_009ea610,0x12);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_observerenter_009ea624,0x12);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_observerareamove_009ea638,0x15);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x20))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_hide_observerareamove_009ea650);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x24))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_show_observerenterconfirm_009ea668);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x18))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_hide_observerenterconfirm_009ea684);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x1c))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_show_observerexit_009ea6a0);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x28))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_hide_observerexit_009ea6b4);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x2c))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_show_observeroption_009ea6c8);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x30))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_hide_observeroption_009ea6dc);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x34))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_load_movelist_009ea6f0);
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5ae54 + 0x14))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_show_observerpop_009ea700);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x38))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_hide_observerpop_009ea714);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*in_ECX + 0x3c))();
  return 1;
}


// ==== FUN_00706930 @ 0x00706930 ====

uint FUN_00706930(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70004) {
    uVar1 = FUN_00706760(param_1);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00706960 @ 0x00706960 ====

void FUN_00706960(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_2a [6];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ec38;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5ae54 + 0x24))();
  if (*(char *)(iVar1 + 2) == '\0') {
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
  else {
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009ea7c4;
    }
    FUN_00797a20();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00706a50 @ 0x00706a50 ====

void FUN_00706a50(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined1 auStackY_100 [8];
  undefined1 *puVar1;
  undefined1 auStack_ce [6];
  undefined1 **ppuVar2;
  undefined1 **ppuVar3;
  undefined1 *puStack_b8;
  undefined4 uStack_b4;
  undefined4 **ppuVar4;
  undefined1 *puStack_ac;
  undefined4 uStack_a8;
  undefined1 **ppuVar5;
  undefined1 *puStack_a0;
  undefined1 auStack_9c [4];
  uint **ppuVar6;
  undefined1 *puStack_94;
  undefined4 uStack_90;
  undefined1 *puVar7;
  undefined1 *puStack_88;
  undefined4 uStack_84;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  uint *puVar8;
  undefined1 *puStack_70;
  undefined4 uStack_6c;
  uint *puVar9;
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
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ed1a;
  pvStack_c = ExceptionList;
  uStack_5c = (uint *)0x0;
  pcStack_60 = &DAT_009ea3d6;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ea88c;
  *(undefined1 *)(in_ECX + 1) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  puStack_64 = (uint *)0x706aa2;
  FUN_00401740();
  uStack_5c = (uint *)0x12;
  pcStack_60 = s_show_observerenter_009ea3d8;
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  puStack_64 = (uint *)0x706ac3;
  FUN_00401740();
  uStack_5c = &local_28;
  pcStack_60 = (char *)0x0;
  puStack_64 = &local_44;
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_38) {
    uStack_6c = (char *)0x706af3;
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    uStack_6c = (char *)0x706b16;
    _free(local_30);
    return;
  }
  uStack_6c = &DAT_009ea3eb;
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  puStack_70 = (undefined1 *)0x706b34;
  FUN_00401740();
  uStack_6c = s_hide_observerenter_009ea3ec;
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  puStack_70 = (undefined1 *)0x706b55;
  FUN_00401740();
  puVar9 = &uStack_34;
  uStack_6c = (char *)0x0;
  puStack_70 = auStack_46 + -10;
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    uStack_78 = (char *)0x706b80;
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = uStack_1c & 0xffffff00;
  if (0xf < local_28) {
    uStack_78 = (char *)0x706ba3;
    _free(pvStack_3c);
    return;
  }
  uStack_78 = &DAT_009ea3ff;
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  puStack_7c = (undefined4 *)0x706bc1;
  FUN_00401740();
  uStack_78 = s_show_observerareamove_009ea400;
  uStack_1c._0_1_ = 5;
  local_44 = 0xf;
  puStack_7c = (undefined4 *)0x706be2;
  FUN_00401740();
  puVar8 = &local_40;
  uStack_78 = (char *)0x0;
  puStack_7c = &uStack_5c;
  uStack_1c = CONCAT31(uStack_1c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < unaff_EBP) {
    uStack_84 = (char *)0x706c0d;
    _free(puStack_64);
    return;
  }
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  local_28 = local_28 & 0xffffff00;
  if (0xf < uStack_34) {
    uStack_84 = (char *)0x706c30;
    _free((void *)0x0);
    return;
  }
  uStack_84 = &DAT_009ea416;
  uStack_34 = 0xf;
  uStack_38 = 0;
  puStack_88 = (undefined1 *)0x706c4e;
  FUN_00401740();
  uStack_84 = s_hide_observerareamove_009ea418;
  local_28._0_1_ = 7;
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  puStack_88 = (undefined1 *)0x706c6f;
  FUN_00401740();
  puVar1 = auStack_46 + -6;
  uStack_84 = (char *)0x0;
  puStack_88 = auStack_46 + -0x22;
  local_28 = CONCAT31(local_28._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < uStack_5c) {
    uStack_90 = (char *)0x706c9a;
    _free(puStack_70);
    return;
  }
  uStack_5c = (uint *)0xf;
  pcStack_60 = (char *)0x0;
  puStack_70 = (undefined1 *)((uint)puStack_70 & 0xffffff00);
  uStack_34 = uStack_34 & 0xffffff00;
  if (0xf < local_40) {
    uStack_90 = (char *)0x706cbd;
    _free((void *)0x0);
    return;
  }
  uStack_90 = &DAT_009ea42e;
  local_40 = 0xf;
  local_44 = 0;
  puStack_94 = (undefined1 *)0x706cdb;
  FUN_00401740();
  uStack_90 = s_show_observerenterconfirm_009ea430;
  uStack_34._0_1_ = 9;
  uStack_5c = (uint *)0xf;
  pcStack_60 = (void *)0x0;
  puStack_70 = (undefined1 *)((uint)puStack_70 & 0xffffff00);
  puStack_94 = (undefined1 *)0x706cfc;
  FUN_00401740();
  puVar7 = auStack_46 + -0x12;
  uStack_90 = (char *)0x0;
  puStack_94 = auStack_9c + 0x28;
  uStack_34 = CONCAT31(uStack_34._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar9) {
    _free(puStack_7c);
    return;
  }
  uStack_6c = (char *)0x0;
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  local_40 = local_40 & 0xffffff00;
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free(pcStack_60);
    return;
  }
  pcStack_60 = (char *)((uint)pcStack_60 & 0xffffff00);
  FUN_00401740();
  local_40._0_1_ = 0xb;
  uStack_6c = (void *)0x0;
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  FUN_00401740();
  ppuVar6 = &puStack_64;
  local_40 = CONCAT31(local_40._1_3_,0xc);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar8) {
    uStack_a8 = (char *)0x706db4;
    _free(puStack_88);
    return;
  }
  uStack_78 = (char *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  if (0xf < ((uint)unaff_EDI & 0xffffff00)) {
    uStack_a8 = (char *)0x706dd7;
    _free(uStack_6c);
    return;
  }
  uStack_a8 = &DAT_009ea466;
  uStack_5c = (uint *)0x0;
  uStack_6c = (char *)((uint)uStack_6c & 0xffffff00);
  puStack_ac = (undefined1 *)0x706df5;
  FUN_00401740();
  uStack_a8 = s_show_observerexit_009ea468;
  uStack_78 = (void *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  puStack_ac = (undefined1 *)0x706e16;
  FUN_00401740();
  ppuVar5 = &puStack_70;
  uStack_a8 = (char *)0x0;
  puStack_ac = auStack_9c + 0x10;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((undefined1 *)0xf < puVar1) {
    uStack_b4 = (char *)0x706e41;
    _free(puStack_94);
    return;
  }
  uStack_84 = (char *)0x0;
  puStack_94 = (undefined1 *)((uint)puStack_94 & 0xffffff00);
  if ((uint *)0xf < puStack_64) {
    uStack_b4 = (char *)0x706e64;
    _free(uStack_78);
    return;
  }
  uStack_b4 = &DAT_009ea47a;
  puStack_64 = (uint *)0xf;
  uStack_78 = (char *)((uint)uStack_78 & 0xffffff00);
  puStack_b8 = (undefined1 *)0x706e82;
  FUN_00401740();
  uStack_b4 = s_hide_observerexit_009ea47c;
  uStack_84 = (void *)0x0;
  puStack_94 = (undefined1 *)((uint)puStack_94 & 0xffffff00);
  puStack_b8 = (undefined1 *)0x706ea3;
  FUN_00401740();
  ppuVar4 = &puStack_7c;
  uStack_b4 = (char *)0x0;
  puStack_b8 = auStack_9c + 4;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((undefined1 *)0xf < puVar7) {
    _free(auStack_9c + 0x1c);
    return;
  }
  uStack_90 = (char *)0x0;
  puStack_a0 = auStackY_100;
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  if ((undefined1 *)0xf < puStack_70) {
    _free(uStack_84);
    return;
  }
  puStack_70 = (undefined1 *)0xf;
  uStack_84 = (char *)((uint)uStack_84 & 0xffffff00);
  FUN_00401740();
  puStack_64._0_1_ = 0x11;
  uStack_90 = (void *)0x0;
  FUN_00401740();
  ppuVar3 = &puStack_88;
  puStack_64 = (uint *)CONCAT31(puStack_64._1_3_,0x12);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint **)0xf < ppuVar6) {
    _free(puStack_ac);
    return;
  }
  puStack_ac = (undefined1 *)((uint)puStack_ac & 0xffffff00);
  puStack_70 = (undefined1 *)((uint)puStack_70 & 0xffffff00);
  if ((undefined4 *)0xf < puStack_7c) {
    _free(uStack_90);
    return;
  }
  puStack_7c = (undefined4 *)0xf;
  uStack_90 = (char *)((uint)uStack_90 & 0xffffff00);
  FUN_00401740();
  puStack_70._0_1_ = 0x13;
  puStack_ac = (undefined1 *)((uint)puStack_ac & 0xffffff00);
  FUN_00401740();
  ppuVar2 = &puStack_94;
  puStack_70 = (undefined1 *)CONCAT31(puStack_70._1_3_,0x14);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((undefined1 **)0xf < ppuVar5) {
    _free(puStack_b8);
    return;
  }
  uStack_a8 = (char *)0x0;
  puStack_b8 = (undefined1 *)((uint)puStack_b8 & 0xffffff00);
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  if ((undefined1 *)0xf < puStack_88) {
    _free((void *)0x0);
    return;
  }
  puStack_88 = (undefined1 *)0xf;
  FUN_00401740(&DAT_009ea4bc);
  puStack_7c._0_1_ = 0x15;
  uStack_a8 = (void *)0x0;
  puStack_b8 = (undefined1 *)((uint)puStack_b8 & 0xffffff00);
  FUN_00401740(s_load_movelist_009ea4c0);
  puVar1 = auStack_ce + 0x12;
  puStack_7c = (undefined4 *)CONCAT31(puStack_7c._1_3_,0x16);
  (**(code **)(*DAT_00b5a6c8 + 8))(puVar1,0);
  if ((undefined4 **)0xf < ppuVar4) {
    _free(auStack_9c + -8);
    return;
  }
  uStack_b4 = (char *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  if ((undefined1 *)0xf < puStack_94) {
    _free(uStack_a8);
    return;
  }
  puStack_94 = (undefined1 *)0xf;
  uStack_a8 = (char *)((uint)uStack_a8 & 0xffffff00);
  FUN_00401740(&DAT_009ea4ce,0);
  puStack_88._0_1_ = 0x17;
  uStack_b4 = (void *)0x0;
  FUN_00401740(s_show_observerpop_009ea4d0,0x10);
  puStack_88 = (undefined1 *)CONCAT31(puStack_88._1_3_,0x18);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_ce + 6,0,&puStack_ac);
  if ((undefined1 **)0xf < ppuVar3) {
    _free(auStack_9c + -0x14);
    return;
  }
  puStack_94 = (undefined1 *)((uint)puStack_94 & 0xffffff00);
  if ((undefined1 *)0xf < puStack_a0) {
    _free(uStack_b4);
    return;
  }
  uStack_b4 = (char *)((uint)uStack_b4 & 0xffffff00);
  FUN_00401740(&DAT_009ea4e1,0);
  puStack_94._0_1_ = 0x19;
  FUN_00401740(s_hide_observerpop_009ea4e4,0x10);
  puStack_94 = (undefined1 *)CONCAT31(puStack_94._1_3_,0x1a);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_ce + -6,0,&puStack_b8);
  if ((undefined1 **)0xf < ppuVar2) {
    _free(puVar1);
    return;
  }
  if ((undefined1 *)0xf < puStack_ac) {
    _free((void *)0x0);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae5c = (undefined4 *)0x0;
    ExceptionList = uStack_a8;
    return;
  }
  DAT_00b5ae5c = in_ECX;
  ExceptionList = uStack_a8;
  return;
}


// ==== FUN_007071f0 @ 0x007071f0 ====

/* WARNING: Removing unreachable block (ram,0x007074f2) */
/* WARNING: Removing unreachable block (ram,0x007074aa) */
/* WARNING: Removing unreachable block (ram,0x0070753a) */
/* WARNING: Removing unreachable block (ram,0x00707462) */
/* WARNING: Removing unreachable block (ram,0x0070741a) */

void FUN_007071f0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 *_Memory;
  void *_Memory_00;
  uint uVar1;
  undefined4 uStack_40;
  void *local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ed94;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ea88c;
  uStack_40 = (void **)0x12;
  local_4 = 0;
  DAT_00b5ae5c = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401740();
  uStack_40 = &local_28;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740();
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  local_14 = local_14 & 0xffffff00;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  FUN_00401740();
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_18 = uStack_18 & 0xffffff00;
  if (0xf < local_24) {
    _free(unaff_ESI);
    return;
  }
  local_24 = 0xf;
  local_28 = (void *)0x0;
  FUN_00401740();
  _Memory_00 = (void *)((int)register0x00000010 + -0x3c);
  uStack_18 = CONCAT31(uStack_18._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_1c = uStack_1c & 0xffffff00;
  if ((void *)0xf < local_28) {
    _free(unaff_EDI);
    return;
  }
  local_28 = (void *)0xf;
  FUN_00401740(s_show_observerexit_009ea588);
  _Memory = &uStack_40;
  uStack_1c = CONCAT31(uStack_1c._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_20 = uStack_20 & 0xffffff00;
  uStack_40 = (void **)((uint)uStack_40 & 0xffffff00);
  FUN_00401740(s_hide_observerexit_009ea59c,0x11);
  uStack_20 = CONCAT31(uStack_20._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x44);
  local_24 = local_24 & 0xffffff00;
  FUN_00401740(s_show_observeroption_009ea5b0,0x13);
  local_24 = CONCAT31(local_24._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x48);
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_observeroption_009ea5c4,0x13);
  local_28 = (void *)CONCAT31(local_28._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x4c);
  FUN_00401740(s_load_movelist_009ea5d8,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x50);
  uStack_40 = (void **)0x0;
  FUN_00401740(s_show_observerpop_009ea5e8,0x10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x54);
  if (0xf < uStack_40) {
    _free(_Memory_00);
    return;
  }
  uStack_40 = (void *)0xf;
  uVar1 = 0;
  FUN_00401740(s_hide_observerpop_009ea5fc,0x10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x58);
  if (uVar1 < 0x10) {
    *in_ECX = &PTR_FUN_009ea744;
    ExceptionList = uStack_40;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_007075f0 @ 0x007075f0 ====

void FUN_007075f0(byte param_1)

{
  void *in_ECX;
  
  FUN_007071f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00707610 @ 0x00707610 ====

void FUN_00707610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea974;
  return;
}


// ==== FUN_00707620 @ 0x00707620 ====

void FUN_00707620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ea974;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00707650 @ 0x00707650 ====

void FUN_00707650(void)

{
  int unaff_retaddr;
  
  (**(code **)(*DAT_00b5af2c + 8))(4);
  (**(code **)(*DAT_00b5ae54 + 4))(*(undefined4 *)(unaff_retaddr + 0x14));
  (**(code **)(*DAT_00b5ae54 + 0xc))(*(undefined4 *)(unaff_retaddr + 0x10));
  (**(code **)(*DAT_00b5ae5c + 0xc))();
                    /* WARNING: Could not recover jumptable at 0x0070769c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae58 + 0x1c))(1);
  return;
}


// ==== FUN_007076a0 @ 0x007076a0 ====

void FUN_007076a0(void)

{
  int unaff_retaddr;
  
  (**(code **)(*DAT_00b5af2c + 8))(4);
  (**(code **)(*DAT_00b5ae54 + 4))(*(undefined4 *)(unaff_retaddr + 0x14));
  (**(code **)(*DAT_00b5ae54 + 0xc))(*(undefined4 *)(unaff_retaddr + 0x10));
  (**(code **)(*DAT_00b5ae5c + 0xc))();
                    /* WARNING: Could not recover jumptable at 0x007076ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae58 + 0x1c))(2);
  return;
}


// ==== FUN_007076f0 @ 0x007076f0 ====

void FUN_007076f0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  void *pvStack_28;
  void *pvStack_24;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098eda8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ae5c + 0x10))();
  if (*(int *)(param_1 + 0x10) == 0) {
    (**(code **)(*DAT_00b5ac98 + 0x30))();
    uStack_40 = 0x707741;
    (**(code **)(*DAT_00b5ae58 + 4))();
    uStack_40 = 1;
    uStack_44 = 0x70774e;
    (**(code **)(*DAT_00b5a97c + 0x48))();
    uStack_44 = 0x707759;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    iVar1 = **(int **)(iVar1 + 0x50);
    uStack_44 = 0x707769;
    uStack_44 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_48 = 0x70776f;
    piVar2 = (int *)(**(code **)(iVar1 + 0x14))();
    uStack_48 = *(undefined4 *)(param_1 + 0x24);
    uStack_4c = CONCAT31((int3)((uint)uStack_48 >> 8),*(undefined1 *)(param_1 + 0x22));
    uStack_50 = 0x707781;
    (**(code **)(*piVar2 + 0xe8))();
    uStack_50 = 1;
    uStack_54 = param_1 + 0x1c;
    uStack_58 = 0x707792;
    FUN_0053acd0();
    uStack_50 = 1;
    uStack_54 = CONCAT13((char)((uint)DAT_00b5a980 >> 0x18),*(undefined3 *)(param_1 + 0x14));
    uStack_58 = 0x7077b1;
    uStack_58 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_5c = 0x7077b7;
    FUN_00827440();
    ExceptionList = pvStack_24;
    return;
  }
  (**(code **)(*DAT_00b5ae58 + 0x1c))();
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  default:
    goto switchD_007077e9_default;
  }
  uStack_40 = 0;
  uStack_44 = 0x707833;
  uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_44 = 0xffffffff;
  uStack_48 = 0;
  uStack_50 = 0x707851;
  FUN_00401660();
  puStack_8 = (undefined1 *)&uStack_5c;
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_10 = (void *)0x0;
  uStack_58 = uStack_58 & 0xffffff00;
  FUN_00401660((int)register0x00000010 + -0x34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_14) {
    uStack_40 = 0x707892;
    _free(pvStack_28);
    return;
  }
switchD_007077e9_default:
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007078d0 @ 0x007078d0 ====

void FUN_007078d0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined1 auStack_26 [2];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098edba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1 + 0x10) == 0) {
    iStack_40 = 0x707903;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5ae58 + 4))();
    iStack_40 = 0;
    uStack_44 = 0x70790f;
    (**(code **)(*DAT_00b5ae58 + 0x1c))();
    uStack_44 = 0;
    uStack_48 = 0x70791b;
    (**(code **)(*DAT_00b5a97c + 0x48))();
    uStack_48 = 0x707926;
    (**(code **)(*DAT_00b5ae5c + 0x2c))();
    uStack_48 = 0x707931;
    (**(code **)(*DAT_00b5ae5c + 0x3c))();
    uStack_48 = 0x70793c;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    iVar1 = **(int **)(iVar1 + 0x50);
    uStack_48 = 0x70794c;
    uStack_48 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_4c = 0x707952;
    piVar2 = (int *)(**(code **)(iVar1 + 0x14))();
    uStack_4c = *(undefined4 *)(param_1 + 0x1c);
    uStack_50 = CONCAT31((int3)((uint)uStack_4c >> 8),*(undefined1 *)(param_1 + 0x1a));
    uStack_54 = 0x707964;
    (**(code **)(*piVar2 + 0xe8))();
    iStack_40 = param_1 + 0x14;
    uStack_44 = 0x707975;
    FUN_0053acd0();
  }
  if ((*(int *)(param_1 + 0x10) == 1) || (*(int *)(param_1 + 0x10) == 2)) {
    iStack_40 = 0;
    uStack_44 = 0x70799b;
    uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_44 = 0xffffffff;
    uStack_48 = 0;
    uStack_50 = 0x7079b9;
    FUN_00401660();
    puStack_4 = auStack_5c;
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_c = (void *)0x0;
    uStack_58 = 0;
    FUN_00401660(auStack_26 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_10) {
      iStack_40 = 0x7079fa;
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00707a20 @ 0x00707a20 ====

void FUN_00707a20(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
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
  puStack_8 = &LAB_0098edcc;
  local_c = ExceptionList;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    ExceptionList = &local_c;
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    puVar3 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009b62d4;
      puVar3 = puVar1;
    }
    uVar2 = (**(code **)(*DAT_00b5adc0 + 0x18))();
    puVar3[1] = uVar2;
    uStack_34 = 0x707a7d;
    FUN_00797a20();
    ExceptionList = local_c;
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_00707a49_default;
  }
  uStack_34 = 0;
  uStack_38 = 0x707ab4;
  ExceptionList = &local_c;
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_38 = 0xffffffff;
  uStack_3c = 0;
  uStack_44 = 0x707ad1;
  FUN_00401660();
  puStack_4 = auStack_50;
  uStack_38 = 0xf;
  uStack_3c = 0;
  local_c = (void *)0x0;
  uStack_4c = 0;
  FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_10) {
    uStack_34 = 0x707b16;
    _free(pvStack_24);
    return;
  }
switchD_00707a49_default:
  ExceptionList = local_c;
  return;
}


// ==== FUN_00707b40 @ 0x00707b40 ====

void FUN_00707b40(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_5c [4];
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  void *pvStack_28;
  void *pvStack_20;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098edde;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ae5c + 0x10))();
  if (*(int *)(param_1 + 0x10) == 0) {
    (**(code **)(*DAT_00b5ae58 + 4))();
    uStack_40 = 0x707b8f;
    (**(code **)(*DAT_00b5a97c + 0x48))();
    uStack_40 = 0x707b9a;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    iVar1 = **(int **)(iVar1 + 0x50);
    uStack_40 = 0x707baa;
    uStack_40 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_44 = 0x707bb0;
    piVar2 = (int *)(**(code **)(iVar1 + 0x14))();
    uStack_44 = *(undefined4 *)(param_1 + 0x20);
    iVar1 = *piVar2;
    uStack_48 = 0x707bc0;
    uStack_48 = FUN_00802534();
    uStack_4c = 0x707bc9;
    (**(code **)(iVar1 + 0xe8))();
    uStack_4c = 1;
    uStack_50 = param_1 + 0x18;
    uStack_54 = 0x707bda;
    FUN_0053acd0();
    uStack_4c = 1;
    uStack_50 = CONCAT13((char)((uint)DAT_00b5a980 >> 0x18),*(undefined3 *)(param_1 + 0x14));
    uStack_54 = 0x707bf9;
    uStack_54 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_58 = 0x707bff;
    FUN_00827440();
    ExceptionList = pvStack_20;
    return;
  }
  (**(code **)(*DAT_00b5ae58 + 0x1c))();
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xffffff96:
    break;
  case 0xffffff97:
    break;
  case 0xffffff98:
    break;
  case 0xffffff99:
    break;
  case 0xffffff9a:
    break;
  case 0xffffff9b:
    break;
  case 0xffffff9c:
    break;
  default:
    goto switchD_00707c29_default;
  }
  uStack_40 = 0;
  uStack_44 = 0x707c6c;
  uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_44 = 0xffffffff;
  uStack_48 = 0;
  uStack_50 = 0x707c8a;
  FUN_00401660();
  puStack_8 = auStack_5c;
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_10 = (void *)0x0;
  uStack_58 = uStack_58 & 0xffffff00;
  FUN_00401660(auStack_5c + 0x28,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_14) {
    uStack_40 = 0x707ccb;
    _free(pvStack_28);
    return;
  }
switchD_00707c29_default:
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00707d00 @ 0x00707d00 ====

void FUN_00707d00(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined1 auStack_26 [2];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098edf0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1 + 0x10) == 0) {
    iStack_40 = 0x707d37;
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5ae58 + 4))();
    iStack_40 = 0;
    uStack_44 = 0x707d43;
    (**(code **)(*DAT_00b5ae58 + 0x1c))();
    uStack_44 = 0;
    uStack_48 = 0x707d4f;
    (**(code **)(*DAT_00b5a97c + 0x48))();
    uStack_48 = 0x707d5a;
    (**(code **)(*DAT_00b5ae5c + 0x2c))();
    uStack_48 = 0x707d65;
    (**(code **)(*DAT_00b5ae5c + 0x3c))();
    uStack_48 = 0x707d70;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    iVar1 = **(int **)(iVar1 + 0x50);
    uStack_48 = 0x707d80;
    uStack_48 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_4c = 0x707d86;
    piVar2 = (int *)(**(code **)(iVar1 + 0x14))();
    uStack_4c = *(undefined4 *)(param_1 + 0x1c);
    iVar1 = *piVar2;
    uStack_50 = 0x707d96;
    uStack_50 = FUN_00802534();
    uStack_54 = 0x707d9f;
    (**(code **)(iVar1 + 0xe8))();
    iStack_40 = param_1 + 0x14;
    uStack_44 = 0x707db0;
    FUN_0053acd0();
  }
  if ((*(int *)(param_1 + 0x10) == -0x66) || (*(int *)(param_1 + 0x10) == -100)) {
    iStack_40 = 0;
    uStack_44 = 0x707dd6;
    uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_44 = 0xffffffff;
    uStack_48 = 0;
    uStack_50 = 0x707df4;
    FUN_00401660();
    puStack_4 = auStack_5c;
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_c = (void *)0x0;
    uStack_58 = 0;
    FUN_00401660(auStack_26 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_10) {
      iStack_40 = 0x707e35;
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00707e50 @ 0x00707e50 ====

void FUN_00707e50(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined1 local_24;
  uint uStack_1c;
  void *pvStack_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ee12;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ea980;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_true_false_009ea908,10);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_isobserver_009ea914,10);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(local_44,1,local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae60 = (undefined4 *)0x0;
    ExceptionList = pvStack_18;
    return;
  }
  DAT_00b5ae60 = in_ECX;
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_00707f50 @ 0x00707f50 ====

void FUN_00707f50(void)

{
  undefined4 *in_ECX;
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ee2c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ea980;
  local_4 = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_isobserver_009ea920,10);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  if (local_14 < 0x10) {
    DAT_00b5ae60 = 0;
    *in_ECX = &PTR_FUN_009ea974;
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_00707ff0 @ 0x00707ff0 ====

void FUN_00707ff0(int param_1)

{
  undefined1 local_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ee3e;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x10) != 1) {
    ExceptionList = &local_c;
    FUN_00401740(s_setposition__d__d_009ea92c,0x11);
    FUN_00404230(local_28);
    local_4 = 0;
    (**(code **)(*DAT_00b5a688 + 4))();
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00708090 @ 0x00708090 ====

undefined4 FUN_00708090(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x5310001) {
    if (uVar1 == 0x5310000) {
      FUN_007076a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar1 + 0xfad30000) {
    case 0:
      FUN_00707650(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_00707ff0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_007076f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_007078d0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 8:
      FUN_00707a20(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    if (uVar1 == 0x5310002) {
      FUN_00707b40(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x5310004) {
      FUN_00707d00(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00708190 @ 0x00708190 ====

undefined4 FUN_00708190(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined1 local_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ee50;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_isobserver_009ea940,10);
  if (iVar1 != 0) {
    ExceptionList = local_c;
    return 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    if ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1) {
      uVar2 = FUN_00459160(local_28,0);
      iVar1 = *DAT_00b5ae58;
      local_4 = 0;
      uVar2 = thunk_FUN_00796fe0(uVar2);
      (**(code **)(iVar1 + 4))(uVar2);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return extraout_EAX;
      }
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00708260 @ 0x00708260 ====

uint FUN_00708260(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x50011) {
    uVar1 = FUN_00708090(param_1);
    return uVar1;
  }
  if (uVar1 == 0x70004) {
    uVar1 = FUN_00708190(param_1);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_007082a0 @ 0x007082a0 ====

void FUN_007082a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00707f50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007082c0 @ 0x007082c0 ====

void FUN_007082c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eaa1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007082e0 @ 0x007082e0 ====

void FUN_007082e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eaa30;
  in_ECX[1] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b12c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b12c = in_ECX;
  return;
}


// ==== FUN_00708310 @ 0x00708310 ====

void FUN_00708310(int param_1)

{
  undefined2 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 0x10);
  uVar1 = *(undefined2 *)(param_1 + 0x14);
  *(undefined2 *)(in_ECX + 8) = uVar1;
  (**(code **)(*DAT_00b5b128 + 8))(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0070833e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acd4 + 4))();
  return;
}


// ==== FUN_007083b0 @ 0x007083b0 ====

void FUN_007083b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b12c = 0;
  *in_ECX = &PTR_FUN_009eaa1c;
  return;
}


// ==== FUN_007083d0 @ 0x007083d0 ====

void FUN_007083d0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x52c0003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00708410 @ 0x00708410 ====

void FUN_00708410(void)

{
  short sVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  int in_ECX;
  undefined1 uStack00000000;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5aa24 + 8))(*(undefined2 *)(in_ECX + 8));
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 4))();
    if ((_uStack00000000 < *(ushort *)(iVar4 + 0x2a)) &&
       (sVar1 = *(short *)((_uStack00000000 + 2) * 0x30 + iVar4), sVar1 != 0)) {
      uVar5 = (**(code **)(*DAT_00b5a980 + 8))();
      FUN_00827520(uVar5,sVar1,&uStack00000000);
      uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar6 = operator_new(0x400);
      *(undefined4 *)((int)pvVar6 + 8) = uVar5;
      *(undefined4 *)((int)pvVar6 + 0xc) = 0x52c0005;
      *(undefined2 *)((int)pvVar6 + 6) = 0x1c;
      iVar4 = FUN_004244d0();
      *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 4);
      *(undefined2 *)(iVar4 + 0x14) = *(undefined2 *)(in_ECX + 8);
      *(ushort *)(iVar4 + 0x16) = _uStack00000000;
      *(undefined2 *)(iVar4 + 0x18) = 0;
      *(undefined1 *)(iVar4 + 0x1a) = 0;
      FUN_004d8570(iVar4);
      return;
    }
  }
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar6 = operator_new(0x400);
  *(undefined4 *)((int)pvVar6 + 8) = uVar5;
  *(undefined4 *)((int)pvVar6 + 0xc) = 0x52c0001;
  *(undefined2 *)((int)pvVar6 + 6) = 0x18;
  iVar4 = FUN_004244d0();
  *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 4);
  uVar2 = *(undefined2 *)(in_ECX + 8);
  *(ushort *)(iVar4 + 0x16) = _uStack00000000;
  *(undefined2 *)(iVar4 + 0x14) = uVar2;
  FUN_004d8570();
  return;
}


// ==== FUN_00708540 @ 0x00708540 ====

void FUN_00708540(undefined2 param_1,undefined2 param_2)

{
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098ee68;
  pvStack_c = ExceptionList;
  uStack_30 = CONCAT22(param_1,param_2);
  pvStack_34 = (void *)0x0;
  uStack_38 = 0x708577;
  ExceptionList = &pvStack_c;
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_38 = 0xffffffff;
  uStack_3c = 0;
  uStack_44 = 0x708594;
  FUN_00401660();
  puStack_4 = auStack_50;
  uStack_38 = 0xf;
  uStack_3c = 0;
  pvStack_c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401660(&uStack_30,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_007085f0 @ 0x007085f0 ====

/* WARNING: Removing unreachable block (ram,0x007087a5) */
/* WARNING: Removing unreachable block (ram,0x007086ce) */

void FUN_007085f0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_7c [4];
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  void *pvStack_5c;
  uint uStack_4c;
  uint uStack_48;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098eea0;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x38) == '\0') {
    ExceptionList = &local_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\0') {
      FUN_00401740();
      uStack_10 = 0;
      FUN_00796d50();
      uStack_10 = 0xffffffff;
    }
    (**(code **)(*DAT_00b5a980 + 8))();
    uStack_78 = 0;
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_10 = 2;
    FUN_00401740();
    piVar2 = (int *)(**(code **)(*piVar2 + 0x48))();
    iVar3 = (**(code **)(*piVar2 + 4))();
    pcVar4 = (char *)(iVar3 + 0x36);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    uStack_10._0_1_ = 3;
    FUN_00401660();
    uStack_10 = CONCAT31(uStack_10._1_3_,2);
    FUN_004e6c20();
    FUN_00827550();
    (**(code **)(*DAT_00b5a790 + 4))();
    (**(code **)(*DAT_00b5ad1c + 8))();
    (**(code **)(*DAT_00b5ad58 + 0xc))();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_20 = CONCAT31(uStack_20._1_3_,4);
    FUN_00401660(auStack_7c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  else {
    switch(*(char *)(param_1 + 0x38)) {
    case '\x01':
    case '\x03':
    case '\x04':
    case '\x05':
    case '\a':
    case '\b':
    case '\t':
    case '\n':
      ExceptionList = &local_c;
      FUN_00708540();
      break;
    case '\x02':
      ExceptionList = &local_c;
      FUN_00708540();
      break;
    case '\x06':
      ExceptionList = &local_c;
      FUN_00708540();
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_007088d0 @ 0x007088d0 ====

/* WARNING: Removing unreachable block (ram,0x00708a91) */
/* WARNING: Removing unreachable block (ram,0x007089bf) */

void FUN_007088d0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_7c [4];
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  void *pvStack_5c;
  uint uStack_4c;
  uint uStack_48;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098eed8;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x3b) == '\0') {
    ExceptionList = &local_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\0') {
      FUN_00401740();
      uStack_10 = 0;
      FUN_00796d50();
      uStack_10 = 0xffffffff;
    }
    (**(code **)(*DAT_00b5a980 + 8))();
    uStack_78 = 0;
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_10 = 2;
    FUN_00401740();
    piVar2 = (int *)(**(code **)(*piVar2 + 0x48))();
    iVar3 = (**(code **)(*piVar2 + 4))();
    pcVar4 = (char *)(iVar3 + 0x36);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    uStack_10._0_1_ = 3;
    FUN_00401660();
    uStack_10 = CONCAT31(uStack_10._1_3_,2);
    FUN_004e6c20();
    FUN_008275f0();
    FUN_008275b0();
    (**(code **)(*DAT_00b5a790 + 4))();
    (**(code **)(*DAT_00b5ad1c + 8))();
    (**(code **)(*DAT_00b5ad58 + 0xc))();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_20 = CONCAT31(uStack_20._1_3_,4);
    FUN_00401660(auStack_7c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  else {
    switch(*(char *)(param_1 + 0x3b)) {
    case '\x01':
    case '\x03':
    case '\x04':
    case '\x05':
    case '\b':
    case '\t':
    case '\n':
    case '\v':
    case '\f':
    case '\r':
      ExceptionList = &local_c;
      FUN_00708540();
      break;
    case '\x02':
      ExceptionList = &local_c;
      FUN_00708540();
      break;
    case '\x06':
      ExceptionList = &local_c;
      FUN_00708540();
      break;
    case '\a':
      ExceptionList = &local_c;
      FUN_00708540();
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00708bd0 @ 0x00708bd0 ====

undefined4 FUN_00708bd0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x52c0000) {
  case 0:
    FUN_00708310(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 2:
    FUN_007085f0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 4:
    (**(code **)(*DAT_00b5b128 + 0xc))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  case 6:
    FUN_007088d0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
}


// ==== FUN_00708c70 @ 0x00708c70 ====

undefined4 FUN_00708c70(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00708bd0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00708ca0 @ 0x00708ca0 ====

void FUN_00708ca0(byte param_1)

{
  void *in_ECX;
  
  FUN_007083b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00708cc0 @ 0x00708cc0 ====

void FUN_00708cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eaac0;
  return;
}


// ==== FUN_00708cd0 @ 0x00708cd0 ====

void FUN_00708cd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eaac0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00708d00 @ 0x00708d00 ====

void FUN_00708d00(undefined2 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    puVar1 = operator_new(8);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eaae0;
      *(undefined2 *)(puVar1 + 1) = param_1;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00708d50 @ 0x00708d50 ====

void FUN_00708d50(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eaaf4;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00708d90 @ 0x00708d90 ====

void FUN_00708d90(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 5) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eab08;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 5) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 5) = 0;
  }
  return;
}


// ==== FUN_00708dd0 @ 0x00708dd0 ====

void FUN_00708dd0(void)

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
  
  puStack_8 = &LAB_0098ef68;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009eab30;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b128 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b128 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009eaa42,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_exchangeshop_009eaa44,0x11);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,1,&local_28);
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
  FUN_00401740(&DAT_009eaa56,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_exchangeshop_009eaa58,0x11);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (local_28 < 0x10) {
    ExceptionList = local_24;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_00708f60 @ 0x00708f60 ====

void FUN_00708f60(void)

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
  
  puStack_8 = &LAB_0098ef8a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009eab30;
  DAT_00b5b128 = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_exchangeshop_009eaa6c,0x11);
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
  FUN_00401740(s_hide_exchangeshop_009eaa80,0x11);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009eaac0;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00709050 @ 0x00709050 ====

void FUN_00709050(undefined1 param_1,void *param_2)

{
  void *pvVar1;
  int in_ECX;
  uint in_stack_0000001c;
  void *in_stack_00000024;
  uint in_stack_00000038;
  void *in_stack_00000040;
  uint in_stack_00000054;
  undefined1 *in_stack_00000058;
  undefined1 auStack_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098efc7;
  local_c = ExceptionList;
  local_4 = 2;
  ExceptionList = &local_c;
  if (*(char *)(in_ECX + 5) != '\x01') {
    local_2c = 0x709086;
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x5c);
    local_4._0_1_ = 3;
    if (pvVar1 != (void *)0x0) {
      in_stack_00000058 = auStack_44;
      local_2c = 0xf;
      local_30 = 0;
      local_40 = 0;
      FUN_00401660();
      local_4._0_1_ = 4;
      FUN_00401660();
      local_4._0_1_ = 5;
      FUN_00401660(&param_1,0,0xffffffff);
      local_4._0_1_ = 3;
      FUN_007092e0();
    }
    local_4 = CONCAT31(local_4._1_3_,2);
    local_2c = 0x709140;
    FUN_00797a20();
    *(undefined1 *)(in_ECX + 5) = 1;
  }
  if (0xf < in_stack_0000001c) {
    local_2c = 0x70915c;
    _free(param_2);
    return;
  }
  if (0xf < in_stack_00000038) {
    local_2c = 0x70916f;
    _free(in_stack_00000024);
    return;
  }
  if (in_stack_00000054 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  local_2c = 0x709182;
  _free(in_stack_00000040);
  return;
}


// ==== FUN_007091a0 @ 0x007091a0 ====

undefined4 FUN_007091a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  void *local_28 [5];
  uint uStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098efd9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_exchangeshop_009eaa94,0x11);
  if (iVar1 != 0) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_exchangeshop_009eaaa8,0x11);
    if (iVar1 == 0) {
      (**(code **)(*in_ECX + 0xc))();
      ExceptionList = local_c;
      return 1;
    }
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_00459160(local_28,0);
  iVar1 = *in_ECX;
  local_4 = 0;
  uVar2 = thunk_FUN_00796f80(uVar2);
  (**(code **)(iVar1 + 8))(uVar2);
  if (uStack_14 < 0x10) {
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(local_28[0]);
  return extraout_EAX;
}


// ==== FUN_00709280 @ 0x00709280 ====

undefined4 FUN_00709280(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_007091a0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007092b0 @ 0x007092b0 ====

undefined4 FUN_007092b0(void)

{
  return 0x70480001;
}


// ==== FUN_007092c0 @ 0x007092c0 ====

undefined4 FUN_007092c0(void)

{
  return 0x70480002;
}


// ==== FUN_007092d0 @ 0x007092d0 ====

undefined4 FUN_007092d0(void)

{
  return 0x70480004;
}


// ==== FUN_007092e0 @ 0x007092e0 ====

void FUN_007092e0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined1 uStack0000003c;
  void *in_stack_00000040;
  uint in_stack_00000054;
  undefined2 in_stack_00000058;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ef31;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009eab1c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  local_4 = 6;
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_00401660(&uStack00000020,0,0xffffffff);
  FUN_00401660(&uStack0000003c,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0x16) = in_stack_00000058;
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


// ==== FUN_007093d0 @ 0x007093d0 ====

undefined4 FUN_007093d0(void)

{
  return 0x70480003;
}


// ==== FUN_007093e0 @ 0x007093e0 ====

void FUN_007093e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00709400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00709400 @ 0x00709400 ====

void FUN_00709400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eab1c;
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


// ==== FUN_00709480 @ 0x00709480 ====

void FUN_00709480(byte param_1)

{
  void *in_ECX;
  
  FUN_00708f60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007094a0 @ 0x007094a0 ====

void FUN_007094a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eabac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007094d0 @ 0x007094d0 ====

void FUN_007094d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eabb8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b134 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b134 = in_ECX;
  return;
}


// ==== FUN_00709500 @ 0x00709500 ====

void FUN_00709500(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b134 = 0;
  *in_ECX = &PTR_FUN_009eabac;
  return;
}


// ==== FUN_00709520 @ 0x00709520 ====

void FUN_00709520(int param_1)

{
  undefined2 local_108;
  undefined2 local_106;
  undefined1 local_104;
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009eaba4,s_RECEIVE______SA_FAILCOUNT_009eab50);
  FUN_00797b80(local_100);
  local_108 = *(undefined2 *)(param_1 + 0x10);
  local_106 = *(undefined2 *)(param_1 + 0x12);
  local_104 = *(undefined1 *)(param_1 + 0x14);
  (**(code **)(*DAT_00b5b138 + 8))(&local_108);
  return;
}


// ==== FUN_00709580 @ 0x00709580 ====

void FUN_00709580(int param_1)

{
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009eaba4,s_RECEIVE______SA_FAILCOUNT_009eab6c);
  FUN_00797b80(local_100);
  (**(code **)(*DAT_00b5b138 + 0x10))(*(undefined1 *)(param_1 + 0x10));
  return;
}


// ==== FUN_007095d0 @ 0x007095d0 ====

void FUN_007095d0(int param_1)

{
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009eaba4,s_RECEIVE______SA_FAILCOUNT_009eab88);
  FUN_00797b80(local_100);
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5b138 + 0x14))(1);
    return;
  case 1:
    (**(code **)(*DAT_00b5b138 + 0x14))(0);
    return;
  case 2:
    (**(code **)(*DAT_00b5b138 + 0x18))(1);
    return;
  case 3:
    (**(code **)(*DAT_00b5b138 + 0x18))(0);
  }
  return;
}


// ==== FUN_00709680 @ 0x00709680 ====

undefined4 FUN_00709680(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x52b0002) {
    FUN_00709580(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x52b0003) {
    FUN_00709520(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x52b0004) {
    FUN_007095d0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_007096e0 @ 0x007096e0 ====

undefined4 FUN_007096e0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00709680(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00709710 @ 0x00709710 ====

void FUN_00709710(byte param_1)

{
  void *in_ECX;
  
  FUN_00709500();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00709730 @ 0x00709730 ====

void FUN_00709730(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ead08;
  return;
}


// ==== FUN_00709740 @ 0x00709740 ====

void FUN_00709740(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ead08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00709790 @ 0x00709790 ====

void FUN_00709790(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined2 *)(in_ECX + 8) = *(undefined2 *)(param_1 + 1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ead30;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007097d0 @ 0x007097d0 ====

void FUN_007097d0(undefined1 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 10) = param_1;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ead58;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00709840 @ 0x00709840 ====

void FUN_00709840(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x52b0001;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined4 *)(iVar3 + 0x10) = param_1;
  FUN_004d8570();
  return;
}


// ==== FUN_00709890 @ 0x00709890 ====

void FUN_00709890(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_EBP;
  uint unaff_ESI;
  uint *_Memory;
  char *pcStack_68;
  undefined4 uStack_64;
  undefined4 *local_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined2 local_4a;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 local_46;
  undefined1 uStack_45;
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
  
  puStack_8 = &LAB_0098f038;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ead80;
  local_4 = 0;
  *(undefined2 *)puVar1 = 0;
  *(undefined2 *)((int)in_ECX + 6) = 0;
  *(undefined1 *)(in_ECX + 2) = 0x2b;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5b138 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b138 = in_ECX;
  }
  local_46 = 0x2b;
  local_4a = 0;
  uStack_48 = 0;
  uStack_47 = 0;
  *puVar1 = 0;
  uStack_64 = (uint *)0x18;
  pcStack_68 = s__PARAM1___MARK___PARAM2__009eabfc;
  *(ushort *)(in_ECX + 2) = CONCAT11(uStack_45,0x2b);
  *(undefined1 *)((int)in_ECX + 10) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_50 = in_ECX;
  FUN_00401740();
  uStack_64 = (uint *)0xd;
  pcStack_68 = s_question_show_009eac18;
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740();
  uStack_64 = &local_28;
  pcStack_68 = (char *)0x3;
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44);
  if (0xf < uStack_38) {
    _free((void *)CONCAT22(local_4a,CONCAT11(uStack_4b,uStack_4c)));
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  uStack_4c = 0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009eac26,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  uStack_4c = 0;
  FUN_00401740(s_question_hide_009eac28,0xd);
  _Memory = &uStack_34;
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_50,0);
  if (0xf < local_44) {
    _free(unaff_EBP);
    return;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  uStack_47 = 0;
  local_46 = 0;
  uStack_45 = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s__FAILCOUNT__009eac38,0xb);
  uStack_1c._0_1_ = 5;
  local_44 = 0xf;
  uStack_48 = 0;
  uStack_47 = 0;
  local_46 = 0;
  uStack_45 = 0;
  FUN_00401740(s_question_refresh_009eac44,0x10);
  uStack_1c = CONCAT31(uStack_1c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))((int)register0x00000010 + -0x5c,1,&local_40);
  if ((undefined4 *)0xf < local_50) {
    _free(uStack_64);
    return;
  }
  local_50 = (undefined4 *)0xf;
  uStack_64 = (uint *)((uint)uStack_64 & 0xffffff00);
  local_28 = local_28 & 0xffffff00;
  if (0xf < uStack_34) {
    _free((void *)CONCAT13(uStack_45,CONCAT12(local_46,CONCAT11(uStack_47,uStack_48))));
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  uStack_48 = 0;
  FUN_00401740(&DAT_009eac55,0);
  local_28._0_1_ = 7;
  local_50 = (undefined4 *)0xf;
  uStack_64 = (uint *)((uint)uStack_64 & 0xffffff00);
  FUN_00401740(s_question_result_009eac58,0xf);
  local_28 = CONCAT31(local_28._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(&pcStack_68,0,&uStack_4c);
  if (0xf < unaff_ESI) {
    _free(_Memory);
    return;
  }
  if (local_40 < 0x10) {
    ExceptionList = pvStack_3c;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00709b60 @ 0x00709b60 ====

void FUN_00709b60(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_20;
  void *pvStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098f06a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ead80;
  local_4 = 0;
  DAT_00b5b138 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_question_show_009eac68,0xd);
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
  FUN_00401740(s_question_hide_009eac78,0xd);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_question_refresh_009eac88,0x10);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10 = local_10 & 0xffffff00;
  if (0xf < pvStack_1c) {
    _free(unaff_EBX);
    return;
  }
  pvStack_1c = (void *)0xf;
  uStack_20 = 0;
  FUN_00401740(s_question_result_009eac9c,0xf);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  if (uStack_20 < 0x10) {
    *in_ECX = &PTR_FUN_009ead08;
    ExceptionList = pvStack_1c;
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_00709ce0 @ 0x00709ce0 ====

void FUN_00709ce0(char param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined1 uStack_31;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f07c;
  pvStack_c = ExceptionList;
  uStack_31 = (undefined1)((uint)unaff_EBX >> 0x18);
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x118006f - (uint)(param_1 != '\0'));
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401660(uVar1,0,0xffffffff);
  pvStack_c = (void *)0x0;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ead6c;
    puVar2[7] = 0xf;
    puVar2[6] = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
  }
  FUN_00401660(auStack_30,0,0xffffffff);
  FUN_00797a20(puVar2);
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ead44;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(ushort *)(in_ECX + 8) = CONCAT11(uStack_31,0x2b);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_00709df0 @ 0x00709df0 ====

void FUN_00709df0(char param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined1 uStack_31;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f08e;
  pvStack_c = ExceptionList;
  uStack_31 = (undefined1)((uint)unaff_EBX >> 0x18);
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1180071 - (uint)(param_1 != '\0'));
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401660(uVar1,0,0xffffffff);
  pvStack_c = (void *)0x0;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ead6c;
    puVar2[7] = 0xf;
    puVar2[6] = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
  }
  FUN_00401660(auStack_30,0,0xffffffff);
  FUN_00797a20(puVar2);
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ead44;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(ushort *)(in_ECX + 8) = CONCAT11(uStack_31,0x2b);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_00709f00 @ 0x00709f00 ====

undefined4 FUN_00709f00(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  undefined1 *puVar7;
  undefined2 uStack_68;
  undefined2 uStack_66;
  undefined1 uStack_64;
  undefined1 local_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  uint uStack_2c;
  undefined1 local_28 [24];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098f0b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_question_show_009eacac,0xd);
  if (iVar4 == 0) {
    if ((*(int *)(param_1 + 0x28) != 0) &&
       ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 3)) {
      iVar4 = FUN_00459160(local_60,1);
      local_4 = 0;
      if (*(int *)(iVar4 + 0x14) == 0) {
        FUN_0079dba3();
      }
      if (*(uint *)(iVar4 + 0x18) < 0x10) {
        puVar7 = (undefined1 *)(iVar4 + 4);
      }
      else {
        puVar7 = *(undefined1 **)(iVar4 + 4);
      }
      uVar1 = *puVar7;
      local_4 = 0xffffffff;
      if (0xf < uStack_48) {
        _free(pvStack_5c);
        return extraout_EAX;
      }
      uVar5 = FUN_00459160(auStack_44,2);
      local_4 = 1;
      uVar6 = FUN_00459160(local_60,0);
      local_4 = CONCAT31(local_4._1_3_,2);
      uVar3 = thunk_FUN_00796f80(uVar5);
      uStack_68 = thunk_FUN_00796f80(uVar6);
      uStack_66 = uVar3;
      uStack_64 = uVar1;
      if (0xf < uStack_48) {
        _free(pvStack_5c);
        return extraout_EAX_00;
      }
      uStack_48 = 0xf;
      uStack_4c = 0;
      pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
      local_4 = 0xffffffff;
      if (uStack_2c < 0x10) {
        (**(code **)(*in_ECX + 8))(&uStack_68);
        ExceptionList = pvStack_10;
        return 1;
      }
      _free(pvStack_40);
      return extraout_EAX_01;
    }
  }
  else {
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_question_hide_009eacbc,0xd);
    if (iVar4 != 0) {
      iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_question_refresh_009eaccc,0x10);
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x28) == 0) {
          ExceptionList = local_c;
          return 1;
        }
        if ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1) {
          uVar5 = FUN_00459160(local_28,0);
          iVar4 = *in_ECX;
          local_4 = 3;
          uVar5 = thunk_FUN_00796f50(uVar5);
          (**(code **)(iVar4 + 0x10))(uVar5);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        ExceptionList = local_c;
        return 1;
      }
      cVar2 = FUN_004036a0(param_1 + 8,s_question_result_009eace0);
      if (cVar2 == '\0') {
        ExceptionList = local_c;
        return 0;
      }
    }
    (**(code **)(*in_ECX + 0x14))(1);
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_0070a170 @ 0x0070a170 ====

undefined4 FUN_0070a170(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00709f00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0070a1a0 @ 0x0070a1a0 ====

undefined4 FUN_0070a1a0(void)

{
  return 0x70920000;
}


// ==== FUN_0070a1b0 @ 0x0070a1b0 ====

undefined4 FUN_0070a1b0(void)

{
  return 0x70920001;
}


// ==== FUN_0070a1c0 @ 0x0070a1c0 ====

undefined4 FUN_0070a1c0(void)

{
  return 0x70920002;
}


// ==== FUN_0070a1d0 @ 0x0070a1d0 ====

undefined4 FUN_0070a1d0(void)

{
  return 0x70920003;
}


// ==== FUN_0070a1e0 @ 0x0070a1e0 ====

void FUN_0070a1e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0070a200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070a200 @ 0x0070a200 ====

void FUN_0070a200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ead6c;
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


// ==== FUN_0070a240 @ 0x0070a240 ====

void FUN_0070a240(byte param_1)

{
  void *in_ECX;
  
  FUN_00709b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070a260 @ 0x0070a260 ====

void FUN_0070a260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eada8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070a280 @ 0x0070a280 ====

void FUN_0070a280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eadd8;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad88 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad88 = in_ECX;
  return;
}


// ==== FUN_0070a2b0 @ 0x0070a2b0 ====

void FUN_0070a2b0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0070a2c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar1 + 0x98) + 0x3c))();
  return;
}


// ==== FUN_0070a2d0 @ 0x0070a2d0 ====

void FUN_0070a2d0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = *(int **)(iVar1 + 0x98);
  (**(code **)(*piVar2 + 0x18))(param_1);
  piVar2 = (int *)(**(code **)(*piVar2 + 0x1c))();
  piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
  iVar1 = (**(code **)(*piVar3 + 4))();
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(iVar1 + 4);
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  iVar1 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(iVar1 + 8);
  return;
}


// ==== FUN_0070a330 @ 0x0070a330 ====

void FUN_0070a330(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0070a343. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar1 + 0x98) + 0xc))();
  return;
}


// ==== FUN_0070a350 @ 0x0070a350 ====

undefined2 FUN_0070a350(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_00b5a980;
  uVar3 = (**(code **)(*DAT_00b5ac1c + 0x3c))();
  uVar3 = (**(code **)(*piVar1 + 8))(uVar3);
  uVar2 = FUN_00827620(uVar3);
  return uVar2;
}


// ==== FUN_0070a380 @ 0x0070a380 ====

undefined4 FUN_0070a380(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  if (*(char *)(iVar2 + 0xee4) == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar1 = *(int **)(iVar2 + 0x24);
  uVar4 = 6;
  do {
    piVar3 = (int *)(**(code **)(*piVar1 + 0x2c))(uVar4);
    if (piVar3 != (int *)0x0) {
      piVar3 = (int *)(**(code **)(*piVar3 + 0x48))();
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (*(int *)(iVar2 + 0xc) == 0x604) {
        return 1;
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x15);
  return 0;
}


// ==== FUN_0070a400 @ 0x0070a400 ====

undefined1 FUN_0070a400(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  return *(undefined1 *)(iVar2 + 0xee4);
}


// ==== FUN_0070a420 @ 0x0070a420 ====

void FUN_0070a420(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00827780(uVar1);
  return;
}


// ==== FUN_0070a440 @ 0x0070a440 ====

void FUN_0070a440(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad88 = 0;
  *in_ECX = &PTR_FUN_009eada8;
  return;
}


// ==== FUN_0070a460 @ 0x0070a460 ====

undefined4 FUN_0070a460(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00b5a980 == (int *)0x0) {
    return 4;
  }
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0070a47d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x98) + 0x40))();
  return uVar2;
}


// ==== FUN_0070a480 @ 0x0070a480 ====

void FUN_0070a480(byte param_1)

{
  void *in_ECX;
  
  FUN_0070a440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070a4a0 @ 0x0070a4a0 ====

void FUN_0070a4a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eae1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070a4c0 @ 0x0070a4c0 ====

void FUN_0070a4c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eae38;
  *(undefined1 *)(in_ECX + 1) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad8c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad8c = in_ECX;
  return;
}


// ==== FUN_0070a4f0 @ 0x0070a4f0 ====

void FUN_0070a4f0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    iVar1 = *DAT_00b5ad84;
    uVar2 = (**(code **)(*DAT_00b5ad88 + 0x1c))();
    (**(code **)(iVar1 + 8))(1,uVar2);
    (**(code **)(*DAT_00b5ad88 + 8))(1);
    *(undefined1 *)(in_ECX + 4) = 1;
    return;
  case 1:
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0xd);
                    /* WARNING: Could not recover jumptable at 0x0070a562. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5ad88 + 8))(2);
    return;
  case 2:
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0xb);
    break;
  case 3:
    uVar2 = 0xc;
    goto LAB_0070a593;
  case 4:
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0x16);
    break;
  case 5:
    uVar2 = 0xe;
LAB_0070a593:
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,uVar2);
  }
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  (**(code **)(*DAT_00b5ad88 + 0x18))();
  return;
}


// ==== FUN_0070a5e0 @ 0x0070a5e0 ====

void FUN_0070a5e0(int param_1)

{
  int *in_ECX;
  undefined4 uVar1;
  
  (**(code **)(*DAT_00b5ad84 + 0xc))();
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5ad88 + 8))(2);
                    /* WARNING: Could not recover jumptable at 0x0070a620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5acd4 + 4))();
    return;
  case 1:
    if ((char)in_ECX[1] != '\0') {
      *(undefined1 *)(in_ECX + 1) = 0;
      (**(code **)(*in_ECX + 0xc))();
      return;
    }
    uVar1 = 0xe;
    break;
  default:
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0xe);
    goto LAB_0070a662;
  case 3:
    uVar1 = 0x16;
  }
  (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,uVar1);
LAB_0070a662:
  (**(code **)(*DAT_00b5ad88 + 8))(0);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  (**(code **)(*DAT_00b5ad88 + 0x18))();
  return;
}


// ==== FUN_0070a6a0 @ 0x0070a6a0 ====

void FUN_0070a6a0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\0') {
    iVar2 = *DAT_00b5ad84;
    uVar3 = (**(code **)(*DAT_00b5ad88 + 0x20))();
    (**(code **)(iVar2 + 8))(2,uVar3);
    (**(code **)(*DAT_00b5acd4 + 4))(0xe);
    (**(code **)(*DAT_00b5ad88 + 8))(3);
    *(undefined1 *)(in_ECX + 4) = 1;
    return;
  }
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0xb);
    return;
  }
  if (cVar1 == '\x02') {
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0x16);
    return;
  }
  (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0xf);
  return;
}


// ==== FUN_0070a740 @ 0x0070a740 ====

void FUN_0070a740(int param_1)

{
  int *in_ECX;
  undefined4 uVar1;
  
  (**(code **)(*DAT_00b5ad84 + 0xc))();
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    (**(code **)(*DAT_00b5ad88 + 8))(0);
    (**(code **)(*DAT_00b5ad88 + 0x18))();
    return;
  case 1:
    if ((char)in_ECX[1] != '\0') {
      *(undefined1 *)(in_ECX + 1) = 0;
      (**(code **)(*in_ECX + 0x14))();
      return;
    }
    uVar1 = 0x10;
    break;
  default:
    (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,0xf);
    goto LAB_0070a7ca;
  case 3:
    uVar1 = 0x16;
  }
  (**(code **)(*DAT_00b5ad84 + 0x10))(0x7d5,uVar1);
LAB_0070a7ca:
  (**(code **)(*DAT_00b5acd4 + 4))(0);
                    /* WARNING: Could not recover jumptable at 0x0070a7e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad88 + 8))(2);
  return;
}


// ==== FUN_0070a800 @ 0x0070a800 ====

void FUN_0070a800(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x10));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
    if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0070a82f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar1 + 0x2c))();
      return;
    }
  }
  return;
}


// ==== FUN_0070a840 @ 0x0070a840 ====

void FUN_0070a840(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad8c = 0;
  *in_ECX = &PTR_FUN_009eae1c;
  return;
}


// ==== FUN_0070a860 @ 0x0070a860 ====

undefined4 FUN_0070a860(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x52a0001) {
  case 0:
    FUN_0070a4f0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 2:
    FUN_0070a5e0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 4:
    FUN_0070a6a0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 6:
    FUN_0070a740(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 7:
    FUN_0070a800(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
}


// ==== FUN_0070a910 @ 0x0070a910 ====

void FUN_0070a910(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  iVar1 = (**(code **)(*DAT_00b5acd4 + 8))();
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5acd4 + 4))(0xe);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x52a0000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_0070a970 @ 0x0070a970 ====

void FUN_0070a970(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x52a0002;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_0070a9b0 @ 0x0070a9b0 ====

void FUN_0070a9b0(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  iVar1 = (**(code **)(*DAT_00b5acd4 + 8))();
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x52a0004;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_0070aa00 @ 0x0070aa00 ====

void FUN_0070aa00(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x52a0006;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_0070aa40 @ 0x0070aa40 ====

undefined4 FUN_0070aa40(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0070a860(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0070aa70 @ 0x0070aa70 ====

void FUN_0070aa70(byte param_1)

{
  void *in_ECX;
  
  FUN_0070a840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070aa90 @ 0x0070aa90 ====

void FUN_0070aa90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eae94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070aad0 @ 0x0070aad0 ====

void FUN_0070aad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eaef0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad84 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad84 = in_ECX;
  return;
}


// ==== FUN_0070ab00 @ 0x0070ab00 ====

uint FUN_0070ab00(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0070ab10 @ 0x0070ab10 ====

void FUN_0070ab10(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined2 extraout_var;
  
  if ((char)in_ECX[1] != '\x01') {
    uVar2 = (**(code **)(*DAT_00b5ad88 + 4))();
    switch(uVar2) {
    case 0:
      iVar3 = (**(code **)(*DAT_00b5ad88 + 0xc))();
      in_ECX[2] = iVar3;
      if (iVar3 != 0) {
        (**(code **)(*DAT_00b5ad88 + 0x14))(CONCAT22(extraout_var,(short)in_ECX[2]));
                    /* WARNING: Could not recover jumptable at 0x0070ab63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*DAT_00b5ad8c + 8))();
        return;
      }
      cVar1 = (**(code **)(*DAT_00b5ad88 + 0x24))();
      if (cVar1 == '\0') {
        (**(code **)(*in_ECX + 0x10))(0x7d5,0xc);
        return;
      }
      (**(code **)(*in_ECX + 0x10))(0x7d5,1);
      return;
    case 1:
      (**(code **)(*in_ECX + 0x10))(0x7d5,7);
      return;
    case 2:
      cVar1 = (**(code **)(*DAT_00b5ad88 + 0x10))();
      if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0070abb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*DAT_00b5ad8c + 0x10))();
        return;
      }
      break;
    case 3:
      (**(code **)(*in_ECX + 0x10))(0x7d5,8);
      return;
    case 4:
      (**(code **)(*in_ECX + 0x10))(0x7d5,0xd);
    }
  }
  return;
}


// ==== FUN_0070abf0 @ 0x0070abf0 ====

void FUN_0070abf0(undefined1 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aee4 + 0x18))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5aee4 + 0x20))(1);
  }
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009eaeb4;
  }
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_1;
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_0070ac50 @ 0x0070ac50 ====

void FUN_0070ac50(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009eaec8;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0070ac90 @ 0x0070ac90 ====

void FUN_0070ac90(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009eaedc;
  }
  cVar1 = (**(code **)(*DAT_00b5ad88 + 0x28))();
  *(bool *)(puVar2 + 1) = cVar1 == '\x01';
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_0070acd0 @ 0x0070acd0 ====

void FUN_0070acd0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad84 = 0;
  *in_ECX = &PTR_FUN_009eae94;
  return;
}


// ==== FUN_0070acf0 @ 0x0070acf0 ====

void FUN_0070acf0(undefined2 param_1,undefined2 param_2)

{
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098f0d8;
  pvStack_c = ExceptionList;
  uStack_30 = CONCAT22(param_1,param_2);
  pvStack_34 = (void *)0x0;
  uStack_38 = 0x70ad27;
  ExceptionList = &pvStack_c;
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_38 = 0xffffffff;
  uStack_3c = 0;
  uStack_44 = 0x70ad44;
  FUN_00401660();
  puStack_4 = auStack_50;
  uStack_38 = 0xf;
  uStack_3c = 0;
  pvStack_c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401660(&uStack_30,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0070ada0 @ 0x0070ada0 ====

undefined4 FUN_0070ada0(void)

{
  return 0x70470000;
}


// ==== FUN_0070adb0 @ 0x0070adb0 ====

undefined4 FUN_0070adb0(void)

{
  return 0x70470001;
}


// ==== FUN_0070adc0 @ 0x0070adc0 ====

undefined4 FUN_0070adc0(void)

{
  return 0x7005000c;
}


// ==== FUN_0070add0 @ 0x0070add0 ====

void FUN_0070add0(byte param_1)

{
  void *in_ECX;
  
  FUN_0070acd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070adf0 @ 0x0070adf0 ====

void FUN_0070adf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb07c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070ae10 @ 0x0070ae10 ====

void FUN_0070ae10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb088;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae68 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae68 = in_ECX;
  return;
}


// ==== FUN_0070ae40 @ 0x0070ae40 ====

void FUN_0070ae40(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uStack_10;
  
  uStack_10 = 0x70ae4e;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  uStack_10 = 0x70ae55;
  piVar2 = (int *)(**(code **)(*piVar2 + 0x24))();
  uStack_10 = param_1 + 0xb4;
  (**(code **)(*piVar2 + 4))();
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x20))();
  (**(code **)(*piVar2 + 4))(param_1 + 0x14);
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x28))();
  uVar5 = (uint)*(byte *)(param_1 + 0xd4);
  if (*(byte *)(param_1 + 0xd4) != 0) {
    puVar6 = (undefined4 *)(param_1 + 0xd6);
    do {
      piVar3 = (int *)(**(code **)(*piVar2 + 0x10))(*puVar6);
      if (piVar3 == (int *)0x0) {
        uVar4 = (**(code **)(*DAT_00b5b018 + 4))(&uStack_10);
        (**(code **)(*piVar2 + 0xc))(uVar4);
      }
      else {
        (**(code **)(*piVar3 + 8))(uStack_10 >> 0x10 & 0xff);
      }
      puVar6 = puVar6 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  cVar1 = (**(code **)(*piVar2 + 0x20))();
  if (cVar1 != '\0') {
    uStack_10 = 0x70af1c;
    (**(code **)(*DAT_00b5ae64 + 0x10))();
    uStack_10 = 0x70af27;
    (**(code **)(*DAT_00b5ae64 + 0x18))();
    uStack_10 = 0x70af32;
    (**(code **)(*DAT_00b5ae64 + 8))();
  }
  return;
}


// ==== FUN_0070af40 @ 0x0070af40 ====

void FUN_0070af40(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
  (**(code **)(*piVar1 + 0x14))(*(undefined1 *)(param_1 + 0x12),*(undefined2 *)(param_1 + 0x14));
  return;
}


// ==== FUN_0070af70 @ 0x0070af70 ====

void FUN_0070af70(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x28))();
  piVar2 = (int *)(**(code **)(*piVar1 + 0x10))
                            (CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x12)));
  if (piVar2 == (int *)0x0) {
    uVar3 = (**(code **)(*DAT_00b5b018 + 4))(param_1 + 0x12);
    (**(code **)(*piVar1 + 0xc))(uVar3);
    (**(code **)(*DAT_00b5ae64 + 0x3c))();
    return;
  }
  (**(code **)(*piVar2 + 8))(*(undefined1 *)(param_1 + 0x14));
  (**(code **)(*DAT_00b5ae64 + 0x3c))();
  return;
}


// ==== FUN_0070afe0 @ 0x0070afe0 ====

void FUN_0070afe0(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x28))();
                    /* WARNING: Could not recover jumptable at 0x0070b002. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x14))();
  return;
}


// ==== FUN_0070b010 @ 0x0070b010 ====

void FUN_0070b010(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x20))();
  (**(code **)(*piVar1 + 0x14))(*(undefined1 *)(param_1 + 0x28),param_1 + 0x14);
  return;
}


// ==== FUN_0070b040 @ 0x0070b040 ====

void FUN_0070b040(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x20))();
                    /* WARNING: Could not recover jumptable at 0x0070b061. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x18))();
  return;
}


// ==== FUN_0070b070 @ 0x0070b070 ====

void FUN_0070b070(int param_1)

{
  (**(code **)(*DAT_00b5ae64 + 0x34))
            (*(undefined2 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
             *(undefined2 *)(param_1 + 0x12));
  return;
}


// ==== FUN_0070b0b0 @ 0x0070b0b0 ====

void FUN_0070b0b0(void)

{
  (**(code **)(*DAT_00b5ae64 + 0x14))();
  (**(code **)(*DAT_00b5ae64 + 0x1c))();
  (**(code **)(*DAT_00b5ae64 + 0xc))();
  return;
}


// ==== FUN_0070b0e0 @ 0x0070b0e0 ====

void FUN_0070b0e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  switch(*(undefined1 *)(param_1 + 0x12)) {
  case 0:
    piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(*(undefined2 *)(param_1 + 0x10));
    iVar1 = *DAT_00b5ad1c;
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    (**(code **)(iVar1 + 0x98))(*(undefined4 *)(iVar3 + 0xec8));
    iVar1 = *DAT_00b5a784;
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    (**(code **)(iVar1 + 0x18))(*(undefined4 *)(iVar3 + 0xecc));
  case 1:
                    /* WARNING: Could not recover jumptable at 0x0070b15e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5acd4 + 4))();
    return;
  case 2:
    break;
  case 3:
    break;
  case 4:
  case 5:
  case 6:
  case 0x18:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    break;
  case 0x17:
  }
                    /* WARNING: Could not recover jumptable at 0x0070b1f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ae64 + 0x2c))();
  return;
}


// ==== FUN_0070b280 @ 0x0070b280 ====

void FUN_0070b280(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae68 = 0;
  *in_ECX = &PTR_FUN_009eb07c;
  return;
}


// ==== FUN_0070b2a0 @ 0x0070b2a0 ====

void FUN_0070b2a0(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined4 in_EDX;
  void *unaff_EDI;
  void *pvStack_4c;
  undefined1 auStack_26 [26];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f0f8;
  pvStack_c = ExceptionList;
  uVar2 = *(undefined2 *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 8))();
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  pcVar5 = (char *)(iVar4 + 2);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(auStack_26 + -6,0,0xffffffff);
  (**(code **)(*DAT_00b5ae64 + 0x24))
            (*(undefined2 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  if (CONCAT22((short)((uint)in_EDX >> 0x10),uVar2) < 0x10) {
    ExceptionList = unaff_EDI;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0070b370 @ 0x0070b370 ====

/* WARNING: Removing unreachable block (ram,0x0070bdc6) */
/* WARNING: Removing unreachable block (ram,0x0070bd20) */
/* WARNING: Removing unreachable block (ram,0x0070bc64) */
/* WARNING: Removing unreachable block (ram,0x0070bba8) */
/* WARNING: Removing unreachable block (ram,0x0070baec) */
/* WARNING: Removing unreachable block (ram,0x0070ba30) */
/* WARNING: Removing unreachable block (ram,0x0070b974) */
/* WARNING: Removing unreachable block (ram,0x0070b879) */
/* WARNING: Removing unreachable block (ram,0x0070b7df) */
/* WARNING: Removing unreachable block (ram,0x0070b745) */
/* WARNING: Removing unreachable block (ram,0x0070b6ab) */
/* WARNING: Removing unreachable block (ram,0x0070b611) */
/* WARNING: Removing unreachable block (ram,0x0070b577) */
/* WARNING: Removing unreachable block (ram,0x0070b4dd) */
/* WARNING: Removing unreachable block (ram,0x0070b490) */
/* WARNING: Removing unreachable block (ram,0x0070b52a) */
/* WARNING: Removing unreachable block (ram,0x0070b5c4) */
/* WARNING: Removing unreachable block (ram,0x0070b65e) */
/* WARNING: Removing unreachable block (ram,0x0070b6f8) */
/* WARNING: Removing unreachable block (ram,0x0070b792) */
/* WARNING: Removing unreachable block (ram,0x0070b82c) */
/* WARNING: Removing unreachable block (ram,0x0070b916) */
/* WARNING: Removing unreachable block (ram,0x0070b9d2) */
/* WARNING: Removing unreachable block (ram,0x0070ba8e) */
/* WARNING: Removing unreachable block (ram,0x0070bb4a) */
/* WARNING: Removing unreachable block (ram,0x0070bc06) */
/* WARNING: Removing unreachable block (ram,0x0070bcc2) */
/* WARNING: Removing unreachable block (ram,0x0070bd73) */
/* WARNING: Removing unreachable block (ram,0x0070be19) */
/* WARNING: Removing unreachable block (ram,0x0070b443) */

void FUN_0070b370(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void **ppvVar4;
  undefined1 auStack_a2 [54];
  void *apvStack_6c [5];
  undefined4 uStack_58;
  uint uStack_54;
  void *apvStack_4c [5];
  uint uStack_38;
  void *pvStack_34;
  undefined1 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f26f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  FUN_00401660();
  pvStack_c = (void *)0x1;
  FUN_00401740();
  pvStack_c._0_1_ = 2;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 3;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 4;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 5;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 6;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 7;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 8;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 9;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 10;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 0xb;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 0xc;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 0xd;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 0xe;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 0xf;
  FUN_00406720();
  pvStack_c._0_1_ = 1;
  FUN_00401740();
  pvStack_c._0_1_ = 0x10;
  FUN_00406720();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x10))();
  ppvVar4 = apvStack_6c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppvVar4 = (void *)*puVar2;
    puVar2 = puVar2 + 1;
    ppvVar4 = ppvVar4 + 1;
  }
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb038,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x12;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb03c,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x13;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb040,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x14;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb044,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x15;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb048,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x16;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb04c,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x17;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb050,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x18;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb054,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x19;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb058,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x1a;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb05c,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x1b;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb060,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x1c;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401740(&DAT_009eb064,2);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x1d;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401830(&DAT_009eb068);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x1e;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401830(&DAT_009eb06c);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x1f;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00401830(&DAT_009eb070);
  FUN_00404230(auStack_a2 + -10);
  pvStack_c._0_1_ = 0x20;
  FUN_00406720();
  pvStack_c._0_1_ = 0x11;
  FUN_00404a40();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0x21);
  FUN_00401660(apvStack_4c,0);
  (**(code **)(*DAT_00b5ad0c + 0x2c))();
  if (0xf < uStack_54) {
    _free(apvStack_6c[1]);
    return;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  apvStack_6c[1] = (void *)((uint)apvStack_6c[1] & 0xffffff00);
  FUN_00406250();
  FUN_00406250();
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return;
  }
  _free(apvStack_4c[0]);
  return;
}


// ==== FUN_0070bef0 @ 0x0070bef0 ====

undefined4 FUN_0070bef0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x5260000) {
  case 0:
    FUN_0070ae40(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 1:
    FUN_0070b370(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 4:
    FUN_0070af40(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 5:
    FUN_0070af70(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 6:
    FUN_0070afe0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 7:
    FUN_0070b010(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 8:
    FUN_0070b040(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 9:
    FUN_0070b070(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 10:
    (**(code **)(*DAT_00b5ae64 + 0x38))();
    return 1;
  case 0xb:
    FUN_0070b0b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xc:
    FUN_0070b2a0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xe:
    FUN_0070b0e0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x11:
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return 1;
  }
}


// ==== FUN_0070c050 @ 0x0070c050 ====

undefined4 FUN_0070c050(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0070bef0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0070c080 @ 0x0070c080 ====

void FUN_0070c080(byte param_1)

{
  void *in_ECX;
  
  FUN_0070b280();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070c0a0 @ 0x0070c0a0 ====

void FUN_0070c0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb1ac;
  return;
}


// ==== FUN_0070c0b0 @ 0x0070c0b0 ====

void FUN_0070c0b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb1ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070c100 @ 0x0070c100 ====

void FUN_0070c100(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eb254;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb218;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c150 @ 0x0070c150 ====

void FUN_0070c150(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 1;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb22c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c180 @ 0x0070c180 ====

void FUN_0070c180(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb240;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c1b0 @ 0x0070c1b0 ====

void FUN_0070c1b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb1f0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c1e0 @ 0x0070c1e0 ====

void FUN_0070c1e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb204;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c210 @ 0x0070c210 ====

void FUN_0070c210(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb268;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c240 @ 0x0070c240 ====

void FUN_0070c240(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb27c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c270 @ 0x0070c270 ====

void FUN_0070c270(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb290;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c2a0 @ 0x0070c2a0 ====

void FUN_0070c2a0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb2a4;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c2e0 @ 0x0070c2e0 ====

void FUN_0070c2e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb2b8;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c310 @ 0x0070c310 ====

void FUN_0070c310(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eb2cc;
  }
  *(undefined2 *)(puVar1 + 1) = param_3;
  puVar1[2] = param_2;
  puVar1[3] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c350 @ 0x0070c350 ====

void FUN_0070c350(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb2e0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0070c380 @ 0x0070c380 ====

undefined4 FUN_0070c380(int param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_dungeoninfo_009eb15c,0x10);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_dungeoninfo_009eb170,0x10);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x14))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_vanishtime_009eb184,0xf);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x34))(0x18,1000,0x32);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1 + 8,s_hide_vanishtime_009eb194);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*in_ECX + 0x38))();
  return 1;
}


// ==== FUN_0070c430 @ 0x0070c430 ====

undefined4 FUN_0070c430(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x20001) {
    if (((char)in_ECX[1] != '\0') && (param_1[1] == 0x1b)) {
      (**(code **)(*in_ECX + 0x14))();
      return 1;
    }
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_0070c380(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0070c490 @ 0x0070c490 ====

void FUN_0070c490(void)

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
  
  puStack_8 = &LAB_0098f2f8;
  pvStack_c = ExceptionList;
  uStack_5c = (uint *)0x0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009eb30c;
  *(undefined1 *)(in_ECX + 1) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740();
  uStack_5c = (uint *)0x10;
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
  FUN_00401740(&DAT_009eb0b9);
  uStack_1c._0_1_ = 5;
  local_44 = 0xf;
  FUN_00401740(s_show_vanishtime_009eb0bc);
  _Memory = &uStack_5c;
  uStack_1c = CONCAT31(uStack_1c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
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
  FUN_00401740(&DAT_009eb0cc,0);
  local_28._0_1_ = 7;
  FUN_00401740(s_hide_vanishtime_009eb0d0,0xf);
  local_28 = CONCAT31(local_28._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + 6,0,auStack_46 + -6);
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
  FUN_00401740(&DAT_009eb0e0,0);
  uStack_34._0_1_ = 9;
  uStack_5c = (uint *)0xf;
  FUN_00401740(s_show_dungeoneffectui_009eb0e4,0x14);
  uStack_34 = CONCAT31(uStack_34._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + -6,4,auStack_6e + 0x16);
  if ((uint *)0xf < puVar1) {
    _free(_Memory);
    return;
  }
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free((void *)0x0);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae64 = (undefined4 *)0x0;
    ExceptionList = (void *)0x0;
    return;
  }
  DAT_00b5ae64 = in_ECX;
  ExceptionList = (void *)0x0;
  return;
}


// ==== FUN_0070c7d0 @ 0x0070c7d0 ====

void FUN_0070c7d0(void)

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
  
  puStack_8 = &LAB_0098f332;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009eb30c;
  local_4 = 0;
  DAT_00b5ae64 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  local_2c = in_ECX;
  FUN_00401740(s_show_dungeoneffectui_009eb0fc,0x14);
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
  FUN_00401740(s_show_dungeoninfo_009eb114,0x10);
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
  FUN_00401740(s_hide_dungeoninfo_009eb128,0x10);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  pvStack_20 = (void *)0x0;
  FUN_00401740(s_show_vanishtime_009eb13c,0xf);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  local_14 = local_14 & 0xffffff00;
  if (0xf < pvStack_20) {
    _free(unaff_EBP);
    return;
  }
  pvStack_20 = (void *)0xf;
  local_24 = 0;
  FUN_00401740(s_hide_vanishtime_009eb14c,0xf);
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x38);
  if (local_24 < 0x10) {
    *in_ECX = &PTR_FUN_009eb1ac;
    ExceptionList = pvStack_20;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0070c990 @ 0x0070c990 ====

void FUN_0070c990(undefined4 param_1,undefined4 param_2,undefined1 param_3,void *param_4)

{
  undefined4 *puVar1;
  uint in_stack_00000024;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098f344;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_009eb2f4;
    puVar1[9] = 0xf;
    puVar1[8] = 0;
    *(undefined1 *)(puVar1 + 4) = 0;
  }
  FUN_00401660(&param_3,0,0xffffffff);
  FUN_0070cb80(param_1,param_2);
  FUN_00797a20();
  if (in_stack_00000024 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_4);
  return;
}


// ==== FUN_0070ca40 @ 0x0070ca40 ====

undefined4 FUN_0070ca40(void)

{
  return 0x70450000;
}


// ==== FUN_0070ca50 @ 0x0070ca50 ====

undefined4 FUN_0070ca50(void)

{
  return 0x70450001;
}


// ==== FUN_0070ca60 @ 0x0070ca60 ====

undefined4 FUN_0070ca60(void)

{
  return 0x70450002;
}


// ==== FUN_0070ca70 @ 0x0070ca70 ====

undefined4 FUN_0070ca70(void)

{
  return 0x70450005;
}


// ==== FUN_0070ca80 @ 0x0070ca80 ====

undefined4 FUN_0070ca80(void)

{
  return 0x70450006;
}


// ==== FUN_0070ca90 @ 0x0070ca90 ====

undefined4 FUN_0070ca90(void)

{
  return 0x70450007;
}


// ==== FUN_0070caa0 @ 0x0070caa0 ====

undefined4 FUN_0070caa0(void)

{
  return 0x70450010;
}


// ==== FUN_0070cab0 @ 0x0070cab0 ====

undefined4 FUN_0070cab0(void)

{
  return 0x70450011;
}


// ==== FUN_0070cac0 @ 0x0070cac0 ====

undefined4 FUN_0070cac0(void)

{
  return 0x70450015;
}


// ==== FUN_0070cad0 @ 0x0070cad0 ====

undefined4 FUN_0070cad0(void)

{
  return 0x70450019;
}


// ==== FUN_0070cae0 @ 0x0070cae0 ====

undefined4 FUN_0070cae0(void)

{
  return 0x70450020;
}


// ==== FUN_0070caf0 @ 0x0070caf0 ====

undefined4 FUN_0070caf0(void)

{
  return 0x70450024;
}


// ==== FUN_0070cb00 @ 0x0070cb00 ====

undefined4 FUN_0070cb00(void)

{
  return 0x70450025;
}


// ==== FUN_0070cb10 @ 0x0070cb10 ====

undefined4 FUN_0070cb10(void)

{
  return 0x70450014;
}


// ==== FUN_0070cb20 @ 0x0070cb20 ====

void FUN_0070cb20(byte param_1)

{
  void *in_ECX;
  
  FUN_0070cb40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070cb40 @ 0x0070cb40 ====

void FUN_0070cb40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb2f4;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0070cb80 @ 0x0070cb80 ====

void FUN_0070cb80(undefined4 param_1,undefined4 param_2,undefined1 param_3,void *param_4)

{
  int in_ECX;
  uint in_stack_00000024;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098f288;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = param_1;
  *(undefined4 *)(in_ECX + 8) = param_2;
  local_4 = 0;
  FUN_00401660(&param_3,0,0xffffffff);
  if (in_stack_00000024 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_4);
  return;
}


// ==== FUN_0070cbe0 @ 0x0070cbe0 ====

void FUN_0070cbe0(byte param_1)

{
  void *in_ECX;
  
  FUN_0070c7d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070cc00 @ 0x0070cc00 ====

void FUN_0070cc00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb3f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0070cc60 @ 0x0070cc60 ====

void FUN_0070cc60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb3fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac90 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac90 = in_ECX;
  return;
}


// ==== FUN_0070cc90 @ 0x0070cc90 ====

void FUN_0070cc90(void)

{
  (**(code **)(*DAT_00b5ac98 + 0x38))();
                    /* WARNING: Could not recover jumptable at 0x0070ccae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac98 + 0x30))();
  return;
}


// ==== FUN_0070ccc0 @ 0x0070ccc0 ====

void FUN_0070ccc0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_3ac [233];
  
  iVar1 = *DAT_00b5ac98;
  puVar3 = (undefined4 *)(param_1 + 0x10);
  puVar4 = auStack_3ac;
  for (iVar2 = 0xe9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  (**(code **)(iVar1 + 0x70))();
  (**(code **)(*DAT_00b5ac94 + 0x54))();
  (**(code **)(*DAT_00b5ac94 + 0x58))();
  return;
}


// ==== FUN_0070cd00 @ 0x0070cd00 ====

void FUN_0070cd00(void)

{
  (**(code **)(*DAT_00b5ac94 + 0x3c))();
  (**(code **)(*DAT_00b5ac94 + 0x48))();
  return;
}


// ==== FUN_0070cd20 @ 0x0070cd20 ====

void FUN_0070cd20(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aaf8 + 8))(*(undefined4 *)(param_1 + 0x10));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00b5abec + 0xc))(param_1 + 0x14);
    if ((iVar2 == 0) && (iVar2 = (**(code **)(*DAT_00b5ac9c + 0xc))(param_1 + 0x14), iVar2 == 0)) {
      return;
    }
    (**(code **)(*piVar1 + 8))(iVar2);
  }
  return;
}


// ==== FUN_0070cd70 @ 0x0070cd70 ====

void FUN_0070cd70(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*DAT_00b5ac98 + 0x4c))
              (*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),uStack_8,
               *(undefined1 *)(param_1 + 0x34));
    iVar1 = *piVar2;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    (**(code **)(iVar1 + 0x20))(uVar3 / 1000 + *(int *)(param_1 + 0x20));
  }
  return;
}


// ==== FUN_0070cdf0 @ 0x0070cdf0 ====

void FUN_0070cdf0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = (**(code **)(*DAT_00b5ac98 + 4))();
  FUN_008278a0(param_1,uVar1);
  piVar2 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0070ce28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x14))();
  return;
}


// ==== FUN_0070ce30 @ 0x0070ce30 ====

void FUN_0070ce30(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iStack_8;
  int iStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = DAT_00b5aa18;
  uVar3 = FUN_00424520();
  iStack_8 = (uVar3 & 0xffff) - 0x1c;
  iStack_4 = param_1 + 0x1c;
  (**(code **)(*piVar1 + 0xa8))(&iStack_8,uVar2);
  (**(code **)(*DAT_00b5adc8 + 0x10))();
  (**(code **)(*DAT_00b5add0 + 0x50))();
  return;
}


// ==== FUN_0070cea0 @ 0x0070cea0 ====

void FUN_0070cea0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iStack_8;
  int iStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = DAT_00b5aa18;
  uVar3 = FUN_00424520();
  iStack_8 = (uVar3 & 0xffff) - 0x10;
  iStack_4 = param_1 + 0x10;
  (**(code **)(*piVar1 + 0xb8))(&iStack_8,uVar2);
  return;
}


// ==== FUN_0070cef0 @ 0x0070cef0 ====

void FUN_0070cef0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iStack_8;
  int iStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = DAT_00b5aa18;
  uVar3 = FUN_00424520();
  iStack_8 = (uVar3 & 0xffff) - 0x10;
  iStack_4 = param_1 + 0x10;
  (**(code **)(*piVar1 + 0xbc))(&iStack_8,uVar2);
  (**(code **)(*DAT_00b5adc8 + 0x10))();
  (**(code **)(*DAT_00b5add0 + 0x50))();
  return;
}


// ==== FUN_0070cf60 @ 0x0070cf60 ====

void FUN_0070cf60(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iStack_8;
  int iStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = DAT_00b5aa18;
  uVar3 = FUN_00424520();
  iStack_8 = (uVar3 & 0xffff) - 0x1c;
  iStack_4 = param_1 + 0x1c;
  (**(code **)(*piVar1 + 0xa4))(&iStack_8,uVar2);
  return;
}


// ==== FUN_0070cfb0 @ 0x0070cfb0 ====

void FUN_0070cfb0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac90 = 0;
  *in_ECX = &PTR_FUN_009eb3f0;
  return;
}


// ==== FUN_0070cfd0 @ 0x0070cfd0 ====

void FUN_0070cfd0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char local_44 [33];
  char local_23 [25];
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  FUN_00496ec0();
  uVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x18 + uVar2);
    local_44[uVar2] = cVar1;
    if (cVar1 == '\0') goto LAB_0070cffe;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x21);
  local_44[0] = '\0';
LAB_0070cffe:
  uVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x39 + uVar2);
    local_23[uVar2] = cVar1;
    if (cVar1 == '\0') goto LAB_0070d019;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  local_23[0] = '\0';
LAB_0070d019:
  local_8 = *(undefined2 *)(param_1 + 0x54);
  local_a = *(undefined2 *)(param_1 + 0x52);
  local_6 = *(undefined2 *)(param_1 + 0x56);
  iVar3 = (**(code **)(*DAT_00b5abec + 0xc))(param_1 + 0x18);
  if (iVar3 != 0) {
    (**(code **)(*DAT_00b5abec + 8))(iVar3);
  }
  iVar3 = (**(code **)(*DAT_00b5abf0 + 4))(local_44 + -4);
  if (iVar3 != 0) {
    (**(code **)(*DAT_00b5abec + 4))(iVar3);
  }
  return;
}


// ==== FUN_0070d080 @ 0x0070d080 ====

/* WARNING: Removing unreachable block (ram,0x0070d121) */

void FUN_0070d080(void)

{
  int *piVar1;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f358;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar1 != (int *)0x0) {
    uStack_38 = (undefined1 *)0x70d0b7;
    (**(code **)(*piVar1 + 0x48))();
    uStack_38 = (undefined1 *)0x2bc008c;
    uStack_3c = 8;
    uStack_40 = 0x70d0c9;
    uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0xffffffff;
    uStack_44 = 0;
    uStack_4c = 0x70d0e6;
    FUN_00401660();
    uStack_38 = auStack_58;
    uStack_40 = 0xf;
    uStack_44 = 0;
    uStack_54 = 0;
    FUN_00401660(auStack_58 + 0x24,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0070d140 @ 0x0070d140 ====

void FUN_0070d140(int param_1)

{
  int iVar1;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098f36a;
  pvStack_c = ExceptionList;
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 < 1) {
    if (iVar1 == 0) {
      uStack_30 = 0x2bc0074;
      goto LAB_0070d1cb;
    }
    switch(iVar1) {
    case -0x137:
      uStack_30 = 0x3200014;
      break;
    case -0x136:
      uStack_30 = 0x320000a;
      break;
    default:
      goto switchD_0070d172_caseD_fffffecb;
    case -0x134:
      uStack_30 = 0x2bc006e;
      break;
    case -0x133:
      uStack_30 = 0x2bc0032;
      break;
    case -0x132:
      uStack_30 = 0x2bc0076;
      break;
    case -0x131:
      uStack_30 = 0x2bc0064;
      break;
    case -0x130:
      uStack_30 = 0x2bc0073;
      break;
    case -0x12f:
      uStack_30 = 0x2bc0063;
      break;
    case -0x12e:
      uStack_30 = 0x2bc0075;
      break;
    case -0x12d:
      uStack_30 = 0x2bc0005;
    }
  }
  else {
switchD_0070d172_caseD_fffffecb:
    uStack_30 = 0x2bc000c;
  }
LAB_0070d1cb:
  pvStack_34 = (void *)0x8;
  uStack_38 = 0x70d1d9;
  ExceptionList = &pvStack_c;
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_38 = 0xffffffff;
  uStack_3c = 0;
  uStack_44 = 0x70d1f6;
  FUN_00401660();
  puStack_4 = auStack_50;
  uStack_38 = 0xf;
  uStack_3c = 0;
  pvStack_c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401660(&uStack_30,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0070d280 @ 0x0070d280 ====

void FUN_0070d280(int param_1)

{
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined1 auStack_30 [32];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098f3a4;
  local_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    iStack_48 = param_1;
    uStack_4c = 0x70d2bc;
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5ac94 + 0x28))();
    ExceptionList = pvStack_10;
    return;
  case 1:
    iStack_48 = 0x3200028;
    uStack_4c = 8;
    uStack_50 = 0x70d2df;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x70d2e9;
    FUN_00765c50();
    local_c = (void *)0x0;
    break;
  case 2:
    iStack_48 = 0x3200029;
    uStack_4c = 8;
    uStack_50 = 0x70d308;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x70d312;
    FUN_00765c50();
    puStack_4 = auStack_68;
    local_c = (void *)0x1;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070d445;
  case 3:
    iStack_48 = 0x320002a;
    uStack_4c = 8;
    uStack_50 = 0x70d354;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x70d35e;
    FUN_00765c50();
    local_c = (void *)0x2;
    break;
  case 4:
    iStack_48 = 0x320002a;
    uStack_4c = 8;
    uStack_50 = 0x70d37a;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x70d384;
    FUN_00765c50();
    puStack_4 = auStack_68;
    local_c = (void *)0x3;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070d445;
  case 5:
    iStack_48 = 0x320002b;
    uStack_4c = 8;
    uStack_50 = 0x70d3c6;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x70d3d0;
    FUN_00765c50();
    local_c = (void *)0x4;
    break;
  case 6:
    iStack_48 = 0x320002c;
    uStack_4c = 8;
    uStack_50 = 0x70d40f;
    ExceptionList = &local_c;
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0x70d419;
    FUN_00765c50();
    puStack_4 = auStack_68;
    local_c = (void *)0x5;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070d445;
  default:
    return;
  }
  puStack_4 = auStack_68;
  FUN_00765c50(&uStack_4c);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0070d445:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0070d480 @ 0x0070d480 ====

void FUN_0070d480(int param_1)

{
  undefined1 *puVar1;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_30 [28];
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098f3de;
  local_c = ExceptionList;
  uStack_50 = *(undefined4 *)(param_1 + 0x14);
  puVar1 = (undefined1 *)(param_1 + 0x10);
  param_1 = CONCAT31(param_1._1_3_,*(undefined1 *)(param_1 + 0x18));
  switch(*puVar1) {
  case 0:
    uStack_4c = param_1;
    uStack_54 = 0x70d4cc;
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5ac94 + 0x20))();
    ExceptionList = pvStack_14;
    return;
  case 1:
    uStack_4c = 0x3200014;
    uStack_50 = 8;
    uStack_54 = 0x70d4f0;
    ExceptionList = &local_c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x70d4fa;
    FUN_00765c50();
    local_c = (void *)0x0;
    break;
  case 2:
    uStack_4c = 0x3200015;
    uStack_50 = 8;
    uStack_54 = 0x70d519;
    ExceptionList = &local_c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x70d523;
    FUN_00765c50();
    puStack_4 = auStack_6c;
    local_c = (void *)0x1;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070d659;
  case 3:
    uStack_4c = 0x3200016;
    uStack_50 = 8;
    uStack_54 = 0x70d566;
    ExceptionList = &local_c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x70d570;
    FUN_00765c50();
    local_c = (void *)0x2;
    break;
  case 4:
    uStack_4c = 0x3200017;
    uStack_50 = 8;
    uStack_54 = 0x70d58c;
    ExceptionList = &local_c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x70d596;
    FUN_00765c50();
    puStack_4 = auStack_6c;
    local_c = (void *)0x3;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070d659;
  case 5:
    uStack_4c = 0x3200018;
    uStack_50 = 8;
    uStack_54 = 0x70d5d9;
    ExceptionList = &local_c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x70d5e3;
    FUN_00765c50();
    local_c = (void *)0x4;
    break;
  case 6:
    uStack_4c = 0x3200019;
    uStack_50 = 8;
    uStack_54 = 0x70d623;
    ExceptionList = &local_c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x70d62d;
    FUN_00765c50();
    puStack_4 = auStack_6c;
    local_c = (void *)0x5;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070d659;
  default:
    return;
  }
  puStack_4 = auStack_6c;
  FUN_00765c50(&uStack_4c);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0070d659:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0070d690 @ 0x0070d690 ====

void FUN_0070d690(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  void *unaff_EDI;
  int unaff_retaddr;
  undefined1 auStack_60 [4];
  undefined1 uStack_5c;
  undefined4 uStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f3f0;
  pvStack_c = ExceptionList;
  uStack_3c = 5;
  uStack_40 = 0x70d6b9;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar4 = *(int *)(unaff_retaddr + 0x10);
  if (iVar4 < 7) {
    if (iVar4 == 6) {
      uVar5 = 0x2bc0016;
      goto LAB_0070d7ab;
    }
    if (iVar4 < 3) {
      if (iVar4 == 2) {
        uVar5 = 0x2bc0004;
        goto LAB_0070d7ab;
      }
      if (iVar4 == -0x136) {
        uVar5 = 0x2bc000a;
        goto LAB_0070d7ab;
      }
      if (iVar4 == 0) {
        uVar5 = 0x2bc0071;
        goto LAB_0070d7ab;
      }
      if (iVar4 == 1) {
        uVar5 = 0x2bc0032;
        goto LAB_0070d7ab;
      }
    }
    else {
      if (iVar4 == 3) {
        uVar5 = 0x2bc0010;
        goto LAB_0070d7ab;
      }
      if (iVar4 == 4) {
        uVar5 = 0x2bc0079;
        goto LAB_0070d7ab;
      }
      if (iVar4 == 5) {
        uVar5 = 0x2bc0005;
        goto LAB_0070d7ab;
      }
    }
switchD_0070d746_default:
    uVar5 = 0x2bc000c;
  }
  else {
    switch(iVar4) {
    case 7:
      uVar5 = 0x2bc0063;
      break;
    case 8:
      uVar5 = 0x2bc0072;
      break;
    case 9:
      uVar5 = 0x2bc0073;
      break;
    case 10:
      uVar5 = 0x2bc0064;
      break;
    case 0xb:
      uVar5 = 0x2bc0061;
      uStack_40 = 0x70d779;
      piVar3 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
      piVar1 = DAT_00b5ac1c;
      if (piVar3 != (int *)0x0) {
        uStack_40 = 0x70d78a;
        iVar4 = (**(code **)(*piVar3 + 0x18))();
        uStack_40 = 0x70d793;
        cVar2 = (**(code **)(*piVar1 + 0xc))();
        if (*(char *)(iVar4 + 0xd) != cVar2) {
          uVar5 = 0x2bc006c;
        }
      }
      break;
    case 0xc:
      uVar5 = 0x2bc006d;
      break;
    default:
      goto switchD_0070d746_default;
    }
  }
LAB_0070d7ab:
  uStack_44 = 8;
  uStack_48 = 0x70d7b9;
  uStack_40 = uVar5;
  pvStack_50 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_48 = 0xffffffff;
  uStack_4c = 0;
  uStack_54 = 0x70d7d7;
  FUN_00401660();
  puStack_8 = auStack_60;
  uStack_48 = 0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  FUN_00401660(auStack_60 + 0x2c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  (**(code **)(*DAT_00b5ac94 + 0x90))();
  if (uStack_3c < 0x10) {
    ExceptionList = unaff_EDI;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_0070d860 @ 0x0070d860 ====

void FUN_0070d860(void)

{
  int iVar1;
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f482;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (-100 < iVar1) {
    switch(iVar1) {
    case 0:
      uStack_54 = 8;
      uStack_58 = 0x70db63;
      uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0x70db6d;
      FUN_00765c50();
      pvStack_10 = (void *)0x0;
      break;
    case -0x22:
      uStack_54 = 8;
      uStack_58 = 0x70dbf5;
      uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0x70dbff;
      FUN_00765c50();
      pvStack_10 = (void *)0xf;
      goto LAB_0070dc07;
    case -0x21:
      uStack_54 = 8;
      uStack_58 = 0x70dbaf;
      uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0x70dbb9;
      FUN_00765c50();
      pvStack_10 = (void *)0x4;
      break;
    case -0x20:
      uStack_54 = 8;
      uStack_58 = 0x70db89;
      uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0x70db93;
      FUN_00765c50();
      pvStack_10 = (void *)0x2;
      goto LAB_0070dc07;
    default:
      goto switchD_0070d8aa_default;
    }
    goto LAB_0070dbc1;
  }
  if (iVar1 == -100) {
    uStack_54 = 8;
    uStack_58 = 0x70daaf;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x70dace;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x10;
    uStack_6c = 0;
    FUN_00401660(auStack_70 + 0x20,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_30) {
      uStack_54 = 0x70db1f;
      _free(pvStack_44);
      return;
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
switchD_0070d8aa_default:
    (**(code **)(*DAT_00b5ac94 + 0x80))();
    ExceptionList = pvStack_10;
    return;
  }
  switch(iVar1) {
  case -0x138:
    uStack_54 = 8;
    uStack_58 = 0x70d8c3;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d8cd;
    FUN_00765c50();
    pvStack_10 = (void *)0x1;
    break;
  case -0x137:
    uStack_54 = 8;
    uStack_58 = 0x70da86;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70da90;
    FUN_00765c50();
    pvStack_10 = (void *)0xe;
    goto LAB_0070dc07;
  case -0x136:
    uStack_54 = 8;
    uStack_58 = 0x70da5d;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70da67;
    FUN_00765c50();
    pvStack_10 = (void *)0xd;
    break;
  case -0x135:
    uStack_54 = 8;
    uStack_58 = 0x70da34;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70da3e;
    FUN_00765c50();
    pvStack_10 = (void *)0xc;
    goto LAB_0070dc07;
  case -0x134:
    uStack_54 = 8;
    uStack_58 = 0x70da0b;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70da15;
    FUN_00765c50();
    pvStack_10 = (void *)0xb;
    break;
  case -0x133:
    uStack_54 = 8;
    uStack_58 = 0x70d9e2;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d9ec;
    FUN_00765c50();
    pvStack_10 = (void *)0xa;
    goto LAB_0070dc07;
  case -0x132:
    uStack_54 = 8;
    uStack_58 = 0x70d990;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d99a;
    FUN_00765c50();
    pvStack_10 = (void *)0x8;
    goto LAB_0070dc07;
  case -0x131:
    uStack_54 = 8;
    uStack_58 = 0x70d967;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d971;
    FUN_00765c50();
    pvStack_10 = (void *)0x7;
    break;
  case -0x130:
    uStack_54 = 8;
    uStack_58 = 0x70d9b9;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d9c3;
    FUN_00765c50();
    pvStack_10 = (void *)0x9;
    break;
  case -0x12f:
    uStack_54 = 8;
    uStack_58 = 0x70d8ec;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d8f6;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    goto LAB_0070dc07;
  case -0x12e:
    uStack_54 = 8;
    uStack_58 = 0x70d93e;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d948;
    FUN_00765c50();
    pvStack_10 = (void *)0x6;
LAB_0070dc07:
    puStack_8 = auStack_70;
    FUN_00765c50(&uStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070dc27;
  case -0x12d:
    uStack_54 = 8;
    uStack_58 = 0x70d915;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0x70d91f;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    break;
  default:
    goto switchD_0070d8aa_default;
  }
LAB_0070dbc1:
  puStack_8 = auStack_70;
  FUN_00765c50(&uStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0070dc27:
  uStack_30 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0070dcc0 @ 0x0070dcc0 ====

void FUN_0070dcc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint unaff_ESI;
  int *piVar3;
  int unaff_retaddr;
  undefined1 auStack_84 [4];
  undefined1 uStack_80;
  undefined4 uStack_78;
  undefined4 uStack_74;
  int iStack_70;
  void *pvStack_6c;
  float fStack_68;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  undefined1 auStack_4a [22];
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  void *pvStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f4d4;
  pvStack_c = ExceptionList;
  uStack_60 = 5;
  puStack_64 = (undefined1 *)0x70dce9;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x10)) {
  case 0:
    puStack_64 = (undefined1 *)0x70dd23;
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    puStack_64 = auStack_4a + -6;
    fStack_68 = 1.036493e-38;
    fStack_68 = (float)(**(code **)(*DAT_00b5a6ac + 0x20))();
    pvStack_6c = (void *)CONCAT22((short)((uint)fStack_68 >> 0x10),
                                  *(undefined2 *)(unaff_retaddr + 0x24));
    uStack_74 = 0x70dd41;
    iStack_70 = iVar1;
    FUN_00827960();
    if (*(int **)(iVar1 + 0x44) == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      puStack_64 = (undefined1 *)0x70dd54;
      piVar3 = (int *)(**(code **)(**(int **)(iVar1 + 0x44) + 0x18))();
    }
    puStack_64 = (undefined1 *)(float)*(int *)(unaff_retaddr + 0x18);
    fStack_68 = 1.0365001e-38;
    (**(code **)(*piVar3 + 0x14))();
    fStack_68 = (float)*(int *)(unaff_retaddr + 0x1c);
    pvStack_6c = (void *)0x70dd7a;
    (**(code **)(*piVar3 + 0x20))();
    pvStack_6c = (void *)(unaff_retaddr + 0x14);
    iStack_70 = 0x70dd86;
    (**(code **)(**(int **)(iVar1 + 0x48) + 0x18))();
    iStack_70 = 0x70dd91;
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 == 0) {
      iStack_70 = 0;
    }
    else {
      iStack_70 = 0x70dd9c;
      iStack_70 = FUN_00511760();
    }
    *(undefined4 *)(iStack_70 + 4) = *(undefined4 *)(unaff_retaddr + 0x26);
    *(undefined2 *)(iStack_70 + 8) = *(undefined2 *)(unaff_retaddr + 0x2a);
    *(undefined1 *)(iStack_70 + 10) = 1;
    uStack_74 = 0x70ddbc;
    FUN_00797a20();
    iStack_70 = 0x70ddca;
    (**(code **)(*DAT_00b5ac94 + 0x40))();
    ExceptionList = pvStack_1c;
    return;
  case 1:
    puStack_64 = (undefined1 *)0x2bc0036;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70ddf1;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70ddfb;
    FUN_00765c50();
    puStack_8 = auStack_84;
    uStack_10 = 0;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  default:
    puStack_64 = (undefined1 *)0x2bc0032;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70e048;
    uStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pvStack_6c = (void *)0xffffffff;
    iStack_70 = 0;
    uStack_78 = 0x70e066;
    FUN_00401660();
    puStack_8 = auStack_84;
    pvStack_6c = (void *)0xf;
    iStack_70 = 0;
    uStack_10 = 8;
    uStack_80 = 0;
    FUN_00401660(auStack_4a + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_30 = 0xffffffff;
    if (0xf < unaff_ESI) {
      _free(pvStack_6c);
      return;
    }
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b6de4;
    }
    FUN_00797a20(puVar2);
    ExceptionList = (void *)0xf;
    return;
  case 3:
    puStack_64 = (undefined1 *)0x2bc0030;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70de7c;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70de86;
    FUN_00765c50();
    puStack_8 = auStack_84;
    uStack_10 = 2;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5ac94 + 0x50))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    puStack_64 = (undefined1 *)0x2bc001f;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70dee9;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70def3;
    FUN_00765c50();
    uStack_10 = 3;
    goto LAB_0070defb;
  case 5:
    puStack_64 = (undefined1 *)0x2bc0069;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70df32;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70df3c;
    FUN_00765c50();
    uStack_10 = 4;
    break;
  case 6:
    puStack_64 = (undefined1 *)0x2bc0068;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70df5b;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70df65;
    FUN_00765c50();
    uStack_10 = 5;
LAB_0070defb:
    puStack_8 = auStack_84;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0070e020;
  case 7:
    puStack_64 = (undefined1 *)0x2bc0030;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70df81;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70df8b;
    FUN_00765c50();
    puStack_8 = auStack_84;
    uStack_10 = 6;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5ac94 + 0x50))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 8:
    puStack_64 = (undefined1 *)0x2bc0010;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70dfee;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70dff8;
    FUN_00765c50();
    uStack_10 = 7;
    break;
  case 9:
    puStack_64 = (undefined1 *)0x2bc0032;
    fStack_68 = 1.12104e-44;
    pvStack_6c = (void *)0x70de53;
    pvStack_6c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_70 = 0x70de5d;
    FUN_00765c50();
    uStack_10 = 1;
  }
  puStack_8 = auStack_84;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0070e020:
  uStack_30 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0070e130 @ 0x0070e130 ====

void FUN_0070e130(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int unaff_retaddr;
  undefined1 auStack_60 [4];
  undefined1 uStack_5c;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f4e6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (iVar1 < -0x22) {
    switch(iVar1) {
    case -0x130:
      break;
    case -0x12f:
      break;
    case -0x12e:
      break;
    case -0x12d:
      break;
    case -100:
    }
  }
  else {
    switch(iVar1) {
    case 0:
      piVar2 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
      if (piVar2 == (int *)0x0) {
        ExceptionList = pvStack_10;
        return;
      }
      iStack_44 = 0x70e1fa;
      (**(code **)(*piVar2 + 0x1c))();
      iVar1 = *piVar2;
      iStack_44 = 0x70e207;
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iStack_44 = uVar3 / 1000 + *(int *)(unaff_retaddr + 0x1c);
      uStack_48 = 0x70e21c;
      (**(code **)(iVar1 + 0x20))();
      break;
    case -0x22:
      break;
    case -0x21:
      break;
    case -0x20:
      break;
    case -0x1f:
    }
  }
  iStack_44 = 8;
  uStack_48 = 0x70e24b;
  uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_48 = 0xffffffff;
  uStack_4c = 0;
  uStack_54 = 0x70e269;
  FUN_00401660();
  puStack_8 = auStack_60;
  uStack_48 = 0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  FUN_00401660(auStack_60 + 0x2c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  (**(code **)(*DAT_00b5ac94 + 0x84))();
  (**(code **)(*DAT_00b5ac94 + 0x34))();
  if (uStack_14 < 0x10) {
    ExceptionList = (void *)0x0;
    return;
  }
  iStack_44 = 0x70e2c3;
  _free(pvStack_28);
  return;
}


// ==== FUN_0070e400 @ 0x0070e400 ====

void FUN_0070e400(void)

{
  int *piVar1;
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
  puStack_8 = &LAB_0098f4f8;
  pvStack_c = ExceptionList;
  uStack_34 = 0x70e424;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  uStack_34 = 0x70e42b;
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  uStack_34 = 2;
  puStack_38 = (undefined1 *)0x70e434;
  (**(code **)(*piVar1 + 0xc))();
  puStack_38 = (undefined1 *)0x70e43f;
  (**(code **)(*DAT_00b5ac94 + 4))();
  puStack_38 = (undefined1 *)0x2bc0001;
  uStack_3c = 8;
  uStack_40 = 0x70e451;
  uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_40 = 0xffffffff;
  uStack_44 = 0;
  uStack_4c = 0x70e470;
  FUN_00401660();
  puStack_38 = auStack_58;
  uStack_40 = 0xf;
  uStack_44 = 0;
  uStack_54 = 0;
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_3c < 0x10) {
    ExceptionList = puStack_38;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_0070e4d0 @ 0x0070e4d0 ====

void FUN_0070e4d0(void)

{
  char cVar1;
  int *piVar2;
  undefined1 auStack_250 [36];
  void *pvStack_21c;
  uint uStack_208;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f518;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if ((piVar2 != (int *)0x0) &&
     (piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(), piVar2 != (int *)0x0)) {
    (**(code **)(*DAT_00b5acac + 0xc))();
    uStack_4 = 0;
    FUN_0050cd30();
    cVar1 = FUN_00710720();
    if (cVar1 == '\0') {
      (**(code **)(*piVar2 + 0xc))();
      (**(code **)(*DAT_00b5ac94 + 4))();
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      FUN_00401660(auStack_250 + 0x24,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_208) {
        _free(pvStack_21c);
        return;
      }
    }
    uStack_4 = 0xffffffff;
    FUN_00537c20();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0070e630 @ 0x0070e630 ====

void FUN_0070e630(int param_1)

{
  int *piVar1;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f52a;
  pvStack_c = ExceptionList;
  uStack_30 = 0x70e654;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  uStack_30 = 0x70e65b;
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  uStack_30 = (uint)*(byte *)(param_1 + 0x18);
  uStack_34 = 0x70e66b;
  (**(code **)(*piVar1 + 0xc))();
  uStack_34 = 0x70e676;
  (**(code **)(*DAT_00b5ac94 + 4))();
  uStack_34 = 0x2bc002b;
  pvStack_38 = (void *)0x8;
  uStack_3c = 0x70e688;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_30 = uStack_30 & 0xffffff00;
  uStack_48 = 0x70e6a7;
  FUN_00401660();
  puStack_8 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_0070e710 @ 0x0070e710 ====

void FUN_0070e710(int param_1)

{
  int *piVar1;
  undefined1 *unaff_ESI;
  undefined1 auStack_108 [20];
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 *puStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined1 *puStack_dc;
  undefined1 *apuStack_d8 [5];
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 auStack_a6 [14];
  uint uStack_98;
  undefined4 uStack_88;
  undefined1 uStack_84;
  undefined4 uStack_80;
  undefined1 auStack_78 [24];
  undefined1 auStack_60 [40];
  undefined1 uStack_38;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_0098f5cd;
  local_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    uStack_b4 = *(char **)(param_1 + 0x18);
    uStack_b8 = 0x70e757;
    ExceptionList = &local_c;
    uStack_b8 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_bc = 0x70e75d;
    FUN_00827bf0();
    uStack_b4 = (char *)0x70e76b;
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    uStack_b4 = (char *)0x70e776;
    piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
    if (piVar1 == (int *)0x0) {
      uStack_b4 = s_pSiege_L_009eb388;
      uStack_b8 = 0x70e78a;
      FUN_00401830();
      uStack_b4 = auStack_60;
      uStack_b8 = 0x70e79b;
      piStack_4 = piVar1;
      FUN_00406880();
      piStack_4 = (int *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      uStack_b4 = (char *)0x70e7b2;
      FUN_00446f10();
    }
    uStack_88 = *(undefined4 *)(param_1 + 0x14);
    uStack_80 = *(undefined4 *)(param_1 + 0x1c);
    uStack_b4 = (char *)&uStack_88;
    uStack_84 = 0;
    uStack_b8 = 0x70e7d2;
    (**(code **)(*piVar1 + 0x30))();
    uStack_b8 = 0x320001e;
    uStack_bc = 8;
    uStack_c0 = 0x70e7e4;
    uStack_c0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c4 = 0x70e7ee;
    FUN_00765c50();
    uStack_b4 = (char *)apuStack_d8;
    puStack_dc = auStack_a6 + -10;
    uStack_10 = 1;
    uStack_e0 = 0x70e80c;
    FUN_00765c50();
    puStack_dc = (undefined1 *)0x2;
    uStack_e0 = 0x70e819;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_e0 = 0x3200027;
    uStack_e4 = 8;
    puStack_e8 = (undefined1 *)0x70e82b;
    puStack_e8 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_ec = 0x70e835;
    FUN_00765c50();
    uStack_38 = 2;
    if (uStack_98 < 0x10) {
      unaff_ESI = auStack_a6 + -6;
    }
    uStack_ec = *(undefined4 *)(param_1 + 0x18);
    puStack_dc = auStack_108;
    puStack_e8 = unaff_ESI;
    FUN_00401830(s___d_DIL__s_009eb394);
    uStack_f0 = FUN_00404230(auStack_78);
    puStack_e8 = (undefined1 *)0xffffffff;
    uStack_ec = 0;
    uStack_38 = 3;
    uStack_f4 = 0x70e88a;
    FUN_00401660();
    uStack_38 = 2;
                    /* WARNING: Subroutine does not return */
    puStack_e8 = (undefined1 *)0x70e89b;
    FUN_00446f10();
  case 1:
    uStack_b4 = (char *)0x320001f;
    uStack_b8 = 8;
    uStack_bc = 0x70e8df;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70e8e9;
    FUN_00765c50();
    local_c = (void *)0x4;
    break;
  case 2:
    uStack_b4 = (char *)0x3200020;
    uStack_b8 = 8;
    uStack_bc = 0x70e90b;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70e915;
    FUN_00765c50();
    local_c = (void *)0x5;
    goto LAB_0070e920;
  case 3:
    uStack_b4 = (char *)0x3200021;
    uStack_b8 = 8;
    uStack_bc = 0x70e95b;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70e965;
    FUN_00765c50();
    local_c = (void *)0x6;
    break;
  case 4:
    uStack_b4 = (char *)0x3200022;
    uStack_b8 = 8;
    uStack_bc = 0x70e987;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70e991;
    FUN_00765c50();
    local_c = (void *)0x7;
    goto LAB_0070e920;
  case 5:
    uStack_b4 = (char *)0x3200022;
    uStack_b8 = 8;
    uStack_bc = 0x70e9b0;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70e9ba;
    FUN_00765c50();
    local_c = (void *)0x8;
    break;
  case 6:
    uStack_b4 = (char *)0x3200026;
    uStack_b8 = 8;
    uStack_bc = 0x70e9dc;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70e9e6;
    FUN_00765c50();
    local_c = (void *)0x9;
LAB_0070e920:
    apuStack_d8[0] = auStack_a6 + -6;
    puStack_dc = (undefined1 *)0x70e933;
    FUN_00765c50();
    apuStack_d8[0] = (undefined1 *)0x2;
    puStack_dc = (undefined1 *)0x70e940;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0070eb6e;
  case 7:
    uStack_b4 = (char *)0x3200023;
    uStack_b8 = 8;
    uStack_bc = 0x70ea08;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70ea12;
    FUN_00765c50();
    local_c = (void *)0xa;
    break;
  case 8:
    uStack_b4 = (char *)0x3200032;
    uStack_b8 = 8;
    uStack_bc = 0x70ead1;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70eadb;
    FUN_00765c50();
    apuStack_d8[0] = auStack_a6 + -6;
    local_c = (void *)0xd;
    puStack_dc = (undefined1 *)0x70eaf9;
    FUN_00765c50();
    apuStack_d8[0] = (undefined1 *)0x2;
    puStack_dc = (undefined1 *)0x70eb06;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_2c = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    puStack_dc = (undefined1 *)0x70eb1a;
    FUN_00446f10();
  case 9:
    uStack_b4 = (char *)0x3200024;
    uStack_b8 = 8;
    uStack_bc = 0x70ea31;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70ea3b;
    FUN_00765c50();
    apuStack_d8[0] = auStack_a6 + -6;
    local_c = (void *)0xb;
    puStack_dc = (undefined1 *)0x70ea59;
    FUN_00765c50();
    apuStack_d8[0] = (undefined1 *)0x2;
    puStack_dc = (undefined1 *)0x70ea66;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0070eb6e;
  case 10:
    uStack_b4 = (char *)0x3200025;
    uStack_b8 = 8;
    uStack_bc = 0x70ea81;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70ea8b;
    FUN_00765c50();
    local_c = (void *)0xc;
    break;
  default:
    return;
  case 0xc:
    uStack_b4 = (char *)0x3200026;
    uStack_b8 = 8;
    uStack_bc = 0x70eb2c;
    ExceptionList = &local_c;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c0 = 0x70eb39;
    FUN_00765c50();
    apuStack_d8[0] = auStack_30;
    local_c = (void *)0xe;
    puStack_dc = (undefined1 *)0x70eb5a;
    FUN_00765c50();
    apuStack_d8[0] = (undefined1 *)0x2;
    puStack_dc = (undefined1 *)0x70eb67;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0070eb6e;
  }
  apuStack_d8[0] = auStack_a6 + -6;
  puStack_dc = (undefined1 *)0x70eaa9;
  FUN_00765c50();
  apuStack_d8[0] = (undefined1 *)0x2;
  puStack_dc = (undefined1 *)0x70eab6;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_0070eb6e:
                    /* WARNING: Subroutine does not return */
  puStack_dc = (undefined1 *)0x70eb73;
  FUN_00446f10();
}


// ==== FUN_0070ebc0 @ 0x0070ebc0 ====

void FUN_0070ebc0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int unaff_retaddr;
  undefined1 auStack_c4 [20];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 ****ppppuStack_a8;
  undefined4 uStack_a4;
  undefined1 *puStack_a0;
  undefined4 uStack_9c;
  undefined4 *puStack_98;
  undefined1 auStack_94 [4];
  undefined4 ****appppuStack_90 [2];
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  void *pvStack_60;
  undefined1 auStack_5c [4];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 uStack_38;
  undefined1 *puStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f66f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (-100 < iVar1) {
    switch(iVar1) {
    case 0:
      uStack_78 = 8;
      uStack_7c = 0x70eef4;
      uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_80 = 0x70eefe;
      FUN_00765c50();
      puStack_8 = auStack_94;
      puStack_98 = &uStack_50;
      pvStack_10 = (void *)0x0;
      uStack_9c = 0x70ef1d;
      FUN_00765c50();
      puStack_98 = (undefined4 *)0x2;
      uStack_9c = 0x70ef2a;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      uStack_9c = *(undefined4 *)(unaff_retaddr + 0x14);
      puStack_a0 = (undefined1 *)0x70ef39;
      puStack_a0 = (undefined1 *)(**(code **)(*DAT_00b5a980 + 8))();
      uStack_a4 = 0x70ef3f;
      FUN_00827bf0();
      uStack_9c = 0x2bc0002;
      puStack_a0 = (undefined1 *)0x8;
      uStack_a4 = 0x70ef54;
      uStack_a4 = (**(code **)(*DAT_00b5a794 + 0xc))();
      ppppuStack_a8 = (undefined4 ****)0x70ef5e;
      FUN_00765c50();
      uStack_a4 = *(undefined4 *)(unaff_retaddr + 0x14);
      uStack_38 = 1;
      if (uStack_7c < 0x10) {
        appppuStack_90[0] = appppuStack_90;
      }
      puStack_30 = auStack_c4;
      ppppuStack_a8 = appppuStack_90[0];
      FUN_00401830(s__s___d_DIL__009eb3a0);
      uStack_ac = FUN_00404230(auStack_5c);
      uStack_a4 = 0xffffffff;
      ppppuStack_a8 = (undefined4 ****)0x0;
      uStack_38 = 2;
      uStack_b0 = 0x70efac;
      FUN_00401660();
      uStack_38 = 1;
                    /* WARNING: Subroutine does not return */
      uStack_a4 = 0x70efba;
      FUN_00446f10();
    case -0x22:
      uStack_78 = 8;
      uStack_7c = 0x70f077;
      uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_80 = 0x70f081;
      FUN_00765c50();
      pvStack_10 = (void *)0x9;
      break;
    case -0x21:
      uStack_78 = 8;
      uStack_7c = 0x70f02e;
      uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_80 = 0x70f038;
      FUN_00765c50();
      pvStack_10 = (void *)0x7;
      goto LAB_0070f040;
    case -0x20:
      uStack_78 = 8;
      uStack_7c = 0x70f008;
      uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_80 = 0x70f012;
      FUN_00765c50();
      pvStack_10 = (void *)0x4;
      break;
    default:
      goto switchD_0070ec0c_default;
    }
    goto LAB_0070f089;
  }
  if (iVar1 == -100) {
    uStack_78 = 8;
    uStack_7c = 0x70ee41;
    uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0xffffffff;
    uStack_80 = 0;
    uStack_54 = 0xf;
    uStack_58 = 0;
    uStack_88 = 0x70ee61;
    FUN_00401660();
    puStack_8 = auStack_94;
    puStack_98 = (undefined4 *)0xffffffff;
    uStack_9c = 0;
    puStack_a0 = auStack_5c + -0x10;
    uStack_7c = 0xf;
    uStack_80 = 0;
    pvStack_10 = (void *)0x12;
    appppuStack_90[0] = (undefined4 ****)((uint)appppuStack_90[0] & 0xffffff00);
    uStack_a4 = 0x70ee8e;
    FUN_00401660();
    puStack_98 = (undefined4 *)0x2;
    uStack_9c = 0x70ee9b;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_4c) {
      uStack_78 = 0x70eeb4;
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
switchD_0070ec0c_default:
    (**(code **)(*DAT_00b5ac94 + 0x7c))();
    ExceptionList = pvStack_10;
    return;
  }
  switch(iVar1) {
  case -0x138:
    uStack_78 = 8;
    uStack_7c = 0x70ec25;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ec2f;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    break;
  case -0x137:
    uStack_78 = 8;
    uStack_7c = 0x70ee18;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ee22;
    FUN_00765c50();
    pvStack_10 = (void *)0x11;
    break;
  case -0x136:
    uStack_78 = 8;
    uStack_7c = 0x70edef;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70edf9;
    FUN_00765c50();
    pvStack_10 = (void *)0x10;
    goto LAB_0070f089;
  case -0x135:
    uStack_78 = 8;
    uStack_7c = 0x70edc6;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70edd0;
    FUN_00765c50();
    pvStack_10 = (void *)0xf;
    break;
  case -0x134:
    uStack_78 = 8;
    uStack_7c = 0x70ed9d;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70eda7;
    FUN_00765c50();
    pvStack_10 = (void *)0xe;
    goto LAB_0070f089;
  case -0x133:
    piVar3 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
    piVar2 = DAT_00b5ac1c;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x18))();
      (**(code **)(*piVar2 + 0xc))();
    }
    uStack_78 = 8;
    uStack_7c = 0x70ed74;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ed7e;
    FUN_00765c50();
    pvStack_10 = (void *)0xd;
    break;
  case -0x132:
    uStack_78 = 8;
    uStack_7c = 0x70ed1b;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ed25;
    FUN_00765c50();
    pvStack_10 = (void *)0xc;
    break;
  case -0x131:
    uStack_78 = 8;
    uStack_7c = 0x70ec77;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ec81;
    FUN_00765c50();
    pvStack_10 = (void *)0x6;
    break;
  case -0x130:
    uStack_78 = 8;
    uStack_7c = 0x70ec4e;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ec58;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    goto LAB_0070f089;
  case -0x12f:
    uStack_78 = 8;
    uStack_7c = 0x70ecf2;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ecfc;
    FUN_00765c50();
    pvStack_10 = (void *)0xb;
    goto LAB_0070f089;
  case -0x12e:
    uStack_78 = 8;
    uStack_7c = 0x70ecc9;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ecd3;
    FUN_00765c50();
    pvStack_10 = (void *)0xa;
    break;
  case -0x12d:
    uStack_78 = 8;
    uStack_7c = 0x70eca0;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x70ecaa;
    FUN_00765c50();
    pvStack_10 = (void *)0x8;
LAB_0070f089:
    puStack_8 = auStack_94;
    puStack_98 = &uStack_50;
    uStack_9c = 0x70f09f;
    FUN_00765c50();
    puStack_98 = (undefined4 *)0x2;
    uStack_9c = 0x70f0ac;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0070f0ac;
  default:
    goto switchD_0070ec0c_default;
  }
LAB_0070f040:
  puStack_8 = auStack_94;
  puStack_98 = &uStack_50;
  uStack_9c = 0x70f056;
  FUN_00765c50();
  puStack_98 = (undefined4 *)0x2;
  uStack_9c = 0x70f063;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_0070f0ac:
  puStack_30 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
  uStack_9c = 0x70f0bd;
  FUN_00446f10();
}


// ==== FUN_0070f150 @ 0x0070f150 ====

void FUN_0070f150(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [4];
  undefined1 uStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  int iStack_78;
  void *pvStack_5c;
  uint uStack_48;
  void *pvStack_40;
  void *pvStack_3c;
  uint uStack_2c;
  uint uStack_28;
  undefined1 uStack_1c;
  undefined1 *puStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f691;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar2 != (int *)0x0) {
    iStack_78 = 0x70f192;
    (**(code **)(*piVar2 + 0x1c))();
    iVar1 = *piVar2;
    iStack_78 = 0x70f19f;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iStack_78 = uVar3 / 1000 + *(int *)(param_1 + 0x1c);
    (**(code **)(iVar1 + 0x20))();
    (**(code **)(*piVar2 + 0x2c))();
    iVar1 = *DAT_00b5ad1c;
    (**(code **)(*piVar2 + 0x18))();
    (**(code **)(iVar1 + 0x30))();
    puStack_14 = (undefined1 *)0x0;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_90 = 0;
    uStack_98 = 0x70f20c;
    FUN_00401660();
    uStack_1c = 1;
    puStack_14 = (undefined1 *)&uStack_a8;
    uStack_90 = 0xf;
    uStack_94 = 0;
    auStack_a4[0] = 0;
    FUN_00401660(&iStack_78,0,0xffffffff);
    uStack_94 = FUN_00404230(&pvStack_40);
    uStack_90 = 0;
    uStack_1c = 2;
    uStack_98 = 0x70f266;
    FUN_00401660();
    uStack_1c = 1;
    if (0xf < uStack_28) {
      uStack_90 = 0x70f27b;
      _free(pvStack_3c);
      return;
    }
    puStack_14 = auStack_a4;
    uStack_a8 = 0xffffffff;
    uStack_90 = 0;
    uStack_a0 = 0;
    FUN_00401660(&iStack_78,0);
    uStack_a8 = 2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < uStack_48) {
      iStack_78 = 0x70f2bd;
      _free(pvStack_5c);
      return;
    }
    if (0xf < uStack_2c) {
      iStack_78 = 0x70f2dc;
      _free(pvStack_40);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0070f300 @ 0x0070f300 ====

/* WARNING: Removing unreachable block (ram,0x0070f44f) */

void FUN_0070f300(int param_1)

{
  int *piVar1;
  undefined1 auStack_244 [36];
  void *pvStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f6bc;
  pvStack_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    ExceptionList = &pvStack_c;
    piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
    (**(code **)(*piVar1 + 0x70))();
    FUN_00401830();
    uStack_4 = 0;
    (**(code **)(*DAT_00b5acac + 0xc))();
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
    (**(code **)(*DAT_00b5ac98 + 0x54))();
    FUN_00537c20();
    (**(code **)(*DAT_00b5ac94 + 8))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
  }
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_c = (void *)0x2;
  FUN_00401660(auStack_244 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  ExceptionList = pvStack_34;
  return;
}


// ==== FUN_0070f4a0 @ 0x0070f4a0 ====

/* WARNING: Removing unreachable block (ram,0x0070f6d0) */
/* WARNING: Removing unreachable block (ram,0x0070f7ec) */
/* WARNING: Removing unreachable block (ram,0x0070f73f) */
/* WARNING: Removing unreachable block (ram,0x0070f744) */

void FUN_0070f4a0(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  void *pvStack_260;
  uint uStack_24c;
  void *pvStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  uint uStack_234;
  uint uStack_230;
  void *pvStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined1 uStack_218;
  uint uStack_214;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 uStack_1fc;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined1 auStack_1e0 [416];
  void *pvStack_40;
  undefined1 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_0098f71e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_00b5adb4 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5adb4 + 4))();
  }
  (**(code **)(*DAT_00b5ac94 + 0x5c))();
  (**(code **)(*DAT_00b5acac + 0xc))();
  pvStack_c = (void *)0x0;
  uStack_1e8 = 0xf;
  uStack_1ec = 0;
  uStack_1fc = 0;
  FUN_00401660();
  pvStack_c._0_1_ = 2;
  FUN_00537c20();
  iVar4 = iStack_4;
  pcVar2 = (char *)(iStack_4 + 0x10);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  pcVar2 = (char *)(iVar4 + 0x31);
  pvStack_c._0_1_ = 3;
  uStack_204 = 0xf;
  uStack_208 = 0;
  uStack_218 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  pvStack_c._0_1_ = 4;
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  pcVar2 = (char *)(**(code **)(*piVar3 + 0x70))();
  uStack_23c = 0xf;
  uStack_240 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  uStack_220 = 0xf;
  uStack_224 = 0;
  uStack_234 = uStack_234 & 0xffffff00;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,6);
  iVar4 = FUN_00403620();
  if (iVar4 == 0) {
    iVar4 = *DAT_00b5add0;
    (**(code **)(*DAT_00b5ae14 + 0x18))();
    cVar1 = (**(code **)(iVar4 + 0x3c))();
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ac94 + 8))();
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401740();
    uStack_18 = 7;
    FUN_00404440();
  }
  else {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401740();
    uStack_18 = 8;
    FUN_00404440();
  }
  uStack_18 = 6;
  iVar4 = FUN_00403620();
  if (iVar4 != 0) {
    (**(code **)(*DAT_00b5ac98 + 0x54))();
  }
  FUN_00401660(&pvStack_244,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_24c) {
    _free(pvStack_260);
    return;
  }
  if (0xf < uStack_230) {
    _free(pvStack_244);
    return;
  }
  uStack_230 = 0xf;
  uStack_234 = 0;
  pvStack_244 = (void *)((uint)pvStack_244 & 0xffffff00);
  if ((undefined1 *)0xf < auStack_1e0) {
    _free((void *)0x0);
    return;
  }
  if (uStack_214 < 0x10) {
    ExceptionList = pvStack_40;
    return;
  }
  _free(pvStack_228);
  return;
}


// ==== FUN_0070f890 @ 0x0070f890 ====

/* WARNING: Removing unreachable block (ram,0x0070fa4a) */
/* WARNING: Removing unreachable block (ram,0x0070faf5) */
/* WARNING: Removing unreachable block (ram,0x0070fab3) */
/* WARNING: Removing unreachable block (ram,0x0070fab8) */

void FUN_0070f890(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int unaff_retaddr;
  undefined1 auStack_2a8 [4];
  undefined1 uStack_2a4;
  undefined4 uStack_29c;
  void **ppvStack_298;
  void **ppvStack_294;
  void *apvStack_260 [3];
  undefined1 uStack_254;
  uint uStack_24c;
  void *pvStack_244;
  undefined4 uStack_240;
  uint uStack_234;
  uint uStack_230;
  void *pvStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined1 uStack_21c;
  undefined4 uStack_218;
  uint uStack_214;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined1 uStack_1fc;
  undefined1 *puStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  void *pvStack_3c;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f775;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac94 + 0x30))();
  (**(code **)(*DAT_00b5ac98 + 0x58))();
  (**(code **)(*DAT_00b5ac94 + 0x5c))();
  pcVar2 = (char *)(unaff_retaddr + 0x10);
  uStack_220 = 0xf;
  uStack_224 = 0;
  uStack_234 = uStack_234 & 0xffffff00;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  pcVar2 = (char *)(unaff_retaddr + 0x31);
  puStack_8 = (undefined1 *)0x0;
  uStack_1e8 = 0xf;
  uStack_1ec = 0;
  uStack_1fc = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  (**(code **)(*DAT_00b5acac + 0xc))();
  pvStack_c._0_1_ = 2;
  uStack_208 = 0xf;
  uStack_20c = 0;
  uStack_21c = 0;
  ppvStack_294 = (void **)0x70f98b;
  FUN_00401660();
  pvStack_c._0_1_ = 4;
  FUN_00537c20();
  uStack_240 = 0xf;
  pvStack_244 = (void *)0x0;
  uStack_254 = 0;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  ppvStack_294 = (void **)0x0;
  ppvStack_298 = (void **)0x70f9db;
  iVar3 = FUN_00403620();
  if (iVar3 == 0) {
    ppvStack_298 = (void **)(**(code **)(*DAT_00b5a794 + 0xc))();
    ppvStack_294 = (void **)0x0;
    uStack_29c = 0x70f9fe;
    FUN_00401660();
    ppvStack_294 = (void **)s_<NAME>_009eb3bc;
    ppvStack_298 = (void **)0x70fa1a;
    FUN_00401740();
    ppvStack_294 = apvStack_260 + -7;
    ppvStack_298 = apvStack_260;
    uStack_14 = 6;
    uStack_29c = 0x70fa39;
    FUN_00404440();
  }
  else {
    ppvStack_298 = (void **)(**(code **)(*DAT_00b5a794 + 0xc))();
    ppvStack_294 = (void **)0x0;
    uStack_29c = 0x70fa6a;
    FUN_00401660();
    ppvStack_294 = (void **)s_<GUILD>_009eb3c4;
    ppvStack_298 = (void **)0x70fa86;
    FUN_00401740();
    ppvStack_294 = apvStack_260 + -7;
    ppvStack_298 = apvStack_260;
    uStack_14 = 7;
    uStack_29c = 0x70faa2;
    FUN_00404440();
  }
  uStack_14 = 5;
  puStack_1f0 = auStack_2a8;
  ppvStack_294 = (void **)0x0;
  uStack_2a4 = 0;
  FUN_00401660(apvStack_260,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_230) {
    _free(pvStack_244);
    return;
  }
  uStack_230 = 0xf;
  uStack_234 = 0;
  pvStack_244 = (void *)((uint)pvStack_244 & 0xffffff00);
  if (0xf < uStack_214) {
    _free(pvStack_228);
    return;
  }
  uStack_214 = 0xf;
  uStack_218 = 0;
  pvStack_228 = (void *)((uint)pvStack_228 & 0xffffff00);
  if (uStack_24c < 0x10) {
    ExceptionList = pvStack_3c;
    return;
  }
  _free(apvStack_260[0]);
  return;
}


// ==== FUN_0070fb90 @ 0x0070fb90 ====

void FUN_0070fb90(void)

{
  char cVar1;
  int iVar2;
  undefined4 uStack_58;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 *puStack_34;
  int iStack_24;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f787;
  pvStack_c = ExceptionList;
  puStack_34 = (undefined1 *)0x2bc0037;
  uStack_38 = 8;
  uStack_3c = 0x70fbbb;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x70fbda;
  FUN_00401660();
  puStack_34 = auStack_54;
  uStack_58 = 0xffffffff;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660();
  uStack_58 = 2;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  (**(code **)(*DAT_00b5ac98 + 0x38))();
  cVar1 = (**(code **)(*DAT_00b5acac + 0x4c))();
  if (cVar1 == *(char *)(iStack_24 + 0x10)) {
    iVar2 = (**(code **)(*DAT_00b5acac + 0x48))();
    if ((iVar2 == 3) || (iVar2 = (**(code **)(*DAT_00b5acac + 0x48))(), iVar2 == 1)) {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      FUN_00401660(&uStack_58,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x2c))(2);
    }
    if (uStack_38 < 0x10) {
      ExceptionList = puStack_34;
      return;
    }
  }
  else if (uStack_38 < 0x10) {
    ExceptionList = puStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0070fce0 @ 0x0070fce0 ====

void FUN_0070fce0(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 ****ppppuVar7;
  int iVar8;
  uint uVar9;
  int unaff_retaddr;
  undefined1 *puVar10;
  undefined4 ****appppuStack_24c [4];
  undefined4 uStack_23c;
  uint uStack_238;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined1 uStack_224;
  undefined1 uStack_203;
  undefined2 uStack_1ea;
  undefined2 uStack_1e8;
  undefined2 uStack_1e6;
  undefined1 uStack_1e4;
  undefined1 local_1dc [16];
  undefined4 uStack_1cc;
  undefined2 uStack_1a0;
  undefined2 uStack_19e;
  undefined2 uStack_19c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f7a7;
  pvStack_c = ExceptionList;
  puVar10 = local_1dc;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5acac + 0xc))(puVar10);
  puStack_8 = (undefined1 *)0x0;
  iVar4 = (**(code **)(*DAT_00b5ac98 + 4))();
  piVar5 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  pcVar1 = (char *)(unaff_retaddr + 0x18);
  uStack_238 = 0xf;
  uStack_23c = 0;
  appppuStack_24c[0] = (undefined4 ****)((uint)appppuStack_24c[0] & 0xffffff00);
  pcVar6 = pcVar1;
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(pcVar1,(int)pcVar6 - (unaff_retaddr + 0x19));
  puStack_8._0_1_ = 1;
  ppppuVar7 = appppuStack_24c[0];
  if (uStack_238 < 0x10) {
    ppppuVar7 = appppuStack_24c;
  }
  iVar8 = FUN_00403620(0,uStack_1cc,ppppuVar7,uStack_23c);
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  if (0xf < uStack_238) {
    _free(appppuStack_24c[0]);
    return;
  }
  uStack_238 = 0xf;
  uStack_23c = 0;
  appppuStack_24c[0] = (undefined4 ****)((uint)appppuStack_24c[0] & 0xffffff00);
  if (((iVar8 == 0) && (iVar4 != 0)) && (piVar5 != (int *)0x0)) {
    piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
    if (piVar5 != (int *)0x0) {
      uStack_224 = 0;
      uStack_203 = 0;
      FUN_00496ed0(pcVar1);
      uStack_1ea = uStack_19e;
      uStack_1e4 = *(undefined1 *)(unaff_retaddr + 0x39);
      uStack_1e8 = uStack_1a0;
      uStack_1e6 = uStack_19c;
      iVar4 = (**(code **)(*DAT_00b5ac9c + 0xc))(pcVar1);
      if (iVar4 != 0) {
        (**(code **)(*DAT_00b5ac9c + 8))(iVar4);
      }
      iVar4 = (**(code **)(*DAT_00b5aca0 + 4))(&uStack_228);
      if (iVar4 != 0) {
        uVar3 = *(undefined4 *)(unaff_retaddr + 0x3c);
        uStack_228 = CONCAT31(CONCAT21(uStack_228._2_2_,*(undefined1 *)(unaff_retaddr + 0x39)),
                              *(undefined1 *)(unaff_retaddr + 0x40));
        uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        (**(code **)(*DAT_00b5ac98 + 0x4c))
                  (uVar3,uVar9 / 1000 + *(int *)(unaff_retaddr + 0x44),uStack_22c,uStack_228);
        (**(code **)(*piVar5 + 0xc))(1);
        (**(code **)(*DAT_00b5ac94 + 4))();
        (**(code **)(*DAT_00b5ac9c + 4))(puVar10);
        piVar5 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
        piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
        (**(code **)(*piVar5 + 0x14))(*(undefined1 *)(unaff_retaddr + 0x39));
        (**(code **)(*DAT_00b5ac94 + 0x2c))();
        (**(code **)(*DAT_00b5add0 + 0x50))();
        (**(code **)(*DAT_00b5add0 + 0x54))();
      }
    }
  }
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_00537c20();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0070ff70 @ 0x0070ff70 ====

/* WARNING: Removing unreachable block (ram,0x0071034b) */
/* WARNING: Removing unreachable block (ram,0x0071030d) */
/* WARNING: Removing unreachable block (ram,0x00710189) */

void FUN_0070ff70(int param_1)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  void *local_5c [4];
  undefined4 local_4c;
  uint local_48;
  void *pvStack_40;
  undefined1 uStack_38;
  void *pvStack_2c;
  undefined1 uStack_1c;
  uint uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098f7f7;
  pvStack_c = ExceptionList;
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = (void *)((uint)local_5c[0] & 0xffffff00);
  pcVar2 = (char *)(param_1 + 0x18);
  local_4 = 1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4._0_1_ = 2;
  if (*(char *)(param_1 + 0x39) == '\0') {
    FUN_00401740();
    FUN_00401660();
    FUN_004e6c20();
    FUN_00401740();
    iVar4 = *DAT_00b5ad1c;
    (**(code **)(*DAT_00b5ac1c + 0xc))();
    (**(code **)(iVar4 + 0x30))();
    pvStack_c._0_1_ = 3;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
    if (0xf < uStack_18) {
      _free(pvStack_2c);
      return;
    }
    FUN_004e6c20();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_1c = 4;
    FUN_00401660(local_5c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    local_4._0_1_ = 2;
    if ((void *)0xf < pvStack_2c) {
      _free(pvStack_40);
      return;
    }
  }
  local_4._0_1_ = 2;
  (**(code **)(*DAT_00b5ac94 + 0x30))();
  (**(code **)(*DAT_00b5ac98 + 0x3c))();
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
  cVar1 = (**(code **)(*piVar3 + 0x1c))();
  if (cVar1 == '\0') {
LAB_007102ea:
    if (*(char *)(param_1 + 0x39) != '\0') goto LAB_007102fc;
    (**(code **)(*DAT_00b5ac98 + 0x50))();
  }
  else {
    if (*(char *)(param_1 + 0x39) == '\0') {
      piVar3 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
      if (piVar3 == (int *)0x0) {
        FUN_0040a7d0();
        goto LAB_00710364;
      }
      (**(code **)(*piVar3 + 0xc))();
      FUN_00401830();
      local_4._0_1_ = 5;
      iVar4 = FUN_00403620();
      if (iVar4 == 0) {
        (**(code **)(*DAT_00b5ac28 + 0x54))();
        (**(code **)(*DAT_00b5a794 + 8))();
        uStack_18 = CONCAT31(uStack_18._1_3_,6);
LAB_0071027d:
        FUN_00765c50();
        (**(code **)(*DAT_00b5ad0c + 0x2c))();
        uStack_38 = 5;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
      if (cVar1 == '\0') {
        (**(code **)(*DAT_00b5ac28 + 0x54))();
        (**(code **)(*DAT_00b5a794 + 8))();
        uStack_18 = CONCAT31(uStack_18._1_3_,7);
        goto LAB_0071027d;
      }
      (**(code **)(*DAT_00b5acd4 + 4))();
      (**(code **)(*DAT_00b5ac94 + 4))();
      local_4._0_1_ = 2;
      if ((void *)0xf < pvStack_2c) {
        _free(pvStack_40);
        return;
      }
      goto LAB_007102ea;
    }
LAB_007102fc:
    (**(code **)(*DAT_00b5ac98 + 0x48))();
  }
  if (0xf < local_48) {
    _free(local_5c[0]);
    return;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = (void *)((uint)local_5c[0] & 0xffffff00);
LAB_00710364:
  FUN_004e67a0();
  ExceptionList = pvStack_c;
  return;
}


