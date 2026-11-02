// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x430000-0x43ffff

// ==== FUN_004300c0 @ 0x004300c0 ====

void FUN_004300c0(void *param_1,void *param_2,int param_3)

{
  size_t _Size;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *_Dst;
  void *pvVar5;
  undefined4 uVar6;
  int in_ECX;
  int extraout_ECX;
  uint uVar7;
  undefined8 uVar8;
  
  uVar1 = param_3 - (int)param_2 >> 2;
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xc) - iVar4 >> 2;
  }
  uVar8 = CONCAT44(uVar1,iVar2);
  if (uVar1 != 0) {
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar4 >> 2;
    }
    if (0x3fffffffU - iVar2 < uVar1) {
      uVar8 = FUN_00412e70();
      iVar4 = extraout_ECX;
    }
    uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
    uVar3 = (uint)uVar8;
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar4 >> 2;
    }
    if (uVar3 < iVar2 + uVar7) {
      if (0x3fffffff - (uVar3 >> 1) < uVar3) {
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + (uVar3 >> 1);
      }
      if (iVar4 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - iVar4 >> 2;
      }
      if (uVar3 < iVar2 + uVar7) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 2;
        }
        uVar3 = iVar4 + uVar7;
      }
      _Dst = operator_new(uVar3 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      pvVar5 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar5 = _memmove((void *)((int)pvVar5 + _Size),param_2,uVar1 * 4);
      _memmove((void *)((int)pvVar5 + uVar1 * 4),param_1,
               (*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar5 = *(void **)(in_ECX + 4);
      if (pvVar5 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)pvVar5 >> 2;
      }
      if (pvVar5 == (void *)0x0) {
        *(void **)(in_ECX + 4) = _Dst;
        *(void **)(in_ECX + 0xc) = (void *)(uVar3 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (uVar1 + iVar4) * 4);
        return;
      }
      _free(pvVar5);
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)(iVar4 - (int)param_1 >> 2) < uVar7) {
      FUN_005a6d90(param_1,iVar4,(void *)((int)param_1 + uVar7 * 4));
      pvVar5 = (void *)((int)param_2 + (*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      FUN_005a6d90(pvVar5,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_005dda80(param_2,pvVar5,param_1);
      return;
    }
    iVar2 = iVar4 + uVar7 * -4;
    uVar6 = FUN_005a6d90(iVar2,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar6;
    FUN_00822d20(param_1,iVar2,iVar4);
    FUN_005dda80(param_2,param_3,param_1);
  }
  return;
}


// ==== FUN_004302b0 @ 0x004302b0 ====

void FUN_004302b0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a190;
  local_10 = ExceptionList;
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = (param_3 - param_2) / 0xc;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    if (0x15555555U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_00412e70();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (uVar6 < iVar2 + uVar1) {
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
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_004a3750();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0xc);
      local_8 = 0;
      uVar5 = FUN_0042eab0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0042eab0(param_2,param_3,uVar5);
      FUN_0042eab0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xc;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0xc + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0xc) < uVar1) {
      FUN_0042eab0(param_1,iVar3,uVar1 * 0xc + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0xc) * 0xc;
      local_8 = 2;
      FUN_0042eab0(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0xc;
      FUN_0042ea00(param_2,iVar3,param_1,param_2);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0xc;
    uVar5 = FUN_0042eab0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_004ab780(param_1,iVar2,iVar3,param_2);
    FUN_0042ea00(param_2,param_3,param_1,param_2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00430458 @ 0x00430458 ====

void Catch_00430458(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00430560 @ 0x00430560 ====

void FUN_00430560(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  int iVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a158;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_0042f1e0(param_3,param_4,param_4);
  local_4 = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    iVar1 = in_ECX + 4;
  }
  else {
    iVar1 = *(int *)(in_ECX + 4);
  }
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - param_1;
  }
  if (param_1 != 0) {
    param_1 = param_1 - iVar1;
  }
  FUN_0042ee20(param_1,param_2,local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00430610 @ 0x00430610 ====

int FUN_00430610(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  return iVar1 + param_1 * 4;
}


// ==== FUN_00430640 @ 0x00430640 ====

void FUN_00430640(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a3f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x15555555 < param_1) {
    ExceptionList = &local_10;
    FUN_00412e70();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0xc;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0xc);
    local_8 = 0;
    FUN_0042eab0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0xc + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00430712 @ 0x00430712 ====

void Catch_00430712(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_00430730 @ 0x00430730 ====

int FUN_00430730(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)) {
      return iVar1 + param_1 * 0xc;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0042f370();
}


// ==== FUN_00430770 @ 0x00430770 ====

void FUN_00430770(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  uint extraout_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x1fffffff < param_1) {
    ExceptionList = &local_10;
    FUN_0042f5c0();
    param_1 = extraout_EDX;
  }
  if (*(int *)(in_ECX + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 3;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 8);
    local_8 = 0;
    FUN_00751a10(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 8 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043082a @ 0x0043082a ====

void Catch_0043082a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00430840 @ 0x00430840 ====

void FUN_00430840(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a410;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x15555555 < param_1) {
    ExceptionList = &local_10;
    FUN_0042f5c0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0xc;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0xc);
    local_8 = 0;
    FUN_0042eab0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0xc + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00430912 @ 0x00430912 ====

void Catch_00430912(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_00430930 @ 0x00430930 ====

void FUN_00430930(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_00430973;
    }
  }
  iVar1 = 0;
LAB_00430973:
  FUN_0042f880(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_004309a0 @ 0x004309a0 ====

void FUN_004309a0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a420;
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
      uVar1 = FUN_0042f5c0();
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


// ==== Catch@00430a46 @ 0x00430a46 ====

void Catch_00430a46(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00430a60 @ 0x00430a60 ====

void FUN_00430a60(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_004309a0(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00430ad0 @ 0x00430ad0 ====

void FUN_00430ad0(int param_1)

{
  void *_Src;
  void *_Memory;
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  _Src = *(void **)(param_1 + 4);
  if (_Src != (void *)0x0) {
    uVar5 = *(int *)(param_1 + 8) - (int)_Src >> 2;
    if (uVar5 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (uVar5 <= uVar4) {
        _memmove(_Memory,_Src,(*(int *)(param_1 + 8) - (int)_Src >> 2) * 4);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2) * 4;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 2;
      }
      if (uVar5 <= uVar4) {
        if (_Memory == (void *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
        }
        iVar2 = *(int *)(param_1 + 4) + iVar2 * 4;
        FUN_005dda80(*(int *)(param_1 + 4),iVar2,_Memory);
        uVar3 = FUN_005a6d90(iVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar3;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
      }
      cVar1 = FUN_00413070(iVar2);
      if (cVar1 == '\0') {
        return;
      }
      uVar3 = FUN_005a6d90(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar3;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00430c20 @ 0x00430c20 ====

void FUN_00430c20(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a450;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x3fffffff < uVar1) {
      uVar1 = FUN_00412e70();
    }
    pvVar2 = operator_new(uVar1 * 4);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 4 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_0042ea40(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00430cc6 @ 0x00430cc6 ====

void Catch_00430cc6(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00430ce0 @ 0x00430ce0 ====

void FUN_00430ce0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_0042f3e0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00430d30 @ 0x00430d30 ====

void FUN_00430d30(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a460;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x15555555 < uVar1) {
      uVar1 = FUN_00412e70();
    }
    pvVar2 = operator_new(uVar1 * 0xc);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0xc + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_0042eab0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00430de3 @ 0x00430de3 ====

void Catch_00430de3(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00430e00 @ 0x00430e00 ====

void FUN_00430e00(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a470;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x15555555 < uVar1) {
      uVar1 = FUN_0042f5c0();
    }
    pvVar2 = operator_new(uVar1 * 0xc);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0xc + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_0042eab0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00430eb3 @ 0x00430eb3 ====

void Catch_00430eb3(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00430ed0 @ 0x00430ed0 ====

void FUN_00430ed0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_00430930(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_00430f50 @ 0x00430f50 ====

void FUN_00430f50(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_004309a0(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00430fc0 @ 0x00430fc0 ====

undefined4 * FUN_00430fc0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x14;
    param_3 = param_3 + -5;
    *param_3 = *(undefined4 *)(param_2 + -0x14);
    FUN_00430ad0(param_2 + -0x10);
    param_2 = iVar1;
  } while (iVar1 != param_1);
  return param_3;
}


// ==== FUN_00431000 @ 0x00431000 ====

void FUN_00431000(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a480;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x9249249 < param_1) {
    ExceptionList = &local_10;
    FUN_00405d70();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x1c;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x1c);
    local_8 = 0;
    FUN_0040c120(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(int *)(in_ECX + 4) != 0) {
      FUN_00405de0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x1c + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004310fa @ 0x004310fa ====

void Catch_004310fa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_00431110 @ 0x00431110 ====

undefined4 *
FUN_00431110(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a4a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x3c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_00430a60(param_4);
    *(undefined1 *)(puVar1 + 0xe) = param_5;
    *(undefined1 *)((int)puVar1 + 0x39) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0043118e @ 0x0043118e ====

void Catch_0043118e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004311b0 @ 0x004311b0 ====

void FUN_004311b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_00430560(piVar1,*(int *)(in_ECX + 0x14) + (int)piVar2,param_1,param_2,param_2);
  return;
}


// ==== FUN_004311f0 @ 0x004311f0 ====

void FUN_004311f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      FUN_00430ad0(param_3 + 1);
      param_1 = param_1 + 5;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_00431220 @ 0x00431220 ====

undefined4 * FUN_00431220(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097a4c1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 5) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      FUN_00430c20(param_1 + 1);
    }
    param_3 = param_3 + 5;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043127e @ 0x0043127e ====

void Catch_0043127e(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (undefined4 *)(iVar2 + 8);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      iVar2 = iVar2 + 0x14;
      puVar1 = puVar1 + 5;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004312d0 @ 0x004312d0 ====

void FUN_004312d0(uint param_1,undefined1 param_2,void *param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a4d8;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x1c;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x1c;
    }
    ExceptionList = &local_c;
    FUN_004062c0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x1c)) {
        ExceptionList = &local_c;
        FUN_004061e0(&param_1,iVar2 + param_1 * 0x1c,*(int *)(in_ECX + 8));
      }
    }
  }
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_004313c0 @ 0x004313c0 ====

void FUN_004313c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097a118;
  local_c = ExceptionList;
  if (0x5d1745b < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00431110(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x38);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x38) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xe] == '\0') {
LAB_004314b9:
        *(undefined1 *)(*piVar5 + 0x38) = 1;
        *(undefined1 *)(piVar6 + 0xe) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x38) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_006c8fe0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x38) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x38) = 0;
        FUN_006c9030(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xe] == '\0') goto LAB_004314b9;
      if (piVar7 == (int *)*piVar2) {
        FUN_006c9030(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x38) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x38) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x39) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x38);
  } while( true );
}


// ==== FUN_004315a0 @ 0x004315a0 ====

void FUN_004315a0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097a501;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *param_3;
      FUN_00430c20(param_3 + 1);
    }
    param_1 = param_1 + 5;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00431600 @ 0x00431600 ====

void Catch_00431600(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (undefined4 *)(iVar2 + 8);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      iVar2 = iVar2 + 0x14;
      puVar1 = puVar1 + 5;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00431650 @ 0x00431650 ====

void FUN_00431650(undefined4 param_1)

{
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_20;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_004312d0(param_1);
  return;
}


// ==== FUN_00431680 @ 0x00431680 ====

/* WARNING: Removing unreachable block (ram,0x004316df) */

void FUN_00431680(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x39) == '\0') {
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
LAB_00431710:
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
        if (uVar5 == 0) goto LAB_00431710;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x39) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_004313c0(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_004be260();
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
    puVar6 = (undefined4 *)FUN_004313c0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_004317f0 @ 0x004317f0 ====

undefined4 *
FUN_004317f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a521;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x28);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_00430e00(param_4 + 1);
    puVar1[8] = param_4[5];
    *(undefined1 *)(puVar1 + 9) = param_5;
    *(undefined1 *)((int)puVar1 + 0x25) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0043187e @ 0x0043187e ====

void Catch_0043187e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004318a0 @ 0x004318a0 ====

void FUN_004318a0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a530;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0xccccccc < uVar1) {
      uVar1 = FUN_0042f5c0();
    }
    pvVar2 = operator_new(uVar1 * 0x14);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x14 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00431220(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00431954 @ 0x00431954 ====

void Catch_00431954(void)

{
  FUN_00413700();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00431970 @ 0x00431970 ====

int FUN_00431970(int param_1,int param_2,undefined4 param_3)

{
  FUN_004315a0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x14;
}


// ==== FUN_004319a0 @ 0x004319a0 ====

undefined4 * FUN_004319a0(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_004313c0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_004313c0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    cVar2 = FUN_0040a6d0(piVar1[2] + 0xc,param_3);
    if (cVar2 != '\0') {
      FUN_004313c0(param_1,0,*(undefined4 *)(*(int *)(in_ECX + 4) + 8),param_3);
      return param_1;
    }
  }
  else {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_004be260();
      cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
      if (cVar2 != '\0') {
        if (*(char *)(param_2[2] + 0x39) == '\0') {
          FUN_004313c0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_004313c0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
    if (cVar2 != '\0') {
      FUN_004be1c0();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
        if (cVar2 == '\0') goto LAB_00431b23;
      }
      if (*(char *)(param_2[2] + 0x39) == '\0') {
        FUN_004313c0(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_004313c0(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_00431b23:
  puVar3 = (undefined4 *)FUN_00431680(local_8,param_3);
  *param_1 = *puVar3;
  return param_1;
}


// ==== FUN_00431b50 @ 0x00431b50 ====

void FUN_00431b50(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097a118;
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
  piVar4 = (int *)FUN_004317f0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00431c49:
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
      if ((char)piVar6[9] == '\0') goto LAB_00431c49;
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


// ==== FUN_00431d30 @ 0x00431d30 ====

void FUN_00431d30(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined4 local_30;
  void *local_28;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a548;
  local_10 = ExceptionList;
  local_30 = *param_3;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x3c);
  ExceptionList = &local_10;
  FUN_00430c20(param_3 + 1);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x14;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x14;
    }
    if (0xcccccccU - iVar1 < param_2) {
      FUN_0042f5c0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x14;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0xccccccc - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x14;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_008913a0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x14);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00431220(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_004315a0(iVar2,param_2,&local_30);
      FUN_00431220(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x14);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x14;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004132c0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x14 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x14);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x14) < param_2) {
        FUN_00431220(param_1,iVar2,param_2 * 0x14 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00431970(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x14,
                     &local_30);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x14;
        local_8 = 0;
        FUN_004311f0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x14,&local_30);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x14;
        uVar4 = FUN_00431220(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00430fc0(param_1,iVar1,iVar2,iVar1);
        FUN_004311f0(param_1,param_2 * 0x14 + param_1,&local_30);
      }
    }
  }
  if (local_28 == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== Catch@00431ef8 @ 0x00431ef8 ====

void Catch_00431ef8(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004132c0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@00431fa9 @ 0x00431fa9 ====

void Catch_00431fa9(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x14;
  FUN_004132c0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00432040 @ 0x00432040 ====

int FUN_00432040(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  void *local_34;
  uint local_20;
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a570;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_0042ec70(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0x24) < 0x10) {
      iVar3 = iVar2 + 0x10;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x10);
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),iVar3,*(undefined4 *)(iVar2 + 0x20));
    if (-1 < iVar3) goto LAB_004320fb;
  }
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_4 = 0;
  uVar4 = FUN_00430f50(iVar1,local_48);
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar5 = (int *)FUN_004319a0(&param_1,iVar2,uVar4);
  iVar2 = *piVar5;
  if (local_18 != (void *)0x0) {
    _free(local_18);
    return extraout_EAX;
  }
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  if (0xf < local_20) {
    _free(local_34);
    return extraout_EAX_00;
  }
LAB_004320fb:
  ExceptionList = local_c;
  return iVar2 + 0x28;
}


// ==== FUN_00432120 @ 0x00432120 ====

void FUN_00432120(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  piVar3 = param_2;
  puVar5 = *(undefined4 **)(in_ECX + 4);
  bVar2 = true;
  if (*(char *)((int)puVar5[1] + 0x25) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *param_2 < (int)puVar5[3];
      if (bVar2) {
        puVar4 = (undefined4 *)*puVar5;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x25) == '\0');
  }
  param_2 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_00431b50(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058aca0();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_00431b50(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004321e0 @ 0x004321e0 ====

void FUN_004321e0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x14 != 0) {
      iVar1 = (param_2 - iVar1) / 0x14;
      goto LAB_00432225;
    }
  }
  iVar1 = 0;
LAB_00432225:
  FUN_00431d30(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x14;
  return;
}


// ==== FUN_00432250 @ 0x00432250 ====

undefined4 * FUN_00432250(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00431b50(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < param_2[3]) {
      FUN_00431b50(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *param_3) {
      FUN_00431b50(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    iVar2 = *param_3;
    iVar3 = param_2[3];
    iVar4 = iVar3 - iVar2;
    if (iVar2 < iVar3) {
      FUN_0058aca0();
      if (param_2[3] < iVar2) {
        if (*(char *)(param_2[2] + 0x25) == '\0') {
          FUN_00431b50(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00431b50(param_1,0,param_2,param_3);
        return param_1;
      }
      iVar3 = param_2[3];
      iVar4 = iVar3 - iVar2;
    }
    if (SBORROW4(iVar3,iVar2) != iVar4 < 0) {
      FUN_0051b6b0();
      if ((param_2 == *(int **)(in_ECX + 4)) || (iVar2 < param_2[3])) {
        if (*(char *)(param_2[2] + 0x25) == '\0') {
          FUN_00431b50(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00431b50(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar5 = (undefined4 *)FUN_00432120(local_8,param_3);
  *param_1 = *puVar5;
  return param_1;
}


// ==== FUN_004323c0 @ 0x004323c0 ====

void FUN_004323c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x14) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x14))) {
    FUN_004321e0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004315a0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x14;
  return;
}


// ==== FUN_00432450 @ 0x00432450 ====

undefined4 * FUN_00432450(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24 [2];
  void *local_1c;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a590;
  local_c = ExceptionList;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (int)puVar3[3])) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_24[0] = *param_1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00430e00(local_38);
    local_10 = local_28;
    local_4 = CONCAT31(local_4._1_3_,1);
    puVar3 = (undefined4 *)FUN_00432250(&param_1,puVar3,local_24);
    puVar3 = (undefined4 *)*puVar3;
    if (local_1c != (void *)0x0) {
      _free(local_1c);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return puVar3 + 4;
}


// ==== FUN_00432510 @ 0x00432510 ====

undefined4 *
FUN_00432510(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a5b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_004318a0(param_4 + 1);
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00432596 @ 0x00432596 ====

void Catch_00432596(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004325b0 @ 0x004325b0 ====

undefined4 * FUN_004325b0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a5c0;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_00432510(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 8));
    if (*(char *)((int)local_18 + 0x21) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_004325b0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_004325b0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00432641 @ 0x00432641 ====

void Catch_00432641(void)

{
  int unaff_EBP;
  
  FUN_004145c0(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00432660 @ 0x00432660 ====

void FUN_00432660(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097a118;
  local_c = ExceptionList;
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00432510(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00432759:
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
      if ((char)piVar6[8] == '\0') goto LAB_00432759;
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


// ==== FUN_00432840 @ 0x00432840 ====

void FUN_00432840(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_004325b0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x21) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x21);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x21);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x21);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x21);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_004328c0 @ 0x004328c0 ====

void FUN_004328c0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00432660(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00432660(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00432980 @ 0x00432980 ====

void FUN_00432980(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined1 local_8 [8];
  
  while (param_1 != param_2) {
    FUN_004328c0(local_8,param_1 + 3);
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
  return;
}


// ==== FUN_00432a00 @ 0x00432a00 ====

void FUN_00432a00(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a5d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_00432840(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@00432a71 @ 0x00432a71 ====

void Catch_00432a71(void)

{
  FUN_004146f0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00432a90 @ 0x00432a90 ====

void FUN_00432a90(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_00432a00(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00432b00 @ 0x00432b00 ====

void FUN_00432b00(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_00432a00(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00432b70 @ 0x00432b70 ====

undefined4 *
FUN_00432b70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a5f1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x38);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_00432a90(param_4);
    *(undefined1 *)(puVar1 + 0xd) = param_5;
    *(undefined1 *)((int)puVar1 + 0x35) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00432bee @ 0x00432bee ====

void Catch_00432bee(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00432c10 @ 0x00432c10 ====

void FUN_00432c10(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097a118;
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
  piVar4 = (int *)FUN_00432b70(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00432d09:
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
      if ((char)piVar6[0xd] == '\0') goto LAB_00432d09;
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


// ==== FUN_00432df0 @ 0x00432df0 ====

/* WARNING: Removing unreachable block (ram,0x00432e4f) */

void FUN_00432df0(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x35) == '\0') {
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
LAB_00432e80:
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
        if (uVar5 == 0) goto LAB_00432e80;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x35) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_00432c10(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00885cd0();
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
    puVar6 = (undefined4 *)FUN_00432c10(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00432f60 @ 0x00432f60 ====

void FUN_00432f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e4e4;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}


// ==== FUN_00432fa0 @ 0x00432fa0 ====

void FUN_00432fa0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int in_ECX;
  
  uVar2 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar2;
  iVar3 = FUN_00424dc0(uVar2);
  iVar1 = *(int *)(in_ECX + 8);
  if (*(void **)(in_ECX + 0x10) != *(void **)(in_ECX + 0x14)) {
    pvVar4 = _memmove(*(void **)(in_ECX + 0x10),*(void **)(in_ECX + 0x14),0);
    *(void **)(in_ECX + 0x14) = pvVar4;
  }
  FUN_00426510(*(undefined4 *)(in_ECX + 0x10),iVar3,iVar1 + iVar3,param_1);
  return;
}


// ==== FUN_00433000 @ 0x00433000 ====

void FUN_00433000(byte param_1)

{
  void *in_ECX;
  
  FUN_00433020();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00433020 @ 0x00433020 ====

void FUN_00433020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e4e4;
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


// ==== FUN_00433060 @ 0x00433060 ====

undefined4 FUN_00433060(void)

{
  return 3;
}


// ==== FUN_00433130 @ 0x00433130 ====

void FUN_00433130(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = param_2;
  piVar1 = param_1;
  FUN_00424a00(param_2);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x1c);
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x20);
  *param_1 = *param_1 + 4;
  uVar6 = 0;
  if (*(int *)(param_2 + 0x20) != 0) {
    param_2 = 0;
    do {
      iVar5 = *(int *)(iVar2 + 0x28);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar5 >> 4) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      puVar4 = (undefined4 *)(param_2 + iVar5);
      FUN_00424960(4);
      *(undefined4 *)(*param_1 + param_1[2]) = puVar4[3];
      *param_1 = *param_1 + 4;
      FUN_00424960(0xc);
      puVar3 = (undefined4 *)(*param_1 + param_1[2]);
      param_2 = param_2 + 0x10;
      *puVar3 = *puVar4;
      puVar3[1] = puVar4[1];
      puVar3[2] = puVar4[2];
      *param_1 = *param_1 + 0xc;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(iVar2 + 0x20));
  }
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(iVar2 + 0x34);
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(iVar2 + 0x38);
  *param_1 = *param_1 + 4;
  uVar6 = 0;
  if (*(int *)(iVar2 + 0x38) != 0) {
    param_2 = 0;
    do {
      iVar5 = *(int *)(iVar2 + 0x40);
      if ((iVar5 == 0) || ((uint)((*(int *)(iVar2 + 0x44) - iVar5) / 0x14) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      puVar3 = (undefined4 *)(iVar5 + param_2);
      FUN_00424960(4);
      *(undefined4 *)(*param_1 + param_1[2]) = puVar3[4];
      *param_1 = *param_1 + 4;
      FUN_00424960(0x10);
      puVar4 = (undefined4 *)(*param_1 + param_1[2]);
      param_2 = param_2 + 0x14;
      *puVar4 = *puVar3;
      puVar4[1] = puVar3[1];
      puVar4[2] = puVar3[2];
      puVar4[3] = puVar3[3];
      *param_1 = *param_1 + 0x10;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(iVar2 + 0x38));
  }
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(iVar2 + 0x4c);
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(iVar2 + 0x50);
  *param_1 = *param_1 + 4;
  param_2 = 0;
  if (*(int *)(iVar2 + 0x50) != 0) {
    param_1 = (int *)0x0;
    do {
      iVar5 = *(int *)(iVar2 + 0x58);
      if ((iVar5 == 0) || ((uint)((*(int *)(iVar2 + 0x5c) - iVar5) / 0x44) <= param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      puVar4 = (undefined4 *)(iVar5 + (int)param_1);
      FUN_00424960(4);
      *(undefined4 *)(*piVar1 + piVar1[2]) = puVar4[0x10];
      *piVar1 = *piVar1 + 4;
      FUN_00424960(0x40);
      param_1 = (int *)((int)param_1 + 0x44);
      puVar3 = (undefined4 *)(*piVar1 + piVar1[2]);
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
      *piVar1 = *piVar1 + 0x40;
      param_2 = param_2 + 1;
    } while (param_2 < *(uint *)(iVar2 + 0x50));
  }
  return;
}


// ==== FUN_00433380 @ 0x00433380 ====

void FUN_00433380(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *param_2;
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[1];
  *param_1 = *param_1 + 4;
  uVar5 = 0;
  if (param_2[1] != 0) {
    iVar4 = 0;
    do {
      iVar1 = param_2[3];
      if ((iVar1 == 0) || ((uint)((param_2[4] - iVar1) / 0xc) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      FUN_00424960(4);
      *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(iVar4 + iVar1);
      *param_1 = *param_1 + 4;
      FUN_00424960(8);
      iVar2 = *param_1;
      iVar3 = param_1[2];
      *(undefined4 *)(iVar2 + iVar3) = *(undefined4 *)(iVar4 + 4 + iVar1);
      *(undefined4 *)(iVar2 + 4 + iVar3) = *(undefined4 *)(iVar4 + 8 + iVar1);
      *param_1 = *param_1 + 8;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0xc;
    } while (uVar5 < (uint)param_2[1]);
  }
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = 0;
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = 0;
  *param_1 = *param_1 + 4;
  return;
}


// ==== FUN_00433480 @ 0x00433480 ====

void FUN_00433480(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_6c;
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [8];
  uint uStack_58;
  undefined1 auStack_54 [64];
  undefined1 auStack_14 [4];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a768;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar4 = FUN_00424e50(&local_6c);
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar4,0,0xffffffff);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_58) {
    _free(local_6c);
    return;
  }
  FUN_00425580(param_1 + 0x1c);
  piVar1 = (int *)(param_1 + 0x20);
  FUN_00425580(piVar1);
  FUN_004355e0(*piVar1);
  uVar5 = 0;
  if (*piVar1 != 0) {
    do {
      FUN_00427da0(auStack_64);
      FUN_00425390(auStack_64 + -0xc);
      iVar3 = *(int *)(param_1 + 0x28);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(param_1 + 0x30) - iVar3 >> 4) <=
          (uint)(*(int *)(param_1 + 0x2c) - iVar3 >> 4))) {
        FUN_00434260(*(undefined4 *)(param_1 + 0x2c),1,auStack_64 + -0xc);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2c);
        FUN_004be4a0(iVar3,1,auStack_64 + -0xc,param_1 + 0x24,uVar5);
        *(int *)(param_1 + 0x2c) = iVar3 + 0x10;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x20));
  }
  FUN_00425580(param_1 + 0x34);
  puVar2 = (uint *)(param_1 + 0x38);
  FUN_00425580(puVar2);
  FUN_004356b0(*puVar2);
  uVar5 = 0;
  if (*puVar2 != 0) {
    do {
      FUN_00427da0(auStack_60);
      FUN_00425430(auStack_64 + -0xc);
      FUN_00435c90(auStack_64 + -0xc);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar2);
  }
  FUN_00425580(param_1 + 0x4c);
  puVar2 = (uint *)(param_1 + 0x50);
  FUN_00425580(puVar2);
  FUN_004357a0(*puVar2);
  uVar5 = 0;
  if (*puVar2 != 0) {
    do {
      FUN_00427da0(auStack_14);
      FUN_004254e0(auStack_54);
      FUN_00435d20(auStack_54);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar2);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00433670 @ 0x00433670 ====

void FUN_00433670(undefined4 param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  iVar3 = param_2;
  FUN_00425580(param_2);
  puVar1 = (uint *)(iVar3 + 4);
  FUN_00425580(puVar1);
  FUN_004358a0(*puVar1);
  uVar2 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_00427da0(local_c);
      FUN_00427d00(local_8);
      FUN_00435db0(local_c);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  FUN_00425580(&param_2);
  FUN_00425580(&param_2);
  for (iVar3 = param_2; iVar3 != 0; iVar3 = iVar3 + -1) {
    FUN_00427da0(&param_2);
    FUN_00427da0(&param_2);
  }
  return;
}


// ==== FUN_00433720 @ 0x00433720 ====

void FUN_00433720(int *param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  piVar1 = param_1;
  FUN_00424960(0x68);
  puVar3 = (undefined4 *)(in_ECX + 0xc);
  puVar5 = (undefined4 *)(param_1[2] + *param_1);
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  *param_1 = *param_1 + 0x68;
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *param_1 + 4;
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x74) != 0) {
    param_1 = (int *)0x0;
    do {
      iVar2 = *(int *)(in_ECX + 0x7c);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x80) - iVar2) / 100) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      FUN_00433130(piVar1,(int)param_1 + iVar2);
      param_1 = (int *)((int)param_1 + 100);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x74));
  }
  FUN_00433380(piVar1,in_ECX + 0x88);
  return;
}


// ==== FUN_004337e0 @ 0x004337e0 ====

void FUN_004337e0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_6c;
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [8];
  uint uStack_58;
  undefined1 auStack_54 [64];
  undefined1 auStack_14 [4];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a77a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar4 = FUN_00424e50(&local_6c);
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar4,0,0xffffffff);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_58) {
    _free(local_6c);
    return;
  }
  FUN_00425580(param_1 + 0x1c);
  piVar1 = (int *)(param_1 + 0x20);
  FUN_00425580(piVar1);
  FUN_004355e0(*piVar1);
  uVar5 = 0;
  if (*piVar1 != 0) {
    do {
      FUN_00427da0(auStack_64);
      FUN_00425390(auStack_64 + -0xc);
      iVar3 = *(int *)(param_1 + 0x28);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(param_1 + 0x30) - iVar3 >> 4) <=
          (uint)(*(int *)(param_1 + 0x2c) - iVar3 >> 4))) {
        FUN_00434260(*(undefined4 *)(param_1 + 0x2c),1,auStack_64 + -0xc);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2c);
        FUN_004be4a0(iVar3,1,auStack_64 + -0xc,param_1 + 0x24,uVar5);
        *(int *)(param_1 + 0x2c) = iVar3 + 0x10;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x20));
  }
  FUN_00425580(param_1 + 0x34);
  puVar2 = (uint *)(param_1 + 0x38);
  FUN_00425580(puVar2);
  FUN_004356b0(*puVar2);
  uVar5 = 0;
  if (*puVar2 != 0) {
    do {
      FUN_00427da0(auStack_60);
      FUN_00425430(auStack_64 + -0xc);
      FUN_00435c90(auStack_64 + -0xc);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar2);
  }
  FUN_00425580(param_1 + 0x4c);
  puVar2 = (uint *)(param_1 + 0x50);
  FUN_00425580(puVar2);
  FUN_004357a0(*puVar2);
  uVar5 = 0;
  if (*puVar2 != 0) {
    do {
      FUN_00427da0(auStack_14);
      FUN_004254e0(auStack_54);
      FUN_00435d20(auStack_54);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar2);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_004339d0 @ 0x004339d0 ====

void FUN_004339d0(undefined4 param_1,float param_2)

{
  uint *puVar1;
  float *pfVar2;
  uint uVar3;
  float fVar4;
  undefined1 local_14 [8];
  undefined1 local_c [4];
  float local_8;
  float local_4;
  
  fVar4 = param_2;
  FUN_00425580(param_2);
  puVar1 = (uint *)((int)fVar4 + 4);
  FUN_00425580(puVar1);
  FUN_004358a0(*puVar1);
  uVar3 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_00427da0(local_c);
      FUN_00427da0(&param_2);
      pfVar2 = (float *)FUN_0040d600(local_14,0);
      local_8 = *pfVar2 * param_2;
      local_4 = pfVar2[1] * param_2;
      FUN_00435db0(local_c);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  FUN_00425580(&param_2);
  FUN_00425580(&param_2);
  for (fVar4 = param_2; fVar4 != 0.0; fVar4 = (float)((int)fVar4 + -1)) {
    FUN_00427da0(&param_2);
    FUN_00427da0(&param_2);
  }
  return;
}


// ==== FUN_00433ac0 @ 0x00433ac0 ====

void FUN_00433ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e50c;
  in_ECX[2] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  return;
}


// ==== FUN_00433b20 @ 0x00433b20 ====

void FUN_00433b20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e50c;
  if ((void *)in_ECX[0x25] == (void *)0x0) {
    in_ECX[0x25] = 0;
    in_ECX[0x26] = 0;
    in_ECX[0x27] = 0;
    FUN_00436000();
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[0x25]);
  return;
}


// ==== FUN_00433b70 @ 0x00433b70 ====

void FUN_00433b70(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int local_6c;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  uVar3 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_004350f0(local_64);
  *(undefined4 *)(in_ECX + 0x10) = local_60;
  *(undefined4 *)(in_ECX + 0x14) = local_5c;
  *(undefined4 *)(in_ECX + 0x1c) = local_54;
  *(undefined4 *)(in_ECX + 0x18) = local_58;
  *(undefined4 *)(in_ECX + 0x20) = local_50;
  *(undefined4 *)(in_ECX + 0x28) = local_48;
  puVar1 = (uint *)(in_ECX + 0x74);
  uVar4 = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0x20031113;
  *(undefined4 *)(in_ECX + 0x24) = local_4c;
  *(undefined4 *)(in_ECX + 0x2c) = local_44;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  FUN_00425580(puVar1);
  FUN_004364f0(*puVar1);
  if (*puVar1 != 0) {
    local_6c = 0;
    do {
      iVar2 = *(int *)(in_ECX + 0x7c);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x80) - iVar2) / 100) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      FUN_004337e0(param_1,local_6c + iVar2);
      local_6c = local_6c + 100;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  FUN_004339d0(param_1,in_ECX + 0x88);
  return;
}


// ==== FUN_00433c80 @ 0x00433c80 ====

void FUN_00433c80(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int local_8;
  
  uVar3 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00435050((int *)(in_ECX + 0xc));
  if (*(int *)(in_ECX + 0xc) == 0x20030820) {
    FUN_00424d50(0x68);
    FUN_00433b70(param_1);
    return;
  }
  puVar1 = (uint *)(in_ECX + 0x74);
  FUN_00425580(puVar1);
  FUN_004364f0(*puVar1);
  uVar4 = 0;
  if (*puVar1 != 0) {
    local_8 = 0;
    do {
      iVar2 = *(int *)(in_ECX + 0x7c);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x80) - iVar2) / 100) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_004341a0();
      }
      FUN_00433480(param_1,local_8 + iVar2);
      local_8 = local_8 + 100;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  FUN_00433670(param_1,in_ECX + 0x88);
  return;
}


// ==== FUN_00433d60 @ 0x00433d60 ====

int FUN_00433d60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 100;
}


// ==== FUN_00433d80 @ 0x00433d80 ====

void FUN_00433d80(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 5) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
    param_1[2] = param_3[2];
    param_1[3] = param_3[3];
    param_1[4] = param_3[4];
  }
  return;
}


// ==== FUN_00433dc0 @ 0x00433dc0 ====

void FUN_00433dc0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x11;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x11; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00433df0 @ 0x00433df0 ====

void FUN_00433df0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  while (param_1 != param_2) {
    param_3[-5] = param_2[-5];
    param_3[-4] = param_2[-4];
    param_3[-3] = param_2[-3];
    param_3[-2] = param_2[-2];
    param_3[-1] = param_2[-1];
    param_2 = param_2 + -5;
    param_3 = param_3 + -5;
  }
  return;
}


// ==== FUN_00433e40 @ 0x00433e40 ====

void FUN_00433e40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3 = param_3 + 4;
  }
  return;
}


// ==== FUN_00433e80 @ 0x00433e80 ====

void FUN_00433e80(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 5) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    param_3 = param_3 + 5;
  }
  return;
}


// ==== FUN_00433ed0 @ 0x00433ed0 ====

void FUN_00433ed0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x11;
    param_3 = param_3 + -0x11;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_00433f00 @ 0x00433f00 ====

void FUN_00433f00(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0x11;
    puVar1 = param_3 + 0x11;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0x11; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_00433f30 @ 0x00433f30 ====

void FUN_00433f30(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = *param_3;
        param_1[1] = param_3[1];
        param_1[2] = param_3[2];
        param_1[3] = param_3[3];
        param_1[4] = param_3[4];
      }
      param_1 = param_1 + 5;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_00433f80 @ 0x00433f80 ====

void FUN_00433f80(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 0x11;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_00433fb0 @ 0x00433fb0 ====

void FUN_00433fb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x11) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 0x11;
  }
  return;
}


// ==== FUN_00433fe0 @ 0x00433fe0 ====

void FUN_00433fe0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 5) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
    }
    param_3 = param_3 + 5;
  }
  return;
}


// ==== FUN_00434030 @ 0x00434030 ====

void FUN_00434030(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004be320(param_1,param_2,param_3);
  return;
}


// ==== FUN_00434050 @ 0x00434050 ====

void FUN_00434050(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00433fe0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00434070 @ 0x00434070 ====

void FUN_00434070(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00433fb0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00434090 @ 0x00434090 ====

int FUN_00434090(int param_1,int param_2,undefined4 param_3)

{
  FUN_004be4a0(param_1,param_2,param_3);
  return param_2 * 0x10 + param_1;
}


// ==== FUN_004340c0 @ 0x004340c0 ====

int FUN_004340c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00433f30(param_1,param_2,param_3);
  return param_1 + param_2 * 0x14;
}


// ==== FUN_004340f0 @ 0x004340f0 ====

int FUN_004340f0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00433f80(param_1,param_2,param_3);
  return param_1 + param_2 * 0x44;
}


// ==== FUN_00434120 @ 0x00434120 ====

void FUN_00434120(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x58) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  if (*(void **)(in_ECX + 0x40) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  if (*(void **)(in_ECX + 0x28) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x28));
    return;
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004341a0 @ 0x004341a0 ====

void FUN_004341a0(void)

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
  puStack_8 = &LAB_0097a628;
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


// ==== FUN_00434210 @ 0x00434210 ====

undefined4 FUN_00434210(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0xfffffff < param_1) {
    param_1 = FUN_00434db0();
  }
  pvVar1 = operator_new(param_1 * 0x10);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x10 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00434260 @ 0x00434260 ====

void FUN_00434260(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined8 uVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a640;
  local_10 = ExceptionList;
  local_24 = *param_3;
  local_20 = param_3[1];
  local_1c = param_3[2];
  local_18 = param_3[3];
  iVar6 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x30);
  if (iVar6 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xc) - iVar6 >> 4;
  }
  uVar7 = CONCAT44(iVar6,iVar2);
  if (param_2 != 0) {
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar6 >> 4;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x30);
    if (0xfffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_00434db0();
      puVar1 = local_14;
    }
    local_14 = puVar1;
    iVar6 = (int)((ulonglong)uVar7 >> 0x20);
    uVar3 = (uint)uVar7;
    if (iVar6 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar6 >> 4;
    }
    if (uVar3 < iVar2 + param_2) {
      if (0xfffffff - (uVar3 >> 1) < uVar3) {
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + (uVar3 >> 1);
      }
      if (iVar6 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - iVar6 >> 4;
      }
      if (uVar3 < iVar2 + param_2) {
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(in_ECX + 8) - iVar6 >> 4;
        }
        uVar3 = iVar6 + param_2;
      }
      pvVar4 = operator_new(uVar3 * 0x10);
      local_8 = 0;
      iVar6 = FUN_004be320(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_004be4a0(iVar6,param_2,&local_24);
      FUN_004be320(param_1,*(undefined4 *)(in_ECX + 8),iVar6 + param_2 * 0x10);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - (int)_Memory >> 4;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar3 * 0x10 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar6) * 0x10 + (int)pvVar4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    if ((uint)(iVar6 - param_1 >> 4) < param_2) {
      FUN_004be320(param_1,iVar6,param_2 * 0x10 + param_1);
      local_8 = 2;
      FUN_00434090(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 4),&local_24);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x10;
      FUN_004be040(param_1,*(int *)(in_ECX + 8) + param_2 * -0x10,&local_24);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar6 + param_2 * -0x10;
    uVar5 = FUN_004be320(iVar2,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_004be080(param_1,iVar2,iVar6,param_2 * 0x10);
    FUN_004be040(param_1,param_2 * 0x10 + param_1,&local_24);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004343dd @ 0x004343dd ====

void Catch_004343dd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004344c0 @ 0x004344c0 ====

undefined4 FUN_004344c0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0xccccccc < param_1) {
    param_1 = FUN_00434db0();
  }
  pvVar1 = operator_new(param_1 * 0x14);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x14 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00434510 @ 0x00434510 ====

void FUN_00434510(int param_1,uint param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a650;
  local_10 = ExceptionList;
  local_28 = *param_3;
  local_24 = param_3[1];
  iVar3 = *(int *)(in_ECX + 4);
  local_20 = param_3[2];
  local_1c = param_3[3];
  local_18 = param_3[4];
  local_14 = (undefined1 *)((int)register0x00000010 + -0x34);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x14;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x14;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x34);
    if (0xcccccccU - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_00434db0();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x14;
    }
    if (uVar6 < iVar2 + param_2) {
      if (0xccccccc - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x14;
      }
      if (uVar6 < iVar3 + param_2) {
        iVar3 = FUN_008913a0();
        uVar6 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar6 * 0x14);
      local_8 = 0;
      iVar3 = FUN_00433fe0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00433f30(iVar3,param_2,&local_28);
      FUN_00433fe0(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 0x14);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x14;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x14 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 0x14);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x14) < param_2) {
      FUN_00433fe0(param_1,iVar3,param_2 * 0x14 + param_1);
      local_8 = 2;
      FUN_004340c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x14,&local_28)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x14;
      FUN_00433d80(param_1,*(int *)(in_ECX + 8) + param_2 * -0x14,&local_28);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + param_2 * -0x14;
    uVar5 = FUN_00433fe0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00433df0(param_1,iVar2,iVar3,iVar2);
    FUN_00433d80(param_1,param_2 * 0x14 + param_1,&local_28);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004346d3 @ 0x004346d3 ====

void Catch_004346d3(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004347e0 @ 0x004347e0 ====

undefined4 FUN_004347e0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x3c3c3c3 < param_1) {
    param_1 = FUN_00434db0();
  }
  pvVar1 = operator_new(param_1 * 0x44);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x44 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00434840 @ 0x00434840 ====

void FUN_00434840(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_58;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a660;
  local_10 = ExceptionList;
  puVar7 = &local_58;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *param_3;
    param_3 = param_3 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x44;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x44;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -100);
    if (0x3c3c3c3U - iVar1 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -100);
      FUN_00434db0();
      uVar5 = extraout_ECX;
    }
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x44;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x3c3c3c3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0x44;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_005d0c90();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x44);
      local_8 = 0;
      iVar4 = FUN_00433fb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_00433f80(iVar4,param_2,&local_58);
      FUN_00433fb0(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x44);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x44;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x44 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar2 + (param_2 + iVar4) * 0x44);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    iVar1 = param_2 * 0x44;
    if ((uint)((iVar4 - param_1) / 0x44) < param_2) {
      FUN_00433fb0(param_1,iVar4,iVar1 + param_1);
      local_8 = 2;
      FUN_004340f0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x44,&local_58)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
      FUN_00433dc0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x44,&local_58);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar4 + param_2 * -0x44;
    uVar3 = FUN_00433fb0(iVar6,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_00433ed0(param_1,iVar6,iVar4);
    FUN_00433dc0(param_1,iVar1 + param_1,&local_58);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004349fd @ 0x004349fd ====

void Catch_004349fd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_00434b00 @ 0x00434b00 ====

void FUN_00434b00(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0097a670;
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
      FUN_00434db0();
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


// ==== Catch@00434cb2 @ 0x00434cb2 ====

void Catch_00434cb2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_00434db0 @ 0x00434db0 ====

void FUN_00434db0(void)

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
  puStack_8 = &LAB_0097a628;
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


// ==== FUN_00434e20 @ 0x00434e20 ====

void FUN_00434e20(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a680;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0xfffffff < uVar1) {
      uVar1 = FUN_00434db0();
    }
    pvVar2 = operator_new(uVar1 * 0x10);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x10 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_004be320(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00434ec4 @ 0x00434ec4 ====

void Catch_00434ec4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00434ee0 @ 0x00434ee0 ====

void FUN_00434ee0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a690;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0xccccccc < uVar1) {
      uVar1 = FUN_00434db0();
    }
    pvVar2 = operator_new(uVar1 * 0x14);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x14 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00433fe0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00434f94 @ 0x00434f94 ====

void Catch_00434f94(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00434fb0 @ 0x00434fb0 ====

void FUN_00434fb0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a6a0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x44;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_004347e0(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00433fb0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043503a @ 0x0043503a ====

void Catch_0043503a(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== __break @ 0x0043504e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00435050 @ 0x00435050 ====

void FUN_00435050(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a6b8;
  local_c = ExceptionList;
  puVar4 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  *in_ECX = *in_ECX + 0x68;
  if (*in_ECX <= in_ECX[1]) {
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_m_dwCurrent_<__m_dwTotal_0099e360,0x18);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004350f0 @ 0x004350f0 ====

void FUN_004350f0(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a6b8;
  local_c = ExceptionList;
  puVar4 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  *in_ECX = *in_ECX + 100;
  if (*in_ECX <= in_ECX[1]) {
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_m_dwCurrent_<__m_dwTotal_0099e360,0x18);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00435190 @ 0x00435190 ====

void FUN_00435190(int param_1)

{
  void *_Memory;
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 != 0) {
    uVar5 = *(int *)(param_1 + 8) - iVar3 >> 4;
    if (uVar5 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 4;
      }
      if (uVar5 <= uVar2) {
        FUN_00433e40(iVar3,*(int *)(param_1 + 8),_Memory,param_1);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4) * 0x10 + *(int *)(in_ECX + 4);
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 4;
      }
      if (uVar5 <= uVar2) {
        if (_Memory == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 4;
        }
        iVar3 = iVar3 * 0x10 + *(int *)(param_1 + 4);
        FUN_00433e40(*(int *)(param_1 + 4),iVar3,_Memory,param_1);
        uVar4 = FUN_004be320(iVar3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
      }
      cVar1 = FUN_00434210(iVar3);
      if (cVar1 == '\0') {
        return;
      }
      uVar4 = FUN_00434030(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004352e0 @ 0x004352e0 ====

void FUN_004352e0(int param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  uint uVar3;
  int iVar4;
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
    iVar4 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x14 + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x14;
      }
      if (uVar7 <= uVar3) {
        FUN_00433e80(iVar1,*(undefined4 *)(param_1 + 8),_Memory,param_1);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14) * 0x14;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x14;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_008913a0();
        iVar1 = iVar1 + iVar4 * 0x14;
        FUN_00433e80(*(undefined4 *)(param_1 + 4),iVar1,_Memory,param_1);
        uVar5 = FUN_00433fe0(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_008913a0();
      cVar2 = FUN_004344c0(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_00434050(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00435460 @ 0x00435460 ====

void FUN_00435460(int param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  uint uVar3;
  int iVar4;
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
    iVar4 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x44 + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x44;
      }
      if (uVar7 <= uVar3) {
        FUN_00433f00(iVar1,*(undefined4 *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x44) * 0x44;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x44;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_005d0c90();
        iVar1 = iVar1 + iVar4 * 0x44;
        FUN_00433f00(*(undefined4 *)(param_1 + 4),iVar1,_Memory);
        uVar5 = FUN_00433fb0(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_005d0c90();
      cVar2 = FUN_004347e0(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_00434070(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004355e0 @ 0x004355e0 ====

void FUN_004355e0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a6d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xfffffff < param_1) {
    ExceptionList = &local_10;
    param_1 = FUN_00434db0();
  }
  if (*(int *)(in_ECX + 4) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 4;
  }
  if (uVar2 < param_1) {
    pvVar1 = operator_new(param_1 * 0x10);
    local_8 = 0;
    FUN_004be320(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar1);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x10 + (int)pvVar1);
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00435697 @ 0x00435697 ====

void Catch_00435697(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004356b0 @ 0x004356b0 ====

void FUN_004356b0(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a6e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xccccccc < param_1) {
    ExceptionList = &local_10;
    FUN_00434db0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x14;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x14);
    local_8 = 0;
    FUN_00433fe0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x14 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00435784 @ 0x00435784 ====

void Catch_00435784(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_004357a0 @ 0x004357a0 ====

void FUN_004357a0(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a6f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x3c3c3c3 < param_1) {
    ExceptionList = &local_10;
    FUN_00434db0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x44;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x44);
    local_8 = 0;
    FUN_00433fb0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x44 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043587c @ 0x0043587c ====

void Catch_0043587c(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_004358a0 @ 0x004358a0 ====

void FUN_004358a0(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a700;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x15555555 < param_1) {
    ExceptionList = &local_10;
    FUN_00434db0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0xc;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0xc);
    local_8 = 0;
    FUN_0042eab0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0xc + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00435972 @ 0x00435972 ====

void Catch_00435972(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_00435990 @ 0x00435990 ====

void FUN_00435990(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x14 != 0) {
      iVar1 = (param_2 - iVar1) / 0x14;
      goto LAB_004359d5;
    }
  }
  iVar1 = 0;
LAB_004359d5:
  FUN_00434510(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x14;
  return;
}


// ==== FUN_00435a00 @ 0x00435a00 ====

void FUN_00435a00(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x44 != 0) {
      iVar1 = (param_2 - iVar1) / 0x44;
      goto LAB_00435a45;
    }
  }
  iVar1 = 0;
LAB_00435a45:
  FUN_00434840(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x44;
  return;
}


// ==== FUN_00435a70 @ 0x00435a70 ====

void FUN_00435a70(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_00435ab3;
    }
  }
  iVar1 = 0;
LAB_00435ab3:
  FUN_00434b00(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_00435ae0 @ 0x00435ae0 ====

void FUN_00435ae0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a72e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  local_4 = 0;
  FUN_00434e20(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x38);
  local_4._0_1_ = 1;
  FUN_00434ee0(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00434fb0(param_1 + 0x54);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00435b90 @ 0x00435b90 ====

int FUN_00435b90(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_1 + 0x20);
    FUN_00435190(param_1 + 0x24);
    *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_3 + 0x38) = *(undefined4 *)(param_1 + 0x38);
    FUN_004352e0(param_1 + 0x3c);
    *(undefined4 *)(param_3 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_3 + 0x50) = *(undefined4 *)(param_1 + 0x50);
    FUN_00435460(param_1 + 0x54);
    param_1 = param_1 + 100;
    param_3 = param_3 + 100;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_00435c10 @ 0x00435c10 ====

int FUN_00435c10(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -100;
    iVar2 = param_3 + -100;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -0x48) = *(undefined4 *)(param_2 + -0x48);
    *(undefined4 *)(param_3 + -0x44) = *(undefined4 *)(param_2 + -0x44);
    FUN_00435190(param_2 + -0x40);
    *(undefined4 *)(param_3 + -0x30) = *(undefined4 *)(param_2 + -0x30);
    *(undefined4 *)(param_3 + -0x2c) = *(undefined4 *)(param_2 + -0x2c);
    FUN_004352e0(param_2 + -0x28);
    *(undefined4 *)(param_3 + -0x18) = *(undefined4 *)(param_2 + -0x18);
    *(undefined4 *)(param_3 + -0x14) = *(undefined4 *)(param_2 + -0x14);
    FUN_00435460(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_00435c90 @ 0x00435c90 ====

void FUN_00435c90(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x14) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x14))) {
    FUN_00435990(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00433f30(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x14;
  return;
}


// ==== FUN_00435d20 @ 0x00435d20 ====

void FUN_00435d20(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x44) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x44))) {
    FUN_00435a00(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00433f80(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x44;
  return;
}


// ==== FUN_00435db0 @ 0x00435db0 ====

void FUN_00435db0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_00435a70(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_00435e30 @ 0x00435e30 ====

void FUN_00435e30(int param_1,int param_2,int param_3)

{
  if (param_1 != param_2) {
    do {
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 0x20);
      FUN_00435190(param_3 + 0x24);
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_3 + 0x34);
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_3 + 0x38);
      FUN_004352e0(param_3 + 0x3c);
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_3 + 0x4c);
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_3 + 0x50);
      FUN_00435460(param_3 + 0x54);
      param_1 = param_1 + 100;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_00435eb0 @ 0x00435eb0 ====

int FUN_00435eb0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097a751;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 100) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_00435ae0(param_1);
    }
    param_3 = param_3 + 100;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00435f06 @ 0x00435f06 ====

void Catch_00435f06(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 100) {
    FUN_00434120();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00435f40 @ 0x00435f40 ====

void FUN_00435f40(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097a7c1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_00435ae0(param_3);
    }
    param_1 = param_1 + 100;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00435f98 @ 0x00435f98 ====

void Catch_00435f98(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 100) {
    FUN_00434120();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00435fd0 @ 0x00435fd0 ====

void FUN_00435fd0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 100) {
    FUN_00434120();
  }
  return;
}


// ==== FUN_00436000 @ 0x00436000 ====

void FUN_00436000(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 100) {
    FUN_00434120();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00436050 @ 0x00436050 ====

void FUN_00436050(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_00435b90(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 100) {
      FUN_00434120();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004360b0 @ 0x004360b0 ====

int FUN_004360b0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00435f40(param_1,param_2,param_3);
  return param_1 + param_2 * 100;
}


// ==== FUN_004360e0 @ 0x004360e0 ====

void FUN_004360e0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 100) {
    FUN_00434120();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004360f0 @ 0x004360f0 ====

void FUN_004360f0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_80 [2];
  undefined1 auStack_7e [98];
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a7d8;
  local_10 = ExceptionList;
  local_14 = local_80 + -0xc;
  ExceptionList = &local_10;
  FUN_00435ae0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 100;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 100;
    }
    if (0x28f5c28U - iVar1 < param_2) {
      FUN_00434db0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 100;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x28f5c28 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 100;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00433d60();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 100);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00435eb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00435f40(iVar2,param_2,local_80);
      FUN_00435eb0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 100);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 100;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_00435fd0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 100 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 100);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 100) < param_2) {
        FUN_00435eb0(param_1,iVar2,param_2 * 100 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004360b0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 100,local_80)
        ;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 100;
        local_8 = 0;
        FUN_00435e30(param_1,*(int *)(in_ECX + 8) + param_2 * -100,local_80);
      }
      else {
        iVar1 = iVar2 + param_2 * -100;
        uVar4 = FUN_00435eb0(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00435c10(param_1,iVar1,iVar2,iVar1);
        FUN_00435e30(param_1,param_2 * 100 + param_1,local_80);
      }
    }
  }
  FUN_00434120();
  ExceptionList = local_10;
  return;
}


// ==== Catch@004362b5 @ 0x004362b5 ====

void Catch_004362b5(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00435fd0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@00436369 @ 0x00436369 ====

void Catch_00436369(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 100;
  FUN_00435fd0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00436400 @ 0x00436400 ====

void FUN_00436400(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a7f8;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 100;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 100;
    }
    ExceptionList = &local_c;
    FUN_004360f0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 100)) {
        ExceptionList = &local_c;
        FUN_00436050(&param_1,iVar2 + param_1 * 100,*(int *)(in_ECX + 8));
      }
    }
  }
  FUN_00434120();
  ExceptionList = local_c;
  return;
}


// ==== FUN_004364d0 @ 0x004364d0 ====

void FUN_004364d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00433b20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004364f0 @ 0x004364f0 ====

void FUN_004364f0(undefined4 param_1)

{
  undefined1 auStack_78 [4];
  undefined1 local_74;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a82e;
  local_c = ExceptionList;
  local_10 = auStack_78;
  local_60 = 0xf;
  local_64 = 0;
  local_74 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  FUN_00436400(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00436560 @ 0x00436560 ====

int FUN_00436560(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x28;
}


// ==== FUN_00436580 @ 0x00436580 ====

int FUN_00436580(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x68;
}


// ==== FUN_004365a0 @ 0x004365a0 ====

void FUN_004365a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0xe;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0xe; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_004365d0 @ 0x004365d0 ====

void FUN_004365d0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  
  fVar1 = param_2[1];
  fVar2 = param_1[1];
  fVar16 = param_2[0xb] - param_1[0xb];
  fVar14 = param_3[0xb] - param_1[0xb];
  fVar15 = param_3[10] - param_1[10];
  fVar3 = *param_2;
  fVar4 = *param_1;
  fVar5 = *param_3;
  fVar6 = *param_1;
  fVar7 = param_3[1];
  fVar8 = param_1[1];
  fVar9 = param_2[2];
  fVar10 = param_1[2];
  fVar11 = param_3[2];
  fVar12 = param_1[2];
  fVar13 = param_2[10] - param_1[10];
  fVar17 = DAT_0099d080 / (fVar14 * fVar13 - fVar16 * fVar15);
  *param_4 = (fVar14 * (fVar3 - fVar4) - fVar16 * (fVar5 - fVar6)) * fVar17;
  param_4[1] = (fVar14 * (fVar1 - fVar2) - fVar16 * (fVar7 - fVar8)) * fVar17;
  param_4[2] = (fVar14 * (fVar9 - fVar10) - fVar16 * (fVar11 - fVar12)) * fVar17;
  *param_5 = (fVar13 * (fVar5 - fVar6) - fVar15 * (fVar3 - fVar4)) * fVar17;
  param_5[1] = (fVar13 * (fVar7 - fVar8) - fVar15 * (fVar1 - fVar2)) * fVar17;
  param_5[2] = (fVar13 * (fVar11 - fVar12) - fVar15 * (fVar9 - fVar10)) * fVar17;
  return;
}


// ==== FUN_00436770 @ 0x00436770 ====

void FUN_00436770(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = param_2;
  FUN_00424a00(param_2);
  FUN_00424960(0xc);
  puVar3 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar3 = *(undefined4 *)(param_2 + 0x1c);
  puVar3[1] = *(undefined4 *)(param_2 + 0x20);
  puVar3[2] = *(undefined4 *)(param_2 + 0x24);
  *param_1 = *param_1 + 0xc;
  FUN_00424960(0xc);
  puVar3 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar3 = *(undefined4 *)(param_2 + 0x28);
  puVar3[1] = *(undefined4 *)(param_2 + 0x2c);
  puVar3[2] = *(undefined4 *)(param_2 + 0x30);
  *param_1 = *param_1 + 0xc;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x34);
  *param_1 = *param_1 + 4;
  FUN_004249c0(*(undefined4 *)(param_2 + 0x3c),*(int *)(param_2 + 0x34) * 0x28);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x48);
  *param_1 = *param_1 + 4;
  FUN_004249c0(*(undefined4 *)(param_2 + 0x50),*(int *)(param_2 + 0x48) * 2);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x5c);
  *param_1 = *param_1 + 4;
  uVar4 = 0;
  if (*(int *)(param_2 + 0x5c) != 0) {
    param_2 = 0;
    do {
      iVar1 = *(int *)(iVar2 + 100);
      if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 0x68) - iVar1) / 0x1c) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00424a00(param_2 + iVar1);
      param_2 = param_2 + 0x1c;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(iVar2 + 0x5c));
  }
  return;
}


// ==== __break @ 0x004368ae ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_004368b0 @ 0x004368b0 ====

void FUN_004368b0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2;
  FUN_00424a00(param_2);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x1c);
  *param_1 = *param_1 + 4;
  FUN_004249c0(*(undefined4 *)(param_2 + 0x24),*(int *)(param_2 + 0x1c) * 0x28);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x30);
  *param_1 = *param_1 + 4;
  uVar3 = 0;
  if (*(int *)(param_2 + 0x30) != 0) {
    param_2 = 0;
    do {
      iVar1 = *(int *)(iVar2 + 0x38);
      if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 0x3c) - iVar1) / 0x1c) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00424a00(param_2 + iVar1);
      param_2 = param_2 + 0x1c;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(iVar2 + 0x30));
  }
  return;
}


// ==== FUN_00436980 @ 0x00436980 ====

void FUN_00436980(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 *_Memory;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  undefined4 *puVar15;
  uint uVar16;
  float fVar17;
  void *pvVar18;
  float fVar19;
  float *local_90;
  uint local_8c;
  int local_88;
  uint local_84;
  int local_80;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_28;
  void *local_24;
  float fStack_20;
  float fStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a978;
  pvStack_c = ExceptionList;
  if (*(int *)(param_1 + 0x34) == 0) {
    local_84 = 0;
  }
  else {
    local_84 = (*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34)) / 0x48;
  }
  uVar13 = local_84 * 0xc;
  ExceptionList = &pvStack_c;
  _Memory = operator_new(uVar13);
  local_90 = operator_new(uVar13);
  puVar15 = _Memory;
  for (uVar11 = uVar13 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
    *(undefined1 *)puVar15 = 0;
    puVar15 = (undefined4 *)((int)puVar15 + 1);
  }
  pfVar14 = local_90;
  for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *pfVar14 = 0.0;
    pfVar14 = pfVar14 + 1;
  }
  for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
    *(undefined1 *)pfVar14 = 0;
    pfVar14 = (float *)((int)pfVar14 + 1);
  }
  local_88 = *(int *)(param_1 + 0x20);
  iVar12 = *(int *)(param_1 + 0x24);
  if (local_88 != iVar12) {
    do {
      if ((*(int *)(local_88 + 4) == 1) && (local_8c = 0, *(int *)(local_88 + 0x10) != 2)) {
        local_80 = 4;
        do {
          iVar5 = *(int *)(local_88 + 0x18);
          if ((iVar5 == 0) || ((uint)(*(int *)(local_88 + 0x1c) - iVar5 >> 1) <= local_8c)) {
LAB_004370a2:
                    /* WARNING: Subroutine does not return */
            FUN_00426d40();
          }
          uVar13 = (uint)*(ushort *)(local_80 + -4 + iVar5);
          iVar5 = *(int *)(local_88 + 0x18);
          if ((iVar5 == 0) ||
             ((((uint)(*(int *)(local_88 + 0x1c) - iVar5 >> 1) <= local_8c + 1 ||
               (uVar11 = (uint)*(ushort *)(local_80 + -2 + iVar5), iVar5 == 0)) ||
              ((uint)(*(int *)(local_88 + 0x1c) - iVar5 >> 1) <= local_8c + 2)))) goto LAB_004370a2;
          uVar16 = (uint)*(ushort *)(local_80 + iVar5);
          if (((local_84 <= uVar13) || (local_84 <= uVar11)) || (local_84 <= uVar16)) {
            FUN_00401740(s_OverIndex____s____d___0099e534,0x15);
            uVar10 = FUN_00404230(&local_28);
            local_4 = 0;
            FUN_00796d50(uVar10);
            local_4 = 0xffffffff;
            if (0xf < local_10) {
              _free(local_24);
              return;
            }
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
            break;
          }
          if ((*(int *)(param_1 + 0x34) == 0) ||
             ((uint)((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34)) / 0x48) <= uVar13))
          goto LAB_004370ad;
          pfVar14 = (float *)(*(int *)(param_1 + 0x34) + uVar13 * 0x48);
          if ((*(int *)(param_1 + 0x34) == 0) ||
             ((uint)((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34)) / 0x48) <= uVar11))
          goto LAB_004370ad;
          pfVar1 = (float *)(*(int *)(param_1 + 0x34) + uVar11 * 0x48);
          iVar5 = *(int *)(param_1 + 0x34);
          if ((iVar5 == 0) || ((uint)((*(int *)(param_1 + 0x38) - iVar5) / 0x48) <= uVar16))
          goto LAB_004370ad;
          pfVar2 = (float *)(iVar5 + uVar16 * 0x48);
          if ((((*pfVar14 != *pfVar2) || ((pfVar14[1] != pfVar2[1] || (pfVar14[2] != pfVar2[2]))))
              && ((*pfVar14 != *pfVar1 || ((pfVar14[1] != pfVar1[1] || (pfVar14[2] != pfVar1[2])))))
              ) && ((*pfVar1 != *pfVar2 || ((pfVar1[1] != pfVar2[1] || (pfVar1[2] != pfVar2[2]))))))
          {
            FUN_004365d0();
            fVar3 = (float)_Memory[uVar13 * 3 + 1];
            fVar4 = (float)_Memory[uVar13 * 3 + 2];
            _Memory[uVar13 * 3] = local_70 + (float)_Memory[uVar13 * 3];
            _Memory[uVar13 * 3 + 1] = fVar3 + local_6c;
            _Memory[uVar13 * 3 + 2] = fVar4 + local_68;
            _Memory[uVar11 * 3] = (float)_Memory[uVar11 * 3] + local_70;
            _Memory[uVar11 * 3 + 1] = (float)_Memory[uVar11 * 3 + 1] + local_6c;
            _Memory[uVar11 * 3 + 2] = (float)_Memory[uVar11 * 3 + 2] + local_68;
            fVar3 = (float)_Memory[uVar16 * 3];
            _Memory[uVar16 * 3 + 1] = local_6c + (float)_Memory[uVar16 * 3 + 1];
            _Memory[uVar16 * 3 + 2] = local_68 + (float)_Memory[uVar16 * 3 + 2];
            _Memory[uVar16 * 3] = fVar3 + local_70;
            local_90[uVar13 * 3] = local_90[uVar13 * 3] + local_64;
            local_90[uVar13 * 3 + 1] = local_60 + local_90[uVar13 * 3 + 1];
            local_90[uVar13 * 3 + 2] = local_5c + local_90[uVar13 * 3 + 2];
            local_90[uVar11 * 3] = local_90[uVar11 * 3] + local_64;
            local_90[uVar11 * 3 + 1] = local_60 + local_90[uVar11 * 3 + 1];
            local_90[uVar11 * 3 + 2] = local_5c + local_90[uVar11 * 3 + 2];
            fVar3 = local_90[uVar16 * 3 + 1];
            fVar4 = local_90[uVar16 * 3 + 2];
            local_90[uVar16 * 3] = local_90[uVar16 * 3] + local_64;
            local_90[uVar16 * 3 + 1] = local_60 + fVar3;
            local_90[uVar16 * 3 + 2] = local_5c + fVar4;
          }
          local_80 = local_80 + 2;
          local_8c = local_8c + 1;
        } while (local_8c < *(int *)(local_88 + 0x10) - 2U);
      }
      local_88 = local_88 + 0x24;
    } while (local_88 != iVar12);
  }
  if (local_84 != 0) {
    iVar12 = (int)_Memory - (int)local_90;
    local_8c = 0;
    uVar13 = 0;
    do {
      iVar5 = *(int *)(param_1 + 0x34);
      if ((iVar5 == 0) || ((uint)((*(int *)(param_1 + 0x38) - iVar5) / 0x48) <= uVar13)) {
LAB_004370ad:
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      pfVar14 = (float *)(iVar12 + (int)local_90);
      fVar3 = *pfVar14;
      fVar4 = pfVar14[1];
      fVar6 = pfVar14[2];
      fVar7 = *local_90;
      fVar17 = *(float *)(local_8c + 0x10 + iVar5) * fVar4 +
               *(float *)(local_8c + 0x14 + iVar5) * fVar6 +
               *(float *)(local_8c + 0xc + iVar5) * fVar3;
      fVar8 = local_90[1];
      fVar9 = local_90[2];
      fVar19 = fVar3 - *(float *)(local_8c + 0xc + iVar5) * fVar17;
      pvVar18 = (void *)(fVar4 - *(float *)(local_8c + 0x10 + iVar5) * fVar17);
      fVar17 = fVar6 - *(float *)(local_8c + 0x14 + iVar5) * fVar17;
      thunk_FUN_0079e1ba();
      fStack_1c = DAT_0099d0dc;
      if (0.0 <= fVar7 * (fVar6 * *(float *)(local_8c + 0x10 + iVar5) -
                         fVar4 * *(float *)(local_8c + 0x14 + iVar5)) +
                 fVar9 * (fVar4 * *(float *)(local_8c + 0xc + iVar5) -
                         fVar3 * *(float *)(local_8c + 0x10 + iVar5)) +
                 fVar8 * (fVar3 * *(float *)(local_8c + 0x14 + iVar5) -
                         fVar6 * *(float *)(local_8c + 0xc + iVar5))) {
        fStack_1c = DAT_0099d080;
      }
      local_90 = local_90 + 3;
      pfVar14 = (float *)(local_8c + 0x18 + iVar5);
      *pfVar14 = fVar19;
      pfVar14[1] = (float)pvVar18;
      pfVar14[2] = fVar17;
      uVar13 = uVar13 + 1;
      local_8c = local_8c + 0x48;
      pfVar14[3] = fStack_1c;
      local_28 = fVar19;
      local_24 = pvVar18;
      fStack_20 = fVar17;
    } while (uVar13 < local_84);
  }
  _free(_Memory);
  return;
}


// ==== FUN_004370e0 @ 0x004370e0 ====

void FUN_004370e0(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = param_2;
  FUN_00424a00(param_2);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 0x1c);
  *param_1 = *param_1 + 4;
  iVar4 = 0;
  piVar1 = (int *)(param_2 + 0x1c);
  param_2 = 0;
  if (*piVar1 != 0) {
    do {
      iVar2 = *(int *)(iVar3 + 0x24);
      if ((iVar2 == 0) || ((uint)(*(int *)(iVar3 + 0x28) - iVar2 >> 4) <= param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      iVar5 = *(int *)(iVar2 + 4 + iVar4);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (*(int *)(iVar2 + 8 + iVar4) - iVar5) / 0x1c;
      }
      FUN_00424960(4);
      *(int *)(*param_1 + param_1[2]) = iVar5;
      *param_1 = *param_1 + 4;
      FUN_004249c0(*(undefined4 *)(iVar2 + 4 + iVar4),iVar5 * 0x1c);
      param_2 = param_2 + 1;
      iVar4 = iVar4 + 0x10;
    } while (param_2 < *(uint *)(iVar3 + 0x1c));
  }
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(iVar3 + 0x30);
  *param_1 = *param_1 + 4;
  uVar6 = 0;
  if (*(int *)(iVar3 + 0x30) != 0) {
    param_2 = 0;
    do {
      iVar4 = *(int *)(iVar3 + 0x38);
      if ((iVar4 == 0) || ((uint)((*(int *)(iVar3 + 0x3c) - iVar4) / 0x1c) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00424a00(param_2 + iVar4);
      param_2 = param_2 + 0x1c;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(iVar3 + 0x30));
  }
  return;
}


// ==== FUN_00437240 @ 0x00437240 ====

void FUN_00437240(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  piVar3 = param_1;
  FUN_00424960(0xc);
  puVar4 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar4 = *param_2;
  puVar4[1] = param_2[1];
  puVar4[2] = param_2[2];
  *param_1 = *param_1 + 0xc;
  FUN_00424960(0xc);
  puVar4 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar4 = param_2[3];
  puVar4[1] = param_2[4];
  puVar4[2] = param_2[5];
  *param_1 = *param_1 + 0xc;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[6];
  *param_1 = *param_1 + 4;
  iVar5 = 0;
  param_1 = (int *)0x0;
  if (param_2[6] != 0) {
    do {
      iVar2 = param_2[8];
      if ((iVar2 == 0) || ((uint)((param_2[9] - iVar2) / 0x24) <= param_1)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_00424960(4);
      *(undefined4 *)(*piVar3 + piVar3[2]) = *(undefined4 *)(iVar5 + iVar2);
      *piVar3 = *piVar3 + 4;
      FUN_00424960(4);
      *(undefined4 *)(*piVar3 + piVar3[2]) = *(undefined4 *)(iVar5 + 4 + iVar2);
      *piVar3 = *piVar3 + 4;
      FUN_00424960(4);
      *(undefined4 *)(*piVar3 + piVar3[2]) = *(undefined4 *)(iVar5 + 8 + iVar2);
      *piVar3 = *piVar3 + 4;
      FUN_00424960(4);
      *(undefined4 *)(*piVar3 + piVar3[2]) = *(undefined4 *)(iVar5 + 0xc + iVar2);
      *piVar3 = *piVar3 + 4;
      FUN_00424960(4);
      piVar1 = (int *)(iVar5 + 0x10 + iVar2);
      *(int *)(*piVar3 + piVar3[2]) = *piVar1;
      *piVar3 = *piVar3 + 4;
      FUN_004249c0(*(undefined4 *)(iVar5 + 0x18 + iVar2),*piVar1 * 2);
      param_1 = (int *)((int)param_1 + 1);
      iVar5 = iVar5 + 0x24;
    } while (param_1 < (uint)param_2[6]);
  }
  FUN_00424960(4);
  *(undefined4 *)(*piVar3 + piVar3[2]) = param_2[0xb];
  *piVar3 = *piVar3 + 4;
  FUN_004249c0(param_2[0xd],param_2[0xb] * 0x48);
  FUN_00424960(4);
  *(undefined4 *)(*piVar3 + piVar3[2]) = param_2[0x14];
  *piVar3 = *piVar3 + 4;
  uVar6 = 0;
  if (param_2[0x14] != 0) {
    param_1 = (int *)0x0;
    do {
      iVar5 = param_2[0x16];
      if ((iVar5 == 0) || ((uint)((param_2[0x17] - iVar5) / 0x1c) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00424a00((int)param_1 + iVar5);
      param_1 = (int *)((int)param_1 + 0x1c);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)param_2[0x14]);
  }
  FUN_00424960(4);
  *(undefined4 *)(*piVar3 + piVar3[2]) = param_2[0x19];
  *piVar3 = *piVar3 + 4;
  return;
}


// ==== FUN_00437460 @ 0x00437460 ====

void FUN_00437460(int *param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  piVar1 = param_1;
  *(undefined4 *)(in_ECX + 0xc) = 0x20060303;
  FUN_00424960(0x70);
  puVar3 = (undefined4 *)(in_ECX + 0xc);
  puVar5 = (undefined4 *)(param_1[2] + *param_1);
  for (iVar2 = 0x1c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  *param_1 = *param_1 + 0x70;
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0x7c);
  *param_1 = *param_1 + 4;
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x7c) != 0) {
    param_1 = (int *)0x0;
    do {
      iVar2 = *(int *)(in_ECX + 0x84);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x88) - iVar2) / 0x70) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_00436770(piVar1,(int)param_1 + iVar2);
      param_1 = (int *)((int)param_1 + 0x70);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x7c));
  }
  FUN_00424960(4);
  *(undefined4 *)(piVar1[2] + *piVar1) = *(undefined4 *)(in_ECX + 0x90);
  *piVar1 = *piVar1 + 4;
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x90) != 0) {
    param_1 = (int *)0x0;
    do {
      iVar2 = *(int *)(in_ECX + 0x98);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x9c) - iVar2) / 0x44) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_004370e0(piVar1,(int)param_1 + iVar2);
      param_1 = (int *)((int)param_1 + 0x44);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x90));
  }
  FUN_00424960(4);
  *(undefined4 *)(piVar1[2] + *piVar1) = *(undefined4 *)(in_ECX + 0xa4);
  *piVar1 = *piVar1 + 4;
  uVar4 = 0;
  if (*(int *)(in_ECX + 0xa4) != 0) {
    param_1 = (int *)0x0;
    do {
      iVar2 = *(int *)(in_ECX + 0xac);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0xb0) - iVar2) / 0x44) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_004368b0(piVar1,(int)param_1 + iVar2);
      param_1 = (int *)((int)param_1 + 0x44);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0xa4));
  }
  FUN_00424960(4);
  *(undefined4 *)(piVar1[2] + *piVar1) = *(undefined4 *)(in_ECX + 0xb8);
  *piVar1 = *piVar1 + 4;
  uVar4 = 0;
  if (*(int *)(in_ECX + 0xb8) != 0) {
    param_1 = (int *)0x0;
    do {
      iVar2 = *(int *)(in_ECX + 0xc0);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0xc4) - iVar2) / 0x68) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_00437240(piVar1,(int)param_1 + iVar2);
      param_1 = (int *)((int)param_1 + 0x68);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0xb8));
  }
  return;
}


// ==== FUN_004376a0 @ 0x004376a0 ====

void FUN_004376a0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  void *pvStack_44;
  void *apvStack_40 [4];
  uint uStack_30;
  void *local_28 [5];
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a992;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar5 = FUN_00424e50(local_28);
  iVar4 = param_1;
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar5,0,0xffffffff);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_14) {
    _free(local_28[0]);
    return;
  }
  FUN_00425390(iVar4 + 0x1c);
  FUN_00425390(iVar4 + 0x28);
  piVar1 = (int *)(iVar4 + 0x34);
  FUN_00425580(piVar1);
  FUN_0043a540(*piVar1);
  iVar6 = FUN_00424dc0(*piVar1 * 0x28);
  iVar3 = *piVar1;
  FUN_00438930(&param_1,*(undefined4 *)(iVar4 + 0x3c),*(undefined4 *)(iVar4 + 0x40));
  FUN_00439cd0(*(undefined4 *)(iVar4 + 0x3c),iVar6,iVar6 + iVar3 * 0x28,iVar6);
  piVar1 = (int *)(iVar4 + 0x48);
  FUN_00425580(piVar1);
  FUN_004271c0(*piVar1);
  param_1 = FUN_00424dc0(*piVar1 * 2);
  iVar3 = param_1 + *piVar1 * 2;
  if (*(void **)(iVar4 + 0x50) != *(void **)(iVar4 + 0x54)) {
    iVar6 = 0;
    pvVar7 = _memmove(*(void **)(iVar4 + 0x50),*(void **)(iVar4 + 0x54),0);
    *(void **)(iVar4 + 0x54) = pvVar7;
  }
  FUN_00426fe0(*(undefined4 *)(iVar4 + 0x50),param_1,iVar3,iVar6);
  puVar2 = (uint *)(iVar4 + 0x5c);
  FUN_00425580(puVar2);
  uVar8 = 0;
  if (*puVar2 != 0) {
    do {
      FUN_00424e50(local_28 + -8);
      puStack_8 = (undefined1 *)0x1;
      FUN_00406720(local_28 + -8);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      uVar8 = uVar8 + 1;
      uStack_30 = 0xf;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    } while (uVar8 < *puVar2);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00437870 @ 0x00437870 ====

void FUN_00437870(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  void *pvStack_44;
  void *apvStack_40 [4];
  uint uStack_30;
  void *local_28 [5];
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a9ac;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar5 = FUN_00424e50(local_28);
  iVar4 = param_1;
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar5,0,0xffffffff);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_14) {
    _free(local_28[0]);
    return;
  }
  piVar1 = (int *)(iVar4 + 0x1c);
  FUN_00425580(piVar1);
  FUN_0043a540(*piVar1);
  iVar6 = FUN_00424dc0(*piVar1 * 0x28);
  iVar3 = *piVar1;
  FUN_00438930(&param_1,*(undefined4 *)(iVar4 + 0x24),*(undefined4 *)(iVar4 + 0x28));
  FUN_00439cd0(*(undefined4 *)(iVar4 + 0x24),iVar6,iVar6 + iVar3 * 0x28,iVar6);
  puVar2 = (uint *)(iVar4 + 0x30);
  FUN_00425580(puVar2);
  uVar7 = 0;
  if (*puVar2 != 0) {
    do {
      FUN_00424e50(local_28 + -8);
      puStack_8 = (undefined1 *)0x1;
      FUN_00406720(local_28 + -8);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      uVar7 = uVar7 + 1;
      uStack_30 = 0xf;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    } while (uVar7 < *puVar2);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_004379c0 @ 0x004379c0 ====

/* WARNING: Removing unreachable block (ram,0x00437ac9) */
/* WARNING: Removing unreachable block (ram,0x00437ad0) */
/* WARNING: Removing unreachable block (ram,0x00437ae1) */
/* WARNING: Removing unreachable block (ram,0x00437ae3) */
/* WARNING: Removing unreachable block (ram,0x00437ae5) */

void FUN_004379c0(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iStack_58;
  void *pvStack_44;
  uint uStack_30;
  void *local_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a9c6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00424e50();
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660();
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_14) {
    _free(local_28);
    return;
  }
  FUN_00425580();
  FUN_0043c090();
  uVar3 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    iStack_58 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x24);
      if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x28) - iVar2 >> 4) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      iVar2 = iStack_58 + iVar2;
      FUN_00425580();
      FUN_0043a630();
      FUN_00424dc0();
      if (*(int *)(iVar2 + 4) != *(int *)(iVar2 + 8)) {
        *(int *)(iVar2 + 8) = *(int *)(iVar2 + 4);
      }
      FUN_00439f90();
      iStack_58 = iStack_58 + 0x10;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x1c));
  }
  uVar3 = 0;
  puVar1 = (uint *)(param_1 + 0x30);
  FUN_00425580();
  FUN_004312d0(*puVar1);
  if (*puVar1 != 0) {
    do {
      if ((*(int *)(param_1 + 0x38) == 0) ||
         ((uint)((*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38)) / 0x1c) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00424e50();
      puStack_8 = (undefined1 *)0x1;
      FUN_00401660();
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      uVar3 = uVar3 + 1;
      uStack_30 = 0xf;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    } while (uVar3 < *puVar1);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00437c30 @ 0x00437c30 ====

void FUN_00437c30(undefined4 param_1,int param_2,char param_3)

{
  uint *puVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint local_84;
  uint local_80;
  void *pvStack_6c;
  uint uStack_58;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a9d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00425390();
  FUN_00425390();
  puVar1 = (uint *)(param_2 + 0x18);
  FUN_00425580();
  FUN_0043c7b0(*puVar1);
  local_84 = 0;
  if (*puVar1 != 0) {
    local_80 = 0;
    do {
      iVar4 = *(int *)(param_2 + 0x20);
      if ((iVar4 == 0) || ((uint)((*(int *)(param_2 + 0x24) - iVar4) / 0x24) <= local_84)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      iVar4 = iVar4 + local_80;
      FUN_00424fa0();
      FUN_00424fa0();
      FUN_00424fa0();
      FUN_00424fa0();
      FUN_00425580();
      FUN_004271c0();
      FUN_00424dc0();
      if (*(void **)(iVar4 + 0x18) != *(void **)(iVar4 + 0x1c)) {
        pvVar2 = _memmove(*(void **)(iVar4 + 0x18),*(void **)(iVar4 + 0x1c),0);
        *(void **)(iVar4 + 0x1c) = pvVar2;
      }
      FUN_00426fe0();
      local_80 = local_80 + 0x24;
      local_84 = local_84 + 1;
    } while (local_84 < *puVar1);
  }
  puVar1 = (uint *)(param_2 + 0x2c);
  FUN_00425580();
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar4 = (**(code **)(*piVar3 + 0x1c))();
  if (*(int *)(iVar4 + 8) == 0) {
    FUN_0043a850();
    if (param_3 == '\0') {
      FUN_00424dc0();
      uVar5 = 0;
      if (*puVar1 != 0) {
        do {
          FUN_0043acd0();
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar1);
      }
    }
    else {
      FUN_00424dc0();
      uVar5 = 0;
      if (*puVar1 != 0) {
        do {
          FUN_0043acd0();
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar1);
      }
    }
  }
  else {
    FUN_0043a760();
    if (param_3 == '\0') {
      FUN_00424dc0();
      local_80 = 0;
      if (*puVar1 != 0) {
        pvStack_6c = (void *)0x0;
        do {
          FUN_0043ac40();
          local_80 = local_80 + 1;
        } while (local_80 < *puVar1);
      }
    }
    else {
      FUN_00424dc0();
      FUN_00438980();
      FUN_0043a280();
    }
  }
  FUN_00425580();
  uVar5 = 0;
  if (*(uint *)(param_2 + 0x50) != 0) {
    do {
      FUN_00424e50();
      uStack_4 = 0;
      FUN_00406720();
      uStack_4 = 0xffffffff;
      if (0xf < uStack_58) {
        _free(pvStack_6c);
        return;
      }
      uVar5 = uVar5 + 1;
      uStack_58 = 0xf;
      pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    } while (uVar5 < *(uint *)(param_2 + 0x50));
  }
  FUN_00424fa0();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_004381b0 @ 0x004381b0 ====

void FUN_004381b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e550;
  in_ECX[0x1f] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  return;
}


// ==== FUN_00438240 @ 0x00438240 ====

void FUN_00438240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e550;
  FUN_0043d6d0();
  FUN_0043cd60();
  FUN_0043db70();
  FUN_0043cd10();
  *in_ECX = &PTR_FUN_0099d408;
  return;
}


// ==== FUN_00438280 @ 0x00438280 ====

/* WARNING: Removing unreachable block (ram,0x004382fa) */

void FUN_00438280(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uStack00000004;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097aa5a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  FUN_00439440();
  if (*(uint *)(in_ECX + 0xc) < 0x20031117) {
    FUN_00401740();
    local_4 = 0;
    FUN_00403e50();
  }
  else {
    FUN_00425580();
    FUN_0043daf0();
    uVar4 = 0;
    if (*(int *)(in_ECX + 0x7c) != 0) {
      do {
        if ((*(int *)(in_ECX + 0x84) == 0) ||
           ((uint)((*(int *)(in_ECX + 0x88) - *(int *)(in_ECX + 0x84)) / 0x70) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00438a40();
        }
        FUN_004376a0();
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 0x7c));
    }
    FUN_00425580();
    FUN_0043e0e0();
    uVar4 = 0;
    if (*(int *)(in_ECX + 0x90) != 0) {
      do {
        if ((*(int *)(in_ECX + 0x98) == 0) ||
           ((uint)((*(int *)(in_ECX + 0x9c) - *(int *)(in_ECX + 0x98)) / 0x44) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00438a40();
        }
        FUN_004379c0();
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 0x90));
    }
    FUN_00425580();
    local_4 = 0xffffffff;
    FUN_0043d600();
    uVar4 = 0;
    if (*(int *)(in_ECX + 0xa4) != 0) {
      do {
        if ((*(int *)(in_ECX + 0xac) == 0) ||
           ((uint)((*(int *)(in_ECX + 0xb0) - *(int *)(in_ECX + 0xac)) / 0x44) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00438a40();
        }
        FUN_00437870();
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 0xa4));
    }
    FUN_00425580();
    local_4 = 0xffffffff;
    FUN_0043dbc0(*(int *)(in_ECX + 0xb8));
    uStack00000004 = 0;
    if (*(int *)(in_ECX + 0xb8) != 0) {
      do {
        if ((*(int *)(in_ECX + 0xc0) == 0) ||
           ((uint)((*(int *)(in_ECX + 0xc4) - *(int *)(in_ECX + 0xc0)) / 0x68) <= uStack00000004)) {
                    /* WARNING: Subroutine does not return */
          FUN_00438a40();
        }
        if (*(int *)(in_ECX + 0xc) == 0x20060303) {
          FUN_00437c30();
        }
        else {
          FUN_00437c30();
          piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
          iVar3 = (**(code **)(*piVar2 + 0x1c))();
          if (*(int *)(iVar3 + 4) == 0) {
            FUN_00436980();
          }
        }
        uStack00000004 = uStack00000004 + 1;
      } while (uStack00000004 < *(uint *)(in_ECX + 0xb8));
      ExceptionList = local_c;
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00438610 @ 0x00438610 ====

void FUN_00438610(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0xe;
    param_3 = param_3 + -0xe;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_00438640 @ 0x00438640 ====

void FUN_00438640(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 10;
    puVar1 = param_3 + 10;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 10; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_00438670 @ 0x00438670 ====

void FUN_00438670(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 7;
    puVar1 = param_3 + 7;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 7; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_004386a0 @ 0x004386a0 ====

void FUN_004386a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0x12;
    puVar1 = param_3 + 0x12;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0x12; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_004386d0 @ 0x004386d0 ====

void FUN_004386d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0xe;
    puVar1 = param_3 + 0xe;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0xe; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_00438700 @ 0x00438700 ====

void FUN_00438700(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x12) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 0x12;
  }
  return;
}


// ==== FUN_00438730 @ 0x00438730 ====

void FUN_00438730(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 10) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 10;
  }
  return;
}


// ==== FUN_00438760 @ 0x00438760 ====

void FUN_00438760(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 7;
  }
  return;
}


// ==== FUN_00438790 @ 0x00438790 ====

void FUN_00438790(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -10;
    param_3 = param_3 + -10;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_004387c0 @ 0x004387c0 ====

void FUN_004387c0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 0x12;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004387f0 @ 0x004387f0 ====

void FUN_004387f0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 0xe;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_00438820 @ 0x00438820 ====

void FUN_00438820(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0xe) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 0xe;
  }
  return;
}


// ==== FUN_00438850 @ 0x00438850 ====

void FUN_00438850(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00438700(param_1,param_2,param_3);
  return;
}


// ==== FUN_00438870 @ 0x00438870 ====

void FUN_00438870(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00438820(param_1,param_2,param_3);
  return;
}


// ==== FUN_00438890 @ 0x00438890 ====

void FUN_00438890(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00438730(param_1,param_2,param_3);
  return;
}


// ==== FUN_004388b0 @ 0x004388b0 ====

void FUN_004388b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00438760(param_1,param_2,param_3);
  return;
}


// ==== FUN_004388d0 @ 0x004388d0 ====

int FUN_004388d0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004387c0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x48;
}


// ==== FUN_00438900 @ 0x00438900 ====

int FUN_00438900(int param_1,int param_2,undefined4 param_3)

{
  FUN_004387f0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x38;
}


// ==== FUN_00438930 @ 0x00438930 ====

void FUN_00438930(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 != param_3) {
    puVar1 = *(undefined4 **)(in_ECX + 8);
    puVar5 = param_2;
    puVar4 = param_2;
    if (param_3 != puVar1) {
      do {
        puVar2 = param_3 + 10;
        puVar5 = puVar4 + 10;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = *param_3;
          param_3 = param_3 + 1;
          puVar4 = puVar4 + 1;
        }
        param_3 = puVar2;
        puVar4 = puVar5;
      } while (puVar2 != puVar1);
    }
    *(undefined4 **)(in_ECX + 8) = puVar5;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_00438980 @ 0x00438980 ====

void FUN_00438980(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 != param_3) {
    puVar1 = *(undefined4 **)(in_ECX + 8);
    puVar5 = param_2;
    puVar4 = param_2;
    if (param_3 != puVar1) {
      do {
        puVar2 = param_3 + 0x12;
        puVar5 = puVar4 + 0x12;
        for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = *param_3;
          param_3 = param_3 + 1;
          puVar4 = puVar4 + 1;
        }
        param_3 = puVar2;
        puVar4 = puVar5;
      } while (puVar2 != puVar1);
    }
    *(undefined4 **)(in_ECX + 8) = puVar5;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004389d0 @ 0x004389d0 ====

void FUN_004389d0(void)

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
  puStack_8 = &LAB_0097a848;
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


// ==== FUN_00438a40 @ 0x00438a40 ====

void FUN_00438a40(void)

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
  puStack_8 = &LAB_0097a848;
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


// ==== FUN_00438ab0 @ 0x00438ab0 ====

undefined4 FUN_00438ab0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x6666666 < param_1) {
    param_1 = FUN_004389d0();
  }
  pvVar1 = operator_new(param_1 * 0x28);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x28 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00438b00 @ 0x00438b00 ====

undefined4 FUN_00438b00(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x9249249 < param_1) {
    param_1 = FUN_004389d0();
  }
  pvVar1 = operator_new(param_1 * 0x1c);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x1c + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00438b60 @ 0x00438b60 ====

undefined4 FUN_00438b60(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x38e38e3 < param_1) {
    param_1 = FUN_004389d0();
  }
  pvVar1 = operator_new(param_1 * 0x48);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x48 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00438bb0 @ 0x00438bb0 ====

void FUN_00438bb0(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint extraout_ECX;
  undefined4 *puVar6;
  undefined4 local_5c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a860;
  local_10 = ExceptionList;
  puVar6 = &local_5c;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x48;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x48;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0x68);
    if (0x38e38e3U - iVar1 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0x68);
      FUN_004389d0();
      uVar5 = extraout_ECX;
    }
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x48;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x38e38e3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0x48;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_00868440();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x48);
      local_8 = 0;
      iVar4 = FUN_00438700(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_004387c0(iVar4,param_2,&local_5c);
      FUN_00438700(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x48);
      iVar4 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x48;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x48 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar2 + (param_2 + iVar4) * 0x48);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)((iVar4 - param_1) / 0x48) < param_2) {
      FUN_00438700(param_1,iVar4,param_2 * 0x48 + param_1);
      local_8 = 2;
      FUN_004388d0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x48,&local_5c)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x48;
      FUN_008684d0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x48,&local_5c);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar4 + param_2 * -0x48;
    uVar3 = FUN_00438700(iVar1,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_00868660(param_1,iVar1,iVar4);
    FUN_008684d0(param_1,param_2 * 0x48 + param_1,&local_5c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00438d62 @ 0x00438d62 ====

void Catch_00438d62(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_00438e70 @ 0x00438e70 ====

undefined4 FUN_00438e70(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x4924924 < param_1) {
    param_1 = FUN_004389d0();
  }
  pvVar1 = operator_new(param_1 * 0x38);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x38 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00438ed0 @ 0x00438ed0 ====

void FUN_00438ed0(int param_1,uint param_2,undefined4 *param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint extraout_ECX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_4c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a870;
  local_10 = ExceptionList;
  puVar6 = &local_4c;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x38;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0x58);
    if (0x4924924U - iVar3 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0x58);
      FUN_004389d0();
      uVar4 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
    }
    if (uVar4 < iVar3 + param_2) {
      if (0x4924924 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
      }
      if (uVar4 < iVar3 + param_2) {
        iVar3 = FUN_00875fa0();
        uVar4 = iVar3 + param_2;
      }
      pvVar1 = operator_new(uVar4 * 0x38);
      local_8 = 0;
      iVar3 = FUN_00438820(*(undefined4 *)(in_ECX + 4),param_1,pvVar1);
      FUN_004387f0(iVar3,param_2,&local_4c);
      FUN_00438820(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 0x38);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar4 * 0x38 + (int)pvVar1);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar1 + (param_2 + iVar3) * 0x38);
        *(void **)(in_ECX + 4) = pvVar1;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x38) < param_2) {
      FUN_00438820(param_1,iVar3,param_2 * 0x38 + param_1);
      local_8 = 2;
      FUN_00438900(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x38,
                   &local_4c);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x38;
      FUN_004365a0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x38,&local_4c);
      ExceptionList = local_10;
      return;
    }
    iVar5 = iVar3 + param_2 * -0x38;
    uVar2 = FUN_00438820(iVar5,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_00438610(param_1,iVar5,iVar3);
    FUN_004365a0(param_1,param_2 * 0x38 + param_1,&local_4c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004390a5 @ 0x004390a5 ====

void Catch_004390a5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004391c0 @ 0x004391c0 ====

void FUN_004391c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a880;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x28;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00438ab0(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00438730(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043924a @ 0x0043924a ====

void Catch_0043924a(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00439260 @ 0x00439260 ====

void FUN_00439260(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a890;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00438b00(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00438760(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004392ec @ 0x004392ec ====

void Catch_004392ec(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00439300 @ 0x00439300 ====

void FUN_00439300(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a8a0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00438b60(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00438700(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043938a @ 0x0043938a ====

void Catch_0043938a(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004393a0 @ 0x004393a0 ====

void FUN_004393a0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a8b0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00438e70(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00438820(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043942c @ 0x0043942c ====

void Catch_0043942c(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00439440 @ 0x00439440 ====

void FUN_00439440(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a8c8;
  local_c = ExceptionList;
  puVar4 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  *in_ECX = *in_ECX + 0x70;
  if (*in_ECX <= in_ECX[1]) {
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_m_dwCurrent_<__m_dwTotal_0099e360,0x18);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004394e0 @ 0x004394e0 ====

void FUN_004394e0(int param_1)

{
  void *_Src;
  void *_Memory;
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  _Src = *(void **)(param_1 + 4);
  if (_Src != (void *)0x0) {
    uVar5 = *(int *)(param_1 + 8) - (int)_Src >> 1;
    if (uVar5 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 1;
      }
      if (uVar5 <= uVar4) {
        _memmove(_Memory,_Src,(*(int *)(param_1 + 8) - (int)_Src >> 1) * 2);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 1) * 2;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 1;
      }
      if (uVar5 <= uVar4) {
        if (_Memory == (void *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 1;
        }
        iVar2 = *(int *)(param_1 + 4) + iVar2 * 2;
        FUN_00426700(*(int *)(param_1 + 4),iVar2,_Memory);
        uVar3 = FUN_00426750(iVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar3;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 1;
      }
      cVar1 = FUN_004130c0(iVar2);
      if (cVar1 == '\0') {
        return;
      }
      uVar3 = FUN_00426750(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar3;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00439620 @ 0x00439620 ====

void FUN_00439620(int param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  uint uVar3;
  int iVar4;
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
    iVar4 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x28 + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x28;
      }
      if (uVar7 <= uVar3) {
        FUN_00438640(iVar1,*(undefined4 *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x28) * 0x28;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x28;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_00436560();
        iVar1 = iVar1 + iVar4 * 0x28;
        FUN_00438640(*(undefined4 *)(param_1 + 4),iVar1,_Memory);
        uVar5 = FUN_00438730(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_00436560();
      cVar2 = FUN_00438ab0(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_00438890(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00439790 @ 0x00439790 ====

void FUN_00439790(int param_1)

{
  void *_Memory;
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  
  if (in_ECX == param_1) {
    return;
  }
  if (*(int *)(param_1 + 4) != 0) {
    iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    iVar3 = iVar5 >> 0x1f;
    iVar5 = iVar5 / 0x1c + iVar3;
    uVar6 = iVar5 - iVar3;
    if (iVar5 != iVar3) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x1c;
      }
      if (uVar6 <= uVar2) {
        FUN_00438670(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c) * 0x1c;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x1c;
      }
      if (uVar6 <= uVar2) {
        iVar3 = FUN_00405820();
        iVar3 = *(int *)(param_1 + 4) + iVar3 * 0x1c;
        FUN_00438670(*(int *)(param_1 + 4),iVar3,_Memory);
        uVar4 = FUN_00438760(iVar3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar4 = FUN_00405820();
      cVar1 = FUN_00438b00(uVar4);
      if (cVar1 == '\0') {
        return;
      }
      uVar4 = FUN_004388b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00439920 @ 0x00439920 ====

void FUN_00439920(int param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  uint uVar3;
  int iVar4;
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
    iVar4 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x48 + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x48;
      }
      if (uVar7 <= uVar3) {
        FUN_004386a0(iVar1,*(undefined4 *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48) * 0x48;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x48;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_00868440();
        iVar1 = iVar1 + iVar4 * 0x48;
        FUN_004386a0(*(undefined4 *)(param_1 + 4),iVar1,_Memory);
        uVar5 = FUN_00438700(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_00868440();
      cVar2 = FUN_00438b60(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_00438850(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00439a90 @ 0x00439a90 ====

void FUN_00439a90(int param_1)

{
  void *_Memory;
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  
  if (in_ECX == param_1) {
    return;
  }
  if (*(int *)(param_1 + 4) != 0) {
    iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    iVar3 = iVar5 >> 0x1f;
    iVar5 = iVar5 / 0x38 + iVar3;
    uVar6 = iVar5 - iVar3;
    if (iVar5 != iVar3) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x38;
      }
      if (uVar6 <= uVar2) {
        FUN_004386d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38) * 0x38;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x38;
      }
      if (uVar6 <= uVar2) {
        iVar3 = FUN_00875fa0();
        iVar3 = *(int *)(param_1 + 4) + iVar3 * 0x38;
        FUN_004386d0(*(int *)(param_1 + 4),iVar3,_Memory);
        uVar4 = FUN_00438820(iVar3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar4 = FUN_00875fa0();
      cVar1 = FUN_00438e70(uVar4);
      if (cVar1 == '\0') {
        return;
      }
      uVar4 = FUN_00438870(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00439c20 @ 0x00439c20 ====

int FUN_00439c20(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00439790(param_1);
    param_1 = param_1 + 0x10;
    param_3 = param_3 + 0x10;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_00439c60 @ 0x00439c60 ====

int FUN_00439c60(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    param_2 = param_2 + -0x10;
    param_3 = param_3 + -0x10;
    FUN_00439790(param_2);
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_00439ca0 @ 0x00439ca0 ====

void FUN_00439ca0(int param_1)

{
  if (*(void **)(param_1 + 4) == (void *)0x0) {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_00439cd0 @ 0x00439cd0 ====

void FUN_00439cd0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a8e0;
  local_10 = ExceptionList;
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = (param_3 - param_2) / 0x28;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x28;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x28;
    }
    ExceptionList = &local_10;
    if (0x6666666U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_004389d0();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x28;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x6666666 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x28;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_00436560();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x28);
      local_8 = 0;
      uVar5 = FUN_00438730(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00438730(param_2,param_3,uVar5);
      FUN_00438730(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x28;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x28 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x28);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x28) < uVar1) {
      FUN_00438730(param_1,iVar3,uVar1 * 0x28 + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x28) * 0x28;
      local_8 = 2;
      FUN_00438730(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x28;
      FUN_00438640(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x28;
    uVar5 = FUN_00438730(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00438790(param_1,iVar2,iVar3);
    FUN_00438640(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00439e80 @ 0x00439e80 ====

void Catch_00439e80(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00439f90 @ 0x00439f90 ====

void FUN_00439f90(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a8f0;
  local_10 = ExceptionList;
  uVar1 = (param_3 - param_2) / 0x1c;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x1c;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x1c;
    }
    ExceptionList = &local_10;
    if (0x9249249U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_004389d0();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x1c;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x9249249 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x1c;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_00405820();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x1c);
      local_8 = 0;
      uVar5 = FUN_00438760(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00438760(param_2,param_3,uVar5);
      FUN_00438760(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x1c + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x1c);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x1c) < uVar1) {
      FUN_00438760(param_1,iVar3,uVar1 * 0x1c + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x1c) * 0x1c;
      local_8 = 2;
      FUN_00438760(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x1c;
      FUN_00438670(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x1c;
    uVar5 = FUN_00438760(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_005cf580(param_1,iVar2,iVar3);
    FUN_00438670(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043a162 @ 0x0043a162 ====

void Catch_0043a162(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0043a280 @ 0x0043a280 ====

void FUN_0043a280(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a900;
  local_10 = ExceptionList;
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = (param_3 - param_2) / 0x48;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x48;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
    }
    ExceptionList = &local_10;
    if (0x38e38e3U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_004389d0();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x38e38e3 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_00868440();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x48);
      local_8 = 0;
      uVar5 = FUN_00438700(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00438700(param_2,param_3,uVar5);
      FUN_00438700(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x48;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x48 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x48);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x48) < uVar1) {
      FUN_00438700(param_1,iVar3,uVar1 * 0x48 + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x48) * 0x48;
      local_8 = 2;
      FUN_00438700(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x48;
      FUN_004386a0(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x48;
    uVar5 = FUN_00438700(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00868660(param_1,iVar2,iVar3);
    FUN_004386a0(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043a430 @ 0x0043a430 ====

void Catch_0043a430(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0043a540 @ 0x0043a540 ====

void FUN_0043a540(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a910;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x6666666 < param_1) {
    ExceptionList = &local_10;
    FUN_004389d0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x28;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x28);
    local_8 = 0;
    FUN_00438730(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x28 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043a616 @ 0x0043a616 ====

void Catch_0043a616(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_0043a630 @ 0x0043a630 ====

void FUN_0043a630(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a920;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x9249249 < param_1) {
    ExceptionList = &local_10;
    FUN_004389d0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x1c;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x1c);
    local_8 = 0;
    FUN_00438760(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x1c + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043a714 @ 0x0043a714 ====

void Catch_0043a714(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_0043a730 @ 0x0043a730 ====

int FUN_0043a730(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 4) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_00438a40();
  }
  return param_1 * 0x10 + iVar1;
}


// ==== FUN_0043a760 @ 0x0043a760 ====

void FUN_0043a760(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x38e38e3 < param_1) {
    ExceptionList = &local_10;
    FUN_004389d0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x48;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x48);
    local_8 = 0;
    FUN_00438700(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x48 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043a836 @ 0x0043a836 ====

void Catch_0043a836(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_0043a850 @ 0x0043a850 ====

void FUN_0043a850(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a940;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x4924924 < param_1) {
    ExceptionList = &local_10;
    FUN_004389d0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x38;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x38);
    local_8 = 0;
    FUN_00438820(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x38 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043a936 @ 0x0043a936 ====

void Catch_0043a936(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_0043a950 @ 0x0043a950 ====

void FUN_0043a950(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x48 != 0) {
      iVar1 = (param_2 - iVar1) / 0x48;
      goto LAB_0043a995;
    }
  }
  iVar1 = 0;
LAB_0043a995:
  FUN_00438bb0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x48;
  return;
}


// ==== FUN_0043a9c0 @ 0x0043a9c0 ====

void FUN_0043a9c0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x38 != 0) {
      iVar1 = (param_2 - iVar1) / 0x38;
      goto LAB_0043aa09;
    }
  }
  iVar1 = 0;
LAB_0043aa09:
  FUN_00438ed0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x38;
  return;
}


// ==== FUN_0043aa40 @ 0x0043aa40 ====

undefined4 FUN_0043aa40(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0xfffffff < param_1) {
    param_1 = FUN_004389d0();
  }
  pvVar1 = operator_new(param_1 * 0x10);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x10 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_0043aa90 @ 0x0043aa90 ====

undefined4 FUN_0043aa90(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x71c71c7 < param_1) {
    param_1 = FUN_004389d0();
  }
  pvVar1 = operator_new(param_1 * 0x24);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x24 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_0043aae0 @ 0x0043aae0 ====

void FUN_0043aae0(int param_1,int param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    FUN_00439790(param_3);
  }
  return;
}


// ==== FUN_0043ab10 @ 0x0043ab10 ====

undefined4 * FUN_0043ab10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    FUN_004394e0(param_1 + 5);
    param_1 = param_1 + 9;
    param_3 = param_3 + 9;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0043ab70 @ 0x0043ab70 ====

void FUN_0043ab70(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == param_2) {
      return;
    }
    if (*(void **)(param_1 + 4) != (void *)0x0) break;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    param_1 = param_1 + 0x10;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_0043abb0 @ 0x0043abb0 ====

int FUN_0043abb0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097a961;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_00439260(param_1);
    }
    param_3 = param_3 + 0x10;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043ac06 @ 0x0043ac06 ====

void Catch_0043ac06(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
    FUN_00439ca0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043ac40 @ 0x0043ac40 ====

void FUN_0043ac40(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x48) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x48))) {
    FUN_0043a950(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004387c0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x48;
  return;
}


// ==== FUN_0043acd0 @ 0x0043acd0 ====

void FUN_0043acd0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x38) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x38))) {
    FUN_0043a9c0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004387f0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x38;
  return;
}


// ==== FUN_0043ad60 @ 0x0043ad60 ====

void FUN_0043ad60(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      param_1[4] = param_3[4];
      FUN_004394e0(param_3 + 5);
      param_1 = param_1 + 9;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0043adb0 @ 0x0043adb0 ====

void FUN_0043adb0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097aa81;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_00439260(param_3);
    }
    param_1 = param_1 + 0x10;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043ae08 @ 0x0043ae08 ====

void Catch_0043ae08(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
    FUN_00439ca0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043ae40 @ 0x0043ae40 ====

undefined4 * FUN_0043ae40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097aaa1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 9) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
      FUN_00427460(param_1 + 5);
    }
    param_3 = param_3 + 9;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043aeb6 @ 0x0043aeb6 ====

void Catch_0043aeb6(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (undefined4 *)(iVar2 + 0x18);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      iVar2 = iVar2 + 0x24;
      puVar1 = puVar1 + 9;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043af00 @ 0x0043af00 ====

void FUN_0043af00(undefined4 param_1,undefined4 param_2)

{
  FUN_0043ab70(param_1,param_2);
  return;
}


// ==== FUN_0043af20 @ 0x0043af20 ====

void FUN_0043af20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0043abb0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0043af40 @ 0x0043af40 ====

void FUN_0043af40(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097aac1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      param_1[4] = param_3[4];
      FUN_00427460(param_3 + 5);
    }
    param_1 = param_1 + 9;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043afb7 @ 0x0043afb7 ====

void Catch_0043afb7(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (undefined4 *)(iVar2 + 0x18);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      iVar2 = iVar2 + 0x24;
      puVar1 = puVar1 + 9;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043b000 @ 0x0043b000 ====

void FUN_0043b000(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 100),*(undefined4 *)(in_ECX + 0x68),in_ECX + 0x60);
    _free(*(void **)(in_ECX + 100));
    return;
  }
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  if (*(void **)(in_ECX + 0x50) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x50));
    return;
  }
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  if (*(void **)(in_ECX + 0x3c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x3c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043b090 @ 0x0043b090 ====

void FUN_0043b090(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c),in_ECX + 0x34);
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043b110 @ 0x0043b110 ====

void FUN_0043b110(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_2 != param_3) {
    uVar1 = FUN_00439c20(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_1);
    FUN_0043ab70(uVar1,*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = uVar1;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_0043b160 @ 0x0043b160 ====

void FUN_0043b160(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097aaee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  FUN_004391c0(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  local_4._0_1_ = 1;
  FUN_00427460(param_1 + 0x4c);
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  FUN_00406600(param_1 + 0x60);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043b230 @ 0x0043b230 ====

void FUN_0043b230(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ab13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  FUN_004391c0(param_1 + 0x20);
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  FUN_00406600(param_1 + 0x34);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043b2c0 @ 0x0043b2c0 ====

void FUN_0043b2c0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ab20;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0xfffffff < uVar1) {
      uVar1 = FUN_004389d0();
    }
    pvVar2 = operator_new(uVar1 * 0x10);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x10 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_0043abb0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043b364 @ 0x0043b364 ====

void Catch_0043b364(void)

{
  FUN_0043b700();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043b380 @ 0x0043b380 ====

int FUN_0043b380(int param_1,int param_2,undefined4 param_3)

{
  FUN_0043adb0(param_1,param_2,param_3);
  return param_2 * 0x10 + param_1;
}


// ==== FUN_0043b3b0 @ 0x0043b3b0 ====

void FUN_0043b3b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0043ae40(param_1,param_2,param_3);
  return;
}


// ==== FUN_0043b3d0 @ 0x0043b3d0 ====

void FUN_0043b3d0(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  
  if (in_ECX == param_1) {
    return;
  }
  if (*(int *)(param_1 + 4) != 0) {
    iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    iVar1 = iVar5 >> 0x1f;
    iVar5 = iVar5 / 0x1c + iVar1;
    uVar6 = iVar5 - iVar1;
    if (iVar5 != iVar1) {
      iVar1 = *(int *)(in_ECX + 4);
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - iVar1) / 0x1c;
      }
      if (uVar6 <= uVar3) {
        uVar4 = FUN_0040c0e0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),iVar1,param_1
                            );
        FUN_00405de0(uVar4,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c) * 0x1c;
        return;
      }
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - iVar1) / 0x1c;
      }
      if (uVar6 <= uVar3) {
        iVar5 = FUN_00405820();
        iVar5 = *(int *)(param_1 + 4) + iVar5 * 0x1c;
        FUN_0040c0e0(*(int *)(param_1 + 4),iVar5,iVar1,param_1);
        uVar4 = FUN_00405e90(iVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (iVar1 != 0) {
        FUN_00406080(iVar1,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar4 = FUN_00405820();
      cVar2 = FUN_00405f30(uVar4);
      if (cVar2 == '\0') {
        return;
      }
      uVar4 = FUN_00406230(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  FUN_00406250();
  return;
}


// ==== FUN_0043b570 @ 0x0043b570 ====

void FUN_0043b570(int param_1)

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
    iVar6 = iVar6 / 0x24 + iVar2;
    uVar7 = iVar6 - iVar2;
    if (iVar6 != iVar2) {
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (uVar7 <= uVar4) {
        uVar5 = FUN_0043ab10(iVar1,*(undefined4 *)(param_1 + 8),iVar2,param_1);
        FUN_004bc690(uVar5,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x24) * 0x24;
        return;
      }
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x24;
      }
      if (uVar7 <= uVar4) {
        iVar6 = FUN_0066e7e0();
        iVar6 = iVar1 + iVar6 * 0x24;
        FUN_0043ab10(iVar1,iVar6,iVar2,iVar6);
        uVar5 = FUN_0043ae40(iVar6,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (iVar2 != 0) {
        FUN_004bc690(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar5 = FUN_0066e7e0();
      cVar3 = FUN_0043aa90(uVar5);
      if (cVar3 == '\0') {
        return;
      }
      uVar5 = FUN_0043b3b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  FUN_004bc830();
  return;
}


// ==== FUN_0043b700 @ 0x0043b700 ====

void FUN_0043b700(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_0043ab70(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043b740 @ 0x0043b740 ====

void FUN_0043b740(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x58) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x58),*(undefined4 *)(in_ECX + 0x5c),in_ECX + 0x54);
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  if (*(void **)(in_ECX + 0x44) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x44));
    return;
  }
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  if (*(void **)(in_ECX + 0x34) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    FUN_004bc830();
    return;
  }
  _free(*(void **)(in_ECX + 0x34));
  return;
}


// ==== FUN_0043b7c0 @ 0x0043b7c0 ====

void FUN_0043b7c0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined8 uVar7;
  undefined1 local_2c [2];
  undefined1 auStack_2a [2];
  void *local_28;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ab38;
  local_10 = ExceptionList;
  local_14 = local_2c + -0xc;
  ExceptionList = &local_10;
  FUN_00439260(param_3);
  iVar3 = *(int *)(in_ECX + 4);
  iVar6 = 0;
  local_8 = 0;
  if (iVar3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar3 >> 4;
  }
  uVar7 = CONCAT44(iVar3,iVar1);
  if (param_2 != 0) {
    if (iVar3 != 0) {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 4;
    }
    if (0xfffffffU - iVar6 < param_2) {
      uVar7 = FUN_004389d0();
    }
    iVar3 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 4;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0xfffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 4;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 4;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 0x10);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar4;
      iVar3 = FUN_0043abb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_0043adb0(iVar3,param_2,local_2c);
      FUN_0043abb0(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 0x10);
      iVar3 = *(int *)(in_ECX + 4);
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 4;
      }
      if (iVar3 != 0) {
        FUN_0043ab70(iVar3,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 0x10 + (int)pvVar4);
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar6) * 0x10 + (int)pvVar4);
      *(void **)(in_ECX + 4) = pvVar4;
    }
    else {
      local_1c = *(void **)(in_ECX + 8);
      if ((uint)((int)local_1c - param_1 >> 4) < param_2) {
        FUN_0043abb0(param_1,local_1c,param_2 * 0x10 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0043b380(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 4),local_2c);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x10;
        local_8 = 0;
        FUN_0043aae0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x10,local_2c);
      }
      else {
        pvVar4 = (void *)((int)local_1c + param_2 * -0x10);
        uVar5 = FUN_0043abb0(pvVar4,local_1c,local_1c);
        *(undefined4 *)(in_ECX + 8) = uVar5;
        FUN_00439c60(param_1,pvVar4,local_1c,param_1);
        FUN_0043aae0(param_1,param_2 * 0x10 + param_1,local_2c);
      }
    }
  }
  if (local_28 == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== Catch@0043b93d @ 0x0043b93d ====

void Catch_0043b93d(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0043af00(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0043b9cc @ 0x0043b9cc ====

void Catch_0043b9cc(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x10;
  FUN_0043af00(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043ba50 @ 0x0043ba50 ====

void FUN_0043ba50(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ab63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  FUN_0043b2c0(param_1 + 0x20);
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  FUN_00406600(param_1 + 0x34);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043bae0 @ 0x0043bae0 ====

void FUN_0043bae0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ab70;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x24;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x71c71c7 < uVar1) {
      uVar1 = FUN_004389d0();
    }
    pvVar2 = operator_new(uVar1 * 0x24);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x24 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_0043ae40(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043bb94 @ 0x0043bb94 ====

void Catch_0043bb94(void)

{
  FUN_004bc830();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043bbb0 @ 0x0043bbb0 ====

int FUN_0043bbb0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0043af40(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_0043bbe0 @ 0x0043bbe0 ====

void FUN_0043bbe0(int param_1)

{
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  FUN_00439620(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  FUN_004394e0(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  FUN_0043b3d0(param_1 + 0x60);
  return;
}


// ==== FUN_0043bc60 @ 0x0043bc60 ====

void FUN_0043bc60(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  FUN_0043b570(param_1 + 7);
  in_ECX[0xb] = param_1[0xb];
  FUN_00439920(param_1 + 0xc);
  FUN_00439a90(param_1 + 0x10);
  in_ECX[0x14] = param_1[0x14];
  FUN_0043b3d0(param_1 + 0x15);
  in_ECX[0x19] = param_1[0x19];
  return;
}


// ==== FUN_0043bce0 @ 0x0043bce0 ====

void FUN_0043bce0(int param_1)

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
    uVar6 = *(int *)(param_1 + 8) - iVar5 >> 4;
    if (uVar6 != 0) {
      iVar1 = *(int *)(in_ECX + 4);
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 8) - iVar1 >> 4;
      }
      if (uVar6 <= uVar3) {
        uVar4 = FUN_00439c20(iVar5,*(int *)(param_1 + 8),iVar1,param_1);
        FUN_0043ab70(uVar4,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4) * 0x10 + *(int *)(in_ECX + 4);
        return;
      }
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 0xc) - iVar1 >> 4;
      }
      if (uVar6 <= uVar3) {
        if (iVar1 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar1 >> 4;
        }
        iVar5 = iVar5 * 0x10 + *(int *)(param_1 + 4);
        FUN_00439c20(*(int *)(param_1 + 4),iVar5,iVar1,param_1);
        uVar4 = FUN_0043abb0(iVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (iVar1 != 0) {
        FUN_0043af00(iVar1,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
      }
      cVar2 = FUN_0043aa40(iVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar4 = FUN_0043af20(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  FUN_0043b700();
  return;
}


// ==== FUN_0043be40 @ 0x0043be40 ====

int FUN_0043be40(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_0043bbe0(param_1);
    param_1 = param_1 + 0x70;
    param_3 = param_3 + 0x70;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0043be80 @ 0x0043be80 ====

int FUN_0043be80(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    param_2 = param_2 + -0x70;
    param_3 = param_3 + -0x70;
    FUN_0043bbe0(param_2);
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_0043bec0 @ 0x0043bec0 ====

int FUN_0043bec0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    FUN_00439620(param_1 + 0x20);
    *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(param_1 + 0x30);
    FUN_0043b3d0(param_1 + 0x34);
    param_1 = param_1 + 0x44;
    param_3 = param_3 + 0x44;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0043bf20 @ 0x0043bf20 ====

int FUN_0043bf20(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x44;
    iVar2 = param_3 + -0x44;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -0x28) = *(undefined4 *)(param_2 + -0x28);
    FUN_00439620(param_2 + -0x24);
    *(undefined4 *)(param_3 + -0x14) = *(undefined4 *)(param_2 + -0x14);
    FUN_0043b3d0(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_0043bf80 @ 0x0043bf80 ====

int FUN_0043bf80(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_0043bc60(param_1);
    param_1 = param_1 + 0x68;
    param_3 = param_3 + 0x68;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0043bfc0 @ 0x0043bfc0 ====

int FUN_0043bfc0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    param_2 = param_2 + -0x68;
    param_3 = param_3 + -0x68;
    FUN_0043bc60(param_2);
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_0043c000 @ 0x0043c000 ====

void FUN_0043c000(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c),in_ECX + 0x34);
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(int *)(in_ECX + 0x24) != 0) {
    FUN_0043ab70(*(int *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x20);
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043c090 @ 0x0043c090 ====

void FUN_0043c090(uint param_1,undefined1 param_2,void *param_3)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ab88;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 4;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 4;
    }
    ExceptionList = &local_c;
    FUN_0043b7c0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if ((iVar2 != 0) &&
       (ExceptionList = &local_c, param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 4))) {
      ExceptionList = &local_c;
      FUN_0043b110(&param_1,param_1 * 0x10 + iVar2,*(int *)(in_ECX + 8));
    }
  }
  if (param_3 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_0043c140 @ 0x0043c140 ====

void FUN_0043c140(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_28;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097aba8;
  local_10 = ExceptionList;
  local_3c = param_3[1];
  local_40 = *param_3;
  local_38 = param_3[2];
  local_30 = param_3[4];
  local_14 = (undefined1 *)((int)register0x00000010 + -0x4c);
  local_34 = param_3[3];
  ExceptionList = &local_10;
  FUN_00427460(param_3 + 5);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (0x71c71c7U - iVar1 < param_2) {
      FUN_004389d0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x71c71c7 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_0066e7e0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x24);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_0043ae40(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0043af40(iVar2,param_2,&local_40);
      FUN_0043ae40(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x24);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x24;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004bc690(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x24 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x24);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x24) < param_2) {
        FUN_0043ae40(param_1,iVar2,param_2 * 0x24 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0043bbb0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,
                     &local_40);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x24;
        local_8 = 0;
        FUN_0043ad60(param_1,*(int *)(in_ECX + 8) + param_2 * -0x24,&local_40);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x24;
        uVar4 = FUN_0043ae40(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_004bc340(param_1,iVar1,iVar2,iVar1);
        FUN_0043ad60(param_1,param_2 * 0x24 + param_1,&local_40);
      }
    }
  }
  if (local_28 == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== Catch@0043c31c @ 0x0043c31c ====

void Catch_0043c31c(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004bc690(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0043c3cd @ 0x0043c3cd ====

void Catch_0043c3cd(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_004bc690(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043c460 @ 0x0043c460 ====

void FUN_0043c460(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097abe1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  FUN_0043bae0(param_1 + 7);
  in_ECX[0xb] = param_1[0xb];
  local_4 = 0;
  FUN_00439300(param_1 + 0xc);
  local_4._0_1_ = 1;
  FUN_004393a0(param_1 + 0x10);
  in_ECX[0x14] = param_1[0x14];
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00406600(param_1 + 0x15);
  in_ECX[0x19] = param_1[0x19];
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043c520 @ 0x0043c520 ====

void FUN_0043c520(int param_1,int param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x70) {
    FUN_0043bbe0(param_3);
  }
  return;
}


// ==== FUN_0043c550 @ 0x0043c550 ====

void FUN_0043c550(int param_1,int param_2,int param_3)

{
  if (param_1 != param_2) {
    do {
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
      FUN_00439620(param_3 + 0x20);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_3 + 0x30);
      FUN_0043b3d0(param_3 + 0x34);
      param_1 = param_1 + 0x44;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0043c5a0 @ 0x0043c5a0 ====

void FUN_0043c5a0(int param_1,int param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x68) {
    FUN_0043bc60(param_3);
  }
  return;
}


// ==== FUN_0043c5d0 @ 0x0043c5d0 ====

int FUN_0043c5d0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    FUN_0043bce0(param_1 + 0x20);
    *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(param_1 + 0x30);
    FUN_0043b3d0(param_1 + 0x34);
    param_1 = param_1 + 0x44;
    param_3 = param_3 + 0x44;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0043c630 @ 0x0043c630 ====

int FUN_0043c630(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x44;
    iVar2 = param_3 + -0x44;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -0x28) = *(undefined4 *)(param_2 + -0x28);
    FUN_0043bce0(param_2 + -0x24);
    *(undefined4 *)(param_3 + -0x14) = *(undefined4 *)(param_2 + -0x14);
    FUN_0043b3d0(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_0043c690 @ 0x0043c690 ====

int FUN_0043c690(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097ac01;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x70) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0043b160(param_1);
    }
    param_3 = param_3 + 0x70;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043c6e6 @ 0x0043c6e6 ====

void Catch_0043c6e6(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x70) {
    FUN_0043b000();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043c720 @ 0x0043c720 ====

int FUN_0043c720(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097ac21;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x44) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0043b230(param_1);
    }
    param_3 = param_3 + 0x44;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043c776 @ 0x0043c776 ====

void Catch_0043c776(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_0043b090();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043c7b0 @ 0x0043c7b0 ====

void FUN_0043c7b0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ac38;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    ExceptionList = &local_c;
    FUN_0043c140(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x24)) {
        ExceptionList = &local_c;
        FUN_004bccf0(&param_1,iVar2 + param_1 * 0x24,*(int *)(in_ECX + 8));
      }
    }
  }
  if (in_stack_00000020 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000020);
  return;
}


// ==== FUN_0043c890 @ 0x0043c890 ====

void FUN_0043c890(int param_1,int param_2,int param_3)

{
  if (param_1 != param_2) {
    do {
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
      FUN_0043bce0(param_3 + 0x20);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_3 + 0x30);
      FUN_0043b3d0(param_3 + 0x34);
      param_1 = param_1 + 0x44;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0043c8e0 @ 0x0043c8e0 ====

void FUN_0043c8e0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097ac61;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_0043b160(param_3);
    }
    param_1 = param_1 + 0x70;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043c938 @ 0x0043c938 ====

void Catch_0043c938(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x70) {
    FUN_0043b000();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043c970 @ 0x0043c970 ====

void FUN_0043c970(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097ac81;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_0043b230(param_3);
    }
    param_1 = param_1 + 0x44;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043c9c8 @ 0x0043c9c8 ====

void Catch_0043c9c8(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_0043b090();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043ca00 @ 0x0043ca00 ====

int FUN_0043ca00(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097aca1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x68) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0043c460(param_1);
    }
    param_3 = param_3 + 0x68;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043ca56 @ 0x0043ca56 ====

void Catch_0043ca56(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x68) {
    FUN_0043b740();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043ca90 @ 0x0043ca90 ====

void FUN_0043ca90(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097acc1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_0043c460(param_3);
    }
    param_1 = param_1 + 0x68;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043cae8 @ 0x0043cae8 ====

void Catch_0043cae8(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x68) {
    FUN_0043b740();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043cb20 @ 0x0043cb20 ====

int FUN_0043cb20(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097ace1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x44) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0043ba50(param_1);
    }
    param_3 = param_3 + 0x44;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0043cb76 @ 0x0043cb76 ====

void Catch_0043cb76(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_0043c000();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043cbb0 @ 0x0043cbb0 ====

void FUN_0043cbb0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x70) {
    FUN_0043b000();
  }
  return;
}


// ==== FUN_0043cbe0 @ 0x0043cbe0 ====

void FUN_0043cbe0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x44) {
    FUN_0043b090();
  }
  return;
}


// ==== FUN_0043cc10 @ 0x0043cc10 ====

int FUN_0043cc10(int param_1,int param_2,undefined4 param_3)

{
  FUN_0043c8e0(param_1,param_2,param_3);
  return param_2 * 0x70 + param_1;
}


// ==== FUN_0043cc50 @ 0x0043cc50 ====

int FUN_0043cc50(int param_1,int param_2,undefined4 param_3)

{
  FUN_0043c970(param_1,param_2,param_3);
  return param_1 + param_2 * 0x44;
}


// ==== FUN_0043cc80 @ 0x0043cc80 ====

void FUN_0043cc80(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097ad01;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_0043ba50(param_3);
    }
    param_1 = param_1 + 0x44;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043ccd8 @ 0x0043ccd8 ====

void Catch_0043ccd8(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_0043c000();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043cd10 @ 0x0043cd10 ====

void FUN_0043cd10(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x70) {
    FUN_0043b000();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043cd60 @ 0x0043cd60 ====

void FUN_0043cd60(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_0043b090();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043cdb0 @ 0x0043cdb0 ====

void FUN_0043cdb0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_0043be40(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x70) {
      FUN_0043b000();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_0043ce10 @ 0x0043ce10 ====

void FUN_0043ce10(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  int iVar5;
  int iVar6;
  undefined1 local_88 [2];
  undefined1 auStack_86 [114];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ad1b;
  local_10 = ExceptionList;
  local_14 = local_88 + -0xc;
  ExceptionList = &local_10;
  FUN_0043b160(param_3);
  iVar1 = *(int *)(in_ECX + 4);
  uVar4 = 0;
  local_8 = 0;
  if (iVar1 != 0) {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar1) / 0x70;
  }
  if (param_2 != 0) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
    }
    if (0x2492492U - iVar1 < param_2) {
      FUN_004389d0();
      uVar4 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x2492492 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
      }
      if (uVar4 < iVar1 + param_2) {
        iVar1 = FUN_0086a420();
        uVar4 = iVar1 + param_2;
      }
      pvVar2 = operator_new(uVar4 * 0x70);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar3 = FUN_0043c690(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      uVar3 = FUN_0043cc10(uVar3,param_2,local_88);
      FUN_0043c690(param_1,*(undefined4 *)(in_ECX + 8),uVar3);
      iVar1 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_0043cbb0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar4 * 0x70 + (int)pvVar2);
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar1) * 0x70 + (int)pvVar2);
      *(void **)(in_ECX + 4) = pvVar2;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8);
      iVar5 = param_2 * 0x70;
      if ((uint)((iVar1 - param_1) / 0x70) < param_2) {
        FUN_0043c690(param_1,iVar1,iVar5 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0043cc10(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x70,
                     local_88);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
        local_8 = 0;
        FUN_0043c520(param_1,*(int *)(in_ECX + 8) + param_2 * -0x70,local_88);
      }
      else {
        iVar6 = iVar1 + param_2 * -0x70;
        uVar3 = FUN_0043c690(iVar6,iVar1,iVar1);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_0043be80(param_1,iVar6,iVar1,param_1);
        FUN_0043c520(param_1,iVar5 + param_1,local_88);
      }
    }
  }
  FUN_0043b000();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043cfdc @ 0x0043cfdc ====

void Catch_0043cfdc(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0043cbb0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0043d0a0 @ 0x0043d0a0 ====

void Catch_0043d0a0(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x70;
  FUN_0043cbb0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043d130 @ 0x0043d130 ====

void FUN_0043d130(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_0043bec0(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x44) {
      FUN_0043b090();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_0043d190 @ 0x0043d190 ====

void FUN_0043d190(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_5c [2];
  undefined1 auStack_5a [70];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ad38;
  local_10 = ExceptionList;
  local_14 = local_5c + -0xc;
  ExceptionList = &local_10;
  FUN_0043b230(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x44;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (0x3c3c3c3U - iVar1 < param_2) {
      FUN_004389d0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x3c3c3c3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_005d0c90();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x44);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_0043c720(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0043c970(iVar2,param_2,local_5c);
      FUN_0043c720(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x44);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (iVar2 != 0) {
        FUN_0043cbe0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x44 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x44);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x44;
      if ((uint)((iVar2 - param_1) / 0x44) < param_2) {
        FUN_0043c720(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0043cc50(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x44,local_5c
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_0043c550(param_1,*(int *)(in_ECX + 8) + param_2 * -0x44,local_5c);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x44;
        uVar4 = FUN_0043c720(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0043bf20(param_1,iVar6,iVar2,param_1);
        FUN_0043c550(param_1,iVar1 + param_1,local_5c);
      }
    }
  }
  FUN_0043b090();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043d354 @ 0x0043d354 ====

void Catch_0043d354(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0043cbe0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0043d40c @ 0x0043d40c ====

void Catch_0043d40c(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x44;
  FUN_0043cbe0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043d490 @ 0x0043d490 ====

void FUN_0043d490(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x68) {
    FUN_0043b740();
  }
  return;
}


// ==== FUN_0043d4c0 @ 0x0043d4c0 ====

int FUN_0043d4c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0043ca90(param_1,param_2,param_3);
  return param_1 + param_2 * 0x68;
}


// ==== FUN_0043d520 @ 0x0043d520 ====

void FUN_0043d520(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ad58;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x70;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x70;
    }
    ExceptionList = &local_c;
    FUN_0043ce10(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x70)) {
        ExceptionList = &local_c;
        FUN_0043cdb0(&param_1,param_1 * 0x70 + iVar2,*(int *)(in_ECX + 8));
      }
    }
  }
  FUN_0043b000();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043d600 @ 0x0043d600 ====

void FUN_0043d600(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ad78;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    ExceptionList = &local_c;
    FUN_0043d190(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x44)) {
        ExceptionList = &local_c;
        FUN_0043d130(&param_1,iVar2 + param_1 * 0x44,*(int *)(in_ECX + 8));
      }
    }
  }
  FUN_0043b090();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043d6d0 @ 0x0043d6d0 ====

void FUN_0043d6d0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x68) {
    FUN_0043b740();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043d720 @ 0x0043d720 ====

void FUN_0043d720(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x44) {
    FUN_0043c000();
  }
  return;
}


// ==== FUN_0043d750 @ 0x0043d750 ====

void FUN_0043d750(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_0043bf80(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x68) {
      FUN_0043b740();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_0043d7b0 @ 0x0043d7b0 ====

void FUN_0043d7b0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_80 [2];
  undefined1 auStack_7e [106];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ad98;
  local_10 = ExceptionList;
  local_14 = local_80 + -0xc;
  ExceptionList = &local_10;
  FUN_0043c460(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x68;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x68;
    }
    if (0x2762762U - iVar1 < param_2) {
      FUN_004389d0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x68;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x2762762 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x68;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00436580();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x68);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar4 = FUN_0043ca00(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      uVar4 = FUN_0043d4c0(uVar4,param_2,local_80);
      FUN_0043ca00(param_1,*(undefined4 *)(in_ECX + 8),uVar4);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x68;
      }
      if (iVar2 != 0) {
        FUN_0043d490(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x68 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x68);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x68;
      if ((uint)((iVar2 - param_1) / 0x68) < param_2) {
        FUN_0043ca00(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0043d4c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x68,local_80
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_0043c5a0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x68,local_80);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x68;
        uVar4 = FUN_0043ca00(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0043bfc0(param_1,iVar6,iVar2,param_1);
        FUN_0043c5a0(param_1,iVar1 + param_1,local_80);
      }
    }
  }
  FUN_0043b740();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043d96f @ 0x0043d96f ====

void Catch_0043d96f(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0043d490(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0043da2f @ 0x0043da2f ====

void Catch_0043da2f(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x68;
  FUN_0043d490(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043dac0 @ 0x0043dac0 ====

int FUN_0043dac0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0043cc80(param_1,param_2,param_3);
  return param_1 + param_2 * 0x44;
}


// ==== FUN_0043daf0 @ 0x0043daf0 ====

void FUN_0043daf0(undefined4 param_1)

{
  undefined1 auStack_84 [4];
  undefined1 local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097adce;
  local_c = ExceptionList;
  local_10 = auStack_84;
  local_6c = 0xf;
  local_70 = 0;
  local_80 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  FUN_0043d520(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043db70 @ 0x0043db70 ====

void FUN_0043db70(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_0043c000();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043dbc0 @ 0x0043dbc0 ====

void FUN_0043dbc0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ade8;
  pvStack_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x68;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x68;
    }
    ExceptionList = &pvStack_c;
    FUN_0043d7b0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &pvStack_c;
    if (iVar2 != 0) {
      ExceptionList = &pvStack_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x68)) {
        ExceptionList = &pvStack_c;
        FUN_0043d750(&param_1,iVar2 + param_1 * 0x68,*(int *)(in_ECX + 8));
      }
    }
  }
  FUN_0043b740();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0043dca0 @ 0x0043dca0 ====

void FUN_0043dca0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_0043c5d0(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x44) {
      FUN_0043c000();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_0043dd00 @ 0x0043dd00 ====

void FUN_0043dd00(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_5c [2];
  undefined1 auStack_5a [70];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ae08;
  local_10 = ExceptionList;
  local_14 = local_5c + -0xc;
  ExceptionList = &local_10;
  FUN_0043ba50(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x44;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (0x3c3c3c3U - iVar1 < param_2) {
      FUN_004389d0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x3c3c3c3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_005d0c90();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x44);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_0043cb20(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0043cc80(iVar2,param_2,local_5c);
      FUN_0043cb20(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x44);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (iVar2 != 0) {
        FUN_0043d720(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x44 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x44);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x44;
      if ((uint)((iVar2 - param_1) / 0x44) < param_2) {
        FUN_0043cb20(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0043dac0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x44,local_5c
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_0043c890(param_1,*(int *)(in_ECX + 8) + param_2 * -0x44,local_5c);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x44;
        uVar4 = FUN_0043cb20(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0043c630(param_1,iVar6,iVar2,param_1);
        FUN_0043c890(param_1,iVar1 + param_1,local_5c);
      }
    }
  }
  FUN_0043c000();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0043dec4 @ 0x0043dec4 ====

void Catch_0043dec4(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0043d720(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0043df7c @ 0x0043df7c ====

void Catch_0043df7c(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x44;
  FUN_0043d720(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0043e010 @ 0x0043e010 ====

void FUN_0043e010(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ae28;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    ExceptionList = &local_c;
    FUN_0043dd00(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x44)) {
        ExceptionList = &local_c;
        FUN_0043dca0(&param_1,iVar2 + param_1 * 0x44,*(int *)(in_ECX + 8));
      }
    }
  }
  FUN_0043c000();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043e0e0 @ 0x0043e0e0 ====

void FUN_0043e0e0(undefined4 param_1)

{
  undefined1 auStack_58 [4];
  undefined1 local_54;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ae53;
  local_c = ExceptionList;
  local_10 = auStack_58;
  local_40 = 0xf;
  local_44 = 0;
  local_54 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  FUN_0043e010(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043e150 @ 0x0043e150 ====

void FUN_0043e150(byte param_1)

{
  void *in_ECX;
  
  FUN_00438240();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0043e170 @ 0x0043e170 ====

void FUN_0043e170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e570;
  return;
}


// ==== FUN_0043e190 @ 0x0043e190 ====

void FUN_0043e190(int param_1)

{
  _free(*(void **)(param_1 + 0xc));
  return;
}


// ==== FUN_0043e1b0 @ 0x0043e1b0 ====

void FUN_0043e1b0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ae68;
  local_c = ExceptionList;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  ExceptionList = &local_c;
  FUN_004400d0();
  local_4 = 0;
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    param_2 = param_2 + 4;
  }
  else {
    param_2 = *(int *)(param_2 + 4);
  }
  local_34 = FUN_004405c0(param_2,&local_3c);
  local_4 = 0xffffffff;
  FUN_0043ff50();
  uVar1 = 0;
  if (local_34 != 0) {
    uVar1 = local_3c;
  }
  *param_1 = 0;
  param_1[1] = uVar1;
  param_1[2] = local_38;
  param_1[3] = local_34;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043e260 @ 0x0043e260 ====

undefined4 FUN_0043e260(undefined4 param_1,undefined4 param_2)

{
  FUN_0043e1b0(param_1,param_2);
  return param_1;
}


// ==== FUN_0043e280 @ 0x0043e280 ====

void FUN_0043e280(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e570;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0043e2a0 @ 0x0043e2a0 ====

void FUN_0043e2a0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x69) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x69) == '\0');
  }
  return;
}


// ==== FUN_0043e2c0 @ 0x0043e2c0 ====

void FUN_0043e2c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x29) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x29) == '\0');
  }
  return;
}


// ==== FUN_0043e2e0 @ 0x0043e2e0 ====

void FUN_0043e2e0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x29) == '\0') {
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


// ==== FUN_0043e340 @ 0x0043e340 ====

void FUN_0043e340(int *param_1)

{
  if (*param_1 == 1) {
                    /* WARNING: Could not recover jumptable at 0x0043e361. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    UnmapViewOfFile((LPCVOID)(param_1[3] - param_1[2]));
    return;
  }
  _free((void *)param_1[3]);
  return;
}


// ==== FUN_0043e370 @ 0x0043e370 ====

undefined4 * FUN_0043e370(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *extraout_EAX;
  char *_Str2;
  int iVar2;
  int *piVar3;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  LPVOID pvVar4;
  undefined4 *extraout_EAX_02;
  HANDLE pvVar5;
  void *_Memory;
  BOOL BVar6;
  undefined4 *extraout_EAX_03;
  undefined4 *extraout_EAX_04;
  int in_ECX;
  char *****_Str1;
  int iVar7;
  undefined8 uVar8;
  void *lpBuffer;
  LONG lDistanceToMove;
  uint nNumberOfBytesToRead;
  PLONG lpDistanceToMoveHigh;
  DWORD *lpNumberOfBytesRead;
  DWORD DVar9;
  LPOVERLAPPED lpOverlapped;
  DWORD local_70;
  int local_6c;
  int local_68;
  DWORD local_64;
  char *****local_5c [5];
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
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097aec8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0043fdf0();
  local_4 = 0;
  FUN_004041d0();
  local_4 = CONCAT31(local_4._1_3_,2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_6c = FUN_00441440();
  if (local_6c != *(int *)(in_ECX + 0x50)) {
    if (*(uint *)(local_6c + 0x28) < 0x10) {
      _Str2 = (char *)(local_6c + 0x14);
    }
    else {
      _Str2 = *(char **)(local_6c + 0x14);
    }
    _Str1 = local_5c[0];
    if (local_48 < 0x10) {
      _Str1 = (char *****)local_5c;
    }
    iVar2 = __stricmp((char *)_Str1,_Str2);
    if (-1 < iVar2) {
      piVar3 = &local_6c;
      goto LAB_0043e437;
    }
  }
  local_68 = *(int *)(in_ECX + 0x50);
  piVar3 = &local_68;
LAB_0043e437:
  iVar2 = *piVar3;
  if (iVar2 == *(int *)(in_ECX + 0x50)) {
    FUN_00401740(s_data___s_missing___0099e5e4,0x12);
    FUN_00404230(local_44);
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_00796d50(local_44);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    if (0xf < local_2c) {
      _free(local_40);
      return extraout_EAX_00;
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    if (0xf < local_48) {
      _free(local_5c[0]);
      return extraout_EAX_01;
    }
  }
  else {
    __alldiv();
    uVar8 = __allmul();
    local_64 = (DWORD)((ulonglong)uVar8 >> 0x20);
    iVar7 = *(int *)(iVar2 + 0x50) - (DWORD)uVar8;
    if (local_64 == 0) {
      DVar9 = 0;
    }
    else {
      DVar9 = local_64;
    }
    pvVar4 = MapViewOfFile(*(HANDLE *)(in_ECX + 0x2c),4,DVar9,(DWORD)uVar8,
                           *(int *)(iVar2 + 0x58) + iVar7);
    uVar1 = *(uint *)(iVar2 + 0x58);
    if (pvVar4 == (LPVOID)0x0) {
      lDistanceToMove = *(LONG *)(iVar2 + 0x50);
      DVar9 = 0;
      lpDistanceToMoveHigh = (PLONG)0x0;
      pvVar5 = (HANDLE)FUN_0043ff00();
      DVar9 = SetFilePointer(pvVar5,lDistanceToMove,lpDistanceToMoveHigh,DVar9);
      if (DVar9 == 0xffffffff) {
        FUN_00401830();
        local_4._0_1_ = 4;
        FUN_00406880();
        local_4 = CONCAT31(local_4._1_3_,2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      _Memory = operator_new(uVar1);
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesRead = &local_70;
      lpBuffer = _Memory;
      nNumberOfBytesToRead = uVar1;
      pvVar5 = (HANDLE)FUN_0043ff00();
      BVar6 = ReadFile(pvVar5,lpBuffer,nNumberOfBytesToRead,lpNumberOfBytesRead,lpOverlapped);
      if (BVar6 == 0) {
        _free(_Memory);
        return extraout_EAX_03;
      }
      *param_1 = 0;
      param_1[1] = uVar1;
      param_1[2] = 0;
      param_1[3] = _Memory;
      if (local_48 < 0x10) {
        ExceptionList = local_c;
        return param_1;
      }
      _free(local_5c[0]);
      return extraout_EAX_04;
    }
    *param_1 = 1;
    param_1[1] = uVar1;
    param_1[2] = iVar7;
    param_1[3] = (int)pvVar4 + iVar7;
    if (0xf < local_48) {
      _free(local_5c[0]);
      return extraout_EAX_02;
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== FUN_0043e6d0 @ 0x0043e6d0 ====

undefined4 FUN_0043e6d0(undefined4 param_1,undefined4 param_2)

{
  FUN_0043e370(param_1,param_2);
  return param_1;
}


// ==== FUN_0043e6f0 @ 0x0043e6f0 ====

void FUN_0043e6f0(int param_1)

{
  uint *puVar1;
  char cVar2;
  char *_Memory;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  int local_1ac;
  int *local_1a8;
  undefined4 local_1a4;
  int local_1a0;
  undefined1 local_19c [4];
  undefined1 local_198;
  undefined4 local_188;
  undefined4 local_184;
  undefined1 local_15c [4];
  void *local_158;
  undefined4 local_148;
  uint local_144;
  void *local_13c;
  undefined4 local_12c;
  uint local_128;
  undefined1 local_108 [4];
  void *local_104;
  undefined4 local_f4;
  uint local_f0;
  undefined1 local_ec [4];
  void *local_e8;
  undefined4 local_d8;
  uint local_d4;
  undefined1 local_d0 [4];
  void *local_cc;
  undefined4 local_bc;
  uint local_b8;
  undefined1 local_b4 [4];
  void *local_b0;
  undefined4 local_a0;
  uint local_9c;
  undefined1 local_98 [8];
  undefined1 local_90 [108];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097af42;
  pvStack_c = ExceptionList;
  local_144 = 0xf;
  local_148 = 0;
  local_158 = (void *)((uint)local_158 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Framework__DriverKernel__Data__L_0099e5a0,0x40);
  local_4 = 0;
  FUN_00401870(local_15c);
  local_4._0_1_ = 2;
  if (0xf < local_144) {
    _free(local_158);
    return;
  }
  local_144 = 0xf;
  local_148 = 0;
  local_158 = (void *)((uint)local_158 & 0xffffff00);
  FUN_004400d0();
  local_4 = CONCAT31(local_4._1_3_,3);
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    param_1 = param_1 + 4;
  }
  else {
    param_1 = *(int *)(param_1 + 4);
  }
  FUN_00440100(param_1,0);
  FUN_0043ff10(400);
  FUN_004402f0(in_ECX + 0x30,8);
  local_1a8 = (int *)(in_ECX + 0x38);
  FUN_004402f0(local_1a8,4);
  puVar1 = (uint *)(in_ECX + 0x3c);
  FUN_004402f0(puVar1,4);
  uVar5 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_004402f0(local_98,4);
      FUN_004402f0(local_90,8);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar1);
  }
  local_128 = 0xf;
  local_12c = 0;
  local_13c = (void *)((uint)local_13c & 0xffffff00);
  local_4._0_1_ = 4;
  local_1a4 = 0;
  if (*local_1a8 == 0) {
    FUN_00440260();
    if (0xf < local_128) {
      _free(local_13c);
      return;
    }
    local_128 = 0xf;
    local_12c = 0;
    local_13c = (void *)((uint)local_13c & 0xffffff00);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_0043ff50();
    local_4 = 0xb;
    FUN_00796d40();
    if (uStack_10 < 0x10) {
      ExceptionList = pvStack_c;
      return;
    }
    _free(pvStack_24);
    return;
  }
  local_1a0 = in_ECX + 0x4c;
  FUN_004402f0(&local_1ac,4);
  _Memory = operator_new(local_1ac + 1);
  FUN_004402f0(_Memory,local_1ac);
  _Memory[local_1ac] = '\0';
  local_184 = 0xf;
  local_188 = 0;
  local_198 = 0;
  pcVar3 = _Memory;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(_Memory,(int)pcVar3 - (int)(_Memory + 1));
  local_4._0_1_ = 5;
  uVar4 = FUN_004041d0(local_d0,local_19c);
  local_4._0_1_ = 6;
  FUN_00401660(uVar4,0,0xffffffff);
  local_4._0_1_ = 5;
  if (0xf < local_b8) {
    _free(local_cc);
    return;
  }
  local_b8 = 0xf;
  local_bc = 0;
  local_cc = (void *)((uint)local_cc & 0xffffff00);
  if ((*_Memory == '/') || (*_Memory == '\\')) {
    uVar4 = FUN_00405b90(local_108,1,local_1ac + -1);
    local_4._0_1_ = 7;
    uVar4 = FUN_0043fdf0(local_ec,uVar4);
    local_4._0_1_ = 8;
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < local_d4) {
      _free(local_e8);
      return;
    }
    local_d4 = 0xf;
    local_d8 = 0;
    local_e8 = (void *)((uint)local_e8 & 0xffffff00);
    local_4 = CONCAT31(local_4._1_3_,5);
    if (0xf < local_f0) {
      _free(local_104);
      return;
    }
    local_f0 = 0xf;
    local_f4 = 0;
    local_104 = (void *)((uint)local_104 & 0xffffff00);
  }
  else {
    uVar4 = FUN_0043fdf0(local_b4,local_19c);
    local_4._0_1_ = 9;
    FUN_00401660(uVar4,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,5);
    if (0xf < local_9c) {
      _free(local_b0);
      return;
    }
    local_9c = 0xf;
    local_a0 = 0;
    local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  }
  _free(_Memory);
  return;
}


// ==== FUN_0043ebf0 @ 0x0043ebf0 ====

void FUN_0043ebf0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097af62;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e610;
  local_4 = 1;
  if ((HANDLE)in_ECX[0xb] != (HANDLE)0x0) {
    CloseHandle((HANDLE)in_ECX[0xb]);
  }
  FUN_00440260();
  local_4 = local_4 & 0xffffff00;
  FUN_0043fce0();
  local_4 = 0xffffffff;
  FUN_0043ff50();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0043ec70 @ 0x0043ec70 ====

void FUN_0043ec70(void)

{
  undefined4 uVar1;
  undefined4 ***pppuVar2;
  DWORD dwMaximumSizeLow;
  HANDLE pvVar3;
  SIZE_T dwNumberOfBytesToMap;
  LPVOID lpBaseAddress;
  undefined4 *in_ECX;
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes;
  DWORD flProtect;
  DWORD dwMaximumSizeHigh;
  LPCSTR lpName;
  undefined1 local_c0 [4];
  undefined4 ***local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  undefined1 local_a0 [4];
  void *local_9c;
  undefined4 local_8c;
  uint local_88;
  undefined1 local_84 [4];
  void *local_80;
  undefined4 local_70;
  uint local_6c;
  undefined1 local_68 [4];
  void *local_64;
  undefined4 local_54;
  uint local_50;
  undefined1 local_4c [4];
  void *local_48;
  uint local_34;
  _SYSTEM_INFO local_30;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097afb9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e610;
  FUN_004400d0();
  local_4 = 0;
  FUN_0043fc50();
  local_4._0_1_ = 1;
  uVar1 = FUN_00404890(local_68);
  local_4._0_1_ = 2;
  uVar1 = FUN_004045b0(local_84,uVar1);
  local_4._0_1_ = 3;
  FUN_004046f0(local_4c,uVar1);
  if (0xf < local_6c) {
    _free(local_80);
    return;
  }
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_50) {
    _free(local_64);
    return;
  }
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  FUN_00402220(local_a0,local_4c,s_data_data_hd_0099e57c);
  local_4._0_1_ = 7;
  FUN_00402220(local_c0,local_4c,s_data_data_pak_0099e58c);
  local_4 = CONCAT31(local_4._1_3_,8);
  FUN_0043e6f0(local_a0);
  pppuVar2 = local_bc[0];
  if (local_a8 < 0x10) {
    pppuVar2 = local_bc;
  }
  FUN_00440100(pppuVar2,0);
  lpName = (LPCSTR)0x0;
  dwMaximumSizeLow = FUN_0043fee0();
  dwMaximumSizeHigh = 0;
  flProtect = 2;
  lpFileMappingAttributes = (LPSECURITY_ATTRIBUTES)0x0;
  pvVar3 = (HANDLE)FUN_0043ff00();
  pvVar3 = CreateFileMappingA(pvVar3,lpFileMappingAttributes,flProtect,dwMaximumSizeHigh,
                              dwMaximumSizeLow,lpName);
  in_ECX[0xb] = pvVar3;
  dwNumberOfBytesToMap = FUN_0043fee0();
  lpBaseAddress = MapViewOfFile((HANDLE)in_ECX[0xb],4,0,0,dwNumberOfBytesToMap);
  UnmapViewOfFile(lpBaseAddress);
  GetSystemInfo(&local_30);
  in_ECX[0x16] = local_30.dwAllocationGranularity;
  if (0xf < local_a8) {
    _free(local_bc[0]);
    return;
  }
  local_a8 = 0xf;
  local_ac = 0;
  local_bc[0] = (undefined4 ***)((uint)local_bc[0] & 0xffffff00);
  if (0xf < local_88) {
    _free(local_9c);
    return;
  }
  local_88 = 0xf;
  local_8c = 0;
  local_9c = (void *)((uint)local_9c & 0xffffff00);
  if (local_34 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_48);
  return;
}


// ==== FUN_0043ee80 @ 0x0043ee80 ====

void FUN_0043ee80(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x69) == '\0') {
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


// ==== FUN_0043ef90 @ 0x0043ef90 ====

void FUN_0043ef90(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x70);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x1a) = 1;
  *(undefined1 *)((int)puVar1 + 0x69) = 0;
  return;
}


// ==== FUN_0043efd0 @ 0x0043efd0 ====

void FUN_0043efd0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    FUN_0043efd0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0043f010 @ 0x0043f010 ====

void FUN_0043f010(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ae88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043f0b0 @ 0x0043f0b0 ====

void FUN_0043f0b0(undefined4 param_1,int param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ae88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_2 + 0x34);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043f150 @ 0x0043f150 ====

/* WARNING: Removing unreachable block (ram,0x0043f263) */
/* WARNING: Removing unreachable block (ram,0x0043f273) */
/* WARNING: Removing unreachable block (ram,0x0043f27c) */
/* WARNING: Removing unreachable block (ram,0x0043f27f) */
/* WARNING: Removing unreachable block (ram,0x0043f26f) */
/* WARNING: Removing unreachable block (ram,0x0043f28d) */
/* WARNING: Removing unreachable block (ram,0x0043f29a) */
/* WARNING: Removing unreachable block (ram,0x0043f2a5) */
/* WARNING: Removing unreachable block (ram,0x0043f2a1) */
/* WARNING: Removing unreachable block (ram,0x0043f295) */
/* WARNING: Removing unreachable block (ram,0x0043f2a8) */

void FUN_0043f150(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097afd8;
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
            goto LAB_0043f375;
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
LAB_0043f375:
            *(undefined1 *)(piVar5 + 10) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 10) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_0043f400 @ 0x0043f400 ====

undefined4 *
FUN_0043f400(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097b001;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x70);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_0043f010(param_4);
    *(undefined1 *)(puVar1 + 0x1a) = param_5;
    *(undefined1 *)((int)puVar1 + 0x69) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0043f47e @ 0x0043f47e ====

void Catch_0043f47e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0043f4a0 @ 0x0043f4a0 ====

void FUN_0043f4a0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0043efd0(piVar6[1]);
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
    FUN_0043f150(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0043f560 @ 0x0043f560 ====

/* WARNING: Removing unreachable block (ram,0x0043f66d) */
/* WARNING: Removing unreachable block (ram,0x0043f67d) */
/* WARNING: Removing unreachable block (ram,0x0043f686) */
/* WARNING: Removing unreachable block (ram,0x0043f689) */
/* WARNING: Removing unreachable block (ram,0x0043f679) */
/* WARNING: Removing unreachable block (ram,0x0043f697) */
/* WARNING: Removing unreachable block (ram,0x0043f6a4) */
/* WARNING: Removing unreachable block (ram,0x0043f6af) */
/* WARNING: Removing unreachable block (ram,0x0043f6ab) */
/* WARNING: Removing unreachable block (ram,0x0043f69f) */
/* WARNING: Removing unreachable block (ram,0x0043f6b2) */

void FUN_0043f560(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097afd8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x69) != '\0') {
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
  FUN_004413a0();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x69) == '\0') {
    if (*(char *)(param_2[2] + 0x69) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x69) == '\0') {
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
    if (*(char *)((int)piVar5 + 0x69) == '\0') {
      piVar3 = (int *)FUN_00441360(piVar5);
    }
    else {
      piVar3 = piVar6;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x69) == '\0') {
      uVar4 = FUN_0043e2a0(piVar5);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar6;
    }
  }
  if ((char)param_2[0x1a] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        if ((char)piVar5[0x1a] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x1a] == '\0') {
            *(undefined1 *)(piVar3 + 0x1a) = 1;
            *(undefined1 *)(piVar6 + 0x1a) = 0;
            FUN_004413f0(piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x69) == '\0') {
            if ((*(char *)(*piVar3 + 0x68) == '\x01') && (*(char *)(piVar3[2] + 0x68) == '\x01'))
            goto LAB_0043f784;
            if (*(char *)(piVar3[2] + 0x68) == '\x01') {
              *(undefined1 *)(*piVar3 + 0x68) = 1;
              *(undefined1 *)(piVar3 + 0x1a) = 0;
              FUN_0043ee80(piVar3);
              piVar3 = (int *)piVar6[2];
            }
            *(char *)(piVar3 + 0x1a) = (char)piVar6[0x1a];
            *(undefined1 *)(piVar6 + 0x1a) = 1;
            *(undefined1 *)(piVar3[2] + 0x68) = 1;
            FUN_004413f0(piVar6);
            break;
          }
        }
        else {
          if ((char)piVar3[0x1a] == '\0') {
            *(undefined1 *)(piVar3 + 0x1a) = 1;
            *(undefined1 *)(piVar6 + 0x1a) = 0;
            FUN_0043ee80(piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x69) == '\0') {
            if ((*(char *)(piVar3[2] + 0x68) != '\x01') || (*(char *)(*piVar3 + 0x68) != '\x01')) {
              if (*(char *)(*piVar3 + 0x68) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x68) = 1;
                *(undefined1 *)(piVar3 + 0x1a) = 0;
                FUN_004413f0(piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 0x1a) = (char)piVar6[0x1a];
              *(undefined1 *)(piVar6 + 0x1a) = 1;
              *(undefined1 *)(*piVar3 + 0x68) = 1;
              FUN_0043ee80(piVar6);
              break;
            }
LAB_0043f784:
            *(undefined1 *)(piVar3 + 0x1a) = 0;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x1a) = 1;
  }
  if (0xf < (uint)param_2[0x12]) {
    _free((void *)param_2[0xd]);
    return;
  }
  param_2[0x12] = 0xf;
  param_2[0x11] = 0;
  *(undefined1 *)(param_2 + 0xd) = 0;
  if ((uint)param_2[10] < 0x10) {
    param_2[10] = 0xf;
    param_2[9] = 0;
    *(undefined1 *)(param_2 + 5) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_0043f850 @ 0x0043f850 ====

void FUN_0043f850(void *param_1)

{
  if (*(char *)((int)param_1 + 0x69) == '\0') {
    FUN_0043f850(*(undefined4 *)((int)param_1 + 8));
    FUN_00441530();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0043fb60 @ 0x0043fb60 ====

void FUN_0043fb60(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0043f850(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x69) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x69) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x69);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x69);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x69);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x69);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0043f560(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0043fc20 @ 0x0043fc20 ====

void FUN_0043fc20(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0043f4a0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0043fc50 @ 0x0043fc50 ====

void FUN_0043fc50(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b01b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_004414b0();
  *(int *)(in_ECX + 0x14) = iVar1;
  *(undefined1 *)(iVar1 + 0x29) = 1;
  *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  local_4 = 0;
  iVar1 = FUN_0043ef90();
  *(int *)(in_ECX + 0x20) = iVar1;
  *(undefined1 *)(iVar1 + 0x69) = 1;
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0043fce0 @ 0x0043fce0 ====

void FUN_0043fce0(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b03b;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_0043fb60(local_10,**(undefined4 **)(in_ECX + 0x20),*(undefined4 **)(in_ECX + 0x20));
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_0043fd80 @ 0x0043fd80 ====

void FUN_0043fd80(byte param_1)

{
  void *in_ECX;
  
  FUN_0043ebf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0043fda0 @ 0x0043fda0 ====

int * FUN_0043fda0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined1 auStack_a [10];
  
  piVar1 = (int *)(**(code **)*DAT_00b5a744)(param_1);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  FUN_00424d30(param_1,param_2);
  (**(code **)(*piVar1 + 8))(auStack_a + -6);
  return piVar1;
}


// ==== FUN_0043fdf0 @ 0x0043fdf0 ====

int FUN_0043fdf0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int extraout_EAX;
  undefined4 ***pppuVar2;
  undefined4 ***pppuVar3;
  uint uVar4;
  undefined1 local_28 [4];
  undefined4 ***local_24 [4];
  uint local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b058;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (undefined4 ***)((uint)local_24[0] & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(param_2,0,0xffffffff);
  uVar1 = 0;
  local_4 = 0;
  if (local_14 != 0) {
    pppuVar2 = local_24[0];
    uVar4 = local_10;
    do {
      pppuVar3 = pppuVar2;
      if (uVar4 < 0x10) {
        pppuVar3 = local_24;
      }
      if (*(char *)((int)pppuVar3 + uVar1) == '\\') {
        if (uVar4 < 0x10) {
          pppuVar2 = local_24;
        }
        *(undefined1 *)((int)pppuVar2 + uVar1) = 0x2f;
        pppuVar2 = local_24[0];
        uVar4 = local_10;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < local_14);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24[0]);
  return extraout_EAX;
}


// ==== FUN_0043fec0 @ 0x0043fec0 ====

int FUN_0043fec0(int param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    return in_ECX + 4 + param_1;
  }
  return param_1 + *(int *)(in_ECX + 4);
}


// ==== FUN_0043fee0 @ 0x0043fee0 ====

void FUN_0043fee0(void)

{
  int in_ECX;
  DWORD local_4;
  
  GetFileSize(*(HANDLE *)(in_ECX + 4),&local_4);
  return;
}


// ==== FUN_0043ff00 @ 0x0043ff00 ====

undefined4 FUN_0043ff00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0043ff10 @ 0x0043ff10 ====

undefined4 FUN_0043ff10(LONG param_1)

{
  int in_ECX;
  
  SetFilePointer(*(HANDLE *)(in_ECX + 4),param_1,(PLONG)0x0,0);
  return 0;
}


// ==== FUN_0043ff50 @ 0x0043ff50 ====

void FUN_0043ff50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e6f8;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0043ff80 @ 0x0043ff80 ====

uint FUN_0043ff80(int param_1)

{
  int iVar1;
  BOOL BVar2;
  LPCSTR **pppCVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  bool bVar4;
  undefined1 local_28 [4];
  LPCSTR **local_24 [4];
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b078;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) != 0) {
    ExceptionList = &local_c;
    FUN_004046f0(local_28,param_1);
    local_4 = 0;
    iVar1 = FUN_00403620(0,local_14,&DAT_0099e617,0);
    if (iVar1 != 0) {
      iVar1 = FUN_00403620(0,local_14,&DAT_0099e618,1);
      if (iVar1 != 0) {
        pppCVar3 = local_24[0];
        if (local_10 < 0x10) {
          pppCVar3 = (LPCSTR **)local_24;
        }
        BVar2 = CreateDirectoryA((LPCSTR)pppCVar3,(LPSECURITY_ATTRIBUTES)0x0);
        bVar4 = BVar2 == 1;
        if (!bVar4) {
          FUN_0043ff80(local_28);
          pppCVar3 = local_24[0];
          if (local_10 < 0x10) {
            pppCVar3 = (LPCSTR **)local_24;
          }
          BVar2 = CreateDirectoryA((LPCSTR)pppCVar3,(LPSECURITY_ATTRIBUTES)0x0);
          bVar4 = BVar2 == 1;
        }
        if (local_10 < 0x10) {
          ExceptionList = local_c;
          return (uint)bVar4;
        }
        _free(local_24[0]);
        return extraout_EAX;
      }
    }
    if (0xf < local_10) {
      _free(local_24[0]);
      return extraout_EAX_00;
    }
  }
  ExceptionList = local_c;
  return 1;
}


