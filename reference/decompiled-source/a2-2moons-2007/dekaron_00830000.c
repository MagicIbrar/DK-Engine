// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x830000-0x83ffff

// ==== FUN_00830020 @ 0x00830020 ====

void FUN_00830020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e1cc;
  DAT_00b5d948 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0e184;
  return;
}


// ==== FUN_00830050 @ 0x00830050 ====

void FUN_00830050(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e194;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830070 @ 0x00830070 ====

void FUN_00830070(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0e1ac;
  iVar1 = 0x100;
  do {
    FUN_0083b180();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0x2201] = 0;
  return;
}


// ==== FUN_008300b0 @ 0x008300b0 ====

void FUN_008300b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0e1b4;
  FUN_00830070();
  in_ECX[0x2202] = in_ECX[0x2202] + 0x100;
  in_ECX[0x2205] = in_ECX + 2;
  in_ECX[0x2203] = 0;
  in_ECX[0x2204] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[0x21] = puVar1 + 0x24;
    puVar1[0x22] = 0;
    puVar1[0x23] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x22;
  } while (iVar2 != 0);
  in_ECX[0x21ff] = 0;
  in_ECX[0x2200] = 0;
  in_ECX[0x2201] = 0;
  return;
}


// ==== FUN_00830120 @ 0x00830120 ====

undefined4 FUN_00830120(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x880c);
}


// ==== FUN_00830130 @ 0x00830130 ====

void FUN_00830130(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0e1ac;
  iVar1 = 0x100;
  do {
    FUN_0083b2f0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830180 @ 0x00830180 ====

void * FUN_00830180(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x84) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0e1d8,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x84) = *(int *)((int)param_2 + 0x84) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x8814);
  *(int *)(in_ECX + 0x880c) = *(int *)(in_ECX + 0x880c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x88);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0083b180();
    }
    *(undefined4 *)((int)pvVar2 + 0x80) = *(undefined4 *)(in_ECX + 0x8810);
    *(void **)(in_ECX + 0x8810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8814) = *(undefined4 *)((int)pvVar2 + 0x7c);
  }
  *(int *)((int)pvVar2 + 0x84) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x7c) = 0;
  FUN_0083aef0();
  return pvVar2;
}


// ==== FUN_00830260 @ 0x00830260 ====

undefined4 FUN_00830260(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x84) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0e1d8,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x84);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x84);
    }
    FUN_0083add0();
    *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(in_ECX + 0x8814);
    *(int *)(in_ECX + 0x880c) = *(int *)(in_ECX + 0x880c) + -1;
    *(int *)(in_ECX + 0x8814) = param_2;
  }
  return 0;
}


// ==== FUN_008302f0 @ 0x008302f0 ====

void FUN_008302f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00830310();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830310 @ 0x00830310 ====

void FUN_00830310(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0e1b4;
  if (in_ECX[0x2203] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e068,
                         s_d__usa_24_0_1_2__develop_module__00a0e000,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x23;
  iVar3 = 0x100;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e0e8,
                           s_d__usa_24_0_1_2__develop_module__00a0e080,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x22;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x2204];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0e1ac;
    iVar3 = 0x100;
    do {
      FUN_0083b2f0();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0e194;
    return;
  }
  if (*(int *)((int)_Memory + 0x84) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e168,
                         s_d__usa_24_0_1_2__develop_module__00a0e100,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0083b2f0();
  _free(_Memory);
  return;
}


// ==== FUN_00830430 @ 0x00830430 ====

void FUN_00830430(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e1cc;
  DAT_00b5d948 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0e184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830480 @ 0x00830480 ====

void FUN_00830480(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e284;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008304a0 @ 0x008304a0 ====

void FUN_008304a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e294;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d940 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d940 = in_ECX;
  return;
}


// ==== FUN_008304d0 @ 0x008304d0 ====

void FUN_008304d0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x008304e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_008304f0 @ 0x008304f0 ====

undefined4 * FUN_008304f0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x40);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0083b900();
  }
  cVar1 = FUN_0083b770(param_2,param_1);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_00830540 @ 0x00830540 ====

undefined4 * FUN_00830540(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x30);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0083bbb0();
  }
  cVar1 = FUN_0083bc00(param_2,param_1);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_00830590 @ 0x00830590 ====

undefined4 * FUN_00830590(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0xc0);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0083bf80();
  }
  cVar1 = FUN_0083bfd0(param_2,param_1,param_3);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_008305f0 @ 0x008305f0 ====

undefined4 * FUN_008305f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x3c);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0083c690();
  }
  cVar1 = FUN_0083c6b0(param_2,param_1,param_3);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_00830660 @ 0x00830660 ====

undefined4 FUN_00830660(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (undefined4 *)(**(code **)(*param_1 + 4))();
    switch(*puVar1) {
    case 1:
      uVar2 = FUN_00830590(param_1,param_2,param_3);
      return uVar2;
    case 6:
      uVar2 = FUN_00830540(param_1,param_2);
      return uVar2;
    case 7:
      uVar2 = FUN_008305f0(param_1,param_2,param_3);
      return uVar2;
    case 0xb:
      uVar2 = FUN_008304f0(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00830710 @ 0x00830710 ====

undefined4 FUN_00830710(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_18;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(param_2 + 0x54) == 0) || (iVar3 = FUN_0083d380(), iVar3 == 0)) {
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    uVar4 = FUN_00830660(param_1,param_2,&local_c);
    return uVar4;
  }
  pvVar5 = operator_new(0x14);
  if (pvVar5 == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0083cc40();
  }
  iVar1 = *(int *)(iVar3 + 0x24);
  for (iVar3 = *(int *)(iVar3 + 0x20); iVar3 != iVar1; iVar3 = iVar3 + 0x10) {
    iVar6 = 0;
    for (uVar7 = 0;
        (iVar2 = *(int *)(iVar3 + 4), iVar2 != 0 &&
        (uVar7 < (uint)((*(int *)(iVar3 + 8) - iVar2) / 0x1c))); uVar7 = uVar7 + 1) {
      uVar4 = FUN_00830660(param_1,param_2,iVar6 + iVar2);
      FUN_0083cc60(uVar4);
      iVar6 = iVar6 + 0x1c;
    }
  }
  return local_18;
}


// ==== FUN_00830800 @ 0x00830800 ====

undefined4 FUN_00830800(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_1 + 4))();
    iVar1 = *piVar2;
    if ((iVar1 == 0xb) || (iVar1 == 6)) {
      uStack_c = 0;
      uStack_8 = 0;
      uStack_4 = 0;
      uVar3 = FUN_00830660(param_1,param_2,&uStack_c);
      return uVar3;
    }
    if ((iVar1 == 1) || (iVar1 == 7)) {
      uVar3 = FUN_00830710(param_1,param_2);
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_00830880 @ 0x00830880 ====

void FUN_00830880(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5d940 = 0;
  *in_ECX = &PTR_FUN_00a0e284;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008308b0 @ 0x008308b0 ====

void FUN_008308b0(void)

{
  void *pvVar1;
  
  if (DAT_00b5d97c == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0083e580();
    }
  }
  if (DAT_00b5d978 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0083df20();
    }
  }
  if (DAT_00b5d974 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0083d650();
      return;
    }
  }
  return;
}


// ==== FUN_00830910 @ 0x00830910 ====

void FUN_00830910(void)

{
  if (DAT_00b5d97c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d97c)(1);
  }
  if (DAT_00b5d978 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d978)(1);
  }
  if (DAT_00b5d974 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d974)(1);
  }
  return;
}


// ==== FUN_00830950 @ 0x00830950 ====

void FUN_00830950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e324;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830970 @ 0x00830970 ====

void FUN_00830970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e334;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af38 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af38 = in_ECX;
  return;
}


// ==== FUN_008309a0 @ 0x008309a0 ====

undefined4 FUN_008309a0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d950 + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d950 + 8))();
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5d94c + 8))(piVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)(*DAT_00b5d950 + 8))(piVar2);
  }
  return 0;
}


// ==== FUN_00830a00 @ 0x00830a00 ====

undefined4 FUN_00830a00(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d94c + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 8))();
  (**(code **)(*DAT_00b5d950 + 8))(piVar1);
  return 1;
}


// ==== FUN_00830a60 @ 0x00830a60 ====

void FUN_00830a60(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5af38 = 0;
  *in_ECX = &PTR_FUN_00a0e324;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830a90 @ 0x00830a90 ====

void FUN_00830a90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e384;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00830ab0 @ 0x00830ab0 ====

int FUN_00830ab0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999ce0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00830b16 @ 0x00830b16 ====

void Catch_00830b16(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00830b20 @ 0x00830b20 ====

void FUN_00830b20(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999cf0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00830b8f @ 0x00830b8f ====

void Catch_00830b8f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00830bb0 @ 0x00830bb0 ====

void * FUN_00830bb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00830c1d @ 0x00830c1d ====

void Catch_00830c1d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00830c40 @ 0x00830c40 ====

void FUN_00830c40(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999d10;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00830ca6 @ 0x00830ca6 ====

void Catch_00830ca6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00830cb0 @ 0x00830cb0 ====

void FUN_00830cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00830ab0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00830d00 @ 0x00830d00 ====

uint FUN_00830d00(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int in_ECX;
  
  uVar4 = (**(code **)(*param_1 + 4))();
  if (uVar4 != 0x40001) {
    return uVar4 & 0xffffff00;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  iVar2 = param_1[2];
  uVar4 = 0x40001;
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined4 *)*puVar3) {
    uVar4 = (**(code **)(*(int *)puVar3[3] + 0x14))(iVar2);
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_00830d50 @ 0x00830d50 ====

undefined4 FUN_00830d50(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  return uVar1;
}


// ==== FUN_00830da0 @ 0x00830da0 ====

undefined4 FUN_00830da0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_00830dd0 @ 0x00830dd0 ====

void FUN_00830dd0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0e39c;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_00830b20();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_008311d0(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5d94c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d94c = in_ECX;
  return;
}


// ==== FUN_00830e50 @ 0x00830e50 ====

void FUN_00830e50(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e39c;
  DAT_00b5d94c = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 8))();
    (**(code **)(*DAT_00b5d950 + 8))(piVar3);
  }
  FUN_00831570();
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  if (_Memory == (void *)in_ECX[3]) {
    _free((void *)in_ECX[3]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00830f00 @ 0x00830f00 ====

undefined1 FUN_00830f00(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  undefined1 uStack_4;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))();
  uStack_10 = *puVar1;
  piStack_c = param_1;
  FUN_00831340(auStack_8,&uStack_10);
  return uStack_4;
}


// ==== FUN_00830f50 @ 0x00830f50 ====

int FUN_00830f50(int param_1,int param_2,undefined4 param_3)

{
  FUN_00830c40(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00830f80 @ 0x00830f80 ====

void FUN_00830f80(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d20;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_00830cb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00830f50(uVar5,param_2,&local_18);
      FUN_00830cb0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00830ab0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00830f50(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00830ab0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008310e1 @ 0x008310e1 ====

void Catch_008310e1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_008311d0 @ 0x008311d0 ====

void FUN_008311d0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_00830f50(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00831264 @ 0x00831264 ====

void Catch_00831264(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00831280 @ 0x00831280 ====

void FUN_00831280(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_00830f80(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_008312f0 @ 0x008312f0 ====

/* WARNING: Removing unreachable block (ram,0x0083130b) */
/* WARNING: Removing unreachable block (ram,0x00831310) */
/* WARNING: Removing unreachable block (ram,0x0083131e) */

void FUN_008312f0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00830f80(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00831340 @ 0x00831340 ====

/* WARNING: Removing unreachable block (ram,0x00831428) */

void FUN_00831340(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_00831280(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_00830bb0(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00831570 @ 0x00831570 ====

void FUN_00831570(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_008312f0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008315d0 @ 0x008315d0 ====

void FUN_008315d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00830e50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008315f0 @ 0x008315f0 ====

void FUN_008315f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e578;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831610 @ 0x00831610 ====

void FUN_00831610(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00831630 @ 0x00831630 ====

void FUN_00831630(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_00831640 @ 0x00831640 ====

void FUN_00831640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e5a8;
  DAT_00b5d950 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0e578;
  return;
}


// ==== FUN_00831670 @ 0x00831670 ====

void FUN_00831670(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0e5a8;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d950 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d950 = in_ECX;
  }
  pvVar2 = operator_new(0x2b18);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_00831770();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_008316c0 @ 0x008316c0 ====

void FUN_008316c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e588;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008316e0 @ 0x008316e0 ====

void FUN_008316e0(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0e5a0;
  iVar1 = 0x40;
  do {
    FUN_0083ee80();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831730 @ 0x00831730 ====

void FUN_00831730(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0e5a0;
  iVar1 = 0x40;
  do {
    FUN_0083ef10();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0xac1] = 0;
  return;
}


// ==== FUN_00831770 @ 0x00831770 ====

void FUN_00831770(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0e5b8;
  FUN_00831730();
  in_ECX[0xac2] = in_ECX[0xac2] + 0x40;
  in_ECX[0xac5] = in_ECX + 2;
  in_ECX[0xac3] = 0;
  in_ECX[0xac4] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[0x2a] = puVar1 + 0x2d;
    puVar1[0x2b] = 0;
    puVar1[0x2c] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x2b;
  } while (iVar2 != 0);
  in_ECX[0xabf] = 0;
  in_ECX[0xac0] = 0;
  in_ECX[0xac1] = 0;
  return;
}


// ==== FUN_008317e0 @ 0x008317e0 ====

undefined4 FUN_008317e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2b0c);
}


// ==== FUN_008317f0 @ 0x008317f0 ====

void * FUN_008317f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0xa8) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0e5d0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xa8) = *(int *)((int)param_2 + 0xa8) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2b14);
  *(int *)(in_ECX + 0x2b0c) = *(int *)(in_ECX + 0x2b0c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0xac);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0083ef10();
    }
    *(undefined4 *)((int)pvVar2 + 0xa4) = *(undefined4 *)(in_ECX + 0x2b10);
    *(void **)(in_ECX + 0x2b10) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2b14) = *(undefined4 *)((int)pvVar2 + 0xa0);
  }
  *(int *)((int)pvVar2 + 0xa8) = param_1;
  *(undefined4 *)((int)pvVar2 + 0xa0) = 0;
  FUN_0083eea0();
  return pvVar2;
}


// ==== FUN_008318d0 @ 0x008318d0 ====

undefined4 FUN_008318d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xa8) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0e5d0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xa8);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xa8);
    }
    FUN_0083ee50();
    *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(in_ECX + 0x2b14);
    *(int *)(in_ECX + 0x2b0c) = *(int *)(in_ECX + 0x2b0c) + -1;
    *(int *)(in_ECX + 0x2b14) = param_2;
  }
  return 0;
}


// ==== FUN_00831960 @ 0x00831960 ====

void FUN_00831960(byte param_1)

{
  void *in_ECX;
  
  FUN_00831980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831980 @ 0x00831980 ====

void FUN_00831980(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0e5b8;
  if (in_ECX[0xac3] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e45c,
                         s_d__usa_24_0_1_2__develop_module__00a0e3f0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x2c;
  iVar3 = 0x40;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e4dc,
                           s_d__usa_24_0_1_2__develop_module__00a0e470,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x2b;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0xac4];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0e5a0;
    iVar3 = 0x40;
    do {
      FUN_0083ee80();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0e588;
    return;
  }
  if (*(int *)((int)_Memory + 0xa8) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e55c,
                         s_d__usa_24_0_1_2__develop_module__00a0e4f0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0083ee80();
  _free(_Memory);
  return;
}


// ==== FUN_00831aa0 @ 0x00831aa0 ====

void FUN_00831aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e5a8;
  DAT_00b5d950 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0e578;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831af0 @ 0x00831af0 ====

void FUN_00831af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e680;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831b10 @ 0x00831b10 ====

int FUN_00831b10(uint param_1)

{
  if (param_1 < 10) {
    return 0;
  }
  if (param_1 < 100) {
    return 1;
  }
  if (param_1 < 1000) {
    return 2;
  }
  return 4 - (uint)(param_1 < 10000);
}


// ==== FUN_00831b50 @ 0x00831b50 ====

void FUN_00831b50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e694;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af3c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af3c = in_ECX;
  return;
}


// ==== FUN_00831b80 @ 0x00831b80 ====

undefined4 FUN_00831b80(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d95c + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d95c + 8))();
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5d958 + 8))(piVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)(*DAT_00b5d95c + 8))(piVar2);
  }
  return 0;
}


// ==== FUN_00831be0 @ 0x00831be0 ====

undefined4 FUN_00831be0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d958 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 8))();
  (**(code **)(*DAT_00b5d95c + 8))(piVar1);
  return 1;
}


// ==== FUN_00831c40 @ 0x00831c40 ====

void FUN_00831c40(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5af3c = 0;
  *in_ECX = &PTR_FUN_00a0e680;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831c70 @ 0x00831c70 ====

void FUN_00831c70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e6e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00831c90 @ 0x00831c90 ====

int FUN_00831c90(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999d40;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00831cf6 @ 0x00831cf6 ====

void Catch_00831cf6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00831d00 @ 0x00831d00 ====

void FUN_00831d00(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00831d6f @ 0x00831d6f ====

void Catch_00831d6f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00831d90 @ 0x00831d90 ====

void * FUN_00831d90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00831dfd @ 0x00831dfd ====

void Catch_00831dfd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00831e20 @ 0x00831e20 ====

void FUN_00831e20(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999d70;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00831e86 @ 0x00831e86 ====

void Catch_00831e86(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00831e90 @ 0x00831e90 ====

void FUN_00831e90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00831c90(param_1,param_2,param_3);
  return;
}


// ==== FUN_00831eb0 @ 0x00831eb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00831eb0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  float fVar4;
  int in_ECX;
  
  fVar4 = (float)*(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  fVar4 = fVar4 * DAT_0099d0ec;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x14))(fVar4,uVar3);
  }
  return;
}


// ==== FUN_00831f00 @ 0x00831f00 ====

uint FUN_00831f00(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00831eb0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00831f30 @ 0x00831f30 ====

undefined4 FUN_00831f30(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  return uVar1;
}


// ==== FUN_00831f80 @ 0x00831f80 ====

undefined4 FUN_00831f80(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_00831fb0 @ 0x00831fb0 ====

void FUN_00831fb0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0e700;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_00831d00();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_008323b0(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5d958 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d958 = in_ECX;
  return;
}


// ==== FUN_00832030 @ 0x00832030 ====

void FUN_00832030(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e700;
  DAT_00b5d958 = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 8))();
    (**(code **)(*DAT_00b5d95c + 8))(piVar3);
  }
  FUN_00832750();
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  if (_Memory == (void *)in_ECX[3]) {
    _free((void *)in_ECX[3]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008320e0 @ 0x008320e0 ====

undefined1 FUN_008320e0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  undefined1 uStack_4;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))();
  uStack_10 = *puVar1;
  piStack_c = param_1;
  FUN_00832520(auStack_8,&uStack_10);
  return uStack_4;
}


// ==== FUN_00832130 @ 0x00832130 ====

int FUN_00832130(int param_1,int param_2,undefined4 param_3)

{
  FUN_00831e20(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00832160 @ 0x00832160 ====

void FUN_00832160(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d80;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_00831e90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00832130(uVar5,param_2,&local_18);
      FUN_00831e90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00831c90(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00832130(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00831c90(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008322c1 @ 0x008322c1 ====

void Catch_008322c1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_008323b0 @ 0x008323b0 ====

void FUN_008323b0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999d90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_00832130(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00832444 @ 0x00832444 ====

void Catch_00832444(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00832460 @ 0x00832460 ====

void FUN_00832460(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_00832160(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_008324d0 @ 0x008324d0 ====

/* WARNING: Removing unreachable block (ram,0x008324eb) */
/* WARNING: Removing unreachable block (ram,0x008324f0) */
/* WARNING: Removing unreachable block (ram,0x008324fe) */

void FUN_008324d0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00832160(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00832520 @ 0x00832520 ====

/* WARNING: Removing unreachable block (ram,0x00832608) */

void FUN_00832520(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_00832460(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_00831d90(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00832750 @ 0x00832750 ====

void FUN_00832750(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_008324d0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008327b0 @ 0x008327b0 ====

void FUN_008327b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00832030();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008327d0 @ 0x008327d0 ====

void FUN_008327d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e8dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008327f0 @ 0x008327f0 ====

void FUN_008327f0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00832810 @ 0x00832810 ====

void FUN_00832810(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_00832820 @ 0x00832820 ====

void FUN_00832820(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0e924;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d95c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d95c = in_ECX;
  }
  pvVar2 = operator_new(0x5118);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_00832900();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_00832870 @ 0x00832870 ====

void FUN_00832870(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e924;
  DAT_00b5d95c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0e8dc;
  return;
}


// ==== FUN_008328a0 @ 0x008328a0 ====

void FUN_008328a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e8ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008328c0 @ 0x008328c0 ====

void FUN_008328c0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0e904;
  iVar1 = 0x40;
  do {
    FUN_0083f600();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0x1441] = 0;
  return;
}


// ==== FUN_00832900 @ 0x00832900 ====

void FUN_00832900(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0e90c;
  FUN_008328c0();
  in_ECX[0x1442] = in_ECX[0x1442] + 0x40;
  in_ECX[0x1445] = in_ECX + 2;
  in_ECX[0x1443] = 0;
  in_ECX[0x1444] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[0x50] = puVar1 + 0x53;
    puVar1[0x51] = 0;
    puVar1[0x52] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x51;
  } while (iVar2 != 0);
  in_ECX[0x143f] = 0;
  in_ECX[0x1440] = 0;
  in_ECX[0x1441] = 0;
  return;
}


// ==== FUN_00832970 @ 0x00832970 ====

undefined4 FUN_00832970(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x510c);
}


// ==== FUN_00832980 @ 0x00832980 ====

void FUN_00832980(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0e904;
  iVar1 = 0x40;
  do {
    FUN_0083f2f0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008329d0 @ 0x008329d0 ====

void * FUN_008329d0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x140) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0e930,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x140) = *(int *)((int)param_2 + 0x140) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x5114);
  *(int *)(in_ECX + 0x510c) = *(int *)(in_ECX + 0x510c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x144);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0083f600();
    }
    *(undefined4 *)((int)pvVar2 + 0x13c) = *(undefined4 *)(in_ECX + 0x5110);
    *(void **)(in_ECX + 0x5110) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5114) = *(undefined4 *)((int)pvVar2 + 0x138);
  }
  *(int *)((int)pvVar2 + 0x140) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x138) = 0;
  FUN_0083f330();
  return pvVar2;
}


// ==== FUN_00832ab0 @ 0x00832ab0 ====

undefined4 FUN_00832ab0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x140) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0e930,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x140);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x140);
    }
    FUN_0083f250();
    *(undefined4 *)(param_2 + 0x138) = *(undefined4 *)(in_ECX + 0x5114);
    *(int *)(in_ECX + 0x510c) = *(int *)(in_ECX + 0x510c) + -1;
    *(int *)(in_ECX + 0x5114) = param_2;
  }
  return 0;
}


// ==== FUN_00832b40 @ 0x00832b40 ====

void FUN_00832b40(byte param_1)

{
  void *in_ECX;
  
  FUN_00832b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00832b60 @ 0x00832b60 ====

void FUN_00832b60(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0e90c;
  if (in_ECX[0x1443] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e7c0,
                         s_d__usa_24_0_1_2__develop_module__00a0e758,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x52;
  iVar3 = 0x40;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e840,
                           s_d__usa_24_0_1_2__develop_module__00a0e7d8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x51;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x1444];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0e904;
    iVar3 = 0x40;
    do {
      FUN_0083f2f0();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0e8ec;
    return;
  }
  if (*(int *)((int)_Memory + 0x140) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0e8c0,
                         s_d__usa_24_0_1_2__develop_module__00a0e858,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0083f2f0();
  _free(_Memory);
  return;
}


// ==== FUN_00832c80 @ 0x00832c80 ====

void FUN_00832c80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e924;
  DAT_00b5d95c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0e8dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00832cd0 @ 0x00832cd0 ====

void FUN_00832cd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e9dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00832cf0 @ 0x00832cf0 ====

void FUN_00832cf0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x19) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x19) == '\0');
  }
  return;
}


// ==== FUN_00832d10 @ 0x00832d10 ====

void FUN_00832d10(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x19) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x19);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x19);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x19);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x19);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00832d60 @ 0x00832d60 ====

void FUN_00832d60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_00832d60(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00832da0 @ 0x00832da0 ====

void * FUN_00832da0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999da0;
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


// ==== Catch@00832e15 @ 0x00832e15 ====

void Catch_00832e15(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00832e30 @ 0x00832e30 ====

void FUN_00832e30(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999db0;
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


// ==== Catch@00832eba @ 0x00832eba ====

void Catch_00832eba(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00832ed0 @ 0x00832ed0 ====

void FUN_00832ed0(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0059a580(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(int *)(iVar1 + 0xc) <= *param_2) &&
       ((*(int *)(iVar1 + 0xc) < *param_2 || (*(ushort *)(iVar1 + 0x10) <= *(ushort *)(param_2 + 1))
        ))) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00832f30 @ 0x00832f30 ====

void FUN_00832f30(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00832da0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00833035:
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
      if ((char)piVar6[6] == '\0') goto LAB_00833035;
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


// ==== FUN_00833110 @ 0x00833110 ====

void FUN_00833110(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00832d60(piVar6[1]);
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


// ==== FUN_008331d0 @ 0x008331d0 ====

void FUN_008331d0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    uVar3 = (**(code **)(*param_1 + 4))();
    FUN_00832ed0(&param_1,uVar3);
    piVar2 = param_1;
    if (param_1 != *(int **)(in_ECX + 8)) {
      piVar1 = (int *)param_1[5];
      iVar4 = (**(code **)(*piVar1 + 0x18))();
      if (iVar4 == 0) {
        FUN_00850bf0(&param_1,piVar2);
        (**(code **)*piVar1)(1);
      }
    }
  }
  return;
}


// ==== FUN_00833230 @ 0x00833230 ====

int * FUN_00833230(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  int in_ECX;
  undefined1 auStack_14 [8];
  undefined4 uStack_c;
  undefined4 uStack_8;
  int *piStack_4;
  
  puVar1 = param_1;
  FUN_00832ed0(&param_1,param_1);
  if (param_1 != *(undefined4 **)(in_ECX + 8)) {
    piVar3 = (int *)param_1[5];
    (**(code **)(*piVar3 + 0x14))();
    return piVar3;
  }
  pvVar2 = operator_new(0x58);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00840130();
  }
  FUN_0083ff10(puVar1);
  (**(code **)(*piVar3 + 0x14))();
  uStack_c = *puVar1;
  uStack_8 = puVar1[1];
  piStack_4 = piVar3;
  FUN_00833370(auStack_14,&uStack_c);
  return piVar3;
}


// ==== FUN_008332d0 @ 0x008332d0 ====

void FUN_008332d0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a0e9ec;
  DAT_00b5d954 = 0;
  FUN_00833110(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00833320 @ 0x00833320 ====

void FUN_00833320(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e9ec;
  iVar1 = FUN_00832e30();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d954 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d954 = in_ECX;
  return;
}


// ==== FUN_00833370 @ 0x00833370 ====

void FUN_00833370(undefined4 *param_1,int *param_2)

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
         ((*param_2 <= (int)puVar4[3] && (*(ushort *)(param_2 + 1) < *(ushort *)(puVar4 + 4))))) {
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
      goto LAB_008333c5;
    }
    FUN_004b83a0();
  }
  if ((*piVar2 <= param_2[3]) &&
     ((*piVar2 < param_2[3] || (*(ushort *)(piVar2 + 1) <= *(ushort *)(param_2 + 4))))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_008333c5:
  puVar4 = (undefined4 *)FUN_00832f30(&param_2,local_4,puVar4,piVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00833440 @ 0x00833440 ====

void FUN_00833440(byte param_1)

{
  void *in_ECX;
  
  FUN_008332d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00833460 @ 0x00833460 ====

void FUN_00833460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ea3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00833480 @ 0x00833480 ====

void FUN_00833480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ea4c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afe4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afe4 = in_ECX;
  return;
}


// ==== FUN_008334b0 @ 0x008334b0 ====

undefined4 FUN_008334b0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d964 + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d964 + 8))();
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5d960 + 8))(piVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)(*DAT_00b5d964 + 8))(piVar2);
  }
  return 0;
}


// ==== FUN_00833510 @ 0x00833510 ====

undefined4 FUN_00833510(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d960 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0xc))();
  (**(code **)(*DAT_00b5d964 + 8))(piVar1);
  return 1;
}


// ==== FUN_00833570 @ 0x00833570 ====

void FUN_00833570(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afe4 = 0;
  *in_ECX = &PTR_FUN_00a0ea3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008335a0 @ 0x008335a0 ====

void FUN_008335a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ea9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008335c0 @ 0x008335c0 ====

void FUN_008335c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = *param_3;
  in_ECX[3] = param_3[1];
  return;
}


// ==== FUN_008335f0 @ 0x008335f0 ====

void FUN_008335f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_1 = *param_3;
  }
  return;
}


// ==== FUN_00833610 @ 0x00833610 ====

int FUN_00833610(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999dc0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00833676 @ 0x00833676 ====

void Catch_00833676(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00833680 @ 0x00833680 ====

void FUN_00833680(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999dd0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008336ef @ 0x008336ef ====

void Catch_008336ef(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00833710 @ 0x00833710 ====

void * FUN_00833710(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999de0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0083377d @ 0x0083377d ====

void Catch_0083377d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008337a0 @ 0x008337a0 ====

void FUN_008337a0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999df0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00833806 @ 0x00833806 ====

void Catch_00833806(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00833810 @ 0x00833810 ====

void FUN_00833810(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00833610(param_1,param_2,param_3);
  return;
}


// ==== FUN_00833830 @ 0x00833830 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00833830(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  int in_ECX;
  
  fVar3 = (float)*(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  fVar3 = fVar3 * DAT_0099d0ec;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x10))(fVar3);
  }
  return;
}


// ==== FUN_00833880 @ 0x00833880 ====

uint FUN_00833880(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00833830(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_008338b0 @ 0x008338b0 ====

undefined4 FUN_008338b0(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  return uVar1;
}


// ==== FUN_00833900 @ 0x00833900 ====

undefined4 FUN_00833900(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_00833930 @ 0x00833930 ====

void FUN_00833930(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0eab4;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_00833680();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_00833dc0(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5d960 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d960 = in_ECX;
  return;
}


// ==== FUN_008339b0 @ 0x008339b0 ====

void FUN_008339b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0eab4;
  DAT_00b5d960 = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 0xc))();
    (**(code **)(*DAT_00b5d964 + 8))(piVar3);
  }
  FUN_00834160();
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  if (_Memory == (void *)in_ECX[3]) {
    _free((void *)in_ECX[3]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00833a60 @ 0x00833a60 ====

undefined1 FUN_00833a60(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  undefined1 uStack_4;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 8))();
  uStack_10 = *puVar1;
  piStack_c = param_1;
  FUN_00833f30(auStack_8,&uStack_10);
  return uStack_4;
}


// ==== FUN_00833ab0 @ 0x00833ab0 ====

int FUN_00833ab0(int param_1,int param_2,undefined4 param_3)

{
  FUN_008337a0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00833ae0 @ 0x00833ae0 ====

void FUN_00833ae0(uint param_1)

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
  
  if (0x1fffffffU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_00833b70 @ 0x00833b70 ====

void FUN_00833b70(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e00;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_00833810(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00833ab0(uVar5,param_2,&local_18);
      FUN_00833810(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00833610(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00833ab0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00833610(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00833cd1 @ 0x00833cd1 ====

void Catch_00833cd1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00833dc0 @ 0x00833dc0 ====

void FUN_00833dc0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_00833ab0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00833e54 @ 0x00833e54 ====

void Catch_00833e54(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00833e70 @ 0x00833e70 ====

void FUN_00833e70(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_00833b70(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00833ee0 @ 0x00833ee0 ====

/* WARNING: Removing unreachable block (ram,0x00833efb) */
/* WARNING: Removing unreachable block (ram,0x00833f00) */
/* WARNING: Removing unreachable block (ram,0x00833f0e) */

void FUN_00833ee0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00833b70(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00833f30 @ 0x00833f30 ====

/* WARNING: Removing unreachable block (ram,0x00834018) */

void FUN_00833f30(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_00833e70(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_00833710(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00834160 @ 0x00834160 ====

void FUN_00834160(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_00833ee0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008341c0 @ 0x008341c0 ====

void FUN_008341c0(byte param_1)

{
  void *in_ECX;
  
  FUN_008339b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008341e0 @ 0x008341e0 ====

void FUN_008341e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ec8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00834200 @ 0x00834200 ====

void FUN_00834200(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00834220 @ 0x00834220 ====

void FUN_00834220(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_00834230 @ 0x00834230 ====

void FUN_00834230(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0ecd4;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d964 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d964 = in_ECX;
  }
  pvVar2 = operator_new(0x62018);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_00834310();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_00834280 @ 0x00834280 ====

void FUN_00834280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ecd4;
  DAT_00b5d964 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0ec8c;
  return;
}


// ==== FUN_008342b0 @ 0x008342b0 ====

void FUN_008342b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ec9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008342d0 @ 0x008342d0 ====

void FUN_008342d0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0ecb4;
  iVar1 = 0x400;
  do {
    FUN_00841160();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0x18801] = 0;
  return;
}


// ==== FUN_00834310 @ 0x00834310 ====

void FUN_00834310(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0ecbc;
  FUN_008342d0();
  in_ECX[0x18802] = in_ECX[0x18802] + 0x400;
  in_ECX[0x18805] = in_ECX + 2;
  in_ECX[0x18803] = 0;
  in_ECX[0x18804] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x61] = puVar1 + 100;
    puVar1[0x62] = 0;
    puVar1[99] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x62;
  } while (iVar2 != 0);
  in_ECX[0x187ff] = 0;
  in_ECX[0x18800] = 0;
  in_ECX[0x18801] = 0;
  return;
}


// ==== FUN_00834380 @ 0x00834380 ====

undefined4 FUN_00834380(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x6200c);
}


// ==== FUN_00834390 @ 0x00834390 ====

void FUN_00834390(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0ecb4;
  iVar1 = 0x400;
  do {
    FUN_00841100();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008343e0 @ 0x008343e0 ====

void * FUN_008343e0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x184) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0ece0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x184) = *(int *)((int)param_2 + 0x184) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x62014);
  *(int *)(in_ECX + 0x6200c) = *(int *)(in_ECX + 0x6200c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x188);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_00841160();
    }
    *(undefined4 *)((int)pvVar2 + 0x180) = *(undefined4 *)(in_ECX + 0x62010);
    *(void **)(in_ECX + 0x62010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x62014) = *(undefined4 *)((int)pvVar2 + 0x17c);
  }
  *(int *)((int)pvVar2 + 0x184) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x17c) = 0;
  FUN_00840500();
  return pvVar2;
}


// ==== FUN_008344c0 @ 0x008344c0 ====

undefined4 FUN_008344c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x184) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0ece0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x184);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x184);
    }
    FUN_008402f0();
    *(undefined4 *)(param_2 + 0x17c) = *(undefined4 *)(in_ECX + 0x62014);
    *(int *)(in_ECX + 0x6200c) = *(int *)(in_ECX + 0x6200c) + -1;
    *(int *)(in_ECX + 0x62014) = param_2;
  }
  return 0;
}


// ==== FUN_00834550 @ 0x00834550 ====

void FUN_00834550(byte param_1)

{
  void *in_ECX;
  
  FUN_00834570();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00834570 @ 0x00834570 ====

void FUN_00834570(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0ecbc;
  if (in_ECX[0x18803] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0eb70,
                         s_d__usa_24_0_1_2__develop_module__00a0eb08,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 99;
  iVar3 = 0x400;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0ebf0,
                           s_d__usa_24_0_1_2__develop_module__00a0eb88,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x62;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x18804];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0ecb4;
    iVar3 = 0x400;
    do {
      FUN_00841100();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0ec9c;
    return;
  }
  if (*(int *)((int)_Memory + 0x184) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0ec70,
                         s_d__usa_24_0_1_2__develop_module__00a0ec08,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00841100();
  _free(_Memory);
  return;
}


// ==== FUN_00834690 @ 0x00834690 ====

void FUN_00834690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ecd4;
  DAT_00b5d964 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0ec8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008346e0 @ 0x008346e0 ====

void FUN_008346e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ed8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00834700 @ 0x00834700 ====

void FUN_00834700(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e20;
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


// ==== Catch@0083478a @ 0x0083478a ====

void Catch_0083478a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_008347a0 @ 0x008347a0 ====

void FUN_008347a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_008347a0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_00834800 @ 0x00834800 ====

void * FUN_00834800(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e30;
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


// ==== Catch@00834875 @ 0x00834875 ====

void Catch_00834875(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00834890 @ 0x00834890 ====

void FUN_00834890(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    uVar3 = (**(code **)(*param_1 + 4))();
    FUN_0069a470(&param_1,uVar3);
    piVar2 = param_1;
    if (param_1 != *(int **)(in_ECX + 8)) {
      puVar1 = (undefined4 *)param_1[10];
      iVar4 = FUN_00841590();
      if ((iVar4 == 0) && (FUN_005a4100(&param_1,piVar2), puVar1 != (undefined4 *)0x0)) {
        (**(code **)*puVar1)(1);
      }
    }
  }
  return;
}


// ==== FUN_008348f0 @ 0x008348f0 ====

undefined4 FUN_008348f0(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 8)) {
    uVar3 = *(undefined4 *)(param_1 + 0x28);
    FUN_00841580();
    return uVar3;
  }
  pvVar2 = operator_new(0x38);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_008416f0();
  }
  FUN_00841720(iVar1);
  FUN_00841580();
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = uVar3;
  FUN_00834d30(local_28,local_20);
  if (local_8 < 0x10) {
    return uVar3;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_008349b0 @ 0x008349b0 ====

void FUN_008349b0(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_00a0ed9c;
  DAT_00b5ac10 = 0;
  local_4 = in_ECX;
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0082c4f0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_008347a0(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  FUN_00834c70(&local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00834a40 @ 0x00834a40 ====

void FUN_00834a40(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ed9c;
  iVar1 = FUN_00834700();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac10 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac10 = in_ECX;
  return;
}


// ==== FUN_00834a90 @ 0x00834a90 ====

void FUN_00834a90(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00834800(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00834b95:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00834b95;
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


// ==== FUN_00834c70 @ 0x00834c70 ====

void FUN_00834c70(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_008347a0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x2d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x2d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_005a4100(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00834d30 @ 0x00834d30 ====

/* WARNING: Removing unreachable block (ram,0x00834d8f) */

void FUN_00834d30(undefined4 *param_1,undefined4 *param_2)

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
LAB_00834dc0:
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
        if (uVar5 == 0) goto LAB_00834dc0;
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
      puVar6 = (undefined4 *)FUN_00834a90(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_00834a90(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00834ea0 @ 0x00834ea0 ====

void FUN_00834ea0(byte param_1)

{
  void *in_ECX;
  
  FUN_008349b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00834ec0 @ 0x00834ec0 ====

void FUN_00834ec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0edec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00834ee0 @ 0x00834ee0 ====

void FUN_00834ee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0edfc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afe0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afe0 = in_ECX;
  return;
}


// ==== FUN_00834f10 @ 0x00834f10 ====

undefined4 FUN_00834f10(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d968 + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d968 + 8))();
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5afdc + 8))(piVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)(*DAT_00b5d968 + 8))(piVar2);
  }
  return 0;
}


// ==== FUN_00834f70 @ 0x00834f70 ====

undefined4 FUN_00834f70(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5afdc + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0xc))();
  (**(code **)(*DAT_00b5d968 + 8))(piVar1);
  return 1;
}


// ==== FUN_00834fd0 @ 0x00834fd0 ====

void FUN_00834fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afe0 = 0;
  *in_ECX = &PTR_FUN_00a0edec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835000 @ 0x00835000 ====

void FUN_00835000(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ee4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835020 @ 0x00835020 ====

undefined1 FUN_00835020(void)

{
  return 0;
}


// ==== FUN_00835030 @ 0x00835030 ====

undefined4 FUN_00835030(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  return uVar1;
}


// ==== FUN_00835080 @ 0x00835080 ====

undefined4 FUN_00835080(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_008350b0 @ 0x008350b0 ====

void FUN_008350b0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0ee64;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_008352a0();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_008356d0(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afdc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afdc = in_ECX;
  return;
}


// ==== FUN_00835130 @ 0x00835130 ====

void FUN_00835130(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ee64;
  DAT_00b5afdc = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 0xc))();
    (**(code **)(*DAT_00b5d968 + 8))(piVar3);
  }
  FUN_00835a70();
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  if (_Memory == (void *)in_ECX[3]) {
    _free((void *)in_ECX[3]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008351e0 @ 0x008351e0 ====

undefined1 FUN_008351e0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  undefined1 uStack_4;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 8))();
  uStack_10 = *puVar1;
  piStack_c = param_1;
  FUN_00835840(auStack_8,&uStack_10);
  return uStack_4;
}


// ==== FUN_00835230 @ 0x00835230 ====

int FUN_00835230(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999e40;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00835296 @ 0x00835296 ====

void Catch_00835296(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008352a0 @ 0x008352a0 ====

void FUN_008352a0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0083530f @ 0x0083530f ====

void Catch_0083530f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00835330 @ 0x00835330 ====

void * FUN_00835330(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0083539d @ 0x0083539d ====

void Catch_0083539d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008353c0 @ 0x008353c0 ====

void FUN_008353c0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999e70;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00835426 @ 0x00835426 ====

void Catch_00835426(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00835430 @ 0x00835430 ====

void FUN_00835430(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00835230(param_1,param_2,param_3);
  return;
}


// ==== FUN_00835450 @ 0x00835450 ====

int FUN_00835450(int param_1,int param_2,undefined4 param_3)

{
  FUN_008353c0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00835480 @ 0x00835480 ====

void FUN_00835480(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e80;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_00835430(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00835450(uVar5,param_2,&local_18);
      FUN_00835430(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00835230(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00835450(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00835230(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008355e1 @ 0x008355e1 ====

void Catch_008355e1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_008356d0 @ 0x008356d0 ====

void FUN_008356d0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999e90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_00835450(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00835764 @ 0x00835764 ====

void Catch_00835764(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00835780 @ 0x00835780 ====

void FUN_00835780(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_00835480(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_008357f0 @ 0x008357f0 ====

/* WARNING: Removing unreachable block (ram,0x0083580b) */
/* WARNING: Removing unreachable block (ram,0x00835810) */
/* WARNING: Removing unreachable block (ram,0x0083581e) */

void FUN_008357f0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00835480(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00835840 @ 0x00835840 ====

/* WARNING: Removing unreachable block (ram,0x00835928) */

void FUN_00835840(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_00835780(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_00835330(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00835a70 @ 0x00835a70 ====

void FUN_00835a70(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_008357f0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00835ad0 @ 0x00835ad0 ====

void FUN_00835ad0(byte param_1)

{
  void *in_ECX;
  
  FUN_00835130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835af0 @ 0x00835af0 ====

void FUN_00835af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f058;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835b10 @ 0x00835b10 ====

void FUN_00835b10(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00835b30 @ 0x00835b30 ====

void FUN_00835b30(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_00835b40 @ 0x00835b40 ====

void FUN_00835b40(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0f0a0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d968 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d968 = in_ECX;
  }
  pvVar2 = operator_new(0x5d018);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_00835c20();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_00835b90 @ 0x00835b90 ====

void FUN_00835b90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f0a0;
  DAT_00b5d968 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0f058;
  return;
}


// ==== FUN_00835bc0 @ 0x00835bc0 ====

void FUN_00835bc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f068;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835be0 @ 0x00835be0 ====

void FUN_00835be0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0f080;
  iVar1 = 0x400;
  do {
    FUN_008420f0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0x17401] = 0;
  return;
}


// ==== FUN_00835c20 @ 0x00835c20 ====

void FUN_00835c20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0f088;
  FUN_00835be0();
  in_ECX[0x17402] = in_ECX[0x17402] + 0x400;
  in_ECX[0x17405] = in_ECX + 2;
  in_ECX[0x17403] = 0;
  in_ECX[0x17404] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x5c] = puVar1 + 0x5f;
    puVar1[0x5d] = 0;
    puVar1[0x5e] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x5d;
  } while (iVar2 != 0);
  in_ECX[0x173ff] = 0;
  in_ECX[0x17400] = 0;
  in_ECX[0x17401] = 0;
  return;
}


// ==== FUN_00835c90 @ 0x00835c90 ====

undefined4 FUN_00835c90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x5d00c);
}


// ==== FUN_00835ca0 @ 0x00835ca0 ====

void FUN_00835ca0(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0f080;
  iVar1 = 0x400;
  do {
    FUN_00842050();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835cf0 @ 0x00835cf0 ====

void * FUN_00835cf0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x170) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0f0b0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x170) = *(int *)((int)param_2 + 0x170) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x5d014);
  *(int *)(in_ECX + 0x5d00c) = *(int *)(in_ECX + 0x5d00c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x174);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_008420f0();
    }
    *(undefined4 *)((int)pvVar2 + 0x16c) = *(undefined4 *)(in_ECX + 0x5d010);
    *(void **)(in_ECX + 0x5d010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5d014) = *(undefined4 *)((int)pvVar2 + 0x168);
  }
  *(int *)((int)pvVar2 + 0x170) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x168) = 0;
  FUN_008418a0();
  return pvVar2;
}


// ==== FUN_00835dd0 @ 0x00835dd0 ====

undefined4 FUN_00835dd0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x170) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0f0b0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x170);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x170);
    }
    FUN_00841800();
    *(undefined4 *)(param_2 + 0x168) = *(undefined4 *)(in_ECX + 0x5d014);
    *(int *)(in_ECX + 0x5d00c) = *(int *)(in_ECX + 0x5d00c) + -1;
    *(int *)(in_ECX + 0x5d014) = param_2;
  }
  return 0;
}


// ==== FUN_00835e60 @ 0x00835e60 ====

void FUN_00835e60(byte param_1)

{
  void *in_ECX;
  
  FUN_00835e80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835e80 @ 0x00835e80 ====

void FUN_00835e80(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0f088;
  if (in_ECX[0x17403] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0ef2c,
                         s_d__usa_24_0_1_2__develop_module__00a0eeb8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x5e;
  iVar3 = 0x400;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0efb4,
                           s_d__usa_24_0_1_2__develop_module__00a0ef40,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x5d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x17404];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0f080;
    iVar3 = 0x400;
    do {
      FUN_00842050();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0f068;
    return;
  }
  if (*(int *)((int)_Memory + 0x170) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0f03c,
                         s_d__usa_24_0_1_2__develop_module__00a0efc8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00842050();
  _free(_Memory);
  return;
}


// ==== FUN_00835fa0 @ 0x00835fa0 ====

void FUN_00835fa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f0a0;
  DAT_00b5d968 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0f058;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00835ff0 @ 0x00835ff0 ====

void FUN_00835ff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f168;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00836010 @ 0x00836010 ====

void FUN_00836010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f188;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b010 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b010 = in_ECX;
  return;
}


// ==== FUN_00836040 @ 0x00836040 ====

void FUN_00836040(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008427a0();
  }
  FUN_00842790(param_1);
  (**(code **)(*DAT_00b5afd4 + 4))(uVar2);
  return;
}


// ==== FUN_00836080 @ 0x00836080 ====

void FUN_00836080(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008428c0();
  }
  FUN_00842890(param_1);
  (**(code **)(*DAT_00b5afd4 + 4))(uVar2);
  return;
}


// ==== FUN_008360c0 @ 0x008360c0 ====

void FUN_008360c0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008429d0();
  }
  FUN_008429a0(param_1);
  (**(code **)(*DAT_00b5afd4 + 4))(uVar2);
  return;
}


// ==== FUN_00836100 @ 0x00836100 ====

void FUN_00836100(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00842ac0();
  }
  FUN_00842a90(param_1);
  (**(code **)(*DAT_00b5afd4 + 4))(uVar2);
  return;
}


// ==== FUN_00836140 @ 0x00836140 ====

void FUN_00836140(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00842bb0();
  }
  FUN_00842b80(param_1);
  (**(code **)(*DAT_00b5afd4 + 4))(uVar2);
  return;
}


// ==== FUN_00836180 @ 0x00836180 ====

void FUN_00836180(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5afd4 + 8))(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x008361a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*puVar1)();
  return;
}


// ==== FUN_008361d0 @ 0x008361d0 ====

void FUN_008361d0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5b010 = 0;
  *in_ECX = &PTR_FUN_00a0f168;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00836200 @ 0x00836200 ====

void FUN_00836200(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f204;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00836220 @ 0x00836220 ====

void FUN_00836220(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00836220(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00836260 @ 0x00836260 ====

void * FUN_00836260(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999ea0;
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


// ==== Catch@008362d5 @ 0x008362d5 ====

void Catch_008362d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008362f0 @ 0x008362f0 ====

void FUN_008362f0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999eb0;
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


// ==== Catch@0083637a @ 0x0083637a ====

void Catch_0083637a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00836390 @ 0x00836390 ====

void FUN_00836390(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_00842cc0();
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00836400 @ 0x00836400 ====

uint FUN_00836400(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00836390(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00836460 @ 0x00836460 ====

void FUN_00836460(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = param_1;
  if ((param_1 != 0) &&
     ((iVar1 = param_1 + 4, *(char *)(param_1 + 8) != '\x01' || (*(int *)(param_1 + 0xc) == 0)))) {
    FUN_0079bba0(&param_1,iVar1);
    if (param_1 != *(int *)(in_ECX + 0x14)) {
      FUN_0051a2a0(&param_1,param_1);
    }
    if (((*(char *)(iVar2 + 8) != '\x01') && (*(int *)(iVar2 + 0xc) == 0)) &&
       (FUN_0079bba0(&param_1,iVar1), iVar2 = param_1, param_1 != *(int *)(in_ECX + 8))) {
      if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x10))(1);
      }
      FUN_0051a2a0(&param_1,iVar2);
    }
  }
  return;
}


// ==== FUN_008364f0 @ 0x008364f0 ====

undefined4 FUN_008364f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_4;
  
  if (param_1 == 0) {
    return 0;
  }
  param_1 = *(undefined4 *)(param_1 + 4);
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if ((local_4 == *(int *)(in_ECX + 8)) || (iVar1 = *(int *)(local_4 + 0x10), iVar1 == 0)) {
    return 0;
  }
  uVar2 = FUN_00842cb0();
  FUN_00836460(iVar1);
  return uVar2;
}


// ==== FUN_00836550 @ 0x00836550 ====

void FUN_00836550(int param_1)

{
  int iVar1;
  int in_ECX;
  int local_4;
  
  if (param_1 != 0) {
    param_1 = *(undefined4 *)(param_1 + 4);
    local_4 = in_ECX;
    FUN_0079bba0(&local_4,&param_1);
    if ((local_4 != *(int *)(in_ECX + 8)) && (iVar1 = *(int *)(local_4 + 0x10), iVar1 != 0)) {
      FUN_00842c70();
      FUN_00836460(iVar1);
    }
  }
  return;
}


// ==== FUN_008365a0 @ 0x008365a0 ====

void FUN_008365a0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  int local_c;
  undefined1 local_8 [8];
  
  iVar2 = param_1;
  if ((((param_1 != 0) && (puVar1 = (undefined4 *)(param_1 + 4), *(char *)(param_1 + 8) != '\0')) &&
      (*(int *)(param_1 + 0xc) != 0)) &&
     (FUN_0079bba0(&param_1,puVar1), param_1 == *(int *)(in_ECX + 0x14))) {
    FUN_00842cc0();
    local_10 = *puVar1;
    local_c = iVar2;
    FUN_00836b80(local_8,&local_10);
  }
  return;
}


// ==== FUN_00836610 @ 0x00836610 ====

void FUN_00836610(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_00a0f220;
  local_4 = in_ECX;
  FUN_00836220(*(undefined4 *)(in_ECX[5] + 4));
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  in_ECX[6] = 0;
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)local_4 & 0xffffff00);
    FUN_00409660(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_00836220(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  DAT_00b5afd4 = 0;
  FUN_00836ac0(&local_4,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_008366f0 @ 0x008366f0 ====

int FUN_008366f0(int *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  int iStack_10;
  int iStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  param_1 = (int *)(**(code **)(*param_1 + 4))();
  FUN_0079bba0(&iStack_10,&param_1);
  if ((iStack_10 == *(int *)(in_ECX + 8)) || (iVar3 = *(int *)(iStack_10 + 0x10), iVar3 == 0)) {
    pvVar2 = operator_new(100);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00842db0();
    }
    FUN_00842d20(piVar1);
    iStack_10 = *(int *)(iVar3 + 4);
    iStack_c = iVar3;
    FUN_00836b80(auStack_8,&iStack_10);
  }
  else if (*(char *)(iVar3 + 8) != '\x01') {
    FUN_00842d20(piVar1);
    FUN_008365a0(iVar3);
    return iVar3;
  }
  return iVar3;
}


// ==== FUN_008367b0 @ 0x008367b0 ====

int FUN_008367b0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int in_ECX;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  FUN_0079bba0(&local_20,&param_1);
  if ((local_20 != *(int *)(in_ECX + 8)) && (iVar1 = *(int *)(local_20 + 0x10), iVar1 != 0)) {
    FUN_00842c60();
    FUN_008365a0(iVar1);
    return iVar1;
  }
  FUN_00401740(s__Effect_Not_Find_ID____x_00a0f1e0,0x18);
  uVar2 = FUN_00404230(local_1c);
  FUN_00403e50(uVar2);
  if (local_4 < 0x10) {
    return 0;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_00836860 @ 0x00836860 ====

void FUN_00836860(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f220;
  iVar1 = FUN_008362f0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  iVar1 = FUN_008362f0();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afd4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afd4 = in_ECX;
  return;
}


// ==== FUN_008368e0 @ 0x008368e0 ====

void FUN_008368e0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00836260(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_008369e5:
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
      if ((char)piVar6[5] == '\0') goto LAB_008369e5;
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


// ==== FUN_00836ac0 @ 0x00836ac0 ====

void FUN_00836ac0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00836220(piVar6[1]);
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


// ==== FUN_00836b80 @ 0x00836b80 ====

void FUN_00836b80(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_008368e0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_008368e0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00836c40 @ 0x00836c40 ====

void FUN_00836c40(byte param_1)

{
  void *in_ECX;
  
  FUN_00836610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00836c60 @ 0x00836c60 ====

void FUN_00836c60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f27c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00836c80 @ 0x00836c80 ====

undefined4 FUN_00836c80(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*DAT_00b5acf4 + 4))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  pvVar2 = operator_new(100);
  if (pvVar2 == (void *)0x0) {
    FUN_008430f0(param_1,iVar1);
    return 0;
  }
  uVar3 = FUN_00842f90();
  FUN_008430f0(param_1,iVar1);
  return uVar3;
}


// ==== FUN_00836ce0 @ 0x00836ce0 ====

void FUN_00836ce0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0f28c;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_00836ee0();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_00837310(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5d970 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d970 = in_ECX;
  return;
}


// ==== FUN_00836d60 @ 0x00836d60 ====

int FUN_00836d60(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int local_10;
  int local_c;
  undefined1 local_8 [8];
  
  FUN_00897340(&local_10,&param_1);
  iVar1 = param_1;
  if (local_10 != *(int *)(in_ECX + 0xc)) {
    return *(int *)(local_10 + 0xc);
  }
  iVar2 = FUN_00836c80(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  local_10 = iVar1;
  local_c = iVar2;
  FUN_00837480(local_8,&local_10);
  return iVar2;
}


// ==== FUN_00836dd0 @ 0x00836dd0 ====

void FUN_00836dd0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((undefined4 *)puVar2[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[3])(1);
    }
  }
  FUN_008376b0();
  return;
}


// ==== FUN_00836e00 @ 0x00836e00 ====

void FUN_00836e00(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f28c;
  DAT_00b5d970 = 0;
  puVar1 = (undefined4 *)in_ECX[3];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((undefined4 *)puVar2[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[3])(1);
    }
  }
  FUN_008376b0();
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    FUN_008984a0();
    *in_ECX = &PTR_FUN_00a0f27c;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00836e70 @ 0x00836e70 ====

int FUN_00836e70(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999ec0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00836ed6 @ 0x00836ed6 ====

void Catch_00836ed6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00836ee0 @ 0x00836ee0 ====

void FUN_00836ee0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999ed0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00836f4f @ 0x00836f4f ====

void Catch_00836f4f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00836f70 @ 0x00836f70 ====

void * FUN_00836f70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999ee0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00836fdd @ 0x00836fdd ====

void Catch_00836fdd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00837000 @ 0x00837000 ====

void FUN_00837000(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999ef0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00837066 @ 0x00837066 ====

void Catch_00837066(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00837070 @ 0x00837070 ====

void FUN_00837070(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00836e70(param_1,param_2,param_3);
  return;
}


// ==== FUN_00837090 @ 0x00837090 ====

int FUN_00837090(int param_1,int param_2,undefined4 param_3)

{
  FUN_00837000(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_008370c0 @ 0x008370c0 ====

void FUN_008370c0(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999f00;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_00837070(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00837090(uVar5,param_2,&local_18);
      FUN_00837070(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00836e70(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00837090(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00836e70(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00837221 @ 0x00837221 ====

void Catch_00837221(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00837310 @ 0x00837310 ====

void FUN_00837310(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999f10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_00837090(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008373a4 @ 0x008373a4 ====

void Catch_008373a4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008373c0 @ 0x008373c0 ====

void FUN_008373c0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_008370c0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00837430 @ 0x00837430 ====

/* WARNING: Removing unreachable block (ram,0x0083744b) */
/* WARNING: Removing unreachable block (ram,0x00837450) */
/* WARNING: Removing unreachable block (ram,0x0083745e) */

void FUN_00837430(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_008370c0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00837480 @ 0x00837480 ====

/* WARNING: Removing unreachable block (ram,0x00837568) */

void FUN_00837480(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_008373c0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_00836f70(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_008376b0 @ 0x008376b0 ====

void FUN_008376b0(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_00837430(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00837710 @ 0x00837710 ====

void FUN_00837710(byte param_1)

{
  void *in_ECX;
  
  FUN_00836e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00837730 @ 0x00837730 ====

void FUN_00837730(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f2dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00837750 @ 0x00837750 ====

undefined4 * FUN_00837750(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x50);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_00844090();
  }
  cVar1 = FUN_008440b0(param_1,param_2);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_008377a0 @ 0x008377a0 ====

undefined4 * FUN_008377a0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x34);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_00844350();
  }
  cVar1 = FUN_00844370(param_1,param_2);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_008377f0 @ 0x008377f0 ====

undefined4 * FUN_008377f0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x5c);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_008445b0();
  }
  cVar1 = FUN_008445e0(param_1,param_2);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_00837840 @ 0x00837840 ====

undefined4 * FUN_00837840(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar2 = operator_new(0x94);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_00844710();
  }
  cVar1 = FUN_00844730(param_1,param_2);
  if (cVar1 != '\0') {
    return puVar3;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_00837890 @ 0x00837890 ====

int FUN_00837890(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999f20;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@008378f6 @ 0x008378f6 ====

void Catch_008378f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00837900 @ 0x00837900 ====

undefined4 FUN_00837900(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5acf0 + 4))(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    switch(*puVar1) {
    case 1:
      uVar2 = FUN_008377a0(param_1,puVar1);
      return uVar2;
    case 6:
      uVar2 = FUN_008377f0(param_1,puVar1);
      return uVar2;
    case 7:
      uVar2 = FUN_00837840(param_1,puVar1);
      return uVar2;
    case 0xb:
      uVar2 = FUN_00837750(param_1,puVar1);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00837990 @ 0x00837990 ====

/* WARNING: Removing unreachable block (ram,0x008379d5) */

void FUN_00837990(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uStack_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((undefined4 *)puVar2[9] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[9])(1);
    }
  }
  FUN_0059c2f0();
  uStack_4 = *(undefined4 *)(in_ECX + 0xc);
  if (*(int *)(in_ECX + 0x18) != *(int *)(in_ECX + 0x1c)) {
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x18);
  }
  FUN_00837ce0(*(undefined4 *)(in_ECX + 0x18),9,&uStack_4);
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(in_ECX + 0x28) = 1;
  return;
}


// ==== FUN_00837a10 @ 0x00837a10 ====

void FUN_00837a10(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0f2ec;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_00837b90();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_00837f30(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5d96c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d96c = in_ECX;
  return;
}


// ==== FUN_00837a90 @ 0x00837a90 ====

void FUN_00837a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f2ec;
  DAT_00b5d96c = 0;
  FUN_00837990();
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    FUN_0059c2f0();
    _free((void *)in_ECX[3]);
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00837af0 @ 0x00837af0 ====

int FUN_00837af0(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  int local_4;
  
  iVar1 = param_1;
  FUN_0041ec50(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 0xc)) {
    return *(int *)(param_1 + 0x24);
  }
  iVar2 = FUN_00837900(iVar1);
  if (iVar2 == 0) {
    return 0;
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = iVar2;
  FUN_008380e0(local_28,local_20);
  if (local_8 < 0x10) {
    return iVar2;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_00837b90 @ 0x00837b90 ====

void FUN_00837b90(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999f30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00837bff @ 0x00837bff ====

void Catch_00837bff(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00837c20 @ 0x00837c20 ====

void FUN_00837c20(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999f40;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00837c86 @ 0x00837c86 ====

void Catch_00837c86(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00837c90 @ 0x00837c90 ====

void FUN_00837c90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00837890(param_1,param_2,param_3);
  return;
}


// ==== FUN_00837cb0 @ 0x00837cb0 ====

int FUN_00837cb0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00837c20(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00837ce0 @ 0x00837ce0 ====

void FUN_00837ce0(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999f50;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_00837c90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00837cb0(uVar5,param_2,&local_18);
      FUN_00837c90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00837890(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00837cb0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00837890(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00837e41 @ 0x00837e41 ====

void Catch_00837e41(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00837f30 @ 0x00837f30 ====

void FUN_00837f30(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999f60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_00837cb0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00837fc4 @ 0x00837fc4 ====

void Catch_00837fc4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00837fe0 @ 0x00837fe0 ====

void FUN_00837fe0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_00837ce0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00838050 @ 0x00838050 ====

void * FUN_00838050(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999f70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0056c180(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@008380bd @ 0x008380bd ====

void Catch_008380bd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008380e0 @ 0x008380e0 ====

/* WARNING: Removing unreachable block (ram,0x008381fb) */
/* WARNING: Removing unreachable block (ram,0x008383ef) */

void FUN_008380e0(int *param_1,int param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  bool bVar16;
  
  uVar5 = *(uint *)(in_ECX + 0x24);
  if (uVar5 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar5 < iVar4 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar5) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar4 * 2 + -3;
      FUN_00837fe0(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar5 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar8 = *(undefined4 **)(uVar5 * 4 + *(int *)(in_ECX + 0x14));
    if (puVar8 != *(undefined4 **)(uVar5 * 4 + *(int *)(in_ECX + 0x14) + 4)) {
      do {
        uVar10 = puVar8[7];
        uVar9 = 0xdeadbeef;
        if (uVar10 != 0) {
          iVar4 = (uVar10 >> 4) + 1;
          uVar7 = 0;
          do {
            if ((uint)puVar8[8] < 0x10) {
              puVar12 = puVar8 + 3;
            }
            else {
              puVar12 = (undefined4 *)puVar8[3];
            }
            pcVar1 = (char *)((int)puVar12 + uVar7);
            uVar7 = uVar7 + iVar4;
            uVar9 = uVar9 + (int)*pcVar1;
          } while (uVar7 <= uVar10 - iVar4);
        }
        if ((uVar9 & *(uint *)(in_ECX + 0x20)) == uVar5) {
          puVar12 = (undefined4 *)*puVar8;
        }
        else {
          puVar12 = (undefined4 *)*puVar8;
          if (puVar12 != *(undefined4 **)(in_ECX + 8)) {
            iVar4 = uVar5 * 4;
            puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            uVar10 = uVar5;
            while ((puVar8 == puVar2 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4) = puVar12, uVar10 != 0))) {
              uVar10 = uVar10 - 1;
              iVar4 = uVar10 * 4;
              puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            }
            iVar4 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar8[1] = puVar12;
            *(int *)puVar12[1] = iVar4;
            **(undefined4 **)(iVar4 + 4) = puVar8;
            uVar3 = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar4 + 4) = puVar12[1];
            puVar12[1] = puVar8[1];
            puVar8[1] = uVar3;
            puVar8 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar10 = *(uint *)(in_ECX + 0x24);
              (uVar5 < uVar10 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar10 * 4) == *(int *)(in_ECX + 8)));
              uVar10 = uVar10 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar10 * 4) = puVar8;
          }
          if (puVar12 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar8 = puVar12;
      } while (puVar12 != *(undefined4 **)(uVar5 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar5 = *(uint *)(param_2 + 0x14);
  uVar10 = 0xdeadbeef;
  if (uVar5 != 0) {
    iVar4 = (uVar5 >> 4) + 1;
    uVar9 = 0;
    do {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        puVar8 = (undefined4 *)(param_2 + 4);
      }
      else {
        puVar8 = *(undefined4 **)(param_2 + 4);
      }
      pcVar1 = (char *)((int)puVar8 + uVar9);
      uVar9 = uVar9 + iVar4;
      uVar10 = uVar10 + (int)*pcVar1;
    } while (uVar9 <= uVar5 - iVar4);
  }
  uVar10 = *(uint *)(in_ECX + 0x20) & uVar10;
  if (*(uint *)(in_ECX + 0x24) <= uVar10) {
    uVar10 = uVar10 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar4 = uVar10 * 4;
  piVar11 = *(int **)(iVar4 + 4 + *(int *)(in_ECX + 0x14));
  if (piVar11 != *(int **)(iVar4 + *(int *)(in_ECX + 0x14))) {
    do {
      piVar11 = (int *)piVar11[1];
      if ((uint)piVar11[8] < 0x10) {
        pbVar14 = (byte *)(piVar11 + 3);
      }
      else {
        pbVar14 = (byte *)piVar11[3];
      }
      uVar9 = *(uint *)(param_2 + 0x14);
      if (uVar5 < *(uint *)(param_2 + 0x14)) {
        uVar9 = uVar5;
      }
      if (uVar9 == 0) {
LAB_00838344:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_00838354;
        }
      }
      else {
        uVar7 = piVar11[7];
        if (uVar9 < (uint)piVar11[7]) {
          uVar7 = uVar9;
        }
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          pbVar13 = (byte *)(param_2 + 4);
        }
        else {
          pbVar13 = *(byte **)(param_2 + 4);
        }
        bVar15 = false;
        iVar6 = 0;
        bVar16 = true;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar15 = *pbVar13 < *pbVar14;
          bVar16 = *pbVar13 == *pbVar14;
          pbVar13 = pbVar13 + 1;
          pbVar14 = pbVar14 + 1;
        } while (bVar16);
        if (!bVar16) {
          iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        }
        bVar15 = iVar6 < 0;
        if (iVar6 == 0) goto LAB_00838344;
LAB_00838354:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_0083841c;
          uVar7 = uVar5;
          if (uVar9 < uVar5) {
            uVar7 = uVar9;
          }
          if ((uint)piVar11[8] < 0x10) {
            pbVar13 = (byte *)(piVar11 + 3);
          }
          else {
            pbVar13 = (byte *)piVar11[3];
          }
          bVar15 = false;
          iVar6 = 0;
          bVar16 = true;
          goto code_r0x0083840f;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_00838365;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x0083840f:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_0083841c:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_0083842d;
    }
  }
  else {
LAB_0083842d:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_00838365:
  iVar6 = FUN_00838050(piVar11,piVar11[1],param_2);
  FUN_0059c010(1);
  piVar11[1] = iVar6;
  **(int **)(iVar6 + 4) = iVar6;
  iVar6 = piVar11[1];
  if (piVar11 == *(int **)(*(int *)(in_ECX + 0x14) + iVar4)) {
    do {
      *(int *)(*(int *)(in_ECX + 0x14) + iVar4) = iVar6;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      iVar4 = uVar10 * 4;
    } while (piVar11 == *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  *param_1 = iVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00838450 @ 0x00838450 ====

void FUN_00838450(byte param_1)

{
  void *in_ECX;
  
  FUN_00837a90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00838470 @ 0x00838470 ====

void FUN_00838470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f370;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00838490 @ 0x00838490 ====

void FUN_00838490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f398;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008384b0 @ 0x008384b0 ====

void FUN_008384b0(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x008384b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_008384c0 @ 0x008384c0 ====

void FUN_008384c0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_008384d0 @ 0x008384d0 ====

void FUN_008384d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x31) = param_1;
  return;
}


// ==== FUN_008384e0 @ 0x008384e0 ====

int FUN_008384e0(void)

{
  int in_ECX;
  
  return in_ECX + 0x30;
}


// ==== FUN_008384f0 @ 0x008384f0 ====

bool FUN_008384f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = *(undefined4 *)(in_ECX + 4);
  local_14 = *(undefined4 *)(in_ECX + 8);
  local_10 = *(undefined4 *)(in_ECX + 0xc);
  local_c = *(undefined4 *)(in_ECX + 0x10);
  local_8 = *(undefined4 *)(in_ECX + 0x14);
  local_4 = *(undefined4 *)(in_ECX + 0x18);
  iVar1 = FUN_0040f630(&local_18,&local_c,param_1);
  return iVar1 != 1;
}


// ==== FUN_00838540 @ 0x00838540 ====

undefined4 FUN_00838540(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*(int *)(in_ECX + -0x24) + 8))();
  return *(undefined4 *)(iVar1 + 4);
}


// ==== FUN_00838550 @ 0x00838550 ====

void FUN_00838550(void)

{
  return;
}


// ==== FUN_00838560 @ 0x00838560 ====

void FUN_00838560(void)

{
  return;
}


// ==== FUN_00838570 @ 0x00838570 ====

void FUN_00838570(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x1b8) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  return;
}


// ==== FUN_008385a0 @ 0x008385a0 ====

void FUN_008385a0(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  if ((char)in_ECX[10] != '\0') {
    iVar1 = *DAT_00b5afac;
    iVar2 = (**(code **)(*in_ECX + 8))(2);
    (**(code **)(iVar1 + 8))(*(undefined4 *)(iVar2 + 4));
    iVar1 = *DAT_00b5a720;
    iVar2 = (**(code **)(*in_ECX + 8))();
    (**(code **)(iVar1 + 8))(*(undefined4 *)(iVar2 + 4));
    (**(code **)(*DAT_00b5d920 + 8))(in_ECX[0x6e]);
    in_ECX[0x6e] = 0;
    *(undefined1 *)(in_ECX + 10) = 0;
  }
  return;
}


// ==== FUN_00838600 @ 0x00838600 ====

int * FUN_00838600(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + -0x14);
  fVar2 = *(float *)(in_ECX + -0x10);
  fVar3 = *(float *)(in_ECX + -8);
  *param_1 = (int)*(float *)(in_ECX + -0x1c);
  param_1[1] = (int)fVar1;
  param_1[2] = (int)fVar2 + 1;
  param_1[3] = (int)fVar3 + 1;
  return param_1;
}


// ==== FUN_00838670 @ 0x00838670 ====

uint FUN_00838670(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  uint in_EAX;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar5 = param_1;
  if (*(char *)(in_ECX + 0xc) == '\0') {
    return in_EAX & 0xffffff00;
  }
  local_48 = *(undefined4 *)(in_ECX + -0x10);
  local_44 = *(undefined4 *)(in_ECX + -0xc);
  local_40 = *(undefined4 *)(in_ECX + -8);
  local_3c = *(undefined4 *)(in_ECX + -0x1c);
  local_38 = *(undefined4 *)(in_ECX + -0x18);
  local_34 = *(undefined4 *)(in_ECX + -0x14);
  local_30 = *(undefined4 *)(in_ECX + -0x10);
  local_2c = *(undefined4 *)(in_ECX + -0xc);
  local_28 = *(undefined4 *)(in_ECX + -8);
  puVar1 = param_1 + 3;
  uVar4 = FUN_0040dfb0(puVar1,&local_3c,&local_48,&param_1);
  if ((char)uVar4 == '\0') {
    *(undefined4 *)(in_ECX + 0x180) = *(undefined4 *)(in_ECX + 0xc0);
    return uVar4;
  }
  puVar8 = local_24;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar5 = (undefined4 *)FUN_0040e920(&local_3c,puVar1,in_ECX + 0x104);
  iVar7 = param_2;
  local_24[3] = *puVar5;
  local_14 = puVar5[1];
  local_10 = puVar5[2];
  local_c = puVar5[3];
  local_8 = puVar5[4];
  local_4 = puVar5[5];
  cVar3 = (**(code **)(**(int **)(in_ECX + 0x194) + 0x10))(local_24,param_2);
  if (cVar3 == '\0') {
    *(uint *)(in_ECX + 0x180) = *(uint *)(in_ECX + 0xc0);
    return *(uint *)(in_ECX + 0xc0) & 0xffffff00;
  }
  iVar6 = iVar7 + 8;
  thunk_FUN_0079e5a0(iVar6,iVar6,in_ECX + 0xc4);
  iVar6 = (**(code **)(*(int *)(in_ECX + -0x24) + 8))();
  uVar2 = *(undefined4 *)(iVar6 + 4);
  *(undefined4 *)(iVar7 + 4) = uVar2;
  *(undefined4 *)(in_ECX + 0x180) = 0x90ffe0ff;
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


// ==== FUN_008387d0 @ 0x008387d0 ====

void FUN_008387d0(void)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int in_ECX;
  uint uVar6;
  float unaff_ESI;
  undefined4 uVar7;
  float fVar8;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_10;
  float afStack_c [3];
  
  fVar8 = DAT_009b0318;
  local_30 = DAT_0099d0b4;
  pfVar1 = (float *)(in_ECX + 8);
  *pfVar1 = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar8;
  *(float *)(in_ECX + 0x10) = fVar8;
  pfVar2 = (float *)(in_ECX + 0x14);
  local_2c = local_30;
  *pfVar2 = local_30;
  local_28 = local_30;
  *(float *)(in_ECX + 0x18) = local_30;
  *(float *)(in_ECX + 0x1c) = local_30;
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x1b8) + 8))();
  if (iVar3 != 0) {
    uVar4 = FUN_004b9c10();
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        iVar3 = FUN_004ba010(uVar6);
        if (iVar3 != 0) {
          if (*(float *)(iVar3 + 0x10) < *pfVar1 || *(float *)(iVar3 + 0x10) == *pfVar1) {
            fVar8 = *(float *)(iVar3 + 0x10);
          }
          else {
            fVar8 = *pfVar1;
          }
          *pfVar1 = fVar8;
          if (*(float *)(iVar3 + 0x14) < *(float *)(in_ECX + 0xc) ||
              *(float *)(iVar3 + 0x14) == *(float *)(in_ECX + 0xc)) {
            uVar7 = *(undefined4 *)(iVar3 + 0x14);
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0xc);
          }
          *(undefined4 *)(in_ECX + 0xc) = uVar7;
          if (*(float *)(iVar3 + 0x18) < *(float *)(in_ECX + 0x10) ||
              *(float *)(iVar3 + 0x18) == *(float *)(in_ECX + 0x10)) {
            uVar7 = *(undefined4 *)(iVar3 + 0x18);
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0x10);
          }
          *(undefined4 *)(in_ECX + 0x10) = uVar7;
          fVar8 = *pfVar2;
          if (fVar8 < *(float *)(iVar3 + 0x1c) || fVar8 == *(float *)(iVar3 + 0x1c)) {
            fVar8 = *(float *)(iVar3 + 0x1c);
          }
          *pfVar2 = fVar8;
          fVar8 = *(float *)(in_ECX + 0x18);
          if (fVar8 < *(float *)(iVar3 + 0x20) || fVar8 == *(float *)(iVar3 + 0x20)) {
            fVar8 = *(float *)(iVar3 + 0x20);
          }
          *(float *)(in_ECX + 0x18) = fVar8;
          fVar8 = *(float *)(in_ECX + 0x1c);
          if (fVar8 < *(float *)(iVar3 + 0x24) || fVar8 == *(float *)(iVar3 + 0x24)) {
            fVar8 = *(float *)(iVar3 + 0x24);
          }
          *(float *)(in_ECX + 0x1c) = fVar8;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    pfVar5 = (float *)FUN_0040f670(&fStack_24,pfVar1,in_ECX + 0xe8);
    *pfVar1 = *pfVar5;
    *(float *)(in_ECX + 0xc) = pfVar5[1];
    *(float *)(in_ECX + 0x10) = pfVar5[2];
    *(float *)(in_ECX + 0x14) = pfVar5[3];
    *(float *)(in_ECX + 0x18) = pfVar5[4];
    *(float *)(in_ECX + 0x1c) = pfVar5[5];
    local_30 = *pfVar2 - *pfVar1;
    fStack_24 = (*pfVar2 - *pfVar1) * DAT_0099d0b4 + *pfVar1;
    local_2c = *(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc);
    fStack_20 = (*(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc)) * DAT_0099d0b4 +
                *(float *)(in_ECX + 0xc);
    local_28 = *(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10);
    fStack_1c = (*(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10)) * DAT_0099d0b4 +
                *(float *)(in_ECX + 0x10);
    thunk_FUN_0079e1ba(afStack_c,&local_30);
    *(float *)(in_ECX + 0x198) = fStack_14 * unaff_ESI;
    *(float *)(in_ECX + 0x19c) = fStack_10 * unaff_ESI;
    *(float *)(in_ECX + 0x1a0) = afStack_c[0] * unaff_ESI;
    *(float *)(in_ECX + 0x168) = local_2c;
    uVar7 = DAT_0099d080;
    *(float *)(in_ECX + 0x16c) = local_28;
    *(float *)(in_ECX + 0x170) = fStack_24;
    *(undefined4 *)(in_ECX + 0x174) = uVar7;
    *(undefined4 *)(in_ECX + 0x178) = 0;
    *(undefined4 *)(in_ECX + 0x17c) = 0;
    *(undefined4 *)(in_ECX + 0x180) = 0;
    *(undefined4 *)(in_ECX + 0x184) = uVar7;
    *(undefined4 *)(in_ECX + 0x188) = 0;
    *(undefined4 *)(in_ECX + 0x18c) = 0;
    *(undefined4 *)(in_ECX + 400) = 0;
    *(undefined4 *)(in_ECX + 0x194) = uVar7;
  }
  return;
}


// ==== FUN_00838af0 @ 0x00838af0 ====

void FUN_00838af0(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_48 [2];
  undefined1 local_40 [40];
  
  local_48[0] = *(undefined4 *)(in_ECX + 0x2c);
  local_48[1] = *(undefined4 *)(in_ECX + 0x7c);
  thunk_FUN_0079fb96(local_40,in_ECX + 0x80);
  puVar2 = local_48;
  puVar3 = (undefined4 *)(in_ECX + 0xe8);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_0079f3a1(in_ECX + 0x128,0,(undefined4 *)(in_ECX + 0xe8));
  return;
}


// ==== FUN_00838b80 @ 0x00838b80 ====

void FUN_00838b80(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5a6b4 + 0x10))(in_ECX + 0x54,(undefined4 *)(in_ECX + 8));
  if (cVar1 == '\0') {
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  FUN_00838af0();
  FUN_008387d0();
  return;
}


// ==== FUN_00838bc0 @ 0x00838bc0 ====

void FUN_00838bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f400;
  in_ECX[1] = &PTR_FUN_00a0f3e8;
  in_ECX[9] = &PTR_FUN_00a0f3c0;
  (*(code *)PTR_FUN_00a0f40c)();
  if (0xf < (uint)in_ECX[0x36]) {
    _free((void *)in_ECX[0x31]);
    return;
  }
  in_ECX[0x36] = 0xf;
  in_ECX[0x35] = 0;
  *(undefined1 *)(in_ECX + 0x31) = 0;
  if (0xf < (uint)in_ECX[0x2f]) {
    _free((void *)in_ECX[0x2a]);
    return;
  }
  in_ECX[0x2f] = 0xf;
  in_ECX[0x2e] = 0;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  if (0xf < (uint)in_ECX[0x1d]) {
    _free((void *)in_ECX[0x18]);
    return;
  }
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  if ((uint)in_ECX[0x16] < 0x10) {
    in_ECX[0x16] = 0xf;
    in_ECX[0x15] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
    in_ECX[9] = &PTR_FUN_00a0f398;
    in_ECX[1] = &PTR_FUN_009bf514;
    *in_ECX = &PTR_FUN_00a0f370;
    return;
  }
  _free((void *)in_ECX[0x11]);
  return;
}


// ==== FUN_00838c90 @ 0x00838c90 ====

void FUN_00838c90(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009bf514;
  in_ECX[9] = &PTR_FUN_00a0f398;
  *in_ECX = &PTR_FUN_00a0f400;
  in_ECX[1] = &PTR_FUN_00a0f3e8;
  in_ECX[9] = &PTR_FUN_00a0f3c0;
  FUN_00839200();
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0xf;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0xf;
  *(undefined1 *)(in_ECX + 0x31) = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x6e] = 0;
  *(undefined1 *)((int)in_ECX + 0x29) = 0;
  in_ECX[0x37] = 0;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 8) = 1;
  return;
}


// ==== FUN_00838d20 @ 0x00838d20 ====

void FUN_00838d20(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  FUN_00401660(in_ECX + 0x40,0,0xffffffff);
  iVar1 = *(int *)(in_ECX + 0x90);
  if (iVar1 == 1) {
    *(undefined4 *)(in_ECX + 0x94) = 0xffffffff;
    FUN_00401740(s_MonID__d__Regen__d_00a0f334,0x12);
    uVar2 = FUN_00404230(local_1c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  else if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x94) = 0xffff00ff;
    FUN_00401740(s_NpcID__d_00a0f348,8);
    uVar2 = FUN_00404230(local_1c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  else if (iVar1 == 4) {
    *(undefined4 *)(in_ECX + 0x94) = 0xffffff00;
    FUN_00401830(s_BrickID__d__UID__d_00a0f354);
    uVar2 = FUN_00404230(local_1c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_00838e80 @ 0x00838e80 ====

undefined4 FUN_00838e80(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
  
  *(undefined4 *)(in_ECX + 0xe4) = 0x90ff60ff;
  FUN_008392e0(param_1);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(undefined4 *)(in_ECX + 0xe0) = uVar1;
  iVar2 = (**(code **)(*DAT_00b5d920 + 4))(param_1 + 0x2c,*(undefined4 *)(param_1 + 0x60));
  *(int *)(in_ECX + 0x1b8) = iVar2;
  if (iVar2 != 0) {
    (**(code **)(*(int *)(in_ECX + 0x24) + 0x10))();
    FUN_00838d20();
    (**(code **)(*DAT_00b5afac + 4))(*(undefined4 *)(in_ECX + 0x34),in_ECX + 4,2);
    (**(code **)(*DAT_00b5a720 + 4))(in_ECX + 0x24);
    *(undefined1 *)(in_ECX + 0x28) = 1;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x1b8) + 4))();
    if (iVar2 != 0) {
      return 1;
    }
    fVar3 = *(float *)(in_ECX + 0x19c) * DAT_0099d100;
    fVar4 = *(float *)(in_ECX + 0x1a0) * DAT_0099d100;
    *(float *)(in_ECX + 0x198) = *(float *)(in_ECX + 0x198) * DAT_0099d100;
    *(float *)(in_ECX + 0x19c) = fVar3;
    *(float *)(in_ECX + 0x1a0) = fVar4;
    *(undefined4 *)(in_ECX + 0xe4) = 0xffffffff;
  }
  return 0;
}


// ==== FUN_00838f90 @ 0x00838f90 ====

void FUN_00838f90(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_8;
  undefined1 local_7;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar1 + 1,0);
  iVar1 = *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar1 + -0x14) = 3;
  *(undefined4 *)(iVar1 + -0x1c) = 0;
  *(undefined4 *)(iVar1 + -0x20) = 0;
  *(undefined4 *)(iVar1 + -0x24) = 0;
  *(undefined4 *)(iVar1 + -0x28) = 0;
  *(undefined4 *)(iVar1 + -0x30) = 0;
  *(undefined4 *)(iVar1 + -0x34) = 0;
  *(undefined4 *)(iVar1 + -0x38) = 0;
  *(undefined4 *)(iVar1 + -0x3c) = 0;
  *(undefined4 *)(iVar1 + -0x44) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -0x4c) = 0;
  *(undefined4 *)(iVar1 + -0x50) = 0;
  local_50 = DAT_0099d080;
  *(undefined4 *)(iVar1 + -0x18) = DAT_0099d080;
  *(undefined4 *)(iVar1 + -0x2c) = local_50;
  *(undefined4 *)(iVar1 + -0x40) = local_50;
  *(undefined4 *)(iVar1 + -0x54) = local_50;
  *(undefined4 *)(iVar1 + -0x58) = 0;
  local_58 = 0;
  local_54 = 0xffffffff;
  local_4c = 0;
  local_4b = 0;
  local_8 = 0;
  local_7 = 0;
  uStack_60 = (**(code **)(**(int **)(in_ECX + 0x1b8) + 8))();
  uStack_5c = (**(code **)(**(int **)(in_ECX + 0x1b8) + 0xc))();
  FUN_005c1360(&uStack_60);
  return;
}


// ==== FUN_008390b0 @ 0x008390b0 ====

void FUN_008390b0(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x2c) != '\0') && (*(char *)(in_ECX + 0x1c) != '\x01')) {
    puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
    if (*(char *)(in_ECX + 0x2d) != '\0') {
      *(undefined4 *)(in_ECX + 0x94) = 0;
      *(float *)(in_ECX + 0x98) =
           SQRT(*(float *)(in_ECX + 0x19c) * *(float *)(in_ECX + 0x19c) +
                *(float *)(in_ECX + 0x198) * *(float *)(in_ECX + 0x198) +
                *(float *)(in_ECX + 0x194) * *(float *)(in_ECX + 0x194));
      *(undefined4 *)(in_ECX + 0x9c) = 0;
      puVar2[0x13] = in_ECX + 0x90;
    }
    puVar2[0xc] = 0;
    puVar2[0xb] = 0;
    puVar2[10] = DAT_009b6df4;
    uVar1 = DAT_0099d080;
    *(undefined1 *)(puVar2 + 9) = 1;
    *(undefined1 *)((int)puVar2 + 0x21) = 0xf0;
    *(undefined1 *)(puVar2 + 8) = 1;
    *(undefined1 *)((int)puVar2 + 0x26) = 0;
    *puVar2 = *(undefined4 *)(in_ECX + 0x74);
    puVar2[1] = *(undefined4 *)(in_ECX + 0x28);
    puVar2[2] = *(undefined4 *)(in_ECX + 0x78);
    puVar2[3] = *(undefined4 *)(in_ECX + 0x7c);
    puVar2[4] = *(undefined4 *)(in_ECX + 0x80);
    puVar2[5] = *(undefined4 *)(in_ECX + 0x84);
    puVar2[6] = *(undefined4 *)(in_ECX + 0x88);
    puVar2[7] = uVar1;
    FUN_00838f90(puVar2);
    (**(code **)(*param_1 + 0x98))(puVar2);
    (**(code **)(*param_1 + 0x94))(in_ECX + 0x164);
  }
  return;
}


// ==== FUN_008391e0 @ 0x008391e0 ====

void FUN_008391e0(void)

{
  FUN_008392c0();
  return;
}


// ==== FUN_008391f0 @ 0x008391f0 ====

void FUN_008391f0(void)

{
  FUN_008392c0();
  return;
}


// ==== FUN_00839200 @ 0x00839200 ====

void FUN_00839200(void)

{
  undefined1 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0xf;
  in_ECX[0x14] = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0xf;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  in_ECX[0x30] = 0;
  in_ECX[1] = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  local_8 = 0;
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x60) = 1;
  *in_ECX = 1;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  puVar1 = (undefined4 *)(in_ECX + 0x14);
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x28)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(&local_8,puVar1,*(int *)(in_ECX + 0x24) + (int)puVar2);
  puVar1 = (undefined4 *)(in_ECX + 0x30);
  if (*(uint *)(in_ECX + 0x44) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x44)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(&local_8,puVar1,*(int *)(in_ECX + 0x40) + (int)puVar2);
  return;
}


// ==== FUN_008392c0 @ 0x008392c0 ====

void FUN_008392c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00838bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008392e0 @ 0x008392e0 ====

void FUN_008392e0(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined2 *)(in_ECX + 2) = *(undefined2 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(in_ECX + 0xc) = *(undefined2 *)(param_1 + 0xc);
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  FUN_00401660(param_1 + 0x2c,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x60);
  return;
}


// ==== FUN_00839370 @ 0x00839370 ====

void FUN_00839370(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f468;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00839390 @ 0x00839390 ====

void FUN_00839390(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return;
}


// ==== FUN_008393a0 @ 0x008393a0 ====

undefined4 FUN_008393a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  }
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_008393c0 @ 0x008393c0 ====

int FUN_008393c0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_008393d0 @ 0x008393d0 ====

undefined4 FUN_008393d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_008393e0 @ 0x008393e0 ====

undefined4 FUN_008393e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_008393f0 @ 0x008393f0 ====

undefined4 FUN_008393f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00839400 @ 0x00839400 ====

undefined1 FUN_00839400(void)

{
  undefined1 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2c) == 0) {
    return 0;
  }
  uVar1 = FUN_008449e0();
  return uVar1;
}


// ==== FUN_00839420 @ 0x00839420 ====

void FUN_00839420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f484;
  in_ECX[1] = 0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_00839450 @ 0x00839450 ====

void FUN_00839450(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f484;
  if (in_ECX[9] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[9]);
    in_ECX[9] = 0;
  }
  if (in_ECX[10] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[10]);
    in_ECX[10] = 0;
  }
  _Memory = (void *)in_ECX[0xb];
  if (_Memory != (void *)0x0) {
    FUN_00844b60();
    _free(_Memory);
    return;
  }
  in_ECX[0xb] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_00a0f468;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_008394d0 @ 0x008394d0 ====

undefined4 FUN_008394d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6dc + 0x1c))(param_2,param_1);
  *(int *)(in_ECX + 0x30) = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_004236c0(iVar1);
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  uVar2 = FUN_00839580(*(int *)(in_ECX + 0x30) + 0x1c);
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  *(undefined4 *)(in_ECX + 4) = 0;
  pvVar3 = operator_new(0x24);
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00844bb0();
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  FUN_00844b10(*(undefined4 *)(in_ECX + 0x24));
  FUN_00401660(param_1,0,0xffffffff);
  return 1;
}


// ==== FUN_00839560 @ 0x00839560 ====

void FUN_00839560(byte param_1)

{
  void *in_ECX;
  
  FUN_00839450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00839580 @ 0x00839580 ====

undefined4 FUN_00839580(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_00b5a7cc;
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0x10;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_008395e0 @ 0x008395e0 ====

void FUN_008395e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f4e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00839600 @ 0x00839600 ====

void FUN_00839600(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00839602. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00839610 @ 0x00839610 ====

int FUN_00839610(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_00839620 @ 0x00839620 ====

void FUN_00839620(void)

{
  return;
}


// ==== FUN_00839630 @ 0x00839630 ====

void FUN_00839630(void)

{
  return;
}


// ==== FUN_00839640 @ 0x00839640 ====

void FUN_00839640(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x54) = param_1;
  return;
}


// ==== FUN_00839650 @ 0x00839650 ====

undefined4 FUN_00839650(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00839660 @ 0x00839660 ====

void FUN_00839660(undefined1 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x174) + 8))();
  if (*(char *)(iVar1 + 5) == '\x01') {
    *(undefined1 *)(in_ECX + 0xe8) = param_1;
  }
  return;
}


// ==== FUN_00839690 @ 0x00839690 ====

uint FUN_00839690(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  uint in_EAX;
  uint uVar5;
  undefined4 *puVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar6 = param_1;
  if ((*(char *)(in_ECX + 0x30) == '\0') || (*(char *)(in_ECX + 0xe4) == '\x01')) {
    return in_EAX & 0xffffff00;
  }
  local_48 = *(undefined4 *)(in_ECX + -0x10);
  local_44 = *(undefined4 *)(in_ECX + -0xc);
  local_40 = *(undefined4 *)(in_ECX + -8);
  local_3c = *(undefined4 *)(in_ECX + -0x1c);
  local_38 = *(undefined4 *)(in_ECX + -0x18);
  local_34 = *(undefined4 *)(in_ECX + -0x14);
  local_30 = *(undefined4 *)(in_ECX + -0x10);
  local_2c = *(undefined4 *)(in_ECX + -0xc);
  local_28 = *(undefined4 *)(in_ECX + -8);
  puVar1 = param_1 + 3;
  uVar5 = FUN_0040dfb0(puVar1,&local_3c,&local_48,&param_1);
  if ((char)uVar5 == '\0') {
    *(undefined4 *)(in_ECX + 0xe0) = *(undefined4 *)(in_ECX + 0xf0);
    return uVar5;
  }
  puVar8 = local_24;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar6 = (undefined4 *)FUN_0040e920(&local_3c,puVar1,in_ECX + 0x134);
  iVar7 = param_2;
  local_24[3] = *puVar6;
  local_14 = puVar6[1];
  local_10 = puVar6[2];
  local_c = puVar6[3];
  local_8 = puVar6[4];
  local_4 = puVar6[5];
  cVar4 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))(local_24,param_2);
  if (cVar4 == '\0') {
    *(uint *)(in_ECX + 0xe0) = *(uint *)(in_ECX + 0xf0);
    return *(uint *)(in_ECX + 0xf0) & 0xffffff00;
  }
  iVar2 = iVar7 + 8;
  thunk_FUN_0079e5a0(iVar2,iVar2,in_ECX + 0xf4);
  puVar6 = (undefined4 *)(**(code **)(*(int *)(in_ECX + -0x24) + 8))();
  uVar3 = *puVar6;
  *(undefined4 *)(iVar7 + 4) = uVar3;
  *(undefined4 *)(in_ECX + 0xf0) = *(undefined4 *)(in_ECX + 0xe0);
  *(undefined4 *)(in_ECX + 0xe0) = 0x90ffa0a0;
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


// ==== FUN_00839800 @ 0x00839800 ====

undefined1 FUN_00839800(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  undefined4 *unaff_retaddr;
  
  cVar1 = (**(code **)(*in_ECX + 0x1c))(param_1,&param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*(int *)in_ECX[0x5d] + 8))();
  *unaff_retaddr = *(undefined4 *)(iVar2 + 8);
  return 1;
}


// ==== FUN_00839870 @ 0x00839870 ====

void FUN_00839870(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  *(undefined1 *)(in_ECX + 0x10c) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  *(undefined4 *)(in_ECX + 0x198) = 0;
  *(undefined4 *)(in_ECX + 0x19c) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  *(undefined1 *)(in_ECX + 0x10d) = 0;
  *(undefined2 *)(in_ECX + 0x10a) = 0xff;
  *(undefined1 *)(in_ECX + 0x108) = 0;
  return;
}


// ==== FUN_008398c0 @ 0x008398c0 ====

void FUN_008398c0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) != '\0') {
    (**(code **)(*DAT_00b5afac + 8))(*(undefined4 *)(in_ECX + 0x34),2);
    (**(code **)(*DAT_00b5a720 + 8))(*(undefined4 *)(in_ECX + 0x34));
    (**(code **)(*DAT_00b5ac10 + 8))(*(undefined4 *)(in_ECX + 0x198));
    *(undefined4 *)(in_ECX + 0x198) = 0;
    (**(code **)(*DAT_00b5d930 + 8))(*(undefined4 *)(in_ECX + 0x19c));
    if (*(undefined4 **)(in_ECX + 0xc4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xc4))(1);
    }
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    *(undefined1 *)(in_ECX + 0x28) = 0;
  }
  return;
}


// ==== FUN_00839940 @ 0x00839940 ====

void FUN_00839940(float param_1)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    *(float *)(in_ECX + 0x78) = param_1 + *(float *)(in_ECX + 0x78);
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
    if (*(float *)(in_ECX + 0x78) < *(float *)(iVar1 + 0xc) * DAT_0099d0f8) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
      if (*(float *)(iVar1 + 0xc) <= *(float *)(in_ECX + 0x78)) {
        iVar1 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
        *(float *)(in_ECX + 0x78) = *(float *)(in_ECX + 0x78) - *(float *)(iVar1 + 0xc);
      }
    }
    else {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
      fVar2 = (float10)FUN_0040d0a0(0,*(undefined4 *)(iVar1 + 0xc));
      *(float *)(in_ECX + 0x78) = (float)fVar2;
    }
    if ((*(char *)(in_ECX + 0x20) == '\0') && (*(char *)(in_ECX + 0x54) != '\0')) {
      uVar4 = 0;
      uVar3 = 0x3f800000;
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))(0x3f800000,0);
      FUN_005ca8b0(*(float *)(in_ECX + 0x78) / *(float *)(iVar1 + 0xc),uVar3,uVar4);
    }
  }
  return;
}


// ==== FUN_00839a10 @ 0x00839a10 ====

undefined1 FUN_00839a10(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x174) == 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x174) + 4))();
  return *(undefined1 *)(iVar1 + 0x1c);
}


// ==== FUN_00839a30 @ 0x00839a30 ====

int * FUN_00839a30(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + -0x14);
  fVar2 = *(float *)(in_ECX + -0x10);
  fVar3 = *(float *)(in_ECX + -8);
  *param_1 = (int)*(float *)(in_ECX + -0x1c);
  param_1[1] = (int)fVar1;
  param_1[2] = (int)fVar2 + 1;
  param_1[3] = (int)fVar3 + 1;
  return param_1;
}


// ==== FUN_00839ac0 @ 0x00839ac0 ====

bool FUN_00839ac0(void)

{
  float fVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x108) != '\0') {
    iVar4 = (**(code **)(*DAT_00b5afb4 + 0x10))();
    piVar2 = DAT_00b5a988;
    if (*(char *)(iVar4 + 0xd8) == '\x02') {
      iVar4 = (**(code **)(*DAT_00b5afb4 + 0x10))();
      fVar1 = *(float *)(iVar4 + 0xd0);
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      if (fVar1 < *(float *)(iVar4 + 0x2c)) {
        return true;
      }
    }
  }
  cVar3 = (**(code **)(*DAT_00b5a988 + 0x24))
                    (*(float *)(in_ECX + 0x30) + DAT_009b0120,in_ECX + 0x58);
  return cVar3 == '\x01';
}


// ==== FUN_00839b50 @ 0x00839b50 ====

void FUN_00839b50(int param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  int in_ECX;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  sVar2 = FUN_00802534();
  *(undefined4 *)(in_ECX + 0x110) = uVar4;
  cVar1 = FUN_00839ac0();
  sVar3 = *(short *)(in_ECX + 0x10a);
  if (cVar1 != '\0') {
    sVar3 = sVar3 - sVar2;
    if (sVar3 < 0x100) {
      if (sVar3 < 0) {
        sVar3 = 0;
      }
    }
    else {
      sVar3 = 0xff;
    }
    *(short *)(in_ECX + 0x10a) = sVar3;
LAB_00839bca:
    *(undefined1 *)(param_1 + 0x23) = 1;
    *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(in_ECX + 0x10a);
    return;
  }
  if (*(char *)(in_ECX + 0x10c) == '\0') {
    sVar3 = sVar3 + sVar2;
    if (sVar3 < 0x100) {
      if (sVar3 < 0) {
        sVar3 = 0;
      }
    }
    else {
      sVar3 = 0xff;
    }
    *(short *)(in_ECX + 0x10a) = sVar3;
    if (0xfe < sVar3) {
      *(undefined1 *)(param_1 + 0x23) = 0;
      return;
    }
    goto LAB_00839bca;
  }
  if (sVar3 < 0x29) {
    sVar3 = sVar3 + sVar2;
    if (sVar3 < 0x29) {
      if (sVar3 < 0) {
        sVar3 = 0;
      }
      goto LAB_00839c1c;
    }
  }
  else {
    sVar3 = sVar3 - sVar2;
    if (0xff < sVar3) {
      sVar3 = 0xff;
      goto LAB_00839c1c;
    }
    if (0x27 < sVar3) goto LAB_00839c1c;
  }
  sVar3 = 0x28;
LAB_00839c1c:
  *(short *)(in_ECX + 0x10a) = sVar3;
  *(undefined1 *)(param_1 + 0x23) = 1;
  *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(in_ECX + 0x10a);
  return;
}


// ==== FUN_00839c80 @ 0x00839c80 ====

void FUN_00839c80(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0 [16];
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  uVar1 = *(undefined4 *)(in_ECX + 0x74);
  local_cc = *(undefined4 *)(in_ECX + 0x58);
  local_c8 = *(undefined4 *)(in_ECX + 0x2c);
  local_c4 = *(undefined4 *)(in_ECX + 0x5c);
  thunk_FUN_0079f761(local_c0,uVar1,uVar1,uVar1);
  puVar2 = local_c0;
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = (undefined4 *)FUN_005cd200(local_40,&local_cc,in_ECX + 0x60,local_80);
  puVar4 = (undefined4 *)(in_ECX + 0x118);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079f3a1(in_ECX + 0x158,0,(undefined4 *)(in_ECX + 0x118));
  return;
}


// ==== FUN_00839d20 @ 0x00839d20 ====

void FUN_00839d20(void)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int in_ECX;
  uint uVar6;
  float unaff_ESI;
  undefined4 uVar7;
  float fVar8;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_10;
  float afStack_c [3];
  
  fVar8 = DAT_009b0318;
  local_30 = DAT_0099d0b4;
  pfVar1 = (float *)(in_ECX + 8);
  *pfVar1 = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar8;
  *(float *)(in_ECX + 0x10) = fVar8;
  pfVar2 = (float *)(in_ECX + 0x14);
  local_2c = local_30;
  *pfVar2 = local_30;
  local_28 = local_30;
  *(float *)(in_ECX + 0x18) = local_30;
  *(float *)(in_ECX + 0x1c) = local_30;
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x198) + 0xc))();
  if (iVar3 != 0) {
    uVar4 = FUN_004b9c10();
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        iVar3 = FUN_004ba010(uVar6);
        if (iVar3 != 0) {
          if (*(float *)(iVar3 + 0x10) < *pfVar1 || *(float *)(iVar3 + 0x10) == *pfVar1) {
            fVar8 = *(float *)(iVar3 + 0x10);
          }
          else {
            fVar8 = *pfVar1;
          }
          *pfVar1 = fVar8;
          if (*(float *)(iVar3 + 0x14) < *(float *)(in_ECX + 0xc) ||
              *(float *)(iVar3 + 0x14) == *(float *)(in_ECX + 0xc)) {
            uVar7 = *(undefined4 *)(iVar3 + 0x14);
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0xc);
          }
          *(undefined4 *)(in_ECX + 0xc) = uVar7;
          if (*(float *)(iVar3 + 0x18) < *(float *)(in_ECX + 0x10) ||
              *(float *)(iVar3 + 0x18) == *(float *)(in_ECX + 0x10)) {
            uVar7 = *(undefined4 *)(iVar3 + 0x18);
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0x10);
          }
          *(undefined4 *)(in_ECX + 0x10) = uVar7;
          fVar8 = *pfVar2;
          if (fVar8 < *(float *)(iVar3 + 0x1c) || fVar8 == *(float *)(iVar3 + 0x1c)) {
            fVar8 = *(float *)(iVar3 + 0x1c);
          }
          *pfVar2 = fVar8;
          fVar8 = *(float *)(in_ECX + 0x18);
          if (fVar8 < *(float *)(iVar3 + 0x20) || fVar8 == *(float *)(iVar3 + 0x20)) {
            fVar8 = *(float *)(iVar3 + 0x20);
          }
          *(float *)(in_ECX + 0x18) = fVar8;
          fVar8 = *(float *)(in_ECX + 0x1c);
          if (fVar8 < *(float *)(iVar3 + 0x24) || fVar8 == *(float *)(iVar3 + 0x24)) {
            fVar8 = *(float *)(iVar3 + 0x24);
          }
          *(float *)(in_ECX + 0x1c) = fVar8;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
    if (*(char *)(iVar3 + 3) == '\x01') {
      *(undefined4 *)(in_ECX + 0x104) = 0x9090ff90;
    }
    else {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
      if (*(char *)(iVar3 + 3) == '\x02') {
        *(undefined4 *)(in_ECX + 0x104) = 0x90ff9090;
      }
      else {
        iVar3 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
        if (*(char *)(iVar3 + 3) == '\x03') {
          *(undefined4 *)(in_ECX + 0x104) = 0x909090ff;
        }
        else {
          *(undefined4 *)(in_ECX + 0x104) = 0x90e0e0e0;
        }
      }
    }
    pfVar5 = (float *)FUN_0040f670(&fStack_24,pfVar1,in_ECX + 0x118);
    *pfVar1 = *pfVar5;
    *(float *)(in_ECX + 0xc) = pfVar5[1];
    *(float *)(in_ECX + 0x10) = pfVar5[2];
    *(float *)(in_ECX + 0x14) = pfVar5[3];
    *(float *)(in_ECX + 0x18) = pfVar5[4];
    *(float *)(in_ECX + 0x1c) = pfVar5[5];
    local_30 = *pfVar2 - *pfVar1;
    fStack_24 = (*pfVar2 - *pfVar1) * DAT_0099d0b4 + *pfVar1;
    local_2c = *(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc);
    fStack_20 = (*(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc)) * DAT_0099d0b4 +
                *(float *)(in_ECX + 0xc);
    local_28 = *(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10);
    fStack_1c = (*(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10)) * DAT_0099d0b4 +
                *(float *)(in_ECX + 0x10);
    thunk_FUN_0079e1ba(afStack_c,&local_30);
    *(float *)(in_ECX + 0xf8) = fStack_14 * unaff_ESI;
    *(float *)(in_ECX + 0xfc) = fStack_10 * unaff_ESI;
    *(float *)(in_ECX + 0x100) = afStack_c[0] * unaff_ESI;
    *(float *)(in_ECX + 200) = local_2c;
    uVar7 = DAT_0099d080;
    *(float *)(in_ECX + 0xcc) = local_28;
    *(float *)(in_ECX + 0xd0) = fStack_24;
    *(undefined4 *)(in_ECX + 0xd4) = uVar7;
    *(undefined4 *)(in_ECX + 0xd8) = 0;
    *(undefined4 *)(in_ECX + 0xdc) = 0;
    *(undefined4 *)(in_ECX + 0xe0) = 0;
    *(undefined4 *)(in_ECX + 0xe4) = uVar7;
    *(undefined4 *)(in_ECX + 0xe8) = 0;
    *(undefined4 *)(in_ECX + 0xec) = 0;
    *(undefined4 *)(in_ECX + 0xf0) = 0;
    *(undefined4 *)(in_ECX + 0xf4) = uVar7;
    *(undefined4 *)(in_ECX + 0x114) = *(undefined4 *)(in_ECX + 0x104);
  }
  return;
}


// ==== FUN_0083a0b0 @ 0x0083a0b0 ====

bool FUN_0083a0b0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  iStack_20 = in_ECX + 0x54;
  cVar1 = (**(code **)(*DAT_00b5a988 + 0x24))(*(undefined4 *)(in_ECX + 0x2c));
  if (cVar1 == '\x01') {
    return false;
  }
  iStack_20 = *(int *)(in_ECX + 4);
  uStack_14 = *(undefined4 *)(in_ECX + 0x10);
  uStack_10 = *(undefined4 *)(in_ECX + 0x14);
  uStack_c = *(undefined4 *)(in_ECX + 0x18);
  iVar2 = FUN_0040f630(&iStack_20,&uStack_14,uStack_4);
  return iVar2 != 1;
}


// ==== FUN_0083a130 @ 0x0083a130 ====

void FUN_0083a130(void)

{
  char cVar1;
  int in_ECX;
  undefined1 *puStack_c;
  undefined1 local_4 [4];
  
  puStack_c = local_4;
  cVar1 = (**(code **)(*DAT_00b5af50 + 0xc))(in_ECX + 0x34);
  if (cVar1 == '\0') {
    puStack_c = (undefined1 *)0x0;
  }
  *(float *)(in_ECX + 8) = *(float *)(in_ECX + 0x4c) + (float)puStack_c;
  FUN_00839c80();
  FUN_00839d20();
  return;
}


// ==== FUN_0083a180 @ 0x0083a180 ====

undefined4 FUN_0083a180(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  undefined4 *unaff_retaddr;
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  float fStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (in_ECX[0x5d] != 0) {
    iVar2 = (**(code **)(*(int *)in_ECX[0x5d] + 4))();
    if (*(char *)(iVar2 + 0x1c) != '\0') {
      iStack_3c = in_ECX[-7];
      iStack_38 = in_ECX[-6];
      iStack_34 = in_ECX[-5];
      iStack_30 = in_ECX[-4];
      fStack_2c = (float)in_ECX[-3];
      iStack_28 = in_ECX[-2];
      uStack_20 = 0;
      uStack_18 = *param_1;
      fStack_14 = fStack_2c + DAT_0099d080;
      uStack_10 = param_1[1];
      uStack_1c = 0;
      uStack_4 = 0;
      uStack_c = 0;
      uStack_8 = DAT_0099d0dc;
      uStack_24 = 2;
      cVar1 = (**(code **)(*in_ECX + 0x18))(&uStack_24,auStack_50);
      if (cVar1 != '\0') {
        *unaff_retaddr = uStack_4c;
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0083a2a0 @ 0x0083a2a0 ====

void FUN_0083a2a0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  uint uStack_4;
  
  if (DAT_00b5afb4 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x30) = 0;
    return;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x198) + 4))();
  uStack_4 = (uint)*(byte *)(iVar1 + 0x1d);
  fVar2 = (float10)(**(code **)(*DAT_00b5afb4 + 0xc))(&uStack_4);
  *(float *)(in_ECX + 0x30) = (float)fVar2;
  return;
}


// ==== FUN_0083a2f0 @ 0x0083a2f0 ====

void FUN_0083a2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f554;
  in_ECX[1] = &PTR_FUN_00a0f53c;
  in_ECX[9] = &PTR_FUN_00a0f514;
  (*(code *)PTR_FUN_00a0f560)();
  if (0xf < (uint)in_ECX[0x30]) {
    _free((void *)in_ECX[0x2b]);
    return;
  }
  in_ECX[0x30] = 0xf;
  in_ECX[0x2f] = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  if (0xf < (uint)in_ECX[0x29]) {
    _free((void *)in_ECX[0x24]);
    return;
  }
  in_ECX[0x29] = 0xf;
  in_ECX[0x28] = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  if ((uint)in_ECX[0x14] < 0x10) {
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0xf;
    *(undefined1 *)(in_ECX + 0xf) = 0;
    in_ECX[9] = &PTR_FUN_00a0f398;
    in_ECX[1] = &PTR_FUN_009bf514;
    *in_ECX = &PTR_FUN_00a0f4e8;
    return;
  }
  _free((void *)in_ECX[0xf]);
  return;
}


// ==== FUN_0083a3b0 @ 0x0083a3b0 ====

void FUN_0083a3b0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009bf514;
  in_ECX[9] = &PTR_FUN_00a0f398;
  *in_ECX = &PTR_FUN_00a0f554;
  in_ECX[1] = &PTR_FUN_00a0f53c;
  in_ECX[9] = &PTR_FUN_00a0f514;
  FUN_0083a8b0();
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0xf;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0xf;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x31] = 0;
  *(undefined1 *)(in_ECX + 0x43) = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x66] = 0;
  in_ECX[0x67] = 0;
  *(undefined1 *)((int)in_ECX + 0x10d) = 0;
  *(undefined1 *)(in_ECX + 0x42) = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0x1e] = 0;
  *(undefined1 *)(in_ECX + 8) = 1;
  *(undefined2 *)((int)in_ECX + 0x10a) = 0xff;
  return;
}


// ==== FUN_0083a460 @ 0x0083a460 ====

uint FUN_0083a460(undefined4 param_1)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  int in_ECX;
  float10 fVar6;
  float fVar7;
  
  FUN_0083a960(param_1);
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(undefined4 *)(in_ECX + 0x110) = uVar3;
  iVar1 = in_ECX + 0x38;
  iVar4 = (**(code **)(*DAT_00b5ac10 + 4))(iVar1);
  *(int *)(in_ECX + 0x198) = iVar4;
  pfVar5 = (float *)0x0;
  if (iVar4 != 0) {
    iVar4 = (**(code **)(*DAT_00b5d930 + 4))(iVar1);
    *(int *)(in_ECX + 0x19c) = iVar4;
    pfVar5 = (float *)0x0;
    if (iVar4 != 0) {
      FUN_0083a2a0();
      (**(code **)(*(int *)(in_ECX + 0x24) + 0x10))();
      uVar3 = (**(code **)(**(int **)(in_ECX + 0x198) + 0x14))();
      *(undefined4 *)(in_ECX + 0xc4) = uVar3;
      (**(code **)(*DAT_00b5afac + 4))(*(undefined4 *)(in_ECX + 0x34),in_ECX + 4,2);
      (**(code **)(*DAT_00b5a720 + 4))(in_ECX + 0x24);
      *(undefined1 *)(in_ECX + 0x28) = 1;
      iVar4 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
      fVar2 = DAT_0099d100;
      if (iVar4 != 0) {
        *(bool *)(in_ECX + 0x108) = *(char *)(iVar4 + 3) == '\x03';
        iVar4 = (**(code **)(**(int **)(in_ECX + 0x198) + 8))();
        fVar6 = (float10)FUN_0040d0a0(0,*(undefined4 *)(iVar4 + 0xc));
        *(float *)(in_ECX + 0x78) = (float)fVar6;
        FUN_00401740(s_OBJECT_00a0f4d8,6);
        *(undefined4 *)(in_ECX + 0x7c) = 0xff5080ff;
        FUN_00401660(iVar1,0,0xffffffff);
        *(undefined4 *)(in_ECX + 0x80) = 0;
        fVar2 = SQRT(*(float *)(in_ECX + 0x100) * *(float *)(in_ECX + 0x100) +
                     *(float *)(in_ECX + 0xfc) * *(float *)(in_ECX + 0xfc) +
                     *(float *)(in_ECX + 0xf8) * *(float *)(in_ECX + 0xf8));
        *(float *)(in_ECX + 0x84) = fVar2;
        *(undefined4 *)(in_ECX + 0x88) = 0;
        return CONCAT31((int3)((uint)fVar2 >> 8),1);
      }
      pfVar5 = (float *)(in_ECX + 0xf8);
      fVar7 = *(float *)(in_ECX + 0xfc) * DAT_0099d100;
      *pfVar5 = *(float *)(in_ECX + 0xf8) * DAT_0099d100;
      *(float *)(in_ECX + 0xfc) = fVar7;
      *(float *)(in_ECX + 0x100) = *(float *)(in_ECX + 0x100) * fVar2;
    }
  }
  return (uint)pfVar5 & 0xffffff00;
}


// ==== FUN_0083a630 @ 0x0083a630 ====

void FUN_0083a630(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar3 + 1,0);
  iVar3 = *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar3 + -0x14) = 3;
  *(undefined4 *)(iVar3 + -0x1c) = 0;
  *(undefined4 *)(iVar3 + -0x20) = 0;
  *(undefined4 *)(iVar3 + -0x24) = 0;
  *(undefined4 *)(iVar3 + -0x28) = 0;
  *(undefined4 *)(iVar3 + -0x30) = 0;
  *(undefined4 *)(iVar3 + -0x34) = 0;
  *(undefined4 *)(iVar3 + -0x38) = 0;
  *(undefined4 *)(iVar3 + -0x3c) = 0;
  *(undefined4 *)(iVar3 + -0x44) = 0;
  *(undefined4 *)(iVar3 + -0x48) = 0;
  *(undefined4 *)(iVar3 + -0x4c) = 0;
  *(undefined4 *)(iVar3 + -0x50) = 0;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(iVar3 + -0x18) = DAT_0099d080;
  *(undefined4 *)(iVar3 + -0x2c) = uVar1;
  *(undefined4 *)(iVar3 + -0x40) = uVar1;
  *(undefined4 *)(iVar3 + -0x54) = uVar1;
  if (*(int *)(in_ECX + 0xc4) == 0) {
    *(undefined4 *)(iVar3 + -0x58) = 0;
  }
  else {
    uVar1 = FUN_005ca7a0();
    *(undefined4 *)(iVar3 + -0x58) = uVar1;
  }
  puVar2 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 0x198) + 8))();
  uStack_4b = 0;
  uStack_7 = 0;
  uStack_60 = (**(code **)(**(int **)(in_ECX + 0x198) + 0xc))();
  uStack_5c = (**(code **)(**(int **)(in_ECX + 0x198) + 0x10))();
  uStack_58 = *puVar2;
  uStack_4c = puVar2[1];
  uStack_54 = 0xffffffff;
  uStack_50 = DAT_0099d080;
  uStack_8 = 0;
  FUN_005c1360(&uStack_60);
  FUN_00839b50(param_1);
  return;
}


// ==== FUN_0083a780 @ 0x0083a780 ====

void FUN_0083a780(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x1c) != '\x01') && (*(char *)(in_ECX + 0x50) != '\0')) {
    puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x194) + 8))();
    *(bool *)(puVar1 + 9) = *(int *)(in_ECX + 0xc0) == 0;
    puVar1[0xc] = (float)*(byte *)(iVar2 + 4);
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x194) + 4))();
    *(undefined1 *)((int)puVar1 + 0x21) = *(undefined1 *)(iVar3 + 0x1d);
    puVar1[0xd] = *(undefined4 *)(iVar2 + 0x14);
    puVar1[0xe] = *(undefined4 *)(iVar2 + 0x18);
    puVar1[0xb] = *(undefined4 *)(iVar2 + 0x1c);
    if (*(char *)(in_ECX + 0x104) == '\x01') {
      *(undefined1 *)(puVar1 + 8) = 0;
    }
    else {
      *(undefined1 *)(puVar1 + 8) = *(undefined1 *)(iVar2 + 3);
    }
    *(undefined1 *)((int)puVar1 + 0x26) = *(undefined1 *)(iVar2 + 2);
    puVar1[10] = *(undefined4 *)(iVar2 + 0x10);
    *puVar1 = *(undefined4 *)(in_ECX + 0x54);
    puVar1[1] = *(undefined4 *)(in_ECX + 0x28);
    puVar1[2] = *(undefined4 *)(in_ECX + 0x58);
    puVar1[3] = *(undefined4 *)(in_ECX + 0x5c);
    puVar1[4] = *(undefined4 *)(in_ECX + 0x60);
    puVar1[5] = *(undefined4 *)(in_ECX + 100);
    puVar1[6] = *(undefined4 *)(in_ECX + 0x68);
    puVar1[7] = *(undefined4 *)(in_ECX + 0x70);
    if (*(char *)(in_ECX + 0x109) != '\0') {
      puVar1[0x13] = in_ECX + 0x78;
    }
    FUN_0083a630(puVar1);
    (**(code **)(*param_1 + 0x98))(puVar1);
    (**(code **)(*param_1 + 0x94))(in_ECX + 0xc4);
  }
  return;
}


// ==== FUN_0083a880 @ 0x0083a880 ====

void FUN_0083a880(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10d) = param_1;
  return;
}


// ==== FUN_0083a890 @ 0x0083a890 ====

void FUN_0083a890(void)

{
  FUN_0083a940();
  return;
}


// ==== FUN_0083a8a0 @ 0x0083a8a0 ====

void FUN_0083a8a0(void)

{
  FUN_0083a940();
  return;
}


// ==== FUN_0083a8b0 @ 0x0083a8b0 ====

void FUN_0083a8b0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = 0;
  local_8 = 0;
  local_4 = 0;
  in_ECX[0xf] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 8) = 1;
  in_ECX[9] = 0;
  in_ECX[0x10] = uVar1;
  puVar2 = in_ECX + 2;
  if ((uint)in_ECX[7] < 0x10) {
    puVar3 = puVar2;
  }
  else {
    puVar3 = (undefined4 *)*puVar2;
  }
  if (0xf < (uint)in_ECX[7]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_004bdb30(&local_8,puVar2,in_ECX[6] + (int)puVar3);
  return;
}


// ==== FUN_0083a940 @ 0x0083a940 ====

void FUN_0083a940(byte param_1)

{
  void *in_ECX;
  
  FUN_0083a2f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083a960 @ 0x0083a960 ====

void FUN_0083a960(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00401660(param_1 + 1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 8) = *(undefined1 *)(param_1 + 8);
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  in_ECX[0xf] = param_1[0xf];
  in_ECX[0x10] = param_1[0x10];
  return;
}


// ==== FUN_0083a9c0 @ 0x0083a9c0 ====

void FUN_0083a9c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f5bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083a9e0 @ 0x0083a9e0 ====

void FUN_0083a9e0(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  return;
}


// ==== FUN_0083a9f0 @ 0x0083a9f0 ====

undefined4 FUN_0083a9f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + -1;
  }
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_0083aa10 @ 0x0083aa10 ====

int FUN_0083aa10(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0083aa60 @ 0x0083aa60 ====

void FUN_0083aa60(undefined4 *param_1,undefined4 param_2)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_24 [9];
  
  puVar2 = local_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  local_24[0] = 2;
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x18))(local_24,param_2);
  return;
}


// ==== FUN_0083aaa0 @ 0x0083aaa0 ====

void FUN_0083aaa0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    (**(code **)(*DAT_00b5ac10 + 8))(*(int *)(in_ECX + 0x24));
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  return;
}


// ==== FUN_0083aac0 @ 0x0083aac0 ====

undefined4 FUN_0083aac0(byte *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  byte *pbVar6;
  undefined4 *unaff_retaddr;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float local_4c;
  float fStack_48;
  float local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float local_38;
  float fStack_34;
  float fStack_30;
  undefined4 local_24 [9];
  
  if (*(int *)(in_ECX + 0x24) == 0) {
    return 0;
  }
  if ((*param_1 & 1) == 0) {
    bVar2 = false;
  }
  else {
    cVar3 = FUN_00844be0(in_ECX + 0x28,param_1 + 0xc,&local_44);
    if (cVar3 == '\0') {
      bVar2 = false;
    }
    else {
      local_4c = 1.4013e-45;
      bVar2 = true;
    }
  }
  pbVar6 = param_1;
  puVar4 = local_24;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *(undefined4 *)pbVar6;
    pbVar6 = pbVar6 + 4;
    puVar4 = puVar4 + 1;
  }
  local_24[0] = 2;
  cVar3 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x18))(local_24,&local_38);
  if (bVar2) {
    if (cVar3 == '\x01') {
      puVar4 = &uStack_54;
      if (SQRT((local_38 - *(float *)(param_1 + 0xc)) * (local_38 - *(float *)(param_1 + 0xc)) +
               (fStack_34 - *(float *)(param_1 + 0x10)) * (fStack_34 - *(float *)(param_1 + 0x10)) +
               (fStack_30 - *(float *)(param_1 + 0x14)) * (fStack_30 - *(float *)(param_1 + 0x14)))
          <= SQRT((local_4c - *(float *)(param_1 + 0xc)) * (local_4c - *(float *)(param_1 + 0xc)) +
                  (fStack_48 - *(float *)(param_1 + 0x10)) *
                  (fStack_48 - *(float *)(param_1 + 0x10)) +
                  (local_44 - *(float *)(param_1 + 0x14)) * (local_44 - *(float *)(param_1 + 0x14)))
         ) {
        puVar4 = &uStack_40;
      }
      *unaff_retaddr = *puVar4;
      unaff_retaddr[1] = puVar4[1];
      unaff_retaddr[2] = puVar4[2];
      uVar1 = puVar4[4];
      unaff_retaddr[3] = puVar4[3];
      unaff_retaddr[4] = uVar1;
      return 1;
    }
  }
  else if (!bVar2) {
    if (cVar3 == '\0') {
      return 0;
    }
    *unaff_retaddr = uStack_40;
    unaff_retaddr[1] = uStack_3c;
    unaff_retaddr[2] = local_38;
    unaff_retaddr[3] = fStack_34;
    unaff_retaddr[4] = fStack_30;
    return 1;
  }
  *unaff_retaddr = uStack_54;
  unaff_retaddr[1] = uStack_50;
  unaff_retaddr[2] = local_4c;
  unaff_retaddr[3] = fStack_48;
  unaff_retaddr[4] = local_44;
  return 1;
}


// ==== FUN_0083ac70 @ 0x0083ac70 ====

void FUN_0083ac70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f5cc;
  if (in_ECX[9] != 0) {
    (**(code **)(*DAT_00b5ac10 + 8))(in_ECX[9]);
    in_ECX[9] = 0;
  }
  FUN_004bb5c0();
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_00a0f5bc;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0083acd0 @ 0x0083acd0 ====

void FUN_0083acd0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  piVar1 = (int *)(**(code **)(*DAT_00b5ac10 + 4))(param_1);
  *(int **)(in_ECX + 0x24) = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 != 0) {
      FUN_004ba050(in_ECX + 0x28);
    }
  }
  return;
}


// ==== FUN_0083ad20 @ 0x0083ad20 ====

void FUN_0083ad20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f5cc;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[9] = 0;
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  return;
}


// ==== FUN_0083ad70 @ 0x0083ad70 ====

void FUN_0083ad70(byte param_1)

{
  void *in_ECX;
  
  FUN_0083ac70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083ad90 @ 0x0083ad90 ====

void FUN_0083ad90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f62c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083adb0 @ 0x0083adb0 ====

void FUN_0083adb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f690;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083add0 @ 0x0083add0 ====

void FUN_0083add0(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0083add2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_0083ade0 @ 0x0083ade0 ====

undefined4 FUN_0083ade0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_0083adf0 @ 0x0083adf0 ====

int FUN_0083adf0(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_0083ae00 @ 0x0083ae00 ====

int FUN_0083ae00(void)

{
  int in_ECX;
  
  return in_ECX + 0x30;
}


// ==== FUN_0083ae10 @ 0x0083ae10 ====

void FUN_0083ae10(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x30) = *param_1;
  return;
}


// ==== FUN_0083ae20 @ 0x0083ae20 ====

int FUN_0083ae20(void)

{
  int in_ECX;
  
  return in_ECX + 0x68;
}


// ==== FUN_0083ae30 @ 0x0083ae30 ====

void FUN_0083ae30(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x68) = *param_1;
  *(undefined4 *)(in_ECX + 0x6c) = param_1[1];
  *(undefined1 *)(in_ECX + 0x29) = 1;
  return;
}


// ==== FUN_0083ae50 @ 0x0083ae50 ====

void FUN_0083ae50(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return;
  }
  FUN_00844f40();
  return;
}


// ==== FUN_0083ae60 @ 0x0083ae60 ====

void FUN_0083ae60(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return;
  }
  FUN_00844f90();
  return;
}


// ==== FUN_0083ae70 @ 0x0083ae70 ====

void FUN_0083ae70(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return;
  }
  FUN_00844fe0();
  return;
}


// ==== FUN_0083ae80 @ 0x0083ae80 ====

void FUN_0083ae80(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return;
  }
  FUN_00845030();
  return;
}


// ==== FUN_0083ae90 @ 0x0083ae90 ====

void FUN_0083ae90(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return;
  }
  FUN_008450a0();
  return;
}


// ==== FUN_0083aea0 @ 0x0083aea0 ====

void FUN_0083aea0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return;
  }
  FUN_00845110();
  return;
}


// ==== FUN_0083aeb0 @ 0x0083aeb0 ====

undefined1 FUN_0083aeb0(void)

{
  return 0;
}


// ==== FUN_0083aec0 @ 0x0083aec0 ====

undefined4 FUN_0083aec0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0083aed0 @ 0x0083aed0 ====

undefined4 FUN_0083aed0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_0083aef0 @ 0x0083aef0 ====

void FUN_0083aef0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0xffffffff;
  *(undefined1 *)(in_ECX + 0x29) = 1;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x31) = 1;
  *(undefined1 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  return;
}


// ==== FUN_0083af40 @ 0x0083af40 ====

undefined4 FUN_0083af40(undefined4 param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    *(undefined4 *)(in_ECX + 0x2c) = param_1;
    (**(code **)(*DAT_00b5a724 + 4))(in_ECX + 0x24);
    (**(code **)(*DAT_00b5afac + 4))(*(undefined4 *)(in_ECX + 0x2c),in_ECX + 4,1);
    FUN_00844e10(in_ECX);
    *(undefined1 *)(in_ECX + 0x28) = 1;
    return 1;
  }
  return 0;
}


// ==== FUN_0083af90 @ 0x0083af90 ====

void FUN_0083af90(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) != '\0') {
    (**(code **)(*DAT_00b5afac + 8))(*(undefined4 *)(in_ECX + 0x2c),1);
    (**(code **)(*DAT_00b5a724 + 8))(*(undefined4 *)(in_ECX + 0x2c));
    FUN_00844ea0();
    *(undefined1 *)(in_ECX + 0x28) = 0;
  }
  return;
}


// ==== FUN_0083afd0 @ 0x0083afd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083afd0(int param_1)

{
  int *piVar1;
  float fVar2;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x78) + 0x54) != 0) {
    fVar2 = (float)param_1;
    if (param_1 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    FUN_0083d110(fVar2 * DAT_0099d0ec);
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x78) + 0x68);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(param_1);
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x78) + 0x58);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(param_1);
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x78) + 0x5c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(param_1);
  }
  return;
}


// ==== FUN_0083b040 @ 0x0083b040 ====

undefined4 FUN_0083b040(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return 0;
  }
  uVar1 = FUN_00844f10();
  return uVar1;
}


// ==== FUN_0083b060 @ 0x0083b060 ====

undefined4 FUN_0083b060(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return 0;
  }
  uVar1 = FUN_00844f60();
  return uVar1;
}


// ==== FUN_0083b080 @ 0x0083b080 ====

undefined4 FUN_0083b080(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return 0;
  }
  uVar1 = FUN_00844fb0();
  return uVar1;
}


// ==== FUN_0083b0a0 @ 0x0083b0a0 ====

undefined4 FUN_0083b0a0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return 0;
  }
  uVar1 = FUN_00845000();
  return uVar1;
}


// ==== FUN_0083b0c0 @ 0x0083b0c0 ====

undefined4 FUN_0083b0c0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return 0;
  }
  uVar1 = FUN_00845050();
  return uVar1;
}


// ==== FUN_0083b0e0 @ 0x0083b0e0 ====

undefined4 FUN_0083b0e0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == '\0') {
    return 0;
  }
  uVar1 = FUN_008450d0();
  return uVar1;
}


// ==== FUN_0083b100 @ 0x0083b100 ====

void FUN_0083b100(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x78) + 0x68);
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0083b10c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 8))();
  return;
}


// ==== FUN_0083b110 @ 0x0083b110 ====

undefined4 FUN_0083b110(int *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (((*(char *)(in_ECX + 0xc) == '\0') || (*(char *)(in_ECX + 0xd) == '\0')) || (*param_1 == 8)) {
    return 0;
  }
  if (((param_1[1] < *(int *)(in_ECX + 0x20)) || (param_1[2] < *(int *)(in_ECX + 0x24))) ||
     ((*(int *)(in_ECX + 0x28) <= param_1[1] || (*(int *)(in_ECX + 0x2c) <= param_1[2])))) {
    return 0;
  }
  param_2[1] = *(undefined4 *)(in_ECX + 8);
  *param_2 = 3;
  param_2[2] = (float)param_1[1];
  param_2[3] = (float)param_1[2];
  param_2[4] = 0;
  return 1;
}


// ==== FUN_0083b180 @ 0x0083b180 ====

void FUN_0083b180(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009bf514;
  in_ECX[9] = &PTR_FUN_00a0f690;
  *in_ECX = &PTR_FUN_00a0f6d4;
  in_ECX[1] = &PTR_FUN_00a0f6b8;
  in_ECX[9] = &PTR_FUN_00a0f6a4;
  pvVar1 = operator_new(0x6c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00844e20();
  }
  in_ECX[0x1e] = uVar2;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0xb] = 0xffffffff;
  *(undefined1 *)((int)in_ECX + 0x29) = 1;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  *(undefined1 *)((int)in_ECX + 0x31) = 1;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0x1a) = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1b] = 0;
  return;
}


// ==== FUN_0083b220 @ 0x0083b220 ====

void FUN_0083b220(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0x70) != 0) {
    local_10 = *(undefined4 *)(in_ECX + 0x5c);
    local_c = *(undefined4 *)(in_ECX + 0x58);
    (**(code **)(*DAT_00b5a7c4 + 4))(&local_10);
    *(undefined4 *)(in_ECX + 0x70) = 0;
  }
  FUN_0083b410(param_1);
  uStack_4 = *(undefined4 *)(in_ECX + 0x58);
  uStack_8 = *(undefined4 *)(in_ECX + 0x5c);
  uVar3 = (**(code **)*DAT_00b5a7c4)(&uStack_8);
  *(undefined4 *)(in_ECX + 0x70) = uVar3;
  *(undefined1 *)(in_ECX + 0x29) = 1;
  *(undefined1 *)(in_ECX + 100) = 0;
  *(undefined1 *)(in_ECX + 0x65) = 0;
  *(undefined1 *)(in_ECX + 0x66) = 0;
  if (*(int *)(in_ECX + 0x58) == 0xffdc) {
    *(undefined1 *)(in_ECX + 0x65) = 1;
  }
  else if (*(int *)(in_ECX + 0x58) == 0xff78) {
    *(undefined1 *)(in_ECX + 0x66) = 1;
  }
  cVar2 = (**(code **)(*DAT_00b5a988 + 0x34))();
  if (((cVar2 != '\0') && (piVar1 = *(int **)(in_ECX + 0x70), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    (**(code **)(*(int *)*piVar1 + 4))();
    iVar4 = FUN_00405850(s_minimap__00a0f614,0,8);
    if (iVar4 != -1) {
      *(undefined1 *)(in_ECX + 100) = 1;
    }
  }
  return;
}


// ==== FUN_0083b2f0 @ 0x0083b2f0 ====

void FUN_0083b2f0(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f6d4;
  in_ECX[1] = &PTR_FUN_00a0f6b8;
  in_ECX[9] = &PTR_FUN_00a0f6a4;
  (*(code *)PTR_FUN_00a0f6e0)();
  pvVar1 = (void *)in_ECX[0x1e];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00844ea0();
    _free(pvVar1);
    return;
  }
  pvVar1 = (void *)in_ECX[0x1d];
  in_ECX[0x1e] = 0;
  if (pvVar1 == (void *)0x0) {
    in_ECX[0x1d] = 0;
    in_ECX[9] = &PTR_FUN_00a0f690;
    in_ECX[1] = &PTR_FUN_009bf514;
    *in_ECX = &PTR_FUN_00a0f62c;
    return;
  }
  if (*(void **)((int)pvVar1 + 0x68) != (void *)0x0) {
    _free(*(void **)((int)pvVar1 + 0x68));
    return;
  }
  *(undefined4 *)((int)pvVar1 + 0x68) = 0;
  *(undefined4 *)((int)pvVar1 + 0x6c) = 0;
  *(undefined4 *)((int)pvVar1 + 0x70) = 0;
  if (*(void **)((int)pvVar1 + 0x58) == (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x58) = 0;
    *(undefined4 *)((int)pvVar1 + 0x5c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x60) = 0;
    _free(pvVar1);
    return;
  }
  _free(*(void **)((int)pvVar1 + 0x58));
  return;
}


// ==== FUN_0083b390 @ 0x0083b390 ====

void FUN_0083b390(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (((*(char *)(in_ECX + 0x2c) != '\0') && (0 < *(int *)(in_ECX + 0x48) - *(int *)(in_ECX + 0x40))
      ) && (0 < *(int *)(in_ECX + 0x4c) - *(int *)(in_ECX + 0x44))) {
    if (*(int *)(in_ECX + 0x70) == 0) {
      uVar2 = (**(code **)(*param_1 + 0x100))();
      *(undefined4 *)(in_ECX + 0x70) = uVar2;
    }
    FUN_0083b4a0();
    (**(code **)(*param_1 + 0x74))(*(undefined4 *)(in_ECX + 0x70));
    if (*(int *)(*(int *)(in_ECX + 0x74) + 100) != 0) {
      FUN_008453a0(param_1);
    }
    piVar1 = *(int **)(*(int *)(in_ECX + 0x74) + 0x58);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(param_1);
    }
    piVar1 = *(int **)(*(int *)(in_ECX + 0x74) + 0x5c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(param_1);
    }
  }
  return;
}


// ==== FUN_0083b410 @ 0x0083b410 ====

void FUN_0083b410(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)((int)in_ECX + 0x31) = *(undefined1 *)((int)param_1 + 0x31);
  *(undefined1 *)((int)in_ECX + 0x32) = *(undefined1 *)((int)param_1 + 0x32);
  return;
}


// ==== FUN_0083b480 @ 0x0083b480 ====

void FUN_0083b480(void)

{
  FUN_0083b6a0();
  return;
}


// ==== FUN_0083b490 @ 0x0083b490 ====

void FUN_0083b490(void)

{
  FUN_0083b6a0();
  return;
}


// ==== FUN_0083b4a0 @ 0x0083b4a0 ====

void FUN_0083b4a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  
  iVar3 = *(int *)(in_ECX + 0x74);
  if (*(void **)(iVar3 + 0x58) != (void *)0x0) {
    _free(*(void **)(iVar3 + 0x58));
    return;
  }
  *(undefined4 *)(iVar3 + 0x58) = 0;
  *(undefined4 *)(iVar3 + 0x5c) = 0;
  *(undefined4 *)(iVar3 + 0x60) = 0;
  iVar3 = *(int *)(in_ECX + 0x74);
  if (*(void **)(iVar3 + 0x68) != (void *)0x0) {
    _free(*(void **)(iVar3 + 0x68));
    return;
  }
  *(undefined4 *)(iVar3 + 0x68) = 0;
  *(undefined4 *)(iVar3 + 0x6c) = 0;
  *(undefined4 *)(iVar3 + 0x70) = 0;
  iVar3 = *(int *)(*(int *)(in_ECX + 0x78) + 0x54);
  if (iVar3 == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x74) + 0x78) = 0;
  }
  else {
    if (*(char *)(iVar3 + 4) == '\0') {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + 0x6c;
    }
    *(int *)(*(int *)(in_ECX + 0x74) + 0x78) = iVar3;
  }
  if (*(int *)(*(int *)(in_ECX + 0x78) + 0x60) != 0) {
    FUN_008460a0(*(undefined4 *)(in_ECX + 0x74));
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x78) + 0x68);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(in_ECX + 0x74));
  }
  if (*(char *)(in_ECX + 0x29) == '\0') {
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x74);
  *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(in_ECX + 0x34);
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(in_ECX + 0x38);
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(in_ECX + 0x3c);
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(in_ECX + 0x40);
  iVar3 = *(int *)(in_ECX + 0x74);
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(in_ECX + 0x44);
  *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(in_ECX + 0x48);
  *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(in_ECX + 0x4c);
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(in_ECX + 0x50);
  *(undefined4 *)(*(int *)(in_ECX + 0x74) + 0xc) = *(undefined4 *)(in_ECX + 0x54);
  if (*(char *)(in_ECX + 100) == '\0') {
    if (*(char *)(in_ECX + 0x65) == '\0') {
      if (*(char *)(in_ECX + 0x66) == '\0') {
        *(undefined4 *)(*(int *)(in_ECX + 0x74) + 4) = 0;
        goto LAB_0083b5c7;
      }
      *(undefined4 *)(*(int *)(in_ECX + 0x74) + 4) = 3;
    }
    else {
      *(undefined4 *)(*(int *)(in_ECX + 0x74) + 4) = 1;
    }
    iVar3 = *(int *)(in_ECX + 0x74);
    *(undefined4 *)(iVar3 + 0x34) = 0;
    *(undefined4 *)(iVar3 + 0x38) = 0;
    *(undefined4 *)(iVar3 + 0x3c) = 1;
    *(undefined4 *)(iVar3 + 0x40) = 1;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0x74) + 4) = 2;
  }
LAB_0083b5c7:
  if (*(undefined4 **)(in_ECX + 0x70) == (undefined4 *)0x0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x74) + 0x74) = 0;
    *(undefined1 *)(*(int *)(in_ECX + 0x74) + 1) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0x74) + 0x74) = **(undefined4 **)(in_ECX + 0x70);
    iVar3 = *(int *)(in_ECX + 0x70);
    iVar2 = *(int *)(in_ECX + 0x74);
    *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined1 *)(*(int *)(in_ECX + 0x74) + 1) = *(undefined1 *)(*(int *)(in_ECX + 0x70) + 0x14);
    iVar3 = *(int *)(in_ECX + 0x70);
    iVar2 = *(int *)(in_ECX + 0x74);
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(iVar2 + 0x4c) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar3 + 0x24);
  }
  uVar5 = *(uint *)(in_ECX + 0x60) & 0xff000000;
  uVar4 = *(uint *)(in_ECX + 0x60) & 0xffffff;
  **(undefined1 **)(in_ECX + 0x74) = 1;
  if (uVar4 == 0) {
    if (*(int *)(*(undefined1 **)(in_ECX + 0x74) + 0x74) == 0) {
      **(undefined1 **)(in_ECX + 0x74) = 0;
    }
    else if (uVar5 == 0) {
      uVar5 = 0xff000000;
    }
    uVar4 = 0xffffff;
  }
  *(uint *)(*(int *)(in_ECX + 0x74) + 0x10) = uVar4 | uVar5;
  *(undefined1 *)(*(int *)(in_ECX + 0x74) + 2) = *(undefined1 *)(in_ECX + 0x68);
  *(undefined4 *)(*(int *)(in_ECX + 0x74) + 8) = *(undefined4 *)(in_ECX + 0x6c);
  if (*(int *)(*(int *)(in_ECX + 0x78) + 100) != 0) {
    FUN_00845350();
  }
  *(undefined1 *)(in_ECX + 0x29) = 0;
  return;
}


// ==== FUN_0083b6a0 @ 0x0083b6a0 ====

void FUN_0083b6a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0083b2f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083b6c0 @ 0x0083b6c0 ====

void FUN_0083b6c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f7c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083b6e0 @ 0x0083b6e0 ====

void FUN_0083b6e0(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 4))(in_ECX[5],in_ECX[6],param_1);
  return;
}


// ==== FUN_0083b700 @ 0x0083b700 ====

void FUN_0083b700(void)

{
  return;
}


// ==== FUN_0083b710 @ 0x0083b710 ====

bool FUN_0083b710(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x10) == '\0') {
    return true;
  }
  return *(uint *)(in_ECX + 0x20) <= *(uint *)(in_ECX + 0x24);
}


// ==== FUN_0083b730 @ 0x0083b730 ====

void FUN_0083b730(void)

{
  int in_ECX;
  
  FUN_00844f10();
  FUN_0083cf80(in_ECX + 0x28);
  return;
}


// ==== FUN_0083b770 @ 0x0083b770 ====

undefined4 FUN_0083b770(undefined4 param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(int **)(in_ECX + 0xc) = param_2;
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00846520();
  *(undefined1 *)(in_ECX + 4) = 1;
  return 1;
}


// ==== FUN_0083b7a0 @ 0x0083b7a0 ====

void FUN_0083b7a0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    if (iVar1 != 0) {
      FUN_00846350();
    }
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0083b7d0 @ 0x0083b7d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083b7d0(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *in_ECX;
  float10 fVar7;
  
  (**(code **)(*in_ECX + 0xc))();
  if (param_1 != (int *)0x0) {
    in_ECX[5] = (int)param_1;
    in_ECX[6] = param_2;
    iVar4 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar4 + 4) != '\0') {
      fVar1 = (float)in_ECX[6];
      if (in_ECX[6] < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      fVar2 = (float)*(int *)(iVar4 + 8);
      if (*(int *)(iVar4 + 8) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar3 = fVar2 * fVar1 * DAT_0099d0ec;
      fVar2 = (float)*(int *)(iVar4 + 0xc);
      if (*(int *)(iVar4 + 0xc) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar1 = fVar2 * fVar1 * DAT_0099d0ec;
      uVar5 = FUN_00802534();
      in_ECX[7] = uVar5;
      uVar6 = FUN_00802534();
      in_ECX[8] = uVar6;
      if (uVar5 < uVar6) {
        if (*(char *)(iVar4 + 5) == '\0') {
          in_ECX[9] = param_3;
        }
        else {
          fVar7 = (float10)FUN_0040d0a0(fVar3,fVar1);
          in_ECX[9] = (int)ROUND(fVar7);
        }
        if ((int *)in_ECX[3] != (int *)0x0) {
          iVar4 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
          in_ECX[0xd] = *(int *)(iVar4 + 4);
          in_ECX[0xe] = *(int *)(iVar4 + 8);
          iVar4 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
          in_ECX[0xf] = *(int *)(iVar4 + 0xc);
          *(undefined1 *)(in_ECX + 4) = 1;
        }
      }
    }
  }
  return;
}


// ==== FUN_0083b8e0 @ 0x0083b8e0 ====

void FUN_0083b8e0(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x10) == '\0') ||
     (*(undefined1 *)(in_ECX + 0x10) = 0, *(int *)(*(int *)(in_ECX + 8) + 0x54) == 0)) {
    return;
  }
  FUN_0083cfd0();
  return;
}


// ==== FUN_0083b900 @ 0x0083b900 ====

void FUN_0083b900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f7e0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  return;
}


// ==== FUN_0083b920 @ 0x0083b920 ====

void FUN_0083b920(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f7e0;
  if (*(char *)(in_ECX + 1) != '\0') {
    iVar1 = (**(code **)(*(int *)in_ECX[3] + 0x10))();
    if (iVar1 != 0) {
      FUN_00846350();
    }
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  *in_ECX = &PTR_FUN_00a0f7c0;
  return;
}


// ==== FUN_0083b950 @ 0x0083b950 ====

void FUN_0083b950(float param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  uint uVar6;
  int iVar7;
  float10 fVar8;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  float fStack_4;
  
  if ((char)in_ECX[4] != '\0') {
    uVar6 = (int)param_1 + in_ECX[9];
    uVar2 = in_ECX[8];
    if (uVar2 <= uVar6) {
      in_ECX[9] = uVar2;
      (**(code **)(*in_ECX + 0xc))();
      return;
    }
    uVar1 = in_ECX[7];
    in_ECX[9] = uVar6;
    if (uVar1 <= uVar6) {
      iVar7 = uVar6 - uVar1;
      uVar2 = (uint)(iVar7 * 999) / (uVar2 - uVar1);
      uVar6 = 999;
      if (uVar2 < 1000) {
        uVar6 = uVar2;
      }
      iVar3 = (**(code **)(*(int *)in_ECX[5] + 4))();
      if (*(int *)(iVar3 + 0x68) == 0) {
        iVar4 = (**(code **)(*(int *)in_ECX[3] + 8))();
        in_ECX[0xc] = *(int *)(iVar4 + 4);
      }
      else {
        FUN_005aa3a0(&iStack_1c,uVar6,iVar7);
        in_ECX[0xc] = iStack_1c;
      }
      if (*(int *)(iVar3 + 0xa8) == 0) {
        iVar4 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
        param_1 = *(float *)(iVar4 + 0x1c);
      }
      else {
        fVar8 = (float10)FUN_005aa2a0(uVar6,iVar7);
        param_1 = (float)fVar8;
      }
      if (*(int *)(iVar3 + 0x88) == 0) {
        iVar7 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
        iStack_1c = *(int *)(iVar7 + 0x10);
        iStack_18 = *(int *)(iVar7 + 0x14);
        iStack_14 = *(int *)(iVar7 + 0x18);
      }
      else {
        piVar5 = (int *)FUN_005aa3a0(&iStack_10,uVar6,iVar7);
        iStack_1c = *piVar5;
        iStack_18 = piVar5[1];
        iStack_14 = piVar5[2];
      }
      iStack_10 = iStack_1c;
      iStack_c = iStack_18;
      iStack_8 = iStack_14;
      fStack_4 = param_1;
      iVar7 = FUN_0040ead0(&iStack_10);
      in_ECX[0xb] = iVar7;
      iVar7 = (**(code **)(*(int *)in_ECX[3] + 0x10))();
      piVar5 = in_ECX + 10;
      if (iVar7 == 0) {
        *piVar5 = 0;
      }
      else {
        iVar7 = FUN_00846410(in_ECX[9] - in_ECX[7]);
        *piVar5 = iVar7;
      }
      FUN_00844f10();
      FUN_0083cf80(piVar5);
    }
  }
  return;
}


// ==== FUN_0083bb00 @ 0x0083bb00 ====

void FUN_0083bb00(byte param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f7e0;
  if (*(char *)(in_ECX + 1) != '\0') {
    iVar1 = (**(code **)(*(int *)in_ECX[3] + 0x10))();
    if (iVar1 != 0) {
      FUN_00846350();
    }
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  *in_ECX = &PTR_FUN_00a0f7c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083bb60 @ 0x0083bb60 ====

void FUN_0083bb60(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 4))(in_ECX[6],in_ECX[7],param_1);
  return;
}


// ==== FUN_0083bb80 @ 0x0083bb80 ====

void FUN_0083bb80(void)

{
  return;
}


// ==== FUN_0083bb90 @ 0x0083bb90 ====

bool FUN_0083bb90(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x14) == '\0') {
    return true;
  }
  return *(uint *)(in_ECX + 0x24) <= *(uint *)(in_ECX + 0x28);
}


// ==== FUN_0083bbb0 @ 0x0083bbb0 ====

void FUN_0083bbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f840;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0xffffffff;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_0083bc00 @ 0x0083bc00 ====

undefined4 FUN_0083bc00(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 8) = param_1;
  *(int *)(in_ECX + 0xc) = param_2;
  if (((param_1 == 0) || (param_2 == 0)) || (*(int **)(param_1 + 0x50) == (int *)0x0)) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 8))();
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  *(undefined1 *)(in_ECX + 4) = 1;
  return 1;
}


// ==== FUN_0083bc40 @ 0x0083bc40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083bc40(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *in_ECX;
  float10 fVar8;
  
  (**(code **)(*in_ECX + 0xc))();
  if (param_1 != (int *)0x0) {
    in_ECX[6] = (int)param_1;
    in_ECX[7] = param_2;
    iVar5 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar5 + 4) != '\0') {
      iVar6 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
      fVar3 = (float)*(int *)(iVar5 + 8);
      iVar2 = *(int *)(iVar6 + 0x28);
      iVar6 = *(int *)(iVar6 + 0x1c);
      if (*(int *)(iVar5 + 8) < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      fVar4 = (float)in_ECX[7];
      if (in_ECX[7] < 0) {
        fVar4 = fVar4 + _DAT_0099d104;
      }
      fVar3 = fVar4 * fVar3 * DAT_0099d0ec;
      uVar7 = FUN_00802534();
      uVar1 = uVar7 + iVar2 * iVar6;
      in_ECX[8] = uVar7;
      in_ECX[9] = uVar1;
      if (uVar7 < uVar1) {
        if (*(char *)(iVar5 + 5) == '\0') {
          in_ECX[10] = param_3;
        }
        else {
          fVar4 = (float)(int)uVar1;
          if ((int)uVar1 < 0) {
            fVar4 = fVar4 + _DAT_0099d104;
          }
          fVar8 = (float10)FUN_0040d0a0(fVar3,fVar4);
          in_ECX[10] = (int)ROUND(fVar8);
        }
        if (in_ECX[3] != 0) {
          *(undefined1 *)(in_ECX + 5) = 1;
        }
      }
    }
  }
  return;
}


// ==== FUN_0083bd30 @ 0x0083bd30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083bd30(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x2c) == '\0') {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
    iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar3 != 0) {
      FUN_00401660(iVar2,0,0xffffffff);
      fVar1 = (float)*(int *)(iVar2 + 0x20);
      if (*(int *)(iVar2 + 0x20) < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      uVar4 = FUN_005ad8e0(*(undefined4 *)(in_ECX + 0x10),0,0,0,*(undefined4 *)(iVar2 + 0x1c),fVar1,
                           *(undefined4 *)(iVar2 + 0x24));
      FUN_00797a20(uVar4);
      *(undefined1 *)(in_ECX + 0x2c) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x2c) = 1;
  }
  return;
}


// ==== FUN_0083be10 @ 0x0083be10 ====

void FUN_0083be10(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x2c) != '\0') {
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 != 0) {
      uVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      FUN_00401660(uVar2,0,0xffffffff);
      uVar2 = FUN_005ad9a0(*(undefined4 *)(in_ECX + 0x10));
      FUN_00797a20(uVar2);
      *(undefined1 *)(in_ECX + 0x2c) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x2c) = 0;
  }
  return;
}


// ==== FUN_0083be90 @ 0x0083be90 ====

void FUN_0083be90(void)

{
  int in_ECX;
  
  FUN_0083be10();
  *(undefined1 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_0083bea0 @ 0x0083bea0 ====

void FUN_0083bea0(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  if ((char)in_ECX[5] != '\0') {
    uVar1 = in_ECX[10] + param_1;
    if ((uint)in_ECX[9] <= uVar1) {
      in_ECX[10] = in_ECX[9];
      (**(code **)(*in_ECX + 0xc))();
      return;
    }
    in_ECX[10] = uVar1;
    if (uVar1 < (uint)in_ECX[8]) {
      FUN_0083be10();
      return;
    }
    FUN_0083bd30();
  }
  return;
}


// ==== FUN_0083bee0 @ 0x0083bee0 ====

void FUN_0083bee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f840;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  *in_ECX = &PTR_FUN_00a0f7c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083bf10 @ 0x0083bf10 ====

void FUN_0083bf10(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 4))(in_ECX[8],in_ECX[9],param_1);
  return;
}


// ==== FUN_0083bf30 @ 0x0083bf30 ====

void FUN_0083bf30(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_0083bf40 @ 0x0083bf40 ====

bool FUN_0083bf40(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) == '\0') {
    return true;
  }
  return *(uint *)(in_ECX + 0x2c) <= *(uint *)(in_ECX + 0x30);
}


// ==== FUN_0083bf80 @ 0x0083bf80 ====

void FUN_0083bf80(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a0f8e8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = uVar1;
  in_ECX[0x13] = 0xffffffff;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x17) = 0;
  *(undefined1 *)((int)in_ECX + 0x5d) = 0;
  in_ECX[0x2f] = 0;
  return;
}


// ==== FUN_0083bfd0 @ 0x0083bfd0 ====

undefined4 FUN_0083bfd0(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(int **)(in_ECX + 0xc) = param_2;
  *(undefined4 *)(in_ECX + 0x10) = *param_3;
  *(undefined4 *)(in_ECX + 0x14) = param_3[1];
  *(undefined4 *)(in_ECX + 0x18) = param_3[2];
  iVar1 = (**(code **)(*param_2 + 0xc))();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00846520();
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  *(undefined4 *)(in_ECX + 0x54) = *puVar2;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
  if (iVar1 != 0) {
    pvVar3 = operator_new(0x54);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_008466d0();
    }
    *(undefined4 *)(in_ECX + 0xbc) = uVar4;
    FUN_008466a0(iVar1);
  }
  *(undefined1 *)(in_ECX + 4) = 1;
  return 1;
}


// ==== FUN_0083c070 @ 0x0083c070 ====

void FUN_0083c070(void)

{
  void *_Memory;
  int iVar1;
  int *in_ECX;
  
  if ((char)in_ECX[1] != '\0') {
    (**(code **)(*in_ECX + 0xc))();
    _Memory = (void *)in_ECX[0x2f];
    if (_Memory != (void *)0x0) {
      FUN_00846660();
      _free(_Memory);
      return;
    }
    in_ECX[0x2f] = 0;
    iVar1 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
    if (iVar1 != 0) {
      FUN_00846350();
    }
    in_ECX[3] = 0;
    in_ECX[2] = 0;
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  return;
}


// ==== FUN_0083c0d0 @ 0x0083c0d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083c0d0(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *in_ECX;
  float10 fVar7;
  
  (**(code **)(*in_ECX + 0xc))();
  if (param_1 != (int *)0x0) {
    in_ECX[8] = (int)param_1;
    in_ECX[9] = param_2;
    iVar4 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar4 + 4) != '\0') {
      fVar1 = (float)in_ECX[9];
      if (in_ECX[9] < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      fVar2 = (float)*(int *)(iVar4 + 8);
      if (*(int *)(iVar4 + 8) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar3 = fVar2 * fVar1 * DAT_0099d0ec;
      fVar2 = (float)*(int *)(iVar4 + 0xc);
      if (*(int *)(iVar4 + 0xc) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar1 = fVar2 * fVar1 * DAT_0099d0ec;
      uVar5 = FUN_00802534();
      in_ECX[10] = uVar5;
      uVar6 = FUN_00802534();
      in_ECX[0xb] = uVar6;
      if (uVar5 < uVar6) {
        if (*(char *)(iVar4 + 5) == '\0') {
          in_ECX[0xc] = param_3;
        }
        else {
          fVar7 = (float10)FUN_0040d0a0(fVar3,fVar1);
          in_ECX[0xc] = (int)ROUND(fVar7);
        }
        if (in_ECX[3] != 0) {
          in_ECX[0x26] = 0;
          in_ECX[0x25] = 0;
          in_ECX[0x24] = 0;
          in_ECX[0x23] = 0;
          in_ECX[0x21] = 0;
          in_ECX[0x20] = 0;
          in_ECX[0x1f] = 0;
          in_ECX[0x1e] = 0;
          in_ECX[0x1c] = 0;
          in_ECX[0x1b] = 0;
          in_ECX[0x1a] = 0;
          in_ECX[0x19] = 0;
          iVar4 = DAT_0099d080;
          in_ECX[0x27] = DAT_0099d080;
          in_ECX[0x22] = iVar4;
          in_ECX[0x1d] = iVar4;
          in_ECX[0x18] = iVar4;
          *(undefined1 *)(in_ECX + 7) = 1;
          (**(code **)(*in_ECX + 0x10))(0);
        }
      }
    }
  }
  return;
}


// ==== FUN_0083c250 @ 0x0083c250 ====

void FUN_0083c250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f8e8;
  FUN_0083c070();
  *in_ECX = &PTR_FUN_00a0f7c0;
  return;
}


// ==== FUN_0083c270 @ 0x0083c270 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083c270(int param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *in_ECX;
  int iVar9;
  uint uVar10;
  float10 fVar11;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (in_ECX[0x2f] != 0) {
    FUN_00846700(param_1);
  }
  if ((char)in_ECX[7] != '\0') {
    uVar10 = param_1 + in_ECX[0xc];
    uVar3 = in_ECX[0xb];
    if (uVar3 <= uVar10) {
      in_ECX[0xc] = uVar3;
      (**(code **)(*in_ECX + 0xc))();
      return;
    }
    uVar2 = in_ECX[10];
    in_ECX[0xc] = uVar10;
    if (uVar2 <= uVar10) {
      iVar9 = uVar10 - uVar2;
      uVar3 = (uint)(iVar9 * 999) / (uVar3 - uVar2);
      uVar10 = 999;
      if (uVar3 < 1000) {
        uVar10 = uVar3;
      }
      iVar4 = (**(code **)(*(int *)in_ECX[8] + 4))();
      if (*(int *)(iVar4 + 0xa8) == 0) {
        fStack_24 = DAT_0099d080;
      }
      else {
        fVar11 = (float10)FUN_005aa2a0(uVar10,iVar9);
        fStack_24 = (float)fVar11;
      }
      if (*(int *)(iVar4 + 0x88) == 0) {
        fStack_1c = DAT_0099d080;
        fStack_18 = DAT_0099d080;
        fStack_14 = DAT_0099d080;
      }
      else {
        pfVar5 = (float *)FUN_005aa3a0(&fStack_10,uVar10,iVar9);
        fStack_1c = *pfVar5;
        fStack_18 = pfVar5[1];
        fStack_14 = pfVar5[2];
      }
      fStack_10 = fStack_1c;
      fStack_c = fStack_18;
      fStack_8 = fStack_14;
      fStack_4 = fStack_24;
      iVar6 = FUN_0040ead0(&fStack_10);
      in_ECX[0x13] = iVar6;
      if (*(int *)(iVar4 + 0x68) == 0) {
        iVar6 = (**(code **)(*(int *)in_ECX[3] + 8))();
        iVar6 = *(int *)(iVar6 + 4);
        in_ECX[0x11] = iVar6;
        in_ECX[0x12] = iVar6;
      }
      else {
        FUN_005aa3a0(&fStack_10,uVar10,iVar9);
        iVar6 = (**(code **)(*(int *)in_ECX[3] + 8))();
        fVar1 = *(float *)(iVar6 + 4);
        in_ECX[0x11] = (int)(fVar1 * fStack_10);
        in_ECX[0x12] = (int)(fVar1 * fStack_8);
      }
      if (*(int *)(iVar4 + 0x50) == 0) {
        in_ECX[0x14] = 0;
      }
      else {
        fVar11 = (float10)FUN_005aa2a0(uVar10,iVar9);
        in_ECX[0x14] = (int)(float)(fVar11 * (float10)_DAT_00b4fc7c);
      }
      if (*(int *)(iVar4 + 0x30) == 0) {
        fStack_10 = (float)in_ECX[4] + *(float *)(iVar4 + 0x10);
        fStack_c = *(float *)(iVar4 + 0x14) + (float)in_ECX[5];
        fStack_8 = *(float *)(iVar4 + 0x18) + (float)in_ECX[6];
      }
      else {
        FUN_005aa3a0(&fStack_10,uVar10,iVar9);
        fStack_10 = (float)in_ECX[4] + *(float *)(iVar4 + 0x10) + fStack_10;
        fStack_c = (float)in_ECX[5] + *(float *)(iVar4 + 0x14) + fStack_c;
        fStack_8 = (float)in_ECX[6] + *(float *)(iVar4 + 0x18) + fStack_8;
      }
      in_ECX[0x2c] = (int)fStack_10;
      in_ECX[0x2d] = (int)fStack_c;
      in_ECX[0x2e] = (int)fStack_8;
      iVar9 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
      if (iVar9 == 0) {
        in_ECX[0x10] = 0;
      }
      else {
        iVar4 = FUN_00846410(in_ECX[0xc] - in_ECX[10]);
        in_ECX[0x10] = iVar4;
        in_ECX[0x16] = *(int *)(iVar9 + 0xc);
        *(undefined1 *)(in_ECX + 0x17) = *(undefined1 *)(iVar9 + 0x4c);
      }
      uVar7 = FUN_00845130();
      thunk_FUN_0079e5a0(in_ECX + 0xd,in_ECX + 0x2c,uVar7);
      piVar8 = (int *)FUN_00845150();
      iVar9 = piVar8[2];
      iVar4 = *piVar8;
      in_ECX[0x28] = 0;
      in_ECX[0x29] = iVar9 - iVar4;
      iVar9 = piVar8[3];
      iVar4 = piVar8[1];
      in_ECX[0x2a] = 0;
      in_ECX[0x2b] = iVar9 - iVar4;
      if (in_ECX[0x2f] != 0) {
        FUN_00846940(fStack_8,in_ECX + 0xd);
      }
    }
  }
  return;
}


// ==== FUN_0083c5a0 @ 0x0083c5a0 ====

void FUN_0083c5a0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xbc) != 0) {
    FUN_00846aa0(param_1);
  }
  if ((((*(char *)(in_ECX + 0x1c) != '\0') && (*(uint *)(in_ECX + 0x30) < *(uint *)(in_ECX + 0x2c)))
      && (*(uint *)(in_ECX + 0x28) <= *(uint *)(in_ECX + 0x30))) && (*(int *)(in_ECX + 0x40) != 0))
  {
    FUN_005aaba0(in_ECX + 0x34);
  }
  return;
}


// ==== FUN_0083c5f0 @ 0x0083c5f0 ====

void FUN_0083c5f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f8e8;
  FUN_0083c070();
  *in_ECX = &PTR_FUN_00a0f7c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083c620 @ 0x0083c620 ====

void FUN_0083c620(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 4))(in_ECX[8],in_ECX[9],param_1);
  return;
}


// ==== FUN_0083c640 @ 0x0083c640 ====

void FUN_0083c640(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) != '\0') {
    *(undefined1 *)(in_ECX + 0x1c) = 0;
  }
  return;
}


// ==== FUN_0083c650 @ 0x0083c650 ====

bool FUN_0083c650(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) == '\0') {
    return true;
  }
  return *(uint *)(in_ECX + 0x2c) <= *(uint *)(in_ECX + 0x30);
}


// ==== FUN_0083c690 @ 0x0083c690 ====

void FUN_0083c690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f948;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[8] = 0;
  in_ECX[0xe] = 0;
  return;
}


// ==== FUN_0083c6b0 @ 0x0083c6b0 ====

undefined4 FUN_0083c6b0(int param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  
  *(int *)(in_ECX + 8) = param_1;
  *(int **)(in_ECX + 0xc) = param_2;
  *(undefined4 *)(in_ECX + 0x10) = *param_3;
  *(undefined4 *)(in_ECX + 0x14) = param_3[1];
  *(undefined4 *)(in_ECX + 0x18) = param_3[2];
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    iVar2 = (**(code **)(*param_2 + 0x10))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      if (*(int *)(iVar2 + 0xc) != 0) {
        FUN_00846520();
        pvVar3 = operator_new(0xb4);
        if (pvVar3 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_00846fb0();
        }
        *(undefined4 *)(in_ECX + 0x38) = uVar4;
        cVar1 = FUN_00846bd0(*(undefined4 *)(in_ECX + 0xc),(undefined4 *)(in_ECX + 0x10));
        if (cVar1 != '\0') {
          *(undefined1 *)(in_ECX + 4) = 1;
          return 1;
        }
        pvVar3 = *(void **)(in_ECX + 0x38);
        if (pvVar3 != (void *)0x0) {
          FUN_00847040();
          _free(pvVar3);
          return extraout_EAX;
        }
        *(undefined4 *)(in_ECX + 0x38) = 0;
      }
    }
  }
  return 0;
}


// ==== FUN_0083c770 @ 0x0083c770 ====

void FUN_0083c770(void)

{
  void *_Memory;
  int iVar1;
  int *in_ECX;
  
  if ((char)in_ECX[1] != '\0') {
    (**(code **)(*in_ECX + 0xc))();
    FUN_00847030();
    _Memory = (void *)in_ECX[0xe];
    if (_Memory != (void *)0x0) {
      FUN_00847040();
      _free(_Memory);
      return;
    }
    in_ECX[0xe] = 0;
    iVar1 = (**(code **)(*(int *)in_ECX[3] + 0x10))();
    if (iVar1 != 0) {
      FUN_00846350();
    }
    in_ECX[3] = 0;
    in_ECX[2] = 0;
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  return;
}


// ==== FUN_0083c7d0 @ 0x0083c7d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083c7d0(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *in_ECX;
  float10 fVar6;
  
  (**(code **)(*in_ECX + 0xc))();
  if (param_1 != (int *)0x0) {
    in_ECX[8] = (int)param_1;
    in_ECX[9] = param_2;
    iVar3 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar3 + 4) != '\0') {
      fVar1 = (float)in_ECX[9];
      if (in_ECX[9] < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      fVar2 = (float)*(int *)(iVar3 + 8);
      if (*(int *)(iVar3 + 8) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar1 = fVar2 * fVar1 * DAT_0099d0ec;
      uVar4 = FUN_00802534();
      in_ECX[10] = uVar4;
      uVar5 = FUN_00802534();
      in_ECX[0xb] = uVar5;
      if (uVar4 < uVar5) {
        if (*(char *)(iVar3 + 5) == '\0') {
          in_ECX[0xc] = param_3;
        }
        else {
          fVar6 = (float10)FUN_0040d0a0(0,fVar1);
          in_ECX[0xc] = (int)ROUND(fVar6);
        }
        if ((int *)in_ECX[3] != (int *)0x0) {
          iVar3 = (**(code **)(*(int *)in_ECX[3] + 0xc))();
          uVar4 = *(uint *)(iVar3 + 0xc);
          *(undefined1 *)(in_ECX + 7) = 1;
          in_ECX[0xd] = ((int)uVar4 < 1) - 1 & uVar4;
        }
      }
    }
  }
  return;
}


// ==== FUN_0083c8d0 @ 0x0083c8d0 ====

void FUN_0083c8d0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x38) != 0) && (*(int *)(in_ECX + 8) != 0)) {
    uVar1 = FUN_00845150();
    uVar2 = FUN_00845130(uVar1);
    FUN_008471e0(param_1,uVar2,uVar1);
  }
  return;
}


// ==== FUN_0083c900 @ 0x0083c900 ====

void FUN_0083c900(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *in_ECX;
  
  if (((char)in_ECX[7] != '\0') && (in_ECX[8] != 0)) {
    uVar3 = in_ECX[0xb];
    uVar1 = param_1 + in_ECX[0xc];
    if (uVar3 <= uVar1) {
      in_ECX[0xc] = uVar3;
      (**(code **)(*in_ECX + 0xc))();
      return;
    }
    uVar2 = in_ECX[10];
    in_ECX[0xc] = uVar1;
    if (uVar2 <= uVar1) {
      uVar3 = ((uVar1 - uVar2) * 999) / (uVar3 - uVar2);
      if (999 < uVar3) {
        uVar3 = 999;
      }
      if (in_ECX[0xe] != 0) {
        FUN_00847060(uVar3,uVar1 - uVar2,in_ECX[8]);
      }
    }
  }
  return;
}


// ==== FUN_0083c980 @ 0x0083c980 ====

void FUN_0083c980(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  
  if ((*(char *)(in_ECX + 0x1c) != '\0') && (*(uint *)(in_ECX + 0x28) <= *(uint *)(in_ECX + 0x30)))
  {
    iVar4 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
    uVar7 = *(uint *)(*(int *)(in_ECX + 0x38) + 0xb0);
    iVar1 = *(int *)(iVar4 + 0xc);
    if (iVar1 < 1) {
      if (*(uint *)(iVar4 + 8) <= uVar7) {
        return;
      }
      uVar7 = *(uint *)(iVar4 + 8) - uVar7;
      uVar6 = -iVar1;
      if (uVar7 <= (uint)-iVar1 && -uVar7 != iVar1) {
        uVar6 = uVar7;
      }
    }
    else {
      uVar5 = *(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x28);
      if (param_1 < uVar5) {
        uVar5 = param_1;
      }
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + uVar5;
      uVar5 = *(uint *)(in_ECX + 0x34);
      uVar2 = *(uint *)(iVar4 + 0xc);
      if (uVar5 < uVar2) {
        return;
      }
      uVar3 = *(uint *)(iVar4 + 8);
      if (uVar3 <= uVar7) {
        *(uint *)(in_ECX + 0x34) = uVar2;
        return;
      }
      uVar6 = uVar5 / uVar2;
      if (uVar3 < uVar6 + uVar7) {
        uVar6 = uVar3 - uVar7;
        *(uint *)(in_ECX + 0x34) = uVar2;
      }
      else {
        *(uint *)(in_ECX + 0x34) = uVar5 % uVar2;
      }
    }
    if (10 < uVar6) {
      uVar6 = 10;
    }
    if (uVar6 != 0) {
      do {
        FUN_00847180(*(undefined4 *)(in_ECX + 0x20));
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  return;
}


// ==== FUN_0083ca40 @ 0x0083ca40 ====

void FUN_0083ca40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f948;
  FUN_0083c770();
  *in_ECX = &PTR_FUN_00a0f7c0;
  return;
}


// ==== FUN_0083ca60 @ 0x0083ca60 ====

void FUN_0083ca60(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0083c900(param_1);
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_00846ef0(param_1);
  }
  FUN_0083c980(param_1);
  return;
}


// ==== FUN_0083ca90 @ 0x0083ca90 ====

void FUN_0083ca90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f948;
  FUN_0083c770();
  *in_ECX = &PTR_FUN_00a0f7c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083cac0 @ 0x0083cac0 ====

void FUN_0083cac0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = *(undefined4 **)(in_ECX + 8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 4))(param_1,param_2,param_3);
  }
  return;
}


// ==== FUN_0083cb00 @ 0x0083cb00 ====

void FUN_0083cb00(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = *(undefined4 **)(in_ECX + 8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 8))(param_1);
  }
  return;
}


// ==== FUN_0083cb30 @ 0x0083cb30 ====

void FUN_0083cb30(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = *(undefined4 **)(in_ECX + 8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0xc))();
  }
  return;
}


// ==== FUN_0083cb60 @ 0x0083cb60 ====

void FUN_0083cb60(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = *(undefined4 **)(in_ECX + 8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x10))(param_1);
  }
  return;
}


// ==== FUN_0083cb90 @ 0x0083cb90 ====

void FUN_0083cb90(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = *(undefined4 **)(in_ECX + 8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x14))(param_1);
  }
  return;
}


// ==== FUN_0083cbc0 @ 0x0083cbc0 ====

undefined4 FUN_0083cbc0(void)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 8);
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  while( true ) {
    if (puVar3 == puVar1) {
      return 1;
    }
    cVar2 = (**(code **)(*(int *)*puVar3 + 0x18))();
    if (cVar2 == '\0') break;
    puVar3 = puVar3 + 1;
  }
  return 0;
}


// ==== FUN_0083cbf0 @ 0x0083cbf0 ====

void FUN_0083cbf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f9a8;
  FUN_004eb890(in_ECX + 1);
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_00a0f7c0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0083cc40 @ 0x0083cc40 ====

void FUN_0083cc40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f9a8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0083cc60 @ 0x0083cc60 ====

void FUN_0083cc60(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    FUN_0083cd10(*(undefined4 *)(in_ECX + 0xc),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0xc) = puVar2 + 1;
  return;
}


// ==== FUN_0083ccb0 @ 0x0083ccb0 ====

void FUN_0083ccb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0f9a8;
  FUN_004eb890(in_ECX + 1);
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_00a0f7c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083cd10 @ 0x0083cd10 ====

void FUN_0083cd10(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00999f80;
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


// ==== Catch@0083ce71 @ 0x0083ce71 ====

void Catch_0083ce71(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0083cf60 @ 0x0083cf60 ====

void FUN_0083cf60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fa14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083cf80 @ 0x0083cf80 ====

void FUN_0083cf80(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xcc) = 1;
  *(undefined4 *)(in_ECX + 0xe4) = *param_1;
  *(undefined4 *)(in_ECX + 0xd0) = param_1[1];
  *(undefined4 *)(in_ECX + 0xd4) = param_1[2];
  *(undefined4 *)(in_ECX + 0xe0) = param_1[5];
  *(undefined4 *)(in_ECX + 0xd8) = param_1[3];
  *(undefined4 *)(in_ECX + 0xdc) = param_1[4];
  return;
}


// ==== FUN_0083cfd0 @ 0x0083cfd0 ====

void FUN_0083cfd0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  return;
}


// ==== FUN_0083cfe0 @ 0x0083cfe0 ====

int FUN_0083cfe0(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_0083cff0 @ 0x0083cff0 ====

void FUN_0083cff0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x6c) = param_1;
  return;
}


// ==== FUN_0083d000 @ 0x0083d000 ====

void FUN_0083d000(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40 [16];
  
  if (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  thunk_FUN_0079f761(local_40,0x3c23d70a,0x3c23d70a,0);
  iVar1 = *(int *)(in_ECX + 0xc4);
  puVar4 = local_40;
  puVar5 = (undefined4 *)(in_ECX + 0x24);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
    *(undefined4 *)(in_ECX + 0xc4) = 0;
  }
  if (*(int *)(in_ECX + 200) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 200));
    *(undefined4 *)(in_ECX + 200) = 0;
  }
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  uVar2 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xc0) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xac) = uVar2;
  *(undefined4 *)(in_ECX + 0x98) = uVar2;
  *(undefined4 *)(in_ECX + 0x84) = uVar2;
  return;
}


// ==== FUN_0083d110 @ 0x0083d110 ====

void FUN_0083d110(float param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined4 auStack_8c [3];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  if (*(char *)(in_ECX + 4) == '\0') {
    return;
  }
  if (*(int *)(in_ECX + 0x20) == 0) {
    return;
  }
  if (*(char *)(in_ECX + 0x1c) == '\0') {
    return;
  }
  param_1 = param_1 + *(float *)(in_ECX + 100);
  fVar7 = *(float *)(in_ECX + 0x68) * DAT_0099d0f8;
  *(float *)(in_ECX + 100) = param_1;
  if (param_1 < fVar7) {
    if (param_1 < *(float *)(in_ECX + 0x68)) goto LAB_0083d172;
    param_1 = param_1 - *(float *)(in_ECX + 0x68);
  }
  else {
    param_1 = 0.0;
  }
  *(float *)(in_ECX + 100) = param_1;
LAB_0083d172:
  FUN_005ca8b0(*(float *)(in_ECX + 100) / *(float *)(in_ECX + 0x68),0x3f800000,0);
  piVar1 = (int *)FUN_005ca7a0();
  iVar2 = (**(code **)(*piVar1 + 0x14))();
  auStack_8c[0] = DAT_009a09b8;
  if (iVar2 != 0) {
    puVar5 = (undefined4 *)(iVar2 + 0xe0);
    puVar6 = (undefined4 *)(in_ECX + 0x84);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    auStack_8c[1] = auStack_8c[0];
    auStack_8c[2] = 0;
    uVar3 = FUN_005cb660(auStack_40,auStack_8c);
    thunk_FUN_0079ee7b(auStack_80,(undefined4 *)(iVar2 + 0xe0),uVar3);
    puVar5 = auStack_8c;
    puVar6 = (undefined4 *)(in_ECX + 0x24);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(in_ECX + 0x54) = 0;
    *(undefined4 *)(in_ECX + 0x58) = 0;
    *(undefined4 *)(in_ECX + 0x5c) = 0;
  }
  return;
}


// ==== FUN_0083d230 @ 0x0083d230 ====

void FUN_0083d230(char param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(char *)(in_ECX + 0x1c) = param_1;
  *(undefined4 *)(in_ECX + 100) = 0;
  if (param_1 != '\x01') {
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    *(undefined4 *)(in_ECX + 0xb8) = 0;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    *(undefined4 *)(in_ECX + 0xa4) = 0;
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    *(undefined4 *)(in_ECX + 0x9c) = 0;
    *(undefined4 *)(in_ECX + 0x94) = 0;
    *(undefined4 *)(in_ECX + 0x90) = 0;
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    *(undefined4 *)(in_ECX + 0x88) = 0;
    uVar1 = DAT_0099d080;
    *(undefined4 *)(in_ECX + 0xc0) = DAT_0099d080;
    *(undefined4 *)(in_ECX + 0xac) = uVar1;
    *(undefined4 *)(in_ECX + 0x98) = uVar1;
    *(undefined4 *)(in_ECX + 0x84) = uVar1;
  }
  return;
}


// ==== FUN_0083d2e0 @ 0x0083d2e0 ====

void FUN_0083d2e0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  *in_ECX = &PTR_FUN_00a0fa28;
  in_ECX[0x1b] = 0xffffffff;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[8] = 0;
  thunk_FUN_0079f761(local_40,0x3c23d70a,0x3c23d70a,0);
  puVar2 = local_40;
  puVar3 = in_ECX + 9;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  return;
}


// ==== FUN_0083d360 @ 0x0083d360 ====

void FUN_0083d360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fa28;
  FUN_0083d000();
  *in_ECX = &PTR_FUN_00a0fa14;
  return;
}


// ==== FUN_0083d380 @ 0x0083d380 ====

undefined4 FUN_0083d380(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((*(char *)(in_ECX + 4) == '\0') || (*(int *)(in_ECX + 0xc4) == 0)) {
    return 0;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_weaponline_00a0fa00,10);
  uVar1 = FUN_004b9e30(local_1c);
  if (local_4 < 0x10) {
    return uVar1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0083d3f0 @ 0x0083d3f0 ====

void FUN_0083d3f0(short *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *in_ECX;
  
  if ((((in_ECX[3] != *(int *)(param_1 + 2)) || (in_ECX[4] != *(int *)(param_1 + 4))) ||
      (in_ECX[5] != *(int *)(param_1 + 6))) ||
     ((in_ECX[6] != *(int *)(param_1 + 8) || ((short)in_ECX[2] != *param_1)))) {
    if ((char)in_ECX[1] == '\x01') {
      FUN_0083d000();
    }
    *(short *)(in_ECX + 2) = *param_1;
    in_ECX[3] = *(int *)(param_1 + 2);
    in_ECX[4] = *(int *)(param_1 + 4);
    iVar1 = *(int *)(param_1 + 6);
    in_ECX[5] = iVar1;
    in_ECX[6] = *(int *)(param_1 + 8);
    *(char *)(in_ECX + 7) = (char)param_1[10];
    *(undefined1 *)((int)in_ECX + 0x1d) = *(undefined1 *)((int)param_1 + 0x15);
    in_ECX[0x1c] = in_ECX[3];
    in_ECX[0x1d] = in_ECX[5];
    in_ECX[0x1e] = in_ECX[4];
    in_ECX[0x1f] = in_ECX[6];
    iVar1 = (**(code **)(*DAT_00b5a6dc + 0x18))
                      (0,CONCAT22((short)((uint)iVar1 >> 0x10),(short)in_ECX[2]));
    if (iVar1 != 0) {
      iVar2 = FUN_004236c0(iVar1);
      in_ECX[0x31] = iVar2;
      iVar2 = FUN_00839580(iVar1 + 0x1c);
      in_ECX[0x32] = iVar2;
      if ((in_ECX[0x31] != 0) && (iVar2 != 0)) {
        *(undefined1 *)(in_ECX + 0x20) = *(undefined1 *)(iVar1 + 0x70);
        iVar2 = *(int *)(iVar1 + 0x74);
        in_ECX[0x19] = 0;
        in_ECX[0x1a] = iVar2;
        in_ECX[0x2f] = 0;
        in_ECX[0x2e] = 0;
        in_ECX[0x2d] = 0;
        in_ECX[0x2c] = 0;
        in_ECX[0x2a] = 0;
        in_ECX[0x29] = 0;
        in_ECX[0x28] = 0;
        in_ECX[0x27] = 0;
        in_ECX[0x25] = 0;
        in_ECX[0x24] = 0;
        in_ECX[0x23] = 0;
        in_ECX[0x22] = 0;
        iVar2 = DAT_0099d080;
        in_ECX[0x30] = DAT_0099d080;
        in_ECX[0x2b] = iVar2;
        in_ECX[0x26] = iVar2;
        in_ECX[0x21] = iVar2;
        if ((*(int *)(iVar1 + 0x4c) != 0) && (*(int *)(iVar1 + 0x68) != 0)) {
          pvVar3 = operator_new(0x40);
          if (pvVar3 == (void *)0x0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_005caa30();
          }
          in_ECX[8] = iVar2;
          FUN_005ca810(iVar1 + 0x38,0);
          FUN_005cab40(iVar1 + 0x54);
        }
        (**(code **)(*in_ECX + 8))((char)in_ECX[7]);
        *(undefined1 *)(in_ECX + 1) = 1;
      }
    }
  }
  return;
}


// ==== FUN_0083d5c0 @ 0x0083d5c0 ====

void FUN_0083d5c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fa28;
  FUN_0083d000();
  *in_ECX = &PTR_FUN_00a0fa14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083d5f0 @ 0x0083d5f0 ====

void FUN_0083d5f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fac8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083d650 @ 0x0083d650 ====

void FUN_0083d650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fad8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d974 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d974 = in_ECX;
  return;
}


// ==== FUN_0083d680 @ 0x0083d680 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083d680(undefined4 *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  int *piStack_1c;
  float fStack_18;
  int *piStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((int *)param_2[9] != (int *)0x0) {
    iVar5 = (**(code **)(*(int *)param_2[9] + 4))();
    piStack_1c = (int *)*param_1;
    iVar6 = (**(code **)(*piStack_1c + 0xc))();
    fStack_c = *(float *)(iVar5 + 0x10) + (float)param_1[5];
    fStack_8 = *(float *)(iVar5 + 0x14) + (float)param_1[6];
    fStack_4 = *(float *)(iVar5 + 0x18) + (float)param_1[7];
    fVar7 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar6 + 0x28),*(undefined4 *)(iVar6 + 0x2c));
    fVar8 = (float10)FUN_0040d0a0(0,DAT_00b4fe04);
    FUN_0040d600(&piStack_14,(float)fVar8);
    pfVar1 = (float *)(param_2 + 1);
    *pfVar1 = fStack_c;
    param_2[2] = (int)fStack_8;
    param_2[3] = (int)fStack_4;
    *pfVar1 = (float)piStack_14 * (float)fVar7 + *pfVar1;
    param_2[3] = (int)(fStack_10 * (float)fVar7 + (float)param_2[3]);
    if ((*(float *)(iVar6 + 0x20) <= _DAT_00a0fabc) ||
       (*(float *)(iVar6 + 0x24) < *(float *)(iVar6 + 0x20))) {
      iVar5 = (**(code **)(*piStack_1c + 8))();
      param_2[8] = *(int *)(iVar5 + 4);
    }
    else {
      fVar7 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x24));
      param_2[8] = (int)(float)fVar7;
    }
    fVar2 = (float)*(int *)(iVar6 + 0x3c);
    if (*(int *)(iVar6 + 0x3c) < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float)*(int *)(iVar6 + 0x38);
    if (*(int *)(iVar6 + 0x38) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar7 = (float10)FUN_0040d0a0(fVar3,fVar2);
    *param_2 = (int)ROUND(fVar7);
    if ((((float)param_1[8] == 0.0) && ((float)param_1[9] == 0.0)) && ((float)param_1[10] == 0.0)) {
      param_2[4] = *(int *)(iVar6 + 0x40);
      param_2[5] = *(int *)(iVar6 + 0x44);
      param_2[6] = *(int *)(iVar6 + 0x48);
    }
    else {
      fStack_4 = SQRT((float)param_1[8] * (float)param_1[8] +
                      (float)param_1[10] * (float)param_1[10] +
                      (float)param_1[9] * (float)param_1[9]);
      fStack_c = fStack_4 * (float)param_1[8];
      fStack_8 = fStack_4 * (float)param_1[9];
      fStack_4 = fStack_4 * (float)param_1[10];
      param_2[4] = (int)fStack_c;
      param_2[5] = (int)fStack_8;
      param_2[6] = (int)fStack_4;
    }
    uVar4 = DAT_00b4fe04;
    param_2[5] = 0;
    fVar7 = (float10)FUN_0040d0a0(0,uVar4);
    FUN_0040d600(&piStack_1c,(float)fVar7);
    piStack_14 = piStack_1c;
    param_2[4] = (int)((float)param_2[4] + (float)piStack_1c);
    fStack_10 = fStack_18;
    param_2[6] = (int)((float)param_2[6] + fStack_18);
    fVar7 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar6 + 0x30),*(undefined4 *)(iVar6 + 0x34));
    param_2[7] = (int)(float)fVar7;
    param_2[0xe] = (int)*pfVar1;
    param_2[0xf] = param_2[2];
    param_2[0x10] = param_2[3];
    param_2[0xb] = (int)*pfVar1;
    param_2[0xc] = param_2[2];
    param_2[0xd] = param_2[3];
    param_2[10] = 0;
  }
  return;
}


// ==== FUN_0083d940 @ 0x0083d940 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083d940(int param_1,undefined4 *param_2,uint *param_3)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  float10 fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 uStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  uint uStack_74;
  float fStack_70;
  float fStack_68;
  float fStack_64;
  uint uStack_60;
  float fStack_5c;
  float fStack_58;
  int iStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  
  if ((param_3[10] < *param_3) && (param_3[9] != 0)) {
    piVar3 = (int *)*param_2;
    fStack_7c = (float)(**(code **)(*piVar3 + 0x10))();
    iVar6 = (**(code **)(*(int *)param_3[9] + 4))();
    iStack_54 = (**(code **)(*piVar3 + 0xc))();
    uVar7 = *param_3;
    uVar10 = param_3[10] + param_1;
    if (uVar7 < param_3[10] + param_1) {
      uVar10 = uVar7;
    }
    fStack_68 = (float)(int)uVar10;
    param_3[10] = uVar10;
    if ((int)uVar10 < 0) {
      fStack_68 = fStack_68 + _DAT_0099d104;
    }
    fVar13 = (float)(int)uVar7;
    if ((int)uVar7 < 0) {
      fVar13 = fVar13 + _DAT_0099d104;
    }
    fStack_68 = fStack_68 / fVar13;
    uVar7 = (uVar10 * 999) / uVar7;
    uVar9 = 999;
    if (uVar7 < 1000) {
      uVar9 = uVar7;
    }
    FUN_0040ec60(&fStack_50,param_3[0x17]);
    if (*(int *)(iVar6 + 0xa8) != 0) {
      fVar12 = (float10)FUN_005aa2a0(uVar9,uVar10);
      fStack_44 = (float)fVar12;
    }
    if (*(int *)(iVar6 + 0x88) != 0) {
      FUN_005aa3a0(&fStack_78,uVar9,uVar10);
      fStack_64 = fStack_78;
      uStack_60 = uStack_74;
      fStack_5c = fStack_70;
      fStack_58 = fStack_44;
      fStack_50 = fStack_78;
      uStack_4c = uStack_74;
      fStack_48 = fStack_70;
    }
    uVar7 = FUN_0040ead0(&fStack_50);
    param_3[0x17] = uVar7;
    if (*(int *)(iVar6 + 0x68) == 0) {
      fStack_84 = (float)param_3[8];
      uStack_88 = fStack_84;
    }
    else {
      FUN_005aa3a0(&fStack_78,uVar9,uVar10);
      uStack_88 = fStack_78 * (float)param_3[8];
      fStack_84 = fStack_70 * (float)param_3[8];
    }
    iVar5 = iStack_54;
    param_3[0x15] = (uint)uStack_88;
    param_3[0x16] = (uint)fStack_84;
    fVar13 = *(float *)(iStack_54 + 0x18);
    if (fVar13 <= 0.0) {
      fVar13 = 0.0 - *(float *)(iStack_54 + 0x18);
    }
    if (_DAT_00a0fabc < fVar13) {
      param_3[0x18] = (uint)(*(float *)(iStack_54 + 0x18) * fStack_68);
    }
    uVar7 = FUN_00846410(param_3[10]);
    param_3[0x14] = uVar7;
    fVar4 = DAT_0099d0b4;
    fStack_7c = (float)(int)param_3[10];
    fVar13 = *(float *)(iVar5 + 0x4c);
    if ((int)param_3[10] < 0) {
      fStack_7c = fStack_7c + _DAT_0099d104;
    }
    fStack_7c = fStack_7c * DAT_0099d0ec;
    fVar2 = (float)param_3[7];
    pfVar1 = (float *)(param_3 + 0xe);
    fVar15 = *(float *)(iVar5 + 0x50) * DAT_0099d0b4;
    fVar14 = 0.0 - *(float *)(iVar5 + 0x1c);
    *pfVar1 = (float)param_3[1];
    param_3[0xf] = param_3[2];
    param_3[0x10] = param_3[3];
    param_3[0xf] = (uint)(fStack_7c * 0.0 * fStack_7c + (float)param_3[0xf]);
    param_3[0x10] = (uint)(fVar15 * fStack_7c * fStack_7c + (float)param_3[0x10]);
    *pfVar1 = *pfVar1 + fVar13 * fVar4 * fStack_7c * fStack_7c;
    if (fVar14 * fStack_7c + fVar2 <= 0.0) {
      if (fVar14 <= 0.0) {
        fVar13 = 0.0 - fVar14;
      }
      else {
        fVar13 = fVar14;
      }
      if (_DAT_00a0fabc < fVar13) {
        fVar13 = 0.0 - fVar2 / fVar14;
        *pfVar1 = *pfVar1 + (float)param_3[4] * fVar2 * fVar13;
        param_3[0xf] = (uint)((float)param_3[5] * fVar2 * fVar13 + (float)param_3[0xf]);
        param_3[0x10] = (uint)((float)param_3[6] * fVar2 * fVar13 + (float)param_3[0x10]);
        *pfVar1 = *pfVar1 + (float)param_3[4] * fVar4 * fVar14 * fVar13 * fVar13;
        param_3[0xf] = (uint)((float)param_3[5] * fVar4 * fVar14 * fVar13 * fVar13 +
                             (float)param_3[0xf]);
        param_3[0x10] =
             (uint)((float)param_3[6] * fVar4 * fVar14 * fVar13 * fVar13 + (float)param_3[0x10]);
      }
    }
    else {
      *pfVar1 = *pfVar1 + (float)param_3[4] * fVar2 * fStack_7c;
      param_3[0xf] = (uint)((float)param_3[5] * fVar2 * fStack_7c + (float)param_3[0xf]);
      param_3[0x10] = (uint)((float)param_3[6] * fVar2 * fStack_7c + (float)param_3[0x10]);
      param_3[0xf] = (uint)((float)param_3[0xf] +
                           (float)param_3[5] * fVar4 * fVar14 * fStack_7c * fStack_7c);
      *pfVar1 = (float)param_3[4] * fVar4 * fVar14 * fStack_7c * fStack_7c + *pfVar1;
      param_3[0x10] =
           (uint)((float)param_3[0x10] + (float)param_3[6] * fVar4 * fVar14 * fStack_7c * fStack_7c)
      ;
    }
    param_3[0xf] = (uint)(*(float *)(iVar6 + 0x14) + (float)param_2[6]);
    if (*(char *)(iStack_54 + 0x10) != '\0') {
      fStack_64 = *pfVar1;
      uStack_60 = param_3[0xf];
      fStack_5c = (float)param_3[0x10];
      fStack_78 = (float)param_3[0xb];
      uStack_88 = fStack_64 - fStack_78;
      uStack_74 = param_3[0xc];
      fStack_70 = (float)param_3[0xd];
      fStack_80 = fStack_5c - fStack_70;
      fStack_84 = 0.0;
      if (_DAT_00a0fabc < SQRT(fStack_80 * fStack_80 + uStack_88 * uStack_88)) {
        thunk_FUN_0079e1ba(&uStack_88,&uStack_88);
        FUN_0040d620(&fStack_80,(int)register0x00000010 + -0x90);
        puVar8 = (uint *)FUN_005acde0(&fStack_48,&fStack_80);
        puVar11 = param_3 + 0x1c;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
        param_3[0xb] = (uint)*pfVar1;
        param_3[0xc] = param_3[0xf];
        param_3[0xd] = param_3[0x10];
      }
    }
  }
  return;
}


// ==== FUN_0083de60 @ 0x0083de60 ====

void FUN_0083de60(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (((int *)*param_2 != (int *)0x0) &&
     (iVar3 = (**(code **)(*(int *)*param_2 + 0x10))(), iVar3 != 0)) {
    puVar1 = *(undefined4 **)(param_3 + 4);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_0083d940(param_1,param_2,puVar2[2]);
    }
  }
  return;
}


// ==== FUN_0083deb0 @ 0x0083deb0 ====

void FUN_0083deb0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5d974 = 0;
  *in_ECX = &PTR_FUN_00a0fac8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083df20 @ 0x0083df20 ====

void FUN_0083df20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fb74;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d978 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d978 = in_ECX;
  return;
}


// ==== FUN_0083df50 @ 0x0083df50 ====

void FUN_0083df50(undefined4 *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int iVar8;
  float *pfVar9;
  float10 fVar10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar7 = (int *)*param_1;
  iVar8 = (**(code **)(*piVar7 + 0xc))();
  fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar8 + 0x28),*(undefined4 *)(iVar8 + 0x2c));
  fVar6 = (float)fVar10;
  fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar8 + 0x30),*(undefined4 *)(iVar8 + 0x34));
  param_2[7] = (int)(float)fVar10;
  pfVar9 = (float *)FUN_0040ecc0(&uStack_c);
  fVar2 = pfVar9[1];
  fVar3 = pfVar9[2];
  fVar4 = (float)param_1[2];
  fVar5 = (float)param_1[3];
  pfVar1 = (float *)(param_2 + 1);
  *pfVar1 = (float)param_1[1] + *pfVar9 * fVar6;
  param_2[2] = (int)(fVar4 + fVar2 * fVar6);
  param_2[3] = (int)(fVar5 + fVar3 * fVar6);
  uStack_c = 0;
  param_2[4] = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  if ((*(float *)(iVar8 + 0x20) <= DAT_00a0fb68) ||
     (*(float *)(iVar8 + 0x24) < *(float *)(iVar8 + 0x20))) {
    iVar8 = (**(code **)(*piVar7 + 8))();
    param_2[8] = *(int *)(iVar8 + 4);
  }
  else {
    fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar8 + 0x20),*(undefined4 *)(iVar8 + 0x24));
    param_2[8] = (int)(float)fVar10;
  }
  if (DAT_00a0fb68 < (float)param_2[7] || DAT_00a0fb68 == (float)param_2[7]) {
    iVar8 = (int)ROUND((fVar6 / (float)param_2[7]) * DAT_009b012c);
    if (iVar8 == 0) {
      iVar8 = 1;
    }
    *param_2 = iVar8;
  }
  else {
    *param_2 = 1000;
  }
  param_2[0xe] = (int)*pfVar1;
  param_2[0xf] = param_2[2];
  param_2[0x10] = param_2[3];
  param_2[10] = 0;
  param_2[0xb] = (int)*pfVar1;
  param_2[0xc] = param_2[2];
  param_2[0xd] = param_2[3];
  return;
}


// ==== FUN_0083e110 @ 0x0083e110 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083e110(int param_1,undefined4 *param_2,uint *param_3)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  float fVar13;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  undefined4 uStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  float fStack_a8;
  float fStack_a4;
  undefined4 uStack_a0;
  float fStack_9c;
  float fStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [8];
  undefined4 auStack_88 [2];
  undefined1 auStack_80 [56];
  undefined4 auStack_48 [18];
  
  if ((param_3[10] < *param_3) && (param_3[9] != 0)) {
    piVar2 = (int *)*param_2;
    uStack_94 = (**(code **)(*piVar2 + 0x10))();
    iVar3 = (**(code **)(*(int *)param_3[9] + 4))();
    iVar4 = (**(code **)(*piVar2 + 0xc))();
    uVar6 = *param_3;
    uVar8 = param_3[10] + param_1;
    if (uVar6 < param_3[10] + param_1) {
      uVar8 = uVar6;
    }
    fStack_c4 = (float)(int)uVar8;
    param_3[10] = uVar8;
    if ((int)uVar8 < 0) {
      fStack_c4 = fStack_c4 + _DAT_0099d104;
    }
    fVar5 = (float)(int)uVar6;
    if ((int)uVar6 < 0) {
      fVar5 = fVar5 + _DAT_0099d104;
    }
    fStack_c4 = fStack_c4 / fVar5;
    fVar5 = (float)((uVar8 * 999) / uVar6);
    fStack_d0 = 1.3999e-42;
    if ((uint)fVar5 < 1000) {
      fStack_d0 = fVar5;
    }
    FUN_0040ec60(&fStack_a4,param_3[0x17]);
    if (*(int *)(iVar3 + 0xa8) != 0) {
      fVar12 = (float10)FUN_005aa2a0(fStack_d0,uVar8);
      fStack_98 = (float)fVar12;
    }
    if (*(int *)(iVar3 + 0x88) != 0) {
      FUN_005aa3a0(&fStack_b0,fStack_d0,uVar8);
      fStack_c0 = fStack_b0;
      uStack_bc = uStack_ac;
      fStack_b8 = fStack_a8;
      fStack_b4 = fStack_98;
      fStack_a4 = fStack_b0;
      uStack_a0 = uStack_ac;
      fStack_9c = fStack_a8;
    }
    uVar6 = FUN_0040ead0(&fStack_a4);
    param_3[0x17] = uVar6;
    if (*(int *)(iVar3 + 0x68) == 0) {
      fStack_d0 = (float)param_3[8];
      param_3[0x15] = (uint)fStack_d0;
      param_3[0x16] = (uint)fStack_d0;
      fStack_cc = fStack_d0;
    }
    else {
      FUN_005aa3a0(&fStack_b0,fStack_d0,uVar8);
      fStack_d0 = fStack_b0 * (float)param_3[8];
      fStack_cc = fStack_a8 * (float)param_3[8];
      param_3[0x15] = (uint)fStack_d0;
      param_3[0x16] = (uint)fStack_cc;
    }
    fVar5 = *(float *)(iVar4 + 0x18);
    if (fVar5 <= 0.0) {
      fVar5 = 0.0 - *(float *)(iVar4 + 0x18);
    }
    if (DAT_00a0fb68 < fVar5) {
      param_3[0x18] = (uint)(*(float *)(iVar4 + 0x18) * fStack_c4);
    }
    uVar6 = FUN_00846410(param_3[10]);
    fVar13 = DAT_0099d080;
    param_3[0x14] = uVar6;
    fVar5 = *(float *)(iVar4 + 0x60);
    fVar13 = fVar13 - fStack_c4;
    fStack_d0 = (float)param_3[1] * fVar13 + *(float *)(iVar4 + 0x58) * fStack_c4;
    pfVar1 = (float *)(param_3 + 0xe);
    fStack_cc = (float)param_3[2] * fVar13 + *(float *)(iVar4 + 0x5c) * fStack_c4;
    *pfVar1 = fStack_d0;
    fStack_c8 = (float)param_3[3] * fVar13 + fVar5 * fStack_c4;
    param_3[0xf] = (uint)fStack_cc;
    param_3[0x10] = (uint)fStack_c8;
    if (*(char *)(iVar4 + 0x10) != '\0') {
      fStack_d0 = *pfVar1 - (float)param_3[0xb];
      fStack_cc = (float)param_3[0xf] - (float)param_3[0xc];
      fStack_c8 = (float)param_3[0x10] - (float)param_3[0xd];
      if (DAT_00a0fb68 < SQRT(fStack_d0 * fStack_d0 + fStack_cc * fStack_cc + fStack_c8 * fStack_c8)
         ) {
        thunk_FUN_0079e1ba(&fStack_d0,&fStack_d0);
        FUN_0040d620(&fStack_c0,&fStack_d0);
        puVar7 = (uint *)FUN_005acde0(auStack_80,&fStack_c0);
        puVar10 = param_3 + 0x1c;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar10 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar10 = puVar10 + 1;
        }
        param_3[0xb] = (uint)*pfVar1;
        param_3[0xc] = param_3[0xf];
        param_3[0xd] = param_3[0x10];
      }
    }
    fVar5 = (float)param_2[8];
    if (DAT_00a0fb68 <=
        SQRT((float)param_2[10] * (float)param_2[10] +
             (float)param_2[9] * (float)param_2[9] + fVar5 * fVar5)) {
      FUN_0040d620(auStack_90,param_2 + 8);
      thunk_FUN_0079fb96(auStack_80,auStack_90);
      puVar9 = auStack_88;
      puVar11 = auStack_48;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      thunk_FUN_0079e5a0(pfVar1,pfVar1,auStack_48);
    }
  }
  return;
}


// ==== FUN_0083e4c0 @ 0x0083e4c0 ====

void FUN_0083e4c0(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (((int *)*param_2 != (int *)0x0) &&
     (iVar3 = (**(code **)(*(int *)*param_2 + 0x10))(), iVar3 != 0)) {
    puVar1 = *(undefined4 **)(param_3 + 4);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_0083e110(param_1,param_2,puVar2[2]);
    }
  }
  return;
}


// ==== FUN_0083e510 @ 0x0083e510 ====

void FUN_0083e510(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5d978 = 0;
  *in_ECX = &PTR_FUN_00a0fac8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083e580 @ 0x0083e580 ====

void FUN_0083e580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fc10;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d97c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d97c = in_ECX;
  return;
}


// ==== FUN_0083e5b0 @ 0x0083e5b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083e5b0(undefined4 *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  float fVar11;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((int *)param_2[9] != (int *)0x0) {
    iVar6 = (**(code **)(*(int *)param_2[9] + 4))();
    piVar5 = (int *)*param_1;
    iVar7 = (**(code **)(*piVar5 + 0xc))();
    fVar1 = *(float *)(iVar6 + 0x10);
    fVar2 = (float)param_1[5];
    fVar11 = *(float *)(iVar6 + 0x14) + (float)param_1[6];
    fVar3 = *(float *)(iVar6 + 0x18);
    fVar4 = (float)param_1[7];
    if ((((float)param_1[8] == 0.0) && ((float)param_1[9] == 0.0)) && ((float)param_1[10] == 0.0)) {
      param_2[4] = *(int *)(iVar7 + 0x40);
      param_2[5] = *(int *)(iVar7 + 0x44);
      param_2[6] = *(int *)(iVar7 + 0x48);
    }
    else {
      fStack_4 = SQRT((float)param_1[8] * (float)param_1[8] +
                      (float)param_1[10] * (float)param_1[10] +
                      (float)param_1[9] * (float)param_1[9]);
      fStack_c = fStack_4 * (float)param_1[8];
      fStack_8 = fStack_4 * (float)param_1[9];
      fStack_4 = fStack_4 * (float)param_1[10];
      param_2[4] = (int)fStack_c;
      param_2[5] = (int)fStack_8;
      param_2[6] = (int)fStack_4;
    }
    iVar6 = *(int *)(iVar7 + 4);
    if (((iVar6 == 2) || (iVar6 == 7)) || (iVar6 == 6)) {
      pfVar8 = (float *)FUN_0040ecc0(&fStack_c);
      param_2[4] = (int)(*pfVar8 + (float)param_2[4]);
      param_2[5] = (int)(pfVar8[1] + (float)param_2[5]);
      param_2[6] = (int)(pfVar8[2] + (float)param_2[6]);
    }
    fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar7 + 0x30),*(undefined4 *)(iVar7 + 0x34));
    param_2[7] = (int)(float)fVar10;
    pfVar8 = (float *)(param_2 + 1);
    *pfVar8 = fVar1 + fVar2;
    param_2[2] = (int)fVar11;
    param_2[3] = (int)(fVar3 + fVar4);
    iVar6 = *(int *)(iVar7 + 4);
    if (((iVar6 == 1) || (iVar6 == 5)) || ((iVar6 == 7 || (iVar6 == 6)))) {
      fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar7 + 0x28),*(undefined4 *)(iVar7 + 0x2c));
      fVar3 = (float)fVar10;
      pfVar9 = (float *)FUN_0040ecc0(&fStack_c);
      fVar1 = *pfVar9;
      fVar2 = pfVar9[2];
      param_2[2] = (int)((float)param_2[2] + pfVar9[1] * fVar3);
      *pfVar8 = *pfVar8 + fVar1 * fVar3;
      param_2[3] = (int)((float)param_2[3] + fVar2 * fVar3);
      if ((*(int *)(iVar7 + 4) == 5) || (*(int *)(iVar7 + 4) == 6)) {
        param_2[2] = (int)fVar11;
      }
    }
    if ((*(float *)(iVar7 + 0x20) <= _DAT_00a0fc04) ||
       (*(float *)(iVar7 + 0x24) < *(float *)(iVar7 + 0x20))) {
      iVar6 = (**(code **)(*piVar5 + 8))();
      param_2[8] = *(int *)(iVar6 + 4);
    }
    else {
      fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(iVar7 + 0x20),*(undefined4 *)(iVar7 + 0x24));
      param_2[8] = (int)(float)fVar10;
    }
    fVar1 = (float)*(int *)(iVar7 + 0x3c);
    if (*(int *)(iVar7 + 0x3c) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (float)*(int *)(iVar7 + 0x38);
    if (*(int *)(iVar7 + 0x38) < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar10 = (float10)FUN_0040d0a0(fVar2,fVar1);
    param_2[10] = 0;
    *param_2 = (int)ROUND(fVar10);
    param_2[0xe] = (int)*pfVar8;
    param_2[0xf] = param_2[2];
    param_2[0x10] = param_2[3];
    param_2[0xb] = (int)*pfVar8;
    param_2[0xc] = param_2[2];
    param_2[0xd] = param_2[3];
  }
  return;
}


// ==== FUN_0083e8a0 @ 0x0083e8a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083e8a0(int param_1,undefined4 *param_2,uint *param_3)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  float10 fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 uStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  
  if ((param_3[10] < *param_3) && (param_3[9] != 0)) {
    piVar3 = (int *)*param_2;
    fStack_70 = (float)(**(code **)(*piVar3 + 0x10))();
    iVar4 = (**(code **)(*(int *)param_3[9] + 4))();
    iVar5 = (**(code **)(*piVar3 + 0xc))();
    uVar6 = *param_3;
    uVar8 = param_3[10] + param_1;
    if (uVar6 < param_3[10] + param_1) {
      uVar8 = uVar6;
    }
    fStack_74 = (float)(int)uVar8;
    param_3[10] = uVar8;
    if ((int)uVar8 < 0) {
      fStack_74 = fStack_74 + _DAT_0099d104;
    }
    fVar11 = (float)(int)uVar6;
    if ((int)uVar6 < 0) {
      fVar11 = fVar11 + _DAT_0099d104;
    }
    fStack_74 = fStack_74 / fVar11;
    uVar6 = (uVar8 * 999) / uVar6;
    uStack_80 = 1.3999e-42;
    if (uVar6 < 1000) {
      uStack_80 = (float)uVar6;
    }
    FUN_0040ec60(&fStack_50,param_3[0x17]);
    if (*(int *)(iVar4 + 0xa8) != 0) {
      fVar10 = (float10)FUN_005aa2a0(uStack_80,uVar8);
      fStack_44 = (float)fVar10;
    }
    if (*(int *)(iVar4 + 0x88) != 0) {
      FUN_005aa3a0(&fStack_6c,uStack_80,uVar8);
      fStack_60 = fStack_6c;
      uStack_5c = uStack_68;
      fStack_58 = fStack_64;
      fStack_54 = fStack_44;
      fStack_50 = fStack_6c;
      uStack_4c = uStack_68;
      fStack_48 = fStack_64;
    }
    uVar6 = FUN_0040ead0(&fStack_50);
    param_3[0x17] = uVar6;
    if (*(int *)(iVar4 + 0x68) == 0) {
      uStack_80 = (float)param_3[8];
      param_3[0x15] = (uint)uStack_80;
      param_3[0x16] = (uint)uStack_80;
      fStack_7c = uStack_80;
    }
    else {
      FUN_005aa3a0(&fStack_6c,uStack_80,uVar8);
      uStack_80 = fStack_6c * (float)param_3[8];
      fStack_7c = fStack_64 * (float)param_3[8];
      param_3[0x15] = (uint)uStack_80;
      param_3[0x16] = (uint)fStack_7c;
    }
    fVar11 = *(float *)(iVar5 + 0x18);
    if (fVar11 <= 0.0) {
      fVar11 = 0.0 - *(float *)(iVar5 + 0x18);
    }
    if (_DAT_00a0fc04 < fVar11) {
      param_3[0x18] = (uint)(*(float *)(iVar5 + 0x18) * fStack_74);
    }
    uVar6 = FUN_00846410(param_3[10]);
    param_3[0x14] = uVar6;
    fVar11 = DAT_0099d0b4;
    fStack_70 = (float)(int)param_3[10];
    if ((int)param_3[10] < 0) {
      fStack_70 = fStack_70 + _DAT_0099d104;
    }
    fStack_70 = fStack_70 * DAT_0099d0ec;
    fVar2 = (float)param_3[7];
    pfVar1 = (float *)(param_3 + 0xe);
    fVar12 = 0.0 - *(float *)(iVar5 + 0x1c);
    *pfVar1 = (float)param_3[1];
    param_3[0xf] = param_3[2];
    param_3[0x10] = param_3[3];
    fStack_64 = *(float *)(iVar5 + 0x54) * fVar11 * fStack_70 * fStack_70;
    fVar13 = *pfVar1 + *(float *)(iVar5 + 0x4c) * fVar11 * fStack_70 * fStack_70;
    param_3[0xf] = (uint)((float)param_3[0xf] +
                         *(float *)(iVar5 + 0x50) * fVar11 * fStack_70 * fStack_70);
    param_3[0x10] = (uint)((float)param_3[0x10] + fStack_64);
    *pfVar1 = fVar13;
    if (fVar12 * fStack_70 + fVar2 <= 0.0) {
      if (fVar12 <= 0.0) {
        fVar13 = 0.0 - fVar12;
      }
      else {
        fVar13 = fVar12;
      }
      if (_DAT_00a0fc04 < fVar13) {
        fVar13 = 0.0 - fVar2 / fVar12;
        *pfVar1 = *pfVar1 + (float)param_3[4] * fVar2 * fVar13;
        param_3[0xf] = (uint)((float)param_3[5] * fVar2 * fVar13 + (float)param_3[0xf]);
        param_3[0x10] = (uint)((float)param_3[6] * fVar2 * fVar13 + (float)param_3[0x10]);
        *pfVar1 = *pfVar1 + (float)param_3[4] * fVar11 * fVar12 * fVar13 * fVar13;
        param_3[0xf] = (uint)((float)param_3[5] * fVar11 * fVar12 * fVar13 * fVar13 +
                             (float)param_3[0xf]);
        param_3[0x10] =
             (uint)((float)param_3[6] * fVar11 * fVar12 * fVar13 * fVar13 + (float)param_3[0x10]);
      }
    }
    else {
      *pfVar1 = fVar13 + (float)param_3[4] * fVar2 * fStack_70;
      param_3[0xf] = (uint)((float)param_3[0xf] + (float)param_3[5] * fVar2 * fStack_70);
      param_3[0x10] = (uint)((float)param_3[0x10] + (float)param_3[6] * fVar2 * fStack_70);
      *pfVar1 = *pfVar1 + (float)param_3[4] * fVar11 * fVar12 * fStack_70 * fStack_70;
      param_3[0xf] = (uint)((float)param_3[0xf] +
                           (float)param_3[5] * fVar11 * fVar12 * fStack_70 * fStack_70);
      param_3[0x10] =
           (uint)((float)param_3[0x10] + (float)param_3[6] * fVar11 * fVar12 * fStack_70 * fStack_70
                 );
    }
    if (*(char *)(iVar5 + 0x10) != '\0') {
      uStack_80 = *pfVar1 - (float)param_3[0xb];
      fStack_7c = (float)param_3[0xf] - (float)param_3[0xc];
      fStack_78 = (float)param_3[0x10] - (float)param_3[0xd];
      if (_DAT_00a0fc04 <
          SQRT(uStack_80 * uStack_80 + fStack_7c * fStack_7c + fStack_78 * fStack_78)) {
        thunk_FUN_0079e1ba(&uStack_80,&uStack_80);
        FUN_0040d620(&uStack_68,(int)register0x00000010 + -0x88);
        puVar7 = (uint *)FUN_005acde0(&fStack_48,&uStack_68);
        puVar9 = param_3 + 0x1c;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        param_3[0xb] = (uint)*pfVar1;
        param_3[0xc] = param_3[0xf];
        param_3[0xd] = param_3[0x10];
      }
    }
  }
  return;
}


// ==== FUN_0083edb0 @ 0x0083edb0 ====

void FUN_0083edb0(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (((int *)*param_2 != (int *)0x0) &&
     (iVar3 = (**(code **)(*(int *)*param_2 + 0x10))(), iVar3 != 0)) {
    puVar1 = *(undefined4 **)(param_3 + 4);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_0083e8a0(param_1,param_2,puVar2[2]);
    }
  }
  return;
}


// ==== FUN_0083ee00 @ 0x0083ee00 ====

void FUN_0083ee00(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5d97c = 0;
  *in_ECX = &PTR_FUN_00a0fac8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083ee30 @ 0x0083ee30 ====

void FUN_0083ee30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fc60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083ee50 @ 0x0083ee50 ====

void FUN_0083ee50(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0083ee52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_0083ee60 @ 0x0083ee60 ====

int FUN_0083ee60(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0083ee70 @ 0x0083ee70 ====

int FUN_0083ee70(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_0083ee80 @ 0x0083ee80 ====

void FUN_0083ee80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fc7c;
  (*(code *)PTR_FUN_00a0fc84)();
  *in_ECX = &PTR_FUN_00a0fc60;
  return;
}


// ==== FUN_0083eea0 @ 0x0083eea0 ====

void FUN_0083eea0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined1 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  return;
}


// ==== FUN_0083eec0 @ 0x0083eec0 ====

void FUN_0083eec0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    return;
  }
  (**(code **)(*DAT_00b5b010 + 0x18))(*(undefined4 *)(in_ECX + 0x9c));
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  _free(*(void **)(in_ECX + 0x98));
  return;
}


// ==== FUN_0083ef10 @ 0x0083ef10 ====

void FUN_0083ef10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fc7c;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[0x24] = 0;
  *(undefined1 *)(in_ECX + 0x25) = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  return;
}


// ==== FUN_0083ef40 @ 0x0083ef40 ====

void FUN_0083ef40(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(undefined4 *)(in_ECX + 0x90) = uVar1;
  puVar4 = (undefined4 *)(in_ECX + 8);
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = operator_new(0x2c);
  uVar1 = DAT_0099d0dc;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar2 + 0x14) = 0;
    *(undefined4 *)(puVar2 + 0x18) = 0;
    *(undefined4 *)(puVar2 + 0x1c) = 0;
    *(undefined4 *)(puVar2 + 0x20) = uVar1;
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    *(undefined4 *)(puVar2 + 8) = 0;
    *(undefined4 *)(puVar2 + 0xc) = 0;
    *(undefined4 *)(puVar2 + 0x10) = 0;
    *(undefined4 *)(puVar2 + 0x24) = 0;
    *(undefined4 *)(puVar2 + 0x28) = 0;
  }
  *(undefined1 **)(in_ECX + 0x98) = puVar2;
  uVar1 = (**(code **)(*DAT_00b5b010 + 8))();
  *(undefined4 *)(in_ECX + 0x9c) = uVar1;
  *(undefined1 *)(in_ECX + 0x94) = 0;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_0083f020 @ 0x0083f020 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083f020(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int in_ECX;
  float fVar8;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(char *)(in_ECX + 0x94) != '\x01') {
    fVar4 = *(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc);
    param_1 = param_1 - *(int *)(in_ECX + 0x90);
    fVar5 = *(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10);
    fVar8 = *(float *)(in_ECX + 0x20) - *(float *)(in_ECX + 0x14);
    fVar4 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar8 * fVar8);
    fVar8 = (float)param_1;
    if (param_1 < 0) {
      fVar8 = fVar8 + _DAT_0099d104;
    }
    fVar8 = fVar8 * DAT_0099d0ec * *(float *)(in_ECX + 0x30);
    if (fVar4 <= fVar8) {
      *(undefined1 *)(in_ECX + 0x94) = 1;
      fVar8 = fVar4;
    }
    local_10 = *(float *)(in_ECX + 0xc) + fVar8 * *(float *)(in_ECX + 0x24);
    local_c = *(float *)(in_ECX + 0x10) + *(float *)(in_ECX + 0x28) * fVar8;
    pfVar1 = (float *)(in_ECX + 0x34);
    *pfVar1 = local_10;
    *(float *)(in_ECX + 0x38) = local_c;
    local_8 = *(float *)(in_ECX + 0x14) + *(float *)(in_ECX + 0x2c) * fVar8;
    *(float *)(in_ECX + 0x3c) = local_8;
    puVar7 = (undefined4 *)FUN_0040d620(&local_10,(float *)(in_ECX + 0x24));
    *(undefined4 *)(in_ECX + 0x40) = *puVar7;
    *(undefined4 *)(in_ECX + 0x44) = puVar7[1];
    *(undefined4 *)(in_ECX + 0x48) = puVar7[2];
    *(undefined4 *)(in_ECX + 0x4c) = puVar7[3];
    thunk_FUN_0079fb96(in_ECX + 0x50,(undefined4 *)(in_ECX + 0x40));
    *(float *)(in_ECX + 0x80) = *pfVar1;
    *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x38);
    *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(in_ECX + 0x3c);
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      uVar2 = *(undefined4 *)(in_ECX + 8);
      *puVar7 = &PTR_FUN_009c2688;
      puVar7[1] = 0;
      puVar7[2] = uVar2;
    }
    iVar3 = *(int *)(in_ECX + 0x98);
    uVar2 = *(undefined4 *)(in_ECX + 0x3c);
    *(float *)(iVar3 + 0x14) = *pfVar1;
    uVar6 = DAT_0099d080;
    *(undefined4 *)(iVar3 + 0x18) = uVar2;
    iVar3 = *(int *)(in_ECX + 0x98);
    *(undefined4 *)(iVar3 + 0x1c) = uVar6;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 0x98) + 8) = *(undefined4 *)(in_ECX + 0x38);
    puVar7[1] = *(undefined4 *)(in_ECX + 0x98);
    FUN_00797a20(puVar7);
  }
  return;
}


// ==== FUN_0083f200 @ 0x0083f200 ====

void FUN_0083f200(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fc7c;
  (*(code *)PTR_FUN_00a0fc84)();
  *in_ECX = &PTR_FUN_00a0fc60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083f230 @ 0x0083f230 ====

void FUN_0083f230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fcd8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083f250 @ 0x0083f250 ====

void FUN_0083f250(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0083f252. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_0083f260 @ 0x0083f260 ====

int FUN_0083f260(void)

{
  int in_ECX;
  
  return in_ECX + 0x2c;
}


// ==== FUN_0083f270 @ 0x0083f270 ====

int FUN_0083f270(void)

{
  int in_ECX;
  
  return in_ECX + 0x4c;
}


// ==== FUN_0083f280 @ 0x0083f280 ====

undefined4 FUN_0083f280(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(in_ECX + -0x24) + 0xc))();
  return *puVar1;
}


// ==== FUN_0083f290 @ 0x0083f290 ====

undefined1 FUN_0083f290(void)

{
  return 0;
}


// ==== FUN_0083f2a0 @ 0x0083f2a0 ====

void FUN_0083f2a0(void)

{
  return;
}


// ==== FUN_0083f2b0 @ 0x0083f2b0 ====

undefined1 FUN_0083f2b0(void)

{
  return 0;
}


// ==== FUN_0083f2c0 @ 0x0083f2c0 ====

undefined1 FUN_0083f2c0(void)

{
  return 0;
}


// ==== FUN_0083f2f0 @ 0x0083f2f0 ====

void FUN_0083f2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fd34;
  in_ECX[1] = &PTR_FUN_00a0fd1c;
  in_ECX[9] = &PTR_FUN_00a0fcf4;
  (*(code *)PTR_FUN_00a0fd3c)();
  in_ECX[9] = &PTR_FUN_00a0f398;
  in_ECX[1] = &PTR_FUN_009bf514;
  *in_ECX = &PTR_FUN_00a0fcd8;
  return;
}


// ==== FUN_0083f330 @ 0x0083f330 ====

void FUN_0083f330(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined1 *)(in_ECX + 0xe8) = 0;
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  return;
}


// ==== FUN_0083f360 @ 0x0083f360 ====

void FUN_0083f360(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  piVar1 = DAT_00b5afac;
  if ((char)in_ECX[10] != '\0') {
    puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0xc))();
    (**(code **)(*piVar1 + 8))(*puVar2,2);
    piVar1 = DAT_00b5a720;
    puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0xc))();
    (**(code **)(*piVar1 + 8))(*puVar2);
    (**(code **)(*DAT_00b5b010 + 0x18))(in_ECX[0x4d]);
    in_ECX[0x4d] = 0;
    (**(code **)(*DAT_00b5d954 + 8))(in_ECX[0x4b]);
    *(undefined1 *)(in_ECX + 10) = 0;
    if ((undefined4 *)in_ECX[0x4c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x4c])(1);
    }
    in_ECX[0x4c] = 0;
  }
  return;
}


// ==== FUN_0083f410 @ 0x0083f410 ====

bool FUN_0083f410(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  iStack_20 = in_ECX + 0x34;
  cVar1 = (**(code **)(*DAT_00b5a988 + 0x24))(0);
  if (cVar1 == '\x01') {
    return false;
  }
  iStack_20 = *(int *)(in_ECX + 4);
  uStack_14 = *(undefined4 *)(in_ECX + 0x10);
  uStack_10 = *(undefined4 *)(in_ECX + 0x14);
  uStack_c = *(undefined4 *)(in_ECX + 0x18);
  iVar2 = FUN_0040f630(&iStack_20,&uStack_14,uStack_4);
  return iVar2 != 1;
}


// ==== FUN_0083f490 @ 0x0083f490 ====

void FUN_0083f490(int *param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar1 = (int)*(float *)(in_ECX + -0x1c);
  iVar2 = (int)*(float *)(in_ECX + -0x14);
  if (iVar1 < 0x200) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0x1ff;
  }
  if (iVar2 < 0x200) {
    if (iVar2 < 0) {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0x1ff;
  }
  *param_1 = iVar1;
  param_1[1] = iVar2;
  param_1[2] = iVar1 + 1;
  param_1[3] = iVar2 + 1;
  return;
}


// ==== FUN_0083f520 @ 0x0083f520 ====

void FUN_0083f520(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(in_ECX + 0x14);
  *(float *)(in_ECX + 0x24) = (float)fVar1;
  return;
}


// ==== FUN_0083f540 @ 0x0083f540 ====

uint FUN_0083f540(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *in_EAX;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined1 local_3c [24];
  int local_24 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((*(int *)(in_ECX + 0xc) == 2) && (*(short *)(in_ECX + 0x10) == 1)) ||
     (in_EAX = param_1, *param_1 == 8)) {
    return (uint)in_EAX & 0xffffff00;
  }
  piVar5 = param_1;
  piVar6 = local_24;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 1;
  }
  puVar2 = (undefined4 *)FUN_0040e920(local_3c,param_1 + 3,in_ECX + 0x84);
  local_24[3] = *puVar2;
  local_14 = puVar2[1];
  local_10 = puVar2[2];
  local_c = puVar2[3];
  local_8 = puVar2[4];
  local_4 = puVar2[5];
  uVar3 = (**(code **)(**(int **)(in_ECX + 0x10c) + 0xc))(local_24,param_2);
  if ((char)uVar3 == '\0') {
    return uVar3;
  }
  thunk_FUN_0079e5a0(param_2 + 8,param_2 + 8,in_ECX + 0x44);
  puVar2 = (undefined4 *)(**(code **)(*(int *)(in_ECX + -0x24) + 0xc))();
  uVar1 = *puVar2;
  *(undefined4 *)(param_2 + 4) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


// ==== FUN_0083f600 @ 0x0083f600 ====

void FUN_0083f600(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009bf514;
  in_ECX[9] = &PTR_FUN_00a0f398;
  *in_ECX = &PTR_FUN_00a0fd34;
  in_ECX[1] = &PTR_FUN_00a0fd1c;
  in_ECX[9] = &PTR_FUN_00a0fcf4;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0x3a) = 0;
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  *(undefined1 *)(in_ECX + 8) = 1;
  return;
}


// ==== FUN_0083f660 @ 0x0083f660 ====

void FUN_0083f660(void)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  float fVar10;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float afStack_d8 [6];
  undefined4 auStack_c0 [16];
  undefined4 auStack_80 [16];
  undefined1 auStack_40 [64];
  
  if (*(int **)(in_ECX + 300) == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(in_ECX + 0x38);
    *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(in_ECX + 0x48);
    *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_ECX + 0x3c);
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    *(undefined4 *)(in_ECX + 0x58) = 0;
    *(undefined4 *)(in_ECX + 100) = DAT_0099d080;
    return;
  }
  iVar4 = (**(code **)(**(int **)(in_ECX + 300) + 8))();
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(in_ECX + 0x38);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_ECX + 0x3c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(in_ECX + 0x48);
  fStack_100 = *(float *)(iVar4 + 4) + *(float *)(in_ECX + 0x4c);
  fStack_fc = *(float *)(iVar4 + 8) + *(float *)(in_ECX + 0x50);
  fStack_f8 = *(float *)(iVar4 + 0xc) + *(float *)(in_ECX + 0x54);
  *(float *)(in_ECX + 0x4c) = fStack_100;
  *(float *)(in_ECX + 0x50) = fStack_fc;
  *(float *)(in_ECX + 0x54) = fStack_f8;
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(iVar4 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(iVar4 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(iVar4 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(iVar4 + 0x1c);
  uVar9 = *(undefined4 *)(iVar4 + 0x20);
  thunk_FUN_0079f761(auStack_80,uVar9,uVar9,uVar9);
  puVar7 = auStack_80;
  puVar5 = auStack_c0;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar5 = (undefined4 *)FUN_005cd200(auStack_40,(float *)(in_ECX + 0x4c),in_ECX + 0x58,auStack_c0);
  puVar7 = (undefined4 *)(in_ECX + 0x68);
  puVar8 = puVar7;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  thunk_FUN_0079f3a1(in_ECX + 0xa8,0,puVar7);
  fVar10 = DAT_009b0318;
  pfVar1 = (float *)(in_ECX + 8);
  *pfVar1 = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar10;
  fVar3 = DAT_0099d0b4;
  *(float *)(in_ECX + 0x10) = fVar10;
  pfVar2 = (float *)(in_ECX + 0x14);
  *pfVar2 = fVar3;
  *(float *)(in_ECX + 0x18) = fVar3;
  *(float *)(in_ECX + 0x1c) = fVar3;
  if (*(int **)(in_ECX + 300) != (int *)0x0) {
    iVar4 = (**(code **)(**(int **)(in_ECX + 300) + 8))();
    if (*(float *)(iVar4 + 0x24) < *pfVar1 || *(float *)(iVar4 + 0x24) == *pfVar1) {
      fVar10 = *(float *)(iVar4 + 0x24);
    }
    else {
      fVar10 = *pfVar1;
    }
    *pfVar1 = fVar10;
    if (*(float *)(iVar4 + 0x28) < *(float *)(in_ECX + 0xc) ||
        *(float *)(iVar4 + 0x28) == *(float *)(in_ECX + 0xc)) {
      uVar9 = *(undefined4 *)(iVar4 + 0x28);
    }
    else {
      uVar9 = *(undefined4 *)(in_ECX + 0xc);
    }
    *(undefined4 *)(in_ECX + 0xc) = uVar9;
    if (*(float *)(iVar4 + 0x2c) < *(float *)(in_ECX + 0x10) ||
        *(float *)(iVar4 + 0x2c) == *(float *)(in_ECX + 0x10)) {
      uVar9 = *(undefined4 *)(iVar4 + 0x2c);
    }
    else {
      uVar9 = *(undefined4 *)(in_ECX + 0x10);
    }
    *(undefined4 *)(in_ECX + 0x10) = uVar9;
    iVar4 = (**(code **)(**(int **)(in_ECX + 300) + 8))();
    fVar10 = *pfVar2;
    pfVar6 = (float *)(iVar4 + 0x30);
    if (fVar10 < *pfVar6 || fVar10 == *pfVar6) {
      fVar10 = *pfVar6;
    }
    *pfVar2 = fVar10;
    fVar10 = *(float *)(in_ECX + 0x18);
    if (fVar10 < *(float *)(iVar4 + 0x34) || fVar10 == *(float *)(iVar4 + 0x34)) {
      fVar10 = *(float *)(iVar4 + 0x34);
    }
    *(float *)(in_ECX + 0x18) = fVar10;
    fVar10 = *(float *)(in_ECX + 0x1c);
    if (fVar10 < *(float *)(iVar4 + 0x38) || fVar10 == *(float *)(iVar4 + 0x38)) {
      fVar10 = *(float *)(iVar4 + 0x38);
    }
    *(float *)(in_ECX + 0x1c) = fVar10;
  }
  pfVar6 = (float *)FUN_0040f670(&fStack_100,pfVar1,puVar7);
  *pfVar1 = *pfVar6;
  *(float *)(in_ECX + 0xc) = pfVar6[1];
  *(float *)(in_ECX + 0x10) = pfVar6[2];
  *(float *)(in_ECX + 0x14) = pfVar6[3];
  *(float *)(in_ECX + 0x18) = pfVar6[4];
  *(float *)(in_ECX + 0x1c) = pfVar6[5];
  *(undefined4 *)(in_ECX + 0x128) = 0x90e0e0e0;
  fStack_e4 = *pfVar2 - *pfVar1;
  fStack_100 = (*pfVar2 - *pfVar1) * DAT_0099d0b4 + *pfVar1;
  fStack_e0 = *(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc);
  fStack_fc = (*(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc)) * DAT_0099d0b4 +
              *(float *)(in_ECX + 0xc);
  fStack_dc = *(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10);
  fStack_f8 = (*(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10)) * DAT_0099d0b4 +
              *(float *)(in_ECX + 0x10);
  fStack_e8 = SQRT(fStack_e4 * fStack_e4 + fStack_e0 * fStack_e0 + fStack_dc * fStack_dc) *
              DAT_0099d0b4;
  thunk_FUN_0079e1ba(afStack_d8,&fStack_e4);
  *(float *)(in_ECX + 0x11c) = fStack_e0 * fStack_f0;
  *(float *)(in_ECX + 0x120) = fStack_dc * fStack_f0;
  *(float *)(in_ECX + 0x124) = afStack_d8[0] * fStack_f0;
  *(float *)(in_ECX + 0xec) = fVar3;
  uVar9 = DAT_0099d080;
  *(float *)(in_ECX + 0xf0) = fVar3;
  *(float *)(in_ECX + 0xf4) = fStack_100;
  *(undefined4 *)(in_ECX + 0xf8) = uVar9;
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0x100) = 0;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = uVar9;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x118) = uVar9;
  return;
}


// ==== FUN_0083fa80 @ 0x0083fa80 ====

undefined4 FUN_0083fa80(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *in_ECX;
  
  in_ECX[0xb] = *param_1;
  in_ECX[0xc] = param_1[1];
  in_ECX[0xd] = param_1[2];
  in_ECX[0xe] = param_1[3];
  in_ECX[0xf] = param_1[4];
  in_ECX[0x10] = param_1[5];
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  in_ECX[0x11] = iVar2;
  iVar2 = (**(code **)(*DAT_00b5d954 + 4))(param_1 + 1);
  in_ECX[0x4b] = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  pvVar3 = operator_new(0x3c);
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_0089e570();
  }
  in_ECX[0x4c] = (int)piVar4;
  iVar2 = *piVar4;
  uVar5 = (**(code **)(*(int *)in_ECX[0x4b] + 0xc))();
  (**(code **)(iVar2 + 4))(uVar5);
  uVar1 = (**(code **)(*(int *)in_ECX[0x4b] + 0x1c))();
  *(undefined1 *)(in_ECX + 0x3a) = uVar1;
  (**(code **)(in_ECX[9] + 0x10))();
  FUN_0083f660();
  piVar4 = DAT_00b5afac;
  puVar6 = (undefined4 *)(**(code **)(*in_ECX + 0xc))();
  (**(code **)(*piVar4 + 4))(*puVar6,in_ECX + 1,2);
  (**(code **)(*DAT_00b5a720 + 4))(in_ECX + 9);
  iVar2 = (**(code **)(*DAT_00b5b010 + 0xc))();
  in_ECX[0x4d] = iVar2;
  *(undefined1 *)(in_ECX + 10) = 1;
  return 1;
}


// ==== FUN_0083fb80 @ 0x0083fb80 ====

void FUN_0083fb80(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  
  if (((*(char *)(in_ECX + 0x20) == '\0') && (*(int **)(in_ECX + 300) != (int *)0x0)) &&
     (*(undefined4 *)(in_ECX + 0x44) = param_2, *(char *)(in_ECX + 0xe8) == '\0')) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 300) + 0x1c))();
    if (cVar1 != '\0') {
      FUN_0083f660();
      *(undefined1 *)(in_ECX + 0xe8) = 1;
    }
  }
  return;
}


// ==== FUN_0083fbc0 @ 0x0083fbc0 ====

void FUN_0083fbc0(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined1 local_4b;
  undefined1 uStack_8;
  undefined1 local_7;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar3 + 1,0);
  iVar3 = *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar3 + -0x14) = 3;
  *(undefined4 *)(iVar3 + -0x1c) = 0;
  *(undefined4 *)(iVar3 + -0x20) = 0;
  *(undefined4 *)(iVar3 + -0x24) = 0;
  *(undefined4 *)(iVar3 + -0x28) = 0;
  *(undefined4 *)(iVar3 + -0x30) = 0;
  *(undefined4 *)(iVar3 + -0x34) = 0;
  *(undefined4 *)(iVar3 + -0x38) = 0;
  *(undefined4 *)(iVar3 + -0x3c) = 0;
  *(undefined4 *)(iVar3 + -0x44) = 0;
  *(undefined4 *)(iVar3 + -0x48) = 0;
  *(undefined4 *)(iVar3 + -0x4c) = 0;
  *(undefined4 *)(iVar3 + -0x50) = 0;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(iVar3 + -0x18) = DAT_0099d080;
  *(undefined4 *)(iVar3 + -0x2c) = uVar1;
  *(undefined4 *)(iVar3 + -0x40) = uVar1;
  *(undefined4 *)(iVar3 + -0x54) = uVar1;
  *(undefined4 *)(iVar3 + -0x58) = 0;
  local_4b = 0;
  local_7 = 0;
  uStack_60 = (**(code **)(**(int **)(in_ECX + 300) + 0xc))();
  uStack_5c = (**(code **)(**(int **)(in_ECX + 300) + 0x10))();
  puVar2 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 300) + 8))();
  uStack_58 = *puVar2;
  uStack_54 = 0xffffffff;
  uStack_50 = DAT_0099d080;
  uStack_4c = 1;
  uStack_8 = 0;
  FUN_005c1360(&uStack_60);
  return;
}


// ==== FUN_0083fcf0 @ 0x0083fcf0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083fcf0(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int in_ECX;
  float fVar8;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  if ((*(char *)(in_ECX + 0x1c) != '\x01') && (*(int *)(in_ECX + 0x128) != 0)) {
    cVar4 = (**(code **)(**(int **)(in_ECX + 0x128) + 0x1c))();
    if (cVar4 != '\0') {
      puVar5 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
      iVar6 = (**(code **)(**(int **)(in_ECX + 0x128) + 8))();
      uVar3 = DAT_009c2848;
      *(undefined1 *)(puVar5 + 9) = 1;
      *(undefined1 *)((int)puVar5 + 0x21) = 0;
      *(undefined1 *)(puVar5 + 8) = 1;
      *(undefined1 *)((int)puVar5 + 0x26) = 0;
      puVar5[10] = uVar3;
      fVar2 = DAT_0099d080;
      uVar7 = *(int *)(in_ECX + 0x40) - *(int *)(in_ECX + 0x3c);
      if (uVar7 < 0x15f) {
        fVar1 = (float)(int)uVar7;
        if ((int)uVar7 < 0) {
          fVar1 = fVar1 + _DAT_0099d104;
        }
        fVar1 = fVar1 * _DAT_00a0fd54;
        fVar8 = fVar1 * DAT_009b9f98 + DAT_00a0fd50;
        *puVar5 = *(undefined4 *)(in_ECX + 0x48);
        puVar5[1] = *(undefined4 *)(in_ECX + 0x4c);
        puVar5[2] = *(undefined4 *)(in_ECX + 0x50);
        puVar5[1] = (0.0 - (fVar8 - fVar2) * fVar8 * _DAT_00a0fd4c) + (float)puVar5[1];
        uStack_8 = 0;
        uStack_c = 0;
        uStack_10 = 0;
        fStack_4 = fVar2;
        thunk_FUN_007a0dd0(puVar5 + 3,&uStack_10,in_ECX + 0x54,fVar1);
      }
      else {
        *puVar5 = *(undefined4 *)(in_ECX + 0x48);
        puVar5[1] = *(undefined4 *)(in_ECX + 0x4c);
        puVar5[2] = *(undefined4 *)(in_ECX + 0x50);
        puVar5[3] = *(undefined4 *)(in_ECX + 0x54);
        puVar5[4] = *(undefined4 *)(in_ECX + 0x58);
        puVar5[5] = *(undefined4 *)(in_ECX + 0x5c);
        puVar5[6] = *(undefined4 *)(in_ECX + 0x60);
      }
      puVar5[7] = *(undefined4 *)(iVar6 + 0x20);
      *(undefined1 *)((int)puVar5 + 0x23) = 0;
      FUN_0083fbc0(puVar5);
      (**(code **)(*param_1 + 0x98))(puVar5);
      (**(code **)(*param_1 + 0x94))(in_ECX + 0xe8);
    }
  }
  return;
}


// ==== FUN_0083fe80 @ 0x0083fe80 ====

void FUN_0083fe80(void)

{
  FUN_0083fea0();
  return;
}


// ==== FUN_0083fe90 @ 0x0083fe90 ====

void FUN_0083fe90(void)

{
  FUN_0083fea0();
  return;
}


// ==== FUN_0083fea0 @ 0x0083fea0 ====

void FUN_0083fea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fd34;
  in_ECX[1] = &PTR_FUN_00a0fd1c;
  in_ECX[9] = &PTR_FUN_00a0fcf4;
  (*(code *)PTR_FUN_00a0fd3c)();
  in_ECX[9] = &PTR_FUN_00a0f398;
  in_ECX[1] = &PTR_FUN_009bf514;
  *in_ECX = &PTR_FUN_00a0fcd8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083fef0 @ 0x0083fef0 ====

void FUN_0083fef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fd9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0083ff10 @ 0x0083ff10 ====

void FUN_0083ff10(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = *param_1;
  *(undefined4 *)(in_ECX + 0x10) = param_1[1];
  return;
}


// ==== FUN_0083ff30 @ 0x0083ff30 ====

int FUN_0083ff30(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_0083ff40 @ 0x0083ff40 ====

int FUN_0083ff40(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_0083ff50 @ 0x0083ff50 ====

undefined4 FUN_0083ff50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50);
}


// ==== FUN_0083ff60 @ 0x0083ff60 ====

undefined4 FUN_0083ff60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x54);
}


// ==== FUN_0083ff70 @ 0x0083ff70 ====

void FUN_0083ff70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fdc0;
  if (in_ECX[0x14] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x14]);
    in_ECX[0x14] = 0;
  }
  if (in_ECX[0x15] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x15]);
    in_ECX[0x15] = 0;
  }
  *in_ECX = &PTR_FUN_00a0fd9c;
  return;
}


// ==== FUN_0083ffc0 @ 0x0083ffc0 ====

int FUN_0083ffc0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 == 0) {
    *(undefined1 *)(in_ECX + 9) = 0;
    *(undefined1 *)(in_ECX + 8) = 0;
    if (*(int *)(in_ECX + 0x50) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x50));
      *(undefined4 *)(in_ECX + 0x50) = 0;
    }
    if (*(int *)(in_ECX + 0x54) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x54));
      *(undefined4 *)(in_ECX + 0x54) = 0;
    }
    iVar1 = *(int *)(in_ECX + 4);
  }
  return iVar1;
}


